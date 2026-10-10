#include "challenge/rep_00B0.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/gd.h"
#include "Dolphin/mtx.h"
#include "Dolphin/os.h"
#include "string.h"

// An axis-aligned box: its low corner, then its high corner
typedef struct Box00B0 {
    /* 0x00 */ Vec min;
    /* 0x0C */ Vec max;
} Box00B0; // size: 0x18

// A ray along the view axis of mtx, and the nearest hit found along it
typedef struct Ray00B0 {
    /* 0x00 */ Mtx mtx;
    /* 0x30 */ u8 _30[0x60 - 0x30];
    /* 0x60 */ Vec normal;
    /* 0x6C */ f32 length;
    /* 0x70 */ f32 nearest;
    /* 0x74 */ u16 material;
} Ray00B0; // size: 0x78

// A collision mesh: runs of triangles or triangle strips, each after a header
typedef struct MeshHdr00B0 {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 strip;
    /* 0x2 */ u16 count;
} MeshHdr00B0;

typedef struct MeshVtx00B0 {
    /* 0x0 */ Vec pos;
    /* 0xC */ u16 material;
} MeshVtx00B0; // size: 0x10

typedef struct Draw00B0 {
    /* 0x0 */ s32 _0;
    /* 0x4 */ void (*_4)(void);
} Draw00B0; // size: 0x8

extern void fn_800A7D4C(s32 arg0, void* arg1);
extern void fn_800A1A70(GDCurrentDL* obj, void* start, u32 len);
extern void fn_800A1A88(void);
extern void fn_800A1B80(void);
extern void makeLookAtMatrix(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);

extern GDCurrentDL* lbl_803CC0F0;
extern u8 lbl_803CBBC0;

extern struct {
    /* 0x000 */ Mtx _000;
    /* 0x030 */ u8 _030[0x20C - 0x30];
    /* 0x20C */ GDCurrentDL _20C;
    /* 0x21C */ void* _21C;
    /* 0x220 */ u32 _220;
    /* 0x224 */ void** _224;
    /* 0x228 */ s16 _228;
    /* 0x22A */ s16 _22A;
    /* 0x22C */ s16 _22C;
    /* 0x22E */ s16 _22E;
    /* 0x230 */ u8 _230[0x239 - 0x230];
    /* 0x239 */ s8 _239;
} lbl_1_common_bss_472B4;

Vec lbl_1_data_200[2] = {
    { 0.21f, -3.0f, 17.26f },
    { 0.21f, 3.0f, 17.26f },
};
Vec lbl_1_data_218 = { 0.0f, 1.0f, 0.0f };
Vec lbl_1_data_224 = { 0.0f, 0.0f, 0.0f };
static GXColor lbl_1_data_240[20] ATTRIBUTE_ALIGN(32) = {
    { 0x00, 0xC0, 0x00, 0xFF }, { 0x00, 0x70, 0x00, 0xFF }, { 0x00, 0x00, 0xC0, 0xFF }, { 0x00, 0x00, 0x70, 0xFF },
    { 0xC0, 0x00, 0x00, 0xFF }, { 0x70, 0x00, 0x00, 0xFF }, { 0xC0, 0xC0, 0x00, 0xFF }, { 0x70, 0x70, 0x00, 0xFF },
    { 0x00, 0xC0, 0xC0, 0xFF }, { 0x00, 0x70, 0x70, 0xFF }, { 0xC0, 0x00, 0xC0, 0xFF }, { 0x70, 0x00, 0x70, 0xFF },
    { 0xFF, 0x00, 0x00, 0x40 }, { 0x00, 0xFF, 0x00, 0x40 }, { 0xFF, 0xFF, 0x00, 0x40 }, { 0x00, 0x00, 0xFF, 0x40 },
    { 0xFF, 0x00, 0xFF, 0x40 }, { 0x00, 0xFF, 0xFF, 0x40 }, { 0xC0, 0xC0, 0x20, 0xFF }, { 0xFF, 0xFF, 0xFF, 0xFF },
};
static GXColor lbl_1_data_290 = { 0x3A, 0x6E, 0xA5, 0xFF };
static GXColor lbl_1_data_294 = { 0x00, 0x00, 0x00, 0x00 };
Draw00B0 lbl_1_data_298[2] = {
    { 0, fn_1_19AC },
    { 0, fn_1_19AC },
};

