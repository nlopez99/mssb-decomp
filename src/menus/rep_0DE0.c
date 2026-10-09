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
    /* 0x1C */ u8 _1C[0x26 - 0x1C];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} Obj0DE0; // size: 0x28

typedef struct TexFrame0DE0 {
    /* 0x00 */ s16 _00;
    /* 0x02 */ u8 _02[0x20 - 0x02];
} TexFrame0DE0; // size: 0x20

typedef struct TexAnim0DE0 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ TexFrame0DE0* _0C;
} TexAnim0DE0;

typedef struct Material0DE0 {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ TexAnim0DE0* _08;
} Material0DE0;

typedef struct Bone0DE0 {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ Material0DE0* _14;
} Bone0DE0;

typedef struct Actor0DE0 {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ Bone0DE0** _18;
} Actor0DE0;

typedef struct Model0DE0 {
    /* 0x00 */ Actor0DE0* _00;
    /* 0x04 */ u8 _04[0x10 - 0x04];
    /* 0x10 */ Control control;
    /* 0x54 */ u8 _54[0x6C - 0x54];
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
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
} MenuTask0DE0;

typedef struct MenuSprite0DE0 {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66;
    /* 0x67 */ u8 _67;
    /* 0x68 */ u8 _68;
} MenuSprite0DE0;

typedef struct MenuSpriteRef0DE0 {
    /* 0x0 */ MenuSprite0DE0* _00;
    /* 0x4 */ u8 _04[0x8 - 0x4];
} MenuSpriteRef0DE0; // size: 0x8

extern MenuSpriteRef0DE0 lbl_80371C30[];

extern void* lbl_803CC1B8;

extern struct {
    /* 0x0000 */ u8 _0000[0x4756];
    /* 0x4756 */ u8 _4756;
    /* 0x4757 */ u8 _4757[0x48AF - 0x4757];
    /* 0x48AF */ u8 _48AF;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0xF6];
    /* 0xF6 */ u8 _F6;
} lbl_80361B20;

typedef struct Camera0DE0 {
    /* 0x00 */ Mtx mtx;
    /* 0x30 */ u16 _30;
    /* 0x32 */ u16 _32;
    /* 0x34 */ f32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ Vec target;
    /* 0x48 */ Vec pos;
    /* 0x54 */ s32 _54;
    /* 0x58 */ u8 _58[0x5C - 0x58];
} Camera0DE0; // size: 0x5C

typedef struct CameraPose0DE0 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec target;
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
typedef struct Tracker0DE0 {
    /* 0x0000 */ u8 _0000[0x1606];
    /* 0x1606 */ s8 _1606;
    /* 0x1607 */ u8 _1607[0x441B - 0x1607];
    /* 0x441B */ u8 _441B;
    /* 0x441C */ u8 _441C[0x444B - 0x441C];
    /* 0x444B */ s8 _444B;
    /* 0x444C */ u8 _444C[0x4508 - 0x444C];
} Tracker0DE0; // size: 0x4508

extern struct {
    /* 0x0000 */ Tracker0DE0 trackers[3];
    /* 0xCF18 */ u8 _CF18[0xCF5E - 0xCF18];
    /* 0xCF5E */ u8 _CF5E[3];
} lbl_80354768;

extern void fn_80034E20(MenuTask0DE0* task, void* desc);
extern void changeScene(u8, s16);
extern s32 fn_80042DA8(MenuTask0DE0* task, s32 index, s32 value);
extern void fn_800363D8(MenuTask0DE0* task, s32 id, s32 part, s32 kind, s32 value);

