#include "static/static_8000BA3C.h"
#include "static/static_8000A0AC.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"
#include "math.h"
#include "string.h"

typedef struct QuadPoint {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
    /* 0xC */ f32 w;
} QuadPoint;

typedef struct SpriteVertex {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ u32 color;
    /* 0x10 */ s16 u;
    /* 0x12 */ s16 v;
} SpriteVertex; // size: 0x14

typedef struct ShapeParams {
    /* 0x00 */ Mtx mtx;
    /* 0x30 */ u8 _30[0x40 - 0x30];
    /* 0x40 */ f32 radius;
    /* 0x44 */ f32 _44;
    /* 0x48 */ u32 color0;
    /* 0x4C */ u32 color1;
    /* 0x50 */ s16 _50;
    /* 0x52 */ s16 _52;
    /* 0x54 */ u8 _54;
    /* 0x55 */ u8 _55;
} ShapeParams;

typedef struct SpriteBuffer {
    union {
        /* 0x00 */ SpriteVertex v[4];
        /* 0x00 */ ShapeParams shape;
    };
    /* 0x58 */ u8 _58[0x64 - 0x58];
    /* 0x64 */ MtxPtr mtx;
    /* 0x68 */ u32 color;
    /* 0x6C */ SpriteNest* nest;
    /* 0x70 */ struct TexFile* tex;
    /* 0x74 */ u8 _74[0x78 - 0x74];
    /* 0x78 */ struct SpriteDesc* sprite;
    /* 0x7C */ u16 flag;
    /* 0x7E */ u8 _7E;
    /* 0x7F */ u8 _7F;
    /* 0x80 */ u8 _80[0x84 - 0x80];
    /* 0x84 */ u32 (*callback)(struct SpriteBuffer* buf);
    /* 0x88 */ void (*_88)(struct SpriteBuffer* buf);
    /* 0x8C */ u8 _8C[0x90 - 0x8C];
} SpriteBuffer; // size: 0x90

extern SpriteBuffer lbl_80366188;
extern struct TexImage* lbl_803CBBD8;

extern void fn_800B12DC(SpriteVertex* verts, s32 count);
typedef struct AnimKey {
    /* 0x0 */ u16 frame;
    /* 0x2 */ u16 mode;
    /* 0x4 */ u16 start;
    /* 0x6 */ u8 _06[0xC - 0x6];
} AnimKey; // size: 0xC

typedef struct AnimKeyList {
    /* 0x0 */ u16 count;
    /* 0x2 */ u16 _02;
    /* 0x4 */ AnimKey keys[1];
} AnimKeyList;

typedef struct AnimRecord {
    /* 0x0 */ u16 link : 1;
    /* 0x0 */ u16 type : 15;
    /* 0x2 */ u16 frame;
    /* 0x4 */ u16 count;
    /* 0x6 */ u16 offset;
} AnimRecord;

typedef struct SpriteLayer {
    /* 0x0 */ u16 count;
    /* 0x2 */ u16 _02;
    /* 0x4 */ SpriteDesc entries[1];
} SpriteLayer;

extern void fn_800B2160(s32 mode);
extern void fn_800B1388(SpriteBuffer* buf);
extern void DrawSprite_TexObj(SpriteBuffer* buf, struct TexImage* img);
extern void fn_800B13C0(Vec* verts, u32* colors, s32 count);
extern void DrawNullSprite(SpriteVertex* verts, u32 count);

static inline void setVertexPos(SpriteVertex* v, f32* p) {
    v->x = p[0];
    v->y = p[1];
    v->z = p[2];
}

// Differs: quad stays in r31 in the target and the eight offset loads are scheduled first;
// pts as an array, four Vec locals and loops all keep quad in r28.
// .text:0x8000EF1C size:0x234
void AddVec2iToQuad(f32* quad, Mtx mtx, s32* offset) {
    Mtx m;
    QuadPoint pts[4];

    pts[0].x = quad[0] + offset[0];
    pts[0].y = quad[1] + offset[1];
    pts[0].z = 0.0f;
    pts[1].x = quad[2] + offset[2];
    pts[1].y = quad[3] + offset[3];
    pts[1].z = 0.0f;
    pts[2].x = quad[4] + offset[4];
    pts[2].y = quad[5] + offset[5];
    pts[2].z = 0.0f;
    pts[3].x = quad[6] + offset[6];
    pts[3].y = quad[7] + offset[7];
    pts[3].z = 0.0f;
    PSMTXCopy(mtx, m);
    PSMTXMultVec(m, (Vec*)&pts[0], (Vec*)&pts[0]);
    PSMTXMultVec(m, (Vec*)&pts[1], (Vec*)&pts[1]);
    PSMTXMultVec(m, (Vec*)&pts[2], (Vec*)&pts[2]);
    PSMTXMultVec(m, (Vec*)&pts[3], (Vec*)&pts[3]);
    quad[0] = pts[0].x;
    quad[1] = pts[0].y;
    quad[4] = pts[1].x;
    quad[5] = pts[1].y;
    quad[8] = pts[2].x;
    quad[9] = pts[2].y;
    quad[12] = pts[3].x;
    quad[13] = pts[3].y;
    quad[2] = pts[0].z;
    quad[6] = pts[1].z;
    quad[10] = pts[2].z;
    quad[14] = pts[3].z;
    // Stands in for code the original compiled to nothing: without one more statement MWCC
    // inlines this function into its callers, which call it with bl.
    {
        s32 unused;
        unused = 0;
    }
}

