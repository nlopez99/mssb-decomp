#include "game/rep_540.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/rand.h"
#include "game/rep_CC8.h"
#include "game/rep_D0.h"
#include "game/rep_13B8.h"
#include "game/rep_1838.h"
#include "game/rep_1CB8.h"
#include "game/rep_3AE8.h"
#include "game/rep_3C80.h"
#include "game/rep_3DA8.h"
#include "game/rep_4090.h"
#include "game/sta_c6.h"
#include "game/rep_AC8.h"
#include "game/m_sound.h"

extern struct {
    /* 0x00 */ s16 _00;
    /* 0x02 */ u8 _02[0x13 - 0x2];
    /* 0x13 */ u8 _13;
} g_RunningLogic;

extern f32 lbl_3_data_450C[18];

extern struct {
    /* 0x00 */ u32 _00;
} lbl_3_data_228;

typedef struct {
    /* 0x000 */ VecXYZ pos;
    /* 0x00C */ u8 _00C[0x74 - 0xC];
    /* 0x074 */ f32 _074;
    /* 0x078 */ u8 _078[0xF4 - 0x78];
    /* 0x0F4 */ f32 _0F4;
    /* 0x0F8 */ u8 _0F8[0x17A - 0xF8];
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x1C7 - 0x17C];
    /* 0x1C7 */ u8 _1C7;
    /* 0x1C8 */ u8 _1C8;
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA[0x1E1 - 0x1CA];
    /* 0x1E1 */ u8 _1E1;
    /* 0x1E2 */ u8 _1E2[0x268 - 0x1E2];
} Rep540Fielder; // size: 0x268

extern Rep540Fielder g_Fielders[9];
extern u8 lbl_800E8558[54][6];

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
} Rep540Friction; // size: 0x14

extern Rep540Friction lbl_3_data_4388[7];
extern Rep540Friction lbl_3_data_4414;
extern f32 lbl_3_data_4428[7];
extern VecXZ lbl_3_data_4444[5];
extern f32 lbl_3_data_45F4[2];
extern f32 lbl_3_data_45FC;
extern u8 lbl_3_data_4600;
extern f32 lbl_3_data_4604;
extern f32 lbl_3_data_47BC[5];
extern f32 lbl_3_data_4930[43];
extern f32 lbl_3_data_5CDC[11];
extern f32 lbl_3_data_21438;
extern u8 lbl_3_data_4608;
extern f32 lbl_3_data_610C[6];
extern f32 lbl_3_data_6124[3];

extern struct {
    /* 0x00 */ u8 _00[0xCA];
    /* 0xCA */ u8 _CA;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x00 */ u8 _00[0x6B];
    /* 0x6B */ u8 _6B;
} lbl_3_common_bss_350E4;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

void fn_3_B7F18(Vec* out, Vec* a, Vec* b);
void fn_80064344(Vec* pos, Vec* vel);

// .text:0x0001014C size:0x17C mapped:0x8064F1E0
void ballPhysica(void) {
    if (g_Ball.matchFramesAndBallAngle.ballOverWallFrames != 0) {
        if (g_Ball.matchFramesAndBallAngle.ballOverWallFrames < 0x7FFE) {
            g_Ball.matchFramesAndBallAngle.ballOverWallFrames++;
        } else {
            g_Ball.matchFramesAndBallAngle.ballOverWallFrames = 0x7FFF;
        }
    }
    if (g_FieldingLogic._107 != 0) {
        if (g_Ball.framesSincePickOff < 0x7FFE) {
            g_Ball.framesSincePickOff++;
        } else {
            g_Ball.framesSincePickOff = 0x7FFF;
        }
    }
    if (g_Ball.AtBat_ContactResult == -1) {
        if (g_Ball.matchFramesAndBallAngle.framesSinceFoulCalled < 0x7FFE) {
            g_Ball.matchFramesAndBallAngle.framesSinceFoulCalled++;
        } else {
            g_Ball.matchFramesAndBallAngle.framesSinceFoulCalled = 0x7FFF;
        }
    }
    if (g_Ball.framesSinceBallHitWall != 0) {
        if (g_Ball.framesSinceBallHitWall < 0x7FFE) {
            g_Ball.framesSinceBallHitWall++;
        } else {
            g_Ball.framesSinceBallHitWall = 0x7FFF;
        }
    }
    if (g_Ball.pauseBallMovementWhenInPlant == 0 && g_Ball.frameCountdownAfterLeavingPlant != 0) {
        g_Ball.frameCountdownAfterLeavingPlant--;
    }
    if ((g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD || g_Minigame.TF_ballDespawnedInd == 0) &&
        g_Ball.groundRuleDoubleInd == 0) {
        if (g_Ball.ballState == 1) {
            fn_3_C9F4();
        } else if (g_Ball.framesSinceHit >= 0) {
            fn_3_A970(0);
        }
    }
    fn_3_E2D4();
}

// .text:0x00010030 size:0x11C mapped:0x8064F0C4
// 99.7%: each seed sum adds the random product from r29 and the shifted rand() in the
// other order (the same difference as its inlined copy in fn_3_FBA8).
void fn_3_10030(void) {
    s32 r;

    r = (lbl_3_data_228._00 % 10 + 1) * (g_Ball.StaticRandomInt1 * rand());
    g_Ball.StaticRandomInt1 = (r + rand() * 16 + lbl_3_data_228._00 / 2 + g_d_GameSettings.FrameCountWhileNotAtMainMenu) & 0x7FFF;
    r = (lbl_3_data_228._00 % 10 + 1) * ((g_Ball.StaticRandomInt2 + 1) * rand());
    g_Ball.StaticRandomInt2 = (r + rand() * 8 + lbl_3_data_228._00 / 2 + (g_d_GameSettings.FrameCountWhileNotAtMainMenu >> 1)) & 0x7FFF;
}

// .text:0x0000FF98 size:0x98 mapped:0x8064F02C
void fn_3_FF98(void) {
    u32 seed = lbl_3_data_228._00;
    s32 r;

    r = g_Ball.StaticRandomInt2 * 16 + (seed % 10 + 1) * (g_Ball.StaticRandomInt2 * g_Ball.StaticRandomInt1) + seed / 2 +
        g_d_GameSettings.FrameCountWhileNotAtMainMenu;
    g_Ball.StaticRandomInt1 = r & 0x7FFF;
    g_Ball.StaticRandomInt1_prePitch = g_Ball.StaticRandomInt1;
    r = g_Ball.StaticRandomInt1 * 8 + (seed % 10 + 1) * (g_Ball.StaticRandomInt2 * (g_Ball.StaticRandomInt2 + 1)) + seed / 2 +
        (g_d_GameSettings.FrameCountWhileNotAtMainMenu >> 1);
    g_Ball.StaticRandomInt2 = r & 0x7FFF;
}

// .text:0x0000FF4C size:0x4C mapped:0x8064EFE0
// 91.8%: same operations; the target computes both masks and shifts before the * 8 terms.
void fn_3_FF4C(void) {
    g_Ball.StaticRandomInt1 = (g_Ball.StaticRandomInt1 * 8 + ((g_Ball.StaticRandomInt1 >> 1) + (g_Ball.StaticRandomInt1 & 0x505))) & 0x7FFF;
    g_Ball.StaticRandomInt2 = (g_Ball.StaticRandomInt2 * 8 + ((g_Ball.StaticRandomInt2 >> 2) + (g_Ball.StaticRandomInt2 & 0x505))) & 0x7FFF;
}

// .text:0x0000FBA8 size:0x3A4 mapped:0x8064EC3C
// 99.9%: each seed sum adds the random product from r29 and the shifted rand() from r6
// in the other order.
void fn_3_FBA8(void) {
    s32 i;

    g_Ball.AtBat_Contact_BallPos.x = lbl_3_data_450C[0];
    g_Ball.AtBat_Contact_BallPos.y = 0.0f;
    g_Ball.AtBat_Contact_BallPos.z = lbl_3_data_450C[1];
    if (g_Minigame.GameMode_MiniGame == 6) {
        g_Ball.AtBat_Contact_BallPos.x = 0.0f;
        g_Ball.AtBat_Contact_BallPos.z = 0.0f;
        g_Ball.AtBat_Contact_BallPos.y = 1.0f;
    }
    for (i = 0; i < 60; i++) {
        g_Ball.pastCoordinates[i].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.pastCoordinates[i].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.pastCoordinates[i].z = g_Ball.AtBat_Contact_BallPos.z;
    }
    g_Ball.physicsSubstruct.acceleration.x = 0.0f;
    g_Ball.physicsSubstruct.acceleration.y = 0.0f;
    g_Ball.physicsSubstruct.acceleration.z = 0.0f;
    g_Ball.physicsSubstruct.velocity.x = 0.0f;
    g_Ball.physicsSubstruct.velocity.y = 0.0f;
    g_Ball.physicsSubstruct.velocity.z = 0.0f;
    g_Ball.physicsSubstruct.acceleration.x = 0.0f;
    g_Ball.physicsSubstruct.acceleration.y = 0.0f;
    g_Ball.physicsSubstruct.acceleration.z = 0.0f;
    g_Ball.offsetWhilePickedUpHistory[0].x = 0.0f;
    g_Ball.offsetWhilePickedUpHistory[0].y = 0.0f;
    g_Ball.offsetWhilePickedUpHistory[0].z = 0.0f;
    g_Ball.physicsSubstruct.gravity = lbl_3_data_45FC;
    g_Ball.airResistance = lbl_3_data_4600;
    g_Ball.fielderWBallIndex = -1;
    g_Ball.ballState = 0;
    g_Ball.AtBat_ContactResult = 0;
    g_Ball.ballInitialHitDoneInd = 0;
    g_Ball.fairBallInd = -1;
    g_Ball.ballStoppingCode1ReallySlow2Stopped = 0;
    g_Ball.framesSinceHit = -1;
    g_Ball.timeSinceBallPickedUp = -1;
    g_Ball.matchFramesAndBallAngle.framesSinceLastThrow = -1;
    g_Ball.framesSinceBallHitGroundOrWasCaught = -1;
    g_Ball.Hit_HorizontalPower = 110;
    g_Ball.Hit_VerticalAngle = 397;
    g_Ball.Hit_HorizontalAngle = 626;
    g_FieldingLogic._0C4 = -1;
    g_FieldingLogic._0C6 = -1;
    g_Strikes.outs = 0;
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        g_Ball.groundYForBounces = lbl_3_data_45F4[1];
    } else {
        g_Ball.groundYForBounces = lbl_3_data_45F4[0];
    }
    fn_3_10030();
}

// .text:0x0000F9F8 size:0x1B0 mapped:0x8064EA8C
void fn_3_F9F8(void) {
    s32 i;

    g_Ball.AtBat_Contact_BallPos.x = lbl_3_data_450C[0];
    g_Ball.AtBat_Contact_BallPos.y = 0.0f;
    g_Ball.AtBat_Contact_BallPos.z = lbl_3_data_450C[1];
    if (g_Minigame.GameMode_MiniGame == 6) {
        g_Ball.AtBat_Contact_BallPos.x = 0.0f;
        g_Ball.AtBat_Contact_BallPos.z = 0.0f;
        g_Ball.AtBat_Contact_BallPos.y = 1.0f;
    }
    for (i = 0; i < 60; i++) {
        g_Ball.pastCoordinates[i].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.pastCoordinates[i].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.pastCoordinates[i].z = g_Ball.AtBat_Contact_BallPos.z;
    }
    g_Ball.physicsSubstruct.velocity.x = 0.0f;
    g_Ball.physicsSubstruct.acceleration.x = 0.0f;
    g_Ball.physicsSubstruct.velocity.y = 0.0f;
    g_Ball.physicsSubstruct.acceleration.y = 0.0f;
    g_Ball.physicsSubstruct.velocity.z = 0.0f;
    g_Ball.physicsSubstruct.acceleration.z = 0.0f;
}

// .text:0x0000F7B8 size:0x240 mapped:0x8064E84C
void fn_3_F7B8(void) {
    fn_3_F9F8();
    fn_3_FF98();
    g_Ball.fielderWBallIndex = -1;
}

// .text:0x0000F578 size:0x240 mapped:0x8064E60C
void fn_3_F578(void) {
    fn_3_F9F8();
    fn_3_FF98();
    g_Ball.deadBallReason = 0;
}

