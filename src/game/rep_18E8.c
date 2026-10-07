#include "game/rep_18E8.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"
#include "game/rep_D0.h"
#include "game/rep_3E58.h"

typedef struct {
    /* 0x000 */ f32 _000;
    /* 0x004 */ f32 _004;
    /* 0x008 */ f32 _008;
    /* 0x00C */ u8 _00C[0x14 - 0xC];
    /* 0x014 */ f32 _014;
    /* 0x018 */ f32 _018;
    /* 0x01C */ f32 _01C;
    /* 0x020 */ u8 _020[0x30 - 0x20];
    /* 0x030 */ f32 _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x48 - 0x40];
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x50 - 0x4C];
    /* 0x050 */ f32 _050;
    /* 0x054 */ u8 _054[0x58 - 0x54];
    /* 0x058 */ f32 _058;
    /* 0x05C */ f32 _05C;
    /* 0x060 */ u8 _060[0x68 - 0x60];
    /* 0x068 */ f32 _068;
    /* 0x06C */ u8 _06C[0x70 - 0x6C];
    /* 0x070 */ f32 _070;
    /* 0x074 */ u8 _074[0xA8 - 0x74];
    /* 0x0A8 */ f32 _0A8[4];
    /* 0x0B8 */ f32 _0B8;
    /* 0x0BC */ u8 _0BC[0xF4 - 0xBC];
    /* 0x0F4 */ f32 _0F4;
    /* 0x0F8 */ u8 _0F8[0x120 - 0xF8];
    /* 0x120 */ f32 _120;
    /* 0x124 */ f32 _124;
    /* 0x128 */ u8 _128[0x174 - 0x128];
    /* 0x174 */ f32 _174;
    /* 0x178 */ s16 _178;
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x17E - 0x17C];
    /* 0x17E */ s16 _17E;
    /* 0x180 */ u8 _180[0x18C - 0x180];
    /* 0x18C */ s16 _18C;
    /* 0x18E */ u8 _18E[0x192 - 0x18E];
    /* 0x192 */ s16 _192;
    /* 0x194 */ u8 _194[0x1AC - 0x194];
    /* 0x1AC */ s16 _1AC;
    /* 0x1AE */ u8 _1AE[0x1C2 - 0x1AE];
    /* 0x1C2 */ s16 _1C2;
    /* 0x1C4 */ u8 _1C4[0x1C9 - 0x1C4];
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA[0x1CD - 0x1CA];
    /* 0x1CD */ u8 _1CD;
    /* 0x1CE */ u8 _1CE;
    /* 0x1CF */ u8 _1CF[0x1D2 - 0x1CF];
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3[0x1D7 - 0x1D3];
    /* 0x1D7 */ u8 _1D7;
    /* 0x1D8 */ u8 _1D8[0x1E0 - 0x1D8];
    /* 0x1E0 */ u8 _1E0;
    /* 0x1E1 */ u8 _1E1[0x1E2 - 0x1E1];
    /* 0x1E2 */ u8 _1E2;
    /* 0x1E3 */ u8 _1E3[0x1ED - 0x1E3];
    /* 0x1ED */ u8 _1ED;
    /* 0x1EE */ u8 _1EE;
    /* 0x1EF */ u8 _1EF[0x1F5 - 0x1EF];
    /* 0x1F5 */ s8 _1F5;
    /* 0x1F6 */ u8 _1F6[0x1F7 - 0x1F6];
    /* 0x1F7 */ s8 _1F7;
    /* 0x1F8 */ u8 _1F8;
    /* 0x1F9 */ u8 _1F9[0x200 - 0x1F9];
    /* 0x200 */ u8 _200;
    /* 0x201 */ u8 _201[0x20D - 0x201];
    /* 0x20D */ u8 _20D;
    /* 0x20E */ u8 _20E[0x211 - 0x20E];
    /* 0x211 */ u8 _211;
    /* 0x212 */ u8 _212;
    /* 0x213 */ u8 _213;
    /* 0x214 */ u8 _214;
    /* 0x215 */ u8 _215;
    /* 0x216 */ u8 _216[0x268 - 0x216];
} Unk18E8Fielder; // size: 0x268

extern Unk18E8Fielder g_Fielders[9];
extern u8 lbl_3_data_4900[][3];
extern f32 lbl_3_data_4444[5][2];
extern u8 lbl_3_data_1C38[2];
extern s16 lbl_3_data_1C40;
extern u8 lbl_3_data_4744[24];
extern s16 lbl_3_data_4860[4][3];
extern f32 lbl_3_data_4760[3];
extern f32 lbl_3_data_4780[5];
extern f32 lbl_3_data_4878[2];
extern s16 lbl_3_data_4880;
extern u8 lbl_3_data_7E34[54][4];
extern u8 lbl_3_data_475C;
extern s16 lbl_3_data_49DC[44];

extern struct {
    /* 0x00 */ s16 _00;
    /* 0x02 */ u8 _02[0x4 - 0x2];
    /* 0x04 */ s16 _04;
} g_RunningLogic;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ struct UnkPlayer3E58* _2C50[9];
} lbl_8036E548;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ u8 _50[0xAA - 0x50];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB[0xAD - 0xAB];
    /* 0xAD */ u8 _AD;
} g_Scores;

// rep_AC8.h declares these as void(void) placeholders
extern void fn_3_52F4C(s32 fielder, f32 x, f32 z);
extern s32 fn_3_52560(s32 fielder);
extern BOOL fn_3_51798(s32 fielder, VecXYZ* delta);
extern void fn_3_5985C(s32 fielder, s32 action);
extern void fn_3_526DC(s32 fielder);

extern void fn_8004AE18(s32 fielder);
extern void fn_8004AFA8(s32 fielder);

// .bss statics, in reverse address order: MWCC lays them out last declared first
static u8 lbl_3_bss_1868[0x98];
static s32 lbl_3_bss_1858[4];
static s32 lbl_3_bss_1848[4];
static s32 lbl_3_bss_1838[4];
static s32 lbl_3_bss_1828[4];
static s32 lbl_3_bss_1824;
static s32 lbl_3_bss_1820;
static s32 lbl_3_bss_181C;
static s32 lbl_3_bss_1818;
static s32 lbl_3_bss_1808[4];
static s32 lbl_3_bss_1804;
static s32 lbl_3_bss_1800;
static u8 lbl_3_bss_17FC[4];
static s32 lbl_3_bss_17F8;

// .text:0x000ABDD0 size:0xC28 mapped:0x806EAE64
void fn_3_ABDD0(void) {
    return;
}

// .text:0x000AB5B0 size:0x820 mapped:0x806EA644
// 99.90%: registers only, in the index arithmetic of the covering fielder's _0F4 load.
void fn_3_AB5B0(s32 maxFrames, f32* angleOut, f32* speedOut) {
    f32 speed = *speedOut;
    f32 best = -9999.9f;
    f32 lift = 0.0f;
    f32 drag = 1.0f - g_Ball.airResistance / 10000.0f;
    f32 lowLimit = 0.2f;
    f32 highLimit;
    f32 dist;
    f32 angle;
    f32 step;
    f32 bestAngle;
    f32 prevAngle;
    s32 result = 0;
    s32 prevResult = 0;
    s32 iter;
    s32 retries;
    s32 frames;
    f32 vx;
    f32 vy;
    f32 y;
    f32 x;

    g_FieldingLogic._141 = 0;
    if (checkFieldingStat(g_GameLogic.teamFielding, g_Fielders[g_Ball.fielderWBallIndex]._178, 4)) {
        if (g_FieldingLogic._0C4 == 0) {
            if (g_RunningLogic._04 & 0x1000) {
                g_FieldingLogic._140 = 1;
                g_FieldingLogic._141 = 1;
                playSoundEffect(0x1A8);
            }
        } else if (g_FieldingLogic._0C4 == 0 && (g_RunningLogic._04 & 0x1100)) {
            g_FieldingLogic._140 = 1;
            g_FieldingLogic._141 = 1;
            playSoundEffect(0x1A8);
        }
    }
    highLimit = g_Fielders[g_FieldingLogic._0D0[g_FieldingLogic._0C4]]._0F4 - 0.2f;
    if (lowLimit < 0.5f * highLimit) {
        lowLimit = 0.5f * highLimit;
    }
    dist = dolsqrtf2(SQ(g_Ball.throwTarget.x - g_Ball.AtBat_Contact_BallPos.x) +
                     SQ(g_Ball.throwTarget.z - g_Ball.AtBat_Contact_BallPos.z));
    angle = 0.0f;
    bestAngle = angle;
    step = 0.025f;
    if (g_FieldingLogic.throwSpeedType <= 6) {
        if (g_FieldingLogic._12D == 0) {
            if (g_FieldingLogic.throwSpeedType != 0) {
                g_FieldingLogic.throwSpeedType--;
            }
        } else if (g_FieldingLogic._12D == 2 && g_FieldingLogic.throwSpeedType < 6) {
            g_FieldingLogic.throwSpeedType++;
        }
    }
    switch (g_FieldingLogic.throwSpeedType) {
    case 0:
        speed *= 1.3f;
        break;
    case 1:
        speed *= 1.2f;
        break;
    case 2:
        speed *= 1.1f;
        break;
    case 4:
        speed *= 0.9f;
        break;
    case 5:
        speed *= 0.8f;
        break;
    case 6:
        speed *= 0.7f;
        break;
    case 7:
        speed = 0.35f;
        if (dist < 10.0f) {
            speed = 0.3f;
        } else if (dist < 15.0f) {
            speed = 0.325f;
        }
        break;
    case 8:
        speed = 0.25f;
        angle = 0.6f;
        bestAngle = angle;
        break;
    case 9:
        speed = 0.55f;
        break;
    case 3:
    case 10:
        break;
    }
    if (g_FieldingLogic._13D) {
        lift = lbl_3_data_4760[0];
        if (g_FieldingLogic._107 == 2 && g_Ball.fielderWBallIndex == 1 && g_Ball.framesSinceHit <= 130) {
            speed *= lbl_3_data_4760[1];
        }
    }
    if (g_FieldingLogic._140) {
        speed *= lbl_3_data_4760[2];
    }
    for (iter = 0, retries = 0; iter < 12; iter++) {
        vx = speed * (f32)cos(angle);
        vy = speed * (f32)sin(angle);
        y = g_Ball.AtBat_Contact_BallPos.y;
        x = 0.0f;
        frames = 0;
        while (frames < 900) {
            frames++;
            vx *= drag;
            x += vx;
            vy -= g_Ball.physicsSubstruct.gravity;
            vy += lift;
            vy *= drag;
            y += vy;
            if (x > dist) {
                if (y < lowLimit) {
                    result = 2;
                } else if (y < highLimit) {
                    result = 3;
                } else {
                    result = 4;
                }
                break;
            }
            if (y < 0.0f) {
                result = 1;
                break;
            }
        }
        if (frames < maxFrames && retries < 5 && result != 1) {
            angle += step;
            g_FieldingLogic._140 = 0;
            retries++;
            speed *= 0.9f;
            g_FieldingLogic._141 = 0;
            continue;
        }
        if (result == 1) {
            if (prevResult >= 2) {
                break;
            }
            if (x - dist > best) {
                bestAngle = angle;
                best = x - dist;
                angle += step;
            } else {
                angle = 0.5f * (bestAngle + angle);
            }
        } else if (result == 2) {
            if (prevResult <= 1) {
                bestAngle = angle;
                angle += step;
                step *= 0.95f;
            } else if (prevResult == 4) {
                bestAngle = angle;
                angle = 0.5f * (prevAngle + angle);
                step *= 0.95f;
            } else if (y > best) {
                bestAngle = angle;
                angle += step;
            } else {
                break;
            }
            best = y;
        } else if (result == 3) {
            bestAngle = angle;
            break;
        } else if (result == 4) {
            if (prevResult <= 2) {
                bestAngle = angle;
                if (iter == 0) {
                    angle -= step;
                } else {
                    angle = 0.5f * (prevAngle + angle);
                }
            } else if (y < best) {
                bestAngle = angle;
                angle -= step;
                step *= 0.95f;
            } else {
                break;
            }
            best = y;
        }
        prevAngle = bestAngle;
        prevResult = result;
    }
    if (result == 1) {
        f32 shortfall = dist - x;
        if (shortfall > 14.0f && shortfall < 20.0f && g_FieldingLogic._0C4 == 0 && g_Ball.ballAngleFromHome > 0x3B8 &&
            g_Ball.ballAngleFromHome < 0x448) {
            bestAngle += 0.015f;
        }
        frames = 600;
    }
    *angleOut = bestAngle;
    *speedOut = speed;
    g_Ball.framesUntilThrowReachesDest = frames;
    g_Ball.throwTimeEstimatesCompleteInd = 0;
    if (g_FieldingLogic._140) {
        fn_3_1682AC(lbl_8036E548._2C50[g_Ball.fielderWBallIndex], 4);
    }
}

