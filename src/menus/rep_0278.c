#include "menus/rep_0278.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "Dolphin/pad.h"
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
    /* 0x0000 */ u8 _0000[0x46F0];
    /* 0x46F0 */ s32 _46F0;
    /* 0x46F4 */ s32 _46F4;
    /* 0x46F8 */ s8 _46F8[4];
    /* 0x46FC */ u8 _46FC[0x4700 - 0x46FC];
    /* 0x4700 */ u8 _4700[8];
    /* 0x4708 */ u8 _4708;
    /* 0x4709 */ u8 _4709[0x4712 - 0x4709];
    /* 0x4712 */ u8 _4712;
    /* 0x4713 */ u8 _4713;
    /* 0x4714 */ u8 _4714[0x4728 - 0x4714];
    /* 0x4728 */ u8 _4728;
    /* 0x4729 */ u8 _4729;
    /* 0x472A */ u8 _472A;
    /* 0x472B */ u8 _472B;
    /* 0x472C */ UnkPad0278 _472C[4];
    /* 0x4744 */ u8 _4744[0x4754 - 0x4744];
    /* 0x4754 */ u8 _4754;
    /* 0x4755 */ u8 _4755;
    /* 0x4756 */ u8 _4756;
    /* 0x4757 */ u8 _4757[0x489B - 0x4757];
    /* 0x489B */ u8 _489B[0x12];
    /* 0x48AD */ u8 _48AD[0x48AF - 0x48AD];
    /* 0x48AF */ u8 _48AF;
    /* 0x48B0 */ u8 _48B0;
    /* 0x48B1 */ u8 _48B1;
    /* 0x48B2 */ u8 _48B2;
    /* 0x48B3 */ u8 _48B3;
    /* 0x48B4 */ u8 _48B4;
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
    /* 0x6 */ u16 _6;
}* lbl_803CBBCC;

extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
}* lbl_803CC1B8;

extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u8 _4;
} lbl_803C6714;

extern struct {
    /* 0x00 */ u8 _00[0xDE];
    /* 0xDE */ u8 _DE[6];
} lbl_80361B20;

extern u8 lbl_803CBCE0;

extern struct {
    /* 0x00 */ u8 _00[0x47];
    /* 0x47 */ u8 _47;
} lbl_803C50E8;

extern struct {
    /* 0x00 */ u8 _00[0x98];
    /* 0x98 */ void* _98;
} lbl_800EF808;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
} lbl_2_bss_F410;

extern struct {
    /* 0x00 */ u8 _00[0x27];
    /* 0x27 */ u8 _27;
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
} lbl_80366158;

extern u8 lbl_803C5EA4[0x3A];
extern u8 lbl_800EFBA4[0x10];

extern void changeScene(u8, s16);
extern void fn_800625A4(s32 index, s32 value);
extern void fn_2_19F2C(void);
extern void fn_2_12988(void);
extern void initializeUnknown(void);
extern void fn_80062764(void* task);
extern s32 fn_80022B68(void);
extern s32 fn_800697B0(void);
extern void fn_8003F23C(void);
extern void fn_80062A94(void);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_2_11A0(s32 arg0);
extern void fn_2_74D8C(void);
extern void fn_2_82E58(void);
extern void fn_80062A74(void);
extern void fn_80035B50(int arg);
extern void fn_800AD054(s32 arg0, s32 arg1);
extern void fn_80021410(void);
extern void fn_800ACFB0(void* arg0);
extern void fn_80021AC8(void);

typedef struct AramEntry0278 {
    /* 0x0 */ u32 _0[4];
} AramEntry0278; // size: 0x10

extern int fn_80035838(AramEntry0278* entry, int count);

