#include "game/rep_3290.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "game/rep_3880.h"
#include "game/m_sound.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/rand.h"
#include "string.h"
#include "game/rep_D18.h"
#include "game/rep_31A0.h"
#include "game/rep_28A8.h"
#include "game/rep_AC8.h"
#include "game/rep_1188.h"
#include "game/rep_1200.h"
#include "game/rep_540.h"
#include "game/rep_3090.h"
#include "musyx/musyx.h"
#include "game/rep_CC8.h"
#include "game/sta_c4.h"
#include "game/rep_3D50.h"

typedef struct {
    /* 0x000 */ VecXYZ _000;
    /* 0x00C */ u8 _00C[0x30 - 0xC];
    /* 0x030 */ f32 _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x50 - 0x40];
    /* 0x050 */ f32 _050;
    /* 0x054 */ u8 _054[0x20D - 0x54];
    /* 0x20D */ s8 _20D;
    /* 0x20E */ u8 _20E[0x268 - 0x20E];
} Unk3290Fielder; // size: 0x268

extern Unk3290Fielder g_Fielders[9];
extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0xAA - 0x04];
    /* 0xAA */ u8 _AA;
} g_Scores;

extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6;
} g_UnkSimulation_31AC0;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern u8 lbl_800EFBA4[0x10];

extern s16 lbl_3_data_5F3C[4];
extern f32 lbl_3_data_450C[18];
extern VecXZ lbl_3_data_21500[4];
extern VecXYZ lbl_3_data_21520[2][7];
extern VecXYZ lbl_3_data_215C8[2];
extern VecXYZ lbl_3_data_215E0[7];
extern f32 lbl_3_data_21634[5];
extern u32 lbl_3_data_21648[3];
extern s16 lbl_3_data_21654[12];
extern f32 lbl_3_data_21674[2];
extern s16 lbl_3_data_2167C[6];
extern f32 lbl_3_data_21688[3];
extern s8 lbl_3_data_21694[4][7];
extern s8 lbl_3_data_216B0[4][2];
extern s8 lbl_3_data_216B8[4];
extern f32 lbl_3_data_219B8[19];

extern void fn_8004C108(VecXYZ* pos, int arg1);
extern void fn_800246D4(int (*compare)(const void*, const void*), void* src, void* dst, int size, int count);
extern void Set_803cb848(int);
extern void changeScene(u8, s16);
extern int fn_3_6C938(int, int);
extern void minigamesSetSomePointers(void);
extern void minigamesGXStuff(void);
extern void minigamesSetSomePointers2(void);
extern u8 lbl_3_common_bss_32234[6];
extern u8 lbl_3_data_2127C[8][5];
extern u8 lbl_3_data_2166C[5];
extern u8 lbl_3_data_21671;
extern s16 lbl_3_data_21672;
extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

// .text:0x001160BC size:0x5E0 mapped:0x80755150
void fn_3_1160BC(void) {
    switch (g_GameLogic.gameStatus) {
    case 4:
        fn_3_115C24();
        break;
    case 26:
        fn_3_115BDC();
        break;
    case 6:
        fn_3_115B5C();
        break;
    case 7:
        fn_3_115AB4();
        break;
    case 0:
        fn_3_115978();
        break;
    case 1:
        fn_3_115540();
        break;
    case 25:
        fn_3_1158B0();
        break;
    case 3:
        fn_3_115738();
        break;
    case 15:
        fn_3_115828();
        break;
    }
}

// .text:0x001160B8 size:0x4 mapped:0x8075514C
void fn_3_1160B8(void) {}

