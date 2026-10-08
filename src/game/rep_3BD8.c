#include "game/rep_3BD8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_16B8.h"

typedef struct UnkTask3BD8 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16[0x18 - 0x16];
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
} UnkTask3BD8;

typedef struct {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66;
    /* 0x67 */ u8 _67;
    /* 0x68 */ u8 _68;
} UnkSprite3BD8;

typedef struct {
    /* 0x00 */ UnkSprite3BD8* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef3BD8; // size: 0x8

typedef struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06[0x9 - 0x6];
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13[0x23 - 0x13];
    /* 0x23 */ u8 _23;
    /* 0x24 */ u8 _24;
    /* 0x25 */ u8 _25;
} UnkBatStats3BD8; // size: 0x26

typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u16 _04;
    /* 0x06 */ u8 _06[0xA - 0x6];
    /* 0x0A */ u16 _0A;
    /* 0x0C */ u8 _0C[0x1A - 0xC];
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
} UnkPitchStats3BD8; // size: 0x1E

typedef struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ s8 _1;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
} UnkSlot3BD8; // size: 0x4

extern UnkPitchStats3BD8 lbl_803535C8[2][9];
extern UnkBatStats3BD8 lbl_803537E4[2][9];
extern UnkSlot3BD8 lbl_80354720[2][9];

// .data of rep_16B8
extern u8 lbl_3_data_F430[12][2];

extern UnkSpriteRef3BD8 lbl_80371C30[];
extern void* lbl_803CC1B8;

extern struct {
    /* 0x000 */ u8 _000[0x104];
    /* 0x104 */ u8 _104;
} lbl_80353A90;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0xAD - 0x4];
    /* 0xAD */ u8 _AD;
} g_Scores;

extern struct {
    /* 0x00 */ u8 _00[0xCE];
    /* 0xCE */ u8 _CE;
    /* 0xCF */ u8 _CF;
    /* 0xD0 */ u8 _D0;
    /* 0xD1 */ u8 _D1;
    /* 0xD2 */ u8 _D2;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x000 */ u8 _000[0x1D8];
    /* 0x1D8 */ u8 _1D8;
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ s8 _1DA;
} lbl_3_common_bss_34C90;

extern void fn_80034CEC(UnkTask3BD8* task);
extern void fn_80034E20(UnkTask3BD8* task, void* desc);
extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void fn_8004D0F0(void);
extern void fn_800362F0(UnkTask3BD8* task, s32 id);
extern void fn_800363D8(UnkTask3BD8* task, s32 id, s32 part, s32 kind, s32 value);

