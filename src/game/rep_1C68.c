#include "game/rep_1C68.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/rep_D18.h"
#include "game/rep_1BC8.h"
#include "game/rep_1B20.h"
#include "game/rep_DB8.h"
#include "game/rep_1038.h"
#include "game/rep_13B8.h"
#include "game/rep_E08.h"
#include "game/rep_540.h"
#include "game/rep_1200.h"
#include "game/game_batter.h"
#include "game/rep_AC8.h"
#include "game/rep_CC8.h"
#include "game/rep_1188.h"
#include "game/rep_1B70.h"

extern void fn_3_1DD48(void);
extern void changeScene(u8, s16);
extern void fn_3_1E154(void);
extern int fn_3_6BA64(void);
extern u8 lbl_3_data_FAF4[4][4];
extern u8 lbl_3_data_FC08[4][4];
extern void* lbl_3_data_FC20[4];
extern void* lbl_3_data_10010[4];
extern BOOL fn_8001594C(int team);
extern u8 lbl_803CBC3C[];

extern struct {
    /* 0x0000 */ u8 _0000[0x2D77];
    /* 0x2D77 */ u8 _2D77;
    /* 0x2D78 */ u8 _2D78[0x2D7B - 0x2D78];
    /* 0x2D7B */ u8 _2D7B;
    /* 0x2D7C */ u8 _2D7C[0x307D - 0x2D7C];
    /* 0x307D */ u8 _307D;
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x9A];
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B;
    /* 0x9C */ u8 _9C;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x0000 */ u8 _0000[0xCF4E];
    /* 0xCF4E */ u8 _CF4E[4][4];
} lbl_80354768;


extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} g_RunningLogic;

// .text:0x000B77DC size:0x1D0 mapped:0x806F6870
void fn_3_B77DC(void) {
    switch (g_Practice.tutorialState) {
    case 0:
        fn_3_B7620();
        break;
    case 1:
        fn_3_B7184();
        break;
    case 2:
        if (fn_3_B254C() == 0) {
            fn_3_B7184();
        } else {
            fn_3_B1DA4(g_Practice.practiceLevel + 12, 0);
            fn_3_5A6D4(7);
        }
        break;
    case 3:
        fn_3_B7184();
        break;
    }
}

// .text:0x000B7794 size:0x48 mapped:0x806F6828
void fn_3_B7794(void) {
    g_Practice._1E8 = 1;
    g_Practice._1E9 = 1;
    g_Practice._1EA = 0;
    g_Practice._1EB = 0;
    g_Practice._1E7 = 0;
    fn_3_B3C78(0);
}

// .text:0x000B777C size:0x18 mapped:0x806F6810
void fn_3_B777C(u8 arg0) {
    g_Practice._1E5 = arg0;
    g_Practice.maybeCommandData[2] = 0;
}

// .text:0x000B7620 size:0x15C mapped:0x806F66B4
void fn_3_B7620(void) {
    switch (g_Practice.practiceState) {
    case 0:
        g_GameLogic.currentBatterPerTeam[0] = 1;
        g_GameLogic.currentBatterPerTeam[1] = 1;
        lbl_8036E548._307D = 0;
        g_Practice._1AB[0] = lbl_3_data_FC08[g_Practice.practiceLevel][0];
        g_Practice._1AB[1] = lbl_3_data_FC08[g_Practice.practiceLevel][1];
        g_Practice._1AB[2] = lbl_3_data_FC08[g_Practice.practiceLevel][2];
        g_Practice._1AB[3] = lbl_3_data_FC08[g_Practice.practiceLevel][3];
        fn_3_B3BD0();
        lbl_3_common_bss_32724._9A = 0;
        lbl_803CBC3C[2] = 0;
        g_Practice._1D9 = 0;
        fn_3_B3C94(1);
        break;
    case 1:
        if (fn_3_6BA64() != 0) {
            fn_3_B3C94(4);
        }
        break;
    case 4:
        if (fn_3_B3CD4() != 0) {
            fn_3_B3C94(7);
        }
        break;
    case 7:
        fn_3_B3B70();
        fn_3_B27A4();
        g_Practice.commandList = lbl_3_data_10010[g_Practice.practiceLevel];
        changeScene(1, 6);
        fn_3_5A6D4(7);
        fn_3_B3C78(1);
        break;
    }
}

