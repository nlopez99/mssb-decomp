#include "menus/rep_0318.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "string.h"

extern void fn_800625A4(s32 port, s32 arg1);
extern void fn_800506E8(s32 port, s32 charID, s32 arg2);
extern u8 fn_80067B40(u8 team, u8 charID, s32 arg2);
extern s16 fn_80067AC8(s16 id, s32 arg1);
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
extern s32 fn_80062578(void);
extern s32 fn_80050F78(s32 arg0);
extern void fn_2_19F2C(void);
extern void fn_80062A74(void);
extern void fn_80021410(void);
extern void fn_80035CA4(s32 id);
extern void fn_2_11A0(s32 arg0);
extern void fn_80021AC0(s32 team, s32 slot);
extern void fn_800AD038(void* arg0);
extern void fn_80066EAC(s32 team);
extern s32 fn_80050760(s32 team, u16 held, u16 trg, u16 rep, s32 arg4);
extern void fn_800203E0(int, s8);
extern void sndFXRelated(s32 arg0);
extern s32 randRange_FUN_80042bf0(s32 min, s32 max);
extern void fn_2_16A74(s32 arg0, s32 arg1);
extern void fn_2_1C34(u16 buttons);
extern s32 fn_2_14F8(s32 min, s32 max);
extern void fn_2_1D54(s32* cursor, u8 arg1, s32 count);
extern int fn_8006285C(void);
extern void fn_800216F8(u8 group, int (*callback)(void));
extern void initializeUnknown(void);
extern void fn_80062A94(void);
extern s32 fn_800697B0(void);
extern void fn_8006496C(void);
extern void fn_2_82E58(void);
extern void fn_80050FE8(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_2_7265C(void);
extern void fn_800628D4(int charID);

// One character's stats, as in inMemRoster and at the start of lbl_8034E9A0
typedef struct CharEntry0318 {
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
} CharEntry0318; // size: 0xA0

extern CharEntry0318 inMemRoster[2][9];
extern struct {
    /* 0x0000 */ struct {
        /* 0x00 */ u8 _00[0x31];
        /* 0x31 */ s8 _31;
        /* 0x32 */ u8 _32[0x34 - 0x32];
    } characters[54];
    /* 0x0AF8 */ u8 _0AF8[0x40B8 - 0xAF8];
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
    /* 0x441F */ s8 _441F;
    /* 0x4420 */ u8 _4420[0x4445 - 0x4420];
    /* 0x4445 */ u8 _4445;
    /* 0x4446 */ u8 _4446[0x44EF - 0x4446];
    /* 0x44EF */ s8 _44EF;
} starMissionCompletionTracker;
extern struct {
    /* 0x0 */ u8 _0[3];
    /* 0x3 */ u8 _3;
} gameInitOptions;

typedef struct Menu0318 {
    /* 0x000 */ s32 _00[2];
    /* 0x008 */ s32 _08[2];
    /* 0x010 */ s32 _10[2];
    /* 0x018 */ u8 _18[0x20 - 0x18];
    /* 0x020 */ s32 _20[2];
    /* 0x028 */ u8 _28[5];
    /* 0x02D */ u8 _2D;
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
    /* 0x047 */ u8 _47[2];
    /* 0x049 */ u8 _49[2];
    /* 0x04B */ u8 _4B[2];
    /* 0x04D */ u8 _4D[0x4F - 0x4D];
    /* 0x04F */ u8 _4F;
    /* 0x050 */ u8 _50[2];
    /* 0x052 */ u8 _52[2];
    /* 0x054 */ u8 _54[0x56 - 0x54];
    /* 0x056 */ u8 _56;
    /* 0x057 */ u8 _57[0x59 - 0x57];
    /* 0x059 */ u8 _59[2];
    /* 0x05B */ u8 _5B[0x5F - 0x5B];
    /* 0x05F */ u8 _5F[2];
    /* 0x061 */ s8 _61[2];
    /* 0x063 */ u8 _63[0x65 - 0x63];
    /* 0x065 */ u8 _65[2];
    /* 0x067 */ u8 _67[0xC4C - 0x67];
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
    /* 0x08 */ u16 _8;
}* lbl_803CBBCC;
extern struct {
    /* 0x0000 */ CharEntry0318 _0000[6][9];
    /* 0x21C0 */ u8 _21C0[0x4380 - 0x21C0];
    /* 0x4380 */ u8 _4380[6][4][0x12];
    /* 0x4530 */ u8 _4530[0x46E0 - 0x4530];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ void* _46E8;
    /* 0x46EC */ u8 _46EC[0x46F8 - 0x46EC];
    /* 0x46F8 */ s8 _46F8[4];
    /* 0x46FC */ s8 _46FC[4];
    /* 0x4700 */ u8 _4700[2];
    /* 0x4702 */ u8 _4702;
    /* 0x4703 */ u8 _4703[0x470B - 0x4703];
    /* 0x470B */ u8 _470B;
    /* 0x470C */ u8 _470C;
    /* 0x470D */ u8 _470D[0x472A - 0x470D];
    /* 0x472A */ u8 _472A;
    /* 0x472B */ u8 _472B;
    /* 0x472C */ u16 _472C[6][3];
    /* 0x4750 */ u8 _4750[0x4752 - 0x4750];
    /* 0x4752 */ u8 _4752[0x4755 - 0x4752];
    /* 0x4755 */ u8 _4755;
    /* 0x4756 */ u8 _4756;
    /* 0x4757 */ u8 _4757[0x36];
    /* 0x478D */ u8 _478D[2][0x36];
    /* 0x47F9 */ u8 _47F9[0x48AD - 0x47F9];
    /* 0x48AD */ u8 _48AD;
    /* 0x48AE */ u8 _48AE;
    /* 0x48AF */ u8 _48AF;
    /* 0x48B0 */ u8 _48B0;
    /* 0x48B1 */ u8 _48B1;
} lbl_8034E9A0;
extern struct {
    /* 0x00 */ u8 _00[0x24];
    /* 0x24 */ u8 _24;
    /* 0x25 */ u8 _25;
    /* 0x26 */ u8 _26;
} lbl_8034E978;
extern struct {
    /* 0x00 */ u8 _00[0x2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ s8 _14[2][9];
    /* 0x26 */ u8 _26[2][9];
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
extern CharEntry0318 lbl_2_bss_E8CC[2][9];
extern struct {
    /* 0x000 */ Slot0318 _000[2][9];
    /* 0x048 */ u8 _048[0xBE4 - 0x48];
} lbl_2_bss_DCE8;
extern u8 lbl_80109038[9];
extern u8 lbl_80108DB8[0x24];
extern u8 lbl_803CB748[6];
extern u8 lbl_80108EC4[12];
extern u8 lbl_800EFBA4[0x10];
extern struct {
    /* 0x00 */ u8 _00[0x74];
    /* 0x74 */ u8 _74[2];
    /* 0x76 */ u8 _76[0x94 - 0x76];
} lbl_803C6028;
extern s16 lbl_80108EDC[28][5];
extern u8 lbl_800FDE84[];
extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[6];
    /* 0x07 */ u8 _07[0x55 - 0x7];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[0x59 - 0x57];
    /* 0x59 */ u8 _59[2];
    /* 0x5B */ u8 _5B[0x5D - 0x5B];
    /* 0x5D */ u8 _5D[2];
    /* 0x5F */ u8 _5F[0x64 - 0x5F];
} lbl_803C66B0;
extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u8 _08[2];
    /* 0x0A */ u8 _0A[2];
    /* 0x0C */ s8 _0C[2];
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F[0x11 - 0xF];
    /* 0x11 */ u8 _11;
    /* 0x12 */ s16 _12[2][9];
    /* 0x36 */ u8 _36[0x3C - 0x36];
} lbl_803C5EA4;
extern struct {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
} lbl_803CBD24;
extern u8 lbl_803CB8D0[8];
extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
}* lbl_803CC1B8;
extern u8 lbl_80361B20[0x130];
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
    /* 0xCF60 */ u8 _CF60[0xCF70 - 0xCF60];
    /* 0xCF70 */ u8 _CF70;
    /* 0xCF71 */ u8 _CF71[0xCFA1 - 0xCF71];
    /* 0xCFA1 */ u8 _CFA1;
} lbl_803297E0;

typedef struct AramEntry0318 {
    /* 0x0 */ u32 _0[4];
} AramEntry0318; // size: 0x10

