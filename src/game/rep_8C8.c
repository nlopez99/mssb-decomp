#include "game/rep_8C8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"

extern BOOL fn_3_B0CF4(void);
extern void fn_3_B0D2C(void);
extern int fn_3_E587C(void);

typedef struct {
    /* 0x000 */ f32 _000;
    /* 0x004 */ u8 _004[0x268 - 0x4];
} Unk8C8Fielder; // size: 0x268

extern Unk8C8Fielder g_Fielders[9];

extern struct {
    /* 0x00 */ s16 _00;
    /* 0x02 */ s16 _02;
} g_RunningLogic;

// .data 0x193C-0x1D28: only this unit uses most of it, but splits.txt does not assign it here
extern f32 lbl_3_data_19CC[4];
extern u8 lbl_3_data_19C4[8];
extern f32 lbl_3_data_19DC[5][2];
extern f32 lbl_3_data_1A04[2];
extern u8 lbl_3_data_1A24[4];
extern u8 lbl_3_data_1A28[4][5];
extern u8 lbl_3_data_1A3C[4];
extern u8 lbl_3_data_1AAC[4];
extern u8 lbl_3_data_1AB0[4][3];
extern u8 lbl_3_data_1ABC[2][4][4];
extern u8 lbl_3_data_1ADC[4][4];
extern u8 lbl_3_data_1AEC[2][3][4][4];
extern u8 lbl_3_data_1B4C[2];
extern u8 lbl_3_data_1B50[4][2][9];
extern u8 lbl_3_data_1B98[4][4];
extern u8 lbl_3_data_1BA8[4];
extern s8 lbl_3_data_1BAC[2][4][2];
extern s8 lbl_3_data_1BBC[4][2];
extern s8 lbl_3_data_1BC4[4][2];
extern s8 lbl_3_data_1BCC[4][2];
extern u8 lbl_3_data_1BD4[4];
extern u8 lbl_3_data_1BD8[4][3];
extern u8 lbl_3_data_1BE4[4][3];
extern u8 lbl_3_data_1BF0[2][4][3];
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
    if (!g_Batter.swingInd && g_Batter.buntStatus == BUNT_STATUS_NONE && fn_3_1EFE4()) {
        g_Batter.swingInd = TRUE;
        g_Batter.framesSinceStartOfSwing = 0;
    }
    if (!g_Batter.swingInd && g_Batter.buntStatus != BUNT_STATUS_STRIKE) {
        fn_3_1F998();
    }
    if (!g_Batter.swingInd && g_Batter.buntStatus != BUNT_STATUS_STRIKE && g_Batter.buntStatus != BUNT_STATUS_6) {
        if (fn_3_1E724()) {
            g_Batter.isBunting = TRUE;
            g_Batter.hitGeneralType = BAT_CONTACT_TYPE_BUNT;
            if (g_Batter.buntStatus == BUNT_STATUS_NONE) {
                g_Batter.buntStatus = BUNT_STATUS_STARTING;
                g_Batter.framesBuntHeld = 0;
            }
        } else {
            g_Batter.isBunting = FALSE;
        }
    }
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
    if (g_Pitcher.windupCountdownUntilBallReleased != lbl_3_data_1A3C[g_AiLogic.aIBatterDifficulty]) {
        return;
    }
    if (g_AiLogic.lastPitchBallLocZone != 0xFF && RandomInt_Game(100) < lbl_3_data_1A24[g_Batter.characterClass]) {
        g_AiLogic.batterAI_GuessedPitchLocZone = g_AiLogic.lastPitchBallLocZone;
        if (g_AiLogic.batterAI_GuessedPitchLocZone == 0) {
            g_AiLogic.batterAI_GuessedPitchLocZone = 1;
        } else if (g_AiLogic.batterAI_GuessedPitchLocZone == 4) {
            g_AiLogic.batterAI_GuessedPitchLocZone = 3;
        }
    } else {
        g_AiLogic.batterAI_GuessedPitchLocZone = RandomIndexFromWeights(lbl_3_data_1A28[g_Batter.characterClass], 5);
    }
    g_AiLogic.batterAIDesiredXPosInBox = RandomF32_Game_Range(lbl_3_data_19DC[g_AiLogic.batterAI_GuessedPitchLocZone][0],
                                                              lbl_3_data_19DC[g_AiLogic.batterAI_GuessedPitchLocZone][1]);
    g_AiLogic.batterAIInd10_relatedToBoxPosPrePitch = 1;
}

