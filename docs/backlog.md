# Backlog

The work queue and open questions for matching batches. Each batch's pull request updates it (`.claude/skills/run-batch/SKILL.md`). This file keeps what the tools cannot show:
- a unit's functions, their state and which stubs each waits on: `python3 tools/match.py <unit>`;
- prototype cleanup: `python3 tools/check_prototypes.py`;
- unassigned code: the `auto_*_text` units in `objdiff.json`.

## Follow-ups

The unit's data and helpers are already in place, so these give the cheapest bytes. Functions an earlier session time-boxed carry a comment saying what still differs.

- **rep_AC8** (214 KB, 60 of 225 functions match): `fn_3_51798` (0x658) is a stub returning 0 that `fn_3_251E4`, `25648`, `25A68` and `2F574` inline, and `fn_3_53130` blocks `fn_3_3C220`, `3C1A8` and others; `match.py rep_AC8` lists both under "waits on". 165 functions are left, the smallest free ones being `fn_3_37114`, `3A234`, `576B4`, `50898`, `3D7D4` and `43038`.
- **rep_16B8** (33 of 56): 18 functions not attempted, the largest `fn_3_91FC4` (0xD14) and `fn_3_959BC` (0xCE0). `fn_3_9894C` is at 87.43% because the build pools `lbl_3_data_D648`, `D7E8` and `D860`, which the target names one by one (Open questions).
- **rep_1FD8** (21 of 49): when it is claimed, give it `.data` 0x17508–0x17898, the unassigned gap between rep_1F58's and rep_21F8's `.data` that its functions read (`lbl_3_data_17514`, `177F0`, `17804`), after checking that its neighbours read nothing there. 27 functions not attempted; `fn_3_C2AA0` is a copy of sta_c2's `fn_3_CD968` and stops at the same 93.77%, and `fn_3_C71CC` and `C805C` resemble sta_c2's `fn_3_D5E80`.
- **sta_c5:** `fn_3_F6FDC` (0x1468) at 96.70%: making `_C3` a `u8` helps it but costs `fn_3_EFB54`, which reads `_C3` as `s8`, so the prop draws may use another layout over those bytes. `fn_3_F082C` 99.97% and `fn_3_F0FA4` 99.17% are register-only; eight time-boxed partials were not retried.
- **sta_c2:** `fn_3_D67CC` (0x2244) at 94.60% from a first draft: its frame is 16 bytes smaller than the target's, and one counter (`cmplw r3,r18; beq; addi r18,r18,1` in the spring loop) is unexplained. `fn_3_CCC24` 98.37% (the target keeps the placement pointer in r28 from entry) and `fn_3_CC81C` 99.19%.
- **rep_1E08:** define `.data` 0x111A8–0x170F0 (only rep_1E08 reads it) and split the lumped `lbl_3_data_111A8`, `111C8`, `1146C` and `15718`. `fn_3_BF070` reaches 100% with that data as statics. `fn_3_C0134` needs `.bss` 0x9952/0x9978 split.
- **rep_3520:** nine partials not yet attempted (`fn_3_136220`, `1373E0`, `1384B4`, `138AA4`, `1391C0`, `139808`, `139CA0`, `13A0AC`, `13ACB4`). Moving `MG.objs`/`MG.pieces` accesses onto real members lifts `fn_3_13BCB8` to about 94.4% but lowers `138AA4`, `1379A0` and `1373E0`, so do it per function. `fn_3_13334C` (0x1170) at 97.79%: the target keeps `g_Minigame`'s address in r14.
- **rep_720:** `fn_3_1850C` 99.94% and `fn_3_1CE90` 99.91% differ only in f28–f30 in their inlined copies of the camera helpers; writing the block out in the caller fixed `fn_3_17DA0` but fixes only the first copy in these two. `fn_3_19FA4` 97.38%.
- **rep_3090:** `fn_3_FDB30` (0x24E8) at 99.59%, registers in the captain searches (opcodes 0x48, 0x49, 0x55, 0x58, 0x59), 0x2F's modulo and 0x66's distance sum. `fn_3_FCF24` 93.12%: its int-to-float constant uses the `addi` form only in the target.
- **rep_13B8:** `fn_3_80028` (0x109C) 97.54%; `fn_3_8A618` 96.50% standalone conflicts with its matched copy in `fn_3_8A958`; `fn_3_85CB0` 60.54%: the target does not fold `fn_3_85C44`'s `direction` tests after inlining it; `fn_3_81BC8` 95.27% not attempted.
- **One function left:** rep_9B0's `fn_3_219CC` (87.36%, the target keeps `&g_GameLogic` and the captain offset apart for an `lwzx`), rep_3A98's `fn_3_15B494` (95.47%), rep_868's `fn_3_1DEB8` (99.64%) and rep_18E8's `fn_3_A8478` (99.64%, register-only).
- **rep_31A0:** `fn_3_10CC20` (0x19EC) at 99.92%, one `bne; b` around a `continue` (`docs/matching-notes/structure.md`).
- **rep_540:** five partials at 94.5–99.94%. For `fn_3_A970`, squaring `velocity.x` into a local first fixes the velocity part (99.85%), but the local found so far is a misused `angle`.
- **rep_3880:** `fn_3_1540E4` inlines `fn_3_153F8C`, which the target calls instead; unsolved.
- **rep_3310:** the model-load pattern (`addi r0,table,0x34` then `lwzx`) keeps `fn_3_119E30`, `119EE0`, `11881C`, `1194AC` and `11897C` at 65–93%.

