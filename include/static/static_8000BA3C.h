#ifndef __STATIC_STATIC_8000BA3C_H_
#define __STATIC_STATIC_8000BA3C_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "Dolphin/GX/GXTypes.h"

typedef union SpriteCorner {
    struct {
        s16 x;
        s16 y;
    };
    u32 xy;
} SpriteCorner;

typedef struct SpriteDesc {
    /* 0x00 */ u8 _00_b7 : 4;
    /* 0x00 */ u8 type : 4;
    /* 0x01 */ u8 flipX : 1;
    /* 0x01 */ u8 flipY : 1;
    /* 0x01 */ u8 _b5 : 1;
    /* 0x01 */ u8 _b4 : 1;
    /* 0x01 */ u8 _b3 : 1;
    /* 0x01 */ u8 _b2 : 1;
    /* 0x01 */ u8 _b1 : 1;
    /* 0x01 */ u8 _b0 : 1;
    /* 0x02 */ u16 index;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ union {
        u32 color;
        GXColor rgba;
    };
    /* 0x0C */ u16 frame;
    /* 0x0E */ s16 rot;
    /* 0x10 */ s16 scaleX;
    /* 0x12 */ s16 scaleY;
    /* 0x14 */ s16 _14;
    /* 0x16 */ s16 _16;
    /* 0x18 */ union {
        SpriteCorner corners[4];
        struct {
            /* 0x18 */ u16 _18;
            /* 0x1A */ u16 _1A;
            /* 0x1C */ u32 _1C;
            /* 0x20 */ u32 _20;
            /* 0x24 */ u8 _24[2];
            /* 0x26 */ u8 _26;
            /* 0x27 */ u8 _27;
        } shape;
    };
} SpriteDesc; // size: 0x28

typedef struct AnimFrame {
    /* 0x0 */ u16 count;
    /* 0x2 */ u16 size;
} AnimFrame;

typedef struct AnimTrack {
    /* 0x0 */ u32 count;
    /* 0x4 */ u32 _04;
    /* 0x8 */ AnimFrame* frames[1];
} AnimTrack;

typedef struct AnimTrackList {
    /* 0x0 */ u32 count;
    /* 0x4 */ u32 _04;
    /* 0x8 */ AnimTrack* tracks[1];
} AnimTrackList;

typedef struct AnimFile {
    /* 0x00 */ u8 _00[0x5];
    /* 0x05 */ u8 _05;
    /* 0x06 */ u16 _06;
    /* 0x08 */ AnimTrackList* tracks;
    /* 0x0C */ void* _0C;
} AnimFile;

typedef struct TexEntry {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u8 _02[0x20 - 0x2];
} TexEntry; // size: 0x20

typedef struct TexFile {
    /* 0x00 */ u8 _00[0x20];
    /* 0x20 */ TexEntry entries[1];
} TexFile;

typedef struct TexImage {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 height;
    /* 0x0A */ u16 width;
} TexImage;

typedef struct SpriteRect {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 index;
    /* 0x08 */ u8 flipX : 1;
    /* 0x08 */ u8 flipY : 1;
    /* 0x08 */ u8 _b5 : 1;
    /* 0x08 */ u8 _b4 : 5;
} SpriteRect;

typedef struct SpriteShape {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ s16 _14;
    /* 0x16 */ s16 _16;
    /* 0x18 */ s16 _18;
    /* 0x1A */ s16 _1A;
    /* 0x1C */ u8 _1C[0x25 - 0x1C];
    /* 0x25 */ u8 _25_b7 : 1;
    /* 0x25 */ u8 _25_b0 : 7;
    /* 0x26 */ u8 _26[0x29 - 0x26];
    /* 0x29 */ u8 _29_b7 : 1;
    /* 0x29 */ u8 _29_b0 : 7;
} SpriteShape;

typedef struct ShapeStyle {
    /* 0x00 */ u8 _00[0x20];
    /* 0x20 */ u32 _20;
    /* 0x24 */ u32 _24;
    /* 0x28 */ u8 _28[0x30 - 0x28];
    /* 0x30 */ f32 _30;
    /* 0x34 */ u16 _34;
    /* 0x36 */ u8 _36;
} ShapeStyle;

