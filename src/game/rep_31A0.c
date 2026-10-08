#include "game/rep_31A0.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/m_sound.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1C0.h"
#include "game/rep_1D58.h"
#include "game/rep_31F0.h"
#include "game/rep_34B0.h"
#include "game/rep_36D8.h"
#include "game/rep_3520.h"
#include "game/rep_60.h"
#include "game/rep_1838.h"
#include "game/rep_3880.h"
#include "game/rep_3CE0.h"
#include "game/rep_3310.h"
#include "game/rep_F80.h"
#include "game/rep_2940.h"
#include "game/rep_28A8.h"
#include "game/rep_1E08.h"
#include "game/rep_16B8.h"
#include "game/rep_E08.h"
#include "game/rep_D18.h"
#include "game/rep_3090.h"
#include "string.h"
#include "musyx/musyx.h"

typedef struct {
    /* 0x00 */ u32 _00[4];
} AramEntry31A0; // size: 0x10

// One player waiting in fn_3_10C81C's queue
typedef struct {
    /* 0x0 */ int player;
    /* 0x4 */ int wait;
} UnkQueue31A0; // size: 0x8

extern struct {
    /* 0x000 */ struct UnkRecord3448 _000[5];
    /* 0x028 */ struct UnkRecord3448 _028[6][5];
    /* 0x118 */ struct UnkRecord3448 _118[5];
    /* 0x140 */ struct UnkStats3448 _140[32];
    /* 0x400 */ s8 _400[1];
} lbl_803616CC;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u8 _10;
} lbl_3_data_228;

extern struct {
    /* 0x0000 */ u8 _0000[0x2D77];
    /* 0x2D77 */ u8 _2D77;
    /* 0x2D78 */ u8 _2D78[0x2D8E - 0x2D78];
    /* 0x2D8E */ u8 _2D8E;
    /* 0x2D8F */ u8 _2D8F[0x3078 - 0x2D8F];
    /* 0x3078 */ s16 _3078;
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B[0x307E - 0x307B];
    /* 0x307E */ u8 _307E;
} lbl_8036E548;

// A task from fn_800B0A5C_insertQueue
typedef struct {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
} UnkTask31A0;

extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
} lbl_8037169C;

extern struct {
    /* 0x00 */ u8 _00[0xB8];
    /* 0xB8 */ u8 _B8;
    /* 0xB9 */ u8 _B9;
    /* 0xBA */ u8 _BA;
    /* 0xBB */ u8 _BB;
    /* 0xBC */ u8 _BC[0xC4 - 0xBC];
    /* 0xC4 */ u8 _C4;
    /* 0xC5 */ u8 _C5[0xD8 - 0xC5];
    /* 0xD8 */ u8 _D8;
} lbl_3_common_bss_32724;

// Main-DOL table that symbols.txt lumps into lbl_8034E9A0
extern CharacterStats lbl_8034E9A0[];
extern u8 lbl_800E86F0[12];

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
    /* 0x1D4 */ u8 _1D4;
    /* 0x1D5 */ u8 _1D5[0x1D9 - 0x1D5];
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ s8 _1DA;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x00 */ u8 _00[0xAA];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB;
} g_Scores;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

