#!/usr/bin/env python3

###
# Creates a git worktree on a new branch and builds it, ready for
# tools/match.py. Parallel workers each need one: ninja cannot run
# concurrently in one build directory.
#
# The worktree links this checkout's game files and reuses its downloaded
# tools and compilers, so it downloads nothing. The first build takes about
# 15 seconds.
#
# Usage:
#   python3 tools/worktree.py <branch> [--base REF] [--dir PATH]
#
# The directory defaults to ../mssb-decomp-<branch>, with "/" replaced by "-".
###

import argparse
import os
import subprocess
import sys

script_dir = os.path.dirname(os.path.realpath(__file__))
sys.path.insert(0, script_dir)
import match  # noqa: E402
import regress  # noqa: E402


def main() -> int:
    parser = argparse.ArgumentParser(description="Create and build a worktree for a worker.")
    parser.add_argument("branch", help="new branch to create")
    parser.add_argument("--base", default="HEAD", help="commit to branch from (default HEAD)")
    parser.add_argument("--dir", help="worktree directory (default ../mssb-decomp-<branch>)")
    args = parser.parse_args()

    path = os.path.abspath(args.dir or os.path.join(regress.root_dir, "..",
                                                     "mssb-decomp-" + args.branch.replace("/", "-")))
    if os.path.exists(path):
        raise match.UsageError(f"{path} already exists")
    flags = regress.tool_flags()

    regress.git("worktree", "add", "-b", args.branch, path, args.base)
    regress.link_game_files(path)
    subprocess.run([sys.executable, "configure.py", "--version", regress.VERSION, *flags],
                   cwd=path, check=True, capture_output=True)
    proc = subprocess.run(["ninja"], cwd=path, capture_output=True, text=True)
    if proc.returncode != 0:
        print("build: FAILED\n" + match.build_errors(proc.stdout + proc.stderr))
        return 2
    # match.py and permute.py look for the tools under build/; ninja has no
    # rules for these paths here, so the links are safe
    for name in ("tools", "binutils", "compilers"):
        os.symlink(os.path.realpath(os.path.join(regress.root_dir, "build", name)),
                   os.path.join(path, "build", name))
    print(path)
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except match.UsageError as e:
        print(f"error: {e}", file=sys.stderr)
        sys.exit(3)
    except subprocess.CalledProcessError as e:
        print(f"error: {' '.join(map(str, e.cmd))} failed:\n{(e.stderr or '')[-2000:]}", file=sys.stderr)
        sys.exit(3)
