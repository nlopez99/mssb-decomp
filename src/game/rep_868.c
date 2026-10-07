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

// .data outside this unit's split
extern u8 lbl_3_data_1C30[8];

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
