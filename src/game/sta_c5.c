#include "game/sta_c5.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/os.h"
#include "musyx/musyx.h"
#include "string.h"
#include "math.h"
#include "game/rep_1D58.h"
#include "game/rep_AC8.h"
#include "game/rep_540.h"
#include "game/m_sound.h"
#include "game/rep_1838.h"
#include "game/rep_23E8.h"
#include "Dolphin/rand.h"

typedef struct {
    /* 0x00 */ u8 _00[0x60];
    /* 0x60 */ u8 _60;
    /* 0x61 */ u8 _61[0xA4 - 0x61];
    /* 0xA4 */ u8 _A4;
} StaC5Bone;

typedef struct {
    /* 0x00 */ u8 _00[0x06];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x18 - 0x08];
    /* 0x18 */ StaC5Bone** _18;
} StaC5Actor;

typedef struct {
    /* 0x00 */ StaC5Actor* _00;
    /* 0x04 */ u8 _04[0x58 - 0x04];
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A[0x5C - 0x5A];
    /* 0x5C */ f32 _5C;
    /* 0x60 */ u8 _60[0x90 - 0x60];
} StaC5Model; // size: 0x90

typedef struct StaC5Draw {
    /* 0x00 */ Control control;
    /* 0x44 */ u8 _44[0x74 - 0x44];
    /* 0x74 */ StaC5Model* _74;
    /* 0x78 */ struct StadiumObjectCollision* _78;
    /* 0x7C */ u8 _7C[0x90 - 0x7C];
    /* 0x90 */ u8 _90_7 : 1;
    /* 0x90 */ u8 _90_6 : 1;
    /* 0x90 */ u8 _90_5 : 1;
    /* 0x90 */ u8 _90_0 : 5;
    /* 0x91 */ u8 _91[0x99 - 0x91];
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A[0x9C - 0x9A];
    /* 0x9C */ u8 _9C;
    /* 0x9D */ u8 _9D;
    /* 0x9E */ u8 _9E[0xA0 - 0x9E];
    /* 0xA0 */ Vec _A0;
    /* 0xAC */ f32 _AC;
    /* 0xB0 */ f32 _B0;
    /* 0xB4 */ f32 _B4;
    /* 0xB8 */ f32 _B8;
    /* 0xBC */ f32 _BC;
    /* 0xC0 */ u8 _C0;
    /* 0xC1 */ s8 _C1;
    /* 0xC2 */ u8 _C2[0xC4 - 0xC2];
    /* 0xC4 */ s8 _C4;
    /* 0xC5 */ u8 _C5;
    /* 0xC6 */ u8 _C6;
    /* 0xC7 */ u8 _C7;
    /* 0xC8 */ u8 _C8;
    /* 0xC9 */ u8 _C9[0xE8 - 0xC9];
} StaC5Draw; // size: 0xE8

typedef struct StaC5Ball {
    /* 0x00 */ Control control;
    /* 0x44 */ u8 _44[0x74 - 0x44];
    /* 0x74 */ StaC5Model* _74;
    /* 0x78 */ u8 _78[0x99 - 0x78];
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A[0x9C - 0x9A];
    /* 0x9C */ u8 _9C;
    /* 0x9D */ u8 _9D[0xA0 - 0x9D];
    /* 0xA0 */ StaC5Draw* _A0;
    /* 0xA4 */ struct StaC5Emitter* _A4;
    /* 0xA8 */ Vec pos;
    /* 0xB4 */ Vec vel;
    /* 0xC0 */ f32 _C0;
    /* 0xC4 */ s8 _C4;
} StaC5Ball;

typedef struct {
    /* 0x00 */ u16 count;
    /* 0x04 */ Mtx _04;
    /* 0x34 */ StaC5Model models[1];
} StaC5ModelTable;

extern struct {
    /* 0x00 */ u8 _00[0x6C];
    /* 0x6C */ StaC5ModelTable* _6C;
} lbl_8036E548;

extern void AnimateActorBones(StaC5Actor* actor);
extern void fn_800B4CA0(StaC5Actor* actor, f32 frame);
extern f32 fn_800B4A94(StaC5Actor* actor);

typedef struct StaC5Particle {
    /* 0x00 */ struct StaC5Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ u8 _30[0x38 - 0x30];
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 life;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 index;
} StaC5Particle;

typedef struct StaC5Emitter {
    /* 0x00 */ struct StaC5Emitter* prev;
    /* 0x04 */ struct StaC5Emitter* next;
    /* 0x08 */ BOOL (*_08)(struct StaC5Emitter*);
    /* 0x0C */ StaC5Particle* particles;
    /* 0x10 */ void* _10;
} StaC5Emitter;

extern void fn_80033620(StaC5Emitter* emitter);
extern void fn_80033964(StaC5Emitter* emitter);
extern void fn_80033F64(f32, f32, f32);
extern void fn_80033CC8(StaC5Particle* particle, void* arg1);

typedef struct StadiumSort1D58 {
    /* 0x00 */ f32 depth;
    /* 0x04 */ s32 index;
} StadiumSort1D58; // size: 0x8

extern struct {
    /* 0x00 */ StaC5Draw* _00;
    /* 0x04 */ u8 _04[0x14 - 0x04];
    /* 0x14 */ StadiumSort1D58* _14;
    /* 0x18 */ void (*_18)(void);
    /* 0x1C */ void (*_1C)(void);
    /* 0x20 */ u8 _20[0x30 - 0x20];
    /* 0x30 */ u32 _30;
    /* 0x34 */ void* _34;
    /* 0x38 */ u8 _38[0x3C - 0x38];
    /* 0x3C */ u32* _3C;
    /* 0x40 */ u16* _40;
    /* 0x44 */ u32* _44;
    /* 0x48 */ Vec* _48;
    /* 0x4C */ u8 _4C[0x64 - 0x4C];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66[0x6D - 0x66];
    /* 0x6D */ u8 _6D;
} lbl_3_common_bss_350E4;

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ u8 type;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} StaC5Prop; // size: 0x14

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ u8 type;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ u8 _14;
} StaC5Prop2; // size: 0x18

