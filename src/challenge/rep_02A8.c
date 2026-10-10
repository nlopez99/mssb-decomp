#include "challenge/rep_02A8.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"

typedef struct Task02A8 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct Task02A8* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ s32 (*_14)(u8* arg0);
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
} Task02A8;

typedef struct ListEntry02A8 {
    /* 0x00 */ char* _00;
    /* 0x04 */ u8 _04[0x10 - 0x4];
} ListEntry02A8; // size: 0x10

typedef struct List02A8 {
    /* 0x00 */ ListEntry02A8* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
} List02A8;

typedef struct AramEntry02A8 {
    /* 0x0 */ u32 _0[4];
} AramEntry02A8; // size: 0x10

extern void* lbl_803CC1B8;

// The sound bank table: group data pointers, indexed by sound group
extern struct {
    /* 0x000 */ s32 _00;
    /* 0x004 */ void* groups[0xE3];
    /* 0x390 */ u8 _390;
    /* 0x391 */ u8 _391[0x396 - 0x391];
    /* 0x396 */ u8 _396;
} lbl_800EF808;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x00 */ s8 _00;
    /* 0x01 */ u8 _01;
    /* 0x02 */ u8 _02[0xC - 0x2];
    /* 0x0C */ s32 _0C;
    /* 0x10 */ u8 _10[0x24 - 0x10];
    /* 0x24 */ s32 _24[11];
} lbl_1_common_bss_49A78;

extern struct {
    /* 0x00 */ u8 _00[0xE0];
    /* 0x E0 */ u8 _E0;
} lbl_1_common_bss_49994;

extern void* ARAMTransfer(AramEntry02A8* entry, s32 arg1, s32 arg2, u32 aram);
extern u8 fn_800211F0(void);
extern BOOL fn_800214D0(void);
extern BOOL fn_80021518(s32 group, void* data);
extern void fn_80021954(void** group);
extern void fn_80021980(void* group);
extern void fn_800ACFB0(void* ptr);
extern s32 fn_80062890(s16 arg0);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void fn_800B0A14_removeQueue(void);

