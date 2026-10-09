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
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
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

typedef struct VtxArray74A0 {
    /* 0x00 */ void* data;
    /* 0x04 */ u8 _04[0x6 - 0x4];
    /* 0x06 */ u8 fmt;
    /* 0x07 */ u8 count;
    /* 0x08 */ u8 _08[0x10 - 0x8];
} VtxArray74A0; // size: 0x10

typedef struct Prim74A0 {
    /* 0x00 */ u8 type;
    /* 0x04 */ u32 desc;
    /* 0x08 */ void* list;
    /* 0x0C */ u32 size;
} Prim74A0; // size: 0x10

typedef struct DList74A0 {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ Prim74A0* prims;
    /* 0x08 */ u32 count;
} DList74A0;

typedef struct Shape74A0 {
    /* 0x00 */ VtxArray74A0* pos;
    /* 0x04 */ u8 _04[0x8 - 0x4];
    /* 0x08 */ VtxArray74A0* texCoords;
    /* 0x0C */ u8 _0C[0x10 - 0xC];
    /* 0x10 */ DList74A0* dlist;
    /* 0x14 */ u8 numTexCoords;
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
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ Vec _10;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ Vec _28;
    /* 0x34 */ u8 _34[0x38 - 0x34];
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ union {
        u32 rgba;
        u8 c[4];
    } _40;
    /* 0x44 */ union {
        u32 rgba;
        u8 c[4];
    } _44;
    /* 0x48 */ s16 _48;
    /* 0x4A */ s16 _4A;
} Particle74A0;

typedef struct Emitter74A0 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ Particle74A0* _0C;
} Emitter74A0;

typedef struct LITObj {
    /* 0x00 */ u8 _00[0xC0];
} LITObj; // size: 0xC0

typedef struct Light74A0 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ GXColor color;
} Light74A0; // size: 0x10

typedef struct Actor74A0 {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ Node74A0* _004;
    /* 0x008 */ u32* _008;
    /* 0x00C */ u8 _00C[0x10 - 0xC];
    /* 0x010 */ void* _010;
    /* 0x014 */ u8 _014[0x34 - 0x14];
    /* 0x034 */ Vec _034;
    /* 0x040 */ Vec _040;
    /* 0x04C */ f32 _04C;
    /* 0x050 */ u8 _050[0x25D - 0x50];
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E[0x27C - 0x25E];
} Actor74A0; // size: 0x27C

