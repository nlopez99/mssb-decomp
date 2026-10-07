---
name: match-functions
description: Match functions in one unit of this decomp, writing or fixing C until tools/match.py reports `match`. Use when asked to match or decompile a function, a unit or a source file.
---

# Match functions

Your **claim** is one unit that already has a source file. Turn as many of its functions as you can into C that compiles to the original instructions with the same relocations. `python3 tools/match.py` gives the **verdict**, and only its `match` counts. The measure is matched bytes per hour, so take cheap functions first and let expensive ones go at the time box.

## Steps

1. **Survey.** Run `date +%s` and keep the number. Run `python3 tools/match.py <unit> --all`; if the checkout has no `objdiff.json`, it is not built, so stop and report that. Read `docs/matching-notes.md`. Put the source file in the order **Source conventions** requires, and define the data in the unit's own ranges first, since functions that read it through a pool base score low until it exists. Order the functions that do not match: `reloc`, then `partial` above 95%, then `missing` and `stub` functions from smallest to largest, then the remaining `partial` ones. Move each inlined function ahead of the function that inlines it: a function with no callers in the assembly whose body appears inside another one is inlined there, and its caller cannot match until it does. A callee that is still an empty stub counts the same way, since the stub gets inlined into its caller. Done when you have that list. (`match.py` exits 1 while anything differs, so don't chain it with `&&`.)

2. **Match each function in list order.**
   1. Run `python3 tools/match.py <unit> <function> --m2c` for the target assembly and an m2c draft. The draft is typed only for globals the source's includes declare, so add the includes it needs (usually `game/UnknownHomes_Game.h`) first. Its types are still guesses. Take parameter types from the callers' register setup, from how the function's entry uses each register, and from SDK prototypes in `include/Dolphin/`. `grep -rn "<function>" build/GYQE01 --include='*.s'` finds both calls and pointers to it in data.
   2. Write the function in its position (see **Source conventions**) and run `python3 tools/match.py <unit> <function>`. Each run rebuilds one object in under a second. `--full` shows diffs longer than the 200-line cap, and `-C 0` shows only the differing lines.
   3. Find the diff's symptom in `docs/matching-notes.md`, change one thing, and run it again.

   Done when the verdict is `match`, or when the **time box** runs out: 20 runs without a new best score for that function; each new best restarts the count. A run is one compile and compare: each variant in a scripted batch counts, a permuter session counts once, and runs that change a callee count toward the function whose score you are chasing. When only register numbers still differ, spend part of the box on `python3 tools/permute.py <unit> <function>`: start the command it prints in the background, read the best score after a few minutes, and stop it with `pkill -f "nonmatchings/<function>"` (macOS has no `timeout`). Compiling a scratch copy with other flags, compiler versions or pragmas is allowed as evidence for an escalation, and counts toward the box.

3. **Keep or restore.** At a time box, keep the **best candidate** only if its score beats what the file had, and put a comment of at most three lines above it saying what still differs. Otherwise restore the previous code. When a function teaches something the notes lack, add it to `docs/matching-notes.md` under its symptom (symptom, cause, fix, example).

4. **Verify and commit.** Run `python3 tools/match.py <unit> --all`, `python3 tools/check_symbols.py` and `python3 tools/regress.py`. Both checks must pass before you commit, and the last must end in `regress: OK`; its gained list also covers earlier branches, so report only your unit's lines. Commit with a message that names the matched functions.

5. **Report.** Your final message gives:
   - the unit, elapsed seconds since step 1, and code bytes matched before and after (the `code X/Y bytes` line of `match.py <unit>`);
   - each function you worked on, with its size and its status and score before and after;
   - each best candidate's remaining difference;
   - lessons added to the notes;
   - every **escalation**.

## Claim

Change only the unit's source file, its header under `include/`, the lines of `config/GYQE01/<module>/symbols.txt` that fall inside the unit's ranges in that module's `splits.txt`, and `docs/matching-notes.md`. You may change a shared declaration, such as a prototype, a field type or a new field in a shared header, when the evidence requires it. If you do, run `match.py` on every unit that uses it and list the change in the report. Likewise, a `symbols.txt` entry outside your ranges that the evidence shows is wrong (separate objects lumped into one symbol, a wrong size) may be fixed in its own commit, once `regress.py` passes with it. List that change in the report too.

