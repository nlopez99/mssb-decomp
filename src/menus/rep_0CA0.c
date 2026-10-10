#include "menus/rep_0CA0.h"
#include "header_rep_data.h"

typedef struct UnkTask0CA0 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16[0x18 - 0x16];
    /* 0x18 */ u16 _18;
} UnkTask0CA0;

typedef struct {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ s32 _54;
    /* 0x58 */ s32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[0x68 - 0x66];
    /* 0x68 */ u8 _68;
} UnkSprite0CA0;

typedef struct {
    /* 0x00 */ UnkSprite0CA0* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef0CA0; // size: 0x8

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc0CA0; // size: 0x20

extern UnkSpriteRef0CA0 lbl_80371C30[];
extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x2B];
    /* 0x2B */ u8 _2B;
    /* 0x2C */ u8 _2C[0x31 - 0x2C];
    /* 0x31 */ u8 _31;
    /* 0x32 */ u8 _32[0x5D - 0x32];
    /* 0x5D */ u8 _5D;
} lbl_803C66B0;

// Main-DOL .sbss object that symbols.txt lumped into lbl_803CBCD0 (+0x8)
extern struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ s8 _1;
    /* 0x2 */ u8 _2[0x4 - 0x2];
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
} lbl_803CBCD8;

extern struct {
    /* 0x00 */ u8 _00[0xE4];
    /* 0xE4 */ u8 _E4[0xF4 - 0xE4];
    /* 0xF4 */ u8 _F4;
    /* 0xF5 */ u8 _F5;
} lbl_80361B20;

extern struct {
    /* 0x00 */ u8 _00[0x44];
    /* 0x44 */ s32 _44;
} lbl_2_bss_F410;

// Main-DOL .sbss object that symbols.txt lumps into lbl_803CBBC2 (+0x2)
extern struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
} lbl_803CBBC4;

extern struct {
    /* 0x00 */ u8 _00[0x57];
    /* 0x57 */ u8 _57;
    /* 0x58 */ u8 _58;
} lbl_2_bss_F468;

extern struct {
    /* 0x00 */ u8 _00[0x47];
    /* 0x47 */ u8 _47;
} lbl_803C50E8;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x8 - 0x1];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
} lbl_8034E978;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} lbl_800FEF70[]; // size: 0x10

extern struct {
    /* 0x0 */ u8 _0[0x2];
    /* 0x2 */ u16 _2;
    /* 0x4 */ u8 _4[0x6 - 0x4];
    /* 0x6 */ u16 _6;
}* lbl_803CBBCC;

static u8 lbl_2_bss_ABC4[0x6D4];
static u8 lbl_2_bss_ABC0;

