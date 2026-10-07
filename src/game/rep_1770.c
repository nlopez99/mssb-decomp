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
    /* 0x1C */ u16 _1C[2];
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
    /* 0x69 */ u8 _69;
    /* 0x6A */ u8 _6A[0x72 - 0x6A];
    /* 0x72 */ s16 _72;
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
    /* 0xA8 */ u8 _A8;
    /* 0xA9 */ u8 _A9[0xAE - 0xA9];
    /* 0xAE */ u8 _AE;
    /* 0xAF */ u8 _AF;
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
    /* 0x1D3 */ u8 _1D3[0x1D5 - 0x1D3];
    /* 0x1D5 */ u8 _1D5;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x0000 */ u8 _0000[0x489B];
    /* 0x489B */ u8 _489B[2][9];
} lbl_8034E9A0;

extern s16 lbl_3_data_5F3C[4];
extern u8 lbl_3_data_F430[12][2];
extern UnkSpriteRef1770 lbl_80371C30[];
extern void* lbl_803CC1B8;

// Only this unit reads these; they lie outside its splits.txt ranges.
extern UnkSpriteDesc1770 lbl_3_data_C22C[9];
extern UnkSpriteDesc1770 lbl_3_data_C34C[17];
extern UnkSpriteDesc1770 lbl_3_data_C56C[2][51];
extern u16 lbl_3_data_D22C[4];
extern u16 lbl_3_data_D234[14];
extern u8 lbl_3_data_D250[5];
extern UnkSpriteDesc1770 lbl_3_data_D258[9];
extern UnkSpriteDesc1770 lbl_3_data_D378[12];
extern UnkSpriteDesc1770 lbl_3_data_D4F8[6];

