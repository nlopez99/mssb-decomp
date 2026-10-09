#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_0F60.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "C3/anim.h"
#include "Dolphin/vec.h"
#include "string.h"

typedef struct Actor0F60 {
    /* 0x00 */ u8 _00[0x99];
    /* 0x99 */ u8 _99;
} Actor0F60;

typedef struct Model0F60 {
    /* 0x00 */ Actor0F60* _00;
    /* 0x04 */ u8 _04[0x10 - 0x04];
    /* 0x10 */ Control control;
    /* 0x54 */ u8 _54[0x6C - 0x54];
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D[0x70 - 0x6D];
    /* 0x70 */ void* _70;
    /* 0x74 */ u8 _74[0x90 - 0x74];
} Model0F60; // size: 0x90

typedef struct ModelTable0F60 {
    /* 0x00 */ u16 count;
    /* 0x04 */ Mtx _04;
    /* 0x34 */ Model0F60 models[1];
} ModelTable0F60;

typedef struct Player0F60 {
    /* 0x000 */ u8 _000[0x8];
    /* 0x008 */ u8* _008;
    /* 0x00C */ u8 _00C[0x10 - 0xC];
    /* 0x010 */ s32 _010;
    /* 0x014 */ u8 _014[0x62 - 0x14];
    /* 0x062 */ s16 _062;
    /* 0x064 */ s16 _064;
    /* 0x066 */ s16 _066;
    /* 0x068 */ s16 _068;
    /* 0x06A */ u8 _06A[0x6C - 0x6A];
    /* 0x06C */ s16 _06C;
    /* 0x06E */ u8 _06E[0x25D - 0x6E];
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E;
    /* 0x25F */ u8 _25F;
    /* 0x260 */ u8 _260;
    /* 0x261 */ u8 _261[0x263 - 0x261];
    /* 0x263 */ u8 _263;
    /* 0x264 */ u8 _264[0x266 - 0x264];
    /* 0x266 */ u8 _266;
    /* 0x267 */ u8 _267[0x26A - 0x267];
    /* 0x26A */ u8 _26A;
    /* 0x26B */ u8 _26B[0x26D - 0x26B];
    /* 0x26D */ u8 _26D;
    /* 0x26E */ u8 _26E[0x27C - 0x26E];
} Player0F60; // size: 0x27C

typedef struct Entry0F60 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ Vec _04;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
    /* 0x1C */ u8 _1C[0x26 - 0x1C];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} Entry0F60; // size: 0x28

typedef struct ActorFiles0F60 {
    /* 0x0 */ void* layout;
    /* 0x4 */ void* geo;
    /* 0x8 */ void* tex;
} ActorFiles0F60; // size: 0xC

typedef struct AramEntry0F60 {
    /* 0x0 */ u32 _0;
    /* 0x4 */ u32 _4;
    /* 0x8 */ u32 _8;
    /* 0xC */ u32 _C;
} AramEntry0F60; // size: 0x10

typedef struct Game0F60 {
    /* 0x0000 */ u8 _0000[0x68];
    /* 0x0068 */ ModelTable0F60* _0068;
    /* 0x006C */ u8 _006C[0xAC - 0x6C];
    /* 0x00AC */ s32 _00AC;
    /* 0x00B0 */ s32 _00B0;
    /* 0x00B4 */ s32 _00B4;
    /* 0x00B8 */ s32 _00B8;
    /* 0x00BC */ u8 _00BC[0xC04 - 0xBC];
    /* 0x0C04 */ Player0F60 _0C04[9];
    /* 0x2260 */ u8 _2260[0x2C50 - 0x2260];
    /* 0x2C50 */ Player0F60* _2C50[9];
    /* 0x2C74 */ u8 _2C74[0x2C88 - 0x2C74];
    /* 0x2C88 */ u8* _2C88;
    /* 0x2C8C */ u8* _2C8C;
    /* 0x2C90 */ u32 _2C90;
    /* 0x2C94 */ u8 _2C94[0x2D94 - 0x2C94];
    /* 0x2D94 */ Entry0F60* _2D94;
    /* 0x2D98 */ u8 _2D98[0x2D9C - 0x2D98];
    /* 0x2D9C */ s32* _2D9C;
    /* 0x2DA0 */ ActorFiles0F60 _2DA0[4];
    /* 0x2DD0 */ u8 _2DD0[0x3078 - 0x2DD0];
    /* 0x3078 */ u16 _3078;
    /* 0x307A */ u8 _307A;
} Game0F60;

