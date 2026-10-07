#include "game/rep_34B0.h"
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
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/rand.h"
#include "string.h"

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

extern void fn_3_5A6D4(u8 status);
extern void changeScene(u8, s16);
extern void fn_3_10F550(u8, s16);
extern int fn_3_6C938(int, int);
extern void fn_3_FBD58(void);
extern void fn_3_FBD70(void);
extern void fn_3_10AD48(void);
extern void fn_8004C108(VecXYZ* pos, int arg1);
extern void fn_3_1608F0(int, int, int);
extern void ballPhysica(void);
extern void fn_3_59A90(void);
extern int fn_3_108854(void);
extern void fn_3_12DB80(void);

// .text:0x001324E8 size:0x9F4 mapped:0x8077157C
void fn_3_1324E8(void) {
    return;
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
    return;
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
            hit = g_Minigame.barrelBatter_hitBarrelID;
            g_Minigame.barrels[hit].barrelState = 3;
            g_Minigame.barrels[hit].animationCounter = 0;
            g_Minigame.barrels[hit].delayUntilBlownUp = lbl_3_data_21788[0];
            delay = lbl_3_data_21788[0] + lbl_3_data_21788[1];
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
                delay += lbl_3_data_21788[1];
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
