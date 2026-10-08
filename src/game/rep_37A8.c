#include "game/rep_37A8.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern void fn_800B993C(void);
extern void fn_800B9948(void* callback);
extern void pitchingMachinePitching(u8 id);

f32 lbl_3_data_26698[3] = { 0.5f, 0.0f, -0.5f };
s8 lbl_3_data_266A4 = -1;

// .bss statics, declared in reverse address order (MWCC lays them out last to first)
static u8 lbl_3_bss_B840[0x10];
static u8 lbl_3_bss_B800[0x40] ATTRIBUTE_ALIGN(32);
static s32 lbl_3_bss_B7E4;
static GXTexObj lbl_3_bss_B7C4;
static u8 lbl_3_bss_B7C1;
static u8 lbl_3_bss_B7C0;

static inline u8* GetTexel(s32 x, s32 y, s32 width) {
    return &lbl_3_bss_B800[fn_3_142030(x, y, width)];
}

// .text:0x00147358 size:0x24 mapped:0x807863EC
void fn_3_147358(void) {
    pitchingMachinePitching(0x26);
}

// .text:0x001471C4 size:0x194 mapped:0x80786258
void fn_3_1471C4(void) {
    return;
}

// .text:0x001471C0 size:0x4 mapped:0x80786254
void fn_3_1471C0(void) {
    return;
}

// .text:0x00146A90 size:0x730 mapped:0x80785B24
void fn_3_146A90(void) {
    return;
}

// .text:0x001469CC size:0xC4 mapped:0x80785A60
void fn_3_1469CC(void) {
    return;
}

// .text:0x00146928 size:0xA4 mapped:0x807859BC
void fn_3_146928(void) {
    return;
}

// .text:0x00146408 size:0x520 mapped:0x8078549C
void fn_3_146408(void) {
    return;
}

// .text:0x001461A4 size:0x264 mapped:0x80785238
void fn_3_1461A4(void) {
    return;
}

// .text:0x00145FF4 size:0x1B0 mapped:0x80785088
void fn_3_145FF4(void) {
    return;
}

// .text:0x00145EB8 size:0x13C mapped:0x80784F4C
void fn_3_145EB8(void) {
    return;
}

// .text:0x00145B98 size:0x320 mapped:0x80784C2C
void fn_3_145B98(void) {
    return;
}

// .text:0x00145AD0 size:0xC8 mapped:0x80784B64
void fn_3_145AD0(void) {
    return;
}

// .text:0x001453BC size:0x714 mapped:0x80784450
void fn_3_1453BC(void) {
    return;
}

// .text:0x00144CB8 size:0x704 mapped:0x80783D4C
void fn_3_144CB8(void) {
    return;
}

// .text:0x00144ADC size:0x1DC mapped:0x80783B70
void fn_3_144ADC(void) {
    return;
}

// .text:0x0014471C size:0x3C0 mapped:0x807837B0
void fn_3_14471C(void) {
    return;
}

// .text:0x0014443C size:0x2E0 mapped:0x807834D0
void fn_3_14443C(void) {
    return;
}

// .text:0x0014423C size:0x200 mapped:0x807832D0
void fn_3_14423C(void) {
    return;
}

// .text:0x0014402C size:0x210 mapped:0x807830C0
void fn_3_14402C(void) {
    return;
}

// .text:0x00143FAC size:0x80 mapped:0x80783040
void fn_3_143FAC(void) {
    return;
}

// .text:0x001439EC size:0x5C0 mapped:0x80782A80
void fn_3_1439EC(void) {
    return;
}

// .text:0x00143770 size:0x27C mapped:0x80782804
void fn_3_143770(struct UnkMgEntry3310* entry) {
    return;
}

// .text:0x00143714 size:0x5C mapped:0x807827A8
void fn_3_143714(void) {
    return;
}

// .text:0x00143358 size:0x3BC mapped:0x807823EC
void fn_3_143358(void) {
    return;
}

// .text:0x001430D0 size:0x288 mapped:0x80782164
void fn_3_1430D0(void) {
    return;
}

// .text:0x00142DB4 size:0x31C mapped:0x80781E48
void fn_3_142DB4(void) {
    return;
}

// .text:0x00142CA8 size:0x10C mapped:0x80781D3C
void fn_3_142CA8(void) {
    return;
}

// .text:0x00142C18 size:0x90 mapped:0x80781CAC
void fn_3_142C18(void) {
    return;
}

// .text:0x001428F0 size:0x328 mapped:0x80781984
void fn_3_1428F0(void) {
    return;
}

