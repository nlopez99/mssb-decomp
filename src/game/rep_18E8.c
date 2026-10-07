#include "game/rep_18E8.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"

typedef struct {
    /* 0x000 */ u8 _000[0xB4];
    /* 0x0B4 */ f32 _0B4;
    /* 0x0B8 */ f32 _0B8;
    /* 0x0BC */ u8 _0BC[0x178 - 0xBC];
    /* 0x178 */ s16 _178;
    /* 0x17A */ u8 _17A[0x18C - 0x17A];
    /* 0x18C */ s16 _18C;
    /* 0x18E */ u8 _18E[0x1ED - 0x18E];
    /* 0x1ED */ u8 _1ED;
    /* 0x1EE */ u8 _1EE[0x1F8 - 0x1EE];
    /* 0x1F8 */ u8 _1F8;
    /* 0x1F9 */ u8 _1F9[0x215 - 0x1F9];
    /* 0x215 */ u8 _215;
    /* 0x216 */ u8 _216[0x268 - 0x216];
} Unk18E8Fielder; // size: 0x268

extern Unk18E8Fielder g_Fielders[9];
extern u8 lbl_3_data_4900[][3];
extern f32 lbl_3_data_4444[5][2];
extern u8 lbl_3_data_1C38[2];

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ u8 _50[0xAA - 0x50];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB[0xAD - 0xAB];
    /* 0xAD */ u8 _AD;
} g_Scores;

// rep_AC8.h declares this as a void(void) placeholder
extern void fn_3_52F4C(s32 fielder, f32 x, f32 z);

// .bss statics, in reverse address order: MWCC lays them out last declared first
static u8 lbl_3_bss_1868[0x98];
static s32 lbl_3_bss_1858[4];
static s32 lbl_3_bss_1848[4];
static s32 lbl_3_bss_1838[4];
static s32 lbl_3_bss_1828[4];
static s32 lbl_3_bss_1824;
static s32 lbl_3_bss_1820;
static s32 lbl_3_bss_181C;
static s32 lbl_3_bss_1818;
static s32 lbl_3_bss_1808[4];
static s32 lbl_3_bss_1804;
static s32 lbl_3_bss_1800;
static u8 lbl_3_bss_17FC[4];
static s32 lbl_3_bss_17F8;

// .text:0x000ABDD0 size:0xC28 mapped:0x806EAE64
void fn_3_ABDD0(void) {
    return;
}

// .text:0x000AB5B0 size:0x820 mapped:0x806EA644
void fn_3_AB5B0(void) {
    return;
}

// .text:0x000AB554 size:0x5C mapped:0x806EA5E8
void fn_3_AB554(void) {
    if (g_FieldingLogic._10D) {
        if (g_Ball.timeSinceBallPickedUp >= 0 && g_Ball.timeSinceBallPickedUp < 40) {
            if (g_FieldingLogic._0C4 >= 0) {
                g_FieldingLogic._10C = 1;
                g_FieldingLogic._10D = 0;
            }
        } else {
            g_FieldingLogic._10D = 0;
        }
    }
}

// .text:0x000AAFF0 size:0x564 mapped:0x806EA084
void fn_3_AAFF0(void) {
    return;
}

// .text:0x000AAC84 size:0x36C mapped:0x806E9D18
void fn_3_AAC84(void) {
    return;
}

// .text:0x000AABF8 size:0x8C mapped:0x806E9C8C
BOOL fn_3_AABF8(void) {
    if (g_FieldingLogic._0D8 == -1) {
        return FALSE;
    }
    if (g_FieldingLogic.playerAtMoundCutoffLocation != 1) {
        return FALSE;
    }
    if (g_Fielders[g_FieldingLogic._0D8]._18C != 5) {
        return FALSE;
    }
    return !(g_Fielders[g_Ball.fielderWBallIndex]._0B8 < 10.0f);
}

// .text:0x000AAA3C size:0x1BC mapped:0x806E9AD0
void fn_3_AAA3C(void) {
    return;
}

// .text:0x000A9D20 size:0xD1C mapped:0x806E8DB4
void fn_3_A9D20(void) {
    return;
}

