#include "header_rep_data.h"
#include "menus/rep_0398.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"

extern struct {
    /* 0x0000 */ u8 _0000[0x46F8];
    /* 0x46F8 */ s8 _46F8[4];
    /* 0x46FC */ u8 _46FC[0x4703 - 0x46FC];
    /* 0x4703 */ u8 _4703;
    /* 0x4704 */ u8 _4704[0x4711 - 0x4704];
    /* 0x4711 */ u8 _4711;
    /* 0x4712 */ u8 _4712[0x472A - 0x4712];
    /* 0x472A */ u8 _472A;
    /* 0x472B */ u8 _472B[0x472E - 0x472B];
    /* 0x472E */ u16 _472E[6][3];
    /* 0x4752 */ u8 _4752[0x48AF - 0x4752];
    /* 0x48AF */ u8 _48AF;
    /* 0x48B0 */ u8 _48B0;
    /* 0x48B1 */ u8 _48B1;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x8 - 0x1];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A[0x24 - 0xA];
    /* 0x24 */ u8 _24;
    /* 0x25 */ u8 _25;
    /* 0x26 */ u8 _26;
} lbl_8034E978;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} lbl_800FEF70[];

extern struct {
    /* 0x00 */ u8 _00[0x36];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
} lbl_803C5EA4;

extern struct {
    /* 0x00 */ u8 _00[0x47];
    /* 0x47 */ u8 _47;
} lbl_803C50E8;

extern struct {
    /* 0x0000 */ u8 _0000[0xCF5F];
    /* 0xCF5F */ u8 _CF5F;
} lbl_803297E0;

// Main-DOL .sbss object that symbols.txt lumps into lbl_803CBBC2 (+0x2)
extern struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
} lbl_803CBBC4;

extern u8 lbl_2_bss_100B4;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x55 - 0x1];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[0x5D - 0x57];
    /* 0x5D */ u8 _5D;
} lbl_803C66B0;

// Main-DOL .sbss object that symbols.txt lumped into lbl_803CBCD0 (+0x8)
extern struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2[0x4 - 0x2];
    /* 0x4 */ u8 _4;
} lbl_803CBCD8;

extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u16 _4;
    /* 0x6 */ u16 _6;
    /* 0x8 */ u16 _8;
} *lbl_803CBBCC;

extern struct {
    /* 0x00 */ u8 _00[0x44];
    /* 0x44 */ s32 _44;
} lbl_2_bss_F410;

extern struct {
    /* 0x00 */ u8 _00[0x57];
    /* 0x57 */ u8 _57;
    /* 0x58 */ u8 _58;
} lbl_2_bss_F468;

extern struct {
    /* 0x00 */ u8 _00[0xE3];
    /* 0xE3 */ u8 _E3[0xF5 - 0xE3];
    /* 0xF5 */ u8 _F5;
} lbl_80361B20;

extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_2_data_130C[];

