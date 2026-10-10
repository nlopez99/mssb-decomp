#include "menus/rep_0438.h"
#include "menus/rep_04B0.h"
#include "menus/rep_0568.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"
#include "string.h"

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x26 - 0x1];
    /* 0x26 */ u8 _26;
} lbl_8034E978;

typedef struct {
    /* 0x0 */ u16 _0;
    /* 0x2 */ u16 _2;
    /* 0x4 */ u16 _4;
} UnkPad0438; // size: 0x6

extern struct {
    /* 0x0000 */ u8 _0000[0x4380];
    /* 0x4380 */ u8 _4380[6][4][0x12];
    /* 0x4530 */ u8 _4530[0x46E0 - 0x4530];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ s32 _46E8;
    /* 0x46EC */ s32 _46EC;
    /* 0x46F0 */ s32 _46F0;
    /* 0x46F4 */ s32 _46F4;
    /* 0x46F8 */ s8 _46F8[2];
    /* 0x46FA */ u8 _46FA[0x4701 - 0x46FA];
    /* 0x4701 */ u8 _4701;
    /* 0x4702 */ u8 _4702[0x470F - 0x4702];
    /* 0x470F */ u8 _470F;
    /* 0x4710 */ u8 _4710;
    /* 0x4711 */ u8 _4711[0x4729 - 0x4711];
    /* 0x4729 */ u8 _4729;
    /* 0x472A */ u8 _472A;
    /* 0x472B */ u8 _472B;
    /* 0x472C */ UnkPad0438 _472C[4];
    /* 0x4744 */ u8 _4744[0x4755 - 0x4744];
    /* 0x4755 */ u8 _4755;
    /* 0x4756 */ u8 _4756;
    /* 0x4757 */ u8 _4757[0x36];
    /* 0x478D */ u8 _478D[0x48AD - 0x478D];
    /* 0x48AD */ u8 _48AD;
    /* 0x48AE */ u8 _48AE;
    /* 0x48AF */ u8 _48AF;
    /* 0x48B0 */ u8 _48B0;
    /* 0x48B1 */ u8 _48B1;
    /* 0x48B2 */ u8 _48B2;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[6];
    /* 0x07 */ u8 _07[0x55 - 0x7];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[0x59 - 0x57];
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
} lbl_803C66B0;

extern struct {
    /* 0x0 */ s32 _0;
    /* 0x4 */ s32 _4;
    /* 0x8 */ s32 _8;
} lbl_803C7898;

extern struct {
    /* 0x00 */ u8 _00[0x5];
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06[0x36 - 0x6];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
} lbl_803C5EA4;

extern struct {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ s32 _0C;
    /* 0x10 */ u8 _10[4];
    /* 0x14 */ u8 _14[4];
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C[4];
    /* 0x20 */ u8 _20;
    /* 0x21 */ s8 _21;
    /* 0x22 */ s8 _22;
    /* 0x23 */ u8 _23[2];
    /* 0x25 */ u8 _25[0x2D - 0x25];
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E[0x40 - 0x2E];
    /* 0x40 */ u8 _40;
    /* 0x41 */ u8 _41;
    /* 0x42 */ u8 _42[0x4A - 0x42];
    /* 0x4A */ u8 _4A;
    /* 0x4B */ u8 _4B[0x54 - 0x4B];
} lbl_2_bss_100B8; // size: 0x54

extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s32 _10[2];
} lbl_2_bss_F410;

extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u16 _4;
    /* 0x6 */ u16 _6;
}* lbl_803CBBCC;

extern struct {
    /* 0x00 */ u8 _00[0xF4];
    /* 0xF4 */ u8 _F4;
} lbl_80361B20;

extern struct {
    /* 0x00 */ u8 _00[2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ u8 _14[2][9];
} lbl_803C6724;

extern struct {
    /* 0x0000 */ u8 _0000[0x40BB];
    /* 0x40BB */ u8 _40BB[9][6];
} starMissionCompletionTracker;

extern struct {
    /* 0x0 */ u8 _0;
} lbl_803CBBC4;

extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u8 _4;
} lbl_803CBD24;

