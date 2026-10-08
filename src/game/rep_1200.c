#include "game/rep_1200.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"

#include "game/rep_1188.h"
#include "game/rep_DB8.h"
#include "game/rep_13B8.h"
#include "game/rep_1838.h"
#include "game/rep_540.h"
#include "game/rep_CC8.h"
#include "game/rep_31A0.h"
#include "game/rep_3880.h"
#include "game/rep_D18.h"
#include "game/rep_8C8.h"
#include "game/rep_940.h"
#include "game/rep_31F0.h"
#include "game/rep_3A98.h"
#include "game/rep_3DA8.h"
#include "game/m_sound.h"
#include "game/rep_D0.h"
#include "musyx/musyx.h"
#include "game/rep_2308.h"

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ u8 _50[0xAA - 0x50];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB;
    /* 0xAC */ u8 _AC;
    /* 0xAD */ u8 _AD;
    /* 0xAE */ u8 _AE[0xC7 - 0xAE];
    /* 0xC7 */ u8 _C7;
} g_Scores;

extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u8 _10;
} g_RunningLogic;

extern struct {
    /* 0x00 */ u8 _00[0x9C];
    /* 0x9C */ u8 _9C;
    /* 0x9D */ u8 _9D[0xB1 - 0x9D];
    /* 0xB1 */ u8 _B1;
    /* 0xB2 */ u8 _B2;
    /* 0xB3 */ u8 _B3;
    /* 0xB4 */ u8 _B4;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ s16 _06;
} lbl_3_common_bss_32220;

extern struct {
    /* 0x00 */ u8 _00[0x42];
    /* 0x42 */ s16 _42;
    /* 0x44 */ u8 _44[2];
    /* 0x46 */ u8 _46;
    /* 0x47 */ u8 _47;
    /* 0x48 */ u8 _48;
} lbl_3_common_bss_37400;

extern struct {
    /* 0x0000 */ u8 _0000[0x2D46];
    /* 0x2D46 */ u8 _2D46;
    /* 0x2D47 */ u8 _2D47[0x2D52 - 0x2D47];
    /* 0x2D52 */ u8 _2D52;
    /* 0x2D53 */ u8 _2D53[0x2D5E - 0x2D53];
    /* 0x2D5E */ u8 _2D5E;
} lbl_8036E548;

extern u8 lbl_803CBC3C[];

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;
extern u8 lbl_800E8558[][6];

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
} Rep540Friction; // size: 0x14

extern Rep540Friction lbl_3_data_4388[7];
extern f32 lbl_3_data_446C[2];
extern VecXZ lbl_3_data_450C[9];
extern s16 lbl_3_data_5D6C[][7];
extern f32 lbl_3_data_5E78[2];
extern f32 lbl_3_data_4474[4];
extern f32 lbl_3_data_5E98[6];
extern f32 lbl_3_data_5EB0[2];
extern f32 lbl_3_data_5EB8[3];
extern f32 lbl_3_data_5EC4[3];
extern f32 lbl_3_data_5ED0[3];
extern s16 lbl_3_data_5EDC[22];
extern f32 lbl_3_data_5F08[13];
extern u8 lbl_3_data_5F44[12];
extern u8 lbl_3_data_5F50[2][5];
extern f32 lbl_3_data_5F5C[8];
extern s16 lbl_3_data_5F7C[10];
extern s16 lbl_3_data_5F3C[4];
extern s16 lbl_3_data_5FC0[2];
extern f32 lbl_3_data_5F90[12];
extern f32 lbl_3_data_2138C[4];
extern u8 lbl_3_data_76FC[][3];
extern VecXYZ lbl_3_data_21380;

// .data 0x8080-0x8088: only this unit uses it, but splits.txt does not assign it here yet
extern s16 lbl_3_data_8080[4];

BOOL fn_8001C920(int charID);
extern int LERPToNewRange_Float(int value, int inMin, int inMax, int outMin, int outMax);
void fn_3_1DD48(void);
void fn_3_7A154(int arg);
void fn_3_7CE90(void);
void fn_3_7BC20(void);
void fn_3_7AB34(void);
extern void changeScene(u8, s16);
int fn_3_6D564(int team, int rosterID, int arg);

// .text 0x6F4E8-0x6F6CC: only this unit calls it, but splits.txt does not assign it here yet
BOOL fn_3_6F4E8(void);

static s32 lbl_3_bss_172C[7];
static s32 lbl_3_bss_1728;

// .text:0x00075560 size:0x45C mapped:0x806B45F4
void fn_3_75560(void) {
    if (fn_3_107DB4(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder])) {
        g_Pitcher.AIInd = 0;
    }
    if (g_Pitcher.currentStateFrameCounter < 0x7FFE) {
        g_Pitcher.currentStateFrameCounter++;
    } else {
        g_Pitcher.currentStateFrameCounter = 0x7FFF;
    }
    fn_3_A83C();
    switch (g_Pitcher.pitcherActionState) {
    case PITCHER_ACTION_STATE_TRANSITION:
        fn_3_75090();
        break;
    case PITCHER_ACTION_STATE_PRE_PITCH:
        fn_3_74D0C();
        break;
    case PITCHER_ACTION_STATE_WINDUP:
        fn_3_74128();
        break;
    case PITCHER_ACTION_STATE_IN_AIR:
        fn_3_73F2C();
        break;
    case PITCHER_ACTION_STATE_NO_CONTACT:
        fn_3_73DE8();
        break;
    case PITCHER_ACTION_STATE_HIT:
        fn_3_738A8();
        break;
    case PITCHER_ACTION_STATE_POST_HIT:
        fn_3_73718();
        break;
    case PITCHER_ACTION_STATE_HIT_BY_PITCH:
        fn_3_6FB98();
        break;
    }
}

// .text:0x000754B8 size:0xA8 mapped:0x806B454C
void fn_3_754B8(void) {
    fn_3_750C4(PITCHER_ACTION_STATE_NONE);
    g_Pitcher.pitchSpeedScaler = lbl_3_data_5F90[0];
    g_Pitcher.decelerationFactor = lbl_3_data_5F90[1];
    g_Pitcher.centerOfStrikeZone.x = 0.5f * (lbl_3_data_5E98[0] + lbl_3_data_5E98[1]);
    g_Pitcher.centerOfStrikeZone.z = 0.5f * (lbl_3_data_5E98[2] + lbl_3_data_5E98[3]);
    g_Pitcher.strikeZoneLeft = lbl_3_data_5E98[0];
    g_Pitcher.strikeZoneRight = lbl_3_data_5E98[1];
    g_Pitcher.beginningOfStrikeCheckZ = lbl_3_data_5E98[2];
    g_Pitcher.endingOfStrikeCheckZ = lbl_3_data_5E98[3];
    g_Pitcher.pitcher.x = lbl_3_data_446C[0];
    g_Pitcher.pitcher.z = lbl_3_data_446C[1];
    g_Pitcher.windupCountdownUntilBallReleased = 100;
    g_Pitcher.pitchWindUpCountDown = 100;
    g_Pitcher.curvePitchWindupFrames = 100;
    g_Pitcher.playStartOfGameAnimation = 1;
}

// .text:0x00075434 size:0x84 mapped:0x806B44C8
void fn_3_75434(void) {
    fn_3_6EBB4(g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]);
    fn_3_753E8(FALSE);
    if (g_Scores._00 == 1) {
        g_Pitcher.playStartOfGameAnimation = 1;
    }
}

// .text:0x000753E8 size:0x4C mapped:0x806B447C
void fn_3_753E8(BOOL keepAction) {
    fn_3_750C4(PITCHER_ACTION_STATE_NONE);
    if (!keepAction) {
        g_Pitcher.nPitchesThisAB = 0;
        g_Pitcher.nPickoffAttempts = 0;
    }
    g_Pitcher.pitcher.x = lbl_3_data_446C[0];
    g_Pitcher.pitcher.z = lbl_3_data_446C[1];
    g_Pitcher.pitchDeliveryAnimationPlaying = 0;
}

// .text:0x000751B4 size:0x234 mapped:0x806B4248
void fn_3_751B4(void) {
    fn_3_750C4(PITCHER_ACTION_STATE_NONE);
    g_Ball.fielderWBallIndex = 0;
    g_Pitcher.pitchSpeedScaler = lbl_3_data_5F90[0];
    g_Pitcher.decelerationFactor = lbl_3_data_5F90[1];
    g_Pitcher.centerOfStrikeZone.x = 0.5f * (lbl_3_data_5E98[0] + lbl_3_data_5E98[1]);
    g_Pitcher.centerOfStrikeZone.z = 0.5f * (lbl_3_data_5E98[2] + lbl_3_data_5E98[3]);
    g_Pitcher.strikeZoneLeft = lbl_3_data_5E98[0];
    g_Pitcher.strikeZoneRight = lbl_3_data_5E98[1];
    g_Pitcher.beginningOfStrikeCheckZ = lbl_3_data_5E98[2];
    g_Pitcher.endingOfStrikeCheckZ = lbl_3_data_5E98[3];
    g_Pitcher.ballCurrentPosition.x = lbl_3_data_450C[0].x;
    g_Pitcher.ballCurrentPosition.y = 1.0f;
    g_Pitcher.ballCurrentPosition.z = lbl_3_data_450C[0].z;
    g_Pitcher.ballVelocity.x = 0.0f;
    g_Pitcher.ballVelocity.y = 0.0f;
    g_Pitcher.ballVelocity.z = 0.0f;
    g_Pitcher.pitchStartingPosition_AIMaxCurve = g_Pitcher.centerOfStrikeZone.x;
    g_Pitcher.eggBallBounceYHeight = lbl_3_data_5E98[4];
    g_Pitcher.frontOfPlateZ = g_Pitcher.centerOfStrikeZone.z;
    g_Pitcher.pitchTotalTimeCounter = 0;
    g_Pitcher.strikeZoneProcessNumber = 0;
    g_Pitcher.frameBallCanStartBeingControlled = 0;
    g_Pitcher.pitchInAirInd = 0;
    g_Pitcher.calledStrikeInd = 0;
    g_Pitcher.strikeInd = 0;
    g_Pitcher.miniGameRelated = 0;
    g_Pitcher.pickOffLoc = -1;
    g_Pitcher.pitchDidntResultInLiveBallInd = 0;
    g_Pitcher.strikeOutOrWalk = 0;
    g_Pitcher.framesUntilPitchGetsToBatter = -1;
    g_Pitcher.pitchChargeUp = 0.0f;
    g_Pitcher.pitchChargeUpAnimationProportion = 0.0f;
    g_Pitcher.unknownFrameCounter = 0;
    g_Pitcher.ChargePitchType = 0;
    g_Pitcher.framesAHeldForChargePitches = 0;
    g_Pitcher.TypeOfPitch = 0;
    g_Pitcher.ballHaloTrainInd_unused = 0;
    g_Pitcher.overChargeInd = 0;
    g_Pitcher.starPitchInd = 0;
    g_Pitcher.starPitchType = 0;
    g_Pitcher.warioWaluStarAnimationStage = 0;
    g_Pitcher.windupCountdownUntilBallReleased = lbl_3_data_8080[0];
    g_Pitcher.warioWaluStarHasPlayedSound = 0;
    g_Pitcher.peachDaisyStarAnimationOn = 0;
    g_Pitcher.peachDaisyAnimationHappened = 0;
    g_Pitcher.anyCurveInput = 0;
    g_Pitcher.bulletPitchFrameCounter = 0;
    g_Pitcher.bulletPitchStageCode = 0;
    g_Pitcher.eggBallBounceNumber = 0;
    g_Pitcher.framesSinceFirstEggBounce = 0;
    g_Pitcher.pitcherOffCenter = 0;
    g_Pitcher.nonCaptainStarPitchTriggeredType = 0;
    g_Pitcher.walkedInRunInd = 0;
    g_Pitcher.unused_pitcherIsFielder = 0;
    g_Pitcher.starPitchPositionAdjustment.x = 0.0f;
    g_Pitcher.starPitchPositionAdjustment.y = 0.0f;
    g_Pitcher.starPitchPositionAdjustment.z = 0.0f;
    g_Pitcher.pitchWindUpCountDown = lbl_3_data_8080[1];
    g_Pitcher.curvePitchWindupFrames = lbl_3_data_8080[2];
    g_Pitcher.windupCountdownUntilBallReleased = g_Pitcher.pitchWindUpCountDown;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        g_Pitcher.AIInd = g_Practice.aIEnabled;
    } else if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY ||
               g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER) {
        g_Pitcher.AIInd = 1;
    } else if (g_d_GameSettings.minigamesEnabled) {
        g_Pitcher.AIInd = g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.minigamePlayerSelectedOrder];
    } else {
        g_Pitcher.AIInd = g_GameLogic._140[g_GameLogic.awayTeamBattingInd_battingTeam];
    }
    lbl_3_common_bss_34C58._34 = 0;
}

