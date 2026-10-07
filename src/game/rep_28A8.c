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
#include "game/rep_1CB8.h"
#include "game/rep_3310.h"
#include "game/rep_3880.h"
#include "game/rep_3CE0.h"
#include "game/rep_1038.h"
#include "game/sta_c6.h"
#include "game/game_batter.h"
#include "musyx/musyx.h"
#include "Dolphin/rand.h"

extern struct {
    /* 0x000 */ s32 _000;
    /* 0x004 */ u16 _004;
    /* 0x006 */ u16 _006;
    /* 0x008 */ u16 _008;
    /* 0x00A */ u8 _00A[0xC - 0xA];
    /* 0x00C */ s16 _00C;
    /* 0x00E */ s16 _00E;
    /* 0x010 */ s16 _010;
    /* 0x012 */ s16 _012;
    /* 0x014 */ u8 _014[0x1D0 - 0x14];
    /* 0x1D0 */ u8 _1D0;
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4;
    /* 0x1D5 */ u8 _1D5;
    /* 0x1D6 */ u8 _1D6[0x1D9 - 0x1D6];
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ s8 _1DA;
    /* 0x1DB */ u8 _1DB[0x220 - 0x1DB];
    /* 0x220 */ u8 _220;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6;
} g_UnkSimulation_31AC0;

extern struct {
    /* 0x00 */ u8 _00[0xC5];
    /* 0xC5 */ u8 _C5;
} g_Scores;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} g_RunningLogic;

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

extern struct {
    /* 0x0000 */ u8 _0000[0x307A];
    /* 0x307A */ u8 _307A;
} lbl_8036E548;

extern u8 lbl_800EFBA4[0x10];
extern struct {
    /* 0x000 */ u8 _000[0x398];
    /* 0x398 */ u8 _398;
} lbl_800EF808;

extern s16 lbl_3_data_49DC[44];
extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];
extern s16 lbl_3_data_1899C[4];
extern u8 lbl_3_data_189AC[9];
extern s16 lbl_3_data_189B8[6];

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 z;
    /* 0x8 */ f32 radius[2];
} Unk28A8Spawn; // size: 0x10

extern Unk28A8Spawn lbl_3_data_18AC8[10];
extern f32 lbl_3_data_18B88[5];
extern f32 lbl_3_data_18B9C[5];
extern s16 lbl_3_data_18BB0[2][2];
extern u8 lbl_3_data_88DC;
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
extern int fn_3_5B380(u16 buttons);
extern void fn_3_107E80(void);
extern void fn_8004CC18(void);
extern void fn_3_DF8D4(void);
extern void ballPhysica(void);
extern void fn_3_D8CD0(void);
extern void fn_3_D9868(void);
extern void fn_3_D9A30(void);
// sta_c6.c
extern BOOL fn_3_E5924(void);

static inline void playStadiumSound(s32 sound) {
    SND_VOICEID voice;
    u8 vol;
    s32 stadium = g_d_GameSettings.StadiumID;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][0];
    } else {
        vol = lbl_3_data_8404[stadium][sound][0];
    }
    voice = sndFXStartEx(lbl_3_data_81DC[stadium] + sound, vol, 63, 0);
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][1];
    } else {
        vol = lbl_3_data_8404[stadium][sound][1];
    }
    sndFXCtrl(voice, 91, vol);
}

s16 lbl_3_data_18C48[10] = { 100, 180, 600, 279, 3, 1, 60, 70, 2, 0 };

