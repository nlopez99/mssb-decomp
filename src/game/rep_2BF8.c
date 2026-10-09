#include "game/rep_2BF8.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_720.h"
#include "musyx/musyx.h"
#include "game/rep_1668.h"
#include "game/rep_16B8.h"
#include "game/rep_1770.h"
#include "game/rep_31A0.h"

typedef struct UnkTask2BF8 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
    /* 0x22 */ u16 _22;
    union {
        /* 0x24 */ u8 _24_arr[4];
        /* 0x24 */ SND_VOICEID voice;
    };
} UnkTask2BF8;

typedef struct {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ f32 _48;
    /* 0x4C */ f32 _4C;
    /* 0x50 */ u8 _50[0x54 - 0x50];
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66;
    /* 0x67 */ u8 _67;
    /* 0x68 */ u8 _68;
    /* 0x69 */ u8 _69;
} UnkSprite2BF8;

typedef struct {
    /* 0x00 */ UnkSprite2BF8* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef2BF8; // size: 0x8

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc2BF8; // size: 0x20

extern struct {
    /* 0x00 */ u8 _00[0x96];
    /* 0x96 */ u8 _96;
    /* 0x97 */ u8 _97;
    /* 0x98 */ u8 _98[0xA5 - 0x98];
    /* 0xA5 */ u8 _A5;
    /* 0xA6 */ u8 _A6;
    /* 0xA7 */ u8 _A7;
    /* 0xA8 */ u8 _A8[0xAA - 0xA8];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB[0xB7 - 0xAB];
    /* 0xB7 */ u8 _B7;
    /* 0xB8 */ u8 _B8[0xD6 - 0xB8];
    /* 0xD6 */ u8 _D6;
    /* 0xD7 */ u8 _D7[0xD9 - 0xD7];
    /* 0xD9 */ u8 _D9;
    /* 0xDA */ u8 _DA;
    /* 0xDB */ u8 _DB;
    /* 0xDC */ u8 _DC;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x000 */ u8 _000[0x1D2];
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} lbl_800FEF70[];
extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x8 - 0x1];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
} lbl_8034E978;

extern struct {
    /* 0x000 */ u8 _000[0x398];
    /* 0x398 */ u8 _398;
} lbl_800EF808;

extern u8 lbl_800EFBA4[0x10];
extern s16 lbl_80109410[8];
extern UnkSpriteRef2BF8 lbl_80371C30[];
extern void* lbl_803CC1B8;

// Screen-edge bands: x from [0] to [1] and from [3] to [2], y from [4] to [5] and from [7] to [6].
extern s16 lbl_3_data_D638[8];
extern u16 lbl_3_data_91AC[8];

extern UnkSpriteDesc2BF8 lbl_3_data_8E68[2];
extern s16 lbl_3_data_8EA8[14];
extern UnkSpriteDesc2BF8 lbl_3_data_8EC4[3];
extern UnkSpriteDesc2BF8 lbl_3_data_8F24[2];
extern UnkSpriteDesc2BF8 lbl_3_data_8F64[3];
extern u16 lbl_3_data_8FC4[4];
extern UnkSpriteDesc2BF8 lbl_3_data_8FCC[2];
extern UnkSpriteDesc2BF8 lbl_3_data_900C[13];
extern u16 lbl_3_data_81DC[0x10];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];
extern s16 lbl_3_data_189C4[3][7];