Report these as an escalation with the evidence, and leave them unchanged: `splits.txt`, compiler flags or versions in `configure.py`, other units' source files, and any difference you trace to something outside the claim. Two cases keep you moving while you escalate:
- Data that only your unit uses but that lies outside its ranges in `splits.txt` gets an `extern` declaration, plus an escalation proposing the split range and any wrong `symbols.txt` entries in it. If the target reads that data from one pool base (offsets past a single symbol's size), no `extern` can match. Tune the function against a temporary copy that declares the data as statics, since the `extern` version differs throughout. Then commit the `extern` version and put the static copy's result in the escalation. Functions just outside the unit's `.text` range that use its data may belong to it too: escalate them with the evidence. When such a function is inlined into one of yours, write it in your file as `static inline` under its `.text` line, so your object gains no extra function, and keep its prototype out of the header until the split moves; then it becomes a plain function with a prototype.
- A function or global that another unit's header declares wrongly (typically a `void(void)` placeholder matching that unit's stub, or a struct where the data is an array) gets a correct `extern` declaration in your source file when fixing the header would break that unit's source. Do not include that header. Escalate with the declaration and its evidence.

A pragma or a section score is also an escalation: if a pragma gives a large gain, report the gain, and keep the pragma out of the source. Section scores (`.rodata`, `.data`, `.bss`) do not need to reach 100% for functions to `match`. Report them, and leave a unit's `Matching`/`NonMatching` flag in `configure.py` alone.

## Source conventions

- Each function sits under its `// .text:0x... size:0x... mapped:0x...` line. For a function new to the file, compute `mapped` from a neighbour: the offset between `.text` and `mapped` is constant within a file.
- Units built with `-inline deferred` (every `game`, `menus` and `challenge` unit, and main-DOL units whose `configure.py` entry adds it) list functions in **reverse address order**, highest first: MWCC generates them last to first. `python3 tools/reverse_functions.py <source file>` converts a file still in address order; if it refuses, reorder by hand. Other units list functions in address order.
- Data in the unit's own ranges is defined in the source with the original's values, which the unit's assembly file lists; split any `symbols.txt` entry there that lumps several objects. Initialized `.data` objects are laid out in declaration order, so declare them in address order. Keep each object's binding from `symbols.txt` (`scope:local` is `static`), except that data the target reaches from one pool base must be `static`; mark those entries `scope:local`. All-zero data needs an explicit `= { 0 }` to stay in `.data`. `jumptable_*` objects come from `switch` statements, not hand-written data. A trailing `gap_*` symbol, or a size that includes alignment padding before the next unit, is padding: leave it.
- Prototypes go in the unit's header in address order. Functions and data from other units that no header declares get `extern` declarations at the top of the source file. A global without a header gets a local `extern struct { ... } name;` with only the fields the unit uses, at their offsets. A type only this unit uses is defined in its source file; a prototype in the header that needs it uses a forward `struct` declaration.
- Use the `symbols.txt` name for every symbol. Rename one only with evidence, such as an SDK function or a string that names it, and then rename it in `symbols.txt` and in every user (`tools/check_symbols.py` finds them). Unknown struct fields are `_XX` with `/* 0xXX */` offset comments.
- Prefer SDK enum names (`GX_TF_RGBA8`) over bare numbers where they compile to the same code, and match the surrounding style. Comments explain what the code cannot: a compiler constraint or a remaining mismatch.

## Integrity

- Call a function matched only when the verdict is `match`, in comments, commits and the report alike.
- Write C a programmer plausibly wrote. Inline asm, casts or pragmas whose only purpose is to steer the compiler, and permuter output pasted verbatim do not count as progress.
- Never change what is measured (compiler flags, splits or objdiff settings) to raise a score.

## Lookups

- Units and their paths: `objdiff.json` (`name`, `metadata.source_path`).
- Symbols and sizes: `config/GYQE01/symbols.txt` for the main DOL; `config/GYQE01/{game,menus,challenge}/symbols.txt` for the RELs.
- Assembly of whole units: `build/GYQE01/<module>/asm/`; main-DOL code with no source: `build/GYQE01/asm/auto_*.s`.
- The objects being compared: `target_path` and `base_path` in `objdiff.json`. `build/binutils/powerpc-eabi-objdump -t <object>` lists their symbols, which shows section layout, pool symbols (`...rodata.0`) and weak objects. `ninja -t commands <base_path>` prints the exact compile command for scratch experiments.
- SDK declarations: `include/Dolphin/` (GX enums in `GX/GXEnum.h`, `OSPanic` and `OSErrorLine` in `os.h`); `memset` comes from `"string.h"`.
