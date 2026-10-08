#include "game/rep_1A80.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "game/rep_D18.h"
#include "game/rep_13B8.h"
#include "game/rep_1E08.h"
#include "game/rep_AC8.h"
#include "game/rep_1188.h"
#include "game/rep_1200.h"
#include "game/rep_3090.h"
#include "game/game_batter.h"
#include "game/rep_CC8.h"
#include "game/rep_720.h"

typedef struct AramEntry1A80 {
    /* 0x0 */ u32 _0[4];
} AramEntry1A80; // size: 0x10

extern struct {
    /* 0x000 */ s32 _000;
    /* 0x004 */ u16 _004;
    /* 0x006 */ u16 _006;
    /* 0x008 */ u16 _008;
    /* 0x00A */ u8 _00A[0xC - 0xA];
    /* 0x00C */ s16 _00C;
    /* 0x00E */ s16 _00E;
    /* 0x010 */ s16 _010;
    /* 0x012 */ s16 _012;
    /* 0x014 */ u8 _014[0x1D0 - 0x14];
    /* 0x1D0 */ u8 _1D0;
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4;
    /* 0x1D5 */ u8 _1D5;
    /* 0x1D6 */ u8 _1D6;
    /* 0x1D7 */ u8 _1D7;
    /* 0x1D8 */ u8 _1D8;
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ s8 _1DA;
    /* 0x1DB */ u8 _1DB;
    /* 0x1DC */ u8 _1DC;
    /* 0x1DD */ u8 _1DD[0x201 - 0x1DD];
    /* 0x201 */ u8 _201;
    /* 0x202 */ u8 _202[2];
    /* 0x204 */ u8 _204[2];
    /* 0x206 */ s8 _206;
    /* 0x207 */ u8 _207;
    /* 0x208 */ u8 _208;
    /* 0x209 */ u8 _209[0x220 - 0x209];
    /* 0x220 */ u8 _220;
    /* 0x221 */ u8 _221;
    /* 0x222 */ u8 _222;
    /* 0x223 */ u8 _223[0x23F - 0x223];
    /* 0x23F */ u8 _23F[2];
    /* 0x241 */ u8 _241;
    /* 0x242 */ s16 _242[9];
    /* 0x254 */ s16 _254;
    /* 0x256 */ s16 _256;
    /* 0x258 */ s16 _258;
    /* 0x25A */ s16 _25A;
    /* 0x25C */ s16 _25C;
    /* 0x25E */ s16 _25E;
    /* 0x260 */ u8 _260;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x00 */ u8 _00[0x9C];
    /* 0x9C */ u8 _9C;
    /* 0x9D */ u8 _9D[0xB3 - 0x9D];
    /* 0xB3 */ u8 _B3;
    /* 0xB4 */ u8 _B4[0xC3 - 0xB4];
    /* 0xC3 */ u8 _C3;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x0000 */ u8 _0000[0x2D46];
    /* 0x2D46 */ u8 _2D46;
    /* 0x2D47 */ u8 _2D47[0x2D52 - 0x2D47];
    /* 0x2D52 */ u8 _2D52;
    /* 0x2D53 */ u8 _2D53[0x2D5E - 0x2D53];
    /* 0x2D5E */ u8 _2D5E;
    /* 0x2D5F */ u8 _2D5F[0x307E - 0x2D5F];
    /* 0x307E */ u8 _307E;
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern u8 lbl_3_data_6104[8];

extern void changeScene(u8, s16);
extern void fn_800203E0(int, s8);
extern void fn_8004CC18(void);
extern void fn_80035B50(int arg);
extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_803CBC3C[];
extern s8 lbl_80354720[2][9][4];
extern int fn_80035838(AramEntry1A80* entry, int count);
extern int fn_8001C588(s16);

u8 lbl_3_data_F510[0x28] = {
    0x02, 0x05, 0x04, 0x03, 0x08, 0x03, 0x04, 0x05, 0x02, 0x06, 0x00, 0x01, 0x08, 0x06, 0x07, 0x01,
    0x02, 0x00, 0x07, 0x04, 0x04, 0x03, 0x01, 0x02, 0x05, 0x01, 0x02, 0x04, 0x06, 0x08, 0x07, 0x06,
    0x08, 0x05, 0x03, 0x03, 0x05, 0x07, 0x04, 0x06,
};

AramEntry1A80 lbl_3_data_F538[62] = {
    { { 0x0000040B, 0x4013764C, 0x1A635000, 0x0007DB48 } },
    { { 0x0000040B, 0x4003E3DC, 0x1A6B3000, 0x00021420 } },
    { { 0x0000040B, 0x4002EC10, 0x1A6D4800, 0x00013108 } },
    { { 0x0000040B, 0x400E72C0, 0x1A6E8000, 0x00060768 } },
    { { 0x0000040B, 0x40049404, 0x1A748800, 0x00020E34 } },
    { { 0x0000040B, 0x40076AE0, 0x18ED7000, 0x00036BC8 } },
    { { 0x0000040B, 0x4010FD70, 0x1A769800, 0x0005E284 } },
    { { 0x0000040B, 0x400DB738, 0x1A7C8000, 0x00049AB4 } },
    { { 0x0000040B, 0x400E9864, 0x1A812000, 0x00059DC0 } },
    { { 0x0000040B, 0x400B7718, 0x1A86C000, 0x00050288 } },
    { { 0x0000040B, 0x400D87FC, 0x1A8BC800, 0x00047BC4 } },
    { { 0x0000040B, 0x400D643C, 0x1A904800, 0x0004E3AC } },
    { { 0x0000040B, 0x400D5C7C, 0x1A953000, 0x00048D9C } },
    { { 0x0000040B, 0x400B767C, 0x1A99C000, 0x00047518 } },
    { { 0x0000040B, 0x400441F8, 0x1A9E3800, 0x0001AA84 } },
    { { 0x0000040B, 0x40106568, 0x1A9FE800, 0x00068C10 } },
    { { 0x0000040B, 0x4010E5A0, 0x0E97A800, 0x0009BCAC } },
    { { 0x0000040B, 0x40016980, 0x0EA16800, 0x0000D6C4 } },
    { { 0x0000040B, 0x40016980, 0x0EA24000, 0x0000C944 } },
    { { 0x0000040B, 0x40016980, 0x0EA31000, 0x0000E700 } },
    { { 0x0000040B, 0x40016980, 0x0EA3F800, 0x0000D64C } },
    { { 0x0000040B, 0x40016980, 0x0EA4D000, 0x0000C900 } },
    { { 0x0000040B, 0x40016980, 0x0EA5A000, 0x0000CFFC } },
    { { 0x0000040B, 0x40016980, 0x0EA67000, 0x0000D720 } },
    { { 0x0000040B, 0x40016980, 0x0EA74800, 0x0000D6CC } },
    { { 0x0000040B, 0x40016980, 0x0EA82000, 0x0000D21C } },
    { { 0x0000040B, 0x40016980, 0x0EA8F800, 0x0000D0BC } },
    { { 0x0000040B, 0x40016980, 0x0EA9D000, 0x0000B544 } },
    { { 0x0000040B, 0x40016980, 0x0EAA8800, 0x0000C4F8 } },
    { { 0x0000040B, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 } },
    { { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 } },
    { { 0x0000040B, 0x4000A820, 0x18ED3800, 0x00003758 } },
    { { 0x0000040B, 0x4011EC24, 0x18F0E000, 0x000D8818 } },
    { { 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8 } },
    { { 0x0000040B, 0x4006C850, 0x06C96000, 0x0002C884 } },
    { { 0x0000040B, 0x4005B178, 0x06CC3000, 0x0003555C } },
    { { 0x0000040B, 0x401EB174, 0x18D43800, 0x000FB220 } },
    { { 0x0000040B, 0x4001ED60, 0x1AA67800, 0x0000CFF0 } },
    { { 0x0000040B, 0x4000BF30, 0x1AA74800, 0x000026E0 } },
    { { 0x0000040B, 0x40003498, 0x1AA77000, 0x00000E28 } },
    { { 0x0000040B, 0x4000BDE0, 0x1AA78000, 0x000024F4 } },
    { { 0x0000040B, 0x40006088, 0x1AA7A800, 0x00001290 } },
    { { 0x0000040B, 0x400049F0, 0x1AA7C000, 0x000018F4 } },
    { { 0x0000040B, 0x40005ECC, 0x1AA7E000, 0x00001D38 } },
    { { 0x0000040B, 0x40002670, 0x1AA80000, 0x00000BE8 } },
    { { 0x00000000, 0x00028240, 0x1AA81000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AAA9800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AAD2000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AAFA800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AB23000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AB4B800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AB74000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AB9C800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1ABC5000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1ABED800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AC16000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AC3E800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AC67000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AC8F800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1ACB8000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1ACE0800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AD09000, 0x00028240 } },
};

// [mode][menu]: item count, then the items
u8 lbl_3_data_F918[2][2][8] = {
    {
        { 5, 0, 3, 4, 5, 6, 0, 0 },
        { 4, 0, 4, 5, 6, 0, 0, 0 },
    },
    {
        { 7, 0, 1, 2, 3, 4, 5, 6 },
        { 6, 0, 1, 2, 4, 5, 6, 0 },
    },
};

// .text:0x000AFDA4 size:0x1C mapped:0x806EEE38
void fn_3_AFDA4(void) {
    lbl_3_common_bss_34C90._1D5 = 0;
    lbl_3_common_bss_34C90._1D6 = 0;
    lbl_3_common_bss_34C90._1D7 = 0;
}

// .text:0x000AFD80 size:0x24 mapped:0x806EEE14
void fn_3_AFD80(u8 arg0) {
    lbl_3_common_bss_34C90._1D1 = arg0;
    lbl_3_common_bss_34C90._1D2 = 0;
    lbl_3_common_bss_34C90._00C = 0;
    lbl_3_common_bss_34C90._00E = 0;
    lbl_3_common_bss_34C90._010 = 0;
}

// .text:0x000AFD48 size:0x38 mapped:0x806EEDDC
s32 fn_3_AFD48(u16 buttons) {
    if (lbl_3_common_bss_34C90._206 <= 0) {
        lbl_3_common_bss_34C90._004 = buttons;
        lbl_3_common_bss_34C90._006 = buttons;
        lbl_3_common_bss_34C90._008 = buttons;
        lbl_3_common_bss_34C90._206 = 13;
        return 1;
    }
    return 0;
}

// .text:0x000AFB64 size:0x1E4 mapped:0x806EEBF8
void fn_3_AFB64(void) {
    if (lbl_8036E548._2D46 != 0) {
        return;
    }
    if (lbl_8036E548._2D52 != 0) {
        return;
    }
    if (lbl_8036E548._2D5E != 0) {
        return;
    }
    if (!g_d_GameSettings.exhibitionMatchInd && lbl_3_common_bss_32724._B3 != 0) {
        return;
    }
    if (g_Pitcher.pitchTotalTimeCounter > 0) {
        return;
    }
    if (lbl_3_common_bss_34C90._1D5 != 0) {
        return;
    }
    if (g_Pitcher.pitcherActionState == PITCHER_ACTION_STATE_WINDUP) {
        return;
    }
    lbl_3_common_bss_34C90._201 = 0;
    if (lbl_3_common_bss_34C90._202[g_GameLogic.teamFielding] != 0) {
        lbl_3_common_bss_34C90._1D8 = 0;
        lbl_3_common_bss_34C90._202[g_GameLogic.teamFielding] = 0;
        lbl_3_common_bss_34C90._204[g_GameLogic.teamFielding] = 0;
    } else if (lbl_3_common_bss_34C90._202[g_GameLogic.teamBatting] != 0) {
        lbl_3_common_bss_34C90._1D8 = 1;
        lbl_3_common_bss_34C90._202[g_GameLogic.teamBatting] = 0;
        lbl_3_common_bss_34C90._204[g_GameLogic.teamBatting] = 0;
    } else if (g_GameLogic._13E[g_GameLogic.teamFielding] == 0 &&
               (g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]].newButtonInput & INPUT_BUTTON_START))
    {
        lbl_3_common_bss_34C90._1D8 = 0;
    } else if (g_GameLogic._13E[g_GameLogic.teamBatting] == 0 &&
               (g_Controls[g_GameLogic.teams[g_GameLogic.teamBatting]].newButtonInput & INPUT_BUTTON_START))
    {
        lbl_3_common_bss_34C90._1D8 = 1;
    } else {
        return;
    }
    lbl_3_common_bss_34C90._1D5 = 1;
    fn_3_AFD80(0);
    fn_3_59918(14, 0);
    lbl_3_common_bss_34C58._2A = 1;
    lbl_3_common_bss_34C58._24 = 59;
}

