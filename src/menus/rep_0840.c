#include "header_rep_data.h"
#include "menus/rep_0840.h"
#include "menus/rep_09B8.h"
#include "menus/rep_0B08.h"
#include "menus/rep_0F60.h"
#include "menus/rep_1028.h"
#include "menus/rep_10C0.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/vec.h"
#include "musyx/musyx.h"
#include "string.h"

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

extern void* lbl_803CC1B8;
extern struct {
    /* 0x000 */ u8 _000[0x7A8];
    /* 0x7A8 */ void* _7A8;
} lbl_80366B18;
extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x3 - 0x1];
    /* 0x03 */ u8 _03;
    /* 0x04 */ u8 _04[0x8 - 0x4];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A[0x26 - 0xA];
    /* 0x26 */ u8 _26;
} lbl_8034E978;
extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} lbl_800FEF70[];
extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} lbl_8037169C;
extern u8 lbl_800E869C[0x20];
extern s16 lbl_8010B438[6];
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
    /* 0x0000 */ u8 _0000[0x16C0];
    /* 0x16C0 */ s16 _16C0;
    /* 0x16C2 */ s16 _16C2;
    /* 0x16C4 */ u8 _16C4[0x40EE - 0x16C4];
    /* 0x40EE */ MenuSlot0840 _40EE[0x33];
    /* 0x42EC */ u8 _42EC[0x43BC - 0x42EC];
    /* 0x43BC */ s16 _43BC;
    /* 0x43BE */ s16 _43BE;
    /* 0x43C0 */ u8 _43C0[0x43C2 - 0x43C0];
    /* 0x43C2 */ s8 _43C2[0x14];
    /* 0x43D6 */ u8 _43D6[0x440C - 0x43D6];
    /* 0x440C */ u8 _440C[6];
    /* 0x4412 */ u8 _4412[0x4415 - 0x4412];
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
    /* 0x4423 */ u8 _4423[0x4428 - 0x4423];
    /* 0x4428 */ u8 _4428;
    /* 0x4429 */ u8 _4429;
    /* 0x442A */ u8 _442A;
    /* 0x442B */ u8 _442B;
    /* 0x442C */ u8 _442C;
    /* 0x442D */ u8 _442D[0x4431 - 0x442D];
    /* 0x4431 */ u8 _4431[5];
    /* 0x4436 */ u8 _4436[0x4439 - 0x4436];
    /* 0x4439 */ u8 _4439;
    /* 0x443A */ u8 _443A[0x4446 - 0x443A];
    /* 0x4446 */ u8 _4446;
    /* 0x4447 */ u8 _4447;
    /* 0x4448 */ u8 _4448[0x444A - 0x4448];
    /* 0x444A */ u8 _444A;
    /* 0x444B */ s8 _444B;
    /* 0x444C */ s8 _444C;
    /* 0x444D */ s8 _444D[0x6C];
    /* 0x44B9 */ s8 _44B9[0x36];
    /* 0x44EF */ u8 _44EF[0x44F2 - 0x44EF];
    /* 0x44F2 */ u8 _44F2;
    /* 0x44F3 */ u8 _44F3;
    /* 0x44F4 */ s8 _44F4;
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
    /* 0x000000 */ u8 _000000[0x1972AC];
    /* 0x1972AC */ s16 _1972AC;
    /* 0x1972AE */ u8 _1972AE[0x1972B0 - 0x1972AE];
    /* 0x1972B0 */ s16 _1972B0;
    /* 0x1972B2 */ u8 _1972B2[0x1972B9 - 0x1972B2];
    /* 0x1972B9 */ u8 _1972B9;
    /* 0x1972BA */ u8 _1972BA[0x1976A8 - 0x1972BA];
    /* 0x1976A8 */ s32 _1976A8;
    /* 0x1976AC */ u8 _1976AC[0x197706 - 0x1976AC];
    /* 0x197706 */ s16 _197706;
    /* 0x197708 */ s16 _197708;
    /* 0x19770A */ s16 _19770A;
    /* 0x19770C */ s16 _19770C;
    /* 0x19770E */ s16 _19770E;
    /* 0x197710 */ s16 _197710;
    /* 0x197712 */ s16 _197712;
    /* 0x197714 */ s16 _197714;
    /* 0x197716 */ u8 _197716[0x197726 - 0x197716];
    /* 0x197726 */ s16 _197726;
    /* 0x197728 */ s16 _197728;
    /* 0x19772A */ s16 _19772A;
    /* 0x19772C */ s16 _19772C;
    /* 0x19772E */ u8 _19772E[0x197730 - 0x19772E];
    /* 0x197730 */ s16 _197730;
    /* 0x197732 */ u8 _197732[0x197734 - 0x197732];
    /* 0x197734 */ s16 _197734;
    /* 0x197736 */ s16 _197736;
    /* 0x197738 */ s16 _197738;
    /* 0x19773A */ s16 _19773A;
    /* 0x19773C */ s16 _19773C;
    /* 0x19773E */ s16 _19773E;
    /* 0x197740 */ s16 _197740;
    /* 0x197742 */ u8 _197742[0x19782C - 0x197742];
    /* 0x19782C */ u8 _19782C;
    /* 0x19782D */ u8 _19782D[0x19783E - 0x19782D];
    /* 0x19783E */ u8 _19783E;
    /* 0x19783F */ u8 _19783F;
    /* 0x197840 */ u8 _197840[0x197843 - 0x197840];
    /* 0x197843 */ s8 _197843;
    /* 0x197844 */ u8 _197844[0x197851 - 0x197844];
    /* 0x197851 */ s8 _197851;
    /* 0x197852 */ u8 _197852[0x197854 - 0x197852];
    /* 0x197854 */ s8 _197854;
    /* 0x197855 */ u8 _197855[0x197863 - 0x197855];
    /* 0x197863 */ s8 _197863;
    /* 0x197864 */ u8 _197864[0x197866 - 0x197864];
    /* 0x197866 */ s8 _197866;
    /* 0x197867 */ s8 _197867;
    /* 0x197868 */ u8 _197868[0x19789E - 0x197868];
    /* 0x19789E */ u8 _19789E;
    /* 0x19789F */ s8 _19789F[20];
    /* 0x1978B3 */ u8 _1978B3[0x1978EF - 0x1978B3];
    /* 0x1978EF */ s8 _1978EF;
    /* 0x1978F0 */ s8 _1978F0;
    /* 0x1978F1 */ u8 _1978F1[0x1978F4 - 0x1978F1];
    /* 0x1978F4 */ u8 _1978F4;
    /* 0x1978F5 */ s8 _1978F5;
    /* 0x1978F6 */ s8 _1978F6;
    /* 0x1978F7 */ u8 _1978F7;
    /* 0x1978F8 */ u8 _1978F8;
    /* 0x1978F9 */ u8 _1978F9;
} *lbl_2_bss_1A824C;

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void* ARAMTransfer(AramEntry0840* entry, int arg1, int arg2, u32 aram);
extern void fn_800111B4(void* arg);
extern s32 fn_80062890(s32 id);
extern void fn_80053FE8(void);
extern void changeScene(u8, s16);
extern u8 fn_80068514(s32, s32);
extern u8 fn_8006862C(s32, s32);
extern void fn_8006C6C4(void);
extern BOOL fn_8006C79C(s32 index);

