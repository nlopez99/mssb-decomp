#include "game/rep_940.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ u8 _50[0xAA - 0x50];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB;
    /* 0xAC */ u8 _AC;
    /* 0xAD */ u8 _AD;
} g_Scores;

extern struct {
    /* 0x00 */ s16 _00;
    /* 0x02 */ s16 _02;
} g_RunningLogic;

extern struct {
    /* 0x00 */ u8 _00[0x46];
    /* 0x46 */ u8 _46;
} lbl_3_common_bss_37400;

// .data 0x1880-0x193C: only this unit uses it, but splits.txt does not assign it here yet
extern u8 lbl_3_data_1880[8];
extern u8 lbl_3_data_1888[2][4][4];
extern u8 lbl_3_data_18A8[3][4];
extern u8 lbl_3_data_18B4[4][4];
extern u8 lbl_3_data_18C4[5][4];
extern s8 lbl_3_data_18D8[2];
extern u8 lbl_3_data_18DC[4];
extern u8 lbl_3_data_18E0[4][4];
extern f32 lbl_3_data_18F0[7];
extern u8 lbl_3_data_190C[4][6];
extern u8 lbl_3_data_1924[4][4];
extern s16 lbl_3_data_1934[4];
extern f32 lbl_3_data_4474[4];

// rep_1200.h declares this as taking no arguments; it stores its argument as
// g_Pitcher.pitcherActionState
extern void fn_3_750C4(u8 state);

// .text:0x000219A0 size:0x2C mapped:0x80660A34
void fn_3_219A0(void) {
    g_AiLogic.nStarPitchesThrownThisAB = 0;
    g_AiLogic.aIMoundLocationX = 0.0f;
    g_AiLogic.aIMoundLocationIndex = 2;
    g_AiLogic.always0_AIPickoffRelated = 0;
}

// .text:0x00021768 size:0x238 mapped:0x806607FC
void fn_3_21768(void) {
    int chance;

    g_AiLogic.pitcherAIPitchDownTheMiddleInd = 0;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        if (g_Practice.practiceType_2 == 1) {
            g_AiLogic.pitcherAIPitchDownTheMiddleInd = 1;
        } else if (g_Practice.practiceType_2 == 2) {
            g_AiLogic.pitcherAIPitchDownTheMiddleInd = 1;
        } else if (g_Practice.practiceType_2 == 3) {
            g_AiLogic.pitcherAIPitchDownTheMiddleInd = 1;
        } else if (g_Practice.practiceLevel == 4) {
            g_AiLogic.pitcherAIPitchDownTheMiddleInd = 1;
        }
    }
    if (g_AiLogic.pitcherAIPitchDownTheMiddleInd) {
        g_AiLogic.aiPitchCurveEndingX = 0.0f;
    }
    g_AiLogic._49 = lbl_3_data_1880[g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.awayTeamBattingInd_battingTeam]];
    if (g_AiLogic.pitcherAIPitchDownTheMiddleInd) {
        g_AiLogic.AIFrameToBeginPitch = lbl_3_data_1934[2];
    } else {
        g_AiLogic.AIFrameToBeginPitch = RandomInt_Game_Range(lbl_3_data_1934[0], lbl_3_data_1934[1]);
    }
    if (!g_d_GameSettings.exhibitionMatchInd && lbl_3_common_bss_37400._46 && !g_Pitcher.nPitchesThisAB) {
        g_AiLogic.AIFrameToBeginPitch = lbl_3_data_1934[1] + 60;
    }
    if (!g_AiLogic.pitcherAIPitchDownTheMiddleInd) {
        g_AiLogic.aIPitcherPickOffInd = 0;
        if (g_RunningLogic._02 != 1 && g_RunningLogic._02 != 0x1111) {
            if (g_AiLogic.always0_AIPickoffRelated) {
                chance = 5;
            } else {
                chance = lbl_3_data_1924[g_Pitcher.charClass][g_AiLogic._49];
            }
            if (RandomInt_Game(100) < chance) {
                g_AiLogic.aIPitcherPickOffInd = 1;
            }
        }
    }
    g_AiLogic.aiPitchCurveType = 0;
    g_AiLogic.aiPitchDirectionInput = 0;
    g_AiLogic.pitchAIDelayCurveStart = 0;
    g_AiLogic.aIPerfectCharge = 0;
}