extern struct {
    /* 0x0000 */ u8 _0000[0xCF5F];
    /* 0xCF5F */ u8 _CF5F;
} lbl_803297E0;

extern struct {
    /* 0x000 */ u8 _000[0xE56];
    /* 0xE56 */ s8 _E56;
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x30];
    /* 0x30 */ u16 _30;
    /* 0x32 */ u16 _32;
} lbl_800E877C;

extern struct {
    /* 0x00 */ u8 _00[0x98];
    /* 0x98 */ s32 _98;
} lbl_800EF808;

extern struct {
    /* 0x00 */ u8 _00[0x47];
    /* 0x47 */ u8 _47;
} lbl_803C50E8;

// Main-DOL .sbss object that symbols.txt lumped into lbl_803CBCD0 (+0x8)
extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
} lbl_803CBCD8;

extern u8 lbl_800FE930[2][6];
extern u8 lbl_800FE5D4[12];
extern u8 lbl_80108EC4[];

extern struct {
    /* 0x0 */ s8 _0;
    /* 0x1 */ u8 _1;
} lbl_2_bss_100B4;
typedef struct AramEntry0438 {
    /* 0x0 */ u32 _0[4];
} AramEntry0438; // size: 0x10

// The debug-menu tables; nothing in the unit reads them.
char lbl_2_data_15C8[2][0x20] = { "BAT FIRST", "BAT LAST" };
char lbl_2_data_1608[2][0x20] = { "FL", "PC" };
char lbl_2_data_1648[4][4] = { "RR", "RL", "LR", "LL" };
char lbl_2_data_1658[2][0x20] = { "OFF", "ON" };
char lbl_2_data_1698[5][0x20] = {
    "SELECT DEBUG MENU", "HIDE CHARA SET", "STAR PLAYER SET", "KOOPA STA FLAG SET", "CHALLE LEVEL FREE SET",
};
char lbl_2_data_1738[8][0x20] = {
    "1P >", "COM1>", "2P >", "COM2>", "3P >", "COM3>", "4P >", "COM4>",
};
u32 lbl_2_data_1838[8] = { 0xFF0F, 0x880F, 0x0FFF, 0x088F, 0xF0FF, 0x808F, 0xF00F, 0x800F };
s16 lbl_2_data_1858[12] = { 0, 4, 10, 6, 2, 9, 1, 5, 11, 17, 3, 19 };
u8 lbl_2_data_1870[2][13] = {
    { 0, 2, 6, 8, 4, 10, 1, 3, 7, 5, 9, 11 },
    { 0, 6, 2, 8, 4, 10, 5, 11, 3, 9, 1, 7 },
};
u8 lbl_2_data_188C[40] = {
    2, 5, 4, 3, 8, 3, 4, 5, 2, 6, 0, 1, 8, 6, 7, 1, 2, 0, 7, 4,
    4, 3, 1, 2, 5, 1, 2, 4, 6, 8, 7, 6, 8, 5, 3, 3, 5, 7, 4, 6,
};
AramEntry0438 lbl_2_data_18B4[1] = {
    { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 },
};
AramEntry0438 lbl_2_data_18C4[2] = {
    { 0x0000040B, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 },
    { 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8 },
};
AramEntry0438 lbl_2_data_18E4[13] = {
    { 0x0000040B, 0x4010E5A0, 0x0E97A800, 0x0009BCAC },
    { 0x0000040B, 0x40016980, 0x0EA16800, 0x0000D6C4 },
    { 0x0000040B, 0x40016980, 0x0EA24000, 0x0000C944 },
    { 0x0000040B, 0x40016980, 0x0EA31000, 0x0000E700 },
    { 0x0000040B, 0x40016980, 0x0EA3F800, 0x0000D64C },
    { 0x0000040B, 0x40016980, 0x0EA4D000, 0x0000C900 },
    { 0x0000040B, 0x40016980, 0x0EA5A000, 0x0000CFFC },
    { 0x0000040B, 0x40016980, 0x0EA67000, 0x0000D720 },
    { 0x0000040B, 0x40016980, 0x0EA74800, 0x0000D6CC },
    { 0x0000040B, 0x40016980, 0x0EA82000, 0x0000D21C },
    { 0x0000040B, 0x40016980, 0x0EA8F800, 0x0000D0BC },
    { 0x0000040B, 0x40016980, 0x0EA9D000, 0x0000B544 },
    { 0x0000040B, 0x40016980, 0x0EAA8800, 0x0000C4F8 },
};