// .text:0x0000F1DC size:0x39C mapped:0x8064E270
void fn_3_F1DC(void) {
    u32 seed;

    fn_3_F9F8();
    seed = lbl_3_data_228._00;
    g_Ball.StaticRandomInt1 = (g_Ball.StaticRandomInt2 * 16 + (seed % 10 + 1) * (g_Ball.StaticRandomInt2 * g_Ball.StaticRandomInt1) + seed / 2 + g_d_GameSettings.FrameCountWhileNotAtMainMenu) & 0x7FFF;
    g_Ball.StaticRandomInt2 = (g_Ball.StaticRandomInt1 * 8 + (seed % 10 + 1) * (g_Ball.StaticRandomInt2 * (g_Ball.StaticRandomInt2 + 1)) + seed / 2 + (g_d_GameSettings.FrameCountWhileNotAtMainMenu >> 1)) & 0x7FFF;
    g_Ball.StaticRandomInt1_prePitch = g_Ball.StaticRandomInt1;
    g_Ball.framesSinceHit = -1;
    g_Ball.physicsSubstruct.gravity = lbl_3_data_45FC;
    g_Ball.framesSinceThrowStarted = -1;
    g_Ball.pitchHangtimeCounter = -1;
    g_Ball.postPitchResultCounter = -1;
    g_Ball.framesSinceBallHitGroundOrWasCaught = -1;
    g_Ball.framesSinceLastBounce = -1;
    g_Ball.framesSincePickOff = -1;
    g_Ball.ballHitGrroundDistanceFromHome = 0.0f;
    g_Ball.AtBat_ContactResult = 0;
    g_Ball.ballInitialHitDoneInd = 0;
    g_Ball.fairBallInd = -1;
    g_Ball.howFoulTheBallWillBe = 0;
    g_Ball.always0_fairFoulRelated = 0;
    g_Ball.ballState = 0;
    g_Ball.fielderAboutToGetBall_hasBall = -1;
    g_Ball.fielderWBallIndex = -1;
    g_Ball.maxYOfHit = 0.0f;
    g_Ball.deadBallReason = 0;
    g_Ball.someCollisionVariable = 0;
    g_Ball.deadBallRBIsAddedInd = 0;
    g_Ball.baseBallAndFielderAreOn = -1;
    g_Ball.fielderBeingThrownTo = -1;
    g_Ball.ballIsLooseInd_unused = 0;
    g_Ball.homeRunClassification = 0;
    g_Ball.lineDriveThroughPitcherInd = 0;
    g_Ball.hitWallInd = 0;
    g_Ball.fielderWithBallIndexStored = -1;
    g_Ball.fielderWithBallIndexStored2 = -1;
    g_Ball.fielderWhoGotLastOut = -1;
    g_Ball.throwingFielder = -1;
    g_Ball.maybeBuntInd = 0;
    g_Ball.maybebuntOn2Strikes = 0;
    g_Ball.timeSinceBallPickedUp = -1;
    g_Ball.matchFramesAndBallAngle.framesSinceLastThrow = -1;
    g_Ball.groundRuleDoubleInd = 0;
    g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow = 0;
    g_Ball.numberOfThrowsDuringPlay = 0;
    g_Ball.framesOnGroundUntilPickedUp = 0;
    g_Ball.numFieldersWhoHandledBallDuringPlay = 0;
    g_Ball.numThrowsDuringPlay = 0;
    g_Ball.bobbleLocation_1fair_2foul = 0;
    g_Ball.matchFramesAndBallAngle.ballAndFielderOnBaseFrames = 0;
    g_Ball.homeRunInd = 0;
    g_Ball.matchFramesAndBallAngle.ballOverWallFrames = 0;
    g_Ball.ballZoneWhenCaught = -1;
    g_Ball._1BDF = 0;
    g_Ball.matchFramesAndBallAngle.framesSinceFoulCalled = 0;
    g_Ball.collisionRelated = 0;
    g_Ball.landingSpotZoneAwayFromHome = 0;
    g_Ball.ballZoneAwayFromHome = 0;
    g_Ball.looseBall_codeForHowLongUntilSomeoneWillGetIt = 0;
    g_Ball.someYCoord = -1.0f;
    g_Ball.looseBall_5FrameCountdown = 0;
    g_Ball.ballIsRollingIndicator = 0;
    g_Ball.ballPickedUpCaught.x = 0.0f;
    g_Ball.ballPickedUpCaught.z = 0.0f;
    g_Ball.matchFramesAndBallAngle.framesOnGround = 0;
    g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy = 0;
    g_Ball.hardHitIndicator = 0;
    g_Ball.ballEnergy = 0.0f;
    g_Ball.framesSinceBallHitWall = 0;
    g_Ball.hittingAddedGravityFactor = 0.0f;
    g_Ball.currentStarSwing = 0;
    g_Ball.currentStarSwing2 = 0;
    g_Ball.knockoutProcessedFlag = 0;
    g_Ball.bODQualifyingHitInd = 0;
    g_Ball.IsAntichemistryThrow = 0;
    g_Ball.warioWaluGarlicIsActive = 0;
    g_Ball.matchFramesAndBallAngle.garlicHitFramesSinceSplit = 0;
    g_Ball.autoFielderAvoidDropSpotForPeachesStarHit = 0;
    g_Ball.fielderActionOccuring = 0;
    g_Ball.catchAnimationTotalFrames = 0;
    g_Ball._1BC0 = 1;
    g_Ball.someCollisionInd = 0;
    g_Ball.hitNoteBlockInd = 0;
    g_Ball.pauseBallMovementWhenInPlant = 0;
    g_Ball.ballCughtByPlantInd = 0;
}

// .text:0x0000EE4C size:0x390 mapped:0x8064DEE0
void fn_3_EE4C(void) {
    f32 x;
    f32 z;
    f32 radius;
    s32 i;
    int j;
    s16 angle;

    g_Ball.offsetWhilePickedUpHistory[0].x = 0.0f;
    g_Ball.offsetWhilePickedUpHistory[0].y = 0.0f;
    g_Ball.offsetWhilePickedUpHistory[0].z = 0.0f;
    g_Ball.framesSinceHit = 0;
    g_Ball.framesSinceThrowStarted = -1;
    g_Ball.framesSinceBallHitGroundOrWasCaught = -1;
    g_Ball.framesSinceLastBounce = -1;
    g_Ball.ballHitGrroundDistanceFromHome = 0.0f;
    g_Ball.AtBat_ContactResult = 0;
    g_Ball.ballInitialHitDoneInd = 0;
    g_Ball.fairBallInd = -1;
    g_Ball.howFoulTheBallWillBe = 0;
    g_Ball.ballState = 0;
    g_Ball.fielderAboutToGetBall_hasBall = -1;
    g_Ball.fielderWBallIndex = -1;
    g_Ball.maxYOfHit = 0.0f;
    g_Ball.deadBallReason = 0;
    g_Ball.someCollisionVariable = 0;
    g_Ball.deadBallRBIsAddedInd = 0;
    g_Ball.baseBallAndFielderAreOn = -1;
    g_Ball.fielderBeingThrownTo = -1;
    g_Ball.ballIsLooseInd_unused = 0;
    g_Ball.homeRunClassification = 0;
    g_Ball.lineDriveThroughPitcherInd = 0;
    g_Ball.hitWallInd = 0;
    g_Ball.collisionRelated = 0;
    g_Ball.timeSinceBallPickedUp = -1;
    g_Ball.matchFramesAndBallAngle.framesSinceLastThrow = -1;
    g_Ball.groundRuleDoubleInd = 0;
    g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow = 0;
    g_Ball.numberOfThrowsDuringPlay = 0;
    g_Ball.ballZoneWhenCaught = -1;
    if (g_Ball.currentStarSwing == 3 || g_Ball.currentStarSwing == 4) {
        g_Ball.warioStarHitCoords[0].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.warioStarHitCoords[0].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.warioStarHitCoords[0].z = g_Ball.AtBat_Contact_BallPos.z;
        g_Ball.warioStarHitCoords[1].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.warioStarHitCoords[1].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.warioStarHitCoords[1].z = g_Ball.AtBat_Contact_BallPos.z;
        g_Ball.warioStarHitCoords[2].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.warioStarHitCoords[2].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.warioStarHitCoords[2].z = g_Ball.AtBat_Contact_BallPos.z;
        for (i = 0; i < 10; i++) {
            g_Ball.warioStarHitCoords[i + 3].x = g_Ball.AtBat_Contact_BallPos.x;
            g_Ball.warioStarHitCoords[i + 3].y = g_Ball.AtBat_Contact_BallPos.y;
            g_Ball.warioStarHitCoords[i + 3].z = g_Ball.AtBat_Contact_BallPos.z;
        }
    }
    if (g_Minigame.GameMode_MiniGame == 1) {
        g_Batter.hitTrajectory = 3;
        if (g_Batter.buntStatus) {
            g_Batter.hitTrajectory = 6;
        }
        if (g_Ball.bODQualifyingHitInd) {
            for (j = 0; j < 360; j += 5) {
                if (g_Ball.physicsSubstruct.futureCoordsAndDist[j].dist > 80.0f) {
                    angle = fn_3_9FB8C(g_Ball.physicsSubstruct.futureCoordsAndDist[j].pos.x,
                                       g_Ball.physicsSubstruct.futureCoordsAndDist[j].pos.z);
                    if (angle > 576 && angle < 1472) {
                        g_Batter.hitTrajectory = 4;
                    }
                    break;
                }
            }
        }
    } else {
        if (g_Minigame.GameMode_MiniGame == 3) {
            g_Batter.hitTrajectory = 3;
            if (g_Batter.buntStatus) {
                g_Batter.hitTrajectory = 6;
            }
        }
        estimateAndSetFutureCoords(0);
        fn_3_C034();
        if (g_Ball.autoFielderAvoidDropSpotForPeachesStarHit) {
            if (g_Ball.currentStarSwing == 11) {
                radius = RandomF32_Game_Range(lbl_3_data_4930[39], lbl_3_data_4930[40]);
            } else {
                radius = RandomF32_Game_Range(lbl_3_data_4930[41], lbl_3_data_4930[42]);
            }
            getComponentsFromSAng(RandomInt_Game(0x1000), &x, &z);
            g_Ball.peachDaisyStarHitFielderLoc.x = x * radius + g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
            g_Ball.peachDaisyStarHitFielderLoc.z = z * radius + g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z;
        }
    }
}

static inline s32 findClosestFutureFrame(s32 count, s32 step, f32 x, f32 z) {
    f32 best = 100000000.0f;
    s32 i;
    s32 bestIdx = -1;
    f32 dx;
    f32 dz;
    f32 dist;

    for (i = 0; i < count; i += step) {
        dx = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x - x;
        dz = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z - z;
        dist = dx * dx + dz * dz;
        if (!(dist < best)) {
            break;
        }
        best = dist;
        bestIdx = i;
    }
    if (bestIdx < 0) {
        return -1;
    }
    return bestIdx;
}

// .text:0x0000E2D4 size:0xB78 mapped:0x8064D368
void fn_3_E2D4(void) {
    s32 frame;
    s32 i;

    g_Ball.ballAngleFromHome = fn_3_9FB8C(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z);
    fn_3_D9EC();
    g_Ball.ballTravelAngle = fn_3_9FB8C(g_Ball.physicsSubstruct.velocity.x, g_Ball.physicsSubstruct.velocity.z);
    g_Ball.ballZoneAwayFromHome = fn_3_51DF0(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z);
    if (g_Ball.AtBat_ContactResult == 0 && g_Ball.framesSinceHit < 10) {
        g_Ball.landingSpotZoneAwayFromHome = fn_3_51DF0(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                                                        g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
    }
    for (i = 1; i < 4; i++) {
        g_Ball.ballDistanceFromBase[i] = VEC_DISTANCE_XZ(&lbl_3_data_4444[i], &g_Ball.AtBat_Contact_BallPos);
    }
    g_Ball.ballDistanceFromBase[0] = g_Ball.ballDistanceFromHome;
    g_Ball.distLandingSpotToMound = VEC_DISTANCE_XZ(&lbl_3_data_4444[4], &g_Ball.AtBat_Contact_BallPos);
    if (g_Ball.AtBat_ContactResult == 0) {
        fn_3_9B74();
    }
    if (g_Ball.ballState != 1) {
        g_Ball.fielderWBallIndex = -1;
        g_Ball._1B88 = -1;
        g_Ball.baseBallAndFielderAreOn = -1;
    }
    if (g_Ball.fielderAboutToGetBall_hasBall >= 0) {
        g_Ball.ballIsLooseInd_unused = 0;
    }
    if (g_Ball.AtBat_ContactResult == 0 && g_FieldingLogic._108 == 0 && g_Ball.currentStarSwing2 == 0 &&
        g_Ball.maybeBuntInd == 0 && g_Ball.hangtimeOfHit >= 120 && g_Ball.maxYOfHit > 10.0f &&
        g_Strikes.storedOuts < 2 && g_Ball.howFoulTheBallWillBe < 3 && g_Ball.framesSinceHit == 60 &&
        g_Ball.numFieldersWhoHandledBallDuringPlay == 0) {
        if (VEC_DISTANCE_XZ(&lbl_3_data_4444[4], &g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot) < 30.0f &&
            (!(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z < g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x - 5.0f ||
               g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z < -g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x - 5.0f) ||
             (g_Ball.Hit_HorizontalAngle >= 544 && g_Ball.Hit_HorizontalAngle <= 1504)) &&
            (g_RunningLogic._00 & 0x110) == 0x110) {
            g_FieldingLogic._108 = 1;
        }
    }
    if (g_FieldingLogic._108 != 0 && g_Ball.framesSinceHit == 60) {
        fn_3_59918(6, 0);
    }
    fn_3_DC48(FALSE);
    if (g_Ball.collisionRelated >= 2) {
        g_Ball.groundRuleDoubleInd = 1;
    }
    if (g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow != 0) {
        if (g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow < 0x7FFE) {
            g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow++;
        } else {
            g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow = 0x7FFF;
        }
        if (g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow >= 120 || g_Ball.AtBat_ContactResult == 2 ||
            g_Ball.AtBat_ContactResult == 3) {
            g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow = 0;
        }
    }
    g_Ball.throwHasLastedEstimatedNOfFrames = 0;
    if (g_Ball.ballOnMoundInd && g_Ball.ballState == 2) {
        frame = findClosestFutureFrame(300, 2, g_Ball.throwTarget.x, g_Ball.throwTarget.z);
        if (frame == -1) {
            g_Ball.throwHasLastedEstimatedNOfFrames = 1;
        } else {
            g_Ball.framesUntilThrowReachesDest = frame;
        }
    }
    if (g_Ball.baseBallAndFielderAreOn >= 0) {
        if (g_Ball.matchFramesAndBallAngle.ballAndFielderOnBaseFrames < 0x7FFE) {
            g_Ball.matchFramesAndBallAngle.ballAndFielderOnBaseFrames++;
        } else {
            g_Ball.matchFramesAndBallAngle.ballAndFielderOnBaseFrames = 0x7FFF;
        }
    } else {
        g_Ball.matchFramesAndBallAngle.ballAndFielderOnBaseFrames = 0;
    }
    fn_3_B940();
    if (g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy) {
        g_Ball.ballEnergy *= lbl_3_data_5CDC[1];
        if (g_Ball.framesSinceLastBounce == 1) {
            g_Ball.ballEnergy *= lbl_3_data_5CDC[2];
        }
        if (g_Ball.ballEnergy < lbl_3_data_5CDC[0]) {
            g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy = 0;
            g_Ball.ballEnergy = 0.0f;
        }
    }
}

// .text:0x0000DC48 size:0x68C mapped:0x8064CCDC
void fn_3_DC48(BOOL fromPitcher) {
    VecSrcDst ray;
    CollisionStruct hit;
    f32 len;
    s32 type;
    int i;
    int j;
    int k;

    if (fromPitcher) {
        ray.src.x = g_Pitcher._30.x;
        ray.src.y = -0.5f;
        ray.src.z = g_Pitcher._30.z;
        if (g_Ball.physicsSubstruct.futureCoordsAndDist[60].dist == 0.0f) {
            ray.dst.x = 200.0f * g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.x;
            ray.dst.y = -0.5f;
            ray.dst.z = 200.0f * g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.z;
        } else {
            ray.dst.x = 200.0f * (g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.x /
                                  g_Ball.physicsSubstruct.futureCoordsAndDist[60].dist);
            ray.dst.y = -0.5f;
            ray.dst.z = 200.0f * (g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.z /
                                  g_Ball.physicsSubstruct.futureCoordsAndDist[60].dist);
        }
    } else {
        ray.src.x = g_Ball.AtBat_Contact_BallPos.x;
        ray.src.y = -0.5f;
        ray.src.z = g_Ball.AtBat_Contact_BallPos.z;
        ray.dst.x = 200.0f * g_Ball.ballVelocityPercent.x + g_Ball.AtBat_Contact_BallPos.x;
        ray.dst.y = -0.5f;
        ray.dst.z = 200.0f * g_Ball.ballVelocityPercent.z + g_Ball.AtBat_Contact_BallPos.z;
    }
    if (ray.src.x == ray.dst.x && ray.src.z == ray.dst.z) {
        ray.dst.z = 10.0f + ray.src.z;
    }
    type = checkCollision(&ray, &hit, 0, 0) & 0x7F;
    g_Ball.someCollisionVariable = 0;
    if (type == BALL_COLLISION_TYPE_WALL || type == BALL_COLLISION_TYPE_UNCLIMBABLE_WALL) {
        g_Ball.ballWillHitBallPos.x = hit.position.x;
        g_Ball.ballWillHitBallPos.z = hit.position.z;
        g_Ball.wallAndBallIntersectionDistFromHome = VEC_LENGTH_XZ(&g_Ball.ballWillHitBallPos);
        len = VEC_LENGTH_XZ(&hit.normal) == 0.0f ? 1.0f : VEC_LENGTH_XZ(&hit.normal);
        g_Ball._1BC0 = 1;
        g_Ball._19E4 = hit.normal.x / len;
        g_Ball._19E8 = hit.normal.z / len;
        g_Ball.physicsSubstruct.throwYAtSelectedFuturePoint = 0.0f;
        g_Ball.frameBallWillHitWall = -1;
        for (i = 0; i < 360; i += 10) {
            if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].dist > g_Ball.wallAndBallIntersectionDistFromHome) {
                for (j = i - 9, k = 0; k < 10; j++, k++) {
                    if (g_Ball.physicsSubstruct.futureCoordsAndDist[j].dist > g_Ball.wallAndBallIntersectionDistFromHome) {
                        i = 360;
                        g_Ball.physicsSubstruct.throwYAtSelectedFuturePoint = g_Ball.physicsSubstruct.futureCoordsAndDist[j].pos.y;
                        g_Ball.frameBallWillHitWall = j;
                        break;
                    }
                }
            }
        }
        if (g_Ball.Hit_HorizontalAngle >= 0x200 && g_Ball.Hit_HorizontalAngle <= 0x600 && g_Ball.someCollisionInd == 0) {
            if (((20.0f + g_Ball.wallAndBallIntersectionDistFromHome < g_Ball.physicsSubstruct.hitLandingSpotDistFromHome &&
                  g_Ball.Hit_VerticalAngle > 300) ||
                 g_Ball.physicsSubstruct.hitLandingSpotDistFromHome >= 140.0f) &&
                g_Ball.physicsSubstruct.throwYAtSelectedFuturePoint >= 8.0f &&
                (g_Ball.ballWillHitBallPos.x < 0.0f ? -g_Ball.ballWillHitBallPos.x : g_Ball.ballWillHitBallPos.x) < g_Ball.ballWillHitBallPos.z) {
                g_Ball.someCollisionVariable = 3;
            } else if (20.0f + g_Ball.wallAndBallIntersectionDistFromHome < g_Ball.physicsSubstruct.hitLandingSpotDistFromHome) {
                g_Ball.someCollisionVariable = 2;
            } else if (10.0f + g_Ball.wallAndBallIntersectionDistFromHome < g_Ball.physicsSubstruct.hitLandingSpotDistFromHome &&
                       g_Ball.Hit_VerticalAngle > 300) {
                g_Ball.someCollisionVariable = 2;
            } else if (1.0f + g_Ball.wallAndBallIntersectionDistFromHome < g_Ball.physicsSubstruct.hitLandingSpotDistFromHome) {
                g_Ball.someCollisionVariable = 1;
            }
        }
    } else {
        g_Ball.wallAndBallIntersectionDistFromHome = 999.9f;
        g_Ball.physicsSubstruct.throwYAtSelectedFuturePoint = 0.0f;
        g_Ball.frameBallWillHitWall = -1;
    }
}

