#include "game/rep_28A8.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"
#include "game/rep_540.h"
#include "game/rep_AC8.h"
#include "game/rep_1188.h"
#include "game/rep_1200.h"
#include "game/rep_1E08.h"
#include "game/rep_868.h"
#include "game/game_batter.h"
#include "musyx/musyx.h"
#include "Dolphin/rand.h"

extern struct {
    /* 0x000 */ s32 _000;
    /* 0x004 */ u16 _004;
    /* 0x006 */ u16 _006;
    /* 0x008 */ u8 _008[0xC - 0x8];
    /* 0x00C */ s16 _00C;
    /* 0x00E */ s16 _00E;
    /* 0x010 */ s16 _010;
    /* 0x012 */ s16 _012;
    /* 0x014 */ u8 _014[0x1D1 - 0x14];
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4;
    /* 0x1D5 */ u8 _1D5;
    /* 0x1D6 */ u8 _1D6[0x1D9 - 0x1D6];
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ s8 _1DA;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6;
} g_UnkSimulation_31AC0;

typedef struct {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
    /* 0x008 */ f32 z;
    /* 0x00C */ u8 _00C[0x1C9 - 0xC];
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA[0x1EC - 0x1CA];
    /* 0x1EC */ u8 _1EC;
    /* 0x1ED */ u8 _1ED;
    /* 0x1EE */ u8 _1EE;
    /* 0x1EF */ u8 _1EF[0x20D - 0x1EF];
    /* 0x20D */ u8 _20D;
    /* 0x20E */ u8 _20E[0x268 - 0x20E];
} Unk28A8Fielder; // size: 0x268

extern Unk28A8Fielder g_Fielders[9];

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern u8 lbl_800EFBA4[0x10];
extern s16 lbl_3_data_1899C[4];

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 z;
    /* 0x8 */ f32 radius[2];
} Unk28A8Spawn; // size: 0x10

extern Unk28A8Spawn lbl_3_data_18AC8[];
extern s16 lbl_3_data_18BB8[][3];
extern u8 lbl_803CBC3C[];

extern void fn_3_5A6D4(u8 status);
extern void fn_3_AFD80(u8);
extern void fn_3_59918(int, int);
extern void fn_3_1DD48(void);
extern void fn_3_FBD58(void);
extern void fn_3_FBD70(void);
extern void Set_803cb848(int);
extern int fn_3_6C938(int, int);
extern void changeScene(u8, s16);
extern void fn_3_5B408(void);
// sta_c6.c
extern BOOL fn_3_E5924(void);

s16 lbl_3_data_18C48[10] = { 100, 180, 600, 279, 3, 1, 60, 70, 2, 0 };

// .text:0x000DE744 size:0x44C mapped:0x8071D7D8
void fn_3_DE744(void) {
    return;
}

// .text:0x000DE610 size:0x134 mapped:0x8071D6A4
void fn_3_DE610(void) {
    g_Minigame.panelHitInd = 0;
    if (g_Minigame._19A6 != 0) {
        g_Minigame._19A6--;
        if (g_Pitcher.strikeOutOrWalk == 2 || g_Pitcher.strikeOutOrWalk == 3) {
            g_Minigame._19A6 = 3;
        }
    }
    g_Strikes.outs = 0;
    g_Strikes.storedOuts = 0;
    g_Minigame._19A5 = 1;
    if ((g_Minigame.rosterID != g_Minigame._19C6 || g_Minigame.minigameControlStruct._1C[g_Minigame.rosterID] == 1) &&
        g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns) {
        lbl_3_common_bss_34C90._1D2 = 0;
        fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    } else if (g_Minigame.toyField_turnNumber < g_Minigame.toyField_selectedTurns && g_Minigame.toyField_turnNumber % 10 == 0) {
        fn_3_5A6D4(GAME_STATUS_INNING_TRANSITION);
    } else {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
    }
}

// .text:0x000DE4FC size:0x114 mapped:0x8071D590
void fn_3_DE4FC(void) {
    s32 i;
    s32 j;
    s16 points;
    s32 rank;

    for (i = 0; i < 4; i++) {
        g_Minigame.minigameControlStruct._1C[i] = 0;
        g_Minigame.minigameControlStruct._20[i] = 0;
    }
    for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        points = g_Minigame.miniGameCurrentPoints[i];
        rank = 1;
        for (j = 0; j < g_Minigame.miniGameNumberOfParticipants; j++) {
            if (g_Minigame.miniGameCurrentPoints[j] > points) {
                rank++;
            }
        }
        g_Minigame.minigameControlStruct._1C[i] = rank;
        g_Minigame.minigameControlStruct._20[i] = rank;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameControlStruct._1C[i] > 1) {
            break;
        }
    }
    if (i >= 4 && g_Minigame.miniGameNumberOfParticipants > 1) {
        g_Minigame.challenge_minigame_haven_tWonYetIndicator = 1;
    } else {
        g_Minigame.challenge_minigame_haven_tWonYetIndicator = 0;
    }
}