// Nothing in the unit reads lbl_2_bss_AE4.
u8 lbl_2_bss_AE4[0x73C];
u16 lbl_2_bss_AE0;

typedef struct CharEntry0438 {
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
} CharEntry0438; // size: 0xA0

typedef struct {
    /* 0x0 */ s8 _0;
    /* 0x1 */ s8 _1;
    /* 0x2 */ s8 _2;
    /* 0x3 */ s8 _3;
} Slot0438;

extern Slot0438 lbl_80354720[2][9];
extern CharEntry0438 inMemRoster[2][9];

static inline void copyChar0438(CharEntry0438* dst, CharEntry0438* src) {
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
}

extern void fn_800AD038(s32 arg0);
extern void fn_800628D4(s32 charID);
extern void fn_8004EEF4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_800678CC(s32 arg0);
extern void fn_8004D990(s32 arg0, s32 arg1, s32 arg2);
extern void fn_8004D460(s32 arg0, s32 arg1);
extern void fn_8004E5B4(s32 arg0, s32 arg1, s32 arg2);
extern void fn_800625A4(s32 index, s32 value);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_2_82E58(void);
extern void fn_2_73758(void);
extern void fn_2_738C8(void);
extern void fn_2_19F2C(void);
extern void fn_2_11A0(s32 arg0);
extern void changeScene(u8, s16);
extern void fn_80062A74(void);
extern void fn_80021410(void);
extern void fn_80035CA4(int arg);
extern void fn_80035B50(int arg);
extern void fn_800AD054(s32 arg0, s32 arg1);
extern void fn_800ACFB0(s32 arg0);
extern void fn_80021AC0(s32 arg0, s32 arg1);
extern void fn_80021AC4(void);
extern s32 fn_80062578(void);
extern s32 fn_8004D93C(s32 arg0);
extern s32 fn_8004EE84(s32 arg0);
extern void fn_8006496C(void);
extern void fn_8004CC2C(void);
extern void fn_8004D0F0(void);
extern s32 fn_8004CA6C(u16 buttons);

