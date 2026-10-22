#include "C3/DisplayObject.h"
extern void OSReport(const char* msg, ...);
#include "string.h"
#include "stl/math.h"

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800ACFB0(void* data);
extern void SKNLoadFile(void* skn, void* hdr);
extern MtxPtr fn_800BEB80(u8 index);
extern f32 lbl_80111750[][3];
extern u8 fn_800BEBA0(void);
extern void fn_800BF008(void);
extern struct { u8 _00[0x4C]; u8 _4C; }* fn_800BF068(void);

typedef struct FogSettings {
    /* 0x00 */ GXFogType type;
    /* 0x04 */ f32 startz;
    /* 0x08 */ f32 endz;
    /* 0x0C */ f32 nearz;
    /* 0x10 */ f32 farz;
    /* 0x14 */ GXColor color;
} FogSettings; // size: 0x18

FogSettings lbl_80111700 = { 0 };

u32 lbl_803CBB58 = 1;
u8 lbl_803CBB60 = 0x40;

// .bss, declared from the highest address down
GXTexObj lbl_803CB5FC[8];
GXTlutObj lbl_803CB49C[29];

// .sbss, declared from the highest address down
GXColor lbl_803CC224;
u8 lbl_803CC220;
u32 lbl_803CC21C;
f32 lbl_803CC218;
u8 lbl_803CC210[8];
DOShadowCallback lbl_803CC20C;
Mtx* lbl_803CC208;
Mtx* lbl_803CC204;
DOTevCallback lbl_803CC200;
f32 lbl_803CC1FC;
f32 lbl_803CC1F8;
DOEnvCallback lbl_803CC1F4;
Light* lbl_803CC1F0;

static inline u32 GetQuantizeSize(u8 quantizeInfo) {
    switch ((u8)(quantizeInfo >> 4)) {
    case GX_U8:
    case GX_S8:
        return 1;
    case GX_U16:
    case GX_S16:
        return 2;
    case GX_F32:
        return 4;
    default:
        return 0;
    }
}

// .text:0x800B993C size:0xC
void fn_800B993C(void) {
    lbl_803CC200 = NULL;
}

// .text:0x800B9948 size:0x8
void fn_800B9948(DOTevCallback arg0) {
    lbl_803CC200 = arg0;
}

// .text:0x800B9950 size:0x1C
void fn_800B9950(u32 flags, f32 arg1, f32 arg2) {
    if (flags & 1) {
        lbl_803CC1F8 = arg1;
    }
    if (flags & 2) {
        lbl_803CC1FC = arg2;
    }
}

// .text:0x800B996C size:0x8
void fn_800B996C(DOEnvCallback arg0) {
    lbl_803CC1F4 = arg0;
}

// .text:0x800B9974 size:0x50
void SetFogNone(void) {
    GXColor color;

    color.r = color.g = color.b = 0;
    GXSetFog(GX_FOG_NONE, 0.0f, 0.0f, 0.0f, 0.0f, color);
}

// .text:0x800B99C4 size:0x6C
// 69.63%: the target copies the float args to f7/f6/f5/f0, rounds them with frsp for GXSetFog
// and stores the unrounded copies; f32 and f64 parameters and a pointer local all fold the frsp.
void SetFog(GXFogType type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color) {
    lbl_80111700.type = type;
    lbl_80111700.startz = startz;
    lbl_80111700.endz = endz;
    lbl_80111700.nearz = nearz;
    lbl_80111700.farz = farz;
    lbl_80111700.color = color;
    GXSetFog(type, startz, endz, nearz, farz, color);
}

// .text:0x800B9A30 size:0x6C
void SetFogNoneAgain(void) {
    lbl_80111700.color.r = lbl_80111700.color.g = lbl_80111700.color.b = 0;
    lbl_80111700.type = GX_FOG_NONE;
    lbl_80111700.startz = 0.0f;
    lbl_80111700.endz = 0.0f;
    lbl_80111700.nearz = 0.0f;
    lbl_80111700.farz = 0.0f;
    GXSetFog(GX_FOG_NONE, 0.0f, 0.0f, 0.0f, 0.0f, lbl_80111700.color);
}

// .text:0x800B9A9C size:0xC
void fn_800B9A9C(u32 arg0, f32 arg1) {
    lbl_803CC21C = arg0;
    lbl_803CC218 = arg1;
}

// .text:0x800B9AA8 size:0x8
void fn_800B9AA8(Light* light) {
    lbl_803CC1F0 = light;
}

// .text:0x800B9AB0 size:0x3F8
s32 fn_800B9AB0(u32 mode, struct DODisplayObj* dispObj, DOState* state, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, GXChannelID* chan, MtxPtr camera) {
    Mtx sp100;
    Mtx spD0;
    Mtx spA0;
    Mtx sp70;
    Mtx sp40;
    Mtx sp10;
    GXTexGenSrc src = GX_TG_NRM;
    GXColor kcolor;
    GXTevColorArg colorArg;
    GXTevAlphaArg alphaArg;
    GXTevColorArg konst;
    f32 scale = 0.5f;

    if (lbl_803CBB58 == 0) {
        return -1;
    }
    if (dispObj == NULL || dispObj->lightingData == NULL || state == NULL) {
        return -1;
    }
    PSMTXIdentity(sp70);
    PSMTXIdentity(sp40);
    PSMTXConcat(camera, dispObj->worldMatrix, sp100);
    PSMTXInverse(sp100, spD0);
    PSMTXTranspose(spD0, sp70);
    PSMTXScale(spD0, -scale, scale, 0.0f);
    PSMTXTrans(spA0, 0.5f, 0.5f, 1.0f);
    PSMTXConcat(spA0, spD0, sp10);
    PSMTXScale(spD0, -scale, scale, 0.0f);
    PSMTXTrans(spA0, 0.5f + lbl_803CC1F8, 0.5f + lbl_803CC1FC, 1.0f);
    PSMTXConcat(spA0, spD0, sp40);
    if (mode == 5) {
        colorArg = GX_CC_RASC;
        *chan = GX_COLOR0A0;
        alphaArg = GX_CA_RASA;
    } else {
        colorArg = GX_CC_CPREV;
        *chan = GX_COLOR_NULL;
        alphaArg = GX_CA_APREV;
    }
    if (state->_01 != 0) {
        kcolor.r = kcolor.g = kcolor.b = kcolor.a = state->_01;
        konst = GX_CC_KONST;
        GXSetTevKColor(GX_KCOLOR0, kcolor);
        GXSetTevKColorSel(*stage, GX_TEV_KCSEL_K0);
    } else {
        konst = GX_CC_APREV;
    }
    if (dispObj->lightingData->compCount == 2) {
        src = GX_TG_BINRM;
    }
    GXLoadTexMtxImm(sp70, GX_TEXMTX0 + *map * 3, GX_MTX3x4);
    GXLoadTexMtxImm(sp40, GX_PTTEXMTX0 + *map * 3, GX_MTX3x4);
    GXSetTexCoordGen2(*coord, GX_TG_MTX3X4, src, GX_TEXMTX0 + *map * 3, GX_TRUE, GX_PTTEXMTX0 + *map * 3);
    GXSetTevOrder(*stage, *coord, *map, *chan);
    if (lbl_803CC210[*map] == 1) {
        GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_TEXC, konst, colorArg);
        GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    } else if (lbl_803CC210[*map] == 0) {
        GXSetTevColorIn(*stage, colorArg, GX_CC_TEXC, konst, GX_CC_ZERO);
        GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    } else {
        GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_TEXC, konst, colorArg);
        GXSetTevColorOp(*stage, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    }
    GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, alphaArg);
    GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    if (lbl_803CC1F4 != NULL) {
        (*coord)++;
        GXLoadTexMtxImm(sp70, GX_TEXMTX0 + (*map + 1) * 3, GX_MTX3x4);
        GXLoadTexMtxImm(sp10, GX_PTTEXMTX0 + (*map + 1) * 3, GX_MTX3x4);
        GXSetTexCoordGen2(*coord, GX_TG_MTX3X4, src, GX_TEXMTX0 + (*map + 1) * 3, GX_TRUE, GX_PTTEXMTX0 + (*map + 1) * 3);
        (*map)++;
        lbl_803CC1F4(*stage, 0, 1, *coord, *map);
    }
    (*stage)++;
    (*coord)++;
    (*map)++;
    return 0;
}

