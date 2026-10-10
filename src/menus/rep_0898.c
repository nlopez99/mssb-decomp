#include "header_rep_data.h"
#include "menus/rep_0898.h"
#include "menus/rep_0840.h"
#include "menus/rep_08E8.h"
#include "menus/rep_09B8.h"
#include "menus/rep_0B08.h"
#include "string.h"

typedef struct MenuTask0898 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct MenuTask0898* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x16 - 0x12];
    /* 0x16 */ s16 _16;
    /* 0x18 */ u8 _18[0x28 - 0x18];
    /* 0x28 */ s8 _28;
} MenuTask0898;

extern void* lbl_803CC1B8;

extern struct {
    /* 0x000000 */ u8 _000000[0x197684];
    /* 0x197684 */ s32* _197684;
    /* 0x197688 */ s32 _197688;
    /* 0x19768C */ s32 _19768C;
    /* 0x197690 */ s32 _197690;
    /* 0x197694 */ s32 _197694;
    /* 0x197698 */ u8 _197698[0x1976E4 - 0x197698];
    /* 0x1976E4 */ s16 _1976E4;
    /* 0x1976E6 */ u8 _1976E6[0x197740 - 0x1976E6];
    /* 0x197740 */ s16 _197740;
    /* 0x197742 */ u8 _197742[0x19774C - 0x197742];
    /* 0x19774C */ s16 _19774C;
    /* 0x19774E */ s16 _19774E;
    /* 0x197750 */ u8 _197750[0x19783D - 0x197750];
    /* 0x19783D */ u8 _19783D;
    /* 0x19783E */ u8 _19783E;
    /* 0x19783F */ u8 _19783F;
    /* 0x197840 */ u8 _197840[0x197844 - 0x197840];
    /* 0x197844 */ u8 _197844;
    /* 0x197845 */ u8 _197845[0x197857 - 0x197845];
    /* 0x197857 */ s8 _197857;
    /* 0x197858 */ u8 _197858;
    /* 0x197859 */ u8 _197859;
    /* 0x19785A */ u8 _19785A[0x1978C7 - 0x19785A];
    /* 0x1978C7 */ s8 _1978C7[20];
    /* 0x1978DB */ s8 _1978DB[20];
    /* 0x1978EF */ s8 _1978EF;
} *lbl_2_bss_1A824C;

extern struct {
    /* 0x0000 */ u8 _0000[0x16BE];
    /* 0x16BE */ s16 _16BE;
    /* 0x16C0 */ s16 _16C0;
    /* 0x16C2 */ s16 _16C2;
    /* 0x16C4 */ u8 _16C4[0x43BE - 0x16C4];
    /* 0x43BE */ s16 _43BE;
    /* 0x43C0 */ u8 _43C0[0x43C2 - 0x43C0];
    /* 0x43C2 */ s8 _43C2[20];
    /* 0x43D6 */ u8 _43D6[0x441C - 0x43D6];
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ u8 _441F[0x4426 - 0x441F];
    /* 0x4426 */ u8 _4426;
    /* 0x4427 */ u8 _4427;
    /* 0x4428 */ u8 _4428[0x442C - 0x4428];
    /* 0x442C */ u8 _442C;
    /* 0x442D */ u8 _442D;
    /* 0x442E */ u8 _442E;
    /* 0x442F */ u8 _442F[0x44EF - 0x442F];
    /* 0x44EF */ s8 _44EF;
    /* 0x44F0 */ s8 _44F0;
    /* 0x44F1 */ u8 _44F1[0x44FE - 0x44F1];
    /* 0x44FE */ s8 _44FE[6];
    /* 0x4504 */ s8 _4504;
} *lbl_2_bss_1A8248;

extern struct {
    /* 0x00 */ u8 _00[0x30];
    /* 0x30 */ s16 _30;
} *lbl_2_bss_1A823C;

extern struct {
    /* 0x000000 */ u8 _000000[0x16264B];
    /* 0x16264B */ u8 _16264B;
    /* 0x16264C */ u8 _16264C;
    /* 0x16264D */ u8 _16264D;
    /* 0x16264E */ u8 _16264E;
    /* 0x16264F */ u8 _16264F;
    /* 0x162650 */ u8 _162650[0x162838 - 0x162650];
    /* 0x162838 */ u8 _162838;
    /* 0x162839 */ u8 _162839;
    /* 0x16283A */ u8 _16283A[0x162871 - 0x16283A];
    /* 0x162871 */ u8 _162871;
    /* 0x162872 */ u8 _162872;
} *lbl_2_bss_1A8234;