extern struct {
    /* 0x00 */ u8 _00[0x27];
    /* 0x27 */ u8 _27;
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_80361B20[0x130];

extern struct {
    /* 0x00 */ u8 _00[0x74];
    /* 0x74 */ u8 _74[4];
    /* 0x78 */ u8 _78[0x7F - 0x78];
    /* 0x7F */ s8 _7F[4];
    /* 0x83 */ u8 _83[0x92 - 0x83];
    /* 0x92 */ u8 _92;
} lbl_803C6028;

extern struct {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3[3];
} lbl_800E8558[];
extern s16 lbl_80109410[8];

extern struct {
    /* 0x0 */ u8 _0[6];
    /* 0x6 */ u8 _6;
} lbl_803C6714;

extern struct {
    /* 0x0 */ u8 _0[3];
    /* 0x3 */ u8 _3;
} lbl_803C5F74;
extern s16 lbl_3_data_607C[16];
extern AramEntry31A0 lbl_3_data_20FDC;
extern u8 lbl_3_data_188E8[3][6];
extern u8 lbl_800E854C[12];
extern u8 lbl_3_data_609C[12][6];
extern s8 lbl_3_data_B060[8][3][5];
extern s8 lbl_3_data_6104[8];
extern u8 lbl_3_data_18918[8];
extern u8 lbl_3_data_188FC[3][5];
extern u8 lbl_3_data_18910[8];
extern u8 lbl_3_data_18920[7][5];
extern u8 lbl_3_data_18944[8];
extern u8 lbl_3_data_1894C[6][7];
extern u8 lbl_3_data_18978[8];

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void* ARAMTransfer(AramEntry31A0* entry, int arg1, int arg2, u32 aram);
extern void fn_8001CA40(int arg);
extern void fn_80011BE4(int arg);
extern void fn_80018B38(void);
extern void fn_80035B50(int arg);
extern void fn_3_909B0(void);
extern void fn_3_9081C(void);
extern void fn_3_9DC18(u8* list, int count, int arg2);
extern void fn_3_1160B8(void);
extern void fn_3_1160BC(void);
extern void fn_3_1471C4(void);
extern void fn_3_1471C0(void);
extern void fn_3_9E078(int* order, int count, int arg2);
extern void changeScene(u8, s16);
extern void fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void fn_8006C398(struct UnkStats3448* stats);
extern void fn_80062A74(void);
extern void fn_80062A94(void);
extern void fn_3_8B318(int arg);
extern int fn_3_90928(void);
extern void fn_800189E4(void);
extern int fn_80035838(AramEntry31A0* entry, int arg1);
extern int fn_3_6C938(int, int);
extern void fn_3_161078(void);
extern void fn_3_1658F0(void);
extern void possiblyTransitionBlackScreen(void);
extern void fn_8004CC18(void);
extern void fn_8004FDA0(int charID);
extern void fn_80050138(int arg0, int c0, int c1, int c2, int c3, int arg5);
extern void fn_800506E8(int port, int charID, int arg2);
extern int fn_80050760(int player, int arg1, int arg2, int arg3, int arg4);
extern s8 fn_8004FD64(int player);
extern int fn_8004FDE8(int player, int other);
extern void fn_800628D4(int charID);
extern void fn_80050FE8(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_8004CC2C(void);
extern void fn_8004CC4C(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_8004D0F0(void);
extern void fn_800189B8(void);
extern void fn_80018B74(void);
extern BOOL fn_80020388(void);
extern void fn_3_908E8(void);
extern BOOL fn_3_90860(void);
extern BOOL fn_3_90A18(void);
extern BOOL fn_3_90DD8(void);
extern BOOL fn_80016F7C(void);
extern void fn_8003A540(int arg);
extern void minigamesSetSomePointers(void);
extern void minigamesGXStuff(void);
extern void fn_80011B64(int port);
extern int fn_80016710(int charID, int port);
extern void fn_800203E0(int, int);
extern s16 fn_8006C13C(struct UnkStats3448* stats);
extern void fn_800246D4(int (*compare)(const void*, const void*), void* src, void* dst, int size, int count);

u8 lbl_3_data_21268[8] = { 1, 2, 4, 5, 3, 6, 7, 0 };
u8 lbl_3_data_21270[8] = { 1, 4, 1, 4, 0, 3, 1, 0 };
u8 lbl_3_data_21278[2] = { 30, 60 };
u8 lbl_3_data_2127C[8][5] = {
    { 0, 1, 2, 3, 0 },
    { 0, 1, 2, 2, 0 },
    { 0, 1, 2, 2, 0 },
    { 0, 1, 2, 2, 0 },
    { 0, 1, 2, 2, 0 },
    { 0, 1, 2, 2, 0 },
    { 0, 1, 2, 2, 0 },
    { 2, 2, 2, 2, 0 },
};
u8 lbl_3_data_212A4[17][6] = {
    { 0, 1, 4, 5, 2, 3 },
    { 13, 12, 17, 21, 24, 28 },
    { 6, 5, 7, 8, 38, 11 },
    { 0, 1, 2, 4, 9, 10 },
    { 0, 1, 2, 4, 9, 10 },
    { 41, 0, 5, 14, 10, 27 },
    { 20, 15, 3, 1, 48, 11 },
    { 7, 8, 13, 6, 18, 39 },
    { 7, 8, 13, 6, 18, 39 },
    { 17, 16, 8, 19, 28, 40 },
    { 6, 38, 21, 14, 7, 5 },
    { 0, 1, 2, 4, 9, 10 },
    { 0, 1, 2, 4, 9, 10 },
    { 40, 17, 16, 14, 3, 10 },
    { 12, 37, 27, 20, 33, 11 },
    { 41, 2, 38, 9, 19, 48 },
    { 41, 2, 38, 9, 19, 48 },
};
f32 lbl_3_data_2130C[28] = {
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
};
s16 lbl_3_data_2137C[2] = { 120, 60 };
f32 lbl_3_data_21380[3] = { 0.0f, 1.6f, 18.0f };
f32 lbl_3_data_2138C[4] = { 0.005f, 0.005f, 0.005f, 0.005f };
u8 lbl_3_data_2139C[8] = { 120, 140, 160, 170, 190, 0, 0, 0 };
// rep_31F0 reads rows of five weights; the last three bytes are not a whole row
u8 lbl_3_data_213A4[48] = {
    0, 100, 0,  0,  0,
    0, 50,  50, 0,  0,
    0, 40,  0,  60, 0,
    0, 30,  10, 20, 40,
    10, 20, 0,  20, 50,
    0, 0,   0,  65, 0,
    0, 10,  25, 30, 40,
    0, 15,  15, 20, 20,
    20, 20, 20, 0,  0,
    0, 50,  50,
};
u8 lbl_3_data_213D4[4][2] = {
    { 0, 0 },
    { 1, 2 },
    { 2, 3 },
    { 0, 0 },
};
u8 lbl_3_data_213DC[4] = { 0, 2, 4, 0 };
u8 lbl_3_data_213E0[4] = { 25, 55, 15, 30 };
u8 lbl_3_data_213E4[4][2] = {
    { 3, 3 },
    { 3, 3 },
    { 3, 3 },
    { 0, 0 },
};
s16 lbl_3_data_213EC[10] = {
    50, 60, 70, 80, 90, 100, 25, 200,
    15, 0,
};
s16 lbl_3_data_21400[4][2] = {
    { 10, 1000 },
    { 10, 1500 },
    { 10, 2000 },
    { 10, 0 },
};
s16 lbl_3_data_21410[5] = { 250, 260, 270, 280, 300 };
s16 lbl_3_data_2141C[7][2] = {
    { 0, 150 },
    { 270, 290 },
    { 280, 300 },
    { 290, 320 },
    { 310, 340 },
    { 330, 360 },
    { 350, 380 },
};
f32 lbl_3_data_21438[4] = { 0.001f, 170.0f, 1.5f, 130.0f };
s16 lbl_3_data_21448[10] = {
    90, 30, 160, 90, 90, 128, 64, 10,
    30, 90,
};
u16 lbl_3_data_2145C[2] = { 20, 70 };
u8 lbl_3_data_21460[8] = { 0, 1, 2, 4, 3, 5, 3, 0 };
u8 lbl_3_data_21468[4][6] = {
    { 60, 30, 10, 0, 0, 0 },
    { 30, 40, 10, 0, 10, 10 },
    { 20, 20, 20, 0, 20, 20 },
    { 15, 10, 10, 0, 25, 40 },
};
u8 lbl_3_data_21480[8] = { 20, 20, 20, 0, 20, 20, 0, 0 };
u8 lbl_3_data_21488[8][3] = {
    { 0, 100, 0 },
    { 0, 100, 0 },
    { 0, 100, 0 },
    { 0, 100, 0 },
    { 0, 100, 0 },
    { 0, 100, 0 },
    { 0, 100, 0 },
    { 0, 100, 0 },
};
s8 lbl_3_data_214A0[4][3][2] = {
    { { 0, 0 }, { -6, 4 }, { 0, 0 } },
    { { 0, 0 }, { -4, 3 }, { 0, 0 } },
    { { 0, 0 }, { -3, 2 }, { 0, 0 } },
    { { 0, 0 }, { -3, 1 }, { 0, 0 } },
};
s8 lbl_3_data_214B8[4][3] = {
    { 15, -10, 10 },
    { 10, -10, 10 },
    { 5, -10, 5 },
    { 5, -10, 5 },
};
s8 lbl_3_data_214C4[4][3] = {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
};
s8 lbl_3_data_214D0[4][3] = {
    { 22, -20, 20 },
    { 15, -20, 20 },
    { 10, -20, 10 },
    { 5, -20, 10 },
};
s8 lbl_3_data_214DC[4][3] = {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
};
s8 lbl_3_data_214E8[4][3] = {
    { 35, -30, 30 },
    { 30, -30, 30 },
    { 20, -30, 20 },
    { 15, -30, 20 },
};
s8 lbl_3_data_214F4[4][3] = {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
};
VecXZ lbl_3_data_21500[4] = {
    { 0.0f, 0.0f },
    { -5.0f, 25.0f },
    { 5.0f, 25.0f },
    { 10.0f, 25.0f },
};
VecXYZ lbl_3_data_21520[2][7] = {
    { { 0.0f, 0.0f, 10.2f }, { 0.0f, 0.0f, 8.5f }, { 0.0f, 0.0f, 6.8f }, { 0.0f, 0.0f, 5.1f }, { 0.0f, 0.0f, 3.4f }, { 0.0f, 0.0f, 1.7f }, { 0.0f, 0.0f, 0.0f } },
    { { 0.0f, 20.0f, 0.0f }, { 0.0f, 23.0f, 0.0f }, { 0.0f, 26.0f, 0.0f }, { 0.0f, 29.0f, 0.0f }, { 0.0f, 32.0f, 0.0f }, { 0.0f, 35.0f, 0.0f }, { 0.0f, 38.0f, 0.0f } },
};
VecXYZ lbl_3_data_215C8[2] = {
    { 0.0f, -0.5f, 0.0f },
    { 0.0f, 0.0f, 0.2f },
};
VecXYZ lbl_3_data_215E0[7] = {
    { 0.0f, 1.5f, 10.2f },
    { 0.0f, 1.5f, 8.5f },
    { 0.0f, 1.5f, 6.8f },
    { 0.0f, 1.5f, 5.1f },
    { 0.0f, 1.5f, 3.4f },
    { 0.0f, 1.5f, 1.7f },
    { 0.0f, 1.5f, 0.0f },
};
f32 lbl_3_data_21634[5] = { 0.2f, 0.1f, 0.0044f, 0.5f, 0.3f };
u32 lbl_3_data_21648[3] = { 1, 2, 5 };
s16 lbl_3_data_21654[12] = {
    30, 123, 150, 10, 17, 22, 17, 5,
    10, 15, 100, 50,
};
u8 lbl_3_data_2166C[5] = { 3, 3, 3, 3, 3 };
u8 lbl_3_data_21671 = 3;
s16 lbl_3_data_21672 = 1;
f32 lbl_3_data_21674[2] = { 0.1f, 0.1f };
s16 lbl_3_data_2167C[6] = { 90, 60, 90, 30, 60, 0 };
f32 lbl_3_data_21688[3] = { 0.1f, 0.3f, 1.0f };
s8 lbl_3_data_21694[4][7] = {
    { 90, 95, 100, 100, 100, 100, 80 },
    { 75, 80, 85, 85, 85, 90, 65 },
    { 55, 60, 65, 65, 65, 70, 40 },
    { 55, 60, 65, 65, 65, 70, 40 },
};
s8 lbl_3_data_216B0[4][2] = {
    { -40, 40 },
    { -30, 30 },
    { -20, 20 },
    { -15, 15 },
};
s8 lbl_3_data_216B8[4] = { 80, 60, 40, 30 };
VecXYZ lbl_3_data_216BC[15] = {
    { -8.4f, 0.0f, 25.0f },
    { -8.4f, 4.5f, 25.0f },
    { -8.4f, 9.0f, 25.0f },
    { -4.2f, 0.0f, 25.0f },
    { -4.2f, 4.5f, 25.0f },
    { -4.2f, 9.0f, 25.0f },
    { 0.0f, 0.0f, 25.0f },
    { 0.0f, 4.5f, 25.0f },
    { 0.0f, 9.0f, 25.0f },
    { 4.2f, 0.0f, 25.0f },
    { 4.2f, 4.5f, 25.0f },
    { 4.2f, 9.0f, 25.0f },
    { 8.4f, 0.0f, 25.0f },
    { 8.4f, 4.5f, 25.0f },
    { 8.4f, 9.0f, 25.0f },
};
f32 lbl_3_data_21770[6] = { 20.0f, -1.0f, 2.1f, 4.5f, 0.2f, 0.1f };
s16 lbl_3_data_21788[4] = { 3, 5, 10, 0 };
s16 lbl_3_data_21790[4] = { 1000, 1500, 2000, 0 };
u8 lbl_3_data_21798[12] = {
    15, 15, 15, 15, 5, 3, 3, 0,
    63, 0, 0, 0,
};
s16 lbl_3_data_217A4[12] = {
    20, 30, 80, 180, 45, 4, 20, 30,
    120, 130, 90, 0,
};
s16 lbl_3_data_217BC[4] = { 256, -3, -1024, 0 };
s16 lbl_3_data_217C4[2] = { 257, 257 };
u8 lbl_3_data_217C8[4] = { 15, 20, 30, 50 };
f32 lbl_3_data_217CC = 11723.279f;
s16 lbl_3_data_217D0[2] = { 770, 513 };
u8 lbl_3_data_217D4[4] = { 30, 25, 15, 15 };
VecXZ lbl_3_data_217D8[4] = {
    { 1.5f, 0.0f },
    { 0.5f, 0.0f },
    { -0.5f, 0.0f },
    { -1.5f, 0.0f },
};
f32 lbl_3_data_217F8[3] = { 0.0f, 0.0f, 18.5f };
s16 lbl_3_data_21804[5][9] = {
    { 50, 90, 110, 150, 150, 150, 150, 150, -1 },
    { 70, 110, 120, 140, 140, 140, 140, 140, -1 },
    { 100, 100, 100, 140, 140, 140, 140, 140, -1 },
    { 100, 100, 100, 140, 140, 140, 140, 140, -1 },
    { 100, 100, 100, 140, 140, 140, 140, 140, -1 },
};
u8 lbl_3_data_21860[5][4] = {
    { 0, 1, 2, 3 },
    { 0, 1, 2, 3 },
    { 0, 1, 2, 3 },
    { 0, 1, 2, 3 },
    { 0, 1, 2, 3 },
};
u8 lbl_3_data_21874[8] = { 60, 60, 60, 90, 60, 0, 0, 0 };
u8 lbl_3_data_2187C[4][2] = {
    { 95, 5 },
    { 90, 10 },
    { 80, 20 },
    { 0, 0 },
};
u8 lbl_3_data_21884[4][2] = {
    { 1, 1 },
    { 5, 1 },
    { 1, 10 },
    { 0, 0 },
};
f32 lbl_3_data_2188C[7] = { 0.1f, 0.3f, 0.1f, 0.3f, -0.01f, 0.7f, 0.5f };
s16 lbl_3_data_218A8 = 120;
u8 lbl_3_data_218AC[5][3] = {
    { 180, 160, 150 },
    { 160, 140, 140 },
    { 130, 110, 100 },
    { 130, 120, 110 },
    { 150, 130, 110 },
};
f32 lbl_3_data_218BC[18] = {
    4.0f, 0.3f, 0.07f, 0.3f,
    0.2f, 0.2f, 0.04f, 0.5f,
    0.05f, 0.05f, 0.1f, 0.1f,
    15.0f, 30.0f, 0.1f, 0.2f,
    0.04f, 1.8f,
};
s16 lbl_3_data_21904[12] = {
    90, 120, 60, 90, 180, 10, 20, 30,
    50, 120, 10, 0,
};
f32 lbl_3_data_2191C[2] = { 0.85f, 2.0f };
s16 lbl_3_data_21924[4] = { 545, 300, 180, 0 };
s8 lbl_3_data_2192C[4][2] = {
    { 30, 40 },
    { 10, 20 },
    { 5, 10 },
    { 5, 10 },
};
f32 lbl_3_data_21934[4] = { 0.7f, 0.6f, 0.5f, 0.4f };
s8 lbl_3_data_21944[4][2] = {
    { 30, 40 },
    { 20, 30 },
    { 15, 20 },
    { 10, 15 },
};
s16 lbl_3_data_2194C[4][2] = {
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};
s16 lbl_3_data_2195C[4][2] = {
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};
s8 lbl_3_data_2196C[4][2] = {
    { 70, 80 },
    { 50, 60 },
    { 20, 30 },
    { 10, 20 },
};
s8 lbl_3_data_21974[4][2] = {
    { 80, 90 },
    { 60, 70 },
    { 30, 40 },
    { 20, 30 },
};
s8 lbl_3_data_2197C[4] = { 10, 20, 30, 30 };
s8 lbl_3_data_21980[4] = { 4, 5, 6, 7 };
u8 lbl_3_data_21984[8] = { 60, 60, 60, 90, 60, 0, 0, 0 };
f32 lbl_3_data_2198C[8] = { 0.0f, 10.0f, -10.0f, 20.0f, 10.0f, 20.0f, 0.0f, 30.0f };
f32 lbl_3_data_219AC[3] = { 0.0f, 4.0f, 20.0f };
f32 lbl_3_data_219B8[19] = {
    0.28f, 0.3f, 0.05f, 0.18f,
    0.03f, 0.25f, 0.55f, 0.5f,
    0.5f, 0.05f, 0.15f, -0.01f,
    0.5f, 0.5f, 0.45f, 0.3f,
    0.05f, 0.08f, 0.25f,
};
s16 lbl_3_data_21A04[8] = { 15, 30, 1, 420, 128, 1, 10, 10 };
f32 lbl_3_data_21A14[7] = { 14.0f, 15.0f, 10.0f, 13.0f, 1.4f, 1.5f, 1.05f };
s16 lbl_3_data_21A30[6] = { 480, 420, 600, 90, 100, 10 };
s16 lbl_3_data_21A3C[4] = { 500, 505, -1, -1 };
s16 lbl_3_data_21A44 = 2;
f32 lbl_3_data_21A48[3] = { 0.0f, 0.5f, 20.0f };
f32 lbl_3_data_21A54[3] = { 2.0f, 13.0f, 0.4f };
s16 lbl_3_data_21A60[2] = { 60, 10 };
f32 lbl_3_data_21A64[9] = {
    30.0f, 1.5f, 0.4f, 0.7f,
    50.0f, 0.5f, 60.0f, 120.0f,
    300.0f,
};
s16 lbl_3_data_21A88[4] = { 2, 3, 4, 4 };
s16 lbl_3_data_21A90[32] = {
    3, 5, 3, 5, 2, 5, 2, 5,
    3, 5, 2, 5, 2, 4, 2, 4,
    3, 5, 2, 4, 1, 3, 1, 3,
    3, 5, 2, 4, 1, 3, 1, 3,
};
s16 lbl_3_data_21AD0[16] = {
    4, 4, 3, 3, 4, 3, 2, 2,
    4, 3, 2, 1, 4, 3, 2, 1,
};
s16 lbl_3_data_21AF0 = 20;
f32 lbl_3_data_21AF4 = 0.2f;
f32 lbl_3_data_21AF8[6] = { 0.3f, 0.15f, -0.01f, 0.85f, 1.5f, 0.5f };
s16 lbl_3_data_21B10[3] = { 60, 300, 300 };
u8 lbl_3_data_21B16 = 80;
f32 lbl_3_data_21B18[2] = { 0.1f, 0.95f };
s16 lbl_3_data_21B20[4] = { 90, 120, 180, 10 };
f32 lbl_3_data_21B28[4] = { 1.0f, 1.2f, 1.3f, 1.3f };
f32 lbl_3_data_21B38[4] = { 3.0f, 4.0f, 5.0f, 6.0f };
f32 lbl_3_data_21B48[4] = { 2.0f, 3.0f, 5.0f, 6.0f };
f32 lbl_3_data_21B58[4] = { 2.0f, 3.0f, 4.0f, 5.0f };
f32 lbl_3_data_21B68[4] = { 3.0f, 4.0f, 6.0f, 7.0f };
f32 lbl_3_data_21B78[4] = { 3.0f, 4.0f, 6.0f, 7.0f };
u8 lbl_3_data_21B88[4] = { 30, 20, 10, 5 };
s16 lbl_3_data_21B8C[4] = { 15, 10, 9, 8 };
f32 lbl_3_data_21B94[12] = {
    -7.5f, 0.0f, 0.0f, -2.5f,
    0.0f, 0.0f, 2.5f, 0.0f,
    0.0f, 7.5f, 0.0f, 0.0f,
};
f32 lbl_3_data_21BC4[86] = {
    14.0f, 0.0f, 18.0f, 14.0f,
    6.0f, 18.0f, 10.0f, 5.0f,
    15.0f, 14.0f, 7.0f, 18.0f,
    0.0f, 0.0f, 30.0f, 0.0f,
    6.0f, 30.0f, 0.0f, 5.0f,
    25.0f, 0.0f, 7.0f, 30.0f,
    -14.0f, 0.0f, 18.0f, -14.0f,
    6.0f, 18.0f, -10.0f, 5.0f,
    15.0f, -14.0f, 7.0f, 18.0f,
    14.0f, 0.0f, 18.0f, 14.0f,
    6.5f, 18.0f, 13.5f, 7.5f,
    17.5f, 14.0f, 10.0f, 18.0f,
    0.0f, 0.0f, 30.0f, 0.0f,
    6.5f, 30.0f, 0.0f, 7.5f,
    25.0f, 0.0f, 10.0f, 30.0f,
    -14.0f, 0.0f, 18.0f, -14.0f,
    6.5f, 18.0f, -13.5f, 7.5f,
    17.5f, -14.0f, 10.0f, 18.0f,
    0.0f, 0.0f, -10.0f, 0.0f,
    0.0f, -10.0f, 0.0f, 0.0f,
    -10.0f, 0.0f, 0.0f, -10.0f,
    1.5f, 1.75f,
};
f32 lbl_3_data_21D1C[4] = { 0.35f, 1.0f, 0.35f, 1.0f };
f32 lbl_3_data_21D2C[2] = { 0.0f, 1.0f };
f32 lbl_3_data_21D34[36] = {
    -7.5f, 1.0f, -2.0f, -7.5f,
    0.5f, -4.0f, -7.5f, 0.0f,
    -6.0f, -2.5f, 1.0f, -2.0f,
    -2.5f, 0.5f, -4.0f, -2.5f,
    0.0f, -6.0f, 2.5f, 1.0f,
    -2.0f, 2.5f, 0.5f, -4.0f,
    2.5f, 0.0f, -6.0f, 7.5f,
    1.0f, -2.0f, 7.5f, 0.5f,
    -4.0f, 7.5f, 0.0f, -6.0f,
};
s16 lbl_3_data_21DC4 = 30;
s16 lbl_3_data_21DC6 = 45;
s16 lbl_3_data_21DC8[30] = {
    20, 30, 20, 50, 60, 50, 20, 30,
    20, 50, 60, 50, 20, 30, 20, 50,
    60, 50, 40, 60, 40, 70, 90, 70,
    20, 30, 20, 50, 60, 50,
};
s16 lbl_3_data_21E04 = 180;
s16 lbl_3_data_21E06 = 240;
u8 lbl_3_data_21E08[8] = { 60, 60, 60, 90, 60, 0, 0, 0 };
u8 lbl_3_data_21E10[8] = { 5, 5, 5, 5, 30, 40, 0, 0 };
s16 lbl_3_data_21E18[2] = { 257, 514 };
u8 lbl_3_data_21E1C[2] = { 45, 30 };
u8 lbl_3_data_21E20[3] = { 70, 20, 10 };
f32 lbl_3_data_21E24[17] = {
    0.5f, 2.0f, 0.25f, 1.0f,
    0.75f, 1.0f, 0.75f, 1.0f,
    0.3f, 0.3f, 0.2f, -0.01f,
    0.99f, 0.75f, 1.0f, 3.0f,
    0.01f,
};
s16 lbl_3_data_21E68[26] = {
    90, 10, 30, 15, 5, 30, 30, 30,
    40, 15, 180, 30, 115, 15, 30, 60,
    10, 90, 30, 0, 150, 50, 80, 60,
    3, 0,
};
u8 lbl_3_data_21E9C[16] = {
    0, 10, 20, 70, 15, 15, 30, 40,
    40, 20, 20, 20, 50, 20, 20, 20,
};
s16 lbl_3_data_21EAC[8] = { 30, 60, 20, 35, 8, 15, 8, 15 };
f32 lbl_3_data_21EBC = 10757.015f;
u8 lbl_3_data_21EC0[4] = { 30, 50, 70, 85 };
u8 lbl_3_data_21EC4[4] = { 10, 6, 3, 0 };
AramEntry31A0 lbl_3_data_21EC8[62] = {
    { 1035, 0x4013764C, 0x1A635000, 0x0007DB48 },
    { 1035, 0x4003E3DC, 0x1A6B3000, 0x00021420 },
    { 1035, 0x4002EC10, 0x1A6D4800, 0x00013108 },
    { 1035, 0x400E72C0, 0x1A6E8000, 0x00060768 },
    { 1035, 0x40049404, 0x1A748800, 0x00020E34 },
    { 1035, 0x40076AE0, 0x18ED7000, 0x00036BC8 },
    { 1035, 0x4010FD70, 0x1A769800, 0x0005E284 },
    { 1035, 0x400DB738, 0x1A7C8000, 0x00049AB4 },
    { 1035, 0x400E9864, 0x1A812000, 0x00059DC0 },
    { 1035, 0x400B7718, 0x1A86C000, 0x00050288 },
    { 1035, 0x400D87FC, 0x1A8BC800, 0x00047BC4 },
    { 1035, 0x400D643C, 0x1A904800, 0x0004E3AC },
    { 1035, 0x400D5C7C, 0x1A953000, 0x00048D9C },
    { 1035, 0x400B767C, 0x1A99C000, 0x00047518 },
    { 1035, 0x400441F8, 0x1A9E3800, 0x0001AA84 },
    { 1035, 0x40106568, 0x1A9FE800, 0x00068C10 },
    { 1035, 0x4010E5A0, 0x0E97A800, 0x0009BCAC },
    { 1035, 0x40016980, 0x0EA16800, 54980 },
    { 1035, 0x40016980, 0x0EA24000, 51524 },
    { 1035, 0x40016980, 0x0EA31000, 59136 },
    { 1035, 0x40016980, 0x0EA3F800, 54860 },
    { 1035, 0x40016980, 0x0EA4D000, 51456 },
    { 1035, 0x40016980, 0x0EA5A000, 53244 },
    { 1035, 0x40016980, 0x0EA67000, 55072 },
    { 1035, 0x40016980, 0x0EA74800, 54988 },
    { 1035, 0x40016980, 0x0EA82000, 53788 },
    { 1035, 0x40016980, 0x0EA8F800, 53436 },
    { 1035, 0x40016980, 0x0EA9D000, 46404 },
    { 1035, 0x40016980, 0x0EAA8800, 50424 },
    { 1035, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 },
    { 1035, 0x4037CF5C, 0x18B3A800, 0x00208AF0 },
    { 1035, 0x4000A820, 0x18ED3800, 14168 },
    { 1035, 0x4011EC24, 0x18F0E000, 0x000D8818 },
    { 1035, 0x400193E8, 0x191B8800, 35288 },
    { 1035, 0x4006C850, 0x06C96000, 0x0002C884 },
    { 1035, 0x4005B178, 0x06CC3000, 0x0003555C },
    { 1035, 0x401EB174, 0x18D43800, 0x000FB220 },
    { 1035, 0x4001ED60, 0x1AA67800, 53232 },
    { 1035, 0x4000BF30, 0x1AA74800, 9952 },
    { 1035, 0x40003498, 0x1AA77000, 3624 },
    { 1035, 0x4000BDE0, 0x1AA78000, 9460 },
    { 1035, 0x40006088, 0x1AA7A800, 4752 },
    { 1035, 0x400049F0, 0x1AA7C000, 6388 },
    { 1035, 0x40005ECC, 0x1AA7E000, 7480 },
    { 1035, 0x40002670, 0x1AA80000, 3048 },
    { 0, 0x00028240, 0x1AA81000, 0x00028240 },
    { 0, 0x00028240, 0x1AAA9800, 0x00028240 },
    { 0, 0x00028240, 0x1AAD2000, 0x00028240 },
    { 0, 0x00028240, 0x1AAFA800, 0x00028240 },
    { 0, 0x00028240, 0x1AB23000, 0x00028240 },
    { 0, 0x00028240, 0x1AB4B800, 0x00028240 },
    { 0, 0x00028240, 0x1AB74000, 0x00028240 },
    { 0, 0x00028240, 0x1AB9C800, 0x00028240 },
    { 0, 0x00028240, 0x1ABC5000, 0x00028240 },
    { 0, 0x00028240, 0x1ABED800, 0x00028240 },
    { 0, 0x00028240, 0x1AC16000, 0x00028240 },
    { 0, 0x00028240, 0x1AC3E800, 0x00028240 },
    { 0, 0x00028240, 0x1AC67000, 0x00028240 },
    { 0, 0x00028240, 0x1AC8F800, 0x00028240 },
    { 0, 0x00028240, 0x1ACB8000, 0x00028240 },
    { 0, 0x00028240, 0x1ACE0800, 0x00028240 },
    { 0, 0x00028240, 0x1AD09000, 0x00028240 },
};

// .text:0x001104D4 size:0x160 mapped:0x8074F568
void fn_3_1104D4(void) {
    MiniGameStruct* mg = &g_Minigame;
    s8 port;
    s8 i;

    i = 0;
    do {
        g_Minigame._1DBC[i] = 0;
    } while (++i < 4);
    i = 0;
    do {
        port = g_Minigame.minigameControlStruct.characterIndex[i];
        if (port >= 0 && port < 4 && i == g_Minigame.rosterID && g_Minigame.minigameControlStruct.battingHandedness[i] != 0) {
            g_Minigame._1DBC[port] = 1;
            memset(&g_Minigame._1D7C[port], 0, sizeof(InputStruct));
            switch (g_Pitcher.pitcherActionState) {
            case 2:
                if (mg->_1DD0_u8 == 0) {
                    fn_3_110634();
                    mg->_1DD0_u8 = 1;
                }
                if (g_Pitcher.windupCountdownUntilBallReleased <= mg->_1DCC) {
                    g_Minigame._1D7C[port].buttonInput |= 0x100;
                }
                break;
            case 3:
                if (g_Ball.pitchHangtimeCounter < g_Pitcher.frameWhenUnhittable - mg->_1DCE_s16) {
                    g_Minigame._1D7C[port].buttonInput |= 0x100;
                }
                break;
            }
        }
    } while (++i < 4);
}

// .text:0x001104A8 size:0x2C mapped:0x8074F53C
void fn_3_1104A8(void) {
    s8 i = 0;

    do {
        g_Minigame._1DBC[i] = 0;
    } while (++i < 4);
}

// .text:0x0010FDC8 size:0x6E0 mapped:0x8074EE5C
void fn_3_10FDC8(void) {
    if (g_Minigame.pauseInd != 0) {
        fn_3_1084B4();
        return;
    }
    g_GameLogic.hudElementLoadingInd = 0;
    g_GameLogic.hudLoadingRelated = 0;
    if (g_Ball.totalFramesAtPlay < 0x7FFE) {
        g_Ball.totalFramesAtPlay++;
    } else {
        g_Ball.totalFramesAtPlay = 0x7FFF;
    }
    switch (g_GameLogic.gameStatus) {
    case 27:
        fn_3_10FB74();
        break;
    case 28:
        fn_3_10F1D4();
        break;
    case 29:
        fn_3_10F3D8();
        break;
    case 30:
        fn_3_10E60C();
        break;
    case 33:
        fn_3_10B8D0();
        break;
    case 5:
        fn_3_10AEF0();
        break;
    case 35:
        fn_3_10AE18();
        break;
    case 14:
        fn_3_10A0A0();
        break;
    case 36:
        fn_3_109254();
        break;
    case 34:
        fn_3_108C54();
        break;
    case 38:
        fn_3_10722C();
        break;
    case 40:
        fn_3_107784();
        break;
    case 41:
        fn_3_10768C();
        break;
    case 39:
        fn_3_1070A4();
        break;
    case 37:
        fn_3_10F91C();
        break;
    default:
        if (g_Minigame.GameMode_MiniGame == 1) {
            fn_3_112BD8();
        } else if (g_Minigame.GameMode_MiniGame == 2) {
            fn_3_1160BC();
        } else if (g_Minigame.GameMode_MiniGame == 3) {
            fn_3_1324E8();
        } else if (g_Minigame.GameMode_MiniGame == 4) {
            fn_3_141A30();
        } else if (g_Minigame.GameMode_MiniGame == 5) {
            fn_3_1471C4();
        } else if (g_Minigame.GameMode_MiniGame == 6) {
            fn_3_13C468();
        }
        if (g_Minigame._17C4 == 600) {
            fn_3_90064(0x2FD);
        }
        break;
    }
}

// .text:0x0010FBE4 size:0x1E4 mapped:0x8074EC78
void fn_3_10FBE4(void) {
    int i;

    g_GameLogic.secondaryGameMode = 2;
    fn_800B0A5C_insertQueue(possiblyTransitionBlackScreen, 2);
    fn_800B0A5C_insertQueue(fn_3_5BAC, 4);
    g_Scores._AA = 5;
    g_Scores._AB = 5;
    g_Minigame._19DF = 28;
    g_Minigame._19E1 = 0;
    g_Minigame._19E2 = 0;
    g_Minigame._19E3 = 0;
    g_Minigame._19E6 = 1;
    g_Minigame._19E7 = 1;
    g_Minigame.GameMode_MiniGame = 1;
    g_Minigame.soloMinigameDifficulty = 0;
    g_Minigame._1A2C = -1;
    g_Minigame._1A0C = -1;
    g_Minigame._19A7 = 4;
    g_Minigame.pauseInd = 0;
    g_Minigame._1A3C = 0;
    g_Minigame._1A3F = 0;
    g_Minigame._190A = 0;
    g_Minigame._1D6D = -1;
    g_Minigame._1A40 = 1;
    g_Minigame.challenge_minigame_haven_tWonYetIndicator = 1;
    g_Minigame._19A9 = 0;
    g_Minigame._1A3D = 0;
    g_Minigame._19E0 = 0;
    g_Minigame._1A38 = 0;
    g_Minigame._1A39 = 0;
    g_Minigame._1A46[0] = 0;
    g_Minigame.battingHandedness[5] = 0;
    for (i = 0; i < 4; i++) {
        g_Minigame._19DA[i] = -1;
        g_Minigame._19E8[i]._0 = -1;
        g_Minigame._19E8[i]._2 = -1;
        g_Minigame._19E8[i]._3 = -1;
        g_Minigame._19E8[i]._7 = 0;
        g_Minigame._19E8[i]._8 = 0;
        g_Minigame._1A0F[i] = -1;
        g_Minigame._19D2[i] = 20;
        g_Minigame._1A13[i] = 0;
        g_Minigame.minigameControlStruct.aIStrength[i] = 0;
        g_Minigame.minigameControlStruct._8[i] = 0;
    }
    g_Minigame.battingHandedness[4] = 0;
    lbl_3_common_bss_32724._B9 = 0;
    if (g_d_GameSettings.exhibitionMatchInd == 0) {
        g_Minigame._190A = 1;
        g_Minigame._19DA[g_d_GameSettings._35] = lbl_3_common_bss_37400._40 = g_d_GameSettings._35;
        g_Minigame.GameMode_MiniGame = g_d_GameSettings._33;
        fn_3_1658F0();
        g_Minigame._19DF = 30;
        fn_3_5A6D4(0x1B);
    } else {
        fn_3_5A6D4(0x1B);
    }
}

// .text:0x0010FB74 size:0x70 mapped:0x8074EC08
void fn_3_10FB74(void) {
    switch (g_GameLogic._125) {
    case 0:
        lbl_3_common_bss_32724._D8 = 0;
        lbl_3_common_bss_34C58._2C = 0;
        g_GameLogic._125++;
        break;
    }
    lbl_8036E548._307A = 0;
    fn_3_5A6D4(0x1D);
}

// .text:0x0010F91C size:0x258 mapped:0x8074E9B0
void fn_3_10F91C(void) {
    switch (g_GameLogic._125) {
    case 0:
        fn_3_10F684();
        lbl_3_common_bss_32724._D8 = 0;
        g_GameLogic._125++;
        break;
    }
    fn_3_10C58C();
    fn_3_5A6D4(0x21);
}

// .text:0x0010F684 size:0x298 mapped:0x8074E718
// 98.64%: the callee-saved registers r24-r30 hold the same values in another order
void fn_3_10F684(void) {
    int pool[6];
    int slot;
    int pick;
    int i;
    int count;
    int k;

    count = 0;
    g_Minigame.GameMode_MiniGame = g_d_GameSettings._33;
    g_Minigame._19DA[g_d_GameSettings._35] = 0;
    for (i = 0; i < 4; i++) {
        if (g_d_GameSettings._35 == i) {
            g_Minigame._19E8[i]._0 = g_d_GameSettings._36;
            g_Minigame._19E8[i]._1 = 1;
        } else {
            g_Minigame._19DA[i] = 1;
            count++;
            g_Minigame.minigameControlStruct.aIStrength[i] = lbl_3_data_18978[g_d_GameSettings.challengeDifficulty];
            if (count >= lbl_3_data_18944[g_Minigame.GameMode_MiniGame]) {
                break;
            }
        }
    }
    g_Minigame.miniGameNumberOfParticipants = lbl_3_data_18944[g_Minigame.GameMode_MiniGame] + 1;
    g_Minigame._1907 = 1;
    g_Minigame.multiPlayerInd = 1;
    g_Minigame.soloMinigameDifficulty = 0;
    for (k = 0; k < 6; k++) {
        pool[k] = lbl_3_data_1894C[g_Minigame.GameMode_MiniGame][k + 1];
    }
    slot = 0;
    for (i = 0; i < lbl_3_data_18944[g_Minigame.GameMode_MiniGame]; i++) {
        while (TRUE) {
            if (g_Minigame._19DA[slot] == 1) {
                break;
            }
            slot++;
        }
        pick = random_fn_3_9EE24(lbl_3_data_1894C[g_Minigame.GameMode_MiniGame][0] - i);
        for (k = 0; k < 6; k++) {
            if (pool[k] != 0xFF) {
                if (pick == 0) {
                    g_Minigame._19E8[slot]._0 = pool[k];
                    g_Minigame._19E8[slot]._1 = 1;
                    slot++;
                    pool[k] = 0xFF;
                    break;
                }
                pick--;
            }
        }
    }
}

// .text:0x0010F5BC size:0xC8 mapped:0x8074E650
void fn_3_10F5BC(void) {
    if (g_Minigame._1A2C >= 0) {
        lbl_8036E548._307E = 0;
        fn_3_B95EC();
        fn_3_5E60();
    }
    g_Minigame._1A2C = -1;
    lbl_3_data_228._10 = 0;
    g_d_GameSettings.StadiumID = lbl_3_data_18910[g_Minigame.GameMode_MiniGame];
    g_d_GameSettings.miniGameStadiumIndicator = 0;
    if (g_d_GameSettings.StadiumID == STADIUM_ID_MARIO_STADIUM || g_d_GameSettings.StadiumID == STADIUM_ID_PEACH_GARDEN ||
        g_d_GameSettings.StadiumID == STADIUM_ID_BOWSERS_CASTLE || g_d_GameSettings.StadiumID == STADIUM_ID_YOHSI_PARK) {
        g_d_GameSettings.miniGameStadiumIndicator = 1;
    }
    fn_800B0A5C_insertQueue(manageStadiumLoading, 0);
}

// .text:0x0010F564 size:0x58 mapped:0x8074E5F8
s32 fn_3_10F564(void) {
    if (g_Minigame._1A2C == -1) {
        if (lbl_3_data_228._10 != 0) {
            g_Minigame._1A2C = lbl_3_data_18910[g_Minigame.GameMode_MiniGame];
            return 0;
        }
        return 1;
    }
    return 0;
}

// .text:0x0010F550 size:0x14 mapped:0x8074E5E4
void fn_3_10F550(u8 arg0, s16 arg1) {
    g_Minigame._1A41 = arg0;
    g_Minigame.someGraphicFrameCountdown = arg1;
}

// .text:0x0010F3D8 size:0x178 mapped:0x8074E46C
void fn_3_10F3D8(void) {
    switch (g_GameLogic._125) {
    case 0:
        fn_3_8B318(-1);
        fn_3_10C7A4();
        lbl_3_common_bss_34C58._2C = 0;
        g_GameLogic._125++;
    case 1:
        if (fn_3_90928() != 0) {
            g_GameLogic._125++;
        }
        break;
    case 2:
        if (fn_80035838(&lbl_3_data_21EC8[29], 9) != 0) {
            g_GameLogic._125++;
        }
        break;
    case 3:
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
            if (fn_80035838(&lbl_3_data_21EC8[13], 0x11) != 0) {
                g_GameLogic._125++;
            }
        } else {
            g_GameLogic._125++;
        }
        break;
    default:
        fn_800189E4();
        fn_800B0A5C_insertQueue(fn_80062A94, 1);
        g_Minigame.battingHandedness[5] = 1;
        fn_3_5A6D4(g_Minigame._19DF);
        break;
    }
}

// .text:0x0010F1D4 size:0x204 mapped:0x8074E268
void fn_3_10F1D4(void) {
    switch (g_GameLogic._125) {
    case 0:
        changeScene(6, 6);
        g_GameLogic._125++;
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        lbl_8036E548._307E = 0;
        g_Minigame._19E4 = 0;
        break;
    case 1:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 20) {
            g_GameLogic._125++;
        }
        break;
    case 2:
        fn_3_10EFAC();
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        break;
    case 3:
        if (lbl_3_common_bss_32724._BB == 0) {
            g_GameLogic._125++;
        }
        break;
    case 4:
        if (g_Minigame.GameMode_MiniGame >= 1 && g_Minigame.GameMode_MiniGame <= 6) {
            if (g_Minigame._190A != 0) {
                g_Minigame._19E4 = 0;
            } else {
                g_Minigame._19E4 = g_d_GameSettings._13_arr[g_Minigame.GameMode_MiniGame];
            }
        }
        fn_3_5A6D4(0x1E);
        break;
    case 5:
        switch (fn_3_5B380(g_Controls[lbl_80366158._27].newButtonInput)) {
        case 1:
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            g_GameLogic._125++;
            break;
        case 2:
            g_GameLogic._125 = 2;
            break;
        }
        break;
    case 6:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
            changeScene(4, 6);
        }
        if (lbl_8037169C._13 != 0) {
            fn_80062A74();
            g_Minigame.battingHandedness[5] = 0;
            g_GameLogic._125++;
        }
        break;
    case 7:
        fn_8004CC18();
        g_GameLogic.framesOfExitingToMenu = 1;
        break;
    }
}

