#include "game/rep_1200.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"

#include "game/rep_1188.h"
#include "game/rep_DB8.h"
#include "game/rep_13B8.h"
#include "game/rep_1838.h"
#include "game/rep_540.h"
#include "game/rep_CC8.h"

extern struct {
    /* 0x00 */ s32 _00;
} g_Scores;

extern struct {
    /* 0x00 */ u8 _00[0x9C];
    /* 0x9C */ u8 _9C;
} lbl_3_common_bss_32724;

extern u8 lbl_803CBC3C[];
extern u8 lbl_800E8558[][6];

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
} Rep540Friction; // size: 0x14

extern Rep540Friction lbl_3_data_4388[7];
extern f32 lbl_3_data_446C[2];
extern f32 lbl_3_data_4474[4];
extern f32 lbl_3_data_5E98[6];
extern f32 lbl_3_data_5EB0[2];
extern u8 lbl_3_data_5F50[2][5];
extern f32 lbl_3_data_5F5C[8];
extern s16 lbl_3_data_5F7C[10];
extern f32 lbl_3_data_5F90[12];
extern f32 lbl_3_data_2138C[4];
extern u8 lbl_3_data_76FC[][3];

BOOL fn_8001C920(int charID);

static s32 lbl_3_bss_172C[7];
static s32 lbl_3_bss_1728;

// .text:0x00075560 size:0x45C mapped:0x806B45F4
void fn_3_75560(void) {
    return;
}

// .text:0x000754B8 size:0xA8 mapped:0x806B454C
void fn_3_754B8(void) {
    fn_3_750C4(PITCHER_ACTION_STATE_NONE);
    g_Pitcher.pitchSpeedScaler = lbl_3_data_5F90[0];
    g_Pitcher.decelerationFactor = lbl_3_data_5F90[1];
    g_Pitcher.centerOfStrikeZone.x = 0.5f * (lbl_3_data_5E98[0] + lbl_3_data_5E98[1]);
    g_Pitcher.centerOfStrikeZone.z = 0.5f * (lbl_3_data_5E98[2] + lbl_3_data_5E98[3]);
    g_Pitcher.strikeZoneLeft = lbl_3_data_5E98[0];
    g_Pitcher.strikeZoneRight = lbl_3_data_5E98[1];
    g_Pitcher.beginningOfStrikeCheckZ = lbl_3_data_5E98[2];
    g_Pitcher.endingOfStrikeCheckZ = lbl_3_data_5E98[3];
    g_Pitcher.pitcher.x = lbl_3_data_446C[0];
    g_Pitcher.pitcher.z = lbl_3_data_446C[1];
    g_Pitcher.windupCountdownUntilBallReleased = 100;
    g_Pitcher.pitchWindUpCountDown = 100;
    g_Pitcher.curvePitchWindupFrames = 100;
    g_Pitcher.playStartOfGameAnimation = 1;
}

// .text:0x00075434 size:0x84 mapped:0x806B44C8
void fn_3_75434(void) {
    fn_3_6EBB4(g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]);
    fn_3_753E8(FALSE);
    if (g_Scores._00 == 1) {
        g_Pitcher.playStartOfGameAnimation = 1;
    }
}

// .text:0x000753E8 size:0x4C mapped:0x806B447C
void fn_3_753E8(BOOL keepAction) {
    fn_3_750C4(PITCHER_ACTION_STATE_NONE);
    if (!keepAction) {
        g_Pitcher.nPitchesThisAB = 0;
        g_Pitcher.nPickoffAttempts = 0;
    }
    g_Pitcher.pitcher.x = lbl_3_data_446C[0];
    g_Pitcher.pitcher.z = lbl_3_data_446C[1];
    g_Pitcher.pitchDeliveryAnimationPlaying = 0;
}

// .text:0x000751B4 size:0x234 mapped:0x806B4248
void fn_3_751B4(void) {
    return;
}

