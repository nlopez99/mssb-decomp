#include "game/rep_36D8.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "game/rep_28A8.h"
#include "game/rep_3448.h"
#include "game/kinoko.h"
#include "game/m_sound.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/rand.h"
#include "string.h"

// The chain chomp, at g_Minigame._CB0
typedef struct Unk36D8Chomp {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ Vec _0C;
    /* 0x18 */ f32 _18;
    /* 0x1C */ s16 _1C;
    /* 0x1E */ u8 _1E;
} Unk36D8Chomp;

// One per player, at g_Minigame._1DCC
typedef struct {
    /* 0x0 */ s16 _0;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ s8 _4;
    /* 0x5 */ u8 _5;
    /* 0x6 */ s8 _6;
    /* 0x7 */ s8 _7;
} Unk36D8Cpu;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_3_data_21278[2];
extern f32 lbl_3_data_217F8[3];
extern s16 lbl_3_data_21804[5][9];
extern u8 lbl_3_data_2187C[4][2];
extern u8 lbl_3_data_21884[4][2];
extern f32 lbl_3_data_2188C[7];
extern s16 lbl_3_data_218A8;
extern u8 lbl_3_data_218AC[5][3];
extern f32 lbl_3_data_218BC[18];
extern s16 lbl_3_data_21904[12];
extern s16 lbl_3_data_21924[4];
extern s8 lbl_3_data_21944[4][2];
extern s16 lbl_3_data_2194C[4][2];
extern s8 lbl_3_data_2197C[4];
extern s8 lbl_3_data_21980[4];

extern void fn_3_5A6D4(u8 status);
extern void fn_3_10F550(u8, s16);
extern void changeScene(u8, s16);
extern void fn_3_7D9DC(int);
extern void fn_3_7DD6C(void);
extern void fn_3_7FED4(void* obj, f32 pos, f32 arg2);
extern void fn_3_157DB8(s16);
extern void fn_800528B4(void);
extern void fn_800115C8(u8);
extern void fn_80011578(void);
extern void fn_8004C094(Vec*);
extern void fn_3_14C904(void);
extern void fn_3_151798(void);
extern void fn_3_152AB4(u8, u8);
extern void fn_3_1541C4(u8, u8, VecXYZ*);
extern void fn_3_1578F8(void);
extern void fn_3_1608F0(int, int, int);
extern void fn_3_106EB0(void);

s32 lbl_3_data_265F0 = -1;

static f32 lbl_3_bss_B794;
static s32 lbl_3_bss_B798;

// .text:0x001414AC size:0x580 mapped:0x80780540
void fn_3_1414AC(void) {
    return;
}

// .text:0x001413E4 size:0xC8 mapped:0x80780478
void fn_3_1413E4(void) {
    fn_3_7DD6C();
    switch (g_GameLogic._125) {
    case 0:
        fn_3_10F550(2, lbl_3_data_21278[0]);
        changeScene(1, 6);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125 = 1;
        break;
    case 1:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > lbl_3_data_21278[0] + lbl_3_data_21278[1]) {
            g_GameLogic._125 = 2;
        }
        break;
    case 2:
        fn_3_5A6D4(GAME_STATUS_DEFAULT);
        break;
    }
}

// .text:0x001412BC size:0x128 mapped:0x80780350
void fn_3_1412BC(void) {
    fn_3_13DEA4();
    changeScene(1, 6);
    fn_3_5A6D4(GAME_STATUS_LIVE_BALL);
}

