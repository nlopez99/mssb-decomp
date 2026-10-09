#include "menus/rep_0318.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "string.h"

extern void fn_800625A4(s32 port, s32 arg1);
extern void fn_800506E8(s32 port, s32 charID, s32 arg2);
extern s32 fn_80067B40(u8 team, u8 charID, s32 arg2);
extern void fn_800670A0(u8 team);
extern void fn_80050138(s32 arg0, s32 c0, s32 c1, s32 c2, s32 c3, s32 arg5);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void fn_8004D0F0(void);
extern s32 fn_8004CA6C(u16 buttons);
extern void fn_8004CC2C(void);
extern void changeScene(u8, s16);
extern void fn_800678CC(s32 team);
extern void unsure_FillRosterPositions(u8 team);
extern void characterSelectScreen(s32 team);
extern void fn_80067F70(s32 team);
extern void fn_800684A4(void);
extern void fn_800671FC(void);
extern void fn_800649BC(void);
extern void fn_80069854(void);
extern void fn_2_72630(void);
extern void fn_800203E0(int, s8);
extern void sndFXRelated(s32 arg0);
extern s32 randRange_FUN_80042bf0(s32 min, s32 max);
extern void fn_2_16A74(s32 arg0, s32 arg1);
extern void fn_2_1C34(u16 buttons);
extern s32 fn_2_14F8(s32 min, s32 max);

extern struct {
    /* 0x00 */ u8 _00[0x24];
    /* 0x24 */ s16 CharID;
    /* 0x26 */ u8 _26[0xA0 - 0x26];
} inMemRoster[2][9];
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
    /* 0x441E */ u8 _441E;
    /* 0x441F */ u8 _441F;
} starMissionCompletionTracker;
extern struct {
    /* 0x0 */ u8 _0[3];
    /* 0x3 */ u8 _3;
} gameInitOptions;

typedef struct Menu0318 {
    /* 0x000 */ s32 _00[2];
    /* 0x008 */ s32 _08[2];
    /* 0x010 */ s32 _10[2];
    /* 0x018 */ u8 _18[0x2E - 0x18];
    /* 0x02E */ u8 _2E;
    /* 0x02F */ s8 _2F[2];
    /* 0x031 */ u8 _31[0x33 - 0x31];
    /* 0x033 */ u8 _33;
    /* 0x034 */ u8 _34;
    /* 0x035 */ u8 _35;
    /* 0x036 */ s8 _36;
    /* 0x037 */ u8 _37[2];
    /* 0x039 */ u8 _39[2];
    /* 0x03B */ u8 _3B[2];
    /* 0x03D */ u8 _3D[2];
    /* 0x03F */ u8 _3F[0x41 - 0x3F];
    /* 0x041 */ u8 _41[2];
    /* 0x043 */ u8 _43[2];
    /* 0x045 */ u8 _45[2];
    /* 0x047 */ u8 _47[0x4F - 0x47];
    /* 0x04F */ u8 _4F;
    /* 0x050 */ u8 _50[0x56 - 0x50];
    /* 0x056 */ u8 _56;
    /* 0x057 */ u8 _57[0x59 - 0x57];
    /* 0x059 */ u8 _59[2];
    /* 0x05B */ u8 _5B[0xC4C - 0x5B];
} Menu0318; // size: 0xC4C

extern Menu0318 lbl_2_bss_F468;
extern u8 lbl_2_bss_100B4;
extern struct {
    /* 0x00 */ u8 _00[0x20];
    /* 0x20 */ s32 _20[2];
    /* 0x28 */ u8 _28[0x4C - 0x28];
    /* 0x4C */ s32 _4C;
    /* 0x50 */ u8 _50[0x58 - 0x50];
} lbl_2_bss_F410;
extern struct {
    /* 0x00 */ u8 _00[0x2D];
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E[2];
    /* 0x30 */ u8 _30[2];
    /* 0x32 */ u8 _32[0x54 - 0x32];
} lbl_2_bss_100B8;
extern u8 lbl_2_data_3CE0[8];

extern struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ u16 _4;
    /* 0x06 */ u16 _6;
}* lbl_803CBBCC;
typedef struct CharEntry0318 {
    /* 0x00 */ u8 _00[0x3B];
    /* 0x3B */ u8 _3B[0x36];
    /* 0x71 */ u8 _71[0xA0 - 0x71];
} CharEntry0318; // size: 0xA0