extern void fn_80034CEC(UnkTask2BF8* task);
extern void fn_80034E20(UnkTask2BF8* task, UnkSpriteDesc2BF8* desc);
extern void fn_800363D8(UnkTask2BF8* task, s32, s32, s32, s32);
extern void fn_800B0A14_removeQueue(void);
extern UnkTask2BF8* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_8004CC4C(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_8004D0F0(void);
extern void fn_80050F78(s32);
extern void fn_80051D00(void);
extern void fn_80053FE8(void);

// rep_3448
extern u32 fn_3_12536C(void);
extern u32 fn_3_125424(UnkTask2BF8* task, s32 i, u32 frame);
extern void fn_3_1254F8(void);
extern void fn_3_126604(void);
extern void fn_3_1274B4(void);
extern void fn_3_128B90(void);
extern void fn_3_129458(void);
extern void fn_3_12A6C4(void);
extern void fn_3_12B7A0(void);
extern void fn_3_12C3F0(void);

static inline SND_VOICEID playStadiumSound(int id) {
    int stadium = g_d_GameSettings.StadiumID;
    SND_VOICEID voice = sndFXStartEx(lbl_3_data_81DC[stadium] + id,
                                     g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD
                                         ? lbl_3_data_84B8[id][0]
                                         : lbl_3_data_8404[stadium][id][0],
                                     0x3F, 0);

    sndFXCtrl(voice, 0x5B,
              g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD ? lbl_3_data_84B8[id][1]
                                                                      : lbl_3_data_8404[stadium][id][1]);
    return voice;
}

static inline u32 getFrame(UnkTask2BF8* task, u32 i) {
    return lbl_80371C30[task->_14 + i]._00->_5C >> 16;
}

static inline BOOL isSpriteDone(UnkTask2BF8* task, u32 i) {
    return lbl_80371C30[task->_14 + i]._00->_69 == 2 ? TRUE : FALSE;
}

static inline void setScreen(u8 id) {
    lbl_8034E978._00 = id;
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._08 = lbl_800FEF70[id]._08;
}

// Several functions reach these tables from one pool base, so most are statics.
static UnkSpriteDesc2BF8 lbl_3_data_19770[6] = {
    { 0, 0xA, { 0, 0, -1 }, { 1, 9 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0xB, { 0, 0, -1 }, { 0, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0xC, { 0, 0, -1 }, { 0, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0xD, { 0, 0, -1 }, { 0, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0xE, { 0, 0, -1 }, { 0, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 3 },
};
UnkSpriteDesc2BF8 lbl_3_data_19830[7] = {
    { 0, 1, { 0, 0, -1 }, { 1, 9 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x67, { 0, 0, -1 }, { 0, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 2, { 0, 0, -1 }, { 1, 7 }, 1, { 0x0E000000, 0, 0x00010003 } },
    { 0, 2, { 0, 0, -1 }, { 1, 7 }, 1, { 0x0E000000, 0, 0x00010002 } },
    { 0, 2, { 0, 0, -1 }, { 1, 7 }, 1, { 0x0E000000, 0, 0x00010001 } },
    { 0, 2, { 0, 0, -1 }, { 1, 7 }, 1, { 0x0E000000, 0, 0x00010000 } },
    { 3 },
};
static UnkSpriteDesc2BF8 lbl_3_data_19910[3] = {
    { 0, 0x11, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0xF, { 0, 0, -1 }, { 1, 7 }, 0, { 0x0E000000, 0, 0x00010000 } },
    { 3 },
};
static u16 lbl_3_data_19970[4] = { 0x11, 0x12, 0x13, 0x14 };
static u16 lbl_3_data_19978[4] = { 0x87, 0x87, 0x87, 0x87 };
static u16 lbl_3_data_19980[4] = { 0xBE, 0xBE, 0xBE, 0xBE };
UnkSpriteDesc2BF8 lbl_3_data_19988[16] = {
    { 0, 0x1B, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x1E, { 0, 0, -1 }, { 0, 7 }, 0, { 0x0E000000, 0, 0x00010002 } },
    { 0, 0x1E, { 0, 0, -1 }, { 0, 7 }, 0, { 0x0E000000, 0, 0x00010001 } },
    { 0, 0x1E, { 0, 0, -1 }, { 0, 7 }, 0, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x1C, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x1A, { 0, 0, -1 }, { 0, 7 }, 1, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x1A, { 0, 0, -1 }, { 0, 7 }, 2, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x1A, { 0, 0, -1 }, { 0, 7 }, 3, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x1A, { 0, 0, -1 }, { 0, 7 }, 1, { 0x0E000000, 0, 0x00010001 } },
    { 0, 0x1A, { 0, 0, -1 }, { 0, 7 }, 2, { 0x0E000000, 0, 0x00010001 } },
    { 0, 0x1A, { 0, 0, -1 }, { 0, 7 }, 3, { 0x0E000000, 0, 0x00010001 } },
    { 0, 0x1D, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x17, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x19, { 0, 0, -1 }, { 0, 7 }, 0xFF, { 0x0E000000, 0, 0x00010000 } },
    { 0, 0x18, { 0, 0, -1 }, { 0, 7 }, 0xD, { 0x0E000000, 0, 0x00010000 } },
    { 3 },
};
u16 lbl_3_data_19B88[8] = { 0, 1, 2, 3, 4, 6, 7, 5 };
UnkSpriteDesc2BF8 lbl_3_data_19B98[46] = {
    { 0, 0x71, { 0, 0, -1 }, { 0, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x4B, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x4B, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x4B, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x4B, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5C, { 0, 0, -1 }, { 0, 7 }, 1, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5C, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5C, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5C, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x60, { 0, 0, -1 }, { 0, 7 }, 1, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x60, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x60, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x60, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 9, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xA, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xB, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xC, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 1, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 1, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 1, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 1, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 1, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 1, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 2, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 2, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 2, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 2, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x5D, { 0, 0, -1 }, { 1, 7 }, 0, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x5D, { 0, 0, -1 }, { 1, 7 }, 0, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x5D, { 0, 0, -1 }, { 1, 7 }, 0, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x5D, { 0, 0, -1 }, { 1, 7 }, 0, { 0x03000000, 0, 0x00010000 } },
    { 3 },
};
u16 lbl_3_data_1A158[8] = { 0x6C, 0x6B, 0x6E, 0x6D, 0x70, 0x6F, 0x72, 0x71 };
UnkSpriteDesc2BF8 lbl_3_data_1A168[46] = {
    { 0, 0x67, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x63, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x63, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x63, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x63, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x55, { 0, 0, -1 }, { 0, 7 }, 1, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x55, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x55, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x55, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5C, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5C, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5C, { 0, 0, -1 }, { 0, 7 }, 7, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5C, { 0, 0, -1 }, { 0, 7 }, 8, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x60, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x60, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x60, { 0, 0, -1 }, { 0, 7 }, 7, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x60, { 0, 0, -1 }, { 0, 7 }, 8, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xD, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xE, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xF, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0x10, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 7, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 8, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 7, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 8, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 7, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 7, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 7, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 8, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 8, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 8, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x5D, { 0, 0, -1 }, { 1, 7 }, 1, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5D, { 0, 0, -1 }, { 1, 7 }, 2, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5D, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x5D, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010000 } },
    { 3 },
};
u16 lbl_3_data_1A728[4] = { 0x67, 0x68, 0x69, 0x6A };
UnkSpriteDesc2BF8 lbl_3_data_1A730[22] = {
    { 0, 0x67, { 0, 0, -1 }, { 0, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x57, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x57, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x57, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x57, { 0, 0, -1 }, { 0, 7 }, 0, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 1, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 1, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 1, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 1, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x56, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010003 } },
    { 3 },
};
static UnkSpriteDesc2BF8 lbl_3_data_1A9F0[44] = {
    { 0, 0x21, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x25, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x2A, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x29, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x29, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x29, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x29, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x2E, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x2E, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x2E, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x2E, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x53, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x53, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x53, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x53, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x17E, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x17F, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x180, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x181, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x5F, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010008 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010008 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010008 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010008 } },
    { 3 },
};
static u16 lbl_3_data_1AF70[8] = { 0x21, 0x1B, 0x1C, 0x1D, 0x1F, 0x1E, 0x20, 0 };
static u16 lbl_3_data_1AF80[4] = { 0x25, 0x26, 0x27, 0x28 };
static u16 lbl_3_data_1AF88[4] = { 0x22, 0x23, 0x24, 0 };
static u16 lbl_3_data_1AF90[4] = { 0x2A, 0x2B, 0x2C, 0x2D };
static u16 lbl_3_data_1AF98[8] = { 6, 0, 1, 2, 4, 3, 5, 0 };
static u16 lbl_3_data_1AFA8[4] = { 0x17E, 0x17F, 0x180, 0x181 };
static UnkSpriteDesc2BF8 lbl_3_data_1AFB0[65] = {
    { 0, 0x16F, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x16E, { 0, 0, -1 }, { 1, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x183, { 0, 0, -1 }, { 0, 7 }, 0xFF, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x182, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x182, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x182, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x182, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x17C, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x17C, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x17C, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x17C, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x17D, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x17D, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x17D, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x17D, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xB, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xB, { 0x01000000, 0, 0x00010001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xC, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xC, { 0x01000000, 0, 0x00010001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xD, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xD, { 0x01000000, 0, 0x00010001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xE, { 0x01000000, 0, 0x00010000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 7 }, 0xE, { 0x01000000, 0, 0x00010001 } },
    { 0, 0x177, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x178, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x179, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x175, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x176, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x17E, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x17F, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x180, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x181, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010004 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010005 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 3, { 0x03000000, 0, 0x00010008 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 4, { 0x03000000, 0, 0x00010008 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 5, { 0x03000000, 0, 0x00010008 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010006 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010007 } },
    { 0, 0x64, { 0, 0, -1 }, { 0, 7 }, 6, { 0x03000000, 0, 0x00010008 } },
    { 0, 0x17A, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x00010009 } },
    { 0, 0x17A, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x00010009 } },
    { 0, 0x17A, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x00010009 } },
    { 0, 0x17A, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x00010009 } },
    { 0, 0x17B, { 0, 0, -1 }, { 1, 7 }, 3, { 0x03000000, 0, 0x0001000A } },
    { 0, 0x17B, { 0, 0, -1 }, { 1, 7 }, 4, { 0x03000000, 0, 0x0001000A } },
    { 0, 0x17B, { 0, 0, -1 }, { 1, 7 }, 5, { 0x03000000, 0, 0x0001000A } },
    { 0, 0x17B, { 0, 0, -1 }, { 1, 7 }, 6, { 0x03000000, 0, 0x0001000A } },
    { 0, 0x172, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x172, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x172, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x172, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010000 } },
    { 0, 0x173, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010003 } },
    { 0, 0x173, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010002 } },
    { 0, 0x173, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010001 } },
    { 0, 0x173, { 0, 0, -1 }, { 0, 7 }, 2, { 0x03000000, 0, 0x00010000 } },
    { 3 },
};
static u16 lbl_3_data_1B7D0[4] = { 0x177, 0x178, 0x179, 0x175 };

// .text:0x000EDD10 size:0x29C mapped:0x8072CDA4
void fn_3_EDD10(void) {
    if (g_GameLogic.gameStatus == GAME_STATUS_MINIGAME_SELECT ||
        (u8)(g_GameLogic.gameStatus - GAME_STATUS_TOY_STADIUM_LOAD) <= 3 ||
        g_GameLogic.gameStatus == GAME_STATUS_MINIGAME_READY) {
        fn_3_EDA3C();
        return;
    }
    lbl_3_common_bss_32724._DA = 0;
    fn_3_97144();
    fn_3_96914();
    fn_3_ED818();
    fn_3_9143C();
    if (g_Minigame.framesSincePanelHit == 1) {
        fn_800B0A5C_insertQueue(fn_3_ED784, 2);
    }
    if (g_Minigame.panelHitInd != 0 && lbl_3_common_bss_32724._D6 == 0 &&
        g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL) {
        fn_800B0A5C_insertQueue(fn_3_EA8FC, 2)->_18 = 1;
        fn_800B0A5C_insertQueue(fn_3_EAEF4, 2);
    }
    if (g_Minigame._19CE != 0 && g_Minigame._19BA == 1) {
        fn_800B0A5C_insertQueue(fn_3_ED2A8, 2);
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_MVP_END_GAME || g_GameLogic.gameStatus == GAME_STATUS_MINIGAME_POST_MENU) {
        fn_3_129458();
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_GAME_START_MOVIE) {
        if (g_Minigame._1E02 == 0) {
            fn_800B0A5C_insertQueue(fn_3_1254F8, 2);
        }
    } else if (g_GameLogic.gameStatus == GAME_STATUS_MINIGAME_POST_MENU) {
        if (lbl_3_common_bss_34C90._1D2 == 1) {
            fn_800B0A5C_insertQueue(fn_3_9894C, 2);
        }
    } else if (g_GameLogic.gameStatus == GAME_STATUS_INNING_TRANSITION) {
        if (g_GameLogic._125 == 0 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 0) {
            fn_800B0A5C_insertQueue(fn_3_E911C, 2)->_18 = 0;
        }
    } else if (g_GameLogic.gameStatus == 36) {
        if (g_GameLogic._125 == 5 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 0) {
            fn_800B0A5C_insertQueue(fn_3_1274B4, 2);
        }
    } else if (g_GameLogic.gameStatus == 9) {
    } else if (g_GameLogic.gameStatus == GAME_STATUS_HOW_TO_PLAY_SCREEN) {
        if (lbl_3_common_bss_34C90._1D2 == 2) {
            fn_800B0A5C_insertQueue(fn_3_128B90, 2);
        }
    } else if (g_GameLogic.gameStatus == GAME_STATUS_PAUSED) {
        if (lbl_3_common_bss_34C90._1D2 == 8 && lbl_3_common_bss_34C90._1D4 == 2) {
            fn_800B0A5C_insertQueue(fn_3_126604, 2);
        }
    }
}

// .text:0x000EDA3C size:0x2D4 mapped:0x8072CAD0
void fn_3_EDA3C(void) {
    if (g_GameLogic.gameStatus >= GAME_STATUS_MINIGAME_SELECT && g_GameLogic.gameStatus <= 32 &&
        lbl_3_common_bss_32724._D9 == 0 && g_GameLogic.framesOfExitingToMenu == 0) {
        fn_800B0A5C_insertQueue(fn_3_12C3F0, 2);
        fn_800B0A5C_insertQueue(fn_80053FE8, 2);
        setScreen(0x2E);
    }
    if (g_GameLogic.gameStatus == 30) {
        if (g_GameLogic._125 == 1 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 0) {
            if (lbl_3_common_bss_32724._DC == 0) {
                fn_800B0A5C_insertQueue(fn_80051D00, 2);
                lbl_3_common_bss_32724._DC = 1;
            }
            if (lbl_3_common_bss_32724._DA != 1) {
                fn_800B0A5C_insertQueue(fn_3_12B7A0, 2);
            }
        }
        if (g_GameLogic._125 == 2) {
            if (lbl_3_common_bss_32724._DC == 0 && g_Minigame._19DE != 5 && g_Minigame._19DE != 8) {
                fn_800B0A5C_insertQueue(fn_80051D00, 2);
                lbl_3_common_bss_32724._DC = 1;
            }
            if (g_Minigame._19DE == 1 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
                fn_800B0A5C_insertQueue(fn_3_12A6C4, 2);
            }
        }
        if (g_GameLogic._125 == 7) {
            fn_80050F78(1);
            lbl_3_common_bss_32724._DC = 0;
        }
        if (g_GameLogic._125 == 3 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            fn_8004CC4C(0, 1, 1, 0, 0x89);
            fn_800B0A5C_insertQueue(fn_8004D0F0, 2);
        }
        if (g_GameLogic._125 == 5) {
            fn_80050F78(1);
        }
    } else if (g_GameLogic.gameStatus == GAME_STATUS_MINIGAME_READY) {
        if (g_GameLogic._125 == 2 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            fn_800B0A5C_insertQueue(fn_3_126604, 2);
            setScreen(0x32);
            if (g_d_GameSettings.exhibitionMatchInd == 0 && lbl_3_common_bss_32724._D9 == 0) {
                fn_800B0A5C_insertQueue(fn_3_12C3F0, 2);
            }
        }
    }
}

// .text:0x000ED818 size:0x224 mapped:0x8072C8AC
void fn_3_ED818(void) {
    if (g_GameLogic.hudElementLoadingInd != 0 && lbl_3_common_bss_32724._A5 == 0) {
        lbl_3_common_bss_32724._A5 = 1;
        lbl_3_common_bss_32724._A6 = 0;
        lbl_3_common_bss_32724._A7 = 0xFF;
        fn_800B0A5C_insertQueue(fn_3_9C28C, 2);
        fn_800B0A5C_insertQueue(fn_3_EA8FC, 2)->_18 = 0;
        fn_800B0A5C_insertQueue(fn_3_EB6E0, 2);
    }
    if (g_Ball.totalFramesAtPlay == 15 && g_Minigame.toyfield_waitFor_CoinsX2_AnimationToEnd == 0 &&
        g_Minigame.toyField_pointMultiplier > 1 && g_Pitcher.nPitchesThisAB == 0) {
        fn_800B0A5C_insertQueue(fn_3_ED490, 2);
    }
    if (lbl_3_common_bss_32724._A5 != 0 && lbl_3_common_bss_32724._A6 < 0xFF) {
        if (lbl_3_common_bss_32724._A6 < 0xF0) {
            lbl_3_common_bss_32724._A6 += 0x10;
        } else {
            lbl_3_common_bss_32724._A6 = 0xFF;
        }
    }
    if (lbl_3_common_bss_32724._A7 != 0 && lbl_3_common_bss_32724._A7 < 0xFF) {
        if (lbl_3_common_bss_32724._A7 <= 0x10) {
            lbl_3_common_bss_32724._A7 = 0;
            lbl_3_common_bss_32724._A5 = 0;
        } else {
            lbl_3_common_bss_32724._A7 -= 0x10;
        }
    } else if (lbl_3_common_bss_32724._A5 != 0) {
        if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION) {
            lbl_3_common_bss_32724._A7 = 0;
            lbl_3_common_bss_32724._A5 = 0;
        } else if (g_GameLogic.gameStatus != GAME_STATUS_AT_BAT && g_GameLogic.gameStatus != GAME_STATUS_DEFAULT &&
                   g_GameLogic.gameStatus != GAME_STATUS_PAUSED &&
                   g_GameLogic.gameStatus != GAME_STATUS_HOW_TO_PLAY_SCREEN) {
            lbl_3_common_bss_32724._A7 = 0xF0;
        }
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_PAUSED && lbl_3_common_bss_34C90._1D2 == 1) {
        fn_800B0A5C_insertQueue(fn_3_9894C, 2);
        if (lbl_3_common_bss_32724._AA == 0) {
            fn_800B0A5C_insertQueue(fn_3_98DE0, 2);
        }
    }
}

// .text:0x000ED784 size:0x94 mapped:0x8072C818
void fn_3_ED784(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    int id;

    if (g_Minigame.toyFieldBallStateResult2 == 11) {
        task->_00 = fn_3_EC014;
        return;
    }
    id = lbl_3_data_8EA8[g_Minigame.toyFieldBallStateResult2];
    if (id < 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    lbl_3_data_8E68[0]._02 = id;
    fn_80034E20(task, lbl_3_data_8E68);
    ((UnkTask2BF8*)lbl_803CC1B8)->_00 = fn_3_ED6E0;
}

// .text:0x000ED6E0 size:0xA4 mapped:0x8072C774
void fn_3_ED6E0(void) {
    UnkTask2BF8* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || lbl_80371C30[task->_14]._00->_69 == 2 ||
        g_GameLogic.gameStatus == GAME_STATUS_TRANSITION) {
        if (g_Minigame._1921 != 0) {
            fn_800B0A5C_insertQueue(fn_3_ED0F4, 2);
        }
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000ED574 size:0x16C mapped:0x8072C608
void fn_3_ED574(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    int turn;

    fn_80034E20(task, lbl_3_data_8EC4);
    fn_800363D8(task, 1, 6, 0x4A, g_Minigame.toyField_selectedTurns % 10);
    fn_800363D8(task, 1, 5, 0x4A, g_Minigame.toyField_selectedTurns / 10);
    turn = g_Minigame.toyField_turnNumber;
    if (turn > g_Minigame.toyField_selectedTurns) {
        turn = g_Minigame.toyField_selectedTurns;
    }
    fn_800363D8(task, 1, 2, 0x4A, turn % 10);
    if (turn >= 10) {
        fn_800363D8(task, 1, 1, 0x4A, turn / 10);
    } else {
        fn_800363D8(task, 1, 1, 0x4A, 10);
    }
    ((UnkTask2BF8*)lbl_803CC1B8)->_00 = fn_3_ED4FC;
}

// .text:0x000ED4FC size:0x78 mapped:0x8072C590
void fn_3_ED4FC(void) {
    UnkTask2BF8* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || g_GameLogic.hudLoadingRelated != 0 ||
        g_GameLogic.gameStatus == GAME_STATUS_INNING_TRANSITION || g_GameLogic.gameStatus == GAME_STATUS_MVP_END_GAME ||
        g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_MENU) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000ED490 size:0x6C mapped:0x8072C524
void fn_3_ED490(void) {
    UnkTask2BF8* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_8F24);
    g_Minigame.toyfield_waitFor_CoinsX2_AnimationToEnd = 1;
    task->_1C = 0;
    ((UnkTask2BF8*)lbl_803CC1B8)->_00 = fn_3_ED2F4;
}

// .text:0x000ED2F4 size:0x19C mapped:0x8072C388
void fn_3_ED2F4(void) {
    UnkTask2BF8* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 == 0) {
        if (g_UnkSound_32718._07 == 0) {
            lbl_80371C30[task->_14]._00->_68 = 1;
            if (task->_1C == 0) {
                if (lbl_800EF808._398 == 1) {
                    playStadiumSound(0x1B);
                }
                task->_1C = 1;
            }
        } else {
            lbl_80371C30[task->_14]._00->_68 = 0;
        }
        if (lbl_80371C30[task->_14]._00->_69 != 2) {
            return;
        }
    }
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
    g_Minigame.toyfield_waitFor_CoinsX2_AnimationToEnd = 0;
}

// .text:0x000ED2A8 size:0x4C mapped:0x8072C33C
void fn_3_ED2A8(void) {
    fn_80034E20(lbl_803CC1B8, lbl_3_data_8FCC);
    ((UnkTask2BF8*)lbl_803CC1B8)->_00 = fn_3_ED244;
}

// .text:0x000ED244 size:0x64 mapped:0x8072C2D8
void fn_3_ED244(void) {
    UnkTask2BF8* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || lbl_80371C30[task->_14]._00->_69 == 2) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000ED0F4 size:0x150 mapped:0x8072C188
void fn_3_ED0F4(void) {
    UnkTask2BF8* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_8F64);
    lbl_80371C30[task->_14 + 1]._00->_64 = lbl_3_data_8FC4[g_Minigame._1921 - 1];
    playStadiumSound(0x1C);
    task->_18 = 0;
    g_Minigame._19CD = 1;
    ((UnkTask2BF8*)lbl_803CC1B8)->_00 = fn_3_ED058;
}

// .text:0x000ED058 size:0x9C mapped:0x8072C0EC
void fn_3_ED058(void) {
    UnkTask2BF8* task = lbl_803CC1B8;

    task->_18++;
    if (lbl_3_common_bss_32724._96 != 0 ||
        (g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL && g_GameLogic.gameStatus != GAME_STATUS_AT_BAT) ||
        lbl_80371C30[task->_14]._00->_69 == 2) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        g_Minigame._19CD = 3;
    }
}

// .text:0x000ECD48 size:0x310 mapped:0x8072BDDC
void fn_3_ECD48(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    u8* flags = g_Minigame._1DF4_u8;
    u32 i;

    if (lbl_3_common_bss_32724._96 != 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_19770);
        playStadiumSound(0x11);
        task->_1C = 1;
        task->_1E = 0;
        break;
    case 1:
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) == 160) {
            i = 0;
            do {
                lbl_80371C30[task->_14 + 1 + g_Minigame._1935[i + 1]]._00->_68 = 1;
            } while (++i < g_Minigame.miniGameNumberOfParticipants - 1);
            task->_1C = 2;
        }
        task->_1E++;
        if (task->_1E == 60) {
            playStadiumSound(0x12);
        }
        break;
    case 2:
        if ((lbl_80371C30[task->_14 + 1 + g_Minigame._1935[1]]._00->_5C >> 16) >= 6) {
            i = 0;
            do {
                flags[g_Minigame._1935[i + 1]] = 2;
            } while (++i < g_Minigame.miniGameNumberOfParticipants - 1);
            g_Minigame._1934 = 2;
            task->_1C = 3;
        }
        break;
    case 3:
        break;
    }
}