// .text:0x000DE308 size:0x1F4 mapped:0x8071D39C
void fn_3_DE308(int type) {
    s32 i;

    if (type == 20 || type == 21) {
        g_Minigame.miniGameLatestPoints[g_Minigame.rosterID] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][0];
        g_Minigame.miniGameLatestPoints[g_Minigame.minigamePlayerSelectedOrder] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][1];
        g_Minigame.miniGameLatestPoints[g_Fielders[g_Ball.fielderWBallIndex]._20D] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][2];
    } else {
        g_Minigame.miniGameLatestPoints[g_Minigame.rosterID] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][0];
        g_Minigame.miniGameLatestPoints[g_Minigame.minigamePlayerSelectedOrder] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][1];
        g_Minigame.miniGameLatestPoints[g_Minigame.minigameControlStruct._28[1]] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][2];
        g_Minigame.miniGameLatestPoints[g_Minigame.minigameControlStruct._28[2]] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][2];
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame.miniGameLatestPoints[i] != 0) {
            g_Minigame.minigamePoints_current_Latest[i][0] = g_Minigame.miniGameCurrentPoints[i];
            g_Minigame.minigamePoints_current_Latest[i][1] = g_Minigame.miniGameLatestPoints[i];
        }
    }
}

// .text:0x000DDFA0 size:0x368 mapped:0x8071D034
void fn_3_DDFA0(void) {
    return;
}

// .text:0x000DDF1C size:0x84 mapped:0x8071CFB0
void fn_3_DDF1C(void) {
    fn_3_6EBB4(g_Minigame.minigamePlayerSelectedOrder);
    fn_3_F1DC();
    fn_3_751B4();
    setDefaultInMemBatter();
    fn_3_58870();
    fn_3_1DEB8();
    fn_3_BF1AC();
    Set_803cb848(1);
    fn_3_BF158();
    g_FieldingLogic._0AE = 0;
    g_GameLogic.homeRunWordAnimationCompletedInd = 0;
    g_UnkSimulation_31AC0._5 = 0;
    g_UnkSimulation_31AC0._6 = 4;
}

// .text:0x000DDD60 size:0x1BC mapped:0x8071CDF4
void fn_3_DDD60(void) {
    if (g_Minigame.turnOverStatus == 1) {
        g_Minigame.turnOverStatus = 2;
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[0];
    }
    g_GameLogic.CountdownUntilFade--;
    if (g_Minigame._19A0 && g_GameLogic.CountdownUntilFade < lbl_3_data_1899C[1]) {
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[1];
    }
    if (g_GameLogic.CountdownUntilFade == lbl_3_data_1899C[1] - 10) {
        if (g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns &&
            g_Minigame.minigameControlStruct._1C[g_Minigame.rosterID] == 1) {
            fn_3_59918(13, 0);
        } else if ((u8)g_Minigame.rosterID != g_Minigame._19C6) {
            if (g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns) {
                fn_3_59918(13, 0);
            } else {
                fn_3_59918(5, 0);
            }
        }
    }
    if (g_GameLogic.CountdownUntilFade == 7) {
        changeScene(3, 6);
    }
    if (g_GameLogic.CountdownUntilFade <= 0) {
        fn_3_DD37C();
    }
}

// .text:0x000DD9A4 size:0x3BC mapped:0x8071CA38
void fn_3_DD9A4(void) {
    return;
}

// .text:0x000DD3FC size:0x5A8 mapped:0x8071C490
void fn_3_DD3FC(void) {
    return;
}

// .text:0x000DD37C size:0x80 mapped:0x8071C410
void fn_3_DD37C(void) {
    if (g_Minigame._19CE) {
        fn_3_FBD70();
        fn_3_FBD58();
    }
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    g_GameLogic.hudLoadingRelated = 1;
    fn_3_1DD48();
    if (!g_Minigame.pointsTargetReachedInd) {
        fn_3_2E87C();
        fn_3_5A6D4(GAME_STATUS_DEFAULT);
    } else {
        fn_3_5A6D4(GAME_STATUS_TRANSITION);
    }
}

