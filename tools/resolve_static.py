#!/usr/bin/env python3
# Resolve a merge conflict between two branches that each added main-DOL
# units under static/: keep both sides' entries in config/GYQE01/splits.txt
# and configure.py, sorted by each unit's .text start. Run it in the
# conflicted worktree, check the build, then `git add` both files.

import os
import re
import sys

root_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
splits_path = os.path.join(root_dir, "config", "GYQE01", "splits.txt")
configure_path = os.path.join(root_dir, "configure.py")
conflict = re.compile(r"^<<<<<<< .*\n((?:.*\n)*?)^=======\n((?:.*\n)*?)^>>>>>>> .*\n", re.M)


def keep_both(text: str) -> str:
    return conflict.sub(lambda m: m.group(1) + m.group(2), text)


def contiguous(indexes, what: str) -> None:
    if indexes != list(range(indexes[0], indexes[-1] + 1)):
        sys.exit(f"resolve_static: the static/ {what} are not one run; resolve by hand")


def main() -> int:
    blocks = re.split(r"\n(?=\S)", keep_both(open(splits_path).read()))
    start = {}
    for block in blocks:
        m = re.match(r"(static/\S+\.c):", block)
        if m:
            start[m.group(1)] = int(re.search(r"\.text\s+start:0x([0-9A-F]+)", block).group(1), 16)
    units = [i for i, b in enumerate(blocks) if re.match(r"static/\S+\.c:", b)]
    contiguous(units, "splits.txt entries")
    ordered = sorted((blocks[i] for i in units), key=lambda b: start[b.split(":")[0]])
    blocks[units[0]:units[-1] + 1] = [b if b.endswith("\n") else b + "\n" for b in ordered]
    with open(splits_path, "w") as f:
        f.write("\n".join(blocks))

    lines = keep_both(open(configure_path).read()).split("\n")
    entries = [i for i, line in enumerate(lines) if re.search(r'Object\(\w+, "static/', line)]
    contiguous(entries, "configure.py entries")
    names = [re.search(r'"(static/[^"]+)"', lines[i]).group(1) for i in entries]
    if len(set(names)) != len(names):
        sys.exit("resolve_static: both sides changed one unit's entry; resolve by hand")
    lines[entries[0]:entries[-1] + 1] = sorted((lines[i] for i in entries),
                                               key=lambda line: start[re.search(r'"(static/[^"]+)"', line).group(1)])
    with open(configure_path, "w") as f:
        f.write("\n".join(lines))
    print(f"resolve_static: {len(units)} static/ units in address order")
    return 0


if __name__ == "__main__":
    sys.exit(main())