// .text:0x000750DC size:0xD8 mapped:0x806B4170
BOOL fn_3_750DC(void) {
    int charID = inMemRoster[g_GameLogic.teamFielding]
                            [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]]
                                .stats.CharID;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice.practiceType_2 != PRACTICE_TYPE_FREEPLAY) {
        charID = g_Pitcher.charID;
    }
    if (lbl_3_common_bss_32724._9C == 0) {
        lbl_803CBC3C[1] = 0;
        lbl_3_common_bss_32724._9C = 1;
    }
    if (lbl_3_common_bss_32724._9C == 1 && fn_8001C920(charID)) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000750C4 size:0x18 mapped:0x806B4158
void fn_3_750C4(u8 state) {
    g_Pitcher.pitcherActionState = state;
    g_Pitcher.currentStateFrameCounter = 0;
}

// .text:0x00075090 size:0x34 mapped:0x806B4124
void fn_3_75090(void) {
    fn_3_750C4(PITCHER_ACTION_STATE_PRE_PITCH);
    g_Ball.AtBat_Contact_BallPos.x = g_Pitcher.ballCurrentPosition.x;
    g_Ball.AtBat_Contact_BallPos.y = g_Pitcher.ballCurrentPosition.y;
    g_Ball.AtBat_Contact_BallPos.z = g_Pitcher.ballCurrentPosition.z;
}

// .text:0x00074D0C size:0x384 mapped:0x806B3DA0
void fn_3_74D0C(void) {
    return;
}

// .text:0x00074AC4 size:0x248 mapped:0x806B3B58
void fn_3_74AC4(void) {
    return;
}

// .text:0x00074128 size:0x99C mapped:0x806B31BC
void fn_3_74128(void) {
    return;
}

// .text:0x000740D0 size:0x58 mapped:0x806B3164
void fn_3_740D0(void) {
    g_Pitcher.nonCaptainStarPitchTriggeredType = g_Pitcher.nonCaptainStarPitch;
    switch (g_Pitcher.nonCaptainStarPitchTriggeredType) {
    case 1:
        g_Pitcher.specialPitchTypeCode = 0x10;
        break;
    case 2:
        g_Pitcher.specialPitchTypeCode = 0x11;
        break;
    case 3:
        g_Pitcher.specialPitchTypeCode = 0x12;
        break;
    }
}

// .text:0x00073FAC size:0x124 mapped:0x806B3040
void fn_3_73FAC(void) {
    g_Pitcher.eggBallBounceYHeight = g_Batter.batPosition2.y;
    g_Pitcher.pitchStartingPosition_AIMaxCurve = LinearInterpolateToNewRange(
        g_Pitcher.pitcher.x, lbl_3_data_4474[0], lbl_3_data_4474[1], lbl_3_data_5EB0[0], lbl_3_data_5EB0[1]);
    if (g_Pitcher.starPitchType == 3 || g_Pitcher.starPitchType == 4) {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = 0.0f;
    } else if (g_Pitcher.starPitchType == 9 || g_Pitcher.starPitchType == 10) {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = RandomF32_Game_Range(-lbl_3_data_5F5C[3], lbl_3_data_5F5C[3]);
        g_Pitcher.eggBallBounceYHeight = lbl_3_data_5F5C[0];
        g_Pitcher.frontOfPlateZ = RandomF32_Game_Range(lbl_3_data_5F5C[1], lbl_3_data_5F5C[2]);
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY ||
        g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER) {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = RandomF32_Game_Range(
            -lbl_3_data_2138C[g_Minigame.soloMinigameDifficulty], lbl_3_data_2138C[g_Minigame.soloMinigameDifficulty]);
    }
}

// .text:0x00073F2C size:0x80 mapped:0x806B2FC0
void fn_3_73F2C(void) {
    return;
}

// .text:0x00073DE8 size:0x144 mapped:0x806B2E7C
void fn_3_73DE8(void) {
    return;
}

// .text:0x000738A8 size:0x540 mapped:0x806B293C
void fn_3_738A8(void) {
    return;
}