// .text:0x00012F88 size:0xC1C
void fn_2_12F88(void) {
    s32 i;
    s32 j;
    s32 ok;

    switch (lbl_803CBBCC->_4) {
    case 0:
        if (lbl_803CBBCC->_6 == 12 && g_d_GameSettings.GameModeSelected == 5 && lbl_803C66B0._55 != 0) {
            break;
        }
        fn_2_123CC();
        lbl_803CBBCC->_4++;
    case 1:
        lbl_803CBBCC->_4 = 2;
        fn_2_12CD8();
        fn_2_738C8();
        if (lbl_803CBBCC->_6 == 5 || (lbl_803CBBCC->_6 == 12 && g_d_GameSettings.GameModeSelected == 5)) {
            fn_2_1641C();
        }
        changeScene(1, 6);
        break;
    case 2:
        fn_2_12B60();
        fn_2_14790();
        fn_2_12A70();
        break;
    case 4:
        if (g_d_GameSettings.GameModeSelected != 5) {
            if (!lbl_2_bss_100B8._40 || !lbl_2_bss_100B8._41 || lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
                break;
            }
            fn_800625A4(0, 7);
            fn_800625A4(1, 7);
        } else {
            if (!lbl_2_bss_100B8._40) {
                break;
            }
            lbl_2_bss_100B4._0 = 1;
            lbl_803CBCD8._5 = 1;
            lbl_8034E9A0._48B1 = 1;
            changeScene(3, 6);
        }
        lbl_803CBBCC->_4 = 5;
        break;
    case 5:
        if (lbl_2_bss_100B4._1 != 0) {
            break;
        }
        if (lbl_803297E0._CF5F) {
            if (g_d_GameSettings.GameModeSelected == 5) {
                ok = fn_8004D93C(0);
            } else {
                ok = fn_8004EE84(0);
            }
            if (ok == 0) {
                break;
            }
        } else {
            if (g_d_GameSettings.GameModeSelected == 5) {
                ok = fn_8004D93C(1);
            } else {
                ok = fn_8004EE84(2);
            }
            if (ok == 0) {
                break;
            }
        }
        lbl_803CBBCC->_4 = 6;
    case 6:
        if (g_d_GameSettings.GameModeSelected != 5 && fn_80062578() == 0) {
            break;
        }
        if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
            break;
        }
        if (lbl_803297E0._CF5F) {
            fn_2_19F2C();
            lbl_8034E9A0._48AD = 1;
            lbl_803C66B0._00 = 0;
            memset(lbl_803C66B0._01, 0, 6);
            lbl_8034E9A0._4755 = 3;
            fn_80062A74();
            fn_80021410();
            fn_80035CA4(15);
            fn_80035CA4(18);
            fn_80035CA4(9);
            fn_80035CA4(6);
            lbl_8034E9A0._48AF = 1;
            lbl_8034E9A0._48B1 = 1;
            lbl_8034E978._26 = 1;
            lbl_803297E0._CF5F = 0;
            fn_2_11A0(4);
            break;
        }
        lbl_8034E9A0._48AD = 1;
        lbl_803C66B0._00 = 0;
        memset(lbl_803C66B0._01, 0, 6);
        lbl_8034E9A0._4755 = 3;
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_8034E9A0._472A = 0;
            fn_800AD038(lbl_8034E9A0._46E8);
            fn_2_19F2C();
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 9; j++) {
                    if (j == 0) {
                        lbl_803C6724._02[i][j] = lbl_8034E9A0._46E0[i];
                    } else {
                        lbl_803C6724._02[i][j] = -1;
                    }
                }
            }
            fn_80021AC0(0, 0);
            fn_80021AC0(1, 0);
            fn_8006496C();
            fn_2_11A0(10);
            break;
        }
        lbl_8034E9A0._48AF = 1;
        fn_8006496C();
        if (lbl_8036E548._E56 != lbl_8034E9A0._46E0[0]) {
            lbl_2_bss_100B8._14[0] = 1;
        }
        fn_2_11EA8();
        changeScene(4, 6);
        lbl_8034E978._26 = 1;
        lbl_8034E9A0._48B2 = 1;
        lbl_8034E9A0._48AF = 1;
        fn_800AD038(lbl_8034E9A0._46E8);
        fn_2_19F2C();
        fn_80062A74();
        fn_80035B50(15);
        fn_80035B50(18);
        fn_80035B50(9);
        fn_80035B50(6);
        fn_800AD054(lbl_8034E9A0._46F0, lbl_8034E9A0._46F4);
        fn_80021410();
        fn_800ACFB0(lbl_800EF808._98);
        lbl_800E877C._30 = 0;
        lbl_800E877C._32 = 0;
        fn_2_11A0(16);
        break;
    case 8:
        if (lbl_2_bss_100B4._1 != 0) {
            break;
        }
        lbl_2_bss_100B8._40 = 1;
        lbl_2_bss_100B8._41 = 1;
        if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
            break;
        }
        if (g_d_GameSettings.GameModeSelected == 5) {
            ok = fn_8004D93C(0);
        } else {
            ok = fn_8004EE84(0);
        }
        if (ok == 0) {
            break;
        }
        lbl_803CBBCC->_4 = 9;
    case 9:
        if (g_d_GameSettings.GameModeSelected == 5) {
            if (lbl_803C50E8._47) {
                lbl_8034E978._26 = 1;
            }
            lbl_803CBCD8._5 = 1;
            lbl_8034E9A0._48B1 = 1;
            fn_800AD038(lbl_8034E9A0._46E8);
            fn_2_11A0(12);
            break;
        }
        lbl_8034E978._26 = 1;
        fn_80021AC4();
        fn_2_120D0();
        fn_2_11A0(5);
        break;
    case 10:
        fn_800B0A5C_insertQueue(fn_8004D0F0, 0x3000);
        lbl_803CBBCC->_4 = 11;
        break;
    case 11:
        switch (fn_8004CA6C(lbl_8034E9A0._472C[lbl_8034E9A0._46F8[lbl_803CBD24._4]]._2)) {
        case 0:
            break;
        case 1:
            fn_8004CC2C();
            break;
        case 3:
            fn_8006496C();
            lbl_2_bss_100B8._40 = 1;
            lbl_2_bss_100B8._41 = 1;
            fn_800625A4(0, 7);
            fn_800625A4(1, 7);
            lbl_2_bss_100B4._0 = 1;
            lbl_803CBD24._4 = 0;
            lbl_2_bss_100B8._41 = 1;
            lbl_2_bss_100B8._40 = 1;
            changeScene(15, 6);
            lbl_803CBBCC->_4 = 5;
            break;
        case 2:
            fn_8004CC2C();
            break;
        case 4:
            lbl_803CBD24._4 = 0;
            lbl_803CBBCC->_4 = 2;
            lbl_803297E0._CF5F = 0;
            break;
        }
        break;
    }
}