// .text:0x0010EFAC size:0x228 mapped:0x8074E040
void fn_3_10EFAC(void) {
    InputStruct* input = &g_Controls[lbl_80366158._27];
    u8 mode;

    if (lbl_3_common_bss_32724._BB == 0) {
        if (input->newButtonInput & 0x100) {
            mode = lbl_3_data_21268[g_Minigame._19E1];
            if (mode == 6 && g_d_GameSettings._12 < 1) {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            } else if (mode == 7 && g_d_GameSettings._12 < 2) {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            } else {
                g_GameLogic._125 = 3;
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            }
        } else if (input->newButtonInput & 0x200) {
            fn_3_5B408();
            g_GameLogic._125 = 5;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        } else if (input->_08 & 1) {
            if (g_Minigame._19E1 != 0) {
                g_Minigame._19E1--;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        } else if (input->_08 & 2) {
            if (g_Minigame._19E1 < 6) {
                g_Minigame._19E1++;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        }
    }
    g_Minigame.GameMode_MiniGame = lbl_3_data_21268[g_Minigame._19E1];
    if (g_Minigame.GameMode_MiniGame == 7) {
        g_Minigame._1A3C = 1;
    } else {
        g_Minigame._1A3C = 0;
    }
    lbl_3_common_bss_32724._B9 = g_Minigame._19E1;
}

// .text:0x0010E60C size:0x9A0 mapped:0x8074D6A0
void fn_3_10E60C(void) {
    CharacterStats* stats;
    int i;
    int j;

    if (g_GameLogic._125 <= 2) {
        for (i = 0; i < 4; i++) {
            g_Minigame._19E8[i]._8 = g_Minigame._19E8[i]._7;
            g_Minigame._19E8[i]._7 = 1;
        }
    }
    switch (g_GameLogic._125) {
    case 0:
        for (i = 0; i < 4; i++) {
            if (g_Minigame._19DA[i] == 1) {
                g_Minigame._19DA[i] = -1;
            }
            g_Minigame.minigameControlStruct.aIStrength[i] = 0;
            g_Minigame._1A13[i] = 1;
        }
        if (g_Minigame._190A != 0) {
            fn_80050FE8(1, 1, 1, 1, 1, 0);
            for (i = 0; i < 54; i++) {
                if (starMissionCompletionTracker.characters[i]._31 != 1) {
                    fn_8004FDA0(i);
                }
            }
            g_Minigame._19E8[lbl_3_common_bss_37400._40]._0 = g_d_GameSettings._36;
        } else {
            fn_80050FE8(1, 1, 1, 1, 1, 1);
            for (i = 0; i < 4; i++) {
                if (g_Minigame._19DA[i] < 0) {
                    g_Minigame._19E8[i]._0 = -1;
                }
            }
        }
        for (i = 0; i < 3; i++) {
            if (g_Minigame._19E8[i]._0 >= 0) {
                for (j = i + 1; j < 4; j++) {
                    if (g_Minigame._19E8[i]._0 == g_Minigame._19E8[j]._0) {
                        g_Minigame._19E8[j]._0 = -3;
                    }
                }
            }
        }
        fn_80050138(1, g_Minigame._19E8[0]._0, g_Minigame._19E8[1]._0, g_Minigame._19E8[2]._0, g_Minigame._19E8[3]._0, 1);
        for (i = 0; i < 4; i++) {
            g_Minigame._19E8[i]._1 = 0;
            g_Minigame._19D2[i] = 20;
        }
        lbl_8036E548._307E = 0;
        lbl_8036E548._2D77 = 0;
        lbl_8036E548._307A = 5;
        g_Minigame._18A2[0] = -1;
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_Minigame._19DE = 0;
        g_Minigame._19E2 = 0;
        g_Minigame._19E3 = 0;
        if (g_Minigame.battingHandedness[5] == 0) {
            fn_800B0A5C_insertQueue(fn_80062A94, 1);
        }
        changeScene(1, 6);
        g_GameLogic._125++;
        break;
    case 1:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            for (i = 0; i < 4; i++) {
                if (g_Minigame._19DA[i] == 0) {
                    g_Minigame._19E8[i]._0 = fn_80050760(i, 0, 0, 0, 0);
                    g_Minigame._19E8[i]._6 = 0;
                    stats = &lbl_8034E9A0[g_Minigame._19E8[i]._0];
                    g_Minigame.battingHandedness[i] = stats->stats.BattingStance + stats->stats.FieldingArm * 2;
                    g_Minigame.minigameControlStruct._8[i] = 0;
                }
            }
            changeScene(1, 6);
        }
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 30) {
            g_Minigame._19DE = 0;
            if (g_Minigame._19E0 != 0) {
                g_Minigame._19DE = 5;
                g_Minigame._19E0 = 0;
                g_Minigame._19E8[lbl_80366158._27]._1 = 1;
                fn_800506E8(lbl_80366158._27, g_Minigame._19E8[lbl_80366158._27]._0, 1);
            }
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            g_GameLogic._125++;
        }
        break;
    case 2:
        fn_3_10CC20();
        break;
    case 3:
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 20) {
                switch (fn_3_5B380(g_Controls[lbl_80366158._27].newButtonInput)) {
                case 1:
                    g_GameLogic._125 = 4;
                    g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                    return;
                case 2:
                    g_GameLogic._125 = 2;
                    break;
                }
            }
            return;
        }
        g_GameLogic._125 = 4;
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        break;
    case 4:
        if (g_Minigame._1A0C == -1) {
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
                if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
                    changeScene(4, 6);
                }
                if (lbl_8037169C._13 != 0) {
                    g_GameLogic._125 = 5;
                }
            } else if (g_GameLogic.FrameCountOfCurrentAtBat_Copy >= 15) {
                fn_3_5A6D4(0x1C);
            }
        }
        lbl_8036E548._307A = 0;
        break;
    case 5:
        fn_3_972C8();
        fn_8004CC18();
        g_GameLogic.framesOfExitingToMenu = 1;
        break;
    case 6:
        if (g_Minigame._1A0F[0] < 0) {
            for (i = 0; i < 4; i++) {
                if (g_Minigame._19E8[i]._7 == 0 && g_Minigame._19E8[i]._1 != 0) {
                    break;
                }
            }
            if (i >= 4) {
                changeScene(3, 6);
                if (g_Minigame._1A3C == 0) {
                    lbl_803C6714._6 = 6;
                    g_Minigame.battingHandedness[5] = 0;
                }
            }
        }
        if (lbl_8037169C._13 != 0) {
            g_GameLogic._125 = 7;
        }
        break;
    case 7:
        fn_3_60768();
        fn_3_10C58C();
        lbl_8036E548._307A = 0;
        g_Minigame.battingHandedness[6] = 0;
        if (g_Minigame._1A3C != 0) {
            fn_3_1078F8();
        } else {
            fn_3_5A6D4(0x21);
        }
        break;
    }
    if (g_GameLogic._125 == 3 || g_GameLogic._125 == 4) {
        for (i = 0; i < 4; i++) {
            g_Minigame._19E8[i]._7 = 0;
        }
    }
    if (g_GameLogic._125 >= 2) {
        fn_3_10C81C();
    }
}