// .text:0x00073850 size:0x58 mapped:0x806B28E4
void fn_3_73850(void) {
    int i;

    g_Strikes.outs++;
    for (i = 0; i < 3; i++) {
        if (g_Strikes.runnerIndexForEachOutThisPitch[i] == -1) {
            g_Strikes.runnerIndexForEachOutThisPitch[i] = 0;
            return;
        }
    }
}

// .text:0x0007372C size:0x124 mapped:0x806B27C0
void fn_3_7372C(void) {
    int i;
    BOOL blocked = FALSE;

    if (g_Pitcher.strikeOutOrWalk == 3) {
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
                if (!blocked) {
                    g_Runners[i].currentBase = i;
                    fn_3_89864(i, 1);
                } else {
                    g_Runners[i].currentBase = g_Runners[i].startingBase_baseAchieved;
                    g_Runners[i].nextBase = (g_Runners[i].currentBase + 1) & 3;
                }
            } else {
                blocked = TRUE;
            }
        }
    } else {
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
                if (i == g_Runners[i].currentBase) {
                    fn_3_89864(i, 1);
                }
            } else {
                break;
            }
        }
    }
    g_Runners[0].currentBase = 1;
    g_Runners[0].nextBase = 2;
}

// .text:0x00073718 size:0x14 mapped:0x806B27AC
void fn_3_73718(void) {
    g_Ball.postPitchResultCounter = -1;
}

// .text:0x000736CC size:0x4C mapped:0x806B2760
void fn_3_736CC(void) {
    int i;

    for (i = 0; i < 3; i++) {
        if (g_Strikes.runnerIndexForEachOutThisPitch[i] == -1) {
            g_Strikes.runnerIndexForEachOutThisPitch[i] = 0;
            return;
        }
    }
}

// .text:0x000735A8 size:0x124 mapped:0x806B263C
void fn_3_735A8(void) {
    int i;
    BOOL blocked = FALSE;

    if (g_Pitcher.strikeOutOrWalk == 3) {
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
                if (!blocked) {
                    g_Runners[i].currentBase = i;
                    fn_3_89864(i, 1);
                } else {
                    g_Runners[i].currentBase = g_Runners[i].startingBase_baseAchieved;
                    g_Runners[i].nextBase = (g_Runners[i].currentBase + 1) & 3;
                }
            } else {
                blocked = TRUE;
            }
        }
    } else {
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
                if (i == g_Runners[i].currentBase) {
                    fn_3_89864(i, 1);
                }
            } else {
                break;
            }
        }
    }
    g_Runners[0].currentBase = 1;
    g_Runners[0].nextBase = 2;
}

// .text:0x0007310C size:0x49C mapped:0x806B21A0
void fn_3_7310C(void) {
    return;
}

// .text:0x00072CA8 size:0x464 mapped:0x806B1D3C
void fn_3_72CA8(void) {
    return;
}

// .text:0x00072768 size:0x540 mapped:0x806B17FC
void fn_3_72768(void) {
    return;
}

// .text:0x00071248 size:0x1520 mapped:0x806B02DC
void fn_3_71248(void) {
    return;
}

// .text:0x00070EF4 size:0x354 mapped:0x806AFF88
void fn_3_70EF4(void) {
    return;
}

// .text:0x00070B94 size:0x360 mapped:0x806AFC28
void fn_3_70B94(void) {
    return;
}

// .text:0x00070AEC size:0xA8 mapped:0x806AFB80
void fn_3_70AEC(void) {
    f32 t;

    if (g_Pitcher.cancelParabolicAdjustmentInd) {
        g_Pitcher.pitchX_parabolicAdjustment = 0.0f;
    } else {
        t = g_Ball.pitchHangtimeCounter - g_Pitcher.frameWhenUnhittable / 2.0f;
        g_Pitcher.pitchX_parabolicAdjustment =
            g_Pitcher.horizontalOffsetParabolaMidpoint - g_Pitcher.horizontalGlobalParabolicVelo * t * t / 10000.0f;
    }
}