// .text:0x000A9C74 size:0xAC mapped:0x806E8D08
void fn_3_A9C74(s32 fielder) {
    Unk18E8Fielder* f = &g_Fielders[fielder];
    BOOL stat = checkFieldingStat(g_GameLogic.teamFielding, f->_178, 5);

    if (f->_1F8 >= 3) {
        f->_215 = lbl_3_data_4900[stat][1];
    } else {
        f->_215 = lbl_3_data_4900[stat][0];
    }
    if (stat && g_FieldingLogic._0C4 >= 0) {
        playSoundEffect(0x1A8);
    }
}

// .text:0x000A9984 size:0x2F0 mapped:0x806E8A18
void fn_3_A9984(void) {
    return;
}

// .text:0x000A96FC size:0x288 mapped:0x806E8790
void fn_3_A96FC(void) {
    return;
}

// .text:0x000A9354 size:0x3A8 mapped:0x806E83E8
void fn_3_A9354(void) {
    return;
}

// .text:0x000A89D4 size:0x980 mapped:0x806E7A68
void fn_3_A89D4(void) {
    return;
}

// .text:0x000A85C8 size:0x40C mapped:0x806E765C
void fn_3_A85C8(void) {
    return;
}

// .text:0x000A8478 size:0x150 mapped:0x806E750C
void fn_3_A8478(void) {
    return;
}

// .text:0x000A8338 size:0x140 mapped:0x806E73CC
void fn_3_A8338(void) {
    return;
}

// .text:0x000A8074 size:0x2C4 mapped:0x806E7108
void fn_3_A8074(void) {
    return;
}

// .text:0x000A7EF8 size:0x17C mapped:0x806E6F8C
void fn_3_A7EF8(void) {
    return;
}

// .text:0x000A7C88 size:0x270 mapped:0x806E6D1C
void fn_3_A7C88(void) {
    return;
}

// .text:0x000A76B4 size:0x5D4 mapped:0x806E6748
void fn_3_A76B4(void) {
    return;
}

// .text:0x000A7040 size:0x674 mapped:0x806E60D4
void fn_3_A7040(void) {
    return;
}

// .text:0x000A6E98 size:0x1A8 mapped:0x806E5F2C
void fn_3_A6E98(void) {
    return;
}

// .text:0x000A6D48 size:0x150 mapped:0x806E5DDC
void fn_3_A6D48(void) {
    return;
}

// .text:0x000A6ABC size:0x28C mapped:0x806E5B50
void fn_3_A6ABC(void) {
    return;
}

// .text:0x000A6810 size:0x2AC mapped:0x806E58A4
s32 fn_3_A6810(f32 x0, f32 z0, f32 x1, f32 z1) {
    return 0;
}

// .text:0x000A67E8 size:0x28 mapped:0x806E587C
void fn_3_A67E8(s32 idx) {
    lbl_3_bss_1838[idx] = 9;
    lbl_3_bss_1828[idx] = -1;
}

// .text:0x000A63E4 size:0x404 mapped:0x806E5478
s32 fn_3_A63E4(s32 runner, s32 arg1, s32* out0, s32* out1) {
    return 0;
}

// .text:0x000A5B4C size:0x898 mapped:0x806E4BE0
void fn_3_A5B4C(void) {
    return;
}

// .text:0x000A5704 size:0x448 mapped:0x806E4798
void fn_3_A5704(void) {
    return;
}

// .text:0x000A53DC size:0x328 mapped:0x806E4470
void fn_3_A53DC(void) {
    return;
}

// .text:0x000A4F50 size:0x48C mapped:0x806E3FE4
void fn_3_A4F50(void) {
    return;
}

// .text:0x000A4A10 size:0x540 mapped:0x806E3AA4
void fn_3_A4A10(void) {
    return;
}

