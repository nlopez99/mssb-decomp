#include "game/rep_A00.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "stl/math.h"
#include "Dolphin/mtx.h"
#include "game/rep_1838.h"
#include "game/game_batter.h"
#include "game/rep_540.h"
#include "game/rep_868.h"
#include "game/rep_1200.h"
#include "game/rep_13B8.h"
#include "game/rep_1330.h"
#include "game/rep_3880.h"
#include "game/rep_AC8.h"
#include "game/rep_E08.h"
#include "game/m_sound.h"
#include "game/rep_9B0.h"
#include "game/rep_D18.h"

typedef struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ u8 _18[0x1C - 0x18];
    /* 0x1C */ f32 _1C;
    /* 0x20 */ u8 _20[0x28 - 0x20];
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
    /* 0x2A */ u8 _2A[0x2C - 0x2A];
} UnkA00ReplayEntry; // size: 0x2C

typedef struct {
    /* 0x000 */ UnkA00ReplayEntry _000[13];
    /* 0x23C */ s16 _23C;
    /* 0x23E */ s16 _23E;
    /* 0x240 */ s16 _240[13];
    /* 0x25A */ s16 _25A;
    /* 0x25C */ u8 _25C;
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E;
    /* 0x25F */ u8 _25F;
    /* 0x260 */ s8 _260;
    /* 0x261 */ u8 _261[13];
    /* 0x26E */ u8 _26E[13];
    /* 0x27B */ s8 _27B;
    /* 0x27C */ s8 _27C;
    /* 0x27D */ u8 _27D;
    /* 0x27E */ u8 _27E;
    /* 0x27F */ s8 _27F;
    /* 0x280 */ s8 _280;
} UnkA00Replay;

extern struct {
    /* 0x0 */ UnkA00Replay* _0;
} lbl_3_common_bss_1323C;

typedef struct {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ Vec _034;
    /* 0x040 */ u8 _040[0x44 - 0x40];
    /* 0x044 */ f32 _044;
    /* 0x048 */ u8 _048[0x62 - 0x48];
    /* 0x062 */ s16 _062;
    /* 0x064 */ u8 _064[0x68 - 0x64];
    /* 0x068 */ s16 _068;
    /* 0x06A */ s16 _06A;
    /* 0x06C */ u8 _06C[0x25D - 0x6C];
    /* 0x25D */ u8 _25D;
} UnkA00Actor;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ UnkA00Actor* _2C50[13];
} lbl_8036E548;

typedef struct {
    /* 0x000 */ Vec _000;
    /* 0x00C */ u8 _00C[0x48 - 0xC];
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x1C7 - 0x4C];
    /* 0x1C7 */ u8 _1C7;
    /* 0x1C8 */ u8 _1C8[0x218 - 0x1C8];
    /* 0x218 */ u8 _218;
    /* 0x219 */ u8 _219[0x268 - 0x219];
} UnkA00Fielder; // size: 0x268

extern UnkA00Fielder g_Fielders[9];

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ u8 _50[0xA6 - 0x50];
    /* 0xA6 */ s16 _A6;
    /* 0xA8 */ u8 _A8[0xAC - 0xA8];
    /* 0xAC */ u8 _AC;
} ScoresA00;

extern ScoresA00 g_Scores;

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32 _34;
    /* 0x38 */ s32 _38;
    /* 0x3C */ s32 _3C;
} UnkA00Mission; // size: 0x40

typedef struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ s16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
} UnkA00Cue; // size: 0x1C

extern UnkA00Cue lbl_3_data_1E434[];
extern UnkA00Cue lbl_3_data_1F090[];

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x1E - 0x12];
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
    /* 0x22 */ u16 _22;
} UnkA00Task;

extern UnkA00Task* lbl_803CC1B8;

extern struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ s16 _14;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
} lbl_803C5090;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x00 */ u8 _00[0x9A];
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B[0xAE - 0x9B];
    /* 0xAE */ u8 _AE;
    /* 0xAF */ u8 _AF;
    /* 0xB0 */ u8 _B0;
    /* 0xB1 */ u8 _B1;
} lbl_3_common_bss_32724;

typedef struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
    /* 0x42 */ u8 _42[0x46 - 0x42];
    /* 0x46 */ u8 _46;
} UnkA00Bss37400;

extern UnkA00Bss37400 lbl_3_common_bss_37400;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

typedef struct {
    /* 0x0 */ u8 _0[0xD];
    /* 0xD */ s8 _D;
    /* 0xE */ u8 _E;
} UnkA00ChallengeTeam; // size: 0xF

extern UnkA00ChallengeTeam lbl_80109420[];

typedef struct {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3[3];
} UnkA00CharEntry; // size: 0x6

extern UnkA00CharEntry lbl_800E8558[54];
extern s16 lbl_3_data_7F7C[][4];

void changeScene(u8, s16);
void fn_8001D074(s32, BOOL);
void fn_800B0A14_removeQueue(void);
UnkA00Task* fn_800B0A5C_insertQueue(void (*)(void), s32);
void fn_80052798(s32);
BOOL fn_3_6B4C8(void);
BOOL fn_3_6C938(s32, s32);
void fn_3_FBD58(void);
void fn_3_FBD70(void);
BOOL fn_3_165D24(void);
void QueueCharacterAnimation(int actor, int anim, u8, u8, s16, u8, int);
void AnimateCharacter(int actor, int anim, u8, u8, u8, s16, u8, int);

