#include "static/unit_80069A68.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "static/sub.h"
#include "Dolphin/vi.h"

typedef struct TexBank {
    /* 0x00 */ u32 _00;
    /* 0x04 */ TextureDesc tex[1];
} TexBank;

typedef struct FadeParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ void (*draw)(struct FadeParams* params);
    /* 0x08 */ s32 mode;
    /* 0x0C */ TexBank* bank;
    /* 0x10 */ s32 index;
    /* 0x14 */ s32 index2;
    /* 0x18 */ f32 alpha;
    /* 0x1C */ f32 alpha2;
} FadeParams;

typedef struct SceneTask {
    /* 0x00 */ void (*func)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u16 priority;
    union {
        /* 0x14 */ u16 _14;
        /* 0x14 */ u32* texFile;
    };
    /* 0x18 */ struct FadeParams* fades;
    /* 0x1C */ void* _1C;
    /* 0x20 */ void* _20;
    /* 0x24 */ void* _24;
    /* 0x28 */ u32* sabFile;
    /* 0x2C */ u8 _2C[0x34 - 0x2C];
    /* 0x34 */ s16 state;
    /* 0x36 */ u16 _36;
    /* 0x38 */ u8 _38;
    /* 0x39 */ u8 _39;
    /* 0x3A */ u8 _3A;
    /* 0x3B */ u8 _3B;
} SceneTask;

typedef struct SceneGlobals {
    /* 0x00 */ u8 _00[0x20];
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21[0x28 - 0x21];
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
    /* 0x2A */ u8 _2A;
} SceneGlobals;

typedef struct SceneObj {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ u32 flags;
    /* 0x58 */ u8 _58[0x5C - 0x58];
    /* 0x5C */ s32 _5C;
} SceneObj;

typedef struct SceneObjSlot {
    /* 0x0 */ SceneObj* obj;
    /* 0x4 */ u32 _4;
} SceneObjSlot;

typedef struct SceneSound {
    /* 0x00 */ u8 _00[0xC0];
    /* 0x0C0 */ void* _C0;
} SceneSound;

typedef struct SceneMenuState {
    /* 0x000 */ u8 _000[0x1E9];
    /* 0x1E9 */ u8 _1E9;
} SceneMenuState;

typedef struct SceneFlags {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} SceneFlags;

typedef struct SceneAram {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ u8 _715;
} SceneAram;



extern SceneTask* lbl_803CC1B8;
extern SceneGlobals lbl_80366158;
extern SceneObjSlot lbl_80371C30[];
extern SceneSound lbl_800EF808;
extern SceneMenuState lbl_803716B8;
extern SceneFlags lbl_8037169C;
extern SceneAram lbl_803C6CF8;
extern GXColor lbl_803CB8DC;
extern u8 lbl_803CBBC0;
extern void* lbl_803CBD30;
extern GXRenderModeObj* lbl_803CBD34;
typedef struct SceneCallback {
    /* 0x0 */ s32 id;
    /* 0x4 */ void (*func)(void);
    /* 0x8 */ void* arg;
} SceneCallback;