// .text:0x0010CC20 size:0x19EC mapped:0x8074BCB4
// 99.90%: case 3's "_1 == 1" skip is a direct beq where the target branches
// over a b (one instruction short), and the lbl_3_data_18920 row lookup in
// case 0 swaps r4 and r5
void fn_3_10CC20(void) {
    s8 sel[4];
    u8 taken[12];
    CharacterStats* stats;
    InputStruct* input;
    int port;
    int maxDiff;
    s32 i;
    s32 j;
    s32 k;
    int changed;
    u8 ready;
    s32 avail;
    s32 pick;
    int old;
    int c;
    u16 buttons;
    u16 held;

    port = lbl_80366158._27;
    input = &g_Controls[port];
    maxDiff = g_d_GameSettings._13_arr[g_Minigame.GameMode_MiniGame];
    if (g_Minigame._190A != 0) {
        maxDiff = 2;
    }
    if (g_Minigame._19DE == 0) {
        changed = 0;
        for (i = 0; i < 4; i++) {
            lbl_803C6028._74[i] = 0;
            sel[i] = -1;
            if (g_Minigame._19DA[i] == 0) {
                if (i != port && g_Minigame._19E8[i]._1 == 0 && (g_Controls[i].newButtonInput & 0x200) &&
                    lbl_803C6028._92 != 0) {
                    g_Minigame._19DA[i] = -1;
                    g_Minigame._19E7--;
                    sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                }
            } else if (i == port) {
                g_Minigame._19DA[i] = 0;
                changed = 1;
                sel[i] = -3;
            } else if (g_Minigame._190A == 0 && (g_Controls[i].newButtonInput & 0x100)) {
                g_Minigame._19DA[i] = 0;
                changed = 1;
                sel[i] = -3;
                g_Minigame._19E7++;
            }
        }
        if (changed) {
            fn_80050138(0, sel[0], sel[1], sel[2], sel[3], 0);
        }
        for (i = 0, ready = 0; i < 4; i++) {
            if (g_Minigame._19DA[i] != 0) {
                continue;
            }
            if (g_Minigame._19D2[i] < 0xFFFE) {
                g_Minigame._19D2[i]++;
            } else {
                g_Minigame._19D2[i] = 0xFFFF;
            }
            if (sel[i] == -3) {
                g_Minigame._19E8[i]._0 = fn_80050760(i, 0, 0, 0, 0);
                g_Minigame._19E8[i]._7 = 0;
                stats = &lbl_8034E9A0[g_Minigame._19E8[i]._0];
                g_Minigame.battingHandedness[i] = stats->stats.BattingStance + stats->stats.FieldingArm * 2;
                g_Minigame.minigameControlStruct._8[i] = 0;
                if (g_d_GameSettings.exhibitionMatchInd == 0 &&
                    starMissionCompletionTracker._43D6[g_Minigame._19E8[i]._0] != 0) {
                    g_Minigame.minigameControlStruct._8[i] = 0;
                }
                if (i != port) {
                    sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                }
            } else if (g_Minigame._19E8[i]._1 != 0) {
                if (g_Controls[i].newButtonInput & 0x200) {
                    if (lbl_803C6028._92 == 0) {
                        continue;
                    }
                    g_Minigame._19E8[i]._1 = 0;
                    fn_800506E8(i, g_Minigame._19E8[i]._0, 0);
                    fn_80050760(i, 0, 0, 0, 0);
                    sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                    for (j = 0; j < 4; j++) {
                        if (i != j && g_Minigame._19DA[j] == 0) {
                            pick = fn_8004FDE8(i, j);
                            if (pick >= -1) {
                                g_Minigame._19E8[j]._0 = pick;
                            }
                        }
                    }
                } else {
                    ready++;
                }
            } else {
                buttons = g_Controls[i].newButtonInput;
                if ((buttons & 0x100) && g_Minigame._19E8[i]._0 >= 0 && g_GameLogic.FrameCountOfCurrentAtBat_Copy > 30) {
                    if (g_Minigame._19E8[i]._6 != 0) {
                        sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                        goto choose;
                    }
                    if (lbl_803C6028._7F[i] < 0 && g_Minigame._19E8[i]._0 == g_Minigame._19E8[i]._2 &&
                        g_Minigame._19E8[i]._4 == g_Minigame._19E8[i]._5 && g_Minigame._19E8[i]._7 != 0 &&
                        g_Minigame._19E8[i]._8 != 0) {
                        g_Minigame._19E8[i]._1 = 1;
                        fn_800506E8(i, g_Minigame._19E8[i]._0, 1);
                        fn_800628D4(g_Minigame._19E8[i]._0);
                    }
                } else if ((buttons & 0x200) && g_d_GameSettings.exhibitionMatchInd != 0) {
                    if (lbl_803C6028._92 == 0) {
                        continue;
                    }
                    if (lbl_803C6028._7F[i] < 0) {
                        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                        g_GameLogic._125 = 3;
                        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                        return;
                    }
                } else {
                choose:
                    old = g_Minigame._19E8[i]._0;
                    c = fn_80050760(i, g_Controls[i].buttonInput, g_Controls[i].newButtonInput, g_Controls[i]._08, 0);
                    if (c >= 0) {
                        g_Minigame._19E8[i]._0 = c;
                        if (old != g_Minigame._19E8[i]._0) {
                            g_Minigame._19D2[i] = 0;
                            stats = &lbl_8034E9A0[g_Minigame._19E8[i]._0];
                            g_Minigame.battingHandedness[i] = stats->stats.BattingStance + stats->stats.FieldingArm * 2;
                            g_Minigame.minigameControlStruct._8[i] = 0;
                            if (g_d_GameSettings.exhibitionMatchInd == 0 &&
                                starMissionCompletionTracker._43D6[g_Minigame._19E8[i]._0] != 0) {
                                g_Minigame.minigameControlStruct._8[i] = 0;
                            }
                        }
                        g_Minigame._19E8[i]._6 = 0;
                    } else {
                        g_Minigame._19E8[i]._0 = fn_8004FD64(i);
                        g_Minigame._19E8[i]._6 = 1;
                        g_Minigame._19E8[i]._7 = 0;
                    }
                }
            }
            if (g_Minigame._19E8[i]._6 == 0 && g_Minigame._19E8[i]._1 == 0 && (g_Controls[i].newButtonInput & 0x400)) {
                g_Minigame._19D2[i] = 0;
                g_Minigame.battingHandedness[i]++;
                if (g_Minigame.battingHandedness[i] > 3) {
                    g_Minigame.battingHandedness[i] = 0;
                }
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
            if (g_Minigame._190A != 0) {
                if (starMissionCompletionTracker._43D6[g_Minigame._19E8[i]._0] != 0) {
                    g_Minigame.minigameControlStruct._8[i] = 1;
                } else {
                    g_Minigame.minigameControlStruct._8[i] = 0;
                }
            } else if (lbl_80361B20[g_Minigame._19E8[i]._0] != 0 && (g_Controls[i].newButtonInput & 0x800)) {
                g_Minigame.minigameControlStruct._8[i] ^= 1;
                if (g_Minigame.minigameControlStruct._8[i] != 0) {
                    sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
                } else {
                    sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                }
            }
        }
        if (ready >= g_Minigame._19E7) {
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            g_Minigame._19DE = 2;
            g_Minigame._19E6 = g_Minigame._19E7;
            if (g_Minigame._1A3C != 0) {
                if (g_Minigame._19E7 == 4) {
                    g_Minigame._19DE = 7;
                } else {
                    g_Minigame._19DE = 6;
                }
                g_Minigame._19E6 = 4;
            } else if (g_Minigame._19E7 == 1 && g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
                g_Minigame._19DE = 5;
            } else if (g_Minigame._19E7 == 4) {
                g_Minigame._19DE = 7;
            } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && g_d_GameSettings.exhibitionMatchInd != 0) {
                g_Minigame._19DE = 2;
                g_Minigame._19E6 = lbl_3_data_18920[g_Minigame.GameMode_MiniGame][4];
            } else if (g_Minigame._19E7 >= lbl_3_data_18920[g_Minigame.GameMode_MiniGame][4]) {
                g_Minigame._19DE = 1;
                if (g_Minigame._19E7 >= lbl_3_data_18920[g_Minigame.GameMode_MiniGame][4]) {
                    g_Minigame._1A0D = 0;
                } else {
                    g_Minigame._1A0D = lbl_3_data_18920[g_Minigame.GameMode_MiniGame][4] - g_Minigame._19E7;
                }
                g_Minigame._1A0E = 4 - g_Minigame._19E7;
                g_Minigame._19E3 = g_Minigame._1A0D;
            } else {
                g_Minigame._19E6 = lbl_3_data_18920[g_Minigame.GameMode_MiniGame][4];
                g_Minigame._19DE = 2;
            }
        }
    } else if (g_Minigame._19DE == 1) {
        buttons = input->newButtonInput;
        if (buttons & 0x100) {
            if (g_Minigame._19E3 != 0) {
                g_Minigame._19E6 = g_Minigame._19E3 + g_Minigame._19E7;
                g_Minigame._19DE = 2;
            } else {
                g_Minigame._19DE = 7;
            }
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        } else if (buttons & 0x200) {
            g_Minigame._19E8[port]._1 = 0;
            fn_800506E8(port, g_Minigame._19E8[port]._0, 0);
            g_Minigame._19DE = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        } else {
            held = input->_08;
            if (held & 8) {
                if (g_Minigame._19E3 > g_Minigame._1A0D) {
                    g_Minigame._19E3--;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
            } else if (held & 4) {
                if (g_Minigame._19E3 < g_Minigame._1A0E) {
                    g_Minigame._19E3++;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
            }
        }
    } else if (g_Minigame._19DE == 2 || g_Minigame._19DE == 6) {
        k = g_Minigame._19E6 - g_Minigame._19E7;
        for (i = 0; i < 4; i++) {
            if (k != 0 && g_Minigame._19DA[i] == -1) {
                g_Minigame._19DA[i] = 1;
                k--;
                g_Minigame._19E8[i]._0 = -1;
                g_Minigame._19E8[i]._2 = -1;
                lbl_803C6028._74[i] = 1;
            }
        }
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && g_d_GameSettings.exhibitionMatchInd == 0) {
            g_Minigame._19DE = 8;
        } else if (g_Minigame._19E7 == 1 && g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
            g_Minigame._19DE = 8;
        } else {
            g_Minigame._19DE = 3;
        }
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
    } else if (g_Minigame._19DE == 3) {
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            if (g_Minigame._18A2[0] >= 0) {
                g_Minigame._18A2[0] = -1;
            } else {
                for (k = 0; k < 12; k++) {
                    taken[k] = 0;
                }
                avail = 12;
                for (i = 0; i < 4; i++) {
                    sel[i] = -1;
                    if (g_Minigame._19E8[i]._1 != 0) {
                        for (k = 0; k < 12; k++) {
                            if (g_Minigame._19E8[i]._0 == lbl_800E854C[k]) {
                                taken[k] = 1;
                                avail--;
                            }
                        }
                    }
                }
                for (i = 0; i < 4; i++) {
                    if (g_Minigame._19DA[i] == 1 && g_Minigame._19E8[i]._1 == 0) {
                        pick = random_fn_3_9EE24(avail);
                        for (k = 0; k < 12; k++) {
                            if (taken[k] == 0) {
                                if (pick == 0) {
                                    sel[i] = lbl_800E854C[k];
                                    fn_80050138(1, sel[0], sel[1], sel[2], sel[3], 0);
                                    g_Minigame._19E8[i]._0 = sel[i];
                                    stats = &lbl_8034E9A0[sel[i]];
                                    g_Minigame.battingHandedness[i] = stats->stats.BattingStance + stats->stats.FieldingArm * 2;
                                    g_Minigame.minigameControlStruct._8[i] = 0;
                                    break;
                                }
                                pick--;
                            }
                        }
                        break;
                    }
                }
            }
        } else if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
            for (i = 0; i < 4; i++) {
                if (g_Minigame._19DA[i] != 1) {
                    continue;
                }
                if (g_Minigame._19E8[i]._1 == 1) {
                    continue;
                }
                if (g_Minigame._19D2[i] < 0xFFFE) {
                    g_Minigame._19D2[i]++;
                } else {
                    g_Minigame._19D2[i] = 0xFFFF;
                }
                buttons = input->newButtonInput;
                if ((buttons & 0x100) && g_Minigame._19E8[i]._0 >= 0 && g_Minigame._19E8[i]._6 == 0) {
                    if (lbl_803C6028._7F[i] < 0 && g_Minigame._19E8[i]._0 == g_Minigame._19E8[i]._2 &&
                        g_Minigame._19E8[i]._4 == g_Minigame._19E8[i]._5 && g_Minigame._19E8[i]._7 != 0 &&
                        g_Minigame._19E8[i]._8 != 0) {
                        g_Minigame._19DE = 4;
                        g_Minigame._18A2[0] = i;
                        g_Minigame._19E8[i]._1 = 1;
                        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                        fn_800506E8(i, g_Minigame._19E8[i]._0, 1);
                        fn_800628D4(g_Minigame._19E8[i]._0);
                    }
                } else {
                    old = g_Minigame._19E8[i]._0;
                    c = fn_80050760(i, input->buttonInput, buttons, input->_08, 0);
                    if (c >= 0) {
                        g_Minigame._19E8[i]._0 = c;
                        if (old != g_Minigame._19E8[i]._0) {
                            g_Minigame._19D2[i] = 0;
                            stats = &lbl_8034E9A0[g_Minigame._19E8[i]._0];
                            g_Minigame.battingHandedness[i] = stats->stats.BattingStance + stats->stats.FieldingArm * 2;
                            g_Minigame.minigameControlStruct._8[i] = 0;
                        }
                        g_Minigame._19E8[i]._6 = 0;
                    } else {
                        g_Minigame._19E8[i]._6 = 1;
                        g_Minigame._19E8[i]._7 = 0;
                    }
                }
                if ((input->newButtonInput & 0x400) && g_Minigame._19E8[i]._6 == 0) {
                    g_Minigame._19D2[i] = 0;
                    g_Minigame.battingHandedness[i]++;
                    if (g_Minigame.battingHandedness[i] > 3) {
                        g_Minigame.battingHandedness[i] = 0;
                    }
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                if (lbl_80361B20[g_Minigame._19E8[i]._0] != 0 && (input->newButtonInput & 0x800)) {
                    g_Minigame.minigameControlStruct._8[i] ^= 1;
                    if (g_Minigame.minigameControlStruct._8[i] != 0) {
                        sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
                    } else {
                        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                    }
                }
                break;
            }
            if (i >= 4) {
                g_Minigame._19DE = 7;
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            } else {
                for (j = 0; j < 4; j++) {
                    if (g_Minigame._19DA[j] == 0 && (g_Controls[j].newButtonInput & 0x200)) {
                        lbl_803C6028._7F[i] = -1;
                        if (j == port) {
                            for (k = 3; k >= 0; k--) {
                                if (g_Minigame._19DA[k] == 1) {
                                    if (g_Minigame._19E8[k]._1 == 0) {
                                        if (g_Minigame._19E8[k]._2 != -1 || g_Minigame._19E8[k]._3 != -1) {
                                            g_Minigame._19E8[k]._0 = -1;
                                            g_Minigame._19E8[k]._2 = -1;
                                            g_Minigame._19E8[k]._7 = 0;
                                            g_Minigame._1A13[k] = 1;
                                        }
                                    } else {
                                        fn_800506E8(k, g_Minigame._19E8[k]._0, 0);
                                        g_Minigame._19E8[k]._1 = 0;
                                        break;
                                    }
                                }
                            }
                            if (k < 0) {
                                for (k = 3; k >= 0; k--) {
                                    if (g_Minigame._19DA[k] == 1) {
                                        if (g_Minigame._19E8[k]._0 >= 0) {
                                            if (g_Minigame._19E8[k]._2 == -1) {
                                                g_Minigame._19E8[k]._4 = 1;
                                            } else {
                                                g_Minigame._19E8[k]._0 = -1;
                                                g_Minigame._19E8[k]._2 = -1;
                                                g_Minigame._1A13[k] = 1;
                                                g_Minigame._19E8[k]._1 = 0;
                                            }
                                        }
                                        g_Minigame._19DA[k] = -1;
                                    }
                                }
                                fn_800506E8(j, g_Minigame._19E8[j]._0, 0);
                                g_Minigame._19DE = 0;
                                g_Minigame._19E8[j]._1 = 0;
                            }
                        } else {
                            fn_800506E8(j, g_Minigame._19E8[j]._0, 0);
                            g_Minigame._19DE = 0;
                            g_Minigame._19E8[j]._1 = 0;
                            for (k = 0; k < 4; k++) {
                                if (g_Minigame._19DA[k] == 1) {
                                    if (g_Minigame._19E8[k]._0 >= 0) {
                                        if (g_Minigame._19E8[k]._1 == 1) {
                                            fn_800506E8(k, g_Minigame._19E8[k]._0, 0);
                                        }
                                        if (g_Minigame._19E8[k]._2 != -1) {
                                            g_Minigame._19E8[k]._0 = -1;
                                            g_Minigame._19E8[k]._2 = -1;
                                            g_Minigame._1A13[k] = 1;
                                            g_Minigame._19E8[k]._1 = 0;
                                        }
                                    }
                                    g_Minigame._19DA[k] = -1;
                                }
                            }
                        }
                        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                        return;
                    }
                }
            }
        }
    } else if (g_Minigame._19DE == 4) {
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 40) {
            buttons = input->newButtonInput;
            if (buttons & 0x100) {
                g_Minigame._18A2[0] = -1;
                g_Minigame._19DE = 3;
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            } else if (buttons & 0x200) {
                fn_800506E8(g_Minigame._18A2[0], g_Minigame._19E8[g_Minigame._18A2[0]]._0, 0);
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                g_Minigame._19E8[g_Minigame._18A2[0]]._1 = 0;
                g_Minigame._19DE = 3;
                sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            } else {
                held = input->_08;
                if (held & 8) {
                    if (g_Minigame.minigameControlStruct.aIStrength[g_Minigame._18A2[0]] != 0) {
                        g_Minigame.minigameControlStruct.aIStrength[g_Minigame._18A2[0]]--;
                        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                    }
                } else if (held & 4) {
                    if (g_Minigame.minigameControlStruct.aIStrength[g_Minigame._18A2[0]] < 3) {
                        g_Minigame.minigameControlStruct.aIStrength[g_Minigame._18A2[0]]++;
                        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                    }
                }
            }
        }
    } else if (g_Minigame._19DE == 5) {
        for (i = 0; i < 4; i++) {
            if (g_Minigame._19DA[i] >= 0 && g_Minigame._19E8[i]._1 != 0) {
                if (g_Minigame._19D2[i] < 0xFFFE) {
                    g_Minigame._19D2[i]++;
                } else {
                    g_Minigame._19D2[i] = 0xFFFF;
                }
            }
        }
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 30) {
            buttons = input->newButtonInput;
            if (buttons & 0x100) {
                g_Minigame._19DE = 6;
                g_Minigame.soloMinigameDifficulty = g_Minigame._19E4;
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            } else if (buttons & 0x200) {
                g_Minigame._19E8[port]._1 = 0;
                fn_800506E8(port, g_Minigame._19E8[port]._0, 0);
                g_Minigame._19DE = 0;
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            } else {
                held = input->_08;
                if (held & 1) {
                    if (g_Minigame._19E4 > 0) {
                        g_Minigame._19E4--;
                        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                    }
                } else if (held & 2) {
                    if (g_Minigame._19E4 < maxDiff) {
                        g_Minigame._19E4++;
                        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                    }
                }
            }
            g_Minigame._19E6 = lbl_3_data_18920[g_Minigame.GameMode_MiniGame][g_Minigame._19E4];
        }
    } else if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 90) {
        g_GameLogic._125 = 6;
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
    }
    if (g_d_GameSettings.exhibitionMatchInd != 0 &&
        (g_Minigame._19DE == 1 || g_Minigame._19DE == 2 || g_Minigame._19DE == 3 || g_Minigame._19DE == 4 || g_Minigame._19DE == 5) &&
        g_GameLogic.FrameCountOfCurrentAtBat_Copy >= 30) {
        for (i = 0; i < 4; i++) {
            sel[i] = -1;
        }
        for (i = 0; i < 4; i++) {
            sel[i] = -1;
            if (g_Minigame._19DA[i] != 0 && (g_Controls[i].newButtonInput & 0x100)) {
                if (g_Minigame._19E8[i]._0 >= 0) {
                    if (g_Minigame._19E8[i]._1 == 1) {
                        fn_800506E8(i, g_Minigame._19E8[i]._0, 0);
                    }
                    if (g_Minigame._19E8[i]._2 != -1) {
                        g_Minigame._19E8[i]._0 = -1;
                        g_Minigame._19E8[i]._2 = -1;
                        g_Minigame._1A13[i] = 1;
                        g_Minigame._19E8[i]._1 = 0;
                    }
                }
                g_Minigame._19DA[i] = 0;
                g_Minigame._19E8[i]._0 = -1;
                g_Minigame._19E8[i]._2 = -1;
                sel[i] = -3;
                break;
            }
        }
        if (i < 4) {
            for (i = 0; i < 4; i++) {
                if (g_Minigame._19DA[i] == 1) {
                    if (g_Minigame._19E8[i]._0 >= 0) {
                        if (g_Minigame._19E8[i]._1 == 1) {
                            fn_800506E8(i, g_Minigame._19E8[i]._0, 0);
                        }
                        if (g_Minigame._19E8[i]._2 != -1) {
                            g_Minigame._19E8[i]._0 = -1;
                            g_Minigame._19E8[i]._2 = -1;
                            g_Minigame._1A13[i] = 1;
                            g_Minigame._19E8[i]._1 = 0;
                        }
                    }
                    g_Minigame._19DA[i] = -1;
                }
            }
            fn_80050138(0, sel[0], sel[1], sel[2], sel[3], 0);
            g_Minigame._19E7++;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            g_Minigame._19DE = 0;
        }
    }
}