// .text:0x0000DBD0 size:0x78 mapped:0x8064CC64
void fn_3_DBD0(void) {
    f32 scale = 1.0f - g_Ball.airResistance / 10000.0f;
    g_Ball.physicsSubstruct.velocity.x *= scale;
    g_Ball.physicsSubstruct.velocity.y *= scale;
    g_Ball.physicsSubstruct.velocity.z *= scale;
}

// .text:0x0000D9EC size:0x1E4 mapped:0x8064CA80
void fn_3_D9EC(void) {
    g_Ball.ballVelocity = VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.velocity);
    g_Ball.ballStoppingCode1ReallySlow2Stopped = 0;
    if (g_Ball.ballVelocity != 0.0f) {
        g_Ball.ballVelocityPercent.x = g_Ball.physicsSubstruct.velocity.x / g_Ball.ballVelocity;
        g_Ball.ballVelocityPercent.z = g_Ball.physicsSubstruct.velocity.z / g_Ball.ballVelocity;
    }
    if (g_Ball.ballVelocity <= 0.1f && g_Ball.AtBat_Contact_BallPos.y <= 0.08f &&
        g_Ball.physicsSubstruct.velocity.y < 0.01f && g_Ball.physicsSubstruct.velocity.y > -0.01f) {
        if (g_Ball.ballVelocity < 0.005f) {
            g_Ball.ballStoppingCode1ReallySlow2Stopped = 2;
            g_Ball.physicsSubstruct.velocity.x = 0.0f;
            g_Ball.physicsSubstruct.velocity.z = 0.0f;
            g_Ball.ballVelocity = 0.0f;
        } else {
            g_Ball.ballStoppingCode1ReallySlow2Stopped = 1;
        }
    }
}

// .text:0x0000CE28 size:0xBC4 mapped:0x8064BEBC
// 99.8%: the bounce interpolation computes x - prevX, z - prevZ and t in other FPRs, and the
// bounce friction blocks swap r0/r3 for the game mode and the collision code.
void estimateAndSetFutureCoords(int mode) {
    f32 x;
    f32 y;
    f32 z;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 ax;
    f32 ay;
    f32 az;
    f32 prevY;
    f32 prevX;
    f32 prevZ;
    f32 scale;
    f32 t;
    f32 remain;
    int frame = 1;
    int bounces = 0;
    BOOL apexFound = FALSE;
    BOOL landed = FALSE;
    u8 stopped = FALSE;
    u8 secondPass = FALSE;
    s32 code;

restart:
    if (mode == 1) {
        bounces = g_Ball.framesOnGroundUntilPickedUp;
    }
    if (mode == 2) {
        x = g_Pitcher._30.x;
        y = g_Pitcher._30.y;
        z = g_Pitcher._30.z;
    } else if (g_Ball.warioWaluGarlicIsActive) {
        if (secondPass) {
            x = g_Ball.warioStarHitCoords[2].x;
            y = g_Ball.warioStarHitCoords[2].y;
            z = g_Ball.warioStarHitCoords[2].z;
        } else {
            x = g_Ball.warioStarHitCoords[1].x;
            y = g_Ball.warioStarHitCoords[1].y;
            z = g_Ball.warioStarHitCoords[1].z;
        }
    } else {
        x = g_Ball.AtBat_Contact_BallPos.x;
        y = g_Ball.AtBat_Contact_BallPos.y;
        z = g_Ball.AtBat_Contact_BallPos.z;
    }
    if (g_Ball.warioWaluGarlicIsActive) {
        if (secondPass) {
            vx = g_Ball.warioStarHitCoords[14].x;
            vy = g_Ball.warioStarHitCoords[14].y;
            vz = g_Ball.warioStarHitCoords[14].z;
        } else {
            vx = g_Ball.warioStarHitCoords[13].x;
            vy = g_Ball.warioStarHitCoords[13].y;
            vz = g_Ball.warioStarHitCoords[13].z;
        }
    } else {
        vx = g_Ball.physicsSubstruct.velocity.x;
        vy = g_Ball.physicsSubstruct.velocity.y;
        vz = g_Ball.physicsSubstruct.velocity.z;
    }
    ax = g_Ball.physicsSubstruct.acceleration.x;
    ay = g_Ball.physicsSubstruct.acceleration.y;
    az = g_Ball.physicsSubstruct.acceleration.z;
    scale = 1.0f - g_Ball.airResistance / 10000.0f;
    if (!secondPass) {
        g_Ball.physicsSubstruct.futureCoordsAndDist[0].pos.x = x;
        g_Ball.physicsSubstruct.futureCoordsAndDist[0].pos.y = y;
        g_Ball.physicsSubstruct.futureCoordsAndDist[0].pos.z = z;
        g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist =
            VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.futureCoordsAndDist[0].pos);
        if (g_Ball.physicsSubstruct.velocity.x == 0.0f && g_Ball.physicsSubstruct.velocity.y == 0.0f &&
            g_Ball.physicsSubstruct.velocity.z == 0.0f) {
            stopped = TRUE;
        }
        if (g_Ball.AtBat_ContactResult != 0) {
            landed = TRUE;
        }
    }
    do {
        prevX = x;
        prevY = y;
        prevZ = z;
        vy -= g_Ball.physicsSubstruct.gravity;
        if (!apexFound && !landed && vy < 0.0f) {
            if (g_Ball.maxYOfHit < y) {
                g_Ball.maxYOfHit = y;
            }
            apexFound = TRUE;
        }
        vy *= scale;
        vx *= scale;
        vz *= scale;
        vy += ay;
        vx += ax;
        vz += az;
        y += vy;
        x += vx;
        z += vz;
        if (y < g_Ball.groundYForBounces) {
            t = prevY - y;
            x -= prevX;
            z -= prevZ;
            t = (prevY - g_Ball.groundYForBounces) / t;
            x = t * x + prevX;
            remain = 1.0f - t;
            z = t * z + prevZ;
            vy = -vy;
            if (secondPass) {
                g_Ball.peachDaisyStarHitFielderLoc.x = x;
                g_Ball.peachDaisyStarHitFielderLoc.z = z;
                return;
            }
            if (!landed) {
                g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x = x;
                g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z = z;
                g_Ball.landingSpotAngle = fn_3_9FB8C(x, z);
                if (mode == 0) {
                    g_Ball.landingSpotLocation.x = x;
                    g_Ball.landingSpotLocation.z = z;
                } else if (mode == 1 && g_Ball.AtBat_ContactResult == 0) {
                    g_Ball.landingSpotLocation.x = x;
                    g_Ball.landingSpotLocation.z = z;
                }
                if (g_Ball.AtBat_ContactResult == 0) {
                    g_Ball.hangtimeOfHit = frame + g_Ball.framesSinceHit;
                }
                landed = TRUE;
                g_Ball.framesUntilBallHitsGround = frame;
                if (g_Ball.AtBat_ContactResult == 0) {
                    code = g_Ball.collisionCode & 0x7F;
                    vx *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._08;
                    vz *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._08;
                    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && code >= 0x70 && code < 0x79) {
                        vy *= lbl_3_data_4414._00;
                    } else {
                        vy *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._00;
                    }
                    if (!stopped && vy < lbl_3_data_4604 && 0 >= (int)lbl_3_data_4608) {
                        stopped = TRUE;
                    }
                    if (stopped) {
                        vy = 0.0f;
                    }
                } else {
                    code = g_Ball.collisionCode & 0x7F;
                    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && code >= 0x70 && code < 0x79) {
                        if (bounces == 0) {
                            vy *= lbl_3_data_4414._00;
                        } else {
                            vy *= lbl_3_data_4414._04;
                        }
                    } else if (bounces == 0) {
                        vy *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._00;
                    } else {
                        vy *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._04;
                    }
                    if (!stopped && vy < lbl_3_data_4604 && bounces >= lbl_3_data_4608) {
                        stopped = TRUE;
                    }
                    if (stopped) {
                        vy = 0.0f;
                    }
                    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && code >= 0x70 && code < 0x79) {
                        if (stopped) {
                            vx *= lbl_3_data_4414._10;
                            vz *= lbl_3_data_4414._10;
                        } else {
                            vx *= lbl_3_data_4414._0C;
                            vz *= lbl_3_data_4414._0C;
                        }
                    } else if (stopped) {
                        vx *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
                        vz *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
                    } else {
                        vx *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
                        vz *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
                    }
                }
            } else {
                code = g_Ball.collisionCode & 0x7F;
                if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && code >= 0x70 && code < 0x79) {
                    if (bounces == 0) {
                        vy *= lbl_3_data_4414._00;
                    } else {
                        vy *= lbl_3_data_4414._04;
                    }
                } else if (bounces == 0) {
                    vy *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._00;
                } else {
                    vy *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._04;
                }
                if (!stopped && vy < lbl_3_data_4604 && bounces >= lbl_3_data_4608) {
                    stopped = TRUE;
                }
                if (stopped) {
                    vy = 0.0f;
                }
                if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && code >= 0x70 && code < 0x79) {
                    if (stopped) {
                        vx *= lbl_3_data_4414._10;
                        vz *= lbl_3_data_4414._10;
                    } else {
                        vx *= lbl_3_data_4414._0C;
                        vz *= lbl_3_data_4414._0C;
                    }
                } else if (stopped) {
                    vx *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
                    vz *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
                } else {
                    vx *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
                    vz *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
                }
            }
            bounces++;
            x = vx * remain + x;
            z = vz * remain + z;
            ax *= 0.5f;
            az *= 0.5f;
            y = vy * remain + (0.005f + g_Ball.groundYForBounces);
        }
        if (frame < 360 && !secondPass) {
            g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x = x;
            g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.y = y;
            g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z = z;
            g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist =
                SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x) +
                SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z);
            if (mode == 0 && g_Ball.someYCoord < 0.0f && g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist > 1089.0f) {
                g_Ball.someYCoord = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.y;
            }
        }
        frame++;
    } while (!landed || frame < 360);
    for (frame = 0; frame < 360; frame++) {
        g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist = dolsqrtf2(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist);
    }
    if (mode == 0 && g_Ball.someYCoord < 0.0f) {
        g_Ball.someYCoord = 0.0f;
    }
    if (g_Ball.AtBat_ContactResult == 0) {
        g_Ball.physicsSubstruct.hitLandingSpotDistFromHome = VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot);
        if (mode == 2) {
            fn_3_DC48(TRUE);
        }
        if (g_Ball.framesUntilBallHitsGround < 360) {
            for (frame = g_Ball.framesUntilBallHitsGround; frame > 0; frame--) {
                if (g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.y > 1.3f) {
                    g_Ball._1B98 = frame;
                    break;
                }
            }
            if (frame == 0) {
                g_Ball._1B98 = -1;
            }
        } else {
            g_Ball._1B98 = 0;
        }
    }
    if (mode == 2) {
        fn_3_C034();
    }
    if (g_Ball.warioWaluGarlicIsActive && g_Ball.matchFramesAndBallAngle.garlicHitFramesSinceSplit == 1) {
        apexFound = FALSE;
        landed = FALSE;
        stopped = FALSE;
        secondPass = TRUE;
        goto restart;
    }
}

