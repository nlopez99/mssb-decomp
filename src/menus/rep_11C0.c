#include "menus/rep_11C0.h"
#include "header_rep_data.h"

typedef struct MenuTask11C0 {
    /* 0x00 */ void (*fn)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
} MenuTask11C0;

typedef struct MenuSprite11C0 {
    /* 0x00 */ u8 _00[0x58];
    /* 0x58 */ u32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66[0x68 - 0x66];
    /* 0x68 */ u8 _68;
} MenuSprite11C0;

typedef struct MenuSpriteRef11C0 {
    /* 0x0 */ MenuSprite11C0* _00;
    /* 0x4 */ u8 _04[0x8 - 0x4];
} MenuSpriteRef11C0; // size: 0x8

extern void* lbl_803CC1B8;
extern MenuSpriteRef11C0 lbl_80371C30[];
extern struct {
    /* 0x00 */ u8 _00[0x4F];
    /* 0x4F */ u8 _4F;
    /* 0x50 */ u8 _50[0x5D - 0x50];
    /* 0x5D */ u8 _5D;
    /* 0x5E */ u8 _5E[0x64 - 0x5E];
} lbl_803C66B0;
extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x8 - 0x1];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A[0x28 - 0xA];
} lbl_8034E978;
extern struct {
    /* 0x000 */ u8 _000[0x5B8];
    /* 0x5B8 */ u16 _5B8;
} lbl_800FEF70;
extern struct {
    /* 0x0 */ u8 _0[0x2];
    /* 0x2 */ s16 _2;
    /* 0x4 */ s16 _4;
    /* 0x6 */ s8 _6;
    /* 0x7 */ s8 _7;
    /* 0x8 */ s8 _8;
    /* 0x9 */ u8 _9[0xB - 0x9];
    /* 0xB */ u8 _B;
    /* 0xC */ u8 _C[0xE - 0xC];
    /* 0xE */ u8 _E;
    /* 0xF */ u8 _F;
} lbl_2_bss_1033C;

// Outside this unit's ranges: lbl_2_data_30900 to 0x312A4 has no unit yet.
extern u8 lbl_2_data_30D04[];
extern u8 lbl_2_data_311E4[];

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80053FE8(void);
extern void fn_80034CEC(MenuTask11C0* task);
extern void fn_80034E20(MenuTask11C0* task, void* desc);
extern void fn_800363D8(MenuTask11C0* task, s32, s32, s32, s32);
extern s32 fn_80042DA8(MenuTask11C0* task, s32, s32);
extern void fn_80062674(s32);
extern void fn_800626EC(s32);
extern void changeScene(u8, s16);

static inline BOOL fn_2_isState(u8 state) {
    return lbl_803C66B0._4F == state ? TRUE : FALSE;
}

// .text:0x00096D20 size:0x74
void fn_2_96D20(void) {
    fn_800B0A5C_insertQueue(fn_80053FE8, 0x3000);
    lbl_8034E978._00 = 0x5B;
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._08 = lbl_800FEF70._5B8;
    fn_800B0A5C_insertQueue(fn_2_948B8, 0x3000);
    fn_800B0A5C_insertQueue(fn_2_96AD4, 0x3000);
}