// .text:0x000AFA64 size:0x100 mapped:0x806EEAF8
void fn_3_AFA64(void) {
    if (lbl_3_common_bss_34C90._00C < 0x7FFE) {
        lbl_3_common_bss_34C90._00C++;
    } else {
        lbl_3_common_bss_34C90._00C = 0x7FFF;
    }
    lbl_803CBC3C[0] = 1;
    if (lbl_3_common_bss_34C90._00C > 60) {
        if (lbl_3_common_bss_34C90._1D8 == 0) {
            if (!g_d_GameSettings.exhibitionMatchInd) {
                lbl_3_common_bss_34C90._1D0 = 2;
            } else {
                lbl_3_common_bss_34C90._1D0 = 0;
            }
        } else if (!g_d_GameSettings.exhibitionMatchInd) {
            lbl_3_common_bss_34C90._1D0 = 3;
        } else {
            lbl_3_common_bss_34C90._1D0 = 1;
        }
        fn_3_AFD80(1);
        fn_3_5A6D4(11);
        fn_3_BF1AC();
        fn_3_BF158();
    } else {
        fn_3_31594();
        fn_3_8A958();
    }
}

// .text:0x000AF5A4 size:0x4C0 mapped:0x806EE638
void fn_3_AF5A4(void) {
    return;
}