// .text:0x00115C24 size:0x494 mapped:0x80754CB8
// The target saves one register fewer (four stw, not stmw r27) and keeps the coin loop's
// counter in the register of the zero it stores, behind an explicit 0 < 100 guard.
void fn_3_115C24(void) {
    int i;
    int n;
    s8 fielder;
    u8 strength;

    if (g_GameLogic._125 == 0) {
        fn_3_59A90();
        g_GameLogic.secondaryGameMode = 4;
        for (i = 0; i < 4; i++) {
            g_Minigame.miniGameCurrentPoints[i] = 0;
            g_Minigame.miniGameLatestPoints[i] = 0;
            g_Minigame.minigamePoints_current_Latest[i][0] = 0;
            g_Minigame.minigamePoints_current_Latest[i][1] = 0;
            g_Minigame.minigameControlStruct._28[i] = -1;
            g_Minigame.minigameFielderIndex[i] = -1;
            g_Minigame._18FC[i] = -1;
            g_Minigame._1900[i] = -1;
            g_Minigame.minigameControlStruct._24[i] = 0;
        }
        g_Scores._00 = 0;
        g_Minigame.turnNumberWithinRound = 0;
        g_Minigame.pointsReqToWin_challenge = 0;
        g_Minigame.rosterID = -1;
        g_Minigame._17C0 = 0;
        g_Minigame._1A37 = 0;
        g_Minigame.miniGameTurnCounter = 0;
        if (!g_Minigame.multiPlayerInd) {
            g_Scores._AA = lbl_3_data_2166C[g_Minigame.soloMinigameDifficulty];
            strength = lbl_3_data_2127C[g_Minigame.GameMode_MiniGame][g_Minigame.soloMinigameDifficulty];
            for (i = 0; i < 4; i++) {
                g_Minigame.minigameControlStruct.aIStrength[i] = strength;
            }
        } else {
            if (g_Minigame._1A3C) {
                for (i = 0; i < 4; i++) {
                    g_Minigame.minigameControlStruct.aIStrength[i] = lbl_3_data_2127C[7][0];
                }
            }
            g_Scores._AA = lbl_3_data_2166C[4];
        }
        n = 0;
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                g_Minigame.minigameControlStruct._28[n] = i;
                fielder = n + 2;
                g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]] = fielder;
                g_Minigame.minigameControlStruct._14[n] = i;
                g_Fielders[fielder]._20D = i;
                n++;
            }
        }
        fn_3_58870();
        fn_3_114A88(TRUE);
        for (i = 0; i < 7; i++) {
            g_Minigame.wallBallWalls[i]._28 = 0;
            g_Minigame.wallBallWalls[i].wallPos = i;
            g_Minigame.wallIndexTracker[i] = i;
        }
        g_Minigame.wallBallGameState = 0;
        g_Minigame._1A80 = 0;
        g_Minigame._1A78 = 0;
        for (i = 0; i < 2; i++) {
            g_Minigame.wallBallSpecialWallPos[i] = (i & 1) ? 0 : 6;
        }
        g_Minigame.wallBallPitcherRotationCounter = 0;
        g_Minigame.wallBallRotatePitchersInd = 0;
        g_Minigame.wallBall_hitNoteBlock = 0;
        g_Minigame.wallBall_hitBowserWall = 0;
        g_Minigame._1A8B = -1;
        g_Minigame.wallBall_UnknownAlways0 = 0;
        g_Minigame._1A8C[0] = 0;
        for (i = 0; i < 100; i++) {
            g_Minigame.wallBall_coinsVisibleInd[i] = 0;
        }
        minigamesSetSomePointers();
        minigamesGXStuff();
        minigamesSetSomePointers2();
        fn_3_F8ABC();
        g_GameLogic._125++;
    } else {
        lbl_3_common_bss_32234[1] = 1;
        fn_3_5A6D4(5);
    }
}

// .text:0x00115BDC size:0x48 mapped:0x80754C70
void fn_3_115BDC(void) {
    sndFXStartEx(0x1BD, lbl_800EFBA4[6], 0x3F, 0);
    fn_3_114A88(TRUE);
    fn_3_5A6D4(6);
}

// .text:0x00115B5C size:0x80 mapped:0x80754BF0
void fn_3_115B5C(void) {
    g_Scores._00++;
    g_Minigame.turnNumberWithinRound = 0;
    fn_3_5A6D4(7);
    if (g_Minigame.multiPlayerInd || g_Minigame._1A3C || g_Minigame.soloMinigameDifficulty != 3) {
        fn_3_10F550(4, 0);
    }
}

// .text:0x00115AB4 size:0xA8 mapped:0x80754B48
void fn_3_115AB4(void) {
    g_Minigame.minigamePlayerSelectedOrder = g_Minigame.minigameControlStruct._14[g_Minigame.turnNumberWithinRound];
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_Minigame.miniGameLatestPoints[0] = 0;
    g_Minigame.miniGameLatestPoints[1] = 0;
    g_Minigame.miniGameLatestPoints[2] = 0;
    g_Minigame.miniGameLatestPoints[3] = 0;
    fn_3_F578();
    fn_3_753E8(FALSE);
    fn_3_6EBB4(g_Minigame.minigamePlayerSelectedOrder);
    g_Batter.batPosition2.x = maybeInitialBatPos.x;
    g_Batter.batPosition2.y = maybeInitialBatPos.y;
    g_Batter.batPosition2.z = maybeInitialBatPos.z;
    fn_3_5A6D4(0);
}

// .text:0x00115978 size:0x13C mapped:0x80754A0C
void fn_3_115978(void) {
    fn_3_1158F8();
    g_Minigame.turnOverStatus = 0;
    g_Minigame.ballStoppedBreakingWallsInd = 0;
    g_Minigame.postBallStoppedCounter = 0;
    g_Minigame.wallBallPitchPower = 0;
    g_Minigame.wallBallPitchPowerRemaining = 0;
    g_Minigame.wallBall_hitNoteBlock = 0;
    g_Minigame.wallBall_hitBowserWall = 0;
    g_Minigame._1A8B = -1;
    g_Ball.totalFramesAtPlay = 0;
    if (g_Minigame.miniGameTurnCounter == 0) {
        if (g_GameLogic.pre_PostMiniGameInd) {
            g_GameLogic.minigameLastTurnSuccessInd = 1;
            g_GameLogic.hudElementLoadingInd = 1;
        } else {
            g_GameLogic.minigameLastTurnSuccessInd = 0;
        }
        g_GameLogic.pre_PostMiniGameInd = 0;
    } else if (g_Minigame.soloMinigameDifficulty != 3) {
        g_Minigame.wallBallPitcherRotationCounter = 0;
        g_Minigame.wallBallRotatePitchersInd = 1;
        fn_3_114A88(FALSE);
    } else {
        g_GameLogic.minigameLastTurnSuccessInd = 0;
    }
    changeScene(1, 6);
    fn_3_5A6D4(1);
}

