#include "menus/rep_0A08.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "musyx/musyx.h"

typedef struct MenuSaveSlot0A08 {
    /* 0x0000 */ u8 _0000[0xAF8];
    /* 0x0AF8 */ union {
        /* 0x0AF8 */ u8 _0AF8[0xB10];
        struct {
            /* 0x0AF8 */ u8 _0AF8_pad[0x1606 - 0xAF8];
            /* 0x1606 */ s8 _1606;
        };
    };
    /* 0x1608 */ u8 _1608[0x441B - 0x1608];
    /* 0x441B */ u8 _441B;
    /* 0x441C */ u8 _441C[0x4508 - 0x441C];
} MenuSaveSlot0A08; // size: 0x4508

extern struct {
    /* 0x0000 */ MenuSaveSlot0A08 _0000[3];
    /* 0xCF18 */ u8 _CF18[0xCF5E - 0xCF18];
    /* 0xCF5E */ u8 _CF5E[3];
    /* 0xCF61 */ u8 _CF61[0xCF64 - 0xCF61];
} lbl_80354768;
extern u8 lbl_800EFBA4[0x10];
extern struct {
    /* 0x00 */ u8 _00[0xF6];
    /* 0xF6 */ u8 _F6;
} lbl_80361B20;
// One character's stats, as in inMemRoster and at the start of lbl_8034E9A0
typedef struct CharEntry0A08 {
    /* 0x00 */ u8 _00[0x1E];
    /* 0x1E */ u8 _1E[2];
    /* 0x20 */ u32 _20;
    /* 0x24 */ s16 CharID;
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
    /* 0x28 */ u8 _28[2];
    /* 0x2A */ u8 _2A[2];
    /* 0x2C */ u8 _2C;
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E;
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u8 _30;
    /* 0x31 */ u8 _31;
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34;
    /* 0x35 */ u8 _35[2];
    /* 0x37 */ u8 _37[4];
    /* 0x3B */ u8 _3B[0x36];
    /* 0x71 */ u8 _71;
    /* 0x72 */ u8 _72[2];
    /* 0x74 */ u16 _74[21];
    /* 0x9E */ u8 _9E[2];
} CharEntry0A08; // size: 0xA0

typedef struct Slot0A08 {
    /* 0x0 */ s8 _0;
    /* 0x1 */ s8 _1;
    /* 0x2 */ s8 _2;
    /* 0x3 */ s8 _3;
} Slot0A08;

extern CharEntry0A08 inMemRoster[2][9];
extern Slot0A08 lbl_80354720[2][9];
extern struct {
    /* 0x00 */ u8 _00[0x2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ s8 _14[2][9];
} lbl_803C6724;
extern struct {
    /* 0x0000 */ u8 _0000[0x40B8];
    /* 0x40B8 */ struct {
        /* 0x0 */ s16 _0;
        /* 0x2 */ u8 _2;
        /* 0x3 */ s8 _3;
        /* 0x4 */ u8 _4;
        /* 0x5 */ u8 _5;
    } _40B8[9];
    /* 0x40EE */ u8 _40EE[0x43BC - 0x40EE];
    /* 0x43BC */ s16 _43BC;
    /* 0x43BE */ u8 _43BE[0x441D - 0x43BE];
    /* 0x441D */ u8 _441D;
} starMissionCompletionTracker;
extern struct {
    /* 0x0000 */ CharEntry0A08 _0000[6][9];
    /* 0x21C0 */ u8 _21C0[0x46E0 - 0x21C0];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x46F0 - 0x46E8];
    /* 0x46F0 */ s32 _46F0;
    /* 0x46F4 */ s32 _46F4;
    /* 0x46F8 */ u8 _46F8[0x4711 - 0x46F8];
    /* 0x4711 */ u8 _4711;
    /* 0x4712 */ u8 _4712[0x472B - 0x4712];
    /* 0x472B */ u8 _472B;
    /* 0x472C */ u16 _472C;
    /* 0x472E */ u16 _472E;
    /* 0x4730 */ u16 _4730;
    /* 0x4732 */ u8 _4732[0x4754 - 0x4732];
    /* 0x4754 */ u8 _4754;
    /* 0x4755 */ u8 _4755;
    /* 0x4756 */ u8 _4756;
    /* 0x4757 */ u8 _4757[0x48AF - 0x4757];
    /* 0x48AF */ u8 _48AF;
} lbl_8034E9A0;
extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x3 - 0x1];
    /* 0x03 */ u8 _03;
    /* 0x04 */ u8 _04[0x8 - 0x4];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A[0x26 - 0xA];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} lbl_8034E978;
extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} lbl_800FEF70[];
extern struct {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _6;
} *lbl_803CBBCC;
extern struct {
    /* 0x00 */ u8 _00[0x50];
    /* 0x50 */ s32 _50;
    /* 0x54 */ s32 _54;
} lbl_2_bss_F410;
extern struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06;
    /* 0x07 */ u8 _07[6];
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ s8 _0F;
    /* 0x10 */ s8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ s8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
} lbl_2_bss_33FBCC;

