#include "game/rep_1D58.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/UnknownHomes_Game.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "Dolphin/rand.h"
#include "C3/actor.h"
#include "C3/control.h"
#include "C3/geoPalette.h"
#include "game/rep_D0.h"
#include "game/rep_1C0.h"
#include "game/m_sound.h"
#include "game/rep_4138.h"
#include "string.h"
#include "math.h"

typedef struct LITObj LITObj;

typedef struct {
    /* 0x00 */ u8 _00[0xA];
} LightData1D58; // size: 0xA

typedef struct {
    /* 0x00 */ LightData1D58 lights[4];
    /* 0x28 */ GXColor ambient;
} StadiumLights1D58; // size: 0x2C

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ GXColor color;
} Light1D58; // size: 0x10

typedef struct {
    /* 0x00 */ u32 _00[4];
} AramEntry1D58; // size: 0x10

typedef struct BoneData1D58 {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
} BoneData1D58; // size: 0x1C

typedef struct ModelBone1D58 {
    /* 0x000 */ u8 _000[0x14];
    /* 0x014 */ struct DODisplayObj* _014;
    /* 0x018 */ u8 _018[0xE8 - 0x18];
    /* 0x0E8 */ BoneData1D58* _0E8;
    /* 0x0EC */ MtxPtr _0EC;
    /* 0x0F0 */ u8 _0F0[0x100 - 0xF0];
    /* 0x100 */ struct ModelBone1D58* _100;
} ModelBone1D58;

typedef struct {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 totalBones;
    /* 0x08 */ u8 _08[0x14 - 0x8];
    /* 0x14 */ struct DODisplayObj* skinObject;
    /* 0x18 */ ModelBone1D58** boneArray;
    /* 0x1C */ u8 _1C[0x64 - 0x1C];
    /* 0x64 */ MtxPtr skinMtxArray;
    /* 0x68 */ MtxPtr skinInvTransposeMtxArray;
    /* 0x6C */ u8 _6C[0x74 - 0x6C];
    /* 0x74 */ ModelBone1D58* drawHead;
    /* 0x78 */ u8 _78[0x7C - 0x78];
    /* 0x7C */ void* _7C;
    /* 0x80 */ u8 _80[0x98 - 0x80];
    /* 0x98 */ u8 _98;
} ModelActor1D58;

typedef struct StadiumModel1D58 {
    /* 0x00 */ ModelActor1D58* actor;
    /* 0x04 */ void* anim;
    /* 0x08 */ u8 _08[0xE - 0x8];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u8 _10[0x54 - 0x10];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u16 _64;
    /* 0x66 */ u16 _66;
    /* 0x68 */ s32 _68;
} StadiumModel1D58;

typedef struct StadiumObject1D58 {
    /* 0x00 */ Control control;
    /* 0x3C */ u8 _3C[0x44 - 0x3C];
    /* 0x44 */ Mtx _44;
    /* 0x74 */ struct StadiumModel1D58* _74;
    /* 0x78 */ struct StadiumObjectCollision* _78;
    /* 0x7C */ void (*_7C)(struct StadiumObject1D58* obj);
    /* 0x80 */ void (*_80)(s32 object, int type, struct _CollisionStruct* collision);
    /* 0x84 */ void (*_84)(struct StadiumObject1D58* obj);
    /* 0x88 */ void (*_88)(struct StadiumObject1D58* obj);
    /* 0x8C */ void* _8C;
    /* 0x90 */ u8 _90_7 : 1;
    /* 0x90 */ u8 _90_6 : 1;
    /* 0x90 */ u8 _90_5 : 1;
    /* 0x90 */ u8 _90_4 : 1;
    /* 0x90 */ u8 _90_3 : 1;
    /* 0x90 */ u8 _90_2 : 1;
    /* 0x90 */ u8 _90_1 : 1;
    /* 0x90 */ u8 _90_0 : 1;
    /* 0x91 */ u8 _91;
    /* 0x92 */ u8 _92;
    /* 0x93 */ u8 _93;
    /* 0x94 */ u16 _94;
    /* 0x96 */ s16 _96;
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B[0xE8 - 0x9B];
} StadiumObject1D58; // size: 0xE8

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ ModelActor1D58* _34;
    /* 0x38 */ u8 _38[0x90 - 0x38];
} StadiumActor1D58; // size: 0x90

