#!/usr/bin/env python3

###
# Rebuilds one unit and reports how closely it matches the original.
#
# Usage:
#   python3 tools/match.py <unit>                 # per-function status for a unit
#   python3 tools/match.py <unit> <function>      # instruction diff for one function
#   python3 tools/match.py <function>             # same, looking the unit up by function
#
# For a function that is not in the source yet, it prints the target assembly
# and an m2c draft (https://github.com/matt-kempster/m2c) using the unit's
# headers for types; --m2c prints the draft for any function. The draft is a
# starting point and will not match as written.
#
# --source FILE compiles FILE in place of the unit's source file for this run,
# for scratch variants such as a copy that defines out-of-range data as
# statics. It compiles into a temporary directory and leaves the source and
# the build directory alone, so such runs can go alongside other edits and
# runs in the same checkout. Repeat it with a header copy to replace a header
# for the run too: a .h file replaces the header of the same name under
# include/, and COPY=include/<path> names the one it replaces.
#
# <unit> may be an objdiff unit name (game/game/kinoko), a source path
# (src/game/kinoko.c) or a unique basename (kinoko).
#
# A function matches when `objdiff-cli report generate` scores it 100% and
# every relocation also points at the same thing. The report alone is not
# enough: it ignores relocation targets, so a call to the wrong function
# still scores 100%. Those functions are reported as "reloc". A function whose
# source is still a placeholder ("{ return; }" or "{ return 0; }") is reported
# as "stub".
#
# Exit codes: 0 = matches, 1 = does not match yet, 2 = build failed,
#             3 = usage or lookup error.
#
# Run one at a time per checkout (ninja is not safe to run concurrently in
# one build directory); parallel workers each need their own worktree.
###

import argparse
import difflib
import json
import math
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import time
from typing import Any, Dict, List, Optional, Tuple

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))
build_dir = os.path.join(root_dir, "build")
objdiff_json = os.path.join(root_dir, "objdiff.json")
objdiff_cli = os.path.join(build_dir, "tools", "objdiff-cli")
objdump = os.path.join(build_dir, "binutils", "powerpc-eabi-objdump")

EXIT_MATCH = 0
EXIT_MISMATCH = 1
EXIT_BUILD_FAILED = 2
EXIT_USAGE = 3


class UsageError(Exception):
    pass


###
# Units and the objdiff report
###


def load_units() -> List[Dict[str, Any]]:
    if not os.path.exists(objdiff_json):
        raise UsageError("objdiff.json not found; run `python3 configure.py && ninja` first")
    with open(objdiff_json) as f:
        return json.load(f)["units"]


def resolve_unit(query: str, units: List[Dict[str, Any]]) -> Optional[Dict[str, Any]]:
    by_name = [u for u in units if u["name"] == query]
    if by_name:
        return by_name[0]

    path = os.path.relpath(os.path.abspath(query), root_dir)
    by_path = [u for u in units if u.get("metadata", {}).get("source_path") == path]
    if by_path:
        return by_path[0]

    base = os.path.splitext(os.path.basename(query))[0]
    candidates = [
        u
        for u in units
        if u["name"].endswith("/" + query)
        or os.path.splitext(os.path.basename(u.get("metadata", {}).get("source_path", "")))[0] == base
    ]
    if len(candidates) == 1:
        return candidates[0]
    if len(candidates) > 1:
        names = "\n  ".join(u["name"] for u in candidates)
        raise UsageError(f"'{query}' matches several units:\n  {names}")
    return None


def generate_report(project: str = root_dir) -> Dict[str, Any]:
    fd, path = tempfile.mkstemp(prefix="match-report-", suffix=".json")
    os.close(fd)
    try:
        proc = subprocess.run(
            [objdiff_cli, "report", "generate", "-p", project, "-o", path],
            cwd=root_dir,
            capture_output=True,
            text=True,
        )
        if proc.returncode != 0:
            raise UsageError(f"objdiff-cli report failed:\n{proc.stderr.strip()}")
        with open(path) as f:
            return json.load(f)
    finally:
        os.unlink(path)


def find_function_unit(report: Dict[str, Any], function: str) -> List[str]:
    return [
        u["name"]
        for u in report["units"]
        if any(f["name"] == function for f in u.get("functions", []))
    ]


def build(unit: Dict[str, Any], with_base: bool = True) -> Tuple[bool, float, str]:
    # Tools are ninja outputs too, so a fresh worktree fetches them on first use.
    # Only ask for missing ones: with configure.py --objdiff/--binutils they are
    # not ninja targets. binutils is a directory output in build.ninja.
    tools = [t for t in (objdiff_cli, os.path.dirname(objdump)) if not os.path.exists(t)]
    # dtk writes a linked (Matching) unit's target object while splitting, but
    # build.ninja does not list it as an output
    targets = [] if unit.get("metadata", {}).get("complete") else [unit["target_path"]]
    targets += ([unit["base_path"]] if with_base else []) + [os.path.relpath(t, root_dir) for t in tools]
    start = time.monotonic()
    proc = subprocess.run(["ninja", *targets], cwd=root_dir, capture_output=True, text=True)
    elapsed = time.monotonic() - start
    output = proc.stdout + proc.stderr
    return proc.returncode == 0, elapsed, output


