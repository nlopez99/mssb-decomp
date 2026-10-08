#include "game/rep_1BC8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/rep_1188.h"
#include "game/m_sound.h"
#include "game/rep_AC8.h"
#include "game/rep_1C0.h"
#include "string.h"
#include "game/rep_1B20.h"
#include "game/rep_1C18.h"
#include "game/rep_1C68.h"
#include "game/rep_1AD0.h"
#include "game/rep_3A98.h"
#include "game/rep_D18.h"

extern struct {
    /* 0x0000 */ u8 _0000[0x2D77];
    /* 0x2D77 */ u8 _2D77;
    /* 0x2D78 */ u8 _2D78[0x2D7B - 0x2D78];
    /* 0x2D7B */ u8 _2D7B;
    /* 0x2D7C */ u8 _2D7C;
    /* 0x2D7D */ u8 _2D7D[0x307A - 0x2D7D];
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B[0x307E - 0x307B];
    /* 0x307E */ u8 _307E;
} lbl_8036E548;

extern struct {
    /* 0x0000 */ CharacterStats _0000[1];
} lbl_8034E9A0;

extern u8 lbl_80354720[2][9][4];

extern struct {
    /* 0x0000 */ u8 _0000[0xCF4E];
    /* 0xCF4E */ u8 _CF4E[4][4];
} lbl_80354768;

// .data of rep_1B20
extern u8 lbl_3_data_FAA8[3][9];
// .data of rep_1BC8's neighbours
extern u8 lbl_3_data_10578[0x20];

extern struct {
    /* 0x00 */ u8 _00[0x27];
    /* 0x27 */ u8 _27;
} lbl_80366158;

extern struct {
    /* 0x000 */ u8 _000[0x7AC];
    /* 0x7AC */ void* _7AC;
} lbl_80366B18;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern void* ARAMTransfer(void* entry, int arg1, int arg2, u32 aram);
extern void fn_800111B4(void* arg);
extern void fn_8000F4B8(int arg0, int arg1, int arg2, int arg3);

extern u8 lbl_800E8558[];
extern BOOL fn_8001594C(int team);

extern void possiblyTransitionBlackScreen(void);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void fn_80011BE4(int arg);
extern BOOL fn_80014F40(s16 id);
extern BOOL fn_80014D4C(s16 id);

extern struct {
    /* 0x00 */ u8 _00[0x9E];
    /* 0x9E */ s16 _9E;
    /* 0xA0 */ s16 _A0;
} lbl_3_common_bss_32724;

// .text outside every unit
extern void fn_3_6AEC0(void);

// .text:0x000B482C size:0x1A8 mapped:0x806F38C0
void fn_3_B482C(void) {
    g_Practice.readyToMoveToNextInstruction = 0;
    if (g_Practice._19F != 0) {
        fn_3_B2E20();
        fn_3_8FC80();
        return;
    }
    if (g_Practice.framesInCurrTransitionState < 0xFFFE) {
        g_Practice.framesInCurrTransitionState++;
    } else {
        g_Practice.framesInCurrTransitionState = 0xFFFF;
    }
    if (g_Practice.framesSincePracticeMenuDefaultTransition < 0xFFFE) {
        g_Practice.framesSincePracticeMenuDefaultTransition++;
    } else {
        g_Practice.framesSincePracticeMenuDefaultTransition = 0xFFFF;
    }
    if (g_Practice.totalFrames < 0xFFFE) {
        g_Practice.totalFrames++;
    } else {
        g_Practice.totalFrames = 0xFFFF;
    }
    switch (g_GameLogic.secondaryGameMode) {
    case 18:
        fn_3_B43E8();
        break;
    case 10:
        fn_3_B5D78();
        break;
    case 11:
        fn_3_B6BA4();
        break;
    case 12:
        fn_3_B0AAC();
        break;
    case 13:
        fn_3_B1C14();
        break;
    case 14:
        fn_3_B77DC();
        break;
    case 15:
    case 16:
        fn_3_15B610();
        break;
    case 17:
        g_GameLogic.framesOfExitingToMenu = 1;
        break;
    }
    fn_3_8FC80();
    if (g_GameLogic.gameStatus == 1 || g_GameLogic.gameStatus == 2) {
        if (lbl_3_common_bss_32724._9E >= 0 && fn_80014F40(lbl_3_common_bss_32724._9E)) {
            lbl_3_common_bss_32724._9E = -1;
        }
        if (lbl_3_common_bss_32724._A0 >= 0 && fn_80014D4C(lbl_3_common_bss_32724._A0)) {
            lbl_3_common_bss_32724._A0 = -1;
        }
    }
}

