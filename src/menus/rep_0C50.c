#include "menus/rep_0C50.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct UnkTask0C50 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
} UnkTask0C50;

typedef struct {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ s32 _54;
    /* 0x58 */ s32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[0x68 - 0x66];
    /* 0x68 */ u8 _68;
} UnkSprite0C50;

typedef struct {
    /* 0x00 */ UnkSprite0C50* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef0C50; // size: 0x8

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc0C50; // size: 0x20

extern UnkSpriteRef0C50 lbl_80371C30[];
extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x7];
    /* 0x07 */ u8 _07;
    /* 0x08 */ u8 _08[0xD - 0x8];
    /* 0x0D */ u8 _0D[0x55 - 0xD];
    /* 0x55 */ u8 _55[4];
    /* 0x59 */ u8 _59[4];
    /* 0x5D */ u8 _5D[0x64 - 0x5D];
} lbl_803C66B0;

// Main-DOL .sbss object that symbols.txt lumps into lbl_803CBBC2 (+0x2)
extern struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
} lbl_803CBBC4;

// Main-DOL .sbss object that symbols.txt lumped into lbl_803CBCD0 (+0x8)
extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
} lbl_803CBCD8;

extern struct {
    /* 0x00 */ u8 _00[2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ s8 _14[2][9];
    /* 0x26 */ u8 _26[2][9];
    /* 0x38 */ s8 _38[2][9];
    /* 0x4A */ s8 _4A[2][9];
} lbl_803C6724;

extern struct {
    /* 0x00 */ u8 _00[6][9];
    /* 0x36 */ u8 _36[0xF4 - 0x36];
    /* 0xF4 */ u8 _F4;
} lbl_80361B20;

typedef struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0xA0 - 0x1];
} UnkRosterEntry0C50; // size: 0xA0

extern struct {
    /* 0x0000 */ u8 _0000[0x34];
    /* 0x0034 */ UnkRosterEntry0C50 _0034[2][9];
    /* 0x0B74 */ u8 _0B74[0x46E0 - 0xB74];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x46F8 - 0x46E8];
    /* 0x46F8 */ s8 _46F8;
    /* 0x46F9 */ u8 _46F9[0x470D - 0x46F9];
    /* 0x470D */ u8 _470D[2];
    /* 0x470F */ u8 _470F[0x472A - 0x470F];
    /* 0x472A */ u8 _472A;
    /* 0x472B */ u8 _472B;
    /* 0x472C */ u16 _472C;
    /* 0x472E */ u8 _472E[0x4748 - 0x472E];
    /* 0x4748 */ UnkTask0C50* _4748;
    /* 0x474C */ u8 _474C[0x4751 - 0x474C];
    /* 0x4751 */ u8 _4751;
    /* 0x4752 */ u8 _4752;
    /* 0x4753 */ u8 _4753[0x48AF - 0x4753];
    /* 0x48AF */ u8 _48AF;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0x11];
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12[0x36 - 0x12];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
} lbl_803C5EA4;

extern UnkSpriteDesc0C50 lbl_2_data_2AADC[];
extern UnkSpriteDesc0C50 lbl_2_data_2B4DC[];

extern u8 lbl_800FE930[2][6];

extern s32 lbl_2_bss_A840;
extern s32 lbl_2_bss_A844;
extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ u8 _08[0x10 - 0x8];
    /* 0x10 */ s32 _10[2];
} lbl_2_bss_F410;
extern struct {
    /* 0x00 */ s32 _00[4];
    /* 0x10 */ u8 _10[0x37 - 0x10];
    /* 0x37 */ u8 _37[2];
    /* 0x39 */ u8 _39[0x41 - 0x39];
    /* 0x41 */ u8 _41[2];
    /* 0x43 */ u8 _43[2];
    /* 0x45 */ u8 _45[0x56 - 0x45];
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[0x59 - 0x57];
    /* 0x59 */ u8 _59[0x5F - 0x59];
    /* 0x5F */ u8 _5F[2];
    /* 0x61 */ s8 _61[2];
    /* 0x63 */ u8 _63[2];
    /* 0x65 */ u8 _65[2];
} lbl_2_bss_F468;
extern UnkSpriteDesc0C50 lbl_2_data_2D33C[];
extern UnkSpriteDesc0C50 lbl_2_data_2AF4C[];
extern u8 lbl_2_data_2B3A4[];

extern u8 lbl_800FE5D4[];
extern u8 lbl_80108EC4[];
extern u8 lbl_2_data_2AF08[];

extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u8 _10;
} lbl_8037169C;

extern struct {
    /* 0x0000 */ u8 _0000[0x441D];
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ s8 _441F;
} starMissionCompletionTracker;
extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u8 _10;
} lbl_2_bss_100B8;

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
    /* 0x0 */ u8 _0[0x6];
    /* 0x6 */ u16 _6;
}* lbl_803CBBCC;

extern s32 fn_80042DA8(UnkTask0C50* task, s32 index, s32 value);
extern void fn_80062674(s32 index);
extern void fn_800626EC(s32 index);
extern void fn_80034E20(UnkTask0C50* task, UnkSpriteDesc0C50* desc);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800363D8(UnkTask0C50* task, s32 id, s32 part, s32 kind, s32 value);
extern void fn_800625A4(s32 index, s32 value);
extern s32 fn_80036214(UnkTask0C50* task, s32 id, s32 arg2, s32 arg3);
extern void fn_80034CEC(UnkTask0C50* task);
extern void fn_800B0A14_removeQueue(void);
extern void fn_8004E2EC(void);
extern void fn_8004F964(void);
extern void fn_80053FE8(void);
extern void fn_80051D00(void);
extern void changeScene(u8, s16);
extern s32 fn_2_8794(s32 flag, s32 value);
extern void fn_2_CCE0(u8 index);
extern void fn_2_16A74(s32 port, s32 flag);
extern void fn_2_102C8(u8 index);

static inline BOOL isAnimDone(UnkTask0C50* task, s32 index, s32 value) {
    return fn_80042DA8(task, index, value) ? TRUE : FALSE;
}

// .text:0x00082DE8 size:0x70
void fn_2_82DE8(void) {
    lbl_8034E9A0._4748 = lbl_803CC1B8;
    lbl_8034E9A0._48AF = 0;
    lbl_803C5EA4._37 = 0;
    lbl_803C5EA4._38 = 0;
    fn_80034E20(lbl_803CC1B8, lbl_2_data_2B4DC);
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_82CF0;
}

