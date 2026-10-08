#include "game/rep_13B8.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_140.h"
#include "game/rep_1188.h"
#include "game/rep_1838.h"
#include "game/rep_3DA8.h"
#include "game/rep_3E58.h"
#include "game/rep_720.h"
#include "game/m_sound.h"
#include "game/rep_D0.h"
#include "game/rep_18E8.h"
#include "game/rep_31A0.h"
#include "game/rep_AC8.h"
#include "game/rep_CC8.h"
#include "game/rep_DB8.h"
#include "static/UnknownHomes_Static.h"

extern struct {
    /* 0x00 */ u8 _00[0x9C];
    /* 0x9C */ s16 _9C;
} g_Scores;

extern struct {
    /* 0x00 */ s16 _00;
    /* 0x02 */ s16 _02;
    /* 0x04 */ s16 _04;
    /* 0x06 */ s16 _06[4];
    /* 0x0E */ s16 _0E;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16[0x1F - 0x16];
    /* 0x1F */ s8 _1F;
} g_RunningLogic;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

typedef struct {
    /* 0x000 */ f32 _000;
    /* 0x004 */ u8 _004[0x14 - 0x4];
    /* 0x014 */ VecXYZ _14;
    /* 0x020 */ u8 _020[0x70 - 0x20];
    /* 0x070 */ f32 _70;
    /* 0x074 */ u8 _074[0x7C - 0x74];
    /* 0x07C */ f32 _7C;
    /* 0x080 */ u8 _080[0xE8 - 0x80];
    /* 0x0E8 */ f32 _E8;
    /* 0x0EC */ u8 _0EC[0x100 - 0xEC];
    /* 0x100 */ f32 _100;
    /* 0x104 */ u8 _104[0x178 - 0x104];
    /* 0x178 */ s16 _178;
    /* 0x17A */ u8 _17A[0x1C9 - 0x17A];
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA[0x1E7 - 0x1CA];
    /* 0x1E7 */ u8 _1E7;
    /* 0x1E8 */ u8 _1E8[0x211 - 0x1E8];
    /* 0x211 */ u8 _211;
    /* 0x212 */ u8 _212[2];
    /* 0x214 */ u8 _214;
    /* 0x215 */ u8 _215[0x268 - 0x215];
} Unk13B8Fielder; // size: 0x268

extern Unk13B8Fielder g_Fielders[9];

extern struct {
    /* 0x0000 */ u8 _0000[0x2C74];
    /* 0x2C74 */ struct UnkPlayer3E58* _2C74[4];
} lbl_8036E548;

extern u8 bodyCheckProbabiliities[][5];

extern int fn_3_6D658(int team, int charID, int otherCharID);

extern s16 lbl_3_data_1C58[5][4];
extern s16 lbl_3_data_1C80[4];
extern s16 lbl_3_data_1C88[4];
extern struct {
    /* 0x000 */ u8 _000[0x1D5];
    /* 0x1D5 */ u8 _1D5;
} lbl_3_common_bss_34C90;

extern VecXZ lbl_3_data_4290[7][2];
extern VecXZ lbl_3_data_4444[5];
extern s16 lbl_3_data_4638[4];
extern s16 lbl_3_data_49DC[44];
extern VecXZ lbl_3_data_4A34[4];
extern VecXZ lbl_3_data_4A54[2][13];
extern s16 lbl_3_data_4B40[2];
extern f32 lbl_3_data_4B44;
extern f32 lbl_3_data_4B24;
extern VecXZ lbl_3_data_4B28[3];
extern s16 lbl_3_data_4B48[4];
extern f32 lbl_3_data_4B50;
extern s16 lbl_3_data_4B54;
extern VecXYZ lbl_3_data_4B58[4];
extern f32 lbl_3_data_4B88[2];
extern s16 lbl_3_data_4B90[4];
extern f32 lbl_3_data_4C44[4];
extern u8 lbl_3_data_7760[54][5];
extern s16 lbl_3_data_4C54[12];
extern f32 lbl_3_data_218BC[18];
extern s16 lbl_3_data_21904[12];
extern f32 lbl_3_data_2191C[2];

// .text:0x0008A958 size:0x73C mapped:0x806C99EC
// 97.75%: as in fn_3_7DD6C, the target keeps g_Runners in a saved register for the inlined
// fn_3_889FC; the inlined fn_3_8A618 loop also has r5 and r6 swapped.
void fn_3_8A958(void) {
    int i;

    fn_3_87424();
    fn_3_8679C();
    if (g_GameLogic.gameStatus == 1) {
        fn_3_8A7B4();
    } else if (g_GameLogic.gameStatus == 2) {
        fn_3_8A618();
    }
    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];

        if (r->runnerOnFieldOrOutOrScored != 0) {
            fn_3_833EC(i);
            r->distanceFromBall = VEC_DISTANCE_XZ(&g_Ball.AtBat_Contact_BallPos, &r->position);
        }
    }
    fn_3_87AE8();
    if (g_GameLogic.secondaryGameMode == 6) {
        fn_3_87CC8();
    } else {
        fn_3_88408();
        fn_3_88B18();
        fn_3_889FC();
        fn_3_87E80();
    }
    fn_3_8781C();
}

// .text:0x0008A7B4 size:0x1A4 mapped:0x806C9848
void fn_3_8A7B4(void) {
    if (g_GameLogic.battingAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam] != 0) {
        fn_3_85CB0();
    } else {
        fn_3_7EA68();
    }
    fn_3_86EF8();
}

// .text:0x0008A618 size:0x19C mapped:0x806C96AC
// 97.94%: the loop's constants 0 and 1 are in swapped registers (r6 and r0 in the target)
void fn_3_8A618(void) {
    int i;
    u8 steal;

    if (g_GameLogic.gameStatus == 2 && g_GameLogic.FrameCountOfCurrentPitch < g_RunningLogic._14 &&
        g_GameLogic.secondaryGameMode != 14 && g_FieldingLogic._107 == 0) {
        return;
    }
    if (g_FieldingLogic._10E != 0) {
        return;
    }
    if (g_GameLogic.battingAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam] == 0) {
        fn_3_7E2BC();
    } else {
        fn_3_83714();
    }
    steal = g_FieldingLogic._107;
    for (i = 0; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored != 0) {
            if (steal == 1 && g_Runners[i].stealingStatus != 0 && g_Runners[i].rosterID >= 0) {
                g_Runners[i].runningDirectionDesired = 1;
            }
            g_Runners[i].stealingStatus = 0;
        }
    }
}

// .text:0x0008A5A4 size:0x74 mapped:0x806C9638
void fn_3_8A5A4(void) {
    int i;

    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        r->rosterID = -1;
        r->_121 = 10;
        r->delayBeforeStartingToRun = 30;
        r->leadoffDistancePercent = 0.1f;
        r->someCollisionCheck = 0;
    }
}

// .text:0x0008A4E4 size:0xC0 mapped:0x806C9578
void fn_3_8A4E4(void) {
    int i;

    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        r->position.x = lbl_3_data_4A34[i].x;
        r->position.z = lbl_3_data_4A34[i].z;
        r->velocity.x = 0.0f;
        r->velocity.y = 0.0f;
        r->velocity.z = 0.0f;
        r->startingBase_baseAchieved = i;
        r->currentBase = i;
        r->nextBase = (i + 1) & 3;
        r->baseStandingOn = i;
        r->baseRunningTowards = 0xFF;
        r->leadOffStatus = 0;
    }
}

// .text:0x0008A4C8 size:0x1C mapped:0x806C955C
void fn_3_8A4C8(void) {
    g_Runners[0].position.x = g_Batter.batterPos.x;
    g_Runners[0].position.z = g_Batter.batterPos.z;
}

// .text:0x0008A350 size:0x178 mapped:0x806C93E4
void fn_3_8A350(void) {
    int i;

    for (i = 1; i < 4; i++) {
        if (g_d_GameSettings.GameModeSelected != 5 || g_d_GameSettings.bJMatchInd != 1 || g_Runners[i].rosterID < 0) {
            g_Runners[i].rosterID = -1;
            g_Runners[i].battingHand = 0;
            g_Runners[i].runnerDidntReachOnError = 0;
            g_Runners[i].pitcherWhoLetRunnerOnBase = -1;
        }
    }
    g_RunningLogic._15 = 0;
    fn_3_8A4E4();
}

// .text:0x0008A1D8 size:0x178 mapped:0x806C926C
void fn_3_8A1D8(void) {
    int i;

    fn_3_8A4E4();
    if (g_GameLogic.secondaryGameMode != 12) {
        for (i = 1; i < 4; i++) {
            InMemRunnerType* r = &g_Runners[i];
            if (r->rosterID >= 0) {
                fn_3_6D964(r->rosterID, i);
            } else {
                r->runnerOnFieldOrOutOrScored = 0;
            }
        }
    }
    fn_3_6D964(g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.homeTeamBattingInd_fieldingTeam]
                                                         [g_GameLogic.currentBatterPerTeam[g_GameLogic.homeTeamBattingInd_fieldingTeam]][0],
               0);
}

// .text:0x000899BC size:0x81C mapped:0x806C8A50
// dest[i + 1] for the runner on third writes past dest, as the target's 0x30-byte frame shows
void fn_3_899BC(void) {
    int dest[4];
    int i;

    if (g_d_GameSettings.GameModeSelected == 2 && g_Strikes.outs >= 3) {
        for (i = 0; i < 4; i++) {
            g_Runners[i].runnerOnFieldOrOutOrScored = 0;
            g_Runners[i].rosterID = -1;
        }
    }
    for (i = 0; i < 4; i++) {
        dest[i] = -1;
        g_RunningLogic._06[i] = -1;
    }
    if (g_Pitcher.strikeOutOrWalk == 2 && g_FieldingLogic._107 != 0) {
        for (i = 3; i >= 1; i--) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
                if (g_Runners[i].currentBase == i && g_Runners[i].forcedToAdvanceInd != 0) {
                    dest[i + 1] = i;
                } else {
                    dest[g_Runners[i].currentBase] = i;
                }
            }
        }
        dest[1] = 0;
        for (i = 3; i >= 0; i--) {
            fn_3_89914(dest[i], i);
        }
        return;
    }
    if (g_Ball.maybebuntOn2Strikes != 0) {
        dest[3] = 3;
        fn_3_89914(3, 3);
        dest[2] = 2;
        fn_3_89914(2, 2);
        dest[1] = 1;
        fn_3_89914(1, 1);
        return;
    }
    if (g_Pitcher.strikeOutOrWalk == 3) {
        if (g_Runners[1].runnerOnFieldOrOutOrScored == 0) {
            dest[3] = 3;
            fn_3_89914(3, 3);
            dest[2] = 2;
            fn_3_89914(2, 2);
        } else if (g_Runners[2].runnerOnFieldOrOutOrScored == 0) {
            dest[2] = 1;
            fn_3_89914(1, 2);
            dest[3] = 3;
            fn_3_89914(3, 3);
        } else {
            dest[3] = 2;
            fn_3_89914(2, 3);
            dest[2] = 1;
            fn_3_89914(1, 2);
        }
        dest[1] = 0;
        fn_3_89914(0, 1);
        return;
    }
    if (g_Ball.deadBallReason == 3) {
        dest[3] = 1;
        fn_3_89914(1, 3);
        dest[2] = 0;
        fn_3_89914(0, 2);
        dest[1] = -1;
        fn_3_89914(-1, 1);
        return;
    }
    if (g_Ball.deadBallReason == 4) {
        if (g_Runners[1].baseReachedAtTimeOfThrow >= 0 && g_Runners[1].runnerOnFieldOrOutOrScored == 1 &&
            g_Runners[1].baseReachedAtTimeOfThrow == 1) {
            dest[3] = 1;
        }
        if (g_Runners[0].baseReachedAtTimeOfThrow >= 0 && g_Runners[0].runnerOnFieldOrOutOrScored == 1) {
            int base = g_Runners[0].baseReachedAtTimeOfThrow + 2;
            if (base < 4) {
                if (dest[3] >= 0 && base == 3) {
                    base--;
                }
                dest[base] = 0;
            }
        }
        for (i = 3; i >= 1; i--) {
            fn_3_89914(dest[i], i);
        }
        return;
    }
    for (i = 0; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
            dest[g_Runners[i].currentBase] = i;
        }
    }
    for (i = 3; i >= 1; i--) {
        fn_3_89914(dest[i], i);
    }
}

// .text:0x00089914 size:0xA8 mapped:0x806C89A8
void fn_3_89914(int from, int to) {
    InMemRunnerType* src = &g_Runners[from];
    InMemRunnerType* dst = &g_Runners[to];

    if (from >= 0 && from <= 3) {
        if (g_GameLogic.secondaryGameMode == 15 && from == 0) {
            dst->rosterID = g_Practice.rosterID;
        } else {
            dst->rosterID = src->rosterID;
            dst->battingHand = src->battingHand;
            dst->runnerDidntReachOnError = src->runnerDidntReachOnError;
            dst->pitcherWhoLetRunnerOnBase = src->pitcherWhoLetRunnerOnBase;
        }
        g_RunningLogic._06[from] = to;
    } else {
        dst->rosterID = -1;
        dst->runnerDidntReachOnError = 0;
        dst->pitcherWhoLetRunnerOnBase = -1;
    }
}

// .text:0x000898BC size:0x58 mapped:0x806C8950
void fn_3_898BC(int runner, int rosterID) {
    InMemRunnerType* r = &g_Runners[runner];

    r->rosterID = rosterID;
    r->battingHand = inMemRoster[g_GameLogic.teamBatting][rosterID].stats.FieldingArm;
    if (r->battingHand == 2) {
        r->battingHand = 0;
    }
}

// .text:0x00089864 size:0x58 mapped:0x806C88F8
void fn_3_89864(int runner, int bases) {
    InMemRunnerType* r = &g_Runners[runner];

    r->currentBase += bases;
    r->nextBase = (r->currentBase + 1) & 3;
    if (r->currentBase >= 4) {
        r->runnerOnFieldOrOutOrScored = 3;
        g_Scores._9C++;
    }
}

// .text:0x0008913C size:0x728 mapped:0x806C81D0
// 99.17%: registers differ after the first loop (the AI and running-logic stores, the position copies)
void fn_3_8913C(void) {
    int i;
    InMemRunnerType* r;

    g_RunningLogic._02 = 0;
    g_RunningLogic._00 = 0;
    g_RunningLogic._10 = 0;
    g_RunningLogic._14 = 20;
    g_RunningLogic._1F = -1;
    g_Runners[0].position.x = g_Batter.batterPos.x;
    g_Runners[0].position.z = g_Batter.batterPos.z;
    for (i = 0; i < 4; i++) {
        r = &g_Runners[i];
        if (r->rosterID >= 0) {
            r->runnerOnFieldOrOutOrScored = 1;
            g_RunningLogic._02 |= 1 << (i * 4);
            g_RunningLogic._00 |= 1 << (i * 4);
            g_RunningLogic._10++;
        } else {
            r->runnerOnFieldOrOutOrScored = 0;
        }
        r->baseStandingOn = -1;
        r->currentBase = i;
        r->nextBase = (i + 1) & 3;
        r->tagUpInd = 0;
        r->restrictedMovementCodes = 0;
        r->relatedToRunnerPos = 0;
        r->outType = 0;
        r->forceOutCd = 0;
        r->isEligibleToScore = 1;
        r->furthestBaseForcedToGoToOnWalk = 0;
        r->framesSinceStealStarted = 0;
        r->batterStayInBattersBoxReason = 0;
        r->baseOfFailedBodyCheck = -1;
        r->timeStandingOnBase = 0;
        r->framesSinceOut = 0;
        r->baseNumberEarned_NotIncludingFieldersChoice = -1;
        r->stealingStatus = 0;
        r->framesSinceStealInput = 0;
        r->unused_someBaseNum = -1;
        r->unused_const_1 = 1;
        r->stamina = lbl_3_data_4C54[9];
        r->staminaMult = 1.0f;
        r->accelerationStaminaEffect = 1.0f;
        r->accelerationStaminaEffectWhileChangingDirection = 1.0f;
        if (i == 0) {
            r->runningAngle = PI;
        }
        if (i >= 1) {
            r->runningAngle = lbl_3_data_4B58[i].x;
        }
        r->distanceFromBall = VEC_DISTANCE_XZ(&g_Ball.AtBat_Contact_BallPos, &r->position);
        r->groundVelocity[0] = 0.0f;
        r->groundVelocity[1] = 0.0f;
        r->groundVelocity[2] = 0.0f;
        r->groundVelocity[3] = 0.0f;
        r->acceleration = 0.0f;
        r->percentRanPerFrame_slideAdj = 0.0f;
        r->slidingAdjustment_backwards = 0.03f;
        r->slidingAdjustment_forwards = 0.03f;
        r->roundingStrengthPercent = 0.0f;
        r->mashVeloAdjustment = 0.0f;
        r->mashPercent = 0.0f;
        r->actionFrames_countUp = 0;
        r->actionFrames_countDown = 0;
        r->_110 = 0;
        r->framesSinceLastDirectionChange = 0;
        r->slideHomeFrames_CountDown = 0;
        r->runningDirectionDesired = 0;
        r->nextDirectionBeingProcessed = 0;
        r->runningDirectionCode = 0;
        r->offsetFromNormalRunningPathInd = 0;
        r->actionCode = 0;
        r->actionStage = 0;
        r->forceOutType_unsed = 0;
        r->baseRoundingState = 0;
        r->overrun1st_doneChecking = 0;
        r->overRun1BStage = 0;
        r->overrunning1BIndicator = 0;
        r->overrunBaseStage = 0;
        r->offsetPositionForRoundingInd = 0;
        r->roundingInitiaializedInd = 0;
        r->runningToDugoutInd = 0;
        r->runningToDugoutStage = 0;
        r->turnaroundCode = 0;
        r->turningAroundInd = 0;
        r->framesSinceLastMash = 0;
        r->someCountdown_unused = 0;
        r->_151 = 0;
        r->scoredOnGRD = 0;
        if (r->rosterID >= 0) {
            r->runningDirectionCode = 2;
        }
        r->runnerDirectionCode_stored = r->runningDirectionCode;
        if (r->leadOffStatus == 0) {
            if (g_GameLogic.secondaryGameMode == 14) {
                r->leadOffStatus = 0;
            } else {
                r->leadOffStatus = 1;
            }
            r->leadoffDurationFrames = 0;
            r->leadOffTotalFrameCountDown = 45;
            fn_3_810C4(i, i);
        }
    }
    g_AiLogic._77 = 0;
    g_RunningLogic._12 = g_RunningLogic._10;
    g_AiLogic._44 = lbl_3_data_1C58[g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.homeTeamBattingInd_fieldingTeam]][1];
    g_RunningLogic._15 = 0;
    if (g_RunningLogic._02 & 0x1000) {
        g_RunningLogic._15 = 1;
    }
    if (g_RunningLogic._02 & 0x100) {
        g_RunningLogic._15++;
    }
    for (i = 1; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 0) {
            g_Runners[i].forcedToAdvanceInd = 0;
        } else if (g_Runners[i - 1].forcedToAdvanceInd != 0) {
            g_Runners[i].forcedToAdvanceInd = 1;
        } else {
            g_Runners[i].forcedToAdvanceInd = 0;
        }
    }
    g_Runners[0].forcedToAdvanceInd = 1;
    g_Runners[0].unused_AIRelated = 1;
    g_Runners[0].battingHand = g_Batter.batterHand;
    g_Runners[0].runnerDidntReachOnError = 1;
    g_Runners[0].pitcherWhoLetRunnerOnBase =
        g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0];
    g_Runners[0].batterStayInBattersBoxReason = 1;
    g_Runners[0].position.x = g_Batter.batterPos.x;
    g_Runners[0].position.y = 0.0f;
    g_Runners[0].position.z = g_Batter.batterPos.z;
    g_Runners[0].positionStored.x = g_Batter.batterPos.x;
    g_Runners[0].positionStored.y = 0.0f;
    g_Runners[0].positionStored.z = g_Batter.batterPos.z;
    for (i = 1; i < 4; i++) {
        g_Runners[i].positionStored.x = g_Runners[i].position.x;
        g_Runners[i].positionStored.y = g_Runners[i].position.y;
        g_Runners[i].positionStored.z = g_Runners[i].position.z;
    }
    if (g_Batter.batterHand == 0) {
        g_RunningLogic._0E = (int)(28.0f / g_Runners[0].maximumBaseVelocity) + 35;
    } else {
        g_RunningLogic._0E = (int)(26.5f / g_Runners[0].maximumBaseVelocity) + 35;
    }
    g_RunningLogic._0E += 20;
    g_Batter.runnersOnBase = 0;
    g_Batter.chemLinksOnBase = 0;
    for (i = 1; i < 4; i++) {
        r = &g_Runners[i];
        if (r->rosterID >= 0 && fn_3_6D658(g_GameLogic.teamBatting, g_Batter.charID, r->charID) >= lbl_3_data_4638[3]) {
            g_Batter.chemLinksOnBase++;
            g_Batter.runnersOnBase |= 1 << (i - 1);
        }
    }
}