// .text:0x8000EC0C size:0x310
void fn_8000EC0C(SpriteDesc* spr, TexFile* tex, Mtx mtx, SpriteVerts* verts, s32 arg4) {
    f32 quad[16];
    TexImage* img;
    f32 x = 0.0f;
    f32 y = 0.0f;

    img = (TexImage*)((u8*)tex + tex->entries[spr->index]._00 * 32 + 4);
    lbl_803CBBD8 = img;
    quad[0] = x;
    quad[1] = y;
    quad[2] = x + img->width;
    quad[3] = y;
    quad[4] = x;
    quad[5] = y + img->height;
    quad[6] = quad[2];
    quad[7] = quad[5];
    AddVec2iToQuad(quad, mtx, verts->offsets);
    lbl_80366188._7E = 0;
    lbl_80366188.sprite = spr;
    lbl_80366188.v[0].color = verts->colors[0];
    lbl_80366188.v[1].color = verts->colors[1];
    lbl_80366188.v[2].color = verts->colors[2];
    lbl_80366188.v[3].color = verts->colors[3];
    if (spr->flipX && spr->flipY) {
        setVertexPos(&lbl_80366188.v[0], &quad[12]);
        setVertexPos(&lbl_80366188.v[1], &quad[4]);
        setVertexPos(&lbl_80366188.v[2], &quad[0]);
        setVertexPos(&lbl_80366188.v[3], &quad[8]);
    } else if (spr->flipX) {
        setVertexPos(&lbl_80366188.v[0], &quad[4]);
        setVertexPos(&lbl_80366188.v[1], &quad[12]);
        setVertexPos(&lbl_80366188.v[2], &quad[8]);
        setVertexPos(&lbl_80366188.v[3], &quad[0]);
    } else if (spr->flipY) {
        setVertexPos(&lbl_80366188.v[0], &quad[8]);
        setVertexPos(&lbl_80366188.v[1], &quad[0]);
        setVertexPos(&lbl_80366188.v[2], &quad[4]);
        setVertexPos(&lbl_80366188.v[3], &quad[12]);
    } else {
        setVertexPos(&lbl_80366188.v[0], &quad[0]);
        setVertexPos(&lbl_80366188.v[1], &quad[8]);
        setVertexPos(&lbl_80366188.v[2], &quad[12]);
        setVertexPos(&lbl_80366188.v[3], &quad[4]);
    }
    lbl_80366188.v[0].u = 0;
    lbl_80366188.v[0].v = 0;
    lbl_80366188.v[1].u = 0;
    lbl_80366188.v[1].v = 1;
    lbl_80366188.v[2].u = 1;
    lbl_80366188.v[2].v = 1;
    lbl_80366188.v[3].u = 1;
    lbl_80366188.v[3].v = 0;
    lbl_80366188.tex = tex;
    lbl_80366188.flag = arg4 | spr->_b4;
}

// .text:0x8000E900 size:0x30C
void SetSpriteRect(SpriteRect* spr, TexFile* tex, Mtx mtx, SpriteVerts* verts, s32 arg4) {
    f32 quad[16];
    TexImage* img;
    f32 x = 0.0f;
    f32 y = 0.0f;

    img = (TexImage*)((u8*)tex + tex->entries[spr->index]._00 * 32 + 4);
    lbl_803CBBD8 = img;
    quad[0] = x;
    quad[1] = y;
    quad[2] = x + img->width;
    quad[3] = y;
    quad[4] = x;
    quad[5] = y + img->height;
    quad[6] = quad[2];
    quad[7] = quad[5];
    AddVec2iToQuad(quad, mtx, verts->offsets);
    lbl_80366188._7E = 0;
    lbl_80366188.v[0].color = verts->colors[0];
    lbl_80366188.v[1].color = verts->colors[1];
    lbl_80366188.v[2].color = verts->colors[2];
    lbl_80366188.v[3].color = verts->colors[3];
    if (spr->flipX && spr->flipY) {
        setVertexPos(&lbl_80366188.v[0], &quad[12]);
        setVertexPos(&lbl_80366188.v[1], &quad[4]);
        setVertexPos(&lbl_80366188.v[2], &quad[0]);
        setVertexPos(&lbl_80366188.v[3], &quad[8]);
    } else if (spr->flipX) {
        setVertexPos(&lbl_80366188.v[0], &quad[4]);
        setVertexPos(&lbl_80366188.v[1], &quad[12]);
        setVertexPos(&lbl_80366188.v[2], &quad[8]);
        setVertexPos(&lbl_80366188.v[3], &quad[0]);
    } else if (spr->flipY) {
        setVertexPos(&lbl_80366188.v[0], &quad[8]);
        setVertexPos(&lbl_80366188.v[1], &quad[0]);
        setVertexPos(&lbl_80366188.v[2], &quad[4]);
        setVertexPos(&lbl_80366188.v[3], &quad[12]);
    } else {
        setVertexPos(&lbl_80366188.v[0], &quad[0]);
        setVertexPos(&lbl_80366188.v[1], &quad[8]);
        setVertexPos(&lbl_80366188.v[2], &quad[12]);
        setVertexPos(&lbl_80366188.v[3], &quad[4]);
    }
    lbl_80366188.v[0].u = 0;
    lbl_80366188.v[0].v = 0;
    lbl_80366188.v[1].u = 0;
    lbl_80366188.v[1].v = 0x400;
    lbl_80366188.v[2].u = 0x400;
    lbl_80366188.v[2].v = 0x400;
    lbl_80366188.v[3].u = 0x400;
    lbl_80366188.v[3].v = 0;
    lbl_80366188.tex = tex;
    lbl_80366188.flag = arg4 | spr->_b5;
}