// .text:0x0000C9F4 size:0x434 mapped:0x8064BA88
void fn_3_C9F4(void) {
    s32 i;

    if (g_Ball.framesSinceHit < 0x7FFE) {
        g_Ball.framesSinceHit++;
    } else {
        g_Ball.framesSinceHit = 0x7FFF;
    }
    if (g_Ball.timeSinceBallPickedUp < 0x7FFE) {
        g_Ball.timeSinceBallPickedUp++;
    } else {
        g_Ball.timeSinceBallPickedUp = 0x7FFF;
    }
    if (g_Ball.framesSinceBallHitGroundOrWasCaught == -1) {
        g_Ball.framesSinceBallHitGroundOrWasCaught = 1;
    } else if (g_Ball.framesSinceBallHitGroundOrWasCaught < 0x7FFE) {
        g_Ball.framesSinceBallHitGroundOrWasCaught++;
    } else {
        g_Ball.framesSinceBallHitGroundOrWasCaught = 0x7FFF;
    }
    fn_3_A83C();
    if (g_Ball.fielderWBallIndex >= 0) {
        g_Ball.AtBat_Contact_BallPos.x = g_Fielders[g_Ball.fielderWBallIndex].pos.x;
        g_Ball.AtBat_Contact_BallPos.y = g_Fielders[g_Ball.fielderWBallIndex].pos.y;
        g_Ball.AtBat_Contact_BallPos.z = g_Fielders[g_Ball.fielderWBallIndex].pos.z;
        g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z = g_Ball.AtBat_Contact_BallPos.z;
    }
    g_Ball.ballDistanceFromHome = VEC_LENGTH_XZ(&g_Ball.AtBat_Contact_BallPos);
    for (i = 0; i < 360; i++) {
        g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z = g_Ball.AtBat_Contact_BallPos.z;
    }
    g_Ball.ballOnMoundInd = 0;
    g_Ball.framesSinceLastBounce = -1;
    if (g_Ball.currentStarSwing != 0) {
        g_Ball.currentStarSwing = 0;
        g_Batter.invisibleBallForPeachStarHit = 0;
        g_Ball.warioWaluGarlicIsActive = 0;
    }
}

// .text:0x0000C034 size:0x9C0 mapped:0x8064B0C8
// 99.9%: Hit_HorizontalAngle, the |0x400 - angle| temporary and &g_RunningLogic take
// r7/r6/r6 where the base has r6/r4/r7.
void fn_3_C034(void) {
    f32 dist;
    f32 adjust;
    s16 angle;
    int landingAngle;
    u8 zone;
    u8 foulSide = FALSE;
    s32 i;

    g_Ball.hitClassification1 = 1;
    if (g_Ball.Hit_HorizontalAngle < 0x1B0 || g_Ball.Hit_HorizontalAngle > 0x650 ||
        (g_Ball.Hit_VerticalAngle > 0x400 && g_Ball.Hit_VerticalAngle < 0xC00)) {
        if (g_Ball.Hit_VerticalAngle > 0x800 || g_Ball.Hit_VerticalAngle < 0) {
            g_Ball.hitClassification1 = 3;
        } else if (g_Ball.Hit_VerticalAngle > 340) {
            g_Ball.hitClassification1 = 5;
        } else {
            g_Ball.hitClassification1 = 4;
        }
    } else if (g_Ball.Hit_VerticalAngle > 0x800 || g_Ball.Hit_VerticalAngle < 0) {
        g_Ball.hitClassification1 = 0;
    } else if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 18.0f && g_Ball.Hit_VerticalAngle < 100) {
        g_Ball.hitClassification1 = 0;
    } else if (g_Ball.Hit_VerticalAngle > 340) {
        g_Ball.hitClassification1 = 2;
    }
    zone = fn_3_51DF0(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
    angle = fn_3_9FB8C(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
    if (angle < 0x1A0 || angle > 0x660) {
        foulSide = TRUE;
    }
    if ((g_Ball.Hit_HorizontalAngle < 0x1A0 || g_Ball.Hit_HorizontalAngle > 0x660) && foulSide) {
        if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > 60.0f) {
            g_Ball.hitClassification2 = 8;
        } else {
            g_Ball.hitClassification2 = 7;
        }
    } else if (g_Ball.Hit_VerticalAngle > 0x400 && g_Ball.Hit_VerticalAngle < 0xC00) {
        g_Ball.hitClassification2 = 7;
    } else if (g_Ball.hitClassification1 == 0) {
        dist = VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos);
        if (g_Ball.Hit_HorizontalPower < 70 && dist < 14.0f) {
            g_Ball.hitClassification2 = 1;
        } else {
            g_Ball.hitClassification2 = 2;
        }
    } else {
        if (zone <= 1) {
            dist = VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos);
            if (g_Ball.Hit_HorizontalPower < 70 && dist < 10.0f &&
                g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 18.0f) {
                g_Ball.hitClassification2 = 1;
                goto classified;
            }
        }
        if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 30.0f && g_Ball.maxYOfHit < 2.0f) {
            g_Ball.hitClassification2 = 2;
        } else if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 20.0f && g_Ball.maxYOfHit < 4.0f) {
            g_Ball.hitClassification2 = 2;
        } else if (zone <= 1 && g_Ball.hangtimeOfHit > 180) {
            g_Ball.hitClassification2 = 4;
        } else if (zone <= 1) {
            g_Ball.hitClassification2 = 3;
        } else if (zone == 2 && g_Ball.maxYOfHit < 4.5f) {
            g_Ball.hitClassification2 = 3;
        } else if (zone <= 2) {
            g_Ball.hitClassification2 = 5;
        } else if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 70.0f ||
                   (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 80.0f && g_Ball.hangtimeOfHit < 180)) {
            g_Ball.hitClassification2 = 5;
        } else {
            g_Ball.hitClassification2 = 6;
        }
    }
classified:
    fn_3_BD78();
    g_Batter.hitTrajectory = 2;
    if (g_Ball.maybeBuntInd) {
        g_Batter.hitTrajectory = 5;
    }
    g_RunningLogic._13 = 0;
    adjust = 0.04f * __abs(0x400 - g_Ball.Hit_HorizontalAngle);
    if (g_Ball.Hit_HorizontalAngle >= 608 && g_Ball.Hit_HorizontalAngle < 1440 &&
        g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
        if (135.0f - adjust < g_Ball.physicsSubstruct.hitLandingSpotDistFromHome) {
            if (g_Ball.Hit_VerticalAngle >= 280) {
                g_Ball.homeRunClassification = 2;
                if (145.0f - adjust < g_Ball.physicsSubstruct.hitLandingSpotDistFromHome) {
                    g_Ball.homeRunClassification = 1;
                }
                g_Batter.hitTrajectory = 4;
                g_RunningLogic._13 = 1;
                if (g_Batter.batterHand == 0) {
                    if (g_Ball.Hit_HorizontalAngle < 1152) {
                        g_Batter.hitTrajectory = 4;
                    }
                } else if (g_Ball.Hit_HorizontalAngle >= 896) {
                    g_Batter.hitTrajectory = 4;
                }
            }
        } else if (125.0f - adjust < g_Ball.physicsSubstruct.hitLandingSpotDistFromHome && g_Ball.Hit_VerticalAngle >= 340) {
            g_Ball.homeRunClassification = 3;
        }
    }
    landingAngle = fn_3_9FB8C(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
    if ((g_Ball.Hit_HorizontalAngle < 480 || g_Ball.Hit_HorizontalAngle >= 1568 ||
         (landingAngle < 256 && g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > 10.0f) ||
         (landingAngle > 1792 && g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > 10.0f)) &&
        (g_d_GameSettings.StadiumID != STADIUM_ID_WARIO_PALACE || g_Ball.Hit_HorizontalAngle <= 316 ||
         g_Ball.Hit_HorizontalAngle > 1732) &&
        g_Ball.currentStarSwing != 5 && g_Ball.currentStarSwing != 6 &&
        !(g_Ball.currentStarSwing == 9 || g_Ball.currentStarSwing == 10) &&
        (g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z < g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x - 5.0f ||
         g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z < -g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x - 5.0f)) {
        if (g_Ball.maybeBuntInd) {
            if (g_Ball.Hit_HorizontalAngle < 416 || g_Ball.Hit_HorizontalAngle >= 1632) {
                g_Batter.hitTrajectory = 6;
            }
        } else if (landingAngle < 416 || landingAngle > 3456) {
            if (g_Ball.maxYOfHit > 15.0f && landingAngle > 3456 && landingAngle < 3968) {
                g_Batter.hitTrajectory = 3;
            } else {
                g_Batter.hitTrajectory = 3;
            }
        } else if (landingAngle > 1632 && landingAngle < 2688) {
            if (g_Ball.maxYOfHit > 15.0f && landingAngle > 2176) {
                g_Batter.hitTrajectory = 3;
            } else {
                g_Batter.hitTrajectory = 3;
            }
        } else if (landingAngle >= 2688 && landingAngle <= 3456) {
            g_Batter.hitTrajectory = 3;
        }
    }
    if (g_Ball.physicsSubstruct.futureCoordsAndDist[50].dist > 16.5f && g_Ball.Hit_HorizontalAngle <= 1072 &&
        g_Ball.Hit_HorizontalAngle >= 976 && g_Ball.maxYOfHit < 10.0f) {
        for (i = 10; i < 100; i += 5) {
            if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].dist > 16.0f) {
                if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y < 0.2f + g_Fielders[0]._0F4) {
                    g_Ball.lineDriveThroughPitcherInd = 1;
                }
                break;
            }
        }
    }
}

// .text:0x0000BD78 size:0x2BC mapped:0x8064AE0C
void fn_3_BD78(void) {
    f32 dist;
    s32 dir = -1;

    if (g_Ball.Hit_HorizontalAngle > 0xC00) {
        dir = 0;
    } else if (g_Ball.Hit_HorizontalAngle < 0x400 && g_Ball.Hit_VerticalAngle > 0x400 && g_Ball.Hit_VerticalAngle < 0xC00) {
        dir = 0;
    } else if (g_Ball.Hit_HorizontalAngle > 0x800) {
        dir = 1;
    } else if (g_Ball.Hit_VerticalAngle > 0x400 && g_Ball.Hit_VerticalAngle < 0xC00) {
        dir = 1;
    } else if (g_Ball.Hit_HorizontalAngle < 0x1B0) {
        dir = 2;
    } else if (g_Ball.Hit_HorizontalAngle > 0x650) {
        dir = 3;
    }
    if (dir == 0 || dir == 2) {
        g_Ball.hitClassification3 = 7;
    } else if (dir == 1 || dir == 3) {
        g_Ball.hitClassification3 = 8;
    } else {
        dist = VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos);
        if (dist < 3.5f) {
            g_Ball.hitClassification3 = 0;
        } else if (dist < 8.0f) {
            g_Ball.hitClassification3 = 1;
        } else if (dist < 10.0f) {
            if (g_Ball.Hit_HorizontalAngle < 0x340) {
                g_Ball.hitClassification3 = 2;
            } else if (g_Ball.Hit_HorizontalAngle >= 0x4C0) {
                g_Ball.hitClassification3 = 4;
            } else {
                g_Ball.hitClassification3 = 3;
            }
        } else if (g_Ball.hitClassification2 <= 4) {
            g_Ball.hitClassification3 = 5;
        } else {
            g_Ball.hitClassification3 = 6;
        }
    }
}

// .text:0x0000BC54 size:0x124 mapped:0x8064ACE8
void fn_3_BC54(void) {
    f32 dist;

    if (!fn_3_B7DD8(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
        if (g_Ball.AtBat_Contact_BallPos.x > 0.0f) {
            dist = g_Ball.AtBat_Contact_BallPos.z - g_Ball.AtBat_Contact_BallPos.x;
        } else {
            dist = g_Ball.AtBat_Contact_BallPos.z + g_Ball.AtBat_Contact_BallPos.x;
        }
        if (!(dist < -5.0f) && !(g_Ball.ballVelocity < 0.05f)) {
            return;
        }
    }
    fn_3_A0F0();
}

// .text:0x0000BBBC size:0x98 mapped:0x8064AC50
s32 fn_3_BBBC(VecXYZ* out, s32 count, s32 step, f32 x, f32 z) {
    f32 best = 100000000.0f;
    s32 i;
    s32 bestIdx = -1;
    f32 dx;
    f32 dz;
    f32 dist;

    for (i = 0; i < count; i += step) {
        dx = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x - x;
        dz = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z - z;
        dist = dx * dx + dz * dz;
        if (!(dist < best)) {
            break;
        }
        best = dist;
        bestIdx = i;
    }
    if (bestIdx < 0) {
        return -1;
    }
    out->x = g_Ball.physicsSubstruct.futureCoordsAndDist[bestIdx].pos.x;
    out->y = g_Ball.physicsSubstruct.futureCoordsAndDist[bestIdx].pos.y;
    out->z = g_Ball.physicsSubstruct.futureCoordsAndDist[bestIdx].pos.z;
    return bestIdx;
}

// .text:0x0000B940 size:0x27C mapped:0x8064A9D4
void fn_3_B940(void) {
    VecXYZ pos;
    Rep540Fielder* fielder;
    s32 character;
    s32 i;
    f32 x;
    f32 y;
    f32 z;
    BOOL held = FALSE;
    s32 index = g_Ball.fielderWBallIndex;

    character = index;
    if (index >= 0) {
        fielder = &g_Fielders[index];
        if (g_d_GameSettings.minigamesEnabled) {
            character = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigameControlStruct._28[index - 2]];
        }
        if (fielder->_17A == 17 && g_FieldingLogic._109 != 0) {
            getAnimRelatedCoordinates(character, 66, &pos);
        } else if (fielder->_17A == 38) {
            getAnimRelatedCoordinates(character, 9, &pos);
        } else if (lbl_800E8558[fielder->_17A][1] == 33) {
            if (fielder->_1C7 == 0) {
                getAnimRelatedCoordinates(character, 79, &pos);
            } else {
                getAnimRelatedCoordinates(character, 78, &pos);
            }
            held = TRUE;
        } else if (fielder->_1C7 == 0) {
            getAnimRelatedCoordinates(character, 25, &pos);
        } else {
            getAnimRelatedCoordinates(character, 19, &pos);
        }
        if (held) {
            if (g_Ball.timeSinceBallPickedUp <= 1) {
                x = pos.x - fielder->pos.x;
                y = -pos.y - fielder->pos.y;
                z = pos.z - fielder->pos.z;
                for (i = 0; i < 4; i++) {
                    g_Ball.offsetWhilePickedUpHistory[i].x = x;
                    g_Ball.offsetWhilePickedUpHistory[i].y = y;
                    g_Ball.offsetWhilePickedUpHistory[i].z = z;
                }
            } else {
                for (i = 3; i > 1; i--) {
                    g_Ball.offsetWhilePickedUpHistory[i].x = g_Ball.offsetWhilePickedUpHistory[i - 1].x;
                    g_Ball.offsetWhilePickedUpHistory[i].y = g_Ball.offsetWhilePickedUpHistory[i - 1].y;
                    g_Ball.offsetWhilePickedUpHistory[i].z = g_Ball.offsetWhilePickedUpHistory[i - 1].z;
                }
                VEC_COPY(&g_Ball.offsetWhilePickedUpHistory[1], &g_Ball.offsetWhilePickedUpHistory[0]);
                g_Ball.offsetWhilePickedUpHistory[0].x = pos.x - fielder->pos.x;
                g_Ball.offsetWhilePickedUpHistory[0].y = -pos.y - fielder->pos.y;
                g_Ball.offsetWhilePickedUpHistory[0].z = pos.z - fielder->pos.z;
            }
        } else {
            g_Ball.offsetWhilePickedUpHistory[0].x = pos.x - fielder->pos.x;
            g_Ball.offsetWhilePickedUpHistory[0].y = -pos.y - fielder->pos.y;
            g_Ball.offsetWhilePickedUpHistory[0].z = pos.z - fielder->pos.z;
        }
    }
}

