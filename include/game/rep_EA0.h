#ifndef __GAME_rep_EA0_H_
#define __GAME_rep_EA0_H_

#include "mssbTypes.h"
#include "Dolphin/vec.h"

struct UnkTexFileEA0;
void fn_3_6750C(struct UnkTexFileEA0* file);
void fn_3_675B8(u16 frames);
void fn_3_67620(s32 type, u16 frames);
void fn_3_678B8(void);
void fn_3_67A48(void);
void fn_3_67C34(void* arg);
struct UnkRingEA0;
s32 fn_3_67EF0(struct UnkRingEA0* ring, s32 count, Vec* pos, u32* colors, u32 color, Vec* pos2, u32* colors2, Vec* dir,
               f32 width);
void fn_3_685F0(void);
void fn_3_68BB4(void);
void fn_3_690FC(void);
void fn_3_6916C(void);
void fn_3_69184(void);
void fn_3_692E0(void);
void fn_3_695F8(BOOL show);
void fn_3_697CC(void);

#endif // !__GAME_rep_EA0_H_
