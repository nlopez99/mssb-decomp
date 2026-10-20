#include "static/sub.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "Dolphin/mtx.h"
#include "Dolphin/mtxext.h"

extern void fn_800ACF14(void* data);
extern void* fn_800ACF34(u32 align, u32 size);

extern OSThread* GXGetCurrentGXThread(void);
extern void fn_800A7E00(void);

s32 lbl_803CBC60;

// 4x4 white RGB5A3 texture, the default for SetDisplayStateTexture
u16 lbl_800F76E0[16] ATTRIBUTE_ALIGN(32) = {
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
};

TextureDesc lbl_800F7700 = {
    lbl_800F76E0, NULL, 4, 4, GX_CLAMP, GX_CLAMP, GX_LINEAR, GX_LINEAR, 0.0f, 0, 0, 0, GX_TF_RGB5A3,
};

typedef struct {
    /* 0x0 */ s8 status; // -1 once completed, -2 when unlocked
    /* 0x1 */ u8 shown;
} StarMissionPair;

extern struct {
    struct {
        /* 0x00 */ u8 _00[0x09];
        /* 0x09 */ StarMissionPair inGame[10];
        /* 0x1D */ u8 _1D[0x34 - 0x1D];
    } characters[54];
    /* 0x0AF8 */ u8 _0AF8[0x44EF - 0xAF8];
    /* 0x44EF */ s8 _44EF;
    /* 0x44F0 */ s8 _44F0;
} starMissionCompletionTracker;

typedef struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2; // index into lbl_80109AE8
    /* 0x3 */ u8 _3[3];
} UnkCharEntry; // size: 0x6

extern UnkCharEntry lbl_800E8558[54];

typedef struct {
    /* 0x0 */ s16 type;
    /* 0x2 */ s16 target;
    /* 0x4 */ s16 flags;
    /* 0x6 */ u8 _6[4];
} UnkMissionDef; // size: 0xA

extern UnkMissionDef lbl_80109AE8[32][10];

extern struct {
    /* 0x0000 */ u8 _0000[0x46E4];
    /* 0x46E4 */ s32 _46E4;
} lbl_8034E9A0;

// .text:0x80024BB4 size:0x50
f32 LinearInterpolateToNewRange(f32 value, f32 prevMin, f32 prevMax, f32 nextMin, f32 nextMax)
{
    f32 outRange;
    f32 range = prevMax - prevMin;
    f32 t;

    if (0.0f == range) {
        t = 1.0f;
    } else {
        t = (value - prevMin) / range;
        t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t);
    }
    outRange = nextMax - nextMin;
    return outRange * t + nextMin;
}

// .text:0x80024B00 size:0xB4
int LERPToNewRange_Float(int value, int inMin, int inMax, int outMin, int outMax)
{
    f32 outRange;
    f32 range = inMax - inMin;
    f32 t;

    if (0.0f == range) {
        t = 1.0f;
    } else {
        t = (value - inMin) / range;
        t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t);
    }
    outRange = outMax - outMin;
    return outMin + (int)(outRange * t);
}

// .text:0x800249D8 size:0x128
int byteWiseMultiply(int value, int factors)
{
    return (int)((value & 0xFF) * ((factors & 0xFF) / 255.0f))
        | ((int)((value & 0xFF) * (((factors >> 8) & 0xFF) / 255.0f)) << 8)
        | ((int)((value & 0xFF) * (((factors >> 16) & 0xFF) / 255.0f)) << 16)
        | ((int)((value & 0xFF) * (((u32)factors >> 24) / 255.0f)) << 24);
}

// .text:0x80024974 size:0x64
int multBottomBits_asFloat(int color, int factor)
{
    f32 scale = (factor & 0xFF) / 255.0f;

    return (color & 0xFFFFFF00) | (int)((color & 0xFF) * scale);
}

// .text:0x80024840 size:0x134
int challengeStarRelatedInd(int character, int mission)
{
    s8 status;
    u8 def;
    s16 flags;

    def = lbl_800E8558[character]._2;
    status = starMissionCompletionTracker.characters[character].inGame[mission].status;

    if (status == -2) {
        return 1;
    }
    if (g_d_GameSettings.GameModeSelected == 5 && status == -1) {
        flags = lbl_80109AE8[def][mission].flags;
        if (flags & 1) {
            return 0;
        }
        if (flags & 2) {
            if (g_d_GameSettings.challengeDifficulty < 1) {
                return 0;
            }
        } else if (flags & 4) {
            if (g_d_GameSettings.challengeDifficulty < 2) {
                return 0;
            }
        } else if (flags & 8) {
            if (g_d_GameSettings.challengeDifficulty < 3) {
                return 0;
            }
        }
        if ((flags & 0x800) && starMissionCompletionTracker._44EF == 0 && starMissionCompletionTracker._44F0 == 0 && lbl_8034E9A0._46E4 != 9) {
            return 0;
        }
        return 1;
    }
    return 0;
}

