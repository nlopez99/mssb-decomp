#include "menus/rep_05F0.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "musyx/musyx.h"

extern void changeScene(u8, s16);
extern void fn_2_19F2C(void);
extern void fn_2_11A0(s32 arg0);

typedef struct MenuTask05F0 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
} MenuTask05F0;

extern MenuTask05F0* lbl_803CC1B8;

// Debug menu labels and tables that no code in the module reads
typedef struct DebugMenu05F0 {
    /* 0x000 */ char _000[4][0x20];
    /* 0x080 */ char _080[4][4];
    /* 0x090 */ char _090[15][0x20];
    /* 0x270 */ u32 _270[8];
    /* 0x290 */ s16 _290[12];
    /* 0x2A8 */ u8 _2A8[0x1C];
} DebugMenu05F0; // size: 0x2C4

DebugMenu05F0 lbl_2_data_2B78 = {
    { "BAT FIRST", "BAT LAST", "FL", "PC" },
    { "RR", "RL", "LR", "LL" },
    {
        "OFF",
        "ON",
        "SELECT DEBUG MENU",
        "HIDE CHARA SET",
        "STAR PLAYER SET",
        "KOOPA STA FLAG SET",
        "CHALLE LEVEL FREE SET",
        "1P >",
        "COM1>",
        "2P >",
        "COM2>",
        "3P >",
        "COM3>",
        "4P >",
        "COM4>",
    },
    { 0xFF0F, 0x880F, 0x0FFF, 0x088F, 0xF0FF, 0x808F, 0xF00F, 0x800F },
    { 0, 4, 10, 6, 2, 9, 1, 5, 11, 17, 3, 19 },
    { 0, 2, 6, 8, 4, 10, 1, 3, 7, 5, 9, 11, 0, 0, 6, 2, 8, 4, 10, 5, 11, 3, 9, 1, 7 },
};
GXColor lbl_2_data_2E3C = { 0 };

s32 lbl_2_bss_1598;

// .text:0x0001A1B4 size:0xF8
void fn_2_1A1B4(void) {
    MenuTask05F0* task = lbl_803CC1B8;

    switch (lbl_2_bss_1598) {
    case 0:
        fn_2_19F2C();
        task->_10 = 0;
        GXSetCopyClear(lbl_2_data_2E3C, 0xFFFFFF);
        lbl_2_bss_1598 = 1;
        break;
    case 1:
        sndVolume(127, 10, 255);
        lbl_2_bss_1598 = 4;
        break;
    case 2:
        lbl_2_bss_1598 = 4;
        break;
    case 4:
        changeScene(3, 6);
        if (g_d_GameSettings.GameModeSelected != 5) {
            fn_2_11A0(5);
        } else {
            fn_2_11A0(16);
        }
        break;
    }
}
