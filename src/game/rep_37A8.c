#include "game/rep_37A8.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "game/rep_28A8.h"
#include "game/rep_31A0.h"
#include "game/rep_3310.h"
#include "game/rep_3880.h"
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
    /* 0x26 */ u8 _26[0x2A - 0x26];
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
    /* 0x18 */ u8 _18[0x1C - 0x18];
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s16 _20;
    /* 0x22 */ u8 _22[0x26 - 0x22];
    /* 0x26 */ u8 active;
    /* 0x27 */ u8 _27;
} Unk37A8Piranha; // size: 0x28

// A CPU player's state, one per player at g_Minigame._1DCC
typedef struct Unk37A8Cpu {
    /* 0x0 */ s16 _0;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
} Unk37A8Cpu; // size: 0x4

// This minigame's view of g_Minigame
typedef struct Unk37A8Minigame {
    /* 0x0000 */ UnkMgEntry3310 _0000[3];
    /* 0x00A8 */ Unk37A8Piranha _00A8[40];
    /* 0x06E8 */ u8 _06E8[0x193A - 0x6E8];
    /* 0x193A */ u8 _193A[100];
    /* 0x199E */ u8 _199E[0x1B44 - 0x199E];
    /* 0x1B44 */ s16 _1B44[4];
    /* 0x1B4C */ u8 _1B4C[0x1B58 - 0x1B4C];
    /* 0x1B58 */ u8 _1B58[4][10];
    /* 0x1B80 */ u8 _1B80[4];
    /* 0x1B84 */ u8 _1B84[0x1BB6 - 0x1B84];
    /* 0x1BB6 */ s8 _1BB6[50];
    /* 0x1BE8 */ u8 _1BE8[0x1C7E - 0x1BE8];
    /* 0x1C7E */ s8 _1C7E[4][3];
    /* 0x1C8A */ u8 _1C8A[0x1C9A - 0x1C8A];
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
    /* 0x010 */ u8 _010[0x17A - 0x10];
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x268 - 0x17C];
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
    return;
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
    return;
}

// .text:0x00145B98 size:0x320 mapped:0x80784C2C
void fn_3_145B98(void) {
    return;
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
void fn_3_1453BC(void) {
    return;
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
void fn_3_14471C(void) {
    return;
}

// .text:0x0014443C size:0x2E0 mapped:0x807834D0
void fn_3_14443C(void) {
    return;
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
void fn_3_143FAC(void) {
    return;
}

// .text:0x001439EC size:0x5C0 mapped:0x80782A80
void fn_3_1439EC(void) {
    return;
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
    return;
}

// .text:0x00143358 size:0x3BC mapped:0x807823EC
void fn_3_143358(void) {
    return;
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
void fn_3_142DB4(void) {
    return;
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
void fn_3_1428F0(void) {
    return;
}

// .text:0x00142570 size:0x380 mapped:0x80781604
void fn_3_142570(void) {
    return;
}

// .text:0x00142284 size:0x2EC mapped:0x80781318
void fn_3_142284(void) {
    return;
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