// .text:0x00012CD8 size:0x2B0
void fn_2_12CD8(void) {
    if (lbl_803CBBCC->_6 == 5) {
        lbl_2_bss_F410._10[0] = 0;
        lbl_2_bss_F410._10[1] = 1;
    }
    lbl_8034E9A0._48AD = 0;
    if (g_d_GameSettings.GameModeSelected == 5) {
        g_d_GameSettings._10 = 0;
        lbl_2_bss_100B8._2D = 1;
    } else {
        lbl_2_bss_100B8._2D = 2;
    }
    lbl_803C66B0._00 = 1;
    lbl_8034E9A0._4755 = 0;
    fn_2_129AC();
    fn_2_18FBC();
    if (g_d_GameSettings.GameModeSelected == 5) {
        fn_2_12238();
    }
    if (g_d_GameSettings.GameModeSelected == 5) {
        fn_8004D990(lbl_8034E9A0._46F8[0], 0, lbl_80361B20._F4);
        fn_8004D460(0, lbl_2_bss_F410._10[0]);
    }
    lbl_8034E9A0._4701 = 1;
}

// .text:0x00012C34 size:0xA4
void fn_2_12C34(void) {
    u8 count;
    s32 i;
    s32 index;

    if (lbl_2_bss_100B8._4A) {
        return;
    }
    if (lbl_2_bss_100B8._20 == 1 || lbl_803C5EA4._05 == 0) {
        if (lbl_2_bss_AE0 == 60000) {
            lbl_2_bss_AE0 = 0;
        }
        lbl_2_bss_AE0++;
    }
    count = 12;
    index = 4;
    if (g_d_GameSettings.GameModeSelected == 5) {
        count = 6;
    }
    for (i = 0; i < count; i++) {
        index++;
        if (index == 21) {
            index = 5;
        }
    }
}

// .text:0x00012B60 size:0xD4
void fn_2_12B60(void) {
    s32 prev[2];
    s32 i;

    prev[0] = lbl_2_bss_F410._10[0];
    prev[1] = lbl_2_bss_F410._10[1];
    fn_2_15E80(0);
    if (g_d_GameSettings._10 == 1) {
        fn_2_15E80(1);
    }
    for (i = 0; i < 2; i++) {
        while (fn_2_15104(lbl_2_bss_F410._10[i], prev[i], i, 1) == 0 && lbl_2_bss_100B8._10[i] != 0) {
            prev[i] = lbl_2_bss_F410._10[i];
        }
    }
}

