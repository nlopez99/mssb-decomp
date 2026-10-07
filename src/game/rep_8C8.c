#include "game/rep_8C8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"

extern BOOL fn_3_B0CF4(void);
extern void fn_3_B0D2C(void);
extern int fn_3_E587C(void);

// .data 0x193C-0x1D28: only this unit uses most of it, but splits.txt does not assign it here
extern f32 lbl_3_data_19CC[4];
extern u8 lbl_3_data_1AAC[4];
extern u8 lbl_3_data_1AB0[4][3];
extern u8 lbl_3_data_1ABC[2][4][4];
extern u8 lbl_3_data_1ADC[4][4];
extern u8 lbl_3_data_1AEC[2][3][4][4];
extern u8 lbl_3_data_1B4C[2];
extern f32 lbl_3_data_4474[4];

// .text:0x00020224 size:0x83C mapped:0x8065F2B8
void fn_3_20224(void) {
    return;
}

// .text:0x00020188 size:0x9C mapped:0x8065F21C
void fn_3_20188(void) {
    if (g_AiLogic.lastPitchType != 0xFF && RandomInt_Game(100) < lbl_3_data_1AAC[g_AiLogic.aIBatterDifficulty]) {
        g_AiLogic.batterAIPitchGuessed = g_AiLogic.lastPitchType;
    } else {
        g_AiLogic.batterAIPitchGuessed = RandomIndexFromWeights(lbl_3_data_1AB0[g_Pitcher.charClass], 3);
    }
}

// .text:0x00020064 size:0x124 mapped:0x8065F0F8
void fn_3_20064(void) {
    g_AiLogic.batterAITrackBallPoorlyOffset = 0.0f;
    if (g_Pitcher.starPitchType != 0) {
        return;
    }
    if (g_Pitcher.TypeOfPitch == 0) {
        g_AiLogic.batterAISwingEarly1OrLate2 = 0;
    } else if (g_AiLogic.batterAIPitchGuessed != g_Pitcher.TypeOfPitch) {
        if (g_Pitcher.TypeOfPitch == 1) {
            if (RandomInt_Game(100) < lbl_3_data_1ABC[0][g_Batter.characterClass][g_AiLogic.aIBatterDifficulty]) {
                g_AiLogic.batterAISwingEarly1OrLate2 = 0;
            } else {
                g_AiLogic.batterAISwingEarly1OrLate2 = 1;
            }
        } else {
            if (RandomInt_Game(100) < lbl_3_data_1ABC[1][g_Batter.characterClass][g_AiLogic.aIBatterDifficulty]) {
                g_AiLogic.batterAISwingEarly1OrLate2 = 0;
            } else {
                g_AiLogic.batterAISwingEarly1OrLate2 = 2;
            }
        }
    } else {
        g_AiLogic.batterAISwingEarly1OrLate2 = 0;
    }
}

// .text:0x0001FF48 size:0x11C mapped:0x8065EFDC
void fn_3_1FF48(void) {
    int zone;
    f32 step;
    f32 edge;

    if (g_Pitcher.starPitchType != 0) {
        return;
    }
    g_AiLogic.lastPitchFramesUntilPitchGetsToBatter = g_Pitcher.framesUntilPitchGetsToBatter;
    g_AiLogic.lastPitchType = g_Pitcher.TypeOfPitch;
    for (zone = 0; zone < 4; zone++) {
        if (g_Pitcher.pitchXPosition < lbl_3_data_19CC[zone]) {
            break;
        }
    }
    if (g_Batter.batterHand != 0) {
        zone = 4 - zone;
    }
    g_AiLogic.lastPitchBallLocZone = zone;
    step = (lbl_3_data_4474[1] - lbl_3_data_4474[0]) / 5.0f;
    edge = lbl_3_data_4474[0];
    for (zone = 0; zone < 4; zone++) {
        edge += step;
        if (g_Pitcher.pitcher.x < edge) {
            break;
        }
    }
    g_AiLogic.lastPitchMoundZone = zone;
}

// .text:0x0001FD8C size:0x1BC mapped:0x8065EE20
void batterAIControlled(void) {
    return;
}

// .text:0x0001F998 size:0x3F4 mapped:0x8065EA2C
void fn_3_1F998(void) {
    return;
}

