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
#include "game/rep_3448.h"
#include "game/rep_3DA8.h"
#include "game/rep_60.h"
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
    /* 0x00 */ u8 _00[0xAA];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB;
    /* 0xAC */ u8 _AC[0xC7 - 0xAC];
    /* 0xC7 */ u8 _C7;
} g_Scores;

extern struct {
    /* 0x0 */ s32 _0;
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
    /* 0x10 */ u8 _10;
} lbl_3_data_228;

extern struct {
    /* 0x00 */ u8 _00[0x96];
    /* 0x96 */ u8 _96;
    /* 0x97 */ u8 _97[0xA4 - 0x97];
    /* 0xA4 */ u8 _A4;
    /* 0xA5 */ u8 _A5[0xD7 - 0xA5];
    /* 0xD7 */ u8 _D7;
    /* 0xD8 */ u8 _D8;
} lbl_3_common_bss_32724;

extern u8 lbl_803CBC3C;

typedef struct UnkTaskD18 {
    /* 0x00 */ void (*callback)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
} UnkTaskD18;

extern UnkTaskD18* lbl_803CC1B8;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x000 */ u8 _000[0x7B0];
    /* 0x7B0 */ void* _7B0;
} lbl_80366B18;

extern struct {
    /* 0x000 */ u8 _000[0x3B0];
    /* 0x3B0 */ u8 _3B0;
} lbl_3_common_bss_35154;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

extern void* lbl_3_common_bss_1323C;
extern u8 lbl_3_common_bss_134C4[];