// .text:0x0008911C size:0x20 mapped:0x806C81B0
void fn_3_8911C(void) {
    g_Runners[0].leadOffStatus = 0;
    g_Runners[1].leadOffStatus = 0;
    g_Runners[2].leadOffStatus = 0;
    g_Runners[3].leadOffStatus = 0;
}

// .text:0x00089028 size:0xF4 mapped:0x806C80BC
void fn_3_89028(void) {
    int i;

    g_Runners[0].leadOffStatus = 0;
    g_Runners[1].leadOffStatus = 0;
    g_Runners[2].leadOffStatus = 0;
    g_Runners[3].leadOffStatus = 0;
    for (i = 1; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        r->unused_AIRelated = 0;
        r->tagUpInd = 0;
        if (r->runnerOnFieldOrOutOrScored == 1) {
            fn_3_85EF4(i, 1);
        }
    }
    if (g_Strikes.balls >= 4) {
        g_Runners[0].runnerOnFieldOrOutOrScored = 5;
    } else if (g_FieldingLogic._107 == 4) {
        g_Runners[0].runnerOnFieldOrOutOrScored = 1;
        fn_3_85EF4(0, 1);
    } else {
        g_Runners[0].runnerOnFieldOrOutOrScored = 4;
    }
}

// .text:0x00088F98 size:0x90 mapped:0x806C802C
void fn_3_88F98(void) {
    int i;

    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        if (i == 0) {
            fn_3_85EF4(i, 1);
        }
        if (i == 0) {
            r->unused_AIRelated = 1;
        } else {
            r->unused_AIRelated = 0;
            if (g_Strikes.storedOuts < 2) {
                r->tagUpInd = 1;
            } else {
                r->tagUpInd = 0;
            }
        }
    }
}

// .text:0x00088D88 size:0x210 mapped:0x806C7E1C
void fn_3_88D88(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    int i;

    if (g_Strikes.outs < 3 && g_GameLogic.EventTriggers_EndOfGame == 0 && r->runnerOnFieldOrOutOrScored == 1) {
        if (g_GameLogic.freeFieldingPracticeInd == 0) {
            g_Strikes.outs++;
        } else if ((g_Practice.practiceType_2 == 2 && g_Practice.practiceLevel == 1) || g_Practice.practiceLevel == 7 ||
                   g_Practice.practiceLevel == 6) {
            g_Strikes.outs++;
        }
        if (g_Ball.maybeBuntInd != 0 && g_Strikes.strikes >= 3) {
            fn_3_59918(22, 0);
        } else if (r->fractionalBasesRan >= 3.8f && g_Ball.baseBallAndFielderAreOn == 0) {
            fn_3_59918(1, 1);
        } else {
            fn_3_59918(1, 0);
        }
        for (i = 0; i < 3; i++) {
            if (g_Strikes.runnerIndexForEachOutThisPitch[i] == -1) {
                g_Strikes.runnerIndexForEachOutThisPitch[i] = runner;
                break;
            }
        }
        if (g_Strikes.outs == 3) {
            if (r->forceOutCd == 1) {
                g_Strikes.forcedOutToEndInningInd = 1;
            } else {
                fn_3_5C74C(1);
            }
            fn_3_5D094(0);
            if (g_GameLogic.EventTriggers_EndOfGame != 0) {
                fn_3_59918(13, 0);
            } else {
                fn_3_59918(5, 0);
            }
        }
        r->runnerOnFieldOrOutOrScored = 2;
    }
}

// .text:0x00088C24 size:0x164 mapped:0x806C7CB8
// 98.65%: only the registers of the inlined fn_3_889FC differ
void fn_3_88C24(void) {
    fn_3_87AE8();
    if (g_GameLogic.secondaryGameMode == 6) {
        fn_3_87CC8();
    } else {
        fn_3_88408();
        fn_3_88B18();
        fn_3_889FC();
        fn_3_87E80();
    }
    fn_3_8781C();
}

// .text:0x00088B18 size:0x10C mapped:0x806C7BAC
void fn_3_88B18(void) {
    int i;
    int state = 0;

    if (g_FieldingLogic._107 != 0 && g_FieldingLogic._107 != 4) {
        state = 1;
    }
    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        if (r->forceOutCd == 2) {
            state = 2;
            continue;
        }
        r->forceOutCd = 0;
        if (g_Ball.AtBat_ContactResult < 0 || g_FieldingLogic._108 != 0) {
            continue;
        }
        if (state != 0) {
            if (r->runnerOnFieldOrOutOrScored == 0) {
                state = 1;
            }
            if (state == 2 && r->startingBase_baseAchieved == r->currentBase) {
                r->forceOutCd = -1;
            }
        } else if (r->runnerOnFieldOrOutOrScored == 1) {
            if (r->baseStandingOn >= 0 && r->baseStandingOn == ((r->startingBase_baseAchieved + 1) & 3)) {
                continue;
            }
            if (r->startingBase_baseAchieved == r->currentBase) {
                r->forceOutCd = 1;
            }
        } else {
            state = 1;
        }
    }
}

// .text:0x000889FC size:0x11C mapped:0x806C7A90
void fn_3_889FC(void) {
    InMemRunnerType* r = g_Runners;
    int result = g_Ball.AtBat_ContactResult;
    u8 fielding = g_FieldingLogic._108;
    u8 landingZone = g_Ball.landingSpotZoneAwayFromHome;
    u8 ballZone = g_Ball.ballZoneAwayFromHome;
    u8 ballState = g_Ball.ballState;
    int i;

    for (i = 0; i < 4; r++, i++) {
        if (r->runnerOnFieldOrOutOrScored == 1) {
            if ((result == 3 || fielding == 2) && landingZone <= 1) {
                r->isEligibleToScore = 0;
            } else if (ballZone <= 1 && ballState != 0 && (u16)result > 1) {
                if (r->currentBase != 0 && r->currentBase < 3) {
                    r->isEligibleToScore = 0;
                }
            }
        }
    }
}

// Credits the throwing fielder with the out
static inline void creditThrowOut(void) {
    if (g_d_GameSettings.exhibitionMatchInd == 0 && lbl_3_common_bss_37400._40 == g_GameLogic.teamFielding &&
        g_Ball.throwingFielder >= 0 && g_FieldingLogic._141 != 0) {
        fn_3_161588(8, g_Fielders[g_Ball.throwingFielder]._178);
    }
}

// .text:0x00088408 size:0x5F4 mapped:0x806C749C
void fn_3_88408(void) {
    InMemRunnerType* r;
    int i;

    if (g_Strikes.outs < 3) {
        if (g_Ball.AtBat_ContactResult == 1 || g_Ball.AtBat_ContactResult == -1 || g_Ball.AtBat_ContactResult == 2) {
            g_Runners[0].tagUpInd = 0;
            g_Runners[1].tagUpInd = 0;
            g_Runners[2].tagUpInd = 0;
            g_Runners[3].tagUpInd = 0;
        }
        if (g_Ball.AtBat_ContactResult != -1) {
            if (g_FieldingLogic._0E8 >= 0 && g_FieldingLogic._0E8 <= 3) {
                r = &g_Runners[g_FieldingLogic._0E8];
            }
            if (g_Ball.AtBat_ContactResult == 3 || g_FieldingLogic._108 == 2) {
                fn_3_88D88(0);
                g_Runners[0].outType = 1;
                if (g_Ball.fielderWhoGotLastOut < 0) {
                    g_Ball.fielderWhoGotLastOut = g_Ball.fielderWBallIndex;
                }
            }
            if (g_FieldingLogic._116 != 0 && g_FieldingLogic._111 == 1 && r->tagUpInd != 2) {
                if (r->baseOfFailedBodyCheck >= 0) {
                    fn_3_88D88(g_FieldingLogic._0E8);
                    r->outType = 3;
                    g_FieldingLogic._0E8 = -1;
                    g_FieldingLogic._111 = 0;
                    if (g_Ball.fielderWhoGotLastOut < 0) {
                        g_Ball.fielderWhoGotLastOut = g_Ball.fielderWithBallIndexStored2;
                        if (g_Ball.fielderWithBallIndexStored2 >= 6 && r->baseOfFailedBodyCheck == 0 &&
                            g_Ball.numberOfThrowsDuringPlay == 2 && g_Ball.timeSinceBallPickedUp < lbl_3_data_49DC[39]) {
                            g_UnkSound_32718._08 = 4;
                            g_FieldingLogic._134 = g_Ball.fielderWithBallIndexStored2;
                            if (g_d_GameSettings.exhibitionMatchInd == 0 &&
                                lbl_3_common_bss_37400._40 == g_GameLogic.teamFielding) {
                                fn_3_161588(2, g_Fielders[g_Ball.fielderWithBallIndexStored2]._178);
                            }
                        }
                    }
                    creditThrowOut();
                }
            } else if (g_FieldingLogic._111 >= 2 && g_FieldingLogic._111 <= 5 && g_FieldingLogic._112 == 2) {
                if (r->tagUpInd == 2) {
                    fn_3_88D88(g_FieldingLogic._0E8);
                    r->outType = 4;
                    g_FieldingLogic._0E8 = -1;
                    creditThrowOut();
                } else if ((r->baseStandingOn < 0 || r->forceOutCd == 1) &&
                           (r->actionStage == 0 || r->actionFrames_countDown >= 15)) {
                    fn_3_88D88(g_FieldingLogic._0E8);
                    if (r->forceOutCd == 1) {
                        r->forceOutCd = 2;
                    }
                    r->outType = 3;
                    g_FieldingLogic._0E8 = -1;
                    if (g_Ball.fielderWhoGotLastOut < 0) {
                        g_Ball.fielderWhoGotLastOut = g_Ball.fielderWithBallIndexStored2;
                    }
                    creditThrowOut();
                }
                g_FieldingLogic._111 = 0;
                g_FieldingLogic._112 = 0;
                g_FieldingLogic._0CC = -1;
            }
            if (g_Ball.baseBallAndFielderAreOn >= 1 && g_Runners[g_Ball.baseBallAndFielderAreOn].tagUpInd == 2) {
                fn_3_88D88(g_Ball.baseBallAndFielderAreOn);
                g_Runners[g_Ball.baseBallAndFielderAreOn].outType = 4;
                creditThrowOut();
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 2) {
            if (g_Runners[i].framesSinceOut < 0x7FFE) {
                g_Runners[i].framesSinceOut++;
            } else {
                g_Runners[i].framesSinceOut = 0x7FFF;
            }
        }
    }
}

// .text:0x00088228 size:0x1E0 mapped:0x806C72BC
void fn_3_88228(void) {
    if (g_Ball.baseBallAndFielderAreOn >= 0 && g_Ball.AtBat_ContactResult >= 0 && g_Ball.AtBat_ContactResult != 3 &&
        g_Fielders[g_Ball.fielderWBallIndex]._1E7 == 0) {
        int runner = (g_Ball.baseBallAndFielderAreOn + 3) & 3;
        if (g_Runners[runner].forceOutCd == 1) {
            fn_3_88D88(runner);
            g_Runners[runner].forceOutCd = 2;
            g_Runners[runner].outType = 2;
            if (g_Ball.fielderWhoGotLastOut < 0) {
                if (g_Ball.throwingFielder < 0) {
                    g_Ball.fielderWhoGotLastOut = g_Ball.fielderWBallIndex;
                } else {
                    g_Ball.fielderWhoGotLastOut = g_Ball.throwingFielder;
                    if (g_FieldingLogic._141 != 0 && g_d_GameSettings.exhibitionMatchInd == 0 &&
                        lbl_3_common_bss_37400._40 == g_GameLogic.teamFielding) {
                        fn_3_161588(8, g_Fielders[g_Ball.throwingFielder]._178);
                    }
                    if (g_FieldingLogic._115 > 0 && g_FieldingLogic._133 != 0) {
                        g_UnkSound_32718._08 = 4;
                        g_FieldingLogic._134 = g_Ball.fielderWithBallIndexStored2;
                        if (g_d_GameSettings.exhibitionMatchInd == 0 && lbl_3_common_bss_37400._40 == g_GameLogic.teamFielding) {
                            fn_3_161588(2, g_Fielders[g_Ball.fielderWithBallIndexStored2]._178);
                        }
                    }
                }
            }
        }
    }
}

// .text:0x00087E80 size:0x3A8 mapped:0x806C6F14
void fn_3_87E80(void) {
    int i;
    f32 angle;
    f32 heading;

    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        if (r->runnerOnFieldOrOutOrScored != 0) {
            angle = r->runningAngle;
            heading = atan2(-r->velocity.x, -r->velocity.y);
            if (g_GameLogic.secondaryGameMode == 6) {
                goto standard;
            }
            if (i == 0 && (r->batterStayInBattersBoxReason == 1 ||
                           (g_Pitcher.strikeOutOrWalk == 1 && g_FieldingLogic._107 != 4))) {
                angle = PI;
            } else if (i == 0 && g_Batter.hitTrajectory != 0 && r->batterStayInBattersBoxReason != 0) {
                if (r->groundVelocity[0] >= 0.01f) {
                    angle = heading;
                } else {
                    angle = PI;
                }
            } else if (i == 0 && (g_FieldingLogic._107 == 1 || g_FieldingLogic._107 == 2) && g_Strikes.outs < 3) {
                angle = PI;
            } else if (r->actionCode != 0) {
                if (r->actionStage == 2 && r->actionFrames_countDown <= 1) {
                    angle = lbl_3_data_4B58[r->baseStandingOn].x;
                }
            } else if (r->overRun1BStage >= 2) {
                angle = atan2(-r->velocity.x, -r->velocity.z);
            } else if (r->baseRoundingState == 2 && r->baseStandingOn >= 0) {
                angle = atan2(-r->velocity.x, -r->velocity.z);
            } else if (r->leadOffStatus == 1) {
                angle = atan2(-r->velocity.x, -r->velocity.z);
            } else if (r->runningToDugoutInd != 0) {
                if (r->runningToDugoutInd == 2 && r->slideHomeFrames_CountDown != 0) {
                    angle = r->runningAngle;
                } else if (0.0f == r->velocity.x) {
                    angle = r->runningAngle;
                } else {
                    angle = atan2(-r->velocity.x, -r->velocity.z);
                }
            } else {
            standard:
                if (r->runningDirectionCode != 0 && r->runningDirectionCode != 2) {
                    if (r->leadOffStatus == 2) {
                        angle = lbl_3_data_4B58[r->currentBase].x;
                    } else if (0.0f == r->velocity.x && 0.0f == r->velocity.z) {
                        angle = atan2(-r->velocityStored.x, -r->velocityStored.z);
                        if (r->turningAroundInd == 1 && r->runningDirectionCode == 1 && r->acceleration > 0.0f) {
                            angle = fn_3_9FEA8(PI + angle);
                        }
                    } else {
                        angle = atan2(-r->velocity.x, -r->velocity.z);
                    }
                } else {
                    angle = lbl_3_data_4B58[r->currentBase].x;
                }
            }
            r->runningAngle = angle;
            if (g_Ball.ballZoneAwayFromHome != 0) {
                angle = atan2(-(g_Ball.AtBat_Contact_BallPos.x - r->position.x), -(g_Ball.AtBat_Contact_BallPos.z - r->position.z));
            }
            r->angleToBall = angle;
        }
    }
}

// .text:0x00087CC8 size:0x1B8 mapped:0x806C6D5C
void fn_3_87CC8(void) {
    int i;
    f32 angle;

    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        // continue and the two-step fn_3_9FEA8 call keep this over -inline auto's limit, so fn_3_88C24 calls it
        if (r->runnerOnFieldOrOutOrScored == 0) {
            continue;
        }
        {
            angle = atan2(-r->velocity.x, -r->velocity.y);
            if (g_Minigame._1B15[g_Minigame._18FC[i]] == 1) {
                angle = fn_3_9FEA8(PI + atan2(-r->velocity.x, -r->velocity.z));
            } else if (r->runningDirectionCode != 0 && r->runningDirectionCode != 2) {
                if (0.0f == r->velocity.x && 0.0f == r->velocity.z) {
                    angle = atan2(-r->velocityStored.x, -r->velocityStored.z);
                    if (r->turningAroundInd == 1 && r->runningDirectionCode == 1 && r->acceleration > 0.0f) {
                        angle = PI + angle;
                        angle = fn_3_9FEA8(angle);
                    }
                } else {
                    angle = atan2(-r->velocity.x, -r->velocity.z);
                }
            } else if (0.0f == r->percentTowardsNextBase) {
                angle = lbl_3_data_4B58[r->currentBase].z;
            } else {
                angle = lbl_3_data_4B58[r->currentBase].x;
            }
            r->runningAngle = angle;
            r->angleToBall = angle;
        }
    }
}