// .text:0x000B7184 size:0x49C mapped:0x806F6218
void fn_3_B7184(void) {
    g_GameLogic.hudElementLoadingInd = 0;
    if (g_Ball.totalFramesAtPlay < 0x7FFE) {
        g_Ball.totalFramesAtPlay++;
    } else {
        g_Ball.totalFramesAtPlay = 0x7FFF;
    }
    if (g_Practice._1C7 != 0) {
        fn_3_B3620();
        return;
    }
    if (fn_3_B1CB0() != 0) {
        fn_3_8A958();
        return;
    }
    if (g_Practice.instructionNumber >= 0) {
        fn_3_B2630();
        if (g_Practice.readyToMoveToNextInstruction != 0) {
            return;
        }
        if (g_Practice.tutorialState == 2) {
            return;
        }
    } else if (fn_3_B707C() != 0) {
        return;
    }
    if (g_Practice.frames_sinceMovedToFromMenu < 0xFFFE) {
        g_Practice.frames_sinceMovedToFromMenu++;
    } else {
        g_Practice.frames_sinceMovedToFromMenu = 0xFFFF;
    }
    switch (g_GameLogic.gameStatus) {
    case 0:
        fn_3_B6E98();
        break;
    case 2:
        fn_3_B6D80();
        break;
    case 7:
        fn_3_B6F6C();
        break;
    }
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_Strikes.outs = 0;
}

// .text:0x000B707C size:0x108 mapped:0x806F6110
int fn_3_B707C(void) {
    if (g_Practice.pauseMenuLoading != 0) {
        return 0;
    }
    if (g_Practice.guidedPracticeCompletionRelated == 0) {
        return 0;
    }
    if (g_UnkSound_32718._07 != 0) {
        return 0;
    }
    if (++g_Practice._186 > 150) {
        if (g_Practice._1B2[g_Practice.practiceType_2][g_Practice.practiceLevel] == 0) {
            g_Practice._1B1 = 1;
            g_Practice._1B2[g_Practice.practiceType_2][g_Practice.practiceLevel] = 1;
            lbl_80354768._CF4E[g_Practice.practiceType_2][g_Practice.practiceLevel] = 1;
        }
        g_Practice._1C7 = 1;
        fn_3_B3A28();
        fn_3_B1DA4(g_Practice.practiceLevel + 12, 1);
        return 1;
    }
    return 0;
}

// .text:0x000B6F6C size:0x110 mapped:0x806F6000
void fn_3_B6F6C(void) {
    fn_3_8A4E4();
    fn_3_6C108();
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_GameLogic._125 = 1;
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    fn_3_B6E98();
    fn_3_6714C(0);
}

// .text:0x000B6E98 size:0xD4 mapped:0x806F5F2C
void fn_3_B6E98(void) {
    fn_3_5F720();
    g_Strikes.storedOuts = g_Strikes.outs;
    g_Strikes.runnerIndexForEachOutThisPitch[0] = -1;
    g_Strikes.runnerIndexForEachOutThisPitch[1] = -1;
    g_Strikes.runnerIndexForEachOutThisPitch[2] = -1;
    g_Strikes.GameControls_StrikeBallBitVector = g_Strikes.balls + g_Strikes.strikes * 16;
    g_Strikes.allForcedRunnersReachedTheirBaseInd = 0;
    g_Ball.totalFramesAtPlay = 0;
    g_FieldingLogic._10E = 0;
    g_FieldingLogic._0EE = 0;
    g_FieldingLogic._10F = 0;
    g_FieldingLogic._110 = 0;
    g_FieldingLogic._128 = 0;
    g_FieldingLogic._129 = 0;
    g_RunningLogic._13 = 0;
    g_GameLogic.pre_PostMiniGameInd = 0;
    g_GameLogic.minigameLastTurnSuccessInd = 0;
    g_Practice._1EC = 0;
    g_Practice._1ED = 0;
    changeScene(1, 6);
    fn_3_5A6D4(2);
    fn_3_6C0E0();
}

// .text:0x000B6D80 size:0x118 mapped:0x806F5E14
void fn_3_B6D80(void) {
    if (g_Practice.instructionNumber < 0 && fn_3_B32B8() != 0) {
        return;
    }
    fn_3_8A958();
    fn_3_B6C9C();
}

// .text:0x000B6C9C size:0xE4 mapped:0x806F5D30
void fn_3_B6C9C(void) {
    if (g_Practice.instructionNumber >= 0) {
        if (g_Practice.allowPlayToEndIndicator == 0) {
            g_FieldingLogic._0AE = 0;
            return;
        }
    } else {
        if (g_Runners[1].runnerOnFieldOrOutOrScored == 3) {
            g_Practice.guidedPracticeCompletionRelated = 1;
        }
        return;
    }
    if (g_FieldingLogic._0AE < 0x7FFE) {
        g_FieldingLogic._0AE++;
    } else {
        g_FieldingLogic._0AE = 0x7FFF;
    }
    if (g_FieldingLogic._0AE >= 60) {
        fn_3_B6C50();
    } else if (g_FieldingLogic._0AE == 54) {
        changeScene(3, 6);
    }
}

