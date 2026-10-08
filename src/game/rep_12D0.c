#include "game/rep_12D0.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_18E8.h"
#include "game/rep_3DA8.h"

extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13[2];
    /* 0x15 */ u8 _15;
} g_RunningLogic;

typedef struct {
    /* 0x000 */ u8 _000[0x178];
    /* 0x178 */ s16 _178;
    /* 0x17A */ u8 _17A[0x1E0 - 0x17A];
    /* 0x1E0 */ u8 _1E0;
    /* 0x1E1 */ u8 _1E1[0x268 - 0x1E1];
} Unk12D0Fielder; // size: 0x268

extern Unk12D0Fielder g_Fielders[9];

extern f32 lbl_3_data_4444[10];

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ s16 _50[2][19];
    /* 0x9C */ s16 _9C;
    /* 0x9E */ u8 _9E[0xA0 - 0x9E];
    /* 0xA0 */ s16 _A0;
    /* 0xA2 */ u8 _A2[0xA8 - 0xA2];
    /* 0xA8 */ u8 _A8[2];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB[0xAD - 0xAB];
    /* 0xAD */ u8 _AD;
    /* 0xAE */ s8 _AE;
    /* 0xAF */ u8 _AF[0xB1 - 0xAF];
    /* 0xB1 */ s8 _B1[2];
    /* 0xB3 */ s8 _B3[2];
    /* 0xB5 */ s8 _B5[2];
    /* 0xB7 */ s8 _B7[2];
    /* 0xB9 */ u8 _B9[2];
    /* 0xBB */ u8 _BB[2];
    /* 0xBD */ u8 _BD[2];
} g_Scores;

typedef struct Unk12D0PitcherStats {
    /* 0x00 */ u8 _00[0xE];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u8 _10[0x1A - 0x10];
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B[0x1E - 0x1B];
} Unk12D0PitcherStats; // size: 0x1E

typedef struct Unk12D0PlayerStats {
    /* 0x00 */ u8 _00[0x11];
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13[0x15 - 0x13];
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17[0x1A - 0x17];
    /* 0x1A */ u8 positions[8];
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
    /* 0x24 */ u8 _24;
    /* 0x25 */ u8 _25;
} Unk12D0PlayerStats; // size: 0x26

extern Unk12D0PitcherStats lbl_803535C8[2][9];
extern Unk12D0PlayerStats lbl_803537E4[2][9];

extern struct {
    /* 0x00 */ u8 _00[8];
    /* 0x08 */ s16 _08[2][19];
    /* 0x54 */ s16 _54[2][19];
    union {
        /* 0xA0 */ s8 _A0[50];
        struct {
            /* 0xA0 */ u8 _A0_pad[0xBE - 0xA0];
            /* 0xBE */ s8 _BE[2][10][2];
        };
    };
    /* 0xE6 */ s8 _E6[2][5];
    /* 0xF0 */ u8 _F0[2];
} lbl_80353A90;

extern s8 lbl_3_common_bss_32A38[2][9][5];

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

extern int fn_3_6C938(int, int);

typedef struct {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2 : 4;
    /* 0x2 */ u8 inning : 4;
    /* 0x3 */ u8 _3;
} Unk12D0Slot; // size: 0x4

extern Unk12D0Slot lbl_80353260[2][9];
extern s8 lbl_80354720[2][9][4];

// .text:0x0007C194 size:0x68 mapped:0x806BB228
BOOL fn_3_7C194(void) {
    if (g_Stats.playFrameCounter < 90) {
        return FALSE;
    }
    if (g_Stats.playFrameCounter > g_Stats._28 - 60) {
        return FALSE;
    }
    return fn_3_6C938(1, 0x1100) != 0;
}

// .text:0x0007C190 size:0x4 mapped:0x806BB224
void fn_3_7C190(void) {
}

// .text:0x0007BC0C size:0x14 mapped:0x806BACA0
void fn_3_7BC0C(void) {
    g_Stats._39 = 1;
}

// .text:0x0007BBF8 size:0x14 mapped:0x806BAC8C
void fn_3_7BBF8(void) {
    g_Stats._39 = 1;
}

// .text:0x0007BBC0 size:0x38 mapped:0x806BAC54
Unk12D0PitcherStats* fn_3_7BBC0(void) {
    return &lbl_803535C8[g_GameLogic.teamFielding]
                        [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]];
}

// .text:0x0007BB74 size:0x4C mapped:0x806BAC08
Unk12D0PlayerStats* fn_3_7BB74(void) {
    return &lbl_803537E4[g_GameLogic.teamBatting]
                        [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.homeTeamBattingInd_fieldingTeam]
                                                                   [g_GameLogic.currentBatterPerTeam[g_GameLogic.homeTeamBattingInd_fieldingTeam]][0]];
}

// .text:0x0007B130 size:0x1D8 mapped:0x806BA1C4
void fn_3_7B130(void) {
    s32 i;
    int team;

    for (team = 0; team < 2; team++) {
        for (i = 0; i < 9; i++) {
            if (lbl_80354720[team][i][3] == 1) {
                lbl_80353260[team][i].inning = g_Scores._00;
            }
        }
    }
    for (i = 0; i < 5; i++) {
        lbl_3_common_bss_32A94._36[i] = 0;
    }
    lbl_3_common_bss_32A94._32 = -1;
    lbl_3_common_bss_32A94._34 = 0;
    lbl_3_common_bss_32A94._3C = 0;
    lbl_3_common_bss_32A94._60 = 1;
    lbl_3_common_bss_32A94._62 = lbl_3_common_bss_32A94._61;
    lbl_3_common_bss_32A94._61 = 0;
    lbl_3_common_bss_32A94._3E = 0;
    lbl_3_common_bss_32A94._3F = 0;
    lbl_3_common_bss_32A94._40 = 0;
    lbl_3_common_bss_32A94._41 = 0;
    lbl_3_common_bss_32A94._42 = 0;
    for (i = 0; i < 9; i++) {
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][i][2] = -1;
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][i][3] = -1;
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][i][4] = -1;
    }
    lbl_3_common_bss_32A38[g_GameLogic.teamFielding]
                          [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]][2] = 0;
}

// .text:0x0007AFE4 size:0x14C mapped:0x806BA078
void fn_3_7AFE4(void) {
    int i;
    int team = g_Scores._AD;
    int batter = g_GameLogic.currentBatterPerTeam[team];

    lbl_3_common_bss_32A94._22 = -1;
    lbl_3_common_bss_32A94._23 = 0;
    lbl_3_common_bss_32A94._24 = 0;
    lbl_3_common_bss_32A94._20 = -1;
    lbl_3_common_bss_32A94._25 = 0;
    lbl_3_common_bss_32A94._26 = 0;
    if (lbl_3_common_bss_32A94._61 < 0xFE) {
        lbl_3_common_bss_32A94._61++;
    } else {
        lbl_3_common_bss_32A94._61 = 0xFF;
    }
    if (batter == 1) {
        if (lbl_3_common_bss_32A94._61 > 1 || g_Scores._00 != 1) {
            lbl_3_common_bss_32A94._44[team]++;
        }
        fn_3_7AF68();
    }
    for (i = 0; i < 7; i++) {
        lbl_3_common_bss_32A94._2B[i] = 0;
    }
}