// .text:0x0010C81C size:0x404 mapped:0x8074B8B0
void fn_3_10C81C(void) {
    int j;
    int cur;
    UnkQueue31A0 queue[4];
    int player;
    int wait;
    int n;
    int i;
    int count;
    int k;
    int port;
    int found;

    n = 4;
restart:
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        n = 1;
    }
    for (i = 0, count = 0; i < n; i++) {
        queue[i].player = -1;
        if (g_Minigame._1A0C != i && g_Minigame._19E8[i]._0 != -1 &&
            (g_Minigame._19E8[i]._0 != g_Minigame._19E8[i]._2 || g_Minigame._19E8[i]._4 != g_Minigame.battingHandedness[i])) {
            g_Minigame._19E8[i]._7 = 0;
            if (g_Minigame._19D2[i] >= 20 || g_Minigame._19DE == 4) {
                queue[count].player = i;
                queue[count].wait = g_Minigame._19D2[i];
                count++;
                g_Minigame._19E8[i]._5 = g_Minigame.battingHandedness[i];
            }
        }
    }
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (queue[i].wait < queue[j].wait) {
                player = queue[i].player;
                wait = queue[i].wait;
                queue[i].player = queue[j].player;
                queue[i].wait = queue[j].wait;
                queue[j].player = player;
                queue[j].wait = wait;
            }
        }
    }
    g_Minigame._1A0F[0] = -1;
    g_Minigame._1A0F[1] = -1;
    g_Minigame._1A0F[2] = -1;
    g_Minigame._1A0F[3] = -1;
    k = 0;
    if (g_Minigame._1A0C >= 0) {
        g_Minigame._1A0F[0] = g_Minigame._1A0C;
        k = 1;
    }
    for (i = 0; i < count; i++, k++) {
        g_Minigame._1A0F[k] = queue[i].player;
    }
    if (g_Minigame._1A0F[0] >= 0) {
        cur = g_Minigame._1A0F[0];
        port = cur;
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
            port = 9;
        }
        if (g_Minigame.battingHandedness[4] == 0) {
            g_Minigame.battingHandedness[4] = 1;
            fn_80011B64(port);
        }
        if (g_Minigame._19E8[cur]._3 >= 0) {
            found = fn_80016710(g_Minigame._19E8[cur]._3, port);
        } else {
            found = fn_80016710(g_Minigame._19E8[cur]._0, port);
        }
        if (found) {
            g_Minigame._19E8[cur]._2 = g_Minigame._19E8[cur]._3;
            g_Minigame._19E8[cur]._3 = -1;
            g_Minigame._19E8[cur]._4 = g_Minigame._19E8[cur]._5;
            lbl_8036E548._2D77 = 0;
            g_Minigame._1A0C = -1;
            g_Minigame._1A0F[0] = -1;
            g_Minigame._1A13[cur] = 0;
            g_Minigame.battingHandedness[4] = 0;
            fn_3_E1370(3);
            goto restart;
        }
        if (g_Minigame._19E8[cur]._3 < 0) {
            g_Minigame._19E8[cur]._3 = g_Minigame._19E8[cur]._0;
        }
        g_Minigame._19E8[cur]._2 = -1;
        g_Minigame._1A0C = cur;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame._1A13[i] != 0 && g_Minigame._19E8[i]._0 == g_Minigame._19E8[i]._2) {
            g_Minigame._1A13[i] = 0;
        }
    }
}

// .text:0x0010C7A4 size:0x78 mapped:0x8074B838
void fn_3_10C7A4(void) {
    int i;

    fn_8001CA40(0);
    for (i = 0; i < 4; i++) {
        fn_80011BE4(i);
        g_Minigame._19E8[i]._1 = 0;
        g_Minigame._19E8[i]._2 = -1;
    }
}

// .text:0x0010C58C size:0x218 mapped:0x8074B620
void fn_3_10C58C(void) {
    int i;

    for (i = 0; i < 4; i++) {
        g_Minigame.minigameControlStruct.characterIndex[i] = -1;
        g_Minigame.minigameControlStruct.battingHandedness[i] = 0;
        g_Minigame.minigameControlStruct._4[i] = 0xFF;
    }
    g_Minigame.miniGameNumberOfParticipants = 0;
    g_Minigame._1907 = 0;
    fn_3_10BE7C();
    for (i = 0; i < 4; i++) {
        if (g_Minigame._19DA[i] >= 0) {
            g_Minigame.minigameControlStruct.characterIndex[g_Minigame.miniGameNumberOfParticipants] = i;
            g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.miniGameNumberOfParticipants] = g_Minigame._19DA[i];
            if (g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.miniGameNumberOfParticipants] == 0) {
                g_Minigame._1907++;
            }
            fn_3_10C450(i, g_Minigame._19E8[i]._0);
            g_Minigame.minigameControlStruct._4[g_Minigame.miniGameNumberOfParticipants] = inMemRoster[0][i].stats.CharID;
            g_Minigame.miniGameNumberOfParticipants++;
        }
    }
}

// .text:0x0010C450 size:0x13C mapped:0x8074B4E4
void fn_3_10C450(int player, int charID) {
    CharacterStats* stats = &inMemRoster[0][player];

    memcpy(stats, &lbl_8034E9A0[charID], sizeof(CharacterStats));
    if (g_Minigame.minigameControlStruct._8[player] != 0) {
        stats->stats.SlapContactSize += lbl_800E86F0[0];
        stats->stats.ChargeContactSize += lbl_800E86F0[1];
        stats->stats.SlapHitPower += lbl_800E86F0[2];
        stats->stats.ChargeHitPower += lbl_800E86F0[3];
        stats->stats.BuntingContactSize += lbl_800E86F0[4];
        stats->stats.Speed += lbl_800E86F0[5];
        stats->stats.ThrowingArm += lbl_800E86F0[6];
        stats->stats.CurveBallSpeed += lbl_800E86F0[7];
        stats->stats.FastBallSpeed += lbl_800E86F0[8];
        stats->stats.cursedBall += lbl_800E86F0[9];
        stats->stats.Curve += lbl_800E86F0[10];
        stats->stats.curveControl += lbl_800E86F0[11];
    }
}

// .text:0x0010BE7C size:0x5D4 mapped:0x8074AF10
// 95.93%: the 12-entry copy keeps a loop-entry test the target has, and registers differ
void fn_3_10BE7C(void) {
    int pool[12];
    int taken[4];
    int count;
    int chr;
    int n;
    int row;
    int i;
    int j;
    int k;

    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameControlStruct.battingHandedness[i] == 0 && g_Minigame._19DA[i] >= 0) {
            taken[i] = g_Minigame._19E8[i]._0;
        } else {
            taken[i] = -1;
        }
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && g_d_GameSettings.exhibitionMatchInd == 0) {
        for (k = 0; k < lbl_3_data_1894C[0][0]; k++) {
            pool[k] = lbl_3_data_1894C[0][k + 1];
        }
    } else if (g_Minigame._1A3C != 0) {
        for (k = 0; k < 12; k++) {
            pool[k] = lbl_800E854C[k];
        }
        fn_3_9E078(pool, 12, 0);
    } else {
        if ((g_Minigame.GameMode_MiniGame == 1 || g_Minigame.GameMode_MiniGame == 3) && g_Minigame._1908 >= 0) {
            return;
        }
        count = 6;
        if (g_d_GameSettings.exhibitionMatchInd == 0) {
            if (g_Minigame.GameMode_MiniGame == 2) {
                row = g_Minigame.soloMinigameDifficulty;
            } else if (g_Minigame.GameMode_MiniGame == 4) {
                row = g_Minigame.soloMinigameDifficulty + 3;
            } else if (g_Minigame.GameMode_MiniGame == 5) {
                row = g_Minigame.soloMinigameDifficulty + 6;
            } else if (g_Minigame.GameMode_MiniGame == 6) {
                row = g_Minigame.soloMinigameDifficulty + 9;
            } else {
                row = 0;
            }
            count = 0;
            for (k = 0; k < 6; k++) {
                pool[k] = lbl_3_data_609C[row][k];
                if (pool[k] != 0xFF) {
                    count++;
                }
            }
        } else {
            if (g_Minigame.GameMode_MiniGame == 2) {
                if (g_Minigame.soloMinigameDifficulty == 3) {
                    row = -1;
                } else {
                    row = g_Minigame.soloMinigameDifficulty + 1;
                }
            } else if (g_Minigame.GameMode_MiniGame == 4) {
                row = g_Minigame.soloMinigameDifficulty + 5;
            } else if (g_Minigame.GameMode_MiniGame == 5) {
                row = g_Minigame.soloMinigameDifficulty + 9;
            } else if (g_Minigame.GameMode_MiniGame == 6) {
                row = g_Minigame.soloMinigameDifficulty + 13;
            } else {
                row = 0;
            }
            if (row < 0) {
                for (k = 0; k < 6; k++) {
                    pool[k] = -1;
                }
            } else {
                for (k = 0; k < 6; k++) {
                    pool[k] = lbl_3_data_212A4[row][k];
                }
            }
        }
        fn_3_9E078(pool, count, 0);
    }
    j = 0;
    for (i = 0; i < 4; i++) {
        if (g_Minigame._19DA[i] != 0 && g_Minigame._19E8[i]._1 == 0) {
            for (n = j; n < 6; n++, j++) {
                for (k = 0; k < 4; k++) {
                    if (pool[n] == taken[k] && pool[n] >= 0) {
                        break;
                    }
                }
                if (k >= 4) {
                    break;
                }
            }
            chr = pool[n];
            g_Minigame._19E8[i]._0 = chr;
            j++;
            g_Minigame._19D2[i] = 20;
            g_Minigame.battingHandedness[i] = lbl_8034E9A0[chr].stats.BattingStance + lbl_8034E9A0[chr].stats.FieldingArm * 2;
        }
    }
}

// .text:0x0010B8D0 size:0x5AC mapped:0x8074A964
void fn_3_10B8D0(void) {
    int i;

    switch (g_GameLogic._125) {
    case 0:
        lbl_8036E548._307E = 0;
        if ((g_Minigame._1A3C == 0 || g_Minigame._1E2A <= 1) && g_Minigame._1A38 == 0) {
            fn_80062A74();
            fn_800189B8();
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
                fn_80035B50(0x11);
            }
            fn_80035B50(9);
            fn_3_908E8();
        }
        g_Minigame.battingHandedness[5] = 0;
        g_Minigame._1A41 = 0;
        g_Minigame.multiPlayerInd = 0;
        g_Minigame._19AA = 0;
        g_Minigame._1908 = -1;
        g_Minigame.battingHandedness[6] = 0;
        g_Minigame._1A23 = 0;
        g_Minigame._1A24[0] = 2;
        g_Minigame._1A46[0] = 0;
        if (g_d_GameSettings.exhibitionMatchInd == 0) {
            g_Minigame._1A24[0] = 0;
        }
        g_d_GameSettings._3A = g_Minigame.soloMinigameDifficulty;
        lbl_8037169C._15 = 0;
        lbl_3_common_bss_34C58._2C = 0;
        if (g_Minigame._1907 != 1 || g_Minigame._1A3C != 0) {
            g_Minigame.multiPlayerInd = 1;
            g_Minigame.soloMinigameDifficulty = 0;
        }
        if (g_Minigame._1907 == 1) {
            for (i = 0; i < 4; i++) {
                if (g_Minigame.minigameControlStruct.battingHandedness[i] == 0) {
                    g_Minigame._1908 = i;
                    break;
                }
            }
        }
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            g_d_GameSettings._33 = 0;
        } else {
            g_d_GameSettings._33 = g_Minigame.GameMode_MiniGame;
        }
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125++;
        if (g_Minigame._1A38 != 0 && g_Minigame._1A3C == 0) {
            changeScene(1, 6);
            g_GameLogic._125 = 2;
        }
        break;
    case 1:
        if (fn_80035838(&lbl_3_data_21EC8[g_Minigame.GameMode_MiniGame + 6], 0x11) != 0) {
            changeScene(1, 6);
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            g_GameLogic._125++;
        }
        break;
    case 2:
        if (g_Minigame._1A38 != 0 && g_Minigame._1A3C == 0) {
            g_GameLogic._125 = 8;
        } else if (fn_3_90860()) {
            lbl_3_common_bss_34C58._2C = 0;
            g_GameLogic._125++;
        }
        break;
    case 3:
        g_d_GameSettings.StadiumID = lbl_3_data_18910[g_Minigame.GameMode_MiniGame];
        if (fn_3_90A18()) {
            g_GameLogic._125++;
        }
        break;
    case 4:
        fn_80018B74();
        g_GameLogic._125++;
    case 5:
        g_Minigame._1A2C = -1;
        lbl_3_data_228._10 = 0;
        g_d_GameSettings.StadiumID = lbl_3_data_18910[g_Minigame.GameMode_MiniGame];
        g_d_GameSettings.miniGameStadiumIndicator = 0;
        if (g_d_GameSettings.StadiumID == STADIUM_ID_MARIO_STADIUM || g_d_GameSettings.StadiumID == STADIUM_ID_PEACH_GARDEN ||
            g_d_GameSettings.StadiumID == STADIUM_ID_BOWSERS_CASTLE || g_d_GameSettings.StadiumID == STADIUM_ID_YOHSI_PARK) {
            g_d_GameSettings.miniGameStadiumIndicator = 1;
        }
        fn_800B0A5C_insertQueue(manageStadiumLoading, 0);
        g_GameLogic._125++;
        break;
    case 6:
        if (fn_3_10F564() == 0) {
            g_GameLogic._125++;
        }
        break;
    case 7:
        if (fn_80020388()) {
            g_GameLogic._125++;
        }
        break;
    case 8:
        if (g_Minigame.battingHandedness[6] != 0) {
            changeScene(3, 6);
            if (g_Minigame.battingHandedness[6] == 2) {
                g_GameLogic._125 = 10;
            } else {
                g_GameLogic._125 = 9;
            }
        }
        break;
    case 9:
        if (lbl_8037169C._13 != 0) {
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
                g_Scores._AB = g_Scores._AA = g_Minigame._1A24[0] * 2 + 1;
                fn_3_5A6D4(5);
            } else {
                fn_3_5A6D4(4);
            }
            fn_3_BF070();
        }
        break;
    case 10:
        if (lbl_8037169C._13 != 0) {
            g_GameLogic._125 = 11;
        }
        break;
    case 11:
        g_Minigame._1A38 = 0;
        fn_3_10B200();
        break;
    }
    if (g_GameLogic._125 >= 2 && g_Minigame.battingHandedness[6] == 0) {
        fn_3_10B27C();
    }
}