static GXRenderModeObj lbl_80109250 = {
    VI_TVMODE_NTSC_INT, 608, 448, 448, 27, 16, 666, 448, VI_XFBMODE_DF, GX_FALSE, GX_FALSE,
    { { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 } },
    { 8, 8, 10, 12, 10, 8, 8 },
};
static GXRenderModeObj lbl_8010928C = {
    2, 608, 448, 448, 27, 16, 666, 448, VI_XFBMODE_SF, GX_FALSE, GX_FALSE,
    { { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 } },
    { 0, 0, 21, 22, 21, 0, 0 },
};
static u32 lbl_801092C8[4] = { 0x0, 0x5233458, 0x12000, 0x5233458 };
static u32 lbl_801092D8[4] = { 0x40B, 0x40078660, 0x6C7B000, 0x1AF54 };
static u32 lbl_801092E8[4] = { 0x40B, 0x4006C850, 0x6C96000, 0x2C884 };
static u32 lbl_801092F8[32] = { 0x1, 0x0, 0x0, 0xFFFFFFFF, 0x21400FF, 0x16000000, 0x0, 0x10000, 0x0, 0x0, 0x0, 0xFFFFFFFF, 0x3140000, 0x16000000, 0x0, 0x10001, 0x2, 0x0, 0x0, 0xFFFFFFFF, 0x3020000, 0x16000000, 0x0, 0x10001, 0x30000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
static u32 lbl_80109378[16] = { 0x3, 0x0, 0x0, 0xFFFFFFFF, 0x30100FF, 0x16000000, 0x0, 0x0, 0x30000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
static SceneCallback lbl_801093B8 = { 0x0000002F, fn_80069A68, 0x00000000 };

extern void fn_80008E00(void (*func)(s32));
extern void fn_8000900C(void);
extern void fn_80009018(void* arg0);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800ACFB0(void* ptr);
extern void fn_800AD070(void);
extern void fn_800AD500(void* arg0, void* arg1);
extern u32 fn_800AD6BC(void* arg0);
extern s32 fn_800AD780(void* arg0);
extern void fn_800AD830(void* arg0);
extern void fn_800AD95C(void* arg0, s32 arg1);
extern void fn_800AD9F4(void* arg0);
extern s32 fn_800ADAFC(void);
extern s32 fn_800ADB04(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern void fn_800ADBFC(void);
extern void fn_800ADC40(void* arg0, u32 arg1);
extern void fn_800A7D4C(s32 layer, FadeParams* params);
extern BOOL fn_80021518(s32 group, void* data);
extern void fn_800215F8(SceneCallback* callback);
extern void* fn_800ACF34(u32 align, u32 size);
extern s32 ARAMTransfer(void* src, void* dst, s32 arg2, s32 arg3);
extern void fn_80035750(void* sab, void* tex, s16 id);
extern void convertTextureHeader(void* tex);
extern BOOL fn_80022B68(void);
extern void changeScene(u8 scene, s16 arg1);
// static/spani_default.h declares fn_80035838 returning u8; its callers here test the full register
extern s32 fn_80035838(void* entry, u8 id);
extern void fn_80034CEC(void* task);
extern void fn_80034E20(void* task, void* desc);
extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*func)(void), u16 priority);

// .text:0x8006C0D0 size:0x30
void fn_8006C0D0(void) {
    fn_800B0A5C_insertQueue(fn_8006BE00, lbl_803CC1B8->priority);
}

// .text:0x8006C088 size:0x48
void fn_8006C088(s32 alt) {
    GXRenderModeObj* mode;

    if (alt != 0) {
        mode = &lbl_8010928C;
    } else {
        mode = &lbl_80109250;
    }
    lbl_803CBD34 = mode;
    VIConfigure(mode);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
}

// .text:0x8006BE00 size:0x288
void fn_8006BE00(void) {
    SceneTask* task = lbl_803CC1B8;

    switch (task->state) {
    case 0:
        if ((task->_3A = lbl_8037169C._13) != 0) {
            changeScene(1, 6);
        }
        GXSetCopyClear(lbl_803CB8DC, 0xFFFFFF);
        task->_36 = 0;
        task->fades = fn_800ACF34(0x20, 0x40);
        task->sabFile = fn_800ACF34(0x20, lbl_801092E8[1] & 0x0FFFFFFF);
        ARAMTransfer(lbl_801092E8, task->sabFile, 0, 0);
        task->state++;
    case 1:
        if ((s32)lbl_803C6CF8._715 == 1) {
            task->sabFile[0] += (u32)task->sabFile;
            task->sabFile[1] += (u32)task->sabFile;
            fn_80035750((void*)task->sabFile[1], (void*)task->sabFile[0], 0x16);
            task->texFile = fn_800ACF34(0x20, lbl_801092D8[1] & 0x0FFFFFFF);
            ARAMTransfer(lbl_801092D8, task->texFile, 0, 0);
            task->state++;
        }
        break;
    case 2:
        if (task->_36 != 0) {
            task->_36--;
        } else if ((task->_3A == 0 || lbl_8037169C._12 != 0) && (s32)lbl_803C6CF8._715 == 1) {
            if (lbl_80366158._29 == 0 || lbl_80366158._29 == 1) {
                fn_80008E00(fn_8006C088);
            }
            lbl_801093B8.arg = lbl_803CC1B8;
            fn_800215F8(&lbl_801093B8);
            task->texFile[0] += (u32)task->texFile;
            convertTextureHeader((void*)task->texFile[0]);
            task->state = 0;
            task->_38 = 0;
            task->_39 = 0;
            switch (lbl_80366158._29) {
            case 0:
                lbl_803CC1B8->func = fn_8006BB60;
                break;
            case 1:
                lbl_803CC1B8->func = fn_8006B78C;
                break;
            case 2:
                lbl_803CC1B8->func = fn_8006B668;
                break;
            }
        }
        break;
    }
}

// .text:0x8006BB60 size:0x2A0
void fn_8006BB60(void) {
    SceneTask* task = lbl_803CC1B8;

    fn_80022B68();
    switch (task->state) {
    case 0:
        if (++task->_38 == 30) {
            task->_36 = 90;
            task->state++;
        }
        break;
    case 1:
        if (task->_36-- == 0) {
            fn_8000900C();
            lbl_80366158._20 = 1;
            task->_36 = 3480;
            task->state++;
        }
        break;
    case 2:
    case 3:
        if (task->state == 2 && ++task->_39 == 30) {
            task->state = 3;
        } else if (task->state == 3 && --task->_39 == 0) {
            task->state = 2;
        }
        if (--task->_36 == 0 || lbl_803C77B8[0]._00 != 0) {
            task->state = 4;
        }
        break;
    case 4:
        if (--task->_38 == 0) {
            task->state = 0;
            lbl_803CC1B8->func = fn_8006B78C;
        }
        break;
    }
    task->fades[lbl_803CBBC0].mode = 0;
    task->fades[lbl_803CBBC0].bank = (TexBank*)task->texFile[0];
    task->fades[lbl_803CBBC0].index = 6;
    task->fades[lbl_803CBBC0].alpha = task->_38 / 30.0f;
    task->fades[lbl_803CBBC0].index2 = 7;
    task->fades[lbl_803CBBC0].alpha2 = task->_39 / 30.0f * task->_38 / 30.0f;
    task->fades[lbl_803CBBC0]._00 = 0;
    task->fades[lbl_803CBBC0].draw = fn_8006AC24;
    fn_800A7D4C(0, &task->fades[lbl_803CBBC0]);
}

// .text:0x8006B78C size:0x3D4
void fn_8006B78C(void) {
}

// .text:0x8006B668 size:0x124
void fn_8006B668(void) {
    SceneTask* task = lbl_803CC1B8;

    if (lbl_803716B8._1E9 == 0 && task->state != 6) {
        fn_80022B68();
    }
    switch (task->state) {
    case 0:
        if (task->_10 != 0) {
            fn_80034E20(fn_800B0A5C_insertQueue(fn_8006B230, lbl_803CC1B8->priority), lbl_801092F8);
            changeScene(3, 0);
            task->_38 = 0;
            task->_36 = 1;
            task->state++;
        }
        break;
    case 5:
        if (lbl_803CC1B8->_3B != 0) {
            task->state = 0;
            lbl_803CC1B8->func = fn_8006AF9C;
        }
        break;
    case 4:
    case 6:
        if (lbl_803CC1B8->_3B != 0) {
            task->state = 0;
            lbl_803CC1B8->func = fn_8006AF6C;
        }
        break;
    }
}

// .text:0x8006B230 size:0x438
void fn_8006B230(void) {
}

// .text:0x8006AF9C size:0x294
void fn_8006AF9C(void) {
    SceneTask* task = lbl_803CC1B8;

    switch (task->state) {
    case 0:
        task->_38 = 0;
        task->_36 = 0;
        task->_1C = _OSAllocFromHeap(0x20, 0x1C0);
        memset(task->_1C, 0, 0x1C0);
        task->_20 = _OSAllocFromHeap(0x20, 0x400000);
        fn_800ADC40(task->_20, 0x400000);
        task->state++;
        break;
    case 1:
        if (fn_800ADB04(lbl_801092C8, task->_1C, 0, 0) != 0) {
            fn_80009018(task->_1C);
            task->state++;
        }
        break;
    case 2:
        if (fn_800ADAFC() != 0) {
            u32 size = fn_800AD6BC(task->_1C);

            task->_24 = _OSAllocFromHeap(0x20, size);
            fn_800AD500(task->_1C, task->_24);
            fn_800AD95C(task->_1C, 1);
            task->state++;
        }
        break;
    case 3:
        if (lbl_803C77B8[0]._04 & 0x1000) {
            task->state = 5;
            break;
        }
    case 4:
        if (fn_800AD780(task->_1C) != 0) {
            fn_80009018(NULL);
            fn_800AD9F4(task->_1C);
            fn_800ADBFC();
            fn_800ACFB0(task->_24);
            fn_800ACFB0(task->_20);
            fn_800ACFB0(task->_1C);
            task->state = 0;
            lbl_803CC1B8->_3B = 0;
            lbl_803CC1B8->func = fn_8006B668;
            return;
        }
        break;
    case 5:
        if (++task->_38 == 30) {
            fn_800AD830(task->_1C);
            task->state = 4;
        }
        break;
    }
    if (task->state >= 3) {
        fn_800AD070();
    }
    if (task->_38 != 0) {
        task->fades[lbl_803CBBC0].mode = 4;
        task->fades[lbl_803CBBC0].alpha = task->_38;
        task->fades[lbl_803CBBC0]._00 = 0;
        task->fades[lbl_803CBBC0].draw = fn_8006AC24;
        fn_800A7D4C(14, &task->fades[lbl_803CBBC0]);
    }
}

// .text:0x8006AF6C size:0x30
void fn_8006AF6C(void) {
    if (lbl_803CC1B8->_3B == 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x8006AC24 size:0x348
void fn_8006AC24(FadeParams* params) {
    switch (params->mode) {
    case 0: {
        Mtx mv;
        Mtx44 proj;

        PSMTXIdentity(mv);
        C_MTXOrtho(proj, -23.0f, 448.0f, 0.0f, 608.0f, -100.0f, 100.0f);
        GXSetProjection(proj, GX_ORTHOGRAPHIC);
        GXLoadPosMtxImm(mv, GX_PNMTX0);
        GXSetCurrentMtx(GX_PNMTX0);
        fn_80069BDC(params->bank, params->index, params->alpha, params->index2, params->alpha2);
        break;
    }
    case 1: {
        Mtx mv;
        Mtx44 proj;

        PSMTXIdentity(mv);
        C_MTXOrtho(proj, -23.0f, 448.0f, 0.0f, 608.0f, -100.0f, 100.0f);
        GXSetProjection(proj, GX_ORTHOGRAPHIC);
        GXLoadPosMtxImm(mv, GX_PNMTX0);
        GXSetCurrentMtx(GX_PNMTX0);
        fn_8006A824(params->bank, params->index, params->alpha);
        break;
    }
    case 2: {
        Mtx mv;
        Mtx44 proj;

        PSMTXIdentity(mv);
        C_MTXOrtho(proj, 0.0f, 448.0f, 0.0f, 608.0f, -100.0f, 100.0f);
        GXSetProjection(proj, GX_ORTHOGRAPHIC);
        GXLoadPosMtxImm(mv, GX_PNMTX0);
        GXSetCurrentMtx(GX_PNMTX0);
        fn_8006A500(params->bank, params->index, params->alpha);
        break;
    }
    case 3: {
        Mtx mv;
        Mtx44 proj;

        PSMTXIdentity(mv);
        C_MTXOrtho(proj, 0.0f, 448.0f, 0.0f, 608.0f, -100.0f, 100.0f);
        GXSetProjection(proj, GX_ORTHOGRAPHIC);
        GXLoadPosMtxImm(mv, GX_PNMTX0);
        GXSetCurrentMtx(GX_PNMTX0);
        fn_8006A194(params->bank, params->index, params->alpha);
        break;
    }
    case 4: {
        Mtx mv;
        Mtx44 proj;

        PSMTXIdentity(mv);
        C_MTXOrtho(proj, 0.0f, 448.0f, 0.0f, 640.0f, 0.0f, 1.0f);
        GXSetProjection(proj, GX_ORTHOGRAPHIC);
        GXLoadPosMtxImm(mv, GX_PNMTX0);
        GXSetCurrentMtx(GX_PNMTX0);
        gOz_GXSetTexture(GX_PASSCLR, 0, 0);
        GXBegin(GX_QUADS, GX_VTXFMT0, 4);
        GXPosition3f32(0.0f, 0.0f, -0.5f);
        GXColor4u8(0, 0, 0, 255.0f * params->alpha / 30.0f);
        GXPosition3f32(640.0f, 0.0f, -0.5f);
        GXColor4u8(0, 0, 0, 255.0f * params->alpha / 30.0f);
        GXPosition3f32(640.0f, 448.0f, -0.5f);
        GXColor4u8(0, 0, 0, 255.0f * params->alpha / 30.0f);
        GXPosition3f32(0.0f, 448.0f, -0.5f);
        GXColor4u8(0, 0, 0, 255.0f * params->alpha / 30.0f);
        break;
    }
    }
}

// .text:0x8006A824 size:0x400
void fn_8006A824(TexBank* bank, s32 index, f32 alpha) {
    f32 c;

    GXSetDispCopySrc(0, 0, lbl_80109250.fbWidth, lbl_80109250.efbHeight);
    GXSetDispCopyDst(lbl_80109250.fbWidth, lbl_80109250.efbHeight);
    GXSetDispCopyYScale((f32)lbl_80109250.xfbHeight / (f32)lbl_80109250.efbHeight);
    GXSetScissor(0, 0, 608, 448);
    GXSetViewport(0.0f, 0.0f, 608.0f, 448.0f, -1.0f, 1.0f);
    SetDisplayStateTexture(&bank->tex[index], GX_TEXMAP0, 0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_U16, 0);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxDesc(GX_VA_CLR1, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR1, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_COLOR1A1, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(2);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR1A1);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_RASC);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_C0, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(2);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    c = 220.0f * alpha;
    GXPosition3s16(117, 154, 0);
    GXColor1u32(0);
    GXColor4u8(c, 0, 0, 255);
    GXTexCoord2u8(0, 0);
    GXPosition3s16(493, 154, 0);
    GXColor1u32(0);
    GXColor4u8(c, 0, 0, 255);
    GXTexCoord2u8(1, 0);
    GXPosition3s16(493, 258, 0);
    GXColor1u32(0);
    GXColor4u8(c, 0, 0, 255);
    GXTexCoord2u8(1, 1);
    GXPosition3s16(117, 257, 0);
    GXColor1u32(0);
    GXColor4u8(c, 0, 0, 255);
    GXTexCoord2u8(0, 1);
}

// .text:0x8006A500 size:0x324
void fn_8006A500(TexBank* bank, s32 index, f32 alpha) {
    u32 halfW;
    u32 halfH;
    f32 c;

    GXSetDispCopySrc(0, 0, lbl_80109250.fbWidth, lbl_80109250.efbHeight);
    GXSetDispCopyDst(lbl_80109250.fbWidth, lbl_80109250.efbHeight);
    GXSetDispCopyYScale((f32)lbl_80109250.xfbHeight / (f32)lbl_80109250.efbHeight);
    GXSetScissor(0, 0, 608, 448);
    GXSetViewport(0.0f, 0.0f, 608.0f, 448.0f, -1.0f, 1.0f);
    SetDisplayStateTexture(&bank->tex[index], GX_TEXMAP0, 0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_U16, 0);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    GXSetNumTevStages(1);
    halfW = bank->tex[index].width / 2u;
    halfH = bank->tex[index].height / 2u;
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    c = 255.0f * alpha;
    GXPosition3s16(304 - halfW, 224 - halfH, 0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(0, 0);
    GXPosition3s16(halfW + 304, 224 - halfH, 0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(1, 0);
    GXPosition3s16(halfW + 304, halfH + 224, 0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(1, 1);
    GXPosition3s16(304 - halfW, halfH + 224, 0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(0, 1);
}

// .text:0x8006A194 size:0x36C
void fn_8006A194(TexBank* bank, s32 index, f32 alpha) {
    f32 c;

    GXSetDispCopySrc(0, 0, lbl_80109250.fbWidth, lbl_80109250.efbHeight);
    GXSetDispCopyDst(lbl_80109250.fbWidth, lbl_80109250.efbHeight);
    GXSetDispCopyYScale((f32)lbl_80109250.xfbHeight / (f32)lbl_80109250.efbHeight);
    GXSetScissor(0, 0, 608, 448);
    GXSetViewport(0.0f, 0.0f, 608.0f, 448.0f, -1.0f, 1.0f);
    SetDisplayStateTexture(&bank->tex[index], GX_TEXMAP0, 0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_U16, 0);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(1);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    c = 255.0f * alpha;
    GXPosition3s16(189, 150, 0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(0, 0);
    GXPosition3s16(421, 150, 0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(1, 0);
    GXPosition3s16(421, 262, 0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(1, 1);
    GXPosition3s16(189, 262, 0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(0, 1);
}

// .text:0x80069BDC size:0x5B8
void fn_80069BDC(TexBank* bank, s32 index, f32 alpha, s32 index2, f32 alpha2) {
    f32 c;

    GXSetDispCopySrc(0, 0, lbl_80109250.fbWidth, lbl_80109250.efbHeight);
    GXSetDispCopyDst(lbl_80109250.fbWidth, lbl_80109250.efbHeight);
    GXSetDispCopyYScale((f32)lbl_80109250.xfbHeight / (f32)lbl_80109250.efbHeight);
    GXSetScissor(0, 0, 608, 448);
    GXSetViewport(0.0f, 0.0f, 608.0f, 448.0f, -1.0f, 1.0f);
    SetDisplayStateTexture(&bank->tex[index], GX_TEXMAP0, 0);
    SetDisplayStateTexture(&bank->tex[index2], GX_TEXMAP1, 1);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_U16, 0);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxDesc(GX_VA_CLR1, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR1, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_COLOR1A1, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(2);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR1A1);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_RASC);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_C0, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(2);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    c = 255.0f * alpha;
    GXPosition3s16(0, 0, 0);
    GXColor1u32(0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(0, 0);
    GXPosition3s16(608, 0, 0);
    GXColor1u32(0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(1, 0);
    GXPosition3s16(608, 448, 0);
    GXColor1u32(0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(1, 1);
    GXPosition3s16(0, 448, 0);
    GXColor1u32(0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(0, 1);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR1A1);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    c = 255.0f * alpha2;
    GXPosition3s16(0, 359, 0);
    GXColor1u32(0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(0, 0);
    GXPosition3s16(608, 359, 0);
    GXColor1u32(0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(1, 0);
    GXPosition3s16(608, 407, 0);
    GXColor1u32(0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(1, 1);
    GXPosition3s16(0, 407, 0);
    GXColor1u32(0);
    GXColor4u8(c, c, c, 255);
    GXTexCoord2u8(0, 1);
}

// .text:0x80069B68 size:0x74
s32 fn_80069B68(void) {
    if (fn_80035838(lbl_801092E8, 0x16) != 0) {
        lbl_803CBD30 = fn_800B0A5C_insertQueue(fn_80069B08, lbl_803CC1B8->priority);
        fn_80034E20(lbl_803CBD30, lbl_80109378);
        lbl_80366158._2A = 0;
        return 1;
    }
    return 0;
}

// .text:0x80069B08 size:0x60
void fn_80069B08(void) {
    SceneTask* task = lbl_803CC1B8;

    if (lbl_80366158._2A != 0) {
        lbl_80371C30[task->_14].obj->_5C = 0;
        lbl_80371C30[task->_14].obj->flags |= 2;
        lbl_803CC1B8->func = fn_80069AD4;
    }
}

// .text:0x80069AD4 size:0x34
void fn_80069AD4(void) {
    if (lbl_80366158._2A == 2) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x80069A98 size:0x3C
void fn_80069A98(void) {
    fn_80034CEC(lbl_803CBD30);
    lbl_803CBD30 = NULL;
    lbl_80366158._2A = 2;
}

// .text:0x80069A68 size:0x30
void fn_80069A68(void) {
    fn_80021518(0x35, lbl_800EF808._C0);
}