static char lbl_2_data_180[2][0x20] = { "BAT FIRST", "BAT LAST" };
static char lbl_2_data_1C0[2][0x20] = { "FL", "PC" };
static char lbl_2_data_200[4][4] = { "RR", "RL", "LR", "LL" };
static char lbl_2_data_210[2][0x20] = { "OFF", "ON" };
static char lbl_2_data_250[5][0x20] = {
    "SELECT DEBUG MENU", "HIDE CHARA SET", "STAR PLAYER SET", "KOOPA STA FLAG SET", "CHALLE LEVEL FREE SET",
};
static char lbl_2_data_2F0[8][0x20] = {
    "1P >", "COM1>", "2P >", "COM2>", "3P >", "COM3>", "4P >", "COM4>",
};
static u32 lbl_2_data_3F0[8] = { 0xFF0F, 0x880F, 0x0FFF, 0x088F, 0xF0FF, 0x808F, 0xF00F, 0x800F };
static s16 lbl_2_data_410[12] = { 0, 4, 10, 6, 2, 9, 1, 5, 11, 17, 3, 19 };
static u8 lbl_2_data_428[2][13] = {
    { 0, 2, 6, 8, 4, 10, 1, 3, 7, 5, 9, 11 },
    { 0, 6, 2, 8, 4, 10, 5, 11, 3, 9, 1, 7 },
};
static AramEntry0278 lbl_2_data_444[1] = {
    { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 },
};
static AramEntry0278 lbl_2_data_454[1] = {
    { 0x0000040B, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 },
};
static AramEntry0278 lbl_2_data_464[1] = {
    { 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8 },
};
static AramEntry0278 lbl_2_data_474[13] = {
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
static char lbl_2_data_544[7][0x20] = {
    "EXHIBITION", "CHALLENGE", "TOY FIELD", "MINI GAME", "TRAINING", "RECORD", "GAME OPTION",
};

// Nothing in the unit reads this.
static u8 lbl_2_bss_24[0x37C];
static u8 lbl_2_bss_20;

// .text:0x000027E0 size:0x3D8
void fn_2_27E0(void) {
    switch (lbl_2_bss_20) {
    case 0:
        fn_2_19F2C();
        switch (lbl_803CBBCC->_6) {
        case 8:
            lbl_2_bss_20 = 3;
            return;
        case 6:
        case 9:
        case 12:
            lbl_2_bss_20 = 12;
            return;
        case 15:
            if (lbl_8034E9A0._4756 == 0) {
                lbl_2_bss_20 = 12;
                return;
            }
        default:
            initializeUnknown();
            fn_2_1D28();
            lbl_8034E9A0._4700[0] = 0;
            lbl_8034E9A0._4700[1] = 0;
            lbl_8034E9A0._4700[2] = 0;
            lbl_8034E9A0._4700[3] = 0;
            lbl_8034E9A0._4700[4] = 0;
            lbl_8034E9A0._4700[5] = 0;
            lbl_8034E9A0._4700[6] = 0;
            lbl_8034E9A0._4700[7] = 0;
            lbl_8034E9A0._4700[0] = 1;
            if (lbl_803CBBCC->_6 != 1) {
                fn_80062764(lbl_803CC1B8);
            }
            lbl_2_bss_20++;
            break;
        }
        break;
    case 1:
        lbl_2_bss_20++;
    case 2:
        if (fn_80022B68() != 0) {
            lbl_2_bss_20++;
        }
        break;
    case 3:
        fn_2_12988();
        lbl_2_bss_20++;
        break;
    case 4:
        if (fn_800697B0() == 0) {
            lbl_2_bss_20++;
        }
        break;
    case 5:
        if (fn_80035838(lbl_2_data_444, 6) != 0) {
            lbl_2_bss_20++;
        }
        break;
    case 6:
        if (fn_80035838(lbl_2_data_454, 9) != 0) {
            lbl_2_bss_20++;
        }
        break;
    case 7:
        if (fn_80035838(lbl_2_data_464, 18) != 0) {
            lbl_2_bss_20++;
        }
        break;
    case 8:
        if (fn_80035838(lbl_2_data_474, 15) != 0) {
            if (lbl_803CBBCC->_6 == 1) {
                lbl_2_bss_20 = 11;
            } else {
                lbl_2_bss_20++;
            }
        }
        break;
    case 9:
        if (lbl_8034E9A0._48B4 != 0) {
            if (lbl_803CBCE0 == 0) {
                fn_8003F23C();
            }
            lbl_2_bss_20++;
        } else {
            lbl_2_bss_20 = 11;
        }
        break;
    case 10:
        if (lbl_803CBCE0 == 0) {
            if (lbl_803CC1B8->_10 == 1 || lbl_803CC1B8->_10 == 11) {
                lbl_803CBCE0 = 1;
                lbl_80361B20._DE[0] = 1;
                lbl_80361B20._DE[1] = 1;
                lbl_80361B20._DE[2] = 1;
                lbl_80361B20._DE[3] = 1;
                lbl_80361B20._DE[4] = 1;
                lbl_80361B20._DE[5] = 1;
                lbl_2_bss_20++;
            }
        } else {
            lbl_2_bss_20++;
        }
        break;
    case 11:
        if (lbl_803CBBCC->_6 != 6 && lbl_803C6714._4 == 0) {
            fn_800B0A5C_insertQueue(fn_80062A94, 0x1000);
        }
        lbl_803CBBCC->_4 = 0;
        lbl_2_bss_20++;
        break;
    case 12:
        fn_2_1F30();
        break;
    }
}

// .text:0x00001F30 size:0x8B0
void fn_2_1F30(void) {
    switch (lbl_803CBBCC->_4) {
    case 0:
        if (lbl_803CBBCC->_6 < 5) {
            fn_2_1A88();
        }
        fn_2_1BAC();
        memset(&lbl_8034E9A0._4712, 0, 2);
        lbl_2_bss_F410._00 = lbl_8034E9A0._4712;
        lbl_2_bss_F410._04 = lbl_8034E9A0._4713;
        g_d_GameSettings._10 = 0;
        lbl_803C66B0._00 = 0;
        memset(lbl_803C66B0._01, 0, 6);
        lbl_8034E9A0._472A = 0xFF;
        fn_2_74D8C();
        fn_800625A4(0, 0x54);
        lbl_803CBBCC->_4++;
        break;
    case 1:
        lbl_803CBBCC->_4++;
        break;
    case 2:
        fn_2_1578();
        break;
    case 5:
        if (lbl_803C66B0._55 == 0) {
            lbl_8034E9A0._4712 = lbl_2_bss_F410._00;
            lbl_8034E9A0._4713 = lbl_2_bss_F410._04;
            switch (lbl_8034E9A0._4708) {
            case 0:
                fn_80021AC8();
                fn_2_82E58();
                changeScene(3, 6);
                lbl_803CBBCC->_4 = 3;
                break;
            case 2:
            case 3:
            case 4:
                lbl_803CBBCC->_4 = 4;
                break;
            case 6:
                lbl_8034E9A0._48AF = 1;
                lbl_8034E9A0._48B1 = 1;
                changeScene(3, 6);
                lbl_803CBBCC->_4 = 8;
                break;
            case 5:
                lbl_8034E9A0._48AF = 1;
                lbl_8034E9A0._48B1 = 1;
                changeScene(3, 6);
                lbl_803CBBCC->_4 = 10;
                break;
            case 1:
                lbl_8034E9A0._4756 = 0;
                lbl_8034E9A0._48AF = 1;
                lbl_8034E9A0._48B1 = 1;
                changeScene(3, 6);
                lbl_803CBBCC->_4 = 3;
                break;
            }
            lbl_8034E9A0._472A = 0;
        }
        break;
    case 6:
        lbl_8034E9A0._48B4 = 0;
        lbl_803CBCE0 = 0;
        fn_80062A74();
        fn_80035B50(15);
        fn_80035B50(18);
        fn_80035B50(9);
        fn_80035B50(6);
        fn_800AD054(lbl_8034E9A0._46F0, lbl_8034E9A0._46F4);
        fn_2_11A0(1);
        lbl_2_bss_20 = 0;
        break;
    case 7:
        lbl_8034E9A0._472A = 0;
        fn_2_11A0(1);
        lbl_8034E9A0._48B4 = 0;
        lbl_803CBCE0 = 0;
        break;
    case 3:
        lbl_8034E9A0._4728 = g_d_GameSettings.GameModeSelected;
        lbl_8034E9A0._4729 = g_d_GameSettings._10;
        g_d_GameSettings.exhibitionMatchInd = 1;
        if (g_d_GameSettings.GameModeSelected == 0) {
            fn_2_11A0(9);
        } else if (g_d_GameSettings.GameModeSelected == 5) {
            if (lbl_803C50E8._47) {
                g_d_GameSettings._10 = 0;
                fn_2_11A0(12);
            } else {
                fn_2_11A0(15);
            }
        } else {
            fn_80062A74();
            fn_80035B50(15);
            fn_80035B50(18);
            fn_80035B50(9);
            fn_80035B50(6);
            fn_800AD054(lbl_8034E9A0._46F0, lbl_8034E9A0._46F4);
            fn_80021410();
            fn_800ACFB0(lbl_800EF808._98);
            fn_2_11A0(4);
        }
        lbl_2_bss_20 = 0;
        break;
    case 4:
        lbl_8034E9A0._48AF = 1;
        lbl_8034E9A0._48B1 = 1;
        lbl_803CBBCC->_4 = 3;
        break;
    case 8:
        fn_2_11A0(6);
        lbl_2_bss_20 = 0;
        break;
    case 9:
        fn_80062A74();
        fn_80035B50(15);
        fn_80035B50(18);
        fn_80035B50(9);
        fn_80035B50(6);
        fn_800AD054(lbl_8034E9A0._46F0, lbl_8034E9A0._46F4);
        fn_80021410();
        fn_800ACFB0(lbl_800EF808._98);
        fn_2_11A0(7);
        lbl_2_bss_20 = 0;
        break;
    case 10:
        fn_80035B50(15);
        fn_80035B50(18);
        fn_80035B50(9);
        fn_80035B50(6);
        fn_800AD054(lbl_8034E9A0._46F0, lbl_8034E9A0._46F4);
        fn_2_11A0(8);
        lbl_2_bss_20 = 0;
        break;
    }
}

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

// .text:0x00001800 size:0x288
void fn_2_1800(void) {
    UnkPad0278 pad;

    memset(&pad, 0, sizeof(pad));
    pad._0 = lbl_8034E9A0._472C[0]._0;
    pad._2 = lbl_8034E9A0._472C[0]._2;
    pad._4 = lbl_8034E9A0._472C[0]._4;
    if (lbl_803C66B0._55 != 0) {
        return;
    }
    if (pad._2 & PAD_BUTTON_A) {
        fn_2_1DC8();
        lbl_80366158._27 = 0;
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    } else if (pad._2 & PAD_BUTTON_B) {
        lbl_80366158._29 = 2;
        lbl_8034E9A0._472A = 0;
        lbl_803CBBCC->_4 = 6;
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
    } else if ((pad._4 & PAD_BUTTON_UP) || (pad._4 & PAD_BUTTON_DOWN)) {
        lbl_2_bss_F410._04 = lbl_2_bss_F410._00;
        fn_2_1D54(&lbl_2_bss_F410._00, 0, 7);
        fn_800625A4(0, 0x56);
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    }
}

// .text:0x00001578 size:0x288
void fn_2_1578(void) {
    UnkPad0278 pad;

    memset(&pad, 0, sizeof(pad));
    pad._0 = lbl_8034E9A0._472C[0]._0;
    pad._2 = lbl_8034E9A0._472C[0]._2;
    pad._4 = lbl_8034E9A0._472C[0]._4;
    if (lbl_803C66B0._55 != 0) {
        return;
    }
    if (pad._2 & PAD_BUTTON_A) {
        fn_2_1DC8();
        lbl_80366158._27 = 0;
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    } else if (pad._2 & PAD_BUTTON_B) {
        lbl_80366158._29 = 2;
        lbl_8034E9A0._472A = 0;
        lbl_803CBBCC->_4 = 6;
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
    } else if ((pad._4 & PAD_BUTTON_UP) || (pad._4 & PAD_BUTTON_DOWN)) {
        lbl_2_bss_F410._04 = lbl_2_bss_F410._00;
        fn_2_1D54(&lbl_2_bss_F410._00, 0, 7);
        fn_800625A4(0, 0x56);
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    }
}
