#include "static/sprt.h"
#include "Dolphin/gd.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "string.h"

typedef struct SprtVtx {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u32 color;
    /* 0x10 */ s16 st[2];
} SprtVtx; // size: 0x14

typedef struct SprtTex {
    /* 0x00 */ void* image;
    /* 0x04 */ void* tlut;
    /* 0x08 */ u16 height;
    /* 0x0A */ u16 width;
    /* 0x0C */ u8 wrapS;
    /* 0x0D */ u8 wrapT;
    /* 0x0E */ u8 minFilter;
    /* 0x0F */ u8 magFilter;
    /* 0x10 */ f32 lodBias;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 minLod;
    /* 0x16 */ u8 maxLod;
    /* 0x17 */ u8 format;
    /* 0x18 */ u16 tlutCount;
    /* 0x1A */ u8 tlutFormat;
} SprtTex;

typedef struct SprtProj {
    /* 0x00 */ f32 type;
    /* 0x04 */ f32 p[6];
} SprtProj; // size: 0x1C

typedef struct SprtState {
    /* 0x00 */ Mtx view;
    /* 0x30 */ SprtProj proj;
    /* 0x4C */ SprtTex* tex[7];
    /* 0x68 */ u16 _68[8];
    /* 0x78 */ u32 zmode;
    /* 0x7C */ u32 _7C;
    /* 0x80 */ s32 _80;
    /* 0x84 */ u16 _84;
    /* 0x86 */ u16 width;
    /* 0x88 */ u16 height;
    /* 0x8A */ u8 _8A;
    /* 0x8B */ u8 _8B;
    /* 0x8C */ u8 _8C;
    /* 0x8D */ u8 _8D;
    /* 0x8E */ u8 _8E[0x90 - 0x8E];
} SprtState; // size: 0x90

typedef struct SprtLayer {
    /* 0x00 */ s32 mode;
    /* 0x04 */ void (*draw)(struct SprtLayer* layer);
    /* 0x08 */ GDCurrentDL* dl;
} SprtLayer; // size: 0xC

extern GDCurrentDL* lbl_803CC0F0;
extern u32 lbl_802FE8B8[24];
extern SprtProj lbl_802FE918[];
extern SprtState lbl_802FEBF8[];
extern SprtState lbl_802FF978[];
extern GDCurrentDL lbl_803006F8[2][24];
extern SprtVtx lbl_803C8A24[];

extern void fn_800A1BB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800A1A70(GDCurrentDL* dl, void* start, u32 length);
extern void fn_800A7D4C(s32 slot, void* node);
extern void fn_800A1E3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_800A1F40(s32 map, s32 wrapS, s32 wrapT, s32 minFilter, s32 magFilter, f32 minLod, f32 maxLod, f32 lodBias,
                        u8 biasClamp, u8 edgeLod, s32 aniso);
extern void fn_800A2194(s32 map, u16 width, u16 height, s32 format);
extern void fn_800A2294(s32 map, void* image);
extern void fn_800A237C(s32 map, u32 tmem, s32 format);
extern void fn_800A246C(s32 coord, u16 sScale, u8 sBias, u8 sWrap, u16 tScale, u8 tBias, u8 tWrap);
extern void fn_800A26FC(void* tlut, u32 tmem);

SprtLayer lbl_80111340[2][24] = {
    { { 0, fn_800B2240, NULL } },
    { { 0, fn_800B2240, NULL } },
};
u32 lbl_80111580[8] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
s16 lbl_801115A0[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 0 } };
Mtx44 lbl_801115B0 = {
    { 0.003125f, 0.0f, 0.0f, -1.0f },
    { 0.0f, -0.004464286f, 0.0f, 1.0f },
    { 0.0f, 0.0f, -0.000000059604645f, -1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f },
};
SprtVtx lbl_801115F0[4] = {
    { { 0.0f, 0.0f, -16777215.0f }, 0, { 0, 0 } },
    { { 0.0f, 448.0f, -16777215.0f }, 0, { 0, 1 } },
    { { 640.0f, 448.0f, -16777215.0f }, 0, { 1, 1 } },
    { { 640.0f, 0.0f, -16777215.0f }, 0, { 1, 0 } },
};

