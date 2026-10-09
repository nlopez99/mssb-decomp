#include "menus/rep_0A08.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"

typedef struct MenuSaveSlot0A08 {
    /* 0x0000 */ u8 _0000[0x1606];
    /* 0x1606 */ s8 _1606;
    /* 0x1607 */ u8 _1607[0x441B - 0x1607];
    /* 0x441B */ u8 _441B;
    /* 0x441C */ u8 _441C[0x4508 - 0x441C];
} MenuSaveSlot0A08; // size: 0x4508

extern MenuSaveSlot0A08 lbl_80354768[];
extern struct {
    /* 0x00 */ u8 _00[0xF6];
    /* 0xF6 */ u8 _F6;
} lbl_80361B20;
extern struct {
    /* 0x0000 */ u8 _0000[0x4711];
    /* 0x4711 */ u8 _4711;
    /* 0x4712 */ u8 _4712[0x472B - 0x4712];
    /* 0x472B */ u8 _472B;
    /* 0x472C */ u8 _472C[0x4754 - 0x472C];
    /* 0x4754 */ u8 _4754;
    /* 0x4755 */ u8 _4755;
    /* 0x4756 */ u8 _4756;
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
    /* 0x07 */ u8 _07;
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A;
    /* 0x0B */ u8 _0B;
    /* 0x0C */ u8 _0C;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
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

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_80053FE8(void);
extern void fn_2_82DE8(void);
extern void fn_2_89F70(void);
extern void fn_2_8ABFC(void);

#define SET_SCREEN(id)                                                                                                 \
    lbl_8034E978._00 = (id);                                                                                           \
    lbl_8034E978._09 = lbl_8034E978._08;                                                                               \
    lbl_8034E978._08 = lbl_800FEF70[(id)]._08

extern struct {
    /* 0x00 */ u8 _00[0x47];
    /* 0x47 */ u8 _47;
    /* 0x48 */ u8 _48[0x52 - 0x48];
    /* 0x52 */ u8 _52;
} lbl_803C50E8;
extern struct {
    /* 0x00 */ u8 _00[0x58];
    /* 0x58 */ s16 _58;
    /* 0x5A */ s16 _5A;
} gameInitOptions;

typedef struct AramEntry0A08 {
    /* 0x0 */ u32 _0[4];
} AramEntry0A08; // size: 0x10

extern int fn_80035838(AramEntry0A08* entry, int count);
extern void fn_80035B50(int arg);
extern void fn_80042D38(s32 arg);
extern void changeScene(u8, s16);

AramEntry0A08 lbl_2_data_1F884 = { 0x0000040B, 0x400B2CB8, 0x18E3F000, 0x00053454 };
AramEntry0A08 lbl_2_data_1F894 = { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 };

s16 lbl_2_bss_9E08;

// .text:0x00053408 size:0x1A8
// The target reads 0x800E877C as its own object (gameInitOptions+0x28 with
// offsets 0x30 and 0x32); symbols.txt lumps it into gameInitOptions.
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
            if (gameInitOptions._58 == 10 && lbl_803C50E8._47 != 0) {
                changeScene(6, 6);
                changeScene(3, 6);
                fn_80035B50(8);
                gameInitOptions._58 = 9;
                gameInitOptions._5A = 0;
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

// .text:0x0005268C size:0x4
void fn_2_5268C(void) {
}

// .text:0x00052648 size:0x44
void fn_2_52648(s32 priority) {
    fn_800B0A5C_insertQueue(fn_2_52690, priority);
    lbl_8034E9A0._472B = g_d_GameSettings._06;
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

// .text:0x000519F0 size:0x2C
void fn_2_519F0(void) {
    fn_800B0A5C_insertQueue(fn_2_89F70, 0x3000);
}

// .text:0x00051890 size:0x160
void fn_2_51890(void) {
    if (lbl_80354768[lbl_80361B20._F6]._1606 != 0) {
        if (lbl_80354768[lbl_8034E9A0._4754]._441B != 0) {
            lbl_2_bss_F410._54 = 1;
            lbl_2_bss_33FBCC._05 = 3;
            lbl_2_bss_33FBCC._07 = 0;
            lbl_2_bss_33FBCC._08 = 1;
            lbl_2_bss_33FBCC._09 = 1;
            lbl_2_bss_33FBCC._0A = 1;
            lbl_2_bss_33FBCC._0B = 1;
            lbl_2_bss_33FBCC._0C = 1;
        } else {
            lbl_2_bss_F410._54 = 2;
            lbl_2_bss_33FBCC._05 = 2;
            lbl_2_bss_33FBCC._07 = 0;
            lbl_2_bss_33FBCC._08 = 0;
            lbl_2_bss_33FBCC._09 = 1;
            lbl_2_bss_33FBCC._0A = 1;
            lbl_2_bss_33FBCC._0B = 1;
            lbl_2_bss_33FBCC._0C = 1;
        }
    } else if (lbl_80354768[lbl_8034E9A0._4754]._441B != 0) {
        lbl_2_bss_F410._54 = 1;
        lbl_2_bss_33FBCC._05 = 1;
        lbl_2_bss_33FBCC._07 = 0;
        lbl_2_bss_33FBCC._08 = 1;
        lbl_2_bss_33FBCC._09 = 0;
        lbl_2_bss_33FBCC._0A = 1;
        lbl_2_bss_33FBCC._0B = 1;
        lbl_2_bss_33FBCC._0C = 1;
    } else {
        lbl_2_bss_F410._54 = 0;
        lbl_2_bss_33FBCC._05 = 0;
        lbl_2_bss_33FBCC._07 = 1;
        lbl_2_bss_33FBCC._08 = 0;
        lbl_2_bss_33FBCC._09 = 0;
        lbl_2_bss_33FBCC._0A = 0;
        lbl_2_bss_33FBCC._0B = 0;
        lbl_2_bss_33FBCC._0C = 1;
    }
}
