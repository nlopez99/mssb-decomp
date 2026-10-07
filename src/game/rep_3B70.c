#include "game/rep_3B70.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/GX/GXFifo.h"
#include "Dolphin/mtx.h"

struct UnkQuad3B70 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*draw)(struct UnkQuad3B70* quad);
    /* 0x08 */ Mtx mtx;
    /* 0x38 */ f32 proj[7];
    /* 0x54 */ Vec verts[4];
    /* 0x84 */ u8* count;
}; // size: 0x88
typedef struct UnkQuad3B70 UnkQuad3B70;

typedef struct {
    /* 0x0 */ s32 size;
    /* 0x4 */ u32 alpha;
} UnkQuadParams3B70;

typedef struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ Mtx _40;
} UnkCamera3B70;

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ u8* _004;
    /* 0x008 */ u8 _008[0x440 - 0x8];
    /* 0x440 */ Vec _440;
} lbl_3_common_bss_35154;

extern u8 lbl_803CBBC0;

extern void gOz_GXSetTexture(s32, s32, s32);
extern void SetDisplayStateTexture(void*, s32, s32);
extern UnkCamera3B70* fn_80052734(s32);
extern void fn_80024390(UnkCamera3B70* camera, f32* proj, s32);
extern void fn_800340F4(Mtx m);
extern void fn_800A7D4C(s32, void*);

static u8 lbl_3_data_271A8[2] = { 0 };
static UnkQuad3B70 lbl_3_data_271AC[2][2] = {
    { { 0, fn_3_15C230 }, { 0, fn_3_15C230 } },
    { { 0, fn_3_15C230 }, { 0, fn_3_15C230 } },
};
static UnkQuadParams3B70 lbl_3_data_273CC = { 100000, 0x80 };
static UnkQuadParams3B70 lbl_3_data_273D4 = { 190000, 0x80 };

// .text:0x0015C3F8 size:0x1FC mapped:0x8079B48C
void fn_3_15C3F8(void) {
    Mtx m;
    UnkQuad3B70* quad;
    u8* count;
    f32 half;
    s32 state;
    s32 i;

    count = &lbl_3_data_271A8[lbl_803CBBC0];
    quad = &lbl_3_data_271AC[(*count)++][lbl_803CBBC0];
    quad->count = count;
    fn_80024390(fn_80052734(0), quad->proj, 0);
    PSMTXTrans(quad->mtx, lbl_3_common_bss_35154._440.x, lbl_3_common_bss_35154._440.y, lbl_3_common_bss_35154._440.z);
    PSMTXConcat(fn_80052734(0)->_40, quad->mtx, quad->mtx);

    if (g_GameLogic.bOD_framesInLiveBallScene >= 0) {
        state = 2;
    } else {
        state = g_Ball.framesSinceHit > 0;
    }
    if (state == 2) {
        half = scaleValue(lbl_3_data_273D4.size / 100000.0f, 0.5f);
    } else {
        half = scaleValue(lbl_3_data_273CC.size / 100000.0f, 0.5f);
    }

    fn_800340F4(m);
    quad->verts[0].x = quad->verts[0].y = quad->verts[1].y = quad->verts[3].x = -half;
    quad->verts[2].x = quad->verts[2].y = quad->verts[3].y = quad->verts[1].x = half;
    quad->verts[0].z = quad->verts[1].z = quad->verts[2].z = quad->verts[3].z = 0.0f;
    for (i = 0; i < 4; i++) {
        PSMTXMultVec(m, &quad->verts[i], &quad->verts[i]);
    }
    fn_800A7D4C(11, quad);
}

// .text:0x0015C230 size:0x1C8 mapped:0x8079B2C4
void fn_3_15C230(UnkQuad3B70* quad) {
    u32 color;
    s32 state;

    gOz_GXSetTexture(0, 0, 0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    SetDisplayStateTexture(lbl_3_common_bss_35154._004 + 0x2E4, 0, 0);
    GXSetProjectionv(quad->proj);
    GXLoadPosMtxImm(quad->mtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetCullMode(GX_CULL_NONE);

    if (g_GameLogic.bOD_framesInLiveBallScene >= 0) {
        state = 2;
    } else {
        state = g_Ball.framesSinceHit > 0;
    }
    if (state == 2) {
        color = lbl_3_data_273D4.alpha | 0xFFFFFF00;
    } else {
        color = lbl_3_data_273CC.alpha | 0xFFFFFF00;
    }

    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(quad->verts[0].x, quad->verts[0].y, quad->verts[0].z);
    GXColor1u32(color);
    GXTexCoord2u16(0, 0);
    GXPosition3f32(quad->verts[1].x, quad->verts[1].y, quad->verts[1].z);
    GXColor1u32(color);
    GXTexCoord2u16(1, 0);
    GXPosition3f32(quad->verts[2].x, quad->verts[2].y, quad->verts[2].z);
    GXColor1u32(color);
    GXTexCoord2u16(1, 1);
    GXPosition3f32(quad->verts[3].x, quad->verts[3].y, quad->verts[3].z);
    GXColor1u32(color);
    GXTexCoord2u16(0, 1);
    (*quad->count)--;
}
