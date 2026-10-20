#include "menus/tasks_37D98.h"
#include "static/UnknownHomes_Static.h"
#include "menus/rep_08E8.h"
#include "musyx/musyx.h"

typedef struct MenuTask37D98 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct MenuTask37D98* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ s16 _14;
    /* 0x16 */ s16 _16;
    /* 0x18 */ s16 _18;
    /* 0x1A */ s16 _1A;
    /* 0x1C */ u8 _1C[0x28 - 0x1C];
    /* 0x28 */ s8 _28;
} MenuTask37D98;

extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern struct {
    /* 0x00 */ u8 _00[0xDE];
    /* 0xDE */ u8 _DE[0xE4 - 0xDE];
    /* 0xE4 */ u8 _E4[0xE8 - 0xE4];
    /* 0xE8 */ u8 _E8[0xF4 - 0xE8];
} *lbl_2_bss_1A8244;

extern u8 lbl_800EFBA4[0x10];

extern struct {
    /* 0x000000 */ u8 _000000[0x162604];
    /* 0x162604 */ u8 _162604[14][0x46];
} *lbl_2_bss_1A8234;
extern struct {
    /* 0x000000 */ u8 _000000[0x19729C];
    /* 0x19729C */ s16 _19729C;
    /* 0x19729E */ s16 _19729E;
    /* 0x1972A0 */ u8 _1972A0[0x1972A4 - 0x1972A0];
    /* 0x1972A4 */ s16 _1972A4;
    /* 0x1972A6 */ s16 _1972A6;
    /* 0x1972A8 */ u8 _1972A8[0x1972AC - 0x1972A8];
    /* 0x1972AC */ s16 _1972AC;
    /* 0x1972AE */ s16 _1972AE;
    /* 0x1972B0 */ u8 _1972B0[0x1972B6 - 0x1972B0];
    /* 0x1972B6 */ u8 _1972B6;
    /* 0x1972B7 */ u8 _1972B7;
    /* 0x1972B8 */ u8 _1972B8[0x1976A8 - 0x1972B8];
    /* 0x1976A8 */ s32 _1976A8;
    /* 0x1976AC */ u8 _1976AC[0x1976DC - 0x1976AC];
    /* 0x1976DC */ s16 _1976DC;
    /* 0x1976DE */ s16 _1976DE;
    /* 0x1976E0 */ s16 _1976E0;
    /* 0x1976E2 */ u8 _1976E2[0x19782C - 0x1976E2];
    /* 0x19782C */ u8 _19782C;
    /* 0x19782D */ u8 _19782D[0x19783F - 0x19782D];
    /* 0x19783F */ u8 _19783F;
    /* 0x197840 */ u8 _197840[0x197863 - 0x197840];
    /* 0x197863 */ s8 _197863;
    /* 0x197864 */ u8 _197864[0x1978FA - 0x197864];
    /* 0x1978FA */ s8 _1978FA;
} *lbl_2_bss_1A824C;
extern struct {
    /* 0x0000 */ u8 _0000[0x4415];
    /* 0x4415 */ u8 _4415;
    /* 0x4416 */ u8 _4416;
    /* 0x4417 */ u8 _4417[0x441C - 0x4417];
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D[0x4420 - 0x441D];
    /* 0x4420 */ u8 _4420;
    /* 0x4421 */ u8 _4421[0x444B - 0x4421];
    /* 0x444B */ s8 _444B;
    /* 0x444C */ s8 _444C;
    /* 0x444D */ u8 _444D[0x44F2 - 0x444D];
    /* 0x44F2 */ u8 _44F2;
} *lbl_2_bss_1A8248;

extern void fn_800B0A14_removeQueue(void);
extern void fn_8000FF04(s32, s32, s32, s32, s32, s32, s32);
extern s32 fn_80062890(s32 id);
extern void changeScene(u8, s16);
extern u8 fn_8006862C(s32, s32);