// .text:0x001410F0 size:0x1CC mapped:0x80780184
void fn_3_1410F0(void) {
    u32 i;

    fn_3_DE4FC();
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    g_Minigame._1AF8 = 0;
    g_Minigame._1B19 = 0;
    g_Minigame._1AE0 = lbl_3_data_217F8[0];
    g_Minigame._1AE4 = lbl_3_data_217F8[1];
    g_Minigame._1AE8 = lbl_3_data_217F8[2];
    g_Minigame._1AEC = 0.0f;
    g_Minigame._1AF0 = 0.0f;
    g_Minigame._1AF4 = 0.0f;
    g_Minigame._1AFA = 0;
    g_Minigame._1AF8 = 0xE00;
    for (i = 0; i < 100; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 0;
        g_Minigame.wallBall_coinsVisibleFrameCounter[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        g_Minigame._1B1A[i] = 0;
        g_Minigame._1B08[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        g_Minigame._1B26[i][0] = -1;
        g_Minigame._1B26[i][1] = -1;
    }
    g_Minigame._1B2E = 0;
    g_Minigame._CCE[0] = 0;
    fn_80011578();
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
}

// .text:0x00140CE0 size:0x410 mapped:0x8077FD74
void fn_3_140CE0(void) {
    return;
}

// .text:0x00140BCC size:0x114 mapped:0x8077FC60
void fn_3_140BCC(void) {
    if (g_Minigame.turnOverStatus == 0) {
        if (g_Minigame._17C4 == 0) {
            fn_3_10F550(3, 0);
            sndFXStart(0x1BE, lbl_800EFBA4[7], 0x3F);
            fn_3_151798();
            fn_3_11F480();
            fn_80011578();
            g_Minigame._CCE[0] = 0;
            g_Minigame.turnOverStatus = 1;
        }
    } else {
        if (g_Minigame.turnOverStatus == 1) {
            g_Minigame.turnOverStatus = 2;
            g_GameLogic.CountdownUntilFade = lbl_3_data_21904[0];
        }
        if (g_Minigame._1B19 != 3) {
            g_GameLogic.CountdownUntilFade--;
        }
        if (g_GameLogic.CountdownUntilFade == 7) {
            changeScene(3, 6);
            fn_3_1578F8();
        }
        if (g_GameLogic.CountdownUntilFade <= 0) {
            fn_3_1409AC();
        }
    }
}

// .text:0x001409AC size:0x220 mapped:0x8077FA40
void fn_3_1409AC(void) {
    u32 i;

    fn_3_DE4FC();
    if (g_Minigame.soloMinigameDifficulty <= MINIGAME_DIFFICULTY_MULTIPLAYER_CHALLENGE_HARD && !g_Minigame.multiPlayerInd) {
        if (g_Minigame.minigameControlStruct._1C[g_Minigame._1908] == 1 && !g_Minigame.challenge_minigame_haven_tWonYetIndicator) {
            g_Minigame._1A37 = 1;
        } else {
            g_Minigame._1A37 = 2;
        }
    }
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    g_Minigame._1AF8 = 0;
    g_Minigame._1B19 = 0;
    g_Minigame._1AE0 = lbl_3_data_217F8[0];
    g_Minigame._1AE4 = lbl_3_data_217F8[1];
    g_Minigame._1AE8 = lbl_3_data_217F8[2];
    g_Minigame._1AEC = 0.0f;
    g_Minigame._1AF0 = 0.0f;
    g_Minigame._1AF4 = 0.0f;
    g_Minigame._1AFA = 0;
    g_Minigame._1AF8 = 0xE00;
    for (i = 0; i < 100; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 0;
        g_Minigame.wallBall_coinsVisibleFrameCounter[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        g_Minigame._1B1A[i] = 0;
        g_Minigame._1B08[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        g_Minigame._1B26[i][0] = -1;
        g_Minigame._1B26[i][1] = -1;
    }
    g_Minigame._1B2E = 0;
    g_Minigame._CCE[0] = 0;
}

// .text:0x001406F4 size:0x2B8 mapped:0x8077F788
void fn_3_1406F4(void) {
    if (g_Minigame._1AFA < 0x7FFE) {
        g_Minigame._1AFA++;
    } else {
        g_Minigame._1AFA = 0x7FFF;
    }
    switch (g_Minigame._1B19) {
    case 0:
        fn_3_1405D8();
        break;
    case 1:
        fn_3_140484();
        break;
    case 2:
        fn_3_140284();
        break;
    case 3:
        fn_3_13FC24();
        break;
    case 4:
        fn_3_13F8C4();
        break;
    }
}

// .text:0x001405D8 size:0x11C mapped:0x8077F66C
void fn_3_1405D8(void) {
    u8 difficulty;
    s16 weight;

    if (g_Minigame._1AFA <= 1) {
        if (g_Minigame.multiPlayerInd) {
            difficulty = 4;
        } else {
            difficulty = g_Minigame.soloMinigameDifficulty;
        }
        weight = RandomInt_Game_Range(0, 1000);
        g_Minigame._1B06 = 0;
        do {
            weight -= lbl_3_data_21804[difficulty][g_Minigame._1B06++];
        } while (weight > 0 && lbl_3_data_21804[difficulty][g_Minigame._1B06] >= 0);
        g_Minigame._1B06 *= 120;
        g_Minigame._1B06 -= 48;
        fn_3_157DB8(g_Minigame._1B06);
    } else {
        g_Minigame._1AF8 = 0xE00;
        if (g_Minigame._1AFA >= g_Minigame._1B06) {
            g_Minigame._1B19 = 1;
            g_Minigame._1AFA = 0;
            g_Minigame._1AF0 = lbl_3_data_218BC[3];
            fn_3_14C904();
            fn_3_90064(0x2E0);
        }
    }
}

// .text:0x00140484 size:0x154 mapped:0x8077F518
void fn_3_140484(void) {
    int i;

    if (g_Minigame.turnOverStatus == 0) {
        g_Minigame._1AE4 += g_Minigame._1AF0;
        if (g_Minigame._1AE4 <= 0.0f && g_Minigame._1AF0 < -lbl_3_data_218BC[6]) {
            g_Minigame._1AF0 = 0.0f;
            g_Minigame._1AE4 = 0.0f;
            fn_8004C094((Vec*)&g_Minigame._1AE0);
            fn_3_90064(0x2DF);
            fn_3_13E174(0);
            for (i = 0; i < 4; i++) {
                fn_3_6C854(i, 1);
            }
        } else if (g_Minigame._1AE4 > 0.0f) {
            g_Minigame._1AF0 -= lbl_3_data_218BC[6];
        }
        if (g_Minigame._1AFA >= lbl_3_data_21904[9]) {
            g_Minigame._1B19 = 2;
            g_Minigame._1AFA = 0;
            g_Minigame._1AF0 = lbl_3_data_218BC[4];
        }
    }
}

// .text:0x00140284 size:0x200 mapped:0x8077F318
void fn_3_140284(void) {
    s32 i;
    int best;
    int winner;
    int threshold;

    g_Minigame._1E00 = 1;
    for (i = 0; i < 4; i++) {
        g_Minigame._1B2F[i] = 0xFF;
    }
    g_Minigame._1B33 = 0;
    best = 0;
    winner = -1;
    if (g_Minigame.multiPlayerInd) {
        threshold = lbl_3_data_218AC[4][g_Minigame._1A3A];
    } else {
        threshold = lbl_3_data_218AC[g_Minigame.soloMinigameDifficulty][g_Minigame._1A3A];
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame._1900[i] >= 0 && g_Minigame._1AFE[i] > best) {
            best = g_Minigame._1AFE[i];
            winner = i;
        }
    }
    if (winner >= 0 && best * 100 / 60 <= threshold) {
        winner = -1;
    }
    if (winner < 0) {
        g_Minigame._1B19 = 0;
        g_Minigame._1AFA = 0;
        return;
    }
    g_Minigame._1B2F[winner] = 1;
    g_Minigame._1B33 = 1;
    for (i = winner + 1; i < 4; i++) {
        if (g_Minigame._1900[i] >= 0 && g_Minigame._1AFE[winner] == g_Minigame._1AFE[i]) {
            g_Minigame._1B2F[i] = 1;
            g_Minigame._1B33++;
        }
    }
    g_Minigame._1AFC = 0;
    g_Minigame._1B19 = 3;
    g_Minigame._1AFA = 0;
}

// .text:0x0013FC24 size:0x660 mapped:0x8077ECB8
void fn_3_13FC24(void) {
    InMemRunnerType* runner;
    int i;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 vy;

    if (g_Minigame._1AFC < 1) {
        for (i = 0; i < 4; i++) {
            if (g_Minigame._1B2F[i] == 1) {
                runner = &g_Runners[g_Minigame._1900[i]];
                dx = runner->position.x - runner->positionStored.x;
                dz = runner->position.z - runner->positionStored.z;
                if (fabsf(dx) > 0.01 || fabsf(dz) > 0.01) {
                    return;
                }
            }
        }
    }
    if (++g_Minigame._1AFC <= 1) {
        for (i = 0; i < 4; i++) {
            if (g_Minigame._1B2F[i] == 1) {
                g_Minigame._1B14 = i;
                g_Minigame._1B2F[i] = 0;
                break;
            }
        }
        runner = &g_Runners[g_Minigame._1900[i]];
        dx = runner->position.x - g_Minigame._1AE0;
        dz = runner->position.z - g_Minigame._1AE8;
        dist = dolsqrtf2(dx * dx + dz * dz);
        g_Minigame._1AF8 = fn_3_9FB8C(dx, dz);
        if (dist < lbl_3_data_218BC[0]) {
            g_Minigame._1AEC = dx;
            g_Minigame._1AF4 = dz;
            goto hit;
        }
        dist = lbl_3_data_218BC[1] / dist;
        g_Minigame._1AEC = dx * dist;
        g_Minigame._1AF4 = dz * dist;
    }
    runner = &g_Runners[g_Minigame._1900[g_Minigame._1B14]];
    g_Minigame._1AE0 += g_Minigame._1AEC;
    g_Minigame._1AE4 += g_Minigame._1AF0;
    g_Minigame._1AE8 += g_Minigame._1AF4;
    if (g_Minigame._1AE4 <= 0.0f) {
        g_Minigame._1AE4 = 0.0f;
        g_Minigame._1AF0 = lbl_3_data_218BC[4];
        fn_8004C094((Vec*)&g_Minigame._1AE0);
        fn_3_90064(0x2DF);
    } else {
        vy = g_Minigame._1AF0;
        g_Minigame._1AF0 -= lbl_3_data_218BC[6];
        if (vy > 0.0f && g_Minigame._1AF0 <= 0.0f) {
            fn_3_90064(0x2DE);
        }
    }
    dz = runner->position.z - g_Minigame._1AE8;
    dx = runner->position.x - g_Minigame._1AE0;
    if (dolsqrtf2(dx * dx + dz * dz) < lbl_3_data_218BC[0]) {
    hit:
        fn_3_13E174(1);
        g_Minigame._1B15[g_Minigame._1B14] = 1;
        fn_3_7D9DC(g_Minigame._1900[g_Minigame._1B14]);
        fn_3_13E7D4(g_Minigame._1B14);
        if (g_Minigame.playerIDWithPowerup[0] == g_Minigame._1B14) {
            fn_800115C8(g_Minigame.playerIDWithPowerup[0]);
            g_Minigame.playerIDWithPowerup[0] = -1;
        }
        g_Minigame.miniGameCurrentPoints[g_Minigame._1B14] /= 2;
        g_Minigame._1DFC[g_Minigame._1B14] = 1;
        fn_3_6C854(g_Minigame._1B14, 2);
        if (--g_Minigame._1B33 == 0) {
            g_Minigame._1B19 = 4;
            g_Minigame._1AFA = 0;
            g_Minigame._1B14 = -1;
            g_Minigame._1AF0 = lbl_3_data_218BC[5];
        } else {
            g_Minigame._1AFC = 0;
        }
    }
}

// .text:0x0013F8C4 size:0x360 mapped:0x8077E958
void fn_3_13F8C4(void) {
    f32 dx;
    f32 dz;
    f32 dist;

    if (g_Minigame._1AFA <= 1) {
        dz = lbl_3_data_217F8[2] - g_Minigame._1AE8;
        dx = lbl_3_data_217F8[0] - g_Minigame._1AE0;
        dist = dolsqrtf2(dx * dx + dz * dz);
        dist = lbl_3_data_218BC[2] / dist;
        g_Minigame._1AEC = dx * dist;
        g_Minigame._1AF4 = dz * dist;
        g_Minigame._1AF8 = fn_3_9FB8C(dx, dz);
    }
    dz = lbl_3_data_217F8[2] - g_Minigame._1AE8;
    dx = lbl_3_data_217F8[0] - g_Minigame._1AE0;
    if (dolsqrtf2(dx * dx + dz * dz) <= lbl_3_data_218BC[2]) {
        g_Minigame._1AE0 = lbl_3_data_217F8[0];
        g_Minigame._1AE4 = lbl_3_data_217F8[1];
        g_Minigame._1AE8 = lbl_3_data_217F8[2];
        g_Minigame._1B19 = 0;
        g_Minigame._1AFA = 0;
    } else {
        g_Minigame._1AE0 += g_Minigame._1AEC;
        g_Minigame._1AE4 += g_Minigame._1AF0;
        g_Minigame._1AE8 += g_Minigame._1AF4;
        if (g_Minigame._1AE4 <= 0.0f) {
            g_Minigame._1AE4 = 0.0f;
            g_Minigame._1AF0 = lbl_3_data_218BC[5];
            fn_8004C094((Vec*)&g_Minigame._1AE0);
            fn_3_90064(0x2DF);
        } else {
            g_Minigame._1AF0 -= lbl_3_data_218BC[6];
        }
    }
}

// .text:0x0013F7E4 size:0xE0 mapped:0x8077E878
void fn_3_13F7E4(void) {
    s32 i;

    if (g_Minigame._1B19 != 1) {
        return;
    }
    if (g_Minigame._1AFA <= 0) {
        g_Minigame._1AFE[0] = 0;
        g_Minigame._1AFE[1] = 0;
        g_Minigame._1AFE[2] = 0;
        g_Minigame._1AFE[3] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame._1900[i] >= 0 && (g_Runners[g_Minigame._1900[i]].runningDirectionCode == 1 ||
                                          g_Runners[g_Minigame._1900[i]].runningDirectionCode == 3)) {
            g_Minigame._1AFE[i]++;
        }
    }
}

// .text:0x0013F6C8 size:0x11C mapped:0x8077E75C
void fn_3_13F6C8(void) {
    if (g_Minigame.turnOverStatus == 0) {
        fn_3_13F484();
        fn_3_13EA30();
        fn_3_13E6D4();
    }
}

// .text:0x0013F484 size:0x244 mapped:0x8077E518
void fn_3_13F484(void) {
    s32 i;
    s32 j;
    int id;
    int count;

    for (i = 0; i < 6; i++) {
        if (g_Minigame._1B1A[i] == 1) {
            g_Minigame._1B08[i]--;
            if (g_Minigame._1B08[i] <= 0) {
                g_Minigame._1B1A[i] = 0;
            }
        } else if (g_Minigame._1B1A[i] == 0) {
            fn_3_13EC44(i);
        } else {
            id = i + 101;
            count = 0;
            for (j = 0; j < 15; j++) {
                if (g_Minigame.wallBall_coinsVisibleInd[j] == id) {
                    count++;
                }
            }
            if (count >= lbl_3_data_21884[g_Minigame._1B1A[i] - 2][0]) {
                for (j = 0; j < 15; j++) {
                    if (g_Minigame.wallBall_coinsVisibleInd[j] == id) {
                        g_Minigame.wallBall_coinsVisibleInd[j] = 0;
                    }
                }
                g_Minigame._1B1A[i] = 1;
                for (j = 0; j < 4; j++) {
                    if (g_Minigame._1B26[j][0] == i) {
                        g_Minigame._1B26[j][0] = -1;
                        break;
                    }
                    if (g_Minigame._1B26[j][1] == i) {
                        g_Minigame._1B26[j][1] = -1;
                        break;
                    }
                }
                g_Minigame._1B08[i] = RandomInt_Game_Range(lbl_3_data_21904[3], lbl_3_data_21904[4]);
            }
        }
    }
}

// .text:0x0013EC44 size:0x840 mapped:0x8077DCD8
void fn_3_13EC44(int slot) {
    int occupied[4];
    int free[4];
    int chomped[4];
    int i;
    int j;
    int n;
    int count;
    int pick;
    int base;
    s8 chomp;

    for (i = 0; i < 6; i++) {
        if (g_Minigame._1B1A[i] == 3) {
            break;
        }
    }
    if (g_Minigame._1B2E < 2 && g_Minigame._17C0 > g_Minigame._18A2[g_Minigame._1B2E]) {
        g_Minigame._1B1A[slot] = 4;
        count = lbl_3_data_21884[2][0];
        g_Minigame._1B2E++;
    } else if (i < 6) {
        g_Minigame._1B1A[slot] = 2;
        count = lbl_3_data_21884[0][0];
    } else {
        if (g_Minigame._17C0 < 1800) {
            j = 0;
        } else if (g_Minigame._17C0 < 3600) {
            j = 1;
        } else {
            j = 2;
        }
        j = RandomIndexFromWeights(lbl_3_data_2187C[j], 2);
        g_Minigame._1B1A[slot] = j + 2;
        count = lbl_3_data_21884[j][0];
    }

    for (;;) {
        n = 0;
        if (g_Minigame._1B1A[slot] == 4) {
            for (j = 0; j < 4; j++) {
                occupied[j] = 0;
                chomped[j] = 0;
            }
            for (j = 0; j < 4; j++) {
                if (g_Minigame._18FC[j] >= 0) {
                    if (g_Runners[j].runningDirectionCode == 1) {
                        occupied[g_Runners[j].nextBase & 3]++;
                    } else if (g_Runners[j].runningDirectionCode == 3) {
                        occupied[g_Runners[j].currentBase]++;
                    } else if (g_Runners[j].percentTowardsNextBase < 0.5f) {
                        occupied[g_Runners[j].currentBase]++;
                    } else {
                        occupied[g_Runners[j].currentBase]++;
                    }
                }
            }
            if (g_Minigame._CCE[0]) {
                chomp = g_Minigame._CC8;
                occupied[chomp]++;
                chomped[chomp]++;
            }
            for (j = 0, n = 0; j < 4; j++) {
                if (occupied[j] == 0) {
                    free[n] = j;
                    n++;
                }
            }
            if (n != 0) {
                base = free[random_fn_3_9EE24(n)] * 10;
                break;
            }
            for (j = 0, n = 0; j < 4; j++) {
                if (chomped[j] == 0) {
                    free[n] = j;
                    n++;
                }
            }
            base = free[random_fn_3_9EE24(n)] * 10;
            break;
        }
        for (j = 0; j < 4; j++) {
            occupied[j] = 0;
            free[j] = -1;
            if (g_Minigame._1B26[j][1] >= 0) {
                occupied[j] = 2;
            } else if (g_Minigame._1B26[j][0] >= 0) {
                if (g_Minigame._1B1A[g_Minigame._1B26[j][0]] == 3) {
                    occupied[j] = 5;
                } else {
                    occupied[j] = 1;
                    if (g_Minigame._1B1A[slot] != 3) {
                        free[n] = j;
                        n++;
                    }
                }
            } else {
                free[n] = j;
                n++;
            }
        }
        if (g_Minigame._1B1A[slot] == 3) {
            if (n == 0) {
                count = lbl_3_data_21884[0][0];
                g_Minigame._1B1A[slot] = 2;
                continue;
            }
            pick = free[random_fn_3_9EE24(n)];
            base = random_fn_3_9EE24(6) + pick * 10;
            base += 2;
            break;
        }
        pick = free[random_fn_3_9EE24(n)];
        if (occupied[pick] == 0) {
            base = random_fn_3_9EE24(8) + pick * 10;
            base += 1;
            break;
        }
        base = pick * 10;
        pick = g_Minigame._1B20[g_Minigame._1B26[pick][0]] % 10;
        n = random_fn_3_9EE24(8) + 1;
        for (j = 0; j < 10; j++) {
            if (pick != j) {
                if (n == 0) {
                    base += j;
                    break;
                }
                n--;
            }
        }
        break;
    }

    if (g_Minigame._1B26[base / 10][0] < 0) {
        g_Minigame._1B26[base / 10][0] = slot;
    } else {
        g_Minigame._1B26[base / 10][1] = slot;
    }
    g_Minigame._1B20[slot] = base;
    base *= 10;
    pick = 0;
    for (i = 0; i < count; i++) {
        for (; pick < 15; pick++) {
            if (g_Minigame.wallBall_coinsVisibleInd[pick] == 0) {
                g_Minigame.wallBall_coinsVisibleInd[pick] = slot + 1;
                g_Minigame._1630[pick] = base / 100.0f;
                g_Minigame.wallBall_coinsVisibleFrameCounter[pick] = 0;
                fn_3_7FED4(&g_Minigame.wallBall_coinCoordinates[pick], g_Minigame._1630[pick], base % 100 / 100.0f);
                fn_3_1541C4(pick, g_Minigame._1B1A[slot], &g_Minigame.wallBall_coinCoordinates[pick]);
                break;
            }
        }
        base += 5;
    }
    if (g_Minigame._1B1A[slot] == 4) {
        fn_3_106EB0();
    }
}

// .text:0x0013EA30 size:0x214 mapped:0x8077DAC4
void fn_3_13EA30(void) {
    int candidates[4];
    int i;
    int kind;
    int j;
    int n;
    int player;
    f32 dist;

    for (i = 0; i < 15; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] >= 1 && g_Minigame.wallBall_coinsVisibleInd[i] <= 6) {
            kind = g_Minigame._1B1A[g_Minigame.wallBall_coinsVisibleInd[i] - 1] - 2;
            n = 0;
            for (j = 0; j < 4; j++) {
                candidates[j] = 0;
                if (g_Minigame._18FC[j] >= 0) {
                    dist = g_Minigame._1630[i] - g_Runners[j].fractionalBasesRan;
                    if (dist < 0.0f) {
                        dist += 4.0f;
                    }
                    if (dist > 2.0f) {
                        dist = 4.0f - dist;
                    }
                    if (dist <= lbl_3_data_218BC[kind + 8]) {
                        candidates[n] = j;
                        n++;
                    }
                }
            }
            if (n != 0) {
                player = candidates[RandomInt_Game(n)];
                g_Minigame.miniGameCurrentPoints[g_Minigame._18FC[player]] += lbl_3_data_21884[kind][1];
                g_Minigame.wallBall_coinsVisibleInd[i] += 100;
                fn_3_152AB4(i, player);
                if (kind == 2) {
                    fn_3_90064(0x2EA);
                    fn_3_90220(g_Runners[player].charID, 0);
                } else {
                    fn_3_90064(0x2DD);
                }
                if (!g_d_GameSettings.exhibitionMatchInd && player == lbl_3_common_bss_37400._40) {
                    fn_3_1608F0(3, kind, 0);
                }
            }
        }
    }
}

