#include "challenge/rep_0138.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "string.h"

extern void fn_80048C1C(void);
extern void fn_80048C28(void);
extern void fn_80048D4C(void);
extern void LITXForm(void* light, Mtx view);
extern void SetFog(GXFogType type, f32 startZ, f32 endZ, f32 nearZ, f32 farZ, GXColor color);
extern void SetFogNoneAgain(void);
extern void fn_800B806C(s32 arg0, f32 top, f32 bottom, f32 left, f32 right, f32 nearZ, f32 farZ, f32 arg7);
extern void fn_80048C14(s32 arg0);
extern void fn_80048E00(s32 arg0, s32 arg1);
extern s32 fn_80048EA8(s32 arg0);
extern void fn_800B49E4(void* layout);
extern void fn_800BCE38(void* geo);
extern void fn_800BD190(void* geo, void* tex);
extern void convertTextureHeader(void* tex);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void fn_800AD038(void* arg0);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800B472C(void* arg0);

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

typedef struct Task0138 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
} Task0138;

extern Task0138* lbl_803CC1B8;

typedef struct Layout0138 {
    /* 0x0 */ u8 _0[0x6];
    /* 0x6 */ u16 _6;
} Layout0138;

typedef struct File0138 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ u32 _04;
    /* 0x08 */ u32 _08;
    /* 0x0C */ u32 _0C;
    /* 0x10 */ u32 _10;
    /* 0x14 */ u32 _14;
} File0138;

typedef struct Draw0138 {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ void (*_04)(void* arg0);
    /* 0x08 */ Mtx _08;
    /* 0x38 */ u8 _38[0x68 - 0x38];
    /* 0x68 */ Layout0138* _68;
} Draw0138; // size: 0x6C

extern struct {
    /* 0x000 */ u8 _000[0x30];
    /* 0x030 */ u16 _030;
    /* 0x032 */ u8 _032[0x4C - 0x32];
    /* 0x04C */ f32 _04C;
    /* 0x050 */ f32 _050;
    /* 0x054 */ f32 _054;
    /* 0x058 */ void* _058;
    /* 0x05C */ Draw0138 _05C[4];
    /* 0x20C */ u8 _20C[0x21C - 0x20C];
    /* 0x21C */ void* _21C;
    /* 0x220 */ u8 _220[0x224 - 0x220];
    /* 0x224 */ u32* _224;
    /* 0x228 */ s16 _228;
    /* 0x22A */ s16 _22A;
    /* 0x22C */ s16 _22C;
    /* 0x22E */ s16 _22E;
    /* 0x230 */ s8 _230;
    /* 0x231 */ s8 _231;
    /* 0x232 */ u8 _232[0x234 - 0x232];
    /* 0x234 */ u8 _234;
    /* 0x235 */ u8 _235[0x238 - 0x235];
    /* 0x238 */ u8 _238;
    /* 0x239 */ u8 _239;
    /* 0x23A */ u8 _23A[0x23C - 0x23A];
    /* 0x23C */ s8 _23C;
} lbl_1_common_bss_472B4;

extern struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
} lbl_1_data_200;

typedef struct Fog0138 {
    /* 0x0 */ GXColor color;
    /* 0x4 */ f32 start;
    /* 0x8 */ f32 end;
} Fog0138;

extern void* lbl_1_data_848[4];
extern GXColor lbl_1_data_858;
extern GXCullMode lbl_1_data_8C4;
extern struct {
    /* 0x0 */ u8 _0;
} lbl_1_data_85C;
extern u8 lbl_1_bss_C2;
extern s32 lbl_1_bss_C4;
extern GXTexObj lbl_1_bss_4E4;
extern Fog0138* lbl_1_bss_4E0;

// .text:0x37D0 size:0x7C
void fn_1_85A8(void) {
    if (lbl_803C77B8[0]._04 & 1) {
        if (--lbl_1_common_bss_472B4._22E < -1) {
            lbl_1_common_bss_472B4._22E = lbl_1_common_bss_472B4._22A - 1;
        }
    } else if (lbl_803C77B8[0]._04 & 2) {
        if (++lbl_1_common_bss_472B4._22E >= lbl_1_common_bss_472B4._22A) {
            lbl_1_common_bss_472B4._22E = -1;
        }
    }
}

