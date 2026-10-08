#include "game/sta_c2.h"
#include "header_rep_data.h"
#include "Dolphin/mtx.h"
#include "musyx/musyx.h"

typedef struct StaC2Place {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
} StaC2Place; // size: 0x10

typedef struct StaC2Place1C {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
} StaC2Place1C; // size: 0x1C

typedef struct StaC2Place20 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ Vec scale;
    /* 0x1C */ f32 rotY;
} StaC2Place20; // size: 0x20

typedef struct StaC2Place34 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ u8 _30;
} StaC2Place34; // size: 0x34

typedef struct StaC2Swing {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ f32 _10;
    /* 0x14 */ Vec scale;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ f32 _30;
} StaC2Swing; // size: 0x34

typedef struct StaC2Rec5C {
    /* 0x00 */ u8 _00[0x5C];
} StaC2Rec5C; // size: 0x5C

// fn_3_D67CC reads these from one pool base, so they are static
static SND_VOICEID lbl_3_data_182C0 = -1;
static SND_VOICEID lbl_3_data_182C4 = -1;
static StaC2Place34 lbl_3_data_182C8[3] = {
    { { 55.0f, 0.0f, 40.0f }, 0, 1, 1, 0, 0.0f, 180.0f, 0.0f, 0.0f, 180.0f, 0.0f, 160.0f, 120.0f, 1 },
    { { -55.0f, 0.0f, 40.0f }, 0, 1, 2, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 290.0f, 100.0f, 0 },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0 },
};
static StaC2Swing lbl_3_data_18364[6] = {
    { { 28.5f, 7.0f, 37.5f }, 3, 1, 1, 0, 30.0f, { 1.0f, 1.0f, 1.0f }, -60.0f, 45.0f, 60.0f, 10.0f, 4.0f },
    { { -28.5f, 7.0f, 37.5f }, 3, 1, 3, 0, 330.0f, { 1.0f, 1.0f, 1.0f }, -60.0f, -10.0f, 60.0f, -45.0f, 4.0f },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0, 0.0f, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
StaC2Place1C lbl_3_data_1849C[11] = {
    { { 0.0f, -5.0f, 40.0f }, 6, 1, 1, 0, 10.0f, 0.0f, 360.0f },
    { { 20.0f, -5.0f, 40.0f }, 6, 1, 2, 0, 10.0f, 0.0f, 360.0f },
    { { -20.0f, -5.0f, 40.0f }, 6, 1, 3, 0, 10.0f, 0.0f, 360.0f },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0, 0.0f, 0.0f, 0.0f },
};
static StaC2Place20 lbl_3_data_185D0[11] = {
    { { 37.4f, 0.0f, 8.0f }, 7, 1, 1, 0, { 1.0f, 1.0f, 1.0f }, -35.0f },
    { { 22.5f, 0.0f, -7.3f }, 7, 1, 1, 0, { 1.0f, 1.0f, 1.0f }, -25.0f },
    { { -22.5f, 0.0f, -7.3f }, 7, 1, 1, 0, { 1.0f, 1.0f, 1.0f }, 20.0f },
    { { -37.4f, 0.0f, 8.0f }, 7, 1, 1, 0, { 1.0f, 1.0f, 1.0f }, 0.0f },
    { { -43.34f, -3.6f, 87.797f }, 7, 1, 1, 0, { 1.0f, 0.85f, 1.0f }, -25.0f },
    { { -32.055f, -3.6f, 101.771f }, 7, 1, 1, 0, { 1.0f, 0.8f, 1.0f }, -15.0f },
    { { 31.884f, -3.6f, 101.246f }, 7, 1, 1, 0, { 1.0f, 0.8f, 1.0f }, 20.0f },
    { { 43.626f, -3.6f, 87.915f }, 7, 1, 1, 0, { 1.0f, 0.88f, 1.0f }, 25.0f },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
static StaC2Place lbl_3_data_18730[11] = {
    { { 0.0f, 0.15f, 60.0f }, 8, 1, 1, 0 },
    { { 20.0f, 0.15f, 60.0f }, 8, 1, 2, 0 },
    { { -20.0f, 0.15f, 60.0f }, 8, 1, 3, 0 },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0 },
};
static StaC2Place lbl_3_data_187E0[11] = {
    { { 0.0f, 0.0f, 0.0f }, 11, 1, 1, 0 },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0 },
};
StaC2Place34 lbl_3_data_18890 = { { 0.0f, 0.0f, 10.0f }, 0, 1, 1, 0, 0.0f, -90.0f, 0.0f, 30.0f, -120.0f, 0.0f, 0.0f, 360.0f, 0 };
static u8 lbl_3_data_188C4[0x1A] = {
    1, 2, 2, 4, 2, 2, 2, 2, 4, 2, 2, 2, 2, 6, 6, 8, 8, 9, 8, 9, 8, 8, 8, 9, 0, 0,
};
f32 lbl_3_data_188E0 = 0.1f;

