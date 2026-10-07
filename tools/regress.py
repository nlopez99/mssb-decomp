#!/usr/bin/env python3

###
# Compares this checkout with a base commit and fails if anything got worse:
#   - the build must pass its hash check (config/<version>/build.sha1);
#   - no function's objdiff score may drop;
#   - no function may lose a strict match (tools/match.py's "match", which
#     also checks relocation targets).
# It also lists what improved; paste the summary into the pull request.
#
# The base defaults to the merge-base with origin/main. It is built once per
# commit in a git worktree under build/regress/, reusing this checkout's game
# files and tools. The comparison includes uncommitted changes.
#
# Usage:
#   python3 tools/regress.py [--base REF]
#
# Exit codes: 0 = no regressions, 1 = regression, 2 = build or hash check
#             failed, 3 = usage error.
###

import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
import tempfile
from typing import Any, Dict, Optional, Tuple

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))
sys.path.insert(0, script_dir)
import match  # noqa: E402

VERSION = "GYQE01"
EXIT_OK, EXIT_REGRESSION, EXIT_BUILD, EXIT_USAGE = 0, 1, 2, 3


def git(*args: str, cwd: str = root_dir) -> str:
    return subprocess.run(["git", *args], cwd=cwd, capture_output=True, text=True, check=True).stdout.strip()


def resolve_base(ref: Optional[str]) -> Tuple[str, str]:
    candidates = [ref] if ref else ["origin/main", "main"]
    for candidate in candidates:
        try:
            return git("merge-base", "HEAD", candidate), candidate
        except subprocess.CalledProcessError:
            continue
    raise match.UsageError(f"cannot find a merge-base with {' or '.join(candidates)}")


def tool_flags() -> list:
    # Point the base build at this checkout's tools so it downloads nothing
    build = os.path.join(root_dir, "build")
    paths = {
        "--dtk": os.path.join(build, "tools", "dtk"),
        "--objdiff": os.path.join(build, "tools", "objdiff-cli"),
        "--sjiswrap": os.path.join(build, "tools", "sjiswrap.exe"),
        "--wrapper": os.path.join(build, "tools", "wibo"),
        "--binutils": os.path.join(build, "binutils"),
        "--compilers": os.path.join(build, "compilers"),
    }
    missing = [p for p in paths.values() if not os.path.exists(p)]
    if missing:
        raise match.UsageError(f"build this checkout first (missing {', '.join(missing)})")
    return [arg for flag, path in paths.items() for arg in (flag, os.path.realpath(path))]


def link_game_files(checkout: str) -> None:
    for name in ("sys", "files"):
        source = os.path.realpath(os.path.join(root_dir, "orig", VERSION, name))
        if not os.path.isdir(source):
            raise match.UsageError(f"game files missing: {source}")
        os.symlink(source, os.path.join(checkout, "orig", VERSION, name))


def ensure_base_build(sha: str) -> str:
    regress_dir = os.path.join(root_dir, "build", "regress")
    base_dir = os.path.join(regress_dir, sha[:12])
    done = os.path.join(base_dir, ".regress-built")
    if os.path.exists(done):
        return base_dir

    # Keep only one base worktree around
    if os.path.isdir(regress_dir):
        for name in os.listdir(regress_dir):
            subprocess.run(["git", "worktree", "remove", "--force", os.path.join(regress_dir, name)],
                           cwd=root_dir, capture_output=True)
            shutil.rmtree(os.path.join(regress_dir, name), ignore_errors=True)
        git("worktree", "prune")
    os.makedirs(regress_dir, exist_ok=True)

    print(f"regress: building base {sha[:12]} in {os.path.relpath(base_dir, root_dir)} (once per base commit)")
    git("worktree", "add", "--detach", base_dir, sha)
    link_game_files(base_dir)
    subprocess.run([sys.executable, "configure.py", "--version", VERSION, *tool_flags()],
                   cwd=base_dir, check=True, capture_output=True)
    proc = subprocess.run(["ninja"], cwd=base_dir, capture_output=True, text=True)
    if proc.returncode != 0:
        raise match.UsageError("the base commit does not build:\n" + match.build_errors(proc.stdout + proc.stderr))
    open(done, "w").close()
    return base_dir


def report(project_dir: str) -> Dict[str, Any]:
    fd, path = tempfile.mkstemp(prefix="regress-report-", suffix=".json")
    os.close(fd)
    try:
        subprocess.run([match.objdiff_cli, "report", "generate", "-p", project_dir, "-o", path],
                       check=True, capture_output=True)
        with open(path) as f:
            return {u["name"]: u for u in json.load(f)["units"]}
    finally:
        os.unlink(path)


def file_hash(path: str) -> Optional[str]:
    if not os.path.exists(path):
        return None
    with open(path, "rb") as f:
        return hashlib.sha1(f.read()).hexdigest()


