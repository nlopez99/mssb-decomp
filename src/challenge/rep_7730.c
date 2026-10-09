#include "challenge/rep_7730.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"

extern void* lbl_803CC1B8;

extern void* ARAMTransfer(void* entry, int arg1, int arg2, u32 aram);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80037B18(void* arg0, Vec* arg1, f32 arg2);
extern void fn_800385F0(void* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern void fn_80035A00(void);
extern void fn_80048C14(s32 arg0);
extern void fn_80048E00(s32 arg0, s32 arg1);

extern void fn_800AD038(s32 arg0);
extern void fn_800B1188(void);
extern void fn_800B24D4(s32 id);
extern void fn_800A7D4C(s32, void*);
extern void fn_80038CD0(u8 count, void* arg1, struct RopeNode7730* nodes, f32 arg3, f32 arg4);
extern void fn_1_AF4(s32 arg0, s32 arg1, f32 arg2);
extern void fn_1_272DC(void* arg0, s32 arg1);

extern u8 lbl_803CBBC0;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ s32 _08;
} lbl_80366158;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

typedef struct SprTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct SprTask7730* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ void* _14;
    /* 0x18 */ u8 _18[0x25 - 0x18];
    /* 0x25 */ u8 _25;
    /* 0x26 */ u8 _26[0x28 - 0x26];
    /* 0x28 */ s32 _28;
} SprTask7730;

typedef struct MenuTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ SprTask7730* _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ u8 _14;
} MenuTask7730;

typedef struct LoadTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ SprTask7730* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ void* _14;
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u8 _1E;
    /* 0x1F */ u8 _1F;
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
    /* 0x24 */ u8 _24;
} LoadTask7730;

typedef struct AnimTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ SprTask7730* _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ u8* _14;
    /* 0x18 */ u8* _18;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
    /* 0x22 */ u16 _22;
    /* 0x24 */ u16 _24;
    /* 0x26 */ u16 _26;
    /* 0x28 */ u16 _28;
    /* 0x2A */ u8 _2A[0x2C - 0x2A];
    /* 0x2C */ void* _2C;
} AnimTask7730;

typedef struct CameraTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ u8 _28[0x2C - 0x28];
    /* 0x2C */ u32 _2C;
} CameraTask7730;

typedef struct Actor7730 {
    /* 0x00 */ u8 _00[0x50];
    /* 0x50 */ f32 _50;
    /* 0x54 */ u8 _54[0xEC - 0x54];
    /* 0xEC */ f32 _EC;
} Actor7730;

typedef struct RopeNode7730 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ Vec _0C;
    /* 0x18 */ u8 _18[0x3C - 0x18];
    /* 0x3C */ s32 _3C;
} RopeNode7730; // size: 0x40

typedef struct RopeParams7730 {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ f32 _18;
    /* 0x1C */ u8 _1C[0x20 - 0x1C];
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
    /* 0x24 */ u8 _24;
} RopeParams7730;

typedef struct DrawEntry7730 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*_04)(struct DrawEntry7730*);
    /* 0x08 */ void* _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ void* _10;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
    /* 0x18 */ u8 _18;
} DrawEntry7730;

typedef struct AramEntry7730 {
    /* 0x0 */ u32 _0[4];
} AramEntry7730; // size: 0x10