// .text:0x000DD1A8 size:0x1D4 mapped:0x8071C23C
void fn_3_DD1A8(void) {
    switch (g_GameLogic._125) {
    case 0:
        if (g_Minigame.toyField_turnNumber == 0) {
            s32 i;

            if (random_fn_3_9EE24(100) < lbl_3_data_18C48[7] || g_Minigame._1907 == 4) {
                i = 0;
                do {
                    g_Minigame.rosterID = random_fn_3_9EE24(4);
                } while (++i < 100 && g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.rosterID] != 0);
            } else {
                i = 0;
                do {
                    g_Minigame.rosterID = random_fn_3_9EE24(4);
                } while (++i < 100 && g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.rosterID] == 0);
            }
        }
        changeScene(1, 6);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125 = 1;
        break;
    case 1: {
        BOOL done = FALSE;
        if (g_GameLogic.FrameCountOfCurrentPitch >= lbl_3_data_18C48[2]) {
            done = TRUE;
        } else if (g_GameLogic.FrameCountOfCurrentAtBat_Copy >= lbl_3_data_18C48[1] && fn_3_6C938(1, 0x1100)) {
            done = TRUE;
        }
        if (done) {
            g_GameLogic._125 = 2;
            changeScene(3, 6);
        }
        break;
    }
    case 2:
        if (lbl_8037169C._13) {
            fn_3_FBD70();
            fn_3_FBD58();
            fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
        }
        break;
    }
}

// .text:0x000DD000 size:0x1A8 mapped:0x8071C094
void fn_3_DD000(void) {
    switch (g_GameLogic._125) {
    case 0:
        changeScene(1, 6);
        g_GameLogic._125 = 1;
        break;
    case 1:
        if (g_GameLogic.FrameCountOfCurrentPitch > 1800) {
            g_GameLogic._125 = 2;
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        } else if (g_GameLogic.FrameCountOfCurrentPitch > 300 && fn_3_6C938(1, 0x1100)) {
            g_GameLogic._125 = 2;
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        }
        break;
    case 2:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 30) {
            if (g_Minigame._190A) {
                g_GameLogic._125 = 4;
            } else {
                g_GameLogic._125 = 3;
            }
        }
        break;
    case 3:
        lbl_3_common_bss_34C90._1D1 = 0;
        lbl_3_common_bss_34C90._1D2 = 0;
        fn_3_5A6D4(0x22);
        break;
    case 4:
        changeScene(4, 6);
        if (lbl_8037169C._13) {
            g_GameLogic._125 = 10;
        }
        break;
    case 5:
        if (g_Minigame.challenge_minigame_haven_tWonYetIndicator) {
            g_d_GameSettings._38 = 0;
        } else {
            g_d_GameSettings._38 = g_Minigame.minigameControlStruct._1C[g_d_GameSettings._35];
        }
        g_GameLogic.framesOfExitingToMenu = 1;
        break;
    }
}

// .text:0x000DCF44 size:0xBC mapped:0x8071BFD8
void fn_3_DCF44(void) {
    s32 i;

    for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0 && !g_Minigame.minigameControlStruct.battingHandedness[i] &&
            (g_Controls[g_Minigame.minigameControlStruct.characterIndex[i]].newButtonInput & INPUT_BUTTON_START)) {
            lbl_3_common_bss_34C90._1D5 = 1;
            lbl_3_common_bss_34C90._000 = g_Minigame.minigameControlStruct.characterIndex[i];
            fn_3_AFD80(0);
            fn_3_59918(14, 0);
            break;
        }
    }
}

// .text:0x000DCED0 size:0x74 mapped:0x8071BF64
void fn_3_DCED0(void) {
    if (lbl_3_common_bss_34C90._00C < 0x7FFE) {
        lbl_3_common_bss_34C90._00C++;
    } else {
        lbl_3_common_bss_34C90._00C = 0x7FFF;
    }
    lbl_803CBC3C[0] = 1;
    if (lbl_3_common_bss_34C90._00C > 60) {
        fn_3_AFD80(1);
        fn_3_5A6D4(GAME_STATUS_PAUSED);
    } else {
        fn_3_2EA24();
    }
}

// .text:0x000DCC80 size:0x250 mapped:0x8071BD14
void fn_3_DCC80(void) {
    return;
}

// .text:0x000DCA68 size:0x218 mapped:0x8071BAFC
void fn_3_DCA68(void) {
    return;
}

// .text:0x000DC6E8 size:0x380 mapped:0x8071B77C
void fn_3_DC6E8(void) {
    return;
}

