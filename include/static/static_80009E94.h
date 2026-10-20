#ifndef __STATIC_STATIC_80009E94_H_
#define __STATIC_STATIC_80009E94_H_

#include "mssbTypes.h"

typedef struct InterpPoint {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ u8 _08[0x8];
} InterpPoint; // size: 0x10

typedef struct BezierVec2s {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
} BezierVec2s;

typedef struct BezierKey {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05[0x14 - 0x5];
    /* 0x14 */ s16 x;
    /* 0x16 */ s16 y;
    /* 0x18 */ u8 _18[0x34 - 0x18];
    /* 0x34 */ s16 handles[4];
} BezierKey;

void interpolatePointsUnknown(s32 i, InterpPoint* pts, u32 first, u32 last);
void BezierInterpolate(InterpPoint* out, InterpPoint* p0, InterpPoint* p1, InterpPoint* p2, InterpPoint* p3, f32 t);
void* fn_8000A094(void* callback);

#endif // !__STATIC_STATIC_80009E94_H_