// .text:0x8000E7BC size:0x144
void fn_8000E7BC(SpriteDesc* spr, Mtx mtx, SpriteVerts* verts, s32 arg3) {
    f32 quad[16];

    quad[0] = 0.0f;
    quad[1] = 0.0f;
    quad[6] = 256.0f;
    quad[7] = 256.0f;
    quad[2] = 256.0f;
    quad[3] = 0.0f;
    quad[4] = 0.0f;
    quad[5] = 256.0f;
    AddVec2iToQuad(quad, mtx, verts->offsets);
    lbl_80366188._7E = 0;
    lbl_80366188.sprite = spr;
    lbl_80366188.v[0].color = verts->colors[0];
    lbl_80366188.v[0].x = quad[0];
    lbl_80366188.v[0].y = quad[1];
    lbl_80366188.v[0].z = quad[2];
    lbl_80366188.v[1].x = quad[4];
    lbl_80366188.v[1].y = quad[5];
    lbl_80366188.v[1].z = quad[6];
    lbl_80366188.v[2].x = quad[12];
    lbl_80366188.v[2].y = quad[13];
    lbl_80366188.v[2].z = quad[14];
    lbl_80366188.v[3].x = quad[8];
    lbl_80366188.v[3].y = quad[9];
    lbl_80366188.v[3].z = quad[10];
    lbl_80366188.flag = spr->_b4 | (arg3 | (spr->type == 2));
    if (lbl_80366188.flag) {
        lbl_80366188.v[1].color = verts->colors[3];
        lbl_80366188.v[2].color = verts->colors[2];
        lbl_80366188.v[3].color = verts->colors[1];
    } else {
        lbl_80366188.v[1].color = verts->colors[0];
        lbl_80366188.v[2].color = verts->colors[0];
        lbl_80366188.v[3].color = verts->colors[0];
    }
}

// .text:0x8000E764 size:0x58
void fn_8000E764(f32 angle, f32* out) {
    out[0] = sin(angle);
    out[1] = cos(angle);
}

static inline void MultVecRound(Mtx m, Vec* src, Vec* dst) {
    s32 x = m[0][0] * src->x + m[0][1] * src->y + m[0][3] * src->z;
    s32 y = m[1][0] * src->x + m[1][1] * src->y + m[1][3] * src->z;
    s32 z = m[2][0] * src->x + m[2][1] * src->y + m[2][3] * src->z;

    dst->x = x;
    dst->y = y;
    dst->z = z;
}

// Differs: FPR numbers in the first two points (the target loads the matrix row by row, the
// build in another order) and the angle and counter registers swapped; declaration orders tried.
// .text:0x8000E2D4 size:0x490
void fn_8000E2D4(SpriteShape* shape, Mtx mtx, ShapeStyle* style) {
    Vec verts[257];
    u32 colors[257];
    Vec center;
    Vec pt;
    Vec* v;
    s32 i;
    s32 n;
    s32 step;
    s16 angle;
    f32 s;
    f32 a;

    if (shape->_25_b7 && style->_36 == 0) {
        return;
    }
    v = verts;
    for (i = 257; i != 0; i--) {
        v->x = 0.0f;
        v->y = 0.0f;
        v->z = 0.0f;
        v++;
    }
    colors[0] = style->_20;
    angle = 0;
    center.x = 128 - shape->_14;
    center.y = 128 - shape->_16;
    pt.x = 128.0f + center.x;
    pt.y = 128.0f + center.y;
    MultVecRound(mtx, &center, &verts[0]);
    colors[1] = style->_24;
    step = 0x10000 / style->_34;
    MultVecRound(mtx, &pt, &verts[1]);
    n = style->_34;
    if (n != style->_36) {
        n = style->_36 + 1;
    }
    i = n;
    do {
        angle -= step;
        a = 0.0000958738f * angle;
        s = sin(a);
        pt.x = 128.0f * (f32)cos(a) + center.x;
        pt.y = 128.0f * s + center.y;
        MultVecRound(mtx, &pt, &verts[i]);
        colors[i] = style->_24;
    } while (--i != 0);
    if (style->_34 == style->_36) {
        verts[style->_36 + 1].x = verts[1].x;
        verts[style->_36 + 1].y = verts[1].y;
        verts[style->_36 + 1].z = verts[1].z;
        colors[style->_36 + 1] = style->_24;
    }
    fn_800B13C0(verts, colors, style->_36 + 2);
}

// .text:0x8000E030 size:0x2A4
void fn_8000E030(SpriteShape* shape, Mtx mtx, ShapeStyle* style) {
    Vec center;
    Vec pt;
    SpriteVertex verts[259];
    SpriteVertex* v;
    s16 angle;
    s32 step;
    s32 n;
    s32 count;
    f32 s;
    f32 a;

    if (shape->_29_b7 && style->_36 == 0) {
        return;
    }
    center.x = 128.0f;
    center.y = 128.0f;
    center.z = shape->_1A;
    PSMTXMultVec(mtx, &center, (Vec*)&verts[0]);
    verts[0].color = style->_20;
    pt.x = 128.0f + center.x;
    pt.y = center.y;
    pt.z = shape->_18 + shape->_1A;
    PSMTXMultVec(mtx, &pt, (Vec*)&verts[1]);
    verts[1].color = style->_24;
    if (style->_36 != 0) {
        n = style->_36;
        count = style->_36 + 2;
    } else {
        count = style->_34 + 2;
        n = style->_34 - 1;
    }
    step = 0x10000 / style->_34;
    angle = 0;
    v = &verts[2];
    do {
        angle -= step;
        a = 0.0000958738f * angle;
        s = sin(a);
        pt.x = 128.0f * (f32)cos(a) + center.x;
        pt.y = 128.0f * s + center.y;
        pt.z = shape->_1A;
        PSMTXMultVec(mtx, &pt, (Vec*)v);
        v->color = style->_24;
        v++;
    } while (--n != 0);
    if (style->_36 == 0) {
        verts[style->_34 + 1].x = verts[1].x;
        verts[style->_34 + 1].y = verts[1].y;
        verts[style->_34 + 1].z = verts[1].z;
        verts[style->_34 + 1].color = style->_24;
    }
    fn_800B12DC(verts, count);
}