typedef struct MenuTask0A08 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
} MenuTask0A08;

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800678CC(s32 team);
extern void fn_80041150(s32 arg0, u8 arg1);
extern void fn_80062A74(void);
extern void fn_800AD054(s32 arg0, s32 arg1);
extern void fn_80021410(void);
extern void fn_800ACFB0(s32 arg0);
extern struct {
    /* 0x00 */ u8 _00[0x36];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
    /* 0x39 */ u8 _39;
} lbl_803C5EA4;
extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;
extern struct {
    /* 0x00 */ u8 _00[0x98];
    /* 0x98 */ s32 _98;
} lbl_800EF808;
extern void fn_8004A34C(void* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 fn_8004CA6C(u16 buttons);
extern void fn_8004CC2C(void);
extern void fn_8003BF54(int, int, int, int, int, int, int, u8, int);
extern void fn_2_460EC(s32 arg0);
extern void* lbl_803CC1B8;
extern void fn_800B0A14_removeQueue(void);
extern u8 lbl_2_bss_33FB4C[0x80];
extern void fn_80053FE8(void);
extern void fn_2_82DE8(void);
extern void fn_2_89F70(void);
extern void fn_2_8ABFC(void);

#define SET_SCREEN(id)                                                                                                 \
    lbl_8034E978._00 = (id);                                                                                           \
    lbl_8034E978._09 = lbl_8034E978._08;                                                                               \
    lbl_8034E978._08 = lbl_800FEF70[(id)]._08

extern struct {
    /* 0x00 */ u8 _00[0x45];
    /* 0x45 */ u8 _45;
    /* 0x46 */ u8 _46;
    /* 0x47 */ u8 _47;
    /* 0x48 */ u8 _48[0x52 - 0x48];
    /* 0x52 */ u8 _52;
} lbl_803C50E8;
extern struct {
    /* 0x00 */ u8 _00[0x30];
    /* 0x30 */ s16 _30;
    /* 0x32 */ s16 _32;
} lbl_800E877C;

typedef struct AramEntry0A08 {
    /* 0x0 */ u32 _0[4];
} AramEntry0A08; // size: 0x10

extern int fn_80035838(AramEntry0A08* entry, int count);
extern void fn_80035B50(int arg);
extern void fn_80042D38(s32 arg);
extern void changeScene(u8, s16);

AramEntry0A08 lbl_2_data_1F884 = { 0x0000040B, 0x400B2CB8, 0x18E3F000, 0x00053454 };
AramEntry0A08 lbl_2_data_1F894 = { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 };

u16 lbl_2_bss_9E08;

// .text:0x00053408 size:0x1A8
void fn_2_53408(void) {
    switch (lbl_2_bss_33FBCC._00) {
    case 0:
        if (fn_80035838(&lbl_2_data_1F884, 8) != 0) {
            lbl_2_bss_33FBCC._0D = 0;
            if (lbl_803CBBCC->_6 == 0x10) {
                lbl_2_bss_33FBCC._00 = 1;
                lbl_8034E9A0._4756 = 1;
            } else {
                lbl_2_bss_33FBCC._00 = 2;
            }
            if (lbl_800E877C._30 == 10 && lbl_803C50E8._47 != 0) {
                changeScene(6, 6);
                changeScene(3, 6);
                fn_80035B50(8);
                lbl_800E877C._30 = 9;
                lbl_800E877C._32 = 0;
                fn_80042D38(5);
                lbl_2_bss_33FBCC._00 = 0;
                lbl_2_bss_F410._50 = 0;
                lbl_2_bss_9E08 = 0;
                lbl_803C50E8._52 = 0;
            }
        }
        break;
    case 1:
        if (fn_80035838(&lbl_2_data_1F894, 6) != 0) {
            lbl_2_bss_33FBCC._00 = 2;
        }
        break;
    case 2:
        fn_2_52648(0x2000);
        lbl_2_bss_33FBCC._00++;
        break;
    case 3:
        break;
    }
}

// .text:0x00052690 size:0xD78
void fn_2_52690(void) {
    s16 result;

    switch (lbl_2_bss_9E08) {
    case 0:
        changeScene(1, 6);
        lbl_2_bss_33FBCC._0F = -1;
        lbl_2_bss_33FBCC._1A = 0;
        lbl_2_bss_F410._54 = 0;
        lbl_2_bss_F410._50 = 0;
        lbl_2_bss_9E08 = 1;
        break;
    case 1:
        fn_2_52198();
        lbl_803C5EA4._36 = 1;
        lbl_803C5EA4._37 = lbl_803C5EA4._38;
        lbl_803C5EA4._38 = 0;
        lbl_2_bss_33FBCC._17 = 0x49;
        if (lbl_8034E9A0._4756 == 1) {
            if (lbl_803C50E8._47 != 0) {
                lbl_2_bss_9E08 = 15;
                break;
            }
            lbl_2_bss_9E08 = 2;
        } else {
            lbl_2_bss_9E08 = 5;
        }
        lbl_2_bss_F410._54 = lbl_80361B20._F6;
        break;
    case 2:
        if (lbl_800E877C._30 == 8 || lbl_800E877C._30 == 9) {
            if (lbl_800E877C._30 == 9) {
                lbl_803C50E8._52 = 3;
            } else {
                lbl_803C50E8._52 = 1;
            }
            fn_8003BF54(0, 0, 0, 0, 1, 1, 2, lbl_80361B20._F6, 0);
            ((MenuTask0A08*)lbl_803CC1B8)->_10 = 0;
            lbl_2_bss_9E08 = 9;
        } else {
            fn_8004A34C(&lbl_803C50E8, 0, 0x34, 0, 0);
            lbl_803C50E8._52 = 2;
            lbl_2_bss_9E08 = 3;
        }
        break;
    case 3:
        switch (lbl_803C50E8._45) {
        case 2:
            if (lbl_800E877C._30 == 9) {
                lbl_803C5EA4._39 = 1;
            } else if (lbl_800E877C._30 == 10) {
                starMissionCompletionTracker._43BC = 0;
            }
            fn_8003BF54(0, 0, 0, 0, 1, 1, 2, lbl_80361B20._F6, 0);
            ((MenuTask0A08*)lbl_803CC1B8)->_10 = 0;
            lbl_2_bss_9E08 = 9;
            break;
        case 3:
        case 4:
            if (lbl_800E877C._30 == 10) {
                fn_8004A34C(&lbl_803C50E8, 0, 0x35, 0, 0);
                lbl_2_bss_9E08 = 4;
            } else {
                lbl_2_bss_33FBCC._17 = 0x4A;
                lbl_2_bss_33FBCC._0F = -1;
                lbl_2_bss_9E08 = 14;
            }
            break;
        }
        break;
    case 4:
        switch (lbl_803C50E8._45) {
        case 2:
            lbl_2_bss_33FBCC._17 = 0x4A;
            lbl_2_bss_33FBCC._0F = -1;
            lbl_2_bss_9E08 = 10;
            break;
        case 3:
        case 4:
            lbl_2_bss_9E08 = 2;
            break;
        }
        break;
    case 5:
        if (lbl_2_bss_33FBCC._17 != 0x49 && lbl_2_bss_33FBCC._21 == 0 && lbl_2_bss_33FBCC._19 == 0) {
            fn_2_52260();
        }
        break;
    case 6:
        fn_2_520A4();
        break;
    case 7:
        lbl_2_bss_9E08 = 8;
        break;
    case 8:
        switch (fn_8004CA6C(lbl_8034E9A0._472E)) {
        case 0:
            break;
        case 1:
            fn_8004CC2C();
            break;
        case 3:
            if (lbl_2_bss_33FBCC._0F != -1) {
                fn_8003BF54(0, 0, 0, 0, 1, 1, 2, lbl_8034E9A0._4754, 2);
            } else {
                fn_8003BF54(0, 0, 0, 0, 1, 1, 2, lbl_8034E9A0._4754, 0);
            }
            ((MenuTask0A08*)lbl_803CC1B8)->_10 = 0;
            lbl_2_bss_9E08 = 9;
            break;
        case 2:
            fn_8004CC2C();
            break;
        case 4:
            lbl_2_bss_33FBCC._17 = 0x4E;
            lbl_2_bss_33FBCC._10 = lbl_2_bss_33FBCC._0F;
            lbl_2_bss_33FBCC._0F = -1;
            lbl_2_bss_9E08 = 5;
            break;
        }
        break;
    case 9:
        result = ((MenuTask0A08*)lbl_803CC1B8)->_10;
        if (result != 0) {
            if (lbl_8034E9A0._4756 == 1) {
                switch (result) {
                case 1:
                    if (lbl_2_bss_33FBCC._0F != -1) {
                        lbl_2_bss_33FBCC._17 = 0x4E;
                        lbl_2_bss_33FBCC._22 = 0x52;
                        lbl_2_bss_33FBCC._10 = lbl_2_bss_33FBCC._0F;
                        lbl_2_bss_33FBCC._0F = -1;
                        lbl_2_bss_9E08 = 5;
                    } else {
                        lbl_2_bss_33FBCC._17 = 0x4B;
                        lbl_2_bss_33FBCC._22 = 0x52;
                        lbl_2_bss_33FBCC._16 = 100;
                        lbl_2_bss_9E08 = 15;
                    }
                    break;
                case 11:
                    if (lbl_2_bss_33FBCC._0F != -1) {
                        lbl_2_bss_33FBCC._22 = 0x52;
                        lbl_2_bss_9E08 = 5;
                    } else {
                        if (lbl_800E877C._30 == 9) {
                            fn_8004A34C(&lbl_803C50E8, 0, 0x24, 0, 0);
                        } else if (lbl_800E877C._30 == 10) {
                            lbl_2_bss_33FBCC._17 = 0x4A;
                            lbl_2_bss_9E08 = 15;
                            break;
                        } else {
                            fn_8004A34C(&lbl_803C50E8, 0, 0x1C, 0, 0);
                        }
                        lbl_2_bss_9E08 = 17;
                    }
                    break;
                default:
                    if (lbl_803C50E8._52 == 2) {
                        lbl_2_bss_9E08 = 2;
                    } else if (lbl_803C50E8._52 == 4) {
                        lbl_2_bss_33FBCC._0E = 1;
                        lbl_2_bss_9E08 = 5;
                    } else if (lbl_803C50E8._52 == 1 || lbl_803C50E8._52 == 3) {
                        lbl_2_bss_33FBCC._17 = 0x4B;
                        lbl_2_bss_33FBCC._16 = 100;
                        lbl_2_bss_9E08 = 15;
                    } else {
                        lbl_2_bss_9E08 = 5;
                    }
                    lbl_2_bss_33FBCC._22 = 0x52;
                    break;
                }
            } else {
                switch (result) {
                case 1:
                    if (lbl_2_bss_33FBCC._0F != -1) {
                        if (lbl_2_bss_33FBCC._15 == 4) {
                            lbl_2_bss_33FBCC._22 = 0x52;
                            lbl_2_bss_33FBCC._0E = 1;
                        } else {
                            lbl_2_bss_33FBCC._17 = 0x4F;
                            lbl_2_bss_33FBCC._22 = 0x52;
                        }
                        lbl_2_bss_33FBCC._10 = lbl_2_bss_33FBCC._0F;
                        lbl_2_bss_33FBCC._0F = -1;
                        lbl_2_bss_9E08 = 5;
                    } else if (lbl_2_bss_33FBCC._06 == 1) {
                        lbl_2_bss_33FBCC._17 = 0x4A;
                        lbl_2_bss_33FBCC._22 = 0x52;
                        lbl_8034E978._26 = 1;
                        lbl_2_bss_33FBCC._0E = 1;
                        lbl_2_bss_9E08 = 10;
                    } else {
                        lbl_2_bss_33FBCC._17 = 0x4A;
                        lbl_2_bss_33FBCC._22 = 0x52;
                        lbl_2_bss_33FBCC._0E = 1;
                        lbl_2_bss_9E08 = 10;
                        lbl_2_bss_33FBCC._02 = 0;
                    }
                    break;
                default:
                    lbl_2_bss_33FBCC._22 = 0x52;
                    if (lbl_2_bss_33FBCC._0F != -1) {
                        lbl_2_bss_33FBCC._17 = 0x4E;
                        lbl_2_bss_33FBCC._10 = lbl_2_bss_33FBCC._0F;
                        lbl_2_bss_33FBCC._0F = -1;
                    }
                    lbl_2_bss_33FBCC._0E = 1;
                    lbl_2_bss_9E08 = 5;
                    break;
                }
            }
        }
        break;
    case 10:
        if (lbl_2_bss_33FBCC._19 != 1 && lbl_8037169C._13 != 0) {
            lbl_2_bss_9E08 = 11;
        }
        break;
    case 11:
        if (lbl_8034E9A0._4756 == 0) {
            fn_80035B50(8);
            switch (lbl_2_bss_33FBCC._06) {
            case 0:
                fn_80042D38(12);
                break;
            case 1:
                fn_80062A74();
                fn_80035B50(15);
                fn_80035B50(18);
                fn_80035B50(9);
                fn_80035B50(6);
                fn_800AD054(lbl_8034E9A0._46F0, lbl_8034E9A0._46F4);
                fn_80021410();
                fn_800ACFB0(lbl_800EF808._98);
                fn_80042D38(16);
                break;
            case 2:
                break;
            }
            lbl_2_bss_33FBCC._06 = 0;
            lbl_800E877C._30 = 1;
            lbl_800E877C._32 = 0;
        } else {
            fn_80035B50(6);
            fn_80035B50(8);
            if (lbl_800E877C._30 == 8) {
                fn_80042D38(16);
            } else {
                fn_80042D38(5);
            }
            lbl_8034E978._26 = 1;
        }
        lbl_2_bss_33FBCC._00 = 0;
        lbl_2_bss_F410._50 = 0;
        lbl_2_bss_9E08 = 0;
        lbl_803C50E8._52 = 0;
        fn_800B0A14_removeQueue();
        break;
    case 14:
        if (lbl_2_bss_33FBCC._19 != 1 && lbl_8037169C._13 != 0) {
            lbl_2_bss_9E08 = 13;
        }
        break;
    case 13:
        lbl_8034E978._26 = 1;
        lbl_8034E9A0._48AF = 1;
        if (lbl_8034E9A0._4756 == 0) {
            fn_80035B50(8);
            fn_80042D38(5);
            lbl_800E877C._30 = 1;
            lbl_800E877C._32 = 0;
        } else {
            fn_80035B50(6);
            fn_80035B50(8);
            if (lbl_800E877C._30 != 10) {
                lbl_800E877C._30 = 8;
                lbl_800E877C._32 = 0;
                fn_80042D38(16);
            } else {
                lbl_800E877C._30 = 9;
                lbl_800E877C._32 = 0;
                fn_80042D38(5);
            }
        }
        lbl_2_bss_33FBCC._00 = 0;
        lbl_2_bss_F410._50 = 0;
        lbl_2_bss_9E08 = 0;
        lbl_803C50E8._52 = 0;
        fn_800B0A14_removeQueue();
        break;
    case 12:
        if (lbl_803C50E8._45 != 0) {
            switch (lbl_803C50E8._45) {
            case 2:
            case 3:
                lbl_2_bss_9E08 = 5;
                break;
            }
        }
        break;
    case 15:
        if (lbl_2_bss_33FBCC._19 != 1) {
            if (lbl_2_bss_33FBCC._16 > 0) {
                lbl_2_bss_33FBCC._16--;
            } else {
                lbl_2_bss_33FBCC._16 = 0;
                lbl_2_bss_33FBCC._17 = 0x4A;
                lbl_2_bss_9E08 = 10;
            }
        }
        break;
    case 16:
        switch (lbl_803C50E8._45) {
        case 1:
        case 2:
            fn_80041150(2, lbl_8034E9A0._4754);
            lbl_2_bss_33FBCC._17 = 0x4A;
            lbl_2_bss_33FBCC._22 = 0x52;
            lbl_2_bss_33FBCC._0E = 1;
            lbl_2_bss_9E08 = 10;
            break;
        }
        break;
    case 17:
        switch (lbl_803C50E8._45) {
        case 2:
            lbl_2_bss_33FBCC._17 = 0x4A;
            lbl_2_bss_9E08 = 15;
            break;
        case 3:
        case 4:
            fn_8003BF54(0, 0, 0, 0, 1, 1, 2, lbl_80361B20._F6, 0);
            ((MenuTask0A08*)lbl_803CC1B8)->_10 = 0;
            lbl_2_bss_9E08 = 9;
            break;
        }
        break;
    }
}

// .text:0x0005268C size:0x4
void fn_2_5268C(void) {
}

// .text:0x00052648 size:0x44
void fn_2_52648(s32 priority) {
    fn_800B0A5C_insertQueue(fn_2_52690, priority);
    lbl_8034E9A0._472B = g_d_GameSettings._06;
}

// .text:0x00052260 size:0x3E8
void fn_2_52260(void) {
    s32 sel;
    u16 buttons[3];

    sel = lbl_2_bss_F410._50;
    memset(buttons, 0, sizeof(buttons));
    buttons[0] = lbl_8034E9A0._472C;
    buttons[1] = lbl_8034E9A0._472E;
    buttons[2] = lbl_8034E9A0._4730;
    if (buttons[1] & 8) {
        if (--sel < 0) {
            sel = 2;
        }
        if (lbl_2_bss_33FBCC._0F != -1 && sel == lbl_8034E9A0._4754) {
            if (--sel < 0) {
                sel = 2;
            }
        }
        lbl_2_bss_33FBCC._17 = 0x4C;
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    } else if (buttons[1] & 4) {
        if (++sel == 3) {
            sel = 0;
        }
        if (lbl_2_bss_33FBCC._0F != -1 && sel == lbl_8034E9A0._4754) {
            if (++sel == 3) {
                sel = 0;
            }
        }
        lbl_2_bss_33FBCC._17 = 0x4C;
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    } else if (buttons[1] & 0x100) {
        lbl_8034E9A0._4754 = sel;
        lbl_80361B20._F6 = sel;
        if (lbl_8034E9A0._4756 == 0 && lbl_2_bss_33FBCC._0F == -1) {
            lbl_2_bss_33FBCC._02 = 0;
            lbl_2_bss_F410._54 = 0;
            lbl_2_bss_9E08 = 6;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        } else if (lbl_8034E9A0._4756 == 1 || lbl_2_bss_33FBCC._0F != -1) {
            if (lbl_2_bss_33FBCC._0F != -1) {
                if (lbl_80354768._CF5E[sel] != 0) {
                    fn_8004A34C(lbl_2_bss_33FB4C, 0, 0x29, 0, 0);
                    sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                    lbl_2_bss_9E08 = 7;
                } else {
                    fn_8003BF54(0, 0, 0, 0, 1, 1, 2, sel, 2);
                    sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                    ((MenuTask0A08*)lbl_803CC1B8)->_10 = 0;
                    lbl_2_bss_9E08 = 9;
                }
            } else {
                fn_8004A34C(lbl_2_bss_33FB4C, 0, 0x1B, 0, 0);
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                lbl_2_bss_9E08 = 7;
            }
        }
    } else if (buttons[1] & 0x200) {
        if (lbl_2_bss_33FBCC._0F != -1) {
            lbl_2_bss_33FBCC._10 = lbl_2_bss_33FBCC._0F;
            lbl_2_bss_33FBCC._0F = -1;
            lbl_2_bss_9E08 = 6;
            lbl_2_bss_33FBCC._17 = 0x4E;
            lbl_803C50E8._52 = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        } else {
            lbl_2_bss_33FBCC._17 = 0x4A;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            lbl_2_bss_33FBCC._0F = -1;
            lbl_2_bss_9E08 = 14;
        }
    }
    lbl_2_bss_F410._50 = sel;
}

// .text:0x00052198 size:0xC8
void fn_2_52198(void) {
    s32 id;

    if (lbl_803CBBCC->_6 == 5 || lbl_803CBBCC->_6 == 0x10) {
        fn_800B0A5C_insertQueue(fn_80053FE8, 0);
        fn_800B0A5C_insertQueue(fn_2_82DE8, 0x3000);
    }
    if (lbl_8034E9A0._4756 == 0) {
        id = 11;
    } else {
        lbl_8034E978._03 = lbl_8034E9A0._4711;
        id = 16;
    }
    SET_SCREEN(id);
    fn_800B0A5C_insertQueue(fn_2_8ABFC, 0x3000);
}

// .text:0x00051C58 size:0x44C
void fn_2_51C58(void) {
    s32 cursor;
    s32 sel;
    u16 buttons[3];

    cursor = lbl_2_bss_F410._54;
    sel = lbl_2_bss_F410._50;
    memset(buttons, 0, sizeof(buttons));
    buttons[0] = lbl_8034E9A0._472C;
    buttons[1] = lbl_8034E9A0._472E;
    buttons[2] = lbl_8034E9A0._4730;
    if (lbl_2_bss_33FBCC._21 != 0) {
        buttons[2] = 0;
        buttons[1] = 0;
        buttons[0] = 0;
    }
    if (buttons[1] & 0x100) {
        switch (cursor) {
        case 0:
            lbl_2_bss_33FBCC._17 = 0x4A;
            memset(lbl_80354768._0000[lbl_8034E9A0._4754]._0AF8, 0, sizeof(lbl_80354768._0000[0]._0AF8));
            memcpy(&starMissionCompletionTracker, &lbl_80354768._0000[lbl_8034E9A0._4754], sizeof(MenuSaveSlot0A08));
            lbl_80361B20._F6 = sel;
            lbl_2_bss_33FBCC._06 = 0;
            lbl_2_bss_33FBCC._02 = 2;
            break;
        case 1:
            fn_80041150(2, lbl_8034E9A0._4754);
            lbl_2_bss_33FBCC._17 = 0x4A;
            lbl_2_bss_33FBCC._22 = 0x52;
            lbl_8034E978._26 = 1;
            fn_2_5163C();
            lbl_80361B20._F6 = sel;
            lbl_2_bss_33FBCC._06 = 1;
            lbl_2_bss_33FBCC._0E = 1;
            lbl_2_bss_9E08 = 10;
            break;
        case 2:
            if (lbl_80354768._0000[lbl_8034E9A0._4754]._441B != 0) {
                fn_8004A34C(&lbl_803C50E8, 0, 0x38, 0, 0);
            } else {
                fn_8004A34C(&lbl_803C50E8, 0, 0x37, 0, 0);
            }
            lbl_80361B20._F6 = sel;
            lbl_2_bss_33FBCC._06 = 0;
            lbl_2_bss_9E08 = 16;
            break;
        case 3:
            lbl_2_bss_33FBCC._0F = lbl_8034E9A0._4754;
            lbl_2_bss_33FBCC._15 = 3;
            memcpy(&starMissionCompletionTracker, &lbl_80354768._0000[lbl_2_bss_33FBCC._0F], sizeof(MenuSaveSlot0A08));
            lbl_803C50E8._52 = 5;
            lbl_2_bss_F410._50++;
            if (lbl_2_bss_F410._50 == 3) {
                lbl_2_bss_F410._50 = 0;
            }
            lbl_2_bss_33FBCC._0D = lbl_2_bss_F410._50;
            lbl_2_bss_33FBCC._17 = 0x4D;
            lbl_2_bss_33FBCC._02 = 3;
            break;
        case 4:
            lbl_2_bss_33FBCC._0F = lbl_8034E9A0._4754;
            lbl_2_bss_33FBCC._15 = 4;
            lbl_2_bss_33FBCC._02 = 4;
            break;
        case 5:
            lbl_2_bss_33FBCC._02 = 3;
            break;
        }
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    } else if (buttons[1] & 0x200) {
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        lbl_2_bss_33FBCC._02 = 3;
    } else if (buttons[2] & 8) {
        lbl_2_bss_33FBCC._1C = cursor;
        do {
            if (--cursor < 0) {
                cursor = 5;
            }
        } while (lbl_2_bss_33FBCC._07[cursor] == 0);
        lbl_2_bss_33FBCC._22 = 0x53;
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    } else if (buttons[2] & 4) {
        lbl_2_bss_33FBCC._1C = cursor;
        do {
            if (++cursor == 6) {
                cursor = 0;
            }
        } while (lbl_2_bss_33FBCC._07[cursor] == 0);
        lbl_2_bss_33FBCC._22 = 0x53;
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    }
    lbl_2_bss_F410._54 = cursor;
}

// .text:0x000520A4 size:0xF4
void fn_2_520A4(void) {
    switch (lbl_2_bss_33FBCC._02) {
    case 0:
        fn_2_51890();
        fn_800B0A5C_insertQueue(fn_2_89F70, 0x3000);
        lbl_2_bss_33FBCC._22 = 0x51;
        lbl_2_bss_33FBCC._02 = 1;
        break;
    case 1:
        if (lbl_2_bss_33FBCC._22 != 0x51) {
            fn_2_51C58();
        }
        break;
    case 2:
        lbl_2_bss_33FBCC._22 = 0x52;
        lbl_2_bss_33FBCC._0E = 1;
        lbl_2_bss_33FBCC._02 = 0;
        lbl_2_bss_9E08 = 10;
        break;
    case 3:
        lbl_2_bss_33FBCC._22 = 0x52;
        lbl_2_bss_9E08 = 5;
        lbl_2_bss_33FBCC._0E = 1;
        lbl_2_bss_33FBCC._02 = 0;
        break;
    case 4:
        fn_2_51A1C();
        break;
    }
}

// .text:0x00051A1C size:0x23C
void fn_2_51A1C(void) {
    switch (lbl_2_bss_33FBCC._12) {
    case 0:
        if (lbl_2_bss_33FBCC._14 == 0) {
            fn_8004A34C(lbl_2_bss_33FB4C, 0, 0x2E, 0, 0);
        } else {
            fn_8004A34C(lbl_2_bss_33FB4C, 0, 0x2F, 0, 0);
        }
        lbl_2_bss_33FBCC._12 = 1;
        break;
    case 1:
        lbl_2_bss_33FBCC._12 = 2;
        break;
    case 2:
        switch (fn_8004CA6C(lbl_8034E9A0._472E)) {
        case 0:
            break;
        case 1:
            fn_8004CC2C();
            break;
        case 3:
            if (++lbl_2_bss_33FBCC._14 == 2) {
                fn_2_460EC(lbl_8034E9A0._4754);
                fn_8003BF54(0, 0, 0, 0, 1, 5, 3, lbl_8034E9A0._4754, 3);
                lbl_803C50E8._52 = 4;
                ((MenuTask0A08*)lbl_803CC1B8)->_10 = 0;
                lbl_2_bss_33FBCC._14 = 0;
                lbl_2_bss_33FBCC._12 = 3;
            } else {
                lbl_2_bss_33FBCC._12 = 0;
            }
            break;
        case 2:
            fn_8004CC2C();
            break;
        case 4:
            lbl_2_bss_33FBCC._22 = 0x52;
            lbl_2_bss_33FBCC._0E = 1;
            lbl_2_bss_33FBCC._0F = -1;
            lbl_2_bss_33FBCC._12 = 0;
            lbl_2_bss_33FBCC._14 = 0;
            lbl_2_bss_9E08 = 5;
            break;
        }
        break;
    case 3:
        if (((MenuTask0A08*)lbl_803CC1B8)->_10 != 0) {
            lbl_2_bss_33FBCC._17 = 0x50;
            lbl_2_bss_33FBCC._22 = 0x52;
            lbl_2_bss_33FBCC._0E = 1;
            lbl_2_bss_33FBCC._0F = -1;
            lbl_2_bss_33FBCC._12 = 0;
            lbl_2_bss_33FBCC._14 = 0;
            lbl_2_bss_9E08 = 5;
        }
        break;
    }
}

// .text:0x000519F0 size:0x2C
void fn_2_519F0(void) {
    fn_800B0A5C_insertQueue(fn_2_89F70, 0x3000);
}

// .text:0x00051890 size:0x160
void fn_2_51890(void) {
    if (lbl_80354768._0000[lbl_80361B20._F6]._1606 != 0) {
        if (lbl_80354768._0000[lbl_8034E9A0._4754]._441B != 0) {
            lbl_2_bss_F410._54 = 1;
            lbl_2_bss_33FBCC._05 = 3;
            lbl_2_bss_33FBCC._07[0] = 0;
            lbl_2_bss_33FBCC._07[1] = 1;
            lbl_2_bss_33FBCC._07[2] = 1;
            lbl_2_bss_33FBCC._07[3] = 1;
            lbl_2_bss_33FBCC._07[4] = 1;
            lbl_2_bss_33FBCC._07[5] = 1;
        } else {
            lbl_2_bss_F410._54 = 2;
            lbl_2_bss_33FBCC._05 = 2;
            lbl_2_bss_33FBCC._07[0] = 0;
            lbl_2_bss_33FBCC._07[1] = 0;
            lbl_2_bss_33FBCC._07[2] = 1;
            lbl_2_bss_33FBCC._07[3] = 1;
            lbl_2_bss_33FBCC._07[4] = 1;
            lbl_2_bss_33FBCC._07[5] = 1;
        }
    } else if (lbl_80354768._0000[lbl_8034E9A0._4754]._441B != 0) {
        lbl_2_bss_F410._54 = 1;
        lbl_2_bss_33FBCC._05 = 1;
        lbl_2_bss_33FBCC._07[0] = 0;
        lbl_2_bss_33FBCC._07[1] = 1;
        lbl_2_bss_33FBCC._07[2] = 0;
        lbl_2_bss_33FBCC._07[3] = 1;
        lbl_2_bss_33FBCC._07[4] = 1;
        lbl_2_bss_33FBCC._07[5] = 1;
    } else {
        lbl_2_bss_F410._54 = 0;
        lbl_2_bss_33FBCC._05 = 0;
        lbl_2_bss_33FBCC._07[0] = 1;
        lbl_2_bss_33FBCC._07[1] = 0;
        lbl_2_bss_33FBCC._07[2] = 0;
        lbl_2_bss_33FBCC._07[3] = 0;
        lbl_2_bss_33FBCC._07[4] = 0;
        lbl_2_bss_33FBCC._07[5] = 1;
    }
}

// .text:0x0005163C size:0x254
void fn_2_5163C(void) {
    CharEntry0A08* src;
    s32 i;
    CharEntry0A08* dst;

    lbl_8034E9A0._46E0[0] = starMissionCompletionTracker._441D;
    for (i = 0; i < 9; i++) {
        lbl_803C6724._02[0][i] = starMissionCompletionTracker._40B8[i]._0;
        src = &lbl_8034E9A0._0000[lbl_803C6724._02[0][i] / 9][lbl_803C6724._02[0][i] % 9];
        dst = &inMemRoster[0][i];
        memcpy(dst->_00, src->_00, sizeof(dst->_00));
        dst->CharID = src->CharID;
        dst->_26 = src->_26;
        dst->_27 = src->_27;
        memcpy(dst->_28, src->_28, sizeof(dst->_28));
        memcpy(dst->_2A, src->_2A, sizeof(dst->_2A));
        dst->_2C = src->_2C;
        dst->_2D = src->_2D;
        dst->_2E = src->_2E;
        dst->_2F = src->_2F;
        dst->_30 = src->_30;
        dst->_31 = src->_31;
        dst->_32 = src->_32;
        dst->_33 = src->_33;
        dst->_34 = src->_34;
        memcpy(dst->_35, src->_35, sizeof(dst->_35));
        dst->_20 = src->_20;
        memcpy(dst->_37, src->_37, sizeof(dst->_37));
        memcpy(dst->_3B, src->_3B, sizeof(dst->_3B));
        dst->_71 = src->_71;
        dst->_74[0] = src->_74[0];
        dst->_74[1] = src->_74[1];
        dst->_74[2] = src->_74[2];
        dst->_74[3] = src->_74[3];
        dst->_74[4] = src->_74[4];
        dst->_74[5] = src->_74[5];
        dst->_74[6] = src->_74[6];
        dst->_74[7] = src->_74[7];
        dst->_74[8] = src->_74[8];
        dst->_74[9] = src->_74[9];
        dst->_74[10] = src->_74[10];
        dst->_74[11] = src->_74[11];
        dst->_74[12] = src->_74[12];
        dst->_74[13] = src->_74[13];
        dst->_74[14] = src->_74[14];
        dst->_74[15] = src->_74[15];
        dst->_74[16] = src->_74[16];
        dst->_74[17] = src->_74[17];
        dst->_74[18] = src->_74[18];
        dst->_74[19] = src->_74[19];
        dst->_74[20] = src->_74[20];
        lbl_80354720[0][i]._1 = i;
        lbl_80354720[0][i]._0 = i;
        lbl_803C6724._14[0][i] = starMissionCompletionTracker._40B8[i]._3;
        lbl_80354720[0][i]._2 = starMissionCompletionTracker._40B8[i]._3;
    }
    fn_800678CC(0);
}