// .text:0x000A46A0 size:0x370 mapped:0x806E3734
BOOL fn_3_A46A0(s32 runner) {
    InMemRunnerType* r = &g_Runners[runner];
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];

    if (runner < 0) {
        g_FieldingLogic._0CC = -1;
        g_FieldingLogic._0C4 = -1;
        return FALSE;
    }
    if (runner == 0 && r->currentBase == 0 && f->_1ED == 0 && fn_3_A36BC()) {
        g_FieldingLogic._0CC = 9;
        g_FieldingLogic._0DE = runner;
        g_FieldingLogic._0C4 = -1;
        fn_3_52F4C(g_Ball.fielderWBallIndex, r->position.x, r->position.z);
        return TRUE;
    }
    if (lbl_3_bss_1838[runner] >= 0) {
        if (f->_1ED) {
            g_FieldingLogic._0CC = -1;
            g_FieldingLogic._0DE = -1;
            return TRUE;
        }
        if (g_FieldingLogic._0CC != lbl_3_bss_1838[runner]) {
            g_FieldingLogic._0CC = lbl_3_bss_1838[runner];
            if (g_FieldingLogic._0CC == 9) {
                if (g_FieldingLogic._130 && !g_GameLogic.autoFielding[g_GameLogic.awayTeamBattingInd_battingTeam]) {
                    g_FieldingLogic._0CC = -1;
                } else {
                    g_FieldingLogic._0DE = runner;
                }
            }
            if (g_FieldingLogic._0CC != 9) {
                fn_3_52F4C(g_Ball.fielderWBallIndex, lbl_3_data_4444[g_FieldingLogic._0CC][0],
                           lbl_3_data_4444[g_FieldingLogic._0CC][1]);
            }
        }
        if (g_FieldingLogic._0CC == 9) {
            fn_3_A4158(runner);
        }
    } else {
        g_FieldingLogic._0CC = -1;
        g_FieldingLogic._0DE = -1;
    }
    if (lbl_3_bss_1828[runner] >= 10) {
        g_FieldingLogic._0C4 = -1;
        return TRUE;
    }
    g_FieldingLogic._0C4 = lbl_3_bss_1828[runner];
    g_FieldingLogic._12D = 1;
    if (lbl_3_bss_1858[runner] >= 4) {
        s32 chance = lbl_3_data_1C38[0] + (s32)((lbl_3_data_1C38[1] - lbl_3_data_1C38[0]) *
                                                g_AiLogic.aIDifficultyMultiplierArray[g_GameLogic.awayTeamBattingInd_battingTeam]);
        if (chance < RandomInt_Game(100)) {
            g_FieldingLogic._12D = 0;
        }
    }
    if (g_FieldingLogic._0C4 == -1 && g_FieldingLogic._0CC == -1) {
        return FALSE;
    }
    return TRUE;
}

// .text:0x000A41E8 size:0x4B8 mapped:0x806E327C
void fn_3_A41E8(void) {
    return;
}

// .text:0x000A4158 size:0x90 mapped:0x806E31EC
void fn_3_A4158(s32 runner) {
    InMemRunnerType* r = &g_Runners[runner];

    if (r->runningDirectionCode == 2) {
        fn_3_52F4C(g_Ball.fielderWBallIndex, r->position.x, r->position.z);
    } else {
        fn_3_52F4C(g_Ball.fielderWBallIndex, r->position.x + 2.0f * (r->velocity.x * r->distanceFromBall),
                   r->position.z + 2.0f * (r->velocity.y * r->distanceFromBall));
    }
}

// .text:0x000A3CC0 size:0x498 mapped:0x806E2D54
void fn_3_A3CC0(void) {
    return;
}

// .text:0x000A3C00 size:0xC0 mapped:0x806E2C94
void fn_3_A3C00(void) {
    s32 i;

    lbl_3_bss_1800 = 0;
    for (i = 0; i < 4; i++) {
        if (lbl_3_bss_1808[i] >= 0) {
            u8 dir = g_Runners[lbl_3_bss_1808[i]].runningDirectionCode;
            if (dir == 1) {
                lbl_3_bss_1800 |= 1 << (i * 4);
            } else if (dir == 3) {
                lbl_3_bss_1800 |= 2 << (i * 4);
            } else if (dir == 2) {
                lbl_3_bss_1800 |= 4 << (i * 4);
            }
        }
    }
}

