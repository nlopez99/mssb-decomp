#!/usr/bin/env python3
# Check that a change leaves every built object the same, for cleanups of
# declarations and includes that must not change code or data anywhere.
# regress.py misses such a change inside a function that was already partial.
#
#   python3 tools/compare_objects.py save      # before the change
#   python3 tools/compare_objects.py compare   # after it and a full ninja
#
# Objects are compared section by section, with their relocations and
# symbols; .line, .debug, .comment and compiler-generated label numbers
# (@123) may differ.

import argparse
import glob
import os
import re
import shutil
import subprocess
import sys

root_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
build_dir = os.path.join(root_dir, "build", "GYQE01")
saved_dir = os.path.join(root_dir, "build", "compare_objects")
objdump = os.path.join(root_dir, "build", "binutils", "powerpc-eabi-objdump")
ignored = re.compile(r"^\.(line|debug|comment|mwcats)")
label = re.compile(r"@\d+")


def objects(top: str):
    return sorted(os.path.relpath(p, top) for p in glob.glob(os.path.join(top, "**", "*.o"), recursive=True))


def run(*args: str) -> str:
    return subprocess.run([objdump, *args], capture_output=True, text=True).stdout


def contents(path: str):
    # A compiler-generated label is renamed to where it points, since its
    # number may change while a load of another constant must not look equal
    table = run("-t", path).splitlines()[4:]
    where = {}
    for line in table:
        fields = line.split()
        if fields and label.fullmatch(fields[-1]):
            where[fields[-1]] = f"<{fields[-3]}+{fields[0]}>"

    def place(text: str) -> str:
        return label.sub(lambda m: where.get(m.group(0), "@N"), text)

    sections = []
    for line in run("-h", path).splitlines():
        m = re.match(r"\s*\d+\s+(\S+)\s+([0-9a-f]+)", line)
        if m and not ignored.match(m.group(1)):
            sections.append((m.group(1), m.group(2)))
    out = [repr(sections)]
    for name, _ in sections:
        out.append(run("-s", "-j", name, path).split("\n", 3)[-1])
    relocs, keep = [], True
    for line in run("-r", path).splitlines()[2:]:
        m = re.match(r"RELOCATION RECORDS FOR \[(.*)\]", line)
        if m:
            keep = not ignored.match(m.group(1))
        if keep:
            relocs.append(place(line))
    out.append("\n".join(relocs))
    symbols = [place(line) for line in table if line.strip() and not re.search(r"\s\.(line|debug)", line)]
    out.append("\n".join(sorted(symbols)))
    return out


def main() -> int:
    parser = argparse.ArgumentParser(description="Check that a change leaves every built object the same.")
    parser.add_argument("action", choices=["save", "compare"])
    args = parser.parse_args()

    if args.action == "save":
        shutil.rmtree(saved_dir, ignore_errors=True)
        for rel in objects(build_dir):
            os.makedirs(os.path.dirname(os.path.join(saved_dir, rel)), exist_ok=True)
            shutil.copy2(os.path.join(build_dir, rel), os.path.join(saved_dir, rel))
        print(f"saved {len(objects(saved_dir))} objects in {os.path.relpath(saved_dir, root_dir)}")
        return 0

    if not os.path.isdir(saved_dir):
        print("compare_objects: nothing saved; run `save` before the change", file=sys.stderr)
        return 2
    differ = []
    for rel in objects(saved_dir):
        old, new = os.path.join(saved_dir, rel), os.path.join(build_dir, rel)
        if not os.path.exists(new):
            differ.append(f"{rel} (missing)")
        elif open(old, "rb").read() != open(new, "rb").read() and contents(old) != contents(new):
            differ.append(rel)
    print(f"compare_objects: {len(objects(saved_dir))} objects, {len(differ)} differ")
    for rel in differ:
        print(f"  {rel}")
    return 1 if differ else 0


if __name__ == "__main__":
    sys.exit(main())
