#include "game/rep_1188.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"

#include "static/UnknownHomes_Static.h"

typedef struct {
    /* 0x0 */ s8 index;
    /* 0x1 */ s8 slot;
    /* 0x2 */ s8 value;
    /* 0x3 */ s8 _3;
} UnkSlot1188; // size: 0x4

typedef struct {
    /* 0x000 */ u8 _000[0x58];
    /* 0x058 */ f32 _058;
    /* 0x05C */ f32 _05C;
    /* 0x060 */ u8 _060[0xE8 - 0x60];
    /* 0x0E8 */ f32 _0E8;
    /* 0x0EC */ f32 _0EC;
    /* 0x0F0 */ f32 _0F0;
    /* 0x0F4 */ f32 _0F4;
    /* 0x0F8 */ f32 _0F8;
    /* 0x0FC */ f32 _0FC;
    /* 0x100 */ f32 _100;
    /* 0x104 */ f32 _104;
    /* 0x108 */ f32 _108;
    /* 0x10C */ u8 _10C[0x16C - 0x10C];
    /* 0x16C */ f32 _16C;
    /* 0x170 */ u8 _170[0x178 - 0x170];
    /* 0x178 */ s16 rosterID;
    /* 0x17A */ s16 charID;
    /* 0x17C */ s16 scoutFlagRelated;
    /* 0x17E */ u8 _17E[0x1C4 - 0x17E];
    /* 0x1C4 */ u8 aiLevel;
    /* 0x1C5 */ u8 _1C5[0x1C7 - 0x1C5];
    /* 0x1C7 */ u8 fieldingArm;
    /* 0x1C8 */ u8 characterClass;
    /* 0x1C9 */ u8 weight;
    /* 0x1CA */ u8 _1CA;
    /* 0x1CB */ u8 _1CB;
    /* 0x1CC */ u8 _1CC;
    /* 0x1CD */ u8 _1CD;
    /* 0x1CE */ u8 throwingArm;
    /* 0x1CF */ u8 _1CF;
    /* 0x1D0 */ u8 speed;
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2[0x218 - 0x1D2];
    /* 0x218 */ u8 _218;
    /* 0x219 */ u8 _219[0x268 - 0x219];
} UnkFielder1188; // size: 0x268

extern UnkFielder1188 g_Fielders[9];
extern f32 lbl_3_data_4640[2][22];
extern struct {
    /* 0x000 */ s16 sizes[54][8];
    /* 0x360 */ s16 mins[8];
} lbl_3_data_79B4;
extern s16 lbl_3_data_7F10[54];

extern UnkSlot1188 lbl_80354720[2][9];
extern struct {
    /* 0x0000 */ u8 _0000[0x4709];
    /* 0x4709 */ u8 _4709;
    /* 0x470A */ u8 _470A;
} lbl_8034E9A0;
extern f32 lbl_3_data_5FC4[12];

extern u8 aILevel[4];
extern s16 lbl_3_data_460C[6];
extern u8 lbl_3_data_4744[24];
extern f32 lbl_3_data_4BC4[10];
extern f32 runnerVelocityLookup[22];
extern s16 lbl_3_data_4C54[12];
extern u8 lbl_3_data_775C;

extern int LERPToNewRange_Float(int value, int inMin, int inMax, int outMin, int outMax);