// .text:0x00082CF0 size:0xF8
void fn_2_82CF0(void) {
    UnkTask0C50* task = lbl_8034E9A0._4748;

    if (lbl_803C5EA4._36) {
        lbl_80371C30[task->_14]._00->_5C = 0;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x280000;
        lbl_80371C30[task->_14 + 2]._00->_64 = lbl_803C5EA4._38 + 0x123;
        lbl_80371C30[task->_14 + 3]._00->_64 = lbl_803C5EA4._37 + 0x123;
        lbl_80371C30[task->_14]._00->_68 = 1;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_803C5EA4._36 = 0;
    }
    if (lbl_8034E9A0._48AF) {
        lbl_8034E9A0._48AF = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00080E0C size:0x150
void fn_2_80E0C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index, 20);
        s32 expected = 2;

        n += isAnimDone(task, index + 2, 20);
        if (index == 0 || lbl_2_bss_100B8._10 != 0 || g_d_GameSettings._10 != 0) {
            n += isAnimDone(task, index + 0x85, 10);
            n += isAnimDone(task, index + 0x87, 10);
            n += isAnimDone(task, index + 0x89, 5);
            expected = 6;
            n += isAnimDone(task, index + 0x8B, 10);
        }
        if (n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00080C2C size:0x1E0
void fn_2_80C2C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (lbl_803C66B0._55[index]) {
            fn_80062674(index);
            lbl_803C66B0._5D[index] = 2;
        }
        lbl_80371C30[task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + index]._00->_68 = 4;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[4 + task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[4 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x80 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x78 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x7C + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xAC + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[task->_14 + 0x84]._00->_54 &= ~2;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00080B5C size:0xD0
void fn_2_80B5C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index, 0);

        n += isAnimDone(task, index + 2, 0);
        n += isAnimDone(task, index + 0x89, 10);
        if (n == 3) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0008082C size:0xAC
void fn_2_8082C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index + 0x89, 5);

        n += isAnimDone(task, index + 0x8B, 10);
        if (n == 2) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x000802EC size:0x214
void fn_2_802EC(UnkTask0C50* task) {
    if (lbl_803C66B0._0D[1] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + 0x81]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x81]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x81]._00->_68 = 1;
        lbl_80371C30[task->_14 + 0x84]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x84]._00->_68 = 0;
        lbl_80371C30[task->_14 + 0x7D]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x7D]._00->_68 = 1;
        lbl_80371C30[task->_14 + 0x98]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x86]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x86]._00->_68 = 1;
        lbl_80371C30[task->_14 + 0x8A]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x8A]._00->_68 = 1;
        fn_2_7630C(task, 1);
        fn_2_74F40(task, 1);
        fn_800626EC(1);
        lbl_803C66B0._0D[1] = 1;
    }
    if (lbl_803C66B0._0D[1] == 1) {
        s32 n = isAnimDone(task, 0x81, 20);

        n += isAnimDone(task, 0x7D, 20);
        n += isAnimDone(task, 0x86, 10);
        n += isAnimDone(task, 0x8A, 5);
        if (n == 4) {
            fn_80062674(1);
            lbl_803C66B0._0D[1] = 2;
        }
    }
}

// .text:0x000805DC size:0x250
void fn_2_805DC(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        u8 off;

        lbl_80371C30[task->_14 + 0x81]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x84]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x84]._00->_68 = 1;
        lbl_80371C30[task->_14 + 0x98]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x86]._00->_5C = 0xA0000;
        lbl_80371C30[task->_14 + 0x86]._00->_68 = 4;
        lbl_80371C30[task->_14 + 0x8A]._00->_5C = 0x50000;
        lbl_80371C30[task->_14 + 0x8A]._00->_68 = 4;
        lbl_80371C30[task->_14 + 0x79]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + 0x79]._00->_68 = 4;
        lbl_80371C30[task->_14 + 0x7D]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + 0x7D]._00->_68 = 4;
        off = lbl_8034E9A0._46F8 == 0;
        lbl_80371C30[task->_14 + 0x7B]._00->_5C = off << 16;
        lbl_80371C30[task->_14 + 0x19]._00->_5C = (off + 4) << 16;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n = isAnimDone(task, 0x86, 0);

        n += isAnimDone(task, 0x8A, 0);
        if (n == 2) {
            if (g_d_GameSettings._10 == 1 && lbl_2_bss_100B8._10 == 0) {
                fn_2_16A74(1, 0);
            }
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
            g_d_GameSettings._10 = 0;
        }
    }
}

// .text:0x000808D8 size:0x284
void fn_2_808D8(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (g_d_GameSettings.GameModeSelected != 5) {
            fn_2_7630C(task, index);
        } else {
            fn_2_760CC(task);
        }
        fn_2_74F40(task, index);
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00080500 size:0xDC
void fn_2_80500(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        u8 off = lbl_8034E9A0._46F8 == 0;

        lbl_80371C30[task->_14 + 0x7B]._00->_5C = off << 16;
        lbl_80371C30[task->_14 + 0x19]._00->_5C = (off + 4) << 16;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        fn_80062674(index);
        lbl_803C66B0._0D[index] = 2;
        g_d_GameSettings._10 = 0;
    }
}

// .text:0x000800B0 size:0x23C
void fn_2_800B0(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + index]._00->_68 = 1;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x80 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x80 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x78 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x78 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x7C + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x7C + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x97 + task->_14 + index]._00->_64 = 0x77;
        lbl_80371C30[0x97 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x97 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xB0 + task->_14 + index]._00->_54 &= ~2;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n = isAnimDone(task, index, 30);

        n += isAnimDone(task, index + 2, 30);
        if (n == 2) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007F8BC size:0x240
void fn_2_7F8BC(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s8 sel = lbl_2_bss_F468._00[index];
        s8 found;
        s32 value;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                found = i;
                break;
            }
        }
        value = lbl_803C6724._02[index][found];
        lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_54 |= 2;
        lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_5C = 0;
        lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_68 = 1;
        lbl_80371C30[0x58 + task->_14 + sel + index * 9]._00->_5C = value << 16;
        fn_2_75BE4(task, index);
        fn_2_74F40(task, index);
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007F714 size:0x1A8
void fn_2_7F714(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1) {
        s8 sel = lbl_2_bss_F468._00[index];
        BOOL done;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                break;
            }
        }
        done = isAnimDone(task, 0x34 + sel + index * 9, 10);
        if (fn_2_75B58(task, index) && done == TRUE) {
            fn_80062674(index);
            fn_2_CCE0(index);
        }
    }
}

// .text:0x0007EF68 size:0xC8
void fn_2_7EF68(UnkTask0C50* task, s32 index) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (i == lbl_2_bss_F468._00[index]) {
            lbl_80371C30[0x22 + task->_14 + i + index * 9]._00->_54 |= 2;
        }
    }
}

