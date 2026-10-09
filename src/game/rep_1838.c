#include "game/rep_1838.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "Dolphin/rand.h"
#include "static/UnknownHomes_Static.h"

extern u8 lbl_80361B20[0x130];

// .text:0x000A0018 size:0x84 mapped:0x806DF0AC
f32 shortAngleToRad_Capped(s16 ang) {
    f32 v = shortAngleToRad(ang);
    if (v > PI) {
        v = -(TAU - v);
    }
    return v;
}

// .text:0x0009FFAC size:0x6C mapped:0x806DF040
f32 shortAngleToRad(s16 ang) {
    f32 v;
    if (ang < 0) {
        ang += SANG_ANG_360;
    }
    if (ang >= SANG_ANG_360) {
        ang -= SANG_ANG_360;
    }
    return PI * (f32)(ang * 2) / (f32)SANG_ANG_360;
}

// .text:0x0009FF60 size:0x4C mapped:0x806DEFF4
s16 radToShortAngle(f32 v) {
    if (v < 0) {
        v = v + TAU;
    }
    return v * (f32)SANG_ANG_180 / PI; // implicit conversion to s16
}

// .text:0x0009FF04 size:0x5C mapped:0x806DEF98
s16 fn_3_9FF04(f32 v) {
    s16 ret = radToShortAngle(v);
    if (ret >= SANG_ANG_180) {
        ret -= SANG_ANG_360;
    }
    return ret; // implicit conversion to s16
}

// .text:0x0009FEA8 size:0x5C mapped:0x806DEF3C
f32 fn_3_9FEA8(f32 v) {
    if (v >= PI) {
        while (v >= PI) {
            v = v - TAU;
        }
    }
    if (v < -PI) {
        while (v < -PI) {
            v = v + TAU;
        }
    }
    return v;
}

// .text:0x0009FE6C size:0x3C mapped:0x806DEF00
s16 fn_3_9FE6C_normalizeAngle(s16 ang) {
    if (ang < 0) {
        while (ang < 0) {
            ang += SANG_ANG_360;
        }
    }
    if (ang >= SANG_ANG_360) {
        while (ang >= SANG_ANG_360) {
            ang -= SANG_ANG_360;
        }
    }
    return ang;
}

// .text:0x0009FDD8 size:0x94 mapped:0x806DEE6C
f32 fn_3_9FDD8(f32 ang) {
    f32 v;
    if (ang < 0) {
        while (ang < 0) {
            ang += (f32)SANG_ANG_360;
        }
    }
    if (ang >= (f32)SANG_ANG_360) {
        while (ang >= (f32)SANG_ANG_360) {
            ang -= (f32)SANG_ANG_360;
        }
    }
    v = PI * (f32)(ang * 2) / (f32)SANG_ANG_360;
    if (v > PI) {
        v = -(TAU - v);
    }
    return v;
}

// .text:0x0009FD6C size:0x6C mapped:0x806DEE00
s16 fn_3_9FD6C(s16 ang) {
    ang = fn_3_9FE6C_normalizeAngle(ang);

    if (ang > SANG_ANG_180) {
        ang -= SANG_ANG_360;
        if (ang <= -SANG_ANG_90) {
            ang = -SANG_ANG_90 + 1;
        }
    } else if (ang >= SANG_ANG_90) {
        ang = SANG_ANG_90 - 1;
    }

    return ang;
}

// .text:0x0009FD28 size:0x44 mapped:0x806DEDBC
s16 fn_3_9FD28(s16 ang) {
    if (ang < -SANG_ANG_180) {
        while (ang < -SANG_ANG_180) {
            ang += SANG_ANG_360;
        }
    }
    if (ang > SANG_ANG_180 - 1) {
        while (ang > SANG_ANG_180 - 1) {
            ang -= SANG_ANG_360;
        }
    }
    return ang;
}

// .text:0x0009FCF8 size:0x30 mapped:0x806DED8C
s16 fn_3_9FCF8(s16 a, s16 b) {
    int diff = a - b;
    diff = (s16)ABS(diff);
    if (diff > SANG_ANG_180) {
        return SANG_ANG_360 - diff;
    }
    return diff;
}