// .text:0x0013E7D4 size:0x25C mapped:0x8077D868
void fn_3_13E7D4(int player) {
    Vec dir;
    InMemRunnerType* runner = &g_Runners[g_Minigame._1900[player]];
    int count = g_Minigame.miniGameCurrentPoints[player] / 2;
    u32 i;
    f32 angle;
    f32 speed;
    f32 height;

    if (count == 0) {
        return;
    }
    if (count > 5) {
        count = 5;
    }
    for (i = 15; i < 35; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] != 1) {
            g_Minigame.wallBall_coinsVisibleInd[i] = 1;
            g_Minigame.wallBall_coinCoordinates[i].x = runner->position.x;
            g_Minigame.wallBall_coinCoordinates[i].y = runner->position.y;
            g_Minigame.wallBall_coinCoordinates[i].z = runner->position.z;
            memcpy(&dir, &runner->velocity, sizeof(Vec));
            dir.y = 0.0f;
            if (!PSVECMag(&dir)) {
                dir.z = 1.0f;
            }
            PSVECNormalize(&dir, &dir);
            angle = 0.017453292f * (f32)(45.0 * (2.0 * (rand() / 32767.0f - 0.5)));
            dir.x = dir.x * cosf_kludge(angle) + -dir.z * sinf_kludge(angle);
            dir.z = dir.x * sinf_kludge(angle) + dir.z * cosf_kludge(angle);
            speed = RandomF32_Game_Range(lbl_3_data_2188C[2], lbl_3_data_2188C[3]);
            height = RandomF32_Game_Range(lbl_3_data_2188C[0], lbl_3_data_2188C[1]);
            g_Minigame.wallBall_coinVelocity[i].x = speed * dir.x;
            g_Minigame.wallBall_coinVelocity[i].y = height;
            g_Minigame.wallBall_coinVelocity[i].z = speed * dir.z;
            g_Minigame.wallBall_coinsVisibleFrameCounter[i] = 0;
            if (--count == 0) {
                return;
            }
        }
    }
}

