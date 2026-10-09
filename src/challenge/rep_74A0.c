#include "challenge/rep_74A0.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "string.h"
#include "Dolphin/rand.h"

typedef struct Task74A0 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x10 - 0x04];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x15 - 0x12];
    /* 0x15 */ u8 _15;
} Task74A0;

typedef struct Sort74A0 {
    /* 0x0 */ void* _0;
    /* 0x4 */ f32 _4;
} Sort74A0; // size: 0x8

typedef struct Bss69FC {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ Mtx _10;
    /* 0x40 */ u8 _40[24];
    /* 0x58 */ u8 _58[0x98 - 0x58];
} Bss69FC; // size: 0x98

typedef struct Shape74A0 {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ Mtx _18;
} Shape74A0;

typedef struct Node74A0 {
    /* 0x000 */ u8 _000[0x6];
    /* 0x006 */ u16 _006;
    /* 0x008 */ u8 _008[0x14 - 0x8];
    /* 0x014 */ Shape74A0* _014;
    /* 0x018 */ u8 _018[0x74 - 0x18];
    /* 0x074 */ struct Node74A0* _074;
    /* 0x078 */ u8 _078[0x98 - 0x78];
    /* 0x098 */ u8 _098;
    /* 0x099 */ u8 _099[0xEC - 0x99];
    /* 0x0EC */ MtxPtr _0EC;
    /* 0x0F0 */ u8 _0F0[0x100 - 0xF0];
    /* 0x100 */ struct Node74A0* _100;
} Node74A0;

typedef struct Model74A0 {
    /* 0x00 */ Node74A0* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
    /* 0x08 */ void (*_08)(struct Model74A0*);
    /* 0x0C */ u8 _0C[0x10 - 0xC];
    /* 0x10 */ Control _10;
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58[0x5A - 0x58];
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B[0x6C - 0x5B];
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D[0x70 - 0x6D];
    /* 0x70 */ void* _70;
    /* 0x74 */ u8 _74[0x90 - 0x74];
} Model74A0; // size: 0x90

typedef struct ModelTable74A0 {
    /* 0x00 */ u16 count;
    /* 0x04 */ Mtx _04;
    /* 0x34 */ Model74A0 models[1];
} ModelTable74A0;

typedef struct Particle74A0 {
    /* 0x00 */ struct Particle74A0* next;
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ f32 _0C;
} Particle74A0;

typedef struct LITObj {
    /* 0x00 */ u8 _00[0xC0];
} LITObj; // size: 0xC0

typedef struct Light74A0 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ GXColor color;
} Light74A0; // size: 0x10

typedef struct Unk8036E548 {
    /* 0x00 */ u8 _00[0x60];
    /* 0x60 */ ModelTable74A0* _60;
    /* 0x64 */ u8 _64[0xAC - 0x64];
    /* 0xAC */ LITObj* _AC[4];
} Unk8036E548;

extern Unk8036E548 lbl_8036E548;
extern Light74A0 lbl_80367318[4];

extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