// .text:0x000ECBB0 size:0x198 mapped:0x8072BC44
void fn_3_ECBB0(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    u8* flags = g_Minigame._1DF4_u8;
    u32 i;

    if (lbl_3_common_bss_32724._96 != 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_19830);
        lbl_80371C30[task->_14 + 1]._00->_5C = 10 << 16;
        i = 0;
        do {
            lbl_80371C30[task->_14 + 2 + i]._00->_54 &= ~2;
        } while (++i < 4);
        lbl_80371C30[task->_14 + 2 + g_Minigame._1935[0]]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 2 + g_Minigame._1935[1]]._00->_54 |= 2;
        flags[g_Minigame._1935[0]] = 1;
        flags[g_Minigame._1935[1]] = 1;
        task->_1C = 1;
        break;
    case 1:
        g_Minigame._1934 = 2;
        task->_1C = 2;
        break;
    case 2:
        break;
    }
}

// .text:0x000EC804 size:0x3AC mapped:0x8072B898
void fn_3_EC804(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    u8* flags = g_Minigame._1DF4_u8;

    if (lbl_3_common_bss_32724._96 != 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_19910);
        lbl_80371C30[task->_14]._00->_64 = lbl_3_data_19970[g_Minigame._1935[1]];
        lbl_80371C30[task->_14 + 1]._00->_64 = (task->_18 != 0) + 15;
        task->_1E = lbl_3_data_19978[g_Minigame._1935[1]];
        task->_20 = lbl_3_data_19980[g_Minigame._1935[1]];
        playStadiumSound(0x10);
        task->_1C = 1;
        break;
    case 1:
        if (task->_1E == (lbl_80371C30[task->_14]._00->_5C >> 16)) {
            if (task->_18 != 0) {
                playStadiumSound(7);
            } else {
                playStadiumSound(6);
            }
        }
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= task->_20) {
            flags[g_Minigame._1935[1]] = 2;
            g_Minigame._1934 = 2;
            task->_1C = 2;
        }
        break;
    case 2:
        break;
    }
}

