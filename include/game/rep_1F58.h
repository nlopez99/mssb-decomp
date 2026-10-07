#ifndef __GAME_rep_1F58_H_
#define __GAME_rep_1F58_H_

#include "mssbTypes.h"

struct Rep1F58Effect;

void fn_3_C0854(void);
void fn_3_C095C(struct Rep1F58Effect* effect);
void fn_3_C0AD8(void);
void fn_3_C0C4C(s32 idx);
void fn_3_C0CE8(int type, f32 x, f32 y, f32 z);
void fn_3_C0D10(s32 idx, u8 r, u8 g, u8 b, u8 a);
void fn_3_C0DD8(void* arg0, s32* tevStage, s32* texCoord, s32* texMap, u8* arg4, u8* arg5);
void fn_3_C0F8C(void);
void fn_3_C1004(void);
void fn_3_C11CC(s32 idx, BOOL remove);
void fn_3_C1344(s32 idx, f32 chargeUp, f32 chargeDown, BOOL full);
void fn_3_C1770(s32 idx);
// Outside this unit's .text range in splits.txt
s32 fn_3_C1930(s32 id);

#endif // !__GAME_rep_1F58_H_