UnkA00Cue lbl_3_data_1D28[18] = {
    { { 0.0f, 0.0f, 15.0f }, 0.0f, 0x2, 0x0, 0, 0, 1, 0, 0, 0 },
    { { 0.0f, 0.0f, -3.0f }, 0.0f, 0x2, 0x0, 1, 0, 1, 0, 0, 0 },
    { { 20.0f, 0.0f, 25.0f }, 0.6f, 0x2, 0x0, 2, 0, 1, 0, 0, 0 },
    { { 12.0f, 0.0f, 40.0f }, 0.0f, 0x2, 0x0, 3, 0, 1, 0, 0, 0 },
    { { -20.0f, 0.0f, 25.0f }, -0.6f, 0x2, 0x0, 4, 0, 1, 0, 0, 0 },
    { { -12.0f, 0.0f, 40.0f }, 0.0f, 0x2, 0x0, 5, 0, 1, 0, 0, 0 },
    { { -40.0f, 0.0f, 67.0f }, 0.0f, 0x2, 0x0, 6, 0, 1, 0, 0, 0 },
    { { 0.0f, 0.0f, 85.0f }, 0.0f, 0x2, 0x0, 7, 0, 1, 0, 0, 0 },
    { { 40.0f, 0.0f, 67.0f }, 0.0f, 0x2, 0x0, 8, 0, 1, 0, 0, 0 },
    { { -0.0f, 0.0f, 0.6f }, -0.85f, 0x3B, 0x0, 9, 2, 1, 0, 0, 0 },
    { { 0.15f, 0.0f, 0.3f }, -0.85f, 0x3C, 0x28, 9, 2, 1, 0, 0, 0 },
    { { 0.1f, 0.0f, 0.5f }, -0.85f, 0x3C, 0x0, 9, 2, 1, 0, 0, 0 },
    { { 0.0f, -0.09f, 16.8f }, 0.0f, 0x45, 0x0, 0, 0, 1, 0, 0, 0 },
    { { 0.0f, -0.09f, 16.8f }, 0.0f, 0x45, 0x0, 0, 0, 1, 0, 0, 0 },
    { { -1.2f, 0.0f, -2.2f }, -2.9f, 0x45, 0x0, 1, 0, 1, 0, 0, 0 },
    { { -1.2f, 0.0f, -2.2f }, -2.9f, 0x45, 0x0, 1, 0, 1, 0, 0, 0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 0x0, 0x0, 0, 0, 0, 0, 0, 0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 0x0, 0x0, 0, 0, 0, 0, 0, 0 },
};
u8 lbl_3_data_1F20[8] = { 0x12, 0x17, 0x0B, 0x0E, 0x0A, 0xFE, 0x00, 0x00 };
u8 lbl_3_data_1F28[8] = { 0x12, 0x18, 0x0B, 0x0E, 0x10, 0xFE, 0x00, 0x00 };
u8 lbl_3_data_1F30[8] = { 0x12, 0x1A, 0x0C, 0x0F, 0x11, 0x02, 0x09, 0xFE };
u8 lbl_3_data_1F38[8] = { 0x12, 0x19, 0x0D, 0x0E, 0x11, 0x04, 0x0A, 0xFE };
u8* lbl_3_data_1F40[4] = { lbl_3_data_1F20, lbl_3_data_1F28, lbl_3_data_1F30, lbl_3_data_1F38 };
static s8 lbl_3_data_1F50[36] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0,
};
s32 lbl_3_data_1F74[33] = {
    0x55, 0x56, 0x57, 0x58, 0x55, 0x56, 0x57, 0x58, 0x59, 0x55, 0x56,
    0x57, 0x58, 0x59, 0x5B, 0x5C, 0x5D, 0x5E, 0x5B, 0x5C, 0x5D, 0x5E,
    0x60, 0x5B, 0x5C, 0x5D, 0x5E, 0x60, 0x60, 0x5A, 0x5A, 0x60, 0x60,
};
s32 lbl_3_data_1FF8[55] = {
    0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F,
    0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F,
    0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F,
    0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F,
    0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F,
};
static s32 lbl_3_data_20D4[55] = {
    0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52,
    0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52,
    0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52,
    0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52,
    0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x52,
};
static s32 lbl_3_data_21B0[55] = {
    0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
    0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
    0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
    0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
    0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
};
static s32 lbl_3_data_228C[55] = {
    0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54,
    0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54,
    0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54,
    0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54,
    0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54,
};
s32 lbl_3_data_2368[6] = {
    0x65, 0x65, 0x65, 0x65, 0x65, 0x65,
};
s32 lbl_3_data_2380[6] = {
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
};
static UnkA00Mission lbl_3_data_2398[33] = {
    { 1, -1, -1, -1, 1, 0, -1, -1, -1, 0, 1, -1, 96, 0, 0, 0 },
    { 1, -1, -1, -1, 0, 1, -1, -1, -1, 0, 1, -1, 97, 0, 0, 0 },
    { 1, -1, -1, 0, 1, 1, -1, -1, -1, 0, 1, -1, 98, 0, 0, 0 },
    { 1, -1, -1, 1, 1, 1, -1, -1, -1, 0, 1, -1, 99, 0, 0, 0 },
    { 2, -1, -1, -1, 1, 0, 1, -1, -1, 0, 1, -1, 96, 0, 0, 0 },
    { 2, -1, -1, -1, 0, 1, 1, -1, -1, 0, 1, -1, 97, 0, 0, 0 },
    { 2, -1, -1, 0, 1, 1, 1, -1, -1, 0, 1, -1, 98, 0, 0, 0 },
    { 2, -1, -1, 1, 1, 1, -1, -1, -1, 0, 1, -1, 99, 0, 0, 0 },
    { 2, -1, -1, -1, 1, -1, -1, -1, 1, 0, 1, 1, 100, 0, 0, 0 },
    { 3, -1, -1, -1, 1, 0, 1, -1, -1, 0, 1, -1, 96, 0, 0, 0 },
    { 3, -1, -1, -1, 0, 1, 1, -1, -1, 0, 1, -1, 97, 0, 0, 0 },
    { 3, -1, -1, 0, 1, 1, 1, -1, -1, 0, 1, -1, 98, 0, 0, 0 },
    { 3, -1, -1, 1, 1, 1, -1, -1, -1, 0, 1, -1, 99, 0, 0, 0 },
    { 3, -1, -1, -1, 1, -1, -1, -1, 1, 0, 1, 1, 100, 0, 0, 0 },
    { 1, -1, -1, -1, 1, 0, -1, -1, -1, 0, 1, 1, 96, 0, 0, 0 },
    { 1, -1, -1, -1, 0, 1, -1, -1, -1, 0, 1, 1, 97, 0, 0, 0 },
    { 1, -1, -1, 0, 1, 1, -1, -1, -1, 0, 1, 1, 98, 0, 0, 0 },
    { 1, -1, -1, 1, 1, 1, -1, -1, -1, 0, 1, 1, 99, 0, 0, 0 },
    { 2, -1, -1, -1, 1, 0, 2, -1, -1, 0, 1, 1, 96, 0, 0, 0 },
    { 2, -1, -1, -1, 0, 1, 2, -1, -1, 0, 1, 1, 97, 0, 0, 0 },
    { 2, -1, -1, 0, 1, 1, 2, -1, -1, 0, 1, 1, 98, 0, 0, 0 },
    { 2, -1, -1, 1, 1, 1, -1, -1, -1, 0, 1, 1, 99, 0, 0, 0 },
    { 2, -1, -1, -1, 1, -1, -1, -1, 1, 0, 1, 1, 100, 0, 0, 0 },
    { 3, -1, -1, -1, 1, 0, 2, -1, -1, 0, 1, 1, 96, 0, 0, 0 },
    { 3, -1, -1, -1, 0, 1, 2, -1, -1, 0, 1, 1, 97, 0, 0, 0 },
    { 3, -1, -1, 0, 1, 1, 2, -1, -1, 0, 1, 1, 98, 0, 0, 0 },
    { 3, -1, -1, 1, 1, 1, -1, -1, -1, 0, 1, 1, 99, 0, 0, 0 },
    { 3, -1, -1, -1, 1, -1, -1, -1, 1, 0, 1, 1, 100, 0, 0, 0 },
    { 1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 100, 0, 0, 0 },
    { 4, -1, 2, -1, -1, -1, -1, 0, -1, 0, 1, 1, 99, 0, 0, 0 },
    { 4, -1, 2, -1, -1, -1, -1, 1, -1, 0, 1, 1, 99, 0, 0, 0 },
    { 4, -1, -1, -1, -1, -1, -1, -1, 1, 0, 1, 1, 100, 0, 0, 0 },
    { 4, -1, -1, -1, -1, -1, -1, -1, 1, 0, 1, 1, 100, 0, 0, 0 },
};
static u8 lbl_3_data_2BD8[55][55] = {
    { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
s32 lbl_3_data_37AC[55] = {
    0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42,
    0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D,
    0x4D, 0x4D, 0x4E, 0x4E, 0x4E, 0x4F, 0x50, 0x45, 0x45, 0x45, 0x45,
    0x51, 0x51, 0x51, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x44, 0x4C,
    0x48, 0x48, 0x48, 0x48, 0x57, 0x57, 0x57, 0x57, 0x4F, 0x4F, 0x1A,
};
s32 lbl_3_data_3888[55] = {
    0x78, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x79,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
};
s32 lbl_3_data_3964[55] = {
    0x78, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x79,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
};
s32 lbl_3_data_3A40[55] = {
    0x78, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x79,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
};
s32 lbl_3_data_3B1C[6] = {
    0x11C, 0x11D, 0x11E, 0x11A, 0x11F, 0x11B,
};
s32 lbl_3_data_3B34[6] = {
    0x11C, 0x11D, 0x11E, 0x11A, 0x11F, 0x11B,
};
s32 lbl_3_data_3B4C[54] = {
    0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x4E, 0x9,
    0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
    0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
    0x9, 0x9, 0x9, 0x9, 0x9, 0x34, 0x9, 0x9, 0x9, 0x9, 0x9,
    0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
};

static int lbl_3_bss_A0[10];
static int lbl_3_bss_9C;
// Nothing reads it, but the target has these 4 bytes ahead of lbl_3_bss_9C
static int lbl_3_bss_98;

// .text:0x000250FC size:0xE8 mapped:0x80664190
void fn_3_250FC(void) {
    s32 i;

    lbl_3_common_bss_1323C._0->_25C = i = 0;
    for (; i < 33; i++) {
        lbl_3_data_2398[i]._34 = 0;
        lbl_3_data_2398[i]._38 = 0;
        lbl_3_data_2398[i]._3C = 0;
    }
    lbl_3_common_bss_1323C._0->_27B = 0;
}

// .text:0x00024F24 size:0x1D8 mapped:0x80663FB8
void fn_3_24F24(int idx) {
    u8* script = lbl_3_data_1F40[idx];
    s32 i;
    int range = 0;
    u8 cue;

    for (i = 0; i < 13; i++) {
        lbl_3_common_bss_1323C._0->_240[i] = -1;
    }
    lbl_3_common_bss_1323C._0->_25C = 1;
    lbl_3_common_bss_1323C._0->_23C = 0;
    lbl_3_common_bss_1323C._0->_27C = 0;
    lbl_3_common_bss_1323C._0->_25D = idx;
    lbl_3_common_bss_1323C._0->_25F = 1;
    lbl_3_common_bss_1323C._0->_27D = 0;
    lbl_3_common_bss_1323C._0->_27E = 0;
    lbl_3_common_bss_1323C._0->_25A = 0;
    lbl_3_common_bss_1323C._0->_280 = 1;
    lbl_3_common_bss_1323C._0->_23E = *script * 10;
    if (*++script == 0xFD) {
        range = 2;
        script++;
    }
    lbl_3_common_bss_1323C._0->_25E = *script++;
    if (range) {
        lbl_3_common_bss_1323C._0->_25E += random_fn_3_9EE24(range);
    }
    for (;;) {
        cue = *script;
        if (cue == 0xFE) {
            break;
        }
        script++;
        lbl_3_common_bss_1323C._0->_240[lbl_3_data_1D28[cue]._14] = cue;
    }
}

// .text:0x00024F20 size:0x4 mapped:0x80663FB4
void fn_3_24F20(void) {
}

// .text:0x00024EA0 size:0x80 mapped:0x80663F34
void fn_3_24EA0(void) {
    int i;

    for (i = 0; i < 13; i++) {
        lbl_3_common_bss_1323C._0->_240[i] = -1;
        memset(&lbl_3_common_bss_1323C._0->_000[i], 0, sizeof(UnkA00ReplayEntry));
        lbl_3_common_bss_1323C._0->_261[i] = 0;
    }
}

// .text:0x00024DBC size:0xE4 mapped:0x80663E50
void fn_3_24DBC(u8 mode) {
    int i;

    for (i = 0; i < 13; i++) {
        lbl_3_common_bss_1323C._0->_240[i] = -1;
        memset(&lbl_3_common_bss_1323C._0->_000[i], 0, sizeof(UnkA00ReplayEntry));
        lbl_3_common_bss_1323C._0->_261[i] = 0;
    }
    fn_3_6714C(FALSE);
    lbl_3_common_bss_1323C._0->_25C = 1;
    lbl_3_common_bss_1323C._0->_23C = 0;
    lbl_3_common_bss_1323C._0->_27C = 0;
    lbl_3_common_bss_1323C._0->_25D = mode;
    lbl_3_common_bss_1323C._0->_25F = 1;
    lbl_3_common_bss_1323C._0->_27D = 0;
    lbl_3_common_bss_1323C._0->_27E = 0;
    lbl_3_common_bss_1323C._0->_25A = 0;
    lbl_3_common_bss_1323C._0->_280 = 1;
}

// .text:0x00024ADC size:0x2E0 mapped:0x80663B70
void fn_3_24ADC(int id, BOOL queue) {
    UnkA00Cue* cue = &lbl_3_data_1E434[id];
    int idx = cue->_14;
    UnkA00Actor* actor;
    InMemRunnerType* runner;
    int flag;

    lbl_3_common_bss_1323C._0->_240[idx] = id;
    if (idx <= 8) {
        actor = lbl_8036E548._2C50[idx];
        if (cue->_19 == 0) {
            memcpy(&g_Fielders[idx]._000, &cue->_00, sizeof(Vec));
            if (actor != NULL) {
                memcpy(&actor->_034, &cue->_00, sizeof(Vec));
            }
        }
        g_Fielders[idx]._048 = lbl_3_common_bss_1323C._0->_000[idx]._0C = cue->_0C;
        if (actor != NULL) {
            actor->_044 = cue->_0C;
            actor->_25D = 1;
        }
        if (cue->_10 >= 0x69 && cue->_10 < 0x75) {
            flag = 0;
        } else {
            flag = g_Fielders[idx]._1C7;
        }
        lbl_3_common_bss_1323C._0->_261[idx] = 1;
        lbl_3_common_bss_1323C._0->_26E[idx] = 1;
    } else if (idx <= 12) {
        actor = lbl_8036E548._2C50[idx];
        if (idx == 10) {
            if (actor == NULL) {
                return;
            }
        } else if (idx == 11) {
            if (actor == NULL) {
                return;
            }
        } else if (idx == 12) {
            if (actor == NULL) {
                return;
            }
        }
        runner = &g_Runners[idx - 9];
        if (cue->_19 == 0) {
            memcpy(&runner->position, &cue->_00, sizeof(Vec));
            if (actor != NULL) {
                memcpy(&actor->_034, &cue->_00, sizeof(Vec));
            }
        }
        runner->runningAngle = lbl_3_common_bss_1323C._0->_000[idx]._0C = cue->_0C;
        if (actor != NULL) {
            actor->_044 = cue->_0C;
            actor->_25D = 1;
        }
        lbl_3_common_bss_1323C._0->_261[idx] = 1;
        lbl_3_common_bss_1323C._0->_26E[idx] = 1;
        if (idx == 9) {
            if (lbl_3_common_bss_1323C._0->_25D == 0 || lbl_3_common_bss_1323C._0->_25D == 1) {
                if (g_Batter.batterHand == BATTING_HAND_LEFT) {
                    flag = 0;
                } else {
                    flag = 1;
                }
            } else {
                flag = 0;
            }
        } else {
            flag = 0;
        }
    }
    if (!queue) {
        AnimateCharacter(idx, cue->_10, cue->_16, cue->_17, cue->_18, cue->_12, flag, 0);
    } else {
        QueueCharacterAnimation(idx, cue->_10, cue->_16, cue->_18, cue->_12, flag, 0);
    }
}

// .text:0x000249E8 size:0xF4 mapped:0x80663A7C
void fn_3_249E8(int id) {
    UnkA00Cue* cue = &lbl_3_data_1F090[id];
    int i;
    u8 slot = cue->_14;

    for (i = 0; i < 9; i++) {
        if (slot == g_Fielders[i]._218) {
            lbl_3_common_bss_1323C._0->_240[i] = id;
            if (cue->_19 == 0) {
                memcpy(&g_Fielders[i]._000, &cue->_00, sizeof(Vec));
            }
            g_Fielders[i]._048 = lbl_3_common_bss_1323C._0->_000[i]._0C = cue->_0C;
            lbl_3_common_bss_1323C._0->_261[i] = 1;
            AnimateCharacter(i, cue->_10, cue->_16, cue->_17, cue->_18, cue->_12, 0, 0);
        }
    }
}

// .text:0x00024708 size:0x2E0 mapped:0x8066379C
void fn_3_24708(void) {
    UnkA00Actor* actor;
    InMemRunnerType* runner;
    int i;
    f32 dist;
    f32 diff;
    Mtx mtx;
    Vec offset;

    for (i = 0; i < 13; i++) {
        actor = lbl_8036E548._2C50[i];
        if (actor == NULL) {
            continue;
        }
        if (lbl_3_common_bss_1323C._0->_000[i]._29 != 1) {
            continue;
        }
        if (lbl_3_common_bss_1323C._0->_27F == 3 && lbl_3_common_bss_1323C._0->_000[i]._1C > actor->_068) {
        } else if (i <= 8) {
            dist = PSVECDistance(&g_Fielders[i]._000, &lbl_3_common_bss_1323C._0->_000[i]._00);
        } else if (i <= 12) {
            runner = &g_Runners[i - 9];
            lbl_3_common_bss_1323C._0->_000[i]._10 =
                atan2(-(lbl_3_common_bss_1323C._0->_000[i]._00.x - runner->position.x),
                      -(lbl_3_common_bss_1323C._0->_000[i]._00.z - runner->position.z));
            PSMTXRotRad(mtx, 'Y', lbl_3_common_bss_1323C._0->_000[i]._0C);
            offset.x = 0.0f;
            offset.y = 0.0f;
            offset.z = lbl_3_common_bss_1323C._0->_000[i]._14;
            PSMTXMultVec(mtx, &offset, &offset);
            runner->position.x -= offset.x;
            runner->position.z -= offset.z;
            diff = fn_3_9FEA8(lbl_3_common_bss_1323C._0->_000[i]._0C - lbl_3_common_bss_1323C._0->_000[i]._10);
            if (!((diff < 0.02 && diff > 0.0f) || (diff > -0.02 && diff < 0.0f))) {
                if (diff < 0.0f) {
                    lbl_3_common_bss_1323C._0->_000[i]._0C += 0.017453292f;
                } else {
                    lbl_3_common_bss_1323C._0->_000[i]._0C -= 0.017453292f;
                }
            }
            runner->runningAngle = lbl_3_common_bss_1323C._0->_000[i]._0C;
            dist = PSVECDistance((Vec*)&runner->position, &lbl_3_common_bss_1323C._0->_000[i]._00);
        }
        if (lbl_3_common_bss_1323C._0->_27F == 3) {
            if (actor->_068 == 0) {
                lbl_3_common_bss_1323C._0->_000[i]._28 = 1;
                lbl_3_common_bss_1323C._0->_000[i]._29 = 0;
            }
        } else if (dist < 3.0f) {
            lbl_3_common_bss_1323C._0->_000[i]._28 = 1;
            lbl_3_common_bss_1323C._0->_000[i]._29 = 0;
        }
    }
}

// .text:0x00024630 size:0xD8 mapped:0x806636C4
void fn_3_24630(void) {
    s32 i;

    fn_80052798(1);
    for (i = 0; i < 13; i++) {
        lbl_3_common_bss_1323C._0->_261[i] = 0;
    }
    lbl_3_common_bss_1323C._0->_25C = 0;
}

// .text:0x00024598 size:0x98 mapped:0x8066362C
void fn_3_24598(void) {
    if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
        lbl_3_common_bss_1323C._0->_23C++;
    } else {
        lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
    }
    if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E - 7) {
        changeScene(3, 6);
    }
    if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
        g_GameLogic._125++;
    }
}

