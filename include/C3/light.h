#ifndef _DOLPHIN_CP_LIGHT_H_
#define _DOLPHIN_CP_LIGHT_H_

#include <dolphin/gx.h>
#include <dolphin/mtx.h>

enum PARENT_TYPE {
    PARENT_BONE = 0,
    PARENT_DISP_OBJ = 1,
    PARENT_MTX = 2,
};

typedef struct Light {
    /* 0x00 */ GXLightObj lt_obj;
    /* 0x40 */ Vec position;
    /* 0x4C */ Vec worldPosition;
    /* 0x58 */ Vec direction;
    /* 0x64 */ Vec worldDirection;
    /* 0x70 */ GXColor color;
    /* 0x74 */ Control control;
    /* 0xB8 */ MtxPtr parent;
    /* 0xBC */ struct ANIMPipe *animPipe;
} Light; // size: 0xC0

// light.c
void LITXForm(Light *light, Mtx view);
void LITInitColor(Light *light, GXColor color);
void LITInitDir(Light *light, f32 nx, f32 ny, f32 nz);
void LITInitPos(Light *light, f32 x, f32 y, f32 z);
void LITInitAttn(Light *light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
void LITAlloc(Light **light);

#endif // _DOLPHIN_CP_LIGHT_H_
