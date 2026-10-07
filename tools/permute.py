#!/usr/bin/env python3

###
# Sets up decomp-permuter (https://github.com/simonlindholm/decomp-permuter)
# for one function, so it can search for source changes that fix the
# remaining differences (it is best at register allocation).
#
# Usage:
#   python3 tools/permute.py <unit> <function>
#   python3 tools/permute.py <function>
#   then run the command it prints, e.g.
#   (cd ~/.local/share/decomp-permuter && .venv/bin/python permuter.py nonmatchings/<function> -j 8 --stop-on-zero)
#
# The permuter is found in $PERMUTER_DIR (default ~/.local/share/decomp-permuter).
# Its import.py is not used: on macOS it needs Homebrew GCC's cpp, and its
# per-function stripping breaks this project's builds, which use
# -inline auto/deferred. Instead this script:
#   - preprocesses the whole source file and keeps every function, marking
#     `inline` the same-file functions the original build inlines into this
#     one (the permuter drops the bodies of all other functions);
#   - assembles the function's original assembly as the target;
#   - writes a compile.sh with the unit's real compiler flags;
#   - scores only this function (objdump --disassemble=<function>);
#   - checks that what the permuter compiles equals the project build.
#
# The permuter often finds changes that only work by accident (e.g. reusing
# an unrelated variable); take the idea, not the literal code.
###

import argparse
import os
import re
import shlex
import shutil
import subprocess
import sys
from typing import Any, Dict, List, Set, Tuple

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))
sys.path.insert(0, script_dir)
import match  # noqa: E402

permuter_dir = os.path.expanduser(os.environ.get("PERMUTER_DIR", "~/.local/share/decomp-permuter"))
binutils_dir = os.path.join(root_dir, "build", "binutils")
include_dir = os.path.join(root_dir, "build", "GYQE01", "include")

FN_DEF = re.compile(r"^(?P<head>(?![ \t#])[^\n;{}()]*\b(?P<name>\w+)\s*\([^;{}]*\))\s*\{", re.M)


def compile_command(unit: Dict[str, Any]) -> List[str]:
    # The unit's compiler invocation from build.ninja, minus -MMD, -c, -o and
    # the dependency-file post-processing step.
    base = unit["base_path"]
    out = subprocess.run(["ninja", "-t", "commands", base], cwd=root_dir, capture_output=True, text=True, check=True)
    parts = shlex.split(out.stdout.strip().splitlines()[-1].split(" && ")[0])
    cut = parts.index("-MMD")
    expected = ["-MMD", "-c", unit["metadata"]["source_path"], "-o", os.path.dirname(base)]
    if parts[cut:] != expected:
        raise match.UsageError(f"unexpected compile command for {base}: {' '.join(parts)}")
    return parts[:cut]


def preprocess(unit: Dict[str, Any], flags: List[str]) -> str:
    compiler = shutil.which("cc") or shutil.which("gcc") or shutil.which("clang")
    if compiler is None:
        raise match.UsageError("no C preprocessor found (cc, gcc or clang)")
    command = [compiler, "-E", "-P", "-undef", "-nostdinc", "-x", "c", *match.CONTEXT_DEFINES]
    args = iter(flags)
    for arg in args:
        if arg == "-i":
            command += ["-I", next(args)]
        elif arg.startswith("-D") and "{" not in arg:
            command.append(arg)
    command.append(unit["metadata"]["source_path"])
    text = subprocess.run(command, cwd=root_dir, capture_output=True, text=True, check=True).stdout
    return match.strip_asm(text)


def brace_end(text: str, start: int) -> int:
    depth = 0
    for i in range(start, len(text)):
        depth += {"{": 1, "}": -1}.get(text[i], 0)
        if depth == 0:
            return i + 1
    raise match.UsageError("unbalanced braces in the preprocessed source")


def mark_inlined(text: str, function: str, call_targets: Set[str]) -> Tuple[str, List[str]]:
    # Same-file functions called in the source (directly or through another
    # inlined function) but never called with bl in the compiled function.
    defs = {}
    for m in FN_DEF.finditer(text):
        if m.group("name") not in ("if", "for", "while", "switch"):
            defs[m.group("name")] = (m, text[m.end() - 1 : brace_end(text, m.end() - 1)])
    if function not in defs:
        raise match.UsageError(f"{function} is not defined in the preprocessed source")
    inlined: List[str] = []
    todo = [function]
    while todo:
        body = defs[todo.pop()][1]
        for callee in sorted(set(re.findall(r"\b(\w+)\s*\(", body))):
            if callee in defs and callee != function and callee not in call_targets and callee not in inlined:
                inlined.append(callee)
                todo.append(callee)
    for name in sorted(inlined, key=lambda n: -defs[n][0].start()):
        m = defs[name][0]
        head = m.group("head")
        if re.search(r"\binline\b", head):
            continue
        new = head.replace("static ", "static inline ", 1) if head.startswith("static ") else "inline " + head
        text = text[: m.start()] + new + text[m.start() + len(head) :]
    return text, inlined


def permuter_view(text: str, function: str) -> str:
    # What the permuter actually compiles: its own parse, extract_fn and normalize
    sys.path.insert(0, permuter_dir)
    from src import ast_util  # type: ignore

    ast = ast_util.parse_c(text)
    fn, _ = ast_util.extract_fn(ast, function)
    ast_util.normalize_ast(fn, ast)
    return ast_util.to_c(ast)


