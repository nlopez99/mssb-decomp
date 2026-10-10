#include "game/rep_34B0.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "game/rep_3880.h"
#include "game/rep_1188.h"
#include "game/rep_540.h"
#include "game/rep_AC8.h"
#include "game/rep_13B8.h"
#include "game/rep_28A8.h"
#include "game/game_batter.h"
#include "game/m_sound.h"
#include "game/rep_1200.h"
#include "game/rep_1E08.h"
#include "game/rep_31A0.h"
#include "game/rep_CC8.h"
#include "game/rep_D18.h"
#include "game/rep_3090.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "string.h"
#include "game/rep_3D50.h"

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0xAA - 0x4];
    /* 0xAA */ u8 _AA;
} g_Scores;

extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6;
} g_UnkSimulation_31AC0;

extern u8 lbl_3_common_bss_32234[0x8];

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

extern struct {
    /* 0x00 */ u8 _00[0xB6];
    /* 0xB6 */ u8 _B6;
    /* 0xB7 */ u8 _B7;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_803CBC3C[];

extern s16 lbl_3_data_18C48[10];
extern u8 lbl_3_data_2127C[][5];
extern VecXYZ lbl_3_data_216BC[15];
extern f32 lbl_3_data_21770[6];
extern s16 lbl_3_data_21788[4];
extern s16 lbl_3_data_21790[4];
extern u8 lbl_3_data_21798[12];
extern s16 lbl_3_data_217A4[12];

typedef struct {
    /* 0x0 */ s8 idx;
    /* 0x1 */ s8 _1;
    /* 0x2 */ s16 _2;
} UnkBarrelTarget34B0; // size: 0x4

typedef struct UnkBarrelCell34B0 {
    /* 0x0 */ u8 state;
    /* 0x1 */ u8 colour;
} UnkBarrelCell34B0; // size: 0x2

extern void changeScene(u8, s16);
extern void fn_800246D4(int (*compare)(const void*, const void*), void* src, void* dst, int size, int count);
extern int fn_3_6C938(int, int);
extern void fn_8004C108(VecXYZ* pos, int arg1);


// .text:0x001324E8 size:0x9F4 mapped:0x8077157C
void fn_3_1324E8(void) {
    switch (g_GameLogic.gameStatus) {
    case GAME_STATUS_LOAD_GAME:
        fn_3_1320BC();
        break;
    case GAME_STATUS_TRANSITION_MINIGAME_TO_BATTING:
        fn_3_13207C();
        break;
    case GAME_STATUS_TRANSITION_TO_MINIGAME_START:
        fn_3_131FFC();
        break;
    case GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY:
        fn_3_131EC4();
        break;
    case GAME_STATUS_DEFAULT:
        fn_3_131C88();
        break;
    case GAME_STATUS_AT_BAT:
        fn_3_130C6C();
        break;
    case GAME_STATUS_LIVE_BALL:
        fn_3_1307D0();
        break;
    case GAME_STATUS_TRANSITION:
        fn_3_131540();
        break;
    case GAME_STATUS_MINIGAME_NEW_ROUND:
        fn_3_13128C();
        break;
    case GAME_STATUS_INNING_TRANSITION:
        fn_3_13119C();
        break;
    case GAME_STATUS_TRANSITION_MINIGAME_POSTGAME:
        fn_3_1312D4();
        break;
    }
}

// .text:0x001323CC size:0x11C mapped:0x80771460
void fn_3_1323CC(void) {
    u32 i;

    for (i = 0; i < 15; i++) {
        if (g_Minigame.barrels[i].barrelState == 1) {
            fn_3_12F9D4(i);
        }
    }
}

// .text:0x001320BC size:0x310 mapped:0x80771150
void fn_3_1320BC(void) {
    int i;

    if (g_GameLogic._125 == 0) {
        fn_3_59A90();
        g_GameLogic.secondaryGameMode = SECONDARY_GAME_MODE_BARREL_BATTER;
        for (i = 0; i < 4; i++) {
            g_Minigame.miniGameCurrentPoints[i] = 0;
            g_Minigame.miniGameLatestPoints[i] = 0;
            g_Minigame.minigamePoints_current_Latest[i][0] = 0;
            g_Minigame.minigamePoints_current_Latest[i][1] = 0;
            g_Minigame.minigameControlStruct._28[i] = -1;
            g_Minigame.minigameFielderIndex[i] = -1;
            g_Minigame._18FC[i] = -1;
            g_Minigame._1900[i] = -1;
            g_Minigame.minigameControlStruct._24[i] = 1;
        }
        g_Scores._00 = 0;
        g_Minigame.pointsReqToWin_challenge = 0;
        g_Minigame._1A37 = 0;
        g_Minigame.minigamePlayerSelectedOrder = -1;
        g_Minigame.rosterID = -1;
        g_Minigame._17C0 = 0;
        g_Minigame.bB_bombBarrelHitInd = 0;
        g_Minigame.bB_bombBarrelID = -1;
        if (!g_Minigame.multiPlayerInd) {
            g_Scores._AA = 1;
            for (i = 0; i < 4; i++) {
                g_Minigame.minigameControlStruct.aIStrength[i] = lbl_3_data_2127C[g_Minigame.GameMode_MiniGame][g_Minigame.soloMinigameDifficulty];
            }
            if (g_Minigame.soloMinigameDifficulty <= MINIGAME_DIFFICULTY_MULTIPLAYER_CHALLENGE_HARD) {
                g_Minigame.pointsReqToWin_challenge = lbl_3_data_21790[g_Minigame.soloMinigameDifficulty];
            }
        } else {
            if (g_Minigame._1A3C) {
                for (i = 0; i < 4; i++) {
                    g_Minigame.minigameControlStruct.aIStrength[i] = lbl_3_data_2127C[7][0];
                }
            }
            g_Scores._AA = lbl_3_data_21798[5];
        }
        fn_3_12FE84();
        g_Minigame.turnNumberWithinRound = 0;
        g_Minigame.barrelBatter_scoreCalculatedInd = 0;
        g_Minigame.barrelBatterChargeMeter = 0;
        g_GameLogic._125++;
    } else {
        fn_3_5A6D4(GAME_STATUS_GAME_START_MOVIE);
    }
}

// .text:0x0013207C size:0x40 mapped:0x80771110
void fn_3_13207C(void) {
    sndFXStart(0x1BD, lbl_800EFBA4[6], 0x3F);
    fn_3_5A6D4(GAME_STATUS_TRANSITION_TO_MINIGAME_START);
}

// .text:0x00131FFC size:0x80 mapped:0x80771090
void fn_3_131FFC(void) {
    g_Scores._00++;
    g_Minigame.turnNumberWithinRound = 0;
    if (!g_Minigame.multiPlayerInd) {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
    } else {
        fn_3_10F550(4, 0);
        if (g_Scores._00 == 1) {
            fn_3_10AD48();
        }
        fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
    }
}

// .text:0x00131EC4 size:0x138 mapped:0x80770F58
void fn_3_131EC4(void) {
    switch (g_GameLogic._125) {
    case 0:
        g_Minigame.rosterID = g_Minigame.minigameControlStruct._14[g_Minigame.turnNumberWithinRound];
        g_GameLogic.pre_PostMiniGameInd = 1;
        g_Minigame.miniGameTurnCounter = 0;
        g_Minigame.pointsTargetReachedInd = 0;
        if (!g_Minigame.multiPlayerInd) {
            g_Minigame.bB_pitchesRemainingInTurn = lbl_3_data_21798[g_Minigame.soloMinigameDifficulty];
        } else {
            g_Minigame.bB_pitchesRemainingInTurn = lbl_3_data_21798[4];
        }
        fn_3_F578();
        fn_3_753E8(FALSE);
        fn_3_6EBB4(-1);
        setBatterContactConstants();
        setInMemBatterConstants(g_Minigame.rosterID);
        lbl_803CBC3C[2] = 0;
        g_GameLogic._125++;
        break;
    case 1:
        if (someAnimationIndFunction()) {
            lbl_3_common_bss_32234[1] = 1;
            g_GameLogic._125++;
        }
        break;
    default:
        lbl_3_common_bss_32724._B6 = 1;
        fn_3_5A6D4(GAME_STATUS_DEFAULT);
        break;
    }
}

// .text:0x00131C88 size:0x23C mapped:0x80770D1C
void fn_3_131C88(void) {
    fn_3_131114();
    fn_3_12FD6C();
    g_Minigame._18A0 = 0;
    g_Minigame.turnOverStatus = 0;
    g_Minigame.barrelBatter_scoreCalculatedInd = 0;
    g_Minigame.barrelBatter_hitBarrelID = -1;
    g_Minigame.barrelBatter_barrelsHit = 0;
    g_Minigame.bB_bombBarrelHitInd = 0;
    g_Ball.totalFramesAtPlay = 0;
    g_Ball.framesSinceHit = -1;
    g_Batter.swingInd = 0;
    g_Batter.framesSinceStartOfSwing = 0;
    g_Pitcher.windupCountdownUntilBallReleased = lbl_3_data_217A4[7];
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

// .text:0x00131540 size:0x748 mapped:0x807705D4
void fn_3_131540(void) {
    switch (g_GameLogic._125) {
    case 0:
        fn_3_12FD6C();
        g_Minigame.turnNumberWithinRound++;
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125++;
        break;
    case 1:
        if (g_Minigame._1A37 == 1) {
            if (g_GameLogic.FrameCountOfCurrentAtBat_Copy >= lbl_3_data_217A4[3]) {
                g_GameLogic._125++;
            }
        } else if (g_GameLogic.FrameCountOfCurrentAtBat_Copy >= lbl_3_data_217A4[2]) {
            g_GameLogic._125++;
        }
        break;
    case 2:
        changeScene(3, 6);
        g_GameLogic._125++;
        break;
    case 3:
        if (lbl_8037169C._13) {
            if (g_Minigame.multiPlayerInd) {
                if (g_Minigame.turnNumberWithinRound < g_Minigame.miniGameNumberOfParticipants) {
                    fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
                } else {
                    fn_3_5A6D4(GAME_STATUS_MINIGAME_NEW_ROUND);
                }
            } else {
                fn_3_DE4FC();
                fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
                fn_3_12FE84();
                fn_3_12FD6C();
            }
            fn_3_14CA00();
            lbl_3_common_bss_32724._B7 = 1;
        }
        break;
    }
    fn_3_12FAC4();
}

// .text:0x001312D4 size:0x26C mapped:0x80770368
void fn_3_1312D4(void) {
    fn_3_DE4FC();
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    fn_3_12FE84();
    fn_3_12FD6C();
}

// .text:0x0013128C size:0x48 mapped:0x80770320
void fn_3_13128C(void) {
    if (g_Scores._00 >= g_Scores._AA) {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_MINIGAME_POSTGAME);
    } else {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_TO_MINIGAME_START);
    }
}