extern struct {
    /* 0x0000 */ CharEntry0318 _0000[6][9];
    /* 0x21C0 */ u8 _21C0[0x46E0 - 0x21C0];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x46F8 - 0x46E8];
    /* 0x46F8 */ s8 _46F8[2];
    /* 0x46FA */ u8 _46FA[0x472A - 0x46FA];
    /* 0x472A */ u8 _472A;
    /* 0x472B */ u8 _472B[0x472E - 0x472B];
    /* 0x472E */ u16 _472E[6][3];
    /* 0x4752 */ u8 _4752[0x4755 - 0x4752];
    /* 0x4755 */ u8 _4755;
    /* 0x4756 */ u8 _4756;
    /* 0x4757 */ u8 _4757[0x36];
} lbl_8034E9A0;
extern struct {
    /* 0x00 */ u8 _00[0x2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ s8 _14[2][9];
    /* 0x26 */ s8 _26[2][9];
    /* 0x38 */ s8 _38[2][9];
    /* 0x4A */ s8 _4A[2][9];
} lbl_803C6724;
typedef struct Slot0318 {
    /* 0x0 */ s8 _0;
    /* 0x1 */ s8 _1;
    /* 0x2 */ s8 _2;
    /* 0x3 */ s8 _3;
} Slot0318;
extern Slot0318 lbl_80354720[2][9];
extern Slot0318 lbl_80353B98[2][9];
extern u8 lbl_80109038[9];
extern u8 lbl_803CB748[6];
extern s16 lbl_80108EDC[28][5];
extern u8 lbl_800FDE84[];
extern struct {
    /* 0x00 */ u8 _00[0x55];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[0x59 - 0x57];
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A[0x5D - 0x5A];
    /* 0x5D */ u8 _5D;
    /* 0x5E */ u8 _5E;
    /* 0x5F */ u8 _5F[0x64 - 0x5F];
} lbl_803C66B0;
extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A[0xE - 0xA];
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F[0x3C - 0xF];
} lbl_803C5EA4;
extern struct {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
} lbl_803CBD24;
extern u8 lbl_803CB8D0[8];
extern struct {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3[3];
} lbl_800E8558[54];
extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
} lbl_8037169C;
extern struct {
    /* 0x0000 */ u8 _0000[0xCF5F];
    /* 0xCF5F */ u8 _CF5F;
    /* 0xCF60 */ u8 _CF60[0xCFA1 - 0xCF60];
    /* 0xCFA1 */ u8 _CFA1;
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
s16 lbl_2_data_E64[2][9] = {
    { 33, 11, 14, 10, 9, 19, 37, 40, 16 },
    { 3, 6, 20, 2, 13, 12, 7, 28, 41 },
};
s16 lbl_2_data_E88[2][9] = {
    { 0, 1, 4, 5, 6, 13, 12, 21, 24 },
    { 10, 11, 2, 3, 17, 40, 20, 16, 14 },
};

static u8 lbl_2_bss_3A0;

// .text:0x000110B0 size:0x244
// Inlines fn_2_323C, which the target calls; it pairs once fn_2_323C counts
// about four more statements (four dead-store blocks there match it).
void fn_2_110B0(void) {
    switch (lbl_803CBBCC->_4) {
    case 0:
        if (g_d_GameSettings.GameModeSelected == 5 || lbl_803CBBCC->_6 != 9) {
            lbl_803CBBCC->_4 = 5;
        } else {
            lbl_803297E0._CFA1 = 0;
            lbl_803CBBCC->_4 = 1;
        }
        break;
    case 1:
        fn_2_86EC();
        break;
    case 2:
        if ((g_d_GameSettings.GameModeSelected == 5 ? lbl_8037169C._12 : 1) != 0) {
            fn_2_6608();
        }
        break;
    case 3:
        if (lbl_2_bss_F468._36 < 0 && lbl_803C66B0._5D == 0 && lbl_803C66B0._5E == 0) {
            fn_2_72630();
            lbl_2_bss_F468._33 = 0;
            lbl_803CBBCC->_4 = 4;
        } else {
            lbl_2_bss_F468._36--;
        }
        break;
    case 4:
        fn_2_6484();
        break;
    case 5:
        fn_2_6D3C();
        break;
    case 6:
        fn_2_323C();
        break;
    case 7:
        if (lbl_2_bss_F468._36 < 0) {
            fn_2_6138();
        } else {
            lbl_2_bss_F468._36--;
        }
        break;
    case 8:
        fn_2_61A0();
        break;
    }
}

// .text:0x000102C8 size:0x234
void fn_2_102C8(u8 port) {
    s32 i;
    s32 empty = 0;

    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._02[port][i] == -1 || lbl_803C6724._02[port][i] == 54) {
            empty++;
        }
    }
    if (lbl_2_bss_F468._41[port ^ 1] != 0 && lbl_8034E9A0._4757[lbl_2_bss_F410._20[port ^ 1]] == 0) {
        lbl_8034E9A0._4757[lbl_2_bss_F410._20[port ^ 1]] = 1;
        lbl_2_bss_F468._3B[port] = 1;
    }
    if (empty != 0) {
        do {
            lbl_803CBD24._2 = randRange_FUN_80042bf0(0, 2);
        } while (lbl_803CBD24._3 == lbl_803CBD24._2);
        fn_2_ABC0(port);
        switch (lbl_803CBD24._2) {
        case 0:
            fn_2_FCB4(port);
            break;
        case 1:
            fn_2_FAA0(port);
            break;
        case 2:
            fn_2_F200(port);
            break;
        }
        fn_800678CC(port);
        unsure_FillRosterPositions(port);
        fn_800625A4(port, 0x16);
        lbl_2_bss_F468._37[port] = 1;
        lbl_803CBD24._3 = lbl_803CBD24._2;
    } else {
        lbl_2_bss_F468._00[port] = 9;
        fn_800625A4(port, 0x11);
    }
    if (lbl_2_bss_F468._3B[port] != 0) {
        lbl_2_bss_F468._3B[port] = 0;
        lbl_8034E9A0._4757[lbl_2_bss_F410._20[port ^ 1]] = 0;
    }
}

