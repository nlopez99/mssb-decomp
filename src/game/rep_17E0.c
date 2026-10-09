#include "game/rep_17E0.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"

// .data outside this unit's split
extern u8 lbl_3_data_4380[8];

extern struct {
    /* 0x00 */ s16 _00;
    /* 0x02 */ s16 _02;
    /* 0x04 */ u8 _04[0x10 - 0x04];
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
} g_RunningLogic;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ s16 _50[2][19];
    /* 0x9C */ u8 _9C[0x9E - 0x9C];
    /* 0x9E */ s16 _9E;
    /* 0xA0 */ s16 _A0;
    /* 0xA2 */ u8 _A2[0xAD - 0xA2];
    /* 0xAD */ u8 _AD;
} g_Scores;

typedef struct {
    /* 0x000 */ u8 _000[0x18C];
    /* 0x18C */ s16 _18C;
    /* 0x18E */ u8 _18E[0x268 - 0x18E];
} Unk17E0Fielder; // size: 0x268

extern Unk17E0Fielder g_Fielders[9];

// .text:0x0009EA1C size:0xC8 mapped:0x806DDAB0
BOOL fn_3_9EA1C(int team) {
    int i;

    for (i = 1; i < 10; i++) {
        if (g_GameLogic.battingOrderAndPositionMapping[team][i][1] % 10 == 9) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x0009E7D4 size:0x60 mapped:0x806DD868
void fn_3_9E7D4(int team) {
    if (g_d_GameSettings.GameModeSelected != 2 || g_GameLogic.secondaryGameMode != 0xF) {
        if (g_GameLogic.currentBatterPerTeam[team] == 9) {
            g_GameLogic.currentBatterPerTeam[team] = 1;
        } else {
            g_GameLogic.currentBatterPerTeam[team]++;
        }
    }
}

// .text:0x0009DBE4 size:0x34 mapped:0x806DCC78
void fn_3_9DBE4(void) {
    lbl_3_common_bss_32A94._7D[0] = 0;
    lbl_3_common_bss_32A94._7D[2] = 0;
    lbl_3_common_bss_32A94._7D[4] = 0;
    lbl_3_common_bss_32A94._7D[5] = 0;
    lbl_3_common_bss_32A94._7D[7] = 0;
    lbl_3_common_bss_32A94._7D[8] = 0;
    lbl_3_common_bss_32A94._7D[10] = 0;
    lbl_3_common_bss_32A94._7D[11] = 0;
    lbl_3_common_bss_32A94._8A = 0;
}

// .text:0x0009DB5C size:0x88 mapped:0x806DCBF0
void fn_3_9DB5C(void) {
    int i;

    for (i = 4; i > 0; i--) {
        lbl_3_common_bss_32A94._06[i] = lbl_3_common_bss_32A94._06[i - 1];
    }
    lbl_3_common_bss_32A94._06[0] = lbl_3_common_bss_32A94._0;
    lbl_3_common_bss_32A94._2 = 0;
    lbl_3_common_bss_32A94._0 = 0;
    lbl_3_common_bss_32A94._4 = 0;
    for (i = 0; i < 5; i++) {
        lbl_3_common_bss_32A94._10[i][0] = -1;
        lbl_3_common_bss_32A94._10[i][1] = -1;
        lbl_3_common_bss_32A94._10[i][2] = -1;
    }
    lbl_3_common_bss_32A94._1F = -1;
}

// .text:0x0009D6A4 size:0x4B8 mapped:0x806DC738
void fn_3_9D6A4(void) {
    int i;
    s16 position;
    BOOL caught = FALSE;

    if (g_Stats.replayInd == 0) {
        if (lbl_3_common_bss_32A94._0 == 0) {
            if (g_FieldingLogic._107 == 4) {
                lbl_3_common_bss_32A94._0 = 0x28;
            } else if (g_GameLogic.gameStatus == 1) {
                fn_3_9D600();
            } else if (g_Ball.deadBallReason == 1) {
                fn_3_9D594();
            } else if (g_Ball.AtBat_ContactResult == -1) {
                fn_3_9D550();
            } else {
                if (g_GameLogic.gameStatus == 2) {
                    if (g_Ball.fielderWBallIndex >= 0) {
                        if (lbl_3_common_bss_32A94._1F == -1) {
                            for (i = 0; i < 5; i++) {
                                if (lbl_3_common_bss_32A94._10[i][0] == -1) {
                                    position = g_Fielders[g_Ball.fielderWBallIndex]._18C;
                                    lbl_3_common_bss_32A94._10[i][0] = g_Ball.fielderWBallIndex;
                                    lbl_3_common_bss_32A94._10[i][1] = g_Strikes.outs - g_Strikes.storedOuts;
                                    if (position >= 0 && position <= 3) {
                                        switch (position) {
                                        case 0:
                                            if ((g_RunningLogic._02 & 0x1111) == 0x1111) {
                                                lbl_3_common_bss_32A94._10[i][2] = 0;
                                            }
                                            break;
                                        case 1:
                                            lbl_3_common_bss_32A94._10[i][2] = 1;
                                            break;
                                        case 2:
                                            if ((g_RunningLogic._02 & 0x11) == 0x11) {
                                                lbl_3_common_bss_32A94._10[i][2] = 2;
                                            }
                                            break;
                                        default:
                                            if ((g_RunningLogic._02 & 0x111) == 0x111) {
                                                lbl_3_common_bss_32A94._10[i][2] = 3;
                                            }
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                            caught = TRUE;
                        } else if (lbl_3_common_bss_32A94._1F == g_Ball.fielderWBallIndex) {
                            for (i = 4; i >= 0; i--) {
                                if (lbl_3_common_bss_32A94._10[i][0] == g_Ball.fielderWBallIndex) {
                                    if (g_Ball.timeSinceBallPickedUp <= 60) {
                                        lbl_3_common_bss_32A94._10[i][1] = g_Strikes.outs - g_Strikes.storedOuts;
                                    }
                                    break;
                                }
                            }
                            caught = TRUE;
                        }
                    }
                    lbl_3_common_bss_32A94._1F = g_Ball.fielderWBallIndex;
                }
                if (g_Ball.maybeBuntInd != 0) {
                    fn_3_9CE78();
                } else if (!fn_3_9D374()) {
                    if (caught) {
                        fn_3_9D140();
                    }
                    fn_3_9CD90();
                }
            }
        }
        fn_3_9CAF0();
        if (lbl_3_common_bss_32A94._0 != 0) {
            lbl_3_common_bss_32A94._2 = lbl_3_common_bss_32A94._0;
        }
    }
}

// .text:0x0009D600 size:0xA4 mapped:0x806DC694
void fn_3_9D600(void) {
    if (g_Pitcher.strikeOutOrWalk == 1) {
        if (g_Batter.missedBuntStatus != 0) {
            lbl_3_common_bss_32A94._2 = 0x26;
        } else if (g_Batter.missSwingOrBunt != 0) {
            lbl_3_common_bss_32A94._2 = 0x24;
        } else {
            lbl_3_common_bss_32A94._2 = 0x25;
        }
    } else if (g_Pitcher.strikeOutOrWalk == 2) {
        lbl_3_common_bss_32A94._2 = 0x2A;
    } else if (g_Pitcher.strikeOutOrWalk == 3) {
        lbl_3_common_bss_32A94._0 = 0x2B;
    }
}

// .text:0x0009D594 size:0x6C mapped:0x806DC628
void fn_3_9D594(void) {
    switch (g_RunningLogic._12) {
    case 4:
        lbl_3_common_bss_32A94._0 = 1;
        break;
    case 3:
        lbl_3_common_bss_32A94._0 = 2;
        break;
    case 2:
        lbl_3_common_bss_32A94._0 = 3;
        break;
    default:
        lbl_3_common_bss_32A94._0 = 4;
        break;
    }
}

// .text:0x0009D550 size:0x44 mapped:0x806DC5E4
void fn_3_9D550(void) {
    if (g_Ball.maybeBuntInd != 0 && g_Strikes.strikes >= 3) {
        lbl_3_common_bss_32A94._0 = 0x27;
    } else {
        lbl_3_common_bss_32A94._0 = 0x2C;
    }
}

// .text:0x0009D374 size:0x1DC mapped:0x806DC408
BOOL fn_3_9D374(void) {
    int diff;
    BOOL walkOff = FALSE;

    if (g_Strikes.allForcedRunnersReachedTheirBaseInd == 1) {
        diff = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] - g_Scores._A0;
        if (diff == 1 && g_Runners[0].runnerOnFieldOrOutOrScored == 3) {
            walkOff = TRUE;
        }
        if (g_Runners[0].baseNumberEarned_NotIncludingFieldersChoice == 0 && g_Runners[0].runnerOnFieldOrOutOrScored == 3) {
            lbl_3_common_bss_32A94._0 = 5;
        } else if (g_Runners[0].baseNumberEarned_NotIncludingFieldersChoice == 3) {
            if (diff != 0 && !walkOff) {
                lbl_3_common_bss_32A94._0 = 6;
            } else {
                lbl_3_common_bss_32A94._2 = 0xB;
            }
        } else if (g_Runners[0].baseNumberEarned_NotIncludingFieldersChoice == 2) {
            if (diff != 0 && !walkOff) {
                lbl_3_common_bss_32A94._0 = 7;
            } else {
                lbl_3_common_bss_32A94._2 = 0xC;
            }
        } else if (g_Runners[0].baseNumberEarned_NotIncludingFieldersChoice == 1) {
            if (g_Ball.ballZoneWhenCaught >= 0 && g_Ball.ballZoneWhenCaught <= 1) {
                if (diff != 0 && !walkOff) {
                    lbl_3_common_bss_32A94._0 = 9;
                } else {
                    lbl_3_common_bss_32A94._2 = 0xE;
                }
            } else if (diff != 0 && !walkOff) {
                lbl_3_common_bss_32A94._0 = 8;
            } else {
                lbl_3_common_bss_32A94._2 = 0xD;
            }
        } else if (diff != 0 && !walkOff) {
            lbl_3_common_bss_32A94._2 = 0xA;
        } else {
            lbl_3_common_bss_32A94._2 = 0xF;
        }
        return TRUE;
    }
    return FALSE;
}

// .text:0x0009D140 size:0x234 mapped:0x806DC1D4
void fn_3_9D140(void) {
    int i;
    int count;

    if (g_Ball.AtBat_ContactResult == 3 || g_FieldingLogic._108 == 2) {
        count = 0;
        for (i = 1; i < 3; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 2 && g_Runners[i].outType == 4) {
                count++;
            }
        }
        if (count == 2) {
            lbl_3_common_bss_32A94._0 = 0x17;
            return;
        }
        if (count == 1) {
            lbl_3_common_bss_32A94._2 = 0x1A;
        }
    }
    if (g_Strikes.storedOuts + 3 == g_Strikes.outs && g_Ball.AtBat_ContactResult == 2 &&
        (g_Strikes.outs == 3 || g_RunningLogic._10 == 0)) {
        lbl_3_common_bss_32A94._0 = 0x17;
        if (lbl_3_common_bss_32A94._10[2][1] == 3 || lbl_3_common_bss_32A94._10[3][1] == 3) {
            lbl_3_common_bss_32A94._0 = 0x16;
            return;
        }
    }
    if (g_Strikes.storedOuts + 2 == g_Strikes.outs && g_Ball.AtBat_ContactResult == 2) {
        lbl_3_common_bss_32A94._2 = 0x19;
        if (lbl_3_common_bss_32A94._10[2][0] == 2 && lbl_3_common_bss_32A94._10[0][1] == 0 &&
            lbl_3_common_bss_32A94._10[1][1] == 1) {
            lbl_3_common_bss_32A94._2 = 0x18;
        }
        if (lbl_3_common_bss_32A94._10[3][0] >= 0 && lbl_3_common_bss_32A94._10[2][1] == 2) {
            lbl_3_common_bss_32A94._0 = lbl_3_common_bss_32A94._2;
            return;
        }
    }
    if (g_Strikes.storedOuts + 1 == g_Strikes.outs && g_Ball.AtBat_ContactResult == 2 &&
        lbl_3_common_bss_32A94._10[2][0] == 2 && lbl_3_common_bss_32A94._10[0][1] == 0 &&
        g_Runners[(lbl_3_common_bss_32A94._10[1][2] + 3) & 3].forcedToAdvanceInd != 0 &&
        lbl_3_common_bss_32A94._10[1][2] >= 0 && lbl_3_common_bss_32A94._10[1][2] != 1 &&
        lbl_3_common_bss_32A94._10[1][1] == 1 && lbl_3_common_bss_32A94._10[2][1] == 1 &&
        lbl_3_common_bss_32A94._10[2][2] == 1) {
        lbl_3_common_bss_32A94._2 = 0x14;
    }
}

// .text:0x0009CE78 size:0x2C8 mapped:0x806DBF0C
void fn_3_9CE78(void) {
    int i;
    BOOL advancing;

    if (g_RunningLogic._12 == 1 || g_Strikes.storedOuts == 2) {
        if ((g_Runners[0].runnerOnFieldOrOutOrScored == 2 && g_Strikes.allForcedRunnersReachedTheirBaseInd == 0) ||
            g_Ball.AtBat_ContactResult == 3) {
            lbl_3_common_bss_32A94._0 = 0x1D;
        } else if (g_Runners[0].forceOutCd == 0) {
            lbl_3_common_bss_32A94._0 = 0x1C;
        }
    } else if (g_Runners[3].runnerOnFieldOrOutOrScored != 0 && g_Runners[3].furthestBaseForcedToGoToOnWalk != 0) {
        if (g_Runners[3].runnerOnFieldOrOutOrScored == 3) {
            if (g_Ball.AtBat_ContactResult == 3) {
                lbl_3_common_bss_32A94._2 = 0x20;
            } else {
                lbl_3_common_bss_32A94._0 = 0x1E;
            }
        } else if (g_Runners[3].runnerOnFieldOrOutOrScored == 2) {
            lbl_3_common_bss_32A94._0 = 0x1F;
        }
    } else if (g_Scores._9E > g_Scores._04[g_Scores._AD][g_Scores._00]) {
        lbl_3_common_bss_32A94._2 = 0x20;
    } else if (lbl_3_common_bss_32A94._2 != 0x22) {
        if (g_Ball.AtBat_ContactResult == 3) {
            lbl_3_common_bss_32A94._2 = 0x22;
            return;
        }
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored != 0 &&
                g_Runners[i].currentBase == g_Runners[i].startingBase_baseAchieved &&
                g_Runners[i].runnerOnFieldOrOutOrScored == 2) {
                lbl_3_common_bss_32A94._2 = 0x22;
                return;
            }
        }
        advancing = FALSE;
        for (i = 1; i < 4; i++) {
            if ((g_Runners[i].runnerOnFieldOrOutOrScored == 1 || g_Runners[i].runnerOnFieldOrOutOrScored == 3) &&
                g_Runners[i].currentBase != g_Runners[i].startingBase_baseAchieved) {
                advancing = TRUE;
                break;
            }
        }
        if (advancing) {
            lbl_3_common_bss_32A94._2 = 0x21;
        }
    }
}

// .text:0x0009CD90 size:0xE8 mapped:0x806DBE24
void fn_3_9CD90(void) {
    int i;

    if (lbl_3_common_bss_32A94._2 == 0) {
        if (g_Strikes.allForcedRunnersReachedTheirBaseInd == 3) {
            lbl_3_common_bss_32A94._0 = 0x10;
            return;
        }
        if (g_Runners[0].runnerOnFieldOrOutOrScored == 2) {
            if (g_Ball.AtBat_ContactResult == 3 || g_FieldingLogic._108 == 2) {
                if (g_Ball.Hit_VerticalAngle > 0xA0) {
                    lbl_3_common_bss_32A94._2 = 0x12;
                } else {
                    lbl_3_common_bss_32A94._2 = 0x13;
                }
            } else {
                lbl_3_common_bss_32A94._2 = 0x15;
            }
        }
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].forceOutCd == 2) {
                lbl_3_common_bss_32A94._2 = 0x15;
            }
        }
    }
}

