#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_DB8.h"
#include "game/rep_D18.h"
#include "game/rep_1200.h"
#include "game/rep_1188.h"
#include "game/rep_1038.h"
#include "game/rep_1C0.h"
#include "game/rep_540.h"
#include "game/game_batter.h"
#include "game/rep_13B8.h"
#include "game/rep_868.h"
#include "game/rep_AC8.h"
#include "game/rep_A00.h"
#include "game/rep_1A80.h"
#include "game/rep_1E08.h"
#include "game/rep_12D0.h"
#include "game/rep_3090.h"
#include "game/m_sound.h"

extern struct {
    /* 0x00 */ u8 _00[0x96];
    /* 0x96 */ u8 _96;
    /* 0x97 */ u8 _97[0x9A - 0x97];
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x0000 */ u8 _0000[0x470F];
    /* 0x470F */ u8 _470F;
    /* 0x4710 */ u8 _4710;
} lbl_8034E9A0;

extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6;
    /* 0x7 */ u8 _7;
    /* 0x8 */ u8 _8;
    /* 0x9 */ u8 _9;
} g_UnkSimulation_31AC0;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern struct {
    /* 0x00 */ int _00;
    /* 0x04 */ s16 _04[4][19];
    /* 0x9C */ s16 _9C;
    /* 0x9E */ u8 _9E[0xA0 - 0x9E];
    /* 0xA0 */ s16 _A0;
    /* 0xA2 */ u8 _A2[0xA4 - 0xA2];
    /* 0xA4 */ s16 _A4;
    /* 0xA6 */ u8 _A6[0xA8 - 0xA6];
    /* 0xA8 */ u8 _A8[2];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB;
    /* 0xAC */ u8 _AC;
    /* 0xAD */ u8 _AD;
    /* 0xAE */ u8 _AE;
    /* 0xAF */ s8 _AF[2];
    /* 0xB1 */ u8 _B1[0xB3 - 0xB1];
    /* 0xB3 */ s8 _B3[2];
    /* 0xB5 */ s8 _B5[2];
    /* 0xB7 */ s8 _B7[2];
    /* 0xB9 */ u8 _B9[2];
    /* 0xBB */ u8 _BB[2];
    /* 0xBD */ u8 _BD[2];
    /* 0xBF */ u8 _BF[0xC1 - 0xBF];
    /* 0xC1 */ u8 _C1;
    /* 0xC2 */ u8 _C2[0xC6 - 0xC2];
    /* 0xC6 */ u8 _C6;
} g_Scores;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
    /* 0x42 */ u8 _42[0x48 - 0x42];
    /* 0x48 */ u8 _48;
} lbl_3_common_bss_37400;

extern u8 lbl_803CBC3C[];

extern struct {
    /* 0x00 */ u8 _00[0x2];
    /* 0x02 */ s16 _02;
    /* 0x04 */ u8 _04[0x11 - 0x4];
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} g_RunningLogic;