extern struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ u8 _0C[0x14 - 0xC];
} lbl_2_data_3198[42];
extern u8 lbl_800EFBA4[0x10];
extern s32 lbl_2_data_3C40[7];
extern u8 lbl_2_data_3CC8[8];
extern s16 lbl_2_data_1056C[4][6];
extern s16 lbl_2_data_3CE8[6][6];
extern s16 lbl_2_data_373C[20];
extern s16 lbl_2_data_3764[20][4];
extern s16 lbl_2_data_296B8[36];
extern s16 lbl_2_data_29700[36];

extern s32 fn_2_45938(s32);
extern void fn_8006877C(s32);
extern void fn_2_1C41C(void);
extern void fn_2_1C490(void);
extern void fn_2_38538(void);
extern void fn_2_42490(void);
extern void fn_2_42638(void);
extern void fn_2_432EC(void);
extern void fn_2_43E8C(void);
extern void fn_2_44014(void);
extern void fn_2_45204(void);
extern s32 fn_2_45A84(void);
extern void fn_2_45E48(void);
extern s32 fn_2_44F14(s32);
extern void fn_2_46D34(s32);
extern void fn_2_46D94(s16*, s16*, s32, s32, s32);
extern void fn_2_44504(void);
extern void fn_2_450E4(void);
extern void fn_2_45354(void);
extern void fn_2_46C2C(s32, Vec*);
extern void fn_2_4A6E8(void);

AramEntry0840 lbl_2_data_12298 = { { 0x00000000, 0x000150CE, 0x08E98800, 0x000150D0 } };
s16 lbl_2_data_122A8[4][2] = { { 3, 0 }, { 2, 1 }, { 3, 1 }, { 4, 1 } };


