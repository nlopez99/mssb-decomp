#include "game/rep_3A98.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/rep_1200.h"
#include "game/rep_D18.h"
#include "game/rep_DB8.h"
#include "game/rep_13B8.h"
#include "game/rep_540.h"
#include "game/rep_AC8.h"

// .data of rep_1B20
extern s16 lbl_3_data_FC1C;

// .text outside every unit
extern void fn_3_6B870(void);

// .text:0x0015B610 size:0x18C mapped:0x8079A6A4
void fn_3_15B610(void) {
    switch (g_Practice.tutorialState) {
    case 0:
        fn_3_15B494();
        break;
    case 3:
        fn_3_15AF78();
        break;
    }
}

// .text:0x0015B494 size:0x17C mapped:0x8079A528
void fn_3_15B494(void) {
    return;
}

// .text:0x0015B204 size:0x290 mapped:0x8079A298
void fn_3_15B204(void) {
    return;
}

// .text:0x0015B0D8 size:0x12C mapped:0x8079A16C
void fn_3_15B0D8(void) {
    int i;

    for (i = 0; i < 2; i++) {
        g_GameLogic._13E[i] = 0;
        g_GameLogic._140[i] = 0;
        g_GameLogic.teamAIInd[i] = 0;
        g_GameLogic.autoFielding[i] = 0;
        g_GameLogic.batterHandedness[i] = 0;
        g_GameLogic.battingAIInd[i] = 0;
    }
    g_Practice.aIEnabled = 0;
    g_Practice.practiceBatterHandedness = 0;
    g_Practice.freePracticeInd_writeOnly = 0;
    g_Practice._1A4 = 0;
    if (g_GameLogic.secondaryGameMode == 15) {
        g_Practice.aIEnabled = 1;
        g_GameLogic._13E[g_GameLogic.teamFielding] = 1;
        g_Practice.freePracticeInd_writeOnly = 1;
        g_GameLogic._140[g_GameLogic.awayTeamBattingInd_battingTeam] = 1;
        g_Practice.rosterID = 1;
        g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam] = 1;
        g_GameLogic.autoFielding[g_GameLogic.awayTeamBattingInd_battingTeam] = 1;
    } else {
        g_Practice.practiceBatterHandedness = 1;
        g_GameLogic._13E[g_GameLogic.teamBatting] = 1;
        g_Practice._1A4 = 1;
        g_GameLogic.batterHandedness[g_GameLogic.homeTeamBattingInd_fieldingTeam] = 1;
        g_GameLogic.battingAIInd[g_GameLogic.homeTeamBattingInd_fieldingTeam] = 1;
    }
    g_Practice._186 = 0;
    fn_3_5A684();
    fn_3_8A350();
    fn_3_F7B8();
    fn_3_75434();
    fn_3_59338();
    g_GameLogic.EventTriggers_GameHasStarted = 0;
    g_GameLogic.currentBatterPerTeam[0] = 1;
    g_GameLogic.currentBatterPerTeam[1] = 1;
}

// .text:0x0015AF78 size:0x160 mapped:0x8079A00C
void fn_3_15AF78(void) {
    g_GameLogic.hudElementLoadingInd = 0;
    g_GameLogic.hudLoadingRelated = 0;
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
        fn_3_5F154();
        break;
    case 1:
        fn_3_5EFEC();
        break;
    case 2:
        fn_3_5EDD8();
        break;
    case 7:
        fn_3_5F3FC();
        if (g_GameLogic.FrameCountOfCurrentPitch == 1) {
            fn_3_15AE34();
        }
        break;
    case 8:
        fn_3_15ADD4();
        break;
    case 10:
        fn_3_5CD24();
        break;
    }
    if (g_Practice.practiceLevel != 7 && g_Practice.practiceLevel != 6) {
        g_Strikes.outs = 0;
    }
}

// .text:0x0015AE34 size:0x144 mapped:0x80799EC8
void fn_3_15AE34(void) {
    int rosterIDs[4];
    int i;
    int j;

    if (g_GameLogic.secondaryGameMode == 15) {
        for (i = 0; i < 4; i++) {
            rosterIDs[i] = i + 1;
        }
        for (i = 0; i < 4; i++) {
            for (j = 1; j < 4; j++) {
                if (g_Runners[j].rosterID == rosterIDs[i]) {
                    rosterIDs[i] = -1;
                }
            }
        }
        for (i = 0; i < 4; i++) {
            if (rosterIDs[i] >= 0) {
                g_Practice.rosterID = rosterIDs[i];
                break;
            }
        }
    }
    if (g_GameLogic.TeamStars[0] == 0) {
        g_GameLogic.TeamStars[0] = 5;
    }
    if (g_GameLogic.TeamStars[1] == 0) {
        g_GameLogic.TeamStars[1] = 5;
    }
    if (g_Strikes.outs >= 3) {
        g_Strikes.outs = 0;
    }
    g_Practice.guidedPracticeCompletionRelated = 0;
}

// .text:0x0015ADD4 size:0x60 mapped:0x80799E68
void fn_3_15ADD4(void) {
    fn_3_6B870();
    g_GameLogic._135 = 0;
    g_GameLogic._136 = 0;
    if (g_GameLogic.secondaryGameMode == 15 && g_Strikes.outs >= 3) {
        g_Strikes.outs = 0;
    }
    fn_3_5A6D4(7);
}

// .text:0x0015AD94 size:0x40 mapped:0x80799E28
void fn_3_15AD94(void) {
    if (g_Pitcher.currentStateFrameCounter > lbl_3_data_FC1C) {
        fn_3_750C4(2);
    }
}
