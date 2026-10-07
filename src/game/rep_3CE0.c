#include "game/rep_3CE0.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/GX/GXFifo.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"
#include "stdarg.h"
#include "string.h"

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec base;
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ u32 _20;
    /* 0x24 */ u32 _24;
    /* 0x28 */ BOOL active;
} UnkMarker3CE0; // size: 0x2C

typedef struct {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*_04)(void*);
    /* 0x08 */ UnkMarker3CE0 _08[4];
    /* 0xB8 */ void* _B8;
    /* 0xBC */ u32 _BC;
    /* 0xC0 */ s32 _C0;
} UnkDraw3CE0; // size: 0xC4

typedef struct {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ u32 _8;
    /* 0xC */ u32 _C;
} UnkOffset3CE0; // size: 0x10

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u16 _12;
} UnkTask3CE0;

typedef struct {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ Vec pos;
    /* 0x040 */ u8 _040[0x252 - 0x40];
    /* 0x252 */ s8 _252;
} UnkPlayer3CE0;

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ struct {
        /* 0x000 */ u8 _000[0x344];
        /* 0x344 */ u8 _344;
    }* _004;
    /* 0x008 */ u8 _008[0x468 - 0x8];
    /* 0x468 */ u32 _468;
    /* 0x46C */ u8 _46C[0x470 - 0x46C];
    /* 0x470 */ u8 _470;
    /* 0x471 */ u8 _471;
    /* 0x472 */ u8 _472;
    /* 0x473 */ u8 _473[4];
    /* 0x477 */ u8 _477[0x479 - 0x477];
    /* 0x479 */ u8 _479;
} lbl_3_common_bss_35154;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ UnkPlayer3CE0* _2C50[4];
} lbl_8036E548;

extern u8 lbl_803CBBC0;
extern UnkTask3CE0* lbl_803CC1B8;

extern void gOz_GXSetTexture(s32, s32, s32);
extern void SetDisplayStateTexture(void*, s32, s32);
extern s32 fn_8005268C(void);
extern void fn_80052694(s32);
extern camera_803c639c_s* fn_80052734(s32);
extern void fn_800A7D4C(s32, void*);
extern void fn_800B0A14_removeQueue(void);
extern UnkTask3CE0* fn_800B0A5C_insertQueue(void (*)(void), s32);

static s32 lbl_3_data_27EC0[3][2] = {
    { 15000, 90000 },
    { 20000, 129999 },
    { 30000, 180000 },
};
static u8 lbl_3_data_27ED8[NUM_CHOOSABLE_CHARACTERS] = {
    1, 1, 2, 1, 1, 1, 1, 0, 0, 2, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 2, 2, 2, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
};
static struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ UnkOffset3CE0 _08[1];
    /* 0x18 */ UnkOffset3CE0 _18[2];
    /* 0x38 */ UnkOffset3CE0 _38[3];
    /* 0x68 */ s32 _68;
} lbl_3_data_27F10 = {
    64,
    16,
    { { 0, 0, 0xFFFF0080, 0xFFFFC818 } },
    { { -200000, 0, 0xFFFF0080, 0xFFFFC818 }, { 200000, 0, 0xFFFF0080, 0xFFFFC818 } },
    {
        { 0, 0, 0xFFFF0080, 0xFFFFC818 },
        { -300000, 0, 0xFFFF0080, 0xFFFFC818 },
        { 300000, 0, 0xFFFF0080, 0xFFFFC818 },
    },
    900000,
};
static UnkDraw3CE0 lbl_3_data_27F7C[2] = {
    { 0, fn_3_15FF28 },
    { 0, fn_3_15FF28 },
};
static Mtx44 lbl_3_data_28104 = {
    { 2.0f / 640.0f, 0.0f, 0.0f, -1.0f },
    { 0.0f, -2.0f / 448.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, -1.0f / 16777216.0f, -1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f },
};
static u8 lbl_3_data_28160[0x20] ATTRIBUTE_ALIGN(32) = {
    GX_QUADS, 0x00, 0x04, 0x00, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0x02, 0xFF, 0xFF, 0x03, 0xFF, 0xFF,
};
static f32 lbl_3_data_28180[4][3] ATTRIBUTE_ALIGN(32) = {
    { 0.0f, 0.0f, -16777215.0f },
    { 0.0f, 448.0f, -16777215.0f },
    { 640.0f, 448.0f, -16777215.0f },
    { 640.0f, 0.0f, -16777215.0f },
};
static f32 lbl_3_data_281C0[4][3] ATTRIBUTE_ALIGN(32) = {
    { 0.0f, 0.0f, -1.0f },
    { 0.0f, 448.0f, -1.0f },
    { 640.0f, 448.0f, -1.0f },
    { 640.0f, 0.0f, -1.0f },
};

