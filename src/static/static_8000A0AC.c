#include "static/static_8000A0AC.h"
#include "static/static_80009E94.h"
#include "static/static_8000BA3C.h"

#define LERP(a, b) ((a) != (b) ? (a) * it + (b) * t : (a))

typedef struct RelocHeader {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u32 _08;
    /* 0x0C */ u32 _0C;
} RelocHeader;

typedef struct RelocList {
    /* 0x00 */ u32 count;
    /* 0x04 */ u32 _04;
    /* 0x08 */ u32 offsets[1];
} RelocList;

// .text:0x8000B9C8 size:0x74
void fn_8000B9C8(RelocHeader* hdr) {
    u32* p;
    u32* q;
    s32 n;
    s32 m;
    RelocList* sub;
    RelocList* list;

    hdr->_08 += (u32)hdr;
    if (hdr->_06 == 0) {
        hdr->_0C += (u32)hdr;
    }
    list = (RelocList*)hdr->_08;
    n = list->count;
    p = (u32*)list;
    do {
        p[2] += (u32)list;
        sub = (RelocList*)p[2];
        q = (u32*)sub;
        m = sub->count & 0x7FFFFFFF;
        do {
            q[2] += (u32)sub;
            q++;
        } while (--m != 0);
        n--;
        p++;
    } while (n != 0);
}

// .text:0x8000AF1C size:0xAAC
s32 fn_8000AF1C(Mtx out, SpriteVerts* verts, SpriteDesc* key, SpriteDesc* next, SpritePalette* pal, InterpPoint* pt, f32 t) {
    Mtx trans;
    Mtx scale;
    Mtx rot;
    f32 sc[4];
    Quaternion q;
    GXColor c;
    SpriteCorner* ka;
    SpriteCorner* kb;
    s32* o;
    SpriteColor* a;
    SpriteColor* b;
    s32 i;
    u32 word;
    u32 type;
    f32 it;
    f32 angle;
    f32 px;
    f32 py;
    f32 sa;
    f32 sb;
    px = 0.0f;
    py = 0.0f;
    it = 1.0f - t;
    if (key->_14 ^ next->_14) {
        px = key->_14 * it + next->_14 * t;
    } else if (key->_14) {
        px = key->_14;
    }
    if (key->_16 ^ next->_16) {
        py = key->_16 * it + next->_16 * t;
    } else if (key->_16) {
        py = key->_16;
    }
    PSMTXIdentity(scale);
    scale[0][0] = key->scaleX / 1024.0f * it + next->scaleX / 1024.0f * t;
    scale[1][1] = key->scaleY / 1024.0f * it + next->scaleY / 1024.0f * t;
    scale[0][3] = scale[0][0] * -px;
    scale[1][3] = scale[1][1] * -py;
    if (key->rot != next->rot) {
        angle = key->rot / 4096.0f * it + next->rot / 4096.0f * t;
    } else {
        angle = key->rot / 4096.0f;
    }
    if (angle) {
        angle *= 360.0f;
        if (key->_b1 != next->_b1) {
            angle *= 0.5f;
            fn_8000E764(1.5707964f * t, sc);
            sa = sc[key->_b1];
            sb = sc[next->_b1];
            fn_8000E764(0.017453292f * angle, sc);
            q.x = 0.0f;
            q.y = sa * sc[0];
            q.z = sb * sc[0];
            q.w = sc[1];
            PSMTXQuat(rot, &q);
        } else if (key->_b1) {
            PSMTXRotRad(rot, 'Y', 0.017453292f * angle);
        } else {
            PSMTXRotRad(rot, 'Z', 0.017453292f * angle);
        }
        PSMTXConcat(rot, scale, scale);
    }
    PSMTXTrans(trans, px, py, 0.0f);
    if (key->_b3) {
        trans[0][3] += pt->x;
        trans[1][3] += pt->y;
    } else if (key->x != next->x || key->y != next->y) {
        trans[0][3] += key->x * it + next->x * t;
        trans[1][3] += key->y * it + next->y * t;
    } else {
        trans[0][3] += key->x;
        trans[1][3] += key->y;
    }
    PSMTXConcat(trans, scale, out);
    ka = key->corners;
    kb = next->corners;
    o = verts->offsets;
    for (i = 0; i < 4; i++) {
        if (ka->xy != kb->xy) {
            o[0] = ka->x * it + kb->x * t;
            o[1] = ka->y * it + kb->y * t;
        } else {
            o[0] = ka->x;
            o[1] = ka->y;
        }
        ka++;
        kb++;
        o += 2;
    }
    type = key->type;
    if (type == 3) {
        verts->_30 = LERP(key->shape._18, next->shape._18);
        verts->_34 = LERP(key->shape._1A, next->shape._1A);
        verts->_36 = LERP(key->shape._26, next->shape._26);
        verts->colors[0] = LERP(key->shape._1C, next->shape._1C);
        verts->colors[1] = LERP(key->shape._20, next->shape._20);
    } else if (type != 2) {
        if (key->color != next->color) {
            c.r = it * key->rgba.r + t * next->rgba.r;
            c.g = it * key->rgba.g + t * next->rgba.g;
            c.b = it * key->rgba.b + t * next->rgba.b;
            c.a = it * key->rgba.a + t * next->rgba.a;
            verts->colors[0] = verts->colors[1] = verts->colors[2] = verts->colors[3] = *(u32*)&c;
        } else {
            verts->colors[0] = verts->colors[1] = verts->colors[2] = verts->colors[3] = key->color;
        }
    } else {
        for (i = 0; i < 4; i++) {
            a = &pal->colors[key->index][i];
            b = &pal->colors[next->index][i];
            word = a->word;
            if (word != b->word) {
                c.r = it * a->rgba.r + t * b->rgba.r;
                c.g = it * a->rgba.g + t * b->rgba.g;
                c.b = it * a->rgba.b + t * b->rgba.b;
                c.a = it * a->rgba.a + t * b->rgba.a;
                verts->colors[i] = *(u32*)&c;
            } else {
                verts->colors[i] = word;
            }
        }
    }
    return !!angle;
}

