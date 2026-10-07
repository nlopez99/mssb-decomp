#include "game/rep_2BF8.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_720.h"

typedef struct UnkTask2BF8 {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ u16 _14;
} UnkTask2BF8;

typedef struct {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ f32 _48;
    /* 0x4C */ f32 _4C;
    /* 0x50 */ u8 _50[0x54 - 0x50];
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ s32 _5C;
} UnkSprite2BF8;

typedef struct {
    /* 0x00 */ UnkSprite2BF8* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef2BF8; // size: 0x8

extern struct {
    /* 0x00 */ u8 _00[0x96];
    /* 0x96 */ u8 _96;
    /* 0x97 */ u8 _97;
} lbl_3_common_bss_32724;

extern UnkSpriteRef2BF8 lbl_80371C30[];
extern void* lbl_803CC1B8;

// Screen-edge bands: x from [0] to [1] and from [3] to [2], y from [4] to [5] and from [7] to [6].
extern s16 lbl_3_data_D638[8];
extern u16 lbl_3_data_91AC[8];

extern void fn_80034CEC(UnkTask2BF8* task);
extern void fn_800B0A14_removeQueue(void);

// .text:0x000E9D30 size:0x610 mapped:0x80728DC4
void fn_3_E9D30(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    VecXYZ pos;
    int x;
    int y;
    int j;
    int alphaX;
    int alphaY;
    int i;
    int dir;
    int px;
    int py;
    int dx;
    int dz;

    if (lbl_3_common_bss_32724._96 == 0 && g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL && g_Minigame._19CE == 0 &&
        g_Minigame.turnOverStatus == 0) {
        for (i = 0; i < 3; i++) {
            if (g_Minigame.minigameControlStruct._28[i] < 0) {
                continue;
            }
            dir = -1;
            alphaX = 0xFF;
            alphaY = 0xFF;
            getAnimRelatedCoordinates(
                g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigameControlStruct._28[i]], 4, &pos);
            if (!fn_3_1650C(&x, &y, FALSE, pos.x, pos.y, pos.z)) {
                for (j = 0; j < 3; j++) {
                    dx = g_pCamera->_284C.x - pos.x;
                    dz = g_pCamera->_284C.z - pos.z;
                    dx *= 0.2f;
                    dz *= 0.2f;
                    pos.x += dx;
                    pos.z += dz;
                    if (fn_3_1650C(&x, &y, FALSE, pos.x, pos.y, pos.z)) {
                        break;
                    }
                }
            }

            if (x <= (px = lbl_3_data_D638[1])) {
                dir = 2;
                if (x > lbl_3_data_D638[0]) {
                    alphaX = 255.0f * (1.0f - (f32)(x - lbl_3_data_D638[0]) / (f32)(px - lbl_3_data_D638[0]));
                }
            } else if (x >= (px = lbl_3_data_D638[3])) {
                dir = 5;
                if (x < lbl_3_data_D638[2]) {
                    alphaX = 255.0f * (1.0f - (f32)(x - lbl_3_data_D638[2]) / (f32)(px - lbl_3_data_D638[2]));
                }
            } else {
                px = x;
            }
            if (alphaX > 0xFF) {
                alphaX = 0xFF;
            }

            if (y <= (py = lbl_3_data_D638[5])) {
                dir += 1;
                if (y > lbl_3_data_D638[4]) {
                    alphaY = 255.0f * (1.0f - (f32)(y - lbl_3_data_D638[4]) / (f32)(py - lbl_3_data_D638[4]));
                }
            } else if (y >= (py = lbl_3_data_D638[7])) {
                dir += 2;
                if (y < lbl_3_data_D638[6]) {
                    alphaY = 255.0f * (1.0f - (f32)(y - lbl_3_data_D638[6]) / (f32)(py - lbl_3_data_D638[6]));
                }
            } else {
                py = y;
            }
            if (alphaY > 0xFF) {
                alphaY = 0xFF;
            }

            if (dir < 0 || alphaX <= 0 || alphaY <= 0) {
                lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                continue;
            }
            lbl_80371C30[task->_14 + i]._00->_54 |= 2;
            lbl_80371C30[task->_14 + i]._00->_48 = px;
            lbl_80371C30[task->_14 + i]._00->_4C = py;
            if (dir == 2 || dir == 5) {
                lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & ~0xFF) | alphaX;
            } else if (dir >= 2) {
                if (alphaX > alphaY) {
                    lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & ~0xFF) | alphaX;
                } else {
                    lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & ~0xFF) | alphaY;
                }
            } else {
                lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & ~0xFF) | alphaY;
            }
            lbl_80371C30[task->_14 + i]._00->_5C = lbl_3_data_91AC[dir] << 16;
        }
    } else {
        lbl_3_common_bss_32724._97 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}
