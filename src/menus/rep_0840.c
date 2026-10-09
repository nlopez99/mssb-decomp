#include "header_rep_data.h"
#include "menus/rep_0840.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/vec.h"

typedef struct MenuTask0840 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct MenuTask0840* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ s16 _14;
    /* 0x16 */ s16 _16;
    /* 0x18 */ s16 _18;
    /* 0x1A */ s16 _1A;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u8 _20[0x28 - 0x20];
    /* 0x28 */ s8 _28;
} MenuTask0840;

typedef struct AramEntry0840 {
    /* 0x0 */ u32 _0[4];
} AramEntry0840; // size: 0x10

extern MenuTask0840* lbl_803CC1B8;
extern struct {
    /* 0x000 */ u8 _000[0x7A8];
    /* 0x7A8 */ void* _7A8;
} lbl_80366B18;
extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

typedef struct MenuSlot0840 {
    /* 0x0 */ u8 _0[0x2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6;
    /* 0x7 */ u8 _7[0xA - 0x7];
} MenuSlot0840; // size: 0xA

extern struct {
    /* 0x0000 */ u8 _0000[0x16C2];
    /* 0x16C2 */ s16 _16C2;
    /* 0x16C4 */ u8 _16C4[0x40EE - 0x16C4];
    /* 0x40EE */ MenuSlot0840 _40EE[0x33];
    /* 0x42EC */ u8 _42EC[0x4415 - 0x42EC];
    /* 0x4415 */ u8 _4415;
    /* 0x4416 */ u8 _4416[0x4418 - 0x4416];
    /* 0x4418 */ u8 _4418;
    /* 0x4419 */ u8 _4419;
    /* 0x441A */ u8 _441A;
    /* 0x441B */ u8 _441B;
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ u8 _441F[0x4420 - 0x441F];
    /* 0x4420 */ u8 _4420;
    /* 0x4421 */ u8 _4421;
    /* 0x4422 */ u8 _4422;
    /* 0x4423 */ u8 _4423[0x442A - 0x4423];
    /* 0x442A */ u8 _442A;
    /* 0x442B */ u8 _442B[0x4431 - 0x442B];
    /* 0x4431 */ u8 _4431[5];
    /* 0x4436 */ u8 _4436[0x4439 - 0x4436];
    /* 0x4439 */ u8 _4439;
} *lbl_2_bss_1A8248;

extern struct {
    /* 0x00000 */ u8 _00000[0x32A04];
    /* 0x32A04 */ u8 _32A04[14][10];
} *lbl_2_bss_1A8230;

extern struct {
    /* 0x000000 */ u8 _000000[0x162604];
    /* 0x162604 */ u8 _162604[14][0x46];
} *lbl_2_bss_1A8234;

extern struct {
    /* 0x000000 */ u8 _000000[0x19782C];
    /* 0x19782C */ u8 _19782C;
    /* 0x19782D */ u8 _19782D[0x19783E - 0x19782D];
    /* 0x19783E */ u8 _19783E;
    /* 0x19783F */ u8 _19783F;
    /* 0x197840 */ u8 _197840[0x197851 - 0x197840];
    /* 0x197851 */ s8 _197851;
    /* 0x197852 */ u8 _197852[0x197854 - 0x197852];
    /* 0x197854 */ s8 _197854;
    /* 0x197855 */ u8 _197855[0x197863 - 0x197855];
    /* 0x197863 */ s8 _197863;
} *lbl_2_bss_1A824C;

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void* ARAMTransfer(AramEntry0840* entry, int arg1, int arg2, u32 aram);
extern void fn_800111B4(void* arg);
extern s32 fn_80062890(s32 id);

extern void fn_2_72054(s32, s32);
extern s32 fn_2_8CC88(s32);
extern Vec lbl_2_data_3198[70];
extern s32 lbl_2_data_3C40[7];
extern u8 lbl_2_data_3CC8[8];
extern s16 lbl_2_data_1056C[4][6];
extern s16 lbl_2_data_3CE8[6][6];

extern s32 fn_2_45938(s32);
extern void fn_8006877C(s32);
extern void fn_2_44504(void);
extern void fn_2_46C2C(s32, Vec*);
extern void fn_2_4A6E8(void);
extern void fn_2_90428(s32);
extern void fn_2_92654(s32, s32);
extern void fn_2_94604(s32);
extern void fn_2_9461C(s32);
extern void fn_2_94634(s32);
extern void fn_2_94854(s32);

AramEntry0840 lbl_2_data_12298 = { { 0x00000000, 0x000150CE, 0x08E98800, 0x000150D0 } };
s16 lbl_2_data_122A8[4][2] = { { 3, 0 }, { 2, 1 }, { 3, 1 }, { 4, 1 } };

// .text:0x000409CC size:0xD0
void fn_2_409CC(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_80366B18._7A8 = ARAMTransfer(&lbl_2_data_12298, 0, 1, 0);
        task->_28 = 1;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            fn_800111B4(lbl_80366B18._7A8);
            task->_28 = 2;
        }
        break;
    case 2:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x000408BC size:0x110
void fn_2_408BC(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 60;
        lbl_2_bss_1A824C->_19782C = 1;
        fn_2_72054(1, 13);
        fn_80062890(9);
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0004078C size:0x130
void fn_2_4078C(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A824C->_19783E = 0;
        task->_28 = 1;
        break;
    case 1:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            task->_28 = 2;
        }
        break;
    case 2:
        lbl_2_bss_1A824C->_19783E = 1;
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x000405B4 size:0x1D8
void fn_2_405B4(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        if (fn_2_45938(lbl_2_bss_1A8248->_16C2) == 0) {
            task->_14 = 180;
            lbl_2_bss_1A8248->_40EE[lbl_2_bss_1A8248->_16C2]._3 = 2;
            lbl_2_bss_1A824C->_197854 = lbl_2_bss_1A8248->_40EE[lbl_2_bss_1A8248->_16C2]._5;
            fn_2_90428(lbl_2_bss_1A824C->_197854 + 10);
            fn_2_90428(lbl_2_bss_1A824C->_197854 + 16);
            fn_2_92654(lbl_2_bss_1A824C->_197854 + 10, 12);
            lbl_2_bss_1A8234->_162604[6][25] = 1;
            task->_28 = 1;
        } else {
            task->_28 = 2;
        }
        break;
    case 1:
        if (task->_14 == 150) {
            fn_80062890(65);
        }
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0004041C size:0x198
void fn_2_4041C(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        if (fn_2_45938(lbl_2_bss_1A8248->_16C2) == 0) {
            task->_14 = 180;
            lbl_2_bss_1A8248->_40EE[lbl_2_bss_1A8248->_16C2]._3 = 2;
            lbl_2_bss_1A824C->_197854 = lbl_2_bss_1A8248->_40EE[lbl_2_bss_1A8248->_16C2]._5;
            lbl_2_bss_1A8234->_162604[6][25] = 1;
            fn_80062890(3);
            task->_28 = 1;
        } else {
            task->_28 = 2;
        }
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        lbl_2_bss_1A8248->_40EE[lbl_2_bss_1A8248->_16C2]._3 = 3;
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003F55C size:0x110
void fn_2_3F55C(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 40;
        if (lbl_2_bss_1A8248->_4418 < 5) {
            fn_80062890(7);
            task->_28 = 1;
        } else {
            task->_28 = 2;
        }
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003F44C size:0x110
void fn_2_3F44C(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 40;
        if (lbl_2_bss_1A8248->_4418 != 0) {
            fn_80062890(8);
            task->_28 = 1;
        } else {
            task->_28 = 2;
        }
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003F29C size:0x1B0
void fn_2_3F29C(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A8234->_162604[6][17] = 1;
        task->_14 = 10;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            lbl_2_bss_1A8248->_4439 = 0;
            fn_2_92654(8, 0);
            fn_2_90428(9);
            fn_2_92654(9, 11);
            fn_2_46C2C(0, &lbl_2_data_3198[15]);
            lbl_2_bss_1A8248->_441A = 0;
            lbl_2_bss_1A8248->_40EE[41]._6 = 0;
            fn_80062890(5);
            task->_14 = 80;
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14 == 70) {
            fn_2_46C2C(0, &lbl_2_data_3198[15]);
        }
        if (task->_14-- == 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003F188 size:0x114
void fn_2_3F188(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_14 = 60;
            fn_2_72054(0, 9);
            task->_28 = 2;
        }
        break;
    case 2:
        if (fn_2_8CC88(0) != 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003F004 size:0x184
void fn_2_3F004(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_14 = 80;
            fn_2_72054(0, 10);
            task->_28 = 2;
        }
        break;
    case 2:
        if ((lbl_2_bss_1A8248->_441C == 3 && lbl_2_bss_1A8248->_441E == 1 && lbl_2_bss_1A8248->_16C2 == 11) ||
            (lbl_2_bss_1A8248->_441C == 3 && lbl_2_bss_1A8248->_441E == 5 && lbl_2_bss_1A8248->_16C2 == 42)) {
            if (task->_14-- == 0) {
                task->_28 = 3;
            }
        } else if (fn_2_8CC88(0) != 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003EEF0 size:0x114
void fn_2_3EEF0(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_14 = 60;
            fn_2_72054(0, 11);
            task->_28 = 2;
        }
        break;
    case 2:
        if (fn_2_8CC88(0) != 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003EDD8 size:0x118
void fn_2_3EDD8(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_14 = 60;
            fn_2_72054(0, 9);
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14-- == 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003ECC0 size:0x118
void fn_2_3ECC0(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_14 = 60;
            fn_2_72054(0, 10);
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14-- == 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003EBA8 size:0x118
void fn_2_3EBA8(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_14 = 60;
            fn_2_72054(0, 10);
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14-- == 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003EA44 size:0x164
void fn_2_3EA44(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_14 = 360;
            fn_2_72054(0, 9);
            fn_2_72054(lbl_2_bss_1A8248->_441E, 10);
            task->_28 = 2;
        }
        break;
    case 2:
        if (fn_2_8CC88(0) != 0) {
            task->_28 = 3;
        }
        break;
    case 3:
        if (lbl_2_bss_1A8248->_441C == 5) {
            lbl_2_bss_1A8248->_40EE[lbl_2_bss_1A8248->_16C2]._3 = 3;
        }
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003E918 size:0x12C
void fn_2_3E918(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_14 = 60;
            fn_2_72054(0, 11);
            fn_2_72054(lbl_2_bss_1A8248->_441E, 11);
            task->_28 = 2;
        }
        break;
    case 2:
        if (fn_2_8CC88(0) != 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003E7EC size:0x12C
void fn_2_3E7EC(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_14 = 60;
            fn_2_72054(0, 10);
            fn_2_72054(lbl_2_bss_1A8248->_441E, 9);
            task->_28 = 2;
        }
        break;
    case 2:
        if (fn_2_8CC88(0) != 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003DF28 size:0x130
void fn_2_3DF28(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 20;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x300) {
            task->_14 = 50;
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003DDC4 size:0x164
void fn_2_3DDC4(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A8234->_162604[1][2] = 1;
        task->_14 = 16;
        fn_80062890(56);
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x300) {
            lbl_2_bss_1A8234->_162604[8][2] = 1;
            task->_14 = 16;
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003DC60 size:0x164
void fn_2_3DC60(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A8234->_162604[1][1] = 1;
        task->_14 = 16;
        fn_80062890(56);
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x300) {
            lbl_2_bss_1A8234->_162604[8][1] = 1;
            task->_14 = 16;
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003DAB8 size:0x1A8
void fn_2_3DAB8(void) {
    MenuTask0840* task = lbl_803CC1B8;
    GameInitVariables* settings = &g_d_GameSettings;

    switch (task->_28) {
    case 0:
        if (settings->_1A[lbl_2_data_3CC8[lbl_2_bss_1A8248->_441C]] == 0) {
            settings->_1A[lbl_2_data_3CC8[lbl_2_bss_1A8248->_441C]] = 1;
            lbl_2_bss_1A8234->_162604[1][3] = 1;
            task->_14 = 16;
            fn_80062890(56);
            task->_28 = 1;
        } else {
            task->_28 = 3;
        }
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x300) {
            lbl_2_bss_1A8234->_162604[8][3] = 1;
            task->_14 = 16;
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003D878 size:0x240
void fn_2_3D878(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        fn_2_44504();
        lbl_2_bss_1A8234->_162604[1][6] = 1;
        task->_14 = 300;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14 == 280) {
            fn_80062890(68);
        }
        if (task->_14-- == 0) {
            task->_14 = 100;
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14-- == 0) {
            lbl_2_bss_1A8234->_162604[6][6] = 1;
            lbl_2_bss_1A8230->_32A04[1][1] = 1;
            task->_14 = lbl_2_data_1056C[lbl_2_bss_1A8248->_4415][lbl_2_bss_1A8248->_441C];
            task->_28 = 3;
        }
        break;
    case 3:
        if (task->_14 == 50) {
            fn_80062890(lbl_2_data_3C40[lbl_2_bss_1A8248->_441C]);
        }
        if (task->_14 == 50) {
            fn_8006877C(12);
        }
        if (task->_14-- == 0) {
            task->_14 = 180;
            task->_28 = 4;
        }
        break;
    case 4:
        if (task->_14-- == 0) {
            task->_14 = 50;
            task->_28 = 5;
        }
        break;
    case 5:
        if (task->_14-- == 0) {
            task->_28 = 6;
        }
        break;
    case 6:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003C3EC size:0x150
void fn_2_3C3EC(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            if (lbl_2_bss_1A8248->_4431[lbl_2_bss_1A8248->_4420] == 0) {
                lbl_2_bss_1A8248->_4431[lbl_2_bss_1A8248->_4420] = 1;
                task->_14 = 60;
                fn_2_72054(lbl_2_bss_1A8248->_441E, 15);
                task->_28 = 2;
            } else {
                task->_28 = 3;
            }
        }
        break;
    case 2:
        if (task->_14-- == 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003C168 size:0x284
void fn_2_3C168(void) {
    MenuTask0840* task = lbl_803CC1B8;
    s16 id;
    s32 i;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            id = lbl_2_data_3CE8[lbl_2_bss_1A8248->_441C][lbl_2_bss_1A8248->_4422 + 1];
            lbl_2_bss_1A824C->_197851 = -1;
            if (lbl_2_data_3CE8[lbl_2_bss_1A8248->_441C][lbl_2_bss_1A8248->_4422] != 5) {
                for (i = 0; i < 0x33; i++) {
                    if (id == lbl_2_bss_1A8248->_40EE[i]._2 && lbl_2_bss_1A8248->_40EE[i]._3 == 1) {
                        lbl_2_bss_1A824C->_197851 = id;
                    }
                }
            }
            if (lbl_2_bss_1A824C->_197851 != -1) {
                fn_2_94854(11);
                fn_2_9461C(lbl_2_bss_1A824C->_197851 + 7);
                fn_2_94604(1);
                fn_2_94634(1);
                task->_14 = 60;
                task->_28 = 2;
            } else {
                task->_28 = 3;
            }
        }
        break;
    case 2:
        if (task->_14-- == 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003C03C size:0x12C
void fn_2_3C03C(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            fn_2_94854(11);
            fn_2_9461C(0);
            fn_2_94604(1);
            fn_2_94634(1);
            task->_14 = 20;
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14-- == 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003BC24 size:0x164
void fn_2_3BC24(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A8248->_442A = 1;
        task->_14 = 60;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            fn_2_90428(25);
            fn_2_92654(25, 8);
            fn_2_90428(26);
            fn_2_92654(26, 1);
            fn_2_90428(27);
            fn_2_92654(27, 2);
            fn_80062890(66);
            task->_14 = 180;
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14-- == 0) {
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003BA40 size:0x1E4
void fn_2_3BA40(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        task->_14 = 60;
        fn_2_4A6E8();
        lbl_2_bss_1A8234->_162604[1][31] = 1;
        lbl_2_bss_1A8234->_162604[1][32] = 1;
        lbl_2_bss_1A8234->_162604[1][33] = 1;
        lbl_2_bss_1A8234->_162604[1][34] = 1;
        lbl_2_bss_1A8234->_162604[1][35] = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x300) {
            task->_14 = 50;
            lbl_2_bss_1A8234->_162604[8][31] = 1;
            lbl_2_bss_1A8234->_162604[8][32] = 1;
            lbl_2_bss_1A8234->_162604[8][33] = 1;
            lbl_2_bss_1A8234->_162604[8][34] = 1;
            lbl_2_bss_1A8234->_162604[8][35] = 1;
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
        lbl_803CC1B8->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}