typedef struct Unk8036E548 {
    /* 0x000 */ u8 _000[0x60];
    /* 0x060 */ ModelTable74A0* _060;
    /* 0x064 */ u8 _064[0xAC - 0x64];
    /* 0x0AC */ LITObj* _0AC[4];
    /* 0x0BC */ u8 _0BC[0xC04 - 0xBC];
    /* 0xC04 */ Actor74A0 _C04[24];
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
extern void fn_800B806C(s32 arg0, f32 top, f32 bottom, f32 left, f32 right, f32 nearZ, f32 farZ, f32 arg7);
extern void makeLookAtMatrix(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);
extern void fn_800BD670(ModelTable74A0* table, MtxPtr mtx);
extern void fn_800BD8C4(ModelTable74A0* table, MtxPtr mtx);
extern ModelTable74A0* ActorObjectInitTable(u16 count);
extern void ANIMGet(void* bank);
extern void convertTextureHeader(void* tex);
extern void LoadActorLayout(void* layout);
extern void convertGeometryAndSknHeader(void* geo, void* skn);
extern void fn_800BCE38(void* geo);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void fn_800BD190(void* geo, void* tex);
extern void fn_800BDC88(ModelTable74A0* table, u16 first, u16 last, void* layout, void* anim, void* skn);
extern void fn_800BD548(Model74A0* model, s32 count, ...);
extern void fn_800B2C08(Node74A0* node, s32 arg1);
extern Emitter74A0* fn_80033A24(BOOL (*update)(Emitter74A0*), s32, s32, s32, s32, s32);
extern u8 lbl_803CBBC0;
extern void* ARAMTransfer(void* entry, int arg1, int arg2, u32 aram);

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;
extern void fn_800A7D4C(s32 arg0, struct DrawEntry74A0* entry);
extern void LITAlloc(LITObj** light);
extern void LITInitDir(LITObj* light, f32 nx, f32 ny, f32 nz);
extern void LITInitAttn(LITObj* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern void LITInitPos(LITObj* light, f32 x, f32 y, f32 z);
extern void LITInitColor(LITObj* light, GXColor color);
extern void LITXForm(LITObj* light, Mtx view);
extern void fn_800B9AA8(void* light);
extern void fn_800B2D5C(Node74A0* node);
extern void DOSetWorldMatrix(Shape74A0* shape, MtxPtr m);

typedef struct Camera74A0 {
    /* 0x00 */ Mtx _00;
    /* 0x30 */ u16 _30;
    /* 0x32 */ u16 _32;
    /* 0x34 */ f32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ Vec _3C;
    /* 0x48 */ Vec _48;
    /* 0x54 */ u8 _54[0x5C - 0x54];
} Camera74A0; // size: 0x5C

typedef struct Tex74A0 {
    /* 0x00 */ void* image;
    /* 0x04 */ void* tlut;
    /* 0x08 */ u16 height;
    /* 0x0A */ u16 width;
    /* 0x0C */ u8 _0C[0x17 - 0xC];
    /* 0x17 */ u8 format;
    /* 0x18 */ u16 tlutEntries;
    /* 0x1A */ u8 tlutFormat;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
} Tex74A0; // size: 0x20

typedef struct TexFile74A0 {
    /* 0x00 */ u16 count;
    /* 0x02 */ u16 _02;
    /* 0x04 */ Tex74A0 tex[1];
} TexFile74A0;

typedef struct AramEntry74A0 {
    /* 0x0 */ u32 _0[4];
} AramEntry74A0; // size: 0x10

typedef struct DrawEntry74A0 {
    /* 0x0 */ u32 _0;
    /* 0x4 */ void (*_4)(void);
} DrawEntry74A0; // size: 0x8

static char lbl_1_data_F888[7][0x20] = {
    "CAMERA", "MODEL", "OFF", "ON", "MIX", "BONE_ONLY", "MODEL_ONLY",
};

static AramEntry74A0 lbl_1_data_F968[24] = {
    { 0x0000040B, 0x40021A48, 0x0E67B800, 0x00018844 },
    { 0x0000040B, 0x4001C1FC, 0x0E694800, 0x00016E90 },
    { 0x0000040B, 0x4001E21C, 0x0E6AB800, 0x000146D0 },
    { 0x0000040B, 0x4001ED7C, 0x0E6C0000, 0x00011D04 },
    { 0x0000040B, 0x40011A3C, 0x0E6D2000, 0x0000A890 },
    { 0x0000040B, 0x4001F938, 0x0E6DD000, 0x000158FC },
    { 0x0000040B, 0x4001A89C, 0x0E6F3000, 0x0001275C },
    { 0x0000040B, 0x4001C1FC, 0x0E705800, 0x00016E90 },
    { 0x0000040B, 0x400347F8, 0x0E71C800, 0x0001432C },
    { 0x0000040B, 0x4002511C, 0x0E731000, 0x0001304C },
    { 0x0000040B, 0x4001A9C4, 0x0E744800, 0x000160C0 },
    { 0x0000040B, 0x400253B4, 0x0E75B000, 0x0001CEB0 },
    { 0x0000040B, 0x40016040, 0x0E778000, 0x0000DCBC },
    { 0x0000040B, 0x4001B060, 0x0E786000, 0x0001235C },
    { 0x0000040B, 0x4002573C, 0x0E798800, 0x0001D2B0 },
    { 0x0000040B, 0x40021FCC, 0x0E7B6000, 0x00016FBC },
    { 0x0000040B, 0x4000FEAC, 0x0E7CD000, 0x0000B05C },
    { 0x0000040B, 0x400B0ADC, 0x0E7D8800, 0x00052EB0 },
    { 0x0000040B, 0x400B0A88, 0x0E82B800, 0x00052E98 },
    { 0x0000040B, 0x400B0ABC, 0x0E87E800, 0x00052EAC },
    { 0x0000040B, 0x400B0D7C, 0x0E8D1800, 0x00052F34 },
    { 0x0000040B, 0x400AA97C, 0x0E924800, 0x00050DF4 },
    { 0x0000040B, 0x4000289C, 0x0E975800, 0x00001C28 },
    { 0x0000040B, 0x40006588, 0x0E977800, 0x00002F60 },
};

static DrawEntry74A0 lbl_1_data_FAE8[2] = { { 0, fn_1_1ADA4 }, { 0, NULL } };
static DrawEntry74A0 lbl_1_data_FAF8[2] = { { 0, fn_1_1A774 }, { 0, NULL } };
static GXColor lbl_1_data_FB08 = { 0xFF, 0xFF, 0xFF, 0xFF };
static Vec lbl_1_data_FB0C = { 0.0f, 1.0f, 0.0f };
static Vec lbl_1_data_FB18 = { 0.0f, 0.0f, 0.0f };
s32 lbl_1_data_FB24[6] = { 50, 2000, 1200000, 100000, 100000, 60 };

static Camera74A0 lbl_1_bss_6B7C;
static void* lbl_1_bss_6AAC[0x34];
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

// .text:0x0001D110 size:0x340
void fn_1_1D110(void) {
    Task74A0* task = lbl_803CC1B8;
    Model74A0* model;
    Actor74A0* actor;
    s32 i;

    fn_1_1B038();
    for (i = 0; i < 24; i++) {
        actor = &lbl_8036E548._C04[i];
        model = &lbl_8036E548._060->models[i];
        model->_6C = (task->_16 != 1) & (i == task->_14);
        CTRLSetTranslation(&model->_10, actor->_034.x, actor->_034.y, actor->_034.z);
        CTRLSetRotation(&model->_10, 57.295776f * actor->_040.x, 57.295776f * actor->_040.y,
                        57.295776f * actor->_040.z);
        model->_54 = actor->_04C;
        model->_5A = 1;
    }
    if (lbl_1_bss_69F5 == 0) {
        fn_800BD670(lbl_8036E548._060, lbl_1_bss_69FC._10);
    } else {
        fn_1_1A290(lbl_8036E548._060, lbl_1_bss_69FC._10);
    }
    for (i = 0; i < 24; i++) {
        model = &lbl_8036E548._060->models[i];
        model->_6C = 1;
    }
    fn_800BD8C4(lbl_8036E548._060, lbl_1_bss_69FC._10);
}

// .text:0x0001D10C size:0x4
void fn_1_1D10C(void) {}

// .text:0x0001D0E8 size:0x24
void fn_1_1D0E8(Model74A0* model) {
    fn_800B9AA8(model->_70);
}

// .text:0x0001CBE4 size:0x504
void fn_1_1CBE4(void) {
    Task74A0* task = lbl_803CC1B8;
    u32 i;
    char* name;

    switch (task->_10) {
    case 0:
        for (i = 0; i < 24; i++) {
            lbl_1_bss_6A94[i] = 0;
        }
        task->_14 = 0;
        task->_16 = 0;
        task->_17 = 0;
        task->_18 = 1;
        fn_1_1B6BC();
        fn_1_1B0FC();
        ((Task74A0*)lbl_803CC1B8)->_10 = 2;
        break;
    case 1:
        task->_14++;
        if (task->_14 == 24) {
            ((Task74A0*)lbl_803CC1B8)->_10 = 8;
        } else {
            ((Task74A0*)lbl_803CC1B8)->_10 = 2;
        }
        break;
    case 2:
        name = (char*)lbl_1_data_F968[task->_14]._0[0];
        if (name == "test/obj/skin/mario/model11.dat" || name == "test/obj/skin/test01/model11.dat" ||
            name == "test/obj/skin/test02/model11.dat" || name == "test/obj/skin/test03/model11.dat" ||
            name == "test/obj/skin/test04/model11.dat" || name == "test/obj/skin/test05/model11.dat" ||
            name == "test/obj/skin/test06/model11.dat" || name == "test/obj/skin/test07/model11.dat") {
            lbl_1_bss_6A94[task->_14] = 1;
        }
        lbl_8036E548._C04[task->_14]._008 = ARAMTransfer(&lbl_1_data_F968[task->_14], 0, 0, 0);
        ((Task74A0*)lbl_803CC1B8)->_10++;
        break;
    case 3:
        if (lbl_803C6CF8._715 == 1) {
            task->_10 = 1;
        }
        break;
    case 8:
        task->_14 = 0;
        ((Task74A0*)lbl_803CC1B8)->_10 = 0;
        ((Task74A0*)lbl_803CC1B8)->_00 = fn_1_1C8C0;
        break;
    }
}

// .text:0x0001C8C0 size:0x324
void fn_1_1C8C0(void) {
    u32* hdr;
    void* layout;
    void* skn;
    void* geo;
    void* tex;
    u32 i;
    u32 j;
    void* anim;
    Actor74A0* actor;
    Model74A0* model;

    lbl_8036E548._060 = ActorObjectInitTable(24);
    for (i = 0; i < 24; i++) {
        if (i < 24) {
            hdr = lbl_8036E548._C04[i]._008;
            if (lbl_1_bss_6A94[i] != 0) {
                for (j = 0; j < 5; j++) {
                    if (j == 4) {
                        lbl_8036E548._C04[i]._010 = (void*)((u32)hdr + hdr[j]);
                        ANIMGet(lbl_8036E548._C04[i]._010);
                    } else {
                        lbl_8036E548._C04[i]._008[j] = (u32)hdr + hdr[j];
                    }
                }
            } else {
                hdr[0] = (u32)hdr + hdr[0];
                lbl_8036E548._C04[i]._008[1] = (u32)hdr + hdr[1];
                lbl_8036E548._C04[i]._008[2] = (u32)hdr + hdr[2];
            }
            tex = (void*)lbl_8036E548._C04[i]._008[0];
            geo = (void*)lbl_8036E548._C04[i]._008[1];
            layout = (void*)lbl_8036E548._C04[i]._008[2];
            if (lbl_1_bss_6A94[i] != 0) {
                skn = (void*)lbl_8036E548._C04[i]._008[3];
            } else {
                skn = NULL;
            }
            convertTextureHeader(tex);
            LoadActorLayout(layout);
            if (lbl_1_bss_6A94[i] != 0) {
                convertGeometryAndSknHeader(geo, skn);
            } else {
                fn_800BCE38(geo);
            }
            lbl_1_bss_6AAC[i] = tex;
            haveActLayoutPointToGeoHeader(layout, geo);
            fn_800BD190(geo, tex);
        }
        if (lbl_1_bss_6A94[i] != 0) {
            anim = lbl_8036E548._C04[i]._010;
        } else {
            anim = NULL;
        }
        actor = &lbl_8036E548._C04[i];
        fn_800BDC88(lbl_8036E548._060, i, i, layout, anim, skn);
        fn_800BD548(&lbl_8036E548._060->models[i], 3, lbl_8036E548._0AC[0], lbl_8036E548._0AC[1],
                    lbl_8036E548._0AC[2], lbl_8036E548._0AC[3]);
        CTRLSetTranslation(&lbl_8036E548._060->models[i]._10, 0.0f, 0.0f, 0.0f);
        CTRLSetRotation(&lbl_8036E548._060->models[i]._10, 0.0f, 0.0f, 0.0f);
        model = &lbl_8036E548._060->models[i];
        model->_54 = 0.5f;
        model->_5A = 1;
        lbl_8036E548._060->models[i]._00->_098 |= 4;
        if (i == 1) {
            fn_800B2C08(lbl_8036E548._060->models[i]._00, 0);
        } else {
            fn_800B2C08(lbl_8036E548._060->models[i]._00, 1);
        }
        actor->_004 = lbl_8036E548._060->models[i]._00;
        actor->_034.x = 0.0f;
        actor->_034.y = 0.0f;
        actor->_034.z = 10.0f;
        actor->_04C = 0.5f;
        actor->_25D = i == 0;
        lbl_8036E548._060->models[i]._08 = fn_1_1D0E8;
    }
    ((Task74A0*)lbl_803CC1B8)->_00 = fn_1_1C3CC;
}

// .text:0x0001C3CC size:0x4F4
void fn_1_1C3CC(void) {
    Task74A0* task = lbl_803CC1B8;
    Mtx44 m;

    C_MTXFrustum(m, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
    GXSetProjection(m, GX_PERSPECTIVE);
    fn_1_1B7DC();
    if (task->_17 != 0) {
        fn_1_1B2C8();
    } else {
        fn_1_1B424();
    }
    PSMTXCopy(lbl_1_bss_6B7C._00, lbl_1_bss_69FC._10);
    lbl_1_bss_69F2 = task->_14;
    fn_800A7D4C(0, &lbl_1_data_FAE8[lbl_803CBBC0]);
    if (task->_16 != 2) {
        fn_800A7D4C(0, &lbl_1_data_FAF8[lbl_803CBBC0]);
    }
    fn_1_1D110();
    if (task->_18 != 0) {
        fn_1_1A3B4();
    }
}

// .text:0x0001B6BC size:0x120
void fn_1_1B6BC(void) {
    Mtx44 m;

    lbl_1_bss_6B7C._48.x = 0.0f;
    lbl_1_bss_6B7C._48.y = -0.8f;
    lbl_1_bss_6B7C._48.z = 0.0f;
    lbl_1_bss_6B7C._3C.x = 0.0f;
    lbl_1_bss_6B7C._3C.y = 0.0f;
    lbl_1_bss_6B7C._3C.z = 10.0f;
    C_MTXFrustum(m, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
    GXSetProjection(m, GX_PERSPECTIVE);
    fn_800B806C(0, -240.0f, 240.0f, -320.0f, 320.0f, -512.0f, -1.0f, 1280.0f);
}

// .text:0x0001B424 size:0x298
void fn_1_1B424(void) {
    Vec rot;
    Vec base = { 0.0f, 0.0f, 100.0f };
    Mtx rx;
    Mtx ry;
    Mtx m;
    f32 c;
    f32 s;

    if (!(lbl_803C77B8[0]._00 & PAD_TRIGGER_Z)) {
        lbl_1_bss_6B7C._30 -= lbl_803C77B8[0]._13;
        lbl_1_bss_6B7C._32 += lbl_803C77B8[0]._12;
        lbl_1_bss_6B7C._34 = lbl_803C77B8[0]._10 / -256.0f;
        lbl_1_bss_6B7C._38 = lbl_803C77B8[0]._11 / 256.0f;
        lbl_1_bss_6B7C._48.y += lbl_803C77B8[0]._15 / 1024.0f;
        lbl_1_bss_6B7C._48.y -= lbl_803C77B8[0]._14 / 1024.0f;
    }
    rot.x = lbl_1_bss_6B7C._30;
    rot.y = lbl_1_bss_6B7C._32;
    rot.z = 0.0f;
    PSVECScale(&rot, 0.0000958738f, &rot);
    PSMTXRotRad(rx, 'X', rot.x);
    PSMTXRotRad(ry, 'Y', rot.y);
    s = ry[0][2];
    c = ry[0][0];
    PSMTXConcat(ry, rx, m);
    PSMTXMultVec(m, &base, &lbl_1_bss_6B7C._3C);
    lbl_1_bss_6B7C._48.x += lbl_1_bss_6B7C._38 * s - lbl_1_bss_6B7C._34 * c;
    lbl_1_bss_6B7C._48.z += lbl_1_bss_6B7C._38 * c + lbl_1_bss_6B7C._34 * s;
    lbl_1_bss_6B7C._3C.x += lbl_1_bss_6B7C._48.x;
    lbl_1_bss_6B7C._3C.y += lbl_1_bss_6B7C._48.y;
    lbl_1_bss_6B7C._3C.z += lbl_1_bss_6B7C._48.z;
    makeLookAtMatrix(lbl_1_bss_6B7C._00, &lbl_1_bss_6B7C._48, &lbl_1_data_FB0C, &lbl_1_bss_6B7C._3C);
}

// .text:0x0001B2C8 size:0x15C
void fn_1_1B2C8(void) {
    Actor74A0* actor = &lbl_8036E548._C04[((Task74A0*)lbl_803CC1B8)->_14];

    actor->_034.x += lbl_803C77B8[0]._10 / 768.0f;
    actor->_034.y = actor->_034.y + lbl_803C77B8[0]._15 / 768.0f - lbl_803C77B8[0]._14 / 768.0f;
    actor->_034.z += lbl_803C77B8[0]._11 / 768.0f;
    lbl_1_data_FB18.x -= lbl_803C77B8[0]._13 * 0.001953125f;
    lbl_1_data_FB18.y -= lbl_803C77B8[0]._12 * 0.001953125f;
    actor->_040.x = lbl_1_data_FB18.x;
    actor->_040.y = lbl_1_data_FB18.y;
    actor->_040.z = lbl_1_data_FB18.z;
}

// .text:0x0001B0FC size:0x1CC
void fn_1_1B0FC(void) {
    GXColor white = { 0xFF, 0xFF, 0xFF, 0xFF };
    GXColor blue = { 0x00, 0x00, 0xFF, 0xFF };

    LITAlloc(&lbl_8036E548._0AC[0]);
    LITAlloc(&lbl_8036E548._0AC[1]);
    LITAlloc(&lbl_8036E548._0AC[2]);
    LITInitAttn(lbl_8036E548._0AC[0], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._0AC[0], -100.0f, -100.0f, 100.0f);
    LITInitColor(lbl_8036E548._0AC[0], white);
    LITInitAttn(lbl_8036E548._0AC[1], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._0AC[1], 500.0f, -500.0f, 250.0f);
    LITInitColor(lbl_8036E548._0AC[1], blue);
    LITInitAttn(lbl_8036E548._0AC[2], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._0AC[2], 0.0f, -500.0f, 250.0f);
    LITInitColor(lbl_8036E548._0AC[2], blue);
    LITInitDir(lbl_8036E548._0AC[0], 100.0f, 100.0f, -100.0f);
}

// .text:0x0001B038 size:0xC4
void fn_1_1B038(void) {
    s32 i;
    GXColor color = { 0xFF, 0xFF, 0xFF, 0xFF };

    for (i = 0; i < 3; i++) {
        LITInitAttn(lbl_8036E548._0AC[i], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        LITInitPos(lbl_8036E548._0AC[i], lbl_80367318[i].pos.x, lbl_80367318[i].pos.y, lbl_80367318[i].pos.z);
        LITInitColor(lbl_8036E548._0AC[i], color);
        LITXForm(lbl_8036E548._0AC[i], lbl_1_bss_69FC._10);
    }
}

// .text:0x0001ADA4 size:0x294
void fn_1_1ADA4(void) {
    Mtx44 m;
    s32 i;
    f32 f;

    C_MTXFrustum(m, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
    GXSetProjection(m, GX_PERSPECTIVE);
    GXLoadPosMtxImm(lbl_1_bss_6B7C._00, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetColorUpdate(GX_TRUE);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetNumTevStages(1);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetChanCtrl(GX_COLOR0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_ALPHA0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
    for (i = -24; i < 25; i++) {
        f = i;
        GXBegin(GX_LINES, GX_VTXFMT0, 4);
        GXPosition3f32(-24.0f, 0.0f, f);
        GXColor4u8(0, 0xFF, 0, 0xC8);
        GXPosition3f32(24.0f, 0.0f, f);
        GXColor4u8(0, 0xFF, 0, 0xC8);
        GXPosition3f32(f, 0.0f, -24.0f);
        GXColor4u8(0, 0xFF, 0, 0xC8);
        GXPosition3f32(f, 0.0f, 24.0f);
        GXColor4u8(0, 0xFF, 0, 0xC8);
        GXEnd();
    }
}

// .text:0x0001A774 size:0xDC
void fn_1_1A774(void) {
    s32 i;
    u8 r, g, b, a;
    Mtx m;

    if (lbl_1_bss_69F0 < lbl_8036E548._060->models[lbl_1_bss_69F2]._00->_006) {
        for (i = 0; i < lbl_8036E548._060->models[lbl_1_bss_69F2]._00->_006; i++) {
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
            fn_800B2C88(lbl_8036E548._060->models[lbl_1_bss_69F2]._00, i, m);
            fn_1_1A850(m, &lbl_1_bss_6B7C, r, g, b, a);
        }
    }
}

// .text:0x0001A3B4 size:0x3C0
void fn_1_1A3B4(void) {
    GXTexObj obj;
    GXTlutObj tlut;
    GXColor white = { 0xFF, 0xFF, 0xFF, 0xFF };
    TexFile74A0* file = lbl_1_bss_6AAC[((Task74A0*)lbl_803CC1B8)->_14];
    Tex74A0* tex;
    u16 count = file->count;
    u32 i;
    Tex74A0* first = &file->tex[file->tex[0]._1C];

    tex = first;
    if (first->tlut != NULL) {
        for (i = 0; i < count; tex++, i++) {
            GXInitTlutObj(&tlut, tex->tlut, tex->tlutFormat, tex->tlutEntries);
            GXLoadTlut(&tlut, GX_TLUT0);
            GXInitTexObjCI(&obj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE,
                           GX_TLUT0);
            GXInitTexObjLOD(&obj, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
            GXLoadTexObj(&obj, GX_TEXMAP0);
        }
    } else {
        for (i = 0; i < count; tex++, i++) {
            GXInitTexObj(&obj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE);
            GXInitTexObjLOD(&obj, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
            GXLoadTexObj(&obj, GX_TEXMAP0);
        }
    }
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTevColor(GX_TEVREG0, white);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_OR);
    GXSetCullMode(GX_CULL_NONE);
    GXLoadPosMtxImm(lbl_1_bss_6B7C._00, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(-3.0f, 0.0f, 20.0f);
    GXTexCoord2f32(0.0f, 1.0f);
    GXPosition3f32(-3.0f, -3.0f, 20.0f);
    GXTexCoord2f32(0.0f, 0.0f);
    GXPosition3f32(0.0f, -3.0f, 20.0f);
    GXTexCoord2f32(1.0f, 0.0f);
    GXPosition3f32(0.0f, 0.0f, 20.0f);
    GXTexCoord2f32(1.0f, 1.0f);
    GXEnd();
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
    Node74A0* child;

    if (model->_08 != NULL) {
        model->_08(model);
    }
    if (node->_014 != NULL) {
        fn_800B2D5C(node);
        GXInvalidateVtxCache();
        fn_1_19D60(node->_014, mtx);
    } else {
        for (child = node->_074; child != NULL; child = child->_100) {
            if (child->_014 != NULL) {
                DOSetWorldMatrix(child->_014, child->_0EC);
            }
            fn_1_19D60(child->_014, mtx);
        }
    }
}

// .text:0x00019D60 size:0x48C
void fn_1_19D60(Shape74A0* shape, Mtx mtx) {
    GXColor color;
    Mtx m;
    GXVtxDescList desc[GX_VA_MAX_ATTR + 1];
    VtxArray74A0* arr;
    Prim74A0* prim;
    s32 i;
    u32 j;
    s32 n;
    s32 attr;
    s32 shift;
    u32 type;

    color.r = lbl_1_bss_69F9;
    color.g = lbl_1_bss_69F8;
    color.b = lbl_1_bss_69F7;
    color.a = lbl_1_bss_69F6;
    GXSetChanMatColor(GX_COLOR0A0, color);
    GXSetNumChans(1);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_RASA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    PSMTXConcat(mtx, shape->_18, m);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    arr = shape->pos;
    GXSetArray(GX_VA_POS, arr->data, arr->count * fn_1_19D1C(arr->fmt));
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, shape->pos->fmt >> 4, shape->pos->fmt & 0xF);
    if (shape->texCoords != NULL) {
        for (i = 0; i < shape->numTexCoords; i++) {
            arr = &shape->texCoords[i];
            GXSetArray(GX_VA_TEX0 + i, arr->data, arr->count * fn_1_19D1C(arr->fmt));
            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0 + i, GX_TEX_ST, shape->texCoords[i].fmt >> 4, shape->texCoords[i].fmt & 0xF);
            GXSetTexCoordGen2(i, GX_TG_MTX2X4, GX_TG_TEX0 + i, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
        }
    }
    prim = shape->dlist->prims;
    for (j = 0; j < shape->dlist->count; j++, prim++) {
        switch (prim->type) {
        case 0:
        case 1:
            break;
        case 2:
            GXClearVtxDesc();
            n = 0;
            if (prim->desc & 3) {
                desc[0].mAttr = GX_VA_PNMTXIDX;
                desc[0].mType = prim->desc & 3;
                n = 1;
            }
            for (attr = GX_VA_POS, shift = 2; attr <= GX_POS_MTX_ARRAY; attr++, shift += 2) {
                type = (prim->desc >> shift) & 3;
                if (type != 0) {
                    desc[n].mAttr = attr;
                    desc[n].mType = type;
                    n++;
                }
            }
            desc[n].mAttr = GX_VA_NULL;
            GXSetVtxDescv(desc);
            break;
        }
        if (prim->list != NULL) {
            GXCallDisplayList(prim->list, prim->size);
        }
    }
}

// .text:0x00019D1C size:0x44
s32 fn_1_19D1C(u8 fmt) {
    switch ((u8)(fmt >> 4)) {
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

// .text:0x0001994C size:0x3D0
void fn_1_1994C(void) {
    Emitter74A0* e = fn_80033A24(fn_1_1857C, 0, 0, lbl_1_data_FB24[0], 1, 0x80);

    if (e != NULL) {
        fn_1_191DC(e);
    }
}

// .text:0x0001957C size:0x3D0
void fn_1_1957C(void) {
    Emitter74A0* e = fn_80033A24(fn_1_1857C, 0, 0, lbl_1_data_FB24[0], 1, 0x80);

    if (e != NULL) {
        fn_1_191DC(e);
    }
}

// .text:0x000191DC size:0x3A0
void fn_1_191DC(Emitter74A0* e) {
    Particle74A0* p = e->_0C;
    u32 i = 0;

    do {
        p->_4A = i;
        p->_38 = lbl_1_data_FB24[3] / 100000.0f;
        p->_3C = lbl_1_data_FB24[4] / 100000.0f;
        fn_1_18EE4(p);
        p->_48 = ((i % 5) * (lbl_1_data_FB24[0] / 5) + rand() % (lbl_1_data_FB24[0] / 5)) * 2;
        i++;
        p = p->next;
    } while (p != NULL);
}

// .text:0x00018EE4 size:0x2F8
void fn_1_18EE4(Particle74A0* p) {
    s32 min;
    u8 base = min = lbl_1_data_FB24[5];
    u8 range;
    f32 scale;


    p->_04 = (p->_4A * 2) / (f32)lbl_1_data_FB24[0] - 1.0f;
    p->_08 = -1.0f;
    p->_0C = 50.0f * (rand() / 32767.0f) + 50.0f;
    fn_1_18E04(p, 0.0f);
    p->_1C = p->_20 = p->_24 = 0.0f;
    scale = lbl_1_data_FB24[2] / 100000.0f;
    p->_28.x = scale * (rand() / 32767.0f);
    p->_28.y = scale * (rand() / 32767.0f);
    p->_28.z = scale * (rand() / 32767.0f);
    p->_44.c[3] = 0xFF;
    p->_40.c[3] = 0xFF;
    range = 255 - min;
    p->_40.c[1] = base + rand() % range;
    p->_40.c[2] = base + rand() % range;
    p->_44.c[0] = base + rand() % range;
    p->_44.c[1] = base + rand() % range;
    p->_44.c[2] = base + rand() % range;
}

// .text:0x00018E04 size:0xE0
void fn_1_18E04(Particle74A0* p, f32 angle) {
    f32 s;
    f32 c;
    f32 rad;

    rad = 0.017453292f * angle;
    s = sin(rad);
    c = cos(rad);

    p->_10.x = (s * lbl_1_data_FB24[1]) / 100000.0f;
    p->_10.y = (c * lbl_1_data_FB24[1]) / 100000.0f;
    p->_10.z = 0.0f;
}

// .text:0x000182C0 size:0x2BC
void fn_1_182C0(Particle74A0* p) {
    Control ctrl;
    Vec v[4];
    Mtx m;
    Mtx44 proj;
    f32 h;
    f32 w;
    s32 i;

    w = p->_38 / 2;
    h = p->_3C / 2;
    ctrl.type = 0;
    v[0].x = -w;
    v[0].y = -h;
    v[1].x = w;
    v[1].y = -h;
    v[2].x = w;
    v[2].y = h;
    v[3].x = -w;
    v[3].y = h;
    v[0].z = v[1].z = v[2].z = v[3].z = 0.0f;
    CTRLSetRotation(&ctrl, p->_1C, p->_20, p->_24);
    CTRLSetTranslation(&ctrl, 0.5f * p->_04 / 2 * p->_0C, 0.35f * p->_08 / 2 * p->_0C, -1.5f);
    CTRLBuildMatrix(&ctrl, m);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    C_MTXOrtho(proj, -0.175f * p->_0C, 0.175f * p->_0C, 0.25f * p->_0C, -0.25f * p->_0C, 1.0f, 512.0f);
    GXSetProjection(proj, GX_ORTHOGRAPHIC);
    GXSetCullMode(GX_CULL_BACK);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (i = 0; i < 4; i++) {
        GXPosition3f32(v[i].x, v[i].y, v[i].z);
        GXColor1u32(p->_40.rgba);
    }
    GXEnd();
    GXSetCullMode(GX_CULL_FRONT);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (i = 0; i < 4; i++) {
        GXPosition3f32(v[i].x, v[i].y, v[i].z);
        GXColor1u32(p->_44.rgba);
    }
    GXEnd();
}

// .text:0x00018174 size:0x14C
void fn_1_18174(void) {
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_RASC);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
}

// .text:0x00017FF0 size:0x184
void fn_1_17FF0(void) {
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetCullMode(GX_CULL_NONE);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_RASA, GX_CA_TEXA, GX_CA_ZERO);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXLoadPosMtxImm(fn_80052768_getCamera(0)->view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetProjection(fn_80052768_getCamera(0)->proj, GX_PERSPECTIVE);
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