extern s16 lbl_2_data_36EC[20];

extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);

extern void fn_2_37F04(void);
extern void fn_2_38538(void);
extern void fn_2_38A40(void);

// .data:0x000124A8 size:0xB0
u32 lbl_2_data_124A8[44] = {
    0x00000001, 0x00000042, 0x00000001, 0x00000043,
    0x00000042, 0x00000002, 0x00000044, 0x00000064,
    0x0000003F, 0x0000039E, 0x00000044, 0x0000014A,
    0x00000040, 0x00000044, 0x000002BC, 0x0000003F,
    0x0000039F, 0x00000043, 0x00000040, 0x00000045,
    0x00000003, 0x00000050, 0x00000041, 0x000003A0,
    0x00000003, 0x00000050, 0x00000055, 0x00000003,
    0x00000001, 0x00000041, 0x000003A1, 0x00000003,
    0x00000050, 0x00000055, 0x00000003, 0x00000001,
    0x00000041, 0x000003A2, 0x00000003, 0x00000078,
    0x00000055, 0x00000003, 0x00000001, 0x00000002,
};

// .data:0x00012558 size:0xC0
u32 lbl_2_data_12558[48] = {
    0x00000001, 0x00000042, 0x00000001, 0x00000043,
    0x00000042, 0x00000002, 0x00000044, 0x00000064,
    0x0000003F, 0x000003A8, 0x00000044, 0x0000014A,
    0x00000040, 0x00000044, 0x000002BC, 0x00000003,
    0x00000050, 0x0000003F, 0x000003A9, 0x00000003,
    0x00000050, 0x00000043, 0x00000040, 0x00000045,
    0x00000003, 0x00000050, 0x00000041, 0x000003AA,
    0x00000003, 0x0000003C, 0x00000055, 0x00000003,
    0x00000001, 0x00000041, 0x000003AB, 0x00000003,
    0x0000003C, 0x00000055, 0x00000003, 0x00000001,
    0x00000041, 0x000003AC, 0x00000003, 0x0000003C,
    0x00000055, 0x00000003, 0x00000001, 0x00000002,
};

// .data:0x00012618 size:0x10
u32 lbl_2_data_12618[4] = {
    0x00000001, 0x0000001B, 0x00000006, 0x00000002,
};

// .data:0x00012628 size:0x10
u32 lbl_2_data_12628[4] = {
    0x00000001, 0x0000001E, 0x00000006, 0x00000002,
};

// .data:0x00012638 size:0x8
u32 lbl_2_data_12638[2] = {
    0x00000001, 0x00000002,
};

// .data:0x00012640 size:0x48
u32 lbl_2_data_12640[18] = {
    0x00000001, 0x00000009, 0x0000000A, 0x0000001C,
    0x00000006, 0x00000031, 0x00000032, 0x00000056,
    0x00000057, 0x0000006A, 0x00000068, 0x00000069,
    0x00000058, 0x00000059, 0x0000006C, 0x0000006D,
    0x0000004A, 0x00000002,
};

// .data:0x00012688 size:0x48
u32 lbl_2_data_12688[18] = {
    0x00000001, 0x00000009, 0x0000000A, 0x0000001C,
    0x00000006, 0x00000031, 0x00000032, 0x00000060,
    0x00000061, 0x0000006A, 0x00000068, 0x00000069,
    0x00000058, 0x00000059, 0x0000006C, 0x0000006D,
    0x0000004A, 0x00000002,
};

// .data:0x000126D0 size:0x38
u32 lbl_2_data_126D0[14] = {
    0x00000001, 0x0000001D, 0x00000006, 0x00000033,
    0x00000034, 0x0000006A, 0x00000068, 0x00000069,
    0x00000058, 0x00000059, 0x0000006C, 0x0000006D,
    0x0000004A, 0x00000002,
};

// .data:0x00012708 size:0x38
u32 lbl_2_data_12708[14] = {
    0x00000001, 0x00000048, 0x00000006, 0x00000035,
    0x00000036, 0x0000006A, 0x00000068, 0x00000069,
    0x00000058, 0x00000059, 0x0000006C, 0x0000006D,
    0x0000004A, 0x00000002,
};