// .text:0x000EC014 size:0x7F0 mapped:0x8072B0A8
// 99.92%: the stadium of the playStadiumSound(2) copy sits in r28 in the target, r24 in the base.
void fn_3_EC014(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    MiniGameStruct* minigame;
    u32 count;
    u32 i;
    s32 sym;

    if (lbl_3_common_bss_32724._96 != 0 || g_GameLogic.gameStatus == GAME_STATUS_TRANSITION || task->_1C == 7) {
        if (task->_1C != 0 && task->voice != SND_ID_ERROR) {
            sndFXKeyOff(task->voice);
            sndFXCtrl(task->voice, 7, 0);
            task->voice = SND_ID_ERROR;
        }
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    minigame = &g_Minigame;
    if (g_Minigame._19CE != 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_19988);
        i = 0;
        do {
            g_Minigame._1931[i] = 0;
        } while (++i < 3);
        task->voice = SND_ID_ERROR;
        task->_1C = 1;
        break;
    case 1:
        if (isSpriteDone(task, 0) && lbl_80371C30[task->_14 + 12]._00->_69 == 2) {
            i = 0;
            do {
                lbl_80371C30[task->_14 + 1 + i]._00->_68 = 1;
            } while (++i < 3);
            lbl_80371C30[task->_14 + 13]._00->_68 = 1;
            lbl_80371C30[task->_14 + 14]._00->_68 = 1;
            task->voice = playStadiumSound(2);
            task->_1C = 2;
        }
        break;
    case 2:
        i = 0;
        do {
            if (isSpriteDone(task, 1 + i)) {
                lbl_80371C30[task->_14 + 1 + i]._00->_5C = 0;
                g_Minigame._192A[i]++;
                if (g_Minigame._192A[i] >= 7) {
                    g_Minigame._192A[i] = 0;
                }
                switch (g_Minigame._1931[i]) {
                case 0:
                    if (g_Minigame._1927[i] >= 1) {
                        lbl_80371C30[task->_14 + 1 + i]._00->_64 = 31;
                        g_Minigame._1931[i] = 1;
                    }
                    break;
                case 1:
                    if (g_Minigame._1927[i] >= 2 &&
                        g_Minigame._192E[i] == lbl_3_data_189C4[i][(g_Minigame._192A[i] + 1) % 7]) {
                        lbl_80371C30[task->_14 + 1 + i]._00->_64 = 32;
                        g_Minigame._1931[i] = 2;
                    }
                    break;
                case 2:
                    if (g_Minigame._192E[i] == lbl_3_data_189C4[i][g_Minigame._192A[i]]) {
                        lbl_80371C30[task->_14 + 1 + i]._00->_68 = 0;
                        g_Minigame._1927[i] = 3;
                        playStadiumSound(3);
                        if (i == 2) {
                            sndFXKeyOff(task->voice);
                            sndFXCtrl(task->voice, 7, 0);
                            task->voice = SND_ID_ERROR;
                        }
                        g_Minigame._1931[i] = 3;
                    }
                    break;
                case 3:
                    break;
                }
            }
        } while (++i < 3);
        count = 0;
        i = 0;
        do {
            if (g_Minigame._1931[i] == 3) {
                count++;
            }
        } while (++i < 3);
        if (count >= 3) {
            task->_1C = 3;
        }
        break;
    case 3:
        i = 0;
        do {
            lbl_80371C30[task->_14 + 5 + i]._00->_68 = 1;
        } while (++i < 3);
        switch (g_Minigame._192D) {
        case 0:
        case 3:
        case 4:
        case 5:
            g_Minigame._1934 = 1;
            task->_1C = 4;
            break;
        case 1:
        case 2:
        case 6:
        case 7:
        case 8:
            g_Minigame._1934 = 2;
            task->_1C = 8;
            break;
        }
        break;
    case 4:
        if (lbl_80371C30[task->_14 + 5]._00->_69 == 2) {
            task->_1C = 5;
        }
        break;
    case 5:
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 12]._00->_68 = 4;
        lbl_80371C30[task->_14 + 13]._00->_68 = 4;
        task->_1C = 6;
        break;
    case 6:
        if (getFrame(task, 0) == 0 && getFrame(task, 12) == 0 && getFrame(task, 13) == 0) {
            switch (minigame->_192D) {
            case 0:
                fn_800B0A5C_insertQueue(fn_3_ECD48, 2);
                break;
            case 3:
                fn_800B0A5C_insertQueue(fn_3_EC804, 2)->_18 = 0;
                break;
            case 4:
                fn_800B0A5C_insertQueue(fn_3_EC804, 2)->_18 = 1;
                break;
            case 5:
                fn_800B0A5C_insertQueue(fn_3_ECBB0, 2);
                break;
            }
            task->_1C = 7;
        }
        break;
    case 7:
    case 8:
        break;
    }
    i = 0;
    do {
        sym = lbl_3_data_189C4[i][g_Minigame._192A[i]];
        fn_800363D8(task, i + 5, 1, 33, lbl_3_data_19B88[sym]);
        fn_800363D8(task, i + 5, 2, 34, lbl_3_data_19B88[sym]);
        sym = lbl_3_data_189C4[i][(g_Minigame._192A[i] + 1) % 7];
        fn_800363D8(task, i + 8, 1, 33, lbl_3_data_19B88[sym]);
        fn_800363D8(task, i + 8, 2, 34, lbl_3_data_19B88[sym]);
    } while (++i < 3);
}

