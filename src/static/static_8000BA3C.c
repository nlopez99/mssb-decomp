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

static inline void setVertexPos(SpriteVertex* v, f32* p) {
    v->x = p[0];
    v->y = p[1];
    v->z = p[2];
}

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
void fn_8000E030(void) {
}

// .text:0x8000DC9C size:0x394
void fn_8000DC9C(void) {
}

// .text:0x8000D8A4 size:0x3F8
void fn_8000D8A4(void) {
}

// .text:0x8000D838 size:0x6C
void fn_8000D838(void) {
}

// .text:0x8000D164 size:0x6D4
void fn_8000D164(void) {
}

// .text:0x8000CEF0 size:0x274
BOOL fn_8000CEF0(AnimFile* file, s32 idx, u32 frame, s32 skip, u32* dst) {
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
