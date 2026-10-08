#include "game/rep_1BC8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/rep_1188.h"
#include "game/m_sound.h"
#include "game/rep_AC8.h"

extern struct {
    /* 0x0000 */ u8 _0000[0x307A];
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B[0x307E - 0x307B];
    /* 0x307E */ u8 _307E;
} lbl_8036E548;

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
    return;
}

// .text:0x000B4124 size:0x184 mapped:0x806F31B8
void fn_3_B4124(void) {
    return;
}

// .text:0x000B3FE8 size:0x13C mapped:0x806F307C
void fn_3_B3FE8(void) {
    return;
}

// .text:0x000B3CD4 size:0x314 mapped:0x806F2D68
void fn_3_B3CD4(void) {
    return;
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