// .text:0x000240F8 size:0x4A0 mapped:0x8066318C
void fn_3_240F8(void) {
    int i;
    GameControlsStruct* logic = &g_GameLogic;
    GameInitVariables* settings = &g_d_GameSettings;
    UnkA00Actor* actor;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            g_pCamera->_AAA = 1;
            g_pCamera->_AAE = 2;
            fn_800B0A5C_insertQueue(fn_3_21DE4, 6);
            logic->_125 = 1;
        }
        break;
    case 1:
        changeScene(1, 6);
        fn_3_24DBC(5);
        if (g_Runners[0].baseStandingOn == 1) {
            fn_3_FBDAC(lbl_3_data_20D4[g_Runners[0].charID]);
        } else if (g_Runners[0].baseStandingOn == 2) {
            fn_3_FBDAC(lbl_3_data_21B0[g_Runners[0].charID]);
        } else if (g_Runners[0].baseStandingOn == 3) {
            fn_3_FBDAC(lbl_3_data_228C[g_Runners[0].charID]);
        } else {
            fn_3_FBDAC(lbl_3_data_20D4[g_Runners[0].charID]);
        }
        logic->_125 = 2;
        break;
    case 2:
        logic->FrameCountOfCurrentAtBat_Copy = 0;
        logic->_125 = 3;
    case 3:
        fn_3_24708();
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 8 &&
            settings->GameModeSelected != GAME_TYPE_DEMO) {
            if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
                lbl_3_common_bss_1323C._0->_27C = 1;
                lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 8;
                changeScene(3, 6);
            }
        } else if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E - 7) {
            changeScene(3, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            logic->_125 = 5;
        }
        for (i = 0; i < 13; i++) {
            if (i == 0 || i == 1 || i == 9) {
                fn_8001D074(i, TRUE);
            } else {
                fn_8001D074(i, FALSE);
            }
        }
        break;
    case 5:
        fn_3_24630();
        fn_3_FBD70();
        fn_3_FBD58();
        fn_3_7C1FC(TRUE);
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        break;
    }
    actor = lbl_8036E548._2C50[9];
    if (actor->_062 == 0x3A &&
        actor->_06A == lbl_3_data_7F7C[lbl_800E8558[g_Batter.charID]._2][2]) {
        fn_3_90220(g_Batter.charID, 0);
    }
}