// .text:0x0007AF68 size:0x7C mapped:0x806BA000
void fn_3_7AF68(void) {
    int i;

    lbl_3_common_bss_32A94._22 = -1;
    lbl_3_common_bss_32A94._27 = 0;
    for (i = 1; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored != 0) {
            lbl_3_common_bss_32A94._28[i - 1] = 1;
        } else {
            lbl_3_common_bss_32A94._28[i - 1] = 0;
        }
    }
}

// .text:0x0007AEEC size:0x7C mapped:0x806B9F80
void fn_3_7AEEC(void) {
    int i;

    lbl_3_common_bss_32A94._22 = -1;
    lbl_3_common_bss_32A94._27 = 0;
    for (i = 1; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored != 0) {
            lbl_3_common_bss_32A94._28[i - 1] = 1;
        } else {
            lbl_3_common_bss_32A94._28[i - 1] = 0;
        }
    }
}

// .text:0x0007AEE8 size:0x4 mapped:0x806B9F7C
void fn_3_7AEE8(void) {
}

// .text:0x0007AEA8 size:0x40 mapped:0x806B9F3C
int fn_3_7AEA8(void) {
    return g_GameLogic.currentBatterPerTeam[g_GameLogic.homeTeamBattingInd_fieldingTeam] +
           (lbl_3_common_bss_32A94._44[g_GameLogic.homeTeamBattingInd_fieldingTeam] - 1) * 9 - 1;
}

// .text:0x0007AD68 size:0x140 mapped:0x806B9DFC
void fn_3_7AD68(void) {
    int i;
    int pitcher = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0];

    if (lbl_3_common_bss_32A38[g_GameLogic.teamFielding][pitcher][2] < 0) {
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][pitcher][2] = 0;
    } else {
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][pitcher][4] = 0;
    }
    for (i = 1; i < 10; i++) {
        int pos = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][1];
        int id = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0];
        if (pos > 0 && lbl_3_common_bss_32A38[g_GameLogic.teamFielding][id][2] == 0 &&
            pos != lbl_3_common_bss_32A38[g_GameLogic.teamFielding][id][3]) {
            lbl_3_common_bss_32A38[g_GameLogic.teamFielding][id][3] = pos;
        }
    }
}

// .text:0x0007AB78 size:0x1F0 mapped:0x806B9C0C
void fn_3_7AB78(int countAppearance) {
    int i;
    int pitcher;
    int catcher;

    if (countAppearance != 0) {
        if (g_Scores._BB[g_GameLogic.awayTeamBattingInd_battingTeam] < 0xFE) {
            g_Scores._BB[g_GameLogic.awayTeamBattingInd_battingTeam]++;
        } else {
            g_Scores._BB[g_GameLogic.awayTeamBattingInd_battingTeam] = 0xFF;
        }
    }
    pitcher = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0];
    for (i = 1; i < 10; i++) {
        if (g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][1] == 1) {
            catcher = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0];
            break;
        }
    }
    if (lbl_80353A90._BE[g_GameLogic.teamFielding][0][0] == -1) {
        lbl_80353A90._BE[g_GameLogic.teamFielding][0][0] = pitcher;
        lbl_80353A90._BE[g_GameLogic.teamFielding][0][1] = 1;
        lbl_80353A90._E6[g_GameLogic.teamFielding][0] = catcher;
        return;
    }
    for (i = 1; i < 10; i++) {
        if (lbl_80353A90._BE[g_GameLogic.teamFielding][i][0] == -1) {
            if (lbl_80353A90._BE[g_GameLogic.teamFielding][i - 1][0] != pitcher) {
                lbl_80353A90._BE[g_GameLogic.teamFielding][i][0] = pitcher;
                lbl_80353A90._BE[g_GameLogic.teamFielding][i][1] = g_Scores._00;
                if (lbl_3_common_bss_32A94._4C[g_GameLogic.awayTeamBattingInd_battingTeam] < 0x7FFE) {
                    lbl_3_common_bss_32A94._4C[g_GameLogic.awayTeamBattingInd_battingTeam]++;
                } else {
                    lbl_3_common_bss_32A94._4C[g_GameLogic.awayTeamBattingInd_battingTeam] = 0x7FFF;
                }
            }
            break;
        }
    }
    if (countAppearance == 0) {
        for (i = 1; i < 5; i++) {
            if (lbl_80353A90._E6[g_GameLogic.teamFielding][i] == -1) {
                if (lbl_80353A90._E6[g_GameLogic.teamFielding][i - 1] != catcher) {
                    lbl_80353A90._E6[g_GameLogic.teamFielding][i] = catcher;
                }
                return;
            }
        }
    }
}

// .text:0x0007AB34 size:0x44 mapped:0x806B9BC8
void fn_3_7AB34(void) {
    fn_3_7BBC0()->_0E++;
}

// .text:0x00079EF4 size:0x260 mapped:0x806B8F88
void fn_3_79EF4(void) {
    int lead;
    int i;
    int n;

    lead = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] -
           g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0];
    if (lead > 0 && lead <= g_Scores._9C) {
        g_Scores._AE = g_Scores._00;
    }
    if (lead >= 0) {
        g_Scores._B5[g_GameLogic.homeTeamBattingInd_fieldingTeam] = -1;
    }
    if (lead <= g_Scores._9C && lead > 0) {
        if (g_Scores._9C == 1) {
            for (i = 0; i < 4; i++) {
                if (g_Runners[i].runnerOnFieldOrOutOrScored == 3) {
                    g_Scores._B5[g_GameLogic.awayTeamBattingInd_battingTeam] = g_Runners[i].pitcherWhoLetRunnerOnBase;
                    break;
                }
            }
        } else {
            n = g_Scores._9C;
            for (i = 3; i >= 0; i--) {
                if (g_Runners[i].runnerOnFieldOrOutOrScored == 3) {
                    if (lead == n) {
                        g_Scores._B5[g_GameLogic.awayTeamBattingInd_battingTeam] =
                            g_Runners[i].pitcherWhoLetRunnerOnBase;
                        break;
                    }
                    n--;
                }
            }
        }
    }
    if (lead >= 0) {
        g_Scores._B3[g_GameLogic.awayTeamBattingInd_battingTeam] = -1;
        if (g_Scores._B9[g_GameLogic.awayTeamBattingInd_battingTeam] == 1) {
            if (g_Scores._BB[g_GameLogic.homeTeamBattingInd_fieldingTeam] == 1) {
                g_Scores._B9[g_GameLogic.awayTeamBattingInd_battingTeam] = 0;
            } else {
                g_Scores._B9[g_GameLogic.awayTeamBattingInd_battingTeam] = 2;
            }
        }
    }
    if (lead <= g_Scores._9C && lead > 0) {
        g_Scores._B3[g_GameLogic.homeTeamBattingInd_fieldingTeam] = g_Scores._B1[g_GameLogic.homeTeamBattingInd_fieldingTeam];
        g_Scores._BD[g_GameLogic.homeTeamBattingInd_fieldingTeam] = g_Scores._BB[g_GameLogic.homeTeamBattingInd_fieldingTeam];
        if (g_Scores._B9[g_GameLogic.homeTeamBattingInd_fieldingTeam] == 0) {
            if (g_Scores._BB[g_GameLogic.homeTeamBattingInd_fieldingTeam] == 1) {
                g_Scores._B9[g_GameLogic.homeTeamBattingInd_fieldingTeam] = 1;
            } else {
                g_Scores._B9[g_GameLogic.homeTeamBattingInd_fieldingTeam] = 2;
            }
        } else if (g_Scores._B9[g_GameLogic.homeTeamBattingInd_fieldingTeam] == 1 &&
                   g_Scores._BB[g_GameLogic.homeTeamBattingInd_fieldingTeam] > 1) {
            g_Scores._B9[g_GameLogic.homeTeamBattingInd_fieldingTeam] = 2;
        }
    }
    if (lead >= 0) {
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding]
                              [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]][1] = 0;
    }
}