// .text:0x00096AD4 size:0x24C
void fn_2_96AD4(void) {
    MenuTask11C0* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_30D04);
    for (i = 0; i < 3; i++) {
        fn_800363D8(task, i + 15, 1, 0, i);
        fn_800363D8(task, i + 15, 2, 0, i);
        fn_800363D8(task, i + 21, 1, 1, i);
        fn_800363D8(task, i + 21, 2, 1, i);
        switch (i) {
        case 0:
            fn_800363D8(task, 0x18, 1, 2, 0);
            fn_800363D8(task, 0x19, 1, 2, 1);
            break;
        case 1:
            fn_800363D8(task, 0x1A, 1, 2, 3);
            fn_800363D8(task, 0x1B, 1, 2, 2);
            fn_800363D8(task, 0x1C, 1, 2, 4);
            break;
        case 2:
            fn_800363D8(task, 0x1D, 1, 2, 0);
            fn_800363D8(task, 0x1E, 1, 2, 1);
            break;
        }
    }
    fn_800363D8(task, 4, 1, 3, 0);
    fn_800363D8(task, 3, 1, 4, 0);
    if (lbl_2_bss_1033C._6 == 0) {
        lbl_80371C30[task->_14 + 16 + i]._00->_5C = 0;
        lbl_80371C30[task->_14 + 16]._00->_68 = 0;
        lbl_80371C30[task->_14 + 19]._00->_64 = 0x1B;
        lbl_80371C30[task->_14 + 22]._00->_64 = 0x11;
    }
    ((MenuTask11C0*)lbl_803CC1B8)->fn = fn_2_96698;
}