// .text:0x0013119C size:0xF0 mapped:0x80770230
void fn_3_13119C(void) {
    switch (g_GameLogic._125) {
    case 0:
        changeScene(1, 6);
        g_GameLogic._125 = 1;
        break;
    case 1:
        if (g_GameLogic.FrameCountOfCurrentPitch >= lbl_3_data_18C48[2] ||
            (g_GameLogic.FrameCountOfCurrentPitch >= lbl_3_data_18C48[1] && fn_3_6C938(1, 0x1100))) {
            changeScene(3, 6);
            g_GameLogic._125 = 2;
        }
        break;
    case 2:
        if (lbl_8037169C._13) {
            fn_3_FBD70();
            fn_3_FBD58();
            g_GameLogic._125 = 3;
        }
        break;
    case 3:
        fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
        break;
    }
}

// .text:0x00131114 size:0x88 mapped:0x807701A8
void fn_3_131114(void) {
    setInMemBatterConstants(g_Minigame.rosterID);
    fn_3_F1DC();
    fn_3_751B4();
    setDefaultInMemBatter();
    fn_3_8913C();
    fn_3_58870();
    memset(g_Minigame._1D7C, 0, 0x78);
    fn_3_BF1AC();
    fn_3_BF158();
    g_FieldingLogic._0AE = 0;
    g_UnkSimulation_31AC0._5 = 0;
    g_UnkSimulation_31AC0._6 = 4;
}