static inline BOOL isAnimDone(MenuTask0DE0* task, s32 index, s32 value) {
    return fn_80042DA8(task, index, value) ? TRUE : FALSE;
}
extern void LITXForm(LITObj* light, Mtx view);
extern void LITAlloc(LITObj** light);
extern void LITInitAttn(LITObj* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern void LITInitPos(LITObj* light, f32 x, f32 y, f32 z);
extern void LITInitColor(LITObj* light, GXColor color);
extern void LITInitDir(LITObj* light, f32 nx, f32 ny, f32 nz);
extern void fn_800BDA94(Model0DE0* model, Mtx mtx);
extern void LoadActorLayout(void* layout);
extern void convertGeometryAndSknHeader(void* geo, void* skn);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void convertTextureHeader(void* tex);
extern void fn_800BD190(void* geo, void* tex);
extern void fn_80011640(Mtx src, Mtx dst);
extern void makeLookAtMatrix(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);
extern void fn_800BDC88(ModelTable0DE0* table, u16 first, u16 last, void* model, void* anim, s32 arg5);
extern void fn_800BD548(Model0DE0* model, s32 count, ...);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern ModelTable0DE0* ActorObjectInitTable(u16 count);

// Each scene's objects: { file index, frame row, animated }
static s16 lbl_2_data_2E608[4][30][3] = {
    {
        { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 },
        { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
        { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 },
        { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 },
    },
    {
        { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 },
        { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
        { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 },
        { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 },
    },
    {
        { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 },
        { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
        { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 },
        { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 },
        { 4, 0, 0 }, { 4, 0, 0 }, { 4, 0, 0 }, { 4, 0, 0 }, { 4, 0, 0 },
    },
    {
        { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 },
        { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
        { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 }, { 2, 2, 1 },
        { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 }, { 3, 0, 0 },
        { 4, 0, 0 }, { 4, 0, 0 }, { 4, 0, 0 }, { 4, 0, 0 }, { 4, 0, 0 }, { 4, 0, 0 },
    },
};
static s16 lbl_2_data_2E8D8[5] = { 1, 1, 1, 10, 11 };
static s16 lbl_2_data_2E8E4[5] = { 8, 8, 8, 4, 7 };
static s16 lbl_2_data_2E8F0[5][8] = {
    { 8, 9, 10, 11, 4, 12, 6, 7 },
    { 0, 1, 2, 3, 4, 5, 6, 7 },
    { 13, 14, 15, 16, 4, 17, 6, 7 },
};
static s8 lbl_2_data_2E940[4] = { 20, 24, 25, 30 };

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

// .text:0x00088D90 size:0x2A8
void fn_2_88D90(MenuTask0DE0* task) {
    s32 i;
    BOOL done;

    if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        for (i = 0; i < 3; i++) {
            lbl_80371C30[task->_14 + 4 + i]._00->_68 = 4;
            if (lbl_80354768._CF5E[i] != 0) {
                lbl_80371C30[task->_14 + 14 + i * 3]._00->_68 = 4;
                lbl_80371C30[task->_14 + 15 + i * 3]._00->_68 = 4;
                lbl_80371C30[task->_14 + 16 + i * 3]._00->_68 = 4;
                lbl_80371C30[task->_14 + 56 + i]._00->_68 = 4;
                if (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B == 0) {
                    lbl_80371C30[task->_14 + 59 + i]._00->_68 = 4;
                } else {
                    lbl_80371C30[task->_14 + 23 + i]._00->_68 = 4;
                    lbl_80371C30[task->_14 + 11 + i]._00->_5C = 0x160000;
                    lbl_80371C30[task->_14 + 11 + i]._00->_68 = 4;
                    if (lbl_80354768.trackers[i]._444B != -1) {
                        lbl_80371C30[task->_14 + 50 + i]._00->_68 = 4;
                    }
                }
            }
        }
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
        done = isAnimDone(task, 0, 0);
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) == 3) {
            changeScene(3, 6);
        }
        if (done == TRUE) {
            lbl_8034E9A0._48AF = 1;
            lbl_2_bss_33FBCC._1A = 1;
            lbl_2_bss_33FBCC._17 = 0;
            lbl_2_bss_33FBCC._18 = 0;
            lbl_2_bss_33FBCC._19 = 0;
        }
    }
}

// .text:0x00088250 size:0x178
void fn_2_88250(MenuTask0DE0* task) {
    if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._0F]._00->_64 = 20;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._0F]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._0F]._00->_5C = 0;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._0F]._00->_68 = 1;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_64 = 19;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_68 = 1;
        lbl_80371C30[task->_14 + 66 + lbl_2_bss_33FBCC._0F]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 66 + lbl_2_bss_33FBCC._0F]._00->_68 = 1;
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
        lbl_2_bss_33FBCC._17 = 0;
        lbl_2_bss_33FBCC._18 = 0;
        lbl_2_bss_33FBCC._19 = 0;
    }
}