typedef struct {
    /* 0x00 */ s32 period[3];
    /* 0x0C */ f32 _0C[3];
    /* 0x18 */ f32 _18[3];
} StaC5Flash; // size: 0x24

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
} StaC5Wave; // size: 0xC

typedef struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ void (*_04)(void);
    /* 0x08 */ void* _08;
    /* 0x0C */ void (*_0C)(void);
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} StaC5Callbacks; // size: 0x14

typedef struct {
    /* 0x000 */ Vec pos;
    /* 0x00C */ u8 _00C[0x217 - 0x00C];
    /* 0x217 */ u8 _217;
    /* 0x218 */ u8 _218[0x268 - 0x218];
} StaC5Fielder; // size: 0x268

extern StaC5Fielder g_Fielders[9];
extern s32 fn_800247E4(s32 x, s32 y, s32 width, s32 bytes);
extern BOOL fn_800527C4(Vec* pos);
extern s32 fn_8005268C(void);
extern s16 fn_3_B7F70(s16 range);

extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];

// The target reaches all of these from one pool base, so they are static
static s32 lbl_3_data_1B820 = -1;
static f32 lbl_3_data_1B824[3][4][2] = {
    { { -33.216f, 75.687f }, { -36.503f, 69.506f }, { -12.026f, 64.419f }, { -15.312f, 58.239f } },
    { { -9.67f, 63.584f }, { -11.425f, 57.847f }, { 16.15f, 55.69f }, { 14.396f, 49.953f } },
    { { 20.255f, 53.422f }, { 16.481f, 58.142f }, { 34.188f, 36.839f }, { 30.415f, 33.538f } },
};
static StaC5Prop lbl_3_data_1B884[6] = {
    { { 32.536f, 4.0f, 100.625f }, -45.0f, 1, 1, 1, 0 },
    { { -32.536f, 4.0f, 100.625f }, 45.0f, 1, 1, 1, 0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 6, 0, 0xFF, 0 },
};
static StaC5Prop lbl_3_data_1B8FC[6] = {
    { { 32.536f, 10.0f, 100.625f }, -45.0f, 0, 1, 1, 0 },
    { { -32.536f, 10.0f, 100.625f }, 45.0f, 0, 1, 1, 0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 6, 0, 0xFF, 0 },
};
static StaC5Flash lbl_3_data_1B974 = { { 15, 10, 2 }, { 1.0f, 1.0f, 1.0f }, { 0.7f, 0.7f, 0.7f } };
static StaC5Wave lbl_3_data_1B998 = { 2, 3.0f, 3.0f };
static StaC5Prop2 lbl_3_data_1B9A4[6] = {
    { { -22.621f, 0.0f, 66.963f }, 0.0f, 2, 1, 1, 0, 0 },
    { { 2.3625f, 0.0f, 56.7685f }, 0.0f, 2, 1, 1, 0, 1 },
    { { 25.3345f, 0.0f, 45.84f }, 0.0f, 2, 1, 1, 0, 2 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 6, 0, 0xFF, 0, 0 },
};
static u8 lbl_3_data_1BA34[18] = { 1, 4, 4, 2, 3, 2, 2, 2, 2, 6, 6, 6, 8, 9, 8, 9, 7, 7 };
static f32 lbl_3_data_1BA48 = 48.0f;
static f32 lbl_3_data_1BA4C[2][2] = { { 3.0f, 0.0f }, { -3.0f, 0.0f } };
static StaC5Callbacks lbl_3_data_1BA5C = { NULL, fn_3_EEE3C, NULL, fn_3_EEE3C, 1, 1, 1, 0 };
static Vec lbl_3_data_1BA70 = { 0.0f, 0.0f, 0.0f };
static Vec lbl_3_data_1BA7C = { 0.0f, 0.0f, 0.0f };

// MWCC lays out .bss statics in reverse declaration order
static s32 lbl_3_bss_B560[4];
static s32 lbl_3_bss_B55C;
static f32 lbl_3_bss_B260[0xBF];
static u32 lbl_3_bss_B244[7];
static struct {
    /* 0x00 */ u8 count;
    /* 0x04 */ f32 _04;
    /* 0x08 */ u8 _08[0x24 - 0x08];
} lbl_3_bss_B220;
static u8 lbl_3_bss_B21F;
static u8 lbl_3_bss_B21E;
static u8 lbl_3_bss_B21D;
static u8 lbl_3_bss_B21C;
static u8 lbl_3_bss_B21B;
static u8 lbl_3_bss_B21A;
static u8 lbl_3_bss_B219;
static u8 lbl_3_bss_B218;
static u8 lbl_3_bss_B1BC[0x5C];
static u8 lbl_3_bss_B160[0x5C];
static u8 lbl_3_bss_B15C;
static void* lbl_3_bss_B154[2];
static GXTexObj lbl_3_bss_B134;
static Mtx23 lbl_3_bss_B11C;
static u8* lbl_3_bss_B118;
static s8 lbl_3_bss_AF18[0x200];
static f32 lbl_3_bss_AF04[5];
static f32 lbl_3_bss_AF00;
static s32 lbl_3_bss_AEFC;
static s32 lbl_3_bss_AEF8;
static void* lbl_3_bss_AEF4;
static s32 lbl_3_bss_AEF0;
static f32 lbl_3_bss_AEEC;
static u8 lbl_3_bss_AEE8;
static s32 lbl_3_bss_AEE4;
static u8 lbl_3_bss_AEE2;
static u8 lbl_3_bss_AEE1;
static u8 lbl_3_bss_AEE0;

// .text:0x000F6FDC size:0x1468 mapped:0x80736070
void fn_3_F6FDC(void) {
    return;
}

// .text:0x000F6FCC size:0x10 mapped:0x80736060
void fn_3_F6FCC(void) {
    lbl_3_bss_AEE8 = 1;
}

// .text:0x000F6C60 size:0x36C mapped:0x80735CF4
void fn_3_F6C60(void) {
    return;
}

