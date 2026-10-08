#!/usr/bin/env python3

###
# Compares the function prototypes declared at the top level of src/ and
# include/, ignoring parameter names, and lists the cleanup they need:
#   - placeholders: a header declares void(void) (a stub's placeholder) while
#     other files declare the real signature; the stub's owner fixes them;
#   - local externs that disagree with a header, which the skill allows while
#     the header is wrong; cleanup moves them into the header;
#   - local externs a header already declares the same way.
# Only declarations that involve REL code (src/ or include/ game, menus,
# challenge) are listed.
#
# It fails when two declarations of a REL function (one in config/<version>/
# {game,menus,challenge}/symbols.txt) disagree on the calling convention: the
# number of parameters, or whether a parameter or the return value is an
# integer, a float or a pointer (a void return is compatible with any). At
# most one of them is right. Main-DOL functions are listed without failing:
# units still declare them locally, with their own types, until the main DOL
# has a shared header.
#
# Usage:
#   python3 tools/check_prototypes.py [--version GYQE01]
#
# Exit codes: 0 = no REL conflicts, 1 = REL conflicts found.
###

import argparse
import glob
import os
import re
import sys
from collections import defaultdict
from typing import Dict, List, Set, Tuple

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))

COMMENT = re.compile(r"//[^\n]*|/\*.*?\*/", re.S)
# One-line declarations at column 0: "extern s32 fn(s32 a, f32 b);"
DECLARATION = re.compile(
    r"^(?:extern\s+)?(?!(?:return|typedef|static|else|case|goto|do)\b)"
    r"([A-Za-z_][\w \t\*]*?[\s\*])([A-Za-z_]\w*)[ \t]*\(([^;{}]*)\)[ \t]*;", re.M)
NAMED_PARAM = re.compile(r"^(.*?[\s\*])([A-Za-z_]\w*)((?:\[[^\]]*\])*)$")
# Array parameters decay to pointers
DECAYED = {"Mtx": "MtxPtr", "Mtx44": "Mtx44Ptr"}
KEYWORDS = {"const", "volatile", "unsigned", "signed", "struct", "union", "enum", "long", "short", "int", "char"}
FLOATS = {"f32", "f64", "float", "double"}
MODULES = ("game", "menus", "challenge")
PLACEHOLDER = "void(void)"

Declaration = Tuple[str, int, str]  # path, line, signature


def clean_type(text: str) -> str:
    text = re.sub(r"\b(?:extern|struct|union|enum)\s+", "", text)
    text = re.sub(r"\s*\*\s*", "*", text)
    return re.sub(r"\s+", " ", text).strip()


def clean_param(param: str) -> str:
    param = param.strip()
    m = NAMED_PARAM.match(param)
    if m and m.group(1).strip() and m.group(2) not in KEYWORDS:
        param = m.group(1) + ("*" if m.group(3) else "")
    param = clean_type(param)
    return DECAYED.get(param, param)


def split_params(params: str) -> List[str]:
    parts, depth, current = [], 0, ""
    for c in params:
        if c == "," and depth == 0:
            parts.append(current)
            current = ""
            continue
        depth += c == "("
        depth -= c == ")"
        current += c
    return parts + [current]


def balanced(params: str) -> bool:
    depth = 0
    for c in params:
        depth += (c == "(") - (c == ")")
        if depth < 0:
            return False
    return depth == 0


def declarations(path: str) -> List[Tuple[str, int, str]]:
    with open(path, errors="replace") as f:
        text = f.read()
    # Blank out comments but keep their newlines so line numbers stay right
    code = COMMENT.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), text)
    found = []
    for m in DECLARATION.finditer(code):
        ret, name, params = m.groups()
        # Skip "f()" (parameters unspecified), macros and function pointer variables
        if not params.strip() or name.isupper() or not clean_type(ret) or not balanced(params):
            continue
        signature = f"{clean_type(ret)}({', '.join(clean_param(p) for p in split_params(params))})"
        found.append((name, code.count("\n", 0, m.start()) + 1, signature))
    return found