AramEntry7730 lbl_1_data_FB98[64] = {
    { 0x0000040B, 0x4023491C, 0x19135800, 0x00082928 },
    { 0x0000040B, 0x4013764C, 0x1A635000, 0x0007DB48 },
    { 0x0000040B, 0x4003E3DC, 0x1A6B3000, 0x00021420 },
    { 0x0000040B, 0x4002EC10, 0x1A6D4800, 0x00013108 },
    { 0x0000040B, 0x400E72C0, 0x1A6E8000, 0x00060768 },
    { 0x0000040B, 0x40049404, 0x1A748800, 0x00020E34 },
    { 0x0000040B, 0x40076AE0, 0x18ED7000, 0x00036BC8 },
    { 0x0000040B, 0x4010FD70, 0x1A769800, 0x0005E284 },
    { 0x0000040B, 0x400DB738, 0x1A7C8000, 0x00049AB4 },
    { 0x0000040B, 0x400E9864, 0x1A812000, 0x00059DC0 },
    { 0x0000040B, 0x400B7718, 0x1A86C000, 0x00050288 },
    { 0x0000040B, 0x400D87FC, 0x1A8BC800, 0x00047BC4 },
    { 0x0000040B, 0x400D643C, 0x1A904800, 0x0004E3AC },
    { 0x0000040B, 0x400D5C7C, 0x1A953000, 0x00048D9C },
    { 0x0000040B, 0x400B767C, 0x1A99C000, 0x00047518 },
    { 0x0000040B, 0x400441F8, 0x1A9E3800, 0x0001AA84 },
    { 0x0000040B, 0x40106568, 0x1A9FE800, 0x00068C10 },
    { 0x0000040B, 0x4010E5A0, 0x0E97A800, 0x0009BCAC },
    { 0x0000040B, 0x40016980, 0x0EA16800, 0x0000D6C4 },
    { 0x0000040B, 0x40016980, 0x0EA24000, 0x0000C944 },
    { 0x0000040B, 0x40016980, 0x0EA31000, 0x0000E700 },
    { 0x0000040B, 0x40016980, 0x0EA3F800, 0x0000D64C },
    { 0x0000040B, 0x40016980, 0x0EA4D000, 0x0000C900 },
    { 0x0000040B, 0x40016980, 0x0EA5A000, 0x0000CFFC },
    { 0x0000040B, 0x40016980, 0x0EA67000, 0x0000D720 },
    { 0x0000040B, 0x40016980, 0x0EA74800, 0x0000D6CC },
    { 0x0000040B, 0x40016980, 0x0EA82000, 0x0000D21C },
    { 0x0000040B, 0x40016980, 0x0EA8F800, 0x0000D0BC },
    { 0x0000040B, 0x40016980, 0x0EA9D000, 0x0000B544 },
    { 0x0000040B, 0x40016980, 0x0EAA8800, 0x0000C4F8 },
    { 0x0000040B, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 },
    { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 },
    { 0x0000040B, 0x4000A820, 0x18ED3800, 0x00003758 },
    { 0x0000040B, 0x4011EC24, 0x18F0E000, 0x000D8818 },
    { 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8 },
    { 0x0000040B, 0x4006C850, 0x06C96000, 0x0002C884 },
    { 0x0000040B, 0x4005B178, 0x06CC3000, 0x0003555C },
    { 0x0000040B, 0x401EB174, 0x18D43800, 0x000FB220 },
    { 0x0000040B, 0x4001ED60, 0x1AA67800, 0x0000CFF0 },
    { 0x0000040B, 0x4000BF30, 0x1AA74800, 0x000026E0 },
    { 0x0000040B, 0x40003498, 0x1AA77000, 0x00000E28 },
    { 0x0000040B, 0x4000BDE0, 0x1AA78000, 0x000024F4 },
    { 0x0000040B, 0x40006088, 0x1AA7A800, 0x00001290 },
    { 0x0000040B, 0x400049F0, 0x1AA7C000, 0x000018F4 },
    { 0x0000040B, 0x40005ECC, 0x1AA7E000, 0x00001D38 },
    { 0x0000040B, 0x40002670, 0x1AA80000, 0x00000BE8 },
    { 0x00000000, 0x00028240, 0x1AA81000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AAA9800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AAD2000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AAFA800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB23000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB4B800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB74000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB9C800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ABC5000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ABED800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC16000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC3E800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC67000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC8F800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ACB8000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ACE0800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AD09000, 0x00028240 },
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
};

char lbl_1_data_FF98[47][20] = {
    "game_td",
    "result",
    "operation",
    "game_toy",
    "game_slot",
    "score",
    "rule_toy",
    "rule_mini_01",
    "rule_mini_02",
    "rule_mini_03",
    "rule_mini_05",
    "rule_mini_04",
    "rule_mini_06",
    "rule_mini_07",
    "training",
    "common",
    "logo_all",
    "logo_00",
    "logo_01",
    "logo_02",
    "logo_03",
    "logo_04",
    "logo_05",
    "logo_06",
    "logo_07",
    "logo_08",
    "logo_09",
    "logo_10",
    "logo_11",
    "chara_sel",
    "select",
    "dictionary",
    "score",
    "end",
    "option",
    "logo_all",
    "title",
    "comingsoon",
    "bg_test",
    "load",
    "fade00",
    "fade01",
    "fade02",
    "fade03",
    "fade04",
    "fade05",
    "fade06",
};

u16 lbl_1_data_10344[32] = {
    0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0xFFFF, 0xFFFF,
    0x0104, 0x00FF, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000,
    0x0003, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000,
};