// .text:0x000B43E8 size:0x444 mapped:0x806F347C
void fn_3_B43E8(void) {
    u8 team;

    switch (g_GameLogic._125) {
    case 0:
        fn_3_B42A8();
        team = lbl_80366158._27;
        g_Practice.homeAway = team;
        g_Practice._192 = team;
        g_GameLogic.homeTeamInd = 0;
        g_GameLogic.teamBatting = 1;
        g_GameLogic.teamFielding = 0;
        g_GameLogic.homeTeamBattingInd_fieldingTeam = 1;
        g_GameLogic.awayTeamBattingInd_battingTeam = 0;
        g_GameLogic.teams[0] = team;
        g_GameLogic.teams[1] = team;
        g_GameLogic.Team_CaptainRosterLoc[0] = 0;
        g_GameLogic.Team_CaptainRosterLoc[1] = 0;
        g_GameLogic._125++;
        break;
    case 1:
        lbl_80366B18._7AC = ARAMTransfer(lbl_3_data_10578, 0, 1, 0);
        g_GameLogic._125++;
        break;
    case 2:
        if (lbl_803C6CF8._715 == 1) {
            fn_800111B4(lbl_80366B18._7AC);
            lbl_3_common_bss_34C58._2C = 0;
            g_GameLogic._125++;
            fn_8000F4B8(g_Practice._192, -1, -1, -1);
        }
        break;
    case 3:
        if (fn_3_90C14(0)) {
            lbl_3_common_bss_34C58._2C = 0;
            g_GameLogic._125++;
        }
        break;
    default:
        g_Practice._19C = 0;
        lbl_8036E548._2D77 = 0;
        lbl_8036E548._2D7B = 0;
        lbl_8036E548._2D7C = 0;
        fn_8001594C(g_GameLogic.teamFielding);
        g_Practice.lakituTextIndex = -1;
        g_Practice.returnToPracticeMenuState = 1;
        g_Practice.someCharID1 = -1;
        g_Practice.someCharID2 = -1;
        g_Practice._1B1 = 0;
        g_Practice._1DA = 1;
        fn_3_5A6D4(5);
        fn_3_B3CAC(10);
        fn_3_B5D4C(0);
        fn_3_B3FE8();
        break;
    }
}

// .text:0x000B42A8 size:0x140 mapped:0x806F333C
void fn_3_B42A8(void) {
    int i;
    int team;

    g_GameLogic.battingOrderAndPositionMapping[0][0][0] = lbl_3_data_FAA8[0][0];
    g_GameLogic.battingOrderAndPositionMapping[1][0][0] = lbl_3_data_FAA8[0][0];
    for (team = 0; team < 2; team++) {
        for (i = 0; i < 9; i++) {
            g_GameLogic.battingOrderAndPositionMapping[team][i + 1][0] = lbl_3_data_FAA8[1][i];
            g_GameLogic.battingOrderAndPositionMapping[team][i + 1][1] = lbl_3_data_FAA8[1][i];
            lbl_80354720[team][i][0] = i;
            lbl_80354720[team][i][1] = i;
            lbl_80354720[team][i][2] = i;
        }
    }
    for (team = 0; team < 2; team++) {
        for (i = 0; i < 9; i++) {
            memcpy(&inMemRoster[team][i], &lbl_8034E9A0._0000[g_GameLogic.battingOrderAndPositionMapping[team][i + 1][0]],
                   sizeof(CharacterStats));
        }
    }
}