// .text:0x0009CAF0 size:0x2A0 mapped:0x806DBB84
void fn_3_9CAF0(void) {
    if (g_Ball.deadBallReason == 1) {
        if (g_Ball.homeRunInd == 1) {
            if (g_Ball.homeRunClassification == 1) {
                lbl_3_common_bss_32A94._4 = 4;
            } else if (g_Ball.Hit_VerticalAngle < 0x100) {
                lbl_3_common_bss_32A94._4 = 8;
            } else {
                lbl_3_common_bss_32A94._4 = 12;
            }
        } else if (g_Ball.ballAngleFromHome < 0x400 - lbl_3_data_4380[g_d_GameSettings.StadiumID]) {
            if (g_Ball.homeRunClassification == 1) {
                lbl_3_common_bss_32A94._4 = 3;
            } else if (g_Ball.Hit_VerticalAngle < 0x100) {
                lbl_3_common_bss_32A94._4 = 7;
            } else {
                lbl_3_common_bss_32A94._4 = 11;
            }
        } else if (g_Ball.ballAngleFromHome > 0x400 + lbl_3_data_4380[g_d_GameSettings.StadiumID]) {
            if (g_Ball.homeRunClassification == 1) {
                lbl_3_common_bss_32A94._4 = 1;
            } else if (g_Ball.Hit_VerticalAngle < 0x100) {
                lbl_3_common_bss_32A94._4 = 5;
            } else {
                lbl_3_common_bss_32A94._4 = 9;
            }
        } else {
            if (g_Ball.homeRunClassification == 1) {
                lbl_3_common_bss_32A94._4 = 2;
            } else if (g_Ball.Hit_VerticalAngle < 0x100) {
                lbl_3_common_bss_32A94._4 = 6;
            } else {
                lbl_3_common_bss_32A94._4 = 10;
            }
        }
    } else if (g_Ball.AtBat_ContactResult == 3) {
        if (g_Runners[3].runnerOnFieldOrOutOrScored == 1 && g_Ball.timeSinceBallPickedUp < 60 &&
            g_Ball.framesSinceThrowStarted < 1 && g_Runners[3].tagUpInd == 0 &&
            g_Runners[3].fractionalBasesRan >= 3.15f) {
            lbl_3_common_bss_32A94._4 = 14;
        }
        if (g_Runners[3].runnerOnFieldOrOutOrScored == 3 && lbl_3_common_bss_32A94._4 == 14 &&
            g_Ball.framesSinceBallHitGroundOrWasCaught <= 240 && g_Strikes.storedOuts < 2) {
            lbl_3_common_bss_32A94._4 = 13;
            lbl_3_common_bss_32A94._0 = 17;
        }
        if (lbl_3_common_bss_32A94._4 == 14 &&
            (g_Runners[3].runningDirectionCode == 2 || g_Runners[3].runningDirectionCode == 3)) {
            lbl_3_common_bss_32A94._4 = 0;
        }
    }
}