static u16 lbl_1_data_FC0[0x3CC] = {
    0x1B1A, 0x1918, 0x1716, 0x1514, 0x1312, 0x1110, 0x0F0E, 0x0D0C,
    0x0B0A, 0x2307, 0x0921, 0x2208, 0x302E, 0x272F, 0x3225, 0x2426,
    0x0144, 0x0137, 0x012A, 0x011D, 0x0110, 0x0103, 0x00F6, 0x00E9,
    0x00DC, 0x00CF, 0x00C2, 0x00B5, 0x00A8, 0x009B, 0x008E, 0x0081,
    0x0074, 0x0067, 0x0201, 0x0040, 0x005A, 0x01E7, 0x01E7, 0x01E7,
    0x01F4, 0x01F4, 0x01F4, 0x004D, 0x0277, 0x009B, 0x009B, 0x009B,
    0x009B, 0x025D, 0x025D, 0x025D, 0x025D, 0x0235, 0x026A, 0x02C9,
    0x021B, 0x020E, 0x00A8, 0x005A, 0x0074, 0x0074, 0x0074, 0x0074,
    0x0228, 0x0228, 0x0228, 0x0228, 0x004D, 0x004D, 0x2A2B, 0x2C34,
    0x0201, 0x0600, 0x0248, 0x024A, 0x0252, 0x030F, 0x0010, 0x0001,
    0x0022, 0x0000, 0x0249, 0x0251, 0x0258, 0x000F, 0x0017, 0x000F,
    0x003F, 0x0000, 0x02D6, 0x02D7, 0x02D8, 0x02D9, 0x02E1, 0x02E2,
    0x02E3, 0x02E4, 0x02E5, 0x02E6, 0x02DD, 0x02DE, 0x02DF, 0x02E0,
    0x02DA, 0x02DB, 0x02DC, 0x02E7, 0x02E8, 0x02E9, 0x02EA, 0x02EB,
    0x02EC, 0x02ED, 0x02EE, 0x02EF, 0x02F0, 0x02F1, 0x02F2, 0x02F3,
    0x02F4, 0x02F5, 0x02F6, 0x02F7, 0x02F8, 0x02F9, 0x02FA, 0x02FB,
    0x02FC, 0x02FD, 0x02FE, 0x02FF, 0x0300, 0x0301, 0x0302, 0x0303,
    0x0304, 0x0305, 0x0306, 0x0307, 0x0308, 0x0309, 0x030A, 0x030B,
    0x030C, 0x030D, 0x030E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100,
    0x7878, 0x7878, 0x7878, 0x7878, 0x7878, 0x7878, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x0000, 0x7F00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x7F00, 0x0000, 0x0000, 0x0000, 0x7F7F, 0x7F7F, 0x7F00, 0x0000,
    0x0000, 0x0000, 0x4B28, 0x4B28, 0x5528, 0x5528, 0x5528, 0x5528,
    0x5528, 0x5528, 0x5528, 0x5A28, 0x5528, 0x5528, 0x5528, 0x5528,
    0x5528, 0x5528, 0x5A28, 0x5F28, 0x6928, 0x0000, 0x5528, 0x0000,
    0x7F00, 0x7F00, 0x7F00, 0x4600, 0x4B00, 0x5500, 0x5A00, 0x5A00,
    0x6400, 0x7F00, 0x6400, 0x7800, 0x6400, 0x7F00, 0x6400, 0x6400,
    0x6400, 0x6400, 0x6400, 0x6400, 0x6400, 0x6400, 0x6400, 0x6400,
    0x7F00, 0x6400, 0x6E00, 0x7F00, 0x7500, 0x7500, 0x6400, 0x6400,
    0x5700, 0x6400, 0x6400, 0x5700, 0x6400, 0x6400, 0x6400, 0x7F00,
    0x7F00, 0x7500, 0x5400, 0x6400, 0x6400, 0x5000, 0x5A00, 0x7F00,
    0x7F00, 0x7F00, 0x7F00, 0x7F00, 0x7F00, 0x6400, 0x6400, 0x6400,
    0x7500, 0x6B00, 0x6400, 0x7300, 0x7F00, 0x7F00, 0x7F00, 0x7F00,
    0x7F00, 0x7F00, 0x7F00, 0x7F00, 0x7F00, 0x6B00, 0x5500, 0x6B00,
    0x6B00, 0x7F00, 0x7F00, 0x7500, 0x6600, 0x7500, 0x7F00, 0x5500,
    0x6400, 0x6400, 0x6400, 0x6400, 0x6400, 0x6E00, 0x6400, 0x6400,
    0x7300, 0x6E00, 0x5A00, 0x6E00, 0x7F00, 0x7F00, 0x6B00, 0x7F00,
    0x7500, 0x7F00, 0x7F00, 0x7300, 0x7F00, 0x7F00, 0x3C00, 0x5A00,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7F00, 0x7F00, 0x7F00,
    0x6900, 0x7F00, 0x7F00, 0x7F00, 0x7F00, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x7F00, 0x7F00, 0x7F00, 0x7F00,
    0x7F00, 0x7F00, 0x7F00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x7F00, 0x7F00, 0x7F00, 0x6400, 0x7F00,
    0x4100, 0x4600, 0x4600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x7F00, 0x7F00, 0x7F00, 0x3200, 0x4D00, 0x4D00,
    0x5700, 0x5700, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x7F00, 0x6400, 0x6400, 0x6400, 0x7F00, 0x7F00, 0x3C00,
    0x3C00, 0x6900, 0x7F00, 0x6E00, 0x7F00, 0x6E00, 0x7F00, 0x7F00,
    0x7F00, 0x6B00, 0x6400, 0x5F00, 0x7500, 0x7000, 0x6B00, 0x7F00,
    0x6B00, 0x7F00, 0x7F00, 0x7F00, 0x4B00, 0x7F00, 0x7F00, 0x7F00,
    0x6400, 0x6400, 0x6900, 0x7500, 0x6900, 0x5F00, 0x5F00, 0x6900,
    0x6400, 0x6E00, 0x7800, 0x6E00, 0x6E00, 0x7F00, 0x6B7F, 0x7F7F,
    0x7F7F, 0x7F4D, 0x4D7F, 0x616B, 0x6161, 0x7F6B, 0x5F69, 0x4337,
    0x7F7F, 0x7F69, 0x7F61, 0x7575, 0x645F, 0x7F64, 0x647F, 0x695A,
    0x646B, 0x7F7F, 0x5A7F, 0x7F75, 0x7F7F, 0x7364, 0x736E, 0x6E7F,
    0x7373, 0x7F7F, 0x7800, 0x0000, 0x6464, 0x6464, 0x6464, 0x6464,
    0x6464, 0x6464, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F,
    0x7F7F, 0x7F7F, 0x7F7F, 0x7F7F, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x3F19, 0x999A, 0x4248, 0x0000,
    0x0000, 0x0000, 0x42FE, 0x0000, 0x4120, 0x0000, 0x4248, 0x0000,
    0x0000, 0x0000, 0x42FE, 0x0000, 0x4120, 0x0000, 0x4248, 0x0000,
    0x0000, 0x0000, 0x42FE, 0x0000, 0x4120, 0x0000, 0x4248, 0x0000,
    0x0000, 0x0000, 0x42FE, 0x0000, 0x4120, 0x0000, 0x42C8, 0x0000,
    0x0000, 0x0000, 0x42FE, 0x0000, 0x4120, 0x0000, 0x42C8, 0x0000,
    0x0000, 0x0000, 0x42FE, 0x0000, 0x4120, 0x0000, 0x0000, 0x0001,
    0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0061,
    0x0000, 0x0061, 0x4248, 0x0000, 0x4248, 0x0000, 0x3F80, 0x0000,
    0x2000, 0x3B00, 0x0003, 0x002D, 0x0046, 0x0000, 0x2000, 0x3FFF,
    0x0001, 0x003C, 0x007F, 0x0000, 0x2000, 0x3FFF, 0x0014, 0x00A5,
    0x007F, 0x0000, 0x0303, 0x0000,
};