// .text:0x000AB554 size:0x5C mapped:0x806EA5E8
void fn_3_AB554(void) {
    if (g_FieldingLogic._10D) {
        if (g_Ball.timeSinceBallPickedUp >= 0 && g_Ball.timeSinceBallPickedUp < 40) {
            if (g_FieldingLogic._0C4 >= 0) {
                g_FieldingLogic._10C = 1;
                g_FieldingLogic._10D = 0;
            }
        } else {
            g_FieldingLogic._10D = 0;
        }
    }
}

// .text:0x000AAFF0 size:0x564 mapped:0x806EA084
void fn_3_AAFF0(f32* x, f32* z) {
    Unk18E8Fielder* t = &g_Fielders[g_FieldingLogic._0BE];
    s32 frames = fn_3_A6ABC(t->_000, t->_008);

    if (t->_17E < frames - 5) {
        *x = t->_014;
        *z = t->_01C;
    } else {
        f32 dx = t->_014 - t->_000;
        f32 dz = t->_01C - t->_008;
        f32 len = dolsqrtf2(dx * dx + dz * dz) == 0.0f ? 1.0f : dolsqrtf2(dx * dx + dz * dz);
        f32 speed;

        if (len <= 0.1f) {
            len = 0.1f;
        }
        dx /= len;
        dz /= len;
        speed = 0.9f * t->_058;
        dx *= speed;
        dz *= speed;
        *x = dx * (frames - 10) + t->_000;
        *z = dz * (frames - 10) + t->_008;
    }
    g_Ball.fielderBeingThrownTo = g_FieldingLogic._0BE;
}

// .text:0x000AAC84 size:0x36C mapped:0x806E9D18
void fn_3_AAC84(f32* x, f32* z) {
    s32 target = g_FieldingLogic._0D8;
    s32 frames;

    if (target < 0) {
        *x = lbl_3_data_4444[4][0];
        *z = lbl_3_data_4444[4][1];
        g_Ball.ballIsLooseInd_unused = 1;
        g_Ball.fielderBeingThrownTo = -1;
        return;
    }
    frames = fn_3_A6ABC(g_Fielders[target]._000, g_Fielders[target]._008);
    frames -= 10;
    if (g_Fielders[target]._17E < frames) {
        *x = g_Fielders[target]._014;
        *z = g_Fielders[target]._01C;
    } else {
        *x = frames * g_Fielders[target]._030 + g_Fielders[target]._000;
        *z = frames * g_Fielders[target]._034 + g_Fielders[target]._008;
    }
    g_Ball.fielderBeingThrownTo = target;
}

// .text:0x000AABF8 size:0x8C mapped:0x806E9C8C
BOOL fn_3_AABF8(void) {
    if (g_FieldingLogic._0D8 == -1) {
        return FALSE;
    }
    if (g_FieldingLogic.playerAtMoundCutoffLocation != 1) {
        return FALSE;
    }
    if (g_Fielders[g_FieldingLogic._0D8]._18C != 5) {
        return FALSE;
    }
    if (g_Fielders[g_Ball.fielderWBallIndex]._0B8 < 10.0f) {
        return FALSE;
    }
    return TRUE;
}

// .text:0x000AAA3C size:0x1BC mapped:0x806E9AD0
void fn_3_AAA3C(s32 fielder) {
    Unk18E8Fielder* f = &g_Fielders[fielder];

    if (g_FieldingLogic._0CE < 0 || g_FieldingLogic._0C4 < 0 || g_FieldingLogic._0C4 > 3) {
        return;
    }
    if (f->_0A8[g_FieldingLogic._0C4] > 10.0f && g_FieldingLogic._0DC < 0) {
        return;
    }
    if (g_FieldingLogic._0C4 == g_FieldingLogic._0CE && g_FieldingLogic._0E0 >= 0 && g_FieldingLogic._0E0 <= 3 &&
        (g_FieldingLogic._0DC == g_Runners[g_FieldingLogic._0E0].nextBase ||
         g_FieldingLogic._0DC == g_Runners[g_FieldingLogic._0E0].currentBase)) {
        g_FieldingLogic._119 = 1;
    }
    if (g_FieldingLogic._0CE == 9 && g_FieldingLogic._0E0 >= 0 && g_FieldingLogic._0E0 <= 3 &&
        g_Runners[g_FieldingLogic._0E0].runnerOnFieldOrOutOrScored == 1 &&
        g_FieldingLogic._0C4 == g_Runners[g_FieldingLogic._0E0].baseRunningTowards) {
        g_FieldingLogic._119 = 1;
    }
    if (g_FieldingLogic._119 && g_FieldingLogic._0C4 >= 0 && g_FieldingLogic._0C4 <= 3 &&
        fn_3_9FC1C(game_atan2(lbl_3_data_4444[g_FieldingLogic._0C4][0] - f->_000,
                              lbl_3_data_4444[g_FieldingLogic._0C4][1] - f->_008),
                   f->_048) > 0x40) {
        g_FieldingLogic._119 = 0;
    }
}

// .text:0x000A9D20 size:0xD1C mapped:0x806E8DB4
void fn_3_A9D20(void) {
    return;
}

// .text:0x000A9C74 size:0xAC mapped:0x806E8D08
void fn_3_A9C74(s32 fielder) {
    Unk18E8Fielder* f = &g_Fielders[fielder];
    BOOL stat = checkFieldingStat(g_GameLogic.teamFielding, f->_178, 5);

    if (f->_1F8 >= 3) {
        f->_215 = lbl_3_data_4900[stat][1];
    } else {
        f->_215 = lbl_3_data_4900[stat][0];
    }
    if (stat && g_FieldingLogic._0C4 >= 0) {
        playSoundEffect(0x1A8);
    }
}

// .text:0x000A9984 size:0x2F0 mapped:0x806E8A18
void fn_3_A9984(s32 fielder) {
    Unk18E8Fielder* f = &g_Fielders[fielder];
    VecXYZ delta;

    if (f->_1AC == 0) {
        if (f->_1EE <= 1) {
            f->_200 = 0;
            return;
        }
        delta.x = g_Ball.pastCoordinates[2].x - g_Ball.pastCoordinates[3].x;
        delta.y = g_Ball.pastCoordinates[2].y - g_Ball.pastCoordinates[3].y;
        delta.z = g_Ball.pastCoordinates[2].z - g_Ball.pastCoordinates[3].z;
        f->_120 = 0.7f * delta.x;
        f->_124 = 0.7f * delta.z;
        f->_200 = 1;
        if (g_d_GameSettings.minigamesEnabled) {
            fn_8004AFA8(f->_20D);
        } else {
            fn_8004AFA8(fielder);
        }
    } else {
        f32 scale = (f32)(f->_1EE - 1) / (f32)f->_1EE;
        f->_120 *= scale;
        f->_124 *= scale;
        if (f->_1EE <= 1) {
            f->_200 = 0;
        }
        if (f->_1AC > 0) {
            if (g_d_GameSettings.minigamesEnabled) {
                fn_8004AE18(f->_20D);
            } else {
                fn_8004AE18(fielder);
            }
        }
    }
    f->_030 = f->_120;
    f->_034 = f->_124;
    f->_050 = dolsqrtf2(SQ(f->_030) + SQ(f->_034));
    if (fn_3_51798(fielder, &delta)) {
        f->_120 = 0.0f;
        f->_124 = 0.0f;
        f->_030 = 0.0f;
        f->_034 = 0.0f;
        f->_050 = 0.0f;
    } else {
        f->_000 += f->_030;
        f->_008 += f->_034;
    }
}

// .text:0x000A96FC size:0x288 mapped:0x806E8790
// 99.57%: registers only, in the countdown test against the 7E34 row; the
// comparison operand order and decrement forms change nothing.
void fn_3_A96FC(s32 fielder) {
    Unk18E8Fielder* f = &g_Fielders[fielder];
    InMemRunnerType* r = &g_Runners[f->_213];
    u8 state = f->_212;
    f32 x;
    f32 z;

    if (state == 0) {
        f->_212 = 1;
        g_FieldingLogic._0F6 = r->actionFrames_countDown - 1;
    } else if (state == 1) {
        if (--g_FieldingLogic._0F6 <= 0) {
            if (f->_211 == 1) {
                f->_212 = 2;
                g_FieldingLogic._0F6 = lbl_3_data_4880;
            } else {
                f->_212 = 3;
                g_FieldingLogic._0F6 = lbl_3_data_7E34[f->_17A][2];
                f->_174 = lbl_3_data_4878[0];
                f->_1C2 = lbl_3_data_4860[f->_1F7][2];
            }
        }
    } else {
        g_FieldingLogic._0F6--;
        if (lbl_3_data_7E34[f->_17A][2] - lbl_3_data_7E34[f->_17A][3] == g_FieldingLogic._0F6 && state == 3) {
            fn_3_A9354(fielder, 0);
            g_FieldingLogic._13B = 1;
            g_FieldingLogic._111 = 0;
        }
        if (f->_212 == 3) {
            getComponentsFromSAng(f->_1C2, &x, &z);
            f->_174 *= lbl_3_data_4878[1];
            f->_030 = x * f->_174;
            f->_034 = z * f->_174;
            f->_050 = f->_174;
            f->_000 += f->_030;
            f->_008 += f->_034;
        }
        if (g_FieldingLogic._0F6 <= 0) {
            if (f->_212 == 3) {
                fn_3_5985C(fielder, 9);
                g_FieldingLogic._0D0[f->_18C] = -1;
                g_FieldingLogic._101[f->_18C] = 0;
                f->_18C = -1;
                f->_1D7 = 0;
                if (g_Ball.fielderWBallIndex == -1) {
                    g_FieldingLogic._13B = 1;
                }
            }
            f->_212 = 0;
            f->_211 = 0;
        }
    }
}

// .text:0x000A9354 size:0x3A8 mapped:0x806E83E8
void fn_3_A9354(s32 fielder, s32 mode) {
    Unk18E8Fielder* f = &g_Fielders[fielder];
    VecSrcDst line;
    CollisionStruct hit;
    f32 x;
    f32 z;
    u32 type;
    s32 angle;
    f32 speed;
    s32 i;

    if (g_Ball.fielderWBallIndex != fielder) {
        return;
    }
    g_Ball.AtBat_Contact_BallPos.x = f->_000 + g_Ball.offsetWhilePickedUpHistory[0].x;
    g_Ball.AtBat_Contact_BallPos.y = f->_004 + g_Ball.offsetWhilePickedUpHistory[0].y;
    g_Ball.AtBat_Contact_BallPos.z = f->_008 + g_Ball.offsetWhilePickedUpHistory[0].z;
    line.src.x = g_Ball.AtBat_Contact_BallPos.x;
    line.src.y = -10.0f;
    line.src.z = g_Ball.AtBat_Contact_BallPos.z;
    line.dst.x = g_Ball.AtBat_Contact_BallPos.x;
    line.dst.y = 5.0f;
    line.dst.z = g_Ball.AtBat_Contact_BallPos.z;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        type = checkCollision(&line, &hit, 2, FALSE);
    } else {
        type = checkCollision(&line, &hit, 1, FALSE);
    }
    type &= 0x7F;
    if (type != 1 && type != 6 && type - 9 > 1) {
        g_Ball.AtBat_Contact_BallPos.x = f->_000;
        g_Ball.AtBat_Contact_BallPos.y = f->_004;
        g_Ball.AtBat_Contact_BallPos.z = f->_008;
        g_Ball.AtBat_Contact_BallPos.y = g_Ball.offsetWhilePickedUpHistory[0].y;
    }
    if (g_Ball.AtBat_Contact_BallPos.y < 0.5f) {
        g_Ball.AtBat_Contact_BallPos.y = 0.5f;
    }
    if (mode == 0) {
        angle = RandomInt_Game_Range(lbl_3_data_4860[f->_214][0], lbl_3_data_4860[f->_214][1]);
    } else if (mode == 1) {
        angle = f->_1C2;
    } else {
        angle = fn_3_9FE6C_normalizeAngle(g_Ball.ballAngleFromHome + 0x800);
    }
    getComponentsFromSAng(angle, &x, &z);
    g_Ball.physicsSubstruct.velocity.y = 0.0001f * RandomInt_Game(300) + 0.02f;
    speed = 0.0001f * RandomInt_Game(200) + 0.05f;
    g_Ball.physicsSubstruct.velocity.x = x * speed;
    g_Ball.physicsSubstruct.velocity.z = z * speed;
    g_Ball.framesSinceThrowStarted = 0;
    g_Ball.ballState = 3;
    g_Ball.fielderWBallIndex = -1;
    g_Ball.baseBallAndFielderAreOn = -1;
    g_Ball.ballIsLooseInd_unused = 0;
    g_Ball.fielderAboutToGetBall_hasBall = -1;
    g_Ball.thrownBallHasHitGround = 0;
    g_Ball.matchFramesAndBallAngle.framesSinceLastThrow = g_Ball.timeSinceBallPickedUp;
    g_Ball.timeSinceBallPickedUp = -1;
    g_Ball.ballIsRollingIndicator = 0;
    g_Ball.groundRuleDoubleInd = 0;
    g_FieldingLogic._124 = 0;
    g_FieldingLogic._125 = -1;
    g_FieldingLogic._12A = 0;
    for (i = 0; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            if (g_Runners[i].tagUpInd == 2) {
                g_Runners[i].baseReachedAtTimeOfThrow = g_Runners[i].startingBase_baseAchieved;
            } else {
                g_Runners[i].baseReachedAtTimeOfThrow = g_Runners[i].currentBase;
            }
        } else {
            g_Runners[i].baseReachedAtTimeOfThrow = -1;
        }
    }
}

