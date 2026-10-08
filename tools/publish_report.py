#!/usr/bin/env python3

###
# Publishes the progress report that decomp.dev reads. GitHub's runners have
# no game files, so this builds build/<version>/report.json here and attaches
# it to the "reports" release, named after the source tree it was built from.
# On each push to main, .github/workflows/report.yml downloads the report for
# its commit's tree and uploads it as the <version>_report artifact.
#
# Run it on a pull request's last commit before merging (merging a branch that
# already contains main keeps its tree), or on main when a Report run failed
# for lack of a report; it re-runs failed Report runs with the same tree.
#
# Usage:
#   python3 tools/publish_report.py [--dry-run]
#
# Exit codes: 0 = published (or the dry run passed), 1 = build, hash check or
#             report failed, 3 = usage error.
###

import argparse
import json
import os
import shutil
import subprocess
import sys
import tempfile

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))
sys.path.insert(0, script_dir)
import match  # noqa: E402

VERSION = "GYQE01"
RELEASE = "reports"
WORKFLOW = "report.yml"
EXIT_OK, EXIT_FAILED, EXIT_USAGE = 0, 1, 3


def run(*args: str, check: bool = True) -> subprocess.CompletedProcess:
    return subprocess.run(args, cwd=root_dir, capture_output=True, text=True, check=check)


def build_report() -> str:
    proc = run("ninja", check=False)
    if proc.returncode != 0:
        raise RuntimeError("build failed\n" + match.build_errors(proc.stdout + proc.stderr))
    sha1 = os.path.join("config", VERSION, "build.sha1")
    proc = run(os.path.join("build", "tools", "dtk"), "shasum", "-c", sha1, check=False)
    if proc.returncode != 0:
        raise RuntimeError(f"hash check failed\n{proc.stdout}{proc.stderr}")
    report_path = os.path.join("build", VERSION, "report.json")
    proc = run("ninja", "all_source", "progress", report_path, check=False)
    if proc.returncode != 0:
        raise RuntimeError("report failed\n" + match.build_errors(proc.stdout + proc.stderr))

    # The report must cover every unit of the target, not only built ones
    with open(os.path.join(root_dir, "objdiff.json")) as f:
        units = len(json.load(f)["units"])
    with open(os.path.join(root_dir, report_path)) as f:
        report = json.load(f)
    measures = report["measures"]
    if len(report["units"]) != units or not int(measures.get("total_code", 0)):
        raise RuntimeError(f"report covers {len(report['units'])} of {units} units")
    print(f"report: {measures['matched_code_percent']:.2f}% code matched, "
          f"{measures['matched_functions']}/{measures['total_functions']} functions, {units} units")
    return os.path.join(root_dir, report_path)


def ensure_release() -> None:
    if run("gh", "release", "view", RELEASE, check=False).returncode == 0:
        return
    notes = ("Progress reports for decomp.dev, one per source tree, published by tools/publish_report.py. "
             "Not a release of the game.")
    run("gh", "release", "create", RELEASE, "--title", "Progress reports", "--notes", notes,
        "--prerelease", "--target", "main")


def rerun_failed(tree: str) -> None:
    run("git", "fetch", "-q", "origin", "main", check=False)
    proc = run("gh", "run", "list", "--workflow", WORKFLOW, "--branch", "main", "--event", "push",
               "--status", "failure", "--limit", "20", "--json", "databaseId,headSha", check=False)
    if proc.returncode != 0:
        return  # The workflow is not on main yet
    for entry in json.loads(proc.stdout):
        commit = run("git", "rev-parse", f"{entry['headSha']}^{{tree}}", check=False)
        if commit.returncode == 0 and commit.stdout.strip() == tree:
            run("gh", "run", "rerun", str(entry["databaseId"]))
            print(f"publish: re-ran Report run {entry['databaseId']} for {entry['headSha'][:12]}")


def main() -> int:
    parser = argparse.ArgumentParser(description="Build the progress report and attach it to the reports release.")
    parser.add_argument("--dry-run", action="store_true", help="build and check the report without uploading it")
    args = parser.parse_args()

    if run("git", "status", "--porcelain", "--untracked-files=no").stdout.strip():
        print("publish: commit or stash changes first; the report must match HEAD's tree", file=sys.stderr)
        return EXIT_USAGE
    if not os.path.exists(os.path.join(root_dir, "build.ninja")):
        print(f"publish: configure and build this checkout first (python3 configure.py --version {VERSION})",
              file=sys.stderr)
        return EXIT_USAGE

    try:
        report_path = build_report()
    except RuntimeError as e:
        print(f"publish: {e}", file=sys.stderr)
        return EXIT_FAILED

    tree = run("git", "rev-parse", "HEAD^{tree}").stdout.strip()
    asset = f"{VERSION}_{tree}.json"
    if args.dry_run:
        print(f"publish: dry run, would upload {asset} to the {RELEASE} release")
        return EXIT_OK

    ensure_release()
    with tempfile.TemporaryDirectory(prefix="publish-report-") as tmp:
        path = os.path.join(tmp, asset)
        shutil.copyfile(report_path, path)
        run("gh", "release", "upload", RELEASE, path, "--clobber")
    print(f"publish: uploaded {asset} to the {RELEASE} release")
    rerun_failed(tree)
    return EXIT_OK


if __name__ == "__main__":
    sys.exit(main())
