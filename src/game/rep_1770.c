#include "game/rep_1770.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"

typedef struct UnkTask1770 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16[0x18 - 0x16];
    /* 0x18 */ u16 _18;
    /* 0x1A */ u8 _1A[0x1C - 0x1A];
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
    /* 0x22 */ u16 _22;
} UnkTask1770;

typedef struct {
    /* 0x00 */ u8 _00[0x4C];
    /* 0x4C */ f32 _4C;
    /* 0x50 */ u8 _50[0x54 - 0x50];
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[0x68 - 0x66];
    /* 0x68 */ u8 _68;
} UnkSprite1770;

typedef struct {
    /* 0x00 */ UnkSprite1770* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef1770; // size: 0x8

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc1770; // size: 0x20

extern struct {
    /* 0x00 */ u8 _00[0x96];
    /* 0x96 */ u8 _96;
    /* 0x97 */ u8 _97[0xA6 - 0x97];
    /* 0xA6 */ u8 _A6;
    /* 0xA7 */ u8 _A7;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ u8 _50[0xAD - 0x50];
    /* 0xAD */ u8 _AD;
} g_Scores;

extern struct {
    /* 0x000 */ u8 _000[0x1D2];
    /* 0x1D2 */ u8 _1D2;
} lbl_3_common_bss_34C90;

extern s16 lbl_3_data_5F3C[4];
extern u8 lbl_3_data_F430[12][2];
extern u8 lbl_3_data_F4D0[16];
extern UnkSpriteRef1770 lbl_80371C30[];
extern void* lbl_803CC1B8;

// Only this unit reads these; they lie outside its splits.txt ranges.
extern UnkSpriteDesc1770 lbl_3_data_C22C[9];
extern UnkSpriteDesc1770 lbl_3_data_C34C[17];
extern UnkSpriteDesc1770 lbl_3_data_D258[9];
extern UnkSpriteDesc1770 lbl_3_data_D378[12];
extern UnkSpriteDesc1770 lbl_3_data_D4F8[6];

extern void fn_80034CEC(UnkTask1770* task);
extern void fn_80034E20(UnkTask1770* task, UnkSpriteDesc1770* desc);
extern void fn_8003649C(UnkTask1770* task, s32, s32, s32, s32);
extern void fn_800B0A14_removeQueue(void);
extern void fn_3_972A0(UnkTask1770* task, s32, s32, s32);

// .text:0x0009C28C size:0x2EC mapped:0x806DB320
void fn_3_9C28C(void) {
    UnkTask1770* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_3_data_C22C);
    task->_22 = 0;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        task->_22 = 1;
        for (i = 0; i < 8; i++) {
            lbl_80371C30[task->_14 + i]._00->_4C = -30.0f;
        }
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        if (g_Practice.practiceLevel != 7 && g_Practice.practiceLevel != 6) {
            task->_22 = 1;
        }
    }
    if (task->_22 != 0) {
        for (i = 1; i < 6; i++) {
            lbl_80371C30[task->_14 + i]._00->_64 = 0x104;
        }
        lbl_80371C30[task->_14]._00->_64 = 0x103;
        lbl_80371C30[task->_14 + 6]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 7]._00->_54 &= ~2;
    }
    task->_1C = task->_1E = task->_20 = 9;
    for (i = 1; i < 8; i++) {
        lbl_80371C30[task->_14 + i]._00->_5C = (i - 1) << 16;
    }
    fn_3_9BEE0(task);
    task->_18 = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_9C014;
}

// .text:0x0009C014 size:0x278 mapped:0x806DB0A8
void fn_3_9C014(void) {
    UnkTask1770* task = lbl_803CC1B8;
    s32 i;

    if (lbl_3_common_bss_32724._96 != 0 || lbl_3_common_bss_32724._A7 == 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    task->_18++;
    fn_3_9BEE0(task);
    if (lbl_3_common_bss_32724._A7 < 0xFF) {
        for (i = 0; i < 8; i++) {
            lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & 0xFFFFFF00) | lbl_3_common_bss_32724._A7;
        }
    } else {
        for (i = 1; i < 8; i++) {
            lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & 0xFFFFFF00) | lbl_3_common_bss_32724._A6;
        }
    }
}

// .text:0x0009BEE0 size:0x134 mapped:0x806DAF74
void fn_3_9BEE0(UnkTask1770* task) {
    s32 i;
    int ball;
    s32 outs;
    s32 type;

    outs = g_Strikes.outs;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        outs = g_Minigame._190D - g_Minigame._1910;
    }
    for (i = 0; i < 7; i++) {
        type = 3;
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && i >= 5) {
            break;
        }
        if (i < 2) {
            if (task->_1C == g_Strikes.strikes) {
                continue;
            }
            if (g_Strikes.strikes >= i + 1) {
                type = 0;
            }
        } else if (i < 5) {
            if (task->_1E == g_Strikes.balls) {
                continue;
            }
            ball = i - 1;
            if (g_Strikes.balls >= ball) {
                type = 1;
            }
        } else {
            if (task->_20 == outs) {
                continue;
            }
            if (outs >= i - 4) {
                type = 2;
            }
        }
        fn_8003649C(task, i + 1, i + 1, 0x107, type);
    }
    task->_1C = g_Strikes.strikes;
    task->_1E = g_Strikes.balls;
    task->_20 = outs;
}