def build_scratch(
    unit: Dict[str, Any], scratch: Optional[str], headers: List[Tuple[str, str]], out_dir: str
) -> Tuple[bool, float, str, Dict[str, Any]]:
    # Compile the scratch file (or the unit's own source) with the unit's own
    # command into out_dir, with the header copies in an include directory
    # searched first, and describe it there as a one-unit objdiff project
    # whose base is that object
    ok, elapsed, output = build(unit, with_base=False)
    if not ok:
        return ok, elapsed, output, unit
    source = unit["metadata"]["source_path"]
    obj_dir = os.path.dirname(unit["base_path"])
    proc = subprocess.run(["ninja", "-t", "commands", unit["base_path"]], cwd=root_dir, capture_output=True, text=True)
    command = proc.stdout.strip().splitlines()[-1].split(" && ")[0]
    io = f" -c {source} -o {obj_dir}"
    if io not in command:
        raise UsageError(f"cannot find '{io.strip()}' in the compile command for {unit['base_path']}")
    copy = os.path.join(out_dir, os.path.basename(source))
    shutil.copyfile(scratch or os.path.join(root_dir, source), copy)
    command = command.replace(io, f" -c {copy} -o {out_dir}")
    if headers:
        if " -i include " not in command:
            raise UsageError(f"cannot find '-i include' in the compile command for {unit['base_path']}")
        overlay = os.path.join(out_dir, "include")
        for header_copy, replaces in headers:
            dest = os.path.join(overlay, os.path.relpath(replaces, "include"))
            os.makedirs(os.path.dirname(dest), exist_ok=True)
            shutil.copyfile(header_copy, dest)
        command = command.replace(" -i include ", f" -i {overlay} -i include ", 1)
    start = time.monotonic()
    proc = subprocess.run(command, shell=True, cwd=root_dir, capture_output=True, text=True)
    elapsed += time.monotonic() - start
    base = os.path.join(out_dir, os.path.splitext(os.path.basename(source))[0] + ".o")
    scratch_unit = dict(unit, target_path=os.path.join(root_dir, unit["target_path"]), base_path=base)
    with open(objdiff_json) as f:
        project = json.load(f)
    project["units"] = [scratch_unit]
    with open(os.path.join(out_dir, "objdiff.json"), "w") as f:
        json.dump(project, f)
    return proc.returncode == 0, elapsed, proc.stdout + proc.stderr, scratch_unit


def build_errors(output: str, limit: int = 80) -> str:
    lines = [
        line
        for line in output.splitlines()
        if line.strip() and not re.match(r"^\[\d+/\d+\] ", line)
    ]
    if len(lines) > limit:
        lines = lines[:limit] + [f"... ({len(lines) - limit} more lines)"]
    return "\n".join(lines)


###
# Minimal ELF32 big-endian reader, for symbol values and data
###


class Symbol:
    def __init__(self, name: str, value: int, size: int, kind: int, section: str, data: Optional[bytes]):
        self.name = name
        self.value = value
        self.size = size
        self.kind = kind  # 1 = object, 2 = function
        self.section = section
        self.data = data  # None for .bss/.sbss