// .data:0x00012740 size:0x44
u32 lbl_2_data_12740[17] = {
    0x00000001, 0x0000001F, 0x00000006, 0x00000013,
    0x00000014, 0x0000006B, 0x0000006A, 0x00000068,
    0x00000069, 0x00000058, 0x00000059, 0x0000006C,
    0x0000006D, 0x00000015, 0x00000016, 0x0000004B,
    0x00000002,
};

// .data:0x00012784 size:0x40
u32 lbl_2_data_12784[16] = {
    0x00000001, 0x00000020, 0x00000006, 0x00000013,
    0x00000014, 0x0000006A, 0x00000068, 0x00000069,
    0x00000058, 0x00000059, 0x0000006C, 0x0000006D,
    0x00000015, 0x00000016, 0x0000004B, 0x00000002,
};

// .data:0x000127C4 size:0x40
u32 lbl_2_data_127C4[16] = {
    0x00000001, 0x00000049, 0x00000006, 0x00000013,
    0x00000014, 0x0000006A, 0x00000068, 0x00000069,
    0x00000058, 0x00000059, 0x0000006C, 0x0000006D,
    0x00000015, 0x00000016, 0x0000004B, 0x00000002,
};

// .data:0x00012804 size:0x38
u32 lbl_2_data_12804[14] = {
    0x00000001, 0x0000002B, 0x0000002C, 0x00000046,
    0x00000047, 0x00000021, 0x00000022, 0x0000006A,
    0x00000068, 0x00000069, 0x00000058, 0x00000059,
    0x0000004C, 0x00000002,
};

// .data:0x0001283C size:0x38
u32 lbl_2_data_1283C[14] = {
    0x00000001, 0x0000002D, 0x0000002E, 0x00000046,
    0x00000047, 0x00000023, 0x00000024, 0x0000006A,
    0x00000068, 0x00000069, 0x00000058, 0x00000059,
    0x0000004C, 0x00000002,
};

// .data:0x00012874 size:0x30
u32 lbl_2_data_12874[12] = {
    0x00000001, 0x0000002F, 0x00000030, 0x00000046,
    0x00000047, 0x0000006A, 0x00000068, 0x00000069,
    0x00000058, 0x00000059, 0x0000004C, 0x00000002,
};

// .data:0x000128A4 size:0x38
u32 lbl_2_data_128A4[14] = {
    0x00000001, 0x00000031, 0x00000032, 0x00000046,
    0x00000047, 0x00000021, 0x00000022, 0x0000006A,
    0x00000068, 0x00000069, 0x00000058, 0x00000059,
    0x0000004D, 0x00000002,
};

// .data:0x000128DC size:0x38
u32 lbl_2_data_128DC[14] = {
    0x00000001, 0x00000033, 0x00000034, 0x00000046,
    0x00000047, 0x00000023, 0x00000024, 0x0000006A,
    0x00000068, 0x00000069, 0x00000058, 0x00000059,
    0x0000004D, 0x00000002,
};

// .data:0x00012914 size:0x38
u32 lbl_2_data_12914[14] = {
    0x00000001, 0x00000035, 0x00000036, 0x00000046,
    0x00000047, 0x00000023, 0x00000024, 0x0000006A,
    0x00000068, 0x00000069, 0x00000058, 0x00000059,
    0x0000004D, 0x00000002,
};

// .data:0x0001294C size:0x14
u32 lbl_2_data_1294C[5] = {
    0x00000001, 0x00000005, 0x00000233, 0x00000006,
    0x00000002,
};

// .data:0x00012960 size:0x14
u32 lbl_2_data_12960[5] = {
    0x00000001, 0x00000005, 0x00000240, 0x00000006,
    0x00000002,
};

// .data:0x00012974 size:0x14
u32 lbl_2_data_12974[5] = {
    0x00000001, 0x00000005, 0x00000241, 0x00000006,
    0x00000002,
};

// .data:0x00012988 size:0x14
u32 lbl_2_data_12988[5] = {
    0x00000001, 0x00000005, 0x00000242, 0x00000006,
    0x00000002,
};

// .data:0x0001299C size:0x14
u32 lbl_2_data_1299C[5] = {
    0x00000001, 0x00000005, 0x00000243, 0x00000006,
    0x00000002,
};