// .text:0x0001F478 size:0x520 mapped:0x8065E50C
void fn_3_1F478(void) {
    return;
}

// .text:0x0001F350 size:0x128 mapped:0x8065E3E4
void fn_3_1F350(void) {
    return;
}

// .text:0x0001F1CC size:0x184 mapped:0x8065E260
void fn_3_1F1CC(void) {
    return;
}

// .text:0x0001EFE4 size:0x1E8 mapped:0x8065E078
void fn_3_1EFE4(void) {
    return;
}

// .text:0x0001EAA8 size:0x53C mapped:0x8065DB3C
void fn_3_1EAA8(void) {
    return;
}

// .text:0x0001E7F4 size:0x2B4 mapped:0x8065D888
BOOL fn_3_1E7F4(void) {
    int kind;
    int zone;
    int chance;

    if (g_Pitcher.starPitchType == 3 || g_Pitcher.starPitchType == 4) {
        kind = 0;
    } else if (g_Pitcher.starPitchType == 11 || g_Pitcher.starPitchType == 12) {
        kind = 0;
    } else if (g_Pitcher.starPitchType == 1 || g_Pitcher.starPitchType == 2) {
        kind = 0;
    } else {
        for (zone = 0; zone < 4; zone++) {
            if (g_Pitcher.pitchXPosition < lbl_3_data_19CC[zone]) {
                break;
            }
        }
        if (g_Batter.batterHand != 0) {
            zone = 4 - zone;
        }
        if (zone == 1 || zone == 3) {
            kind = 1;
        } else if (zone == 2) {
            kind = 0;
        } else {
            kind = 2;
        }
        if (g_AiLogic.batterAIBuntInd != 1) {
            if (g_AiLogic.aIBatterTrackingCode != 0 || kind == 0 || g_AiLogic.lastPitchBallLocZone == zone) {
                if (g_AiLogic.batterAISwingEarly1OrLate2 == 0) {
                    chance = lbl_3_data_1ADC[1][g_AiLogic.aIBatterDifficulty];
                } else {
                    chance = lbl_3_data_1ADC[3][g_AiLogic.aIBatterDifficulty];
                }
            } else {
                if (g_AiLogic.batterAISwingEarly1OrLate2 == 0) {
                    chance = lbl_3_data_1ADC[0][g_AiLogic.aIBatterDifficulty];
                } else {
                    chance = lbl_3_data_1ADC[2][g_AiLogic.aIBatterDifficulty];
                }
            }
            if (RandomInt_Game(100) >= chance) {
                return FALSE;
            }
        }
    }
    if (g_d_GameSettings.GameModeSelected == 6) {
        kind = lbl_3_data_1AEC[1][kind][g_Batter.characterClass][g_AiLogic.aIBatterDifficulty];
    } else {
        kind = lbl_3_data_1AEC[0][kind][g_Batter.characterClass][g_AiLogic.aIBatterDifficulty];
    }
    if (g_AiLogic.batterAIBuntInd == 1) {
        kind += lbl_3_data_1B4C[0];
    } else if (g_AiLogic.batterAIPotentialSwingTypeForCurrentPitch == 2) {
        kind += lbl_3_data_1B4C[1];
    }
    return RandomInt_Game(100) < kind;
}

// .text:0x0001E724 size:0xD0 mapped:0x8065D7B8
BOOL fn_3_1E724(void) {
    if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_FIELDING) {
        if (fn_3_B0CF4()) {
            return TRUE;
        }
        return FALSE;
    }
    if (g_AiLogic.batterAIBuntInd != 1) {
        return FALSE;
    }
    if (g_AiLogic.aISwingDecisionRelated_noSwingOverride != 0) {
        return FALSE;
    }
    if (g_Ball.pitchHangtimeCounter <= 0) {
        return TRUE;
    }
    if (g_Pitcher.framesUntilBallReachesBatterZ == g_AiLogic.batterAIZPosition && !fn_3_1E7F4()) {
        g_AiLogic.aISwingDecisionRelated_noSwingOverride = 1;
        return FALSE;
    }
    return TRUE;
}

// .text:0x0001E4B8 size:0x26C mapped:0x8065D54C
void fn_3_1E4B8(void) {
    return;
}