// Differs: the colour loop walks key, next and c with pointers where the target indexes them
// (lbzx/stbx off one counter); local copies and index forms did not change it.
// .text:0x8000A3EC size:0xB30
s32 fn_8000A3EC(Mtx out, SpriteVerts* verts, SpriteKey* key, SpriteKey* next, InterpPoint* pt, f32 t, f32 z) {
    Mtx trans;
    Mtx scale;
    Mtx rot;
    u8 c[4];
    u8* ka;
    u8* kb;
    s16* kr;
    s16* nr;
    s32 i;
    s32 j;
    s32 stride;
    s32 ret;
    f32 it;
    f32 px;
    f32 py;
    f32 a;

    px = 0.0f;
    py = 0.0f;
    it = 1.0f - t;
    if (key->type == 2) {
        verts->_30 = key->shape._1C != next->shape._28 ? key->shape._28 * it + next->shape._28 * t : key->shape._28;
        verts->_34 = LERP(key->shape._1E, next->shape._1E);
        verts->_36 = LERP(key->shape._2A, next->shape._2A);
        if (*(u32*)&key->shape._20 != *(u32*)&next->shape._20) {
            ((GXColor*)&verts->colors[0])->r = it * key->shape._20.r + t * next->shape._20.r;
            ((GXColor*)&verts->colors[0])->g = it * key->shape._20.g + t * next->shape._20.g;
            ((GXColor*)&verts->colors[0])->b = it * key->shape._20.b + t * next->shape._20.b;
            ((GXColor*)&verts->colors[0])->a = it * key->shape._20.a + t * next->shape._20.a;
        } else {
            verts->colors[0] = *(u32*)&key->shape._20;
        }
        if (*(u32*)&key->shape._24 != *(u32*)&next->shape._24) {
            ((GXColor*)&verts->colors[1])->r = it * key->shape._24.r + t * next->shape._24.r;
            ((GXColor*)&verts->colors[1])->g = it * key->shape._24.g + t * next->shape._24.g;
            ((GXColor*)&verts->colors[1])->b = it * key->shape._24.b + t * next->shape._24.b;
            ((GXColor*)&verts->colors[1])->a = it * key->shape._24.a + t * next->shape._24.a;
        } else {
            verts->colors[1] = *(u32*)&key->shape._24;
        }
        kr = key->rot;
        nr = next->rot;
    } else {
        verts->offsets[0] = key->offsets[0] * it + next->offsets[0] * t;
        verts->offsets[1] = key->offsets[1] * it + next->offsets[1] * t;
        verts->offsets[2] = key->offsets[2] * it + next->offsets[2] * t;
        verts->offsets[3] = key->offsets[3] * it + next->offsets[3] * t;
        verts->offsets[4] = key->offsets[4] * it + next->offsets[4] * t;
        verts->offsets[5] = key->offsets[5] * it + next->offsets[5] * t;
        verts->offsets[6] = key->offsets[6] * it + next->offsets[6] * t;
        verts->offsets[7] = key->offsets[7] * it + next->offsets[7] * t;
        stride = (key->_08_b2 | next->_08_b2) * 4;
        ka = (u8*)key;
        kb = (u8*)next;
        for (i = 0; i < 4; i++) {
            for (j = 3; j >= 0; j--) {
                if (((SpriteKey*)ka)->colors[0][j] != ((SpriteKey*)kb)->colors[0][j]) {
                    c[j] = it * ((SpriteKey*)ka)->colors[0][j] + t * ((SpriteKey*)kb)->colors[0][j];
                } else {
                    c[j] = ((SpriteKey*)ka)->colors[0][j];
                }
                if (key->blend == 2 && j <= 2) {
                    c[j] = c[3] * c[j] / 255;
                }
            }
            verts->colors[i] = *(u32*)c;
            ka += stride;
            kb += stride;
        }
        kr = key->rot;
        nr = next->rot;
    }
    if (key->_10 ^ next->_10) {
        px = key->_10 * it + next->_10 * t;
    } else if (key->_10) {
        px = key->_10;
    }
    if (key->_12 ^ next->_12) {
        py = key->_12 * it + next->_12 * t;
    } else if (key->_12) {
        py = key->_12;
    }
    PSMTXTrans(trans, -px, -py, 0.0f);
    PSMTXScale(scale, key->scaleX / 1024.0f * it + next->scaleX / 1024.0f * t, key->scaleY / 1024.0f * it + next->scaleY / 1024.0f * t, 1.0f);
    PSMTXConcat(scale, trans, scale);
    ret = 0;
    i = 3;
    while (i-- != 0) {
        a = it * (kr[i] / 4096.0f) + t * (nr[i] / 4096.0f);
        ret |= a != 0.0f;
        if (a != 0.0f) {
            a *= 6.2831855f;
            switch (i) {
            case 0:
                PSMTXRotRad(rot, 'X', a);
                break;
            case 1:
                PSMTXRotRad(rot, 'Y', a);
                break;
            case 2:
                PSMTXRotRad(rot, 'Z', a);
                break;
            }
            PSMTXConcat(rot, scale, scale);
        }
    }
    PSMTXTrans(trans, px, py, 0.0f);
    if (key->_08_b4) {
        trans[0][3] += pt->x;
        trans[1][3] += pt->y;
    } else {
        trans[0][3] += key->x * it + next->x * t;
        trans[1][3] += key->y * it + next->y * t;
    }
    trans[2][3] = z;
    PSMTXConcat(trans, scale, out);
    return ret;
}