// .text:0x000AF428 size:0x17C mapped:0x806EE4BC
void fn_3_AF428(void) {
    if (lbl_3_common_bss_34C90._254 >= 0) {
        if (lbl_3_common_bss_34C90._25C == lbl_3_common_bss_34C90._254) {
            lbl_3_common_bss_34C90._254 = -1;
        } else if (lbl_3_common_bss_34C90._258 < 0) {
            lbl_3_common_bss_34C90._258 = lbl_3_common_bss_34C90._254;
            lbl_3_common_bss_32724._9C = 0;
            g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0] =
                lbl_80354720[lbl_3_common_bss_34C90._000][lbl_3_common_bss_34C90._254][0];
            fn_3_750DC();
        } else if (fn_3_750DC() != 0) {
            lbl_3_common_bss_34C90._25C = lbl_3_common_bss_34C90._258;
            lbl_3_common_bss_34C90._254 = -1;
            lbl_3_common_bss_34C90._258 = -1;
        }
    } else if (lbl_3_common_bss_34C90._256 >= 0) {
        if (lbl_3_common_bss_34C90._25E == lbl_3_common_bss_34C90._25A) {
            lbl_3_common_bss_34C90._256 = -1;
            lbl_3_common_bss_34C90._25A = -1;
        } else if (lbl_3_common_bss_34C90._25A < 0) {
            lbl_3_common_bss_34C90._25A = lbl_3_common_bss_34C90._256;
            lbl_803CBC3C[3] = 0;
        } else if (fn_8001C588(inMemRoster[lbl_3_common_bss_34C90._000]
                                          [lbl_80354720[lbl_3_common_bss_34C90._000][lbl_3_common_bss_34C90._256][0]]
                                              .stats.CharID) != 0)
        {
            lbl_3_common_bss_34C90._25E = lbl_3_common_bss_34C90._25A;
            lbl_3_common_bss_34C90._256 = -1;
            lbl_3_common_bss_34C90._25A = -1;
        }
    }
}

