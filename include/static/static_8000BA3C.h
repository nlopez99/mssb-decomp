#ifndef __STATIC_STATIC_8000BA3C_H_
#define __STATIC_STATIC_8000BA3C_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

typedef struct SpriteDesc {
    /* 0x00 */ u8 _00_b7 : 4;
    /* 0x00 */ u8 type : 4;
    /* 0x01 */ u8 flipX : 1;
    /* 0x01 */ u8 flipY : 1;
    /* 0x01 */ u8 _b5 : 1;
    /* 0x01 */ u8 _b4 : 1;
    /* 0x01 */ u8 _b3 : 4;
    /* 0x02 */ u16 index;
} SpriteDesc;

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
    /* 0x00 */ u8 _00[0x18];
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

typedef struct SpriteVerts {
    /* 0x00 */ s32 offsets[8];
    /* 0x20 */ u32 colors[4];
} SpriteVerts;

void fn_8000BA3C(void);
void fn_8000C194(void);
void fn_8000CC4C(void);
u32 fn_8000CEF0(AnimFile* file, s32 idx, u32 frame, s32 skip, u32* dst);
void fn_8000D164(void);
void fn_8000D838(void);
void fn_8000D8A4(void);
void fn_8000DC9C(SpriteShape* shape, Mtx mtx, ShapeStyle* style);
void fn_8000E030(SpriteShape* shape, Mtx mtx, ShapeStyle* style);
void fn_8000E2D4(void);
void fn_8000E764(f32 angle, f32* out);
void fn_8000E7BC(SpriteDesc* spr, Mtx mtx, SpriteVerts* verts, s32 arg3);
void SetSpriteRect(SpriteRect* spr, TexFile* tex, Mtx mtx, SpriteVerts* verts, s32 arg4);
void fn_8000EC0C(SpriteDesc* spr, TexFile* tex, Mtx mtx, SpriteVerts* verts, s32 arg4);
void AddVec2iToQuad(f32* quad, Mtx mtx, s32* offset);

#endif // !__STATIC_STATIC_8000BA3C_H_