// .text:0x000A89D4 size:0x980 mapped:0x806E7A68
void fn_3_A89D4(void) {
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];
    f32 dist;
    s32 i;

    g_FieldingLogic.throwSpeedType = 3;
    g_FieldingLogic._109 = 0;
    g_FieldingLogic._10B = 0;
    g_FieldingLogic._0E6 = 0;
    dist = dolsqrtf2(SQ(f->_000 - g_Ball.throwDestination.x) + SQ(f->_008 - g_Ball.throwDestination.z));
    if (g_FieldingLogic._119) {
        g_FieldingLogic.throwSpeedType = 9;
        return;
    }
    if (g_Runners[1].runnerOnFieldOrOutOrScored != 0 && g_Runners[1].actionCode != 0 &&
        g_Runners[1].fractionalBasesRan >= 1.8f && g_Runners[1].fractionalBasesRan <= 2.0f &&
        g_FieldingLogic._0C4 == 1 && g_Ball.baseBallAndFielderAreOn == 2) {
        g_FieldingLogic.throwSpeedType = 10;
        return;
    }
    if (dist > 45.0f || (g_Ball.ballZoneAwayFromHome >= 3 && dist > 35.0f)) {
        g_FieldingLogic._109 = 1;
    }
    if (g_FieldingLogic._0C4 >= 0 && g_FieldingLogic._0C4 <= 3) {
        if (f->_1E0 == 1 && g_Ball.timeSinceBallPickedUp < 45) {
            if (dolsqrtf2(SQ(2.0f * f->_038 + f->_000 - g_Ball.throwDestination.x) +
                          SQ(2.0f * f->_03C + f->_008 - g_Ball.throwDestination.z)) < 7.0f) {
                g_FieldingLogic.throwSpeedType = 8;
                return;
            }
        } else {
            if (dist < 6.0f) {
                g_FieldingLogic.throwSpeedType = 8;
                return;
            }
            if (dist < 7.5f && g_Fielders[g_FieldingLogic._0D0[g_FieldingLogic._0C4]]._17E > 30) {
                g_FieldingLogic.throwSpeedType = 8;
                return;
            }
        }
    }
    if (g_Ball.ballZoneAwayFromHome <= 2) {
        for (i = 0; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 &&
                (g_Runners[i].forceOutCd == 1 || g_Runners[i].tagUpInd == 2 || g_Runners[i].overrunBaseStage >= 3 ||
                 (g_Runners[i].percentTowardsNextBase <= 0.15f && g_Runners[i].runningDirectionCode == 1) ||
                 (g_Runners[i].percentTowardsNextBase >= 0.15f && g_Runners[i].percentTowardsNextBase <= 0.8f))) {
                break;
            }
        }
        if (i >= 4) {
            if (dist < 15.0f) {
                g_FieldingLogic.throwSpeedType = 7;
            } else {
                g_FieldingLogic.throwSpeedType = 5;
            }
            return;
        }
    }
    if (g_Ball.AtBat_ContactResult == -1) {
        if (dist > 30.0f) {
            g_FieldingLogic.throwSpeedType = 4;
        } else {
            g_FieldingLogic.throwSpeedType = 5;
        }
        return;
    }
    if (dist < 10.0f && g_FieldingLogic.throwSpeedType < 5) {
        g_FieldingLogic.throwSpeedType = 5;
        return;
    }
    if (g_Ball.ballZoneAwayFromHome >= 3) {
        if (g_Ball.AtBat_ContactResult != 3 && g_Runners[0].runnerOnFieldOrOutOrScored == 1 &&
            g_Runners[0].fractionalBasesRan < 1.0f && g_FieldingLogic._0C4 == 1) {
            g_FieldingLogic.throwSpeedType = 3;
        }
    } else {
        fn_3_A85C8(dist);
    }
}

// .text:0x000A85C8 size:0x40C mapped:0x806E765C
void fn_3_A85C8(f32 dist) {
    s32 runner;
    s32 frames;
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            count++;
        }
    }
    if (!fn_3_A8478(&runner, &frames)) {
        if (dist < 15.0f) {
            g_FieldingLogic.throwSpeedType = 7;
        } else if (dist < 20.0f && g_FieldingLogic.throwSpeedType < 5) {
            g_FieldingLogic.throwSpeedType = 5;
        }
    } else {
        s32 margin = fn_3_A6ABC(g_Ball.throwDestination.x, g_Ball.throwDestination.z) + 20 - frames;
        if ((g_Strikes.outs >= 2 || count == 1) && margin < -30 &&
            g_Ball.numberOfThrowsDuringPlay <= 1) {
            g_FieldingLogic.throwSpeedType = 4;
            if (dist > 30.0f) {
                g_FieldingLogic.throwSpeedType = 3;
            } else if (dist < 13.0f) {
                g_FieldingLogic.throwSpeedType = 6;
            }
            g_FieldingLogic._10B = 1;
        }
    }
}

// .text:0x000A8478 size:0x150 mapped:0x806E750C
// 99.64%: idx gets r8 where the target uses r6 (and r7 for its scaled index);
// declaration order and if/ternary forms change nothing.
BOOL fn_3_A8478(s32* runnerOut, s32* framesOut) {
    s32 idx;
    InMemRunnerType* r;
    s32 cur = g_FieldingLogic._0C4;

    if (g_FieldingLogic._0C4 >= 4 || g_FieldingLogic._0C4 < 0) {
        return FALSE;
    }
    if (g_Ball.AtBat_ContactResult == 3) {
        r = &g_Runners[cur];
        if (r->runnerOnFieldOrOutOrScored == 1 && r->tagUpInd == 2) {
            *runnerOut = cur;
            goto tagUp;
        }
    }
    idx = 3;
    if (cur != 0) {
        idx = cur - 1;
    }
    r = &g_Runners[idx];
    if (r->runnerOnFieldOrOutOrScored == 1 && r->forceOutCd == 1) {
        *runnerOut = idx;
        goto forced;
    }
    return FALSE;

tagUp:
    if (r->currentBase == cur) {
        if (r->runningDirectionCode == 3 || r->runningDirectionCode == 2) {
            *framesOut = r->framesToPreviousBase;
        } else if ((r->runningDirectionCode == 1 && r->nextDirectionBeingProcessed == 3) ||
                   (r->runningDirectionCode == 3 && r->nextDirectionBeingProcessed == 1)) {
            *framesOut = r->framesToPreviousBase + 20;
        } else {
            *framesOut = r->framesToPreviousBase + 50;
        }
    } else {
        *framesOut = r->framesToPreviousBase + r->framesToPreviousBase + r->framesToNextBase;
    }
    return TRUE;

forced:
    *framesOut = r->framesToNextBase;
    return TRUE;
}

// .text:0x000A8338 size:0x140 mapped:0x806E73CC
void fn_3_A8338(s32 fielder) {
    Unk18E8Fielder* f = &g_Fielders[fielder];

    if (g_FieldingLogic._0CC >= 0 && g_FieldingLogic._0CC <= 3 && f->_1F5 == g_FieldingLogic._0CC) {
        g_FieldingLogic._0CC = -1;
        return;
    }
    if (g_FieldingLogic._0E2 == -1) {
        if (g_FieldingLogic._0DE >= 0 && g_Runners[g_FieldingLogic._0DE].runnerOnFieldOrOutOrScored != 1) {
            g_FieldingLogic._0DE = -1;
            g_FieldingLogic._0CC = -1;
            return;
        }
        g_FieldingLogic._0E2 = g_FieldingLogic._0CC;
        fn_3_A8074(fielder);
    }
    if (g_FieldingLogic._0CC >= 0 && g_FieldingLogic._0CC <= 3) {
        if (g_FieldingLogic._0DE == -1) {
            fn_3_52F4C(g_Ball.fielderWBallIndex, lbl_3_data_4444[g_FieldingLogic._0CC][0],
                       lbl_3_data_4444[g_FieldingLogic._0CC][1]);
        } else {
            fn_3_52F4C(g_Ball.fielderWBallIndex, g_Runners[g_FieldingLogic._0DE].position.x,
                       g_Runners[g_FieldingLogic._0DE].position.z);
        }
    }
    fn_3_A3CC0();
}

// .text:0x000A8074 size:0x2C4 mapped:0x806E7108
void fn_3_A8074(s32 fielder) {
    s32 base = -1;
    Unk18E8Fielder* f = &g_Fielders[fielder];
    BOOL forward = FALSE;
    s32 runner = -1;
    s32 i;
    s32 diff;

    if (g_FieldingLogic._0DC < 0) {
        g_FieldingLogic._0DE = -1;
        return;
    }
    diff = g_FieldingLogic._0CC - g_FieldingLogic._0DC;
    if (diff == 1 || diff == -3) {
        base = g_FieldingLogic._0DC;
    } else if (diff == -1 || diff == 3) {
        base = g_FieldingLogic._0CC;
    }
    if (base >= 0) {
        if (g_FieldingLogic._0CC > g_FieldingLogic._0DC || (g_FieldingLogic._0CC == 0 && g_FieldingLogic._0DC == 3)) {
            forward = TRUE;
        }
        if (forward) {
            for (i = 0; i < 4; i++) {
                if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 && base == g_Runners[i].currentBase &&
                    g_Runners[i].baseStandingOn < 0 && f->_0A8[g_FieldingLogic._0CC] > g_Runners[i].distToNextBase) {
                    runner = i;
                    break;
                }
            }
        } else {
            for (i = 3; i >= 0; i--) {
                if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 && base == g_Runners[i].currentBase &&
                    g_Runners[i].baseStandingOn < 0 && f->_0A8[g_FieldingLogic._0CC] > g_Runners[i].distToCurrentBase) {
                    runner = i;
                    break;
                }
            }
        }
    }
    g_FieldingLogic._0DE = runner;
}

// .text:0x000A7EF8 size:0x17C mapped:0x806E6F8C
void fn_3_A7EF8(void) {
    InputStruct* inputs;
    u8 prev;

    inputs = &g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]];
    if (ACTIVE_TUTORIAL()) {
        inputs = &g_Practice.inputs[g_GameLogic.teamFielding];
    } else if (g_d_GameSettings.minigamesEnabled) {
        inputs = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[g_Minigame._1922]];
    }
    prev = g_FieldingLogic._12E;
    if (inputs->controlStickAngle >= 0xE00) {
        g_FieldingLogic._12E = 2;
    } else if (inputs->controlStickAngle >= 0xA00) {
        g_FieldingLogic._12E = 3;
    } else if (inputs->controlStickAngle >= 0x600) {
        g_FieldingLogic._12E = 4;
    } else if (inputs->controlStickAngle >= 0x200) {
        g_FieldingLogic._12E = 1;
    } else if (inputs->controlStickAngle >= 0) {
        g_FieldingLogic._12E = 2;
    } else {
        g_FieldingLogic._12E = 0;
    }
    if (g_FieldingLogic._12E == 0) {
        g_FieldingLogic._12F = 0;
    } else if (g_FieldingLogic._12E == prev) {
        if (g_FieldingLogic._12F < 0xFE) {
            g_FieldingLogic._12F++;
        } else {
            g_FieldingLogic._12F = 0xFF;
        }
    } else {
        g_FieldingLogic._12F = 1;
    }
}