// .text:0x0009B7F4 size:0x6EC mapped:0x806DA888
void fn_3_9B7F4(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_C34C);
    lbl_80371C30[task->_14 + 5]._00->_64 = lbl_3_data_F430[g_GameLogic.logo[0].captain][1];
    lbl_80371C30[task->_14 + 6]._00->_64 = lbl_3_data_F430[g_GameLogic.logo[1].captain][1];
    lbl_80371C30[task->_14 + 5]._00->_5C = g_GameLogic.logo[0].variationID << 16;
    lbl_80371C30[task->_14 + 6]._00->_5C = g_GameLogic.logo[1].variationID << 16;
    if (g_Scores._AD != 0) {
        lbl_80371C30[task->_14 + 1]._00->_64 = 0x11B;
        lbl_80371C30[task->_14 + 2]._00->_64 = 0x119;
        lbl_80371C30[task->_14 + 3]._00->_64 = 0x116;
    }

    fn_8003649C(task, 3, 1, 0x110, lbl_3_data_F4D0[g_Scores._00 - 1]);
    fn_8003649C(task, 3, 3, 0x110, lbl_3_data_F4D0[g_Scores._00 - 1]);
    if (g_Scores._00 >= 10) {
        lbl_80371C30[task->_14 + 7]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 8]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 9]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 9]._00->_5C = 0;
        lbl_80371C30[task->_14 + 8]._00->_5C = 1 << 16;
        fn_8003649C(task, 9, 1, 0x112, g_Scores._00 / 10);
        fn_8003649C(task, 8, 2, 0x112, g_Scores._00 % 10);
        fn_8003649C(task, 9, 4, 0x112, g_Scores._00 / 10);
        fn_8003649C(task, 8, 5, 0x112, g_Scores._00 % 10);
    } else {
        lbl_80371C30[task->_14 + 7]._00->_5C = 2 << 16;
        fn_8003649C(task, 7, 3, 0x112, g_Scores._00);
        fn_8003649C(task, 7, 6, 0x112, g_Scores._00);
    }

    if (g_Scores._04[0][0] >= 10) {
        lbl_80371C30[task->_14 + 10]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 11]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 12]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 12]._00->_5C = 2 << 16;
        lbl_80371C30[task->_14 + 11]._00->_5C = 3 << 16;
    } else {
        lbl_80371C30[task->_14 + 10]._00->_5C = 0;
    }
    if (g_Scores._04[1][0] >= 10) {
        lbl_80371C30[task->_14 + 13]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 14]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 15]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 15]._00->_5C = 4 << 16;
        lbl_80371C30[task->_14 + 14]._00->_5C = 5 << 16;
    } else {
        lbl_80371C30[task->_14 + 13]._00->_5C = 1 << 16;
    }

    fn_3_9B108(task);
    task->_1C = g_Scores._04[0][0];
    task->_1E = g_Scores._04[1][0];
    task->_18 = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_9B320;
}

// .text:0x0009B320 size:0x4D4 mapped:0x806DA3B4
void fn_3_9B320(void) {
    UnkTask1770* task = lbl_803CC1B8;
    s32 i;

    task->_18++;
    if (lbl_3_common_bss_32724._96 != 0 || lbl_3_common_bss_32724._A7 == 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    if (task->_1C != g_Scores._04[0][0] || task->_1E != g_Scores._04[1][0]) {
        fn_3_9B108(task);
    }
    if (lbl_3_common_bss_32724._A7 < 0xFF) {
        for (i = 0; i < 16; i++) {
            lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & 0xFFFFFF00) | lbl_3_common_bss_32724._A7;
        }
    } else {
        for (i = 4; i <= 15; i++) {
            lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & 0xFFFFFF00) | lbl_3_common_bss_32724._A6;
        }
    }
}