// .text:0x000750DC size:0xD8 mapped:0x806B4170
BOOL fn_3_750DC(void) {
    int charID = inMemRoster[g_GameLogic.teamFielding]
                            [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]]
                                .stats.CharID;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice.practiceType_2 != PRACTICE_TYPE_FREEPLAY) {
        charID = g_Pitcher.charID;
    }
    if (lbl_3_common_bss_32724._9C == 0) {
        lbl_803CBC3C[1] = 0;
        lbl_3_common_bss_32724._9C = 1;
    }
    if (lbl_3_common_bss_32724._9C == 1 && fn_8001C920(charID)) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000750C4 size:0x18 mapped:0x806B4158
void fn_3_750C4(u8 state) {
    g_Pitcher.pitcherActionState = state;
    g_Pitcher.currentStateFrameCounter = 0;
}

// .text:0x00075090 size:0x34 mapped:0x806B4124
void fn_3_75090(void) {
    fn_3_750C4(PITCHER_ACTION_STATE_PRE_PITCH);
    g_Ball.AtBat_Contact_BallPos.x = g_Pitcher.ballCurrentPosition.x;
    g_Ball.AtBat_Contact_BallPos.y = g_Pitcher.ballCurrentPosition.y;
    g_Ball.AtBat_Contact_BallPos.z = g_Pitcher.ballCurrentPosition.z;
}

// .text:0x00074D0C size:0x384 mapped:0x806B3DA0
void fn_3_74D0C(void) {
    InputStruct* input = &g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]];

    g_Ball.AtBat_Contact_BallPos.x = g_Pitcher.ballCurrentPosition.x;
    g_Ball.AtBat_Contact_BallPos.y = g_Pitcher.ballCurrentPosition.y;
    g_Ball.AtBat_Contact_BallPos.z = g_Pitcher.ballCurrentPosition.z;
    if (g_GameLogic.frameCountdownAtBeginningOfAtBatLockout != 0) {
        g_Pitcher.currentStateFrameCounter = 0;
        return;
    }
    if (g_Batter.beginningOfABAnimationOccuring) {
        g_Pitcher.currentStateFrameCounter = 0;
        return;
    }
    if (g_UnkSound_32718._07 == 12) {
        g_Pitcher.currentStateFrameCounter = 0;
        return;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && g_Minigame.toyfield_waitFor_CoinsX2_AnimationToEnd) {
        g_Pitcher.currentStateFrameCounter = 0;
        return;
    }
    if (lbl_8036E548._2D46) {
        return;
    }
    if (lbl_8036E548._2D52) {
        return;
    }
    if (lbl_8036E548._2D5E) {
        return;
    }
    if (!g_d_GameSettings.exhibitionMatchInd && lbl_3_common_bss_32724._B3) {
        return;
    }
    if (g_Pitcher.pitchDeliveryAnimationPlaying) {
        g_Pitcher.currentStateFrameCounter = 0;
        return;
    }
    if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_FIELDING && !g_Practice.hitVariablesSetIndicator) {
        return;
    }
    if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_BASERUNNING && !g_Practice._1EC) {
        return;
    }
    if (g_d_GameSettings.minigamesEnabled) {
        if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY) {
            fn_3_1118B4();
            return;
        }
        if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER) {
            fn_3_1118B4();
            return;
        }
        input = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
        if (fn_3_107DB4(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder])) {
            input = &g_Minigame._1D7C[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
        }
        if (g_Pitcher.AIInd) {
            fn_3_215AC();
            return;
        }
    } else {
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice.practiceLevel == 4) {
            fn_3_15AD94();
            return;
        }
        if (ACTIVE_TUTORIAL()) {
            input = &g_Practice.inputs[g_GameLogic.teamFielding];
        }
        if (fn_3_6F748()) {
            return;
        }
        if (g_Pitcher.AIInd) {
            fn_3_215AC();
            return;
        }
    }
    fn_3_74AC4();
    if (input->newButtonInput & INPUT_BUTTON_A) {
        if (!g_d_GameSettings.minigamesEnabled && (input->buttonInput & INPUT_TRIGGER_R)) {
            g_Pitcher.starPitchInd = 1;
        }
        if (!g_Pitcher.starPitchInd && (input->buttonInput & INPUT_BUTTON_DOWN)) {
            g_Pitcher.TypeOfPitch = 2;
        } else {
            g_Pitcher.framesAHeldForChargePitches = 1;
        }
        fn_3_750C4(PITCHER_ACTION_STATE_WINDUP);
        g_Stats._38 = 1;
    }
}

// .text:0x00074AC4 size:0x248 mapped:0x806B3B58
void fn_3_74AC4(void) {
    InputStruct* input = &g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]];
    f32 step = 0.0f;

    if (ACTIVE_TUTORIAL()) {
        input = &g_Practice.inputs[g_GameLogic.teamFielding];
    } else if (fn_3_107DB4(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder])) {
        input = &g_Minigame._1D7C[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
    } else if (g_d_GameSettings.minigamesEnabled) {
        input = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
    }
    if (input->buttonInput & INPUT_TRIGGER_L) {
        g_Pitcher.pitcherOffCenter = 1;
    }
    if (g_Pitcher.pitcherOffCenter) {
        if (g_Pitcher.pitcher.x >= -lbl_3_data_4474[3] && g_Pitcher.pitcher.x <= lbl_3_data_4474[3]) {
            g_Pitcher.pitcherOffCenter = 0;
            g_Pitcher.pitcher.x = 0.0f;
        } else if (g_Pitcher.pitcher.x < 0.0f) {
            g_Pitcher.pitcher.x += lbl_3_data_4474[3];
        } else {
            g_Pitcher.pitcher.x -= lbl_3_data_4474[3];
        }
    } else {
        if (input->buttonInput & INPUT_BUTTON_LEFT) {
            step = -lbl_3_data_4474[2];
        } else if (input->buttonInput & INPUT_BUTTON_RIGHT) {
            step = lbl_3_data_4474[2];
        }
        g_Pitcher.pitcher.x += step;
        if (g_Pitcher.pitcher.x < lbl_3_data_4474[0]) {
            g_Pitcher.pitcher.x = lbl_3_data_4474[0];
        }
        if (g_Pitcher.pitcher.x > lbl_3_data_4474[1]) {
            g_Pitcher.pitcher.x = lbl_3_data_4474[1];
        }
    }
}

