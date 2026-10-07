#include "game/rep_13B8.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_140.h"
#include "game/rep_1188.h"
#include "game/rep_1838.h"
#include "game/rep_18E8.h"
#include "game/rep_3DA8.h"
#include "game/rep_D0.h"
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
    /* 0x0E */ u8 _0E[0x10 - 0x0E];
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11[0x14 - 0x11];
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
} g_RunningLogic;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

typedef struct {
    /* 0x000 */ u8 _000[0x178];
    /* 0x178 */ s16 _178;
    /* 0x17A */ u8 _17A[0x1E7 - 0x17A];
    /* 0x1E7 */ u8 _1E7;
    /* 0x1E8 */ u8 _1E8[0x268 - 0x1E8];
} Unk13B8Fielder; // size: 0x268

extern Unk13B8Fielder g_Fielders[9];

extern u32 fn_3_107DF8(s8 port);
extern void fn_3_59918(int event, int arg);
extern void fn_3_5C74C(int arg);
extern void fn_3_5D094(int arg);

// rep_AC8.h declares this as a void(void) placeholder
extern int fn_3_52560(int fielder, f32 x, f32 z);

extern s16 lbl_3_data_1C58[5][4];
extern s16 lbl_3_data_1C88[4];
extern VecXZ lbl_3_data_4444[5];
extern VecXZ lbl_3_data_4A34[4];
extern VecXZ lbl_3_data_4A54[2][13];
extern f32 lbl_3_data_4B44;
extern s16 lbl_3_data_4B48[4];
extern VecXYZ lbl_3_data_4B58[4];
extern s16 lbl_3_data_4B90[4];
extern f32 lbl_3_data_4C44[4];
extern u8 lbl_3_data_7760[54][5];
extern s16 lbl_3_data_4C54[12];
extern f32 lbl_3_data_218BC[18];
extern s16 lbl_3_data_21904[12];

// .text:0x0008A958 size:0x73C mapped:0x806C99EC
void fn_3_8A958(void) {
    return;
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
void fn_3_8A618(void) {
    return;
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
void fn_3_899BC(void) {
    return;
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
void fn_3_8913C(void) {
    return;
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
void fn_3_88C24(void) {
    return;
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

// .text:0x00088408 size:0x5F4 mapped:0x806C749C
void fn_3_88408(void) {
    return;
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
    return;
}

// .text:0x00087CC8 size:0x1B8 mapped:0x806C6D5C
void fn_3_87CC8(void) {
    int i;
    f32 angle;

    for (i = 0; i < 4; i++) {
        InMemRunnerType* r = &g_Runners[i];
        if (r->runnerOnFieldOrOutOrScored != 0) {
            angle = atan2(-r->velocity.x, -r->velocity.y);
            if (g_Minigame._1B15[g_Minigame._18FC[i]] == 1) {
                angle = fn_3_9FEA8(PI + atan2(-r->velocity.x, -r->velocity.z));
            } else if (r->runningDirectionCode != 0 && r->runningDirectionCode != 2) {
                if (0.0f == r->velocity.x && 0.0f == r->velocity.z) {
                    angle = atan2(-r->velocityStored.x, -r->velocityStored.z);
                    if (r->turningAroundInd == 1 && r->runningDirectionCode == 1 && r->acceleration > 0.0f) {
                        angle = fn_3_9FEA8(PI + angle);
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
        u32 caughtZone = g_Ball.ballZoneWhenCaught;
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
void fn_3_87424(void) {
    return;
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
    return;
}

// .text:0x00086118 size:0x684 mapped:0x806C51AC
void fn_3_86118(void) {
    return;
}

// .text:0x0008604C size:0xCC mapped:0x806C50E0
int fn_3_8604C(int* fielderOut) {
    int i;
    int best = 9999;

    for (i = 0; i < 9; i++) {
        u8 state = g_FieldingLogic._0F0[i + 8];
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
void fn_3_85840(void) {
    return;
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

// .text:0x00085074 size:0x6D0 mapped:0x806C4108
void fn_3_85074(void) {
    return;
}

// .text:0x00084AD0 size:0x5A4 mapped:0x806C3B64
void fn_3_84AD0(void) {
    return;
}

// .text:0x000846C8 size:0x408 mapped:0x806C375C
void fn_3_846C8(void) {
    return;
}

// .text:0x000842E4 size:0x3E4 mapped:0x806C3378
void fn_3_842E4(void) {
    return;
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
    return;
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
void fn_3_833EC(void) {
    return;
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
void fn_3_82670(void) {
    return;
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
void fn_3_81EAC(void) {
    return;
}

// .text:0x00081BC8 size:0x2E4 mapped:0x806C0C5C
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
void fn_3_81190(void) {
    return;
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
void fn_3_80028(void) {
    return;
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
void fn_3_7F9C4(void) {
    return;
}

// .text:0x0007F494 size:0x530 mapped:0x806BE528
void fn_3_7F494(void) {
    return;
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
void fn_3_7ECFC(void) {
    return;
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
void fn_3_7E2BC(void) {
    return;
}

// .text:0x0007DD6C size:0x550 mapped:0x806BCE00
void fn_3_7DD6C(void) {
    return;
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