// .text:0x00079DD4 size:0x120 mapped:0x806B8E68
void fn_3_79DD4(void) {
    int lead;
    int runners;
    int pitcher;
    int i;

    lead = g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0] -
           g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0];
    g_Scores._B7[g_GameLogic.awayTeamBattingInd_battingTeam] = -1;
    if (lead <= 0) {
        return;
    }
    if (g_Scores._00 + 2 < g_Scores._AA || (g_Scores._00 + 2 == g_Scores._AA && g_Strikes.outs == 0)) {
        goto save;
    }
    if (lead <= 3 && (g_Scores._00 < g_Scores._AA || (g_Scores._00 >= g_Scores._AA && g_Strikes.outs == 0))) {
        goto save;
    }
    runners = 0;
    for (i = 1; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            runners++;
        }
    }
    if (lead > runners + 2) {
        return;
    }
save:
    pitcher = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0];
    g_Scores._B7[g_GameLogic.awayTeamBattingInd_battingTeam] = pitcher;
    lbl_3_common_bss_32A38[g_GameLogic.teamFielding][pitcher][1] = 1;
}

// .text:0x00079ACC size:0x308 mapped:0x806B8B60
void fn_3_79ACC(void) {
    if (lbl_3_common_bss_32A94._22 == -1) {
        fn_3_7976C();
    } else if (lbl_3_common_bss_32A94._22 >= 1) {
        fn_3_795A8();
    }
    if (lbl_3_common_bss_32A94._22 == 1 && lbl_3_common_bss_32A94._20 == 0 &&
        g_Strikes.allForcedRunnersReachedTheirBaseInd == 0 &&
        (g_FieldingLogic._113 == 0 || g_Ball.lineDriveThroughPitcherInd != 0 || g_FieldingLogic._121 >= 0)) {
        g_Strikes.allForcedRunnersReachedTheirBaseInd = 1;
    }
    if (g_Ball.maybeBuntInd != 0) {
        fn_3_79414();
    } else {
        fn_3_79338();
    }
    fn_3_79A00();
    fn_3_78AC4();
    fn_3_78730();
    if ((g_Batter.captainStarSwingActivated != 0 || g_Batter.nonCaptainStarSwingActivated != 0 ||
         g_Batter.moonShotInd != 0) &&
        g_Ball.framesSinceHit == 1) {
        if (lbl_803537E4[g_GameLogic.teamBatting][g_Batter.rosterID]._24 < 0xFE) {
            lbl_803537E4[g_GameLogic.teamBatting][g_Batter.rosterID]._24++;
        } else {
            lbl_803537E4[g_GameLogic.teamBatting][g_Batter.rosterID]._24 = 0xFF;
        }
    }
}

// .text:0x00079A00 size:0xCC mapped:0x806B8A94
void fn_3_79A00(void) {
    s16 forceOut;

    if (lbl_3_common_bss_32A94._25 == -1) {
        return;
    }
    if (lbl_3_common_bss_32A94._25 == 0 && g_Strikes.runnerIndexForEachOutThisPitch[0] >= 0) {
        if (g_Runners[g_Strikes.runnerIndexForEachOutThisPitch[0]].forceOutCd == 2) {
            lbl_3_common_bss_32A94._25 = 1;
        } else {
            lbl_3_common_bss_32A94._25 = -1;
        }
    }
    if (lbl_3_common_bss_32A94._25 == 1 && g_Strikes.runnerIndexForEachOutThisPitch[1] >= 0) {
        forceOut = g_Runners[g_Strikes.runnerIndexForEachOutThisPitch[1]].forceOutCd;
        if (forceOut == 2) {
            lbl_3_common_bss_32A94._25 = 2;
        } else if (forceOut == -1) {
            lbl_3_common_bss_32A94._25 = 3;
        } else {
            lbl_3_common_bss_32A94._25 = -1;
        }
    }
}

// .text:0x0007976C size:0x294 mapped:0x806B8800
void fn_3_7976C(void) {
    int i;
    int force = 0;
    int result = -1;

    if (g_FieldingLogic._107 != 0) {
        lbl_3_common_bss_32A94._22 = 0;
        return;
    }
    if (g_Ball.ballInitialHitDoneInd != 0 && g_Ball.AtBat_ContactResult != 0 && g_Ball.AtBat_ContactResult != -1) {
        if (g_Ball.AtBat_ContactResult == 3 || g_FieldingLogic._108 == 2) {
            result = 0;
        } else if (g_Ball.deadBallReason == 1 || g_Ball.deadBallReason == 3) {
            result = 1;
        } else {
            for (i = 0; i < 4; i++) {
                if (g_Runners[i].forceOutCd == 1) {
                    force = 1;
                }
                if (g_Runners[i].forceOutCd == 2) {
                    force = 2;
                }
            }
            if (force == 2) {
                result = 0;
            } else if (force == 0) {
                if (lbl_3_common_bss_32A94._27 == 2 && g_Runners[0].runnerOnFieldOrOutOrScored == 1) {
                    result = 1;
                }
                if (g_Ball.fielderWithBallIndexStored2 >= 0 && g_Ball.fielderWithBallIndexStored2 <= 5 &&
                    g_Ball.ballZoneWhenCaught <= 1 && result == 1) {
                    for (i = 1; i < 4; i++) {
                        if (g_Runners[i].runnerOnFieldOrOutOrScored == 2) {
                            result = 0;
                            goto end;
                        }
                    }
                    for (i = 1; i < 4; i++) {
                        if (g_Runners[i].runnerOnFieldOrOutOrScored != 0 && g_Runners[i].baseStandingOn < 0 &&
                            g_Runners[i].runnerOnFieldOrOutOrScored != 3 &&
                            g_Runners[i].currentBase <= g_Runners[i].startingBase_baseAchieved) {
                            break;
                        }
                    }
                    if (i < 4) {
                        result = -1;
                    }
                }
            }
        }
    }
end:
    lbl_3_common_bss_32A94._22 = result;
}