extern void possiblyTransitionBlackScreen(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void Set_803cb848(int);
extern int fn_3_6BA64(void);
extern void fn_3_6B870(void);
extern void starMissionRelated2(void);
extern void changeScene(u8, s16);
extern void fn_800A7568(void);
extern void fn_3_16598C(void);
extern void fn_3_7B130(void);
extern void fn_3_7AFE4(void);
extern void fn_3_1E178(void);
extern void fn_3_1E154(void);
extern void fn_3_7CE90(void);
extern void fn_3_9E7D4(int);
extern void fn_8006C9D8(void);
extern void fn_3_1E328(void);
extern void fn_3_7B308(void);
extern void fn_3_9DBE4(void);
extern void fn_3_7D780(void);
extern void initializeUnknown(void);
extern int fn_3_6C938(int, int);
extern void fn_800203E0(int, s8);
extern u16 fn_3_6BD6C(void);

extern s16 lbl_3_data_607C[16];
extern u8 lbl_3_data_6104[8];

// .text:0x0006011C size:0x64C mapped:0x8069F1B0
void fn_3_6011C(void) {
    return;
}

// .text:0x0005FF10 size:0x20C mapped:0x8069EFA4
void fn_3_5FF10(void) {
    s32 i;

    fn_3_6EF1C();
    g_GameLogic.currentBatterPerTeam[0] = 1;
    g_GameLogic.currentBatterPerTeam[1] = 1;
    g_GameLogic.TeamStars[0] = lbl_8034E9A0._470F;
    g_GameLogic.TeamStars[1] = lbl_8034E9A0._4710;
    if (gameInitOptions.starSkillsSetting == 0) {
        g_GameLogic.TeamStars[0] = 0;
        g_GameLogic.TeamStars[1] = 0;
    }
    g_GameLogic.IsStarChance = 0;
    g_GameLogic.freeFieldingPracticeInd = 0;
    g_GameLogic.gameOverInd = 0;
    g_GameLogic.scoutFlag_VsScreenInd = 0;
    g_GameLogic.playBatterWalkupAnimation = 0;
    g_Scores._A4 = -1;
    g_Scores._AE = 0;
    g_Scores._00 = 1;
    g_Scores._AD = 0;
    g_Scores._C6 = 0;
    for (i = 0; i < 19; i++) {
        g_Scores._04[0][i] = 0;
        g_Scores._04[1][i] = 0;
        g_Scores._04[2][i] = 0;
        g_Scores._04[3][i] = 0;
    }
    for (i = 0; i < 2; i++) {
        g_Scores._A8[i] = 0;
        g_Scores._B3[i] = -1;
        g_Scores._B5[i] = -1;
        g_Scores._B7[i] = -1;
        g_Scores._B9[i] = 0;
        g_Scores._AF[i] = g_GameLogic.battingOrderAndPositionMapping[i][0][0];
        g_Scores._BB[i] = 1;
        g_Scores._BD[i] = 1;
    }
    fn_3_5A6D4(4);
    fn_3_754B8();
    initializeInMemBatter();
    fn_3_FBA8();
    fn_3_595C4();
    fn_3_8A5A4();
    fn_3_1E328();
    fn_3_7B308();
    fn_3_9DBE4();
    fn_3_7D780();
    fn_3_8FF18();
    fn_3_250FC();
    fn_3_8BE8C();
    initializeUnknown();
}

// .text:0x0005FE88 size:0x88 mapped:0x8069EF1C
void fn_3_5FE88(void) {
    switch (g_GameLogic._125) {
    case 0:
        fn_800B0A5C_insertQueue(possiblyTransitionBlackScreen, 2);
        g_GameLogic._125 = 1;
        break;
    case 1:
        fn_800B0A5C_insertQueue(fn_3_5BAC, 4);
        g_GameLogic._125 = 2;
        break;
    default:
        fn_3_5A6D4(5);
        break;
    }
}

// .text:0x0005F930 size:0x558 mapped:0x8069E9C4
void fn_3_5F930(void) {
    return;
}

// .text:0x0005F7A8 size:0x188 mapped:0x8069E83C
void fn_3_5F7A8(void) {
    fn_3_5D3FC();
    fn_3_5A684();
    fn_3_75434();
    fn_3_59338();
    fn_3_8A350();
    fn_3_1E178();
    fn_3_AFDA4();
    fn_3_6C13C();
    fn_3_7B130();
    setBatterContactConstants();
    fn_3_8A1D8();
    fn_3_7AFE4();
    fn_3_1E154();
    fn_3_6C108();
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_Strikes._1E = -1;
    g_Strikes.stateRelated = 0;
    g_GameLogic.frameCountdownAtBeginningOfAtBatLockout = 90;
    g_GameLogic._13D = 0;
}

// .text:0x0005F720 size:0x88 mapped:0x8069E7B4
void fn_3_5F720(void) {
    fn_3_F1DC();
    fn_3_751B4();
    setDefaultInMemBatter();
    fn_3_8913C();
    fn_3_58870();
    fn_3_1DEB8();
    Set_803cb848(1);
    fn_3_6EBB4(g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]);
    g_FieldingLogic._0AE = 0;
    g_GameLogic.homeRunWordAnimationCompletedInd = 0;
    g_UnkSimulation_31AC0._5 = 0;
    g_UnkSimulation_31AC0._6 = 4;
}

// .text:0x0005F3FC size:0x324 mapped:0x8069E490
void fn_3_5F3FC(void) {
    return;
}

// .text:0x0005F154 size:0x2A8 mapped:0x8069E1E8
void fn_3_5F154(void) {
    return;
}

// .text:0x0005EFEC size:0x168 mapped:0x8069E080
void fn_3_5EFEC(void) {
    return;
}

