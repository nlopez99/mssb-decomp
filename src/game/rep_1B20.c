#include "game/rep_1B20.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/rep_1B70.h"
#include "game/rep_CC8.h"
#include "game/rep_D18.h"
#include "musyx/musyx.h"
#include "game/rep_1C18.h"
#include "game/m_sound.h"
#include "game/rep_F80.h"

typedef struct AramEntry1B20 {
    /* 0x0 */ u32 _0[4];
} AramEntry1B20; // size: 0x10

extern struct {
    /* 0x000 */ s32 _000;
    /* 0x004 */ u8 _004[0xA - 0x4];
    /* 0x00A */ s16 _00A;
    /* 0x00C */ s16 _00C;
    /* 0x00E */ u8 _00E[0x12 - 0xE];
    /* 0x012 */ s16 _012;
    /* 0x014 */ u8 _014[0x1D0 - 0x14];
    /* 0x1D0 */ u8 _1D0;
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4[0x1D9 - 0x1D4];
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ s8 _1DA;
    /* 0x1DB */ u8 _1DB[0x221 - 0x1DB];
    /* 0x221 */ u8 _221;
    /* 0x222 */ u8 _222;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x00 */ u8 _00[0xC3];
    /* 0xC3 */ u8 _C3;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11[0x13 - 0x11];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern struct {
    /* 0x0000 */ u8 _0000[0x2D46];
    /* 0x2D46 */ u8 _2D46;
    /* 0x2D47 */ u8 _2D47[0x2D52 - 0x2D47];
    /* 0x2D52 */ u8 _2D52;
    /* 0x2D53 */ u8 _2D53[0x307D - 0x2D53];
    /* 0x307D */ u8 _307D;
    /* 0x307E */ u8 _307E;
} lbl_8036E548;

extern void changeScene(u8, s16);
extern void minigamesSetSomePointers(void);
extern u8 lbl_800EFBA4[0x10];
extern int fn_80035838(AramEntry1B20* entry, int count);
extern void fn_80035B50(int arg);
extern void fn_8004CC18(void);
extern void fn_80011A60(void);
extern void fn_80011BE4(int arg);

extern u8 lbl_3_data_FC30[];
extern u8 lbl_3_data_FCE8[];
extern u8 lbl_3_data_FD54[];
extern u8 lbl_3_data_FD90[];
extern u8 lbl_3_data_FDF4[];
extern u8 lbl_3_data_FE88[];
extern u8 lbl_3_data_FF28[];
extern u8 lbl_3_data_FFB0[];
extern u8 lbl_3_data_10020[];
extern u8 lbl_3_data_100B0[];
extern u8 lbl_3_data_100E4[];
extern u8 lbl_3_data_10174[];
extern u8 lbl_3_data_101F0[];
extern u8 lbl_3_data_102A8[];
extern u8 lbl_3_data_10318[];
extern u8 lbl_3_data_10368[];

u8 lbl_3_data_FAA8[3][9] = {
    { 0x00, 0x0D, 0x1D, 0x1E, 0x1F, 0x20, 0x18, 0x19, 0x1A },
    { 0x01, 0x15, 0x16, 0x14, 0x17, 0x2B, 0x2C, 0x10, 0x2D },
    { 0x06, 0x04, 0x00, 0x09, 0x02, 0x05, 0x0A, 0x0B, 0x01 },
};
u8 lbl_3_data_FAC4[8] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00, 0x00,
};
u8 lbl_3_data_FACC[5][5] = {
    { 4, 0, 1, 2, 3 },
    { 4, 0, 1, 2, 3 },
    { 4, 0, 1, 2, 3 },
    { 4, 0, 1, 2, 3 },
    { 4, 4, 5, 6, 7 },
};
u8 lbl_3_data_FAE8[2][5] = {
    { 4, 0, 1, 2, 3 },
    { 3, 1, 2, 3, 0 },
};
u8 lbl_3_data_FAF4[4][4] = {
    { 5, 5, 5, 5 },
    { 5, 5, 5, 5 },
    { 3, 3, 3, 3 },
    { 5, 5, 5, 5 },
};
s16 lbl_3_data_FB04 = 90;
s16 lbl_3_data_FB08[10][3] = {
    { 100, 40, 1000 },
    { 100, 80, 1300 },
    { 100, 70, 800 },
    { 100, 50, 870 },
    { 100, 60, 940 },
    { 100, 20, 1100 },
    { 100, 30, 1170 },
    { 100, 60, 1240 },
    { 100, 70, 1310 },
    { 100, 50, 1390 },
};
s16 lbl_3_data_FB44[10][3] = {
    { 130, 400, 1000 },
    { 100, 80, 1300 },
    { 130, 400, 800 },
    { 100, 50, 870 },
    { 130, 400, 940 },
    { 130, 400, 750 },
    { 100, 50, 1170 },
    { 130, 400, 1240 },
    { 100, 70, 1310 },
    { 130, 400, 1090 },
};
s16 lbl_3_data_FB80[10][3] = {
    { 160, 250, 600 },
    { 130, 200, 650 },
    { 160, 250, 800 },
    { 160, 300, 900 },
    { 160, 250, 1100 },
    { 160, 250, 1200 },
    { 160, 250, 1250 },
    { 160, 250, 1300 },
    { 160, 250, 1350 },
    { 160, 250, 1400 },
};
s16 lbl_3_data_FBBC[10][3] = {
    { 160, 280, 750 },
    { 125, 370, 640 },
    { 155, 280, 1250 },
    { 150, 300, 910 },
    { 155, 250, 1100 },
    { 130, 350, 1100 },
    { 140, 250, 1250 },
    { 140, 280, 1220 },
    { 125, 365, 1350 },
    { 150, 240, 1400 },
};
s16 lbl_3_data_FBF8[8] = {
    60, 120, 90, 120, 300, 90, 120, 0,
};
u8 lbl_3_data_FC08[16] = {
    0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01,
};
u8 lbl_3_data_FC18[4] = { 0x01, 0x00, 0x06, 0x0A };
s16 lbl_3_data_FC1C[2] = { 90, 90 };
void* lbl_3_data_FC20[4] = { lbl_3_data_FC30, lbl_3_data_FCE8, lbl_3_data_FD54, lbl_3_data_FD90 };
u8 lbl_3_data_FC30[184] = {
    0x21, 0x00, 0xB0, 0x1B, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x1C, 0x22, 0x00,
    0xB0, 0x68, 0x49, 0x00, 0x42, 0x01, 0x43, 0x01, 0x51, 0x00, 0x01, 0x00, 0x90, 0x3C, 0x14, 0x00,
    0x00, 0x02, 0x80, 0x0A, 0x01, 0x00, 0x80, 0x3C, 0x14, 0x00, 0x00, 0x01, 0x80, 0x0F, 0x01, 0x00,
    0x80, 0x3C, 0x14, 0x00, 0x00, 0x02, 0x80, 0x05, 0x04, 0x00, 0x52, 0x00, 0x41, 0x00, 0x23, 0x00,
    0x21, 0x00, 0xB0, 0x1D, 0x22, 0x00, 0xB0, 0x69, 0x42, 0x02, 0x43, 0x02, 0x01, 0x00, 0x80, 0x1E,
    0x13, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0xE6, 0x04, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00,
    0xB0, 0x1E, 0x22, 0x00, 0xB0, 0x6A, 0x42, 0x01, 0x43, 0x03, 0x01, 0x00, 0x80, 0x1E, 0x13, 0x00,
    0x01, 0x00, 0x01, 0x00, 0x80, 0x5A, 0x14, 0x00, 0x00, 0x02, 0x80, 0x64, 0x01, 0x00, 0x80, 0x8C,
    0x04, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x1F, 0x22, 0x00, 0xB0, 0x6B, 0x42, 0x01,
    0x43, 0x04, 0x01, 0x00, 0x80, 0x1E, 0x13, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x5A, 0x14, 0x00,
    0x00, 0x01, 0x80, 0x64, 0x01, 0x00, 0x80, 0x96, 0x04, 0x00, 0x48, 0x00, 0x23, 0x00, 0x41, 0x00,
    0x21, 0x00, 0xB0, 0x20, 0x7F, 0x00, 0x00, 0x00,
};
u8 lbl_3_data_FCE8[108] = {
    0x21, 0x00, 0xB0, 0x21, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x22, 0x22, 0x00,
    0xB0, 0x6C, 0x49, 0x00, 0x42, 0x02, 0x43, 0x05, 0x14, 0x00, 0x01, 0x00, 0x80, 0x64, 0x01, 0x00,
    0x80, 0x46, 0x03, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x23, 0x22, 0x00, 0xB0, 0x6D,
    0x42, 0x02, 0x43, 0x06, 0x13, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0xDC, 0x04, 0x00, 0x23, 0x00,
    0x41, 0x00, 0x21, 0x00, 0xB0, 0x24, 0x22, 0x00, 0xB0, 0x6D, 0x42, 0x02, 0x43, 0x06, 0x14, 0x00,
    0x01, 0x00, 0x80, 0x73, 0x01, 0x00, 0x80, 0x62, 0x01, 0x00, 0x80, 0xD2, 0x04, 0x00, 0x48, 0x00,
    0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x25, 0x7F, 0x00, 0x00, 0x00,
};
u8 lbl_3_data_FD54[60] = {
    0x21, 0x00, 0xB0, 0x26, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x27, 0x01, 0x00,
    0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x28, 0x49, 0x00, 0x22, 0x00, 0xB0, 0x6E, 0x42, 0x07,
    0x43, 0x07, 0x14, 0x00, 0x01, 0x04, 0x80, 0x0A, 0x01, 0x00, 0x80, 0xE6, 0x04, 0x00, 0x48, 0x00,
    0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x29, 0x7F, 0x00, 0x00, 0x00,
};
u8 lbl_3_data_FD90[84] = {
    0x21, 0x00, 0xB0, 0x2A, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x2B, 0x01, 0x00,
    0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x2C, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00,
    0xB0, 0x2D, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x2E, 0x49, 0x00, 0x22, 0x00,
    0xB0, 0x6F, 0x42, 0x08, 0x43, 0x08, 0x14, 0x00, 0x00, 0x20, 0x80, 0x0A, 0x13, 0x00, 0x01, 0x00,
    0x01, 0x00, 0x80, 0xB4, 0x04, 0x00, 0x48, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x2F,
    0x7F, 0x00, 0x00, 0x00,
};
void* lbl_3_data_FDE4[4] = { lbl_3_data_FDF4, lbl_3_data_FE88, lbl_3_data_FF28, lbl_3_data_FFB0 };
u8 lbl_3_data_FDF4[148] = {
    0x21, 0x00, 0xB0, 0x30, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x31, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x70, 0x42, 0x01, 0x43, 0x09, 0x01, 0x00, 0x90, 0x3C, 0x12, 0x00, 0x00, 0x08,
    0x80, 0x0A, 0x01, 0x00, 0x80, 0x14, 0x12, 0x00, 0x00, 0x02, 0x80, 0x0A, 0x01, 0x00, 0x80, 0x14,
    0x12, 0x00, 0x00, 0x04, 0x80, 0x0F, 0x01, 0x00, 0x80, 0x14, 0x12, 0x00, 0x00, 0x01, 0x80, 0x0F,
    0x01, 0x00, 0x80, 0x14, 0x12, 0x00, 0x00, 0x08, 0x80, 0x0A, 0x01, 0x00, 0x80, 0x14, 0x12, 0x00,
    0x00, 0x02, 0x80, 0x05, 0x01, 0x00, 0x80, 0x06, 0x04, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00,
    0xB0, 0x32, 0x22, 0x00, 0xB0, 0x71, 0x42, 0x02, 0x43, 0x02, 0x01, 0x00, 0x80, 0x3C, 0x13, 0x00,
    0x01, 0x00, 0x33, 0x00, 0x32, 0x00, 0x00, 0x96, 0x00, 0x96, 0x04, 0xA6, 0x01, 0x00, 0x80, 0xDC,
    0x04, 0x00, 0x31, 0x00, 0x23, 0x00, 0x41, 0x00, 0x01, 0x00, 0x80, 0x3C, 0x21, 0x00, 0xB0, 0x37,
    0x48, 0x00, 0x7F, 0x00,
};
u8 lbl_3_data_FE88[160] = {
    0x21, 0x00, 0xB0, 0x38, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x39, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x76, 0x42, 0x02, 0x43, 0x05, 0x01, 0x00, 0x80, 0x14, 0x12, 0x00, 0x01, 0x00,
    0x80, 0xF8, 0x01, 0x00, 0x80, 0x46, 0x03, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x3A,
    0x22, 0x00, 0xB0, 0x77, 0x42, 0x02, 0x43, 0x06, 0x01, 0x00, 0x80, 0x3C, 0x13, 0x00, 0x01, 0x00,
    0x33, 0x01, 0x32, 0x00, 0x00, 0x98, 0x00, 0x64, 0x04, 0xA8, 0x01, 0x00, 0x80, 0xDC, 0x04, 0x00,
    0x31, 0x00, 0x23, 0x00, 0x41, 0x00, 0x01, 0x00, 0x80, 0x3C, 0x21, 0x00, 0xB0, 0x3B, 0x22, 0x00,
    0xB0, 0x77, 0x42, 0x02, 0x43, 0x06, 0x01, 0x00, 0x80, 0x14, 0x13, 0x00, 0x01, 0x00, 0x01, 0x00,
    0x80, 0x14, 0x12, 0x00, 0x01, 0x00, 0x81, 0x2C, 0x01, 0x00, 0x80, 0x5A, 0x33, 0x01, 0x32, 0x00,
    0x00, 0x9B, 0x01, 0x90, 0x04, 0x9D, 0x01, 0x00, 0x81, 0x0E, 0x04, 0x00, 0x31, 0x00, 0x23, 0x00,
    0x41, 0x00, 0x01, 0x00, 0x80, 0x3C, 0x21, 0x00, 0xB0, 0x3C, 0x48, 0x00, 0x7F, 0x00, 0x00, 0x00,
};
u8 lbl_3_data_FF28[136] = {
    0x21, 0x00, 0xB0, 0x3D, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x3E, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x78, 0x42, 0x03, 0x43, 0x0D, 0x01, 0x00, 0x80, 0x14, 0x12, 0x00, 0x02, 0x00,
    0x83, 0xE8, 0x01, 0x00, 0x80, 0x3C, 0x03, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x3F,
    0x22, 0x00, 0xB0, 0x79, 0x42, 0x01, 0x43, 0x09, 0x01, 0x00, 0x80, 0x14, 0x13, 0x00, 0x01, 0x00,
    0x01, 0x00, 0x80, 0x0A, 0x12, 0x00, 0x02, 0x01, 0x80, 0x0A, 0x01, 0x00, 0x80, 0x0A, 0x12, 0x00,
    0x02, 0x02, 0x80, 0x0F, 0x01, 0x00, 0x80, 0x0F, 0x12, 0x00, 0x02, 0x01, 0x80, 0x03, 0x01, 0x00,
    0x80, 0x03, 0x12, 0x00, 0x02, 0x00, 0x80, 0xC8, 0x32, 0x00, 0x00, 0x32, 0x0F, 0xC7, 0x02, 0x30,
    0x01, 0x00, 0x80, 0xDC, 0x04, 0x00, 0x31, 0x00, 0x23, 0x00, 0x41, 0x00, 0x01, 0x00, 0x80, 0x3C,
    0x21, 0x00, 0xB0, 0x40, 0x48, 0x00, 0x7F, 0x00,
};
u8 lbl_3_data_FFB0[96] = {
    0x21, 0x00, 0xB0, 0x41, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x42, 0x01, 0x00,
    0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x43, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00,
    0xB0, 0x44, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x45, 0x49, 0x00, 0x22, 0x00,
    0xB0, 0x7A, 0x42, 0x08, 0x43, 0x08, 0x13, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x6E, 0x33, 0x02,
    0x32, 0x00, 0x00, 0xC3, 0x00, 0x3C, 0x04, 0xA8, 0x01, 0x00, 0x80, 0xB4, 0x04, 0x00, 0x31, 0x00,
    0x23, 0x00, 0x41, 0x00, 0x01, 0x00, 0x80, 0x3C, 0x21, 0x00, 0xB0, 0x46, 0x48, 0x00, 0x7F, 0x00,
};
void* lbl_3_data_10010[4] = { lbl_3_data_10020, lbl_3_data_100B0, lbl_3_data_100E4, lbl_3_data_10174 };
u8 lbl_3_data_10020[144] = {
    0x21, 0x00, 0xB0, 0x47, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x48, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x7B, 0x42, 0x05, 0x43, 0x0F, 0x12, 0x00, 0x08, 0x00, 0x80, 0x01, 0x01, 0x00,
    0x80, 0x78, 0x12, 0x00, 0x04, 0x00, 0x80, 0x01, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x23, 0x00,
    0x21, 0x00, 0xB0, 0x49, 0x22, 0x00, 0xB0, 0x7C, 0x42, 0x04, 0x43, 0x10, 0x12, 0x00, 0x04, 0x00,
    0x80, 0x01, 0x01, 0x00, 0x80, 0x96, 0x04, 0x00, 0x23, 0x00, 0x21, 0x00, 0xB0, 0x4A, 0x22, 0x00,
    0xB0, 0x7D, 0x42, 0x09, 0x43, 0x11, 0x01, 0x00, 0x80, 0x14, 0x12, 0x00, 0x08, 0x00, 0x80, 0x01,
    0x01, 0x00, 0x80, 0x78, 0x12, 0x00, 0x04, 0x00, 0x80, 0x01, 0x01, 0x00, 0x80, 0x3C, 0x12, 0x00,
    0x04, 0x00, 0x80, 0x01, 0x01, 0x00, 0x80, 0x3C, 0x12, 0x00, 0x08, 0x00, 0x80, 0x01, 0x01, 0x00,
    0x80, 0x28, 0x04, 0x00, 0x48, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x4B, 0x7F, 0x00,
};
u8 lbl_3_data_100B0[52] = {
    0x21, 0x00, 0xB0, 0x4C, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x4D, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x7E, 0x42, 0x03, 0x43, 0x12, 0x12, 0x00, 0x08, 0x00, 0x80, 0x01, 0x15, 0x00,
    0x01, 0x00, 0x80, 0xC8, 0x04, 0x00, 0x48, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x4E,
    0x7F, 0x00, 0x00, 0x00,
};
u8 lbl_3_data_100E4[144] = {
    0x21, 0x00, 0xB0, 0x4F, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x50, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x7F, 0x42, 0x05, 0x43, 0x0F, 0x12, 0x00, 0x08, 0x00, 0x80, 0x01, 0x01, 0x00,
    0x80, 0x78, 0x12, 0x00, 0x04, 0x00, 0x80, 0x01, 0x01, 0x00, 0x80, 0x28, 0x04, 0x00, 0x23, 0x00,
    0x21, 0x00, 0xB0, 0x51, 0x22, 0x00, 0xB0, 0x80, 0x42, 0x04, 0x43, 0x10, 0x12, 0x00, 0x04, 0x00,
    0x80, 0x01, 0x01, 0x00, 0x80, 0x96, 0x04, 0x00, 0x23, 0x00, 0x21, 0x00, 0xB0, 0x52, 0x22, 0x00,
    0xB0, 0x81, 0x42, 0x09, 0x43, 0x11, 0x01, 0x00, 0x80, 0x14, 0x12, 0x00, 0x08, 0x00, 0x80, 0x01,
    0x01, 0x00, 0x80, 0x78, 0x12, 0x00, 0x04, 0x00, 0x80, 0x01, 0x01, 0x00, 0x80, 0x3C, 0x12, 0x00,
    0x04, 0x00, 0x80, 0x01, 0x01, 0x00, 0x80, 0x3C, 0x12, 0x00, 0x08, 0x00, 0x80, 0x01, 0x01, 0x00,
    0x80, 0x32, 0x04, 0x00, 0x48, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x4B, 0x7F, 0x00,
};
u8 lbl_3_data_10174[108] = {
    0x21, 0x00, 0xB0, 0x54, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x55, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x82, 0x42, 0x01, 0x43, 0x19, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00,
    0xB0, 0x56, 0x12, 0x00, 0x08, 0x04, 0x80, 0x78, 0x01, 0x00, 0x80, 0x78, 0x12, 0x00, 0x04, 0x00,
    0x80, 0x01, 0x01, 0x00, 0x80, 0x3C, 0x12, 0x00, 0x08, 0x01, 0x80, 0x78, 0x01, 0x00, 0x80, 0x78,
    0x12, 0x00, 0x04, 0x00, 0x80, 0x01, 0x01, 0x00, 0x80, 0x3C, 0x12, 0x00, 0x08, 0x08, 0x80, 0x78,
    0x01, 0x00, 0x80, 0x78, 0x12, 0x00, 0x04, 0x00, 0x80, 0x01, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00,
    0x48, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x57, 0x7F, 0x00,
};
void* lbl_3_data_101E0[4] = { lbl_3_data_101F0, lbl_3_data_102A8, lbl_3_data_10318, lbl_3_data_10368 };
u8 lbl_3_data_101F0[184] = {
    0x21, 0x00, 0xB0, 0x58, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x59, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x83, 0x42, 0x01, 0x43, 0x09, 0x01, 0x00, 0x90, 0x3C, 0x13, 0x00, 0x01, 0x00,
    0x01, 0x00, 0x80, 0x75, 0x12, 0x00, 0x01, 0x00, 0x80, 0x08, 0x32, 0x00, 0x00, 0x64, 0x00, 0x50,
    0x04, 0xE2, 0x01, 0x00, 0x80, 0x64, 0x03, 0x00, 0x23, 0x00, 0x21, 0x00, 0xB0, 0x5A, 0x22, 0x00,
    0xB0, 0x84, 0x42, 0x02, 0x43, 0x18, 0x01, 0x00, 0x80, 0x14, 0x14, 0x00, 0x01, 0x02, 0x80, 0x01,
    0x01, 0x00, 0x80, 0x96, 0x03, 0x00, 0x31, 0x00, 0x23, 0x00, 0x41, 0x00, 0x01, 0x00, 0x90, 0x3C,
    0x21, 0x00, 0xB0, 0x5B, 0x22, 0x00, 0xB0, 0x85, 0x42, 0x07, 0x43, 0x19, 0x01, 0x00, 0x90, 0x3C,
    0x13, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x75, 0x12, 0x00, 0x01, 0x00, 0x80, 0x08, 0x32, 0x00,
    0x00, 0x8C, 0x00, 0x8C, 0x03, 0x20, 0x01, 0x00, 0x80, 0x64, 0x14, 0x00, 0x01, 0x08, 0x80, 0x02,
    0x01, 0x00, 0x80, 0x28, 0x14, 0x00, 0x01, 0x01, 0x80, 0x02, 0x01, 0x00, 0x80, 0x4B, 0x14, 0x00,
    0x01, 0x02, 0x80, 0x02, 0x01, 0x00, 0x80, 0xA0, 0x03, 0x00, 0x48, 0x00, 0x23, 0x00, 0x41, 0x00,
    0x21, 0x00, 0xB0, 0x5C, 0x7F, 0x00, 0x00, 0x00,
};
u8 lbl_3_data_102A8[112] = {
    0x21, 0x00, 0xB0, 0x5D, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x5E, 0x01, 0x00,
    0x90, 0x3C, 0x13, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x75, 0x12, 0x00, 0x01, 0x00, 0x80, 0x08,
    0x32, 0x00, 0x00, 0x6E, 0x00, 0x3C, 0x04, 0xB0, 0x01, 0x00, 0x80, 0x5A, 0x14, 0x00, 0x01, 0x00,
    0x80, 0x78, 0x01, 0x00, 0x80, 0x6E, 0x04, 0x00, 0x31, 0x00, 0x01, 0x00, 0x90, 0x3C, 0x21, 0x00,
    0xB0, 0x5F, 0x01, 0x00, 0x80, 0x78, 0x13, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x75, 0x12, 0x00,
    0x01, 0x00, 0x80, 0x08, 0x32, 0x00, 0x00, 0x82, 0x01, 0x90, 0x02, 0xEE, 0x01, 0x00, 0x80, 0xB4,
    0x04, 0x00, 0x31, 0x00, 0x01, 0x00, 0x90, 0x3C, 0x21, 0x00, 0xB0, 0x61, 0x7F, 0x00, 0x00, 0x00,
};
u8 lbl_3_data_10318[80] = {
    0x21, 0x00, 0xB0, 0x62, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x63, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x86, 0x42, 0x03, 0x43, 0x12, 0x01, 0x00, 0x80, 0x3C, 0x13, 0x00, 0x01, 0x00,
    0x01, 0x00, 0x80, 0x75, 0x12, 0x00, 0x01, 0x00, 0x80, 0x08, 0x32, 0x00, 0x00, 0xA5, 0x00, 0xF8,
    0x04, 0xD8, 0x01, 0x00, 0x80, 0x3C, 0x14, 0x00, 0x00, 0x08, 0x80, 0xA0, 0x17, 0x00, 0x01, 0x00,
    0x80, 0xD2, 0x04, 0x00, 0x48, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x64, 0x7F, 0x00,
};
u8 lbl_3_data_10368[80] = {
    0x21, 0x00, 0xB0, 0x65, 0x01, 0x00, 0x80, 0x1E, 0x04, 0x00, 0x21, 0x00, 0xB0, 0x66, 0x49, 0x00,
    0x22, 0x00, 0xB0, 0x87, 0x42, 0x07, 0x43, 0x1B, 0x01, 0x00, 0x80, 0x32, 0x13, 0x00, 0x01, 0x00,
    0x01, 0x00, 0x80, 0x75, 0x12, 0x00, 0x01, 0x00, 0x80, 0x08, 0x32, 0x00, 0x00, 0x8F, 0x01, 0x31,
    0x03, 0x9D, 0x01, 0x00, 0x80, 0x6E, 0x14, 0x00, 0x01, 0x02, 0x80, 0x0A, 0x01, 0x00, 0x80, 0x78,
    0x04, 0x00, 0x48, 0x00, 0x23, 0x00, 0x41, 0x00, 0x21, 0x00, 0xB0, 0x67, 0x7F, 0x00, 0x00, 0x00,
};
s16 lbl_3_data_103B8[128] = {
    1, 104, 2, 105, 3, 106, 4, 107, 5, 108, 6, 109,
    0, 0, 0, 0, 7, 110, 0, 0, 0, 0, 0, 0,
    8, 111, 0, 0, 0, 0, 0, 0, 9, 112, 10, 113,
    0, 0, 0, 0, 11, 118, 12, 119, 0, 0, 0, 0,
    13, 120, 0, 0, 0, 0, 0, 0, 14, 122, 0, 0,
    0, 0, 0, 0, 23, 131, 25, 133, 24, 132, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 26, 134, 0, 0,
    0, 0, 0, 0, 27, 135, 0, 0, 0, 0, 0, 0,
    15, 123, 16, 124, 17, 125, 0, 0, 18, 126, 0, 0,
    0, 0, 0, 0, 19, 127, 20, 128, 21, 129, 0, 0,
    25, 130, 0, 0, 0, 0, 0, 0,
};
s16 lbl_3_data_104B8[16][2][3] = {
    136, -1, -1, 137, -1, -1, 138, -1, -1, 139, -1, -1,
    140, -1, -1, 141, -1, -1, 142, -1, -1, 143, -1, -1,
    144, -1, -1, 145, -1, -1, 146, -1, -1, 147, -1, -1,
    148, -1, -1, 149, -1, -1, 150, -1, -1, 151, -1, -1,
    160, -1, -1, 161, -1, -1, 162, -1, -1, 163, -1, -1,
    164, -1, -1, 165, -1, -1, 166, -1, -1, 167, -1, -1,
    152, -1, -1, 153, -1, -1, 154, -1, -1, 155, -1, -1,
    156, -1, -1, 157, -1, -1, 158, -1, -1, 159, -1, -1,
};
u8 lbl_3_data_10578[32] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x98, 0x08, 0xF2, 0x10, 0x00, 0x00, 0x00, 0x3C, 0x98,
    0x00, 0x00, 0x04, 0x0B, 0x40, 0x00, 0xEB, 0xBC, 0x08, 0xF2, 0x50, 0x00, 0x00, 0x00, 0x95, 0x70,
};
AramEntry1B20 lbl_3_data_10598[62] = {
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
};