// .text:0x0001F1CC size:0x184 mapped:0x8065E260
void fn_3_1F1CC(void) {
    f32 offset;

    if (g_AiLogic.batterAIInd10_relatedToBoxPosPrePitch == 3) {
        g_AiLogic.batterAIDesiredXPosInBox = g_AiLogic.boxHorizontalPoint;
    } else if (g_Batter.characterClass == 2) {
        if (g_AiLogic.batterAIInd10_relatedToBoxPosPrePitch == 1) {
            return;
        }
        if (g_AiLogic.batterAIInd10_relatedToBoxPosPrePitch == 2 && g_AiLogic._6B != 0) {
            g_AiLogic._6B--;
            return;
        }
        g_AiLogic.batterAIDesiredXPosInBox = RandomF32_Game_Range(lbl_3_data_19DC[0][0], lbl_3_data_19DC[4][1]);
        offset = RandomF32_Game_Range(lbl_3_data_1A04[1], lbl_3_data_1A04[0] + lbl_3_data_1A04[0]);
        if (RandomInt_Game(2) != 0) {
            g_AiLogic.batterAIDesiredXPosInBox += offset;
        } else {
            g_AiLogic.batterAIDesiredXPosInBox -= offset;
        }
        if (g_AiLogic.batterAIDesiredXPosInBox < -lbl_3_data_1A04[0]) {
            g_AiLogic.batterAIDesiredXPosInBox = -lbl_3_data_1A04[0];
        } else if (g_AiLogic.batterAIDesiredXPosInBox > lbl_3_data_1A04[0]) {
            g_AiLogic.batterAIDesiredXPosInBox = lbl_3_data_1A04[0];
        }
        g_AiLogic.batterAIInd10_relatedToBoxPosPrePitch = 1;
        g_AiLogic._6B = RandomInt_Game(45) + 15;
    } else if (g_AiLogic.batterAIInd10_relatedToBoxPosPrePitch == 0) {
        g_AiLogic.batterAIDesiredXPosInBox = RandomF32_Game_Range(lbl_3_data_19DC[g_AiLogic.batterAIInd9PrincessStarHit + 1][0],
                                                                  lbl_3_data_19DC[g_AiLogic.batterAIInd9PrincessStarHit + 1][1]);
        g_AiLogic.batterAIInd10_relatedToBoxPosPrePitch = 1;
    }
}

// .text:0x0001EFE4 size:0x1E8 mapped:0x8065E078
BOOL fn_3_1EFE4(void) {
    int frame;
    int left;
    s16 hangtime;

    if (g_AiLogic.batterAIPotentialSwingTypeForCurrentPitch == 3) {
        return FALSE;
    }
    if (g_AiLogic.batterAIPotentialSwingTypeForCurrentPitch == 1) {
        if (g_AiLogic._70 != 0 && g_AiLogic.lastPitchType != 0xFF) {
            frame = (&g_Pitcher.windupCountdownUntilBallReleased)[2 - g_AiLogic.lastPitchType] +
                    g_AiLogic.lastPitchFramesUntilPitchGetsToBatter;
            frame -= lbl_3_data_19C4[4];
        } else {
            frame = g_Pitcher.curvePitchWindupFrames + 20;
        }
        left = frame - g_Pitcher.pitchTotalTimeCounter;
        left -= g_Batter.frameFullyCharged;
        if (left <= 0 || g_Pitcher.windupCountdownUntilBallReleased < 8) {
            g_Batter.chargeStatus = CHARGE_SWING_STAGE_CHARGEUP;
            g_Batter.hitGeneralType = BAT_CONTACT_TYPE_CHARGE;
        }
    }
    hangtime = g_Ball.pitchHangtimeCounter;
    if (hangtime <= 0) {
        return FALSE;
    }
    if (g_AiLogic.batterAISwingInd != 0) {
        return FALSE;
    }
    if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_FIELDING) {
        fn_3_B0D2C();
    } else {
        if (g_AiLogic.aISwingDecisionRelated_noSwingOverride != 0) {
            return FALSE;
        }
        if (hangtime == 1) {
            fn_3_1EAA8();
        }
        if (g_Pitcher.framesUntilBallReachesBatterZ == g_AiLogic.batterAIZPosition && !fn_3_1E7F4()) {
            g_AiLogic.someNotAISwingInd = 1;
        }
        if (g_Ball.pitchHangtimeCounter == g_AiLogic.frameToStartSwing + 1 && g_AiLogic.frameToStartSwing != 0 &&
            g_AiLogic.someNotAISwingInd == 0) {
            g_AiLogic.batterAISwingInd = 1;
        }
    }
    return g_AiLogic.batterAISwingInd != 0;
}

