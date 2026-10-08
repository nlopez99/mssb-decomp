#include "game/rep_37A8.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "game/rep_28A8.h"
#include "game/rep_31A0.h"
#include "game/rep_3310.h"
#include "game/rep_3880.h"
#include "game/m_sound.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_D18.h"
#include "Dolphin/gx.h"
#include "string.h"
#include "musyx/musyx.h"

// g_Minigame's three entries in this minigame
typedef struct UnkMgEntry3310 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec rot;
    /* 0x18 */ s16 _18;
    /* 0x1A */ s16 _1A;
    /* 0x1C */ s16 _1C;
    /* 0x1E */ s16 _1E;
    /* 0x20 */ s16 _20;
    /* 0x22 */ s16 _22;
    /* 0x24 */ s16 _24;
    /* 0x26 */ s16 _26;
    /* 0x28 */ s16 _28;
    /* 0x2A */ u8 _2A;
    /* 0x2B */ u8 _2B;
    /* 0x2C */ u8 _2C;
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E;
    /* 0x2F */ s8 _2F[4];
    /* 0x33 */ u8 _33;
    /* 0x34 */ s8 _34;
    /* 0x35 */ s8 _35;
    /* 0x36 */ u8 _36[0x38 - 0x36];
} UnkMgEntry3310; // size: 0x38

// A piranha, 40 of them at g_Minigame._A8
typedef struct Unk37A8Piranha {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec vel;
    /* 0x18 */ f32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s16 _20;
    /* 0x22 */ s16 _22;
    /* 0x24 */ u8 _24[0x26 - 0x24];
    /* 0x26 */ u8 active;
    /* 0x27 */ u8 _27;
} Unk37A8Piranha; // size: 0x28

// A CPU player's state, one per player at g_Minigame._1DCC
typedef struct Unk37A8Cpu {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s8 _2;
    /* 0x3 */ s8 _3;
} Unk37A8Cpu; // size: 0x4

// This minigame's view of g_Minigame
typedef struct Unk37A8Minigame {
    /* 0x0000 */ UnkMgEntry3310 _0000[3];
    /* 0x00A8 */ Unk37A8Piranha _00A8[40];
    /* 0x06E8 */ u8 _06E8[0x17C8 - 0x6E8];
    /* 0x17C8 */ s16 _17C8[50];
    /* 0x182C */ u8 _182C[0x193A - 0x182C];
    /* 0x193A */ u8 _193A[100];
    /* 0x199E */ u8 _199E[0x1B34 - 0x199E];
    /* 0x1B34 */ s16 _1B34[4];
    /* 0x1B3C */ s16 _1B3C[4];
    /* 0x1B44 */ s16 _1B44[4];
    /* 0x1B4C */ u8 _1B4C[0x1B50 - 0x1B4C];
    /* 0x1B50 */ s16 _1B50[4];
    /* 0x1B58 */ u8 _1B58[4][10];
    /* 0x1B80 */ u8 _1B80[4];
    /* 0x1B84 */ u8 _1B84[50];
    /* 0x1BB6 */ s8 _1BB6[50];
    /* 0x1BE8 */ s8 _1BE8[50];
    /* 0x1C1A */ u8 _1C1A[50];
    /* 0x1C4C */ u8 _1C4C[50];
    /* 0x1C7E */ s8 _1C7E[4][3];
    /* 0x1C8A */ u8 _1C8A[4];
    /* 0x1C8E */ u8 _1C8E[0x1C9A - 0x1C8E];
    /* 0x1C9A */ u8 _1C9A[4];
    /* 0x1C9E */ u8 _1C9E[4];
    /* 0x1CA2 */ u8 _1CA2[0x1CA9 - 0x1CA2];
    /* 0x1CA9 */ u8 _1CA9[4];
    /* 0x1CAD */ u8 _1CAD[0x1DCC - 0x1CAD];
    /* 0x1DCC */ Unk37A8Cpu _1DCC[4];
} Unk37A8Minigame;

#define MG (*(Unk37A8Minigame*)&g_Minigame)

typedef struct Unk37A8Fielder {
    /* 0x000 */ Vec pos;
    /* 0x00C */ f32 _00C;
    /* 0x010 */ u8 _010[0x38 - 0x10];
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x48 - 0x40];
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x50 - 0x4C];
    /* 0x050 */ f32 _050;
    /* 0x054 */ u8 _054[0x10C - 0x54];
    /* 0x10C */ f32 _10C;
    /* 0x110 */ f32 _110;
    /* 0x114 */ f32 _114;
    /* 0x118 */ u8 _118[0x17A - 0x118];
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x1C7 - 0x17C];
    /* 0x1C7 */ u8 _1C7;
    /* 0x1C8 */ u8 _1C8;
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA[0x1CE - 0x1CA];
    /* 0x1CE */ u8 _1CE;
    /* 0x1CF */ u8 _1CF[0x1D2 - 0x1CF];
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3[0x20D - 0x1D3];
    /* 0x20D */ u8 _20D;
    /* 0x20E */ u8 _20E[0x268 - 0x20E];
} Unk37A8Fielder; // size: 0x268

extern Unk37A8Fielder g_Fielders[9];

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern void fn_800B993C(void);
extern void fn_800B9948(void* callback);
extern void pitchingMachinePitching(u8 id);
extern void changeScene(u8, s16);
extern u8 lbl_800EFBA4[0x10];
extern s16 lbl_3_data_7F10[54];
extern Vec lbl_3_data_21B94[4];
extern Vec lbl_3_data_21BC4[3][4];

extern u8 lbl_3_data_21278[2];
extern f32 lbl_3_data_21D34[4][3][3];
extern s16 lbl_3_data_21DC4[2];
extern f32 lbl_3_data_21D1C[4];
extern f32 lbl_3_data_21D2C[2];
extern s16 lbl_3_data_21DC8[5][2][3];
extern s16 lbl_3_data_21E04[2];
extern u8 lbl_3_data_21E10[8];
extern s16 lbl_3_data_21E68[26];
extern s16 lbl_3_data_21EAC[4][2];
extern s8 lbl_3_data_21EBC[4];
extern f32 lbl_3_data_21E24[17];
extern u8 lbl_3_data_21E9C[4][4];
extern u8 lbl_3_data_21E1C[2];
extern u8 lbl_3_data_2127C[8][5];
extern u8 lbl_3_data_21E08[8];
extern struct {
    /* 0x0 */ s32 _0;
} g_Scores;
extern void minigamesSetSomePointers(void);
extern void minigamesGXStuff(void);
extern void minigamesSetSomePointers2(void);
extern void fn_3_59A90(void);
extern void fn_3_591AC(void);
extern void fn_3_58870(void);
extern void fn_3_6E24C(int rosterID, int fielderIdx);
extern void fn_3_1608F0(int, int, int);
extern void fn_80062BE4(Vec* pos);
extern u8 lbl_3_data_21E18[2][2];
extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;
extern int LERPToNewRange_Float(int value, int inMin, int inMax, int outMin, int outMax);
extern f32 lbl_3_data_47BC[5];
extern s8 lbl_3_data_21EC0[4];

f32 lbl_3_data_26698[3] = { 0.5f, 0.0f, -0.5f };
s8 lbl_3_data_266A4 = -1;

// .bss statics, declared in reverse address order (MWCC lays them out last to first)
static u8 lbl_3_bss_B840[0x10];
static u8 lbl_3_bss_B800[0x40] ATTRIBUTE_ALIGN(32);
static s32 lbl_3_bss_B7E4;
static GXTexObj lbl_3_bss_B7C4;
static u8 lbl_3_bss_B7C1;
static u8 lbl_3_bss_B7C0;

