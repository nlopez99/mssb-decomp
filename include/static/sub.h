#ifndef __STATIC_SUB_H_
#define __STATIC_SUB_H_

#include "mssbTypes.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"

typedef struct TextureDesc {
    /* 0x00 */ void* image;
    /* 0x04 */ void* tlut;
    /* 0x08 */ u16 height;
    /* 0x0A */ u16 width;
    /* 0x0C */ u8 wrapS;
    /* 0x0D */ u8 wrapT;
    /* 0x0E */ u8 minFilter;
    /* 0x0F */ u8 magFilter;
    /* 0x10 */ f32 lodBias;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 minLOD;
    /* 0x16 */ u8 maxLOD;
    /* 0x17 */ u8 format;
    /* 0x18 */ u16 tlutCount;
    /* 0x1A */ u8 tlutFormat;
    /* 0x1B */ u8 _1B[0x20 - 0x1B];
} TextureDesc; // size: 0x20

// A ring of the last positions pushed, read back from the newest or the oldest
typedef struct VecRing {
    /* 0x00 */ Vec* buf;
    /* 0x04 */ int capacity;
    /* 0x08 */ int count;
    /* 0x0C */ int head;
    /* 0x10 */ int tail;
    /* 0x14 */ int cur;
    /* 0x18 */ int step; // 0 until the first push
} VecRing; // size: 0x1C

void fn_80023CF4(s32 progressive);
s32 fn_80023D3C(void);
void fn_80023D44(s32 progressive);
BOOL fn_80023D4C(VecRing* ring, Vec* out);
BOOL fn_80023D98(VecRing* ring, Vec* out);
BOOL fn_80023DFC(VecRing* ring, Vec* out);
void fn_80023E48(VecRing* ring, Vec* v);
void fn_80023EEC(VecRing* ring, Vec* buf, int capacity);
int fn_80023F0C(TextureDesc* src, TextureDesc* dst, int srcX, int srcY, int w, int h, int dstX, int dstY);
void gOz_GXSetTexture(GXTevMode mode, s32 frac, s32 useNormal);

void fn_80024390(camera_803c639c_s* camera, f32* p, s32 type);
void SetDisplayStateTexture(TextureDesc* tex, GXTexMapID map, u32 tlutName);
void fn_800245EC(camera_803c639c_s* camera, Mtx view, Vec* points, f32* out, s32 count, s32 arg5);
void fn_800246D4(int (*compare)(const void*, const void*), void* src, void* dst, int size, int count);
s32 fn_800247E4(s32 x, s32 y, s32 width, s32 bytes);
int challengeStarRelatedInd(int character, int mission);
int multBottomBits_asFloat(int color, int factor);
int byteWiseMultiply(int value, int factors);
int LERPToNewRange_Float(int value, int inMin, int inMax, int outMin, int outMax);
f32 LinearInterpolateToNewRange(f32 value, f32 prevMin, f32 prevMax, f32 nextMin, f32 nextMax);

#endif // !__STATIC_SUB_H_