u32 lbl_1_data_10384[72] = {
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF,
    0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF, 0xFF0000FF,
    0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF,
    0x00FFFFFF, 0xFFFFFFFF, 0xFF0000FF, 0x00FF00FF,
    0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF,
    0xFFFFFFFF, 0xFF0000FF, 0x00FF00FF, 0xFFFF00FF,
    0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF,
    0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF, 0xFF0000FF,
    0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF,
    0x00FFFFFF, 0xFFFFFFFF, 0xFF0000FF, 0x00FF00FF,
    0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF,
    0xFFFFFFFF, 0xFF0000FF, 0x00FF00FF, 0xFFFF00FF,
    0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
    0x00000064, 0x43480000, 0x42C80000, 0x41A00000,
    0x0000000A, 0x3F800000, 0x3F800000, 0x00000000,
    0xBF800000, 0x00000000, 0x00000000, 0x00000000,
    0xC0A00000, 0x00000000, 0x00000000, 0x00000000,
};

f32 lbl_1_data_104A4 = 50.0f;

void (*lbl_1_data_104A8[4])(void) = { fn_1_1F2D8, fn_1_24410, fn_1_22644, fn_1_2040C };
u32 lbl_1_data_104B8[6] = { 0x3E99999A, 0x3D010204, 0x3F800000, 0x3F7AE148, 0x3D4CCCCD, 0x00000400 };

f32 lbl_1_data_104D0[3] = { 0.125f, 0.125f, 0.125f };

GXColor lbl_1_data_104DC[6] = {
    { 0xFF, 0x80, 0x80, 0xFF }, { 0x80, 0xFF, 0x80, 0xFF }, { 0x80, 0x80, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0x80, 0xFF }, { 0xFF, 0x80, 0xFF, 0xFF }, { 0x80, 0xFF, 0xFF, 0xFF },
};

u32 lbl_1_data_104F4[5] = {
    0x0000040B, 0x40000528, 0x09438800, 0x00000424,
    0x3E000000,
};

void* lbl_1_data_10508[2] = { fn_1_1FD78, fn_1_1F418 };

void* lbl_1_data_10510[2] = { fn_1_1F900, fn_1_1F618 };

AramEntry7730 lbl_1_data_10518[21] = {
    { 0x0000040B, 0x40168A6C, 0x06CFD000, 0x000C69A8 },
    { 0x0000040B, 0x401331E0, 0x06DC4000, 0x000B67C4 },
    { 0x0000040B, 0x4011924C, 0x06E7A800, 0x000A5764 },
    { 0x0000040B, 0x400FBAE0, 0x06F20000, 0x000BE038 },
    { 0x0000040B, 0x400E5AC0, 0x06FDE800, 0x000B4FB8 },
    { 0x0000040B, 0x40131200, 0x07093800, 0x000A317C },
    { 0x0000040B, 0x4011B660, 0x07137000, 0x000D0294 },
    { 0x0000040B, 0x4011B660, 0x07137000, 0x000D0294 },
    { 0x0000040B, 0x4011B660, 0x07137000, 0x000D0294 },
    { 0x0000040B, 0x40141C60, 0x07207800, 0x000CE904 },
    { 0x0000040B, 0x4013CA40, 0x072D6800, 0x000CA560 },
    { 0x0000040B, 0x40141C60, 0x07207800, 0x000CE904 },
    { 0x0000040B, 0x4016C138, 0x073A1000, 0x000ED41C },
    { 0x0000040B, 0x401157B8, 0x0748E800, 0x000CA83C },
    { 0x0000040B, 0x4016C138, 0x073A1000, 0x000ED41C },
    { 0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510 },
    { 0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510 },
    { 0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510 },
    { 0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390 },
    { 0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390 },
    { 0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390 },
};

void (*lbl_1_data_10668[1])(s16) = { fn_1_1DE60 };

void (*lbl_1_data_1066C[1])(s16) = { fn_1_1DE5C };

s32 lbl_1_data_10670 = 4;