// .text:0x0005EE58 size:0x194 mapped:0x8069DEEC
void fn_3_5EE58(void) {
    if (g_Stats.replayInd == 0) {
        fn_3_7CE90();
        fn_3_77914();
        g_GameLogic.playOverInd = 0;
        if (g_GameLogic.freeFieldingPracticeInd != 0) {
            fn_3_899BC();
            fn_3_9E7D4(g_GameLogic.homeTeamBattingInd_fieldingTeam);
        } else if (g_GameLogic.EventTriggers_EndOfGame != 0) {
            if (g_d_GameSettings.exhibitionMatchInd == 0 &&
                (g_GameLogic.homeTeamInd ^ (g_Scores._A4 == g_d_GameSettings.humanTeamNumber)) != 0) {
                fn_8006C9D8();
            }
        } else if (g_Strikes.outs >= 3) {
            if (g_FieldingLogic._107 < 1 || g_FieldingLogic._107 > 3 || g_Strikes.balls >= 4) {
                fn_3_9E7D4(g_GameLogic.homeTeamBattingInd_fieldingTeam);
            }
            if (g_d_GameSettings.GameModeSelected == 2 && (g_Practice.practiceLevel == 7 || g_Practice.practiceLevel == 6)) {
                fn_3_899BC();
            }
        } else {
            fn_3_899BC();
            fn_3_9E7D4(g_GameLogic.homeTeamBattingInd_fieldingTeam);
        }
        fn_3_5A6D4(8);
        if (g_GameLogic.secondaryGameMode == 0 && g_Stats._39 == 1) {
            g_Stats._39 = 2;
        }
        fn_3_BF1AC();
        fn_3_BF158();
    }
}

// .text:0x0005EDD8 size:0x80 mapped:0x8069DE6C
void fn_3_5EDD8(void) {
    return;
}

// .text:0x0005ED98 size:0x40 mapped:0x8069DE2C
void fn_3_5ED98(void) {
    fn_3_5A6D4(2);
    g_FieldingLogic._0AE = 0;
    g_Pitcher.peachDaisyStarAnimationOn = 0;
}

// .text:0x0005E2C4 size:0xAD4 mapped:0x8069D358
void fn_3_5E2C4(void) {
    return;
}

// .text:0x0005DF54 size:0x370 mapped:0x8069CFE8
void fn_3_5DF54(void) {
    return;
}

// .text:0x0005DD30 size:0x224 mapped:0x8069CDC4
void fn_3_5DD30(void) {
    return;
}

// .text:0x0005DCE0 size:0x50 mapped:0x8069CD74
int fn_3_5DCE0(void) {
    int ret = 0;
    if (g_Pitcher.strikeOutOrWalk == 1) {
        fn_3_736CC();
        ret = 1;
    } else if (g_Pitcher.strikeOutOrWalk == 2) {
        fn_3_735A8();
        ret = 1;
    }
    return ret;
}

// .text:0x0005DA9C size:0x244 mapped:0x8069CB30
void fn_3_5DA9C(void) {
    return;
}

// .text:0x0005D9F8 size:0xA4 mapped:0x8069CA8C
void fn_3_5D9F8(void) {
    if (g_Stats.replayInd == 0) {
        g_Pitcher._15C = 0;
        if (g_d_GameSettings.GameModeSelected == 4 && g_Scores._AD == 0) {
            g_GameLogic.framesOfExitingToMenu = 1;
        } else if (g_GameLogic.EventTriggers_EndOfGame != 0) {
            fn_3_5A6D4(9);
        } else {
            fn_3_5A6D4(3);
        }
    }
}

// .text:0x0005D5E8 size:0x410 mapped:0x8069C67C
void fn_3_5D5E8(void) {
    return;
}

// .text:0x0005D51C size:0xCC mapped:0x8069C5B0
void fn_3_5D51C(void) {
    if (g_Scores._AD == 0) {
        g_Scores._AD = 1;
    } else {
        g_Scores._AD = 0;
        g_Scores._00++;
    }
    g_GameLogic.homeTeamBattingInd_fieldingTeam ^= 1;
    g_GameLogic.awayTeamBattingInd_battingTeam ^= 1;
    g_GameLogic.teamBatting ^= 1;
    g_GameLogic.teamFielding ^= 1;
    g_GameLogic._131 = 0;
    g_GameLogic._132 = 0;
    g_Scores._A0 = g_Scores._04[g_Scores._AD][0];
    fn_3_5A684();
    fn_3_8A350();
    fn_3_F7B8();
    fn_3_75434();
    fn_3_59338();
    fn_3_7B130();
    fn_3_22850();
}