// .text:0x0007F030 size:0x28C
void fn_2_7F030(UnkTask0C50* task, s32 index) {
    s32 n;
    s32 expected;
    s32 i;
    s32 sel;
    s32 prev;
    s32 foundPrev;
    s32 foundSel;

    sel = lbl_2_bss_F468._00[index];
    prev = lbl_2_bss_F468._00[index + 2];
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        n = 0;
        expected = 0;
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                foundSel = i;
            }
            if (lbl_803C6724._14[index][i] == prev) {
                foundPrev = i;
            }
        }
        if (sel == prev) {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 0);
        } else if (lbl_803C6724._02[index][foundSel] != -1 && lbl_803C6724._02[index][foundSel] != 0x36) {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 10);
        }
        if (lbl_8034E9A0._46E0[index] == lbl_803C6724._02[index][foundPrev]) {
            expected++;
            n += isAnimDone(task, 0x34 + prev + index * 9, 20);
        }
        if (fn_2_75B58(task, index) && n == expected) {
            if (sel == prev) {
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_54 &= ~2;
            }
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007EE7C size:0xEC
void fn_2_7EE7C(UnkTask0C50* task, s32 index) {
    s32 sel = lbl_2_bss_F468._00[index];

    if (lbl_2_bss_F468._41[index]) {
        lbl_80371C30[0x22 + task->_14 + sel + index * 9]._00->_54 &= ~2;
    } else {
        lbl_80371C30[0x22 + task->_14 + sel + index * 9]._00->_54 |= 2;
    }
    fn_2_74F40(task, index);
    lbl_803C66B0._5D[index] = 0;
    if (lbl_2_bss_F468._59[index]) {
        fn_800625A4(index, 0x1A);
    }
}

// .text:0x0007D85C size:0x25C
void fn_2_7D85C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n;
        s32 expected;
        s32 i;
        s32 foundSel;
        s32 prev;
        s32 sel;
        s32 foundPrev;

        n = 0;
        expected = 0;
        sel = lbl_2_bss_F468._00[index];
        prev = lbl_2_bss_F468._00[index + 2];

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                foundSel = i;
            }
            if (lbl_803C6724._14[index][i] == prev) {
                foundPrev = i;
            }
        }
        if (prev != 9 && prev != 10 && prev < 9 && lbl_803C6724._02[index][foundPrev] != -1 &&
            lbl_803C6724._02[index][foundPrev] != 0x36 && prev != lbl_2_bss_F468._61[index] && prev != sel)
        {
            expected++;
            n += isAnimDone(task, 0x34 + prev + index * 9, 20);
        }
        if (sel != 9 && sel != 10 && sel < 9 && lbl_803C6724._02[index][foundSel] != -1 &&
            lbl_803C6724._02[index][foundSel] != 0x36 && sel != lbl_2_bss_F468._61[index])
        {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 10);
        }
        if (n == expected) {
            lbl_2_bss_F468._00[index + 2] = lbl_2_bss_F468._00[index];
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
            if (lbl_2_bss_F468._63[index]) {
                lbl_2_bss_F468._63[index] = 0;
                fn_800625A4(index, 0x1A);
            }
        }
    }
}

// .text:0x0007E380 size:0x4E0
void fn_2_7E380(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[0xC + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0x12 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xC + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xE + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x12 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x12 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xB6 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x8F + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xAC + task->_14 + index]._00->_68 = 1;
        if (g_d_GameSettings._10 == 0 && index == 0) {
            s8 id;
            s32 i;

            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._02[1][i] == lbl_8034E9A0._46E0[1]) {
                    id = lbl_803C6724._14[1][i];
                }
            }
            for (i = 0; i < 9; i++) {
                if (index == 0) {
                    if (i != id) {
                        lbl_80371C30[0x4F + task->_14 + i]._00->_54 &= ~2;
                    } else {
                        lbl_80371C30[0x3D + task->_14 + id]._00->_68 = 1;
                        lbl_80371C30[0x4F + task->_14 + id]._00->_68 = 4;
                        lbl_80371C30[0x4F + task->_14 + id]._00->_54 |= 2;
                    }
                }
                lbl_80371C30[0x22 + task->_14 + i + 9]._00->_54 &= ~2;
            }
            lbl_80371C30[task->_14 + 0x94]._00->_68 = 4;
            lbl_80371C30[task->_14 + 0x96]._00->_68 = 4;
            lbl_80371C30[task->_14 + 0x90]._00->_68 = 4;
            lbl_80371C30[task->_14 + 0x92]._00->_68 = 4;
            lbl_80371C30[task->_14 + 0x98]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0xAD]._00->_54 &= ~2;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007E194 size:0x1EC
