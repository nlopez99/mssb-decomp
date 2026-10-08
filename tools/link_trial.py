#!/usr/bin/env python3

###
# Tries linking units. For each unit (by default every NonMatching unit whose
# code objdiff's report scores fully matched) it switches the configure.py
# entry to Matching, builds, and keeps the change only if the build still
# passes its hash check (config/<version>/build.sha1); otherwise it restores
# the entry. A unit that fails usually has a .rodata constant order, .data
# alignment padding or an unreferenced .bss object left to fix (see
# docs/matching-notes.md).
#
# Run it in a checkout whose configure.py has no uncommitted changes; it
# leaves the kept switches for you to commit.
#
# Usage:
#   python3 tools/link_trial.py [unit ...]
###

import argparse
import json
import os
import subprocess
import sys
from typing import List

script_dir = os.path.dirname(os.path.realpath(__file__))
sys.path.insert(0, script_dir)
import match  # noqa: E402
import regress  # noqa: E402

root_dir = regress.root_dir
configure = os.path.join(root_dir, "configure.py")


def build_ok() -> bool:
    if subprocess.run(["ninja"], cwd=root_dir, capture_output=True).returncode != 0:
        return False
    sha1 = os.path.join("config", regress.VERSION, "build.sha1")
    dtk = os.path.join(root_dir, "build", "tools", "dtk")
    return subprocess.run([dtk, "shasum", "-c", sha1], cwd=root_dir, capture_output=True).returncode == 0


def candidates(units: List[dict], text: str) -> List[dict]:
    report = regress.report(root_dir)
    found = []
    for unit in units:
        measures = report.get(unit["name"], {}).get("measures", {})
        total = int(measures.get("total_code", 0))
        entry = entry_for(unit, "NonMatching")
        if total and int(measures.get("matched_code", 0)) == total and entry in text:
            found.append(unit)
    return found


def entry_for(unit: dict, status: str) -> str:
    source = unit.get("metadata", {}).get("source_path", "")
    return f'Object({status}, "{source[len("src/"):]}")'


def main() -> int:
    parser = argparse.ArgumentParser(description="Link units whose code matches, keeping those that pass the hash check.")
    parser.add_argument("units", nargs="*", help="units to try (default: every fully matched NonMatching unit)")
    args = parser.parse_args()

    if regress.git("status", "--porcelain", "--", "configure.py"):
        raise match.UsageError("configure.py has uncommitted changes")
    if not build_ok():
        raise match.UsageError("this checkout does not build or fails its hash check before any change")
    with open(os.path.join(root_dir, "objdiff.json")) as f:
        units = json.load(f)["units"]
    with open(configure) as f:
        text = f.read()
    if args.units:
        chosen = []
        for query in args.units:
            unit = match.resolve_unit(query, units)
            if not unit:
                raise match.UsageError(f"no unit matches {query}")
            chosen.append(unit)
    else:
        chosen = candidates(units, text)
        print(f"{len(chosen)} NonMatching units with all code matched in objdiff's report")

    kept = []
    for unit in chosen:
        old, new = entry_for(unit, "NonMatching"), entry_for(unit, "Matching")
        if old not in text:
            print(f"{unit['name']}: no {old} in configure.py")
            continue
        with open(configure, "w") as f:
            f.write(text.replace(old, new))
        if build_ok():
            text = text.replace(old, new)
            kept.append(unit["name"])
            print(f"{unit['name']}: linked, hash OK")
        else:
            with open(configure, "w") as f:
                f.write(text)
            print(f"{unit['name']}: hash check FAILED, restored")
    build_ok()
    print(f"kept {len(kept)}: {' '.join(kept) or 'none'}")
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except match.UsageError as e:
        print(f"error: {e}", file=sys.stderr)
        sys.exit(3)
