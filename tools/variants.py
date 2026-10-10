#!/usr/bin/env python3

###
# Tries many source variants of one function in parallel and ranks them.
#
# Usage:
#   python3 tools/variants.py <function> <template.c> [--jobs N] [--first]
#
# The template is a copy of the unit's source (usually under build/scratch/)
# with variant markers in it. Each combination of choices is compiled with
# `match.py <unit> --source` (a temporary directory per run, so runs go in
# parallel) and scored for <function>; every other function of the unit is
# checked too, so a variant that drops another function shows it.
#
# Markers:
#   @{a@|b@|c@}       one of a, b or c (may span lines; empty choices allowed)
#   @perm{ ... @}     every order of the items inside: one item per non-blank
#                     line, or items separated by @, when the block has any
# Markers do not nest. Each marker is a site; the variant count is the product
# of the sites' choice counts, and --limit (default 20000) caps it unless
# --sample N picks N combinations at random.
#
# Examples: declaration orders as one @perm{ block of declarations; s32/int
# swaps as @{s32@|int@} at each declaration; loop-counter choice as
# @{i@|j@} at each use; statement orders as @perm{ with @, between statements.
#
# Copy the template from the current source: drops are measured against the
# unit's source as it is now. Redirect the output to a file rather than piping
# it to head or sed, which kill the run. Scores are objdiff's, which ignore
# branch targets: check a control-flow change with match.py --source.
# Markers do not nest: to vary both the order of a block and a form inside
# it, run the @perm{ batch with one form, then again with the other.
#
# --header FILE passes a header copy to every run, as match.py --source does.
# The best variants are written to build/variants/<function>/<run>/<rank>.c,
# a new <run> directory each time. Lines left blank only by markers are dropped.
#
# Exit codes: 0 = some variant matches, 1 = none does, 3 = usage error.
###

import argparse
import concurrent.futures
import itertools
import json
import math
import os
import random
import re
import subprocess
import sys
import tempfile
import threading
from typing import Any, Dict, List, Optional, Sequence, Tuple

root_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
MATCH = os.path.join(root_dir, "tools", "match.py")

MARKER = re.compile(r"@perm\{|@\{|@\||@,|@\}")


class UsageError(Exception):
    pass


# A template is a list of parts: plain strings, and sites, each a list of
# choices (strings). A permutation site's choices are its item orders.
def parse_template(text: str) -> Tuple[List[Any], List[str]]:
    parts: List[Any] = []
    kinds: List[str] = []
    pos = 0
    for m in MARKER.finditer(text):
        if m.start() < pos:
            continue
        token = m.group(0)
        if token in ("@|", "@,", "@}"):
            line = text.count("\n", 0, m.start()) + 1
            raise UsageError(f"line {line}: '{token}' outside a marker")
        end = text.find("@}", m.end())
        if end < 0:
            line = text.count("\n", 0, m.start()) + 1
            raise UsageError(f"line {line}: '{token}' has no closing '@}}'")
        body = text[m.end():end]
        if "@{" in body or "@perm{" in body:
            line = text.count("\n", 0, m.start()) + 1
            raise UsageError(f"line {line}: markers do not nest")
        parts.append(text[pos:m.start()])
        if token == "@{":
            parts.append(body.split("@|"))
            kinds.append("alt")
        else:
            parts.append(permutations(body))
            kinds.append("perm")
        pos = end + 2
    parts.append(text[pos:])
    return parts, kinds


class Orders:
    """Every order of a block's items, built on demand: a 15-item block has
    over 10^12 orders, so they cannot be listed, only sampled."""

    def __init__(self, items: List[str], join: str, head: str = "", tail: str = ""):
        self.items, self.join, self.head, self.tail = items, join, head, tail

    def __len__(self) -> int:
        return math.factorial(len(self.items))

    def __getitem__(self, n: int) -> str:
        pool = list(self.items)
        order = []
        for k in range(len(pool), 0, -1):
            n, i = divmod(n, k)
            order.append(pool.pop(i))
        return self.head + self.join.join(order) + self.tail