// .text:0x000F6A94 size:0x1CC mapped:0x80735B28
void fn_3_F6A94(s32* n) {
    Mtx m;
    Control control;
    struct StadiumObjectCollision* collision;
    s32 i;
    u16 start;

    start = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._3C[*n - 1] + lbl_3_common_bss_350E4._40[*n - 1];
    for (i = 0; i < lbl_3_bss_B21E; i++) {
        lbl_3_common_bss_350E4._44[start + i] = lbl_3_bss_B21D + i;
        lbl_3_common_bss_350E4._3C[*n]++;
    }
    fn_3_B8574();
    collision = lbl_3_common_bss_350E4._00[lbl_3_bss_B21D]._78;
    control.type = 0;
    CTRLSetTranslation(&control, -50.0f, 0.0f, 40.0f);
    CTRLBuildMatrix(&control, m);
    fn_3_B8464(m, collision);
    control.type = 0;
    CTRLSetTranslation(&control, 50.0f, -20.0f, 95.0f);
    CTRLBuildMatrix(&control, m);
    fn_3_B8464(m, collision);
    if (lbl_3_common_bss_350E4._3C[*n] != 0) {
        fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
        (*n)++;
    }
}

// .text:0x000F6938 size:0x15C mapped:0x807359CC
void fn_3_F6938(s32* n) {
    Mtx m;
    Control control;
    s32 i;
    s32 idx;
    StaC5Draw* draw;
    struct StadiumObjectCollision* collision;
    u16 start;

    for (i = 0; i < lbl_3_bss_B220.count; i++) {
        start = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
        idx = lbl_3_bss_B21F + i;
        lbl_3_common_bss_350E4._44[start] = idx;
        lbl_3_common_bss_350E4._3C[*n]++;
        draw = &lbl_3_common_bss_350E4._00[idx];
        collision = draw->_78;
        control.type = 0;
        CTRLSetTranslation(&control, lbl_3_data_1B884[draw->_9C].pos.x, -lbl_3_data_1B884[draw->_9C].pos.y,
                           lbl_3_data_1B884[draw->_9C].pos.z);
        CTRLSetScale(&control, 1.5f, 1.5f, 1.5f);
        CTRLBuildMatrix(&control, m);
        fn_3_B8574();
        fn_3_B8464(m, collision);
        fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
        (*n)++;
    }
}

// .text:0x000F66C8 size:0x270 mapped:0x8073575C
void fn_3_F66C8(void) {
    return;
}

// .text:0x000F65C8 size:0x100 mapped:0x8073565C
void fn_3_F65C8(s32* n) {
    Mtx m;
    Control control;
    StaC5Draw* draw;
    struct StadiumObjectCollision* collision;
    u16 start;

    draw = &lbl_3_common_bss_350E4._00[lbl_3_bss_B21A];
    start = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
    lbl_3_common_bss_350E4._44[start] = lbl_3_bss_B21A;
    lbl_3_common_bss_350E4._3C[*n]++;
    collision = draw->_78;
    control.type = 0;
    CTRLBuildMatrix(&control, m);
    fn_3_B8464(m, collision);
    fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
    (*n)++;
}

// .text:0x000F6504 size:0xC4 mapped:0x80735598
struct StadiumObjectCollision* fn_3_F6504(s32 idx, MtxPtr mtx) {
    if (lbl_3_common_bss_350E4._00[idx]._9D == 2) {
        if (lbl_3_common_bss_350E4._00[idx]._C6 < 3 && g_Ball.ballState != BALL_STATE_HELD) {
            CTRLBuildMatrix(&lbl_3_common_bss_350E4._00[idx].control, mtx);
        } else {
            return NULL;
        }
    } else if (lbl_3_common_bss_350E4._00[idx]._9D == 0) {
        if ((u8)lbl_3_common_bss_350E4._00[idx]._C1 == 2) {
            return NULL;
        }
        if (g_Ball.AtBat_ContactResult >= 2) {
            return NULL;
        }
        CTRLBuildMatrix(&lbl_3_common_bss_350E4._00[idx].control, mtx);
    } else {
        CTRLBuildMatrix(&lbl_3_common_bss_350E4._00[idx].control, mtx);
    }
    return lbl_3_common_bss_350E4._00[idx]._78;
}

// .text:0x000F6084 size:0x480 mapped:0x80735118
void fn_3_F6084(void) {
    return;
}

// .text:0x000F5F4C size:0x138 mapped:0x80734FE0
void fn_3_F5F4C(MtxPtr mtx) {
    Vec pos;
    u32 i;
    StaC5Draw* draw;
    StadiumSort1D58* sort;
    f32 near;

    memcpy(&pos, &g_Ball.AtBat_Contact_BallPos, sizeof(Vec));
    PSMTXMultVec(mtx, &pos, &pos);
    for (i = 0; i < lbl_3_common_bss_350E4._30; i++) {
        sort = &lbl_3_common_bss_350E4._14[i];
        draw = &lbl_3_common_bss_350E4._00[sort->index];
        if (draw->_90_7) {
            if (draw->_9D == 1) {
                sort->depth = 1.0f;
            } else if (sort->depth < (near = 2.0f + pos.z)) {
                sort->depth = 1.0f;
            } else if (sort->depth > 10.0f + pos.z) {
                sort->depth = 0.25f;
            } else {
                sort->depth = 1.0 - 0.75f * ((sort->depth - near) / 8);
            }
        }
    }
}

// .text:0x000F5F28 size:0x24 mapped:0x80734FBC
s32 fn_3_F5F28(const void* a, const void* b) {
    f32 da = *(const f32*)a;
    f32 db = *(const f32*)b;

    if (da < db) {
        return -1;
    }
    return da > db;
}

// .text:0x000F5EFC size:0x2C mapped:0x80734F90
s32 fn_3_F5EFC(const void* a, const void* b) {
    u32 da = *(const u32*)a;
    u32 db = *(const u32*)b;

    if (da < db) {
        return -1;
    }
    return da > db;
}