// .text:0x0009FCA4 size:0x54 mapped:0x806DED38
s16 fn_3_9FCA4(s16 a, s16 b) {
    s16 diff;
    if (a > SANG_ANG_180) {
        a = a - SANG_ANG_360;
    }
    if (b > SANG_ANG_180) {
        b = b - SANG_ANG_360;
    }
    diff = a - b;
    if (diff > SANG_ANG_180) {
        diff -= SANG_ANG_360;
    }
    if (diff < -SANG_ANG_180) {
        diff += SANG_ANG_360;
    }
    return diff;
}

// .text:0x0009FC1C size:0x88 mapped:0x806DECB0
s16 fn_3_9FC1C(f32 x, f32 y) {
    f32 diff = x - y;
    int ang;
    if (diff < 0) {
        diff = -diff;
    }

    if (diff < 0) {
        diff = diff + TAU;
    }

    ang = (diff * (f32)SANG_ANG_180 / PI);

    if ((s16)ang >= SANG_ANG_180) {
        ang = ang - SANG_ANG_360;
    }
    ang = (s16)ang;

    return (s16)ABS(ang);
}

// .text:0x0009FB8C size:0x90 mapped:0x806DEC20
s16 fn_3_9FB8C(f32 x, f32 y) {
    s16 v;
    if (x == 0) {
        if (y >= 0.f) {
            return SANG_ANG_90;
        } else {
            return SANG_ANG_270;
        }
    }
    v = ATAN2F(y, x) * (f32)SANG_ANG_180 / PI;
    if (v < 0) {
        v = v + SANG_ANG_360;
    }
    return v;
}

// .text:0x0009FB40 size:0x4C mapped:0x806DEBD4
f32 game_atan2(f32 x, f32 y) {
    if (x == 0.f && y == 0.f) {
        return 0.f;
    }
    return ATAN2F(y, x);
}

// .text:0x0009FAA4 size:0x9C mapped:0x806DEB38
f32 fn_3_9FAA4(f32 x, f32 y) {
    f32 v;
    if (x == 0) {
        if (y >= 0.f) {
            return (f32)SANG_ANG_90;
        } else {
            return (f32)SANG_ANG_270;
        }
    }

    v = ATAN2F(y, x) * (f32)SANG_ANG_180 / PI;
    if (v < 0.f) {
        v = v + (f32)SANG_ANG_360;
    }
    return v;
}

// .text:0x0009F9C8 size:0xDC mapped:0x806DEA5C
void getComponentsFromSAng(s16 ang, f32* x, f32* y) {
    f32 v;
    if (ang < 0) {
        ang += SANG_ANG_360;
    }
    if (ang >= SANG_ANG_360) {
        ang -= SANG_ANG_360;
    }
    v = (ang * 2) * PI / (f32)SANG_ANG_360;
    if (v > PI) {
        v = -(TAU - v);
    }
    getComponentsFromRad(v, x, y);
}

// .text:0x0009F964 size:0x64 mapped:0x806DE9F8
void getComponentsFromRad(f32 v, f32* x, f32* y) {
    *x = COSF(v);
    *y = SINF(v);
}

// .text:0x0009F79C size:0x1C8 mapped:0x806DE830
void fn_3_9F79C(f32 a, f32 x, f32 y, f32* outX, f32* outY) {
    f32 c, s, v, mag;
    mag = game_atan2(x, y);
    getComponentsFromRad(mag + a, &c, &s);
    v = dolsqrtf2(x * x + y * y);
    *outX = c * v;
    *outY = s * v;
}

// .text:0x0009F658 size:0x144 mapped:0x806DE6EC
void normalizeVector(VecXYZ* out, VecXYZ* v) {
    f32 mag = 1.f / dolsqrtf2(v->x * v->x + v->y * v->y + v->z * v->z);
    out->x = v->x * (mag);
    out->y = v->y * (mag);
    out->z = v->z * (mag);
}

// .text:0x0009F5B8 size:0xA0 mapped:0x806DE64C
bool calculateLineIntersection(VecXZ* out, VecXZ* a, VecXZ* b) {
    f32 param;
    // Calculate the magnitude of the cross product of the direction vectors
    f32 cross_mag = ((a[1].x - a[0].x) * (b[1].z - b[0].z)) - ((a[1].z - a[0].z) * (b[1].x - b[0].x));

    // If the magnitude is near zero, the lines are parallel or coincident
    if (cross_mag >= -0.01f && cross_mag <= 0.01f) {
        return false;
    }

    // Calculate the parameter for the intersection point along the first segment
    param = ((a[0].z - b[0].z) * (b[1].x - b[0].x) - (a[0].x - b[0].x) * (b[1].z - b[0].z)) / cross_mag;

    // Compute the intersection point
    out->x = param * (a[1].x - a[0].x) + a[0].x;
    out->z = param * (a[1].z - a[0].z) + a[0].z;

    return true;
}

