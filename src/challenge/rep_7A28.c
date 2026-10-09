#include "challenge/rep_7A28.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"
#include "Dolphin/gx.h"
#include "Dolphin/pad.h"
#include "string.h"

// A particle effect editor: a debug camera, an emitter position and a menu per effect

// rep_7978's debug camera
typedef struct Camera7A28 {
    /* 0x00 */ Mtx _00;
    /* 0x30 */ Mtx44 _30;
    /* 0x70 */ Vec _70;
    /* 0x7C */ Vec _7C;
    /* 0x88 */ Vec _88;
    /* 0x94 */ u8 _94[0xDC - 0x94];
} Camera7A28; // size: 0xDC

// One line of a debug menu: an integer setting with its range and steps
typedef struct MenuItem7A28 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ char* _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32* _1C;
    /* 0x20 */ s32 _20[3];
} MenuItem7A28; // size: 0x2C

typedef struct Menu7A28 {
    /* 0x00 */ char* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ MenuItem7A28* _18;
} Menu7A28; // size: 0x1C

typedef struct Task7A28Parent {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u16 _10;
} Task7A28Parent;

typedef struct Task7A28 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ Task7A28Parent* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ Camera7A28* _14;
    /* 0x18 */ void* _18;
    /* 0x1C */ Menu7A28* _1C;
    /* 0x20 */ Vec _20;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ f32 _30;
    /* 0x34 */ u16 _34;
    /* 0x36 */ s8 _36;
    /* 0x37 */ s8 _37;
} Task7A28;

// A trail or burst emitter's settings
typedef struct Emitter7A28 {
    /* 0x00 */ void* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32 _34;
    /* 0x38 */ s32 _38;
    /* 0x3C */ s32 _3C;
    /* 0x40 */ u32 _40;
    /* 0x44 */ s32 _44;
    /* 0x48 */ s32 _48;
    /* 0x4C */ s32 _4C;
} Emitter7A28; // size: 0x50

// A fireball's settings
typedef struct Fireball7A28 {
    /* 0x00 */ void* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24[8];
} Fireball7A28; // size: 0x44

extern void* lbl_803CC1B8;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void* ARAMTransfer(void* entry, int arg1, int arg2, u32 aram);
extern void convertTextureHeader(void* tex);
extern void fn_800AD038(void* arg0);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80030D88(Vec* pos, Vec* dir, Emitter7A28* emitter, s32 n);
extern void fn_8002F5F4(Vec* pos, Vec* dir, Fireball7A28* fireball);
extern void fn_80030470(Vec* pos, Vec* dir, Vec* back, Emitter7A28* emitter, s32 n);
extern void fn_80048820(Menu7A28* menu, u16 held, u16 pressed, u16 repeat, u8 trigger);
extern void fn_80048BEC(Menu7A28* menu, s32 arg1, s32 arg2);
extern void fn_8003414C(Mtx mtx);
extern void minigamesGXStuff(void);
extern void GXDrawSphere1(u8 subdivisions);
extern void fn_1_AF4(s32 arg0, s32 arg1, f32 arg2);
extern void fn_1_F2C(s32 arg0, s32 arg1, s32 arg2);
extern void fn_1_26D28(Camera7A28* cam, u16 held, u16 pressed, u16 repeat, s8* stick);
extern void fn_1_272DC(Camera7A28* cam, s32 id);
extern void fn_1_27330(Camera7A28* cam);
extern void fn_1_273D8(Camera7A28* cam);

static void (*lbl_1_data_108E8[2])(void) = { fn_1_27AD4, fn_1_276CC };
static void (*lbl_1_data_108F0[2])(void) = { fn_1_27AD0, fn_1_27594 };
static s32 lbl_1_data_108F8[4] = { 0x40B, 0x40046100, 0x0E641000, 0x24B48 };

