#include "game/rep_31F0.h"
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

extern struct {
    /* 0x0 */ u8 _0[0x8];
    /* 0x8 */ u8 _8;
} lbl_3_common_bss_32220;

extern u8 lbl_3_common_bss_32234[0x8];

extern struct {
    /* 0x00 */ u8 _00[0xB6];
    /* 0xB6 */ u8 _B6;
    /* 0xB7 */ u8 _B7;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_803CBC3C[];

extern s16 lbl_3_data_18C48[10];
extern u8 lbl_3_data_2127C[][5];
extern u8 lbl_3_data_2139C[8];
extern u8 lbl_3_data_213A4[][5];
extern u8 lbl_3_data_213D4[4][2];
extern u8 lbl_3_data_213DC[4];
extern u8 lbl_3_data_213E0[4];
extern u8 lbl_3_data_213E4[][2];
extern s16 lbl_3_data_213EC[10];
extern s16 lbl_3_data_21400[4][2];
extern f32 lbl_3_data_21438[4];
extern s16 lbl_3_data_21448[10];
extern u8 lbl_3_data_21488[][3];
extern s8 lbl_3_data_214A0[4][3][2];
extern s8 lbl_3_data_214B8[4][3];
extern s8 lbl_3_data_214C4[4][3];
extern s8 lbl_3_data_214D0[4][3];
extern s8 lbl_3_data_214DC[4][3];
extern s8 lbl_3_data_214E8[4][3];
extern s8 lbl_3_data_214F4[4][3];
extern s16 lbl_3_data_217A4[12];

// rep_1200.h and rep_1E08.h declare these as void(void) placeholders for their stubs
void fn_3_750C4(u8 state);
void fn_3_751B4(void);
void fn_3_753E8(BOOL keepAction);
void fn_3_75560(void);
void fn_3_BC6D8(Vec* pos, Vec* eye, int type, BOOL flag);
void fn_3_BF1AC(void);

extern int fn_3_9E368(int* weights, int count);
extern void fn_8003A540(int);
extern void fn_3_5A6D4(u8 status);
extern void fn_3_1608F0(int, int, int);
extern void ballPhysica(void);
extern int fn_3_108854(void);
extern void changeScene(u8, s16);
extern void fn_3_10F550(u8, s16);
extern int fn_3_6C938(int, int);
extern void fn_3_FBD58(void);
extern void fn_3_FBD70(void);
extern void minigamesSetSomePointers(void);
extern void minigamesGXStuff(void);
extern void minigamesSetSomePointers2(void);
extern void Set_803cb848(int);
extern void fn_3_10AD48(void);
extern void fn_3_59A90(void);
extern camera_803c639c_s* fn_80052734(int);
extern void fn_8003414C(Mtx);

static const Vec lbl_3_rodata_3240 = { 0.0f, -45.0f, 160.0f };
static u8 lbl_3_bss_B699;
static u8 lbl_3_bss_B698;

// .text:0x00112BD8 size:0x7C0 mapped:0x80751C6C
void fn_3_112BD8(void) {
    switch (g_GameLogic.gameStatus) {
    case GAME_STATUS_DEFAULT:
        fn_3_112230();
        break;
    case GAME_STATUS_AT_BAT:
        fn_3_111C5C();
        break;
    case GAME_STATUS_LIVE_BALL:
        fn_3_111738();
        break;
    case GAME_STATUS_INNING_TRANSITION:
        fn_3_111F80();
        break;
    case GAME_STATUS_LOAD_GAME:
        fn_3_112610();
        break;
    case GAME_STATUS_TRANSITION_TO_MINIGAME_START:
        fn_3_112558();
        break;
    case GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY:
        fn_3_112450();
        break;
    case GAME_STATUS_TRANSITION:
        fn_3_112128();
        break;
    case GAME_STATUS_TRANSITION_MINIGAME_POSTGAME:
        fn_3_112070();
        break;
    case GAME_STATUS_MINIGAME_NEW_ROUND:
        fn_3_1120E0();
        break;
    case GAME_STATUS_TRANSITION_MINIGAME_TO_BATTING:
        fn_3_1125D0();
        break;
    }
}

// .text:0x001128EC size:0x2EC mapped:0x80751980
void fn_3_1128EC(void) {
    camera_803c639c_s* camera = fn_80052734(0);
    Vec eye;
    Vec pos;
    Mtx inv;
    Vec offset;
    u8 type;

    if (g_Minigame._18A6 <= 0) {
        eye = camera->eye;
        pos = camera->target;
        PSVECSubtract(&pos, &eye, &pos);
        PSVECNormalize(&pos, &pos);
        PSVECScale(&pos, 200.0f, &pos);
        PSVECAdd(&eye, &pos, &pos);
        if (pos.y > 55.0f) {
            pos.y = 55.0f;
        }
        PSMTXInverse(camera->view, inv);
        offset.x = (rand() % 10000 - 5000) / 250.0f;
        offset.y = (rand() % 1000 - 500) / 100.0f;
        offset.z = 0.0f;
        PSMTXMultVecSR(inv, &offset, &offset);
        PSVECAdd(&pos, &offset, &pos);
        if (pos.y > -55.0f) {
            pos.y = -55.0f + -10.0f * (rand() / 32767.0f);
        }
        if (lbl_3_bss_B699) {
            type = rand() % 5 + 8;
        } else {
            type = rand() % 4 + 4;
        }
        fn_3_BC6D8(&pos, &camera->eye, type, FALSE);
        lbl_3_bss_B699 = !lbl_3_bss_B699;
        g_Minigame._18A6 = rand() % 60 + 60;
    } else {
        g_Minigame._18A6--;
    }
    fn_8003414C(camera->view);
}

// .text:0x001128E8 size:0x4 mapped:0x8075197C
void fn_3_1128E8(void) {
    return;
}

// .text:0x00112610 size:0x2D8 mapped:0x807516A4
void fn_3_112610(void) {
    return;
}

// .text:0x001125D0 size:0x40 mapped:0x80751664
void fn_3_1125D0(void) {
    sndFXStart(0x1BD, lbl_800EFBA4[6], 0x3F);
    fn_3_5A6D4(GAME_STATUS_TRANSITION_TO_MINIGAME_START);
}

// .text:0x00112558 size:0x78 mapped:0x807515EC
void fn_3_112558(void) {
    g_Scores._00++;
    g_Minigame.turnNumberWithinRound = 0;
    if (!g_Minigame.multiPlayerInd) {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
    } else {
        if (g_Scores._00 == 1) {
            fn_3_10AD48();
        }
        fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
        fn_3_10F550(4, 0);
    }
}

// .text:0x00112450 size:0x108 mapped:0x807514E4
void fn_3_112450(void) {
    switch (g_GameLogic._125) {
    case 0:
        g_Minigame.rosterID = g_Minigame.minigameControlStruct._14[g_Minigame.turnNumberWithinRound];
        g_GameLogic.pre_PostMiniGameInd = 1;
        g_Minigame.miniGameTurnCounter = 0;
        g_Minigame.pointsTargetReachedInd = 0;
        g_Minigame.bOD_HRStreak = 0;
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

// .text:0x00112230 size:0x220 mapped:0x807512C4
void fn_3_112230(void) {
    return;
}

// .text:0x001121A4 size:0x8C mapped:0x80751238
void fn_3_1121A4(void) {
    setInMemBatterConstants(g_Minigame.rosterID);
    fn_3_F1DC();
    fn_3_751B4();
    setDefaultInMemBatter();
    fn_3_8913C();
    fn_3_58870();
    fn_3_110A04();
    fn_3_BF1AC();
    Set_803cb848(1);
    g_FieldingLogic._0AE = 0;
    g_UnkSimulation_31AC0._5 = 0;
    g_UnkSimulation_31AC0._6 = 4;
}

// .text:0x00112128 size:0x7C mapped:0x807511BC
void fn_3_112128(void) {
    g_Minigame.turnNumberWithinRound++;
    if (!g_Minigame.multiPlayerInd) {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_MINIGAME_POSTGAME);
    } else if (g_Minigame.turnNumberWithinRound >= g_Minigame.miniGameNumberOfParticipants) {
        fn_3_5A6D4(GAME_STATUS_MINIGAME_NEW_ROUND);
    } else {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
    }
    lbl_3_common_bss_32724._B7 = 1;
}

// .text:0x001120E0 size:0x48 mapped:0x80751174
void fn_3_1120E0(void) {
    if (g_Scores._00 >= g_Scores._AA) {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_MINIGAME_POSTGAME);
    } else {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_TO_MINIGAME_START);
    }
}