void fn_2_7E194(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n;
        s32 expected = 2;
        s8 id;
        s32 i;

        n = isAnimDone(task, index + 0x1C, 10);
        n += isAnimDone(task, index + 0x6A, 10);
        expected++;
        n += isAnimDone(task, index + 0x89, 5);
        if (g_d_GameSettings._10 == 0 && index == 0) {
            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._02[1][i] == lbl_8034E9A0._46E0[1]) {
                    id = lbl_803C6724._14[1][i];
                }
            }
            expected++;
            n += isAnimDone(task, id + 0x3D, 20);
        }
        if (n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007E974 size:0x508
void fn_2_7E974(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s8 off;
        s32 i;

        lbl_80371C30[0xC + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0x12 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xC + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xC + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xE + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xE + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x10 + task->_14 + index]._00->_5C = lbl_8034E9A0._470D[index] << 16;
        lbl_80371C30[0x12 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x12 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x14 + task->_14 + index]._00->_5C = lbl_8034E9A0._470D[index] << 16;
        lbl_80371C30[0xB6 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x8F + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0x50000;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xAC + task->_14 + index]._00->_68 = 4;
        if (g_d_GameSettings._10 == 0) {
            off = lbl_8034E9A0._46F8 == 0;
            if (lbl_2_bss_F468._37[1]) {
                lbl_80371C30[task->_14 + 0x98]._00->_68 = 4;
            }
        }
        if (g_d_GameSettings._10 == 0 && lbl_2_bss_F468._37[0] && index == 0) {
            for (i = 0; i < 9; i++) {
                lbl_80371C30[0x4F + task->_14 + i]._00->_54 |= 2;
                lbl_80371C30[0x4F + task->_14 + i]._00->_64 = off + 0x11;
                lbl_80371C30[0x4F + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[0x4F + task->_14 + i]._00->_68 = 0;
            }
            lbl_80371C30[0x8F + task->_14 + off]._00->_68 = 1;
            lbl_80371C30[0x91 + task->_14 + off]._00->_5C = 0;
            lbl_80371C30[0x91 + task->_14 + off]._00->_68 = 1;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007E860 size:0x114
void fn_2_7E860(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index + 0xC, 10);

        n += isAnimDone(task, index + 0xE, 14);
        n += isAnimDone(task, index + 0x12, 10);
        n += isAnimDone(task, index + 0x1C, 20);
        n += isAnimDone(task, index + 0x6A, 30);
        if (n == 5) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007AC64 size:0x1D8
void fn_2_7AC64(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n;
        s32 expected = 2;

        n = isAnimDone(task, index, 20);
        n += isAnimDone(task, index + 2, 20);
        n += isAnimDone(task, index + 0x1C, 10);
        expected += 2;
        n += isAnimDone(task, index + 0x6A, 10);
        if (g_d_GameSettings.GameModeSelected == 5) {
            n += isAnimDone(task, index + 0x89, 5);
            expected += 2;
            n += isAnimDone(task, index + 0x85, 10);
        }
        if (fn_2_75B58(task, index) && n == expected) {
            fn_80062674(index);
            if (lbl_803CBBCC->_6 == 11 && index == 0 && g_d_GameSettings._10 == 0) {
                fn_800625A4(0, 0x11);
            } else {
                lbl_803C66B0._0D[index] = 2;
            }
        }
    }
}

// .text:0x0007A9D8 size:0x28C
void fn_2_7A9D8(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + index]._00->_68 = 4;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[4 + task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[4 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x85 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x85 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0x50000;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x34 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xB2 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xAE + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0x97 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xAC + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xC + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0x12 + task->_14 + index]._00->_54 &= ~2;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007A748 size:0x290
void fn_2_7A748(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index, 0);

        n += isAnimDone(task, index + 2, 0);
        n += isAnimDone(task, index + 0x85, 0);
        n += isAnimDone(task, index + 0x6A, 0);
        if (n == 4) {
            lbl_80371C30[task->_14 + index]._00->_64 = 0x47;
            lbl_80371C30[2 + task->_14 + index]._00->_64 = 0x47;
            lbl_80371C30[0x97 + task->_14 + index]._00->_64 = 0x78;
            lbl_80371C30[0x99 + task->_14 + index]._00->_64 = 0x79;
            lbl_80371C30[task->_14 + 0x1C]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x1D]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x1E]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x1F]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x78]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x79]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x7C]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x7D]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x80]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x81]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0xF]._00->_68 = 0;
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007A5B8 size:0x190
void fn_2_7A5B8(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + index]._00->_68 = 1;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x85 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x85 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
        if (g_d_GameSettings.GameModeSelected != 5 || index == 0) {
            lbl_80371C30[0x93 + task->_14 + index]._00->_54 &= ~2;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007A460 size:0x158
void fn_2_7A460(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index, 40);

        n += isAnimDone(task, index + 2, 40);
        n += isAnimDone(task, index + 0x85, 30);
        n += isAnimDone(task, index + 0x1C, 30);
        n += isAnimDone(task, index + 0x6A, 50);
        if (n == 5) {
            lbl_80371C30[0xC + task->_14 + index]._00->_54 &= ~2;
            lbl_80371C30[0x12 + task->_14 + index]._00->_54 &= ~2;
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007A194 size:0x2CC
void fn_2_7A194(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s32 prev = lbl_2_bss_F468._00[index + 2];
        s8 found;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == prev) {
                found = i;
                break;
            }
        }
        lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
        if (prev == 10) {
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
        } else if (prev != 9) {
            lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_5C = 0xF0000;
            lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 4;
            if (lbl_803C6724._02[index][found] != -1 && lbl_803C6724._02[index][found] != 0x36) {
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_5C = 0xA0000;
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 1;
            }
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00079FAC size:0x1E8
void fn_2_79FAC(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = 0;
        s32 expected = 0;
        s32 sel = lbl_2_bss_F468._00[index + 2];
        s8 found;
        s32 i;
        s8 id;

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                found = i;
                break;
            }
        }
        id = lbl_803C6724._02[index][found];
        if (id != -1 && id != 0x36 && sel < 9) {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 20);
        }
        if (n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00079CF8 size:0x2B4
void fn_2_79CF8(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s8 sel = lbl_2_bss_F468._00[index];
        s8 prev = lbl_2_bss_F468._00[index + 2];
        s8 found;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (sel == lbl_803C6724._14[index][i]) {
                found = i;
                break;
            }
        }
        if (prev == 9) {
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 4;
        } else if (prev == 10) {
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
        }
        lbl_80371C30[0x46 + task->_14 + sel + index * 9]._00->_5C = 0;
        lbl_80371C30[0x46 + task->_14 + sel + index * 9]._00->_68 = 1;
        if (lbl_803C6724._02[index][found] != -1) {
            lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_5C = 0x140000;
            lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_68 = 4;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00079B24 size:0x1D4
void fn_2_79B24(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = 0;
        s32 expected = 0;
        s8 sel = lbl_2_bss_F468._00[index];
        s32 found;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (sel == lbl_803C6724._14[index][i]) {
                found = i;
                break;
            }
        }
        if (lbl_803C6724._02[index][found] != -1) {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 10);
        }
        if (n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00079930 size:0x1F4
void fn_2_79930(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s32 i;

        for (i = 0; i < 9; i++) {
            s32 slot = lbl_803C6724._14[index][i];
            s32 value = lbl_803C6724._02[index][i];

            lbl_80371C30[0x34 + task->_14 + slot + index * 9]._00->_54 |= 2;
            lbl_80371C30[0x34 + task->_14 + slot + index * 9]._00->_5C = 0;
            lbl_80371C30[0x34 + task->_14 + slot + index * 9]._00->_68 = 1;
            lbl_80371C30[0x58 + task->_14 + slot + index * 9]._00->_5C = value << 16;
        }
        fn_2_75BE4(task, index);
        if (lbl_2_bss_F468._00[index] == 9) {
            lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00079764 size:0x1CC
void fn_2_79764(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = 0;
        s32 total = 0;
        s32 i;

        for (i = 0; i < 9; i++) {
            total++;
            n += isAnimDone(task, 0x34 + i + index * 9, 20);
        }
        if (fn_2_75B58(task, index) && n == total) {
            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._4A[index][i] == 0) {
                    lbl_803C6724._4A[index][i] = 1;
                }
            }
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00079688 size:0xDC
void fn_2_79688(UnkTask0C50* task, s32 index) {
    s32 i;

    if (lbl_803C66B0._0D[index] == 0) {
        for (i = 0; i < 9; i++) {
            lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_68 = 4;
        }
        lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
    }
}

// .text:0x00079634 size:0x54
void fn_2_79634(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        fn_80062674(index);
        lbl_803C66B0._0D[index] = 2;
    }
}

// .text:0x00079394 size:0x2A0
void fn_2_79394(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (lbl_2_bss_F468._00[index] == 9) {
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
        } else if (lbl_2_bss_F468._00[index] == 10) {
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 4;
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 1;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n = 0;
        s32 expected = 0;

        if (lbl_2_bss_F468._00[index] == 9) {
            expected = 2;
            n = (lbl_80371C30[0x95 + task->_14 + index]._00->_5C >> 16 >= 10) +
                (lbl_80371C30[0x91 + task->_14 + index]._00->_5C >> 16 == 0);
        } else if (lbl_2_bss_F468._00[index] == 10) {
            expected = 2;
            n = (lbl_80371C30[0x95 + task->_14 + index]._00->_5C >> 16 == 0) +
                (lbl_80371C30[0x91 + task->_14 + index]._00->_5C >> 16 >= 10);
        }
        if (n == expected) {
            lbl_2_bss_F468._00[index + 2] = lbl_2_bss_F468._00[index];
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007912C size:0x268
void fn_2_7912C(UnkTask0C50* task, s32 index) {
    s32 i;

    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (lbl_803C66B0._00[0] == 2) {
            for (i = 1; i < 9; i++) {
                s8 slot = lbl_803C6724._14[index][i];
                s8 value = lbl_803C6724._02[index][slot];

                if (value != -1 && value != 0x36) {
                    lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_68 = 4;
                }
            }
            fn_2_75BE4(task, index);
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n = 0;
        s32 expected = 0;

        for (i = 1; i < 9; i++) {
            s8 slot = lbl_803C6724._14[index][i];
            s8 value = lbl_803C6724._02[index][slot];

            if (value != -1 && value != 0x36) {
                expected++;
                n += isAnimDone(task, 0x34 + i + index * 9, 0);
            }
        }
        if ((lbl_803C66B0._00[0] != 2 || fn_2_75B58(task, index)) && n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
            if (lbl_2_bss_F468._43[index]) {
                fn_2_102C8(index);
                lbl_2_bss_F468._43[index] = 0;
            }
        }
    }
}

// .text:0x00078F78 size:0x1B4
void fn_2_78F78(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[0xA + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xA + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x1E + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x8D + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x8D + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 4;
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_80371C30[0x8F + task->_14 + index]._00->_64 = 8;
            lbl_80371C30[0x8F + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 1;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        fn_80062674(index);
        lbl_803C66B0._0D[index] = 2;
    }
}

// .text:0x00078AC0 size:0x4B8
void fn_2_78AC0(UnkTask0C50* task, s32 index) {
    s8 prev;
    s8 found;
    s8 sel;
    s32 i;

    sel = lbl_2_bss_F468._00[index];
    prev = lbl_2_bss_F468._61[index];
    if (prev != -1) {
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == prev) {
                found = i;
            }
        }
    }
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[0xA + task->_14 + index]._00->_5C = 0xF0000;
        lbl_80371C30[0xA + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x1E + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x93 + task->_14 + index]._00->_64 = 9;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x8D + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x8D + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_80371C30[0x8F + task->_14 + index]._00->_64 = 7;
        }
        if (prev != -1 && prev != sel) {
            lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 4;
            if (lbl_803C6724._02[index][found] != -1 && lbl_803C6724._02[index][found] != 0x36) {
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_5C = 0xA0000;
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 1;
            }
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n;
        s32 expected = 1;

        n = isAnimDone(task, index + 0x89, 5);
        expected++;
        n += isAnimDone(task, index + 0x6A, 10);
        if (prev != -1 && lbl_2_bss_F468._56 == 0 && prev != sel && lbl_803C6724._02[index][found] != -1 &&
            lbl_803C6724._02[index][found] != 0x36)
        {
            expected++;
            n += isAnimDone(task, 0x34 + prev + index * 9, 20);
        }
        if (n == expected) {
            lbl_2_bss_F468._61[index] = -1;
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
            if (lbl_2_bss_F468._65[index]) {
                if (g_d_GameSettings.GameModeSelected == 5) {
                    fn_800625A4(0, 0x13);
                    fn_800625A4(1, 0x13);
                } else if (g_d_GameSettings._10 == 0) {
                    fn_800625A4(index, 0x11);
                } else {
                    fn_800625A4(index, 0x11);
                }
                lbl_2_bss_F468._65[index] = 0;
            } else if (lbl_2_bss_F468._56) {
                fn_800625A4(index, 0xB);
            }
        }
    }
}

// .text:0x0007805C size:0x310
void fn_2_7805C(UnkTask0C50* task, s32 index) {
    s32 n;
    s8 prev;
    s32 expected;
    s8 found;
    s32 i;

    prev = lbl_2_bss_F468._61[index];
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._14[index][i] == prev) {
            found = i;
        }
    }
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (prev != lbl_2_bss_F468._00[index]) {
            lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 4;
            if (lbl_803C6724._02[index][found] != -1 && lbl_803C6724._02[index][found] != 0x36) {
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 1;
            }
        }
        if (lbl_2_bss_F468._37[index]) {
            lbl_80371C30[0x93 + task->_14 + index]._00->_64 = 9;
            lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 0;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        n = 0;
        expected = 0;
        if (lbl_2_bss_F468._61[index] != lbl_2_bss_F468._00[index] && lbl_803C6724._02[index][found] != -1 &&
            lbl_803C6724._02[index][found] != 0x36)
        {
            expected++;
            n += isAnimDone(task, 0x34 + prev + index * 9, 20);
        }
        if (n == expected) {
            lbl_2_bss_F468._5F[index] = 0;
            lbl_2_bss_F468._61[index] = -1;
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00078034 size:0x28
void fn_2_78034(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007664C size:0x4
void fn_2_7664C(void) {
}

// .text:0x00076650 size:0x224
void fn_2_76650(UnkTask0C50* task, u8 index, u32 mask) {
    s32 values[2];
    s32 n;
    s32 i;

    memset(values, -1, 2);
    for (i = 0, n = 0; i < 14; i++) {
        if (mask & (1 << i)) {
            switch (i) {
            case 0:
                i++;
                break;
            case 1:
                values[n++] = 1;
                break;
            case 2:
                values[n++] = 2;
                break;
            case 3:
                values[n++] = 3;
                break;
            case 4:
                values[n++] = 4;
                break;
            case 5:
                values[n++] = 5;
                break;
            case 6:
                values[n++] = 6;
                break;
            case 7:
                values[n++] = 7;
                break;
            case 8:
                values[n++] = 8;
                break;
            case 9:
                values[n++] = 9;
                break;
            case 10:
                values[n++] = 10;
                break;
            case 11:
                values[n++] = 11;
                break;
            case 12:
                values[n++] = 12;
                break;
            default:
                values[n++] = 13;
                break;
            }
        }
    }
    for (i = 0; i < 2; i++) {
        values[i]--;
    }
    for (i = 0; i < 2; i++) {
        if (values[i] < 0) {
            values[i] = 12;
        }
    }
    lbl_80371C30[0xCE + task->_14 + index]._00->_5C = values[0] << 16;
    lbl_80371C30[0xD0 + task->_14 + index]._00->_5C = values[1] << 16;
}

// .text:0x000760CC size:0x240
void fn_2_760CC(UnkTask0C50* task) {
    s32 a = lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[0]];
    s32 b = lbl_800FE930[lbl_80361B20._F4][lbl_803C6724._00[0]];
    u8 c = lbl_8034E9A0._0034[a / 9][a % 9]._00;
    u8 d = lbl_8034E9A0._0034[b / 9][b % 9]._00;

    lbl_80371C30[task->_14 + 0x82]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    fn_800363D8(task, 0x89, 1, 3, lbl_2_data_2B3A4[c]);
    fn_800363D8(task, 0x8B, 1, 3, lbl_2_data_2B3A4[d]);
    lbl_80371C30[task->_14 + 0x7E]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    lbl_80371C30[task->_14 + 0x80]._00->_5C = 0;
    lbl_80371C30[task->_14 + 0x89]._00->_5C = 0;
    lbl_80371C30[task->_14 + 0x8B]._00->_5C = 0xA0000;
    lbl_80371C30[task->_14 + 0x78]._00->_5C = 0;
    lbl_80371C30[task->_14 + 0x7C]._00->_5C = 0;
    lbl_80371C30[task->_14 + 0x80]._00->_68 = 1;
    lbl_80371C30[task->_14 + 0x89]._00->_68 = 1;
    lbl_80371C30[task->_14 + 0x8B]._00->_68 = 4;
    lbl_80371C30[task->_14 + 0x78]._00->_68 = 1;
    lbl_80371C30[task->_14 + 0x7C]._00->_68 = 1;
}

// .text:0x0007630C size:0x340
void fn_2_7630C(UnkTask0C50* task, u8 index) {
    u8 slot;
    s32 a;
    s32 b;
    u8 c;
    u8 d;

    if (g_d_GameSettings._10 == 0) {
        slot = lbl_803C66B0._59[0];
    } else {
        slot = lbl_803C66B0._59[index];
    }
    a = lbl_800FE5D4[lbl_2_bss_F410._10[slot]];
    b = lbl_800FE5D4[lbl_803C6724._00[slot]];
    c = lbl_8034E9A0._0034[a / 9][a % 9]._00;
    d = lbl_8034E9A0._0034[b / 9][b % 9]._00;
    lbl_80371C30[0x82 + task->_14 + slot]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    lbl_80371C30[0x85 + task->_14 + slot]._00->_5C = 0xA0000;
    lbl_80371C30[0x87 + task->_14 + slot]._00->_5C = 0xA0000;
    lbl_80371C30[0x85 + task->_14 + slot]._00->_68 = 0;
    lbl_80371C30[0x87 + task->_14 + slot]._00->_68 = 0;
    fn_800363D8(task, slot + 0x89, 1, 3, lbl_2_data_2B3A4[c]);
    fn_800363D8(task, slot + 0x8B, 1, 3, lbl_2_data_2B3A4[d]);
    lbl_80371C30[0x7E + task->_14 + slot]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    lbl_80371C30[0x1A + task->_14 + slot]._00->_54 |= 2;
    lbl_80371C30[0x1A + task->_14 + slot]._00->_68 = 1;
    lbl_80371C30[0x80 + task->_14 + slot]._00->_5C = 0;
    lbl_80371C30[0x89 + task->_14 + slot]._00->_5C = 0;
    lbl_80371C30[0x8B + task->_14 + slot]._00->_5C = 0xA0000;
    lbl_80371C30[0x78 + task->_14 + slot]._00->_5C = 0;
    lbl_80371C30[0x7C + task->_14 + slot]._00->_5C = 0;
    lbl_80371C30[0x80 + task->_14 + slot]._00->_68 = 1;
    lbl_80371C30[0x89 + task->_14 + slot]._00->_68 = 1;
    lbl_80371C30[0x8B + task->_14 + slot]._00->_68 = 4;
    lbl_80371C30[0x78 + task->_14 + slot]._00->_68 = 1;
    lbl_80371C30[0x7C + task->_14 + slot]._00->_68 = 1;
}

// .text:0x0007609C size:0x30
void fn_2_7609C(UnkTask0C50* task, u8 flag, u8 skip) {
    if (!skip) {
        fn_2_8794(flag, 0);
    }
}

// .text:0x00076098 size:0x4
void fn_2_76098(void) {
}

// .text:0x00075BE4 size:0x4B4
void fn_2_75BE4(UnkTask0C50* task, s32 index) {
    s32 level;
    s32 i;
    s32 sum = 0;
    s32 avg = 0;
    s32 count = 0;

    level = 0;
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._26[index][i] != 0 && lbl_803C6724._02[index][i] != lbl_8034E9A0._46E0[index]) {
            sum += lbl_803C6724._26[index][i];
            count++;
        }
    }
    if (count != 0) {
        avg = sum / count;
    }
    if (avg >= 70) {
        level = 5;
    } else if (avg <= 69 && avg >= 55) {
        level = 4;
    } else if (avg <= 54 && avg >= 35) {
        level = 3;
    } else if (avg <= 34 && avg >= 15) {
        level = 2;
    } else if (avg <= 14 && avg > 0) {
        level = 1;
    }
    lbl_8034E9A0._470F[index] = level;
    for (i = 0; i < 5; i++) {
        if (lbl_80371C30[0x6E + task->_14 + i + index * 5]._00->_5C >> 16 == 30) {
            lbl_80371C30[0x6E + task->_14 + i + index * 5]._00->_68 = 1;
        }
    }
    for (i = 0; i < level; i++) {
        lbl_80371C30[0x6E + task->_14 + i + index * 5]._00->_5C = 0;
        lbl_80371C30[0x6E + task->_14 + i + index * 5]._00->_68 = 1;
    }
}

// .text:0x00075B58 size:0x8C
u8 fn_2_75B58(UnkTask0C50* task, s32 index) {
    s32 i;
    u8 count = lbl_8034E9A0._470F[index];
    s32 hits = 0;
    s32 total = 0;

    for (i = 0; i < count; i++) {
        total++;
        hits += fn_80042DA8(task, 0x6E + i + index * 5, 0x1E) != 0;
    }
    return hits == total;
}

// .text:0x00074E14 size:0x12C
void fn_2_74E14(UnkTask0C50* task, s32 index, s32 count, u8 sel) {
    s32 value;

    lbl_80371C30[0x97 + task->_14 + index]._00->_54 |= 2;
    lbl_80371C30[0x97 + task->_14 + index]._00->_5C = 0;
    lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 1;
    lbl_80371C30[0x9B + task->_14 + sel + index * 4]._00->_5C = (count - 1) << 16;
    value = fn_80036214(task, 0xAB, 0, (count + 1) / 2 - 1);
    lbl_80371C30[0xA3 + task->_14 + sel + index * 4]._00->_5C = (count - 1) << 16;
    lbl_80371C30[0xA3 + task->_14 + sel + index * 4]._00->_58 = value;
}

// .text:0x00074DB8 size:0x5C
s32 fn_2_74DB8(s32 arg0) {
    switch (arg0) {
    case 0xD:
    case 0x10:
    case 0x14:
    case 0x16:
    case 0x19:
    case 0x22:
    case 0x2A:
    case 0x32:
    case 0x34:
        return 1;
    case 0x15:
    case 0x18:
    case 0x1D:
    case 0x21:
    case 0x2C:
    case 0x33:
    case 0x35:
        return 2;
    case 0x17:
    case 0x1E:
    case 0x24:
    case 0x2D:
        return 3;
    case 0xC:
    case 0x1A:
    case 0x1B:
    case 0x1F:
    case 0x23:
    case 0x2B:
    case 0x2E:
    case 0x31:
        return 4;
    case 0x20:
        return 5;
    case 0x2F:
        return 6;
    default:
        return 0;
    }
}

// .text:0x00074D8C size:0x2C
void fn_2_74D8C(void) {
    fn_800B0A5C_insertQueue(fn_2_74CD8, 0x1000);
}

// .text:0x00074CD8 size:0xB4
void fn_2_74CD8(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2D33C);
    for (i = 0; i < 7; i++) {
        fn_800363D8(task, i + 0x18, 1, 0x36, i);
    }
    fn_800363D8(task, 0x20, 1, 0x32, 0);
    lbl_2_bss_A840 = lbl_2_bss_F410._00;
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_747FC;
}

// .text:0x000747FC size:0x4DC
void fn_2_747FC(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 sel = lbl_2_bss_F410._00;
    s32 id;

    if (lbl_8034E9A0._472A == 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        lbl_8034E9A0._472A = 0xFF;
        return;
    }
    switch (lbl_803C66B0._5D[0]) {
    case 0x54:
        fn_2_7463C(task);
        fn_2_74564(task);
        break;
    case 0x55:
        if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
            fn_800626EC(0);
            lbl_803C66B0._07 = 1;
        }
        if (lbl_803C66B0._07 == 1) {
            fn_80062674(0);
            lbl_803C66B0._07 = 2;
        }
        break;
    case 0x56:
        fn_2_73EFC(task);
        fn_2_73CBC(task);
        break;
    case 0x57:
        if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
            id = sel + 0x11;
            lbl_80371C30[task->_14 + id]._00->_5C = 0xE0000;
            lbl_80371C30[task->_14 + id]._00->_68 = 1;
            lbl_803C66B0._07 = 1;
        }
        if (lbl_803C66B0._07 == 1) {
            if (lbl_8034E9A0._472C == 0 && lbl_8034E9A0._4751 != 0) {
                lbl_8034E9A0._4752 = 1;
                if (lbl_2_bss_F410._00 != lbl_2_bss_F410._04) {
                    fn_800625A4(0, 0x56);
                }
                lbl_8034E9A0._4751 = 0;
                lbl_2_bss_A840 = lbl_2_bss_A844;
            } else {
                id = sel + 0x11;
                if (isAnimDone(task, id, 0x37) == TRUE) {
                    lbl_80371C30[task->_14 + id]._00->_5C = 0xE0000;
                    lbl_80371C30[task->_14 + id]._00->_68 = 1;
                }
            }
        }
        break;
    case 0x58:
        if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
            lbl_80371C30[0x11 + task->_14 + sel]._00->_5C = 0x370000;
            lbl_80371C30[0x11 + task->_14 + sel]._00->_68 = 1;
            fn_800626EC(0);
            lbl_803C66B0._07 = 1;
        }
        if (lbl_803C66B0._07 == 1) {
            if (isAnimDone(task, sel + 0x11, 0x41) == TRUE) {
                fn_80062674(0);
                lbl_803C66B0._07 = 2;
            }
        }
        break;
    }
}