// MWCC lays out .bss statics in reverse order of declaration
static u8 lbl_3_bss_ADD0[0x30];
static u8 lbl_3_bss_ABD0[0x200];
static u8 lbl_3_bss_A9D0[0x200];
static u8 lbl_3_bss_A8D0[0x100];
static f32 lbl_3_bss_A8A8[10];
static s32 lbl_3_bss_A8A4;
static u8 lbl_3_bss_A898[0xC];
static f32 lbl_3_bss_A820[30];
static u8 lbl_3_bss_A81C;
static StaC2Rec5C lbl_3_bss_A764[2];
static StaC2Rec5C lbl_3_bss_A3CC[10];
static StaC2Rec5C lbl_3_bss_A034[10];
static f32 lbl_3_bss_A030;
static u8 lbl_3_bss_A02D;
static u8 lbl_3_bss_A02C;
static u8 lbl_3_bss_A02B;
static u8 lbl_3_bss_A02A;
static u8 lbl_3_bss_A029;
static u8 lbl_3_bss_A028;
static u8 lbl_3_bss_A027;
static u8 lbl_3_bss_A026;
static u8 lbl_3_bss_A025;
static u8 lbl_3_bss_A024;
static u8 lbl_3_bss_A023;
static u8 lbl_3_bss_A022;
static u8 lbl_3_bss_A021;
static u8 lbl_3_bss_A020;
static s32 lbl_3_bss_A01C;
static u8 lbl_3_bss_A018;

// .text:0x000D67CC size:0x2244 mapped:0x80715860
void fn_3_D67CC(void) {
    return;
}

// .text:0x000D6514 size:0x2B8 mapped:0x807155A8
void fn_3_D6514(void) {
    return;
}

// .text:0x000D62F0 size:0x224 mapped:0x80715384
void fn_3_D62F0(void) {
    return;
}

// .text:0x000D60C0 size:0x230 mapped:0x80715154
void fn_3_D60C0(void) {
    return;
}

// .text:0x000D5E80 size:0x240 mapped:0x80714F14
void fn_3_D5E80(void) {
    return;
}

// .text:0x000D5C8C size:0x1F4 mapped:0x80714D20
void fn_3_D5C8C(void) {
    return;
}

// .text:0x000D5B6C size:0x120 mapped:0x80714C00
void fn_3_D5B6C(void) {
    return;
}

// .text:0x000D55EC size:0x580 mapped:0x80714680
void fn_3_D55EC(void) {
    return;
}

// .text:0x000D5494 size:0x158 mapped:0x80714528
void fn_3_D5494(void) {
    return;
}

// .text:0x000D5470 size:0x24 mapped:0x80714504
void fn_3_D5470(void) {
    return;
}

// .text:0x000D5444 size:0x2C mapped:0x807144D8
void fn_3_D5444(void) {
    return;
}

// .text:0x000D53C0 size:0x84 mapped:0x80714454
void fn_3_D53C0(void) {
    return;
}

// .text:0x000D511C size:0x2A4 mapped:0x807141B0
void fn_3_D511C(void) {
    return;
}

// .text:0x000D501C size:0x100 mapped:0x807140B0
void fn_3_D501C(void) {
    return;
}

// .text:0x000D4E00 size:0x21C mapped:0x80713E94
void fn_3_D4E00(void) {
    return;
}

// .text:0x000D4CA4 size:0x15C mapped:0x80713D38
void fn_3_D4CA4(void) {
    return;
}

// .text:0x000D4780 size:0x524 mapped:0x80713814
void fn_3_D4780(void) {
    return;
}

// .text:0x000D3F54 size:0x82C mapped:0x80712FE8
void fn_3_D3F54(void) {
    return;
}

// .text:0x000D3CDC size:0x278 mapped:0x80712D70
void fn_3_D3CDC(void) {
    return;
}