// .text:0x00074128 size:0x99C mapped:0x806B31BC
void fn_3_74128(void) {
    InputStruct* input = &g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]];

    if (ACTIVE_TUTORIAL()) {
        input = &g_Practice.inputs[g_GameLogic.teamFielding];
    } else if (fn_3_107DB4(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder])) {
        input = &g_Minigame._1D7C[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
    } else if (g_d_GameSettings.minigamesEnabled && g_Minigame.minigamePlayerSelectedOrder >= 0) {
        input = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
    }
    if (g_Pitcher.framesAHeldForChargePitches) {
        g_Pitcher.framesAHeldForChargePitches++;
        if ((g_Pitcher.AIInd == 0 && !(input->buttonInput & INPUT_BUTTON_A)) ||
            (g_Pitcher.AIInd == 1 && g_AiLogic.aIPitchType == 0)) {
            g_Pitcher.ChargePitchType = 0;
        } else {
            g_Pitcher.ChargePitchType = 1;
        }
        if (g_Pitcher.framesAHeldForChargePitches >= lbl_3_data_5F3C[0]) {
            g_Pitcher.framesAHeldForChargePitches = 0;
            goto windup;
        }
        return;
    }
windup:
    if (g_Pitcher.pitchTotalTimeCounter < 0x7FFE) {
        g_Pitcher.pitchTotalTimeCounter++;
    } else {
        g_Pitcher.pitchTotalTimeCounter = 0x7FFF;
    }
    if (g_Pitcher.pitchTotalTimeCounter == 1) {
        if (g_Pitcher.starPitchInd && !g_d_GameSettings.minigamesEnabled &&
            g_GameLogic.TeamStars[g_GameLogic.teamFielding] &&
            fn_3_6D564(g_GameLogic.teamFielding, g_Pitcher.rosterID, 0) >= lbl_3_data_5EDC[4] &&
            (gameInitOptions.starSkillsSetting || g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE)) {
            if (!g_Pitcher.captainStarPitch) {
                if (g_GameLogic.TeamStars[g_GameLogic.teamFielding] >= starPowerCosts.regularStarCost &&
                    g_Pitcher.nonCaptainStarPitch) {
                    fn_3_740D0();
                } else {
                    g_Pitcher.starPitchInd = 0;
                }
            } else if (g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamFielding] != g_Pitcher.rosterID &&
                       g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
                if (g_GameLogic.TeamStars[g_GameLogic.teamFielding] >= starPowerCosts.nonCaptain_CaptainStarCost) {
                    g_Pitcher.starPitchType = g_Pitcher.captainStarPitch;
                } else {
                    g_Pitcher.starPitchInd = 0;
                }
            } else if (g_GameLogic.TeamStars[g_GameLogic.teamFielding] >= starPowerCosts.captainStarCost) {
                g_Pitcher.starPitchType = g_Pitcher.captainStarPitch;
            } else {
                g_Pitcher.starPitchInd = 0;
            }
        }
        fn_3_73FAC();
        g_Pitcher.unknownFrameCounter = 0;
        g_Pitcher.pitchChargeUp = 0.0f;
        g_Pitcher.pitchChargeUpAnimationProportion = 0.0f;
    }
    if (g_Pitcher.AIInd) {
        if (g_AiLogic.aIPitchType == 1 || g_AiLogic.aIPitchType == 3) {
            if (g_AiLogic.aIPitchType != 3) {
                if (g_AiLogic.aIPerfectCharge) {
                    g_Pitcher.ChargePitchType = 3;
                } else {
                    g_Pitcher.ChargePitchType = 2;
                }
            }
            g_Pitcher.pitchChargeUp = 1.0f;
            g_Pitcher.unknownFrameCounter++;
            g_Pitcher.pitchChargeUpAnimationProportion =
                1.0f - (f32)(g_Pitcher.windupCountdownUntilBallReleased - 1) / (f32)g_Pitcher.pitchWindUpCountDown;
            if (g_Pitcher.pitchChargeUpAnimationProportion > 1.0f) {
                g_Pitcher.pitchChargeUpAnimationProportion = 1.0f;
            }
        } else if (g_Pitcher.starPitchInd) {
            g_Pitcher.unknownFrameCounter++;
        }
    } else if (g_Pitcher.ChargePitchType == 1 || g_Pitcher.starPitchInd || g_Pitcher.ballHaloTrainInd_unused) {
        if ((g_Pitcher.AIInd == 0 && (input->buttonInput & INPUT_BUTTON_A)) ||
            (g_Pitcher.AIInd == 1 && g_AiLogic.aIPitchType == 1) || g_Pitcher.starPitchInd ||
            g_Pitcher.ballHaloTrainInd_unused) {
            g_Pitcher.unknownFrameCounter++;
        } else {
            g_Pitcher.ChargePitchType = 2;
            if (g_Pitcher.windupCountdownUntilBallReleased < lbl_3_data_5F3C[2]) {
                g_Pitcher.ChargePitchType = 3;
                if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_WALLBALL) {
                    playSoundEffect(0x1B5);
                } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE &&
                           (g_Practice.practiceLevel == 5 ||
                            (g_Practice.practiceType_2 == PRACTICE_TYPE_PITCHING && g_Practice.practiceLevel == 1))) {
                    playSoundEffect(0x1B5);
                }
            } else if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_WALLBALL) {
                playSoundEffect(0x1B4);
            } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE &&
                       (g_Practice.practiceLevel == 5 ||
                        (g_Practice.practiceType_2 == PRACTICE_TYPE_PITCHING && g_Practice.practiceLevel == 1))) {
                playSoundEffect(0x1B4);
            }
        }
        if (g_Pitcher.ChargePitchType) {
            g_Pitcher.pitchChargeUp =
                1.0f - (f32)(g_Pitcher.windupCountdownUntilBallReleased - 1) / (f32)g_Pitcher.pitchWindUpCountDown;
            if (g_Pitcher.pitchChargeUp > 1.0f) {
                g_Pitcher.pitchChargeUp = 1.0f;
            }
        } else {
            g_Pitcher.pitchChargeUp = 0.0f;
        }
        g_Pitcher.pitchChargeUpAnimationProportion = g_Pitcher.pitchChargeUp;
    } else if (g_Pitcher.ChargePitchType || g_Pitcher.TypeOfPitch == 2) {
        g_Pitcher.pitchChargeUpAnimationProportion =
            1.0f - (f32)(g_Pitcher.windupCountdownUntilBallReleased - 1) / (f32)g_Pitcher.pitchWindUpCountDown;
        if (g_Pitcher.pitchChargeUpAnimationProportion > 1.0f) {
            g_Pitcher.pitchChargeUpAnimationProportion = 1.0f;
        }
    }
    if (--g_Pitcher.windupCountdownUntilBallReleased <= 0) {
        if (g_Pitcher.ChargePitchType == 1) {
            g_Pitcher.pitchChargeUp = RandomF32_Game_Range(lbl_3_data_5F08[11], lbl_3_data_5F08[12]);
            g_Pitcher.overChargeInd = 1;
        }
        fn_3_7310C();
        if (g_Pitcher.ChargePitchType == 3) {
            g_UnkSound_32718._08 = 1;
            fn_3_CAF9C();
        }
        if (g_Pitcher.specialPitchTypeCode != 1 && g_Pitcher.specialPitchTypeCode != 2 &&
            g_Pitcher.specialPitchTypeCode != 3 && !g_Pitcher.nonCaptainStarPitchTriggeredType &&
            g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
            g_GameLogic.PauseSimulationFrameCount = lbl_3_data_5FC0[1];
        } else {
            g_GameLogic.PauseSimulationFrameCount = lbl_3_data_5FC0[0];
        }
        if (g_GameLogic.PauseSimulationFrameCount) {
            lbl_80366158._28 = 1;
        }
        fn_3_750C4(PITCHER_ACTION_STATE_IN_AIR);
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES &&
            g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY && !g_Minigame.bOD_KingBombInd) {
            fn_3_156218();
        }
    }
    g_Ball.AtBat_Contact_BallPos.x = g_Pitcher.ballCurrentPosition.x;
    g_Ball.AtBat_Contact_BallPos.y = g_Pitcher.ballCurrentPosition.y;
    g_Ball.AtBat_Contact_BallPos.z = g_Pitcher.ballCurrentPosition.z;

}

// .text:0x000740D0 size:0x58 mapped:0x806B3164
void fn_3_740D0(void) {
    g_Pitcher.nonCaptainStarPitchTriggeredType = g_Pitcher.nonCaptainStarPitch;
    switch (g_Pitcher.nonCaptainStarPitchTriggeredType) {
    case 1:
        g_Pitcher.specialPitchTypeCode = 0x10;
        break;
    case 2:
        g_Pitcher.specialPitchTypeCode = 0x11;
        break;
    case 3:
        g_Pitcher.specialPitchTypeCode = 0x12;
        break;
    }
}

// .text:0x00073FAC size:0x124 mapped:0x806B3040
void fn_3_73FAC(void) {
    g_Pitcher.eggBallBounceYHeight = g_Batter.batPosition2.y;
    g_Pitcher.pitchStartingPosition_AIMaxCurve = LinearInterpolateToNewRange(
        g_Pitcher.pitcher.x, lbl_3_data_4474[0], lbl_3_data_4474[1], lbl_3_data_5EB0[0], lbl_3_data_5EB0[1]);
    if (g_Pitcher.starPitchType == 3 || g_Pitcher.starPitchType == 4) {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = 0.0f;
    } else if (g_Pitcher.starPitchType == 9 || g_Pitcher.starPitchType == 10) {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = RandomF32_Game_Range(-lbl_3_data_5F5C[3], lbl_3_data_5F5C[3]);
        g_Pitcher.eggBallBounceYHeight = lbl_3_data_5F5C[0];
        g_Pitcher.frontOfPlateZ = RandomF32_Game_Range(lbl_3_data_5F5C[1], lbl_3_data_5F5C[2]);
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY ||
        g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER) {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = RandomF32_Game_Range(
            -lbl_3_data_2138C[g_Minigame.soloMinigameDifficulty], lbl_3_data_2138C[g_Minigame.soloMinigameDifficulty]);
    }
}

// .text:0x00073F2C size:0x80 mapped:0x806B2FC0
void fn_3_73F2C(void) {
    if (g_Pitcher.pitchTotalTimeCounter < 0x7FFE) {
        g_Pitcher.pitchTotalTimeCounter++;
    } else {
        g_Pitcher.pitchTotalTimeCounter = 0x7FFF;
    }
    if (g_Ball.pitchHangtimeCounter < 0x7FFE) {
        g_Ball.pitchHangtimeCounter++;
    } else {
        g_Ball.pitchHangtimeCounter = 0x7FFF;
    }
    g_Pitcher.warioWaluStarAnimationStage = 0;
    fn_3_71248();
}

// .text:0x00073DE8 size:0x144 mapped:0x806B2E7C
void fn_3_73DE8(void) {
    if (g_Pitcher.pitchTotalTimeCounter < 0x7FFE) {
        g_Pitcher.pitchTotalTimeCounter++;
    } else {
        g_Pitcher.pitchTotalTimeCounter = 0x7FFF;
    }
    if (g_Ball.postPitchResultCounter < 0x7FFE) {
        g_Ball.postPitchResultCounter++;
    } else {
        g_Ball.postPitchResultCounter = 0x7FFF;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES &&
        (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY ||
         g_Minigame.GameMode_MiniGame == MINI_GAME_ID_WALLBALL ||
         g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER)) {
        g_Pitcher.miniGameRelated = 1;
        if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY) {
            fn_3_155288();
        }
    } else if (!g_Pitcher.miniGameRelated) {
        fn_3_703EC();
        return;
    }
    if (fn_3_6F4E8()) {
        return;
    }
    if (!(g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice.guidedPracticeCompletionRelated)) {
        if (g_Pitcher.currentStateFrameCounter > 75) {
            g_GameLogic.playBatterWalkupAnimation = 0;
            fn_3_5A6D4(0);
        }
    }
    fn_3_7CE90();
}

// .text:0x000738A8 size:0x540 mapped:0x806B293C
// Registers only: g_Scores._C7 and &g_Scores._04 swap r5/r6. The permuter matched it with
// `... + 1 >= (margin = g_Scores._C7)` (a u8 local), which no programmer would write.
void fn_3_738A8(void) {
    int endFrame = 120;

    if (g_Pitcher.pitchTotalTimeCounter < 0x7FFE) {
        g_Pitcher.pitchTotalTimeCounter++;
    } else {
        g_Pitcher.pitchTotalTimeCounter = 0x7FFF;
    }
    if (g_Pitcher.framesSinceAtBatEnded < 0x7FFE) {
        g_Pitcher.framesSinceAtBatEnded++;
    } else {
        g_Pitcher.framesSinceAtBatEnded = 0x7FFF;
    }
    if (g_d_GameSettings.minigamesEnabled) {
        return;
    }
    if (g_GameLogic.gameOverInd) {
        endFrame = 195;
    } else if (g_Batter.hitByPitch) {
        endFrame = 90;
    } else {
        if (g_Ball.postPitchResultCounter < 0x7FFE) {
            g_Ball.postPitchResultCounter++;
        } else {
            g_Ball.postPitchResultCounter = 0x7FFF;
        }
        if (fn_3_6F4E8()) {
            return;
        }
    }
    if (g_Pitcher.framesSinceAtBatEnded == 1) {
        if (!g_d_GameSettings.exhibitionMatchInd && lbl_3_common_bss_37400._46 && !g_Stats.replayInd) {
            fn_3_164A74();
            lbl_3_common_bss_37400._42 = 180;
        }
        if ((g_Pitcher.strikeOutOrWalk == 2 || g_Pitcher.strikeOutOrWalk == 3) && g_RunningLogic._10 == 4) {
            if (g_Scores._AD) {
                if (g_Scores._00 >= g_Scores._AA && g_Scores._04[0][0] == g_Scores._04[1][0]) {
                    fn_3_59918(13, 0);
                    g_GameLogic.gameOverInd = 1;
                } else if (g_Scores._C7 &&
                           g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] -
                                   g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0] + 1 >=
                               g_Scores._C7) {
                    fn_3_59918(17, 0);
                    g_GameLogic.gameOverInd = 1;
                }
            }
            g_Pitcher.walkedInRunInd = 1;
        }
    }
    if (!g_d_GameSettings.exhibitionMatchInd && lbl_3_common_bss_37400._46 && !g_Stats.replayInd &&
        !lbl_3_common_bss_37400._48) {
        if (--lbl_3_common_bss_37400._42 == 120) {
            lbl_3_common_bss_32724._B4 = 1;
        }
        endFrame = 120;
    }
    if (g_Pitcher.framesSinceAtBatEnded == 1) {
        if (endFrame > 120) {
            lbl_3_common_bss_34C58._2A = 1;
            lbl_3_common_bss_34C58._24 = 119;
        } else {
            lbl_3_common_bss_34C58._2A = 1;
            lbl_3_common_bss_34C58._24 = endFrame - 1;
        }
    }
    if (g_Pitcher.framesSinceAtBatEnded == endFrame - 11) {
        if (!lbl_3_common_bss_32724._B1) {
            changeScene(3, 6);
        }
    } else if (g_Pitcher.framesSinceAtBatEnded == endFrame - 31) {
        if (lbl_3_common_bss_32220._06 > 29) {
            g_Pitcher.framesSinceAtBatEnded--;
        } else {
            fn_3_7BC20();
            if (g_Stats._39) {
                lbl_3_common_bss_32724._B1 = 1;
            }
        }
    } else if (g_Pitcher.framesSinceAtBatEnded >= endFrame) {
        g_GameLogic.hudLoadingRelated = 1;
        fn_3_73718();
        fn_3_750C4(PITCHER_ACTION_STATE_POST_HIT);
        if (g_Pitcher.strikeOutOrWalk == 1) {
            fn_3_73850();
        } else if (g_Pitcher.strikeOutOrWalk == 2 || g_Pitcher.strikeOutOrWalk == 3) {
            fn_3_735A8();
        }
        if (g_Stats._39) {
            fn_3_8C07C();
        }
    }
}

