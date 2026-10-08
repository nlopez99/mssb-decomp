#include "game/rep_16B8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "game/rep_720.h"

typedef struct UnkTask1770 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16[0x18 - 0x16];
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
    /* 0x1C */ u16 _1C[4];
} UnkTask1770;

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
    /* 0x6A */ u8 _6A[0x72 - 0x6A];
    /* 0x72 */ u16 _72;
} UnkSprite1770;

typedef struct {
    /* 0x00 */ UnkSprite1770* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef1770; // size: 0x8

typedef struct {
    /* 0x0 */ u16 _0;
    /* 0x2 */ u16 _2;
    /* 0x4 */ u16 _4[8];
} UnkLayout16B8; // size: 0x14

typedef struct {
    /* 0x0 */ u16 _0;
    /* 0x2 */ u16 _2;
    /* 0x4 */ u16 _4[7];
} UnkCounts16B8; // size: 0x12

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc1770; // size: 0x20

extern struct {
    /* 0x00 */ u8 _00[0x96];
    /* 0x96 */ u8 _96;
    /* 0x97 */ u8 _97;
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B;
    /* 0x9C */ u8 _9C;
    /* 0x9D */ u8 _9D;
    /* 0x9E */ u8 _9E;
    /* 0x9F */ u8 _9F;
    /* 0xA0 */ u8 _A0;
    /* 0xA1 */ u8 _A1;
    /* 0xA2 */ u8 _A2;
    /* 0xA3 */ u8 _A3;
    /* 0xA4 */ u8 _A4;
    /* 0xA5 */ u8 _A5;
    /* 0xA6 */ u8 _A6;
    /* 0xA7 */ u8 _A7;
    /* 0xA8 */ u8 _A8;
    /* 0xA9 */ u8 _A9;
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB;
    /* 0xAC */ u8 _AC;
    /* 0xAD */ u8 _AD;
    /* 0xAE */ u8 _AE;
    /* 0xAF */ u8 _AF;
    /* 0xB0 */ u8 _B0;
    /* 0xB1 */ u8 _B1;
    /* 0xB2 */ u8 _B2;
    /* 0xB3 */ u8 _B3;
    /* 0xB4 */ u8 _B4;
    /* 0xB5 */ u8 _B5;
    /* 0xB6 */ u8 _B6;
    /* 0xB7 */ u8 _B7;
    /* 0xB8 */ u8 _B8;
    /* 0xB9 */ u8 _B9;
    /* 0xBA */ u8 _BA;
    /* 0xBB */ u8 _BB;
    /* 0xBC */ u8 _BC;
    /* 0xBD */ u8 _BD;
    /* 0xBE */ u8 _BE;
    /* 0xBF */ u8 _BF;
    /* 0xC0 */ u8 _C0;
    /* 0xC1 */ u8 _C1;
    /* 0xC2 */ u8 _C2;
    /* 0xC3 */ u8 _C3;
    /* 0xC4 */ u8 _C4;
    /* 0xC5 */ u8 _C5;
    /* 0xC6 */ u8 _C6;
    /* 0xC7 */ u8 _C7;
    /* 0xC8 */ u8 _C8;
    /* 0xC9 */ u8 _C9;
    /* 0xCA */ u8 _CA;
    /* 0xCB */ u8 _CB;
    /* 0xCC */ u8 _CC;
    /* 0xCD */ u8 _CD;
    /* 0xCE */ u8 _CE;
    /* 0xCF */ u8 _CF;
    /* 0xD0 */ u8 _D0;
    /* 0xD1 */ u8 _D1;
    /* 0xD2 */ u8 _D2;
    /* 0xD3 */ u8 _D3;
    /* 0xD4 */ u8 _D4;
    /* 0xD5 */ u8 _D5;
    /* 0xD6 */ u8 _D6;
    /* 0xD7 */ u8 _D7;
    /* 0xD8 */ u8 _D8;
    /* 0xD9 */ u8 _D9;
    /* 0xDA */ u8 _DA;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x000 */ u8 _000[0x1D0];
    /* 0x1D0 */ u8 _1D0;
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4[0x1D9 - 0x1D4];
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ u8 _1DA[0x221 - 0x1DA];
    /* 0x221 */ u8 _221;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ struct {
        /* 0x0 */ s8 _0;
        /* 0x1 */ s8 _1;
        /* 0x2 */ s8 _2;
        /* 0x3 */ s8 _3;
        /* 0x4 */ s8 _4;
    } _12[9];
    /* 0x3F */ u8 _3F[0x42 - 0x3F];
    /* 0x42 */ s16 _42;
    /* 0x44 */ u8 _44[0x46 - 0x44];
    /* 0x46 */ u8 _46;
    /* 0x47 */ u8 _47;
} lbl_3_common_bss_37400;

extern struct {
    /* 0x00 */ u8 _00[0x26];
    /* 0x26 */ u8 _26;
} lbl_8034E978;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
} g_Scores;

extern struct {
    /* 0x0000 */ u8 _0000[0x46E0];
    /* 0x46E0 */ s32 _46E0;
    /* 0x46E4 */ s32 _46E4;
} lbl_8034E9A0;

typedef struct {
    /* 0x000 */ f32 _000;
    /* 0x004 */ f32 _004;
    /* 0x008 */ f32 _008;
    /* 0x00C */ f32 _00C;
    /* 0x010 */ u8 _010[0x268 - 0x10];
} UnkFielder16B8; // size: 0x268

extern UnkFielder16B8 g_Fielders[9];

extern UnkSpriteRef1770 lbl_80371C30[];
extern void* lbl_803CC1B8;

// Only this unit reads these; they lie outside its splits.txt ranges.
extern struct {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
    /* 0x4 */ s16 _4;
    /* 0x6 */ u8 _6[0x8 - 0x6];
} lbl_3_data_BE50[];
extern UnkSpriteDesc1770 lbl_3_data_8D88[];
extern UnkSpriteDesc1770 lbl_3_data_BF6C[];
extern UnkSpriteDesc1770 lbl_3_data_BFEC[];
extern UnkSpriteDesc1770 lbl_3_data_C1EC[];

extern void fn_80034CEC(UnkTask1770* task);
extern void fn_80034E20(UnkTask1770* task, UnkSpriteDesc1770* desc);
extern void fn_8003649C(UnkTask1770* task, s32, s32, s32, s32);
extern void fn_800B0A14_removeQueue(void);
extern void fn_3_ED0F4(void);
extern void fn_3_ED574(void);
extern void fn_80035CA4(s32 id);
extern void fn_80069A98(void);
extern void fn_800363D8(UnkTask1770* task, s32, s32, s32, u32);
extern void* fn_800B0A5C_insertQueue(void (*)(void), u16);

u16 lbl_3_data_D638[8] = {
    0x0000, 0x0038, 0x0280, 0x0248, 0x0010, 0x0040, 0x01B0, 0x0180
};