// .text:0x000F5E78 size:0x84 mapped:0x80734F0C
s32 fn_3_F5E78(u8 id) {
    u32 i;
    StadiumSort1D58* sort = &lbl_3_common_bss_350E4._14[lbl_3_common_bss_350E4._30];

    for (i = lbl_3_common_bss_350E4._30; i != 0; i--) {
        if (id == sort[-1].index) {
            return i - 1;
        }
        sort--;
    }
    OSPanic("sta_c5.c", 0x637, "//OZ \x96\xDF\x82\xE8\x92\x6C\x82\xAA\x82\xA0\x82\xE8\x82\xDC\x82\xB9\x82\xF1\n");
    return 0;
}

// .text:0x000F5C30 size:0x248 mapped:0x80734CC4
void fn_3_F5C30(StaC5Ball* obj) {
    obj->pos.x = lbl_3_data_1B884[obj->_9C].pos.x;
    obj->pos.y = lbl_3_data_1B884[obj->_9C].pos.y;
    obj->pos.z = lbl_3_data_1B884[obj->_9C].pos.z;
    obj->_C0 = -lbl_3_data_1B884[obj->_9C].rotY;
    obj->control.type = 0;
    CTRLSetTranslation(&obj->control, obj->pos.x, -obj->pos.y, obj->pos.z);
    CTRLSetRotation(&obj->control, 0.0f, obj->_C0, 0.0f);
    obj->vel.x = obj->vel.y = obj->vel.z = 0.0f;
    if (obj->_A4 != NULL) {
        if (obj->_A4->_08 != NULL) {
            fn_80033964(obj->_A4);
            obj->_A4 = NULL;
        } else {
            obj->_A4 = NULL;
        }
    }
    if (obj->_A0 != NULL) {
        fn_3_F3BB0(obj->_A0);
    }
    obj->_99 = 1;
    obj->_C4 = 0;
    if (lbl_3_data_1B820 != -1) {
        fn_3_8B890(lbl_3_data_1B820);
        lbl_3_data_1B820 = -1;
    }
}

// .text:0x000F56CC size:0x564 mapped:0x80734760
void fn_3_F56CC(void) {
    return;
}

// .text:0x000F4FBC size:0x710 mapped:0x80734050
void fn_3_F4FBC(void) {
    return;
}

// .text:0x000F4DAC size:0x210 mapped:0x80733E40
void fn_3_F4DAC(void) {
    Vec vel;
    Vec dir;
    Vec forward = { 0.0f, 0.0f, 1.0f };
    u8 step = 100 / lbl_3_bss_B220.count;
    u8 n = 0;
    f32 speed;
    f32 angle;
    f32 t;
    u8 roll;
    StaC5Draw* draw;

    vel.x = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
    vel.y = 0.0f;
    vel.z = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z;
    PSVECNormalize(&vel, &dir);
    speed = PSVECMag(&vel);
    angle = 57.29578f * (f32)acos(PSVECDotProduct(&dir, &forward));
    if (angle < 18.0f) {
        roll = fn_3_B7F70(100);
        while (roll / step != 0) {
            step += 100 / lbl_3_bss_B220.count;
            n++;
        }
        draw = &lbl_3_common_bss_350E4._00[n + lbl_3_bss_B21F];
    } else if (dir.x < 0.0f) {
        draw = &lbl_3_common_bss_350E4._00[lbl_3_bss_B21F];
    } else {
        draw = &lbl_3_common_bss_350E4._00[lbl_3_bss_B21F + 1];
    }
    t = angle / 45.0f;
    if (speed > 90.0 * (1.0 - t) + 73.0f * t) {
        return;
    }
    if (speed > 52.0f) {
        draw->_C4 = 1;
    } else {
        draw->_C4 = 2;
    }
}

// .text:0x000F4D00 size:0xAC mapped:0x80733D94
void fn_3_F4D00(StaC5Ball* obj) {
    Vec d;
    Vec target;

    PSVECAdd(&obj->pos, &obj->vel, &obj->pos);
    CTRLSetTranslation(&obj->control, obj->pos.x, -obj->pos.y, obj->pos.z);
    target.x = lbl_3_data_1B884[obj->_9C].pos.x;
    target.y = lbl_3_data_1B884[obj->_9C].pos.y;
    target.z = lbl_3_data_1B884[obj->_9C].pos.z;
    PSVECSubtract(&target, &obj->pos, &d);
    obj->vel.x = 0.2f * d.x;
    obj->vel.z = 0.2f * d.z;
}

// .text:0x000F4C4C size:0xB4 mapped:0x80733CE0
void fn_3_F4C4C(StaC5Ball* obj) {
    f32 angle = -obj->_C0;

    angle = 0.017453292f * angle;

    obj->vel.x = 3.0f * sinf_kludge(angle);
    obj->vel.y = 0.0f;
    obj->vel.z = 3.0f * -cosf_kludge(angle);
    PSVECScale(&obj->vel, -1.0f, &obj->vel);
}

// .text:0x000F4BA0 size:0xAC mapped:0x80733C34
void fn_3_F4BA0(StaC5Ball* obj) {
    Vec target;
    Vec d;

    PSVECAdd(&obj->pos, &obj->vel, &obj->pos);
    CTRLSetTranslation(&obj->control, obj->pos.x, -obj->pos.y, obj->pos.z);
    target.x = lbl_3_data_1B884[obj->_9C].pos.x;
    target.y = lbl_3_data_1B884[obj->_9C].pos.y;
    target.z = lbl_3_data_1B884[obj->_9C].pos.z;
    PSVECSubtract(&target, &obj->pos, &d);
    obj->vel.x = 0.2f * d.x;
    obj->vel.z = 0.2f * d.z;
}

// .text:0x000F46A0 size:0x500 mapped:0x80733734
void fn_3_F46A0(void) {
    return;
}

// .text:0x000F469C size:0x4 mapped:0x80733730
void fn_3_F469C(void) {
    return;
}

// .text:0x000F466C size:0x30 mapped:0x80733700
void fn_3_F466C(void) {
    fn_3_27648();
    g_FieldingLogic._13B = 1;
}