// .text:0x000A7C88 size:0x270 mapped:0x806E6D1C
void fn_3_A7C88(void) {
    InputStruct* inputs = &g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]];

    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD &&
        !g_GameLogic.autoFielding[g_GameLogic.awayTeamBattingInd_battingTeam]) {
        if (ACTIVE_TUTORIAL()) {
            inputs = &g_Practice.inputs[g_GameLogic.teamFielding];
        } else if (g_d_GameSettings.minigamesEnabled) {
            inputs = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[g_Minigame._1922]];
        }
        if (!(inputs->buttonInput & 0x100)) {
            g_FieldingLogic._145 = 0;
        }
        if (g_FieldingLogic._145) {
            if (g_FieldingLogic._145 < 0xFE) {
                g_FieldingLogic._145++;
            } else {
                g_FieldingLogic._145 = 0xFF;
            }
        }
        if (!(inputs->buttonInput & 0x100)) {
            return;
        }
        if (inputs->newButtonInput & 0x100) {
            if (inputs->buttonInput & 0x40) {
                g_FieldingLogic._0C6 = 6;
            } else if (inputs->controlStickAngle >= 0xE00) {
                g_FieldingLogic._0C6 = 1;
            } else if (inputs->controlStickAngle >= 0xA00) {
                g_FieldingLogic._0C6 = 0;
            } else if (inputs->controlStickAngle >= 0x600) {
                g_FieldingLogic._0C6 = 3;
            } else if (inputs->controlStickAngle >= 0x200) {
                g_FieldingLogic._0C6 = 2;
            } else if (inputs->controlStickAngle >= 0) {
                g_FieldingLogic._0C6 = 1;
            } else {
                g_FieldingLogic._145 = 1;
            }
        } else if (g_FieldingLogic._145 >= lbl_3_data_49DC[40]) {
            if (g_FieldingLogic._0C2 >= 0) {
                return;
            }
            g_FieldingLogic._0C6 = 8;
        }
        g_FieldingLogic._0C8 = 0;
        if (g_FieldingLogic._0C6 == 8) {
            g_FieldingLogic._12D = 1;
        } else if (g_FieldingLogic._12F <= lbl_3_data_475C && !g_d_GameSettings.minigamesEnabled) {
            g_FieldingLogic._12D = 0;
        } else {
            g_FieldingLogic._12D = 1;
        }
    }
}

// .text:0x000A76B4 size:0x5D4 mapped:0x806E6748
void fn_3_A76B4(void) {
    return;
}

// .text:0x000A7040 size:0x674 mapped:0x806E60D4
// 98.49%: before testing distanceFromBall - f->_050 < 1.8f, the target also compares
// f->_050 + f->_05C with f->_058 and discards the result; no plausible source found for that.
void fn_3_A7040(s32 fielder) {
    Unk18E8Fielder* f;
    s32 base;
    s32 i;
    InMemRunnerType* r;

    f = &g_Fielders[fielder];
    g_FieldingLogic._111 = 0;
    base = -1;
    g_FieldingLogic._0E8 = -1;
    if (g_Strikes.outs < 3 && g_Ball.ballState == 1 && g_Ball.fielderWBallIndex >= 0 && g_FieldingLogic._124 == 0) {
        if (f->_1F5 >= 0) {
            base = f->_1F5;
        }
        for (i = 0; i < 4; i++) {
            if (f->_0A8[i] <= 0.8f) {
                base = i;
                break;
            }
        }
        if (base >= 0) {
            for (i = 3; i >= 0; i--) {
                r = &g_Runners[i];
                if ((g_Pitcher.strikeOutOrWalk != 2 || r->furthestBaseForcedToGoToOnWalk <= r->currentBase) &&
                    r->runnerOnFieldOrOutOrScored == 1) {
                    if (base == r->baseStandingOn_Stored && r->baseStandingOn < 0 && g_Ball.timeSinceBallPickedUp > 15 &&
                        r->position.x < 20.0f) {
                        g_FieldingLogic._111 = 5;
                        g_FieldingLogic._0E8 = i;
                        g_FieldingLogic._112 = 1;
                        g_FieldingLogic._0EC = 1;
                        g_FieldingLogic._124 = 15;
                        g_FieldingLogic._135 = 1;
                        goto found;
                    }
                    if (base == r->baseRunningTowards) {
                        if ((r->forceOutCd == 1 && r->nextBase == base) || r->forceOutType_unsed != 0) {
                            break;
                        }
                        if (r->actionCode != 0) {
                            if (r->actionFrames_countDown < 6) {
                                g_FieldingLogic._111 = 1;
                                g_FieldingLogic._0E8 = i;
                                g_FieldingLogic._112 = 1;
                                g_FieldingLogic._124 = 15;
                                g_FieldingLogic._125 = base;
                                g_FieldingLogic._135 = 1;
                                if (g_FieldingLogic._0DE >= 0) {
                                    g_FieldingLogic._0DE = i;
                                }
                                goto found;
                            }
                        } else if (r->tagUpInd == 2 && r->distanceFromBall < 1.8f && g_Ball.timeSinceBallPickedUp > 15) {
                            if (r->baseStandingOn == base && i != r->baseStandingOn) {
                                g_FieldingLogic._111 = 5;
                            } else {
                                g_FieldingLogic._111 = 2;
                            }
                            g_FieldingLogic._0E8 = i;
                            g_FieldingLogic._112 = 1;
                            g_FieldingLogic._0EC = 1;
                            g_FieldingLogic._124 = 15;
                            g_FieldingLogic._135 = 1;
                            goto found;
                        }
                    }
                }
            }
        }
        if (g_Ball.timeSinceBallPickedUp > 15) {
            for (i = 3; i >= 0; i--) {
                r = &g_Runners[i];
                if (r->runnerOnFieldOrOutOrScored == 1 && (f->_18C < 0 || r->forceOutCd != 1 || r->nextBase != base)) {
                    f32 runAngle = game_atan2(r->velocity.x, r->velocity.z);
                    if (fn_3_9FC1C(game_atan2(f->_000 - r->position.x, f->_008 - r->position.z), runAngle) < 0x100 &&
                        r->baseStandingOn < 0) {
                        if ((r->baseStandingOn < 0 || r->tagUpInd == 2) &&
                            r->distanceFromBall - f->_050 < 1.8f) {
                            g_FieldingLogic._111 = 2;
                            g_FieldingLogic._0E8 = i;
                            g_FieldingLogic._112 = 1;
                            g_FieldingLogic._0EC = 1;
                            g_FieldingLogic._124 = 15;
                            g_FieldingLogic._135 = 1;
                            if (g_FieldingLogic._0DE >= 0) {
                                g_FieldingLogic._0DE = i;
                            }
                            goto found;
                        }
                    } else {
                        f32 dist = r->distanceFromBall;
                        BOOL close = FALSE;
                        s32 action;

                        if (dist < 5.0f) {
                            if (r->baseStandingOn < 0) {
                                close = TRUE;
                            } else {
                                if (r->runningDirectionCode == 1 && r->distToCurrentBase > 2.5f) {
                                    close = TRUE;
                                }
                                if (r->forceOutCd == 1 && r->baseStandingOn == r->startingBase_baseAchieved) {
                                    close = TRUE;
                                }
                            }
                        }
                        if (close) {
                            action = 0;
                            if (r->forceOutCd == 1 && r->baseStandingOn == r->startingBase_baseAchieved && dist < 1.8f) {
                                action = 2;
                            } else if ((g_FieldingLogic._0CC < 0 || g_FieldingLogic._0CC > 3 ||
                                        (!(f->_0A8[g_FieldingLogic._0CC] < 1.5f) &&
                                         (!(f->_0A8[g_FieldingLogic._0CC] < 5.0f) ||
                                          (r->forceOutCd == 0 && r->tagUpInd != 2)))) &&
                                       dist < 1.8f) {
                                action = 1;
                            }
                            if (action) {
                                g_FieldingLogic._111 = 2;
                                g_FieldingLogic._0E8 = i;
                                g_FieldingLogic._112 = 1;
                                g_FieldingLogic._0EC = 1;
                                g_FieldingLogic._124 = 15;
                                g_FieldingLogic._135 = 1;
                                if (g_FieldingLogic._0DE >= 0) {
                                    g_FieldingLogic._0DE = i;
                                }
                                goto found;
                            }
                        }
                    }
                }
            }
        }
        if (g_FieldingLogic._111 == 2 && f->_050 == 0.0f) {
            g_FieldingLogic._111 = 5;
        }
    }
    return;

found:
    if (g_Runners[g_FieldingLogic._0E8].actionCode != 0) {
        if (g_Runners[g_FieldingLogic._0E8].runningDirectionCode == 1) {
            g_FieldingLogic._090.x = lbl_3_data_4444[g_Runners[g_FieldingLogic._0E8].currentBase][0];
            g_FieldingLogic._090.y = 0.0f;
            g_FieldingLogic._090.z = lbl_3_data_4444[g_Runners[g_FieldingLogic._0E8].currentBase][1];
        } else {
            g_FieldingLogic._090.x = lbl_3_data_4444[g_Runners[g_FieldingLogic._0E8].nextBase][0];
            g_FieldingLogic._090.y = 0.0f;
            g_FieldingLogic._090.z = lbl_3_data_4444[g_Runners[g_FieldingLogic._0E8].nextBase][1];
        }
    } else {
        g_FieldingLogic._090.x = g_Runners[g_FieldingLogic._0E8].position.x;
        g_FieldingLogic._090.y = g_Runners[g_FieldingLogic._0E8].position.y;
        g_FieldingLogic._090.z = g_Runners[g_FieldingLogic._0E8].position.z;
    }
}

// .text:0x000A6E98 size:0x1A8 mapped:0x806E5F2C
void fn_3_A6E98(s32 fielder) {
    if (g_FieldingLogic._0EC > 0) {
        g_FieldingLogic._0EC--;
    }
    if (g_FieldingLogic._125 >= 0) {
        g_Ball.baseBallAndFielderAreOn = g_FieldingLogic._125;
        if (g_FieldingLogic._0CC == g_FieldingLogic._125) {
            g_FieldingLogic._0CC = -1;
        }
    }
    if (g_FieldingLogic._0EC <= 0) {
        g_FieldingLogic._112 = 2;
    }
    if (g_FieldingLogic._111 == 2 && g_FieldingLogic._112 == 1) {
        fn_3_52F4C(fielder, g_Runners[g_FieldingLogic._0E8].position.x, g_Runners[g_FieldingLogic._0E8].position.z);
        if (g_FieldingLogic._0CC == 9) {
            g_FieldingLogic._0DE = g_FieldingLogic._0E8;
        }
        fn_3_A3CC0();
    } else if (g_FieldingLogic._111 == 1) {
        if (g_FieldingLogic._0E8 >= 0) {
            InMemRunnerType* r = &g_Runners[g_FieldingLogic._0E8];
            if (r->runnerOnFieldOrOutOrScored == 1) {
                if (r->baseStandingOn >= 0) {
                    g_FieldingLogic._111 = 0;
                } else if (r->actionCode == 0 && (r->runningDirectionCode == 1 || r->runningDirectionCode == 3)) {
                    g_FieldingLogic._111 = 0;
                }
            } else {
                g_FieldingLogic._111 = 0;
            }
        } else {
            g_FieldingLogic._111 = 0;
        }
        if (g_FieldingLogic._0DE >= 0) {
            g_FieldingLogic._0DE = -1;
            g_FieldingLogic._0CC = -1;
        }
    }
}

// .text:0x000A6D48 size:0x150 mapped:0x806E5DDC
void fn_3_A6D48(void) {
    s32 i;

    lbl_3_bss_1824 = 0;
    lbl_3_bss_1808[0] = -1;
    lbl_3_bss_1808[1] = -1;
    lbl_3_bss_1808[2] = -1;
    lbl_3_bss_1808[3] = -1;
    for (i = 3; i >= 0; i--) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            InMemRunnerType* r = &g_Runners[i];
            lbl_3_bss_1824 |= 1 << ((s32)r->fractionalBasesRan * 4);
            if (lbl_3_bss_1808[r->currentBase] < 0 || g_Runners[lbl_3_bss_1808[r->currentBase]].baseStandingOn >= 0) {
                lbl_3_bss_1808[r->currentBase] = i;
            }
        }
    }
}

