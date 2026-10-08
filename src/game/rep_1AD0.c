#include "game/rep_1AD0.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/rep_1BC8.h"
#include "game/rep_D18.h"
#include "game/rep_1200.h"
#include "game/game_batter.h"
#include "game/rep_13B8.h"
#include "game/rep_AC8.h"
#include "game/rep_DB8.h"
#include "game/rep_1038.h"
#include "game/rep_540.h"
#include "game/rep_CC8.h"
#include "game/rep_E08.h"
#include "game/rep_1838.h"
#include "game/rep_1188.h"
#include "game/rep_1B70.h"

typedef struct Fielder1AD0 {
    /* 0x000 */ Vec _000;
    /* 0x00C */ u8 _00C[0x1C7 - 0xC];
    /* 0x1C7 */ u8 _1C7;
    /* 0x1C8 */ u8 _1C8[0x268 - 0x1C8];
} Fielder1AD0; // size: 0x268

extern Fielder1AD0 g_Fielders[9];

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} g_RunningLogic;

extern struct {
    /* 0x0000 */ u8 _0000[0x307D];
    /* 0x307D */ u8 _307D;
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x9A];
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B;
    /* 0x9C */ u8 _9C;
} lbl_3_common_bss_32724;

extern u8 lbl_803CBC3C[];

extern u8 lbl_3_data_FAF4[4][4];
extern s16 lbl_3_data_FB04;
extern s16 lbl_3_data_FB08[10][3];
extern s16 lbl_3_data_FB44[10][3];
extern s16 lbl_3_data_FB80[10][3];
extern s16 lbl_3_data_FBBC[10][3];
extern s16 lbl_3_data_FBF8[8];
extern s16 lbl_3_data_FC1C[2];
extern void* lbl_3_data_FDE4[];
extern void* lbl_3_data_101E0[];

extern struct {
    /* 0x0000 */ u8 _0000[0xCF4E];
    /* 0xCF4E */ u8 _CF4E[4][4];
} lbl_80354768;

extern void fn_3_1DD48(void);
extern int fn_3_B1CB0(void);
extern void fn_3_B1DA4(int, int);
extern int fn_3_B254C(void);
extern void fn_3_B2630(void);
extern int fn_3_B32B8(void);
extern void fn_3_B3620(void);
extern void fn_3_B3A28(void);
extern void fn_3_B27A4(void);
extern int fn_3_6BA64(void);
extern void fn_80011BE4(int arg);
extern void fn_3_1E154(void);
extern void changeScene(u8, s16);

// .text:0x000B1C14 size:0x9C mapped:0x806F0CA8
void fn_3_B1C14(void) {
    return;
}

// .text:0x000B1BCC size:0x48 mapped:0x806F0C60
void fn_3_B1BCC(void) {
    g_Practice._1DD = 0;
    g_Practice._1DE = 0;
    g_Practice._1DF = 0;
    g_Practice._1E0 = 0;
    g_Practice._1E2 = 0;
    g_Practice.maybeCommandData[0] = 0;
    fn_3_B3C78(0);
}