// The eight corners of the selected box
Vec lbl_1_bss_60[8];

static inline void GDOverflowCheck00B0(u32 size) {
    if (lbl_803CC0F0->pDisplayListData + size > lbl_803CC0F0->end) {
        fn_800A1B80();
    }
}

static inline void GDWrite00B0(u32 data) {
    *lbl_803CC0F0->pDisplayListData++ = data;
}

static inline void GDWrite_u8(u8 data) {
    GDOverflowCheck00B0(1);
    GDWrite00B0(data);
}

static inline void GDWrite_u16(u16 data) {
    GDOverflowCheck00B0(2);
    GDWrite00B0((data >> 8) & 0xFF);
    GDWrite00B0((data >> 0) & 0xFF);
}

static inline void GDWrite_u32(u32 data) {
    GDOverflowCheck00B0(4);
    GDWrite00B0((data >> 24) & 0xFF);
    GDWrite00B0((data >> 16) & 0xFF);
    GDWrite00B0((data >> 8) & 0xFF);
    GDWrite00B0((data >> 0) & 0xFF);
}

static inline void GDWrite_f32(f32 data) {
    union {
        f32 f;
        u32 u;
    } fid;

    fid.f = data;
    GDWrite_u32(fid.u);
}

static inline void GDBegin(GXPrimitive type, GXVtxFmt vtxfmt, u16 nverts) {
    GDWrite_u8(type | (vtxfmt & 7));
    GDWrite_u16(nverts);
}

static inline void GDPosition3f32(f32 x, f32 y, f32 z) {
    GDWrite_f32(x);
    GDWrite_f32(y);
    GDWrite_f32(z);
}

static inline void GDColor1x8(u8 index) {
    GDWrite_u8(index);
}

// A material's colour index: two shades per material, the dark one when bit 7 is set
static inline void GDColorMaterial00B0(u32 material) {
    GDColor1x8((material >> 7) + ((material & 0x7F) - 1) * 2);
}

// .text:0x00004DD8 size:0xC0
// Relocates the collision table: its entries are offsets from the file's start
void fn_1_4DD8(u16* data) {
    s32 i;
    u32* table;

    lbl_1_common_bss_472B4._228 = data[0];
    lbl_1_common_bss_472B4._224 = (void**)(data + 2);
    table = (u32*)lbl_1_common_bss_472B4._224;
    for (i = lbl_1_common_bss_472B4._228; i >= 0; i--) {
        *table++ += (u32)data;
    }
}

// .text:0x00004A24 size:0x3B4
void fn_1_4A24(Ray00B0* ray, void* mesh) {
    Vec v[3];
    Vec e[3];
    f32 t;
    u32 count;
    u32 flip;
    u32 ok;
    MeshVtx00B0* vtx;
    u8 strip;

    vtx = mesh;
    while (TRUE) {
        count = ((MeshHdr00B0*)vtx)->count;
        if (count == 0) {
            break;
        }
        strip = ((MeshHdr00B0*)vtx)->strip;
        vtx = (MeshVtx00B0*)((MeshHdr00B0*)vtx + 1);
        if (!strip) {
            do {
                PSMTXMultVec(ray->mtx, &vtx[0].pos, &v[0]);
                PSMTXMultVec(ray->mtx, &vtx[1].pos, &v[1]);
                PSMTXMultVec(ray->mtx, &vtx[2].pos, &v[2]);
                ok = v[0].x * v[1].y - v[1].x * v[0].y >= 0.0f;
                ok &= v[1].x * v[2].y - v[2].x * v[1].y >= 0.0f;
                ok &= v[2].x * v[0].y - v[0].x * v[2].y >= 0.0f;
                if (ok)
                {
                    PSVECSubtract(&v[1], &v[0], &e[0]);
                    PSVECSubtract(&v[2], &v[1], &e[1]);
                    PSVECCrossProduct(&e[0], &e[1], &e[2]);
                    t = -PSVECDotProduct(&e[2], &v[0]) / e[2].z;
                    if (t >= 0.0f && ray->nearest > t) {
                        ray->nearest = t;
                        ray->material = vtx[2].material;
                        ray->normal = e[2];
                    }
                }
                vtx += 3;
            } while (--count);
        } else {
            flip = 0;
            PSMTXMultVec(ray->mtx, &vtx[0].pos, &v[0]);
            PSMTXMultVec(ray->mtx, &vtx[1].pos, &v[1]);
            vtx += 2;
            do {
                PSMTXMultVec(ray->mtx, &vtx->pos, &v[2]);
                e[0].x = v[0].x * v[1].y - v[1].x * v[0].y;
                e[0].y = v[1].x * v[2].y - v[2].x * v[1].y;
                e[0].z = v[2].x * v[0].y - v[0].x * v[2].y;
                ok = flip ? (e[0].x <= 0.0f) & (e[0].y <= 0.0f) & (e[0].z <= 0.0f)
                          : (e[0].x >= 0.0f) & (e[0].y >= 0.0f) & (e[0].z >= 0.0f);
                if (ok)
                {
                    PSVECSubtract(&v[1], &v[0], &e[0]);
                    PSVECSubtract(&v[2], &v[1], &e[1]);
                    PSVECCrossProduct(&e[0], &e[1], &e[2]);
                    t = -PSVECDotProduct(&e[2], &v[0]) / e[2].z;
                    if (t >= 0.0f && ray->nearest > t) {
                        ray->nearest = t;
                        ray->material = vtx->material;
                        if (!flip) {
                            ray->normal = e[2];
                        } else {
                            ray->normal.x = -e[2].x;
                            ray->normal.y = -e[2].y;
                            ray->normal.z = -e[2].z;
                        }
                    }
                }
                flip ^= 1;
                vtx++;
                v[0] = v[1];
                v[1] = v[2];
            } while (--count);
        }
    }
}