typedef struct Save0F60 {
    /* 0x000000 */ u8 _000000[0x197746];
    /* 0x197746 */ s16 _197746;
} Save0F60;

typedef struct Obj0F60 {
    /* 0x00 */ u8 _00[0x70];
    /* 0x70 */ void* _70;
} Obj0F60;

extern struct {
    /* 0x00 */ Game0F60* _00;
} lbl_2_bss_340140;
extern Game0F60 lbl_8036E548;
extern u8* lbl_2_bss_3401BC;
extern struct {
    /* 0x00 */ Save0F60* _00;
} lbl_2_bss_1A824C;
extern Mtx lbl_2_bss_1A81D4;

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern ModelTable0F60* ActorObjectInitTable(u16 count);
extern void fn_800BDC88(ModelTable0F60* table, u16 first, u16 last, void* model, void* anim, s32 arg5);
extern void fn_800BD548(Model0F60* model, s32 count, ...);
extern void LoadActorLayout(void* layout);
extern void convertGeometryAndSknHeader(void* geo, void* skn);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void convertTextureHeader(void* tex);
extern void fn_800BD190(void* geo, void* tex);
extern void fn_800B9AA8(void* arg0);
extern f32 fn_2_4A1E8(f32 x, f32 y);
extern void fn_2_190DC(ModelTable0F60* table, MtxPtr view);

AramEntry0F60 lbl_2_data_2F990[13] = {
    { 0x0000040B, 0x4005A338, 0x19233000, 0x0003A448 },
    { 0x0000040B, 0x4004D644, 0x1926D800, 0x00030E60 },
    { 0x0000040B, 0x40061CB0, 0x1929E800, 0x0003E260 },
    { 0x0000040B, 0x4004A820, 0x1930B800, 0x000316E0 },
    { 0x0000040B, 0x40046B64, 0x192DD000, 0x0002E4EC },
    { 0x0000040B, 0x40047D78, 0x1933D000, 0x0002F2DC },
    { 0x0000040B, 0x40042A7C, 0x1936C800, 0x0002AD8C },
    { 0x0000040B, 0x40047B30, 0x19397800, 0x0002D5A8 },
    { 0x0000040B, 0x4003F9D0, 0x193C5000, 0x00025C68 },
    { 0x0000040B, 0x400413A4, 0x193EB000, 0x000292B0 },
    { 0x0000040B, 0x40044F28, 0x19432000, 0x0002D5EC },
    { 0x0000040B, 0x40030574, 0x19414800, 0x0001D740 },
    { 0x0000040B, 0x40036CD8, 0x1945F800, 0x00023828 },
};
Vec lbl_2_data_2FED4 = { 0.0f, 0.0f, 0.0f };
Vec lbl_2_data_2FEE0 = { 0.0f, 0.0f, 0.0f };
f32 lbl_2_bss_B2B8;

// .text:0x0008DC00 size:0xD8
void fn_2_8DC00(void) {
    u32 max = 0;
    s32 i;
    s32 size;

    for (i = 0; i < 13; i++) {
        if (max < (lbl_2_data_2F990[i]._4 & 0x0FFFFFFF)) {
            max = lbl_2_data_2F990[i]._4 & 0x0FFFFFFF;
        }
    }
    size = (max + 0x1F) & ~0x1F;
    lbl_2_bss_340140._00->_2C8C = _OSAllocFromHeap(0x20, size * lbl_2_bss_1A824C._00->_197746);
    for (i = 0; i < lbl_2_bss_1A824C._00->_197746; i++) {
        lbl_2_bss_340140._00->_0C04[i]._008 = lbl_2_bss_340140._00->_2C8C + i * size;
    }
}

// .text:0x0008DB14 size:0xEC
void fn_2_8DB14(void) {
    u32 max = 0;
    s32 i;
    u32 size;

    for (i = 0; i < lbl_2_bss_1A824C._00->_197746; i++) {
        if (max < (lbl_2_data_2F990[i]._4 & 0x0FFFFFFF)) {
            max = lbl_2_data_2F990[i]._4 & 0x0FFFFFFF;
        }
    }
    size = (max + 0x1F) & ~0x1F;
    lbl_2_bss_340140._00->_2C90 = size;
    lbl_2_bss_340140._00->_2C88 = _OSAllocFromHeap(0x20, size * lbl_2_bss_1A824C._00->_197746);
    for (i = 0; i < lbl_2_bss_1A824C._00->_197746; i++) {
        lbl_2_bss_340140._00->_0C04[i]._010 = 0;
    }
}

