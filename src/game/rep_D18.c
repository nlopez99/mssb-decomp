#include "game/rep_D18.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "string.h"
#include "game/m_sound.h"
#include "game/rep_10E8.h"
#include "game/rep_1038.h"
#include "game/rep_16B8.h"
#include "game/rep_1BC8.h"
#include "game/rep_1D58.h"
#include "game/rep_1E08.h"
#include "game/rep_28A8.h"
#include "game/rep_3090.h"
#include "game/rep_31A0.h"
#include "game/rep_540.h"
#include "game/rep_720.h"
#include "game/rep_DB8.h"
#include "game/rep_E08.h"

typedef struct AramEntryD18 {
    /* 0x0 */ u32 _0[4];
} AramEntryD18; // size: 0x10

extern struct {
    /* 0x00 */ u8 _00[0x1C];
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D[0x27 - 0x1D];
    /* 0x27 */ u8 _27;
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
    /* 0x2A */ u8 _2A;
} lbl_80366158;

extern struct {
    /* 0x0000 */ u8 _0000[0x6C];
    /* 0x006C */ s32 _006C;
    /* 0x0070 */ u8 _0070[0x2D44 - 0x70];
    /* 0x2D44 */ s16 _2D44;
    /* 0x2D46 */ u8 _2D46[0x2D50 - 0x2D46];
    /* 0x2D50 */ s16 _2D50;
    /* 0x2D52 */ u8 _2D52[0x2D5C - 0x2D52];
    /* 0x2D5C */ s16 _2D5C;
    /* 0x2D5E */ u8 _2D5E[0x2D7D - 0x2D5E];
    /* 0x2D7D */ u8 _2D7D;
    /* 0x2D7E */ u8 _2D7E[0x307A - 0x2D7E];
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B;
    /* 0x307C */ u8 _307C;
    /* 0x307D */ u8 _307D;
    /* 0x307E */ u8 _307E;
    /* 0x307F */ u8 _307F[0x3088 - 0x307F];
    /* 0x3088 */ u8 _3088;
} lbl_8036E548;

extern struct {
    /* 0x0000 */ u8 _0000[0x470D];
    /* 0x470D */ u8 _470D[2];
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0xC7];
    /* 0xC7 */ u8 _C7;
} g_Scores;

extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6;
    /* 0x7 */ u8 _7[2];
    /* 0x9 */ u8 _9;
} g_UnkSimulation_31AC0;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
} lbl_3_data_228;

extern struct {
    /* 0x00 */ u8 _00[0x96];
    /* 0x96 */ u8 _96;
    /* 0x97 */ u8 _97[0xA4 - 0x97];
    /* 0xA4 */ u8 _A4;
    /* 0xA5 */ u8 _A5[0xD7 - 0xA5];
    /* 0xD7 */ u8 _D7;
} lbl_3_common_bss_32724;

extern u8 lbl_803CBC3C;

extern struct {
    /* 0x00 */ void (*callback)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
}* lbl_803CC1B8;

extern void changeScene(u8, s16);
extern void fn_8001E474(void);
extern void fn_8001F228(void);
extern void fn_3_7D458(void);
extern void fn_3_E19E8(void);
extern void fn_3_1663AC(void);
extern void fn_8003BF54(u8, int, int, int, int, int, int, int, int);
extern int fn_8004CA6C(u16 buttons);
extern void fn_8004CC2C(void);

AramEntryD18 lbl_3_data_3D60 = { { 0x0000040B, 0x400098A0, 0x0773D800, 0x00003C88 } };
AramEntryD18 lbl_3_data_3D70 = { { 0x0000040B, 0x40000970, 0x07741800, 0x00000368 } };
AramEntryD18 lbl_3_data_3D80[67] = {
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
    { { 0x0000040B, 0x40001640, 0x08EB4800, 0x00000C38 } },
    { { 0x0000040B, 0x400B2D00, 0x08EB5800, 0x0006A948 } },
    { { 0x00000000, 0x00000686, 0x08F20800, 0x00000688 } },
    { { 0x00000000, 0x00003C98, 0x08F21000, 0x00003C98 } },
    { { 0x0000040B, 0x4000EBBC, 0x08F25000, 0x00009570 } },
};

// .text:0x0005B408 size:0x14 mapped:0x8069A49C
void fn_3_5B408(void) {
    g_GameLogic.frame_exitMenuShowing = 0;
}

// .text:0x0005B380 size:0x88 mapped:0x8069A414
int fn_3_5B380(u16 buttons) {
    if (g_GameLogic.frame_exitMenuShowing < 0x7FFE) {
        g_GameLogic.frame_exitMenuShowing++;
    } else {
        g_GameLogic.frame_exitMenuShowing = 0x7FFF;
    }
    if (g_GameLogic.frame_exitMenuShowing > 20) {
        int result = fn_8004CA6C(buttons);
        if (result == 1) {
            return 1;
        } else if (result == 2) {
            fn_8004CC2C();
        } else if (result == 4) {
            return 2;
        }
    }
    return 0;
}