// Not in the target as a function: the value parameter gives the target's `mr r3,r4`, as in
// rep_31F0.c.
static inline void setCpuInputFlags(u8 value) {
    s8 i = 0;
    do {
        g_Minigame._1DBC[i] = value;
    } while (++i < 4);
}

// .text:0x00130C6C size:0x4A8 mapped:0x8076FD00
// 98.14%: the target keeps setCpuInputFlags' &g_Minigame in r25 and walks the barrels from it,
// with a separate r31 for the rosterID base; here the walk starts from that base.
void fn_3_130C6C(void) {
    if (g_Minigame.turnOverStatus == 0) {
        if (fn_3_108854()) {
            return;
        }
        if (g_Minigame.miniGameTurnCounter != 0 || g_GameLogic.FrameCountOfCurrentPitch >= lbl_3_data_217A4[8]) {
            fn_3_75560();
        }
        fn_3_12DB80();
        atBat_batter();
        setCpuInputFlags(0);
        fn_3_8A958();
        fn_3_12FAC4();
    }
    fn_3_130ACC();
}

// .text:0x00130ACC size:0x1A0 mapped:0x8076FB60
void fn_3_130ACC(void) {
    if (g_Minigame.turnOverStatus == 0) {
        if (g_Pitcher.pitcherActionState == 4) {
            if (g_Minigame.bB_pitchesRemainingInTurn == 0) {
                g_Minigame.turnOverStatus = 1;
                g_Minigame.pointsTargetReachedInd = 2;
            }
            g_Minigame.bB_bombBarrelHitInd = 0;
            g_Minigame.bB_bombBarrelID = -1;
        }
        return;
    }
    if (g_Minigame.turnOverStatus == 1) {
        g_Minigame.turnOverStatus = 2;
        g_GameLogic.CountdownUntilFade = lbl_3_data_217A4[0];
    }
    g_GameLogic.CountdownUntilFade--;
    if (g_Minigame.pointsTargetReachedInd) {
        if (g_GameLogic.CountdownUntilFade <= 0) {
            fn_3_130A80();
        }
    } else if (g_GameLogic.CountdownUntilFade <= 0) {
        fn_3_5A6D4(GAME_STATUS_DEFAULT);
    }
    if (g_Minigame.pointsTargetReachedInd &&
        (!g_Minigame.multiPlayerInd ||
         (g_Minigame.multiPlayerInd && g_Minigame.turnNumberWithinRound + 1 >= g_Minigame.miniGameNumberOfParticipants &&
          g_Scores._00 >= g_Scores._AA)) &&
        !g_Minigame._1A37 && g_GameLogic.CountdownUntilFade == 1) {
        sndFXStart(0x1BE, lbl_800EFBA4[7], 0x3F);
    }
}

// .text:0x00130A80 size:0x4C mapped:0x8076FB14
void fn_3_130A80(void) {
    g_Minigame.bB_bombBarrelID = -1;
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    g_GameLogic.hudLoadingRelated = 1;
    fn_3_5A6D4(GAME_STATUS_TRANSITION);
}

// .text:0x001307D0 size:0x2B0 mapped:0x8076F864
void fn_3_1307D0(void) {
    ballPhysica();
    fn_3_12FAC4();
    fn_3_130288();
}