// .text:0x00087AE8 size:0x1E0 mapped:0x806C6B7C
void fn_3_87AE8(void) {
    InMemRunnerType* batter = &g_Runners[0];
    int i;

    batter->batterStayInBattersBoxReason = 0;
    if (g_GameLogic.secondaryGameMode != 6) {
        if (g_Minigame.GameMode_MiniGame == 3) {
            batter->batterStayInBattersBoxReason = 1;
        } else if (g_Ball.framesSinceHit < 0) {
            batter->batterStayInBattersBoxReason = 1;
        } else if (g_FieldingLogic._107 == 1 || g_FieldingLogic._107 == 2 || g_FieldingLogic._107 == 3) {
            if (g_Strikes.outs < 3) {
                batter->batterStayInBattersBoxReason = 1;
            }
        } else if (batter->outType == 0 || batter->runnerOnFieldOrOutOrScored != 2) {
            if (g_Ball.framesSinceHit < batter->delayBeforeStartingToRun) {
                batter->batterStayInBattersBoxReason = 2;
            } else if (g_Batter.hitTrajectory == 4 && g_Ball.framesSinceHit < 90) {
                batter->batterStayInBattersBoxReason = 2;
            } else if (g_Batter.hitTrajectory == 3 || g_Batter.hitTrajectory == 6) {
                batter->batterStayInBattersBoxReason = 3;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        g_Runners[i].velocity.x = g_Runners[i].position.x - g_Runners[i].positionStored.x;
        g_Runners[i].velocity.y = g_Runners[i].position.y - g_Runners[i].positionStored.y;
        g_Runners[i].velocity.z = g_Runners[i].position.z - g_Runners[i].positionStored.z;
    }
}

// .text:0x0008781C size:0x2CC mapped:0x806C68B0
void fn_3_8781C(void) {
    int i;
    InMemRunnerType* r;
    VecSrcDst ray;
    CollisionStruct hit;

    g_RunningLogic._00 = 0;
    g_RunningLogic._04 = 0;
    g_RunningLogic._10 = 0;
    for (i = 0; i < 4; i++) {
        r = &g_Runners[i];
        if (r->percentTowardsNextBase > 0.2f) {
            r->relatedToRunnerPos = 0;
        }
        if (r->runnerOnFieldOrOutOrScored == 1) {
            g_RunningLogic._00 |= 1 << (i * 4);
            g_RunningLogic._10++;
            if (r->currentBase <= 3) {
                g_RunningLogic._04 |= 1 << (r->currentBase * 4);
            }
        }
        if (g_Ball.AtBat_ContactResult == -1 && r->runnerOnFieldOrOutOrScored == 1) {
            r->runnerOnFieldOrOutOrScored = 4;
        }
        if (r->baseStandingOn >= 0) {
            if (r->timeStandingOnBase < 0x7FFE) {
                r->timeStandingOnBase++;
            } else {
                r->timeStandingOnBase = 0x7FFF;
            }
        } else {
            r->timeStandingOnBase = 0;
        }
        r->nextBase = (r->currentBase + 1) & 3;
        if (r->runnerOnFieldOrOutOrScored != 0) {
            ray.src.x = r->position.x;
            ray.src.y = -1.0f;
            ray.src.z = r->position.z;
            ray.dst.x = r->position.x;
            ray.dst.y = 1.0f;
            ray.dst.z = r->position.z;
            r->someCollisionCheck = checkCollision(&ray, &hit, 0, 0);
        }
    }
    if (g_Runners[0].baseNumberEarned_NotIncludingFieldersChoice == -1) {
        u32 ballState = g_Ball.ballState;
        u32 ballZone = g_Ball.ballZoneAwayFromHome;
        // Read as unsigned, so that -1 (no zone) fails the test below; the target has no extsb
        u32 caughtZone = (u8)g_Ball.ballZoneWhenCaught;
        u32 fielding = g_FieldingLogic._10E;
        int j;

        for (j = 0; j < 4; j++) {
            r = &g_Runners[j];
            if ((ballState == 1 && ballZone <= 2) || caughtZone <= 1 || fielding != 0) {
                if (r->runnerOnFieldOrOutOrScored == 2) {
                    r->baseNumberEarned_NotIncludingFieldersChoice = r->currentBase;
                } else if (r->runnerOnFieldOrOutOrScored != 0 && r->baseStandingOn >= 0) {
                    r->baseNumberEarned_NotIncludingFieldersChoice = r->baseStandingOn;
                }
            } else if (r->runnerOnFieldOrOutOrScored == 3) {
                r->baseNumberEarned_NotIncludingFieldersChoice = 0;
            }
        }
    }
}

// .text:0x00087424 size:0x3F8 mapped:0x806C64B8
// 99.53%: only the registers of the inlined fn_3_871BC differ, as they do in fn_3_871BC itself
void fn_3_87424(void) {
    fn_3_872CC();
    if (g_GameLogic.secondaryGameMode != 6 && g_GameLogic.secondaryGameMode != 14) {
        fn_3_88228();
        fn_3_871BC();
        fn_3_870AC();
    }
}

// .text:0x000872CC size:0x158 mapped:0x806C6360
void fn_3_872CC(void) {
    int i;

    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        if (r->runnerOnFieldOrOutOrScored != 0) {
            r->baseStandingOn_Stored = r->baseStandingOn;
            r->positionStored.x = r->position.x;
            r->positionStored.y = r->position.y;
            r->positionStored.z = r->position.z;
            r->velocityStored.x = r->velocity.x;
            r->velocityStored.y = r->velocity.y;
            r->velocityStored.z = r->velocity.z;
            r->fractionalBasesRan_stored = r->fractionalBasesRan;
            r->percentTowardsNextBase_stored = r->percentTowardsNextBase;
            r->runningDirectionDesired = 0;
            r->newButtonThisFrame_forMashPurposes = 0;
            if (g_Ball.AtBat_ContactResult == 3 && g_Strikes.storedOuts < 2 && r->tagUpInd == 1) {
                r->tagUpInd = 2;
                if (r->baseStandingOn == r->startingBase_baseAchieved) {
                    r->tagUpInd = 0;
                }
            }
            if (r->someCountdown_unused != 0) {
                r->someCountdown_unused--;
                if (r->someCountdown_unused == 0) {
                    r->_151 = 0;
                }
            }
            if (g_GameLogic.gameStatus == 2) {
                r->leadOffStatus = 0;
            }
        }
    }
    if (g_Ball.framesSinceHit == 1 && g_Ball.maxYOfHit >= 5.0f && g_Ball.landingSpotZoneAwayFromHome >= 2) {
        g_RunningLogic._14 = 10;
    }
}

// .text:0x000871BC size:0x110 mapped:0x806C6250
// 96.76%: the target keeps g_Runners in r7 from the start; this copies it from r5 (one extra mr)
void fn_3_871BC(void) {
    InMemRunnerType* r = g_Runners;
    int runDrain = lbl_3_data_4C54[10];
    int turnDrain = lbl_3_data_4C54[11];
    int maxStamina = lbl_3_data_4C54[9];
    f32 speedEffect = lbl_3_data_4C44[1];
    f32 accelEffect = lbl_3_data_4C44[2];
    f32 turnEffect = lbl_3_data_4C44[3];
    int i;

    for (i = 0; i < 4; r++, i++) {
        if (r->runnerOnFieldOrOutOrScored == 1) {
            int drain = 0;
            f32 tired;

            if (r->groundVelocity[0] >= 0.1f) {
                drain = runDrain;
            }
            if (r->turnaroundCode != 0) {
                drain += turnDrain;
            }
            if (drain != 0) {
                r->stamina -= drain;
                if (r->stamina < 0) {
                    r->stamina = 0;
                }
            }
            tired = 1.0f - (f32)r->stamina / (f32)maxStamina;
            r->staminaMult = 1.0f - speedEffect * tired;
            r->accelerationStaminaEffect = 1.0f - accelEffect * tired;
            r->accelerationStaminaEffectWhileChangingDirection = 1.0f - turnEffect * tired;
        }
    }
}

// .text:0x000870AC size:0x110 mapped:0x806C6140
void fn_3_870AC(void) {
    InMemRunnerType* r;

    g_Runners[0].tagType = 0;
    g_Runners[1].tagType = 0;
    g_Runners[2].tagType = 0;
    g_Runners[3].tagType = 0;
    if ((g_FieldingLogic._111 == 2 || g_FieldingLogic._111 == 4) && g_FieldingLogic._0E8 >= 0) {
        r = &g_Runners[g_FieldingLogic._0E8];
        if (r->runnerOnFieldOrOutOrScored == 1) {
            r->tagType = 1;
        }
        if (g_FieldingLogic._0EC < 5 && r->actionCode != 0) {
            r->tagType = 2;
        }
        if (g_d_GameSettings.exhibitionMatchInd == 0 && lbl_3_common_bss_37400._40 == g_GameLogic.teamFielding) {
            fn_3_161588(6, g_Fielders[g_Ball.fielderWBallIndex]._178);
        }
    }
}

// .text:0x00086EF8 size:0x1B4 mapped:0x806C5F8C
void fn_3_86EF8(void) {
    int i;

    for (i = 1; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        if (r->runnerOnFieldOrOutOrScored != 0 && r->stealingStatus != 0) {
            if (r->framesSinceStealInput < 0xFE) {
                r->framesSinceStealInput++;
            } else {
                r->framesSinceStealInput = 0xFF;
            }
            if (g_Pitcher.pitchTotalTimeCounter > 0 && r->stealingStatus == 1) {
                if (g_Pitcher.pitchTotalTimeCounter == lbl_3_data_4B90[2]) {
                    int lo = lbl_3_data_4B90[2];
                    int hi = lbl_3_data_4B90[2];
                    lo -= lbl_3_data_4B90[1];
                    hi -= lbl_3_data_4B90[0];
                    if (r->framesSinceStealInput >= lo && r->framesSinceStealInput <= hi) {
                        r->stealingStatus = 3;
                        r->leadOffStatus = 0;
                        fn_3_7FEA8(i, 1);
                    }
                } else if (g_Pitcher.pitchTotalTimeCounter >= lbl_3_data_4B90[3]) {
                    r->stealingStatus = 2;
                    r->leadOffStatus = 0;
                    fn_3_7FEA8(i, 1);
                }
            }
            if (r->runnerOnFieldOrOutOrScored == 1) {
                if (r->runningDirectionCode == 1 && r->furthestBaseForcedToGoToOnWalk == 0) {
                    int j;
                    int forced = 1;

                    for (j = 1; j < i; j++) {
                        if (g_Runners[j].runnerOnFieldOrOutOrScored == 0) {
                            forced = 0;
                        }
                    }
                    if (forced) {
                        r->furthestBaseForcedToGoToOnWalk = i + 1;
                    } else {
                        r->furthestBaseForcedToGoToOnWalk = 1;
                    }
                }
                if (r->furthestBaseForcedToGoToOnWalk != 0) {
                    if (r->framesSinceStealStarted < 0x7FFE) {
                        r->framesSinceStealStarted++;
                    } else {
                        r->framesSinceStealStarted = 0x7FFF;
                    }
                }
            }
        }
    }
}

// .text:0x00086DFC size:0xFC mapped:0x806C5E90
void fn_3_86DFC(void) {
    int i;

    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        if (r->runnerOnFieldOrOutOrScored != 0) {
            if (g_FieldingLogic._107 == 1 && r->stealingStatus != 0) {
                fn_3_7FEA8(i, 1);
            }
            r->stealingStatus = 0;
        }
    }
}

// .text:0x0008679C size:0x660 mapped:0x806C5830
void fn_3_8679C(void) {
    f32 prevFrac = -1.0f;
    int prev = -1;
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        g_Runners[i].restrictedMovementCodes_stored = g_Runners[i].restrictedMovementCodes;
        g_Runners[i].restrictedMovementCodes = 0;
    }
    if (g_Strikes.outs >= 3) {
        return;
    }

    for (i = 3; i >= 0; i--) {
        InMemRunnerType* r = &g_Runners[i];

        if (r->runnerOnFieldOrOutOrScored != 1) {
            continue;
        }
        if (i == 1 && g_Ball.AtBat_ContactResult != 3 && g_FieldingLogic._108 == 0 && g_FieldingLogic._107 == 0 &&
            r->fractionalBasesRan <= 1.2f && g_Ball.framesSinceHit >= 1) {
            if (g_Ball.AtBat_ContactResult == 0 && g_Ball.framesUntilBallHitsGround < 120 &&
                VEC_DISTANCE_XZ(&lbl_3_data_4444[1], &g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot) < 10.0f) {
            } else if (g_Batter.hitTrajectory != 3 && g_Runners[0].runnerOnFieldOrOutOrScored != 2) {
                r->restrictedMovementCodes |= 2;
                if (r->runningDirectionCode == 3 && r->tagUpInd != 0) {
                    r->restrictedMovementCodes |= 8;
                }
            }
        } else if (i == 0 && g_Ball.AtBat_ContactResult == 0 && g_Runners[1].runnerOnFieldOrOutOrScored == 1 &&
                   g_Runners[1].fractionalBasesRan < 2.0f && g_Runners[1].runningDirectionCode == 3) {
            r->restrictedMovementCodes |= 1;
        } else if (prevFrac < 0.0f) {
            if (r->fractionalBasesRan >= 3.75f && g_GameLogic.secondaryGameMode != 14 && g_Strikes.storedOuts < 2) {
                if (r->tagUpInd != 0) {
                    r->restrictedMovementCodes |= 4;
                } else if (g_Ball.AtBat_ContactResult == 0 || g_Ball.AtBat_ContactResult == -1) {
                    r->restrictedMovementCodes |= 4;
                }
            }
        } else {
            f32 gap = prevFrac - r->fractionalBasesRan;
            InMemRunnerType* ahead = &g_Runners[prev];

            if (r->runningDirectionCode == 3) {
                gap -= 0.15f;
            } else if (r->runningDirectionCode == 2) {
                gap -= 0.1f;
            }
            if (g_Runners[prev].runningDirectionCode == 3) {
                gap -= 0.05f;
            }
            if (r->currentBase != g_Runners[prev].currentBase && g_Runners[prev].baseStandingOn < 0) {
                gap -= 0.15f;
            }
            if (gap < 0.3f) {
                r->restrictedMovementCodes |= 1;
                g_Runners[prev].restrictedMovementCodes |= 2;
                if (ahead->runningDirectionCode == 3 && ahead->tagUpInd != 0 &&
                    (g_Ball.AtBat_ContactResult == 0 || g_Ball.AtBat_ContactResult == 3)) {
                    ahead->restrictedMovementCodes |= 8;
                }
                if (ahead->percentTowardsNextBase < 0.5f && ahead->baseStandingOn == -1 &&
                    r->percentTowardsNextBase > 0.5f && r->baseStandingOn == -1) {
                    if (ahead->distToCurrentBase <= r->distToNextBase) {
                        if (ahead->runningDirectionCode == 3 && r->baseStandingOn == -1) {
                            ahead->restrictedMovementCodes &= 0xFD;
                        } else if (r->runningDirectionCode == 1 && ahead->baseStandingOn == -1) {
                            ahead->restrictedMovementCodes &= 0xFE;
                        } else if (r->baseStandingOn == -1) {
                            ahead->restrictedMovementCodes &= 0xFD;
                        } else if (ahead->baseStandingOn == -1) {
                            r->restrictedMovementCodes &= 0xFE;
                        }
                    } else if (ahead->tagUpInd != 0 && r->baseStandingOn == -1) {
                        ahead->restrictedMovementCodes &= 0xFD;
                    } else if (r->runningDirectionCode == 1 && ahead->baseStandingOn == -1) {
                        r->restrictedMovementCodes &= 0xFE;
                    } else if (ahead->runningDirectionCode == 3 && r->baseStandingOn == -1) {
                        ahead->restrictedMovementCodes &= 0xFD;
                    } else if (ahead->baseStandingOn == -1) {
                        r->restrictedMovementCodes &= 0xFE;
                    } else if (r->baseStandingOn == -1) {
                        ahead->restrictedMovementCodes &= 0xFD;
                    }
                }
            }
        }
        prevFrac = r->fractionalBasesRan;
        prev = i;
    }

    for (i = 0; i <= 1; i++) {
        InMemRunnerType* r = &g_Runners[i];
        s16 next = r->currentBase + 1;
        s16 count = 0;

        if (next <= 3 && !(r->percentTowardsNextBase < 0.75f)) {
            for (j = i + 1; j < 4; j++) {
                if (g_Runners[j].runnerOnFieldOrOutOrScored == 1 && next == g_Runners[j].currentBase) {
                    count++;
                }
            }
            if (count >= 2) {
                r->restrictedMovementCodes |= 1;
            }
        }
    }
}

// .text:0x00086118 size:0x684 mapped:0x806C51AC
int fn_3_86118(void) {
    int best = 9999;
    int bestFrame = 0;
    int closest = -1;
    int frame;
    int i;
    int diff;
    f32 dist;

    if (g_Ball.landingSpotZoneAwayFromHome <= 1 && g_Ball.maxYOfHit < 3.5f && g_Ball.framesSinceHit <= 45 &&
        g_Ball.Hit_HorizontalPower > 80) {
        for (i = 2; i < 6; i++) {
            if (g_Fielders[i]._7C < 2.0f && g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > g_Fielders[i]._70) {
                return 2;
            }
        }
        return 7;
    }

    if ((g_Ball.physicsSubstruct.velocity.y < 0.0f && g_Ball.AtBat_Contact_BallPos.y < 2.0f) || g_Ball.maxYOfHit < 2.0f) {
        dist = VEC_DISTANCE_XZ(&g_Ball.AtBat_Contact_BallPos, &g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot);
        frame = 1;
    } else {
        for (frame = g_Ball.framesUntilBallHitsGround; frame > 0; frame -= 5) {
            if (g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.y >= 2.0f) {
                frame++;
                for (i = 0; i < 5; i++) {
                    if (g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.y < 2.0f) {
                        break;
                    }
                }
                break;
            }
        }
        if (frame < 1) {
            frame = 1;
        }
        dist = VEC_DISTANCE_XZ(&g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos,
                               &g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot);
    }

    i = 1;
    if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 25.0f && g_Ball.hangtimeOfHit > 30 && g_Ball.maxYOfHit > 3.0f) {
        i = 0;
    }
    if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 18.0f && g_Ball.hangtimeOfHit > 30 && g_Ball.maxYOfHit > 4.0f) {
        i = 0;
    }

    if (g_Ball.maxYOfHit <= 3.0f) {
        int found = -1;

        for (; i < 6; i++) {
            u8 state = g_FieldingLogic._0F8[i];
            if (state == 1 || state == 10 || state == 11) {
                if (g_Fielders[i]._7C < 3.0f && 3.0f + g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > g_Fielders[i]._70) {
                    if (g_Fielders[i]._7C < 1.5f * g_Fielders[i]._E8) {
                        return 1;
                    }
                    if (g_Fielders[i]._70 > 1.5f * g_Fielders[i]._7C + g_Ball.ballDistanceFromHome) {
                        return 1;
                    }
                }
                if (g_Fielders[i]._7C < 5.0f && 2.0f + g_Ball.ballDistanceFromHome < g_Fielders[i]._70 &&
                    5.0f + g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > g_Fielders[i]._70) {
                    found = i;
                }
            }
        }
        if (found >= 0) {
            return 3;
        }
        return 5;
    }

    for (; i < 9; i++) {
        u8 state = g_FieldingLogic._0F8[i];
        if (state == 1 || state == 10 || state == 11) {
            if (g_Fielders[i]._7C < 3.0f && g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > g_Fielders[i]._70) {
                int t = fn_3_52560(i, g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                                   g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z) - 10;
                if (best > t) {
                    best = t;
                    bestFrame = frame;
                    if (g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist > 1.0f + g_Fielders[i]._70) {
                        best = t + 15;
                    }
                }
                closest = i;
            } else {
                int toLanding = fn_3_52560(i, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                                           g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z) - 10;
                int toFrame = fn_3_52560(i, g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                                         g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z) - 10;
                if (toLanding < toFrame) {
                    if (best > toLanding) {
                        bestFrame = g_Ball.framesUntilBallHitsGround;
                        best = toLanding + 3;
                    }
                } else if (best > toFrame) {
                    best = toFrame;
                    bestFrame = frame;
                }
            }
        }
    }

    diff = best - bestFrame;
    if (g_GameLogic.battingAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam] != 0) {
        diff += lbl_3_data_1C80[g_GameLogic.runnerAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam]];
    }
    if (best <= 0) {
        return 0;
    }
    if (g_Ball.someCollisionVariable != 0 && diff < 5) {
        return 3;
    }
    if (diff < -60) {
        return 0;
    }
    if (diff < -30) {
        return 1;
    }
    if (diff < -5) {
        return 2;
    }
    if (diff < 8) {
        if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 40.0f) {
            if (diff <= 5) {
                return 3;
            }
        } else {
            return 3;
        }
    }
    if (closest >= 0 && g_Ball.AtBat_Contact_BallPos.y < g_Fielders[closest]._100) {
        return 3;
    }
    if (diff < 20) {
        return 4;
    }
    if (diff < 40) {
        return 5;
    }
    return (diff < 90) ? 6 : 7;
}

// .text:0x0008604C size:0xCC mapped:0x806C50E0
int fn_3_8604C(int* fielderOut) {
    int i;
    int best = 9999;

    for (i = 0; i < 9; i++) {
        u8 state = g_FieldingLogic._0F8[i];
        if (state == 1 || state == 10 || state == 11) {
            int frame;
            int t;

            for (frame = 1; frame < 120; frame += 5) {
                t = fn_3_52560(i, g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                               g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z);
                if (t < frame + 15) {
                    break;
                }
            }
            if (frame >= 120) {
                if (best >= 120) {
                    best = 120;
                }
            } else if (best > t) {
                best = t;
                *fielderOut = i;
            }
        }
    }
    return best;
}

// .text:0x00085EF4 size:0x158 mapped:0x806C4F88
void fn_3_85EF4(int runner, int direction) {
    InMemRunnerType* r = &g_Runners[runner];

    if (r->runnerOnFieldOrOutOrScored != 1) {
        return;
    }
    if (r->tagUpInd == 2 && direction != -1) {
        return;
    }
    if (r->actionCode != 0 && r->actionStage != 0) {
        if (r->actionInForwardDirectionInd == 1) {
            r->baseRunningTowards = r->nextBase;
        } else {
            r->baseRunningTowards = r->currentBase;
        }
        return;
    }
    if (direction == 1) {
        r->baseRunningTowards = r->nextBase;
    }
    if (direction == -1) {
        if (r->currentBase == 0) {
            return;
        }
        if (r->runningDirectionCode == 1 && r->baseStandingOn >= 0 && r->tagUpInd == 0) {
            if (r->baseRoundingState != 1) {
                r->runningDirectionCode = 2;
            }
            return;
        }
        if (r->baseStandingOn >= 0) {
            if (r->baseStandingOn == 1) {
                return;
            }
            if (runner == 0) {
                return;
            }
            if (r->tagUpInd == 0) {
                return;
            }
            r->baseRunningTowards = (r->baseStandingOn + 3) & 3;
        } else {
            r->baseRunningTowards = r->currentBase;
        }
    }
    if (direction == 0 && runner == 0 && r->currentBase == 0) {
        return;
    }
    if (direction == 0) {
        r->runningDirectionDesired = 2;
    } else if (direction == 1) {
        r->runningDirectionDesired = 1;
    } else {
        r->runningDirectionDesired = 3;
    }
}

// .text:0x00085CB0 size:0x244 mapped:0x806C4D44
// 60.54%: the target keeps fn_3_85C44's direction tests after inlining it with direction 1;
// this build folds them away, which also shrinks the frame.
void fn_3_85CB0(void) {
    int i;

    if (g_Ball.pitchHangtimeCounter <= 30 && g_Pitcher.pitcherActionState == 2) {
        if (g_Strikes.outs == 2 && g_Strikes.GameControls_StrikeBallBitVector == 0x23) {
            for (i = 1; i <= 3; i++) {
                if (g_Runners[i].runnerOnFieldOrOutOrScored == 0) {
                    break;
                }
                if (g_Pitcher.pitchTotalTimeCounter >= g_AiLogic.batterAIStealingStartFrame) {
                    fn_3_85C44(i, 1);
                }
            }
        } else if (g_AiLogic.batterAIStealIndicator != 0) {
            for (i = 1; i <= 2; i++) {
                if (g_Pitcher.pitchTotalTimeCounter >= g_AiLogic.batterAIStealingStartFrame) {
                    if (g_Runners[i].stealingStatus == 0) {
                        if (g_AiLogic.batterAIStealingStartFrame < lbl_3_data_4B90[2]) {
                            g_Runners[i].stealingStatus = 3;
                        } else {
                            g_Runners[i].stealingStatus = 2;
                        }
                        g_Runners[i].leadOffStatus = 0;
                    }
                    fn_3_85C44(i, 1);
                }
            }
        } else if (g_AiLogic._74 == 2 && g_Pitcher.pitchTotalTimeCounter >= g_AiLogic.batterAIStealingStartFrame) {
            fn_3_85C44(3, 1);
        }
    }
}

// .text:0x00085C44 size:0x6C mapped:0x806C4CD8
void fn_3_85C44(int runner, int direction) {
    InMemRunnerType* r = &g_Runners[runner];

    if (r->baseRoundingState != 1 || r->overRun1BStage < 2 || direction == 1) {
        if (direction == -1 && r->startingBase_baseAchieved == r->baseStandingOn) {
            direction = 0;
        }
        fn_3_85EF4(runner, direction);
    }
}