// .text:0x3590 size:0x240
void fn_1_8368(void) {
    if (lbl_803C77B8[0]._04 & 1) {
        if (--lbl_1_common_bss_472B4._22E < -1) {
            lbl_1_common_bss_472B4._22E = lbl_1_common_bss_472B4._228 - 1;
        }
    } else if (lbl_803C77B8[0]._04 & 2) {
        if (++lbl_1_common_bss_472B4._22E >= lbl_1_common_bss_472B4._228) {
            lbl_1_common_bss_472B4._22E = -1;
        }
    } else if (lbl_803C77B8[0]._02 & 0x400) {
        lbl_1_common_bss_472B4._239 ^= 1;
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        lbl_1_common_bss_472B4._238 ^= 1;
    }
    lbl_1_data_200._00 += lbl_803C77B8[0]._10 / 128.0f;
    lbl_1_data_200._08 += lbl_803C77B8[0]._11 / 128.0f;
    lbl_1_data_200._0C += lbl_803C77B8[0]._12 / 128.0f;
    lbl_1_data_200._14 += lbl_803C77B8[0]._13 / 128.0f;
    if (!(lbl_803C77B8[0]._00 & 0x100)) {
        lbl_1_data_200._04 -= lbl_803C77B8[0]._15 / 1024.0f;
        lbl_1_data_200._04 += lbl_803C77B8[0]._14 / 1024.0f;
    } else {
        lbl_1_data_200._10 -= lbl_803C77B8[0]._15 / 1024.0f;
        lbl_1_data_200._10 += lbl_803C77B8[0]._14 / 1024.0f;
    }
}

// .text:0x3220 size:0x370
void fn_1_7FF8(void) {
    switch (lbl_803C77B8[0]._04) {
    case 8:
        if (--lbl_1_common_bss_472B4._23C < 0) {
            lbl_1_common_bss_472B4._23C = 5;
        }
        break;
    case 4:
        if (++lbl_1_common_bss_472B4._23C >= 6) {
            lbl_1_common_bss_472B4._23C = 0;
        }
        break;
    case 1:
        switch (lbl_1_common_bss_472B4._23C) {
        case 0:
            switch (--lbl_1_bss_4E0->color.a) {
            case 0xFF:
                lbl_1_bss_4E0->color.a = 7;
                break;
            case 3:
                lbl_1_bss_4E0->color.a = 2;
                break;
            case 1:
                lbl_1_bss_4E0->color.a = 0;
                break;
            }
            break;
        case 1:
            lbl_1_bss_4E0->color.r--;
            break;
        case 2:
            lbl_1_bss_4E0->color.g--;
            break;
        case 3:
            lbl_1_bss_4E0->color.b--;
            break;
        case 4:
            if ((lbl_1_bss_4E0->start -= 1.0f) < 0.0f) {
                lbl_1_bss_4E0->start = 0.0f;
            }
            break;
        case 5:
            if ((lbl_1_bss_4E0->end -= 1.0f) < 0.0f) {
                lbl_1_bss_4E0->end = 0.0f;
            }
            break;
        }
        break;
    case 2:
        switch (lbl_1_common_bss_472B4._23C) {
        case 0:
            switch (++lbl_1_bss_4E0->color.a) {
            case 1:
                lbl_1_bss_4E0->color.a = 2;
                break;
            case 3:
                lbl_1_bss_4E0->color.a = 4;
                break;
            case 8:
                lbl_1_bss_4E0->color.a = 0;
                break;
            }
            break;
        case 1:
            lbl_1_bss_4E0->color.r++;
            break;
        case 2:
            lbl_1_bss_4E0->color.g++;
            break;
        case 3:
            lbl_1_bss_4E0->color.b++;
            break;
        case 4:
            if ((lbl_1_bss_4E0->start += 1.0f) > 512.0f) {
                lbl_1_bss_4E0->start = 512.0f;
            }
            break;
        case 5:
            if ((lbl_1_bss_4E0->end += 1.0f) > 512.0f) {
                lbl_1_bss_4E0->end = 512.0f;
            }
            break;
        }
        break;
    }
}