// .text:0x000B1A30 size:0x19C mapped:0x806F0AC4
void fn_3_B1A30(void) {
    int i;

    switch (g_Practice.practiceState) {
    case 0:
        lbl_8036E548._307D = 0;
        fn_3_6EBB4(0);
        fn_3_8A350();
        for (i = 0; i < 9; i++) {
            fn_3_6E24C(i, i);
        }
        setInMemBatterConstants(0);
        fn_3_6D964(0, 0);
        g_GameLogic.currentBatterPerTeam[0] = 1;
        g_GameLogic.currentBatterPerTeam[1] = 1;
        lbl_3_common_bss_32724._9A = 0;
        lbl_3_common_bss_32724._9C = 0;
        lbl_803CBC3C[2] = 0;
        g_Practice.aIEnabled = 1;
        g_Practice.practiceBatterHandedness = 1;
        g_Practice._1D9 = 0;
        fn_80011BE4(9);
        fn_3_B3C94(1);
        break;
    case 1:
        if (fn_3_6BA64()) {
            fn_3_B3C94(2);
        }
        break;
    case 2:
        if (fn_3_750DC()) {
            fn_3_B3C94(3);
        }
        break;
    case 3:
        if (someAnimationIndFunction()) {
            fn_3_B3C94(4);
        }
        break;
    case 4:
        if (fn_3_B3CD4()) {
            fn_3_B3C94(7);
        }
        break;
    case 7:
        fn_3_B3B70();
        fn_3_B27A4();
        g_Practice.commandList = lbl_3_data_101E0[g_Practice.practiceLevel];
        changeScene(1, 6);
        fn_3_5A6D4(7);
        fn_3_B3C78(1);
        break;
    }
}

// .text:0x000B1578 size:0x4B8 mapped:0x806F060C
void fn_3_B1578(void) {
    return;
}

// .text:0x000B1470 size:0x108 mapped:0x806F0504
BOOL fn_3_B1470(void) {
    if (g_Practice.pauseMenuLoading != 0) {
        return FALSE;
    }
    if (g_Practice.guidedPracticeCompletionRelated == 0) {
        return FALSE;
    }
    if (g_UnkSound_32718._07 != 0) {
        return FALSE;
    }
    if (++g_Practice._186 > 150) {
        if (g_Practice._1B2[g_Practice.practiceType_2][g_Practice.practiceLevel] == 0) {
            g_Practice._1B1 = 1;
            g_Practice._1B2[g_Practice.practiceType_2][g_Practice.practiceLevel] = 1;
            lbl_80354768._CF4E[g_Practice.practiceType_2][g_Practice.practiceLevel] = 1;
        }
        g_Practice._1C7 = 1;
        fn_3_B3A28();
        fn_3_B1DA4(g_Practice.practiceLevel + 8, 1);
        return TRUE;
    }
    return FALSE;
}

// .text:0x000B12F8 size:0x178 mapped:0x806F038C
void fn_3_B12F8(void) {
    fn_3_F578();
    fn_3_753E8(FALSE);
    setBatterContactConstants();
    fn_3_8A1D8();
    fn_3_58E50();
    fn_3_1E154();
    fn_3_59A90();
    fn_3_6C108();
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_GameLogic._125 = 1;
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    fn_3_B11D0();
    fn_3_6714C(FALSE);
}

// .text:0x000B11D0 size:0x128 mapped:0x806F0264
void fn_3_B11D0(void) {
    fn_3_5F720();
    fn_3_B0D7C();
    g_Strikes.storedOuts = g_Strikes.outs;
    g_Strikes.runnerIndexForEachOutThisPitch[0] = -1;
    g_Strikes.runnerIndexForEachOutThisPitch[1] = -1;
    g_Strikes.runnerIndexForEachOutThisPitch[2] = -1;
    g_Strikes.GameControls_StrikeBallBitVector = g_Strikes.balls + (g_Strikes.strikes * 16);
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
    g_Practice.hitVariablesSetIndicator = 0;
    g_Practice._1E4 = 0;
    g_Practice._1CB = 0;
    g_Strikes.outs = 0;
    g_Practice._152 = 0;
    changeScene(1, 6);
    fn_3_5A6D4(1);
    fn_3_6C0E0();
}

// .text:0x000B116C size:0x64 mapped:0x806F0200
void fn_3_B116C(void) {
    if (g_Practice.instructionNumber >= 0 || !fn_3_B32B8()) {
        if (g_Practice.hitVariablesSetIndicator == 0) {
            fn_3_B0B5C();
        }
        fn_3_75560();
        atBat_batter();
        fn_3_8A958();
        fn_3_31594();
    }
}