extern void fn_800625A4(s32 port, s32 arg1);
extern void fn_2_1C34(u16 buttons);
extern s32 fn_2_14F8(s32 min, s32 max);
extern void fn_2_2DC(void);
extern void fn_2_328(void);
extern void fn_2_11A0(s32 arg0);
extern void fn_2_15A90(s32* index, s32 arg1, u8 arg2);
extern void fn_2_2FC0(s32, s32, s32);
extern void fn_2_836A4(void);
extern void fn_2_85108(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void changeScene(u8, s16);
extern void fn_80035CA4(s32 id);
extern s32 fn_8004CA6C(u16 buttons);
extern void fn_8004CC2C(void);
extern void fn_8004D0F0(void);
extern void fn_80062A74(void);

// .bss:0x00000758 size:0x388
u8 lbl_2_bss_758[0x388];

// .text:0x00011698 size:0x810
void fn_2_11698(void) {
    s8 best;
    s32 i;

    best = -1;
    switch (lbl_803CBBCC->_4) {
    case 0:
        if (lbl_803CBBCC->_6 == 13) {
            fn_800625A4(0, 0x26);
            lbl_803CBBCC->_4 = 1;
        } else if (g_d_GameSettings.GameModeSelected == 5) {
            changeScene(1, 6);
            fn_2_836A4();
            lbl_2_bss_F468._57 = 0;
            for (i = 0; i < 4; i++) {
                if (lbl_80361B20._E3[i + 1] != 0 && best < i) {
                    best = i;
                }
            }
            if (best != -1) {
                lbl_2_bss_F468._57 = best + 1;
                if (lbl_2_bss_F468._57 > 3) {
                    lbl_2_bss_F468._57 = 3;
                }
            }
            lbl_803CBBCC->_4 = 5;
        } else {
            fn_2_85108();
            if (lbl_803C66B0._55 == 0 && lbl_803C66B0._56 == 0) {
                lbl_8034E978._00 = 5;
                lbl_8034E978._09 = lbl_8034E978._08;
                lbl_8034E978._08 = lbl_800FEF70[5]._08;
                lbl_803C5EA4._36 = 1;
                lbl_803C5EA4._37 = lbl_803C5EA4._38;
                lbl_803C5EA4._38 = 2;
                lbl_803C66B0._00 = 4;
                if (lbl_8034E9A0._4703 == 0) {
                    lbl_2_bss_F410._44 = 0;
                    lbl_2_bss_F410._44 = 0;
                }
                lbl_8034E9A0._4703 = 1;
                fn_800625A4(0, 0x27);
                lbl_803CBBCC->_4 = 1;
            }
        }
        break;
    case 1:
        if (lbl_803C66B0._55 == 0 && lbl_803C66B0._56 == 0) {
            lbl_803CBBCC->_4 = 2;
        }
        break;
    case 2:
        for (i = 0; i < 2; i++) {
            fn_2_11340(i);
        }
        break;
    case 3:
        if (lbl_803CBCD8._4 == 0 && lbl_803C66B0._5D == 0) {
            lbl_803C66B0._00 = 3;
            lbl_803CBBCC->_4 = 11;
        }
        break;
    case 4:
        if (lbl_803C66B0._5D == 0) {
            lbl_2_bss_100B4 = 1;
            lbl_803CBBCC->_4 = 12;
        }
        break;
    case 5:
        if (lbl_803C66B0._55 == 0) {
            lbl_803CBBC4._0 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._4 = 0;
            lbl_2_bss_F410._44 = 0;
            changeScene(1, 6);
            lbl_803C5EA4._36 = 1;
            lbl_803C5EA4._37 = lbl_803C5EA4._38;
            lbl_803C5EA4._38 = 4;
            lbl_803CBBC4._0 = 0x5D;
            lbl_803CBBC4._5 = 0;
            lbl_803CBBCC->_4 = 6;
        }
        break;
    case 6:
        if (lbl_803C66B0._55 == 0) {
            lbl_803CBBC4._1 = lbl_2_bss_F410._44;
            fn_2_15A90(&lbl_2_bss_F410._44, 0, lbl_2_bss_F468._57);
            lbl_8034E9A0._4711 = lbl_2_bss_F410._44;
            if (lbl_803CBBC4._1 != lbl_8034E9A0._4711) {
                lbl_803CBBC4._0 = 0x5E;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
            if (lbl_8034E9A0._472E[0][0] & 0x100) {
                if (lbl_2_bss_F410._44 < 6) {
                    if (lbl_80361B20._E3[lbl_8034E9A0._4711] == 0 && lbl_8034E9A0._4711 != 0) {
                        sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                    } else {
                        lbl_803CBBC4._0 = 0x60;
                        lbl_8034E9A0._472A = 1;
                        fn_2_1C34(0x100);
                        lbl_803CBBCC->_4 = 7;
                    }
                }
            } else if (lbl_8034E9A0._472E[0][0] & 0x200) {
                fn_2_1C34(0x200);
                lbl_803CBBC4._0 = 0x60;
                lbl_8034E9A0._472A = 1;
                lbl_803CBBCC->_4 = 8;
            }
        }
        break;
    case 7:
        if (lbl_803CBBC4._5 != 0) {
            lbl_803CBBC4._5 = 0;
            lbl_2_bss_100B4 = 1;
            lbl_803CBBCC->_4 = 12;
        }
        break;
    case 8:
        if (lbl_803CBBC4._5 != 0) {
            lbl_803CBBCC->_4 = 11;
        }
        break;
    case 9:
        fn_800B0A5C_insertQueue(fn_8004D0F0, 0x3000);
        lbl_803CBBCC->_4 = 10;
        break;
    case 10:
        switch (fn_8004CA6C(lbl_8034E9A0._472E[0][0])) {
        case 0:
            break;
        case 1:
            fn_8004CC2C();
            break;
        case 3:
            fn_2_2FC0(12, 1, 1);
            lbl_803CBCD8._4 = 1;
            fn_80035CA4(15);
            fn_80035CA4(18);
            fn_80035CA4(9);
            fn_80035CA4(6);
            lbl_8034E9A0._48AF = 1;
            lbl_8034E9A0._48B1 = 1;
            lbl_8034E978._26 = 1;
            changeScene(15, 6);
            lbl_803CBBCC->_4 = 12;
            lbl_2_bss_758[0] = 1;
            break;
        case 2:
            fn_8004CC2C();
            break;
        case 4:
            lbl_803297E0._CF5F = 0;
            lbl_803CBBCC->_4 = 2;
            break;
        }
        break;
    case 11:
        if (g_d_GameSettings.GameModeSelected != 5) {
            if (lbl_803CBCD8._4 != 0 || lbl_803C66B0._5D != 0) {
                break;
            }
            lbl_803CBCD8._1 = 0;
            lbl_803CBCD8._0 = 0;
            fn_2_11A0(11);
        } else {
            lbl_803CBBC4._4 = 1;
            if (lbl_803C50E8._47 == 0) {
                fn_2_11A0(15);
            } else {
                lbl_8034E978._26 = 1;
                lbl_8034E9A0._48AF = 1;
                fn_2_11A0(5);
            }
        }
        lbl_803CBBCC->_8 = 0;
        break;
    case 12:
        if (lbl_2_bss_758[0] != 0) {
            if (lbl_8034E978._24 == 0) {
                fn_80062A74();
                lbl_2_bss_758[0] = 0;
                changeScene(15, 6);
                fn_2_11A0(4);
            }
        } else if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_803CBCD8._4 = 0;
            lbl_2_bss_F468._58 = 0;
            fn_2_11A0(13);
        } else if (lbl_803CBBC4._3 != 1) {
            lbl_803CBBC4._4 = 1;
            fn_2_11A0(9);
        }
        break;
    }
}

// .text:0x00011340 size:0x358
// 98.36%: the target loads the wraparound 0 into r6 early (`mr r4,r6`) and swaps the
// registers of the two button words; the rest matches.
void fn_2_11340(u8 port) {
    s32 prev;
    s32 r;
    s32 i;
    u8 found;
    u16 held;
    u16 pressed;

    found = 0;
    if (lbl_803CBCD8._0 != 0) {
        prev = lbl_2_bss_F410._44;
        do {
            if (lbl_80361B20._F5 != 0) {
                r = fn_2_14F8(0, 5);
            } else {
                r = fn_2_14F8(0, 4);
            }
        } while (prev == r);
        lbl_2_bss_F410._44 = r;
        lbl_803CBCD8._1--;
        fn_800625A4(0, 0x28);
        return;
    }
    if (lbl_803C66B0._55 != 0) {
        return;
    }
    if (g_d_GameSettings.GameModeSelected != 5) {
        for (i = 0; i < 2; i++) {
            if (g_d_GameSettings.PlayerPorts[i] == lbl_8034E9A0._46F8[port]) {
                found = 1;
            }
        }
        lbl_8034E9A0._46F8[port] = lbl_8034E9A0._46F8[port];
        if (!found) {
            return;
        }
    } else if (port != 0) {
        return;
    }
    held = lbl_8034E9A0._472E[port][1];
    pressed = lbl_8034E9A0._472E[port][0];
    if (held & 1) {
        if (lbl_803C66B0._5D != 0x24) {
            r = lbl_2_bss_F410._44 - 1;
            if (r < 0) {
                r = 5;
            }
            lbl_2_bss_F410._44 = r;
            fn_800625A4(0, 0x28);
            fn_2_1C34(1);
        }
    } else if (held & 2) {
        if (lbl_803C66B0._5D != 0x24) {
            r = lbl_2_bss_F410._44 + 1;
            if (r == 6) {
                r = 0;
            }
            lbl_2_bss_F410._44 = r;
            fn_800625A4(0, 0x28);
            fn_2_1C34(2);
        }
    } else if (pressed & 0x20) {
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_803CBCD8._0 = 1;
            lbl_803CBCD8._1 = 6;
        }
    } else if (lbl_8034E9A0._472E[port][0] & 0x100) {
        if (lbl_2_bss_F410._44 < 6) {
            if (lbl_80361B20._F5 == 0 && lbl_2_data_130C[lbl_2_bss_F410._44] == 1) {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            } else if (lbl_803C66B0._5D == 0) {
                g_d_GameSettings.StadiumID = lbl_2_data_130C[lbl_2_bss_F410._44];
                lbl_2_bss_F468._58 = 1;
                fn_2_328();
                fn_2_1C34(0x100);
                fn_800625A4(0, 0x25);
                lbl_803CBBCC->_4 = 4;
            }
        }
    } else if (lbl_8034E9A0._472E[port][0] & 0x200) {
        if (lbl_803CBCD8._0 == 0 && lbl_803C66B0._5D == 0) {
            fn_2_2DC();
            fn_2_1C34(0x200);
            lbl_803CBBCC->_6 = 12;
            fn_800625A4(0, 0x24);
            lbl_803CBBCC->_4 = 3;
        }
    }
}