// .text:0x000EBFD4 size:0x40 mapped:0x8072B068
u32 fn_3_EBFD4(void) {
    if (lbl_3_common_bss_32724._96 != 0 || g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL ||
        g_GameLogic.gameStatus == GAME_STATUS_TRANSITION) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000EB684 size:0x5C mapped:0x8072A718
u32 fn_3_EB684(void) {
    if (lbl_3_common_bss_32724._96 != 0 || lbl_3_common_bss_32724._B7 != 0) {
        return TRUE;
    }
    if (g_GameLogic.gameStatus != GAME_STATUS_AT_BAT && g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL &&
        g_GameLogic.gameStatus != GAME_STATUS_PAUSED) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000EAEF4 size:0x790 mapped:0x80729F88
void fn_3_EAEF4(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    u32 playSound = 0;
    UnkTask2BF8* t = lbl_803CC1B8;
    u8* flags = g_Minigame._1DF4_u8;
    s32 leader;
    u32 tied;
    u32 n;
    s32 diff;
    s32 step;
    s32 ch;
    u32 i;

    if (fn_3_EB684()) {
        lbl_3_common_bss_32724._D6 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        i = 0;
        do {
            flags[i] = 0;
        } while (++i < 4);
        lbl_3_common_bss_32724._D6 = 1;
        lbl_3_common_bss_32724._B7 = 0;
        fn_80034E20(task, lbl_3_data_1A168);
        i = 0;
        do {
            ch = g_Minigame.minigameControlStruct.characterIndex[i];
            fn_800363D8(task, i + 9, 1, 0x65, ch);
            lbl_80371C30[task->_14 + 0x11 + i]._00->_5C = inMemRoster[0][ch].stats.CharID << 16;
        } while (++i < g_Minigame.miniGameNumberOfParticipants);
        i = 0;
        do {
            lbl_80371C30[task->_14 + 0x29 + i]._00->_54 &= ~2;
        } while (++i < 4);
        task->_1C = 1;
        break;
    case 1:
        g_Minigame._19A0 = 0;
        i = 0;
        do {
            diff = g_Minigame.miniGameCurrentPoints[i] - g_Minigame.minigamePoints_current_Latest[i][0];
            if (diff < 0) {
                g_Minigame._19A0 = 1;
                if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= 10) {
                    step = diff / 8;
                    if (step != 0) {
                        g_Minigame.minigamePoints_current_Latest[i][0] += step;
                    } else {
                        g_Minigame.minigamePoints_current_Latest[i][0] += diff / __abs(diff);
                    }
                }
                playSound = 1;
            }
        } while (++i < g_Minigame.miniGameNumberOfParticipants);
        if (g_Minigame._19A0 == 0) {
            i = 0;
            do {
                if (g_Minigame.miniGameCurrentPoints[i] != g_Minigame.minigamePoints_current_Latest[i][0]) {
                    g_Minigame._19A0 = 1;
                    task->_1C = 2;
                }
            } while (++i < g_Minigame.miniGameNumberOfParticipants);
        }
        break;
    case 2:
        g_Minigame._19A0 = 0;
        i = 0;
        do {
            diff = g_Minigame.miniGameCurrentPoints[i] - g_Minigame.minigamePoints_current_Latest[i][0];
            if (diff > 0) {
                g_Minigame._19A0 = 1;
                t->_24_arr[i] = 1;
                if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= 10) {
                    step = diff / 8;
                    if (step != 0) {
                        g_Minigame.minigamePoints_current_Latest[i][0] += step;
                    } else {
                        g_Minigame.minigamePoints_current_Latest[i][0] += diff / __abs(diff);
                    }
                }
                playSound = 1;
            } else if (diff == 0) {
                if (t->_24_arr[i] != 0) {
                    t->_24_arr[i] = 0;
                    lbl_80371C30[task->_14 + 0x19 + i]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 0x19 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 0x1D + i * 3]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 0x1E + i * 3]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 0x1F + i * 3]._00->_5C = 0;
                }
            }
        } while (++i < g_Minigame.miniGameNumberOfParticipants);
        if (g_Minigame._19A0 == 0) {
            i = 0;
            do {
                if (g_Minigame.miniGameCurrentPoints[i] != g_Minigame.minigamePoints_current_Latest[i][0]) {
                    g_Minigame._19A0 = 1;
                }
            } while (++i < g_Minigame.miniGameNumberOfParticipants);
            task->_1C = 1;
        }
        break;
    }
    if (g_UnkSound_32718._07 == 5) {
        task->_22 = 1;
    }
    lbl_80371C30[task->_14]._00->_64 = lbl_3_data_1A728[g_Minigame._19C6];
    if (task->_22 != 0) {
        lbl_80371C30[task->_14]._00->_68 = 1;
    } else {
        fn_3_125424(task, 0, 10);
    }
    leader = fn_3_107CD0();
    tied = fn_3_107C88();
    i = 0;
    do {
        n = g_Minigame.minigamePoints_current_Latest[i][0];
        if (n > 999) {
            n = 999;
        }
        fn_800363D8(task, 0x1D + i * 3, 1, 0x66, (n % 1000) / 100);
        fn_800363D8(task, 0x1E + i * 3, 1, 0x66, (n % 100) / 10);
        fn_800363D8(task, 0x1F + i * 3, 1, 0x66, n % 10);
        if (tied == 0 && g_Minigame.minigamePoints_current_Latest[i][0] == g_Minigame.minigamePoints_current_Latest[leader][0]) {
            lbl_80371C30[task->_14 + 0x29 + i]._00->_54 |= 2;
        } else {
            lbl_80371C30[task->_14 + 0x29 + i]._00->_54 &= ~2;
        }
    } while (++i < g_Minigame.miniGameNumberOfParticipants);
    i = 0;
    do {
        if (flags[i] != 0) {
            switch (flags[i]) {
            case 1:
                lbl_80371C30[task->_14 + 0xD + i]._00->_64 = 0x60;
                break;
            case 2:
                lbl_80371C30[task->_14 + 0xD + i]._00->_64 = 0x61;
                break;
            }
            lbl_80371C30[task->_14 + 0xD + i]._00->_5C = 0;
            lbl_80371C30[task->_14 + 0xD + i]._00->_68 = 1;
            flags[i] = 0;
        }
    } while (++i < g_Minigame.miniGameNumberOfParticipants);
    if (playSound && g_Minigame._1939 == 0) {
        sndFXStartEx(0x1C0, lbl_800EFBA4[9], 0x3F, 0);
    }
}