// .text:0x000AF10C size:0x31C mapped:0x806EE1A0
void fn_3_AF10C(void) {
    if (lbl_3_common_bss_34C90._00C <= 1) {
        if (lbl_3_common_bss_34C90._1D8 == 0) {
            lbl_3_common_bss_34C90._000 = g_GameLogic.teamFielding;
            if (g_GameLogic._131[g_GameLogic.teamFielding] < 0xFE) {
                g_GameLogic._131[g_GameLogic.teamFielding]++;
            } else {
                g_GameLogic._131[g_GameLogic.teamFielding] = 0xFF;
            }
            if (g_GameLogic._133[g_GameLogic.teamFielding] < 0xFE) {
                g_GameLogic._133[g_GameLogic.teamFielding]++;
            } else {
                g_GameLogic._133[g_GameLogic.teamFielding] = 0xFF;
            }
        } else {
            lbl_3_common_bss_34C90._000 = g_GameLogic.teamBatting;
            if (g_GameLogic._131[g_GameLogic.teamBatting] < 0xFE) {
                g_GameLogic._131[g_GameLogic.teamBatting]++;
            } else {
                g_GameLogic._131[g_GameLogic.teamBatting] = 0xFF;
            }
            if (g_GameLogic._133[g_GameLogic.teamBatting] < 0xFE) {
                g_GameLogic._133[g_GameLogic.teamBatting]++;
            } else {
                g_GameLogic._133[g_GameLogic.teamBatting] = 0xFF;
            }
        }
        fn_3_AEFF8();
        lbl_3_common_bss_34C90._1DA = 0;
        lbl_3_common_bss_34C90._206 = 13;
        lbl_3_common_bss_34C90._201 = 0;
        lbl_3_common_bss_34C90._207 = 0;
        lbl_3_common_bss_34C90._208 = 0;
        if (g_GameLogic._13E[lbl_3_common_bss_34C90._000] != 0) {
            lbl_3_common_bss_34C90._201 = 1;
        }
        lbl_3_common_bss_34C90._1DB = 0;
        lbl_3_common_bss_34C90._1DC = 0;
        if (g_GameLogic.playBatterWalkupAnimation != 0) {
            g_GameLogic.playBatterWalkupAnimation = 2;
        }
        fn_3_15F94();
    } else if (fn_80035838(&lbl_3_data_F538[2], 19) != 0) {
        if (lbl_3_common_bss_34C90._1D8 == 0) {
            fn_3_AFD80(2);
        } else {
            fn_3_AFD80(9);
        }
    }
}