// .text:0x00004728 size:0x2FC
u32 fn_1_4728(Vec* line, Vec* out) {
    u8 hit[256];
    Vec d[4];
    Ray00B0 ray;
    Mtx inv;
    s32 k;
    void** list;
    s32 n;
    u32 miss;
    f32 dist;
    Box00B0* box;
    u8* p;

    box = *lbl_1_common_bss_472B4._224;
    memset(hit, 1, lbl_1_common_bss_472B4._228);
    n = lbl_1_common_bss_472B4._228;
    p = hit;
    miss = 1;
    do {
        PSVECSubtract(&line[0], &box->min, &d[0]);
        PSVECSubtract(&box->max, &line[0], &d[1]);
        PSVECSubtract(&line[1], &box->min, &d[2]);
        PSVECSubtract(&box->max, &line[1], &d[3]);
        if (!(((*(u32*)&d[0].x & *(u32*)&d[2].x) | (*(u32*)&d[1].x & *(u32*)&d[3].x)) & 0x80000000) &&
            !(((*(u32*)&d[0].y & *(u32*)&d[2].y) | (*(u32*)&d[1].y & *(u32*)&d[3].y)) & 0x80000000) &&
            !(((*(u32*)&d[0].z & *(u32*)&d[2].z) | (*(u32*)&d[1].z & *(u32*)&d[3].z)) & 0x80000000))
        {
            *p = 0;
            miss = 0;
        }
        n--;
        p++;
        box++;
    } while (n != 0);
    if (miss) {
        return 0;
    }
    makeLookAtMatrix(ray.mtx, &line[0], &lbl_1_data_218, &line[1]);
    dist = dolsqrtf2(PSVECSquareDistance(&line[1], &line[0]));
    ray.length = dist;
    p = hit;
    k = lbl_1_common_bss_472B4._228;
    list = lbl_1_common_bss_472B4._224 + 1;
    ray.nearest = dist;
    ray.material = 0;
    do {
        if (*p++ == 0) {
            fn_1_4A24(&ray, *list);
        }
        k--;
        list++;
    } while (k != 0);
    if (ray.material) {
        PSMTXInverse(ray.mtx, inv);
        lbl_1_data_224.z = -ray.nearest;
        PSMTXMultVec(inv, &lbl_1_data_224, &out[0]);
        PSMTXTranspose(ray.mtx, inv);
        PSMTXMultVec(inv, &ray.normal, &out[1]);
        PSVECNormalize(&out[1], &out[1]);
        return ray.material;
    }
    return 0;
}

// .text:0x00004290 size:0x498
void fn_1_4290(Vec* line) {
    GDBegin(GX_LINES, GX_VTXFMT0, 2);
    GDPosition3f32(line[0].x, line[0].y, line[0].z);
    GDColor1x8(19);
    GDPosition3f32(line[1].x, line[1].y, line[1].z);
    GDColor1x8(20);
}