// .text:0x00085A70 size:0x1D4 mapped:0x806C4B04
int fn_3_85A70(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    int next;
    int current;
    int toNext;
    int toCurrent;
    int framesNext;
    int framesPrev;
    int base;

    if (g_FieldingLogic._0CC == 9 && g_FieldingLogic._0DE != runner) {
        return -2;
    }
    if (r->baseStandingOn >= 0) {
        return -2;
    }
    next = r->nextBase;
    current = r->currentBase;
    if (next == g_FieldingLogic._0DC && (g_FieldingLogic._0CC == current || g_FieldingLogic._0CC == 9)) {
        return -1;
    }
    if (current == g_FieldingLogic._0DC && (g_FieldingLogic._0CC == next || g_FieldingLogic._0CC == 9)) {
        return 1;
    }
    toNext = fn_3_52560(g_Ball.fielderWBallIndex, lbl_3_data_4444[next].x, lbl_3_data_4444[next].z);
    toCurrent = fn_3_52560(g_Ball.fielderWBallIndex, lbl_3_data_4444[current].x, lbl_3_data_4444[current].z);
    framesNext = r->framesToNextBase;
    framesPrev = r->framesToPreviousBase;
    if (g_FieldingLogic._0CC == 9) {
        if (r->runningDirectionCode == 1 || r->runningDirectionCode == 2) {
            if (framesNext < toNext) {
                return 1;
            }
            return -1;
        }
        if (framesPrev < toCurrent) {
            return -1;
        }
        return 1;
    }
    if (r->distanceFromBall > 20.0f) {
        return -2;
    }
    base = r->currentBase;
    if (r->runningDirectionCode == 1 || r->runningDirectionCode == 2) {
        base = r->nextBase;
    }
    if (base != g_FieldingLogic._0CC) {
        return -2;
    }
    if (r->runningDirectionCode == 1) {
        if (framesNext <= toNext) {
            return 1;
        }
        return -1;
    }
    if (framesPrev <= toCurrent) {
        return -1;
    }
    return 1;
}

// .text:0x00085840 size:0x230 mapped:0x806C48D4
// 94.03%: the target holds runner + 1, its runner offset and g_Runners in r29-r31; this build needs only two
int fn_3_85840(int runner, int count, int* decisions) {
    InMemRunnerType* r = &g_Runners[runner];
    int next = r->nextBase;
    int i;
    u8 ballState;
    s16 contact;
    u8 hitClass;

    if (next == 0) {
        return 0;
    }
    ballState = g_Ball.ballState;
    contact = g_Ball.AtBat_ContactResult;
    hitClass = g_Ball.hitClassification2;
    for (i = runner + 1; i < 4; i++) {
        InMemRunnerType* other = &g_Runners[i];
        if (other->runnerOnFieldOrOutOrScored != 1) {
            continue;
        }
        if (other->currentBase == r->currentBase) {
            if (other->baseRoundingState == 2 && other->overrunBaseStage == 3) {
                return 1;
            }
            if (other->runningDirectionCode == 3) {
                return 1;
            }
            if (other->runningDirectionCode == 2 && other->fractionalBasesRan - r->fractionalBasesRan < 0.7f) {
                return 2;
            }
            if (ballState != 0) {
                return 1;
            }
            if (runner == 0 && contact == 0 && r->fractionalBasesRan > 1.0f && count <= 3 &&
                other->fractionalBasesRan < r->fractionalBasesRan) {
                return 2;
            }
        }
        if (other->currentBase == next) {
            if (contact == 0) {
                if (hitClass <= 4 && other->percentTowardsNextBase < 0.5f) {
                    if (r->forceOutCd == 1 && count > 3) {
                        return 0;
                    }
                    if (other->runningDirectionCode == 3 || other->runningDirectionCode == 2) {
                        return 1;
                    }
                }
            } else if (other->percentTowardsNextBase < 0.5f && decisions[i] <= 0) {
                if (other->runningDirectionCode == 2 || other->runningDirectionCode == 3 ||
                    (other->runningDirectionCode == 1 && other->nextDirectionBeingProcessed == 3)) {
                    return 1;
                }
                if (other->baseRoundingState == 2 && other->overrunBaseStage >= 2) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// .text:0x00085744 size:0xFC mapped:0x806C47D8
void fn_3_85744(int runner) {
    InMemRunnerType* r = &g_Runners[runner];

    if (r->fractionalBasesRan > 0.2) {
        return;
    }
    if (r->distanceFromBall < 20.0f && g_Ball.ballState == 3) {
        r->relatedToRunnerPos = 0;
    }
    if (g_FieldingLogic._0C4 == 5 || g_FieldingLogic._0C4 == 6 || g_FieldingLogic._0C4 == r->currentBase) {
        if (r->percentTowardsNextBase >= 0.125f && r->runningDirectionCode == 1 && g_Ball.ballZoneAwayFromHome <= 3) {
            r->relatedToRunnerPos = 0;
        }
    }
    if (r->baseStandingOn >= 0 && r->baseRoundingState == 2) {
        r->relatedToRunnerPos = 1;
        if (0.0f == r->groundVelocity[0]) {
            r->relatedToRunnerPos = 0;
        }
    }
}

// Frames until the ball lands plus the frames from the landing spot to the base
static inline int landingFramesToBase(int base) {
    return g_Ball.framesUntilBallHitsGround +
           fn_3_A6810(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z,
                      lbl_3_data_4444[base].x, lbl_3_data_4444[base].z);
}

// .text:0x00085074 size:0x6D0 mapped:0x806C4108
int fn_3_85074(int runner, int risk) {
    InMemRunnerType* r = &g_Runners[runner];
    int next = r->nextBase;
    int current = r->currentBase;
    int frames;
    int margin;

    if (g_Ball.pauseBallMovementWhenInPlant == 0 && g_Ball.hitClassification1 == 0) {
        if (r->forceOutCd == 1) {
            return 1;
        }
        return -1;
    }
    if (g_Strikes.outs == 2) {
        return 1;
    }
    if (g_Ball.landingSpotZoneAwayFromHome <= 1) {
        if (g_Ball.maxYOfHit >= 5.0f) {
            return -1;
        }
        if (g_Ball.maxYOfHit < 2.0f && r->forceOutCd == 1) {
            return 1;
        }
        if (risk <= 2) {
            return -1;
        }
        if (r->forceOutCd == 1) {
            return 1;
        }
        return landingFramesToBase(next) + 30 > r->framesToNextBase ? 1 : -1;
    }
    if (risk >= 6) {
        return 1;
    }
    if (risk >= 5 && g_Ball.someCollisionVariable >= 2 && g_Ball.landingSpotZoneAwayFromHome < 3) {
        return 1;
    }
    if (runner == 3) {
        if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > 63.0f) {
            return -1;
        }
        if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > 55.0f && risk <= 5) {
            return -1;
        }
    }
    if (runner == 2 && risk <= 1) {
        if (VEC_DISTANCE_XZ(&lbl_3_data_4444[3], &g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot) > 70.0f &&
            g_Ball.ballAngleFromHome < 0x48C) {
            return -1;
        }
    }
    if (g_Ball.framesUntilBallHitsGround < 60 && runner != 0) {
        if ((risk <= 2 || (risk == 3 && g_Ball.landingSpotZoneAwayFromHome <= 2)) &&
            r->framesToPreviousBase > landingFramesToBase(current)) {
            return -1;
        }
        if (risk >= 4) {
            if (runner == 3 && risk == 4 && g_Ball.landingSpotZoneAwayFromHome >= 4) {
                return -1;
            }
            if (risk >= 5) {
                if (r->forceOutCd != 0) {
                    return 1;
                }
                if (g_Ball.maxYOfHit < 2.5f && g_Ball.ballVelocity > 0.5f) {
                    if (g_Fielders[3]._7C < g_Fielders[5]._7C) {
                        if (g_Ball.ballDistanceFromHome - 2.0f > g_Fielders[3]._70 && g_Fielders[3]._7C > 3.0f) {
                            return 1;
                        }
                        if (g_Fielders[3]._7C > 4.0f && g_Ball.ballDistanceFromHome + g_Fielders[3]._7C > g_Fielders[3]._70) {
                            return 1;
                        }
                    } else {
                        if (g_Ball.ballDistanceFromHome - 2.0f > g_Fielders[5]._70) {
                            return 1;
                        }
                        if (g_Fielders[5]._7C > 4.0f && g_Ball.ballDistanceFromHome + g_Fielders[5]._7C > g_Fielders[5]._70) {
                            return 1;
                        }
                    }
                }
                if (landingFramesToBase(next) + 30 > r->framesToNextBase) {
                    return 1;
                }
            }
        }
    }
    if (runner != 0) {
        frames = fn_3_A6810(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z,
                            lbl_3_data_4444[current].x, lbl_3_data_4444[current].z);
        if (g_Ball.framesUntilBallHitsGround < 45) {
            margin = r->framesToPreviousBase + 30;
        } else {
            margin = r->framesToPreviousBase + 15;
        }
        if (margin > frames) {
            return 0;
        }
        if (r->runningDirectionCode == 2 && margin + 5 > frames) {
            return 0;
        }
        if (0.8f + r->startingBase_baseAchieved <= r->fractionalBasesRan) {
            if (risk >= 5 && g_Ball.ballDistanceFromHome > 3.0f + g_Fielders[6]._70 &&
                g_Ball.ballDistanceFromHome > 3.0f + g_Fielders[7]._70 &&
                g_Ball.ballDistanceFromHome > 3.0f + g_Fielders[8]._70) {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    margin = landingFramesToBase(next) + 30;
    frames = r->framesToNextBase;
    if (r->overRun1BStage != 0) {
        return -2;
    }
    if (margin > frames) {
        return 1;
    }
    return -2;
}

// .text:0x00084AD0 size:0x5A4 mapped:0x806C3B64
// Written out in fn_3_84AD0, the base's &lbl_3_data_4444[i].z is kept for its later call; inline, it is not
static inline int ballFramesToBase(int frame, int base) {
    return fn_3_A6810(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                      g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z, lbl_3_data_4444[base].x,
                      lbl_3_data_4444[base].z);
}

int fn_3_84AD0(int runner, int frame) {
    InMemRunnerType* r = &g_Runners[runner];
    int frames;
    f32 best;
    int closest;
    int i;

    if (r->forceOutCd == 1) {
        return 1;
    }
    if (runner == 3 && g_RunningLogic._02 == 0x1011) {
        r->unused_someBaseNum = 0;
        return 1;
    }
    if ((g_FieldingLogic._107 == 3 || g_FieldingLogic._107 == 4) && r->currentBase == r->startingBase_baseAchieved) {
        r->unused_someBaseNum = r->nextBase;
        return 1;
    }
    frames = ballFramesToBase(frame, r->nextBase) + frame;
    frames += 20;
    if (g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.awayTeamBattingInd_battingTeam] >= 3) {
        frames -= 30;
    } else {
        frames += lbl_3_data_1C88[g_GameLogic.runnerAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam]];
    }
    if (runner == 2 && g_Ball.framesSinceHit < 100 && g_Runners[3].runnerOnFieldOrOutOrScored == 0) {
        if (g_Ball.Hit_HorizontalAngle > 0x2A8 && g_Ball.Hit_HorizontalAngle < 0x30C) {
            if (frames + 45 > r->framesToNextBase) {
                r->unused_someBaseNum = 3;
                return 1;
            }
            if (g_Ball.framesSinceHit < 60 && g_Ball.ballZoneAwayFromHome <= 1) {
                return 0;
            }
        }
        if (g_Ball.Hit_HorizontalAngle > 0x3A0 && g_Ball.Hit_HorizontalAngle < 0x460 && g_Ball.framesSinceHit < 60 &&
            g_Ball.ballZoneAwayFromHome <= 1) {
            return 0;
        }
        if (g_Ball.maybeBuntInd != 0 && g_Ball.framesSinceHit < 60) {
            r->unused_someBaseNum = 3;
            return 1;
        }
    }
    if (g_Ball.ballZoneAwayFromHome >= 3) {
        if (r->fractionalBasesRan >= 3.25f && r->runningDirectionCode == 1) {
            r->unused_someBaseNum = 0;
            return 1;
        }
        if (r->currentBase == r->startingBase_baseAchieved && frames > r->framesToNextBase - 30) {
            return 1;
        }
        if (frames > r->framesToNextBase) {
            return 1;
        }
        return -2;
    }
    best = 999.9f;
    closest = -1;
    if (g_Ball.someCollisionInd != 0) {
        for (i = 2; i <= 5; i++) {
            if (g_Ball.ballDistanceFromHome > 3.0f + g_Fielders[i]._70) {
                continue;
            }
            if (g_Fielders[i]._7C < best) {
                best = g_Fielders[i]._7C;
                closest = i;
            }
        }
        if (best < 3.0f && g_Fielders[closest]._70 > g_Ball.ballDistanceFromHome &&
            (r->runningDirectionCode == 3 || r->runningDirectionCode == 2)) {
            if (fn_3_A6810(g_Fielders[closest]._000, g_Fielders[closest]._000, lbl_3_data_4444[r->currentBase].x,
                           lbl_3_data_4444[r->currentBase].z) < r->framesToPreviousBase - 20) {
                return -1;
            }
        }
    }
    if (g_Ball.ballZoneAwayFromHome <= 1 && g_Ball.ballVelocity > 0.5f && g_Ball.ballDistanceFromHome > 30.0f) {
        if (closest >= 0) {
            if (g_Fielders[closest]._70 - g_Ball.ballDistanceFromHome < best) {
                return 1;
            }
        } else {
            return 1;
        }
    }
    if (g_Ball.ballZoneAwayFromHome >= 2 || closest == -1) {
        if (r->fractionalBasesRan >= 3.325f && r->runningDirectionCode == 1) {
            r->unused_someBaseNum = 0;
            return 1;
        }
        if (r->currentBase == r->startingBase_baseAchieved && frames > r->framesToNextBase - 30) {
            return 1;
        }
        if (g_Ball.someCollisionInd != 0) {
            if (frames > r->framesToNextBase + 30) {
                return 1;
            }
            if (r->percentTowardsNextBase > 0.5f) {
                return 1;
            }
            return -1;
        }
        if (g_Ball.ballState == 3) {
            if (frames > r->framesToNextBase + 20) {
                return 1;
            }
            if (r->percentTowardsNextBase > 0.5f) {
                return 1;
            }
            return -1;
        }
    }
    return 0;
}

// .text:0x000846C8 size:0x408 mapped:0x806C375C
int fn_3_846C8(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    int next = r->nextBase;
    int current = r->currentBase;
    int toNext;
    int toCurrent;
    int result;

    if (g_Ball.ballZoneAwayFromHome <= 2 && r->baseStandingOn >= 0) {
        return 0;
    }
    if (g_Ball.ballZoneAwayFromHome >= 3 && r->percentTowardsNextBase >= 3.2f && r->runningDirectionCode == 1 &&
        r->baseRoundingState == 2) {
        r->unused_someBaseNum = 0;
        return 1;
    }
    if (r->runningDirectionCode == 1 && r->percentTowardsNextBase > 0.8f && r->baseStandingOn < 0) {
        return -2;
    }
    if (r->runningDirectionCode == 3 && r->percentTowardsNextBase < 0.2f && g_Ball.ballZoneAwayFromHome <= 2) {
        return -2;
    }
    if (g_FieldingLogic._0D0[next] == g_Ball.fielderWBallIndex) {
        return -1;
    }
    if (g_FieldingLogic._0D0[current] == g_Ball.fielderWBallIndex) {
        return 1;
    }
    if (g_FieldingLogic._0CC != -1 && g_Ball.ballZoneAwayFromHome <= 2) {
        result = fn_3_85A70(runner);
        if (result != -2) {
            return result;
        }
    }
    toNext = fn_3_A6ABC(lbl_3_data_4444[next].x, lbl_3_data_4444[next].z);
    toCurrent = fn_3_A6ABC(lbl_3_data_4444[current].x, lbl_3_data_4444[current].z);
    if (g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.awayTeamBattingInd_battingTeam] >= 3) {
        toNext -= 30;
    } else {
        toNext += lbl_3_data_1C88[g_GameLogic.runnerAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam]];
    }
    if (g_FieldingLogic._0C4 >= 0) {
        int delay = 30 - g_FieldingLogic._0F0;
        if (delay > 0) {
            toNext += delay;
            toCurrent += delay;
        }
    } else {
        toNext += 30;
        toCurrent += 30;
    }
    if (r->runningDirectionCode == 1 && r->percentTowardsNextBase > 0.5f) {
        toNext += 40;
        if (r->currentBase == 3) {
            toNext += 20;
        }
    } else if (r->runningDirectionCode == 1 && (r->baseRoundingState != 1 || r->overrunBaseStage != 2)) {
        if (r->percentTowardsNextBase >= 0.15f) {
            toNext += 20;
        }
    }
    if (toNext > r->framesToNextBase) {
        if (runner == 3 && g_Ball.AtBat_ContactResult == 3 && g_Ball.timeSinceBallPickedUp <= 1 &&
            g_Ball.numberOfThrowsDuringPlay == 1) {
            r->unused_someBaseNum = 0;
        }
        return 1;
    }
    if (g_Ball.ballZoneAwayFromHome >= 3 && runner >= 1 && r->currentBase == r->startingBase_baseAchieved &&
        g_Ball.AtBat_ContactResult != 3 && toNext > r->framesToNextBase - 20) {
        return 1;
    }
    if (r->currentBase == 3 && g_Ball.ballZoneAwayFromHome >= 3 && g_Ball.AtBat_ContactResult != 3) {
        if (toNext > r->framesToNextBase - 20) {
            return 1;
        }
        if (toNext > r->framesToNextBase - 30 && g_Strikes.outs >= 2) {
            return 1;
        }
    }
    if (toCurrent > r->framesToPreviousBase) {
        if (r->baseRoundingState == 2 && r->overrunBaseStage == 2 && toCurrent - 20 > r->framesToPreviousBase) {
            return -2;
        }
        return -1;
    }
    if (toNext - r->framesToNextBase > toCurrent - r->framesToPreviousBase) {
        return 1;
    }
    return -1;
}

// .text:0x000842E4 size:0x3E4 mapped:0x806C3378
// 99.14%: register allocation only; the target gives the call arguments' saved pointers r26-r28
// and r, next and current r25, r30 and r29
int fn_3_842E4(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    int next;
    int current;
    int throwFrames;
    int frames;

    if (g_Ball.throwTimeEstimatesCompleteInd == 0) {
        return -2;
    }
    next = r->nextBase;
    current = r->currentBase;
    throwFrames = g_Ball.framesUntilThrowReachesDest;
    if (g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.awayTeamBattingInd_battingTeam] >= 3) {
        throwFrames -= 30;
    } else {
        throwFrames += lbl_3_data_1C88[g_GameLogic.runnerAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam]];
    }
    if (r->runningDirectionCode == 1 && r->percentTowardsNextBase > 0.8f) {
        r->baseRunningTowards = next;
        return -2;
    }
    if (r->runningDirectionCode == 3 && r->percentTowardsNextBase < 0.2f && g_Ball.ballZoneAwayFromHome <= 3) {
        r->baseRunningTowards = current;
        return -2;
    }
    if (r->baseStandingOn == g_FieldingLogic._0C4) {
        return -(g_FieldingLogic._0C4 == current);
    }
    if (r->runningDirectionCode == 1 && g_FieldingLogic._0C4 == next) {
        if (r->percentTowardsNextBase >= 0.4f) {
            throwFrames += 30;
            if (r->currentBase == 3) {
                throwFrames += 20;
            }
        }
        if (r->framesToNextBase < throwFrames) {
            return 1;
        }
        if (g_FieldingLogic._119 != 0 &&
            g_Ball.StaticRandomInt1 % (g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.teamBatting] + 5) != 0) {
            return 1;
        }
        return -1;
    }
    if (r->runningDirectionCode == 3 && g_FieldingLogic._0C4 == current) {
        if (r->percentTowardsNextBase <= 0.4f) {
            throwFrames += 15;
        }
        if (r->framesToPreviousBase < throwFrames) {
            return -1;
        }
        if (g_FieldingLogic._119 != 0 &&
            g_Ball.StaticRandomInt1 % (g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.teamBatting] + 5) != 0) {
            return -1;
        }
        return 1;
    }
    if (g_FieldingLogic._0C4 == 6) {
        frames = throwFrames + fn_3_A6810(g_Fielders[g_FieldingLogic._0BE]._14.x, g_Fielders[g_FieldingLogic._0BE]._14.z,
                                          lbl_3_data_4444[next].x, lbl_3_data_4444[next].z);
        frames += 30;
        if (next == 0) {
            frames += 15;
            if (g_Strikes.outs >= 2) {
                frames += 10;
            }
        }
        if (r->percentTowardsNextBase >= 0.5f) {
            frames += 15;
        } else if (r->percentTowardsNextBase >= 0.15f) {
            frames += 5;
        }
        if (r->framesToNextBase < frames) {
            if (r->fractionalBasesRan >= 3.15f && g_Ball.ballZoneAwayFromHome >= 3) {
                r->unused_someBaseNum = 0;
            }
            return 1;
        }
        if (r->baseRoundingState == 2 && r->overrunBaseStage == 2) {
            frames = throwFrames + fn_3_A6810(g_Fielders[g_FieldingLogic._0BE]._14.x, g_Fielders[g_FieldingLogic._0BE]._14.z,
                                              lbl_3_data_4444[current].x, lbl_3_data_4444[current].z);
            frames += 20;
            return (frames < r->framesToPreviousBase) - 2;
        }
        return -1;
    }
    return -2;
}

