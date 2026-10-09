#include "header_rep_data.h"
#include "menus/rep_0398.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"

extern struct {
    /* 0x0000 */ u8 _0000[0x46F8];
    /* 0x46F8 */ s8 _46F8[4];
    /* 0x46FC */ u8 _46FC[0x472E - 0x46FC];
    /* 0x472E */ u16 _472E[6][3];
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0x55];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56[0x5D - 0x56];
    /* 0x5D */ u8 _5D;
} lbl_803C66B0;

// Main-DOL .sbss object that symbols.txt lumped into lbl_803CBCD0 (+0x8)
extern struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
} lbl_803CBCD8;

extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u16 _4;
    /* 0x6 */ u16 _6;
} *lbl_803CBBCC;

extern struct {
    /* 0x00 */ u8 _00[0x44];
    /* 0x44 */ s32 _44;
} lbl_2_bss_F410;

extern struct {
    /* 0x00 */ u8 _00[0x58];
    /* 0x58 */ u8 _58;
} lbl_2_bss_F468;

extern struct {
    /* 0x00 */ u8 _00[0xF5];
    /* 0x0F5 */ u8 _F5;
} lbl_80361B20;

extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_2_data_130C[];

extern void fn_800625A4(s32 port, s32 arg1);
extern void fn_2_1C34(u16 buttons);
extern s32 fn_2_14F8(s32 min, s32 max);
extern void fn_2_2DC(void);
extern void fn_2_328(void);

// .text:0x00011340 size:0x358
// 96.96%: the target keeps lbl_803CBCD8._0 in r0 for the whole function, adds 1 to the
// g_d_GameSettings base for PlayerPorts[1] and loads the wraparound 0 early; registers differ.
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
    } else if (pressed & 0x100) {
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
    } else if (pressed & 0x200) {
        if (lbl_803CBCD8._0 == 0 && lbl_803C66B0._5D == 0) {
            fn_2_2DC();
            fn_2_1C34(0x200);
            lbl_803CBBCC->_6 = 12;
            fn_800625A4(0, 0x24);
            lbl_803CBBCC->_4 = 3;
        }
    }
}