// .text:0x000B4124 size:0x184 mapped:0x806F31B8
void fn_3_B4124(int team, int slot, int charID, int handedness) {
    if (team == 0 && slot == 0) {
        g_GameLogic.battingOrderAndPositionMapping[team][0][0] = slot;
    }
    g_GameLogic.battingOrderAndPositionMapping[team][slot + 1][0] = slot;
    g_GameLogic.battingOrderAndPositionMapping[team][slot + 1][1] = slot;
    lbl_80354720[team][slot][0] = slot;
    lbl_80354720[team][slot][1] = slot;
    lbl_80354720[team][slot][2] = slot;
    if (slot >= 0 && slot <= 8) {
        fn_80011BE4(slot);
    }
    memcpy(&inMemRoster[team][slot], &lbl_8034E9A0._0000[charID], sizeof(CharacterStats));
    if (handedness >= 0) {
        if (handedness == 0 || handedness == 1) {
            inMemRoster[team][slot].stats.FieldingArm = 0;
        } else {
            inMemRoster[team][slot].stats.FieldingArm = 1;
        }
        if (handedness == 0 || handedness == 2) {
            inMemRoster[team][slot].stats.BattingStance = 0;
        } else {
            inMemRoster[team][slot].stats.BattingStance = 1;
        }
    }
}

// .text:0x000B3FE8 size:0x13C mapped:0x806F307C
void fn_3_B3FE8(void) {
    int i;
    int j;

    fn_800B0A5C_insertQueue(possiblyTransitionBlackScreen, 2);
    fn_800B0A5C_insertQueue(fn_3_5BAC, 4);
    lbl_8036E548._307E = 0;
    g_Practice.practiceType = 0;
    g_Practice._1AB[0] = 0;
    g_Practice._1AB[1] = 0;
    g_Practice._1AB[2] = 0;
    g_Practice._1A6 = 0;
    g_Practice._1A8 = 0;
    g_Practice._1A9 = 0;
    g_Practice._19F = 0;
    g_Practice.aIEnabled = 0;
    g_Practice.practiceBatterHandedness = 0;
    g_Practice.freePracticeInd_writeOnly = 0;
    g_Practice._1A4 = 0;
    g_Practice.instructionNumber = -1;
    g_Practice.transitioningIndicator = 0;
    g_Practice.loadingGuidedPractice = 0;
    g_Practice._1D5 = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            g_Practice._1B2[i][j] = lbl_80354768._CF4E[i][j];
        }
    }
}

