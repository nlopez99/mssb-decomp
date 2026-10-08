#include "game/rep_12D0.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_18E8.h"
#include "game/rep_3DA8.h"
#include "game/rep_1838.h"

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
    /* 0x9E */ s16 _9E;
    /* 0xA0 */ s16 _A0;
    /* 0xA2 */ u8 _A2[0xA4 - 0xA2];
    /* 0xA4 */ s16 _A4;
    /* 0xA6 */ s16 _A6;
    /* 0xA8 */ u8 _A8[2];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB;
    /* 0xAC */ u8 _AC;
    /* 0xAD */ u8 _AD;
    /* 0xAE */ s8 _AE;
    /* 0xAF */ s8 _AF[2];
    /* 0xB1 */ s8 _B1[2];
    /* 0xB3 */ s8 _B3[2];
    /* 0xB5 */ s8 _B5[2];
    /* 0xB7 */ s8 _B7[2];
    /* 0xB9 */ u8 _B9[2];
    /* 0xBB */ u8 _BB[2];
    /* 0xBD */ u8 _BD[2];
    /* 0xBF */ u8 _BF[0xC2 - 0xBF];
    /* 0xC2 */ u8 _C2;
} g_Scores;

typedef struct Unk12D0PitcherStats {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u16 _04;
    /* 0x06 */ u16 _06;
    /* 0x08 */ u16 _08;
    /* 0x0A */ u16 _0A;
    /* 0x0C */ u16 _0C;
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u16 _10;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
} Unk12D0PitcherStats; // size: 0x1E

typedef struct Unk12D0PlayerStats {
    /* 0x00 */ s16 _00;
    /* 0x02 */ u8 _02;
    /* 0x03 */ u8 _03;
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06;
    /* 0x07 */ u8 _07;
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A;
    /* 0x0B */ u8 _0B;
    /* 0x0C */ u8 _0C;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
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
    /* 0x08 */ u16 _08[2][19];
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
    /* 0xF2 */ u8 _F2;
    /* 0xF3 */ s8 _F3;
    /* 0xF4 */ s8 _F4;
    /* 0xF5 */ s8 _F5;
    /* 0xF6 */ u8 _F6;
    /* 0xF7 */ u8 _F7;
    /* 0xF8 */ s8 _F8[2];
    /* 0xFA */ s8 _FA;
    /* 0xFB */ s8 _FB;
    /* 0xFC */ s8 _FC;
    /* 0xFD */ s8 _FD;
    /* 0xFE */ s8 _FE;
    /* 0xFF */ s8 _FF;
    /* 0x100 */ s8 _100;
    /* 0x101 */ s8 _101[2];
    /* 0x103 */ s8 _103;
    /* 0x104 */ u8 _104;
} lbl_80353A90;

typedef struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ s8 _2;
    /* 0x3 */ s8 _3;
    /* 0x4 */ s8 _4;
} Unk12D0PitcherGame; // size: 0x5

extern Unk12D0PitcherGame lbl_3_common_bss_32A38[2][9];

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

extern int fn_3_6C938(int, int);
extern int random_fn_3_9EE24(int max);
extern int fn_3_6D564(int team, int rosterID, int arg);
extern void fn_3_9C794(void);

extern s8 lbl_3_common_bss_32888[2][100];

// rep_DB8's .data: MVP point weights
extern u8 lbl_3_data_60F8[12];

extern u8 lbl_800E8558[][6];

extern struct {
    /* 0x0000 */ u8 _0000[0xCF18];
    /* 0xCF18 */ u8 _CF18[1];
} lbl_80354768;

typedef struct {
    /* 0x0 */ u8 team : 5;
    /* 0x0 */ u8 _0b : 3;
    /* 0x1 */ u8 _1a : 2;
    /* 0x1 */ u8 order : 4;
    /* 0x1 */ u8 _1c : 2;
    /* 0x2 */ u8 _2 : 4;
    /* 0x2 */ u8 inning : 4;
    /* 0x3 */ u8 position : 4;
    /* 0x3 */ u8 _3b : 4;
} Unk12D0Slot; // size: 0x4

extern Unk12D0Slot lbl_80353260[2][9];

typedef struct {
    /* 0x0 */ u16 _0 : 5;
    /* 0x0 */ u16 _0b : 4;
    /* 0x1 */ u16 _1 : 4;
    /* 0x1 */ u16 _1b : 3;
    /* 0x2 */ s8 _2;
    /* 0x3 */ u8 _3;
} Unk12D0Play; // size: 0x4

extern Unk12D0Play lbl_803532A8[2][100];

// rep_DB8's .data
extern s16 lbl_3_data_5EDC[22];
extern s8 lbl_80354720[2][9][4];

static inline int GetLineupPosition(int slot) {
    return g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][slot][1];
}

static inline int GetLineupPlayer(int slot) {
    return g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][slot][0];
}

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