static inline u8* GetTexel(s32 x, s32 y, s32 width) {
    return &lbl_3_bss_B800[fn_3_142030(x, y, width)];
}

// .text:0x00147358 size:0x24 mapped:0x807863EC
void fn_3_147358(void) {
    pitchingMachinePitching(0x26);
}

// .text:0x001471C4 size:0x194 mapped:0x80786258
void fn_3_1471C4(void) {
    return;
}

// .text:0x001471C0 size:0x4 mapped:0x80786254
void fn_3_1471C0(void) {
    return;
}

// .text:0x00146A90 size:0x730 mapped:0x80785B24
void fn_3_146A90(void) {
    Unk37A8Fielder* fielder;
    s32 i;
    s32 j;
    s32 n;
    u8 strength;

    if (g_GameLogic._125 == 0) {
        fn_3_59A90();
        g_Minigame._17C0 = 0;
        g_Minigame.turnOverStatus = 0;
        g_GameLogic.secondaryGameMode = 7;
        g_Minigame._1A37 = 0;
        for (i = 0; i < 4; i++) {
            g_Minigame.miniGameCurrentPoints[i] = 0;
            g_Minigame.miniGameLatestPoints[i] = 0;
            g_Minigame.minigamePoints_current_Latest[i][0] = 0;
            g_Minigame.minigamePoints_current_Latest[i][1] = 0;
            g_Minigame.minigameControlStruct._28[i] = -1;
            g_Minigame.minigameFielderIndex[i] = -1;
            g_Minigame._18FC[i] = -1;
            g_Minigame._1900[i] = -1;
            g_Minigame.minigameControlStruct._24[i] = 0;
        }
        g_Scores._0 = 0;
        g_Minigame.pointsReqToWin_challenge = 0;
        g_Minigame.turnNumberWithinRound = 0;
        g_Minigame.minigamePlayerSelectedOrder = -1;
        g_Minigame.rosterID = -1;
        g_Minigame._17C0 = 0;
        if (!g_Minigame.multiPlayerInd) {
            g_Minigame._17C4 = lbl_3_data_21E08[g_Minigame.soloMinigameDifficulty] * 60;
            strength = lbl_3_data_2127C[g_Minigame.GameMode_MiniGame][g_Minigame.soloMinigameDifficulty];
            for (i = 0; i < 4; i++) {
                g_Minigame.minigameControlStruct.aIStrength[i] = strength;
            }
        } else {
            if (g_Minigame._1A3C) {
                for (i = 0; i < 4; i++) {
                    g_Minigame.minigameControlStruct.aIStrength[i] = lbl_3_data_2127C[7][0];
                }
            }
            g_Minigame._17C4 = lbl_3_data_21E08[4] * 60;
        }
        fn_3_591AC();
        fn_3_58870();
        n = 0;
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                g_Minigame.minigameControlStruct._28[n] = i;
                g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]] = n + 2;
                fn_3_6E24C(i, g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]);
                MG._1C7E[i][0] = -1;
                MG._1C7E[i][1] = -1;
                MG._1C7E[i][2] = -1;
                fielder = &g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]];
                g_Minigame._1C8A[i] = 0;
                fielder->_20D = i;
                fielder->pos.x = lbl_3_data_21B94[n].x;
                MG._1B34[i] = -1;
                g_Minigame._1C92[i] = -1;
                fielder->pos.y = lbl_3_data_21B94[n].y;
                MG._1C9A[i] = 0;
                fielder->pos.z = lbl_3_data_21B94[n].z;
                MG._1B50[i] = 0;
                fielder->_00C = lbl_3_data_21D2C[1];
                MG._1B80[i] = 0;
                fielder->_1D2 = 0;
                g_Minigame._1CA5[i] = 0;
                fielder->_050 = 0.0f;
                g_Minigame._1CAD[i] = i;
                fielder->_048 = 1.5707964f;
                g_Minigame._1CB1[i] = 0;
                for (j = 0; j < 10; j++) {
                    MG._1B58[i][j] = 0;
                }
                MG._1C9E[i] = 0;
                n++;
            }
        }
        for (i = 0; i < 100; i++) {
            MG._193A[i] = 0;
            MG._1BB6[i] = -1;
        }
        g_Minigame._1B4C = 60;
        fn_3_145B98();
        for (i = 0; i < 3; i++) {
            MG._0000[i]._2A = 0;
            MG._0000[i]._2B = 0;
            MG._0000[i]._2E = 0;
            MG._0000[i]._1A = 0;
            MG._0000[i]._1C = -1;
            MG._0000[i]._1E = 0;
            MG._0000[i]._20 = 0;
            MG._0000[i]._22 = 0;
            MG._0000[i]._33 = 0xFF;
            MG._0000[i].pos.x = lbl_3_data_21BC4[i][0].x;
            MG._0000[i].pos.y = lbl_3_data_21BC4[i][0].y;
            MG._0000[i].pos.z = lbl_3_data_21BC4[i][0].z;
            MG._0000[i]._2F[0] = -1;
            MG._0000[i]._2F[1] = -1;
            MG._0000[i]._2F[2] = -1;
            MG._0000[i]._2F[3] = -1;
        }
        for (i = 0; i < 4; i++) {
            MG._1CA9[i] = 0;
        }
        g_Minigame._1CA2 = 0;
        g_Minigame._1CA3 = 0;
        g_Minigame._1CA4 = 0;
        if (!g_Minigame.multiPlayerInd) {
            g_Minigame._1B4E = RandomInt_Game_Range(lbl_3_data_21DC8[g_Minigame.soloMinigameDifficulty][0][0],
                                                    lbl_3_data_21DC8[g_Minigame.soloMinigameDifficulty][0][1]) * 60;
        } else {
            g_Minigame._1B4E = RandomInt_Game_Range(lbl_3_data_21DC8[4][0][0], lbl_3_data_21DC8[4][0][1]) * 60;
        }
        minigamesSetSomePointers();
        minigamesGXStuff();
        minigamesSetSomePointers2();
        for (i = 0; i < 40; i++) {
            MG._00A8[i].active = 0;
        }
        fn_3_157588(40);
        g_GameLogic._125++;
    } else {
        fn_3_5A6D4(GAME_STATUS_GAME_START_MOVIE);
    }
    fn_3_142088();
}