extern int fn_80035838(AramEntry0318* entry, int count);

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
static AramEntry0318 lbl_2_data_D14[1] = {
    { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 },
};
static AramEntry0318 lbl_2_data_D24[2] = {
    { 0x0000040B, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 },
    { 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8 },
};
static AramEntry0318 lbl_2_data_D44[13] = {
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

static u8 lbl_2_bss_408[0x350];
static s16 lbl_2_bss_3E4[2][9];
static s8 lbl_2_bss_3E0[4];
static u8 lbl_2_bss_3A8[56];
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
        if (lbl_2_bss_F468._36 < 0 && lbl_803C66B0._5D[0] == 0 && lbl_803C66B0._5D[1] == 0) {
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

// .text:0x000104FC size:0xBB4
void fn_2_104FC(u16 port) {
    u16 pad[3];
    s8 count = 0;
    s32 team = lbl_803C66B0._59[port];
    s8 slot;
    s32 i;
    s32 cursor;
    s32 g;
    s32 j;
    s8 id;

    if (lbl_803C66B0._5D[team] != 0) {
        pad[0] = pad[1] = pad[2] = 0;
    } else if (g_d_GameSettings._10 == 1 && lbl_2_bss_100B8._2E[team] != 0) {
        pad[0] = lbl_8034E9A0._472C[port][0] & 0x200;
        pad[1] = lbl_8034E9A0._472C[port][1] & 0x200;
        pad[2] = lbl_8034E9A0._472C[port][2] & 0x200;
    } else if (lbl_2_bss_F468._52[team] != 0) {
        pad[0] = pad[1] = pad[2] = 0;
    } else {
        pad[0] = lbl_8034E9A0._472C[port][0];
        pad[1] = lbl_8034E9A0._472C[port][1];
        pad[2] = lbl_8034E9A0._472C[port][2];
    }
    if (pad[1] & 0x1000) {
        return;
    }
    if (pad[1] & 0x40) {
        if (fn_2_35D0(team)) {
            return;
        }
        if (lbl_2_bss_F468._41[team] != 0) {
            if (g_d_GameSettings.GameModeSelected == 5) {
                return;
            }
            if (lbl_8034E9A0._4757[lbl_2_bss_F410._20[team]] != 0) {
                return;
            }
            lbl_2_bss_F410._20[team] =
                fn_80050760(lbl_8034E9A0._46FC[lbl_8034E9A0._46F8[team]] == 0 ? lbl_8034E9A0._46F8[team]
                                                                                : lbl_8034E9A0._46F8[0] == 0,
                            pad[0], pad[1], pad[2], 0);
            return;
        }
        if (g_d_GameSettings.GameModeSelected == 5) {
            return;
        }
        cursor = lbl_2_bss_F468._00[team];
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[team][i] == cursor) {
                slot = i;
                break;
            }
        }
        id = lbl_803C6724._02[team][slot];
        if (id == -1 || id == 54) {
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            return;
        }
        if (lbl_2_bss_F468._00[team] != 9 && lbl_2_bss_F468._00[team] != 10) {
            lbl_2_bss_F468._50[team] = 0;
            for (g = 0; g < 9; g++) {
                for (j = 0; j < 5; j++) {
                    if (id == lbl_80108EDC[g][j]) {
                        lbl_2_bss_F468._50[team] = 1;
                        goto found;
                    }
                }
            }
        found:
            if (lbl_2_bss_F468._50[team] == 0) {
                return;
            }
            fn_2_A040(g, j, team, slot);
            fn_2_C698(slot, team);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
        }
    } else if (pad[1] & 0x800) {
        if (fn_2_35D0(team)) {
            return;
        }
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._02[team][i] != -1 && lbl_803C6724._02[team][i] != 54) {
                count++;
            }
        }
        if (count == 1) {
            return;
        }
        if (g_d_GameSettings.GameModeSelected == 5) {
            return;
        }
        for (i = 1; i < 9; i++) {
            if (lbl_803C6724._02[team][i] != -1 && lbl_803C6724._02[team][i] != 54) {
                lbl_8034E9A0._4757[lbl_803C6724._02[team][i]] = 0;
                fn_800506E8(lbl_8034E9A0._46F8[team], lbl_803C6724._02[team][i], 0);
                fn_80067B40(team, lbl_803C6724._02[team][i], 0);
                lbl_803C6724._02[team][i] = -1;
                lbl_803C6724._4A[team][i] = 0;
                lbl_803C6724._26[team][i] = 0;
            }
        }
        lbl_2_bss_F468._37[team] = 0;
        lbl_2_bss_F468._41[team] = 0;
        lbl_2_bss_F468._50[team] = 0;
        lbl_2_bss_F468._08[team] = lbl_2_bss_F468._00[team];
        lbl_2_bss_F468._00[team] = 10;
        lbl_2_bss_F468._3D[team] = 0;
        lbl_2_bss_F468._52[team] = 1;
    } else if (pad[1] & 0x10) {
        if (fn_2_35D0(team)) {
            return;
        }
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[team][i] == lbl_2_bss_F468._00[team]) {
                slot = i;
                break;
            }
        }
        if (lbl_2_bss_F468._00[team] != 10 && lbl_2_bss_F468._00[team] != 9 && lbl_803C6724._02[team][slot] != -1 &&
            lbl_803C6724._02[team][slot] != 54 && lbl_2_bss_F468._41[team] == 0) {
            lbl_2_bss_F468._45[team] = 1;
            lbl_2_bss_F468._4B[team] = 1;
            lbl_2_bss_F468._47[team] = 0;
            sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
        } else if (lbl_2_bss_F468._41[team] != 0 && lbl_8034E9A0._4757[lbl_2_bss_F410._20[team]] == 0 &&
                   lbl_2_bss_F410._20[team] != -1) {
            lbl_2_bss_F468._45[team] = 1;
            lbl_2_bss_F468._4B[team] = 1;
            lbl_2_bss_F468._47[team] = 0;
            sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
        }
    } else if (pad[1] & 0x20) {
        if (fn_2_35D0(team)) {
            return;
        }
        if (lbl_2_bss_F468._59[team] != 0) {
            return;
        }
        lbl_2_bss_F468._59[team] = 1;
        lbl_2_bss_F468._61[team] = -1;
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        if (lbl_2_bss_F468._41[team] != 0) {
            lbl_2_bss_F468._41[team] = 0;
            fn_800625A4(team, 13);
        } else if (lbl_2_bss_F468._00[team] == 10) {
            lbl_2_bss_F468._63[team] = 1;
            lbl_2_bss_F468._08[team] = lbl_2_bss_F468._00[team];
            lbl_2_bss_F468._00[team] = 1;
            fn_800625A4(team, 14);
        } else {
            fn_800625A4(team, 26);
        }
    } else {
        fn_2_ED94(team, pad[0], pad[1], pad[2]);
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

// .text:0x0000FCB4 size:0x614
void fn_2_FCB4(u8 port) {
    s8 pool[54];
    s32 i;
    s32 j;
    s32 g;
    s32 m;
    s32 k;
    s8 r;
    s8 id;
    s8 tmp;
    s8 range;
    s16 member;
    s32 empty = 0;
    s32 cap = lbl_8034E9A0._46E0[port];

    memset(pool, -1, sizeof(pool));
    for (i = 0; i < 54; i++) {
        for (g = 0; g < 9; g++) {
            for (j = 1; j < 5; j++) {
                if (lbl_8034E9A0._478D[port][i] == lbl_80108EDC[g][j]) {
                    lbl_8034E9A0._4757[lbl_8034E9A0._478D[port][i]] = 1;
                }
            }
        }
        if (lbl_8034E9A0._4757[lbl_8034E9A0._478D[port][i]] == 0) {
            pool[i] = lbl_8034E9A0._478D[port][i];
        }
    }
    for (i = 0; i < 54; i++) {
        for (j = i; j < 54; j++) {
            if (pool[i] == -1 && pool[j] != -1) {
                tmp = pool[i];
                pool[i] = pool[j];
                pool[j] = tmp;
            }
        }
    }
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._02[port][i] == -1 || lbl_803C6724._02[port][i] == 54) {
            empty++;
        }
    }
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._02[port][i] == -1 || lbl_803C6724._02[port][i] == 54) {
            range = 20 - (9 - empty);
            do {
                do {
                    r = fn_2_14F8(0, range);
                    id = pool[r];
                } while (id == -1);
            } while (lbl_8034E9A0._4757[id] == 1);
            pool[r] = -1;
            lbl_8034E9A0._4757[id] = 1;
            if (g_d_GameSettings._10 == 0 && port != 0) {
                if (lbl_8034E9A0._46F8[0] == 0) {
                    fn_800506E8(1, id, 1);
                } else {
                    fn_800506E8(1, id, 1);
                }
            } else {
                fn_800506E8(lbl_8034E9A0._46F8[port], id, 1);
            }
            fn_80067B40(port, id, 1);
            for (g = 0; g < 9; g++) {
                for (j = 0; j < 5; j++) {
                    if (id == lbl_80108EDC[g][j]) {
                        id = lbl_80108EDC[g][0];
                        for (k = 0; k < 5; k++) {
                            member = lbl_80108EDC[g][k];
                            if (member != -1) {
                                for (m = 0; m < 54; m++) {
                                    if (pool[m] == member) {
                                        pool[m] = -1;
                                    }
                                }
                            }
                        }
                        goto found;
                    }
                }
            }
        found:
            lbl_803C6724._02[port][i] = id;
            empty--;
            lbl_803C6724._26[port][i] = lbl_8034E9A0._0000[id / 9][id % 9]._3B[cap];
        }
    }
    for (g = 0; g < 9; g++) {
        for (j = 0; j < 5; j++) {
            lbl_8034E9A0._4757[lbl_80108EDC[g][j]] = 0;
        }
    }
    for (i = 0; i < 9; i++) {
        fn_80067B40(port ^ 1, lbl_803C6724._02[port ^ 1][i], 1);
        fn_80067B40(port, lbl_803C6724._02[port][i], 1);
    }
    if (g_d_GameSettings._1A[5] == 0) {
        lbl_8034E9A0._4757[53] = 1;
        lbl_8034E9A0._4757[52] = 1;
        lbl_8034E9A0._4757[27] = 1;
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

// .text:0x0000F200 size:0x8A0
void fn_2_F200(u8 port) {
    s8 pool[8];
    s8 classes[9];
    s32 i;
    s32 k;
    s32 g;
    s32 j;
    s16 id;
    s32 cur;
    s8 n;
    u8 c1 = 0;
    u8 c2 = 0;
    u8 c3 = 0;
    u8 c0 = 0;
    u8 f1 = 0;
    u8 f2 = 0;
    u8 f3 = 0;
    u8 f0 = 0;
    s32 cap = lbl_8034E9A0._46E0[port];

    memset(classes, -1, sizeof(classes));
    for (i = 0; i < 9; i++) {
        cur = lbl_803C6724._02[port][i];
        if (cur != -1 && cur != 54) {
            classes[i] = lbl_8034E9A0._0000[cur / 9][cur % 9]._31;
            switch (classes[i]) {
            case 0:
                c0++;
                if (c0 >= 2) {
                    f0 = 1;
                }
                break;
            case 1:
                c1++;
                if (c1 >= 2) {
                    f1 = 1;
                }
                break;
            case 2:
                c2++;
                if (c2 >= 2) {
                    f2 = 1;
                }
                break;
            case 3:
                c3++;
                if (c3 >= 2) {
                    f3 = 1;
                }
                break;
            }
        }
    }
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._02[port][i] == -1 || lbl_803C6724._02[port][i] == 54) {
            memset(pool, -1, sizeof(pool));
            n = -1;
            if (!f0) {
                for (k = 0; k < 32; k++) {
                    id = lbl_80108DB8[k];
                    if (lbl_8034E9A0._0000[id / 9][id % 9]._31 == 0 && lbl_8034E9A0._4757[id] == 0) {
                        n++;
                        pool[n] = id;
                    }
                }
                if (pool[0] == -1) {
                    goto random;
                }
                id = pool[randRange_FUN_80042bf0(0, n)];
                c0++;
                if (c0 >= 2) {
                    f0 = 1;
                }
                goto found;
            }else if (!f1) {
                for (j = 0; j < 32; j++) {
                    id = lbl_80108DB8[j];
                    if (lbl_8034E9A0._0000[id / 9][id % 9]._31 == 1 && lbl_8034E9A0._4757[id] == 0) {
                        n++;
                        pool[n] = id;
                    }
                }
                if (pool[0] == -1) {
                    goto random;
                }
                id = pool[randRange_FUN_80042bf0(0, n)];
                c1++;
                if (c1 >= 2) {
                    f1 = 1;
                }
                goto found;
            }else if (!f2) {
                for (j = 0; j < 32; j++) {
                    id = lbl_80108DB8[j];
                    if (lbl_8034E9A0._0000[id / 9][id % 9]._31 == 2 && lbl_8034E9A0._4757[id] == 0) {
                        n++;
                        pool[n] = id;
                    }
                }
                if (pool[0] == -1) {
                    goto random;
                }
                id = pool[randRange_FUN_80042bf0(0, n)];
                c2++;
                if (c2 >= 2) {
                    f2 = 1;
                }
                goto found;
            }else if (!f3) {
                for (j = 0; j < 32; j++) {
                    id = lbl_80108DB8[j];
                    if (lbl_8034E9A0._0000[id / 9][id % 9]._31 == 3 && lbl_8034E9A0._4757[id] == 0) {
                        n++;
                        pool[n] = id;
                    }
                }
                if (pool[0] == -1) {
                    goto random;
                }
                id = pool[randRange_FUN_80042bf0(0, n)];
                c3++;
                if (c3 >= 2) {
                    f3 = 1;
                }
                goto found;
            }
        random:
            do {
                id = randRange_FUN_80042bf0(0, 0x35);
            } while (lbl_8034E9A0._4757[id] != 0);
        found:
            fn_80067B40(port, id, 1);
            for (g = 0; g < 9; g++) {
                for (j = 0; j < 5; j++) {
                    if (id == lbl_80108EDC[g][j]) {
                        lbl_8034E9A0._4757[lbl_80108EDC[g][1]] = 1;
                        lbl_8034E9A0._4757[lbl_80108EDC[g][2]] = 1;
                        lbl_8034E9A0._4757[lbl_80108EDC[g][3]] = 1;
                        lbl_8034E9A0._4757[lbl_80108EDC[g][4]] = 1;
                        id = lbl_80108EDC[g][0];
                        goto done;
                    }
                }
            }
        done:
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

// .text:0x0000ED94 size:0x46C
// 96%: the target forms &lbl_2_bss_F410._20[port] from the unextended port and
// allocates registers differently.
s32 fn_2_ED94(u8 port, u16 held, u16 trg, u16 rep) {
    s32 team;

    if (lbl_2_bss_F468._41[port] == 0) {
        if ((held & 8) || (held & 4) || (held & 1) || (held & 2)) {
            if (lbl_2_bss_F468._45[port] != 0) {
                if (lbl_2_bss_F468._47[port] == 0 && (held & 2)) {
                    lbl_2_bss_F468._47[port] = 1;
                    lbl_2_bss_F468._49[port] = 0;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                } else if (lbl_2_bss_F468._47[port] == 1 && (held & 1)) {
                    lbl_2_bss_F468._47[port] = 0;
                    lbl_2_bss_F468._49[port] = 0;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                rep = 0;
                trg = 0;
                held = 0;
            }
            if (lbl_2_bss_F468._59[port] != 0) {
                rep = 0;
                trg = 0;
                held = 0;
            }
            fn_2_57F0(port, held, trg, rep);
            return 1;
        }
    } else if (lbl_2_bss_F468._59[port] != 0) {
        lbl_2_bss_F468._41[port] = 0;
        fn_800625A4(port, 0xD);
        return 1;
    } else if (lbl_2_bss_F468._00[port] != 9) {
        lbl_2_bss_F468._20[port] = lbl_2_bss_F410._20[port];
        if (lbl_2_bss_F468._45[port] != 0) {
            if (lbl_2_bss_F468._47[port] == 0 && (held & 2)) {
                lbl_2_bss_F468._47[port] = 1;
                lbl_2_bss_F468._49[port] = 0;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            } else if (lbl_2_bss_F468._47[port] == 1 && (held & 1)) {
                lbl_2_bss_F468._47[port] = 0;
                lbl_2_bss_F468._49[port] = 0;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
            if (g_d_GameSettings._10 == 0 && port != 0) {
                team = lbl_8034E9A0._46F8[0] == 0;
                lbl_803C6028._74[team] = 1;
                lbl_2_bss_F410._20[port] = fn_80050760(team, 0, 0, 0, 0);
            } else {
                team = lbl_8034E9A0._46F8[port];
                if (lbl_8034E9A0._46FC[team] != 0) {
                    team = lbl_8034E9A0._46F8[0] == 0;
                }
                lbl_2_bss_F410._20[port] = fn_80050760(team, 0, 0, 0, 0);
            }
        } else {
            if (g_d_GameSettings._10 == 0 && port != 0) {
                team = lbl_8034E9A0._46F8[0] == 0;
                lbl_803C6028._74[team] = 1;
                lbl_2_bss_F410._20[port] = fn_80050760(team, held, trg, rep, 0);
            } else {
                team = lbl_8034E9A0._46F8[port];
                if (lbl_8034E9A0._46FC[team] != 0) {
                    team = lbl_8034E9A0._46F8[0] == 0;
                }
                lbl_2_bss_F410._20[port] = fn_80050760(team, held, trg, rep, 0);
            }
        }
    }
    if (trg & 0x100) {
        if (fn_2_35D0(port)) {
            return 1;
        }
        fn_2_DFAC(port);
        return 1;
    }
    if (trg & 0x200) {
        if (fn_2_35D0(port)) {
            return 1;
        }
        fn_2_CE44(port);
        return 1;
    }
    return 0;
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

// .text:0x0000EAE0 size:0x154
// 81%: the target addresses the cursor as word i + 8 of lbl_2_bss_F410,
// saves r27-r31, and allocates registers differently.
void fn_2_EAE0(void) {
    s32 i;
    s32 x;

    for (i = 0; i < (g_d_GameSettings._10 == 1) + 1; i++) {
        if (lbl_803C5EA4._08[i] != 0) {
            if (lbl_8034E9A0._4757[lbl_800FDE84[lbl_2_bss_F410._20[i]]] != 0) {
                do {
                    do {
                        lbl_2_bss_F410._20[i]++;
                        if (lbl_2_bss_F410._20[i] == 54) {
                            lbl_2_bss_F410._20[i] = 0;
                        }
                    } while (lbl_8034E9A0._4757[lbl_800FDE84[lbl_2_bss_F410._20[i]]] != 0);
                } while (lbl_2_bss_F410._20[0] == lbl_2_bss_F410._20[1]);
            }
            while (1) {
                x = lbl_8034E9A0._46F8[i];
                if (lbl_8034E9A0._46FC[x] != 0) {
                    x = lbl_8034E9A0._46F8[0] == 0;
                }
                fn_2_1D54(&lbl_2_bss_F410._20[i], x, 54);
            }
        }
    }
}

// .text:0x0000DFAC size:0xB34
// 99.8%: registers only, in the final _26 store's id / 9 and id % 9.
void fn_2_DFAC(s32 port) {
    s32 cap;
    s32 i;
    s32 g;
    CharEntry0318* entry;
    s32 j;
    s32 c;
    s32 id;
    s8 cursor;
    char slot = 0;
    s8 group = -1;
    s8 used = 0;
    s8 freeCount = 0;
    s32 locked;

    cursor = lbl_2_bss_F468._00[port];
    cap = fn_2_60D4(port);
    if (lbl_803C66B0._5D[0] == 11) {
        return;
    }
    for (i = 0; i < 9; i++) {
        if (cursor == lbl_803C6724._14[port][i]) {
            slot = i;
            break;
        }
    }
    if (lbl_2_bss_F468._41[port] == 0) {
        if (lbl_2_bss_F468._00[port] == 9) {
            fn_2_5444(port);
            fn_2_1C34(0x100);
        } else if (lbl_2_bss_F468._00[port] == 10) {
            locked = 0;
            if (g_d_GameSettings.GameModeSelected == 5 && lbl_2_bss_F468._3F[0] != 0) {
                locked = 1;
            }
            if (locked) {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                return;
            }
            fn_2_5184(port);
            fn_2_1C34(0x100);
        } else if (lbl_803C6724._02[port][slot] == lbl_8034E9A0._46E0[port]) {
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
        } else {
            locked = 0;
            if (g_d_GameSettings.GameModeSelected == 5 && lbl_2_bss_F468._3F[0] != 0) {
                locked = 1;
            }
            if (locked) {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                return;
            }
            lbl_2_bss_F468._41[port] = 1;
            fn_800625A4(port, 13);
            fn_2_1C34(0x100);
        }
        return;
    }
    if (lbl_8034E9A0._4757[lbl_2_bss_F410._20[port]] != 0 || lbl_2_bss_F410._20[port] == -1) {
        sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
        return;
    }
    locked = 0;
    if (g_d_GameSettings.GameModeSelected == 5 && lbl_2_bss_F468._3F[0] != 0) {
        locked = 1;
    }
    if (locked) {
        return;
    }
    if (g_d_GameSettings._10 == 1 && lbl_2_bss_F410._20[port] != -1 &&
        lbl_2_bss_F410._20[port] == lbl_2_bss_F410._20[port ^ 1] && lbl_2_bss_F468._41[port ^ 1] != 0) {
        sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
        return;
    }
    if (g_d_GameSettings.GameModeSelected != 5) {
        if (lbl_803C6724._02[port][slot] != -1 && lbl_803C6724._02[port][slot] != 54) {
            fn_800506E8(port, lbl_803C6724._02[port][slot], 0);
            lbl_8034E9A0._4757[lbl_803C6724._02[port][slot]] = 0;
            fn_80067B40(port, lbl_803C6724._02[port][slot], 0);
        }
    } else {
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._02[port][i] != -1 && lbl_803C6724._02[port][i] != 54 && lbl_803C6724._02[port][i] != cap) {
                used++;
            }
        }
        for (c = 0; c < 54; c++) {
            if (lbl_8034E9A0._4757[c] == 0) {
                freeCount++;
            }
        }
        if (freeCount <= 8 - used && lbl_803C6724._02[port][slot] != -1 && lbl_803C6724._02[port][slot] != 54) {
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            return;
        }
        if (lbl_803C6724._02[port][slot] != -1 && lbl_803C6724._02[port][slot] != 54) {
            if (fn_80067B40(port, lbl_803C6724._02[port][slot], 2)) {
                for (g = 0; g < 9; g++) {
                    for (j = 0; j < 5; j++) {
                        if (lbl_803C6724._02[port][slot] == lbl_80108EDC[g][j]) {
                            group = g;
                            goto found;
                        }
                    }
                }
            found:
                if (group != -1) {
                    for (i = 0; i < 9; i++) {
                        for (j = 0; j < 5; j++) {
                            if (lbl_803C6724._02[port][i] == lbl_80108EDC[group][j] && i != slot && lbl_80108EDC[group][j] != -1) {
                                goto done;
                            }
                        }
                    }
                    fn_800506E8(port, fn_80067AC8(lbl_803C6724._02[port][slot], 0), 0);
                    lbl_8034E9A0._4757[fn_80067AC8(lbl_803C6724._02[port][slot], 0)] = 0;
                }
            } else {
                fn_800506E8(port, lbl_803C6724._02[port][slot], 0);
                lbl_8034E9A0._4757[lbl_803C6724._02[port][slot]] = 0;
            }
        }
    }
done:
    id = lbl_2_bss_F410._20[port];
    lbl_803C6724._02[port][slot] = id;
    lbl_803C6724._4A[port][slot] = 1;
    fn_800628D4(lbl_803C6724._02[port][slot]);
    fn_800678CC(port);
    fn_2_C698(slot, port);
    lbl_803C5EA4._0C[port] = slot;
    lbl_803C5EA4._0A[port] = 1;
    entry = &lbl_8034E9A0._0000[id / 9][id % 9];
    lbl_803C6724._26[port][slot] = entry->_3B[cap];
    fn_800625A4(port, 15);
    if (lbl_2_bss_F468._37[port] != 0) {
        lbl_2_bss_F468._41[port] = 0;
    }
}

// .text:0x0000CE44 size:0x1168
// 93.5% draft: the target forms lbl_2_bss_F468._00[port] as base plus port*4
// (lwzx), materializes the lock flag with neg/or/srwi, and allocates otherwise.
void fn_2_CE44(s32 port) {
    s32 used = 0;
    s8 freeCount = 0;
    s32 locked = 0;
    s32 cap;
    s32 i;
    s32 c;
    s32 t;
    s32 cursor;
    s8 slot;
    s8 id;

    if (g_d_GameSettings.GameModeSelected == 5 && lbl_2_bss_F468._3F[0] != 0) {
        locked = 1;
    }
    if (locked != 0) {
        sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
        return;
    }
    if (lbl_2_bss_F468._41[port] != 0) {
        lbl_2_bss_F468._41[port] = 0;
        fn_800625A4(port, 13);
        goto end;
    }
    cap = lbl_8034E9A0._46E0[port];
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._02[port][i] != -1 && lbl_803C6724._02[port][i] != 54 && lbl_803C6724._02[port][i] != cap) {
            used++;
        }
    }
    if (g_d_GameSettings.GameModeSelected == 5) {
        for (c = 0; c < 54; c++) {
            if (lbl_8034E9A0._4757[c] == 0) {
                freeCount++;
            }
        }
        if (freeCount <= 8 - used) {
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            return;
        }
    }
    lbl_2_bss_F468._08[port] = lbl_2_bss_F468._00[port];
    if (used == 0) {
        lbl_2_bss_F468._37[port] = 0;
        if (lbl_2_bss_F468._00[port] == 9) {
            lbl_2_bss_F468._00[port] = 0;
            switch (port) {
            case 0:
                if (lbl_803C6724._02[0][0] == lbl_8034E9A0._46E0[0]) {
                    lbl_2_bss_F468._00[0] = 1;
                }
                break;
            case 1:
                if (lbl_803C6724._02[1][0] == lbl_8034E9A0._46E0[1]) {
                    lbl_2_bss_F468._00[1] = 1;
                }
                break;
            }
        }
    }
    if (g_d_GameSettings._10 == 0) {
        if (lbl_2_bss_F468._00[port] != 9 && lbl_2_bss_F468._00[port] != 10 && used != 0) {
            fn_2_4970(port, cap);
        } else if (lbl_2_bss_F468._00[port] == 9) {
            lbl_2_bss_F468._08[port] = lbl_2_bss_F468._00[port];
            lbl_2_bss_F468._00[port]--;
            if (cap == lbl_803C6724._02[port][8]) {
                lbl_2_bss_F468._00[port]--;
            }
            fn_800625A4(port, 21);
        } else if (lbl_2_bss_F468._00[port] == 10) {
            if (used == 0 && lbl_803C5EA4._0E != 0) {
                lbl_2_bss_100B8._2E[1] = 0;
                lbl_2_bss_100B8._2E[0] = 0;
                lbl_803C5EA4._0E = 0;
                lbl_803C66B0._59[1] = 0;
                lbl_803C66B0._59[0] = 0;
                lbl_2_bss_F468._00[1] = 9;
                lbl_2_bss_F468._00[0] = 9;
                fn_800625A4(0, 18);
            } else if (used == 0 && lbl_803C5EA4._0E == 0) {
                if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
                    return;
                }
                for (t = 0; t < 2; t++) {
                    for (i = 0; i < 9; i++) {
                        lbl_803C6724._26[t][i] = 0;
                    }
                }
                fn_2_EC54(port);
            } else {
                lbl_2_bss_F468._08[port] = lbl_2_bss_F468._00[port];
                lbl_2_bss_F468._00[port] = 8;
                if (cap == lbl_803C6724._02[port][8]) {
                    lbl_2_bss_F468._00[port]--;
                }
                fn_800625A4(port, 21);
            }
        } else if (lbl_2_bss_F468._37[0] != 0 && used == 0) {
            lbl_2_bss_100B8._2E[1] = 0;
            lbl_2_bss_100B8._2E[0] = 0;
            lbl_803C5EA4._0E = 0;
            lbl_803C66B0._59[1] = 0;
            lbl_803C66B0._59[0] = 0;
            lbl_2_bss_F468._00[1] = 9;
            lbl_2_bss_F468._00[0] = 9;
            fn_800625A4(0, 18);
        } else if (used == 0) {
            if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
                return;
            }
            for (t = 0; t < 2; t++) {
                for (i = 0; i < 9; i++) {
                    lbl_803C6724._26[t][i] = 0;
                }
            }
            fn_2_EC54(port);
        }
    } else if (g_d_GameSettings._10 == 1) {
        if (lbl_2_bss_F468._00[port] != 9 && lbl_2_bss_F468._00[port] != 10) {
            if (used == 0) {
                if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
                    return;
                }
                lbl_2_bss_F468._45[1] = 0;
                lbl_2_bss_F468._45[0] = 0;
                lbl_2_bss_F468._00[1] = 0;
                lbl_2_bss_F468._00[0] = 0;
                lbl_2_bss_F468._5F[1] = 0;
                lbl_2_bss_F468._5F[0] = 0;
                fn_2_EC54(port);
                return;
            }
            cursor = lbl_2_bss_F468._00[port];
            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._14[port][i] == cursor) {
                    slot = i;
                }
            }
            lbl_2_bss_F468._00[port] = cursor;
            if (lbl_803C6724._02[port][slot] == cap) {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                return;
            }
            lbl_2_bss_F468._08[port] = lbl_2_bss_F468._00[port];
            lbl_2_bss_F468._00[port]--;
            if (lbl_2_bss_F468._00[port] < 0) {
                lbl_2_bss_F468._00[port] = 8;
            }
            if (lbl_803C6724._02[port][lbl_2_bss_F468._00[port]] == cap) {
                lbl_2_bss_F468._00[port]--;
                if (lbl_2_bss_F468._00[port] < 0) {
                    lbl_2_bss_F468._00[port] = 8;
                }
            }
            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._14[port][i] == lbl_2_bss_F468._08[port]) {
                    slot = i;
                }
            }
            if (lbl_803C6724._02[port][slot] != -1) {
                fn_2_C698(slot, port);
                fn_800506E8(port, lbl_803C6724._02[port][slot], 0);
                fn_80067B40(port, lbl_803C6724._02[port][slot], 0);
                id = lbl_803C6724._02[port][slot];
                lbl_803C6724._26[port][slot] = 0;
                lbl_803C6724._02[port][slot] = -1;
                lbl_2_bss_F468._3D[0] = 0;
                lbl_8034E9A0._4757[id] = 0;
                lbl_803C6724._4A[port][slot] = 0;
                lbl_2_bss_F468._37[port] = 0;
            }
            fn_800625A4(port, 16);
        } else if (lbl_2_bss_100B8._2E[port] != 0) {
            lbl_2_bss_100B8._2E[port] = 0;
            fn_800625A4(port, 18);
            fn_2_1C34(0x200);
            return;
        } else if (used != 0) {
            lbl_2_bss_F468._08[port] = lbl_2_bss_F468._00[port];
            lbl_2_bss_F468._00[port] = 8;
            if (cap == lbl_803C6724._02[port][8]) {
                lbl_2_bss_F468._00[port]--;
            }
            fn_800625A4(port, 21);
            fn_2_1C34(0x200);
            return;
        } else {
            if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
                return;
            }
            for (t = 0; t < 2; t++) {
                for (i = 0; i < 9; i++) {
                    lbl_803C6724._26[t][i] = 0;
                }
            }
            lbl_2_bss_F468._45[1] = 0;
            lbl_2_bss_F468._45[0] = 0;
            lbl_2_bss_F468._00[1] = 0;
            lbl_2_bss_F468._00[0] = 0;
            lbl_2_bss_F468._5F[1] = 0;
            lbl_2_bss_F468._5F[0] = 0;
            for (t = 0; t < 2; t++) {
                for (i = 1; i < 9; i++) {
                    lbl_8034E9A0._4757[lbl_803C6724._02[t][i]] = 0;
                    fn_800506E8(lbl_8034E9A0._46F8[t], lbl_803C6724._02[t][i], 0);
                    fn_80067B40(t, lbl_803C6724._02[t][i], 0);
                    lbl_803C6724._02[t][i] = -1;
                    lbl_803C6724._4A[t][i] = 0;
                    lbl_803C6724._26[t][i] = 0;
                }
                lbl_2_bss_F468._37[t] = 0;
                if (lbl_2_bss_F468._00[t] == 9) {
                    lbl_2_bss_F468._00[t] = 0;
                    switch (t) {
                    case 0:
                        if (lbl_803C6724._02[0][0] == lbl_8034E9A0._46E0[0]) {
                            lbl_2_bss_F468._00[0] = 1;
                        }
                        break;
                    case 1:
                        if (lbl_803C6724._02[1][0] == lbl_8034E9A0._46E0[1]) {
                            lbl_2_bss_F468._00[1] = 11;
                        }
                        break;
                    }
                }
                lbl_2_bss_F468._3D[t] = 0;
            }
            fn_2_EC54(port);
        }
    }