// .text:0x00130288 size:0x548 mapped:0x8076F31C
void fn_3_130288(void) {
    if (g_Minigame.turnOverStatus == 0 && g_Ball.framesSinceHit >= lbl_3_data_217A4[4]) {
        g_Minigame.turnOverStatus = 1;
        if (!g_Minigame.multiPlayerInd && g_Minigame.soloMinigameDifficulty <= MINIGAME_DIFFICULTY_MULTIPLAYER_CHALLENGE_HARD &&
            g_Minigame.miniGameCurrentPoints[g_Minigame.rosterID] >= g_Minigame.pointsReqToWin_challenge) {
            g_Minigame.pointsTargetReachedInd = 2;
            g_Minigame._1A37 = 1;
            g_Minigame.challenge_minigame_haven_tWonYetIndicator = 0;
            fn_3_10F550(1, lbl_3_data_217A4[10]);
        }
        if (g_Minigame.bB_bombBarrelHitInd) {
            g_Minigame.bB_pitchesRemainingInTurn += lbl_3_data_21798[6 + g_Minigame.multiPlayerInd];
        }
        if (g_Minigame.bB_pitchesRemainingInTurn == 0) {
            g_Minigame.pointsTargetReachedInd = 2;
        }
    }
    if (g_Minigame.turnOverStatus == 0) {
        return;
    }
    if (g_Minigame.turnOverStatus == 1) {
        g_Minigame.turnOverStatus = 2;
        g_GameLogic.CountdownUntilFade = lbl_3_data_217A4[1];
    }
    g_GameLogic.CountdownUntilFade--;
    if (g_GameLogic.CountdownUntilFade <= 0 && fn_3_12ED80()) {
        fn_3_12FFD4();
    }
    if (g_Minigame.pointsTargetReachedInd &&
        (!g_Minigame.multiPlayerInd ||
         (g_Minigame.multiPlayerInd && g_Minigame.turnNumberWithinRound + 1 >= g_Minigame.miniGameNumberOfParticipants &&
          g_Scores._00 >= g_Scores._AA)) &&
        !g_Minigame._1A37 && g_GameLogic.CountdownUntilFade == 1) {
        sndFXStart(0x1BE, lbl_800EFBA4[7], 0x3F);
    }
}

// .text:0x0012FFD4 size:0x2B4 mapped:0x8076F068
void fn_3_12FFD4(void) {
    g_Minigame.bB_bombBarrelID = -1;
    fn_3_12EB10();
    fn_3_12E8FC();
    if (g_Minigame.pointsTargetReachedInd) {
        fn_3_5A6D4(GAME_STATUS_TRANSITION);
    } else {
        fn_3_5A6D4(GAME_STATUS_DEFAULT);
    }
}

// .text:0x0012FE84 size:0x150 mapped:0x8076EF18
void fn_3_12FE84(void) {
    int i;

    for (i = 0; i < 15; i++) {
        g_Minigame.barrels[i].barrelState = 1;
        g_Minigame.barrels[i].animationCounter = 0;
        g_Minigame.barrels[i].replacingBarrelInd = 0;
        g_Minigame.barrels[i].desiredPos.x = lbl_3_data_216BC[i].x;
        g_Minigame.barrels[i].desiredPos.y = lbl_3_data_216BC[i].y;
        g_Minigame.barrels[i].desiredPos.z = lbl_3_data_216BC[i].z;
        g_Minigame.barrels[i].currentPos.x = lbl_3_data_216BC[i].x;
        g_Minigame.barrels[i].currentPos.y = lbl_3_data_216BC[i].y;
        g_Minigame.barrels[i].currentPos.z = lbl_3_data_216BC[i].z;
        g_Minigame.barrels[i].currentPos.y += lbl_3_data_21770[0];
        g_Minigame.barrels[i].currentPos.y += (i % 3) * 10 - random_fn_3_9EE24(101) * 5 / 100.0;
        g_Minigame.barrels[i].barrelColour = random_fn_3_9EE24(3);
    }
}

// .text:0x0012FD6C size:0x118 mapped:0x8076EE00
void fn_3_12FD6C(void) {
    int i;

    for (i = 0; i < 15; i++) {
        if (g_Minigame.barrels[i].barrelState) {
            g_Minigame.barrels[i].posAtStartOfTurn.x = g_Minigame.barrels[i].currentPos.x;
            g_Minigame.barrels[i].posAtStartOfTurn.y = g_Minigame.barrels[i].currentPos.y;
            g_Minigame.barrels[i].posAtStartOfTurn.z = g_Minigame.barrels[i].currentPos.z;
            g_Minigame.barrels[i].barrelState = 1;
        }
        g_Minigame.barrels[i].animationCounter = 0;
    }
}

// .text:0x0012FAC4 size:0x2A8 mapped:0x8076EB58
void fn_3_12FAC4(void) {
    BB_barrelStruct* barrel;
    int i;

    fn_3_12F624();
    for (i = 0; i < 15; i++) {
        barrel = &g_Minigame.barrels[i];
        if (barrel->animationCounter < 0x7FFE) {
            barrel->animationCounter++;
        } else {
            barrel->animationCounter = 0x7FFF;
        }
        if (barrel->barrelState == 1) {
            fn_3_12F9D4(i);
        }
        if (barrel->barrelState == 3) {
            fn_3_12F28C(i);
        }
        if (barrel->replacingBarrelInd) {
            fn_3_12EFA4(i);
        }
    }
}

// .text:0x0012F9D4 size:0xF0 mapped:0x8076EA68
void fn_3_12F9D4(int idx) {
    BB_barrelStruct* barrel = &g_Minigame.barrels[idx];
    VecXYZ pos;

    barrel->currentPos.y += lbl_3_data_21770[1];
    if (barrel->currentPos.y < barrel->desiredPos.y) {
        barrel->currentPos.y = barrel->desiredPos.y;
        if (barrel->posAtStartOfTurn.y != barrel->desiredPos.y) {
            pos.x = barrel->currentPos.x;
            pos.y = barrel->currentPos.y;
            pos.z = barrel->currentPos.z;
            pos.y = -pos.y;
            pos.z = pos.z - 1.0f;
            if (barrel->currentPos.y <= 0.0f) {
                fn_8004C108(&pos, 1);
                fn_3_90064(0x2E4);
            } else {
                fn_8004C108(&pos, 0);
                fn_3_90064(0x2E5);
            }
        }
        barrel->barrelState = 2;
    }
}

