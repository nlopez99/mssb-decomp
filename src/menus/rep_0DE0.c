#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_0DE0.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/vec.h"
#include "string.h"

typedef struct LITObj {
    /* 0x00 */ u8 _00[0xC0];
} LITObj; // size: 0xC0

// One of the scene's objects in lbl_8036E548's array at 0x2D94
typedef struct Obj0DE0 {
    /* 0x00 */ void (*_00)(s32 index);
    /* 0x04 */ Vec _04;
    /* 0x10 */ Vec _10;
    /* 0x1C */ u8 _1C[0x28 - 0x1C];
} Obj0DE0; // size: 0x28

typedef struct Model0DE0 {
    /* 0x00 */ void* _00;
    /* 0x04 */ u8 _04[0x6C - 0x04];
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D[0x90 - 0x6D];
} Model0DE0; // size: 0x90

typedef struct ModelTable0DE0 {
    /* 0x00 */ u16 count;
    /* 0x04 */ Mtx _04;
    /* 0x34 */ Model0DE0 models[1];
} ModelTable0DE0;

typedef struct ActorFiles0DE0 {
    /* 0x0 */ void* layout;
    /* 0x4 */ void* geo;
    /* 0x8 */ void* tex;
} ActorFiles0DE0; // size: 0xC

typedef struct Scene0DE0 {
    /* 0x0000 */ u8 _0000[0x68];
    /* 0x0068 */ ModelTable0DE0* _0068;
    /* 0x006C */ u8 _006C[0xAC - 0x6C];
    /* 0x00AC */ LITObj* _00AC[4];
    /* 0x00BC */ u8 _00BC[0x2D94 - 0xBC];
    /* 0x2D94 */ Obj0DE0* _2D94;
    /* 0x2D98 */ u8 _2D98[0x2D9C - 0x2D98];
    /* 0x2D9C */ u32* _2D9C;
    union {
        /* 0x2DA0 */ void* _2DA0[15];
        /* 0x2DA0 */ ActorFiles0DE0 files[5];
    };
    /* 0x2DDC */ u8 _2DDC[0x3078 - 0x2DDC];
    /* 0x3078 */ u16 _3078;
    /* 0x307A */ u8 _307A;
} Scene0DE0;

extern Scene0DE0 lbl_8036E548;
extern Scene0DE0* lbl_2_bss_340140;

extern struct {
    /* 0x00 */ u8 _00[0x64];
    /* 0x64 */ void* _64;
    /* 0x68 */ void* _68;
} lbl_2_bss_34009C;

extern struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06;
    /* 0x07 */ u8 _07[6];
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ s8 _0F;
    /* 0x10 */ s8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ s8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
} lbl_2_bss_33FBCC;

extern struct {
    /* 0x00 */ u8 _00[0x50];
    /* 0x50 */ s32 _50;
    /* 0x54 */ s32 _54;
} lbl_2_bss_F410;

typedef struct MenuTask0DE0 {
    /* 0x00 */ void (*_00)(void);
} MenuTask0DE0;

extern void* lbl_803CC1B8;

extern struct {
    /* 0x0000 */ u8 _0000[0x4756];
    /* 0x4756 */ u8 _4756;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0xF6];
    /* 0xF6 */ u8 _F6;
} lbl_80361B20;

typedef struct Camera0DE0 {
    /* 0x00 */ Mtx mtx;
    /* 0x30 */ u16 _30;
    /* 0x32 */ s16 _32;
    /* 0x34 */ u8 _34[0x38 - 0x34];
    /* 0x38 */ f32 _38;
    /* 0x3C */ Vec rot;
    /* 0x48 */ Vec pos;
    /* 0x54 */ s32 _54;
    /* 0x58 */ u8 _58[0x5C - 0x58];
} Camera0DE0; // size: 0x5C

typedef struct CameraPose0DE0 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec rot;
} CameraPose0DE0; // size: 0x18

typedef struct StateEntry0DE0 {
    /* 0x0 */ s32 _0;
    /* 0x4 */ void (*_4)(void);
} StateEntry0DE0; // size: 0x8

extern Camera0DE0 lbl_2_bss_1A81D4;
extern s8 lbl_2_bss_33FBF5;
extern u8 lbl_803CBBC0;

extern CameraPose0DE0 lbl_2_data_2E944[];
extern StateEntry0DE0 lbl_2_data_2E9B4[];
extern Vec lbl_2_data_2E9C4;
extern Vec lbl_2_data_2E9D0;
extern f32 lbl_2_bss_B29C;
extern u8 lbl_2_bss_B2A4;
extern u8 lbl_2_bss_B2A5;