end:
    fn_2_1C34(0x200);
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
void fn_2_CA60(u8 idx, u8 team) {
    s8 id = lbl_803C6724._02[team][idx];

    if (id != -1 && id != 54) {
        inMemRoster[team][idx].CharID = id;
        lbl_80354720[team][idx]._1 = idx;
        lbl_80354720[team][idx]._0 = idx;
    } else {
        fn_2_A1A0(idx, team);
    }
    fn_2_C698(idx, team);
}

// .text:0x0000C7DC size:0x284
// 88%: the slot stores are scheduled differently, and the retry loop
// compares its operands in the other order.
void fn_2_C7DC(u8 idx, u8 team) {
    s32 i;
    s32 id;

retry:
    if (idx == 0) {
        inMemRoster[team][idx].CharID = lbl_8034E9A0._46E0[team];
        lbl_80354720[team][idx]._1 = idx;
        lbl_80354720[team][idx]._0 = idx;
        lbl_80354720[team][idx]._2 = idx;
        lbl_80353B98[team][idx]._1 = idx;
        lbl_80353B98[team][idx]._0 = idx;
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
        inMemRoster[team][idx].CharID = id;
        lbl_80354720[team][idx]._1 = idx;
        lbl_80354720[team][idx]._0 = idx;
        lbl_80354720[team][idx]._2 = idx;
        lbl_80353B98[team][idx]._1 = idx;
        lbl_80353B98[team][idx]._0 = idx;
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

// .text:0x0000BF90 size:0x394
// 98%: the target gives grp and the last loop's counter one register (r26)
// and loads 0 twice before the stores to _10.
void fn_2_BF90(void) {
    s32 i;
    s32 grp = -1;

    memset(lbl_8034E9A0._4757, 0, sizeof(lbl_8034E9A0._4757));
    for (i = 0; i < 12; i++) {
        if (lbl_80108EC4[i] == starMissionCompletionTracker._441F) {
            lbl_8034E9A0._470C = i;
            grp = lbl_8034E9A0._470C;
        }
    }
    lbl_2_bss_F468._10[1] = 0;
    lbl_2_bss_F468._10[0] = 0;
    for (i = 0; i < 9; i++) {
        lbl_803C6724._02[1][i] = lbl_8034E9A0._4380[grp][lbl_2_bss_F468._10[1]][i];
    }
    for (i = 0; i < 9; i++) {
        fn_2_CA60(i, 1);
    }
}

// .text:0x0000B920 size:0x670
void fn_2_B920(void) {
    s32 i;
    s32 r;
    s32 t;
    s8 mode;
    s32 grp[2];

    grp[0] = grp[1] = 0;
    memset(lbl_8034E9A0._4757, 0, sizeof(lbl_8034E9A0._4757));
    if (g_d_GameSettings.GameModeSelected != 5) {
        for (i = 0; i < 12; i++) {
            if (lbl_80108EC4[i] == lbl_8034E9A0._46E0[0]) {
                grp[0] = lbl_8034E9A0._470B = i;
            } else if (lbl_80108EC4[i] == lbl_8034E9A0._46E0[1]) {
                grp[1] = lbl_8034E9A0._470C = i;
            }
        }
    } else {
        for (i = 0; i < 12; i++) {
            if (lbl_80108EC4[i] == starMissionCompletionTracker._441D) {
                lbl_8034E9A0._470B = i;
            } else if (lbl_80108EC4[i] == starMissionCompletionTracker._441F) {
                lbl_8034E9A0._470C = i;
            }
        }
    }
    fn_2_A288();
    if (lbl_2_bss_3E0[0] != -1) {
        do {
            r = fn_2_14F8(1, 2);
        } while (lbl_2_bss_3E0[r] == 0);
        mode = r;
    } else {
        mode = -1;
    }
    if (mode != -1) {
        switch (mode) {
        case 0:
            lbl_2_bss_F468._10[0] = 1;
            break;
        case 1:
            lbl_2_bss_F468._10[0] = 2;
            break;
        }
    } else {
        lbl_2_bss_F468._10[0] = 3;
    }
    lbl_2_bss_F468._10[1] = 3;
    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            lbl_803C6724._02[t][i] = lbl_8034E9A0._4380[grp[t]][lbl_2_bss_F468._10[t]][i];
        }
    }
    fn_2_ABC0(0);
    lbl_8034E9A0._4757[lbl_8034E9A0._46E0[1]] = 1;
    for (i = 0; i < 9; i++) {
        fn_2_CA60(i, 0);
    }
    lbl_80354720[1][0]._2 = 0;
    lbl_80353B98[1][0]._2 = 0;
    lbl_803C6724._02[1][0] = lbl_8034E9A0._46E0[1];
    lbl_803C6724._4A[1][0] = 1;
    for (i = 1; i < 9; i++) {
        lbl_80354720[1][i]._2 = i;
        lbl_80353B98[1][i]._2 = i;
        lbl_803C6724._02[1][i] = 54;
        lbl_803C6724._4A[1][i] = 0;
    }
}