// .text:0x000B1120 size:0x4C mapped:0x806F01B4
void fn_3_B1120(void) {
    return;
}

// .text:0x000B0E00 size:0x320 mapped:0x806EFE94
void fn_3_B0E00(void) {
    return;
}

// .text:0x000B0DB0 size:0x50 mapped:0x806EFE44
void fn_3_B0DB0(void) {
    g_Practice.allowPlayToEndIndicator = 0;
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    g_GameLogic.hudLoadingRelated = 1;
    fn_3_1DD48();
    fn_3_5A6D4(7);
}

// .text:0x000B0D7C size:0x34 mapped:0x806EFE10
void fn_3_B0D7C(void) {
    g_Pitcher.handedness = g_Fielders[0]._1C7;
    g_Pitcher.curveBallSpeed = 125;
    g_Pitcher.fastBallSpeed = 145;
    g_Pitcher.cursedBallStat = 100;
}

// .text:0x000B0D78 size:0x4 mapped:0x806EFE0C
void fn_3_B0D78(void) {
    return;
}

// .text:0x000B0D2C size:0x4C mapped:0x806EFDC0
void fn_3_B0D2C(void) {
    if (g_Practice.aiBuntIndicator == 0 && g_Pitcher.framesUntilUnhittable + 1 == swingSoundFrame[0][1]) {
        g_AiLogic.batterAISwingInd = 1;
    }
}

// .text:0x000B0CF4 size:0x38 mapped:0x806EFD88
BOOL fn_3_B0CF4(void) {
    if (g_Practice.aiBuntIndicator == 0) {
        return FALSE;
    }
    return g_Ball.pitchHangtimeCounter > 0;
}

// .text:0x000B0B5C size:0x198 mapped:0x806EFBF0
void fn_3_B0B5C(void) {
    int i;

    if (g_Practice.hitVariablesSetIndicator == 0 && ++g_Practice._152 >= lbl_3_data_FBF8[0]) {
        if (g_Practice.practiceLevel == 0) {
            i = random_fn_3_9EE24(10);
            g_Ball.Hit_HorizontalPower = lbl_3_data_FB08[i][0];
            g_Ball.Hit_VerticalAngle = lbl_3_data_FB08[i][1];
            g_Ball.Hit_HorizontalAngle = lbl_3_data_FB08[i][2];
        } else if (g_Practice.practiceLevel == 1) {
            i = random_fn_3_9EE24(10);
            g_Ball.Hit_HorizontalPower = lbl_3_data_FB44[i][0];
            g_Ball.Hit_VerticalAngle = lbl_3_data_FB44[i][1];
            g_Ball.Hit_HorizontalAngle = lbl_3_data_FB44[i][2];
        } else if (g_Practice.practiceLevel == 2) {
            i = random_fn_3_9EE24(10);
            g_Ball.Hit_HorizontalPower = lbl_3_data_FB80[i][0];
            g_Ball.Hit_VerticalAngle = lbl_3_data_FB80[i][1];
            g_Ball.Hit_HorizontalAngle = lbl_3_data_FB80[i][2];
        } else if (g_Practice.practiceLevel == 3) {
            i = random_fn_3_9EE24(10);
            g_Ball.Hit_HorizontalPower = lbl_3_data_FBBC[i][0];
            g_Ball.Hit_VerticalAngle = lbl_3_data_FBBC[i][1];
            g_Ball.Hit_HorizontalAngle = lbl_3_data_FBBC[i][2];
        }
        g_Practice.hitVariablesSetIndicator = 1;
        if (g_Practice.maybeCommandData[0] < 0x7FFE) {
            g_Practice.maybeCommandData[0]++;
        } else {
            g_Practice.maybeCommandData[0] = 0x7FFF;
        }
    }
}

