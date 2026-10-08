#!/usr/bin/env python3

###
# Checks that no lesson heading (a bullet starting "- **heading**") appears
# twice in docs/matching-notes.md and docs/matching-notes/*.md.
#
# .gitattributes merges these files with git's union driver, so a rebase keeps
# both sides' lessons without stopping. When two branches edit the same
# lesson, the merge keeps both versions of it; this check finds them, and the
# fix is to combine them into one.
#
# Usage:
#   python3 tools/check_notes.py
###

import glob
import os
import re
import sys
from typing import Dict, List, Tuple

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))

HEADING = re.compile(r"^- \*\*(.+?)\*\*")


def main() -> int:
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
    if not duplicates:
        print(f"Notes OK: {len(seen)} lessons in {len(files)} files, no heading repeated")
        return 0
    for heading, places in duplicates.items():
        print(f"{heading}: " + ", ".join(f"{path}:{line}" for path, line in places))
    print("Combine each repeated lesson into one bullet.", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