// .text:0x00073850 size:0x58 mapped:0x806B28E4
void fn_3_73850(void) {
    int i;

    g_Strikes.outs++;
    for (i = 0; i < 3; i++) {
        if (g_Strikes.runnerIndexForEachOutThisPitch[i] == -1) {
            g_Strikes.runnerIndexForEachOutThisPitch[i] = 0;
            return;
        }
    }
}

// .text:0x0007372C size:0x124 mapped:0x806B27C0
void fn_3_7372C(void) {
    int i;
    BOOL blocked = FALSE;

    if (g_Pitcher.strikeOutOrWalk == 3) {
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
                if (!blocked) {
                    g_Runners[i].currentBase = i;
                    fn_3_89864(i, 1);
                } else {
                    g_Runners[i].currentBase = g_Runners[i].startingBase_baseAchieved;
                    g_Runners[i].nextBase = (g_Runners[i].currentBase + 1) & 3;
                }
            } else {
                blocked = TRUE;
            }
        }
    } else {
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
                if (i == g_Runners[i].currentBase) {
                    fn_3_89864(i, 1);
                }
            } else {
                break;
            }
        }
    }
    g_Runners[0].currentBase = 1;
    g_Runners[0].nextBase = 2;
}

// .text:0x00073718 size:0x14 mapped:0x806B27AC
void fn_3_73718(void) {
    g_Ball.postPitchResultCounter = -1;
}

// .text:0x000736CC size:0x4C mapped:0x806B2760
void fn_3_736CC(void) {
    int i;

    for (i = 0; i < 3; i++) {
        if (g_Strikes.runnerIndexForEachOutThisPitch[i] == -1) {
            g_Strikes.runnerIndexForEachOutThisPitch[i] = 0;
            return;
        }
    }
}

// .text:0x000735A8 size:0x124 mapped:0x806B263C
void fn_3_735A8(void) {
    int i;
    BOOL blocked = FALSE;

    if (g_Pitcher.strikeOutOrWalk == 3) {
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
                if (!blocked) {
                    g_Runners[i].currentBase = i;
                    fn_3_89864(i, 1);
                } else {
                    g_Runners[i].currentBase = g_Runners[i].startingBase_baseAchieved;
                    g_Runners[i].nextBase = (g_Runners[i].currentBase + 1) & 3;
                }
            } else {
                blocked = TRUE;
            }
        }
    } else {
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 5) {
                if (i == g_Runners[i].currentBase) {
                    fn_3_89864(i, 1);
                }
            } else {
                break;
            }
        }
    }
    g_Runners[0].currentBase = 1;
    g_Runners[0].nextBase = 2;
}

// .text:0x0007310C size:0x49C mapped:0x806B21A0
void fn_3_7310C(void) {
    VecXYZ release;
    int port;

    if (g_Pitcher.starPitchInd) {
        if (g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE || g_Practice.practiceLevel == 7) {
            if (g_Pitcher.nonCaptainStarPitchTriggeredType) {
                if (g_GameLogic.TeamStars[g_GameLogic.teamFielding] >= starPowerCosts.regularStarCost) {
                    g_GameLogic.TeamStars[g_GameLogic.teamFielding] -= starPowerCosts.regularStarCost;
                } else {
                    g_GameLogic.TeamStars[g_GameLogic.teamFielding] = 0;
                }
            } else if (g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamFielding] != g_Pitcher.rosterID &&
                       g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
                if (g_GameLogic.TeamStars[g_GameLogic.teamFielding] >= starPowerCosts.nonCaptain_CaptainStarCost) {
                    g_GameLogic.TeamStars[g_GameLogic.teamFielding] -= starPowerCosts.nonCaptain_CaptainStarCost;
                } else {
                    g_GameLogic.TeamStars[g_GameLogic.teamFielding] = 0;
                }
            } else {
                if (g_GameLogic.TeamStars[g_GameLogic.teamFielding] >= starPowerCosts.captainStarCost) {
                    g_GameLogic.TeamStars[g_GameLogic.teamFielding] -= starPowerCosts.captainStarCost;
                } else {
                    g_GameLogic.TeamStars[g_GameLogic.teamFielding] = 0;
                }
            }
        }
        g_AiLogic.nStarPitchesThrownThisAB++;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        if (g_Minigame.miniGameTurnCounter < 0xFE) {
            g_Minigame.miniGameTurnCounter++;
        } else {
            g_Minigame.miniGameTurnCounter = 0xFF;
        }
        if (g_Minigame.bB_pitchesRemainingInTurn) {
            g_Minigame.bB_pitchesRemainingInTurn--;
        }
    }
    port = 0;
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY ||
        g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER ||
        (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice.practiceLevel == 4)) {
        release.x = lbl_3_data_21380.x;
        release.y = lbl_3_data_21380.y;
        release.z = lbl_3_data_21380.z;
        release.y = -release.y;
    } else {
        if (g_d_GameSettings.minigamesEnabled) {
            port = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        }
        if (g_Pitcher.charID == 0x26) {
            getAnimRelatedCoordinates(port, 9, &release);
        } else if (!g_Pitcher.handedness) {
            getAnimRelatedCoordinates(port, 0x19, &release);
        } else {
            getAnimRelatedCoordinates(port, 0x13, &release);
        }
    }
    g_Pitcher.pitchRelease.x = g_Pitcher.ballCurrentPosition.x = release.x;
    g_Pitcher.pitchRelease.y = g_Pitcher.ballCurrentPosition.y = -release.y;
    g_Pitcher.pitchRelease.z = g_Pitcher.ballCurrentPosition.z = release.z;
    if (g_Pitcher.nonCaptainStarPitchTriggeredType) {
        g_Pitcher.TypeOfPitch = 0;
    } else if (g_Pitcher.starPitchType) {
        g_Pitcher.specialPitchTypeCode = g_Pitcher.starPitchType + 3;
        g_Pitcher.TypeOfPitch = lbl_3_data_5F44[g_Pitcher.specialPitchTypeCode - 4];
    } else if (g_Pitcher.TypeOfPitch == 2) {
        g_Pitcher.specialPitchTypeCode = 3;
    } else {
        g_Pitcher.specialPitchTypeCode = 1;
        if (g_Pitcher.ChargePitchType >= 1) {
            g_Pitcher.TypeOfPitch = 1;
        } else {
            g_Pitcher.TypeOfPitch = 0;
        }
    }
    fn_3_72CA8();
    fn_3_72768();
    g_Ball.framesSinceHit = -1;
    g_Ball.pitchHangtimeCounter = 0;
    g_Ball.postPitchResultCounter = -1;
    g_Ball.fielderWBallIndex = -1;
    g_Ball.AtBat_ContactResult = 0;
    g_Ball.ballState = 0;
    g_Pitcher.pitchCurveVeloV1 = 0.0f;
    g_Pitcher._60 = 0.0f;
    g_Pitcher.pitchCurveVeloV2 = 0.0f;
    g_Pitcher._68 = 0.0f;
    g_Pitcher.cancelParabolicAdjustmentInd = 0;
    g_Pitcher.strikeZoneProcessNumber = 0;
    g_Pitcher.nPickoffAttempts = 0;
    g_Pitcher._10C[1] = 0.0f;
    g_Pitcher._10C[2] = 0.0f;
    g_Minigame._1911 = 0;
    sndFXKeyOff(lbl_3_bss_172C[0]);
    fn_3_20064();
    if (g_Pitcher.nPitchesThisAB < 0xFE) {
        g_Pitcher.nPitchesThisAB++;
    } else {
        g_Pitcher.nPitchesThisAB = 0xFF;
    }
    fn_3_71248();
    fn_3_7AB34();
    if (!g_Pitcher.AIInd &&
        (g_Pitcher.ChargePitchType == 3 || g_Pitcher.nonCaptainStarPitchTriggeredType || g_Pitcher.starPitchType)) {
        if (g_d_GameSettings.minigamesEnabled) {
            fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder], 2);
        } else {
            fn_3_6C854(g_GameLogic.teamFielding, 2);
        }
    }
}