// .text:0x0010B27C size:0x654 mapped:0x8074A310
void fn_3_10B27C(void) {
    int mode;
    int k;

    if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
        g_Minigame.battingHandedness[7] = 0;
        g_Minigame.battingHandedness[8] = 0;
        g_Minigame._1A20 = 0;
        g_Minigame._1A22 = 0;
        if (g_Minigame.multiPlayerInd != 0) {
            g_Minigame._1A20 = 2;
        } else if (g_Minigame.soloMinigameDifficulty == 3) {
            g_Minigame._1A20 = 1;
        }
        mode = g_Minigame.GameMode_MiniGame;
        if (g_GameLogic.gameStatus == 0x28) {
            mode = 7;
        }
        g_Minigame._1A21 = 0;
        for (k = 0; k < 5; k++) {
            if (lbl_3_data_B060[mode][g_Minigame._1A20][k] >= 0) {
                g_Minigame._1A21++;
            }
        }
    }
    if (lbl_8037169C._12 == 0) {
        return;
    }
    if (g_Minigame.battingHandedness[8] != 0) {
        g_Minigame.battingHandedness[8]--;
    } else if (g_Minigame.battingHandedness[7] == 0) {
        if (fn_3_6C938(1, 0x200)) {
            if (g_Minigame._1A3C == 0 || g_GameLogic.gameStatus == 0x28) {
                g_Minigame.battingHandedness[6] = 2;
                sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            }
        } else if ((g_GameLogic._125 >= 8 || g_GameLogic.gameStatus == 0x28) && fn_3_6C938(1, 0x100)) {
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
                if (g_Minigame._1A23 == 0) {
                    g_Minigame.battingHandedness[6] = 1;
                    sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                }
            } else {
                g_Minigame.battingHandedness[6] = 1;
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            }
        } else if (fn_3_6C938(2, 0x20)) {
            g_Minigame.battingHandedness[7] = 1;
            g_Minigame._1A22 = 0;
            g_Minigame.battingHandedness[8] = 30;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && g_d_GameSettings.exhibitionMatchInd != 0) {
            if (fn_3_6C938(2, 8) && g_Minigame._1A23 == 1) {
                g_Minigame._1A23 = 0;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            } else if (fn_3_6C938(2, 4) && g_Minigame._1A23 == 0) {
                g_Minigame._1A23 = 1;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            } else if (g_Minigame._1A23 == 1) {
                if (fn_3_6C938(2, 1)) {
                    if (g_Minigame._1A24[0] == 0) {
                        g_Minigame._1A24[0] = 4;
                    } else {
                        g_Minigame._1A24[0]--;
                    }
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                } else if (fn_3_6C938(2, 2)) {
                    if (g_Minigame._1A24[0] == 4) {
                        g_Minigame._1A24[0] = 0;
                    } else {
                        g_Minigame._1A24[0]++;
                    }
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
            }
        }
    } else if ((g_GameLogic._125 >= 8 || g_GameLogic.gameStatus == 0x28) && fn_3_6C938(0, 0x100)) {
        g_Minigame.battingHandedness[6] = 1;
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    } else if (fn_3_6C938(2, 0x220)) {
        g_Minigame.battingHandedness[7] = 0;
        g_Minigame._1A22 = 0;
        g_Minigame.battingHandedness[8] = 30;
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
    } else if (g_Minigame._1A21 > 1) {
        if (fn_3_6C938(2, 2)) {
            if (g_Minigame.battingHandedness[7] == g_Minigame._1A21) {
                g_Minigame.battingHandedness[7] = 1;
            } else {
                g_Minigame.battingHandedness[7]++;
            }
            g_Minigame._1A22 = 0;
            g_Minigame.battingHandedness[8] = 20;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (fn_3_6C938(2, 1)) {
            if (g_Minigame.battingHandedness[7] == 1) {
                g_Minigame.battingHandedness[7] = g_Minigame._1A21;
            } else {
                g_Minigame.battingHandedness[7]--;
            }
            g_Minigame._1A22 = 1;
            g_Minigame.battingHandedness[8] = 20;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    }
}

// .text:0x0010B200 size:0x7C mapped:0x8074A294
void fn_3_10B200(void) {
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
        lbl_8036E548._3078 = 0;
    }
    fn_80035B50(0xD);
    fn_3_B95EC();
    fn_3_5E60();
    fn_80018B38();
    fn_3_909B0();
    fn_3_9081C();
    fn_80035B50(0x11);
    g_Minigame._19DF = 30;
    fn_3_5A6D4(0x1D);
}

// .text:0x0010AEF0 size:0x310 mapped:0x80749F84
void fn_3_10AEF0(void) {
    int i;

    switch (g_GameLogic._125) {
    case 0:
        fn_800203E0(7, 0);
        g_Minigame._1A40 = 0;
        g_Minigame._19A7 = lbl_3_data_21270[g_Minigame.GameMode_MiniGame];
        g_Minigame._1A3E = 0;
        lbl_8036E548._307E = 1;
        lbl_8036E548._2D8E = 0;
        g_GameLogic._125 = 1;
        if (g_d_GameSettings.exhibitionMatchInd == 0) {
            g_d_GameSettings._36 = g_Minigame.minigameControlStruct._4[g_Minigame._1908];
        }
        break;
    case 1:
        fn_3_10C81C();
        if (g_Minigame._1A0F[0] < 0) {
            fn_3_E1370(lbl_3_data_18918[g_Minigame.GameMode_MiniGame]);
            g_GameLogic._125 = 2;
        }
        break;
    case 2:
        if (fn_80016F7C()) {
            g_GameLogic._125 = 3;
            lbl_3_common_bss_34C58._2C = 0;
        }
        break;
    case 3:
        if (fn_3_90DD8()) {
            g_GameLogic._125 = 5;
        }
        break;
    case 5:
        g_GameLogic._125 = 6;
        break;
    case 6:
        if (lbl_8037169C._12 == 0) {
            return;
        }
        if (g_GameLogic.FrameCountOfCurrentPitch >= lbl_3_data_18C48[2] ||
            (g_GameLogic.FrameCountOfCurrentPitch >= lbl_3_data_18C48[1] && fn_3_6C938(2, 0x1100))) {
            g_GameLogic._125 = 7;
            changeScene(3, 6);
            fn_8003A540(0);
        }
        break;
    case 7:
        if (lbl_8037169C._13 != 0) {
            fn_3_FBD70();
            fn_3_FBD58();
            g_GameLogic._125 = 8;
        }
        break;
    case 8:
        lbl_8036E548._307A = 1;
        g_Minigame._1A38 = 0;
        g_Minigame._1A39 = 0;
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                g_Minigame.minigameControlStruct._14[i] = i;
            }
        }
        if (g_GameLogic.secondaryGameMode == 3) {
            minigamesSetSomePointers();
            minigamesGXStuff();
            g_Minigame._18A6 = 0;
        }
        if (g_Minigame.GameMode_MiniGame == 2) {
            fn_3_5A6D4(0x23);
        } else if (g_Minigame.miniGameNumberOfParticipants >= 2) {
            if (g_GameLogic.secondaryGameMode == 8) {
                fn_3_5A6D4(0x1A);
            } else {
                fn_3_5A6D4(0x23);
            }
        } else {
            fn_3_5A6D4(0x1A);
        }
        break;
    }
    if (g_GameLogic.secondaryGameMode == 3 && g_GameLogic._125 >= 3) {
        fn_3_1128EC();
    }
}

// .text:0x0010AE18 size:0xD8 mapped:0x80749EAC
void fn_3_10AE18(void) {
    fn_3_10AD48();
    fn_3_5A6D4(0x1A);
}

// .text:0x0010AD48 size:0xD0 mapped:0x80749DDC
void fn_3_10AD48(void) {
    int order[4];
    int i;

    for (i = 0; i < 4; i++) {
        order[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
            order[i] = i;
        }
    }
    fn_3_9E078(order, g_Minigame.miniGameNumberOfParticipants, 0);
    for (i = 0; i < 4; i++) {
        g_Minigame.minigameControlStruct._14[i] = order[i];
    }
}

// .text:0x0010A0A0 size:0xCA8 mapped:0x80749134
// 99.41%: registers differ, and the minigame level is incremented from the compared value instead of reloaded
void fn_3_10A0A0(void) {
    struct UnkRecord3448 rec;
    int rank;
    int ok;
    int count;
    u8* level;

    switch (g_GameLogic._125) {
    case 0:
        lbl_3_common_bss_32724._B8 = 0;
        g_Minigame._19A9 = 1;
        g_Minigame._19AA = 0;
        g_Minigame._1A44 = 0;
        g_Minigame._1A45 = 0;
        g_Minigame._1A43 = 0;
        g_Minigame._1A3D = 0;
        if (g_d_GameSettings.exhibitionMatchInd == 0) {
            fn_3_106ED4();
        } else if (g_Minigame.soloMinigameDifficulty == 3 || g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            ok = TRUE;
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
                if (g_Minigame._1908 < 0) {
                    ok = FALSE;
                }
            } else if ((g_Minigame.GameMode_MiniGame == 2 || g_Minigame.GameMode_MiniGame == 4 || g_Minigame.GameMode_MiniGame == 5 ||
                        g_Minigame.GameMode_MiniGame == 6) &&
                       g_Minigame.minigameControlStruct._1C[g_Minigame._1908] > 1) {
                ok = FALSE;
            }
            if (ok) {
                fn_3_109DE0(&rec);
                rank = fn_3_109CE8(&rec);
                if (rank >= 5) {
                    g_Minigame._1A43 = 0;
                } else {
                    g_Minigame._1A43 = rank + 1;
                    g_Minigame._19AA = 1;
                }
            }
        } else if (g_Minigame._1A37 == 1 && g_d_GameSettings.exhibitionMatchInd != 0 && g_Minigame.GameMode_MiniGame >= 1 &&
                   g_Minigame.GameMode_MiniGame <= 6) {
            level = &g_d_GameSettings._13_arr[g_Minigame.GameMode_MiniGame];
            if (*level == g_Minigame.soloMinigameDifficulty) {
                g_Minigame._1A44 = 1;
                (*level)++;
                for (count = 0; count < 6; count++) {
                    if (g_d_GameSettings._13_arr[count + 1] < 3) {
                        break;
                    }
                }
                if (count >= 6) {
                    g_Minigame._1A45 = 2;
                    g_d_GameSettings._12 = 2;
                }
            }
        }
        fn_3_8C07C();
        fn_3_5B368();
        changeScene(1, 6);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125 = 1;
        break;
    case 1:
        g_Minigame._19A9 = 2;
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        if (g_Minigame._1A37 == 0) {
            fn_3_8FC0C();
        }
        g_GameLogic._125 = 2;
        break;
    case 2:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == lbl_3_data_2137C[1]) {
            lbl_3_common_bss_32724._B8 = 1;
        }
        if (g_Minigame._1A44 == 1) {
            if (g_GameLogic.FrameCountOfCurrentPitch > 300) {
                g_GameLogic._125 = 5;
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            }
        } else if (g_Minigame._1A45 != 0) {
            if (g_GameLogic.FrameCountOfCurrentPitch > 300) {
                g_GameLogic._125 = 6;
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            }
        } else if (g_GameLogic.FrameCountOfCurrentPitch > 300) {
            if (g_d_GameSettings.exhibitionMatchInd == 0) {
                if (g_GameLogic.FrameCountOfCurrentPitch > 420) {
                    g_GameLogic._125 = 3;
                }
            } else if (g_Minigame.GameMode_MiniGame == 1 && g_Minigame.soloMinigameDifficulty == 3 && fn_3_6C938(0, 0x10) &&
                       fn_3_6C938(0, 0x800) && fn_3_6C938(0, 0x200)) {
                sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                g_GameLogic._125 = 7;
            } else if (fn_3_6C938(1, 0x1100)) {
                g_GameLogic._125 = 3;
            }
        }
        break;
    case 7:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 30 && fn_3_6C938(1, 0x200)) {
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            g_GameLogic.FrameCountOfCurrentPitch = 270;
            g_GameLogic._125 = 2;
        }
        break;
    case 5:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            count = g_d_GameSettings._13_arr[g_Minigame.GameMode_MiniGame];
            fn_8004CC4C(9, 0, count - 1, 0, count + 140);
            fn_800B0A5C_insertQueue(fn_8004D0F0, 2);
            g_GameLogic.scoreBook_logoFadeDirectionLeft_Right = 0;
            fn_3_90064(0x301);
        } else if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 150) {
            if (fn_3_6C938(1, 0x1100)) {
                fn_8004CC2C();
                g_GameLogic.scoreBook_logoFadeDirectionLeft_Right = 1;
            } else if (g_GameLogic.scoreBook_logoFadeDirectionLeft_Right != 0 && lbl_803C5F74._3 == 4) {
                if (g_Minigame._1A45 != 0) {
                    g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                    g_GameLogic._125 = 6;
                } else {
                    g_GameLogic._125 = 3;
                }
            }
        }
        break;
    case 6:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            fn_8004CC4C(9, 0, 4, 0, 0x91);
            fn_800B0A5C_insertQueue(fn_8004D0F0, 2);
            g_GameLogic.scoreBook_logoFadeDirectionLeft_Right = 0;
        } else if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 150) {
            if (fn_3_6C938(1, 0x1100)) {
                fn_8004CC2C();
                g_GameLogic.scoreBook_logoFadeDirectionLeft_Right = 1;
            } else if (g_GameLogic.scoreBook_logoFadeDirectionLeft_Right != 0 && lbl_803C5F74._3 == 4) {
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                g_GameLogic._125 = 3;
            }
        }
        break;
    case 3:
        if (g_Minigame._1A44 != 0 || g_Minigame._1A45 != 0) {
            if (fn_3_5B220(1)) {
                g_GameLogic._125 = 4;
            }
        } else {
            g_GameLogic._125 = 4;
        }
        break;
    case 4:
        if (g_Minigame._190A != 0) {
            g_GameLogic._125 = 9;
        } else {
            g_GameLogic._125 = 8;
        }
        fn_3_8FC0C();
        break;
    case 8:
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            lbl_3_common_bss_34C90._1D2 = 0;
            if (g_Minigame._1908 >= 0) {
                fn_3_5A6D4(0x24);
            } else {
                fn_3_5A6D4(0x22);
            }
        } else if (g_Minigame.multiPlayerInd == 0 && g_Minigame._1A3C == 0 && g_Minigame.soloMinigameDifficulty == 3) {
            fn_3_5A6D4(0x24);
        } else {
            lbl_3_common_bss_34C90._1D1 = 0;
            lbl_3_common_bss_34C90._1D2 = 0;
            if (g_Minigame._1A3C != 0) {
                fn_3_5A6D4(0x26);
            } else {
                fn_3_5A6D4(0x22);
            }
        }
        break;
    case 9:
        fn_800203E0(12, lbl_3_data_6104[starMissionCompletionTracker._441C]);
        if (lbl_8037169C._13 != 0) {
            g_GameLogic._125 = 10;
        }
        break;
    case 10:
        if (g_Minigame.GameMode_MiniGame == 1 || g_Minigame.GameMode_MiniGame == 3) {
            if (g_Minigame._1A37 != 0) {
                g_d_GameSettings._38 = 1;
            } else {
                g_d_GameSettings._38 = 0;
            }
        } else if (g_Minigame.challenge_minigame_haven_tWonYetIndicator != 0) {
            g_d_GameSettings._38 = 0;
        } else {
            g_d_GameSettings._38 = g_Minigame.minigameControlStruct._1C[g_d_GameSettings._35];
        }
        fn_3_15F998();
        fn_3_147DFC();
        fn_3_11CF84();
        g_GameLogic.framesOfExitingToMenu = 1;
        break;
    }
    fn_3_10A01C();
}

// .text:0x0010A01C size:0x84 mapped:0x807490B0
void fn_3_10A01C(void) {
    if (g_Minigame.GameMode_MiniGame == 1) {
        fn_3_1128E8();
    } else if (g_Minigame.GameMode_MiniGame == 2) {
        fn_3_1160B8();
    } else if (g_Minigame.GameMode_MiniGame == 3) {
        fn_3_1323CC();
    } else if (g_Minigame.GameMode_MiniGame == 4) {
        fn_3_141A2C();
    } else if (g_Minigame.GameMode_MiniGame == 5) {
        fn_3_1471C0();
    } else if (g_Minigame.GameMode_MiniGame == 6) {
        fn_3_13C464();
    }
}

// .text:0x00109DE0 size:0x23C mapped:0x80748E74
void fn_3_109DE0(struct UnkRecord3448* rec) {
    struct UnkStats3448 stats;

    memset(rec, 0, sizeof(struct UnkRecord3448));
    if (g_Minigame._1907 == 1) {
        rec->_06 = inMemRoster[0][g_Minigame.minigameControlStruct.characterIndex[g_Minigame._1908]].stats.CharID;
        if (g_Minigame._1A3C != 0) {
            fn_3_10754C(&stats);
            rec->_00 = fn_8006C13C(&stats);
            rec->_04 = 0;
        } else {
            rec->_00 = g_Minigame.miniGameCurrentPoints[g_Minigame._1908];
            if (rec->_00 > lbl_80109410[g_Minigame.GameMode_MiniGame]) {
                rec->_00 = lbl_80109410[g_Minigame.GameMode_MiniGame];
            }
            switch (g_Minigame.GameMode_MiniGame) {
            case 1:
                rec->_04 = g_Minigame.bOD_HitPowerOfEachChar[g_Minigame._1908];
                if (rec->_04 > 999) {
                    rec->_04 = 999;
                }
                break;
            default:
                rec->_04 = 0;
                break;
            }
        }
    }
}

// .text:0x00109D88 size:0x58 mapped:0x80748E1C
struct UnkRecord3448* fn_3_109D88(void) {
    if (g_Minigame._1A3C != 0) {
        return lbl_803616CC._118;
    }
    if (g_Minigame.GameMode_MiniGame != 0) {
        return lbl_803616CC._028[g_Minigame.GameMode_MiniGame - 1];
    }
    return lbl_803616CC._000;
}