// .text:0x001158F8 size:0x80 mapped:0x8075498C
void fn_3_1158F8(void) {
    fn_3_6EBB4(g_Minigame.minigamePlayerSelectedOrder);
    fn_3_F1DC();
    fn_3_751B4();
    fn_3_58870();
    memset(g_Minigame._1D7C, 0, 0x78);
    Set_803cb848(1);
    g_FieldingLogic._0AE = 0;
    g_UnkSimulation_31AC0._5 = 0;
    g_UnkSimulation_31AC0._6 = 4;
}

// .text:0x001158B0 size:0x48 mapped:0x80754944
void fn_3_1158B0(void) {
    if (g_Scores._00 >= g_Scores._AA) {
        fn_3_5A6D4(0xF);
    } else {
        fn_3_5A6D4(6);
    }
}

// .text:0x00115828 size:0x88 mapped:0x807548BC
void fn_3_115828(void) {
    fn_3_DE4FC();
    if (g_Minigame.soloMinigameDifficulty <= 2 && !g_Minigame.multiPlayerInd) {
        if (g_Minigame.minigameControlStruct._1C[g_Minigame._1908] == 1 &&
            g_Minigame.challenge_minigame_haven_tWonYetIndicator == 0) {
            g_Minigame._1A37 = 1;
        } else {
            g_Minigame._1A37 = 2;
        }
    }
    fn_3_5A6D4(0xE);
}

// .text:0x00115738 size:0xF0 mapped:0x807547CC
void fn_3_115738(void) {
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
        fn_3_5A6D4(7);
        break;
    }
}

static inline void clearWallFlags(void) {
    s8 j;

    j = 0;
    do {
        g_Minigame._1DC4[j] = 0;
        j++;
    } while (j < 4);
}

static inline void updateCoins(void) {
    int i;

    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i]) {
            g_Minigame.wallBall_coinsVisibleFrameCounter[i]++;
            g_Minigame.wallBall_coinCoordinates[i].x += g_Minigame.wallBall_coinVelocity[i].x;
            g_Minigame.wallBall_coinCoordinates[i].y += g_Minigame.wallBall_coinVelocity[i].y;
            g_Minigame.wallBall_coinCoordinates[i].z += g_Minigame.wallBall_coinVelocity[i].z;
            g_Minigame.wallBall_coinVelocity[i].y -= lbl_3_data_21634[2];
            if (g_Minigame.wallBall_coinCoordinates[i].y < lbl_3_data_219B8[14]) {
                g_Minigame.wallBall_coinCoordinates[i].y = lbl_3_data_219B8[14];
                g_Minigame.wallBall_coinVelocity[i].y = -g_Minigame.wallBall_coinVelocity[i].y * lbl_3_data_21634[3];
                g_Minigame.wallBall_coinVelocity[i].x *= lbl_3_data_21634[4];
                g_Minigame.wallBall_coinVelocity[i].z *= lbl_3_data_21634[4];
            }
            if (g_Minigame.wallBall_coinsVisibleFrameCounter[i] > lbl_3_data_2167C[4]) {
                g_Minigame.wallBall_coinsVisibleInd[i] = 0;
            }
        }
    }
}

// .text:0x00115540 size:0x1F8 mapped:0x807545D4
void fn_3_115540(void) {

    if (fn_3_108854() == 0) {
        if (g_Minigame.wallBallRotatePitchersInd) {
            fn_3_114A88(FALSE);
        } else if (g_Minigame.wallBallGameState == 2) {
            fn_3_1133C4();
            fn_3_75560();
            clearWallFlags();
            fn_3_113A48();
        }
        if (g_Minigame.ballStoppedBreakingWallsInd) {
            if (g_Minigame.postBallStoppedCounter < 0x7FFE) {
                g_Minigame.postBallStoppedCounter++;
            } else {
                g_Minigame.postBallStoppedCounter = 0x7FFF;
            }
        }
        fn_3_2EA24();
        if (g_Minigame.wallBallGameState == 0) {
            fn_3_114384();
            fn_3_1500C8();
        } else if (g_Minigame.wallBallGameState == 1) {
            fn_3_114204();
        } else if (g_Minigame.wallBallGameState == 2) {
            fn_3_113F14();
            fn_3_113D20();
        }
        updateCoins();
        fn_3_115108();
    }
}