// .text:0x0001EAA8 size:0x53C mapped:0x8065DB3C
void fn_3_1EAA8(void) {
    int offset;
    int swing;
    int late;
    int n;
    int first;
    int second;

    if (g_AiLogic.batterAIPotentialSwingTypeForCurrentPitch == 3) {
        return;
    }
    if (g_AiLogic.batterAIPotentialSwingTypeForCurrentPitch == 0) {
        offset = RandomIndexFromWeights(lbl_3_data_1B50[g_AiLogic.aIBatterDifficulty][0], 9);
        swing = 0;
    } else {
        offset = RandomIndexFromWeights(lbl_3_data_1B50[g_AiLogic.aIBatterDifficulty][1], 9);
        swing = 1;
    }
    g_AiLogic.frameToStartSwing =
        g_Pitcher.framesUntilBallReachesBatterZ + g_Ball.pitchHangtimeCounter - swingSoundFrame[swing][1];
    g_AiLogic.aIDesiredFrameToSwing = g_AiLogic.frameToStartSwing;
    g_AiLogic.frameToStartSwing += offset - 4;
    if (g_Pitcher.starPitchType == 7 || g_Pitcher.starPitchType == 8) {
        if (RandomInt_Game(100) >= lbl_3_data_1BD4[g_AiLogic.aIBatterDifficulty]) {
            g_AiLogic.frameToStartSwing += g_Pitcher.bulletPitchLoopFrames;
        }
    }
    if (g_Pitcher.starPitchType == 1 || g_Pitcher.starPitchType == 2) {
        offset = RandomInt_Game_Range(lbl_3_data_1BC4[g_AiLogic.aIBatterDifficulty][0],
                                      lbl_3_data_1BC4[g_AiLogic.aIBatterDifficulty][1]);
        if (offset > 5) {
            offset = 5;
        }
        g_AiLogic.frameToStartSwing += offset;
    } else if (g_Pitcher.starPitchType == 11 || g_Pitcher.starPitchType == 12) {
        g_AiLogic.frameToStartSwing += RandomInt_Game_Range(lbl_3_data_1BBC[g_AiLogic.aIBatterDifficulty][0],
                                                            lbl_3_data_1BBC[g_AiLogic.aIBatterDifficulty][1]);
    } else if (g_Pitcher.starPitchType == 9 || g_Pitcher.starPitchType == 10) {
        g_AiLogic.frameToStartSwing += RandomInt_Game_Range(lbl_3_data_1BCC[g_AiLogic.aIBatterDifficulty][0],
                                                            lbl_3_data_1BCC[g_AiLogic.aIBatterDifficulty][1]);
    } else if (g_AiLogic.batterAISwingEarly1OrLate2 == 0) {
        if (RandomInt_Game(100) < lbl_3_data_1B98[g_Batter.characterClass][g_AiLogic.aIBatterDifficulty]) {
            g_AiLogic.frameToStartSwing += lbl_3_data_1BA8[g_AiLogic.aIBatterDifficulty];
        }
    } else {
        late = g_AiLogic.batterAISwingEarly1OrLate2 == 1 ? 0 : 1;
        g_AiLogic.frameToStartSwing += RandomInt_Game_Range(lbl_3_data_1BAC[late][g_AiLogic.aIBatterDifficulty][0],
                                                            lbl_3_data_1BAC[late][g_AiLogic.aIBatterDifficulty][1]);
    }
    g_AiLogic.batterAILeftRightInput = RandomIndexFromWeights(lbl_3_data_1BD8[g_Batter.characterClass], 3);
    if (g_d_GameSettings.GameModeSelected == 6) {
        first = g_Minigame.minigameFielderIndex[(s8)g_Minigame.minigameControlStruct._28[1]];
        second = g_Minigame.minigameFielderIndex[(s8)g_Minigame.minigameControlStruct._28[2]];
        if (g_Fielders[first]._000 < 0.0f && g_Fielders[second]._000 < 0.0f) {
            if (g_Batter.batterHand != 0) {
                g_AiLogic.batterAILeftRightInput = 0;
            } else {
                g_AiLogic.batterAILeftRightInput = 2;
            }
        } else if (g_Fielders[first]._000 > 0.0f && g_Fielders[second]._000 > 0.0f) {
            if (g_Batter.batterHand != 0) {
                g_AiLogic.batterAILeftRightInput = 2;
            } else {
                g_AiLogic.batterAILeftRightInput = 0;
            }
        } else {
            n = fn_3_E587C();
            if (n >= 4) {
                if (g_Batter.batterHand != 0) {
                    g_AiLogic.batterAILeftRightInput = 0;
                } else {
                    g_AiLogic.batterAILeftRightInput = 2;
                }
            } else if (n != 3 && n >= 0) {
                if (g_Batter.batterHand != 0) {
                    g_AiLogic.batterAILeftRightInput = 2;
                } else {
                    g_AiLogic.batterAILeftRightInput = 0;
                }
            }
        }
    } else if (g_Strikes.outs <= 1 && (g_RunningLogic._02 & 0x1000) && g_AiLogic.aIBatterDifficulty >= 1) {
        if (g_Batter.characterClass == CHARACTER_CLASS_POWER) {
            g_AiLogic.batterAIUpDownInput = RandomIndexFromWeights(lbl_3_data_1BF0[0][g_AiLogic.aIBatterDifficulty], 3);
        } else {
            g_AiLogic.batterAIUpDownInput = RandomIndexFromWeights(lbl_3_data_1BF0[1][g_AiLogic.aIBatterDifficulty], 3);
        }
    } else {
        g_AiLogic.batterAIUpDownInput = RandomIndexFromWeights(lbl_3_data_1BE4[g_Batter.characterClass], 3);
    }
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