// .text:0x0007BC20 size:0x570 mapped:0x806BACB4
void fn_3_7BC20(void) {
    int sub = 0;
    int type = 0;
    int runners;
    int diff;
    InMemBallType* ball = &g_Ball;
    inMemStrikes* strikes = &g_Strikes;

    if (g_GameLogic.freeFieldingPracticeInd != 0) {
        return;
    }
    if (ball->deadBallReason == 1) {
        type = 2;
        if (lbl_3_common_bss_32A94._8A != 0) {
            type = 9;
        }
        if (g_Ball.homeRunClassification == 1) {
            type = 13;
        }
    } else if (g_Scores._C2 != 0) {
        if (lbl_3_common_bss_32A94._2 >= 6 && lbl_3_common_bss_32A94._2 <= 10) {
            type = 3;
            if (type == 3 && strikes->outs != 3 && g_Runners[0].runnerOnFieldOrOutOrScored != 2 &&
                g_Runners[0].runnerOnFieldOrOutOrScored != 3) {
                type = 4;
            }
            if (ball->fielderWithBallIndexStored2 != 6 && ball->fielderWithBallIndexStored2 != 7 &&
                ball->fielderWithBallIndexStored2 != 8) {
                sub = type;
                type = 1;
            }
            if (g_pCamera->_AC6 == 3) {
                sub = type;
                type = 1;
            }
        }
        if (lbl_3_common_bss_32A94._2 == 17) {
            if (g_Scores._A6 <= 1) {
                type = 5;
            } else if (g_Scores._A6 <= 1 && g_Scores._AC >= 3) {
                type = 5;
            }
            if (lbl_3_common_bss_32A94._8A != 0) {
                type = 11;
            }
        }
        diff = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] -
               g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0];
        if (diff > 4 || diff < -4) {
            type = 0;
        }
    } else {
        if (g_pCamera->_A50 >= 2) {
            if (g_GameLogic.EventTriggers_EndOfGame != 0) {
                if (g_pCamera->_A98 > 0 &&
                    (lbl_3_common_bss_32A94._2 == 18 || lbl_3_common_bss_32A94._2 == 19 || lbl_3_common_bss_32A94._2 == 26)) {
                    type = 7;
                } else if (g_pCamera->_A98 > 0 && lbl_3_common_bss_32A94._2 >= 20 && lbl_3_common_bss_32A94._2 <= 27) {
                    type = 8;
                }
            } else {
                runners = 0;
                if (g_Runners[1].rosterID != -1) {
                    runners++;
                }
                if (g_Runners[2].rosterID != -1) {
                    runners++;
                }
                if (g_Runners[3].rosterID != -1) {
                    runners++;
                }
                if (g_Scores._A6 <= 4 && runners == 3) {
                    if (g_pCamera->_A98 > 0 &&
                        (lbl_3_common_bss_32A94._2 == 18 || lbl_3_common_bss_32A94._2 == 19 || lbl_3_common_bss_32A94._2 == 26)) {
                        type = 7;
                    } else if (g_pCamera->_A98 > 0 && lbl_3_common_bss_32A94._2 >= 20 && lbl_3_common_bss_32A94._2 <= 27) {
                        type = 8;
                    }
                }
                runners = 0;
                if (g_Runners[2].rosterID != -1) {
                    runners++;
                }
                if (g_Runners[3].rosterID != -1) {
                    runners++;
                }
                if (g_Scores._A6 <= runners && runners > 0) {
                    if (g_pCamera->_A98 > 0 &&
                        (lbl_3_common_bss_32A94._2 == 18 || lbl_3_common_bss_32A94._2 == 19 || lbl_3_common_bss_32A94._2 == 26)) {
                        type = 7;
                    } else if (g_pCamera->_A98 > 0 && lbl_3_common_bss_32A94._2 >= 20 && lbl_3_common_bss_32A94._2 <= 27) {
                        type = 8;
                    }
                }
            }
        }
        if (lbl_3_common_bss_32A94._2 >= 36 && lbl_3_common_bss_32A94._2 <= 38 && g_pCamera->_A50 == 2) {
            if (g_GameLogic.EventTriggers_EndOfGame != 0) {
                type = 6;
            } else {
                runners = 0;
                if (g_Runners[1].rosterID != -1) {
                    runners++;
                }
                if (g_Runners[2].rosterID != -1) {
                    runners++;
                }
                if (g_Runners[3].rosterID != -1) {
                    runners++;
                }
                if (g_Scores._A6 <= 4 && runners == 3) {
                    type = 6;
                }
                runners = 0;
                if (g_Runners[2].rosterID != -1) {
                    runners++;
                }
                if (g_Runners[3].rosterID != -1) {
                    runners++;
                }
                if (g_Scores._A6 <= runners && runners > 0) {
                    type = 6;
                }
            }
        }
    }
    if (type == 0) {
        return;
    }
    switch (type) {
    case 2:
    case 9:
        g_Stats._3C = 2;
        break;
    case 13:
        g_Stats._3C = 13;
        break;
    case 3:
    case 10:
        g_Stats._3C = 3;
        break;
    case 4:
        g_Stats._3C = 4;
        break;
    case 5:
        g_Stats._3C = 5;
        break;
    case 6:
        g_Stats._3C = 6;
        break;
    case 7:
        g_Stats._3C = 7;
        break;
    case 8:
        g_Stats._3C = 1;
        g_Stats._3D = 0;
        break;
    case 11:
        g_Stats._3C = 11;
        break;
    default:
        g_Stats._3C = 1;
        g_Stats._3D = sub;
        break;
    }
    g_Stats._39 = 1;
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