// .text:0x000EA8FC size:0x5F8 mapped:0x80729990
// 99.63%: the target keeps i in r21, sign in r22 and points in r23; the base rotates them.
void fn_3_EA8FC(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    u32 i;
    int player;
    s32 sign;
    int points;

    if (task->_18 != 0) {
        if (fn_3_EB684()) {
            lbl_3_common_bss_32724._D6 = 0;
            fn_80034CEC(task);
            fn_800B0A14_removeQueue();
            return;
        }
    } else if (fn_3_EBFD4()) {
        lbl_3_common_bss_32724._D6 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_1A730);
        if (task->_18 != 0) {
            lbl_80371C30[task->_14]._00->_5C = 10 << 16;
        } else {
            lbl_80371C30[task->_14]._00->_64 =
                lbl_3_data_1A158[g_Batter.batterHand + (g_Minigame.miniGameNumberOfParticipants - 1) * 2];
            lbl_80371C30[task->_14]._00->_5C = 10 << 16;
            lbl_80371C30[task->_14 + 1]._00->_64 = 0x58;
            lbl_80371C30[task->_14 + 2]._00->_64 = 0x58;
            lbl_80371C30[task->_14 + 3]._00->_64 = 0x58;
            lbl_80371C30[task->_14 + 4]._00->_64 = 0x58;
        }
        task->_1C = 1;
        break;
    case 1:
        i = 0;
        do {
            if (task->_18 != 0) {
                player = i;
            } else {
                player = g_Minigame.minigameControlStruct
                             ._14[(g_Minigame.turnNumberWithinRound + i) % g_Minigame.miniGameNumberOfParticipants];
            }
            points = g_Minigame.minigamePoints_current_Latest[player][1];
            if (points != 0) {
                if (points < 0) {
                    points *= -1;
                    sign = 89;
                } else {
                    sign = 90;
                }
                if (points > 999) {
                    points = 999;
                }
                if (task->_18 != 0) {
                    if (points >= 100) {
                        lbl_80371C30[task->_14 + 1 + i]._00->_5C = 2 << 16;
                    } else if (points >= 10) {
                        lbl_80371C30[task->_14 + 1 + i]._00->_5C = 1 << 16;
                    } else {
                        lbl_80371C30[task->_14 + 1 + i]._00->_5C = 0 << 16;
                    }
                } else if (points >= 100) {
                    lbl_80371C30[task->_14 + 1 + i]._00->_5C = ((g_Batter.batterHand != 0 ? 0 : 3) + 2) << 16;
                } else if (points >= 10) {
                    lbl_80371C30[task->_14 + 1 + i]._00->_5C = ((g_Batter.batterHand != 0 ? 0 : 3) + 1) << 16;
                } else {
                    lbl_80371C30[task->_14 + 1 + i]._00->_5C = (g_Batter.batterHand != 0 ? 0 : 3) << 16;
                }
                fn_800363D8(task, 5 + i * 4, 1, sign, 11);
                fn_800363D8(task, 6 + i * 4, 1, sign, points % 1000 / 100);
                fn_800363D8(task, 7 + i * 4, 1, sign, points % 100 / 10);
                fn_800363D8(task, 8 + i * 4, 1, sign, points % 10);
                if (g_Minigame._19A0 != 0) {
                    fn_3_125424(task, 5 + i * 4, 8);
                    fn_3_125424(task, 6 + i * 4, 8);
                    fn_3_125424(task, 7 + i * 4, 8);
                    fn_3_125424(task, 8 + i * 4, 8);
                } else {
                    lbl_80371C30[task->_14 + 5 + i * 4]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 6 + i * 4]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 7 + i * 4]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 8 + i * 4]._00->_68 = 1;
                }
            }
        } while (++i < g_Minigame.miniGameNumberOfParticipants);
        break;
    }
}