// .text:0x000DC5A4 size:0x144 mapped:0x8071B638
void fn_3_DC5A4(void) {
    int pad;

    if ((pad = fn_3_6C938(1, 0x100)) != 0) {
        lbl_3_common_bss_34C90._000 = pad - 1;
        if (lbl_3_common_bss_34C90._1DA == 2) {
            fn_3_5B408();
            lbl_3_common_bss_34C90._1D2 = 9;
        } else {
            lbl_3_common_bss_34C90._1D2 = 4;
        }
        sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
    } else if (fn_3_6C938(1, 8)) {
        if (lbl_3_common_bss_34C90._1DA != 0) {
            lbl_3_common_bss_34C90._1DA--;
        } else {
            lbl_3_common_bss_34C90._1DA = 2;
        }
        sndFXStart(0x1B7, lbl_800EFBA4[0], 0x3F);
    } else if (fn_3_6C938(1, 4)) {
        lbl_3_common_bss_34C90._1DA++;
        if (lbl_3_common_bss_34C90._1DA >= 3) {
            lbl_3_common_bss_34C90._1DA = 0;
        }
        sndFXStart(0x1B7, lbl_800EFBA4[0], 0x3F);
    }
}

// .text:0x000DC380 size:0x224 mapped:0x8071B414
void fn_3_DC380(void) {
    return;
}

// .text:0x000DC240 size:0x140 mapped:0x8071B2D4
void fn_3_DC240(void) {
    g_Minigame.toyFieldBallStateResult2 = g_Minigame.toyFieldBallStateResult;
    if (fn_3_E5924()) {
        if (g_Minigame._19CF == 0) {
            g_Minigame.toyFieldBallStateResult2 = 12;
        }
        if (g_Minigame._19CF > 60) {
            g_Minigame._19CE = 1;
        } else if (g_Minigame._19CF < 0xFE) {
            g_Minigame._19CF++;
        } else {
            g_Minigame._19CF = 0xFF;
        }
    } else if (g_Minigame.toyFieldBallStateResult2 == 2 || g_Ball.maybebuntOn2Strikes) {
        if (!g_Ball.maybebuntOn2Strikes) {
            fn_3_59918(1, 0);
        }
        g_Minigame._19C6 = g_Minigame.minigamePlayerSelectedOrder;
        if (g_Ball.fielderWBallIndex >= 0) {
            g_Minigame._19C6 = g_Fielders[g_Ball.fielderWBallIndex]._20D;
        }
    } else if (g_Minigame.toyFieldBallStateResult2 == 1) {
        fn_3_A0F0();
    } else if (g_Minigame.toyFieldBallStateResult2 == 6) {
        fn_3_59918(15, 0);
    }
}

// .text:0x000DA834 size:0x1A0C mapped:0x807198C8
void fn_3_DA834(void) {
    return;
}

// .text:0x000DA640 size:0x1F4 mapped:0x807196D4
void fn_3_DA640(s32 count, s32 idx) {
    f32 x;
    f32 z;
    s32 i;
    f32 radius;
    f32 dist;
    int ang;
    f32 speed;

    g_Minigame._1939 = count;
    radius = lbl_3_data_18AC8[idx].radius[0];
    g_Minigame.panelHitInd = 1;
    g_Minigame.wallBall_coinsVisibleFrameCounter[0] = 0;
    if (count >= 20) {
        radius = lbl_3_data_18AC8[idx].radius[1];
    }
    for (i = 0; i < count; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 1;
        g_Minigame.wallBall_coinCoordinates[i].y = 0.8f;
        dist = 0.001f * (rand() % (int)(1000.0f * radius));
        ang = fn_3_9FE6C_normalizeAngle(rand() % 4096);
        getComponentsFromSAng(ang, &x, &z);
        g_Minigame.wallBall_coinCoordinates[i].x = x * dist + lbl_3_data_18AC8[idx].x;
        g_Minigame.wallBall_coinCoordinates[i].z = z * dist + lbl_3_data_18AC8[idx].z;
        speed = RandomF32_Game_Range(0.0f, 0.03f);
        g_Minigame.wallBall_coinVelocity[i].x = x * speed;
        g_Minigame.wallBall_coinVelocity[i].z = z * speed;
        g_Minigame.wallBall_coinVelocity[i].y = RandomF32_Game_Range(0.08f, 0.12f);
    }
}

// .text:0x000D9EA0 size:0x7A0 mapped:0x80718F34
void fn_3_D9EA0(void) {
    return;
}