typedef struct StadiumObjectCollision {
    /* 0x00 */ u8 _00[8];
    /* 0x08 */ TriangleGroup* triangles;
} StadiumObjectCollision;

typedef struct {
    /* 0x00 */ f32 depth;
    /* 0x04 */ s32 index;
} StadiumSort1D58; // size: 0x8

extern struct {
    /* 0x00 */ StadiumObject1D58* _00;
    /* 0x04 */ StadiumObject1D58* _04;
    /* 0x08 */ void* _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ StadiumSort1D58* _14;
    /* 0x18 */ void (*_18)(void);
    /* 0x1C */ void (*_1C)(void);
    /* 0x20 */ LITObj* _20[4];
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32* _34;
    /* 0x38 */ void* _38;
    /* 0x3C */ u32* _3C;
    /* 0x40 */ u16* _40;
    /* 0x44 */ s32* _44;
    /* 0x48 */ Vec* _48;
    /* 0x4C */ Vec _4C;
    /* 0x58 */ u8 _58[0x64 - 0x58];
    /* 0x64 */ s16 numAreas;
    /* 0x66 */ s16 _66;
    /* 0x68 */ s16 _68;
    /* 0x6A */ u8 _6A;
    /* 0x6B */ u8 _6B;
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D;
} lbl_3_common_bss_350E4; // size: 0x70

extern StadiumLights1D58 lbl_800F7478[14];
extern AramEntry1D58 lbl_3_data_10ACC[21];
extern void (*lbl_3_data_10AB0[7])(void* file);
extern u8 lbl_3_data_11168[0x10];