// .text:0x00072CA8 size:0x464 mapped:0x806B1D3C
void fn_3_72CA8(void) {
    f32 cursed = g_Pitcher.cursedBallStat;
    f32 control = g_Pitcher.curveControlStat;
    f32 curve = g_Pitcher.curveStat;
    f32 t;

    if (g_Pitcher.starPitchType) {
        g_Pitcher.pitchSpeed = lbl_3_data_5D6C[g_Pitcher.specialPitchTypeCode][0];
        g_Pitcher.calced_cursedBall = 100;
        g_Pitcher.calced_curveControl = 100;
        g_Pitcher.calced_curve = 100;
        if (g_Pitcher.starPitchType == 9 || g_Pitcher.starPitchType == 10) {
            g_Pitcher.pitchSpeed = RandomInt_Game_Range(lbl_3_data_5F7C[0], lbl_3_data_5F7C[1]);
        }
        return;
    }
    if (g_Pitcher.ChargePitchType == 3 || g_Pitcher.nonCaptainStarPitchTriggeredType == 2) {
        g_Pitcher.pitchSpeed = g_Pitcher.fastBallSpeed * lbl_3_data_5F08[10];
    } else if (g_Pitcher.ChargePitchType != 0) {
        if (g_Pitcher.ChargePitchType == 1) {
            g_Pitcher.ChargePitchType = 2;
        }
        t = lbl_3_data_5F08[9] * ((f32)g_Pitcher.fastBallSpeed - (f32)g_Pitcher.curveBallSpeed);
        t *= 1.0f - g_Pitcher.pitchChargeUp;
        g_Pitcher.pitchSpeed = g_Pitcher.fastBallSpeed - (int)t;
    } else if (g_Pitcher.TypeOfPitch == 2) {
        g_Pitcher.pitchSpeed = g_Pitcher.curveBallSpeed;
    } else {
        g_Pitcher.pitchSpeed = g_Pitcher.curveBallSpeed;
    }
    if (g_Pitcher.ChargePitchType >= 2 || g_Pitcher.TypeOfPitch == 2 || g_Pitcher.nonCaptainStarPitchTriggeredType == 2 ||
        g_Pitcher.nonCaptainStarPitchTriggeredType == 3) {
        cursed *= lbl_3_data_5F08[8];
        control *= lbl_3_data_5F08[5];
        curve *= lbl_3_data_5F08[2];
    }
    if (g_Pitcher.nonCaptainStarPitchTriggeredType == 0 &&
        fn_3_6D564(g_GameLogic.teamFielding, g_Pitcher.rosterID, 0) < lbl_3_data_5EDC[3]) {
        if (g_Pitcher.ChargePitchType) {
            g_Pitcher.pitchSpeed = g_Pitcher.pitchSpeed * (1.0f - 0.01f * lbl_3_data_5EDC[6]);
        } else if (g_Pitcher.TypeOfPitch != 2) {
            curve *= 1.0f - 0.01f * lbl_3_data_5EDC[5];
        }
        control *= 1.0f - 0.01f * lbl_3_data_5EDC[7];
        cursed *= 1.0f - 0.01f * lbl_3_data_5EDC[8];
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY ||
        g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER) {
        g_Pitcher.pitchSpeed = g_Minigame.minigamePitchSpeedAdjustment;
    }
    g_Pitcher.calced_cursedBall = cursed;
    g_Pitcher.calced_curveControl = control;
    g_Pitcher.calced_curve = curve;
}

// .text:0x00072768 size:0x540 mapped:0x806B17FC
// The setup before the frame loop is scheduled differently (the target loads cur.z once for
// dz and the loop, and 18.44f early); the loop and everything after it match.
void fn_3_72768(void) {
    InputStruct* input = &g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]];
    s16* pitchData;
    int frame;
    f32 z;
    f32 vz;
    f32 slowedVz;
    f32 half;
    int bullet;

    if (ACTIVE_TUTORIAL()) {
        input = &g_Practice.inputs[g_GameLogic.teamFielding];
    } else if (fn_3_107DB4(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder])) {
        input = &g_Minigame._1D7C[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
    } else if (g_d_GameSettings.minigamesEnabled && g_Minigame.minigamePlayerSelectedOrder >= 0) {
        input = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
    }
    pitchData = lbl_3_data_5D6C[g_Pitcher.specialPitchTypeCode];
    z = g_Pitcher.ballCurrentPosition.z;
    g_Pitcher.ballVelocity.z = -(g_Pitcher.pitchSpeed / g_Pitcher.pitchSpeedScaler);
    g_Pitcher.moundZ = 18.44f;
    g_Pitcher.ballVelocity.x = -((g_Pitcher.pitchStartingPosition_AIMaxCurve - g_Pitcher.ballCurrentPosition.x) *
                                 g_Pitcher.ballVelocity.z /
                                 (g_Pitcher.ballCurrentPosition.z - g_Pitcher.frontOfPlateZ));
    g_Pitcher.pitchZ_whenAirResistanceStarts = g_Pitcher.moundZ * (100 - pitchData[4]) / 100.0f;
    g_Pitcher.ballVelocity.y = -((g_Pitcher.eggBallBounceYHeight - g_Pitcher.ballCurrentPosition.y) *
                                 g_Pitcher.ballVelocity.z /
                                 (g_Pitcher.ballCurrentPosition.z - g_Pitcher.frontOfPlateZ));
    g_Pitcher.airResistance_veloAdj = 0.001f * pitchData[3];
    vz = g_Pitcher.ballVelocity.z;
    for (frame = 1; frame < 0xFFFF; frame++) {
        if (z <= g_Pitcher.moundZ && !g_Pitcher.pitchInAirInd) {
            g_Pitcher.pitchInAirInd = frame;
        }
        if (z <= g_Pitcher.pitchZ_whenAirResistanceStarts) {
            if (!g_Pitcher.frameBallCanStartBeingControlled) {
                g_Pitcher.frameBallCanStartBeingControlled = frame;
            }
            slowedVz = vz - vz * g_Pitcher.airResistance_veloAdj;
            if (slowedVz < -0.05f) {
                vz = slowedVz;
            }
        }
        vz *= g_Pitcher.decelerationFactor;
        z += vz;
        if (z <= g_Pitcher.frontOfPlateZ) {
            g_Pitcher.frameWhenUnhittable = frame;
            break;
        }
    }
    g_Pitcher.verticalGlobalParabolicVelo = pitchData[5];
    if (g_Pitcher.starPitchType == 9 || g_Pitcher.starPitchType == 10) {
        g_Pitcher.verticalGlobalParabolicVelo = RandomInt_Game_Range(lbl_3_data_5F7C[2], lbl_3_data_5F7C[3]);
    }
    half = g_Pitcher.frameWhenUnhittable / 2.0f;
    g_Pitcher.verticalOffsetParabolaMidpoint = g_Pitcher.verticalGlobalParabolicVelo * half * half / 10000.0f;
    g_Pitcher.horizontalGlobalParabolicVelo = pitchData[6];
    if (g_Pitcher.handedness) {
        g_Pitcher.horizontalGlobalParabolicVelo = -g_Pitcher.horizontalGlobalParabolicVelo;
    }
    half = g_Pitcher.frameWhenUnhittable / 2.0f;
    g_Pitcher.horizontalOffsetParabolaMidpoint = g_Pitcher.horizontalGlobalParabolicVelo * half * half / 10000.0f;
    if (g_Pitcher.starPitchType == 3 || g_Pitcher.starPitchType == 4) {
        if (g_Pitcher.AIInd) {
            g_Pitcher.warioWaluStarPitchRightLeft = RandomInt_Game(2);
        } else if (input->buttonInput & INPUT_BUTTON_RIGHT) {
            g_Pitcher.warioWaluStarPitchRightLeft = 0;
        } else if (input->buttonInput & INPUT_BUTTON_LEFT) {
            g_Pitcher.warioWaluStarPitchRightLeft = 1;
        } else {
            g_Pitcher.warioWaluStarPitchRightLeft = RandomInt_Game(2);
        }
    }
    if (g_Pitcher.starPitchType == 7 || g_Pitcher.starPitchType == 8) {
        bullet = g_Pitcher.starPitchType - 7;
        g_Pitcher.bulletPitchLoopFrames = RandomInt_Game_Range(lbl_3_data_5F50[bullet][0], lbl_3_data_5F50[bullet][1]);
        g_Pitcher.bulletPitchLoopStartingFrame = RandomInt_Game_Range(lbl_3_data_5F50[bullet][2], lbl_3_data_5F50[bullet][3]);
        g_Pitcher.frameWhenUnhittable += g_Pitcher.bulletPitchLoopFrames;
    }
}