// .text:0x0013E6D4 size:0x100 mapped:0x8077D768
void fn_3_13E6D4(void) {
    u32 i;

    for (i = 15; i < 35; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd) {
            PSVECAdd((Vec*)&g_Minigame.wallBall_coinCoordinates[i], (Vec*)&g_Minigame.wallBall_coinVelocity[i], (Vec*)&g_Minigame.wallBall_coinCoordinates[i]);
            g_Minigame.wallBall_coinVelocity[i].y += lbl_3_data_2188C[4];
            if (g_Minigame.wallBall_coinCoordinates[i].y < 0.01) {
                g_Minigame.wallBall_coinCoordinates[i].y = 0.01f;
                g_Minigame.wallBall_coinVelocity[i].x *= lbl_3_data_2188C[5];
                g_Minigame.wallBall_coinVelocity[i].z *= lbl_3_data_2188C[5];
                g_Minigame.wallBall_coinVelocity[i].y *= -lbl_3_data_2188C[6];
            }
            if (++g_Minigame.wallBall_coinsVisibleFrameCounter[i] >= lbl_3_data_218A8) {
                g_Minigame.wallBall_coinsVisibleInd[i] = 0;
            }
        }
    }
}

// .text:0x0013E670 size:0x64 mapped:0x8077D704
void fn_3_13E670(void) {
    if (g_Minigame.turnOverStatus) {
        g_Minigame.playerIDWithPowerup[0] = -1;
        g_Minigame._CCE[0] = 0;
    } else if (g_Minigame._CCE[0]) {
        fn_3_13E21C((Unk36D8Chomp*)&g_Minigame._CB0);
    } else {
        fn_3_13E3A4((Unk36D8Chomp*)&g_Minigame._CB0);
    }
}

