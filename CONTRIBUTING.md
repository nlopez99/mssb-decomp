# Contributing to mssb-decomp

This is an independent continuation of roeming's Mario Superstar Baseball decompilation. The upstream repository is https://github.com/roeming/mssb-dtk. Existing work and its CC0 license stay intact. Credit upstream work and other contributors accurately.

AI-assisted contributions are welcome. Disclose substantial AI assistance in the pull request and review the output yourself. Acceptance depends on evidence and source quality, not the tool used to write it.

## Get a working baseline

The initial target is the USA Rev 0 release, `GYQE01`. Supply your own game files; this repository does not distribute them. Use Dolphin's extraction feature and place these files in the ignored local directory:

```text
orig/GYQE01/sys/main.dol
orig/GYQE01/files/aaaa.dat
```

Install Python and Ninja. Follow the upstream README for your operating system and compiler-wrapper requirements. Then, from the repository root:

```bash
python3 decompress.py
python3 configure.py --version GYQE01
ninja
ninja all_source progress build/GYQE01/report.json
```

Do not begin matching work until the untouched baseline builds and passes its configured hash checks. If it fails, record the exact command and error before changing code or tool versions.

Then enable the pre-push checks once per clone: `git config core.hooksPath tools/hooks`. Each push runs `tools/check_symbols.py` and `tools/regress.py`.

## Pick a contribution

Start with one unmatched function in objdiff, preferably a small game-code function with understood inputs and outputs. Avoid racing someone else's claimed work. Until GitHub issues are available, agree on a function and file in chat before starting.

1. Create a branch for the function or a small related group.
2. Inspect its target assembly and existing types. Use related matched functions as references.
3. Write or refine C, then run `python3 tools/match.py <unit> <function>` to rebuild the object and diff it against the target, or inspect it in objdiff. For remaining register-allocation differences, `python3 tools/permute.py <function>` sets up decomp-permuter.
4. Require an exact match including relocations before marking it matching. `tools/match.py` reports this as `match`. The 100% in objdiff's progress report is not enough on its own, because the report ignores relocation targets.
5. Run `python3 tools/regress.py`. It builds, checks the hashes, and compares every function with the base commit; it fails if any objdiff score drops or any strict match is lost.
6. Review names, comments, types and undefined-behavior risks. A matching function does not prove that every guessed name or explanation is correct.

Keep matching work separate from gameplay changes, ports and experiments. Those belong on explicitly non-matching branches. Do not alter compiler flags, target objects, matching thresholds or report denominators just to make a score increase.

## Pull requests

Include the function/object names, what changed, commands you actually ran, object-match evidence, the whole-build result, and any uncertainty. The summary from `tools/regress.py` covers the evidence and the whole-build result. Explain substantial AI assistance briefly. State clearly if validation is blocked. Unverified work can be discussed, but must not be described as a verified match.

Never commit game images, extracted binaries, assets, proprietary compiler binaries, credentials or generated build output. Use human-readable source and honest attribution; assembly wrappers are not new C decompilation progress.

## Continuous integration

The inherited workflow depended on `ghcr.io/roeming/mssb-dtk-build:main`, a private upstream build container. Its original definition is preserved under `.github/upstream/` for reference and is not an active workflow here.

Our initial automated checks validate Python syntax, configuration entry-point loading and whitespace. They do not compile the game and must not be treated as matching-build evidence. A private, separately isolated build environment and progress-report publishing still need to be configured after a local baseline is verified. Do not publish a new decomp.dev listing before our own workflow produces valid reports.