// .text:0x00115108 size:0x438 mapped:0x8075419C
void fn_3_115108(void) {
    BOOL done = FALSE;
    s16 mult;
    int points;
    s16 lost;
    s16 i;
    s16 k;

    if (g_Pitcher.pitcherActionState == 4) {
        if (g_Pitcher.currentStateFrameCounter > 0x4A) {
            done = TRUE;
        } else if (g_Minigame.soloMinigameDifficulty == 3 && g_Pitcher.currentStateFrameCounter == 0x4A) {
            g_Minigame._1A8C[0] = 1;
        }
    } else if (g_Minigame.postBallStoppedCounter > lbl_3_data_2167C[2]) {
        done = TRUE;
    } else if (g_Minigame.soloMinigameDifficulty == 3 && g_Minigame.postBallStoppedCounter == lbl_3_data_2167C[2]) {
        g_Minigame._1A8C[0] = 1;
    }
    if (done) {
        if (!g_Minigame.wallBall_hitBowserWall) {
            mult = 1;
            if ((g_Minigame.multiPlayerInd || g_Minigame._1A3C || g_Minigame.soloMinigameDifficulty != 3) &&
                g_Scores._00 == g_Scores._AA) {
                mult = lbl_3_data_21672;
            }
            if (g_Minigame.wallBall_hitNoteBlock == 1) {
                points = g_Minigame.wallBall_UnknownAlways0 + lbl_3_data_21654[10] * mult;
                g_Minigame.miniGameCurrentPoints[g_Minigame.minigamePlayerSelectedOrder] += points;
                g_Minigame.wallBall_UnknownAlways0 = 0;
            } else {
                points = g_Minigame.miniGameLatestPoints[g_Minigame.minigamePlayerSelectedOrder] * mult;
                g_Minigame.miniGameCurrentPoints[g_Minigame.minigamePlayerSelectedOrder] += points;
            }
        } else {
            points = 0;
            if (g_Minigame.multiPlayerInd || g_Minigame._1A3C || g_Minigame.soloMinigameDifficulty != 3) {
                lost = g_Minigame.miniGameCurrentPoints[g_Minigame.minigamePlayerSelectedOrder] / 2;
                g_Minigame.miniGameCurrentPoints[g_Minigame.minigamePlayerSelectedOrder] -= lost;
                for (i = 0; i < 4; i++) {
                    if (i != g_Minigame.minigamePlayerSelectedOrder) {
                        g_Minigame.miniGameCurrentPoints[i] += lost / 3;
                    }
                }
                points = -lost;
            }
        }
        if (!g_d_GameSettings.exhibitionMatchInd && g_Minigame.minigamePlayerSelectedOrder == lbl_3_common_bss_37400._40) {
            fn_3_1608F0(1, points, g_Minigame.wallBall_hitNoteBlock);
        }
        g_Minigame.wallBallSomeXPos = g_Pitcher.pitcherCoord.x;
        g_Minigame.wallBallSomeZPos = g_Pitcher.pitcherCoord.z;
        g_Minigame.turnNumberWithinRound++;
        if (g_Minigame.turnNumberWithinRound >= g_Minigame.miniGameNumberOfParticipants) {
            g_Minigame.turnNumberWithinRound -= g_Minigame.miniGameNumberOfParticipants;
            g_Scores._00++;
            if (!g_Minigame.multiPlayerInd && !g_Minigame._1A3C && g_Minigame.soloMinigameDifficulty == 3) {
                g_Scores._00--;
                if (g_Minigame.wallBall_hitNoteBlock == 1) {
                    if (g_Scores._AA < lbl_3_data_21671) {
                        g_Scores._AA++;
                    }
                } else {
                    g_Scores._AA--;
                    if (g_Minigame.wallBall_hitBowserWall) {
                        for (k = 0; k < 1; k++) {
                            if (g_Scores._AA == 0) {
                                break;
                            }
                            g_Scores._AA--;
                        }
                    }
                }
            }
        }
        fn_3_1500C8();
        if (g_Scores._00 > g_Scores._AA) {
            sndFXStartEx(0x1BE, lbl_800EFBA4[7], 0x3F, 0);
            fn_3_5A6D4(0xF);
        } else {
            g_Minigame.wallBallGameState = 0;
            fn_3_5A6D4(7);
            if ((g_Minigame.multiPlayerInd || g_Minigame._1A3C || g_Minigame.soloMinigameDifficulty != 3) &&
                g_Minigame.turnNumberWithinRound == 0) {
                fn_3_10F550(4, 0);
            }
        }
    }
}

// .text:0x0011502C size:0xDC mapped:0x807540C0
void fn_3_11502C(void) {
    if (g_Minigame.turnOverStatus == 1) {
        g_Minigame.turnOverStatus = 2;
        g_GameLogic.CountdownUntilFade = lbl_3_data_2167C[0];
    }
    if (--g_GameLogic.CountdownUntilFade == 7) {
        changeScene(3, 6);
    }
    if (g_GameLogic.CountdownUntilFade <= 0) {
        fn_3_114FC0();
    }
}

// .text:0x00114FC0 size:0x6C mapped:0x80754054
void fn_3_114FC0(void) {
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    g_GameLogic.hudLoadingRelated = 1;
    if (++g_Minigame.turnNumberWithinRound >= g_Minigame.miniGameNumberOfParticipants) {
        fn_3_5A6D4(0x19);
    } else {
        fn_3_5A6D4(7);
    }
}