// .text:0x000795A8 size:0x1C4 mapped:0x806B863C
void fn_3_795A8(void) {
    int base;

    if (lbl_3_common_bss_32A94._23 > 0) {
        return;
    }
    if (g_Ball.deadBallReason == 1) {
        lbl_3_common_bss_32A94._23 = lbl_3_common_bss_32A94._22 = 4;
        return;
    }
    if (g_Ball.deadBallReason == 3) {
        lbl_3_common_bss_32A94._23 = lbl_3_common_bss_32A94._22 = 2;
        return;
    }
    if (g_Runners[0].runnerOnFieldOrOutOrScored == 3) {
        lbl_3_common_bss_32A94._23 = lbl_3_common_bss_32A94._22 = 4;
        return;
    }
    if (g_Ball.ballZoneAwayFromHome <= 1 && g_Ball.ballState != 0) {
        if (g_Runners[0].currentBase == 0) {
            base = 1;
        } else if (g_Runners[0].percentTowardsNextBase < 0.3f) {
            if (g_Runners[0].runnerOnFieldOrOutOrScored == 2 && g_Runners[0].percentTowardsNextBase == 0.0f) {
                base = g_Runners[0].currentBase - 1;
            } else {
                base = g_Runners[0].currentBase;
            }
        } else {
            base = g_Runners[0].nextBase;
        }
        lbl_3_common_bss_32A94._23 = -base;
    }
    if (g_Runners[0].currentBase == -lbl_3_common_bss_32A94._23 && lbl_3_common_bss_32A94._23 != 0) {
        lbl_3_common_bss_32A94._23 *= -1;
        if ((s8)g_Runners[0].baseOfFailedBodyCheck == lbl_3_common_bss_32A94._23) {
            lbl_3_common_bss_32A94._23--;
        }
        lbl_3_common_bss_32A94._22 = lbl_3_common_bss_32A94._23;
        return;
    }
    if (g_Runners[0].currentBase - 1 == -lbl_3_common_bss_32A94._23 && lbl_3_common_bss_32A94._23 != 0) {
        if ((s8)g_Runners[0].baseOfFailedBodyCheck == (1 - lbl_3_common_bss_32A94._23) % 4) {
            lbl_3_common_bss_32A94._22 = lbl_3_common_bss_32A94._23 *= -1;
            return;
        }
    }
    if (g_Runners[0].currentBase != 0) {
        lbl_3_common_bss_32A94._22 = g_Runners[0].currentBase;
    }
}

// .text:0x00079414 size:0x194 mapped:0x806B84A8
void fn_3_79414(void) {
    int count;
    int forced;
    int i;
    InMemRunnerType* runner;

    if (g_Ball.maybebuntOn2Strikes != 0) {
        lbl_3_common_bss_32A94._24 = 14;
        return;
    }
    if (g_Strikes.storedOuts < 2 && g_RunningLogic._12 > 1) {
        if (lbl_3_common_bss_32A94._24 == 0 &&
            (g_Ball.ballState == 1 || g_Ball.ballState == 2 || g_FieldingLogic._0CC >= 0 || g_FieldingLogic._0E8 >= 0)) {
            lbl_3_common_bss_32A94._24 = 12;
        }
        if (lbl_3_common_bss_32A94._24 == 12 || lbl_3_common_bss_32A94._24 == 15) {
            count = 0;
            forced = 0;
            for (i = 1; i < 4; i++) {
                if (g_Runners[i].forceOutCd != 0) {
                    forced++;
                }
            }
            for (i = 1; i < 4; i++) {
                runner = &g_Runners[i];
                if (runner->currentBase > runner->startingBase_baseAchieved || runner->runnerOnFieldOrOutOrScored == 3) {
                    if (runner->currentBase == 4 && runner->startingBase_baseAchieved == 3 &&
                        runner->runnerOnFieldOrOutOrScored == 2) {
                        lbl_3_common_bss_32A94._24 = 13;
                        break;
                    }
                    if (runner->forceOutCd == 0) {
                        count++;
                    }
                } else if (runner->runnerOnFieldOrOutOrScored == 2) {
                    lbl_3_common_bss_32A94._24 = 13;
                    break;
                }
            }
            if (count != 0 && forced == 0) {
                lbl_3_common_bss_32A94._24 = 11;
            }
        }
    }
}

// .text:0x00079338 size:0xDC mapped:0x806B83CC
void fn_3_79338(void) {
    int i;

    if (g_Strikes.storedOuts != 2 && g_Strikes.outs < 3) {
        if (lbl_3_common_bss_32A94._24 == 0) {
            if ((g_Ball.AtBat_ContactResult == 3 || g_FieldingLogic._113 == 1) && g_Ball.landingSpotZoneAwayFromHome >= 2) {
                lbl_3_common_bss_32A94._24 = 2;
            }
        } else if (lbl_3_common_bss_32A94._24 == 2 && g_Ball.AtBat_ContactResult == 3) {
            for (i = 1; i < 4; i++) {
                if (g_Runners[i].runnerOnFieldOrOutOrScored == 3) {
                    lbl_3_common_bss_32A94._24 = 1;
                }
            }
        }
    }
}

// .text:0x00079040 size:0x2F8 mapped:0x806B80D4
void fn_3_79040(void) {
    s32 out0;
    s32 out1;
    int frames;

    if (lbl_3_common_bss_32A94._20 != -1) {
        return;
    }
    if (g_Ball.fielderWBallIndex > 5) {
        lbl_3_common_bss_32A94._20 = 0;
        return;
    }
    if (g_Runners[0].runnerOnFieldOrOutOrScored != 1 || g_Runners[0].currentBase != 0) {
        lbl_3_common_bss_32A94._20 = 0;
        return;
    }
    if (g_FieldingLogic._0C4 == 1) {
        lbl_3_common_bss_32A94._20 = 0;
        return;
    }
    frames = fn_3_A63E4(0, 1, &out0, &out1) + 10;
    if (g_Fielders[g_Ball.fielderWBallIndex]._1E0 != 0) {
        frames += 20;
    }
    if (frames >= 0) {
        lbl_3_common_bss_32A94._20 = 0;
        return;
    }
    lbl_3_common_bss_32A94._20 = 5;
    if (g_FieldingLogic._0C4 == 0) {
        if (g_Runners[3].runnerOnFieldOrOutOrScored == 1) {
            lbl_3_common_bss_32A94._20 = 3;
        }
        if (g_Runners[3].runnerOnFieldOrOutOrScored == 3 && g_Runners[3].timeStandingOnBase < 60) {
            lbl_3_common_bss_32A94._20 = 3;
        }
        if (g_Runners[2].runnerOnFieldOrOutOrScored == 1 && g_Runners[2].currentBase == 3 &&
            lbl_3_common_bss_32A94._20 == 3) {
            lbl_3_common_bss_32A94._20 = 23;
        }
    } else if (g_FieldingLogic._0C4 == 3) {
        if (g_Runners[1].runnerOnFieldOrOutOrScored == 1 && g_Runners[1].currentBase == 2) {
            if (g_Runners[3].runnerOnFieldOrOutOrScored == 1 && g_Runners[2].runnerOnFieldOrOutOrScored == 1) {
                lbl_3_common_bss_32A94._20 = 123;
            } else if (g_Runners[3].runnerOnFieldOrOutOrScored == 1) {
                lbl_3_common_bss_32A94._20 = 13;
            } else if (g_Runners[2].runnerOnFieldOrOutOrScored == 1) {
                lbl_3_common_bss_32A94._20 = 12;
            } else {
                lbl_3_common_bss_32A94._20 = 1;
            }
        } else if (g_Runners[3].runnerOnFieldOrOutOrScored == 1 && g_Runners[2].runnerOnFieldOrOutOrScored == 1) {
            lbl_3_common_bss_32A94._20 = 23;
        } else if (g_Runners[3].runnerOnFieldOrOutOrScored == 1) {
            lbl_3_common_bss_32A94._20 = 3;
        } else if (g_Runners[2].runnerOnFieldOrOutOrScored == 1) {
            lbl_3_common_bss_32A94._20 = 2;
        }
    } else if (g_FieldingLogic._0C4 == 2) {
        if (g_Runners[2].runnerOnFieldOrOutOrScored == 1 && g_Runners[1].runnerOnFieldOrOutOrScored == 1) {
            lbl_3_common_bss_32A94._20 = 12;
        } else if (g_Runners[2].runnerOnFieldOrOutOrScored == 1) {
            lbl_3_common_bss_32A94._20 = 2;
        } else if (g_Runners[1].runnerOnFieldOrOutOrScored == 1) {
            lbl_3_common_bss_32A94._20 = 1;
        }
    }
    if (lbl_3_common_bss_32A94._20 == 5) {
        g_FieldingLogic._0EA = g_Ball.fielderWBallIndex;
    }
}