// .text:0x0000FAA0 size:0x214
void fn_2_FAA0(u8 port) {
    s32 i;
    s32 g;
    s32 j;
    s16 id;
    s32 cap = lbl_8034E9A0._46E0[port];

    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._02[port][i] == -1 || lbl_803C6724._02[port][i] == 54) {
            do {
                id = randRange_FUN_80042bf0(0, 0x35);
            } while (lbl_8034E9A0._4757[id] != 0);
            fn_80067B40(port, id, 1);
            for (g = 0; g < 9; g++) {
                for (j = 0; j < 5; j++) {
                    if (id == lbl_80108EDC[g][j]) {
                        lbl_8034E9A0._4757[lbl_80108EDC[g][1]] = 1;
                        lbl_8034E9A0._4757[lbl_80108EDC[g][2]] = 1;
                        lbl_8034E9A0._4757[lbl_80108EDC[g][3]] = 1;
                        lbl_8034E9A0._4757[lbl_80108EDC[g][4]] = 1;
                        id = lbl_80108EDC[g][0];
                        goto found;
                    }
                }
            }
        found:
            if (g_d_GameSettings._10 == 0 && port != 0) {
                if (lbl_8034E9A0._46F8[0] == 0) {
                    fn_800506E8(1, id, 1);
                } else {
                    fn_800506E8(1, id, 1);
                }
            } else {
                fn_800506E8(lbl_8034E9A0._46F8[port], id, 1);
            }
            lbl_803C6724._02[port][i] = id;
            lbl_8034E9A0._4757[id] = 1;
            lbl_803C6724._26[port][i] = lbl_8034E9A0._0000[id / 9][id % 9]._3B[cap];
        }
    }
}

// .text:0x0000EC54 size:0x140
void fn_2_EC54(s32 port) {
    s32 t;
    s32 i;

    if (g_d_GameSettings.GameModeSelected == 5) {
        return;
    }
    if (g_d_GameSettings._10 == 1) {
        lbl_2_bss_100B8._2E[1] = 0;
        lbl_2_bss_100B8._2E[0] = 0;
    } else {
        lbl_2_bss_100B8._2E[port] = 0;
    }
    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            lbl_803C6724._26[t][i] = 0;
        }
        if (lbl_2_bss_F468._45[t] != 0) {
            lbl_2_bss_F468._45[t] = 0;
        }
    }
    fn_2_EC34();
    lbl_2_bss_F468._2E = 1;
    lbl_2_bss_100B4 = 1;
    lbl_803CBBCC->_4 = 8;
}

// .text:0x0000EC34 size:0x20
void fn_2_EC34(void) {
    if (lbl_2_bss_F468._56 == 0) {
        lbl_2_bss_F468._56 = 1;
    }
}

// .text:0x0000CCE0 size:0x164
void fn_2_CCE0(u8 port) {
    s32 i;

    if (lbl_2_bss_F468._37[port] == 0) {
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._02[port][i] == -1 || lbl_803C6724._02[port][i] == 54) {
                break;
            }
        }
        if (i == 9) {
            lbl_2_bss_F468._37[port] = 1;
            lbl_2_bss_F468._08[port] = lbl_2_bss_F468._00[port];
            lbl_2_bss_F468._00[port] = 9;
            lbl_2_bss_F468._41[port] = 0;
            fn_800625A4(port, 20);
            fn_80050138(1, -1, -1, -1, -1, 0);
        } else {
            lbl_2_bss_F468._08[port] = lbl_2_bss_F468._00[port];
            lbl_2_bss_F468._00[port] = lbl_803C6724._14[port][i];
            fn_800625A4(port, 14);
        }
    }
}

