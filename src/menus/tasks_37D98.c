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
    /* 0x000000 */ u8 _000000[0x16264B];
    /* 0x16264B */ u8 _16264B;
    /* 0x16264C */ u8 _16264C;
    /* 0x16264D */ u8 _16264D;
    /* 0x16264E */ u8 _16264E;
    /* 0x16264F */ u8 _16264F;
    /* 0x162650 */ u8 _162650;
    /* 0x162651 */ u8 _162651;
    /* 0x162652 */ u8 _162652;
    /* 0x162653 */ u8 _162653;
    /* 0x162654 */ u8 _162654;
    /* 0x162655 */ u8 _162655;
    /* 0x162656 */ u8 _162656;
    /* 0x162657 */ u8 _162657[0x16266E - 0x162657];
    /* 0x16266E */ u8 _16266E;
    /* 0x16266F */ u8 _16266F;
    /* 0x162670 */ u8 _162670;
    /* 0x162671 */ u8 _162671[0x162680 - 0x162671];
    /* 0x162680 */ u8 _162680;
    /* 0x162681 */ u8 _162681[0x16281C - 0x162681];
    /* 0x16281C */ u8 _16281C;
    /* 0x16281D */ u8 _16281D[0x162836 - 0x16281D];
    /* 0x162836 */ u8 _162836;
    /* 0x162837 */ u8 _162837;
    /* 0x162838 */ u8 _162838;
    /* 0x162839 */ u8 _162839;
    /* 0x16283A */ u8 _16283A;
    /* 0x16283B */ u8 _16283B;
    /* 0x16283C */ u8 _16283C;
    /* 0x16283D */ u8 _16283D;
    /* 0x16283E */ u8 _16283E;
    /* 0x16283F */ u8 _16283F;
    /* 0x162840 */ u8 _162840;
    /* 0x162841 */ u8 _162841[0x162858 - 0x162841];
    /* 0x162858 */ u8 _162858;
    /* 0x162859 */ u8 _162859;
    /* 0x16285A */ u8 _16285A;
    /* 0x16285B */ u8 _16285B[0x16286A - 0x16285B];
    /* 0x16286A */ u8 _16286A;
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
            lbl_2_bss_1A8234->_16266E = 1;
            break;
        case 1:
            lbl_2_bss_1A8234->_16266F = 1;
            break;
        case 2:
            lbl_2_bss_1A8234->_162670 = 1;
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
            lbl_2_bss_1A8234->_162858 = 1;
            break;
        case 1:
            lbl_2_bss_1A8234->_162859 = 1;
            break;
        case 2:
            lbl_2_bss_1A8234->_16285A = 1;
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
            lbl_2_bss_1A8234->_16264F = 1;
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
            lbl_2_bss_1A8234->_162839 = 1;
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
        lbl_2_bss_1A8234->_162680 = 1;
        task->_14 = 90;
        task->_28 = 3;
        break;
    case 3:
        if (task->_14-- == 0) {
            lbl_2_bss_1A8234->_16286A = 1;
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
            lbl_2_bss_1A8234->_16264C = 1;
            lbl_2_bss_1A8234->_16264D = 1;
            lbl_2_bss_1A8234->_16264E = 1;
        }
        if (lbl_2_bss_1A824C->_19729E != 0) {
            lbl_2_bss_1A8234->_162652 = 1;
            lbl_2_bss_1A8234->_162653 = 1;
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
                lbl_2_bss_1A8234->_16264F = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_162650 = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162651 = 1;
                break;
            }
        }
        if (task->_1A == 1) {
            task->_1A = 0;
            switch (lbl_2_bss_1A824C->_1972AE) {
            case 0:
                lbl_2_bss_1A8234->_162654 = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_162655 = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162656 = 1;
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
            lbl_2_bss_1A8234->_162836 = 1;
            lbl_2_bss_1A8234->_162837 = 1;
            lbl_2_bss_1A8234->_162838 = 1;
        }
        if (lbl_2_bss_1A824C->_1972A4 != 0) {
            switch (lbl_2_bss_1A824C->_1972AC) {
            case 0:
                lbl_2_bss_1A8234->_162839 = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_16283A = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_16283B = 1;
                break;
            }
        }
        if (lbl_2_bss_1A824C->_19729E != 0) {
            lbl_2_bss_1A8234->_16283C = 1;
            lbl_2_bss_1A8234->_16283D = 1;
        }
        if (lbl_2_bss_1A824C->_1972A6 != 0) {
            switch (lbl_2_bss_1A824C->_1972AE) {
            case 0:
                lbl_2_bss_1A8234->_16283E = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_16283F = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162840 = 1;
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
                lbl_2_bss_1A8234->_162839 = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_16283A = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_16283B = 1;
                break;
            }
        }
        if ((task->_16 == 1 || task->_16 == 2) && lbl_2_bss_1A824C->_1972A6 != 0) {
            switch (lbl_2_bss_1A824C->_1972AE) {
            case 0:
                lbl_2_bss_1A8234->_16283E = 1;
                break;
            case 1:
                lbl_2_bss_1A8234->_16283F = 1;
                break;
            case 2:
            case 3:
                lbl_2_bss_1A8234->_162840 = 1;
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
        lbl_2_bss_1A8234->_162838 = 1;
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
        lbl_2_bss_1A8234->_16264E = 1;
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
        lbl_2_bss_1A8234->_16281C = 1;
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
        lbl_2_bss_1A8234->_16264B = 1;
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