// .text:0x000AEFF8 size:0x114 mapped:0x806EE08C
void fn_3_AEFF8(void) {
    int i;

    lbl_3_common_bss_34C90._254 = -1;
    lbl_3_common_bss_34C90._258 = -1;
    lbl_3_common_bss_34C90._256 = -1;
    lbl_3_common_bss_34C90._25A = -1;
    for (i = 0; i < 9; i++) {
        if (lbl_80354720[lbl_3_common_bss_34C90._000][i][2] == 0) {
            lbl_3_common_bss_34C90._25C = i;
        }
        if (lbl_80354720[lbl_3_common_bss_34C90._000][i][2] == 1) {
            lbl_3_common_bss_34C90._25E = i;
        }
    }
}

// .text:0x000AEC50 size:0x3A8 mapped:0x806EDCE4
void fn_3_AEC50(void) {
    int mode;

    mode = 0;
    if (!g_d_GameSettings.exhibitionMatchInd) {
        mode = 1;
    }
    switch (lbl_3_common_bss_34C90._1D2) {
    case 0:
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D2 = 1;
        if (lbl_3_common_bss_34C58._2A != 0) {
            lbl_3_common_bss_34C58._2A = 2;
            lbl_3_common_bss_34C58._24 = 120;
        }
        break;
    case 1:
        if (lbl_3_common_bss_34C90._012 > 20) {
            lbl_3_common_bss_34C90._1D2 = 2;
        }
        break;
    case 2:
        fn_3_AE900();
        lbl_3_common_bss_34C90._012 = 0;
        break;
    case 3:
        if (lbl_3_common_bss_34C90._012 == 1) {
            changeScene(3, 6);
            lbl_3_common_bss_34C58._2A = 1;
            lbl_3_common_bss_34C58._24 = 5;
        }
        if (lbl_8037169C._13 != 0) {
            lbl_3_common_bss_34C90._1D2 = 4;
        }
        break;
    case 4:
        switch (lbl_3_data_F918[mode][1][1 + lbl_3_common_bss_34C90._1DA]) {
        case 0:
            fn_3_AFD80(10);
            break;
        }
        lbl_3_common_bss_34C90._1D9 = 2;
        break;
    case 5:
        if (lbl_3_common_bss_34C90._012 > 20) {
            lbl_3_common_bss_34C90._1D2 = 6;
        }
        break;
    case 6:
        switch (lbl_3_data_F918[mode][1][1 + lbl_3_common_bss_34C90._1DA]) {
        case 3:
            fn_3_AFD80(11);
            break;
        case 5:
            lbl_3_common_bss_34C90._220 = 0;
            fn_3_AFD80(13);
            break;
        case 4:
            fn_3_AFD80(12);
            break;
        case 1:
            fn_3_AFD80(14);
            break;
        case 2:
            fn_3_AFD80(15);
            break;
        }
        break;
    case 7:
        switch (fn_3_5B380(lbl_3_common_bss_34C90._006)) {
        case 1:
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            lbl_3_common_bss_34C90._1D2 = 8;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 2;
            break;
        }
        break;
    case 8:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
            if (!g_d_GameSettings.exhibitionMatchInd) {
                if (g_d_GameSettings.bJMatchInd == 1) {
                    fn_800203E0(12, lbl_3_data_6104[starMissionCompletionTracker._441C]);
                } else {
                    fn_800203E0(12, lbl_3_data_6104[starMissionCompletionTracker._441E]);
                }
            } else {
                changeScene(4, 6);
            }
        }
        if (lbl_8037169C._13 != 0) {
            g_GameLogic.framesOfExitingToMenu = 1;
            lbl_3_common_bss_34C90._1D9 = 2;
            g_d_GameSettings._13 = 1;
            fn_80035B50(0x13);
            fn_8004CC18();
        }
        break;
    }
}