// .text:0x000F42A0 size:0x3CC mapped:0x80733334
void fn_3_F42A0(void) {
    return;
}

// .text:0x000F3EFC size:0x3A4 mapped:0x80732F90
void fn_3_F3EFC(void) {
    return;
}

// .text:0x000F3CD0 size:0x22C mapped:0x80732D64
BOOL fn_3_F3CD0(StaC5Emitter* emitter) {
    StaC5Particle* p = emitter->particles;
    u32 alive = 0;

    fn_80033620(emitter);
    do {
        if (p->delay <= 0 && p->life != 0) {
            fn_80033F64(p->_38, p->_3C, p->_20);
            fn_80033CC8(p, emitter->_10);
            if (-p->delay < 5) {
                p->_38 += (p->_28 - 10.0) / 5.0;
                p->_3C = p->_38;
                p->color[3] += 12.0;
            } else {
                p->_38 += (p->_2C - p->_28) / 495.0f;
                p->_3C = p->_38;
                p->color[3] += -60.0 / (495 - p->index);
                if (p->color[3] >= 60) {
                    p->color[3] = 0;
                }
            }
            p->pos.x += p->vel.x;
            p->pos.y += p->vel.y;
            p->pos.z += p->vel.z;
            p->_20 += p->_1C * p->_24;
            p->life--;
        }
        p->delay--;
        if (p->life != 0) {
            alive++;
        }
    } while ((p = p->next) != NULL);
    return alive == 0;
}

// .text:0x000F3BB0 size:0x120 mapped:0x80732C44
void fn_3_F3BB0(StaC5Draw* draw) {
    fn_3_F3AE0(draw);
    draw->_C1 = 0;
    draw->_90_7 = 1;
    draw->_74 = &lbl_8036E548._6C->models[lbl_3_bss_B219 + draw->_9C];
    draw->_C4 = 0;
    draw->_99 = 1;
}

// .text:0x000F3AE0 size:0xD0 mapped:0x80732B74
void fn_3_F3AE0(StaC5Draw* draw) {
    draw->_AC = lbl_3_data_1B884[draw->_9C].pos.x;
    draw->_B0 = lbl_3_data_1B884[draw->_9C].pos.z;
    fn_3_F3A5C(draw, draw->_AC, 10.0f, draw->_B0, -lbl_3_data_1B884[draw->_9C].rotY);
}

// .text:0x000F3A5C size:0x84 mapped:0x80732AF0
void fn_3_F3A5C(StaC5Draw* draw, f32 x, f32 y, f32 z, f32 rotY) {
    draw->_A0.x = x;
    draw->_A0.y = y;
    draw->_A0.z = z;
    draw->_B4 = rotY;
    draw->control.type = 0;
    CTRLSetTranslation(&draw->control, draw->_A0.x, -draw->_A0.y, draw->_A0.z);
    CTRLSetRotation(&draw->control, 0.0f, rotY, 0.0f);
}

// .text:0x000F3A04 size:0x58 mapped:0x80732A98
void fn_3_F3A04(StaC5Draw* draw) {
    u32 i;
    StaC5Actor* actor = draw->_74->_00;

    for (i = 0; i < actor->_06; i++) {
    }
}

// .text:0x000F38D4 size:0x130 mapped:0x80732968
void fn_3_F38D4(void) {
    u32 i;

    for (i = 0; i < 7; i++) {
        lbl_3_bss_B244[i] = fn_3_F37BC(6, i);
    }
}

// .text:0x000F37BC size:0x118 mapped:0x80732850
u32 fn_3_F37BC(u32 n, u32 k) {
    u32 result = 1;
    u32 i;

    for (i = 1; i <= k; i++) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

// .text:0x000F31E0 size:0x5DC mapped:0x80732274
void fn_3_F31E0(void) {
    return;
}

// .text:0x000F2FFC size:0x1E4 mapped:0x80732090
void fn_3_F2FFC(void) {
    return;
}

// .text:0x000F2938 size:0x6C4 mapped:0x807319CC
void fn_3_F2938(void) {
    return;
}

// .text:0x000F2724 size:0x214 mapped:0x807317B8
void fn_3_F2724(StaC5Draw* draw, StaC5Draw* target) {
    Vec d;
    f32 sn;
    f32 cs;
    f32 m00;
    f32 m01;
    f32 m10;
    f32 m11;
    f32 x;
    f32 z;
    s32 stadium;
    u8 vol;
    SND_VOICEID voice;

    sn = sin(-(0.017453292f * draw->_B4));
    cs = cos(-(0.017453292f * draw->_B4));
    PSVECSubtract(&target->_A0, &draw->_A0, &d);
    d.y = 0.0f;
    m00 = cos(-(0.017453292f * draw->_B4));
    m01 = sin(-(0.017453292f * draw->_B4));
    m10 = sin(-(0.017453292f * draw->_B4));
    m11 = cos(-(0.017453292f * draw->_B4));
    x = d.x * m00 + d.z * m01;
    z = d.x * -m10 + d.z * m11;
    x = fabs(x);
    z = fabs(z);
    if (x <= 3.0 && z <= 1.75) {
        target->_C6 = 5;
        stadium = g_d_GameSettings.StadiumID;
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            vol = lbl_3_data_84B8[11][0];
        } else {
            vol = lbl_3_data_8404[stadium][11][0];
        }
        voice = sndFXStartEx(lbl_3_data_81DC[stadium] + 11, vol, 63, 0);
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            vol = lbl_3_data_84B8[11][1];
        } else {
            vol = lbl_3_data_8404[stadium][11][1];
        }
        sndFXCtrl(voice, 91, vol);
    }
}

// .text:0x000F2448 size:0x2DC mapped:0x807314DC
void fn_3_F2448(void) {
    return;
}