// .text:0x000709B4 size:0x138 mapped:0x806AFA48
void fn_3_709B4(void) {
    f32 angle;
    f32 y;
    f32 z;
    f32 radius;

    g_Pitcher.bulletPitchFrameCounter++;
    if (g_Pitcher.bulletPitchFrameCounter >= g_Pitcher.bulletPitchLoopFrames) {
        g_Pitcher.bulletPitchStageCode = 2;
    } else {
        angle = (f32)g_Pitcher.bulletPitchFrameCounter / (f32)g_Pitcher.bulletPitchLoopFrames;
        angle *= 6.2831855f;
        angle += 3.1415927f;
        getComponentsFromRad(angle, &y, &z);
        radius = 0.01f * lbl_3_data_5F50[g_Pitcher.starPitchType - 7][4];
        g_Pitcher.starPitchPositionAdjustment.x = 0.0f;
        g_Pitcher.bulletPitchLoopAngleRadians = angle;
        g_Pitcher.starPitchPositionAdjustment.y = radius * y + radius;
        g_Pitcher.starPitchPositionAdjustment.z = radius * z;
    }
}

// .text:0x00070838 size:0x17C mapped:0x806AF8CC
void fn_3_70838(void) {
    f32 dx;
    f32 dy;
    f32 dz;

    if (g_Pitcher.eggBallBounceNumber == 0) {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = RandomF32_Game_Range(-lbl_3_data_5F5C[6], lbl_3_data_5F5C[6]);
        g_Pitcher.eggBallBounceYHeight = lbl_3_data_5F5C[0];
        g_Pitcher.eggBallBounceZLoc = RandomF32_Game_Range(lbl_3_data_5F5C[4], lbl_3_data_5F5C[5]);
        g_Pitcher.frontOfPlateZ = 0.5f * (g_Pitcher.eggBallBounceZLoc + g_Pitcher.frontOfPlateZ);
    } else {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = RandomF32_Game_Range(-lbl_3_data_5F5C[7], lbl_3_data_5F5C[7]);
        g_Pitcher.eggBallBounceYHeight = lbl_3_data_5F5C[0];
        g_Pitcher.frontOfPlateZ = g_Pitcher.centerOfStrikeZone.z;
    }
    g_Pitcher.pitchSpeed = RandomInt_Game_Range(lbl_3_data_5F7C[4], lbl_3_data_5F7C[5]);
    g_Pitcher.eggBallBounceNumber++;
    g_Pitcher.framesSinceFirstEggBounce = 0;
    dx = g_Pitcher.pitchStartingPosition_AIMaxCurve - g_Pitcher.ballCurrentPosition.x;
    dy = g_Pitcher.eggBallBounceYHeight - g_Pitcher.ballCurrentPosition.y;
    dz = g_Pitcher.ballCurrentPosition.z - g_Pitcher.frontOfPlateZ;
    g_Pitcher.ballVelocity.z = -(g_Pitcher.pitchSpeed / g_Pitcher.pitchSpeedScaler);
    g_Pitcher.ballVelocity.x = -(dx * g_Pitcher.ballVelocity.z / dz);
    g_Pitcher.ballVelocity.y = -(dy * g_Pitcher.ballVelocity.z / dz);
}

