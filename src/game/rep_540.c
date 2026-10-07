#include "game/rep_540.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/rand.h"
#include "game/rep_AC8.h"
#include "game/rep_CC8.h"
#include "game/rep_D0.h"
#include "game/rep_13B8.h"
#include "game/rep_1838.h"
#include "game/rep_1CB8.h"

extern struct {
    /* 0x00 */ s16 _00;
} g_RunningLogic;

extern f32 lbl_3_data_450C[18];

extern struct {
    /* 0x00 */ u32 _00;
} lbl_3_data_228;

typedef struct {
    /* 0x000 */ VecXYZ pos;
    /* 0x00C */ u8 _00C[0x74 - 0xC];
    /* 0x074 */ f32 _074;
    /* 0x078 */ u8 _078[0x17A - 0x78];
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x1C7 - 0x17C];
    /* 0x1C7 */ u8 _1C7;
    /* 0x1C8 */ u8 _1C8[0x268 - 0x1C8];
} Rep540Fielder; // size: 0x268

extern Rep540Fielder g_Fielders[9];
extern u8 lbl_800E8558[54][6];
extern f32 lbl_3_data_4428[7];

// m_sound.h declares these as void(void) placeholders.
extern void fn_3_8FF5C(s32 sound, f32 x, f32 y, f32 z);

// .text:0x0000FBA8 size:0x3A4 mapped:0x8064EC3C
void fn_3_FBA8(void) {
    return;
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
    u32 seed;

    fn_3_F9F8();
    seed = lbl_3_data_228._00;
    g_Ball.StaticRandomInt1 =
        (g_Ball.StaticRandomInt2 * 16 + (seed % 10 + 1) * (g_Ball.StaticRandomInt2 * g_Ball.StaticRandomInt1) + seed / 2 + g_d_GameSettings.FrameCountWhileNotAtMainMenu) & 0x7FFF;
    g_Ball.StaticRandomInt1_prePitch = g_Ball.StaticRandomInt1;
    g_Ball.StaticRandomInt2 =
        (g_Ball.StaticRandomInt1 * 8 + (seed % 10 + 1) * (g_Ball.StaticRandomInt2 * (g_Ball.StaticRandomInt2 + 1)) + seed / 2 + (g_d_GameSettings.FrameCountWhileNotAtMainMenu >> 1)) & 0x7FFF;
    g_Ball.fielderWBallIndex = -1;
}

// .text:0x0000F578 size:0x240 mapped:0x8064E60C
void fn_3_F578(void) {
    u32 seed;

    fn_3_F9F8();
    seed = lbl_3_data_228._00;
    g_Ball.StaticRandomInt1 =
        (g_Ball.StaticRandomInt2 * 16 + (seed % 10 + 1) * (g_Ball.StaticRandomInt2 * g_Ball.StaticRandomInt1) + seed / 2 + g_d_GameSettings.FrameCountWhileNotAtMainMenu) & 0x7FFF;
    g_Ball.StaticRandomInt1_prePitch = g_Ball.StaticRandomInt1;
    g_Ball.StaticRandomInt2 =
        (g_Ball.StaticRandomInt1 * 8 + (seed % 10 + 1) * (g_Ball.StaticRandomInt2 * (g_Ball.StaticRandomInt2 + 1)) + seed / 2 + (g_d_GameSettings.FrameCountWhileNotAtMainMenu >> 1)) & 0x7FFF;
    g_Ball.deadBallReason = 0;
}

// .text:0x0000F1DC size:0x39C mapped:0x8064E270
void fn_3_F1DC(void) {
    return;
}

// .text:0x0000EE4C size:0x390 mapped:0x8064DEE0
void fn_3_EE4C(void) {
    return;
}

// .text:0x0000E2D4 size:0xB78 mapped:0x8064D368
void fn_3_E2D4(void) {
    return;
}