// .text:0x001469CC size:0xC4 mapped:0x80785A60
void fn_3_1469CC(void) {
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

// .text:0x00146928 size:0xA4 mapped:0x807859BC
void fn_3_146928(void) {
    fn_3_142C18();
    changeScene(1, 6);
    fn_3_5A6D4(GAME_STATUS_LIVE_BALL);
}

// .text:0x00146408 size:0x520 mapped:0x8078549C
void fn_3_146408(void) {
    return;
}

// .text:0x001461A4 size:0x264 mapped:0x80785238
void fn_3_1461A4(void) {
    if (g_Minigame.turnOverStatus == 0) {
        if (g_Minigame._17C4 == 0) {
            g_Minigame.turnOverStatus = 1;
            fn_3_10F550(3, 0);
            sndFXStart(0x1BE, lbl_800EFBA4[7], 0x3F);
        }
    } else {
        if (g_Minigame.turnOverStatus == 1) {
            g_Minigame.turnOverStatus = 2;
            g_GameLogic.CountdownUntilFade = lbl_3_data_21E68[17];
        }
        if (--g_GameLogic.CountdownUntilFade == 7) {
            changeScene(3, 6);
        }
        if (g_GameLogic.CountdownUntilFade <= 0) {
            fn_3_145FF4();
        }
    }
}

// .text:0x00145FF4 size:0x1B0 mapped:0x80785088
void fn_3_145FF4(void) {
    u32 i;

    fn_3_157570();
    fn_3_DE4FC();
    if (g_Minigame.soloMinigameDifficulty <= MINIGAME_DIFFICULTY_MULTIPLAYER_CHALLENGE_HARD && !g_Minigame.multiPlayerInd) {
        if (g_Minigame.minigameControlStruct._1C[g_Minigame._1908] == 1 && !g_Minigame.challenge_minigame_haven_tWonYetIndicator) {
            g_Minigame._1A37 = 1;
        } else {
            g_Minigame._1A37 = 2;
        }
    }
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    for (i = 0; i < 50; i++) {
        MG._193A[i] = 0;
        MG._1BB6[i] = -1;
    }
    g_Minigame._1B4C = 60;
    for (i = 0; i < 3; i++) {
        fn_3_14402C(i);
        MG._0000[i]._2A = 2;
        MG._0000[i]._1C = 1;
        MG._0000[i]._2B = 0;
    }
    fn_3_154214();
}

// .text:0x00145EB8 size:0x13C mapped:0x80784F4C
void fn_3_145EB8(void) {
    int i;

    fn_3_145B98();
    for (i = 0; i < 50; i++) {
        if (MG._193A[i] == 5 || MG._193A[i] == 6) {
            fn_3_1453BC(i);
        } else if (MG._193A[i] == 2) {
            fn_3_145AD0(i);
        }
    }
}

// .text:0x00145B98 size:0x320 mapped:0x80784C2C
void fn_3_145B98(void) {
    s32 list[4];
    int team;
    int coin;
    int n;
    int i;

    if (g_Minigame.turnOverStatus != 0) {
        return;
    }
    for (team = 0; team < 4; team++) {
        if (g_Minigame.minigameControlStruct.characterIndex[team] < 0) {
            continue;
        }
        if (MG._1C7E[team][2] < 0) {
            for (i = 0; i < 3; i++) {
                for (coin = 0; coin < 50; coin++) {
                    if (MG._193A[coin] == 0) {
                        MG._1C7E[team][i] = coin;
                        MG._1BB6[coin] = team;
                        MG._193A[coin] = 2;
                        MG._17C8[coin] = 0;
                        MG._1B84[coin] = RandomInt_Game(4);
                        MG._1C1A[coin] = 0;
                        MG._1C4C[coin] = 0;
                        g_Minigame._1C8A[team]++;
                        fn_3_145AD0(coin);
                        break;
                    }
                }
            }
        } else if (MG._1C7E[team][0] < 0) {
            MG._1C7E[team][0] = MG._1C7E[team][1];
            MG._1C7E[team][1] = MG._1C7E[team][2];
            for (coin = 0; coin < 50; coin++) {
                if (MG._193A[coin] == 0) {
                    MG._1C7E[team][2] = coin;
                    MG._1BB6[coin] = team;
                    MG._193A[coin] = 2;
                    MG._17C8[coin] = 0;
                    MG._1C1A[coin] = 0;
                    MG._1C4C[coin] = 0;
                    g_Minigame._1C8A[team]++;
                    if (g_Minigame._1C8A[team] <= lbl_3_data_21E68[1]) {
                        n = 0;
                        for (i = 0; i < 4; i++) {
                            if (MG._1CA9[i] == 1) {
                                list[n] = i;
                                n++;
                            }
                        }
                        if (n == 0) {
                            MG._1B84[coin] = RandomInt_Game(4);
                        } else {
                            MG._1B84[coin] = list[RandomInt_Game(n)];
                        }
                    } else {
                        MG._1B84[coin] = 5;
                        g_Minigame._1C8A[team] = 0;
                    }
                    break;
                }
            }
        }
    }
}

// .text:0x00145AD0 size:0xC8 mapped:0x80784B64
void fn_3_145AD0(int player) {
    int team;
    int slot;

    team = MG._1BB6[player];
    for (slot = 0; slot < 3; slot++) {
        if (MG._1C7E[team][slot] == player) {
            break;
        }
    }
    g_Minigame.wallBall_coinCoordinates[player].x = lbl_3_data_21D34[g_Minigame._1CAD[team]][slot][0];
    g_Minigame.wallBall_coinCoordinates[player].y = lbl_3_data_21D34[g_Minigame._1CAD[team]][slot][1];
    g_Minigame.wallBall_coinCoordinates[player].z = lbl_3_data_21D34[g_Minigame._1CAD[team]][slot][2];
}

// .text:0x001453BC size:0x714 mapped:0x80784450
void fn_3_1453BC(int coin) {
    UnkMgEntry3310* entry;
    Unk37A8Fielder* fielder;
    s16* timer;
    u8* state;
    VecXYZ pos;
    Vec dir;
    f32 dx;
    f32 dz;
    f32 dist;
    s16 points;
    s16 left;
    int team;
    int player;
    int target;
    int i;

    team = MG._1BB6[coin];
    timer = &g_Minigame.wallBall_coinsVisibleFrameCounter[coin];
    if (g_Minigame.wallBall_coinsVisibleFrameCounter[coin] < 0x7FFE) {
        (*timer)++;
    } else {
        *timer = 0x7FFF;
    }
    state = &g_Minigame.wallBall_coinsVisibleInd[coin];
    if (g_Minigame.wallBall_coinsVisibleInd[coin] == 6) {
        g_Minigame.wallBall_coinVelocity[coin].y += lbl_3_data_21E24[11];
        if (MG._1B84[coin] != 5) {
            g_Minigame.wallBall_coinVelocity[coin].x *= lbl_3_data_21E24[12];
            g_Minigame.wallBall_coinVelocity[coin].z *= lbl_3_data_21E24[12];
        } else if (*timer >= lbl_3_data_21E68[23]) {
            player = -1 - MG._1BE8[coin];
            fn_3_147CFC((Vec*)&g_Minigame.wallBall_coinCoordinates[coin]);
            fn_3_90064(0x309);
            fn_3_154238(coin);
            if (g_Minigame._1CA5[player] == 0 && MG._1C9A[player] == 0) {
                MG._1C9A[player] = 1;
                MG._1B3C[player] = lbl_3_data_21E68[14];
                MG._1B50[player] = 0;
                fielder = &g_Fielders[g_Minigame.minigameFielderIndex[player]];
                dir.x = 0.0f;
                dir.y = 0.0f;
                dir.z = -1.0f;
                PSVECNormalize(&dir, &dir);
                fielder->_038 = dir.x;
                g_Minigame._1DF4_u8[player] = 1;
                fielder->_03C = dir.z;
                fielder->_050 = lbl_3_data_21E24[15];
                fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[player], 2);
                if (g_Minigame._1CB1[player] < 0xFFFE) {
                    g_Minigame._1CB1[player]++;
                } else {
                    g_Minigame._1CB1[player] = 0xFF;
                }
            }
            *state = 0;
            *timer = 0;
            return;
        }
    }
    g_Minigame.wallBall_coinCoordinates[coin].x += g_Minigame.wallBall_coinVelocity[coin].x;
    g_Minigame.wallBall_coinCoordinates[coin].y += g_Minigame.wallBall_coinVelocity[coin].y;
    g_Minigame.wallBall_coinCoordinates[coin].z += g_Minigame.wallBall_coinVelocity[coin].z;
    if (g_Minigame.wallBall_coinCoordinates[coin].y < 0.0f) {
        *state = 0;
        *timer = 0;
        if (MG._1B84[coin] == 5) {
            fn_3_154238(coin);
        }
        return;
    }
    target = MG._1BE8[coin];
    if (target >= 0) {
        dx = g_Minigame.wallBall_coinCoordinates[coin].x - lbl_3_data_21BC4[target][1].x;
        dz = g_Minigame.wallBall_coinCoordinates[coin].z - lbl_3_data_21BC4[target][1].z;
        dist = dolsqrtf2(dx * dx + dz * dz);
        entry = &MG._0000[target];
        if (entry->_2A == 2 && dist < lbl_3_data_21E24[1]) {
            if (MG._1B84[coin] == entry->_2C || entry->_2C == 4 || MG._1B84[coin] == 5) {
                if (MG._1B84[coin] == 5) {
                    points = lbl_3_data_21E68[24];
                } else {
                    points = 1;
                }
                pos = g_Minigame.wallBall_coinCoordinates[coin];
                pos.y *= -1.0f;
                if (MG._1B84[coin] == 5) {
                    fn_3_147CFC((Vec*)&pos);
                    fn_3_154238(coin);
                } else {
                    fn_80062BE4((Vec*)&pos);
                }
                if (MG._1B84[coin] == 5) {
                    fn_3_90064(0x309);
                } else {
                    fn_3_90064(0x2DC);
                }
                left = entry->_2D - (s8)points;
                if (left <= 0) {
                    entry->_2D = 0;
                } else {
                    entry->_2D = left;
                }
                MG._1B50[team]++;
                MG._1B58[team][g_Minigame._1B80[team]] = (s8)points * lbl_3_data_21E18[entry->_2B][1];
                g_Minigame._1B80[team]++;
                entry->_2F[0] = -1;
                entry->_2F[1] = -1;
                entry->_2F[2] = -1;
                entry->_2F[3] = -1;
                entry->_2E = 0;
                if (entry->_2D == 0) {
                    MG._1B58[team][g_Minigame._1B80[team]] = lbl_3_data_21E18[entry->_2B][0];
                    g_Minigame._1B80[team]++;
                    if (entry->_2C == 4) {
                        g_Minigame._1CA3 = 0;
                        entry->_2E = 0;
                    } else if (g_Minigame._1CA2 != 0) {
                        g_Minigame._1CA2 = 2;
                    }
                    entry->_1C = lbl_3_data_21E68[8] - lbl_3_data_21E68[9];
                    entry->_1A = 0;
                    entry->_2A = 4;
                    MG._1CA9[entry->_2C] = 0;
                    if (!g_d_GameSettings.exhibitionMatchInd && team == lbl_3_common_bss_37400._40) {
                        fn_3_1608F0(5, entry->_2C, 0);
                    }
                }
                entry->_1E = 1;
            } else if ((entry->_33 == 3 && entry->_2E == 0) || entry->_33 == 0) {
                if (entry->_2E == 0) {
                    entry->_26 = 0;
                }
                for (i = 0; i < 4; i++) {
                    if (entry->_2F[i] < 0) {
                        entry->_2F[i] = MG._1BB6[coin];
                        entry->_2E = 1;
                        entry->_20 = 0;
                        break;
                    }
                }
                MG._1B50[team] = 0;
            }
            *state = 0;
            *timer = 0;
            return;
        }
    }
    if (*timer > lbl_3_data_21E68[0]) {
        *state = 0;
        *timer = 0;
        if (MG._1B84[coin] == 5) {
            fn_3_154238(coin);
        }
    }
}