// .text:0x000AE900 size:0x350 mapped:0x806ED994
void fn_3_AE900(void) {
    int mode;
    int i;

    mode = 0;
    if (!g_d_GameSettings.exhibitionMatchInd) {
        mode = 1;
    }
    if (lbl_3_common_bss_34C90._006 & PAD_BUTTON_START) {
        for (i = 1; i < 7; i++) {
            if (lbl_3_data_F918[mode][1][i] == 0) {
                lbl_3_common_bss_34C90._1DA = i - 1;
                break;
            }
        }
        lbl_3_common_bss_34C90._1D2 = 3;
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    } else if (lbl_3_common_bss_34C90._006 & PAD_BUTTON_A) {
        switch (lbl_3_data_F918[mode][1][1 + lbl_3_common_bss_34C90._1DA]) {
        case 6:
            fn_3_5B408();
            lbl_3_common_bss_34C90._1D2 = 7;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            break;
        case 1:
            lbl_3_common_bss_34C90._1D9 = 1;
            lbl_3_common_bss_34C90._012 = 0;
            lbl_3_common_bss_34C90._1D2 = 5;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D9 = 1;
            lbl_3_common_bss_34C90._012 = 0;
            lbl_3_common_bss_34C90._1D2 = 5;
            break;
        case 3:
            lbl_3_common_bss_34C90._1D9 = 1;
            lbl_3_common_bss_34C90._012 = 0;
            lbl_3_common_bss_34C90._1D2 = 5;
            break;
        case 4:
            lbl_3_common_bss_34C90._1D9 = 1;
            lbl_3_common_bss_34C90._1D2 = 5;
            break;
        case 5:
            lbl_3_common_bss_34C90._1D9 = 1;
            lbl_3_common_bss_34C90._1D2 = 5;
            break;
        default:
            lbl_3_common_bss_34C90._1D2 = 3;
            break;
        }
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    } else if (lbl_3_common_bss_34C90._006 & PAD_BUTTON_B) {
        if (lbl_3_data_F918[mode][1][1 + lbl_3_common_bss_34C90._1DA] != 0) {
            for (i = 1; i < 7; i++) {
                if (lbl_3_data_F918[mode][1][i] == 0) {
                    lbl_3_common_bss_34C90._1DA = i - 1;
                    break;
                }
            }
        } else {
            lbl_3_common_bss_34C90._1D2 = 3;
        }
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
    } else if (lbl_3_common_bss_34C90._008 & PAD_BUTTON_UP) {
        if (lbl_3_common_bss_34C90._1DA == 0) {
            lbl_3_common_bss_34C90._1DA = lbl_3_data_F918[mode][1][0] - 1;
        } else {
            lbl_3_common_bss_34C90._1DA--;
        }
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    } else if (lbl_3_common_bss_34C90._008 & PAD_BUTTON_DOWN) {
        lbl_3_common_bss_34C90._1DA++;
        if (lbl_3_common_bss_34C90._1DA >= lbl_3_data_F918[mode][1][0]) {
            lbl_3_common_bss_34C90._1DA = 0;
        }
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
    }
}

// .text:0x000AE770 size:0x190 mapped:0x806ED804
void fn_3_AE770(void) {
    int i;

    if (lbl_3_common_bss_34C90._00C <= 1) {
        lbl_803CBC3C[2] = 0;
        fn_80035B50(0x13);
    }
    fn_3_753E8(TRUE);
    setBatterContactConstants();
    for (i = 0; i < 2; i++) {
        if (g_GameLogic._13E[i] == 0) {
            if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoRunning) {
                g_GameLogic.battingAIInd[g_GameLogic.homeTeamInd ^ i] = 1;
            } else {
                g_GameLogic.battingAIInd[g_GameLogic.homeTeamInd ^ i] = 0;
            }
            if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoFielding) {
                g_GameLogic.teamAIInd[g_GameLogic.homeTeamInd ^ i] = 1;
                g_GameLogic.autoFielding[g_GameLogic.homeTeamInd ^ i] = 1;
            } else {
                g_GameLogic.teamAIInd[g_GameLogic.homeTeamInd ^ i] = 0;
                g_GameLogic.autoFielding[g_GameLogic.homeTeamInd ^ i] = 0;
            }
        }
    }
    fn_3_FBD70();
    fn_3_FBD58();
    lbl_8036E548._307E = 1;
    g_GameLogic.pre_PostMiniGameInd = 1;
    changeScene(1, 6);
    fn_3_5A6D4(0);
}

