#ifndef __GAME_kinoko_H_
#define __GAME_kinoko_H_

#include "mssbTypes.h"
#include "Dolphin/gx.h"

// Named after the panic message in fn_3_16B488
typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec _0C;
    /* 0x18 */ Vec _18;
    /* 0x24 */ u8 color[4];
    /* 0x28 */ u8 colorFrom;
    /* 0x29 */ u8 colorTo;
    /* 0x2A */ u8 _2A;
} RibbonEffect;

void fn_3_16917C(void* arg0, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* arg4, u8* arg5);
void fn_3_16943C(void);
void fn_3_1695A0(void);
void fn_3_1695A4(s8 arg0, u8 arg1);
void fn_3_169600(void);
void fn_3_169804(void);
void fn_3_169984(void);
void fn_3_169D00(RibbonEffect* ribbon, u32* count);
void fn_3_169E70(RibbonEffect* ribbon);
void fn_3_16A07C(void);
void fn_3_16B488(Vec* pos, s8 id);
void fn_3_16B5B4(RibbonEffect* ribbon, s8 id, int frame);
void fn_3_16B884(void);
void fn_3_16C394(s8 arg0);

#endif // !__GAME_kinoko_H_
