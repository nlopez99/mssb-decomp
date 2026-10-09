#include "menus/rep_0278.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "string.h"

typedef struct {
    /* 0x0 */ u16 _0;
    /* 0x2 */ u16 _2;
    /* 0x4 */ u16 _4;
} UnkPad0278; // size: 0x6

extern struct {
    /* 0x00 */ u8 _00[0x28];
} lbl_8034E978;

extern struct {
    /* 0x0000 */ u8 _0000[0x46F8];
    /* 0x46F8 */ s8 _46F8[4];
    /* 0x46FC */ u8 _46FC[0x4708 - 0x46FC];
    /* 0x4708 */ u8 _4708;
    /* 0x4709 */ u8 _4709[0x472A - 0x4709];
    /* 0x472A */ u8 _472A;
    /* 0x472B */ u8 _472B;
    /* 0x472C */ UnkPad0278 _472C[4];
    /* 0x4744 */ u8 _4744[0x4754 - 0x4744];
    /* 0x4754 */ u8 _4754;
    /* 0x4755 */ u8 _4755;
    /* 0x4756 */ u8 _4756;
    /* 0x4757 */ u8 _4757[0x489B - 0x4757];
    /* 0x489B */ u8 _489B[0x12];
    /* 0x48AD */ u8 _48AD[0x48B3 - 0x48AD];
    /* 0x48B3 */ u8 _48B3;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x54];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
} lbl_803C66B0;

extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u16 _4;
}* lbl_803CBBCC;

extern struct {
    /* 0x00 */ s32 _00;
} lbl_2_bss_F410;

extern u8 lbl_803C5EA4[0x3A];
extern u8 lbl_800EFBA4[0x10];

extern void changeScene(u8, s16);
extern void fn_800625A4(s32 index, s32 value);

// .text:0x00001DC8 size:0x168
void fn_2_1DC8(void) {
    switch (lbl_2_bss_F410._00) {
    case 0:
        lbl_8034E9A0._4708 = 0;
        g_d_GameSettings.GameModeSelected = 0;
        break;
    case 1:
        lbl_8034E9A0._4708 = 1;
        g_d_GameSettings.GameModeSelected = 5;
        break;
    case 3:
        lbl_8034E9A0._4708 = 3;
        g_d_GameSettings.GameModeSelected = 7;
        changeScene(4, 6);
        break;
    case 2:
        lbl_8034E9A0._4708 = 2;
        g_d_GameSettings.GameModeSelected = 6;
        changeScene(4, 6);
        break;
    case 4:
        lbl_8034E9A0._4708 = 4;
        g_d_GameSettings.GameModeSelected = 2;
        g_d_GameSettings.StadiumID = 0;
        g_d_GameSettings.miniGameStadiumIndicator = 2;
        changeScene(4, 6);
        break;
    case 6:
        lbl_8034E9A0._4708 = 6;
        break;
    case 5:
        lbl_8034E9A0._4708 = 5;
        break;
    }
    lbl_803CBBCC->_4 = 5;
    fn_800625A4(0, 0x58);
}

// .text:0x00001DC4 size:0x4
void fn_2_1DC4(void) {}

// .text:0x00001D54 size:0x70
void fn_2_1D54(s32* cursor, u8 port, s32 count) {
    u16 buttons = lbl_8034E9A0._472C[port]._4;

    if (buttons & 8) {
        (*cursor)--;
        if (*cursor < 0) {
            *cursor = count - 1;
        }
    } else if (buttons & 4) {
        (*cursor)++;
        if (*cursor == count) {
            *cursor = 0;
        }
    }
}

// .text:0x00001D28 size:0x2C
void fn_2_1D28(void) {
    lbl_8034E9A0._472A = 0xFF;
    lbl_8034E9A0._4756 = 0;
    lbl_8034E9A0._4754 = 0;
    lbl_8034E9A0._4755 = 3;
    lbl_8034E9A0._48B3 = 0;
}

// .text:0x00001C34 size:0xF4
void fn_2_1C34(u16 buttons) {
    switch (buttons) {
    case 0x100:
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        break;
    case 0x200:
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        break;
    case 1:
    case 2:
    case 4:
    case 8:
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        break;
    case 3:
    case 0x20:
    case 0x40:
    case 0x400:
    case 0x800:
        break;
    }
}

// .text:0x00001BAC size:0x88
void fn_2_1BAC(void) {
    memset(lbl_803C66B0._01, 0, sizeof(lbl_803C66B0._01));
    lbl_803C66B0._56 = 0;
    lbl_803C66B0._55 = 0;
    memset(lbl_803C5EA4, 0, sizeof(lbl_803C5EA4));
    memset(lbl_8034E9A0._489B, 0, sizeof(lbl_8034E9A0._489B));
    memset(&lbl_8034E978, 0, sizeof(lbl_8034E978));
}

// .text:0x00001A88 size:0x124
void fn_2_1A88(void) {
    s32 i;
    s32 n;

    lbl_8034E9A0._46F8[0] = 0;
    n = 1;
    for (i = 1; i < 4; i++) {
        if (lbl_803C77B8[i]._08 != -1) {
            lbl_8034E9A0._46F8[n++] = i;
        }
    }
    while (n < 4) {
        lbl_8034E9A0._46F8[n++] = -1;
    }
}