u8 lbl_803CBB18[8] = { 0x61, 0x28, 0x3B, 0xF0, 0x40 };
u8 lbl_803CBB20[8] = { 0x61, 0x28, 0x3B, 0xF0, 0x41 };
s32 lbl_803CBB28 = 640;
s32 lbl_803CBB2C = 480;
s32 lbl_803CBB30 = 1;
SprtState* lbl_803CBB34 = lbl_802FEBF8;
SprtState* lbl_803CBB38 = lbl_802FF978;
s32 lbl_803CBB3C = 0x400;
SprtProj* lbl_803CBB40 = lbl_802FE918;

GDCurrentDL* lbl_803CC1E4;
s32 lbl_803CC1E0;
u32* lbl_803CC1D8[2];
s32 lbl_803CC1D4;
s32 lbl_803CC1D0;
s32 lbl_803CC1CC;
s32 lbl_803CC1C8;
s32 lbl_803CC1C4;
GDCurrentDL* lbl_803CC1C0;

static inline void SetProjection(SprtProj* proj, Mtx44 m, s32 type) {
    s32 col = (type == GX_ORTHOGRAPHIC) + 2;

    proj->type = type;
    proj->p[0] = m[0][0];
    proj->p[1] = m[0][col];
    proj->p[2] = m[1][1];
    proj->p[3] = m[1][col];
    proj->p[4] = m[2][2];
    proj->p[5] = m[2][3];
}

static inline void ReserveSprite(s32 size) {
    size -= lbl_803CC1C0->end - lbl_803CC1C0->pDisplayListData;
    if (size > 0) {
        if (AllocateSprite(lbl_803CC1D4, size) > 0) {
            OSPanic("sprt.c", 415, "SPRITE BUFFER OVERFLOW\n");
        }
    }
}

static inline s32 UpdateProjection(void) {
    if (memcmp(&lbl_803CBB38->proj, &lbl_803CBB34->proj, sizeof(SprtProj)) != 0) {
        memcpy(&lbl_803CBB38->proj, &lbl_803CBB34->proj, sizeof(SprtProj));
        ReserveSprite(0x21);
        lbl_803CC1C0->pDisplayListData[0] = 0x10;
        *(u16*)(lbl_803CC1C0->pDisplayListData + 1) = 6;
        *(u16*)(lbl_803CC1C0->pDisplayListData + 3) = 0x1020;
        lbl_803CC1C0->pDisplayListData += 5;
        *(u32*)lbl_803CC1C0->pDisplayListData = *(u32*)&lbl_803CBB34->proj.p[0];
        lbl_803CC1C0->pDisplayListData += 4;
        *(u32*)lbl_803CC1C0->pDisplayListData = *(u32*)&lbl_803CBB34->proj.p[1];
        lbl_803CC1C0->pDisplayListData += 4;
        *(u32*)lbl_803CC1C0->pDisplayListData = *(u32*)&lbl_803CBB34->proj.p[2];
        lbl_803CC1C0->pDisplayListData += 4;
        *(u32*)lbl_803CC1C0->pDisplayListData = *(u32*)&lbl_803CBB34->proj.p[3];
        lbl_803CC1C0->pDisplayListData += 4;
        *(u32*)lbl_803CC1C0->pDisplayListData = *(u32*)&lbl_803CBB34->proj.p[4];
        lbl_803CC1C0->pDisplayListData += 4;
        *(u32*)lbl_803CC1C0->pDisplayListData = *(u32*)&lbl_803CBB34->proj.p[5];
        lbl_803CC1C0->pDisplayListData += 4;
        *(u32*)lbl_803CC1C0->pDisplayListData = lbl_803CBB34->proj.type;
        lbl_803CC1C0->pDisplayListData += 4;
        return 1;
    }
    return 0;
}