// .text:0x000841C0 size:0x124 mapped:0x806C3254
int fn_3_841C0(int runner, int frame) {
    InMemRunnerType* r = &g_Runners[runner];
    int frames;

    if (r->forceOutCd == 1) {
        return 1;
    }
    frames = frame + fn_3_A6810(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                        g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z, lbl_3_data_4444[r->nextBase].x,
                        lbl_3_data_4444[r->nextBase].z);
    frames += 45;
    if (g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.awayTeamBattingInd_battingTeam] >= 3) {
        frames -= 30;
    } else {
        frames += lbl_3_data_1C88[g_GameLogic.runnerAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam]];
    }
    if (g_Ball.ballZoneAwayFromHome <= 1) {
        if (frames - 20 > r->framesToNextBase) {
            return 1;
        }
    } else if (frames > r->framesToNextBase) {
        return 1;
    }
    return -1;
}

// .text:0x00083714 size:0xAAC mapped:0x806C27A8
void fn_3_83714(void) {
    int j;
    int i;
    int fielder;
    int decisions[4];
    int decision = 3;
    s16 contact;
    int frame = 0;

    if (g_d_GameSettings.GameModeSelected == 2) {
        return;
    }
    if (g_GameLogic.gameStatus == 2 && g_GameLogic.FrameCountOfCurrentPitch < g_RunningLogic._14) {
        return;
    }
    if (g_FieldingLogic._10E != 0) {
        return;
    }

    if (g_Ball.framesSinceHit >= 0 && g_Ball.AtBat_ContactResult == 0) {
        decision = fn_3_86118();
    } else if (g_Ball.AtBat_ContactResult == 1 || g_Ball.ballState == 3) {
        frame = fn_3_8604C(&fielder);
    }

    contact = g_Ball.AtBat_ContactResult;
    if (g_Ball.framesSinceHit < 0) {
        contact = -2;
    }
    if (g_Ball.AtBat_ContactResult == 0 && g_Ball.hitClassification1 == 0) {
        contact = 1;
    }

    for (i = 3; i >= 0; i--) {
        InMemRunnerType* r = &g_Runners[i];

        decisions[i] = -2;
        if (r->runnerOnFieldOrOutOrScored != 1 || r->unused_const_1 == 0 || g_Strikes.outs >= 3 ||
            g_FieldingLogic._10E != 0) {
            continue;
        }
        if (i == 0 && g_Ball.framesSinceHit < r->delayBeforeStartingToRun) {
            decisions[i] = 0;
        } else if (i == 0 && g_Ball.framesSinceHit == r->delayBeforeStartingToRun) {
            decisions[i] = 1;
        } else if (g_Ball.deadBallReason == 1) {
            decisions[i] = 1;
        } else if (i == 0 && g_Ball.framesSinceHit == -1) {
            decisions[i] = 0;
        } else if (i == 0 && r->currentBase == 0) {
        } else if ((g_Ball.AtBat_ContactResult == 0 || g_Ball.AtBat_ContactResult == 1) && g_FieldingLogic._108 != 0) {
            decisions[i] = -1;
        } else if (g_Ball.howFoulTheBallWillBe >= 2 &&
                   (g_Ball.numFieldersWhoHandledBallDuringPlay == 0 || g_Ball.bobbleLocation_1fair_2foul != 1)) {
            decisions[i] = -1;
        } else if (g_Strikes.storedOuts == 2 && g_FieldingLogic._107 == 0 &&
                   r->currentBase == r->startingBase_baseAchieved) {
            decisions[i] = 1;
        } else {
            int found;
            int ret;

            if (contact == 3) {
                if (r->tagUpInd == 2) {
                    decisions[i] = -1;
                    r->relatedToRunnerPos = 0;
                    r->unused_someBaseNum = -1;
                    continue;
                }
                for (j = 3; j > i; j--) {
                    if (g_Runners[j].runnerOnFieldOrOutOrScored == 1 && g_Runners[j].tagUpInd == 2) {
                        decisions[i] = -1;
                        r->unused_someBaseNum = -1;
                    }
                }
            }
            if (contact == 3 && r->tagUpInd == 2) {
                decisions[i] = -1;
                continue;
            }
            if (r->forceOutCd == 1 && contact >= 1 && contact <= 2) {
                decisions[i] = 1;
                continue;
            }
            if (r->unused_someBaseNum >= 0) {
                if (g_Ball.AtBat_ContactResult == 3 && r->tagUpInd != 0) {
                    r->unused_someBaseNum = -1;
                } else if (r->unused_someBaseNum == r->currentBase) {
                    r->unused_someBaseNum = -1;
                } else if (r->actionCode != 0) {
                    r->unused_someBaseNum = -1;
                } else {
                    decisions[i] = 1;
                    continue;
                }
            }
            found = 0;
            for (j = 0; j < i; j++) {
                if (g_Runners[j].runnerOnFieldOrOutOrScored == 1 && r->currentBase == g_Runners[j].currentBase &&
                    (j != 0 || (g_Ball.AtBat_ContactResult != 0 && g_Ball.AtBat_ContactResult != 3))) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                decisions[i] = 1;
                continue;
            }
            if (!(r->fractionalBasesRan > 0.2)) {
                if (r->distanceFromBall < 20.0f && g_Ball.ballState == 3) {
                    r->relatedToRunnerPos = 0;
                }
                if (g_FieldingLogic._0C4 == 5 || g_FieldingLogic._0C4 == 6 || g_FieldingLogic._0C4 == r->currentBase) {
                    if (r->percentTowardsNextBase >= 0.125f && r->runningDirectionCode == 1 &&
                        g_Ball.ballZoneAwayFromHome <= 3) {
                        r->relatedToRunnerPos = 0;
                    }
                }
                if (r->baseStandingOn >= 0 && r->baseRoundingState == 2) {
                    r->relatedToRunnerPos = 1;
                    if (0.0f == r->groundVelocity[0]) {
                        r->relatedToRunnerPos = 0;
                    }
                }
            }
            ret = fn_3_85840(i, decision, decisions);
            if (ret == 1) {
                if (g_Ball.framesSinceHit < 60 || g_Ball.AtBat_ContactResult == 0) {
                    decisions[i] = 0;
                } else {
                    decisions[i] = -1;
                }
            } else if (ret == 2) {
                decisions[i] = 0;
            } else if (g_Ball.framesSinceHit != -1 && g_Ball.framesSinceHit >= 10) {
                if (contact == 0) {
                    if (g_Ball.pauseBallMovementWhenInPlant != 0) {
                        decisions[i] = fn_3_85074(i, 5);
                    } else if (g_Ball.maxYOfHit <= 1.2f) {
                        decisions[i] = fn_3_84AD0(i, frame);
                    } else {
                        decisions[i] = fn_3_85074(i, decision);
                    }
                } else if (g_Ball.ballStoppingCode1ReallySlow2Stopped != 0 &&
                           (g_Ball.ballState == 3 || (g_Ball.AtBat_ContactResult == 1 && g_Ball.framesSinceHit > 400))) {
                    decisions[i] = fn_3_841C0(i, frame);
                } else if (g_Ball.numberOfThrowsDuringPlay >= 1 && g_Ball.ballState == 3 &&
                           (g_Ball.ballVelocity < 0.1f || g_FieldingLogic._12C != 0)) {
                    decisions[i] = fn_3_841C0(i, frame);
                } else if (contact == 1 || g_Ball.ballState == 3) {
                    decisions[i] = fn_3_84AD0(i, frame);
                } else if (g_Ball.ballState == 1) {
                    decisions[i] = fn_3_846C8(i);
                } else {
                    decisions[i] = fn_3_842E4(i);
                }
            }
        }
    }

    for (i = 3; i >= 0; i--) {
        if (decisions[i] != -2) {
            fn_3_85C44(i, decisions[i]);
        }
    }
    if (g_GameLogic.battingAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam] != 0) {
        fn_3_835B0();
    }
}

// .text:0x000835B0 size:0x164 mapped:0x806C2644
void fn_3_835B0(void) {
    if (g_GameLogic._13E[g_GameLogic.homeTeamBattingInd_fieldingTeam] == 0) {
        InputStruct* input = &g_Controls[g_GameLogic.teams[g_GameLogic.teamBatting]];
        if (input->newButtonInput & 0xF00) {
            g_Runners[0].newButtonThisFrame_forMashPurposes = 1;
            g_Runners[1].newButtonThisFrame_forMashPurposes = 1;
            g_Runners[2].newButtonThisFrame_forMashPurposes = 1;
            g_Runners[3].newButtonThisFrame_forMashPurposes = 1;
        }
    } else if (g_AiLogic._44 > 0 &&
               g_Ball.framesSinceHit >=
                   lbl_3_data_1C58[g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.homeTeamBattingInd_fieldingTeam]][0]) {
        if (g_AiLogic._77 != 0) {
            g_AiLogic._77--;
        } else {
            if (RandomInt_Game(100) <
                lbl_3_data_1C58[g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.homeTeamBattingInd_fieldingTeam]][3]) {
                g_Runners[0].newButtonThisFrame_forMashPurposes = 1;
                g_Runners[1].newButtonThisFrame_forMashPurposes = 1;
                g_Runners[2].newButtonThisFrame_forMashPurposes = 1;
                g_Runners[3].newButtonThisFrame_forMashPurposes = 1;
                g_AiLogic._44--;
            }
            g_AiLogic._77 =
                lbl_3_data_1C58[g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.homeTeamBattingInd_fieldingTeam]][2];
        }
    }
}

// .text:0x000833EC size:0x1C4 mapped:0x806C2480
void fn_3_833EC(int runner) {
    InMemRunnerType* r;

    fn_3_8307C(runner);
    r = &g_Runners[runner];
    fn_3_7FD90(runner);
    if (r->runningToDugoutInd != 0) {
        r->baseRoundingState = 0;
        r->actionCode = 0;
    } else {
        fn_3_7ECFC(runner);
        fn_3_7F494(runner);
        if (g_GameLogic.secondaryGameMode != 6) {
            if (runner == 0 && r->nextBase == 1) {
                fn_3_7F2D8();
            } else if (r->baseRoundingState == 1) {
                r->baseRoundingState = 0;
            }
            fn_3_7EBD4(runner);
        }
    }
    fn_3_82670(runner);
    fn_3_81190(runner);
    fn_3_80028(runner);
    fn_3_8307C(runner);
}

// .text:0x0008307C size:0x370 mapped:0x806C2110
void fn_3_8307C(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    int base;
    int ahead;
    int next;
    f32 distCurrent;
    f32 distNext;

    if ((r->runningToDugoutInd != 1 || r->runningToDugoutStage == 0) && g_Pitcher.pitcherActionState != 6) {
        base = r->fractionalBasesRan;
        r->currentBaseCoordinates.y = 0.0f;
        ahead = base + 1;
        r->nextBaseCoordinates.y = 0.0f;
        next = ahead % 4;
        if (g_GameLogic.secondaryGameMode == 6) {
            r->currentBaseCoordinates.x = lbl_3_data_4A34[base].x;
            r->currentBaseCoordinates.z = lbl_3_data_4A34[base].z;
        } else if (ahead == 1) {
            r->currentBaseCoordinates.x = g_Batter.batterPos.x;
            r->currentBaseCoordinates.z = g_Batter.batterPos.z;
        } else {
            r->currentBaseCoordinates.x = lbl_3_data_4A34[base].x;
            r->currentBaseCoordinates.z = lbl_3_data_4A34[base].z;
        }
        r->nextBaseCoordinates.x = lbl_3_data_4A34[next].x;
        r->nextBaseCoordinates.z = lbl_3_data_4A34[next].z;
        distCurrent = VEC_DISTANCE_XZ(&r->currentBaseCoordinates, &r->position);
        distNext = VEC_DISTANCE_XZ(&r->nextBaseCoordinates, &r->position);
        r->calculatedLengthOfCurrentBaseline = distCurrent + distNext;
        r->fractionOfCalculatedBaselineRan = distCurrent / (distCurrent + distNext);
        r->distToCurrentBase = distCurrent;
        r->distToNextBase = distNext;
        r->currentBase = base;
        r->nextBase = next;
        fn_3_82F80(runner, &r->framesToPreviousBase, &r->framesToNextBase);
    }
}

// .text:0x00082F80 size:0xFC mapped:0x806C2014
void fn_3_82F80(int runner, s16* framesBack, s16* framesForward) {
    InMemRunnerType* r = &g_Runners[runner];
    int frames;
    f32 dist;
    f32 v;

    frames = 0;
    dist = r->percentTowardsNextBase_slideAdj;
    if (dist > 0.0f) {
        if (r->percentRanPerFrame_slideAdj < r->velocityPercent_stamAdj) {
            v = r->percentRanPerFrame_slideAdj;
            for (;;) {
                v += r->accelerationPercent_stamAdj;
                frames++;
                if (v > r->velocityPercent_stamAdj) {
                    dist -= r->velocityPercent_stamAdj;
                    break;
                }
                dist -= v;
                if (dist < 0.0f) {
                    break;
                }
            }
        }
        frames += (int)(dist / r->velocityPercent_stamAdj) + 1;
    }
    *framesForward = frames;

    frames = 0;
    dist = r->percentFromCurrentBase_slideAdj;
    if (dist > 0.0f) {
        if (r->percentRanPerFrame_slideAdj > -r->velocityPercent_stamAdj) {
            v = r->percentRanPerFrame_slideAdj;
            for (;;) {
                v -= r->accelerationPercent_stamAdj;
                frames++;
                if (v < -r->velocityPercent_stamAdj) {
                    dist -= r->velocityPercent_stamAdj;
                    break;
                }
                dist -= v;
                if (dist < 0.0f) {
                    break;
                }
            }
        }
        frames += (int)(dist / r->velocityPercent_stamAdj) + 1;
    }
    *framesBack = frames;
}

// .text:0x00082670 size:0x910 mapped:0x806C1704
// 99.92%: only float registers differ in the final 10000.0f rounding (the target keeps 10000.0f in f2)
void fn_3_82670(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    int turnaround = r->turnaroundCode;
    f32 topSpeed;
    f32 boost;
    f32 inv;
    int capped;

    if (lbl_3_common_bss_34C90._1D5 != 0) {
        return;
    }
    r->groundVelocity[3] = r->groundVelocity[2];
    r->groundVelocity[2] = r->groundVelocity[1];
    r->groundVelocity[1] = r->groundVelocity[0];
    if (g_GameLogic.secondaryGameMode != 6) {
        if (runner == 0 && r->delayBeforeStartingToRun > g_Ball.framesSinceHit) {
            return;
        }
        if (r->batterStayInBattersBoxReason == 3) {
            r->acceleration = 0.0f;
            return;
        }
    }
    if (r->actionCode != 0) {
        fn_3_823B4(runner);
        goto advance;
    }
    if (r->overRun1BStage != 0 && fn_3_81EAC(runner) != 0) {
        return;
    }
    if (r->overrunBaseStage != 0 && fn_3_81BC8(runner) != 0) {
        return;
    }
    if (r->leadOffStatus == 1) {
        fn_3_81AEC(runner);
        goto slide;
    }
    if (r->slideHomeFrames_CountDown != 0) {
        return;
    }
    if (r->fractionalBasesRan >= 4.0f) {
        return;
    }
    r->acceleration = 0.0f;
    r->turnaroundCode = 0;
    if (r->framesSinceLastDirectionChange < 0x7FFE) {
        r->framesSinceLastDirectionChange++;
    } else {
        r->framesSinceLastDirectionChange = 0x7FFF;
    }
    if (r->nextDirectionBeingProcessed == 1) {
        if (r->runningDirectionCode == 3) {
            r->acceleration = r->baseAccelerationWhileChaingingDirection * r->accelerationStaminaEffectWhileChangingDirection;
        } else {
            r->acceleration = r->baseAcceleration * r->accelerationStaminaEffect;
        }
    } else if (r->nextDirectionBeingProcessed == 2) {
        if (r->runningDirectionCode == 1) {
            r->acceleration = -(r->baseAccelerationWhileChaingingDirection * r->accelerationStaminaEffectWhileChangingDirection);
        } else if (r->runningDirectionCode == 3) {
            r->acceleration = r->baseAccelerationWhileChaingingDirection * r->accelerationStaminaEffectWhileChangingDirection;
        } else if (r->runningDirectionCode == 2) {
            r->groundVelocity[0] = 0.0f;
        }
    } else if (r->nextDirectionBeingProcessed == 3) {
        if (r->runningDirectionCode == 1) {
            r->acceleration = -(r->baseAccelerationWhileChaingingDirection * r->accelerationStaminaEffectWhileChangingDirection);
        } else {
            r->acceleration = -(r->baseAcceleration * r->accelerationStaminaEffect);
        }
    } else if (r->runningDirectionCode == 1) {
        r->acceleration = r->baseAcceleration * r->accelerationStaminaEffect;
    } else if (r->runningDirectionCode == 3) {
        r->acceleration = -(r->baseAcceleration * r->accelerationStaminaEffect);
    } else if (r->runningDirectionCode == 2) {
        r->groundVelocity[0] = 0.0f;
    }
    if (g_GameLogic.secondaryGameMode == 6) {
        boost = lbl_3_data_218BC[16] * g_Minigame.miniGameCurrentPoints[r->miniGamePlayerNum] + 1.0f;
        if (boost > lbl_3_data_218BC[17]) {
            boost = lbl_3_data_218BC[17];
        }
        if (g_Minigame.playerIDWithPowerup[0] == runner) {
            boost *= lbl_3_data_2191C[1];
        }
        topSpeed = boost * (r->maximumBaseVelocity * r->staminaMult);
    } else if (r->stealingStatus != 0) {
        topSpeed = lbl_3_data_4B88[1] * (r->maximumBaseVelocity * r->staminaMult);
    } else {
        topSpeed = lbl_3_data_4B88[0] * (r->maximumBaseVelocity * r->staminaMult);
    }
    capped = 0;
    r->groundVelocity[0] += r->acceleration;
    if (r->groundVelocity[0] > topSpeed) {
        r->groundVelocity[0] = topSpeed;
        capped = 1;
    }
    if (r->groundVelocity[0] < -topSpeed) {
        r->groundVelocity[0] = -topSpeed;
        capped = -1;
    }
    if (capped != 0) {
        if (r->newButtonThisFrame_forMashPurposes != 0) {
            r->framesSinceLastMash = r->FramesUntilNotSprinting;
            r->mashPercent += r->percentAddedPerMash;
            if (r->mashPercent > 1.0f) {
                r->mashPercent = 1.0f;
            }
        } else if (r->framesSinceLastMash != 0) {
            r->framesSinceLastMash--;
        } else {
            r->mashPercent -= r->stamina_MashPercentTakenAwayPerFrame;
            if (r->mashPercent < 0.0f) {
                r->mashPercent = 0.0f;
            }
        }
        r->mashVeloAdjustment = r->mashPercent * r->maxMashVeloAdjustment;
        if (capped == 1 && r->acceleration > 0.0f) {
            r->groundVelocity[0] += r->mashVeloAdjustment;
        } else if (r->acceleration < 0.0f) {
            r->groundVelocity[0] -= r->mashVeloAdjustment;
        }
    } else {
        r->mashPercent = 0.0f;
        r->framesSinceLastMash = 0;
    }
    if (r->nextDirectionBeingProcessed == 1) {
        if (r->groundVelocity[0] >= 0.0f) {
            if (r->runningDirectionCode != 1) {
                r->runnerDirectionCode_stored = r->runningDirectionCode;
            }
            r->runningDirectionCode = 1;
            r->nextDirectionBeingProcessed = 0;
            r->framesSinceLastDirectionChange = 0;
            if (turnaround == 2 || r->groundVelocity[1] < 0.0f || r->groundVelocity[2] < 0.0f || r->groundVelocity[3] < 0.0f) {
                r->turningAroundInd = 1;
                playSoundEffect(0x174);
            } else {
                r->turningAroundInd = 0;
            }
            r->leadOffStatus = 0;
        } else {
            r->turnaroundCode = 2;
        }
    } else if (r->nextDirectionBeingProcessed == 2) {
        if ((r->runningDirectionCode == 1 && r->groundVelocity[0] < 0.0f) ||
            (r->runningDirectionCode == 3 && r->groundVelocity[0] > 0.0f) || r->groundVelocity[0] == 0.0f) {
            if (r->runningDirectionCode != 2) {
                r->runningDirectionCode = 2;
                r->framesSinceLastDirectionChange = 0;
            }
            r->nextDirectionBeingProcessed = 0;
            r->groundVelocity[0] = 0.0f;
            r->turningAroundInd = 0;
        } else {
            r->turnaroundCode = 1;
        }
    } else if (r->nextDirectionBeingProcessed == 3) {
        if (r->groundVelocity[0] <= 0.0f) {
            if (r->runningDirectionCode != 3) {
                r->runnerDirectionCode_stored = r->runningDirectionCode;
            }
            r->runningDirectionCode = 3;
            r->nextDirectionBeingProcessed = 0;
            r->framesSinceLastDirectionChange = 0;
            if (turnaround == 2 || r->groundVelocity[1] > 0.0f || r->groundVelocity[2] > 0.0f || r->groundVelocity[3] > 0.0f) {
                r->turningAroundInd = 1;
                playSoundEffect(0x174);
            } else {
                r->turningAroundInd = 0;
            }
        } else {
            r->turnaroundCode = 2;
        }
    }
    if (r->runningDirectionCode == 1) {
        r->baseRunningTowards = r->nextBase;
    } else if (r->runningDirectionCode == 3) {
        if (r->baseStandingOn >= 0 && r->startingBase_baseAchieved == r->baseStandingOn && r->tagUpInd == 2) {
            r->baseRunningTowards = (r->currentBase + 3) & 3;
        } else {
            r->baseRunningTowards = r->currentBase;
        }
    }
    inv = 1.0f / r->calculatedLengthOfCurrentBaseline;
    r->percentRanPerFrame_slideAdj = r->groundVelocity[0] * inv;
    r->velocityPercent_stamAdj = inv * (r->maximumBaseVelocity * r->staminaMult);
    r->accelerationPercent_stamAdj = inv * (r->baseAcceleration * r->accelerationStaminaEffect);
advance:
    if (r->percentRanPerFrame_slideAdj != 0.0f) {
        int scaled = 10000.0f * (r->fractionalBasesRan + r->percentRanPerFrame_slideAdj);
        r->fractionalBasesRan = scaled / 10000.0f;
        r->percentTowardsNextBase = (scaled % 10000) / 10000.0f;
    }
slide:
    r->percentFromCurrentBase_slideAdj = r->percentTowardsNextBase - r->slidingAdjustment_backwards;
    r->percentTowardsNextBase_slideAdj = (1.0f - r->percentTowardsNextBase) - r->slidingAdjustment_forwards;
    if (r->overRun1BStage != 0) {
        fn_3_81EAC(runner);
    }
}