// .text:0x0000B440 size:0x500 mapped:0x8064A4D4
void fn_3_B440(void) {
    f32 dx;
    f32 dz;
    int i;

    g_Ball.throwTimeEstimatesCompleteInd = 1;
    if (g_Ball.framesUntilThrowReachesDest < 15) {
        return;
    }
    dx = ABS(g_Ball.throwTarget.x - g_Ball.AtBat_Contact_BallPos.x);
    dz = ABS(g_Ball.throwTarget.z - g_Ball.AtBat_Contact_BallPos.z);
    if (dx > dz) {
        if (g_Ball.throwTarget.x < g_Ball.AtBat_Contact_BallPos.x) {
            for (i = 10; i < 360; i += 10) {
                if (g_Ball.throwTarget.x >= g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x) {
                    i -= 10;
                    break;
                }
            }
            for (; i < 360; i++) {
                if (g_Ball.throwTarget.x >= g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x) {
                    break;
                }
            }
        } else {
            for (i = 10; i < 360; i += 10) {
                if (g_Ball.throwTarget.x <= g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x) {
                    i -= 10;
                    break;
                }
            }
            for (; i < 360; i++) {
                if (g_Ball.throwTarget.x <= g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x) {
                    break;
                }
            }
        }
    } else if (g_Ball.throwTarget.z < g_Ball.AtBat_Contact_BallPos.z) {
            for (i = 10; i < 360; i += 10) {
                if (g_Ball.throwTarget.z >= g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z) {
                    i -= 10;
                    break;
                }
            }
            for (; i < 360; i++) {
                if (g_Ball.throwTarget.z >= g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z) {
                    break;
                }
            }
    } else {
            for (i = 10; i < 360; i += 10) {
                if (g_Ball.throwTarget.z <= g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z) {
                    i -= 10;
                    break;
                }
            }
            for (; i < 360; i++) {
                if (g_Ball.throwTarget.z <= g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z) {
                    break;
                }
            }
    }
    g_Ball.framesUntilThrowReachesDest = i;
}

// .text:0x0000A970 size:0xAD0 mapped:0x80649A04
// 99.70%: &velocity.x and &velocity.z swap r28/r27, and the star swing takes r6 for r5.
void fn_3_A970(int mode) {
    f32 speed;
    f32 angle;
    BOOL ended;

    if (mode != 1) {
        if (g_Ball.framesSinceHit < 0x7FFE) {
            g_Ball.framesSinceHit++;
        } else {
            g_Ball.framesSinceHit = 0x7FFF;
        }
        if (g_Ball.AtBat_ContactResult != 0) {
            if (g_Ball.framesSinceBallHitGroundOrWasCaught == -1) {
                g_Ball.framesSinceBallHitGroundOrWasCaught = 1;
            } else if (g_Ball.framesSinceBallHitGroundOrWasCaught < 0x7FFE) {
                g_Ball.framesSinceBallHitGroundOrWasCaught++;
            } else {
                g_Ball.framesSinceBallHitGroundOrWasCaught = 0x7FFF;
            }
        }
        if (g_Ball.framesSinceLastBounce >= 0) {
            if (g_Ball.framesSinceLastBounce < 0x7FFE) {
                g_Ball.framesSinceLastBounce++;
            } else {
                g_Ball.framesSinceLastBounce = 0x7FFF;
            }
        }
        if (g_Ball.ballBounceState != 0) {
            g_Ball.ballBounceState--;
        }
        if (g_Ball.ballState == 2) {
            if (g_Ball.framesSinceThrowStarted < 0x7FFE) {
                g_Ball.framesSinceThrowStarted++;
            } else {
                g_Ball.framesSinceThrowStarted = 0x7FFF;
            }
            if (g_Ball.framesSinceThrowStarted == 2) {
                fn_3_B440();
            } else {
                g_Ball.framesUntilThrowReachesDest--;
                if (g_Ball.framesUntilThrowReachesDest < -1) {
                    g_Ball.framesUntilThrowReachesDest = -1;
                }
            }
        }
    }
    fn_3_A83C();
    if (g_Ball.pauseBallMovementWhenInPlant) {
        fn_3_65C8();
        return;
    }
    if (g_Ball.catchAnimationTotalFrames) {
        return;
    }
    if (g_Ball.warioWaluGarlicIsActive) {
        g_Ball.AtBat_Contact_BallPos.x = g_Ball.warioStarHitCoords[0].x;
        g_Ball.AtBat_Contact_BallPos.y = g_Ball.warioStarHitCoords[0].y;
        g_Ball.AtBat_Contact_BallPos.z = g_Ball.warioStarHitCoords[0].z;
    }
    if (g_Minigame.GameMode_MiniGame == 1 && g_Ball.bODQualifyingHitInd) {
        g_Ball.physicsSubstruct.velocity.y -= lbl_3_data_21438;
    } else {
        g_Ball.physicsSubstruct.velocity.y -= g_Ball.physicsSubstruct.gravity;
        fn_3_DBD0();
    }
    g_Ball.physicsSubstruct.velocity.x += g_Ball.physicsSubstruct.acceleration.x;
    g_Ball.physicsSubstruct.velocity.y += g_Ball.physicsSubstruct.acceleration.y;
    g_Ball.physicsSubstruct.velocity.z += g_Ball.physicsSubstruct.acceleration.z;
    if ((g_Ball.currentStarSwing == 5 || g_Ball.currentStarSwing == 6) &&
        g_Ball.framesSinceHit > g_Ball.matchFramesAndBallAngle.bananaHitStartFrame &&
        g_Ball.framesSinceHit < g_Ball.matchFramesAndBallAngle.bananaHitEndFrame) {
        speed = VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.velocity);
        angle = game_atan2(g_Ball.physicsSubstruct.velocity.x, g_Ball.physicsSubstruct.velocity.z);
        if (g_Ball.directionOfBananaHit) {
            angle += g_hitFloats.DKStarAngleDelta;
        } else {
            angle -= g_hitFloats.DKStarAngleDelta;
        }
        getComponentsFromRad(angle, &g_Ball.physicsSubstruct.velocity.x, &g_Ball.physicsSubstruct.velocity.z);
        g_Ball.physicsSubstruct.velocity.z *= speed;
        g_Ball.physicsSubstruct.velocity.x *= speed;
    }
    g_Ball.AtBat_Contact_BallPos.x += g_Ball.physicsSubstruct.velocity.x;
    g_Ball.AtBat_Contact_BallPos.y += g_Ball.physicsSubstruct.velocity.y;
    g_Ball.AtBat_Contact_BallPos.z += g_Ball.physicsSubstruct.velocity.z;
    if (g_Ball.currentStarSwing == 3 || g_Ball.currentStarSwing == 4) {
        fn_3_A198();
    }
    fn_3_6C38();
    if ((g_d_GameSettings.StadiumID == STADIUM_ID_MARIO_STADIUM || g_d_GameSettings.StadiumID == STADIUM_ID_WARIO_PALACE ||
         g_d_GameSettings.StadiumID == STADIUM_ID_YOHSI_PARK || g_d_GameSettings.StadiumID == STADIUM_ID_PEACH_GARDEN ||
         g_d_GameSettings.StadiumID == STADIUM_ID_DK_JUNGLE) &&
        g_Ball.AtBat_Contact_BallPos.y < g_Ball.groundYForBounces) {
        g_Ball.AtBat_Contact_BallPos.y = g_Ball.groundYForBounces;
        if (g_Ball.physicsSubstruct.velocity.y < 0.0f) {
            g_Ball.physicsSubstruct.velocity.y *= -1.0f;
        }
    }
    g_Ball.ballDistanceFromHome = VEC_LENGTH_XZ(&g_Ball.AtBat_Contact_BallPos);
    if (g_Minigame.GameMode_MiniGame == 1) {
        return;
    }
    estimateAndSetFutureCoords(1);
    if (g_Ball.currentStarSwing == 0) {
        return;
    }
    ended = FALSE;
    if (g_Ball.someCollisionInd) {
        ended = TRUE;
    } else if (g_Ball.numFieldersWhoHandledBallDuringPlay != 0) {
        ended = TRUE;
    }
    if (g_Ball.currentStarSwing == 11 || g_Ball.currentStarSwing == 12) {
        if (ended || g_Ball.AtBat_ContactResult != 0) {
            g_Ball.currentStarSwing = 0;
            g_Batter.invisibleBallForPeachStarHit = 0;
            if (fn_3_15C014()) {
                fn_3_15C000();
            }
        } else if (g_Ball.currentStarSwing == 12) {
            if (g_Ball.framesSinceHit >= fn_3_15C014()) {
                g_Ball.currentStarSwing = 0;
                g_Batter.invisibleBallForPeachStarHit = 0;
            } else if (g_Ball.framesSinceHit >= ((s16*)&g_hitShorts)[g_Ball.currentStarSwing - 2]) {
                g_Batter.invisibleBallForPeachStarHit = 1;
            }
        } else if (g_Ball.framesSinceHit >= ((s16*)&g_hitShorts)[g_Ball.currentStarSwing]) {
            g_Ball.currentStarSwing = 0;
            g_Batter.invisibleBallForPeachStarHit = 0;
        } else if (g_Ball.framesSinceHit >= ((s16*)&g_hitShorts)[g_Ball.currentStarSwing - 2]) {
            g_Batter.invisibleBallForPeachStarHit = 1;
        }
        if (!g_Batter.invisibleBallForPeachStarHit) {
            g_Ball.autoFielderAvoidDropSpotForPeachesStarHit = 0;
        }
    } else if (ended) {
        g_Ball.currentStarSwing = 0;
    } else if (g_Ball.ballIsRollingIndicator) {
        g_Ball.currentStarSwing = 0;
    } else if (g_Ball.framesSinceLastBounce == 0) {
        if (g_Ball.currentStarSwing == 5 || g_Ball.currentStarSwing == 6) {
            g_Ball.currentStarSwing = 0;
        } else if (g_Ball.currentStarSwing == 7 || g_Ball.currentStarSwing == 8) {
            g_Ball.currentStarSwing = 0;
        } else if (g_Ball.currentStarSwing == 9 || g_Ball.currentStarSwing == 10) {
            if (g_Ball.framesOnGroundUntilPickedUp >= g_hitShorts.NEggBounces) {
                g_Ball.currentStarSwing = 0;
            }
        } else if (g_Ball.framesOnGroundUntilPickedUp >= g_hitShorts.framesOnGroundBeforeCheckingMinStarVelo) {
            if (VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.velocity) < g_hitFloats.minStarHitVelo) {
                g_Ball.currentStarSwing = 0;
            }
        }
    }
}

// .text:0x0000A83C size:0x134 mapped:0x806498D0
void fn_3_A83C(void) {
    int i;

    for (i = 59; i > 0; i--) {
        g_Ball.pastCoordinates[i].x = g_Ball.pastCoordinates[i - 1].x;
        g_Ball.pastCoordinates[i].y = g_Ball.pastCoordinates[i - 1].y;
        g_Ball.pastCoordinates[i].z = g_Ball.pastCoordinates[i - 1].z;
    }
    if (g_Ball.catchAnimationTotalFrames != 0 || g_Ball.fielderActionOccuring != 0) {
        g_Ball.pastCoordinates[0].x = g_Ball.fielderActionCatchCoords.x;
        g_Ball.pastCoordinates[0].y = g_Ball.fielderActionCatchCoords.y;
        g_Ball.pastCoordinates[0].z = g_Ball.fielderActionCatchCoords.z;
    } else {
        g_Ball.pastCoordinates[0].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.pastCoordinates[0].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.pastCoordinates[0].z = g_Ball.AtBat_Contact_BallPos.z;
    }
    if (g_Ball.currentStarSwing == 3 || g_Ball.currentStarSwing == 4) {
        for (i = 9; i > 0; i--) {
            g_Ball.warioStarHitCoords[i + 3].x = g_Ball.warioStarHitCoords[i + 2].x;
            g_Ball.warioStarHitCoords[i + 3].y = g_Ball.warioStarHitCoords[i + 2].y;
            g_Ball.warioStarHitCoords[i + 3].z = g_Ball.warioStarHitCoords[i + 2].z;
        }
        g_Ball.warioStarHitCoords[3].x = g_Ball.warioStarHitCoords[0].x;
        g_Ball.warioStarHitCoords[3].y = g_Ball.warioStarHitCoords[0].y;
        g_Ball.warioStarHitCoords[3].z = g_Ball.warioStarHitCoords[0].z;
    }
}

