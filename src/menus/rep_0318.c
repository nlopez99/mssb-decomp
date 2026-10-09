#include "menus/rep_0318.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "string.h"

extern void fn_800625A4(s32 port, s32 arg1);
extern void fn_800203E0(int, s8);
extern void sndFXRelated(s32 arg0);
extern s16 randRange_FUN_80042bf0(s32 min, s32 max);
extern void fn_2_16A74(s32 arg0, s32 arg1);

typedef struct Menu0318 {
    /* 0x000 */ s32 _00[2];
    /* 0x008 */ u8 _08[0x10 - 0x8];
    /* 0x010 */ s32 _10[2];
    /* 0x018 */ u8 _18[0x2E - 0x18];
    /* 0x02E */ u8 _2E;
    /* 0x02F */ s8 _2F[2];
    /* 0x031 */ u8 _31[0x45 - 0x31];
    /* 0x045 */ u8 _45[2];
    /* 0x047 */ u8 _47[0x4F - 0x47];
    /* 0x04F */ u8 _4F;
    /* 0x050 */ u8 _50[0x56 - 0x50];
    /* 0x056 */ u8 _56;
    /* 0x057 */ u8 _57[0xC4C - 0x57];
} Menu0318; // size: 0xC4C

extern Menu0318 lbl_2_bss_F468;
extern u8 lbl_2_bss_100B4;
extern struct {
    /* 0x00 */ u8 _00[0x2D];
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E[0x54 - 0x2E];
} lbl_2_bss_100B8;
extern u8 lbl_2_data_3CE0[8];

extern struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ s16 _4;
    /* 0x06 */ u16 _6;
}* lbl_803CBBCC;
extern struct {
    /* 0x0000 */ u8 _0000[0x46E0];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x4755 - 0x46E8];
    /* 0x4755 */ u8 _4755;
    /* 0x4756 */ u8 _4756;
    /* 0x4757 */ u8 _4757[0x36];
} lbl_8034E9A0;
extern struct {
    /* 0x00 */ u8 _00[0x2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ s8 _14[2][9];
    /* 0x26 */ s8 _26[2][9];
    /* 0x38 */ u8 _38[0x4A - 0x38];
    /* 0x4A */ s8 _4A[9];
    /* 0x53 */ s8 _53[9];
} lbl_803C6724;
typedef struct Slot0318 {
    /* 0x0 */ s8 _0;
    /* 0x1 */ s8 _1;
    /* 0x2 */ s8 _2;
    /* 0x3 */ s8 _3;
} Slot0318;
extern Slot0318 lbl_80354720[2][9];
extern u8 lbl_80109038[9];
extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
} lbl_8037169C;
extern struct {
    /* 0x0000 */ u8 _0000[0xCF5F];
    /* 0xCF5F */ u8 _CF5F;
} lbl_803297E0;

typedef struct AramEntry0318 {
    /* 0x0 */ u32 _0[4];
} AramEntry0318; // size: 0x10