// .text:0x00114A88 size:0x538 mapped:0x80753B1C
void fn_3_114A88(BOOL instant) {
    int i;
    int slot;
    Unk3290Fielder* fielder;
    f32 t;
    f32 dx;
    f32 dz;

    if (++g_Minigame.wallBallPitcherRotationCounter == 1 || instant) {
        if (g_Minigame.soloMinigameDifficulty != MINIGAME_DIFFICULTY_SOLO_NON_CHALLENGE || g_Minigame.multiPlayerInd) {
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._14[(g_Minigame.turnNumberWithinRound + 3) % 4]]]._000.x = g_Minigame.wallBallSomeXPos;
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._14[(g_Minigame.turnNumberWithinRound + 3) % 4]]]._000.z = g_Minigame.wallBallSomeZPos;
        }
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                slot = i - g_Minigame.turnNumberWithinRound;
                if (slot < 0) {
                    slot += g_Minigame.miniGameNumberOfParticipants;
                }
                if (slot == 0) {
                    g_Minigame.wallBallWaitingLocations[g_Minigame.minigameControlStruct._14[i]].x = lbl_3_data_450C[0];
                    g_Minigame.wallBallWaitingLocations[g_Minigame.minigameControlStruct._14[i]].z = lbl_3_data_450C[1];
                } else {
                    g_Minigame.wallBallWaitingLocations[g_Minigame.minigameControlStruct._14[i]].x = lbl_3_data_21500[slot].x;
                    g_Minigame.wallBallWaitingLocations[g_Minigame.minigameControlStruct._14[i]].z = lbl_3_data_21500[slot].z;
                }
            }
        }
        if (instant) {
            for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
                fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
                fielder->_000.x = g_Minigame.wallBallWaitingLocations[i].x;
                fielder->_000.y = 0.0f;
                fielder->_000.z = g_Minigame.wallBallWaitingLocations[i].z;
            }
            return;
        }
    }
    if (g_Minigame.wallBallPitcherRotationCounter >= lbl_3_data_2167C[1]) {
        g_Minigame.wallBallRotatePitchersInd = FALSE;
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                g_Fielders[g_Minigame.minigameFielderIndex[i]]._050 = 0.0f;
            }
        }
    } else {
        t = 1.0f / (lbl_3_data_2167C[1] - g_Minigame.wallBallPitcherRotationCounter);
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
                dx = g_Minigame.wallBallWaitingLocations[i].x - fielder->_000.x;
                dx *= t;
                dz = g_Minigame.wallBallWaitingLocations[i].z - fielder->_000.z;
                dz *= t;
                fielder->_030 = dx;
                fielder->_034 = dz;
                fielder->_000.x += dx;
                fielder->_000.z += dz;
                fielder->_050 = dolsqrtf2(dx * dx + dz * dz);
                if (fielder->_050 > 0.0f) {
                    fielder->_038 = dx / fielder->_050;
                    fielder->_03C = dx / fielder->_050; // dx, not dz, in the original too
                }
            }
        }
    }
}

// .text:0x00114A2C size:0x5C mapped:0x80753AC0
void fn_3_114A2C(void) {
    if (g_Minigame.wallBallGameState == WALL_BALL_GAME_STATE_CALCULATE_NEW_WALLS) {
        fn_3_114384();
        fn_3_1500C8();
    } else if (g_Minigame.wallBallGameState == WALL_BALL_GAME_STATE_DROP_IN_NEW_WALLS) {
        fn_3_114204();
    } else if (g_Minigame.wallBallGameState == WALL_BALL_GAME_STATE_PITCH_OR_WAITING_FOR_PITCH) {
        fn_3_113F14();
        fn_3_113D20();
    }
}

// .text:0x001149B8 size:0x74 mapped:0x80753A4C
int fn_3_1149B8(const void* a, const void* b) {
    MaybeWallBallStruct* wallA = &g_Minigame.wallBallWalls[*(u8*)a];
    MaybeWallBallStruct* wallB = &g_Minigame.wallBallWalls[*(u8*)b];

    if (wallA->_28 == 3 && wallB->_28 != 3) {
        return -1;
    }
    if (wallA->_28 != 3 && wallB->_28 == 3) {
        return 1;
    }
    return wallA->wallPos - wallB->wallPos;
}