static char* lbl_1_data_1758[19] = {
    "Voice Test",
    "Voice Test2",
    "Training Se Test",
    "SE Test",
    "Surround Test",
    "VOICE NO ",
    "HAPPY",
    "POWER_UP_P",
    "POWER_UP_B",
    "SWING_WIDE",
    "STRUCK_OUT",
    "RELEASE FAST",
    "RELEASE G_FAST",
    "NO 1",
    "MAX SWING OUT",
    "LOSE",
    "DEAD BALL",
    "FIRE BALL",
    "end",
};

static u8 lbl_1_data_17A4[0x20] = {
    0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C,
    0x0B, 0x0A, 0x23, 0x07, 0x09, 0x08, 0x25, 0x24, 0x26, 0x21, 0x22, 0x2E, 0x27, 0x2F, 0x30, 0x32,
};

static u16 lbl_1_data_17C4[18] = {
    0x0144, 0x0137, 0x012A, 0x011D, 0x0110, 0x0103, 0x00F6, 0x00E9, 0x00DC,
    0x00CF, 0x00C2, 0x00B5, 0x00A8, 0x009B, 0x008E, 0x0081, 0x0074, 0x0067,
};

static u16 lbl_1_data_17E8[14] = {
    0x0201, 0x0040, 0x005A, 0x004D, 0x021B, 0x020E, 0x0228,
    0x01E7, 0x01F4, 0x025D, 0x0235, 0x026A, 0x0277, 0x02C9,
};

static char* lbl_1_data_1804[32] = {
    "MARIO      ",
    "LUIGI      ",
    "DONKEY     ",
    "DIDDY      ",
    "PEACH      ",
    "DAISY      ",
    "YOSHI      ",
    "BABYMARIO  ",
    "BABYLUIGI  ",
    "KOOPA      ",
    "WARIO      ",
    "WALUIGI    ",
    "NOKONOKO   ",
    "KINOPIO    ",
    "TERESA     ",
    "KINOPIKO   ",
    "HEIHO R    ",
    "CATHERINE  ",
    "CHOROPU    ",
    "KOOPA JR.  ",
    "PATA_P     ",
    "HAMM BROS  ",
    "KURIBO     ",
    "PATA_K     ",
    "KARON      ",
    "MONTE      ",
    "MARE       ",
    "KAMEKKU    ",
    "KING TERESA",
    "BOSS PAKKUN",
    "KINOJI     ",
    "DIXY       ",
};

static u8 lbl_1_data_1884[8] = { 0x2A, 0x2B, 0x2C, 0x34, 0x02, 0x01, 0x06, 0x00 };

static u16 lbl_1_data_188C[48] = {
    0x0248, 0x0249, 0x024A, 0x024B, 0x024C, 0x024D, 0x024E, 0x024F,
    0x0250, 0x0252, 0x0253, 0x0254, 0x0255, 0x0256, 0x0257, 0x030F,
    0x0310, 0x0311, 0x0312, 0x0313, 0x0314, 0x0315, 0x0316, 0x0010,
    0x0011, 0x0012, 0x0013, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005,
    0x0006, 0x0007, 0x0008, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026,
    0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002F,
};

static u16 lbl_1_data_18EC[24] = {
    0x02D6, 0x02D7, 0x02D8, 0x02D9, 0x02DA, 0x02DB, 0x02DC, 0x02DD,
    0x02DE, 0x02DF, 0x02E0, 0x02E1, 0x02E2, 0x02E3, 0x02E4, 0x02E5,
    0x02E6, 0x02E7, 0x02E8, 0x02E9, 0x02EA, 0x02EB, 0x02EC, 0x0017,
};

static char* lbl_1_data_191C[20] = {
    "POS_X",
    "POS_Y",
    "POS_Z",
    "DIR_X",
    "DIR_Y",
    "DIR_Z",
    "HEAD_X",
    "HEAD_Y",
    "HEAD_Z",
    "UP_X",
    "UP_Y",
    "UP_Z",
    "VOL",
    "POS_X",
    "POS_Y",
    "POS_Z",
    "DIR_X",
    "DIR_Y",
    "DIR_Z",
    "VOL",
};