// .text:0x800B9EA8 size:0x5A4
s32 fn_800B9EA8(u32 mode, struct DODisplayObj* dispObj, DOState* state, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, GXChannelID* chan, MtxPtr camera) {
    Mtx spF4;
    Mtx spC4;
    Mtx sp94;
    Mtx sp64;
    Mtx sp34;
    Vec dir;
    Vec axis;
    Vec up = { 0.0f, 0.0f, 1.0f };
    GXTexGenSrc src = GX_TG_NRM;
    GXColor kcolor;
    GXTevColorArg colorArg;
    GXTevAlphaArg alphaArg;
    GXTevColorArg konst;
    GXTexMapID map2;
    f32 dot;
    f32 reflect;
    f32 scale;

    if (lbl_803CBB58 == 0) {
        return -1;
    }
    if (dispObj == NULL || dispObj->lightingData == NULL || lbl_803CC1F0 == NULL || state == NULL) {
        return -1;
    }
    PSMTXIdentity(sp64);
    PSMTXIdentity(sp34);
    PSMTXConcat(camera, dispObj->worldMatrix, spF4);
    PSMTXInverse(spF4, spC4);
    PSMTXTranspose(spC4, spF4);
    PSMTXMultVecSR(camera, &lbl_803CC1F0->direction, &dir);
    dot = PSVECDotProduct(&dir, &up);
    if (dot == -1.0f) {
        PSMTXScale(sp64, 0.0f, 0.0f, 0.0f);
        PSMTXScale(sp34, 0.0f, 0.0f, 0.0f);
    } else {
        dir.x = -dir.x;
        dir.y = -dir.y;
        dir.z = -dir.z;
        if (PSVECMag(&dir) == 0.0f) {
            return -1;
        }
        PSVECNormalize(&dir, &dir);
        if (dot == 1.0f) {
            PSMTXIdentity(spC4);
        } else {
            PSVECCrossProduct(&dir, &up, &axis);
            if (PSVECMag(&axis) == 0.0f) {
                PSMTXIdentity(spC4);
            } else {
                PSMTXRotAxisRad(spC4, &axis, acos(PSVECDotProduct(&up, &dir)));
            }
        }
        PSMTXConcat(spC4, spF4, sp64);
        if (lbl_803CC21C != 0) {
            reflect = lbl_803CC218;
        } else {
            reflect = (state->_01 & 0x7F) / 100.0f;
        }
        scale = 0.5f * (0.5f - reflect) + 0.75f;
        PSMTXScale(spC4, scale, -scale, 0.0f);
        PSMTXTrans(sp94, 0.5f, 0.5f, 1.0f);
        PSMTXConcat(sp94, spC4, sp34);
    }
    if (mode == 5) {
        colorArg = GX_CC_RASC;
        *chan = GX_COLOR0A0;
        alphaArg = GX_CA_RASA;
    } else {
        colorArg = GX_CC_CPREV;
        *chan = GX_COLOR_NULL;
        alphaArg = GX_CA_APREV;
    }
    if (dispObj->pad8 != 0) {
        kcolor.r = kcolor.g = kcolor.b = kcolor.a = dispObj->pad8;
        konst = GX_CC_KONST;
        GXSetTevKColor(GX_KCOLOR0, kcolor);
        GXSetTevKColorSel(*stage, GX_TEV_KCSEL_K0);
    } else {
        konst = GX_CC_APREV;
    }
    if (dispObj->lightingData->compCount == 2) {
        src = GX_TG_BINRM;
    }
    GXLoadTexMtxImm(sp64, GX_TEXMTX0 + *map * 3, GX_MTX3x4);
    GXLoadTexMtxImm(sp34, GX_PTTEXMTX0 + *map * 3, GX_MTX3x4);
    if (state->flags == 0) {
        GXSetTexCoordGen2(*coord, GX_TG_MTX3X4, src, GX_TEXMTX0 + *map * 3, GX_TRUE, GX_PTTEXMTX0 + *map * 3);
        GXSetTevOrder(*stage, *coord, *map, *chan);
        GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_TEXC, konst, colorArg);
        GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, alphaArg);
        GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        (*stage)++;
        (*coord)++;
        (*map)++;
    } else {
        map2 = *map + 1;
        GXSetTexCoordGen2(*coord, GX_TG_MTX2X4, map2 + GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
        GXSetTevOrder(*stage, *coord, map2, GX_COLOR0A0);
        GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
        GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
        GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_TEXA);
        GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
        (*stage)++;
        (*coord)++;
        GXSetTexCoordGen2(*coord, GX_TG_MTX3X4, src, GX_TEXMTX0 + *map * 3, GX_TRUE, GX_PTTEXMTX0 + *map * 3);
        GXSetTevOrder(*stage, *coord, *map, GX_COLOR_NULL);
        GXSetTevColorIn(*stage, colorArg, GX_CC_TEXC, GX_CC_C0, GX_CC_ZERO);
        GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, alphaArg);
        GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        (*stage)++;
        (*coord)++;
        *map += 2;
    }
    return 0;
}