// .text:0x000D3880 size:0x45C mapped:0x80712914
void fn_3_D3880(void) {
    return;
}

// .text:0x000D36B0 size:0x1D0 mapped:0x80712744
void fn_3_D36B0(void) {
    return;
}

// .text:0x000D30D0 size:0x5E0 mapped:0x80712164
void fn_3_D30D0(void) {
    return;
}

// .text:0x000D2A0C size:0x6C4 mapped:0x80711AA0
void fn_3_D2A0C(void) {
    return;
}

// .text:0x000D278C size:0x280 mapped:0x80711820
void fn_3_D278C(void) {
    return;
}

// .text:0x000D2684 size:0x108 mapped:0x80711718
void fn_3_D2684(void) {
    return;
}

// .text:0x000D255C size:0x128 mapped:0x807115F0
void fn_3_D255C(void) {
    return;
}

// .text:0x000D24E8 size:0x74 mapped:0x8071157C
void fn_3_D24E8(void) {
    return;
}

// .text:0x000D249C size:0x4C mapped:0x80711530
void fn_3_D249C(void) {
    return;
}

// .text:0x000D233C size:0x160 mapped:0x807113D0
void fn_3_D233C(void) {
    return;
}

// .text:0x000D2220 size:0x11C mapped:0x807112B4
void fn_3_D2220(void) {
    return;
}

// .text:0x000D1F2C size:0x2F4 mapped:0x80710FC0
void fn_3_D1F2C(void) {
    return;
}

// .text:0x000D1B24 size:0x408 mapped:0x80710BB8
void fn_3_D1B24(void) {
    return;
}

// .text:0x000D1AC4 size:0x60 mapped:0x80710B58
void fn_3_D1AC4(void) {
    return;
}

// .text:0x000D196C size:0x158 mapped:0x80710A00
void fn_3_D196C(void) {
    return;
}

// .text:0x000D1848 size:0x124 mapped:0x807108DC
void fn_3_D1848(void) {
    return;
}

// .text:0x000D173C size:0x10C mapped:0x807107D0
void fn_3_D173C(void) {
    return;
}

// .text:0x000D141C size:0x320 mapped:0x807104B0
void fn_3_D141C(void) {
    return;
}

// .text:0x000D1280 size:0x19C mapped:0x80710314
void fn_3_D1280(void) {
    return;
}

// .text:0x000D127C size:0x4 mapped:0x80710310
void fn_3_D127C(void) {
    return;
}

// .text:0x000D1110 size:0x16C mapped:0x807101A4
void fn_3_D1110(void) {
    return;
}

// .text:0x000D1004 size:0x10C mapped:0x80710098
void fn_3_D1004(void) {
    return;
}

// .text:0x000D0918 size:0x6EC mapped:0x8070F9AC
void fn_3_D0918(void) {
    return;
}

// .text:0x000D0854 size:0xC4 mapped:0x8070F8E8
void fn_3_D0854(void) {
    return;
}

// .text:0x000D0534 size:0x320 mapped:0x8070F5C8
void fn_3_D0534(void) {
    return;
}

// .text:0x000D052C size:0x8 mapped:0x8070F5C0
void fn_3_D052C(void) {
    return;
}

// .text:0x000D0528 size:0x4 mapped:0x8070F5BC
void fn_3_D0528(void) {
    return;
}

// .text:0x000D0490 size:0x98 mapped:0x8070F524
void fn_3_D0490(void) {
    return;
}

// .text:0x000D0284 size:0x20C mapped:0x8070F318
void fn_3_D0284(void) {
    return;
}

// .text:0x000D0280 size:0x4 mapped:0x8070F314
void fn_3_D0280(void) {
    return;
}

// .text:0x000D00D0 size:0x1B0 mapped:0x8070F164
void fn_3_D00D0(void) {
    return;
}

// .text:0x000D00CC size:0x4 mapped:0x8070F160
void fn_3_D00CC(void) {
    return;
}

// .text:0x000CFD58 size:0x374 mapped:0x8070EDEC
void fn_3_CFD58(void) {
    return;
}

// .text:0x000CFB44 size:0x214 mapped:0x8070EBD8
void fn_3_CFB44(void) {
    return;
}

// .text:0x000CFAB4 size:0x90 mapped:0x8070EB48
void fn_3_CFAB4(void) {
    return;
}