// Differs: saved-register numbers, a copy of the segment count (mr) the target loads in
// place, and the vertex loop, which compares a u16 counter where the target uses ctr.
// .text:0x8000DC9C size:0x394
void fn_8000DC9C(SpriteShape* shape, Mtx mtx, ShapeStyle* style) {
    Vec out;
    Vec pt;
    f32 radius[2];
    SpriteVertex verts[516];
    Vec ringB[257];
    Vec ringA[257];
    Mtx m;
    u32 colorB;
    u32 colorA;
    s32 step;
    s32 n;
    s16 angle;
    Vec* pb;
    s32 i;
    Vec* pa;
    SpriteVertex* v;
    u16 j;
    s32 k;
    u32 count;
    f32 s;
    f32 c;
    f32 a;

    if (shape->_25_b7 && style->_36 == 0) {
        return;
    }
    PSMTXCopy(mtx, m);
    if (style->_30 > 128.0f) {
        radius[1] = 128.0f;
        colorB = style->_24;
        radius[0] = style->_30;
        colorA = style->_20;
    } else {
        radius[0] = 128.0f;
        colorA = style->_24;
        radius[1] = style->_30;
        colorB = style->_20;
    }
    for (i = 0; i < 2; i++) {
        pt.x = 128.0f + radius[i];
        pt.y = 128.0f;
        pt.z = 0.0f;
        PSMTXMultVec(m, &pt, &out);
        if (i != 0) {
            ringA[0].x = out.x;
            ringA[0].y = out.y;
            ringA[0].z = out.z;
        } else {
            ringB[0].x = out.x;
            ringB[0].y = out.y;
            ringB[0].z = out.z;
        }
    }
    if (style->_36 != 0) {
        n = style->_36;
    } else {
        n = style->_34 - 1;
    }
    step = 0x10000 / style->_34;
    angle = 0;
    pa = &ringA[1];
    pb = &ringB[1];
    do {
        angle -= step;
        a = 0.0000958738f * angle;
        s = sin(a);
        c = cos(a);
        for (i = 0; i < 2; i++) {
            pt.x = c * radius[i] + 128.0f;
            pt.y = s * radius[i] + 128.0f;
            pt.z = 0.0f;
            PSMTXMultVec(m, &pt, &out);
            if (i != 0) {
                pa->x = out.x;
                pa->y = out.y;
                pa->z = out.z;
            } else {
                pb->x = out.x;
                pb->y = out.y;
                pb->z = out.z;
            }
        }
        pa++;
        pb++;
    } while (--n != 0);
    if (!shape->_25_b7) {
        k = style->_34;
        ringA[k].x = ringA[0].x;
        ringB[k].x = ringB[0].x;
        ringA[k].y = ringA[0].y;
        ringB[k].y = ringB[0].y;
        ringA[k].z = ringA[0].z;
        ringB[k].z = ringB[0].z;
    }
    if (shape->_25_b7) {
        count = (style->_36 + 1) * 2;
    } else {
        count = (style->_34 + 1) * 2;
    }
    pa = ringA;
    pb = ringB;
    v = verts;
    for (j = 0; j < count; j += 2) {
        v[0].x = pb->x;
        v[1].x = pa->x;
        v[0].y = pb->y;
        v[1].y = pa->y;
        v[0].z = pb->z;
        v[1].z = pa->z;
        v[0].color = colorA;
        v[1].color = colorB;
        pa++;
        pb++;
        v += 2;
    }
    DrawNullSprite(verts, count);
}