// .text:0x0007463C size:0x1C0
void fn_2_7463C(UnkTask0C50* task) {
    s32 i;
    s32 sel;

    sel = lbl_2_bss_F410._00;
    if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
        for (i = 0; i < 7; i++) {
            if (sel == i) {
                lbl_80371C30[3 + task->_14 + i]._00->_54 |= 2;
                lbl_80371C30[3 + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[3 + task->_14 + i]._00->_68 = 1;
                lbl_80371C30[0x18 + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[0x18 + task->_14 + i]._00->_68 = 1;
            } else {
                lbl_80371C30[0x18 + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[0x18 + task->_14 + i]._00->_68 = 0;
                lbl_80371C30[3 + task->_14 + i]._00->_54 &= ~2;
            }
        }
        if (lbl_8037169C._10) {
            changeScene(1, 6);
        }
        lbl_80371C30[task->_14 + 0x20]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x20]._00->_68 = 1;
        fn_800626EC(0);
        lbl_803C66B0._07 = 1;
    }
}

// .text:0x00074564 size:0xD8
void fn_2_74564(UnkTask0C50* task) {
    s32 i;
    s32 n;
    s32 expected;
    s32 sel;

    sel = lbl_2_bss_F410._00;
    if (lbl_803C66B0._07 == 1 ? TRUE : FALSE) {
        n = 0;
        expected = 0;
        for (i = 0; i < 7; i++) {
            if (sel == i) {
                expected++;
                n += isAnimDone(task, i + 3, 14);
            }
        }
        n += isAnimDone(task, 0x20, 10);
        if (n == expected + 1) {
            fn_80062674(0);
            lbl_803C66B0._07 = 2;
            fn_800625A4(0, 0x57);
        }
    }
}

// .text:0x00074518 size:0x4C
void fn_2_74518(void) {
    if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
        fn_800626EC(0);
        lbl_803C66B0._07 = 1;
    }
}