// .text:0x00023CEC size:0x40C mapped:0x80662D80
void fn_3_23CEC(void) {
    int i;
    GameInitVariables* settings = &g_d_GameSettings;
    GameControlsStruct* logic = &g_GameLogic;
    UnkA00Actor* actor;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            changeScene(1, 6);
            logic->_125 = 1;
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        }
        break;
    case 1:
        fn_3_24DBC(3);
        fn_3_FBDAC(lbl_3_data_1FF8[g_Runners[0].charID]);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        logic->_125 = 2;
        break;
    case 2:
        fn_3_24708();
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 7 &&
            settings->GameModeSelected != GAME_TYPE_DEMO) {
            if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
                lbl_3_common_bss_1323C._0->_27C = 1;
                lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 8;
                changeScene(3, 6);
            }
        } else if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E - 7) {
            changeScene(3, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            logic->_125 = 4;
        }
        for (i = 0; i < 13; i++) {
            if (i == 0 || i == 1 || i == 9) {
                fn_8001D074(i, TRUE);
            } else {
                fn_8001D074(i, FALSE);
            }
        }
        break;
    case 4:
        fn_3_24630();
        fn_3_FBD70();
        fn_3_FBD58();
        fn_3_7C1FC(TRUE);
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        break;
    }
    actor = lbl_8036E548._2C50[9];
    if (actor->_062 == 0x3C &&
        actor->_06A == lbl_3_data_7F7C[lbl_800E8558[g_Batter.charID]._2][0]) {
        fn_3_90220(g_Batter.charID, 0);
    }
}