// .text:0x8000A1E8 size:0x204
void interpolatePointsBezier_Vec2s(InterpPoint* out, BezierVec2s* p0, BezierVec2s* p1, BezierVec2s* p2, BezierVec2s* p3, u32 mode, f32 t) {
    InterpPoint pts[10];

    pts[0].x = p0->x;
    pts[0].y = p0->y;
    pts[3].x = p1->x;
    pts[3].y = p1->y;
    pts[6].x = p2->x;
    pts[6].y = p2->y;
    pts[9].x = p3->x;
    pts[9].y = p3->y;
    if (mode == 0) {
        interpolatePointsUnknown(3, pts, 1, 0);
        BezierInterpolate(out, &pts[0], &pts[1], &pts[2], &pts[3], t);
    } else if (mode == 1) {
        interpolatePointsUnknown(3, pts, 1, 0);
        interpolatePointsUnknown(6, pts, 0, 1);
        BezierInterpolate(out, &pts[3], &pts[4], &pts[5], &pts[6], t);
    } else {
        interpolatePointsUnknown(6, pts, 0, 1);
        BezierInterpolate(out, &pts[6], &pts[7], &pts[8], &pts[9], t);
    }
}

// .text:0x8000A0AC size:0x13C
void fn_8000A0AC(InterpPoint* out, BezierKey* a, BezierKey* b, f32 t) {
    InterpPoint pts[4];
    s16* handles[2];

    if (a->_04 == 2) {
        handles[0] = a->handles;
        handles[1] = b->handles;
    } else {
        handles[0] = a->handles;
        handles[1] = b->handles;
    }
    pts[0].x = a->x;
    pts[0].y = a->y;
    pts[1].x = handles[0][2];
    pts[1].y = handles[0][3];
    pts[2].x = handles[1][0];
    pts[2].y = handles[1][1];
    pts[3].x = b->x;
    pts[3].y = b->y;
    BezierInterpolate(out, &pts[0], &pts[1], &pts[2], &pts[3], t);
}