// .text:0x00112070 size:0x70 mapped:0x80751104
void fn_3_112070(void) {
    fn_3_DE4FC();
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    g_Minigame._18A6 = rand() % 30 + 15;
    fn_3_155288();
    minigamesSetSomePointers();
    minigamesGXStuff();
    minigamesSetSomePointers2();
}

// .text:0x00111F80 size:0xF0 mapped:0x80751014
void fn_3_111F80(void) {
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

// .text:0x00111C5C size:0x324 mapped:0x80750CF0
void fn_3_111C5C(void) {
    return;
}

// .text:0x00111AC4 size:0x198 mapped:0x80750B58
void fn_3_111AC4(void) {
    if (g_Minigame.turnOverStatus == 0) {
        if (g_Pitcher.pitcherActionState == 4) {
            if (g_Minigame.miniGameTurnCounter >= g_Minigame.bODRoundStartingNumPitches) {
                g_Minigame.turnOverStatus = 1;
                g_Minigame.pointsTargetReachedInd = 1;
            }
            g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] = 0;
            fn_3_155288();
        }
        return;
    }
    if (g_Minigame.turnOverStatus == 1) {
        g_Minigame.turnOverStatus = 2;
        g_GameLogic.CountdownUntilFade = lbl_3_data_21448[0];
    }
    g_GameLogic.CountdownUntilFade--;
    if (g_Minigame.pointsTargetReachedInd &&
        (!g_Minigame.multiPlayerInd ||
         (g_Minigame.multiPlayerInd && g_Minigame.turnNumberWithinRound + 1 >= g_Minigame.miniGameNumberOfParticipants &&
          g_Scores._00 >= g_Scores._AA)) &&
        !g_Minigame._1A37 && g_GameLogic.CountdownUntilFade == 0x43) {
        sndFXStart(0x1BE, lbl_800EFBA4[7], 0x3F);
    }
    if (g_GameLogic.CountdownUntilFade == 7) {
        changeScene(3, 6);
    }
    if (g_GameLogic.CountdownUntilFade <= 0) {
        fn_3_111A88();
    }
}