// .text:0x0009EFD0 size:0x5E8 mapped:0x806DE064
f32 fn_3_9EFD0(VecXYZ* l_start, VecXYZ* l_end, VecXYZ* point, VecXYZ* outClosest) {
    // r6 = r31
    // r5 = r30
    // r4 = r29
    // r3 = r28
    VecXYZ ab;
    VecXYZ bp;
    VecXYZ proj;
    f32 abLen, v2, distA, distB, dist;

    ab.x = l_end->x - l_start->x;
    ab.y = l_end->y - l_start->y;
    ab.z = l_end->z - l_start->z;
    bp.x = point->x - l_start->x;
    bp.y = point->y - l_start->y;
    bp.z = point->z - l_start->z;
    abLen = dolsqrtf2(ab.x * ab.x + ab.y * ab.y + ab.z * ab.z);
    if (abLen <= 0 || (v2 = vecDotProduct(&ab, &bp) / (SQ(ab.x) + SQ(ab.y) + SQ(ab.z)), v2 < 0.f) || v2 > 1.f) {
        distA = dolsqrtf2((SQ(point->x - l_start->x) + SQ(point->y - l_start->y) + SQ(point->z - l_start->z)));
        distB = dolsqrtf2(SQ(point->x - l_end->x) + SQ(point->y - l_end->y) + SQ(point->z - l_end->z));
        if (distA < distB) {
            if (outClosest != NULL) {
                outClosest->x = l_start->x;
                outClosest->y = l_start->y;
                outClosest->z = l_start->z;
            }
            return -distA;
        } else {
            if (outClosest != NULL) {
                outClosest->x = l_end->x;
                outClosest->y = l_end->y;
                outClosest->z = l_end->z;
            }
            return -distB;
        }
    }
    proj.x = ab.x * v2;
    proj.y = ab.y * v2;
    proj.z = ab.z * v2;
    ab.x = proj.x - bp.x;
    ab.y = proj.y - bp.y;
    ab.z = proj.z - bp.z;

    dist = dolsqrtf2(SQ(ab.x) + SQ(ab.y) + SQ(ab.z));
    if (outClosest != NULL) {
        outClosest->x = l_start->x + proj.x;
        outClosest->y = l_start->y + proj.y;
        outClosest->z = l_start->z + proj.z;
    }
    return dist;
}

// UNUSED .text:0x0009EFAC size:0x24 mapped:0x806DE040
static u8 static_clamp(int v, int min, int max) {
    if (v > max) {
        return max;
    } else if (v < min) {
        return min;
    } else {
        return v;
    }
}

// .text:0x0009EEB8 size:0xF4 mapped:0x806DDF4C
// The branch form of |max| is what RandomIndexFromWeights and fn_3_9E368 inline (both match);
// this copy and the ones in fn_3_9E078 and RandomInt_Game_Range compute it branch-free (ABS) in the target.
int RandomInt_Game(int max) {
    int ret;
    int absmax = max;

    if (max < 0) {
        absmax = -max;
    }

    if (absmax <= 1) {
        return 0;
    }

    g_Ball.StaticRandomInt1 = g_Ball.StaticRandomInt1 - ((u8)g_Ball.StaticRandomInt2) +
                              g_Ball.StaticRandomInt2 / absmax + g_Ball.totalFramesAtPlay;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice.instructionNumber >= 0) {
        return 0;
    }

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        g_Ball.StaticRandomInt1 += rand();
    }

    ret = g_Ball.StaticRandomInt1 % absmax;
    ret = ABS(ret);
    if (max < 0) {
        return -ret;
    } else {
        return ret;
    }
}

// .text:0x0009EE24 size:0x94 mapped:0x806DDEB8
int random_fn_3_9EE24(int max) {
    int absMax;
    int ret, r2;
    absMax = ABS(max);

    if (absMax <= 1) {
        return 0;
    }
    ret = unkSimulationRelatedStruct._00 + g_d_GameSettings.FrameCountWhileNotAtMainMenu +
          (g_d_GameSettings.FrameCountWhileNotAtMainMenu >> 1) - g_Ball.StaticRandomInt1 +
          ((u8)g_Ball.StaticRandomInt2) + (unkSimulationRelatedStruct._00 / absMax);
    unkSimulationRelatedStruct._00 = ret;
    ret %= (u32)absMax;
    r2 = ABS(ret);

    if (max < 0) {
        return -r2;
    } else {
        return r2;
    }
}