// .text:0x00144CB8 size:0x704 mapped:0x80783D4C
void fn_3_144CB8(void) {
    return;
}

// .text:0x00144ADC size:0x1DC mapped:0x80783B70
static inline f32 Lerp37A8(f32 a, f32 b, f32 t) {
    return (b - a) * t + a;
}

void fn_3_144ADC(int player) {
    Unk37A8Fielder* fielder;
    InputStruct* input;

    input = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[player]];
    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[player]];
    if (g_Minigame.minigameControlStruct.battingHandedness[player] != 0) {
        input = &g_Minigame._1D7C[g_Minigame.minigameControlStruct.characterIndex[player]];
    }
    if (MG._1B44[player] < 0x7FFE) {
        MG._1B44[player]++;
    } else {
        MG._1B44[player] = 0x7FFF;
    }
    switch (g_Minigame._1CA5[player]) {
    case 1:
        fielder->_00C = Lerp37A8(lbl_3_data_21D2C[1], lbl_3_data_21D2C[0], (f32)MG._1B44[player] / (f32)lbl_3_data_21E68[16]);
        if (MG._1B44[player] >= lbl_3_data_21E68[16]) {
            g_Minigame._1CA5[player] = 2;
            MG._1B44[player] = 0;
        }
        break;
    case 2:
        if (!(input->buttonInput & 4)) {
            g_Minigame._1CA5[player] = 3;
            MG._1B44[player] = 0;
        }
        break;
    case 3:
        fielder->_00C = Lerp37A8(lbl_3_data_21D2C[0], lbl_3_data_21D2C[1], (f32)MG._1B44[player] / (f32)lbl_3_data_21E68[16]);
        if (MG._1B44[player] >= lbl_3_data_21E68[16]) {
            g_Minigame._1CA5[player] = 0;
            MG._1B44[player] = 0;
        }
        break;
    }
}

// .text:0x0014471C size:0x3C0 mapped:0x807837B0
void fn_3_14471C(int player) {
    Unk37A8Fielder* fielder;
    VecXYZ d;
    f32 xx;
    f32 zz;
    f32 dist;
    f32 scale;
    s32 frames;
    int port;
    u8 coin;

    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[player]];
    port = g_Minigame.minigameControlStruct.characterIndex[player];
    coin = g_Minigame._1C8E[player];
    if (fielder->_17A == 0x26) {
        getAnimRelatedCoordinates(port, 9, &d);
    } else if (fielder->_1C7 == 0) {
        getAnimRelatedCoordinates(port, 0x19, &d);
    } else {
        getAnimRelatedCoordinates(port, 0x13, &d);
    }
    g_Minigame.wallBall_coinCoordinates[coin].x = d.x;
    g_Minigame.wallBall_coinCoordinates[coin].y = -d.y;
    g_Minigame.wallBall_coinCoordinates[coin].z = d.z;
    d.x = fielder->_10C - g_Minigame.wallBall_coinCoordinates[coin].x;
    d.y = fielder->_110 - g_Minigame.wallBall_coinCoordinates[coin].y;
    d.z = fielder->_114 - g_Minigame.wallBall_coinCoordinates[coin].z;
    if (MG._193A[coin] == 4) {
        if (MG._1B84[coin] != 5) {
            xx = d.x * d.x;
            zz = d.z * d.z;
            dist = dolsqrtf2(xx + zz);
            if (player == 0 || player == 3) {
                scale = lbl_3_data_21E24[8] / dist;
            } else {
                scale = lbl_3_data_21E24[9] / dist;
            }
            g_Minigame.wallBall_coinVelocity[coin].x = d.x * scale;
            g_Minigame.wallBall_coinVelocity[coin].z = d.z * scale;
            g_Minigame.wallBall_coinVelocity[coin].y = lbl_3_data_21E24[10];
        } else {
            frames = lbl_3_data_21E68[23] + 10;
            g_Minigame.wallBall_coinVelocity[coin].x = (fielder->_10C - g_Minigame.wallBall_coinCoordinates[coin].x) / frames;
            g_Minigame.wallBall_coinVelocity[coin].z = (fielder->_114 - g_Minigame.wallBall_coinCoordinates[coin].z) / frames;
            g_Minigame.wallBall_coinVelocity[coin].y = -lbl_3_data_21E24[11] * frames * 0.5f;
        }
        MG._193A[coin] = 6;
    } else {
        frames = LERPToNewRange_Float(fielder->_1CE, 0, 100, lbl_3_data_21E1C[0], lbl_3_data_21E1C[1]);
        g_Minigame.wallBall_coinVelocity[coin].x = d.x / frames;
        g_Minigame.wallBall_coinVelocity[coin].y = d.y / frames;
        g_Minigame.wallBall_coinVelocity[coin].z = d.z / frames;
        MG._193A[coin] = 5;
    }
    MG._17C8[coin] = 0;
    if (MG._1B84[coin] == 5) {
        fn_3_90064(0x308);
    }
}