// .text:0x0008D24C size:0x24
void fn_2_8D24C(Obj0F60* obj) {
    fn_800B9AA8(obj->_70);
}

// .text:0x0008CCCC size:0x8C
void fn_2_8CCCC(s32 idx, s32 arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Player0F60* p = lbl_2_bss_340140._00->_2C50[idx];

    if (p == NULL) {
        return;
    }
    if (arg3 == 1 && p->_062 == arg1) {
        return;
    }
    if (arg3 == 3) {
        arg3 = 1;
    }
    p->_064 = arg1;
    p->_06C = arg5;
    p->_260 = arg2;
    p->_25E = arg3;
    p->_263 = arg4;
    p->_266 = arg6;
    p->_26D = 0;
    if (arg7 == -1) {
        p->_26A = 5;
    } else {
        p->_26A = arg7;
    }
    p->_066 = -1;
}

// .text:0x0008CCAC size:0x20
void fn_2_8CCAC(s32 idx, s32 arg1) {
    Player0F60* p = &lbl_2_bss_340140._00->_0C04[idx];

    if (p != NULL) {
        p->_25D = arg1;
    }
}

// .text:0x0008CC88 size:0x24
s32 fn_2_8CC88(s32 idx) {
    return lbl_8036E548._2C50[idx]->_068 == 0;
}

// .text:0x0008C80C size:0x104
void fn_2_8C80C(s32 file, s32 first, s32 count, void* anim, s32 arg4) {
    s32 i;

    for (i = first; i < first + count; i++) {
        fn_800BDC88(lbl_2_bss_340140._00->_0068, i, i, lbl_2_bss_340140._00->_2DA0[file].layout, anim, arg4);
        lbl_2_bss_340140._00->_0068->models[i]._00->_99 = 1;
        fn_800BD548(&lbl_2_bss_340140._00->_0068->models[i], 4, lbl_2_bss_340140._00->_00AC,
                    lbl_2_bss_340140._00->_00B0, lbl_2_bss_340140._00->_00B4, lbl_2_bss_340140._00->_00B8);
        CTRLSetTranslation(&lbl_2_bss_340140._00->_0068->models[i].control, 0.0f, 0.0f, 0.0f);
        CTRLSetRotation(&lbl_2_bss_340140._00->_0068->models[i].control, 0.0f, 0.0f, 0.0f);
    }
}

// .text:0x0008C724 size:0xE8
void fn_2_8C724(void) {
    s32 i;

    for (i = 0; i < lbl_2_bss_340140._00->_3078; i++) {
        lbl_2_bss_340140._00->_2D94[i]._04.x = 0.0f;
        lbl_2_bss_340140._00->_2D94[i]._04.y = 0.0f;
        lbl_2_bss_340140._00->_2D94[i]._04.z = 0.0f;
        lbl_2_bss_340140._00->_2D94[i]._10 = 0.0f;
        lbl_2_bss_340140._00->_2D94[i]._14 = 0.0f;
        lbl_2_bss_340140._00->_2D94[i]._18 = 0.0f;
        lbl_2_bss_340140._00->_2D94[i]._26 = 0;
        lbl_2_bss_340140._00->_2D94[i]._00 = 0;
        lbl_2_bss_340140._00->_0068->models[i]._6C = 0;
    }
}