// .text:0x000B0AAC size:0xB0 mapped:0x806EFB40
void fn_3_B0AAC(void) {
    switch (g_Practice.tutorialState) {
    case 0:
        fn_3_B0874();
        break;
    case 1:
        fn_3_B056C();
        break;
    case 2:
        if (!fn_3_B254C()) {
            fn_3_B056C();
        } else {
            fn_3_B1DA4(g_Practice.practiceLevel + 4, 0);
            fn_3_5A6D4(7);
        }
        break;
    case 3:
        fn_3_B056C();
        break;
    }
    g_GameLogic.TeamStars[1] = 5;
    g_GameLogic.TeamStars[0] = 5;
}

// .text:0x000B0A88 size:0x24 mapped:0x806EFB1C
void fn_3_B0A88(void) {
    fn_3_B3C78(0);
}

// .text:0x000B0874 size:0x214 mapped:0x806EF908
void fn_3_B0874(void) {
    switch (g_Practice.practiceState) {
    case 0:
        lbl_8036E548._307D = 0;
        fn_3_8A350();
        if (g_Practice.practiceType_2 == 4) {
            fn_3_B4124(1, 0, g_Minigame._19E8[g_Practice.homeAway]._0, g_Minigame.battingHandedness[g_Practice.homeAway]);
            setInMemBatterConstants(0);
            fn_3_6D964(0, 0);
        } else {
            fn_3_6EBB4(0);
            fn_3_6E24C(0, 0);
            setInMemBatterConstants(0);
            fn_3_6D964(0, 0);
        }
        g_GameLogic.currentBatterPerTeam[0] = 1;
        g_GameLogic.currentBatterPerTeam[1] = 1;
        lbl_3_common_bss_32724._9A = 0;
        lbl_3_common_bss_32724._9C = 0;
        lbl_803CBC3C[2] = 0;
        g_Practice._1D9 = 0;
        fn_80011BE4(9);
        fn_3_B3C94(1);
        break;
    case 1:
        if (fn_3_6BA64()) {
            fn_3_B3C94(2);
        }
        break;
    case 2:
        if (g_Practice.practiceType_2 == 4) {
            fn_3_B3C94(3);
        } else if (fn_3_750DC()) {
            fn_3_B3C94(3);
        }
        break;
    case 3:
        if (someAnimationIndFunction()) {
            fn_3_B3C94(4);
        }
        break;
    case 4:
        if (fn_3_B3CD4()) {
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
            g_Practice.commandList = lbl_3_data_FDE4[g_Practice.practiceLevel];
            fn_3_B3C78(1);
        }
        changeScene(1, 6);
        fn_3_5A6D4(7);
        break;
    }
}

// .text:0x000B056C size:0x308 mapped:0x806EF600
void fn_3_B056C(void) {
    g_GameLogic.hudElementLoadingInd = 0;
    if (g_Practice._1C7 != 0) {
        fn_3_B3620();
        return;
    }
    if (fn_3_B1CB0()) {
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
    } else if (fn_3_B0464()) {
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
        fn_3_B02A8();
        break;
    case 1:
        fn_3_B025C();
        break;
    case 2:
        fn_3_B01E0();
        break;
    case 7:
        fn_3_B03F0();
        break;
    }
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_Strikes.outs = 0;
}

// .text:0x000B0464 size:0x108 mapped:0x806EF4F8
BOOL fn_3_B0464(void) {
    if (g_Practice.pauseMenuLoading != 0) {
        return FALSE;
    }
    if (g_Practice.guidedPracticeCompletionRelated == 0) {
        return FALSE;
    }
    if (g_UnkSound_32718._07 != 0) {
        return FALSE;
    }
    if (++g_Practice._186 > 150) {
        if (g_Practice._1B2[g_Practice.practiceType_2][g_Practice.practiceLevel] == 0) {
            g_Practice._1B1 = 1;
            g_Practice._1B2[g_Practice.practiceType_2][g_Practice.practiceLevel] = 1;
            lbl_80354768._CF4E[g_Practice.practiceType_2][g_Practice.practiceLevel] = 1;
        }
        g_Practice._1C7 = 1;
        fn_3_B3A28();
        fn_3_B1DA4(g_Practice.practiceLevel + 4, 1);
        return TRUE;
    }
    return FALSE;
}

