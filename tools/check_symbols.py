#!/usr/bin/env python3

###
# Checks that every placeholder symbol name used in src/ and include/
# (lbl_..., fn_...) is a symbol in config/<version>/**/symbols.txt.
#
# A name missing from symbols.txt still compiles, but the unit cannot link,
# and objdiff's progress report still scores the function 100% because it
# ignores relocation targets. This happens when source declares its own
# placeholder for an address symbols.txt has since named, or when a symbol is
# renamed in symbols.txt but not in the source.
#
# Labels defined in the same file (inside asm functions) are allowed.
#
# Usage:
#   python3 tools/check_symbols.py [--version GYQE01]
###

import argparse
import glob
import os
import re
import sys
from typing import Dict, List, Set, Tuple

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))

# dtk's generated names: lbl_3_data_5B34, lbl_3_common_bss_34C58,
# lbl_800E8754, fn_3_16943C, fn_800247E4
PLACEHOLDER = re.compile(r"\b(?:lbl|fn)_(?:\d+_(?:[a-z0-9]+_)*[0-9A-F]+|8[0-9A-F]{7})\b")
COMMENT = re.compile(r"//[^\n]*|/\*.*?\*/", re.S)
SYMBOL_LINE = re.compile(r"^(\S+) = ")


def symbol_names(version: str) -> Set[str]:
    names: Set[str] = set()
    pattern = os.path.join(root_dir, "config", version, "**", "symbols.txt")
    for path in glob.glob(pattern, recursive=True):
        with open(path) as f:
            for line in f:
                m = SYMBOL_LINE.match(line)
                if m:
                    names.add(m.group(1))
    return names


def unknown_names(path: str, names: Set[str]) -> List[Tuple[int, str]]:
    with open(path, errors="replace") as f:
        text = f.read()
    labels = set(re.findall(r"^\s*(\w+):", text, re.M))
    # Blank out comments but keep their newlines so line numbers stay right
    code = COMMENT.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), text)
    found = []
    for m in PLACEHOLDER.finditer(code):
        name = m.group(0)
        if name not in names and name not in labels:
            found.append((code.count("\n", 0, m.start()) + 1, name))
    return found


def main() -> int:
    parser = argparse.ArgumentParser(description="Check placeholder symbol names against symbols.txt.")
    parser.add_argument("--version", default="GYQE01", help="game version (default GYQE01)")
    args = parser.parse_args()

    names = symbol_names(args.version)
    if not names:
        print(f"error: no symbols.txt found under config/{args.version}", file=sys.stderr)
        return 2

    problems: Dict[str, List[Tuple[int, str]]] = {}
    files = sorted(
        glob.glob(os.path.join(root_dir, "src", "**", "*.[ch]"), recursive=True)
        + glob.glob(os.path.join(root_dir, "include", "**", "*.h"), recursive=True)
    )
    for path in files:
        found = unknown_names(path, names)
        if found:
            problems[os.path.relpath(path, root_dir)] = found

    if not problems:
        print(f"Symbol names OK: {len(files)} files checked against config/{args.version}")
        return 0
    for path, found in problems.items():
        for line, name in found:
            print(f"{path}:{line}: {name} is not in config/{args.version}/**/symbols.txt")
    print(
        "Use the name symbols.txt gives that address (or rename it there and in every file that uses it).",
        file=sys.stderr,
    )
    return 1


if __name__ == "__main__":
    sys.exit(main())