// .text:0x0000B66C size:0x2B4
void fn_2_B66C(void) {
    s32 i;
    s32 r;
    s8 mode;

    fn_2_A6E0();
    if (lbl_2_bss_3E0[0] != -1) {
        do {
            r = fn_2_14F8(1, 2);
        } while (lbl_2_bss_3E0[r] == 0);
        mode = r;
    } else {
        mode = -1;
    }
    if (mode != -1) {
        switch (mode) {
        case 0:
            lbl_2_bss_F468._10[1] = 1;
            break;
        case 1:
            lbl_2_bss_F468._10[1] = 2;
            break;
        }
    } else {
        lbl_2_bss_F468._10[1] = 3;
    }
    fn_2_ABC0(1);
    for (i = 0; i < 9; i++) {
        fn_2_CA60(i, 1);
    }
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

// .text:0x0000AEE8 size:0x43C
// 99.9%: the target keeps cap in r29 apart from the remainder in r26.
void fn_2_AEE8(void) {
    u8 order[2][54];
    u8 value[54];
    s32 t;
    s32 i;
    s32 j;
    u8 max;
    u8 tmpOrder;
    u8 tmpValue;
    s32 cap;
    s32 row;
    s32 col;

    for (t = 0; t < 2; t++) {
        for (i = 0; i < 54; i++) {
            order[t][i] = i;
        }
    }
    for (t = 0; t < 2; t++) {
        cap = lbl_8034E9A0._46E0[t];
        row = cap / 9;
        col = cap % 9;
        for (i = 0; i < 54; i++) {
            value[i] = lbl_8034E9A0._0000[row][col]._3B[i];
        }
        for (i = 0; i < 54; i++) {
            max = value[i];
            for (j = i + 1; j < 54; j++) {
                if (max < value[j]) {
                    tmpValue = value[i];
                    max = value[j];
                    tmpOrder = order[t][i];
                    value[i] = value[j];
                    order[t][i] = order[t][j];
                    value[j] = tmpValue;
                    order[t][j] = tmpOrder;
                }
            }
        }
    }
    for (t = 0; t < 2; t++) {
        for (i = 0; i < 54; i++) {
            lbl_8034E9A0._478D[t][i] = order[t][i];
        }
    }
}

// .text:0x0000ABC0 size:0x328
// 97.5%: registers only.
void fn_2_ABC0(u8 port) {
    u8 order[54];
    u8 value[54];
    s32 i;
    s32 j;
    u8 max;
    u8 tmpOrder;
    u8 tmpValue;
    s32 cap = lbl_8034E9A0._46E0[port];
    s32 row = cap / 9;
    s32 col = cap % 9;

    for (i = 0; i < 54; i++) {
        value[i] = lbl_8034E9A0._0000[row][col]._3B[i];
        order[i] = i;
    }
    for (i = 0; i < 54; i++) {
        max = value[i];
        for (j = i + 1; j < 54; j++) {
            if (max < value[j]) {
                tmpValue = value[i];
                max = value[j];
                tmpOrder = order[i];
                value[i] = value[j];
                order[i] = order[j];
                value[j] = tmpValue;
                order[j] = tmpOrder;
            }
        }
    }
    for (i = 0; i < 54; i++) {
        lbl_8034E9A0._478D[port][i] = order[i];
    }
}

// .text:0x0000A6E0 size:0x4E0
void fn_2_A6E0(void) {
    s32 k;
    u8 count = 0;

    if (g_d_GameSettings.GameModeSelected == 5) {
        return;
    }
    if (lbl_2_bss_100B8._2E[0] != 0 && g_d_GameSettings._10 == 0) {
        lbl_2_bss_3E0[1] = fn_2_A50C() == 0;
        lbl_2_bss_3E0[2] = fn_2_A50C() == 0;
        if (lbl_2_bss_3E0[1] == 0 && lbl_2_bss_3E0[2] == 0) {
            lbl_2_bss_3E0[0] = -1;
        }
        return;
    }
    for (k = 1; k < 3; k++) {
        if (fn_2_A62C() == 0) {
            lbl_2_bss_3E0[k - 1] = 1;
        } else {
            lbl_2_bss_3E0[k - 1] = 0;
        }
        if (fn_2_A62C() == 0) {
            lbl_2_bss_3E0[k + 1] = 1;
        } else {
            lbl_2_bss_3E0[k + 1] = 0;
        }
    }
    for (k = 0; k < 4; k++) {
        if (lbl_2_bss_3E0[k] == 0) {
            count++;
        }
    }
    if (count == 4) {
        lbl_2_bss_3E0[0] = -1;
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

// .text:0x0000A288 size:0x284
void fn_2_A288(void) {
    s32 i;
    s32 k;
    s32 j;
    s32 grp;
    u8 count = 0;
    s32 v;

    for (i = 0; i < 12; i++) {
        if (lbl_80108EC4[i] == lbl_8034E9A0._46E0[0]) {
            grp = lbl_8034E9A0._470B = i;
        } else if (lbl_80108EC4[i] == lbl_8034E9A0._46E0[1]) {
            lbl_8034E9A0._470C = i;
        }
    }
    for (k = 1; k < 3; k++) {
        for (j = 1; j < 9; j++) {
            v = lbl_8034E9A0._4380[grp][k][j];
            if (v == lbl_8034E9A0._46E0[1] && v != 0xFF) {
                lbl_2_bss_3E0[k - 1] = -1;
            }
        }
        if (lbl_2_bss_3E0[k - 1] != -1) {
            lbl_2_bss_3E0[k - 1] = 1;
        } else {
            lbl_2_bss_3E0[k - 1] = 0;
        }
    }
    if (lbl_2_bss_3E0[1] == 0) {
        count++;
    }
    if (lbl_2_bss_3E0[2] == 0) {
        count++;
    }
    if (count == 2) {
        lbl_2_bss_3E0[0] = -1;
    }
}

// .text:0x0000A1A0 size:0xE8
void fn_2_A1A0(u8 idx, u8 team) {
    s32 i;
    s32 t;
    s32 slot;
    s8 id = 0;

retry:
    if (lbl_8034E9A0._4757[id] != 0) {
        goto retry;
    }
    for (i = 0; i < idx; i++) {
        for (t = 0; t < 2; t++) {
            if (g_d_GameSettings._10 == 0 && lbl_2_bss_100B8._2E[0] != 0) {
                slot = lbl_803C6724._02[t][i];
            } else {
                slot = lbl_803C6724._02[team][i];
            }
            if (slot == id) {
                goto retry;
            }
        }
    }
    lbl_803C6724._02[team][idx] = id;
}

// .text:0x0000A040 size:0x160
void fn_2_A040(s32 group, s32 slot, u8 team, u8 idx) {
    s32 i;
    s32 j;

    if (lbl_80108EDC[group][slot] != -1 && slot < 4) {
        slot++;
        if (slot == 5 || lbl_80108EDC[group][slot] == -1) {
            slot = 0;
        }
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 9; j++) {
                if (lbl_803C6724._02[i][j] == lbl_80108EDC[group][slot]) {
                    return;
                }
            }
        }
        lbl_803C6724._02[team][idx] = lbl_80108EDC[group][slot];
    } else {
        lbl_803C6724._02[team][idx] = lbl_80108EDC[group][0];
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

// .text:0x00009ACC size:0x4A4
// 95%: registers in the stats copy (r0/r3 swapped) and the team loop counter.
// The copy is fn_2_8940's; an inline helper shared by both may be the original.
void fn_2_9ACC(u16 team) {
    s32 t;
    s32 i;
    CharEntry0318* dst;
    CharEntry0318* src;

    if (g_d_GameSettings._10 == 1) {
        for (i = 0; i < 9; i++) {
            if (lbl_2_bss_100B8._30[team] != 0) {
                src = &lbl_2_bss_E8CC[team][i];
                dst = &inMemRoster[team][i];
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
                lbl_80354720[team][i]._0 = lbl_2_bss_DCE8._000[team][i]._0;
                lbl_80354720[team][i]._1 = lbl_2_bss_DCE8._000[team][i]._1;
                lbl_80354720[team][i]._2 = lbl_2_bss_DCE8._000[team][i]._2;
                lbl_80354720[team][i]._3 = lbl_2_bss_DCE8._000[team][i]._3;
                inMemRoster[team][i].CharID = lbl_8034E9A0._46E0[team];
            }
        }
    } else {
        for (t = 0; t < 2; t++) {
            for (i = 0; i < 9; i++) {
                if (lbl_2_bss_100B8._30[t] != 0) {
                    src = &lbl_2_bss_E8CC[t][i];
                    dst = &inMemRoster[t][i];
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
                    lbl_80354720[t][i]._0 = lbl_2_bss_DCE8._000[t][i]._0;
                    lbl_80354720[t][i]._1 = lbl_2_bss_DCE8._000[t][i]._1;
                    lbl_80354720[t][i]._2 = lbl_2_bss_DCE8._000[t][i]._2;
                    lbl_80354720[t][i]._3 = lbl_2_bss_DCE8._000[t][i]._3;
                    inMemRoster[t][i].CharID = lbl_8034E9A0._46E0[t];
                }
            }
        }
    }
}

// .text:0x000095D8 size:0x4F4
// 92.6%: the target keeps g_d_GameSettings's address from the first loop for
// the second instead of forming it again, so its first loop uses r25-r31.
void fn_2_95D8(void) {
    u32 color[2];
    s8 slots[2][9];
    s8 chars[54];
    s32 t;
    s32 i;
    s32 j;
    s32 cursor;
    s32 cap;
    s32 y;

    if (lbl_803CBBCC->_4 < 4) {
        for (t = 0; t < 2; t++) {
            if (t == 0) {
                cursor = lbl_2_bss_F468._00[t];
            } else {
                cursor = lbl_2_bss_F468._00[t] - 10;
            }
            if (t == 0) {
                color[t] = 0xFF0F;
            } else {
                color[t] = 0xF00F;
            }
            for (i = 0; i < 9; i++) {
                for (j = 0; j < 9; j++) {
                    if (i == lbl_80354720[t][j]._1) {
                        break;
                    }
                }
                if (g_d_GameSettings.GameModeSelected != 5) {
                    cap = lbl_8034E9A0._46E0[t];
                } else if (t == 0) {
                    cap = lbl_8034E9A0._46E0[t];
                } else {
                    cap = starMissionCompletionTracker._441F;
                }
                if (lbl_803C6724._02[t][i] == cap) {
                    color[t] = 0x88FF;
                } else if (i == cursor) {
                    color[t] = 0xFF0F;
                } else {
                    color[t] = 0xFFFF;
                }
            }
        }
        y = 5;
        for (t = 0; t < 2; t++) {
            for (j = 0; j < 9; j++) {
                slots[t][j] = -1;
            }
        }
        for (i = 0; i < 54; i++) {
            chars[i] = -1;
        }
        for (i = 0; i < 54; i++) {
            if (i == lbl_2_bss_F410._20[0]) {
                color[0] = 0xFFF;
            } else if (i == lbl_2_bss_F410._20[1]) {
                color[1] = 0xF0FF;
            } else {
                color[0] = 0xFFFF;
                color[1] = 0xFFFF;
            }
            for (t = 0; t < 2; t++) {
                for (j = 0; j < 9; j++) {
                    if (i == lbl_803C6724._02[t][j] && t == 0 && color[0] != 0xFFF) {
                        chars[i] = i;
                        color[0] = 0x88F;
                        slots[t][j] = i;
                    } else if (i == lbl_803C6724._02[t][j] && t != 0 && color[0] != 0xFFF) {
                        chars[i] = i;
                        color[0] = 0x808F;
                        slots[t][j] = i;
                    }
                }
            }
            if (lbl_8034E9A0._4757[i] != 0 && chars[i] == -1) {
                color[0] = 0x888F;
            }
            if (g_d_GameSettings._10 != 1 || i != lbl_2_bss_F410._20[1]) {
                y++;
            }
            if (y == 26) {
                y = 6;
            }
        }
    }
    if ((lbl_803CBBCC->_4 >= 2 && lbl_803CBBCC->_4 < 4) || lbl_803CBBCC->_4 == 9 || lbl_803CBBCC->_4 == 19) {
        return;
    }
    if (lbl_803CBBCC->_4 == 4) {
        return;
    }
}

// .text:0x00008CF8 size:0x8E0
void fn_2_8CF8(u16 team) {
    CharEntry0318* dst;
    CharEntry0318* src;
    s32 t;
    s32 i;

    if (lbl_2_bss_100B8._30[team] != 0) {
        if (g_d_GameSettings._10 != 1) {
            for (t = 0; t < 2; t++) {
                for (i = 0; i < 9; i++) {
                    src = &inMemRoster[t][i];
                    dst = &lbl_2_bss_E8CC[t][i];
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
                    lbl_2_bss_DCE8._000[t][i]._0 = lbl_80354720[t][i]._0;
                    lbl_2_bss_DCE8._000[t][i]._1 = lbl_80354720[t][i]._1;
                    lbl_2_bss_DCE8._000[t][i]._2 = lbl_80354720[t][i]._2;
                    lbl_2_bss_DCE8._000[t][i]._3 = lbl_80354720[t][i]._3;
                    lbl_2_bss_3E4[t][i] = inMemRoster[t][i].CharID;
                }
            }
        } else {
            for (i = 0; i < 9; i++) {
                src = &inMemRoster[team][i];
                dst = &lbl_2_bss_E8CC[team][i];
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
                lbl_2_bss_DCE8._000[team][i]._0 = lbl_80354720[team][i]._0;
                lbl_2_bss_DCE8._000[team][i]._1 = lbl_80354720[team][i]._1;
                lbl_2_bss_DCE8._000[team][i]._2 = lbl_80354720[team][i]._2;
                lbl_2_bss_DCE8._000[team][i]._3 = lbl_80354720[team][i]._3;
                lbl_2_bss_3E4[team][i] = inMemRoster[team][i].CharID;
            }
        }
        fn_2_9ACC(team);
    } else if (g_d_GameSettings._10 != 1) {
        for (t = 0; t < 2; t++) {
            for (i = 0; i < 9; i++) {
                src = &lbl_2_bss_E8CC[t][i];
                dst = &inMemRoster[t][i];
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
                lbl_80354720[t][i]._0 = lbl_2_bss_DCE8._000[t][i]._0;
                lbl_80354720[t][i]._1 = lbl_2_bss_DCE8._000[t][i]._1;
                lbl_80354720[t][i]._2 = lbl_2_bss_DCE8._000[t][i]._2;
                lbl_80354720[t][i]._3 = lbl_2_bss_DCE8._000[t][i]._3;
                inMemRoster[t][i].CharID = lbl_2_bss_3E4[t][i];
            }
        }
    } else {
        for (i = 0; i < 9; i++) {
            src = &lbl_2_bss_E8CC[team][i];
            dst = &inMemRoster[team][i];
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
            lbl_80354720[team][i]._0 = lbl_2_bss_DCE8._000[team][i]._0;
            lbl_80354720[team][i]._1 = lbl_2_bss_DCE8._000[team][i]._1;
            lbl_80354720[team][i]._2 = lbl_2_bss_DCE8._000[team][i]._2;
            lbl_80354720[team][i]._3 = lbl_2_bss_DCE8._000[team][i]._3;
            inMemRoster[team][i].CharID = lbl_2_bss_3E4[team][i];
        }
    }
}

// .text:0x00008940 size:0x3B8
void fn_2_8940(void) {
    CharEntry0318* dst;
    CharEntry0318* src;
    s32 t;
    s32 i;
    s8 id;
    u16 value;

    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            id = lbl_803C6724._02[t][i];
            src = &lbl_8034E9A0._0000[id / 9][id % 9];
            dst = &inMemRoster[t][i];
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
            lbl_80354720[t][i]._2 = lbl_803C6724._14[t][i];
            if (t == 0 && g_d_GameSettings.GameModeSelected == 5) {
                value = lbl_2_bss_3A8[starMissionCompletionTracker._40B8[i]._0];
                dst->_26 = value / 2;
                dst->_27 = value % 2;
            }
        }
    }
    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            lbl_803C5EA4._12[t][i] = lbl_803C6724._02[t][i];
        }
    }
    fn_80066EAC(0);
    fn_80066EAC(1);
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

