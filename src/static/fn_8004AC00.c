#include "static/fn_8004AC00.h"
#include "static/fn_8004B284.h"
#include "static/fn_8004B6EC.h"
#include "static/fn_8004C094.h"
#include "static/particle.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"

// Character effect dispatch: runs a fielder's effect handler by its action

typedef struct EffectParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 _0C[13];
    /* 0x40 */ s32 _40;
    /* 0x44 */ s32 _44;
    /* 0x48 */ s32 _48;
    /* 0x4C */ s32 _4C;
} EffectParams; // size: 0x50

typedef struct EffectActor {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ Vec pos;
    /* 0x040 */ u8 _040[0x4];
    /* 0x044 */ f32 angle;
    /* 0x048 */ u8 _048[0x252 - 0x48];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253[0x275 - 0x253];
    /* 0x275 */ u8 _275;
    /* 0x276 */ u8 _276;
} EffectActor;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ EffectActor* _2C50[13];
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern u8 lbl_800FC0FC[][3];

extern BOOL getAnimRelatedCoordinates(int, int, Vec*);

s16 lbl_800FB798[54] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
s16 lbl_800FB804[54] = {
    28, 20, 36, 27, 14, 24, 28, 24, 24, 29, 16, 19, 29, 29, 25, 30, 26, 28,
    29, 20, 30, 28, 28, 28, 30, 30, 30, 20, 34, 29, 29, 29, 29, 30, 30, 30,
    30, 30, 20, 26, 30, 26, 29, 30, 26, 26, 26, 26, 26, 26, 26, 26, 20, 20,
};
s16 lbl_800FB870[54] = {
    20, 20, 20, 25, 5, 6, 14, 14, 14, 21, 8, 14, 20, 22, 99, 22, 22, 17,
    13, 20, 16, 6, 6, 6, 9, 9, 9, 4, 31, 22, 22, 22, 22, 14, 14, 14,
    14, 99, 8, 23, 20, 32, 20, 16, 22, 22, 22, 22, 20, 20, 20, 20, 4, 4,
};
s16 lbl_800FB8DC[54] = {
    32, 32, 27, 30, 13, 13, 32, 19, 19, 35, 29, 20, 40, 33, 99, 40, 39, 27,
    28, 33, 23, 22, 22, 22, 26, 26, 26, 20, 47, 33, 33, 33, 33, 25, 25, 25,
    25, 99, 14, 30, 35, 34, 40, 23, 39, 39, 39, 39, 32, 32, 32, 32, 20, 20,
};
s16 lbl_800FB948[54] = {
    18, 12, 30, 20, 7, 7, 20, 3, 3, 21, 4, 12, 21, 21, 10, 23, 20, 20,
    18, 1, 21, 9, 9, 9, 9, 9, 9, 5, 29, 21, 21, 21, 21, 21, 21, 21,
    21, 9, 8, 20, 24, 22, 21, 21, 20, 20, 20, 20, 20, 20, 20, 20, 5, 5,
};
s16 lbl_800FB9B4[54] = {
    28, 20, 36, 27, 14, 24, 28, 24, 24, 29, 16, 19, 29, 29, 25, 30, 26, 28,
    29, 20, 30, 28, 28, 28, 30, 30, 30, 20, 34, 29, 29, 29, 29, 30, 30, 30,
    30, 30, 20, 26, 30, 26, 29, 30, 26, 26, 26, 26, 26, 26, 26, 26, 20, 20,
};
s16 lbl_800FBA20[54] = {
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
};
s16 lbl_800FBA8C[54] = {
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
};
s16 lbl_800FBAF8[54] = {
    10, 10, 14, 13, 13, 13, 99, 10, 10, 3, 10, 10, 11, 9, 99, 9, 10, 10,
    10, 10, 11, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 99, 99, 99,
    99, 99, 10, 10, 10, 99, 11, 11, 14, 14, 14, 14, 10, 10, 10, 10, 10, 10,
};
s16 lbl_800FBB64[54] = {
    30, 30, 28, 30, 30, 28, 25, 27, 27, 30, 28, 28, 20, 25, 99, 25, 28, 23,
    28, 28, 25, 30, 30, 30, 30, 30, 30, 22, 25, 25, 25, 25, 25, 99, 99, 99,
    99, 99, 19, 29, 34, 99, 20, 25, 17, 17, 17, 17, 30, 30, 30, 30, 22, 22,
};
s16 lbl_800FBBD0[54] = {
    12, 14, 8, 9, 9, 14, 12, 15, 15, 13, 12, 10, 17, 99, 21, 22, 21, 14,
    13, 13, 15, 9, 9, 9, 9, 9, 9, 6, 27, 21, 21, 21, 21, 13, 13, 13,
    13, 7, 15, 9, 13, 15, 17, 15, 21, 21, 21, 21, 12, 12, 12, 12, 6, 6,
};
s16 lbl_800FBC3C[54] = {
    15, 22, 13, 12, 13, 22, 15, 22, 22, 16, 19, 13, 45, 99, 28, 22, 25, 27,
    22, 21, 20, 10, 10, 10, 14, 14, 14, 11, 30, 28, 28, 28, 28, 25, 25, 25,
    25, 11, 16, 13, 18, 18, 45, 20, 25, 25, 25, 25, 15, 15, 15, 15, 11, 11,
};
s16 lbl_800FBCA8[54] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
s16 lbl_800FBD14[54] = {
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
};
s16 lbl_800FBD80[54] = {
    22, 56, 99, 55, 28, 17, 50, 16, 29, 99, 35, 65, 30, 41, 47, 19, 15, 35,
    38, 16, 40, 12, 12, 12, 13, 13, 13, 16, 18, 41, 41, 41, 41, 36, 36, 36,
    36, 46, 94, 20, 22, 52, 30, 40, 15, 15, 15, 15, 6, 6, 6, 6, 16, 16,
};
s8 lbl_800FBDEC[0x75] = {
    11, 11, 11, 11, 11, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 0, 0, 4, 11, 11, 11, 11, 11, 3, 11, 4, 8, 11, 11,
    5, 5, 5, 5, 5, 3, 3, 3, 0, 11, 0, 0, 0, 11, 3, 3, 11, 11, 11, 3,
    11, 11, 11, 11, 11, 6, 11, 6, 11, 11, 7, 11, 10, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 9, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
};

