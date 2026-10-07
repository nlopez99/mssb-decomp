# Matching notes

Lessons from matched functions, indexed by the **symptom** `tools/match.py` shows. Find the symptom, try its causes in order, and add a lesson here when a function teaches you something new (symptom, cause, fix, example).

## `reloc`: a reference points somewhere else

objdiff's report scores these 100% because it ignores relocation targets; the unit cannot link until they are fixed.

- **Placeholder shadows a named symbol.** The source declares its own `extern ... lbl_3_data_XXXX` for an address that `symbols.txt` already names. Look the address up in `config/GYQE01/**/symbols.txt`, use the existing header declaration, delete the placeholder. Example: `calculateHorizontalPower` read `hitTrajOptions` through `lbl_3_data_5B34`.
- **Source is ahead of `symbols.txt`.** The source uses a good name that `symbols.txt` still calls `lbl_...`. Rename it in `symbols.txt` after checking the source type's size equals the symbol's `size:`, then fix every other use of the old name (`tools/check_symbols.py` lists them). Example: `gameInitOptions` and `aILevel` for `setInMemBatterConstants`.
- **Wrong callee or global.** The call or load goes to a different symbol with the same shape. Treat it as a source bug, not a naming issue.
- **`...bss.0` or `...data.0` with offsets in the base.** MWCC addresses a file's statics from one base symbol plus literal offsets (`addi r4,r5,160`, `lwz r3,8(r31)`), so the target's offsets give the layout, and `symbols.txt` often lumps several statics into one symbol. Declare one static per object, in reverse address order (MWCC lays them out in reverse declaration order), including statics nothing in the file reads, and split the symbol in `symbols.txt` to match. One static struct does not reproduce this: it recomputes its base in each branch, while the pool base is computed once. Example: kinoko's `lbl_3_bss_BA00` to `BAA0`.

## Registers only: same instructions, different register numbers