extern void fn_800AD038(void* arg0);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800246D4(s32 (*compare)(Sort74A0*, Sort74A0*), Sort74A0* src, Sort74A0* dst, s32 size, s32 count);
extern void fn_800ACFB0(void* ptr);
extern void fn_800B2C88(Node74A0* node, u16 index, Mtx out);
extern void LITInitAttn(LITObj* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern void LITInitPos(LITObj* light, f32 x, f32 y, f32 z);
extern void LITInitColor(LITObj* light, GXColor color);
extern void LITXForm(LITObj* light, Mtx view);
extern void fn_800B9AA8(void* light);
extern void fn_800B2D5C(Node74A0* node);
extern void DOSetWorldMatrix(Shape74A0* shape, MtxPtr m);

static u8 lbl_1_bss_6B7C[0x5C];
static u8 lbl_1_bss_6AAC[0xD0];
static u8 lbl_1_bss_6A94[0x18];
static Bss69FC lbl_1_bss_69FC;
static u8 lbl_1_bss_69F9;
static u8 lbl_1_bss_69F8;
static u8 lbl_1_bss_69F7;
static u8 lbl_1_bss_69F6;
static u8 lbl_1_bss_69F5;
static u8 lbl_1_bss_69F4;
static u8 lbl_1_bss_69F3;
static u8 lbl_1_bss_69F2;
static u16 lbl_1_bss_69F0;

// .text:0x0001D514 size:0x7C
void fn_1_1D514(void) {
    fn_800AD038(lbl_80366158._08);
    ((Task74A0*)lbl_803CC1B8)->_10 = 0;
    ((Task74A0*)lbl_803CC1B8)->_00 = fn_1_1D470;
    lbl_1_bss_69F6 = 0xFF;
    lbl_1_bss_69F7 = 0xFF;
    lbl_1_bss_69F8 = 0xFF;
    lbl_1_bss_69F9 = 0xFF;
    lbl_1_bss_69F5 = 0;
    lbl_1_bss_69F3 = 0;
}

// .text:0x0001D470 size:0xA4
void fn_1_1D470(void) {
    Task74A0* task = lbl_803CC1B8;
    s32 i;

    for (i = 0; i < 24; i++) {
        lbl_1_bss_69FC._40[i] = 0;
    }
    task->_15 = 0;
    ((Task74A0*)lbl_803CC1B8)->_00 = fn_1_1D450;
}

// .text:0x0001D450 size:0x20
void fn_1_1D450(void) {
    fn_1_1CBE4();
}

// .text:0x0001D10C size:0x4
void fn_1_1D10C(void) {}

// .text:0x0001D0E8 size:0x24
void fn_1_1D0E8(Model74A0* model) {
    fn_800B9AA8(model->_70);
}

// .text:0x0001B038 size:0xC4
void fn_1_1B038(void) {
    s32 i;
    GXColor color = { 0xFF, 0xFF, 0xFF, 0xFF };

    for (i = 0; i < 3; i++) {
        LITInitAttn(lbl_8036E548._AC[i], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        LITInitPos(lbl_8036E548._AC[i], lbl_80367318[i].pos.x, lbl_80367318[i].pos.y, lbl_80367318[i].pos.z);
        LITInitColor(lbl_8036E548._AC[i], color);
        LITXForm(lbl_8036E548._AC[i], lbl_1_bss_69FC._10);
    }
}

// .text:0x0001A774 size:0xDC
void fn_1_1A774(void) {
    s32 i;
    u8 r, g, b, a;
    Mtx m;

    if (lbl_1_bss_69F0 < lbl_8036E548._60->models[lbl_1_bss_69F2]._00->_006) {
        for (i = 0; i < lbl_8036E548._60->models[lbl_1_bss_69F2]._00->_006; i++) {
            if (i == lbl_1_bss_69F0) {
                r = 0;
                g = 0xFF;
                b = 0xFF;
                a = 0xFF;
            } else {
                r = 0;
                g = 0x80;
                b = 0x80;
                a = 0x40;
            }
            fn_800B2C88(lbl_8036E548._60->models[lbl_1_bss_69F2]._00, i, m);
            fn_1_1A850(m, &lbl_1_bss_6B7C, r, g, b, a);
        }
    }
}

// .text:0x0001A290 size:0x124
void fn_1_1A290(ModelTable74A0* table, Mtx mtx) {
    u16 i;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetCullMode(GX_CULL_BACK);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    for (i = 0; i < table->count; i++) {
        Model74A0* model = &table->models[i];
        if (table->models[i]._00 != NULL && table->models[i]._6C != 0) {
            fn_1_1A1EC(model, mtx);
        }
    }
}

// .text:0x0001A1EC size:0xA4
void fn_1_1A1EC(Model74A0* model, Mtx mtx) {
    Node74A0* node = model->_00;

    if (model->_08 != NULL) {
        model->_08(model);
    }
    if (node->_014 != NULL) {
        fn_800B2D5C(node);
        GXInvalidateVtxCache();
        fn_1_19D60(node->_014, mtx);
    } else {
        for (node = node->_074; node != NULL; node = node->_100) {
            if (node->_014 != NULL) {
                DOSetWorldMatrix(node->_014, node->_0EC);
            }
            fn_1_19D60(node->_014, mtx);
        }
    }
}

// .text:0x00019D1C size:0x44
s32 fn_1_19D1C(u32 fmt) {
    switch ((fmt >> 4) & 0xF) {
    case 0:
    case 1:
        return 1;
    case 2:
    case 3:
        return 2;
    case 4:
        return 4;
    }
    return 0;
}

// .text:0x00017F28 size:0xC8
Particle74A0* fn_1_17F28(Particle74A0* list, s32 count) {
    Sort74A0* arr;
    Sort74A0* p;
    Particle74A0* it;

    arr = _OSAllocFromHeap(0x20, count * sizeof(Sort74A0));
    p = arr;
    for (it = list; it != NULL; it = it->next) {
        p->_0 = it;
        p->_4 = it->_0C;
        p++;
    }
    fn_800246D4(fn_1_17EFC, arr, arr, sizeof(Sort74A0), count);
    list = arr[0]._0;
    p = arr;
    while (--count) {
        ((Particle74A0*)p->_0)->next = p[1]._0;
        p++;
    }
    ((Particle74A0*)p->_0)->next = NULL;
    fn_800ACFB0(arr);
    return list;
}

// .text:0x00017EFC size:0x2C
s32 fn_1_17EFC(Sort74A0* a, Sort74A0* b) {
    if (a->_4 < b->_4) {
        return 1;
    }
    if (a->_4 > b->_4) {
        return -1;
    }
    return 0;
}