// .text:0x0000A198 size:0x6A4 mapped:0x8064922C
void fn_3_A198(void) {
    f32 x1;
    f32 z1;
    f32 x2;
    f32 z2;
    f32 angle;
    f32 speed;
    f32 scale;
    f32 dist;
    f32 best;
    s32 bestIdx;
    s32 i;

    if (g_Ball.framesUntilBallHitsGround > g_Ball.matchFramesAndBallAngle.garlicHitFramesUntilHitGroundForSplit) {
        return;
    }
    if (g_Ball.framesUntilBallHitsGround == g_Ball.matchFramesAndBallAngle.garlicHitFramesUntilHitGroundForSplit) {
        for (i = 9; i >= 0; i--) {
            g_Ball.warioStarHitCoords[i + 3].x = g_Ball.pastCoordinates[i].x;
            g_Ball.warioStarHitCoords[i + 3].y = g_Ball.pastCoordinates[i].y;
            g_Ball.warioStarHitCoords[i + 3].z = g_Ball.pastCoordinates[i].z;
        }
        g_Ball.physicsSubstruct.acceleration.x = 0.0f;
        g_Ball.physicsSubstruct.acceleration.y = 0.0f;
        g_Ball.physicsSubstruct.acceleration.z = 0.0f;
        g_Ball.warioStarHitCoords[0].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.warioStarHitCoords[0].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.warioStarHitCoords[0].z = g_Ball.AtBat_Contact_BallPos.z;
        g_Ball.warioStarHitCoords[1].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.warioStarHitCoords[1].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.warioStarHitCoords[1].z = g_Ball.AtBat_Contact_BallPos.z;
        g_Ball.warioStarHitCoords[2].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.warioStarHitCoords[2].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.warioStarHitCoords[2].z = g_Ball.AtBat_Contact_BallPos.z;
        angle = game_atan2(g_Ball.physicsSubstruct.velocity.x, g_Ball.physicsSubstruct.velocity.z);
        speed = VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.velocity);
        getComponentsFromRad(angle + RandomF32_Game_Range(g_hitFloats.garlicSpreadLower, g_hitFloats.garlicSpreadUpper), &x1, &z1);
        getComponentsFromRad(angle - RandomF32_Game_Range(g_hitFloats.garlicSpreadLower, g_hitFloats.garlicSpreadUpper), &x2, &z2);
        x1 *= speed;
        z1 *= speed;
        x2 *= speed;
        z2 *= speed;
        if (g_Ball.warioWaluStarHitDirection) {
            g_Ball.warioStarHitCoords[13].x = x1;
            g_Ball.warioStarHitCoords[13].y = g_Ball.physicsSubstruct.velocity.y;
            g_Ball.warioStarHitCoords[13].z = z1;
            g_Ball.warioStarHitCoords[14].x = x2;
            g_Ball.warioStarHitCoords[14].y = g_Ball.physicsSubstruct.velocity.y;
            g_Ball.warioStarHitCoords[14].z = z2;
        } else {
            g_Ball.warioStarHitCoords[13].x = x2;
            g_Ball.warioStarHitCoords[13].y = g_Ball.physicsSubstruct.velocity.y;
            g_Ball.warioStarHitCoords[13].z = z2;
            g_Ball.warioStarHitCoords[14].x = x1;
            g_Ball.warioStarHitCoords[14].y = g_Ball.physicsSubstruct.velocity.y;
            g_Ball.warioStarHitCoords[14].z = z1;
        }
        g_Ball.matchFramesAndBallAngle.garlicHitFramesSinceSplit = 0;
    } else {
        g_Ball.warioStarHitCoords[0].x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.warioStarHitCoords[0].y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.warioStarHitCoords[0].z = g_Ball.AtBat_Contact_BallPos.z;
        if (g_Ball.matchFramesAndBallAngle.garlicHitFramesSinceSplit == 3) {
            g_AiLogic._79[0] = RandomInt_Game(2);
            g_FieldingLogic._13B = 1;
        }
        scale = 1.0f - g_Ball.airResistance / 10000.0f;
        for (i = 0; i < 2; i++) {
            g_Ball.warioStarHitCoords[i + 13].y -= g_Ball.physicsSubstruct.gravity;
            g_Ball.warioStarHitCoords[i + 13].x *= scale;
            g_Ball.warioStarHitCoords[i + 13].y *= scale;
            g_Ball.warioStarHitCoords[i + 13].z *= scale;
            g_Ball.warioStarHitCoords[i + 1].x += g_Ball.warioStarHitCoords[i + 13].x;
            g_Ball.warioStarHitCoords[i + 1].y += g_Ball.warioStarHitCoords[i + 13].y;
            g_Ball.warioStarHitCoords[i + 1].z += g_Ball.warioStarHitCoords[i + 13].z;
        }
        g_Ball.AtBat_Contact_BallPos.x = g_Ball.warioStarHitCoords[1].x;
        g_Ball.AtBat_Contact_BallPos.y = g_Ball.warioStarHitCoords[1].y;
        g_Ball.AtBat_Contact_BallPos.z = g_Ball.warioStarHitCoords[1].z;
        if (g_Ball.warioStarHitCoords[1].y < 2.0f && g_Ball.framesUntilBallHitsGround < 30) {
            best = 999.9f;
            for (i = 0, bestIdx = -1; i < 9; i++) {
                dist = dolsqrtf2(SQ(g_Ball.warioStarHitCoords[2].x - g_Fielders[i].pos.x) + SQ(g_Ball.warioStarHitCoords[2].z - g_Fielders[i].pos.z));
                if (dist < best) {
                    bestIdx = i;
                    best = dist;
                }
            }
            if (best < lbl_3_data_47BC[g_Fielders[bestIdx]._1C9]) {
                fn_3_253A4(bestIdx, fn_3_9FB8C(g_Fielders[bestIdx].pos.x - g_Ball.warioStarHitCoords[2].x, g_Fielders[bestIdx].pos.z - g_Ball.warioStarHitCoords[2].z));
                g_Ball.currentStarSwing = 0;
                g_Ball.warioWaluGarlicIsActive = 0;
                return;
            }
        }
    }
    if (g_Ball.matchFramesAndBallAngle.garlicHitFramesSinceSplit < 0x7FFE) {
        g_Ball.matchFramesAndBallAngle.garlicHitFramesSinceSplit++;
    } else {
        g_Ball.matchFramesAndBallAngle.garlicHitFramesSinceSplit = 0x7FFF;
    }
    if (!g_Ball.warioWaluGarlicIsActive) {
        playSoundEffect(435);
    }
    g_Ball.warioWaluGarlicIsActive = 1;
}

// .text:0x0000A0F0 size:0xA8 mapped:0x80649184
void fn_3_A0F0(void) {
    BOOL done = FALSE;

    g_Ball.AtBat_ContactResult = -1;
    g_Ball.ballInitialHitDoneInd = 1;
    if (g_FieldingLogic._110 != 1) {
        g_FieldingLogic._110 = 1;
        g_Strikes.strikes++;
        if (g_Strikes.strikes >= 3) {
            if (g_Ball.maybeBuntInd != 0) {
                g_Ball.maybebuntOn2Strikes = 1;
                fn_3_88D88(0);
                done = TRUE;
            } else {
                g_Strikes.strikes = 2;
            }
        }
        if (!done) {
            fn_3_59918(3, 0);
        }
    }
}

// .text:0x0000A020 size:0xD0 mapped:0x806490B4
void fn_3_A020(void) {
    if (g_Ball.deadBallReason == 0) {
        g_Ball.deadBallReason = 2;
        g_Ball.deadballLastLoc.x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.deadballLastLoc.y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.deadballLastLoc.z = g_Ball.AtBat_Contact_BallPos.z;
        fn_3_A0F0();
    }
}

// .text:0x00009FA4 size:0x7C mapped:0x80649038
void fn_3_9FA4(void) {
    if (g_Ball.deadBallReason == 0) {
        g_Ball.deadballLastLoc.x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.deadballLastLoc.y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.deadballLastLoc.z = g_Ball.AtBat_Contact_BallPos.z;
        g_Ball.deadBallReason = 1;
        g_Ball.matchFramesAndBallAngle.ballOverWallFrames = 1;
        g_Ball.AtBat_ContactResult = 1;
        g_Ball.ballInitialHitDoneInd = 1;
        if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
            fn_3_59918(15, 0);
        }
    }
}

// .text:0x00009E84 size:0x120 mapped:0x80648F18
void fn_3_9E84(void) {
    if (g_Ball.deadBallReason == 0) {
        if (g_FieldingLogic._107 != 0) {
            fn_3_9E18();
        } else if (g_Ball.numFieldersWhoHandledBallDuringPlay != 0 && g_Ball.numberOfThrowsDuringPlay != 0) {
            fn_3_9E18();
        } else {
            g_Ball.deadballLastLoc.x = g_Ball.AtBat_Contact_BallPos.x;
            g_Ball.deadballLastLoc.y = g_Ball.AtBat_Contact_BallPos.y;
            g_Ball.deadballLastLoc.z = g_Ball.AtBat_Contact_BallPos.z;
            g_Ball.deadBallReason = 3;
            fn_3_59918(7, 0);
        }
    }
}

// .text:0x00009E18 size:0x6C mapped:0x80648EAC
void fn_3_9E18(void) {
    if (g_Ball.deadBallReason != 4) {
        g_Ball.deadballLastLoc.x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.deadballLastLoc.y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.deadballLastLoc.z = g_Ball.AtBat_Contact_BallPos.z;
        g_Ball.deadBallReason = 4;
        if (g_RunningLogic._00 != 0) {
            fn_3_59918(20, 0);
        }
    }
}

// .text:0x00009CE0 size:0x138 mapped:0x80648D74
f32 fn_3_9CE0(f32 x, f32 z) {
    f32 dx = x - g_Ball.AtBat_Contact_BallPos.x;
    f32 dz = z - g_Ball.AtBat_Contact_BallPos.z;
    f32 along = g_Ball.ballVelocityPercent.x * dx + g_Ball.ballVelocityPercent.z * dz;
    f32 distSq = (dx * dx + dz * dz) - along * along;

    if (distSq < 0.0f) {
        return 0.0f;
    }
    return dolsqrtf2(distSq);
}

static inline void setHowFoul(f32 dist) {
    if (dist < -20.0f) {
        g_Ball.howFoulTheBallWillBe = 3;
    } else if (dist < -10.0f) {
        g_Ball.howFoulTheBallWillBe = 2;
    } else if (dist < -5.0f) {
        g_Ball.howFoulTheBallWillBe = 1;
    } else {
        g_Ball.howFoulTheBallWillBe = 0;
    }
}

// .text:0x00009B74 size:0x16C mapped:0x80648C08
void fn_3_9B74(void) {
    f32 dist;
    f32 x;

    if (g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x > 0.0f) {
        dist = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z - g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
    } else {
        dist = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z + g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
    }
    setHowFoul(dist);
    if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > 110.0f) {
        x = g_Ball.ballWillHitBallPos.x;
        if (x < 0.0f) {
            x = -x;
        }
        setHowFoul(g_Ball.ballWillHitBallPos.z - x);
    }
    if (g_Ball.deadBallReason == 1) {
        g_Ball.howFoulTheBallWillBe = 0;
    }
}