- **Shared across functions.** When several functions show the same unexplained allocation while identically written ones match, look at what they share before tweaking each: a prototype's parameter or return type changes the compiler's internal conversions and so its allocation, with identical instructions. Example: `minigame_checkIfAIInputIs_Algorithmic_Or_ControllerBased(u8)` should take `s8` (callers pass `s8 characterIndex[]`); that fixed three functions.
- **Declaration order.** The order locals are declared in affects which callee-saved register each gets; try moving the variable that lands in the wrong register above its neighbour. Example: `inputs` declared before the `BOOL` flag.
- **A value loaded once.** Holding a repeated load in its own local (with the type of the expression, usually `int`, not the field's `u8`) changes allocation. Example: `slapContactSize` in `calculateBuntHorizontalAngle`.
- **Operands swapped in an add** (`add r31,r31,r0` versus `add r31,r0,r3`): split the expression, e.g. `value = tex[i]; value += step * 2;`. Example: `fn_3_16943C`.
- **Operands swapped in a branchless `or`/`or.` chain** (`cntlzw; srwi; or; or.` tests): reorder the operands of `|` in the condition; each order gives a different pairing. Example: `fn_3_16E1EC` matches only as `lbl_3_bss_D6EC | !lbl_8036E548._3088 | !lbl_3_bss_D6E4`.
- **Stalled after a few tries:** run `python3 tools/permute.py <unit> <function>` and the command it prints. Take the permuter's idea, not its literal code (it reuses unrelated variables and adds casts like `(long long)`), then rewrite it plausibly and recheck.

## Instruction differences that reveal types

- **Signedness of an int-to-float conversion.** Signed: `xoris rX,rX,0x8000` with the double constant `0x4330000080000000`. Unsigned: no `xoris`, constant `0x4330000000000000`. Fix the element or variable type to match.
- **Array shape from index arithmetic.** `subfic r0,e,3; slwi; lwzx` from a struct's start is one 4-element array indexed `[3 - e]`, not two 2-element fields. Example: `trajOptions_s._0` must stay `s32[4]`.
- **`extsb` before a call only in the target:** the callee takes `int`, and the caller sign-extends its `s8` argument; with an `s8` parameter the callee extends instead. Example: `fn_8001B728(s32, s32, Vec*)`.
- **A flag parameter tested with `clrlwi. r0,r4,24`** is a `u8`; a `BOOL` (`int`) compiles to `cmpwi`.
- **`extsb` before `cmpwi rX,-1` but none before `cmpwi rX,1` on the same field:** the field is `s8`; MWCC drops the sign extension when testing equality with a non-negative constant. Example: `AIStruct.aiPitchDirectionInput` in `fn_3_20CEC`.
- **`cmplw` between two computed element addresses:** the source compares two arrays, which decay to pointers. Keep the original's bug. Example: `g_Scores._04[batting] > g_Scores._04[fielding]` in `fn_3_212A0`.
- **A `u8` copy of a value.** `clrlwi rX,rY,24` before comparisons can mean the code compares a `u8` variable assigned from a cast (e.g. `u8 starType = (s8)field`), not the field directly.
- **`neg` before `cntlzw` only in the base:** a pointer tested with `p == NULL` inside a `|` chain. Write `!p`, which compiles to plain `cntlzw; srwi`. Example: `fn_3_16E1EC`.
- **A word loaded from `.rodata`, stored to the stack, reloaded after a call and written to the FIFO** (`lwz r0,lbl@l; stw r0,8(r1)` ... `lwz r0,8(r1); stw r0,-0x8000(r3)`): a local `GXColor color = { 0xFF, 0xFF, 0xFF, 0xFF };` sent with `GXColor1u32(*(u32*)&color)`. Example: `fn_3_16D810`.

## Structure differences

- **A different stored value** (`li r3,0` versus a register holding data) is a logic error in the source, not allocation. Example: in `calculateHitVariables` the original stores 0 into `inAirOrBefore2ndBounceOrLowBallEnergy`, not the star type.
- **Code shared with a `*_unused` static function.** Upstream's `_unused` means the standalone copy has no callers in the binary. The caller may hold its own written-out copy, possibly with statements in a different order, or call the function and have it inlined (units build with `-inline auto` and `-inline deferred`). Try both and keep whichever matches while the standalone function still matches. Example: `calculateHitVariables` matches with written-out copies of `starHitSetting_unused` and `calculateBuntVerticalAngle_unused`; calling them allocates registers differently.
- **Inlined same-file functions.** A call in the source with no `bl` in the object was inlined; small non-static functions from the same file inline too (`calculateBuntHorizontalPower`).
- **A `bl` only in the target, to an empty stub in the same file:** the stub gets inlined away, and `#pragma dont_inline` does not stop it. The caller matches once the stub has a real body; to check the rest now, delete the stub's definition temporarily and keep its prototype. Example: `fn_3_16C394` calls `fn_3_16B884`.
- **The base inlines a same-file function that the target calls with `bl`:** `-inline auto` inlines a callee whose statement count is under a threshold, so the original callee had more statements than yours, though they compiled to the same code. Measured on `fn_3_6A83C`: each expression statement, call, `if` and `return` counts about one; declarations with initializers count like assignments; empty statements and folded constants count nothing. Rewrite the callee in a plausible longer form (early `return`s instead of one nested `if`, a local for a value read twice) until the caller's size matches, and recheck the callee. To learn how far off you are, add `x = 0;` lines to a scratch copy until the inlining stops. Example: `fn_3_6A83C` stays a call in `fn_3_6AB58` only with its early returns and its `state` and `order` locals.
- **A comparison argument computed in a different place** (`cror; mfcr; rlwinm` or `srawi; subfc; adde` before the float loads in one listing, after them in the other): MWCC evaluates arguments left to right, and since ints and floats go in separate registers, register use does not show where a mixed prototype puts its `int` parameter. Move the flag in the prototype until the evaluation order matches. Example: `fn_3_C1344(s32, f32, f32, BOOL)` and `fn_3_BD504(f32, f32, f32, BOOL)` in `rep_F80.c`.
- **Stores in a different order with the same values,** such as `[2]` before `[0]`: chained assignments store right to left, so `a[0] = a[2] = 255;`. Example: `fn_3_169600`.
- **A float argument of an inlined call computed late** (the base adds the constant after the callee's first `bl` into a scratch FPR; the target adds it into the saved FPR before): update the variable before the call, `x += 1.8f; draw(d, x, y);`, instead of passing `x + 1.8f`. Example: `fn_3_16DB6C` inlining `fn_3_16D810`.
- **A table load before a call in the target, after it in the base** (`lbzx r31,...; bl RandomInt_Game; cmpw r3,r31`): MWCC evaluates a call in an expression before the other operands, whichever side it is on, so the original read the value in its own statement first: `chance = table[i][j]; if (RandomInt_Game(100) < chance)`. Example: `fn_3_212A0`.
- **A retry counter that only increments when the loop repeats** (`cmpwi r30,2; bge exit; addi r30,r30,1; b top`, where `while (... && tries++ < 2)` gives `cmpwi; addi; blt top`): `for (;;) { ...; if (done || tries >= 2) break; tries++; }`. Example: `fn_3_20FB0`.
- **Float loads in another order, and a different constant addressed through `addi rX,rY,sym@l; lfs f,0(rX)`:** how the arithmetic is split into statements decides the scheduling. Try splitting a compound expression and moving neighbouring stores. Example: `fn_3_20EEC` matched only as `index` stored first, then `width = max - min; width /= 5.0f; x = min + width * index;`.
- **Assertion panics:** `OSErrorLine(line, "message")` produces `OSPanic(__FILE__, line, ...)`, and `__FILE__` is the bare file name (`"kinoko.c"`).

## `...rodata.0` in the base, constants one by one in the target

The base shows `lis rX,...rodata.0@ha; addi` and then `lfs f0,100(rX)`, while the target names each constant (`lfs f0,lbl_3_rodata_418C@l(r4)`). MWCC pools a function's `.rodata` references once it touches enough of them (three float constants alone stayed separate in `fn_3_16D810`; adding a `GXColor` initializer pooled all four).

- **Cause: the original's `.rodata` began with weak objects, which turns pooling off for that section** (observed: with weak objects first nothing in `.rodata` is pooled, while `.bss` statics still are). `game/UnknownHomes_Game.h` defines `SQRT2_LINKAGE extern` before including `math.h`, so `dolsqrtf2` becomes an `extern inline` whose static locals are emitted as weak `_half$localstatic` and `_three$localstatic` even when unused; plain `#include "math.h"` emits nothing. The target's `.rodata` does not show them, presumably because the linker kept one weak copy for the whole module.
- **Fix, only when the base shows `...rodata.0`:** include `game/UnknownHomes_Game.h` above `header_rep_data.h`, as `game_batter.c` does. The `.rodata` section score loses those 0x10 bytes; the code matches. Example: `rep_4138.c`, where this matched `fn_3_16D810` and `fn_3_16DB6C`. `-pool off` also matches such functions but breaks pooled `.bss`, and GC/1.3.2 to 2.7 behave identically, so the include order is the explanation, not the flags.
- The same include matched `fn_3_16B5B4` in `kinoko.c`, which pooled once an inlined callee added string literals.
- **When nothing needs unpooled constants, include `header_rep_data.h` first.** That puts `repHeaderData` at offset 0 as in the target and scores `.rodata` higher (92% against 86% in `rep_F80.c`); every function matched with either order.

## `.rodata` below 100% with every function matched

- **Literal constants in the reverse of the target's order:** the source lists functions in address order. With `-inline deferred` MWCC generates functions last to first (objdiff's `reverse_fn_order` hides this for `.text`) and creates each function's constants as it goes, so REL source lists functions from the highest address down; `tools/reverse_functions.py` converts a file. Example: rep_940 `.rodata` 83% to 93%.
- **The weak `dolsqrtf2` constants** (0x10 bytes, from `game/UnknownHomes_Game.h`) stay as a difference; the linker keeps one copy for the whole module.

## Before committing

- Run `tools/match.py` on every function that uses a type, prototype or symbol you changed, not only the one you were fixing.
- Run `python3 tools/regress.py`; it fails on any dropped objdiff score or lost strict match. Its summary goes in the pull request.

## Tool pitfalls

- Install m2c from https://github.com/matt-kempster/m2c. The PyPI package named `m2c` is an unrelated project.
- `match.py --m2c` prepares the unit's context for m2c (preprocesses it and strips inline asm); the draft is typed only for globals the source's includes declare, so a placeholder file including only `header_rep_data.h` gives `?` types until you add `game/UnknownHomes_Game.h` and the like.
- decomp-permuter's own `import.py` breaks on this project; `tools/permute.py` explains why in its header and replaces it.