// .text:0x0007B308 size:0x86C mapped:0x806BA39C
void fn_3_7B308(void) {
    int t;
    int i;
    s32 j;
    Unk12D0Slot* slot;
    int found;

    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            lbl_803537E4[t][i]._02 = 0;
            lbl_803537E4[t][i]._03 = 0;
            lbl_803537E4[t][i]._04 = 0;
            lbl_803537E4[t][i]._05 = 0;
            lbl_803537E4[t][i]._06 = 0;
            lbl_803537E4[t][i]._07 = 0;
            lbl_803537E4[t][i]._08 = 0;
            lbl_803537E4[t][i]._09 = 0;
            lbl_803537E4[t][i]._0A = 0;
            lbl_803537E4[t][i]._0B = 0;
            lbl_803537E4[t][i]._0C = 0;
            lbl_803537E4[t][i]._0D = 0;
            lbl_803537E4[t][i]._0E = 0;
            lbl_803537E4[t][i]._0F = 0;
            lbl_803537E4[t][i]._10 = 0;
            lbl_803537E4[t][i]._11 = 0;
            lbl_803537E4[t][i]._12 = 0;
            lbl_803537E4[t][i]._13 = 0;
            lbl_803537E4[t][i]._14 = 0;
            lbl_803537E4[t][i]._15 = 0;
            lbl_803537E4[t][i]._16 = 0;
            lbl_803537E4[t][i]._17 = 0;
            lbl_803537E4[t][i]._18 = 0;
            lbl_803537E4[t][i]._19 = 0;
            lbl_803537E4[t][i].positions[0] = 0;
            lbl_803537E4[t][i].positions[1] = 0;
            lbl_803537E4[t][i].positions[2] = 0;
            lbl_803537E4[t][i].positions[3] = 0;
            lbl_803537E4[t][i].positions[4] = 0;
            lbl_803537E4[t][i].positions[5] = 0;
            lbl_803537E4[t][i].positions[6] = 0;
            lbl_803537E4[t][i].positions[7] = 0;
            lbl_803537E4[t][i]._22 = 0;
            lbl_803537E4[t][i]._23 = 0;
            lbl_803537E4[t][i]._24 = 0;
            lbl_803535C8[t][i]._00 = 0;
            lbl_803535C8[t][i]._02 = 0;
            lbl_803535C8[t][i]._04 = 0;
            lbl_803535C8[t][i]._06 = 0;
            lbl_803535C8[t][i]._08 = 0;
            lbl_803535C8[t][i]._0A = 0;
            lbl_803535C8[t][i]._0C = 0;
            lbl_803535C8[t][i]._0E = 0;
            lbl_803535C8[t][i]._10 = lbl_3_data_5EDC[0];
            lbl_803535C8[t][i]._12 = 0;
            lbl_803535C8[t][i]._13 = 0;
            lbl_803535C8[t][i]._14 = 0;
            lbl_803535C8[t][i]._15 = 0;
            lbl_803535C8[t][i]._16 = 0;
            lbl_803535C8[t][i]._17 = 0;
            lbl_803535C8[t][i]._18 = 0;
            lbl_803535C8[t][i]._19 = 0;
            lbl_803535C8[t][i]._1A = 0;
            lbl_803535C8[t][i]._1B = 0;
            lbl_803535C8[t][i]._1C = 0;
            lbl_803535C8[t][i]._1D = 0;
            lbl_3_common_bss_32A38[t][i]._0 = 0;
            lbl_3_common_bss_32A38[t][i]._1 = 0;
        }
    }
    for (t = 0; t < 2; t++) {
        lbl_3_common_bss_32A94._44[t] = 1;
        lbl_3_common_bss_32A94._48[t] = 1;
        lbl_3_common_bss_32A94._4C[t] = 1;
        lbl_3_common_bss_32A94._63[t] = 1;
        lbl_3_common_bss_32A94._65[t] = 0;
        lbl_3_common_bss_32A94._50[t][1] = 0;
        lbl_3_common_bss_32A94._67[t] = 0;
        lbl_3_common_bss_32A94._58[t][0] = -1;
        for (j = 1; j <= 9; j++) {
            lbl_3_common_bss_32A94._69[t][j] = 0;
        }
    }
    for (t = 0; t < 2; t++) {
        for (j = 0; j < 19; j++) {
            lbl_80353A90._08[t][j] = 0xFFFF;
            lbl_80353A90._54[t][j] = 0;
        }
        lbl_80353A90._F0[t] = 0;
        lbl_80353A90._101[t] = -1;
    }
    for (t = 0; t < 2; t++) {
        for (j = 0; j < 10; j++) {
            lbl_80353A90._BE[t][j][0] = -1;
            lbl_80353A90._BE[t][j][1] = 0;
        }
        for (i = 0; i < 5; i++) {
            lbl_80353A90._E6[t][i] = -1;
        }
    }
    for (j = 0; j < 30; j++) {
        lbl_80353A90._A0[j] = -1;
    }
    lbl_80353A90._F3 = -1;
    lbl_80353A90._F4 = -1;
    lbl_80353A90._F5 = -1;
    lbl_80353A90._F6 = 0;
    lbl_80353A90._F7 = 0;
    lbl_80353A90._F8[0] = -1;
    lbl_80353A90._F8[1] = -1;
    lbl_80353A90._FA = -1;
    lbl_80353A90._FB = -1;
    lbl_80353A90._FC = -1;
    lbl_80353A90._FD = -1;
    lbl_80353A90._FE = -1;
    lbl_80353A90._FF = -1;
    for (t = 0; t < 2; t++) {
        for (i = 0; i < 100; i++) {
            lbl_803532A8[t][i]._0 = 0;
            lbl_803532A8[t][i]._0b = 0;
            lbl_803532A8[t][i]._2 = -1;
            lbl_803532A8[t][i]._3 = 0;
            lbl_803532A8[t][i]._1 = 0;
            lbl_803532A8[t][i]._1b = 0;
        }
    }
    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            lbl_80353260[t][i]._2 = 0;
            lbl_80353260[t][i].inning = 0;
            lbl_80353260[t][i].position = 10;
            lbl_80353260[t][i]._3b = 0;
            lbl_80353260[t][i].team = 9;
            lbl_80353260[t][i].order = 0;
        }
    }
    for (t = 0; t < 2; t++) {
        for (i = 0; i < 9; i++) {
            if (lbl_80354720[0][i][3] == 1) {
                lbl_803537E4[0][i]._02 = 1;
            }
        }
    }
    lbl_3_common_bss_32A94._50[0][0] = g_GameLogic.battingOrderAndPositionMapping[0][0][0];
    lbl_3_common_bss_32A94._50[1][0] = g_GameLogic.battingOrderAndPositionMapping[1][0][0];
    lbl_803535C8[g_GameLogic.teamFielding][g_GameLogic.battingOrderAndPositionMapping[g_Scores._AD ^ 1][0][0]]._12 = 1;
    lbl_803535C8[g_GameLogic.teamBatting][g_GameLogic.battingOrderAndPositionMapping[g_Scores._AD][0][0]]._12 = 1;
    for (t = 0; t < 2; t++) {
        found = 0;
        for (i = 0; i < 9; i++) {
            slot = &lbl_80353260[t ^ g_GameLogic.homeTeamInd][g_GameLogic.battingOrderAndPositionMapping[t][i + 1][0]];
            slot->_2 = 1;
            slot->inning = 1;
            slot->position = g_GameLogic.battingOrderAndPositionMapping[t][i + 1][1];
            slot->_3b = 1;
            slot->team = t;
            slot->order = i + 1;
            if (g_GameLogic.battingOrderAndPositionMapping[t][i + 1][1] == 9) {
                found = 1;
            }
        }
        if (found) {
            slot = &lbl_80353260[t ^ g_GameLogic.homeTeamInd][g_GameLogic.battingOrderAndPositionMapping[t][0][0]];
            slot->_2 = 1;
            slot->inning = 1;
            slot->position = 0;
            slot->_3b = 1;
            slot->team = 9;
            slot->order = 10;
        }
    }
    lbl_3_common_bss_32A94._62 = 0;
    lbl_3_common_bss_32A94._61 = 0;
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
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][i]._2 = -1;
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][i]._3 = -1;
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][i]._4 = -1;
    }
    lbl_3_common_bss_32A38[g_GameLogic.teamFielding]
                          [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]]._2 = 0;
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
    int pitcher = GetLineupPlayer(0);

    if (lbl_3_common_bss_32A38[g_GameLogic.teamFielding][pitcher]._2 < 0) {
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][pitcher]._2 = 0;
    } else {
        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][pitcher]._4 = 0;
    }
    for (i = 1; i < 10; i++) {
        int pos = GetLineupPosition(i);
        int id = GetLineupPlayer(i);
        if (pos > 0 && lbl_3_common_bss_32A38[g_GameLogic.teamFielding][id]._2 == 0 &&
            pos != lbl_3_common_bss_32A38[g_GameLogic.teamFielding][id]._3) {
            lbl_3_common_bss_32A38[g_GameLogic.teamFielding][id]._3 = pos;
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

// .text:0x0007A154 size:0x9E0 mapped:0x806B91E8
void fn_3_7A154(int arg0) {
    s32 i;
    int runs;
    int left;
    int flag = 0;
    int lead;
    int code;
    int scored[4];
    Unk12D0PitcherStats* pitcherStats = fn_3_7BBC0();

    if (g_Stats.replayInd != 0) {
        return;
    }
    for (i = 0; i < 9; i++) {
        lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[i]._178]._02 = 1;
    }
    for (i = 0; i < 4; i++) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored != 0 && g_Runners[i].rosterID >= 0) {
            lbl_803537E4[g_GameLogic.teamBatting][g_Runners[i].rosterID]._02 = 1;
        }
    }
    fn_3_7BBC0()->_12 = 1;
    fn_3_7AB78(0);
    if (pitcherStats->_1B < g_Pitcher.pitchSpeed) {
        pitcherStats->_1B = g_Pitcher.pitchSpeed;
    }
    if (g_FieldingLogic._107 == 0) {
        if (g_Pitcher.starPitchType != 0 || g_Pitcher.nonCaptainStarPitchTriggeredType != 0) {
            fn_3_6D564(g_GameLogic.teamFielding, g_Pitcher.rosterID, lbl_3_data_5EDC[1]);
            if (lbl_803535C8[g_GameLogic.teamFielding]
                            [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]]
                                ._1D < 0xFE) {
                lbl_803535C8[g_GameLogic.teamFielding]
                            [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]]
                                ._1D++;
            } else {
                lbl_803535C8[g_GameLogic.teamFielding]
                            [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]]
                                ._1D = 0xFF;
            }
        }
        if ((g_Pitcher.strikeOutOrWalk == 2 || g_Pitcher.strikeOutOrWalk == 3) && g_RunningLogic._12 >= 4) {
            fn_3_6D564(g_GameLogic.teamFielding, g_Pitcher.rosterID, lbl_3_data_5EDC[2]);
        } else if (g_Scores._C2 != 0) {
            fn_3_6D564(g_GameLogic.teamFielding, g_Pitcher.rosterID, lbl_3_data_5EDC[2] * g_Scores._C2);
        }
    }
    for (i = 1; i < 10; i++) {
        if (lbl_80353260[g_GameLogic.teamFielding]
                        [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]]
                            .position == 10) {
            lbl_80353260[g_GameLogic.teamFielding]
                        [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][0]]
                            .position = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][1];
        }
    }
    lead = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] -
           g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0];
    runs = lead - (g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][g_Scores._00] - g_Scores._9E);
    if (lead >= 0 && runs <= 0) {
        flag = 1;
    }
    if (arg0 == 0) {
        if ((g_Pitcher.strikeOutOrWalk == 2 || g_Pitcher.strikeOutOrWalk == 3) && g_RunningLogic._12 >= 4 &&
            g_Runners[3].pitcherWhoLetRunnerOnBase >= 0) {
            if (lbl_803535C8[g_GameLogic.teamFielding][g_Runners[3].pitcherWhoLetRunnerOnBase]._02 < 0xFFFE) {
                lbl_803535C8[g_GameLogic.teamFielding][g_Runners[3].pitcherWhoLetRunnerOnBase]._02++;
            } else {
                lbl_803535C8[g_GameLogic.teamFielding][g_Runners[3].pitcherWhoLetRunnerOnBase]._02 = 0xFFFF;
            }
            if (g_Runners[3].runnerDidntReachOnError != 0) {
                if (lbl_803535C8[g_GameLogic.teamFielding][g_Runners[3].pitcherWhoLetRunnerOnBase]._04 < 0xFFFE) {
                    lbl_803535C8[g_GameLogic.teamFielding][g_Runners[3].pitcherWhoLetRunnerOnBase]._04++;
                } else {
                    lbl_803535C8[g_GameLogic.teamFielding][g_Runners[3].pitcherWhoLetRunnerOnBase]._04 = 0xFFFF;
                }
            }
            if (flag) {
                runs++;
                if (runs >= 0) {
                    lbl_3_common_bss_32A38[g_GameLogic.teamFielding][g_Runners[3].pitcherWhoLetRunnerOnBase]._1 = 0;
                }
            }
        }
    } else {
        left = g_Scores._9C;
        for (i = 0; i < 4; i++) {
            scored[i] = 0;
            if (g_Runners[i].runnerOnFieldOrOutOrScored == 3 || g_Runners[i].scoredOnGRD != 0) {
                if (left <= 0) {
                    scored[i] = 1;
                } else {
                    left--;
                }
            }
        }
        if (g_Strikes.storedOuts == 2) {
            code = 0;
            if (g_Ball.AtBat_ContactResult == 3) {
                code = 1;
            } else {
                for (i = 0; i < 4; i++) {
                    if (g_Runners[i].forceOutCd == 2) {
                        code = 1;
                    }
                }
            }
            if (code) {
                for (i = 0; i < 4; i++) {
                    scored[i] = 0;
                }
            }
        }
        if (g_Strikes.storedOuts == 1) {
            code = 2;
            for (i = 0; i < 4; i++) {
                if (g_Runners[i].forceOutCd == 2) {
                    code--;
                }
            }
            if (code <= 0) {
                for (i = 0; i < 4; i++) {
                    scored[i] = 0;
                }
            }
        }
        for (i = 3; i >= 0; i--) {
            if (scored[i] && g_Runners[i].pitcherWhoLetRunnerOnBase >= 0) {
                if (lbl_803535C8[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._02 < 0xFFFE) {
                    lbl_803535C8[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._02++;
                } else {
                    lbl_803535C8[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._02 = 0xFFFF;
                }
                if (g_Runners[i].runnerDidntReachOnError != 0) {
                    if (g_FieldingLogic._113 == 9) {
                        if (i == 3 && g_FieldingLogic._132 == 1 && g_Ball.landingSpotZoneAwayFromHome == 4) {
                            if (lbl_803535C8[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._04 < 0xFFFE) {
                                lbl_803535C8[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._04++;
                            } else {
                                lbl_803535C8[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._04 = 0xFFFF;
                            }
                        }
                    } else if (lbl_803535C8[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._04 < 0xFFFE) {
                        lbl_803535C8[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._04++;
                    } else {
                        lbl_803535C8[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._04 = 0xFFFF;
                    }
                }
                if (flag) {
                    runs++;
                    if (runs >= 0) {
                        lbl_3_common_bss_32A38[g_GameLogic.teamFielding][g_Runners[i].pitcherWhoLetRunnerOnBase]._1 = 0;
                    }
                }
            }
        }
    }
    if (lbl_3_common_bss_32A94._50[g_GameLogic.awayTeamBattingInd_battingTeam][0] !=
        g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]) {
        lbl_3_common_bss_32A94._50[g_GameLogic.awayTeamBattingInd_battingTeam][0] =
            g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0];
        lbl_3_common_bss_32A94._50[g_GameLogic.awayTeamBattingInd_battingTeam][1] = 0;
        lbl_3_common_bss_32A94._34 = 0;
    }
    code = g_Strikes.balls + g_Strikes.strikes * 16;
    for (i = 0; i < 7; i++) {
        if (lbl_3_common_bss_32A94._2B[i] == 0) {
            if (i <= 0 || lbl_3_common_bss_32A94._2B[i - 1] != code) {
                lbl_3_common_bss_32A94._2B[i] = code;
            }
            break;
        }
    }
    if (lbl_3_common_bss_32A94._34 < 0x7FFE) {
        lbl_3_common_bss_32A94._34++;
    } else {
        lbl_3_common_bss_32A94._34 = 0x7FFF;
    }
    fn_3_9C794();
    if (!g_d_GameSettings.exhibitionMatchInd) {
        fn_3_162080();
    }
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
                              [g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0]]._1 = 0;
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
    lbl_3_common_bss_32A38[g_GameLogic.teamFielding][pitcher]._1 = 1;
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
                    lbl_3_common_bss_32A38[g_GameLogic.awayTeamBattingInd_battingTeam][pitcher]._0 +=
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
    if (lbl_3_common_bss_32A94._50[g_GameLogic.awayTeamBattingInd_battingTeam][1] < 0x7FFE) {
        lbl_3_common_bss_32A94._50[g_GameLogic.awayTeamBattingInd_battingTeam][1]++;
    } else {
        lbl_3_common_bss_32A94._50[g_GameLogic.awayTeamBattingInd_battingTeam][1] = 0x7FFF;
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

// .text:0x00076D08 size:0xC0C mapped:0x806B5D9C
void fn_3_76D08(s32 rosterID, s32 result, s16 fielder, s32 streak) {
    int atBat = 0;
    int pitcher = g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][0][0];
    Unk12D0PlayerStats* playerStats = &lbl_803537E4[g_GameLogic.teamBatting][rosterID];
    Unk12D0PitcherStats* pitcherStats = &lbl_803535C8[g_GameLogic.teamFielding][pitcher];
    int idx;
    int i;
    int runs;
    s16 angle;

    if (playerStats->_03 < 0xFE) {
        playerStats->_03++;
    } else {
        playerStats->_03 = 0xFF;
    }
    idx = fn_3_7AEA8();
    if (idx >= 100) {
        for (i = 0; i < 99; i++) {
            lbl_3_common_bss_32888[g_GameLogic.teamBatting][i] = lbl_3_common_bss_32888[g_GameLogic.teamBatting][i + 1];
            lbl_803532A8[g_GameLogic.teamBatting][i]._0 = lbl_803532A8[g_GameLogic.teamBatting][i + 1]._0;
            lbl_803532A8[g_GameLogic.teamBatting][i]._0b = lbl_803532A8[g_GameLogic.teamBatting][i + 1]._0b;
            lbl_803532A8[g_GameLogic.teamBatting][i]._2 = lbl_803532A8[g_GameLogic.teamBatting][i + 1]._2;
            lbl_803532A8[g_GameLogic.teamBatting][i]._3 = lbl_803532A8[g_GameLogic.teamBatting][i + 1]._3;
            lbl_803532A8[g_GameLogic.teamBatting][i]._1 = lbl_803532A8[g_GameLogic.teamBatting][i + 1]._1;
            lbl_803532A8[g_GameLogic.teamBatting][i]._1b = lbl_803532A8[g_GameLogic.teamBatting][i + 1]._1b;
        }
        idx = 99;
    }
    lbl_803532A8[g_GameLogic.teamBatting][idx]._0 = g_Scores._00;
    lbl_803532A8[g_GameLogic.teamBatting][idx]._0b = g_GameLogic.currentBatterPerTeam[g_GameLogic.homeTeamBattingInd_fieldingTeam];
    lbl_803532A8[g_GameLogic.teamBatting][idx]._2 = rosterID;
    lbl_803532A8[g_GameLogic.teamBatting][idx]._3 = result;
    lbl_3_common_bss_32888[g_GameLogic.teamBatting][idx] = lbl_3_common_bss_32A94._0;
    lbl_803532A8[g_GameLogic.teamBatting][idx]._1 = fielder;
    lbl_803532A8[g_GameLogic.teamBatting][idx]._1b = streak;
    if (result == 10) {
        angle = fn_3_9FB8C(g_Ball.landingSpotLocation.x, g_Ball.landingSpotLocation.z);
        if (angle < 0x380) {
            lbl_803532A8[g_GameLogic.teamBatting][idx]._1 = 8;
        } else if (angle < 0x480) {
            lbl_803532A8[g_GameLogic.teamBatting][idx]._1 = 7;
        } else {
            lbl_803532A8[g_GameLogic.teamBatting][idx]._1 = 6;
        }
    }
    switch (result) {
    case 1:
        if (playerStats->_0D < 0xFE) {
            playerStats->_0D++;
        } else {
            playerStats->_0D = 0xFF;
        }
        atBat = 1;
        break;
    case 2:
        if (playerStats->_0E < 0xFE) {
            playerStats->_0E++;
        } else {
            playerStats->_0E = 0xFF;
        }
        break;
    case 3:
        if (playerStats->_0F < 0xFE) {
            playerStats->_0F++;
        } else {
            playerStats->_0F = 0xFF;
        }
        break;
    case 7:
        if (playerStats->_06 < 0xFE) {
            playerStats->_06++;
        } else {
            playerStats->_06 = 0xFF;
        }
        if (playerStats->_05 < 0xFE) {
            playerStats->_05++;
        } else {
            playerStats->_05 = 0xFF;
        }
        atBat = 1;
        break;
    case 8:
        if (playerStats->_07 < 0xFE) {
            playerStats->_07++;
        } else {
            playerStats->_07 = 0xFF;
        }
        if (playerStats->_05 < 0xFE) {
            playerStats->_05++;
        } else {
            playerStats->_05 = 0xFF;
        }
        atBat = 1;
        break;
    case 9:
        if (playerStats->_08 < 0xFE) {
            playerStats->_08++;
        } else {
            playerStats->_08 = 0xFF;
        }
        if (playerStats->_05 < 0xFE) {
            playerStats->_05++;
        } else {
            playerStats->_05 = 0xFF;
        }
        atBat = 1;
        break;
    case 10:
        if (playerStats->_09 < 0xFE) {
            playerStats->_09++;
        } else {
            playerStats->_09 = 0xFF;
        }
        if (playerStats->_05 < 0xFE) {
            playerStats->_05++;
        } else {
            playerStats->_05 = 0xFF;
        }
        atBat = 1;
        fn_3_76C78();
        break;
    case 13:
        if (playerStats->_0A < 0xFE) {
            playerStats->_0A++;
        } else {
            playerStats->_0A = 0xFF;
        }
        break;
    case 14:
        if (playerStats->_0B < 0xFE) {
            playerStats->_0B++;
        } else {
            playerStats->_0B = 0xFF;
        }
        break;
    case 15:
        if (playerStats->_0C < 0xFE) {
            playerStats->_0C++;
        } else {
            playerStats->_0C = 0xFF;
        }
        atBat = 1;
        break;
    default:
        atBat = 1;
        break;
    }
    if (playerStats->_04 < 0xFF - atBat) {
        playerStats->_04 += atBat;
    } else {
        playerStats->_04 = 0xFF;
    }
    if (playerStats->_10 < 0xFF - streak) {
        playerStats->_10 += streak;
    } else {
        playerStats->_10 = 0xFF;
    }
    if (g_RunningLogic._15 != 0) {
        if (playerStats->_13 < 0xFF - atBat) {
            playerStats->_13 += atBat;
        } else {
            playerStats->_13 = 0xFF;
        }
        if (result >= 7 && result <= 10) {
            if (playerStats->_14 < 0xFE) {
                playerStats->_14++;
            } else {
                playerStats->_14 = 0xFF;
            }
        }
        if (result == 10) {
            if (playerStats->_18 < 0xFE) {
                playerStats->_18++;
            } else {
                playerStats->_18 = 0xFF;
            }
        }
        if (streak != 0) {
            if (playerStats->_17 < 0xFF - streak) {
                playerStats->_17 += streak;
            } else {
                playerStats->_17 = 0xFF;
            }
        }
    }
    runs = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] - g_Scores._A0;
    for (i = 3; i >= 0; i--) {
        if (runs <= 0) {
            break;
        }
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 3) {
            if (lbl_803537E4[g_GameLogic.teamBatting][g_Runners[i].rosterID]._11 < 0xFE) {
                lbl_803537E4[g_GameLogic.teamBatting][g_Runners[i].rosterID]._11++;
            } else {
                lbl_803537E4[g_GameLogic.teamBatting][g_Runners[i].rosterID]._11 = 0xFF;
            }
            runs--;
            if (g_d_GameSettings.exhibitionMatchInd == 0 && g_GameLogic.teamBatting == lbl_3_common_bss_37400._40) {
                fn_3_161588(11, g_Runners[i].rosterID);
            }
        }
    }
    g_Scores._B1[g_GameLogic.awayTeamBattingInd_battingTeam] = pitcher;
    if (pitcherStats->_00 < 0xFFFE) {
        pitcherStats->_00++;
    } else {
        pitcherStats->_00 = 0xFFFF;
    }
    if (pitcherStats->_1A < 0xFF - g_Strikes.outs - g_Strikes.storedOuts) {
        pitcherStats->_1A += g_Strikes.outs - g_Strikes.storedOuts;
    } else {
        pitcherStats->_1A = 0xFF;
    }
    if (g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0] > g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0]) {
        lbl_3_common_bss_32A38[g_GameLogic.awayTeamBattingInd_battingTeam][pitcher]._0 += g_Strikes.outs - g_Strikes.storedOuts;
    }
    if (result >= 7 && result <= 10) {
        if (pitcherStats->_0A < 0xFFFE) {
            pitcherStats->_0A++;
        } else {
            pitcherStats->_0A = 0xFFFF;
        }
    }
    if (result == 10) {
        if (pitcherStats->_0C < 0xFFFE) {
            pitcherStats->_0C++;
        } else {
            pitcherStats->_0C = 0xFFFF;
        }
    }
    if (result == 1) {
        if (pitcherStats->_1C < 0xFE) {
            pitcherStats->_1C++;
        } else {
            pitcherStats->_1C = 0xFF;
        }
    }
    if (result == 2) {
        if (g_Strikes._1E >= 0) {
            if (lbl_803535C8[g_GameLogic.teamFielding][g_Strikes._1E]._06 < 0xFFFE) {
                lbl_803535C8[g_GameLogic.teamFielding][g_Strikes._1E]._06++;
            } else {
                lbl_803535C8[g_GameLogic.teamFielding][g_Strikes._1E]._06 = 0xFFFF;
            }
        } else {
            if (pitcherStats->_06 < 0xFFFE) {
                pitcherStats->_06++;
            } else {
                pitcherStats->_06 = 0xFFFF;
            }
        }
    }
    if (result == 3) {
        if (pitcherStats->_08 < 0xFFFE) {
            pitcherStats->_08++;
        } else {
            pitcherStats->_08 = 0xFFFF;
        }
    }
    if (lbl_3_common_bss_32A94._63[g_GameLogic.awayTeamBattingInd_battingTeam] != 0) {
        if (lbl_3_common_bss_32A94._4C[g_GameLogic.awayTeamBattingInd_battingTeam] > 1) {
            lbl_3_common_bss_32A94._63[g_GameLogic.awayTeamBattingInd_battingTeam] = 0;
        } else {
            if (lbl_3_common_bss_32A94._63[g_GameLogic.awayTeamBattingInd_battingTeam] == 1 &&
                (result == 2 || result == 3 || result == 11 || result == 12)) {
                lbl_3_common_bss_32A94._63[g_GameLogic.awayTeamBattingInd_battingTeam] = 2;
            }
            if (lbl_3_common_bss_32A94._63[g_GameLogic.awayTeamBattingInd_battingTeam] != 0 &&
                (result == 7 || result == 8 || result == 9 || result == 10 ||
                 g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] > 0 ||
                 lbl_80353A90._BE[g_GameLogic.teamFielding][1][0] >= 0)) {
                lbl_3_common_bss_32A94._63[g_GameLogic.awayTeamBattingInd_battingTeam] = 0;
            }
        }
    }
    if (g_FieldingLogic._113 == 9) {
        if (g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam] < 0xFE) {
            g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam]++;
        } else {
            g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam] = 0xFF;
        }
        if (lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_FieldingLogic._0EA]._178]._15 < 0xFE) {
            lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_FieldingLogic._0EA]._178]._15++;
        } else {
            lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_FieldingLogic._0EA]._178]._15 = 0xFF;
        }
    }
    if (g_Ball.fielderWithBallIndexStored >= 0 && g_Ball.fielderWithBallIndexStored <= 8) {
        if (lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_Ball.fielderWithBallIndexStored]._178]._16 < 0xFE) {
            lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_Ball.fielderWithBallIndexStored]._178]._16++;
        } else {
            lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_Ball.fielderWithBallIndexStored]._178]._16 = 0xFF;
        }
    }
    if (g_FieldingLogic._133 == 2 && g_Ball.fielderWithBallIndexStored2 >= 0) {
        if (lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_Ball.fielderWithBallIndexStored2]._178]._16 < 0xFE) {
            lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_Ball.fielderWithBallIndexStored2]._178]._16++;
        } else {
            lbl_803537E4[g_GameLogic.teamFielding][g_Fielders[g_Ball.fielderWithBallIndexStored2]._178]._16 = 0xFF;
        }
    }
    lbl_80353A90._08[g_GameLogic.teamBatting][g_Scores._00] =
        g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][g_Scores._00];
    lbl_80353A90._54[g_GameLogic.teamBatting][g_Scores._00] =
        g_Scores._50[g_GameLogic.homeTeamBattingInd_fieldingTeam][g_Scores._00];
    lbl_80353A90._08[g_GameLogic.teamBatting][0] = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0];
    lbl_80353A90._54[g_GameLogic.teamBatting][0] = g_Scores._50[g_GameLogic.homeTeamBattingInd_fieldingTeam][0];
    lbl_80353A90._F0[g_GameLogic.teamBatting] = g_Scores._A8[g_GameLogic.homeTeamBattingInd_fieldingTeam];
    lbl_80353A90._F0[g_GameLogic.teamFielding] = g_Scores._A8[g_GameLogic.awayTeamBattingInd_battingTeam];
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