static AramEntry02A8 lbl_1_data_196C[50] = {
    { 0x00000000, 0x0002B060, 0x07742000, 0x0002B060 },
    { 0x00000000, 0x00415EA0, 0x0776D800, 0x00415EA0 },
    { 0x00000000, 0x00103340, 0x07B83800, 0x00103340 },
    { 0x00000000, 0x0029D520, 0x07C87000, 0x0029D520 },
    { 0x00000000, 0x001364E0, 0x07F24800, 0x001364E0 },
    { 0x00000000, 0x0002BB40, 0x0805B000, 0x0002BB40 },
    { 0x00000000, 0x00028800, 0x08087000, 0x00028800 },
    { 0x00000000, 0x0003DC00, 0x080AF800, 0x0003DC00 },
    { 0x00000000, 0x00039DC0, 0x080ED800, 0x00039DC0 },
    { 0x00000000, 0x00022260, 0x08127800, 0x00022260 },
    { 0x00000000, 0x0001B180, 0x0814A000, 0x0001B180 },
    { 0x00000000, 0x00021140, 0x08165800, 0x00021140 },
    { 0x00000000, 0x0002E080, 0x08187000, 0x0002E080 },
    { 0x00000000, 0x00029500, 0x081B5800, 0x00029500 },
    { 0x00000000, 0x0002FEA0, 0x081DF000, 0x0002FEA0 },
    { 0x00000000, 0x0002D360, 0x0820F000, 0x0002D360 },
    { 0x00000000, 0x00039DC0, 0x0823C800, 0x00039DC0 },
    { 0x00000000, 0x0000F760, 0x08276800, 0x0000F760 },
    { 0x00000000, 0x00023EA0, 0x08286000, 0x00023EA0 },
    { 0x00000000, 0x00026600, 0x082AA000, 0x00026600 },
    { 0x00000000, 0x0001D8C0, 0x082D0800, 0x0001D8C0 },
    { 0x00000000, 0x00021DE0, 0x082EE800, 0x00021DE0 },
    { 0x00000000, 0x00035100, 0x08310800, 0x00035100 },
    { 0x00000000, 0x00016F40, 0x08346000, 0x00016F40 },
    { 0x00000000, 0x000246A0, 0x0835D000, 0x000246A0 },
    { 0x00000000, 0x00013240, 0x08381800, 0x00013240 },
    { 0x00000000, 0x0001D020, 0x083E3000, 0x0001D020 },
    { 0x00000000, 0x00016BA0, 0x084A5800, 0x00016BA0 },
    { 0x00000000, 0x0001A500, 0x084BC800, 0x0001A500 },
    { 0x00000000, 0x0001A060, 0x084D7000, 0x0001A060 },
    { 0x00000000, 0x0002CB20, 0x08395000, 0x0002CB20 },
    { 0x00000000, 0x00020BE0, 0x083C2000, 0x00020BE0 },
    { 0x00000000, 0x00026280, 0x0841A000, 0x00026280 },
    { 0x00000000, 0x000217A0, 0x08440800, 0x000217A0 },
    { 0x00000000, 0x0001A000, 0x08462000, 0x0001A000 },
    { 0x00000000, 0x000190E0, 0x08400800, 0x000190E0 },
    { 0x00000000, 0x000291C0, 0x0847C000, 0x000291C0 },
    { 0x00000000, 0x00016BA0, 0x084A5800, 0x00016BA0 },
    { 0x00000000, 0x0001A500, 0x084BC800, 0x0001A500 },
    { 0x00000000, 0x0001A060, 0x084D7000, 0x0001A060 },
    { 0x00000000, 0x00334600, 0x084F1800, 0x00334600 },
    { 0x00000000, 0x001B65E0, 0x08826000, 0x001B65E0 },
    { 0x00000000, 0x00047F20, 0x089DC800, 0x00047F20 },
    { 0x00000000, 0x000353E0, 0x08A24800, 0x000353E0 },
    { 0x00000000, 0x00020FA0, 0x08A5A000, 0x00020FA0 },
    { 0x00000000, 0x000444E0, 0x08A7B000, 0x000444E0 },
    { 0x00000000, 0x000145C0, 0x08ABF800, 0x000145C0 },
    { 0x00000000, 0x00044CA0, 0x08AD4000, 0x00044CA0 },
    { 0x00000000, 0x0010F6A0, 0x08B19000, 0x0010F6A0 },
    { 0x00000000, 0x001622E0, 0x08C28800, 0x001622E0 },
};

static void (*lbl_1_data_1C8C[5])(void) = { fn_1_C188, fn_1_BDD8, fn_1_A634, fn_1_BA64, fn_1_B4A4 };

static u8 lbl_1_data_1CA0 = 0x12;

static s16 lbl_1_data_1CA2 = 0x0151;

static s16 lbl_1_data_1CA4 = 0x0151;

static s32 lbl_1_data_1CA8 = 0x151;

