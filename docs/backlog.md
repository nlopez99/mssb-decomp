# Backlog

The work queue and open questions for matching batches. Each batch's pull request updates it (`.claude/skills/run-batch/SKILL.md`). This file keeps what the tools cannot show:
- a unit's functions, their state and which stubs each waits on: `python3 tools/match.py <unit>`;
- prototype cleanup: `python3 tools/check_prototypes.py`;
- unassigned code: the `auto_*_text` units in `objdiff.json`.

## Follow-ups

The unit's data and helpers are already in place, so these give the cheapest bytes.

- **rep_1E08:** define `.data` 0x111A8–0x170F0 (only rep_1E08 reads it) and split the lumped `lbl_3_data_111A8`, `111C8`, `1146C` and `15718`. `fn_3_BF070` reaches 100% with that data as statics. `fn_3_C0134` needs `.bss` 0x9952/0x9978 split. The stubs from 0xBA150 came with the batch-5 split.
- **rep_3090:** six stubs (`fn_3_FC448`, `FC938`, `FD51C`, `FD5A8`, `1069C0`, `106BA0`, about 4 KB) need a union view of `g_Camera` as two 0x9BC per-player slots at +0x13C. With it, `FD51C` and `FD5A8` match in a scratch copy and `1069C0` reaches 98.42%. Then `fn_3_FDB30`, a 0x24E8 script interpreter that `FD670` waits on.
- **rep_540:** `fn_3_6C38` (0x20B8) first, since `fn_3_A970` waits on it at 99.55%. The tail moved in by the batch-5 split: stubs `fn_3_FF4C` and `ballPhysica`; `fn_3_FF98` and `fn_3_10030` are still `static inline` in `rep_540.c` and become plain functions.
- **rep_13B8, rep_18E8, rep_3520, rep_31A0:** large stubs that their other functions wait on (`match.py` lists them).
- **rep_3880:** `fn_3_1540E4` inlines `fn_3_153F8C`, which the target calls instead; unsolved.
- **rep_3310:** the model-load pattern (`addi r0,table,0x34` then `lwzx`) keeps `fn_3_119E30`, `119EE0`, `11881C`, `1194AC` and `11897C` at 65–93%.

## Untouched units

- **Largest first:**
  - rep_AC8: about 214 KB in one object, 225 functions, so several sessions.
  - sta_c2: about 53 KB. Apply `.data` 0x182C0–0x188E8 when it is claimed.
  - sta_c5 (42 KB), rep_1FD8 (31 KB), rep_16B8 (31 KB), rep_E08 (28 KB), rep_1200 (25 KB), rep_37A8 (22 KB), m_sound (22 KB) and rep_DB8 (21 KB).
- **Created by the batch-5 splits pass; bundle the small ones:** rep_1A80 (13 KB), rep_3BD8, rep_3A48, rep_1AD0, rep_1B20, rep_1C68, rep_D18, rep_1C18, rep_1BC8, rep_3A98, rep_1720, rep_CC8, rep_9B0 and rep_868.
- **Whole modules:** the `menus` and `challenge` modules, both at 0%.

## Unassigned game code

Each game object has exactly one `repHeaderData` copy, so every gap is a neighbour's head or tail (`docs/matching-notes.md`, "Unit boundaries"). Each line below gives the likely owner. Decide when that unit is claimed, from pool bases and jump tables.

- 0x759BC: rep_1200's tail.
- 0x7976C: rep_12D0's tail.
- 0x8B094 and 0x90754: m_sound's head and tail.
- 0x1471C0: rep_37A8's tail.
- 0x113398: rep_31F0's tail.
- 0x1293D0–0x12E8FC (21 KB): only its position is known, between rep_3448 and rep_34B0.
- 0xE911C and 0xEA340 (15 KB): around rep_2BF8, using the tables at 0x19770–0x1BA88.
- 0xE0668 and 0xE1964: around rep_2940; they are copies of one function.
- Tails of linked units: 0xCB6B4 (rep_2390, with `.data` 0x18268–0x182C0 and `.bss` 0x9FDC–0xA018), 0x114FC0 (rep_3290), 0x1608F0 (rep_3D50) and 0x1665E4 (rep_3E00). Head of a linked unit: 0x1E154 (rep_8C8).
- Position only: 0x1D86C, 0x674E0, 0x6A160, 0x6AEC0, 0x6B4C8, 0x6C854, 0x6D4A0, 0x6F4E8, 0x7CE90, 0x9C578, 0x9CD90, 0xB7EF0, 0xC0810, 0xCB344, 0x13C790 and 0x1658F0.

## Open questions

- **Units with no code found:** rep_A78 and rep_D68. rep_D68 may hold only data: rep_13B8 is the only unit that reads 0x4A34–0x4C54, and rep_540 the only one that reads 0x4414–0x4608, yet both ranges lie inside rep_DB8's `.data`.
- **rep_3310's `.bss` 0xB6B8–0xB6BC:** probably an unreferenced static of rep_3310. Starting its `.bss` at 0xB6BC would break the 8-byte alignment rule.
- **Stadium types:** rep_2998's `Rep2998Model`/`Rep2998Actor` and rep_1D58's `StadiumModel1D58`/`ModelActor1D58` describe the same objects. They need one shared header; rep_2998.c's local externs that disagree with `rep_1D58.h` follow from this.
- **Main DOL:** no shared header for its functions, so units declare them locally with their own types. `check_prototypes.py` lists those whose calling conventions differ, such as `fn_800B0A5C_insertQueue`.
- **C3 headers:** offset comments after the embedded `Control` assume the SDK's 0x3C; this game's is 0x44.
- **Tables one unit uses that are not contiguous with its data:** rep_34B0's 0x216BC, and rep_36D8's 0x217F8–0x21984.
- **Unreferenced `.bss` that may be several objects:** rep_3D50's 0xB9BC (0x24 bytes) and rep_1D58's 0x9944 (0xC bytes).

## Decisions for the maintainer

- `fn_3_8781C` (rep_13B8) reads `g_Ball.ballZoneWhenCaught` through a `(u8)` cast, which keeps it at 99.75%; it scores lower without the cast.
- `calculateHitVariables` (game_batter) is at 99.46%. The permuter reached a match only with casts no programmer would write.