// .data:0x000129B0 size:0x14
u32 lbl_2_data_129B0[5] = {
    0x00000001, 0x00000005, 0x00000244, 0x00000006,
    0x00000002,
};

// .data:0x000129C4 size:0x14
u32 lbl_2_data_129C4[5] = {
    0x00000001, 0x00000005, 0x00000245, 0x00000006,
    0x00000002,
};

// .data:0x000129D8 size:0x14
u32 lbl_2_data_129D8[5] = {
    0x00000001, 0x00000005, 0x00000246, 0x00000006,
    0x00000002,
};

// .data:0x000129EC size:0x14
u32 lbl_2_data_129EC[5] = {
    0x00000001, 0x00000005, 0x00000247, 0x00000006,
    0x00000002,
};

// .data:0x00012A00 size:0x14
u32 lbl_2_data_12A00[5] = {
    0x00000001, 0x00000005, 0x00000248, 0x00000006,
    0x00000002,
};

// .data:0x00012A14 size:0x14
u32 lbl_2_data_12A14[5] = {
    0x00000001, 0x00000005, 0x00000249, 0x00000006,
    0x00000002,
};

// .data:0x00012A28 size:0x14
u32 lbl_2_data_12A28[5] = {
    0x00000001, 0x00000005, 0x0000024A, 0x00000006,
    0x00000002,
};

// .data:0x00012A3C size:0x14
u32 lbl_2_data_12A3C[5] = {
    0x00000001, 0x00000005, 0x0000024B, 0x00000006,
    0x00000002,
};

// .data:0x00012A50 size:0x14
u32 lbl_2_data_12A50[5] = {
    0x00000001, 0x00000005, 0x0000024C, 0x00000006,
    0x00000002,
};

// .data:0x00012A64 size:0x14
u32 lbl_2_data_12A64[5] = {
    0x00000001, 0x00000005, 0x0000024D, 0x00000006,
    0x00000002,
};

// .data:0x00012A78 size:0x14
u32 lbl_2_data_12A78[5] = {
    0x00000001, 0x00000005, 0x0000024E, 0x00000006,
    0x00000002,
};

// .data:0x00012A8C size:0x14
u32 lbl_2_data_12A8C[5] = {
    0x00000001, 0x00000005, 0x0000024F, 0x00000006,
    0x00000002,
};

// .data:0x00012AA0 size:0x14
u32 lbl_2_data_12AA0[5] = {
    0x00000001, 0x00000005, 0x00000250, 0x00000006,
    0x00000002,
};

// .data:0x00012AB4 size:0x14
u32 lbl_2_data_12AB4[5] = {
    0x00000001, 0x00000005, 0x00000251, 0x00000006,
    0x00000002,
};

// .data:0x00012AC8 size:0x14
u32 lbl_2_data_12AC8[5] = {
    0x00000001, 0x00000005, 0x00000252, 0x00000006,
    0x00000002,
};

// .data:0x00012ADC size:0x14
u32 lbl_2_data_12ADC[5] = {
    0x00000001, 0x00000005, 0x00000253, 0x00000006,
    0x00000002,
};

// .data:0x00012AF0 size:0x14
u32 lbl_2_data_12AF0[5] = {
    0x00000001, 0x00000005, 0x00000254, 0x00000006,
    0x00000002,
};

// .data:0x00012B04 size:0x14
u32 lbl_2_data_12B04[5] = {
    0x00000001, 0x00000005, 0x00000255, 0x00000006,
    0x00000002,
};

// .data:0x00012B18 size:0x14
u32 lbl_2_data_12B18[5] = {
    0x00000001, 0x00000005, 0x00000256, 0x00000006,
    0x00000002,
};

// .data:0x00012B2C size:0x14
u32 lbl_2_data_12B2C[5] = {
    0x00000001, 0x00000005, 0x00000257, 0x00000006,
    0x00000002,
};

// .data:0x00012B40 size:0x14
u32 lbl_2_data_12B40[5] = {
    0x00000001, 0x00000005, 0x00000258, 0x00000006,
    0x00000002,
};

// .data:0x00012B54 size:0x14
u32 lbl_2_data_12B54[5] = {
    0x00000001, 0x00000005, 0x0000025D, 0x00000006,
    0x00000002,
};

// .data:0x00012B68 size:0x14
u32 lbl_2_data_12B68[5] = {
    0x00000001, 0x00000005, 0x0000025F, 0x00000006,
    0x00000002,
};