// .text:0x3120 size:0x100
void fn_1_7EF8(void) {
    switch (lbl_803C77B8[0]._04) {
    case 4:
    case 8:
        lbl_1_bss_C2 = !lbl_1_bss_C2;
        break;
    case 1:
        fn_80048E00(lbl_1_bss_C2, fn_80048EA8(lbl_1_bss_C2) - 1);
        break;
    case 2:
        fn_80048E00(lbl_1_bss_C2, fn_80048EA8(lbl_1_bss_C2) + 1);
        break;
    case 0x100:
        lbl_1_data_85C._0 = !lbl_1_data_85C._0;
        if (lbl_1_data_85C._0) {
            fn_80048C14(0x3F);
        } else {
            fn_80048C14(0);
        }
        break;
    }
}

// .text:0x302C size:0xF4
void fn_1_7E04(f32 zoom) {
    Mtx44 proj;
    f32 scale = 1.0f / zoom;

    C_MTXFrustum(proj, -0.175f * scale, 0.175f * scale, 0.25f * scale, -0.25f * scale, 1.0f, 512.0f);
    GXSetProjection(proj, GX_PERSPECTIVE);
    fn_800B806C(0, -240.0f * scale, 240.0f * scale, -320.0f * scale, 320.0f * scale, -512.0f, -1.0f, 1280.0f);
}

// .text:0x2B0C size:0x7C
void fn_1_78E4(void) {
    GXSetCopyClear(lbl_1_data_858, 0xFFFFFF);
    if (lbl_1_bss_C4 != 0) {
        GXSetCullMode(GX_CULL_NONE);
    } else {
        GXSetCullMode(GX_CULL_BACK);
    }
    SetFogNoneAgain();
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
}

// .text:0x2A94 size:0x78
void fn_1_786C(void) {
    fn_80048D4C();
    GXSetCopyClear(lbl_1_data_858, 0xFFFFFF);
    SetFog(lbl_1_bss_4E0->color.a, lbl_1_bss_4E0->start, lbl_1_bss_4E0->end, 1.0f, 512.0f, lbl_1_bss_4E0->color);
}

// .text:0x2A70 size:0x24
void fn_1_7848(void) {
    fn_80048C28();
    fn_80048C1C();
}

// .text:0x2A14 size:0x5C
void fn_1_77EC(void* arg0) {
    GXSetCullMode(lbl_1_data_8C4);
    fn_1_73B8(arg0, 3, lbl_1_data_848[0], lbl_1_data_848[1], lbl_1_data_848[2]);
}

// .text:0x23A4 size:0x104
// MWCC inlines fn_1_4DD8 here, where the target calls it; with that call it
// matches (body checked against a copy without fn_1_4DD8's definition).
void fn_1_717C(File0138* file) {
    void* geo;
    Layout0138* layout;
    u8* tex;

    layout = (Layout0138*)((u8*)file + file->_00);
    geo = (u8*)file + file->_0C;
    tex = (u8*)file + file->_14;

    fn_1_4DD8((u16*)((u8*)file + file->_08));
    fn_800B49E4(layout);
    fn_800BCE38(geo);
    convertTextureHeader(tex);
    lbl_1_common_bss_472B4._058 = tex + 4;
    fn_800BD190(geo, tex);
    haveActLayoutPointToGeoHeader(layout, geo);
    lbl_1_common_bss_472B4._22A = layout->_6;
    lbl_1_common_bss_472B4._05C[1]._68 = layout;
    lbl_1_common_bss_472B4._05C[0]._68 = layout;
    layout = (Layout0138*)((u8*)file + file->_04);
    geo = (u8*)file + file->_10;
    fn_800B49E4(layout);
    fn_800BCE38(geo);
    fn_800BD190(geo, tex);
    haveActLayoutPointToGeoHeader(layout, geo);
    lbl_1_common_bss_472B4._05C[3]._68 = layout;
    lbl_1_common_bss_472B4._05C[2]._68 = layout;
}