## Untouched units

- **Largest first:** rep_E08 (28 KB), rep_1200 (25 KB), rep_37A8 (22 KB), m_sound (22 KB) and rep_DB8 (21 KB; see the open question on its `.data`).
- **Created by the batch-5 splits pass; bundle the small ones:** rep_1A80 (13 KB), rep_3BD8 (12 KB), rep_3A48 (12 KB), rep_1AD0, rep_1B20, rep_1C68, rep_D18, rep_1C18 and rep_1720.
- **Whole modules:** the `menus` and `challenge` modules, both at 0%.

## Unassigned game code

Each game object has exactly one `repHeaderData` copy, so every gap is a neighbour's head or tail (`docs/matching-notes.md`, "Unit boundaries"). Each line below gives the likely owner. Decide when that unit is claimed, from pool bases and jump tables.

- 0x759BC: rep_1200's tail.
- 0x7976C: rep_12D0's tail.
- 0x8B094 and 0x90754: m_sound's head and tail.
- 0x1471C0: rep_37A8's tail.
- 0x113398: rep_31F0's tail.
- 0x1293D0–0x12E8FC (21 KB): only its position is known, between rep_3448 and rep_34B0.
- 0xE911C and 0xEA340 (15 KB): rep_2BF8's head and tail, or sta_c5's head; they read the tables at 0x19770–0x1B820, which end just before sta_c5's `.data`. rep_16B8 calls `fn_3_ED574` in the second gap.
- 0xE0668 and 0xE1964: around rep_2940; they are copies of one function.
- 0xB7EF0: holds `fn_3_B7F18` (a cross product rep_540 calls) and `fn_3_B7F70` (sta_c2 and rep_2998 call it); both are declared locally by their callers.
- Tails of linked units: 0xCB6B4 (rep_2390, with `.data` 0x18268–0x182C0 and `.bss` 0x9FDC–0xA018), 0x114FC0 (rep_3290), 0x1608F0 (rep_3D50) and 0x1665E4 (rep_3E00). Head of a linked unit: 0x1E154 (rep_8C8).
- Position only: 0x1D86C, 0x674E0, 0x6A160, 0x6AEC0, 0x6B4C8, 0x6C854, 0x6D4A0, 0x6F4E8, 0x7CE90, 0x9C578, 0x9CD90, 0xC0810, 0xCB344, 0x13C790 and 0x1658F0.

## Open questions