// .text:0x00004074 size:0x21C
void fn_1_4074(Vec* pos) {
    GDPosition3f32(pos->x, pos->y, pos->z);
    GDColor1x8(18);
}

// .text:0x00003E38 size:0x23C
void fn_1_3E38(Vec* pos, u32 material) {
    GDPosition3f32(pos->x, pos->y, pos->z);
    GDColorMaterial00B0(material);
}

// .text:0x000025BC size:0x187C
// n, m and nverts are reused (n for the strip flag, nverts for each strip vertex's
// material): only then does MWCC allocate them as in the target
void fn_1_25BC(void* mesh) {
    u32 count;
    u32 n;
    u32 nverts;
    u32 m;
    u32 mat;
    MeshVtx00B0* vtx;
    MeshVtx00B0* first;
    u8* p;

    p = mesh;
    do {
        count = ((MeshHdr00B0*)p)->count;
        n = ((MeshHdr00B0*)p)->strip;
        if (!n) {
            vtx = (MeshVtx00B0*)(p + 4);
            n = count * 3;
            GDBegin(GX_TRIANGLES, GX_VTXFMT0, n);
            for (; n != 0; n--) {
                GDPosition3f32(vtx->pos.x, vtx->pos.y, vtx->pos.z);
                m = ((u32)vtx->material >> 7) + (((u32)vtx->material & 0x7F) - 1) * 2;
                GDColor1x8(m);
                vtx++;
            }
            n = count;
            vtx = (MeshVtx00B0*)(p + 4);
            for (; n != 0; n--) {
                GDBegin(GX_LINESTRIP, GX_VTXFMT0, 4);
                first = vtx;
                fn_1_4074(&vtx++->pos);
                fn_1_4074(&vtx++->pos);
                fn_1_4074(&vtx++->pos);
                fn_1_4074(&first->pos);
            }
        } else {
            nverts = 0;
            vtx = (MeshVtx00B0*)(p + 4);
            mat = vtx->material;
            for (n = count + 2; n != 0; vtx++, n--) {
                nverts++;
                if (mat != vtx->material) {
                    mat = vtx->material;
                    nverts += 2;
                }
            }
            m = ((MeshVtx00B0*)(p + 4))->material;
            vtx = (MeshVtx00B0*)(p + 4);
            GDBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, nverts);
            for (n = count + 2; n != 0; n--) {
                nverts = vtx->material;
                if (m != nverts) {
                    m = nverts;
                    fn_1_3E38(&vtx[-2].pos, nverts);
                    fn_1_3E38(&vtx[-1].pos, nverts);
                }
                fn_1_3E38(&vtx->pos, nverts);
                vtx++;
            }
            n = count + 2;
            first = (MeshVtx00B0*)(p + 4);
            GDBegin(GX_LINESTRIP, GX_VTXFMT0, n);
            for (; n != 0; n--) {
                fn_1_4074(&first++->pos);
            }
            n = (count + 3) >> 1;
            first = (MeshVtx00B0*)(p + 4);
            GDBegin(GX_LINESTRIP, GX_VTXFMT0, n);
            for (; n != 0; n--) {
                fn_1_4074(&first->pos);
                first += 2;
            }
            n = (count + 2) >> 1;
            first = (MeshVtx00B0*)(p + 4) + 1;
            GDBegin(GX_LINESTRIP, GX_VTXFMT0, n);
            for (; n != 0; n--) {
                fn_1_4074(&first->pos);
                first += 2;
            }
        }
        p = (u8*)vtx;
    } while (*(u32*)p != 0);
}

// .text:0x00001DBC size:0x800
void fn_1_1DBC(s32 a, s32 b, s32 c, s32 d, s32 color) {
    GDPosition3f32(lbl_1_bss_60[a].x, lbl_1_bss_60[a].y, lbl_1_bss_60[a].z);
    GDColor1x8(color);
    GDPosition3f32(lbl_1_bss_60[b].x, lbl_1_bss_60[b].y, lbl_1_bss_60[b].z);
    GDColor1x8(color);
    GDPosition3f32(lbl_1_bss_60[c].x, lbl_1_bss_60[c].y, lbl_1_bss_60[c].z);
    GDColor1x8(color);
    GDPosition3f32(lbl_1_bss_60[d].x, lbl_1_bss_60[d].y, lbl_1_bss_60[d].z);
    GDColor1x8(color);
}