// .text:0x0012F624 size:0x3B0 mapped:0x8076E6B8
void fn_3_12F624(void) {
    int flags[15];
    s32 i;
    int row;
    int col;
    int delay;
    BOOL changed;
    int points;
    int hit;
    s16* delays;

    i = g_Ball.framesSinceHit;
    if (i <= 0 || g_Minigame.barrelBatter_scoreCalculatedInd ||
        g_Ball.AtBat_Contact_BallPos.z < lbl_3_data_216BC[0].z - lbl_3_data_21770[2] ||
        g_Batter.contactType < 1 || g_Batter.contactType > 3) {
        return;
    }
    for (row = 0; row < 3; row++) {
        if (g_Ball.AtBat_Contact_BallPos.y < lbl_3_data_21770[3] + lbl_3_data_216BC[row].y) {
            break;
        }
    }
    if (row < 3 && !(g_Ball.AtBat_Contact_BallPos.x < lbl_3_data_216BC[0].x - lbl_3_data_21770[2])) {
        for (col = 0; col < 15; col += 3) {
            if (g_Ball.AtBat_Contact_BallPos.x < lbl_3_data_21770[2] + lbl_3_data_216BC[col].x) {
                break;
            }
        }
        if (col < 15) {
            g_Minigame.barrelBatter_hitBarrelID = col + row;
            for (i = 0; i < 15; i++) {
                flags[i] = 0;
            }
            delays = lbl_3_data_21788;
            hit = g_Minigame.barrelBatter_hitBarrelID;
            g_Minigame.barrels[hit].barrelState = 3;
            g_Minigame.barrels[hit].animationCounter = 0;
            g_Minigame.barrels[hit].delayUntilBlownUp = delays[0];
            delay = delays[0] + delays[1];
            if (g_Minigame.bB_bombBarrelID == hit && g_Minigame.barrels[hit].barrelColour == 3) {
                g_Minigame.bB_bombBarrelHitInd = 1;
            }
            for (;;) {
                changed = FALSE;
                for (i = 0; i < 15; i++) {
                    if (g_Minigame.barrels[i].barrelState == 3 && g_Minigame.barrels[i].delayUntilBlownUp != delay && !flags[i]) {
                        if (g_Minigame.bB_bombBarrelHitInd) {
                            fn_3_12F424(i, delay, TRUE);
                        } else {
                            fn_3_12F424(i, delay, FALSE);
                        }
                        flags[i] = 1;
                        changed = TRUE;
                        g_Minigame.barrelBatter_barrelsHit++;
                    }
                }
                if (!changed) {
                    break;
                }
                delay += delays[1];
            }
            if (!g_Minigame.bB_bombBarrelHitInd && g_Minigame.barrelBatter_barrelsHit >= 2) {
                g_Minigame.barrelBatterChargeMeter += g_Minigame.barrelBatter_barrelsHit - 1;
            }
            if (g_Minigame.barrelBatter_barrelsHit <= 1) {
                points = lbl_3_data_217A4[5] * g_Minigame.barrelBatter_barrelsHit;
            } else {
                points = g_Minigame.barrelBatter_barrelsHit * ((g_Minigame.barrelBatter_barrelsHit - 1) * lbl_3_data_217A4[5]);
            }
            g_Minigame.miniGameCurrentPoints[g_Minigame.rosterID] += points;
            g_Minigame._1DF4_s16 = points;
            if (!g_d_GameSettings.exhibitionMatchInd && g_Minigame.rosterID == lbl_3_common_bss_37400._40) {
                fn_3_1608F0(2, points, g_Minigame.barrelBatter_barrelsHit);
            }
        }
    }
    g_Minigame.barrelBatter_scoreCalculatedInd = 1;
}

// .text:0x0012F424 size:0x200 mapped:0x8076E4B8
// 94.65%: the target computes idx % 3 again for the second test, where this reuses the first
// result (one register more through the first block). A cast, (int)idx % 3, matches.
void fn_3_12F424(int idx, int delay, BOOL all) {
    int colour = g_Minigame.barrels[idx].barrelColour;
    int n;

    if (idx % 3 != 2) {
        n = idx + 1;
        if (g_Minigame.barrels[n].barrelState == 2 && n != g_Minigame.bB_bombBarrelID &&
            (g_Minigame.barrels[n].barrelColour == colour || all)) {
            g_Minigame.barrels[n].barrelState = 3;
            g_Minigame.barrels[n].animationCounter = 0;
            g_Minigame.barrels[n].delayUntilBlownUp = delay;
        }
    }
    if (idx % 3 != 0) {
        n = idx - 1;
        if (g_Minigame.barrels[n].barrelState == 2 && n != g_Minigame.bB_bombBarrelID &&
            (g_Minigame.barrels[n].barrelColour == colour || all)) {
            g_Minigame.barrels[n].barrelState = 3;
            g_Minigame.barrels[n].animationCounter = 0;
            g_Minigame.barrels[n].delayUntilBlownUp = delay;
        }
    }
    if (idx / 3 > 0) {
        n = idx - 3;
        if (g_Minigame.barrels[n].barrelState == 2 && n != g_Minigame.bB_bombBarrelID &&
            (g_Minigame.barrels[n].barrelColour == colour || all)) {
            g_Minigame.barrels[n].barrelState = 3;
            g_Minigame.barrels[n].animationCounter = 0;
            g_Minigame.barrels[n].delayUntilBlownUp = delay;
        }
    }
    if (idx / 3 < 4) {
        n = idx + 3;
        if (g_Minigame.barrels[n].barrelState == 2 && n != g_Minigame.bB_bombBarrelID &&
            (g_Minigame.barrels[n].barrelColour == colour || all)) {
            g_Minigame.barrels[n].barrelState = 3;
            g_Minigame.barrels[n].animationCounter = 0;
            g_Minigame.barrels[n].delayUntilBlownUp = delay;
        }
    }
}