// .text:0x000B6C50 size:0x4C mapped:0x806F5CE4
void fn_3_B6C50(void) {
    g_Practice.allowPlayToEndIndicator = 0;
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    fn_3_1DD48();
    fn_3_5A6D4(7);
}

// .text:0x000B6BA4 size:0xAC mapped:0x806F5C38
void fn_3_B6BA4(void) {
    switch (g_Practice.tutorialState) {
    case 0:
        fn_3_B6994();
        break;
    case 1:
        fn_3_B6440();
        break;
    case 2:
        if (fn_3_B254C() == 0) {
            fn_3_B6440();
        } else {
            fn_3_B1DA4(g_Practice.practiceLevel, 0);
            fn_3_5A6D4(7);
        }
        break;
    case 3:
        fn_3_B6440();
        break;
    }
    g_GameLogic.TeamStars[1] = 5;
    g_GameLogic.TeamStars[0] = 5;
}

// .text:0x000B6B70 size:0x34 mapped:0x806F5C04
void fn_3_B6B70(void) {
    g_Practice._1DB = 0;
    fn_3_B3C78(0);
}

// .text:0x000B6994 size:0x1DC mapped:0x806F5A28
void fn_3_B6994(void) {
    switch (g_Practice.practiceState) {
    case 0:
        if (g_Practice.practiceType_2 == 4) {
            fn_3_B4124(0, 0, g_Minigame._19E8[g_Practice.homeAway]._0, g_Minigame.battingHandedness[g_Practice.homeAway]);
            fn_3_6EBB4(0);
            fn_3_6E24C(0, 0);
        } else {
            fn_3_6EBB4(0);
            fn_3_6E24C(0, 0);
        }
        g_GameLogic.currentBatterPerTeam[0] = 1;
        g_GameLogic.currentBatterPerTeam[1] = 1;
        lbl_8036E548._307D = 1;
        lbl_3_common_bss_32724._9C = 0;
        lbl_8036E548._2D77 = 0;
        lbl_8036E548._2D7B = 0;
        g_Practice._1D9 = 0;
        if (g_Practice.practiceType_2 == 4) {
            fn_3_B3C94(1);
        } else {
            fn_3_B3C94(2);
        }
        break;
    case 1:
        if (fn_8001594C(g_GameLogic.teamFielding) != 0) {
            fn_3_B3C94(2);
        }
        break;
    case 2:
        if (fn_3_750DC() != 0) {
            fn_3_B3C94(4);
        }
        break;
    case 4:
        if (fn_3_B3CD4() != 0) {
            fn_3_B3C94(7);
        }
        break;
    case 7:
        fn_3_B3B70();
        if (g_Practice.practiceType_2 == 4) {
            fn_3_B3A4C();
            fn_3_B3C78(3);
        } else {
            fn_3_B27A4();
            g_Practice.commandList = lbl_3_data_FC20[g_Practice.practiceLevel];
            fn_3_B3C78(1);
        }
        changeScene(1, 6);
        fn_3_5A6D4(7);
        break;
    }
}

// .text:0x000B6440 size:0x554 mapped:0x806F54D4
void fn_3_B6440(void) {
    g_GameLogic.hudElementLoadingInd = 0;
    if (g_Practice._1C7 != 0) {
        fn_3_B3620();
        return;
    }
    if (fn_3_B1CB0() != 0) {
        return;
    }
    if (g_Practice.instructionNumber >= 0) {
        fn_3_B2630();
        if (g_Practice.readyToMoveToNextInstruction != 0) {
            return;
        }
        if (g_Practice.tutorialState == 2) {
            return;
        }
    } else if (fn_3_B6320() != 0) {
        return;
    }
    if (g_Ball.totalFramesAtPlay < 0x7FFE) {
        g_Ball.totalFramesAtPlay++;
    } else {
        g_Ball.totalFramesAtPlay = 0x7FFF;
    }
    if (g_Practice.frames_sinceMovedToFromMenu < 0xFFFE) {
        g_Practice.frames_sinceMovedToFromMenu++;
    } else {
        g_Practice.frames_sinceMovedToFromMenu = 0xFFFF;
    }
    switch (g_GameLogic.gameStatus) {
    case 0:
        fn_3_B60F0();
        break;
    case 1:
        fn_3_B5F7C();
        break;
    case 7:
        fn_3_B61C0();
        break;
    }
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_Strikes.outs = 0;
}

