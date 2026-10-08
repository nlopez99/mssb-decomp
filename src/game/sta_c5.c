#include "game/sta_c5.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/os.h"
#include "musyx/musyx.h"
#include "string.h"
#include "game/rep_1D58.h"
#include "game/rep_AC8.h"

typedef struct {
    /* 0x00 */ u8 _00[0x60];
    /* 0x60 */ u8 _60;
    /* 0x61 */ u8 _61[0xA4 - 0x61];
    /* 0xA4 */ u8 _A4;
} StaC5Bone;

typedef struct {
    /* 0x00 */ u8 _00[0x06];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x18 - 0x08];
    /* 0x18 */ StaC5Bone** _18;
} StaC5Actor;

typedef struct {
    /* 0x00 */ StaC5Actor* _00;
    /* 0x04 */ u8 _04[0x58 - 0x04];
    /* 0x58 */ u8 _58;
} StaC5Model;

typedef struct StaC5Draw {
    /* 0x00 */ Control control;
    /* 0x44 */ u8 _44[0x74 - 0x44];
    /* 0x74 */ StaC5Model* _74;
    /* 0x78 */ u8 _78[0x90 - 0x78];
    /* 0x90 */ u8 _90_7 : 1;
    /* 0x90 */ u8 _90_6 : 1;
    /* 0x90 */ u8 _90_5 : 1;
    /* 0x90 */ u8 _90_0 : 5;
    /* 0x91 */ u8 _91[0xA0 - 0x91];
    /* 0xA0 */ Vec _A0;
    /* 0xAC */ u8 _AC[0xB4 - 0xAC];
    /* 0xB4 */ f32 _B4;
    /* 0xB8 */ u8 _B8[0xC6 - 0xB8];
    /* 0xC6 */ u8 _C6;
    /* 0xC7 */ u8 _C7;
} StaC5Draw;

typedef struct StadiumSort1D58 {
    /* 0x00 */ f32 depth;
    /* 0x04 */ s32 index;
} StadiumSort1D58; // size: 0x8

extern struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ StadiumSort1D58* _14;
    /* 0x18 */ void (*_18)(void);
    /* 0x1C */ void (*_1C)(void);
    /* 0x20 */ u8 _20[0x30 - 0x20];
    /* 0x30 */ u32 _30;
    /* 0x34 */ void* _34;
    /* 0x38 */ u8 _38[0x64 - 0x38];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66[0x6D - 0x66];
    /* 0x6D */ u8 _6D;
} lbl_3_common_bss_350E4;

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ u8 type;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} StaC5Prop; // size: 0x14

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ u8 type;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ u8 _14;
} StaC5Prop2; // size: 0x18

typedef struct {
    /* 0x00 */ s32 period[3];
    /* 0x0C */ f32 _0C[3];
    /* 0x18 */ f32 _18[3];
} StaC5Flash; // size: 0x24

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
} StaC5Wave; // size: 0xC

typedef struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ void (*_04)(void);
    /* 0x08 */ void* _08;
    /* 0x0C */ void (*_0C)(void);
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} StaC5Callbacks; // size: 0x14

extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];

// The target reaches all of these from one pool base, so they are static
static s32 lbl_3_data_1B820 = -1;
static f32 lbl_3_data_1B824[3][4][2] = {
    { { -33.216f, 75.687f }, { -36.503f, 69.506f }, { -12.026f, 64.419f }, { -15.312f, 58.239f } },
    { { -9.67f, 63.584f }, { -11.425f, 57.847f }, { 16.15f, 55.69f }, { 14.396f, 49.953f } },
    { { 20.255f, 53.422f }, { 16.481f, 58.142f }, { 34.188f, 36.839f }, { 30.415f, 33.538f } },
};
static StaC5Prop lbl_3_data_1B884[6] = {
    { { 32.536f, 4.0f, 100.625f }, -45.0f, 1, 1, 1, 0 },
    { { -32.536f, 4.0f, 100.625f }, 45.0f, 1, 1, 1, 0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 6, 0, 0xFF, 0 },
};
static StaC5Prop lbl_3_data_1B8FC[6] = {
    { { 32.536f, 10.0f, 100.625f }, -45.0f, 0, 1, 1, 0 },
    { { -32.536f, 10.0f, 100.625f }, 45.0f, 0, 1, 1, 0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 6, 0, 0xFF, 0 },
};
static StaC5Flash lbl_3_data_1B974 = { { 15, 10, 2 }, { 1.0f, 1.0f, 1.0f }, { 0.7f, 0.7f, 0.7f } };
static StaC5Wave lbl_3_data_1B998 = { 2, 3.0f, 3.0f };
static StaC5Prop2 lbl_3_data_1B9A4[6] = {
    { { -22.621f, 0.0f, 66.963f }, 0.0f, 2, 1, 1, 0, 0 },
    { { 2.3625f, 0.0f, 56.7685f }, 0.0f, 2, 1, 1, 0, 1 },
    { { 25.3345f, 0.0f, 45.84f }, 0.0f, 2, 1, 1, 0, 2 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 6, 0, 0xFF, 0, 0 },
};
static u8 lbl_3_data_1BA34[18] = { 1, 4, 4, 2, 3, 2, 2, 2, 2, 6, 6, 6, 8, 9, 8, 9, 7, 7 };
static f32 lbl_3_data_1BA48 = 48.0f;
static f32 lbl_3_data_1BA4C[2][2] = { { 3.0f, 0.0f }, { -3.0f, 0.0f } };
static StaC5Callbacks lbl_3_data_1BA5C = { NULL, fn_3_EEE3C, NULL, fn_3_EEE3C, 1, 1, 1, 0 };
static Vec lbl_3_data_1BA70 = { 0.0f, 0.0f, 0.0f };
static Vec lbl_3_data_1BA7C = { 0.0f, 0.0f, 0.0f };