- **rep_DB8's `.data` (0x4290–0x65F0) holds objects only other units read:** 0x4A34–0x4C54 (rep_13B8, which also reads 0x4290), 0x4414–0x4608 (rep_540), 0x610C and 0x6124 (rep_540's `fn_3_6C38`), and 0x470C/0x4710 (rep_AC8 and rep_18E8). Either rep_DB8's range is too wide or those units read another object's data; decide when rep_DB8 is claimed.
- **Units with no code found:** rep_A78 and rep_D68. rep_D68 may hold only data.
- **rep_3310's `.bss` 0xB6B8–0xB6BC:** probably an unreferenced static of rep_3310. Starting its `.bss` at 0xB6BC would break the 8-byte alignment rule.
- **rep_3520's `.bss`:** 0xE bytes follow `lbl_3_bss_B781` (`gap_05_0000B782_bss`), more than alignment padding; probably an unreferenced static of unknown size.
- **Stadium types:** rep_2998 now uses `rep_1D58.h`'s types. Two pairs still describe the same objects: `Rep2998Common` and rep_1D58's struct for `lbl_3_common_bss_350E4`, and `Rep2998ModelTable` and `StadiumActor1D58`. rep_1D58.c still declares `fn_3_F6084`, `fn_3_F6504` (now in `sta_c5.h`) and `fn_3_D55EC` (now in `sta_c2.h`) locally.
- **rep_1838 prototypes:** `fn_3_9FB8C` returns `s32` in practice (29 of 68 call sites sign-extend its result; `rep_1838.h` says `s16`), and `fn_3_9FCF8` takes `(s32, s32)` (it sign-extends both on entry). rep_AC8 declares both locally; fixing the header needs `rep_1838.c` to compile the same.
- **Main DOL:** no shared header for its functions, so units declare them locally with their own types. `check_prototypes.py` lists those whose calling conventions differ, such as `fn_800B0A5C_insertQueue`.
- **C3 headers:** offset comments after the embedded `Control` assume the SDK's 0x3C; this game's is 0x44. `geoPalette.h` puts `DODisplayObj.worldMatrix` at 0x1C, but this game's is at 0x18 (`fn_3_EE100`, `fn_3_EE67C`); sta_c5 declares `DOSetWorldMatrix` locally.
- **Tables one unit uses that are not contiguous with its data:** rep_34B0's 0x216BC, and rep_36D8's 0x217F8–0x21984. rep_3A98 and rep_1BC8 read `lbl_3_data_FAA8`, and rep_3A98 `FC1C`, inside rep_1B20's `.data`.
- **rep_16B8's pooled tables:** its `fn_3_9894C` names `lbl_3_data_D648`, `D7E8` and `D860` one by one, which an `extern` copy reproduces (95.97%) and a definition in the same file does not (87.43%, pooled). The original may have defined them in another file, which bears on rep_16B8's `.data` range.
- **`fn_800363D8`'s last parameter:** `rep_1770.c` declares it `u16`, but rep_16B8's `fn_3_94760` passes an untruncated 32-bit sum; rep_16B8 declares it `u32` locally.
- **Unreferenced `.bss` that may be several objects:** rep_3D50's 0xB9BC (0x24 bytes) and rep_1D58's 0x9944 (0xC bytes).

## Decisions for the maintainer

- `fn_3_8781C` (rep_13B8) reads `g_Ball.ballZoneWhenCaught` through a `(u8)` cast, which keeps it at 99.75%; it scores lower without the cast.
- `calculateHitVariables` (game_batter) is at 99.46%. The permuter reached a match only with casts no programmer would write.
- `fn_3_A7040` (rep_18E8) is at 98.93% with a conditional whose two arms are equal, `(a > b ? x : x)`, which reproduces a compare the target keeps; without it the function is at 98.49%.
- `fn_3_135520` (rep_3520) stays out of line, as in the target, only because it is written with `else if` and a `goto out;` to a shared `return 0`, which compiles the same but counts as larger for MWCC's auto-inline limit.
- `fn_3_80028` (rep_13B8, 97.54%) passes `(VecXZ*)&out` to `running_roundBasePosition` in case 2, which keeps the target's step stores.
- `rep_720.c` keeps a `#pragma dont_inline on/reset` around `fn_3_16D6C` from an earlier batch.
