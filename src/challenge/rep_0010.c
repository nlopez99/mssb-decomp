#include "challenge/rep_0010.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "C3/anim.h"

typedef struct Task0010 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ void* _14;
    /* 0x18 */ void* _18;
} Task0010;

typedef struct Model0010 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ u32 _04;
    /* 0x08 */ u32 _08;
    /* 0x0C */ u32 _0C;
    /* 0x10 */ u32 _10;
} Model0010;

typedef struct Draw0010 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ void (*_04)(void);
    /* 0x08 */ void* _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
} Draw0010; // size: 0x18

extern void* lbl_803CC1B8;
extern u8 lbl_803CBBC0;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
} lbl_80366158;

extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800B0C80(void (*callback)(void));
extern void fn_800AD054(s32 arg0, s32 arg1);
extern void fn_800A7D4C(s32 arg0, void* arg1);
extern void* ARAMTransfer(void* entry, int arg1, int arg2, u32 aram);
extern void convertTextureHeader(void* tex);
extern void resetAllDrawingStructs(void);
extern void LoadActorLayout(void* layout);
extern void convertGeometryAndSknHeader(void* geo, void* skn);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void fn_80025DDC(void* anim);
extern void fn_80009144(void);

static s32 lbl_1_data_0[7][4] = {
    { 0x40B, 0x40022EF0, 0x07684800, 0x16B18 },
    { 0x40B, 0x40020260, 0x0769B800, 0x12864 },
    { 0x40B, 0x4002FDC0, 0x076AE800, 0x207F8 },
    { 0x40B, 0x40024E2C, 0x076CF000, 0x159AC },
    { 0x40B, 0x4001CB88, 0x076E5000, 0xEE60 },
    { 0x40B, 0x40035BD0, 0x076F4000, 0x257FC },
    { 0x40B, 0x400397CC, 0x07719800, 0x23FF4 },
};
static Draw0010 lbl_1_data_70[2] = {
    { 0, fn_1_1240 },
    { 0, fn_1_1240 },
};
static s32 lbl_1_data_A0 = 2;
static s32 lbl_1_data_A4 = -1;
GXColor lbl_1_data_A8 = { 0x11, 0x77, 0x55, 0x00 };
u32 lbl_1_data_AC[15][4] = {
    { 0x00000000, 0x01070000, 0x00000000, 0x01070000 },
    { 0x00000000, 0x01040000, 0x01070000, 0x01040000 },
    { 0x00000000, 0x01020000, 0x020B0000, 0x01020000 },
    { 0x00000000, 0x01070000, 0x030D0000, 0x01070000 },
    { 0x00000000, 0x01088000, 0x04140000, 0x01088000 },
    { 0x00000000, 0x01040000, 0x051C8000, 0x01040000 },
    { 0x00000000, 0x00A18000, 0x06208000, 0x00A18000 },
    { 0x00000000, 0x00A18000, 0x06C20000, 0x00A18000 },
    { 0x00000000, 0x00AC0000, 0x07638000, 0x00AC0000 },
    { 0x00000000, 0x01010000, 0x080F8000, 0x01010000 },
    { 0x00000000, 0x009A8000, 0x09108000, 0x009A8000 },
    { 0x00000000, 0x00198000, 0x09AB0000, 0x00198000 },
    { 0x00000000, 0x00038000, 0x09C48000, 0x00038000 },
    { 0x00000000, 0x00C40000, 0x09C80000, 0x00C40000 },
    { 0x00000000, 0x00040000, 0x0A8C0000, 0x00040000 },
};

u32 lbl_1_bss_0;

// .text:0x00001948 size:0x24
void fn_1_1948(void) {
    Task0010* task = lbl_803CC1B8;

    if (task->_10 != 0) {
        task->_00 = fn_1_11D0;
    }
}

// .text:0x00001634 size:0x6C
void fn_1_1634(void) {
    if (lbl_803C6CF8._715 == 1) {
        ((Task0010*)lbl_803CC1B8)->_14 = ARAMTransfer(lbl_1_data_0[3], 0, 0, 0);
        ((Task0010*)lbl_803CC1B8)->_00 = fn_1_15CC;
    }
}

// .text:0x000015CC size:0x68
void fn_1_15CC(void) {
    Task0010* task = lbl_803CC1B8;

    if (lbl_803C6CF8._715 == 1) {
        task->_18 = (u8*)task->_14 + *(u32*)task->_14;
        convertTextureHeader(task->_18);
        ((Task0010*)lbl_803CC1B8)->_00 = fn_1_1538;
    }
}

// .text:0x00001538 size:0x94
void fn_1_1538(void) {
    Task0010* task = lbl_803CC1B8;

    fn_800A7D4C(0, &lbl_1_data_70[lbl_803CBBC0]);
    lbl_1_data_70[lbl_803CBBC0]._08 = task->_18;
    lbl_1_data_70[lbl_803CBBC0]._0C = lbl_1_bss_0;
    lbl_1_data_70[lbl_803CBBC0]._10 = lbl_1_data_A0;
    lbl_1_data_70[lbl_803CBBC0]._14 = lbl_1_data_A4;
}

// .text:0x00001240 size:0x2F8
void fn_1_1240(void) {}