def read_symbols(path: str) -> Dict[str, Symbol]:
    with open(path, "rb") as f:
        data = f.read()
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 2:
        raise UsageError(f"{path} is not a 32-bit big-endian ELF")
    shoff, = struct.unpack_from(">I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 0x2E)
    sections = []
    for i in range(shnum):
        sections.append(struct.unpack_from(">IIIIIIIIII", data, shoff + i * shentsize))

    def c_string(table_offset: int, offset: int) -> str:
        end = data.index(b"\0", table_offset + offset)
        return data[table_offset + offset : end].decode("ascii", "replace")

    shstr_offset = sections[shstrndx][4]
    section_names = [c_string(shstr_offset, s[0]) for s in sections]

    symbols: Dict[str, Symbol] = {}
    for sh in sections:
        if sh[1] != 2:  # SHT_SYMTAB
            continue
        strtab_offset = sections[sh[6]][4]
        for j in range(sh[5] // 16):
            st_name, value, size, info, _, shndx = struct.unpack_from(">IIIBBH", data, sh[4] + j * 16)
            if st_name == 0 or shndx == 0 or shndx >= len(sections):
                continue
            name = c_string(strtab_offset, st_name)
            sec = sections[shndx]
            sym_data = None
            if sec[1] != 8:  # not SHT_NOBITS
                sym_data = data[sec[4] + value : sec[4] + value + max(size, 0)]
            symbols.setdefault(name, Symbol(name, value, size, info & 0xF, section_names[shndx], sym_data))
    return symbols


ANONYMOUS = re.compile(r"^(@|lbl_|\.\.\.|jumptable_|gap_)|\$")


def is_anonymous(name: str) -> bool:
    return bool(ANONYMOUS.search(name))


def symbol_bytes(sym: Symbol, addend: int) -> Optional[bytes]:
    if sym.data is None:
        return None
    raw = sym.data[addend:] if addend < len(sym.data) else b""
    if len(raw) in (4, 8):
        return raw  # float/double/word constants
    nul = raw.find(b"\0", 0, 96)
    if nul > 0 and all(32 <= c < 127 or c in (9, 10, 13) for c in raw[:nul]):
        return raw[: nul + 1]
    return raw[:16]


def format_value(sym: Symbol, addend: int) -> str:
    if sym.data is None:
        return f"bss[{sym.size:#x}]"
    raw = symbol_bytes(sym, addend) or b""
    if len(raw) == 4:
        return f"{raw.hex()} {format_float(raw, '>f', 9)}f"
    if len(raw) == 8:
        return f"{raw.hex()} {format_float(raw, '>d', 17)}"
    if raw.endswith(b"\0") and len(raw) > 1:
        text = raw[:-1].decode("ascii", "replace")
        return json.dumps(text if len(text) <= 40 else text[:40] + "...")
    return raw.hex()


def format_float(raw: bytes, fmt: str, max_digits: int) -> str:
    value, = struct.unpack(fmt, raw)
    if not math.isfinite(value):
        return str(value)
    text = repr(value)
    for digits in range(1, max_digits + 1):
        shortest = f"{value:.{digits}g}"
        if struct.pack(fmt, float(shortest)) == raw:
            text = shortest
            break
    if "e" in text and 1e-5 <= abs(value) < 1e16:
        text = repr(float(text))  # 1e+02 -> 100.0
    if not re.search(r"[.e]", text):
        text += ".0"
    return text


###
# Disassembly
###


class Insn:
    def __init__(self, offset: int, text: str, refs: List[Tuple[str, int]]):
        self.offset = offset
        self.text = text
        self.refs = refs  # (symbol, addend) for each relocation


INSN_LINE = re.compile(r"^\s+([0-9a-f]+):\s+(\S+)(?:\s+(.*))?$")
RELOC_LINE = re.compile(r"^\s+([0-9a-f]+): (R_PPC_\S+)\s+(\S+)$")
RELOC_SUFFIX = {
    "R_PPC_ADDR16_HA": "@ha",
    "R_PPC_ADDR16_HI": "@h",
    "R_PPC_ADDR16_LO": "@l",
    "R_PPC_ADDR16": "",
    "R_PPC_EMB_SDA21": "@sda21",
}


def split_addend(target: str) -> Tuple[str, int]:
    m = re.match(r"^(.*?)([+-]0x[0-9a-f]+)$", target)
    if m:
        return m.group(1), int(m.group(2), 16)
    return target, 0


BRANCH_RELOCS = ("R_PPC_REL24", "R_PPC_REL14", "R_PPC_ADDR24", "R_PPC_ADDR14")


def fold_reloc(operands: str, rtype: str, target: str) -> str:
    if rtype in BRANCH_RELOCS:
        folded = re.sub(r"[0-9a-f]+ <[^>]*>$", target, operands)
        if folded == operands:
            parts = operands.split(",")
            parts[-1] = target
            folded = ",".join(parts)
        return folded
    suffix = RELOC_SUFFIX.get(rtype)
    if suffix is not None:
        parts = operands.split(",")
        m = re.match(r"^-?(?:0x)?0(\(.*\))?$", parts[-1])
        if m:
            parts[-1] = f"{target}{suffix}{m.group(1) or ''}"
            return ",".join(parts)
    return f"{operands} ; {rtype} {target}"


def disassemble(obj: str, function: str, symbols: Dict[str, Symbol]) -> List[Insn]:
    sym = symbols.get(function)
    if sym is None or sym.kind != 2:
        return []
    # Disassemble by address range: --disassemble=<name> would stop at the
    # first label inside the function (e.g. __RAS_OSDisableInterrupts_begin).
    start, end = sym.value, sym.value + sym.size
    proc = subprocess.run(
        [objdump, "-dr", "--no-show-raw-insn", "-j", sym.section,
         f"--start-address={start:#x}", f"--stop-address={end:#x}", obj],
        capture_output=True,
        text=True,
    )
    if proc.returncode != 0:
        raise UsageError(f"objdump failed on {obj}:\n{proc.stderr.strip()}")

    raw: List[Tuple[int, str, str]] = []
    relocs: List[Tuple[int, str, str]] = []
    for line in proc.stdout.splitlines():
        m = RELOC_LINE.match(line)
        if m:
            relocs.append((int(m.group(1), 16), m.group(2), m.group(3)))
            continue
        m = INSN_LINE.match(line)
        if m and start <= int(m.group(1), 16) < end:
            raw.append((int(m.group(1), 16), m.group(2), m.group(3) or ""))

    insns = []
    for i, (addr, mnemonic, operands) in enumerate(raw):
        next_addr = raw[i + 1][0] if i + 1 < len(raw) else addr + 4
        refs = []
        for raddr, rtype, rtarget in relocs:
            if not addr <= raddr < next_addr:
                continue
            name, addend = split_addend(rtarget)
            if rtype in BRANCH_RELOCS and name == function:
                # A relocated branch back into this function is still a local branch
                operands = fold_reloc(operands, rtype, f"<+{addend:#x}>")
                continue
            operands = fold_reloc(operands, rtype, rtarget)
            refs.append((name, addend))
        # Unrelocated branch targets: objdump labels them with whichever symbol is
        # nearest, which differs between the objects. Show targets inside this
        # function as offsets from its start and anything else as an address.
        operands = re.sub(
            r"\b([0-9a-f]+) <[^>]*>",
            lambda m: f"<+{int(m.group(1), 16) - start:#x}>" if start <= int(m.group(1), 16) < end else m.group(1),
            operands,
        )
        text = f"{mnemonic:<8}{operands}".rstrip()
        insns.append(Insn(addr - start, text, refs))
    return insns


def forms(insn: Insn, symbols: Dict[str, Symbol]) -> Tuple[str, str, str]:
    # Two instructions match if any of these forms agree:
    #  - as written (same symbol names)
    #  - by section and offset for symbols defined in the object, as objdiff does
    #    (DriveInfo vs ...bss.0+0x20)
    #  - by value for anonymous literals (lbl_3_rodata_6E8 vs @1140 both 1.0f),
    #    which sit in different pool slots until the whole unit is written
    by_address = by_value = insn.text
    for name, addend in insn.refs:
        sym = symbols.get(name)
        if sym is None:
            continue
        pattern = re.escape(name) + r"([+-]0x[0-9a-f]+)?"
        address_key = f"<{sym.section}+{sym.value + addend:#x}>"
        by_address = re.sub(pattern, lambda _: address_key, by_address)
        if is_anonymous(name) and sym.kind != 2 and sym.data is not None:
            kind = sym.section.lstrip(".").rstrip("0123456789")
            value_key = f"<{kind}:{(symbol_bytes(sym, addend) or b'').hex()}>"
            by_value = re.sub(pattern, lambda _: value_key, by_value)
        else:
            by_value = re.sub(pattern, lambda _: address_key, by_value)
    return insn.text, by_address, by_value


def same(left: Tuple[str, ...], right: Tuple[str, ...]) -> bool:
    return any(a == b for a, b in zip(left, right))


def annotate(insn: Insn, symbols: Dict[str, Symbol]) -> str:
    notes = []
    for name, addend in insn.refs:
        sym = symbols.get(name)
        if sym is not None and sym.kind != 2 and is_anonymous(name):
            notes.append(f"{name}={format_value(sym, addend)}")
    return f"  ; {', '.join(notes)}" if notes else ""


REGISTER = re.compile(r"\b(?:r|f|cr)\d+\b")


def classify(left: Tuple[str, ...], right: Tuple[str, ...]) -> str:
    mnemonic = left[0].split(" ", 1)[0]
    if mnemonic != right[0].split(" ", 1)[0]:
        return "|"
    if same(tuple(REGISTER.sub("R", s) for s in left), tuple(REGISTER.sub("R", s) for s in right)):
        return "r"
    if mnemonic.startswith("b") or re.search(r"@(?:ha|h|l|sda21)\b", left[0] + right[0]):
        return "s"
    return "i"


###
# m2c drafts
###


M2C_MISSING = (
    "m2c not found on PATH (or $M2C); install it from https://github.com/matt-kempster/m2c\n"
    "(the PyPI package named m2c is a different project)"
)

# m2c parses context with pycparser, which needs plain preprocessed C
CONTEXT_DEFINES = ["-D__MWERKS__=0x4302", "-D__PPCGEKKO__", "-D__PPC__", "-D__declspec(x)="]


def asm_path(unit: Dict[str, Any]) -> str:
    # dtk writes each unit's assembly next to its split object: .../obj/x.o -> .../asm/x.s
    return os.path.join(root_dir, os.path.splitext(unit["target_path"].replace("/obj/", "/asm/", 1))[0] + ".s")


def context_path(unit: Dict[str, Any]) -> Optional[str]:
    return unit.get("scratch", {}).get("ctx_path")


def prepare_context(ctx: str, out_dir: str) -> Optional[str]:
    compiler = shutil.which("cc") or shutil.which("gcc") or shutil.which("clang")
    if compiler is None or not os.path.exists(ctx):
        return None
    out = os.path.join(out_dir, "ctx.c")
    proc = subprocess.run(
        [compiler, "-E", "-P", "-undef", "-nostdinc", "-x", "c", *CONTEXT_DEFINES, ctx, "-o", out],
        capture_output=True,
        text=True,
    )
    if proc.returncode != 0:
        return None
    with open(out) as f:
        text = f.read()
    with open(out, "w") as f:
        f.write(strip_asm(text))
    return out


def strip_asm(text: str) -> str:
    # m2c only needs declarations, so drop inline asm blocks (asm { ... }) and
    # empty the bodies of functions written in asm (asm void f() { ... }).
    pieces = []
    pos = 0
    for m in re.finditer(r"\basm\b", text):
        if m.start() < pos:
            continue
        brace = text.find("{", m.end())
        semi = text.find(";", m.end())
        pieces.append(text[pos : m.start()])
        if brace == -1 or (semi != -1 and semi < brace and text[m.end() : brace].strip()):
            pos = m.end()  # a prototype such as `asm void f(void);`
            continue
        depth = 0
        end = brace
        while end < len(text):
            depth += {"{": 1, "}": -1}.get(text[end], 0)
            end += 1
            if depth == 0:
                break
        header = text[m.end() : brace]
        pieces.append(header + "{}" if header.strip() else "")
        pos = end
    pieces.append(text[pos:])
    return "".join(pieces)


def hide_placeholder(ctx: str, function: str) -> None:
    # A stub's header declares it void(void), and m2c would trust that over the
    # registers the assembly reads, so rename it out of the context
    with open(ctx) as f:
        text = f.read()
    if re.search(rf"\b{re.escape(function)}\s*\(\s*void\s*\)", text):
        with open(ctx, "w") as f:
            f.write(re.sub(rf"\b{re.escape(function)}\b", function + "_placeholder", text))


def m2c_draft(unit: Dict[str, Any], function: str, build_context: bool) -> str:
    m2c = os.environ.get("M2C") or shutil.which("m2c")
    if m2c is None:
        return M2C_MISSING
    command = [m2c, "-t", "ppc-mwcc-c", "-f", function]
    note = ""
    ctx = context_path(unit)
    if ctx and build_context:
        # Best effort: without it m2c still runs, just without types
        subprocess.run(["ninja", ctx], cwd=root_dir, capture_output=True)
    with tempfile.TemporaryDirectory(prefix="match-m2c-") as tmp:
        prepared = prepare_context(os.path.join(root_dir, ctx), tmp) if ctx else None
        if prepared is None:
            note = "/* m2c ran without type context: the unit's .ctx could not be prepared */\n"
        else:
            hide_placeholder(prepared, function)
        proc = subprocess.run(
            command + (["--context", prepared] if prepared else []) + [asm_path(unit)],
            capture_output=True,
            text=True,
        )
        output = (proc.stdout + proc.stderr).strip()
        if prepared and "parsing C context" in output:
            reason = next((line.strip() for line in output.splitlines() if line.strip().startswith("before:")), "")
            note = f"/* m2c ran without type context: it could not parse the unit's headers ({reason}) */\n"
            proc = subprocess.run(command + [asm_path(unit)], capture_output=True, text=True)
            output = (proc.stdout + proc.stderr).strip()
    return note + output


###
# Output
###


def function_diff(
    target: List[Insn],
    base: List[Insn],
    target_syms: Dict[str, Symbol],
    base_syms: Dict[str, Symbol],
) -> List[Tuple[str, Optional[Insn], Optional[Insn]]]:
    left = [forms(i, target_syms) for i in target]
    right = [forms(i, base_syms) for i in base]
    rows: List[Tuple[str, Optional[Insn], Optional[Insn]]] = []
    # Align on opcodes first (as asm-differ does), then classify each pair, so
    # register swaps stay paired and reordering shows as moved lines.
    matcher = difflib.SequenceMatcher(
        None, [s[0].split(" ", 1)[0] for s in left], [s[0].split(" ", 1)[0] for s in right], autojunk=False
    )
    for op, i1, i2, j1, j2 in matcher.get_opcodes():
        pairs = min(i2 - i1, j2 - j1) if op in ("equal", "replace") else 0
        for k in range(pairs):
            a, b = i1 + k, j1 + k
            mark = " " if same(left[a], right[b]) else classify(left[a], right[b])
            rows.append((mark, target[a], base[b]))
        rows.extend(("<", target[i], None) for i in range(i1 + pairs, i2))
        rows.extend((">", None, base[j]) for j in range(j1 + pairs, j2))
    return rows


MARK_NAMES = {
    "r": "register",
    "i": "immediate",
    "s": "symbol/branch",
    "|": "opcode",
    "<": "only in target",
    ">": "only in base",
}


def print_diff(rows, target_syms, base_syms, context: int, max_lines: int, full: bool) -> None:
    changed = [k for k, row in enumerate(rows) if row[0] != " "]
    counts: Dict[str, int] = {}
    for k in changed:
        counts[rows[k][0]] = counts.get(rows[k][0], 0) + 1
    summary = ", ".join(f"{MARK_NAMES[m]} {n}" for m, n in sorted(counts.items(), key=lambda x: -x[1]))
    print(f"{len(changed)} differing lines" + (f" ({summary})" if summary else ""))
    if not changed and not full:
        return
    if changed:
        print("markers: r register  i immediate  s symbol/branch  | opcode  < only in target  > only in base")

    shown = set(range(len(rows))) if full else set()
    if not full:
        for k in changed:
            shown.update(range(max(0, k - context), min(len(rows), k + context + 1)))

    width = max([len(r[1].text) for r in rows if r[1] is not None] + [20])
    width = min(width, 44)
    printed = 0
    last = -1
    print(f"{'off':>5}  {'target':<{width}}    base")
    for k in sorted(shown):
        if not full and printed >= max_lines:
            print(f"... truncated at {max_lines} lines; use --max-lines or --full")
            break
        if last != -1 and k != last + 1:
            print("  ...")
        last = k
        mark, t, b = rows[k]
        off = f"{t.offset:04x}" if t is not None else ""
        left = t.text if t is not None else ""
        right = b.text if b is not None else ""
        note = ""
        if mark != " ":
            note = (annotate(t, target_syms) if t is not None else "") + (annotate(b, base_syms) if b is not None else "")
        print(f"{off:>5}  {left:<{width}}  {mark} {right}{note}")
        printed += 1


def print_listing(insns: List[Insn], symbols: Dict[str, Symbol], max_lines: int, full: bool) -> None:
    for n, insn in enumerate(insns):
        if not full and n >= max_lines:
            print(f"... truncated at {max_lines} of {len(insns)} lines; use --max-lines or --full")
            break
        print(f"{insn.offset:04x}  {insn.text}{annotate(insn, symbols)}")


def print_draft(draft: Optional[str], function: str, max_lines: int, full: bool) -> None:
    if draft is None:
        return
    lines = draft.splitlines()
    print("\nm2c draft (a starting point; it will not match as written):")
    for n, line in enumerate(lines):
        if not full and n >= max_lines:
            # Keep the whole draft, so reading the rest needs no second run
            path = os.path.join(build_dir, "m2c", f"{function}.c")
            os.makedirs(os.path.dirname(path), exist_ok=True)
            with open(path, "w") as f:
                f.write(draft)
            print(f"... truncated at {max_lines} of {len(lines)} lines; the whole draft is in {os.path.relpath(path, root_dir)}")
            break
        print(line)


def function_status(func: Dict[str, Any], base_syms: Optional[Dict[str, "Symbol"]] = None) -> str:
    percent = func.get("fuzzy_match_percent")
    if percent is None:
        return "missing"
    if percent >= 100.0:
        return "match"
    # An upstream placeholder, "{ return; }", compiles to a lone blr, and one
    # that returns a constant ("{ return 0; }") to two instructions; both are
    # inlined into their callers like an empty stub
    base = base_syms.get(func["name"]) if base_syms else None
    if base is not None and base.size <= 8 and int(func["size"]) > 2 * base.size:
        return "stub"
    return "partial"


def stub_callees(unit: Dict[str, Any], statuses: Dict[str, str]) -> Dict[str, List[str]]:
    # An empty stub is inlined into its callers, so a caller cannot match until
    # each stub it calls in this unit has a body: list those per function. A
    # callee absent from the source is called, not inlined, so it blocks nothing
    path = asm_path(unit)
    if not os.path.exists(path):
        return {}
    waits: Dict[str, List[str]] = {}
    current = None
    with open(path) as f:
        for line in f:
            if line.startswith(".fn "):
                current = line[4:].split(",")[0].strip()
                continue
            m = re.search(r"\tbl?\s+([A-Za-z_][\w.@]*)\s*$", line)
            if current and m:
                callee = m.group(1)
                if callee != current and statuses.get(callee) == "stub":
                    if callee not in waits.setdefault(current, []):
                        waits[current].append(callee)
    return waits


def print_unit(
    unit: Dict[str, Any],
    report_unit: Dict[str, Any],
    statuses: Dict[str, str],
    base_only: List[str],
    show_all: bool,
    waits: Dict[str, List[str]],
) -> None:
    measures = report_unit.get("measures", {})
    funcs = sorted(report_unit.get("functions", []), key=lambda f: int(f.get("address", 0)))
    sections = " ".join(
        f"{s['name']} {s.get('fuzzy_match_percent', 0.0):.2f}%" for s in report_unit.get("sections", [])
    )
    complete = "Matching" if unit.get("metadata", {}).get("complete") else "NonMatching"
    strict = sum(1 for s in statuses.values() if s == "match")
    strict_code = sum(int(f["size"]) for f in funcs if statuses[f["name"]] == "match")
    print(
        f"functions {strict}/{measures.get('total_functions', 0)} matched "
        f"({measures.get('matched_functions', 0)} in objdiff's report), "
        f"code {strict_code}/{measures.get('total_code', 0)} bytes "
        f"({measures.get('matched_code', 0)} in objdiff's report), configure.py: {complete}"
    )
    if sections:
        print(f"sections: {sections}")
    hidden = 0
    for func in funcs:
        status = statuses[func["name"]]
        if status == "match" and not show_all:
            hidden += 1
            continue
        percent = func.get("fuzzy_match_percent")
        shown = f"{percent:6.2f}%" if percent is not None else "      -"
        waiting = f"  (waits on {', '.join(waits[func['name']])})" if waits.get(func["name"]) else ""
        print(f"  {status:<8}{shown}  {int(func['size']):#7x}  {func['name']}{waiting}")
    if hidden:
        print(f"  ({hidden} matching functions hidden; --all shows them)")
    if "reloc" in statuses.values():
        print(RELOC_NOTE)
        if complete == "Matching":
            print(LINKED_NOTE)
    if base_only:
        print(
            "warning: functions in the source but not in the target: "
            + ", ".join(base_only)
            + " (renamed? update symbols.txt; static helper? check splits)"
        )


RELOC_NOTE = (
    "reloc: 100% in objdiff's report, which ignores relocation targets, but a call, global or\n"
    "  constant reference points somewhere else; diff the function to see where"
)
LINKED_NOTE = (
    "  this unit is linked (Matching in configure.py), so the full build's hash check is the\n"
    "  final word; differences here are usually aliases or literals pooled in another split"
)


def check_function(unit: Dict[str, Any], func: Dict[str, Any], target_syms, base_syms):
    status = function_status(func, base_syms)
    target = disassemble(os.path.join(root_dir, unit["target_path"]), func["name"], target_syms)
    base = disassemble(os.path.join(root_dir, unit["base_path"]), func["name"], base_syms) if status != "missing" else []
    rows = function_diff(target, base, target_syms, base_syms) if base else []
    if status == "match" and any(row[0] != " " for row in rows):
        status = "reloc"
    return status, target, rows


###
# Main
###


def main() -> int:
    parser = argparse.ArgumentParser(description="Rebuild one unit and report how closely it matches.")
    parser.add_argument("unit", help="unit name, source path, basename, or a function name")
    parser.add_argument("function", nargs="?", help="function to diff")
    parser.add_argument("--no-build", action="store_true", help="skip rebuilding the unit")
    parser.add_argument("--all", action="store_true", help="list matching functions too")
    parser.add_argument("--full", action="store_true", help="show the whole function, not just changed hunks")
    parser.add_argument("-C", "--context", type=int, default=3, help="context lines around changes (default 3)")
    parser.add_argument("--max-lines", type=int, default=200, help="cap on printed diff lines (default 200)")
    parser.add_argument("--json", action="store_true", help="print a machine-readable result instead")
    parser.add_argument("--m2c", action="store_true", help="print an m2c draft even if the function is in the source")
    parser.add_argument(
        "--source",
        metavar="FILE",
        action="append",
        help="for this run, compile FILE in place of the unit's source (.c) or of the header of the same name "
        "under include/ (.h, or FILE=include/<path>); repeatable",
    )
    args = parser.parse_args()

    units = load_units()
    unit = resolve_unit(args.unit, units)
    function = args.function
    if unit is None and function is None:
        owners = find_function_unit(generate_report(), args.unit)
        if len(owners) == 1:
            unit = next(u for u in units if u["name"] == owners[0])
            function = args.unit
        elif len(owners) > 1:
            raise UsageError(f"function '{args.unit}' is in several units: {', '.join(owners)}")
    if unit is None:
        raise UsageError(f"no unit or function named '{args.unit}'")
    if "base_path" not in unit:
        raise UsageError(f"{unit['name']} has no source file yet (it is not split out into src/)")

    if args.source:
        if args.no_build:
            raise UsageError("--source needs a build; drop --no-build")
        args.scratch_source, args.scratch_headers = scratch_files(args.source)
        with tempfile.TemporaryDirectory(prefix="match-source-") as out_dir:
            return run(args, unit, function, out_dir)
    return run(args, unit, function)


def scratch_files(specs: List[str]) -> Tuple[Optional[str], List[Tuple[str, str]]]:
    # Sort --source arguments into the source copy and (header copy, the
    # header under include/ it replaces) pairs
    source = None
    headers = []
    for spec in specs:
        copy, _, replaces = spec.partition("=")
        if not os.path.isfile(copy):
            raise UsageError(f"{copy} not found")
        if not replaces and copy.endswith(".c"):
            if source:
                raise UsageError("--source takes one .c file")
            source = copy
            continue
        if not replaces:
            name = os.path.basename(copy)
            found = [
                os.path.relpath(os.path.join(d, name), root_dir)
                for d, _, files in os.walk(os.path.join(root_dir, "include"))
                if name in files
            ]
            if len(found) != 1:
                where = ", ".join(found) or "nothing"
                raise UsageError(f"{name} names {where} under include/; write {copy}=include/<path>")
            replaces = found[0]
        replaces = os.path.normpath(replaces)
        if not replaces.startswith("include" + os.sep) or not os.path.isfile(os.path.join(root_dir, replaces)):
            raise UsageError(f"{replaces} is not a file under include/")
        headers.append((copy, replaces))
    return source, headers


def run(args: argparse.Namespace, unit: Dict[str, Any], function: Optional[str], scratch_dir: Optional[str] = None) -> int:
    result: Dict[str, Any] = {"unit": unit["name"], "source": unit.get("metadata", {}).get("source_path")}
    project = root_dir
    if scratch_dir:
        replaced = [f"{args.scratch_source} in place of {result['source']}"] if args.scratch_source else []
        replaced += [f"{copy} in place of {replaces}" for copy, replaces in args.scratch_headers]
        result["source"] = f"{result['source']} ({'; '.join(replaced)})"
        ok, elapsed, output, unit = build_scratch(unit, args.scratch_source, args.scratch_headers, scratch_dir)
        project = scratch_dir
    elif not args.no_build:
        ok, elapsed, output = build(unit)
    if scratch_dir or not args.no_build:
        result["build"] = {"ok": ok, "seconds": round(elapsed, 2)}
        if not ok:
            result["build"]["errors"] = build_errors(output)
            if args.json:
                print(json.dumps(result, indent=1))
            else:
                print(f"{unit['name']}  {result['source']}  BUILD FAILED ({elapsed:.2f}s)")
                print(result["build"]["errors"])
            return EXIT_BUILD_FAILED

    report = generate_report(project)
    report_unit = next((u for u in report["units"] if u["name"] == unit["name"]), None)
    if report_unit is None:
        raise UsageError(f"{unit['name']} is not in the objdiff report")

    target_syms = read_symbols(os.path.join(root_dir, unit["target_path"]))
    base_syms = read_symbols(os.path.join(root_dir, unit["base_path"]))
    target_funcs = {f["name"] for f in report_unit.get("functions", [])}
    base_only = sorted(
        s.name for s in base_syms.values() if s.kind == 2 and s.section.startswith(".text") and s.name not in target_funcs
    )

    if function is None:
        funcs = sorted(report_unit.get("functions", []), key=lambda f: int(f.get("address", 0)))
        statuses = {}
        for f in funcs:
            status = function_status(f, base_syms)
            if status == "match":
                status = check_function(unit, f, target_syms, base_syms)[0]
            statuses[f["name"]] = status
        waits = stub_callees(unit, statuses)
        if funcs:
            matched = all(s == "match" for s in statuses.values())
        else:  # data-only unit
            matched = all(s.get("fuzzy_match_percent", 0.0) >= 100.0 for s in report_unit.get("sections", []))
        if args.json:
            result.update(
                matched=matched,
                matched_code=sum(int(f["size"]) for f in funcs if statuses[f["name"]] == "match"),
                measures=report_unit.get("measures", {}),
                sections=report_unit.get("sections", []),
                functions=[
                    {
                        "name": f["name"],
                        "size": int(f["size"]),
                        "percent": f.get("fuzzy_match_percent"),
                        "status": statuses[f["name"]],
                        "waits_on": waits.get(f["name"], []),
                    }
                    for f in funcs
                ],
                base_only=base_only,
            )
            print(json.dumps(result, indent=1))
        else:
            built = f" (built in {result['build']['seconds']:.2f}s)" if "build" in result else ""
            print(f"{unit['name']}  {result['source']}{built}")
            print_unit(unit, report_unit, statuses, base_only, args.all, waits)
        return EXIT_MATCH if matched else EXIT_MISMATCH

    func = next((f for f in report_unit.get("functions", []) if f["name"] == function), None)
    if func is None:
        raise UsageError(f"{unit['name']} has no function named '{function}' in the target")
    status, target, rows = check_function(unit, func, target_syms, base_syms)
    percent = func.get("fuzzy_match_percent")
    draft = m2c_draft(unit, function, not args.no_build) if status == "missing" or args.m2c else None

    if args.json:
        result.update(
            function=function,
            size=int(func["size"]),
            percent=percent,
            status=status,
            matched=status == "match",
            diff=[
                {"mark": m, "offset": t.offset if t else None, "target": t.text if t else None, "base": b.text if b else None}
                for m, t, b in rows
                if m != " "
            ],
        )
        if draft is not None:
            result["m2c"] = draft
        print(json.dumps(result, indent=1))
        return EXIT_MATCH if status == "match" else EXIT_MISMATCH

    built = f"  (built in {result['build']['seconds']:.2f}s)" if "build" in result else ""
    shown = f"{percent:.2f}%" if percent is not None else "-"
    print(f"{unit['name']}  {result['source']}{built}")
    print(f"{function}  size {int(func['size']):#x}  {shown}  {status.upper()}")
    if status == "missing":
        print("not in the source yet; target assembly:")
        print_listing(target, target_syms, args.max_lines, args.full)
        print_draft(draft, function, args.max_lines, args.full)
        return EXIT_MISMATCH
    if status == "reloc":
        print(RELOC_NOTE)
        if unit.get("metadata", {}).get("complete"):
            print(LINKED_NOTE)
    if status != "match" or args.full:
        print_diff(rows, target_syms, base_syms, args.context, args.max_lines, args.full)
    print_draft(draft, function, args.max_lines, args.full)
    return EXIT_MATCH if status == "match" else EXIT_MISMATCH


if __name__ == "__main__":
    try:
        sys.exit(main())
    except UsageError as e:
        print(f"error: {e}", file=sys.stderr)
        sys.exit(EXIT_USAGE)