// MWCC lays out .bss statics in reverse declaration order
static s32 lbl_3_bss_B560[4];
static s32 lbl_3_bss_B55C;
static f32 lbl_3_bss_B260[0xBF];
static s32 lbl_3_bss_B244[7];
static u8 lbl_3_bss_B220[0x24];
static u8 lbl_3_bss_B21F;
static u8 lbl_3_bss_B21E;
static u8 lbl_3_bss_B21D;
static u8 lbl_3_bss_B21C;
static u8 lbl_3_bss_B21B;
static u8 lbl_3_bss_B21A;
static u8 lbl_3_bss_B219;
static u8 lbl_3_bss_B218;
static u8 lbl_3_bss_B1BC[0x5C];
static u8 lbl_3_bss_B160[0x5C];
static u8 lbl_3_bss_B15C;
static void* lbl_3_bss_B154[2];
static s32 lbl_3_bss_B118[0xF];
static u8 lbl_3_bss_AF18[0x200];
static f32 lbl_3_bss_AF04[5];
static struct {
    /* 0x00 */ u8 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ u8 _08[0x0C - 0x08];
    /* 0x0C */ void* _0C;
    /* 0x10 */ void* _10;
    /* 0x14 */ void* _14;
    /* 0x18 */ f32 _18;
} lbl_3_bss_AEE8;
static u8 lbl_3_bss_AEE0[8];

// .text:0x000F6FDC size:0x1468 mapped:0x80736070
void fn_3_F6FDC(void) {
    return;
}

// .text:0x000F6FCC size:0x10 mapped:0x80736060
void fn_3_F6FCC(void) {
    lbl_3_bss_AEE8._00 = 1;
}

// .text:0x000F6C60 size:0x36C mapped:0x80735CF4
void fn_3_F6C60(void) {
    return;
}

// .text:0x000F6A94 size:0x1CC mapped:0x80735B28
void fn_3_F6A94(void) {
    return;
}

// .text:0x000F6938 size:0x15C mapped:0x807359CC
void fn_3_F6938(void) {
    return;
}

// .text:0x000F66C8 size:0x270 mapped:0x8073575C
void fn_3_F66C8(void) {
    return;
}

// .text:0x000F65C8 size:0x100 mapped:0x8073565C
void fn_3_F65C8(void) {
    return;
}

// .text:0x000F6504 size:0xC4 mapped:0x80735598
void fn_3_F6504(void) {
    return;
}

// .text:0x000F6084 size:0x480 mapped:0x80735118
void fn_3_F6084(void) {
    return;
}

// .text:0x000F5F4C size:0x138 mapped:0x80734FE0
void fn_3_F5F4C(void) {
    return;
}

// .text:0x000F5F28 size:0x24 mapped:0x80734FBC
s32 fn_3_F5F28(const void* a, const void* b) {
    f32 da = *(const f32*)a;
    f32 db = *(const f32*)b;

    if (da < db) {
        return -1;
    }
    return da > db;
}

// .text:0x000F5EFC size:0x2C mapped:0x80734F90
s32 fn_3_F5EFC(const void* a, const void* b) {
    u32 da = *(const u32*)a;
    u32 db = *(const u32*)b;

    if (da < db) {
        return -1;
    }
    return da > db;
}

// .text:0x000F5E78 size:0x84 mapped:0x80734F0C
s32 fn_3_F5E78(u8 id) {
    u32 i;
    StadiumSort1D58* sort = &lbl_3_common_bss_350E4._14[lbl_3_common_bss_350E4._30];

    for (i = lbl_3_common_bss_350E4._30; i != 0; i--) {
        if (id == sort[-1].index) {
            return i - 1;
        }
        sort--;
    }
    OSPanic("sta_c5.c", 0x637, "//OZ \x96\xDF\x82\xE8\x92\x6C\x82\xAA\x82\xA0\x82\xE8\x82\xDC\x82\xB9\x82\xF1\n");
    return 0;
}