// .text:0x0000CCBC size:0x24
void fn_2_CCBC(void) {
    fn_2_7DDC();
    fn_2_7504();
}

// .text:0x0000CA60 size:0x25C
// 95%: registers only (fn_2_A1A0 inlined, see there).
void fn_2_CA60(u8 idx, u8 team) {
    s8 id = lbl_803C6724._02[team][idx];

    if (id != -1 && id != 54) {
        lbl_80354720[team][idx]._1 = idx;
        lbl_80354720[team][idx]._0 = idx;
        inMemRoster[team][idx].CharID = id;
    } else {
        fn_2_A1A0(idx, team);
    }
    fn_2_C698(idx, team);
}

// .text:0x0000C7DC size:0x284
// 86%: the idx == 0 block's stores are scheduled differently, and the
// retry loop compares its operands in the other order.
void fn_2_C7DC(u8 idx, u8 team) {
    s32 i;
    s32 id;

retry:
    if (idx == 0) {
        lbl_80354720[team][idx]._1 = idx;
        lbl_80353B98[team][idx]._1 = idx;
        lbl_80353B98[team][idx]._0 = idx;
        lbl_80354720[team][idx]._0 = idx;
        lbl_80354720[team][idx]._2 = idx;
        inMemRoster[team][idx].CharID = lbl_8034E9A0._46E0[team];
        lbl_80353B98[team][idx]._2 = idx;
    } else {
        do {
            id = fn_2_14F8(0, 0x35);
        } while (lbl_8034E9A0._4757[lbl_800FDE84[id]] != 0);
        for (i = 0; i < idx; i++) {
            if (inMemRoster[0][i].CharID == id || inMemRoster[1][i].CharID == id) {
                goto retry;
            }
        }
        lbl_80354720[team][idx]._1 = idx;
        lbl_80353B98[team][idx]._1 = idx;
        lbl_80353B98[team][idx]._0 = idx;
        lbl_80354720[team][idx]._0 = idx;
        lbl_80354720[team][idx]._2 = idx;
        inMemRoster[team][idx].CharID = id;
        lbl_80353B98[team][idx]._2 = idx;
        fn_2_C698(idx, team);
    }
}

// .text:0x0000C698 size:0x144
void fn_2_C698(u8 idx, u8 team) {
    s32 id;

    if (g_d_GameSettings.GameModeSelected != 5) {
        id = lbl_803C6724._02[team][idx];
        lbl_8034E9A0._4757[id] = 1;
        if (g_d_GameSettings._10 == 0 && team != 0) {
            if (lbl_8034E9A0._46F8[0] == 0) {
                fn_800506E8(1, id, 1);
            } else {
                fn_800506E8(0, id, 1);
            }
        } else {
            fn_800506E8(lbl_8034E9A0._46F8[team], id, 1);
        }
        fn_80067B40(team, id, 1);
    } else {
        id = lbl_803C6724._02[0][idx];
        fn_800506E8(0, id, 1);
        lbl_8034E9A0._4757[id] = 1;
        fn_80067B40(team, id, 1);
    }
}

// .text:0x0000C484 size:0x214
void fn_2_C484(u8 team, s16 charID) {
    s32 c;

    for (c = 0; c < 54; c++) {
        if (c == charID) {
            lbl_8034E9A0._4757[c] = 0;
            if (g_d_GameSettings.GameModeSelected == 5) {
                if (fn_2_C324(c) == -1) {
                    fn_800506E8(team, c, 0);
                }
            } else {
                fn_800506E8(team, c, 0);
                fn_80067B40(team, c, 0);
            }
            return;
        }
    }
}

// .text:0x0000C324 size:0x160
s8 fn_2_C324(s32 charID) {
    s32 i;
    s32 j;
    s32 group = -1;
    s16 id;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 5; j++) {
            if (charID == lbl_80108EDC[i][j]) {
                group = i;
                goto found;
            }
        }
    }
found:
    if (group == -1) {
        return group;
    }
    for (i = 0; i < 9; i++) {
        id = inMemRoster[0][i].CharID;
        for (j = 0; j < 5; j++) {
            if (id == lbl_80108EDC[group][j] && id != charID) {
                return group;
            }
        }
    }
    return -1;
}