// .text:0x00096698 size:0x43C
void fn_2_96698(void) {
    MenuTask11C0* task = lbl_803CC1B8;

    switch (lbl_803C66B0._5D) {
    case 0x59:
        fn_2_96118(task);
        fn_2_95FE0(task);
        break;
    case 0x5A:
        fn_2_95F3C(task);
        fn_2_95E80(task);
        break;
    case 0x5B:
        if (lbl_2_bss_1033C._B != 0) {
            fn_2_95654(task);
            fn_2_95604();
        } else {
            fn_2_95B78(task);
            fn_2_95B28();
        }
        break;
    case 0x5C:
        fn_2_94A8C(task);
        fn_2_9493C(task);
        break;
    }
    if (lbl_2_bss_1033C._E != 0) {
        lbl_2_bss_1033C._E = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00096118 size:0x580
void fn_2_96118(MenuTask11C0* task) {
    s32 i;
    s32 j;

    if (fn_2_isState(0)) {
        lbl_80371C30[task->_14]._00->_68 = 1;
        for (i = 0; i < 3; i++) {
            if (i == lbl_2_bss_1033C._2) {
                lbl_80371C30[task->_14 + 15 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 15 + i]._00->_68 = 1;
                lbl_80371C30[task->_14 + 18 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 18 + i]._00->_68 = 1;
            } else if (lbl_2_bss_1033C._6 != 0 || i != 1) {
                lbl_80371C30[task->_14 + 15 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 15 + i]._00->_68 = 0;
                lbl_80371C30[task->_14 + 18 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 18 + i]._00->_68 = 0;
                lbl_80371C30[task->_14 + 6 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 6 + i]._00->_68 = 1;
            }
            switch (i) {
            case 0:
                lbl_80371C30[task->_14 + 24]._00->_5C = 0;
                lbl_80371C30[task->_14 + 25]._00->_5C = 0;
                if (lbl_2_bss_1033C._6 != 0) {
                    lbl_80371C30[task->_14 + 24]._00->_64 = 0x18;
                    lbl_80371C30[task->_14 + 25]._00->_64 = 0x15;
                    lbl_80371C30[task->_14 + 24]._00->_68 = 0;
                    lbl_80371C30[task->_14 + 25]._00->_68 = 0;
                } else {
                    lbl_80371C30[task->_14 + 24]._00->_64 = 0x15;
                    lbl_80371C30[task->_14 + 25]._00->_64 = 0x18;
                    lbl_80371C30[task->_14 + 24]._00->_68 = 0;
                    lbl_80371C30[task->_14 + 25]._00->_68 = 0;
                }
                break;
            case 1:
                for (j = 0; j < 3; j++) {
                    lbl_80371C30[task->_14 + 26 + j]._00->_5C = 0;
                    if (lbl_2_bss_1033C._6 != 0) {
                        if (lbl_2_bss_1033C._7 == j) {
                            lbl_80371C30[task->_14 + 26 + j]._00->_64 = 0x18;
                            lbl_80371C30[task->_14 + 26 + j]._00->_68 = 0;
                        } else {
                            lbl_80371C30[task->_14 + 26 + j]._00->_64 = 0x15;
                            lbl_80371C30[task->_14 + 26 + j]._00->_68 = 0;
                        }
                    } else {
                        lbl_80371C30[task->_14 + 7]._00->_68 = 1;
                        if (lbl_2_bss_1033C._7 == j) {
                            lbl_80371C30[task->_14 + 26 + j]._00->_64 = 0x19;
                        } else {
                            lbl_80371C30[task->_14 + 26 + j]._00->_64 = 0x17;
                        }
                        lbl_80371C30[task->_14 + 26 + j]._00->_68 = 1;
                    }
                }
                break;
            case 2:
                lbl_80371C30[task->_14 + 29]._00->_5C = 0;
                lbl_80371C30[task->_14 + 30]._00->_5C = 0;
                if (lbl_2_bss_1033C._8 != 0) {
                    lbl_80371C30[task->_14 + 29]._00->_64 = 0x18;
                    lbl_80371C30[task->_14 + 30]._00->_64 = 0x15;
                    lbl_80371C30[task->_14 + 29]._00->_68 = 0;
                    lbl_80371C30[task->_14 + 30]._00->_68 = 0;
                } else {
                    lbl_80371C30[task->_14 + 29]._00->_64 = 0x15;
                    lbl_80371C30[task->_14 + 30]._00->_64 = 0x18;
                    lbl_80371C30[task->_14 + 29]._00->_68 = 0;
                    lbl_80371C30[task->_14 + 30]._00->_68 = 0;
                }
                break;
            }
            lbl_80371C30[task->_14 + 12 + i]._00->_58 &= ~0xFF;
            lbl_80371C30[task->_14 + 21 + i]._00->_5C = 0;
            lbl_80371C30[task->_14 + 21 + i]._00->_68 = 0;
        }
        fn_800626EC(0);
        lbl_803C66B0._4F = 1;
    }
}

// .text:0x00095FE0 size:0x138
void fn_2_95FE0(MenuTask11C0* task) {
    s32 done;
    s32 count;
    s32 i;

    if (fn_2_isState(1)) {
        done = 0;
        count = 0;
        count++;
        done += fn_80042DA8(task, 0, 0xF) != 0;
        for (i = 0; i < 3; i++) {
            if (i != lbl_2_bss_1033C._2) {
                count++;
                done += fn_80042DA8(task, i + 6, 0xF) != 0;
            }
        }
        if (done == count) {
            changeScene(1, 6);
            for (i = 6; i < 9; i++) {
                lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & ~0xFF) | 0xFF;
            }
            fn_80062674(0);
            lbl_803C66B0._4F = 2;
        }
    }
}

// .text:0x00095F3C size:0xA4
void fn_2_95F3C(MenuTask11C0* task) {
    if (fn_2_isState(0)) {
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_80371C30[task->_14 + 3]._00->_68 = 4;
        lbl_80371C30[task->_14 + 4]._00->_68 = 4;
        fn_800626EC(0);
        lbl_803C66B0._4F = 1;
    }
}

// .text:0x00095E80 size:0xBC
void fn_2_95E80(MenuTask11C0* task) {
    s32 done;
    s32 count;

    if (fn_2_isState(1)) {
        done = 0;
        count = 0;
        count++;
        done += fn_80042DA8(task, 0, 0) != 0;
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) == 3) {
            changeScene(3, 6);
        }
        if (done == count) {
            lbl_2_bss_1033C._E = 1;
            fn_80062674(0);
            lbl_803C66B0._4F = 2;
        }
    }
}