// .text:0x000F22FC size:0x14C mapped:0x80731390
void fn_3_F22FC(StaC5Draw* draw, s8 idx) {
    Vec dir;
    StaC5Draw* other;
    u32 i;

    PSVECSubtract(&g_Fielders[idx].pos, &draw->_A0, &dir);
    dir.y = 0.0f;
    PSVECNormalize(&dir, &dir);
    fn_3_253A4(idx, fn_3_9FB8C(dir.x, dir.z));
    fn_800527C4(&draw->_A0);
    for (i = 0; i < lbl_3_bss_B21C; i++) {
        other = &lbl_3_common_bss_350E4._00[lbl_3_bss_B21B + i];
        if (other->_C6 == 3 && other->_C1 == idx) {
            other->_B8 = 0.017453292f * (-other->_AC - 180.0f);
            other->_C6 = 4;
            other->_BC = 0.5f;
            g_Fielders[idx]._217--;
        }
    }
}

// .text:0x000F1E2C size:0x4D0 mapped:0x80730EC0
void fn_3_F1E2C(void) {
    return;
}

// .text:0x000F193C size:0x4F0 mapped:0x807309D0
void fn_3_F193C(void) {
    return;
}

// .text:0x000F18A4 size:0x98 mapped:0x80730938
void fn_3_F18A4(StaC5Draw* draw) {
    StaC5Model* model = &lbl_8036E548._6C->models[lbl_3_bss_B218];

    draw->_74 = model;
    model->_5C = 0.0f;
    model->_59 = 1;
    fn_800B4CA0(model->_00, model->_5C);
    draw->_B4 += 180.0;
    AnimateActorBones(model->_00);
}

// .text:0x000F1750 size:0x154 mapped:0x807307E4
void fn_3_F1750(StaC5Draw* draw) {
    StaC5Model* model = draw->_74;

    if (!fn_800B4A94(model->_00)) {
        fn_3_F3BB0(draw);
    } else {
        AnimateActorBones(model->_00);
    }
}

// .text:0x000F1674 size:0xDC mapped:0x80730708
void fn_3_F1674(void) {
    s32 stadium;
    u8 vol;
    SND_VOICEID voice;

    stadium = g_d_GameSettings.StadiumID;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[5][0];
    } else {
        vol = lbl_3_data_8404[stadium][5][0];
    }
    voice = sndFXStartEx(lbl_3_data_81DC[stadium] + 5, vol, 63, 0);
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[5][1];
    } else {
        vol = lbl_3_data_8404[stadium][5][1];
    }
    sndFXCtrl(voice, 91, vol);
    fn_3_65A8();
    fn_3_F466C();
}

// .text:0x000F1518 size:0x15C mapped:0x807305AC
void fn_3_F1518(StaC5Draw* draw) {
    draw->_C5 = lbl_3_data_1B9A4[draw->_9C]._14;
    draw->_C6 = 1;
    draw->_C7 = 0;
    draw->_C1 = -1;
    if (!draw->_90_7) {
        draw->_90_7 = 1;
    }
    draw->_99 = 1;
    draw->_B0 = 0.0f;
    fn_3_F1448(draw);
    fn_3_B97DC(draw->_74, lbl_3_bss_B154[0]);
    draw->_74->_58 = 1;
    draw->_C0 = 0;
}

// .text:0x000F1448 size:0xD0 mapped:0x807304DC
void fn_3_F1448(StaC5Draw* draw) {
    draw->_A0.x = lbl_3_data_1B9A4[draw->_9C].pos.x;
    draw->_A0.y = lbl_3_data_1B9A4[draw->_9C].pos.y;
    draw->_A0.z = lbl_3_data_1B9A4[draw->_9C].pos.z;
    draw->_AC = -lbl_3_data_1B9A4[draw->_9C].rotY;
    draw->control.type = 0;
    CTRLSetTranslation(&draw->control, draw->_A0.x, -draw->_A0.y, draw->_A0.z);
    CTRLSetRotation(&draw->control, 0.0f, draw->_AC, 0.0f);
    CTRLSetScale(&draw->control, 1.0f, 1.0f, 1.0f);
}

// .text:0x000F13F8 size:0x50 mapped:0x8073048C
void fn_3_F13F8(StaC5Draw* draw) {
    StaC5Actor* actor = draw->_74->_00;
    u32 i;

    for (i = 0; i < actor->_06; i++) {
        StaC5Bone* bone = actor->_18[i];
        bone->_60 = 0;
        bone->_A4 = 0;
    }
    draw->_74->_58 = 0;
}

// .text:0x000F0FA4 size:0x454 mapped:0x80730038
void fn_3_F0FA4(void) {
    return;
}

// .text:0x000F082C size:0x778 mapped:0x8072F8C0
void fn_3_F082C(void) {
    return;
}

// .text:0x000F0224 size:0x608 mapped:0x8072F2B8
void fn_3_F0224(void) {
    return;
}

// .text:0x000F0184 size:0xA0 mapped:0x8072F218
void fn_3_F0184(void) {
    return;
}

// .text:0x000EFB54 size:0x630 mapped:0x8072EBE8
void fn_3_EFB54(void) {
    return;
}

// .text:0x000EF930 size:0x224 mapped:0x8072E9C4
void fn_3_EF930(StaC5Draw* draw) {
    Quaternion q;
    Quaternion rot;
    Vec cross;
    Vec vel;
    Vec down;
    f32 angle;
    Vec axis = { 0.0f, -1.0f, 0.0f };

    vel.x = 0.3 * cosf_kludge(draw->_B8);
    vel.y = draw->_BC;
    vel.z = 0.3 * sinf_kludge(draw->_B8);
    PSVECAdd(&draw->_A0, &vel, &draw->_A0);
    if (draw->_BC < 0.0f && draw->_A0.y - 1.0f < 0.0f) {
        draw->_A0.x -= vel.x;
        draw->_A0.y = 1.0f;
        draw->_A0.z -= vel.z;
        draw->_C6 = 6;
        draw->_C7 = 75;
    } else {
        draw->_BC -= 0.044;
    }
    C_QUATRotAxisRad(&rot, &axis, -(0.017453292f * draw->_AC));
    vel.y = -vel.y;
    down.x = -vel.x;
    down.y = -0.5f;
    down.z = -vel.z;
    PSVECNormalize(&vel, &vel);
    PSVECNormalize(&down, &down);
    PSVECCrossProduct(&down, &vel, &cross);
    angle = acos(PSVECDotProduct(&vel, &down));
    if (1.0f != angle && -1.0f != angle) {
        C_QUATRotAxisRad(&q, &cross, angle);
        PSQUATMultiply(&q, &rot, &q);
        PSQUATNormalize(&q, &q);
        CTRLSetQuat(&draw->control, q.x, q.y, q.z, q.w);
    }
    CTRLSetTranslation(&draw->control, draw->_A0.x, -draw->_A0.y, draw->_A0.z);
}