// .text:0x000397AC size:0x214
void fn_2_397AC(void) {
    MenuTask37D98* task = lbl_803CC1B8;
    u16 buttons;

    switch (task->_28) {
    case 0:
        task->_14 = 30;
        lbl_2_bss_1A824C->_1976DC = 0;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        buttons = lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04;
        if ((buttons & 1) && lbl_2_bss_1A824C->_1976DC == 1) {
            lbl_2_bss_1A824C->_1976DC = 0;
        } else if ((buttons & 2) && lbl_2_bss_1A824C->_1976DC == 0) {
            lbl_2_bss_1A824C->_1976DC = 1;
        }
        buttons = lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02;
        if (buttons & 0x100) {
            task->_28 = 3;
        } else if (buttons & 0x200) {
            if (lbl_2_bss_1A824C->_1976DC == 0) {
                lbl_2_bss_1A824C->_1976DC = 1;
            } else {
                task->_28 = 3;
            }
        }
        fn_8000FF04(4, 0x2DF, 100, 200, 9, -1, 0);
        break;
    case 3:
        task->_14 = 16;
        task->_28 = 4;
        break;
    case 4:
        if (task->_14-- == 0) {
            if (lbl_2_bss_1A824C->_1976DC == 0) {
                ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
            } else {
                ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 2;
            }
            fn_800B0A14_removeQueue();
            task->_28 = 0;
        }
        break;
    }
}