// .text:0x00071248 size:0x1520 mapped:0x806B02DC
// Mostly inlined copies of this file's functions; the remaining differences are those of
// fn_3_709B4 and the scheduling of the bounce and collision blocks.
void fn_3_71248(void) {
    VecSrcDst ray;
    CollisionStruct hit;
    f32 dist;
    f32 t;
    f32 amp;
    f32 ground;
    f32 speed;
    BALL_COLLISION_TYPE collision;

    if (g_Pitcher.eggBallBounceNumber) {
        g_Pitcher.framesSinceFirstEggBounce++;
    }
    g_Pitcher.ballLastPosition.x = g_Pitcher.ballCurrentPosition.x;
    g_Pitcher.ballLastPosition.y = g_Pitcher.ballCurrentPosition.y;
    g_Pitcher.ballLastPosition.z = g_Pitcher.ballCurrentPosition.z;
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_WALLBALL && g_Minigame.ballStoppedBreakingWallsInd) {
        g_Pitcher.ballVelocity.y -= g_Ball.physicsSubstruct.gravity;
        g_Pitcher.ballCurrentPosition.x += g_Pitcher.ballVelocity.x;
        g_Pitcher.ballCurrentPosition.y += g_Pitcher.ballVelocity.y;
        g_Pitcher.ballCurrentPosition.z += g_Pitcher.ballVelocity.z;
        if (g_Ball.AtBat_Contact_BallPos.y < g_Ball.groundYForBounces) {
            g_Pitcher.ballCurrentPosition.y = g_Ball.groundYForBounces;
            g_Pitcher.ballVelocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
            g_Pitcher.ballVelocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
            g_Pitcher.ballVelocity.y *= -lbl_3_data_4388[g_d_GameSettings.StadiumID]._04;
        }
        g_Ball.AtBat_Contact_BallPos.x = g_Pitcher.ballCurrentPosition.x;
        g_Ball.AtBat_Contact_BallPos.y = g_Pitcher.ballCurrentPosition.y;
        g_Ball.AtBat_Contact_BallPos.z = g_Pitcher.ballCurrentPosition.z;
    } else {
        if (g_Pitcher.starPitchType == 7 || g_Pitcher.starPitchType == 8) {
            if (g_Ball.pitchHangtimeCounter >= g_Pitcher.bulletPitchLoopStartingFrame && g_Pitcher.bulletPitchStageCode == 0) {
                g_Pitcher.bulletPitchStageCode = 1;
            }
            if (g_Pitcher.bulletPitchStageCode == 1) {
                fn_3_709B4();
            } else {
                goto straight;
            }
        } else {
        straight:
            if (g_Pitcher.ballCurrentPosition.z <= g_Pitcher.pitchZ_whenAirResistanceStarts) {
                dist = g_Pitcher.ballVelocity.z - g_Pitcher.ballVelocity.z * g_Pitcher.airResistance_veloAdj;
                if (dist < -0.05f) {
                    g_Pitcher.ballVelocity.z = dist;
                    g_Pitcher.ballVelocity.x =
                        g_Pitcher.ballVelocity.x - g_Pitcher.ballVelocity.x * g_Pitcher.airResistance_veloAdj;
                    g_Pitcher.ballVelocity.y =
                        g_Pitcher.ballVelocity.y - g_Pitcher.ballVelocity.y * g_Pitcher.airResistance_veloAdj;
                }
            }
            fn_3_70EF4();
            g_Pitcher.ballVelocity.x *= g_Pitcher.decelerationFactor;
            g_Pitcher.ballVelocity.y *= g_Pitcher.decelerationFactor;
            g_Pitcher.ballVelocity.z *= g_Pitcher.decelerationFactor;
            fn_3_70B94();
            fn_3_70AEC();
            g_Pitcher.ballVelocity.x += g_Pitcher.pitchCurveVeloV1;
            g_Pitcher.ballCurrentPosition.x += g_Pitcher.ballVelocity.x;
            g_Pitcher.ballCurrentPosition.y += g_Pitcher.ballVelocity.y;
            g_Pitcher.ballCurrentPosition.z += g_Pitcher.ballVelocity.z;
        }
        g_Ball.AtBat_Contact_BallPos.x = g_Pitcher.ballCurrentPosition.x + g_Pitcher.pitchX_parabolicAdjustment;
        g_Ball.AtBat_Contact_BallPos.y = g_Pitcher.ballCurrentPosition.y + g_Pitcher.pitchY_parabolicAdjustment;
        g_Ball.AtBat_Contact_BallPos.z = g_Pitcher.ballCurrentPosition.z;
        if ((g_Pitcher.starPitchType == 7 || g_Pitcher.starPitchType == 8) && g_Pitcher.bulletPitchStageCode == 1) {
            g_Ball.AtBat_Contact_BallPos.x += g_Pitcher.starPitchPositionAdjustment.x;
            g_Ball.AtBat_Contact_BallPos.y += g_Pitcher.starPitchPositionAdjustment.y;
            g_Ball.AtBat_Contact_BallPos.z += g_Pitcher.starPitchPositionAdjustment.z;
        }
        if (g_Pitcher.starPitchType == 3) {
            dist = lbl_3_data_5EB8[1] - g_Ball.AtBat_Contact_BallPos.z;
            if (dist >= 0.0f) {
                g_Pitcher.starPitchPositionAdjustment.x = lbl_3_data_5EB8[0] * (dist / lbl_3_data_5EB8[1]);
                if (g_Pitcher.warioWaluStarPitchRightLeft) {
                    g_Pitcher.starPitchPositionAdjustment.x = -g_Pitcher.starPitchPositionAdjustment.x;
                }
                g_Ball.AtBat_Contact_BallPos.x += g_Pitcher.starPitchPositionAdjustment.x;
                if (g_Pitcher.warioWaluStarHasPlayedSound == 0) {
                    playSoundEffect(0x1B2);
                }
                g_Pitcher.warioWaluStarAnimationStage = 1;
                if (g_Ball.AtBat_Contact_BallPos.z < lbl_3_data_5EB8[2]) {
                    g_Pitcher.warioWaluStarAnimationStage = 2;
                }
                g_Pitcher.warioWaluStarHasPlayedSound++;
            }
        } else if (g_Pitcher.starPitchType == 4) {
            dist = lbl_3_data_5EC4[1] - g_Ball.AtBat_Contact_BallPos.z;
            if (dist >= 0.0f) {
                t = dist / lbl_3_data_5EC4[1];
                amp = lbl_3_data_5EC4[0] * t;
                if (t > 1.0f) {
                    t = 1.0f;
                }
                g_Pitcher.starPitchPositionAdjustment.x = 2.0f * amp * -sinf_kludge(4.712389f * t) + -amp;
                if (g_Pitcher.warioWaluStarPitchRightLeft) {
                    g_Pitcher.starPitchPositionAdjustment.x = -g_Pitcher.starPitchPositionAdjustment.x;
                }
                g_Ball.AtBat_Contact_BallPos.x += g_Pitcher.starPitchPositionAdjustment.x;
                if (g_Pitcher.warioWaluStarHasPlayedSound == 0) {
                    playSoundEffect(0x1B2);
                }
                g_Pitcher.warioWaluStarAnimationStage = 1;
                if (g_Ball.AtBat_Contact_BallPos.z < lbl_3_data_5EC4[2]) {
                    g_Pitcher.warioWaluStarAnimationStage = 2;
                }
                g_Pitcher.warioWaluStarHasPlayedSound++;
            }
        }
        if (g_Pitcher.starPitchType == 11 || g_Pitcher.starPitchType == 12) {
            t = (f32)g_Ball.pitchHangtimeCounter / (f32)g_Pitcher.frameWhenUnhittable;
            if (t >= lbl_3_data_5F90[g_Pitcher.starPitchType - 11 + 8] &&
                t <= lbl_3_data_5F90[g_Pitcher.starPitchType - 11 + 10]) {
                g_Pitcher.peachDaisyAnimationHappened = 1;
                g_Pitcher.peachDaisyStarAnimationOn++;
            } else {
                g_Pitcher.peachDaisyStarAnimationOn = 0;
            }
        }
        ground = g_Ball.groundYForBounces;
        if (g_Pitcher.starPitchType == 9 || g_Pitcher.starPitchType == 10) {
            ground = lbl_3_data_5F5C[0];
        }
        if (g_Ball.AtBat_Contact_BallPos.y < ground) {
            if ((g_Pitcher.starPitchType == 9 || g_Pitcher.starPitchType == 10) &&
                (g_Pitcher.eggBallBounceNumber == 0 || g_Pitcher.eggBallBounceNumber == 1)) {
                fn_3_70838();
            } else {
                speed = SQ(g_Pitcher.ballVelocity.x) + SQ(g_Pitcher.ballVelocity.z);
                g_Pitcher.ballVelocity.y = -(ground - g_Ball.pastCoordinates[0].y);
                g_Pitcher.eggBallBounceNumber++;
                g_Pitcher.cancelParabolicAdjustmentInd = 1;
                g_Ball.AtBat_Contact_BallPos.y = ground;
                g_Pitcher.ballCurrentPosition.y = ground;
                g_Pitcher.ballVelocity.y *= lbl_3_data_5ED0[1];
                speed = dolsqrtf2(speed);
                if (speed < 0.01f) {
                    speed = 0.01f;
                }
                g_Pitcher.pitchCurveVeloV1 = 0.0f;
                g_Pitcher._60 = 0.0f;
                g_Pitcher.ballVelocity.x = 0.15f * (g_Pitcher.ballVelocity.x / speed);
                g_Pitcher.ballVelocity.z = 0.15f * (g_Pitcher.ballVelocity.z / speed);
                playSoundEffect(0x17E);
            }
        }
        g_Pitcher.framesUntilBallReachesBatterZ = fn_3_70768(&g_Pitcher.pitchXPosition, FALSE, g_Batter.batPosition.z);
        fn_3_70768(&g_Pitcher.pitchXPosition2, TRUE, g_Batter.batPosition.z);
        if (g_Pitcher.framesUntilPitchGetsToBatter < 0) {
            g_Pitcher.framesUntilPitchGetsToBatter = g_Pitcher.framesUntilBallReachesBatterZ + g_Ball.pitchHangtimeCounter;
        }
        fn_3_70280();
        if (g_Pitcher.strikeZoneProcessNumber == 0 && g_Ball.AtBat_Contact_BallPos.z < g_Pitcher.strikeCheckZ[0]) {
            fn_3_706B8(0);
            g_Pitcher.strikeZoneProcessNumber = 1;
        }
        if (g_Pitcher.strikeZoneProcessNumber <= 1 && g_Ball.AtBat_Contact_BallPos.z < g_Pitcher.strikeCheckZ[1]) {
            if (!g_Pitcher.calledStrikeInd) {
                fn_3_706B8(1);
            }
            g_Pitcher.strikeZoneProcessNumber = 2;
        }
        if (g_Ball.AtBat_Contact_BallPos.z >= g_Pitcher.centerOfStrikeZone.z) {
            g_Pitcher.framesUntilUnhittable = g_Pitcher.frameWhenUnhittable - g_Ball.pitchHangtimeCounter;
        }
        if (g_Ball.AtBat_Contact_BallPos.z < -3.0f) {
            fn_3_750C4(PITCHER_ACTION_STATE_NO_CONTACT);
            g_Pitcher.pitchDidntResultInLiveBallInd = 1;
            if (g_Pitcher.pitchSpeed > 144) {
                playSoundEffect(0x16B);
            } else {
                playSoundEffect(0x16A);
            }
        }
        g_Pitcher.frontOfPlateZ2 = g_Pitcher.frontOfPlateZ;
        g_Pitcher.pitchLinearInterpolateX =
            g_Pitcher.pitchRelease.x + (g_Pitcher.ballCurrentPosition.x - g_Pitcher.pitchRelease.x) *
                                           (g_Pitcher.frontOfPlateZ - g_Pitcher.pitchRelease.z) /
                                           (g_Pitcher.ballCurrentPosition.z - g_Pitcher.pitchRelease.z);
        g_Pitcher.pitchLinearInterpolateY =
            g_Pitcher.pitchRelease.x + (g_Pitcher.ballCurrentPosition.y - g_Pitcher.pitchRelease.y) *
                                           (g_Pitcher.frontOfPlateZ - g_Pitcher.pitchRelease.z) /
                                           (g_Pitcher.ballCurrentPosition.z - g_Pitcher.pitchRelease.z);
        if (g_Batter.hitByPitch) {
            fn_3_6FFC4();
            fn_3_750C4(PITCHER_ACTION_STATE_HIT_BY_PITCH);
            g_Pitcher.pitchDidntResultInLiveBallInd = 1;
        }
    }
    ray.src.x = g_Ball.AtBat_Contact_BallPos.x;
    ray.src.y = -g_Ball.AtBat_Contact_BallPos.y;
    ray.src.z = g_Ball.AtBat_Contact_BallPos.z;
    ray.dst.x = g_Ball.AtBat_Contact_BallPos.x;
    ray.dst.y = 10.0f;
    ray.dst.z = g_Ball.AtBat_Contact_BallPos.z;
    collision = checkCollision(&ray, &hit, 0, 0);
    g_Ball.maybeCollisionRelated = g_Ball.collisionCode;
    g_Ball.physicsSubstruct.twoFrameLookback[1] = -hit.position.y;
    if (collision) {
        g_Ball.collisionCode = collision;
    }
}

// .text:0x00070EF4 size:0x354 mapped:0x806AFF88
void fn_3_70EF4(void) {
    InputStruct* input = &g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]];
    s16* curveRange = lbl_3_data_5D6C[g_Pitcher.specialPitchTypeCode];
    int dir = 0;
    f32 maxCurve;
    f32 divisor;
    f32 step;

    g_Pitcher.pitchCurveVeloV1 = 0.0f;
    g_Pitcher._60 = 0.0f;
    if (!g_Pitcher.cancelParabolicAdjustmentInd && g_Pitcher.calced_curve) {
        maxCurve = 0.00005f * LinearInterpolateToNewRange(g_Pitcher.calced_curve, 1.0f, 100.0f, curveRange[1], curveRange[2]);
        if (g_Pitcher.AIInd) {
            dir = fn_3_20CEC(maxCurve);
        } else {
            if (ACTIVE_TUTORIAL()) {
                input = &g_Practice.inputs[g_GameLogic.teamFielding];
            } else if (fn_3_107DB4(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder])) {
                input = &g_Minigame._1D7C[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
            } else if (g_d_GameSettings.minigamesEnabled) {
                input = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
            }
            if (input->buttonInput & INPUT_BUTTON_LEFT) {
                dir = -1;
            } else if (input->buttonInput & INPUT_BUTTON_RIGHT) {
                dir = 1;
            }
        }
        divisor = LinearInterpolateToNewRange(g_Pitcher.calced_curveControl, 1.0f, 100.0f, lbl_3_data_5E78[0], lbl_3_data_5E78[1]);
        if (divisor < 1.0f) {
            divisor = 1.0f;
        }
        if (dir == 0) {
            step = maxCurve / divisor;
            if (g_Pitcher.pitchCurveVeloV2 < 0.0f) {
                g_Pitcher.pitchCurveVeloV2 += step;
                if (g_Pitcher.pitchCurveVeloV2 > 0.0f) {
                    g_Pitcher.pitchCurveVeloV2 = 0.0f;
                }
            } else {
                g_Pitcher.pitchCurveVeloV2 -= step;
                if (g_Pitcher.pitchCurveVeloV2 < 0.0f) {
                    g_Pitcher.pitchCurveVeloV2 = 0.0f;
                }
            }
        } else {
            g_Pitcher.pitchCurveVeloV2 += maxCurve * dir / divisor;
            if (dir < 0) {
                if (g_Pitcher.pitchCurveVeloV2 < -maxCurve) {
                    g_Pitcher.pitchCurveVeloV2 = -maxCurve;
                }
            } else if (g_Pitcher.pitchCurveVeloV2 > maxCurve) {
                g_Pitcher.pitchCurveVeloV2 = maxCurve;
            }
        }
        g_Pitcher.pitchCurveVeloV1 = g_Pitcher.pitchCurveVeloV2;
        if (dir) {
            g_Pitcher.anyCurveInput = 1;
        }
    }
}