// .text:0x000B3A28 size:0x24 mapped:0x806F2ABC
void fn_3_B3A28(void) {
    g_Practice.frames_onPauseScreen = 0;
    lbl_3_common_bss_34C90._1D2 = 0;
    lbl_3_common_bss_34C90._1DA = 0;
}

// .text:0x000B3620 size:0x408 mapped:0x806F26B4
void fn_3_B3620(void) {
    lbl_80366158._28 = 1;
    if (g_Practice.frames_onPauseScreen < 0x7FFE) {
        g_Practice.frames_onPauseScreen++;
    } else {
        g_Practice.frames_onPauseScreen = 0x7FFF;
    }
    if (g_Practice.frames_onPauseScreen2 < 0x7FFE) {
        g_Practice.frames_onPauseScreen2++;
    } else {
        g_Practice.frames_onPauseScreen2 = 0x7FFF;
    }
    if (lbl_3_common_bss_34C90._00A < 0x7FFE) {
        lbl_3_common_bss_34C90._00A++;
    } else {
        lbl_3_common_bss_34C90._00A = 0x7FFF;
    }
    if (lbl_3_common_bss_34C90._00C < 0x7FFE) {
        lbl_3_common_bss_34C90._00C++;
    } else {
        lbl_3_common_bss_34C90._00C = 0x7FFF;
    }
    if (lbl_3_common_bss_34C90._012 < 0x7FFE) {
        lbl_3_common_bss_34C90._012++;
    } else {
        lbl_3_common_bss_34C90._012 = 0x7FFF;
    }
    if (g_Practice._188 < 0x7FFE) {
        g_Practice._188++;
    } else {
        g_Practice._188 = 0x7FFF;
    }
    switch (lbl_3_common_bss_34C90._1D2) {
    case 0:
        if (g_Practice.practiceLevel == lbl_3_data_FACC[g_Practice.practiceType_2][0] - 1) {
            lbl_3_common_bss_34C90._1D0 = 8;
        } else {
            lbl_3_common_bss_34C90._1D0 = 7;
        }
        lbl_3_common_bss_34C90._000 = g_Practice.homeAway;
        g_Practice.frames_onPauseScreen2 = 0;
        lbl_3_common_bss_34C90._1D2 = 1;
        break;
    case 1:
        if (g_Practice.frames_onPauseScreen2 > 30) {
            lbl_3_common_bss_34C90._1D2 = 2;
        }
        break;
    case 2:
        fn_3_B3448();
        lbl_3_common_bss_34C90._012 = 0;
        break;
    case 4:
    case 10:
        changeScene(3, 6);
        lbl_3_common_bss_34C90._1D2++;
        break;
    case 5:
    case 11:
        if (lbl_8037169C._13 != 0) {
            g_Practice.loadingGuidedPractice = 0;
            lbl_3_common_bss_34C90._1D9 = 2;
            g_Practice._19F = 0;
            lbl_8036E548._307D = 0;
            if (lbl_3_common_bss_34C90._1D2 == 11) {
                g_Practice.practiceState = 0;
                g_Practice.practiceLevel++;
                g_Practice.tutorialState = 0;
                g_Practice.framesSincePracticeMenuDefaultTransition = 0;
            } else {
                g_Practice.practiceState = 0;
                g_Practice.transitioningIndicator = 1;
                g_Practice.tutorialState = 2;
                g_Practice.framesSincePracticeMenuDefaultTransition = 0;
            }
        }
        break;
    case 6:
        changeScene(3, 6);
        lbl_3_common_bss_34C90._1D2 = 7;
        break;
    case 7:
        if (lbl_8037169C._13 != 0) {
            g_Practice.loadingGuidedPractice = 0;
            lbl_3_common_bss_34C90._1D9 = 2;
            g_Practice._19F = 0;
            lbl_8036E548._307D = 0;
            lbl_8036E548._307E = 0;
            fn_3_B5D4C(0);
            g_Practice.returnToPracticeMenuState = 1;
            g_GameLogic.secondaryGameMode = 10;
            g_Practice.totalFrames = 0;
            g_Practice.framesInCurrTransitionState = 0;
            g_Practice.practiceState = 0;
            fn_80011A60();
            fn_3_8C07C();
        }
        break;
    case 12:
        switch (fn_3_5B380(g_Controls[lbl_3_common_bss_34C90._000].newButtonInput)) {
        case 1:
            if (g_Practice._1B1 != 0) {
                fn_8004CC18();
                fn_3_5B368();
            } else {
                changeScene(3, 6);
            }
            lbl_3_common_bss_34C90._1D2 = 13;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 2;
            break;
        }
        break;
    case 13:
        if (g_Practice._1B1 != 0) {
            if (fn_3_5B220(3) != 0) {
                changeScene(3, 6);
                g_Practice._1B1 = 0;
            }
        } else if (lbl_8037169C._13 != 0) {
            g_GameLogic.framesOfExitingToMenu = 1;
            lbl_3_common_bss_34C90._1D9 = 2;
            fn_8004CC18();
        }
        break;
    }
}