// .text:0x000AE334 size:0x43C mapped:0x806ED3C8
void fn_3_AE334(void) {
    return;
}

// .text:0x000ADEDC size:0x458 mapped:0x806ECF70
void fn_3_ADEDC(void) {
    return;
}

// .text:0x000ADA3C size:0x4A0 mapped:0x806ECAD0
void fn_3_ADA3C(void) {
    return;
}

// .text:0x000AD8CC size:0x170 mapped:0x806EC960
void fn_3_AD8CC(void) {
    return;
}

// .text:0x000AD3BC size:0x510 mapped:0x806EC450
void fn_3_AD3BC(void) {
    return;
}

// .text:0x000AD2A0 size:0x11C mapped:0x806EC334
void fn_3_AD2A0(void) {
    int pitcher;
    int i;
    int j;

    pitcher = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0];
    for (i = 0; i < 9; i++) {
        for (j = 1; j < 10; j++) {
            if (i == g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][j][0]) {
                if (g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][j][1] !=
                    lbl_3_common_bss_34C90._242[i])
                {
                    lbl_3_common_bss_34C90._260 = 1;
                }
                g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][j][1] =
                    lbl_3_common_bss_34C90._242[i];
                if (lbl_3_common_bss_34C90._242[i] == 0) {
                    g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0] = i;
                    if (pitcher != g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]) {
                        g_GameLogic.playOverInd = 1;
                    }
                }
            }
        }
    }
    fn_3_596F8();
    fn_3_6EBB4(g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]);
}

// .text:0x000AD164 size:0x13C mapped:0x806EC1F8
void fn_3_AD164(int arg0) {
    switch (lbl_3_common_bss_34C90._1D2) {
    case 0:
        lbl_3_common_bss_34C90._23F[lbl_3_common_bss_34C90._000] = 0;
        if (g_GameLogic._13E[lbl_3_common_bss_34C90._000 ^ 1] == 0) {
            lbl_3_common_bss_34C90._23F[lbl_3_common_bss_34C90._000 ^ 1] = 1;
        } else {
            lbl_3_common_bss_34C90._23F[lbl_3_common_bss_34C90._000 ^ 1] = 0xFF;
        }
        lbl_3_common_bss_34C90._1D2 = 1;
        break;
    case 1:
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D2 = 2;
        break;
    case 2:
        if (lbl_3_common_bss_34C90._012 > 20) {
            lbl_3_common_bss_34C90._1D2 = 3;
        }
        break;
    case 3:
        fn_3_ACD38();
        break;
    case 4:
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D2 = 5;
        break;
    case 5:
        if (lbl_3_common_bss_34C90._012 > 20) {
            lbl_3_common_bss_34C90._1D2 = 6;
        }
        break;
    case 6:
        if (arg0 == 0) {
            fn_3_AFD80(2);
        } else {
            fn_3_AFD80(9);
        }
        break;
    }
}