// .text:0x000DE744 size:0x44C mapped:0x8071D7D8
void fn_3_DE744(void) {
    s32 i;

    fn_3_DDF1C();
    fn_3_6C0E0();
    g_Runners[0].positionStored.x = g_Runners[0].position.x;
    g_Runners[0].positionStored.y = g_Runners[0].position.y;
    g_Runners[0].positionStored.z = g_Runners[0].position.z;
    g_Runners[0].unused_AIRelated = 1;
    g_Runners[0].battingHand = g_Batter.batterHand;
    g_Runners[0].batterStayInBattersBoxReason = 1;
    g_Runners[0].position.x = g_Batter.batterPos.x;
    g_Runners[0].position.y = 0.0f;
    g_Runners[0].position.z = g_Batter.batterPos.z;
    g_Runners[0].runningAngle = 3.1415927f;
    g_GameLogic.CountdownUntilFade = 10000;
    g_Strikes.storedOuts = g_Strikes.outs;
    g_Strikes.outs = 0;
    g_Strikes.storedOuts = 0;
    g_Ball.totalFramesAtPlay = 0;
    lbl_3_common_bss_34C90._1D5 = 0;
    g_Scores._C5 = 0;
    g_Minigame.turnOverStatus = 0;
    g_Minigame.pointsTargetReachedInd = 0;
    g_Minigame.toyFieldBallStateResult2 = 0;
    g_Minigame.framesSincePanelHit = 0;
    g_Minigame._1921 = 0;
    g_Minigame._1914_arr[0] = 1;
    g_Minigame.toyFieldStateInd_collisionRelated = 0;
    g_Minigame._1939 = 0;
    g_Minigame.panelHitInd = 0;
    g_Minigame._19A0 = 0;
    g_Minigame._1934 = 0;
    g_Minigame._18BA = 0;
    g_Minigame._19A3 = 0;
    g_Minigame.TF_framesSinceHittingPanel = 0;
    g_Minigame.TF_ballDespawnedInd = 0;
    g_Minigame._190E = 0;
    g_Minigame.maybeTFCollisionResultState = 0;
    g_Minigame.toyFieldBallStateResult = 0;
    g_Minigame._19BC = 0;
    g_Minigame._19D0 = 0;
    g_Minigame._19CD = 0;
    g_Minigame._19CF = 0;
    if (g_Minigame._19CE == 3) {
        fn_3_E67F4();
    }
    g_Minigame._19CE = 0;
    for (i = 0; i < 4; i++) {
        g_Minigame.minigamePoints_current_Latest[i][0] = g_Minigame.miniGameCurrentPoints[i];
        g_Minigame.minigamePoints_current_Latest[i][1] = 0;
        g_Minigame._1935[i] = -1;
    }
    for (i = 0; i < 100; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame._1914_arr[i]) {
            g_Minigame._191C[i] = i;
        } else {
            g_Minigame._191C[i] = -1;
        }
        g_Minigame._1918[i] = g_Minigame._1914_arr[i];
    }
    g_FieldingLogic._10E = 0;
    g_FieldingLogic._0EE = 0;
    g_FieldingLogic._10F = 0;
    g_FieldingLogic._110 = 0;
    g_FieldingLogic._128 = 0;
    g_FieldingLogic._129 = 0;
    g_FieldingLogic._0E4 = 0;
    g_RunningLogic._13 = 0;
    if (g_GameLogic.pre_PostMiniGameInd) {
        g_GameLogic.minigameLastTurnSuccessInd = 1;
        g_GameLogic.hudElementLoadingInd = 1;
    } else {
        g_GameLogic.minigameLastTurnSuccessInd = 0;
    }
    g_GameLogic.pre_PostMiniGameInd = 0;
    changeScene(1, 6);
    fn_3_5A6D4(GAME_STATUS_AT_BAT);
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
    if (g_Pitcher.pitchTotalTimeCounter <= 0 && !lbl_3_common_bss_34C90._1D5) {
        fn_3_DCF44();
    }
    if (lbl_3_common_bss_34C90._1D5) {
        fn_3_DCED0();
    } else {
        fn_3_75560();
        atBat_batter();
        fn_3_2EA24();
        if (g_Minigame.toyFieldBallStateResult2 == 0 && g_Pitcher.strikeOutOrWalk != 0) {
            if (g_Pitcher.strikeOutOrWalk == 1) {
                g_Minigame.toyFieldBallStateResult2 = 2;
            } else if (g_Pitcher.strikeOutOrWalk == 2) {
                g_Minigame.toyFieldBallStateResult2 = 7;
            } else {
                g_Minigame.toyFieldBallStateResult2 = 8;
            }
        }
        if (g_Minigame.toyFieldBallStateResult2) {
            fn_3_DA834();
        }
        if (g_Minigame.turnOverStatus) {
            fn_3_DDD60();
        }
    }
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
    s16 frames = g_Minigame.TF_framesSinceHittingPanel;

    if (frames != 0 && g_Ball.fielderWBallIndex < 0) {
        if (frames < lbl_3_data_18C48[6]) {
            g_Minigame.TF_framesSinceHittingPanel = frames + 1;
        } else if (!g_Minigame.TF_ballDespawnedInd) {
            g_Minigame.TF_ballDespawnedInd = 1;
            playStadiumSound(0x15);
        }
    }
    ballPhysica();
    fn_3_2F484();
    if (g_Minigame._19CF) {
        if (!g_Minigame._19CE) {
            fn_3_DC240();
        }
    } else if (g_Minigame.toyFieldBallStateResult && !g_Minigame.toyFieldBallStateResult2) {
        fn_3_DC240();
    } else if (!g_Minigame.toyFieldBallStateResult2) {
        fn_3_DC380();
    }
    if (g_Minigame.toyFieldBallStateResult2) {
        fn_3_DA834();
    }
    if (g_Minigame.turnOverStatus) {
        fn_3_DD3FC();
    }
}