static char lbl_2_data_720[2][0x20] = { "BAT FIRST", "BAT LAST" };
static char lbl_2_data_760[2][0x20] = { "FL", "PC" };
static char lbl_2_data_7A0[4][4] = { "RR", "RL", "LR", "LL" };
static char lbl_2_data_7B0[2][0x20] = { "OFF", "ON" };
static char lbl_2_data_7F0[5][0x20] = {
    "SELECT DEBUG MENU", "HIDE CHARA SET", "STAR PLAYER SET", "KOOPA STA FLAG SET", "CHALLE LEVEL FREE SET",
};
static char lbl_2_data_890[8][0x20] = {
    "1P >", "COM1>", "2P >", "COM2>", "3P >", "COM3>", "4P >", "COM4>",
};
static u32 lbl_2_data_990[8] = { 0xFF0F, 0x880F, 0x0FFF, 0x088F, 0xF0FF, 0x808F, 0xF00F, 0x800F };
static s16 lbl_2_data_9B0[12] = { 0, 4, 10, 6, 2, 9, 1, 5, 11, 17, 3, 19 };
static u8 lbl_2_data_9C8[2][13] = {
    { 0, 2, 6, 8, 4, 10, 1, 3, 7, 5, 9, 11 },
    { 0, 6, 2, 8, 4, 10, 5, 11, 3, 9, 1, 7 },
};
static char lbl_2_data_9E4[8][0x20] = {
    "BATTING", "DEFENCE", "RUN", "FALL", "BATTING_2", "DEFENCE_2", "RUN_2", "FALL_2",
};
static char lbl_2_data_AE4[5][0x20] = {
    "ONE   INNING", "THREE INNING", "FIVE  INNING", "SEVEN INNING", "NINE  INNING",
};
static char lbl_2_data_B84[2][0x20] = { "OFF", "ON" };
static char lbl_2_data_BC4[2][0x20] = { "MANUAL", "AUTO" };
static char lbl_2_data_C04[2][0x20] = { "NO", "YES" };
static char lbl_2_data_C44[2][0x20] = { "NORMAL", "EASY" };
static char lbl_2_data_C84[2][8] = { "FIRST", "LAST" };
static char lbl_2_data_C94[4][0x20] = {
    "EASY      MODE", "NORMAL    MODE", "HARD      MODE", "VERY HARD MODE",
};
static AramEntry0318 lbl_2_data_D14[16] = {
    { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 },
    { 0x0000040B, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 },
    { 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8 },
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
static u8 lbl_2_data_E14[40] = {
    2, 5, 4, 3, 8, 3, 4, 5, 2, 6, 0, 1, 8, 6, 7, 1, 2, 0, 7, 4,
    4, 3, 1, 2, 5, 1, 2, 4, 6, 8, 7, 6, 8, 5, 3, 3, 5, 7, 4, 6,
};
static char* lbl_2_data_E3C[10] = { "P", "C", "1B", "2B", "3B", "SS", "LF", "CF", "RF", "  ?  " };
s16 lbl_2_data_E64[18] = { 33, 11, 14, 10, 9, 19, 37, 40, 16, 3, 6, 20, 2, 13, 12, 7, 28, 41 };
s16 lbl_2_data_E88[18] = { 0, 1, 4, 5, 6, 13, 12, 21, 24, 10, 11, 2, 3, 17, 40, 20, 16, 14 };

// .text:0x0000EC34 size:0x20
void fn_2_EC34(void) {
    if (lbl_2_bss_F468._56 == 0) {
        lbl_2_bss_F468._56 = 1;
    }
}

// .text:0x0000CCBC size:0x24
void fn_2_CCBC(void) {
    fn_2_7DDC();
    fn_2_7504();
}

// .text:0x0000A62C size:0xB4
s32 fn_2_A62C(void) {
    s32 i;
    s32 j;
    s32 id;

    for (i = 0; i < 9; i++) {
        id = lbl_803C6724._02[0][i];
        for (j = 0; j < 9; j++) {
            if (id == lbl_803C6724._02[1][j] && id != 0xFF) {
                return 1;
            }
        }
    }
    return 0;
}

// .text:0x00009F70 size:0xD0
s32 fn_2_9F70(s8 port) {
    s32 ret;
    s32 i;
    s32 j;
    s8 team = lbl_2_bss_F468._2F[port];
    s8 other = lbl_2_bss_F468._2F[port ^ 1];

    switch (lbl_2_bss_F468._10[team]) {
    case 1:
        ret = 2;
        break;
    case 2:
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    }
retry:
    for (i = 0; i < 9; i++) {
        u8 id = inMemRoster[other][i].stats.CharID;
        for (j = 0; j < 9; j++) {
            if (id == 0) {
                if (ret == 1 || ret == 2) {
                    return 3;
                }
                ret = 2;
                goto retry;
            }
        }
    }
    return ret;
}

// .text:0x0000893C size:0x4
void fn_2_893C(void) {}

// .text:0x00008794 size:0x14
s32 fn_2_8794(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        arg1 += 10;
    }
    return arg1;
}

// .text:0x00008780 size:0x14
s32 fn_2_8780(s32 arg0) {
    s32 ret = 9;
    if (arg0 != 0) {
        ret = 19;
    }
    return ret;
}