// .text:0x800BA44C size:0x3FC
void DODefaultUserTevMode(s32 mode, struct DODisplayObj* dispObj, MtxPtr camera, u8* numTexGens, u8* numStages) {
    Mtx m;
    GXTevStageID stage;
    GXTexCoordID coord;
    GXTexMapID map;
    GXTevColorArg colorArg;
    GXTevAlphaArg alphaArg;
    GXChannelID chan;
    f32 x;
    f32 y;
    f32 len;
    f32 offset;

    if (dispObj->overrideTevMode) {
        OSReport("Error: DODefaultUserTevMode: Cannot override tev mode AND use default user tev mode function.\n");
        return;
    }
    stage = *numStages;
    coord = *numStages;
    map = *numStages;
    if (stage == GX_TEVSTAGE0) {
        colorArg = GX_CC_RASC;
        alphaArg = GX_CA_RASA;
        chan = GX_COLOR0A0;
    } else {
        colorArg = GX_CC_CPREV;
        alphaArg = GX_CA_APREV;
        chan = GX_COLOR_NULL;
    }
    switch (mode) {
    case 9:
        GXSetTevOrder(stage, coord, map, chan);
        GXSetTevColorIn(stage, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, colorArg);
        GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, alphaArg);
        GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        break;
    case 10:
        GXSetTevOrder(stage, coord, map, chan);
        GXSetTevColorIn(stage, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, colorArg);
        GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, alphaArg);
        GXSetTevColorOp(stage, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        break;
    case 11:
        x = camera[2][0];
        y = camera[2][1];
        if (x == 0.0f && y == 0.0f) {
            GXSetTexCoordGen2(coord, GX_TG_MTX2X4, *numStages + GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
        } else {
            len = dolsqrtf2(x * x + y * y);
            offset = 0.159154f * (f32)asin(y / len);
            if (x < 0.0f) {
                offset = 0.5f - offset;
            }
            PSMTXIdentity(m);
            m[0][0] = 2.0f;
            m[0][3] = -offset;
            GXLoadTexMtxImm(m, GX_TEXMTX0 + *numStages * 3, GX_MTX3x4);
            GXSetTexCoordGen2(coord, GX_TG_MTX3X4, *numStages + GX_TG_TEX0, GX_TEXMTX0 + *numStages * 3, GX_FALSE, GX_PTIDENTITY);
        }
        GXSetTevOrder(stage, coord, map, chan);
        GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_APREV, colorArg);
        GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_KONST);
        GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        break;
    default:
        OSReport("Warning: DODefaultUserTevMode: Unknown user tev mode %d\n", mode);
        return;
    }
    (*numTexGens)++;
    (*numStages)++;
}