// .text:0x0013E3A4 size:0x2CC mapped:0x8077D438
void fn_3_13E3A4(Unk36D8Chomp* chomp) {
    int targets[2];
    int* target;
    int last;
    int i;
    int base;
    int next;
    f32 pos;
    InMemRunnerType* runner;

    if (g_Minigame.playerIDWithPowerup[0] != -1) {
        if (g_Minigame._1B19 != 2 && g_Minigame._1B19 != 3) {
            g_Minigame._1D58--;
        }
        if (g_Minigame._1D58 <= 0) {
            fn_800115C8(g_Minigame.playerIDWithPowerup[0]);
            g_Minigame.playerIDWithPowerup[0] = -1;
        }
    } else {
        chomp->_1C--;
        if (chomp->_1C <= 0) {
            chomp->_1E = 1;
            last = 0;
            for (i = 1; i < 4; i++) {
                if (g_Minigame.miniGameCurrentPoints[last] > g_Minigame.miniGameCurrentPoints[i]) {
                    last = i;
                }
            }
            runner = &g_Runners[last];
            pos = runner->fractionalBasesRan;
            base = (int)pos * 10;
            next = base + 10;
            if (next >= 40) {
                next = 0;
            }
            if ((int)(100.0f * pos) % 100 < 0.5f) {
                targets[0] = base;
                targets[1] = next;
            } else {
                targets[0] = next;
                targets[1] = base;
            }
            target = &targets[0];
            for (i = 0; i < 15; i++) {
                if (g_Minigame._1B20[i] == targets[0]) {
                    target = &targets[1];
                    break;
                }
            }
            chomp->_18 = *target / 10.0f;
            fn_3_7FED4(chomp, chomp->_18, 0.0f);
            memset(&chomp->_0C, 0, sizeof(Vec));
            chomp->_1C = lbl_3_data_21924[1];
        }
    }
}

