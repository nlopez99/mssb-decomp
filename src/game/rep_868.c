#include "game/rep_868.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"
#include "game/rep_8C8.h"
#include "game/rep_940.h"

typedef struct {
    /* 0x000 */ u8 _000[0x1C4];
    /* 0x1C4 */ u8 _1C4;
    /* 0x1C5 */ u8 _1C5[0x268 - 0x1C5];
} Unk868Fielder; // size: 0x268

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ u8 _50[0xAC - 0x50];
    /* 0xAC */ u8 _AC;
    /* 0xAD */ u8 _AD;
} g_Scores;

extern struct {
    /* 0x00 */ s16 _00;
    /* 0x02 */ s16 _02;
} g_RunningLogic;

extern Unk868Fielder g_Fielders[9];

extern struct {
    /* 0x000 */ u8 _000[0x168];
    /* 0x168 */ s16 _168[2][10][2];
    /* 0x1B8 */ u8 _1B8[0x202 - 0x1B8];
    /* 0x202 */ u8 _202[2];
    /* 0x204 */ u8 _204[0x20A - 0x204];
    /* 0x20A */ u8 _20A[2][9];
    /* 0x21C */ u8 _21C[2];
} lbl_3_common_bss_34C90;

extern s8 lbl_80354720[2][9][4];

// .data outside this unit's split
extern u8 lbl_3_data_1C30[8];

// .text:0x0001E328 size:0xC4 mapped:0x8065D3BC
void fn_3_1E328(void) {
    g_AiLogic._46 = g_GameLogic.AIDifficulty0Special3Weak[0] * 255 / 4;
    g_AiLogic._47 = g_GameLogic.AIDifficulty0Special3Weak[1] * 255 / 4;
    fn_3_20AE0();
    lbl_3_common_bss_34C90._202[0] = 0;
    lbl_3_common_bss_34C90._202[1] = 0;
    lbl_3_common_bss_34C90._21C[0] = 0;
    lbl_3_common_bss_34C90._21C[1] = 0;
    if (g_GameLogic._13E[g_GameLogic.homeTeamInd]) {
        g_GameLogic.runnerAIInd[0] = 1;
    }
    if (g_GameLogic._13E[g_GameLogic.homeTeamInd ^ 1]) {
        g_GameLogic.runnerAIInd[1] = 1;
    }
    g_AiLogic.aIPitchDesiredEndingLocIndex = 0xFF;
}

// .text:0x0001E178 size:0x1B0 mapped:0x8065D20C
void fn_3_1E178(void) {
    s32 i;
    int t;
    s32 j;

    fn_3_20AB0();
    for (i = 0; i < 10; i++) {
        lbl_3_common_bss_34C90._168[g_GameLogic.homeTeamBattingInd_fieldingTeam][i][0] =
            g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.homeTeamBattingInd_fieldingTeam][i][0];
        lbl_3_common_bss_34C90._168[g_GameLogic.homeTeamBattingInd_fieldingTeam][i][1] =
            g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.homeTeamBattingInd_fieldingTeam][i][1];
    }
    for (t = 0; t < 2; t++) {
        for (j = 0; j < 9; j++) {
            lbl_3_common_bss_34C90._20A[t][j] = lbl_80354720[t][j][3];
        }
    }
}

// .text:0x0001E154 size:0x24 mapped:0x8065D1E8
void fn_3_1E154(void) {
    fn_3_219A0();
    fn_3_20A60();
}

// .text:0x0001DEB8 size:0x29C mapped:0x8065CF4C
// Differs only in `count = 1`: the target copies the 1 stored to `_48` (`mr r4,r6`), this
// loads it again (`li r4,1`).
void fn_3_1DEB8(void) {
    s32 count = 0;
    s32 fielding;
    s32 batting;
    s32 i;

    g_AiLogic.aIDifficultyMultiplierArray[0] = g_AiLogic._46 / 255.0f;
    g_AiLogic.aIDifficultyMultiplierArray[1] = g_AiLogic._47 / 255.0f;
    g_AiLogic._48 = 1;
    if (g_RunningLogic._02 & 0x1000) {
        count = 1;
    }
    if (g_RunningLogic._02 & 0x100) {
        count++;
    }
    if (g_Scores._AC >= 4 && g_Scores._AD != 0 && count != 0 &&
        g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] + count >
            g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0]) {
        g_AiLogic._48 = 4;
    } else {
        if (g_Scores._AC >= 3 && count != 0) {
            fielding = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0];
            batting = g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0];
            if (fielding < batting && fielding + count >= batting) {
                g_AiLogic._48 = 3;
                goto done;
            }
            if (fielding == batting) {
                g_AiLogic._48 = 2;
                goto done;
            }
        }
        if (g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] + 5 <
            g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0]) {
            g_AiLogic._48 = 0;
        }
    }
done:
    fn_3_21768();
    fn_3_20224();
    if (g_d_GameSettings.minigamesEnabled) {
        for (i = 0; i < 4; i++) {
            g_FieldingLogic._074[i]._4 = 0;
            g_FieldingLogic._074[i]._3 = 0;
            if (RandomInt_Game(100) < lbl_3_data_1C30[g_Fielders[g_Minigame.minigameFielderIndex[i]]._1C4]) {
                g_FieldingLogic._074[i]._4 = 1;
            }
        }
    } else {
        g_FieldingLogic._074[0]._4 = 0;
        g_FieldingLogic._074[0]._3 = 0;
        if (RandomInt_Game(100) < lbl_3_data_1C30[g_Fielders[0]._1C4]) {
            g_FieldingLogic._074[0]._4 = 1;
        }
    }
}
