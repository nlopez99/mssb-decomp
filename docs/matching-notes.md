# Matching notes

Lessons from matched functions, indexed by the **symptom** `tools/match.py` shows. Find the symptom, try its causes in order, and add a lesson here when a function teaches you something new (symptom, cause, fix, example).

## `reloc`: a reference points somewhere else

objdiff's report scores these 100% because it ignores relocation targets; the unit cannot link until they are fixed.

- **Placeholder shadows a named symbol.** The source declares its own `extern ... lbl_3_data_XXXX` for an address that `symbols.txt` already names. Look the address up in `config/GYQE01/**/symbols.txt`, use the existing header declaration, delete the placeholder. Example: `calculateHorizontalPower` read `hitTrajOptions` through `lbl_3_data_5B34`.
- **Source is ahead of `symbols.txt`.** The source uses a good name that `symbols.txt` still calls `lbl_...`. Rename it in `symbols.txt` after checking the source type's size equals the symbol's `size:`, then fix every other use of the old name (`tools/check_symbols.py` lists them). Example: `gameInitOptions` and `aILevel` for `setInMemBatterConstants`.
- **Wrong callee or global.** The call or load goes to a different symbol with the same shape. Treat it as a source bug, not a naming issue.
- **`...bss.0` or `...data.0` with offsets in the base.** MWCC addresses a file's statics from one base symbol plus literal offsets (`addi r4,r5,160`, `lwz r3,8(r31)`), so the target's offsets give the layout, and `symbols.txt` often lumps several statics into one symbol. Declare one static per object, in reverse address order (MWCC lays them out in reverse declaration order), and split the symbol in `symbols.txt` to match. One static struct does not reproduce this: it recomputes its base in each branch, while the pool base is computed once. Example: kinoko's `lbl_3_bss_BA00` to `BAA0`.

## Registers only: same instructions, different register numbers

- **Shared across functions.** When several functions show the same unexplained allocation while identically written ones match, look at what they share before tweaking each: a prototype's parameter or return type changes the compiler's internal conversions and so its allocation, with identical instructions. Example: `minigame_checkIfAIInputIs_Algorithmic_Or_ControllerBased(u8)` should take `s8` (callers pass `s8 characterIndex[]`); that fixed three functions.
- **Declaration order.** The order locals are declared in affects which callee-saved register each gets; try moving the variable that lands in the wrong register above its neighbour. Example: `inputs` declared before the `BOOL` flag.
- **A value loaded once.** Holding a repeated load in its own local (with the type of the expression, usually `int`, not the field's `u8`) changes allocation. Example: `slapContactSize` in `calculateBuntHorizontalAngle`.
- **Operands swapped in an add** (`add r31,r31,r0` versus `add r31,r0,r3`): split the expression, e.g. `value = tex[i]; value += step * 2;`. Example: `fn_3_16943C`.
- **Stalled after a few tries:** run `python3 tools/permute.py <function>` and the command it prints. Take the permuter's idea, not its literal code (it reuses unrelated variables and adds casts like `(long long)`), then rewrite it plausibly and recheck.

## Instruction differences that reveal types

- **Signedness of an int-to-float conversion.** Signed: `xoris rX,rX,0x8000` with the double constant `0x4330000080000000`. Unsigned: no `xoris`, constant `0x4330000000000000`. Fix the element or variable type to match.
- **Array shape from index arithmetic.** `subfic r0,e,3; slwi; lwzx` from a struct's start is one 4-element array indexed `[3 - e]`, not two 2-element fields. Example: `trajOptions_s._0` must stay `s32[4]`.
- **`extsb` before a call only in the target:** the callee takes `int`, and the caller sign-extends its `s8` argument; with an `s8` parameter the callee extends instead. Example: `fn_8001B728(s32, s32, Vec*)`.
- **A flag parameter tested with `clrlwi. r0,r4,24`** is a `u8`; a `BOOL` (`int`) compiles to `cmpwi`.
- **A `u8` copy of a value.** `clrlwi rX,rY,24` before comparisons can mean the code compares a `u8` variable assigned from a cast (e.g. `u8 starType = (s8)field`), not the field directly.

## Structure differences

- **A different stored value** (`li r3,0` versus a register holding data) is a logic error in the source, not allocation. Example: in `calculateHitVariables` the original stores 0 into `inAirOrBefore2ndBounceOrLowBallEnergy`, not the star type.
- **Code shared with a `*_unused` static function.** Upstream's `_unused` means the standalone copy has no callers in the binary. The caller may hold its own written-out copy, possibly with statements in a different order, or call the function and have it inlined (units build with `-inline auto` and `-inline deferred`). Try both and keep whichever matches while the standalone function still matches. Example: `calculateHitVariables` matches with written-out copies of `starHitSetting_unused` and `calculateBuntVerticalAngle_unused`; calling them allocates registers differently.
- **Inlined same-file functions.** A call in the source with no `bl` in the object was inlined; small non-static functions from the same file inline too (`calculateBuntHorizontalPower`).
- **A `bl` only in the target, to an empty stub in the same file:** the stub gets inlined away, and `#pragma dont_inline` does not stop it. The caller matches once the stub has a real body; to check the rest now, delete the stub's definition temporarily and keep its prototype. Example: `fn_3_16C394` calls `fn_3_16B884`.
- **Stores in a different order with the same values,** such as `[2]` before `[0]`: chained assignments store right to left, so `a[0] = a[2] = 255;`. Example: `fn_3_169600`.
- **Assertion panics:** `OSErrorLine(line, "message")` produces `OSPanic(__FILE__, line, ...)`, and `__FILE__` is the bare file name (`"kinoko.c"`).

## Unsolved

- **Constants addressed through `...rodata.0` in the base but one by one in the target.** Seen in `fn_3_16B5B4` once an inlined callee adds string literals. Compiling with `-pool off` matches it but breaks the pooled `.bss` statics, and GC/2.0 to 2.7 compile it identically. Leave such functions as best candidates rather than changing flags.

## Before committing

- Run `tools/match.py` on every function that uses a type, prototype or symbol you changed, not only the one you were fixing.
- Run `python3 tools/regress.py`; it fails on any dropped objdiff score or lost strict match. Its summary goes in the pull request.

## Tool pitfalls

- Install m2c from https://github.com/matt-kempster/m2c. The PyPI package named `m2c` is an unrelated project.
- `match.py --m2c` prepares the unit's context for m2c (preprocesses it and strips inline asm); typed drafts work for every game and menus unit.
- decomp-permuter's own `import.py` breaks on this project; `tools/permute.py` explains why in its header and replaces it.