u8 lbl_3_data_F4A4[0x2C] = {
    0, 0, 0, 0, 2, 5, 4, 3, 8, 3, 4, 5, 2, 6, 0, 1, 8, 6, 7, 1, 2, 0,
    7, 4, 4, 3, 1, 2, 5, 1, 2, 4, 6, 8, 7, 6, 8, 5, 3, 3, 5, 7, 4, 6,
};
u8 lbl_3_data_F4D0[16] = { 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

extern void fn_80034CEC(UnkTask1770* task);
extern void fn_80034E20(UnkTask1770* task, UnkSpriteDesc1770* desc);
extern void fn_8003649C(UnkTask1770* task, s32, s32, s32, s32);
extern void fn_800363D8(UnkTask1770* task, s32, s32, s32, u16);
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
    task->_1C[0] = task->_1C[1] = task->_20 = 9;
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
            if (task->_1C[0] == g_Strikes.strikes) {
                continue;
            }
            if (g_Strikes.strikes >= i + 1) {
                type = 0;
            }
        } else if (i < 5) {
            if (task->_1C[1] == g_Strikes.balls) {
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
    task->_1C[0] = g_Strikes.strikes;
    task->_1C[1] = g_Strikes.balls;
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
    task->_1C[0] = g_Scores._04[0][0];
    task->_1C[1] = g_Scores._04[1][0];
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
    if (task->_1C[0] != g_Scores._04[0][0] || task->_1C[1] != g_Scores._04[1][0]) {
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
    UnkTask1770* task = lbl_803CC1B8;
    s32 next;
    s32 i;

    fn_80034E20(task, lbl_3_data_C56C[g_Batter.batterHand]);
    lbl_80371C30[task->_14 + 9]._00->_5C = inMemRoster[g_GameLogic.teamFielding][g_Pitcher.rosterID].stats.CharID << 16;
    lbl_80371C30[task->_14 + 10]._00->_5C = inMemRoster[g_GameLogic.teamBatting][g_Batter.rosterID].stats.CharID << 16;
    next = g_GameLogic.currentBatterPerTeam[g_GameLogic.homeTeamBattingInd_fieldingTeam] + 1;
    if (next > 9) {
        next = 1;
    }
    next = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.homeTeamBattingInd_fieldingTeam][next][0];
    lbl_80371C30[task->_14 + 6]._00->_5C = inMemRoster[g_GameLogic.teamBatting][next].stats.CharID << 16;
    fn_800363D8(task, 13, 1, 0x2A, lbl_3_data_D22C[inMemRoster[g_GameLogic.teamFielding][g_Pitcher.rosterID].stats.CharacterClass]);
    fn_800363D8(task, 14, 1, 0x2A, lbl_3_data_D22C[inMemRoster[g_GameLogic.teamBatting][g_Batter.rosterID].stats.CharacterClass]);

    if (g_GameLogic._13E[g_GameLogic.teamFielding] != 0) {
        lbl_80371C30[task->_14 + 15]._00->_5C = (g_GameLogic.teams[g_GameLogic.teamFielding] + 4) << 16;
    } else {
        lbl_80371C30[task->_14 + 15]._00->_5C = g_GameLogic.teams[g_GameLogic.teamFielding] << 16;
    }
    if (g_GameLogic._13E[g_GameLogic.teamBatting] != 0) {
        lbl_80371C30[task->_14 + 16]._00->_5C = (g_GameLogic.teams[g_GameLogic.teamBatting] + 4) << 16;
    } else {
        lbl_80371C30[task->_14 + 16]._00->_5C = g_GameLogic.teams[g_GameLogic.teamBatting] << 16;
    }

    for (i = 0; i < 5; i++) {
        if (g_GameLogic.TeamStars[g_GameLogic.teamFielding] > i) {
            lbl_80371C30[task->_14 + 0x22 + i]._00->_5C = 3 << 16;
        }
        if (g_GameLogic.TeamStars[g_GameLogic.teamBatting] > i) {
            lbl_80371C30[task->_14 + 0x27 + i]._00->_5C = 3 << 16;
        }
    }

    if (gameInitOptions.starSkillsSetting == 0 && g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
        fn_800363D8(task, 3, 1, 0x22, lbl_3_data_D234[0]);
        fn_800363D8(task, 4, 1, 0x22, lbl_3_data_D234[0]);
        lbl_80371C30[task->_14 + 3]._00->_58 = (lbl_80371C30[task->_14 + 3]._00->_58 & 0xFF) | 0xBEBEBE00;
        lbl_80371C30[task->_14 + 4]._00->_58 = (lbl_80371C30[task->_14 + 4]._00->_58 & 0xFF) | 0xBEBEBE00;
        for (i = 24; i <= 43; i++) {
            lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
        }
    } else {
        fn_800363D8(task, 3, 1, 0x22, lbl_3_data_D234[inMemRoster[g_GameLogic.teamFielding][g_Pitcher.rosterID].stats.CaptainStarHitPitch]);
        fn_800363D8(task, 4, 1, 0x22, lbl_3_data_D234[inMemRoster[g_GameLogic.teamBatting][g_Batter.rosterID].stats.CaptainStarHitPitch]);
    }

    if (g_GameLogic.IsStarChance != 0) {
        lbl_80371C30[task->_14 + 21]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 17]._00->_54 &= ~2;
    } else {
        lbl_80371C30[task->_14 + 22]._00->_54 &= ~2;
        if (g_Batter.chemLinksOnBase == 0) {
            lbl_80371C30[task->_14 + 17]._00->_54 &= ~2;
        }
        if (lbl_3_common_bss_32724._AE == 0 || lbl_3_common_bss_32724._AF != g_Pitcher.rosterID) {
            lbl_80371C30[task->_14 + 21]._00->_54 &= ~2;
        }
    }

    lbl_80371C30[task->_14 + 46]._00->_5C = 30 << 16;
    lbl_80371C30[task->_14 + 47]._00->_5C = 30 << 16;
    if (!g_d_GameSettings.exhibitionMatchInd) {
        if (starMissionCompletionTracker._43D6[g_Pitcher.charID] != 0 && g_GameLogic._13E[g_GameLogic.teamFielding] == 0) {
            lbl_80371C30[task->_14 + 48]._00->_54 |= 2;
        }
        if (starMissionCompletionTracker._43D6[g_Batter.charID] != 0 && g_GameLogic._13E[g_GameLogic.teamBatting] == 0) {
            lbl_80371C30[task->_14 + 49]._00->_54 |= 2;
        }
    } else {
        if (lbl_8034E9A0._489B[g_GameLogic.teamFielding][g_Pitcher.rosterID] != 0) {
            lbl_80371C30[task->_14 + 48]._00->_54 |= 2;
        }
        if (lbl_8034E9A0._489B[g_GameLogic.teamBatting][g_Batter.rosterID] != 0) {
            lbl_80371C30[task->_14 + 49]._00->_54 |= 2;
        }
    }

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice.practiceLevel != 7) {
        lbl_80371C30[task->_14 + 20]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 5]._00->_54 &= ~2;
    }

    task->_18 = 0;
    task->_1C[0] = g_GameLogic.TeamStars[0];
    task->_1C[1] = g_GameLogic.TeamStars[1];
    task->_20 = 0;
    lbl_3_common_bss_32724._A8 = 1;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_99E10;
}