// .text:0x00001BF8 size:0x1C4
void fn_1_1BF8(Box00B0* boxes, s32 idx) {
    Box00B0* box = &boxes[idx];

    lbl_1_bss_60[0].x = box->min.x;
    lbl_1_bss_60[0].y = box->min.y;
    lbl_1_bss_60[0].z = box->max.z;
    lbl_1_bss_60[1].x = box->max.x;
    lbl_1_bss_60[1].y = box->min.y;
    lbl_1_bss_60[1].z = box->max.z;
    lbl_1_bss_60[2].x = box->max.x;
    lbl_1_bss_60[2].y = box->min.y;
    lbl_1_bss_60[2].z = box->min.z;
    lbl_1_bss_60[3].x = box->min.x;
    lbl_1_bss_60[3].y = box->min.y;
    lbl_1_bss_60[3].z = box->min.z;
    lbl_1_bss_60[4].x = box->min.x;
    lbl_1_bss_60[4].y = box->max.y;
    lbl_1_bss_60[4].z = box->max.z;
    lbl_1_bss_60[5].x = box->max.x;
    lbl_1_bss_60[5].y = box->max.y;
    lbl_1_bss_60[5].z = box->max.z;
    lbl_1_bss_60[6].x = box->max.x;
    lbl_1_bss_60[6].y = box->max.y;
    lbl_1_bss_60[6].z = box->min.z;
    lbl_1_bss_60[7].x = box->min.x;
    lbl_1_bss_60[7].y = box->max.y;
    lbl_1_bss_60[7].z = box->min.z;
    GDBegin(GX_QUADS, GX_VTXFMT0, 24);
    fn_1_1DBC(7, 6, 2, 3, 12);
    fn_1_1DBC(5, 4, 0, 1, 13);
    fn_1_1DBC(3, 2, 1, 0, 14);
    fn_1_1DBC(4, 5, 6, 7, 15);
    fn_1_1DBC(4, 7, 3, 0, 16);
    fn_1_1DBC(6, 5, 1, 2, 17);
}

// .text:0x000019AC size:0x24C
void fn_1_19AC(void) {
    Vec line[2];
    u32 size;
    u32 i;
    void** list;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetCopyClear(lbl_1_data_294, 0xFFFFFF);
    GXSetCullMode(GX_CULL_FRONT);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetArray(GX_VA_CLR0, lbl_1_data_240, sizeof(GXColor));
    GXSetLineWidth(18, GX_TO_ONE);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXLoadPosMtxImm(lbl_1_common_bss_472B4._000, GX_PNMTX0);
    list = lbl_1_common_bss_472B4._224 + 1;
    fn_800A1A70(&lbl_1_common_bss_472B4._20C, lbl_1_common_bss_472B4._21C, 0x80000);
    lbl_803CC0F0 = &lbl_1_common_bss_472B4._20C;
    if (lbl_1_common_bss_472B4._22E < 0) {
        for (i = 0; i < lbl_1_common_bss_472B4._228; i++) {
            fn_1_25BC(*list++);
        }
        fn_1_4290(lbl_1_data_200);
    } else {
        fn_1_25BC(list[lbl_1_common_bss_472B4._22E]);
        fn_1_4290(lbl_1_data_200);
        if (lbl_1_common_bss_472B4._239) {
            fn_1_1BF8(*lbl_1_common_bss_472B4._224, lbl_1_common_bss_472B4._22E);
        }
    }
    if (fn_1_4728(lbl_1_data_200, line)) {
        PSVECAdd(&line[0], &line[1], &line[1]);
        fn_1_4290(line);
    }
    fn_800A1A88();
    size = lbl_1_common_bss_472B4._20C.pDisplayListData - lbl_1_common_bss_472B4._20C.begin;
    DCFlushRangeNoSync(lbl_1_common_bss_472B4._21C, size);
    lbl_1_common_bss_472B4._220 = size;
    if (size > 0x80000) {
        OSReport("Gd Buffer overflow:%d\n", size);
        while (TRUE) {}
    }
    GXCallDisplayList(lbl_1_common_bss_472B4._21C, size);
}

// .text:0x0000196C size:0x40
void fn_1_196C(void) {
    fn_800A7D4C(0, &lbl_1_data_298[lbl_803CBBC0]);
}