u32 lbl_3_data_273E0[16] = {
    0x000000BE, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000800FF, 0x02000000, 0x00000000, 0x00010000,
    0x00030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

u32 lbl_3_data_27420[48] = {
    0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010700FF, 0x01000000, 0x00000000, 0x00010000,
    0x0000000F, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00070000, 0x01000000, 0x00000000, 0x00010001,
    0x0000000D, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00070000, 0x01000000, 0x00000000, 0x00010000,
    0x000000CB, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010700FF, 0x02000000, 0x00000000, 0x00010000,
    0x000000CF, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010600FF, 0x02000000, 0x00000000, 0x00010000,
    0x00030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

u32 lbl_3_data_274E0[472] = {
    0x0000000A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010700FF, 0x0C000000, 0x00000000, 0x00010000,
    0x0000000B, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01070000, 0x0C000000, 0x00000000, 0x00010000,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010031,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010030,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001002F,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001002E,
    0x0000000C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001002D,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010024,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010023,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010022,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010021,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010020,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001001F,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001001E,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001001D,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001001C,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001001B,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001001A,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010019,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010018,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010017,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010016,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010015,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010014,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010013,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010012,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010011,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010010,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001000F,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001000E,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001000D,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001000C,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001000B,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001000A,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010009,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010008,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010007,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010006,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010005,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010004,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010003,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010002,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010001,
    0x0000000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001002A,
    0x0000000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010029,
    0x0000000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010028,
    0x0000000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010027,
    0x0000000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010026,
    0x0000000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x00010025,
    0x00000004, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001002C,
    0x00000005, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x01060000, 0x0C000000, 0x00000000, 0x0001002B,
    0x00000001, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010600FF, 0x0C000000, 0x00000000, 0x00010000,
    0x0000001B, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010600FF, 0x0C000000, 0x00000000, 0x00010000,
    0x00000007, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010600FF, 0x0C000000, 0x00000000, 0x00010000,
    0x00000006, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010600FF, 0x0C000000, 0x00000000, 0x00010000,
    0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00060036, 0x0F000000, 0x00000000, 0x00010000,
    0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00060036, 0x10000000, 0x00000000, 0x00010000,
    0x00000002, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010600FF, 0x0C000000, 0x00000000, 0x00010000,
    0x00030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

u8 lbl_3_data_27C40[2][6] = {
    { 0, 1, 2, 3, 4, 5 },
    { 6, 7, 8, 9, 10, 11 },
};

u8 lbl_3_data_27C4C[8] = { 0x05, 0x07, 0x09, 0x0B, 0x0D, 0x0F, 0x00, 0x00 };

u32 lbl_3_data_27C54[16] = {
    0x000000BF, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x010800FF, 0x02000000, 0x00000000, 0x00010000,
    0x00030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

static inline void fn_3BD8_set68(UnkTask3BD8* task, s32 idx, u8 value) {
    lbl_80371C30[task->_14 + idx]._00->_68 = value;
}

// .text:0x0015F410 size:0x164 mapped:0x8079E4A4
void fn_3_15F410(void) {
    if (g_GameLogic._125 < 3) {
        return;
    }
    if (g_GameLogic._125 == 3) {
        lbl_3_common_bss_32724._CF = g_Scores._00;
        lbl_3_common_bss_32724._D0 = g_Scores._AD;
        fn_800B0A5C_insertQueue(fn_3_15F3C4, 2);
    }
    if (g_GameLogic._125 == 4 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
        fn_800B0A5C_insertQueue(fn_3_15C638, 2);
    }
    if (g_GameLogic._125 == 7) {
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            if (lbl_3_common_bss_34C90._1D8 == 0 && g_GameLogic._11A != 0) {
                fn_800B0A5C_insertQueue(fn_3_91FC4, 2);
                fn_800B0A5C_insertQueue(fn_3_15F220, 2);
                g_GameLogic._11A = 0;
            } else if (g_GameLogic._11A != 1) {
                fn_800B0A5C_insertQueue(fn_3_15EE2C, 2);
                g_GameLogic._11A = 1;
            }
        }
    } else if (g_GameLogic._125 == 5) {
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            fn_800B0A5C_insertQueue(fn_8004D0F0, 2);
        }
    }
}

// .text:0x0015F3C4 size:0x4C mapped:0x8079E458
void fn_3_15F3C4(void) {
    fn_80034E20(lbl_803CC1B8, lbl_3_data_273E0);
    ((UnkTask3BD8*)lbl_803CC1B8)->_00 = fn_3_15F380;
}

// .text:0x0015F380 size:0x44 mapped:0x8079E414
void fn_3_15F380(void) {
    UnkTask3BD8* task = lbl_803CC1B8;

    if (g_GameLogic._125 == 10) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0015F220 size:0x160 mapped:0x8079E2B4
void fn_3_15F220(void) {
    UnkTask3BD8* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_27420);
    if (!g_d_GameSettings.exhibitionMatchInd) {
        lbl_80371C30[task->_14 + 1]._00->_64 = 14;
    }
    if (lbl_80353A90._104 == 3) {
        lbl_80371C30[task->_14 + 3]._00->_64 = 0xCC;
        lbl_80371C30[task->_14 + 4]._00->_64 = 0xD0;
    } else if (lbl_80353A90._104 == 2) {
        lbl_80371C30[task->_14 + 3]._00->_64 = 0xCD;
        lbl_80371C30[task->_14 + 4]._00->_64 = 0xD1;
    }
    if (!g_d_GameSettings.exhibitionMatchInd && g_GameLogic.playOverFadeOutStarted >= 0) {
        lbl_80371C30[task->_14 + 1]._00->_64 = 16;
    }
    task->_1A = 0;
    ((UnkTask3BD8*)lbl_803CC1B8)->_00 = fn_3_15F088;
}

// .text:0x0015F088 size:0x198 mapped:0x8079E11C
void fn_3_15F088(void) {
    UnkTask3BD8* task = lbl_803CC1B8;

    if (g_GameLogic._125 != 10) {
        if (lbl_3_common_bss_34C90._1DA == 0) {
            lbl_80371C30[task->_14 + 1]._00->_68 = 1;
            lbl_80371C30[task->_14 + 2]._00->_68 = 4;
            if ((lbl_80371C30[task->_14 + 2]._00->_5C >> 16) > 10) {
                lbl_80371C30[task->_14 + 2]._00->_5C = 0xA0000;
            }
        } else {
            lbl_80371C30[task->_14 + 1]._00->_68 = 4;
            if ((lbl_80371C30[task->_14 + 1]._00->_5C >> 16) > 10) {
                lbl_80371C30[task->_14 + 1]._00->_5C = 0xA0000;
            }
            lbl_80371C30[task->_14 + 2]._00->_68 = 1;
        }
        if (lbl_3_common_bss_32724._CE != 0) {
            lbl_80371C30[task->_14]._00->_68 = 4;
            lbl_80371C30[task->_14 + 3]._00->_68 = 4;
            lbl_80371C30[task->_14 + 4]._00->_54 &= ~2;
            task->_1A++;
            if (task->_1A >= 45) {
                goto kill;
            }
        }
        return;
    }
kill:
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}

// .text:0x0015EE2C size:0x25C mapped:0x8079DEC0
void fn_3_15EE2C(void) {
    UnkTask3BD8* task = lbl_803CC1B8;
    s32 team;
    s32 i;

    fn_80034E20(task, lbl_3_data_274E0);
    lbl_80371C30[task->_14 + 55]._00->_64 = lbl_3_data_F430[g_GameLogic.logo[0].captain][0];
    lbl_80371C30[task->_14 + 56]._00->_64 = lbl_3_data_F430[g_GameLogic.logo[1].captain][0];
    lbl_80371C30[task->_14 + 55]._00->_5C = g_GameLogic.logo[0].variationID << 16;
    lbl_80371C30[task->_14 + 56]._00->_5C = g_GameLogic.logo[1].variationID << 16;
    if (g_GameLogic.scoreBook_teamDisplayed == 0) {
        lbl_80371C30[task->_14 + 56]._00->_54 &= ~2;
    } else {
        lbl_80371C30[task->_14 + 55]._00->_54 &= ~2;
    }
    team = g_GameLogic.homeTeamInd ^ g_GameLogic.scoreBook_teamDisplayed;
    if (g_GameLogic._13E[team] != 0) {
        fn_800363D8(task, 57, 1, 3, g_GameLogic.teams[team] + 4);
    } else {
        fn_800363D8(task, 57, 1, 3, g_GameLogic.teams[team]);
    }
    for (i = 0; i < 6; i++) {
        fn_800363D8(task, i + 43, 1, 15, lbl_3_data_27C40[g_GameLogic.scoreBook_batter_pitcherStatsDisplayed][i]);
    }
    if (g_GameLogic.scoreBook_batter_pitcherStatsDisplayed == 0) {
        lbl_80371C30[task->_14 + 53]._00->_5C = 0x50000;
    } else {
        lbl_80371C30[task->_14 + 53]._00->_5C = 0x330000;
    }
    lbl_3_common_bss_32724._D2 = 0;
    task->_18 = 0;
    task->_1A = 0;
    task->_1C = g_GameLogic.scoreBook_teamDisplayed;
    task->_1E = g_GameLogic.scoreBook_batter_pitcherStatsDisplayed;
    task->_20 = g_GameLogic.scoreBook_scrollIndex;
    fn_3_15D1D8(task);
    ((UnkTask3BD8*)lbl_803CC1B8)->_00 = fn_3_15DB44;
}

// .text:0x0015DB44 size:0x12E8 mapped:0x8079CBD8
void fn_3_15DB44(void) {
    UnkTask3BD8* task = lbl_803CC1B8;
    s32 flag;
    s32 i;
    s32 j;
    s32 team;
    s32 frame;
    UnkSprite3BD8* sprite;

    if (task->_18 < 0xFFFE) {
        task->_18++;
    } else {
        task->_18 = 0xFFFF;
    }
    flag = 0;
    lbl_3_common_bss_32724._D2 = 0;
    if (g_GameLogic._125 == 10) {
        goto kill;
    }
    if (task->_1A == 0) {
        lbl_3_common_bss_32724._D2 = 1;
        task->_1A++;
    } else if (task->_1A == 1) {
        lbl_3_common_bss_32724._D2 = 1;
        if (task->_1E == 0) {
            sprite = lbl_80371C30[task->_14 + 49]._00;
            if ((sprite->_5C >> 16) >= 10) {
                sprite->_68 = flag;
            }
            sprite = lbl_80371C30[task->_14 + 50]._00;
            if ((sprite->_5C >> 16) >= 5) {
                sprite->_68 = flag;
            }
        } else {
            sprite = lbl_80371C30[task->_14 + 49]._00;
            if ((sprite->_5C >> 16) >= 5) {
                sprite->_68 = flag;
            }
            sprite = lbl_80371C30[task->_14 + 50]._00;
            if ((sprite->_5C >> 16) >= 10) {
                sprite->_68 = flag;
            }
        }
        sprite = lbl_80371C30[task->_14 + 54]._00;
        if ((sprite->_5C >> 16) >= 10) {
            sprite->_68 = flag;
        }
        if (task->_18 >= 30) {
            lbl_80371C30[task->_14]._00->_68 = flag;
            task->_1A++;
        }
    } else if (task->_1A == 2) {
        if (task->_20 != g_GameLogic.scoreBook_scrollIndex) {
            lbl_3_common_bss_32724._D2 = 1;
            task->_18 = 0;
            task->_1A = 7;
        } else if (task->_1C != g_GameLogic.scoreBook_teamDisplayed) {
            lbl_3_common_bss_32724._D2 = 1;
            task->_18 = 0;
            task->_1A = 3;
        } else if (task->_1E != g_GameLogic.scoreBook_batter_pitcherStatsDisplayed) {
            lbl_3_common_bss_32724._D2 = 1;
            task->_18 = 0;
            task->_1A = 5;
        } else if (g_GameLogic._125 == 8) {
            lbl_3_common_bss_32724._D2 = 1;
            task->_18 = 0;
            task->_1A = 9;
        }
    } else if (task->_1A == 3) {
        lbl_3_common_bss_32724._D2 = 1;
        flag = 0;
        if (g_GameLogic.scoreBook_logoFadeDirectionLeft_Right == 0) {
            if (task->_18 == 1) {
                lbl_80371C30[task->_14 + 54]._00->_5C = 0x150000;
                lbl_80371C30[task->_14 + 54]._00->_68 = 1;
            }
            sprite = lbl_80371C30[task->_14 + 54]._00;
            if ((sprite->_5C >> 16) >= 31) {
                flag = 1;
                sprite->_68 = 0;
            }
        } else {
            if (task->_18 == 1) {
                lbl_80371C30[task->_14 + 54]._00->_5C = 0xA0000;
                lbl_80371C30[task->_14 + 54]._00->_68 = 1;
            }
            sprite = lbl_80371C30[task->_14 + 54]._00;
            if ((sprite->_5C >> 16) >= 20) {
                flag = 1;
                sprite->_68 = 0;
            }
        }
        for (i = 2; i <= 42; i++) {
            lbl_80371C30[task->_14 + i]._00->_68 = 4;
        }
        if (flag) {
            task->_1A = 4;
            task->_18 = 0;
        }
    } else if (task->_1A == 4) {
        lbl_3_common_bss_32724._D2 = 1;
        if (task->_18 == 1) {
            task->_1C = g_GameLogic.scoreBook_teamDisplayed;
            if (task->_1C == 0) {
                lbl_80371C30[task->_14 + 55]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 56]._00->_54 &= ~2;
            } else {
                lbl_80371C30[task->_14 + 55]._00->_54 &= ~2;
                lbl_80371C30[task->_14 + 56]._00->_54 |= 2;
            }
            team = g_GameLogic.homeTeamInd ^ task->_1C;
            if (g_GameLogic._13E[team] != 0) {
                fn_800363D8(task, 57, 1, 3, g_GameLogic.teams[team] + 4);
            } else {
                fn_800363D8(task, 57, 1, 3, g_GameLogic.teams[team]);
            }
            fn_3_15D1D8(task);
        }
        if (g_GameLogic.scoreBook_logoFadeDirectionLeft_Right == 1) {
            if (task->_18 == 1) {
                lbl_80371C30[task->_14 + 54]._00->_5C = 0x1F0000;
                lbl_80371C30[task->_14 + 54]._00->_68 = 4;
            }
            sprite = lbl_80371C30[task->_14 + 54]._00;
            if ((sprite->_5C >> 16) <= 21) {
                sprite->_5C = 0xA0000;
                flag = 1;
                lbl_80371C30[task->_14 + 54]._00->_68 = 0;
            }
        } else {
            if (task->_18 == 1) {
                lbl_80371C30[task->_14 + 54]._00->_5C = 0x140000;
                lbl_80371C30[task->_14 + 54]._00->_68 = 4;
            }
            sprite = lbl_80371C30[task->_14 + 54]._00;
            if ((sprite->_5C >> 16) <= 10) {
                sprite->_5C = 0xA0000;
                flag = 1;
                lbl_80371C30[task->_14 + 54]._00->_68 = 0;
            }
        }
        for (i = 2; i <= 42; i++) {
            lbl_80371C30[task->_14 + i]._00->_68 = 1;
        }
        if (flag) {
            task->_1A = 2;
            task->_18 = 0;
        }
    } else if (task->_1A == 5) {
        lbl_3_common_bss_32724._D2 = 1;
        if (task->_18 == 1) {
            for (i = 7; i <= 48; i++) {
                lbl_80371C30[task->_14 + i]._00->_68 = 4;
            }
        }
        if (task->_1E == 0) {
            sprite = lbl_80371C30[task->_14 + 49]._00;
            if ((sprite->_5C >> 16) <= 5) {
                sprite->_68 = 0;
            } else {
                sprite->_68 = 4;
            }
            sprite = lbl_80371C30[task->_14 + 50]._00;
            if ((sprite->_5C >> 16) >= 10) {
                sprite->_68 = 0;
            } else {
                sprite->_68 = 1;
            }
        } else {
            sprite = lbl_80371C30[task->_14 + 50]._00;
            if ((sprite->_5C >> 16) <= 5) {
                sprite->_68 = 0;
            } else {
                sprite->_68 = 4;
            }
            sprite = lbl_80371C30[task->_14 + 49]._00;
            if ((sprite->_5C >> 16) >= 10) {
                sprite->_68 = 0;
            } else {
                sprite->_68 = 1;
            }
        }
        if (task->_18 >= 8) {
            task->_1A = 6;
            task->_18 = 0;
        }
    } else if (task->_1A == 6) {
        lbl_3_common_bss_32724._D2 = 1;
        if (task->_18 == 1) {
            task->_1E = g_GameLogic.scoreBook_batter_pitcherStatsDisplayed;
            for (i = 7; i <= 48; i++) {
                lbl_80371C30[task->_14 + i]._00->_68 = 1;
            }
            for (i = 0; i < 6; i++) {
                fn_800363D8(task, i + 43, 1, 15, lbl_3_data_27C40[task->_1E][i]);
            }
            if (task->_1E == 0) {
                lbl_80371C30[task->_14 + 53]._00->_5C = 0x50000;
            } else {
                lbl_80371C30[task->_14 + 53]._00->_5C = 0x330000;
            }
            fn_3_15D1D8(task);
        }
        if (task->_18 >= 8) {
            task->_1A = 2;
            task->_18 = 0;
        }
    } else if (task->_1A == 7) {
        lbl_3_common_bss_32724._D2 = 1;
        if (task->_18 == 1) {
            for (i = 2; i <= 42; i++) {
                if (i != 12 && i != 18 && i != 24 && i != 30 && i != 36 && i != 42) {
                    lbl_80371C30[task->_14 + i]._00->_68 = 4;
                }
            }
        }
        if (task->_18 >= 8) {
            task->_1A = 8;
            task->_18 = 0;
        }
    } else if (task->_1A == 8) {
        lbl_3_common_bss_32724._D2 = 1;
        if (task->_18 == 1) {
            task->_20 = g_GameLogic.scoreBook_scrollIndex;
            for (i = 2; i <= 42; i++) {
                lbl_80371C30[task->_14 + i]._00->_68 = 1;
            }
            fn_3_15D1D8(task);
        }
        if (task->_18 >= 8) {
            task->_1A = 2;
            task->_18 = 0;
        }
    } else {
        lbl_3_common_bss_32724._D2 = 1;
        lbl_80371C30[task->_14]._00->_68 = 4;
        sprite = lbl_80371C30[task->_14]._00;
        frame = sprite->_5C >> 16;
        if (frame == 10) {
            lbl_80371C30[task->_14 + 54]._00->_68 = 4;
            lbl_80371C30[task->_14 + 51]._00->_68 = 4;
            if (task->_1E == 0) {
                lbl_80371C30[task->_14 + 53]._00->_5C = 0x50000;
                lbl_80371C30[task->_14 + 53]._00->_68 = 4;
            } else {
                lbl_80371C30[task->_14 + 53]._00->_5C = 0x330000;
                lbl_80371C30[task->_14 + 53]._00->_68 = 1;
            }
        }
        if (frame <= lbl_3_data_27C4C[0] + 5) {
            if (task->_1E == 0) {
                lbl_80371C30[task->_14 + 49]._00->_68 = 1;
                lbl_80371C30[task->_14 + 50]._00->_68 = 4;
            } else {
                lbl_80371C30[task->_14 + 49]._00->_68 = 4;
                lbl_80371C30[task->_14 + 50]._00->_68 = 1;
            }
        }
        for (i = 0; i < 5; i++) {
            if (frame <= lbl_3_data_27C4C[i] + 5) {
                fn_3BD8_set68(task, i + 2, 4);
            }
        }
        for (i = 0; i < 6; i++) {
            if (frame <= lbl_3_data_27C4C[i] + 5) {
                fn_3BD8_set68(task, i + 43, 4);
            }
        }
        for (i = 0; i < 6; i++) {
            if (frame <= lbl_3_data_27C4C[i] + 5) {
                for (j = 0; j < 6; j++) {
                    fn_3BD8_set68(task, i * 6 + j + 7, 4);
                }
            }
        }
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) == 0) {
            goto kill;
        }
    }
    if (task->_1A >= 2) {
        if (task->_1E == 0) {
            sprite = lbl_80371C30[task->_14 + 53]._00;
            if ((sprite->_5C >> 16) >= 45) {
                sprite->_5C = 0x50000;
            }
        } else {
            sprite = lbl_80371C30[task->_14 + 53]._00;
            if ((sprite->_5C >> 16) >= 93) {
                sprite->_5C = 0x330000;
            }
        }
    }
    if (task->_20 == 0) {
        sprite = lbl_80371C30[task->_14 + 52]._00;
        if ((sprite->_5C >> 16) >= 302 || (sprite->_5C >> 16) < 202) {
            sprite->_5C = 0xCA0000;
        }
    } else if (task->_20 == 4) {
        sprite = lbl_80371C30[task->_14 + 52]._00;
        if ((sprite->_5C >> 16) >= 201 || (sprite->_5C >> 16) < 101) {
            sprite->_5C = 0x650000;
        }
    } else {
        sprite = lbl_80371C30[task->_14 + 52]._00;
        if ((sprite->_5C >> 16) >= 100) {
            sprite->_5C = 0;
        }
    }
    return;