def permutations(body: str) -> Orders:
    if "@," in body:
        return Orders(body.split("@,"), "")
    lines = body.split("\n")
    # Keep the block's leading and trailing whitespace lines in place.
    head = []
    while lines and not lines[0].strip():
        head.append(lines.pop(0))
    tail = []
    while lines and not lines[-1].strip():
        tail.insert(0, lines.pop())
    items = [line for line in lines if line.strip()]
    return Orders(items, "\n", "".join(h + "\n" for h in head), "".join("\n" + t for t in tail))


def sites(parts: List[Any]) -> List[Any]:
    return [p for p in parts if not isinstance(p, str)]


SITE = "\x00"


def render(parts: List[Any], choice: Sequence[int]) -> str:
    out = []
    it = iter(choice)
    for p in parts:
        out.append(p if isinstance(p, str) else SITE + p[next(it)] + SITE)
    # A line left blank only by a marker (an empty choice, or a marker on a
    # line of its own) is dropped, so a winning variant can be copied as is.
    lines = [line for line in "".join(out).split("\n") if not (SITE in line and not line.replace(SITE, "").strip())]
    return "\n".join(lines).replace(SITE, "")


def describe(choice: Sequence[int], kinds: List[str]) -> str:
    return " ".join(f"{'P' if k == 'perm' else 'A'}{n + 1}={c}" for n, (c, k) in enumerate(zip(choice, kinds)))


def run_match(target: str, source: str, headers: List[str]) -> Optional[Dict[str, Any]]:
    cmd = [sys.executable, MATCH, target, "--json", "--source", source]
    for h in headers:
        cmd += ["--source", h]
    proc = subprocess.run(cmd, capture_output=True, text=True, cwd=root_dir)
    try:
        return json.loads(proc.stdout)
    except json.JSONDecodeError:
        return None


def find_unit(function: str) -> str:
    proc = subprocess.run(
        [sys.executable, MATCH, function, "--json", "--no-build"], capture_output=True, text=True, cwd=root_dir
    )
    try:
        result = json.loads(proc.stdout)
    except json.JSONDecodeError:
        raise UsageError(f"match.py could not find {function}: {proc.stderr.strip() or proc.stdout.strip()}")
    if result.get("function") != function:
        raise UsageError(f"{function} is not a function match.py knows")
    return result["unit"]


def scores(result: Dict[str, Any]) -> Dict[str, float]:
    return {f["name"]: f.get("percent") or 0.0 for f in result.get("functions", [])}