extern void fn_800111B4(void* arg);
extern void fn_8001A25C(void* arg);
extern void* ARAMTransfer(AramEntryD18* entry, int arg1, int arg2, u32 aram);
extern void changeScene(u8, s16);
extern void fn_80019A60(void* arg);
extern void fn_8001A3FC(int arg);
extern void fn_8001CE74(void);
extern void fn_800216F8(u8 group, int (*callback)(void));
extern int fn_80035838(AramEntryD18* entry, int count);
extern int fn_3_1665E4(void);
extern void fn_8001E474(void);
extern void fn_8001F228(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_3_7D458(void);
extern void fn_3_E19E8(void);
extern void fn_3_1663AC(void);
extern void fn_8003BF54(u8, int, int, int, int, int, int, int, int);
extern int fn_8004CA6C(u16 buttons);
extern void fn_8004CC2C(void);
extern void fn_3_6D4A0(void);
extern u8 calledWhenStartingMatch(void);
extern int fn_80020218(void);
extern int fn_80020278(u8 arg);
extern s32 fn_800698F8(s32 charID);
extern int fn_80069B68(void);

extern struct {
    /* 0x000 */ u8 _000[0x39A];
    /* 0x39A */ u8 _39A;
} lbl_800EF808;

extern struct {
    /* 0x00 */ u8 _00[0x1B];
    /* 0x1B */ u8 _1B;
} lbl_8037169C;

static AramEntryD18 lbl_3_data_3D60 = { { 0x0000040B, 0x400098A0, 0x0773D800, 0x00003C88 } };
static AramEntryD18 lbl_3_data_3D70 = { { 0x0000040B, 0x40000970, 0x07741800, 0x00000368 } };
static AramEntryD18 lbl_3_data_3D80[62] = {
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
static AramEntryD18 lbl_3_data_4160[5] = {
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
    fn_3_6D4A0();
    g_UnkSimulation_31AC0._7[1] = 0;
    g_UnkSimulation_31AC0._7[0] = 0;
    fn_3_5A87C();
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        fn_3_DFA20();
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        fn_3_10FBE4();
    }
    g_Minigame._19AB = 0;
    fn_3_6C150();
    fn_3_8F1C8();
    lbl_803CC1B8->callback = fn_3_5B0C4;
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
    int i;
    int home;
    u8 mode;

    lbl_80366158._28 = 0;
    lbl_3_data_228._00 = 0;
    lbl_3_data_228._04 = 0;
    g_UnkSimulation_31AC0._0 = g_d_GameSettings.FrameCountWhileNotAtMainMenu;
    g_UnkSimulation_31AC0._5 = 0;
    g_UnkSimulation_31AC0._6 = 4;
    g_d_GameSettings.humanTeamNumber = 0;
    g_GameLogic._125 = 0;
    g_GameLogic.EventTriggers_EndOfGame = 0;
    g_GameLogic._128 = 0;
    g_GameLogic.sceneID = 0;
    g_GameLogic.EventTriggers_GameHasStarted = 0;
    g_GameLogic._124 = 0;
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    g_GameLogic.winType = 0;
    g_GameLogic._131[0] = 0;
    g_GameLogic._131[1] = 0;
    g_GameLogic._133[0] = 0;
    g_GameLogic._133[1] = 0;
    g_GameLogic._106 = -1;
    g_GameLogic.bOD_framesInLiveBallScene = -1;
    g_GameLogic.playOverFadeOutStarted = -1;
    g_GameLogic.PauseSimulationFrameCount = 0;
    g_Practice.practiceLevel = 0;
    lbl_3_common_bss_1323C = lbl_3_common_bss_134C4;
    g_GameLogic.secondaryGameMode = 0;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        g_GameLogic.secondaryGameMode = 0x12;
    }
    fn_3_1CCC8();
    mode = g_d_GameSettings.GameModeSelected;
    g_Scores._AA = gameInitOptions.inningSetting;
    g_Scores._AB = gameInitOptions.inningSetting + 3;
    if (mode == GAME_TYPE_DEMO) {
        g_Scores._AB = 5;
        g_Scores._AA = 5;
    }
    for (i = 0; i < 2; i++) {
        g_GameLogic._13E[i] = 0;
        g_GameLogic._140[i] = 0;
        g_GameLogic.batterHandedness[i] = 0;
        g_GameLogic.teamAIInd[i] = 0;
        g_GameLogic.autoFielding[i] = 0;
        g_GameLogic.battingAIInd[i] = 0;
    }
    g_GameLogic.AIDifficulty0Special3Weak[0] = gameInitOptions._3;
    g_GameLogic.AIDifficulty0Special3Weak[1] = gameInitOptions._3;
    g_GameLogic.homeTeamBattingInd_fieldingTeam = 0;
    g_GameLogic.awayTeamBattingInd_battingTeam = 1;
    g_GameLogic.homeTeamInd = g_d_GameSettings.home_AwaySetting;
    g_GameLogic.teamBatting = g_d_GameSettings.home_AwaySetting;
    g_GameLogic.teamFielding = g_d_GameSettings.home_AwaySetting ^ 1;
    home = g_d_GameSettings.home_AwaySetting;
    g_GameLogic._1C = (&g_d_GameSettings.maybeHomeAway)[home];
    g_GameLogic._20 = (&g_d_GameSettings.maybeHomeAway)[home ^ 1];
    if (mode == GAME_TYPE_PRACTICE) {
        g_GameLogic.AIDifficulty0Special3Weak[home] = 1;
        g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.homeTeamInd ^ 1] = 1;
    } else if (g_d_GameSettings._10 == 0) {
        g_GameLogic._13E[1] = 1;
        g_GameLogic._140[home ^ 1] = 1;
        g_GameLogic.batterHandedness[g_GameLogic.homeTeamInd ^ 1] = 1;
        lbl_3_common_bss_37400._40 = 0;
        g_GameLogic.teamAIInd[g_GameLogic.homeTeamInd ^ 1] = 1;
        g_GameLogic.autoFielding[g_GameLogic.homeTeamInd ^ 1] = 1;
        g_GameLogic.battingAIInd[g_GameLogic.homeTeamInd ^ 1] = 1;
        g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.homeTeamInd] = 1;
    } else if (g_d_GameSettings._10 == 3) {
        g_GameLogic._13E[0] = 1;
        g_GameLogic._140[home] = 1;
        g_GameLogic.batterHandedness[g_GameLogic.homeTeamInd] = 1;
        lbl_3_common_bss_37400._40 = 1;
        g_GameLogic.teamAIInd[g_GameLogic.homeTeamInd] = 1;
        g_GameLogic.autoFielding[g_GameLogic.homeTeamInd] = 1;
        g_GameLogic.battingAIInd[g_GameLogic.homeTeamInd] = 1;
        g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.homeTeamInd ^ 1] = 1;
    } else if (g_d_GameSettings._10 == 2) {
        g_GameLogic._13E[1] = 1;
        g_GameLogic._13E[0] = 1;
        g_GameLogic._140[1] = 1;
        g_GameLogic._140[0] = 1;
        g_GameLogic.batterHandedness[1] = 1;
        g_GameLogic.batterHandedness[0] = 1;
        g_GameLogic.teamAIInd[1] = 1;
        g_GameLogic.teamAIInd[0] = 1;
        g_GameLogic.autoFielding[1] = 1;
        g_GameLogic.autoFielding[0] = 1;
        g_GameLogic.battingAIInd[1] = 1;
        g_GameLogic.battingAIInd[0] = 1;
    } else {
        g_GameLogic.AIDifficulty0Special3Weak[0] = 1;
        g_GameLogic.AIDifficulty0Special3Weak[1] = 1;
    }
    for (i = 0; i < 2; i++) {
        if (g_GameLogic._13E[i] == 0) {
            if (gameInitOptions.teamOptions[g_GameLogic.teams[i]]._0) {
                g_GameLogic.batterHandedness[g_GameLogic.homeTeamInd ^ i] = 1;
            }
            if (gameInitOptions.teamOptions[g_GameLogic.teams[i]]._1) {
                g_GameLogic._140[g_GameLogic.homeTeamInd ^ i] = 1;
            }
            if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoRunning) {
                g_GameLogic.battingAIInd[g_GameLogic.homeTeamInd ^ i] = 1;
            }
            if (gameInitOptions.controlOptions[g_GameLogic.teams[i]].autoFielding) {
                g_GameLogic.teamAIInd[g_GameLogic.homeTeamInd ^ i] = 1;
                g_GameLogic.autoFielding[g_GameLogic.homeTeamInd ^ i] = 1;
            }
        }
    }
    fn_3_1658F0();
    fn_3_5FF10();
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