// .text:0x800BA848 size:0x12E4
// 99.86%: numChans and bumpState take each other's registers (r26/r24) and case 8 swaps two
// temporaries; every order of the six counter declarations was tried.
void Custom_SetState(struct DODisplayObj* dispObj, DOState* state, MtxPtr camera) {
    Mtx sp128;
    Mtx spF8;
    Mtx spC8;
    Mtx sp98;
    Mtx sp68;
    Mtx sp38;
    GXTevStageID stage = GX_TEVSTAGE0;
    GXTexCoordID coord = GX_TEXCOORD0;
    GXTexMapID map = GX_TEXMAP0;
    GXChannelID chan;
    GXColor kcolor;
    GXColor black;
    GXTevColorArg colorArg;
    GXTevAlphaArg alphaArg;
    GXTevColorArg konst;
    GXTexGenSrc src;
    u8 numChans = 0;
    u8 shift = 0;
    u8 bumpState = 0;
    u32 tevModes;
    s32 mode;
    u8 texIdx = 0;
    u8 numStages;
    u8 numTexGens;
    f32 scale;

    tevModes = state->tevModes;
    numStages = 0;
    numTexGens = 0;
    GXSetNumIndStages(0);
    for (mode = GX_TEVSTAGE0; mode < 16; mode++) {
        GXSetTevDirect((GXTevStageID)mode);
    }
    for (;;) {
        mode = (tevModes >> shift) & 0xF;
        if (mode == 0) {
            break;
        }
        switch (mode) {
        case 10:
            chan = GX_COLOR0A0;
            numChans++;
            GXSetTevOrder(stage, coord, map, GX_COLOR0A0);
            GXSetTexCoordGen2(coord, GX_TG_MTX2X4, texIdx + GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_RASC);
            GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_TEXA, GX_CA_RASA, GX_CA_ZERO);
            GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            texIdx++;
            numTexGens++;
            numStages++;
            break;
        case 12:
            chan = GX_COLOR_NULL;
            GXSetTevOrder(stage, coord, map, GX_COLOR_NULL);
            GXSetTexCoordGen2(coord, GX_TG_MTX2X4, texIdx + GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_CPREV, GX_CC_ZERO);
            GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_TEXA, GX_CA_APREV, GX_CA_ZERO);
            GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            if (lbl_803CC210[map] == 2) {
                numStages++;
                GXSetTevOrder(stage + 1, coord, map, chan);
                GXSetTevColorIn(stage + 1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_APREV, GX_CC_ZERO);
                GXSetTevColorOp(stage + 1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                GXSetTevAlphaIn(stage + 1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                GXSetTevAlphaOp(stage + 1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            }
            texIdx++;
            numTexGens++;
            numStages++;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            if (numStages != 0 || mode == 4) {
                chan = GX_COLOR_NULL;
            } else {
                chan = GX_COLOR0A0;
            }
            GXSetTevOrder(stage, coord, map, chan);
            GXSetTexCoordGen2(coord, GX_TG_MTX2X4, texIdx + GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            GXSetTevOp(stage, (GXTevMode)(mode - 1));
            if (lbl_803CC210[map] == 2) {
                numStages++;
                GXSetTevOrder(stage + 1, coord, map, GX_COLOR_NULL);
                GXSetTevColorIn(stage + 1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_APREV, GX_CC_ZERO);
                GXSetTevColorOp(stage + 1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                GXSetTevAlphaIn(stage + 1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                GXSetTevAlphaOp(stage + 1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            }
            texIdx++;
            numTexGens++;
            numStages++;
            break;
        case 5:
            if (dispObj->envTexObj == NULL) {
                GXSetTevOrder(stage, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
                GXSetTevOp(stage, GX_PASSCLR);
                numStages++;
            }
            break;
        case 6:
            if (numStages != 0 || mode == 4) {
                chan = GX_COLOR_NULL;
            } else {
                chan = GX_COLOR0A0;
            }
            GXSetTexCoordGen2(coord, GX_TG_MTX2X4, texIdx + GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            numTexGens++;
            GXSetTexCoordGen2(coord + 1, GX_TG_MTX2X4, texIdx + GX_TG_TEX1, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            GXSetTevOrder(stage, coord + 1, map + 1, GX_COLOR0A0);
            GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
            GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
            GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_TEXA, GX_CA_RASA, GX_CA_ZERO);
            GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
            numStages++;
            stage++;
            GXSetTevOrder(stage, coord, map, chan);
            GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_C0);
            GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
            GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_A0, GX_CA_TEXA, GX_CA_ZERO);
            GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
            bumpState = 1;
            texIdx++;
            numTexGens++;
            numStages++;
            break;
        case 7:
            if (bumpState == 0) {
                GXSetTexCoordGen2(coord, GX_TG_MTX2X4, texIdx + GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
                numTexGens++;
                GXSetTevOrder(stage, coord, map, GX_COLOR0A0);
                numStages++;
                GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
                GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
                GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_TEXA, GX_CA_RASA, GX_CA_ZERO);
                GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
                stage++;
            }
            GXSetTevOrder(stage, coord, map, GX_COLOR_NULL);
            texIdx++;
            numStages++;
            if (bumpState == 1) {
                switch (lbl_803CC210[map]) {
                case 0:
                default:
                    GXSetTevColorIn(stage, GX_CC_CPREV, GX_CC_C0, GX_CC_A0, GX_CC_ZERO);
                    GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    GXSetTevAlphaIn(stage, GX_CA_A0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                    GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    break;
                case 1:
                    GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_C0, GX_CC_C0, GX_CC_CPREV);
                    GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                    GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    break;
                case 2:
                    GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_C0, GX_CC_C0, GX_CC_CPREV);
                    GXSetTevColorOp(stage, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                    GXSetTevAlphaOp(stage, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    break;
                }
            } else {
                switch (lbl_803CC210[map]) {
                case 0:
                default:
                    GXSetTevColorIn(stage, GX_CC_CPREV, GX_CC_C0, GX_CC_TEXA, GX_CC_ZERO);
                    GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                    GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    break;
                case 1:
                    GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_C0, GX_CC_A0, GX_CC_CPREV);
                    GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                    GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    break;
                case 2:
                    GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_C0, GX_CC_A0, GX_CC_CPREV);
                    GXSetTevColorOp(stage, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                    GXSetTevAlphaOp(stage, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                    break;
                }
            }
            bumpState = 2;
            break;
        case 8: {
            GXColor shadowColor = { 0, 0, 0, 0x80 };

            scale = state->scale / 1000.0f;
            GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ZERO, GX_LO_CLEAR);
            PSMTXConcat(camera, dispObj->worldMatrix, sp128);
            GXLoadPosMtxImm(sp128, GX_PNMTX0);
            PSMTXScale(spF8, scale, scale, scale);
            PSMTXConcat(sp128, spF8, spF8);
            GXLoadNrmMtxImm(spF8, GX_PNMTX0);
            numChans++;
            GXSetChanCtrl(GX_COLOR0, GX_TRUE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT0, GX_DF_CLAMP, GX_AF_NONE);
            GXSetChanCtrl(GX_ALPHA0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_CLAMP, GX_AF_NONE);
            numTexGens += 2;
            GXSetTexCoordGen2(coord, GX_TG_MTX2X4, numStages + GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            if (numStages == 0) {
                GXSetTexCoordGen2(coord + 1, GX_TG_BUMP0, coord + GX_TG_TEXCOORD0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            } else {
                GXSetTexCoordGen2(coord + 1, GX_TG_BUMP0, coord + GX_TG_TEXCOORD0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            }
            GXSetTevOrder(stage, coord, map, GX_COLOR0A0);
            GXSetTevOrder(stage + 1, coord + 1, map, GX_COLOR_NULL);
            GXSetTevColor(GX_TEVREG0, shadowColor);
            if (numStages == 0) {
                GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_A0, GX_CC_RASC);
            } else {
                GXSetTevColorIn(stage, GX_CC_CPREV, GX_CC_TEXC, GX_CC_A0, GX_CC_RASC);
            }
            GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
            GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
            GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
            GXSetTevColorIn(stage + 1, GX_CC_ZERO, GX_CC_TEXC, GX_CC_A0, GX_CC_CPREV);
            GXSetTevColorOp(stage + 1, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            GXSetTevAlphaIn(stage + 1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
            GXSetTevAlphaOp(stage + 1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
            texIdx += 2;
            numStages += 2;
            break;
        }
        default:
            if (dispObj->userTevMode != NULL) {
                dispObj->userTevMode(mode, dispObj, camera, &numTexGens, &numStages);
            } else {
                OSReport("Warning: DisplayObject.c: User TevMode %d not handled.\n", mode);
            }
            break;
        }
        if (mode == 5) {
            break;
        }
        coord = texIdx;
        shift += 4;
        stage = numStages;
        map = texIdx;
        if (texIdx >= dispObj->numTextureChannels) {
            break;
        }
    }
    if (dispObj->lightingData != NULL && bumpState != 0) {
        GXSetTevOrder(stage, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
        GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_CPREV, GX_CC_RASC, GX_CC_ZERO);
        GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_APREV, GX_CA_RASA, GX_CA_ZERO);
        GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        numStages++;
        stage++;
    }
    if (state->flags & 0x80) {
        if (fn_800B9AB0(mode, dispObj, state, &stage, &coord, &map, &chan, camera) == 0) {
            numTexGens++;
            numStages++;
            if (lbl_803CC1F4 != NULL) {
                numTexGens++;
            }
        }
    } else if (state->_01 & 0x80) {
        if (fn_800B9EA8(mode, dispObj, state, &stage, &coord, &map, &chan, camera) == 0) {
            if (state->flags == 0) {
                numTexGens++;
                numStages++;
            } else {
                numTexGens += 2;
                numStages += 2;
            }
        }
    }
    if (dispObj->envTexObj != NULL && dispObj->lightingData != NULL) {
        colorArg = GX_CC_CPREV;
        alphaArg = GX_CA_APREV;
        src = GX_TG_NRM;
        if (dispObj->lightingData->compCount == 2) {
            src = GX_TG_BINRM;
        }
        chan = GX_COLOR_NULL;
        if (mode == 5) {
            colorArg = GX_CC_RASC;
            chan = GX_COLOR0A0;
            alphaArg = GX_CA_RASA;
        }
        if (dispObj->pad8 != 0) {
            kcolor.r = kcolor.g = kcolor.b = kcolor.a = dispObj->pad8;
            konst = GX_CC_KONST;
            GXSetTevKColor(GX_KCOLOR0, kcolor);
            GXSetTevKColorSel(stage, GX_TEV_KCSEL_K0);
        } else {
            konst = GX_CC_APREV;
            alphaArg = GX_CA_KONST;
        }
        PSMTXScale(sp68, 0.5f, -0.5f, 0.0f);
        PSMTXTrans(sp98, 0.5f, 0.5f, 1.0f);
        PSMTXConcat(camera, dispObj->worldMatrix, spC8);
        PSMTXInverse(spC8, spC8);
        PSMTXTranspose(spC8, spC8);
        GXLoadTexMtxImm(spC8, GX_TEXMTX0 + numStages * 3, GX_MTX3x4);
        PSMTXConcat(sp98, sp68, spC8);
        GXLoadTexMtxImm(spC8, GX_PTTEXMTX0 + numStages * 3, GX_MTX3x4);
        GXSetTexCoordGen2(coord, GX_TG_MTX3X4, src, GX_TEXMTX0 + numStages * 3, GX_TRUE, GX_PTTEXMTX0 + numStages * 3);
        GXLoadTexObj(dispObj->envTexObj, map);
        GXSetTevOrder(stage, coord, map, chan);
        GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_TEXC, konst, colorArg);
        GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, alphaArg);
        GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        numTexGens++;
        numStages++;
        stage++;
        coord++;
        map++;
    }
    if (dispObj->projTexObj != NULL && fn_800BEBA0() && (state->flags & fn_800BF068()->_4C)) {
        PSMTXConcat(fn_800BEB80(fn_800BEBA0() - 1), dispObj->worldMatrix, sp38);
        if (lbl_803CC20C != NULL) {
            lbl_803CC20C(sp38, &stage, &coord, &map, &numStages, &numTexGens);
        } else {
            GXSetTevOrder(stage, coord, map, GX_COLOR0A0);
            GXSetTevColorIn(stage, GX_CC_CPREV, GX_CC_ZERO, GX_CC_TEXC, GX_CC_ZERO);
            GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            GXSetTevAlphaIn(stage, GX_CA_APREV, GX_CA_APREV, GX_CA_ZERO, GX_CA_ZERO);
            GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            GXSetTexCoordGen2(coord, GX_TG_MTX3X4, GX_TG_POS, GX_TEXMTX0 + numStages * 3, GX_FALSE, GX_PTIDENTITY);
            fn_800BF008();
            GXLoadTexObj(dispObj->projTexObj, map);
            GXLoadTexMtxImm(sp38, GX_TEXMTX0 + numStages * 3, GX_MTX3x4);
            numTexGens++;
            numStages++;
            stage++;
            coord++;
            map++;
        }
    }
    if (state->flags & 0x10) {
        black.r = black.g = black.b = 0;
        GXSetFog(GX_FOG_NONE, 0.0f, 0.0f, 0.0f, 0.0f, black);
    } else {
        GXSetFog(lbl_80111700.type, lbl_80111700.startz, lbl_80111700.endz, lbl_80111700.nearz, lbl_80111700.farz, lbl_80111700.color);
    }
    if (lbl_803CC200 != NULL) {
        lbl_803CC200(dispObj, &stage, &coord, &map, &numStages, &numTexGens, camera);
    }
    GXSetNumTexGens(numTexGens);
    if (numStages != 0) {
        GXSetNumTevStages(numStages);
    }
    if (numChans != 0) {
        GXSetNumChans(numChans);
    }
}

// .text:0x800BBB2C size:0x430
// 96.91%: registers only; the target gives map the camera's r28, and the VCD head's first
// attr store reuses n's zero register.
void SetState(DisplayStateList* state, struct DODisplayObj* dispObj, MtxPtr camera) {
    Mtx m;
    GXVtxDescList vcd[GX_VA_MAX_ATTR + 1];
    DOTexHeader* tex;
    DOTexPalette* palette;
    GXTexWrapMode wrapS;
    GXTexWrapMode wrapT;
    GXTexFilter minFilter;
    GXTexFilter magFilter;
    f32 minLOD;
    f32 maxLOD;
    f32 lodBias;
    u8 mipmap;
    u32 setting;
    u32 mtxId;
    s32 n;
    s32 attr;
    s32 shift;
    u32 type;
    GXTexMapID map;

    switch (state->id) {
    case 1:
        map = (state->setting >> 13) & 7;
        palette = (DOTexPalette*)dispObj->textureData[(state->setting >> 13) & 7].texturePalette;
        tex = &palette->entries[palette->entries[state->setting & 0x1FFF].index];
        lbl_803CC210[map] = state->pad16;
        setting = state->setting;
        wrapS = (setting >> 16) & 0xF;
        switch (wrapS) {
        case 0:
            wrapS = GX_CLAMP;
            break;
        case 1:
            wrapS = GX_REPEAT;
            break;
        case 2:
            wrapS = GX_MIRROR;
            break;
        }
        wrapT = (setting >> 20) & 0xF;
        switch (wrapT) {
        case 0:
            wrapT = GX_CLAMP;
            break;
        case 1:
            wrapT = GX_REPEAT;
            break;
        case 2:
            wrapT = GX_MIRROR;
            break;
        }
        minLOD = tex->minLOD;
        maxLOD = tex->maxLOD;
        mipmap = tex->minLOD != tex->maxLOD;
        minFilter = tex->minFilter;
        magFilter = tex->magFilter;
        lodBias = tex->lodBias;
        if (tex->tlut != NULL) {
            GXInitTexObjCI(&lbl_803CB5FC[map], tex->image, tex->width, tex->height, tex->format, wrapS, wrapT, mipmap, map);
            GXInitTlutObj(&lbl_803CB49C[map], tex->tlut, tex->tlutFormat, tex->tlutEntries);
            GXLoadTlut(&lbl_803CB49C[map], map);
        } else {
            GXInitTexObj(&lbl_803CB5FC[map], tex->image, tex->width, tex->height, tex->format, wrapS, wrapT, mipmap);
        }
        GXInitTexObjLOD(&lbl_803CB5FC[map], minFilter, magFilter, minLOD, maxLOD, lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
        GXLoadTexObj(&lbl_803CB5FC[map], map);
        break;
    case 2:
        setting = state->setting;
        GXClearVtxDesc();
        n = 0;
        if (setting & 3) {
            vcd[n].mAttr = GX_VA_PNMTXIDX;
            vcd[n].mType = setting & 3;
            n++;
        }
        for (shift = 2, attr = GX_VA_POS; attr <= GX_VA_TEX7; attr++, shift += 2) {
            type = (setting >> shift) & 3;
            if (type != 0) {
                vcd[n].mAttr = attr;
                vcd[n].mType = type;
                n++;
            }
        }
        type = (setting >> 26) & 3;
        if (type != 0) {
            vcd[n].mAttr = GX_VA_NBT;
            vcd[n].mType = type;
            n++;
        }
        vcd[n].mAttr = GX_VA_NULL;
        GXSetVtxDescv(vcd);
        break;
    case 3:
        Custom_SetState(dispObj, (DOState*)state, camera);
        break;
    case 4:
        setting = state->setting;
        mtxId = (u16)setting * 3;
        PSMTXConcat(camera, lbl_803CC204[setting >> 16], m);
        GXLoadPosMtxImm(m, mtxId);
        if (dispObj->lightingData != NULL) {
            PSMTXConcat(camera, lbl_803CC208[state->setting >> 16], m);
            GXLoadNrmMtxImm(m, mtxId);
        }
        break;
    }
}

// .text:0x800BBF5C size:0x168
void GetColorFromQuant(void* color, u32 quantizeInfo, u8* r, u8* g, u8* b, u8* a) {
    switch ((quantizeInfo >> 4) & 0xF) {
    case GX_RGB565:
        *r = (*(u16*)color >> 8) & 0xF8;
        *g = (*(u16*)color >> 3) & 0xFC;
        *b = (*(u16*)color << 3) & 0xF8;
        *a = 0xFF;
        break;
    case GX_RGBA4:
        *r = (*(u16*)color >> 12) & 0xF;
        *g = (*(u16*)color >> 8) & 0xF;
        *b = (*(u16*)color >> 4) & 0xF;
        *a = *(u16*)color & 0xF;
        *r |= *r << 4;
        *g |= *g << 4;
        *b |= *b << 4;
        *a |= *a << 4;
        break;
    case GX_RGBA8:
        *r = *(u32*)color >> 24;
        *g = *(u32*)color >> 16;
        *b = *(u32*)color >> 8;
        *a = *(u32*)color;
        break;
    case GX_RGB8:
    case GX_RGBX8:
        *r = *(u32*)color >> 24;
        *g = *(u32*)color >> 16;
        *b = *(u32*)color >> 8;
        *a = 0xFF;
        break;
    case GX_RGBA6:
        *r = (*(u16*)color & 0xFC0000) >> 16;
        *g = (*(u16*)color & 0x3F000) >> 10;
        *b = (*(u16*)color & 0xFC0) >> 4;
        *a = (*(u16*)color & 0x3F) << 2;
        break;
    }
}

// .text:0x800BC0C4 size:0x724
// 99.08%: the target tests visibility with bne/b, the GXColor temporaries sit 4 bytes apart
// on the stack, and the parameters land in r30/r31/r25/r26.
void DOVARender(struct DODisplayObj *dispObj, MtxPtr camera, u8 numLights, va_list *list) {
    Mtx mv;
    Mtx tmp;
    GXColor color;
    GXColorSrc matSrc = GX_SRC_VTX;
    DisplayStateList* stateList;
    Light* light;
    u32 i;
    u32 lightMask;
    u32 lightId;
    f32 ambient;
    f32 diffuse;
    u32 stride;
    u8 compCount;

    if (dispObj != NULL) {
        if (!dispObj->visibility) {
            return;
        }
        if (lbl_803CC204 == NULL) {
            PSMTXConcat(camera, dispObj->worldMatrix, mv);
            GXLoadPosMtxImm(mv, GX_PNMTX0);
            GXSetCurrentMtx(GX_PNMTX0);
        }
        GXSetArray(GX_VA_POS, dispObj->positionData->positionArray, (u8)(dispObj->positionData->compCount * GetQuantizeSize(dispObj->positionData->quantizeInfo)));
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, dispObj->positionData->quantizeInfo >> 4, dispObj->positionData->quantizeInfo & 0xF);
        if (dispObj->colorData != NULL) {
            if (dispObj->colorData->numColors == 1) {
                matSrc = GX_SRC_REG;
                GetColorFromQuant(dispObj->colorData->colorArray, dispObj->colorData->quantizeInfo, &color.r, &color.g, &color.b, &color.a);
                GXSetChanMatColor(GX_COLOR0A0, color);
            } else {
                switch ((u8)(dispObj->colorData->quantizeInfo >> 4)) {
                case GX_RGB565:
                case GX_RGBA4:
                    stride = 2;
                    break;
                case GX_RGB8:
                case GX_RGBA6:
                    stride = 3;
                    break;
                case GX_RGBX8:
                case GX_RGBA8:
                    stride = 4;
                    break;
                default:
                    stride = 0;
                    break;
                }
                GXSetArray(GX_VA_CLR0, dispObj->colorData->colorArray, stride);
                GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, dispObj->colorData->compCount != 3, dispObj->colorData->quantizeInfo >> 4, 0);
            }
            GXSetNumChans(1);
        } else {
            color.r = 0xFF;
            color.g = 0xFF;
            color.b = 0xFF;
            color.a = 0xFF;
            GXSetChanMatColor(GX_COLOR0A0, color);
            GXSetNumChans(1);
            matSrc = GX_SRC_REG;
        }
        if (dispObj->textureData != NULL) {
            for (i = 0; i < dispObj->numTextureChannels; i++) {
                GXSetArray(GX_VA_TEX0 + i, dispObj->textureData[i].textureCoordArray, (u8)(dispObj->textureData[i].compCount * GetQuantizeSize(dispObj->textureData[i].quantizeInfo)));
                GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0 + i, GX_TEX_ST, dispObj->textureData[i].quantizeInfo >> 4, dispObj->textureData[i].quantizeInfo & 0xF);
                GXSetTexCoordGen2(i, GX_TG_MTX2X4, GX_TG_TEX0 + i, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            }
        }
        if (dispObj->lightingData != NULL) {
            if (dispObj->lightingData->normalArray != NULL) {
                compCount = dispObj->lightingData->compCount;
                if (compCount == 3 || compCount == 6) {
                    GXSetArray(GX_VA_NRM, dispObj->lightingData->normalArray, (u8)(compCount * GetQuantizeSize(dispObj->lightingData->quantizeInfo)));
                    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, dispObj->lightingData->quantizeInfo >> 4, dispObj->lightingData->quantizeInfo & 0xF);
                } else if (compCount == 2) {
                    GXSetArray(GX_VA_NBT, dispObj->lightingData->normalArray, (u8)(GetQuantizeSize(dispObj->lightingData->quantizeInfo) * 3));
                    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NBT, GX_NRM_NBT3, dispObj->lightingData->quantizeInfo >> 4, dispObj->lightingData->quantizeInfo & 0xF);
                } else {
                    OSReport("DOVARender: Invalid component count for normals %d\n", compCount);
                }
            } else {
                GXSetArray(GX_VA_NRM, lbl_80111750, (u8)(GetQuantizeSize(lbl_803CBB60) * 3));
                GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, lbl_803CBB60 >> 4, lbl_803CBB60 & 0xF);
            }
            if (lbl_803CC204 == NULL) {
                PSMTXInverse(mv, tmp);
                PSMTXTranspose(tmp, mv);
                GXLoadNrmMtxImm(mv, GX_PNMTX0);
            }
        }
        if (dispObj->lightingData != NULL && dispObj->colorData != NULL && numLights != 0) {
            GXColor amb;

            lightMask = 0;
            ambient = 0.01f * dispObj->lightingData->ambientPercentage;
            if (fn_800BD2B0(&amb) == 0) {
                amb.a = 0xFF;
                amb.r = amb.g = amb.b = 255.0f * ambient;
            }
            GXSetChanAmbColor(GX_COLOR0A0, amb);
            diffuse = 1.0f - ambient;
            for (i = 0; i < numLights; i++) {
                light = va_arg(*list, Light*);
                amb.r = light->color.r * diffuse;
                amb.g = light->color.g * diffuse;
                amb.b = light->color.b * diffuse;
                GXInitLightColor(&light->lt_obj, amb);
                GXInitLightPos(&light->lt_obj, light->worldPosition.x, light->worldPosition.y, light->worldPosition.z);
                GXInitLightDir(&light->lt_obj, light->worldDirection.x, light->worldDirection.y, light->worldDirection.z);
                lightId = 1 << i;
                GXLoadLightObjImm(&light->lt_obj, lightId);
                lightMask |= lightId;
            }
            GXSetChanCtrl(GX_COLOR0A0, GX_TRUE, GX_SRC_REG, matSrc, lightMask, GX_DF_CLAMP, GX_AF_SPOT);
        } else {
            GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, matSrc, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
        }
        stateList = dispObj->displayData->displayStateList;
        for (i = 0; i < dispObj->displayData->numStateEntries; i++) {
            SetState(stateList, dispObj, camera);
            if (stateList->primitiveList != NULL) {
                GXCallDisplayList(stateList->primitiveList, stateList->listSize);
            }
            stateList++;
        }
    }
}

// .text:0x800BC7E8 size:0x3C
void DOVARenderSkin(struct DODisplayObj *dispObj, MtxPtr camera, MtxPtr mtxArray, MtxPtr invTransposeMtxArray, u8 numLights, va_list *list) {
    lbl_803CC204 = (Mtx*)mtxArray;
    lbl_803CC208 = (Mtx*)invTransposeMtxArray;
    DOVARender(dispObj, camera, numLights, list);
    lbl_803CC204 = NULL;
    lbl_803CC208 = NULL;
}

// .text:0x800BC824 size:0x10
void fn_800BC824(struct DODisplayObj* dispObj, GXTexObj* texObj) {
    if (dispObj != NULL) {
        dispObj->projTexObj = texObj;
    }
}

// .text:0x800BC834 size:0x2C
void DOSetWorldMatrix(struct DODisplayObj *dispObj, MtxPtr m) {
    PSMTXCopy(m, dispObj->worldMatrix);
}

// .text:0x800BC860 size:0x258
void InitDisplayObjWithLayout(struct DODisplayObj* dispObj, DOLayout* layout) {
    u16 i;

    if (layout->positionData != NULL) {
        dispObj->positionData = _OSAllocFromHeap(0x20, sizeof(PositionData));
        *dispObj->positionData = *layout->positionData;
    } else {
        dispObj->positionData = NULL;
    }
    if (layout->colorData != NULL) {
        dispObj->colorData = _OSAllocFromHeap(0x20, sizeof(ColorData));
        *dispObj->colorData = *layout->colorData;
    } else {
        dispObj->colorData = NULL;
    }
    if (layout->textureData != NULL && layout->numTextureChannels != 0) {
        dispObj->textureData = _OSAllocFromHeap(0x20, layout->numTextureChannels * sizeof(TextureData));
        dispObj->numTextureChannels = layout->numTextureChannels;
        for (i = 0; i < layout->numTextureChannels; i++) {
            dispObj->textureData[i] = layout->textureData[i];
        }
    } else {
        dispObj->textureData = NULL;
        dispObj->numTextureChannels = 0;
    }
    if (layout->lightingData != NULL) {
        dispObj->lightingData = _OSAllocFromHeap(0x20, sizeof(LightingData));
        *dispObj->lightingData = *layout->lightingData;
    } else {
        dispObj->lightingData = NULL;
    }
    if (layout->displayData != NULL) {
        dispObj->displayData = _OSAllocFromHeap(0x20, sizeof(DisplayData));
        *dispObj->displayData = *layout->displayData;
    } else {
        dispObj->displayData = NULL;
    }
    dispObj->visibility = 1;
    PSMTXIdentity(dispObj->worldMatrix);
    dispObj->envTexObj = NULL;
    dispObj->projTexObj = NULL;
    dispObj->pad8 = layout->pad8;
    memcpy(&dispObj->xMax, layout->_20, 4);
    memcpy(&dispObj->xMin, layout->_1C, 4);
    memcpy(&dispObj->yMax, layout->_28, 4);
    memcpy(&dispObj->yMin, layout->_24, 4);
    memcpy(&dispObj->zMax, layout->_30, 4);
    memcpy(&dispObj->zMin, layout->_2C, 4);
}

// .text:0x800BCAB8 size:0x8C
void DOGet(struct DODisplayObj **dispObj, DODisplayDataPtr pal, u16 id) {
    DOLayout* layout;

    if (id >= pal->numDescriptors) {
        OSReport("Display object id %d is greater than number of objects %d", id, pal->numDescriptors);
        *dispObj = NULL;
        return;
    }
    layout = (DOLayout*)pal->descriptorArray[id].layout;
    *dispObj = _OSAllocFromHeap(0x20, sizeof(struct DODisplayObj));
    InitDisplayObjWithLayout(*dispObj, layout);
}

// .text:0x800BCB44 size:0x21C
void* LoadGeoPalette(DODisplayDataPtr pal) {
    void* skin = NULL;
    DOLayout* layout;
    u16 i;
    u16 j;

    if (pal->userDataSize != 0 && pal->userData != NULL) {
        pal->userData = (void*)((u32)pal->userData + (u32)pal);
    }
    pal->descriptorArray = (DODescriptorPtr)((u32)pal->descriptorArray + (u32)pal);
    for (i = 0; i < pal->numDescriptors; i++) {
        pal->descriptorArray[i].layout = (DODisplayLayout*)((u32)pal->descriptorArray[i].layout + (u32)pal);
        pal->descriptorArray[i].name = (char*)((u32)pal->descriptorArray[i].name + (u32)pal);
        layout = (DOLayout*)pal->descriptorArray[i].layout;
        if (layout->positionData != NULL) {
            layout->positionData = (PositionData*)((u32)layout->positionData + (u32)layout);
            if (layout->positionData->positionArray != NULL) {
                layout->positionData->positionArray = (char*)((u32)layout->positionData->positionArray + (u32)layout);
            }
            if (layout->positionData->compCount == 6) {
                skin = layout->positionData->positionArray;
            }
        }
        if (layout->colorData != NULL) {
            layout->colorData = (ColorData*)((u32)layout->colorData + (u32)layout);
            if (layout->colorData->colorArray != NULL) {
                layout->colorData->colorArray = (char*)((u32)layout->colorData->colorArray + (u32)layout);
            }
        }
        if (layout->textureData != NULL) {
            layout->textureData = (TextureData*)((u32)layout->textureData + (u32)layout);
            for (j = 0; j < layout->numTextureChannels; j++) {
                if (layout->textureData[j].textureCoordArray != NULL) {
                    layout->textureData[j].textureCoordArray = (char*)((u32)layout->textureData[j].textureCoordArray + (u32)layout);
                }
                if (layout->textureData[j].texturePaletteName != NULL) {
                    layout->textureData[j].texturePaletteName = (char*)((u32)layout->textureData[j].texturePaletteName + (u32)layout);
                }
            }
        }
        if (layout->lightingData != NULL) {
            layout->lightingData = (LightingData*)((u32)layout->lightingData + (u32)layout);
            if (layout->lightingData->normalArray != NULL) {
                layout->lightingData->normalArray = (char*)((u32)layout->lightingData->normalArray + (u32)layout);
            }
        }
        if (layout->displayData != NULL) {
            layout->displayData = (DisplayData*)((u32)layout->displayData + (u32)layout);
            if (layout->displayData->primitiveBank != NULL) {
                layout->displayData->primitiveBank = (char*)((u32)layout->displayData->primitiveBank + (u32)layout);
            }
            if (layout->displayData->displayStateList != NULL) {
                layout->displayData->displayStateList = (DisplayStateList*)((u32)layout->displayData->displayStateList + (u32)layout);
            }
            for (j = 0; j < layout->displayData->numStateEntries; j++) {
                if (layout->displayData->displayStateList[j].primitiveList != NULL) {
                    layout->displayData->displayStateList[j].primitiveList = (char*)((u32)layout->displayData->displayStateList[j].primitiveList + (u32)layout);
                }
            }
        }
        if (layout->_18 != NULL) {
            layout->_18 = (void*)((u32)layout->_18 + (u32)layout);
        }
    }
    return skin;
}

// .text:0x800BCD60 size:0x5C
void convertGeometryAndSknHeader(DODisplayDataPtr pal, void* skn) {
    void* hdr;

    hdr = LoadGeoPalette(pal);
    if (skn != NULL) {
        SKNLoadFile(skn, hdr);
    }
    // this game keeps the skinning header in the palette's first word
    pal->versionNumber = (u32)hdr;
}

// .text:0x800BCDBC size:0x7C
void fn_800BCDBC(DODisplayDataPtr pal) {
    s32 i;

    for (i = pal->numDescriptors - 1; i >= 0; i--) {
        if (pal->descriptorArray[i].layout->textureData != NULL) {
            fn_800ACFB0(pal->descriptorArray[i].layout->textureData);
        }
    }
    fn_800ACFB0(pal->descriptorArray[0].layout);
}

// .text:0x800BCE38 size:0xC0
void fn_800BCE38(DODisplayDataPtr pal) {
    struct DODisplayObj* objs;
    u32 i;

    pal->userData = (void*)((u32)pal + (u32)pal->userData);
    pal->descriptorArray = (DODescriptorPtr)((u32)pal + (u32)pal->descriptorArray);
    objs = _OSAllocFromHeap(0x20, pal->numDescriptors * sizeof(struct DODisplayObj));
    for (i = 0; i < pal->numDescriptors; i++) {
        fn_800BCEF8((DOLayout*)((u32)pal + (u32)pal->descriptorArray[i].layout), &objs[i]);
        pal->descriptorArray[i].layout = (DODisplayLayout*)&objs[i];
        pal->descriptorArray[i].name = (char*)((u32)pal + (u32)pal->descriptorArray[i].name);
    }
}

// .text:0x800BCEF8 size:0x298
void* fn_800BCEF8(DOLayout* layout, struct DODisplayObj* dispObj) {
    void* skin = NULL;
    s32 i;

    if (layout->positionData != NULL) {
        dispObj->positionData = (PositionData*)((u32)layout + (u32)layout->positionData);
        dispObj->positionData->positionArray = (char*)((u32)layout + (u32)dispObj->positionData->positionArray);
        if (dispObj->positionData->compCount == 6) {
            skin = dispObj->positionData->positionArray;
        }
    } else {
        dispObj->positionData = NULL;
    }
    if (layout->colorData != NULL) {
        dispObj->colorData = (ColorData*)((u32)layout + (u32)layout->colorData);
        dispObj->colorData->colorArray = (char*)((u32)layout + (u32)dispObj->colorData->colorArray);
    } else {
        dispObj->colorData = NULL;
    }
    if (layout->textureData != NULL && layout->numTextureChannels != 0) {
        dispObj->textureData = _OSAllocFromHeap(0x20, layout->numTextureChannels * sizeof(TextureData));
        dispObj->numTextureChannels = layout->numTextureChannels;
        for (i = 0; i < layout->numTextureChannels; i++) {
            dispObj->textureData[i] = *(TextureData*)((u32)layout + (u32)&layout->textureData[i]);
            dispObj->textureData[i].textureCoordArray = (char*)((u32)layout + (u32)dispObj->textureData[i].textureCoordArray);
        }
    } else {
        dispObj->textureData = NULL;
        dispObj->numTextureChannels = 0;
    }
    if (layout->lightingData != NULL) {
        dispObj->lightingData = (LightingData*)((u32)layout + (u32)layout->lightingData);
        dispObj->lightingData->normalArray = (char*)((u32)layout + (u32)dispObj->lightingData->normalArray);
    } else {
        dispObj->lightingData = NULL;
    }
    if (layout->displayData != NULL) {
        dispObj->displayData = (DisplayData*)((u32)layout + (u32)layout->displayData);
        dispObj->displayData->primitiveBank = (char*)((u32)layout + (u32)dispObj->displayData->primitiveBank);
        dispObj->displayData->displayStateList = (DisplayStateList*)((u32)layout + (u32)dispObj->displayData->displayStateList);
        for (i = 0; i < dispObj->displayData->numStateEntries; i++) {
            if (dispObj->displayData->displayStateList[i].primitiveList != NULL) {
                dispObj->displayData->displayStateList[i].primitiveList = (char*)((u32)layout + (u32)dispObj->displayData->displayStateList[i].primitiveList);
            }
        }
    } else {
        dispObj->displayData = NULL;
    }
    dispObj->pad8 = layout->pad8;
    dispObj->visibility = 1;
    dispObj->overrideTevMode = 0;
    dispObj->userTevMode = DODefaultUserTevMode;
    dispObj->envTexObj = NULL;
    dispObj->projTexObj = NULL;
    memcpy(&dispObj->xMax, layout->_20, 4);
    memcpy(&dispObj->xMin, layout->_1C, 4);
    memcpy(&dispObj->yMax, layout->_28, 4);
    memcpy(&dispObj->yMin, layout->_24, 4);
    memcpy(&dispObj->zMax, layout->_30, 4);
    memcpy(&dispObj->zMin, layout->_2C, 4);
    return skin;
}

// .text:0x800BD190 size:0x58
void fn_800BD190(DODisplayDataPtr pal, TEXPalettePtr tex) {
    u32 i;
    s32 j;

    for (i = 0; i < pal->numDescriptors; i++) {
        for (j = 0; j < pal->descriptorArray[i].layout->numTextureChannels; j++) {
            pal->descriptorArray[i].layout->textureData[j].texturePalette = tex;
        }
    }
}

// .text:0x800BD1E8 size:0x8
void fn_800BD1E8(DOShadowCallback arg0) {
    lbl_803CC20C = arg0;
}

// .text:0x800BD1F0 size:0x8
asm void __MTGQR5(register u32 val) {
    nofralloc
    mtspr GQR5, val
    blr
}

// .text:0x800BD1F8 size:0x8
asm void __MTGQR6(register u32 val) {
    nofralloc
    mtspr GQR6, val
    blr
}

// .text:0x800BD200 size:0x8
asm void __MTGQR7(register u32 val) {
    nofralloc
    mtspr GQR7, val
    blr
}

// .text:0x800BD208 size:0x38
void GQRSetup7(u32 loadScale, u32 loadType, u32 storeScale, u32 storeType) {
    __MTGQR7(((loadScale << 8) + loadType) << 16 | ((storeScale << 8) + storeType));
}

// .text:0x800BD240 size:0x38
void GQRSetup6(u32 loadScale, u32 loadType, u32 storeScale, u32 storeType) {
    __MTGQR6(((loadScale << 8) + loadType) << 16 | ((storeScale << 8) + storeType));
}

// .text:0x800BD278 size:0x38
void GQRSetup5(u32 loadScale, u32 loadType, u32 storeScale, u32 storeType) {
    __MTGQR5(((loadScale << 8) + loadType) << 16 | ((storeScale << 8) + storeType));
}

// .text:0x800BD2B0 size:0x1C
u8 fn_800BD2B0(GXColor* color) {
    if (lbl_803CC220) {
        *color = lbl_803CC224;
    }
    return lbl_803CC220;
}

// .text:0x800BD2CC size:0x10
void fn_800BD2CC(u8 enable, GXColor color) {
    lbl_803CC220 = enable;
    lbl_803CC224 = color;
}

// .text:0x800BD2DC size:0x24
void fn_800BD2DC(void) {
    lbl_803CC220 = 0;
    lbl_803CC224.r = 0;
    lbl_803CC224.b = 0;
    lbl_803CC224.g = 0;
    lbl_803CC224.a = 255;
}