static Emitter7A28 lbl_1_data_10908[3] = {
    { NULL, 0, 5, 280000, 0, 0, 4, 2, 120000, 90000, 0, 128, 1000000, 1000000, -500000, 500000, 0xFFFFFF00, 0,
      -28000, 1 },
    { NULL, 0, 10, 78000, 60000, 50000, 12, 6, 109000, 101000, 0, 40, 4500000, 9500000, -1000000, 4500000, 0xFFFFFF00,
      0, 0, 0 },
    { NULL, 0, 3, 90000, 100000, 10000, 20, 10, 103000, 105999, 0, 60, 10000000, 18000000, 1000000, -1000000,
      0x3C3C3C00, 0, 0, 0 },
};

static Fireball7A28 lbl_1_data_109F8 = {
    NULL, 20, 8, 7, 250000, 50000, 550000, 0, 255, { 12, 13, 14, 15, 16, 17, 18, 19 },
};

static MenuItem7A28 lbl_1_data_10A3C[15] = {
    { 0, "NUM     ", 1, 100, 1, 10, 20, &lbl_1_data_10908[0]._08 },
    { 1, "SIZE    ", 10, 10000000, 100, 10, 1000, &lbl_1_data_10908[0]._0C },
    { 1, "SPEED   ", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[0]._10 },
    { 1, "SLOWDOWN", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[0]._14 },
    { 0, "LIFE    ", 1, 100, 1, 10, 20, &lbl_1_data_10908[0]._18 },
    { 0, "LIFETURN", 1, 100, 1, 10, 20, &lbl_1_data_10908[0]._1C },
    { 1, "SCALE UP", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[0]._20 },
    { 1, "SCALE DN", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[0]._24 },
    { 0, "MAXALPHA", 0, 255, 1, 10, 20, &lbl_1_data_10908[0]._2C },
    { 1, "SP ANGLE", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[0]._30 },
    { 1, "HANG MAX", 0, 18000000, 100000, 10000, 1000000, &lbl_1_data_10908[0]._34 },
    { 1, "VANG MIN", -18000000, 18000000, 100000, 10000, 1000000, &lbl_1_data_10908[0]._38 },
    { 1, "VANG MAX", -18000000, 18000000, 100000, 10000, 1000000, &lbl_1_data_10908[0]._3C },
    { 1, "BIAS    ", -10000000, 10000000, 100, 10, 1000, &lbl_1_data_10908[0]._48 },
    { 0 },
};

static MenuItem7A28 lbl_1_data_10CD0[14] = {
    { 0, "NUM     ", 1, 100, 1, 10, 20, &lbl_1_data_10908[1]._08 },
    { 1, "SIZE    ", 10, 10000000, 100, 10, 1000, &lbl_1_data_10908[1]._0C },
    { 1, "SPEED   ", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[1]._10 },
    { 1, "SLOWDOWN", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[1]._14 },
    { 0, "LIFE    ", 1, 100, 1, 10, 20, &lbl_1_data_10908[1]._18 },
    { 0, "LIFETURN", 1, 100, 1, 10, 20, &lbl_1_data_10908[1]._1C },
    { 1, "SCALE UP", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[1]._20 },
    { 1, "SCALE DN", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[1]._24 },
    { 0, "MAXALPHA", 0, 255, 1, 10, 20, &lbl_1_data_10908[1]._2C },
    { 1, "SP ANGLE", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[1]._30 },
    { 1, "HANG MAX", 0, 18000000, 100000, 10000, 1000000, &lbl_1_data_10908[1]._34 },
    { 1, "VANG MIN", -18000000, 18000000, 100000, 10000, 1000000, &lbl_1_data_10908[1]._38 },
    { 1, "VANG MAX", -18000000, 18000000, 100000, 10000, 1000000, &lbl_1_data_10908[1]._3C },
    { 0 },
};