// .text:0x0000B508 size:0x164
void fn_2_B508(void) {
    s32 c;
    s32 i;

    for (c = 0; c < 54; c++) {
        for (i = 1; i < 9; i++) {
            if (lbl_803C6724._02[1][i] == c) {
                lbl_8034E9A0._4757[c] = 0;
                fn_800506E8(lbl_8034E9A0._46F8[1], c, 0);
                fn_80067B40(1, c, 0);
            }
        }
    }
    for (i = 1; i < 9; i++) {
        lbl_80354720[1][i]._2 = i;
        lbl_80353B98[1][i]._2 = i;
        lbl_803C6724._02[1][i] = 54;
        lbl_803C6724._4A[1][i] = 0;
    }
}

// .text:0x0000B324 size:0x1E4
void fn_2_B324(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        lbl_80354720[1][i]._0 = i;
        lbl_80354720[0][i]._0 = i;
        lbl_80353B98[1][i]._0 = i;
        lbl_80353B98[0][i]._0 = i;
        lbl_80354720[1][i]._1 = i;
        lbl_80354720[0][i]._1 = i;
        lbl_80353B98[1][i]._1 = i;
        lbl_80353B98[0][i]._1 = i;
        lbl_80354720[1][i]._2 = i;
        lbl_80354720[0][i]._2 = i;
        lbl_80353B98[1][i]._2 = i;
        lbl_80353B98[0][i]._2 = i;
        lbl_80354720[1][i]._3 = 1;
        lbl_80354720[0][i]._3 = 1;
        inMemRoster[0][i].CharID = lbl_8034E9A0._46E0[0] + i;
        inMemRoster[1][i].CharID = lbl_8034E9A0._46E0[1] + i;
    }
    for (; i < 9; i++) {
        lbl_80354720[1][i]._0 = i;
        lbl_80354720[0][i]._0 = i;
        lbl_80353B98[1][i]._0 = i;
        lbl_80353B98[0][i]._0 = i;
        lbl_80354720[1][i]._1 = -1;
        lbl_80354720[0][i]._1 = -1;
        lbl_80353B98[1][i]._1 = -1;
        lbl_80353B98[0][i]._1 = -1;
        lbl_80354720[1][i]._2 = -1;
        lbl_80354720[0][i]._2 = -1;
        lbl_80353B98[1][i]._2 = -1;
        lbl_80353B98[0][i]._2 = -1;
        lbl_80354720[1][i]._3 = -1;
        lbl_80354720[0][i]._3 = -1;
        inMemRoster[0][i].CharID = 0;
        inMemRoster[1][i].CharID = 0;
    }
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

// .text:0x0000A50C size:0x120
s32 fn_2_A50C(void) {
    s32 i;
    s32 j;
    int id;

    for (i = 0; i < 9; i++) {
        id = lbl_803C6724._02[0][i];
        for (j = 0; j < 9; j++) {
            if (id == lbl_803C6724._02[1][j]) {
                return 1;
            }
        }
    }
    return 0;
}

static inline s32 fn_2_SlotOf(s8* shared, s8* own) {
    if (g_d_GameSettings._10 == 0 && lbl_2_bss_100B8._2E[0] != 0) {
        return *shared;
    }
    return *own;
}

// .text:0x0000A1A0 size:0xE8
// 91%: the target computes i + 2 and &_02[1][i] before each test of the
// condition, and allocates registers differently.
void fn_2_A1A0(u8 idx, u8 team) {
    s32 i;
    s8 id = 0;

retry:
    if (lbl_8034E9A0._4757[id] != 0) {
        goto retry;
    }
    for (i = 0; i < idx; i++) {
        if (fn_2_SlotOf(&lbl_803C6724._02[0][i], &lbl_803C6724._02[team][i]) == id) {
            goto retry;
        }
        if (fn_2_SlotOf(&lbl_803C6724._02[1][i], &lbl_803C6724._02[team][i]) == id) {
            goto retry;
        }
    }
    lbl_803C6724._02[team][idx] = id;
}

// .text:0x0000A040 size:0x160
void fn_2_A040(s32 group, s32 slot, u8 team, u8 idx) {
    s16* row = lbl_80108EDC[group];
    s32 i;
    s32 j;

    if (row[slot] != -1 && slot < 4) {
        slot++;
        if (slot == 5 || row[slot] == -1) {
            slot = 0;
        }
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 9; j++) {
                if (lbl_803C6724._02[i][j] == row[slot]) {
                    return;
                }
            }
        }
        lbl_803C6724._02[team][idx] = row[slot];
    } else {
        lbl_803C6724._02[team][idx] = row[0];
    }
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
        u8 id = inMemRoster[other][i].CharID;
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