// .text:0x00087FB0 size:0x2A0
void fn_2_87FB0(MenuTask0DE0* task) {
    s32 i;
    s32 done;
    s32 total;

    if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
        fn_2_8A008(task);
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._10]._00->_64 = 18;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._10]._00->_5C = 0;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._10]._00->_68 = 1;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_64 = 18;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_68 = 1;
        lbl_80371C30[task->_14 + 4 + lbl_2_bss_33FBCC._10]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 66 + lbl_2_bss_33FBCC._10]._00->_54 &= ~2;
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._0D = lbl_2_bss_33FBCC._10;
        lbl_2_bss_F410._50 = lbl_2_bss_33FBCC._10;
        lbl_2_bss_33FBCC._10 = -1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
        done = 0;
        total = 0;
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                if (lbl_80354768.trackers[i]._444B != -1) {
                    total++;
                    done += isAnimDone(task, i + 50, 10);
                } else if (lbl_80354768.trackers[i]._1606 == 0) {
                    total++;
                    done += isAnimDone(task, i + 53, 14);
                }
            }
        }
        if (done == total) {
            lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_64 = 19;
            lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_68 = 1;
            lbl_2_bss_33FBCC._17 = 0;
            lbl_2_bss_33FBCC._18 = 0;
            lbl_2_bss_33FBCC._19 = 0;
        }
    }
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

// .text:0x00087654 size:0x1D8
void fn_2_87654(void* arg0, s32 start, s32 count, void* anim, s32 arg5) {
    s32 i;
    s32 j;
    s32 k;
    s32 file;
    s32 row;
    s32 animated;
    s16* frames;
    TexAnim0DE0* tex;

    for (i = start; i < start + count; i++) {
        file = lbl_2_data_2E608[lbl_2_bss_33FBF5][i][0];
        row = lbl_2_data_2E608[lbl_2_bss_33FBF5][i][1];
        animated = lbl_2_data_2E608[lbl_2_bss_33FBF5][i][2];
        fn_800BDC88(lbl_2_bss_340140->_0068, i, i, lbl_2_bss_340140->files[file].layout, anim, arg5);
        fn_800BD548(&lbl_2_bss_340140->_0068->models[i], 4, lbl_2_bss_340140->_00AC[0], lbl_2_bss_340140->_00AC[1],
                    lbl_2_bss_340140->_00AC[2], lbl_2_bss_340140->_00AC[3]);
        CTRLSetTranslation(&lbl_2_bss_340140->_0068->models[i].control, 0.0f, 0.0f, 0.0f);
        CTRLSetRotation(&lbl_2_bss_340140->_0068->models[i].control, -90.0f, 0.0f, 0.0f);
        if (animated != 0) {
            for (j = 0; j < lbl_2_data_2E8D8[file]; j++) {
                frames = lbl_2_data_2E8F0[row];
                tex = lbl_2_bss_340140->_0068->models[i]._00->_18[j]->_14->_08;
                for (k = 0; k < lbl_2_data_2E8E4[file]; k++) {
                    tex->_0C[k + 1]._00 = j + frames[k];
                }
            }
        }
    }
}

// .text:0x00087350 size:0x304
void fn_2_87350(void) {
    s32 i;

    fn_2_87118();
    for (i = 0; i < lbl_2_bss_340140->_3078; i++) {
        lbl_2_bss_340140->_2D94[i]._04.x = 0.0f;
        lbl_2_bss_340140->_2D94[i]._04.y = 0.0f;
        lbl_2_bss_340140->_2D94[i]._04.z = 0.0f;
        lbl_2_bss_340140->_2D94[i]._10.x = 0.0f;
        lbl_2_bss_340140->_2D94[i]._10.y = 0.0f;
        lbl_2_bss_340140->_2D94[i]._10.z = 0.0f;
        lbl_2_bss_340140->_2D94[i]._26 = 0;
        lbl_2_bss_340140->_2D94[i]._00 = NULL;
        lbl_2_bss_340140->_0068->models[i]._6C = 0;
    }
}