// .text:0x000744C8 size:0x50
void fn_2_744C8(void) {
    if (lbl_803C66B0._07 == 1 ? TRUE : FALSE) {
        fn_80062674(0);
        lbl_803C66B0._07 = 2;
    }
}

// .text:0x00073CBC size:0x240
void fn_2_73CBC(UnkTask0C50* task) {
    s32 i;
    s32 n;
    s32 expected;
    s32 sel;

    sel = lbl_2_bss_F410._00;
    if (lbl_803C66B0._07 == 1 ? TRUE : FALSE) {
        n = 0;
        expected = 0;
        if (lbl_8034E9A0._4751 == 0) {
            for (i = 0; i < 7; i++) {
                s32 value = fn_2_73B94(sel);

                if (lbl_2_bss_F410._00 == i) {
                    expected++;
                    n += isAnimDone(task, i + 3, value);
                }
                if (lbl_2_bss_A840 == 0 && sel == 6 && i == lbl_2_bss_A840) {
                    expected++;
                    n += isAnimDone(task, i + 3, 0);
                } else if (lbl_2_bss_A840 == 6 && sel == 0 && i == lbl_2_bss_A840) {
                    expected++;
                    n += isAnimDone(task, i + 3, 0x36);
                }
            }
            n += isAnimDone(task, sel + 0x11, 14);
            expected += 2;
            n += isAnimDone(task, 0x20, 10);
        }
        if (n == expected) {
            if (lbl_8034E9A0._4751) {
                lbl_2_bss_A844 = lbl_2_bss_A840;
            }
            lbl_2_bss_A840 = sel;
            lbl_8034E9A0._4752 = 0;
            if (lbl_8034E9A0._4751 == 0) {
                fn_80062674(0);
            }
            lbl_803C66B0._07 = 2;
            fn_800625A4(0, 0x57);
        }
    }
}