extern f32 fn_2_4A1E8(f32 x, f32 z);
extern void fn_2_48D54(void);
extern void fn_2_190DC(ModelTable0DE0* table, Mtx view);
extern void fn_800A7D4C(s32 arg0, void* arg1);
extern void fn_800B806C(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
extern void fn_80034E20(MenuTask0DE0* task, void* desc);
extern void LITXForm(LITObj* light, Mtx view);
extern void fn_800BDA94(Model0DE0* model, Mtx mtx);
extern void LoadActorLayout(void* layout);
extern void convertGeometryAndSknHeader(void* geo, void* skn);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void convertTextureHeader(void* tex);
extern void fn_800BD190(void* geo, void* tex);

extern u8 lbl_2_data_2E9F8[];
extern u8 lbl_2_data_2ECE4[];

// .text:0x0008ABFC size:0x88
void fn_2_8ABFC(void) {
    MenuTask0DE0* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_2_data_2ECE4);
    fn_2_8A008(task);
    if (lbl_8034E9A0._4756 == 1) {
        lbl_2_bss_F410._50 = lbl_80361B20._F6;
    }
    ((MenuTask0DE0*)lbl_803CC1B8)->_00 = fn_2_8A824;
}

// .text:0x00089F70 size:0x98
void fn_2_89F70(void) {
    MenuTask0DE0* task = lbl_803CC1B8;
    void* desc;

    switch (lbl_2_bss_33FBCC._05) {
    case 0:
        desc = lbl_2_data_2E9F8 + 0xDCC;
        break;
    case 1:
    case 2:
        desc = lbl_2_data_2E9F8 + 0xCCC;
        break;
    case 3:
        desc = lbl_2_data_2E9F8 + 0xBAC;
        break;
    }
    fn_80034E20(task, desc);
    lbl_2_bss_33FBCC._0E = 0;
    ((MenuTask0DE0*)lbl_803CC1B8)->_00 = fn_2_8975C;
}

// .text:0x000895F8 size:0x164
s32 fn_2_895F8(u8 useSaved) {
    s32 result;
    s32 v = lbl_2_bss_F410._54;
    s32 saved = lbl_2_bss_33FBCC._1C;

    if (useSaved) {
        v = saved;
    }
    result = 0;
    switch (lbl_2_bss_33FBCC._05) {
    case 0:
        switch (v) {
        case 0:
            result = 0;
            break;
        case 5:
            result = 1;
            break;
        }
        break;
    case 1:
        switch (v) {
        case 1:
            result = 0;
            break;
        case 3:
            result = 1;
            break;
        case 4:
            result = 2;
            break;
        case 5:
            result = 3;
            break;
        }
        break;
    case 2:
        switch (v) {
        case 2:
            result = 0;
            break;
        case 3:
            result = 1;
            break;
        case 4:
            result = 2;
            break;
        case 5:
            result = 3;
            break;
        }
        break;
    case 3:
        switch (v) {
        case 1:
            result = 0;
            break;
        case 2:
            result = 1;
            break;
        case 3:
            result = 2;
            break;
        case 4:
            result = 3;
            break;
        case 5:
            result = 4;
            break;
        }
        break;
    }
    return result;
}

// .text:0x0008782C size:0x16C
void fn_2_8782C(void) {
    u32* base;
    int i;

    lbl_2_bss_340140->_3078 = 0;
    base = lbl_2_bss_340140->_2D9C;
    for (i = 0; i < 15; i++) {
        lbl_2_bss_340140->_2DA0[i] = (u8*)base + base[i];
    }
    lbl_2_bss_34009C._64 = (u8*)base + base[++i];
    lbl_2_bss_34009C._68 = (u8*)base + base[++i];
    for (i = 0; i < 5; i++) {
        void* layout = lbl_2_bss_340140->files[i].layout;
        void* geo = lbl_2_bss_340140->files[i].geo;
        void* tex = lbl_2_bss_340140->files[i].tex;

        LoadActorLayout(layout);
        convertGeometryAndSknHeader(geo, NULL);
        haveActLayoutPointToGeoHeader(layout, geo);
        convertTextureHeader(tex);
        fn_800BD190(geo, tex);
    }
    convertTextureHeader(lbl_2_bss_34009C._64);
    convertTextureHeader(lbl_2_bss_34009C._68);
}

// .text:0x00087114 size:0x4
void fn_2_87114(void) {}

// .text:0x000870D4 size:0x40
void fn_2_870D4(f32 x) {
    if (x) {
        lbl_2_bss_340140->_307A = 3;
    } else {
        lbl_2_bss_340140->_307A = 0;
    }
}