// .text:0x0009B108 size:0x218 mapped:0x806DA19C
void fn_3_9B108(UnkTask1770* task) {
    if (g_Scores._04[0][0] >= 10) {
        fn_3_972A0(task, 11, 4, g_Scores._04[0][0] % 10);
        fn_3_972A0(task, 12, 3, g_Scores._04[0][0] / 10);
        fn_3_972A0(task, 11, 10, g_Scores._04[0][0] % 10);
        fn_3_972A0(task, 12, 9, g_Scores._04[0][0] / 10);
    } else {
        fn_3_972A0(task, 10, 1, g_Scores._04[0][0]);
        fn_3_972A0(task, 10, 7, g_Scores._04[0][0]);
    }
    if (g_Scores._04[1][0] >= 10) {
        fn_3_972A0(task, 14, 6, g_Scores._04[1][0] % 10);
        fn_3_972A0(task, 15, 5, g_Scores._04[1][0] / 10);
        fn_3_972A0(task, 14, 12, g_Scores._04[1][0] % 10);
        fn_3_972A0(task, 15, 11, g_Scores._04[1][0] / 10);
    } else {
        fn_3_972A0(task, 13, 2, g_Scores._04[1][0]);
        fn_3_972A0(task, 13, 8, g_Scores._04[1][0]);
    }
}

// .text:0x0009A8A4 size:0x864 mapped:0x806D9938
void fn_3_9A8A4(void) {
    return;
}

// .text:0x00099E10 size:0xA94 mapped:0x806D8EA4
void fn_3_99E10(void) {
    return;
}

// .text:0x00099CFC size:0x114 mapped:0x806D8D90
void fn_3_99CFC(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_D4F8);
    if (!(g_Batter.runnersOnBase & 1)) {
        lbl_80371C30[task->_14 + 3]._00->_54 &= ~2;
    }
    if (!(g_Batter.runnersOnBase & 2)) {
        lbl_80371C30[task->_14 + 2]._00->_54 &= ~2;
    }
    if (!(g_Batter.runnersOnBase & 4)) {
        lbl_80371C30[task->_14 + 1]._00->_54 &= ~2;
    }
    if (g_Pitcher.nPitchesThisAB == 0 && g_Pitcher.nPickoffAttempts == 0) {
        playSoundEffect(0x1AB);
    }
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_99C88;
}

// .text:0x00099C88 size:0x74 mapped:0x806D8D1C
void fn_3_99C88(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 == 0 && lbl_3_common_bss_32724._A7 != 0) {
        lbl_80371C30[task->_14]._00->_58 = (lbl_80371C30[task->_14]._00->_58 & 0xFFFFFF00) | lbl_3_common_bss_32724._A7;
    } else {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00099BDC size:0xAC mapped:0x806D8C70
void fn_3_99BDC(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_D258);
    if (g_Minigame.GameMode_MiniGame == 2) {
        lbl_80371C30[task->_14]._00->_5C = 3 << 16;
    } else {
        lbl_80371C30[task->_14]._00->_5C = 2 << 16;
    }
    task->_1C = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_99818;
}

// .text:0x00099818 size:0x3C4 mapped:0x806D88AC
void fn_3_99818(void) {
    UnkTask1770* task = lbl_803CC1B8;
    s32 frame = 0;
    f32 ratio;

    if (lbl_3_common_bss_32724._96 != 0) {
        goto remove;
    }
    if (g_Minigame.GameMode_MiniGame == 2) {
        if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_MINIGAME_POSTGAME) {
            goto remove;
        }
        if (g_Minigame.pauseInd != 0) {
            if (lbl_3_common_bss_34C90._1D2 == 7 || lbl_3_common_bss_34C90._1D2 == 13) {
                goto remove;
            }
        }
    } else if (lbl_3_common_bss_32724._A7 == 0) {
        goto remove;
    }

    if (g_Pitcher.ChargePitchType != 0) {
        ratio = (f32)g_Pitcher.unknownFrameCounter / (f32)(g_Pitcher.pitchWindUpCountDown - lbl_3_data_5F3C[2]);
        if (ratio >= 1.0f) {
            ratio = 1.0f;
        }
        lbl_80371C30[task->_14 + 3]._00->_68 = 0;
        frame = 106.0f * ratio;
        if (g_Pitcher.ChargePitchType == 3) {
            lbl_80371C30[task->_14 + 3]._00->_5C = 106 << 16;
            if ((s32)(lbl_80371C30[task->_14 + 2]._00->_5C >> 16) < 106) {
                lbl_80371C30[task->_14 + 2]._00->_5C = 106 << 16;
            } else {
                lbl_80371C30[task->_14 + 2]._00->_68 = 1;
            }
            frame = 106;
        } else if (g_Pitcher.overChargeInd != 0) {
            frame = 106.0f * g_Pitcher.pitchChargeUp;
            lbl_80371C30[task->_14 + 3]._00->_5C = frame << 16;
        } else {
            lbl_80371C30[task->_14 + 3]._00->_5C = frame << 16;
        }
    } else {
        lbl_80371C30[task->_14 + 3]._00->_5C = 0;
        lbl_80371C30[task->_14 + 3]._00->_68 = 0;
        lbl_80371C30[task->_14 + 2]._00->_5C = 0;
    }

    if (g_Pitcher.ChargePitchType != 0) {
        lbl_80371C30[task->_14 + 5]._00->_68 = 0;
        if (g_Pitcher.ChargePitchType == 3) {
            lbl_80371C30[task->_14 + 5]._00->_68 = 1;
        } else {
            lbl_80371C30[task->_14 + 5]._00->_5C = (frame + 10) << 16;
        }
    } else {
        if ((lbl_80371C30[task->_14 + 5]._00->_5C >> 16) < 10) {
            lbl_80371C30[task->_14 + 5]._00->_68 = 1;
        } else {
            lbl_80371C30[task->_14 + 5]._00->_5C = 10 << 16;
            lbl_80371C30[task->_14 + 5]._00->_68 = 0;
        }
    }

    if (g_Pitcher.ChargePitchType >= 2) {
        if (task->_1C == 0) {
            lbl_80371C30[task->_14 + 6]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 6]._00->_5C = frame << 16;
            lbl_80371C30[task->_14 + 7]._00->_5C = 0;
            lbl_80371C30[task->_14 + 7]._00->_68 = 1;
            task->_1C = 1;
        }
    } else {
        lbl_80371C30[task->_14 + 6]._00->_54 &= ~2;
        task->_1C = 0;
    }
    return;