// .text:0x000B3448 size:0x1D8 mapped:0x806F24DC
// The target tests the inputs in r3 where this uses r4; it returns the sound's
// voice on some paths only, like the target's use of r3.
int fn_3_B3448(void) {
    int menu = 0;
    InputStruct* input = &g_Controls[g_Practice.homeAway];

    if (g_Practice.practiceLevel == 3) {
        menu = 1;
    }
    if (input->newButtonInput & 0x100) {
        if (g_Practice.currentMessageDoneTyping != 0) {
            switch (lbl_3_data_FAE8[menu][lbl_3_common_bss_34C90._1DA + 1]) {
            case 0:
                lbl_3_common_bss_34C90._1D2 = 10;
                break;
            case 1:
                lbl_3_common_bss_34C90._1D2 = 4;
                break;
            case 2:
                lbl_3_common_bss_34C90._1D2 = 6;
                break;
            case 3:
                fn_3_5B408();
                lbl_3_common_bss_34C90._1D2 = 12;
                break;
            default:
                break;
            }
            return sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        }
    } else if (input->_08 & 4) {
        lbl_3_common_bss_34C90._1DA++;
        if (lbl_3_common_bss_34C90._1DA >= lbl_3_data_FAE8[menu][0]) {
            lbl_3_common_bss_34C90._1DA = 0;
        }
        return sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    } else if (input->_08 & 8) {
        lbl_3_common_bss_34C90._1DA--;
        if (lbl_3_common_bss_34C90._1DA < 0) {
            lbl_3_common_bss_34C90._1DA = lbl_3_data_FAE8[menu][0] - 1;
        }
        return sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    }
}