static inline BOOL isAnimDone(UnkSprite1770* sprite) {
    return sprite->_69 == 2 ? TRUE : FALSE;
}

// .text:0x00099E10 size:0xA94 mapped:0x806D8EA4
void fn_3_99E10(void) {
    UnkTask1770* task = lbl_803CC1B8;
    s32 gained = -1;
    s32 lost = -1;
    s32 earned = -1;
    s32 i;
    s32 idx;
    s32 frame2;
    s32 frame;
    s32 stars;
    s32 t;

    task->_18++;
    if (lbl_3_common_bss_32724._96 != 0 || g_GameLogic.hudLoadingRelated != 0 || g_GameLogic.gameStatus == 3 ||
        g_GameLogic.gameStatus == 14 || g_GameLogic.secondaryGameMode == 10) {
        goto remove;
    }
    if (g_GameLogic.IsStarChance == 0 || lbl_3_common_bss_34C90._1D5 != 0) {
        if (lbl_3_common_bss_32724._A7 == 0) {
            goto remove;
        }
        if (lbl_3_common_bss_32724._A7 < 0xFF) {
            for (i = 0; i < 50; i++) {
                lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & 0xFFFFFF00) | lbl_3_common_bss_32724._A7;
            }
        } else {
            for (i = 0; i < 50; i++) {
                lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & 0xFFFFFF00) | lbl_3_common_bss_32724._A6;
            }
        }
    }
    if (lbl_3_common_bss_34C90._1D5 != 0) {
        if (lbl_3_common_bss_32724._A7 == 0) {
            goto remove;
        }
        if (lbl_3_common_bss_32724._A7 < 0xFF) {
            for (i = 0; i < 50; i++) {
                lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & 0xFFFFFF00) | lbl_3_common_bss_32724._A7;
            }
        }
    }

    for (t = 0; t < 2; t++) {
        for (i = 0; i < 5; i++) {
            if (t == g_GameLogic.teamFielding) {
                idx = i + 0x22;
            } else {
                idx = i + 0x27;
            }
            stars = g_GameLogic.TeamStars[t];
            frame = lbl_80371C30[task->_14 + idx]._00->_5C >> 16;
            if (g_Batter.moonShotInd != 0 && g_Ball.framesSinceHit == 0 && t == g_GameLogic.teamBatting) {
                for (stars = 0; stars < 5; stars++) {
                    if (lbl_3_data_D250[stars] > g_GameLogic.PauseSimulationFrameCount) {
                        break;
                    }
                }
                earned = stars;
            }
            if (stars > i) {
                if (task->_1C[t] <= i) {
                    if (frame == 0) {
                        frame2 = lbl_80371C30[task->_14 + 44]._00->_5C >> 16;
                        if (frame2 == 0) {
                            gained = t;
                        } else if (frame2 == 25) {
                            lbl_80371C30[task->_14 + idx]._00->_5C = 4 << 16;
                            lbl_80371C30[task->_14 + idx]._00->_68 = 1;
                        }
                    } else if (frame >= 20) {
                        lbl_80371C30[task->_14 + idx]._00->_5C = 3 << 16;
                        lbl_80371C30[task->_14 + idx]._00->_68 = 0;
                        task->_1C[t]++;
                    }
                } else if (frame >= 3) {
                    lbl_80371C30[task->_14 + idx]._00->_68 = 0;
                }
            } else if (stars < task->_1C[t] && frame >= 3) {
                lbl_80371C30[task->_14 + idx]._00->_68 = 4;
                lost = t;
                task->_1C[t]--;
                if (earned >= 0 && earned != 4) {
                    lost = -1;
                }
            }
        }
    }

    if (gained >= 0) {
        lbl_80371C30[task->_14 + 44]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 44]._00->_68 = 1;
        lbl_80371C30[task->_14 + 45]._00->_68 = 1;
        if (g_Batter.batterHand == 0) {
            if (gained == g_GameLogic.teamFielding) {
                lbl_80371C30[task->_14 + 45]._00->_72 = 1;
            } else {
                lbl_80371C30[task->_14 + 45]._00->_72 = 0;
            }
        } else {
            if (gained == g_GameLogic.teamFielding) {
                lbl_80371C30[task->_14 + 45]._00->_72 = 3;
            } else {
                lbl_80371C30[task->_14 + 45]._00->_72 = 2;
            }
        }
    } else if (isAnimDone(lbl_80371C30[task->_14 + 44]._00)) {
        lbl_80371C30[task->_14 + 44]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 44]._00->_68 = 0;
        lbl_80371C30[task->_14 + 44]._00->_5C = 0;
        lbl_80371C30[task->_14 + 45]._00->_68 = 0;
        lbl_80371C30[task->_14 + 45]._00->_5C = 0;
        lbl_80371C30[task->_14 + 44]._00->_54 &= ~2;
    }

    if (lost >= 0) {
        lbl_80371C30[task->_14 + 46]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 46]._00->_68 = 4;
        lbl_80371C30[task->_14 + 47]._00->_68 = 4;
        if (g_Batter.batterHand == 0) {
            if (lost == g_GameLogic.teamFielding) {
                lbl_80371C30[task->_14 + 47]._00->_72 = 1;
            } else {
                lbl_80371C30[task->_14 + 47]._00->_72 = 0;
            }
        } else {
            if (lost == g_GameLogic.teamFielding) {
                lbl_80371C30[task->_14 + 47]._00->_72 = 3;
            } else {
                lbl_80371C30[task->_14 + 47]._00->_72 = 2;
            }
        }
    } else if ((lbl_80371C30[task->_14 + 46]._00->_5C >> 16) == 0) {
        lbl_80371C30[task->_14 + 46]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 46]._00->_68 = 0;
        lbl_80371C30[task->_14 + 46]._00->_5C = 30 << 16;
        lbl_80371C30[task->_14 + 47]._00->_68 = 0;
        lbl_80371C30[task->_14 + 47]._00->_5C = 30 << 16;
        lbl_80371C30[task->_14 + 46]._00->_54 &= ~2;
    }
    return;

remove:
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
    lbl_3_common_bss_32724._A8 = 0;
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
    task->_1C[0] = 0;
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
        if (task->_1C[0] == 0) {
            lbl_80371C30[task->_14 + 6]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 6]._00->_5C = frame << 16;
            lbl_80371C30[task->_14 + 7]._00->_5C = 0;
            lbl_80371C30[task->_14 + 7]._00->_68 = 1;
            task->_1C[0] = 1;
        }
    } else {
        lbl_80371C30[task->_14 + 6]._00->_54 &= ~2;
        task->_1C[0] = 0;
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
    task->_1C[0] = 0;
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
            if (task->_1C[0] == 0) {
                lbl_80371C30[task->_14 + 6]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 6]._00->_5C = frame << 16;
                lbl_80371C30[task->_14 + 7]._00->_5C = 0;
                lbl_80371C30[task->_14 + 7]._00->_68 = 1;
                task->_1C[0] = 1;
            }
        } else {
            lbl_80371C30[task->_14 + 6]._00->_54 &= ~2;
            task->_1C[0] = 0;
        }
    } else {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}
