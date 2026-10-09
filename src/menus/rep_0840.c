#include "header_rep_data.h"
#include "menus/rep_0840.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"

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

extern struct {
    /* 0x0000 */ u8 _0000[0x4418];
    /* 0x4418 */ u8 _4418;
    /* 0x4419 */ u8 _4419[0x441E - 0x4419];
    /* 0x441E */ u8 _441E;
    /* 0x441F */ u8 _441F[0x4420 - 0x441F];
    /* 0x4420 */ u8 _4420;
    /* 0x4421 */ u8 _4421[0x4431 - 0x4421];
    /* 0x4431 */ u8 _4431[5];
} *lbl_2_bss_1A8248;

extern struct {
    /* 0x000000 */ u8 _000000[0x19782C];
    /* 0x19782C */ u8 _19782C;
    /* 0x19782D */ u8 _19782D[0x19783E - 0x19782D];
    /* 0x19783E */ u8 _19783E;
    /* 0x19783F */ u8 _19783F;
    /* 0x197840 */ u8 _197840[0x197863 - 0x197840];
    /* 0x197863 */ s8 _197863;
} *lbl_2_bss_1A824C;

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void* ARAMTransfer(AramEntry0840* entry, int arg1, int arg2, u32 aram);
extern void fn_800111B4(void* arg);
extern s32 fn_80062890(s32 id);

extern void fn_2_72054(s32, s32);
extern s32 fn_2_8CC88(s32);
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