// .text:0x0014443C size:0x2E0 mapped:0x807834D0
void fn_3_14443C(void) {
    int i;
    int j;

    fn_3_14423C();
    for (i = 0; i < 3; i++) {
        if (MG._0000[i]._18 < 0x7FFE) {
            MG._0000[i]._18++;
        } else {
            MG._0000[i]._18 = 0x7FFF;
        }
        if (MG._0000[i]._1A < 0x7FFE) {
            MG._0000[i]._1A++;
        } else {
            MG._0000[i]._1A = 0x7FFF;
        }
        if (MG._0000[i]._1E != 0) {
            if (MG._0000[i]._1E < 0x7FFE) {
                MG._0000[i]._1E++;
            } else {
                MG._0000[i]._1E = 0x7FFF;
            }
        }
        if (MG._0000[i]._2A == 0) {
            fn_3_14402C(i);
        } else if (MG._0000[i]._2A == 1) {
            MG._0000[i]._1C--;
            MG._0000[i].pos.y = Lerp37A8(lbl_3_data_21D1C[MG._0000[i]._2B * 2], lbl_3_data_21D1C[MG._0000[i]._2B * 2 + 1],
                                         (f32)MG._0000[i]._1A / (f32)lbl_3_data_21E68[5]);
            if (MG._0000[i]._1C <= 0) {
                MG._0000[i]._2A = 2;
                MG._0000[i]._1A = 0;
            }
        } else if (MG._0000[i]._2A == 2) {
            if (g_Minigame._1CA2 == 2) {
                for (j = 0; j < 3; j++) {
                    if (MG._0000[j]._2A == 2) {
                        MG._0000[j]._2A = 3;
                        MG._0000[j]._1A = 0;
                    }
                }
            }
            fn_3_1439EC(i);
        } else if (MG._0000[i]._2A == 3) {
            MG._0000[i].pos.y = (lbl_3_data_21D1C[MG._0000[i]._2B * 2] - lbl_3_data_21D1C[MG._0000[i]._2B * 2 + 1]) *
                                    ((f32)MG._0000[i]._1A / (f32)lbl_3_data_21E68[6]) +
                                lbl_3_data_21D1C[MG._0000[i]._2B * 2];
            if (MG._0000[i]._1A >= lbl_3_data_21E68[6]) {
                MG._0000[i]._2A = 0;
                MG._0000[i]._1A = 0;
                MG._1CA9[MG._0000[i]._2C] = 0;
                if (g_Minigame._1CA3 != 0) {
                    g_Minigame._1CA3 = 0;
                }
            }
        } else if (MG._0000[i]._2A == 4) {
            if (MG._0000[i]._1C != 0) {
                MG._0000[i]._1C--;
            }
            if (MG._0000[i]._1A >= lbl_3_data_21E68[8]) {
                MG._0000[i]._2A = 0;
                MG._0000[i]._1A = 0;
            }
        }
    }
}

// .text:0x0014423C size:0x200 mapped:0x807832D0
void fn_3_14423C(void) {
    u32 start;
    u32 end;
    int i;
    UnkMgEntry3310* entry;

    if (g_Minigame.turnOverStatus != 0) {
        return;
    }
    if (g_Minigame._1CA3 != 0) {
        if (MG._0000[1]._2A == 2 && MG._0000[1]._18 >= lbl_3_data_21DC8[g_Minigame.soloMinigameDifficulty][g_Minigame._1CA4 - 1][2] * 60) {
            MG._0000[1]._2A = 3;
            MG._0000[1]._2E = 0;
            MG._0000[1]._1A = 0;
        }
    } else if (g_Minigame._1CA4 < 2) {
        if (!g_Minigame.multiPlayerInd) {
            start = lbl_3_data_21DC8[g_Minigame.soloMinigameDifficulty][g_Minigame._1CA4][0] * 60;
            end = lbl_3_data_21DC8[g_Minigame.soloMinigameDifficulty][g_Minigame._1CA4][1] * 60;
        } else {
            start = lbl_3_data_21DC8[4][g_Minigame._1CA4][0] * 60;
            end = lbl_3_data_21DC8[4][g_Minigame._1CA4][1] * 60;
        }
        if (g_Minigame._17C0 < start || g_Minigame._17C0 > end) {
            g_Minigame._1CA2 = 0;
            return;
        }
        for (i = 0; i < 3; i++) {
            if (MG._0000[i]._2A != 0) {
                break;
            }
        }
        if (i < 3) {
            if (g_Minigame._1CA2 == 0) {
                g_Minigame._1CA2 = 2;
            }
        } else {
            entry = &MG._0000[1];
            entry->_2A = 1;
            entry->_2B = 1;
            entry->_2C = 4;
            entry->_2D = lbl_3_data_21E10[g_Minigame._1CA4 + 4];
            entry->_18 = 0;
            entry->_1A = 0;
            entry->_1C = lbl_3_data_21E68[5];
            entry->_20 = 0;
            entry->_2E = 0;
            entry->pos.y = lbl_3_data_21D1C[3];
            entry->_2F[0] = -1;
            entry->_2F[1] = -1;
            entry->_2F[2] = -1;
            entry->_2F[3] = -1;
            g_Minigame._1CA3 = 1;
            g_Minigame._1CA2 = 0;
            g_Minigame._1CA4++;
        }
    }
}

// .text:0x0014402C size:0x210 mapped:0x807830C0
void fn_3_14402C(int idx) {
    s16* timer;
    s32 candidates[4];
    int n;
    int i;

    if (g_Minigame.turnOverStatus == 0) {
        timer = &MG._0000[idx]._1C;
        if (*timer < 0) {
            *timer = RandomInt_Game_Range(lbl_3_data_21DC4[0], lbl_3_data_21DC4[1]);
        } else if (g_Minigame._1CA3 == 0 && g_Minigame._1CA2 == 0) {
            (*timer)--;
            if (*timer == 0) {
                n = 0;
                for (i = 0; i < 4; i++) {
                    if (MG._1CA9[i] == 0) {
                        candidates[n] = i;
                        n++;
                    }
                }
                MG._0000[idx]._2C = candidates[random_fn_3_9EE24(n)];
                MG._1CA9[MG._0000[idx]._2C] = 1;
                MG._0000[idx]._2D = lbl_3_data_21E10[MG._0000[idx]._2C];
                *timer = lbl_3_data_21E68[5];
                MG._0000[idx]._18 = 0;
                MG._0000[idx]._1A = 0;
                MG._0000[idx]._1E = 0;
                MG._0000[idx]._2A = 1;
                MG._0000[idx]._2B = 0;
                MG._0000[idx].pos.y = lbl_3_data_21D1C[1];
                MG._0000[idx]._22 = lbl_3_data_21E04[0] + RandomInt_Game_Range(lbl_3_data_21E04[0], lbl_3_data_21E04[1]);
                MG._0000[idx]._24 = MG._0000[idx]._22;
                MG._0000[idx]._34 = -1;
                MG._0000[idx].rot.z = 0.0f;
                MG._0000[idx].rot.x = 0.0f;
                MG._0000[idx].rot.y = lbl_3_data_26698[idx];
            }
        }
    }
}