// .text:0x00109CE8 size:0xA0 mapped:0x80748D7C
u32 fn_3_109CE8(struct UnkRecord3448* rec) {
    struct UnkRecord3448* table;
    u32 i;

    if (g_Minigame._1907 == 1) {
        table = fn_3_109D88();
        i = 0;
        do {
            if (rec->_00 > table[i]._00) {
                break;
            }
            if (rec->_00 == table[i]._00 && rec->_04 > table[i]._04) {
                break;
            }
            i++;
        } while (i < 5);
        return i;
    }
}

// .text:0x0010952C size:0x7BC mapped:0x807485C0
void fn_3_10952C(void) {
    struct UnkRecord3448 rec;
    struct UnkRecord3448* table;
    struct UnkStats3448 stats;
    struct UnkStats3448* best;
    u32 rank;
    u32 i;
    int slot;

    g_Minigame._1E03 = 5;
    if (g_Minigame._1907 == 1 &&
        (g_Minigame._1A3C != 0 ||
         (g_Minigame.GameMode_MiniGame != 4 && g_Minigame.GameMode_MiniGame != 5 && g_Minigame.GameMode_MiniGame != 6) ||
         g_Minigame.minigameControlStruct._1C[g_Minigame._1908] == 1)) {
        fn_3_109DE0(&rec);
        rank = fn_3_109CE8(&rec);
        g_Minigame._1E03 = rank;
        if (rank < 5) {
            table = fn_3_109D88();
            for (i = 4; i > rank; i--) {
                memcpy(&table[i], &table[i - 1], sizeof(struct UnkRecord3448));
            }
            memcpy(&table[rank], &rec, sizeof(struct UnkRecord3448));
            g_Minigame._1A43 = rank + 1;
        }
        if (g_Minigame._1A3C != 0) {
            fn_3_10754C(&stats);
            slot = lbl_800E8558[stats._14]._2;
            best = &lbl_803616CC._140[slot];
            if (fn_8006C13C(&stats) > fn_8006C13C(best)) {
                fn_3_10754C(best);
                g_Minigame._1A46[0] = 1;
            } else if (fn_8006C13C(&stats) == fn_8006C13C(best) && stats._12 < best->_12) {
                fn_3_10754C(best);
                g_Minigame._1A46[0] = 1;
            }
            if (3 - lbl_803616CC._400[slot] > stats._12) {
                lbl_803616CC._400[slot] = 3 - stats._12;
                g_Minigame._1A46[0] = 1;
            }
        }
    }
}

// .text:0x00109254 size:0x2D8 mapped:0x807482E8
void fn_3_109254(void) {
    InputStruct* input = &g_Controls[lbl_80366158._27];

    switch (g_GameLogic._125) {
    case 0:
        fn_3_5B368();
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        if (g_Minigame._1907 == 1) {
            fn_3_10952C();
            if (g_Minigame._1A3C != 0) {
                g_GameLogic._125 = 1;
            } else {
                g_GameLogic._125 = 5;
            }
        } else {
            g_GameLogic._125 = 5;
        }
        break;
    case 1:
        if (((UnkTask31A0*)g_Minigame._1E04)->_18 != 0) {
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 30;
            g_GameLogic._125 = 2;
        }
        break;
    case 2:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy >= 30) {
            if ((input->buttonInput & 0x10) && (input->buttonInput & 0x800) && (input->buttonInput & 0x200)) {
                sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                g_GameLogic._125 = 3;
            } else if (input->newButtonInput & 0x1100) {
                ((UnkTask31A0*)g_Minigame._1E04)->_1A = 1;
                g_GameLogic._125 = 4;
            }
        }
        break;
    case 3:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 30 && (input->newButtonInput & 0x200)) {
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            g_GameLogic._125 = 2;
        }
        break;
    case 4:
        if (g_Minigame._1E04 == NULL) {
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            g_GameLogic._125 = 5;
        }
        break;
    case 5:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 20) {
            g_GameLogic._125 = 6;
        }
        break;
    case 6:
        if (input->newButtonInput & 0x1100) {
            g_GameLogic._125 = 7;
        }
        break;
    case 7:
        if (g_Minigame._1A44 != 0 || g_Minigame._1A45 != 0 || g_Minigame._1A43 != 0 || g_Minigame._1A46[0] != 0) {
            if (fn_3_5B220(1)) {
                g_GameLogic._125 = 8;
                g_Minigame._1A46[0] = 0;
            }
        } else {
            g_GameLogic._125 = 8;
        }
        break;
    case 8:
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125 = 9;
        break;
    case 9:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 20) {
            g_GameLogic._125 = 10;
        }
        break;
    case 10:
        lbl_3_common_bss_34C90._1D1 = 0;
        lbl_3_common_bss_34C90._1D2 = 0;
        fn_3_5A6D4(0x22);
        break;
    }
}

// .text:0x00108C54 size:0x600 mapped:0x80747CE8
void fn_3_108C54(void) {
    CharacterStats* stats;
    s8 player;
    int i;

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
        if (g_Minigame.multiPlayerInd != 0 || g_d_GameSettings._13_arr[g_Minigame.GameMode_MiniGame] == 0) {
            lbl_3_common_bss_34C90._1D0 = 12;
        } else if (g_Minigame._1A44 != 0) {
            lbl_3_common_bss_34C90._1D0 = 11;
        } else {
            lbl_3_common_bss_34C90._1D0 = 10;
        }
        if (g_Minigame._1A3C != 0) {
            if (g_Minigame._1E2A >= 6) {
                lbl_3_common_bss_34C90._1D0 = 15;
            } else {
                lbl_3_common_bss_34C90._1D0 = 14;
            }
        }
        lbl_3_common_bss_34C90._00A = 0;
        lbl_3_common_bss_34C90._00C = 0;
        lbl_3_common_bss_34C90._1DA = 0;
        lbl_3_common_bss_34C90._1D2 = 1;
        break;
    case 1:
        lbl_3_common_bss_34C90._00C = 0;
        lbl_3_common_bss_34C90._1D2 = 2;
        break;
    case 2:
        if (lbl_3_common_bss_34C90._00C >= 20) {
            lbl_3_common_bss_34C90._1D2 = 3;
        }
        break;
    case 3:
        fn_3_1089E8();
        lbl_3_common_bss_34C90._00C = 0;
        lbl_3_common_bss_34C90._012 = 0;
        break;
    case 6:
        changeScene(3, 6);
        if (lbl_8037169C._13 != 0) {
            lbl_3_common_bss_34C90._1D2 = 7;
        }
        break;
    case 7:
        if (g_Minigame._1A3C != 0) {
            if (g_Minigame._1E2A >= 6) {
                if (lbl_3_common_bss_34C90._1DA == 0) {
                    g_Minigame._1A38 = 1;
                    fn_3_1078F8();
                    fn_3_5A6D4(0x29);
                } else if (lbl_3_common_bss_34C90._1DA == 1) {
                    g_Minigame._19DF = 30;
                    fn_3_5A6D4(0x1D);
                } else {
                    g_Minigame._19DF = 28;
                    fn_3_5A6D4(0x1D);
                }
                fn_3_FBD70();
                fn_3_FBD58();
            } else if (lbl_3_common_bss_34C90._1DA == 0) {
                fn_3_5A6D4(0x29);
            } else {
                fn_3_5A6D4(0x1D);
            }
        } else {
            switch (lbl_3_data_188FC[lbl_3_common_bss_34C90._1D0 - 10][lbl_3_common_bss_34C90._1DA]) {
            case 0:
                g_Minigame._1A38 = 1;
                fn_3_5A6D4(4);
                break;
            case 1:
                g_Minigame._19DF = 30;
                fn_3_5A6D4(0x1D);
                break;
            case 2:
                g_Minigame._19DF = 30;
                g_Minigame._19E0 = 1;
                fn_3_5A6D4(0x1D);
                break;
            case 3:
                g_Minigame._19DF = 28;
                fn_3_5A6D4(0x1D);
                break;
            case 5:
                g_Minigame._1A38 = 1;
                g_Minigame.soloMinigameDifficulty++;
                g_Minigame._1A39 = 1;
                fn_3_5A6D4(0x21);
                break;
            }
        }
        fn_3_11CF84();
        if (g_Minigame._1A39 != 0) {
            fn_3_10BE7C();
            g_Minigame.miniGameNumberOfParticipants = lbl_3_data_18920[g_Minigame.GameMode_MiniGame][g_Minigame.soloMinigameDifficulty];
            for (i = 0; i < 4; i++) {
                if (g_Minigame.minigameControlStruct.battingHandedness[i] != 0) {
                    if (g_Minigame.miniGameNumberOfParticipants == 1) {
                        g_Minigame.minigameControlStruct.characterIndex[i] = -1;
                    } else {
                        player = g_Minigame.minigameControlStruct.characterIndex[i];
                        stats = &lbl_8034E9A0[g_Minigame._19E8[player]._0];
                        memcpy(&inMemRoster[0][player], stats, sizeof(CharacterStats));
                        g_Minigame.battingHandedness[i] = stats->stats.BattingStance + stats->stats.FieldingArm * 2;
                        g_Minigame.minigameControlStruct._4[i] =
                            inMemRoster[0][g_Minigame.minigameControlStruct.characterIndex[i]].stats.CharID;
                    }
                }
            }
        }
        g_Minigame._1A40 = 1;
        g_Minigame._19A9 = 0;
        fn_3_15F998();
        fn_3_147DFC();
        lbl_8036E548._307A = 0;
        lbl_3_common_bss_34C90._1D9 = 2;
        break;
    case 8:
        switch (fn_3_5B380(g_Controls[lbl_3_common_bss_34C90._000].newButtonInput)) {
        case 1:
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            lbl_3_common_bss_34C90._1D2 = 9;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 3;
            break;
        }
        break;
    case 9:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
            changeScene(4, 6);
        }
        if (lbl_8037169C._13 != 0) {
            g_Minigame._1A40 = 1;
            lbl_3_common_bss_34C90._1D9 = 2;
            fn_3_15F998();
            fn_3_147DFC();
            fn_3_11CF84();
            fn_8004CC18();
            g_GameLogic.framesOfExitingToMenu = 1;
        }
        break;
    }
}

// .text:0x001089E8 size:0x26C mapped:0x80747A7C
void fn_3_1089E8(void) {
    int count = 5;
    int menu = lbl_3_common_bss_34C90._1D0 - 10;
    int player;

    if (g_Minigame._1A3C != 0) {
        if (g_Minigame._1E2A >= 6) {
            count = 4;
        } else {
            count = 3;
        }
    } else if (lbl_3_common_bss_34C90._1D0 == 12) {
        count = 4;
    }
    if ((player = fn_3_6C938(1, 0x100)) != 0) {
        if (g_Minigame._1A3C != 0) {
            if (g_Minigame._1E2A >= 6) {
                if (lbl_3_common_bss_34C90._1DA == 3) {
                    lbl_3_common_bss_34C90._1D2 = 8;
                } else if (lbl_3_common_bss_34C90._1DA == 1) {
                    lbl_3_common_bss_34C90._1D2 = 6;
                } else {
                    lbl_3_common_bss_34C90._1D2 = 6;
                }
            } else if (lbl_3_common_bss_34C90._1DA == 2) {
                lbl_3_common_bss_34C90._1D2 = 8;
            } else {
                lbl_3_common_bss_34C90._1D2 = 6;
            }
        } else {
            switch (lbl_3_data_188FC[menu][lbl_3_common_bss_34C90._1DA]) {
            case 4:
                lbl_3_common_bss_34C90._1D2 = 8;
                break;
            default:
                lbl_3_common_bss_34C90._1D2 = 6;
                break;
            }
        }
        lbl_3_common_bss_34C90._000 = player - 1;
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        if (lbl_3_common_bss_34C90._1D2 == 8) {
            fn_3_5B408();
        }
    } else if (fn_3_6C938(2, 8)) {
        if (lbl_3_common_bss_34C90._1DA == 0) {
            lbl_3_common_bss_34C90._1DA = count - 1;
        } else {
            lbl_3_common_bss_34C90._1DA--;
        }
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    } else if (fn_3_6C938(2, 4)) {
        if (lbl_3_common_bss_34C90._1DA < count - 1) {
            lbl_3_common_bss_34C90._1DA++;
        } else {
            lbl_3_common_bss_34C90._1DA = 0;
        }
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    }
}

// .text:0x00108854 size:0x194 mapped:0x807478E8
int fn_3_108854(void) {
    int i;

    if (g_Minigame.turnOverStatus != 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0 && g_Minigame.minigameControlStruct.battingHandedness[i] == 0 &&
            (g_Controls[g_Minigame.minigameControlStruct.characterIndex[i]].newButtonInput & 0x1000)) {
            goto found;
        }
    }
    return 0;
found:
    g_Minigame.pauseInd = 1;
    lbl_3_common_bss_34C90._000 = g_Minigame.minigameControlStruct.characterIndex[i];
    lbl_3_common_bss_34C90._00A = 0;
    if (g_d_GameSettings.exhibitionMatchInd == 0) {
        lbl_3_common_bss_34C90._1D0 = 16;
    } else if (g_Minigame._1A3C != 0) {
        lbl_3_common_bss_34C90._1D0 = 13;
    } else {
        lbl_3_common_bss_34C90._1D0 = 9;
    }
    lbl_3_common_bss_34C90._1D2 = 0;
    lbl_3_common_bss_34C90._1DA = 0;
    return 1;
}

// .text:0x001084B4 size:0x3A0 mapped:0x80747548
// 99.96%: the lbl_3_data_6104 entry is loaded into r4 instead of r0 before its extsb
void fn_3_1084B4(void) {
    lbl_80366158._28 = 1;
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
        lbl_3_common_bss_34C90._00C = 0;
        lbl_3_common_bss_34C90._1D2 = 1;
        break;
    case 1:
        lbl_3_common_bss_34C90._1D2 = 3;
        break;
    case 2:
        if (lbl_3_common_bss_34C90._00C > 20) {
            lbl_3_common_bss_34C90._1D2 = 3;
        }
        break;
    case 3:
        fn_3_108230();
        lbl_3_common_bss_34C90._00C = 0;
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D4 = 0;
        break;
    case 4:
        lbl_3_common_bss_34C90._1D9 = 1;
        lbl_3_common_bss_34C90._1D2 = 5;
        break;
    case 5:
        if (lbl_3_common_bss_34C90._1D9 == 3) {
            g_Minigame.pauseInd = 0;
        }
        break;
    case 6:
        changeScene(3, 6);
        if (lbl_8037169C._13 != 0) {
            lbl_3_common_bss_34C90._1D2 = 7;
        }
        break;
    case 7:
        lbl_8036E548._307A = 0;
        g_Minigame._1A40 = 1;
        lbl_3_common_bss_34C90._1D9 = 2;
        g_Minigame.pauseInd = 0;
        fn_3_6AB30();
        fn_3_11CF84();
        g_Minigame._19DF = 28;
        fn_3_5A6D4(0x1D);
        break;
    case 8:
        switch (fn_3_5B380(g_Controls[lbl_3_common_bss_34C90._000].newButtonInput)) {
        case 1:
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            lbl_3_common_bss_34C90._1D2 = 9;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 3;
            break;
        }
        break;
    case 9:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
            if (g_d_GameSettings.exhibitionMatchInd == 0) {
                fn_800203E0(12, lbl_3_data_6104[starMissionCompletionTracker._441C]);
            } else {
                changeScene(4, 6);
            }
        }
        if (lbl_8037169C._13 != 0) {
            g_Minigame._1A40 = 1;
            lbl_3_common_bss_34C90._1D9 = 2;
            g_Minigame.pauseInd = 0;
            g_d_GameSettings._13 = 1;
            fn_3_11CF84();
            fn_8004CC18();
            g_GameLogic.framesOfExitingToMenu = 1;
        }
        break;
    case 10:
        fn_3_107E80();
        break;
    case 11:
        fn_3_107E80();
        break;
    case 12:
        changeScene(3, 6);
        if (lbl_8037169C._13 != 0) {
            lbl_3_common_bss_34C90._1D2 = 13;
        }
        break;
    case 13:
        g_Minigame._1A38 = 1;
        fn_3_11CF84();
        lbl_8036E548._307A = 0;
        fn_3_6AB30();
        g_Minigame._1A40 = 1;
        lbl_3_common_bss_34C90._1D9 = 2;
        g_Minigame.pauseInd = 0;
        fn_3_5A6D4(4);
        break;
    }
}

// .text:0x00108230 size:0x284 mapped:0x807472C4
void fn_3_108230(void) {
    InputStruct* input;
    int menu = 0;
    int count = 6;

    input = &g_Controls[lbl_3_common_bss_34C90._000];
    if (g_d_GameSettings.exhibitionMatchInd == 0) {
        menu = 2;
        count = 4;
    } else if (g_Minigame._1A3C != 0) {
        menu = 1;
        count = 5;
    }
    if (input->newButtonInput & 0x1000) {
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        lbl_3_common_bss_34C90._1D2 = 4;
    } else if (input->newButtonInput & 0x100) {
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        switch (lbl_3_data_188E8[menu][lbl_3_common_bss_34C90._1DA]) {
        case 0:
            lbl_3_common_bss_34C90._1D2 = 4;
            break;
        case 1:
            lbl_3_common_bss_34C90._1D2 = 12;
            break;
        case 3:
            lbl_3_common_bss_34C90._1D2 = 10;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 11;
            break;
        case 4:
            lbl_3_common_bss_34C90._1D2 = 6;
            break;
        case 5:
            fn_3_5B408();
            lbl_3_common_bss_34C90._1D2 = 8;
            break;
        }
    } else if (input->newButtonInput & 0x200) {
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        if (lbl_3_common_bss_34C90._1DA != 0) {
            lbl_3_common_bss_34C90._1DA = 0;
        } else {
            lbl_3_common_bss_34C90._1D2 = 4;
        }
    } else if (input->_08 & 8) {
        if (lbl_3_common_bss_34C90._1DA == 0) {
            lbl_3_common_bss_34C90._1DA = count - 1;
        } else {
            lbl_3_common_bss_34C90._1DA--;
        }
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    } else if (input->_08 & 4) {
        lbl_3_common_bss_34C90._1DA++;
        if (lbl_3_common_bss_34C90._1DA >= count) {
            lbl_3_common_bss_34C90._1DA = 0;
        }
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    }
}

