#include "menus/rep_0A08.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

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
    /* 0x40EE */ u8 _40EE[0x441D - 0x40EE];
    /* 0x441D */ u8 _441D;
} starMissionCompletionTracker;
extern struct {
    /* 0x0000 */ CharEntry0A08 _0000[6][9];
    /* 0x21C0 */ u8 _21C0[0x46E0 - 0x21C0];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x4711 - 0x46E8];
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
extern void fn_800678CC(s32 team);
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