// .text:0x00111A88 size:0x3C mapped:0x80750B1C
void fn_3_111A88(void) {
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    g_GameLogic.hudLoadingRelated = 1;
    fn_3_5A6D4(GAME_STATUS_TRANSITION);
}

// .text:0x001118B4 size:0x1D4 mapped:0x80750948
void fn_3_1118B4(void) {
    return;
}

// .text:0x00111738 size:0x17C mapped:0x807507CC
void fn_3_111738(void) {
    int i;

    ballPhysica();
    fn_3_1111D0();
    if (g_Ball.bODQualifyingHitInd && g_Ball.deadBallReason == 1 &&
        (g_Ball.ballDistanceFromHome > lbl_3_data_21438[3] || g_Minigame.bODRelated3)) {
        fn_3_110AD4();
        g_Minigame.bOD_hitFinishedInd = 1;
    }
    for (i = 0; i < 10; i++) {
        if (g_Minigame._1A96[i] != 0) {
            g_Minigame._1A96[i]--;
            if (g_Minigame._1A96[i] == 0) {
                fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.rosterID], 0);
            }
        }
    }
    if (g_Ball.deadBallReason == 2) {
        g_Minigame.bOD_hitFinishedInd = 1;
    }
    fn_3_8F21C();
    fn_3_1112B4();
}

