#include "challenge/rep_0138.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"

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

extern struct {
    /* 0x000 */ u8 _000[0x58];
    /* 0x058 */ void* _058;
    /* 0x05C */ u8 _05C[0xC4 - 0x5C];
    /* 0x0C4 */ Layout0138* _0C4;
    /* 0x0C8 */ u8 _0C8[0x130 - 0xC8];
    /* 0x130 */ Layout0138* _130;
    /* 0x134 */ u8 _134[0x19C - 0x134];
    /* 0x19C */ Layout0138* _19C;
    /* 0x1A0 */ u8 _1A0[0x208 - 0x1A0];
    /* 0x208 */ Layout0138* _208;
    /* 0x20C */ u8 _20C[0x224 - 0x20C];
    /* 0x224 */ u32* _224;
    /* 0x228 */ s16 _228;
    /* 0x22A */ s16 _22A;
    /* 0x22C */ s16 _22C;
    /* 0x22E */ s16 _22E;
} lbl_1_common_bss_472B4;

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
    lbl_1_common_bss_472B4._130 = layout;
    lbl_1_common_bss_472B4._0C4 = layout;
    layout = (Layout0138*)((u8*)file + file->_04);
    geo = (u8*)file + file->_10;
    fn_800B49E4(layout);
    fn_800BCE38(geo);
    fn_800BD190(geo, tex);
    haveActLayoutPointToGeoHeader(layout, geo);
    lbl_1_common_bss_472B4._208 = layout;
    lbl_1_common_bss_472B4._19C = layout;
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