// .text:0x00143FAC size:0x80 mapped:0x80783040
void fn_3_143FAC(int idx) {
    int i;

    if (g_Minigame._1CA2 == 2) {
        for (i = 0; i < 3; i++) {
            if (MG._0000[i]._2A == 2) {
                MG._0000[i]._2A = 3;
                MG._0000[i]._1A = 0;
            }
        }
    }
    fn_3_1439EC(idx);
}

// .text:0x001439EC size:0x5C0 mapped:0x80782A80
void fn_3_1439EC(int idx) {
    UnkMgEntry3310* entry;
    s32 i;

    entry = &MG._0000[idx];
    if (entry->_2B != 0) {
        entry->_20++;
        if (entry->_20 == 1) {
            entry->_2E = 0;
        }
        if (entry->_20 >= lbl_3_data_21E68[12]) {
            entry->_20 = 0;
            for (i = 0; i < 4; i++) {
                fn_3_1430D0(idx, i);
                fn_3_90064(0x2DA);
            }
            entry->_2E = 1;
        }
    } else if (entry->_2E != 0) {
        entry->_26++;
        if (entry->_26 == lbl_3_data_21E68[13]) {
            fn_3_1430D0(idx, entry->_2F[0]);
            entry->_34 = -1;
            entry->_2F[0] = entry->_2F[1];
            entry->_2F[1] = entry->_2F[2];
            entry->_2F[2] = entry->_2F[3];
            entry->_2F[3] = -1;
            if (entry->_2F[0] < 0) {
                entry->_2E = 0;
            }
            entry->_26 = 0;
            fn_3_90064(0x2DA);
        }
    }
}

// .text:0x00143770 size:0x27C mapped:0x80782804
s32 fn_3_143770(UnkMgEntry3310* entry) {
    s32 open[4];
    s32 free[4];
    Vec dir;
    Vec fwd = { 0.0f, 0.0f, -1.0f };
    Vec fwd2 = { 0.0f, 0.0f, -1.0f };
    Vec fwd3 = { 0.0f, 0.0f, -1.0f };
    s32 nOpen;
    s32 nFree;
    s32* list;
    s32* count;
    int i;
    f32 angle;

    if (entry->_2E == 0) {
        open[0] = -1;
        open[1] = -1;
        open[2] = -1;
        open[3] = -1;
        nOpen = 0;
        nFree = 0;
        for (i = 0; i < 4; i++) {
            if (MG._1C9A[i] == 0) {
                if (MG._1C9E[i] == 0) {
                    open[nOpen] = i;
                    nOpen++;
                }
                free[i] = i;
                nFree++;
            }
        }
        if (nOpen == 0) {
            if (nFree == 0) {
                for (nFree = 0; nFree < 4; nFree++) {
                    free[nFree] = nFree;
                }
            }
            list = free;
            count = &nFree;
        } else {
            list = open;
            count = &nOpen;
        }
        entry->_35 = list[random_fn_3_9EE24(*count)];
        entry->_34 = g_Minigame.minigameFielderIndex[entry->_35];
        MG._1C9E[entry->_35] = 1;
    } else {
        entry->_34 = g_Minigame.minigameFielderIndex[entry->_2F[0]];
    }
    PSVECSubtract(&g_Fielders[entry->_34].pos, &entry->pos, &dir);
    dir.y = 0.0f;
    if (PSVECMag(&dir)) {
        PSVECNormalize(&dir, &dir);
    }
    angle = acosf_kludge(PSVECDotProduct(&dir, &fwd));
    if (dir.x < 0.0f) {
        angle = 360.0 * 0.017453292f - angle;
    }
    entry->rot.y = -angle;
    return 1;
}

// .text:0x00143714 size:0x5C mapped:0x807827A8
void fn_3_143714(void) {
    int i;

    for (i = 0; i < 40; i++) {
        if (MG._00A8[i].active != 0) {
            fn_3_143358(i);
        }
    }
}

// .text:0x00143358 size:0x3BC mapped:0x807823EC
void fn_3_143358(int idx) {
    Unk37A8Piranha* piranha;
    Unk37A8Fielder* fielder;
    Vec dir;
    f32 dx;
    f32 dz;
    f32 xx;
    f32 zz;
    f32 dist;
    int i;

    piranha = &MG._00A8[idx];
    piranha->_20++;
    if (piranha->_20 > lbl_3_data_21E68[10]) {
        piranha->active = 0;
        return;
    }
    piranha->pos.x += piranha->vel.x;
    piranha->pos.y += piranha->vel.y;
    piranha->pos.z += piranha->vel.z;
    if (piranha->active == 2) {
        piranha->vel.y += piranha->_18;
    }
    if (piranha->pos.y < lbl_3_data_21E24[13]) {
        if (piranha->pos.z < 0.0f) {
            if (piranha->active == 2) {
                MG._1C9E[piranha->_1C] = 0;
            }
            piranha->active = 0;
            return;
        }
        piranha->vel.y = -piranha->vel.y;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameFielderIndex[i] < 0) {
            continue;
        }
        fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
        if (g_Minigame._1CA5[i] != 0) {
            continue;
        }
        dx = piranha->pos.x - fielder->pos.x;
        dz = piranha->pos.z - fielder->pos.z;
        xx = dx * dx;
        zz = dz * dz;
        dist = dolsqrtf2(xx + zz);
        if (lbl_3_data_21E24[2] + lbl_3_data_47BC[fielder->_1C9] > dist) {
            if (piranha->active == 2) {
                MG._1C9E[piranha->_1C] = 0;
            }
            piranha->active = 0;
            if (MG._1C9A[i] == 0) {
                MG._1C9A[i] = 1;
                MG._1B3C[i] = lbl_3_data_21E68[14];
                MG._1B50[i] = 0;
                dir.x = piranha->vel.x;
                dir.y = 0.0f;
                dir.z = piranha->vel.z;
                PSVECNormalize(&dir, &dir);
                fielder->_038 = dir.x;
                g_Minigame._1DF4_u8[i] = 1;
                fielder->_03C = dir.z;
                fielder->_050 = lbl_3_data_21E24[15];
                fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[i], 2);
                if (g_Minigame._1CB1[i] < 0xFFFE) {
                    g_Minigame._1CB1[i]++;
                } else {
                    g_Minigame._1CB1[i] = 0xFF;
                }
            }
            return;
        }
    }
}

// .text:0x001430D0 size:0x288 mapped:0x80782164
void fn_3_1430D0(s32 arg0, s32 player) {
    Unk37A8Piranha* piranha;
    Unk37A8Fielder* fielder;
    int i;
    f32 size;
    Vec d;

    for (i = 0; i < 40; i++) {
        if (MG._00A8[i].active == 0) {
            break;
        }
    }
    if (i < 40) {
        piranha = &MG._00A8[i];
        fn_3_118358(arg0, &piranha->pos);
        fielder = &g_Fielders[g_Minigame.minigameFielderIndex[player]];
        d.x = lbl_3_data_21B94[g_Minigame._1CAD[player]].x - piranha->pos.x;
        d.y = lbl_3_data_21B94[g_Minigame._1CAD[player]].y - piranha->pos.y;
        d.z = lbl_3_data_21B94[g_Minigame._1CAD[player]].z - piranha->pos.z;
        size = 0.01f * (lbl_3_data_7F10[fielder->_17A] * charSizeMultipliers[fielder->_17A][0]);
        d.y += lbl_3_data_21D2C[1] + size;
        piranha->vel.x = d.x / (f32)lbl_3_data_21E68[21];
        piranha->vel.y = d.y / (f32)lbl_3_data_21E68[21];
        piranha->vel.z = d.z / (f32)lbl_3_data_21E68[21];
        piranha->active = 1;
        piranha->_20 = 0;
        piranha->_1C = player;
        fn_3_15730C(i, piranha->pos.x, -piranha->pos.y, piranha->pos.z);
    }
}