EffectHandler lbl_800FBE64[11] = {
    fn_8004B284, fn_8004BEB0, fn_8004C510, fn_8004C5F8, fn_80062C60, fn_80062E6C,
    fn_8004C19C, fn_8006C444, fn_8006C3F8, fn_8004ACF4, fn_8004AC00,
};
s32 lbl_800FBE90[5] = { 0, 5, 40000, 128, 64 };
EffectParams lbl_800FBEA4 = {
    0, 4, 2, { 80000, 30000, 78000, 50, 5, 109000, 101000, 0, 40, 12800000, 8000000, 0, 0 },
    0xFFFFFF00, 0, 75000, 0,
};

s32 lbl_803CB848 = 1;
EffectParams* lbl_803CB84C = &lbl_800FBEA4;
s32 lbl_803CB850[2] = { 45, 0 };
s32 lbl_803CB858[2] = { 0, -1 };

s32 lbl_803CBD0C;
s32 lbl_803CBD08;
s32 lbl_803CBD04;
s32 lbl_803CBD00;
s32 lbl_803CBCFC;
s32 lbl_803CBCF8;

// .text:0x8004B270 size:0x14
void fn_8004B270(void) {
    lbl_803CBD0C = 0;
    lbl_803CBD08 = 0;
    lbl_803CBD04 = 0;
}

// .text:0x8004B208 size:0x68
void fn_8004B208(void* actor, s32 action, s32 b, f32 t) {
    if (lbl_803CB848 != 0 && action >= 0 && action < 0x75) {
        s8 kind = lbl_800FBDEC[action];
        if (kind != 11) {
            lbl_800FBE64[kind](actor, action, b, t);
        }
    }
}

// .text:0x8004B1C0 size:0x48
void fn_8004B1C0(s32 kind, void* actor, s32 a, s32 b, f32 t) {
    if (kind != 11) {
        lbl_800FBE64[kind](actor, a, b, t);
    }
}

// .text:0x8004B1B8 size:0x8
void fn_8004B1B8(s32 v) {
    lbl_803CBD0C = v;
}