typedef union SpriteColor {
    u32 word;
    GXColor rgba;
} SpriteColor;

typedef struct SpriteKey {
    /* 0x00 */ u16 hdr;
    /* 0x02 */ u16 frame;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 blend;
    /* 0x06 */ u16 index;
    /* 0x08 */ u8 _08_b7 : 3;
    /* 0x08 */ u8 _08_b4 : 1;
    /* 0x08 */ u8 _08_b3 : 1;
    /* 0x08 */ u8 _08_b2 : 1;
    /* 0x08 */ u8 _08_b1 : 2;
    /* 0x09 */ u8 _09[0xC - 0x9];
    /* 0x0C */ s16 scaleX;
    /* 0x0E */ s16 scaleY;
    /* 0x10 */ s16 _10;
    /* 0x12 */ s16 _12;
    /* 0x14 */ s16 x;
    /* 0x16 */ s16 y;
    /* 0x18 */ s16 z;
    /* 0x1A */ u8 _1A[0x1C - 0x1A];
    /* 0x1C */ union {
        u8 colors[4][4];
        struct {
            /* 0x1C */ u16 _1C;
            /* 0x1E */ u16 _1E;
            /* 0x20 */ GXColor _20;
            /* 0x24 */ GXColor _24;
            /* 0x28 */ u8 _28;
            /* 0x29 */ u8 _29;
            /* 0x2A */ u8 _2A;
            /* 0x2B */ u8 _2B;
        } shape;
    };
    /* 0x2C */ s16 rot[3];
    /* 0x32 */ u8 _32[0x40 - 0x32];
    /* 0x40 */ s16 offsets[8];
} SpriteKey; // size: 0x50

typedef struct SpriteNest {
    /* 0x0 */ s16 index;
    /* 0x2 */ s16 layer;
} SpriteNest;

typedef struct SpritePalette {
    /* 0x0 */ u32 count;
    /* 0x4 */ SpriteColor colors[1][4];
} SpritePalette;

typedef struct SpriteVerts {
    /* 0x00 */ s32 offsets[8];
    /* 0x20 */ u32 colors[4];
    /* 0x30 */ f32 _30;
    /* 0x34 */ u16 _34;
    /* 0x36 */ u8 _36;
} SpriteVerts;

s32 fn_8000BA3C(u32* time, AnimFile* file, s32 idx, Mtx mtx, s32 flags, u32 color, u16** outKey, SpriteNest* nest);
void fn_8000C194(void);
void fn_8000CC4C(AnimFile* file, AnimFrame* f, u8* src, u32 offset, u32 size);
u32 fn_8000CEF0(AnimFile* file, s32 idx, u32 frame, s32 skip, u32* dst);
s32 fn_8000D164(u32* time, AnimFile* file, s32 idx, Mtx mtx, s32 flags, u32 color, u16** outKey, TexFile* tex);
void fn_8000D838(void);
void fn_8000D8A4(SpriteShape* shape, Mtx mtx, ShapeStyle* style);
void fn_8000DC9C(SpriteShape* shape, Mtx mtx, ShapeStyle* style);
void fn_8000E030(SpriteShape* shape, Mtx mtx, ShapeStyle* style);
void fn_8000E2D4(SpriteShape* shape, Mtx mtx, ShapeStyle* style);
void fn_8000E764(f32 angle, f32* out);
void fn_8000E7BC(SpriteDesc* spr, Mtx mtx, SpriteVerts* verts, s32 arg3);
void SetSpriteRect(SpriteRect* spr, TexFile* tex, Mtx mtx, SpriteVerts* verts, s32 arg4);
void fn_8000EC0C(SpriteDesc* spr, TexFile* tex, Mtx mtx, SpriteVerts* verts, s32 arg4);
void AddVec2iToQuad(f32* quad, Mtx mtx, s32* offset);

#endif // !__STATIC_STATIC_8000BA3C_H_