// .text:0x00070B94 size:0x360 mapped:0x806AFC28
void fn_3_70B94(void) {
    f32 t;

    if (g_Pitcher.starPitchType == 9 || g_Pitcher.starPitchType == 10) {
        if (g_Pitcher.eggBallBounceNumber == 0) {
            t = g_Ball.pitchHangtimeCounter - g_Pitcher.frameWhenUnhittable / 2.0f;
            g_Pitcher.pitchY_parabolicAdjustment =
                g_Pitcher.verticalOffsetParabolaMidpoint - g_Pitcher.verticalGlobalParabolicVelo * t * t / 10000.0f;
        } else if (g_Pitcher.eggBallBounceNumber == 1 || g_Pitcher.eggBallBounceNumber == 2) {
            if (g_Pitcher.framesSinceFirstEggBounce == 1) {
                if (g_Pitcher.eggBallBounceNumber == 1) {
                    g_Pitcher.ballBouncePeakZ = fn_3_70768(&t, FALSE, g_Pitcher.eggBallBounceZLoc) / 2.0f;
                    g_Pitcher.verticalGlobalParabolicVelo = LERPToNewRange_Float(
                        g_Pitcher.pitchSpeed, lbl_3_data_5F7C[4], lbl_3_data_5F7C[5], lbl_3_data_5F7C[6], lbl_3_data_5F7C[7]);
                    t = g_Pitcher.ballBouncePeakZ;
                    g_Pitcher.verticalOffsetParabolaMidpoint = g_Pitcher.verticalGlobalParabolicVelo * t * t / 10000.0f;
                } else {
                    g_Pitcher.ballBouncePeakZ = g_Pitcher.framesUntilBallReachesBatterZ;
                    g_Pitcher.verticalOffsetParabolaMidpoint = 0.3f + lbl_3_data_5E98[4];
                    t = g_Pitcher.framesUntilBallReachesBatterZ;
                    g_Pitcher.verticalGlobalParabolicVelo = 10000.0f * g_Pitcher.verticalOffsetParabolaMidpoint / (t * t);
                }
            }
            t = (f32)g_Pitcher.framesSinceFirstEggBounce - (f32)g_Pitcher.ballBouncePeakZ;
            g_Pitcher.pitchY_parabolicAdjustment =
                g_Pitcher.verticalOffsetParabolaMidpoint - g_Pitcher.verticalGlobalParabolicVelo * t * t / 10000.0f;
        } else {
            g_Pitcher.pitchY_parabolicAdjustment = 0.0f;
        }
    } else if (g_Pitcher.cancelParabolicAdjustmentInd) {
        g_Pitcher.pitchY_parabolicAdjustment = 0.0f;
    } else {
        t = g_Ball.pitchHangtimeCounter - g_Pitcher.frameWhenUnhittable / 2.0f;
        g_Pitcher.pitchY_parabolicAdjustment =
            g_Pitcher.verticalOffsetParabolaMidpoint - g_Pitcher.verticalGlobalParabolicVelo * t * t / 10000.0f;
    }
}

// .text:0x00070AEC size:0xA8 mapped:0x806AFB80
void fn_3_70AEC(void) {
    f32 t;

    if (g_Pitcher.cancelParabolicAdjustmentInd) {
        g_Pitcher.pitchX_parabolicAdjustment = 0.0f;
    } else {
        t = g_Ball.pitchHangtimeCounter - g_Pitcher.frameWhenUnhittable / 2.0f;
        g_Pitcher.pitchX_parabolicAdjustment =
            g_Pitcher.horizontalOffsetParabolaMidpoint - g_Pitcher.horizontalGlobalParabolicVelo * t * t / 10000.0f;
    }
}

// .text:0x000709B4 size:0x138 mapped:0x806AFA48
// Registers only: after getComponentsFromRad the target holds 0.0f and the radius in f0
// and y in f2; the base swaps them.
void fn_3_709B4(void) {
    f32 angle;
    f32 y;
    f32 z;
    f32 radius;

    g_Pitcher.bulletPitchFrameCounter++;
    if (g_Pitcher.bulletPitchFrameCounter >= g_Pitcher.bulletPitchLoopFrames) {
        g_Pitcher.bulletPitchStageCode = 2;
    } else {
        angle = (f32)g_Pitcher.bulletPitchFrameCounter / (f32)g_Pitcher.bulletPitchLoopFrames;
        angle *= 6.2831855f;
        angle += 3.1415927f;
        getComponentsFromRad(angle, &y, &z);
        radius = 0.01f * lbl_3_data_5F50[g_Pitcher.starPitchType - 7][4];
        g_Pitcher.starPitchPositionAdjustment.x = 0.0f;
        g_Pitcher.bulletPitchLoopAngleRadians = angle;
        g_Pitcher.starPitchPositionAdjustment.y = radius * y + radius;
        g_Pitcher.starPitchPositionAdjustment.z = radius * z;
    }
}

// .text:0x00070838 size:0x17C mapped:0x806AF8CC
void fn_3_70838(void) {
    f32 dx;
    f32 dy;
    f32 dz;

    if (g_Pitcher.eggBallBounceNumber == 0) {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = RandomF32_Game_Range(-lbl_3_data_5F5C[6], lbl_3_data_5F5C[6]);
        g_Pitcher.eggBallBounceYHeight = lbl_3_data_5F5C[0];
        g_Pitcher.eggBallBounceZLoc = RandomF32_Game_Range(lbl_3_data_5F5C[4], lbl_3_data_5F5C[5]);
        g_Pitcher.frontOfPlateZ = 0.5f * (g_Pitcher.eggBallBounceZLoc + g_Pitcher.frontOfPlateZ);
    } else {
        g_Pitcher.pitchStartingPosition_AIMaxCurve = RandomF32_Game_Range(-lbl_3_data_5F5C[7], lbl_3_data_5F5C[7]);
        g_Pitcher.eggBallBounceYHeight = lbl_3_data_5F5C[0];
        g_Pitcher.frontOfPlateZ = g_Pitcher.centerOfStrikeZone.z;
    }
    g_Pitcher.pitchSpeed = RandomInt_Game_Range(lbl_3_data_5F7C[4], lbl_3_data_5F7C[5]);
    g_Pitcher.eggBallBounceNumber++;
    g_Pitcher.framesSinceFirstEggBounce = 0;
    dx = g_Pitcher.pitchStartingPosition_AIMaxCurve - g_Pitcher.ballCurrentPosition.x;
    dy = g_Pitcher.eggBallBounceYHeight - g_Pitcher.ballCurrentPosition.y;
    dz = g_Pitcher.ballCurrentPosition.z - g_Pitcher.frontOfPlateZ;
    g_Pitcher.ballVelocity.z = -(g_Pitcher.pitchSpeed / g_Pitcher.pitchSpeedScaler);
    g_Pitcher.ballVelocity.x = -(dx * g_Pitcher.ballVelocity.z / dz);
    g_Pitcher.ballVelocity.y = -(dy * g_Pitcher.ballVelocity.z / dz);
}

// .text:0x00070768 size:0xD0 mapped:0x806AF7FC
// Registers only: the last fmuls has its operands swapped (f0,f0,f1 in the target).
int fn_3_70768(f32* outX, BOOL curve, f32 targetZ) {
    int frames = 0;
    f32 z = g_Pitcher.ballCurrentPosition.z;
    f32 x = g_Pitcher.ballCurrentPosition.x;
    f32 vx = g_Pitcher.ballVelocity.x;
    f32 vy = g_Pitcher.ballVelocity.y;
    f32 vz = g_Pitcher.ballVelocity.z;
    f32 curveVelo = g_Pitcher.pitchCurveVeloV1;
    f32 prevX;
    f32 prevZ;
    f32 airZ;
    f32 adj;
    f32 decel;
    f32 slowedVz;
    f32 dist;

    if (z < targetZ) {
        return 0;
    }
    airZ = g_Pitcher.pitchZ_whenAirResistanceStarts;
    adj = g_Pitcher.airResistance_veloAdj;
    decel = g_Pitcher.decelerationFactor;
    while (TRUE) {
        prevX = x;
        prevZ = z;
        frames++;
        if (z <= airZ) {
            slowedVz = vz - vz * adj;
            if (slowedVz < -0.05f) {
                vz = slowedVz;
                vx = vx - vx * adj;
                vy = vy - vy * adj;
            }
        }
        vx *= decel;
        vz *= decel;
        vy *= decel;
        x += vx;
        z += vz;
        if (curve) {
            x += curveVelo;
        }
        if (z < targetZ) break;
    }
    dist = z - prevZ;
    dist = (1.0f - (z - targetZ) / dist) * (x - prevX);
    *outX = prevX + dist;
    return frames;
}

// .text:0x000706B8 size:0xB0 mapped:0x806AF74C
void fn_3_706B8(int which) {
    f32 t;

    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_WALLBALL) {
        return;
    }
    t = (g_Pitcher.strikeCheckZ[which] - g_Pitcher.ballCurrentPosition.z) /
        (g_Pitcher.ballLastPosition.z - g_Pitcher.ballCurrentPosition.z);
    g_Pitcher.estimatedEndingPos.x =
        g_Pitcher.ballCurrentPosition.x + t * (g_Pitcher.ballLastPosition.x - g_Pitcher.ballCurrentPosition.x);
    g_Pitcher.estimatedEndingPos.z =
        g_Pitcher.ballCurrentPosition.y + t * (g_Pitcher.ballLastPosition.y - g_Pitcher.ballCurrentPosition.y);
    if (fn_3_70680(g_Pitcher.estimatedEndingPos.x)) {
        g_Pitcher.calledStrikeInd = 1;
        g_Pitcher.strikeInd = 1;
    }
}