static inline void setScreen(u8 id) {
    lbl_8034E978._00 = id;
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._08 = lbl_800FEF70[id]._08;
}

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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003FDE0 size:0x63C
void fn_2_3FDE0(void) {
    MenuTask0840* task = lbl_803CC1B8;
    s16 id;
    s32 i;

    switch (task->_28) {
    case 0:
        task->_14 = 70;
        id = lbl_2_data_3CE8[lbl_2_bss_1A8248->_441C][lbl_2_bss_1A8248->_4422 + 1];
        lbl_2_bss_1A824C->_197851 = -1;
        if (lbl_2_data_3CE8[lbl_2_bss_1A8248->_441C][lbl_2_bss_1A8248->_4422] != 5) {
            for (i = 0; i < 0x33; i++) {
                if (id == lbl_2_bss_1A8248->_40EE[i]._2 && lbl_2_bss_1A8248->_40EE[i]._3 == 1) {
                    lbl_2_bss_1A8248->_40EE[i]._3 = 0;
                    lbl_2_bss_1A824C->_197851 = id;
                }
            }
        }
        if (lbl_2_bss_1A824C->_197851 != -1) {
            lbl_2_bss_1A8248->_440C[lbl_2_bss_1A824C->_197851] = 1;
            switch (lbl_2_bss_1A8248->_441C) {
            case 0:
                if (lbl_2_bss_1A824C->_197851 == 3) {
                    for (i = 0; i < 0x33; i++) {
                        if ((lbl_2_bss_1A8248->_40EE[i]._2 == 6 && lbl_2_bss_1A8248->_40EE[i]._3 == 1) || (lbl_2_bss_1A8248->_40EE[i]._2 == 8 && lbl_2_bss_1A8248->_40EE[i]._3 == 1)) {
                            lbl_2_bss_1A8248->_40EE[i]._3 = 0;
                        }
                    }
                }
                break;
            case 1:
                if (lbl_2_bss_1A824C->_197851 == 3) {
                    for (i = 0; i < 0x33; i++) {
                        if ((lbl_2_bss_1A8248->_40EE[i]._2 == 6 && lbl_2_bss_1A8248->_40EE[i]._3 == 1) || (lbl_2_bss_1A8248->_40EE[i]._2 == 8 && lbl_2_bss_1A8248->_40EE[i]._3 == 1)) {
                            lbl_2_bss_1A8248->_40EE[i]._3 = 0;
                        }
                    }
                }
                break;
            case 2:
                if (lbl_2_bss_1A824C->_197851 == 1) {
                    for (i = 0; i < 0x33; i++) {
                        if ((lbl_2_bss_1A8248->_40EE[i]._2 == 6 && lbl_2_bss_1A8248->_40EE[i]._3 == 1) || (lbl_2_bss_1A8248->_40EE[i]._2 == 7 && lbl_2_bss_1A8248->_40EE[i]._3 == 1)) {
                            lbl_2_bss_1A8248->_40EE[i]._3 = 0;
                        }
                    }
                }
                break;
            case 3:
                break;
            }
            lbl_2_bss_1A8234->_162604[3][15] = 1;
            fn_80062890(4);
            task->_28 = 1;
        } else {
            task->_28 = 4;
        }
        break;
    case 1:
        if (task->_14-- == 0) {
            fn_2_92654(lbl_2_bss_1A824C->_197851 + 1, 7);
            if (lbl_2_bss_1A824C->_197851 == 2) {
                fn_2_92654(7, 7);
            }
            task->_14 = 60;
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14-- == 0) {
            if (lbl_2_bss_1A824C->_197851 == 5) {
                lbl_2_bss_1A8234->_162604[3][17] = 1;
                task->_14 = 16;
                task->_28 = 3;
            } else {
                task->_28 = 4;
            }
        }
        break;
    case 3:
        if (task->_14-- == 0) {
            lbl_2_bss_1A8248->_441A = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003FA14 size:0x3CC
void fn_2_3FA14(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A824C->_197740 = 0;
        lbl_2_bss_1A824C->_197734 = lbl_2_bss_1A8248->_43BC;
        lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_19773C = lbl_2_bss_1A8248->_43BE;
        lbl_2_bss_1A824C->_19773A = 0;
        lbl_2_bss_1A824C->_197738 = lbl_2_bss_1A824C->_197734 / 2;
        task->_28 = 1;
        break;
    case 1:
        lbl_2_bss_1A824C->_19773A *= 2;
        if (lbl_2_bss_1A824C->_19773A == 0) {
            lbl_2_bss_1A824C->_19773A++;
        }
        lbl_2_bss_1A824C->_197736 += lbl_2_bss_1A824C->_19773A;
        lbl_2_bss_1A824C->_19773A++;
        lbl_2_bss_1A8234->_162604[6][45] = 1;
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(55);
        if (lbl_2_bss_1A824C->_197736 >= lbl_2_bss_1A824C->_197738 || lbl_2_bss_1A824C->_197736 >= lbl_2_bss_1A824C->_197734) {
            if (lbl_2_bss_1A824C->_197736 >= lbl_2_bss_1A824C->_197734) {
                lbl_2_bss_1A824C->_197736 -= lbl_2_bss_1A824C->_19773A;
                if (lbl_2_bss_1A824C->_197736 < 1) {
                    lbl_2_bss_1A824C->_197736 = 1;
                }
            }
            task->_28 = 2;
        }
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_197734;
            task->_28 = 4;
        }
        break;
    case 2:
        if (lbl_2_bss_1A824C->_197736 >= lbl_2_bss_1A824C->_197734) {
            lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_197734;
            task->_28 = 4;
        } else {
            lbl_2_bss_1A824C->_197736 += (lbl_2_bss_1A824C->_197734 - lbl_2_bss_1A824C->_197736) / 20;
            lbl_2_bss_1A824C->_197736++;
            lbl_2_bss_1A8234->_162604[6][45] = 1;
            lbl_2_bss_1A824C->_1976A8 = fn_80062890(55);
            if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
                lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_197734;
                task->_28 = 4;
            }
        }
        break;
    case 3:
        break;
    case 4:
        task->_14 = 10;
        task->_28 = 5;
        break;
    case 5:
        if (task->_14-- == 0) {
            lbl_2_bss_1A824C->_197740 = 1;
            lbl_2_bss_1A824C->_19773E = 0;
            ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
            fn_800B0A14_removeQueue();
            task->_28 = 0;
        }
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003F66C size:0x3A8
void fn_2_3F66C(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A824C->_197740 = 0;
        lbl_2_bss_1A824C->_197734 = lbl_2_bss_1A8248->_43BC;
        lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_19773C = lbl_2_bss_1A8248->_43BE;
        lbl_2_bss_1A824C->_19773A = 0;
        lbl_2_bss_1A824C->_197738 = lbl_2_bss_1A824C->_197734 + (lbl_2_bss_1A824C->_197736 - lbl_2_bss_1A824C->_197734) / 2;
        task->_28 = 1;
        break;
    case 1:
        lbl_2_bss_1A824C->_19773A *= 2;
        if (lbl_2_bss_1A824C->_19773A == 0) {
            lbl_2_bss_1A824C->_19773A++;
        }
        lbl_2_bss_1A824C->_197736 -= lbl_2_bss_1A824C->_19773A;
        lbl_2_bss_1A824C->_19773A++;
        lbl_2_bss_1A8234->_162604[7][45] = 1;
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(55);
        if (lbl_2_bss_1A824C->_197736 <= lbl_2_bss_1A824C->_197734) {
            lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_197734;
            task->_28 = 4;
        } else if (lbl_2_bss_1A824C->_197736 <= lbl_2_bss_1A824C->_197738) {
            lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_197738;
            task->_28 = 2;
        }
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_197734;
            task->_28 = 4;
        }
        break;
    case 2:
        lbl_2_bss_1A824C->_197736 += (lbl_2_bss_1A824C->_197734 - lbl_2_bss_1A824C->_197736) / 20;
        lbl_2_bss_1A824C->_197736--;
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(55);
        lbl_2_bss_1A8234->_162604[7][45] = 1;
        if (lbl_2_bss_1A824C->_197736 <= lbl_2_bss_1A824C->_197734) {
            lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_197734;
            task->_28 = 4;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            lbl_2_bss_1A824C->_197736 = lbl_2_bss_1A824C->_197734;
            task->_28 = 4;
        }
        break;
    case 3:
        break;
    case 4:
        task->_14 = 10;
        task->_28 = 5;
        break;
    case 5:
        if (task->_14-- == 0) {
            lbl_2_bss_1A824C->_197740 = 1;
            lbl_2_bss_1A824C->_19773E = 0;
            ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
            fn_800B0A14_removeQueue();
            task->_28 = 0;
        }
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
            fn_2_46C2C(0, &lbl_2_data_3198[9]._00);
            lbl_2_bss_1A8248->_441A = 0;
            lbl_2_bss_1A8248->_40EE[41]._6 = 0;
            fn_80062890(5);
            task->_14 = 80;
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14 == 70) {
            fn_2_46C2C(0, &lbl_2_data_3198[9]._00);
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003E38C size:0x460
void fn_2_3E38C(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        fn_2_1C490();
        task->_14 = 30;
        if (lbl_2_bss_1A8248->_4422 >= 4 && lbl_2_bss_1A8248->_4446 == 0 && lbl_2_bss_1A8248->_441C != 5) {
            lbl_2_bss_1A8248->_4446 = 1;
            task->_28 = 1;
        } else {
            task->_28 = 14;
        }
        break;
    case 1:
        if (fn_8006862C(120, 0) == 0) {
            lbl_2_bss_1A8248->_44F2 = 4;
            fn_2_94854(11);
            fn_2_9461C(12);
            fn_2_94604(1);
            fn_2_94634(1);
            task->_14 = 60;
            task->_28 = 2;
            fn_2_8F758(24, 2);
        }
        break;
    case 2:
        if (task->_14-- == 0) {
            task->_28 = 3;
        }
        break;
    case 3:
        lbl_2_bss_1A8234->_162604[1][47] = 1;
        task->_14 = 200;
        task->_28 = 4;
        break;
    case 4:
        if (task->_14-- == 0) {
            task->_28 = 5;
        }
        break;
    case 5:
        task->_14 = 8;
        task->_28 = 6;
        break;
    case 6:
        if (task->_14-- == 0) {
            task->_28 = 7;
        }
        break;
    case 7:
        lbl_2_bss_1A8248->_4439 = 0;
        fn_2_92654(8, 0);
        fn_2_90428(9);
        fn_2_92654(9, 11);
        fn_2_46C2C(0, &lbl_2_data_3198[9]._00);
        lbl_2_bss_1A8248->_441A = 0;
        lbl_2_bss_1A8248->_40EE[41]._6 = 0;
        fn_80062890(5);
        task->_14 = 80;
        task->_28 = 8;
        break;
    case 8:
        if (task->_14 == 70) {
            fn_2_46C2C(0, &lbl_2_data_3198[9]._00);
        }
        if (task->_14-- == 0) {
            task->_28 = 9;
        }
        break;
    case 9:
        fn_2_92654(24, 15);
        task->_14 = 200;
        task->_28 = 10;
        break;
    case 10:
        if (task->_14-- == 0) {
            task->_28 = 11;
        }
        break;
    case 11:
        if (fn_80068514(120, 127) == 0) {
            task->_28 = 12;
        }
        break;
    case 12:
        fn_2_94854(11);
        fn_2_9461C(0);
        fn_2_94604(1);
        fn_2_94634(1);
        task->_14 = 60;
        task->_28 = 13;
        break;
    case 13:
        if (task->_14-- == 0) {
            lbl_2_bss_1A8248->_44F2 = 0;
            task->_28 = 14;
        }
        break;
    case 14:
        fn_2_1C41C();
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    task->_16++;
    if (task->_16 == 166) {
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(58);
    } else if (task->_16 == 246) {
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(59);
    } else if (task->_16 == 326) {
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(62);
    } else if (task->_16 == 336) {
    } else if (task->_16 == 516) {
    } else if (task->_16 == 316) {
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(60);
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003E058 size:0x334
void fn_2_3E058(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        fn_2_1C490();
        task->_14 = 30;
        if (lbl_2_bss_1A8248->_4422 >= 5 && lbl_2_bss_1A8248->_4447 == 0 && lbl_2_bss_1A8248->_441C == 5) {
            lbl_2_bss_1A8248->_4447 = 1;
            task->_28 = 1;
        } else {
            task->_28 = 14;
        }
        break;
    case 1:
        if (fn_8006862C(120, 0) == 0) {
            lbl_2_bss_1A8248->_44F2 = 4;
            fn_2_94854(11);
            fn_2_9461C(12);
            fn_2_94604(1);
            fn_2_94634(1);
            task->_14 = 60;
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14-- == 0) {
            task->_28 = 3;
        }
        break;
    case 3:
        lbl_2_bss_1A8234->_162604[1][47] = 1;
        task->_14 = 200;
        task->_28 = 4;
        break;
    case 4:
        if (task->_14-- == 0) {
            task->_28 = 5;
        }
        break;
    case 5:
        task->_14 = 188;
        task->_28 = 6;
        break;
    case 6:
        if (task->_14-- == 0) {
            task->_28 = 7;
        }
        break;
    case 7:
        if (fn_80068514(120, 127) == 0) {
            task->_28 = 12;
        }
        break;
    case 12:
        fn_2_94854(11);
        fn_2_9461C(0);
        fn_2_94604(1);
        fn_2_94634(1);
        task->_14 = 60;
        task->_28 = 13;
        break;
    case 13:
        if (task->_14-- == 0) {
            lbl_2_bss_1A8248->_44F2 = 0;
            task->_28 = 14;
        }
        break;
    case 14:
        fn_2_1C41C();
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    task->_16++;
    if (task->_16 == 166) {
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(58);
    } else if (task->_16 == 246) {
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(59);
    } else if (task->_16 == 326) {
    } else if (task->_16 == 266) {
    } else if (task->_16 == 366) {
    } else if (task->_16 == 316) {
        lbl_2_bss_1A824C->_1976A8 = fn_80062890(60);
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003D5C4 size:0x2B4
void fn_2_3D5C4(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        fn_2_45354();
        lbl_2_bss_1A824C->_197867 = 0;
        task->_14 = 1;
        if (lbl_2_bss_1A824C->_197866 == 0) {
            task->_28 = 6;
        } else {
            task->_28 = 1;
        }
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (lbl_2_bss_1A8248->_44F4 != 0) {
            lbl_2_bss_1A8234->_162604[1][4] = 1;
        } else {
            lbl_2_bss_1A8234->_162604[1][42] = 1;
        }
        task->_14 = 12;
        fn_80062890(56);
        task->_28 = 3;
        break;
    case 3:
        if (task->_14-- == 0) {
            task->_28 = 4;
        }
        break;
    case 4:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x300) {
            if (lbl_2_bss_1A8248->_44F4 != 0) {
                lbl_2_bss_1A8234->_162604[8][4] = 1;
            } else {
                lbl_2_bss_1A8234->_162604[8][42] = 1;
            }
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->_14 = 12;
            task->_28 = 5;
        }
        break;
    case 5:
        lbl_2_bss_1A824C->_197867++;
        if (lbl_2_bss_1A824C->_197866 <= lbl_2_bss_1A824C->_197867) {
            task->_28 = 6;
        } else {
            task->_28 = 2;
        }
        break;
    case 6:
        fn_2_450E4();
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003CD34 size:0x890
void fn_2_3CD34(void) {
    MenuTask0840* task = lbl_803CC1B8;
    MenuTask0840* child;

    switch (task->_28) {
    case 0:
        fn_2_42638();
        fn_2_45E48();
        fn_2_3C7DC();
        lbl_2_bss_1A824C->_197726 = 0;
        lbl_2_bss_1A824C->_19772A = 0;
        lbl_2_bss_1A824C->_197728 = 0;
        lbl_2_bss_1A824C->_19772C = 20;
        task->_14 = 18;
        lbl_2_bss_1A8234->_162604[1][43] = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            if (lbl_2_bss_1A824C->_19789F[lbl_2_bss_1A824C->_197726] == 2) {
                fn_2_50B0C(620, 0);
            } else {
                fn_2_50B0C(lbl_2_bss_1A824C->_197726 + 621, 0);
            }
            task->_28 = 2;
        }
        break;
    case 2:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 == 8 || lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 == 4) {
            lbl_2_bss_1A8234->_162604[6][43] = 1;
            fn_2_46D94(&lbl_2_bss_1A824C->_197728, &lbl_2_bss_1A824C->_19772A, lbl_2_bss_1A824C->_19772C, 6, 9);
            lbl_2_bss_1A824C->_197726 = lbl_2_bss_1A824C->_197728 + lbl_2_bss_1A824C->_19772A;
            if (lbl_2_bss_1A824C->_19789F[lbl_2_bss_1A824C->_197726] == 2) {
                fn_2_50B0C(620, 0);
            } else {
                fn_2_50B0C(lbl_2_bss_1A824C->_197726 + 621, 0);
            }
            task->_28 = 3;
        } else {
            lbl_2_bss_1A824C->_197726 = lbl_2_bss_1A824C->_197728 + lbl_2_bss_1A824C->_19772A;
            if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
                if (lbl_2_bss_1A824C->_19789F[lbl_2_bss_1A824C->_197726] == 2) {
                    fn_2_50B0C(615, 0);
                    sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                } else if (lbl_2_bss_1A824C->_19789F[lbl_2_bss_1A824C->_197726] == 1) {
                    fn_2_50B0C(617, 0);
                    sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                } else if (lbl_2_bss_1A824C->_19789F[lbl_2_bss_1A824C->_197726] == 0 && lbl_2_data_3764[lbl_2_bss_1A824C->_197726][lbl_2_bss_1A8248->_4415] > lbl_2_bss_1A8248->_43BC) {
                    fn_2_50B0C(616, 0);
                    sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                } else if (lbl_2_bss_1A8248->_444B == lbl_2_bss_1A824C->_197726 && lbl_2_data_373C[lbl_2_bss_1A824C->_197726] == 1) {
                    fn_2_50B0C(617, 0);
                    sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                } else {
                    task->_28 = 7;
                }
            } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
                sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                lbl_2_bss_1A8234->_162604[8][43] = 1;
                task->_28 = 9;
            }
        }
        break;
    case 7:
        if (lbl_2_bss_1A8248->_444B == -1 || lbl_2_data_373C[lbl_2_bss_1A824C->_197726] == 0) {
            fn_2_50CC0(612);
        } else {
            fn_2_50CC0(613);
        }
        task->_10 = 0;
        task->_28 = 8;
        break;
    case 8:
        if (task->_10 == 1 && lbl_2_bss_1A824C->_1972B0 == 0) {
            lbl_2_bss_1A8234->_162604[3][43] = 1;
            fn_2_50B0C(618, 0);
            if (lbl_2_data_373C[lbl_2_bss_1A824C->_197726] == 1) {
                lbl_2_bss_1A8234->_162604[3][46] = 1;
                lbl_2_bss_1A8248->_444A = 1;
                lbl_2_bss_1A8248->_444B = lbl_2_bss_1A824C->_197726;
            }
            lbl_2_bss_1A8248->_43C2[lbl_2_bss_1A824C->_197726] = 1;
            fn_2_3C7DC();
            if (lbl_2_bss_1A824C->_197726 == 18) {
                lbl_2_bss_1A824C->_19789E = 1;
            }
            lbl_2_bss_1A824C->_1978F4 = 1;
            lbl_2_bss_1A824C->_1978F5 = lbl_2_bss_1A824C->_197726;
            lbl_2_bss_1A824C->_1976A8 = fn_80062890(12);
            task->_14 = 16;
            task->_28 = 4;
        } else if (task->_10 == 1 && lbl_2_bss_1A824C->_1972B0 == 1) {
            if (lbl_2_bss_1A824C->_19789F[lbl_2_bss_1A824C->_197726] == 2) {
                fn_2_50B0C(620, 0);
            } else {
                fn_2_50B0C(lbl_2_bss_1A824C->_197726 + 621, 0);
            }
            task->_28 = 2;
        }
        break;
    case 3:
        task->_28 = 2;
        break;
    case 4:
        if (task->_14-- == 0) {
            task->_28 = 5;
        }
        break;
    case 5:
        fn_2_46D34(-lbl_2_data_3764[lbl_2_bss_1A824C->_197726][lbl_2_bss_1A8248->_4415]);
        if (lbl_2_bss_1A8248->_43BE > 0) {
            child = fn_800B0A5C_insertQueue(fn_2_3F66C, 2);
            child->_28 = 0;
            task->_10 = 0;
        } else {
            task->_10 = 1;
        }
        task->_28 = 6;
        break;
    case 6:
        if (task->_10 == 1) {
            if (lbl_2_data_373C[lbl_2_bss_1A824C->_197726] == 1) {
                lbl_2_bss_1A8248->_444C = lbl_2_bss_1A8248->_444B;
            }
            task->_28 = 2;
        }
        break;
    case 9:
        fn_2_44014();
        fn_2_43E8C();
        fn_2_432EC();
        fn_2_50CC0(619);
        task->_10 = 0;
        task->_28 = 10;
        break;
    case 10:
        if (task->_10 == 1) {
            lbl_2_bss_1A8234->_162604[8][2] = 1;
            lbl_2_bss_1A8234->_162604[8][3] = 1;
            lbl_2_bss_1A8234->_162604[8][4] = 1;
            lbl_2_bss_1A824C->_1972AC = 0;
            lbl_2_bss_1A824C->_1972B9 = 0;
            lbl_2_bss_1A8234->_162604[8][14] = 1;
            lbl_2_bss_1A8234->_162604[8][61] = 1;
            lbl_2_bss_1A8234->_162604[8][62] = 1;
            child = fn_800B0A5C_insertQueue(fn_2_38538, 2);
            child->_28 = 0;
            task->_10 = 0;
            task->_28 = 11;
        }
        break;
    case 11:
        if (task->_10 == 1) {
            child = fn_800B0A5C_insertQueue(fn_2_3C53C, 2);
            child->_28 = 0;
            task->_10 = 0;
            task->_28 = 12;
        }
        break;
    case 12:
        if (task->_10 == 1) {
            task->_0C->_10 = 1;
            fn_800B0A14_removeQueue();
            task->_28 = 0;
        }
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003C7DC size:0x558
void fn_2_3C7DC(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        lbl_2_bss_1A824C->_19789F[i] = 0;
    }
    fn_8006C6C4();
    for (i = 0; i < 20; i++) {
        if (lbl_2_data_373C[i] == 1) {
            if (i == 5 && lbl_2_bss_1A8248->_442C == 0) {
                lbl_2_bss_1A824C->_19789F[i] = 2;
            } else if (i == 19 && (lbl_2_bss_1A8248->_43C2[0] == 0 ||
                       lbl_2_bss_1A8248->_43C2[1] == 0 ||
                       lbl_2_bss_1A8248->_43C2[2] == 0 ||
                       lbl_2_bss_1A8248->_43C2[3] == 0 ||
                       lbl_2_bss_1A8248->_43C2[4] == 0 ||
                       lbl_2_bss_1A8248->_43C2[5] == 0 ||
                       lbl_2_bss_1A8248->_43C2[6] == 0 ||
                       lbl_2_bss_1A8248->_43C2[7] == 0 ||
                       lbl_2_bss_1A8248->_43C2[8] == 0 ||
                       lbl_2_bss_1A8248->_43C2[9] == 0 ||
                       lbl_2_bss_1A8248->_43C2[10] == 0 ||
                       lbl_2_bss_1A8248->_43C2[11] == 0 ||
                       lbl_2_bss_1A8248->_43C2[12] == 0 ||
                       lbl_2_bss_1A8248->_43C2[13] == 0 ||
                       lbl_2_bss_1A8248->_43C2[14] == 0 ||
                       lbl_2_bss_1A8248->_43C2[15] == 0 ||
                       lbl_2_bss_1A8248->_43C2[16] == 0 ||
                       lbl_2_bss_1A8248->_43C2[17] == 0 ||
                       lbl_2_bss_1A8248->_43C2[18] == 0)) {
                lbl_2_bss_1A824C->_19789F[i] = 2;
            }
        } else if (lbl_2_data_373C[i] == 0 && lbl_2_bss_1A8248->_43C2[i] == 1) {
            lbl_2_bss_1A824C->_19789F[i] = 1;
        } else if (lbl_2_data_373C[i] == 0 && lbl_2_bss_1A8248->_43C2[i] == 0) {
            switch (i) {
            case 6:
                if (fn_8006C79C(0) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 8:
                if (fn_8006C79C(4) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 10:
                if (fn_8006C79C(10) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 12:
                if (fn_8006C79C(6) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 14:
                if (fn_8006C79C(2) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 16:
                if (fn_8006C79C(9) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 7:
                if (fn_8006C79C(1) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 9:
                if (fn_8006C79C(5) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 11:
                if (fn_8006C79C(11) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 13:
                if (fn_8006C79C(17) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 15:
                if (fn_8006C79C(3) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 17:
                if (fn_8006C79C(19) == 0) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            case 18:
                if (lbl_2_bss_1A8248->_4428 != 0x1F) {
                    lbl_2_bss_1A824C->_19789F[i] = 2;
                }
                break;
            }
        }
    }
}

// .text:0x0003C53C size:0x2A0
void fn_2_3C53C(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A824C->_1978F0 = 0;
        fn_2_42490();
        if (lbl_2_bss_1A824C->_1978EF > 0) {
            task->_14 = 1;
            task->_28 = 1;
        } else {
            task->_28 = 7;
        }
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        lbl_2_bss_1A8234->_162604[1][60] = 1;
        fn_80062890(56);
        task->_14 = 10;
        task->_28 = 3;
        break;
    case 3:
        if (task->_14-- == 0) {
            task->_28 = 4;
        }
        break;
    case 4:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            lbl_2_bss_1A8234->_162604[8][60] = 1;
            task->_14 = 10;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->_28 = 5;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
            lbl_2_bss_1A8234->_162604[8][60] = 1;
            task->_14 = 10;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            task->_28 = 5;
        }
        break;
    case 5:
        if (task->_14-- == 0) {
            lbl_2_bss_1A824C->_1978F0++;
            if (lbl_2_bss_1A824C->_1978F0 == lbl_2_bss_1A824C->_1978EF) {
                task->_28 = 7;
            } else {
                task->_28 = 2;
            }
        }
        break;
    case 6:
        break;
    case 7:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003BD88 size:0x2B4
void fn_2_3BD88(void) {
    MenuTask0840* task = lbl_803CC1B8;
    Vec pos;

    switch (task->_28) {
    case 0:
        task->_14 = 1;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            fn_2_72054(0, 19);
            task->_14 = 50;
            task->_28 = 2;
        }
        break;
    case 2:
        if (task->_14 == 12) {
            if (lbl_2_bss_1A8248->_16C2 == 18) {
                fn_2_92654(25, 9);
            } else {
                fn_2_92654(26, 9);
            }
        }
        if (task->_14-- == 0) {
            fn_80062890(11);
        }
        if (fn_2_6AF9C(0) == 1) {
            fn_2_6AF80(0, 0);
            task->_28 = 3;
        }
        break;
    case 3:
        task->_28 = 4;
        break;
    case 4:
        if (lbl_2_bss_1A8248->_16C0 == 48) {
            memcpy(&pos, &lbl_2_data_3198[26]._00, sizeof(Vec));
            PSVECScale(&pos, 0.5f, &pos);
            fn_2_6AABC(0, &pos);
            fn_2_92654(26, 9);
        } else {
            memcpy(&pos, &lbl_2_data_3198[25]._00, sizeof(Vec));
            PSVECScale(&pos, 0.5f, &pos);
            fn_2_6AABC(0, &pos);
            fn_2_92654(25, 9);
        }
        task->_28 = 5;
        break;
    case 5:
        fn_2_72054(0, 20);
        task->_28 = 6;
        break;
    case 6:
        if (fn_2_6AF9C(0) == 1) {
            fn_2_6AF80(0, 0);
            fn_2_72054(0, 4);
            if (lbl_2_bss_1A8248->_16C0 == 48) {
                lbl_2_bss_1A8248->_16C2 = 50;
                lbl_2_bss_1A8248->_16C0 = 50;
            } else {
                lbl_2_bss_1A8248->_16C2 = 18;
                lbl_2_bss_1A8248->_16C0 = 18;
            }
            task->_28 = 7;
        }
        break;
    case 7:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
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
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003AF08 size:0xB38
void fn_2_3AF08(void) {
    MenuTask0840* task = lbl_803CC1B8;
    MenuTask0840* child;
    s32 i;
    s32 j;

    switch (task->_28) {
    case 0:
        for (i = 0; i < 20; i++) {
        }
        j = 0;
        for (i = 0; i < 20; i++) {
            if (lbl_2_bss_1A8248->_43C2[i] == 1 && lbl_2_data_373C[i] == 0) {
                lbl_2_bss_1A824C->_1978B3[j++] = 1;
            }
        }
        changeScene(3, 6);
        task->_28 = 1;
        break;
    case 1:
        if (lbl_8037169C._13 != 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        lbl_2_bss_1A824C->_197730 = 6;
        lbl_2_bss_1A8248->_44F2 = 2;
        lbl_2_bss_1A824C->_197706 = 0;
        lbl_2_bss_1A824C->_197708 = 1;
        lbl_2_bss_1A824C->_19770A = 0;
        lbl_2_bss_1A8234->_162604[1][49] = 1;
        lbl_2_bss_1A8234->_162604[1][52] = 1;
        lbl_8034E978._03 = lbl_2_bss_1A8248->_4415;
        fn_800B0A5C_insertQueue(fn_80053FE8, 0);
        lbl_8034E978._00 = 14;
        setScreen(14);
        changeScene(1, 6);
        task->_28 = 3;
        break;
    case 3:
        task->_14--;
        if (lbl_8037169C._12 != 0) {
            task->_28 = 4;
        }
        break;
    case 4:
        task->_14 = 40;
        lbl_2_bss_1A8234->_162604[1][50] = 1;
        task->_28 = 5;
        break;
    case 5:
        if (task->_14-- <= 0) {
            task->_28 = 6;
        }
        break;
    case 6:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 1) {
            lbl_2_bss_1A824C->_197708--;
            if (lbl_2_bss_1A824C->_197708 == 0 && (lbl_2_bss_1A824C->_19770A == 0 || lbl_2_bss_1A824C->_19770A == 5)) {
                lbl_2_bss_1A824C->_197708 = 4;
            } else if (lbl_2_bss_1A824C->_197708 < 0) {
                lbl_2_bss_1A824C->_197708 = 5;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 2) {
            lbl_2_bss_1A824C->_197708++;
            if (lbl_2_bss_1A824C->_197708 == 5 && (lbl_2_bss_1A824C->_19770A == 0 || lbl_2_bss_1A824C->_19770A == 5)) {
                lbl_2_bss_1A824C->_197708 = 1;
            } else if (lbl_2_bss_1A824C->_197708 > 5) {
                lbl_2_bss_1A824C->_197708 = 0;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 8) {
            lbl_2_bss_1A824C->_19770A--;
            if (lbl_2_bss_1A824C->_19770A == 0 && (lbl_2_bss_1A824C->_197708 == 0 || lbl_2_bss_1A824C->_197708 == 5)) {
                lbl_2_bss_1A824C->_19770A = 4;
            } else if (lbl_2_bss_1A824C->_19770A < 0) {
                lbl_2_bss_1A824C->_19770A = 5;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 4) {
            lbl_2_bss_1A824C->_19770A++;
            if (lbl_2_bss_1A824C->_19770A == 5 && (lbl_2_bss_1A824C->_197708 == 0 || lbl_2_bss_1A824C->_197708 == 5)) {
                lbl_2_bss_1A824C->_19770A = 1;
            } else if (lbl_2_bss_1A824C->_19770A > 5) {
                lbl_2_bss_1A824C->_19770A = 0;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
        lbl_2_bss_1A824C->_197706 = lbl_2_data_296B8[lbl_2_bss_1A824C->_197708 + lbl_2_bss_1A824C->_19770A * 6];
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x40) {
            lbl_2_bss_1A824C->_197730 = 1;
            lbl_2_bss_1A8234->_162604[11][52] = 1;
            lbl_2_bss_1A8234->_162604[8][50] = 1;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->_14 = 50;
            task->_28 = 7;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x20) {
            lbl_2_bss_1A824C->_197730 = 1;
            lbl_2_bss_1A8234->_162604[12][52] = 1;
            lbl_2_bss_1A8234->_162604[8][50] = 1;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->_14 = 50;
            task->_28 = 7;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            if (fn_8006C79C(lbl_800E869C[lbl_2_bss_1A824C->_197706]) == 1) {
                lbl_2_bss_1A824C->_197712 = 0;
                lbl_2_bss_1A824C->_197710 = 0;
                lbl_2_bss_1A824C->_19770C = 0;
                lbl_2_bss_1A824C->_19770E = 0;
                lbl_2_bss_1A824C->_197714 = lbl_8010B438[fn_2_44F14(lbl_800E869C[lbl_2_bss_1A824C->_197706])];
                sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
                task->_28 = 8;
            } else {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            }
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
            lbl_2_bss_1A8234->_162604[8][50] = 1;
            task->_14 = 40;
            task->_28 = 14;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        }
        break;
    case 7:
        if (task->_14-- == 0) {
            task->_28 = 10;
        }
        break;
    case 8:
        child = fn_800B0A5C_insertQueue(fn_2_3A8FC, 2);
        child->_28 = 0;
        task->_10 = 0;
        task->_28 = 9;
        break;
    case 9:
        if (task->_10 == 1) {
            task->_28 = 6;
        }
        break;
    case 10:
        task->_14 = 30;
        setScreen(15);
        lbl_2_bss_1A8234->_162604[1][51] = 1;
        task->_28 = 11;
        break;
    case 11:
        if (task->_14-- <= 0) {
            task->_28 = 12;
        }
        break;
    case 12:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x40) {
            lbl_2_bss_1A824C->_197730 = 6;
            lbl_2_bss_1A8234->_162604[11][52] = 1;
            lbl_2_bss_1A8234->_162604[8][51] = 1;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->_14 = 30;
            setScreen(14);
            task->_28 = 13;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x20) {
            lbl_2_bss_1A824C->_197730 = 6;
            lbl_2_bss_1A8234->_162604[12][52] = 1;
            lbl_2_bss_1A8234->_162604[8][51] = 1;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->_14 = 30;
            setScreen(14);
            task->_28 = 13;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
            lbl_2_bss_1A8234->_162604[8][51] = 1;
            task->_14 = 30;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            task->_28 = 14;
        }
        break;
    case 13:
        if (task->_14-- == 0) {
            task->_28 = 4;
        }
        break;
    case 14:
        if (task->_14-- == 0) {
            changeScene(3, 6);
            task->_28 = 15;
        }
        break;
    case 15:
        if (lbl_8037169C._13 != 0) {
            task->_28 = 16;
        }
        break;
    case 16:
        lbl_2_bss_1A8248->_44F2 = 0;
        lbl_8034E978._26 = 1;
        lbl_2_bss_1A8234->_162604[8][49] = 1;
        lbl_2_bss_1A8234->_162604[8][52] = 1;
        task->_14 = 50;
        changeScene(1, 6);
        task->_28 = 17;
        break;
    case 17:
        task->_14--;
        if (lbl_8037169C._12 != 0) {
            task->_28 = 18;
        }
        break;
    case 18:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x0003A8FC size:0x60C
void fn_2_3A8FC(void) {
    MenuTask0840* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        if (lbl_2_bss_1A8248->_44F4 == 0) {
            lbl_2_bss_1A8234->_162604[1][53] = 1;
        } else {
            lbl_2_bss_1A8234->_162604[1][7] = 1;
        }
        task->_14 = 12;
        task->_28 = 1;
        break;
    case 1:
        if (task->_14-- == 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 1) {
            lbl_2_bss_1A824C->_197712 = lbl_2_bss_1A824C->_197710;
            lbl_2_bss_1A824C->_19770C--;
            if (lbl_2_bss_1A824C->_19770C < 0) {
                lbl_2_bss_1A824C->_19770C = lbl_2_data_122A8[lbl_2_bss_1A824C->_197714][0];
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 2) {
            lbl_2_bss_1A824C->_197712 = lbl_2_bss_1A824C->_197710;
            lbl_2_bss_1A824C->_19770C++;
            if (lbl_2_bss_1A824C->_19770C > lbl_2_data_122A8[lbl_2_bss_1A824C->_197714][0]) {
                lbl_2_bss_1A824C->_19770C = 0;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 8) {
            if (lbl_2_data_122A8[lbl_2_bss_1A824C->_197714][1] != 0) {
                lbl_2_bss_1A824C->_197712 = lbl_2_bss_1A824C->_197710;
                lbl_2_bss_1A824C->_19770E--;
                if (lbl_2_bss_1A824C->_19770E < 0) {
                    lbl_2_bss_1A824C->_19770E = lbl_2_data_122A8[lbl_2_bss_1A824C->_197714][1];
                }
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 4) {
            if (lbl_2_data_122A8[lbl_2_bss_1A824C->_197714][1] != 0) {
                lbl_2_bss_1A824C->_197712 = lbl_2_bss_1A824C->_197710;
                lbl_2_bss_1A824C->_19770E++;
                if (lbl_2_bss_1A824C->_19770E > lbl_2_data_122A8[lbl_2_bss_1A824C->_197714][1]) {
                    lbl_2_bss_1A824C->_19770E = 0;
                }
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        }
        lbl_2_bss_1A824C->_197710 = lbl_2_bss_1A824C->_19770C + lbl_2_bss_1A824C->_19770E * (lbl_2_data_122A8[lbl_2_bss_1A824C->_197714][0] + 1);
        if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 8) || (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 4)) {
            if (lbl_2_data_122A8[lbl_2_bss_1A824C->_197714][1] != 0) {
                if (lbl_2_bss_1A8248->_44F4 == 0) {
                    lbl_2_bss_1A8234->_162604[3][53] = 1;
                } else {
                    lbl_2_bss_1A8234->_162604[3][7] = 1;
                }
                task->_28 = 3;
                break;
            }
        } else if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 1) || (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 2)) {
            if (lbl_2_bss_1A8248->_44F4 == 0) {
                lbl_2_bss_1A8234->_162604[3][53] = 1;
            } else {
                lbl_2_bss_1A8234->_162604[3][7] = 1;
            }
            task->_28 = 3;
            break;
        }
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            if (lbl_2_bss_1A8248->_44F4 == 0) {
                lbl_2_bss_1A8234->_162604[8][53] = 1;
            } else {
                lbl_2_bss_1A8234->_162604[8][7] = 1;
            }
            task->_14 = 12;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->_28 = 4;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
            if (lbl_2_bss_1A8248->_44F4 == 0) {
                lbl_2_bss_1A8234->_162604[8][53] = 1;
            } else {
                lbl_2_bss_1A8234->_162604[8][7] = 1;
            }
            task->_14 = 12;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            task->_28 = 4;
        }
        break;
    case 3:
        task->_28 = 2;
        break;
    case 4:
        if (task->_14-- == 0) {
            task->_28 = 5;
        }
        break;
    case 5:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x000399C0 size:0xF3C
void fn_2_399C0(void) {
    MenuTask0840* task = lbl_803CC1B8;
    GameInitVariables* settings = &g_d_GameSettings;
    MenuTask0840* child;
    s32 i;

    switch (task->_28) {
    case 0:
        fn_2_45204();
        fn_2_45A84();
        for (i = 0; i < 54; i++) {
            if (lbl_2_bss_1A8248->_444D[i] == 1) {
                lbl_2_bss_1A824C->_1978F8 = 1;
            }
            if (lbl_2_bss_1A8248->_44B9[i] == 1) {
                lbl_2_bss_1A824C->_1978F9 = 1;
            }
        }
        if (lbl_2_bss_1A824C->_1978F7 == 2) {
            task->_28 = 17;
        } else {
            changeScene(3, 6);
            task->_28 = 1;
        }
        break;
    case 1:
        if (lbl_8037169C._13 != 0) {
            task->_28 = 2;
        }
        break;
    case 2:
        lbl_2_bss_1A8248->_44F2 = 2;
        lbl_2_bss_1A824C->_1978F6 = 0;
        lbl_2_bss_1A824C->_197706 = 0;
        lbl_2_bss_1A824C->_197708 = 1;
        lbl_2_bss_1A824C->_19770A = 0;
        if (lbl_2_bss_1A8248->_44F4 == 0) {
            lbl_2_bss_1A8234->_162604[1][55] = 1;
            lbl_2_bss_1A8234->_162604[1][56] = 1;
        } else {
            lbl_2_bss_1A8234->_162604[1][8] = 1;
            lbl_2_bss_1A8234->_162604[1][9] = 1;
        }
        if (lbl_2_bss_1A824C->_1978F7 == 0) {
            lbl_2_bss_1A824C->_1978F6 = 0;
        } else {
            lbl_2_bss_1A824C->_1978F6 = 1;
        }
        changeScene(1, 6);
        task->_28 = 3;
        break;
    case 3:
        task->_14--;
        if (lbl_8037169C._12 != 0) {
            task->_28 = 4;
        }
        break;
    case 4:
        task->_14 = 40;
        if (lbl_2_bss_1A824C->_1978F7 == 0) {
            lbl_8034E978._03 = lbl_2_bss_1A8248->_4415;
            fn_800B0A5C_insertQueue(fn_80053FE8, 0);
            if (lbl_2_bss_1A824C->_1978F8 == 1) {
                if (lbl_2_bss_1A824C->_197843 == 0) {
                    if (settings->someChallengeModeFlag == 1) {
                        setScreen(40);
                    } else {
                        setScreen(39);
                    }
                }
                fn_80062890(57);
            } else if (lbl_2_bss_1A824C->_197843 == 0) {
                setScreen(41);
            } else if (lbl_2_bss_1A824C->_197843 == 1) {
                setScreen(42);
            } else {
                setScreen(42);
            }
            lbl_2_bss_1A824C->_1978F6 = 0;
        } else {
            lbl_8034E978._03 = lbl_2_bss_1A8248->_4415;
            fn_800B0A5C_insertQueue(fn_80053FE8, 0);
            if (lbl_2_bss_1A824C->_1978F9 == 1) {
                setScreen(43);
                fn_80062890(63);
            } else {
                setScreen(44);
            }
            if (lbl_2_bss_1A8248->_44F4 == 0) {
                lbl_2_bss_1A8234->_162604[1][59] = 1;
                lbl_2_bss_1A8234->_162604[3][56] = 1;
            } else {
                lbl_2_bss_1A8234->_162604[1][12] = 1;
                lbl_2_bss_1A8234->_162604[3][9] = 1;
            }
            lbl_2_bss_1A824C->_1978F6 = 1;
        }
        if (lbl_2_bss_1A8248->_44F4 == 0) {
            lbl_2_bss_1A8234->_162604[1][58] = 1;
        } else {
            lbl_2_bss_1A8234->_162604[1][11] = 1;
        }
        task->_28 = 5;
        break;
    case 5:
        if (task->_14-- <= 0) {
            if (lbl_2_bss_1A824C->_1978F7 == 0) {
                task->_28 = 6;
            } else {
                task->_28 = 8;
            }
        }
        break;
    case 6:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            task->_14 = 10;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->_28 = 7;
        }
        break;
    case 7:
        if (task->_14-- == 0) {
            lbl_2_bss_1A824C->_1978F6 = 1;
            if (lbl_2_bss_1A824C->_1978F9 == 1) {
                setScreen(43);
                fn_80062890(63);
            } else {
                setScreen(44);
            }
            if (lbl_2_bss_1A8248->_44F4 == 0) {
                lbl_2_bss_1A8234->_162604[1][59] = 1;
                lbl_2_bss_1A8234->_162604[3][56] = 1;
                lbl_2_bss_1A8234->_162604[3][58] = 1;
            } else {
                lbl_2_bss_1A8234->_162604[1][12] = 1;
                lbl_2_bss_1A8234->_162604[3][9] = 1;
                lbl_2_bss_1A8234->_162604[3][11] = 1;
            }
            task->_28 = 8;
        }
        break;
    case 8:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 1) {
            lbl_2_bss_1A824C->_197708--;
            if (lbl_2_bss_1A824C->_197708 == 0 && lbl_2_bss_1A824C->_19770A == 0) {
                lbl_2_bss_1A824C->_197708 = 5;
            } else if (lbl_2_bss_1A824C->_197708 == 0 && lbl_2_bss_1A824C->_19770A == 5) {
                lbl_2_bss_1A824C->_197708 = 4;
            } else if (lbl_2_bss_1A824C->_197708 < 0) {
                lbl_2_bss_1A824C->_197708 = 5;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 2) {
            lbl_2_bss_1A824C->_197708++;
            if (lbl_2_bss_1A824C->_197708 == 6 && lbl_2_bss_1A824C->_19770A == 0) {
                lbl_2_bss_1A824C->_197708 = 1;
            } else if (lbl_2_bss_1A824C->_197708 == 5 && lbl_2_bss_1A824C->_19770A == 5) {
                lbl_2_bss_1A824C->_197708 = 1;
            } else if (lbl_2_bss_1A824C->_197708 > 5) {
                lbl_2_bss_1A824C->_197708 = 0;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 8) {
            lbl_2_bss_1A824C->_19770A--;
            if (lbl_2_bss_1A824C->_19770A == 0 && lbl_2_bss_1A824C->_197708 == 0) {
                lbl_2_bss_1A824C->_19770A = 4;
            } else if (lbl_2_bss_1A824C->_19770A < 0 && lbl_2_bss_1A824C->_197708 == 5) {
                lbl_2_bss_1A824C->_19770A = 4;
            } else if (lbl_2_bss_1A824C->_19770A < 0) {
                lbl_2_bss_1A824C->_19770A = 5;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 4) {
            lbl_2_bss_1A824C->_19770A++;
            if (lbl_2_bss_1A824C->_19770A == 5 && lbl_2_bss_1A824C->_197708 == 0) {
                lbl_2_bss_1A824C->_19770A = 1;
            } else if (lbl_2_bss_1A824C->_19770A == 5 && lbl_2_bss_1A824C->_197708 == 5) {
                lbl_2_bss_1A824C->_19770A = 0;
            } else if (lbl_2_bss_1A824C->_19770A > 5) {
                lbl_2_bss_1A824C->_19770A = 0;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
        lbl_2_bss_1A824C->_197706 = lbl_2_data_29700[lbl_2_bss_1A824C->_197708 + lbl_2_bss_1A824C->_19770A * 6];
        if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 8) || (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 4) || (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 1) || (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 2)) {
            if (lbl_2_bss_1A8248->_44F4 == 0) {
                lbl_2_bss_1A8234->_162604[6][59] = 1;
            } else {
                lbl_2_bss_1A8234->_162604[6][12] = 1;
            }
            task->_28 = 9;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            if (lbl_2_bss_1A824C->_19770A == 0 && lbl_2_bss_1A824C->_197708 == 5) {
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                task->_28 = 12;
            } else if (fn_8006C79C(lbl_800E869C[lbl_2_bss_1A824C->_197706]) == 1) {
                lbl_2_bss_1A824C->_197712 = 0;
                lbl_2_bss_1A824C->_197710 = 0;
                lbl_2_bss_1A824C->_19770C = 0;
                lbl_2_bss_1A824C->_19770E = 0;
                lbl_2_bss_1A824C->_197714 = lbl_8010B438[fn_2_44F14(lbl_800E869C[lbl_2_bss_1A824C->_197706])];
                sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
                task->_28 = 10;
            } else {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            }
        } else if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) && (lbl_2_bss_1A824C->_19770A != 0 || lbl_2_bss_1A824C->_197708 != 5)) {
            lbl_2_bss_1A824C->_19770A = 0;
            lbl_2_bss_1A824C->_197708 = 5;
            lbl_2_bss_1A824C->_197706 = lbl_2_data_29700[lbl_2_bss_1A824C->_197708 + lbl_2_bss_1A824C->_19770A * 6];
            if (lbl_2_bss_1A8248->_44F4 == 0) {
                lbl_2_bss_1A8234->_162604[6][59] = 1;
            } else {
                lbl_2_bss_1A8234->_162604[6][12] = 1;
            }
            task->_28 = 9;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        }
        break;
    case 9:
        task->_28 = 8;
        break;
    case 10:
        child = fn_800B0A5C_insertQueue(fn_2_3A8FC, 2);
        child->_28 = 0;
        task->_10 = 0;
        task->_28 = 11;
        break;
    case 11:
        if (task->_10 == 1) {
            task->_28 = 8;
        }
        break;
    case 12:
        if (lbl_2_bss_1A8248->_44F4 == 0) {
            lbl_2_bss_1A8234->_162604[8][59] = 1;
            lbl_2_bss_1A8234->_162604[8][58] = 1;
            task->_14 = 40;
            task->_28 = 13;
        } else {
            task->_14 = 10;
            task->_28 = 18;
        }
        break;
    case 13:
        if (task->_14-- == 0) {
            changeScene(3, 6);
            task->_28 = 14;
        }
        break;
    case 14:
        if (lbl_8037169C._13 != 0) {
            task->_28 = 15;
        }
        break;
    case 15:
        lbl_8034E978._26 = 1;
        lbl_2_bss_1A8248->_44F2 = 0;
        if (lbl_2_bss_1A8248->_44F4 == 0) {
            lbl_2_bss_1A8234->_162604[8][55] = 1;
            lbl_2_bss_1A8234->_162604[8][56] = 1;
            task->_14 = 50;
        } else {
            task->_14 = 1;
        }
        changeScene(1, 6);
        fn_2_72054(0, 4);
        task->_28 = 16;
        break;
    case 16:
        task->_14--;
        if (lbl_8037169C._12 != 0) {
            task->_28 = 17;
        }
        break;
    case 17:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    case 18:
        if (task->_14-- == 0) {
            task->_28 = 17;
        }
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask0840*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}