// .text:0x0000DC48 size:0x68C mapped:0x8064CCDC
void fn_3_DC48(void) {
    return;
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
void estimateAndSetFutureCoords(int) {
    return;
}

// .text:0x0000C9F4 size:0x434 mapped:0x8064BA88
void fn_3_C9F4(void) {
    return;
}

// .text:0x0000C034 size:0x9C0 mapped:0x8064B0C8
void fn_3_C034(void) {
    return;
}

// .text:0x0000BD78 size:0x2BC mapped:0x8064AE0C
void fn_3_BD78(void) {
    return;
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
                for (i = 3; i != 0; i--) {
                    g_Ball.offsetWhilePickedUpHistory[i].x = g_Ball.offsetWhilePickedUpHistory[i - 1].x;
                    g_Ball.offsetWhilePickedUpHistory[i].y = g_Ball.offsetWhilePickedUpHistory[i - 1].y;
                    g_Ball.offsetWhilePickedUpHistory[i].z = g_Ball.offsetWhilePickedUpHistory[i - 1].z;
                }
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
    return;
}

// .text:0x0000A970 size:0xAD0 mapped:0x80649A04
void fn_3_A970(void) {
    return;
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
    return;
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
            g_Ball.deadBallReason = 3;
            g_Ball.deadballLastLoc.x = g_Ball.AtBat_Contact_BallPos.x;
            g_Ball.deadballLastLoc.y = g_Ball.AtBat_Contact_BallPos.y;
            g_Ball.deadballLastLoc.z = g_Ball.AtBat_Contact_BallPos.z;
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

// .text:0x00009B74 size:0x16C mapped:0x80648C08
void fn_3_9B74(void) {
    f32 dist;
    f32 x;

    if (g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x > 0.0f) {
        dist = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z - g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
    } else {
        dist = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z + g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
    }
    if (dist < -20.0f) {
        g_Ball.howFoulTheBallWillBe = 3;
    } else if (dist < -10.0f) {
        g_Ball.howFoulTheBallWillBe = 2;
    } else if (dist < -5.0f) {
        g_Ball.howFoulTheBallWillBe = 1;
    } else {
        g_Ball.howFoulTheBallWillBe = 0;
    }
    if (g_Ball.physicsSubstruct.hitLandingSpotDistFromHome > 110.0f) {
        x = g_Ball.ballWillHitBallPos.x;
        if (x < 0.0f) {
            x = -x;
        }
        dist = g_Ball.ballWillHitBallPos.z - x;
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
    if (g_Ball.deadBallReason == 1) {
        g_Ball.howFoulTheBallWillBe = 0;
    }
}

// .text:0x00009808 size:0x36C mapped:0x8064889C
void fn_3_9808(void) {
    return;
}

// .text:0x00009508 size:0x300 mapped:0x8064859C
void fn_3_9508(void) {
    return;
}

// .text:0x00009260 size:0x2A8 mapped:0x806482F4
void fn_3_9260(int collision) {
    s32 i;

    g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4428[g_d_GameSettings.StadiumID];
    g_Ball.physicsSubstruct.velocity.y *= lbl_3_data_4428[g_d_GameSettings.StadiumID];
    g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4428[g_d_GameSettings.StadiumID];
    if ((collision & 0x7F) != BALL_COLLISION_TYPE_CHOMP_HAZARD && g_Ball.AtBat_ContactResult == 0) {
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
            fn_3_9FA4();
            g_Ball.homeRunInd = 1;
        } else {
            fn_3_9E84();
        }
    }
}

// .text:0x00008CF0 size:0x35C mapped:0x80647D84
void fn_3_8CF0(void) {
    return;
}

// .text:0x00006C38 size:0x20B8 mapped:0x80645CCC
void fn_3_6C38(void) {
    return;
}

// .text:0x00006694 size:0x5A4 mapped:0x80645728
void fn_3_6694(void) {
    return;
}

// .text:0x00006620 size:0x74 mapped:0x806456B4
void fn_3_6620(void) {
    if (g_Ball.pauseBallMovementWhenInPlant == 0) {
        g_Ball.pauseBallMovementWhenInPlant = 1;
        g_Ball.ballCughtByPlantInd = 1;
        g_Ball.matchFramesAndBallAngle.framesInsidePlant = 0;
        g_Ball.someCollisionVariable = 0;
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

static inline void fn_3_6530_inline(void) {
    g_Ball.currentStarSwing = 0;
    g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy = 0;
    g_Ball.warioWaluGarlicIsActive = 0;
    g_Ball.autoFielderAvoidDropSpotForPeachesStarHit = 0;
    g_Ball.physicsSubstruct.acceleration.x = 0.0f;
    g_Ball.physicsSubstruct.acceleration.y = 0.0f;
    g_Ball.physicsSubstruct.acceleration.z = 0.0f;
    fn_3_27648();
}

// .text:0x00006530 size:0x78 mapped:0x806455C4
void fn_3_6530(void) {
    g_Ball.someCollisionInd = 1;
    fn_3_65A8();
    g_Ball.someCollisionInd = 1;
    fn_3_6530_inline();
}