// .text:0x00070768 size:0xD0 mapped:0x806AF7FC
int fn_3_70768(f32* outX, BOOL curve, f32 targetZ) {
    int frames = 0;
    f32 z = g_Pitcher.ballCurrentPosition.z;
    f32 x = g_Pitcher.ballCurrentPosition.x;
    f32 vx = g_Pitcher.ballVelocity.x;
    f32 vy = g_Pitcher.ballVelocity.y;
    f32 vz = g_Pitcher.ballVelocity.z;
    f32 curveVelo = g_Pitcher.pitchCurveVeloV1;
    f32 prevX;
    f32 prevZ;
    f32 airZ;
    f32 adj;
    f32 decel;
    f32 slowedVz;
    f32 dist;

    if (z < targetZ) {
        return 0;
    }
    airZ = g_Pitcher.pitchZ_whenAirResistanceStarts;
    adj = g_Pitcher.airResistance_veloAdj;
    decel = g_Pitcher.decelerationFactor;
    while (TRUE) {
        prevX = x;
        prevZ = z;
        frames++;
        if (z <= airZ) {
            slowedVz = vz - vz * adj;
            if (slowedVz < -0.05f) {
                vz = slowedVz;
                vx = vx - vx * adj;
                vy = vy - vy * adj;
            }
        }
        vx *= decel;
        vz *= decel;
        vy *= decel;
        x += vx;
        z += vz;
        if (curve) {
            x += curveVelo;
        }
        if (z < targetZ) break;
    }
    dist = z - prevZ;
    dist = (1.0f - (z - targetZ) / dist) * (x - prevX);
    *outX = prevX + dist;
    return frames;
}

// .text:0x000706B8 size:0xB0 mapped:0x806AF74C
void fn_3_706B8(int which) {
    f32 t;

    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_WALLBALL) {
        return;
    }
    t = (g_Pitcher.strikeCheckZ[which] - g_Pitcher.ballCurrentPosition.z) /
        (g_Pitcher.ballLastPosition.z - g_Pitcher.ballCurrentPosition.z);
    g_Pitcher.estimatedEndingPos.x =
        g_Pitcher.ballCurrentPosition.x + t * (g_Pitcher.ballLastPosition.x - g_Pitcher.ballCurrentPosition.x);
    g_Pitcher.estimatedEndingPos.z =
        g_Pitcher.ballCurrentPosition.y + t * (g_Pitcher.ballLastPosition.y - g_Pitcher.ballCurrentPosition.y);
    if (fn_3_70680(g_Pitcher.estimatedEndingPos.x)) {
        g_Pitcher.calledStrikeInd = 1;
        g_Pitcher.strikeInd = 1;
    }
}

// .text:0x00070680 size:0x38 mapped:0x806AF714
BOOL fn_3_70680(f32 x) {
    if (x >= g_Pitcher.strikeZoneLeft && x <= g_Pitcher.strikeZoneRight) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000703EC size:0x294 mapped:0x806AF480
void fn_3_703EC(void) {
    return;
}

// .text:0x00070280 size:0x16C mapped:0x806AF314
void fn_3_70280(void) {
    BOOL hit = FALSE;
    int dx;
    int dz;
    u8 type;

    if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_PITCHING && !g_Practice._1DB) {
        return;
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_WALLBALL) {
        return;
    }
    if (g_Batter.framesSinceStartOfSwing > 0) {
        return;
    }
    if (g_Pitcher.calledStrikeInd) {
        return;
    }
    dx = 100.0f * (g_Pitcher.ballCurrentPosition.x - g_Batter.batterPos.x);
    dz = 100.0f * (g_Pitcher.ballCurrentPosition.z - g_Batter.batterPos.z);
    if (g_Batter.batterHand) {
        dx = -dx;
    }
    type = lbl_800E8558[g_Batter.charID][2];
    if (dz <= lbl_3_data_76FC[type][0] && dz >= 0.0f && dx <= lbl_3_data_76FC[type][1] &&
        dx >= -lbl_3_data_76FC[type][2]) {
        hit = TRUE;
    }
    if (hit) {
        g_Batter.hitByPitch = 1;
    }
}

// .text:0x0006FFC4 size:0x2BC mapped:0x806AF058
void fn_3_6FFC4(void) {
    return;
}