// .text:0x00078AC4 size:0x57C mapped:0x806B7B58
// 99.72%: one extra `b` to the epilogue after the unrolled state == 5 loop (break, return,
// while, continue and pointer forms all keep it); everything else matches.
void fn_3_78AC4(void) {
    s32 state = lbl_3_common_bss_32A94._20;
    BOOL batterSafe = FALSE;
    int i;
    u8 status;

    if (lbl_3_common_bss_32A94._27 == 0 && g_Ball.ballState == 1) {
        lbl_3_common_bss_32A94._27 = 2;
        if ((g_Runners[0].forceOutCd != 0 || g_Runners[0].runnerOnFieldOrOutOrScored != 1) &&
            g_Ball.AtBat_ContactResult != 3 && g_Ball.ballZoneAwayFromHome < 2 &&
            fn_3_A6810(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z, lbl_3_data_4444[2],
                       lbl_3_data_4444[3]) + 75 < g_Runners[0].framesToNextBase) {
            lbl_3_common_bss_32A94._27 = 1;
        }
    } else if (lbl_3_common_bss_32A94._27 == 0 && g_Ball.AtBat_ContactResult != 0 && g_Ball.ballState != 1 &&
               g_Runners[0].runnerOnFieldOrOutOrScored == 1 && g_Runners[0].currentBase >= 1) {
        lbl_3_common_bss_32A94._27 = 2;
    }
    if (lbl_3_common_bss_32A94._27 == 1) {
        for (i = 1; i < 4; i++) {
            if (g_Runners[i].baseStandingOn >= 0 || g_Runners[i].runnerOnFieldOrOutOrScored == 3) {
                lbl_3_common_bss_32A94._28[i - 1] = 2;
            }
        }
        for (i = 0; i < 3; i++) {
            if (lbl_3_common_bss_32A94._28[i] == 1) {
                break;
            }
        }
        if (i >= 3) {
            lbl_3_common_bss_32A94._27 = 2;
        }
    }
    if (g_Runners[0].forceOutCd == 0 && g_Runners[0].runnerOnFieldOrOutOrScored == 1) {
        batterSafe = TRUE;
    }
    if (state == 5) {
        if (batterSafe) {
            g_FieldingLogic._113 = 9;
            lbl_3_common_bss_32A94._20 = 0;
            g_Runners[0].runnerDidntReachOnError = 0;
            g_FieldingLogic._132 = 3;
        }
        for (i = 0; i < 4; i++) {
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 2 && g_Runners[i].forceOutCd == 2) {
                lbl_3_common_bss_32A94._20 = 0;
                break;
            }
        }
    } else {
        if (g_Runners[0].runnerOnFieldOrOutOrScored == 2 && g_Runners[0].currentBase == 0) {
            lbl_3_common_bss_32A94._20 = 0;
            return;
        }
        if (state == -1 || state == 0 || state == 4) {
            if (state == -1 && g_Runners[0].currentBase >= 1 &&
                (g_Ball.AtBat_ContactResult == 1 || g_Ball.AtBat_ContactResult == 2)) {
                lbl_3_common_bss_32A94._20 = 0;
            }
            if (lbl_3_common_bss_32A94._20 == 4 && g_Strikes.allForcedRunnersReachedTheirBaseInd == 0 &&
                g_Runners[0].forceOutCd == 0) {
                g_Strikes.allForcedRunnersReachedTheirBaseInd = 3;
            }
        } else if (state >= 100) {
            if (g_Runners[1].runnerOnFieldOrOutOrScored == 2 || g_Runners[2].runnerOnFieldOrOutOrScored == 2 ||
                g_Runners[3].runnerOnFieldOrOutOrScored == 2) {
                lbl_3_common_bss_32A94._20 = 0;
                return;
            }
            if (g_Runners[1].baseStandingOn >= 0 && g_Runners[1].runnerOnFieldOrOutOrScored != 2) {
                lbl_3_common_bss_32A94._20 = 23;
                return;
            }
            if (g_Runners[2].baseStandingOn >= 0 && g_Runners[2].runnerOnFieldOrOutOrScored != 2) {
                lbl_3_common_bss_32A94._20 = 13;
                return;
            }
            if (g_Runners[3].baseStandingOn >= 0 && g_Runners[3].runnerOnFieldOrOutOrScored != 2) {
                lbl_3_common_bss_32A94._20 = 12;
            }
        } else if (state >= 10) {
            if (g_Runners[state / 10].runnerOnFieldOrOutOrScored == 2 ||
                g_Runners[state % 10].runnerOnFieldOrOutOrScored == 2) {
                lbl_3_common_bss_32A94._20 = 0;
                return;
            }
            if (g_Runners[state / 10].baseStandingOn >= 0 && g_Runners[state / 10].runnerOnFieldOrOutOrScored != 2) {
                lbl_3_common_bss_32A94._20 = state % 10;
                return;
            }
            if (g_Runners[state % 10].baseStandingOn >= 0 && g_Runners[state % 10].runnerOnFieldOrOutOrScored != 2) {
                lbl_3_common_bss_32A94._20 = state / 10;
            }
        } else {
            status = g_Runners[state].runnerOnFieldOrOutOrScored;
            if (status == 2) {
                lbl_3_common_bss_32A94._20 = 0;
            }
            if (((g_Runners[state].baseStandingOn >= 0 && status == 1) || status == 3) && batterSafe) {
                lbl_3_common_bss_32A94._20 = 4;
            }
        }
    }
}