// .text:0x000B32B8 size:0x190 mapped:0x806F234C
int fn_3_B32B8(void) {
    InputStruct* input = &g_Controls[g_Practice.homeAway];

    if (lbl_8036E548._2D46 != 0) {
        return 0;
    }
    if (lbl_8036E548._2D52 != 0) {
        return 0;
    }
    if (g_Practice._186 != 0 || g_Practice.guidedPracticeCompletionRelated != 0) {
        return 0;
    }
    if (g_GameLogic.FrameCountOfCurrentPitch < 30 || lbl_8037169C._10 != 0) {
        return 0;
    }
    if (g_Practice.pauseMenuLoading != 0) {
        lbl_80366158._28 = 1;
        if (++g_Practice.frames_sinceTimeCalled >= 60) {
            fn_3_B3288();
        }
        return 1;
    }
    if (g_Practice.practiceType_2 == 4 && g_Pitcher.pitchTotalTimeCounter > 0) {
        return 0;
    }
    if (input->newButtonInput & 0x1000) {
        lbl_80366158._28 = 1;
        fn_3_59918(14, 0);
        g_Practice.pauseMenuLoading = 1;
        g_Practice.frames_sinceTimeCalled = 0;
        return 1;
    }
    return 0;
}

// .text:0x000B3288 size:0x30 mapped:0x806F231C
void fn_3_B3288(void) {
    g_Practice.pauseMenuLoading = 0;
    g_Practice._19F = 1;
    g_Practice.frames_onPauseScreen = 0;
    lbl_3_common_bss_34C90._1D2 = 0;
    lbl_3_common_bss_34C90._1DA = 0;
}

