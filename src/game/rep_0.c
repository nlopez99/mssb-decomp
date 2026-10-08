#include "game/rep_0.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1E08.h"
#include "game/rep_D18.h"
#include "Dolphin/pad.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u32 _00[4];
} UnkAramEntry0; // size: 0x10

typedef struct {
    /* 0x0 */ u8 index;
    /* 0x1 */ u8 slot;
    /* 0x2 */ u8 value;
    /* 0x3 */ u8 found;
} UnkSlot0; // size: 0x4

typedef struct {
    /* 0x0 */ u8 loadState;
    /* 0x1 */ u8 option;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 menuState;
    /* 0x4 */ u8 _4[4];
} UnkMenu0; // size: 0x8

extern struct {
    /* 0x00 */ void (*callback)(void);
}* lbl_803CC1B8;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern UnkSlot0 lbl_80354720[2][9];

extern void* ARAMTransfer(UnkAramEntry0* entry, int arg1, int arg2, u32 aram);
extern void fn_80036C88(u32* arg0, u32* arg1);
extern void fn_8004B270(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0D28(u32* arg0);
extern void fn_800BF038(int arg0);
extern void fn_3_C0824(void);

UnkAramEntry0 lbl_3_data_0 = { { 0x00000000, 0x000046E0, 0x06CF8800, 0x000046E0 } };
char lbl_3_data_10[12][22] = {
    "Yokohama Stadium    ", "Tokyo Dome          ", "Nagoya Dome         ", "Kousien Stadium     ",
    "Hirosima Stadium    ", "Jingu Stadium       ", "Green Stadium Kobe  ", "Osaka Dome          ",
    "Seibu Dome          ", "Fukuoka Dome        ", "Chiba Marine Stadium", "Sapporo Dome        ",
};
u32 lbl_3_data_118[2][23] = {
    { 0x1040, 0, 0, 0x1880, 0x1C40, 0x65A0, 0x6B20, 0x2E40, 0, 0xFA0, 0, 0, 0, 0x940, 0x1000, 0x560, 0xBE0 },
    { 0 },
};

static UnkMenu0 lbl_3_bss_10;
static u8 lbl_3_bss_8[8];
static CharacterStats (*lbl_3_bss_4)[PLAYERS_PER_TEAM];
static u32 lbl_3_bss_0;

// .text:0x0000049C size:0x58 mapped:0x8063F530
void _prolog(void) {
    fn_800B0A5C_insertQueue(fn_3_5AE9C, 1);
    fn_3_C0824();
    fn_80036C88(lbl_3_data_118[0], lbl_3_data_118[1]);
    fn_800B0D28(lbl_3_data_118[1]);
    fn_8004B270();
}

// .text:0x00000464 size:0x38 mapped:0x8063F4F8
void _epilog(void) {
    g_d_GameSettings._55 = 0;
    fn_800BF038(0);
    fn_3_BF20C();
}

// .text:0x00000258 size:0x20C mapped:0x8063F2EC
void fn_3_258(void) {
    if (lbl_3_bss_10.menuState == 0) {
        if ((lbl_803C77B8[0]._04 & PAD_BUTTON_UP) && lbl_3_bss_10.option != 0) {
            lbl_3_bss_10.option--;
        }
        if ((lbl_803C77B8[0]._04 & PAD_BUTTON_DOWN) && lbl_3_bss_10.option < 1) {
            lbl_3_bss_10.option++;
        }
        if (lbl_803C77B8[0]._04 & PAD_BUTTON_A) {
            lbl_3_bss_10.menuState = 1;
        }
    } else if (lbl_3_bss_10.menuState == 1 && lbl_3_bss_10.option == 0) {
        if ((lbl_803C77B8[0]._04 & PAD_BUTTON_UP) && lbl_3_bss_10._2 != 0) {
            lbl_3_bss_10._2--;
        }
        if ((lbl_803C77B8[0]._04 & PAD_BUTTON_DOWN) && lbl_3_bss_10._2 < 3) {
            lbl_3_bss_10._2++;
        }
        if (lbl_803C77B8[0]._04 & PAD_BUTTON_A) {
            lbl_3_bss_10.menuState = 3;
        }
        if (lbl_803C77B8[0]._04 & PAD_BUTTON_B) {
            lbl_3_bss_10.menuState = 0;
        }
    } else if (lbl_3_bss_10.menuState == 1 && lbl_3_bss_10.option == 1) {
        g_d_GameSettings.GameModeSelected = GAME_TYPE_PRACTICE;
        lbl_803CC1B8->callback = maybeProcessTeamData;
    } else if (lbl_3_bss_10.menuState == 2) {
    } else if (lbl_3_bss_10.menuState == 3) {
        if ((lbl_803C77B8[0]._04 & PAD_BUTTON_LEFT) && g_d_GameSettings.StadiumID != 0) {
            g_d_GameSettings.StadiumID--;
        }
        if ((lbl_803C77B8[0]._04 & PAD_BUTTON_RIGHT) && g_d_GameSettings.StadiumID < 10) {
            g_d_GameSettings.StadiumID++;
        }
        if (lbl_803C77B8[0]._04 & PAD_BUTTON_A) {
            lbl_3_bss_10.menuState = 4;
        }
        if (lbl_803C77B8[0]._04 & PAD_BUTTON_B) {
            lbl_3_bss_10.menuState = 1;
        }
    } else if (lbl_3_bss_10.menuState == 4) {
        g_d_GameSettings.GameModeSelected = GAME_TYPE_EXHIBITION_GAME;
        g_d_GameSettings._10 = lbl_3_bss_10._2;
        lbl_803CC1B8->callback = maybeProcessTeamData;
    }
}

// .text:0x00000000 size:0x258 mapped:0x8063F094
void maybeProcessTeamData(void) {
    int teams[2];
    u8* order;
    int i;
    int j;
    int t;

    teams[0] = g_d_GameSettings.maybeHomeAway;
    teams[1] = g_d_GameSettings.maybeHomeAway2;
    switch (lbl_3_bss_10.loadState) {
    case 0:
        lbl_3_bss_4 = ARAMTransfer(&lbl_3_data_0, 0, 1, 0);
        lbl_3_bss_10.loadState++;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            lbl_3_bss_10.loadState++;
        }
        break;
    case 2:
        memcpy(inMemRoster[0], lbl_3_bss_4[teams[0]], sizeof(inMemRoster[0]));
        memcpy(inMemRoster[1], lbl_3_bss_4[teams[1]], sizeof(inMemRoster[1]));
        lbl_3_bss_10.loadState++;
        break;
    case 3:
        for (t = 0; t < 2; t++) {
            order = (u8*)lbl_3_bss_4 + 0x4380 + teams[t] * 0x48;
            for (i = 0; i < 9; i++) {
                lbl_80354720[t][i].index = i;
                lbl_80354720[t][i].slot = 10;
                lbl_80354720[t][i].value = 10;
                lbl_80354720[t][i].found = 0;
                for (j = 0; j < 9; j++) {
                    if (i == order[j]) {
                        break;
                    }
                }
                if (j < 9) {
                    lbl_80354720[t][i].slot = j;
                    lbl_80354720[t][i].value = order[j + 9];
                    lbl_80354720[t][i].found = 1;
                }
            }
        }
        lbl_3_bss_10.loadState++;
        break;
    }
}