// .text:0x00142DB4 size:0x31C mapped:0x80781E48
void fn_3_142DB4(int idx) {
    UnkMgEntry3310* entry;
    Unk37A8Piranha* piranha;
    Unk37A8Fielder* fielder;
    int i;
    f32 size;
    Vec d;

    entry = &MG._0000[idx];
    for (i = 0; i < 40; i++) {
        if (MG._00A8[i].active == 0) {
            break;
        }
    }
    if (i < 40) {
        piranha = &MG._00A8[i];
        if (entry->_2B != 0) {
            piranha->pos.x = lbl_3_data_21BC4[idx][3].x;
            piranha->pos.y = lbl_3_data_21BC4[idx][3].y;
            piranha->pos.z = lbl_3_data_21BC4[idx][3].z;
        } else {
            piranha->pos.x = lbl_3_data_21BC4[idx][2].x;
            piranha->pos.y = lbl_3_data_21BC4[idx][2].y;
            piranha->pos.z = lbl_3_data_21BC4[idx][2].z;
        }
        piranha->_22 = entry->_35;
        fielder = &g_Fielders[entry->_34];
        piranha->_1C = entry->_35;
        d.x = lbl_3_data_21B94[g_Minigame._1CAD[entry->_35]].x - piranha->pos.x;
        d.y = lbl_3_data_21B94[g_Minigame._1CAD[entry->_35]].y - piranha->pos.y;
        d.z = lbl_3_data_21B94[g_Minigame._1CAD[entry->_35]].z - piranha->pos.z;
        size = 0.01f * (lbl_3_data_7F10[fielder->_17A] * charSizeMultipliers[fielder->_17A][0]);
        d.y += lbl_3_data_21D2C[1] + size;
        piranha->vel.x = d.x / (f32)lbl_3_data_21E68[22];
        piranha->vel.y = d.y / (f32)lbl_3_data_21E68[22];
        piranha->vel.z = d.z / (f32)lbl_3_data_21E68[22];
        piranha->_18 = 0.0f;
        piranha->active = 2;
        piranha->_20 = 0;
        fn_3_15730C(i, piranha->pos.x, -piranha->pos.y, piranha->pos.z);
    }
}

// .text:0x00142CA8 size:0x10C mapped:0x80781D3C
void fn_3_142CA8(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 10; j++) {
            g_Minigame.miniGameCurrentPoints[i] += MG._1B58[i][j];
            MG._1B58[i][j] = 0;
        }
        MG._1B80[i] = 0;
    }
}

// .text:0x00142C18 size:0x90 mapped:0x80781CAC
void fn_3_142C18(void) {
    Unk37A8Cpu* cpus = MG._1DCC;
    Unk37A8Cpu* cpu;
    s8 i;
    u8 strength;

    memset(g_Minigame._1D7C, 0, 0x78);
    i = 0;
    do {
        cpu = &cpus[i];
        strength = g_Minigame.minigameControlStruct.aIStrength[i];
        cpu->_3 = 1;
        cpu->_0 = RandomInt_Game_Range(lbl_3_data_21EAC[strength][0], lbl_3_data_21EAC[strength][1]);
    } while (++i < 4);
}

// .text:0x001428F0 size:0x328 mapped:0x80781984
u8 fn_3_1428F0(s8 player, u8 force) {
    Unk37A8Cpu* cpu;
    s8 port;
    u8 strength;
    s8 target;
    s8 coin;
    s8 ready;
    s8 count;
    s8 i;
    u8 kind;
    u8 found;
    UnkMgEntry3310* entry;

    ready = -1;
    found = FALSE;
    count = 0;
    target = MG._1DCC[player]._3;
    port = g_Minigame.minigameControlStruct.characterIndex[player];
    strength = g_Minigame.minigameControlStruct.aIStrength[player];
    if (MG._1DCC[player]._0 >= 0) {
        cpu->_0--;
    }
    cpu = &MG._1DCC[player];
    coin = MG._1C7E[player][0];
    if (coin < 0) {
        return FALSE;
    }
    for (i = 0; i < 3; i++) {
        if (MG._0000[i]._2A == 2) {
            count++;
            if (MG._0000[target]._2C == 4) {
                ready = i;
                break;
            }
        }
    }
    if (ready < 0 && cpu->_0 >= 0 && !force) {
        return FALSE;
    }
    kind = MG._1B84[coin];
    if (kind != 5 || (count != 0 && RandomInt_Game(100) >= lbl_3_data_21EC0[strength])) {
        if (count == 0) {
            return FALSE;
        }
        if (RandomInt_Game(100) < lbl_3_data_21EBC[strength]) {
            found = TRUE;
        }
        if (!found) {
            entry = &MG._0000[target];
            if (entry->_2A == 2 && (kind == entry->_2C || kind == 5 || entry->_2C == 4)) {
                found = TRUE;
            }
        }
        if (!found) {
            for (i = 0; i < 3; i++) {
                if (MG._0000[i]._2A == 2 && (kind == MG._0000[i]._2C || kind == 5 || MG._0000[i]._2C == 4)) {
                    target = i;
                    found = TRUE;
                    break;
                }
            }
        }
    }
    if (found) {
        switch (target) {
        case 0:
            g_Minigame._1D7C[port].newButtonInput |= 0x102;
            g_Minigame._1D7C[port].buttonInput |= 0x102;
            break;
        case 1:
            g_Minigame._1D7C[port].newButtonInput |= 0x108;
            g_Minigame._1D7C[port].buttonInput |= 0x108;
            break;
        case 2:
            g_Minigame._1D7C[port].newButtonInput |= 0x101;
            g_Minigame._1D7C[port].buttonInput |= 0x101;
            break;
        }
        cpu->_3 = target;
    } else {
        g_Minigame._1D7C[port].newButtonInput |= 0x200;
        g_Minigame._1D7C[port].buttonInput |= 0x200;
    }
    cpu->_0 = RandomInt_Game_Range(lbl_3_data_21EAC[strength][0], lbl_3_data_21EAC[strength][1]);
    return TRUE;
}

// .text:0x00142570 size:0x380 mapped:0x80781604
s32 fn_3_142570(s8 player) {
    Unk37A8Fielder* fielder;
    Unk37A8Piranha* piranha;
    f32 speed;
    f32 vx2;
    f32 vz2;
    f32 dx;
    f32 dz;
    f32 reach;
    f32 dist;
    s32 best;
    s32 t;
    s16 limit;
    u8 found;
    s8 i;

    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[player]];
    reach = lbl_3_data_21E24[2] + lbl_3_data_47BC[fielder->_1C9];
    best = 10000;
    found = FALSE;
    i = 0;
    do {
        piranha = &MG._00A8[i];
        if (piranha->active != 0) {
            dz = fielder->pos.z - piranha->pos.z;
            dx = fielder->pos.x - piranha->pos.x;
            dist = dolsqrtf2(dx * dx + dz * dz);
            if (dist < reach) {
                return 0;
            }
            dx /= dist;
            dz /= dist;
            vx2 = piranha->vel.x * piranha->vel.x;
            vz2 = piranha->vel.z * piranha->vel.z;
            speed = dolsqrtf2(vx2 + vz2);
            if (dx * (piranha->vel.x / speed) + dz * (piranha->vel.z / speed) >= 0.9994f) {
                t = (dist - reach) / speed;
                if (t < best) {
                    best = t;
                }
                found = TRUE;
            }
        }
    } while (++i < 40);
    limit = lbl_3_data_21E68[23];
    i = 0;
    do {
        if (MG._193A[i] == 6 && MG._1B84[i] == 5 && player == -1 - MG._1BE8[i]) {
            t = limit - MG._17C8[i];
            if (t >= 0) {
                if (t < best) {
                    best = t;
                }
                found = TRUE;
            }
        }
    } while (++i < 50);
    if (found) {
        return best;
    }
    return -1;
}