// .text:0x000DD3FC size:0x5A8 mapped:0x8071C490
// The target reaches lbl_3_data_188E8 to lbl_3_data_18C48 from one pool base, so that data
// belongs in this file (outside the unit's .data split). Defined here, the code is identical
// and only the pool base's relocation name differs.
void fn_3_DD3FC(void) {
    s32 i;

    if (g_Minigame.turnOverStatus == 1) {
        g_Minigame.turnOverStatus = 2;
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[0];
        if (g_Minigame.toyFieldBallStateResult2 == 1 && !g_Ball.maybebuntOn2Strikes) {
            g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[2];
        }
    }
    g_GameLogic.CountdownUntilFade--;
    if (g_Minigame._19A0 && !g_Minigame._19CE && g_GameLogic.CountdownUntilFade < lbl_3_data_1899C[1]) {
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[1];
    }
    if (g_Minigame._1939 && g_GameLogic.CountdownUntilFade < lbl_3_data_1899C[1]) {
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[1];
    }
    if (g_Minigame._19CE && g_Minigame._19CE < 3) {
        if (g_GameLogic.CountdownUntilFade <= lbl_3_data_1899C[1] - 10) {
            g_GameLogic.CountdownUntilFade++;
        }
        if (g_Minigame._19CE == 1) {
            fn_3_DE308(12);
            g_Minigame._19BA = 0;
            g_Minigame._19CE = 2;
            for (i = 0; i < 4; i++) {
                if (g_Minigame._1918[i]) {
                    g_Minigame._1914_arr[i] = 0;
                }
            }
            if (lbl_800EF808._398 == 1) {
                playStadiumSound(0x1A);
            }
        }
        if (g_Minigame._19BA < 0x7FFE) {
            g_Minigame._19BA++;
        } else {
            g_Minigame._19BA = 0x7FFF;
        }
        if (g_Minigame._19BA > lbl_3_data_18C48[3]) {
            g_Minigame._19CE = 3;
        }
    }
    if (!g_Minigame.TF_ballDespawnedInd && g_Ball.fielderWBallIndex < 0 && !g_Ball.deadBallReason && g_Ball.AtBat_ContactResult >= 0 &&
        g_GameLogic.CountdownUntilFade <= lbl_3_data_1899C[1] - 10 + lbl_3_data_49DC[11]) {
        g_GameLogic.CountdownUntilFade++;
    }
    if (g_GameLogic.CountdownUntilFade == lbl_3_data_1899C[1] - 10) {
        if (g_Minigame._19CD == 1 || g_Minigame._19CD == 2 || (g_Minigame._19CD != 3 && g_Minigame._1921)) {
            g_GameLogic.CountdownUntilFade++;
        } else if (g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns &&
                   g_Minigame.minigameControlStruct._1C[g_Minigame.rosterID] == 1) {
            fn_3_59918(13, 0);
        } else if ((u8)g_Minigame.rosterID != g_Minigame._19C6) {
            if (g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns) {
                fn_3_59918(13, 0);
            } else {
                fn_3_59918(5, 0);
            }
        }
        if (g_Minigame._19BC < 0x7FFE) {
            g_Minigame._19BC++;
        } else {
            g_Minigame._19BC = 0x7FFF;
        }
    }
    if (g_GameLogic.CountdownUntilFade == 7) {
        changeScene(3, 6);
    }
    if (g_GameLogic.CountdownUntilFade <= 0) {
        fn_3_DD37C();
    }
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

static inline BOOL isSceneSkipped(void) {
    BOOL done = FALSE;

    if (g_GameLogic.FrameCountOfCurrentPitch >= lbl_3_data_18C48[2]) {
        done = TRUE;
    } else if (g_GameLogic.FrameCountOfCurrentAtBat_Copy >= lbl_3_data_18C48[1] && fn_3_6C938(1, 0x1100)) {
        done = TRUE;
    }
    return done;
}

// .text:0x000DD1A8 size:0x1D4 mapped:0x8071C23C
void fn_3_DD1A8(void) {
    s32 i;

    switch (g_GameLogic._125) {
    case 0:
        if (g_Minigame.toyField_turnNumber == 0) {
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
    case 1:
        if (isSceneSkipped()) {
            g_GameLogic._125 = 2;
            changeScene(3, 6);
        }
        break;
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
    if (lbl_3_common_bss_34C90._00C < 0x7FFE) {
        lbl_3_common_bss_34C90._00C++;
    } else {
        lbl_3_common_bss_34C90._00C = 0x7FFF;
    }
    if (lbl_3_common_bss_34C90._012 < 0x7FFE) {
        lbl_3_common_bss_34C90._012++;
    } else {
        lbl_3_common_bss_34C90._012 = 0x7FFF;
    }
    lbl_803CBC3C[0] = 1;
    lbl_3_common_bss_34C90._004 = g_Controls[lbl_3_common_bss_34C90._000].buttonInput;
    lbl_3_common_bss_34C90._006 = g_Controls[lbl_3_common_bss_34C90._000].newButtonInput;
    lbl_3_common_bss_34C90._008 = g_Controls[lbl_3_common_bss_34C90._000]._08;
    switch (lbl_3_common_bss_34C90._1D2) {
    case 0:
        lbl_3_common_bss_34C90._1DA = 0;
        lbl_3_common_bss_34C90._1D5 = 0;
        lbl_3_common_bss_34C90._1D0 = 0x11;
        lbl_3_common_bss_34C90._1D2 = 1;
        break;
    case 1:
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D2 = 2;
        break;
    case 2:
        if (lbl_3_common_bss_34C90._012 >= 20) {
            lbl_3_common_bss_34C90._1D2 = 3;
        }
        break;
    case 3:
        fn_3_DCA68();
        lbl_3_common_bss_34C90._012 = 0;
        break;
    case 4:
        lbl_3_common_bss_34C90._1D9 = 1;
        lbl_3_common_bss_34C90._1D2 = 5;
        break;
    case 5:
        if (lbl_3_common_bss_34C90._1D9 == 3) {
            fn_3_5A6D4(GAME_STATUS_AT_BAT);
        }
        break;
    case 6:
        lbl_3_common_bss_34C90._1D9 = 1;
        lbl_3_common_bss_34C90._1D2 = 7;
        break;
    case 7:
        if (lbl_3_common_bss_34C90._1D9 == 3) {
            lbl_3_common_bss_34C90._220 = 2;
            lbl_3_common_bss_34C90._1D2 = 0;
            fn_3_5A6D4(GAME_STATUS_HOW_TO_PLAY_SCREEN);
        }
        break;
    case 8:
        fn_3_107E80();
        break;
    case 9:
        switch (fn_3_5B380(lbl_3_common_bss_34C90._006)) {
        case 1:
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            lbl_3_common_bss_34C90._1D2 = 10;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 3;
            break;
        }
        break;
    case 10:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
            changeScene(4, 6);
        }
        if (lbl_8037169C._13) {
            lbl_3_common_bss_34C90._1D9 = 2;
            g_d_GameSettings._13 = 1;
            fn_8004CC18();
            g_GameLogic.framesOfExitingToMenu = 1;
        }
        break;
    }
}

// .text:0x000DCA68 size:0x218 mapped:0x8071BAFC
void fn_3_DCA68(void) {
    if (lbl_3_common_bss_34C90._006 & PAD_BUTTON_START) {
        lbl_3_common_bss_34C90._1D2 = 4;
        sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
    } else if (lbl_3_common_bss_34C90._006 & PAD_BUTTON_A) {
        if (lbl_3_common_bss_34C90._1DA == 0) {
            lbl_3_common_bss_34C90._1D2 = 4;
            sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
        } else if (lbl_3_common_bss_34C90._1DA == 1) {
            lbl_3_common_bss_34C90._1D2 = 8;
            lbl_3_common_bss_34C90._1D4 = 0;
            sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
        } else if (lbl_3_common_bss_34C90._1DA == 2) {
            lbl_3_common_bss_34C90._1D2 = 6;
            sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
        } else if (lbl_3_common_bss_34C90._1DA == 3) {
            fn_3_5B408();
            lbl_3_common_bss_34C90._1D2 = 9;
            sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
        }
    } else if (lbl_3_common_bss_34C90._006 & PAD_BUTTON_B) {
        if (lbl_3_common_bss_34C90._1DA != 0) {
            lbl_3_common_bss_34C90._1DA = 0;
        } else {
            lbl_3_common_bss_34C90._1D2 = 4;
        }
        sndFXStart(0x1B9, lbl_800EFBA4[2], 0x3F);
    } else if (lbl_3_common_bss_34C90._008 & PAD_BUTTON_UP) {
        if (lbl_3_common_bss_34C90._1DA > 0) {
            lbl_3_common_bss_34C90._1DA--;
        } else {
            lbl_3_common_bss_34C90._1DA = 3;
        }
        sndFXStart(0x1B7, lbl_800EFBA4[0], 0x3F);
    } else if (lbl_3_common_bss_34C90._008 & PAD_BUTTON_DOWN) {
        lbl_3_common_bss_34C90._1DA++;
        if (lbl_3_common_bss_34C90._1DA >= 4) {
            lbl_3_common_bss_34C90._1DA = 0;
        }
        sndFXStart(0x1B7, lbl_800EFBA4[0], 0x3F);
    }
}

// .text:0x000DC6E8 size:0x380 mapped:0x8071B77C
void fn_3_DC6E8(void) {
    BOOL started;

    if (lbl_3_common_bss_34C90._012 < 0x7FFE) {
        lbl_3_common_bss_34C90._012++;
    } else {
        lbl_3_common_bss_34C90._012 = 0x7FFF;
    }
    switch (lbl_3_common_bss_34C90._1D2) {
    case 0:
        lbl_3_common_bss_34C90._1DA = 0;
        lbl_3_common_bss_34C90._1D0 = 0x12;
        lbl_3_common_bss_34C90._1D2 = 1;
        break;
    case 1:
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D2 = 2;
        break;
    case 2:
        if (lbl_3_common_bss_34C90._012 >= 20) {
            lbl_3_common_bss_34C90._1D2 = 3;
        }
        break;
    case 3:
        fn_3_DC5A4();
        lbl_3_common_bss_34C90._012 = 0;
        break;
    case 4:
        if (lbl_3_common_bss_34C90._012 >= 20) {
            changeScene(3, 6);
        }
        if (lbl_8037169C._13) {
            lbl_3_common_bss_34C90._1D2 = 5;
        }
        break;
    case 5:
        lbl_8036E548._307A = 0;
        lbl_3_common_bss_34C90._1D9 = 2;
        started = FALSE;
        if (lbl_3_common_bss_34C90._1DA == 0) {
            fn_3_5A6D4(GAME_STATUS_GAME_START_MOVIE);
            g_Minigame._1A38 = 1;
            started = TRUE;
        } else if (lbl_3_common_bss_34C90._1DA == 1) {
            g_Minigame._19DF = 30;
            fn_3_5A6D4(GAME_STATUS_TOY_STADIUM_LOAD);
            started = TRUE;
        }
        if (started) {
            fn_3_DF8D4();
            fn_3_15F998();
            fn_3_147DFC();
            if (lbl_3_common_bss_34C90._1DA == 1) {
                fn_3_11CF84();
            }
        }
        break;
    case 9:
        switch (fn_3_5B380(g_Controls[lbl_3_common_bss_34C90._000].newButtonInput)) {
        case 1:
            fn_3_15F998();
            fn_3_147DFC();
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            lbl_3_common_bss_34C90._1D2 = 10;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 3;
            break;
        }
        break;
    case 10:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
            changeScene(4, 6);
        }
        if (lbl_8037169C._13) {
            lbl_3_common_bss_34C90._1D9 = 2;
            fn_8004CC18();
            g_GameLogic.framesOfExitingToMenu = 1;
        }
        break;
    }
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
    s32 code;
    s16 result;
    Unk28A8Fielder* fielder;

    if (g_Ball.framesSinceLastBounce == 0 && g_Ball.ballBounceState != 3) {
        code = g_Ball.collisionCode;
        if (code >= 0x80) {
            code -= 0x80;
        }
        if (code >= 0x70 && code < 0x79) {
            g_Minigame.maybeTFCollisionResultState = lbl_3_data_189AC[code - 0x70];
        }
    }
    result = g_Ball.AtBat_ContactResult;
    if (result == -1) {
        g_Minigame.toyFieldBallStateResult = 1;
    } else if (g_Minigame.toyFieldStateInd_collisionRelated) {
        g_Minigame.toyFieldBallStateResult = lbl_3_data_189AC[g_Minigame.toyFieldStateInd_collisionRelated - 0x70];
    } else if (g_Ball.deadBallReason) {
        if (g_Ball.deadBallReason == 1) {
            g_Minigame.toyFieldBallStateResult = 6;
        } else if (g_Ball.deadBallReason == 3) {
            g_Minigame.toyFieldBallStateResult = 4;
        } else {
            g_Minigame.toyFieldBallStateResult = 1;
        }
        g_Minigame.turnOverStatus = 1;
    } else if (result != 0) {
        if (g_Ball.ballState == 1) {
            fielder = &g_Fielders[g_Ball.fielderWBallIndex];
            if (fielder->_1EE || fielder->_1EC) {
                return;
            }
        } else if (!(g_Ball.ballVelocity < 0.003f || g_Ball.groundRuleDoubleInd || g_Ball.ballStoppingCode1ReallySlow2Stopped == 2)) {
            return;
        }
        if (result == 3) {
            g_Minigame.toyFieldBallStateResult = 2;
        } else {
            if (g_Minigame.maybeTFCollisionResultState == 0) {
                if (fn_3_B7E10(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
                    g_Minigame.toyFieldBallStateResult = 1;
                } else {
                    g_Minigame.toyFieldBallStateResult = 2;
                }
            } else {
                g_Minigame.toyFieldBallStateResult = g_Minigame.maybeTFCollisionResultState;
            }
            g_Minigame.lastKnownBallPosX = g_Ball.AtBat_Contact_BallPos.x;
            g_Minigame.lastKnownBallPosZ = g_Ball.AtBat_Contact_BallPos.z;
            g_Minigame.TF_framesSinceHittingPanel = 1;
        }
    }
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
// The target reaches lbl_3_data_188E8 to lbl_3_data_18C48 from one pool base, so that data
// belongs in this file (outside the unit's .data split). Defined here, the code is identical
// and only the pool base's relocation name differs.
void fn_3_DA834(void) {
    s32 i;
    s32 j;
    s32 n;

    if (g_Minigame.framesSincePanelHit < 0x7FFE) {
        g_Minigame.framesSincePanelHit++;
    } else {
        g_Minigame.framesSincePanelHit = 0x7FFF;
    }
    if (g_Minigame.framesSincePanelHit <= 1) {
        if (g_Minigame.toyFieldBallStateResult2 == 1 && !g_Ball.maybebuntOn2Strikes) {
            g_Minigame.turnOverStatus = 1;
            fn_3_DE308(11);
            return;
        }
        g_Minigame.panelHitInd = 1;
        if (g_Minigame.toyFieldBallStateResult2 >= 1 && g_Minigame.toyFieldBallStateResult2 <= 8) {
            g_Minigame.turnOverStatus = 1;
            switch (g_Minigame.toyFieldBallStateResult2) {
            case 1:
                fn_3_DE308(22);
                break;
            case 2:
                if (g_Pitcher.strikeOutOrWalk == 1 || g_Ball.maybebuntOn2Strikes) {
                    fn_3_DE308(22);
                } else if (g_Minigame.toyFieldStateInd_collisionRelated == 0x71) {
                    fn_3_DE308(9);
                } else {
                    fn_3_DE308(10);
                }
                break;
            case 3:
                fn_3_DE308(0);
                break;
            case 4:
                fn_3_DE308(1);
                break;
            case 5:
                fn_3_DE308(2);
                break;
            case 6:
                if (g_Ball.deadBallReason == 1) {
                    fn_3_DE308(4);
                } else {
                    fn_3_DE308(3);
                }
                break;
            case 7:
                fn_3_DE308(23);
                break;
            case 8:
                fn_3_DE308(23);
                break;
            }
            if (g_Minigame.toyFieldBallStateResult2 >= 3 && g_Minigame.toyFieldBallStateResult2 <= 6) {
                playStadiumSound(0);
            }
            if (g_Minigame.toyFieldBallStateResult2 == 2 || g_Ball.maybebuntOn2Strikes) {
                if (g_Ball.fielderWBallIndex >= 0) {
                    g_Minigame._19C6 = g_Fielders[g_Ball.fielderWBallIndex]._20D;
                } else {
                    g_Minigame._19C6 = g_Minigame.minigamePlayerSelectedOrder;
                }
            }
        } else if (g_Minigame.toyFieldBallStateResult2 == 11) {
            fn_3_D9A30();
            fn_3_D9868();
            g_Minigame.TF_framesSinceHittingPanel = 1;
        } else if (g_Minigame.toyFieldBallStateResult2 == 9 || g_Minigame.toyFieldBallStateResult2 == 10) {
            if (g_Minigame.lastKnownBallPosX < 0.0f) {
                fn_3_DA640(30, 6);
            } else {
                fn_3_DA640(30, 4);
            }
            g_Minigame.TF_framesSinceHittingPanel = 1;
            g_Minigame._199E = 0;
        } else {
            g_Minigame.turnOverStatus = 1;
        }
        if (g_Minigame.toyFieldBallStateResult2 >= 3 && g_Minigame.toyFieldBallStateResult2 <= 6) {
            n = g_Minigame.toyFieldBallStateResult2 - 2;
            for (j = 0; j < n; j++) {
                if (g_Minigame._1914_arr[3]) {
                    g_Minigame._1921++;
                }
                for (i = 3; i > 0; i--) {
                    g_Minigame._1914_arr[i] = g_Minigame._1914_arr[i - 1];
                    g_Minigame._1914_arr[i - 1] = 0;
                }
            }
            for (i = 0; i < 4; i++) {
                if (g_Minigame._191C[i] >= 0) {
                    g_Minigame._191C[i] += n;
                    if (g_Minigame._191C[i] >= 4) {
                        g_Minigame._191C[i] = 4;
                    }
                }
            }
        }
        if (g_Minigame.toyFieldBallStateResult2 == 7 || g_Minigame.toyFieldBallStateResult2 == 8) {
            if (g_Minigame._1914_arr[3]) {
                g_Minigame._1921++;
            }
            for (n = 1; n < 4; n++) {
                if (!g_Minigame._1914_arr[n]) {
                    break;
                }
            }
            for (i = n; i >= 1; i--) {
                g_Minigame._1914_arr[i] = g_Minigame._1914_arr[i - 1];
                g_Minigame._1914_arr[i - 1] = 0;
            }
            for (i = 0; i < 4; i++) {
                if (g_Minigame._191C[i] < 0) {
                    break;
                }
                g_Minigame._191C[i]++;
                if (g_Minigame._191C[i] >= 4) {
                    g_Minigame._191C[i] = 4;
                }
            }
        }
        for (i = 0; i < 4; i++) {
            if (g_Ball.fielderWBallIndex >= 0 && g_Minigame.minigameFielderIndex[i] == g_Ball.fielderWBallIndex) {
                if (g_Ball.AtBat_ContactResult == 3) {
                    fn_3_DE308(20);
                } else {
                    fn_3_DE308(21);
                }
                break;
            }
        }
        g_Minigame.pointsTargetReachedInd = 1;
    } else {
        if (g_Minigame.toyFieldBallStateResult2 == 11) {
            if (g_Minigame._1934 == 0) {
                if (g_Minigame._18B8 < 0x7FFE) {
                    g_Minigame._18B8++;
                } else {
                    g_Minigame._18B8 = 0x7FFF;
                }
                for (i = 0; i < 3; i++) {
                    if (g_Minigame._1927[i] == 0) {
                        if (g_Minigame._18B8 > lbl_3_data_189B8[i]) {
                            g_Minigame._1927[i] = 1;
                        }
                    } else if (g_Minigame._1927[i] == 1) {
                        if (i == 0) {
                            if (g_Minigame._18B8 > lbl_3_data_189B8[3]) {
                                g_Minigame._1927[i] = 2;
                            }
                        } else if (i == 2) {
                            if (g_Minigame._1930[i] == 3) {
                                g_Minigame._1927[i] = 2;
                            }
                        } else if (g_Minigame._1930[i] >= 2) {
                            g_Minigame._1927[i] = 2;
                        }
                    }
                }
            } else if (g_Minigame._1934 == 1) {
            } else if (g_Minigame._1934 == 2) {
                fn_3_D8CD0();
                g_Minigame._1934 = 3;
            } else {
                if (g_Minigame._192D == 6) {
                    g_Minigame._19A6 = 3;
                    if (g_Minigame._18BA == 1) {
                        fn_3_E8AC8();
                    }
                }
                if (g_Minigame._18BA < 0x7FFE) {
                    g_Minigame._18BA++;
                } else {
                    g_Minigame._18BA = 0x7FFF;
                }
            }
        }
        if (g_Minigame.toyFieldBallStateResult2 == 9 || g_Minigame.toyFieldBallStateResult2 == 10) {
            fn_3_D9EA0();
        }
    }
}

// .text:0x000DA640 size:0x1F4 mapped:0x807196D4
void fn_3_DA640(s32 count, s32 idx) {
    f32 x;
    f32 z;
    s32 i;
    f32 radius;
    f32 dist;
    int ang;
    int r;
    f32 speed;

    g_Minigame._1939 = count;
    g_Minigame.panelHitInd = 1;
    radius = lbl_3_data_18AC8[idx].radius[0];
    g_Minigame.wallBall_coinsVisibleFrameCounter[0] = 0;
    if (count >= 20) {
        radius = lbl_3_data_18AC8[idx].radius[1];
    }
    for (i = 0; i < count; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 1;
        g_Minigame.wallBall_coinCoordinates[i].y = 0.8f;
        r = rand();
        dist = 0.001f * (r % (int)(1000.0f * radius));
        ang = rand() % 4096;
        ang = fn_3_9FE6C_normalizeAngle(ang);
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
// The target reaches lbl_3_data_188E8 to lbl_3_data_18C48 from one pool base, so that data
// belongs in this file (outside the unit's .data split). Defined here, the code is identical
// and only the pool base's relocation name differs.
void fn_3_D9EA0(void) {
    s32 i;
    Unk28A8Fielder* fielder;
    f32 dx;
    f32 dz;
    f32 dist0;
    f32 dist1;
    f32 dist2;
    s32 closest;
    f32 dx2;
    f32 dz2;

    if (g_Minigame._1939) {
        if (g_Minigame.wallBall_coinsVisibleFrameCounter[0] < 0x7FFE) {
            g_Minigame.wallBall_coinsVisibleFrameCounter[0]++;
        } else {
            g_Minigame.wallBall_coinsVisibleFrameCounter[0] = 0x7FFF;
        }
        for (i = 0; i < 100; i++) {
            if (g_Minigame.wallBall_coinsVisibleInd[i]) {
                if (g_Minigame.wallBall_coinsVisibleFrameCounter[0] > lbl_3_data_18BB0[g_Minigame._199E][0]) {
                    g_Minigame.wallBall_coinsVisibleInd[i] = 0;
                } else {
                    g_Minigame.wallBall_coinVelocity[i].y -= lbl_3_data_18B9C[0];
                    g_Minigame.wallBall_coinVelocity[i].x *= lbl_3_data_18B9C[1];
                    g_Minigame.wallBall_coinVelocity[i].y *= lbl_3_data_18B9C[1];
                    g_Minigame.wallBall_coinVelocity[i].z *= lbl_3_data_18B9C[1];
                    g_Minigame.wallBall_coinCoordinates[i].x += g_Minigame.wallBall_coinVelocity[i].x;
                    g_Minigame.wallBall_coinCoordinates[i].y += g_Minigame.wallBall_coinVelocity[i].y;
                    g_Minigame.wallBall_coinCoordinates[i].z += g_Minigame.wallBall_coinVelocity[i].z;
                    if (g_Minigame.wallBall_coinCoordinates[i].y <= lbl_3_data_18B9C[3]) {
                        g_Minigame.wallBall_coinCoordinates[i].y = lbl_3_data_18B9C[3];
                        g_Minigame.wallBall_coinVelocity[i].y = -g_Minigame.wallBall_coinVelocity[i].y;
                        g_Minigame.wallBall_coinVelocity[i].x *= lbl_3_data_18B9C[2];
                        g_Minigame.wallBall_coinVelocity[i].y *= lbl_3_data_18B9C[2];
                        g_Minigame.wallBall_coinVelocity[i].z *= lbl_3_data_18B9C[2];
                    }
                }
            }
        }
        for (i = 0; i < 100; i++) {
            if (g_Minigame.wallBall_coinsVisibleInd[i]) {
                dist1 = dist2 = 999.9f;
                fielder = &g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[0]]];
                dx = g_Minigame.wallBall_coinCoordinates[i].x - fielder->x;
                dz = g_Minigame.wallBall_coinCoordinates[i].z - fielder->z;
                dx2 = dx * dx;
                dz2 = dz * dz;
                dist0 = dolsqrtf2(dx2 + dz2);
                if (g_Minigame.minigameControlStruct._28[1] >= 0) {
                    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[1]]];
                    dx = g_Minigame.wallBall_coinCoordinates[i].x - fielder->x;
                    dz = g_Minigame.wallBall_coinCoordinates[i].z - fielder->z;
                    dx2 = dx * dx;
                    dz2 = dz * dz;
                    dist1 = dolsqrtf2(dx2 + dz2);
                }
                if (g_Minigame.minigameControlStruct._28[2] >= 0) {
                    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[2]]];
                    dx = g_Minigame.wallBall_coinCoordinates[i].x - fielder->x;
                    dz = g_Minigame.wallBall_coinCoordinates[i].z - fielder->z;
                    dx2 = dx * dx;
                    dz2 = dz * dz;
                    dist2 = dolsqrtf2(dx2 + dz2);
                }
                if (dist0 < dist2) {
                    if (dist0 < dist1) {
                        dist1 = dist0;
                        closest = g_Minigame.minigameControlStruct._28[0];
                    } else {
                        closest = g_Minigame.minigameControlStruct._28[1];
                    }
                } else if (dist1 < dist2) {
                    closest = g_Minigame.minigameControlStruct._28[1];
                } else {
                    dist1 = dist2;
                    closest = g_Minigame.minigameControlStruct._28[2];
                }
                if (dist1 < lbl_3_data_18B88[g_Fielders[g_Minigame.minigameFielderIndex[closest]]._1C9]) {
                    g_Minigame.wallBall_coinsVisibleInd[i] = 0;
                    g_Minigame.miniGameCurrentPoints[closest] += lbl_3_data_18C48[8] * g_Minigame.toyField_pointMultiplier;
                    if (--g_Minigame._1939 == 0 && !g_Minigame.turnOverStatus) {
                        g_Minigame.turnOverStatus = 1;
                    }
                    if (!lbl_3_common_bss_34C58._30) {
                        playStadiumSound(0xC);
                        lbl_3_common_bss_34C58._30 = lbl_3_data_88DC;
                    }
                }
            }
        }
        if (g_Minigame.wallBall_coinsVisibleFrameCounter[0] > lbl_3_data_18BB0[g_Minigame._199E][0]) {
            if (!g_Minigame.turnOverStatus) {
                g_Minigame.turnOverStatus = 1;
            }
            if (g_Minigame._1939) {
                g_Minigame.miniGameLatestPoints[g_Minigame.rosterID] = g_Minigame._1939 * g_Minigame.toyField_pointMultiplier;
                g_Minigame.minigamePoints_current_Latest[g_Minigame.rosterID][0] = g_Minigame.miniGameCurrentPoints[g_Minigame.rosterID];
                g_Minigame.minigamePoints_current_Latest[g_Minigame.rosterID][1] = g_Minigame.miniGameLatestPoints[g_Minigame.rosterID];
                g_Minigame._1939 = 0;
            }
        }
    }
}