// .text:0x00095B78 size:0x308
void fn_2_95B78(MenuTask11C0* task) {
    s32 i;

    if (fn_2_isState(0)) {
        for (i = 0; i < 3; i++) {
            if (i == lbl_2_bss_1033C._2) {
                lbl_80371C30[task->_14 + 15 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 15 + i]._00->_68 = 1;
                lbl_80371C30[task->_14 + 18 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 18 + i]._00->_68 = 1;
                lbl_80371C30[task->_14 + 6 + i]._00->_68 = 4;
            } else if (i == lbl_2_bss_1033C._4) {
                lbl_80371C30[task->_14 + 15 + i]._00->_5C = 0xA0000;
                lbl_80371C30[task->_14 + 15 + i]._00->_68 = 4;
                lbl_80371C30[task->_14 + 18 + i]._00->_5C = 0xA0000;
                lbl_80371C30[task->_14 + 18 + i]._00->_68 = 4;
                lbl_80371C30[task->_14 + 6 + i]._00->_68 = 1;
            } else if (lbl_2_bss_1033C._6 != 0 || i != 1) {
                lbl_80371C30[task->_14 + 15 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 15 + i]._00->_68 = 0;
                lbl_80371C30[task->_14 + 18 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 18 + i]._00->_68 = 0;
                lbl_80371C30[task->_14 + 6 + i]._00->_5C = 0xF0000;
                lbl_80371C30[task->_14 + 6 + i]._00->_68 = 0;
            }
        }
        lbl_80371C30[task->_14 + 3]._00->_5C = 0;
        fn_800363D8(task, 3, 1, 4, lbl_2_bss_1033C._2);
        lbl_80371C30[task->_14 + 3]._00->_68 = 1;
        lbl_80371C30[task->_14 + 4]._00->_5C = 0;
        fn_800363D8(task, 4, 1, 3, lbl_2_bss_1033C._2);
        lbl_80371C30[task->_14 + 4]._00->_68 = 1;
        fn_800626EC(0);
        lbl_803C66B0._4F = 1;
    }
}

// .text:0x00095B28 size:0x50
void fn_2_95B28(void) {
    if (fn_2_isState(1)) {
        fn_80062674(0);
        lbl_803C66B0._4F = 2;
    }
}

// .text:0x00095604 size:0x50
void fn_2_95604(void) {
    if (fn_2_isState(1)) {
        fn_80062674(0);
        lbl_803C66B0._4F = 2;
    }
}

// .text:0x0009493C size:0x150
void fn_2_9493C(MenuTask11C0* task) {
    s32 done;
    s32 count;

    if (fn_2_isState(1)) {
        done = 0;
        count = 0;
        if (lbl_2_bss_1033C._6 != 0 && lbl_2_bss_1033C._2 == 0 && lbl_2_bss_1033C._B == 0) {
            count++;
            done += fn_80042DA8(task, 0x13, 0) != 0;
        }
        if (done == count) {
            if (lbl_2_bss_1033C._6 != 0 && lbl_2_bss_1033C._2 == 0 && lbl_2_bss_1033C._B == 0) {
                lbl_80371C30[task->_14 + 19]._00->_5C = 0;
                lbl_80371C30[task->_14 + 22]._00->_5C = 0;
                lbl_80371C30[task->_14 + 19]._00->_64 = 0x1A;
                lbl_80371C30[task->_14 + 22]._00->_64 = 0x10;
            }
            fn_80062674(0);
            lbl_803C66B0._4F = 2;
        }
    }
}

// .text:0x000948B8 size:0x84
void fn_2_948B8(void) {
    MenuTask11C0* task = lbl_803CC1B8;

    lbl_2_bss_1033C._F = 0;
    fn_80034E20(task, lbl_2_data_311E4);
    lbl_80371C30[task->_14]._00->_5C = 0x280000;
    ((MenuTask11C0*)lbl_803CC1B8)->fn = fn_2_9486C;
}

// .text:0x0009486C size:0x4C
void fn_2_9486C(void) {
    MenuTask11C0* task = lbl_803CC1B8;

    if (lbl_2_bss_1033C._F != 0) {
        lbl_2_bss_1033C._F = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}