static u8 lbl_1_bss_3058[0x18];
static s16 lbl_1_bss_3056;
static s16 lbl_1_bss_3054;
static s32 lbl_1_bss_3050;
static s32 lbl_1_bss_304C;
static s32 lbl_1_bss_3048;
static s32 lbl_1_bss_3044;
static f32 lbl_1_bss_300C[14];
static f32 lbl_1_bss_2FF0[7];
static u8 lbl_1_bss_2FEE;
static u8 lbl_1_bss_2FED;
static u8 lbl_1_bss_2FEC;
static s16 lbl_1_bss_2FEA;
static u8 lbl_1_bss_2FE8;
static s16 lbl_1_bss_2FE6;
static s16 lbl_1_bss_2FE4;
static s16 lbl_1_bss_2FE2;
static u8 lbl_1_bss_2FE1;
static u8 lbl_1_bss_2FE0;
static u8 lbl_1_bss_2FDF;
static u8 lbl_1_bss_2FDE;
static u8 lbl_1_bss_2FDD;
static u8 lbl_1_bss_2FDC;
static u8 lbl_1_bss_2FDB;
static u8 lbl_1_bss_2FDA;
static u8 lbl_1_bss_2FD9;
static u8 lbl_1_bss_2FD8;

static inline s32 ListVisible02A8(List02A8* list) {
    if (list->_08 + list->_0C < list->_10) {
        return list->_0C;
    }
    if (list->_10 < list->_0C) {
        return list->_10;
    }
    return list->_10 - list->_08;
}

// .text:0x0000C2A4 size:0x38
void fn_1_C2A4(void) {
    ((Task02A8*)lbl_803CC1B8)->_0C->_10 = 1;
    fn_800B0A14_removeQueue();
}

// .text:0x0000C188 size:0x11C
void fn_1_C188(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FDD) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(lbl_1_bss_2FD9 + 5, fn_1_A908);
        lbl_1_bss_2FDD++;
        break;
    case 1:
        if (task->_10 != 0) {
            if (lbl_1_bss_2FD9 != 17) {
                lbl_1_bss_2FD9++;
                lbl_1_bss_2FDD = 0;
                break;
            }
            task->_10 = 0;
            lbl_1_bss_2FDD++;
        }
        break;
    case 2:
        task->_00 = fn_1_BFB0;
        lbl_1_bss_2FDD = 0;
        break;
    }
}

// .text:0x0000BFB0 size:0x1D8
void fn_1_BFB0(void) {
    u16 trg = lbl_803C77B8[0]._02;
    u16 rep = lbl_803C77B8[0]._04;
    s16 n;

    if (trg & 0x100) {
        fn_1_BF34((u16)(lbl_1_bss_3056 % 13 + lbl_1_data_17C4[lbl_1_bss_3056 / 13]));
    } else if (trg & 0x1200) {
        fn_1_A718();
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A348;
    } else if (rep & 1) {
        if (rep & 0x800) {
            lbl_1_bss_3056 -= 10;
        } else {
            lbl_1_bss_3056 -= 1;
        }
        if (lbl_1_bss_3056 < 0) {
            lbl_1_bss_3056 = 233;
        }
    } else if (rep & 2) {
        n = lbl_1_bss_3056 + 1;
        if (rep & 0x800) {
            n = lbl_1_bss_3056 + 10;
        }
        lbl_1_bss_3056 = n;
        if (n > 233) {
            lbl_1_bss_3056 = 0;
        }
    }
}

// .text:0x0000BF34 size:0x7C
s32 fn_1_BF34(s32 fx) {
    SND_VOICEID vid = sndFXStartEx(fx, 0x7F, 0x3F, 0);

    OSReport("sndFXReverb was %s.\n", sndFXCtrl(vid, 0x5B, fn_800211F0()) ? "succeed" : "failed");
    return vid;
}

// .text:0x0000BEF4 size:0x40
void fn_1_BEF4(s16 vid) {
    sndFXKeyOff(vid);
    sndFXCtrl(vid, 7, 0);
}

// .text:0x0000BDD8 size:0x11C
void fn_1_BDD8(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FDE) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(lbl_1_data_1CA0 + 5, fn_1_A8B4);
        lbl_1_bss_2FDE++;
        break;
    case 1:
        if (task->_10 != 0) {
            if (lbl_1_data_1CA0 != 31) {
                lbl_1_data_1CA0++;
                lbl_1_bss_2FDE = 0;
                break;
            }
            task->_10 = 0;
            lbl_1_bss_2FDE++;
        }
        break;
    case 2:
        task->_00 = fn_1_BC00;
        lbl_1_bss_2FDE = 0;
        break;
    }
}

// .text:0x0000BC00 size:0x1D8
void fn_1_BC00(void) {
    u16 trg = lbl_803C77B8[0]._02;
    u16 rep = lbl_803C77B8[0]._04;
    s16 n;

    if (trg & 0x100) {
        fn_1_BF34((u16)(lbl_1_bss_3054 % 13 + lbl_1_data_17E8[lbl_1_bss_3054 / 13]));
    } else if (trg & 0x1200) {
        fn_1_A718();
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A348;
    } else if (rep & 1) {
        if (rep & 0x800) {
            lbl_1_bss_3054 -= 10;
        } else {
            lbl_1_bss_3054 -= 1;
        }
        if (lbl_1_bss_3054 < 0) {
            lbl_1_bss_3054 = 181;
        }
    } else if (rep & 2) {
        n = lbl_1_bss_3054 + 1;
        if (rep & 0x800) {
            n = lbl_1_bss_3054 + 10;
        }
        lbl_1_bss_3054 = n;
        if (n > 181) {
            lbl_1_bss_3054 = 0;
        }
    }
}