// .text:0x18EC size:0x184
void fn_1_66C4(void) {
    Task0138* task = lbl_803CC1B8;
    s32 save230;
    s32 save231;

    fn_800AD038(lbl_80366158._08);
    task->_10 = 0;
    save230 = lbl_1_common_bss_472B4._230;
    save231 = lbl_1_common_bss_472B4._231;
    memset(&lbl_1_common_bss_472B4, 0, 0x240);
    lbl_1_common_bss_472B4._230 = save230;
    lbl_1_common_bss_472B4._231 = save231;
    lbl_1_common_bss_472B4._21C = _OSAllocFromHeap(0x20, 0x80000);
    lbl_1_common_bss_472B4._04C = -6.0f;
    lbl_1_common_bss_472B4._050 = -10.666667f;
    lbl_1_common_bss_472B4._030 = 0xF36C;
    lbl_1_common_bss_472B4._054 = 0.63f;
    lbl_1_common_bss_472B4._22E = -1;
    lbl_1_common_bss_472B4._234 = 0;
    PSMTXIdentity(lbl_1_common_bss_472B4._05C[0]._08);
    lbl_1_common_bss_472B4._05C[0]._04 = fn_1_77EC;
    lbl_1_common_bss_472B4._05C[1] = lbl_1_common_bss_472B4._05C[0];
    lbl_1_common_bss_472B4._05C[2]._04 = fn_800B472C;
    lbl_1_common_bss_472B4._05C[3] = lbl_1_common_bss_472B4._05C[2];
    lbl_803CC1B8->_00 = fn_1_6848;
}

// .text:0xB4C size:0x19C
// Registers differ in every case, and the target adds the tile offset as the
// left operand last; no statement split or declaration order reproduced it.
s32 fn_1_5924(s32 width, s32 x, s32 y, s32 bpp, s32 arg4) {
    s32 offset;
    s32 row;
    s32 col;

    switch (bpp) {
    case 4:
        row = (y / 8) * width * 8;
        row += (y % 8) * 8;
        row += x % 8;
        offset = (x / 8) * 32 + row;
        return offset;
    case 8:
        row = (y / 4) * width * 4;
        row += (y % 4) * 8;
        row += x % 8;
        offset = (x / 8) * 32 + row;
        return offset;
    case 16:
        row = (y / 4) * width * 4;
        row += (y % 4) * 4;
        row += x % 4;
        offset = (x / 4) * 16 + row;
        return offset;
    case 32:
        row = (y / 4) * width * 4;
        row += (y % 4) * 4;
        row += x % 4;
        offset = (x / 4) * 16 + row;
        if (arg4 != 0) {
            offset += 16;
        }
        return offset;
    }
    return offset;
}

// .text:0x8C0 size:0x28C
void fn_1_5698(void) {
    Mtx44 proj;
    Mtx view;

    C_MTXOrtho(proj, 0.0f, 448.0f, 0.0f, 640.0f, -0.0f, -0.5f);
    GXSetProjection(proj, GX_ORTHOGRAPHIC);
    PSMTXIdentity(view);
    GXLoadPosMtxImm(view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetCullMode(GX_CULL_NONE);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 2);
    GXSetNumChans(0);
    GXSetNumTevStages(1);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_TEXA);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXLoadTexObj(&lbl_1_bss_4E4, GX_TEXMAP0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(0.0f, 100.0f, 0.0f);
    GXTexCoord2u16(0, 0);
    GXPosition3f32(0.0f, 356.0f, 0.0f);
    GXTexCoord2u16(0, 4);
    GXPosition3f32(256.0f, 356.0f, 0.0f);
    GXTexCoord2u16(4, 4);
    GXPosition3f32(256.0f, 100.0f, 0.0f);
    GXTexCoord2u16(4, 0);
    GXEnd();
    GXSetNumIndStages(0);
    GXSetTevDirect(GX_TEVSTAGE0);
}

// .text:0x768 size:0x4
void fn_1_5540(void) {
}

// .text:0x708 size:0x60
void fn_1_54E0(MtxPtr view) {
    s32 i;

    for (i = 0; i < 3; i++) {
        LITXForm(lbl_1_data_848[i], view);
    }
}

// .text:0x0 size:0xC0
void fn_1_4DD8(u16* data) {
    s32 i;
    u32* table;

    lbl_1_common_bss_472B4._228 = data[0];
    lbl_1_common_bss_472B4._224 = (u32*)(data + 2);
    table = lbl_1_common_bss_472B4._224;
    for (i = lbl_1_common_bss_472B4._228; i >= 0; i--) {
        *table++ += (u32)data;
    }
}