// .text:0x00023890 size:0x45C mapped:0x80662924
void fn_3_23890(void) {
    int i;
    UnkA00Task* task = lbl_803CC1B8;
    GameControlsStruct* logic = &g_GameLogic;
    GameInitVariables* settings = &g_d_GameSettings;
    UnkA00Task* fade;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            g_pCamera->_AAA = 1;
            g_pCamera->_AAE = 2;
            fn_800B0A5C_insertQueue(fn_3_21DE4, 6);
            logic->_125 = 1;
        }
        break;
    case 1:
        fn_3_24DBC(4);
        fn_3_FBDAC(0x4C);
        logic->_125 = 2;
        break;
    case 2:
        changeScene(1, 6);
        lbl_3_common_bss_1323C._0->_27E = 1;
        fade = fn_800B0A5C_insertQueue(fn_3_21AA8, 4);
        task->_10 = 0;
        fade->_22 = 0;
        fade->_1E = 0;
        logic->_125 = 3;
        break;
    case 3:
        fn_3_24708();
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 31 &&
            settings->GameModeSelected != GAME_TYPE_DEMO && g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60 &&
            lbl_3_common_bss_32724._B1 == 0) {
            lbl_3_common_bss_1323C._0->_27C = 1;
            lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 31;
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E - 31) {
            lbl_3_common_bss_32724._B1 = 1;
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            logic->_125 = 5;
        }
        for (i = 0; i < 13; i++) {
            if (i == 0 || i == 1 || i == 9) {
                fn_8001D074(i, TRUE);
            } else {
                fn_8001D074(i, FALSE);
            }
        }
        break;
    case 4:
        break;
    case 5:
        lbl_3_common_bss_1323C._0->_27E = 0;
        fn_3_24630();
        fn_3_FBD70();
        fn_3_FBD58();
        logic->_125 = 6;
        break;
    case 6:
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        fn_3_8C07C();
        if (lbl_3_common_bss_1323C._0->_27C) {
            fn_3_5A6D4(g_GameLogic.gameStatus_prev);
            g_Stats._39 = 2;
        } else {
            fn_3_5A6D4(g_GameLogic.gameStatus_prev);
            g_Stats._39 = 2;
        }
        break;
    }
}