// .text:0x0000BA64 size:0x19C
void fn_1_BA64(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FDF) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(1, fn_1_A880);
        lbl_1_bss_2FDF++;
        break;
    case 1:
        if (task->_10 != 0) {
            task->_10 = 0;
            lbl_1_bss_2FDF++;
        }
        break;
    case 2:
        task->_10 = 0;
        lbl_1_bss_2FDF++;
        break;
    case 3:
        task->_10 = 0;
        lbl_1_bss_2FDF++;
        break;
    case 4:
        lbl_1_bss_2FDF++;
        break;
    case 5:
        lbl_1_bss_2FDF++;
        break;
    case 6:
        task->_10 = 0;
        fn_1_9EA0(41, fn_1_A77C);
        lbl_1_bss_2FDF++;
        break;
    case 7:
        if (task->_10 != 0) {
            task->_10 = 0;
            lbl_1_bss_2FDF++;
        }
        break;
    case 8:
        task->_00 = fn_1_B5B8;
        lbl_1_bss_2FDF = 0;
        break;
    }
}

// .text:0x0000B5B8 size:0x4AC
// Registers differ (rep & 0x800, trg and the loop counter), and the target
// converts fx with clrlwi before the inlined sndFXStartEx where this copies it.
void fn_1_B5B8(void) {
    u16 rep = lbl_803C77B8[0]._04;
    u16 trg = lbl_803C77B8[0]._02;
    s8 i;
    s16 n;
    s32 fx;

    if (rep & 0x800) {
        lbl_1_bss_2FE0 = 0;
    } else if (rep & 0x400) {
        lbl_1_bss_2FE0 = 1;
    } else if (lbl_1_bss_2FE0 == 0) {
        if (trg & 0x100) {
            if (lbl_1_bss_2FE1 == 0) {
                fn_1_BEF4(lbl_1_bss_3050);
                lbl_1_bss_3050 = fn_1_BF34(lbl_1_data_1CA2);
            } else if (lbl_1_bss_2FE1 == 1) {
                fx = lbl_1_data_188C[lbl_1_bss_2FE2];
                fn_1_BEF4(lbl_1_bss_304C);
                lbl_1_bss_304C = fn_1_BF34(fx);
            } else if (lbl_1_bss_2FE1 == 2) {
                fx = lbl_1_data_18EC[lbl_1_bss_2FE4];
                fn_1_BEF4(lbl_1_bss_3048);
                lbl_1_bss_3048 = fn_1_BF34(fx);
            } else if (lbl_1_bss_2FE1 == 3) {
                lbl_1_bss_3044 = fn_80062890(lbl_1_bss_2FE6);
            }
        } else if (trg & 0x1200) {
            for (i = (s8)lbl_800EF808._390 - 1; i > 0; i--) {
                if (!fn_800214D0()) {
                    break;
                }
            }
            fn_800ACFB0(lbl_800EF808.groups[0x29]);
            fn_800ACFB0(lbl_800EF808.groups[1]);
            ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A348;
        } else if (rep & 1) {
            if (lbl_1_bss_2FE1 == 0) {
                if (rep & 0x800) {
                    lbl_1_data_1CA2 -= 10;
                } else {
                    lbl_1_data_1CA2 -= 1;
                }
                if (lbl_1_data_1CA2 < 0x151) {
                    lbl_1_data_1CA2 = 0x1B6;
                }
            } else if (lbl_1_bss_2FE1 == 1) {
                if (--lbl_1_bss_2FE2 < 0) {
                    lbl_1_bss_2FE2 = 47;
                }
            } else if (lbl_1_bss_2FE1 == 2) {
                if (--lbl_1_bss_2FE4 < 0) {
                    lbl_1_bss_2FE4 = 23;
                }
            } else if (lbl_1_bss_2FE1 == 3) {
                if (--lbl_1_bss_2FE6 < 0) {
                    lbl_1_bss_2FE6 = 68;
                }
            }
        } else if (rep & 2) {
            if (lbl_1_bss_2FE1 == 0) {
                n = lbl_1_data_1CA2 + 1;
                if (rep & 0x800) {
                    n = lbl_1_data_1CA2 + 10;
                }
                lbl_1_data_1CA2 = n;
                if (n > 0x1B6) {
                    lbl_1_data_1CA2 = 0x151;
                }
            } else if (lbl_1_bss_2FE1 == 1) {
                if (++lbl_1_bss_2FE2 > 47) {
                    lbl_1_bss_2FE2 = 0;
                }
            } else if (lbl_1_bss_2FE1 == 2) {
                if (++lbl_1_bss_2FE4 > 23) {
                    lbl_1_bss_2FE4 = 0;
                }
            } else if (lbl_1_bss_2FE1 == 3) {
                if (++lbl_1_bss_2FE6 > 68) {
                    lbl_1_bss_2FE6 = 0;
                }
            }
        } else if (rep & 8) {
            if (--lbl_1_bss_2FE1 < 0) {
                lbl_1_bss_2FE1 = 3;
            }
        } else if (rep & 4) {
            if (++lbl_1_bss_2FE1 > 3) {
                lbl_1_bss_2FE1 = 0;
            }
        }
    }
}