// .text:0x00087118 size:0x238
void fn_2_87118(void) {
    lbl_2_bss_340140->_3078 = lbl_2_data_2E940[lbl_2_bss_33FBF5];
    lbl_2_bss_340140->_2D94 = _OSAllocFromHeap(32, lbl_2_bss_340140->_3078 * sizeof(Obj0DE0));
    lbl_2_bss_340140->_0068 = ActorObjectInitTable(lbl_2_bss_340140->_3078);
    fn_2_87654(NULL, 0, lbl_2_bss_340140->_3078, NULL, 0);
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
    lbl_2_bss_1A81D4.target.x = lbl_2_data_2E944[lbl_2_bss_33FBF5].target.x;
    lbl_2_bss_1A81D4.target.y = lbl_2_data_2E944[lbl_2_bss_33FBF5].target.y;
    lbl_2_bss_1A81D4.target.z = lbl_2_data_2E944[lbl_2_bss_33FBF5].target.z;
    C_MTXFrustum(proj, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
    GXSetProjection(proj, GX_PERSPECTIVE);
    fn_800B806C(0, -240.0f, 240.0f, -320.0f, 320.0f, -512.0f, -1.0f, 1280.0f);
    lbl_2_bss_1A81D4._54 = 0;
    lbl_2_bss_1A81D4._38 = 0.0f;
    lbl_2_bss_1A81D4._30 = 0xC19F;
    lbl_2_bss_1A81D4._32 = 0;
}

// .text:0x00086A80 size:0x34C
void fn_2_86A80(void) {
    GXColor white = { 255, 255, 255, 255 };
    GXColor blue = { 0, 0, 255, 255 };
    GXColor red = { 255, 0, 0, 255 };
    GXColor unused = { 255, 255, 255, 255 };

    LITAlloc(&lbl_2_bss_340140->_00AC[0]);
    LITAlloc(&lbl_2_bss_340140->_00AC[1]);
    LITAlloc(&lbl_2_bss_340140->_00AC[2]);
    LITAlloc(&lbl_2_bss_340140->_00AC[3]);

    LITInitAttn(lbl_2_bss_340140->_00AC[0], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_2_bss_340140->_00AC[0], 5.0f, 0.0f, 5.0f);
    LITInitDir(lbl_2_bss_340140->_00AC[0], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_2_bss_340140->_00AC[0], red);
    LITInitDir(lbl_2_bss_340140->_00AC[0], -5.0f, 0.0f, -5.0f);

    LITInitAttn(lbl_2_bss_340140->_00AC[1], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_2_bss_340140->_00AC[1], -5.0f, 5.0f, 0.0f);
    LITInitDir(lbl_2_bss_340140->_00AC[1], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_2_bss_340140->_00AC[1], blue);

    LITInitAttn(lbl_2_bss_340140->_00AC[2], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_2_bss_340140->_00AC[2], 0.0f, 0.0f, 5.0f);
    LITInitDir(lbl_2_bss_340140->_00AC[2], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_2_bss_340140->_00AC[2], white);

    LITInitAttn(lbl_2_bss_340140->_00AC[3], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_2_bss_340140->_00AC[3], 0.0f, 0.0f, -5.0f);
    LITInitDir(lbl_2_bss_340140->_00AC[3], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_2_bss_340140->_00AC[3], white);
}

// .text:0x00086A0C size:0x74
void fn_2_86A0C(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        LITXForm(lbl_2_bss_340140->_00AC[i], fn_80052768_getCamera(0)->view);
    }
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

// .text:0x00085D6C size:0x704
void fn_2_85D6C(Camera0DE0* camera) {
    switch (lbl_2_bss_B2A5) {
    case 0:
        fn_2_8563C(camera);
        break;
    case 1:
        fn_2_85AC0(camera);
        break;
    case 2:
        fn_2_858A4(camera);
        break;
    }
    fn_80011640(camera->mtx, camera->mtx);
}

// .text:0x00085AC0 size:0x2AC
void fn_2_85AC0(Camera0DE0* camera) {
    Vec up = { 0.0f, 1.0f, 0.0f };
    Vec angles;
    Vec dir = { 0.0f, 0.0f, 1.0f };
    Mtx rotX;
    Mtx rotY;
    Mtx rot;
    f32 c;
    f32 s;

    if (!(lbl_803C77B8[0]._00 & PAD_TRIGGER_Z)) {
        camera->_30 -= lbl_803C77B8[0]._13;
        camera->_32 += lbl_803C77B8[0]._12;
        camera->_34 = lbl_803C77B8[0]._10 / -256.0f;
        camera->_38 = lbl_803C77B8[0]._11 / 256.0f;
        camera->pos.y += lbl_803C77B8[0]._15 / 1024.0f;
        camera->pos.y -= lbl_803C77B8[0]._14 / 1024.0f;
    }
    angles.x = camera->_30;
    angles.y = camera->_32;
    angles.z = 0.0f;
    PSVECScale(&angles, 0.0000958738f, &angles);
    PSMTXRotRad(rotX, 'X', angles.x);
    PSMTXRotRad(rotY, 'Y', angles.y);
    s = rotY[0][2];
    c = rotY[0][0];
    PSMTXConcat(rotY, rotX, rot);
    PSMTXMultVec(rot, &dir, &camera->target);
    camera->pos.x += camera->_38 * s - camera->_34 * c;
    camera->pos.z += camera->_38 * c + camera->_34 * s;
    camera->target.x += camera->pos.x;
    camera->target.y += camera->pos.y;
    camera->target.z += camera->pos.z;
    makeLookAtMatrix(camera->mtx, &camera->pos, &up, &camera->target);
}

// .text:0x000858A4 size:0x21C
void fn_2_858A4(Camera0DE0* camera) {
    Vec up = { 0.0f, 1.0f, 0.0f };
    Vec angles;
    Vec dir = { 0.0f, 0.0f, 1.0f };
    Mtx rotX;
    Mtx rotY;
    Mtx rot;

    if (!(lbl_803C77B8[0]._00 & PAD_TRIGGER_Z)) {
        camera->_30 -= lbl_803C77B8[0]._13;
        camera->_32 += lbl_803C77B8[0]._12;
        camera->_38 += lbl_803C77B8[0]._11 / 256.0f;
        camera->target.y += lbl_803C77B8[0]._15 / 1024.0f;
        camera->target.y -= lbl_803C77B8[0]._14 / 1024.0f;
    }
    angles.x = camera->_30;
    angles.y = camera->_32;
    angles.z = 0.0f;
    PSVECScale(&angles, 0.0000958738f, &angles);
    PSMTXRotRad(rotX, 'X', angles.x);
    PSMTXRotRad(rotY, 'Y', angles.y);
    PSMTXConcat(rotX, rotY, rot);
    dir.z = -camera->_38;
    PSMTXMultVec(rot, &dir, &dir);
    PSVECAdd(&dir, &camera->target, &camera->pos);
    PSMTXMultVec(rot, &up, &dir);
    makeLookAtMatrix(camera->mtx, &camera->pos, &dir, &camera->target);
}

// .text:0x0008563C size:0x268
void fn_2_8563C(Camera0DE0* camera) {
    Vec up = { 0.0f, 1.0f, 0.0f };
    Vec angles;
    Vec dir = { 0.0f, 0.0f, 1.0f };
    Mtx rotX;
    Mtx rotY;
    Mtx rot;
    f32 c;
    f32 s;

    camera->_30 = 0xC19F;
    camera->_32 = 0;
    camera->_34 = 0.0f;
    camera->_38 = 0.0f;
    angles.x = camera->_30;
    angles.y = camera->_32;
    angles.z = 0.0f;
    PSVECScale(&angles, 0.0000958738f, &angles);
    PSMTXRotRad(rotX, 'X', angles.x);
    PSMTXRotRad(rotY, 'Y', angles.y);
    s = rotY[0][2];
    c = rotY[0][0];
    PSMTXConcat(rotY, rotX, rot);
    PSMTXMultVec(rot, &dir, &camera->target);
    camera->pos.x += camera->_38 * s - camera->_34 * c;
    camera->pos.z += camera->_38 * c + camera->_34 * s;
    camera->target.x += camera->pos.x;
    camera->target.y += camera->pos.y;
    camera->target.z += camera->pos.z;
    camera->pos.x = lbl_2_data_2E944[lbl_2_bss_33FBF5].pos.x;
    camera->pos.y = lbl_2_data_2E944[lbl_2_bss_33FBF5].pos.y;
    camera->pos.z = lbl_2_data_2E944[lbl_2_bss_33FBF5].pos.z;
    camera->target.x = lbl_2_data_2E944[lbl_2_bss_33FBF5].target.x;
    camera->target.y = lbl_2_data_2E944[lbl_2_bss_33FBF5].target.y;
    camera->target.z = lbl_2_data_2E944[lbl_2_bss_33FBF5].target.z;
    makeLookAtMatrix(camera->mtx, &camera->pos, &up, &camera->target);
}