// .text:0x000B2E20 size:0x468 mapped:0x806F1EB4
void fn_3_B2E20(void) {
    int i;

    lbl_80366158._28 = 1;
    if (g_Practice.frames_onPauseScreen < 0x7FFE) {
        g_Practice.frames_onPauseScreen++;
    } else {
        g_Practice.frames_onPauseScreen = 0x7FFF;
    }
    if (g_Practice.frames_onPauseScreen2 < 0x7FFE) {
        g_Practice.frames_onPauseScreen2++;
    } else {
        g_Practice.frames_onPauseScreen2 = 0x7FFF;
    }
    if (lbl_3_common_bss_34C90._00A < 0x7FFE) {
        lbl_3_common_bss_34C90._00A++;
    } else {
        lbl_3_common_bss_34C90._00A = 0x7FFF;
    }
    if (lbl_3_common_bss_34C90._00C < 0x7FFE) {
        lbl_3_common_bss_34C90._00C++;
    } else {
        lbl_3_common_bss_34C90._00C = 0x7FFF;
    }
    if (lbl_3_common_bss_34C90._012 < 0x7FFE) {
        lbl_3_common_bss_34C90._012++;
    } else {
        lbl_3_common_bss_34C90._012 = 0x7FFF;
    }
    switch (lbl_3_common_bss_34C90._1D2) {
    case 0:
        if (g_Practice.practiceType_2 == 4) {
            lbl_3_common_bss_34C90._1D0 = 6;
        } else if (g_Practice.practiceLevel == lbl_3_data_FACC[g_Practice.practiceType_2][0] - 1) {
            lbl_3_common_bss_34C90._1D0 = 5;
        } else {
            lbl_3_common_bss_34C90._1D0 = 4;
        }
        g_Practice.frames_onPauseScreen2 = 0;
        lbl_3_common_bss_34C90._1D2 = 1;
        break;
    case 1:
        if (g_Practice.frames_onPauseScreen2 > 30) {
            lbl_3_common_bss_34C90._1D2 = 2;
        }
        break;
    case 2:
        fn_3_B2AA0();
        break;
    case 3:
        fn_3_B28A8();
        break;
    case 4:
        lbl_3_common_bss_34C90._1D9 = 1;
        g_Practice.frames_onPauseScreen2 = 0;
        lbl_3_common_bss_34C90._1D2 = 5;
        break;
    case 5:
        if (g_Practice.frames_onPauseScreen2 > 30) {
            g_Practice._19F = 0;
        }
        break;
    case 6:
        changeScene(3, 6);
        if (lbl_8037169C._13 != 0) {
            lbl_3_common_bss_34C90._1D2 = 7;
        }
        break;
    case 7:
    case 9:
        if (g_GameLogic.secondaryGameMode == 15 || g_GameLogic.secondaryGameMode == 16) {
            for (i = 0; i < 4; i++) {
                fn_80011BE4(i + 9);
            }
        }
        lbl_3_common_bss_34C90._1D9 = 2;
        g_Practice._19F = 0;
        lbl_8036E548._307D = 0;
        lbl_8036E548._307E = 0;
        if (lbl_3_common_bss_34C90._1D2 == 9) {
            fn_3_B5D4C(6);
        } else {
            fn_3_B5D4C(0);
        }
        g_Practice.returnToPracticeMenuState = 1;
        g_GameLogic.secondaryGameMode = 10;
        g_Practice.totalFrames = 0;
        g_Practice.framesInCurrTransitionState = 0;
        g_Practice.practiceState = 0;
        fn_80011A60();
        fn_3_6AB30();
        fn_3_8C07C();
        break;
    case 8:
        changeScene(3, 6);
        if (lbl_8037169C._13 != 0) {
            lbl_3_common_bss_34C90._1D2 = 9;
        }
        break;
    case 10:
        changeScene(3, 6);
        if (lbl_8037169C._13 != 0) {
            lbl_3_common_bss_34C90._1D2 = 11;
        }
        break;
    case 11:
        lbl_3_common_bss_34C90._1D9 = 2;
        g_Practice._19F = 0;
        lbl_8036E548._307D = 0;
        g_Practice.practiceLevel++;
        g_Practice.practiceState = 0;
        g_Practice.tutorialState = 0;
        g_Practice.framesSincePracticeMenuDefaultTransition = 0;
        break;
    case 12:
        switch (fn_3_5B380(g_Controls[lbl_3_common_bss_34C90._000].newButtonInput)) {
        case 1:
            lbl_3_common_bss_34C90._1D2 = 13;
            if (g_Practice._1B1 != 0) {
                fn_8004CC18();
                fn_3_5B368();
            } else {
                changeScene(4, 6);
            }
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 2;
            break;
        }
        break;
    case 13:
        if (g_Practice._1B1 != 0) {
            if (fn_3_5B220(3) != 0) {
                changeScene(3, 6);
                g_Practice._1B1 = 0;
            }
        } else if (lbl_8037169C._13 != 0) {
            g_GameLogic.framesOfExitingToMenu = 1;
            lbl_3_common_bss_34C90._1D9 = 2;
            fn_8004CC18();
        }
        break;
    }
}