// .text:0x000EA454 size:0x4A8 mapped:0x807294E8
void fn_3_EA454(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    UnkRank31A0 ranks[4];
    u32 i;
    u32 j;
    s16 points;

    if (lbl_3_common_bss_32724._96 != 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && lbl_3_common_bss_34C90._1D2 == 5) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_MINIGAME_POST_MENU &&
        (lbl_3_common_bss_34C90._1D2 == 7 || g_GameLogic.framesOfExitingToMenu != 0)) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    if (g_GameLogic.gameStatus == 38) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    if (g_GameLogic.gameStatus == 36) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_1A9F0);
        lbl_80371C30[task->_14]._00->_64 = lbl_3_data_1AF70[g_Minigame.GameMode_MiniGame];
        if (g_Minigame.GameMode_MiniGame != 0 && g_Minigame.multiPlayerInd == 0 && g_Minigame._1A3C == 0) {
            if (g_Minigame._190A != 0) {
                lbl_80371C30[task->_14 + 1]._00->_64 = lbl_3_data_1AF88[g_Minigame.soloMinigameDifficulty];
            } else {
                lbl_80371C30[task->_14 + 1]._00->_64 = lbl_3_data_1AF80[g_Minigame.soloMinigameDifficulty];
            }
        } else {
            lbl_80371C30[task->_14 + 1]._00->_64 = 0x175;
        }
        fn_3_1079C8(ranks, 0);
        lbl_80371C30[task->_14 + 2]._00->_64 = lbl_3_data_1AF90[g_Minigame.miniGameNumberOfParticipants - 1];
        i = 0;
        do {
            s32 ch = g_Minigame.minigameControlStruct.characterIndex[i];

            lbl_80371C30[task->_14 + 3 + i]._00->_5C = lbl_3_data_1AF98[g_Minigame.GameMode_MiniGame] << 16;
            lbl_80371C30[task->_14 + 7 + i]._00->_5C = ch << 16;
            if (fn_3_107C40()) {
                lbl_80371C30[task->_14 + 19 + i]._00->_64 = 0x175;
            } else {
                j = 0;
                do {
                    if (i == ranks[j].id) {
                        lbl_80371C30[task->_14 + 19 + i]._00->_64 = lbl_3_data_1AFA8[ranks[j].rank];
                        break;
                    }
                } while (++j < g_Minigame.miniGameNumberOfParticipants);
            }
            points = g_Minigame.miniGameCurrentPoints[i];
            if (points > lbl_80109410[g_Minigame.GameMode_MiniGame]) {
                points = lbl_80109410[g_Minigame.GameMode_MiniGame];
            }
            fn_800363D8(task, 27 + i * 4, 1, 102, points % 10000 / 1000);
            fn_800363D8(task, 28 + i * 4, 1, 102, points % 1000 / 100);
            fn_800363D8(task, 29 + i * 4, 1, 102, points % 100 / 10);
            fn_800363D8(task, 30 + i * 4, 1, 102, points % 10);
        } while (++i < g_Minigame.miniGameNumberOfParticipants);
        task->_1C = 1;
        break;
    case 1:
        break;
    }
}

