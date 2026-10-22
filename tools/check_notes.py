#!/usr/bin/env python3

###
# Checks that no lesson heading (a bullet starting "- **heading**") appears
# twice in docs/matching-notes.md and docs/matching-notes/*.md.
#
# .gitattributes merges these files with git's union driver, so a rebase keeps
# both sides' lessons without stopping. When two branches edit the same
# lesson, the merge keeps both versions of it; this check finds them, and the
# fix is to combine them into one. When one version only extends the other
# (the usual case: a worker added a sentence), --fix deletes the shorter one.
#
# Usage:
#   python3 tools/check_notes.py [--fix]
###

import glob
import os
import re
import sys
from typing import Dict, List, Tuple

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))

HEADING = re.compile(r"^- \*\*(.+?)\*\*")


def drop_extended(places: List[Tuple[str, int]]) -> bool:
    """Delete the bullets another bullet with the same heading extends."""
    lines = {}
    for path, number in places:
        with open(os.path.join(root_dir, path)) as f:
            lines[(path, number)] = f.readlines()[number - 1].rstrip("\n")
    keep = max(lines, key=lambda place: len(lines[place]))
    drop = [place for place in lines if place != keep]
    if not all(lines[keep].startswith(lines[place].rstrip(". ")) for place in drop):
        return False
    for path, number in sorted(drop, reverse=True):
        full = os.path.join(root_dir, path)
        with open(full) as f:
            content = f.readlines()
        del content[number - 1]
        with open(full, "w") as f:
            f.writelines(content)
    return True


def main() -> int:
    fix = "--fix" in sys.argv[1:]
    files = [os.path.join(root_dir, "docs", "matching-notes.md")]
    files += sorted(glob.glob(os.path.join(root_dir, "docs", "matching-notes", "*.md")))
    seen: Dict[str, List[Tuple[str, int]]] = {}
    for path in files:
        with open(path) as f:
            for number, line in enumerate(f, 1):
                m = HEADING.match(line)
                if m:
                    seen.setdefault(m.group(1).strip().rstrip("."), []).append(
                        (os.path.relpath(path, root_dir), number))
    duplicates = {heading: places for heading, places in seen.items() if len(places) > 1}
    if fix:
        fixed = [heading for heading, places in duplicates.items() if drop_extended(places)]
        for heading in fixed:
            print(f"Kept the fuller bullet: {heading}")
        if fixed:
            return main_check()
    if not duplicates:
        print(f"Notes OK: {len(seen)} lessons in {len(files)} files, no heading repeated")
        return 0
    for heading, places in duplicates.items():
        print(f"{heading}: " + ", ".join(f"{path}:{line}" for path, line in places))
    print("Combine each repeated lesson into one bullet "
          "(--fix does it where one version extends the other).", file=sys.stderr)
    return 1


def main_check() -> int:
    sys.argv = sys.argv[:1]
    return main()


if __name__ == "__main__":
    sys.exit(main())
