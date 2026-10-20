#ifndef __STATIC_MB_SUBFUNC_H_
#define __STATIC_MB_SUBFUNC_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

void fn_80064534(void);
s8 translateStarPitchHitIndex(u8 index);
s32 translateStarPitch(s32 index);
s32 translateStarSwing(s32 index);
s32 fn_80064918(s16 id);
void fn_8006496C(void);
void fn_800649BC(void);
void unsure_FillRosterPositions(void);
void characterSelectScreen(void);
void fn_80066EAC(u8 team);
void fn_800670A0(u8 team);
void fn_800671FC(void);
u8 fn_80067264(s32 team, s32 captain);
u8 fn_800675C4(s32 team, s32 captain);
void fn_800678CC(s32 team);
s16 fn_80067AC8(s16 id, s8 slot);
s32 fn_80067B40(s32 arg0, u8 id, u8 value);
void fn_80067C48(u8 team);
void fn_80067F70(u8 team);
void fn_800684A4(void);
s32 fn_80068514(u32 frames, u8 target);
s32 fn_8006862C(u32 frames, u8 target);
void fn_80068720(u8 index);
void fn_8006877C(u8 index);
void fn_80068838(void);
s32 fn_800697B0(void);
void fn_80069854(void);
s32 fn_800698F8(s32 charId);

#endif // !__STATIC_MB_SUBFUNC_H_
