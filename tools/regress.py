#!/usr/bin/env python3

###
# Compares this checkout with a base commit and fails if anything got worse:
#   - the build must pass its hash check (config/<version>/build.sha1);
#   - no function's objdiff score may drop;
#   - no function may lose a strict match (tools/match.py's "match", which
#     also checks relocation targets).
# It also lists what improved; paste the summary into the pull request.
#
# The base defaults to the merge-base with the local branch this branch tracks
# (tools/worktree.py sets one, so a worker keeps the matches of the branch it
# started from, including any not yet on origin/main), else with origin/main.
# It is built once per commit in a git worktree under build/regress/, reusing
# this checkout's game files and tools. The comparison includes uncommitted
# changes.
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


def local_upstream() -> Optional[str]:
    # Only a local branch: a pushed branch tracks its own remote copy
    try:
        branch = git("symbolic-ref", "--short", "HEAD")
        if git("config", f"branch.{branch}.remote") == ".":
            merge = git("config", f"branch.{branch}.merge")
            return merge[len("refs/heads/"):] if merge.startswith("refs/heads/") else merge
    except subprocess.CalledProcessError:
        pass
    return None


def resolve_base(ref: Optional[str]) -> Tuple[str, str]:
    upstream = local_upstream()
    candidates = [ref] if ref else ([upstream] if upstream else []) + ["origin/main", "main"]
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
    parser.add_argument("--base", help="ref to compare against (default: merge-base with the tracked local branch, else origin/main)")
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

    # Functions are keyed by name (by unit and name for names several units
    # share), so a function that moved to another unit is compared with itself
    def shared_names(units: Dict[str, Any]) -> set:
        seen, shared = set(), set()
        for unit in units.values():
            for f in unit.get("functions", []):
                (shared if f["name"] in seen else seen).add(f["name"])
        return shared

    shared = shared_names(before) | shared_names(after)

    def key(unit: str, fn: str) -> str:
        return f"{unit}:{fn}" if fn in shared else fn

    # objdiff scores, per function
    def scores(units: Dict[str, Any]) -> Dict[str, Tuple[str, float]]:
        return {key(u, f["name"]): (u, f.get("fuzzy_match_percent", 0.0)) for u, unit in units.items()
                for f in unit.get("functions", [])}

    old, new = scores(before), scores(after)
    keys = sorted(set(old) | set(new))
    dropped = [(k, old[k][1], new[k][1]) for k in keys if k in old and k in new and new[k][1] < old[k][1]]
    raised = [(k, old[k][1], new[k][1]) for k in keys if k in old and k in new and new[k][1] > old[k][1]]
    vanished = [k for k in keys if k in old and k not in new]
    appeared = [k for k in keys if k not in old and k in new]
    print(f"objdiff scores: {len(raised)} improved, {len(dropped)} dropped ({len(new)} functions)")
    for k, b, a in dropped:
        print(f"  DROPPED  {k} ({new[k][0]}) {b:.2f}% -> {a:.2f}%")
    for k, b, a in raised:
        print(f"  improved {k} ({new[k][0]}) {b:.2f}% -> {a:.2f}%")
    for k in vanished:
        print(f"  gone     {k} ({old[k][0]}): in the base report but not this one (splits changed?)")
    for k in appeared:
        print(f"  new      {k} ({new[k][0]})")

    # Strict matches, only in units whose objects changed
    old_units, new_units = load_units(base_dir), load_units(root_dir)

    def changed(name: str) -> bool:
        o, n = old_units.get(name), new_units.get(name)
        if not o or not n:
            return True
        return not all(file_hash(os.path.join(base_dir, o[path])) == file_hash(os.path.join(root_dir, n[path]))
                       for path in ("target_path", "base_path") if path in o and path in n)

    was: Dict[str, Tuple[str, str]] = {}
    now: Dict[str, Tuple[str, str]] = {}
    checked = 0
    for name in sorted(set(before) | set(after)):
        if not changed(name):
            continue
        o, n = old_units.get(name), new_units.get(name)
        if name in before and o and "base_path" in o:
            for fn, status in strict_statuses(base_dir, o, before[name]).items():
                was[key(name, fn)] = (name, status)
        if name in after and n and "base_path" in n:
            checked += 1
            for fn, status in strict_statuses(root_dir, n, after[name]).items():
                now[key(name, fn)] = (name, status)
    # A function absent from the new report altogether was merged away by a
    # symbols change; the scores section lists it as gone
    lost = [(was[k][0], k, now.get(k, (None, "missing"))[1]) for k in sorted(was)
            if was[k][1] == "match" and k in new and now.get(k, (None, ""))[1] != "match"]
    gained = [(now[k][0], k, was.get(k, (None, "missing"))[1]) for k in sorted(now)
              if now[k][1] == "match" and was.get(k, (None, ""))[1] != "match"]
    print(f"strict matches: {len(gained)} gained, {len(lost)} lost ({checked} changed units checked)")
    for unit, fn, status in lost:
        print(f"  LOST     {fn} ({unit}): now {status}")
    for unit, fn, status in gained:
        print(f"  gained   {fn} ({unit}): was {status}")

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