// .text:0x000086EC size:0x94
void fn_2_86EC(void) {
    if (g_d_GameSettings.GameModeSelected == 5 && lbl_8037169C._12 == 0) {
        fn_800203E0(10, lbl_2_data_3CE0[starMissionCompletionTracker._441E]);
    }
    fn_2_7DDC();
    fn_2_7504();
    lbl_2_bss_F468._56 = 0;
    lbl_803CBBCC->_4 = 2;
}

// .text:0x00007D44 size:0x98
void fn_2_7D44(void) {
    if (lbl_803CBBCC->_6 == 9) {
        memset(&lbl_2_bss_100B8, 0, sizeof(lbl_2_bss_100B8));
    }
    lbl_8034E9A0._4755 = 1;
    lbl_2_bss_100B8._2D = 4;
    fn_2_16A74(0, 0);
    fn_2_16A74(1, 0);
    fn_2_16A74(2, 0);
    fn_2_16A74(3, 0);
}

// .text:0x00006784 size:0x100
void fn_2_6784(void) {
    s32 i;
    s32 j;
    u8 found;
    u8 id;

    for (i = 0; i < 9; i++) {
        if (i == 0) {
            lbl_8034E9A0._46E0[1] = 0;
            lbl_803C6724._02[1][0] = 0;
            lbl_803C6724._53[0] = 1;
            lbl_8034E9A0._4757[lbl_803C6724._02[1][0]] = 1;
        } else {
            do {
                found = 0;
                id = lbl_80109038[randRange_FUN_80042bf0(0, 9)];
                for (j = 0; j < i; j++) {
                    if (lbl_803C6724._02[1][j] == id) {
                        found = 1;
                    }
                }
            } while (found);
            lbl_803C6724._02[1][i] = id;
            lbl_803C6724._53[i] = 1;
            lbl_8034E9A0._4757[id] = 1;
        }
        lbl_80354720[1][i]._0 = i;
        lbl_80354720[1][i]._2 = i;
        lbl_80354720[1][i]._1 = i;
    }
}

// .text:0x00006138 size:0x68
void fn_2_6138(void) {
    fn_800625A4(0, 0x13);
    fn_800625A4(1, 0x13);
    lbl_2_bss_F468._4F = 0;
    lbl_2_bss_F468._2E = 0;
    lbl_2_bss_100B4 = 1;
    lbl_803CBBCC->_4 = 8;
}

// .text:0x000060D4 size:0x64
s32 fn_2_60D4(u8 port) {
    if (g_d_GameSettings.GameModeSelected != 5) {
        return lbl_8034E9A0._46E0[port];
    }
    if (port != 0) {
        return lbl_8034E9A0._46E0[port];
    }
    return lbl_8034E9A0._46E0[port];
}

// .text:0x00006098 size:0x3C
void fn_2_6098(u8 port) {
    lbl_2_bss_F468._00[port] = 9;
    fn_800625A4(port, 0x17);
}

// .text:0x00005F80 size:0x118
void fn_2_5F80(void) {
    s32 t;
    s32 i;
    s32 j;

    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (lbl_80354720[t][i]._2 == lbl_80354720[t][j]._2) {
                    lbl_803C6724._02[t][i] = inMemRoster[t][j].stats.CharID;
                }
            }
            lbl_803C6724._14[t][i] = i;
        }
    }
}

// .text:0x000057E8 size:0x8
s32 fn_2_57E8(s32 arg0, s32 arg1) {
    return (s8)arg1;
}

// .text:0x000035D0 size:0x54
s32 fn_2_35D0(u8 port) {
    if (lbl_2_bss_F468._45[port] != 0) {
        lbl_2_bss_F468._45[port] = 0;
        sndFXRelated(0x200);
        return 1;
    }
    return 0;
}

// .text:0x000033BC size:0xD0
s32 fn_2_33BC(void) {
    s32 ret = 1;
    s32 i;

    for (i = 1; i < 9; i++) {
        if (starMissionCompletionTracker._40B8[0]._3 == starMissionCompletionTracker._40B8[i]._3) {
            ret = 0;
        }
    }
    return ret;
}

// .text:0x00003204 size:0x38
void fn_2_3204(void) {
    fn_2_2FC0(lbl_803297E0._CF5F, 1, 1);
}