// .data:0x00012B7C size:0x14
u32 lbl_2_data_12B7C[5] = {
    0x00000001, 0x00000005, 0x00000260, 0x00000006,
    0x00000002,
};

// .data:0x00012B90 size:0x10
u32 lbl_2_data_12B90[4] = {
    0x00000001, 0x00000029, 0x0000002A, 0x00000002,
};

// .data:0x00012BA0 size:0x14
u32 lbl_2_data_12BA0[5] = {
    0x00000001, 0x00000005, 0x00000261, 0x00000006,
    0x00000002,
};

// .data:0x00012BB4 size:0x10
u32 lbl_2_data_12BB4[4] = {
    0x00000001, 0x0000005E, 0x0000005F, 0x00000002,
};

// .data:0x00012BC4 size:0x8
u32 lbl_2_data_12BC4[2] = {
    0x00000001, 0x00000002,
};

// .data:0x00012BCC size:0x10
u32 lbl_2_data_12BCC[4] = {
    0x00000001, 0x00000054, 0x00000006, 0x00000002,
};

// .data:0x00012BDC size:0x10
u32 lbl_2_data_12BDC[4] = {
    0x00000001, 0x00000062, 0x00000063, 0x00000002,
};

// .data:0x00012BEC size:0x10
u32 lbl_2_data_12BEC[4] = {
    0x00000001, 0x00000064, 0x00000065, 0x00000002,
};

// .data:0x00012BFC size:0x10
u32 lbl_2_data_12BFC[4] = {
    0x00000001, 0x00000066, 0x00000067, 0x00000002,
};

// .data:0x00012C0C size:0xDC
void* lbl_2_data_12C0C[55] = {
    lbl_2_data_124A8, lbl_2_data_12558, lbl_2_data_12618, lbl_2_data_12628,
    lbl_2_data_12638, lbl_2_data_12640, lbl_2_data_12688, lbl_2_data_126D0,
    lbl_2_data_12708, lbl_2_data_12740, lbl_2_data_12784, lbl_2_data_127C4,
    lbl_2_data_12804, lbl_2_data_1283C, lbl_2_data_12874, lbl_2_data_128A4,
    lbl_2_data_128DC, lbl_2_data_12914, lbl_2_data_1294C, lbl_2_data_12960,
    lbl_2_data_12974, lbl_2_data_12988, lbl_2_data_1299C, lbl_2_data_129B0,
    lbl_2_data_129C4, lbl_2_data_129D8, lbl_2_data_129EC, lbl_2_data_12A00,
    lbl_2_data_12A14, lbl_2_data_12A28, lbl_2_data_12A3C, lbl_2_data_12A50,
    lbl_2_data_12A64, lbl_2_data_12A78, lbl_2_data_12A8C, lbl_2_data_12AA0,
    lbl_2_data_12AB4, lbl_2_data_12AC8, lbl_2_data_12ADC, lbl_2_data_12AF0,
    lbl_2_data_12B04, lbl_2_data_12B18, lbl_2_data_12B2C, lbl_2_data_12B40,
    lbl_2_data_12B54, lbl_2_data_12B68, lbl_2_data_12B7C, lbl_2_data_12B90,
    lbl_2_data_12BA0, lbl_2_data_12BB4, lbl_2_data_12BC4, lbl_2_data_12BCC,
    lbl_2_data_12BDC, lbl_2_data_12BEC, lbl_2_data_12BFC,
};

// .data:0x00012CE8 size:0x4
void* lbl_2_data_12CE8[1] = {
    lbl_2_data_12558,
};

// .bss:0x000015B8 size:0x4000
s32 lbl_2_bss_15B8[0x1000];

// .text:0x00042638 size:0xD0
void fn_2_42638(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        lbl_2_bss_1A824C->_1978C7[i] = lbl_2_bss_1A8248->_43C2[i];
    }
}

// .text:0x00042490 size:0x1A8
void fn_2_42490(void) {
    s32 i;
    s32 count;

    for (i = 0; i < 20; i++) {
        lbl_2_bss_1A824C->_1978DB[i] = 0;
    }
    count = 0;
    for (i = 0; i < 20; i++) {
        if (lbl_2_bss_1A824C->_1978C7[i] == 0 && lbl_2_bss_1A8248->_43C2[i] == 1 && lbl_2_data_36EC[i] == 1) {
            lbl_2_bss_1A824C->_1978DB[count++] = i;
        }
    }
    lbl_2_bss_1A824C->_1978EF = count;
}

