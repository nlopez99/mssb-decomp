# Backlog

The work queue and open questions for matching batches. Each batch's pull request updates it (`.claude/skills/run-batch/SKILL.md`). This file keeps what the tools cannot show:
- a unit's functions, their state and which stubs each waits on: `python3 tools/match.py <unit>`;
- prototype cleanup: `python3 tools/check_prototypes.py`;
- unassigned code: the `auto_*_text` units in `objdiff.json`.

## Follow-ups

The unit's data and helpers are already in place, so these give the cheapest bytes. Functions an earlier session time-boxed carry a comment saying what still differs.

- **rep_AC8** (214 KB, 144 of 225 functions match, 122 KB left): 61 stubs. Unblocked and not yet attempted, smallest first: `fn_3_3C594` (0x5F8, a tangled cutoff-takeover routine), `2BB04` (0x734, calls `fn_3_9EFD0` with stack vectors), `4A9AC`, `3DB78`, `4207C` (a cascade of `fn_3_5985C` calls and one block repeated three times, probably an inline helper), `45E98`, `57BB4`, `54B58` (blocks `55370`, `2CBE0`, `2EEC4`, `3B9E4` and `583B8`), `46E08`, `334EC`, `402A8`, `4D20C`, `28224`, `447C4`, `26A74`, `4FB34`, `4BA0C`, `34A40`, `433E0` and `28CA8`. `fn_3_36678` (0xA9C) is at 98.86%: the target passes `radToShortAngle`'s results to `fn_3_9FCF8` unextended, which needs `s16` parameters that break matched callers (see rep_1838 prototypes). Switching `fn_3_52560`, `fn_3_4EFC8` and `fn_3_4A408` to `s32` was tried in all 8 combinations, with rep_13B8's `fn_3_8604C` adapted; none is a net gain. About 30 partials carry comments; scripted declaration-order and `int`/`s32` batches solved most register-only ones, the permuter few.
- **rep_16B8** (50 of 56): all attempted. `fn_3_91FC4` (0xD14) 99.22% and `fn_3_96CA4` 86.85% reach seven tables (0xBE50–0xF430) through one base, `lbl_3_data_8D88`; a scratch copy laying out 0x8D88–0xD638 before the file's data reaches 99.25–99.43% (Open questions). `fn_3_94BC4` 98.79%, `9497C` 93.71%, `9894C` 88.34% (pooling), `94760` 91.77%.
- **rep_1FD8** (41 of 49): all attempted. `fn_3_C597C` 99.70%, `C5DDC` 99.77%, `C63D0` 99.77% and `C7A0C` 99.22% differ in the float registers of inlined helpers; `C77AC` 96.61%, `C1C18` 95.95%, `C8650` 94.59%, `C2AA0` 93.77% (the same diff as sta_c2's `fn_3_CD968`).
- **rep_1200** (35 of 42): `fn_3_6F4E8` (0x1E4) joined the unit this batch and is not attempted (empty stubs for it were inlined, so it is left undefined). Partials: `fn_3_738A8` 99.91%, `70768` 99.81%, `6FFC4` 99.49%, `709B4` 99.23%, `71248` 97.97%, `72768` 89.28%.
- **rep_E08** (21 of 28): give it `.text` up to 0x6750C when claimed: `fn_3_674E0` resets the same common `.bss` objects as `fn_3_67130` (116 references in rep_E08, none in rep_EA0). `lbl_3_common_bss_32230` is sized 0x1 but holds an `s16` and a byte at +2. Not attempted: `fn_3_63AF8` (0x10E4), `64BDC` (0xC08), `657E4` (0x7FC), `6714C` (0x394, waits on the two largest), `66140` and `664FC`. `fn_3_668BC` 99.62%.
- **rep_37A8** (20 of 37): not attempted `fn_3_144CB8` (0x704, holds `fn_3_144ADC`'s logic inlined), then `146408` and `1471C4`, which wait on it. 14 partials from 74.65% (`14402C`) to 99.88% (`145B98`); `fn_3_146A90` 85.24% has the same diff as rep_3520's `fn_3_13BCB8`.
- **rep_12D0** (31 of 37): `fn_3_76D08` 98.64% (its jump table and the others' keep `.data` at 0% until it matches), `76174` 97.95%, `7B308` 95.03%, `759BC` 87.88%; `78574` 99.01% and `78AC4` 99.72% not retried.
- **rep_DB8** (30 of 34): `fn_3_5DD30` 99.31%, `5F154` 99.18%, `5C74C` 98.07%, `5B5A0` 95.33%; see the Open question on its `.data`.
- **m_sound** (54 of 56): `fn_3_8B094` 93.01% and `fn_3_8F21C` 99.37%.
- **rep_D18** (11 of 16): not attempted `fn_3_5A28C` (0x3F8), `fn_3_5A87C` (0x424) and `fn_3_5AE0C` (waits on `5A87C`). `fn_3_59F40` (92.11%) reaches the unit's tables from one pool base, `lbl_3_data_3D60`, and addresses 0x4160 with one `addi` of 0x400, so `lbl_3_data_3D80` (0x430) lumps a 62-entry table (0x3E0), an object at 0x4160 and what follows; split them first. `fn_3_5AE9C` 97.07% (registers only).
- **rep_1B20** (13 of 15): `fn_3_B1DD0` (0x77C) 90.14%, which re-reads `cpuInputDuration[i]` after decrementing it and keeps the 0x1200 case's stick masks in r29–r31, and `fn_3_B3448` 98.64% (registers only).
- **sta_c5:** `fn_3_F6FDC` (0x1468) at 96.70%: making `_C3` a `u8` helps it but costs `fn_3_EFB54`, which reads `_C3` as `s8`, so the prop draws may use another layout over those bytes. `fn_3_F082C` 99.97% and `fn_3_F0FA4` 99.17% are register-only; eight time-boxed partials were not retried.
- **sta_c2:** `fn_3_D67CC` (0x2244) at 94.60% from a first draft: its frame is 16 bytes smaller than the target's, and one counter (`cmplw r3,r18; beq; addi r18,r18,1` in the spring loop) is unexplained. `fn_3_CCC24` 98.37% (the target keeps the placement pointer in r28 from entry) and `fn_3_CC81C` 99.19%.
- **rep_1E08:** define `.data` 0x111A8–0x170F0 (only rep_1E08 reads it) and split the lumped `lbl_3_data_111A8`, `111C8`, `1146C` and `15718`. `fn_3_BF070` reaches 100% with that data as statics. `fn_3_C0134` needs `.bss` 0x9952/0x9978 split.
- **rep_3520:** nine partials not yet attempted (`fn_3_136220`, `1373E0`, `1384B4`, `138AA4`, `1391C0`, `139808`, `139CA0`, `13A0AC`, `13ACB4`). Moving `MG.objs`/`MG.pieces` accesses onto real members lifts `fn_3_13BCB8` to about 94.4% but lowers `138AA4`, `1379A0` and `1373E0`, so do it per function. `fn_3_13334C` (0x1170) at 97.79%: the target keeps `g_Minigame`'s address in r14.
- **rep_720:** `fn_3_1850C` 99.94% and `fn_3_1CE90` 99.91% differ only in f28–f30 in their inlined copies of the camera helpers; writing the block out in the caller fixed `fn_3_17DA0` but fixes only the first copy in these two. `fn_3_19FA4` 97.38%.
- **rep_3090:** `fn_3_FDB30` (0x24E8) at 99.59%, registers in the captain searches (opcodes 0x48, 0x49, 0x55, 0x58, 0x59), 0x2F's modulo and 0x66's distance sum. `fn_3_FCF24` 93.12%: its int-to-float constant uses the `addi` form only in the target.
- **rep_13B8:** `fn_3_80028` (0x109C) 97.54%; `fn_3_8A618` 96.50% standalone conflicts with its matched copy in `fn_3_8A958`; `fn_3_85CB0` 60.54%: the target does not fold `fn_3_85C44`'s `direction` tests after inlining it; `fn_3_81BC8` 95.27% not attempted.
- **One function left:** rep_9B0's `fn_3_219CC` (87.36%, the target keeps `&g_GameLogic` and the captain offset apart for an `lwzx`), rep_3A98's `fn_3_15B494` (95.47%), rep_868's `fn_3_1DEB8` (99.64%) and rep_18E8's `fn_3_A8478` (99.64%, register-only).
- **rep_31A0** (59 of 63): `fn_3_10CC20` (0x19EC) at 99.92%, one `bne; b` around a `continue` (`docs/matching-notes/structure.md`).
- **rep_540:** five partials at 94.5–99.94%. For `fn_3_A970`, squaring `velocity.x` into a local first fixes the velocity part (99.85%), but the local found so far is a misused `angle`.
- **rep_3880:** `fn_3_1540E4` inlines `fn_3_153F8C`, which the target calls instead; unsolved.
- **rep_3310:** the model-load pattern (`addi r0,table,0x34` then `lwzx`) keeps `fn_3_119E30`, `119EE0`, `11881C`, `1194AC` and `11897C` at 65–93%.

## Untouched units

- **game:** none left; every named unit has been claimed.
- **challenge** (0%, 163 KB in 13 named units, only 8 KB unassigned, so ready to claim): rep_0610 (46 KB), rep_7730 (37 KB), rep_74A0 (20 KB), rep_0138 and rep_00B0 (13 KB each), then rep_02A8, rep_7BF0, rep_0250, rep_0010, rep_7A28 and rep_7978 (2–7 KB).
- **menus** (0%): 42 named units hold 250 KB, the largest rep_0788 (90 KB), rep_0B08 (38 KB), rep_0AB0 (20 KB), rep_08E8 (17 KB), rep_0F60 (14 KB), rep_1028 (12 KB) and rep_0568 (10 KB). Another 367 KB sits in 20 unassigned ranges (the largest at 0x71EC4, 80 KB, and 0x1254, 70 KB), so the module needs a splits pass by the `repHeaderData` rule before most of its code can be claimed.
- The game units matched fastest this batch were menu and minigame UI code (rep_1A80, rep_1AD0, rep_1C68, rep_3A48, rep_3BD8: 40–60 KB/h per worker), which suggests the menus module will go quickly once split.

## Unassigned game code

Each game object has exactly one `repHeaderData` copy, so every gap is a neighbour's head or tail (`docs/matching-notes.md`, "Unit boundaries"). Each line below gives the likely owner. Decide when that unit is claimed, from pool bases and jump tables.

- 0x113398: rep_31F0's tail.
- 0x1293D0–0x12E8FC (21 KB): only its position is known, between rep_3448 and rep_34B0. rep_3A48's `fn_3_15A448` queues `fn_3_12BFE8` and `fn_3_12C3F0` from it.
- 0xE911C and 0xEA340 (15 KB): rep_2BF8's head and tail, or sta_c5's head; they read the tables at 0x19770–0x1B820, which end just before sta_c5's `.data`. rep_16B8 calls `fn_3_ED574` in the second gap.
- 0xE0668 and 0xE1964: around rep_2940; they are copies of one function.
- 0xB7EF0: holds `fn_3_B7F18` (a cross product rep_540 calls) and `fn_3_B7F70` (sta_c2 and rep_2998 call it); both are declared locally by their callers.
- Tails of linked units: 0xCB6B4 (rep_2390, with `.data` 0x18268–0x182C0 and `.bss` 0x9FDC–0xA018), 0x114FC0 (rep_3290), 0x1608F0 (rep_3D50) and 0x1665E4 (rep_3E00). Head of a linked unit: 0x1E154 (rep_8C8).
- 0x674E0: rep_E08's tail (Follow-ups).
- Position only: 0x1D86C, 0x6A160, 0x6AEC0, 0x6B4C8, 0x6C854, 0x6D4A0, 0x7CE90, 0x9C578, 0x9CD90, 0xC0810, 0xCB344, 0x13C790 and 0x1658F0.

## Open questions

- **rep_DB8's `.data` (0x4290–0x65F0) is probably two objects.** rep_DB8's own functions read nothing below 0x5FF4 (0x5FF4, 0x6074, 0x607C, 0x60F0, 0x6104, 0x6130 and its jump tables at 0x6510–0x65EC), all by symbol, with no pool base. 0x4290–0x5FF4 is read only by other units (rep_AC8, rep_13B8, rep_540, rep_18E8, rep_1188, rep_1200, rep_12D0, rep_E08, game_batter). rep_D68, between rep_D18 (whose `.data` ends at 0x4290) and rep_DB8, has no code and only its `repHeaderData` in `.rodata`, so it is a data-only object: give it `.data` 0x4290–X and rep_DB8 X–0x65F0, with X 8-aligned and at most 0x5FF4 (0x5FC0 or 0x5FF0; rep_1200 reads 0x5FC0 as one `s16[2]`).
- **Units with no code found:** rep_A78, and rep_D68 (above).
- **rep_3310's `.bss` 0xB6B8–0xB6BC:** probably an unreferenced static of rep_3310. Starting its `.bss` at 0xB6BC would break the 8-byte alignment rule.
- **rep_3520's `.bss`:** 0xE bytes follow `lbl_3_bss_B781` (`gap_05_0000B782_bss`), more than alignment padding; probably an unreferenced static of unknown size.
- **Stadium types:** rep_2998 now uses `rep_1D58.h`'s types. Two pairs still describe the same objects: `Rep2998Common` and rep_1D58's struct for `lbl_3_common_bss_350E4`, and `Rep2998ModelTable` and `StadiumActor1D58`.
- **rep_1838 prototypes:** `fn_3_9FB8C` returns `s32` in practice (29 of 68 call sites sign-extend its result; `rep_1838.h` says `s16`), and `fn_3_9FCF8` takes `(s32, s32)` (it sign-extends both on entry). rep_AC8 declares both locally; fixing the header needs `rep_1838.c` to compile the same. Against that: two rep_AC8 callers (`fn_3_2B694`, `fn_3_4E638`) cast the result to `s16`, `fn_3_36678` passes `fn_3_9FCF8` unextended `s16` angles, and `fn_3_361D8` re-extends each angle at every call, so the original types may be `s16` with something else explaining the other call sites.
- **Main DOL:** no shared header for its functions, so units declare them locally with their own types. `check_prototypes.py` lists those whose calling conventions differ, such as `fn_800B0A5C_insertQueue`.
- **C3 headers:** offset comments after the embedded `Control` assume the SDK's 0x3C; this game's is 0x44. `geoPalette.h` puts `DODisplayObj.worldMatrix` at 0x1C, but this game's is at 0x18 (`fn_3_EE100`, `fn_3_EE67C`); sta_c5 declares `DOSetWorldMatrix` locally. The game's actors have fields at 0x98 and 0x99, past `actor.h`'s 0x70-byte `Actor`, so rep_2308, rep_3F60 and sta_c4 call `ACTSetAnimation` with their own actor types.
- **Tables one unit uses that are not contiguous with its data:** rep_34B0's 0x216BC, and rep_36D8's 0x217F8–0x21984. rep_3A98 and rep_1BC8 read `lbl_3_data_FAA8`, and rep_3A98 `FC1C`, inside rep_1B20's `.data`.
- **rep_16B8's `.data`:** `fn_3_96CA4` and `fn_3_91FC4` reach seven tables (0xBE50–0xF430) through one base, `lbl_3_data_8D88`, so the object's `.data` seems to start at 0x8D88 (right after m_sound's), across rep_1610's 0xD5B8–0xD638. The tables rep_3A48 reads (0x9D50–0xBD90) lie inside that object too. Against it, `fn_3_9894C` names `lbl_3_data_D648`, `D7E8` and `D860` one by one, which an `extern` of `D648` alone reproduces (96.91%) and a definition in the same file does not (88.34%, pooled).
- **`fn_800363D8`'s last parameter** is declared `u16` in rep_1770, `u32` in rep_16B8 (`fn_3_94760` passes an untruncated 32-bit sum) and `s32` in rep_3448.
- **`checkCollision` returns an unsigned type:** rep_1FD8's `fn_3_C63D0` tests its result with `cmplwi`; `rep_D0.h` declares the signed `BALL_COLLISION_TYPE`, which rep_13B8, rep_EA0 and rep_1CB8 use.
- **`lbl_3_data_1C54`** and `1C56` are one `s16[2]` (`lhau` then `lha 2` from one base, in rep_AC8); no unit's range covers them.
- **`lbl_3_common_bss_32888`** is 0x1B0 bytes in `symbols.txt`, but rep_12D0 uses only an `s8[2][100]` (0xC8); it may lump several objects.
- **Unreferenced `.bss` that may be several objects:** rep_3D50's 0xB9BC (0x24 bytes) and rep_1D58's 0x9944 (0xC bytes).

## Decisions for the maintainer

- `fn_3_8781C` (rep_13B8) reads `g_Ball.ballZoneWhenCaught` through a `(u8)` cast, which keeps it at 99.75%; it scores lower without the cast.
- `calculateHitVariables` (game_batter) is at 99.46%. The permuter reached a match only with casts no programmer would write.
- `fn_3_A7040` (rep_18E8) is at 98.93% with a conditional whose two arms are equal, `(a > b ? x : x)`, which reproduces a compare the target keeps; without it the function is at 98.49%.
- `fn_3_135520` (rep_3520) stays out of line, as in the target, only because it is written with `else if` and a `goto out;` to a shared `return 0`, which compiles the same but counts as larger for MWCC's auto-inline limit.
- `fn_3_80028` (rep_13B8, 97.54%) passes `(VecXZ*)&out` to `running_roundBasePosition` in case 2, which keeps the target's step stores.
- `rep_720.c` keeps a `#pragma dont_inline on/reset` around `fn_3_16D6C` from an earlier batch.
- `fn_3_8DA80` (m_sound) matches only as `jingle = FALSE; if (song == 4 || song == 0) jingle = TRUE; jingle = !jingle; if (jingle) ...`; no other form keeps the target's negated value.
- `fn_3_8CD74` (m_sound) tests `captainStarSwingActivated == 11 || captainStarSwingActivated == 11`, most likely a typo in the original for `== 12`, since the `switch` above pairs cases 11 and 12.
- `fn_3_15DB44` (rep_3BD8) matches only with the first sprite's index written `lbl_80371C30[task->_14 + 0]`, at all six such indexes for one style: the `+ 0` makes the index an `int`, giving the target's `slwi` instead of a masked `rlwinm`. Without it the function is at 99.93%.
- Several best candidates stop short of a match that the permuter reached only with unlikely source: `fn_3_738A8` (rep_1200, 99.91%) with an assignment inside a comparison, and `fn_3_8F21C` (m_sound, 99.37%) with `dome = dome != FALSE;` (99.78%).