// Differs like fn_8000DC9C, from which it was written: saved-register numbers, the
// segment count's copy and the u16 vertex loop counter where the target uses ctr.
// .text:0x8000D8A4 size:0x3F8
void fn_8000D8A4(SpriteShape* shape, Mtx mtx, ShapeStyle* style) {
    Vec out;
    Vec pt;
    f32 radius[2];
    SpriteVertex verts[516];
    Vec ringB[257];
    Vec ringA[257];
    u32 colorB;
    u32 colorA;
    s32 step;
    s32 n;
    s16 angle;
    Vec* pb;
    s32 i;
    Vec* pa;
    SpriteVertex* v;
    u16 j;
    s32 k;
    u32 count;
    f32 s;
    f32 c;
    f32 a;
    f32 z;

    if (shape->_29_b7 && style->_36 == 0) {
        return;
    }
    z = shape->_1A;
    if (style->_30 > 128.0f) {
        radius[1] = 128.0f;
        colorB = style->_24;
        radius[0] = style->_30;
        colorA = style->_20;
    } else {
        radius[0] = 128.0f;
        colorA = style->_24;
        radius[1] = style->_30;
        colorB = style->_20;
    }
    for (i = 0; i < 2; i++) {
        pt.x = 128.0f + radius[i];
        pt.y = 128.0f;
        pt.z = shape->_18 + z;
        PSMTXMultVec(mtx, &pt, &out);
        if (i != 0) {
            ringA[0].x = out.x;
            ringA[0].y = out.y;
            ringA[0].z = out.z;
        } else {
            ringB[0].x = out.x;
            ringB[0].y = out.y;
            ringB[0].z = out.z;
        }
    }
    if (style->_36 != 0) {
        n = style->_36;
    } else {
        n = style->_34 - 1;
    }
    step = 0x10000 / style->_34;
    angle = 0;
    pa = &ringA[1];
    pb = &ringB[1];
    do {
        angle -= step;
        a = 0.0000958738f * angle;
        s = sin(a);
        c = cos(a);
        for (i = 0; i < 2; i++) {
            pt.x = c * radius[i] + 128.0f;
            pt.y = s * radius[i] + 128.0f;
            pt.z = shape->_18 + z;
            PSMTXMultVec(mtx, &pt, &out);
            if (i != 0) {
                pa->x = out.x;
                pa->y = out.y;
                pa->z = out.z;
            } else {
                pb->x = out.x;
                pb->y = out.y;
                pb->z = out.z;
            }
        }
        pa++;
        pb++;
    } while (--n != 0);
    if (!shape->_29_b7) {
        k = style->_34;
        ringA[k].x = ringA[0].x;
        ringB[k].x = ringB[0].x;
        ringA[k].y = ringA[0].y;
        ringB[k].y = ringB[0].y;
        ringA[k].z = ringA[0].z;
        ringB[k].z = ringB[0].z;
    }
    if (shape->_29_b7) {
        count = (style->_36 + 1) * 2;
    } else {
        count = (style->_34 + 1) * 2;
    }
    memset(verts, 0, sizeof(verts));
    pa = ringA;
    pb = ringB;
    v = verts;
    for (j = 0; j < count; j += 2) {
        v[0].x = pb->x;
        v[1].x = pa->x;
        v[0].y = pb->y;
        v[1].y = pa->y;
        v[0].z = pb->z;
        v[1].z = pa->z;
        v[0].color = colorA;
        v[1].color = colorB;
        pa++;
        pb++;
        v += 2;
    }
    DrawNullSprite(verts, count);
}

// .text:0x8000D838 size:0x6C
void fn_8000D838(void) {
}