// .text:0x00142570 size:0x380 mapped:0x80781604
void fn_3_142570(void) {
    return;
}

// .text:0x00142284 size:0x2EC mapped:0x80781318
void fn_3_142284(void) {
    return;
}

// .text:0x0014225C size:0x28 mapped:0x807812F0
void fn_3_14225C(void) {
    fn_800B9948(fn_3_141C8C);
}

// .text:0x00142088 size:0x1D4 mapped:0x8078111C
void fn_3_142088(void) {
    u32 y;
    u32 x;
    u32 offset;

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            offset = fn_3_142030(x, y, 4) * 4;
            if (offset < 32) {
                lbl_3_bss_B800[offset + 0] = lbl_3_bss_B800[offset + 2] = 255;
                lbl_3_bss_B800[offset + 1] = lbl_3_bss_B800[offset + 3] = 150;
            } else {
                lbl_3_bss_B800[offset + 0] = lbl_3_bss_B800[offset + 2] = 0;
                lbl_3_bss_B800[offset + 1] = lbl_3_bss_B800[offset + 3] = 0;
            }
        }
    }
    GXInitTexObj(&lbl_3_bss_B7C4, lbl_3_bss_B800, 4, 4, GX_TF_RGBA8, GX_REPEAT, GX_REPEAT, GX_FALSE);
    GXInitTexObjLOD(&lbl_3_bss_B7C4, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    lbl_3_bss_B7E4 = 0;
    lbl_3_data_266A4 = -1;
    lbl_3_bss_B7C1 = 0;
}

// .text:0x00142030 size:0x58 mapped:0x807810C4
s32 fn_3_142030(s32 x, s32 y, s32 width) {
    return (y / 4) * 4 * width + (x / 4) * 4 * 4 + (y % 4) * 4 + x % 4;
}

// .text:0x00141F30 size:0x100 mapped:0x80780FC4
void fn_3_141F30(void) {
    int value;
    int i;
    u8* tex;

    lbl_3_bss_B7E4 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_B7E4 & 1) == 0) {
        tex = GetTexel(0, 0, 4);
        value = *tex;
        value += lbl_3_data_266A4 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            tex[i] = value;
        }
        DCFlushRange(lbl_3_bss_B800, 0x40);
        if (value + lbl_3_data_266A4 * 2 > 255 || value + lbl_3_data_266A4 * 2 < 0) {
            lbl_3_data_266A4 *= -1;
        }
    }
}

// .text:0x00141C8C size:0x2A4 mapped:0x80780D20
void fn_3_141C8C(void* arg0, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* arg4, u8* arg5) {
    int value;
    int i;
    u8* tex;
    Mtx m;
    Mtx scale;
    Mtx trans;

    lbl_3_bss_B7E4 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_B7E4 & 1) == 0) {
        tex = GetTexel(0, 0, 4);
        value = *tex;
        value += lbl_3_data_266A4 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            tex[i] = value;
        }
        DCFlushRange(lbl_3_bss_B800, 0x40);
        if (value + lbl_3_data_266A4 * 2 > 255 || value + lbl_3_data_266A4 * 2 < 0) {
            lbl_3_data_266A4 *= -1;
        }
    }
    GXLoadTexObj(&lbl_3_bss_B7C4, *map);
    PSMTXIdentity(m);
    PSMTXScale(scale, 0.5f, -0.5f, 0.0f);
    PSMTXTrans(trans, 0.5f, 0.5f, 1.0f);
    PSMTXConcat(trans, scale, scale);
    GXLoadTexMtxImm(m, *map * 3 + GX_TEXMTX0, GX_MTX3x4);
    GXLoadTexMtxImm(scale, *map * 3 + GX_PTTEXMTX0, GX_MTX3x4);
    GXSetTexCoordGen2(*coord, GX_TG_MTX3X4, GX_TG_POS, *map * 3 + GX_TEXMTX0, GX_TRUE, *map * 3 + GX_PTTEXMTX0);
    GXSetTevOrder(*stage, *coord, *map, GX_COLOR_NULL);
    GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_TEXA, GX_CC_CPREV);
    GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    (*stage)++;
    (*coord)++;
    (*map)++;
    (*arg4)++;
    (*arg5)++;
    if (++lbl_3_bss_B7C1 >= 6) {
        lbl_3_bss_B7C1 = 0;
        fn_800B993C();
    }
}

// .text:0x00141C44 size:0x48 mapped:0x80780CD8
void fn_3_141C44(void) {
    if (++lbl_3_bss_B7C1 >= 6) {
        lbl_3_bss_B7C1 = 0;
        fn_800B993C();
    }
}