// .text:0x00107E80 size:0x3B0 mapped:0x80746F14
void fn_3_107E80(void) {
    InputStruct* input = &g_Controls[lbl_3_common_bss_34C90._000];
    int mode;
    int k;

    switch (lbl_3_common_bss_34C90._1D4) {
    case 0:
        if (lbl_3_common_bss_34C90._1D2 == 11 || g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            g_Minigame.battingHandedness[7] = 1;
            g_Minigame.battingHandedness[8] = 0;
            g_Minigame._1A20 = 0;
            g_Minigame._1A22 = 0;
            if (g_Minigame.multiPlayerInd != 0) {
                g_Minigame._1A20 = 2;
            } else if (g_Minigame.soloMinigameDifficulty == 3) {
                g_Minigame._1A20 = 1;
            }
            mode = g_Minigame.GameMode_MiniGame;
            if (g_GameLogic.gameStatus == 0x28) {
                mode = 7;
            }
            g_Minigame._1A21 = 0;
            for (k = 0; k < 5; k++) {
                if (lbl_3_data_B060[mode][g_Minigame._1A20][k] >= 0) {
                    g_Minigame._1A21++;
                }
            }
        }
        lbl_3_common_bss_34C90._1D9 = 1;
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D4 = 1;
        break;
    case 1:
        if (lbl_3_common_bss_34C90._1D9 == 3) {
            lbl_3_common_bss_34C90._1D4 = 2;
        }
        break;
    case 2:
        lbl_3_common_bss_34C90._1D4 = 3;
        break;
    case 3:
        if (lbl_3_common_bss_34C90._012 > 20) {
            lbl_3_common_bss_34C90._1D4 = 4;
        }
        break;
    case 4:
        if (lbl_3_common_bss_32724._C4 == 0) {
            if (input->newButtonInput & 0x200) {
                sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                lbl_3_common_bss_34C90._012 = 0;
                lbl_3_common_bss_34C90._1D4 = 5;
            } else if (lbl_3_common_bss_34C90._1D2 == 11 ||
                       (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && g_GameLogic.gameStatus == 0xB)) {
                if (input->_08 & 2) {
                    if (g_Minigame.battingHandedness[7] == g_Minigame._1A21) {
                        g_Minigame.battingHandedness[7] = 1;
                    } else {
                        g_Minigame.battingHandedness[7]++;
                    }
                    g_Minigame._1A22 = 0;
                    g_Minigame.battingHandedness[8] = 20;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                } else if (input->_08 & 1) {
                    if (g_Minigame.battingHandedness[7] == 1) {
                        g_Minigame.battingHandedness[7] = g_Minigame._1A21;
                    } else {
                        g_Minigame.battingHandedness[7]--;
                    }
                    g_Minigame._1A22 = 1;
                    g_Minigame.battingHandedness[8] = 20;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
            }
        }
        break;
    case 5:
        if (lbl_3_common_bss_34C90._012 > 20) {
            lbl_3_common_bss_34C90._00C = 0;
            lbl_3_common_bss_34C90._1D2 = 1;
        }
        break;
    }
}

// .text:0x00107E3C size:0x44 mapped:0x80746ED0
u32 minigame_checkIfAIInputIs_Algorithmic_Or_ControllerBased(s8 port) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES && port >= 0 && port < 4) {
        return g_Minigame._1DBC[port];
    }
    return 0;
}

// .text:0x00107DF8 size:0x44 mapped:0x80746E8C
u32 fn_3_107DF8(s8 port) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES && port >= 0 && port < 4) {
        return g_Minigame._1DBC[port + 4];
    }
    return 0;
}

// .text:0x00107DB4 size:0x44 mapped:0x80746E48
u32 fn_3_107DB4(s8 port) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES && port >= 0 && port < 4) {
        return g_Minigame._1DC4[port];
    }
    return 0;
}

// .text:0x00107D70 size:0x44 mapped:0x80746E04
u32 fn_3_107D70(s8 port) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES && port >= 0 && port < 4) {
        return g_Minigame._1DC8[port];
    }
    return 0;
}

// .text:0x00107D34 size:0x3C mapped:0x80746DC8
int fn_3_107D34(const void* a, const void* b) {
    u8 j = *(u8*)b;
    u8 i = *(u8*)a;

    if (g_Minigame.minigamePoints_current_Latest[j][0] != g_Minigame.minigamePoints_current_Latest[i][0]) {
        return g_Minigame.minigamePoints_current_Latest[j][0] - g_Minigame.minigamePoints_current_Latest[i][0];
    }
    return i - j;
}

// .text:0x00107CD0 size:0x64 mapped:0x80746D64
s32 fn_3_107CD0(void) {
    u8 order[4];
    u32 i;

    i = 0;
    do {
        order[i] = i;
        i++;
    } while (i < g_Minigame.miniGameNumberOfParticipants);
    fn_800246D4(fn_3_107D34, order, order, 1, g_Minigame.miniGameNumberOfParticipants);
    return order[0];
}

// .text:0x00107C88 size:0x48 mapped:0x80746D1C
u32 fn_3_107C88(void) {
    u32 i;

    for (i = 1; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        if (g_Minigame.minigamePoints_current_Latest[i][0] != g_Minigame.minigamePoints_current_Latest[0][0]) {
            return FALSE;
        }
    }
    return TRUE;
}

// .text:0x00107C40 size:0x48 mapped:0x80746CD4
u32 fn_3_107C40(void) {
    u32 i;

    for (i = 1; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        if (g_Minigame.miniGameCurrentPoints[i] != g_Minigame.miniGameCurrentPoints[0]) {
            return FALSE;
        }
    }
    return TRUE;
}

// .text:0x00107C04 size:0x3C mapped:0x80746C98
int fn_3_107C04(const void* a, const void* b) {
    u8 j = *(u8*)b;
    u8 i = *(u8*)a;

    if (g_Minigame.miniGameCurrentPoints[j] != g_Minigame.miniGameCurrentPoints[i]) {
        return g_Minigame.miniGameCurrentPoints[j] - g_Minigame.miniGameCurrentPoints[i];
    }
    return i - j;
}

// .text:0x00107BD0 size:0x34 mapped:0x80746C64
int fn_3_107BD0(const void* a, const void* b) {
    u8 j = *(u8*)b;
    u8 i = *(u8*)a;

    if (g_Minigame._1E22[j] != g_Minigame._1E22[i]) {
        return g_Minigame._1E22[j] - g_Minigame._1E22[i];
    }
    return i - j;
}

// .text:0x00107B9C size:0x34 mapped:0x80746C30
int fn_3_107B9C(const void* a, const void* b) {
    u8 j = *(u8*)b;
    u8 i = *(u8*)a;

    if (g_Minigame._1E26[j] != g_Minigame._1E26[i]) {
        return g_Minigame._1E26[j] - g_Minigame._1E26[i];
    }
    return i - j;
}

// .text:0x001079C8 size:0x1D4 mapped:0x80746A5C
void fn_3_1079C8(struct UnkRank31A0* out, int mode) {
    u8 order[4];
    s16 scores[4];
    u32 i;

    i = 0;
    do {
        order[i] = i;
        i++;
    } while (i < g_Minigame.miniGameNumberOfParticipants);
    switch (mode) {
    case 0:
    default:
        fn_800246D4(fn_3_107C04, order, order, 1, g_Minigame.miniGameNumberOfParticipants);
        i = 0;
        do {
            scores[i] = g_Minigame.miniGameCurrentPoints[i];
            i++;
        } while (i < g_Minigame.miniGameNumberOfParticipants);
        break;
    case 1:
        fn_800246D4(fn_3_107BD0, order, order, 1, g_Minigame.miniGameNumberOfParticipants);
        i = 0;
        do {
            scores[i] = g_Minigame._1E22[i];
            i++;
        } while (i < g_Minigame.miniGameNumberOfParticipants);
        break;
    case 2:
        fn_800246D4(fn_3_107B9C, order, order, 1, g_Minigame.miniGameNumberOfParticipants);
        i = 0;
        do {
            scores[i] = g_Minigame._1E26[i];
            i++;
        } while (i < g_Minigame.miniGameNumberOfParticipants);
        break;
    }
    out[0].id = order[0];
    out[0].rank = 0;
    for (i = 1; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        out[i].id = order[i];
        if (scores[order[i]] == scores[order[i - 1]]) {
            out[i].rank = out[i - 1].rank;
        } else {
            out[i].rank = i;
        }
    }
}

// .text:0x00107988 size:0x40 mapped:0x80746A1C
BOOL fn_3_107988(u32 id) {
    u32 i;

    for (i = 0; i < g_Minigame._1E2A - 1; i++) {
        if (g_Minigame._1E1C[i] == id) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x001078F8 size:0x90 mapped:0x8074698C
void fn_3_1078F8(void) {
    u32 i;

    memset(&g_Minigame._1E04, 0, 0x28);
    g_Minigame._1A3D = 0;
    g_Minigame._1A3F = 0;
    lbl_8036E548._307E = 0;
    i = 0;
    do {
        g_Minigame._1E1C[i] = i + 1;
    } while (++i < 6);
    fn_3_9DC18(g_Minigame._1E1C, 6, 0);
    fn_3_5A6D4(0x28);
}

// .text:0x00107784 size:0x174 mapped:0x80746818
void fn_3_107784(void) {
    switch (g_GameLogic._125) {
    case 0:
        g_GameLogic._125++;
        g_Minigame.battingHandedness[7] = 0;
        if (g_Minigame.battingHandedness[5] == 0) {
            fn_800B0A5C_insertQueue(fn_80062A94, 1);
        }
        break;
    case 1:
        changeScene(1, 6);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125++;
        break;
    case 2:
        fn_3_10B27C();
        if (g_Minigame.battingHandedness[6] == 2) {
            g_GameLogic._125 = 5;
        } else if (g_Minigame.battingHandedness[6] != 0) {
            g_GameLogic._125++;
        }
        break;
    case 3:
        changeScene(3, 6);
        if (lbl_8037169C._13 != 0) {
            g_GameLogic._125++;
        }
        break;
    case 4:
        fn_80062A74();
        g_Minigame.battingHandedness[5] = 0;
        fn_3_5A6D4(0x29);
        break;
    case 5:
        changeScene(3, 6);
        if (lbl_8037169C._13 != 0) {
            g_GameLogic._125 = 6;
        }
        break;
    case 6:
        fn_3_5A6D4(0x1E);
        break;
    }
}

// .text:0x0010768C size:0xF8 mapped:0x80746720
void fn_3_10768C(void) {
    switch (g_GameLogic._125) {
    case 0:
        g_Minigame.GameMode_MiniGame = g_Minigame._1E1C[g_Minigame._1E2A++];
        changeScene(1, 6);
        g_GameLogic._125 = 1;
        break;
    case 1:
        if (((UnkTask31A0*)g_Minigame._1E04)->_1A != 0) {
            changeScene(3, 6);
            g_GameLogic._125 = 2;
        }
        break;
    case 2:
        if (lbl_8037169C._13 != 0) {
            g_GameLogic._125 = 3;
        }
        break;
    case 3:
        g_GameLogic._125 = 4;
        break;
    case 4:
        fn_3_5A6D4(0x21);
        break;
    }
}

// .text:0x0010754C size:0x140 mapped:0x807465E0
void fn_3_10754C(struct UnkStats3448* stats) {
    UnkRank31A0 ranks[4];
    u32 i;

    fn_8006C398(stats);
    if (g_Minigame._1A3C != 0 && g_Minigame._1908 >= 0 && g_Minigame._1908 < 4) {
        i = 0;
        do {
            stats->_00[i] = g_Minigame._1E10[i];
        } while (++i < 6);
        i = 0;
        do {
            stats->_0C[i] = g_Minigame._1E1C[i];
        } while (++i < 6);
        fn_3_1079C8(ranks, 1);
        i = 0;
        do {
            if (g_Minigame._1908 == ranks[i].id) {
                stats->_12 = ranks[i].rank;
            }
        } while (++i < g_Minigame.miniGameNumberOfParticipants);
        stats->_13 = g_Minigame._1E22[g_Minigame._1908];
        stats->_14 = inMemRoster[0][g_Minigame.minigameControlStruct.characterIndex[g_Minigame._1908]].stats.CharID;
    }
}

// .text:0x0010722C size:0x320 mapped:0x807462C0
void fn_3_10722C(void) {
    UnkRank31A0 ranks[4];
    u32 i;
    u32 j;

    switch (g_GameLogic._125) {
    case 0:
        i = 0;
        do {
            g_Minigame._1E26[i] = g_Minigame._1E22[i];
            i++;
        } while (i < g_Minigame.miniGameNumberOfParticipants);
        fn_3_1079C8(ranks, 0);
        i = 0;
        do {
            g_Minigame._1E22[ranks[i].id] += lbl_3_data_21EC4[ranks[i].rank] * (g_Minigame._1E2A >= 6 ? 2 : 1);
            i++;
        } while (i < g_Minigame.miniGameNumberOfParticipants);
        fn_3_1079C8((struct UnkRank31A0*)g_Minigame._1E08, 1);
        if (g_Minigame._1907 == 1) {
            g_Minigame._1E10[g_Minigame.GameMode_MiniGame - 1] = g_Minigame.miniGameCurrentPoints[g_Minigame._1908];
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (i == g_Minigame._1E08[j][0]) {
                    g_Minigame.minigameControlStruct._1C[i] = g_Minigame._1E08[j][1] + 1;
                }
            }
        }
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125 = 1;
        break;
    case 1:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 120) {
            g_GameLogic._125 = 2;
        }
        break;
    case 2:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 1800 || fn_3_6C938(1, 0x1100) != 0) {
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            g_GameLogic._125 = 3;
        }
        break;
    case 3:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 120) {
            g_GameLogic._125 = 4;
        }
        break;
    case 4:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 1800 || fn_3_6C938(1, 0x1100) != 0) {
            g_GameLogic._125 = 5;
        }
        break;
    case 5:
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125 = 6;
        if (g_Minigame._1E2A >= 6) {
            changeScene(3, 6);
        }
        break;
    case 6:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
            g_GameLogic._125 = 7;
        }
        break;
    case 7:
        if (g_Minigame._1E2A >= 6) {
            fn_3_15F998();
            fn_3_147DFC();
            lbl_3_common_bss_34C58._31 = 0;
            fn_3_5A6D4(0x27);
        } else {
            lbl_3_common_bss_34C90._1D1 = 0;
            lbl_3_common_bss_34C90._1D2 = 0;
            fn_3_5A6D4(0x22);
        }
        break;
    }
}

// .text:0x001070A4 size:0x188 mapped:0x80746138
void fn_3_1070A4(void) {
    switch (g_GameLogic._125) {
    case 0:
        g_Minigame._1A3D = g_Minigame._1907;
        g_Minigame._1A3E = 1;
        lbl_3_common_bss_32724._B8 = 0;
        if (g_Minigame._1907 == 1) {
            fn_3_107078();
        }
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125 = 1;
        break;
    case 1:
        changeScene(1, 6);
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == lbl_3_data_2137C[1]) {
            lbl_3_common_bss_32724._B8 = 1;
        }
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 300) {
            g_GameLogic._125 = 2;
        }
        break;
    case 2:
        if (fn_3_6C938(1, 0x1100) != 0) {
            g_GameLogic._125 = 6;
        }
        break;
    case 6:
        g_GameLogic._125 = 7;
        break;
    case 7:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
            g_GameLogic._125 = 8;
        }
        break;
    case 8:
        lbl_3_common_bss_34C90._1D1 = 0;
        lbl_3_common_bss_34C90._1D2 = 0;
        if (g_Minigame._19E7 == 1) {
            fn_3_5A6D4(0x24);
        } else {
            fn_3_5A6D4(0x22);
        }
        break;
    }
}

// .text:0x00107078 size:0x2C mapped:0x8074610C
void fn_3_107078(void) {
    if (g_Minigame.minigameControlStruct._1C[g_Minigame._1908] == 1) {
        g_Minigame._1A3F = 1;
    }
}

// .text:0x00106ED4 size:0x1A4 mapped:0x80745F68
void fn_3_106ED4(void) {
    int i;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        if (g_Minigame.challenge_minigame_haven_tWonYetIndicator == 0) {
            if (g_Minigame.minigameControlStruct._1C[g_d_GameSettings._35] == 1) {
                g_d_GameSettings.challengeMinigame_baseCoinsEarned += g_Minigame.miniGameCurrentPoints[g_d_GameSettings._35];
            } else {
                g_d_GameSettings.challengeMinigame_baseCoinsEarned += lbl_3_data_607C[15];
            }
        }
    } else if (g_Minigame.challenge_minigame_haven_tWonYetIndicator != 0) {
        g_d_GameSettings.challengeMinigame_baseCoinsEarned += lbl_3_data_607C[7];
    } else if (g_Minigame.minigameControlStruct._1C[g_d_GameSettings._35] == 1) {
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct._1C[i] > 1) {
                break;
            }
        }
        g_d_GameSettings.challengeMinigame_baseCoinsEarned += lbl_3_data_607C[6];
    } else if (g_d_GameSettings.challengeDifficulty != 0) {
        g_d_GameSettings.challengeMinigame_baseCoinsEarned += lbl_3_data_607C[8];
    }
    for (i = 0; i < 4; i++) {
        g_d_GameSettings._20[i][0] = g_Minigame.miniGameCurrentPoints[i];
        g_d_GameSettings._20[i][1] = g_Minigame.minigameControlStruct._1C[i];
    }
    fn_3_161078();
}

// .text:0x00106EB0 size:0x24 mapped:0x80745F44
void fn_3_106EB0(void) {
    fn_3_90064(0x30B);
}

// .text:0x00106E50 size:0x60 mapped:0x80745EE4
BOOL fn_3_106E50(void) {
    if (lbl_803C6CF8._715 == 1) {
        g_Camera._1B4 = ARAMTransfer(&lbl_3_data_20FDC, 0, 0, 0);
        return TRUE;
    }
    return FALSE;
}

// .text:0x00106DFC size:0x54 mapped:0x80745E90
void fn_3_106DFC(void) {
    g_Camera._AB0 = _OSAllocFromHeap(4, 0x8000);
    g_Camera._146C = _OSAllocFromHeap(4, 0x8000);
}