// .text:0x0012F28C size:0x198 mapped:0x8076E320
void fn_3_12F28C(int idx) {
    BB_barrelStruct* barrel = &g_Minigame.barrels[idx];

    if (barrel->animationCounter >= barrel->delayUntilBlownUp) {
        barrel->barrelState = 4;
        barrel->animationCounter = 0;
        fn_3_12EE68(idx);
        fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.rosterID], 0);
    }
}

// .text:0x0012EFA4 size:0x2E8 mapped:0x8076E038
void fn_3_12EFA4(int idx) {
    BB_barrelStruct* barrel = &g_Minigame.barrels[idx];
    BB_barrelStruct* above;
    BB_barrelStruct* below;
    VecXYZ pos;

    barrel->currentPos.y += barrel->velo_bounceUpOnBlowUp;
    if (barrel->velo_bounceUpOnBlowUp > 0.0f && idx % 3 == 1) {
        above = &g_Minigame.barrels[idx + 1];
        if (above->barrelState != 4 && !above->replacingBarrelInd) {
            fn_3_12EE68(idx);
        }
        if (above->currentPos.y - barrel->currentPos.y < lbl_3_data_21770[3]) {
            barrel->velo_bounceUpOnBlowUp -= lbl_3_data_21770[5];
        }
    }
    barrel->velo_bounceUpOnBlowUp -= lbl_3_data_21770[5];
    if (barrel->velo_bounceUpOnBlowUp > 0.0f && idx % 3 == 2) {
        below = &g_Minigame.barrels[idx - 1];
        if (barrel->currentPos.y - below->currentPos.y < lbl_3_data_21770[3]) {
            barrel->velo_bounceUpOnBlowUp += lbl_3_data_21770[5];
        }
    }
    if (barrel->currentPos.y < barrel->_28) {
        barrel->currentPos.y = barrel->_28;
        barrel->velo_bounceUpOnBlowUp = 0.0f;
        barrel->replacingBarrelInd = 0;
        if (barrel->barrelState != 4) {
            pos.x = barrel->currentPos.x;
            pos.y = barrel->currentPos.y;
            pos.z = barrel->currentPos.z;
            pos.z = pos.z - 1.0f;
            pos.y = -barrel->_28;
            if (barrel->_28 == 0.0f) {
                fn_8004C108(&pos, 1);
                fn_3_90064(0x2E4);
            } else {
                fn_8004C108(&pos, 0);
                fn_3_90064(0x2E5);
            }
        }
    }
}

// .text:0x0012EE68 size:0x13C mapped:0x8076DEFC
void fn_3_12EE68(int idx) {
    BB_barrelStruct* barrel = &g_Minigame.barrels[idx];
    BB_barrelStruct* above;
    u8 n;

    if (idx % 3 == 2) {
        return;
    }
    above = &g_Minigame.barrels[idx + 1];
    if (above->barrelState == 4) {
        return;
    }
    if (above->barrelState == 3 && above->currentPos.y - barrel->currentPos.y > 0.3 + lbl_3_data_21770[3]) {
        return;
    }
    above->replacingBarrelInd = 1;
    above->velo_bounceUpOnBlowUp = lbl_3_data_21770[4];
    if ((idx + 1) % 3 == 1) {
        above->_28 = lbl_3_data_216BC[idx].y;
    } else {
        n = 0;
        n |= g_Minigame.barrels[idx - 1].barrelState == 2;
        n |= g_Minigame.barrels[idx].barrelState == 2;
        above->_28 = lbl_3_data_216BC[n].y;
    }
}

// .text:0x0012ED80 size:0xE8 mapped:0x8076DE14
u8 fn_3_12ED80(void) {
    int i;

    for (i = 1; i < 15; i += 3) {
        if (g_Minigame.barrels[i].replacingBarrelInd) {
            return FALSE;
        }
        if (g_Minigame.barrels[i + 1].replacingBarrelInd) {
            return FALSE;
        }
    }
    return TRUE;
}

// .text:0x0012EB10 size:0x270 mapped:0x8076DBA4
void fn_3_12EB10(void) {
    int col;
    int row;
    int k;
    int idx;

    for (col = 0; col < 5; col++) {
        for (row = 0; row < 2; row++) {
            for (;;) {
                idx = col * 3 + row;
                if (g_Minigame.barrels[idx].barrelState != 4) {
                    break;
                }
                for (k = row + 1; k < 3; k++) {
                    g_Minigame.barrels[col * 3 + k - 1].barrelState = g_Minigame.barrels[col * 3 + k].barrelState;
                    g_Minigame.barrels[col * 3 + k - 1].barrelColour = g_Minigame.barrels[col * 3 + k].barrelColour;
                    g_Minigame.barrels[col * 3 + k - 1].currentPos.x = g_Minigame.barrels[col * 3 + k].currentPos.x;
                    g_Minigame.barrels[col * 3 + k - 1].currentPos.y = g_Minigame.barrels[col * 3 + k].currentPos.y;
                    g_Minigame.barrels[col * 3 + k - 1].currentPos.z = g_Minigame.barrels[col * 3 + k].currentPos.z;
                    g_Minigame.barrels[col * 3 + k].barrelState = 0;
                }
            }
        }
    }
    for (col = 0; col < 5; col++) {
        idx = col * 3 + 2;
        if (g_Minigame.barrels[idx].barrelState == 4) {
            g_Minigame.barrels[idx].barrelState = 0;
        }
    }
}