def strict_statuses(project_dir: str, unit: Dict[str, Any], report_unit: Dict[str, Any]) -> Dict[str, str]:
    target = os.path.join(project_dir, unit["target_path"])
    base = os.path.join(project_dir, unit["base_path"])
    if not os.path.exists(base):
        return {}
    target_syms, base_syms = match.read_symbols(target), match.read_symbols(base)
    statuses = {}
    for func in report_unit.get("functions", []):
        status = match.function_status(func)
        if status == "match":
            rows = match.function_diff(
                match.disassemble(target, func["name"], target_syms),
                match.disassemble(base, func["name"], base_syms),
                target_syms,
                base_syms,
            )
            if any(row[0] != " " for row in rows):
                status = "reloc"
        statuses[func["name"]] = status
    return statuses


def load_units(project_dir: str) -> Dict[str, Dict[str, Any]]:
    with open(os.path.join(project_dir, "objdiff.json")) as f:
        return {u["name"]: u for u in json.load(f)["units"]}


def main() -> int:
    parser = argparse.ArgumentParser(description="Fail if this checkout regresses any function against a base commit.")
    parser.add_argument("--base", help="ref to compare against (default: merge-base with origin/main)")
    args = parser.parse_args()

    base_sha, base_ref = resolve_base(args.base)
    head = git("rev-parse", "--short=12", "HEAD")
    dirty = git("status", "--porcelain", "--untracked-files=no")
    print(f"regress: {head}{' + uncommitted changes' if dirty else ''} vs {base_sha[:12]} (merge-base with {base_ref})")

    proc = subprocess.run(["ninja"], cwd=root_dir, capture_output=True, text=True)
    if proc.returncode != 0:
        print("build: FAILED\n" + match.build_errors(proc.stdout + proc.stderr))
        return EXIT_BUILD
    dtk = os.path.join(root_dir, "build", "tools", "dtk")
    sha1 = os.path.join("config", VERSION, "build.sha1")
    check = subprocess.run([dtk, "shasum", "-c", sha1], cwd=root_dir, capture_output=True, text=True)
    outputs = sum(1 for line in check.stdout.splitlines() if line.strip())
    if check.returncode != 0:
        print(f"build: hash check FAILED\n{check.stdout}{check.stderr}")
        return EXIT_BUILD
    print(f"build: OK ({outputs} outputs match {sha1})")

    base_dir = ensure_base_build(base_sha)
    before, after = report(base_dir), report(root_dir)

    # objdiff scores, per function
    def scores(units: Dict[str, Any]) -> Dict[Tuple[str, str], float]:
        return {(u, f["name"]): f.get("fuzzy_match_percent", 0.0) for u, unit in units.items()
                for f in unit.get("functions", [])}

    old, new = scores(before), scores(after)
    keys = sorted(set(old) | set(new))
    dropped = [(k, old.get(k), new.get(k)) for k in keys if k in old and k in new and new[k] < old[k]]
    raised = [(k, old.get(k), new.get(k)) for k in keys if k in old and k in new and new[k] > old[k]]
    vanished = [k for k in keys if k in old and k not in new]
    appeared = [k for k in keys if k not in old and k in new]
    print(f"objdiff scores: {len(raised)} improved, {len(dropped)} dropped ({len(new)} functions)")
    for (unit, fn), b, a in dropped:
        print(f"  DROPPED  {fn} ({unit}) {b:.2f}% -> {a:.2f}%")
    for (unit, fn), b, a in raised:
        print(f"  improved {fn} ({unit}) {b:.2f}% -> {a:.2f}%")
    for unit, fn in vanished:
        print(f"  gone     {fn} ({unit}): in the base report but not this one (splits changed?)")
    for unit, fn in appeared:
        print(f"  new      {fn} ({unit})")

    # Strict matches, only in units whose objects changed
    old_units, new_units = load_units(base_dir), load_units(root_dir)
    lost, gained, checked = [], [], 0
    for name in sorted(set(before) & set(after)):
        o, n = old_units.get(name), new_units.get(name)
        if not o or not n or "base_path" not in n:
            continue
        same = all(file_hash(os.path.join(base_dir, o[key])) == file_hash(os.path.join(root_dir, n[key]))
                   for key in ("target_path", "base_path") if key in o and key in n)
        if same:
            continue
        checked += 1
        was = strict_statuses(base_dir, o, before[name]) if "base_path" in o else {}
        now = strict_statuses(root_dir, n, after[name])
        for fn, status in now.items():
            if was.get(fn) == "match" and status != "match":
                lost.append((name, fn, status))
            elif status == "match" and was.get(fn) != "match":
                gained.append((name, fn, was.get(fn, "missing")))
    print(f"strict matches: {len(gained)} gained, {len(lost)} lost ({checked} changed units checked)")
    for unit, fn, status in lost:
        print(f"  LOST     {fn} ({unit}): now {status}")
    for unit, fn, was in gained:
        print(f"  gained   {fn} ({unit}): was {was}")

    if dropped or lost:
        print("regress: FAILED")
        return EXIT_REGRESSION
    print("regress: OK")
    return EXIT_OK


if __name__ == "__main__":
    try:
        sys.exit(main())
    except match.UsageError as e:
        print(f"error: {e}", file=sys.stderr)
        sys.exit(EXIT_USAGE)
    except subprocess.CalledProcessError as e:
        print(f"error: {' '.join(map(str, e.cmd))} failed:\n{(e.stderr or '')[-2000:]}", file=sys.stderr)
        sys.exit(EXIT_USAGE)