// .text:0x000A3B30 size:0xD0 mapped:0x806E2BC4
void fn_3_A3B30(void) {
    s32 diff = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] -
               g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0];

    lbl_3_bss_181C = 0;
    if (g_Scores._00 >= g_Scores._AA && g_Scores._AD && diff == 0) {
        lbl_3_bss_181C = 3;
    } else if (g_Scores._00 >= g_Scores._AA - 1 && diff <= 1 && diff >= -1) {
        lbl_3_bss_181C = 2;
    } else if (g_Scores._00 >= g_Scores._AA - 4 && diff <= 1 && diff >= -3) {
        lbl_3_bss_181C = 1;
    }
}

// .text:0x000A384C size:0x2E4 mapped:0x806E28E0
void fn_3_A384C(void) {
    return;
}

// .text:0x000A37BC size:0x90 mapped:0x806E2850
BOOL fn_3_A37BC(void) {
    if (g_Ball.ballAngleFromHome < 0x398) {
        return FALSE;
    }
    if (g_Ball.ballDistanceFromBase[2] < 5.0f) {
        return TRUE;
    }
    if (g_Ball.ballAngleFromHome < 0x400) {
        if (g_Ball.AtBat_Contact_BallPos.z + g_Ball.AtBat_Contact_BallPos.x > 40.0f) {
            return TRUE;
        }
    } else if (g_Ball.AtBat_Contact_BallPos.z - g_Ball.AtBat_Contact_BallPos.x > 40.0f) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A3768 size:0x54 mapped:0x806E27FC
BOOL fn_3_A3768(void) {
    if (g_Ball.ballAngleFromHome >= 0x380 && g_Ball.ballAngleFromHome < 0x640 && g_Ball.ballZoneAwayFromHome <= 1 &&
        g_Ball.AtBat_Contact_BallPos.z > 35.0f + g_Ball.AtBat_Contact_BallPos.x) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A372C size:0x3C mapped:0x806E27C0
BOOL fn_3_A372C(void) {
    if (g_Ball.AtBat_Contact_BallPos.z < 40.0f + g_Ball.AtBat_Contact_BallPos.x &&
        g_Ball.AtBat_Contact_BallPos.z < 40.0f - g_Ball.AtBat_Contact_BallPos.x) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A36BC size:0x70 mapped:0x806E2750
BOOL fn_3_A36BC(void) {
    if (g_Ball.AtBat_Contact_BallPos.z < 15.0f && g_Ball.AtBat_Contact_BallPos.z > 8.0f &&
        g_Ball.AtBat_Contact_BallPos.z < 1.5f + g_Ball.AtBat_Contact_BallPos.x &&
        g_Ball.AtBat_Contact_BallPos.z > g_Ball.AtBat_Contact_BallPos.x - 1.5f &&
        g_Ball.AtBat_Contact_BallPos.x > g_Runners[0].position.x) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A3374 size:0x348 mapped:0x806E2408
void fn_3_A3374(void) {
    return;
}

// .text:0x000A32B8 size:0xBC mapped:0x806E234C
BOOL fn_3_A32B8(void) {
    if (!(lbl_3_bss_1824 & 0x1000)) {
        return FALSE;
    }
    if ((lbl_3_bss_1804 & 0x1000) && fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    if ((lbl_3_bss_1800 & 0x1000) && g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase >= 0.2f &&
        fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A31E8 size:0xD0 mapped:0x806E227C
BOOL fn_3_A31E8(void) {
    if (!(lbl_3_bss_1824 & 0x1000)) {
        return FALSE;
    }
    if ((lbl_3_bss_1804 & 0x1000) && fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    if ((lbl_3_bss_1800 & 0x1000) && g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase >= 0.2f &&
        lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 6 && fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A2FD8 size:0x210 mapped:0x806E206C
void fn_3_A2FD8(void) {
    return;
}

// .text:0x000A2DDC size:0x1FC mapped:0x806E1E70
void fn_3_A2DDC(void) {
    return;
}

// .text:0x000A2C9C size:0x140 mapped:0x806E1D30
BOOL fn_3_A2C9C(void) {
    if ((lbl_3_bss_1824 & 0x100) && g_Ball.ballDistanceFromBase[3] < 5.0f && lbl_3_bss_1858[lbl_3_bss_1808[2]] <= 2 &&
        fn_3_A46A0(lbl_3_bss_1808[2])) {
        return TRUE;
    }
    if (lbl_3_bss_1818 != 0 && fn_3_A46A0(lbl_3_bss_1808[1])) {
        return TRUE;
    }
    if (lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 4 && g_Strikes.outs == g_Strikes.storedOuts) {
        if (g_Ball.ballDistanceFromBase[1] < 2.5f && lbl_3_bss_1858[lbl_3_bss_1808[1]] <= 2 && fn_3_A46A0(lbl_3_bss_1808[0])) {
            return TRUE;
        }
        if (fn_3_A46A0(lbl_3_bss_1808[1])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A2B6C size:0x130 mapped:0x806E1C00
BOOL fn_3_A2B6C(void) {
    if (g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase >= 0.25f) {
        if (lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 3 && fn_3_A46A0(lbl_3_bss_1808[3])) {
            return TRUE;
        }
        if ((lbl_3_bss_1800 & 0x6000) && lbl_3_bss_1858[lbl_3_bss_1808[3]] <= 4 && g_FieldingLogic._0D6 >= 0 &&
            !(g_Fielders[g_FieldingLogic._0D6]._0B4 > 4.0f) &&
            (!(g_Runners[lbl_3_bss_1808[3]].percentTowardsNextBase < 0.5f) || lbl_3_bss_17FC[3]) &&
            fn_3_A46A0(lbl_3_bss_1808[3])) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000A295C size:0x210 mapped:0x806E19F0
void fn_3_A295C(void) {
    return;
}

// .text:0x000A25C4 size:0x398 mapped:0x806E1658
void fn_3_A25C4(void) {
    return;
}

// .text:0x000A2404 size:0x1C0 mapped:0x806E1498
void fn_3_A2404(void) {
    return;
}

// .text:0x000A222C size:0x1D8 mapped:0x806E12C0
void fn_3_A222C(void) {
    return;
}

// .text:0x000A2048 size:0x1E4 mapped:0x806E10DC
void fn_3_A2048(void) {
    return;
}

// .text:0x000A1F3C size:0x10C mapped:0x806E0FD0
BOOL fn_3_A1F3C(void) {
    s32 i;

    if (g_Ball.ballZoneAwayFromHome >= 3) {
        return FALSE;
    }
    if (lbl_3_bss_1808[3] < 0 || lbl_3_bss_1808[3] > 3) {
        return FALSE;
    }
    if (lbl_3_bss_1858[lbl_3_bss_1808[3]] >= 7) {
        return FALSE;
    }
    if (g_Runners[lbl_3_bss_1808[3]].tagUpInd) {
        return FALSE;
    }
    if (lbl_3_bss_1808[3] >= 1) {
        for (i = lbl_3_bss_1808[3] - 1; i >= 0; i--) {
            if (g_Runners[i].percentTowardsNextBase > 0.15f && g_Runners[i].percentTowardsNextBase < 0.85f) {
                return FALSE;
            }
        }
    }
    if (fn_3_A46A0(lbl_3_bss_1808[3])) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000A1DA0 size:0x19C mapped:0x806E0E34
void fn_3_A1DA0(void) {
    return;
}

// .text:0x000A1D04 size:0x9C mapped:0x806E0D98
s32 fn_3_A1D04(void) {
    s32 prev;
    f32 prevBases = -10.0f;
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            f32 bases = g_Runners[i].fractionalBasesRan;
            f32 diff = bases - prevBases;
            if (diff < 0.0f) {
                diff = -diff;
            }
            if (diff < 0.35f) {
                if (g_Runners[prev].baseStandingOn < 0) {
                    return prev;
                }
                return i;
            }
            prevBases = bases;
            prev = i;
        }
    }
    return -1;
}

// .text:0x000A009C size:0x1C68 mapped:0x806DF130
void fn_3_A009C(void) {
    return;
}