// .text:0x0005D3FC size:0x120 mapped:0x8069C490
void fn_3_5D3FC(void) {
    GameInitVariables* settings = &g_d_GameSettings;

    g_GameLogic._135 = 0;
    g_GameLogic._136 = 0;
    g_RunningLogic._11 = 0;
    g_RunningLogic._13 = 0;
    g_RunningLogic._02 = 0;
    g_Scores._AC = fn_3_5C530(g_Scores._00);
    g_Scores._C1 = 0;
    g_Scores._C6 = 0;
    lbl_3_common_bss_37400._48 = 0;
    fn_3_6C13C();
    if (settings->exhibitionMatchInd == 0) {
        fn_3_16598C();
    }
}

// .text:0x0005D094 size:0x368 mapped:0x8069C128
void fn_3_5D094(int arg) {
    return;
}

// .text:0x0005CFD0 size:0xC4 mapped:0x8069C064
void fn_3_5CFD0(void) {
    StarMissionCompletionTracker* t = &starMissionCompletionTracker;
    int a = t->_441C;
    int b = t->_441E;
    int c;

    if (g_d_GameSettings.exhibitionMatchInd == 0 && g_Scores._A4 <= 1 &&
        (g_Scores._A4 ^ (g_GameLogic.homeTeamInd == lbl_3_common_bss_37400._40)) != 0) {
        if ((t->_441F[3] >= 4 && b == 5) ||
            (t->_441F[3] >= 5 && (c = t->_441F[0xD0]) == 1 && a == 5)) {
            g_GameLogic.playOverFadeOutStarted = 0;
        }
        starMissionRelated2();
    }
}

// .text:0x0005CDB4 size:0x21C mapped:0x8069BE48
void fn_3_5CDB4(void) {
    switch (g_GameLogic._125) {
    case 0:
        changeScene(1, 6);
        g_GameLogic.scoreBook_teamDisplayed = 0;
        lbl_3_common_bss_32724._9B = 0;
        lbl_3_common_bss_32724._9A = 0;
        g_GameLogic._125 = 1;
        break;
    case 1:
        if (g_GameLogic.playOverFadeOutStarted < 0 || g_GameLogic.scoreBook_teamDisplayed != 0) {
            if (g_GameLogic.FrameCountOfCurrentPitch >= 40 && fn_3_6C938(1, 0x1300) != 0) {
                g_GameLogic._125 = 2;
            }
            if (fn_3_FD9FC() != 0) {
                g_GameLogic._125 = 2;
            }
        }
        break;
    case 2:
        if (g_d_GameSettings.exhibitionMatchInd == 0 && g_d_GameSettings.bJMatchInd == 1) {
            fn_800203E0(12, lbl_3_data_6104[starMissionCompletionTracker._441C]);
        } else {
            changeScene(3, 6);
        }
        fn_3_90328(-1);
        g_GameLogic._125 = 3;
        break;
    case 3:
        if (lbl_8037169C._13 != 0) {
            fn_3_FBD70();
            fn_3_FBD58();
            g_GameLogic._125 = 4;
        }
        break;
    case 4:
        if (g_GameLogic.playOverFadeOutStarted >= 0) {
            fn_3_5A6D4(14);
            fn_3_8C07C();
        } else if (g_d_GameSettings.exhibitionMatchInd == 0 && g_d_GameSettings.bJMatchInd == 1) {
            g_GameLogic._125 = 5;
        } else {
            fn_3_5A6D4(14);
            fn_3_8C07C();
        }
        break;
    case 5:
        fn_3_8C07C();
        g_GameLogic._125 = 6;
        break;
    case 6:
        g_GameLogic._128 = 1;
        g_GameLogic.framesOfExitingToMenu = 1;
        break;
    }
    if (g_GameLogic.playOverFadeOutStarted >= 0 && g_GameLogic.scoreBook_teamDisplayed == 0) {
        g_GameLogic.teamFielding = g_GameLogic.playOverFadeOutStarted;
        g_GameLogic.scoreBook_teamDisplayed = fn_3_6BD6C();
    }
}

// .text:0x0005CD24 size:0x90 mapped:0x8069BDB8
void fn_3_5CD24(void) {
    if (g_GameLogic._125 == 0) {
        lbl_3_common_bss_32724._9A = 0;
        fn_3_8A1D8();
        fn_3_6C108();
        fn_3_6B870();
        g_GameLogic._125++;
    } else if (g_GameLogic._125 == 1) {
        if (fn_3_6BA64() != 0) {
            lbl_803CBC3C[2] = 0;
            fn_3_5A6D4(0);
        }
    }
}