// .text:0x001112B4 size:0x484 mapped:0x80750348
void fn_3_1112B4(void) {
    if (g_Minigame.turnOverStatus == 0) {
        if (g_Ball.framesOnGroundUntilPickedUp) {
            g_GameLogic.CountdownUntilFade = lbl_3_data_21448[1];
            g_Minigame.turnOverStatus = 1;
            g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] = 0;
        } else if (g_Ball.deadBallReason) {
            if (g_Ball.deadBallReason == 1) {
                g_GameLogic.CountdownUntilFade = lbl_3_data_21448[2];
                g_Minigame.bOD_HRStreak++;
                fn_3_111038();
            } else {
                g_GameLogic.CountdownUntilFade = lbl_3_data_21448[2];
                g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] = 0;
            }
            g_Minigame.turnOverStatus = 1;
        }
        return;
    }
    if (g_Minigame.turnOverStatus == 1) {
        g_Minigame.turnOverStatus = 2;
        if (!g_Minigame.multiPlayerInd && g_Minigame.soloMinigameDifficulty <= 2 &&
            g_Minigame.miniGameCurrentPoints[g_Minigame.rosterID] >= g_Minigame.pointsReqToWin_challenge) {
            g_Minigame.pointsTargetReachedInd = 1;
            g_Minigame._1A37 = 1;
            g_Minigame.challenge_minigame_haven_tWonYetIndicator = 0;
            fn_3_10F550(1, lbl_3_data_21448[9]);
        } else if (g_Minigame.miniGameTurnCounter >= g_Minigame.bODRoundStartingNumPitches) {
            if (!g_Minigame.multiPlayerInd && g_Minigame.soloMinigameDifficulty == 3 && g_Ball.deadBallReason == 1 &&
                g_Minigame.miniGameTurnCounter < 20) {
                if (g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] < g_Minigame.miniGameTurnCounter) {
                    g_Minigame.pointsTargetReachedInd = 1;
                }
            } else {
                g_Minigame.pointsTargetReachedInd = 1;
            }
        }
    }
    if (g_Minigame.bODControllerInputAllowedInd && !g_Minigame.bODRelated) {
        g_GameLogic.CountdownUntilFade--;
        if (g_Minigame.pointsTargetReachedInd &&
            (!g_Minigame.multiPlayerInd ||
             (g_Minigame.multiPlayerInd && g_Minigame.turnNumberWithinRound + 1 >= g_Minigame.miniGameNumberOfParticipants &&
              g_Scores._00 >= g_Scores._AA)) &&
            !g_Minigame._1A37 && g_GameLogic.CountdownUntilFade == 0x43) {
            sndFXStart(0x1BE, lbl_800EFBA4[7], 0x3F);
        }
        if (g_GameLogic.CountdownUntilFade == 7) {
            changeScene(3, 6);
        }
        if (g_GameLogic.CountdownUntilFade <= 0) {
            fn_3_111250();
        }
    }
}

// .text:0x00111250 size:0x64 mapped:0x807502E4
void fn_3_111250(void) {
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    g_GameLogic.hudLoadingRelated = 1;
    fn_8003A540(0);
    if (g_Minigame.pointsTargetReachedInd == 1) {
        fn_3_5A6D4(GAME_STATUS_TRANSITION);
    } else {
        fn_3_5A6D4(GAME_STATUS_DEFAULT);
    }
}

// .text:0x001111D0 size:0x80 mapped:0x80750264
void fn_3_1111D0(void) {
    InMemRunnerType* runner = &g_Runners[0];
    int angle;

    if (lbl_3_common_bss_32220._8 == 4) {
        angle = g_Ball.Hit_HorizontalAngle;
        if (angle < 0x200) {
            angle = 0x200;
        }
        if (angle > 0x600) {
            angle = 0x600;
        }
        runner->runningAngle = -shortAngleToRad(angle) - 1.5707964f;
    }
}

// .text:0x00111038 size:0x198 mapped:0x807500CC
void fn_3_111038(void) {
    s16 power = g_Ball.Hit_HorizontalPower;
    f32 points;

    g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0]++;
    if (g_Minigame.bOD_HitPowerOfEachChar[g_Minigame.rosterID] < power) {
        g_Minigame.bOD_HitPowerOfEachChar[g_Minigame.rosterID] = power;
    }
    points = power;
    if (g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] > 1) {
        points += lbl_3_data_213EC[8] * g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0];
    }
    if (g_Minigame.bOD_KingBombInd) {
        points += lbl_3_data_213EC[7];
    }
    g_Minigame.miniGameLatestPoints[g_Minigame.rosterID] = points;
    g_Minigame.miniGameCurrentPoints[g_Minigame.rosterID] += (s16)points;
    if (!g_d_GameSettings.exhibitionMatchInd && g_Minigame.rosterID == lbl_3_common_bss_37400._40) {
        fn_3_1608F0(0, points, g_Minigame.bOD_KingBombInd);
    }
}