// .text:0x00078730 size:0x394 mapped:0x806B77C4
void fn_3_78730(void) {
    int i;
    int idx;

    if (g_FieldingLogic._107 != 0) {
        if (g_FieldingLogic._127 != 0) {
            return;
        }
        if (g_FieldingLogic._126 < 0 && g_Ball.framesSinceHit > 160) {
            g_FieldingLogic._127 = -1;
            return;
        }
        if (g_FieldingLogic._107 == 1 && g_FieldingLogic._126 >= 0) {
            if (g_FieldingLogic._126 <= 3) {
                if (g_Ball.looseBall_codeForHowLongUntilSomeoneWillGetIt == 1) {
                    g_FieldingLogic._126 += 4;
                }
            } else if (g_FieldingLogic._126 <= 7) {
                idx = g_FieldingLogic._126 - 4;
                if (g_Runners[idx].runnerOnFieldOrOutOrScored == 3) {
                    g_FieldingLogic._127 = 1;
                    return;
                }
                if (g_Runners[idx].baseStandingOn >= idx + 1) {
                    g_FieldingLogic._127 = 1;
                    return;
                }
            }
        }
        if (g_FieldingLogic._107 == 2 && g_FieldingLogic._126 >= 0) {
            if (g_FieldingLogic._126 <= 3) {
                if (g_FieldingLogic._126 == 3) {
                    g_FieldingLogic._127 = -1;
                    return;
                }
                if (g_Ball.looseBall_codeForHowLongUntilSomeoneWillGetIt == 1) {
                    g_FieldingLogic._126 += 4;
                }
            } else if (g_FieldingLogic._126 <= 7) {
                idx = g_FieldingLogic._126 - 4;
                if (g_Runners[idx].runnerOnFieldOrOutOrScored == 3) {
                    g_FieldingLogic._127 = 2;
                    return;
                }
                if (g_Runners[idx].baseStandingOn >= idx + 2) {
                    g_FieldingLogic._127 = 2;
                    return;
                }
            }
        }
        return;
    } else {
        if (g_FieldingLogic._113 == 9 && g_Runners[0].currentBase >= 1) {
            g_Strikes.allForcedRunnersReachedTheirBaseInd = 2;
            return;
        }
        if ((g_FieldingLogic._113 == 1 || g_FieldingLogic._113 == 2) && g_Ball.lineDriveThroughPitcherInd == 0 &&
            g_FieldingLogic._121 < 0 && g_FieldingLogic._129 == 0 && g_Ball.AtBat_ContactResult != 0 &&
            g_Ball.deadBallReason == 0) {
            if ((g_Runners[0].runnerOnFieldOrOutOrScored == 1 && g_Runners[0].fractionalBasesRan >= 1.0f) ||
                g_Runners[0].runnerOnFieldOrOutOrScored == 3) {
                if (g_FieldingLogic._113 == 1) {
                    g_FieldingLogic._132 = 1;
                } else {
                    g_FieldingLogic._132 = 2;
                }
                g_FieldingLogic._113 = 9;
                g_Runners[0].runnerDidntReachOnError = 0;
            }
            if (g_Runners[0].runnerOnFieldOrOutOrScored == 2 &&
                (g_Runners[0].forceOutCd == 2 || g_Ball.AtBat_ContactResult == 3)) {
                g_FieldingLogic._113 = 0;
            }
        }
        if (g_FieldingLogic._113 >= 3 && g_FieldingLogic._113 <= 7) {
            if ((g_Runners[g_FieldingLogic._113 - 3].runnerOnFieldOrOutOrScored == 1 &&
                 g_Runners[g_FieldingLogic._113 - 3].baseStandingOn >= 0 &&
                 g_Runners[g_FieldingLogic._113 - 3].forceOutCd <= 0) ||
                g_Runners[g_FieldingLogic._113 - 3].runnerOnFieldOrOutOrScored == 3) {
                g_FieldingLogic._113 = 9;
                g_Runners[0].runnerDidntReachOnError = 0;
                g_FieldingLogic._132 = 3;
            }
            if (g_Runners[g_FieldingLogic._113 - 3].runnerOnFieldOrOutOrScored == 2) {
                g_FieldingLogic._113 = 0;
            }
        }
        if (g_FieldingLogic._113 == 9 && g_Strikes.storedOuts == 2) {
            for (i = 0; i < 4; i++) {
                g_Runners[i].runnerDidntReachOnError = 0;
            }
        }
    }
}

// .text:0x00078574 size:0x1BC mapped:0x806B7608
// 99.01%: from the g_Ball load on, volatile registers differ (g_Ball r6 for r7, _0C4 r7 for r8,
// runner r10 for r6); every declaration order gives the same.
void fn_3_78574(s32 fielder) {
    BOOL beatRunner = FALSE;
    int frames;
    int base;
    InMemRunnerType* runner;

    if (g_FieldingLogic._126 == -1) {
        if (g_FieldingLogic._107 == 1) {
            if (g_Runners[g_FieldingLogic._0C4].runnerOnFieldOrOutOrScored != 1) {
                g_FieldingLogic._127 = -1;
                return;
            }
            g_FieldingLogic._126 = g_FieldingLogic._0C4;
        }
        if (g_FieldingLogic._107 == 2) {
            base = (g_FieldingLogic._0C4 + 3) & 3;
            if (g_Runners[base].runnerOnFieldOrOutOrScored != 1) {
                g_FieldingLogic._127 = -1;
                return;
            }
            g_FieldingLogic._126 = base;
        }
    }
    if (g_FieldingLogic._107 != 0 || g_Ball.numberOfThrowsDuringPlay > 1 || g_FieldingLogic._0C4 < 0 ||
        g_FieldingLogic._0C4 > 3) {
        return;
    }
    if (g_Ball.AtBat_ContactResult != 3 && lbl_3_common_bss_32A94._22 < 1 && g_Ball.ballZoneAwayFromHome < 2 &&
        g_Strikes.outs <= g_Strikes.storedOuts) {
        base = (g_FieldingLogic._0C4 + 3) & 3;
        runner = &g_Runners[base];
        if (runner->runnerOnFieldOrOutOrScored == 1) {
            frames = g_Ball.framesUntilThrowReachesDest + 15;
            if (runner->forceOutCd == 0) {
                if (g_FieldingLogic._0C4 != runner->baseRunningTowards) {
                    return;
                }
                if (g_FieldingLogic._0C4 == runner->currentBase) {
                    return;
                }
                frames += 30;
            }
            if (frames < g_Runners[base].framesToNextBase) {
                beatRunner = TRUE;
            }
            if (beatRunner) {
                g_FieldingLogic._0EA = fielder;
                g_FieldingLogic._113 = base + 3;
            }
        }
    }
}