// .text:0x0005C74C size:0x5D8 mapped:0x8069B7E0
void fn_3_5C74C(int arg) {
    return;
}

// .text:0x0005C69C size:0xB0 mapped:0x8069B730
void fn_3_5C69C(int base) {
    g_Ball.framesSinceHit = 100;
    g_Ball.framesSincePickOff = 0;
    g_FieldingLogic._107 = base + 1;
    g_FieldingLogic.throwSpeedType = 3;
    fn_3_5ED98();
    fn_3_32090();
    fn_3_8911C();
    if (g_Strikes.balls >= 4) {
        g_Runners[0].runnerOnFieldOrOutOrScored = 5;
    } else {
        g_Runners[0].runnerOnFieldOrOutOrScored = 4;
    }
}

// .text:0x0005C5C8 size:0xD4 mapped:0x8069B65C
void fn_3_5C5C8(void) {
    int i;

    for (i = 0; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 3 ||
            g_Runners[i].runnerOnFieldOrOutOrScored == 4) {
            g_Scores._9C++;
            g_Runners[i].runnerOnFieldOrOutOrScored = 3;
        }
    }
}

// .text:0x0005C530 size:0x98 mapped:0x8069B5C4
u8 fn_3_5C530(int inning) {
    if (inning > g_Scores._AA) {
        return 5;
    }
    if (g_Scores._AA <= 3) {
        if (g_Scores._AA == inning && g_Scores._AD != 0) {
            return 4;
        }
        return 0;
    }
    if (inning == g_Scores._AA) {
        return 4;
    }
    if ((g_Scores._AA == 9 && inning >= 7) || (g_Scores._AA == 7 && inning >= 6)) {
        return 3;
    }
    if (inning >= 4) {
        return 2;
    }
    return 1;
}

// .text:0x0005C418 size:0x118 mapped:0x8069B4AC
void fn_3_5C418(void) {
    int flag = 0;

    if (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT || g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL ||
        (u8)(g_GameLogic.gameStatus - GAME_STATUS_HOMERUN_END) <= 3 ||
        g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY) {
        flag = 1;
    }
    if (g_UnkSimulation_31AC0._8 == 0) {
        if (lbl_803C77B8[0]._02 & 0x1000) {
            g_UnkSimulation_31AC0._8 = 1;
        }
    } else {
        if (flag) {
            changeScene(3, 6);
        }
        if (lbl_8037169C._13 != 0 && flag) {
            if (lbl_803C6CF8._715 == 1) {
                lbl_3_common_bss_32724._96 = 1;
                g_GameLogic.framesOfExitingToMenu = 1;
            } else if (g_UnkSimulation_31AC0._9 == 0) {
                fn_800A7568();
                g_UnkSimulation_31AC0._9 = 1;
            }
        }
    }
}

// .text:0x0005BD40 size:0x6D8 mapped:0x8069ADD4
void fn_3_5BD40(void) {
    return;
}

// .text:0x0005BA2C size:0x314 mapped:0x8069AAC0
void fn_3_5BA2C(void) {
    return;
}

// .text:0x0005B5A0 size:0x48C mapped:0x8069A634
void fn_3_5B5A0(void) {
    return;
}

// .text:0x0005B41C size:0x184 mapped:0x8069A4B0
void fn_3_5B41C(void) {
    int result = 2;
    int diff;

    if (g_Scores._A4 == 2) {
        result = 1;
    } else if (g_Scores._A4 == g_GameLogic.homeTeamInd) {
        result = 0;
    }
    if (g_d_GameSettings.bJMatchInd == 0) {
        g_d_GameSettings.challengeMinigame_baseCoinsEarned += lbl_3_data_607C[result];
        diff = __abs(g_Scores._04[g_GameLogic.homeTeamInd][0] - g_Scores._04[g_GameLogic.homeTeamInd ^ 1][0]);
        if (result == 0) {
            g_d_GameSettings.challengeMinigame_baseCoinsEarned += diff * lbl_3_data_607C[3] / 100;
        } else if (result == 2) {
            g_d_GameSettings.challengeMinigame_baseCoinsEarned += diff * lbl_3_data_607C[4] / 100;
        }
        g_d_GameSettings.challengeMinigame_baseCoinsEarned += g_GameLogic.TeamStars[0] * lbl_3_data_607C[5] / 100;
    } else {
        g_d_GameSettings.challengeMinigame_baseCoinsEarned += lbl_3_data_607C[result + 9];
        g_d_GameSettings.bJMatchRelated += lbl_3_data_607C[result + 12];
    }
}