// .text:0x00012A70 size:0xF0
void fn_2_12A70(void) {
    if (lbl_2_bss_100B8._10[2]) {
        lbl_2_bss_100B8._10[2] = 0;
        fn_800628D4(lbl_8034E9A0._46E0[0]);
    }
    if (lbl_2_bss_100B8._10[3]) {
        lbl_2_bss_100B8._10[3] = 0;
        fn_800628D4(lbl_8034E9A0._46E0[1]);
    }
    if (lbl_2_bss_100B8._10[0] && lbl_2_bss_100B8._10[1]) {
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_2_bss_100B4._0 = 1;
        }
        lbl_803CBBCC->_4 = 4;
        if (g_d_GameSettings._10 == 0) {
            lbl_2_bss_100B8._10[1] = 0;
            lbl_2_bss_100B8._10[3] = 0;
        }
    }
}

// .text:0x000129D0 size:0xA0
void fn_2_129D0(void) {
    memset(lbl_2_bss_100B8._14, 0, lbl_2_bss_100B8._2D);
    memset(lbl_2_bss_100B8._1C, 0, lbl_2_bss_100B8._2D);
    memset(lbl_2_bss_100B8._23, -1, 2);
    lbl_2_bss_100B8._18 = 0;
    lbl_2_bss_100B8._19 = 0;
    lbl_2_bss_100B8._1A = 0;
    lbl_2_bss_100B8._1B = 0;
    lbl_2_bss_100B8._20 = 0;
    lbl_2_bss_100B8._21 = -1;
    lbl_2_bss_100B8._22 = -1;
    lbl_2_bss_100B8._0C = -1;
    lbl_2_bss_100B8._2D = 0;
}

// .text:0x000129AC size:0x24
void fn_2_129AC(void) {
    lbl_8034E9A0._46E8 = lbl_803C7898._4;
    lbl_8034E9A0._46EC = lbl_803C7898._8;
}

// .text:0x00012988 size:0x24
void fn_2_12988(void) {
    lbl_8034E9A0._46F0 = lbl_803C7898._4;
    lbl_8034E9A0._46F4 = lbl_803C7898._8;
}

// .text:0x000123CC size:0x5BC
void fn_2_123CC(void) {
    s32 i;
    s32 j;
    s32 prev;

    memset(lbl_8034E9A0._4757, 0, sizeof(lbl_8034E9A0._4757));
    lbl_8034E9A0._4710 = 0;
    lbl_8034E9A0._470F = 0;
    if (g_d_GameSettings.GameModeSelected == 5) {
        lbl_803C5EA4._36 = 1;
        lbl_803C5EA4._37 = lbl_803C5EA4._38;
        lbl_803C5EA4._38 = 5;
    }
    if (lbl_803CBBCC->_6 == 5 || (lbl_803CBBCC->_6 == 12 && g_d_GameSettings.GameModeSelected == 5)) {
        fn_2_129D0();
        lbl_8034E9A0._472A = 0xFF;
        lbl_8034E9A0._46E0[1] = -1;
        lbl_8034E9A0._46E0[0] = -1;
        fn_2_1641C();
        switch (lbl_2_bss_100B8._20) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            lbl_8034E9A0._4729 = 0;
            g_d_GameSettings._10 = 0;
            lbl_803C5EA4._05 = 0;
            break;
        }
        memset(&lbl_2_bss_100B8, 0, sizeof(lbl_2_bss_100B8));
        lbl_803C6724._00[1] = 0;
        lbl_803C6724._00[0] = 0;
        if (g_d_GameSettings.GameModeSelected != 5) {
            fn_800625A4(0, 1);
            fn_800625A4(1, 1);
        } else {
            fn_2_82E58();
            fn_800B0A5C_insertQueue(fn_2_73758, 0x3000);
            fn_800625A4(0, 1);
            lbl_803CBBC4._0 = 1;
        }
        lbl_803C66B0._59 = 0;
        lbl_803C66B0._5A = 1;
        lbl_2_bss_F410._10[0] = 0;
        lbl_2_bss_F410._10[1] = 1;
        fn_2_16A48(0, 1);
        fn_2_16A48(1, 0);
        fn_2_1216C();
    } else {
        if (g_d_GameSettings.GameModeSelected != 5 && g_d_GameSettings._10 != 0) {
            lbl_2_bss_100B8._10[0] = 0;
            lbl_2_bss_100B8._10[2] = 0;
            lbl_2_bss_100B8._10[1] = 0;
            lbl_2_bss_100B8._10[3] = 0;
        }
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 12; j++) {
                if (lbl_8034E9A0._46E0[i] == lbl_800FE5D4[j]) {
                    lbl_2_bss_F410._10[i] = j;
                    break;
                }
            }
            if (g_d_GameSettings.GameModeSelected != 5) {
                prev = -1;
                while (fn_2_15104(lbl_2_bss_F410._10[i], prev, i, 1) == 0) {
                    prev = lbl_2_bss_F410._10[i];
                }
            }
        }
        if (g_d_GameSettings.GameModeSelected != 5) {
            fn_2_1216C();
        }
        if (g_d_GameSettings._10 == 0 && g_d_GameSettings.GameModeSelected != 5) {
            lbl_2_bss_100B8._10[0] = 1;
            lbl_2_bss_100B8._10[2] = 1;
            lbl_803C66B0._59 = 1;
            fn_8004E5B4(lbl_8034E9A0._46F8[0], lbl_8034E9A0._46E0[0], 1);
        } else if (g_d_GameSettings.GameModeSelected == 5) {
            lbl_2_bss_100B8._10[0] = 0;
            lbl_2_bss_100B8._10[2] = 0;
            lbl_803C66B0._59 = 0;
        }
        fn_800625A4(0, 8);
        fn_800625A4(1, 8);
    }
    lbl_2_bss_100B4._0 = 0;
    lbl_8034E9A0._472A = 0xFF;
}