// .text:0x0012E8FC size:0x214 mapped:0x8076D990
void fn_3_12E8FC(void) {
    int i;
    BOOL bomb = FALSE;
    int n;

    if (g_Minigame.barrelBatterChargeMeter >= lbl_3_data_21788[2]) {
        for (i = 0, n = 0; i < 15; i++) {
            if (g_Minigame.barrels[i].barrelState == 0) {
                n++;
            }
        }
        n = random_fn_3_9EE24(n);
        g_Minigame.barrelBatterChargeMeter = 0;
        bomb = TRUE;
    }
    for (i = 0; i < 15; i++) {
        if (g_Minigame.barrels[i].barrelState == 0) {
            g_Minigame.barrels[i].barrelState = 1;
            g_Minigame.barrels[i].animationCounter = 0;
            g_Minigame.barrels[i].currentPos.x = lbl_3_data_216BC[i].x;
            g_Minigame.barrels[i].currentPos.y = lbl_3_data_216BC[i].y;
            g_Minigame.barrels[i].currentPos.z = lbl_3_data_216BC[i].z;
            g_Minigame.barrels[i].currentPos.y += lbl_3_data_21770[0];
            g_Minigame.barrels[i].currentPos.y += (i % 3) * 10 - random_fn_3_9EE24(101) * 5 / 100.0;
            g_Minigame.barrels[i].barrelColour = random_fn_3_9EE24(3);
            if (bomb) {
                if (n == 0) {
                    n = -1;
                    g_Minigame.barrels[i].barrelColour = 3;
                    g_Minigame.bB_bombBarrelID = i;
                } else if (n > 0) {
                    n--;
                }
            }
        }
    }
}

// .text:0x0012E83C size:0xC0 mapped:0x8076D8D0
void fn_3_12E83C(void) {
    int points;

    if (g_Minigame.barrelBatter_barrelsHit <= 1) {
        points = lbl_3_data_217A4[5] * g_Minigame.barrelBatter_barrelsHit;
    } else {
        points = g_Minigame.barrelBatter_barrelsHit * ((g_Minigame.barrelBatter_barrelsHit - 1) * lbl_3_data_217A4[5]);
    }
    g_Minigame.miniGameCurrentPoints[g_Minigame.rosterID] += points;
    g_Minigame._1DF4_s16 = points;
    if (!g_d_GameSettings.exhibitionMatchInd && g_Minigame.rosterID == lbl_3_common_bss_37400._40) {
        fn_3_1608F0(2, points, g_Minigame.barrelBatter_barrelsHit);
    }
}

// .text:0x0012E808 size:0x34 mapped:0x8076D89C
void fn_3_12E808(void) {
    memset(g_Minigame._1D7C, 0, 0x78);
}

// .text:0x0012E384 size:0x484 mapped:0x8076D418
u8 fn_3_12E384(UnkBarrelCell34B0* cells, s8 idx, u8 colour) {
    u8 n;

    if (colour == cells[idx].colour && cells[idx].state == 2) {
        cells[idx].state = 0;
        n = 1;
        if (idx / 3 > 0) {
            n += fn_3_12E384(cells, idx - 3, colour);
        }
        if (idx / 3 < 4) {
            n += fn_3_12E384(cells, idx + 3, colour);
        }
        if (idx % 3 > 0) {
            n += fn_3_12E384(cells, idx - 1, colour);
        }
        if (idx % 3 < 2) {
            n += fn_3_12E384(cells, idx + 1, colour);
        }
        return n;
    }
    return 0;
}

// .text:0x0012E17C size:0x208 mapped:0x8076D210
void fn_3_12E17C(s8* hits, s16* points, u8 lookahead) {
    UnkBarrelCell34B0 cells[15];
    UnkBarrelCell34B0 copy[15];
    s8 j;
    s8 k;
    s8 m;
    s8 i;
    s8 col;
    s8 row;
    s8 n;
    s16 score;
    s16 best;

    i = 0;
    do {
        j = 0;
        do {
            cells[j].state = g_Minigame.barrels[j].barrelState;
            cells[j].colour = g_Minigame.barrels[j].barrelColour;
        } while (++j < 15);
        hits[i] = fn_3_12E384(cells, i, cells[i].colour);
        if (hits[i] >= 2) {
            points[i] = (hits[i] - 1) * hits[i];
        } else {
            points[i] = hits[i];
        }
        if (lookahead) {
            m = 0;
            do {
                col = 0;
                do {
                    row = 0;
                    do {
                        if (cells[col + row * 3].state != 2) {
                            memcpy(&cells[col + row * 3], &cells[col + 1 + row * 3], sizeof(UnkBarrelCell34B0));
                            cells[col + 1 + row * 3].state = 0;
                        }
                    } while (++row < 5);
                } while (++col < 2);
            } while (++m < 2);
            best = 0;
            j = 0;
            do {
                k = 0;
                do {
                    memcpy(&copy[k], &cells[k], sizeof(UnkBarrelCell34B0));
                } while (++k < 15);
                n = fn_3_12E384(copy, j, copy[j].colour);
                if (n >= 2) {
                    score = (n - 1) * n;
                } else {
                    score = n;
                }
                if (score > best) {
                    best = score;
                }
            } while (++j < 15);
            points[i] += best;
        }
    } while (++i < 15);
}