// .text:0x00042474 size:0x1C
void fn_2_42474(void) {
    lbl_2_bss_1A824C->_1976E4 = 120;
}

// .text:0x00042388 size:0xEC
void fn_2_42388(void) {
    MenuTask0898* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        fn_2_42474();
        task->_28 = 1;
        break;
    case 1:
        if (fn_2_40CB8() != 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0898*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x000422FC size:0x8C
void fn_2_422FC(s32 index) {
    lbl_2_bss_1A824C->_197694 = 0;
    lbl_2_bss_1A824C->_19768C = 0;
    lbl_2_bss_1A824C->_197690 = 0;
    memcpy(lbl_2_bss_15B8, lbl_2_data_12C0C[index], sizeof(lbl_2_bss_15B8));
    lbl_2_bss_1A824C->_197684 = lbl_2_bss_15B8;
}

// .text:0x00042270 size:0x8C
void fn_2_42270(s32 index) {
    lbl_2_bss_1A824C->_197694 = 0;
    lbl_2_bss_1A824C->_19768C = 0;
    lbl_2_bss_1A824C->_197690 = 0;
    memcpy(lbl_2_bss_15B8, lbl_2_data_12CE8[index], sizeof(lbl_2_bss_15B8));
    lbl_2_bss_1A824C->_197684 = lbl_2_bss_15B8;
}

// .text:0x00040CB8 size:0x15B8
s32 fn_2_40CB8(void) {
    MenuTask0898* task = lbl_803CC1B8;
    MenuTask0898* child;
    s32 id;

    if (lbl_2_bss_1A824C->_19768C != 0) {
        lbl_2_bss_1A824C->_19768C--;
        return 0;
    }
    while (1) {
        switch (*lbl_2_bss_1A824C->_197684) {
        case 0x1:
            lbl_2_bss_1A824C->_197694 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x2:
            lbl_2_bss_1A824C->_197694 = 1;
            return 1;
        case 0x3:
            lbl_2_bss_1A824C->_19768C = lbl_2_bss_1A824C->_197684[1];
            lbl_2_bss_1A824C->_197684 += 2;
            break;
        case 0x5:
            fn_2_50CC0(lbl_2_bss_1A824C->_197684[1]);
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684 += 2;
            continue;
        case 0x1B:
            if (lbl_2_bss_1A8248->_44EF == 0) {
                if (!(lbl_2_bss_1A8248->_4427 & (1 << lbl_2_bss_1A8248->_441E))) {
                    id = lbl_2_bss_1A8248->_441E + lbl_2_bss_1A8248->_441C * 6 + 75;
                } else if (!(lbl_2_bss_1A8248->_4426 & (1 << lbl_2_bss_1A8248->_441E))) {
                    id = lbl_2_bss_1A8248->_441E + lbl_2_bss_1A8248->_441C * 6 + 147;
                } else if (lbl_2_bss_1A8248->_44FE[lbl_2_bss_1A8248->_441E] == 0) {
                    id = lbl_2_bss_1A8248->_441E + lbl_2_bss_1A8248->_441C * 6 + 3;
                } else {
                    id = lbl_2_bss_1A8248->_441E + lbl_2_bss_1A8248->_441C * 6 + 147;
                }
            } else if (lbl_2_bss_1A8248->_44F0 == 0) {
                id = 556;
            } else {
                id = 557;
            }
            fn_2_50CC0(id);
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x1C:
            if (fn_2_45938(lbl_2_bss_1A8248->_16C2) == 1) {
                id = lbl_2_bss_1A8248->_441E + lbl_2_bss_1A8248->_441C * 6 + 292;
            } else {
                id = lbl_2_bss_1A8248->_441E + lbl_2_bss_1A8248->_441C * 6 + 328;
            }
            fn_2_50CC0(id);
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x48:
            if (lbl_2_bss_1A8248->_44EF == 0) {
                id = lbl_2_bss_1A8248->_441E + lbl_2_bss_1A8248->_441C * 6 + 400;
            } else {
                id = 562;
            }
            fn_2_50CC0(id);
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x1D:
            if (lbl_2_bss_1A8248->_44EF == 0) {
                id = lbl_2_bss_1A8248->_441E + lbl_2_bss_1A8248->_441C * 6 + 364;
            } else {
                id = 561;
            }
            fn_2_50CC0(id);
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x1E:
            if (lbl_2_bss_1A8248->_4504 == 0) {
                id = lbl_2_bss_1A8248->_441C + lbl_2_bss_1A8248->_442C * 6 + 436;
            } else {
                id = lbl_2_bss_1A8248->_441C + lbl_2_bss_1A8248->_442D * 6 + 460;
            }
            fn_2_50CC0(id);
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x1F:
            fn_2_50CC0((lbl_2_bss_1A8248->_441C + lbl_2_bss_1A8248->_442C * 6 + 484));
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x20:
            fn_2_50CC0((lbl_2_bss_1A8248->_441C + lbl_2_bss_1A8248->_442D * 6 + 508));
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x49:
            fn_2_50CC0((lbl_2_bss_1A8248->_441C + lbl_2_bss_1A8248->_442E * 6 + 532));
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x6:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x7:
            lbl_2_bss_1A824C->_19783D = 1;
            if (lbl_2_bss_1A823C->_30 == 4) {
                fn_2_72054(0, 0xC);
                lbl_2_bss_1A8248->_16C0 = lbl_2_bss_1A8248->_16BE;
            } else {
                fn_2_6AF80(0, 1);
            }
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x8:
            if (fn_2_6AFD4(0) == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x9:
            child = fn_800B0A5C_insertQueue(fn_2_405B4, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0xA:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0xF:
            child = fn_800B0A5C_insertQueue(fn_2_4041C, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x10:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0xB:
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0xC:
            lbl_2_bss_1A824C->_197684++;
            break;
        case 0xD:
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0xE:
            lbl_2_bss_1A824C->_197684++;
            break;
        case 0x21:
            if (lbl_2_bss_1A8248->_43BE < 0x3E7) {
                child = fn_800B0A5C_insertQueue(fn_2_3FA14, 2);
            child->_28 = 0;
                task->_10 = 0;
            } else {
                lbl_2_bss_1A824C->_197740 = 1;
                task->_10 = 1;
            }
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x22:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x23:
            if (lbl_2_bss_1A8248->_43BE > 0) {
                child = fn_800B0A5C_insertQueue(fn_2_3F66C, 2);
            child->_28 = 0;
                task->_10 = 0;
            } else {
                lbl_2_bss_1A824C->_197740 = 1;
                task->_10 = 1;
            }
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x24:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x25:
            child = fn_800B0A5C_insertQueue(fn_2_3F55C, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x26:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x27:
            child = fn_800B0A5C_insertQueue(fn_2_3F44C, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x28:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x11:
            child = fn_800B0A5C_insertQueue(fn_2_3FDE0, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x12:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x13:
            fn_2_72054(1, 0xE);
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x14:
            if (fn_2_6AFD4(1) == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x6B:
            if (lbl_2_bss_1A824C->_197740 == 1) {
                lbl_2_bss_1A824C->_197740 = 0;
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x15:
            fn_2_72054(0, 2);
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x16:
            if (fn_2_6AFD4(0) == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x17:
            child = fn_800B0A5C_insertQueue(fn_2_38A40, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197688 = *lbl_2_bss_1A824C->_197684;
            *lbl_2_bss_1A824C->_197684 = 0x18;
            continue;
        case 0x18:
            if (task->_10 == 1) {
                *lbl_2_bss_1A824C->_197684 = lbl_2_bss_1A824C->_197688;
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x19:
            lbl_2_bss_1A824C->_197844 = 2;
            lbl_2_bss_1A8234->_162871 = 1;
            lbl_2_bss_1A8234->_162872 = 1;
            child = fn_800B0A5C_insertQueue(fn_2_38538, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197688 = *lbl_2_bss_1A824C->_197684;
            *lbl_2_bss_1A824C->_197684 = 0x1A;
            continue;
        case 0x1A:
            if (task->_10 == 1) {
                *lbl_2_bss_1A824C->_197684 = lbl_2_bss_1A824C->_197688;
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x29:
            child = fn_800B0A5C_insertQueue(fn_2_3F29C, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197688 = *lbl_2_bss_1A824C->_197684;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x2A:
            if (task->_10 == 1) {
                *lbl_2_bss_1A824C->_197684 = lbl_2_bss_1A824C->_197688;
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x2B:
            child = fn_800B0A5C_insertQueue(fn_2_3EA44, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x2C:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x2D:
            child = fn_800B0A5C_insertQueue(fn_2_3E7EC, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x2E:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x2F:
            child = fn_800B0A5C_insertQueue(fn_2_3E918, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x30:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x31:
            child = fn_800B0A5C_insertQueue(fn_2_3F188, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x32:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x33:
            child = fn_800B0A5C_insertQueue(fn_2_3F004, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x34:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x35:
            child = fn_800B0A5C_insertQueue(fn_2_3EEF0, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x36:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x37:
            child = fn_800B0A5C_insertQueue(fn_2_3EDD8, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x38:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x39:
            child = fn_800B0A5C_insertQueue(fn_2_3ECC0, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x3A:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x3B:
            child = fn_800B0A5C_insertQueue(fn_2_3EBA8, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x3C:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x3D:
            child = fn_800B0A5C_insertQueue(fn_2_408BC, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x3E:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x3F:
            lbl_2_bss_1A824C->_19774C = lbl_2_bss_1A824C->_197684[1];
            lbl_2_bss_1A8234->_16264E = 1;
            lbl_2_bss_1A824C->_197684 += 2;
            continue;
        case 0x41:
            lbl_2_bss_1A824C->_19774C = lbl_2_bss_1A824C->_197684[1];
            lbl_2_bss_1A8234->_16264F = 1;
            lbl_2_bss_1A824C->_197684 += 2;
            continue;
        case 0x40:
            lbl_2_bss_1A8234->_162838 = 1;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x55:
            lbl_2_bss_1A8234->_162839 = 1;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x42:
            lbl_2_bss_1A824C->_197859 = 0;
            lbl_2_bss_1A824C->_197857 = lbl_2_bss_1A824C->_197684[1];
            lbl_2_bss_1A8234->_16264B = 1;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684 += 2;
            continue;
        case 0x43:
            if (lbl_2_bss_1A824C->_197859 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x44:
            if (lbl_2_bss_1A824C->_19774E == lbl_2_bss_1A824C->_197684[1]) {
                lbl_2_bss_1A824C->_197684 += 2;
            }
            break;
        case 0x45:
            lbl_2_bss_1A8234->_16264D = 1;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x46:
            child = fn_800B0A5C_insertQueue(fn_2_3BA40, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x47:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x4A:
            fn_2_72054(0, 3);
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x4B:
            fn_2_72054(0, 3);
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x4C:
            fn_2_72054(0, 3);
            fn_2_72054(lbl_2_bss_1A8248->_441E, 7);
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x4D:
            fn_2_72054(0, 3);
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x4E:
            child = fn_800B0A5C_insertQueue(fn_2_3C3EC, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x4F:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x50:
            child = fn_800B0A5C_insertQueue(fn_2_3C168, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x51:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x52:
            child = fn_800B0A5C_insertQueue(fn_2_3C03C, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x53:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x54:
            fn_2_50CC0( (lbl_2_bss_1A8248->_441C + 0x23A));
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x56:
            child = fn_800B0A5C_insertQueue(fn_2_3E38C, 2);
            child->_28 = 0;
            child->_16 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x57:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x60:
            child = fn_800B0A5C_insertQueue(fn_2_3E058, 2);
            child->_28 = 0;
            child->_16 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x61:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x58:
            child = fn_800B0A5C_insertQueue(fn_2_3D5C4, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x59:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x5A:
            child = fn_800B0A5C_insertQueue(fn_2_3DF28, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x5B:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x5E:
            child = fn_800B0A5C_insertQueue(fn_2_3CD34, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x5F:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x62:
            child = fn_800B0A5C_insertQueue(fn_2_3BD88, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x63:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x64:
            child = fn_800B0A5C_insertQueue(fn_2_3BD88, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x65:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x66:
            child = fn_800B0A5C_insertQueue(fn_2_3BC24, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x67:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x68:
            child = fn_800B0A5C_insertQueue(fn_2_399C0, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x69:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        case 0x6A:
            fn_2_43404();
            fn_2_42708();
            fn_2_432EC();
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x6C:
            child = fn_800B0A5C_insertQueue(fn_2_37F04, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_197684++;
            continue;
        case 0x6D:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_197684++;
            }
            break;
        }
        return 0;
    }
}
