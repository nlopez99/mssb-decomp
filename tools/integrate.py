#!/usr/bin/env python3

###
# Brings a worker's branch into the integration branch it started from:
#   1. rebases the branch onto the integration branch if that has moved, and
#      stops on a conflict;
#   2. checks the worker's worktree: nothing uncommitted, check_symbols.py,
#      check_prototypes.py, check_notes.py (two workers can add the same
#      lesson, and the notes' union merge keeps both) and regress.py against
#      the integration branch; it
#      also lists the commits, the changed files, each changed unit's
#      summary and any added line a reviewer should look at (inline asm,
#      pragmas, m2c leftovers);
#   3. fast-forwards the integration branch, which must be checked out in its
#      own worktree, and runs regress.py there against the old tip;
#   4. removes the worker's worktree and branch only if that passes.
#
# Usage:
#   python3 tools/integrate.py <worker branch> [--into BRANCH] [--check-only]
#
# --into defaults to the branch the worker's branch tracks (tools/worktree.py
# sets it to --base). --check-only runs step 2 alone, against the fork point.
#
# Exit codes: 0 = merged (or checked), 1 = a check or regress failed,
#             2 = rebase conflict, 3 = usage error.
###

import argparse
import json
import os
import re
import subprocess
import sys
from typing import Dict, List, Optional, Tuple

script_dir = os.path.dirname(os.path.realpath(__file__))
sys.path.insert(0, script_dir)
import match  # noqa: E402
import regress  # noqa: E402
import worktree  # noqa: E402

EXIT_OK, EXIT_FAILED, EXIT_CONFLICT, EXIT_USAGE = 0, 1, 2, 3
# Added lines a reviewer should see: compiler steering and m2c leftovers, in
# code rather than in a // comment ("the volatile registers differ")
REVIEW = re.compile(r"^\+(?:(?!//).)*(\basm\b|#pragma|\(long long\)|\bM2C_|__declspec|\bvolatile\b)")
SUMMARY = re.compile(r"^(regress|build|objdiff|strict)|DROPPED|LOST|\bgone\b")


def worktrees() -> Dict[str, str]:
    """Branch name -> worktree path, for every worktree of this repository."""
    found, path = {}, None
    for line in regress.git("worktree", "list", "--porcelain").splitlines():
        if line.startswith("worktree "):
            path = line[len("worktree "):]
        elif line.startswith("branch refs/heads/") and path:
            found[line[len("branch refs/heads/"):]] = path
    return found


def run_tool(checkout: str, script: str, *args: str) -> Tuple[int, str]:
    path = os.path.join(checkout, "tools", script)
    if not os.path.exists(path):
        return 0, f"{script}: not in this checkout, skipped"
    proc = subprocess.run([sys.executable, path, *args], cwd=checkout, capture_output=True, text=True)
    return proc.returncode, (proc.stdout + proc.stderr).strip()


def regress_summary(output: str, failed: bool) -> str:
    # On failure show everything but the improvements, which can run to
    # hundreds of lines
    lines = output.splitlines()
    if failed:
        return "\n".join(l for l in lines if not re.match(r"^  (improved|gained|new) ", l))
    return "\n".join(l for l in lines if SUMMARY.search(l))


def changed_units(checkout: str, files: List[str]) -> List[str]:
    try:
        with open(os.path.join(checkout, "objdiff.json")) as f:
            units = json.load(f)["units"]
    except (OSError, ValueError, KeyError):
        return []
    sources = {u.get("metadata", {}).get("source_path"): u["name"] for u in units}
    return [sources[f] for f in files if f in sources]