// .text:0x0008B2C0 size:0x158
void fn_2_8B2C0(void) {
    s32 i;
    s32* hdr;
    void* layout;
    void* geo;
    void* tex;

    lbl_2_bss_340140._00->_3078 = 0;
    hdr = lbl_2_bss_340140._00->_2D9C;
    lbl_2_bss_340140._00->_2DA0[0].layout = (u8*)hdr + hdr[0];
    lbl_2_bss_340140._00->_2DA0[0].geo = (u8*)hdr + hdr[1];
    lbl_2_bss_340140._00->_2DA0[0].tex = (u8*)hdr + hdr[2];
    lbl_2_bss_340140._00->_2DA0[1].layout = (u8*)hdr + hdr[3];
    lbl_2_bss_340140._00->_2DA0[1].geo = (u8*)hdr + hdr[4];
    lbl_2_bss_340140._00->_2DA0[1].tex = (u8*)hdr + hdr[5];
    lbl_2_bss_340140._00->_2DA0[2].layout = (u8*)hdr + hdr[6];
    lbl_2_bss_340140._00->_2DA0[2].geo = (u8*)hdr + hdr[7];
    lbl_2_bss_340140._00->_2DA0[2].tex = (u8*)hdr + hdr[8];
    lbl_2_bss_340140._00->_2DA0[3].layout = (u8*)hdr + hdr[9];
    lbl_2_bss_340140._00->_2DA0[3].geo = (u8*)hdr + hdr[10];
    lbl_2_bss_340140._00->_2DA0[3].tex = (u8*)hdr + hdr[11];
    for (i = 0; i < 4; i++) {
        layout = lbl_2_bss_340140._00->_2DA0[i].layout;
        geo = lbl_2_bss_340140._00->_2DA0[i].geo;
        tex = lbl_2_bss_340140._00->_2DA0[i].tex;
        LoadActorLayout(layout);
        convertGeometryAndSknHeader(geo, NULL);
        haveActLayoutPointToGeoHeader(layout, geo);
        convertTextureHeader(tex);
        fn_800BD190(geo, tex);
    }
}

// .text:0x0008B158 size:0x168
void fn_2_8B158(void) {
    s32 i;

    lbl_2_bss_340140._00->_3078 = 4;
    lbl_2_bss_340140._00->_2D94 = _OSAllocFromHeap(0x20, lbl_2_bss_340140._00->_3078 * sizeof(Entry0F60));
    lbl_2_bss_340140._00->_0068 = ActorObjectInitTable(lbl_2_bss_340140._00->_3078);
    for (i = 0; i < lbl_2_bss_340140._00->_3078; i++) {
        fn_2_8C80C(i, i, 1, NULL, 0);
    }
}

// .text:0x0008B118 size:0x40
void fn_2_8B118(f32 x) {
    if (x) {
        lbl_2_bss_340140._00->_307A = 3;
    } else {
        lbl_2_bss_340140._00->_307A = 0;
    }
}

// .text:0x0008AEE0 size:0x238
void fn_2_8AEE0(void) {
    camera_803c639c_s* cam;

    fn_2_8ACE0();
    PSMTXCopy(lbl_2_bss_1A81D4, fn_80052768_getCamera(0)->view);
    cam = fn_80052768_getCamera(0);
    fn_2_190DC(lbl_2_bss_340140._00->_0068, cam->view);
}

// .text:0x0008ACE0 size:0x200
void fn_2_8ACE0(void) {
    Vec pos;
    Vec delta;
    Entry0F60* e;
    s32 i;

    for (i = 0; i < lbl_2_bss_340140._00->_3078; i++) {
        e = &lbl_2_bss_340140._00->_2D94[i];
        memcpy(&pos, &e->_04, sizeof(Vec));
        PSVECSubtract(&pos, &lbl_2_data_2FEE0, &delta);
        delta.x *= -1.0f;
        delta.z *= -1.0f;
        if (delta.x != 0.0f || delta.z != 0.0f) {
            lbl_2_bss_B2B8 = fn_2_4A1E8(delta.z, delta.x);
        }
        memcpy(&lbl_2_data_2FEE0, &e->_04, sizeof(Vec));
        if (pos.x != 0.0f) {
            e->_04.x = pos.x / 2.0f;
        }
        if (pos.y != 0.0f) {
            e->_04.y = pos.y / 2.0f;
        }
        if (pos.z != 0.0f) {
            e->_04.z = pos.z / 2.0f;
        }
        lbl_2_data_2FED4.y = e->_14;
        CTRLSetTranslation(&lbl_2_bss_340140._00->_0068->models[i].control, pos.x, pos.y, pos.z);
        CTRLSetRotation(&lbl_2_bss_340140._00->_0068->models[i].control, 57.295776f * lbl_2_data_2FED4.x,
                        57.295776f * lbl_2_data_2FED4.y, 57.295776f * lbl_2_data_2FED4.z);
        lbl_2_bss_340140._00->_0068->models[i]._6C = lbl_2_bss_3401BC[i + 0x50];
    }
}

// .text:0x0008ACDC size:0x4
void fn_2_8ACDC(void) {
}