AramEntry7730 lbl_1_data_10674[21] = {
    { 0x0000040B, 0x40168A6C, 0x06CFD000, 0x000C69A8 },
    { 0x0000040B, 0x401331E0, 0x06DC4000, 0x000B67C4 },
    { 0x0000040B, 0x4011924C, 0x06E7A800, 0x000A5764 },
    { 0x0000040B, 0x400FBAE0, 0x06F20000, 0x000BE038 },
    { 0x0000040B, 0x400E5AC0, 0x06FDE800, 0x000B4FB8 },
    { 0x0000040B, 0x40131200, 0x07093800, 0x000A317C },
    { 0x0000040B, 0x4011B660, 0x07137000, 0x000D0294 },
    { 0x0000040B, 0x4011B660, 0x07137000, 0x000D0294 },
    { 0x0000040B, 0x4011B660, 0x07137000, 0x000D0294 },
    { 0x0000040B, 0x40141C60, 0x07207800, 0x000CE904 },
    { 0x0000040B, 0x4013CA40, 0x072D6800, 0x000CA560 },
    { 0x0000040B, 0x40141C60, 0x07207800, 0x000CE904 },
    { 0x0000040B, 0x4016C138, 0x073A1000, 0x000ED41C },
    { 0x0000040B, 0x401157B8, 0x0748E800, 0x000CA83C },
    { 0x0000040B, 0x4016C138, 0x073A1000, 0x000ED41C },
    { 0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510 },
    { 0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510 },
    { 0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510 },
    { 0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390 },
    { 0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390 },
    { 0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390 },
};

u8 lbl_1_data_107C4[4][8] = {
    { 0, 1, 2, 3, 4, 5, 6, 7 },
    { 1, 2, 3, 4, 5, 6, 7, 8 },
    { 2, 3, 4, 5, 6, 7, 8, 9 },
    { 3, 4, 5, 6, 7, 8, 9, 10 },
};

DrawEntry7730 lbl_1_data_107E4[2] = {
    { 0, fn_1_1D694 },
    { 0, fn_1_1D694 },
};

// .bss statics, declared in reverse address order (MWCC lays them out in reverse)
static Mtx44 lbl_1_bss_47010;
static u8 lbl_1_bss_45868[0x17A8];
static u8 lbl_1_bss_43F68[0x1900];
static u8 lbl_1_bss_43EE0[0x88];
static u8 lbl_1_bss_F6E0[0x34800];
static u8 lbl_1_bss_76E0[0x8000];
static u8 lbl_1_bss_74E0[0x200];
static RopeNode7730 lbl_1_bss_6FE0[20];
static struct {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ f32 _24;
} lbl_1_bss_6FB8;
static u8 lbl_1_bss_6FB4[4];
static Vec lbl_1_bss_6FA8;
static void* lbl_1_bss_6FA4;
static u8 lbl_1_bss_6EA4[0x100];
static u8 lbl_1_bss_6E44[0x60];
static u8 lbl_1_bss_6D48[0xFC];
static u8 lbl_1_bss_6BF4[0x154];
static struct {
    /* 0x0 */ f32 _0;
    /* 0x4 */ Vec _4;
} lbl_1_bss_6BE4;
static s32 lbl_1_bss_6BE0;
static s32 lbl_1_bss_6BDC;
static s32 lbl_1_bss_6BD8;

// .text:0x00026AF8 size:0x84
void fn_1_26AF8(void) {
    LoadTask7730* task = lbl_803CC1B8;

    task->_1E = 0;
    task->_20 = 0;
    task->_21 = 0;
    task->_1F = 0;
    task->_22 = 0;
    while (lbl_1_data_FB98[task->_1F]._0[0] != 0) {
        task->_1F++;
    }
    fn_80035A00();
    ((LoadTask7730*)lbl_803CC1B8)->_00 = fn_1_26928;
}

// .text:0x00026A34 size:0xC4
void fn_1_26A34(void) {
    GXSetProjection(lbl_1_bss_47010, GX_PERSPECTIVE);
    GXClearVtxDesc();
    GXSetCullMode(GX_CULL_NONE);
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
}

