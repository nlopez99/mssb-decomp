#include "game/rep_1BC8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/rep_1188.h"
#include "game/m_sound.h"
#include "game/rep_AC8.h"
#include "game/rep_1C0.h"
#include "string.h"

extern struct {
    /* 0x0000 */ u8 _0000[0x307A];
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

extern void possiblyTransitionBlackScreen(void);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void fn_80011BE4(int arg);

// .text outside every unit
extern void fn_3_6AEC0(void);

// .text:0x000B482C size:0x1A8 mapped:0x806F38C0
void fn_3_B482C(void) {
    return;
}

// .text:0x000B43E8 size:0x444 mapped:0x806F347C
void fn_3_B43E8(void) {
    return;
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
    return FALSE;
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