static inline s32 UpdateViewMtx(void) {
    if (memcmp(lbl_803CBB38->view, lbl_803CBB34->view, sizeof(Mtx)) != 0) {
        PSMTXCopy(lbl_803CBB34->view, lbl_803CBB38->view);
        ReserveSprite(0x35);
        lbl_803CC1C0->pDisplayListData[0] = 0x10;
        *(u16*)(lbl_803CC1C0->pDisplayListData + 1) = 11;
        *(u16*)(lbl_803CC1C0->pDisplayListData + 3) = 0;
        lbl_803CC1C0->pDisplayListData += 5;
        memcpy(lbl_803CC1C0->pDisplayListData, lbl_803CBB34->view, sizeof(Mtx));
        lbl_803CC1C0->pDisplayListData += sizeof(Mtx);
        return 1;
    }
    return 0;
}

static inline s32 UpdateBlendMode(void) {
    if (lbl_803CBB38->_8A != lbl_803CBB34->_8A) {
        lbl_803CBB38->_8A = lbl_803CBB34->_8A;
        ReserveSprite(10);
        lbl_803CC0F0 = lbl_803CC1C0;
        switch (lbl_803CBB34->_8A) {
        case 0:
            fn_800A1BB0(GX_BM_NONE, GX_BL_ZERO, GX_BL_ZERO, GX_LO_CLEAR);
            break;
        case 1:
            fn_800A1BB0(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
            break;
        case 2:
            fn_800A1BB0(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_DSTALPHA, GX_LO_CLEAR);
            break;
        case 3:
            fn_800A1BB0(GX_BM_SUBTRACT, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
            break;
        }
        return 1;
    }
    return 0;
}

static inline s32 UpdateAlphaCompare(void) {
    s32 mode = 0;

    if (lbl_803CBB34->_8C != 0) {
        mode = 2;
    }
    if (lbl_803CBB38->_8D == mode) {
        return 0;
    }
    lbl_803CBB38->_8D = mode;
    if (mode != 0) {
        if (lbl_803CBB38->zmode != 0x40000013) {
            lbl_803CBB38->zmode = 0x40000013;
            ReserveSprite(5);
            lbl_803CC1C0->pDisplayListData[0] = 0x61;
            *(u32*)(lbl_803CC1C0->pDisplayListData + 1) = 0x40000013;
            lbl_803CC1C0->pDisplayListData += 5;
        }
        ReserveSprite(5);
        lbl_803CC0F0 = lbl_803CC1C0;
        fn_800A1E3C(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
        lbl_803CC0F0 = NULL;
    } else {
        if (lbl_803CBB38->zmode != lbl_803CBB34->zmode) {
            lbl_803CBB38->zmode = lbl_803CBB34->zmode;
            ReserveSprite(5);
            lbl_803CC1C0->pDisplayListData[0] = 0x61;
            *(u32*)(lbl_803CC1C0->pDisplayListData + 1) = lbl_803CBB34->zmode;
            lbl_803CC1C0->pDisplayListData += 5;
        }
        ReserveSprite(5);
        lbl_803CC0F0 = lbl_803CC1C0;
        fn_800A1E3C(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
        lbl_803CC0F0 = NULL;
    }
    return 1;
}

static inline s32 UpdateZMode(void) {
    if (lbl_803CBB38->zmode != lbl_803CBB34->zmode) {
        lbl_803CBB38->zmode = lbl_803CBB34->zmode;
        ReserveSprite(5);
        lbl_803CC1C0->pDisplayListData[0] = 0x61;
        *(u32*)(lbl_803CC1C0->pDisplayListData + 1) = lbl_803CBB38->zmode;
        lbl_803CC1C0->pDisplayListData += 5;
        return 1;
    }
    return 0;
}

// .text:0x800B2854 size:0x274
void fn_800B2854(u8* buf, s32 size, Mtx44 proj, s32 projType, s32 count, u32* handles, u32* sizes) {
    s32 half;
    u8* front;
    u8* back;
    GDCurrentDL* dl;
    s32 i;
    u32 n;
    SprtProj* p;
    s32 col;

    lbl_803CBB30 = count;
    lbl_803CC1E0 = size / 2;
    memcpy(lbl_802FE8B8, handles, count * sizeof(u32));
    half = size / 2;
    front = buf;
    back = buf + half;
    dl = lbl_803006F8[0];
    half = half / count;
    for (i = 0; i < count; i++) {
        if (sizes != NULL) {
            n = sizes[i];
        } else {
            n = half;
        }
        fn_800A1A70(dl, front, n);
        fn_800A1A70(dl + 24, back, n);
        SetProjection(&lbl_803CBB40[i], proj, projType);
        front += n;
        back += n;
        dl++;
    }
    lbl_803CC1D4 = lbl_803CBB30;
    lbl_803CBB34 = &lbl_802FEBF8[lbl_803CBB30];
    lbl_803CBB38 = lbl_803CBB34 + 24;
    lbl_803CC1E4 = lbl_803006F8[lbl_803CC1C4];
    lbl_803CC1C0 = &lbl_803CC1E4[lbl_803CBB30];
    lbl_803CBB40 = &lbl_802FE918[lbl_803CBB30];
    lbl_803CC1C0->end = lbl_803CC1E4[0].begin + lbl_803CC1E0;
    while (lbl_803CC1D4 != 0) {
        lbl_803CC1D4--;
        lbl_803CC1C0--;
        lbl_803CBB34--;
        lbl_803CBB38--;
        lbl_803CBB40--;
        memset(lbl_803CBB34, 0, sizeof(SprtState));
        PSMTXIdentity(lbl_803CBB34->view);
        memcpy(&lbl_803CBB34->proj, lbl_803CBB40, sizeof(SprtProj));
        lbl_803CBB34->_8A = 1;
        lbl_803CBB34->_80 = -1;
        memcpy(lbl_803CBB38, lbl_803CBB34, sizeof(SprtState));
    }
    lbl_803CC1D8[1] = NULL;
    lbl_803CC1D8[0] = NULL;
}

// .text:0x800B27DC size:0x78
void fn_800B27DC(Mtx44 m, GXProjectionType type) {
    SetProjection(&lbl_803CBB34->proj, m, type);
}

// .text:0x800B27A4 size:0x38
void fn_800B27A4(s32 shift) {
    s16 one;

    if (shift >= 0 && shift <= 14) {
        one = 1 << shift;
        lbl_803CC1C8 = shift;
        lbl_801115A0[3][0] = one;
        lbl_801115A0[2][1] = one;
        lbl_801115A0[2][0] = one;
        lbl_801115A0[1][1] = one;
    }
}

// .text:0x800B251C size:0x288
void fn_800B251C(void) {
    u32* handle;
    s32 i;
    u32 len;
    SprtLayer* layer;

    if (lbl_803CC1C0 != NULL) {
        handle = lbl_802FE8B8;
        lbl_803CC1C0 = lbl_803CC1E4;
        for (i = 0; i < lbl_803CBB30; i++) {
            len = lbl_803CC1C0->pDisplayListData - lbl_803CC1C0->begin;
            if (len != 0) {
                while (len & 31) {
                    len++;
                    *lbl_803CC1C0->pDisplayListData = 0;
                    lbl_803CC1C0->pDisplayListData++;
                }
                DCStoreRangeNoSync(lbl_803CC1C0->begin, len);
                layer = &lbl_80111340[lbl_803CC1C4][i];
                layer->dl = lbl_803CC1C0;
                layer->draw = fn_800B2240;
                fn_800A7D4C(*handle, layer);
            }
            handle++;
            lbl_803CC1C0++;
        }
        lbl_803CC1D4 = lbl_803CBB30;
        lbl_803CC1C4 ^= 1;
        lbl_803CC1E4 = lbl_803006F8[lbl_803CC1C4];
        lbl_803CBB34 = &lbl_802FEBF8[lbl_803CBB30];
        lbl_803CBB38 = lbl_803CBB34 + 24;
        lbl_803CBB40 = &lbl_802FE918[lbl_803CBB30];
        lbl_803CC1C0 = &lbl_803CC1E4[lbl_803CBB30];
        lbl_803CC1C0->end = lbl_803CC1E4[0].begin + lbl_803CC1E0;
        while (lbl_803CC1D4 != 0) {
            lbl_803CC1D4--;
            lbl_803CC1C0--;
            lbl_803CBB34--;
            lbl_803CBB38--;
            lbl_803CBB40--;
            memset(lbl_803CBB34, 0, sizeof(SprtState));
            PSMTXIdentity(lbl_803CBB34->view);
            memcpy(&lbl_803CBB34->proj, lbl_803CBB40, sizeof(SprtProj));
            lbl_803CBB34->_8A = 1;
            lbl_803CBB34->_80 = -1;
            memcpy(lbl_803CBB38, lbl_803CBB34, sizeof(SprtState));
            if (lbl_803CC1D8[lbl_803CC1C4] != NULL) {
                lbl_803CC1C0->length = lbl_803CC1D8[lbl_803CC1C4][lbl_803CC1D4];
                lbl_803CC1C0->begin = lbl_803CC1C0->end - lbl_803CC1C0->length;
                if (lbl_803CC1D4 != 0) {
                    lbl_803CC1C0[-1].end = lbl_803CC1C0->begin;
                }
            }
            lbl_803CC1C0->pDisplayListData = lbl_803CC1C0->begin;
        }
        lbl_803CC1D8[lbl_803CC1C4] = NULL;
    }
}

// .text:0x800B24D4 size:0x48
void fn_800B24D4(s32 index) {
    SprtState* state = &lbl_802FEBF8[index];

    lbl_803CC1D4 = index;
    lbl_803CBB34 = state;
    lbl_803CBB38 = state + 24;
    lbl_803CBB40 = &lbl_802FE918[index];
    lbl_803CC1C0 = &lbl_803CC1E4[index];
}

// .text:0x800B2240 size:0x294
void fn_800B2240(SprtLayer* layer) {
    GDCurrentDL* dl = layer->dl;
    GXColor fogColor;
    GXTexObj texObj;
    Mtx identity;

    GXSetScissor(lbl_803CC1CC, lbl_803CC1D0, lbl_803CBB28, lbl_803CBB2C);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    GXSetZCompLoc(GX_TRUE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetCullMode(GX_CULL_NONE);
    fogColor.r = fogColor.g = fogColor.b = 0;
    GXSetFog(GX_FOG_NONE, 0.0f, 0.0f, 0.0f, 0.0f, fogColor);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, lbl_803CC1C8);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXInitTexObj(&texObj, lbl_80111580, 4, 4, GX_TF_RGB5A3, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&texObj, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXLoadTexObj(&texObj, GX_TEXMAP0);
    GXLoadTexObj(&texObj, GX_TEXMAP1);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_RASA, GX_CA_TEXA, GX_CA_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetNumIndStages(0);
    GXSetTevDirect(GX_TEVSTAGE0);
    GXSetProjectionv((f32*)lbl_803CBB40);
    PSMTXIdentity(identity);
    GXLoadPosMtxImm(identity, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXCallDisplayList(dl->begin, dl->pDisplayListData - dl->begin);
}


// .text:0x800B21A8 size:0x98
void fn_800B21A8(s32 mode) {
    u32 zmode;

    if (mode == 2) {
        zmode = lbl_803CBB34->zmode;
        if (fn_800B216C(1, GX_LESS, 1)) {
            lbl_803CBB34->_7C = zmode;
        }
    } else if (mode != 0) {
        fn_800B216C(1, GX_LEQUAL, 1);
    } else {
        fn_800B216C(1, GX_ALWAYS, 1);
    }
}

// .text:0x800B216C size:0x3C
s32 fn_800B216C(u8 enable, s32 func, u8 update) {
    u32 zmode = (enable | (func << 1) | (update << 4)) | 0x40000000;

    if (lbl_803CBB34->zmode == zmode) {
        return 0;
    }
    lbl_803CBB34->zmode = zmode;
    return 1;
}

// .text:0x800B2160 size:0xC
void fn_800B2160(u8 value) {
    lbl_803CBB34->_8A = value;
}

// .text:0x800B1EBC size:0x2A4
s32 fn_800B1EBC(SprtTex* tex, s32 id, u16 width, u16 height) {
    s32 map = id + 1;
    s32 dirty;
    s32 n;
    u32 tmem;
    u8 wrapS;
    u8 wrapT;
    u16 bits;
    u16 v;

    lbl_803CBB34->_68[id] = lbl_803CBB34->_84;
    dirty = 0;
    lbl_803CBB34->_84++;
    if (lbl_803CBB34->tex[id] != tex) {
        lbl_803CBB34->tex[id] = tex;
        ReserveSprite(((tex->tlut != NULL) * 7 + 4) * 5);
        if (tex->tlut != NULL) {
            n = 1;
            while (n * 16 < tex->tlutCount) {
                n *= 2;
            }
            tmem = (id << 13) + 0xC0000;
            fn_800A26FC(tex->tlut, tmem);
            fn_800A237C(map, tmem, tex->tlutFormat);
        }
        wrapS = tex->wrapS;
        if (wrapS != GX_CLAMP) {
            v = tex->width;
            bits = 0;
            while (v != 0) {
                bits += v & 1;
                v >>= 1;
            }
            if (bits > 1) {
                wrapS = GX_CLAMP;
            }
        }
        wrapT = tex->wrapT;
        if (wrapT != GX_CLAMP) {
            v = tex->height;
            bits = 0;
            while (v != 0) {
                bits += v & 1;
                v >>= 1;
            }
            if (bits > 1) {
                wrapT = GX_CLAMP;
            }
        }
        fn_800A1F40(map, wrapS, wrapT, tex->minFilter, tex->magFilter, tex->minLod, tex->maxLod, tex->lodBias, 0, 0, 0);
        fn_800A2194(map, tex->width, tex->height, tex->format);
        fn_800A2294(map, tex->image);
        dirty = 1;
    }
    if (lbl_803CBB34->width != width || lbl_803CBB34->height != height) {
        lbl_803CBB34->width = width;
        lbl_803CBB34->height = height;
        ReserveSprite(15);
        fn_800A246C(id, width, 0, 0, height, 0, 0);
        dirty = 1;
    }
    return dirty;
}


// .text:0x800B1500 size:0x9BC
void DrawSprite(s32 prim, SprtVtx* verts, s32 count, SprtTex* tex, u16 width, u16 height) {
    s32 dirty;
    s32 changed;
    u8* cmd;
    u8* hdr;
    u16 n;
    s32 size;

    dirty = 0;
    if (tex != NULL) {
        lbl_803CC0F0 = lbl_803CC1C0;
        dirty = fn_800B1EBC(tex, 0, width, height);
        lbl_803CC0F0 = NULL;
    }
    dirty |= UpdateProjection();
    dirty |= UpdateViewMtx();
    dirty |= UpdateBlendMode();
    changed = UpdateAlphaCompare();
    if (changed == 0) {
        changed = UpdateZMode();
    }
    dirty |= changed;
    if (verts[0].color != 0 && (verts[0].pos.x != 0.0f || verts[0].pos.y != 0.0f) &&
        (verts[1].pos.x != 0.0f || verts[1].pos.y != 0.0f) && (verts[2].pos.x != 0.0f || verts[2].pos.y != 0.0f) &&
        verts[3].pos.x != 0.0f) {
    }
    if ((lbl_803CBB34->_8B == 1) == (tex == NULL)) {
        cmd = lbl_803CBB20;
        if (tex == NULL) {
            cmd = lbl_803CBB18;
        }
        ReserveSprite(5);
        memcpy(lbl_803CC1C0->pDisplayListData, cmd, 5);
        dirty = 1;
        lbl_803CC1C0->pDisplayListData += 5;
        lbl_803CBB34->_8B = tex != NULL;
    }
    if (lbl_803CBB34->_80 >= 0 && dirty == 0) {
        hdr = lbl_803CC1C0->begin + lbl_803CBB34->_80;
        n = *(u16*)(hdr + 1);
        if (hdr[0] == GX_QUADS && prim == GX_QUADS && lbl_803CC1C0->pDisplayListData == hdr + n * sizeof(SprtVtx) + 3 &&
            n < 0xFFFF - count) {
            size = count * sizeof(SprtVtx);
            ReserveSprite(size);
            hdr = lbl_803CC1C0->begin + lbl_803CBB34->_80;
            memcpy(lbl_803CC1C0->pDisplayListData, verts, size);
            lbl_803CC1C0->pDisplayListData += size;
            *(u16*)(hdr + 1) += count;
            return;
        }
    }
    size = count * sizeof(SprtVtx);
    lbl_803CBB34->_80 = lbl_803CC1C0->pDisplayListData - lbl_803CC1C0->begin;
    ReserveSprite(size + 3);
    lbl_803CC1C0->pDisplayListData[0] = prim;
    *(u16*)(lbl_803CC1C0->pDisplayListData + 1) = count;
    lbl_803CC1C0->pDisplayListData += 3;
    memcpy(lbl_803CC1C0->pDisplayListData, verts, size);
    lbl_803CC1C0->pDisplayListData += size;
}

// .text:0x800B1468 size:0x98
void fn_800B1468(Vec* pos, u32 color, SprtTex* tex) {
    SprtVtx verts[4];
    s32 i;

    for (i = 0; i < 4; i++) {
        memcpy(&verts[i].pos, &pos[i], sizeof(Vec));
        verts[i].color = color;
        memcpy(verts[i].st, lbl_801115A0[i], sizeof(lbl_801115A0[i]));
    }
    DrawSprite(GX_QUADS, verts, 4, tex, tex->width, tex->height);
}

// .text:0x800B13C0 size:0xA8
void fn_800B13C0(Vec* pos, u32* colors, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        memcpy(&lbl_803C8A24[i].pos, &pos[i], sizeof(Vec));
        lbl_803C8A24[i].color = colors[i];
        memcpy(lbl_803C8A24[i].st, lbl_801115A0[0], sizeof(lbl_801115A0[0]));
    }
    DrawSprite(GX_TRIANGLEFAN, lbl_803C8A24, count, NULL, 0, 0);
}

// .text:0x800B1388 size:0x38
void fn_800B1388(SprtVtx* verts) {
    DrawSprite(GX_QUADS, verts, 4, NULL, 0, 0);
}

// .text:0x800B1350 size:0x38
void DrawSprite_TexObj(SprtVtx* verts, SprtTex* tex) {
    DrawSprite(GX_QUADS, verts, 4, tex, tex->width, tex->height);
}

// .text:0x800B1314 size:0x3C
void fn_800B1314(SprtVtx* verts, SprtTex* tex, u16 width, u16 height) {
    DrawSprite(GX_QUADS, verts, 4, tex, width, height);
}

// .text:0x800B12DC size:0x38
void fn_800B12DC(SprtVtx* verts, s32 count) {
    DrawSprite(GX_TRIANGLEFAN, verts, count, NULL, 0, 0);
}

// .text:0x800B12A4 size:0x38
void DrawNullSprite(SprtVtx* verts, s32 count) {
    DrawSprite(GX_TRIANGLESTRIP, verts, count, NULL, 0, 0);
}

// .text:0x800B1188 size:0x11C
void fn_800B1188(void) {
    SprtProj proj;
    u32 zmode;
    u8 c;
    s16 one;

    memcpy(&proj, &lbl_803CBB38->proj, sizeof(SprtProj));
    zmode = lbl_803CBB38->zmode;
    c = lbl_803CBB38->_8C;
    one = 1 << lbl_803CC1C8;
    lbl_801115F0[3].st[0] = one;
    lbl_801115F0[2].st[0] = one;
    lbl_801115F0[2].st[1] = one;
    lbl_801115F0[1].st[1] = one;
    fn_800B27DC(lbl_801115B0, GX_ORTHOGRAPHIC);
    fn_800B117C(1);
    fn_800B21A8(0);
    DrawSprite(GX_QUADS, lbl_801115F0, 4, NULL, 0, 0);
    memcpy(&lbl_803CBB34->proj, &proj, sizeof(SprtProj));
    lbl_803CBB34->_8C = c;
    lbl_803CBB34->zmode = zmode;
}

// .text:0x800B117C size:0xC
void fn_800B117C(u8 value) {
    lbl_803CBB34->_8C = value;
}

// .text:0x800B0D68 size:0x414
s32 AllocateSprite(s32 index, s32 size) {
    s32 need;
    s32 lo;
    s32 hi;
    s32 last;
    s32 avail;
    s32 amount;
    s32 moved;
    s32 i;
    u8* src;
    u8* dst;
    u8* flushStart;
    u8* flushEnd;

    if (size <= 0) {
        return 0;
    }
    if (size < lbl_803CBB3C) {
        need = lbl_803CBB3C * ((lbl_803CBB3C + size - 1) / lbl_803CBB3C);
    } else {
        need = (size + 31) / 32 * 32;
    }
    lo = index;
    last = lbl_803CBB30 - 1;
    hi = index;
    flushEnd = lbl_803CC1E4[0].begin;
    flushStart = lbl_803CC1E4[last].end;
    do {
        lo -= lo > 0;
        avail = lbl_803CC1E4[lo].length - ((lbl_803CC1E4[lo].pDisplayListData - lbl_803CC1E4[lo].begin + 31) & ~31);
        if (need <= avail) {
            avail = need;
        }
        amount = (lo != index) * avail;
        if (amount != 0) {
            lbl_803CC1E4[lo].length -= amount;
            lbl_803CC1E4[lo].end -= amount;
            src = lbl_803CC1E4[lo + 1].begin;
            moved = 0;
            i = lo;
            do {
                i++;
                lbl_803CC1E4[i].begin -= amount;
                moved += lbl_803CC1E4[i].length;
                lbl_803CC1E4[i].end -= amount;
                lbl_803CC1E4[i].pDisplayListData -= amount;
            } while (i < index);
            if (moved != 0) {
                dst = src - amount;
                memmove(dst, src, moved);
                if (flushStart > dst) {
                    flushStart = dst;
                }
                if (flushEnd < src) {
                    flushEnd = src;
                }
            }
            need -= amount;
            lbl_803CC1E4[index].length += amount;
            lbl_803CC1E4[index].end += amount;
        }
        hi += hi < last;
        avail = lbl_803CC1E4[hi].length - ((lbl_803CC1E4[hi].pDisplayListData - lbl_803CC1E4[hi].begin + 31) & ~31);
        if (need <= avail) {
            avail = need;
        }
        amount = (hi != index) * avail;
        if (amount != 0) {
            lbl_803CC1E4[hi].length -= amount;
            lbl_803CC1E4[hi].end -= amount;
            src = lbl_803CC1E4[index + 1].begin;
            moved = 0;
            for (i = index + 1; i <= hi; i++) {
                lbl_803CC1E4[i].begin += amount;
                moved += lbl_803CC1E4[i].length;
                lbl_803CC1E4[i].end += amount;
                lbl_803CC1E4[i].pDisplayListData += amount;
            }
            if (moved != 0) {
                dst = src + amount;
                memmove(dst, src, moved);
                if (flushEnd < dst) {
                    flushEnd = dst;
                }
                if (flushStart > src) {
                    flushStart = src;
                }
            }
            need -= amount;
            lbl_803CC1E4[index].length += amount;
            lbl_803CC1E4[index].end += amount;
        }
    } while (need > 0 && (lo != 0 || last - hi != 0));
    if (flushStart < flushEnd) {
        DCStoreRange(flushStart, flushEnd - flushStart);
    }
    if (need > 0) {
        return need;
    }
    return 0;
}

// .text:0x800B0D38 size:0x30
void fn_800B0D38(s32 index, s32 mode) {
    if (index >= 0 && index < lbl_803CBB30) {
        lbl_80111340[1][index].mode = mode;
        lbl_80111340[0][index].mode = mode;
    }
}

// .text:0x800B0D28 size:0x10
void fn_800B0D28(u32* value) {
    lbl_803CC1D8[0] = value;
    lbl_803CC1D8[1] = value;
}