remove:
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}

// .text:0x0009976C size:0xAC mapped:0x806D8800
void fn_3_9976C(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_D378);
    if (g_Batter.batterHand != 0) {
        lbl_80371C30[task->_14]._00->_5C = 0;
    } else {
        lbl_80371C30[task->_14]._00->_5C = 1 << 16;
    }
    task->_1C = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_993A8;
}

// .text:0x000993A8 size:0x3C4 mapped:0x806D843C
void fn_3_993A8(void) {
    UnkTask1770* task = lbl_803CC1B8;
    s32 frame = 0;

    if (lbl_3_common_bss_32724._96 == 0 && lbl_3_common_bss_32724._A7 != 0) {
        if (g_Batter.chargeStatus != 0) {
            if (g_Batter.chargeUp < 1.0f) {
                lbl_80371C30[task->_14 + 2]._00->_64 = 0x49;
                frame = 75.0f * g_Batter.chargeUp;
            } else {
                lbl_80371C30[task->_14 + 2]._00->_64 = 0x48;
                frame = (s32)(31.0f * g_Batter.chargeDown) + 75;
            }
            if (g_Batter.chargeDown >= 1.0f) {
                lbl_80371C30[task->_14 + 3]._00->_5C = 106 << 16;
                if ((lbl_80371C30[task->_14 + 2]._00->_5C >> 16) < 106) {
                    lbl_80371C30[task->_14 + 2]._00->_5C = 106 << 16;
                } else {
                    lbl_80371C30[task->_14 + 2]._00->_68 = 1;
                }
                frame = 106;
            } else {
                lbl_80371C30[task->_14 + 3]._00->_5C = frame << 16;
                lbl_80371C30[task->_14 + 2]._00->_5C = 0;
                lbl_80371C30[task->_14 + 2]._00->_68 = 0;
            }
        } else {
            lbl_80371C30[task->_14 + 3]._00->_5C = 0;
            lbl_80371C30[task->_14 + 3]._00->_68 = 0;
            lbl_80371C30[task->_14 + 2]._00->_5C = 0;
        }

        if (g_Batter.chargeStatus != 0) {
            lbl_80371C30[task->_14 + 5]._00->_68 = 0;
            if (g_Batter.swingInd != 0 && g_Batter.chargeDown >= 1.0f) {
                if ((lbl_80371C30[task->_14 + 5]._00->_5C >> 16) < 106) {
                    lbl_80371C30[task->_14 + 5]._00->_5C = 106 << 16;
                } else {
                    lbl_80371C30[task->_14 + 5]._00->_68 = 1;
                }
            } else {
                lbl_80371C30[task->_14 + 5]._00->_5C = (frame + 10) << 16;
            }
        } else {
            if ((lbl_80371C30[task->_14 + 5]._00->_5C >> 16) < 10) {
                lbl_80371C30[task->_14 + 5]._00->_68 = 1;
            } else {
                lbl_80371C30[task->_14 + 5]._00->_5C = 10 << 16;
                lbl_80371C30[task->_14 + 5]._00->_68 = 0;
            }
        }

        if (g_Batter.chargeStatus != 0 && g_Batter.swingInd != 0) {
            if (task->_1C == 0) {
                lbl_80371C30[task->_14 + 6]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 6]._00->_5C = frame << 16;
                lbl_80371C30[task->_14 + 7]._00->_5C = 0;
                lbl_80371C30[task->_14 + 7]._00->_68 = 1;
                task->_1C = 1;
            }
        } else {
            lbl_80371C30[task->_14 + 6]._00->_54 &= ~2;
            task->_1C = 0;
        }
    } else {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}