// .text:0x000ACD38 size:0x42C mapped:0x806EBDCC
void fn_3_ACD38(void) {
    int i;
    InputStruct* input;

    for (i = 0; i < 2; i++) {
        input = &g_Controls[g_GameLogic.teams[i]];
        if (g_GameLogic._13E[i] != 0) {
            continue;
        }
        if (input->newButtonInput & PAD_BUTTON_A) {
            if (lbl_3_common_bss_34C90._23F[i] == 0) {
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                lbl_3_common_bss_34C90._1D2 = 4;
            }
        } else if (input->_08 & PAD_BUTTON_UP) {
            if (lbl_3_common_bss_34C90._23F[i] == 0) {
                lbl_3_common_bss_34C90._23F[i] = 4;
            } else if (lbl_3_common_bss_34C90._23F[i] == 1) {
                if (i == lbl_3_common_bss_34C90._000) {
                    lbl_3_common_bss_34C90._23F[i] = 0;
                } else {
                    lbl_3_common_bss_34C90._23F[i] = 4;
                }
            } else {
                lbl_3_common_bss_34C90._23F[i]--;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (input->_08 & PAD_BUTTON_DOWN) {
            if (lbl_3_common_bss_34C90._23F[i] == 4) {
                if (i == lbl_3_common_bss_34C90._000) {
                    lbl_3_common_bss_34C90._23F[i] = 0;
                } else {
                    lbl_3_common_bss_34C90._23F[i] = 1;
                }
            } else {
                lbl_3_common_bss_34C90._23F[i]++;
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (input->_08 & PAD_BUTTON_RIGHT) {
            if (lbl_3_common_bss_34C90._23F[i] == 0) {
                continue;
            }
            switch (lbl_3_common_bss_34C90._23F[i]) {
            case 1:
                if (!gameInitOptions.controlOptions[g_GameLogic.teams[i]].easyBatting) {
                    gameInitOptions.controlOptions[g_GameLogic.teams[i]].easyBatting = TRUE;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                break;
            case 2:
                if (!gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoFielding) {
                    gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoFielding = TRUE;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                break;
            case 3:
                if (!gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoRunning) {
                    gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoRunning = TRUE;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                break;
            case 4:
                if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].dropSpot == TRUE) {
                    gameInitOptions.controlOptions[g_GameLogic.teams[i]].dropSpot = FALSE;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                break;
            }
        } else if (input->_08 & PAD_BUTTON_LEFT) {
            if (lbl_3_common_bss_34C90._23F[i] == 0) {
                continue;
            }
            switch (lbl_3_common_bss_34C90._23F[i]) {
            case 1:
                if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].easyBatting) {
                    gameInitOptions.controlOptions[g_GameLogic.teams[i]].easyBatting = FALSE;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                break;
            case 2:
                if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoFielding) {
                    gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoFielding = FALSE;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                break;
            case 3:
                if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoRunning) {
                    gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoRunning = FALSE;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                break;
            case 4:
                if (!gameInitOptions.controlOptions[g_GameLogic.teams[i]].dropSpot) {
                    gameInitOptions.controlOptions[g_GameLogic.teams[i]].dropSpot = TRUE;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
                break;
            }
        }
    }
}

// .text:0x000ACAF8 size:0x240 mapped:0x806EBB8C
void fn_3_ACAF8(void) {
    switch (lbl_3_common_bss_34C90._1D2) {
    case 0:
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._221 = 1;
        lbl_3_common_bss_34C90._222 = 3;
        lbl_3_common_bss_34C90._1D2 = 2;
        break;
    case 1:
        break;
    case 2:
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D2 = 3;
        break;
    case 3:
        changeScene(1, 6);
        if (lbl_3_common_bss_34C90._012 > 20) {
            lbl_3_common_bss_34C90._1D2 = 4;
        }
        break;
    case 4:
        fn_3_AC9F8();
        lbl_3_common_bss_34C90._012 = 0;
        break;
    case 5:
        if (lbl_3_common_bss_34C90._012 > 20 && lbl_3_common_bss_32724._C3 == 0) {
            lbl_3_common_bss_34C90._1D2 = 6;
        }
        break;
    case 6:
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            lbl_3_common_bss_34C90._1D2 = 0;
            fn_3_5A6D4(11);
        } else if (lbl_3_common_bss_34C90._1D8 == 0) {
            fn_3_AFD80(2);
        } else {
            fn_3_AFD80(9);
        }
        break;
    }
}

// .text:0x000AC9F8 size:0x100 mapped:0x806EBA8C
void fn_3_AC9F8(void) {
    if (lbl_3_common_bss_32724._C3 == 0) {
        if (lbl_3_common_bss_34C90._006 & 0x200) {
            lbl_3_common_bss_34C90._1D2 = 5;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        } else if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
            if ((lbl_3_common_bss_34C90._008 & 1) && lbl_3_common_bss_34C90._221 != 0) {
                lbl_3_common_bss_34C90._221--;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            } else if ((lbl_3_common_bss_34C90._008 & 2) &&
                       lbl_3_common_bss_34C90._221 < lbl_3_common_bss_34C90._222 - 1)
            {
                lbl_3_common_bss_34C90._221++;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        }
    }
}