// .text:0x000B03F0 size:0x74 mapped:0x806EF484
void fn_3_B03F0(void) {
    fn_3_F578();
    fn_3_753E8(FALSE);
    setBatterContactConstants();
    fn_3_8A1D8();
    fn_3_58E50();
    fn_3_1E154();
    fn_3_59A90();
    fn_3_6C108();
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_GameLogic._125 = 1;
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    fn_3_B02A8();
    fn_3_6714C(FALSE);
}

// .text:0x000B02A8 size:0x148 mapped:0x806EF33C
void fn_3_B02A8(void) {
    fn_3_5F720();
    if (g_Practice.practiceLevel == 4) {
        g_Pitcher.windupCountdownUntilBallReleased = lbl_3_data_FC1C[1];
    }
    g_Strikes.storedOuts = g_Strikes.outs;
    g_Strikes.runnerIndexForEachOutThisPitch[0] = -1;
    g_Strikes.runnerIndexForEachOutThisPitch[1] = -1;
    g_Strikes.runnerIndexForEachOutThisPitch[2] = -1;
    g_Strikes.GameControls_StrikeBallBitVector = g_Strikes.balls + (g_Strikes.strikes * 16);
    g_Strikes.allForcedRunnersReachedTheirBaseInd = 0;
    g_Ball.totalFramesAtPlay = 0;
    g_FieldingLogic._10E = 0;
    g_FieldingLogic._0EE = 0;
    g_FieldingLogic._10F = 0;
    g_FieldingLogic._110 = 0;
    g_FieldingLogic._128 = 0;
    g_FieldingLogic._129 = 0;
    g_RunningLogic._13 = 0;
    if (g_GameLogic.pre_PostMiniGameInd != 0) {
        g_GameLogic.minigameLastTurnSuccessInd = 1;
        g_GameLogic.hudElementLoadingInd = 1;
    } else {
        g_GameLogic.minigameLastTurnSuccessInd = 0;
    }
    g_GameLogic.pre_PostMiniGameInd = 0;
    g_GameLogic.minigameLastTurnSuccessInd = 0;
    g_Practice.guidedPracticeCompletionRelated2 = 0;
    g_Practice._1B0 = 0;
    changeScene(1, 6);
    fn_3_5A6D4(1);
    fn_3_6C0E0();
    if (lbl_3_common_bss_34C58._2A != 0) {
        lbl_3_common_bss_34C58._2A = 2;
        lbl_3_common_bss_34C58._24 = 120;
    }
}

// .text:0x000B025C size:0x4C mapped:0x806EF2F0
void fn_3_B025C(void) {
    if (g_Practice.instructionNumber >= 0 || !fn_3_B32B8()) {
        fn_3_75560();
        atBat_batter();
        fn_3_8A958();
        fn_3_31594();
    }
}

// .text:0x000B01E0 size:0x7C mapped:0x806EF274
void fn_3_B01E0(void) {
    ballPhysica();
    fn_3_598D0();
    if (g_Ball.framesSinceHit == 60) {
        g_Fielders[0]._000.x = g_Pitcher.pitcherCoord.x;
        g_Fielders[0]._000.z = g_Pitcher.pitcherCoord.z;
    }
    fn_3_AFE0C();
    if (g_Practice.instructionNumber < 0 && g_Practice.guidedPracticeCompletionRelated2 == 0) {
        fn_3_B003C();
    }
}