UnkSpriteDesc1770 lbl_3_data_D648[11] = {
    { 0, 0xd1, { 0, 0, -1 }, { 1, 2 }, 0xff, { 0x1000000, 0, 0x10000 } },
    { 0, 0xda, { 0, 0, -1 }, { 1, 2 }, 0xff, { 0x1000000, 0, 0x10000 } },
    { 0, 0xbe, { 0, 0, -1 }, { 0, 2 }, 1, { 0x1000000, 0, 0x10000 } },
    { 0, 0xce, { 0, 0, -1 }, { 2, 2 }, 1, { 0x1000000, 0, 0x10001 } },
    { 0, 0xce, { 0, 0, -1 }, { 2, 2 }, 1, { 0x1000000, 0, 0x10001 } },
    { 0, 0xce, { 0, 0, -1 }, { 2, 2 }, 1, { 0x1000000, 0, 0x10001 } },
    { 0, 0xce, { 0, 0, -1 }, { 2, 2 }, 1, { 0x1000000, 0, 0x10001 } },
    { 0, 0xce, { 0, 0, -1 }, { 2, 2 }, 1, { 0x1000000, 0, 0x10001 } },
    { 0, 0xce, { 0, 0, -1 }, { 2, 2 }, 1, { 0x1000000, 0, 0x10001 } },
    { 0, 0xce, { 0, 0, -1 }, { 2, 2 }, 1, { 0x1000000, 0, 0x10001 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkSpriteDesc1770 lbl_3_data_D7A8[2] = {
    { 0, 0xd1, { 0, 0, -1 }, { 1, 8 }, 0xff, { 0x1000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkLayout16B8 lbl_3_data_D7E8[6] = {
    { 214, 191, { 15, 2, 1, 0, 0, 0, 0, 0 } },
    { 213, 190, { 15, 3, 2, 1, 0, 0, 0, 0 } },
    { 215, 192, { 17, 4, 3, 2, 1, 0, 0, 0 } },
    { 216, 192, { 17, 5, 4, 3, 2, 1, 0, 0 } },
    { 217, 193, { 17, 6, 5, 4, 3, 2, 1, 0 } },
    { 218, 194, { 23, 7, 6, 5, 4, 3, 2, 1 } },
};

UnkCounts16B8 lbl_3_data_D860[19] = {
    { 5, 1, { 0, 4, 2, 5, 3, 0, 0 } },
    { 4, 1, { 0, 2, 5, 3, 0, 0, 0 } },
    { 7, 1, { 0, 30, 29, 4, 2, 5, 3 } },
    { 6, 1, { 0, 30, 29, 2, 5, 3, 0 } },
    { 5, 0, { 11, 8, 14, 12, 3, 0, 0 } },
    { 4, 0, { 11, 8, 12, 3, 0, 0, 0 } },
    { 5, 0, { 11, 8, 15, 12, 3, 0, 0 } },
    { 4, 2, { 14, 6, 12, 3, 0, 0, 0 } },
    { 3, 2, { 6, 12, 3, 0, 0, 0, 0 } },
    { 6, 0, { 0, 26, 7, 8, 9, 3, 0 } },
    { 5, 2, { 6, 13, 15, 9, 3, 0, 0 } },
    { 5, 2, { 27, 6, 15, 9, 3, 0, 0 } },
    { 4, 2, { 6, 15, 9, 3, 0, 0, 0 } },
    { 5, 0, { 0, 7, 8, 17, 3, 0, 0 } },
    { 3, 2, { 16, 17, 3, 0, 0, 0, 0 } },
    { 4, 2, { 6, 15, 17, 3, 0, 0, 0 } },
    { 4, 0, { 0, 7, 8, 18, 0, 0, 0 } },
    { 4, 1, { 0, 7, 8, 3, 0, 0, 0 } },
    { 3, 2, { 6, 15, 3, 0, 0, 0, 0 } },
};

u32 lbl_3_data_D9B8[11] = {
    0x060A0000, 0x00000006, 0x080A0000, 0x00000608, 0x0A0C0000, 0x0006080A, 0x0C0E0000, 0x06080A0C,
    0x0E110006, 0x080A0C0E, 0x11170000
};

UnkSpriteDesc1770 lbl_3_data_D9E4[3] = {
    { 0, 12, { 0, 0, -1 }, { 0, 5 }, 0xff, { 0x13000000, 0, 0x10000 } },
    { 0, 11, { 0, 0, -1 }, { 0, 5 }, 0, { 0x13000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

u16 lbl_3_data_DA44[2][3] = {
    { 1, 0, 2 },
    { 3, 0, 4 },
};

UnkSpriteDesc1770 lbl_3_data_DA50[52] = {
    { 0, 1, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x1000000, 0, 0x10000 } },
    { 0, 0x16, { 0, 0, -1 }, { 1, 5 }, 0, { 0x1000000, 0, 0x10000 } },
    { 0, 0x11d, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x1000000, 0, 0x10000 } },
    { 0, 0x114, { 0, 0, -1 }, { 1, 5 }, 2, { 0x1000000, 0, 0x10001 } },
    { 0, 0x11c, { 0, 0, -1 }, { 0, 5 }, 2, { 0x1000000, 0, 0x10001 } },
    { 0, 0x113, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10003 } },
    { 0, 0x113, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10002 } },
    { 0, 0x113, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10001 } },
    { 0, 0x113, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10000 } },
    { 0, 0x115, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10003 } },
    { 0, 0x115, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10002 } },
    { 0, 0x115, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10001 } },
    { 0, 0x115, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10000 } },
    { 0, 0x119, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10003 } },
    { 0, 0x119, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10002 } },
    { 0, 0x119, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10001 } },
    { 0, 0x119, { 0, 0, -1 }, { 0, 5 }, 3, { 0x1000000, 0, 0x10000 } },
    { 0, 0x117, { 0, 0, -1 }, { 1, 5 }, 13, { 0x1000000, 0, 0x10001 } },
    { 0, 0x117, { 0, 0, -1 }, { 1, 5 }, 14, { 0x1000000, 0, 0x10001 } },
    { 0, 0x117, { 0, 0, -1 }, { 1, 5 }, 15, { 0x1000000, 0, 0x10001 } },
    { 0, 0x117, { 0, 0, -1 }, { 1, 5 }, 0x10, { 0x1000000, 0, 0x10001 } },
    { 0, 0x118, { 0, 0, -1 }, { 1, 5 }, 13, { 0x1000000, 0, 0x10000 } },
    { 0, 0x118, { 0, 0, -1 }, { 1, 5 }, 14, { 0x1000000, 0, 0x10000 } },
    { 0, 0x118, { 0, 0, -1 }, { 1, 5 }, 15, { 0x1000000, 0, 0x10000 } },
    { 0, 0x118, { 0, 0, -1 }, { 1, 5 }, 0x10, { 0x1000000, 0, 0x10000 } },
    { 0, 0x112, { 0, 0, -1 }, { 1, 5 }, 2, { 0x1000000, 0, 0x10001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 5 }, 0x19, { 0x1000000, 0, 0x10000 } },
    { 0, 0x114, { 0, 0, -1 }, { 1, 5 }, 2, { 0x1000000, 0, 0x10000 } },
    { 0, 0x11c, { 0, 0, -1 }, { 0, 5 }, 2, { 0x1000000, 0, 0x10000 } },
    { 0, 0x113, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10003 } },
    { 0, 0x113, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10002 } },
    { 0, 0x113, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10001 } },
    { 0, 0x113, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10000 } },
    { 0, 0x115, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10003 } },
    { 0, 0x115, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10002 } },
    { 0, 0x115, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10001 } },
    { 0, 0x115, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10000 } },
    { 0, 0x119, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10003 } },
    { 0, 0x119, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10002 } },
    { 0, 0x119, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10001 } },
    { 0, 0x119, { 0, 0, -1 }, { 0, 5 }, 0x1b, { 0x1000000, 0, 0x10000 } },
    { 0, 0x117, { 0, 0, -1 }, { 1, 5 }, 0x25, { 0x1000000, 0, 0x10001 } },
    { 0, 0x117, { 0, 0, -1 }, { 1, 5 }, 0x26, { 0x1000000, 0, 0x10001 } },
    { 0, 0x117, { 0, 0, -1 }, { 1, 5 }, 0x27, { 0x1000000, 0, 0x10001 } },
    { 0, 0x117, { 0, 0, -1 }, { 1, 5 }, 0x28, { 0x1000000, 0, 0x10001 } },
    { 0, 0x118, { 0, 0, -1 }, { 1, 5 }, 0x25, { 0x1000000, 0, 0x10000 } },
    { 0, 0x118, { 0, 0, -1 }, { 1, 5 }, 0x26, { 0x1000000, 0, 0x10000 } },
    { 0, 0x118, { 0, 0, -1 }, { 1, 5 }, 0x27, { 0x1000000, 0, 0x10000 } },
    { 0, 0x118, { 0, 0, -1 }, { 1, 5 }, 0x28, { 0x1000000, 0, 0x10000 } },
    { 0, 0x112, { 0, 0, -1 }, { 1, 5 }, 2, { 0x1000000, 0, 0x10000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 5 }, 0x31, { 0x1000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

u16 lbl_3_data_E0D0[8] = {
    0x0001, 0x0000, 0x0001, 0x000E, 0x0001, 0x000E, 0x0003, 0x0002
};

UnkSpriteDesc1770 lbl_3_data_E0E0[2] = {
    { 0, 0x35, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkSpriteDesc1770 lbl_3_data_E120[2] = {
    { 0, 0x9f, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkSpriteDesc1770 lbl_3_data_E160[5] = {
    { 0, 0x5b, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x5c, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x65, { 0, 0, -1 }, { 0, 4 }, 1, { 0x2000000, 0, 0x10000 } },
    { 0, 0x65, { 0, 0, -1 }, { 0, 4 }, 1, { 0x2000000, 0, 0x10001 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

u16 lbl_3_data_E200[14] = { 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0 };

UnkSpriteDesc1770 lbl_3_data_E21C[2] = {
    { 0, 0x59, { 0, 0, -1 }, { 0, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

u8 lbl_3_data_E25C[0x1C] = {
    0x06, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x02, 0xFF, 0xFF, 0xFF, 0x05, 0x06, 0x07, 0xFF,
    0xFF, 0x00, 0x01, 0x02, 0x03, 0xFF, 0x04, 0x05, 0x06, 0x07, 0x08, 0x00, 0x00, 0x00,
};

UnkSpriteDesc1770 lbl_3_data_E278[4] = {
    { 0, 0x5d, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x5e, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x65, { 0, 0, -1 }, { 0, 4 }, 1, { 0x2000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkSpriteDesc1770 lbl_3_data_E2F8[4] = {
    { 0, 0x66, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x67, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x65, { 0, 0, -1 }, { 0, 5 }, 1, { 0x2000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkSpriteDesc1770 lbl_3_data_E378[31] = {
    { 0, 0x60, { 0, 0, -1 }, { 0, 3 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x62, { 0, 0, -1 }, { 0, 3 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x61, { 0, 0, -1 }, { 0, 3 }, 1, { 0x2000000, 0, 0x10003 } },
    { 0, 0x61, { 0, 0, -1 }, { 0, 3 }, 1, { 0x2000000, 0, 0x10002 } },
    { 0, 0x61, { 0, 0, -1 }, { 0, 3 }, 1, { 0x2000000, 0, 0x10001 } },
    { 0, 0x61, { 0, 0, -1 }, { 0, 3 }, 1, { 0x2000000, 0, 0x10000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 3 }, 2, { 0x1000000, 0, 0x10000 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 2, { 0x2000000, 0, 0x10005 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 2, { 0x2000000, 0, 0x10004 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 2, { 0x2000000, 0, 0x10003 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 2, { 0x2000000, 0, 0x10002 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 2, { 0x2000000, 0, 0x10001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 3 }, 3, { 0x1000000, 0, 0x10000 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 3, { 0x2000000, 0, 0x10005 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 3, { 0x2000000, 0, 0x10004 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 3, { 0x2000000, 0, 0x10003 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 3, { 0x2000000, 0, 0x10002 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 3, { 0x2000000, 0, 0x10001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 3 }, 4, { 0x1000000, 0, 0x10000 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 4, { 0x2000000, 0, 0x10005 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 4, { 0x2000000, 0, 0x10004 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 4, { 0x2000000, 0, 0x10003 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 4, { 0x2000000, 0, 0x10002 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 4, { 0x2000000, 0, 0x10001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 3 }, 5, { 0x1000000, 0, 0x10000 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 5, { 0x2000000, 0, 0x10005 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 5, { 0x2000000, 0, 0x10004 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 5, { 0x2000000, 0, 0x10003 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 5, { 0x2000000, 0, 0x10002 } },
    { 0, 0x5f, { 0, 0, -1 }, { 0, 3 }, 5, { 0x2000000, 0, 0x10001 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

u8 lbl_3_data_E758[4] = { 6, 12, 18, 24 };

UnkSpriteDesc1770 lbl_3_data_E75C[8] = {
    { 0, 0xb7, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xb3, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xb4, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0, { 0, 0, -1 }, { 0, 5 }, 1, { 0xf000000, 0, 0x10000 } },
    { 0, 0, { 0, 0, -1 }, { 0, 5 }, 2, { 0x10000000, 0, 0x10000 } },
    { 0, 0xb5, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xb6, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkSpriteDesc1770 lbl_3_data_E85C[19] = {
    { 0, 0xe1, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xec, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10003 } },
    { 0, 0xed, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10002 } },
    { 0, 1, { 0, 0, -1 }, { 0, 5 }, 1, { 0xf000000, 0, 0x10000 } },
    { 0, 1, { 0, 0, -1 }, { 0, 5 }, 1, { 0xf000000, 0, 0x10001 } },
    { 0, 1, { 0, 0, -1 }, { 0, 5 }, 1, { 0xf000000, 0, 0x10002 } },
    { 0, 1, { 0, 0, -1 }, { 0, 5 }, 2, { 0x10000000, 0, 0x10000 } },
    { 0, 1, { 0, 0, -1 }, { 0, 5 }, 2, { 0x10000000, 0, 0x10001 } },
    { 0, 1, { 0, 0, -1 }, { 0, 5 }, 2, { 0x10000000, 0, 0x10002 } },
    { 0, 0xe5, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10006 } },
    { 0, 0xeb, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10008 } },
    { 0, 0xeb, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10007 } },
    { 0, 0xeb, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10005 } },
    { 0, 0xeb, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10004 } },
    { 0, 0xe7, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10009 } },
    { 0, 0xb9, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10000 } },
    { 0, 0xb9, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x10001 } },
    { 0, 0xe2, { 0, 0, -1 }, { 1, 5 }, 0, { 0x2000000, 0, 0x1000a } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkSpriteDesc1770 lbl_3_data_EABC[11] = {
    { 0, 0xf5, { 0, 0, -1 }, { 0, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xf3, { 0, 0, -1 }, { 0, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 1, { 0, 0, -1 }, { 0, 5 }, 1, { 0xf000000, 0, 0x10001 } },
    { 0, 1, { 0, 0, -1 }, { 0, 5 }, 1, { 0x10000000, 0, 0x10000 } },
    { 0, 0xf4, { 0, 0, -1 }, { 0, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xf4, { 0, 0, -1 }, { 2, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xf4, { 0, 0, -1 }, { 2, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xf4, { 0, 0, -1 }, { 0, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xf4, { 0, 0, -1 }, { 2, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0xf4, { 0, 0, -1 }, { 2, 5 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

u32 lbl_3_data_EC1C[377] = {
    0x0000000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010500FF, 0x02000000, 0x00000000, 0x00010000,
    0x00000001, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00050000, 0x0F000000, 0x00000000, 0x00010001,
    0x00000001, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00050000, 0x10000000, 0x00000000, 0x00010000,
    0x0000000D, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010500FF, 0x02000000, 0x00000000, 0x00010000,
    0x0000000F, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010500FF, 0x02000000, 0x00000000, 0x00010000,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x02050004, 0x02000000, 0x00000000, 0x00010005,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x02050004, 0x02000000, 0x00000000, 0x00010003,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x02050004, 0x02000000, 0x00000000, 0x00010004,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x02050004, 0x02000000, 0x00000000, 0x00010002,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x02050004, 0x02000000, 0x00000000, 0x00010001,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x02050004, 0x02000000, 0x00000000, 0x00010000,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01050004, 0x02000000, 0x00000000, 0x00010005,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01050004, 0x02000000, 0x00000000, 0x00010003,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01050004, 0x02000000, 0x00000000, 0x00010004,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01050004, 0x02000000, 0x00000000, 0x00010002,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01050004, 0x02000000, 0x00000000, 0x00010001,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01050004, 0x02000000, 0x00000000, 0x00010000,
    0x00030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000000C6, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010700FF, 0x02000000, 0x00000000, 0x00010000,
    0x000000C1, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010700FF, 0x02000000, 0x00000000, 0x00010000,
    0x000000D2, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060001, 0x02000000, 0x00000000, 0x0001000F,
    0x000000D2, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060001, 0x02000000, 0x00000000, 0x0001000E,
    0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00060002, 0x0F000000, 0x00000000, 0x00010000,
    0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00060003, 0x10000000, 0x00000000, 0x00010000,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x0001000D,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x0001000C,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x0001000B,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x0001000A,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010009,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010000,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010000,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010000,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010000,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010008,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010007,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010006,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010005,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010004,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010003,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010002,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010000,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010000,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010000,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010000,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010001,
    0x000000C3, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x03060001, 0x02000000, 0x00000000, 0x00010000,
    0x00030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00C200C3
};

u8 lbl_3_data_F200[36] = {
    0x05, 0x07, 0x0B, 0x09, 0x0D, 0x11, 0x0F, 0x13, 0x15, 0x17, 0x19, 0x00, 0x17, 0x15, 0x14, 0x13,
    0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x16, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04,
    0x03, 0x02, 0x01, 0x00
};

UnkSpriteDesc1770 lbl_3_data_F224[9] = {
    { 0, 0x3e, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 11, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x40, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x42, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x43, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 4 }, 2, { 0x1000000, 0, 0x10000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 4 }, 3, { 0x1000000, 0, 0x10000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0, 4 }, 4, { 0x1000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

u16 lbl_3_data_F344[6] = { 0x41, 0x42, 0x41, 0x42, 0x41, 0x42 };

UnkSpriteDesc1770 lbl_3_data_F350[2] = {
    { 0, 0xb1, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkSpriteDesc1770 lbl_3_data_F390[3] = {
    { 0, 0xb0, { 0, 0, -1 }, { 1, 5 }, 0xff, { 0x2000000, 0, 0 } },
    { 0, 0xb2, { 0, 0, -1 }, { 3, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

UnkSpriteDesc1770 lbl_3_data_F3F0[2] = {
    { 0, 0x6d, { 0, 0, -1 }, { 1, 4 }, 0xff, { 0x2000000, 0, 0x10000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};

u8 lbl_3_data_F430[12][2] = {
    { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 },
    { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 },
};


// .text:0x00098DE0 size:0xC8 mapped:0x806D7E74
void fn_3_98DE0(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_D7A8);
    if (g_d_GameSettings.minigamesEnabled) {
        lbl_80371C30[task->_14]._00->_67 = 5;
    } else if (g_d_GameSettings.GameModeSelected == 2) {
        lbl_80371C30[task->_14]._00->_67 = 6;
    }
    lbl_3_common_bss_32724._AA = 1;
    task->_1C[0] = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_98C20;
}

// .text:0x00098C20 size:0x1C0 mapped:0x806D7CB4
void fn_3_98C20(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0) {
        goto kill;
    }
    if (task->_1C[0] == 0) {
        task->_1C[0] = 1;
    } else if (task->_1C[0] == 1) {
        if (g_d_GameSettings.GameModeSelected == 2) {
            if (!g_Practice._19F) {
                goto kill;
            }
            if (lbl_3_common_bss_34C90._1D2 == 4) {
                task->_1C[0] = 2;
            }
        } else if (g_d_GameSettings.minigamesEnabled) {
            if (g_GameLogic.gameStatus == 11 && lbl_3_common_bss_34C90._1D2 == 4) {
                task->_1C[0] = 2;
            }
            if (g_d_GameSettings.GameModeSelected == 7) {
                if (lbl_3_common_bss_34C90._1D2 == 4) {
                    task->_1C[0] = 2;
                }
                if (lbl_3_common_bss_34C90._1D2 == 7) {
                    goto kill;
                }
                if (lbl_3_common_bss_34C90._1D2 == 13) {
                    goto kill;
                }
            }
        } else {
            if ((lbl_3_common_bss_34C90._1D1 == 2 || lbl_3_common_bss_34C90._1D1 == 9) &&
                lbl_3_common_bss_34C90._1D2 == 4)
            {
                goto kill;
            }
            if (lbl_3_common_bss_34C90._1D9 == 2) {
                goto kill;
            }
        }
    } else if (task->_1C[0] == 2) {
        lbl_80371C30[task->_14]._00->_68 = 4;
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) == 0) {
            goto kill;
        }
    }
    return;

kill:
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
    lbl_3_common_bss_32724._AA = 0;
}

// .text:0x0009894C size:0x2D4 mapped:0x806D79E0
// 87.43%: the base reaches lbl_3_data_D648, D7E8 and D860 from one pooled
// ...data.0 base where the target names each (95.97% with the three as externs).
void fn_3_9894C(void) {
    UnkTask1770* task = lbl_803CC1B8;
    UnkLayout16B8* layout;
    s32 i;
    u16 count;
    u16 icon;

    fn_80034E20(task, lbl_3_data_D648);
    if ((!g_d_GameSettings.minigamesEnabled && g_GameLogic.gameStatus == 11) ||
        (g_d_GameSettings.GameModeSelected == 6 && g_GameLogic.gameStatus == 11) ||
        (g_d_GameSettings.GameModeSelected == 7 && g_Minigame.pauseInd != 0))
    {
        lbl_80371C30[task->_14]._00->_54 &= ~2;
    }
    count = lbl_3_data_D860[lbl_3_common_bss_34C90._1D0]._0;
    layout = &lbl_3_data_D7E8[count - 2];
    lbl_80371C30[task->_14 + 1]._00->_64 = layout->_0;
    lbl_80371C30[task->_14 + 2]._00->_64 = layout->_2;
    lbl_80371C30[task->_14 + 2]._00->_5C = lbl_3_data_D860[lbl_3_common_bss_34C90._1D0]._2 << 16;
    for (i = 0; i < count; i++) {
        lbl_80371C30[task->_14 + 3 + i]._00->_72 = layout->_4[i + 1];
        lbl_80371C30[task->_14 + 3 + i]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 3 + i]._00->_68 = 1;
        icon = lbl_3_data_D860[lbl_3_common_bss_34C90._1D0]._4[i];
        if (!g_d_GameSettings.exhibitionMatchInd && icon == 3) {
            icon = 18;
        }
        fn_800363D8(task, i + 3, 1, 0xCF, icon);
    }
    if (g_d_GameSettings.GameModeSelected == 2) {
        if (g_Practice._19F) {
            lbl_80371C30[task->_14]._00->_54 &= ~2;
        } else if (g_Practice._1C7) {
            lbl_80371C30[task->_14]._00->_67 = 5;
        }
    }
    lbl_3_common_bss_34C90._1D9 = 0;
    task->_1C[0] = 0;
    task->_1C[1] = count;
    task->_1C[2] = 0xFF;
    task->_18 = 0;
    lbl_3_common_bss_32724._AB = 1;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_98434;
}

// .text:0x00098434 size:0x518 mapped:0x806D74C8
void fn_3_98434(void) {
    return;
}

// .text:0x000983B8 size:0x7C mapped:0x806D744C
void fn_3_983B8(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_D9E4);
    lbl_3_common_bss_32724._C3 = 0;
    task->_1C[0] = 0;
    task->_1C[1] = lbl_3_common_bss_34C90._221;
    task->_1C[2] = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_98028;
}

// .text:0x00098028 size:0x390 mapped:0x806D70BC
void fn_3_98028(void) {
    UnkTask1770* task = lbl_803CC1B8;
    UnkSprite1770* sprite;
    s32 row = 0;
    s32 done;
    u8 state;

    if (lbl_3_common_bss_32724._96 != 0) {
        goto kill;
    }
    state = lbl_3_common_bss_34C90._1D2;
    if (state == 6) {
        goto kill;
    }
    if (gameInitOptions.starSkillsSetting == 0 && g_d_GameSettings.GameModeSelected != 2) {
        row = 1;
    }
    if (task->_1C[0] == 0) {
        lbl_80371C30[task->_14 + 1]._00->_5C = lbl_3_data_DA44[row][task->_1C[1]] << 16;
        if (task->_1C[2] == 0) {
            lbl_80371C30[task->_14]._00->_5C = 0;
            lbl_80371C30[task->_14]._00->_68 = 1;
        } else {
            lbl_80371C30[task->_14]._00->_5C = 15 << 16;
            lbl_80371C30[task->_14]._00->_68 = 4;
        }
        lbl_3_common_bss_32724._C3 = 1;
        task->_1C[0]++;
    } else if (task->_1C[0] == 1) {
        if (task->_1C[2] == 0) {
            sprite = lbl_80371C30[task->_14]._00;
            if ((sprite->_5C >> 16) >= 8) {
                sprite->_68 = 0;
                task->_1C[0]++;
            }
        } else {
            sprite = lbl_80371C30[task->_14]._00;
            if ((sprite->_5C >> 16) <= 8) {
                sprite->_68 = 0;
                task->_1C[0]++;
            }
        }
        lbl_3_common_bss_32724._C3 = 1;
    } else if (task->_1C[0] == 2) {
        lbl_3_common_bss_32724._C3 = 0;
        if ((g_d_GameSettings.GameModeSelected == 2 && lbl_3_common_bss_34C90._1D3 == 6) ||
            (g_d_GameSettings.GameModeSelected != 2 && state == 5))
        {
            lbl_80371C30[task->_14]._00->_68 = 1;
            task->_1C[2] = 0;
            task->_1C[0] = 4;
        } else if (lbl_3_common_bss_34C90._221 != task->_1C[1]) {
            task->_1C[1] = lbl_3_common_bss_34C90._221;
            lbl_80371C30[task->_14 + 1]._00->_5C = lbl_3_data_DA44[row][task->_1C[1]] << 16;
        }
    } else {
        lbl_3_common_bss_32724._C3 = 1;
        done = 0;
        if (task->_1C[2] == 0) {
            if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= 15) {
                done = 1;
            }
        } else if ((lbl_80371C30[task->_14]._00->_5C >> 16) == 0) {
            done = 1;
        }
        if (done) {
            task->_1C[1] = lbl_3_common_bss_34C90._221;
            lbl_80371C30[task->_14]._00->_68 = 0;
            if (task->_1C[0] != 3) {
                goto kill;
            }
            task->_1C[0] = 0;
        }
    }
    return;

kill:
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
    lbl_3_common_bss_32724._C3 = 0;
}

// .text:0x00097CEC size:0x33C mapped:0x806D6D80
void fn_3_97CEC(void) {
    UnkTask1770* task = lbl_803CC1B8;
    s32 i;
    s32 base;
    u32 logo;

    fn_80034E20(task, lbl_3_data_DA50);
    for (i = 0; i < 2; i++) {
        if (g_GameLogic._13E[i] != 0) {
            logo = g_GameLogic.teams[i] + 4;
        } else {
            logo = g_GameLogic.teams[i];
        }
        if (i == 0) {
            fn_800363D8(task, 4, 1, 70, logo);
        } else {
            fn_800363D8(task, 28, 1, 70, logo);
        }
    }
    for (i = 0; i < 4; i++) {
        fn_800363D8(task, i + 5, 1, 282, i);
        fn_800363D8(task, i + 29, 1, 282, i);
    }
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            base = 9;
        } else {
            base = 33;
        }
        fn_800363D8(task, base, 1, 278, lbl_3_data_E0D0[0]);
        fn_800363D8(task, base, 2, 278, lbl_3_data_E0D0[1]);
        if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].easyBatting) {
            lbl_80371C30[task->_14 + base]._00->_5C = 10 << 16;
        }
        fn_800363D8(task, base + 1, 1, 278, lbl_3_data_E0D0[2]);
        fn_800363D8(task, base + 1, 2, 278, lbl_3_data_E0D0[3]);
        if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoFielding) {
            lbl_80371C30[base + 1 + task->_14]._00->_5C = 10 << 16;
        }
        fn_800363D8(task, base + 2, 1, 278, lbl_3_data_E0D0[4]);
        fn_800363D8(task, base + 2, 2, 278, lbl_3_data_E0D0[5]);
        if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoRunning) {
            lbl_80371C30[base + 2 + task->_14]._00->_5C = 10 << 16;
        }
        fn_800363D8(task, base + 3, 1, 278, lbl_3_data_E0D0[7]);
        fn_800363D8(task, base + 3, 2, 278, lbl_3_data_E0D0[6]);
        if (!gameInitOptions.controlOptions[g_GameLogic.teams[i]].dropSpot) {
            lbl_80371C30[base + 3 + task->_14]._00->_5C = 10 << 16;
        }
    }
    lbl_80371C30[task->_14 + 26]._00->_5C = lbl_8034E9A0._46E0 << 16;
    lbl_80371C30[task->_14 + 50]._00->_5C = lbl_8034E9A0._46E4 << 16;
    task->_18 = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_978DC;
}

// .text:0x000978DC size:0x410 mapped:0x806D6970
void fn_3_978DC(void) {
    return;
}

// .text:0x00097800 size:0xDC mapped:0x806D6894
void fn_3_97800(void) {
    lbl_3_common_bss_32724._96 = 0;
    lbl_3_common_bss_32724._A5 = 0;
    lbl_3_common_bss_32724._97 = 0;
    lbl_3_common_bss_32724._A8 = 0;
    lbl_3_common_bss_32724._98 = 0;
    lbl_3_common_bss_32724._99 = 0;
    lbl_3_common_bss_32724._D1 = 0;
    lbl_3_common_bss_32724._AD = 0;
    lbl_3_common_bss_32724._AE = 0;
    lbl_3_common_bss_32724._B0 = 0;
    lbl_3_common_bss_32724._B1 = 0;
    lbl_3_common_bss_32724._B2 = 0;
    lbl_3_common_bss_32724._C7 = 0;
    lbl_3_common_bss_32724._D6 = 0;
    lbl_3_common_bss_32724._B6 = 0;
    lbl_3_common_bss_32724._D9 = 0;
    lbl_3_common_bss_32724._DA = 0;
    lbl_3_common_bss_32724._BC = 0;
    lbl_3_common_bss_32724._C0 = 0;
    lbl_3_common_bss_32724._C1 = 0;
    lbl_3_common_bss_32724._C2 = 0;
    lbl_3_common_bss_32724._C6 = 0;
    lbl_3_common_bss_32724._AA = 0;
    lbl_3_common_bss_32724._AB = 0;
    lbl_3_common_bss_32724._C3 = 0;
    lbl_3_common_bss_32724._C4 = 0;
    lbl_3_common_bss_32724._BE = 0;
    lbl_3_common_bss_32724._BF = 0;
    lbl_3_common_bss_32724._B3 = 0;
    lbl_3_common_bss_32724._B4 = 0;
    lbl_3_common_bss_32724._B5 = 0;
    lbl_3_common_bss_32724._C5 = 0;
    if (!g_d_GameSettings.minigamesEnabled) {
        fn_800B0A5C_insertQueue(fn_3_95970, 2);
    }
    fn_800B0A5C_insertQueue(fn_3_91A60, 2);
}

// .text:0x000973EC size:0x414 mapped:0x806D6480
void fn_3_973EC(void) {
    return;
}

// .text:0x000972C8 size:0x124 mapped:0x806D635C
void fn_3_972C8(void) {
    lbl_3_common_bss_32724._96 = 1;
    if (g_d_GameSettings.GameModeSelected == 4) {
        fn_80069A98();
        fn_80035CA4(0x16);
    }
    if (g_d_GameSettings.GameModeSelected == 0 || g_d_GameSettings.GameModeSelected == 5 ||
        g_d_GameSettings.GameModeSelected == 4)
    {
        fn_80035CA4(0x10);
        fn_80035CA4(0xF);
    }
    fn_80035CA4(2);
    fn_80035CA4(5);
    fn_80035CA4(4);
    if (g_d_GameSettings.minigamesEnabled) {
        fn_80035CA4(0x14);
        if (g_d_GameSettings.GameModeSelected == 6) {
            fn_80035CA4(0xE);
        }
        fn_80035CA4(3);
        fn_80035CA4(9);
        fn_80035CA4(0xD);
        fn_80035CA4(0x11);
    } else if (g_d_GameSettings.GameModeSelected == 2) {
        fn_80035CA4(0xB);
        fn_80035CA4(9);
    }
    if (lbl_3_common_bss_32724._D1 != 0) {
        fn_80035CA4(0xC);
    }
}

// .text:0x000972A0 size:0x28 mapped:0x806D6334
void fn_3_972A0(UnkTask1770* task, s32 arg1, s32 arg2, s32 arg3) {
    fn_8003649C(task, arg1, arg2, 0x28, arg3);
}

// .text:0x00097144 size:0x15C mapped:0x806D61D8
void fn_3_97144(void) {
    s32 started = 0;

    if (g_GameLogic.gameStatus == 3 || (u8)(g_GameLogic.gameStatus - 0x13) <= 4 ||
        g_GameLogic.gameStatus == 0x18)
    {
        g_UnkSound_32718._02 = 0;
        g_UnkSound_32718._03 = 0;
        g_UnkSound_32718._04 = 0;
        g_UnkSound_32718._05 = 0;
        g_UnkSound_32718._06 = 0;
        return;
    }
    if (g_UnkSound_32718._07 == 0) {
        if (g_UnkSound_32718._02 != 0) {
            if (g_Stats.replayInd == 0) {
                started = 1;
                g_UnkSound_32718._07 = g_UnkSound_32718._02;
                g_UnkSound_32718._02 = g_UnkSound_32718._03;
                g_UnkSound_32718._03 = g_UnkSound_32718._04;
                g_UnkSound_32718._04 = g_UnkSound_32718._05;
                g_UnkSound_32718._05 = g_UnkSound_32718._06;
                g_UnkSound_32718._06 = 0;
                g_UnkSound_32718._00 = 0;
            }
            sndFXKeyOff(lbl_3_common_bss_34C58._1C);
        }
    } else {
        g_UnkSound_32718._00++;
        if (g_UnkSound_32718._02 != 0 && g_UnkSound_32718._00 < 60) {
            g_UnkSound_32718._00 = 60;
        }
    }
    if (lbl_3_data_BE50[g_UnkSound_32718._07]._0 >= 0 && started) {
        fn_800B0A5C_insertQueue(fn_3_96CA4, 2);
    }
}

// .text:0x00096CA4 size:0x4A0 mapped:0x806D5D38
void fn_3_96CA4(void) {
    return;
}

// .text:0x0009698C size:0x318 mapped:0x806D5A20
void fn_3_9698C(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (task->_18 < 0xFFFE) {
        task->_18++;
    } else {
        task->_18 = 0xFFFF;
    }
    if (lbl_3_common_bss_32724._96 != 0 || g_Stats.replayInd != 0) {
        goto kill;
    }
    if (task->_1C[0] == 15) {
        if (lbl_80371C30[task->_14]._00->_69 == 2) {
            if (g_d_GameSettings.GameModeSelected == 6) {
                fn_800B0A5C_insertQueue(fn_3_ED0F4, 2);
            }
            goto kill;
        }
        if (g_GameLogic.gameStatus == 2) {
        } else if (g_GameLogic.gameStatus == 1) {
        } else if (g_GameLogic.gameStatus == 0) {
        } else if (g_GameLogic.gameStatus != 20) {
            goto kill;
        }
    } else if (task->_1C[1] == 2) {
        if (lbl_80371C30[task->_14]._00->_69 == 2) {
            goto kill;
        }
        if (g_GameLogic.hudElementLoadingInd != 0) {
            goto kill;
        }
        if (g_GameLogic.gameStatus == 2) {
        } else if (g_GameLogic.gameStatus == 1) {
        } else if (g_GameLogic.gameStatus != 0) {
            goto kill;
        }
    } else if (task->_1C[1] == 1) {
        if (g_GameLogic.hudElementLoadingInd != 0) {
            goto kill;
        }
        if (g_GameLogic.gameStatus == 2) {
        } else if (g_GameLogic.gameStatus == 1) {
        } else if (g_GameLogic.gameStatus == 0) {
        } else {
            goto kill;
        }
    }
    if (task->_1C[1] == 0) {
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= lbl_3_data_BE50[task->_1C[0]]._2) {
            task->_1C[1] = 1;
            lbl_80371C30[task->_14]._00->_68 = 0;
        }
    } else if (task->_1C[1] == 1) {
        if (g_UnkSound_32718._02 != 0 || (!g_d_GameSettings.exhibitionMatchInd && lbl_3_common_bss_32724._B4 != 0)) {
            lbl_80371C30[task->_14]._00->_68 = 1;
            task->_1C[1] = 2;
        } else {
            if (task->_1A < 0xFFFE) {
                task->_1A++;
            } else {
                task->_1A = 0xFFFF;
            }
            if (task->_1A >= lbl_3_data_BE50[task->_1C[0]]._4) {
                lbl_80371C30[task->_14]._00->_68 = 1;
                task->_1C[1] = 2;
            }
        }
    }
    if ((task->_1C[0] == 16 || task->_1C[0] == 22) && task->_18 == 35) {
        playSoundEffect(348);
    }
    return;

kill:
    g_UnkSound_32718._07 = 0;
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}

// .text:0x00096914 size:0x78 mapped:0x806D59A8
void fn_3_96914(void) {
    if (lbl_3_common_bss_32724._C7 == 0 && g_GameLogic.hudElementLoadingInd != 0) {
        fn_800B0A5C_insertQueue(fn_3_9669C, 2);
        if (g_d_GameSettings.GameModeSelected == 6) {
            fn_800B0A5C_insertQueue(fn_3_ED574, 2);
        }
    }
}

// .text:0x0009669C size:0x278 mapped:0x806D5730
void fn_3_9669C(void) {
    UnkTask1770* task = lbl_803CC1B8;
    UnkSprite1770* sprite;
    s32 i;

    if (g_d_GameSettings.GameModeSelected == 6) {
        fn_80034E20(task, lbl_3_data_8D88);
        for (i = 1; i < 4; i++) {
            if (g_Minigame._1914_arr[i] != 0) {
                sprite = lbl_80371C30[task->_14 + 1 + i]._00;
                sprite->_54 |= 2;
                lbl_80371C30[task->_14 + 1 + i]._00->_68 = 0;
                task->_1C[i] = i;
            } else {
                task->_1C[i] = 9;
            }
            lbl_80371C30[task->_14 + 1 + i]._00->_5C = (i - 1) << 16;
        }
        if (g_Minigame._19A2 != 0) {
            lbl_80371C30[task->_14 + 5]._00->_54 |= 2;
        }
    } else {
        fn_80034E20(task, lbl_3_data_BFEC);
        for (i = 0; i < 3; i++) {
            lbl_80371C30[task->_14 + 9 + i]._00->_5C = i << 16;
        }
        for (i = 0; i < 4; i++) {
            if (g_Runners[i].charID >= 0) {
                lbl_80371C30[task->_14 + 5 + i]._00->_5C = g_Runners[i].charID << 16;
            }
        }
    }
    lbl_3_common_bss_32724._C7 = 1;
    task->_18 = 0;
    task->_1A = 0;
    task->_1C[0] = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_959BC;
}

// .text:0x000959BC size:0xCE0 mapped:0x806D4A50
void fn_3_959BC(void) {
    return;
}

// .text:0x00095970 size:0x4C mapped:0x806D4A04
void fn_3_95970(void) {
    fn_80034E20(lbl_803CC1B8, lbl_3_data_C1EC);
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_95620;
}

// .text:0x00095620 size:0x350 mapped:0x806D46B4
void fn_3_95620(void) {
    UnkTask1770* task = lbl_803CC1B8;
    UnkSprite1770* sprite;
    s16 fielder;
    UnkFielder16B8* pos;
    int x;
    int y;
    f32 fx;
    f32 fy;

    if (lbl_3_common_bss_32724._96 != 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    if (g_d_GameSettings.GameModeSelected == 2) {
        if (g_GameLogic.secondaryGameMode == 13 || g_GameLogic.secondaryGameMode == 14 ||
            g_GameLogic.secondaryGameMode == 15 || g_GameLogic.secondaryGameMode == 16)
        {
            if (g_Practice._186 != 0) {
                lbl_80371C30[task->_14]._00->_54 &= ~2;
                return;
            }
        } else {
            lbl_80371C30[task->_14]._00->_54 &= ~2;
            return;
        }
    }
    if (g_Stats.replayInd != 0) {
        lbl_80371C30[task->_14]._00->_54 &= ~2;
    } else if (g_GameLogic.gameStatus != 2) {
        lbl_80371C30[task->_14]._00->_54 &= ~2;
    } else if (g_GameLogic.sceneID == 1) {
        lbl_80371C30[task->_14]._00->_54 &= ~2;
    } else if (g_GameLogic._13E[g_GameLogic.teamFielding] != 0) {
        lbl_80371C30[task->_14]._00->_54 &= ~2;
    } else if (g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam] != 0 &&
               g_GameLogic.autoFielding[g_GameLogic.awayTeamBattingInd_battingTeam] != 0)
    {
        lbl_80371C30[task->_14]._00->_54 &= ~2;
    } else if (g_FieldingLogic._139 != 0) {
        lbl_80371C30[task->_14]._00->_54 &= ~2;
    } else if ((fielder = g_FieldingLogic._0B0) < 0) {
        lbl_80371C30[task->_14]._00->_54 &= ~2;
    } else {
        pos = &g_Fielders[fielder];
        lbl_80371C30[task->_14]._00->_54 |= 2;
        fy = -2.0f - pos->_00C;
        fn_3_1650C(&x, &y, FALSE, pos->_000, fy, pos->_008);
        fx = x;
        fy = y;
        lbl_80371C30[task->_14]._00->_48 = fx;
        lbl_80371C30[task->_14]._00->_4C = fy;
        lbl_80371C30[task->_14]._00->_58 = (lbl_80371C30[task->_14]._00->_58 & 0xFF) | 0xFFFFFF00;
    }
}

// .text:0x000955CC size:0x54 mapped:0x806D4660
void fn_3_955CC(void) {
    fn_80034E20(lbl_803CC1B8, lbl_3_data_E0E0);
    playSoundEffect(0x1A9);
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_95568;
}

// .text:0x00095568 size:0x64 mapped:0x806D45FC
void fn_3_95568(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || lbl_80371C30[task->_14]._00->_69 == 2) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0009551C size:0x4C mapped:0x806D45B0
void fn_3_9551C(void) {
    fn_80034E20(lbl_803CC1B8, lbl_3_data_E120);
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_954C4;
}

// .text:0x000954C4 size:0x58 mapped:0x806D4558
void fn_3_954C4(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || g_GameLogic.gameStatus != 0x16) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000953FC size:0xC8 mapped:0x806D4490
void fn_3_953FC(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_E160);
    lbl_80371C30[task->_14 + 2]._00->_5C = lbl_3_data_E200[lbl_3_common_bss_37400._46] << 16;
    lbl_80371C30[task->_14 + 3]._00->_5C = lbl_3_data_E200[lbl_3_common_bss_37400._46] << 16;
    lbl_3_common_bss_32724._B4 = 0;
    lbl_3_common_bss_32724._B3 = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_9538C;
}

// .text:0x0009538C size:0x70 mapped:0x806D4420
void fn_3_9538C(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || g_GameLogic.gameStatus != 0x16) {
        fn_800B0A5C_insertQueue(fn_3_95000, 2);
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000952DC size:0xB0 mapped:0x806D4370
void fn_3_952DC(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._B5 != 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    fn_80034E20(task, lbl_3_data_E21C);
    if (lbl_3_common_bss_37400._47 == 1) {
        lbl_80371C30[task->_14]._00->_64 = 90;
    }
    lbl_3_common_bss_32724._B5 = 1;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_951B4;
}

// .text:0x000951B4 size:0x128 mapped:0x806D4248
void fn_3_951B4(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (g_Ball.deadBallReason == 1) {
        if (g_GameLogic.gameStatus == 20) {
            lbl_80371C30[task->_14]._00->_68 = 1;
        }
        if (g_GameLogic.gameStatus == 2) {
        } else if (g_GameLogic.gameStatus == 20) {
        } else {
            goto kill;
        }
        return;
    }
    if (g_UnkSound_32718._07 == 0 || g_GameLogic.gameStatus == 1) {
        lbl_80371C30[task->_14]._00->_68 = 1;
    }
    if (lbl_3_common_bss_32724._96 == 0 && lbl_3_common_bss_37400._42 != 0) {
        if (g_GameLogic.gameStatus == 1) {
        } else if (g_GameLogic.gameStatus == 2) {
        } else {
            goto kill;
        }
        return;
    }
kill:
    lbl_3_common_bss_32724._B4 = 0;
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}

// .text:0x00095124 size:0x90 mapped:0x806D41B8
void fn_3_95124(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_E278);
    lbl_80371C30[task->_14 + 2]._00->_5C = lbl_3_data_E200[lbl_3_common_bss_37400._46] << 16;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_95098;
}

// .text:0x00095098 size:0x8C mapped:0x806D412C
void fn_3_95098(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || lbl_80371C30[task->_14]._00->_69 == 2) {
        fn_800B0A5C_insertQueue(fn_3_95000, 2);
        lbl_3_common_bss_32724._B3 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00095000 size:0x98 mapped:0x806D4094
void fn_3_95000(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_E2F8);
    lbl_80371C30[task->_14 + 2]._00->_5C = lbl_3_data_E200[lbl_3_common_bss_37400._46] << 16;
    task->_1C[0] = lbl_3_common_bss_37400._46;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_94E68;
}

// .text:0x00094E68 size:0x198 mapped:0x806D3EFC
void fn_3_94E68(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 == 0 &&
        (task->_1C[0] == lbl_3_common_bss_37400._46 || lbl_3_common_bss_37400._47 == 2) &&
        g_GameLogic.gameStatus != 3 && (g_GameLogic.gameStatus != 8 || lbl_3_common_bss_37400._47 == 0) &&
        (g_GameLogic.gameStatus != 0 || lbl_3_common_bss_37400._47 != 2))
    {
        if (g_Stats.replayInd != 0) {
            lbl_80371C30[task->_14]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 1]._00->_54 &= ~2;
        } else if (g_GameLogic.gameStatus == 0 || g_GameLogic.gameStatus == 1 || g_GameLogic.gameStatus == 2) {
            lbl_80371C30[task->_14]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 1]._00->_54 |= 2;
        } else {
            lbl_80371C30[task->_14]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 1]._00->_54 &= ~2;
        }
    } else {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00094BC4 size:0x2A4 mapped:0x806D3C58
// 98.22%: the target computes idx as base + (j + 1) (addi, then add) and
// allocates the counters differently; the instructions are otherwise the same.
void fn_3_94BC4(void) {
    UnkTask1770* task = lbl_803CC1B8;
    UnkSprite1770* sprite;
    s32 count;
    s32 i;
    s32 j;
    s32 idx;
    s32 base;

    if (lbl_3_common_bss_32724._B4 != 0) {
        task->_1C[0] = 2;
    } else if (g_GameLogic.gameStatus == 22) {
        task->_1C[0] = 1;
    } else {
        task->_1C[0] = 0;
    }
    fn_80034E20(task, lbl_3_data_E378);
    count = 0;
    for (i = 0; i < 9; i++) {
        if (lbl_3_common_bss_37400._12[i]._3 != 0) {
            base = lbl_3_data_E758[count];
            lbl_80371C30[task->_14 + base]._00->_5C = lbl_3_common_bss_37400._12[i]._4 << 16;
            for (j = 0; j < 5; j++) {
                idx = base + (j + 1);
                if (j >= lbl_3_common_bss_37400._12[i]._1) {
                    lbl_80371C30[task->_14 + idx]._00->_54 &= ~2;
                } else {
                    sprite = lbl_80371C30[task->_14 + idx]._00;
                    sprite->_54 |= 2;
                    lbl_80371C30[task->_14 + idx]._00->_68 = 0;
                    lbl_80371C30[task->_14 + idx]._00->_5C = 0;
                    if (j < lbl_3_common_bss_37400._12[i]._0) {
                        lbl_80371C30[task->_14 + idx]._00->_5C = 1 << 16;
                    } else if (j < lbl_3_common_bss_37400._12[i]._2 + lbl_3_common_bss_37400._12[i]._0) {
                        if (task->_1C[0] == 2) {
                            lbl_80371C30[task->_14 + idx]._00->_5C = 40 << 16;
                        } else {
                            lbl_80371C30[task->_14 + idx]._00->_5C = 60 << 16;
                        }
                        lbl_80371C30[task->_14 + idx]._00->_68 = 1;
                    }
                }
            }
            count++;
        }
    }
    if (count < 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    lbl_80371C30[task->_14 + 1]._00->_5C = (count - 1) << 16;
    task->_1A = count;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_9497C;
}

// .text:0x0009497C size:0x248 mapped:0x806D3A10
// 87.50%: the target adds each offset to task->_14 + k computed first and
// keeps 60 << 16 in a register for the loop; the branches are otherwise the same.
void fn_3_9497C(void) {
    UnkTask1770* task = lbl_803CC1B8;
    u16 state;
    s32 i;
    UnkSprite1770* sprite;

    if (lbl_3_common_bss_32724._96 != 0) {
        goto kill;
    }
    if (g_UnkSound_32718._07 == 0 || g_GameLogic.gameStatus == 1) {
        lbl_80371C30[task->_14]._00->_68 = 1;
        lbl_80371C30[task->_14 + 2]._00->_68 = 1;
        lbl_80371C30[task->_14 + 3]._00->_68 = 1;
        lbl_80371C30[task->_14 + 4]._00->_68 = 1;
        lbl_80371C30[task->_14 + 5]._00->_68 = 1;
    }
    state = task->_1C[0];
    if (state == 2) {
        if (lbl_3_common_bss_32724._B4 == 0) {
            goto kill;
        }
    } else if (state != 0) {
        if (g_GameLogic.gameStatus != 22) {
            goto kill;
        }
    } else if (lbl_3_common_bss_32724._B3 == 0) {
        goto kill;
    }
    if (state != 2) {
        for (i = 0; i < task->_1A; i++) {
            sprite = lbl_80371C30[task->_14 + 1 + lbl_3_data_E758[i]]._00;
            if ((sprite->_5C >> 16) > 40) {
                sprite->_5C = 60 << 16;
            }
            sprite = lbl_80371C30[task->_14 + 2 + lbl_3_data_E758[i]]._00;
            if ((sprite->_5C >> 16) > 40) {
                sprite->_5C = 60 << 16;
            }
            sprite = lbl_80371C30[task->_14 + 3 + lbl_3_data_E758[i]]._00;
            if ((sprite->_5C >> 16) > 40) {
                sprite->_5C = 60 << 16;
            }
            sprite = lbl_80371C30[task->_14 + 4 + lbl_3_data_E758[i]]._00;
            if ((sprite->_5C >> 16) > 40) {
                sprite->_5C = 60 << 16;
            }
            sprite = lbl_80371C30[task->_14 + 5 + lbl_3_data_E758[i]]._00;
            if ((sprite->_5C >> 16) > 40) {
                sprite->_5C = 60 << 16;
            }
        }
    }
    return;

kill:
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}

// .text:0x00094930 size:0x4C mapped:0x806D39C4
void fn_3_94930(void) {
    fn_80034E20(lbl_803CC1B8, lbl_3_data_F3F0);
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_948B8;
}

// .text:0x000948B8 size:0x78 mapped:0x806D394C
void fn_3_948B8(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || g_GameLogic.gameStatus != 0x17 ||
        lbl_80371C30[task->_14]._00->_69 == 2)
    {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00094760 size:0x158 mapped:0x806D37F4
// 91.77%: the target loads 37 for the first call and the second sprite
// row offset earlier; the instructions are otherwise the same.
void fn_3_94760(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_E75C);
    lbl_80371C30[task->_14 + 3]._00->_64 = lbl_3_data_F430[g_GameLogic.logo[0].captain][0];
    lbl_80371C30[task->_14 + 4]._00->_64 = lbl_3_data_F430[g_GameLogic.logo[1].captain][0];
    lbl_80371C30[task->_14 + 3]._00->_5C = g_GameLogic.logo[0].variationID << 16;
    lbl_80371C30[task->_14 + 4]._00->_5C = g_GameLogic.logo[1].variationID << 16;
    fn_800363D8(task, 5, 1, 37,
                g_GameLogic.teams[g_GameLogic.homeTeamInd] + g_GameLogic._13E[g_GameLogic.homeTeamInd] * 4);
    fn_800363D8(task, 6, 1, 37,
                g_GameLogic.teams[g_GameLogic.homeTeamInd ^ 1] + g_GameLogic._13E[g_GameLogic.homeTeamInd ^ 1] * 4);
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_94708;
}

// .text:0x00094708 size:0x58 mapped:0x806D379C
void fn_3_94708(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || g_GameLogic._125 > 9) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00094194 size:0x574 mapped:0x806D3228
void fn_3_94194(void) {
    return;
}

// .text:0x0009413C size:0x58 mapped:0x806D31D0
void fn_3_9413C(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || g_GameLogic.gameStatus != 9) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00093D5C size:0x3E0 mapped:0x806D2DF0
void fn_3_93D5C(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_EABC);
    lbl_80371C30[task->_14 + 2]._00->_64 = lbl_3_data_F430[g_GameLogic.logo[0].captain][1];
    lbl_80371C30[task->_14 + 3]._00->_64 = lbl_3_data_F430[g_GameLogic.logo[1].captain][1];
    lbl_80371C30[task->_14 + 2]._00->_5C = g_GameLogic.logo[0].variationID << 16;
    lbl_80371C30[task->_14 + 3]._00->_5C = g_GameLogic.logo[1].variationID << 16;
    lbl_80371C30[task->_14 + 4]._00->_5C = 0;
    lbl_80371C30[task->_14 + 5]._00->_5C = 1 << 16;
    lbl_80371C30[task->_14 + 6]._00->_5C = 2 << 16;
    lbl_80371C30[task->_14 + 7]._00->_5C = 3 << 16;
    lbl_80371C30[task->_14 + 8]._00->_5C = 4 << 16;
    lbl_80371C30[task->_14 + 9]._00->_5C = 5 << 16;
    fn_3_93688(task);
    lbl_3_common_bss_32724._98 = 1;
    task->_18 = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_93960;
}

// .text:0x00093960 size:0x3FC mapped:0x806D29F4
void fn_3_93960(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._98 == 2) {
        lbl_3_common_bss_32724._98 = 1;
        task->_18 = 0;
    }
    if (task->_18 < 0xFFFE) {
        task->_18++;
    } else {
        task->_18 = 0xFFFF;
    }
    if (lbl_3_common_bss_32724._96 != 0) {
        goto kill;
    }
    if (g_GameLogic.gameStatus == 3 && g_GameLogic._125 == 9) {
        goto kill;
    }
    if (g_GameLogic.gameStatus == 9 && g_GameLogic._125 == 4) {
        goto kill;
    }
    if (g_GameLogic.gameStatus == 5 && (g_GameLogic._125 == 10 || g_GameLogic._125 == 11)) {
        goto kill;
    }
    if ((g_UnkSound_32718._07 == 7 || g_UnkSound_32718._07 == 20) && task->_18 > 30) {
        goto kill;
    }
    if (g_GameLogic.gameStatus == 8 || g_GameLogic.gameStatus == 6) {
        goto kill;
    }
    if (g_GameLogic.gameStatus == 2 && task->_18 > 90) {
        goto kill;
    }
    fn_3_93688(task);
    return;

kill:
    lbl_3_common_bss_32724._98 = 0;
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}

// .text:0x00093688 size:0x2D8 mapped:0x806D271C
void fn_3_93688(UnkTask1770* task) {
    s32 score;

    if (g_Scores._04[0][0] >= 10) {
        score = g_Scores._04[0][0];
        if (g_Scores._04[0][0] >= 99) {
            score = 99;
        }
        lbl_80371C30[task->_14 + 4]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 5]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 6]._00->_54 |= 2;
        fn_8003649C(task, 5, 2, 0xF6, score / 10);
        fn_8003649C(task, 6, 3, 0xF6, score % 10);
    } else {
        lbl_80371C30[task->_14 + 4]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 5]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 6]._00->_54 &= ~2;
        fn_8003649C(task, 4, 1, 0xF6, g_Scores._04[0][0]);
    }
    score = g_Scores._04[1][0];
    if (score >= 10) {
        if (score >= 99) {
            score = 99;
        }
        lbl_80371C30[task->_14 + 7]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 8]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 9]._00->_54 |= 2;
        fn_8003649C(task, 8, 5, 0xF6, score / 10);
        fn_8003649C(task, 9, 6, 0xF6, score % 10);
    } else {
        lbl_80371C30[task->_14 + 7]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 8]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 9]._00->_54 &= ~2;
        fn_8003649C(task, 7, 4, 0xF6, g_Scores._04[1][0]);
    }
}

// .text:0x00093544 size:0x144 mapped:0x806D25D8
void fn_3_93544(void) {
    return;
}

// .text:0x000933CC size:0x178 mapped:0x806D2460
void fn_3_933CC(void) {
    return;
}

// .text:0x00092CD8 size:0x6F4 mapped:0x806D1D6C
void fn_3_92CD8(void) {
    return;
}

// .text:0x00091FC4 size:0xD14 mapped:0x806D1058
void fn_3_91FC4(void) {
    return;
}

// .text:0x00091E4C size:0x178 mapped:0x806D0EE0
// 98.72%: the target branches to the shared exit with bge, then b to the
// end, where this compiles to one blt.
void fn_3_91E4C(void) {
    UnkTask1770* task = lbl_803CC1B8;
    s32 i;
    s32 value;

    if (lbl_3_common_bss_32724._CD == 0) {
        if (lbl_3_common_bss_32724._CE == 0) {
            return;
        }
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        value = lbl_80371C30[task->_14 + 1]._00->_5C >> 16;
        for (i = 0; i < 11; i++) {
            if (value <= lbl_3_data_F200[i]) {
                if (i == 0) {
                    lbl_80371C30[task->_14 + 2]._00->_68 = 4;
                    lbl_80371C30[task->_14 + 3]._00->_68 = 4;
                }
                lbl_80371C30[task->_14 + 6 + i]._00->_68 = 4;
                lbl_80371C30[task->_14 + 17 + i]._00->_68 = 4;
            }
        }
        task->_1A++;
        if (task->_1A < 45) {
            return;
        }
    }
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
    if (g_GameLogic.gameStatus == 3) {
        lbl_8034E978._26 = 1;
    }
}

// .text:0x00091D1C size:0x130 mapped:0x806D0DB0
void fn_3_91D1C(void) {
    UnkTask1770* task = lbl_803CC1B8;
    s32 i;
    s32 batter;

    fn_80034E20(task, lbl_3_data_F224);
    lbl_80371C30[task->_14 + 3]._00->_64 = lbl_3_data_F344[g_d_GameSettings.StadiumID];
    for (i = 0; i < 3; i++) {
        batter = g_GameLogic.currentBatterPerTeam[g_GameLogic.awayTeamBattingInd_battingTeam] + i;
        if (batter > 9) {
            batter -= 9;
        }
        lbl_80371C30[task->_14 + 5 + i]._00->_5C =
            inMemRoster[g_GameLogic.teamFielding]
                       [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][batter][0]]
                           .stats.CharID
            << 16;
    }
    fn_800363D8(task, 1, 4, 7, g_d_GameSettings.StadiumID);
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_91CCC;
}

// .text:0x00091CCC size:0x50 mapped:0x806D0D60
void fn_3_91CCC(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0 || lbl_3_common_bss_32724._CD != 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00091C70 size:0x5C mapped:0x806D0D04
void fn_3_91C70(void) {
    fn_80034E20(lbl_803CC1B8, lbl_3_data_F390);
    lbl_3_common_bss_32724._B0 = 1;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_91B9C;
}

// .text:0x00091B9C size:0xD4 mapped:0x806D0C30
void fn_3_91B9C(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 == 0) {
        s32 idx = task->_14;

        if ((lbl_80371C30[idx]._00->_5C >> 16) >= 75) {
            lbl_80371C30[idx + 1]._00->_54 |= 2;
        }
        if ((g_Stats.replayInd != 0 || g_Stats._39 != 0) && g_GameLogic.gameStatus != 3 &&
            g_GameLogic.gameStatus != 11 && g_GameLogic.gameStatus != 14)
        {
            return;
        }
    }
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
    lbl_3_common_bss_32724._B0 = 0;
    lbl_3_common_bss_32724._B1 = 0;
}

// .text:0x00091B50 size:0x4C mapped:0x806D0BE4
void fn_3_91B50(void) {
    fn_80034E20(lbl_803CC1B8, lbl_3_data_F350);
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_91AC8;
}

// .text:0x00091AC8 size:0x88 mapped:0x806D0B5C
void fn_3_91AC8(void) {
    UnkTask1770* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 == 0 && g_Stats.replayInd == 0) {
        if (g_GameLogic.gameStatus == 2) {
        } else if (g_GameLogic.gameStatus == 1) {
        } else {
            goto kill;
        }
        return;
    }
kill:
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        lbl_3_common_bss_32724._B2 = 0;
}

// .text:0x00091A60 size:0x68 mapped:0x806D0AF4
void fn_3_91A60(void) {
    UnkTask1770* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_BF6C);
    task->_18 = 0;
    task->_1C[0] = 0;
    task->_1C[1] = 0;
    task->_1C[2] = 0;
    ((UnkTask1770*)lbl_803CC1B8)->_00 = fn_3_91520;
}

// .text:0x00091520 size:0x540 mapped:0x806D05B4
void fn_3_91520(void) {
    return;
}