// .text:0x000A6ABC size:0x28C mapped:0x806E5B50
int fn_3_A6ABC(f32 x, f32 z) {
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];
    f32 speed = f->_1CD / 200.0f;
    f32 dist = dolsqrtf2(SQ(x - f->_000) + SQ(z - f->_008));
    f32 div = speed == 0.0f ? 1.0f : speed;
    s32 frames;

    if (dist > 60.0f) {
        frames = 1.15f * dist / div;
    } else if (dist > 30.0f) {
        frames = dist / div;
    } else {
        frames = 0.8f * dist / div;
    }
    if (dist > 80.0f) {
        frames *= 1.3f;
        frames += 30;
    } else if (dist > 70.0f) {
        frames *= 1.15f;
        frames += 30;
    }
    return frames;
}

// .text:0x000A6810 size:0x2AC mapped:0x806E58A4
s32 fn_3_A6810(f32 x0, f32 z0, f32 x1, f32 z1) {
    f32 speed = lbl_3_data_4744[10] / 400.0f;
    f32 dist = dolsqrtf2(SQ(x1 - x0) + SQ(z1 - z0));
    f32 div;
    s32 frames;

    if (speed == 0.0f) {
        div = 1.0f;
    } else {
        div = speed;
    }
    frames = dist / div;
    if (dist > 80.0f) {
        frames *= 1.4f;
        frames += 30;
    } else if (dist > 70.0f) {
        frames *= 1.3f;
        frames += 30;
    } else if (dist > 60.0f) {
        frames *= 1.2f;
        frames += 30;
    } else if (dist > 50.0f) {
        frames *= 1.1f;
    }
    return frames;
}

// .text:0x000A67E8 size:0x28 mapped:0x806E587C
void fn_3_A67E8(s32 idx) {
    lbl_3_bss_1838[idx] = 9;
    lbl_3_bss_1828[idx] = -1;
}

// .text:0x000A63E4 size:0x404 mapped:0x806E5478
// 95.47%: registers only. The inlined fn_3_A6ABC keeps its speed in f4 where the target
// uses f7, which shifts its other FPRs; statement and declaration orders change nothing.
s32 fn_3_A63E4(s32 runner, s32 toNext, s32* out0, s32* out1) {
    InMemRunnerType* r = &g_Runners[runner];
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];
    s32 runnerFrames;
    s32 arrival;
    s32 base;
    s16 coverer;
    s32 fielderFrames;
    f32 ballDist;

    if (toNext == 0) {
        runnerFrames = r->framesToPreviousBase;
        base = r->currentBase;
    } else {
        runnerFrames = r->framesToNextBase;
        base = r->nextBase;
    }
    coverer = g_FieldingLogic._0D0[base];
    fielderFrames = fn_3_A6ABC(lbl_3_data_4444[base][0], lbl_3_data_4444[base][1]);
    ballDist = g_Ball.ballDistanceFromBase[base];
    arrival = f->_192 + fielderFrames;
    if (ballDist > 60.0f && ballDist < 70.0f && (base == 0 || base == 3)) {
        arrival -= 45;
    }
    fielderFrames = fn_3_52560(g_Ball.fielderWBallIndex);
    if (coverer == g_Ball.fielderWBallIndex || coverer == -1 || ballDist < 3.0f) {
        *out0 = -1;
        *out1 = base;
        return fielderFrames - runnerFrames;
    }
    if (fielderFrames < g_Fielders[coverer]._17E + 5) {
        *out0 = -1;
        *out1 = base;
        return fielderFrames - runnerFrames;
    }
    if (arrival < g_Fielders[coverer]._17E) {
        *out0 = base + 10;
        *out1 = -1;
        return g_Fielders[coverer]._17E - runnerFrames;
    }
    *out0 = base;
    *out1 = -1;
    return arrival - runnerFrames;
}

// .text:0x000A5B4C size:0x898 mapped:0x806E4BE0
void fn_3_A5B4C(s32 runner) {
    InMemRunnerType* r = &g_Runners[runner];
    s32 cur = r->currentBase;
    s32 next = r->nextBase;
    f32 toNext;
    f32 toCur;
    f32 ballToNext = g_Ball.ballDistanceFromBase[next];
    f32 ballToCur = g_Ball.ballDistanceFromBase[cur];
    s32 dir = 0;
    s32 ballDist;
    s32 cover;
    s32 frames;
    s32 base;

    toNext = r->distToNextBase;
    toCur = r->distToCurrentBase;
    ballDist = r->distanceFromBall;
    if (ballToNext + ballToCur < 32.0f && r->actionCode == 0) {
        lbl_3_bss_17FC[runner] = 1;
        if (ballToNext < toNext) {
            dir = 1;
        } else if (ballToCur < toCur) {
            dir = -1;
        }
        if (r->runningDirectionCode == 1) {
            if (r->restrictedMovementCodes & 1) {
                lbl_3_bss_1838[runner] = 9;
                lbl_3_bss_1828[runner] = -1;
                lbl_3_bss_1848[runner] = 0;
            } else if (dir == 1) {
                if (g_Ball.baseBallAndFielderAreOn == next &&
                    ((toNext < 7.0f && r->runningDirectionCode == 1 && r->nextDirectionBeingProcessed == 0) ||
                     r->actionCode != 0)) {
                    lbl_3_bss_1848[runner] = -50;
                    lbl_3_bss_1838[runner] = next;
                    lbl_3_bss_1828[runner] = -1;
                } else {
                    lbl_3_bss_1838[runner] = 9;
                    lbl_3_bss_1828[runner] = -1;
                    lbl_3_bss_1848[runner] = -15;
                }
            } else {
                frames = fn_3_A63E4(runner, 1, &cover, &base) - 10;
                if (g_Ball.numberOfThrowsDuringPlay <= 3 && g_FieldingLogic._0CC == -1 && frames >= -45) {
                    lbl_3_bss_1848[runner] = frames;
                    lbl_3_bss_1828[runner] = cover;
                    lbl_3_bss_1838[runner] = base;
                } else if (r->percentTowardsNextBase > 0.6f || frames >= -15) {
                    lbl_3_bss_1848[runner] = frames;
                    lbl_3_bss_1828[runner] = cover;
                    lbl_3_bss_1838[runner] = base;
                } else {
                    lbl_3_bss_1838[runner] = 9;
                    lbl_3_bss_1828[runner] = -1;
                    lbl_3_bss_1848[runner] = 0;
                }
            }
        } else if (r->runningDirectionCode == 3) {
            if (r->restrictedMovementCodes & 2) {
                lbl_3_bss_1838[runner] = 9;
                lbl_3_bss_1828[runner] = -1;
                lbl_3_bss_1848[runner] = 0;
            } else if (dir == -1) {
                if (g_Ball.baseBallAndFielderAreOn == cur && toCur < 7.0f && r->runningDirectionCode == 3 &&
                    r->nextDirectionBeingProcessed == 0) {
                    lbl_3_bss_1848[runner] = -50;
                    lbl_3_bss_1838[runner] = cur;
                    lbl_3_bss_1828[runner] = -1;
                } else {
                    lbl_3_bss_1838[runner] = 9;
                    lbl_3_bss_1828[runner] = -1;
                    lbl_3_bss_1848[runner] = -15;
                }
            } else {
                frames = fn_3_A63E4(runner, 0, &cover, &base) - 10;
                if (r->percentTowardsNextBase < 0.2f || frames >= -8) {
                    lbl_3_bss_1848[runner] = frames;
                    lbl_3_bss_1828[runner] = cover;
                    lbl_3_bss_1838[runner] = base;
                } else if (r->percentTowardsNextBase < 0.3f && frames >= -8 &&
                           (r->nextDirectionBeingProcessed == 0 || r->runningDirectionCode != 2)) {
                    lbl_3_bss_1848[runner] = frames;
                    lbl_3_bss_1828[runner] = cover;
                    lbl_3_bss_1838[runner] = base;
                } else {
                    lbl_3_bss_1838[runner] = 9;
                    lbl_3_bss_1828[runner] = -1;
                    lbl_3_bss_1848[runner] = 0;
                }
            }
        } else {
            lbl_3_bss_1838[runner] = 9;
            lbl_3_bss_1828[runner] = -1;
            lbl_3_bss_1848[runner] = 0;
        }
    } else if (r->runningDirectionCode == 1) {
        if (r->percentTowardsNextBase < 0.25f) {
            if (ballToNext < 10.0f) {
                lbl_3_bss_1838[runner] = 9;
                lbl_3_bss_1828[runner] = -1;
                lbl_3_bss_1848[runner] = -15;
                return;
            }
            if (ballToCur < 10.0f) {
                if (ballDist > 5.0f) {
                    lbl_3_bss_1848[runner] = fn_3_A63E4(runner, 0, &cover, &base);
                    lbl_3_bss_1828[runner] = cover;
                    lbl_3_bss_1838[runner] = base;
                }
                return;
            }
        }
        frames = fn_3_A63E4(runner, 1, &cover, &base);
        frames += lbl_3_data_1C40;
        if (frames < -45) {
            if (ballDist < 15.0f) {
                lbl_3_bss_1838[runner] = 9;
                lbl_3_bss_1828[runner] = -1;
                lbl_3_bss_1848[runner] = -15;
            } else if (ballToNext > 10.0f) {
                lbl_3_bss_1848[runner] = frames;
                lbl_3_bss_1828[runner] = cover;
                lbl_3_bss_1838[runner] = base;
            } else if (ballToNext < toNext) {
                lbl_3_bss_1838[runner] = 9;
                lbl_3_bss_1828[runner] = -1;
                lbl_3_bss_1848[runner] = -30;
            } else {
                lbl_3_bss_1848[runner] = frames;
                lbl_3_bss_1828[runner] = cover;
                lbl_3_bss_1838[runner] = base;
            }
        } else {
            lbl_3_bss_1848[runner] = frames;
            lbl_3_bss_1828[runner] = cover;
            lbl_3_bss_1838[runner] = base;
        }
    } else if (r->runningDirectionCode == 3) {
        frames = fn_3_A63E4(runner, 0, &cover, &base);
        frames += lbl_3_data_1C40;
        if (frames < -30) {
            if (ballToCur > 10.0f) {
                lbl_3_bss_1848[runner] = frames;
                lbl_3_bss_1828[runner] = cover;
                lbl_3_bss_1838[runner] = base;
            } else if (ballToCur < toCur) {
                lbl_3_bss_1838[runner] = 9;
                lbl_3_bss_1828[runner] = -1;
                lbl_3_bss_1848[runner] = -30;
            } else {
                lbl_3_bss_1848[runner] = frames;
                lbl_3_bss_1828[runner] = cover;
                lbl_3_bss_1838[runner] = base;
            }
        } else if (r->percentTowardsNextBase >= 0.45f) {
            lbl_3_bss_1848[runner] = frames;
            lbl_3_bss_1828[runner] = cover;
            lbl_3_bss_1838[runner] = base;
        } else {
            lbl_3_bss_1848[runner] = frames;
            lbl_3_bss_1828[runner] = cover;
            lbl_3_bss_1838[runner] = base;
        }
    } else if (r->runningDirectionCode == 2) {
        if (r->baseStandingOn < 0) {
            if (ballToNext < 10.0f) {
                lbl_3_bss_1838[runner] = 9;
                lbl_3_bss_1828[runner] = -1;
                lbl_3_bss_1848[runner] = -15;
            } else {
                frames = fn_3_A63E4(runner, 1, &cover, &base);
                frames += lbl_3_data_1C40;
                lbl_3_bss_1828[runner] = cover;
                lbl_3_bss_1848[runner] = frames;
                lbl_3_bss_1838[runner] = base;
            }
        }
    }
}