def kind(type_name: str) -> str:
    if type_name == "...":
        return "..."
    if "*" in type_name or "(" in type_name or type_name.endswith("Ptr"):
        return "pointer"
    if type_name.split(" ")[-1] in FLOATS:
        return "float"
    return "void" if type_name == "void" else "int"


def convention(signature: str) -> Tuple[str, Tuple[str, ...]]:
    ret, params = signature[:-1].split("(", 1)
    kinds = tuple(kind(p.strip()) for p in split_params(params))
    return kind(ret), () if kinds == ("void",) else kinds


def conflicting(decls: List[Declaration]) -> bool:
    shapes = {convention(d[2]) for d in decls}
    returns = {ret for ret, _ in shapes} - {"void"}
    return len({params for _, params in shapes}) > 1 or len(returns) > 1


def rel_functions(version: str) -> Set[str]:
    names = set()
    for module in MODULES:
        path = os.path.join(root_dir, "config", version, module, "symbols.txt")
        if os.path.exists(path):
            with open(path) as f:
                names.update(line.split(" = ", 1)[0] for line in f if "type:function" in line)
    return names


def main() -> int:
    parser = argparse.ArgumentParser(description="Compare function prototypes across src/ and include/.")
    parser.add_argument("--version", default="GYQE01", help="game version (default GYQE01)")
    args = parser.parse_args()

    headers: Dict[str, List[Declaration]] = defaultdict(list)
    sources: Dict[str, List[Declaration]] = defaultdict(list)
    files = sorted(glob.glob(os.path.join(root_dir, "src", "**", "*.[ch]"), recursive=True)
                   + glob.glob(os.path.join(root_dir, "include", "**", "*.h"), recursive=True))
    for path in files:
        rel = os.path.relpath(path, root_dir)
        for name, line, signature in declarations(path):
            (headers if rel.endswith(".h") else sources)[name].append((rel, line, signature))
    rel_names = rel_functions(args.version)
    rel_dirs = tuple(os.path.join(top, m) + os.sep for top in ("src", "include") for m in MODULES)

    placeholders, disagree, redundant, rel_conflicts, dol_conflicts = [], [], [], [], []
    for name in sorted(set(headers) | set(sources)):
        stubs = [d for d in headers[name] if d[2] == PLACEHOLDER]
        real = [d for d in headers[name] if d[2] != PLACEHOLDER]
        known = real + [d for d in sources[name] if d[2] != PLACEHOLDER]
        if stubs and known:
            placeholders.append((name, stubs + known))
        signatures = {d[2] for d in real}
        for decl in sources[name]:
            if decl[2] in signatures:
                redundant.append((name, [decl] + real))
            elif signatures:
                disagree.append((name, [decl] + real))
        if conflicting(known):
            (rel_conflicts if name in rel_names else dol_conflicts).append((name, known))

    def show(title: str, items: List[Tuple[str, List[Declaration]]]) -> None:
        print(f"{title}: {len(items)}")
        for name, decls in items:
            print(f"  {name}: " + " | ".join(f"{path}:{line} {sig}" for path, line, sig in decls))

    def in_rel_code(items: List[Tuple[str, List[Declaration]]]) -> List[Tuple[str, List[Declaration]]]:
        return [(name, decls) for name, decls in items if any(d[0].startswith(rel_dirs) for d in decls)]

    show("Placeholders (a header declares void(void); the stub's owner gives it the real prototype)",
         in_rel_code(placeholders))
    show("Local externs that disagree with a header", in_rel_code(disagree))
    show("Local externs a header already declares the same way", in_rel_code(redundant))
    show("Main-DOL functions declared with different calling conventions (no shared header yet)",
         in_rel_code(dol_conflicts))
    show("FAIL: REL functions declared with different calling conventions" if rel_conflicts
         else "REL functions declared with different calling conventions", rel_conflicts)
    return 1 if rel_conflicts else 0


if __name__ == "__main__":
    sys.exit(main())