// .text:0x000B2AA0 size:0x380 mapped:0x806F1B34
void fn_3_B2AA0(void) {
    int count = 5;
    InputStruct* input = &g_Controls[g_Practice.homeAway];

    if (lbl_3_common_bss_34C90._1D0 == 6) {
        count = 5;
    } else if (lbl_3_common_bss_34C90._1D0 == 5) {
        count = 4;
    }
    if (input->newButtonInput & 0x1000) {
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        lbl_3_common_bss_34C90._1D2 = 4;
    } else if (input->newButtonInput & 0x100) {
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        if (lbl_3_common_bss_34C90._1D0 == 6) {
            switch (lbl_3_common_bss_34C90._1DA) {
            case 0:
                lbl_3_common_bss_34C90._1D2 = 4;
                break;
            case 1:
                lbl_3_common_bss_34C90._1D3 = 0;
                lbl_3_common_bss_34C90._1D2 = 3;
                break;
            case 2:
                lbl_3_common_bss_34C90._1D2 = 8;
                break;
            case 3:
                lbl_3_common_bss_34C90._1D2 = 6;
                break;
            case 4:
                fn_3_5B408();
                lbl_3_common_bss_34C90._012 = 0;
                lbl_3_common_bss_34C90._1D2 = 12;
                break;
            }
        } else if (lbl_3_common_bss_34C90._1D0 == 5) {
            switch (lbl_3_common_bss_34C90._1DA) {
            case 0:
                lbl_3_common_bss_34C90._1D2 = 4;
                break;
            case 1:
                lbl_3_common_bss_34C90._1D3 = 0;
                lbl_3_common_bss_34C90._1D2 = 3;
                break;
            case 2:
                lbl_3_common_bss_34C90._1D2 = 6;
                break;
            case 3:
                fn_3_5B408();
                lbl_3_common_bss_34C90._012 = 0;
                lbl_3_common_bss_34C90._1D2 = 12;
                break;
            }
        } else {
            switch (lbl_3_common_bss_34C90._1DA) {
            case 0:
                lbl_3_common_bss_34C90._1D2 = 4;
                break;
            case 1:
                lbl_3_common_bss_34C90._1D3 = 0;
                lbl_3_common_bss_34C90._1D2 = 3;
                break;
            case 2:
                lbl_3_common_bss_34C90._1D2 = 10;
                break;
            case 3:
                lbl_3_common_bss_34C90._1D2 = 6;
                break;
            case 4:
                fn_3_5B408();
                lbl_3_common_bss_34C90._012 = 0;
                lbl_3_common_bss_34C90._1D2 = 12;
                break;
            }
        }
    } else if (input->newButtonInput & 0x200) {
        if (lbl_3_common_bss_34C90._1DA != 0) {
            lbl_3_common_bss_34C90._1DA = 0;
        } else {
            lbl_3_common_bss_34C90._1D2 = 4;
        }
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
    } else if (input->_08 & 4) {
        lbl_3_common_bss_34C90._1DA++;
        if (lbl_3_common_bss_34C90._1DA >= count) {
            lbl_3_common_bss_34C90._1DA = 0;
        }
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    } else if (input->_08 & 8) {
        lbl_3_common_bss_34C90._1DA--;
        if (lbl_3_common_bss_34C90._1DA < 0) {
            lbl_3_common_bss_34C90._1DA = count - 1;
        }
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    }
}