// .text:0x0006EF1C size:0x5CC mapped:0x806ADFB0
void fn_3_6EF1C(void) {
    int j;
    int team;
    int (*entry)[2];
    int i;

    for (i = 0; i < 2; i++) {
        team = i ^ g_GameLogic.homeTeamInd;
        g_GameLogic.battingOrderAndPositionMapping[team][0][1] = 0;
        for (j = 0; j < 9; j++) {
            if (lbl_80354720[i][j].slot == 9) {
                g_GameLogic.battingOrderAndPositionMapping[team][0][0] = lbl_80354720[i][j].index;
            } else {
                entry = g_GameLogic.battingOrderAndPositionMapping[team];
                entry += lbl_80354720[i][j].slot;
                entry[1][0] = lbl_80354720[i][j].index;
                entry[1][1] = lbl_80354720[i][j].value;
                if (lbl_80354720[i][j].value == 0) {
                    g_GameLogic.battingOrderAndPositionMapping[team][0][0] = lbl_80354720[i][j].index;
                }
            }
        }
    }

    g_GameLogic.Team_CaptainRosterLoc[0] = lbl_8034E9A0._4709;
    g_GameLogic.Team_CaptainRosterLoc[1] = lbl_8034E9A0._470A;

    if (!g_d_GameSettings.exhibitionMatchInd) {
        for (i = 0; i < 9; i++) {
            if (g_d_GameSettings.challengeCaptainStarBought[0] || g_d_GameSettings._4F) {
                inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.SlapContactSize *= lbl_3_data_5FC4[0];
                inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.ChargeContactSize *= lbl_3_data_5FC4[0];
            }
            if (g_d_GameSettings.challengeCaptainStarBought[1] || g_d_GameSettings._4F) {
                inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.SlapHitPower *= lbl_3_data_5FC4[2];
                inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.ChargeHitPower *= lbl_3_data_5FC4[2];
            }
            if (g_d_GameSettings.challengeCaptainStarBought[2] || g_d_GameSettings.challengeCaptainStarBought[2]) {
                inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CurveBallSpeed += (u8)lbl_3_data_5FC4[4];
                inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.FastBallSpeed += (u8)lbl_3_data_5FC4[4];
                inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.Curve *= lbl_3_data_5FC4[5];
            }
            if (g_d_GameSettings.challengeCaptainStarBought[3] || g_d_GameSettings._4F) {
                inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.ThrowingArm *= lbl_3_data_5FC4[7];
            }
            if (g_d_GameSettings.challengeCaptainStarBought[4] || g_d_GameSettings._4F) {
                inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.Speed *= lbl_3_data_5FC4[8];
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 0) {
                if (g_d_GameSettings.challengeCaptainStarBought[6]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 1;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 1) {
                if (g_d_GameSettings.challengeCaptainStarBought[7]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 2;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 2) {
                if (g_d_GameSettings.challengeCaptainStarBought[14]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 5;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 3) {
                if (g_d_GameSettings.challengeCaptainStarBought[15]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 6;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 4) {
                if (g_d_GameSettings.challengeCaptainStarBought[8]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 11;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 5) {
                if (g_d_GameSettings.challengeCaptainStarBought[9]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 12;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 6) {
                if (g_d_GameSettings.challengeCaptainStarBought[12]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 9;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 17) {
                if (g_d_GameSettings.challengeCaptainStarBought[13]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 10;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 10) {
                if (g_d_GameSettings.challengeCaptainStarBought[10]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 3;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 11) {
                if (g_d_GameSettings.challengeCaptainStarBought[11]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 4;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 9) {
                if (g_d_GameSettings.challengeCaptainStarBought[16]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 7;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
            if (inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CharID == 19) {
                if (g_d_GameSettings.challengeCaptainStarBought[17]) {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 8;
                } else {
                    inMemRoster[g_d_GameSettings.humanTeamNumber][i].stats.CaptainStarHitPitch = 0;
                }
            }
        }
    }
}

// .text:0x0006EBB4 size:0x368 mapped:0x806ADC48
void fn_3_6EBB4(int rosterID) {
    int index;

    CharacterStats* char_stats = &inMemRoster[g_GameLogic.teamFielding][rosterID];
    ChallengeTrackingStruct* starMissions = starMissionCompletionTracker;

    if (rosterID < 0) {
        g_Pitcher.rosterID = 0;
        g_Pitcher.charID = 0;
        g_Pitcher.handedness = 0;
        g_Pitcher.curveBallSpeed = lbl_3_data_460C[0];
        g_Pitcher.fastBallSpeed = lbl_3_data_460C[1];
        g_Pitcher.cursedBallStat = lbl_3_data_460C[2];
        g_Pitcher.curveControlStat = lbl_3_data_460C[3];
        g_Pitcher.curveStat = lbl_3_data_460C[4];
        g_Pitcher.captainStarPitch = lbl_3_data_460C[5];
        return;
    }

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        if (g_Practice.practiceType_2 == 0 || g_Practice.practiceType_2 == 1 || g_Practice.practiceType_2 == 2 ||
            g_Practice.practiceType_2 == 3) {
            rosterID = 0;
            char_stats = &inMemRoster[g_GameLogic.teamFielding][g_Minigame.minigamePlayerSelectedOrder];
        }
    } else if (g_d_GameSettings.minigamesEnabled) {
        rosterID = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        char_stats = &inMemRoster[0][rosterID];
    }

    g_Pitcher.rosterID = rosterID;
    g_Pitcher.charID = (u8)char_stats->stats.CharID;
    g_Pitcher.handedness = char_stats->stats.FieldingArm;
    g_Pitcher.curveBallSpeed = char_stats->stats.CurveBallSpeed;
    g_Pitcher.fastBallSpeed = char_stats->stats.FastBallSpeed;
    g_Pitcher.cursedBallStat = char_stats->stats.cursedBall;
    g_Pitcher.curveControlStat = char_stats->stats.curveControl;
    g_Pitcher.curveStat = char_stats->stats.Curve;
    g_Pitcher.charClass = char_stats->stats.CharacterClass;
    g_Pitcher.aiLevel = g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.awayTeamBattingInd_battingTeam];

    if (!g_d_GameSettings.exhibitionMatchInd) {
        g_Pitcher.scoutFlagRelated = -1;
        for (index = 0; index < 54; index++) {
            if ((g_Pitcher.charID == index) && (starMissions[index].variantClassification <= 3)) {
                g_Pitcher.scoutFlagRelated = index;
                break;
            }
        }
    }

    if (g_d_GameSettings.minigamesEnabled) {
        s8 bVar1;
        g_Pitcher.captainStarPitch = 0;
        g_Pitcher.nonCaptainStarPitch = 0;
        if (g_Minigame.battingHandedness[rosterID] <= 1) {
            g_Pitcher.handedness = 0;
        } else {
            g_Pitcher.handedness = 1;
        }

        bVar1 = g_Minigame.minigameControlStruct.characterIndex[rosterID];

        if (g_Minigame.minigameControlStruct.battingHandedness[bVar1] != 0) {
            g_Pitcher.aiLevel = aILevel[g_Minigame.minigameControlStruct.aIStrength[bVar1]];
        }
    } else {
        g_Pitcher.captainStarPitch = char_stats->stats.CaptainStarHitPitch;
        g_Pitcher.nonCaptainStarPitch = char_stats->stats.NonCaptainStarPitch;
    }
}

static inline u32 getFieldingStats(int rosterID) {
    int team = g_GameLogic.teamFielding;
    if (g_d_GameSettings.minigamesEnabled) {
        team = 0;
    }
    return inMemRoster[team][rosterID].stats.FieldingStats;
}

// .text:0x0006E24C size:0x968 mapped:0x806AD2E0
void fn_3_6E24C(int rosterID, int fielderIdx) {
    int index;
    int charID;
    int lo;
    int hi;
    f32 width;
    f32 third;
    f32 min;

    UnkFielder1188* fielder = &g_Fielders[fielderIdx];
    CharacterStats* char_stats = &inMemRoster[g_GameLogic.teamFielding][rosterID];
    ChallengeTrackingStruct* starMissions = starMissionCompletionTracker;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        if (g_Practice.practiceType_2 == 0 || g_Practice.practiceType_2 == 1 || g_Practice.practiceType_2 == 2 ||
            g_Practice.practiceType_2 == 3) {
            char_stats = &inMemRoster[g_GameLogic.teamFielding][fielderIdx];
        }
    } else if (g_d_GameSettings.minigamesEnabled) {
        char_stats = &inMemRoster[0][g_Minigame.minigameControlStruct.characterIndex[rosterID]];
    }

    fielder->rosterID = rosterID;
    charID = char_stats->stats.CharID;
    fielder->charID = charID;
    fielder->fieldingArm = char_stats->stats.FieldingArm;
    fielder->weight = char_stats->stats.Weight;
    fielder->aiLevel = g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.awayTeamBattingInd_battingTeam];

    if ((getFieldingStats(fielder->rosterID) >> 7) & 1) {
        fielder->_1CA = 5;
    } else {
        fielder->_1CA = fielder->weight;
    }

    if (!g_d_GameSettings.exhibitionMatchInd) {
        fielder->scoutFlagRelated = -1;
        for (index = 0; index < 54; index++) {
            if ((fielder->charID == index) && (starMissions[index].variantClassification <= 3)) {
                fielder->scoutFlagRelated = index;
                break;
            }
        }
    }

    if (g_d_GameSettings.minigamesEnabled) {
        s8 bVar1 = g_Minigame.minigameControlStruct.characterIndex[rosterID];

        if (g_Minigame.minigameControlStruct.battingHandedness[bVar1] != 0) {
            fielder->aiLevel = aILevel[g_Minigame.minigameControlStruct.aIStrength[bVar1]];
        }
    }

    if (g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamFielding] == fielder->rosterID) {
        fielder->_218 = 0;
    } else {
        fielder->_218 = ++g_GameLogic.rosterLoc_skippingCap;
    }

    if (g_d_GameSettings.minigamesEnabled) {
        if (g_Minigame.battingHandedness[rosterID] <= 1) {
            fielder->fieldingArm = 0;
        } else {
            fielder->fieldingArm = 1;
        }
    }

    fielder->speed = char_stats->stats.Speed;
    if (fielder->speed > 200) {
        fielder->speed = 200;
    }
    lo = fielder->speed / 10 * 10;
    hi = lo + 10;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        fielder->_058 = LinearInterpolateToNewRange(fielder->speed, lo, hi, lbl_3_data_4640[1][lo / 10], lbl_3_data_4640[1][hi / 10]);
    } else {
        fielder->_058 = LinearInterpolateToNewRange(fielder->speed, lo, hi, lbl_3_data_4640[0][lo / 10], lbl_3_data_4640[0][hi / 10]);
    }
    fielder->_05C = fielder->_058 / fielder->_1D1;

    fielder->throwingArm = char_stats->stats.ThrowingArm;
    fielder->_1CD = fn_3_6E1D4(fielder->throwingArm);
    if (fielder->_1CD > 200) {
        fielder->_1CD = 200;
    }

    fielder->characterClass = char_stats->stats.CharacterClass;
    fielder->_1CB = 0;
    if (getFieldingStats(fielder->rosterID) & 1) {
        fielder->_1CB = 1;
    } else if ((getFieldingStats(fielder->rosterID) >> 1) & 1) {
        fielder->_1CB = 2;
    } else if (getFieldingStats(fielder->rosterID) & 4) {
        fielder->_1CB = 3;
    }

    fielder->_1CC = 0;
    if (getFieldingStats(fielder->rosterID) & 0x40) {
        fielder->_1CC = 1;
    }

    fielder->_0E8 = 0.01f * lbl_3_data_79B4.sizes[charID][0] * charSizeMultipliers[charID][0];
    fielder->_0EC = 0.01f * lbl_3_data_79B4.sizes[charID][1] * charSizeMultipliers[charID][0];
    fielder->_0F0 = 0.01f * lbl_3_data_79B4.sizes[charID][2] * charSizeMultipliers[charID][0];
    fielder->_0F4 = 0.01f * lbl_3_data_79B4.sizes[charID][3] * charSizeMultipliers[charID][0];
    fielder->_100 = 0.01f * lbl_3_data_79B4.sizes[charID][5] * charSizeMultipliers[charID][0];
    fielder->_104 = 0.01f * lbl_3_data_79B4.sizes[charID][6] * charSizeMultipliers[charID][0];
    fielder->_108 = 0.01f * lbl_3_data_79B4.sizes[charID][7] * charSizeMultipliers[charID][0];
    width = 0.01f * lbl_3_data_79B4.sizes[charID][2] * charSizeMultipliers[charID][0];
    third = width / 3.0f;
    fielder->_0F8 = width + third;
    fielder->_0FC = width - third;

    min = 0.01f * lbl_3_data_79B4.mins[0];
    if (fielder->_0E8 < min) {
        fielder->_0E8 = min;
    }
    min = 0.01f * lbl_3_data_79B4.mins[1];
    if (fielder->_0F4 < min) {
        fielder->_0F4 = min;
    }
    min = 0.01f * lbl_3_data_79B4.mins[3];
    if (fielder->_100 < min) {
        fielder->_100 = min;
    }
    min = 0.01f * lbl_3_data_79B4.mins[4];
    if (fielder->_104 < min) {
        fielder->_104 = min;
    }
    min = 0.01f * lbl_3_data_79B4.mins[5];
    if (fielder->_108 < min) {
        fielder->_108 = min;
    }

    fielder->_16C = 0.01f * lbl_3_data_7F10[charID] * charSizeMultipliers[charID][0];
}

// .text:0x0006E1D4 size:0x78 mapped:0x806AD268
u8 fn_3_6E1D4(u8 value) {
    int lo = value / 10 * 10;
    int hi = lo + 10;
    return LERPToNewRange_Float(value, lo, hi, lbl_3_data_4744[lo / 10], lbl_3_data_4744[hi / 10]);
}

// .text:0x0006DE60 size:0x374 mapped:0x806ACEF4
void setInMemBatterConstants(int rosterID) {
    int battingOrderCounter;
    int index;
    int batterID;

    CharacterStats* char_stats = &inMemRoster[g_GameLogic.teamBatting][rosterID];
    ChallengeTrackingStruct* starMissions = starMissionCompletionTracker;
    g_Batter.easyBatting = 0;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        if (g_Practice.practiceType_2 == 0 || g_Practice.practiceType_2 == 1 || g_Practice.practiceType_2 == 2 ||
            g_Practice.practiceType_2 == 3) {
            char_stats = inMemRoster[g_GameLogic.teamBatting];
        }
    } else if (g_d_GameSettings.minigamesEnabled) {
        rosterID = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.rosterID];
        char_stats = &inMemRoster[0][rosterID];
    } else {
        g_Batter.easyBatting =
            gameInitOptions.controlOptions[g_d_GameSettings.PlayerPorts[g_GameLogic.teamBatting] % 4].easyBatting;
    }

    g_Batter.rosterID = rosterID;
    g_Batter.charID = char_stats->stats.CharID;
    g_Batter.contactSize_raw[BAT_CONTACT_TYPE_SLAP] = char_stats->stats.SlapContactSize;
    g_Batter.contactSize_raw[BAT_CONTACT_TYPE_CHARGE] = char_stats->stats.ChargeContactSize;
    g_Batter.hitPower_raw[BAT_CONTACT_TYPE_SLAP] = char_stats->stats.SlapHitPower;
    g_Batter.hitPower_raw[BAT_CONTACT_TYPE_CHARGE] = char_stats->stats.ChargeHitPower;
    g_Batter.buntingContactSize = char_stats->stats.BuntingContactSize;
    g_Batter.trajectoryPushPull = char_stats->stats.HitTrajectoryPushPull;
    g_Batter.trajectoryHighLow = char_stats->stats.HitTrajectoryHighLow;
    g_Batter.batterHand = char_stats->stats.BattingStance;
    g_Batter.characterClass = char_stats->stats.CharacterClass;
    g_Batter.trimmedBat = BatterHitbox[g_Batter.charID].TrimmedBat;
    g_Batter.chemLinksOnBase = 0;
    g_Batter.aiLevel = g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.homeTeamBattingInd_fieldingTeam];

    if (g_d_GameSettings.minigamesEnabled) {
        g_Batter.captainStarHitPitch = 0;
        g_Batter.noncaptainStarSwing = 0;
    } else {
        g_Batter.captainStarHitPitch = (char_stats->stats).CaptainStarHitPitch;
        g_Batter.noncaptainStarSwing = (char_stats->stats).NonCaptainStarSwing;
    }

    if (!g_d_GameSettings.exhibitionMatchInd) {
        g_Batter.charIDForScoutFlagMission = -1;
        for (index = 0; index < 54; index++) {
            if ((g_Batter.charID == index) && (starMissions[index].variantClassification <= 3)) {
                g_Batter.charIDForScoutFlagMission = index;
                break;
            }
        }
    }

    if (g_d_GameSettings.minigamesEnabled) {
        s8 bVar1;
        // This should match target's struct access pattern
        if (g_Minigame.battingHandedness[rosterID] & 1) {
            g_Batter.batterHand = 1;
        } else {
            g_Batter.batterHand = 0;
        }

        bVar1 = g_Minigame.minigameControlStruct.characterIndex[rosterID];

        if (g_Minigame.minigameControlStruct.battingHandedness[bVar1] != 0) {
            g_Pitcher.aiLevel = aILevel[g_Minigame.minigameControlStruct.aIStrength[bVar1]];
        }
    }
}

// .text:0x0006D964 size:0x4FC mapped:0x806AC9F8
void fn_3_6D964(int rosterID, int runnerIdx) {
    int index;

    CharacterStats* char_stats = &inMemRoster[g_GameLogic.teamBatting][rosterID];
    InMemRunnerType* runner = &g_Runners[runnerIdx];
    ChallengeTrackingStruct* starMissions = starMissionCompletionTracker;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        if (g_Practice.practiceType_2 == 0 || g_Practice.practiceType_2 == 1 || g_Practice.practiceType_2 == 2 ||
            g_Practice.practiceType_2 == 3) {
            char_stats = &inMemRoster[g_GameLogic.teamBatting][rosterID];
        }
    } else if (g_d_GameSettings.minigamesEnabled) {
        char_stats = &inMemRoster[0][rosterID];
    }

    runner->rosterID = rosterID;
    runner->charID = char_stats->stats.CharID;
    runner->speed = char_stats->stats.Speed;
    runner->weight = char_stats->stats.Weight;
    runner->delayBeforeStartingToRun = lbl_3_data_775C;
    runner->aIStrength0Special3Weak = g_GameLogic.AIDifficulty0Special3Weak[g_GameLogic.homeTeamBattingInd_fieldingTeam];
    runner->characterClass = char_stats->stats.CharacterClass;
    if (runner->speed > 200) {
        runner->speed = 200;
    }

    if (!g_d_GameSettings.exhibitionMatchInd) {
        runner->unused_starMissionCharID = -1;
        for (index = 0; index < 54; index++) {
            if ((runner->charID == index) && (starMissions[index].variantClassification <= 3)) {
                runner->unused_starMissionCharID = index;
                break;
            }
        }
    }

    if (g_d_GameSettings.minigamesEnabled) {
        s8 bVar1 = g_Minigame.minigameControlStruct.characterIndex[rosterID];

        if (g_Minigame.minigameControlStruct.battingHandedness[bVar1] != 0) {
            runner->aIStrength0Special3Weak = aILevel[g_Minigame.minigameControlStruct.aIStrength[bVar1]];
        }
    }

    fn_3_6D6D4(runnerIdx);
}

// .text:0x0006D6D4 size:0x290 mapped:0x806AC768
void fn_3_6D6D4(int runnerIdx) {
    InMemRunnerType* runner = &g_Runners[runnerIdx];
    int lo = runner->speed / 10 * 10;
    int hi = lo + 10;
    f32 frames;

    runner->maximumBaseVelocity =
        LinearInterpolateToNewRange(runner->speed, lo, hi, runnerVelocityLookup[lo / 10], runnerVelocityLookup[hi / 10]);
    runner->baseAcceleration =
        LinearInterpolateToNewRange(runner->speed, 0.0f, 100.0f, lbl_3_data_4BC4[0], lbl_3_data_4BC4[1]);
    runner->baseAccelerationWhileChaingingDirection =
        LinearInterpolateToNewRange(runner->speed, 0.0f, 100.0f, lbl_3_data_4BC4[2], lbl_3_data_4BC4[3]);
    runner->maxMashVeloAdjustment =
        LinearInterpolateToNewRange(runner->speed, 0.0f, 100.0f, lbl_3_data_4BC4[4], lbl_3_data_4BC4[5]);
    frames = LinearInterpolateToNewRange(runner->speed, 0.0f, 100.0f, lbl_3_data_4BC4[6], lbl_3_data_4BC4[7]);
    runner->percentAddedPerMash = 1.0f / frames;
    frames = LinearInterpolateToNewRange(runner->speed, 0.0f, 100.0f, lbl_3_data_4BC4[8], lbl_3_data_4BC4[9]);
    runner->stamina_MashPercentTakenAwayPerFrame = 1.0f / frames;
    runner->FramesUntilNotSprinting = lbl_3_data_4C54[7];
}