// .text:0x000A5704 size:0x448 mapped:0x806E4798
// 91.78%: like fn_3_A63E4, the inlined fn_3_A6ABC allocates its FPRs differently
// (the target keeps the speed in f7 and loads the target point into f1/f2).
void fn_3_A5704(s32 runner) {
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];
    InMemRunnerType* r = &g_Runners[runner];
    s32 base = r->nextBase;
    s32 runnerFrames = r->framesToNextBase;
    s16 coverer = g_FieldingLogic._0D0[base];
    s32 arrival;
    f32 ballDist;
    s32 frames;

    {
        f32 x = lbl_3_data_4444[base][0];
        f32 z = lbl_3_data_4444[base][1];
        arrival = f->_192 + fn_3_A6ABC(x, z) + lbl_3_data_1C40;
    }
    ballDist = g_Ball.ballDistanceFromBase[base];
    frames = fn_3_52560(g_Ball.fielderWBallIndex);
    if (coverer == g_Ball.fielderWBallIndex || coverer == -1 || ballDist < 3.0f || g_Fielders[coverer]._1E2 ||
        (g_Fielders[coverer]._17E < 0 && g_FieldingLogic._101[base] == 0)) {
        lbl_3_bss_1838[runner] = base;
        lbl_3_bss_1828[runner] = -1;
        lbl_3_bss_1848[runner] = frames - runnerFrames;
        return;
    }
    if (frames < g_Fielders[coverer]._17E + 5) {
        lbl_3_bss_1838[runner] = base;
        lbl_3_bss_1828[runner] = -1;
        lbl_3_bss_1848[runner] = frames - runnerFrames;
        return;
    }
    if (arrival + 5 < g_Fielders[coverer]._17E) {
        lbl_3_bss_1828[runner] = base + 10;
        lbl_3_bss_1838[runner] = -1;
        lbl_3_bss_1848[runner] = g_Fielders[coverer]._17E - runnerFrames;
        return;
    }
    lbl_3_bss_1828[runner] = base;
    lbl_3_bss_1838[runner] = -1;
    lbl_3_bss_1848[runner] = arrival - runnerFrames;
}

// .text:0x000A53DC size:0x328 mapped:0x806E4470
// 97.46%: the tail schedules the framesToNextBase load and the 0 and -1 constants
// differently (registers and order only); several statement orders tried.
void fn_3_A53DC(s32 runner) {
    InMemRunnerType* r = &g_Runners[runner];
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];

    if (runner == 3 && r->baseStandingOn == 3 && g_RunningLogic._00 == 0x1000 && g_Ball.ballZoneAwayFromHome >= 4 &&
        g_Ball.AtBat_ContactResult == 3) {
        s32 frames = f->_192 + fn_3_A6ABC(lbl_3_data_4444[0][0], lbl_3_data_4444[0][1]);
        frames += lbl_3_data_1C40;
        frames -= r->framesToNextBase;
        lbl_3_bss_1828[runner] = 0;
        lbl_3_bss_1838[runner] = -1;
        lbl_3_bss_1848[runner] = frames;
    }
}

// .text:0x000A4F50 size:0x48C mapped:0x806E3FE4
// 89.83%: the inlined fn_3_A6ABC allocates its FPRs differently, as in fn_3_A63E4.
void fn_3_A4F50(s32 runner) {
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];
    InMemRunnerType* r = &g_Runners[runner];
    s32 base = r->startingBase_baseAchieved;
    s16 coverer = g_FieldingLogic._0D0[base];
    s32 arrival;
    f32 ballDist;
    s32 frames;
    s32 runnerFrames;

    arrival = f->_192 + (fn_3_A6ABC(lbl_3_data_4444[base][0], lbl_3_data_4444[base][1]) + 20) + lbl_3_data_1C40;
    ballDist = g_Ball.ballDistanceFromBase[base];
    frames = fn_3_52560(g_Ball.fielderWBallIndex);
    if (r->currentBase == r->startingBase_baseAchieved) {
        runnerFrames = r->framesToPreviousBase;
    } else {
        runnerFrames = r->framesToPreviousBase + 180;
    }
    if (coverer == g_Ball.fielderWBallIndex || coverer == -1 || ballDist < 4.0f ||
        (g_Fielders[coverer]._17E < 0 && g_FieldingLogic._101[base] == 0) || g_Ball.framesSinceHit < 70) {
        lbl_3_bss_1838[runner] = base;
        lbl_3_bss_1828[runner] = -1;
        lbl_3_bss_1848[runner] = frames - runnerFrames;
        return;
    }
    if (frames < g_Fielders[coverer]._17E + 5) {
        lbl_3_bss_1838[runner] = base;
        lbl_3_bss_1828[runner] = -1;
        lbl_3_bss_1848[runner] = frames - runnerFrames;
        return;
    }
    if (arrival < g_Fielders[coverer]._17E ||
        (g_Fielders[coverer]._17E < 0 && g_Fielders[coverer]._1D2 <= g_Ball.framesSinceHit)) {
        lbl_3_bss_1828[runner] = base + 10;
        lbl_3_bss_1838[runner] = -1;
        lbl_3_bss_1848[runner] = g_Fielders[coverer]._17E - runnerFrames;
        return;
    }
    lbl_3_bss_1828[runner] = base;
    lbl_3_bss_1838[runner] = -1;
    lbl_3_bss_1848[runner] = arrival - runnerFrames;
}

// .text:0x000A4A10 size:0x540 mapped:0x806E3AA4
// 99.24%: only the inlined fn_3_A53DC tail differs, with the same residue as fn_3_A53DC.
void fn_3_A4A10(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        lbl_3_bss_1848[i] = 0;
        lbl_3_bss_1838[i] = -1;
        lbl_3_bss_1828[i] = -1;
        lbl_3_bss_17FC[i] = 0;
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            if (g_Runners[i].tagUpInd == 2) {
                fn_3_A4F50(i);
            } else if (g_Runners[i].baseStandingOn != -1 && g_Runners[i].forceOutCd <= 0) {
                fn_3_A53DC(i);
            } else if (g_Runners[i].overrunBaseStage == 0) {
                if (g_Runners[i].forceOutCd == 1) {
                    fn_3_A5704(i);
                } else {
                    fn_3_A5B4C(i);
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        lbl_3_bss_1858[i] = 9;
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 &&
            (g_Runners[i].baseStandingOn == -1 || g_Runners[i].tagUpInd == 2 || g_Runners[i].forceOutCd > 0 ||
             lbl_3_bss_1828[i] == 0)) {
            if (lbl_3_bss_1848[i] >= 90) {
                lbl_3_bss_1858[i] = 8;
            } else if (lbl_3_bss_1848[i] >= 30) {
                lbl_3_bss_1858[i] = 7;
            } else if (lbl_3_bss_1848[i] >= 15) {
                lbl_3_bss_1858[i] = 6;
            } else if (lbl_3_bss_1848[i] >= 8) {
                lbl_3_bss_1858[i] = 5;
            } else if (lbl_3_bss_1848[i] >= -8) {
                lbl_3_bss_1858[i] = 4;
            } else if (lbl_3_bss_1848[i] >= -15) {
                lbl_3_bss_1858[i] = 3;
            } else if (lbl_3_bss_1848[i] >= -30) {
                lbl_3_bss_1858[i] = 2;
            } else if (lbl_3_bss_1848[i] >= -45) {
                lbl_3_bss_1858[i] = 1;
            } else {
                lbl_3_bss_1858[i] = 0;
            }
            if (g_FieldingLogic._107 == 2) {
                lbl_3_bss_1858[i] -= 2;
                if (lbl_3_bss_1858[i] < 2) {
                    lbl_3_bss_1858[i] = 0;
                } else {
                    lbl_3_bss_1858[i] -= 2;
                }
            }
        }
    }
}

// .text:0x000A46A0 size:0x370 mapped:0x806E3734
BOOL fn_3_A46A0(s32 runner) {
    InMemRunnerType* r = &g_Runners[runner];
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];

    if (runner < 0) {
        g_FieldingLogic._0CC = -1;
        g_FieldingLogic._0C4 = -1;
        return FALSE;
    }
    if (runner == 0 && r->currentBase == 0 && f->_1ED == 0 && fn_3_A36BC()) {
        g_FieldingLogic._0CC = 9;
        g_FieldingLogic._0DE = runner;
        g_FieldingLogic._0C4 = -1;
        fn_3_52F4C(g_Ball.fielderWBallIndex, r->position.x, r->position.z);
        return TRUE;
    }
    if (lbl_3_bss_1838[runner] >= 0) {
        if (f->_1ED) {
            g_FieldingLogic._0CC = -1;
            g_FieldingLogic._0DE = -1;
            return TRUE;
        }
        if (g_FieldingLogic._0CC != lbl_3_bss_1838[runner]) {
            g_FieldingLogic._0CC = lbl_3_bss_1838[runner];
            if (g_FieldingLogic._0CC == 9) {
                if (g_FieldingLogic._130 && !g_GameLogic.autoFielding[g_GameLogic.awayTeamBattingInd_battingTeam]) {
                    g_FieldingLogic._0CC = -1;
                } else {
                    g_FieldingLogic._0DE = runner;
                }
            }
            if (g_FieldingLogic._0CC != 9) {
                fn_3_52F4C(g_Ball.fielderWBallIndex, lbl_3_data_4444[g_FieldingLogic._0CC][0],
                           lbl_3_data_4444[g_FieldingLogic._0CC][1]);
            }
        }
        if (g_FieldingLogic._0CC == 9) {
            fn_3_A4158(runner);
        }
    } else {
        g_FieldingLogic._0CC = -1;
        g_FieldingLogic._0DE = -1;
    }
    if (lbl_3_bss_1828[runner] >= 10) {
        g_FieldingLogic._0C4 = -1;
        return TRUE;
    }
    g_FieldingLogic._0C4 = lbl_3_bss_1828[runner];
    g_FieldingLogic._12D = 1;
    if (lbl_3_bss_1858[runner] >= 4) {
        s32 chance = lbl_3_data_1C38[0] + (s32)((lbl_3_data_1C38[1] - lbl_3_data_1C38[0]) *
                                                g_AiLogic.aIDifficultyMultiplierArray[g_GameLogic.awayTeamBattingInd_battingTeam]);
        if (chance < RandomInt_Game(100)) {
            g_FieldingLogic._12D = 0;
        }
    }
    if (g_FieldingLogic._0C4 == -1 && g_FieldingLogic._0CC == -1) {
        return FALSE;
    }
    return TRUE;
}

// .text:0x000A41E8 size:0x4B8 mapped:0x806E327C
// 95.38%: the inlined fn_3_A6ABC allocates its FPRs differently, as in fn_3_A63E4.
void fn_3_A41E8(s32 base) {
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];
    s16 coverer = g_FieldingLogic._0D0[base];
    s32 arrival;
    f32 ballDist;
    s32 frames;

    if (base == 5) {
        if (fn_3_AABF8()) {
            g_FieldingLogic._0CC = -1;
            g_FieldingLogic._0C4 = 5;
        } else if (g_Ball.ballZoneAwayFromHome >= 3 && g_FieldingLogic._0BE >= 0 &&
                   g_FieldingLogic._0BE != g_Ball.fielderWBallIndex) {
            g_FieldingLogic._0CC = -1;
            g_FieldingLogic._0C4 = 6;
        } else {
            g_FieldingLogic._0CC = -1;
            g_FieldingLogic._0C4 = -1;
        }
        return;
    }
    arrival = f->_192 + fn_3_A6ABC(lbl_3_data_4444[base][0], lbl_3_data_4444[base][1]);
    ballDist = g_Ball.ballDistanceFromBase[base];
    frames = fn_3_52560(g_Ball.fielderWBallIndex);
    if (coverer == g_Ball.fielderWBallIndex || coverer == -1 || ballDist < 3.0f) {
        g_FieldingLogic._0CC = base;
        g_FieldingLogic._0C4 = -1;
    } else if (frames < g_Fielders[coverer]._17E + 5) {
        g_FieldingLogic._0CC = base;
        g_FieldingLogic._0C4 = -1;
    } else if (arrival < g_Fielders[coverer]._17E) {
        g_FieldingLogic._0CC = base;
        g_FieldingLogic._0C4 = -1;
    } else {
        g_FieldingLogic._0CC = -1;
        g_FieldingLogic._0C4 = base;
    }
}

// .text:0x000A4158 size:0x90 mapped:0x806E31EC
void fn_3_A4158(s32 runner) {
    InMemRunnerType* r = &g_Runners[runner];

    if (r->runningDirectionCode == 2) {
        fn_3_52F4C(g_Ball.fielderWBallIndex, r->position.x, r->position.z);
    } else {
        fn_3_52F4C(g_Ball.fielderWBallIndex, r->position.x + 2.0f * (r->velocity.x * r->distanceFromBall),
                   r->position.z + 2.0f * (r->velocity.y * r->distanceFromBall));
    }
}