static MenuItem7A28 lbl_1_data_10F38[14] = {
    { 0, "NUM     ", 1, 100, 1, 10, 20, &lbl_1_data_10908[2]._08 },
    { 1, "SIZE    ", 10, 10000000, 100, 10, 1000, &lbl_1_data_10908[2]._0C },
    { 1, "SPEED   ", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[2]._10 },
    { 1, "SLOWDOWN", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[2]._14 },
    { 0, "LIFE    ", 1, 100, 1, 10, 20, &lbl_1_data_10908[2]._18 },
    { 0, "LIFETURN", 1, 100, 1, 10, 20, &lbl_1_data_10908[2]._1C },
    { 1, "SCALE UP", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[2]._20 },
    { 1, "SCALE DN", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[2]._24 },
    { 0, "MAXALPHA", 0, 255, 1, 10, 20, &lbl_1_data_10908[2]._2C },
    { 1, "SP ANGLE", 0, 10000000, 100, 10, 1000, &lbl_1_data_10908[2]._30 },
    { 1, "HANG MAX", 0, 18000000, 100000, 10000, 1000000, &lbl_1_data_10908[2]._34 },
    { 1, "VANG MIN", -18000000, 18000000, 100000, 10000, 1000000, &lbl_1_data_10908[2]._38 },
    { 1, "VANG MAX", -18000000, 18000000, 100000, 10000, 1000000, &lbl_1_data_10908[2]._3C },
    { 0 },
};

static MenuItem7A28 lbl_1_data_111A0[7] = {
    { 0, "NUM     ", 2, 8, 1, 1, 1, &lbl_1_data_109F8._08 },
    { 0, "TAILNUM ", 1, 7, 1, 1, 1, &lbl_1_data_109F8._0C },
    { 1, "SIZE    ", 10, 10000000, 100, 10, 1000, &lbl_1_data_109F8._10 },
    { 1, "TAILSIZE", 10, 10000000, 100, 10, 1000, &lbl_1_data_109F8._14 },
    { 1, "LENGTH  ", 10, 10000000, 100, 10, 1000, &lbl_1_data_109F8._18 },
    { 0, "CENTER  ", 0, 7, 1, 1, 1, &lbl_1_data_109F8._1C },
    { 0 },
};

// .text:0xCA0 size:0xF4
void fn_1_28200(void) {
    Task7A28* task = lbl_803CC1B8;

    task->_10 = 0;
    fn_800AD038(lbl_80366158._08);
    task->_14 = _OSAllocFromHeap(0x20, sizeof(Camera7A28));
    fn_1_273D8(task->_14);
    task->_1C = _OSAllocFromHeap(0x20, sizeof(Menu7A28));
    task->_1C->_08 = 16;
    task->_1C->_14 = 1;
    task->_14->_88.y *= -1.0f;
    task->_20.x = 0.0f;
    task->_20.y = -1.0f;
    task->_20.z = 0.0f;
    task->_2C = 1.0f;
    task->_30 = 1.0f;
    task->_36 = 0;
    task->_37 = 0;
    task->_34 = 0;
    ((Task7A28*)lbl_803CC1B8)->_00 = fn_1_28118;
}

// .text:0xBB8 size:0xE8
void fn_1_28118(void) {
    Task7A28* task = lbl_803CC1B8;

    switch (task->_10) {
    case 0:
        task->_10++;
        task->_18 = ARAMTransfer(lbl_1_data_108F8, 0, 0, 0);
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            task->_18 = (u8*)task->_18 + *(s32*)task->_18;
            convertTextureHeader(task->_18);
            fn_1_27560(task->_18);
            ((Task7A28*)lbl_803CC1B8)->_00 = fn_1_27E98;
        }
        break;
    }
}

// .text:0x938 size:0x280
void fn_1_27E98(void) {
    Task7A28* task = lbl_803CC1B8;

    fn_1_27D6C();
    fn_1_27330(task->_14);
    fn_1_27BB8();
}

// .text:0x8F0 size:0x48
void fn_1_27E50(void) {
    fn_800AD038(lbl_80366158._08);
    ((Task7A28*)lbl_803CC1B8)->_0C->_10 = 1;
    fn_800B0A14_removeQueue();
}