// .text:0x00076558 size:0x544 mapped:0x806B55EC
void fn_3_76558(void) {
    int i;
    int team;
    s32 j;

    if (g_Scores._A4 == 0) {
        lbl_80353A90._F2 = g_GameLogic.homeTeamInd;
    }
    if (g_Scores._A4 == 1) {
        lbl_80353A90._F2 = g_GameLogic.homeTeamInd ^ 1;
    }
    if (g_Scores._A4 == 2) {
        lbl_80353A90._F2 = 2;
    }
    if (g_Scores._A4 == 0 || g_Scores._A4 == 1) {
        fn_3_76174();
        if (lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._13 < 0xFE) {
            lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._13++;
        } else {
            lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._13 = 0xFF;
        }
        if (g_Scores._BB[g_Scores._A4] == 1) {
            if (lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._17 < 0xFE) {
                lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._17++;
            } else {
                lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._17 = 0xFF;
            }
            if (lbl_80353A90._08[lbl_80353A90._F2 ^ 1][0] == 0) {
                if (lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._18 < 0xFE) {
                    lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._18++;
                } else {
                    lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._18 = 0xFF;
                }
                if (lbl_3_common_bss_32A94._63[g_Scores._A4] == 1) {
                    lbl_80353A90._F7 = 1;
                }
                if (lbl_3_common_bss_32A94._63[g_Scores._A4] == 2) {
                    lbl_80353A90._F7 = 2;
                }
            }
        }
        if (lbl_80353A90._F3 != g_Scores._AF[g_Scores._A4]) {
            if (lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._16 < 0xFE) {
                lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._16++;
            } else {
                lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F3]._16 = 0xFF;
            }
        }
        lbl_80353A90._F4 = g_Scores._B5[g_Scores._A4 ^ 1];
        if (lbl_803535C8[lbl_80353A90._F2 ^ 1][lbl_80353A90._F4]._14 < 0xFE) {
            lbl_803535C8[lbl_80353A90._F2 ^ 1][lbl_80353A90._F4]._14++;
        } else {
            lbl_803535C8[lbl_80353A90._F2 ^ 1][lbl_80353A90._F4]._14 = 0xFF;
        }
        if (g_Scores._BB[g_Scores._A4 ^ 1] == 1) {
            if (lbl_803535C8[lbl_80353A90._F2 ^ 1][lbl_80353A90._F4]._17 < 0xFE) {
                lbl_803535C8[lbl_80353A90._F2 ^ 1][lbl_80353A90._F4]._17++;
            } else {
                lbl_803535C8[lbl_80353A90._F2 ^ 1][lbl_80353A90._F4]._17 = 0xFF;
            }
        }
        if (g_Scores._B7[g_Scores._A4] != lbl_80353A90._F3 && g_Scores._B7[g_Scores._A4] >= 0) {
            lbl_80353A90._F5 = g_Scores._B7[g_Scores._A4];
            if (lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F5]._15 < 0xFE) {
                lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F5]._15++;
            } else {
                lbl_803535C8[lbl_80353A90._F2][lbl_80353A90._F5]._15 = 0xFF;
            }
        }
        for (team = 0; team < 2; team++) {
            for (i = 0; i < 9; i++) {
                if (team == g_Scores._A4) {
                    if (i == lbl_80353A90._F3) {
                        lbl_3_common_bss_32A38[lbl_80353A90._F2][i]._1 = 0;
                    }
                    if (i == lbl_80353A90._F5) {
                        lbl_3_common_bss_32A38[lbl_80353A90._F2][i]._1 = 0;
                    }
                }
                if (team == (g_Scores._A4 ^ 1) && i == lbl_80353A90._F4) {
                    lbl_3_common_bss_32A38[lbl_80353A90._F2 ^ 1][i]._1 = 0;
                }
            }
        }
    }
    for (j = 0; j < 9; j++) {
        lbl_803535C8[0][j]._19 += lbl_3_common_bss_32A38[0][j]._1;
        lbl_803535C8[1][j]._19 += lbl_3_common_bss_32A38[1][j]._1;
    }
    lbl_80353A90._F6 = g_Scores._00;
    fn_3_759BC();
    if (!g_d_GameSettings.exhibitionMatchInd) {
        fn_3_162D54();
    }
}