// .text:0x00026928 size:0x10C
void fn_1_26928(void) {
    LoadTask7730* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._04 & 2) {
        task->_20++;
        if (task->_20 == task->_1F) {
            task->_20 = 0;
        }
    } else if (lbl_803C77B8[0]._04 & 1) {
        if (task->_20 == 0) {
            task->_20 = task->_1F;
        }
        task->_20--;
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        task->_1E = 0;
        ((LoadTask7730*)lbl_803CC1B8)->_00 = fn_1_267F4;
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        fn_800AD038(lbl_80366158._08);
        ((LoadTask7730*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
    } else if (lbl_803C77B8[0]._02 & 0x1000) {
        task->_00 = fn_1_25C68;
    }
    fn_800B24D4(4);
    fn_800B1188();
}

// .text:0x000267BC size:0x38
void fn_1_267BC(void) {
    if (((SprTask7730*)lbl_803CC1B8)->_10 != 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00024778 size:0x28
void fn_1_24778(void) {
    ((MenuTask7730*)lbl_803CC1B8)->_14 = 0;
    ((MenuTask7730*)lbl_803CC1B8)->_00 = fn_1_246AC;
}

// .text:0x000246AC size:0xCC
void fn_1_246AC(void) {
    MenuTask7730* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._04 & 8) {
        if (task->_14 == 0) {
            task->_14 = 4;
        }
        task->_14--;
    } else if (lbl_803C77B8[0]._04 & 4) {
        task->_14++;
        if (task->_14 == 4) {
            task->_14 = 0;
        }
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        task->_00 = lbl_1_data_104A8[task->_14];
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00023AD8 size:0x7C
void fn_1_23AD8(Mtx44 m, Vec* eye, Vec* at) {
    eye->x = 0.0f;
    eye->y = 0.0f;
    eye->z = -10.0f;
    at->x = 0.0f;
    at->y = 0.0f;
    at->z = 0.0f;
    C_MTXFrustum(m, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
}

// .text:0x000225B8 size:0x8C
void fn_1_225B8(void) {
    SprTask7730* task = lbl_803CC1B8;
    SprTask7730* child;

    switch (task->_25) {
    case 0:
        child = fn_800B0A5C_insertQueue(fn_1_20BD8, 1);
        child->_25 = 0;
        child->_10 = 0;
        task->_25++;
        break;
    case 1:
        if (task->_10 != 0) {
            task->_00 = fn_1_21408;
        }
        break;
    }
}

// .text:0x00021180 size:0x118
void fn_1_21180(RopeParams7730* params) {
    f32 dt;
    s32 last;

    lbl_1_bss_6FB8._20 = params->_20;
    dt = (1.0f / lbl_1_bss_6FB8._20) / 60.0f;
    lbl_1_bss_6FB8._18 = dt;
    lbl_1_bss_6FB8._1C = dt * dt;
    lbl_1_bss_6FB8._24 = 1.0f / (2.0f * dt);
    if (lbl_803C77B8[0]._00 & 0x400) {
        lbl_1_bss_6FB8._20 = 1;
    }
    fn_80038CD0(params->_21, &lbl_1_bss_6FB8, lbl_1_bss_6FE0, 0.2f, params->_18);
    last = params->_21 - 1;
    lbl_1_bss_6FA8.x = lbl_1_bss_6FE0[last]._0C.x;
    lbl_1_bss_6FA8.y = lbl_1_bss_6FE0[last]._0C.y;
    lbl_1_bss_6FA8.z = lbl_1_bss_6FE0[last]._0C.z;
    lbl_1_bss_6FE0[last]._3C = params->_23;
}

// .text:0x00020F8C size:0xB4
void fn_1_20F8C(void) {
    SprTask7730* parent = ((SprTask7730*)lbl_803CC1B8)->_0C;

    switch (((SprTask7730*)lbl_803CC1B8)->_10) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            parent->_14 = ARAMTransfer(lbl_1_data_104F4, 0, 0, 0);
            ((SprTask7730*)lbl_803CC1B8)->_10++;
        }
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            parent->_10 = 1;
        }
        break;
    }
}

// .text:0x00020DC8 size:0x38
void fn_1_20DC8(void) {
    SprTask7730* task = fn_800B0A5C_insertQueue(fn_1_20BD8, 1);
    task->_25 = 0;
    task->_10 = 0;
}

// .text:0x00020890 size:0xC0
void fn_1_20890(void) {
    Mtx m;

    C_MTXOrtho(lbl_1_bss_47010, 0.0f, 448.0f, 0.0f, 640.0f, 0.5f, -1.0f);
    GXSetProjection(lbl_1_bss_47010, GX_ORTHOGRAPHIC);
    PSMTXIdentity(m);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXLoadTexMtxImm(m, GX_TEXMTX0, GX_MTX2x4);
    fn_80048C14(3);
    fn_80048E00(0, 32);
    fn_80048E00(1, 0);
}

// .text:0x000207D4 size:0xBC
void fn_1_207D4(void) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 8);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
}

// .text:0x0001F23C size:0x9C
void fn_1_1F23C(Actor7730* actor) {
    fn_800385F0(lbl_1_bss_6BF4, ((CameraTask7730*)lbl_803CC1B8)->_14, ((CameraTask7730*)lbl_803CC1B8)->_18,
                ((CameraTask7730*)lbl_803CC1B8)->_1C, ((CameraTask7730*)lbl_803CC1B8)->_20);
    actor->_50 = -((CameraTask7730*)lbl_803CC1B8)->_24;
    actor->_EC += 2.0f;
    ((CameraTask7730*)lbl_803CC1B8)->_2C &= ~2;
    ((CameraTask7730*)lbl_803CC1B8)->_2C |= 2;
}