// .text:0x80C size:0xE4
void fn_1_27D6C(void) {
    s8 stick[6];

    if (((Task7A28*)lbl_803CC1B8)->_34 & 1) {
        lbl_1_data_108E8[((Task7A28*)lbl_803CC1B8)->_36]();
    } else {
        memcpy(stick, &lbl_803C77B8[0]._10, 6);
        stick[0] = -stick[0];
        stick[4] = lbl_803C77B8[0]._15;
        stick[5] = lbl_803C77B8[0]._14;
        fn_1_26D28(((Task7A28*)lbl_803CC1B8)->_14, lbl_803C77B8[0]._00, lbl_803C77B8[0]._02, lbl_803C77B8[0]._04,
                   stick);
    }
    if (lbl_803C77B8[0]._02 & PAD_BUTTON_START) {
        ((Task7A28*)lbl_803CC1B8)->_34 ^= 1;
    }
}

// .text:0x658 size:0x1B4
void fn_1_27BB8(void) {
    Task7A28* task = lbl_803CC1B8;
    Mtx m;
    Vec tip;

    fn_8003414C(task->_14->_00);
    fn_1_272DC(task->_14, 0);
    fn_1_AF4(20, 20, 1.0f);
    PSMTXScale(m, task->_30, task->_30, task->_30);
    PSMTXTransApply(m, m, task->_20.x, task->_20.y, task->_20.z);
    PSMTXConcat(task->_14->_00, m, task->_14->_00);
    fn_1_272DC(task->_14, 0);
    fn_1_F2C(4, 0, 0);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXDrawSphere1(2);
    PSMTXTrans(m, task->_20.x, task->_20.y, task->_20.z);
    PSMTXConcat(task->_14->_00, m, task->_14->_00);
    fn_1_272DC(task->_14, 0);
    fn_1_F2C(4, 0, 0);
    GXBegin(GX_LINES, GX_VTXFMT0, 2);
    GXPosition3f32(task->_20.x, task->_20.y, task->_20.z);
    GXColor1u32(0xFF0000FF);
    tip.x = 0.0f;
    tip.y = 0.0f;
    tip.z = task->_2C;
    PSVECAdd(&task->_20, &tip, &tip);
    GXPosition3f32(tip.x, tip.y, tip.z);
    GXColor1u32(0xFF0000FF);
    lbl_1_data_108F0[task->_36]();
    minigamesGXStuff();
}

// .text:0x574 size:0xE4
void fn_1_27AD4(void) {
    Task7A28* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._04 & PAD_BUTTON_UP) {
        task->_37 = (task->_37 + 1) % 2;
    } else if (lbl_803C77B8[0]._04 & PAD_BUTTON_DOWN) {
        task->_37 = (task->_37 + 1) % 2;
    } else if (lbl_803C77B8[0]._02 & PAD_BUTTON_A) {
        task->_36 = task->_37 + 1;
        task->_37 = 0;
    } else if (lbl_803C77B8[0]._02 & PAD_BUTTON_B) {
        fn_1_27E50();
    }
}

// .text:0x570 size:0x4
void fn_1_27AD0(void) {}