// Differs: the schedule of the colour loop and the saved registers that follow from it
// (statement and declaration orders tried in random batches), and the prologue's load order.
// .text:0x8000D164 size:0x6D4
s32 fn_8000D164(u32* time, AnimFile* file, s32 idx, Mtx mtx, s32 flags, u32 color, u16** outKey, TexFile* tex) {
    SpriteVerts verts;
    Mtx m;
    InterpPoint pt;
    u32 dstA[4];
    u32 dstB[4];
    u32 dstG[4];
    u32 dstR[4];
    u32 srcA[4];
    u32 srcB[4];
    u32 srcG[4];
    u32 srcR[4];
    u32 t;
    u16* subKey;
    s32 i;
    s32 k;
    AnimKey* key;
    u32 start;
    u32 span;
    f32 f;
    s32 j;
    SpriteLayer** lp;
    SpriteDesc* e;
    u32 now;
    SpriteDesc* next;
    u32 c;
    SpriteLayer* layer;
    AnimKeyList* keys;
    u32 dt;
    s32 n;
    u16 frame;
    SpritePalette* arg;
    s32 ret;
    AnimTrack* track;
    track = ((AnimTrack**)file->tracks)[idx + 2];
    keys = (AnimKeyList*)track->frames[0];
    arg = file->_0C;
    now = *time;
    ret = 0;
    n = track->count;
    *outKey = NULL;
    key = &keys->keys[keys->count];
    for (i = keys->count; i != 0; i--) {
        key--;
        if (now >= key->frame << 16) {
            *outKey = &key->start;
            ret = key->mode + 1;
            if (key->mode == 0) {
                now %= key->frame << 16;
            } else if (key->mode == 2) {
                start = **outKey << 16;
                now = start + (now - start) % ((key->frame << 16) - start);
            }
            *time = now;
            break;
        }
    }
    n--;
    lbl_80366188._7F = 0;
    lp = (SpriteLayer**)&track->frames[n];
    do {
        layer = *lp--;
        j = layer->count;
        k = j;
        e = &layer->entries[j];
        next = e - 1;
        while (k-- != 0) {
            e--;
            j--;
            frame = e->frame;
            if (now < frame << 16) {
                next = e;
                continue;
            }
            if (e->_b5) {
                SpriteDesc* p = e;
                for (; k != 0; k--) {
                    p--;
                    if (!((k != 1) & p->_b5)) {
                        frame = p->frame;
                    }
                }
            }
            if (next->type == 0) {
                next = e;
            }
            if (e->type != 0) {
                dt = now - (e->frame << 16);
                f = 1.0f;
                span = (next->frame - e->frame) << 16;
                if (dt < span) {
                    f = (f32)dt / (f32)span;
                }
                if (e->_b3) {
                    if (e[-1]._b3 && j != 0) {
                        if (e[1]._b3) {
                            interpolatePointsBezier_Vec2s(&pt, (BezierVec2s*)(e - 1), (BezierVec2s*)e, (BezierVec2s*)(e + 1), (BezierVec2s*)(e + 2), 1, f);
                        } else {
                            interpolatePointsBezier_Vec2s(&pt, (BezierVec2s*)(e - 1), (BezierVec2s*)(e - 1), (BezierVec2s*)e, (BezierVec2s*)(e + 1), 2, f);
                        }
                    } else if (j == 0) {
                        interpolatePointsBezier_Vec2s(&pt, (BezierVec2s*)e, (BezierVec2s*)(e + 1), (BezierVec2s*)(e + 1), (BezierVec2s*)(e + 2), 0, f);
                    } else {
                        interpolatePointsBezier_Vec2s(&pt, (BezierVec2s*)e, (BezierVec2s*)(e + 1), (BezierVec2s*)(e + 2), (BezierVec2s*)(e + 2), 0, f);
                    }
                }
                flags |= fn_8000AF1C(m, &verts, e, next, arg, &pt, f);
                PSMTXConcat(mtx, m, m);
                for (i = 0; i < 4; i++) {
                    c = verts.colors[i];
                    dstR[i] = color >> 24;
                    dstG[i] = (color >> 16) & 0xFF;
                    srcR[i] = c >> 24;
                    dstB[i] = (color >> 8) & 0xFF;
                    srcB[i] = (c >> 8) & 0xFF;
                    srcG[i] = (c >> 16) & 0xFF;
                    dstA[i] = color & 0xFF;
                    srcA[i] = c & 0xFF;
                    dstR[i] = dstR[i] * srcR[i] / 255;
                    dstG[i] = dstG[i] * srcG[i] / 255;
                    dstB[i] = dstB[i] * srcB[i] / 255;
                    dstA[i] = dstA[i] * srcA[i] / 255;
                    verts.colors[i] = (dstR[i] << 24) | (dstG[i] << 16) | (dstB[i] << 8) | dstA[i];
                }
                switch (e->_00_b7) {
                case 0:
                    fn_800B2160(1);
                    break;
                case 1:
                    fn_800B2160(2);
                    break;
                case 2:
                    fn_800B2160(3);
                    break;
                }
                switch (e->type) {
                case 1:
                case 2:
                    fn_8000E7BC(e, m, &verts, flags);
                    t = TRUE;
                    if (lbl_80366188.callback != NULL && e->_b2) {
                        t = lbl_80366188.callback(&lbl_80366188);
                    }
                    if (t) {
                        fn_800B1388(&lbl_80366188);
                    }
                    break;
                case 3:
                    t = TRUE;
                    if (lbl_80366188.callback != NULL && e->_b2) {
                        lbl_80366188.sprite = e;
                        lbl_80366188.tex = NULL;
                        lbl_80366188.flag = 1;
                        lbl_80366188._7E = 1;
                        memcpy(lbl_80366188.shape.mtx, m, sizeof(Mtx));
                        lbl_80366188.shape.color0 = verts.colors[0];
                        lbl_80366188.shape.color1 = verts.colors[1];
                        lbl_80366188.shape._50 = e->_14;
                        lbl_80366188.shape._52 = e->_16;
                        lbl_80366188.shape.radius = 128.0f;
                        lbl_80366188.shape._44 = verts._30;
                        lbl_80366188.shape._54 = verts._34;
                        lbl_80366188.shape._55 = verts._36;
                        t = lbl_80366188.callback(&lbl_80366188);
                    }
                    if (t) {
                        if (verts._30 == 0.0f) {
                            fn_8000E2D4((SpriteShape*)e, m, (ShapeStyle*)&verts);
                        } else {
                            fn_8000DC9C((SpriteShape*)e, m, (ShapeStyle*)&verts);
                        }
                    }
                    break;
                case 4:
                    fn_8000EC0C(e, tex, m, &verts, flags);
                    t = TRUE;
                    if (lbl_80366188.callback != NULL && e->_b2) {
                        t = lbl_80366188.callback(&lbl_80366188);
                    }
                    if (t) {
                        DrawSprite_TexObj(&lbl_80366188, lbl_803CBBD8);
                    }
                    break;
                case 5:
                    t = now - (frame << 16);
                    fn_8000D164(&t, file, e->index, m, flags, verts.colors[0], &subKey, tex);
                    break;
                }
            }
            break;
        }
    } while (--n != 0);
    return ret;
}

// Differs: four fewer saved registers in the target (stw r28-r31, not stmw r27) and the
// case 2/3 copy loops, whose pointers the target steps down from the end.
// .text:0x8000CEF0 size:0x274
u32 fn_8000CEF0(AnimFile* file, s32 idx, u32 frame, s32 skip, u32* dst) {
    AnimTrack* track = ((AnimTrack**)file->tracks)[idx + 2];
    AnimFrame* f;
    u32* p;
    u32* next;
    s32 n;
    u32* body;
    u16 count;
    u32* vals;
    u16* ids;
    u16* ent;
    u8* src;
    u32 words;
    u32 stride;
    u32 size;

    if (frame >= (track->count & 0x7FFFFFFF) - 1) {
        return FALSE;
    }
    frame++;
    f = ((AnimFrame**)track)[frame + 2];
    n = f->count - skip;
    if (n <= 0) {
        return FALSE;
    }
    p = (u32*)(f + 1);
    while (--n != 0) {
        next = p;
        words = (u32)f->size >> 2;
        stride = file->_05;
        switch (((u16*)p)[0] & 0x7FFF) {
        case 0:
            next = p + words;
            break;
        case 1:
            next = p + stride;
            break;
        case 2:
            next = p + ((u16*)p)[3];
            break;
        case 3:
            next = p + ((u16*)p)[3];
            break;
        }
        p = next;
    }
    size = file->_05 * 4;
    switch (((u16*)p)[0] & 0x7FFF) {
    case 0:
        memset(dst, 0, size);
        memcpy(dst, f + 1, f->size);
        break;
    case 1:
        memcpy(dst, p, size);
        break;
    case 2:
        memset(dst, 0, size);
        body = dst + 1;
        memcpy(body, (u8*)f + 8, f->size - 4);
        memcpy(dst, p, 4);
        count = ((u16*)p)[2];
        vals = p + ((u16*)p)[3];
        ids = (u16*)p + count;
        while (count-- != 0) {
            vals--;
            ids--;
            body[ids[4]] = *vals;
        }
        break;
    case 3:
        memset(dst, 0, size);
        body = dst + 1;
        memcpy(body, (u8*)f + 8, f->size - 4);
        memcpy(dst, p, 4);
        count = ((u16*)p)[2];
        ent = (u16*)(p + 2);
        src = (u8*)(p + count + 2);
        while (count-- != 0) {
            memcpy((u8*)body + ent[0], src, ent[1]);
            src += ent[1];
            ent += 2;
        }
        break;
    }
    return TRUE;
}

