# Matching notes

Lessons from matched functions, indexed by the **symptom** `tools/match.py` shows. Find the symptom, try its causes in order, and add a lesson here when a function teaches you something new (symptom, cause, fix, example).

## `reloc`: a reference points somewhere else

objdiff's report scores these 100% because it ignores relocation targets; the unit cannot link until they are fixed.

- **Placeholder shadows a named symbol.** The source declares its own `extern ... lbl_3_data_XXXX` for an address that `symbols.txt` already names. Look the address up in `config/GYQE01/**/symbols.txt`, use the existing header declaration, delete the placeholder. Example: `calculateHorizontalPower` read `hitTrajOptions` through `lbl_3_data_5B34`.
- **Source is ahead of `symbols.txt`.** The source uses a good name that `symbols.txt` still calls `lbl_...`. Rename it in `symbols.txt` after checking the source type's size equals the symbol's `size:`, then fix every other use of the old name (`tools/check_symbols.py` lists them). Example: `gameInitOptions` and `aILevel` for `setInMemBatterConstants`.
- **Wrong callee or global.** The call or load goes to a different symbol with the same shape. Treat it as a source bug, not a naming issue.

## Registers only: same instructions, different register numbers

- **Shared across functions.** When several functions show the same unexplained allocation while identically written ones match, look at what they share before tweaking each: a prototype's parameter or return type changes the compiler's internal conversions and so its allocation, with identical instructions. Example: `minigame_checkIfAIInputIs_Algorithmic_Or_ControllerBased(u8)` should take `s8` (callers pass `s8 characterIndex[]`); that fixed three functions.
- **Declaration order.** The order locals are declared in affects which callee-saved register each gets; try moving the variable that lands in the wrong register above its neighbour. Example: `inputs` declared before the `BOOL` flag.
- **A value loaded once.** Holding a repeated load in its own local (with the type of the expression, usually `int`, not the field's `u8`) changes allocation. Example: `slapContactSize` in `calculateBuntHorizontalAngle`.
- **Stalled after a few tries:** run `python3 tools/permute.py <function>` and the command it prints. Take the permuter's idea, not its literal code (it reuses unrelated variables and adds casts like `(long long)`), then rewrite it plausibly and recheck.

## Instruction differences that reveal types

- **Signedness of an int-to-float conversion.** Signed: `xoris rX,rX,0x8000` with the double constant `0x4330000080000000`. Unsigned: no `xoris`, constant `0x4330000000000000`. Fix the element or variable type to match.
- **Array shape from index arithmetic.** `subfic r0,e,3; slwi; lwzx` from a struct's start is one 4-element array indexed `[3 - e]`, not two 2-element fields. Example: `trajOptions_s._0` must stay `s32[4]`.
- **A `u8` copy of a value.** `clrlwi rX,rY,24` before comparisons can mean the code compares a `u8` variable assigned from a cast (e.g. `u8 starType = (s8)field`), not the field directly.

## Structure differences

- **A different stored value** (`li r3,0` versus a register holding data) is a logic error in the source, not allocation. Example: in `calculateHitVariables` the original stores 0 into `inAirOrBefore2ndBounceOrLowBallEnergy`, not the star type.
- **Code shared with a `*_unused` static function.** Upstream's `_unused` means the standalone copy has no callers in the binary. The caller may hold its own written-out copy, possibly with statements in a different order, or call the function and have it inlined (units build with `-inline auto` and `-inline deferred`). Try both and keep whichever matches while the standalone function still matches. Example: `calculateHitVariables` matches with written-out copies of `starHitSetting_unused` and `calculateBuntVerticalAngle_unused`; calling them allocates registers differently.
- **Inlined same-file functions.** A call in the source with no `bl` in the object was inlined; small non-static functions from the same file inline too (`calculateBuntHorizontalPower`).

## Before committing

- Run `tools/match.py` on every function that uses a type, prototype or symbol you changed, not only the one you were fixing.
- Run `python3 tools/regress.py`; it fails on any dropped objdiff score or lost strict match. Its summary goes in the pull request.

## Tool pitfalls

- Install m2c from https://github.com/matt-kempster/m2c. The PyPI package named `m2c` is an unrelated project.
- `match.py --m2c` prepares the unit's context for m2c (preprocesses it and strips inline asm); typed drafts work for every game and menus unit.
- decomp-permuter's own `import.py` breaks on this project; `tools/permute.py` explains why in its header and replaces it.