static inline s16 getSlotCharID(u8 slot) {
    return inMemRoster[slot / 9][slot % 9].stats.CharID;
}

// .text:0x0005A28C size:0x3F8 mapped:0x80699320
void fn_3_5A28C(void) {
    UnkTaskD18* task = lbl_803CC1B8;
    s16 group;

    switch (g_UnkSimulation_31AC0._4) {
    case 0:
        lbl_8037169C._1B = calledWhenStartingMatch();
        g_UnkSimulation_31AC0._4++;
    case 1:
        lbl_3_common_bss_32724._A4 = 0;
        if (fn_80020218() != 0) {
            if (fn_80020278(lbl_8037169C._1B) != 0) {
                lbl_3_common_bss_32724._A4 = 1;
                g_UnkSimulation_31AC0._4++;
            }
        } else {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 2:
        task->_10 = 0;
        fn_800216F8(1, fn_3_910AC);
        g_UnkSimulation_31AC0._4++;
        break;
    case 3:
        if (task->_10 != 0) {
            task->_10 = 0;
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 4:
        group = fn_800698F8(getSlotCharID(lbl_800EF808._39A));
        fn_800216F8(group + 5, fn_3_90F48);
        g_UnkSimulation_31AC0._4++;
        break;
    case 5:
        if (task->_10 != 0) {
            if (lbl_800EF808._39A != 17) {
                lbl_800EF808._39A++;
                g_UnkSimulation_31AC0._4 = 4;
            } else {
                lbl_800EF808._39A = 0;
                task->_10 = 0;
                g_UnkSimulation_31AC0._4++;
            }
        }
        break;
    case 6:
        fn_800216F8(g_d_GameSettings.StadiumID + 39, fn_3_90798);
        g_UnkSimulation_31AC0._4++;
        break;
    case 7:
        if (task->_10 != 0) {
            task->_10 = 0;
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 8:
        lbl_3_data_228._10 = 0;
        fn_800B0A5C_insertQueue(manageLoadingState, 0);
        g_UnkSimulation_31AC0._4++;
        break;
    case 9:
        if (lbl_3_data_228._10 != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 10:
        if (fn_80035838(lbl_3_data_3D80, 2) != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 11:
        if (fn_80035838(&lbl_3_data_3D80[g_GameLogic.logo[0].ID / 4 + 17], 15) != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 12:
        if (fn_80035838(&lbl_3_data_3D80[g_GameLogic.logo[1].ID / 4 + 17], 16) != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 13:
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_DEMO && fn_80069B68() == 0) {
            break;
        }
        g_UnkSimulation_31AC0._4++;
    case 14:
        fn_8001CE74();
        fn_8001A3FC(0);
        g_UnkSimulation_31AC0._4 = 17;
        break;
    case 17:
        lbl_3_common_bss_34C58._00 = (u32)ARAMTransfer(&lbl_3_data_3D60, 0, 0, 0);
        g_UnkSimulation_31AC0._4++;
        break;
    case 18:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_906FC();
            g_UnkSimulation_31AC0._4++;
        }
        break;
    default:
        task->callback = fn_3_5AE0C;
        break;
    }
}

// The target reaches the tables from one pool base: lbl_3_data_3D80 lumps a
// 62-entry table with the entry at 0x4160 (one addi of 0x400) and what follows,
// which need their own statics before the base and branches match (92%).
// .text:0x00059F40 size:0x34C mapped:0x80698FD4
void fn_3_59F40(void) {
    UnkTaskD18* task = lbl_803CC1B8;

    switch (g_UnkSimulation_31AC0._4) {
    case 0:
        task->_10 = 0;
        lbl_3_common_bss_32724._D8 = 0;
        g_UnkSimulation_31AC0._4++;
        break;
    case 1:
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            fn_800216F8(45, fn_3_90798);
        } else {
            fn_800216F8(46, fn_3_90764);
        }
        g_UnkSimulation_31AC0._4++;
        break;
    case 2:
        if (task->_10 != 0) {
            task->_10 = 0;
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 3:
        lbl_3_common_bss_34C58._00 = (u32)ARAMTransfer(&lbl_3_data_3D60, 0, 0, 0);
        g_UnkSimulation_31AC0._4++;
        break;
    case 4:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_906FC();
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 5:
        fn_8001CE74();
        lbl_8036E548._2D7D = 0;
        fn_8001A25C(&lbl_8036E548);
        g_UnkSimulation_31AC0._4++;
        break;
    case 6:
        if (lbl_8036E548._2D7D != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 7:
        if (fn_3_BF878() != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 8:
        if (lbl_3_common_bss_35154._3B0 == 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 9:
        if (fn_3_11D6A0() != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 10:
        fn_3_106E50();
        g_UnkSimulation_31AC0._4++;
        break;
    case 11:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_106DFC();
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 12:
        lbl_80366B18._7B0 = ARAMTransfer(&lbl_3_data_4160[2], 0, 1, 0);
        g_UnkSimulation_31AC0._4++;
        break;
    case 13:
        if (lbl_803C6CF8._715 == 1) {
            fn_800111B4(lbl_80366B18._7B0);
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 14:
        if (fn_80035838(&lbl_3_data_3D80[0], 2) != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 15:
        if (fn_80035838(&lbl_3_data_3D80[3], 3) != 0) {
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
                g_UnkSimulation_31AC0._4 = 16;
            } else {
                g_UnkSimulation_31AC0._4 = 17;
            }
        }
        break;
    case 16:
        if (fn_80035838(&lbl_3_data_3D80[4], 14) != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 17:
        if (fn_80035838(&lbl_3_data_3D80[5], 20) != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 18:
        task->callback = fn_3_5AE0C;
        break;
    }
}

// .text:0x00059C2C size:0x314 mapped:0x80698CC0
void fn_3_59C2C(void) {
    UnkTaskD18* task = lbl_803CC1B8;

    switch (g_UnkSimulation_31AC0._4) {
    case 0:
        task->_10 = 0;
        fn_800216F8(3, fn_3_91064);
        g_UnkSimulation_31AC0._4++;
        break;
    case 1:
        if (task->_10 != 0) {
            task->_10 = 0;
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 2:
        fn_800216F8(g_d_GameSettings.StadiumID + 39, fn_3_90798);
        g_UnkSimulation_31AC0._4++;
        break;
    case 3:
        if (task->_10 != 0) {
            task->_10 = 0;
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 4:
        lbl_3_data_228._10 = 0;
        fn_800B0A5C_insertQueue(manageLoadingState, 0);
        g_UnkSimulation_31AC0._4++;
        break;
    case 5:
        if (lbl_3_data_228._10 == 1) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 6:
        if (fn_80035838(lbl_3_data_3D80, 2) != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 7:
        if (fn_80035838(&lbl_3_data_3D80[14], 11) != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 8:
        if (fn_80035838(&lbl_3_data_3D80[29], 9) != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 9:
        lbl_3_common_bss_34C58._00 = (u32)ARAMTransfer(&lbl_3_data_3D70, 0, 0, 0);
        g_UnkSimulation_31AC0._4++;
        break;
    case 10:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_906FC();
            lbl_3_common_bss_34C58._2C = 0;
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 11:
        if (fn_3_90928() != 0) {
            lbl_3_common_bss_34C58._2C = 0;
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 12:
        fn_8001CE74();
        fn_3_B42A8();
        fn_8001A3FC(2);
        lbl_8036E548._2D7D = 0;
        fn_80019A60(&lbl_8036E548);
        g_UnkSimulation_31AC0._4++;
        break;
    case 13:
        if (lbl_8036E548._2D7D != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 14:
        if (fn_3_1665E4() != 0) {
            g_UnkSimulation_31AC0._4++;
        }
        break;
    case 15:
        fn_3_106E50();
        g_UnkSimulation_31AC0._4++;
        break;
    case 16:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_106DFC();
            g_UnkSimulation_31AC0._4++;
        }
        break;
    default:
        task->callback = fn_3_5AE0C;
        break;
    }
}