// .text:0x00114384 size:0x634 mapped:0x80753418
void fn_3_114384(void) {
    int limit;
    u32 i;
    u8 n;
    u32 j;
    int k;
    u32 standing;
    u32 counts[3];
    u32 candidates[7];
    u8 positions[7];
    u8 pick;
    int m;
    MaybeWallBallStruct* wall;

    if (g_Minigame.multiPlayerInd || g_Minigame._1A3C || g_Minigame.soloMinigameDifficulty != MINIGAME_DIFFICULTY_SOLO_NON_CHALLENGE) {
        switch (g_Scores._00) {
        case 1:
            limit = 1;
            break;
        case 2:
            limit = 2;
            break;
        default:
            limit = 3;
            break;
        }
    } else if (g_Minigame.miniGameTurnCounter < 6) {
        limit = 1;
    } else if (g_Minigame.miniGameTurnCounter < 11) {
        limit = 2;
    } else if (g_Minigame.miniGameTurnCounter < 16) {
        limit = 3;
    } else {
        limit = 4;
    }
    fn_800246D4(fn_3_1149B8, g_Minigame.wallIndexTracker, g_Minigame.wallIndexTracker, 1, 7);
    i = 0;
    do {
        g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].wallPos = i;
    } while (++i < 7);
    i = 0;
    do {
        counts[i] = 0;
    } while (++i < 3);
    standing = 0;
    i = 0;
    do {
        wall = &g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]];
        if (wall->_28 == 3) {
            standing++;
            counts[wall->coinGenerationCategory]++;
        }
    } while (++i < 7);
    i = 0;
    do {
        wall = &g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]];
        VEC_COPY(&wall->_C, &lbl_3_data_21520[0][wall->wallPos]);
        if (i < standing) {
            wall->_28 = 2;
        } else {
            VEC_COPY(&wall->_0, &wall->_C);
            VEC_ADD(&wall->_0, &wall->_0, &lbl_3_data_21520[1][wall->wallPos]);
            wall->_28 = 1;
            wall->coinGenerationCategory = 1;
            counts[wall->coinGenerationCategory]++;
            wall->_24 = lbl_3_data_21654[wall->coinGenerationCategory + 4];
        }
        wall->_26 = 0;
        wall->_18 = 0.0f;
        wall->_1C = 0.0f;
        wall->_20 = 0.0f;
    } while (++i < 7);
    if (standing < 7) {
        if (counts[2] == 0) {
            n = 0;
            for (i = standing; i < 7; i++) {
                j = 0;
                do {
                    if (i == g_Minigame.wallBallSpecialWallPos[j]) {
                        break;
                    }
                } while (++j < 2);
                if (j >= 2) {
                    positions[n++] = i;
                }
            }
            if (n) {
                pick = positions[RandomInt_Game(n)];
            } else {
                pick = RandomInt_Game_Range(standing, 6);
            }
            wall = &g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[pick]];
            wall->coinGenerationCategory = 2;
            wall->_24 = lbl_3_data_21654[wall->coinGenerationCategory + 4];
            counts[1]--;
        }
        if (counts[1] > limit) {
            m = 0;
            for (i = standing; i < 7; i++) {
                if (g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory != 2 &&
                    (i == 0 || g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i - 1]].coinGenerationCategory != 2) &&
                    (i == 6 || limit <= 1 || g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i + 1]].coinGenerationCategory != 2)) {
                    candidates[m] = i;
                    m++;
                }
            }
            if (m != 0) {
                while (counts[1] > limit) {
                    k = RandomInt_Game(m);
                    wall = &g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[candidates[k]]];
                    wall->coinGenerationCategory = 0;
                    wall->_24 = lbl_3_data_21654[wall->coinGenerationCategory + 4];
                    counts[1]--;
                    for (i = k; i < m - 1; i++) {
                        candidates[i] = candidates[i + 1];
                    }
                    if (--m <= 0) {
                        break;
                    }
                }
            }
        }
    }
    i = 0;
    do {
        g_Minigame.wallBallSpecialWallPos[i + 1] = g_Minigame.wallBallSpecialWallPos[i];
    } while (++i < 1);
    i = 0;
    do {
        if (g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory == 2) {
            g_Minigame.wallBallSpecialWallPos[0] = i;
            break;
        }
    } while (++i < 7);
    g_Minigame.wallBallGameState = WALL_BALL_GAME_STATE_DROP_IN_NEW_WALLS;
    g_Minigame._1A80 = 7;
}

// .text:0x00114204 size:0x180 mapped:0x80753298
void fn_3_114204(void) {
    int i;
    int count = 0;
    MaybeWallBallStruct* wall;

    for (i = 0; i < 7; i++) {
        wall = &g_Minigame.wallBallWalls[i];
        if (wall->_28 == 2) {
            VEC_ADD(&wall->_0, &wall->_0, &lbl_3_data_215C8[1]);
            if (wall->_0.z >= wall->_C.z) {
                wall->_0.z = wall->_C.z;
                wall->_28 = 3;
            }
            count++;
        }
    }
    if (count == 0) {
        for (i = 0; i < 7; i++) {
            wall = &g_Minigame.wallBallWalls[i];
            if (wall->_28 == 1) {
                VEC_ADD(&wall->_0, &wall->_0, &lbl_3_data_215C8[0]);
                if (wall->_0.y <= wall->_C.y) {
                    wall->_0.y = wall->_C.y;
                    wall->_28 = 3;
                    fn_8004C108(&wall->_C, 1);
                    fn_3_90064(0x2F4);
                }
                count++;
            }
        }
        if (count == 0) {
            g_Minigame.wallBallGameState = WALL_BALL_GAME_STATE_PITCH_OR_WAITING_FOR_PITCH;
        }
    }
}

// .text:0x00113F14 size:0x2F0 mapped:0x80752FA8
void fn_3_113F14(void) {
    MaybeWallBallStruct* wall;
    int i;
    int j;
    u8 count;
    f32 angle;

    if (g_Ball.pitchHangtimeCounter >= 1) {
        for (i = 0; i < 7; i++) {
            wall = &g_Minigame.wallBallWalls[i];
            if (wall->_28 == 3 &&
                g_Ball.AtBat_Contact_BallPos.z - g_Ball.groundYForBounces - lbl_3_data_21674[1] <= wall->_0.z &&
                !g_Minigame.ballStoppedBreakingWallsInd) {
                wall->_24 -= g_Minigame.wallBallPitchPowerRemaining;
                if (wall->_24 <= 0) {
                    g_Minigame.wallBallPitchPowerRemaining = -wall->_24;
                    wall->_28 = 4;
                    g_Minigame.miniGameLatestPoints[g_Minigame.minigamePlayerSelectedOrder] += lbl_3_data_21654[wall->coinGenerationCategory + 7];
                    count = lbl_3_data_21648[wall->coinGenerationCategory];
                    for (j = 0; j < 100; j++) {
                        if (!g_Minigame.wallBall_coinsVisibleInd[j]) {
                            g_Minigame.wallBall_coinsVisibleFrameCounter[j] = 0;
                            g_Minigame.wallBall_coinsVisibleInd[j] = TRUE;
                            VEC_COPY(&g_Minigame.wallBall_coinCoordinates[j], &lbl_3_data_215E0[wall->wallPos]);
                            angle = MTXDegToRad(rand() % 180);
                            g_Minigame.wallBall_coinVelocity[j].x = lbl_3_data_21634[1] * COSF(angle);
                            g_Minigame.wallBall_coinVelocity[j].z = lbl_3_data_21634[1] * SINF(angle);
                            g_Minigame.wallBall_coinVelocity[j].y = lbl_3_data_21634[0];
                            if (--count == 0) {
                                break;
                            }
                        }
                    }
                    fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder], 0);
                } else {
                    wall->_18 = 0.0f;
                    wall->_1C = lbl_3_data_21688[0];
                    wall->_20 = lbl_3_data_21688[1];
                    fn_3_90064(0x2E1);
                    fn_3_113EC0();
                }
                break;
            }
        }
    }
}