// .text:0x000234BC size:0x3D4 mapped:0x80662550
void fn_3_234BC(void) {
    int i;
    GameInitVariables* settings = &g_d_GameSettings;
    GameControlsStruct* logic = &g_GameLogic;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            if (g_GameLogic.playOverInd == 0 && !fn_3_21F14()) {
                lbl_3_common_bss_1323C._0->_25C = 0;
                changeScene(1, 6);
                fn_3_FBD58();
                fn_3_5A6D4(0);
            } else {
                fn_3_F1DC();
                fn_3_751B4();
                setDefaultInMemBatter();
                fn_3_8913C();
                fn_3_58870();
                fn_3_1DEB8();
                g_Pitcher.playStartOfGameAnimation = 0;
                g_GameLogic.scoutFlag_VsScreenInd = 1;
                logic->_125 = 1;
            }
        }
        break;
    case 1:
        fn_3_24DBC(0);
        if (g_GameLogic.playOverInd == 1) {
            fn_3_FBDAC(0x6A);
        } else {
            fn_3_FBDAC(lbl_3_data_1F74[lbl_3_common_bss_1323C._0->_260]);
        }
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        logic->_125 = 2;
        break;
    case 2:
        fn_3_24708();
        if (lbl_3_common_bss_1323C._0->_23C == 9) {
            changeScene(1, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 7 &&
            settings->GameModeSelected != GAME_TYPE_DEMO && g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
            lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 8;
            changeScene(3, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            logic->_125 = 3;
        }
        break;
    case 3:
        fn_3_24630();
        fn_3_FBD70();
        fn_3_FBD58();
        fn_3_5A6D4(0);
        break;
    }
}

// .text:0x000230D4 size:0x3E8 mapped:0x80662168
void fn_3_230D4(void) {
    int i;
    GameInitVariables* settings = &g_d_GameSettings;
    GameControlsStruct* logic = &g_GameLogic;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            changeScene(1, 6);
            fn_3_24630();
            fn_3_FBD70();
            fn_3_FBD58();
            fn_3_5A6D4(0);
        }
        break;
    case 1:
        changeScene(1, 6);
        fn_3_24DBC(1);
        fn_3_FBDAC(0x6B);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        logic->_125 = 2;
        break;
    case 2:
        if (lbl_3_common_bss_1323C._0->_23C == 9) {
            changeScene(1, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 7 &&
            settings->GameModeSelected != GAME_TYPE_DEMO && g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
            lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 8;
            changeScene(3, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            fn_3_24630();
            fn_3_FBD70();
            fn_3_FBD58();
            fn_3_5A6D4(0);
        }
        break;
    }
}

// .text:0x00022C20 size:0x4B4 mapped:0x80661CB4
void fn_3_22C20(void) {
    int i;
    GameInitVariables* settings = &g_d_GameSettings;
    lbl_3_common_bss_32A94_s* bss = &lbl_3_common_bss_32A94;
    GameControlsStruct* logic = &g_GameLogic;
    StarMissionCompletionTracker* challenge;
    s16 team;
    s16 charID;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_147DFC();
            lbl_3_common_bss_32724._9A = 0;
            logic->_125 = 1;
        }
        break;
    case 1:
        if (fn_3_6B4C8()) {
            logic->_125 = 2;
        }
        break;
    case 2:
        fn_3_8C104(-1);
        fn_3_24DBC(2);
        challenge = &starMissionCompletionTracker;
        if (bss->_8A) {
            fn_3_FBDAC(lbl_3_data_2368[challenge->_441C]);
        } else {
            fn_3_FBDAC(lbl_3_data_2380[challenge->_441C]);
        }
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        logic->_125 = 3;
        break;
    case 3:
        if (lbl_3_common_bss_1323C._0->_23C == 9) {
            changeScene(1, 0x5A);
        }
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 91 &&
            settings->GameModeSelected != GAME_TYPE_DEMO) {
            if (lbl_3_common_bss_1323C._0->_280 == 1 && g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
                lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 92;
                changeScene(3, 0x5A);
                lbl_3_common_bss_34C58._2A = 1;
                lbl_3_common_bss_34C58._24 = 0x5A;
            }
        } else if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E - 91) {
            changeScene(3, 0x5A);
            lbl_3_common_bss_34C58._2A = 1;
            lbl_3_common_bss_34C58._24 = 0x5A;
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            logic->_125 = 4;
        }
        break;
    case 4:
        if (lbl_8037169C._13) {
            fn_3_24630();
            fn_3_FBD70();
            fn_3_FBD58();
            logic->_125 = 5;
        }
        break;
    case 5:
        logic->_128 = 1;
        logic->framesOfExitingToMenu = 1;
        break;
    }
    team = lbl_3_common_bss_37400._40;
    charID = inMemRoster[team][g_GameLogic.Team_CaptainRosterLoc[team]].stats.CharID;
    if (lbl_3_common_bss_1323C._0->_23C == lbl_3_data_7F7C[lbl_800E8558[charID]._2][3]) {
        fn_3_90220(charID, 7);
    }
}