kill:
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}

// .text:0x0015D1D8 size:0x96C mapped:0x8079C26C
void fn_3_15D1D8(UnkTask3BD8* task) {
    s32 order[5];
    s32 i;
    s32 j;
    s32 total;
    s32 total2;
    s32 rate;
    UnkBatStats3BD8* bat;
    UnkPitchStats3BD8* pitch;
    s32 team;

    team = task->_1C ^ g_GameLogic.homeTeamInd;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 9; j++) {
            if (i + task->_20 == lbl_80354720[team][j]._1) {
                order[i] = j;
                fn_800363D8(task, i + 2, 1, 13, inMemRoster[team][j].stats.CharID);
                break;
            }
        }
    }
    if (task->_1E == 0) {
        for (i = 0; i < 5; i++) {
            bat = &lbl_803537E4[team][order[i]];
            fn_3_15C6E4(task, i + 7, bat->_05, 3);
            fn_3_15C6E4(task, i + 13, bat->_10, 3);
            fn_3_15C6E4(task, i + 19, bat->_09, 3);
            fn_3_15C6E4(task, i + 25, bat->_12, 3);
            fn_3_15C6E4(task, i + 31, bat->_24, 3);
            if (bat->_04 == 0) {
                fn_3_15C6E4(task, i + 37, 0, 22);
            } else {
                total = bat->_05 * 10000 / bat->_04;
                if (total % 10 >= 5) {
                    total += 10;
                }
                fn_3_15C6E4(task, i + 37, total / 10, 10);
            }
        }
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803537E4[team][j]._05;
        }
        fn_3_15C6E4(task, 12, total, 3);
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803537E4[team][j]._10;
        }
        fn_3_15C6E4(task, 18, total, 3);
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803537E4[team][j]._09;
        }
        fn_3_15C6E4(task, 24, total, 3);
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803537E4[team][j]._12;
        }
        fn_3_15C6E4(task, 30, total, 3);
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803537E4[team][j]._24;
        }
        fn_3_15C6E4(task, 36, total, 3);
        total = 0;
        total2 = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803537E4[team][j]._05;
            total2 += lbl_803537E4[team][j]._04;
        }
        rate = total * 10000 / total2;
        if (rate % 10 >= 5) {
            rate += 10;
        }
        fn_3_15C6E4(task, 42, rate / 10, 10);
    } else {
        for (i = 0; i < 5; i++) {
            bat = &lbl_803537E4[team][order[i]];
            pitch = &lbl_803535C8[team][order[i]];
            fn_3_15C6E4(task, i + 7, bat->_23, 3);
            if (pitch->_00 == 0) {
                fn_3_15C6E4(task, i + 13, 0, 21);
                fn_3_15C6E4(task, i + 19, 0, 21);
                fn_3_15C6E4(task, i + 25, 0, 21);
                fn_3_15C6E4(task, i + 31, 0, 21);
            } else {
                fn_3_15C6E4(task, i + 13, pitch->_0A, 3);
                fn_3_15C6E4(task, i + 19, pitch->_1C, 3);
                fn_3_15C6E4(task, i + 25, pitch->_02, 3);
                fn_3_15C6E4(task, i + 31, pitch->_1D, 3);
            }
            if (pitch->_1A != 0) {
                rate = pitch->_04 * 27000 / pitch->_1A;
                if (rate % 10 >= 5) {
                    rate += 10;
                }
                rate /= 10;
            } else if (pitch->_00 != 0) {
                rate = 9999;
            } else {
                rate = 0;
            }
            if (pitch->_00 == 0) {
                fn_3_15C6E4(task, i + 37, 0, 22);
            } else {
                fn_3_15C6E4(task, i + 37, rate, 11);
            }
        }
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803537E4[team][j]._23;
        }
        fn_3_15C6E4(task, 12, total, 3);
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803535C8[team][j]._0A;
        }
        fn_3_15C6E4(task, 18, total, 3);
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803535C8[team][j]._1C;
        }
        fn_3_15C6E4(task, 24, total, 3);
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803535C8[team][j]._02;
        }
        fn_3_15C6E4(task, 30, total, 3);
        total = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803535C8[team][j]._1D;
        }
        fn_3_15C6E4(task, 36, total, 3);
        total = 0;
        total2 = 0;
        for (j = 0; j < 9; j++) {
            total += lbl_803535C8[team][j]._04;
            total2 += lbl_803535C8[team][j]._1A;
        }
        if (total2 == 0) {
            rate = 9999;
        } else {
            rate = total * 27000 / total2;
            if (rate % 10 >= 5) {
                rate += 10;
            }
            rate /= 10;
        }
        fn_3_15C6E4(task, 42, rate, 11);
    }
}