// .text:0x00070680 size:0x38 mapped:0x806AF714
BOOL fn_3_70680(f32 x) {
    if (x >= g_Pitcher.strikeZoneLeft && x <= g_Pitcher.strikeZoneRight) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000703EC size:0x294 mapped:0x806AF480
void fn_3_703EC(void) {
    if (g_Batter.framesSinceStartOfSwing > 0 && g_Batter.framesSinceStartOfSwing < swingSoundFrame[0][1] &&
        !g_Batter._95) {
        return;
    }
    g_Pitcher.miniGameRelated = 1;
    if (g_Pitcher.strikeInd) {
        if (++g_Strikes.strikes >= 3) {
            g_Pitcher.strikeOutOrWalk = 1;
            g_Pitcher.framesSinceAtBatEnded = 0;
            fn_3_750C4(PITCHER_ACTION_STATE_HIT);
            fn_3_59918(16, 0);
            if (g_GameLogic.IsStarChance == 1) {
                if ((g_Scores._00 < g_Scores._AA || !g_Scores._AD || g_Strikes.outs < 2 ||
                     g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0] <=
                         g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0]) &&
                    (g_Scores._00 < g_Scores._AB || !g_Scores._AD || g_Strikes.outs < 2)) {
                    if (g_GameLogic.TeamStars[g_GameLogic.teamFielding] < 5) {
                        g_GameLogic.TeamStars[g_GameLogic.teamFielding]++;
                        if (g_Stats.replayInd == 0) {
                            playSoundEffect(0x19D);
                        }
                    }
                }
                g_GameLogic.IsStarChance = 2;
            }
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
                g_Minigame._19C6 = g_Minigame.minigamePlayerSelectedOrder;
            }
        } else {
            fn_3_59918(8, 0);
        }
    } else {
        if (++g_Strikes.balls >= 4) {
            g_Pitcher.strikeOutOrWalk = 2;
            g_Pitcher.framesSinceAtBatEnded = 0;
            fn_3_750C4(PITCHER_ACTION_STATE_HIT);
            fn_3_59918(10, 0);
            if (g_GameLogic.IsStarChance == 1) {
                if (g_GameLogic.TeamStars[g_GameLogic.teamBatting] < 5) {
                    g_GameLogic.TeamStars[g_GameLogic.teamBatting]++;
                    if (g_Stats.replayInd == 0) {
                        playSoundEffect(0x19D);
                    }
                }
                g_GameLogic.IsStarChance = 3;
            }
        } else {
            fn_3_59918(9, 0);
        }
    }
    fn_3_7A154(0);
    fn_3_1DD48();
}

// .text:0x00070280 size:0x16C mapped:0x806AF314
void fn_3_70280(void) {
    BOOL hit = FALSE;
    int dx;
    int dz;
    u8 type;

    if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_PITCHING && !g_Practice._1DB) {
        return;
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_WALLBALL) {
        return;
    }
    if (g_Batter.framesSinceStartOfSwing > 0) {
        return;
    }
    if (g_Pitcher.calledStrikeInd) {
        return;
    }
    dx = 100.0f * (g_Pitcher.ballCurrentPosition.x - g_Batter.batterPos.x);
    dz = 100.0f * (g_Pitcher.ballCurrentPosition.z - g_Batter.batterPos.z);
    if (g_Batter.batterHand) {
        dx = -dx;
    }
    type = lbl_800E8558[g_Batter.charID][2];
    if (dz <= lbl_3_data_76FC[type][0] && dz >= 0.0f && dx <= lbl_3_data_76FC[type][1] &&
        dx >= -lbl_3_data_76FC[type][2]) {
        hit = TRUE;
    }
    if (hit) {
        g_Batter.hitByPitch = 1;
    }
}

// .text:0x0006FFC4 size:0x2BC mapped:0x806AF058
// Registers only: the target keeps the speed in f5 and the 0.01f term in f4 (fn_3_6FDA0,
// written the same way, matches); declaration and statement orders did not change it.
void fn_3_6FFC4(void) {
    int spread = g_Ball.StaticRandomInt1 % 257 - 128;
    int ang;
    f32 z;
    f32 x;
    f32 extra;
    f32 speed;

    ang = fn_3_9FB8C(g_Pitcher.ballVelocity.x, -g_Pitcher.ballVelocity.z);
    getComponentsFromSAng(ang + spread, &x, &z);
    extra = 0.01f * (g_Ball.StaticRandomInt2 % 10);
    speed = dolsqrtf2(SQ(g_Pitcher.ballVelocity.x) + SQ(g_Pitcher.ballVelocity.z));
    g_Ball.physicsSubstruct.velocity.x = (0.1f + extra) * (x * speed);
    g_Ball.physicsSubstruct.velocity.z = (0.1f + extra) * (z * speed);
    g_Ball.physicsSubstruct.velocity.y = 0.0f;
    g_Pitcher.strikeOutOrWalk = 3;
    g_Pitcher.miniGameRelated = 1;
    g_Pitcher.framesSinceAtBatEnded = 0;
    playSoundEffect(0x170);
    if (!g_Batter.aiControlledInd) {
        if (g_d_GameSettings.minigamesEnabled) {
            fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.rosterID], 2);
        } else {
            fn_3_6C854(g_GameLogic.teamBatting, 2);
        }
    }
    fn_3_7A154(0);
}

// .text:0x0006FDA0 size:0x224 mapped:0x806AEE34
void fn_3_6FDA0(void) {
    int spread = g_Ball.StaticRandomInt1 % 257 - 128;
    int ang;
    f32 x;
    f32 z;
    f32 extra;
    f32 speed;

    ang = fn_3_9FB8C(g_Pitcher.ballVelocity.x, -g_Pitcher.ballVelocity.z);
    getComponentsFromSAng(ang + spread, &x, &z);
    extra = 0.01f * (g_Ball.StaticRandomInt2 % 10);
    speed = dolsqrtf2(SQ(g_Pitcher.ballVelocity.x) + SQ(g_Pitcher.ballVelocity.z));
    g_Ball.physicsSubstruct.velocity.x = (0.1f + extra) * (x * speed);
    g_Ball.physicsSubstruct.velocity.z = (0.1f + extra) * (z * speed);
    g_Ball.physicsSubstruct.velocity.y = 0.0f;
}

// .text:0x0006FB98 size:0x208 mapped:0x806AEC2C
void fn_3_6FB98(void) {
    fn_3_6FA28();
    if (g_Pitcher.currentStateFrameCounter == 10) {
        fn_3_59918(11, 0);
        fn_3_750C4(PITCHER_ACTION_STATE_HIT);
        if (g_GameLogic.IsStarChance == 1) {
            if (g_GameLogic.TeamStars[g_GameLogic.teamBatting] < 5) {
                g_GameLogic.TeamStars[g_GameLogic.teamBatting]++;
                if (g_Stats.replayInd == 0) {
                    playSoundEffect(0x19D);
                }
            }
            g_GameLogic.IsStarChance = 3;
        }
    }
}

// .text:0x0006FA28 size:0x170 mapped:0x806AEABC
void fn_3_6FA28(void) {
    if (g_Ball.pitchHangtimeCounter < 0x7FFE) {
        g_Ball.pitchHangtimeCounter++;
    } else {
        g_Ball.pitchHangtimeCounter = 0x7FFF;
    }
    if (g_Pitcher.pitchTotalTimeCounter < 0x7FFE) {
        g_Pitcher.pitchTotalTimeCounter++;
    } else {
        g_Pitcher.pitchTotalTimeCounter = 0x7FFF;
    }
    g_Ball.pastCoordinates[0].x = g_Ball.AtBat_Contact_BallPos.x;
    g_Ball.pastCoordinates[0].y = g_Ball.AtBat_Contact_BallPos.y;
    g_Ball.pastCoordinates[0].z = g_Ball.AtBat_Contact_BallPos.z;
    g_Ball.physicsSubstruct.velocity.y -= g_Ball.physicsSubstruct.gravity;
    fn_3_DBD0();
    g_Ball.AtBat_Contact_BallPos.x += g_Ball.physicsSubstruct.velocity.x;
    g_Ball.AtBat_Contact_BallPos.y += g_Ball.physicsSubstruct.velocity.y;
    g_Ball.AtBat_Contact_BallPos.z += g_Ball.physicsSubstruct.velocity.z;
    if (g_Ball.AtBat_Contact_BallPos.y < g_Ball.groundYForBounces) {
        g_Ball.physicsSubstruct.velocity.y *=
            lbl_3_data_4388[g_d_GameSettings.StadiumID]._04 - g_Ball.physicsSubstruct.velocity.y / 2.0f;
        g_Ball.physicsSubstruct.velocity.y = -g_Ball.physicsSubstruct.velocity.y;
        if (g_Ball.physicsSubstruct.velocity.y < 0.01f) {
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._10;
        } else {
            g_Ball.physicsSubstruct.velocity.x *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
            g_Ball.physicsSubstruct.velocity.z *= lbl_3_data_4388[g_d_GameSettings.StadiumID]._0C;
        }
        g_Ball.AtBat_Contact_BallPos.y = g_Ball.groundYForBounces;
    }
}

// .text:0x0006F748 size:0x2E0 mapped:0x806AE7DC
BOOL fn_3_6F748(void) {
    InputStruct* input = &g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]];

    if (g_Pitcher.AIInd) {
        if (fn_3_20B30()) {
            goto pickoff;
        }
        return FALSE;
    }
    if (ACTIVE_TUTORIAL()) {
        input = &g_Practice.inputs[g_GameLogic.teamFielding];
    } else if (fn_3_107DB4(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder])) {
        input = &g_Minigame._1D7C[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
    } else if (g_d_GameSettings.minigamesEnabled && g_Minigame.minigamePlayerSelectedOrder >= 0) {
        input = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder]];
    }
    if (g_GameLogic.FrameCountOfCurrentPitch < 90) {
        return FALSE;
    }
    if (g_RunningLogic._10 <= 1) {
        return FALSE;
    }
    if (fn_3_6F6CC()) {
        if (g_Pitcher.nPickoffAttempts < 0xFE) {
            g_Pitcher.nPickoffAttempts++;
        } else {
            g_Pitcher.nPickoffAttempts = 0xFF;
        }
        return TRUE;
    }
    if (input->newButtonInput & INPUT_BUTTON_B) {
        g_Pitcher.pickOffLoc = 4;
        if (input->buttonInput & INPUT_BUTTON_LEFT) {
            if (g_Runners[3].runnerOnFieldOrOutOrScored) {
                g_Pitcher.pickOffLoc = 3;
            }
        } else if (input->buttonInput & INPUT_BUTTON_UP) {
            if (g_Runners[2].runnerOnFieldOrOutOrScored) {
                g_Pitcher.pickOffLoc = 2;
            }
        } else if (input->buttonInput & INPUT_BUTTON_RIGHT) {
            if (g_Runners[1].runnerOnFieldOrOutOrScored) {
                g_Pitcher.pickOffLoc = 1;
            }
        }
    pickoff:
        fn_3_5C69C(0);
        if (g_Pitcher.nPickoffAttempts < 0xFE) {
            g_Pitcher.nPickoffAttempts++;
        } else {
            g_Pitcher.nPickoffAttempts = 0xFF;
        }
        return TRUE;
    }
    return FALSE;
}

// .text:0x0006F6CC size:0x7C mapped:0x806AE760
BOOL fn_3_6F6CC(void) {
    int i;

    for (i = 1; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 && g_Runners[i].percentTowardsNextBase > 0.5f) {
            g_Pitcher.pickOffLoc = 4;
            fn_3_5C69C(0);
            return TRUE;
        }
    }
    return FALSE;
}