// .text:0x000011D0 size:0x70
void fn_1_11D0(void) {
    resetAllDrawingStructs();
    fn_80009144();
    fn_800AD054(lbl_80366158._08, lbl_80366158._04);
    GXSetCopyClear(lbl_1_data_A8, 0xFFFFFF);
    ((Task0010*)lbl_803CC1B8)->_00 = fn_1_16A0;
}

// .text:0x00001148 size:0x88
void fn_1_1148(void) {
    Task0010* task = lbl_803CC1B8;

    *(u16*)((u8*)task + 0x16) = 0;
    *(u16*)((u8*)task + 0x14) = 0;
    resetAllDrawingStructs();
    fn_80009144();
    fn_800AD054(lbl_80366158._08, lbl_80366158._04);
    GXSetCopyClear(lbl_1_data_A8, 0xFFFFFF);
    ((Task0010*)lbl_803CC1B8)->_00 = fn_1_16A0;
}

// .text:0x0000110C size:0x3C
void _prolog(void) {
    fn_800B0C80(fn_1_1148);
    fn_800AD054(lbl_80366158._08, lbl_80366158._04);
}

// .text:0x00001108 size:0x4
void _unresolved(void) {}

// .text:0x00001104 size:0x4
void _epilog(void) {}

// .text:0x00000F2C size:0x1D8
void fn_1_F2C(s32 mode, s32 frac, s32 normals) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    if (normals != 0) {
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
        if (frac == -1) {
            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
        } else {
            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, frac);
        }
        break;
    }
    GXSetTevOrder(GX_TEVSTAGE0, mode == GX_PASSCLR ? GX_TEXCOORD_NULL : GX_TEXCOORD0,
                  mode == GX_PASSCLR ? GX_TEXMAP_NULL : GX_TEXMAP0, mode == GX_REPLACE ? GX_COLOR_NULL : GX_COLOR0A0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumChans(mode != GX_REPLACE);
    GXSetNumTexGens(mode != GX_PASSCLR);
    GXSetNumTevStages(1);
    GXSetTevOp(GX_TEVSTAGE0, mode);
}

// .text:0x000005E8 size:0x4
void fn_1_5E8(void) {}

// .text:0x0000058C size:0x5C
void fn_1_58C(void) {
    s32 zero = 0;

    ((Task0010*)fn_800B0A5C_insertQueue(fn_1_1E0, zero))->_10 = zero;
    ((Task0010*)lbl_803CC1B8)->_00 = fn_1_568;
    ((Task0010*)lbl_803CC1B8)->_10 = 0;
}

// .text:0x00000568 size:0x24
void fn_1_568(void) {
    Task0010* task = lbl_803CC1B8;

    if (task->_10 == 1) {
        task->_00 = fn_1_16A0;
    }
}

// .text:0x000001E0 size:0x388
void fn_1_1E0(void) {}

// .text:0x000001B0 size:0x30
void fn_1_1B0(u32* base, s32 count) {
    s32 i;
    u32* p = base;

    for (i = 0; i < count; i++, p++) {
        if (*p != 0) {
            *p += (u32)base;
        }
    }
}

// .text:0x000000E8 size:0xC8
// 97.40%: the target fixes _08 to _10 through a pointer to _08 (addi r3,r31,8);
// a pointer local, an inline helper or an array field all fold back into r31.
void fn_1_E8(Model0010* model) {
    if (model->_00 != 0) {
        model->_00 += (u32)model;
    }
    if (model->_04 != 0) {
        model->_04 += (u32)model;
    }
    if (model->_08 != 0) {
        model->_08 += (u32)model;
    }
    if (model->_0C != 0) {
        model->_0C += (u32)model;
    }
    if (model->_10 != 0) {
        model->_10 += (u32)model;
    }
    convertTextureHeader((void*)model->_00);
    LoadActorLayout((void*)model->_04);
    convertGeometryAndSknHeader((void*)model->_08, (void*)model->_0C);
    haveActLayoutPointToGeoHeader((void*)model->_04, (void*)model->_08);
    if (model->_10 != 0) {
        fn_80025DDC((void*)model->_10);
    }
}

// .text:0x00000020 size:0xC8
// 97.40%: the target fixes _08 to _10 through a pointer to _08 (addi r3,r31,8);
// a pointer local, an inline helper or an array field all fold back into r31.
void fn_1_20(Model0010* model) {
    if (model->_00 != 0) {
        model->_00 += (u32)model;
    }
    if (model->_04 != 0) {
        model->_04 += (u32)model;
    }
    if (model->_08 != 0) {
        model->_08 += (u32)model;
    }
    if (model->_0C != 0) {
        model->_0C += (u32)model;
    }
    if (model->_10 != 0) {
        model->_10 += (u32)model;
    }
    convertTextureHeader((void*)model->_00);
    LoadActorLayout((void*)model->_04);
    convertGeometryAndSknHeader((void*)model->_08, (void*)model->_0C);
    haveActLayoutPointToGeoHeader((void*)model->_04, (void*)model->_08);
    if (model->_10 != 0) {
        fn_80025DDC((void*)model->_10);
    }
}

// .text:0x00000000 size:0x20
void fn_1_0(ANIMBank* bank) {
    ANIMGet(bank);
}