// .text:0x000F5C30 size:0x248 mapped:0x80734CC4
void fn_3_F5C30(void) {
    return;
}

// .text:0x000F56CC size:0x564 mapped:0x80734760
void fn_3_F56CC(void) {
    return;
}

// .text:0x000F4FBC size:0x710 mapped:0x80734050
void fn_3_F4FBC(void) {
    return;
}

// .text:0x000F4DAC size:0x210 mapped:0x80733E40
void fn_3_F4DAC(void) {
    return;
}

// .text:0x000F4D00 size:0xAC mapped:0x80733D94
void fn_3_F4D00(void) {
    return;
}

// .text:0x000F4C4C size:0xB4 mapped:0x80733CE0
void fn_3_F4C4C(void) {
    return;
}

// .text:0x000F4BA0 size:0xAC mapped:0x80733C34
void fn_3_F4BA0(void) {
    return;
}

// .text:0x000F46A0 size:0x500 mapped:0x80733734
void fn_3_F46A0(void) {
    return;
}

// .text:0x000F469C size:0x4 mapped:0x80733730
void fn_3_F469C(void) {
    return;
}

// .text:0x000F466C size:0x30 mapped:0x80733700
void fn_3_F466C(void) {
    fn_3_27648();
    g_FieldingLogic._13B = 1;
}

// .text:0x000F42A0 size:0x3CC mapped:0x80733334
void fn_3_F42A0(void) {
    return;
}

// .text:0x000F3EFC size:0x3A4 mapped:0x80732F90
void fn_3_F3EFC(void) {
    return;
}

// .text:0x000F3CD0 size:0x22C mapped:0x80732D64
void fn_3_F3CD0(void) {
    return;
}

// .text:0x000F3BB0 size:0x120 mapped:0x80732C44
void fn_3_F3BB0(void) {
    return;
}

// .text:0x000F3AE0 size:0xD0 mapped:0x80732B74
void fn_3_F3AE0(void) {
    return;
}

// .text:0x000F3A5C size:0x84 mapped:0x80732AF0
void fn_3_F3A5C(StaC5Draw* draw, f32 x, f32 y, f32 z, f32 rotY) {
    draw->_A0.x = x;
    draw->_A0.y = y;
    draw->_A0.z = z;
    draw->_B4 = rotY;
    draw->control.type = 0;
    CTRLSetTranslation(&draw->control, draw->_A0.x, -draw->_A0.y, draw->_A0.z);
    CTRLSetRotation(&draw->control, 0.0f, rotY, 0.0f);
}

// .text:0x000F3A04 size:0x58 mapped:0x80732A98
void fn_3_F3A04(StaC5Draw* draw) {
    u32 i;
    StaC5Actor* actor = draw->_74->_00;

    for (i = 0; i < actor->_06; i++) {
    }
}

// .text:0x000F38D4 size:0x130 mapped:0x80732968
void fn_3_F38D4(void) {
    return;
}

// .text:0x000F37BC size:0x118 mapped:0x80732850
void fn_3_F37BC(void) {
    return;
}

// .text:0x000F31E0 size:0x5DC mapped:0x80732274
void fn_3_F31E0(void) {
    return;
}

// .text:0x000F2FFC size:0x1E4 mapped:0x80732090
void fn_3_F2FFC(void) {
    return;
}

// .text:0x000F2938 size:0x6C4 mapped:0x807319CC
void fn_3_F2938(void) {
    return;
}

// .text:0x000F2724 size:0x214 mapped:0x807317B8
void fn_3_F2724(void) {
    return;
}

// .text:0x000F2448 size:0x2DC mapped:0x807314DC
void fn_3_F2448(void) {
    return;
}

// .text:0x000F22FC size:0x14C mapped:0x80731390
void fn_3_F22FC(void) {
    return;
}

// .text:0x000F1E2C size:0x4D0 mapped:0x80730EC0
void fn_3_F1E2C(void) {
    return;
}

// .text:0x000F193C size:0x4F0 mapped:0x807309D0
void fn_3_F193C(void) {
    return;
}

// .text:0x000F18A4 size:0x98 mapped:0x80730938
void fn_3_F18A4(void) {
    return;
}

// .text:0x000F1750 size:0x154 mapped:0x807307E4
void fn_3_F1750(void) {
    return;
}

// .text:0x000F1674 size:0xDC mapped:0x80730708
void fn_3_F1674(void) {
    return;
}