// .text:0x000B3CD4 size:0x314 mapped:0x806F2D68
BOOL fn_3_B3CD4(void) {
    int second = -1;
    int first = 0;

    if (g_Practice._1D9 == 0) {
        g_Practice._1D9 = 1;
        g_Practice.someCharID3 = -1;
        g_Practice.someCharID4 = -1;
        switch (g_Practice.practiceType_2) {
        case 0:
            break;
        case 1:
            second = 1;
            break;
        case 2:
            second = 1;
            break;
        case 3:
            return TRUE;
        case 4:
            first = g_Minigame._19E8[g_Practice.homeAway]._0;
            break;
        }
        if (first == 0) {
            first = -1;
        }
        if (second == 0) {
            second = -1;
        }
        if (first < 0) {
            first = second;
            second = -1;
        }
        if (first < 0) {
            return TRUE;
        }
        if (second >= 0 && lbl_800E8558[first * 6 + 2] == lbl_800E8558[second * 6 + 2]) {
            second = -1;
        }
        if (second < 0) {
            if ((g_Practice.someCharID1 >= 0 && lbl_800E8558[g_Practice.someCharID1 * 6 + 2] == lbl_800E8558[first * 6 + 2]) ||
                (g_Practice.someCharID2 >= 0 && lbl_800E8558[g_Practice.someCharID2 * 6 + 2] == lbl_800E8558[first * 6 + 2])) {
                return TRUE;
            }
            if (g_Practice.someCharID2 >= 0) {
                fn_3_90AB0(lbl_800E8558[g_Practice.someCharID2 * 6 + 1]);
                g_Practice.someCharID2 = lbl_800E8558[first * 6 + 1];
            } else if (g_Practice.someCharID1 < 0) {
                g_Practice.someCharID1 = lbl_800E8558[first * 6 + 1];
            } else {
                g_Practice.someCharID2 = lbl_800E8558[first * 6 + 1];
            }
            g_Practice.someCharID3 = lbl_800E8558[first * 6 + 1];
        } else if (g_Practice.someCharID1 >= 0) {
            if (lbl_800E8558[g_Practice.someCharID1 * 6 + 1] != lbl_800E8558[second * 6 + 1]) {
                if (lbl_800E8558[g_Practice.someCharID1 * 6 + 1] == lbl_800E8558[first * 6 + 1]) {
                    first = second;
                    goto replace_second;
                }
                fn_3_90AB0(lbl_800E8558[g_Practice.someCharID1 * 6 + 1]);
                fn_3_90AB0(lbl_800E8558[g_Practice.someCharID2 * 6 + 1]);
                g_Practice.someCharID3 = lbl_800E8558[first * 6 + 1];
                g_Practice.someCharID4 = lbl_800E8558[second * 6 + 1];
                g_Practice.someCharID1 = lbl_800E8558[first * 6 + 1];
                g_Practice.someCharID2 = lbl_800E8558[second * 6 + 1];
            } else {
            replace_second:
                if (lbl_800E8558[g_Practice.someCharID2 * 6 + 1] != lbl_800E8558[first * 6 + 1]) {
                    fn_3_90AB0(lbl_800E8558[g_Practice.someCharID2 * 6 + 1]);
                    g_Practice.someCharID3 = lbl_800E8558[first * 6 + 1];
                    g_Practice.someCharID2 = lbl_800E8558[first * 6 + 1];
                }
            }
        }
    }
    if (g_Practice.someCharID3 >= 0 && !fn_3_90B14(g_Practice.someCharID3, g_Practice.someCharID4)) {
        return FALSE;
    }
    return TRUE;
}

// .text:0x000B3CAC size:0x28 mapped:0x806F2D40
void fn_3_B3CAC(int mode) {
    g_GameLogic.secondaryGameMode = mode;
    g_Practice.totalFrames = 0;
    g_Practice.framesInCurrTransitionState = 0;
    g_Practice.practiceState = 0;
}

// .text:0x000B3C94 size:0x18 mapped:0x806F2D28
void fn_3_B3C94(int state) {
    g_Practice.practiceState = state;
    g_Practice.framesInCurrTransitionState = 0;
}

// .text:0x000B3C78 size:0x1C mapped:0x806F2D0C
void fn_3_B3C78(int state) {
    g_Practice.practiceState = 0;
    g_Practice.tutorialState = state;
    g_Practice.framesSincePracticeMenuDefaultTransition = 0;
}

// .text:0x000B3C64 size:0x14 mapped:0x806F2CF8
void fn_3_B3C64(void) {
    g_GameLogic.framesOfExitingToMenu = 1;
}

// .text:0x000B3BD0 size:0x94 mapped:0x806F2C64
void fn_3_B3BD0(void) {
    int i;

    for (i = 0; i < 4; i++) {
        InMemRunnerType* runner = &g_Runners[i];
        if (g_Practice._1AB[i] != 0) {
            if (g_GameLogic.secondaryGameMode == 14) {
                fn_3_6D964(i - 1, i);
            }
            runner->runnerOnFieldOrOutOrScored = 1;
        } else {
            runner->runnerOnFieldOrOutOrScored = 0;
            runner->rosterID = -1;
        }
    }
}

// .text:0x000B3B70 size:0x60 mapped:0x806F2C04
void fn_3_B3B70(void) {
    g_GameLogic.freeFieldingPracticeInd = 0;
    g_Practice.instructionNumber = -1;
    g_Practice.transitioningIndicator = 0;
    lbl_8036E548._307E = 1;
    lbl_8036E548._307A = 1;
    fn_3_6AEC0();
    fn_3_8F1C8();
    fn_3_59338();
}