// Differs: saved-register numbers throughout, and src + (size + 4) is computed as
// (size + src) + 4; inlining that sum into its memcpy fixed the order but not the registers.
// .text:0x8000CC4C size:0x2A4
void fn_8000CC4C(AnimFile* file, AnimFrame* f, u8* src, u32 offset, u32 size) {
    u32* p = (u32*)(f + 1);
    u8* srcEnd = src + (size + 4);
    u32 end = offset + size;
    s32 i;
    u32 lim;
    u32 d;
    u32* vals;
    u16* ids;
    s32 j;
    u32 base;
    u32 o;
    u16* ent;
    u8* dst;
    u16 eo;
    u16 elen;
    u32* next;
    u32 words;
    u32 stride;

    for (i = 0; i < f->count; i++) {
        switch (((u16*)p)[0] & 0x7FFF) {
        case 0:
            if (f->size < end && f->size - offset == 0) {
                break;
            }
        case 1:
            memcpy((u8*)p + offset, src, size);
            break;
        case 2:
            base = offset - 4;
            ids = (u16*)p;
            lim = base + size;
            vals = (u32*)((u8*)p + (((((u16*)p)[2] + 1) * 2) & ~3) + 8);
            for (j = 0; j < ((u16*)p)[2]; j++) {
                o = ids[4] * 4;
                if (o >= lim) {
                    break;
                }
                if (o + 4 > base) {
                    d = o + 4 - base;
                    if (d < 4) {
                        if (d > size) {
                            d = size;
                        }
                        memcpy((u8*)vals + 4 - d, src, d);
                    } else {
                        d = lim - o;
                        if (d < 4) {
                            memcpy(vals, srcEnd - d, d);
                        } else {
                            memcpy(vals, src + o - base, 4);
                        }
                    }
                }
                ids++;
                vals++;
            }
            break;
        case 3:
            base = offset - 4;
            ent = (u16*)p;
            lim = base + size;
            dst = (u8*)p + ((u16*)p)[2] * 4 + 8;
            for (j = 0; j < ((u16*)p)[2]; j++) {
                eo = ent[4];
                elen = ent[5];
                if (eo >= lim) {
                    break;
                }
                if (eo + elen > base) {
                    d = base - eo;
                    if (d < elen) {
                        o = elen - d;
                        if (o > size) {
                            o = size;
                        }
                        memcpy(dst + d, src, o);
                    } else if (lim < eo + elen) {
                        memcpy(dst, src + (eo - base), lim - eo);
                    } else {
                        memcpy(dst, src + (eo - base), elen);
                    }
                }
                dst += elen;
                ent += 2;
            }
            break;
        }
        next = p;
        words = f->size >> 2;
        stride = file->_05;
        switch (((u16*)p)[0] & 0x7FFF) {
        case 0:
            next = p + words;
            break;
        case 1:
            next = p + stride;
            break;
        case 2:
            next = p + ((u16*)p)[3];
            break;
        case 3:
            next = p + ((u16*)p)[3];
            break;
        }
        p = next;
    }
}

// .text:0x8000C194 size:0xAB8
void fn_8000C194(void) {
}