// .text:0x000B28A8 size:0x1F8 mapped:0x806F193C
void fn_3_B28A8(void) {
    InputStruct* input = &g_Controls[g_Practice.homeAway];

    switch (lbl_3_common_bss_34C90._1D3) {
    case 0:
        lbl_3_common_bss_34C90._221 = 1;
        lbl_3_common_bss_34C90._222 = 3;
        lbl_3_common_bss_34C90._1D9 = 1;
        lbl_3_common_bss_34C90._1D3 = 1;
        break;
    case 1:
        if (fn_80035838(&lbl_3_data_10598[2], 19) != 0) {
            lbl_3_common_bss_34C90._1D3 = 2;
        }
        break;
    case 2:
        if (lbl_3_common_bss_34C90._1D9 == 3) {
            lbl_3_common_bss_34C90._1D3 = 3;
        }
        break;
    case 3:
        lbl_3_common_bss_34C90._1D3 = 4;
        break;
    case 4:
        if (lbl_3_common_bss_32724._C3 == 0) {
            lbl_3_common_bss_34C90._1D3 = 5;
        }
        break;
    case 5:
        if (lbl_3_common_bss_32724._C3 != 0) {
            break;
        }
        if (input->newButtonInput & 0x200) {
            lbl_3_common_bss_34C90._1D3 = 6;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        } else if ((input->_08 & 1) && lbl_3_common_bss_34C90._221 != 0) {
            lbl_3_common_bss_34C90._221--;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if ((input->_08 & 2) && lbl_3_common_bss_34C90._221 < lbl_3_common_bss_34C90._222 - 1) {
            lbl_3_common_bss_34C90._221++;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
        break;
    case 6:
        lbl_3_common_bss_34C90._1D3 = 7;
        break;
    case 7:
        if (lbl_3_common_bss_32724._C3 == 0) {
            fn_80035B50(19);
            lbl_3_common_bss_34C90._1D2 = 0;
        }
        break;
    }
}

// .text:0x000B27A4 size:0x104 mapped:0x806F1838
void fn_3_B27A4(void) {
    g_Practice.framesOnAllInstructions = 0;
    g_Practice._164 = 0;
    g_Practice.framesOnCurrInstruction = 0;
    g_Practice.laukituTextChannelIndex = -1;
    g_Practice.lakituTextIndex_stored = -1;
    g_Practice.diagramTextChannelIndex = -1;
    g_Practice.diagramTitleTextIndex_stored = -1;
    g_Practice.cpuCommandDuration = 0;
    g_Practice.instructionNumber = 0;
    g_Practice.currentMessageDoneTyping = 0;
    g_Practice.commandIndex = 0;
    g_Practice.allInstructionsComplete = 0;
    g_Practice.instructionComplete_readyToAdvance = 0;
    g_Practice.allowPlayToEndIndicator = 0;
    g_Practice._1C7 = 0;
    g_Practice.guidedPracticeCompletionRelated = 0;
    g_Practice.guidedPracticeCounter = 0;
    g_Practice.maybeControlFlag1 = 0;
    g_Practice.maybeControlFlag2 = 0;
    g_Practice.practice_runner_countInputForMashing = 0;
    g_Practice.practice_fielding_enableSprinting = 0;
    g_Practice._1C6 = 0;
    g_Practice.textRelatedIndicator = 0;
    g_Practice.maybePreviousInput = 0;
    g_Practice._17A = 0;
    g_Practice.cpu_inputDuration = 0;
    g_Practice._17E = 0;
    g_Practice._186 = 0;
    g_Practice.aIEnabled = 0;
    g_Practice.practiceBatterHandedness = 0;
    g_GameLogic._140[0] = g_GameLogic._140[1] = 0;
    g_GameLogic.batterHandedness[0] = g_GameLogic.batterHandedness[1] = 0;
    g_GameLogic.teamAIInd[0] = g_GameLogic.teamAIInd[1] = 0;
    g_GameLogic.autoFielding[0] = g_GameLogic.autoFielding[1] = 0;
    g_GameLogic.battingAIInd[0] = g_GameLogic.battingAIInd[1] = 0;
    fn_3_B274C();
}

// .text:0x000B274C size:0x58 mapped:0x806F17E0
void fn_3_B274C(void) {
    int i;
    for (i = 0; i < 2; i++) {
        g_Practice.inputs[i].controlStickAngle = -1;
        g_Practice.inputs[i].controlStickMagnitude = 0;
        g_Practice.inputs[i].buttonInput = 0;
        g_Practice.inputs[i].newButtonInput = 0;
        g_Practice.inputs[i]._08 = 0;
        g_Practice.inputs[i].right_left = 0;
        g_Practice.inputs[i].up_down = 0;
        g_Practice.inputs[i].rightTriggerDistance = 0;
        g_Practice.inputs[i].leftTriggerDistance = 0;
    }
}

// .text:0x000B2630 size:0x11C mapped:0x806F16C4
void fn_3_B2630(void) {
    InputStruct* input = &g_Controls[g_Practice.homeAway];

    if (g_Practice.framesOnAllInstructions < 0x7FFE) {
        g_Practice.framesOnAllInstructions++;
    } else {
        g_Practice.framesOnAllInstructions = 0x7FFF;
    }
    if (g_Practice.instructionComplete_readyToAdvance == 0 && g_Practice.allInstructionsComplete == 0) {
        if (g_Practice.framesOnCurrInstruction < 0x7FFE) {
            g_Practice.framesOnCurrInstruction++;
        } else {
            g_Practice.framesOnCurrInstruction = 0x7FFF;
        }
    }
    if (g_Practice.tutorialState == 1 && (input->newButtonInput & 0x1000)) {
        if (g_Practice.tutorialState != 2) {
            g_Practice.practiceState = 0;
            g_Practice.tutorialState = 2;
            g_Practice.framesSincePracticeMenuDefaultTransition = 0;
        }
    } else if (g_Practice.allInstructionsComplete != 0) {
        if ((input->newButtonInput & 0x100) && g_Practice.tutorialState != 2) {
            g_Practice.practiceState = 0;
            g_Practice.tutorialState = 2;
            g_Practice.framesSincePracticeMenuDefaultTransition = 0;
        }
    } else {
        fn_3_B1DD0();
    }
}

// .text:0x000B254C size:0xE4 mapped:0x806F15E0
int fn_3_B254C(void) {
    if (g_Practice.transitioningIndicator == 0) {
        lbl_80366158._28 = 1;
        switch (g_Practice.practiceState) {
        case 0:
            g_Practice.framesInCurrTransitionState = 0;
            g_Practice.practiceState++;
            break;
        case 1:
            if (g_Practice.framesInCurrTransitionState > 30) {
                changeScene(3, 6);
                g_Practice.practiceState++;
            }
            break;
        case 2:
            if (lbl_8037169C._13 != 0) {
                g_Practice.practiceState++;
            }
            break;
        case 3:
            goto load;
        }
    } else {
    load:
        minigamesSetSomePointers();
        fn_3_B3A4C();
        return 1;
    }
    return 0;
}

// .text:0x000B1DD0 size:0x77C mapped:0x806F0E64
// First draft (86.46%): the target keeps the stick-direction masks in r29-r31 and
// lays out the command switch differently; registers and blocks differ throughout.
void fn_3_B1DD0(void) {
    int i;
    s16 cmd;
    s16 team;
    InputStruct* input;
    InputStruct* ctrl = &g_Controls[g_Practice.homeAway];

    g_Practice.inputs[0].newButtonInput = 0;
    g_Practice.inputs[1].newButtonInput = 0;
    if (g_Practice.instructionComplete_readyToAdvance != 0) {
        if (g_Practice.currentMessageDoneTyping != 0 && (ctrl->newButtonInput & 0x100)) {
            g_Practice.instructionComplete_readyToAdvance = 0;
            g_Practice.framesOnCurrInstruction = 0;
            g_Practice.currentMessageDoneTyping = 0;
            g_Practice.instructionNumber++;
        }
        if (g_Practice.instructionComplete_readyToAdvance == 1) {
            lbl_80366158._28 = 1;
        }
        g_Practice.readyToMoveToNextInstruction = 1;
        return;
    }
    if (g_Practice.maybeInputResetCountdown != 0 && --g_Practice.maybeInputResetCountdown != 0) {
        g_Practice.readyToMoveToNextInstruction = 1;
        lbl_80366158._28 = 1;
        return;
    }
    fn_3_B274C();
    for (i = 0; i < 2; i++) {
        if (g_Practice.cpuInputDuration[i] != 0 && --g_Practice.cpuInputDuration[i] != 0) {
            input = &g_Practice.inputs[i];
            input->buttonInput = g_Practice.cpuInput[i];
            if ((input->buttonInput & 2) && (input->buttonInput & 8)) {
                input->controlStickAngle = 0x200;
            } else if ((input->buttonInput & 8) && (input->buttonInput & 1)) {
                input->controlStickAngle = 0x600;
            } else if ((input->buttonInput & 1) && (input->buttonInput & 4)) {
                input->controlStickAngle = 0xA00;
            } else if ((input->buttonInput & 4) && (input->buttonInput & 2)) {
                input->controlStickAngle = 0xE00;
            } else if (input->buttonInput & 2) {
                input->controlStickAngle = 0;
            } else if (input->buttonInput & 8) {
                input->controlStickAngle = 0x400;
            } else if (input->buttonInput & 1) {
                input->controlStickAngle = 0x800;
            } else if (input->buttonInput & 4) {
                input->controlStickAngle = 0xC00;
            }
            if (input->controlStickAngle >= 0) {
                input->controlStickMagnitude = 0x40;
            }
        }
    }
    if (g_Practice.cpuCommandDuration != 0 && --g_Practice.cpuCommandDuration != 0) {
        return;
    }
    while (TRUE) {
        cmd = g_Practice.commandList[g_Practice.commandIndex];
        switch (cmd & 0xFF00) {
        case 0x100:
            g_Practice.cpuCommandDuration = g_Practice.commandList[++g_Practice.commandIndex] & 0xFFF;
            g_Practice.commandIndex++;
            return;
        case 0x200:
            g_Practice.maybeInputResetCountdown = g_Practice.commandList[++g_Practice.commandIndex] & 0xFFF;
            g_Practice.commandIndex++;
            return;
        case 0x300:
            g_Practice.instructionComplete_readyToAdvance = 1;
            g_Practice.commandIndex++;
            return;
        case 0x400:
            g_Practice.instructionComplete_readyToAdvance = 2;
            g_Practice.commandIndex++;
            return;
        case 0x1100:
        case 0x1300:
            team = g_GameLogic.teamFielding;
            if ((cmd & 0xFF00) == 0x1100) {
                team = g_GameLogic.teamBatting;
            }
            g_Practice.inputs[team].newButtonInput |= g_Practice.commandList[++g_Practice.commandIndex] & 0xFFF;
            break;
        case 0x1200:
        case 0x1400:
            team = g_GameLogic.teamFielding;
            if ((cmd & 0xFF00) == 0x1200) {
                team = g_GameLogic.teamBatting;
            }
            input = &g_Practice.inputs[team];
            g_Practice.cpuInput[team] = g_Practice.commandList[++g_Practice.commandIndex];
            input->buttonInput |= g_Practice.cpuInput[team];
            input->newButtonInput |= g_Practice.cpuInput[team];
            g_Practice.commandIndex++;
            if ((input->buttonInput & 2) && (input->buttonInput & 8)) {
                input->controlStickAngle = 0x200;
            } else if ((input->buttonInput & 8) && (input->buttonInput & 1)) {
                input->controlStickAngle = 0x600;
            } else if ((input->buttonInput & 1) && (input->buttonInput & 4)) {
                input->controlStickAngle = 0xA00;
            } else if ((input->buttonInput & 4) && (input->buttonInput & 2)) {
                input->controlStickAngle = 0xE00;
            } else if (input->buttonInput & 2) {
                input->controlStickAngle = 0;
            } else if (input->buttonInput & 8) {
                input->controlStickAngle = 0x400;
            } else if (input->buttonInput & 1) {
                input->controlStickAngle = 0x800;
            } else if (input->buttonInput & 4) {
                input->controlStickAngle = 0xC00;
            }
            if (input->controlStickAngle >= 0) {
                input->controlStickMagnitude = 0x40;
            }
            g_Practice.cpuInputDuration[team] = g_Practice.commandList[g_Practice.commandIndex] & 0xFFF;
            break;
        case 0x1500:
            g_Practice.practice_runner_countInputForMashing = 1;
            break;
        case 0x1600:
            g_Practice.practice_runner_countInputForMashing = 0;
            break;
        case 0x1700:
            g_Practice.practice_fielding_enableSprinting = 1;
            break;
        case 0x1800:
            g_Practice.practice_fielding_enableSprinting = 0;
            break;
        case 0x2100:
            g_Practice.lakituTextIndex = g_Practice.commandList[++g_Practice.commandIndex] & 0xFFF;
            break;
        case 0x2200:
            g_Practice.diagramTitleTextIndex = g_Practice.commandList[++g_Practice.commandIndex] & 0xFFF;
            break;
        case 0x2300:
            g_Practice.diagramTitleTextIndex = 0;
            break;
        case 0x3100:
            g_Practice.allowPlayToEndIndicator = 1;
            break;
        case 0x3200:
            g_Practice.practice_hitHorizontalPower = g_Practice.commandList[++g_Practice.commandIndex];
            g_Practice.practice_hitVerticalAngle = g_Practice.commandList[++g_Practice.commandIndex];
            g_Practice.practice_hitHorizontalAngle = g_Practice.commandList[++g_Practice.commandIndex];
            break;
        case 0x3300:
            g_Practice._1C6 = cmd;
            g_Practice._1C6++;
            break;
        case 0x4100:
            g_Practice.maybeControlFlag1 = 0;
            g_Practice.maybeControlFlag2 = 0;
            break;
        case 0x4200:
            g_Practice.maybeControlFlag1 = cmd;
            break;
        case 0x4300:
            g_Practice.maybeControlFlag2 = cmd;
            break;
        case 0x4800:
            g_Practice.textRelatedIndicator = 0;
            break;
        case 0x4900:
            g_Practice.textRelatedIndicator = 1;
            break;
        case 0x5100:
            g_Camera._2819 = 1;
            g_Camera._2810 = (u8)cmd;
            break;
        case 0x5200:
            g_Camera._2819 = 2;
            break;
        case 0x7F00:
            g_Practice.allInstructionsComplete = 1;
            lbl_80366158._28 = 1;
            return;
        default:
            return;
        }
        g_Practice.commandIndex++;
    }
}

// .text:0x000B1DA4 size:0x2C mapped:0x806F0E38
void fn_3_B1DA4(int level, int arg1) {
    g_Practice.loadingGuidedPractice = 1;
    g_Practice._1D5 = 0;
    g_Practice.practiceLevel_2 = level;
    g_Practice._1D7 = arg1;
    g_Practice._1D8 = 0;
    g_Practice._188 = 0;
}

// .text:0x000B1CB0 size:0xF4 mapped:0x806F0D44
int fn_3_B1CB0(void) {
    InputStruct* input = &g_Controls[g_Practice._192];

    if (g_Practice.loadingGuidedPractice == 0) {
        return 0;
    }
    if (g_GameLogic.gameStatus != 1 && g_GameLogic.gameStatus != 2) {
        return 0;
    }
    if (g_Practice._188 < 0x7FFE) {
        g_Practice._188++;
    } else {
        g_Practice._188 = 0x7FFF;
    }
    if (g_Practice._188 > 90 && (input->newButtonInput & 0x1100)) {
        g_Practice._1D8++;
        if (g_Practice._1D8 >= 3 || lbl_3_data_104B8[g_Practice.practiceLevel_2][g_Practice._1D7][g_Practice._1D8] < 0) {
            g_Practice.loadingGuidedPractice = 0;
        }
    }
    return 1;
}