// .text:0x00110AD4 size:0x564 mapped:0x8074FB68
void fn_3_110AD4(void) {
    Vec pos;
    f32 x;
    int i;
    int horizontal;
    int vertical;
    int type;

    if (!g_Minigame.bODRelated3) {
        for (i = 9; i > 0; i--) {
            g_Minigame._1AA0[g_Minigame.rosterID][i] = g_Minigame._1AA0[g_Minigame.rosterID][i - 1];
        }
        g_Minigame._1AA0[g_Minigame.rosterID][0] = g_Minigame.bODAngleIndexBasedOnHitPower;
        pos.x = g_Ball.AtBat_Contact_BallPos.x;
        pos.y = -g_Ball.AtBat_Contact_BallPos.y;
        pos.z = g_Ball.AtBat_Contact_BallPos.z;
        g_Minigame.bB_bombBarrelHitInd = fn_3_9FB8C(pos.x, pos.z);
        g_Minigame.bB_bombBarrelID = fn_3_9FB8C(g_Ball.ballDistanceFromHome, -pos.y);
        if (g_Pitcher.starPitchInd) {
            fn_3_BC6D8(&pos, &fn_80052768_getCamera(0)->eye, RandomInt_Game_Range(0, 3), TRUE);
        } else if (g_Minigame.bOD_KingBombInd) {
            fn_3_BC6D8(&pos, &fn_80052768_getCamera(0)->eye, 13, TRUE);
        } else {
            fn_3_BC6D8(&pos, &fn_80052768_getCamera(0)->eye, RandomInt_Game_Range(8, 12), TRUE);
        }
        g_Minigame.bODRelated3 = 1;
        g_Minigame._1DF7 = 1;
        g_Minigame._18A0 = 1;
        g_Minigame._18A6 = RandomInt_Game_Range(lbl_3_data_213E0[0], lbl_3_data_213E0[1]);
        if (g_Pitcher.starPitchInd) {
            g_Minigame.bODControllerInputAllowedInd = 0;
        } else if (g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] <= 1 || g_Minigame.bOD_KingBombInd) {
            g_Minigame.bODControllerInputAllowedInd = 1;
            g_Minigame._1DF8 = 1;
        } else {
            g_Minigame.bODControllerInputAllowedInd = 0;
        }
        fn_3_155288();
        for (i = 0; i < 10; i++) {
            if (g_Minigame._1A96[i] == 0) {
                g_Minigame._1A96[i] = lbl_3_data_21448[8];
                break;
            }
        }
    } else if (!g_Minigame.bODControllerInputAllowedInd) {
        if (--g_Minigame._18A6 > 0) {
            return;
        }
        horizontal = rand() % lbl_3_data_21448[5];
        if (rand() & 1) {
            horizontal = -horizontal;
        }
        horizontal += g_Minigame.bB_bombBarrelHitInd;
        vertical = rand() % lbl_3_data_21448[6];
        if (rand() & 1) {
            vertical = -vertical;
        }
        vertical += g_Minigame.bB_bombBarrelID;
        getComponentsFromSAng(horizontal, &pos.x, &pos.z);
        getComponentsFromSAng(vertical, &x, &pos.y);
        pos.y = pos.y / x;
        pos.x *= lbl_3_data_21438[3];
        pos.z *= lbl_3_data_21438[3];
        pos.y *= -lbl_3_data_21438[3];
        if (g_Pitcher.starPitchInd) {
            fn_3_BC6D8(&pos, &fn_80052768_getCamera(0)->eye, RandomInt_Game_Range(0, 3), TRUE);
        } else if (g_Minigame._18A0 & 1) {
            fn_3_BC6D8(&pos, &fn_80052768_getCamera(0)->eye, RandomInt_Game_Range(4, 7), TRUE);
        } else {
            fn_3_BC6D8(&pos, &fn_80052768_getCamera(0)->eye, RandomInt_Game_Range(8, 12), TRUE);
        }
        g_Minigame._18A6 = RandomInt_Game_Range(lbl_3_data_213E0[2], lbl_3_data_213E0[3]);
        g_Minigame._18A0++;
        if (g_Pitcher.starPitchInd) {
            if (g_Minigame._18A0 >= 10) {
                g_Minigame.bODControllerInputAllowedInd = 1;
                g_Minigame._1DF8 = 1;
            }
        } else if (g_Minigame._18A0 >= g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] ||
                   g_Minigame._18A0 >= lbl_3_data_21448[7]) {
            g_Minigame.bODControllerInputAllowedInd = 1;
            g_Minigame._1DF8 = 1;
        }
        for (i = 0; i < 10; i++) {
            if (g_Minigame._1A96[i] == 0) {
                g_Minigame._1A96[i] = lbl_3_data_21448[8];
                break;
            }
        }
    }
}

// .text:0x00110A38 size:0x9C mapped:0x8074FACC
int fn_3_110A38(void) {
    if (g_Pitcher.starPitchInd) {
        switch (g_Pitcher.starPitchType) {
        case 1:
            return 20;
        default:
            return 20;
        }
    }
    return 35.0f + -0.18867925f * (g_Minigame.minigamePitchSpeedAdjustment - 138.0f);
}

// .text:0x00110A04 size:0x34 mapped:0x8074FA98
void fn_3_110A04(void) {
    memset(g_Minigame._1D7C, 0, 0x78);
}

// .text:0x00110634 size:0x3D0 mapped:0x8074F6C8
void fn_3_110634(void) {
    return;
}
