#include "game/rep_1188.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"

#include "static/UnknownHomes_Static.h"

extern u8 aILevel[4];
extern s16 lbl_3_data_460C[6];
extern u8 lbl_3_data_4744[24];
extern f32 lbl_3_data_4BC4[10];
extern f32 runnerVelocityLookup[22];
extern s16 lbl_3_data_4C54[12];

extern int LERPToNewRange_Float(int value, int inMin, int inMax, int outMin, int outMax);

// .text:0x0006EF1C size:0x5CC mapped:0x806ADFB0
void fn_3_6EF1C(void) {
    return;
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

// .text:0x0006E24C size:0x968 mapped:0x806AD2E0
void fn_3_6E24C(void) {
    return;
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
void fn_3_6D964(void) {
    return;
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