// .text:0x00012238 size:0x194
void fn_2_12238(void) {
    s32 i;
    s32 captain;
    s32 id;

    id = lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[0]];
    for (i = 0; i < 6; i++) {
        if (lbl_80108EC4[i] == id) {
            captain = i;
            break;
        }
    }
    if (i == 6) {
        OSPanic("teamselect.c", 1113, " Captain Not Found ");
    }
    for (i = 0; i < 9; i++) {
        lbl_803C6724._02[0][i] = lbl_8034E9A0._4380[captain][0][i];
        starMissionCompletionTracker._40BB[i][0] = i;
        lbl_803C6724._14[0][i] = i;
    }
    fn_800678CC(0);
}

// .text:0x0001216C size:0xCC
void fn_2_1216C(void) {
    s8 ports[4];

    memset(ports, 2, 4);
    if (g_d_GameSettings._10 == 0) {
        ports[lbl_8034E9A0._46F8[0]] = 1;
        if (lbl_8034E9A0._46F8[0] == 0) {
            ports[1] = 2;
        } else {
            ports[0] = 2;
        }
    } else {
        ports[lbl_8034E9A0._46F8[1]] = 1;
        ports[lbl_8034E9A0._46F8[0]] = 1;
    }
    fn_8004EEF4(ports[0], ports[1], ports[2], ports[3], 1);
}

// .text:0x000120D0 size:0x9C
void fn_2_120D0(void) {
    lbl_8034E9A0._48AD = 1;
    lbl_8034E9A0._4755 = 3;
    lbl_803C66B0._00 = 0;
    lbl_803C66B0._5A = 0;
    lbl_803C66B0._59 = 0;
    lbl_8034E9A0._472A = 0xFF;
    lbl_8034E9A0._48AF = 1;
    lbl_8034E9A0._48B1 = 1;
    memset(lbl_803C66B0._01, 0, 6);
    lbl_8034E978._26 = 1;
    fn_800AD038(lbl_8034E9A0._46E8);
    g_d_GameSettings._10 = 0;
}

// .text:0x00011EA8 size:0x228
void fn_2_11EA8(void) {
    s32 i;
    s8 id;

    for (i = 0; i < 9; i++) {
        id = lbl_803C6724._02[0][i];
        copyChar0438(&inMemRoster[0][i], &((CharEntry0438(*)[9])&lbl_8034E9A0)[id / 9][id % 9]);
        lbl_80354720[0][i]._2 = i;
        lbl_80354720[0][i]._1 = i;
        lbl_80354720[0][i]._0 = i;
    }
}