// .text:0x0013E21C size:0x188 mapped:0x8077D2B0
void fn_3_13E21C(Unk36D8Chomp* chomp) {
    int candidates[4];
    int n;
    int i;
    int player;
    f32 dist;

    n = 0;
    for (i = 0; i < 4; i++) {
        candidates[i] = 0;
        if (g_Minigame._18FC[i] >= 0) {
            dist = chomp->_18 - g_Runners[i].fractionalBasesRan;
            if (dist < 0.0f) {
                dist += 4.0f;
            }
            if (dist > 2.0f) {
                dist = 4.0f - dist;
            }
            if (dist <= lbl_3_data_218BC[11]) {
                candidates[n] = i;
                n++;
            }
        }
    }
    if (n != 0) {
        player = candidates[RandomInt_Game(n)];
        g_Minigame.playerIDWithPowerup[0] = player;
        g_Minigame._1D58 = lbl_3_data_21924[2];
        chomp->_1E = 0;
        chomp->_1C = lbl_3_data_21924[0];
        fn_3_90064(0x2F6);
        fn_3_16C394(player);
    } else {
        if (g_Minigame._1B19 != 2 && g_Minigame._1B19 != 3) {
            chomp->_1C--;
        }
        if (chomp->_1C <= 0) {
            chomp->_1E = 0;
            chomp->_1C = lbl_3_data_21924[0];
        }
    }
}