// .text:0x000823B4 size:0x2BC mapped:0x806C1448
void fn_3_823B4(int runner) {
    InMemRunnerType* r = &g_Runners[runner];

    r->actionFrames_countUp++;
    r->actionFrames_countDown--;
    if (r->actionStage == 1) {
        if (r->actionInForwardDirectionInd != 0) {
            f32 dist = (1.0f - r->slidingAdjustment_forwards) - r->percentTowardsNextBase;
            if (r->actionFrames_countDown <= 0) {
                r->percentRanPerFrame_slideAdj = 0.03f + dist;
            } else {
                r->percentRanPerFrame_slideAdj = dist / (r->actionFrames_countDown + 1);
            }
        } else {
            f32 dist = r->percentTowardsNextBase - r->slidingAdjustment_backwards;
            if (r->actionFrames_countDown <= 0) {
                r->percentRanPerFrame_slideAdj = -dist - 0.03f;
            } else {
                r->percentRanPerFrame_slideAdj = -dist / (r->actionFrames_countDown + 1);
            }
        }
        if (r->actionFrames_countDown <= 0) {
            r->actionFrames_countUp = 0;
            r->actionFrames_countDown = lbl_3_data_7760[r->charID][3];
            r->actionStage = 2;
            r->percentRanPerFrame_slideAdj = 0.0f;
            r->fractionalBasesRan = r->baseRunningTowards;
            r->percentTowardsNextBase = 0.0f;
            if (r->baseRunningTowards == 0) {
                r->fractionalBasesRan = 4.0f;
            }
            if (r->runnerOnFieldOrOutOrScored == 2) {
                r->actionStage = 3;
            }
        }
    } else if (r->actionStage == 2) {
        r->groundVelocity[0] = 0.0f;
        r->percentRanPerFrame_slideAdj = 0.0f;
        if (r->actionFrames_countDown <= 0) {
            r->actionCode = 0;
            r->actionStage = 0;
            if (r->baseStandingOn >= 0) {
                fn_3_81AB8(runner);
                fn_3_810C4(runner, r->baseStandingOn);
                r->framesSinceLastDirectionChange = 1;
            }
        }
    }
}

// .text:0x00081EAC size:0x508 mapped:0x806C0F40
int fn_3_81EAC(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    f32 distFirst;
    f32 distSecond;
    f32 pct;

    if (r->fractionalBasesRan < 1.0f) {
        return 0;
    }
    if (r->nextDirectionBeingProcessed == 1) {
        r->overRun1BStage = 0;
        r->runningDirectionCode = 2;
        r->overrunning1BIndicator = 1;
        distFirst = VEC_DISTANCE_XZ(&lbl_3_data_4A34[1], &r->position);
        distSecond = VEC_DISTANCE_XZ(&lbl_3_data_4A34[2], &r->position);
        pct = (int)(10000.0f * (distFirst / (distFirst + distSecond))) / 10000.0f;
        r->percentTowardsNextBase = pct;
        r->fractionalBasesRan = 1.0f + pct;
        r->fractionalBasesRan_stored = r->fractionalBasesRan;
        r->percentTowardsNextBase_stored = r->percentTowardsNextBase;
        r->groundVelocity[0] = 0.0f;
        r->percentRanPerFrame_slideAdj = 0.0f;
        r->percentFromCurrentBase_slideAdj = r->percentTowardsNextBase - r->slidingAdjustment_backwards;
        r->percentTowardsNextBase_slideAdj = (1.0f - r->percentTowardsNextBase) - r->slidingAdjustment_forwards;
        return 1;
    }
    if (r->overRun1BStage == 1) {
        r->overRun1BStage = 2;
        r->overrunBaseFrames_countUp = 0;
        r->overrunBaseFrames_countDown = lbl_3_data_4B40[0];
        r->runningDirectionCode = 4;
        r->overrun1B_someDistConst_proportionPerFrame =
            1.0f / ((r->overrunBaseFrames_countDown + 1) * (r->overrunBaseFrames_countDown / 2));
        r->overrun1B_somePositionControl = 0.0f;
    }
    if (r->overRun1BStage == 2) {
        r->overrunBaseFrames_countUp++;
        r->overrunBaseFrames_countDown--;
        if (r->overrunBaseFrames_countDown == 0) {
            r->overRun1BStage = 3;
            r->overrunBaseFrames_countUp = 0;
            r->overrunBaseFrames_countDown = lbl_3_data_4B40[1];
        } else {
            r->overrun1B_somePositionControl +=
                r->overrun1B_someDistConst_proportionPerFrame * r->overrunBaseFrames_countDown;
        }
    }
    if (r->overRun1BStage == 3) {
        r->overrunBaseFrames_countUp++;
        r->overrunBaseFrames_countDown--;
        if (r->overrunBaseFrames_countDown == 0) {
            r->runningDirectionCode = 2;
            r->overRun1BStage = 0;
            fn_3_810C4(runner, 1);
            return 1;
        }
    }
    return 1;
}

// .text:0x00081BC8 size:0x2E4 mapped:0x806C0C5C
// 95.27%: in the first overrun stage the target schedules the int-to-float constant ahead of lbl_3_data_4B44
int fn_3_81BC8(int runner) {
    InMemRunnerType* r = &g_Runners[runner];

    if (r->runningDirectionDesired == 1) {
        r->nextDirectionBeingProcessed = 1;
        r->overrunBaseStage = 0;
        return 0;
    }
    if (r->overrunBaseStage == 1) {
        r->overrunBaseStage = 2;
        r->overrunBaseFrames_countUp = 0;
        r->overrunBaseFrames_countDown = lbl_3_data_4B48[0];
        r->runningDirectionCode = 5;
        r->overrun1B_someDistConst_proportionPerFrame =
            lbl_3_data_4B44 / ((r->overrunBaseFrames_countDown + 1) * (r->overrunBaseFrames_countDown / 2));
    }
    if (r->overrunBaseStage == 2) {
        r->overrunBaseFrames_countUp++;
        r->overrunBaseFrames_countDown--;
        if (r->overrunBaseFrames_countDown < 0) {
            r->overrunBaseStage = 3;
            r->overrunBaseFrames_countUp = 0;
            r->overrunBaseFrames_countDown = lbl_3_data_4B48[1];
            r->overrun1B_someDistConst_proportionPerFrame =
                (r->slidingAdjustment_backwards - r->percentTowardsNextBase) / r->overrunBaseFrames_countDown;
        } else {
            r->percentRanPerFrame_slideAdj = r->overrun1B_someDistConst_proportionPerFrame * r->overrunBaseFrames_countDown;
        }
    }
    if (r->overrunBaseStage == 3) {
        r->overrunBaseFrames_countUp++;
        r->overrunBaseFrames_countDown--;
        if (r->overrunBaseFrames_countDown < 0) {
            r->overrunBaseStage = 0;
            fn_3_81AB8(runner);
            fn_3_810C4(runner, r->currentBase);
        } else {
            r->percentRanPerFrame_slideAdj = r->overrun1B_someDistConst_proportionPerFrame;
            r->offsetFromNormalRunningPathInd = 0;
        }
    }
    r->fractionalBasesRan += r->percentRanPerFrame_slideAdj;
    r->percentTowardsNextBase += r->percentRanPerFrame_slideAdj;
    r->percentFromCurrentBase_slideAdj = r->percentTowardsNextBase - r->slidingAdjustment_backwards;
    r->percentTowardsNextBase_slideAdj = (1.0f - r->percentTowardsNextBase) - r->slidingAdjustment_forwards;
    return 1;
}

// .text:0x00081AEC size:0xDC mapped:0x806C0B80
void fn_3_81AEC(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    f32 step;

    if (r->leadoffDurationFrames < 0x7FFE) {
        r->leadoffDurationFrames++;
    } else {
        r->leadoffDurationFrames = 0x7FFF;
    }
    if (r->leadOffTotalFrameCountDown <= 0) {
        r->leadOffStatus = 2;
        r->percentRanPerFrame_slideAdj = 0.0f;
        return;
    }
    step = r->leadoffDistancePercent + r->slidingAdjustment_backwards;
    step -= r->percentTowardsNextBase;
    step /= r->leadOffTotalFrameCountDown;
    r->percentRanPerFrame_slideAdj = step;
    r->percentTowardsNextBase += step;
    r->fractionalBasesRan = r->startingBase_baseAchieved + r->percentTowardsNextBase;
    r->leadOffTotalFrameCountDown--;
}

// .text:0x00081AB8 size:0x34 mapped:0x806C0B4C
void fn_3_81AB8(int runner) {
    InMemRunnerType* r = &g_Runners[runner];

    r->runningDirectionCode = 2;
    r->nextDirectionBeingProcessed = 2;
    r->groundVelocity[0] = 0.0f;
    r->percentRanPerFrame_slideAdj = 0.0f;
    r->roundingStrengthPercent = 0.0f;
}

// .text:0x00081190 size:0x928 mapped:0x806C0224
void fn_3_81190(int runner) {
    int reverse = 0;
    int arrived = -1;
    InMemRunnerType* r = &g_Runners[runner];
    s16 prevBase = r->baseStandingOn;

    if (r->runnerOnFieldOrOutOrScored != 1 && r->runnerOnFieldOrOutOrScored != 2 && r->runnerOnFieldOrOutOrScored != 4) {
        return;
    }
    if (r->groundVelocity[0] > 0.0f) {
        int base = r->fractionalBasesRan;
        if (base > (int)r->fractionalBasesRan_stored) {
            if (r->baseRoundingState == 2) {
                r->fractionalBasesRan = base;
                r->percentTowardsNextBase = 0.0f;
                if (g_GameLogic.secondaryGameMode == 6) {
                    if (r->fractionalBasesRan >= 4.0f) {
                        r->fractionalBasesRan -= 4.0f;
                    }
                } else if (r->runningDirectionDesired != 1) {
                    r->runningDirectionCode = 2;
                    r->nextDirectionBeingProcessed = 2;
                    r->overrunBaseStage = 1;
                }
            } else if (r->baseRoundingState == 1) {
                r->fractionalBasesRan = base;
                r->percentTowardsNextBase = 0.0f;
            } else if (r->actionCode != 0) {
                r->fractionalBasesRan = base;
                r->percentTowardsNextBase = 0.0f;
                if (r->runnerOnFieldOrOutOrScored != 1) {
                    fn_3_8307C(runner);
                }
            } else {
                arrived = base & 3;
            }
        }
    } else if (r->groundVelocity[0] < 0.0f) {
        if (g_GameLogic.secondaryGameMode == 6) {
            reverse = 1;
        }
        if (g_Ball.AtBat_ContactResult == 3 && r->tagUpInd == 2 && r->currentBase > r->startingBase_baseAchieved) {
            reverse = 1;
        }
        if (reverse != 0) {
            if (r->fractionalBasesRan < 0.0f) {
                r->fractionalBasesRan += 4.0f;
                r->percentTowardsNextBase += 1.0f;
            }
        } else if (r->percentTowardsNextBase <= r->slidingAdjustment_backwards) {
            if (r->actionCode != 0) {
                r->fractionalBasesRan = (int)r->fractionalBasesRan + r->slidingAdjustment_backwards;
                r->percentTowardsNextBase = r->slidingAdjustment_backwards;
            } else {
                arrived = r->currentBase;
            }
        }
    }
    if (arrived >= 0) {
        fn_3_81AB8(runner);
        fn_3_810C4(runner, arrived);
    }
    if (r->runnerOnFieldOrOutOrScored == 1 || (r->runnerOnFieldOrOutOrScored == 4 && g_Ball.AtBat_ContactResult == -1)) {
        r->baseStandingOn = -1;
        if (r->fractionalBasesRan > 0.5f || g_GameLogic.secondaryGameMode == 6) {
            if (r->fractionalBasesRan >= 4.0f) {
                r->baseStandingOn = 0;
            } else if (r->percentTowardsNextBase <= r->slidingAdjustment_backwards) {
                r->baseStandingOn = r->fractionalBasesRan;
            } else if (r->percentTowardsNextBase >= 1.0f - r->slidingAdjustment_forwards) {
                r->baseStandingOn = ((int)r->fractionalBasesRan + 1) & 3;
            }
        }
        if (r->baseStandingOn >= 0) {
            if (r->groundVelocity[0] == 0.0f && r->percentTowardsNextBase > 0.5f) {
                fn_3_810C4(runner, r->baseStandingOn);
            }
            if (r->baseStandingOn == g_Ball.baseBallAndFielderAreOn && prevBase == -1) {
                g_FieldingLogic._125 = -1;
                if (g_FieldingLogic._116 == 1) {
                    if (g_Pitcher.strikeOutOrWalk != 2 ||
                        (!(r->furthestBaseForcedToGoToOnWalk > r->currentBase) &&
                         (r->forcedToAdvanceInd == 0 || r->currentBase != r->startingBase_baseAchieved))) {
                        r->baseOfFailedBodyCheck = r->baseStandingOn;
                        r->baseStandingOn = -1;
                        g_FieldingLogic._111 = 1;
                        g_FieldingLogic._0E8 = runner;
                    }
                } else if (g_Strikes.outs < 3 &&
                           (r->tagUpInd != 2 || g_Ball.baseBallAndFielderAreOn == r->startingBase_baseAchieved)) {
                    fn_3_59918(2, 0);
                }
            } else if (prevBase == -1 && g_Ball.framesSinceHit > 100 && g_Ball.fielderWBallIndex >= 0 &&
                       g_Ball.ballDistanceFromBase[r->baseStandingOn] < 2.5f) {
                if (r->forceOutCd == 1) {
                    fn_3_59918(2, 0);
                } else if (r->tagUpInd == 2) {
                    fn_3_59918(2, 0);
                } else if (r->baseOfFailedBodyCheck < 0 && r->tagType != 2 && r->runnerOnFieldOrOutOrScored != 2 &&
                           (g_FieldingLogic._111 == 2 || g_FieldingLogic._111 == 4)) {
                    fn_3_59918(2, 0);
                }
            }
            fn_3_8307C(runner);
            if (r->baseStandingOn == r->startingBase_baseAchieved && r->tagUpInd == 2) {
                r->tagUpInd = 0;
            }
            if (r->runningDirectionCode == 1) {
                if (r->percentTowardsNextBase < 0.5f) {
                    r->roundingInitiaializedInd = 0;
                    r->offsetPositionForRoundingInd = 0;
                }
            } else if (r->runningDirectionCode == 3) {
                if (r->percentTowardsNextBase > 0.5f) {
                    r->roundingInitiaializedInd = 0;
                    r->offsetPositionForRoundingInd = 0;
                }
            } else {
                r->roundingInitiaializedInd = 0;
                r->offsetPositionForRoundingInd = 0;
            }
            r->overrunning1BIndicator = 0;
        }
        if (r->baseStandingOn == 0) {
            if (g_Strikes.outs < 3 && g_d_GameSettings.GameModeSelected != 7 &&
                (g_Ball.AtBat_ContactResult == 1 || g_Ball.AtBat_ContactResult == 2 ||
                 (g_Ball.AtBat_ContactResult == 3 && r->tagUpInd == 0) ||
                 (g_Ball.AtBat_ContactResult == 0 && g_Strikes.storedOuts == 2) || g_Practice.practiceType_2 == 3)) {
                r->runningDirectionCode = 0;
                r->runnerOnFieldOrOutOrScored = 3;
                if (g_GameLogic.EventTriggers_EndOfGame != 0) {
                    r->runnerOnFieldOrOutOrScored = 4;
                } else if (g_Ball.deadBallReason != 0) {
                    r->runnerOnFieldOrOutOrScored = 4;
                } else {
                    g_Scores._9C++;
                }
                if (r->actionCode != 0) {
                    r->runningToDugoutInd = 2;
                } else {
                    r->runningToDugoutInd = 3;
                }
                r->runningToDugoutStage = 0;
            }
            if (r->actionCode != 0 && r->slideHomeFrames_CountDown == 0 && g_GameLogic.secondaryGameMode != 6) {
                r->slideHomeFrames_CountDown = lbl_3_data_4C54[0];
            }
        } else if (r->fractionalBasesRan >= 4.0f && g_GameLogic.EventTriggers_EndOfGame != 0 && r->actionCode != 0) {
            r->runningToDugoutInd = 2;
        }
    }
}

// .text:0x000810C4 size:0xCC mapped:0x806C0158
void fn_3_810C4(int runner, int base) {
    InMemRunnerType* r = &g_Runners[runner];
    int next = (base + 1) & 3;

    if (g_GameLogic.secondaryGameMode == 6) {
        r->runningAngle = lbl_3_data_4B58[base].z;
        r->percentTowardsNextBase = 0.0f;
    } else {
        r->percentTowardsNextBase = r->slidingAdjustment_backwards;
    }
    r->fractionalBasesRan = r->percentTowardsNextBase + base;
    r->baseStandingOn = base;
    r->currentBaseCoordinates.x = lbl_3_data_4A34[base].x;
    r->currentBaseCoordinates.z = lbl_3_data_4A34[base].z;
    r->nextBaseCoordinates.x = lbl_3_data_4A34[next].x;
    r->nextBaseCoordinates.z = lbl_3_data_4A34[next].z;
}