// .text:0x00077914 size:0xC60 mapped:0x806B69A8
// 99.64%: in the g_Scores copies after fn_3_76A9C, the g_Scores base, `&_04[H]` and the scaled
// inning swap registers (r12, r10, r23) and one `add` is scheduled earlier; the rest matches.
void fn_3_77914(void) {
    s32 pitcher = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0];
    s16 result = 0;
    s16 fielder = -1;
    s32 streak = 0;
    Unk12D0PitcherStats* pitcherStats = &lbl_803535C8[g_GameLogic.teamFielding][pitcher];
    int i;
    int j;

    if (g_Stats.replayInd != 0) {
        return;
    }
    if (g_Ball.AtBat_ContactResult == -1 && g_Ball.maybebuntOn2Strikes == 0) {
        return;
    }
    if (g_FieldingLogic._107 != 0 && g_FieldingLogic._107 != 4) {
        fn_3_76A9C();
        lbl_80353A90._08[g_GameLogic.teamBatting][g_Scores._00] =
            g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][g_Scores._00];
        lbl_80353A90._08[g_GameLogic.teamBatting][0] = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0];
        lbl_80353A90._54[g_GameLogic.teamBatting][g_Scores._00] =
            g_Scores._50[g_GameLogic.homeTeamBattingInd_fieldingTeam][g_Scores._00];
        lbl_80353A90._54[g_GameLogic.teamBatting][0] = g_Scores._50[g_GameLogic.homeTeamBattingInd_fieldingTeam][0];
        lbl_80353A90._F0[g_GameLogic.teamBatting] = g_Scores._A8[g_GameLogic.homeTeamBattingInd_fieldingTeam];
        lbl_80353A90._F0[g_GameLogic.teamFielding] = g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam];
        if (g_FieldingLogic._107 == 2) {
            if (g_FieldingLogic._126 != 0) {
                if (lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[1]._178]._16 < 0xFE) {
                    lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[1]._178]._16++;
                } else {
                    lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[1]._178]._16 = 0xFF;
                }
            }
            if (g_FieldingLogic._127 == 2) {
                if (g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam] < 0xFE) {
                    g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam]++;
                } else {
                    g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam] = 0xFF;
                }
                if (lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[1]._178]._15 < 0xFE) {
                    lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[1]._178]._15++;
                } else {
                    lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[1]._178]._15 = 0xFF;
                }
            }
        }
        if (g_FieldingLogic._107 == 1) {
            if (g_FieldingLogic._126 != 0) {
                if (lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[0]._178]._16 < 0xFE) {
                    lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[0]._178]._16++;
                } else {
                    lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[0]._178]._16 = 0xFF;
                }
            }
            if (g_FieldingLogic._127 == 2) {
                if (g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam] < 0xFE) {
                    g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam]++;
                } else {
                    g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam] = 0xFF;
                }
                if (lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[0]._178]._15 < 0xFE) {
                    lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[0]._178]._15++;
                } else {
                    lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[0]._178]._15 = 0xFF;
                }
            }
        }
        if (g_Pitcher.strikeOutOrWalk != 1 && g_Pitcher.strikeOutOrWalk != 2) {
            if (g_Strikes.outs > g_Strikes.storedOuts) {
                if (pitcherStats->_1A < 0xFF - g_Strikes.outs - g_Strikes.storedOuts) {
                    pitcherStats->_1A += g_Strikes.outs - g_Strikes.storedOuts;
                } else {
                    pitcherStats->_1A = 0xFF;
                }
                if (g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0] >
                    g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0]) {
                    lbl_3_common_bss_32A38[g_GameLogic.awayTeamBattingInd_battingTeam][pitcher][0] +=
                        g_Strikes.outs - g_Strikes.storedOuts;
                }
            }
            lbl_3_common_bss_32A94._26 = 0;
            goto positions;
        }
    }
    if (g_Pitcher.strikeOutOrWalk == 1 || lbl_3_common_bss_32A94._24 == 14) {
        result = 1;
        if (lbl_3_common_bss_32A94._65[g_GameLogic.awayTeamBattingInd_battingTeam] < 0xFE) {
            lbl_3_common_bss_32A94._65[g_GameLogic.awayTeamBattingInd_battingTeam]++;
        } else {
            lbl_3_common_bss_32A94._65[g_GameLogic.awayTeamBattingInd_battingTeam] = 0xFF;
        }
    } else {
        lbl_3_common_bss_32A94._65[g_GameLogic.awayTeamBattingInd_battingTeam] = 0;
        if (g_Pitcher.strikeOutOrWalk == 2) {
            result = 2;
            if (lbl_3_common_bss_32A94._40 < 0xFE) {
                lbl_3_common_bss_32A94._40++;
            } else {
                lbl_3_common_bss_32A94._40 = 0xFF;
            }
            if (lbl_3_common_bss_32A94._42 < 0xFE) {
                lbl_3_common_bss_32A94._42++;
            } else {
                lbl_3_common_bss_32A94._42 = 0xFF;
            }
        } else {
            lbl_3_common_bss_32A94._40 = 0;
            if (g_Pitcher.strikeOutOrWalk == 3) {
                result = 3;
                if (lbl_3_common_bss_32A94._41 < 0xFE) {
                    lbl_3_common_bss_32A94._41++;
                } else {
                    lbl_3_common_bss_32A94._41 = 0xFF;
                }
                if (lbl_3_common_bss_32A94._42 < 0xFE) {
                    lbl_3_common_bss_32A94._42++;
                } else {
                    lbl_3_common_bss_32A94._42 = 0xFF;
                }
            } else {
                lbl_3_common_bss_32A94._41 = 0;
                lbl_3_common_bss_32A94._42 = 0;
                if (g_Ball.fielderWithBallIndexStored2 == -1) {
                    if (g_Ball.fielderWithBallIndexStored >= 0) {
                        g_Ball.fielderWithBallIndexStored2 = g_Ball.fielderWithBallIndexStored;
                    } else if (g_Ball.ballZoneAwayFromHome >= 2) {
                        if (g_Ball.ballAngleFromHome < 0x340) {
                            g_Ball.fielderWithBallIndexStored2 = g_Ball.fielderWithBallIndexStored = 8;
                        } else if (g_Ball.ballAngleFromHome < 0x4C0) {
                            g_Ball.fielderWithBallIndexStored2 = g_Ball.fielderWithBallIndexStored = 7;
                        } else {
                            g_Ball.fielderWithBallIndexStored2 = g_Ball.fielderWithBallIndexStored = 6;
                        }
                    } else {
                        if (g_Ball.AtBat_Contact_BallPos.z < 8.0f) {
                            g_Ball.fielderWithBallIndexStored2 = g_Ball.fielderWithBallIndexStored = 1;
                        }
                        if (g_Ball.ballAngleFromHome < 0x300) {
                            g_Ball.fielderWithBallIndexStored2 = g_Ball.fielderWithBallIndexStored = 2;
                        } else if (g_Ball.ballAngleFromHome < 0x400) {
                            g_Ball.fielderWithBallIndexStored2 = g_Ball.fielderWithBallIndexStored = 3;
                        } else if (g_Ball.ballAngleFromHome < 0x500) {
                            g_Ball.fielderWithBallIndexStored2 = g_Ball.fielderWithBallIndexStored = 5;
                        } else {
                            g_Ball.fielderWithBallIndexStored2 = g_Ball.fielderWithBallIndexStored = 4;
                        }
                    }
                }
                if (lbl_3_common_bss_32A94._24 == 1) {
                    result = 14;
                } else if (lbl_3_common_bss_32A94._24 == 11) {
                    result = 13;
                } else if (g_FieldingLogic._113 == 9) {
                    fielder = g_FieldingLogic._0EA;
                    result = 11;
                } else if (lbl_3_common_bss_32A94._20 == 5 && g_Runners[0].forceOutCd != 2) {
                    fielder = g_FieldingLogic._0EA;
                    result = 11;
                } else if (lbl_3_common_bss_32A94._20 > 0) {
                    result = 12;
                } else if (lbl_3_common_bss_32A94._22 >= 1) {
                    result = lbl_3_common_bss_32A94._22 + 6;
                    if (lbl_3_common_bss_32A94._22 <= 3) {
                        fielder = g_Ball.fielderWithBallIndexStored2;
                    }
                    g_Scores._50[g_GameLogic.homeTeamBattingInd_fieldingTeam][g_Scores._00]++;
                    g_Scores._50[g_GameLogic.homeTeamBattingInd_fieldingTeam][0]++;
                    if (lbl_3_common_bss_32A94._22 >= 4 && g_Ball.deadBallReason == 1) {
                        if (lbl_3_common_bss_32A94._3E < 0xFE) {
                            lbl_3_common_bss_32A94._3E++;
                        } else {
                            lbl_3_common_bss_32A94._3E = 0xFF;
                        }
                    } else {
                        lbl_3_common_bss_32A94._3E = 0;
                    }
                } else if (lbl_3_common_bss_32A94._25 >= 2) {
                    result = 15;
                } else if (g_Ball.AtBat_ContactResult == 3 || g_FieldingLogic._108 == 2) {
                    if (g_Ball.fairBallInd == 1) {
                        result = 16;
                    } else if (g_Ball.Hit_VerticalAngle > 160) {
                        result = 6;
                    } else {
                        result = 5;
                    }
                    fielder = g_Ball.fielderWithBallIndexStored2;
                } else {
                    result = 4;
                    fielder = g_Ball.fielderWithBallIndexStored2;
                }
            }
        }
    }
    if (g_GameLogic.secondaryGameMode != 0) {
        return;
    }
    if (lbl_3_common_bss_32A94._22 >= 1) {
        if (lbl_3_common_bss_32A94._3F < 0xFE) {
            lbl_3_common_bss_32A94._3F++;
        } else {
            lbl_3_common_bss_32A94._3F = 0xFF;
        }
    } else {
        lbl_3_common_bss_32A94._3E = lbl_3_common_bss_32A94._3F = 0;
    }
    if (result != 15 && g_FieldingLogic._107 != 4) {
        streak = lbl_3_common_bss_32A94._26;
    }
    lbl_3_common_bss_32A94._32 = g_Batter.rosterID;
    lbl_3_common_bss_32A94._3B = g_Ball.fielderWithBallIndexStored2;
    lbl_3_common_bss_32A94._3C = streak;
    lbl_3_common_bss_32A94._3D = g_Strikes.storedOuts;
    for (i = 4; i > 0; i--) {
        lbl_3_common_bss_32A94._36[i] = lbl_3_common_bss_32A94._36[i - 1];
    }
    lbl_3_common_bss_32A94._36[0] = result;
    if (result == 1 || result == 4 || result == 5 || result == 6 || result == 15 || result == 16) {
        lbl_3_common_bss_32A94._67[g_GameLogic.homeTeamBattingInd_fieldingTeam]++;
    } else {
        lbl_3_common_bss_32A94._67[g_GameLogic.homeTeamBattingInd_fieldingTeam] = 0;
    }
    if (lbl_3_common_bss_32A94._52[g_GameLogic.awayTeamBattingInd_battingTeam][0] < 0x7FFE) {
        lbl_3_common_bss_32A94._52[g_GameLogic.awayTeamBattingInd_battingTeam][0]++;
    } else {
        lbl_3_common_bss_32A94._52[g_GameLogic.awayTeamBattingInd_battingTeam][0] = 0x7FFF;
    }
    fn_3_76D08(g_Batter.rosterID, result, fielder, streak);
    g_Stats._32 = result;
    if (g_RunningLogic._15 != 0) {
        lbl_3_common_bss_32A94._69[g_GameLogic.homeTeamBattingInd_fieldingTeam]
                                   [g_GameLogic.currentBatterPerTeam[g_GameLogic.homeTeamBattingInd_fieldingTeam]] = 1;
    } else {
        lbl_3_common_bss_32A94._69[g_GameLogic.homeTeamBattingInd_fieldingTeam]
                                   [g_GameLogic.currentBatterPerTeam[g_GameLogic.homeTeamBattingInd_fieldingTeam]] = 0;
    }