// .text:0x000EA340 size:0x114 mapped:0x807293D4
void fn_3_EA340(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    int i;

    fn_80034E20(task, lbl_3_data_900C);
    for (i = 0; i < 3; i++) {
        if (g_Minigame.minigameControlStruct._28[i] >= 0) {
            s32 ch = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigameControlStruct._28[i]] << 16;
            lbl_80371C30[task->_14 + 3 + i]._00->_5C = ch;
            lbl_80371C30[task->_14 + 6 + i]._00->_5C = ch;
            lbl_80371C30[task->_14 + 9 + i]._00->_5C =
                inMemRoster[0][g_Minigame.minigameControlStruct._28[i]].stats.CharID << 16;
        }
    }
    task->_18 = 0;
    ((UnkTask2BF8*)lbl_803CC1B8)->_00 = fn_3_E9D30;
}

// .text:0x000E9D30 size:0x610 mapped:0x80728DC4
void fn_3_E9D30(void) {
    UnkTask2BF8* task = lbl_803CC1B8;
    VecXYZ pos;
    int x;
    int y;
    int j;
    int alphaX;
    int alphaY;
    int i;
    int dir;
    int px;
    int py;
    int dx;
    int dz;

    if (lbl_3_common_bss_32724._96 == 0 && g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL && g_Minigame._19CE == 0 &&
        g_Minigame.turnOverStatus == 0) {
        for (i = 0; i < 3; i++) {
            if (g_Minigame.minigameControlStruct._28[i] < 0) {
                continue;
            }
            dir = -1;
            alphaX = 0xFF;
            alphaY = 0xFF;
            getAnimRelatedCoordinates(
                g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigameControlStruct._28[i]], 4, &pos);
            if (!fn_3_1650C(&x, &y, FALSE, pos.x, pos.y, pos.z)) {
                for (j = 0; j < 3; j++) {
                    dx = g_pCamera->_284C.x - pos.x;
                    dz = g_pCamera->_284C.z - pos.z;
                    dx *= 0.2f;
                    dz *= 0.2f;
                    pos.x += dx;
                    pos.z += dz;
                    if (fn_3_1650C(&x, &y, FALSE, pos.x, pos.y, pos.z)) {
                        break;
                    }
                }
            }

            if (x <= (px = lbl_3_data_D638[1])) {
                dir = 2;
                if (x > lbl_3_data_D638[0]) {
                    alphaX = 255.0f * (1.0f - (f32)(x - lbl_3_data_D638[0]) / (f32)(px - lbl_3_data_D638[0]));
                }
            } else if (x >= (px = lbl_3_data_D638[3])) {
                dir = 5;
                if (x < lbl_3_data_D638[2]) {
                    alphaX = 255.0f * (1.0f - (f32)(x - lbl_3_data_D638[2]) / (f32)(px - lbl_3_data_D638[2]));
                }
            } else {
                px = x;
            }
            if (alphaX > 0xFF) {
                alphaX = 0xFF;
            }

            if (y <= (py = lbl_3_data_D638[5])) {
                dir += 1;
                if (y > lbl_3_data_D638[4]) {
                    alphaY = 255.0f * (1.0f - (f32)(y - lbl_3_data_D638[4]) / (f32)(py - lbl_3_data_D638[4]));
                }
            } else if (y >= (py = lbl_3_data_D638[7])) {
                dir += 2;
                if (y < lbl_3_data_D638[6]) {
                    alphaY = 255.0f * (1.0f - (f32)(y - lbl_3_data_D638[6]) / (f32)(py - lbl_3_data_D638[6]));
                }
            } else {
                py = y;
            }
            if (alphaY > 0xFF) {
                alphaY = 0xFF;
            }

            if (dir < 0 || alphaX <= 0 || alphaY <= 0) {
                lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                continue;
            }
            lbl_80371C30[task->_14 + i]._00->_54 |= 2;
            lbl_80371C30[task->_14 + i]._00->_48 = px;
            lbl_80371C30[task->_14 + i]._00->_4C = py;
            if (dir == 2 || dir == 5) {
                lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & ~0xFF) | alphaX;
            } else if (dir >= 2) {
                if (alphaX > alphaY) {
                    lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & ~0xFF) | alphaX;
                } else {
                    lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & ~0xFF) | alphaY;
                }
            } else {
                lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & ~0xFF) | alphaY;
            }
            lbl_80371C30[task->_14 + i]._00->_5C = lbl_3_data_91AC[dir] << 16;
        }
    } else {
        lbl_3_common_bss_32724._97 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}