// .text:0x00080028 size:0x109C mapped:0x806BF0BC
// 97.54%: the overrun and action steps schedule the target point's loads later, the dugout
// velocity takes the speed as the second fmuls operand, and some FPR pairs are swapped.
void fn_3_80028(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    VecXYZ p;
    f32 bx;
    f32 bz;
    f32 by;
    VecXYZ out;
    VecXYZ d;
    f32 a;
    f32 b;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 t;

    if (g_GameLogic.secondaryGameMode != 6) {
        if (g_Ball.framesSinceHit <= 0 && runner == 0) {
            r->position.x = g_Batter.batterPos.x;
            r->position.y = 0.0f;
            r->position.z = g_Batter.batterPos.z;
            r->fractionalBasesRan = 0.0f;
            r->percentTowardsNextBase = 0.0f;
            r->fractionalBasesRan_stored = 0.0f;
            r->percentTowardsNextBase_stored = 0.0f;
            r->groundVelocity[0] = 0.0f;
            r->runningDirectionCode = 0;
            r->nextDirectionBeingProcessed = 0;
        } else if (r->overRun1BStage >= 2) {
            if (r->overRun1BStage == 2) {
                // The target writes this point into out's stack slot, which keeps the step stores below
                running_roundBasePosition(r->overrun1B_somePositionControl, (VecXZ*)&out, lbl_3_data_4B28, 3);
                r->position.x = ((VecXZ*)&out)->x;
                r->position.z = ((VecXZ*)&out)->z;
            } else if (r->overRun1BStage == 3) {
                fn_3_7FFD0(&p, 1, 2, r->slidingAdjustment_backwards);
                out.x = (p.x - r->position.x) / r->overrunBaseFrames_countDown;
                out.y = (p.y - r->position.y) / r->overrunBaseFrames_countDown;
                out.z = (p.z - r->position.z) / r->overrunBaseFrames_countDown;
                r->position.x += out.x;
                r->position.y += out.y;
                r->position.z += out.z;
            }
        } else if (r->slideHomeFrames_CountDown != 0) {
            r->slideHomeFrames_CountDown--;
        } else if (r->actionCode != 0 && r->actionStage == 2) {
            if (r->timeStandingOnBase >= 6) {
                if (r->baseOfFailedBodyCheck >= 0) {
                    fn_3_7FFD0(&p, r->baseOfFailedBodyCheck, (r->baseOfFailedBodyCheck + 1) & 3,
                               r->slidingAdjustment_backwards);
                } else {
                    fn_3_7FFD0(&p, r->baseStandingOn, (r->baseStandingOn + 1) & 3, r->slidingAdjustment_backwards);
                }
                out.x = (p.x - r->position.x) / r->actionFrames_countDown;
                out.y = (p.y - r->position.y) / r->actionFrames_countDown;
                out.z = (p.z - r->position.z) / r->actionFrames_countDown;
                r->position.x += out.x;
                r->position.y += out.y;
                r->position.z += out.z;
            }
        } else if (r->runningToDugoutInd == 1) {
                if (r->runningToDugoutStage == 0) {
                    r->nextBaseCoordinates.x =
                        lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.homeTeamBattingInd_fieldingTeam].x;
                    r->nextBaseCoordinates.z =
                        lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.homeTeamBattingInd_fieldingTeam].z;
                    dx = r->nextBaseCoordinates.x - r->position.x;
                    dz = r->nextBaseCoordinates.z - r->position.z;
                    dist = dolsqrtf2(dx * dx + dz * dz);
                    r->velocity.x = (dx / dist) * lbl_3_data_4B50;
                    r->velocity.z = (dz / dist) * lbl_3_data_4B50;
                    r->velocity.y = 0.0f;
                    r->runningToDugoutFrameCounter = 0;
                    r->framesToReachDugout = (s16)(dist / lbl_3_data_4B50) + 1;
                    r->runningToDugoutStage = 2;
                }
                if (r->runningToDugoutStage == 2) {
                    r->runningToDugoutFrameCounter++;
                    r->framesToReachDugout--;
                    r->position.x += r->velocity.x;
                    r->position.y += r->velocity.y;
                    r->position.z += r->velocity.z;
                    if (r->framesToReachDugout < 0) {
                        r->velocity.x = 0.0f;
                        r->velocity.y = 0.0f;
                        r->velocity.z = 0.0f;
                        r->runningToDugoutStage = 3;
                    }
                }
        } else if (r->runningToDugoutInd == 3) {
                if (r->runningToDugoutStage == 0) {
                    r->nextBaseCoordinates.x =
                        lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.homeTeamBattingInd_fieldingTeam].x;
                    r->nextBaseCoordinates.z =
                        lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.homeTeamBattingInd_fieldingTeam].z;
                    dx = r->nextBaseCoordinates.x - r->position.x;
                    dz = r->nextBaseCoordinates.z - r->position.z;
                    dist = dolsqrtf2(dx * dx + dz * dz);
                    dist = dolsqrtf2(r->velocity.x * r->velocity.x + r->velocity.z * r->velocity.z);
                    if (dist <= 0.0f) {
                        r->velocity.x = 1.0f;
                        r->velocity.z = -1.0f;
                    } else {
                        r->velocity.x /= dist;
                        r->velocity.z /= dist;
                    }
                    r->velocity.y = 0.0f;
                    r->velocity.x *= r->maximumBaseVelocity;
                    r->velocity.z *= r->maximumBaseVelocity;
                    r->runningToDugoutFrameCounter = 0;
                    r->framesToReachDugout = lbl_3_data_4B54;
                    r->runningToDugoutStage = 1;
                }
                if (r->runningToDugoutStage == 1) {
                    r->framesToReachDugout--;
                    r->position.x += r->velocity.x;
                    r->position.y += r->velocity.y;
                    r->position.z += r->velocity.z;
                    if (r->framesToReachDugout <= 0) {
                        r->nextBaseCoordinates.x =
                            lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.homeTeamBattingInd_fieldingTeam].x;
                        r->nextBaseCoordinates.z =
                            lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.homeTeamBattingInd_fieldingTeam].z;
                        dx = r->nextBaseCoordinates.x - r->position.x;
                        dz = r->nextBaseCoordinates.z - r->position.z;
                        dist = dolsqrtf2(dx * dx + dz * dz);
                        r->velocity.x = (dx / dist) * lbl_3_data_4B50;
                        r->velocity.z = (dz / dist) * lbl_3_data_4B50;
                        r->velocity.y = 0.0f;
                        r->runningToDugoutFrameCounter = 0;
                        r->framesToReachDugout = (s16)(dist / lbl_3_data_4B50) + 1;
                        r->runningToDugoutStage = 2;
                    }
                }
                if (r->runningToDugoutStage == 2) {
                    r->runningToDugoutFrameCounter++;
                    r->framesToReachDugout--;
                    r->position.x += r->velocity.x;
                    r->position.y += r->velocity.y;
                    r->position.z += r->velocity.z;
                    if (r->framesToReachDugout < 0) {
                        r->velocity.x = 0.0f;
                        r->velocity.y = 0.0f;
                        r->velocity.z = 0.0f;
                        r->runningToDugoutStage = 3;
                    }
                }
        } else if (r->runningToDugoutInd != 0) {
                if (r->runningToDugoutStage == 0) {
                    r->nextBaseCoordinates.x =
                        lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.homeTeamBattingInd_fieldingTeam].x;
                    r->nextBaseCoordinates.z =
                        lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.homeTeamBattingInd_fieldingTeam].z;
                    dx = r->nextBaseCoordinates.x - r->position.x;
                    dz = r->nextBaseCoordinates.z - r->position.z;
                    dist = dolsqrtf2(dx * dx + dz * dz);
                    r->velocity.x = (dx / dist) * lbl_3_data_4B50;
                    r->velocity.z = (dz / dist) * lbl_3_data_4B50;
                    r->velocity.y = 0.0f;
                    r->runningToDugoutFrameCounter = 0;
                    r->framesToReachDugout = (s16)(dist / lbl_3_data_4B50) + 1;
                    r->runningToDugoutStage = 2;
                }
                if (r->runningToDugoutStage == 2) {
                    r->runningToDugoutFrameCounter++;
                    r->framesToReachDugout--;
                    r->position.x += r->velocity.x;
                    r->position.y += r->velocity.y;
                    r->position.z += r->velocity.z;
                    if (r->framesToReachDugout < 0) {
                        r->velocity.x = 0.0f;
                        r->velocity.y = 0.0f;
                        r->velocity.z = 0.0f;
                        r->runningToDugoutStage = 3;
                    }
                }
        } else {
            goto normal;
        }
    } else {
    normal:
        d.x = r->nextBaseCoordinates.x - r->currentBaseCoordinates.x;
        d.y = r->nextBaseCoordinates.y - r->currentBaseCoordinates.y;
        d.z = r->nextBaseCoordinates.z - r->currentBaseCoordinates.z;
        d.x *= r->percentTowardsNextBase;
        d.y *= r->percentTowardsNextBase;
        d.z *= r->percentTowardsNextBase;
        bx = r->currentBaseCoordinates.x + d.x;
        by = r->currentBaseCoordinates.y + d.y;
        bz = r->currentBaseCoordinates.z + d.z;
        fn_3_7FED4(&out, r->fractionalBasesRan, r->percentTowardsNextBase);
        if (r->overrunning1BIndicator != 0 && r->fractionalBasesRan < 2.0f) {
            if (r->runningDirectionCode == 1) {
                a = 1.0f - r->percentTowardsNextBase_stored;
                b = 1.0f - r->percentTowardsNextBase;
                d.x = r->nextBaseCoordinates.x - r->positionStored.x;
                d.y = r->nextBaseCoordinates.y - r->positionStored.y;
                d.z = r->nextBaseCoordinates.z - r->positionStored.z;
            } else {
                a = -r->percentTowardsNextBase_stored;
                b = -r->percentTowardsNextBase;
                d.x = r->currentBaseCoordinates.x - r->positionStored.x;
                d.y = r->currentBaseCoordinates.y - r->positionStored.y;
                d.z = r->currentBaseCoordinates.z - r->positionStored.z;
            }
            if (a == 0.0f) {
                out.x = bx;
                out.y = by;
                out.z = bz;
            } else {
                t = 1.0f - b / a;
                d.x *= t;
                d.y *= t;
                d.z *= t;
                out.x = r->positionStored.x + d.x;
                out.y = r->positionStored.y + d.y;
                out.z = r->positionStored.z + d.z;
            }
            r->position.x = out.x;
            r->position.y = out.y;
            r->position.z = out.z;
        } else if (r->offsetFromNormalRunningPathInd != 0 && r->roundingInitiaializedInd == 0) {
            if (r->runningDirectionCode != 2 && r->nextDirectionBeingProcessed == 0 && r->turningAroundInd != 1) {
                r->roundingStrengthPercent += lbl_3_data_4B24;
            }
            if (r->roundingStrengthPercent < 0.0f) {
                r->roundingStrengthPercent = 0.0f;
            }
            if (r->roundingStrengthPercent > 1.0f) {
                r->roundingStrengthPercent = 1.0f;
            }
            d.x = out.x - bx;
            d.y = out.y - by;
            d.z = out.z - bz;
            d.x *= r->roundingStrengthPercent;
            d.y *= r->roundingStrengthPercent;
            d.z *= r->roundingStrengthPercent;
            r->position.x = bx + d.x;
            r->position.y = by + d.y;
            r->position.z = bz + d.z;
            r->offsetPositionForRoundingInd = 1;
            r->_110 = 0;
        } else {
            r->roundingStrengthPercent = 0.0f;
            if (r->offsetPositionForRoundingInd == 0) {
                r->position.x = bx;
                r->position.y = by;
                r->position.z = bz;
            } else {
                if (g_GameLogic.secondaryGameMode != 6) {
                    r->roundingInitiaializedInd = 1;
                }
                if (r->runningDirectionCode == 1) {
                    a = 1.0f - r->percentTowardsNextBase_stored;
                    b = 1.0f - r->percentTowardsNextBase;
                    if (b > a) {
                        a += 1.0f;
                    }
                    d.x = r->nextBaseCoordinates.x - r->positionStored.x;
                    d.y = r->nextBaseCoordinates.y - r->positionStored.y;
                    d.z = r->nextBaseCoordinates.z - r->positionStored.z;
                } else {
                    a = -r->percentTowardsNextBase_stored;
                    b = -r->percentTowardsNextBase;
                    d.x = r->currentBaseCoordinates.x - r->positionStored.x;
                    d.y = r->currentBaseCoordinates.y - r->positionStored.y;
                    d.z = r->currentBaseCoordinates.z - r->positionStored.z;
                }
                if (a == 0.0f) {
                    out.x = bx;
                out.y = by;
                out.z = bz;
                } else {
                    t = 1.0f - b / a;
                    d.x *= t;
                    d.y *= t;
                    d.z *= t;
                    out.x = r->positionStored.x + d.x;
                    out.y = r->positionStored.y + d.y;
                    out.z = r->positionStored.z + d.z;
                }
                r->position.x = out.x;
                r->position.y = out.y;
                r->position.z = out.z;
            }
        }
    }
    r->position.y = 0.0f;
}

// .text:0x0007FFD0 size:0x58 mapped:0x806BF064
void fn_3_7FFD0(VecXYZ* out, int from, int to, f32 t) {
    VecXZ d;
    d.x = (lbl_3_data_4A34[to].x - lbl_3_data_4A34[from].x);
    d.z = (lbl_3_data_4A34[to].z - lbl_3_data_4A34[from].z);
    d.x *= t;
    d.z *= t;
    out->x = d.x + lbl_3_data_4A34[from].x;
    out->z = d.z + lbl_3_data_4A34[from].z;
    out->y = 0.0f;
}

// .text:0x0007FED4 size:0xFC mapped:0x806BEF68
void fn_3_7FED4(VecXYZ* out, f32 pos, f32 t) {
    VecXZ p;
    int start;
    int count;

    if (pos < 1.0f) {
        start = 0;
        count = 4;
    } else if (pos < 2.0f) {
        start = 3;
        count = 4;
    } else if (pos < 3.0f) {
        start = 6;
        count = 4;
    } else if (g_GameLogic.secondaryGameMode == 6) {
        start = 9;
        count = 4;
    } else {
        start = 9;
        count = 3;
    }
    running_roundBasePosition(t, &p, &lbl_3_data_4A54[g_GameLogic.secondaryGameMode == 6][start], count);
    out->x = p.x;
    out->z = p.z;
    out->y = 0.0f;
}

// .text:0x0007FEA8 size:0x2C mapped:0x806BEF3C
void fn_3_7FEA8(int runner, int direction) {
    InMemRunnerType* r = &g_Runners[runner];

    if (r->rosterID >= 0 && direction != 0) {
        r->runningDirectionDesired = direction;
    }
}

// .text:0x0007FD90 size:0x118 mapped:0x806BEE24
void fn_3_7FD90(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    int forced;

    if ((r->runningToDugoutInd == 0 || r->runningToDugoutStage == 0) && r->actionCode == 0) {
        if (r->framesSinceLastDirectionChange >= lbl_3_data_4C54[3] ||
            (r->runningDirectionCode != 1 && r->runningDirectionCode != 3)) {
            if (r->runningDirectionDesired != 0) {
                if (g_GameLogic.secondaryGameMode == 6) {
                    if (r->runnerOnFieldOrOutOrScored == 1) {
                        r->nextDirectionBeingProcessed = r->runningDirectionDesired;
                    }
                } else {
                    if ((runner != 0 || r->nextBase != 1) && r->runnerOnFieldOrOutOrScored == 1) {
                        r->nextDirectionBeingProcessed = r->runningDirectionDesired;
                    }
                    if (r->nextDirectionBeingProcessed == 3 && r->tagUpInd != 3 && r->baseStandingOn >= 0) {
                        r->nextDirectionBeingProcessed = 0;
                    }
                }
            }
        }
        forced = fn_3_7FA78(runner);
        if (forced != 0) {
            r->nextDirectionBeingProcessed = forced;
        }
    }
}

// .text:0x0007FA78 size:0x318 mapped:0x806BEB0C
int fn_3_7FA78(int runner) {
    InMemRunnerType* r = &g_Runners[runner];

    if (g_GameLogic.secondaryGameMode == 6) {
        if (g_Minigame.turnOverStatus != 0) {
            return 2;
        }
        if (g_Minigame._1B19 == 2 || g_Minigame._1B19 == 3) {
            return 2;
        }
        return 0;
    }
    if (g_GameLogic.secondaryGameMode != 14) {
        if (g_Ball.framesSinceHit <= 0) {
            return 0;
        }
        if (g_FieldingLogic._107 == 1) {
            if (runner != 0 && r->runningDirectionCode == 2 && r->runningDirectionDesired == 0 &&
                g_Ball.framesSincePickOff == lbl_3_data_4C54[4]) {
                return 3;
            }
        } else if (g_FieldingLogic._107 == 2) {
            if (runner != 0 && r->runningDirectionCode == 2 && r->runningDirectionDesired == 0 &&
                g_Ball.framesSincePickOff == lbl_3_data_4C54[4]) {
                return 3;
            }
        }
        if (runner == 0) {
            if (r->fractionalBasesRan < 1.0f && r->forceOutCd == 1 && g_FieldingLogic._108 == 0 && g_FieldingLogic._107 == 0) {
                return 1;
            }
        } else if (r->leadOffStatus == 1) {
            return 1;
        }
        if (g_Ball.deadBallReason == 1) {
            return 1;
        }
        if (g_Ball.framesSinceHit == 5) {
            return 1;
        }
    }
    if (r->restrictedMovementCodes & 4) {
        if (r->runningDirectionCode == 1) {
            return 2;
        }
        if (r->nextDirectionBeingProcessed == 1 && r->runningDirectionCode == 2) {
            return 2;
        }
    } else if (r->restrictedMovementCodes & 1) {
        if ((r->baseRoundingState != 1 || r->overRun1BStage == 0) && r->runningDirectionCode == 1) {
            return 2;
        }
        if (r->nextDirectionBeingProcessed == 1) {
            return 2;
        }
    } else if (r->restrictedMovementCodes & 2) {
        if (r->runningDirectionCode == 3) {
            return 2;
        }
        if (r->nextDirectionBeingProcessed == 3) {
            return 2;
        }
    } else if (r->restrictedMovementCodes_stored & 4) {
        if (!(r->restrictedMovementCodes & 1) && g_Ball.framesSinceHit > 0 &&
            (r->runningDirectionCode == 2 || r->nextDirectionBeingProcessed == 2) && r->tagUpInd == 0) {
            return 1;
        }
    } else if ((r->restrictedMovementCodes_stored & 8) && !(r->restrictedMovementCodes & 2) &&
               (r->runningDirectionCode == 2 || r->nextDirectionBeingProcessed == 2)) {
        return 3;
    }
    if (g_Ball.AtBat_ContactResult == 3 && r->tagUpInd == 2) {
        return 3;
    }
    return 0;
}

// .text:0x0007F9C4 size:0xB4 mapped:0x806BEA58
void fn_3_7F9C4(int runner) {
    InMemRunnerType* r = &g_Runners[runner];

    if (r->runningToDugoutInd != 0) {
        r->baseRoundingState = 0;
        r->actionCode = 0;
        return;
    }
    fn_3_7ECFC(runner);
    fn_3_7F494(runner);
    if (g_GameLogic.secondaryGameMode != 6) {
        if (runner == 0 && r->nextBase == 1) {
            fn_3_7F2D8();
        } else if (r->baseRoundingState == 1) {
            r->baseRoundingState = 0;
        }
        fn_3_7EBD4(runner);
    }
}

// .text:0x0007F494 size:0x530 mapped:0x806BE528
// 99.64%: registers differ only where the body-check fielder and its probability row are addressed
int fn_3_7F494(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    int bodyCheck = 0;
    int frames;
    f32 t;

    if (g_GameLogic.secondaryGameMode == 6) {
        return 0;
    }
    if (r->runnerOnFieldOrOutOrScored != 1 && r->runnerOnFieldOrOutOrScored != 2) {
        return 0;
    }
    if (r->baseStandingOn >= 0) {
        return 0;
    }
    if (!(r->runningDirectionCode == 1 && r->percentRanPerFrame_slideAdj > 0.0f) &&
        !(r->runningDirectionCode == 3 && r->percentRanPerFrame_slideAdj < 0.0f)) {
        return 0;
    }
    if (r->actionCode != 0) {
        return 1;
    }
    if (r->baseRoundingState == 2) {
        return 0;
    }
    if (r->nextBase == 1) {
        return 0;
    }
    if (r->runningDirectionCode == 3) {
        if (r->tagUpInd == 2 && r->currentBase != r->startingBase_baseAchieved) {
            return 0;
        }
        if (r->forceOutCd == 1 && g_Ball.AtBat_ContactResult != 0) {
            return 0;
        }
    }
    if (r->runningDirectionCode == 1) {
        t = r->percentTowardsNextBase_slideAdj / r->percentRanPerFrame_slideAdj;
    } else {
        t = r->percentFromCurrentBase_slideAdj / -r->percentRanPerFrame_slideAdj;
    }
    frames = (int)t + 1;
    if (g_Ball.ballState == 2) {
        if (g_FieldingLogic._0C4 == r->baseRunningTowards) {
            int margin = g_Ball.framesUntilThrowReachesDest + 6 - frames;
            if (margin >= lbl_3_data_4C54[1] && margin <= lbl_3_data_4C54[2]) {
                bodyCheck = 1;
            }
        }
    } else if (g_Ball.ballState == 1) {
        int margin = 6 - g_Ball.timeSinceBallPickedUp - frames;
        if (margin >= lbl_3_data_4C54[1] && margin <= lbl_3_data_4C54[2]) {
            bodyCheck = 1;
        }
    }
    if (frames < lbl_3_data_7760[r->charID][0] || frames > lbl_3_data_7760[r->charID][1]) {
        return 0;
    }
    r->actionCode = 1;
    r->actionFrames_countUp = 0;
    r->actionFrames_countDown = frames;
    r->actionStage = 1;
    if (r->runningDirectionCode == 1) {
        r->actionInForwardDirectionInd = 1;
        if (bodyCheck != 0 && r->forceOutCd == 0 && r->mashPercent >= lbl_3_data_4C44[0] &&
            checkFieldingStat(g_GameLogic.teamBatting, r->rosterID, 12)) {
            u8 base = r->baseRunningTowards;
            if (g_FieldingLogic._101[base] != 0 &&
                ((g_Ball.fielderWBallIndex >= 0 && g_Ball.fielderWBallIndex == g_FieldingLogic._0D0[base] &&
                  g_Ball.timeSinceBallPickedUp <= 9) ||
                 (g_FieldingLogic._0C4 == base && g_Ball.framesUntilThrowReachesDest < 15))) {
                Unk13B8Fielder* fielder = &g_Fielders[g_FieldingLogic._0D0[base]];
                u8 chance = bodyCheckProbabiliities[r->weight][fielder->_1C9];

                fielder->_211 = 1;
                fielder->_214 = r->baseRunningTowards;
                if (RandomInt_Game(100) < chance) {
                    r->actionCode = 2;
                    if (g_d_GameSettings.exhibitionMatchInd == 0 && lbl_3_common_bss_37400._40 == g_GameLogic.teamBatting) {
                        fn_3_161588(12, r->rosterID);
                    }
                } else {
                    r->actionCode = 3;
                    if (g_GameLogic._13E[g_GameLogic.teamBatting] == 0) {
                        fn_3_6C854(g_GameLogic.teamBatting, 2);
                    }
                }
                fn_3_1682AC(lbl_8036E548._2C74[runner], 12);
                fn_3_90220(r->charID, 10);
                playSoundEffect(0x19C);
                fn_3_1AE44(4, 0, lbl_3_data_4444[r->baseRunningTowards].x, 0.0f, lbl_3_data_4444[r->baseRunningTowards].z);
            }
        }
    } else {
        r->actionInForwardDirectionInd = 0;
    }
    if (r->forceOutCd == 1 && r->baseRunningTowards != r->startingBase_baseAchieved) {
        r->forceOutType_unsed = 1;
    }
    if (r->tagUpInd == 2 && r->baseRunningTowards == r->startingBase_baseAchieved) {
        r->forceOutType_unsed = 2;
    }
    if (g_Pitcher.strikeOutOrWalk == 2 &&
        (r->furthestBaseForcedToGoToOnWalk > r->currentBase ||
         (r->forcedToAdvanceInd != 0 && r->currentBase == r->startingBase_baseAchieved))) {
        r->forceOutType_unsed = 3;
    }
    return 1;
}