// .text:0x0001EFF4 size:0x68
void fn_1_1EFF4(void) {
    fn_1_272DC(lbl_1_bss_6D48, 0);
    fn_1_AF4(20, 20, 1.0f);
    if (((CameraTask7730*)lbl_803CC1B8)->_2C & 2) {
        fn_1_1E5D0(lbl_1_bss_6BF4);
    }
}

// .text:0x0001E8C0 size:0x4C
void fn_1_1E8C0(s32 arg0) {
    lbl_1_data_1066C[((SprTask7730*)lbl_803CC1B8)->_28](arg0 - 8);
}

// .text:0x0001E28C size:0x4
void fn_1_1E28C(void) {}

// .text:0x0001DE5C size:0x4
void fn_1_1DE5C(s16 arg0) {}

// .text:0x0001DE50 size:0xC
f32 fn_1_1DE50(void) { return lbl_1_bss_6BE4._0; }

// .text:0x0001DE40 size:0x10
f32 fn_1_1DE40(void) { return lbl_1_bss_6BE4._4.x; }

// .text:0x0001DE30 size:0x10
f32 fn_1_1DE30(void) { return lbl_1_bss_6BE4._4.y; }

// .text:0x0001DE20 size:0x10
f32 fn_1_1DE20(void) { return lbl_1_bss_6BE4._4.z; }

// .text:0x0001DE14 size:0xC
void fn_1_1DE14(f32 v) { lbl_1_bss_6BE4._0 = v; }

// .text:0x0001DE04 size:0x10
void fn_1_1DE04(f32 v) { lbl_1_bss_6BE4._4.x = v; }

// .text:0x0001DDF4 size:0x10
void fn_1_1DDF4(f32 v) { lbl_1_bss_6BE4._4.y = v; }

// .text:0x0001DDE4 size:0x10
void fn_1_1DDE4(f32 v) { lbl_1_bss_6BE4._4.z = v; }

// .text:0x0001DD94 size:0x50
void fn_1_1DD94(void) {
    Vec v;

    v.x = lbl_1_bss_6BE4._4.x;
    v.y = lbl_1_bss_6BE4._4.y;
    v.z = lbl_1_bss_6BE4._4.z;
    fn_80037B18(lbl_1_bss_6BF4, &v, lbl_1_bss_6BE4._0);
}

// .text:0x0001DD48 size:0x4C
f32 fn_1_1DD48(u16 buttons, s32 negate, f32 value, f32 step, f32 normal, f32 fast, f32 min, f32 max) {
    f32 delta = normal;

    if (buttons & 0x40) {
        delta = step;
    } else if (buttons & 0x20) {
        delta = fast;
    }
    if (negate) {
        delta = -delta;
    }
    value += delta;
    if (value < min) {
        value = min;
    }
    if (value > max) {
        value = max;
    }
    return value;
}

// .text:0x0001DCE4 size:0x64
void fn_1_1DCE4(void) {
    SprTask7730* task = lbl_803CC1B8;

    task->_14 = ARAMTransfer(lbl_1_data_10674, 0, 0, 0);
    ((SprTask7730*)lbl_803CC1B8)->_00 = fn_1_1DA54;
}

// .text:0x0001D944 size:0x110
void fn_1_1D944(void) {
    AnimTask7730* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._02 & 0x200) {
        fn_800AD038(lbl_80366158._08);
        ((AnimTask7730*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        return;
    }
    if (--task->_20 == 0) {
        task->_20 = task->_22;
        task->_1E = (task->_1E + 1) % task->_1C;
    }
    lbl_1_data_107E4[lbl_803CBBC0]._0C = task->_18 + (task->_28 + task->_1E) * 32 + 4;
    lbl_1_data_107E4[lbl_803CBBC0]._14 = task->_24;
    lbl_1_data_107E4[lbl_803CBBC0]._16 = task->_26;
    lbl_1_data_107E4[lbl_803CBBC0]._18 = 1;
    lbl_1_data_107E4[lbl_803CBBC0]._10 = lbl_1_data_107C4;
    lbl_1_data_107E4[lbl_803CBBC0]._08 = task->_2C;
    fn_800A7D4C(0, &lbl_1_data_107E4[lbl_803CBBC0]);
}
