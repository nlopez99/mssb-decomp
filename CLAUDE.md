# mssb-decomp

- `CONTRIBUTING.md`: setup, matching rules and pull request evidence.
- `docs/matching-notes.md`: lessons indexed by the symptom `tools/match.py` shows; the large symptom catalogs it links are in `docs/matching-notes/`. Read it when starting a function and whenever a diff stalls.
- `python3 tools/match.py <function>`: the verdict on a function, including relocation targets; objdiff's report alone is not one. A function missing from the source gets its original assembly and an m2c draft.
- `python3 tools/regress.py`: run before committing a match; it fails on any regression and its summary is the PR evidence.
