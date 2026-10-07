#include "game/rep_18E8.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"

typedef struct {
    /* 0x000 */ f32 _000;
    /* 0x004 */ f32 _004;
    /* 0x008 */ f32 _008;
    /* 0x00C */ u8 _00C[0x48 - 0xC];
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x70 - 0x4C];
    /* 0x070 */ f32 _070;
    /* 0x074 */ u8 _074[0xA8 - 0x74];
    /* 0x0A8 */ f32 _0A8[3];
    /* 0x0B4 */ f32 _0B4;
    /* 0x0B8 */ f32 _0B8;
    /* 0x0BC */ u8 _0BC[0x178 - 0xBC];
    /* 0x178 */ s16 _178;
    /* 0x17A */ u8 _17A[0x18C - 0x17A];
    /* 0x18C */ s16 _18C;
    /* 0x18E */ u8 _18E[0x1CE - 0x18E];
    /* 0x1CE */ u8 _1CE;
    /* 0x1CF */ u8 _1CF[0x1ED - 0x1CF];
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
void fn_3_AAA3C(s32 fielder) {
    Unk18E8Fielder* f = &g_Fielders[fielder];

    if (g_FieldingLogic._0CE < 0 || g_FieldingLogic._0C4 < 0 || g_FieldingLogic._0C4 > 3) {
        return;
    }
    if (f->_0A8[g_FieldingLogic._0C4] > 10.0f && g_FieldingLogic._0DC < 0) {
        return;
    }
    if (g_FieldingLogic._0C4 == g_FieldingLogic._0CE && g_FieldingLogic._0E0 >= 0 && g_FieldingLogic._0E0 <= 3 &&
        (g_FieldingLogic._0DC == g_Runners[g_FieldingLogic._0E0].nextBase ||
         g_FieldingLogic._0DC == g_Runners[g_FieldingLogic._0E0].currentBase)) {
        g_FieldingLogic._119 = 1;
    }
    if (g_FieldingLogic._0CE == 9 && g_FieldingLogic._0E0 >= 0 && g_FieldingLogic._0E0 <= 3 &&
        g_Runners[g_FieldingLogic._0E0].runnerOnFieldOrOutOrScored == 1 &&
        g_FieldingLogic._0C4 == g_Runners[g_FieldingLogic._0E0].baseRunningTowards) {
        g_FieldingLogic._119 = 1;
    }
    if (g_FieldingLogic._119 && g_FieldingLogic._0C4 >= 0 && g_FieldingLogic._0C4 <= 3 &&
        fn_3_9FC1C(game_atan2(lbl_3_data_4444[g_FieldingLogic._0C4][0] - f->_000,
                              lbl_3_data_4444[g_FieldingLogic._0C4][1] - f->_008),
                   f->_048) > 0x40) {
        g_FieldingLogic._119 = 0;
    }
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
// 99.64%: idx gets r8 where the target uses r6 (and r7 for its scaled index);
// declaration order and if/ternary forms change nothing.
BOOL fn_3_A8478(s32* runnerOut, s32* framesOut) {
    s32 idx;
    InMemRunnerType* r;
    s32 cur = g_FieldingLogic._0C4;

    if (g_FieldingLogic._0C4 >= 4 || g_FieldingLogic._0C4 < 0) {
        return FALSE;
    }
    if (g_Ball.AtBat_ContactResult == 3) {
        r = &g_Runners[cur];
        if (r->runnerOnFieldOrOutOrScored == 1 && r->tagUpInd == 2) {
            *runnerOut = cur;
            goto tagUp;
        }
    }
    idx = 3;
    if (cur != 0) {
        idx = cur - 1;
    }
    r = &g_Runners[idx];
    if (r->runnerOnFieldOrOutOrScored == 1 && r->forceOutCd == 1) {
        *runnerOut = idx;
        goto forced;
    }
    return FALSE;

tagUp:
    if (r->currentBase == cur) {
        if (r->runningDirectionCode == 3 || r->runningDirectionCode == 2) {
            *framesOut = r->framesToPreviousBase;
        } else if ((r->runningDirectionCode == 1 && r->nextDirectionBeingProcessed == 3) ||
                   (r->runningDirectionCode == 3 && r->nextDirectionBeingProcessed == 1)) {
            *framesOut = r->framesToPreviousBase + 20;
        } else {
            *framesOut = r->framesToPreviousBase + 50;
        }
    } else {
        *framesOut = r->framesToPreviousBase + r->framesToPreviousBase + r->framesToNextBase;
    }
    return TRUE;

forced:
    *framesOut = r->framesToNextBase;
    return TRUE;
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
    InputStruct* inputs;
    u8 prev;

    inputs = &g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]];
    if (ACTIVE_TUTORIAL()) {
        inputs = &g_Practice.inputs[g_GameLogic.teamFielding];
    } else if (g_d_GameSettings.minigamesEnabled) {
        inputs = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[g_Minigame._1922]];
    }
    prev = g_FieldingLogic._12E;
    if (inputs->controlStickAngle >= 0xE00) {
        g_FieldingLogic._12E = 2;
    } else if (inputs->controlStickAngle >= 0xA00) {
        g_FieldingLogic._12E = 3;
    } else if (inputs->controlStickAngle >= 0x600) {
        g_FieldingLogic._12E = 4;
    } else if (inputs->controlStickAngle >= 0x200) {
        g_FieldingLogic._12E = 1;
    } else if (inputs->controlStickAngle >= 0) {
        g_FieldingLogic._12E = 2;
    } else {
        g_FieldingLogic._12E = 0;
    }
    if (g_FieldingLogic._12E == 0) {
        g_FieldingLogic._12F = 0;
    } else if (g_FieldingLogic._12E == prev) {
        if (g_FieldingLogic._12F < 0xFE) {
            g_FieldingLogic._12F++;
        } else {
            g_FieldingLogic._12F = 0xFF;
        }
    } else {
        g_FieldingLogic._12F = 1;
    }
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
    s32 i;

    lbl_3_bss_1824 = 0;
    lbl_3_bss_1808[0] = -1;
    lbl_3_bss_1808[1] = -1;
    lbl_3_bss_1808[2] = -1;
    lbl_3_bss_1808[3] = -1;
    for (i = 3; i >= 0; i--) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            InMemRunnerType* r = &g_Runners[i];
            lbl_3_bss_1824 |= 1 << ((s32)r->fractionalBasesRan * 4);
            if (lbl_3_bss_1808[r->currentBase] < 0 || g_Runners[lbl_3_bss_1808[r->currentBase]].baseStandingOn >= 0) {
                lbl_3_bss_1808[r->currentBase] = i;
            }
        }
    }
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
BOOL fn_3_A2404(void) {
    s32 order[3];
    s32 i;

    if (g_Ball.AtBat_ContactResult != 3) {
        return FALSE;
    }
    if (lbl_3_bss_1820 == 0) {
        return FALSE;
    }
    if (g_Ball.ballDistanceFromBase[1] < g_Ball.ballDistanceFromBase[3]) {
        if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[1]) {
            order[0] = 2;
            order[1] = 1;
            order[2] = 3;
        } else if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[3]) {
            order[0] = 1;
            order[1] = 2;
            order[2] = 3;
        } else {
            order[0] = 1;
            order[1] = 3;
            order[2] = 2;
        }
    } else if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[3]) {
        order[0] = 2;
        order[1] = 3;
        order[2] = 1;
    } else if (g_Ball.ballDistanceFromBase[2] < g_Ball.ballDistanceFromBase[1]) {
        order[0] = 3;
        order[1] = 2;
        order[2] = 1;
    } else {
        order[0] = 3;
        order[1] = 1;
        order[2] = 2;
    }
    for (i = 0; i < 3; i++) {
        InMemRunnerType* r = &g_Runners[order[i]];
        if (r->runnerOnFieldOrOutOrScored == 1 && r->tagUpInd == 2 && lbl_3_bss_1858[order[i]] <= 4 &&
            fn_3_A46A0(order[i])) {
            return TRUE;
        }
    }
    return FALSE;
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
BOOL fn_3_A1DA0(void) {
    Unk18E8Fielder* f = &g_Fielders[g_Ball.fielderWBallIndex];

    if (f->_070 > 80.0f - 0.1f * (100 - f->_1CE)) {
        return FALSE;
    }
    if (!(g_Runners[3].runnerOnFieldOrOutOrScored == 1 && g_Runners[3].fractionalBasesRan < 3.15f &&
          (g_Runners[3].runningDirectionCode == 2 || g_Runners[3].runningDirectionCode == 1)) &&
        !(g_Runners[2].runnerOnFieldOrOutOrScored == 1 && g_Runners[2].fractionalBasesRan > 2.85f &&
          g_Runners[2].fractionalBasesRan <= 3.15f && g_Runners[3].runningDirectionCode == 1 && g_Runners[2].tagUpInd == 0)) {
        return FALSE;
    }
    if (g_Runners[1].runnerOnFieldOrOutOrScored == 1) {
        if (g_Runners[1].tagUpInd) {
            if (g_Runners[1].fractionalBasesRan > 1.5f) {
                return FALSE;
            }
        } else if (g_Runners[1].forceOutCd == 1 && g_Runners[1].fractionalBasesRan <= 0.7f) {
            return FALSE;
        }
    }
    g_FieldingLogic._0C4 = 0;
    g_FieldingLogic._0CC = -1;
    g_FieldingLogic._0DE = -1;
    return TRUE;
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