// .text:0x000215AC size:0x1BC mapped:0x80660640
void fn_3_215AC(void) {
    if (g_Pitcher.currentStateFrameCounter == 1) {
        fn_3_20EEC();
    }
    fn_3_20E50();
    if (g_Pitcher.currentStateFrameCounter >= g_AiLogic.AIFrameToBeginPitch &&
        !g_Batter.beginningOfABAnimationOccuring) {
        fn_3_212A0();
        fn_3_20FB0();
        fn_3_750C4(PITCHER_ACTION_STATE_WINDUP);
        g_Stats._38 = 1;
    }
}

// .text:0x000212A0 size:0x30C mapped:0x80660334
void fn_3_212A0(void) {
    BOOL useStar;
    int chance;

    g_AiLogic.aIPitchType = 0;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        return;
    }
    if (!g_d_GameSettings.minigamesEnabled && g_GameLogic.TeamStars[g_GameLogic.teamFielding]) {
        useStar = FALSE;
        // Compares the two arrays' addresses (cmplw), not their contents
        if (g_Scores._00 >= g_Scores._AA &&
            g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam] >
                g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam] &&
            g_Strikes.outs >= 2) {
            useStar = TRUE;
        } else if (g_Scores._00 >= g_Scores._AB && g_Scores._AD && g_Strikes.outs >= 2) {
            useStar = TRUE;
        } else if (g_RunningLogic._02 == 0x101 || g_RunningLogic._02 == 0x1101 || g_RunningLogic._02 == 0x1111) {
            useStar = TRUE;
        }
        if (useStar) {
            chance = lbl_3_data_18C4[g_GameLogic.TeamStars[g_GameLogic.teamFielding] - 1][g_AiLogic._49];
            if (g_AiLogic.nStarPitchesThrownThisAB) {
                chance += lbl_3_data_18D8[0];
            } else if (g_Strikes.strikes) {
                chance += g_Strikes.strikes * lbl_3_data_18D8[1];
            }
            if (RandomInt_Game(100) < chance) {
                g_AiLogic.aIPitchType = 2;
                g_Pitcher.starPitchInd = 1;
                return;
            }
        }
    }
    if (g_RunningLogic._00 == 1 || g_RunningLogic._00 == 0x1101 || g_RunningLogic._00 == 0x1111 ||
        g_RunningLogic._00 == 0x1001) {
        chance = lbl_3_data_1888[0][g_Pitcher.charClass][g_AiLogic._49];
    } else {
        chance = lbl_3_data_1888[1][g_Pitcher.charClass][g_AiLogic._49];
    }
    if (RandomInt_Game(100) < chance) {
        g_AiLogic.aIPitchType = 1;
        if (RandomInt_Game(100) < lbl_3_data_18B4[g_Pitcher.charClass][g_AiLogic._49]) {
            g_AiLogic.aIPitchType = 3;
            g_Pitcher.TypeOfPitch = 2;
        } else {
            chance = lbl_3_data_18A8[g_Strikes.strikes][g_AiLogic._49];
            if (RandomInt_Game(100) < chance) {
                g_AiLogic.aIPerfectCharge = 1;
            }
        }
    }
}

