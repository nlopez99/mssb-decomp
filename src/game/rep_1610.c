#include "game/rep_1610.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"

typedef struct {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16[0x18 - 0x16];
    /* 0x18 */ u16 _18;
    /* 0x1A */ u8 _1A[0x1C - 0x1A];
    /* 0x1C */ u16 _1C;
} UnkTask1610;

typedef struct {
    /* 0x00 */ u8 _00[0x4C];
    /* 0x4C */ f32 _4C;
    /* 0x50 */ u8 _50[0x5C - 0x50];
    /* 0x5C */ s32 _5C;
} UnkSprite1610;

typedef struct {
    /* 0x00 */ UnkSprite1610* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef1610; // size: 0x8

extern UnkSpriteRef1610 lbl_80371C30[];
extern void* lbl_803CC1B8;

// .data outside this unit's split
extern u8 lbl_3_data_D5B8[];

// .text outside this unit's split
extern void fn_3_911A8(void);

extern void fn_80034E20(UnkTask1610* task, void* data);
extern void fn_8003649C(UnkTask1610* task, s32, s32, s32, s32);

// .text:0x000910F4 size:0xB4 mapped:0x806D0188
// Outside this unit's split; inlined into fn_3_912B4
static inline void fn_3_910F4(UnkTask1610* task) {
    s32 i;
    s32 outs;
    s32 type;

    outs = g_Strikes.outs;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        outs = g_Minigame._190D - g_Minigame._1910;
    }
    for (i = 0; i < 2; i++) {
        type = 3;
        if (task->_1C != outs) {
            if (outs >= i + 1) {
                type = 2;
            }
            fn_8003649C(task, i + 1, i + 1, 0x107, type);
        }
    }
    task->_1C = outs;
}

// .text:0x000912B4 size:0x188 mapped:0x806D0348
void fn_3_912B4(void) {
    UnkTask1610* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_3_data_D5B8);
    task->_1C = 9;
    for (i = 1; i < 3; i++) {
        lbl_80371C30[task->_14 + i]._00->_5C = (i - 1) << 16;
    }

    fn_3_910F4(task);

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        for (i = 0; i < 3; i++) {
            lbl_80371C30[task->_14 + i]._00->_4C = 56.0f;
        }
    }
    task->_18 = 0;
    ((UnkTask1610*)lbl_803CC1B8)->_00 = fn_3_911A8;
}