// .text:0x00022C10 size:0x10 mapped:0x80661CA4
void fn_3_22C10(void) {
    int i;

    for (i = 13; i != 0; i--) {
    }
}

// .text:0x00022ABC size:0x154 mapped:0x80661B50
int fn_3_22ABC(void) {
    ScoresA00* scores = &g_Scores;
    BOOL close = FALSE;
    int n;

    n = 0;
    if (g_Runners[1].rosterID != -1) {
        n++;
    }
    if (g_Runners[2].rosterID != -1) {
        n++;
    }
    if (g_Runners[3].rosterID != -1) {
        n++;
    }
    if (__abs(scores->_A6) <= 4 && n == 3 &&
        scores->_04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] <=
            scores->_04[g_GameLogic.awayTeamBattingInd_battingTeam][0]) {
        close = TRUE;
    }
    n = 0;
    if (g_Runners[2].rosterID != -1) {
        n++;
    }
    if (g_Runners[3].rosterID != -1) {
        n++;
    }
    if (__abs(scores->_A6) <= n && n > 0 &&
        scores->_04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] <=
            scores->_04[g_GameLogic.awayTeamBattingInd_battingTeam][0]) {
        close = TRUE;
    }
    if (close) {
        if (g_Batter.aiControlledInd) {
            return 1;
        }
        return 2;
    }
    return -1;
}

// .text:0x00022A20 size:0x9C mapped:0x80661AB4
BOOL fn_3_22A20(void) {
    if (g_Batter.aiControlledInd) {
        if (g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] <
            g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0]) {
            return FALSE;
        }
        return TRUE;
    }
    if (g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] <
        g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0]) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x00022948 size:0xD8 mapped:0x806619DC
void fn_3_22948(void) {
    s32 i;

    for (i = 0; i < 33; i++) {
        lbl_3_data_2398[i]._34 = 0;
        lbl_3_data_2398[i]._38 = 0;
        lbl_3_data_2398[i]._3C = 0;
    }
    lbl_3_common_bss_1323C._0->_27B = 0;
}

// .text:0x00022944 size:0x4 mapped:0x806619D8
void fn_3_22944(void) {
    return;
}

// .text:0x00022850 size:0xF4 mapped:0x806618E4
void fn_3_22850(void) {
    s32 i;

    for (i = 0; i < 33; i++) {
        lbl_3_data_2398[i]._38 = 0;
        lbl_3_data_2398[i]._3C = 0;
    }
    lbl_3_common_bss_1323C._0->_27B = 0;
}

// .text:0x0002281C size:0x34 mapped:0x806618B0
BOOL fn_3_2281C(int i) {
    UnkA00Actor* actor = lbl_8036E548._2C50[i];

    if (actor == NULL) {
        return TRUE;
    }
    if (actor->_068 == 0) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x0002273C size:0xE0 mapped:0x806617D0
BOOL fn_3_2273C(void) {
    int i;

    for (i = 0; i < 9; i++) {
        if (g_Fielders[i]._218 == 0) {
            if (lbl_8036E548._2C50[i] == NULL) {
                return TRUE;
            }
            if (lbl_8036E548._2C50[i]->_068 == 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// .text:0x00021F14 size:0x828 mapped:0x80660FA8
BOOL fn_3_21F14(void) {
    StarMissionCompletionTracker* challenge = &starMissionCompletionTracker;
    GameInitVariables* settings = &g_d_GameSettings;
    UnkA00Bss37400* bss = &lbl_3_common_bss_37400;
    BOOL ret;
    BOOL ok;
    int i;
    int x;
    UnkA00Replay* p;
    s8 idx;

    ret = FALSE;
    if (!settings->exhibitionMatchInd) {
        if (challenge->_441E == 5 || challenge->_16C2 == 42) {
            ret = FALSE;
        } else {
            ret = fn_3_165D24();
        }
    }
    if (!settings->exhibitionMatchInd) {
        if (ret && lbl_80109420[bss->_46]._D) {
            lbl_3_common_bss_1323C._0->_260 = 28;
            challenge->_44F1 = 0;
            return TRUE;
        }
        return FALSE;
    }
    lbl_3_common_bss_1323C._0->_260 = -1;
    for (i = 0; i < 33; i++) {
        // A no-op, but the target keeps its compare and store
        if (i == 45) {
            i = 45;
        }
        ok = TRUE;
        if (g_Scores._AC != lbl_3_data_2398[i]._00) {
            if (lbl_3_data_2398[i]._00 == 1 && g_Scores._AC != 1 && g_Scores._AC != 0) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._00 != 1 && (g_Scores._AC == 1 || g_Scores._AC == 0)) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._00 == 2 && g_Scores._AC != 2) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._00 != 2 && g_Scores._AC == 2) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._00 == 3 && g_Scores._AC != 3) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._00 != 3 && g_Scores._AC == 3) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._00 == 4 && g_Scores._AC < 4) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._00 != 4 && g_Scores._AC >= 4) {
                ok = FALSE;
            }
        }
        if (lbl_3_data_2398[i]._08 != -1 && g_Strikes.outs != lbl_3_data_2398[i]._08) {
            ok = FALSE;
        }
        if (lbl_3_data_2398[i]._0C != -1) {
            if (lbl_3_data_2398[i]._0C == 1 && g_Runners[1].rosterID == -1) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._0C == 0 && g_Runners[1].rosterID != -1) {
                ok = FALSE;
            }
        }
        if (lbl_3_data_2398[i]._10 != -1) {
            if (lbl_3_data_2398[i]._10 == 1 && g_Runners[2].rosterID == -1) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._10 == 0 && g_Runners[2].rosterID != -1) {
                ok = FALSE;
            }
        }
        if (lbl_3_data_2398[i]._14 != -1) {
            if (lbl_3_data_2398[i]._14 == 1 && g_Runners[3].rosterID == -1) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._14 == 0 && g_Runners[3].rosterID != -1) {
                ok = FALSE;
            }
        }
        if (lbl_3_data_2398[i]._18 != -1) {
            x = fn_3_22ABC();
            if (lbl_3_data_2398[i]._18 == 0 && x != 0) {
                ok = FALSE;
            }
            if (lbl_3_data_2398[i]._18 == 1 && x != 1) {
                ok = FALSE;
            }
            if (lbl_3_data_2398[i]._18 == 2 && x != 2) {
                ok = FALSE;
            }
        }
        if (lbl_3_data_2398[i]._1C != -1) {
            x = fn_3_22A20();
            if (lbl_3_data_2398[i]._1C == 0 && x != 0) {
                ok = FALSE;
            } else if (lbl_3_data_2398[i]._1C == 1 && x != 1) {
                ok = FALSE;
            }
        }
        if (lbl_3_data_2398[i]._20 != -1) {
            if (lbl_3_data_2398[i]._20 == 1 && lbl_3_data_2BD8[g_Batter.charID][g_Pitcher.charID] == 0) {
                if (g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamBatting] != g_Batter.charID ||
                    g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamFielding] != g_Pitcher.charID) {
                    ok = FALSE;
                }
            } else if (lbl_3_data_2398[i]._20 == 0 &&
                       lbl_3_data_2BD8[g_Batter.charID][g_Pitcher.charID] == 1) {
                ok = FALSE;
            }
        }
        if (lbl_3_data_2398[i]._24 != -1 && lbl_3_data_2398[i]._24 != 0 && lbl_3_data_2398[i]._34 != 0) {
            ok = FALSE;
        }
        if (lbl_3_data_2398[i]._28 != -1 && lbl_3_data_2398[i]._28 != 0) {
            if (lbl_3_data_2398[i]._38 != 0) {
                if (lbl_3_data_2398[i]._20 == 1 && lbl_3_data_2BD8[g_Batter.charID][g_Pitcher.charID] == 1) {
                    if (g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamBatting] == g_Batter.charID &&
                        g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamFielding] == g_Pitcher.charID) {
                        if (lbl_3_data_2398[i]._3C != 0) {
                            ok = FALSE;
                        }
                    } else {
                        ok = FALSE;
                    }
                } else {
                    ok = FALSE;
                }
            } else if (lbl_3_common_bss_1323C._0->_27B >= lbl_3_data_2398[i]._30) {
                ok = FALSE;
            }
        }
        if (ok) {
            lbl_3_common_bss_1323C._0->_260 = i;
        }
    }
    p = lbl_3_common_bss_1323C._0;
    idx = p->_260;
    if (idx != -1) {
        if (!settings->exhibitionMatchInd && lbl_3_data_1F50[idx] == 1) {
            p->_260 = -1;
            return FALSE;
        }
        if (lbl_3_data_2398[idx]._24 == 1) {
            lbl_3_data_2398[idx]._34 = 1;
        }
        if (lbl_3_data_2398[p->_260]._28 == 1) {
            lbl_3_data_2398[p->_260]._38 = 1;
            if (lbl_3_data_2398[p->_260]._20 == 1 &&
                lbl_3_data_2BD8[g_Batter.charID][g_Pitcher.charID] == 1) {
                if (g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamBatting] == g_Batter.charID &&
                    g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamFielding] == g_Pitcher.charID) {
                    lbl_3_data_2398[p->_260]._3C = 1;
                }
                lbl_3_common_bss_32724._AE = 1;
                lbl_3_common_bss_32724._AF = g_Pitcher.rosterID;
            }
        }
        p->_27B = lbl_3_data_2398[p->_260]._30;
        return TRUE;
    }
    return FALSE;
}