// .text:0x8004AFA8 size:0x210
void fn_8004AFA8(s32 player) {
    EffectActor* actor = lbl_8036E548._2C50[player];
    Vec pos;

    lbl_803CB84C->_00 = lbl_803CBD0C;
    lbl_800FBE90[0] = lbl_803CBD0C;
    if (actor->_252 == 14 || actor->_252 == 37) {
        return;
    }
    fn_8004AE18(player);
    if (actor->_276 & 2) {
        getAnimRelatedCoordinates(player, 30, &pos);
        fn_8002F258(&pos, player * 2, (struct FlareParams*)lbl_800FBE90);
    }
    if (actor->_276 & 4) {
        getAnimRelatedCoordinates(player, 34, &pos);
        fn_8002F258(&pos, player * 2 + 1, (struct FlareParams*)lbl_800FBE90);
    }
}

// .text:0x8004AE18 size:0x190
void fn_8004AE18(s32 player) {
    EffectActor* actor = lbl_8036E548._2C50[player];
    Mtx m;
    Vec v;

    lbl_800FBEA4._40 = (lbl_800FC0FC[fn_8004AD54(g_d_GameSettings.StadiumID, actor->_275)][0] << 24) |
                       ((lbl_800FC0FC[fn_8004AD54(g_d_GameSettings.StadiumID, actor->_275)][1] << 16) & 0xFF0000) |
                       ((lbl_800FC0FC[fn_8004AD54(g_d_GameSettings.StadiumID, actor->_275)][2] << 8) & 0xFF00);
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 1.0f;
    PSMTXRotRad(m, 'Y', actor->angle);
    PSMTXMultVec(m, &v, &v);
    fn_80030D88(&actor->pos, &v, lbl_803CB84C, 5);
    if (actor->_252 == 14 || actor->_252 == 37) {
        return;
    }
    if (actor->_276 & 2) {
        getAnimRelatedCoordinates(player, 30, &v);
        fn_8002F1AC(&v, player * 2);
    }
    if (actor->_276 & 4) {
        getAnimRelatedCoordinates(player, 34, &v);
        fn_8002F1AC(&v, player * 2 + 1);
    }
}

// .text:0x8004AD54 size:0xC4
s32 fn_8004AD54(s32 stadium, s32 flags) {
    s32 kind = flags & 0x7F;
    s32 ret;

    switch (stadium) {
    case 0:
        if (kind == 1) {
            ret = 1;
        } else {
            ret = 0;
        }
        break;
    case 1:
        ret = 5;
        break;
    case 2:
        if (kind == 1) {
            ret = 11;
        } else {
            ret = 10;
        }
        break;
    case 3:
        if (kind == 1) {
            ret = 7;
        } else {
            ret = 6;
        }
        break;
    case 4:
        if (kind == 10) {
            ret = 4;
        } else if (kind == 1) {
            ret = 3;
        } else {
            ret = 2;
        }
        break;
    case 5:
        if (kind == 10) {
            ret = 9;
        } else {
            ret = 8;
        }
        break;
    case 6:
        ret = 12;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

// .text:0x8004ACF4 size:0x60
void fn_8004ACF4(void* actor, s32 a, s32 b, f32 t) {
    switch (((EffectActor*)actor)->_252) {
    case 48:
    case 49:
    case 50:
    case 51:
        if (t < 0.5f) {
            lbl_803CBD04 = 1;
        }
        break;
    }
    lbl_800FBE64[2](actor, a, b, t);
}

// .text:0x8004ACDC size:0x18
s32 fn_8004ACDC(s32 clear) {
    s32 v = lbl_803CBD08;

    if (clear) {
        lbl_803CBD08 = 0;
    }
    return v;
}

// .text:0x8004ACC4 size:0x18
s32 fn_8004ACC4(s32 clear) {
    s32 v = lbl_803CBD04;

    if (clear) {
        lbl_803CBD04 = 0;
    }
    return v;
}

// .text:0x8004AC00 size:0xC4
void fn_8004AC00(void* actor, s32 a, s32 b, f32 t) {
    if (lbl_80366158._28 != 1) {
        if (((EffectActor*)actor)->_252 == 0) {
            if (t >= lbl_803CBCF8 && t <= lbl_803CB850[0]) {
                lbl_803CBD00 = 1;
                if (t == 0.5) {
                    lbl_803CBCFC = 1;
                } else {
                    lbl_803CBCFC = 0;
                }
            }
        } else if (((EffectActor*)actor)->_252 == 18) {
            fn_8004C19C(actor, a, b, t);
        }
    }
}
