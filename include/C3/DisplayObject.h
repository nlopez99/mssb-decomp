#ifndef _C3_DISPLAYOBJECT_H_
#define _C3_DISPLAYOBJECT_H_

#include "C3/charPipeline.h"

typedef void (*DOEnvCallback)(GXTevStageID stage, s32 arg1, s32 arg2, GXTexCoordID coord, GXTexMapID map);

// An entry of this game's texture palettes
typedef struct DOTexHeader {
    /* 0x00 */ void* image;
    /* 0x04 */ void* tlut;
    /* 0x08 */ u16 height;
    /* 0x0A */ u16 width;
    /* 0x0C */ u8 _0C[2];
    /* 0x0E */ u8 minFilter;
    /* 0x0F */ u8 magFilter;
    /* 0x10 */ f32 lodBias;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 minLOD;
    /* 0x16 */ u8 maxLOD;
    /* 0x17 */ u8 format;
    /* 0x18 */ u16 tlutEntries;
    /* 0x1A */ u8 tlutFormat;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u16 index;
    /* 0x1E */ u8 _1E[2];
} DOTexHeader; // size: 0x20

typedef struct DOTexPalette {
    /* 0x00 */ u32 _00;
    /* 0x04 */ DOTexHeader entries[1];
} DOTexPalette;

typedef struct DOState {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01;
    /* 0x02 */ u16 flags;
    /* 0x04 */ u32 tevModes;
    /* 0x08 */ u8 _08[4];
    /* 0x0C */ u32 scale;
} DOState;

typedef void (*DOTevCallback)(struct DODisplayObj* dispObj, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* numStages, u8* numTexGens, MtxPtr camera);
typedef void (*DOShadowCallback)(MtxPtr m, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* numStages, u8* numTexGens);

// The layout in this game's geometry palettes: the SDK's DODisplayLayout with more fields after it.
typedef struct DOLayout {
    /* 0x00 */ PositionData *positionData;
    /* 0x04 */ ColorData *colorData;
    /* 0x08 */ TextureData *textureData;
    /* 0x0C */ LightingData *lightingData;
    /* 0x10 */ DisplayData *displayData;
    /* 0x14 */ u8 numTextureChannels;
    /* 0x15 */ u8 pad8;
    /* 0x16 */ u8 _16[2];
    /* 0x18 */ void *_18;
    /* 0x1C */ u8 _1C[4];
    /* 0x20 */ u8 _20[4];
    /* 0x24 */ u8 _24[4];
    /* 0x28 */ u8 _28[4];
    /* 0x2C */ u8 _2C[4];
    /* 0x30 */ u8 _30[4];
} DOLayout; // size: 0x34

void fn_800B993C(void);
void fn_800B9948(DOTevCallback arg0);
void fn_800B9950(u32 flags, f32 arg1, f32 arg2);
void fn_800B996C(DOEnvCallback arg0);
void SetFogNone(void);
void SetFog(GXFogType type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color);
void SetFogNoneAgain(void);
void fn_800B9A9C(u32 arg0, f32 arg1);
void fn_800B9AA8(Light* light);
s32 fn_800B9AB0(u32 mode, struct DODisplayObj* dispObj, DOState* state, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, GXChannelID* chan, MtxPtr camera);
s32 fn_800B9EA8(u32 mode, struct DODisplayObj* dispObj, DOState* state, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, GXChannelID* chan, MtxPtr camera);
void DODefaultUserTevMode(s32 mode, struct DODisplayObj* dispObj, MtxPtr camera, u8* numTexGens, u8* numStages);
void Custom_SetState(struct DODisplayObj* dispObj, DOState* state, MtxPtr camera);
void SetState(DisplayStateList* state, struct DODisplayObj* dispObj, MtxPtr camera);
void GetColorFromQuant(void* color, u32 quantizeInfo, u8* r, u8* g, u8* b, u8* a);
void DOVARender(struct DODisplayObj *dispObj, MtxPtr camera, u8 numLights, va_list *list);
void DOVARenderSkin(struct DODisplayObj *dispObj, MtxPtr camera, MtxPtr mtxArray, MtxPtr invTransposeMtxArray, u8 numLights, va_list *list);
void fn_800BC824(struct DODisplayObj* dispObj, GXTexObj* texObj);
void DOSetWorldMatrix(struct DODisplayObj *dispObj, MtxPtr m);
void InitDisplayObjWithLayout(struct DODisplayObj* dispObj, DOLayout* layout);
void DOGet(struct DODisplayObj **dispObj, DODisplayDataPtr pal, u16 id, char *name);
void* LoadGeoPalette(DODisplayDataPtr pal);
void convertGeometryAndSknHeader(DODisplayDataPtr pal, void* skn);
void fn_800BCDBC(DODisplayDataPtr pal);
void fn_800BCE38(DODisplayDataPtr pal);
void* fn_800BCEF8(DOLayout* layout, struct DODisplayObj* dispObj);
void fn_800BD190(DODisplayDataPtr pal, TEXPalettePtr tex);
void fn_800BD1E8(DOShadowCallback arg0);
void __MTGQR5(register u32 val);
void __MTGQR6(register u32 val);
void __MTGQR7(register u32 val);
void GQRSetup7(u32 loadScale, u32 loadType, u32 storeScale, u32 storeType);
void GQRSetup6(u32 loadScale, u32 loadType, u32 storeScale, u32 storeType);
void GQRSetup5(u32 loadScale, u32 loadType, u32 storeScale, u32 storeType);
u8 fn_800BD2B0(GXColor* color);
void fn_800BD2CC(u8 enable, GXColor color);
void fn_800BD2DC(void);

#endif // _C3_DISPLAYOBJECT_H_