// .text:0x00073BF0 size:0xCC
s32 fn_2_73BF0(s32 arg0) {
    if (lbl_2_bss_A840 == 0 && arg0 == 6) {
        switch (lbl_8034E9A0._4752) {
        case 0:
            return 54;
        default:
            return 54;
        }
    }
    if (lbl_2_bss_A840 == 6 && arg0 == 0) {
        switch (lbl_8034E9A0._4752) {
        case 0:
            return 0;
        default:
            return 8;
        }
    }
    if (lbl_2_bss_A840 <= arg0) {
        switch (lbl_8034E9A0._4752) {
        case 0:
            return 15;
        default:
            return 23;
        }
    }
    if (lbl_2_bss_A840 > arg0) {
        switch (lbl_8034E9A0._4752) {
        case 0:
            return 30;
        default:
            return 38;
        }
    }
}

// .text:0x00073B94 size:0x5C
s32 fn_2_73B94(s32 arg0) {
    if (lbl_2_bss_A840 == 0 && arg0 == 6) {
        return 45;
    }
    if (lbl_2_bss_A840 == 6 && arg0 == 0) {
        return 14;
    }
    if (lbl_2_bss_A840 <= arg0) {
        return 29;
    }
    if (lbl_2_bss_A840 > arg0) {
        return 44;
    }
}