// .text:0x00142284 size:0x2EC mapped:0x80781318
void fn_3_142284(void) {
    Unk37A8Cpu* cpus = MG._1DCC;
    Unk37A8Cpu* cpu;
    s32 eta[4];
    s8 port;
    u8 strength;
    s8 i;

    i = 0;
    do {
        cpu = &cpus[i];
        port = g_Minigame.minigameControlStruct.characterIndex[i];
        if (port >= 0 && port < 4) {
            eta[i] = fn_3_142570(i);
            if (g_Minigame.minigameControlStruct.battingHandedness[i] == 0) {
                continue;
            }
            memset(&g_Minigame._1D7C[port], 0, sizeof(InputStruct));
            strength = g_Minigame.minigameControlStruct.aIStrength[i];
            switch (cpu->_2) {
            case 0:
                if (eta[i] >= 0) {
                    switch (RandomIndexFromWeights(lbl_3_data_21E9C[strength], 4)) {
                    case 0:
                        if (eta[i] > LERPToNewRange_Float(MG._1B50[i], 0, lbl_3_data_21E68[19], lbl_3_data_21E68[2], lbl_3_data_21E68[3]) + 3) {
                            if (fn_3_1428F0(i, FALSE)) {
                                cpu->_2 = 1;
                            }
                        } else {
                            g_Minigame._1D7C[port].newButtonInput |= 4;
                            g_Minigame._1D7C[port].buttonInput |= 4;
                            cpu->_2 = 2;
                        }
                        break;
                    case 1:
                        if (eta[i] > lbl_3_data_21E68[2] + 3) {
                            if (fn_3_1428F0(i, FALSE)) {
                                cpu->_2 = 1;
                            }
                        } else {
                            g_Minigame._1D7C[port].newButtonInput |= 4;
                            g_Minigame._1D7C[port].buttonInput |= 4;
                            cpu->_2 = 2;
                        }
                        break;
                    case 2:
                        g_Minigame._1D7C[port].newButtonInput |= 4;
                        g_Minigame._1D7C[port].buttonInput |= 4;
                        cpu->_2 = 2;
                        break;
                    case 3:
                        if (fn_3_1428F0(i, TRUE)) {
                            cpu->_2 = 1;
                        }
                        break;
                    }
                } else if (fn_3_1428F0(i, FALSE)) {
                    cpu->_2 = 1;
                }
                break;
            case 1:
                if (g_Minigame._1C92[i] < 0) {
                    cpu->_2 = 0;
                }
                break;
            case 2:
                g_Minigame._1D7C[port].buttonInput |= 4;
                if (g_Minigame._1CA5[i] != 1) {
                    cpu->_2 = 3;
                }
                break;
            case 3:
                if (eta[i] >= 0) {
                    g_Minigame._1D7C[port].buttonInput |= 4;
                } else {
                    cpu->_2 = 4;
                }
                break;
            case 4:
                if (g_Minigame._1CA5[i] != 3) {
                    cpu->_2 = 0;
                }
                break;
            }
        } else {
            eta[i] = -1;
        }
    } while (++i < 4);
}

// .text:0x0014225C size:0x28 mapped:0x807812F0
void fn_3_14225C(void) {
    fn_800B9948(fn_3_141C8C);
}

// .text:0x00142088 size:0x1D4 mapped:0x8078111C
void fn_3_142088(void) {
    u32 y;
    u32 x;
    u32 offset;

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            offset = fn_3_142030(x, y, 4) * 4;
            if (offset < 32) {
                lbl_3_bss_B800[offset + 0] = lbl_3_bss_B800[offset + 2] = 255;
                lbl_3_bss_B800[offset + 1] = lbl_3_bss_B800[offset + 3] = 150;
            } else {
                lbl_3_bss_B800[offset + 0] = lbl_3_bss_B800[offset + 2] = 0;
                lbl_3_bss_B800[offset + 1] = lbl_3_bss_B800[offset + 3] = 0;
            }
        }
    }
    GXInitTexObj(&lbl_3_bss_B7C4, lbl_3_bss_B800, 4, 4, GX_TF_RGBA8, GX_REPEAT, GX_REPEAT, GX_FALSE);
    GXInitTexObjLOD(&lbl_3_bss_B7C4, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    lbl_3_bss_B7E4 = 0;
    lbl_3_data_266A4 = -1;
    lbl_3_bss_B7C1 = 0;
}

// .text:0x00142030 size:0x58 mapped:0x807810C4
s32 fn_3_142030(s32 x, s32 y, s32 width) {
    return (y / 4) * 4 * width + (x / 4) * 4 * 4 + (y % 4) * 4 + x % 4;
}

// .text:0x00141F30 size:0x100 mapped:0x80780FC4
void fn_3_141F30(void) {
    int value;
    int i;
    u8* tex;

    lbl_3_bss_B7E4 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_B7E4 & 1) == 0) {
        tex = GetTexel(0, 0, 4);
        value = *tex;
        value += lbl_3_data_266A4 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            tex[i] = value;
        }
        DCFlushRange(lbl_3_bss_B800, 0x40);
        if (value + lbl_3_data_266A4 * 2 > 255 || value + lbl_3_data_266A4 * 2 < 0) {
            lbl_3_data_266A4 *= -1;
        }
    }
}

// .text:0x00141C8C size:0x2A4 mapped:0x80780D20
void fn_3_141C8C(void* arg0, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* arg4, u8* arg5) {
    int value;
    int i;
    u8* tex;
    Mtx m;
    Mtx scale;
    Mtx trans;

    lbl_3_bss_B7E4 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_B7E4 & 1) == 0) {
        tex = GetTexel(0, 0, 4);
        value = *tex;
        value += lbl_3_data_266A4 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            tex[i] = value;
        }
        DCFlushRange(lbl_3_bss_B800, 0x40);
        if (value + lbl_3_data_266A4 * 2 > 255 || value + lbl_3_data_266A4 * 2 < 0) {
            lbl_3_data_266A4 *= -1;
        }
    }
    GXLoadTexObj(&lbl_3_bss_B7C4, *map);
    PSMTXIdentity(m);
    PSMTXScale(scale, 0.5f, -0.5f, 0.0f);
    PSMTXTrans(trans, 0.5f, 0.5f, 1.0f);
    PSMTXConcat(trans, scale, scale);
    GXLoadTexMtxImm(m, *map * 3 + GX_TEXMTX0, GX_MTX3x4);
    GXLoadTexMtxImm(scale, *map * 3 + GX_PTTEXMTX0, GX_MTX3x4);
    GXSetTexCoordGen2(*coord, GX_TG_MTX3X4, GX_TG_POS, *map * 3 + GX_TEXMTX0, GX_TRUE, *map * 3 + GX_PTTEXMTX0);
    GXSetTevOrder(*stage, *coord, *map, GX_COLOR_NULL);
    GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_TEXA, GX_CC_CPREV);
    GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    (*stage)++;
    (*coord)++;
    (*map)++;
    (*arg4)++;
    (*arg5)++;
    if (++lbl_3_bss_B7C1 >= 6) {
        lbl_3_bss_B7C1 = 0;
        fn_800B993C();
    }
}

// .text:0x00141C44 size:0x48 mapped:0x80780CD8
void fn_3_141C44(void) {
    if (++lbl_3_bss_B7C1 >= 6) {
        lbl_3_bss_B7C1 = 0;
        fn_800B993C();
    }
}