// .text:0x000CFA8C size:0x28 mapped:0x8070EB20
void fn_3_CFA8C(void) {
    return;
}

// .text:0x000CFA88 size:0x4 mapped:0x8070EB1C
void fn_3_CFA88(void) {
    return;
}

// .text:0x000CF930 size:0x158 mapped:0x8070E9C4
void fn_3_CF930(void) {
    return;
}

// .text:0x000CF92C size:0x4 mapped:0x8070E9C0
void fn_3_CF92C(void) {
    return;
}

// .text:0x000CF72C size:0x200 mapped:0x8070E7C0
void fn_3_CF72C(void) {
    return;
}

// .text:0x000CF278 size:0x4B4 mapped:0x8070E30C
void fn_3_CF278(void) {
    return;
}

// .text:0x000CEFA8 size:0x2D0 mapped:0x8070E03C
void fn_3_CEFA8(void) {
    return;
}

// .text:0x000CEE5C size:0x14C mapped:0x8070DEF0
void fn_3_CEE5C(void) {
    return;
}

// .text:0x000CED40 size:0x11C mapped:0x8070DDD4
void fn_3_CED40(void) {
    return;
}

// .text:0x000CED3C size:0x4 mapped:0x8070DDD0
void fn_3_CED3C(void) {
    return;
}

// .text:0x000CED38 size:0x4 mapped:0x8070DDCC
void fn_3_CED38(void) {
    return;
}

// .text:0x000CED34 size:0x4 mapped:0x8070DDC8
void fn_3_CED34(void) {
    return;
}

// .text:0x000CED30 size:0x4 mapped:0x8070DDC4
void fn_3_CED30(void) {
    return;
}

// .text:0x000CEC98 size:0x98 mapped:0x8070DD2C
void fn_3_CEC98(void) {
    return;
}

// .text:0x000CEBBC size:0xDC mapped:0x8070DC50
void fn_3_CEBBC(void) {
    return;
}

// .text:0x000CE954 size:0x268 mapped:0x8070D9E8
void fn_3_CE954(void) {
    return;
}

// .text:0x000CE8E4 size:0x70 mapped:0x8070D978
void fn_3_CE8E4(void) {
    return;
}

// .text:0x000CE56C size:0x378 mapped:0x8070D600
void fn_3_CE56C(void) {
    return;
}

// .text:0x000CDFA4 size:0x5C8 mapped:0x8070D038
void fn_3_CDFA4(void) {
    return;
}

// .text:0x000CDD90 size:0x214 mapped:0x8070CE24
void fn_3_CDD90(void) {
    return;
}

// .text:0x000CDB48 size:0x248 mapped:0x8070CBDC
void fn_3_CDB48(void) {
    return;
}

// .text:0x000CD968 size:0x1E0 mapped:0x8070C9FC
void fn_3_CD968(void) {
    return;
}

// .text:0x000CD958 size:0x10 mapped:0x8070C9EC
void fn_3_CD958(void) {
    return;
}

// .text:0x000CCC24 size:0xD34 mapped:0x8070BCB8
void fn_3_CCC24(void) {
    return;
}

// .text:0x000CC81C size:0x408 mapped:0x8070B8B0
void fn_3_CC81C(void) {
    return;
}

// .text:0x000CC5C4 size:0x258 mapped:0x8070B658
void fn_3_CC5C4(void) {
    return;
}

// .text:0x000CC438 size:0x18C mapped:0x8070B4CC
void fn_3_CC438(void) {
    return;
}

// .text:0x000CC354 size:0xE4 mapped:0x8070B3E8
void fn_3_CC354(void) {
    return;
}

// .text:0x000CC1D4 size:0x180 mapped:0x8070B268
void fn_3_CC1D4(void) {
    return;
}

// .text:0x000CBF80 size:0x254 mapped:0x8070B014
void fn_3_CBF80(void) {
    return;
}

// .text:0x000CBC18 size:0x368 mapped:0x8070ACAC
void fn_3_CBC18(void) {
    return;
}

// .text:0x000CBAFC size:0x11C mapped:0x8070AB90
void fn_3_CBAFC(void) {
    return;
}

// .text:0x000CBA9C size:0x60 mapped:0x8070AB30
void fn_3_CBA9C(void) {
    return;
}

// .text:0x000CB8A8 size:0x1F4 mapped:0x8070A93C
void fn_3_CB8A8(void) {
    return;
}