// .text:0x00009808 size:0x36C mapped:0x8064889C
void fn_3_9808(void) {
    s32 code = g_Ball.collisionCode & 0x7F;

    if (g_Ball.knockoutProcessedFlag) {
        g_Ball.physicsSubstruct.velocity.x = g_Ball.savedVelocity.x;
        g_Ball.physicsSubstruct.velocity.z = g_Ball.savedVelocity.z;
        g_Ball.knockoutProcessedFlag = 0;
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && code >= 0x70 && code < 0x79) {
        g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy = 0;
        g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4414._08;
        g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4414._08;
    } else {
        g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._08;
        g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._08;
    }
    g_Ball.AtBat_ContactResult = 1;
    g_Ball.ballHitGrroundDistanceFromHome = g_Ball.ballDistanceFromHome;
    if (g_Ball.always0_fairFoulRelated == 1 || g_Ball.bobbleLocation_1fair_2foul == 2) {
        fn_3_A0F0();
    } else if (g_Ball.always0_fairFoulRelated == 2 || g_Ball.bobbleLocation_1fair_2foul == 1) {
        g_Ball.ballInitialHitDoneInd = 1;
        g_Ball.AtBat_ContactResult = 1;
        if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
            fn_3_59918(4, 1);
        }
    } else if (fn_3_B7E10(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
        fn_3_BC54();
    } else if (fn_3_B7DD8(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
        g_Ball.ballInitialHitDoneInd = 1;
        if (fn_3_B7D6C(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z) &&
            g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
            fn_3_59918(4, 1);
        }
    }
    fn_3_8C5C8();
}

// .text:0x00009508 size:0x300 mapped:0x8064859C
void fn_3_9508(void) {
    s32 code = g_Ball.collisionCode & 0x7F;
    u8 rolling = g_Ball.ballIsRollingIndicator;

    if (g_Ball.knockoutProcessedFlag) {
        g_Ball.physicsSubstruct.velocity.x = g_Ball.savedVelocity.x;
        g_Ball.physicsSubstruct.velocity.z = g_Ball.savedVelocity.z;
        g_Ball.knockoutProcessedFlag = 0;
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && code >= 0x70 && code < 0x79) {
        if (rolling) {
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4414._10;
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4414._10;
        } else {
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4414._0C;
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4414._0C;
        }
    } else if (rolling) {
        g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
        g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
    } else {
        g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
        g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
    }
    if (!g_Ball.ballInitialHitDoneInd) {
        if (fn_3_B7E10(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
            fn_3_BC54();
        } else if (g_Ball.ballVelocity < 0.003f) {
            g_Ball.ballInitialHitDoneInd = 1;
        }
    } else if (g_Ball.numFieldersWhoHandledBallDuringPlay != 0 && g_Ball.framesOnGroundUntilPickedUp == 0 &&
               g_Ball.AtBat_ContactResult == 1) {
        fn_3_59918(4, 1);
    }
    if (g_Ball.framesOnGroundUntilPickedUp < 3) {
        fn_3_8C5C8();
    }
}

// .text:0x00009260 size:0x2A8 mapped:0x806482F4
void fn_3_9260(int collision) {
    s32 i;

    i = collision & 0x7F;
    g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4428[g_d_GameSettings.StadiumID];
    g_Ball.physicsSubstruct.velocity.y *= lbl_3_data_4428[g_d_GameSettings.StadiumID];
    g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4428[g_d_GameSettings.StadiumID];
    if (i != BALL_COLLISION_TYPE_CHOMP_HAZARD && g_Ball.AtBat_ContactResult == 0) {
        if ((collision & BALL_COLLISION_TYPE_FOUL) && g_Ball.numFieldersWhoHandledBallDuringPlay == 0) {
            fn_3_A0F0();
        } else {
            g_Ball.AtBat_ContactResult = 1;
            g_Ball.ballInitialHitDoneInd = 1;
            if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
                if (fn_3_B7D6C(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
                    fn_3_59918(4, 1);
                } else if (g_Ball.AtBat_Contact_BallPos.y < 5.0f) {
                    for (i = 0; i < 9; i++) {
                        if (g_Fielders[i]._074 < 2.0f) {
                            fn_3_59918(4, 1);
                            break;
                        }
                    }
                }
            }
        }
    }
    switch (g_d_GameSettings.StadiumID) {
    case STADIUM_ID_MARIO_STADIUM:
        fn_3_8FF5C(370, g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z);
        break;
    case STADIUM_ID_BOWSERS_CASTLE:
        fn_3_8FF5C(417, g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z);
        break;
    case STADIUM_ID_WARIO_PALACE:
        fn_3_8FF5C(417, g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z);
        break;
    case STADIUM_ID_YOHSI_PARK:
        fn_3_8FF5C(419, g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z);
        break;
    case STADIUM_ID_PEACH_GARDEN:
        fn_3_8FF5C(417, g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z);
        break;
    case STADIUM_ID_DK_JUNGLE:
        fn_3_8FF5C(370, g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z);
        break;
    case STADIUM_ID_TOY_FIELD:
        fn_3_8FF5C(370, g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z);
        break;
    }
}

// .text:0x0000904C size:0x214 mapped:0x806480E0
void fn_3_904C(void) {
    g_Ball.physicsSubstruct.velocity.x = 0.3f * g_Ball.physicsSubstruct.velocity.x;
    g_Ball.physicsSubstruct.velocity.y = 0.3f * g_Ball.physicsSubstruct.velocity.y;
    g_Ball.physicsSubstruct.velocity.z = 0.3f * g_Ball.physicsSubstruct.velocity.z;
    if (g_Ball.deadBallReason == 1) {
        g_Ball.homeRunInd = 1;
    } else if (g_Ball.AtBat_ContactResult != -1) {
        if (g_Ball.AtBat_ContactResult == 0 || g_Ball.deadBallReason == 1 ||
            (g_Ball.numberOfThrowsDuringPlay == 0 && g_Ball.numFieldersWhoHandledBallDuringPlay != 0 &&
             g_Ball.framesOnGroundUntilPickedUp == 0)) {
            if (g_Ball.deadBallReason == 0) {
                g_Ball.deadballLastLoc.x = g_Ball.AtBat_Contact_BallPos.x;
                g_Ball.deadballLastLoc.y = g_Ball.AtBat_Contact_BallPos.y;
                g_Ball.deadballLastLoc.z = g_Ball.AtBat_Contact_BallPos.z;
                g_Ball.deadBallReason = 1;
                g_Ball.matchFramesAndBallAngle.ballOverWallFrames = 1;
                g_Ball.AtBat_ContactResult = 1;
                g_Ball.ballInitialHitDoneInd = 1;
                if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
                    fn_3_59918(15, 0);
                }
            }
            g_Ball.homeRunInd = 1;
        } else {
            if (g_Ball.deadBallReason == 0) {
                if (g_FieldingLogic._107 != 0) {
                    fn_3_9E18();
                } else if (g_Ball.numFieldersWhoHandledBallDuringPlay != 0 && g_Ball.numberOfThrowsDuringPlay != 0) {
                    fn_3_9E18();
                } else {
                    g_Ball.deadballLastLoc.x = g_Ball.AtBat_Contact_BallPos.x;
                    g_Ball.deadballLastLoc.y = g_Ball.AtBat_Contact_BallPos.y;
                    g_Ball.deadballLastLoc.z = g_Ball.AtBat_Contact_BallPos.z;
                    g_Ball.deadBallReason = 3;
                    fn_3_59918(7, 0);
                }
            }
        }
    }
}

// .text:0x00008CF0 size:0x35C mapped:0x80647D84
// 99.9%: offset and ballTravelAngle are added from swapped volatile registers (r0/r3).
void fn_3_8CF0(f32* speed, int frames, u8* stopped, BOOL noKnockout) {
    f32 x;
    f32 z;
    f32 dist;
    int offset;
    s32 code = g_Ball.collisionCode & 0x7F;

    if ((g_Ball.currentStarSwing == 9 || g_Ball.currentStarSwing == 10) && !noKnockout) {
        dist = VEC_DISTANCE(&g_Ball.pastCoordinates[1], &g_Ball.pastCoordinates[0]);
        dist *= g_hitFloats.eggVeloMaintainedOnBounce;
        getComponentsFromSAng(RandomInt_Game(0x200) + 0x80, &x, &z);
        *speed = dist * z;
        dist = dist * x;
        offset = RandomInt_Game(0x800) - 0x400;
        getComponentsFromSAng(offset + g_Ball.ballTravelAngle, &x, &z);
        g_Ball.knockoutProcessedFlag = 1;
        g_Ball.savedVelocity.x = dist * x;
        g_Ball.savedVelocity.z = dist * z;
        g_FieldingLogic._13B = 1;
        fn_3_27648();
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && code >= 0x70 && code < 0x79) {
        if (frames == 0) {
            *speed *= lbl_3_data_4414._00;
        } else {
            *speed *= lbl_3_data_4414._04;
        }
    } else if (frames == 0) {
        *speed *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._00;
    } else {
        *speed *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._04;
    }
    if (*stopped == 0 && *speed < lbl_3_data_4604 && frames >= lbl_3_data_4608) {
        *stopped = 1;
    }
    if (*stopped != 0) {
        *speed = 0.0f;
    }
}

static inline void applyBounceFriction(void) {
    s32 code = g_Ball.collisionCode & 0x7F;
    u8 rolling = g_Ball.ballIsRollingIndicator;

    if (g_Ball.knockoutProcessedFlag) {
        g_Ball.physicsSubstruct.velocity.x = g_Ball.savedVelocity.x;
        g_Ball.physicsSubstruct.velocity.z = g_Ball.savedVelocity.z;
        g_Ball.knockoutProcessedFlag = 0;
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && code >= 0x70 && code < 0x79) {
        if (rolling) {
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4414._10;
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4414._10;
        } else {
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4414._0C;
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4414._0C;
        }
    } else if (rolling) {
        g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
        g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
    } else {
        g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
        g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
    }
}

static inline void keepMinimumSpeed(void) {
    f32 speed = dolsqrtf2(SQ(g_Ball.physicsSubstruct.velocity.x) + SQ(g_Ball.physicsSubstruct.velocity.z));

    if (speed < 0.03f) {
        if (speed == 0.0f) {
            g_Ball.physicsSubstruct.velocity.x = 0.03f * (g_Ball.AtBat_Contact_BallPos.x / g_Ball.ballDistanceFromHome);
            g_Ball.physicsSubstruct.velocity.z = 0.03f * (g_Ball.AtBat_Contact_BallPos.z / g_Ball.ballDistanceFromHome);
        } else {
            g_Ball.physicsSubstruct.velocity.x = 0.03f * (g_Ball.physicsSubstruct.velocity.x / speed);
            g_Ball.physicsSubstruct.velocity.z = 0.03f * (g_Ball.physicsSubstruct.velocity.z / speed);
        }
    }
}

static inline void stopIfSlow(void) {
    f32 speed = dolsqrtf2(SQ(g_Ball.physicsSubstruct.velocity.x) + SQ(g_Ball.physicsSubstruct.velocity.z));

    if (speed < 0.0001f) {
        g_Ball.physicsSubstruct.velocity.x = 0.0f;
        g_Ball.physicsSubstruct.velocity.z = 0.0f;
    }
}

// .text:0x00006C38 size:0x20B8 mapped:0x80645CCC
void fn_3_6C38(void) {
    VecSrcDst ray;
    CollisionStruct hit;
    Vec axis;
    Vec tangent1;
    Vec tangent2;
    Vec vel;
    f32 t;
    f32 diff;
    f32 nx;
    f32 along1;
    f32 along2;
    f32 normalComp;
    f32 speed;
    u32 collision;
    u32 type;

    g_Ball.ballOnMoundInd = 0;
    ray.src.x = g_Ball.AtBat_Contact_BallPos.x;
    ray.src.y = -g_Ball.AtBat_Contact_BallPos.y;
    ray.src.z = g_Ball.AtBat_Contact_BallPos.z;
    ray.dst.x = g_Ball.AtBat_Contact_BallPos.x;
    ray.dst.y = 10.0f;
    ray.dst.z = g_Ball.AtBat_Contact_BallPos.z;
    if (ray.src.y >= -0.1f) {
        ray.src.y = -0.1f;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        ray.src.y -= 1.0f;
        collision = checkCollision(&ray, &hit, 1, FALSE);
    } else {
        collision = checkCollision(&ray, &hit, 0, FALSE);
    }
    g_Ball.maybeCollisionRelated = g_Ball.collisionCode;
    g_Ball.physicsSubstruct.twoFrameLookback[1] = -hit.position.y;
    if (collision != 0) {
        g_Ball.collisionCode = collision;
    }
    if ((g_Ball.collisionCode & 0x7F) == 9) {
        fn_3_16D5E4(0);
    }
    if (g_Ball.ballState == 2 && g_Ball.framesSinceThrowStarted < 20) {
        return;
    }
    if (g_Ball.hitNoteBlockInd != 0) {
        if (lbl_3_common_bss_350E4._6B != 0) {
            return;
        }
        g_Ball.hitNoteBlockInd = 0;
        g_FieldingLogic._13B = 1;
        if (g_d_GameSettings.exhibitionMatchInd == 0 && lbl_3_common_bss_37400._40 == g_GameLogic.teamBatting) {
            fn_3_161588(0, g_Batter.rosterID);
        }
    }

    ray.src.x = g_Ball.pastCoordinates[0].x;
    ray.src.y = -(g_Ball.pastCoordinates[0].y - g_Ball.groundYForBounces);
    ray.src.z = g_Ball.pastCoordinates[0].z;
    ray.dst.x = g_Ball.AtBat_Contact_BallPos.x;
    ray.dst.y = -(g_Ball.AtBat_Contact_BallPos.y - g_Ball.groundYForBounces);
    ray.dst.z = g_Ball.AtBat_Contact_BallPos.z;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        collision = checkCollision(&ray, &hit, 2, TRUE);
    } else {
        collision = checkCollision(&ray, &hit, 1, TRUE);
    }
    if (collision == 0) {
        fn_3_6694();
        return;
    }
    type = collision & 0x7F;
    if (g_Ball.ballState == 2) {
        if (type == 0x10 || type == 0x11 || type == 0x12 || type == 0x13 || type == 0x14 || type == 0x15 || type == 0x21 ||
            type == 0x30 || type == 0x40 || type == 0x60 || type == 0x61) {
            return;
        }
    }
    if (g_Ball.someCollisionInd != 0) {
        if (type == 0x21 || type == 0x30 || type == 0x40 || type == 0x60 || type == 0x61) {
            return;
        }
    }
    if ((g_Ball.currentStarSwing2 == 11 || g_Ball.currentStarSwing2 == 12) && g_Ball.AtBat_ContactResult == 0) {
        if (type == 0x10 || type == 0x11 || type == 0x12 || type == 0x13 || type == 0x14 || type == 0x15 || type == 0x21 ||
            type == 0x40) {
            return;
        }
    }
    if (g_Minigame.GameMode_MiniGame == 1 && g_Ball.bODQualifyingHitInd != 0) {
        return;
    }

    if (g_Ball.matchFramesAndBallAngle.framesOnGround < 0x7FFE) {
        g_Ball.matchFramesAndBallAngle.framesOnGround++;
    } else {
        g_Ball.matchFramesAndBallAngle.framesOnGround = 0x7FFF;
    }
    diff = ray.src.y - ray.dst.y;
    if (diff == 0.0f) {
        t = 1.0f;
    } else {
        t = 1.0f - (ray.src.y - hit.position.y) / diff;
    }
    g_Ball.AtBat_Contact_BallPos.x = hit.normal.x * (0.005f + g_Ball.groundYForBounces) + hit.position.x;
    g_Ball.AtBat_Contact_BallPos.y = -(hit.normal.y * (0.005f + g_Ball.groundYForBounces) + hit.position.y);
    g_Ball.AtBat_Contact_BallPos.z = hit.normal.z * (0.005f + g_Ball.groundYForBounces) + hit.position.z;
    vel.x = g_Ball.physicsSubstruct.velocity.x;
    vel.y = -g_Ball.physicsSubstruct.velocity.y;
    vel.z = g_Ball.physicsSubstruct.velocity.z;
    nx = hit.normal.x < 0.0f ? -hit.normal.x : hit.normal.x;
    if (nx < 0.5f) {
        axis.x = 1.0f;
        axis.y = 0.0f;
        axis.z = 0.0f;
    } else {
        axis.x = 0.0f;
        axis.y = 1.0f;
        axis.z = 0.0f;
    }
    fn_3_B7F18(&tangent1, &hit.normal, &axis);
    fn_3_B7F18(&tangent2, &hit.normal, &tangent1);
    along1 = vecDotProduct((VecXYZ*)&vel, (VecXYZ*)&tangent1);
    along2 = vecDotProduct((VecXYZ*)&vel, (VecXYZ*)&tangent2);
    normalComp = -vecDotProduct((VecXYZ*)&vel, (VecXYZ*)&hit.normal);
    g_Ball.physicsSubstruct.velocity.x = hit.normal.x * normalComp + (tangent1.x * along1 + tangent2.x * along2);
    g_Ball.physicsSubstruct.velocity.y = hit.normal.y * normalComp + (tangent1.y * along1 + tangent2.y * along2);
    g_Ball.physicsSubstruct.velocity.z = hit.normal.z * normalComp + (tangent1.z * along1 + tangent2.z * along2);
    g_Ball.physicsSubstruct.velocity.y *= -1.0f;

    if (type == 1 || type == 6 || type == 9 || type == 10 || type == 0x22 || type == 0x32) {
        if (g_Ball.ballIsRollingIndicator == 0) {
            fn_3_15F648(type, lbl_3_common_bss_32724._CA, (Vec*)&g_Ball.AtBat_Contact_BallPos,
                        (Vec*)&g_Ball.physicsSubstruct.velocity);
        } else if (type == 10) {
            fn_80064344((Vec*)&g_Ball.AtBat_Contact_BallPos, (Vec*)&g_Ball.physicsSubstruct.velocity);
        }
        if (g_Ball.AtBat_ContactResult == 0) {
            fn_3_8CF0(&g_Ball.physicsSubstruct.velocity.y, 0, &g_Ball.ballIsRollingIndicator, FALSE);
        } else {
            fn_3_8CF0(&g_Ball.physicsSubstruct.velocity.y, g_Ball.framesOnGroundUntilPickedUp, &g_Ball.ballIsRollingIndicator,
                      FALSE);
        }
        g_Ball.physicsSubstruct.acceleration.x *= 0.5f;
        g_Ball.physicsSubstruct.acceleration.z *= 0.5f;
        if (g_Ball.ballState == 2) {
            applyBounceFriction();
            g_Ball.thrownBallHasHitGround = 1;
        } else {
            if (g_Ball.AtBat_ContactResult == 0) {
                fn_3_9808();
            } else if (g_Ball.AtBat_ContactResult == 1) {
                fn_3_9508();
            } else if (g_Ball.AtBat_ContactResult == -1) {
                applyBounceFriction();
            } else {
                applyBounceFriction();
            }
        }
        ray.src.x = g_Ball.AtBat_Contact_BallPos.x;
        ray.src.y = -(g_Ball.AtBat_Contact_BallPos.y - g_Ball.groundYForBounces);
        ray.src.z = g_Ball.AtBat_Contact_BallPos.z;
        ray.dst.x = g_Ball.physicsSubstruct.velocity.x * t + g_Ball.AtBat_Contact_BallPos.x;
        ray.dst.y = -((g_Ball.physicsSubstruct.velocity.y * t + g_Ball.AtBat_Contact_BallPos.y) - g_Ball.groundYForBounces);
        ray.dst.z = g_Ball.physicsSubstruct.velocity.z * t + g_Ball.AtBat_Contact_BallPos.z;
        collision = checkCollision(&ray, &hit, 1, FALSE);
        if (collision == 0) {
            g_Ball.AtBat_Contact_BallPos.x += g_Ball.physicsSubstruct.velocity.x * t;
            g_Ball.AtBat_Contact_BallPos.y += g_Ball.physicsSubstruct.velocity.y * t;
            g_Ball.AtBat_Contact_BallPos.z += g_Ball.physicsSubstruct.velocity.z * t;
        }
        if (g_Ball.distLandingSpotToMound <= 3.0f) {
            g_Ball.ballOnMoundInd = 1;
        }
        if (g_Ball.framesOnGroundUntilPickedUp < 0xFE) {
            g_Ball.framesOnGroundUntilPickedUp++;
        } else {
            g_Ball.framesOnGroundUntilPickedUp = 0xFF;
        }
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            fn_3_E7350();
        }
    } else {
        g_Ball.framesSinceBallHitWall = 1;
        g_Ball.AtBat_Contact_BallPos.y += g_Ball.groundYForBounces;
        g_Ball.physicsSubstruct.acceleration.x = 0.0f;
        g_Ball.physicsSubstruct.acceleration.y = 0.0f;
        g_Ball.physicsSubstruct.acceleration.z = 0.0f;
        if (type == 4) {
            fn_3_904C();
            g_Ball.currentStarSwing = 0;
        } else if (type == 2 || type == 5 || type == 0x20) {
            fn_3_9260(collision);
            fn_3_27648();
            g_Ball.currentStarSwing = 0;
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
                fn_3_E7350();
            }
        } else if (type == 11) {
            fn_3_9260(collision);
            fn_3_27648();
            g_Ball.currentStarSwing = 0;
        } else if ((type == 3 || type == 7 || type == 8 || type == 0x23) && g_Ball.AtBat_ContactResult == 0) {
            if (g_Ball.bobbleLocation_1fair_2foul == 1) {
                if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && (type == 7 || type == 8)) {
                    fn_3_A0F0();
                } else if (g_Ball.numberOfThrowsDuringPlay == 0 && g_Ball.numFieldersWhoHandledBallDuringPlay != 0 &&
                           g_Ball.framesOnGroundUntilPickedUp == 0) {
                    if (fn_3_B7E10(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
                        fn_3_9E84();
                    } else {
                        fn_3_9FA4();
                    }
                } else {
                    fn_3_9E84();
                }
            } else if (!(collision & BALL_COLLISION_TYPE_FOUL)) {
                fn_3_9FA4();
            } else {
                fn_3_A0F0();
            }
            g_Ball.physicsSubstruct.velocity.x = 0.3f * g_Ball.physicsSubstruct.velocity.x;
            g_Ball.physicsSubstruct.velocity.y = 0.3f * g_Ball.physicsSubstruct.velocity.y;
            g_Ball.currentStarSwing = 0;
            g_Ball.physicsSubstruct.velocity.z = 0.3f * g_Ball.physicsSubstruct.velocity.z;
        } else if (type == 0x10 || type == 0x11 || type == 0x12 || type == 0x13 || type == 0x14 || type == 0x15) {
            if (type == 0x12 || type == 0x15) {
                g_Ball.hitNoteBlockInd = 1;
            } else {
                g_FieldingLogic._13B = 1;
            }
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_610C[type - 0x10];
            g_Ball.physicsSubstruct.velocity.y *= lbl_3_data_610C[type - 0x10];
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_610C[type - 0x10];
            keepMinimumSpeed();
            if (g_Ball.ballState == 2) {
                g_Ball.ballState = 1;
            }
            fn_3_27648();
            g_Ball.someCollisionVariable = 0;
            g_Ball.someCollisionInd = 1;
        } else if (type == 0x20 || type == 0x21) {
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_6124[type - 0x20];
            g_Ball.physicsSubstruct.velocity.y *= lbl_3_data_6124[type - 0x20];
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_6124[type - 0x20];
            // The target computes this speed once more and discards it: only its first compare survives.
            speed = dolsqrtf2(SQ(g_Ball.physicsSubstruct.velocity.x) + SQ(g_Ball.physicsSubstruct.velocity.z));
            keepMinimumSpeed();
            g_Ball.someCollisionVariable = 0;
            if (g_Ball.ballState == 2) {
                g_Ball.ballState = 1;
            }
            g_Ball.someCollisionInd = 1;
        } else if (type == 0x30 || type == 0x40 || type == 0x60 || type == 0x61) {
            g_Ball.physicsSubstruct.velocity.x = 0.5f * g_Ball.physicsSubstruct.velocity.x;
            g_Ball.physicsSubstruct.velocity.y = 0.5f * g_Ball.physicsSubstruct.velocity.y;
            g_Ball.physicsSubstruct.velocity.z = 0.5f * g_Ball.physicsSubstruct.velocity.z;
            keepMinimumSpeed();
            if (g_Ball.ballState == 2) {
                g_Ball.ballState = 1;
            }
            fn_3_27648();
            g_Ball.someCollisionVariable = 0;
            g_Ball.someCollisionInd = 1;
        } else if (type >= 0x70 && type < 0x79) {
            if (type == 0x70) {
                g_Ball.physicsSubstruct.velocity.x = 0.3f * g_Ball.physicsSubstruct.velocity.x;
                g_Ball.physicsSubstruct.velocity.y = 0.3f * g_Ball.physicsSubstruct.velocity.y;
                g_Ball.physicsSubstruct.velocity.z = 0.3f * g_Ball.physicsSubstruct.velocity.z;
            } else {
                if (g_Minigame.toyFieldStateInd_collisionRelated == 0) {
                    g_Minigame.toyFieldStateInd_collisionRelated = type;
                }
                g_Ball.physicsSubstruct.velocity.x = 0.3f * g_Ball.physicsSubstruct.velocity.x;
                g_Ball.physicsSubstruct.velocity.y = 0.3f * g_Ball.physicsSubstruct.velocity.y;
                g_Ball.physicsSubstruct.velocity.z = 0.3f * g_Ball.physicsSubstruct.velocity.z;
            }
        } else {
            if (g_Ball.ballState != 0) {
                g_Ball.physicsSubstruct.velocity.x = 0.05f * g_Ball.physicsSubstruct.velocity.x;
                g_Ball.physicsSubstruct.velocity.y = 0.05f * g_Ball.physicsSubstruct.velocity.y;
                g_Ball.physicsSubstruct.velocity.z = 0.05f * g_Ball.physicsSubstruct.velocity.z;
            } else {
                g_Ball.physicsSubstruct.velocity.x = 0.3f * g_Ball.physicsSubstruct.velocity.x;
                g_Ball.physicsSubstruct.velocity.y = 0.3f * g_Ball.physicsSubstruct.velocity.y;
                g_Ball.physicsSubstruct.velocity.z = 0.3f * g_Ball.physicsSubstruct.velocity.z;
            }
            if (type == 7 || type == 8) {
                if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
                    fn_3_A0F0();
                } else if (g_Ball.AtBat_ContactResult == -1) {
                    fn_3_A0F0();
                } else if (g_Ball.AtBat_ContactResult > 0) {
                    fn_3_9E84();
                } else if (g_Ball.numberOfThrowsDuringPlay == 0) {
                    if (g_Ball.numFieldersWhoHandledBallDuringPlay != 0) {
                        if (g_Ball.bobbleLocation_1fair_2foul == 2) {
                            fn_3_A0F0();
                        } else {
                            fn_3_9E84();
                        }
                    } else if (collision & BALL_COLLISION_TYPE_FOUL) {
                        fn_3_A0F0();
                    } else {
                        fn_3_9E84();
                    }
                } else {
                    fn_3_9E84();
                }
            }
            g_Ball.collisionRelated++;
            if (g_Ball.deadBallReason == 3) {
                g_Ball.collisionRelated = 2;
            }
            g_Ball.currentStarSwing = 0;
            fn_3_27648();
        }
        if (g_d_GameSettings.StadiumID == STADIUM_ID_MARIO_STADIUM || g_d_GameSettings.StadiumID == STADIUM_ID_WARIO_PALACE ||
            g_d_GameSettings.StadiumID == STADIUM_ID_YOHSI_PARK || g_d_GameSettings.StadiumID == STADIUM_ID_PEACH_GARDEN ||
            g_d_GameSettings.StadiumID == STADIUM_ID_DK_JUNGLE) {
            if (g_Ball.AtBat_Contact_BallPos.y < 0.005f + g_Ball.groundYForBounces) {
                g_Ball.AtBat_Contact_BallPos.y = 0.005f + g_Ball.groundYForBounces;
                if (g_Ball.physicsSubstruct.velocity.y < 0.0f) {
                    g_Ball.physicsSubstruct.velocity.y *= -1.0f;
                }
            }
        }
        if (g_Ball.ballIsRollingIndicator != 0 && g_Ball.physicsSubstruct.velocity.y < 0.0f) {
            g_Ball.physicsSubstruct.velocity.y *= -1.0f;
        }
        g_Ball.ballBounceState = 3;
        g_Ball.hitWallInd = 1;
        if (g_Ball.framesOnGroundUntilPickedUp < 0xFE) {
            g_Ball.framesOnGroundUntilPickedUp++;
        } else {
            g_Ball.framesOnGroundUntilPickedUp = 0xFF;
        }
        if (g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam] != 0) {
            s32 i;

            for (i = 0; i < 9; i++) {
                g_Fielders[i]._1E1 = 0;
            }
        }
    }
    stopIfSlow();
    g_Ball.framesSinceLastBounce = 0;
    if (g_Ball.currentStarSwing == 3 || g_Ball.currentStarSwing == 4) {
        g_Ball.currentStarSwing = 0;
    }
    g_Ball.warioWaluGarlicIsActive = 0;
}