// .text:0x0015C6E4 size:0xAF4 mapped:0x8079B778
void fn_3_15C6E4(UnkTask3BD8* task, s32 id, s32 value, s32 type) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 rem;
    s32 whole;

    fn_800362F0(task, id);
    if (type == 21) {
        lbl_80371C30[task->_14 + id]._00->_64 = 0x10;
        fn_800363D8(task, id, 1, 0x1A, 14);
        fn_800363D8(task, id, 2, 0x1A, 14);
    } else if (type == 22) {
        lbl_80371C30[task->_14 + id]._00->_64 = 0x15;
        fn_800363D8(task, id, 3, 0x1A, 14);
        fn_800363D8(task, id, 2, 0x1A, 14);
        fn_800363D8(task, id, 1, 0x1A, 14);
        fn_800363D8(task, id, 6, 0x1A, 14);
        fn_800363D8(task, id, 5, 0x1A, 14);
        fn_800363D8(task, id, 4, 0x1A, 14);
    } else if (type == 10) {
        if (value >= 1000) {
            lbl_80371C30[task->_14 + id]._00->_64 = 0x18;
            fn_800363D8(task, id, 1, 0x1A, 1);
            fn_800363D8(task, id, 3, 0x1A, 0);
            fn_800363D8(task, id, 4, 0x1A, 0);
            fn_800363D8(task, id, 5, 0x1A, 0);
            fn_800363D8(task, id, 6, 0x1A, 1);
            fn_800363D8(task, id, 8, 0x1A, 0);
            fn_800363D8(task, id, 9, 0x1A, 0);
            fn_800363D8(task, id, 10, 0x1A, 0);
        } else {
            lbl_80371C30[task->_14 + id]._00->_64 = 0x19;
            a = value / 100;
            fn_800363D8(task, id, 2, 0x1A, a);
            b = (value / 10) % 10;
            fn_800363D8(task, id, 3, 0x1A, b);
            c = value % 10;
            fn_800363D8(task, id, 4, 0x1A, c);
            fn_800363D8(task, id, 6, 0x1A, a);
            fn_800363D8(task, id, 7, 0x1A, b);
            fn_800363D8(task, id, 8, 0x1A, c);
        }
    } else if (type == 11) {
        if (value >= 1000) {
            if (value >= 10000) {
                value = 9999;
            }
            lbl_80371C30[task->_14 + id]._00->_64 = 0x17;
            a = value / 1000;
            fn_800363D8(task, id, 1, 0x1A, a);
            b = (value / 100) % 10;
            fn_800363D8(task, id, 2, 0x1A, b);
            c = (value / 10) % 10;
            fn_800363D8(task, id, 4, 0x1A, c);
            d = value % 10;
            fn_800363D8(task, id, 5, 0x1A, d);
            fn_800363D8(task, id, 6, 0x1A, a);
            fn_800363D8(task, id, 7, 0x1A, b);
            fn_800363D8(task, id, 9, 0x1A, c);
            fn_800363D8(task, id, 10, 0x1A, d);
        } else {
            lbl_80371C30[task->_14 + id]._00->_64 = 0x16;
            a = (value / 100) % 10;
            fn_800363D8(task, id, 1, 0x1A, a);
            b = (value / 10) % 10;
            fn_800363D8(task, id, 3, 0x1A, b);
            c = value % 10;
            fn_800363D8(task, id, 4, 0x1A, c);
            fn_800363D8(task, id, 5, 0x1A, a);
            fn_800363D8(task, id, 7, 0x1A, b);
            fn_800363D8(task, id, 8, 0x1A, c);
        }
    } else {
        if (type == 12) {
            rem = value % 3;
            whole = value / 3;
            if (value == 0) {
                lbl_80371C30[task->_14 + id]._00->_64 = 0x11;
                fn_800363D8(task, id, 1, 0x1A, 11);
                fn_800363D8(task, id, 2, 0x1A, 11);
                return;
            }
            if (rem != 0) {
                if (whole >= 10) {
                    lbl_80371C30[task->_14 + id]._00->_64 = 0x14;
                    a = whole / 10;
                    fn_800363D8(task, id, 1, 0x1A, a);
                    b = whole % 10;
                    fn_800363D8(task, id, 2, 0x1A, b);
                    fn_800363D8(task, id, 3, 0x1A, rem + 11);
                    fn_800363D8(task, id, 4, 0x1A, a);
                    fn_800363D8(task, id, 5, 0x1A, b);
                    fn_800363D8(task, id, 6, 0x1A, rem + 11);
                } else if (whole != 0) {
                    lbl_80371C30[task->_14 + id]._00->_64 = 0x12;
                    fn_800363D8(task, id, 1, 0x1A, whole);
                    fn_800363D8(task, id, 2, 0x1A, rem + 11);
                    fn_800363D8(task, id, 3, 0x1A, whole);
                    fn_800363D8(task, id, 4, 0x1A, rem + 11);
                } else {
                    lbl_80371C30[task->_14 + id]._00->_64 = 0x11;
                    fn_800363D8(task, id, 1, 0x1A, rem + 11);
                    fn_800363D8(task, id, 2, 0x1A, rem + 11);
                }
                return;
            }
            value = whole;
        }
        if (value < 10) {
            lbl_80371C30[task->_14 + id]._00->_64 = 0x10;
            fn_800363D8(task, id, 1, 0x1A, value);
            fn_800363D8(task, id, 2, 0x1A, value);
        } else if (type == 2 || value < 100) {
            if (value >= 100) {
                value = 99;
            }
            lbl_80371C30[task->_14 + id]._00->_64 = 0x13;
            a = value % 10;
            fn_800363D8(task, id, 2, 0x1A, a);
            b = value / 10;
            fn_800363D8(task, id, 1, 0x1A, b);
            fn_800363D8(task, id, 4, 0x1A, a);
            fn_800363D8(task, id, 3, 0x1A, b);
        } else {
            if (value >= 1000) {
                value = 999;
            }
            lbl_80371C30[task->_14 + id]._00->_64 = 0x15;
            a = value % 10;
            fn_800363D8(task, id, 3, 0x1A, a);
            b = (value / 10) % 10;
            fn_800363D8(task, id, 2, 0x1A, b);
            c = value / 100;
            fn_800363D8(task, id, 1, 0x1A, c);
            fn_800363D8(task, id, 6, 0x1A, a);
            fn_800363D8(task, id, 5, 0x1A, b);
            fn_800363D8(task, id, 4, 0x1A, c);
        }
    }
}

// .text:0x0015C638 size:0xAC mapped:0x8079B6CC
void fn_3_15C638(void) {
    UnkTask3BD8* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_27C54);
    if (lbl_80353A90._104 == 2) {
        lbl_80371C30[task->_14]._00->_64 = 0xD3;
    } else if (lbl_80353A90._104 == 3) {
        lbl_80371C30[task->_14]._00->_64 = 0xC0;
    }
    ((UnkTask3BD8*)lbl_803CC1B8)->_00 = fn_3_15C5F4;
}

// .text:0x0015C5F4 size:0x44 mapped:0x8079B688
void fn_3_15C5F4(void) {
    UnkTask3BD8* task = lbl_803CC1B8;

    if (g_GameLogic._125 == 7) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}