// .text:0x0006FDA0 size:0x224 mapped:0x806AEE34
void fn_3_6FDA0(void) {
    int spread = g_Ball.StaticRandomInt1 % 257 - 128;
    int ang;
    f32 x;
    f32 z;
    f32 extra;
    f32 speed;

    ang = fn_3_9FB8C(g_Pitcher.ballVelocity.x, -g_Pitcher.ballVelocity.z);
    getComponentsFromSAng(ang + spread, &x, &z);
    extra = 0.01f * (g_Ball.StaticRandomInt2 % 10);
    speed = dolsqrtf2(SQ(g_Pitcher.ballVelocity.x) + SQ(g_Pitcher.ballVelocity.z));
    g_Ball.physicsSubstruct.velocity.x = (0.1f + extra) * (x * speed);
    g_Ball.physicsSubstruct.velocity.z = (0.1f + extra) * (z * speed);
    g_Ball.physicsSubstruct.velocity.y = 0.0f;
}

// .text:0x0006FB98 size:0x208 mapped:0x806AEC2C
void fn_3_6FB98(void) {
    fn_3_6FA28();
    if (g_Pitcher.currentStateFrameCounter == 10) {
        fn_3_59918(11, 0);
        fn_3_750C4(PITCHER_ACTION_STATE_HIT);
        if (g_GameLogic.IsStarChance == 1) {
            if (g_GameLogic.TeamStars[g_GameLogic.teamBatting] < 5) {
                g_GameLogic.TeamStars[g_GameLogic.teamBatting]++;
                if (g_Stats.replayInd == 0) {
                    playSoundEffect(0x19D);
                }
            }
            g_GameLogic.IsStarChance = 3;
        }
    }
}

// .text:0x0006FA28 size:0x170 mapped:0x806AEABC
void fn_3_6FA28(void) {
    if (g_Ball.pitchHangtimeCounter < 0x7FFE) {
        g_Ball.pitchHangtimeCounter++;
    } else {
        g_Ball.pitchHangtimeCounter = 0x7FFF;
    }
    if (g_Pitcher.pitchTotalTimeCounter < 0x7FFE) {
        g_Pitcher.pitchTotalTimeCounter++;
    } else {
        g_Pitcher.pitchTotalTimeCounter = 0x7FFF;
    }
    g_Ball.pastCoordinates[0].x = g_Ball.AtBat_Contact_BallPos.x;
    g_Ball.pastCoordinates[0].y = g_Ball.AtBat_Contact_BallPos.y;
    g_Ball.pastCoordinates[0].z = g_Ball.AtBat_Contact_BallPos.z;
    g_Ball.physicsSubstruct.velocity.y -= g_Ball.physicsSubstruct.gravity;
    fn_3_DBD0();
    g_Ball.AtBat_Contact_BallPos.x += g_Ball.physicsSubstruct.velocity.x;
    g_Ball.AtBat_Contact_BallPos.y += g_Ball.physicsSubstruct.velocity.y;
    g_Ball.AtBat_Contact_BallPos.z += g_Ball.physicsSubstruct.velocity.z;
    if (g_Ball.AtBat_Contact_BallPos.y < g_Ball.groundYForBounces) {
        g_Ball.physicsSubstruct.velocity.y *=
            lbl_3_data_4388[g_d_GameSettings.StadiumID]._04 - g_Ball.physicsSubstruct.velocity.y / 2.0f;
        g_Ball.physicsSubstruct.velocity.y = -g_Ball.physicsSubstruct.velocity.y;
        if (g_Ball.physicsSubstruct.velocity.y < 0.01f) {
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
        } else {
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
        }
        g_Ball.AtBat_Contact_BallPos.y = g_Ball.groundYForBounces;
    }
}

// .text:0x0006F748 size:0x2E0 mapped:0x806AE7DC
void fn_3_6F748(void) {
    return;
}

// .text:0x0006F6CC size:0x7C mapped:0x806AE760
BOOL fn_3_6F6CC(void) {
    int i;

    for (i = 1; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 && g_Runners[i].percentTowardsNextBase > 0.5f) {
            g_Pitcher.pickOffLoc = 4;
            fn_3_5C69C(0);
            return TRUE;
        }
    }
    return FALSE;
}