static char lbl_2_data_2D998[2][0x20] = { "BAT FIRST", "BAT LAST" };
static char lbl_2_data_2D9D8[2][0x20] = { "FL", "PC" };
static char lbl_2_data_2DA18[4][4] = { "RR", "RL", "LR", "LL" };
static char lbl_2_data_2DA28[2][0x20] = { "OFF", "ON" };
static char lbl_2_data_2DA68[5][0x20] = {
    "SELECT DEBUG MENU", "HIDE CHARA SET", "STAR PLAYER SET", "KOOPA STA FLAG SET", "CHALLE LEVEL FREE SET",
};
static char lbl_2_data_2DB08[8][0x20] = {
    "1P >", "COM1>", "2P >", "COM2>", "3P >", "COM3>", "4P >", "COM4>",
};
static u32 lbl_2_data_2DC08[8] = { 0xFF0F, 0x880F, 0x0FFF, 0x088F, 0xF0FF, 0x808F, 0xF00F, 0x800F };
static s16 lbl_2_data_2DC28[12] = { 0, 4, 10, 6, 2, 9, 1, 5, 11, 17, 3, 19 };
static u8 lbl_2_data_2DC40[2][13] = {
    { 0, 2, 6, 8, 4, 10, 1, 3, 7, 5, 9, 11 },
    { 0, 6, 2, 8, 4, 10, 5, 11, 3, 9, 1, 7 },
};
static u8 lbl_2_data_2DC5C[40] = {
    2, 5, 4, 3, 8, 3, 4, 5, 2, 6, 0, 1, 8, 6, 7, 1, 2, 0, 7, 4,
    4, 3, 1, 2, 5, 1, 2, 4, 6, 8, 7, 6, 8, 5, 3, 3, 5, 7, 4, 6,
};
static u8 lbl_2_data_2DC84[8] = { 0, 4, 2, 3, 5, 1, 0, 0 };
static UnkSpriteDesc0CA0 lbl_2_data_2DC8C[29] = {
    { 0, 31, { 0, 0, -1 }, { 0, 20 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 31, { 0, 0, 0xFFFFFF00 }, { 0, 20 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 33, { 0, 0, -1 }, { 1, 7 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 35, { 0, 0, -1 }, { 1, 7 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 38, { 0, 0, -1 }, { 0, 7 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 29, { 0, 0, -1 }, { 1, 6 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 27, { 0, 0, 0xFFFFFF00 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010005 } },
    { 0, 27, { 0, 0, 0xFFFFFF00 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010004 } },
    { 0, 27, { 0, 0, 0xFFFFFF00 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010003 } },
    { 0, 27, { 0, 0, 0xFFFFFF00 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010002 } },
    { 0, 27, { 0, 0, 0xFFFFFF00 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010001 } },
    { 0, 27, { 0, 0, 0xFFFFFF00 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
    { 0, 31, { 0, 0, -1 }, { 1, 8 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 31, { 0, 0, -1 }, { 1, 8 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 33, { 0, 0, -1 }, { 1, 7 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 35, { 0, 0, -1 }, { 1, 7 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 38, { 0, 0, -1 }, { 0, 7 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 28, { 0, 0, -1 }, { 1, 6 }, 255, { 0x06000000, 0, 0x00010000 } },
    { 0, 27, { 0, 0, -1 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010004 } },
    { 0, 27, { 0, 0, -1 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010003 } },
    { 0, 27, { 0, 0, -1 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010002 } },
    { 0, 27, { 0, 0, -1 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010001 } },
    { 0, 27, { 0, 0, -1 }, { 0, 5 }, 5, { 0x06000000, 0, 0x00010000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
    { 0, 301, { 0, 0, -1 }, { 1, 22 }, 255, { 0x01000000, 0, 0x00010000 } },
    { 0, 301, { 0, 0, 0xFFFFFF00 }, { 1, 22 }, 255, { 0x01000000, 0, 0x00010000 } },
    { 0, 302, { 0, 0, -1 }, { 1, 22 }, 255, { 0x01000000, 0, 0x00010000 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
};
static UnkSpriteDesc0CA0 lbl_2_data_2E02C[22] = {
    { 0, 32, { 0, 0, -1 }, { 0, 21 }, 255, { 0x09000000, 0, 0x00010000 } },
    { 0, 33, { 0, 0, -1 }, { 0, 8 }, 255, { 0x09000000, 0, 0x00010000 } },
    { 0, 37, { 0, 0, -1 }, { 1, 21 }, 255, { 0x09000000, 0, 0x00010000 } },
    { 0, 105, { 0, 0, -1 }, { 0, 21 }, 2, { 0x09000000, 0, 0x00010003 } },
    { 0, 105, { 0, 0, -1 }, { 0, 21 }, 2, { 0x09000000, 0, 0x00010002 } },
    { 0, 105, { 0, 0, -1 }, { 0, 21 }, 2, { 0x09000000, 0, 0x00010001 } },
    { 0, 105, { 0, 0, -1 }, { 0, 21 }, 2, { 0x09000000, 0, 0x00010000 } },
    { 0, 99, { 0, 0, -1 }, { 1, 8 }, 255, { 0x09000000, 0, 0x00010000 } },
    { 0, 98, { 0, 0, -1 }, { 1, 8 }, 255, { 0x09000000, 0, 0x00010000 } },
    { 0, 36, { 0, 0, -1 }, { 2, 8 }, 255, { 0x09000000, 0, 0x00010000 } },
    { 0, 97, { 0, 0, -1 }, { 1, 8 }, 255, { 0x09000000, 0, 0x00010000 } },
    { 0, 90, { 0, 0, -1 }, { 0, 7 }, 10, { 0x09000000, 0, 0x00010000 } },
    { 0, 93, { 0, 0, -1 }, { 0, 7 }, 10, { 0x09000000, 0, 0x00010001 } },
    { 3, 0, { 0, 0, 0 }, { 0, 0 }, 0, { 0, 0, 0 } },
    { 0, 1035, { 0x4037CF5C, 0x18B3A800, 0x00208AF0 }, { 0, 0 }, 1035, { 0x400ADFFC, 0x18AEE800, 0x0004BAB0 } },
    { 0, 1035, { 0x400193E8, 0x191B8800, 35288 }, { 0, 0 }, 1035, { 0x4010E5A0, 0x0E97A800, 0x0009BCAC } },
    { 0, 1035, { 0x40016980, 0x0EA16800, 54980 }, { 0, 0 }, 1035, { 0x40016980, 0x0EA24000, 51524 } },
    { 0, 1035, { 0x40016980, 0x0EA31000, 59136 }, { 0, 0 }, 1035, { 0x40016980, 0x0EA3F800, 54860 } },
    { 0, 1035, { 0x40016980, 0x0EA4D000, 51456 }, { 0, 0 }, 1035, { 0x40016980, 0x0EA5A000, 53244 } },
    { 0, 1035, { 0x40016980, 0x0EA67000, 55072 }, { 0, 0 }, 1035, { 0x40016980, 0x0EA74800, 54988 } },
    { 0, 1035, { 0x40016980, 0x0EA82000, 53788 }, { 0, 0 }, 1035, { 0x40016980, 0x0EA8F800, 53436 } },
    { 0, 1035, { 0x40016980, 0x0EA9D000, 46404 }, { 0, 0 }, 1035, { 0x40016980, 0x0EAA8800, 50424 } },
};
static s8 lbl_2_data_2E2EC = -1;
static s8 lbl_2_data_2E2ED = -1;

extern s32 fn_80042DA8(UnkTask0CA0* task, s32 index, s32 value);
extern void fn_80062674(s32 index);
extern void fn_800626EC(s32 index);
extern void fn_80034E20(UnkTask0CA0* task, UnkSpriteDesc0CA0* desc);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800363D8(UnkTask0CA0* task, s32 id, s32 part, s32 kind, s32 value);
extern void fn_80034CEC(UnkTask0CA0* task);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80053FE8(void);
extern void fn_2_82DE8(void);

static inline BOOL isZero(u8 value) {
    return value == 0 ? TRUE : FALSE;
}

static inline s16 getIcon0CA0(s32 sel, s16 special) {
    BOOL b = FALSE;

    if (lbl_2_data_2DC84[lbl_2_bss_F410._44] == 1 && lbl_80361B20._F5 == 0) {
        b = TRUE;
    }
    return b ? special : lbl_2_data_2DC84[sel];
}

// .text:0x00084FA8 size:0x160
void fn_2_84FA8(void) {
    UnkTask0CA0* task = lbl_803CC1B8;
    s32 i;
    s8 v;

    fn_80034E20(task, lbl_2_data_2DC8C);
    for (i = 0; i < 6; i++) {
        if (lbl_80361B20._F5 == 0 && lbl_2_data_2DC84[i] == 1) {
            v = 6;
        } else {
            v = lbl_2_data_2DC84[i];
        }
        fn_800363D8(task, i + 6, 2, 0x1E, v);
    }
    if (lbl_80361B20._F5 == 0 && lbl_2_data_2DC84[lbl_2_bss_F410._44] == 1) {
        v = 0x12;
    } else {
        v = lbl_2_data_2DC84[lbl_2_bss_F410._44];
    }
    if (lbl_2_bss_F410._44 != 0) {
        fn_800363D8(task, 0, 1, 0x20, v);
    }
    lbl_803CBCD8._4 = 0;
    task->_18 = 0;
    ((UnkTask0CA0*)lbl_803CC1B8)->_00 = fn_2_845A8;
}

// .text:0x000845A8 size:0xA00
void fn_2_845A8(void) {
    UnkTask0CA0* task = lbl_803CC1B8;
    u8 base;
    s32 first;
    s32 i;
    s32 sel;
    s32 icon;

    if (lbl_803CBCD8._4) {
        lbl_803CBCD8._4 = 0;
        lbl_2_data_2E2EC = -1;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    lbl_2_data_2E2ED = -1;
    switch (lbl_803C66B0._5D) {
    case 39:
        fn_2_84388(task);
        break;
    case 36:
        fn_2_84194(task);
        break;
    case 38:
        fn_2_837D8(task);
        break;
    case 37:
        fn_2_83974(task);
        break;
    case 49:
        fn_2_83744(task);
        break;
    case 40:
        fn_2_83B34(task, lbl_2_bss_F410._44);
        break;
    }
    if (lbl_803CBCD8._4 == 0 && lbl_803C66B0._5D != 37 && lbl_803C66B0._5D != 36) {
        sel = lbl_2_bss_F410._44;
        if (lbl_803CBBCC->_2 != 13 && lbl_2_bss_F468._58 == 0 && lbl_2_data_2E2EC == sel &&
            lbl_2_data_2E2ED == -1) {
            if (lbl_80361B20._F5 == 0 && lbl_2_data_2DC84[sel] == 1) {
                fn_800363D8(task, 0, 1, 0x20, 0x12);
                fn_800363D8(task, 1, 1, 0x20, 0x12);
                return;
            }
            for (i = 0; i < 3; i++) {
                if (task->_18 == i * 100) {
                    base = lbl_2_data_2DC84[sel];
                    first = base + i * 6;
                    if (lbl_2_bss_ABC0) {
                        icon = base + 12;
                        lbl_2_bss_ABC0 = 0;
                    } else if (i != 0) {
                        icon = base + (i - 1) * 6;
                    } else {
                        icon = base;
                    }
                    lbl_80371C30[task->_14]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 1]._00->_5C = 0xA0000;
                    fn_800363D8(task, 0, 1, 0x20, first);
                    fn_800363D8(task, 1, 1, 0x20, icon);
                    lbl_80371C30[task->_14]._00->_58 = (lbl_80371C30[task->_14]._00->_58 & 0xFFFFFF00) | 0xFF;
                    lbl_80371C30[task->_14 + 1]._00->_58 = (lbl_80371C30[task->_14 + 1]._00->_58 & 0xFFFFFF00) | 0xFF;
                    lbl_80371C30[task->_14]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 1]._00->_68 = 4;
                }
            }
            fn_80042DA8(task, 0, 10);
            fn_80042DA8(task, 1, 0);
            task->_18++;
            if ((s32)task->_18 > 300) {
                task->_18 = 0;
                lbl_2_bss_ABC0 = 1;
            }
        }
    }
}

// .text:0x00084388 size:0x220
void fn_2_84388(UnkTask0CA0* task) {
    s32 i;
    s32 sel;
    s32 done;

    if (isZero(lbl_803C66B0._2B)) {
        lbl_80371C30[task->_14]._00->_5C = 0;
        lbl_80371C30[task->_14]._00->_68 = 1;
        sel = lbl_2_bss_F410._44;
        lbl_80371C30[task->_14 + 4]._00->_5C = 0;
        lbl_80371C30[task->_14 + 4]._00->_68 = 1;
        for (i = 6; i < 12; i++) {
            lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & 0xFFFFFF00) | 0xFF;
        }
        lbl_80371C30[task->_14 + 6 + sel]._00->_5C = 0x10000;
        lbl_80371C30[task->_14 + 6 + sel]._00->_68 = 1;
        fn_800626EC(0);
        lbl_803C66B0._2B = 1;
    }
    if (lbl_803C66B0._2B == 1) {
        done = fn_80042DA8(task, 0, 10) != 0;
        if (done + (fn_80042DA8(task, 4, 20) != 0) == 2) {
            lbl_2_data_2E2EC = lbl_2_bss_F410._44;
            fn_80062674(0);
            lbl_803C66B0._2B = 2;
        }
    }
}

// .text:0x00084194 size:0x1F4
void fn_2_84194(UnkTask0CA0* task) {
    s32 done;

    if (isZero(lbl_803C66B0._2B)) {
        lbl_80371C30[task->_14]._00->_5C = 0xA0000;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0xA0000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_80371C30[task->_14 + 2]._00->_68 = 4;
        lbl_80371C30[task->_14 + 3]._00->_68 = 4;
        lbl_80371C30[task->_14 + 5]._00->_68 = 4;
        lbl_80371C30[task->_14 + 4]._00->_68 = 4;
        fn_800626EC(0);
        lbl_803C66B0._2B = 1;
    }
    if (lbl_803C66B0._2B == 1) {
        done = fn_80042DA8(task, 0, 0) != 0;
        done += fn_80042DA8(task, 1, 0) != 0;
        done += fn_80042DA8(task, 2, 0) != 0;
        done += fn_80042DA8(task, 3, 0) != 0;
        done += fn_80042DA8(task, 5, 0) != 0;
        if (done == 5) {
            lbl_2_data_2E2EC = lbl_2_bss_F410._44;
            fn_80062674(0);
            lbl_803C66B0._2B = 2;
            lbl_2_data_2E2EC = -1;
            fn_80034CEC(task);
            fn_800B0A14_removeQueue();
        }
    }
}

// .text:0x00083B34 size:0x660
void fn_2_83B34(UnkTask0CA0* task, s32 sel) {
    s32 i;
    s16 icon;
    u8 v;
    s32 n;
    s32 want;

    if (isZero(lbl_803C66B0._2B)) {
        for (i = 0; i < 6; i++) {
            lbl_80371C30[6 + task->_14 + i]._00->_68 = 0;
            lbl_80371C30[6 + task->_14 + i]._00->_5C = 0;
        }
        if (lbl_803CBCD8._0 != 0) {
            if (lbl_803CBCD8._1 == 0) {
                lbl_80371C30[task->_14]._00->_58 = (lbl_80371C30[task->_14]._00->_58 & 0xFFFFFF00) | 0xFF;
                lbl_80371C30[task->_14 + 1]._00->_58 = (lbl_80371C30[task->_14 + 1]._00->_58 & 0xFFFFFF00) | 0xFF;
                lbl_80371C30[task->_14]._00->_5C = 0;
                lbl_80371C30[task->_14 + 1]._00->_5C = 0xA0000;
                fn_800363D8(task, 0, 1, 0x20, lbl_2_data_2DC84[sel]);
                if (lbl_2_data_2E2EC == -1) {
                    fn_800363D8(task, 1, 1, 0x20, lbl_2_data_2DC84[sel]);
                } else {
                    fn_800363D8(task, 1, 1, 0x20, lbl_2_data_2DC84[lbl_2_data_2E2EC]);
                }
                lbl_80371C30[task->_14]._00->_68 = 1;
                lbl_80371C30[task->_14 + 1]._00->_68 = 1;
                sel = lbl_2_data_2E2EC;
            }
        } else {
            lbl_80371C30[task->_14]._00->_58 = (lbl_80371C30[task->_14]._00->_58 & 0xFFFFFF00) | 0xFF;
            lbl_80371C30[task->_14 + 1]._00->_58 = (lbl_80371C30[task->_14 + 1]._00->_58 & 0xFFFFFF00) | 0xFF;
            lbl_80371C30[task->_14]._00->_5C = 0;
            lbl_80371C30[task->_14 + 1]._00->_5C = 0xA0000;
            fn_800363D8(task, 0, 1, 0x20, getIcon0CA0(sel, 0x12));
            if (lbl_2_data_2E2EC == -1) {
                fn_800363D8(task, 1, 1, 0x20, getIcon0CA0(sel, 0x12));
            } else {
                v = lbl_2_data_2DC84[lbl_2_data_2E2EC];
                if (v == 1 && lbl_80361B20._F5 == 0) {
                    icon = 0x12;
                } else {
                    icon = v;
                }
                fn_800363D8(task, 1, 1, 0x20, icon);
            }
            lbl_80371C30[task->_14]._00->_68 = 1;
            lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        }
        lbl_80371C30[6 + task->_14 + sel]._00->_5C = 0x10000;
        lbl_80371C30[6 + task->_14 + sel]._00->_68 = 1;
        icon = getIcon0CA0(sel, 6);
        lbl_80371C30[task->_14 + 2]._00->_5C = 0;
        fn_800363D8(task, 2, 1, 0x22, icon);
        icon = getIcon0CA0(sel, 6);
        lbl_80371C30[task->_14 + 3]._00->_5C = 0;
        fn_800363D8(task, 3, 1, 0x25, icon);
        fn_800363D8(task, 3, 3, 0x24, icon);
        lbl_80371C30[task->_14 + 3]._00->_68 = 1;
        lbl_803C66B0._2B = 1;
    }
    if (lbl_803C66B0._2B == 1) {
        n = 0;
        want = 0;
        if (lbl_803CBCD8._1 == 0) {
            n = fn_80042DA8(task, 0, 10) != 0;
            n += fn_80042DA8(task, 1, 0) != 0;
            want += 3;
            n += fn_80042DA8(task, sel + 6, 4) != 0;
        }
        if (n == want) {
            lbl_2_data_2E2ED = lbl_2_data_2E2EC;
            lbl_2_data_2E2EC = sel;
            task->_18 = 0;
            if (lbl_803CBCD8._1 < 0) {
                lbl_803CBCD8._1 = 0;
                lbl_803CBCD8._0 = 0;
            }
            lbl_803C66B0._2B = 2;
            lbl_803C66B0._5D = 0;
        }
    }
}

// .text:0x00083974 size:0x1C0
void fn_2_83974(UnkTask0CA0* task) {
    s32 done;

    if (isZero(lbl_803C66B0._2B)) {
        lbl_80371C30[task->_14]._00->_5C = 0xA0000;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0;
        lbl_80371C30[task->_14]._00->_68 = 1;
        lbl_80371C30[task->_14 + 1]._00->_68 = 0;
        lbl_80371C30[task->_14 + 2]._00->_68 = 4;
        lbl_80371C30[task->_14 + 3]._00->_68 = 4;
        lbl_80371C30[task->_14 + 5]._00->_68 = 4;
        lbl_80371C30[task->_14 + 4]._00->_68 = 1;
        fn_800626EC(0);
        lbl_803C66B0._2B = 1;
    }
    if (lbl_803C66B0._2B == 1) {
        done = fn_80042DA8(task, 0, 20) != 0;
        done += fn_80042DA8(task, 2, 0) != 0;
        done += fn_80042DA8(task, 5, 0) != 0;
        done += fn_80042DA8(task, 3, 0) != 0;
        if (done == 4) {
            lbl_2_data_2E2EC = lbl_2_bss_F410._44;
            fn_80062674(0);
            lbl_803C66B0._2B = 2;
        }
    }
}

// .text:0x000837D8 size:0x19C
void fn_2_837D8(UnkTask0CA0* task) {
    s32 value;
    s32 done;

    if (isZero(lbl_803C66B0._2B)) {
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0;
        lbl_80371C30[task->_14 + 1]._00->_68 = 0;
        lbl_80371C30[task->_14 + 2]._00->_68 = 1;
        lbl_80371C30[task->_14 + 5]._00->_68 = 1;
        lbl_80371C30[task->_14 + 3]._00->_68 = 1;
        lbl_80371C30[task->_14 + 4]._00->_5C = 0x280000;
        lbl_80371C30[task->_14 + 4]._00->_68 = 4;
        fn_800626EC(0);
        lbl_803C66B0._2B = 1;
    }
    if (lbl_803C66B0._2B == 1) {
        done = fn_80042DA8(task, 0, 10) != 0;
        if (done + (fn_80042DA8(task, 4, 20) != 0) == 2) {
            value = lbl_2_bss_F410._44;
            if (lbl_80361B20._F5 == 0 && value != 0) {
                value--;
            }
            lbl_2_data_2E2EC = value;
            fn_80062674(0);
            lbl_803C66B0._2B = 2;
        }
    }
}

// .text:0x00083744 size:0x94
void fn_2_83744(UnkTask0CA0* task) {
    UnkSprite0CA0* sprite = lbl_80371C30[task->_14]._00;

    if ((sprite->_5C >> 16) == 20) {
        sprite->_68 = 1;
    }
    if ((lbl_80371C30[task->_14]._00->_5C >> 16) == 30) {
        lbl_803CBCD8._4 = 1;
        fn_80062674(0);
        lbl_803C66B0._31 = 2;
    }
}

// .text:0x000836A4 size:0xA0
void fn_2_836A4(void) {
    if (lbl_803C50E8._47) {
        fn_800B0A5C_insertQueue(fn_80053FE8, 0);
    }
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._00 = 12;
    lbl_8034E978._08 = lbl_800FEF70[12]._08;
    if (lbl_803CBBCC->_6 != 9) {
        fn_800B0A5C_insertQueue(fn_2_82DE8, 0x3000);
    }
    fn_800B0A5C_insertQueue(fn_2_834F0, 0x3000);
}

// .text:0x000834F0 size:0x1B4
void fn_2_834F0(void) {
    UnkTask0CA0* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2E02C);
    for (i = 0; i < 4; i++) {
        if (lbl_2_bss_F468._57 < i) {
            fn_800363D8(task, i + 3, 1, 0x6B, 4);
        } else {
            fn_800363D8(task, i + 3, 1, 0x6B, i);
        }
    }
    lbl_80371C30[task->_14 + 12]._00->_5C = 0;
    if (lbl_80361B20._F4) {
        lbl_80371C30[task->_14 + 1]._00->_64 = 0x22;
        lbl_80371C30[task->_14 + 11]._00->_5C = 0x40000;
    } else {
        lbl_80371C30[task->_14 + 1]._00->_64 = 0x21;
        lbl_80371C30[task->_14 + 11]._00->_5C = 0;
    }
    if (lbl_80361B20._E4[0]) {
        lbl_80371C30[task->_14 + 9]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 9]._00->_68 = 1;
        fn_800363D8(task, 9, 1, 0x27, 0);
    }
    ((UnkTask0CA0*)lbl_803CC1B8)->_00 = fn_2_82EC0;
}

// .text:0x00082EC0 size:0x630
void fn_2_82EC0(void) {
    UnkTask0CA0* task = lbl_803CC1B8;
    s32 sel = lbl_2_bss_F410._44;
    u8 prev = lbl_803CBBC4._1;
    s32 i;

    switch (lbl_803CBBC4._0) {
    case 0x5D:
        if (isZero(lbl_803CBBC4._2)) {
            lbl_80371C30[task->_14]._00->_68 = 1;
            lbl_80371C30[task->_14 + 1]._00->_68 = 1;
            lbl_80371C30[task->_14 + 2]._00->_68 = 1;
            lbl_80371C30[3 + task->_14 + sel]._00->_68 = 1;
            lbl_803CBBC4._2 = 1;
            lbl_803CBBC4._3 = 1;
        }
        if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
            lbl_803CBBC4._0 = 0;
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0x5F;
        }
        break;
    case 0x5F:
        if ((lbl_80371C30[3 + task->_14 + sel]._00->_5C >> 16) >= 55) {
            lbl_80371C30[3 + task->_14 + sel]._00->_5C = 0x50000;
            lbl_80371C30[3 + task->_14 + sel]._00->_68 = 1;
        }
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= 35) {
            lbl_80371C30[task->_14]._00->_5C = 0x230000;
            lbl_80371C30[task->_14]._00->_68 = 0;
        }
        break;
    case 0x5E:
        if (isZero(lbl_803CBBC4._2)) {
            lbl_80371C30[3 + task->_14 + sel]._00->_68 = 1;
            if (lbl_2_bss_F468._57 >= sel) {
                lbl_80371C30[task->_14 + 12]._00->_5C = sel << 16;
                if (lbl_80361B20._F4) {
                    lbl_80371C30[task->_14 + 11]._00->_5C = (sel + 4) << 16;
                } else {
                    lbl_80371C30[task->_14 + 11]._00->_5C = sel << 16;
                }
            } else {
                lbl_80371C30[task->_14 + 12]._00->_5C = 0x80000;
                lbl_80371C30[task->_14 + 11]._00->_5C = 0x80000;
            }
            if (lbl_80361B20._E4[sel]) {
                fn_800363D8(task, 9, 1, 0x27, sel);
            } else {
                fn_800363D8(task, 9, 1, 0x27, 4);
            }
            if (prev != -1) {
                lbl_80371C30[3 + task->_14 + prev]._00->_5C = 0;
                lbl_80371C30[3 + task->_14 + prev]._00->_68 = 0;
            }
            lbl_803CBBC4._2 = 1;
            lbl_803CBBC4._3 = 1;
        }
        if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
            lbl_803CBBC4._0 = 0;
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0x5F;
        }
        break;
    case 0x60:
        if (isZero(lbl_803CBBC4._2)) {
            lbl_80371C30[task->_14]._00->_5C = 0x230000;
            lbl_80371C30[task->_14]._00->_68 = 1;
            lbl_80371C30[task->_14 + 1]._00->_68 = 4;
            lbl_80371C30[3 + task->_14 + sel]._00->_5C = 0x370000;
            lbl_80371C30[3 + task->_14 + sel]._00->_68 = 1;
            lbl_80371C30[task->_14 + 7]._00->_68 = 4;
            lbl_80371C30[task->_14 + 8]._00->_68 = 4;
            lbl_80371C30[task->_14 + 10]._00->_68 = 4;
            lbl_80371C30[task->_14 + 9]._00->_68 = 4;
            lbl_803CBBC4._2 = 1;
            lbl_803CBBC4._3 = 1;
        }
        if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
            if ((fn_80042DA8(task, sel + 3, 70) ? TRUE : FALSE) == TRUE) {
                lbl_803CBBC4._0 = 0;
                lbl_803CBBC4._3 = 0;
                lbl_803CBBC4._2 = 0;
                lbl_803CBBC4._0 = 0x61;
            }
        }
        break;
    case 0x61:
        if (isZero(lbl_803CBBC4._2)) {
            lbl_80371C30[task->_14 + 2]._00->_68 = 4;
            for (i = 0; i < 4; i++) {
                lbl_80371C30[3 + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[3 + task->_14 + i]._00->_68 = 0;
            }
            lbl_803CBBC4._2 = 1;
            lbl_803CBBC4._3 = 1;
        }
        if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
            if ((fn_80042DA8(task, 2, 0) ? TRUE : FALSE) == TRUE) {
                lbl_803CBBC4._0 = 0;
                lbl_803CBBC4._3 = 0;
                lbl_803CBBC4._2 = 0;
                lbl_803CBBC4._4 = 1;
            }
        }
        break;
    }
    if (lbl_803CBBC4._4 && lbl_803CBBC4._3 != 1) {
        lbl_803CBBC4._4 = 0;
        lbl_803CBBC4._5 = 1;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}