// .text:0x00020FB0 size:0x2F0 mapped:0x80660044
void fn_3_20FB0(void) {
    int tries;
    int loc;
    int n;
    int i;
    int chance;

    if (g_AiLogic.aiPitchCurveType == 0) {
        g_AiLogic.aiPitchCurveType = 3;
        if (g_AiLogic.pitcherAIPitchDownTheMiddleInd) {
            g_AiLogic.aiPitchCurveType = 1;
        }
    }
    if (g_AiLogic.aiPitchCurveType == 1) {
        g_AiLogic.aiPitchCurveEndingX = 0.0f;
    } else if (g_AiLogic.aiPitchCurveType == 2) {
        g_AiLogic.aiPitchCurveEndingX = 0.01f * RandomInt_Game_Range(-10, 10);
    } else if (g_AiLogic.aiPitchCurveType == 3) {
        tries = 0;
        if (RandomInt_Game(100) < lbl_3_data_18DC[g_AiLogic._49]) {
            for (;;) {
                loc = g_AiLogic.aIMoundLocationIndex + RandomInt_Game(3);
                if (g_AiLogic.aIPitchDesiredEndingLocIndex != loc || tries >= 2) {
                    break;
                }
                tries++;
            }
        } else {
            for (;;) {
                n = RandomInt_Game(4);
                for (i = 0; i < 7; i++) {
                    if (i == g_AiLogic.aIMoundLocationIndex || i == g_AiLogic.aIMoundLocationIndex + 1 ||
                        i == g_AiLogic.aIMoundLocationIndex + 2) {
                        continue;
                    }
                    if (n == 0) {
                        break;
                    }
                    n--;
                }
                loc = i;
                if (g_AiLogic.aIPitchDesiredEndingLocIndex != loc || tries >= 2) {
                    break;
                }
                tries++;
            }
        }
        g_AiLogic.aIPitchDesiredEndingLocIndex = loc;
        g_AiLogic.aiPitchCurveEndingX = lbl_3_data_18F0[loc];
    }
    g_AiLogic.pitchAIDelayCurveStart = 0;
    chance = lbl_3_data_18E0[g_Pitcher.charClass][g_AiLogic._49];
    if (chance < RandomInt_Game(100)) {
        g_AiLogic.pitchAIDelayCurveStart = 1;
    }
}

// .text:0x00020EEC size:0xC4 mapped:0x8065FF80
void fn_3_20EEC(void) {
    int index;
    f32 width;

    if (g_AiLogic.pitcherAIPitchDownTheMiddleInd) {
        g_AiLogic.aIMoundLocationX = 0.0f;
        return;
    }
    index = RandomIndexFromWeights(lbl_3_data_190C[g_Pitcher.charClass], 6);
    if (index != 5) {
        g_AiLogic.aIMoundLocationIndex = index;
        width = lbl_3_data_4474[1] - lbl_3_data_4474[0];
        width /= 5.0f;
        g_AiLogic.aIMoundLocationX = lbl_3_data_4474[0] + width * index;
    }
}

// .text:0x00020E50 size:0x9C mapped:0x8065FEE4
void fn_3_20E50(void) {
    f32 diff;

    if (g_Pitcher.currentStateFrameCounter < 30) {
        return;
    }
    if (g_AiLogic.aIMoundLocationX == g_Pitcher.pitcher.x) {
        return;
    }
    diff = g_AiLogic.aIMoundLocationX - g_Pitcher.pitcher.x;
    if (diff > 0.0f) {
        if (diff <= lbl_3_data_4474[2]) {
            g_Pitcher.pitcher.x = g_AiLogic.aIMoundLocationX;
        } else {
            g_Pitcher.pitcher.x += lbl_3_data_4474[2];
        }
    } else {
        if (diff >= -lbl_3_data_4474[2]) {
            g_Pitcher.pitcher.x = g_AiLogic.aIMoundLocationX;
        } else {
            g_Pitcher.pitcher.x -= lbl_3_data_4474[2];
        }
    }
}

// .text:0x00020CEC size:0x164 mapped:0x8065FD80
int fn_3_20CEC(f32 step) {
    f32 diff;
    s32 frames;

    if (g_Ball.pitchHangtimeCounter <= 1) {
        return 0;
    }
    if (step == 0.0f) {
        return 0;
    }
    diff = g_AiLogic.aiPitchCurveEndingX - g_Pitcher.pitchXPosition2;
    if (g_AiLogic.pitchAIDelayCurveStart) {
        frames = g_Pitcher.frameWhenUnhittable - g_Ball.pitchHangtimeCounter;
        if (frames <= 0) {
            return 0;
        }
        step *= frames / 2 * frames;
        if (diff < 0.0f) {
            if (-diff < step) {
                return 0;
            }
        } else if (diff < step) {
            return 0;
        }
        g_AiLogic.pitchAIDelayCurveStart = 0;
    }
    if (diff > 0.03f) {
        if (g_AiLogic.aiPitchDirectionInput == -1) {
            return 0;
        }
        g_AiLogic.aiPitchDirectionInput = 1;
        return 1;
    }
    if (diff < -0.03f) {
        if (g_AiLogic.aiPitchDirectionInput == 1) {
            return 0;
        }
        g_AiLogic.aiPitchDirectionInput = -1;
        return -1;
    }
    return 0;
}