def main() -> int:
    parser = argparse.ArgumentParser(description="Try source variants of one function in parallel and rank them.")
    parser.add_argument("function", help="function to score")
    parser.add_argument("template", help="copy of the unit's source with @{a@|b@} and @perm{ ... @} markers")
    parser.add_argument("--jobs", type=int, default=min(12, os.cpu_count() or 4), help="parallel runs (default 12)")
    parser.add_argument("--limit", type=int, default=20000, help="refuse more variants than this (default 20000)")
    parser.add_argument("--sample", type=int, help="try this many combinations at random instead of all")
    parser.add_argument("--first", action="store_true", help="stop at the first variant that matches")
    parser.add_argument("--top", type=int, default=10, help="variants to list and write out (default 10)")
    parser.add_argument("--header", action="append", default=[], help="header copy passed to every run")
    parser.add_argument("--dry-run", action="store_true", help="count the variants and write the first; compile nothing")
    args = parser.parse_args()
    sys.stdout.reconfigure(line_buffering=True)

    try:
        with open(args.template) as f:
            parts, kinds = parse_template(f.read())
        counts = [len(s) for s in sites(parts)]
        total = 1
        for c in counts:
            total *= c
        if not counts:
            raise UsageError("the template has no markers")
        # Each run writes to its own directory, so an earlier run's winners
        # are never overwritten.
        fn_dir = os.path.join(root_dir, "build", "variants", args.function)
        os.makedirs(fn_dir, exist_ok=True)
        run = 1 + max([int(d) for d in os.listdir(fn_dir) if d.isdigit()], default=0)
        out_dir = os.path.join(fn_dir, str(run))
        os.makedirs(out_dir)
        print(f"{len(counts)} sites ({' x '.join(map(str, counts))}) = {total} variants")
        if args.dry_run:
            path = os.path.join(out_dir, "first.c")
            with open(path, "w") as f:
                f.write(render(parts, [0] * len(counts)))
            print(f"first variant: {os.path.relpath(path, root_dir)}")
            return 0
        if args.sample:
            seen = set()
            while len(seen) < min(args.sample, total):
                seen.add(tuple(random.randrange(c) for c in counts))
            choices = sorted(seen)
        elif total > args.limit:
            raise UsageError(f"{total} variants is over --limit {args.limit}; use --sample N or fewer markers")
        else:
            choices = list(itertools.product(*[range(c) for c in counts]))
        unit = find_unit(args.function)
        base = run_match(unit, os.path.join(root_dir, json_source(unit)), args.header)
    except UsageError as e:
        print(f"variants: {e}", file=sys.stderr)
        return 3
    if base is None or not base.get("build", {}).get("ok"):
        print("variants: the unit's own source does not build", file=sys.stderr)
        return 3
    base_scores = scores(base)
    print(f"{unit}: {args.function} is at {base_scores.get(args.function, 0.0):.2f}% in the source;"
          f" {len(choices)} runs, {args.jobs} at a time")

    results: List[Tuple[float, int, Tuple[int, ...], List[str], bool]] = []
    failed = 0
    done = 0
    stop = threading.Event()
    lock = threading.Lock()
    tmp = tempfile.mkdtemp(prefix="variants-", dir=os.path.join(root_dir, "build"))

    def work(n_choice: Tuple[int, Tuple[int, ...]]):
        n, choice = n_choice
        if stop.is_set():
            return None
        path = os.path.join(tmp, f"v{n}_{os.path.basename(args.template)}")
        with open(path, "w") as f:
            f.write(render(parts, choice))
        result = run_match(unit, path, args.header)
        os.unlink(path)
        return choice, result

    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        for item in pool.map(work, enumerate(choices)):
            if item is None:
                continue
            choice, result = item
            with lock:
                done += 1
                if result is None or not result.get("build", {}).get("ok"):
                    failed += 1
                    continue
                s = scores(result)
                drops = [f"{name} {base_scores[name]:.2f}->{pct:.2f}" for name, pct in s.items()
                         if name != args.function and name in base_scores and pct < base_scores[name] - 1e-6]
                status = next((f.get("status") for f in result["functions"] if f["name"] == args.function), None)
                inverted = any(args.function in pair for pair in result.get("order_inversions", []))
                matched = status == "match" and not inverted
                results.append((s.get(args.function, 0.0), result.get("matched_code", 0), choice, drops, matched))
                if matched and args.first:
                    stop.set()
                if done % 200 == 0:
                    best = max(r[0] for r in results)
                    print(f"  {done}/{len(choices)} run, best {best:.4f}%", flush=True)
    os.rmdir(tmp)

    results.sort(key=lambda r: (r[4], r[0], -len(r[3]), r[1]), reverse=True)
    print(f"{done} run, {failed} failed to build")
    for rank, (pct, code, choice, drops, matched) in enumerate(results[: args.top], 1):
        path = os.path.join(out_dir, f"{rank}.c")
        with open(path, "w") as f:
            f.write(render(parts, choice))
        tag = "MATCH " if matched else ""
        print(f"{rank:3}. {tag}{pct:.4f}%  {describe(choice, kinds)}  {os.path.relpath(path, root_dir)}")
        if drops:
            print(f"      drops: {', '.join(drops[:4])}{' ...' if len(drops) > 4 else ''}")
    return 0 if results and results[0][4] else 1


def json_source(unit: str) -> str:
    with open(os.path.join(root_dir, "objdiff.json")) as f:
        for u in json.load(f)["units"]:
            if u["name"] == unit:
                return u["metadata"]["source_path"]
    raise UsageError(f"{unit} is not in objdiff.json")


if __name__ == "__main__":
    sys.exit(main())