// .text:0x0013E174 size:0xA8 mapped:0x8077D208
void fn_3_13E174(u8 strength) {
    switch (strength) {
    case 0:
        lbl_3_bss_B798 = lbl_3_data_218BC[12];
        lbl_3_bss_B794 = lbl_3_data_218BC[14];
        break;
    case 1:
        lbl_3_bss_B798 = lbl_3_data_218BC[13];
        lbl_3_bss_B794 = lbl_3_data_218BC[15];
        break;
    default:
        return;
    }
    fn_800528AC(fn_3_13DFBC);
}

// .text:0x0013DFBC size:0x1B8 mapped:0x8077D050
void fn_3_13DFBC(camera_803c639c_s* camera) {
    Mtx inv;
    Vec offset;
    int range = 1000.0f * lbl_3_bss_B794;

    offset.x = (rand() % range - range / 2) / 1000.0;
    offset.y = (rand() % range - range / 2) / 1000.0;
    offset.z = 0.0f;
    PSMTXInverse(camera->view, inv);
    PSMTXMultVecSR(inv, &offset, &offset);
    VEC_ADD(&camera->eye, &camera->eye, &offset);
    VEC_ADD(&camera->target, &camera->target, &offset);
    if (--lbl_3_bss_B798 <= 0) {
        lbl_3_bss_B798 = 0;
        lbl_3_bss_B794 = 0.0f;
        fn_800528B4();
    }
}