// Differs: the schedule of the colour loop and the saved registers that follow from it, and
// case 3's source pointer, which the build computes from the entry pointer (rec + 8).
// .text:0x8000BA3C size:0x758
s32 fn_8000BA3C(u32* time, AnimFile* file, s32 idx, Mtx mtx, s32 flags, u32 color, u16** outKey, SpriteNest* nest) {
    SpriteKey keys[2];
    SpriteVerts verts;
    Mtx m;
    InterpPoint pt;
    u32 dstA[4];
    u32 dstB[4];
    u32 dstG[4];
    u32 dstR[4];
    u32 srcA[4];
    u32 srcB[4];
    u32 srcG[4];
    u32 srcR[4];
    u32* recs[2];
    u32 t;
    u16* subKey;
    s32 ret;
    AnimTrack* track;
    AnimKeyList* keys_;
    AnimKey* key;
    AnimFrame** lp;
    AnimFrame* layer;
    SpriteKey* cur;
    SpriteKey* next;
    u32* p;
    u32* dst;
    u32* body;
    u32* vals;
    u16* ids;
    u16* ent;
    u8* src;
    u32 now;
    u32 start;
    u32 dt;
    u32 span;
    u32 words;
    u32 stride;
    s32 i;
    s32 k;
    s32 count;
    u16 frame;
    f32 f;
    u32 c;

    if (nest != NULL) {
        nest->index = idx;
    }
    now = *time;
    track = ((AnimTrack**)file->tracks)[idx + 2];
    ret = 0;
    keys_ = (AnimKeyList*)track->frames[0];
    idx = track->count & 0x7FFFFFFF;
    *outKey = NULL;
    key = &keys_->keys[keys_->count];
    for (i = keys_->count; i != 0; i--) {
        key--;
        if (now >= key->frame << 16) {
            *outKey = &key->start;
            ret = key->mode + 1;
            if (key->mode == 0) {
                now %= key->frame << 16;
            } else if (key->mode == 2) {
                start = **outKey << 16;
                now = start + (now - start) % ((key->frame << 16) - start);
            }
            *time = now;
            break;
        }
    }
    idx--;
    lp = &track->frames[idx];
    lbl_80366188._7F = 0;
    if (nest != NULL) {
        nest->layer = 0;
    }
    do {
        layer = *lp--;
        p = recs[1] = (u32*)(layer + 1);
        k = layer->count;
        while (k-- != 0) {
            recs[0] = p;
            frame = ((u16*)p)[1];
            if (now < ((u16*)p)[1] << 16) {
                recs[1] = p;
                words = (u32)layer->size >> 2;
                stride = file->_05;
                switch (((u16*)p)[0] & 0x7FFF) {
                case 0:
                    p += words;
                    break;
                case 1:
                    p += stride;
                    break;
                case 2:
                    p += ((u16*)p)[3];
                    break;
                case 3:
                    p += ((u16*)p)[3];
                    break;
                }
                continue;
            }
            if (((AnimRecord*)p)->link) {
                for (; k != 0; k--) {
                    words = (u32)layer->size >> 2;
                    stride = file->_05;
                    switch (((u16*)p)[0] & 0x7FFF) {
                    case 0:
                        p += words;
                        break;
                    case 1:
                        p += stride;
                        break;
                    case 2:
                        p += ((u16*)p)[3];
                        break;
                    case 3:
                        p += ((u16*)p)[3];
                        break;
                    }
                    if (!((k != 1) & ((AnimRecord*)p)->link)) {
                        frame = ((u16*)p)[1];
                    }
                }
            }
            for (i = 0; i < 2; i++) {
                dst = (u32*)&keys[i];
                switch (((u16*)recs[i])[0] & 0x7FFF) {
                case 0:
                    memset(dst, 0, file->_05 * 4);
                    memcpy(dst, layer + 1, layer->size);
                    break;
                case 1:
                    memcpy(dst, recs[i], file->_05 * 4);
                    break;
                case 2:
                    memset(dst, 0, file->_05 * 4);
                    body = dst + 1;
                    memcpy(body, (u8*)layer + 8, layer->size - 4);
                    memcpy(dst, recs[i], 4);
                    count = ((u16*)recs[i])[2];
                    vals = recs[i] + ((u16*)recs[i])[3] - count;
                    ids = (u16*)recs[i];
                    while (count-- != 0) {
                        body[ids[count + 4]] = vals[count];
                    }
                    break;
                case 3:
                    memset(dst, 0, file->_05 * 4);
                    body = dst + 1;
                    memcpy(body, (u8*)layer + 8, layer->size - 4);
                    memcpy(dst, recs[i], 4);
                    count = ((u16*)recs[i])[2];
                    ent = (u16*)(recs[i] + 2);
                    src = (u8*)recs[i] + count * 4 + 8;
                    while (count-- != 0) {
                        memcpy((u8*)body + ent[0], src, ent[1]);
                        src += ent[1];
                        ent += 2;
                    }
                    break;
                }
            }
            cur = &keys[0];
            if (keys[1].type == 0) {
                next = cur;
            } else {
                next = &keys[1];
            }
            if (keys[0].type != 0) {
                dt = now - (keys[0].frame << 16);
                f = 1.0f;
                span = (next->frame - keys[0].frame) << 16;
                if (dt < span) {
                    f = (f32)dt / (f32)span;
                }
                if (keys[0]._08_b4) {
                    fn_8000A0AC(&pt, (BezierKey*)cur, (BezierKey*)next, f);
                }
                flags |= fn_8000A3EC(m, &verts, cur, next, &pt, f, next->z);
                PSMTXConcat(mtx, m, m);
                for (i = 0; i < 4; i++) {
                    c = verts.colors[i];
                    dstR[i] = color >> 24;
                    dstG[i] = (color >> 16) & 0xFF;
                    srcR[i] = c >> 24;
                    dstB[i] = (color >> 8) & 0xFF;
                    srcB[i] = (c >> 8) & 0xFF;
                    srcG[i] = (c >> 16) & 0xFF;
                    dstA[i] = color & 0xFF;
                    srcA[i] = c & 0xFF;
                    dstR[i] = dstR[i] * srcR[i] / 255;
                    dstG[i] = dstG[i] * srcG[i] / 255;
                    dstB[i] = dstB[i] * srcB[i] / 255;
                    dstA[i] = dstA[i] * srcA[i] / 255;
                    verts.colors[i] = (dstR[i] << 24) | (dstG[i] << 16) | (dstB[i] << 8) | dstA[i];
                }
                switch (keys[0].type) {
                case 2:
                    break;
                case 1:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    if (nest != NULL && lbl_80366188._88 != NULL) {
                        lbl_80366188.nest = nest;
                        lbl_80366188.mtx = m;
                        lbl_80366188.color = verts.colors[0];
                        lbl_80366188._88(&lbl_80366188);
                    }
                    if (keys[0].type == 3) {
                        t = now - (frame << 16);
                        fn_8000BA3C(&t, file, keys[0].index, m, flags, verts.colors[0], &subKey, nest + 1);
                    }
                    break;
                }
            }
            break;
        }
        if (nest != NULL) {
            nest->layer++;
        }
    } while (--idx != 0);
    return ret;
}