// .text:0x0012E084 size:0xF8 mapped:0x8076D118
int fn_3_12E084(const void* a, const void* b) {
    const UnkBarrelTarget34B0* x = a;
    const UnkBarrelTarget34B0* y = b;
    MiniGameStruct* mg = &g_Minigame;
    s8 dx;
    s8 dy;

    if (x->_2 != y->_2) {
        return y->_2 - x->_2;
    }
    if (x->_1 != y->_1) {
        if (mg->_1DD2) {
            return x->_1 - y->_1;
        }
        return y->_1 - x->_1;
    }
    dx = __abs(2 - x->idx / 3);
    dy = __abs(2 - y->idx / 3);
    if (dx != dy) {
        return dx - dy;
    }
    dx = __abs(1 - x->idx % 3);
    dy = __abs(1 - y->idx % 3);
    return dx - dy;
}

// .text:0x0012DDCC size:0x2B8 mapped:0x8076CE60
void fn_3_12DDCC(void) {
    MiniGameStruct* mg = &g_Minigame;
    UnkBarrelTarget34B0 targets[15];
    s16 points[15];
    s8 hits[15];
    u8 strength;
    u32 lookahead;
    s8 row;
    s8 col;
    s8 i;
    s16 bomb;

    strength = mg->minigameControlStruct.aIStrength[mg->rosterID];
    bomb = mg->bB_bombBarrelID;
    if (bomb >= 0) {
        row = bomb / 3;
        col = bomb % 3;
    } else {
        if (mg->bB_pitchesRemainingInTurn > 2 && lbl_3_data_217C4[strength]) {
            lookahead = RandomInt_Game(100) < lbl_3_data_217C8[strength];
        } else {
            lookahead = FALSE;
        }
        if (lookahead) {
            fn_3_12E17C(hits, points, TRUE);
        } else {
            fn_3_12E17C(hits, points, FALSE);
        }
        i = 0;
        do {
            targets[i].idx = i;
            targets[i]._1 = hits[i];
            targets[i]._2 = points[i];
        } while (++i < 15);
        if (lookahead) {
            mg->_1DD2 = 1;
        } else {
            mg->_1DD2 = 0;
        }
        fn_800246D4(fn_3_12E084, targets, targets, sizeof(UnkBarrelTarget34B0), 15);
        row = targets[0].idx / 3;
        col = targets[0].idx % 3;
    }
    if (g_Batter.batterHand) {
        row = 4 - row;
    }
    mg->_1DCC = swingSoundFrame[0][1] + lbl_3_data_217BC[row];
    switch (col) {
    case 0:
        mg->_1DCE_u16 = 8;
        break;
    case 1:
    default:
        mg->_1DCE_u16 = 0;
        break;
    case 2:
        mg->_1DCE_u16 = 4;
        break;
    }
    if (RandomInt_Game(100) < lbl_3_data_217CC[strength]) {
        mg->_1DCC += (RandomInt_Game(2) ? 1 : -1) * (RandomInt_Game(lbl_3_data_217D0[strength]) + 1);
    }
    if (RandomInt_Game(100) < lbl_3_data_217D4[strength]) {
        mg->_1DCE_u16 = 0;
    }
}

// .text:0x0012DD88 size:0x44 mapped:0x8076CE1C
BOOL fn_3_12DD88(void) {
    u32 i = 0;

    do {
        if (g_Minigame.barrels[i].barrelState != 2) {
            break;
        }
    } while (++i < 15);
    return i >= 15;
}

// .text:0x0012DB80 size:0x208 mapped:0x8076CC14
void fn_3_12DB80(void) {
    MiniGameStruct* mg = &g_Minigame;
    s8 i;
    s8 idx;

    i = 0;
    do {
        g_Minigame._1DBC[i] = 0;
    } while (++i < 4);
    i = 0;
    do {
        idx = g_Minigame.minigameControlStruct.characterIndex[i];
        if (idx >= 0 && idx < 4 && i == g_Minigame.rosterID && g_Minigame.minigameControlStruct.battingHandedness[i]) {
            g_Minigame._1DBC[idx] = 1;
            memset(&g_Minigame._1D7C[idx], 0, sizeof(InputStruct));
            switch (g_Pitcher.pitcherActionState) {
            case 3:
                if (mg->_1DD1) {
                    if (g_Pitcher.framesUntilBallReachesBatterZ <= mg->_1DCC) {
                        switch (mg->_1DD0) {
                        case 0:
                            g_Minigame._1D7C[idx].newButtonInput |= INPUT_BUTTON_A;
                            g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                            mg->_1DD0++;
                            break;
                        case 1:
                            g_Minigame._1D7C[idx].newButtonInput |= mg->_1DCE_u16;
                            g_Minigame._1D7C[idx].buttonInput |= mg->_1DCE_u16 | INPUT_BUTTON_A;
                            mg->_1DD0++;
                            break;
                        case 2:
                            g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                            if (g_Batter.framesSinceStartOfSwing > 0) {
                                g_Minigame._1D7C[idx].buttonInput |= mg->_1DCE_u16;
                            }
                            break;
                        }
                    }
                } else if (fn_3_12DD88()) {
                    fn_3_12DDCC();
                    mg->_1DD1 = 1;
                }
                break;
            }
        }
    } while (++i < 4);
}

// .text:0x0012DB54 size:0x2C mapped:0x8076CBE8
void fn_3_12DB54(void) {
    s8 i = 0;

    do {
        g_Minigame._1DBC[i] = 0;
    } while (++i < 4);
}