// .text:0x0015FF28 size:0x650 mapped:0x8079EFBC
void fn_3_15FF28(void* arg) {
    UnkDraw3CE0* draw = arg;
    Mtx identity;
    Vec v;
    Vec dir;
    camera_803c639c_s* camera;
    s32 cameraIdx;
    s32 i;

    GXSetCullMode(GX_CULL_NONE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    PSMTXIdentity(identity);
    GXSetZCompLoc(GX_FALSE);
    fn_3_15F874(FALSE);
    cameraIdx = fn_8005268C();
    camera = fn_80052734(cameraIdx);
    fn_80052694(cameraIdx);
    gOz_GXSetTexture(0, 0, 0);
    if (lbl_3_common_bss_35154._472 != 0 && lbl_3_common_bss_35154._471 != 0) {
        GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
        GXLoadPosMtxImm(identity, GX_PNMTX0);
        SetDisplayStateTexture(NULL, 0, 0);
        for (i = 0; i < draw->_C0; i++) {
            if (draw->_08[i].active) {
                PSMTXMultVec(camera->view, &draw->_08[i].pos, &v);
                GXBegin(GX_QUADS, GX_VTXFMT0, 4);
                GXPosition3f32(v.x - draw->_08[i]._18, v.y, v.z);
                GXColor1u32(draw->_08[i]._20);
                GXTexCoord2u16(0, 0);
                GXPosition3f32(v.x + draw->_08[i]._18, v.y, v.z);
                GXColor1u32(draw->_08[i]._20);
                GXTexCoord2u16(1, 0);
                PSMTXMultVec(camera->view, &draw->_08[i].base, &v);
                dir.x = v.x;
                dir.y = 0.0f;
                dir.z = v.z;
                if (PSVECMag(&dir)) {
                    PSVECNormalize(&dir, &dir);
                    PSVECScale(&dir, draw->_08[i]._1C, &dir);
                } else {
                    dir.x = draw->_08[i]._1C;
                    dir.z = 0.0f;
                }
                GXPosition3f32(v.x - dir.z, v.y, v.z + dir.x);
                GXColor1u32(draw->_08[i]._24);
                GXTexCoord2u16(1, 1);
                GXPosition3f32(v.x + dir.z, v.y, v.z - dir.x);
                GXColor1u32(draw->_08[i]._24);
                GXTexCoord2u16(0, 1);
            }
        }
        GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
        GXLoadPosMtxImm(camera->view, GX_PNMTX0);
        SetDisplayStateTexture(draw->_B8, 0, 0);
        for (i = 0; i < draw->_C0; i++) {
            if (draw->_08[i].active) {
                GXBegin(GX_QUADS, GX_VTXFMT0, 4);
                GXPosition3f32(draw->_08[i].base.x - draw->_08[i]._1C, draw->_08[i].base.y,
                               draw->_08[i].base.z - draw->_08[i]._1C);
                GXColor1u32(draw->_08[i]._24);
                GXTexCoord2u16(0, 0);
                GXPosition3f32(draw->_08[i].base.x + draw->_08[i]._1C, draw->_08[i].base.y,
                               draw->_08[i].base.z - draw->_08[i]._1C);
                GXColor1u32(draw->_08[i]._24);
                GXTexCoord2u16(1, 0);
                GXPosition3f32(draw->_08[i].base.x + draw->_08[i]._1C, draw->_08[i].base.y,
                               draw->_08[i].base.z + draw->_08[i]._1C);
                GXColor1u32(draw->_08[i]._24);
                GXTexCoord2u16(1, 1);
                GXPosition3f32(draw->_08[i].base.x - draw->_08[i]._1C, draw->_08[i].base.y,
                               draw->_08[i].base.z + draw->_08[i]._1C);
                GXColor1u32(draw->_08[i]._24);
                GXTexCoord2u16(0, 1);
            }
        }
    }
    GXSetProjection(lbl_3_data_28104, GX_ORTHOGRAPHIC);
    GXLoadPosMtxImm(identity, GX_PNMTX0);
    SetDisplayStateTexture(NULL, 0, 0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(0.0f, 0.0f, -16777215.0f);
    GXColor1u32(draw->_BC);
    GXTexCoord2u16(0, 0);
    GXPosition3f32(640.0f, 0.0f, -16777215.0f);
    GXColor1u32(draw->_BC);
    GXTexCoord2u16(1, 0);
    GXPosition3f32(640.0f, 448.0f, -16777215.0f);
    GXColor1u32(draw->_BC);
    GXTexCoord2u16(1, 1);
    GXPosition3f32(0.0f, 448.0f, -16777215.0f);
    GXColor1u32(draw->_BC);
    GXTexCoord2u16(0, 1);
    fn_3_15F874(FALSE);
}

// .text:0x0015FB84 size:0x3A4 mapped:0x8079EC18
void fn_3_15FB84(s32 count, ...) {
    va_list args;
    s32 counts[4];
    f32 height;
    s32 i;
    s32 n;
    UnkMarker3CE0* marker;
    UnkOffset3CE0* offset;
    UnkPlayer3CE0* player;

    lbl_3_data_27F7C[lbl_803CBBC0]._C0 = count;
    height = -((f32)lbl_3_data_27F10._68 / 100000.0f);
    lbl_3_data_27F7C[lbl_803CBBC0]._B8 = &lbl_3_common_bss_35154._004->_344;
    lbl_3_data_27F7C[lbl_803CBBC0]._BC = lbl_3_common_bss_35154._468;
    memset(counts, 0, sizeof(counts));
    va_start(args, count);
    for (i = 0; i < count; i++) {
        counts[va_arg(args, s32)]++;
    }
    va_end(args);
    n = 0;
    marker = lbl_3_data_27F7C[lbl_803CBBC0]._08;
    for (i = 0; i < 4; i++) {
        player = lbl_8036E548._2C50[i];
        if (player != NULL) {
            switch (counts[i]) {
            case 0:
                break;
            case 1:
                offset = lbl_3_data_27F10._08;
                break;
            case 2:
                offset = lbl_3_data_27F10._18;
                break;
            case 3:
            default:
                offset = lbl_3_data_27F10._38;
                break;
            }
            while (counts[i]-- != 0) {
                marker->active = TRUE;
                n++;
                marker->pos.x = player->pos.x + (f32)offset->x / 100000.0f;
                marker->pos.y = height + (player->pos.y + (f32)offset->y / 100000.0f);
                marker->pos.z = player->pos.z;
                marker->base.x = player->pos.x;
                marker->base.y = player->pos.y;
                marker->base.z = player->pos.z;
                marker->_18 = (f32)lbl_3_data_27EC0[lbl_3_data_27ED8[player->_252]][0] / 100000.0f;
                marker->_1C = (f32)lbl_3_data_27EC0[lbl_3_data_27ED8[player->_252]][1] / 100000.0f;
                marker->_20 = offset->_8;
                marker->_24 = offset->_C;
                marker++;
                offset++;
            }
        }
    }
    for (; n < 4; n++) {
        marker->active = FALSE;
        marker++;
    }
    fn_800A7D4C(11, &lbl_3_data_27F7C[lbl_803CBBC0]);
}

// .text:0x0015FA58 size:0x12C mapped:0x8079EAEC
void fn_3_15FA58(s32 count, s32* ids) {
    UnkTask3CE0* task;

    task = fn_800B0A5C_insertQueue(fn_3_15F9C0, lbl_803CC1B8->_12);
    lbl_3_common_bss_35154._470 = 1;
    lbl_3_common_bss_35154._471 = 0;
    lbl_3_common_bss_35154._468 = 0;
    lbl_3_common_bss_35154._472 = 0;
    while (count--) {
        lbl_3_common_bss_35154._473[lbl_3_common_bss_35154._472++] = *ids++;
    }
    task->_10 = lbl_3_data_27F10._04;
}

// .text:0x0015F9C0 size:0x98 mapped:0x8079EA54
void fn_3_15F9C0(void) {
    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    lbl_803CC1B8->_10--;
    lbl_3_common_bss_35154._468 =
        lbl_3_data_27F10._00 * (lbl_3_data_27F10._04 - lbl_803CC1B8->_10) / lbl_3_data_27F10._04;
    if (lbl_803CC1B8->_10 == 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0015F9AC size:0x14 mapped:0x8079EA40
void fn_3_15F9AC(void) {
    lbl_3_common_bss_35154._471 = 1;
}

// .text:0x0015F998 size:0x14 mapped:0x8079EA2C
void fn_3_15F998(void) {
    lbl_3_common_bss_35154._470 = 0;
}

// .text:0x0015F874 size:0x124 mapped:0x8079E908
void fn_3_15F874(BOOL arg0) {
    Mtx mtx;

    GXSetProjection(lbl_3_data_28104, GX_ORTHOGRAPHIC);
    PSMTXIdentity(mtx);
    GXLoadPosMtxImm(mtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetColorUpdate(GX_FALSE);
    GXSetAlphaUpdate(GX_FALSE);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    gOz_GXSetTexture(4, 0, 0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA4, 0);
    if (arg0) {
        GXSetArray(GX_VA_POS, lbl_3_data_281C0, sizeof(lbl_3_data_281C0[0]));
    } else {
        GXSetArray(GX_VA_POS, lbl_3_data_28180, sizeof(lbl_3_data_28180[0]));
    }
    GXCallDisplayList(lbl_3_data_28160, sizeof(lbl_3_data_28160));
    GXSetColorUpdate(GX_TRUE);
    GXSetAlphaUpdate(GX_TRUE);
}
