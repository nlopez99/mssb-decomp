#include "game/kinoko.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "string.h"

extern struct {
    u8 _00[0x28];
    u8 _28;
} lbl_80366158;

extern void fn_80011604(s8, void*);
extern s32 fn_800247E4(s32, s32, s32, s32);
extern BOOL fn_8001B728(s32, s32, Vec*);
extern void fn_800B0A5C_insertQueue(void (*)(void), s32);

typedef struct {
    /* 0x0000 */ u8 _0000[0x19D4];
    /* 0x19D4 */ s32 _19D4;
    /* 0x19D8 */ u8 _19D8[4];
    /* 0x19DC */ s8 _19DC;
    /* 0x19DD */ u8 _19DD;
} lbl_3_data_28928_s; // size 0x19E0

extern lbl_3_data_28928_s lbl_3_data_28928;
extern u8 lbl_3_data_2A308[10][4];

s8 lbl_3_data_2A330 = -1;

// MWCC lays out these statics in reverse order of declaration
static u8 lbl_3_bss_BAE0[0x1BF0];
static u8 lbl_3_bss_BAA0[0x40] ATTRIBUTE_ALIGN(32);
static u8 lbl_3_bss_BA60[0x40] ATTRIBUTE_ALIGN(32);
static GXTexObj lbl_3_bss_BA2C;
static GXTexObj lbl_3_bss_BA0C;
static s32 lbl_3_bss_BA08;
static GXTexObj* lbl_3_bss_BA04;
static u8* lbl_3_bss_BA00;

// .text:0x0016C394 size:0x7C mapped:0x807AB428
// Matches once fn_3_16B884 has a real body; its empty stub gets inlined here.
void fn_3_16C394(s8 arg0) {
    memset(&lbl_3_data_28928, 0, sizeof(lbl_3_data_28928));
    memset(lbl_3_bss_BAE0, 0, sizeof(lbl_3_bss_BAE0));
    lbl_3_data_28928._19DC = arg0;
    lbl_3_data_28928._19DD = 1;
    lbl_3_data_28928._19D4 = 1;
    fn_3_16B884();
    fn_800B0A5C_insertQueue(fn_3_16A07C, 0);
}

// .text:0x0016B884 size:0xB10 mapped:0x807AA918
void fn_3_16B884(void) {
    return;
}

// .text:0x0016B5B4 size:0x2D0 mapped:0x807AA648
void fn_3_16B5B4(RibbonEffect* ribbon, s8 id, int frame) {
    f32 t = frame / 5.0f;

    ribbon->color[0] = (1.0 - t) * lbl_3_data_2A308[ribbon->colorFrom][0] + t * lbl_3_data_2A308[ribbon->colorTo][0];
    ribbon->color[1] = (1.0 - t) * lbl_3_data_2A308[ribbon->colorFrom][1] + t * lbl_3_data_2A308[ribbon->colorTo][1];
    ribbon->color[2] = (1.0 - t) * lbl_3_data_2A308[ribbon->colorFrom][2] + t * lbl_3_data_2A308[ribbon->colorTo][2];
    ribbon->color[3] = (1.0 - t) * lbl_3_data_2A308[ribbon->colorFrom][3] + t * lbl_3_data_2A308[ribbon->colorTo][3];
    ribbon->_2A = 1;
    fn_3_16B488(&ribbon->pos, id);
}

// .text:0x0016B488 size:0x12C mapped:0x807AA51C
void fn_3_16B488(Vec* pos, s8 id) {
    if (pos == NULL) {
        OSErrorLine(284, "Ribbon Effect Pos Data None\n");
    }
    memset(pos, 0, sizeof(Vec));
    if (!fn_8001B728(lbl_3_data_28928._19DC, id, pos)) {
        switch (id) {
        case 28:
            fn_8001B728(lbl_3_data_28928._19DC, 30, pos);
            break;
        case 32:
            fn_8001B728(lbl_3_data_28928._19DC, 34, pos);
            break;
        case 7:
            fn_8001B728(lbl_3_data_28928._19DC, 5, pos);
            break;
        case 18:
            fn_8001B728(lbl_3_data_28928._19DC, 19, pos);
            break;
        case 24:
            fn_8001B728(lbl_3_data_28928._19DC, 25, pos);
            break;
        }
    }
}

// .text:0x0016A07C size:0x140C mapped:0x807A9110
void fn_3_16A07C(void) {
    return;
}

// .text:0x00169E70 size:0x20C mapped:0x807A8F04
void fn_3_169E70(void) {
    return;
}

// .text:0x00169D00 size:0x170 mapped:0x807A8D94
void fn_3_169D00(void) {
    return;
}

// .text:0x00169984 size:0x37C mapped:0x807A8A18
void fn_3_169984(void) {
    return;
}

