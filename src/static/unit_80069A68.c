#include "static/unit_80069A68.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "Dolphin/gx.h"
#include "static/sub.h"
#include "Dolphin/vi.h"

typedef struct SceneTask {
    /* 0x00 */ void (*func)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u16 priority;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16[0x34 - 0x16];
    /* 0x34 */ s16 state;
    /* 0x36 */ s16 _36;
    /* 0x38 */ u8 _38;
    /* 0x39 */ u8 _39[0x3B - 0x39];
    /* 0x3B */ u8 _3B;
} SceneTask;

typedef struct SceneGlobals {
    /* 0x00 */ u8 _00[0x28];
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

typedef struct TexBank {
    /* 0x00 */ u32 _00;
    /* 0x04 */ TextureDesc tex[1];
} TexBank;

extern SceneTask* lbl_803CC1B8;
extern SceneGlobals lbl_80366158;
extern SceneObjSlot lbl_80371C30[];
extern SceneSound lbl_800EF808;
extern SceneMenuState lbl_803716B8;
extern void* lbl_803CBD30;
extern GXRenderModeObj* lbl_803CBD34;
extern GXRenderModeObj lbl_80109250;
extern GXRenderModeObj lbl_8010928C;
extern u8 lbl_801092E8[];
extern u8 lbl_801092F8[];
extern u8 lbl_80109378[];

extern BOOL fn_80021518(s32 group, void* data);
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
}

// .text:0x8006BB60 size:0x2A0
void fn_8006BB60(void) {
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
}

// .text:0x8006AF6C size:0x30
void fn_8006AF6C(void) {
    if (lbl_803CC1B8->_3B == 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x8006AC24 size:0x348
void fn_8006AC24(void) {
}

// .text:0x8006A824 size:0x400
void fn_8006A824(void) {
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
void fn_8006A194(void) {
}

// .text:0x80069BDC size:0x5B8
void fn_80069BDC(void) {
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