// .text:0x000B6320 size:0x120 mapped:0x806F53B4
int fn_3_B6320(void) {
    if (g_Practice.pauseMenuLoading != 0) {
        return 0;
    }
    if (g_Practice.guidedPracticeCompletionRelated == 0) {
        return 0;
    }
    if (g_Pitcher.miniGameRelated == 0) {
        return 0;
    }
    if (g_UnkSound_32718._07 != 0) {
        return 0;
    }
    if (++g_Practice._186 > 90) {
        if (g_Practice._1B2[g_Practice.practiceType_2][g_Practice.practiceLevel] == 0) {
            g_Practice._1B1 = 1;
            g_Practice._1B2[g_Practice.practiceType_2][g_Practice.practiceLevel] = 1;
            lbl_80354768._CF4E[g_Practice.practiceType_2][g_Practice.practiceLevel] = 1;
        }
        g_Practice._1C7 = 1;
        fn_3_B3A28();
        fn_3_B1DA4(g_Practice.practiceLevel, 1);
        return 1;
    }
    return 0;
}

// .text:0x000B61C0 size:0x160 mapped:0x806F5254
void fn_3_B61C0(void) {
    fn_3_F578();
    fn_3_753E8(0);
    setBatterContactConstants();
    fn_3_8A350();
    fn_3_8A1D8();
    fn_3_58E50();
    fn_3_58870();
    fn_3_1E154();
    fn_3_59A90();
    fn_3_6C108();
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_GameLogic._125 = 1;
    if (g_GameLogic.pre_PostMiniGameInd != 0) {
        g_GameLogic.minigameLastTurnSuccessInd = 1;
        g_GameLogic.hudElementLoadingInd = 1;
    } else {
        g_GameLogic.minigameLastTurnSuccessInd = 0;
    }
    g_GameLogic.pre_PostMiniGameInd = 0;
    g_GameLogic.minigameLastTurnSuccessInd = 0;
    fn_3_B60F0();
    fn_3_6714C(0);
}

// .text:0x000B60F0 size:0xD0 mapped:0x806F5184
void fn_3_B60F0(void) {
    fn_3_5F720();
    g_Strikes.storedOuts = g_Strikes.outs;
    g_Strikes.runnerIndexForEachOutThisPitch[0] = -1;
    g_Strikes.runnerIndexForEachOutThisPitch[1] = -1;
    g_Strikes.runnerIndexForEachOutThisPitch[2] = -1;
    g_Strikes.GameControls_StrikeBallBitVector = g_Strikes.balls + g_Strikes.strikes * 16;
    g_Strikes.allForcedRunnersReachedTheirBaseInd = 0;
    g_Ball.totalFramesAtPlay = 0;
    g_FieldingLogic._10E = 0;
    g_FieldingLogic._0EE = 0;
    g_FieldingLogic._10F = 0;
    g_FieldingLogic._110 = 0;
    g_FieldingLogic._128 = 0;
    g_FieldingLogic._129 = 0;
    g_RunningLogic._13 = 0;
    g_GameLogic.pre_PostMiniGameInd = 0;
    g_GameLogic.minigameLastTurnSuccessInd = 0;
    g_Practice.guidedPracticeCompletionRelated2 = 0;
    changeScene(1, 6);
    fn_3_5A6D4(1);
    fn_3_6C0E0();
}

// .text:0x000B5F7C size:0x174 mapped:0x806F5010
void fn_3_B5F7C(void) {
    if (g_Practice.instructionNumber < 0 && fn_3_B32B8() != 0) {
        return;
    }
    fn_3_75560();
    if (g_Practice._1DB != 0) {
        atBat_batter();
        fn_3_8A958();
    }
    fn_3_31594();
    if (g_Practice.instructionNumber < 0 && g_Practice.guidedPracticeCompletionRelated2 == 0) {
        fn_3_B5E7C();
    }
}

// .text:0x000B5E7C size:0x100 mapped:0x806F4F10
void fn_3_B5E7C(void) {
    if (g_Practice.practiceType_2 == 4) {
        return;
    }
    if (g_Pitcher.pitcherActionState != 4) {
        return;
    }
    switch (g_Practice.practiceLevel) {
    case 0:
        g_Practice.guidedPracticeCounter++;
        break;
    case 1:
        if (g_Pitcher.ChargePitchType >= 2) {
            g_Practice.guidedPracticeCounter++;
        }
        break;
    case 2:
        if (g_Pitcher.TypeOfPitch == 2) {
            g_Practice.guidedPracticeCounter++;
        }
        break;
    case 3:
        if (g_Pitcher.starPitchType != 0) {
            g_Practice.guidedPracticeCounter++;
        }
        break;
    }
    if (g_Practice.guidedPracticeCounter >= lbl_3_data_FAF4[g_Practice.practiceType_2][g_Practice.practiceLevel]) {
        g_Practice.guidedPracticeCompletionRelated = 1;
    }
    g_Practice.guidedPracticeCompletionRelated2 = 1;
}