// .text:0x0005B368 size:0x18 mapped:0x8069A3FC
void fn_3_5B368(void) {
    g_GameLogic.frames_memoryCardWriteOnMVP = 0;
    g_GameLogic.endGameStage = 0;
}

// .text:0x0005B220 size:0x148 mapped:0x8069A2B4
int fn_3_5B220(int arg) {
    if (g_GameLogic.frames_memoryCardWriteOnMVP < 0x7FFE) {
        g_GameLogic.frames_memoryCardWriteOnMVP++;
    } else {
        g_GameLogic.frames_memoryCardWriteOnMVP = 0x7FFF;
    }
    switch (g_GameLogic.endGameStage) {
    case 0:
        if (arg == 1 && g_Minigame._1A3C == 0 && g_Minigame._1A44 == 0 && g_Minigame._1A45 == 0 && g_Minigame._1A43 == 0) {
            return 1;
        }
        fn_8003BF54(lbl_80366158._27, 0, 0, 1, 0, 4, 5, 0, 0);
        g_GameLogic.endGameStage++;
        break;
    case 1:
        if (lbl_803CC1B8->_10 == 1 || lbl_803CC1B8->_10 == 11 || lbl_803CC1B8->_10 == 12 || lbl_803CC1B8->_10 == 7) {
            g_GameLogic.endGameStage++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}

// .text:0x0005B0C4 size:0x15C mapped:0x8069A158
void fn_3_5B0C4(void) {
    g_d_GameSettings.FrameCountWhileNotAtMainMenu++;
    lbl_80366158._28 = 0;
    lbl_80366158._28 = 0;
    fn_3_10007C();
    if (g_UnkSimulation_31AC0._5 != 0) {
        if (g_UnkSimulation_31AC0._6 == 0) {
            g_UnkSimulation_31AC0._5 = 0;
            goto run;
        }
        g_UnkSimulation_31AC0._6--;
        lbl_803CBC3C = 1;
    } else {
    run:
        if (g_GameLogic.PauseSimulationFrameCount != 0) {
            if (--g_GameLogic.PauseSimulationFrameCount != 0) {
                lbl_80366158._28 = 1;
            } else {
                lbl_80366158._28 = 0;
            }
        }
        if (lbl_80366158._28 == 0) {
            lbl_3_data_228._00++;
            fn_3_5ACA0();
        }
    }
    if (g_d_GameSettings.minigamesEnabled) {
        fn_3_E19E8();
    } else {
        fn_3_6C1D8();
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
            fn_3_1663AC();
        }
    }
    fn_3_1CE90();
    fn_3_8DA80();
    lbl_3_data_228._08 = g_Ball.StaticRandomInt1;
    lbl_3_data_228._0C = g_Ball.StaticRandomInt2;
    lbl_3_data_228._04++;
}

// Registers differ from the setup through the stores (97.07%); the instructions
// and their order match.
// .text:0x0005AE9C size:0x228 mapped:0x80699F30
void fn_3_5AE9C(void) {
    int logo0;
    int logo1;
    u8 side;

    changeScene(4, 0);
    side = g_d_GameSettings.home_AwaySetting;
    logo0 = lbl_8034E9A0._470D[side];
    logo1 = lbl_8034E9A0._470D[side ^ 1];
    g_GameLogic.framesOfExitingToMenu = 0;
    g_UnkSimulation_31AC0._4 = 0;
    g_UnkSimulation_31AC0._9 = 0;
    lbl_8036E548._307E = 0;
    g_d_GameSettings.minigamesEnabled = 0;
    g_d_GameSettings._13 = 0;
    g_d_GameSettings.someChallengeModeFlag = 0;
    lbl_8036E548._307A = 0;
    lbl_8036E548._006C = 0;
    lbl_8036E548._307C = 0;
    lbl_8036E548._307D = 0;
    lbl_3_common_bss_32724._A4 = 0;
    g_d_GameSettings._55 = 0;
    g_d_GameSettings.challengeMinigame_baseCoinsEarned = 0;
    g_d_GameSettings.bJMatchRelated = 0;
    lbl_8036E548._2D44 = -1;
    lbl_8036E548._2D50 = -1;
    lbl_8036E548._2D5C = -1;
    g_GameLogic.teams[0] = g_d_GameSettings.PlayerPorts[0];
    g_GameLogic.teams[1] = g_d_GameSettings.PlayerPorts[1] % 4;
    g_GameLogic.logo[0].ID = logo0;
    g_GameLogic.logo[1].ID = logo1;
    g_GameLogic.logo[0].variationID = logo0 % 4;
    g_GameLogic.logo[1].variationID = logo1 % 4;
    g_GameLogic.logo[0].captain = logo0 / 4;
    g_GameLogic.logo[1].captain = logo1 / 4;
    g_Scores._C7 = gameInitOptions.runsNeededForMercy;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD || g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        g_d_GameSettings.minigamesEnabled = 1;
    }
    memset(&g_Minigame, 0, sizeof(g_Minigame));
    g_Minigame.GameMode_MiniGame = 0;
    sndVolume(127, 10, 255);
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD || g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        lbl_8036E548._2D7D = 0;
        lbl_3_common_bss_32724._D7 = 0;
        lbl_803CC1B8->callback = fn_3_59F40;
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        lbl_803CC1B8->callback = fn_3_59C2C;
    } else {
        lbl_803CC1B8->callback = fn_3_5A28C;
    }
}