// .text:0x0013DEA4 size:0x118 mapped:0x8077CF38
void fn_3_13DEA4(void) {
    Unk36D8Cpu* cpus = (Unk36D8Cpu*)&g_Minigame._1DCC;
    Unk36D8Cpu* cpu;
    s8 i;
    u8 strength;

    memset(g_Minigame._1D7C, 0, 0x78);
    i = 0;
    do {
        cpu = &cpus[i];
        strength = g_Minigame.minigameControlStruct.aIStrength[i];
        cpu->_0 = RandomInt_Game_Range(lbl_3_data_2194C[strength][0], lbl_3_data_2194C[strength][1]);
        if (RandomInt_Game(100) < lbl_3_data_2197C[strength]) {
            if (lbl_3_data_21980[strength] < 8) {
                cpu->_6 = RandomInt_Game_Range(lbl_3_data_21980[strength], 8);
            } else {
                cpu->_6 = 8;
            }
        } else {
            cpu->_6 = 0x7F;
        }
        cpu->_5 = 2;
        cpu->_7 = RandomInt_Game_Range(lbl_3_data_21944[strength][0], lbl_3_data_21944[strength][1]);
    } while (++i < 4);
}

// .text:0x0013DDE0 size:0xC4 mapped:0x8077CE74
f32 fn_3_13DDE0(u8 dir, f32 from, f32 to) {
    if (from < 0.0f) {
        from += 4.0f;
    } else if (from >= 4.0f) {
        from -= 4.0f;
    }
    if (to < 0.0f) {
        to += 4.0f;
    } else if (to >= 4.0f) {
        to -= 4.0f;
    }
    if (dir == 1) {
        if (from > to) {
            return 4.0f + to - from;
        }
        return to - from;
    }
    if (from < to) {
        return 4.0f + from - to;
    }
    return from - to;
}

// .text:0x0013DC48 size:0x198 mapped:0x8077CCDC
void fn_3_13DC48(s8 runner, f32 target, f32* forward, f32* backward) {
    *forward = fn_3_13DDE0(1, g_Runners[runner].fractionalBasesRan, target);
    if (g_Runners[runner].runningDirectionCode == 3) {
        *forward += 0.15f;
    }
    *backward = fn_3_13DDE0(3, g_Runners[runner].fractionalBasesRan, target);
    if (g_Runners[runner].runningDirectionCode == 1) {
        *backward += 0.15f;
    }
}

// .text:0x0013DA50 size:0x1F8 mapped:0x8077CAE4
f32 fn_3_13DA50(s8 runner, f32 target, u8* dir) {
    f32 forward;
    f32 backward;

    forward = fn_3_13DDE0(1, g_Runners[runner].fractionalBasesRan, target);
    if (g_Runners[runner].runningDirectionCode == 3) {
        forward += 0.15f;
    }
    backward = fn_3_13DDE0(3, g_Runners[runner].fractionalBasesRan, target);
    if (g_Runners[runner].runningDirectionCode == 1) {
        backward += 0.15f;
    }
    if (forward < backward) {
        *dir = 1;
        return forward;
    }
    if (forward > backward) {
        *dir = 3;
        return backward;
    }
    *dir = RandomInt_Game(2) ? 1 : 3;
    return forward;
}

// .text:0x0013DA20 size:0x30 mapped:0x8077CAB4
int fn_3_13DA20(const void* a, const void* b) {
    return 100.0f * *(f32*)a - 100.0f * *(f32*)b;
}

// .text:0x0013D618 size:0x408 mapped:0x8077C6AC
void fn_3_13D618(void) {
    return;
}

// .text:0x0013D5E8 size:0x30 mapped:0x8077C67C
int fn_3_13D5E8(const void* a, const void* b) {
    return 100.0f * *(f32*)a - 100.0f * *(f32*)b;
}

// .text:0x0013D578 size:0x70 mapped:0x8077C60C
BOOL fn_3_13D578(s8 player) {
    s8 i = 0;

    do {
        if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0 && g_Minigame.minigameControlStruct.characterIndex[i] < 4 &&
            g_Minigame.miniGameCurrentPoints[i] > g_Minigame.miniGameCurrentPoints[player]) {
            return TRUE;
        }
    } while (++i < 4);
    return FALSE;
}

// .text:0x0013C7BC size:0xDBC mapped:0x8077B850
void fn_3_13C7BC(void) {
    return;
}