def target_asm(unit: Dict[str, Any], function: str) -> str:
    lines = open(match.asm_path(unit)).read().splitlines()
    starts = [i for i, line in enumerate(lines) if re.match(rf"^\.fn {re.escape(function)},", line)]
    if not starts:
        raise match.UsageError(f"{function} not found in {match.asm_path(unit)}")
    end = lines.index(f".endfn {function}", starts[0])
    return '.include "macros.inc"\n.text\n.balign 4\n' + "\n".join(lines[starts[0] : end + 1]) + "\n"


def write_compile_script(path: str, flags: List[str]) -> None:
    with open(path, "w") as f:
        f.write("#!/usr/bin/env bash\nset -euo pipefail\n")
        # macOS realpath needs the file to exist, so resolve the output via its directory
        f.write('INPUT="$(realpath "$1")"\nOUTPUT="$(cd "$(dirname "$3")" && pwd)/$(basename "$3")"\n')
        f.write(f"cd {shlex.quote(root_dir)}\n")
        f.write(" ".join(shlex.quote(a) for a in flags) + ' -c "$INPUT" -o "$OUTPUT"\n')
    os.chmod(path, 0o755)


def main() -> int:
    parser = argparse.ArgumentParser(description="Set up decomp-permuter for one function.")
    parser.add_argument("unit", help="unit name, source path or basename, or a function name")
    parser.add_argument("function", nargs="?", help="function to permute")
    parser.add_argument("-o", "--out", help="output directory (default: <permuter>/nonmatchings/<function>)")
    args = parser.parse_args()

    if not os.path.exists(os.path.join(permuter_dir, "permuter.py")):
        raise match.UsageError(
            f"decomp-permuter not found in {permuter_dir}; clone "
            "https://github.com/simonlindholm/decomp-permuter there (or set $PERMUTER_DIR) "
            "and install its requirements: python3 -m pip install toml Levenshtein"
        )

    units = match.load_units()
    unit = match.resolve_unit(args.unit, units)
    function = args.function
    if unit is None and function is None:
        owners = match.find_function_unit(match.generate_report(), args.unit)
        if len(owners) != 1:
            raise match.UsageError(f"cannot find a unique unit for '{args.unit}'")
        unit = next(u for u in units if u["name"] == owners[0])
        function = args.unit
    if unit is None or function is None or "base_path" not in unit:
        raise match.UsageError("give a unit with source and a function")

    ok, _, output = match.build(unit)
    if not ok:
        raise match.UsageError("build failed:\n" + match.build_errors(output))

    out_dir = args.out or os.path.join(permuter_dir, "nonmatchings", function)
    os.makedirs(out_dir, exist_ok=True)
    # An earlier run on this function, perhaps from another worktree, left its
    # results here; they would mix with this run's
    stale = [d for d in os.listdir(out_dir) if d.startswith("output-")]
    for d in stale:
        shutil.rmtree(os.path.join(out_dir, d))
    if stale:
        print(f"removed {len(stale)} output folders from an earlier run in {out_dir}")
    flags = compile_command(unit)

    project_o = os.path.join(root_dir, unit["base_path"])
    project_syms = match.read_symbols(project_o)
    project_insns = match.disassemble(project_o, function, project_syms)
    if not project_insns:
        raise match.UsageError(f"{function} is not in {unit['base_path']}; write a first version (match.py --m2c) first")
    call_targets = {i.text.split()[1] for i in project_insns if i.text.startswith("bl ")}
    source, inlined = mark_inlined(preprocess(unit, flags), function, call_targets)
    if inlined:
        print(f"marked inline (the original build inlines them): {', '.join(inlined)}")
    with open(os.path.join(out_dir, "base.c"), "w") as f:
        f.write(source)

    target_s = os.path.join(out_dir, "target.s")
    with open(target_s, "w") as f:
        f.write(target_asm(unit, function))
    subprocess.run(
        [os.path.join(binutils_dir, "powerpc-eabi-as"), "-mgekko", "-I", include_dir, target_s, "-o",
         os.path.join(out_dir, "target.o")],
        check=True,
    )

    compile_sh = os.path.join(out_dir, "compile.sh")
    write_compile_script(compile_sh, flags)

    objdump_command = [os.path.join(binutils_dir, "powerpc-eabi-objdump"), "-dr", "-EB", "-mpowerpc", "-M",
                       "broadway", f"--disassemble={function}"]
    with open(os.path.join(out_dir, "settings.toml"), "w") as f:
        f.write(f'func_name = "{function}"\ncompiler_type = "mwcc"\n')
        f.write(f'objdump_command = "{" ".join(objdump_command)}"\n')

    # What the permuter compiles must equal the project build, or its scores mislead
    view_c, view_o = os.path.join(out_dir, "permuter_view.c"), os.path.join(out_dir, "permuter_view.o")
    with open(view_c, "w") as f:
        f.write(permuter_view(source, function))
    subprocess.run([compile_sh, view_c, "-o", view_o], check=True, capture_output=True)
    view_syms = match.read_symbols(view_o)
    rows = match.function_diff(match.disassemble(view_o, function, view_syms), project_insns, view_syms, project_syms)
    differing = sum(1 for row in rows if row[0] != " ")
    if differing:
        print(f"warning: the permuter's view compiles differently from {unit['base_path']} "
              f"({differing} lines); its scores will be off", file=sys.stderr)

    inside = os.path.commonpath([os.path.abspath(out_dir), permuter_dir]) == permuter_dir
    rel = os.path.relpath(out_dir, permuter_dir) if inside else os.path.abspath(out_dir)
    print(f"ready: {out_dir}")
    print(f"run:   (cd {shlex.quote(permuter_dir)} && .venv/bin/python permuter.py {shlex.quote(rel)} -j 8 --stop-on-zero)")
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except match.UsageError as e:
        print(f"error: {e}", file=sys.stderr)
        sys.exit(match.EXIT_USAGE)