extern struct {
    /* 0x0000 */ u8 _0000[0x8];
    /* 0x0008 */ void* _0008;
    /* 0x000C */ u8 _000C[0x6C - 0xC];
    /* 0x006C */ StadiumActor1D58* _006C;
    /* 0x0070 */ u8 _0070[0x3088 - 0x70];
    /* 0x3088 */ u8 _3088;
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800ACFB0(void* data);
extern void minigamesSetSomePointers(void);
extern void minigamesGXStuff(void);
extern void minigamesSetSomePointers2(void);
extern void fn_8001B200(void);
extern void fn_800B4278(ModelActor1D58* actor);
extern void fn_3_C1964(void);
extern void fn_800528B4(void);
extern void fn_800638CC(void);
extern StadiumObjectCollision* fn_3_C823C(s32 object, Mtx mtx);
extern StadiumObjectCollision* fn_3_E4BE8(s32 object, Mtx mtx);
extern StadiumObjectCollision* fn_3_F6504(s32 object, Mtx mtx);
extern StadiumObjectCollision* fn_3_E751C(s32 object, Mtx mtx);
extern void fn_800B4BC8(ModelActor1D58* actor, s32 arg1);
extern void fn_800B4CA0(ModelActor1D58* actor, f32 time);
extern void fn_800B4C04(ModelActor1D58* actor, f32 speed);
extern void fn_800B4AFC(ModelActor1D58* actor, s32 arg1);
extern void LITAlloc(LITObj** light);
extern void LITInitAttn(LITObj* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern void LITInitPos(LITObj* light, f32 x, f32 y, f32 z);
extern void LITInitColor(LITObj* light, GXColor color);
extern void LITInitDir(LITObj* light, f32 nx, f32 ny, f32 nz);
extern void LITXForm(LITObj* light, Mtx view);
extern void fn_80023B90(LightData1D58* data, Light1D58* light);
extern void fn_8001B214(void (*callback)(void));
extern void fn_8001E474(void);
extern void* ARAMTransfer(AramEntry1D58* entry, int arg1, int arg2, u32 aram);
extern void fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void fn_800B0A14_removeQueue(void);
extern void fn_8003A548(void (*callback)(void));
extern struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ struct {
        /* 0x00 */ u8 _00[0x40];
        /* 0x40 */ Mtx _40;
    }* _14;
}* fn_800BF068(void);
extern void fn_8003A8A0(struct DODisplayObj* obj, MtxPtr view, s32 arg2);

f32 lbl_3_data_11178[5] = { 18.0f, 90.0f, 162.0f, 234.0f, 306.0f };

static void (*lbl_3_bss_9940)(void);
static u8 lbl_3_bss_1940[0x8000] ATTRIBUTE_ALIGN(32);
static Vec lbl_3_bss_1910[2];
static StadiumObject1D58* lbl_3_bss_190C;
static f32 lbl_3_bss_1908;
static void* lbl_3_bss_1904;
static u8 lbl_3_bss_1902;
static u8 lbl_3_bss_1901;

// .text:0x000B9FB8 size:0x198 mapped:0x806F904C
void fn_3_B9FB8(s32 stadium, void* file) {
    Light1D58 data;
    LITObj* light;
    s32 i;

    fn_8001E474();
    memset(&lbl_3_common_bss_350E4, 0, sizeof(lbl_3_common_bss_350E4));
    fn_3_35E4(NULL);
    if (file != NULL) {
        for (i = 0; i < 4; i++) {
            fn_80023B90(&lbl_800F7478[g_d_GameSettings._54].lights[i], &data);
            LITAlloc(&light);
            LITInitAttn(light, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
            LITInitPos(light, data.pos.x, data.pos.y, data.pos.z);
            LITInitColor(light, data.color);
            lbl_3_common_bss_350E4._20[i] = light;
        }
        lbl_3_common_bss_350E4._38 = file;
        lbl_3_common_bss_350E4._08 = NULL;
        lbl_3_common_bss_350E4._0C = NULL;
        lbl_3_data_10AB0[stadium](file);
        lbl_3_common_bss_350E4._14 = _OSAllocFromHeap(4, lbl_3_common_bss_350E4._30 * sizeof(StadiumSort1D58));
        fn_8001B214(fn_3_B8298);
        lbl_3_common_bss_350E4._66 = rand();
        lbl_8036E548._3088 = 1;
        lbl_3_bss_1901 = 0;
    }
}

// .text:0x000B9D68 size:0x250 mapped:0x806F8DFC
void fn_3_B9D68(u8* types, s32 count, void** files, s32* indices) {
    return;
}

// .text:0x000B9BB4 size:0x1B4 mapped:0x806F8C48
s32 fn_3_B9BB4(s32 stadium) {
    if (lbl_803C6CF8._715 == 1) {
        switch (stadium) {
        case 0:
            lbl_8036E548._0008 = ARAMTransfer(&lbl_3_data_10ACC[0], 0, 0, 0);
            break;
        case 1:
            lbl_8036E548._0008 = ARAMTransfer(&lbl_3_data_10ACC[1], 0, 0, 0);
            break;
        case 2:
            lbl_8036E548._0008 = ARAMTransfer(&lbl_3_data_10ACC[2], 0, 0, 0);
            break;
        case 3:
            lbl_8036E548._0008 = ARAMTransfer(&lbl_3_data_10ACC[3], 0, 0, 0);
            break;
        case 4:
            lbl_8036E548._0008 = ARAMTransfer(&lbl_3_data_10ACC[4], 0, 0, 0);
            break;
        case 5:
            lbl_8036E548._0008 = ARAMTransfer(&lbl_3_data_10ACC[5], 0, 0, 0);
            break;
        case 6:
            lbl_8036E548._0008 = ARAMTransfer(&lbl_3_data_10ACC[6], 0, 0, 0);
            break;
        default:
            return -1;
        }
        fn_800B0A5C_insertQueue(fn_3_B99E4, 0);
        lbl_3_common_bss_350E4._6A = 1;
        return 1;
    }
    return 0;
}

// .text:0x000B99E4 size:0x1D0 mapped:0x806F8A78
void fn_3_B99E4(void) {
    if (lbl_803C6CF8._715 == 1) {
        lbl_3_common_bss_350E4._6A = 0;
        fn_3_B9FB8(g_d_GameSettings.StadiumID, lbl_8036E548._0008);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000B98E8 size:0xFC mapped:0x806F897C
void fn_3_B98E8(StadiumModel1D58* model) {
    u32 i;
    ModelBone1D58* bone;

    for (i = 0; i < model->actor->totalBones; i++) {
        bone = model->actor->boneArray[i];
        bone->_0E8 = _OSAllocFromHeap(0x20, sizeof(BoneData1D58));
        bone->_0E8->_00 = 0.0f;
        bone->_0E8->_04 = 0.0f;
        bone->_0E8->_08 = 1.0f;
        bone->_0E8->_0C = 0;
        bone->_0E8->_10 = 0;
        bone->_0E8->_16 = 0;
        bone->_0E8->_17 = 1;
        bone->_0E8->_18 = 1;
        bone->_0E8->_14 = 0;
    }
}

// .text:0x000B97DC size:0x10C mapped:0x806F8870
void fn_3_B97DC(void* arg, void* anim) {
    StadiumModel1D58* model = arg;

    if (model == NULL || anim == NULL) {
        return;
    }
    model->anim = anim;
    model->_0E = 0;
    model->_5C = 0.0f;
    model->_58 = 1;
    model->_59 = anim != NULL;
    model->_5A = anim != NULL;
    model->_60 = 0.0f;
    model->_5B = 3;
    model->_5C = 0.0f;
    model->_59 = 1;
    model->_54 = 1.0f;
    model->_5A = 1;
    model->_68 = 0;
    model->_58 = 1;
    if (model->_58) {
        ACTSetAnimation((Actor*)model->actor, model->anim, NULL, model->_0E, 0.0f, model->_60);
        fn_800B4BC8(model->actor, 1);
    }
    if (model->_59) {
        fn_800B4CA0(model->actor, model->_5C);
    }
    if (model->_5A) {
        fn_800B4C04(model->actor, model->_54);
    }
    if (model->_5B & 1) {
        fn_800B4AFC(model->actor, model->_5B & 1);
    }
}

// .text:0x000B97C8 size:0x14 mapped:0x806F885C
void fn_3_B97C8(void (*callback)(void)) {
    if (callback != NULL) {
        lbl_3_bss_9940 = callback;
    }
}

// .text:0x000B95EC size:0x1DC mapped:0x806F8680
void fn_3_B95EC(void) {
    u8 i;

    minigamesSetSomePointers();
    minigamesGXStuff();
    minigamesSetSomePointers2();
    if (lbl_3_bss_9940 != NULL) {
        lbl_3_bss_9940();
        lbl_3_bss_9940 = NULL;
    }
    if (g_d_GameSettings.minigamesEnabled) {
        fn_8001B200();
        if (lbl_3_common_bss_350E4._14 != NULL) {
            fn_800ACFB0(lbl_3_common_bss_350E4._14);
        }
        if (lbl_3_common_bss_350E4._48 != NULL) {
            fn_800ACFB0(lbl_3_common_bss_350E4._48);
        }
        if (lbl_3_common_bss_350E4._04 != NULL) {
            fn_800ACFB0(lbl_3_common_bss_350E4._04);
        }
        if (lbl_3_common_bss_350E4._00 != NULL) {
            fn_800ACFB0(lbl_3_common_bss_350E4._00);
        }
        if (lbl_8036E548._006C != NULL) {
            for (i = lbl_3_common_bss_350E4._6D; i != 0; i--) {
                fn_800B4278(lbl_8036E548._006C[i - 1]._34);
            }
            fn_800ACFB0(lbl_8036E548._006C);
            lbl_8036E548._006C = NULL;
        }
        if (lbl_3_common_bss_350E4._34 != NULL) {
            fn_800ACFB0(lbl_3_common_bss_350E4._34);
        }
        for (i = 4; i != 0; i--) {
            if (lbl_3_common_bss_350E4._20[i - 1] != NULL) {
                fn_800ACFB0(lbl_3_common_bss_350E4._20[i - 1]);
            }
        }
        if (lbl_3_common_bss_350E4._38 != NULL) {
            fn_800ACFB0(lbl_3_common_bss_350E4._38);
        }
        lbl_8036E548._3088 = 0;
        fn_3_C1964();
        fn_3_16E328();
        fn_800528B4();
        fn_8001E474();
        fn_3_B9524();
        memset(&lbl_3_common_bss_350E4, 0, sizeof(lbl_3_common_bss_350E4));
        lbl_3_bss_1901 = 1;
    }
}

// .text:0x000B9534 size:0xB8 mapped:0x806F85C8
u8* fn_3_B9534(s32 width, s32 height, GXTexObj* obj) {
    if (lbl_3_bss_1902 != 0 || obj == NULL) {
        return NULL;
    }
    lbl_3_bss_1902 = 1;
    GXInitTexObj(obj, lbl_3_bss_1940, width, height, GX_TF_IA8, GX_REPEAT, GX_REPEAT, GX_FALSE);
    GXInitTexObjLOD(obj, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    return lbl_3_bss_1940;
}

// .text:0x000B9524 size:0x10 mapped:0x806F85B8
void fn_3_B9524(void) {
    lbl_3_bss_1902 = 0;
}

// .text:0x000B9510 size:0x14 mapped:0x806F85A4
void fn_3_B9510(s32 idx) {
    lbl_3_data_11168[idx] = 1;
}

// .text:0x000B950C size:0x4 mapped:0x806F85A0
void fn_3_B950C(void) {
    return;
}

// .text:0x000B93CC size:0x140 mapped:0x806F8460
void fn_3_B93CC(void) {
    s32 i;

    if (g_d_GameSettings._55 != 0) {
        return;
    }
    if (g_GameLogic.gameStatus == 0) {
        lbl_3_common_bss_350E4._66 = rand();
    }
    if (lbl_80366158._28 != 0) {
        if (g_d_GameSettings.GameModeSelected == 2 && lbl_3_common_bss_350E4._1C != NULL) {
            lbl_3_common_bss_350E4._1C();
        }
        return;
    }
    if (lbl_3_common_bss_350E4._18 != NULL) {
        lbl_3_common_bss_350E4._18();
    }
    if (lbl_3_common_bss_350E4._1C != NULL) {
        lbl_3_common_bss_350E4._1C();
    }
    if (g_GameLogic.gameStatus == 0) {
        fn_800638CC();
    }
    for (i = 0; i < lbl_3_common_bss_350E4._30; i++) {
        if (lbl_3_common_bss_350E4._00[i]._7C != NULL) {
            lbl_3_common_bss_350E4._00[i]._7C(&lbl_3_common_bss_350E4._00[i]);
        }
    }
}

// .text:0x000B93C8 size:0x4 mapped:0x806F845C
void fn_3_B93C8(int arg0) {
    return;
}

// .text:0x000B93C4 size:0x4 mapped:0x806F8458
void fn_3_B93C4(void) {
    return;
}

// .text:0x000B939C size:0x28 mapped:0x806F8430
void fn_3_B939C(void) {
    lbl_3_common_bss_350E4._6C = g_GameLogic.gameStatus == 2;
}

// .text:0x000B91C8 size:0x1D4 mapped:0x806F825C
StadiumObjectCollision* fn_3_B91C8(int stadium, s32 object, Mtx mtx) {
    if (stadium == 1) {
        return fn_3_C823C(object, mtx);
    } else if (stadium == 2) {
        if (g_Ball.AtBat_ContactResult >= 2) {
            return NULL;
        }
        CTRLBuildMatrix(&lbl_3_common_bss_350E4._00[object].control, mtx);
        return lbl_3_common_bss_350E4._00[object]._78;
    } else if (stadium == 3) {
        if (g_Ball.currentStarSwing2 == 11 | g_Ball.currentStarSwing2 == 12) {
            return NULL;
        }
        return fn_3_E4BE8(object, mtx);
    } else if (stadium == 4) {
        if (g_Ball.AtBat_ContactResult >= 2 | g_Ball.currentStarSwing2 == 11 | g_Ball.currentStarSwing2 == 12) {
            return NULL;
        }
        CTRLBuildMatrix(&lbl_3_common_bss_350E4._00[object].control, mtx);
        return lbl_3_common_bss_350E4._00[object]._78;
    } else if (stadium == 5) {
        if (g_Ball.AtBat_ContactResult >= 2) {
            return NULL;
        }
        return fn_3_F6504(object, mtx);
    } else if (stadium == 6) {
        return fn_3_E751C(object, mtx);
    } else {
        CTRLBuildMatrix(&lbl_3_common_bss_350E4._00[object].control, mtx);
        return lbl_3_common_bss_350E4._00[object]._78;
    }
}

// .text:0x000B916C size:0x5C mapped:0x806F8200
void processStadiumObjectFunction(int stadium, s32 object, int type, struct _CollisionStruct* collision) {
    if (object < lbl_3_common_bss_350E4._30) {
        if (lbl_3_common_bss_350E4._00[object]._80 != NULL) {
            lbl_3_common_bss_350E4._00[object]._80(object, type, collision);
        }
    }
}

// .text:0x000B9124 size:0x48 mapped:0x806F81B8
void fn_3_B9124(void) {
    memcpy(lbl_3_common_bss_350E4._04, lbl_3_common_bss_350E4._00,
           lbl_3_common_bss_350E4._30 * sizeof(StadiumObject1D58));
    lbl_3_common_bss_350E4._68 = lbl_3_common_bss_350E4._66;
}

// .text:0x000B908C size:0x98 mapped:0x806F8120
void fn_3_B908C(void) {
    if (lbl_3_bss_1904 == NULL) {
        lbl_3_bss_1904 = _OSAllocFromHeap(0x20, lbl_3_common_bss_350E4._30 * sizeof(StadiumObject1D58));
        memcpy(lbl_3_bss_1904, lbl_3_common_bss_350E4._00, lbl_3_common_bss_350E4._30 * sizeof(StadiumObject1D58));
    }
    memcpy(lbl_3_common_bss_350E4._00, lbl_3_common_bss_350E4._04,
           lbl_3_common_bss_350E4._30 * sizeof(StadiumObject1D58));
    lbl_3_common_bss_350E4._66 = lbl_3_common_bss_350E4._68;
}

// .text:0x000B902C size:0x60 mapped:0x806F80C0
void fn_3_B902C(void) {
    if (lbl_3_bss_1904 != NULL) {
        memcpy(lbl_3_common_bss_350E4._00, lbl_3_bss_1904, lbl_3_common_bss_350E4._30 * sizeof(StadiumObject1D58));
        fn_800ACFB0(lbl_3_bss_1904);
        lbl_3_bss_1904 = NULL;
    }
}

// .text:0x000B8C08 size:0x424 mapped:0x806F7C9C
void fn_3_B8C08(Mtx view) {
    return;
}

// .text:0x000B8828 size:0x3E0 mapped:0x806F78BC
void fn_3_B8828(void) {
    return;
}

// .text:0x000B867C size:0x1AC mapped:0x806F7710
void fn_3_B867C(void) {
    return;
}

// .text:0x000B8658 size:0x24 mapped:0x806F76EC
s32 fn_3_B8658(const void* a, const void* b) {
    f32 da = ((const StadiumSort1D58*)a)->depth;
    f32 db = ((const StadiumSort1D58*)b)->depth;

    if (da < db) {
        return -1;
    }
    return da > db;
}

// .text:0x000B85DC size:0x7C mapped:0x806F7670
void fn_3_B85DC(s32 area, Vec* min, Vec* max) {
    memcpy(min, &lbl_3_common_bss_350E4._48[area * 2], sizeof(Vec));
    memcpy(max, &lbl_3_common_bss_350E4._48[area * 2 + 1], sizeof(Vec));
}

// .text:0x000B85A8 size:0x34 mapped:0x806F763C
u32 fn_3_B85A8(s32 area, s32** objects) {
    *objects = &lbl_3_common_bss_350E4._44[lbl_3_common_bss_350E4._40[area]];
    return lbl_3_common_bss_350E4._3C[area];
}

// .text:0x000B8574 size:0x34 mapped:0x806F7608
void fn_3_B8574(void) {
    lbl_3_bss_1910[0].x = 10000.0f;
    lbl_3_bss_1910[0].y = 10000.0f;
    lbl_3_bss_1910[0].z = 10000.0f;
    lbl_3_bss_1910[1].x = -10000.0f;
    lbl_3_bss_1910[1].y = -10000.0f;
    lbl_3_bss_1910[1].z = -10000.0f;
}

// .text:0x000B8464 size:0x110 mapped:0x806F74F8
void fn_3_B8464(Mtx mtx, StadiumObjectCollision* collision) {
    Vec v;
    s32 n;
    TriangleGroup* group = collision->triangles;
    u16 count;

    while (TRUE) {
        count = group->count;
        if (count == 0) {
            break;
        }
        n = group->isTriangleList ? count + 2 : count * 3;
        group = (TriangleGroup*)group->tris;
        do {
            PSMTXMultVec(mtx, &((CollisionTriangle*)group)->trianglePoint, &v);
            group = (TriangleGroup*)((CollisionTriangle*)group + 1);
            if (lbl_3_bss_1910[0].x > v.x) {
                lbl_3_bss_1910[0].x = v.x;
            }
            if (lbl_3_bss_1910[0].y > v.y) {
                lbl_3_bss_1910[0].y = v.y;
            }
            if (lbl_3_bss_1910[0].z > v.z) {
                lbl_3_bss_1910[0].z = v.z;
            }
            if (lbl_3_bss_1910[1].x < v.x) {
                lbl_3_bss_1910[1].x = v.x;
            }
            if (lbl_3_bss_1910[1].y < v.y) {
                lbl_3_bss_1910[1].y = v.y;
            }
            if (lbl_3_bss_1910[1].z < v.z) {
                lbl_3_bss_1910[1].z = v.z;
            }
        } while (--n);
    }
}

// .text:0x000B8414 size:0x50 mapped:0x806F74A8
void fn_3_B8414(Vec* min, Vec* max) {
    memcpy(min, &lbl_3_bss_1910[0], sizeof(Vec));
    memcpy(max, &lbl_3_bss_1910[1], sizeof(Vec));
}

// .text:0x000B8298 size:0x17C mapped:0x806F732C
void fn_3_B8298(void) {
    StadiumObject1D58* obj;
    u32 i;

    switch (g_d_GameSettings.StadiumID) {
    case 3:
        fn_8003A548(fn_3_B80D0);
        break;
    }
    for (i = 0; i < lbl_3_common_bss_350E4._30; i++) {
        obj = &lbl_3_common_bss_350E4._00[i];
        if (obj->_90_7 && obj->_74 != NULL && obj->_9A != 0) {
            fn_3_B828C(obj);
            fn_3_B8184(obj->_74, fn_800BF068()->_14->_40);
        }
    }
    fn_8003A548(NULL);
}

// .text:0x000B828C size:0xC mapped:0x806F7320
void fn_3_B828C(StadiumObject1D58* obj) {
    lbl_3_bss_190C = obj;
}

// .text:0x000B827C size:0x10 mapped:0x806F7310
StadiumObject1D58* fn_3_B827C(void) {
    return lbl_3_bss_190C;
}

// .text:0x000B8184 size:0xF8 mapped:0x806F7218
void fn_3_B8184(StadiumModel1D58* model, Mtx view) {
    Mtx mv;
    Mtx m;
    ModelActor1D58* actor;
    ModelBone1D58* bone;

    CTRLBuildMatrix(&lbl_3_bss_190C->control, m);
    if (m[1][3] > 0.0f && g_d_GameSettings.StadiumID == 1) {
        return;
    }
    PSMTXConcat(view, m, mv);
    actor = model->actor;
    bone = actor->drawHead;
    if (actor->skinObject != NULL) {
        if (actor->_7C != NULL) {
            fn_8003A8A0(actor->skinObject, mv, 1);
        } else {
            DOVARenderSkin(actor->skinObject, mv, actor->skinMtxArray, actor->skinInvTransposeMtxArray, 0, NULL);
        }
    }
    while (bone != NULL) {
        if (bone->_014 != NULL) {
            DOSetWorldMatrix(bone->_014, bone->_0EC);
            fn_8003A8A0(bone->_014, mv, 0);
        }
        bone = bone->_100;
    }
}

// .text:0x000B80D0 size:0xB4 mapped:0x806F7164
void fn_3_B80D0(void) {
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
}

// .text:0x000B7FC8 size:0x108 mapped:0x806F705C
s32 fn_3_B7FC8(u32 id, s32 arg1) {
    return 0;
}