// .text:0x00113EC0 size:0x54 mapped:0x80752F54
void fn_3_113EC0(void) {
    g_Pitcher.ballVelocity.z = -g_Pitcher.ballVelocity.z;
    VEC_SCALE(&g_Pitcher.ballVelocity, &g_Pitcher.ballVelocity, lbl_3_data_21674[0]);
    g_Minigame.ballStoppedBreakingWallsInd = TRUE;
}

// .text:0x00113D20 size:0x1A0 mapped:0x80752DB4
void fn_3_113D20(void) {
    MaybeWallBallStruct* wall;
    int i;
    s8 flag = 0;
    s8 dir;
    f32 prev;
    f32 cur;

    for (i = 0; i < 7; i++) {
        wall = &g_Minigame.wallBallWalls[i];
        prev = wall->_18;
        if (prev == 0.0f && wall->_1C == 0.0f) {
            continue;
        }
        wall->_18 += wall->_1C * cos(prev);
        cur = wall->_18;
        if (cur >= 0.0f) {
            dir = -1;
        } else {
            dir = 1;
        }
        if (prev < cur) {
            if (prev < 0.0f && cur >= 0.0f) {
                flag = 1;
            }
        } else {
            if (prev > 0.0f && cur <= 0.0f) {
                flag = 1;
            }
        }
        if (flag) {
            wall->_1C *= lbl_3_data_21688[2];
            if (fabsf(wall->_1C) < wall->_20 * lbl_3_data_21688[2]) {
                wall->_18 = wall->_1C = wall->_20 = 0.0f;
            }
            flag = 0;
        }
        wall->_1C += dir * wall->_20;
    }
}

// .text:0x00113A48 size:0x2D8 mapped:0x80752ADC
void fn_3_113A48(void) {
    int i;
    int sum;
    s16 rem;

    if (g_Ball.pitchHangtimeCounter == 1) {
        g_Minigame.wallBallPitchPower = lbl_3_data_21654[3];
        if (g_Pitcher.ChargePitchType == 3) {
            g_Minigame.wallBallPitchPower = lbl_3_data_21654[2];
        } else if (g_Pitcher.ChargePitchType >= 2) {
            g_Minigame.wallBallPitchPower = LinearInterpolateToNewRange(g_Pitcher.pitchChargeUp, 0.0f, 1.0f, lbl_3_data_21654[0], lbl_3_data_21654[1]);
        }
        g_Minigame.wallBallPitchPowerRemaining = g_Minigame.wallBallPitchPower;
        i = sum = 0;
        do {
            sum += g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24;
            if (g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory == 2) {
                i++;
                break;
            }
            i++;
        } while (i < 7);
        if (g_Minigame.wallBallPitchPower >= sum) {
            if (i < 7) {
                if (g_Minigame.wallBallPitchPower <= sum + g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24 - 1) {
                    g_Minigame.wallBall_hitNoteBlock = TRUE;
                }
            } else {
                g_Minigame.wallBall_hitNoteBlock = TRUE;
            }
        }
        if (g_Minigame.wallBall_hitNoteBlock != TRUE) {
            rem = g_Minigame.wallBallPitchPower;
            for (i = 0; i < 7; i++) {
                rem -= g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24;
                if (rem < 0) {
                    break;
                }
            }
            if (--i >= 0 && g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory == 1) {
                g_Minigame._1A8B = i;
                g_Minigame.wallBall_hitBowserWall = TRUE;
            }
        }
    }
}

// .text:0x00113950 size:0xF8 mapped:0x807529E4
void fn_3_113950(void) {
    int i;

    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i]) {
            g_Minigame.wallBall_coinsVisibleFrameCounter[i]++;
            VEC_ADD(&g_Minigame.wallBall_coinCoordinates[i], &g_Minigame.wallBall_coinCoordinates[i], &g_Minigame.wallBall_coinVelocity[i]);
            g_Minigame.wallBall_coinVelocity[i].y -= lbl_3_data_21634[2];
            if (g_Minigame.wallBall_coinCoordinates[i].y < lbl_3_data_219B8[14]) {
                g_Minigame.wallBall_coinCoordinates[i].y = lbl_3_data_219B8[14];
                g_Minigame.wallBall_coinVelocity[i].y = -g_Minigame.wallBall_coinVelocity[i].y * lbl_3_data_21634[3];
                g_Minigame.wallBall_coinVelocity[i].x *= lbl_3_data_21634[4];
                g_Minigame.wallBall_coinVelocity[i].z *= lbl_3_data_21634[4];
            }
            if (g_Minigame.wallBall_coinsVisibleFrameCounter[i] > lbl_3_data_2167C[4]) {
                g_Minigame.wallBall_coinsVisibleInd[i] = 0;
            }
        }
    }
}