// .text:0x16C size:0x404
void fn_1_276CC(void) {
    Task7A28* task = lbl_803CC1B8;

    if (task->_34 & 8) {
        fn_80048820(task->_1C, lbl_803C77B8[0]._00, lbl_803C77B8[0]._02, lbl_803C77B8[0]._04, lbl_803C77B8[0]._15);
        if (lbl_803C77B8[0]._00 & PAD_BUTTON_A) {
            ((Task7A28*)lbl_803CC1B8)->_34 &= ~2;
            ((Task7A28*)lbl_803CC1B8)->_34 |= 2;
        } else if (lbl_803C77B8[0]._02 & PAD_BUTTON_B) {
            ((Task7A28*)lbl_803CC1B8)->_34 ^= 8;
        }
    } else if (lbl_803C77B8[0]._04 & PAD_BUTTON_UP) {
        task->_37 = (task->_37 + 6) % 7;
    } else if (lbl_803C77B8[0]._04 & PAD_BUTTON_DOWN) {
        task->_37 = (task->_37 + 1) % 7;
    } else if (lbl_803C77B8[0]._04 & PAD_BUTTON_LEFT) {
        switch (task->_37) {
        case 0:
            task->_34 ^= 4;
            break;
        case 1:
            task->_30 *= 0.5f;
            break;
        case 2:
            task->_2C -= task->_2C > 1.0f;
            break;
        }
    } else if (lbl_803C77B8[0]._04 & PAD_BUTTON_RIGHT) {
        switch (task->_37) {
        case 0:
            task->_34 ^= 4;
            break;
        case 1:
            task->_30 *= 2.0f;
            break;
        case 2:
            task->_2C += 1.0f;
            break;
        }
    } else if (lbl_803C77B8[0]._00 & PAD_BUTTON_A) {
        task->_1C->_0C = 0;
        task->_1C->_10 = 0;
        task->_1C->_04 = 0;
        switch (task->_37) {
        case 3:
            task->_1C->_00 = "Fire 0";
            task->_1C->_18 = lbl_1_data_10A3C;
            ((Task7A28*)lbl_803CC1B8)->_34 ^= 8;
            break;
        case 4:
            task->_1C->_00 = "Fire 1";
            task->_1C->_18 = lbl_1_data_10CD0;
            ((Task7A28*)lbl_803CC1B8)->_34 ^= 8;
            break;
        case 5:
            task->_1C->_00 = "Smoke";
            task->_1C->_18 = lbl_1_data_10F38;
            ((Task7A28*)lbl_803CC1B8)->_34 ^= 8;
            break;
        case 6:
            task->_1C->_00 = "Fireball";
            task->_1C->_18 = lbl_1_data_111A0;
            ((Task7A28*)lbl_803CC1B8)->_34 ^= 8;
            break;
        default:
            task->_1C->_18 = NULL;
            ((Task7A28*)lbl_803CC1B8)->_34 &= ~2;
            ((Task7A28*)lbl_803CC1B8)->_34 |= 2;
            break;
        }
        if (task->_1C->_18 != NULL) {
            while (task->_1C->_18[task->_1C->_04]._04 != NULL) {
                task->_1C->_04++;
            }
        }
    } else if (lbl_803C77B8[0]._02 & PAD_BUTTON_B) {
        task->_36 = 0;
        task->_37 = 0;
    }
}

// .text:0x34 size:0x138
void fn_1_27594(void) {
    Task7A28* task = lbl_803CC1B8;
    Vec dir;
    Vec back = { 0.0f, 0.0f, 0.0f };
    s32 i;

    if ((task->_34 & 2) || (task->_34 & 4)) {
        dir.x = 0.0f;
        dir.y = 0.0f;
        dir.z = task->_2C;
        for (i = 1; i < 3; i++) {
            fn_80030D88(&task->_20, &dir, &lbl_1_data_10908[i], 5);
        }
        fn_8002F5F4(&task->_20, &dir, &lbl_1_data_109F8);
        PSVECNormalize(&dir, &dir);
        fn_80030470(&task->_20, &dir, &back, &lbl_1_data_10908[0], 5);
        ((Task7A28*)lbl_803CC1B8)->_34 ^= 2;
    }
    if (((Task7A28*)lbl_803CC1B8)->_34 & 8) {
        fn_80048BEC(task->_1C, 1, 1);
    }
}

// .text:0x0 size:0x34
void fn_1_27560(void* tex) {
    lbl_1_data_10908[0]._00 = lbl_1_data_10908[1]._00 = lbl_1_data_10908[2]._00 = tex;
    lbl_1_data_10908[0]._04 = 7;
    lbl_1_data_10908[1]._04 = 7;
    lbl_1_data_10908[2]._04 = 4;
    lbl_1_data_109F8._00 = tex;
}