// .text:0x000EF890 size:0xA0 mapped:0x8072E924
void fn_3_EF890(StaC5Draw* draw) {
    fn_3_F13F8(draw);
    CTRLSetScale(&draw->control, 2.0f, 0.1f, 2.0f);
    draw->_C6 = 6;
    draw->_C7 = 75;
}

// .text:0x000EF800 size:0x90 mapped:0x8072E894
void fn_3_EF800(StaC5Draw* draw) {
    if (draw->_C7 == 0) {
        CTRLSetTranslation(&draw->control, draw->_A0.x, 100.0f, draw->_A0.z);
    } else {
        if (draw->_C7 % 6 == 0) {
            draw->_90_7 = 0;
        } else {
            draw->_90_7 = 1;
        }
        draw->_C7--;
    }
}

// .text:0x000EF7B4 size:0x4C mapped:0x8072E848
void fn_3_EF7B4(void) {
    return;
}

// .text:0x000EF55C size:0x258 mapped:0x8072E5F0
void fn_3_EF55C(void) {
    return;
}

// .text:0x000EF408 size:0x154 mapped:0x8072E49C
void fn_3_EF408(StaC5Draw* draw) {
    Vec to;
    Vec facing;
    Vec cross;
    f32 angle;
    f32 dot;

    to.x = lbl_3_data_1B9A4[draw->_9C].pos.x - draw->_A0.x;
    to.y = 0.0f;
    to.z = lbl_3_data_1B9A4[draw->_9C].pos.z - draw->_A0.z;
    PSVECNormalize(&to, &to);
    angle = -(0.017453292f * draw->_AC);
    facing.x = cos(angle);
    facing.y = 0.0f;
    facing.z = sin(angle);
    PSVECNormalize(&facing, &facing);
    dot = PSVECDotProduct(&to, &facing);
    if (dot < -1.0) {
        dot = -1.0f;
    }
    draw->_B4 = 57.29578f * (f32)acos(dot);
    PSVECCrossProduct(&to, &facing, &cross);
    if (cross.y < 0.0f) {
        draw->_C4 = 1;
    } else {
        draw->_C4 = -1;
    }
    draw->_C6 = 0;
}

// .text:0x000EF3D4 size:0x34 mapped:0x8072E468
void fn_3_EF3D4(StaC5Draw* draw, u8 idx) {
    fn_3_B97DC(draw->_74, lbl_3_bss_B154[idx]);
}

// .text:0x000EF21C size:0x1B8 mapped:0x8072E2B0
void fn_3_EF21C(void) {
    return;
}

// .text:0x000EF218 size:0x4 mapped:0x8072E2AC
void fn_3_EF218(void) {
    return;
}

// .text:0x000EEFD4 size:0x244 mapped:0x8072E068
void fn_3_EEFD4(s32 idx) {
    StaC5Draw* draw = &lbl_3_common_bss_350E4._00[idx];
    Vec dir;
    Vec ref = { 1.0f, 0.0f, 0.0f };
    Vec pos;
    f32 angle;
    s32 stadium;
    u8 vol;
    SND_VOICEID voice;

    if (draw->_C6 < 3) {
        dir.x = g_Ball.physicsSubstruct.velocity.x;
        dir.y = 0.0f;
        dir.z = g_Ball.physicsSubstruct.velocity.z;
        PSVECNormalize(&dir, &dir);
        angle = acosf_kludge(PSVECDotProduct(&ref, &dir));
        if (dir.z < 0.0f) {
            angle = 360.0 * 0.017453292f - angle;
        }
        draw->_B8 = angle;
        draw->_BC = 0.5f;
        draw->_C6 = 4;
        fn_3_F13F8(draw);
        if (g_Ball.AtBat_ContactResult != 2 && gameInitOptions.starSkillsSetting) {
            CTRLGetTranslation(&draw->control, &pos.x, &pos.y, &pos.z);
            fn_3_CB7E8(pos.x, pos.y - 5.0f, pos.z);
            draw->_C8 = 1;
        }
        stadium = g_d_GameSettings.StadiumID;
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            vol = lbl_3_data_84B8[9][0];
        } else {
            vol = lbl_3_data_8404[stadium][9][0];
        }
        voice = sndFXStartEx(lbl_3_data_81DC[stadium] + 9, vol, 63, 0);
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            vol = lbl_3_data_84B8[9][1];
        } else {
            vol = lbl_3_data_8404[stadium][9][1];
        }
        sndFXCtrl(voice, 91, vol);
        fn_3_F466C();
    }
}

// .text:0x000EEFD0 size:0x4 mapped:0x8072E064
void fn_3_EEFD0(void) {
    return;
}

// .text:0x000EEFA4 size:0x2C mapped:0x8072E038
void fn_3_EEFA4(void) {
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
}

// .text:0x000EEF24 size:0x80 mapped:0x8072DFB8
void fn_3_EEF24(void) {
    return;
}

// .text:0x000EEE3C size:0xE8 mapped:0x8072DED0
void fn_3_EEE3C(void) {
    return;
}