// .text:0x000F1518 size:0x15C mapped:0x807305AC
void fn_3_F1518(void) {
    return;
}

// .text:0x000F1448 size:0xD0 mapped:0x807304DC
void fn_3_F1448(void) {
    return;
}

// .text:0x000F13F8 size:0x50 mapped:0x8073048C
void fn_3_F13F8(StaC5Draw* draw) {
    StaC5Actor* actor = draw->_74->_00;
    u32 i;

    for (i = 0; i < actor->_06; i++) {
        StaC5Bone* bone = actor->_18[i];
        bone->_60 = 0;
        bone->_A4 = 0;
    }
    draw->_74->_58 = 0;
}

// .text:0x000F0FA4 size:0x454 mapped:0x80730038
void fn_3_F0FA4(void) {
    return;
}

// .text:0x000F082C size:0x778 mapped:0x8072F8C0
void fn_3_F082C(void) {
    return;
}

// .text:0x000F0224 size:0x608 mapped:0x8072F2B8
void fn_3_F0224(void) {
    return;
}

// .text:0x000F0184 size:0xA0 mapped:0x8072F218
void fn_3_F0184(void) {
    return;
}

// .text:0x000EFB54 size:0x630 mapped:0x8072EBE8
void fn_3_EFB54(void) {
    return;
}

// .text:0x000EF930 size:0x224 mapped:0x8072E9C4
void fn_3_EF930(void) {
    return;
}

// .text:0x000EF890 size:0xA0 mapped:0x8072E924
void fn_3_EF890(void) {
    return;
}

// .text:0x000EF800 size:0x90 mapped:0x8072E894
void fn_3_EF800(StaC5Draw* draw) {
    if (draw->_C7 == 0) {
        CTRLSetTranslation(&draw->control, draw->_A0.x, 100.0f, draw->_A0.z);
    } else {
        if (draw->_C7 % 6 == 0) {
            draw->_90_7 = 0;
        } else {
            draw->_90_7 = 1;
        }
        draw->_C7--;
    }
}

// .text:0x000EF7B4 size:0x4C mapped:0x8072E848
void fn_3_EF7B4(void) {
    return;
}

// .text:0x000EF55C size:0x258 mapped:0x8072E5F0
void fn_3_EF55C(void) {
    return;
}

// .text:0x000EF408 size:0x154 mapped:0x8072E49C
void fn_3_EF408(void) {
    return;
}

// .text:0x000EF3D4 size:0x34 mapped:0x8072E468
void fn_3_EF3D4(StaC5Draw* draw, u8 idx) {
    fn_3_B97DC(draw->_74, lbl_3_bss_B154[idx]);
}

// .text:0x000EF21C size:0x1B8 mapped:0x8072E2B0
void fn_3_EF21C(void) {
    return;
}

// .text:0x000EF218 size:0x4 mapped:0x8072E2AC
void fn_3_EF218(void) {
    return;
}

// .text:0x000EEFD4 size:0x244 mapped:0x8072E068
void fn_3_EEFD4(void) {
    return;
}

// .text:0x000EEFD0 size:0x4 mapped:0x8072E064
void fn_3_EEFD0(void) {
    return;
}

// .text:0x000EEFA4 size:0x2C mapped:0x8072E038
void fn_3_EEFA4(void) {
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
}

// .text:0x000EEF24 size:0x80 mapped:0x8072DFB8
void fn_3_EEF24(void) {
    return;
}

// .text:0x000EEE3C size:0xE8 mapped:0x8072DED0
void fn_3_EEE3C(void) {
    return;
}

// .text:0x000EECF4 size:0x148 mapped:0x8072DD88
void fn_3_EECF4(void) {
    return;
}

// .text:0x000EEB94 size:0x160 mapped:0x8072DC28
void fn_3_EEB94(void) {
    return;
}

// .text:0x000EE96C size:0x228 mapped:0x8072DA00
void fn_3_EE96C(void) {
    return;
}

// .text:0x000EE67C size:0x2F0 mapped:0x8072D710
void fn_3_EE67C(void) {
    return;
}

// .text:0x000EE388 size:0x2F4 mapped:0x8072D41C
void fn_3_EE388(void) {
    return;
}

// .text:0x000EE100 size:0x288 mapped:0x8072D194
void fn_3_EE100(void) {
    return;
}

// .text:0x000EE0BC size:0x44 mapped:0x8072D150
s32 fn_3_EE0BC(u32 flags) {
    switch ((flags >> 4) & 0xF) {
    case 0:
    case 1:
        return 1;
    case 2:
    case 3:
        return 2;
    case 4:
        return 4;
    default:
        return 0;
    }
}

// .text:0x000EDFAC size:0x110 mapped:0x8072D040
void fn_3_EDFAC(void) {
    return;
}