// .text:0x000A3CC0 size:0x498 mapped:0x806E2D54
void fn_3_A3CC0(void) {
    s16 fielder = g_Ball.fielderWBallIndex;
    Unk18E8Fielder* f = &g_Fielders[fielder];
    s32 i;
    s32 other;

    if (f->_1D7 == 1) {
        s16 base = f->_18C;
        if (g_FieldingLogic._0CC != base) {
            f->_18C = -1;
            g_FieldingLogic._0D0[base] = -1;
            g_FieldingLogic._101[base] = 0;
            f->_1D7 = 0;
        }
    }
    g_FieldingLogic._11D = 0;
    if (g_FieldingLogic._0CC >= 0 && g_FieldingLogic._0CC <= 3) {
        if (g_FieldingLogic._0D0[g_FieldingLogic._0CC] != fielder && f->_0A8[g_FieldingLogic._0CC] < 3.0f) {
            other = g_FieldingLogic._0D0[g_FieldingLogic._0CC];
            if (other >= 0) {
                fn_3_5985C(other, 9);
                g_Fielders[other]._18C = -1;
            }
            f->_18C = g_FieldingLogic._0CC;
            f->_1D7 = 1;
            g_FieldingLogic._0D0[f->_18C] = fielder;
        }
        if (f->_18C >= 0) {
            if (f->_068 < lbl_3_data_4780[f->_1C9]) {
                g_FieldingLogic._101[f->_18C] = 1;
            } else {
                g_FieldingLogic._101[f->_18C] = 0;
            }
        }
        g_FieldingLogic._11D = 1;
        for (i = 0; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
                if (g_Runners[i].forceOutCd == 1 && g_FieldingLogic._0CC == g_Runners[i].nextBase) {
                    g_FieldingLogic._11D = 2;
                    break;
                }
                if (g_Runners[i].tagUpInd == 2 && g_FieldingLogic._0CC == i) {
                    g_FieldingLogic._11D = 2;
                    break;
                }
            }
        }
    }
    if (g_FieldingLogic._0CC == 9) {
        s16 base;
        fn_3_A4158(g_FieldingLogic._0DE);
        base = g_Runners[g_FieldingLogic._0DE].baseStandingOn;
        if (base >= 0) {
            if (f->_0A8[g_FieldingLogic._0CC] < 3.0f) {
                other = g_FieldingLogic._0D0[base];
                if (other >= 0) {
                    fn_3_5985C(other, 9);
                    g_Fielders[other]._18C = -1;
                }
                f->_18C = base;
                f->_1D7 = 1;
                g_FieldingLogic._0D0[f->_18C] = fielder;
            }
            if (f->_18C >= 0) {
                if (f->_068 < lbl_3_data_4780[f->_1C9]) {
                    g_FieldingLogic._101[f->_18C] = 1;
                    g_FieldingLogic._0CC = -1;
                } else {
                    g_FieldingLogic._101[f->_18C] = 0;
                }
            }
            g_FieldingLogic._11D = 1;
        }
    }
    if (f->_050 > 0.01f) {
        f->_17E = f->_068 / f->_050;
    }
    fn_3_526DC(g_Ball.fielderWBallIndex);
}

// .text:0x000A3C00 size:0xC0 mapped:0x806E2C94
void fn_3_A3C00(void) {
    s32 i;

    lbl_3_bss_1800 = 0;
    for (i = 0; i < 4; i++) {
        if (lbl_3_bss_1808[i] >= 0) {
            u8 dir = g_Runners[lbl_3_bss_1808[i]].runningDirectionCode;
            if (dir == 1) {
                lbl_3_bss_1800 |= 1 << (i * 4);
            } else if (dir == 3) {
                lbl_3_bss_1800 |= 2 << (i * 4);
            } else if (dir == 2) {
                lbl_3_bss_1800 |= 4 << (i * 4);
            }
        }
    }
}

// .text:0x000A3B30 size:0xD0 mapped:0x806E2BC4
void fn_3_A3B30(void) {
    s32 diff = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] -
               g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0];

    lbl_3_bss_181C = 0;
    if (g_Scores._00 >= g_Scores._AA && g_Scores._AD && diff == 0) {
        lbl_3_bss_181C = 3;
    } else if (g_Scores._00 >= g_Scores._AA - 1 && diff <= 1 && diff >= -1) {
        lbl_3_bss_181C = 2;
    } else if (g_Scores._00 >= g_Scores._AA - 4 && diff <= 1 && diff >= -3) {
        lbl_3_bss_181C = 1;
    }
}

// .text:0x000A384C size:0x2E4 mapped:0x806E28E0
void fn_3_A384C(void) {
    if ((lbl_3_bss_1824 & 0x11) && lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 4 &&
        fn_3_A6ABC(lbl_3_data_4444[2][0], lbl_3_data_4444[2][1]) + 50 < g_Runners[0].framesToNextBase) {
        lbl_3_bss_1818 = 1;
    }
}