// .text:0x00076174 size:0x3E4 mapped:0x806B5208
void fn_3_76174(void) {
    int i;
    int best;
    int bestOuts;
    Unk12D0PitcherStats* stats;
    Unk12D0PitcherStats* cur;
    Unk12D0PitcherStats* other;
    Unk12D0PitcherStats* closerStats;
    int w;
    int team;
    s8* pStarter;
    s8 starter;
    int closer;

    w = g_Scores._A4;
    team = w ^ g_GameLogic.homeTeamInd;
    if (g_Scores._BB[w] == 1) {
        lbl_80353A90._F3 = g_Scores._AF[w];
        return;
    }
    if (g_Scores._04[1][g_Scores._00] > 0 && w == 1) {
        lbl_80353A90._F3 = g_Scores._B1[w];
        return;
    }
    if (g_Scores._00 < 5) {
        lbl_80353A90._F3 = g_Scores._B1[w];
        return;
    }
    closer = g_Scores._B3[w];
    stats = lbl_803535C8[team];
    closerStats = &stats[closer];
    if (g_Scores._B9[w] == 1) {
        if (g_Scores._00 == 5) {
            if (closerStats->_1A >= 12) {
                lbl_80353A90._F3 = g_Scores._AF[w];
                return;
            }
        } else if (closerStats->_1A >= 15) {
            lbl_80353A90._F3 = g_Scores._AF[w];
            return;
        }
        bestOuts = 0;
        best = -1;
        for (i = 0; i < 9; i++) {
            cur = &stats[i];
            if (cur->_00 != 0 && closer != i) {
                if (best == -1) {
                    bestOuts = cur->_1A;
                    best = i;
                } else if (cur->_1A - bestOuts >= 3) {
                    bestOuts = cur->_1A;
                    best = i;
                } else if (cur->_1A - bestOuts > -3) {
                    other = &stats[best];
                    if (cur->_04 < other->_04) {
                        best = i;
                    } else if (cur->_04 == other->_04) {
                        if (cur->_00 - cur->_1A < other->_00 - other->_1A) {
                            best = i;
                        } else if (cur->_00 - cur->_1A == other->_00 - other->_1A) {
                            if (cur->_1A > bestOuts) {
                                best = i;
                            } else if (bestOuts == cur->_1A && cur->_0E < other->_0E) {
                                best = i;
                            }
                        }
                    }
                    if (cur->_1A > bestOuts) {
                        bestOuts = cur->_1A;
                    }
                }
            }
        }
        lbl_80353A90._F3 = lbl_803537E4[team][best]._00;
        return;
    }
    bestOuts = 0;
    best = -1;
    if (g_Scores._BB[w] == 2) {
        lbl_80353A90._F3 = closer;
        return;
    }
    if (closer == -1 || closer == g_Scores._AF[w]) {
        pStarter = &g_Scores._AF[w];
        starter = *pStarter;
        for (i = 0; i < 9; i++) {
            if (starter != i && closer != i) {
                if (best == -1) {
                    if (lbl_3_common_bss_32A38[w][i]._0 != 0 && bestOuts == 0) {
                        best = i;
                        bestOuts = lbl_3_common_bss_32A38[w][i]._0;
                    }
                } else if (lbl_3_common_bss_32A38[w][i]._0 > bestOuts) {
                    best = i;
                    bestOuts = lbl_3_common_bss_32A38[w][i]._0;
                } else if (bestOuts == lbl_3_common_bss_32A38[w][i]._0) {
                    if (stats[i]._04 < stats[best]._04) {
                        best = i;
                    } else if (stats[i]._04 == stats[best]._04) {
                        if (stats[i]._00 < stats[best]._00) {
                            best = i;
                        } else if (stats[i]._00 == stats[best]._00 && stats[i]._0E < stats[best]._0E) {
                            best = i;
                        }
                    }
                }
            }
        }
        *pStarter = starter;
    }
    if (best == -1) {
        lbl_80353A90._F3 = g_Scores._B3[w];
    } else {
        lbl_80353A90._F3 = lbl_803537E4[team][best]._00;
    }
    if (lbl_80353A90._F3 == -1) {
        lbl_80353A90._F3 = g_Scores._B1[w];
    }
}