// .text:0x000087A8 size:0x194
void fn_2_87A8(void) {
    s32 prev = lbl_2_bss_F410._4C;

    if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
        return;
    }
    {
        if (lbl_803C77B8[lbl_8034E9A0._46F8[0]]._04 & 8) {
            lbl_2_bss_F410._4C--;
            if (lbl_2_bss_F410._4C < 0) {
                lbl_2_bss_F410._4C = 3;
            }
            if (prev != lbl_2_bss_F410._4C) {
                fn_800625A4(0, 0x20);
            }
            fn_2_1C34(8);
        } else if (lbl_803C77B8[lbl_8034E9A0._46F8[0]]._04 & 4) {
            lbl_2_bss_F410._4C++;
            if (lbl_2_bss_F410._4C == 4) {
                lbl_2_bss_F410._4C = 0;
            }
            if (prev != lbl_2_bss_F410._4C) {
                fn_800625A4(0, 0x20);
            }
            fn_2_1C34(4);
        } else if (lbl_803C77B8[lbl_8034E9A0._46F8[0]]._02 & 0x200) {
            lbl_2_bss_F468._33 = 2;
            lbl_2_bss_F468._34 = 0;
            lbl_2_bss_F468._35 = 1;
            lbl_803C5EA4._0E = 1;
            fn_800625A4(1, 0x1F);
            fn_2_1C34(0x200);
        } else if (lbl_803C77B8[lbl_8034E9A0._46F8[0]]._02 & 0x100) {
            gameInitOptions._3 = lbl_803CB8D0[prev];
            fn_800625A4(0, 0x21);
            lbl_2_bss_F468._33 = 2;
            lbl_2_bss_F468._34 = 0;
            lbl_2_bss_F468._35 = 0;
            fn_2_1C34(0x100);
        }
    }
}

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

// .text:0x00006884 size:0x270
void fn_2_6884(void) {
    s32 i;
    s32 j;
    u8 id;
    s8 group;

    for (i = 0; i < 9; i++) {
        id = starMissionCompletionTracker._40B8[i]._0;
        lbl_803C6724._02[0][i] = starMissionCompletionTracker._40B8[i]._0;
        lbl_80354720[0][i]._1 = starMissionCompletionTracker._40B8[i]._2;
        lbl_80354720[0][i]._0 = i;
        lbl_803C6724._4A[0][i] = 1;
        lbl_80354720[0][i]._2 = i;
        lbl_8034E9A0._4757[id] = 1;
        group = fn_2_C324(id);
        if (group != -1) {
            for (j = 0; j < 5; j++) {
                if (lbl_80108EDC[group][j] != -1) {
                    lbl_8034E9A0._4757[lbl_80108EDC[group][j]] = 1;
                }
            }
        }
    }
}

// .text:0x00006784 size:0x100
void fn_2_6784(void) {
    s32 i;
    s32 j;
    u8 found;
    u8 id;
    s16 r;

    for (i = 0; i < 9; i++) {
        if (i == 0) {
            lbl_8034E9A0._46E0[1] = 0;
            lbl_803C6724._02[1][0] = 0;
            lbl_803C6724._4A[1][0] = 1;
            lbl_8034E9A0._4757[lbl_803C6724._02[1][0]] = 1;
        } else {
            do {
                found = 0;
                r = randRange_FUN_80042bf0(0, 9);
                id = lbl_80109038[r];
                for (j = 0; j < i; j++) {
                    if (lbl_803C6724._02[1][j] == id) {
                        found = 1;
                    }
                }
            } while (found);
            lbl_803C6724._02[1][i] = id;
            lbl_803C6724._4A[1][i] = 1;
            lbl_8034E9A0._4757[id] = 1;
        }
        lbl_80354720[1][i]._0 = i;
        lbl_80354720[1][i]._2 = i;
        lbl_80354720[1][i]._1 = i;
    }
}

// .text:0x00006608 size:0x17C
void fn_2_6608(void) {
    s32 i;

    if (lbl_2_bss_F468._59[0] != 0) {
        fn_2_3624(0);
    } else if (lbl_2_bss_F468._59[1] != 0 && lbl_2_bss_100B8._2E[0] != 0 && g_d_GameSettings._10 == 0) {
        fn_2_3624(0);
    } else {
        fn_2_104FC(0);
    }
    if (g_d_GameSettings._10 == 1) {
        if (lbl_2_bss_F468._59[1] != 0) {
            fn_2_3624(1);
        } else {
            fn_2_104FC(1);
        }
    }
    if (lbl_2_bss_F468._56 != 0) {
        lbl_803C5EA4._09 = 0;
        lbl_803C5EA4._08 = 0;
        lbl_2_bss_100B8._30[1] = 0;
        lbl_2_bss_100B8._30[0] = 0;
        if (g_d_GameSettings._10 == 0) {
            lbl_2_bss_F468._00[0] = 9;
            lbl_803C66B0._59 = 0;
        }
        for (i = 0; i < 2; i++) {
            if (lbl_2_bss_F468._59[i] != 0) {
                fn_800625A4(i, 0x1B);
                lbl_2_bss_F468._59[i] = 0;
            } else {
                fn_800625A4(i, 0xB);
            }
        }
    }
}