// .text:0x00086FEC size:0xE8
void fn_2_86FEC(void) {
    Mtx44 proj;

    C_MTXFrustum(proj, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
    GXSetProjection(proj, GX_PERSPECTIVE);
    fn_2_48D54();
    fn_2_86470();
    fn_2_85D6C(&lbl_2_bss_1A81D4);
    PSMTXCopy(lbl_2_bss_1A81D4.mtx, fn_80052768_getCamera(0)->view);
    fn_800A7D4C(0, &lbl_2_data_2E9B4[lbl_803CBBC0]);
    fn_2_190DC(lbl_2_bss_340140->_0068, fn_80052768_getCamera(0)->view);
}

// .text:0x00086F40 size:0xAC
void fn_2_86F40(void) {
    Model0DE0* model;
    ModelTable0DE0* table;
    s32 i;

    for (i = 0; i < lbl_8036E548._0068->count; i++) {
        table = lbl_8036E548._0068;
        model = &table->models[i];
        if (model->_00 != NULL && table->models[i]._6C != 0) {
            if (lbl_8036E548._2D94[i]._00 != NULL) {
                lbl_8036E548._2D94[i]._00(i);
            }
            fn_800BDA94(model, fn_80052768_getCamera(0)->view);
        }
    }
}

// .text:0x00086DCC size:0x174
void fn_2_86DCC(void) {
    Mtx44 proj;

    lbl_2_bss_B2A5 = 0;
    lbl_2_bss_B2A4 = 0;
    lbl_2_bss_1A81D4.pos.x = lbl_2_data_2E944[lbl_2_bss_33FBF5].pos.x;
    lbl_2_bss_1A81D4.pos.y = lbl_2_data_2E944[lbl_2_bss_33FBF5].pos.y;
    lbl_2_bss_1A81D4.pos.z = lbl_2_data_2E944[lbl_2_bss_33FBF5].pos.z;
    lbl_2_bss_1A81D4.rot.x = lbl_2_data_2E944[lbl_2_bss_33FBF5].rot.x;
    lbl_2_bss_1A81D4.rot.y = lbl_2_data_2E944[lbl_2_bss_33FBF5].rot.y;
    lbl_2_bss_1A81D4.rot.z = lbl_2_data_2E944[lbl_2_bss_33FBF5].rot.z;
    C_MTXFrustum(proj, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
    GXSetProjection(proj, GX_PERSPECTIVE);
    fn_800B806C(0, -240.0f, 240.0f, -320.0f, 320.0f, -512.0f, -1.0f, 1280.0f);
    lbl_2_bss_1A81D4._54 = 0;
    lbl_2_bss_1A81D4._38 = 0.0f;
    lbl_2_bss_1A81D4._30 = 0xC19F;
    lbl_2_bss_1A81D4._32 = 0;
}

// .text:0x00086A0C size:0x74
void fn_2_86A0C(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        LITXForm(lbl_2_bss_340140->_00AC[i], fn_80052768_getCamera(0)->view);
    }
}

// .text:0x000868C8 size:0xEC
void fn_2_868C8(void) {
    Vec pos;
    Vec delta;
    Obj0DE0* obj = lbl_2_bss_340140->_2D94;

    memcpy(&pos, &obj->_04, sizeof(Vec));
    PSVECSubtract(&pos, &lbl_2_data_2E9D0, &delta);
    delta.x *= -1.0f;
    delta.z *= -1.0f;
    if (delta.x != 0.0f || delta.z != 0.0f) {
        lbl_2_bss_B29C = fn_2_4A1E8(delta.z, delta.x);
    }
    memcpy(&lbl_2_data_2E9D0, &obj->_04, sizeof(Vec));
    obj->_04.x = pos.x;
    obj->_04.y = pos.y;
    obj->_04.z = pos.z;
    obj->_10.x = lbl_2_data_2E9C4.x;
    obj->_10.y = lbl_2_bss_B29C;
    obj->_10.z = lbl_2_data_2E9C4.z;
}

// .text:0x000869B4 size:0x58
void fn_2_869B4(void) {
    s32 i;

    for (i = 0; i < lbl_2_bss_340140->_3078; i++) {
        Obj0DE0* obj = &lbl_2_bss_340140->_2D94[i];

        obj->_04.x = 0.0f;
        obj->_04.y = 0.0f;
        obj->_04.z = 0.0f;
        obj->_10.x = 0.0f;
        obj->_10.y = 0.0f;
        obj->_10.z = 0.0f;
    }
}