// .text:0x800247E4 size:0x5C
s32 fn_800247E4(s32 x, s32 y, s32 width, s32 bytes)
{
    return bytes * ((y / 4) * 4 * width + (x / 4) * 4 * 4 + (y % 4) * 4 + x % 4);
}

// .text:0x800246D4 size:0x110
void fn_800246D4(int (*compare)(const void*, const void*), void* src, void* dst, int size, int count)
{
    int total = size * count;
    u8* buf = fn_800ACF34(0x20, total);
    u8* p = src;
    int n = 0;

    while (count-- != 0) {
        int hi = n;
        int lo = 0;
        int offset;

        while (lo != hi) {
            int mid = lo + (hi - lo) / 2;
            int c = compare(p, buf + mid * size);
            if (c == 0) {
                lo = mid;
                break;
            }
            if (c < 0) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        offset = lo * size;
        if (n - lo != 0) {
            memmove(buf + offset + size, buf + offset, (n - lo) * size);
        }
        memcpy(buf + offset, p, size);
        p += size;
        n++;
    }
    memcpy(dst, buf, total);
    fn_800ACF14(buf);
}

// .text:0x800245EC size:0xE8
void fn_800245EC(camera_803c639c_s* camera, Mtx view, Vec* points, f32* out, s32 count, s32 arg5)
{
    Vec v;
    Mtx44 m;

    PSMTX44Identity(m);
    PSMTXCopy(view, m);
    PSMTX44Concat(camera->proj, m, m);
    while (count-- != 0) {
        PSMTX44MultVec(m, points, &v);
        points++;
        out[0] = 0.5f * v.x + 0.5f;
        out[1] = 0.5f * v.y * -arg5 + 0.5f;
        out += 2;
    }
}

// .text:0x80024404 size:0x1E8
void SetDisplayStateTexture(TextureDesc* tex, GXTexMapID map, u32 tlutName)
{
    GXTexObj texObj;
    GXTlutObj tlutObj;
    GXTexWrapMode wrapS;
    GXTexWrapMode wrapT;

    if (OSGetCurrentThread() != GXGetCurrentGXThread()) {
        OSPanic("sub.c", 574, "gOz_GXSetTexture was called in thread that is not current GX thread.\n");
    }
    if (tex == NULL) {
        tex = &lbl_800F7700;
    }
    // A repeating wrap mode needs a power-of-two size: count the size's set bits
    wrapS = tex->wrapS;
    if (wrapS != GX_CLAMP) {
        u32 n = 0;
        u16 w = tex->width;
        while (w != 0) {
            n += w & 1;
            w >>= 1;
        }
        if (n > 1) {
            wrapS = GX_CLAMP;
        }
    }
    wrapT = tex->wrapT;
    if (wrapT != GX_CLAMP) {
        u16 h = tex->height;
        u32 n = 0;
        while (h != 0) {
            n += h & 1;
            h >>= 1;
        }
        if (n > 1) {
            wrapT = GX_CLAMP;
        }
    }
    if (tex->tlut != NULL) {
        GXInitTexObjCI(&texObj, tex->image, tex->width, tex->height, tex->format, wrapS, wrapT, tex->minLOD != tex->maxLOD, tlutName);
        GXInitTlutObj(&tlutObj, tex->tlut, tex->tlutFormat, tex->tlutCount);
        GXLoadTlut(&tlutObj, tlutName);
    } else {
        GXInitTexObj(&texObj, tex->image, tex->width, tex->height, tex->format, wrapS, wrapT, tex->minLOD != tex->maxLOD);
    }
    GXInitTexObjLOD(&texObj, tex->minFilter, tex->magFilter, tex->minLOD, tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXLoadTexObj(&texObj, map);
}

// .text:0x80024390 size:0x74
void fn_80024390(camera_803c639c_s* camera, f32* p, s32 type)
{
    s32 col = (type == GX_PERSPECTIVE) ? 2 : 3;

    p[0] = type;
    p[1] = camera->proj[0][0];
    p[2] = camera->proj[0][col];
    p[3] = camera->proj[1][1];
    p[4] = camera->proj[1][col];
    p[5] = camera->proj[2][2];
    p[6] = camera->proj[2][3];
}

// .text:0x80024184 size:0x20C
void gOz_GXSetTexture(GXTevMode mode, s32 frac, s32 useNormal)
{
    if (OSGetCurrentThread() != GXGetCurrentGXThread()) {
        OSPanic("sub.c", 674, "gOz_GXSetTexture was called in thread that is not current GX thread.\n");
    }
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    if (useNormal) {
        GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_NBT, GX_F32, 0);
    }
    switch (mode) {
    case GX_MODULATE:
    case GX_PASSCLR:
        GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        if (mode == GX_PASSCLR) {
            break;
        }
    case GX_REPLACE:
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        if (frac < 0) {
            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
        } else {
            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, frac);
        }
        break;
    }
    GXSetTevOrder(GX_TEVSTAGE0, mode == GX_PASSCLR ? GX_TEXCOORD_NULL : GX_TEXCOORD0, mode == GX_PASSCLR ? GX_TEXMAP_NULL : GX_TEXMAP0,
                  mode == GX_REPLACE ? GX_COLOR_NULL : GX_COLOR0A0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumChans(mode != GX_REPLACE);
    GXSetNumTexGens(mode != GX_PASSCLR);
    GXSetNumTevStages(1);
    GXSetTevOp(GX_TEVSTAGE0, mode);
}

// .text:0x80023F0C size:0x278
// Copies a rectangle of 4-bit, 8-bit or compressed texels between two textures, a tile at a time
int fn_80023F0C(TextureDesc* src, TextureDesc* dst, int srcX, int srcY, int w, int h, int dstX, int dstY)
{
    int srcStride;
    int dstStride;
    u8* from;
    u8* to;

    if (src->format != dst->format) {
        return 1;
    }
    if (src->tlut != NULL) {
        switch (src->format) {
        case GX_TF_C4:
            srcStride = (src->width + 7) / 8;
            dstStride = (dst->width + 7) / 8;
            w = (w + 7) / 8 + ((srcX & 7) != 0);
            srcX /= 8;
            h = (h + 7) / 8 + ((srcY & 7) != 0);
            srcY /= 8;
            dstX /= 8;
            dstY /= 8;
            break;
        case GX_TF_C8:
            srcStride = (src->width + 7) / 8;
            dstStride = (dst->width + 7) / 8;
            w = (w + 7) / 8 + ((srcX & 7) != 0);
            srcX /= 8;
            h = (h + 3) / 4 + ((srcY & 3) != 0);
            srcY /= 4;
            dstX /= 8;
            dstY /= 4;
            break;
        case GX_TF_C14X2:
            return 1;
        }
    } else {
        switch (src->format) {
        case GX_TF_CMPR:
            srcStride = (src->width + 7) / 8;
            dstStride = (dst->width + 7) / 8;
            w = (w + 7) / 8 + ((srcX & 7) != 0);
            srcX /= 8;
            h = (h + 7) / 8 + ((srcY & 7) != 0);
            srcY /= 8;
            dstX /= 8;
            dstY /= 8;
            break;
        default:
            return 1;
        }
    }
    from = (u8*)src->image + (srcX + srcStride * srcY) * 32;
    to = (u8*)dst->image + (dstX + dstStride * dstY) * 32;
    while (h != 0) {
        memcpy(to, from, w * 32);
        from += srcStride * 32;
        to += dstStride * 32;
        h--;
    }
    return 0;
}

// .text:0x80023EEC size:0x20
void fn_80023EEC(VecRing* ring, Vec* buf, int capacity)
{
    ring->buf = buf;
    ring->capacity = capacity;
    ring->count = 0;
    ring->head = 0;
    ring->tail = 0;
    ring->step = 0;
}

// .text:0x80023E48 size:0xA4
void fn_80023E48(VecRing* ring, Vec* v)
{
    ring->head = (ring->head + ring->step) % ring->capacity;
    if (ring->tail == ring->head) {
        ring->tail = (ring->tail + ring->step) % ring->capacity;
    }
    ring->step = 1;
    ring->buf[ring->head] = *v;
    ring->count += ring->count < ring->capacity;
}

// .text:0x80023DFC size:0x4C
BOOL fn_80023DFC(VecRing* ring, Vec* out)
{
    if (ring->count != 0) {
        ring->cur = ring->head;
        *out = ring->buf[ring->cur];
        return TRUE;
    }
    return FALSE;
}

// .text:0x80023D98 size:0x64
BOOL fn_80023D98(VecRing* ring, Vec* out)
{
    if (ring->cur == ring->tail) {
        return FALSE;
    }
    ring->cur = (ring->cur + ring->capacity - 1) % ring->capacity;
    *out = ring->buf[ring->cur];
    return TRUE;
}

// .text:0x80023D4C size:0x4C
BOOL fn_80023D4C(VecRing* ring, Vec* out)
{
    if (ring->count != 0) {
        ring->cur = ring->tail;
        *out = ring->buf[ring->cur];
        return TRUE;
    }
    return FALSE;
}

// .text:0x80023D44 size:0x8
void fn_80023D44(s32 progressive)
{
    lbl_803CBC60 = progressive;
}

// .text:0x80023D3C size:0x8
s32 fn_80023D3C(void)
{
    return lbl_803CBC60;
}

// .text:0x80023CF4 size:0x48
void fn_80023CF4(s32 progressive)
{
    if (progressive) {
        OSSetProgressiveMode(TRUE);
        fn_800A7E00();
    } else {
        OSSetProgressiveMode(FALSE);
    }
    lbl_803CBC60 = progressive;
}
