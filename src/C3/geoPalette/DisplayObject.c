#include "C3/DisplayObject.h"
extern void OSReport(const char* msg, ...);
#include "string.h"
#include "stl/math.h"

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800ACFB0(void* data);
extern void SKNLoadFile(void* skn, void* hdr);

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

// .sbss, declared from the highest address down
GXColor lbl_803CC224;
u8 lbl_803CC220;
u32 lbl_803CC21C;
f32 lbl_803CC218;
u8 lbl_803CC210[8];
s32 lbl_803CC20C;
MtxPtr lbl_803CC208;
MtxPtr lbl_803CC204;
s32 lbl_803CC200;
f32 lbl_803CC1FC;
f32 lbl_803CC1F8;
DOEnvCallback lbl_803CC1F4;
Light* lbl_803CC1F0;

// .text:0x800B993C size:0xC
void fn_800B993C(void) {
    lbl_803CC200 = 0;
}

// .text:0x800B9948 size:0x8
void fn_800B9948(s32 arg0) {
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
s32 fn_800B9AB0(u32 mode, struct DODisplayObj* dispObj, u8* setting, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, GXChannelID* chan, MtxPtr camera) {
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
    if (dispObj == NULL || dispObj->lightingData == NULL || setting == NULL) {
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
    if (setting[1] != 0) {
        kcolor.r = kcolor.g = kcolor.b = kcolor.a = setting[1];
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
s32 fn_800B9EA8(u32 mode, struct DODisplayObj* dispObj, u8* setting, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, GXChannelID* chan, MtxPtr camera) {
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
    if (dispObj == NULL || dispObj->lightingData == NULL || lbl_803CC1F0 == NULL || setting == NULL) {
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
            reflect = (setting[1] & 0x7F) / 100.0f;
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
    if (*(u16*)(setting + 2) == 0) {
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
void DODefaultUserTevMode(s32 mode, struct DODisplayObj* dispObj, DOUserTevData* data, u8* numTexGens, u8* numStages) {
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
        x = data->_20;
        y = data->_24;
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
void Custom_SetState(void) {}

// .text:0x800BBB2C size:0x430
void SetState(void) {}

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
void DOVARender(struct DODisplayObj *dispObj, MtxPtr camera, u8 numLights, va_list *list) {}

// .text:0x800BC7E8 size:0x3C
void DOVARenderSkin(struct DODisplayObj *dispObj, MtxPtr camera, MtxPtr mtxArray, MtxPtr invTransposeMtxArray, u8 numLights, va_list *list) {
    lbl_803CC204 = mtxArray;
    lbl_803CC208 = invTransposeMtxArray;
    DOVARender(dispObj, camera, numLights, list);
    lbl_803CC204 = NULL;
    lbl_803CC208 = NULL;
}

// .text:0x800BC824 size:0x10
void fn_800BC824(struct DODisplayObj* dispObj, void* arg1) {
    if (dispObj != NULL) {
        dispObj->shaderData = arg1;
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
    dispObj->shaderFunc = NULL;
    dispObj->shaderData = NULL;
    dispObj->pad8 = layout->pad8;
    memcpy(dispObj->_58, layout->_20, 4);
    memcpy(dispObj->_54, layout->_1C, 4);
    memcpy(dispObj->_60, layout->_28, 4);
    memcpy(dispObj->_5C, layout->_24, 4);
    memcpy(dispObj->_68, layout->_30, 4);
    memcpy(dispObj->_64, layout->_2C, 4);
}

// .text:0x800BCAB8 size:0x8C
void DOGet(struct DODisplayObj **dispObj, DODisplayDataPtr pal, u16 id, char *name) {
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

    pal->userData = (void*)((u32)pal->userData + (u32)pal);
    pal->descriptorArray = (DODescriptorPtr)((u32)pal->descriptorArray + (u32)pal);
    objs = _OSAllocFromHeap(0x20, pal->numDescriptors * sizeof(struct DODisplayObj));
    for (i = 0; i < pal->numDescriptors; i++) {
        fn_800BCEF8((DOLayout*)((u32)pal->descriptorArray[i].layout + (u32)pal), objs);
        pal->descriptorArray[i].layout = (DODisplayLayout*)objs++;
        pal->descriptorArray[i].name = (char*)((u32)pal->descriptorArray[i].name + (u32)pal);
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
    dispObj->shaderFunc = NULL;
    dispObj->shaderData = NULL;
    memcpy(dispObj->_58, layout->_20, 4);
    memcpy(dispObj->_54, layout->_1C, 4);
    memcpy(dispObj->_60, layout->_28, 4);
    memcpy(dispObj->_5C, layout->_24, 4);
    memcpy(dispObj->_68, layout->_30, 4);
    memcpy(dispObj->_64, layout->_2C, 4);
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
void fn_800BD1E8(s32 arg0) {
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