// .text:0x000B003C size:0x1A4 mapped:0x806EF0D0
void fn_3_B003C(void) {
    if (g_Practice.practiceType_2 == 4) {
        return;
    }
    if (g_Practice.guidedPracticeCompletionRelated2 != 0) {
        return;
    }
    if (g_Ball.deadBallReason != 0) {
        if (g_Ball.framesOnGroundUntilPickedUp == 0 && g_Practice._1B0 == 0 &&
            g_Ball.matchFramesAndBallAngle.ballOverWallFrames < lbl_3_data_FB04) {
            return;
        }
    } else if (g_Ball.framesSinceBallHitGroundOrWasCaught < lbl_3_data_FB04) {
        return;
    }
    switch (g_Practice.practiceLevel) {
    case 0:
        if (g_Batter.hitGeneralType != 3) {
            g_Practice.guidedPracticeCounter++;
        }
        break;
    case 1:
        if (g_Batter.hitGeneralType == 1 || (g_Batter.hitGeneralType == 2 && g_Batter.moonShotInd != 0)) {
            g_Practice.guidedPracticeCounter++;
        }
        break;
    case 2:
        if (g_Batter.hitGeneralType == 3) {
            g_Practice.guidedPracticeCounter++;
        }
        break;
    case 3:
        if (g_Batter.hitGeneralType == 2 && g_Batter.moonShotInd == 0) {
            g_Practice.guidedPracticeCounter++;
        }
        break;
    }
    if (g_Practice.guidedPracticeCounter >= lbl_3_data_FAF4[g_Practice.practiceType_2][g_Practice.practiceLevel]) {
        g_Practice.guidedPracticeCompletionRelated = 1;
    }
    g_Practice.guidedPracticeCompletionRelated2 = 1;
}

// .text:0x000AFE0C size:0x230 mapped:0x806EEEA0
void fn_3_AFE0C(void) {
    s16 endFrame = 120;
    InputStruct* input = &g_Controls[g_Practice.homeAway];

    if (g_Practice.instructionNumber >= 0) {
        if (g_Practice.allowPlayToEndIndicator != 0) {
            endFrame = 60;
        } else {
            g_FieldingLogic._0AE = 0;
            return;
        }
    } else if (g_Ball.AtBat_ContactResult == 0) {
        g_FieldingLogic._0AE = 0;
        return;
    } else if (g_Practice.guidedPracticeCompletionRelated != 0) {
        g_FieldingLogic._0AE = 0;
        return;
    } else if (g_Ball.deadBallReason == 1) {
        if (g_Practice._1B0 == 0) {
            if (input->newButtonInput & 0x1100) {
                g_Practice._1B0 = 1;
            }
            endFrame = 300;
        } else {
            endFrame = 45;
        }
        lbl_3_common_bss_34C58._2A = 1;
        lbl_3_common_bss_34C58._24 = 30;
    } else if (g_Ball.framesSinceHit > 180) {
        endFrame = 120;
    }
    if (g_FieldingLogic._0AE < 0x7FFE) {
        g_FieldingLogic._0AE++;
    } else {
        g_FieldingLogic._0AE = 0x7FFF;
    }
    if (g_GameLogic.framePlayEnd > endFrame && g_FieldingLogic._0AE > endFrame - 90) {
        g_FieldingLogic._0AE = 0;
        g_FieldingLogic._0EE = 0;
    }
    if (g_FieldingLogic._0AE >= endFrame) {
        fn_3_AFDC0();
    } else if (g_FieldingLogic._0AE >= endFrame - 6) {
        changeScene(3, 6);
    } else if (g_FieldingLogic._0AE == endFrame - 30) {
        g_FieldingLogic._10E = 1;
        g_FieldingLogic._0EE = 1;
    }
    g_GameLogic.framePlayEnd = endFrame;
    g_GameLogic.CountdownUntilFade = endFrame - g_FieldingLogic._0AE;
}

// .text:0x000AFDC0 size:0x4C mapped:0x806EEE54
void fn_3_AFDC0(void) {
    g_Practice.allowPlayToEndIndicator = 0;
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    fn_3_1DD48();
    fn_3_5A6D4(7);
}