// .text:0x0007F2D8 size:0x1BC mapped:0x806BE36C
int fn_3_7F2D8(void) {
    InMemRunnerType* r = &g_Runners[0];

    if (r->actionCode == 0 && r->overrun1st_doneChecking == 0) {
        if (r->overRun1BStage != 0) {
            return 1;
        }
        if (g_Ball.AtBat_ContactResult != 3) {
            if (r->fractionalBasesRan < 0.5f ||
                (g_Ball.AtBat_ContactResult == 0 && g_Runners[1].runnerOnFieldOrOutOrScored == 1 &&
                 (g_Runners[1].baseStandingOn == 1 ||
                  (g_Ball.landingSpotZoneAwayFromHome <= 2 && g_Runners[1].fractionalBasesRan < 1.5f))) ||
                (!(g_Ball.AtBat_ContactResult == 0 && g_Ball.maxYOfHit > 15.0f) &&
                 (g_Ball.ballZoneAwayFromHome <= 1 || (g_Ball.ballZoneAwayFromHome <= 2 && g_Ball.ballVelocity < 0.2f) ||
                  (g_Ball.fielderWBallIndex >= 0 && g_Ball.ballDistanceFromBase[1] < 25.0f) ||
                  (g_Ball.fielderWBallIndex == 8 && r->fractionalBasesRan <= 0.75f) ||
                  (g_FieldingLogic._0C4 == 1 && g_Ball.ballState == 2 &&
                   r->framesToNextBase + 30 > g_Ball.framesUntilThrowReachesDest)))) {
                goto round;
            }
            r->overrun1st_doneChecking = 1;
        }
    }
    if (r->baseRoundingState == 1) {
        r->baseRoundingState = 0;
    }
    return 0;

round:
    r->baseRoundingState = 1;
    if (r->fractionalBasesRan > 0.8f) {
        r->overRun1BStage = 1;
    }
    return 1;
}

// .text:0x0007ECFC size:0x5DC mapped:0x806BDD90
int fn_3_7ECFC(int runner) {
    InMemRunnerType* r = &g_Runners[runner];
    f32 throwDist = 100.0f;
    int cutBack = 0;

    if (g_GameLogic.secondaryGameMode == 6) {
        r->baseRoundingState = 2;
        r->offsetFromNormalRunningPathInd = 1;
        return 1;
    }
    if (r->baseRoundingState == 2) {
        r->baseRoundingState = 0;
    }
    r->offsetFromNormalRunningPathInd = 0;
    if (g_Ball.framesSinceHit <= 0 && g_Practice.practiceType_2 != 3) {
        return 0;
    }
    if (r->actionCode != 0) {
        return 0;
    }
    if (r->baseRoundingState == 1) {
        return 0;
    }
    if (r->runningDirectionCode == 3) {
        cutBack = 1;
    } else {
        if (g_FieldingLogic._0C4 >= 0) {
            throwDist = VEC_DISTANCE_XZ(&lbl_3_data_4444[r->baseRunningTowards], &g_Ball.throwTarget) +
                        VEC_DISTANCE_XZ(&g_Ball.AtBat_Contact_BallPos, &g_Ball.throwTarget);
        }
        if (r->distanceFromBall < 15.0f) {
            cutBack = 1;
        } else if (throwDist < 20.0f) {
            cutBack = 1;
        } else if (g_Pitcher.strikeOutOrWalk >= 2) {
            cutBack = 1;
        } else if (g_Ball.ballZoneAwayFromHome <= 1 &&
                   (g_Ball.AtBat_ContactResult == 1 || g_Ball.AtBat_ContactResult == 2) &&
                   r->percentTowardsNextBase < 0.7f) {
            cutBack = 1;
        } else if (g_FieldingLogic._107 == 2) {
            cutBack = 1;
        }
        if (g_Practice.practiceType_2 == 3) {
            cutBack = 0;
        }
        if (cutBack != 0 && g_Ball.ballState == 0 && g_Ball.ballZoneAwayFromHome >= 1 && g_Ball.ballVelocity > 0.35f &&
            r->percentTowardsNextBase >= 0.65f && r->percentTowardsNextBase <= 0.8f &&
            g_Ball.ballDistanceFromHome > 2.0f + g_Fielders[2]._70 &&
            g_Ball.ballDistanceFromHome > 2.0f + g_Fielders[4]._70) {
            if (g_Ball.ballDistanceFromHome > 2.0f + g_Fielders[3]._70 &&
                g_Ball.ballDistanceFromHome > 2.0f + g_Fielders[5]._70) {
                cutBack = 0;
            } else if (g_Fielders[3]._7C > g_Fielders[3]._70 - g_Ball.ballDistanceFromHome &&
                       g_Fielders[5]._7C > g_Fielders[5]._70 - g_Ball.ballDistanceFromHome) {
                cutBack = 0;
            }
        }
    }
    if (g_Ball.ballState == 1 && g_Ball.ballDistanceFromBase[r->baseRunningTowards] < 25.0f &&
        r->percentTowardsNextBase > 0.5f) {
        cutBack = 1;
    }
    if ((r->runningDirectionCode == 1 || r->runningDirectionCode == 2) && 0.0f == r->roundingStrengthPercent &&
        (r->percentTowardsNextBase < 0.5f || r->fractionalBasesRan >= 3.0f)) {
        cutBack = 1;
    }
    if (r->overrunBaseStage != 3 && cutBack != 0) {
        r->offsetFromNormalRunningPathInd = 0;
        return 0;
    }
    r->baseRoundingState = 2;
    r->offsetFromNormalRunningPathInd = 1;
    if (r->baseStandingOn >= 0) {
        r->roundingStrengthPercent = 1.0f;
    }
    return 1;
}

// .text:0x0007EBD4 size:0x128 mapped:0x806BDC68
void fn_3_7EBD4(int runner) {
    InMemRunnerType* r = &g_Runners[runner];

    if (g_GameLogic.gameStatus == 1) {
        return;
    }
    if (r->runnerOnFieldOrOutOrScored == 2) {
        if (r->runningToDugoutInd != 0) {
            return;
        }
        if (r->actionCode != 0) {
            if (r->actionStage == 3) {
                r->actionCode = 0;
                r->actionStage = 0;
            } else {
                return;
            }
        }
        if (r->forceOutCd == 2) {
            if (r->overRun1BStage != 0) {
                if (r->overRun1BStage == 3) {
                    r->baseRoundingState = 0;
                    r->overRun1BStage = 0;
                } else {
                    return;
                }
            } else if (r->percentTowardsNextBase < 0.8f || r->runningDirectionCode == 2) {
            } else {
                return;
            }
        }
        r->runningToDugoutInd = 1;
        r->runningToDugoutStage = 0;
        r->overRun1BStage = 0;
    } else if (g_Strikes.outs >= 3) {
        if (r->actionCode != 0) {
            if (r->actionStage == 3) {
                r->actionCode = 0;
                r->actionStage = 0;
            } else {
                return;
            }
        }
        r->runningToDugoutInd = 1;
        r->runningToDugoutStage = 0;
    }
}

// .text:0x0007EA68 size:0x16C mapped:0x806BDAFC
void fn_3_7EA68(void) {
    InputStruct* input = &g_Controls[g_GameLogic.teams[g_GameLogic.teamBatting]];

    if (g_Pitcher.pitcherActionState != 1 && g_Pitcher.pitcherActionState != 2 && g_Pitcher.pitcherActionState != 3) {
        return;
    }
    if (ACTIVE_TUTORIAL()) {
        input = &g_Practice.inputs[g_GameLogic.teamBatting];
    }
    if (!(input->newButtonInput & 0x800)) {
        return;
    }
    if (input->controlStickAngle < 0) {
        int i;
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored != 0 && g_Runners[i].stealingStatus == 0) {
                g_Runners[i].stealingStatus = 1;
            }
        }
    } else {
        if (input->controlStickAngle >= 0x1C0 && input->controlStickAngle <= 0x640) {
            g_Runners[1].stealingStatus = 1;
        }
        if (input->controlStickAngle >= 0x5C0 && input->controlStickAngle <= 0xA40) {
            g_Runners[2].stealingStatus = 1;
        }
        if (input->controlStickAngle >= 0x9C0 && input->controlStickAngle <= 0xE40) {
            g_Runners[3].stealingStatus = 1;
        }
    }
}

// .text:0x0007E2BC size:0x7AC mapped:0x806BD350
// 99.46%: registers differ in the stick-held branch (base and i swapped) and the third loop's
// handled counter starts as li 0 here where the target copies it from i with mr
void fn_3_7E2BC(void) {
    InputStruct* input = &g_Controls[g_GameLogic.teams[g_GameLogic.teamBatting]];
    int i;
    int reverse;
    u16 buttons;

    if (g_d_GameSettings.GameModeSelected == 2 && g_Practice.loadingGuidedPractice != 0) {
        return;
    }
    if (ACTIVE_TUTORIAL()) {
        input = &g_Practice.inputs[g_GameLogic.teamBatting];
    }
    buttons = input->buttonInput;
    if (g_Ball.framesSinceHit < 30) {
        buttons = input->newButtonInput;
    }
    if (input->controlStickAngle < 0) {
        reverse = 0;
        for (i = 0; i < 4; i++) {
            InMemRunnerType* r = &g_Runners[i];
            if (r->runnerOnFieldOrOutOrScored == 1) {
                if (r->runningDirectionCode == 3) {
                    if (r->nextDirectionBeingProcessed != 2 && r->nextDirectionBeingProcessed != 1 &&
                        (input->newButtonInput & 0x800)) {
                        reverse = 1;
                        break;
                    }
                } else if (r->runningDirectionCode == 1 && r->currentBase != 0 && r->nextDirectionBeingProcessed != 2 &&
                           r->nextDirectionBeingProcessed != 3 && (input->newButtonInput & 0x400)) {
                    reverse = 1;
                    break;
                }
            }
        }
        if (reverse != 0) {
            for (i = 0; i < 4; i++) {
                if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
                    fn_3_7FEA8(i, 2);
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                InMemRunnerType* r = &g_Runners[i];
                if (r->runnerOnFieldOrOutOrScored != 1) {
                    continue;
                }
                if (r->runningDirectionCode == 3) {
                    if (r->nextDirectionBeingProcessed == 2 || r->nextDirectionBeingProcessed == 1) {
                        if (buttons & 0x400) {
                            fn_3_7FEA8(i, 3);
                        } else if (input->newButtonInput & 0x800) {
                            fn_3_7FEA8(i, 1);
                        }
                    }
                } else if (r->runningDirectionCode == 1) {
                    if (r->nextDirectionBeingProcessed == 2 || r->nextDirectionBeingProcessed == 3) {
                        if (input->newButtonInput & 0x400) {
                            fn_3_7FEA8(i, 3);
                        } else if (buttons & 0x800) {
                            fn_3_7FEA8(i, 1);
                        }
                    }
                } else if (r->runningDirectionCode == 5 && (buttons & 0x800)) {
                    fn_3_7FEA8(i, 1);
                } else if (input->newButtonInput & 0x800) {
                    fn_3_7FEA8(i, 1);
                } else if (input->newButtonInput & 0x400) {
                    fn_3_7FEA8(i, 3);
                }
            }
        }
        if (input->newButtonInput & 0xF00) {
            g_Runners[0].newButtonThisFrame_forMashPurposes = 1;
            g_Runners[1].newButtonThisFrame_forMashPurposes = 1;
            g_Runners[2].newButtonThisFrame_forMashPurposes = 1;
            g_Runners[3].newButtonThisFrame_forMashPurposes = 1;
        }
        if (ACTIVE_TUTORIAL() && g_Practice.practice_runner_countInputForMashing != 0) {
            g_Runners[0].newButtonThisFrame_forMashPurposes = 1;
            g_Runners[1].newButtonThisFrame_forMashPurposes = 1;
            g_Runners[2].newButtonThisFrame_forMashPurposes = 1;
            g_Runners[3].newButtonThisFrame_forMashPurposes = 1;
        }
    } else if (buttons & 0x800) {
        int base = -1;
        int waited;

        if (input->controlStickAngle >= 0xA00 && input->controlStickAngle < 0xE00) {
            base = 0;
        } else if (input->controlStickAngle >= 0x600) {
            base = 3;
        } else if (input->controlStickAngle >= 0x200) {
            base = 2;
        }
        if (base < 0) {
            return;
        }
        waited = 0;
        for (i = 3; i >= 0; i--) {
            InMemRunnerType* r = &g_Runners[i];
            if (r->runnerOnFieldOrOutOrScored != 1 || r->nextBase != base) {
                continue;
            }
            if (waited != 0) {
                if (r->_151 <= 0) {
                    r->_151 = 1;
                } else {
                    r->_151++;
                }
                r->someCountdown_unused = lbl_3_data_4C54[5];
                if (r->_151 <= lbl_3_data_4C54[6]) {
                    return;
                }
            }
            if (r->runningDirectionCode == 1) {
                if (r->nextDirectionBeingProcessed == 2 || r->nextDirectionBeingProcessed == 3) {
                    fn_3_7FEA8(i, 1);
                    return;
                }
                if (waited != 0) {
                    return;
                }
                waited++;
            } else if (r->runningDirectionCode == 3) {
                if (r->nextDirectionBeingProcessed == 2 || r->nextDirectionBeingProcessed == 1) {
                    fn_3_7FEA8(i, 1);
                    return;
                }
                if (input->newButtonInput & 0x800) {
                    fn_3_7FEA8(i, 2);
                }
                return;
            } else if (r->runningDirectionCode == 5 && (buttons & 0x800)) {
                fn_3_7FEA8(i, 1);
                return;
            } else {
                if (input->newButtonInput & 0x800) {
                    fn_3_7FEA8(i, 1);
                }
                return;
            }
        }
    } else if (buttons & 0x400) {
        int base = -1;
        int handled;

        if (input->controlStickAngle < 0xA00 || input->controlStickAngle >= 0xE00) {
            if (input->controlStickAngle >= 0x600) {
                base = 3;
            } else if (input->controlStickAngle >= 0x200) {
                base = 2;
            } else {
                base = 1;
            }
        }
        if (base < 0) {
            return;
        }
        for (handled = i = 0; i < 4; i++) {
            InMemRunnerType* r = &g_Runners[i];
            if (r->runnerOnFieldOrOutOrScored != 1 || r->currentBase != base) {
                continue;
            }
            if (r->runningDirectionCode == 1) {
                if (r->nextDirectionBeingProcessed == 2 || r->nextDirectionBeingProcessed == 3) {
                    fn_3_7FEA8(i, 3);
                    return;
                }
                if (input->newButtonInput & 0x400) {
                    fn_3_7FEA8(i, 2);
                }
                return;
            } else if (r->runningDirectionCode == 3) {
                if (r->nextDirectionBeingProcessed == 2 || r->nextDirectionBeingProcessed == 1) {
                    fn_3_7FEA8(i, 3);
                    return;
                }
            } else if (input->newButtonInput & 0x400) {
                fn_3_7FEA8(i, 3);
                return;
            }
            if (handled >= 2) {
                return;
            }
        }
    }
}

// .text:0x0007DD6C size:0x550 mapped:0x806BCE00
// 97.70%: the target keeps g_Runners in r25 through the loop, walks a copy and reuses it in the
// inlined fn_3_889FC; this build recomputes it there, which shifts the saved registers.
void fn_3_7DD6C(void) {
    int i;

    fn_3_87424();
    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        u8 state;

        if (r->runnerOnFieldOrOutOrScored == 0) {
            continue;
        }
        g_Minigame.runnerNum = i;
        if (r->runningDirectionCode == 0) {
            r->runningDirectionCode = 2;
        }
        r->turningAroundInd = 0;
        state = g_Minigame._1B15[g_Minigame._18FC[i]];
        if (state == 4) {
        } else if (state == 1 || state == 2) {
            fn_3_7D920(i);
        } else if (state == 3) {
            fn_3_7D79C(i);
        } else {
            if (g_GameLogic.gameStatus == 2 && g_Minigame.turnOverStatus == 0) {
                fn_3_7DB30(i);
            }
            fn_3_833EC(i);
        }
    }
    fn_3_87AE8();
    if (g_GameLogic.secondaryGameMode == 6) {
        fn_3_87CC8();
    } else {
        fn_3_88408();
        fn_3_88B18();
        fn_3_889FC();
        fn_3_87E80();
    }
    fn_3_8781C();
}

// .text:0x0007DD24 size:0x48 mapped:0x806BCDB8
void fn_3_7DD24(int player) {
    if (g_GameLogic.gameStatus == 2 && g_Minigame.turnOverStatus == 0) {
        fn_3_7DB30(player);
    }
}

// .text:0x0007DB30 size:0x1F4 mapped:0x806BCBC4
void fn_3_7DB30(int player) {
    InputStruct* input = &g_Controls[g_Minigame._18FC[player]];
    InMemRunnerType* r = &g_Runners[player];

    if (fn_3_107DF8(g_Minigame._18FC[player])) {
        input = &g_Minigame._1D7C[g_Minigame._18FC[player]];
    }
    if (r->runningDirectionCode == 3) {
        if (r->nextDirectionBeingProcessed == 2 || r->nextDirectionBeingProcessed == 1) {
            if (input->newButtonInput & 0x400) {
                fn_3_7FEA8(player, 3);
            } else if (input->newButtonInput & 0x800) {
                fn_3_7FEA8(player, 1);
            }
        } else if (input->newButtonInput & 0x800) {
            fn_3_7FEA8(player, 2);
        }
    } else if (r->runningDirectionCode == 1) {
        if (r->nextDirectionBeingProcessed == 2 || r->nextDirectionBeingProcessed == 3) {
            if (input->newButtonInput & 0x400) {
                fn_3_7FEA8(player, 3);
            } else if (input->newButtonInput & 0x800) {
                fn_3_7FEA8(player, 1);
            }
        } else if (input->newButtonInput & 0x400) {
            fn_3_7FEA8(player, 2);
        }
    } else {
        if (input->buttonInput & 0x800) {
            fn_3_7FEA8(player, 1);
        } else if (input->buttonInput & 0x400) {
            fn_3_7FEA8(player, 3);
        }
    }
    if (input->newButtonInput & 0xF00) {
        r->newButtonThisFrame_forMashPurposes = 1;
    }
}

// .text:0x0007D9DC size:0x154 mapped:0x806BCA70
void fn_3_7D9DC(int player) {
    InMemRunnerType* r = &g_Runners[player];
    f32 len = dolsqrtf2(SQ(g_Minigame._1AEC) + SQ(g_Minigame._1AF4));

    r->velocity.x = lbl_3_data_218BC[7] * (g_Minigame._1AEC / len);
    r->velocity.z = lbl_3_data_218BC[7] * (g_Minigame._1AF4 / len);
    r->runningToDugoutFrameCounter = 0;
}

// .text:0x0007D920 size:0xBC mapped:0x806BC9B4
void fn_3_7D920(int player) {
    InMemRunnerType* r = &g_Runners[player];

    if (g_Minigame._1B15[g_Minigame._18FC[player]] == 2) {
        if (g_Minigame._1B19 == 0) {
            g_Minigame._1B15[g_Minigame._18FC[player]] = 3;
            r->runningToDugoutFrameCounter = 0;
        }
        return;
    }
    if (r->runningToDugoutFrameCounter < lbl_3_data_21904[1]) {
        r->position.x += r->velocity.x;
        r->position.z += r->velocity.z;
    } else {
        g_Minigame._1B15[g_Minigame._18FC[player]] = 2;
    }
    if (r->runningToDugoutFrameCounter < 0x7FFE) {
        r->runningToDugoutFrameCounter++;
    } else {
        r->runningToDugoutFrameCounter = 0x7FFF;
    }
}

// .text:0x0007D79C size:0x184 mapped:0x806BC830
void fn_3_7D79C(int player) {
    InMemRunnerType* r = &g_Runners[player];

    if (r->runningToDugoutFrameCounter <= 0) {
        fn_3_7FED4(&r->position, r->fractionalBasesRan, r->percentTowardsNextBase);
        r->velocity.x = 0.0f;
        r->velocity.z = 0.0f;
    }
    if (r->runningToDugoutFrameCounter < 0x7FFE) {
        r->runningToDugoutFrameCounter++;
    } else {
        r->runningToDugoutFrameCounter = 0x7FFF;
    }
    if (r->runningToDugoutFrameCounter >= lbl_3_data_21904[2]) {
        g_Minigame._1B15[g_Minigame._18FC[player]] = 0;
    }
}