positions:
    for (i = 0; i <= 9; i++) {
        for (j = 0; j < 8; j++) {
            if (lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[j] != 0) {
                break;
            }
        }
        if (j >= 8) {
            if (i == 0) {
                lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[0] = 1;
            } else {
                switch (g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][1]) {
                case 0:
                    lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[0] = 1;
                    break;
                case 1:
                    lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[1] = 1;
                    break;
                case 2:
                    lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[2] = 1;
                    break;
                case 3:
                    lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[3] = 1;
                    break;
                case 4:
                    lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[4] = 1;
                    break;
                case 5:
                    lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[5] = 1;
                    break;
                case 6:
                case 7:
                case 8:
                    lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[6] = 1;
                    break;
                case 9:
                    lbl_803537E4[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]].positions[7] = 1;
                    break;
                }
            }
        }
    }
    if (g_FieldingLogic._134 >= 0) {
        if (lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_FieldingLogic._134]._178]._23 < 0xFE) {
            lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_FieldingLogic._134]._178]._23++;
        } else {
            lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_FieldingLogic._134]._178]._23 = 0xFF;
        }
    }
    if (!g_d_GameSettings.exhibitionMatchInd) {
        fn_3_16230C(result, streak);
    }
}

// .text:0x00076C78 size:0x90 mapped:0x806B5D0C
void fn_3_76C78(void) {
    int i;

    for (i = 0; i < 50; i++) {
        if (lbl_80353A90._A0[i] == -1) {
            if (g_GameLogic.teamBatting == 0) {
                lbl_80353A90._A0[i] = g_Batter.rosterID;
            } else {
                lbl_80353A90._A0[i] = (s8)g_Batter.rosterID + 9;
            }
            return;
        }
    }
}

// .text:0x00076A9C size:0x1DC mapped:0x806B5B30
void fn_3_76A9C(void) {
    int i;
    int runs;
    InMemRunnerType* runner;

    for (i = 1; i < 4; i++) {
        runner = &g_Runners[i];
        if ((runner->runnerOnFieldOrOutOrScored == 1 || runner->runnerOnFieldOrOutOrScored == 3) &&
            i != runner->currentBase &&
            (g_FieldingLogic._107 != 3 || runner->furthestBaseForcedToGoToOnWalk != 0) && runner->forceOutCd <= 0) {
            if (lbl_803537E4[g_GameLogic.teamBatting][runner->rosterID]._12 < 0xFE) {
                lbl_803537E4[g_GameLogic.teamBatting][runner->rosterID]._12++;
            } else {
                lbl_803537E4[g_GameLogic.teamBatting][runner->rosterID]._12 = 0xFF;
            }
            if (g_d_GameSettings.exhibitionMatchInd == 0 && lbl_3_common_bss_37400._40 == g_GameLogic.teamBatting) {
                fn_3_161588(10, runner->rosterID);
            }
        }
    }
    runs = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] - g_Scores._A0;
    for (i = 3; i >= 0; i--) {
        if (runs <= 0) {
            break;
        }
        runner = &g_Runners[i];
        if (runner->runnerOnFieldOrOutOrScored == 3) {
            if (lbl_803537E4[g_GameLogic.teamBatting][runner->rosterID]._11 < 0xFE) {
                lbl_803537E4[g_GameLogic.teamBatting][runner->rosterID]._11++;
            } else {
                lbl_803537E4[g_GameLogic.teamBatting][runner->rosterID]._11 = 0xFF;
            }
            runs--;
            if (g_d_GameSettings.exhibitionMatchInd == 0 && g_GameLogic.teamBatting == lbl_3_common_bss_37400._40) {
                fn_3_161588(11, runner->rosterID);
            }
        }
    }
}

void fn_3_76558(void) {
    return;
}

void fn_3_76174(void) {
    return;
}

void fn_3_759BC(void) {
    return;
}