// .text:0x00169804 size:0x180 mapped:0x807A8898
void fn_3_169804(void) {
    return;
}

// .text:0x00169600 size:0x204 mapped:0x807A8694
void fn_3_169600(void) {
    u32 y;
    u32 x;
    u32 offset;

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            offset = fn_800247E4(x, y, 4, 4);
            if (offset < 32) {
                lbl_3_bss_BAA0[offset + 0] = lbl_3_bss_BAA0[offset + 2] = 255;
                lbl_3_bss_BAA0[offset + 1] = lbl_3_bss_BAA0[offset + 3] = 155;
            } else {
                lbl_3_bss_BAA0[offset + 0] = lbl_3_bss_BAA0[offset + 2] = 0;
                lbl_3_bss_BAA0[offset + 1] = lbl_3_bss_BAA0[offset + 3] = 255;
            }
        }
    }
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            offset = fn_800247E4(x, y, 4, 4);
            if (offset < 32) {
                lbl_3_bss_BA60[offset + 0] = lbl_3_bss_BA60[offset + 2] = 255;
                lbl_3_bss_BA60[offset + 1] = lbl_3_bss_BA60[offset + 3] = 0;
            } else {
                lbl_3_bss_BA60[offset + 0] = lbl_3_bss_BA60[offset + 2] = 155;
                lbl_3_bss_BA60[offset + 1] = lbl_3_bss_BA60[offset + 3] = 255;
            }
        }
    }
    GXInitTexObj(&lbl_3_bss_BA2C, lbl_3_bss_BAA0, 4, 4, GX_TF_RGBA8, GX_REPEAT, GX_REPEAT, GX_FALSE);
    GXInitTexObjLOD(&lbl_3_bss_BA2C, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXInitTexObj(&lbl_3_bss_BA0C, lbl_3_bss_BA60, 4, 4, GX_TF_RGBA8, GX_REPEAT, GX_REPEAT, GX_FALSE);
    GXInitTexObjLOD(&lbl_3_bss_BA0C, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    lbl_3_data_2A330 = -1;
    lbl_3_bss_BA08 = 0;
}

// .text:0x001695A4 size:0x5C mapped:0x807A8638
void fn_3_1695A4(s8 arg0, u8 arg1) {
    if (!arg1) {
        lbl_3_bss_BA00 = lbl_3_bss_BAA0;
        lbl_3_bss_BA04 = &lbl_3_bss_BA2C;
    } else {
        lbl_3_bss_BA00 = lbl_3_bss_BA60;
        lbl_3_bss_BA04 = &lbl_3_bss_BA0C;
    }
    fn_80011604(arg0, fn_3_16917C);
}

// .text:0x001695A0 size:0x4 mapped:0x807A8634
void fn_3_1695A0(void) {}

// .text:0x0016943C size:0x164 mapped:0x807A84D0
void fn_3_16943C(void) {
    int value;
    int i;

    lbl_3_bss_BA08 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_BA08 & 1) == 0) {
        value = lbl_3_bss_BA00[fn_800247E4(0, 0, 4, 4)];
        value += lbl_3_data_2A330 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            lbl_3_bss_BA00[i] = value;
        }
        DCFlushRange(lbl_3_bss_BA00, 4);
        if (value + lbl_3_data_2A330 * 2 > 255 || value + lbl_3_data_2A330 * 2 < 0) {
            lbl_3_data_2A330 *= -1;
        }
    }
}

// .text:0x0016917C size:0x2C0 mapped:0x807A8210
void fn_3_16917C(void* arg0, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* arg4, u8* arg5) {
    int value;
    int i;

    lbl_3_bss_BA08 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_BA08 & 1) == 0) {
        value = lbl_3_bss_BA00[fn_800247E4(0, 0, 4, 4)];
        value += lbl_3_data_2A330 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            lbl_3_bss_BA00[i] = value;
        }
        DCFlushRange(lbl_3_bss_BA00, 4);
        if (value + lbl_3_data_2A330 * 2 > 255 || value + lbl_3_data_2A330 * 2 < 0) {
            lbl_3_data_2A330 *= -1;
        }
    }
    GXLoadTexObj(lbl_3_bss_BA04, *map);
    GXSetTexCoordGen2(*coord, GX_TG_MTX3X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTevOrder(*stage, *coord, *map, GX_COLOR_NULL);
    if (lbl_3_bss_BA00 == lbl_3_bss_BAA0) {
        GXSetTevColorIn(*stage, GX_CC_CPREV, GX_CC_TEXC, GX_CC_TEXA, GX_CC_ZERO);
        GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    } else {
        GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_TEXA, GX_CC_CPREV);
        GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    }
    (*stage)++;
    (*coord)++;
    (*map)++;
    (*arg4)++;
    (*arg5)++;
}
