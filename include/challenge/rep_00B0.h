#ifndef __CHALLENGE_rep_00B0_H_
#define __CHALLENGE_rep_00B0_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct Box00B0;
struct Ray00B0;

void fn_1_196C(void);
void fn_1_19AC(void);
void fn_1_1BF8(struct Box00B0* boxes, s32 idx);
void fn_1_1DBC(s32 a, s32 b, s32 c, s32 d, s32 color);
void fn_1_25BC(void* mesh);
void fn_1_3E38(Vec* pos, u32 material);
void fn_1_4074(Vec* pos);
void fn_1_4290(Vec* line);
u32 fn_1_4728(Vec* line, Vec* out);
void fn_1_4A24(struct Ray00B0* ray, void* mesh);
void fn_1_4DD8(u16* data);

#endif // !__CHALLENGE_rep_00B0_H_