// .text:0x0011391C size:0x34 mapped:0x807529B0
void fn_3_11391C(void) {
    memset(g_Minigame._1D7C, 0, 0x78);
}

// .text:0x001136FC size:0x220 mapped:0x80752790
void fn_3_1136FC(void) {
    MiniGameStruct* mg = &g_Minigame;
    u8 strength;
    s8 i;
    s16 min;
    s16 max;
    s8 idx;
    s16 r;

    min = 0;
    max = 0x7FFF;
    idx = 0;
    strength = mg->minigameControlStruct.aIStrength[mg->minigamePlayerSelectedOrder];
    i = 0;
    do {
        min += g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24;
        if (g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory == 2) {
            idx = i++;
            break;
        }
        i++;
    } while (i < 7);
    if (i < 7) {
        max = min + g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24 - 1;
    }
    if (RandomInt_Game(100) < lbl_3_data_21694[strength][idx]) {
        r = RandomInt_Game_Range(lbl_3_data_216B0[strength][0], lbl_3_data_216B0[strength][1]);
        min += r;
        max += r;
    }
    if (min <= lbl_3_data_21654[2] && lbl_3_data_21654[2] <= max) {
        mg->_1DCE = 0;
    } else if (min <= lbl_3_data_21654[3] && lbl_3_data_21654[3] <= max) {
        mg->_1DCE = 3;
    } else if (max >= lbl_3_data_21654[0] && min <= lbl_3_data_21654[1]) {
        mg->_1DCE = 2;
        if (min < lbl_3_data_21654[0]) {
            min = lbl_3_data_21654[0];
        }
        if (max > lbl_3_data_21654[1]) {
            max = lbl_3_data_21654[1];
        }
        mg->_1DCC = RandomInt_Game_Range(min, max);
    } else {
        mg->_1DCE = 1;
    }
    if (mg->_1DCE == 0 && RandomInt_Game(100) < lbl_3_data_216B8[strength]) {
        mg->_1DCE = 1;
    }
}

// .text:0x001133C4 size:0x338 mapped:0x80752458
void fn_3_1133C4(void) {
    MiniGameStruct* mg = &g_Minigame;
    s8 i;
    s8 idx;
    s16 power;

    i = 0;
    do {
        g_Minigame._1DC4[i] = FALSE;
    } while (++i < 4);
    i = 0;
    do {
        if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0 && g_Minigame.minigameControlStruct.characterIndex[i] < 4 &&
            i == g_Minigame.minigamePlayerSelectedOrder && g_Minigame.minigameControlStruct.battingHandedness[i]) {
            idx = g_Minigame.minigameControlStruct.characterIndex[i];
            g_Minigame._1DC4[idx] = TRUE;
            memset(&g_Minigame._1D7C[idx], 0, sizeof(InputStruct));
            switch (mg->_1DCF) {
            case 0:
                fn_3_1136FC();
                mg->_1DD0 = 60;
                mg->_1DCF = 1;
                break;
            case 1:
                if (--mg->_1DD0 > 0) {
                    break;
                }
                switch (mg->_1DCE) {
                case 0:
                    mg->_1DCF = 2;
                    break;
                case 1:
                    mg->_1DCF = 4;
                    break;
                case 2:
                    mg->_1DCF = 6;
                    break;
                case 3:
                default:
                    mg->_1DCF = 8;
                    break;
                }
                break;
            case 2:
                g_Minigame._1D7C[idx].newButtonInput |= INPUT_BUTTON_A;
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                mg->_1DCF = 3;
                break;
            case 3:
                if (g_Pitcher.windupCountdownUntilBallReleased < lbl_3_data_5F3C[2]) {
                    mg->_1DCF = 9;
                } else {
                    g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                }
                break;
            case 4:
                g_Minigame._1D7C[idx].newButtonInput |= INPUT_BUTTON_A;
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                mg->_1DCF = 5;
                break;
            case 5:
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                break;
            case 6:
                g_Minigame._1D7C[idx].newButtonInput |= INPUT_BUTTON_A;
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                mg->_1DCF = 7;
                break;
            case 7:
                if (!g_Pitcher.framesAHeldForChargePitches) {
                    power = LinearInterpolateToNewRange(1.0f - (f32)g_Pitcher.windupCountdownUntilBallReleased / (f32)g_Pitcher.pitchWindUpCountDown, 0.0f, 1.0f,
                                                        lbl_3_data_21654[0], lbl_3_data_21654[1]);
                    if (power >= mg->_1DCC) {
                        mg->_1DCF = 9;
                        break;
                    }
                }
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                break;
            case 8:
                g_Minigame._1D7C[idx].newButtonInput |= INPUT_BUTTON_A;
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                mg->_1DCF = 9;
                break;
            case 9:
                break;
            }
        }
    } while (++i < 4);
}
