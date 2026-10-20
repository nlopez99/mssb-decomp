#include "static/static_8000BA3C.h"
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

typedef struct SpriteBuffer {
    /* 0x00 */ SpriteVertex v[4];
    /* 0x50 */ u8 _50[0x70 - 0x50];
    /* 0x70 */ struct TexFile* tex;
    /* 0x74 */ u8 _74[0x78 - 0x74];
    /* 0x78 */ struct SpriteDesc* sprite;
    /* 0x7C */ u16 flag;
    /* 0x7E */ u8 _7E;
    /* 0x7F */ u8 _7F[0x88 - 0x7F];
    /* 0x88 */ void* _88;
    /* 0x8C */ u8 _8C[0x90 - 0x8C];
} SpriteBuffer; // size: 0x90

extern SpriteBuffer lbl_80366188;
extern struct TexImage* lbl_803CBBD8;

extern void fn_800B12DC(SpriteVertex* verts, s32 count);
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

// .text:0x8000E2D4 size:0x490
void fn_8000E2D4(void) {
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

// Differs: the target computes the ring addresses for the closing copy late and runs the
// vertex loop on ctr; with a u32 counter this build unrolls it, with u16 it compares.
// .text:0x8000DC9C size:0x394
void fn_8000DC9C(SpriteShape* shape, Mtx mtx, ShapeStyle* style) {
    Vec out;
    Vec pt;
    f32 radius[2];
    SpriteVertex verts[516];
    Vec ringB[257];
    Vec ringA[257];
    Mtx m;
    u32 colorA;
    u32 colorB;
    s32 i;
    s32 n;
    s32 step;
    s16 angle;
    Vec* pa;
    Vec* pb;
    SpriteVertex* v;
    u16 j;
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
        ringA[style->_34].x = ringA[0].x;
        ringB[style->_34].x = ringB[0].x;
        ringA[style->_34].y = ringA[0].y;
        ringB[style->_34].y = ringB[0].y;
        ringA[style->_34].z = ringA[0].z;
        ringB[style->_34].z = ringB[0].z;
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

// Draft from fn_8000DC9C, with its differences: the ring addresses for the closing copy
// are hoisted to saved registers and the vertex loop is unrolled by two.
// .text:0x8000D8A4 size:0x3F8
void fn_8000D8A4(SpriteShape* shape, Mtx mtx, ShapeStyle* style) {
    Vec out;
    Vec pt;
    f32 radius[2];
    SpriteVertex verts[516];
    Vec ringB[257];
    Vec ringA[257];
    u32 colorA;
    u32 colorB;
    s32 i;
    s32 n;
    s32 step;
    s16 angle;
    Vec* pa;
    Vec* pb;
    SpriteVertex* v;
    u32 j;
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
        ringA[style->_34].x = ringA[0].x;
        ringB[style->_34].x = ringB[0].x;
        ringA[style->_34].y = ringA[0].y;
        ringB[style->_34].y = ringB[0].y;
        ringA[style->_34].z = ringA[0].z;
        ringB[style->_34].z = ringB[0].z;
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

// .text:0x8000D164 size:0x6D4
void fn_8000D164(void) {
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

// .text:0x8000CC4C size:0x2A4
void fn_8000CC4C(void) {
}

// .text:0x8000C194 size:0xAB8
void fn_8000C194(void) {
}

// .text:0x8000BA3C size:0x758
void fn_8000BA3C(void) {
}