// .text:0x00073B54 size:0x40
s32 fn_2_73B54(s32 arg0) {
    if (lbl_2_bss_A840 == 0 && arg0 == 6) {
        return 4;
    }
    if (lbl_2_bss_A840 == 6 && arg0 == 0) {
        return 1;
    }
    return 1;
}

// .text:0x00073994 size:0x1C0
void fn_2_73994(UnkTask0C50* task, s32 index) {
    s32 a;
    s32 b;
    u8 c;
    u8 d;

    if (g_d_GameSettings.GameModeSelected != 5) {
        a = lbl_800FE5D4[lbl_2_bss_F410._10[index]];
        b = lbl_800FE5D4[lbl_803C6724._00[index]];
    } else if (index != 0) {
        a = b = starMissionCompletionTracker._441F;
    } else {
        a = b = starMissionCompletionTracker._441D;
    }
    c = lbl_8034E9A0._0034[a / 9][a % 9]._00;
    d = lbl_8034E9A0._0034[b / 9][b % 9]._00;
    lbl_80371C30[0x82 + task->_14 + index]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    lbl_80371C30[0x7E + task->_14 + index]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    fn_800363D8(task, index + 0x89, 1, 3, lbl_2_data_2B3A4[c]);
    fn_800363D8(task, index + 0x8B, 1, 3, lbl_2_data_2B3A4[d]);
}

// .text:0x000738C8 size:0xCC
void fn_2_738C8(void) {
    if (lbl_803CBBCC->_6 == 5) {
        fn_800B0A5C_insertQueue(fn_80053FE8, 0);
    }
    if (g_d_GameSettings.GameModeSelected == 5) {
        lbl_8034E978._00 = 13;
        lbl_8034E978._09 = lbl_8034E978._08;
        lbl_8034E978._08 = lbl_800FEF70[13]._08;
        fn_800B0A5C_insertQueue(fn_8004E2EC, 0x3000);
    } else {
        lbl_8034E978._00 = 0;
        lbl_8034E978._09 = lbl_8034E978._08;
        lbl_8034E978._08 = lbl_800FEF70[0]._08;
        fn_800B0A5C_insertQueue(fn_8004F964, 0x3000);
    }
}

// .text:0x00073758 size:0x170
void fn_2_73758(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2AF4C);
    for (i = 0; i < 8; i++) {
        lbl_80371C30[task->_14 + 4 + i]._00->_5C = lbl_803C6724._02[0][1 + i] << 16;
    }
    lbl_803CBCD8._5 = 0;
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_7308C;
}

// .text:0x0007302C size:0x60
s32 fn_2_7302C(void) {
    s32 i;
    u8* p = lbl_800FE930[lbl_80361B20._F4];

    for (i = 0; i < (lbl_80361B20._F4 != 0) + 5; i++) {
        if (lbl_8034E9A0._46E0[0] == *p) {
            return i;
        }
        p++;
    }
    return i;
}

// .text:0x00073028 size:0x4
void fn_2_73028(void) {
}

// .text:0x00072DDC size:0x78
void fn_2_72DDC(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        if ((fn_80042DA8(task, 0, 25) ? TRUE : FALSE) == TRUE) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
        }
    }
}

// .text:0x00072D60 size:0x7C
void fn_2_72D60(UnkTask0C50* task) {
    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x190000;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072CB4 size:0xAC
void fn_2_72CB4(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, 0, 0);

        n += isAnimDone(task, 1, 0);
        if (n == 2) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
            lbl_803CBBC4._4 = 1;
        }
    }
}

// .text:0x00072A88 size:0x22C
void fn_2_72A88(UnkTask0C50* task) {
    s32 found = -1;
    s32 i;

    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        for (i = 0; i < 6; i++) {
            if (lbl_80108EC4[i] == lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[0]]) {
                found = i;
                break;
            }
        }
        lbl_80371C30[task->_14 + 2]._00->_5C = lbl_2_data_2AF08[found] << 18;
        lbl_80371C30[task->_14 + 3]._00->_5C = lbl_2_data_2AF08[found] << 18;
        for (i = 0; i < 8; i++) {
            lbl_80371C30[task->_14 + 4 + i]._00->_5C = lbl_803C6724._02[0][1 + i] << 16;
        }
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072A58 size:0x30
void fn_2_72A58(void) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        lbl_803CBBC4._3 = 0;
        lbl_803CBBC4._2 = 0;
        lbl_803CBBC4._0 = 0;
    }
}

// .text:0x000729E0 size:0x78
void fn_2_729E0(UnkTask0C50* task) {
    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 1;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x190000;
        lbl_80371C30[task->_14 + 1]._00->_68 = 1;
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x0007293C size:0xA4
void fn_2_7293C(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, 0, 25);

        n += isAnimDone(task, 1, 25);
        if (n == 2) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
        }
    }
}

// .text:0x000728C0 size:0x7C
void fn_2_728C0(UnkTask0C50* task) {
    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x190000;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072814 size:0xAC
void fn_2_72814(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, 0, 0);

        n += isAnimDone(task, 1, 0);
        if (n == 2) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
            lbl_803CBBC4._4 = 1;
        }
    }
}

// .text:0x0007265C size:0x1B8
void fn_2_7265C(void) {
    s32 found = FALSE;
    s32 mode;
    s32 i;

    if (g_d_GameSettings.GameModeSelected == 5 && lbl_803C5EA4._11 == 0) {
        lbl_803C5EA4._11 = 1;
        fn_800B0A5C_insertQueue(fn_80053FE8, 0x3000);
        fn_800B0A5C_insertQueue(fn_2_82DE8, 0x3000);
    }
    for (i = 0; i < 54; i++) {
        if (((u8*)lbl_80361B20._00)[i]) {
            found = TRUE;
            break;
        }
    }
    if (g_d_GameSettings.GameModeSelected != 5) {
        if (found) {
            mode = 2;
        } else {
            mode = 1;
        }
    } else {
        mode = 19;
    }
    lbl_8034E978._00 = mode;
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._08 = lbl_800FEF70[mode]._08;
    fn_800B0A5C_insertQueue(fn_80051D00, 0x3000);
}

// .text:0x00072630 size:0x2C
void fn_2_72630(void) {
    fn_800B0A5C_insertQueue(fn_2_72594, 0x3000);
}

// .text:0x00072594 size:0x9C
void fn_2_72594(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2AADC);
    for (i = 0; i < 4; i++) {
        fn_800363D8(task, i + 7, 1, 0x32, 3 - i);
    }
    fn_800363D8(task, 2, 1, 0x35, 0);
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_7207C;
}