// .text:0x00039408 size:0x3A4
void fn_2_39408(void) {
    MenuTask37D98* task = lbl_803CC1B8;
    u16 buttons;

    switch (task->_28) {
    case 0:
        switch (lbl_2_bss_1A824C->_1972B6) {
        case 0:
            lbl_2_bss_1A8234->_162604[1][36] = 1;
            break;
        case 1:
            lbl_2_bss_1A8234->_162604[1][37] = 1;
            break;
        case 2:
            lbl_2_bss_1A8234->_162604[1][38] = 1;
            break;
        }
        task->_14 = 10;
        task->_16 = 0;
        lbl_2_bss_1A824C->_1976DE = lbl_2_bss_1A824C->_1972B7;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        buttons = lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04;
        if ((buttons & 1) && lbl_2_bss_1A824C->_1976DE == 1) {
            lbl_2_bss_1A824C->_1976DE = 0;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if ((buttons & 2) && lbl_2_bss_1A824C->_1976DE == 0) {
            lbl_2_bss_1A824C->_1976DE = 1;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
        buttons = lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02;
        if (buttons & 0x100) {
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->_28 = 3;
        } else if (buttons & 0x200) {
            if (lbl_2_bss_1A824C->_1976DE == 0) {
                lbl_2_bss_1A824C->_1976DE = 1;
            } else {
                task->_16 = 1;
                task->_28 = 3;
            }
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        }
        break;
    case 3:
        switch (lbl_2_bss_1A824C->_1972B6) {
        case 0:
            lbl_2_bss_1A8234->_162604[8][36] = 1;
            break;
        case 1:
            lbl_2_bss_1A8234->_162604[8][37] = 1;
            break;
        case 2:
            lbl_2_bss_1A8234->_162604[8][38] = 1;
            break;
        }
        task->_14 = 10;
        task->_28 = 4;
        break;
    case 4:
        if (task->_14-- == 0) {
            if (lbl_2_bss_1A824C->_1976DE == 0) {
                ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
            } else if (task->_16 == 0) {
                ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 2;
            } else {
                ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 3;
            }
            fn_800B0A14_removeQueue();
            task->_28 = 0;
        }
        break;
    }
}

// .text:0x000391B4 size:0x254
void fn_2_391B4(void) {
    MenuTask37D98* task = lbl_803CC1B8;
    u16 buttons;

    switch (task->_28) {
    case 0:
        task->_14 = 30;
        lbl_2_bss_1A824C->_1976E0 = 0;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        buttons = lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04;
        if ((buttons & 1) && lbl_2_bss_1A824C->_1976E0 == 1) {
            lbl_2_bss_1A824C->_1976E0 = 0;
        } else if ((buttons & 2) && lbl_2_bss_1A824C->_1976E0 == 0) {
            lbl_2_bss_1A824C->_1976E0 = 1;
        }
        buttons = lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02;
        if (buttons & 0x100) {
            task->_28 = 3;
        } else if (buttons & 0x200) {
            if (lbl_2_bss_1A824C->_1976E0 == 0) {
                lbl_2_bss_1A824C->_1976E0 = 1;
            } else {
                task->_28 = 3;
            }
        }
        if (task->_16 == 0) {
            fn_8000FF04(4, 0x2E0, 100, 200, 9, -1, 0);
        } else {
            fn_8000FF04(4, lbl_2_bss_1A8248->_4420 + 0x2ED, 100, 200, 9, -1, 0);
        }
        break;
    case 3:
        task->_14 = 16;
        task->_28 = 4;
        break;
    case 4:
        if (task->_14-- == 0) {
            if (lbl_2_bss_1A824C->_1976E0 == 0) {
                ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
            } else {
                ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 2;
            }
            fn_800B0A14_removeQueue();
            task->_28 = 0;
        }
        break;
    }
}

// .text:0x00038F48 size:0x26C
void fn_2_38F48(void) {
    MenuTask37D98* task = lbl_803CC1B8;
    s32 flag;

    switch (task->_28) {
    case 0:
        flag = 0;
        if (lbl_2_bss_1A8244->_E4[lbl_2_bss_1A8248->_4415] == 0 && lbl_2_bss_1A8248->_4415 < 3) {
            flag = 1;
        }
        fn_2_38EA8();
        if (flag != 0) {
            task->_14 = 18;
            lbl_2_bss_1A8234->_162604[1][5] = 1;
            fn_80062890(0x38);
            task->_28 = 1;
        } else {
            task->_28 = 4;
        }
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            task->_14 = 18;
            lbl_2_bss_1A8234->_162604[8][5] = 1;
            task->_28 = 3;
        }
        break;
    case 3:
        if (task->_14-- == 0) {
            task->_28 = 4;
        }
        break;
    case 4:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x00038EA8 size:0xA0
void fn_2_38EA8(void) {
    lbl_2_bss_1A8248->_4416 = lbl_2_bss_1A8248->_4415;
    lbl_2_bss_1A8244->_E4[lbl_2_bss_1A8248->_4415] = 1;
    if (lbl_2_bss_1A8248->_4415 < 3) {
        if (lbl_2_bss_1A8244->_E8[lbl_2_bss_1A8248->_441C] == 0) {
            lbl_2_bss_1A8244->_E8[lbl_2_bss_1A8248->_441C] = 1;
        }
        lbl_2_bss_1A8248->_4415++;
        lbl_2_bss_1A8244->_DE[lbl_2_bss_1A8248->_441C]++;
    }
}

// .text:0x00038D44 size:0x164
void fn_2_38D44(void) {
    MenuTask37D98* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        if (fn_2_45A84() == 1) {
            task->_14 = 1;
            task->_28 = 1;
        } else {
            task->_28 = 4;
        }
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        lbl_2_bss_1A8234->_162604[1][54] = 1;
        task->_14 = 90;
        task->_28 = 3;
        break;
    case 3:
        if (task->_14-- == 0) {
            lbl_2_bss_1A8234->_162604[8][54] = 1;
            task->_28 = 4;
        }
        break;
    case 4:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x00038C14 size:0x130
void fn_2_38C14(void) {
    MenuTask37D98* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 20;
        task->_28 = 2;
        break;
    case 1:
        if (task->_14-- == 0) {
            lbl_2_bss_1A824C->_19782C = 1;
            task->_14 = 20;
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14-- == 0) {
            task->_14 = 20;
            task->_28 = 3;
        }
        break;
    case 3:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x00038A40 size:0x1D4
void fn_2_38A40(void) {
    MenuTask37D98* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A8248->_44F2 = 3;
        task->_14 = 15;
        if (lbl_2_bss_1A824C->_19729C != 0) {
            lbl_2_bss_1A8234->_162604[1][2] = 1;
            lbl_2_bss_1A8234->_162604[1][3] = 1;
            lbl_2_bss_1A8234->_162604[1][4] = 1;
        }
        if (lbl_2_bss_1A824C->_19729E != 0) {
            lbl_2_bss_1A8234->_162604[1][8] = 1;
            lbl_2_bss_1A8234->_162604[1][9] = 1;
        }
        if (lbl_2_bss_1A824C->_1978FA == 0) {
            lbl_2_bss_1A824C->_1976A8 = fn_80062890(0x11);
        }
        lbl_2_bss_1A824C->_1978FA = 0;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x00038824 size:0x21C
void fn_2_38824(void) {
    MenuTask37D98* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 10;
        if (task->_18 == 1) {
            task->_18 = 0;
            switch (lbl_2_bss_1A824C->_1972AC) {
            case 0:
                lbl_2_bss_1A8234->_162604[1][5] = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_162604[1][6] = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162604[1][7] = 1;
                break;
            }
        }
        if (task->_1A == 1) {
            task->_1A = 0;
            switch (lbl_2_bss_1A824C->_1972AE) {
            case 0:
                lbl_2_bss_1A8234->_162604[1][10] = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_162604[1][11] = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162604[1][12] = 1;
                break;
            }
        }
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x00038538 size:0x2EC
void fn_2_38538(void) {
    MenuTask37D98* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 30;
        if (lbl_2_bss_1A824C->_19729C != 0) {
            lbl_2_bss_1A8234->_162604[8][2] = 1;
            lbl_2_bss_1A8234->_162604[8][3] = 1;
            lbl_2_bss_1A8234->_162604[8][4] = 1;
        }
        if (lbl_2_bss_1A824C->_1972A4 != 0) {
            switch (lbl_2_bss_1A824C->_1972AC) {
            case 0:
                lbl_2_bss_1A8234->_162604[8][5] = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_162604[8][6] = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162604[8][7] = 1;
                break;
            }
        }
        if (lbl_2_bss_1A824C->_19729E != 0) {
            lbl_2_bss_1A8234->_162604[8][8] = 1;
            lbl_2_bss_1A8234->_162604[8][9] = 1;
        }
        if (lbl_2_bss_1A824C->_1972A6 != 0) {
            switch (lbl_2_bss_1A824C->_1972AE) {
            case 0:
                lbl_2_bss_1A8234->_162604[8][10] = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_162604[8][11] = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162604[8][12] = 1;
                break;
            }
        }
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(0x11);
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        lbl_2_bss_1A8248->_44F2 = 0;
        lbl_2_bss_1A824C->_1972A6 = 0;
        lbl_2_bss_1A824C->_1972A4 = 0;
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x000382A0 size:0x298
void fn_2_382A0(void) {
    MenuTask37D98* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 5;
        if ((task->_16 == 0 || task->_16 == 2) && lbl_2_bss_1A824C->_1972A4 != 0) {
            switch (lbl_2_bss_1A824C->_1972AC) {
            case 0:
                lbl_2_bss_1A8234->_162604[8][5] = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_162604[8][6] = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162604[8][7] = 1;
                break;
            }
        }
        if ((task->_16 == 1 || task->_16 == 2) && lbl_2_bss_1A824C->_1972A6 != 0) {
            switch (lbl_2_bss_1A824C->_1972AE) {
            case 0:
                lbl_2_bss_1A8234->_162604[8][10] = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_162604[8][11] = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162604[8][12] = 1;
                break;
            }
        }
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_16 == 0 || task->_16 == 2) {
            lbl_2_bss_1A824C->_1972A4 = 0;
        }
        if (task->_16 == 1 || task->_16 == 2) {
            lbl_2_bss_1A824C->_1972A6 = 0;
        }
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x000381A8 size:0xF8
void fn_2_381A8(void) {
    MenuTask37D98* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 21;
        lbl_2_bss_1A8234->_162604[8][4] = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x000380B0 size:0xF8
void fn_2_380B0(void) {
    MenuTask37D98* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 21;
        lbl_2_bss_1A8234->_162604[1][4] = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x00037F04 size:0x1AC
void fn_2_37F04(void) {
    MenuTask37D98* task = lbl_803CC1B8;
    GameInitVariables* settings = &g_d_GameSettings;

    switch (task->_28) {
    case 0:
        if (lbl_2_bss_1A8248->_444B != -1) {
            task->_14 = 20;
            task->_28 = 1;
        } else {
            task->_28 = 4;
        }
        break;
    case 1:
        if (task->_14 == 4) {
            fn_80062890(0x43);
        }
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        settings->challengeCaptainStarBought[lbl_2_bss_1A8248->_444B] = 0;
        lbl_2_bss_1A8248->_444C = -1;
        lbl_2_bss_1A8248->_444B = -1;
        lbl_2_bss_1A8234->_162604[7][46] = 1;
        task->_14 = 60;
        task->_28 = 3;
        break;
    case 3:
        if (task->_14-- == 0) {
            task->_28 = 4;
        }
        break;
    case 4:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x00037D98 size:0x16C
void fn_2_37D98(void) {
    MenuTask37D98* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        changeScene(1, 6);
        task->_14 = 9902;
        task->_16 = 0;
        lbl_2_bss_1A8234->_162604[1][1] = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        task->_16++;
        break;
    case 2:
        if (fn_8006862C(0x1A4, 0) == 0) {
            task->_28 = 3;
        }
        break;
    case 3:
        changeScene(3, 6);
        task->_28 = 4;
        break;
    case 4:
        if (lbl_8037169C._13 != 0) {
            task->_0C->_10 = 1;
            fn_800B0A14_removeQueue();
            task->_28 = 0;
        }
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask37D98*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}