def check(branch: str, checkout: str, into: str) -> bool:
    ok = True
    fork = regress.git("merge-base", "HEAD", into, cwd=checkout)
    print(f"== {branch} ({checkout}), fork point {fork[:12]} on {into}")
    commits = regress.git("log", "--oneline", f"{fork}..HEAD", cwd=checkout)
    print(commits or "no commits")
    if regress.git("status", "--porcelain", "--untracked-files=no", cwd=checkout):
        print("FAILED: uncommitted changes (the worker must commit or restore them)")
        ok = False
    files = regress.git("diff", "--name-only", f"{fork}..HEAD", cwd=checkout).split()
    print(f"files changed: {' '.join(files) or 'none'}")

    for script, args in (("check_symbols.py", ()), ("check_prototypes.py", ()), ("check_notes.py", ())):
        code, output = run_tool(checkout, script, *args)
        last = output.splitlines()[-1] if output else ""
        print(last if code == 0 else f"FAILED: {script}\n{output}")
        ok = ok and code == 0
    code, output = run_tool(checkout, "regress.py", "--base", into)
    print(regress_summary(output, code != 0))
    ok = ok and code == 0

    for unit in changed_units(checkout, files):
        _, output = run_tool(checkout, "match.py", unit, "--no-build")
        lines = output.splitlines()
        print(f"{unit}: {lines[1] if len(lines) > 1 else output}")
    review = [l for l in regress.git("diff", f"{fork}..HEAD", "--", "src", "include", cwd=checkout).splitlines()
              if REVIEW.search(l)]
    if review:
        print("review these added lines (steering or m2c leftovers do not count as matches):")
        print("\n".join("  " + l[:160] for l in review[:20]))
    return ok


def rebase(checkout: str, into: str) -> bool:
    proc = subprocess.run(["git", "rebase", into], cwd=checkout, capture_output=True, text=True)
    if proc.returncode == 0:
        print(f"rebased onto {into}")
        return True
    conflicts = regress.git("diff", "--name-only", "--diff-filter=U", cwd=checkout)
    subprocess.run(["git", "rebase", "--abort"], cwd=checkout, capture_output=True)
    print(f"REBASE CONFLICT onto {into}, rebase aborted; conflicting files:\n{conflicts or proc.stderr.strip()}")
    print("Resolve it in the worker's worktree (with many commits, `git merge " + into + "` once instead), "
          "then run this again.")
    return False


def main() -> int:
    parser = argparse.ArgumentParser(description="Check a worker's branch and merge it into its integration branch.")
    parser.add_argument("branch", help="the worker's branch")
    parser.add_argument("--into", help="integration branch (default: the branch it tracks)")
    parser.add_argument("--check-only", action="store_true", help="only check the worker's branch")
    args = parser.parse_args()

    trees = worktrees()
    checkout = trees.get(args.branch)
    if not checkout:
        raise match.UsageError(f"no worktree has {args.branch} checked out")
    into: Optional[str] = args.into
    if not into:
        try:
            into = regress.git("rev-parse", "--abbrev-ref", f"{args.branch}@{{upstream}}")
        except subprocess.CalledProcessError:
            raise match.UsageError(f"{args.branch} tracks no branch; pass --into")
    into_dir = trees.get(into)
    if not into_dir and not args.check_only:
        raise match.UsageError(f"check out {into} in its own worktree first (tools/worktree.py)")

    if args.check_only:
        return EXIT_OK if check(args.branch, checkout, into) else EXIT_FAILED

    if subprocess.run(["git", "merge-base", "--is-ancestor", into, "HEAD"], cwd=checkout).returncode != 0:
        if regress.git("status", "--porcelain", "--untracked-files=no", cwd=checkout):
            print(f"FAILED: {checkout} has uncommitted changes")
            return EXIT_FAILED
        if not rebase(checkout, into):
            return EXIT_CONFLICT
    if not check(args.branch, checkout, into):
        print("NOT MERGED")
        return EXIT_FAILED

    if regress.git("status", "--porcelain", "--untracked-files=no", cwd=into_dir):
        print(f"FAILED: {into_dir} has uncommitted changes")
        return EXIT_FAILED
    old = regress.git("rev-parse", "HEAD", cwd=into_dir)
    proc = subprocess.run(["git", "merge", "--ff-only", args.branch], cwd=into_dir, capture_output=True, text=True)
    if proc.returncode != 0:
        print(f"FAILED: fast-forward of {into} to {args.branch}:\n{proc.stderr.strip()}")
        return EXIT_FAILED
    print(f"== merged {args.branch} into {into} at {regress.git('rev-parse', '--short=12', 'HEAD', cwd=into_dir)}")
    code, output = run_tool(into_dir, "regress.py", "--base", old)
    print(regress_summary(output, code != 0))
    if code != 0:
        print(f"NOT REMOVING {checkout}: regress failed on {into}. Fix forward there, "
              f"or undo the merge with `git -C {into_dir} reset --hard {old[:12]}`.")
        return EXIT_FAILED

    worktree.remove(checkout)
    regress.git("branch", "-d", args.branch, cwd=into_dir)
    print(f"deleted branch {args.branch}")
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