// .text:0x0000B4A4 size:0x114
void fn_1_B4A4(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FE8) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(42, fn_1_A7E4);
        lbl_1_bss_2FE8++;
        break;
    case 1:
        if (task->_10 != 0) {
            lbl_800EF808._396 = 2;
            sndOutputMode(2);
            task->_10 = 0;
            lbl_1_bss_2FE8++;
        }
        break;
    case 2:
        task->_00 = fn_1_A95C;
        lbl_1_common_bss_49994._E0 = 0;
        lbl_1_bss_2FE8 = 0;
        break;
    }
}

// Loads a sound group into its slot of the bank table; the slot is computed by the caller
static inline void LoadGroup02A8(s32 group, s32 slot) {
    fn_80021518(group, lbl_800EF808.groups[slot]);
}

// .text:0x0000A908 size:0x54
s32 fn_1_A908(u8* arg0) {
    LoadGroup02A8(lbl_1_data_17A4[lbl_1_bss_2FD9], lbl_1_bss_2FD9 + 5);
    return 0;
}

// .text:0x0000A8B4 size:0x54
s32 fn_1_A8B4(u8* arg0) {
    LoadGroup02A8(lbl_1_data_17A4[lbl_1_data_1CA0], lbl_1_data_1CA0 + 5);
    return 0;
}

// .text:0x0000A880 size:0x34
s32 fn_1_A880(u8* arg0) {
    fn_80021518(0x1C, lbl_800EF808.groups[1]);
    return 0;
}

// .text:0x0000A838 size:0x48
s32 fn_1_A838(u8* arg0) {
    fn_80021518(0x1C, lbl_800EF808.groups[3]);
    fn_80021518(0x36, lbl_800EF808.groups[3]);
    return 0;
}

// .text:0x0000A7E4 size:0x54
s32 fn_1_A7E4(u8* arg0) {
    LoadGroup02A8(lbl_1_data_1884[lbl_1_bss_2FDB], lbl_1_bss_2FDB + 42);
    return 0;
}

// .text:0x0000A7B0 size:0x34
s32 fn_1_A7B0(u8* arg0) {
    fn_80021518(0x33, lbl_800EF808.groups[49]);
    return 0;
}

// .text:0x0000A77C size:0x34
s32 fn_1_A77C(u8* arg0) {
    fn_80021518(0x31, lbl_800EF808.groups[41]);
    return 0;
}

// .text:0x0000A718 size:0x64
BOOL fn_1_A718(void) {
    s8 i;

    for (i = (s8)lbl_800EF808._390 - 1; i > 0; i--) {
        if (!fn_800214D0()) {
            return FALSE;
        }
    }
    return TRUE;
}

// .text:0x0000A714 size:0x4
void fn_1_A714(void) {
}

// .text:0x0000A634 size:0xE0
void fn_1_A634(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FEE) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(3, fn_1_A838);
        lbl_1_bss_2FEE++;
        break;
    case 1:
        if (task->_10 != 0) {
            task->_10 = 0;
            lbl_1_bss_2FEE++;
        }
        break;
    case 2:
        task->_00 = fn_1_A464;
        lbl_1_bss_2FEE = 0;
        break;
    }
}

// .text:0x0000A464 size:0x1D0
void fn_1_A464(void) {
    u16 trg = lbl_803C77B8[0]._02;
    u16 rep = lbl_803C77B8[0]._04;
    s16 n;

    if (trg & 0x100) {
        fn_1_BEF4(lbl_1_data_1CA8);
        lbl_1_data_1CA8 = fn_1_BF34(lbl_1_data_1CA4);
    } else if (trg & 0x1200) {
        fn_1_A718();
        fn_800ACFB0(lbl_800EF808.groups[3]);
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A348;
    } else if (rep & 1) {
        if (rep & 0x800) {
            lbl_1_data_1CA4 -= 10;
        } else {
            lbl_1_data_1CA4 -= 1;
        }
        if (lbl_1_data_1CA4 < 0x1AD) {
            lbl_1_data_1CA4 = 0x1B6;
        }
    } else if (rep & 2) {
        n = lbl_1_data_1CA4 + 1;
        if (rep & 0x800) {
            n = lbl_1_data_1CA4 + 10;
        }
        lbl_1_data_1CA4 = n;
        if (n > 0x1B6) {
            lbl_1_data_1CA4 = 0x151;
        }
    }
}