// .text:0x000EECF4 size:0x148 mapped:0x8072DD88
void fn_3_EECF4(void) {
    u32 x;
    u32 y;
    s32 offset;

    lbl_3_bss_B11C[0][0] = 0.01f;
    lbl_3_bss_B11C[0][1] = 0.0f;
    lbl_3_bss_B11C[0][2] = 0.0f;
    lbl_3_bss_B11C[1][0] = 0.0f;
    lbl_3_bss_B11C[1][1] = 0.01f;
    lbl_3_bss_B11C[1][2] = 0.0f;
    GXSetIndTexMtx(GX_ITM_0, lbl_3_bss_B11C, 2);
    lbl_3_bss_B118 = fn_3_B9534(0x10, 0x10, &lbl_3_bss_B134);
    if (lbl_3_bss_B118 == NULL) {
        OSErrorLine(4136, "error\n");
    }
    for (y = 0; y < 0x10; y++) {
        for (x = 0; x < 0x10; x++) {
            offset = fn_800247E4(x, y, 0x10, 2);
            lbl_3_bss_B118[offset] = (u8)(rand() % 200) + 27;
            lbl_3_bss_B118[offset + 1] = (u8)(rand() % 200) + 27;
        }
    }
    memset(lbl_3_bss_AF18, 1, sizeof(lbl_3_bss_AF18));
}

// .text:0x000EEB94 size:0x160 mapped:0x8072DC28
void fn_3_EEB94(void) {
    u32 x;
    u32 y;
    s32 offset;
    s32 s;
    s32 t;

    for (y = 0; y < 0x10; y++) {
        for (x = 0; x < 0x10; x++) {
            offset = fn_800247E4(x, y, 0x10, 2);
            s = lbl_3_bss_B118[offset];
            t = lbl_3_bss_B118[offset + 1];
            s += lbl_3_bss_AF18[offset] * (rand() % 14 + 8);
            t += lbl_3_bss_AF18[offset + 1] * (rand() % 14 + 8);
            if (s >= 227) {
                s--;
                lbl_3_bss_AF18[offset] = -1;
            } else if (s <= 27) {
                s++;
                lbl_3_bss_AF18[offset] = 1;
            }
            if (t >= 227) {
                t--;
                lbl_3_bss_AF18[offset + 1] = -1;
            } else if (t <= 27) {
                t++;
                lbl_3_bss_AF18[offset + 1] = 1;
            }
            lbl_3_bss_B118[offset] = s;
            lbl_3_bss_B118[offset + 1] = t;
        }
    }
}

// .text:0x000EE96C size:0x228 mapped:0x8072DA00
void fn_3_EE96C(Vec* pos) {
    Mtx view;
    Vec dir;
    Vec down = { 0.0f, -1.0f, 0.0f };
    camera_803c639c_s* camera;
    f32 dist;
    f32 scale;
    f32 range;
    s32 scaleS;
    s32 scaleT;

    camera = fn_80052768_getCamera(fn_8005268C());
    PSVECSubtract(&camera->eye, &camera->target, &dir);
    if (PSVECMag(&dir)) {
        PSVECNormalize(&dir, &dir);
    } else {
        dir.y = 0.0f;
        dir.x = 0.0f;
        dir.z = 1.0f;
    }
    acos(PSVECDotProduct(&dir, &down));
    PSVECSubtract(&camera->eye, pos, &dir);
    range = dist = PSVECMag(&dir);
    if (dist < 20.0f) {
        dist = 20.0f;
    }
    PSMTXCopy(camera->view, view);
    scale = 0.19999999f / dist;
    lbl_3_bss_B11C[0][0] = scale;
    lbl_3_bss_B11C[1][1] = scale * (f32)(1.0 - fabs(0.5f * (down.y * view[1][1])));
    if (range < 35.0f) {
        scaleS = GX_ITS_16;
        scaleT = GX_ITS_16;
    } else if (range < 55.0f) {
        scaleS = GX_ITS_8;
        scaleT = GX_ITS_8;
    } else {
        scaleS = GX_ITS_4;
        scaleT = GX_ITS_4;
    }
    lbl_3_bss_AEF4 = NULL;
    DCFlushRange(lbl_3_bss_B118, 0x200);
    GXSetIndTexMtx(GX_ITM_0, lbl_3_bss_B11C, 2);
    GXLoadTexObj(&lbl_3_bss_B134, GX_TEXMAP7);
    GXSetIndTexOrder(GX_IND_TEX_STAGE_0, GX_TEXCOORD0, GX_TEXMAP7);
    GXSetNumIndStages(1);
    GXSetIndTexCoordScale(GX_IND_TEX_STAGE_0, scaleS, scaleT);
    GXSetTevIndWarp(GX_TEVSTAGE0, GX_IND_TEX_STAGE_0, GX_TRUE, GX_FALSE, GX_ITM_0);
}

// .text:0x000EE67C size:0x2F0 mapped:0x8072D710
void fn_3_EE67C(void) {
    return;
}

// .text:0x000EE388 size:0x2F4 mapped:0x8072D41C
void fn_3_EE388(void) {
    return;
}

// .text:0x000EE100 size:0x288 mapped:0x8072D194
void fn_3_EE100(void) {
    return;
}

// .text:0x000EE0BC size:0x44 mapped:0x8072D150
s32 fn_3_EE0BC(u32 flags) {
    switch ((flags >> 4) & 0xF) {
    case 0:
    case 1:
        return 1;
    case 2:
    case 3:
        return 2;
    case 4:
        return 4;
    default:
        return 0;
    }
}

// .text:0x000EDFAC size:0x110 mapped:0x8072D040
void fn_3_EDFAC(void) {
    if (g_GameLogic.gameStatus == GAME_STATUS_MINIGAME_READY) {
        return;
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_PAUSED) {
        if (!lbl_3_bss_B15C) {
            fn_3_8B890(lbl_3_bss_AEFC);
            fn_3_8B890(lbl_3_bss_AEF8);
            lbl_3_bss_B15C = 1;
        }
        return;
    }
    if (lbl_3_bss_B15C) {
        lbl_3_bss_AEFC = fn_3_8BBC4(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 6, NULL, NULL, 4);
        lbl_3_bss_AEF8 = fn_3_8BBC4(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 7, NULL, NULL, 5);
        lbl_3_bss_B15C = 0;
    } else {
        fn_3_8BA60(lbl_3_bss_AEFC, NULL, NULL);
        fn_3_8BA60(lbl_3_bss_AEF8, NULL, NULL);
    }
}