// .text:0x000A37BC size:0x90 mapped:0x806E2850
BOOL fn_3_A37BC(void) {
    if (g_Ball.ballAngleFromHome < 0x398) {
        return FALSE;
    }
    if (g_Ball.ballDistanceFromBase[2] < 5.0f) {
        return TRUE;
    }
    if (g_Ball.ballAngleFromHome < 0x400) {
        if (g_Ball.AtBat_Contact_BallPos.z + g_Ball.AtBat_Contact_BallPos.x > 40.0f) {
            return TRUE;
        }
    } else if (g_Ball.AtBat_Contact_BallPos.z - g_Ball.AtBat_Contact_BallPos.x > 40.0f) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A3768 size:0x54 mapped:0x806E27FC
BOOL fn_3_A3768(void) {
    if (g_Ball.ballAngleFromHome >= 0x380 && g_Ball.ballAngleFromHome < 0x640 && g_Ball.ballZoneAwayFromHome <= 1 &&
        g_Ball.AtBat_Contact_BallPos.z > 35.0f + g_Ball.AtBat_Contact_BallPos.x) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A372C size:0x3C mapped:0x806E27C0
BOOL fn_3_A372C(void) {
    if (g_Ball.AtBat_Contact_BallPos.z < 40.0f + g_Ball.AtBat_Contact_BallPos.x &&
        g_Ball.AtBat_Contact_BallPos.z < 40.0f - g_Ball.AtBat_Contact_BallPos.x) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A36BC size:0x70 mapped:0x806E2750
BOOL fn_3_A36BC(void) {
    if (g_Ball.AtBat_Contact_BallPos.z < 15.0f && g_Ball.AtBat_Contact_BallPos.z > 8.0f &&
        g_Ball.AtBat_Contact_BallPos.z < 1.5f + g_Ball.AtBat_Contact_BallPos.x &&
        g_Ball.AtBat_Contact_BallPos.z > g_Ball.AtBat_Contact_BallPos.x - 1.5f &&
        g_Ball.AtBat_Contact_BallPos.x > g_Runners[0].position.x) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A3374 size:0x348 mapped:0x806E2408
BOOL fn_3_A3374(void) {
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];

    if (lbl_3_bss_1824 & 0x1000) {
        if (!(lbl_3_bss_1824 & 0xFFF) && g_Ball.AtBat_ContactResult == 3 && g_Ball.timeSinceBallPickedUp < 30) {
            f32 limit = 69.0f;
            limit += 0.35f * f->_1CE;
            if (g_Ball.ballDistanceFromBase[0] >= 62.0f && g_Ball.ballDistanceFromBase[0] <= limit &&
                g_Runners[3].tagUpInd == 0) {
                if (g_Runners[3].runningDirectionCode == 1 && fn_3_A46A0(lbl_3_bss_1808[3])) {
                    return TRUE;
                }
                return TRUE;
            }
        }
        if (lbl_3_bss_1800 & 0x1000) {
            if (lbl_3_bss_181C == 3) {
                if (g_Ball.ballDistanceFromBase[0] < 75.0f && lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 7 &&
                    fn_3_A46A0(lbl_3_bss_1808[3])) {
                    return TRUE;
                }
                return FALSE;
            }
            if (lbl_3_bss_181C == 2) {
                if (g_Ball.ballDistanceFromBase[0] < 75.0f && lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 6 &&
                    fn_3_A46A0(lbl_3_bss_1808[3])) {
                    return TRUE;
                }
                return FALSE;
            }
            if (g_Ball.ballDistanceFromBase[0] < 68.0f) {
                if (lbl_3_bss_1824 & 0x110) {
                    return FALSE;
                }
                if (lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 4 && fn_3_A46A0(lbl_3_bss_1808[3])) {
                    return TRUE;
                }
            }
        }
    }
    if ((lbl_3_bss_1824 & 0x100) && g_Ball.ballDistanceFromBase[3] < 65.0f && (lbl_3_bss_1800 & 0x100)) {
        if (!(lbl_3_bss_1824 & 0x10)) {
            if (lbl_3_bss_1858[lbl_3_bss_1808[2]] <= 5 && fn_3_A46A0(lbl_3_bss_1808[2])) {
                return TRUE;
            }
        } else if (!(lbl_3_bss_1800 & 0x60)) {
            if (lbl_3_bss_1858[lbl_3_bss_1808[2]] <= 4 && fn_3_A46A0(lbl_3_bss_1808[2])) {
                return TRUE;
            }
        }
    }
    if ((lbl_3_bss_1824 & 0x10) && g_Ball.ballDistanceFromBase[2] < 50.0f && (lbl_3_bss_1800 & 0x10) &&
        !(lbl_3_bss_1824 & 0x1000)) {
        if (lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 5 && fn_3_A46A0(lbl_3_bss_1808[1])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A32B8 size:0xBC mapped:0x806E234C
BOOL fn_3_A32B8(void) {
    if (!(lbl_3_bss_1824 & 0x1000)) {
        return FALSE;
    }
    if ((lbl_3_bss_1804 & 0x1000) && fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    if ((lbl_3_bss_1800 & 0x1000) && g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase >= 0.2f &&
        fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A31E8 size:0xD0 mapped:0x806E227C
BOOL fn_3_A31E8(void) {
    if (!(lbl_3_bss_1824 & 0x1000)) {
        return FALSE;
    }
    if ((lbl_3_bss_1804 & 0x1000) && fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    if ((lbl_3_bss_1800 & 0x1000) && g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase >= 0.2f &&
        lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 6 && fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A2FD8 size:0x210 mapped:0x806E206C
BOOL fn_3_A2FD8(void) {
    if (fn_3_A372C()) {
        if (lbl_3_bss_181C >= 1) {
            if (lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 4 && fn_3_A46A0(lbl_3_bss_1808[3])) {
                return TRUE;
            }
        } else if (lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 3 && fn_3_A46A0(lbl_3_bss_1808[3])) {
            return TRUE;
        }
    }
    if (lbl_3_bss_181C <= 1 && g_Ball.ballDistanceFromBase[3] < 5.0f && lbl_3_bss_1858[lbl_3_bss_1808[2]] <= 2 &&
        fn_3_A46A0(lbl_3_bss_1808[2])) {
        return TRUE;
    }
    if (g_Ball.ballDistanceFromBase[0] <= g_Ball.ballDistanceFromBase[2]) {
        if (lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 4 && fn_3_A46A0(lbl_3_bss_1808[3])) {
            return TRUE;
        }
        if (lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 4 && fn_3_A46A0(lbl_3_bss_1808[1])) {
            return TRUE;
        }
    } else {
        if (lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 4 && fn_3_A46A0(lbl_3_bss_1808[1])) {
            return TRUE;
        }
        if (lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 4 && fn_3_A46A0(lbl_3_bss_1808[3])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A2DDC size:0x1FC mapped:0x806E1E70
BOOL fn_3_A2DDC(void) {
    if (lbl_3_bss_1818 != 0 && fn_3_A46A0(lbl_3_bss_1808[1])) {
        return TRUE;
    }
    if (g_Ball.ballDistanceFromBase[0] <= g_Ball.ballDistanceFromBase[2]) {
        if ((lbl_3_bss_1800 & 0x1000) && lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 3 && fn_3_A46A0(lbl_3_bss_1808[3])) {
            return TRUE;
        }
        if ((lbl_3_bss_1800 & 0x6000) && lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 4) {
            if ((g_FieldingLogic._0D0[3] < 0 || g_Fielders[g_FieldingLogic._0D0[3]]._0A8[3] > 4.0f) &&
                lbl_3_bss_1858[lbl_3_bss_1808[1]] == 3 && fn_3_A46A0(lbl_3_bss_1808[1])) {
                return TRUE;
            }
            if (fn_3_A46A0(lbl_3_bss_1808[3])) {
                return TRUE;
            }
        }
        if (lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 4 && fn_3_A46A0(lbl_3_bss_1808[1])) {
            return TRUE;
        }
    } else {
        if (lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 4 && fn_3_A46A0(lbl_3_bss_1808[1])) {
            return TRUE;
        }
        if ((lbl_3_bss_1800 & 0x1000) && lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 3 && fn_3_A46A0(lbl_3_bss_1808[3])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A2C9C size:0x140 mapped:0x806E1D30
BOOL fn_3_A2C9C(void) {
    if ((lbl_3_bss_1824 & 0x100) && g_Ball.ballDistanceFromBase[3] < 5.0f && lbl_3_bss_1858[lbl_3_bss_1808[2]] <= 2 &&
        fn_3_A46A0(lbl_3_bss_1808[2])) {
        return TRUE;
    }
    if (lbl_3_bss_1818 != 0 && fn_3_A46A0(lbl_3_bss_1808[1])) {
        return TRUE;
    }
    if (lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 4 && g_Strikes.outs == g_Strikes.storedOuts) {
        if (g_Ball.ballDistanceFromBase[1] < 2.5f && lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 2 && fn_3_A46A0(lbl_3_bss_1808[0])) {
            return TRUE;
        }
        if (fn_3_A46A0(lbl_3_bss_1808[1])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A2B6C size:0x130 mapped:0x806E1C00
BOOL fn_3_A2B6C(void) {
    if (g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase >= 0.25f) {
        if (lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 3 && fn_3_A46A0(lbl_3_bss_1808[3])) {
            return TRUE;
        }
        if ((lbl_3_bss_1800 & 0x6000) && lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 4 && g_FieldingLogic._0D0[3] >= 0 &&
            !(g_Fielders[g_FieldingLogic._0D0[3]]._0A8[3] > 4.0f) &&
            (!(g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase < 0.5f) || lbl_3_bss_17FC[3]) &&
            fn_3_A46A0(lbl_3_bss_1808[3])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A295C size:0x210 mapped:0x806E19F0
BOOL fn_3_A295C(void) {
    InMemRunnerType* r = &g_Runners[lbl_3_bss_1808[2]];

    if (r->percentTowardsNextBase > 0.2f && lbl_3_bss_1858[lbl_3_bss_1808[2]] < 3 && g_Ball.ballZoneAwayFromHome <= 1 &&
        r->percentTowardsNextBase <= 0.25f && !(r->percentTowardsNextBase >= 0.25f && r->runningDirectionCode == 1) &&
        (lbl_3_bss_1824 & 1) && g_Ball.ballAngleFromHome > 0x1C0 && g_Ball.ballAngleFromHome < 0x300 &&
        r->percentTowardsNextBase <= 0.3f && lbl_3_bss_1858[lbl_3_bss_1808[0]] <= 3 && fn_3_A46A0(lbl_3_bss_1808[0])) {
        return TRUE;
    }
    if (fn_3_A3768() && lbl_3_bss_1858[lbl_3_bss_1808[2]] <= 4 && g_Strikes.outs == g_Strikes.storedOuts) {
        if (r->percentTowardsNextBase > 0.2f && fn_3_A46A0(lbl_3_bss_1808[2])) {
            return TRUE;
        }
        if ((lbl_3_bss_1800 & 0x10) && r->percentTowardsNextBase > 0.15f && fn_3_A46A0(lbl_3_bss_1808[2])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A25C4 size:0x398 mapped:0x806E1658
BOOL fn_3_A25C4(void) {
    s32 base;

    if (lbl_3_bss_1808[3] >= 0 && lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 5) {
        if ((g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase > 0.2f ||
             (g_Runners[lbl_3_bss_1808[3]].baseStandingOn == -1 && g_Ball.baseBallAndFielderAreOn == 3)) &&
            fn_3_A46A0(lbl_3_bss_1808[3])) {
            base = 3;
            goto found;
        }
        if ((lbl_3_bss_1800 & 0x1000) && g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase > 0.15f &&
            fn_3_A46A0(lbl_3_bss_1808[3])) {
            base = 3;
            goto found;
        }
    }
    if (lbl_3_bss_1808[2] >= 0 && lbl_3_bss_1858[lbl_3_bss_1808[2]] <= 5) {
        if ((g_Runners[lbl_3_bss_1808[2]].percentTowardsNextBase > 0.2f ||
             (g_Runners[lbl_3_bss_1808[2]].baseStandingOn == -1 && g_Ball.baseBallAndFielderAreOn == 2)) &&
            fn_3_A46A0(lbl_3_bss_1808[2])) {
            base = 2;
            goto found;
        }
        if ((lbl_3_bss_1800 & 0x100) && g_Runners[lbl_3_bss_1808[2]].percentTowardsNextBase >= 0.15f &&
            fn_3_A46A0(lbl_3_bss_1808[2])) {
            base = 2;
            goto found;
        }
    }
    if (lbl_3_bss_1808[1] >= 0 && lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 5) {
        if ((g_Runners[lbl_3_bss_1808[1]].percentTowardsNextBase > 0.2f ||
             (g_Runners[lbl_3_bss_1808[1]].baseStandingOn == -1 && g_Ball.baseBallAndFielderAreOn == 1)) &&
            fn_3_A46A0(lbl_3_bss_1808[1])) {
            base = 1;
            goto found;
        }
        if ((lbl_3_bss_1800 & 0x10) && g_Runners[lbl_3_bss_1808[1]].percentTowardsNextBase > 0.15f &&
            fn_3_A46A0(lbl_3_bss_1808[1])) {
            base = 1;
            goto found;
        }
    }
    return FALSE;

found:
    if (g_Ball.ballDistanceFromBase[0] < 3.0f && g_FieldingLogic._0C4 == 2 && lbl_3_bss_1808[3] >= 0 && base == 1 &&
        g_Runners[lbl_3_bss_1808[base]].fractionalBasesRan <= 1.2f && fn_3_AABF8()) {
        g_FieldingLogic._0CC = -1;
        g_FieldingLogic._0C4 = 5;
    }
    return TRUE;
}

// .text:0x000A2404 size:0x1C0 mapped:0x806E1498
BOOL fn_3_A2404(void) {
    s32 order[3];
    s32 i;

    if (g_Ball.AtBat_ContactResult != 3) {
        return FALSE;
    }
    if (lbl_3_bss_1820 == 0) {
        return FALSE;
    }
    if (g_Ball.ballDistanceFromBase[1] < g_Ball.ballDistanceFromBase[3]) {
        if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[1]) {
            order[0] = 2;
            order[1] = 1;
            order[2] = 3;
        } else if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[3]) {
            order[0] = 1;
            order[1] = 2;
            order[2] = 3;
        } else {
            order[0] = 1;
            order[1] = 3;
            order[2] = 2;
        }
    } else if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[3]) {
        order[0] = 2;
        order[1] = 3;
        order[2] = 1;
    } else if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[1]) {
        order[0] = 3;
        order[1] = 2;
        order[2] = 1;
    } else {
        order[0] = 3;
        order[1] = 1;
        order[2] = 2;
    }
    for (i = 0; i < 3; i++) {
        InMemRunnerType* r = &g_Runners[order[i]];
        if (r->runnerOnFieldOrOutOrScored == 1 && r->tagUpInd == 2 && lbl_3_bss_1858[order[i]] <= 4 &&
            fn_3_A46A0(order[i])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A222C size:0x1D8 mapped:0x806E12C0
BOOL fn_3_A222C(void) {
    s32 order[3];
    s32 i;

    if (g_Ball.AtBat_ContactResult != 3) {
        return FALSE;
    }
    if (lbl_3_bss_1820 == 0) {
        return FALSE;
    }
    if (g_Ball.ballDistanceFromBase[1] < g_Ball.ballDistanceFromBase[3]) {
        if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[1]) {
            order[0] = 2;
            order[1] = 1;
            order[2] = 3;
        } else if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[3]) {
            order[0] = 1;
            order[1] = 2;
            order[2] = 3;
        } else {
            order[0] = 1;
            order[1] = 3;
            order[2] = 2;
        }
    } else if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[3]) {
        order[0] = 2;
        order[1] = 3;
        order[2] = 1;
    } else if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[1]) {
        order[0] = 3;
        order[1] = 2;
        order[2] = 1;
    } else {
        order[0] = 3;
        order[1] = 1;
        order[2] = 2;
    }
    for (i = 0; i < 3; i++) {
        InMemRunnerType* r = &g_Runners[order[i]];
        if (r->runnerOnFieldOrOutOrScored == 1 && r->tagUpInd == 2 && lbl_3_bss_1858[order[i]] <= 4 &&
            g_Ball.ballDistanceFromBase[order[i]] < 45.0f && fn_3_A46A0(order[i])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A2048 size:0x1E4 mapped:0x806E10DC
BOOL fn_3_A2048(void) {
    s32 i;
    s32 flags = 0;

    for (i = 0; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            if (g_Runners[i].fractionalBasesRan < 1.7f) {
                flags |= 0x10;
            } else if (g_Runners[i].fractionalBasesRan < 2.2f) {
                flags |= 0x100;
            } else if (g_Runners[i].fractionalBasesRan <= 3.0f) {
                flags |= 0x1000;
            }
        }
    }
    if (g_Ball.ballAngleFromHome > 0x500) {
        if (flags & 0x1000) {
            fn_3_A41E8(3);
            return TRUE;
        }
        if (flags & 0x100) {
            fn_3_A41E8(3);
            return TRUE;
        }
        if (flags & 0x10) {
            fn_3_A41E8(2);
            return TRUE;
        }
        return FALSE;
    }
    if (g_Ball.ballAngleFromHome > 0x400) {
        if (flags & 0x1000) {
            fn_3_A41E8(3);
            return TRUE;
        }
        if ((flags & 0x100) && !(flags & 0x1000)) {
            fn_3_A41E8(2);
            return TRUE;
        }
        return FALSE;
    }
    if (flags & 0x1000) {
        if (!(flags & 0x10) || (flags & 0x100)) {
            fn_3_A41E8(0);
            return TRUE;
        }
    } else if (flags & 0x100) {
        fn_3_A41E8(3);
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A1F3C size:0x10C mapped:0x806E0FD0
BOOL fn_3_A1F3C(void) {
    s32 i;

    if (g_Ball.ballZoneAwayFromHome >= 3) {
        return FALSE;
    }
    if (lbl_3_bss_1808[3] < 0 || lbl_3_bss_1808[3] > 3) {
        return FALSE;
    }
    if (lbl_3_bss_1858[lbl_3_bss_1808[3]] >= 7) {
        return FALSE;
    }
    if (g_Runners[lbl_3_bss_1808[3]].tagUpInd) {
        return FALSE;
    }
    if (lbl_3_bss_1808[3] >= 1) {
        for (i = lbl_3_bss_1808[3] - 1; i >= 0; i--) {
            if (g_Runners[i].percentTowardsNextBase > 0.15f && g_Runners[i].percentTowardsNextBase < 0.85f) {
                return FALSE;
            }
        }
    }
    if (fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A1DA0 size:0x19C mapped:0x806E0E34
BOOL fn_3_A1DA0(void) {
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];

    if (f->_070 > 80.0f - 0.1f * (100 - f->_1CE)) {
        return FALSE;
    }
    if (!(g_Runners[3].runnerOnFieldOrOutOrScored == 1 && g_Runners[3].fractionalBasesRan < 3.15f &&
          (g_Runners[3].runningDirectionCode == 2 || g_Runners[3].runningDirectionCode == 1)) &&
        !(g_Runners[2].runnerOnFieldOrOutOrScored == 1 && g_Runners[2].fractionalBasesRan > 2.85f &&
          g_Runners[2].fractionalBasesRan <= 3.15f && g_Runners[3].runningDirectionCode == 1 && g_Runners[2].tagUpInd == 0)) {
        return FALSE;
    }
    if (g_Runners[1].runnerOnFieldOrOutOrScored == 1) {
        if (g_Runners[1].tagUpInd) {
            if (g_Runners[1].fractionalBasesRan > 1.5f) {
                return FALSE;
            }
        } else if (g_Runners[1].forceOutCd == 1 && g_Runners[1].fractionalBasesRan <= 0.7f) {
            return FALSE;
        }
    }
    g_FieldingLogic._0C4 = 0;
    g_FieldingLogic._0CC = -1;
    g_FieldingLogic._0DE = -1;
    return TRUE;
}

// .text:0x000A1D04 size:0x9C mapped:0x806E0D98
s32 fn_3_A1D04(void) {
    s32 prev;
    f32 prevBases = -10.0f;
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            f32 bases = g_Runners[i].fractionalBasesRan;
            f32 diff = bases - prevBases;
            if (diff < 0.0f) {
                diff = -diff;
            }
            if (diff < 0.35f) {
                if (g_Runners[prev].baseStandingOn < 0) {
                    return prev;
                }
                return i;
            }
            prevBases = bases;
            prev = i;
        }
    }
    return -1;
}

// .text:0x000A009C size:0x1C68 mapped:0x806DF130
void fn_3_A009C(void) {
    return;
}