// .text:0x0000A348 size:0x11C
void fn_1_A348(void) {
    u16 rep = lbl_803C77B8[0]._04;
    u16 trg = lbl_803C77B8[0]._02;

    if (rep & 8) {
        lbl_1_common_bss_49A78._00 = (lbl_1_common_bss_49A78._00 + 4) % 5;
    } else if (rep & 4) {
        lbl_1_common_bss_49A78._00 = (lbl_1_common_bss_49A78._00 + 6) % 5;
    } else if (trg & 0x100) {
        ((Task02A8*)lbl_803CC1B8)->_00 = lbl_1_data_1C8C[lbl_1_common_bss_49A78._00];
        lbl_1_common_bss_49A78._01 = 0;
    } else if (trg & 0x1200) {
        lbl_1_bss_2FDA = 0;
        lbl_1_bss_2FD9 = 0;
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_C2A4;
    }
}

// .text:0x0000A2E4 size:0x64
void fn_1_A2E4(void) {
    switch (lbl_1_bss_2FDA) {
    case 0:
        lbl_1_bss_2FDA++;
        break;
    case 1:
        lbl_1_bss_2FDA++;
        break;
    case 2:
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A250;
        break;
    }
}

// .text:0x0000A250 size:0x94
void fn_1_A250(void) {
    s32 i;

    for (i = 0; i < 11; i++) {
        lbl_1_common_bss_49A78._24[i] = -1;
    }
    lbl_1_common_bss_49A78._0C = -1;
    ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A348;
}

// .text:0x0000A210 size:0x40
char* fn_1_A210(char* path) {
    char c;
    char* name = path;

    if (path == NULL) {
        return NULL;
    }
    while ((c = *path++) != 0) {
        if (c == '/') {
            name = path;
        }
    }
    return name;
}

// .text:0x0000A1F4 size:0x1C
void fn_1_A1F4(List02A8* list, ListEntry02A8* entries, s32 count, s32 page) {
    list->_00 = entries;
    list->_10 = count;
    list->_0C = page;
    list->_08 = 0;
    list->_04 = 0;
}

// .text:0x0000A184 size:0x70
// Differs only in registers: the entry pointer takes r3 and the string r4, the
// target the reverse (r5/r3). Declaration orders and loop forms did not change it.
void fn_1_A184(List02A8* list) {
    s32 n = ListVisible02A8(list);
    ListEntry02A8* entry = &list->_00[list->_08];
    s32 i;
    char* p;

    for (i = 0; i < n; i++, entry++) {
        if ((p = entry->_00) != NULL) {
            while (*p++ != 0) {
            }
        }
    }
}

// .text:0x0000A024 size:0x160
void fn_1_A024(List02A8* list, s32 dir) {
    s32 top = list->_08;
    s32 page = list->_0C;
    s32 count = list->_10;
    s32 cur = list->_04;
    s32 rel = cur - top;
    s32 n;

    if (top + page < count) {
        n = page;
    } else if (count < page) {
        n = count;
    } else {
        n = count - top;
    }

    switch (dir) {
    case 0:
        if (rel != 0) {
            list->_04--;
        } else if (top != 0) {
            list->_08--;
            list->_04--;
        }
        break;
    case 1:
        if (rel + 1 == n) {
            if (cur + 1 < count) {
                list->_08++;
                list->_04++;
            }
        } else {
            list->_04++;
        }
        break;
    case 2:
        if (top < page) {
            list->_08 = 0;
            list->_04 = 0;
        } else {
            list->_08 -= page;
            list->_04 -= list->_0C;
        }
        break;
    case 3:
        if (cur + n >= count) {
            list->_08 = count - n;
            list->_04 = list->_10 - 1;
        } else {
            list->_08 += page;
            list->_04 += list->_0C;
        }
        break;
    }
}

// .text:0x00009F04 size:0x120
void fn_1_9F04(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (task->_18) {
    case 0:
        lbl_800EF808.groups[task->_19] = ARAMTransfer(&lbl_1_data_196C[task->_19], 0, 1, 0);
        task->_18 = 1;
        break;
    case 1:
        if (lbl_803C6CF8._715 != 1) {
            break;
        }
        fn_80021980(lbl_800EF808.groups[task->_19]);
        task->_18 = 2;
        task->_1A = 0;
    case 2:
        if (task->_14(&task->_1A) == 0) {
            fn_80021954(&lbl_800EF808.groups[task->_19]);
            task->_0C->_10 = 1;
            fn_800B0A14_removeQueue();
        }
        break;
    }
}

// .text:0x00009EA0 size:0x64
void fn_1_9EA0(s32 index, s32 (*callback)(u8* arg0)) {
    Task02A8* task = fn_800B0A5C_insertQueue(fn_1_9F04, 1);

    task->_18 = 0;
    task->_19 = index;
    task->_14 = callback;
    ((Task02A8*)lbl_803CC1B8)->_10 = 0;
}