// .text:0x00006694 size:0x5A4 mapped:0x80645728
void fn_3_6694(void) {
    s32 type = g_Ball.collisionCode & 0x7F;
    s32 foul = g_Ball.collisionCode & BALL_COLLISION_TYPE_FOUL;

    if (fn_3_B7E10(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
        foul = TRUE;
    }
    if (type == BALL_COLLISION_TYPE_STRUCTURE && g_Ball.deadBallReason == 0) {
        switch (g_Ball.AtBat_ContactResult) {
        case -1:
            fn_3_A020();
            break;
        case 0:
            if (g_Ball.matchFramesAndBallAngle.ballOverWallFrames >= 5) {
                if (foul) {
                    fn_3_A020();
                } else {
                    fn_3_9FA4();
                }
            }
            break;
        case 1:
            if (!g_Ball.ballInitialHitDoneInd && foul) {
                fn_3_A020();
            } else if ((g_Ball.maybeCollisionRelated & 0x7F) == BALL_COLLISION_TYPE_STRUCTURE) {
                fn_3_9E84();
            }
            break;
        default:
            fn_3_9E18();
            break;
        }
        if (g_Ball.matchFramesAndBallAngle.ballOverWallFrames == 0) {
            g_Ball.matchFramesAndBallAngle.ballOverWallFrames = 1;
        }
    } else if (g_Ball.AtBat_ContactResult == 1 && !g_Ball.ballInitialHitDoneInd &&
               g_Ball.AtBat_Contact_BallPos.z > lbl_3_data_4444[1].z) {
        g_Ball.ballInitialHitDoneInd = 1;
        if (foul) {
            fn_3_A0F0();
        } else {
            g_Ball.AtBat_ContactResult = 1;
            if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD &&
                fn_3_B7D6C(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
                fn_3_59918(4, 1);
            }
        }
    }
}

static inline void resetBallFlags(void) {
    g_Ball.currentStarSwing = 0;
    g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy = 0;
    g_Ball.someCollisionInd = 1;
    g_Ball.warioWaluGarlicIsActive = 0;
    g_Ball.autoFielderAvoidDropSpotForPeachesStarHit = 0;
    g_Ball.physicsSubstruct.acceleration.x = 0.0f;
    g_Ball.physicsSubstruct.acceleration.y = 0.0f;
    g_Ball.physicsSubstruct.acceleration.z = 0.0f;
    fn_3_27648();
}

// .text:0x00006620 size:0x74 mapped:0x806456B4
void fn_3_6620(void) {
    if (g_Ball.pauseBallMovementWhenInPlant == 0) {
        g_Ball.pauseBallMovementWhenInPlant = 1;
        g_Ball.ballCughtByPlantInd = 1;
        g_Ball.matchFramesAndBallAngle.framesInsidePlant = 0;
        g_Ball.someCollisionVariable = 0;
        resetBallFlags();
    }
}

// .text:0x000065F4 size:0x2C mapped:0x80645688
void fn_3_65F4(void) {
    g_Ball.pauseBallMovementWhenInPlant = 0;
    g_FieldingLogic._13B = 1;
    g_Ball.frameCountdownAfterLeavingPlant = 3;
}

// .text:0x000065C8 size:0x2C mapped:0x8064565C
void fn_3_65C8(void) {
    if (g_Ball.matchFramesAndBallAngle.framesInsidePlant < 0x7FFE) {
        g_Ball.matchFramesAndBallAngle.framesInsidePlant++;
        return;
    }
    g_Ball.matchFramesAndBallAngle.framesInsidePlant = 0x7FFF;
}

// .text:0x000065A8 size:0x20 mapped:0x8064563C
void fn_3_65A8(void) {
    if (g_Ball.ballState == 2) {
        g_Ball.ballState = 1;
    }
}

// .text:0x00006530 size:0x78 mapped:0x806455C4
void fn_3_6530(void) {
    g_Ball.someCollisionInd = 1;
    fn_3_65A8();
    resetBallFlags();
}