// .text:0x00007DDC size:0x910
// 99.97%: registers only: the target gives the loop counter in the
// fn_80067B40(0, ..., 2) loop r24, not c's r23.
void fn_2_7DDC(void) {
    u8 ports[4];
    s32 k;
    s32 j;
    s32 g;
    s32 i;
    s32 c;
    s16 id;

    if (g_d_GameSettings.GameModeSelected != 5) {
        memset(lbl_8034E9A0._4757, 0, sizeof(lbl_8034E9A0._4757));
    }
    lbl_8034E9A0._48AD = 0;
    lbl_803C66B0._00 = 2;
    memset(ports, 0xFF, sizeof(ports));
    if (lbl_803CBBCC->_6 == 9) {
        lbl_803C66B0._59[0] = 0;
        lbl_803C66B0._59[1] = 1;
    } else {
        if (g_d_GameSettings._10 == 0 && g_d_GameSettings.GameModeSelected != 5) {
            lbl_803C66B0._59[0] = 1;
        } else {
            lbl_803C66B0._59[0] = 0;
        }
        lbl_803C66B0._59[1] = 1;
    }
    memset(ports, 0, sizeof(ports));
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
    if (g_d_GameSettings.GameModeSelected != 5) {
        fn_80050FE8(ports[0], ports[1], ports[2], ports[3], 0, 1);
    } else {
        fn_80050FE8(ports[0], ports[1], ports[2], ports[3], 0, 0);
    }
    fn_2_7265C();
    lbl_8034E9A0._472A = 0xFF;
    if (lbl_803CBBCC->_6 != 11 && g_d_GameSettings.GameModeSelected != 5) {
        lbl_2_bss_F468._00[0] = 10;
        lbl_2_bss_F468._00[1] = 10;
    } else {
        lbl_2_bss_F468._00[0] = 9;
        lbl_2_bss_F468._00[1] = 9;
    }
    if (g_d_GameSettings.GameModeSelected == 5) {
        for (c = 0; c < 54; c++) {
            if (starMissionCompletionTracker.characters[c]._31 == 1) {
                lbl_8034E9A0._4757[c] = 0;
                fn_800506E8(0, c, 0);
            } else {
                lbl_8034E9A0._4757[c] = 1;
                id = fn_80067AC8(c, 0);
                if (id != -1 && starMissionCompletionTracker.characters[id]._31 == 1) {
                    fn_800506E8(0, c, 0);
                } else {
                    fn_800506E8(0, c, 1);
                }
            }
        }
        for (i = 0; i < 9; i++) {
            lbl_8034E9A0._4757[lbl_803C6724._02[0][i]] = 1;
            fn_800506E8(0, lbl_803C6724._02[0][i], 1);
            if (fn_80067B40(0, lbl_803C6724._02[0][i], 2)) {
                for (g = 0; g < 9; g++) {
                    for (j = 0; j < 5; j++) {
                        if (lbl_803C6724._02[0][i] == lbl_80108EDC[g][j]) {
                            for (k = 0; k < 5; k++) {
                                if (lbl_80108EDC[g][k] == -1) {
                                    goto next;
                                }
                                lbl_8034E9A0._4757[lbl_80108EDC[g][k]] = 1;
                            }
                        }
                    }
                }
            }
        next:;
        }
        lbl_2_bss_F468._37[0] = 1;
    } else {
        fn_2_348C();
        for (g = 0; g < 2; g++) {
            for (j = 0; j < 9; j++) {
                if (lbl_803C6724._02[g][j] != -1) {
                    lbl_8034E9A0._4757[lbl_803C6724._02[g][j]] = 1;
                    if (g_d_GameSettings._10 == 0 && g != 0) {
                        if (lbl_8034E9A0._46F8[0] == 0) {
                            fn_800506E8(1, lbl_803C6724._02[g][j], 1);
                        } else {
                            fn_800506E8(0, lbl_803C6724._02[g][j], 1);
                        }
                    } else {
                        fn_800506E8(lbl_8034E9A0._46F8[g], lbl_803C6724._02[g][j], 1);
                    }
                    fn_80067B40(g, lbl_803C6724._02[g][j], 1);
                }
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (g_d_GameSettings._10 == 0 && i != 0) {
            lbl_803C6028._74[lbl_8034E9A0._46F8[i]] = 1;
        } else {
            lbl_803C6028._74[lbl_8034E9A0._46F8[i]] = 0;
        }
        if (i != 0) {
            lbl_2_bss_F410._20[i] = 9;
        } else {
            lbl_2_bss_F410._20[i] = 0;
        }
        if (lbl_8034E9A0._4757[lbl_2_bss_F410._20[i]] != 0) {
            for (k = 0; k < 32; k++) {
                if (lbl_8034E9A0._4757[lbl_800FDE84[k]] == 0 && lbl_800FDE84[k] != 0xFF) {
                    lbl_2_bss_F410._20[i] = lbl_800FDE84[k];
                    break;
                }
            }
        }
        switch (lbl_8034E9A0._46F8[i]) {
        case 0:
            fn_80050138(1, lbl_2_bss_F410._20[i], -1, -1, -1, 0);
            break;
        case 1:
            fn_80050138(1, -1, lbl_2_bss_F410._20[i], -1, -1, 0);
            break;
        case 2:
            fn_80050138(1, -1, -1, lbl_2_bss_F410._20[i], -1, 0);
            break;
        case 3:
            fn_80050138(1, -1, -1, -1, lbl_2_bss_F410._20[i], 0);
            break;
        }
    }
    if (lbl_803CBBCC->_6 == 9) {
        fn_800625A4(0, 10);
        fn_800625A4(1, 10);
    } else if (lbl_803CBBCC->_6 != 11 && g_d_GameSettings.GameModeSelected == 5) {
        fn_800625A4(0, 10);
        fn_800625A4(1, 10);
    } else {
        fn_800625A4(0, 9);
        fn_800625A4(1, 9);
    }
    lbl_803C66B0._00 = 2;
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

// .text:0x00007504 size:0x840
void fn_2_7504(void) {
    s32 free = 0;
    s32 i;
    s32 id;
    s32 t;
    s32 j;
    u8 keep = 0;
    u8 unique;
    s32 cap;

    lbl_803CBD24._2 = 0;
    lbl_803CBD24._3 = 0xFF;
    lbl_2_bss_F468._61[1] = -1;
    lbl_2_bss_F468._61[0] = -1;
    lbl_2_bss_F468._65[1] = 0;
    lbl_2_bss_F468._65[0] = 0;
    if (lbl_803CBBCC->_6 != 9) {
        if (g_d_GameSettings._10 == 0 && g_d_GameSettings.GameModeSelected != 5) {
            lbl_2_bss_100B8._2E[0] = 1;
            lbl_2_bss_100B8._2E[1] = 1;
        } else {
            lbl_2_bss_100B8._2E[1] = 0;
            lbl_2_bss_100B8._2E[0] = 0;
        }
        if (g_d_GameSettings.GameModeSelected == 5) {
            for (t = 0; t < 2; t++) {
                if (t == 0) {
                    cap = starMissionCompletionTracker._441D;
                    unique = 1;
                    for (i = 1; i < 9; i++) {
                        if (starMissionCompletionTracker._40B8[0]._3 == starMissionCompletionTracker._40B8[i]._3) {
                            unique = 0;
                        }
                    }
                    keep = unique;
                } else {
                    cap = starMissionCompletionTracker._441F;
                }
                for (j = 0; j < 9; j++) {
                    id = lbl_803C6724._02[t][j];
                    if (t == 0 && lbl_803297E0._CFA1 == 0) {
                        lbl_803C6724._14[t][j] = starMissionCompletionTracker._40B8[j]._3;
                    } else if (t == 0 && keep) {
                        lbl_803C6724._14[t][j] = starMissionCompletionTracker._40B8[j]._3;
                    } else {
                        lbl_803C6724._14[t][j] = j;
                    }
                    lbl_803C6724._26[t][j] = lbl_8034E9A0._0000[id / 9][id % 9]._3B[cap];
                }
            }
            for (i = 0; i < 54; i++) {
                lbl_2_bss_3A8[i] = lbl_8034E9A0._0000[i / 9][i % 9]._27 + lbl_8034E9A0._0000[i / 9][i % 9]._26 * 2;
            }
            if (lbl_803CBBCC->_6 != 11 && lbl_803297E0._CFA1 == 0) {
                for (i = 0; i < 9; i++) {
                    lbl_2_bss_3A8[starMissionCompletionTracker._40B8[i]._0] = starMissionCompletionTracker._40B8[i]._4;
                }
            }
        }
    } else {
        for (t = 0; t < 2; t++) {
            for (i = 0; i < 9; i++) {
                lbl_803C6724._14[t][i] = i;
                lbl_803C6724._4A[t][i] = 0;
                lbl_803C6724._26[t][i] = 0;
                if (i != 0) {
                    lbl_803C6724._02[t][i] = -1;
                }
            }
        }
    }
    if (g_d_GameSettings.GameModeSelected == 5) {
        for (t = 0; t < 2; t++) {
            fn_800678CC(t);
        }
    }
    lbl_8034E9A0._4702 = 1;
    if (g_d_GameSettings.GameModeSelected == 5) {
        for (i = 0; i < 54; i++) {
            if (lbl_8034E9A0._4757[i] == 0) {
                free++;
            }
        }
        if (free == 0) {
            lbl_2_bss_F468._3F[0] = 1;
            lbl_2_bss_F468._37[0] = 1;
            lbl_2_bss_F468._00[0] = 9;
        } else {
            lbl_2_bss_F468._3F[0] = 0;
        }
    }
}

// .text:0x00006D3C size:0x7C8
// 99%: registers only, in the written-out copy of fn_2_6884 (the target
// keeps i in r3); calling fn_2_6884 there scores 98.3%.
void fn_2_6D3C(void) {
    s32 i;
    s32 j;
    u8 id;
    s8 group;

    if (g_d_GameSettings.GameModeSelected == 5 && lbl_803C5EA4._11 == 0) {
        if (lbl_2_bss_F468._28[4] == 0) {
            if (lbl_2_bss_F468._2D == 0) {
                fn_800216F8(37, fn_8006285C);
                lbl_2_bss_F468._2D = 1;
                return;
            }
            if (lbl_2_bss_F468._2D == 1) {
                if (lbl_803CC1B8->_10 == 0) {
                    return;
                }
                lbl_803CC1B8->_10 = 0;
                initializeUnknown();
                fn_800B0A5C_insertQueue(fn_80062A94, 0x1000);
                lbl_2_bss_F468._2D = 0;
            }
        }
        lbl_2_bss_F468._28[4] = 1;
        if (lbl_2_bss_F468._28[0] == 0 && fn_800697B0() != 0) {
            return;
        }
        lbl_2_bss_F468._28[0] = 1;
        if (lbl_2_bss_F468._28[1] == 0 && fn_80035838(lbl_2_data_D14, 6) == 0) {
            return;
        }
        lbl_2_bss_F468._28[1] = 1;
        if (lbl_2_bss_F468._28[2] == 0 && fn_80035838(lbl_2_data_D24, 9) == 0) {
            return;
        }
        lbl_2_bss_F468._28[2] = 1;
        if (lbl_2_bss_F468._28[3] == 0 && fn_80035838(lbl_2_data_D44, 15) == 0) {
            return;
        }
        lbl_2_bss_F468._28[3] = 1;
    }
    if (g_d_GameSettings.GameModeSelected == 5 && starMissionCompletionTracker._4445 != 0) {
        starMissionCompletionTracker._4445 = 0;
        lbl_803297E0._CFA1 = 1;
        if (lbl_80361B20[228] != 0) {
            lbl_803297E0._CF70 = 0;
        } else {
            lbl_803297E0._CF70 = 1;
        }
        fn_2_BF90();
        unsure_FillRosterPositions(1);
    } else if (g_d_GameSettings.GameModeSelected == 5 && starMissionCompletionTracker._4445 == 0) {
        if (starMissionCompletionTracker._441D == 9 && starMissionCompletionTracker._44EF != 0) {
            fn_2_6784();
        } else {
            fn_2_6AF4();
        }
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
        lbl_803297E0._CFA1 = 0;
    }
    if (g_d_GameSettings.GameModeSelected == 5) {
        fn_8006496C();
    }
    fn_2_82E58();
    lbl_803CBBCC->_4 = 1;
}

// .text:0x00006AF4 size:0x248
void fn_2_6AF4(void) {
    s32 i;
    u8 grp;
    u8 id;

    for (i = 0; i < 12; i++) {
        if (starMissionCompletionTracker._441F == lbl_80108EC4[i]) {
            grp = i;
            break;
        }
    }
    for (i = 0; i < 9; i++) {
        id = lbl_8034E9A0._4380[grp][0][i];
        lbl_803C6724._02[1][i] = lbl_8034E9A0._0000[(u8)(id / 9)][(u8)(id % 9)].CharID;
        lbl_80354720[1][i]._0 = i;
        lbl_80354720[1][i]._2 = i;
        lbl_80354720[1][i]._1 = i;
        lbl_803C6724._4A[1][i] = 1;
    }
    lbl_8034E9A0._46E0[0] = starMissionCompletionTracker._441D;
    lbl_8034E9A0._46E0[1] = starMissionCompletionTracker._441F;
    for (i = 0; i < 9; i++) {
        if (starMissionCompletionTracker.characters[lbl_803C6724._02[1][i]]._31 == 1) {
            lbl_803C6724._02[1][i] = 54;
        }
    }
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
        lbl_803C5EA4._08[1] = 0;
        lbl_803C5EA4._08[0] = 0;
        lbl_2_bss_100B8._30[1] = 0;
        lbl_2_bss_100B8._30[0] = 0;
        if (g_d_GameSettings._10 == 0) {
            lbl_2_bss_F468._00[0] = 9;
            lbl_803C66B0._59[0] = 0;
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
        if (lbl_803C66B0._5D[0] != 0 && lbl_803C66B0._5D[1] != 0) {
            break;
        }
        if (lbl_2_bss_F468._34 == 0) {
            fn_800625A4(0, 0x1E);
            lbl_2_bss_F468._34 = 1;
        }
        lbl_2_bss_F468._33 = 1;
        break;
    case 1:
        if (lbl_803C66B0._5D[0] != 0 && lbl_803C66B0._5D[1] != 0) {
            break;
        }
        fn_2_87A8();
        break;
    case 2:
        if (lbl_803C66B0._5D[0] != 0 && lbl_803C66B0._5D[1] != 0) {
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

// .text:0x000061A0 size:0x2E4
void fn_2_61A0(void) {
    s32 i;
    s32 t;
    s32 j;

    if (fn_80062578() == 0) {
        return;
    }
    if (lbl_2_bss_F468._2E == 0) {
        if (fn_80050F78(0) == 0) {
            lbl_803C66B0._56 = 1;
            lbl_803C66B0._55 = 1;
            return;
        }
    } else {
        if (fn_80050F78(2) == 0) {
            lbl_803C66B0._56 = 1;
            lbl_803C66B0._55 = 1;
            return;
        }
    }
    if (lbl_2_bss_F468._36 > 0) {
        lbl_2_bss_F468._36--;
        return;
    }
    lbl_803C66B0._56 = 0;
    lbl_803C66B0._55 = 0;
    if (lbl_2_bss_F468._2E == 0) {
        if (lbl_803297E0._CF5F != 0) {
            fn_2_19F2C();
            lbl_8034E9A0._48AD = 1;
            lbl_803C66B0._00 = 0;
            memset(lbl_803C66B0._01, 0, sizeof(lbl_803C66B0._01));
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
        } else {
            for (i = 0; i < 5; i++) {
                lbl_2_bss_F468._28[i] = 0;
            }
            fn_2_8940();
            fn_2_AEE8();
            lbl_803C66B0._00 = 0;
            memset(lbl_803C66B0._01, 0, sizeof(lbl_803C66B0._01));
            lbl_8034E9A0._48B1 = 1;
            fn_2_11A0(11);
            for (i = 1; i < 9; i++) {
                fn_80021AC0(0, i);
                fn_80021AC0(1, i);
            }
        }
    } else {
        if (lbl_8034E978._24 != 0) {
            return;
        }
        lbl_2_bss_F468._41[1] = 0;
        lbl_2_bss_F468._41[0] = 0;
        lbl_2_bss_F468._37[1] = 0;
        lbl_2_bss_F468._37[0] = 0;
        for (t = 0; t < 2; t++) {
            for (j = 0; j < 9; j++) {
                lbl_803C6724._4A[t][j] = 0;
            }
        }
        fn_2_11A0(9);
        lbl_803CBBCC->_8 = 0;
    }
    fn_800AD038(lbl_8034E9A0._46E8);
    lbl_8034E9A0._4755 = 3;
    lbl_8034E9A0._472A = 0;
    lbl_8034E9A0._48AD = 1;
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

// .text:0x000057F0 size:0x790
void fn_2_57F0(u8 port, u16 held, u16 trg, u16 rep) {
    lbl_2_bss_F468._08[port] = lbl_2_bss_F468._00[port];
    if ((rep & 8) || (trg & 8)) {
        if (lbl_2_bss_F468._00[port] == 9) {
            lbl_2_bss_F468._00[port] = 2;
            fn_800625A4(port, 14);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_2_bss_F468._00[port] == 10) {
            if (lbl_2_bss_F468._37[port] != 0) {
                lbl_2_bss_F468._00[port] = 9;
                fn_800625A4(port, 24);
            } else {
                lbl_2_bss_F468._00[port] = 2;
                fn_800625A4(port, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            switch (lbl_2_bss_F468._00[port]) {
            case 0:
                lbl_2_bss_F468._00[port] = 5;
                break;
            case 1:
                lbl_2_bss_F468._00[port] = 0;
                break;
            case 2:
                lbl_2_bss_F468._00[port] = 8;
                break;
            case 3:
                lbl_2_bss_F468._00[port] = 7;
                break;
            case 4:
                lbl_2_bss_F468._00[port] = 6;
                break;
            case 5:
                lbl_2_bss_F468._00[port] = 7;
                break;
            case 6:
                lbl_2_bss_F468._00[port] = 4;
                break;
            case 8:
                if (g_d_GameSettings.GameModeSelected != 5) {
                    lbl_2_bss_F468._00[port] = 10;
                } else if (lbl_2_bss_F468._37[port] != 0) {
                    lbl_2_bss_F468._00[port] = 9;
                } else {
                    lbl_2_bss_F468._00[port] = 2;
                }
                break;
            case 7:
                lbl_2_bss_F468._00[port] = 1;
                break;
            }
            if (lbl_2_bss_F468._08[port] != lbl_2_bss_F468._00[port]) {
                fn_800625A4(port, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if ((rep & 4) || (trg & 4)) {
        if (lbl_2_bss_F468._00[port] == 9) {
            if (g_d_GameSettings.GameModeSelected != 5) {
                lbl_2_bss_F468._00[port] = 10;
                fn_800625A4(port, 24);
            } else {
                lbl_2_bss_F468._00[port] = 8;
                fn_800625A4(port, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_2_bss_F468._00[port] == 10) {
            lbl_2_bss_F468._00[port] = 8;
            fn_800625A4(port, 14);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            switch (lbl_2_bss_F468._00[port]) {
            case 0:
                lbl_2_bss_F468._00[port] = 1;
                break;
            case 2:
                if (g_d_GameSettings.GameModeSelected != 5) {
                    if (lbl_2_bss_F468._37[port] != 0) {
                        lbl_2_bss_F468._00[port] = 9;
                    } else {
                        lbl_2_bss_F468._00[port] = 10;
                    }
                } else if (lbl_2_bss_F468._37[port] != 0) {
                    lbl_2_bss_F468._00[port] = 9;
                } else {
                    lbl_2_bss_F468._00[port] = 8;
                }
                break;
            case 4:
                lbl_2_bss_F468._00[port] = 6;
                break;
            case 3:
                lbl_2_bss_F468._00[port] = 0;
                break;
            case 5:
                lbl_2_bss_F468._00[port] = 0;
                break;
            case 7:
                lbl_2_bss_F468._00[port] = 5;
                break;
            case 6:
                lbl_2_bss_F468._00[port] = 4;
                break;
            case 8:
                lbl_2_bss_F468._00[port] = 2;
                break;
            case 1:
                lbl_2_bss_F468._00[port] = 7;
                break;
            }
            if (lbl_2_bss_F468._08[port] != lbl_2_bss_F468._00[port]) {
                fn_800625A4(port, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if ((rep & 1) || (trg & 1)) {
        if (lbl_2_bss_F468._00[port] == 9) {
            lbl_2_bss_F468._00[port] = 0;
            fn_800625A4(port, 14);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_2_bss_F468._00[port] == 10) {
            lbl_2_bss_F468._00[port] = 1;
            fn_800625A4(port, 14);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            switch (lbl_2_bss_F468._00[port]) {
            case 0:
                lbl_2_bss_F468._00[port] = 4;
                break;
            case 1:
                if (g_d_GameSettings.GameModeSelected != 5) {
                    lbl_2_bss_F468._00[port] = 10;
                } else if (lbl_2_bss_F468._37[port] == 0) {
                    return;
                } else {
                    lbl_2_bss_F468._00[port] = 9;
                }
                break;
            case 2:
                lbl_2_bss_F468._00[port] = 3;
                break;
            case 3:
                lbl_2_bss_F468._00[port] = 5;
                break;
            case 7:
                lbl_2_bss_F468._00[port] = 6;
                break;
            case 8:
                lbl_2_bss_F468._00[port] = 7;
                break;
            case 4:
                lbl_2_bss_F468._00[port] = 2;
                break;
            case 10:
                lbl_2_bss_F468._00[port] = 1;
                break;
            case 5:
                lbl_2_bss_F468._00[port] = 4;
                break;
            case 6:
                lbl_2_bss_F468._00[port] = 8;
                break;
            }
            if (lbl_2_bss_F468._08[port] != lbl_2_bss_F468._00[port]) {
                fn_800625A4(port, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if ((rep & 2) || (trg & 2)) {
        if (lbl_2_bss_F468._00[port] == 9) {
            lbl_2_bss_F468._00[port] = 0;
            fn_800625A4(port, 14);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_2_bss_F468._00[port] == 10) {
            if (lbl_2_bss_F468._37[port] != 0) {
                lbl_2_bss_F468._00[port] = 9;
                fn_800625A4(port, 24);
            } else {
                lbl_2_bss_F468._00[port] = 1;
                fn_800625A4(port, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            switch (lbl_2_bss_F468._00[port]) {
            case 0:
                if (lbl_2_bss_F468._37[port] != 0) {
                    lbl_2_bss_F468._00[port] = 9;
                    fn_800625A4(port, 24);
                } else {
                    lbl_2_bss_F468._00[port] = 2;
                    fn_800625A4(port, 14);
                }
                break;
            case 1:
                if (g_d_GameSettings.GameModeSelected != 5) {
                    lbl_2_bss_F468._00[port] = 10;
                } else if (lbl_2_bss_F468._37[port] == 0) {
                    return;
                } else {
                    lbl_2_bss_F468._00[port] = 9;
                }
                break;
            case 4:
                lbl_2_bss_F468._00[port] = 5;
                break;
            case 5:
                lbl_2_bss_F468._00[port] = 3;
                break;
            case 6:
                lbl_2_bss_F468._00[port] = 7;
                break;
            case 7:
                lbl_2_bss_F468._00[port] = 8;
                break;
            case 2:
                lbl_2_bss_F468._00[port] = 4;
                break;
            case 8:
                lbl_2_bss_F468._00[port] = 6;
                break;
            case 3:
                lbl_2_bss_F468._00[port] = 2;
                break;
            }
            if (lbl_2_bss_F468._08[port] != lbl_2_bss_F468._00[port]) {
                fn_800625A4(port, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    }
}

// .text:0x000057E8 size:0x8
s32 fn_2_57E8(s32 arg0, s32 arg1) {
    return (s8)arg1;
}

// .text:0x00005444 size:0x3A4
void fn_2_5444(u8 port) {
    s32 i;

    lbl_2_bss_F468._3D[port] = 0;
    if (g_d_GameSettings.GameModeSelected == 5) {
        for (i = 0; i < 9; i++) {
            starMissionCompletionTracker._40B8[i]._0 = inMemRoster[0][i].CharID = lbl_803C6724._02[0][i];
            starMissionCompletionTracker._40B8[i]._2 = i;
            starMissionCompletionTracker._40B8[i]._3 = lbl_80354720[0][i]._2 = lbl_803C6724._14[0][i];
        }
        fn_800625A4(0, 0x13);
        fn_800625A4(1, 0x13);
        lbl_2_bss_F468._2E = 0;
        lbl_2_bss_100B4 = 1;
        lbl_803CBBCC->_4 = 8;
    } else if (g_d_GameSettings._10 == 0 && lbl_2_bss_100B8._2E[0] != 0) {
        fn_800625A4(1, 0x11);
        lbl_8034E9A0._472A = 0xFF;
        lbl_2_bss_F468._36 = 30;
        lbl_803CBBCC->_4 = 3;
    } else if (g_d_GameSettings._10 == 0) {
        fn_2_52CC();
        fn_800625A4(0, 0x11);
    } else if (g_d_GameSettings._10 == 1) {
        lbl_2_bss_100B8._2E[port] = 1;
        fn_800625A4(port, 0x11);
        if (lbl_2_bss_100B8._2E[0] != 0 && lbl_2_bss_100B8._2E[1] != 0) {
            lbl_2_bss_F468._4F = 1;
            lbl_2_bss_F468._36 = 30;
            lbl_803CBBCC->_4 = 7;
        }
    }
}

// .text:0x000052CC size:0x178
void fn_2_52CC(void) {
    s32 i;

    lbl_2_bss_100B8._2E[0] = 1;
    lbl_803C66B0._59[0] = 1;
    lbl_2_bss_F468._00[lbl_803C66B0._59[0]] = 10;
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

// .text:0x00004970 size:0x814
void fn_2_4970(u8 port, s32 id) {
    s32 i;
    s32 g;
    s32 j;
    s32 k;
    s32 slot;
    s32 cursor;
    s8 cur;
    u8 inUse = 0;
    s8 group = 0;

    cursor = lbl_2_bss_F468._00[port];
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._14[port][i] == cursor) {
            slot = i;
        }
    }
    cur = lbl_803C6724._02[port][slot];
    if (cur == id) {
        lbl_2_bss_F468._00[port]--;
        if (lbl_2_bss_F468._00[port] < 0) {
            lbl_2_bss_F468._00[port] = 8;
        }
    } else {
        if (lbl_2_bss_F468._37[port] == 0 && lbl_2_bss_F468._3D[port] == 0) {
            lbl_2_bss_F468._08[port] = cursor;
            lbl_2_bss_F468._00[port]--;
            if (lbl_2_bss_F468._00[port] < 0) {
                lbl_2_bss_F468._00[port] = 8;
            }
            if (cur != -1 && cur != 54) {
            fn_2_C698(slot, port);
            if (g_d_GameSettings.GameModeSelected != 5) {
                fn_800506E8(port, lbl_803C6724._02[port][slot], 0);
                fn_80067B40(port, lbl_803C6724._02[port][slot], 0);
                lbl_8034E9A0._4757[lbl_803C6724._02[port][slot]] = 0;
            } else if (fn_80067B40(port, lbl_803C6724._02[port][slot], 2)) {
                for (g = 0; g < 9; g++) {
                    for (j = 0; j < 5; j++) {
                        if (lbl_803C6724._02[port][slot] == lbl_80108EDC[g][j]) {
                            group = g;
                            goto found;
                        }
                    }
                }
            found:
                for (k = 0; k < 9; k++) {
                    for (j = 0; j < 5; j++) {
                        if (lbl_803C6724._02[port][k] == lbl_80108EDC[group][j] && lbl_80108EDC[group][j] != -1 &&
                            lbl_803C6724._02[port][k] != lbl_803C6724._02[port][slot]) {
                            inUse = 1;
                        }
                    }
                }
                if (!inUse) {
                    fn_800506E8(port, fn_80067AC8(lbl_803C6724._02[port][slot], 0), 0);
                    lbl_8034E9A0._4757[fn_80067AC8(lbl_803C6724._02[port][slot], 0)] = 0;
                }
            } else {
                fn_800506E8(port, lbl_803C6724._02[port][slot], 0);
                lbl_8034E9A0._4757[lbl_803C6724._02[port][slot]] = 0;
            }
                lbl_803C6724._26[port][slot] = 0;
                lbl_803C6724._02[port][slot] = -1;
                lbl_803C6724._4A[port][slot] = 0;
            }
        } else {
        fn_2_C698(slot, port);
        if (g_d_GameSettings.GameModeSelected != 5) {
            fn_800506E8(port, lbl_803C6724._02[port][slot], 0);
            fn_80067B40(port, lbl_803C6724._02[port][slot], 0);
            lbl_8034E9A0._4757[lbl_803C6724._02[port][slot]] = 0;
        } else if (fn_80067B40(port, lbl_803C6724._02[port][slot], 2)) {
            for (g = 0; g < 9; g++) {
                for (j = 0; j < 5; j++) {
                    if (lbl_803C6724._02[port][slot] == lbl_80108EDC[g][j]) {
                        group = g;
                        goto found2;
                    }
                }
            }
        found2:
            for (k = 0; k < 9; k++) {
                for (j = 0; j < 5; j++) {
                    if (lbl_803C6724._02[port][k] == lbl_80108EDC[group][j] && lbl_80108EDC[group][j] != -1 &&
                        lbl_803C6724._02[port][k] != lbl_803C6724._02[port][slot]) {
                        inUse = 1;
                    }
                }
            }
            if (!inUse) {
                fn_800506E8(port, fn_80067AC8(lbl_803C6724._02[port][slot], 0), 0);
                lbl_8034E9A0._4757[fn_80067AC8(lbl_803C6724._02[port][slot], 0)] = 0;
            }
        } else {
            fn_800506E8(port, lbl_803C6724._02[port][slot], 0);
            lbl_8034E9A0._4757[lbl_803C6724._02[port][slot]] = 0;
        }
            lbl_803C6724._26[port][slot] = 0;
            lbl_2_bss_F468._3D[port] = 0;
            lbl_803C6724._02[port][slot] = -1;
            lbl_803C6724._4A[port][slot] = 0;
        }
        lbl_2_bss_F468._37[port] = 0;
    }
    fn_800625A4(port, 16);
}

// .text:0x00003624 size:0x134C
void fn_2_3624(u8 port) {
    u16 pad[3];
    s32 team = lbl_803C66B0._59[port];
    s32 curSlot;
    s32 cur;
    s32 prevSlot;
    s32 prev;
    s8 id;
    s32 i;
    s32 j;
    s8 slot;
    s8 cursor;

    memset(pad, 0, sizeof(pad));
    if (lbl_803C66B0._5D[team] != 0) {
        return;
    }
    pad[0] = lbl_8034E9A0._472C[port][0];
    pad[1] = lbl_8034E9A0._472C[port][1];
    pad[2] = lbl_8034E9A0._472C[port][2];
    if (pad[2] & 8) {
        if (lbl_2_bss_F468._45[team] != 0) {
            return;
        }
        if (lbl_2_bss_F468._00[team] == 9) {
            lbl_2_bss_F468._00[team] = 2;
            fn_800625A4(team, 14);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_2_bss_F468._00[team] == 10) {
            if (lbl_2_bss_F468._37[team] != 0) {
                lbl_2_bss_F468._00[team] = 9;
                fn_800625A4(team, 24);
            } else {
                lbl_2_bss_F468._00[team] = 2;
                fn_800625A4(team, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            lbl_2_bss_F468._08[team] = lbl_2_bss_F468._00[team];
            switch (lbl_2_bss_F468._00[team]) {
            case 0:
                lbl_2_bss_F468._00[team] = 5;
                break;
            case 1:
                lbl_2_bss_F468._00[team] = 0;
                break;
            case 2:
                lbl_2_bss_F468._00[team] = 8;
                break;
            case 3:
                lbl_2_bss_F468._00[team] = 7;
                break;
            case 4:
                lbl_2_bss_F468._00[team] = 6;
                break;
            case 5:
                lbl_2_bss_F468._00[team] = 7;
                break;
            case 6:
                lbl_2_bss_F468._00[team] = 4;
                break;
            case 8:
                if (lbl_2_bss_F468._37[team] != 0 && lbl_2_bss_F468._5F[team] == 0) {
                    lbl_2_bss_F468._00[team] = 9;
                } else {
                    lbl_2_bss_F468._00[team] = 2;
                }
                break;
            case 7:
                lbl_2_bss_F468._00[team] = 1;
                break;
            }
            if (lbl_2_bss_F468._08[team] != lbl_2_bss_F468._00[team]) {
                fn_800625A4(team, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad[2] & 4) {
        if (lbl_2_bss_F468._45[team] != 0) {
            return;
        }
        if (lbl_2_bss_F468._00[team] == 9) {
            lbl_2_bss_F468._00[team] = 8;
            fn_800625A4(team, 14);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            lbl_2_bss_F468._08[team] = lbl_2_bss_F468._00[team];
            switch (lbl_2_bss_F468._00[team]) {
            case 0:
                lbl_2_bss_F468._00[team] = 1;
                break;
            case 2:
                if (lbl_2_bss_F468._37[team] != 0 && lbl_2_bss_F468._5F[team] == 0) {
                    lbl_2_bss_F468._00[team] = 9;
                } else {
                    lbl_2_bss_F468._00[team] = 8;
                }
                break;
            case 4:
                lbl_2_bss_F468._00[team] = 6;
                break;
            case 3:
                lbl_2_bss_F468._00[team] = 0;
                break;
            case 5:
                lbl_2_bss_F468._00[team] = 0;
                break;
            case 7:
                lbl_2_bss_F468._00[team] = 5;
                break;
            case 6:
                lbl_2_bss_F468._00[team] = 4;
                break;
            case 8:
                lbl_2_bss_F468._00[team] = 2;
                break;
            case 1:
                lbl_2_bss_F468._00[team] = 7;
                break;
            }
            if (lbl_2_bss_F468._08[team] != lbl_2_bss_F468._00[team]) {
                fn_800625A4(team, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad[2] & 1) {
        if (lbl_2_bss_F468._45[team] != 0) {
            if (lbl_2_bss_F468._47[team] == 1) {
                lbl_2_bss_F468._47[team] = 0;
                lbl_2_bss_F468._49[team] = 0;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        } else if (lbl_2_bss_F468._00[team] == 9) {
            lbl_2_bss_F468._00[team] = 0;
            fn_800625A4(team, 14);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            lbl_2_bss_F468._08[team] = lbl_2_bss_F468._00[team];
            switch (lbl_2_bss_F468._00[team]) {
            case 0:
                lbl_2_bss_F468._00[team] = 4;
                break;
            case 1:
                if (lbl_2_bss_F468._37[team] == 0) {
                    return;
                } else if (lbl_2_bss_F468._5F[team] != 0) {
                    return;
                } else {
                    lbl_2_bss_F468._00[team] = 9;
                }
                break;
            case 2:
                lbl_2_bss_F468._00[team] = 3;
                break;
            case 3:
                lbl_2_bss_F468._00[team] = 5;
                break;
            case 7:
                lbl_2_bss_F468._00[team] = 6;
                break;
            case 8:
                lbl_2_bss_F468._00[team] = 7;
                break;
            case 4:
                lbl_2_bss_F468._00[team] = 2;
                break;
            case 10:
                lbl_2_bss_F468._00[team] = 1;
                break;
            case 5:
                lbl_2_bss_F468._00[team] = 4;
                break;
            case 6:
                lbl_2_bss_F468._00[team] = 8;
                break;
            }
            if (lbl_2_bss_F468._08[team] != lbl_2_bss_F468._00[team]) {
                fn_800625A4(team, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad[2] & 2) {
        if (lbl_2_bss_F468._45[team] != 0) {
            if (lbl_2_bss_F468._47[team] == 0) {
                lbl_2_bss_F468._47[team] = 1;
                lbl_2_bss_F468._49[team] = 0;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        } else if (lbl_2_bss_F468._00[team] == 9) {
            lbl_2_bss_F468._00[team] = 0;
            fn_800625A4(team, 14);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            lbl_2_bss_F468._08[team] = lbl_2_bss_F468._00[team];
            switch (lbl_2_bss_F468._00[team]) {
            case 0:
                if (lbl_2_bss_F468._37[team] != 0 && lbl_2_bss_F468._5F[team] == 0) {
                    lbl_2_bss_F468._00[team] = 9;
                    fn_800625A4(team, 24);
                } else {
                    lbl_2_bss_F468._00[team] = 2;
                    fn_800625A4(team, 14);
                }
                break;
            case 1:
                if (lbl_2_bss_F468._37[team] == 0) {
                    return;
                } else if (lbl_2_bss_F468._5F[team] != 0) {
                    return;
                } else {
                    lbl_2_bss_F468._00[team] = 9;
                }
                break;
            case 4:
                lbl_2_bss_F468._00[team] = 5;
                break;
            case 5:
                lbl_2_bss_F468._00[team] = 3;
                break;
            case 6:
                lbl_2_bss_F468._00[team] = 7;
                break;
            case 7:
                lbl_2_bss_F468._00[team] = 8;
                break;
            case 2:
                lbl_2_bss_F468._00[team] = 4;
                break;
            case 8:
                lbl_2_bss_F468._00[team] = 6;
                break;
            case 3:
                lbl_2_bss_F468._00[team] = 2;
                break;
            }
            if (lbl_2_bss_F468._08[team] != lbl_2_bss_F468._00[team]) {
                fn_800625A4(team, 14);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad[1] & 0x100) {
        if (fn_2_35D0(team)) {
            return;
        }
        if (lbl_2_bss_F468._00[team] == 9) {
            lbl_2_bss_F468._59[team] = 0;
            lbl_2_bss_F468._61[team] = -1;
            lbl_2_bss_F468._65[team] = 1;
            if (g_d_GameSettings.GameModeSelected == 5) {
                for (i = 0; i < 9; i++) {
                    starMissionCompletionTracker._40B8[i]._0 = inMemRoster[0][i].CharID = lbl_803C6724._02[0][i];
                    starMissionCompletionTracker._40B8[i]._2 = i;
                    starMissionCompletionTracker._40B8[i]._3 = lbl_80354720[0][i]._2 = lbl_803C6724._14[0][i];
                }
                lbl_2_bss_F468._2E = 0;
                lbl_2_bss_100B4 = 1;
                lbl_803CBBCC->_4 = 8;
            } else if (g_d_GameSettings._10 == 0) {
                if (team != 0) {
                    lbl_2_bss_F468._36 = 30;
                    lbl_803CBBCC->_4 = 3;
                } else {
                    fn_2_52CC();
                }
            } else {
                lbl_2_bss_100B8._2E[team] = 1;
                if (lbl_2_bss_100B8._2E[0] != 0 && lbl_2_bss_100B8._2E[1] != 0) {
                    lbl_2_bss_F468._4F = 1;
                    lbl_2_bss_F468._36 = 30;
                    lbl_803CBBCC->_4 = 7;
                }
            }
            fn_800625A4(team, 27);
        } else if (lbl_2_bss_F468._5F[team] == 0) {
            lbl_2_bss_F468._61[team] = lbl_2_bss_F468._00[team];
            fn_800625A4(team, 28);
        } else {
            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._14[team][i] == lbl_2_bss_F468._61[team]) {
                    prevSlot = i;
                    prev = lbl_2_bss_F468._61[team];
                }
                if (lbl_803C6724._14[team][i] == lbl_2_bss_F468._00[team]) {
                    curSlot = i;
                    cur = lbl_2_bss_F468._00[team];
                }
            }
            lbl_803C6724._14[team][prevSlot] = cur;
            lbl_803C6724._14[team][curSlot] = prev;
            fn_800625A4(team, 28);
        }
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    } else if (pad[1] & 0x200) {
        if (fn_2_35D0(team)) {
            return;
        }
        if (lbl_2_bss_F468._5F[team] != 0) {
            fn_800625A4(team, 29);
        }
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
    } else if (pad[1] & 0x20) {
        if (fn_2_35D0(team)) {
            return;
        }
        if (lbl_2_bss_F468._5F[team] != 0) {
            lbl_2_bss_F468._5F[team] = 0;
        }
        fn_800625A4(team, 27);
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        lbl_2_bss_F468._59[team] = 0;
    } else if (pad[1] & 0x40) {
        if (fn_2_35D0(team)) {
            return;
        }
        if (g_d_GameSettings.GameModeSelected == 5) {
            return;
        }
        cursor = lbl_2_bss_F468._00[team];
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[team][i] == cursor) {
                slot = i;
                break;
            }
        }
        id = lbl_803C6724._02[team][slot];
        if (id == -1 || id == 54) {
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            return;
        }
        if (lbl_2_bss_F468._00[team] != 9) {
            lbl_2_bss_F468._50[team] = 0;
            for (i = 0; i < 9; i++) {
                for (j = 0; j < 5; j++) {
                    if (id == lbl_80108EDC[i][j]) {
                        lbl_2_bss_F468._50[team] = 1;
                        goto found;
                    }
                }
            }
        found:
            if (lbl_2_bss_F468._50[team] == 0) {
                return;
            }
            fn_2_A040(i, j, team, slot);
            fn_2_C698(slot, team);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
        }
    } else if (pad[1] & 0x10) {
        if (fn_2_35D0(team)) {
            return;
        }
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[team][i] == lbl_2_bss_F468._00[team]) {
                slot = i;
                break;
            }
        }
        if (lbl_2_bss_F468._00[team] != 9 && lbl_803C6724._02[team][slot] != -1 &&
            lbl_803C6724._02[team][slot] != 54 && lbl_2_bss_F468._41[team] == 0) {
            lbl_2_bss_F468._45[team] = 1;
            lbl_2_bss_F468._4B[team] = 1;
            lbl_2_bss_F468._47[team] = 0;
            sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
        }
    }
}

// .text:0x000035D0 size:0x54
u8 fn_2_35D0(u8 port) {
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
        result = fn_8004CA6C(lbl_8034E9A0._472C[lbl_803CBD24._4][1]);
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