// .text:0x0005AE0C size:0x90 mapped:0x80699EA0
void fn_3_5AE0C(void) {
    return;
}

// .text:0x0005ACA0 size:0x16C mapped:0x80699D34
void fn_3_5ACA0(void) {
    if (g_GameLogic.framesOfExitingToMenu != 0) {
        fn_3_5A6FC();
        return;
    }
    if (g_GameLogic.FrameCountOfCurrentPitch < 0xFFFE) {
        g_GameLogic.FrameCountOfCurrentPitch++;
    } else {
        g_GameLogic.FrameCountOfCurrentPitch = 0xFFFF;
    }
    if (g_GameLogic.FrameCountOfCurrentAtBat_Copy < 0xFFFE) {
        g_GameLogic.FrameCountOfCurrentAtBat_Copy++;
    } else {
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0xFFFF;
    }
    fn_3_FF4C();
    fn_3_6D304();
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD && g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
        fn_3_7D458();
    }
    fn_3_668BC();
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        fn_3_B482C();
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        fn_3_DFBAC();
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        fn_3_10FDC8();
    } else if (g_GameLogic.secondaryGameMode == 0) {
        fn_3_6011C();
    }
    if (g_d_GameSettings.minigamesEnabled) {
        fn_3_66140();
    } else {
        fn_3_664FC();
    }
    fn_3_BBF94();
    if (lbl_8036E548._3088 != 0) {
        fn_3_B93CC();
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_DEMO && lbl_80366158._2A == 0) {
        lbl_80366158._2A = 1;
    }
}

// .text:0x0005A87C size:0x424 mapped:0x80699910
void fn_3_5A87C(void) {
    return;
}

// .text:0x0005A6FC size:0x180 mapped:0x80699790
void fn_3_5A6FC(void) {
    switch (g_GameLogic.framesOfExitingToMenu) {
    case 1:
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_CHALLENGE && g_d_GameSettings.bJMatchInd == 1) {
            g_d_GameSettings.home_AwaySetting ^= 1;
        }
        fn_3_BF1AC();
        lbl_3_common_bss_32724._96 = 1;
        if (g_d_GameSettings.minigamesEnabled) {
            fn_3_90CB0();
            if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
                fn_3_B95EC();
            }
        } else {
            fn_3_B95EC();
        }
        fn_8001E474();
        fn_3_BC224();
        fn_3_972C8();
        fn_8001F228();
        fn_3_902FC();
        fn_3_8C07C();
        g_GameLogic.framesOfExitingToMenu++;
        g_d_GameSettings._55 = 1;
        break;
    case 2:
        g_GameLogic.framesOfExitingToMenu++;
        break;
    case 29:
        fn_3_90434();
        g_GameLogic.framesOfExitingToMenu++;
        break;
    case 30:
        if (g_GameLogic._128 != 0) {
            lbl_80366158._1C = 2;
        } else {
            lbl_80366158._1C = 1;
        }
        g_d_GameSettings.minigamesEnabled = 0;
        break;
    default:
        g_GameLogic.framesOfExitingToMenu++;
        break;
    }
}

// .text:0x0005A6D4 size:0x28 mapped:0x80699768
void fn_3_5A6D4(u8 status) {
    g_GameLogic.gameStatus_prev = g_GameLogic.gameStatus;
    g_GameLogic.FrameCountOfCurrentPitch = 0;
    g_GameLogic.gameStatus = status;
    g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
    g_GameLogic._125 = 0;
}

// .text:0x0005A6A0 size:0x34 mapped:0x80699734
void fn_3_5A6A0(int battingInd, int homeTeam, int arg2, int arg3) {
    g_GameLogic.homeTeamBattingInd_fieldingTeam = battingInd;
    g_GameLogic.awayTeamBattingInd_battingTeam = battingInd ^ 1;
    g_GameLogic.homeTeamInd = homeTeam;
    g_GameLogic.teamBatting = homeTeam ^ battingInd;
    g_GameLogic.teamFielding = g_GameLogic.teamBatting ^ 1;
    g_GameLogic._1C = arg2;
    g_GameLogic._20 = arg3;
}

// .text:0x0005A684 size:0x1C mapped:0x80699718
void fn_3_5A684(void) {
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_Strikes.outs = 0;
    g_Strikes.forcedOutToEndInningInd = 0;
}

// .text:0x0005A28C size:0x3F8 mapped:0x80699320
void fn_3_5A28C(void) {
    return;
}

// .text:0x00059F40 size:0x34C mapped:0x80698FD4
void fn_3_59F40(void) {
    return;
}

// .text:0x00059C2C size:0x314 mapped:0x80698CC0
void fn_3_59C2C(void) {
    return;
}
