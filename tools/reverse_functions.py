#!/usr/bin/env python3

###
# Puts a source file's functions in reverse address order.
#
# Units built with -inline deferred (every REL unit, and main-DOL units whose
# configure.py entry adds it) have MWCC generate functions last to first, so
# their source lists functions from the highest address down. Upstream's
# placeholder files list them in address order.
#
# A function is its "// .text:0x... size:0x..." line, the comment lines just
# above it, and everything down to the first unindented line ending in "}".
# Anything else between functions (data, macros, helpers without a .text line)
# would change layout if moved, so the script refuses and names the line.
#
# Usage:
#   python3 tools/reverse_functions.py <source file>...
###

import re
import sys
from typing import List, Tuple

TEXT_LINE = re.compile(r"^// \.text:0x([0-9A-Fa-f]+) size:")


class Refusal(Exception):
    pass


def split(lines: List[str]) -> Tuple[List[str], List[Tuple[int, List[str]]], List[str]]:
    starts = [i for i, line in enumerate(lines) if TEXT_LINE.match(line)]
    if not starts:
        raise Refusal("no '// .text:' lines")
    blocks = []
    end = None
    for n, i in enumerate(starts):
        start = i
        while start > 0 and lines[start - 1].startswith("//"):
            start -= 1
        if end is not None:
            for j in range(end + 1, start):
                if lines[j].strip():
                    raise Refusal(f"line {j + 1} is between functions: {lines[j].strip()!r}")
        else:
            preamble = lines[:start]
        limit = starts[n + 1] if n + 1 < len(starts) else len(lines)
        # The closing brace starts a line, or ends a one-line function
        close = next((j for j in range(i + 1, limit)
                      if lines[j].rstrip().endswith("}") and not lines[j][:1].isspace()), None)
        if close is None:
            raise Refusal(f"no closing '}}' for the function at line {i + 1}")
        end = close
        blocks.append((int(TEXT_LINE.match(lines[i]).group(1), 16), lines[start : close + 1]))
    rest = lines[end + 1 :]
    for j, line in enumerate(rest):
        if line.strip():
            raise Refusal(f"line {end + 2 + j} follows the last function: {line.strip()!r}")
    while preamble and not preamble[-1].strip():
        preamble.pop()
    return preamble, blocks, rest


def reverse(path: str) -> str:
    with open(path) as f:
        lines = f.read().split("\n")
    preamble, blocks, _ = split(lines)
    addresses = [a for a, _ in blocks]
    if addresses == sorted(addresses, reverse=True):
        return "already in reverse address order"
    if addresses != sorted(addresses):
        raise Refusal("functions are in neither address order nor reverse address order")
    out = list(preamble)
    for _, block in reversed(blocks):
        out += [""] + block
    with open(path, "w") as f:
        f.write("\n".join(out) + "\n")
    return f"reversed {len(blocks)} functions"


def main() -> int:
    if len(sys.argv) < 2:
        print("usage: python3 tools/reverse_functions.py <source file>...", file=sys.stderr)
        return 3
    status = 0
    for path in sys.argv[1:]:
        try:
            print(f"{path}: {reverse(path)}")
        except Refusal as e:
            print(f"{path}: not changed, {e}; reorder it by hand", file=sys.stderr)
            status = 1
    return status


if __name__ == "__main__":
    sys.exit(main())