// .text:0x0009ED1C size:0x108 mapped:0x806DDDB0
int RandomInt_Game_Range(int min, int max) {
    int diff = max - min + 1;
    return RandomInt_Game(diff) + min;
}

// .text:0x0009EBCC size:0x150 mapped:0x806DDC60
f32 RandomF32_Game_Range(f32 a, f32 b) {
    return RandomInt_Game((int)((b - a) * 1000.f) + 1) * (1.f / 1000.f) + a;
}

// .text:0x0009EAE4 size:0xE8 mapped:0x806DDB78
f32 RandomF32_UNK_Range(f32 a, f32 b) {
    return random_fn_3_9EE24((int)((b - a) * 1000.f) + 1) * (1.f / 1000.f) + a;
}

// .text:0x0009EA1C size:0xC8 mapped:0x806DDAB0
BOOL fn_3_9EA1C(int team) {
    int i;

    for (i = 1; i < 10; i++) {
        if (g_GameLogic.battingOrderAndPositionMapping[team][i][1] % 10 == 9) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x0009E834 size:0x1E8 mapped:0x806DD8C8
BOOL fn_3_9E834(void) {
    int i;

    if (!g_d_GameSettings.exhibitionMatchInd) {
        for (i = 0; i < 54; i++) {
            if (starMissionCompletionTracker._43D6[i]) {
                return TRUE;
            }
        }
    } else {
        for (i = 0; i < 54; i++) {
            if (lbl_80361B20[i]) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// .text:0x0009E7D4 size:0x60 mapped:0x806DD868
void fn_3_9E7D4(int team) {
    if (g_d_GameSettings.GameModeSelected != 2 || g_GameLogic.secondaryGameMode != 0xF) {
        if (g_GameLogic.currentBatterPerTeam[team] == 9) {
            g_GameLogic.currentBatterPerTeam[team] = 1;
        } else {
            g_GameLogic.currentBatterPerTeam[team]++;
        }
    }
}

// .text:0x0009E5A0 size:0x234 mapped:0x806DD634
int RandomIndexFromWeights(u8* weights, int count) {
    int local[10];
    int i;
    int total = 0;
    int r;

    for (i = 0; i < count; i++) {
        local[i] = weights[i];
        total += local[i];
    }
    r = RandomInt_Game(total);
    for (i = 0; i < count; i++) {
        if (r < local[i]) {
            return i;
        }
        r -= local[i];
    }
    return 0;
}

// .text:0x0009E368 size:0x238 mapped:0x806DD3FC
int fn_3_9E368(int* weights, int count) {
    int local[10];
    int i;
    int total = 0;
    int r;

    for (i = 0; i < count; i++) {
        local[i] = weights[i];
        total += local[i];
    }
    r = RandomInt_Game(total);
    for (i = 0; i < count; i++) {
        if (r < local[i]) {
            return i;
        }
        r -= local[i];
    }
    return 0;
}

// .text:0x0009E078 size:0x2F0 mapped:0x806DD10C
// The target's inlined random helpers take |n| branch-free (srawi/xor) and keep n in its own
// register; here they branch, and the copy loop allocates differently.
void fn_3_9E078(int* order, int count, BOOL useGameRandom) {
    int src[20];
    int used[20];
    int i;
    int j;
    int r;
    int n;

    for (i = 0; i < count; i++) {
        used[i] = 0;
        src[i] = order[i];
    }
    for (i = count - 1; i >= 0; i--) {
        n = i + 1;
        if (useGameRandom) {
            r = RandomInt_Game(n);
        } else {
            r = random_fn_3_9EE24(n);
        }
        for (j = 0; j < count; j++) {
            if (used[j] == 0) {
                if (r == 0) {
                    order[i] = src[j];
                    used[j] = 1;
                    break;
                }
                r--;
            }
        }
    }
}

// .text:0x0009DC18 size:0x460 mapped:0x806DCCAC
void fn_3_9DC18(u8* list, int count, BOOL useGameRandom) {
    int order[10];
    u32 i;

    for (i = 0; i < count; i++) {
        order[i] = list[i];
    }
    fn_3_9E078(order, count, useGameRandom);
    for (i = 0; i < count; i++) {
        list[i] = order[i];
    }
}