// .text:0x00021DE4 size:0x130 mapped:0x80660E78
void fn_3_21DE4(void) {
    UnkA00Task* task = lbl_803CC1B8;

    switch (lbl_3_bss_9C) {
    case 0:
        task->_1E = 0;
        task->_20 = 0xFF;
        lbl_803C5090._1D = 9;
        lbl_803C5090._00 = 1.0f;
        lbl_803C5090._14 = 0x1C0;
        lbl_803C5090._19 = 1;
        lbl_803C5090._18 = 0;
        lbl_803C5090._1A = 0xFF;
        lbl_803C5090._1B = 0xFF;
        lbl_803C5090._1C = 0xFF;
        lbl_803C5090._17 = 0xFF;
        lbl_3_bss_9C++;
        break;
    case 1:
        lbl_803C5090._1D = 8;
        lbl_803C5090._00 = 1.0f;
        lbl_803C5090._14 = 0x1C0;
        lbl_803C5090._19 = 1;
        lbl_803C5090._18 = 0;
        lbl_803C5090._1A = 0xFF;
        lbl_803C5090._1B = 0xFF;
        lbl_803C5090._1C = 0xFF;
        lbl_803C5090._17 = 0xFF;
        task->_1E++;
        if (g_pCamera->_AAE <= task->_1E) {
            g_pCamera->_AAA = 0;
            fn_800B0A14_removeQueue();
            lbl_3_bss_9C = 0;
        }
        break;
    case 2:
        break;
    }
}

// .text:0x00021C90 size:0x154 mapped:0x80660D24
void fn_3_21C90(void) {
    UnkA00Task* task = lbl_803CC1B8;

    switch (lbl_3_bss_A0[0]) {
    case 0:
        task->_1E = 0;
        task->_20 = 0xFF;
        lbl_803C5090._1D = 9;
        lbl_803C5090._00 = 1.0f;
        lbl_803C5090._14 = 0x1C0;
        lbl_803C5090._19 = 1;
        lbl_803C5090._18 = 0;
        lbl_803C5090._1A = 0xFF;
        lbl_803C5090._1B = 0xFF;
        lbl_803C5090._1C = 0xFF;
        lbl_803C5090._17 = task->_20;
        lbl_3_bss_A0[0]++;
        break;
    case 1:
        lbl_803C5090._1D = 8;
        lbl_803C5090._00 = 1.0f;
        lbl_803C5090._14 = 0x1C0;
        lbl_803C5090._19 = 1;
        lbl_803C5090._18 = 0;
        lbl_803C5090._1A = 0xFF;
        lbl_803C5090._1B = 0xFF;
        lbl_803C5090._1C = 0xFF;
        lbl_803C5090._17 = task->_20;
        task->_1E++;
        if (g_pCamera->_AAC <= task->_1E) {
            g_pCamera->_AA8 = 0;
            fn_800B0A14_removeQueue();
            lbl_3_bss_A0[0] = 0;
        } else {
            task->_20 = 0xFF - task->_1E * 0xFF / g_pCamera->_AAC;
        }
        break;
    case 2:
        break;
    }
}