// .text:0x000759BC size:0x7B8 mapped:0x806B4A50
void fn_3_759BC(void) {
    int winner = -1;
    int team = -1;
    int mvpTeam;
    int t;
    int i;
    int best;
    int bestScore;
    s32 score[9];
    Unk12D0PlayerStats* player;

    lbl_80353A90._103 = -1;
    if (g_Scores._A4 == 0 || g_Scores._A4 == 1) {
        winner = g_Scores._A4;
        team = g_Scores._A4 ^ g_GameLogic.homeTeamInd;
    }
    lbl_80353A90._104 = 0;
    if (g_Scores._A4 == 0) {
        lbl_80353A90._103 = inMemRoster[team][g_GameLogic.Team_CaptainRosterLoc[team]].stats.CharID;
    } else if (g_Scores._A4 == 1) {
        lbl_80353A90._103 = inMemRoster[team][g_GameLogic.Team_CaptainRosterLoc[team]].stats.CharID;
    } else {
        lbl_80353A90._103 = inMemRoster[team][g_GameLogic.Team_CaptainRosterLoc[random_fn_3_9EE24(2)]].stats.CharID;
    }
    if (winner != 2 && ((g_d_GameSettings._10 != 0 && g_d_GameSettings._10 != 3) ||
                        ((g_GameLogic._13E[0] != 0 || team == 0) && (g_GameLogic._13E[1] != 0 || team != 0)))) {
        if (lbl_80353A90._FB >= 0) {
            lbl_3_common_bss_32A94._58[winner][0] = lbl_80353A90._FB;
            mvpTeam = team;
            lbl_80353A90._101[mvpTeam] = lbl_3_common_bss_32A94._58[winner][0];
            goto found;
        }
        if (lbl_80353A90._F7 == 1 && g_Scores._AA >= 5) {
            lbl_3_common_bss_32A94._58[winner][0] = lbl_80353A90._BE[team][0][0];
            mvpTeam = team;
            lbl_80353A90._101[mvpTeam] = lbl_3_common_bss_32A94._58[winner][0];
            goto found;
        }
        if (lbl_80353A90._F7 == 2 && g_Scores._AA >= 5) {
            lbl_3_common_bss_32A94._58[winner][0] = lbl_80353A90._BE[team][0][0];
            mvpTeam = team;
            lbl_80353A90._101[mvpTeam] = lbl_3_common_bss_32A94._58[winner][0];
            goto found;
        }
        if (lbl_80353A90._FA >= 0) {
            lbl_3_common_bss_32A94._58[winner][0] = lbl_80353A90._FA;
            mvpTeam = team;
            lbl_80353A90._101[mvpTeam] = lbl_3_common_bss_32A94._58[winner][0];
            goto found;
        }
        if (winner >= 0 && lbl_80353A90._FE == team && lbl_80353A90._FD == lbl_80353A90._FF) {
            lbl_3_common_bss_32A94._58[winner][0] = lbl_80353A90._FF;
            mvpTeam = team;
            lbl_80353A90._101[mvpTeam] = lbl_3_common_bss_32A94._58[winner][0];
            goto found;
        }
        for (t = 0; t < 2; t++) {
            bestScore = 0;
            best = -1;
            for (i = 0; i < 9; i++) {
                score[i] = 0;
                if (winner == t) {
                    if (i == lbl_80353A90._F3) {
                        score[i] = lbl_3_data_60F8[0];
                    }
                    if (i == lbl_80353A90._FF) {
                        if (lbl_80353A90._100 != 0) {
                            score[i] = lbl_3_data_60F8[1];
                        } else {
                            score[i] = lbl_3_data_60F8[4];
                        }
                    }
                }
                player = &lbl_803537E4[t ^ g_GameLogic.homeTeamInd][i];
                score[i] += lbl_3_data_60F8[2] * player->_09;
                score[i] += lbl_3_data_60F8[3] * player->_22;
                score[i] += lbl_3_data_60F8[5] * player->_23;
                score[i] += lbl_3_data_60F8[6] * lbl_803535C8[t ^ g_GameLogic.homeTeamInd][i]._1C;
                score[i] += lbl_3_data_60F8[7] * player->_10;
                score[i] += lbl_3_data_60F8[8] * (player->_05 + (player->_0E + player->_0F));
                score[i] += lbl_3_data_60F8[9] * player->_12;
                if (score[i] > bestScore) {
                    bestScore = score[i];
                    best = i;
                }
            }
            lbl_3_common_bss_32A94._58[t][0] = best;
            lbl_3_common_bss_32A94._58[t][1] = bestScore;
        }
    }
    if (g_GameLogic._13E[0] != g_GameLogic._13E[1]) {
        mvpTeam = g_GameLogic._13E[0] != 0;
        if (team == mvpTeam) {
            lbl_80353A90._101[mvpTeam] = lbl_3_common_bss_32A94._58[winner][0];
            lbl_80353A90._104 = 1;
        } else if (team >= 0) {
            lbl_80353A90._101[mvpTeam] = g_GameLogic.Team_CaptainRosterLoc[mvpTeam];
            lbl_80353A90._104 = 2;
        } else {
            lbl_80353A90._101[mvpTeam] = g_GameLogic.Team_CaptainRosterLoc[mvpTeam];
            lbl_80353A90._104 = 3;
        }
    } else if (team >= 0) {
        mvpTeam = team;
        lbl_80353A90._101[mvpTeam] = lbl_3_common_bss_32A94._58[winner][0];
    found:
        lbl_80353A90._104 = 1;
    } else {
        lbl_80353A90._101[0] = g_GameLogic.Team_CaptainRosterLoc[0];
        mvpTeam = 0;
        lbl_80353A90._104 = 3;
    }
    lbl_80353A90._103 = inMemRoster[mvpTeam][lbl_80353A90._101[mvpTeam]].stats.CharID;
    if ((g_d_GameSettings._10 == 0 || g_d_GameSettings._10 == 3) &&
        ((g_d_GameSettings._10 == 0 && mvpTeam == 0) || (g_d_GameSettings._10 == 3 && mvpTeam == 1)) &&
        g_Scores._AA >= 5 && lbl_80353A90._104 == 1) {
        if (g_d_GameSettings.exhibitionMatchInd != 0) {
            lbl_80354768._CF18[lbl_800E8558[lbl_80353A90._103][1]] = 1;
        }
        g_GameLogic._13D = 1;
    }
}