// .text:0x00006484 size:0x184
void fn_2_6484(void) {
    switch (lbl_2_bss_F468._33) {
    case 0:
        if (lbl_803C66B0._5D != 0 && lbl_803C66B0._5E != 0) {
            break;
        }
        if (lbl_2_bss_F468._34 == 0) {
            fn_800625A4(0, 0x1E);
            lbl_2_bss_F468._34 = 1;
        }
        lbl_2_bss_F468._33 = 1;
        break;
    case 1:
        if (lbl_803C66B0._5D != 0 && lbl_803C66B0._5E != 0) {
            break;
        }
        fn_2_87A8();
        break;
    case 2:
        if (lbl_803C66B0._5D != 0 && lbl_803C66B0._5E != 0) {
            break;
        }
        lbl_8034E9A0._472A = 1;
        if (lbl_2_bss_F468._35 == 0) {
            lbl_2_bss_F468._2E = 0;
            lbl_2_bss_100B4 = 1;
            lbl_803CBBCC->_4 = 8;
            fn_800625A4(0, 0x13);
            fn_800625A4(1, 0x13);
        } else {
            fn_800625A4(1, 0x12);
            lbl_803CBBCC->_4 = 2;
        }
        lbl_2_bss_F468._35 = 0;
        lbl_2_bss_F468._33 = 0;
        break;
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
                    lbl_803C6724._02[t][i] = inMemRoster[t][j].CharID;
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

// .text:0x000052CC size:0x178
void fn_2_52CC(void) {
    s32 i;

    lbl_2_bss_100B8._2E[0] = 1;
    lbl_803C66B0._59 = 1;
    lbl_2_bss_F468._00[lbl_803C66B0._59] = 10;
    lbl_803C5EA4._0E = 1;
    if (lbl_8034E9A0._4757[lbl_2_bss_F410._20[1]] != 0) {
        for (i = 0; i < 32; i++) {
            if (lbl_8034E9A0._4757[lbl_800FDE84[i]] == 0) {
                lbl_2_bss_F410._20[1] = lbl_800FDE84[i];
                break;
            }
        }
    }
    switch (lbl_8034E9A0._46F8[1]) {
    case 0:
        fn_80050138(1, lbl_2_bss_F410._20[1], -1, -1, -1, 0);
        break;
    case 1:
        fn_80050138(1, -1, lbl_2_bss_F410._20[1], -1, -1, 0);
        break;
    case 2:
        fn_80050138(1, -1, -1, lbl_2_bss_F410._20[1], -1, 0);
        break;
    case 3:
        fn_80050138(1, -1, -1, -1, lbl_2_bss_F410._20[1], 0);
        break;
    }
}

// .text:0x00005184 size:0x148
void fn_2_5184(u8 port) {
    s32 i;

    lbl_2_bss_F468._3D[port] = 0;
    if (g_d_GameSettings.GameModeSelected == 5) {
        return;
    }
    if (lbl_2_bss_F468._37[port] == 0) {
        fn_2_102C8(port);
        lbl_2_bss_F468._00[port] = 9;
        return;
    }
    for (i = 0; i < 9; i++) {
        if (lbl_8034E9A0._46E0[port] != lbl_803C6724._02[port][i]) {
            lbl_8034E9A0._4757[lbl_803C6724._02[port][i]] = 0;
            fn_800506E8(lbl_8034E9A0._46F8[port], lbl_803C6724._02[port][i], 0);
            fn_80067B40(port, lbl_803C6724._02[port][i], 0);
            lbl_803C6724._02[port][i] = -1;
            lbl_803C6724._4A[port][i] = 0;
            lbl_803C6724._26[port][i] = 0;
        }
    }
    lbl_2_bss_F468._37[port] = 0;
    lbl_2_bss_F468._43[port] = 1;
    fn_800625A4(port, 25);
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

// .text:0x0000348C size:0x144
void fn_2_348C(void) {
    s32 i;
    s32 j;
    s32 locked;

    for (i = 0; i < 6; i++) {
        locked = g_d_GameSettings._1A[i] == 0;
        for (j = 0; j < 54; j++) {
            if (lbl_803CB748[i] == lbl_800E8558[j]._2) {
                lbl_8034E9A0._4757[j] = locked;
            }
        }
        lbl_803CB748[i] = lbl_803CB748[i];
    }
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

// .text:0x0000323C size:0x180
void fn_2_323C(void) {
    s32 result;

    switch (lbl_2_bss_3A0) {
    case 0:
        fn_800B0A5C_insertQueue(fn_8004D0F0, 0x3000);
        lbl_2_bss_3A0++;
        break;
    case 1:
        result = fn_8004CA6C(lbl_8034E9A0._472E[lbl_803CBD24._4][0]);
        switch (result) {
        case 0:
            break;
        case 1:
            fn_8004CC2C();
            break;
        case 3:
            fn_2_2FC0(10, 1, 1);
            lbl_803CBD24._4 = 0;
            fn_800625A4(0, 0x13);
            fn_800625A4(1, 0x13);
            changeScene(15, 6);
            lbl_2_bss_3A0 = 0;
            lbl_2_bss_F468._2E = 0;
            lbl_2_bss_100B4 = 1;
            lbl_803CBBCC->_4 = 8;
            break;
        case 2:
            fn_8004CC2C();
            break;
        case 4:
            lbl_2_bss_3A0 = 0;
            lbl_803CBD24._4 = 0;
            lbl_803297E0._CF5F = 0;
            lbl_803CBBCC->_4 = 2;
            break;
        }
        break;
    }
}

// .text:0x00003204 size:0x38
void fn_2_3204(void) {
    fn_2_2FC0(lbl_803297E0._CF5F, 1, 1);
}

// .text:0x00002FC0 size:0x244
// 96.8%: registers in the fn_2_348C loop. Calling fn_2_348C() there matches this
// function, but then fn_2_3204 and fn_2_323C inline it; the target calls it.
void fn_2_2FC0(u8 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 j;
    s32 locked;

    switch (arg0) {
    case 9:
        fn_800684A4();
        if (arg2 == 0) {
            break;
        }
    case 10:
        memset(lbl_8034E9A0._4757, 0, sizeof(lbl_8034E9A0._4757));
        lbl_8034E9A0._4757[lbl_8034E9A0._46E0[0]] = 1;
        lbl_8034E9A0._4757[lbl_8034E9A0._46E0[1]] = 1;
        for (i = 0; i < 6; i++) {
            locked = g_d_GameSettings._1A[i] == 0;
            for (j = 0; j < 54; j++) {
                if (lbl_803CB748[i] == lbl_800E8558[j]._2) {
                    lbl_8034E9A0._4757[j] = locked;
                }
            }
            lbl_803CB748[i] = lbl_803CB748[i];
        }
        fn_80067F70(0);
        fn_80067F70(1);
        fn_2_8940();
        fn_800678CC(0);
        fn_800678CC(1);
        unsure_FillRosterPositions(0);
        unsure_FillRosterPositions(1);
        characterSelectScreen(0);
        characterSelectScreen(1);
        fn_80069854();
        if (arg2 == 0) {
            break;
        }
    case 12:
        fn_800671FC();
        if (arg1 != 0) {
            fn_800649BC();
        }
        break;
    case 11:
        break;
    }
}

// .text:0x00002D1C size:0x2A4
void fn_2_2D1C(void) {
    s32 t;
    s32 i;

    lbl_8034E9A0._46E0[0] = 10;
    lbl_8034E9A0._46E0[1] = 2;
    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            lbl_803C6724._02[t][i] = lbl_2_data_E64[t][i];
            lbl_803C6724._26[t][i] = lbl_8034E9A0._0000[lbl_2_data_E64[t][i] / 9][lbl_2_data_E64[t][i] % 9]._3B[lbl_8034E9A0._46E0[t]];
        }
    }
    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            lbl_80354720[t][i]._2 = i;
            lbl_80354720[t][i]._1 = i;
            lbl_80354720[t][i]._0 = i;
        }
    }
}

// .text:0x00002BB8 size:0x164
void fn_2_2BB8(void) {
    s32 t;
    s32 i;
    s16 id;
    s32 cap;

    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            cap = lbl_8034E9A0._46E0[t];
            if (cap == 0) {
                id = lbl_2_data_E88[0][i];
                lbl_803C6724._02[t][i] = id;
                lbl_803C6724._26[t][i] = lbl_8034E9A0._0000[id / 9][id % 9]._3B[cap];
            } else {
                id = lbl_2_data_E88[1][i];
                lbl_803C6724._02[t][i] = id;
                lbl_803C6724._26[t][i] = lbl_8034E9A0._0000[id / 9][id % 9]._3B[cap];
            }
            lbl_80354720[t][i]._2 = i;
            lbl_80354720[t][i]._1 = i;
            lbl_80354720[t][i]._0 = i;
        }
        fn_800670A0(t);
    }
}

