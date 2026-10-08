#include "game/rep_3520.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "game/rep_28A8.h"
#include "game/rep_540.h"
#include "game/m_sound.h"
#include "game/rep_D0.h"
#include "game/rep_140.h"
#include "game/kinoko.h"
#include "game/rep_1188.h"
#include "game/rep_1FD8.h"
#include "game/rep_31A0.h"
#include "game/rep_3880.h"
#include "game/rep_AC8.h"
#include "game/rep_CC8.h"
#include "game/rep_D18.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "Dolphin/rand.h"
#include "musyx/musyx.h"

// One of four objects at g_Minigame + 0xBB0
typedef struct Unk3520Obj {
    /* 0x00 */ Vec _0;
    /* 0x0C */ Vec _C;
    /* 0x18 */ Vec _18;
    /* 0x24 */ Vec _24;
    /* 0x30 */ f32 _30;
    /* 0x34 */ f32 _34;
    /* 0x38 */ s16 _38;
    /* 0x3A */ s16 _3A;
    /* 0x3C */ s8 _3C;
    /* 0x3D */ u8 _3D;
    /* 0x3E */ u8 _3E;
    /* 0x3F */ u8 _3F;
} Unk3520Obj; // size: 0x40

// A spoke's end points, one per player at g_Minigame._1CE8
typedef struct Unk3520Spoke {
    /* 0x00 */ VecXYZ start;
    /* 0x0C */ VecXYZ end;
} Unk3520Spoke; // size: 0x18

// The pieces along the spokes, at g_Minigame._A8
typedef struct Unk3520Piece {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 _0C[0x22 - 0xC];
    /* 0x22 */ s16 _22;
    /* 0x24 */ u8 _24[2];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} Unk3520Piece; // size: 0x28

// The bonus box, at g_Minigame._CB0
typedef struct Unk3520Box {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec vel;
    /* 0x18 */ u8 _18[0x1C - 0x18];
    /* 0x1C */ s16 _1C;
    /* 0x1E */ u8 _1E;
} Unk3520Box; // size: 0x20

// A wall the bounce reflects off
typedef struct Unk3520Line {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec dir;
} Unk3520Line;

// The coin bag, at g_Minigame._B6C
typedef struct Unk3520Bag {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec vel;
    /* 0x18 */ s32 coins[10];
    /* 0x40 */ u8 active;
    /* 0x41 */ u8 _41[3];
} Unk3520Bag; // size: 0x44

// This minigame's view of g_Minigame
typedef struct Unk3520Minigame {
    /* 0x0000 */ u8 _0000[0xA8];
    /* 0x00A8 */ Unk3520Piece pieces[40];
    /* 0x06E8 */ u8 _06E8[0xB6C - 0x6E8];
    /* 0x0B6C */ Unk3520Bag bag;
    /* 0x0BB0 */ Unk3520Obj objs[4];
    /* 0x0CB0 */ Unk3520Box box;
    /* 0x0CD0 */ u8 _0CD0[0x1CE8 - 0xCD0];
    /* 0x1CE8 */ Unk3520Spoke spokes[4];
} Unk3520Minigame;

#define MG (*(Unk3520Minigame*)&g_Minigame)

// Another player as a target, sorted by fn_3_134918 (distance) or fn_3_134908 (points)
typedef struct Unk3520Target {
    /* 0x0 */ f32 dist;
    /* 0x4 */ s16 points;
    /* 0x6 */ u8 player;
} Unk3520Target; // size: 0x8

// A coin a CPU player could go for, scored by fn_3_1350BC and sorted by fn_3_135698
typedef struct Unk3520Coin {
    /* 0x00 */ f32 score;
    /* 0x04 */ s32 coin;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 z;
    /* 0x10 */ u8 quadrant;
    /* 0x11 */ u8 valid;
} Unk3520Coin; // size: 0x14

// One per player, at g_Minigame._1DCC
typedef struct Unk3520Cpu {
    /* 0x0 */ f32 _0;
    /* 0x4 */ s16 _4;
    /* 0x6 */ u8 _6;
    /* 0x7 */ s8 _7;
} Unk3520Cpu; // size: 0x8

// The CPU players' state, at g_Minigame._1DCC
typedef struct Unk3520Ai {
    /* 0x00 */ Unk3520Cpu cpu[4];
    /* 0x20 */ f32 sin;
    /* 0x24 */ f32 cos;
} Unk3520Ai;

typedef struct Unk3520Fielder {
    /* 0x000 */ Vec pos;
    /* 0x00C */ f32 _00C;
    /* 0x010 */ u8 _010[0x30 - 0x10];
    /* 0x030 */ f32 _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x48 - 0x40];
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x50 - 0x4C];
    /* 0x050 */ f32 _050;
    /* 0x054 */ u8 _054[0x15C - 0x54];
    /* 0x15C */ f32 _15C;
    /* 0x160 */ u8 _160[0x16C - 0x160];
    /* 0x16C */ f32 _16C;
    /* 0x170 */ u8 _170[0x17A - 0x170];
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x1C9 - 0x17C];
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA[0x1D2 - 0x1CA];
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3[0x203 - 0x1D3];
    /* 0x203 */ u8 _203;
    /* 0x204 */ u8 _204;
    /* 0x205 */ u8 _205[0x20D - 0x205];
    /* 0x20D */ u8 _20D;
    /* 0x20E */ u8 _20E;
    /* 0x20F */ u8 _20F;
    /* 0x210 */ u8 _210[0x268 - 0x210];
} Unk3520Fielder; // size: 0x268

extern Unk3520Fielder g_Fielders[9];

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern s32 fn_800247E4(s32, s32, s32, s32);
extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

extern void fn_80011604(s8, void*);
extern void fn_3_1608F0(int, int, int);
extern void minigamesSetSomePointers(void);
extern void minigamesGXStuff(void);
extern void minigamesSetSomePointers2(void);
extern void fn_800528B4(void);
extern void fn_800246D4(int (*compare)(const void*, const void*), void* src, void* dst, int size, int count);
extern void fn_800115C8(s8);
extern void fn_80011578(void);
extern void changeScene(u8, s16);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800ACFB0(void* data);
extern u8 lbl_803CBBC0;
extern u16 lbl_3_data_81FC[0x88];

extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_3_data_21278[2];
extern u8 lbl_3_data_2127C[8][5];
extern u8 lbl_3_data_21984[8];
extern f32 lbl_3_data_4444[10];
extern u8 lbl_3_data_88DC[2];
extern f32 lbl_3_data_47BC[5];
extern f32 lbl_3_data_2198C[4][2];
extern Vec lbl_3_data_219AC;
extern f32 lbl_3_data_219B8[19];
extern f32 lbl_3_data_21A14[7];
extern s16 lbl_3_data_21A30[6];
extern s16 lbl_3_data_21A04[8];
extern s16 lbl_3_data_21A3C[2][2];
extern s16 lbl_3_data_21A44;
extern Vec lbl_3_data_21A48;
extern f32 lbl_3_data_21A54[3];
extern struct {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
} lbl_3_data_21A60;
extern f32 lbl_3_data_21A64[9];
extern s16 lbl_3_data_21A90[4][4][2];
extern s16 lbl_3_data_21A88[4];
extern s16 lbl_3_data_21AD0[4][4];
extern s16 lbl_3_data_21AF0[1];
extern f32 lbl_3_data_21AF4;
extern f32 lbl_3_data_21AF8[6];
extern s16 lbl_3_data_21B10[3];
extern f32 lbl_3_data_21B18[2];
extern f32 lbl_3_data_21B28[4];
extern f32 lbl_3_data_21B38[4];
extern f32 lbl_3_data_21B48[4];
extern f32 lbl_3_data_21B58[4];
extern f32 lbl_3_data_21B68[4];
extern f32 lbl_3_data_21B78[4];
extern u8 lbl_3_data_21B16;
extern s16 lbl_3_data_21B20[4];
extern s8 lbl_3_data_21B88[4];
extern s16 lbl_3_data_21B8C[4];

s8 lbl_3_data_26580 = -1;

// .bss statics, declared in reverse address order (MWCC lays them out last to first)
static u8 lbl_3_bss_B781;
static u8 lbl_3_bss_B780;
static u8 lbl_3_bss_B740[0x40] ATTRIBUTE_ALIGN(32);
static GXTexObj lbl_3_bss_B708;
static s32 lbl_3_bss_B704;
static s16 lbl_3_bss_B702;
static u8 lbl_3_bss_B700;

// Waits a random time from the difficulty's range for the elapsed minutes
static inline void Unk3520Obj_SetDelay(Unk3520Obj* obj, u32 t) {
    s16 lo;
    int r;

    obj->_3D = 0;
    obj->_3A = 0;
    lo = lbl_3_data_21A90[g_Minigame.soloMinigameDifficulty][t][0];
    r = random_fn_3_9EE24((lbl_3_data_21A90[g_Minigame.soloMinigameDifficulty][t][1] - lo) * 60);
    obj->_38 = r + lo * 60;
}

// .text:0x0013C468 size:0x328 mapped:0x8077B4FC
void fn_3_13C468(void) {
    switch (g_GameLogic.gameStatus) {
    case GAME_STATUS_LOAD_GAME:
        fn_3_13BCB8();
        break;
    case GAME_STATUS_TRANSITION_MINIGAME_TO_BATTING:
        fn_3_13BBF4();
        break;
    case GAME_STATUS_DEFAULT:
        fn_3_13BB30();
        break;
    case GAME_STATUS_LIVE_BALL:
        fn_3_13B284();
        break;
    case GAME_STATUS_TRANSITION_MINIGAME_POSTGAME:
        fn_3_13B9C4();
        break;
    }
    if (lbl_3_common_bss_34C58._30 != 0) {
        lbl_3_common_bss_34C58._30--;
    }
}

// .text:0x0013C464 size:0x4 mapped:0x8077B4F8
void fn_3_13C464(void) {
    return;
}

// .text:0x0013BCB8 size:0x7AC mapped:0x8077AD4C
// 93.8%: the fielder setup reads its table and stores in another order, and several
// loops start from fresh g_Minigame bases instead of copies.
void fn_3_13BCB8(void) {
    s32 i;
    int n;
    int j;
    u8 strength;
    int r;

    if (g_GameLogic._125 == 0) {
        fn_3_59A90();
        g_GameLogic.secondaryGameMode = 8;
        g_Minigame._17C0 = 0;
        g_Minigame.turnOverStatus = 0;
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
        g_Minigame.pointsReqToWin_challenge = 0;
        g_Minigame.minigamePlayerSelectedOrder = -1;
        g_Minigame.rosterID = -1;
        lbl_3_common_bss_34C58._30 = 0;
        if (!g_Minigame.multiPlayerInd) {
            g_Minigame._17C4 = lbl_3_data_21984[g_Minigame.soloMinigameDifficulty] * 60;
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
            g_Minigame._17C4 = lbl_3_data_21984[4] * 60;
        }
        fn_3_58870();
        n = 0;
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                g_Minigame.minigameControlStruct._28[n] = i;
                g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]] = n + 2;
                fn_3_6E24C(i, g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]);
                g_Minigame.starDashStunType[i] = 0;
                g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]]._20D = i;
                g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]].pos.x = lbl_3_data_2198C[n][0];
                g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]].pos.z = lbl_3_data_2198C[n][1];
                g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]].pos.y = 0.0f;
                g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]]._00C = 0.0f;
                g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]]._1D2 = 0;
                g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[n]]]._048 = -1.5707964f;
                n++;
            }
        }
        for (i = 0; i < 100; i++) {
            g_Minigame.wallBall_coinsVisibleInd[i] = 0;
        }
        g_Minigame._1D50 = 30;
        g_Minigame._1D6C = 0;
        g_Minigame._1D54 = 0;
        MG.bag.active = 0;
        g_Minigame._72A = 0;
        g_Minigame._1D52 = 600;
        g_Minigame._1D6D = -1;
        g_Minigame._1D72 = 0;
        g_Minigame._1D73 = 0;
        for (i = 0; i < 4; i++) {
            MG.spokes[i].start.y = lbl_3_data_21A48.y;
            MG.spokes[i].end.y = lbl_3_data_21A48.y;
            g_Minigame._1D64[i] = i * 0x400;
        }
        for (i = 0; i < 40; i++) {
            MG.pieces[i]._26 = 0;
            MG.pieces[i].pos.y = lbl_3_data_21A48.y;
            MG.pieces[i]._22 = 0;
        }
        if (!g_Minigame.multiPlayerInd && !g_Minigame._1A3C) {
            lbl_3_bss_B781 = g_Minigame.soloMinigameDifficulty;
            lbl_3_bss_B780 = lbl_3_data_21A88[g_Minigame.soloMinigameDifficulty];
        } else {
            lbl_3_bss_B781 = 3;
            lbl_3_bss_B780 = 4;
        }
        for (i = 0; i < 4; i++) {
            memset(&MG.objs[i]._0, 0, sizeof(Vec));
            memset(&MG.objs[i]._C, 0, sizeof(Vec));
            memset(&MG.objs[i]._18, 0, sizeof(Vec));
            memset(&MG.objs[i]._24, 0, sizeof(Vec));
            MG.objs[i]._3D = 0;
        }
        for (j = 0; j < lbl_3_bss_B780; j++) {
            r = random_fn_3_9EE24((lbl_3_data_21A90[g_Minigame.soloMinigameDifficulty][0][1] - lbl_3_data_21A90[g_Minigame.soloMinigameDifficulty][0][0]) * 60);
            MG.objs[j]._38 = lbl_3_data_21A90[g_Minigame.soloMinigameDifficulty][0][0] * 60 + r;
            MG.objs[j]._30 = 360 / lbl_3_bss_B780 * j;
            MG.objs[j]._34 = MG.objs[j]._30 + 360 / lbl_3_data_21A88[lbl_3_bss_B781];
        }
        g_Minigame._1D78[0] = 0;
        g_Minigame._1D78[1] = 0;
        g_Minigame._1D78[2] = 0;
        g_Minigame._1D78[3] = 0;
        g_Minigame._1D76 = 0;
        MG.box._1C = lbl_3_data_21B10[0];
        MG.box._1E = 0;
        g_Minigame.playerIDWithPowerup[0] = -1;
        fn_3_133200();
        fn_3_169600();
        minigamesSetSomePointers();
        minigamesGXStuff();
        minigamesSetSomePointers2();
        fn_3_C39C8();
        g_GameLogic._125++;
    } else {
        fn_3_5A6D4(GAME_STATUS_GAME_START_MOVIE);
    }
}

// .text:0x0013BBF4 size:0xC4 mapped:0x8077AC88
void fn_3_13BBF4(void) {
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

// .text:0x0013BB30 size:0xC4 mapped:0x8077ABC4
void fn_3_13BB30(void) {
    fn_3_F1DC();
    fn_3_1356F8();
    changeScene(1, 6);
    fn_3_5A6D4(GAME_STATUS_LIVE_BALL);
}

// .text:0x0013B9C4 size:0x16C mapped:0x8077AA58
void fn_3_13B9C4(void) {
    u32 i;

    fn_3_157570();
    fn_3_DE4FC();
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    fn_80011578();
    for (i = 0; i < 100; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 0;
    }
    g_Minigame._1D50 = 30;
    g_Minigame._1D6C = 0;
    for (i = 0; i < 4; i++) {
        MG.objs[i]._3D = 0;
    }
    g_Minigame._CCE[0] = 0;
}

// .text:0x0013B284 size:0x740 mapped:0x8077A318
void fn_3_13B284(void) {
    if (fn_3_108854() == 0) {
        if (g_Minigame.turnOverStatus == 0) {
            g_Minigame._17C0++;
        }
        if (g_Minigame._17C4 != 0) {
            g_Minigame._17C4--;
            if (g_Minigame._17C4 < 600 && g_Minigame._17C4 != 0 && g_Minigame._17C4 % 60 == 0) {
                fn_3_90064(lbl_3_data_81FC[40]);
            }
        }
        fn_3_13334C();
        fn_3_2F484();
        fn_3_133320();
        fn_3_136220();
        fn_3_139F84();
        fn_3_139700();
        fn_3_13AA78();
        fn_3_136048();
        fn_3_138AA4();
        fn_3_136EA4();
        fn_3_135924();
        fn_3_13AFE4();
    }
}

// .text:0x0013AFE4 size:0x2A0 mapped:0x8077A078
void fn_3_13AFE4(void) {
    if (g_Minigame.turnOverStatus == 0) {
        if (g_Minigame._17C4 == 0) {
            g_Minigame.turnOverStatus = 1;
            fn_3_10F550(3, 0);
            sndFXStart(0x1BE, lbl_800EFBA4[7], 0x3F);
        }
    } else {
        if (g_Minigame.turnOverStatus == 1) {
            g_Minigame.turnOverStatus = 2;
            g_GameLogic.CountdownUntilFade = lbl_3_data_21B20[0];
            fn_3_14E894();
        }
        if (--g_GameLogic.CountdownUntilFade == 7) {
            changeScene(3, 6);
        }
        if (g_GameLogic.CountdownUntilFade <= 0) {
            fn_3_13AE1C();
        }
    }
}

// .text:0x0013AE1C size:0x1C8 mapped:0x80779EB0
void fn_3_13AE1C(void) {
    u32 i;

    fn_3_DE4FC();
    if (g_Minigame.soloMinigameDifficulty <= MINIGAME_DIFFICULTY_MULTIPLAYER_CHALLENGE_HARD && g_Minigame.multiPlayerInd == 0) {
        if (g_Minigame.minigameControlStruct._1C[g_Minigame._1908] == 1 &&
            g_Minigame.challenge_minigame_haven_tWonYetIndicator == 0) {
            g_Minigame._1A37 = 1;
        } else {
            g_Minigame._1A37 = 2;
        }
    }
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    fn_80011578();
    for (i = 0; i < 100; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 0;
    }
    g_Minigame._1D50 = 30;
    g_Minigame._1D6C = 0;
    for (i = 0; i < 4; i++) {
        MG.objs[i]._3D = 0;
    }
    g_Minigame._CCE[0] = 0;
}

// .text:0x0013ADC0 size:0x5C mapped:0x80779E54
void fn_3_13ADC0(Vec* out, Vec* v, Vec* n) {
    f32 d = v->x * n->x + v->y * n->y + v->z * n->z;

    d *= 2.0f;
    out->x = v->x - d * n->x;
    out->y = v->y - d * n->y;
    out->z = v->z - d * n->z;
}

// .text:0x0013ACB4 size:0x10C mapped:0x80779D48
// 91.2%: the second reflection loads _70C and _714 before the first one stores, and
// the FPRs differ throughout.
void fn_3_13ACB4(Unk3520Line* line) {
    Vec n;
    Vec d;
    Vec r;

    n.x = -line->dir.z;
    n.y = 0.0f;
    n.z = line->dir.x;
    d.x = line->pos.x - g_Minigame._6F4;
    d.y = 0.0f;
    d.z = line->pos.z - g_Minigame._6FC;
    if (d.x * n.x + d.z * n.z > 0.0f) {
        n.x *= -1.0f;
        n.z *= -1.0f;
    }
    fn_3_13ADC0(&r, &d, &n);
    n.x *= -1.0f;
    n.z *= -1.0f;
    g_Minigame._6F4 = line->pos.x + r.x;
    g_Minigame._6FC = line->pos.z + r.z;
    d.x = line->pos.x - g_Minigame._70C;
    d.z = line->pos.z - g_Minigame._714;
    fn_3_13ADC0(&r, &d, &n);
    g_Minigame._70C = line->pos.x + r.x;
    g_Minigame._714 = line->pos.z + r.z;
    g_Minigame._700 = 0.5f * (g_Minigame._70C + g_Minigame._6F4);
    g_Minigame._708 = 0.5f * (g_Minigame._714 + g_Minigame._6FC);
}

// .text:0x0013AA78 size:0x23C mapped:0x80779B0C
void fn_3_13AA78(void) {
    if (g_Minigame._72A != 0) {
        fn_3_13A0AC();
    } else {
        fn_3_13A89C();
    }
    if (g_Minigame._1D6D >= 0) {
        if (--g_Minigame._1D56 < 0 || g_Minigame.turnOverStatus != 0) {
            fn_3_14E988(g_Minigame._1D6D);
            fn_800115C8(g_Minigame._1D6D);
            g_Minigame._1D6D = -1;
        }
    }
}

// .text:0x0013A89C size:0x1DC mapped:0x80779930
void fn_3_13A89C(void) {
    if (g_Minigame.turnOverStatus == 0) {
        if (--g_Minigame._1D52 <= 0) {
            g_Minigame._6E8 = lbl_3_data_219AC.x;
            g_Minigame._6EC = lbl_3_data_219AC.y;
            g_Minigame._6F0 = lbl_3_data_219AC.z;
            g_Minigame._72B = 0;
            fn_3_13A724();
            g_Minigame._72A = 1;
            g_Minigame._724 = 0;
            g_Minigame._1D52 = lbl_3_data_21A30[2];
            fn_3_150010(4);
            fn_3_106EB0();
        }
    }
}

// .text:0x0013A724 size:0x178 mapped:0x807797B8
void fn_3_13A724(void) {
    f32 speed;
    Vec d;
    f32 dist;

    g_Minigame._6F4 = g_Minigame._6E8;
    g_Minigame._6F8 = g_Minigame._6EC;
    g_Minigame._6FC = g_Minigame._6F0;
    g_Minigame._728 = RandomInt_Game_Range(lbl_3_data_21A30[3], lbl_3_data_21A30[4]);
    speed = RandomF32_Game_Range(lbl_3_data_21A14[0], lbl_3_data_21A14[1]);
    d.x = lbl_3_data_219AC.x - g_Minigame._6E8;
    d.y = lbl_3_data_219AC.y - g_Minigame._6EC;
    d.z = lbl_3_data_219AC.z - g_Minigame._6F0;
    dist = dolsqrtf2(d.x * d.x + d.z * d.z);
    getComponentsFromSAng(random_fn_3_9EE24(0x1000), &d.x, &d.z);
    g_Minigame._70C = d.x * speed + g_Minigame._6F4;
    g_Minigame._714 = d.z * speed + g_Minigame._6FC;
    g_Minigame._710 = lbl_3_data_21A14[4];
    g_Minigame._700 = 0.5f * (g_Minigame._6F4 + g_Minigame._70C);
    g_Minigame._708 = 0.5f * (g_Minigame._6FC + g_Minigame._714);
    g_Minigame._704 = g_Minigame._6F8 + RandomF32_Game_Range(lbl_3_data_21A14[2], lbl_3_data_21A14[3]);
    g_Minigame._726 = 0;
}

// .text:0x0013A0AC size:0x678 mapped:0x80779140
// 94.0%: the inlined fn_3_13ACB4 and fn_3_13A724 schedule their loads and stores
// differently, and the setup computes the ratio in another order.
void fn_3_13A0AC(void) {
    VecSrcDst seg;
    CollisionStruct col;
    f32 t;
    f32 best;
    f32 dx;
    f32 dz;
    f32 xx;
    f32 zz;
    f32 dist;
    u32 type;
    int i;
    int who;
    Unk3520Fielder* fielder;

    g_Minigame._724++;
    g_Minigame._726++;
    if (g_Minigame.turnOverStatus != 0) {
        g_Minigame._72A = 0;
        return;
    }
    if (g_Minigame._724 > lbl_3_data_21A30[0]) {
        g_Minigame._72A = 0;
        fn_3_14E988(4);
        return;
    }
    t = (f32)g_Minigame._726 / (f32)g_Minigame._728;
    seg.src.x = g_Minigame._6E8;
    seg.src.y = -(lbl_3_data_21A14[2] / 2);
    seg.src.z = g_Minigame._6F0;
    fn_3_28E4((Vec*)&g_Minigame._6E8, (Vec*)&g_Minigame._6F4, 3, t);
    seg.dst.x = g_Minigame._6E8;
    seg.dst.y = -(lbl_3_data_21A14[2] / 2);
    seg.dst.z = g_Minigame._6F0;
    type = checkCollision(&seg, &col, 0, FALSE);
    if (type == 5) {
        g_Minigame._6E8 = col.position.x;
        fn_3_13ACB4((Unk3520Line*)&col);
        g_Minigame._6F0 = seg.src.z;
    }
    if (g_Minigame._6EC <= lbl_3_data_21A14[4]) {
        g_Minigame._6EC = lbl_3_data_21A14[4];
        g_Minigame._72B++;
        fn_3_13A724();
    }
    best = 999.9f;
    for (i = 0, who = -1; i < 4; i++) {
        if (g_Minigame.minigameFielderIndex[i] < 0) {
            continue;
        }
        fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
        if (fielder->_16C + fielder->_00C < g_Minigame._6EC - lbl_3_data_21A14[5]) {
            continue;
        }
        dx = g_Minigame._6E8 - fielder->pos.x;
        dz = g_Minigame._6F0 - fielder->pos.z;
        xx = dx * dx;
        zz = dz * dz;
        dist = dolsqrtf2(xx + zz);
        if (dist < lbl_3_data_21A14[5] + lbl_3_data_47BC[fielder->_1C9] && dist < best) {
            best = dist;
            who = i;
        }
    }
    if (who >= 0) {
        g_Minigame.miniGameCurrentPoints[who] += lbl_3_data_21A30[5];
        g_Minigame._72A = 0;
        g_Minigame._1D6D = who;
        g_Minigame._1D56 = lbl_3_data_21A30[1];
        fn_3_14E988(4);
        if (g_Minigame.playerIDWithPowerup[0] == who) {
            fn_800115C8(who);
            if (g_Minigame.starDashRelated_0_5Or1_5 == &lbl_3_data_21AF8[5]) {
                g_Minigame.playerIDWithPowerup[0] = -1;
            }
        }
        fn_3_150010(who);
        fn_80011604(who, fn_3_132EDC);
        if (!g_d_GameSettings.exhibitionMatchInd && who == lbl_3_common_bss_37400._40) {
            fn_3_1608F0(3, 0, 0);
        }
    }
}

// .text:0x0013A048 size:0x64 mapped:0x807790DC
void fn_3_13A048(s32 to, s32 from) {
    s16* points = g_Minigame.miniGameCurrentPoints;

    if (points[from] < lbl_3_data_21A04[7]) {
        points[to] += points[from];
        points[from] = 0;
    } else {
        points[to] += lbl_3_data_21A04[7];
        points[from] -= lbl_3_data_21A04[7];
    }
}

// .text:0x00139F84 size:0xC4 mapped:0x80779018
void fn_3_139F84(void) {
    fn_3_139CA0();
    fn_3_139808();
    fn_3_13974C();
}

// .text:0x00139CA0 size:0x2E4 mapped:0x80778D34
// 96.2%: the target keeps count * 4 in its own register (r18) for bag->coins.
void fn_3_139CA0(void) {
    Unk3520Bag* bag = NULL;
    u8 filling = FALSE;
    int count;
    int angle;
    f32 speed;
    f32 scale;
    int i;

    if (g_Minigame.turnOverStatus != 0) {
        return;
    }
    if (--g_Minigame._1D50 > 0) {
        return;
    }
    count = lbl_3_data_21A04[2];
    if (g_Minigame._1D54 % lbl_3_data_21A04[6] == 0 && 100 - g_Minigame._1D6C >= 10 && MG.bag.active == 0) {
        bag = &MG.bag;
        MG.bag.active = TRUE;
        count = 10;
        filling = TRUE;
    }
    angle = random_fn_3_9EE24(0x1000);
    speed = RandomF32_Game_Range(lbl_3_data_219B8[2], lbl_3_data_219B8[3]);
    for (i = 0; i < 100; i++) {
        if (filling) {
            if (count != 0) {
                if (g_Minigame.wallBall_coinsVisibleInd[i] == 0) {
                    g_Minigame.wallBall_coinsVisibleInd[i] = 2;
                    g_Minigame.wallBall_coinsVisibleFrameCounter[i] = 0;
                    g_Minigame._1D6C++;
                    bag->coins[count - 1] = i;
                    count--;
                }
            } else {
                bag->pos.x = lbl_3_data_219AC.x;
                bag->pos.y = lbl_3_data_219AC.y;
                bag->pos.z = lbl_3_data_219AC.z;
                getComponentsFromSAng(angle + (random_fn_3_9EE24(lbl_3_data_21A04[4] * 2) - lbl_3_data_21A04[4]), &bag->vel.x,
                                      &bag->vel.z);
                scale = speed + RandomF32_Game_Range(-lbl_3_data_219B8[4], lbl_3_data_219B8[4]);
                bag->vel.x *= scale;
                bag->vel.z *= scale;
                bag->vel.y = RandomF32_Game_Range(lbl_3_data_219B8[5], lbl_3_data_219B8[6]);
                break;
            }
        } else if (g_Minigame.wallBall_coinsVisibleInd[i] == 0) {
            g_Minigame.wallBall_coinCoordinates[i].x = lbl_3_data_219AC.x;
            g_Minigame.wallBall_coinCoordinates[i].y = lbl_3_data_219AC.y;
            g_Minigame.wallBall_coinCoordinates[i].z = lbl_3_data_219AC.z;
            getComponentsFromSAng(angle + (random_fn_3_9EE24(lbl_3_data_21A04[4] * 2) - lbl_3_data_21A04[4]),
                                  &g_Minigame.wallBall_coinVelocity[i].x, &g_Minigame.wallBall_coinVelocity[i].z);
            scale = speed + RandomF32_Game_Range(-lbl_3_data_219B8[4], lbl_3_data_219B8[4]);
            g_Minigame.wallBall_coinVelocity[i].x *= scale;
            g_Minigame.wallBall_coinVelocity[i].z *= scale;
            g_Minigame.wallBall_coinVelocity[i].y = RandomF32_Game_Range(lbl_3_data_219B8[0], lbl_3_data_219B8[1]);
            g_Minigame.wallBall_coinsVisibleInd[i] = 1;
            g_Minigame.wallBall_coinsVisibleFrameCounter[i] = 0;
            g_Minigame._1D6C++;
            g_Minigame._1D54++;
            if (--count <= 0) {
                fn_3_90064(0x2E8);
                break;
            }
        }
    }
    g_Minigame._1D50 = RandomInt_Game_Range(lbl_3_data_21A04[0], lbl_3_data_21A04[1]);
}

// .text:0x00139808 size:0x498 mapped:0x8077889C
// 94.6%: the inlined reflections load -1.0f through addi and schedule the y loads
// differently.
void fn_3_139808(void) {
    int i;
    int j;
    int who;
    VecSrcDst seg;
    CollisionStruct col;
    u32 type;
    f32 best;
    f32 radius;
    f32 reach;
    f32 dx;
    f32 dz;
    f32 dist;
    Unk3520Fielder* fielder;

    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] != 1) {
            continue;
        }
        g_Minigame.wallBall_coinsVisibleFrameCounter[i]++;
        if (g_Minigame.wallBall_coinsVisibleFrameCounter[i] > lbl_3_data_21A04[3]) {
            g_Minigame.wallBall_coinsVisibleInd[i] = 0;
            g_Minigame._1D6C--;
            continue;
        }
        seg.src.x = g_Minigame.wallBall_coinCoordinates[i].x;
        seg.src.y = -g_Minigame.wallBall_coinCoordinates[i].y;
        seg.src.z = g_Minigame.wallBall_coinCoordinates[i].z;
        g_Minigame.wallBall_coinVelocity[i].y += lbl_3_data_219B8[11];
        g_Minigame.wallBall_coinCoordinates[i].x += g_Minigame.wallBall_coinVelocity[i].x;
        g_Minigame.wallBall_coinCoordinates[i].y += g_Minigame.wallBall_coinVelocity[i].y;
        g_Minigame.wallBall_coinCoordinates[i].z += g_Minigame.wallBall_coinVelocity[i].z;
        if (g_Minigame.wallBall_coinCoordinates[i].y < lbl_3_data_219B8[14]) {
            g_Minigame.wallBall_coinCoordinates[i].y = lbl_3_data_219B8[14];
            g_Minigame.wallBall_coinVelocity[i].y *= -lbl_3_data_219B8[12];
            g_Minigame.wallBall_coinVelocity[i].x *= lbl_3_data_219B8[13];
            g_Minigame.wallBall_coinVelocity[i].z *= lbl_3_data_219B8[13];
        }
        seg.dst.x = g_Minigame.wallBall_coinCoordinates[i].x;
        seg.dst.y = -g_Minigame.wallBall_coinCoordinates[i].y;
        seg.dst.z = g_Minigame.wallBall_coinCoordinates[i].z;
        type = checkCollision(&seg, &col, 0, FALSE);
        if (type == 5) {
            col.normal.y *= -1.0f;
            fn_3_13ADC0((Vec*)&g_Minigame.wallBall_coinVelocity[i], (Vec*)&g_Minigame.wallBall_coinVelocity[i], &col.normal);
            g_Minigame.wallBall_coinCoordinates[i].x = col.position.x;
            g_Minigame.wallBall_coinCoordinates[i].y = -col.position.y;
            g_Minigame.wallBall_coinCoordinates[i].z = col.position.z;
        }
        seg.dst.x = g_Minigame.wallBall_coinCoordinates[i].x;
        seg.dst.y = -g_Minigame.wallBall_coinCoordinates[i].y;
        seg.dst.z = g_Minigame.wallBall_coinCoordinates[i].z;
        if (fn_3_1373E0(&seg, (Vec*)&g_Minigame.wallBall_coinVelocity[i], (VecSrcDst*)&col, lbl_3_data_219B8[15])) {
            g_Minigame.wallBall_coinCoordinates[i].x = col.position.x;
            g_Minigame.wallBall_coinCoordinates[i].y = col.position.y;
            g_Minigame.wallBall_coinCoordinates[i].z = col.position.z;
            memcpy(&g_Minigame.wallBall_coinVelocity[i], &col.normal, sizeof(Vec));
            seg.dst.x = g_Minigame.wallBall_coinCoordinates[i].x;
            seg.dst.y = -g_Minigame.wallBall_coinCoordinates[i].y;
            seg.dst.z = g_Minigame.wallBall_coinCoordinates[i].z;
            type = checkCollision(&seg, &col, 0, FALSE);
            if (type == 5) {
                col.normal.y *= -1.0f;
                fn_3_13ADC0((Vec*)&g_Minigame.wallBall_coinVelocity[i], (Vec*)&g_Minigame.wallBall_coinVelocity[i], &col.normal);
                g_Minigame.wallBall_coinCoordinates[i].x = col.position.x;
                g_Minigame.wallBall_coinCoordinates[i].y = -col.position.y;
                g_Minigame.wallBall_coinCoordinates[i].z = col.position.z;
            }
        }
        if (g_Minigame.turnOverStatus != 0) {
            continue;
        }
        best = 99999.9f;
        radius = lbl_3_data_219B8[15];
        for (j = 0, who = -1; j < 4; j++) {
            if (g_Minigame.minigameFielderIndex[j] < 0) {
                continue;
            }
            if (g_Minigame.starDashStunType[j] != 0 && g_Minigame.starDashStunType[j] != 3) {
                continue;
            }
            fielder = &g_Fielders[g_Minigame.minigameFielderIndex[j]];
            if (fielder->_203 != 0 && fielder->_204 > 3) {
                continue;
            }
            if (fielder->_16C + fielder->_00C < g_Minigame.wallBall_coinCoordinates[i].y) {
                continue;
            }
            reach = radius + lbl_3_data_47BC[fielder->_1C9];
            dz = fielder->pos.z - g_Minigame.wallBall_coinCoordinates[i].z;
            dx = fielder->pos.x - g_Minigame.wallBall_coinCoordinates[i].x;
            reach *= reach;
            dist = dx * dx + dz * dz;
            if (dist < reach && dist < best) {
                best = dist;
                who = j;
            }
        }
        if (who >= 0) {
            g_Minigame.miniGameCurrentPoints[who] += lbl_3_data_21A04[5];
            g_Minigame.wallBall_coinsVisibleInd[i] = 3;
            g_Minigame.wallBall_coinVelocity[i].z = 0.0f;
            g_Minigame.wallBall_coinVelocity[i].x = 0.0f;
            g_Minigame.wallBall_coinVelocity[i].y = RandomF32_Game_Range(lbl_3_data_219B8[0], lbl_3_data_219B8[1]);
            g_Minigame.wallBall_coinsVisibleFrameCounter[i] = 0;
            if (lbl_3_common_bss_34C58._30 == 0) {
                fn_3_90064(0x2E9);
                lbl_3_common_bss_34C58._30 = lbl_3_data_88DC[1];
            }
        }
    }
}

// .text:0x0013974C size:0xBC mapped:0x807787E0
void fn_3_13974C(void) {
    u32 i;

    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 3) {
            g_Minigame.wallBall_coinsVisibleFrameCounter[i]++;
            PSVECAdd((Vec*)&g_Minigame.wallBall_coinCoordinates[i], (Vec*)&g_Minigame.wallBall_coinVelocity[i],
                     (Vec*)&g_Minigame.wallBall_coinCoordinates[i]);
            g_Minigame.wallBall_coinVelocity[i].y += lbl_3_data_219B8[11];
            if (g_Minigame.wallBall_coinVelocity[i].y < 0.0f) {
                g_Minigame.wallBall_coinsVisibleInd[i] = 0;
                g_Minigame._1D6C--;
            }
        }
    }
}

// .text:0x00139700 size:0x4C mapped:0x80778794
void fn_3_139700(void) {
    if (MG.bag.active != 0) {
        if (g_Minigame.turnOverStatus != 0) {
            MG.bag.active = 0;
        } else {
            fn_3_1391C0();
        }
    }
}

// .text:0x001391C0 size:0x540 mapped:0x80778254
// 98.5%: registers only; bag sits in r28 where the target has r31, and the rest shift.
void fn_3_1391C0(void) {
    Unk3520Bag* bag = &MG.bag;
    VecSrcDst seg;
    CollisionStruct col;
    u32 type;
    int i;
    int who;
    int angle;
    s32 coin;
    f32 best;
    f32 radius;
    f32 reach;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 speed;
    f32 scale;
    Unk3520Fielder* fielder;

    seg.src.x = bag->pos.x;
    seg.src.y = -bag->pos.y;
    seg.src.z = bag->pos.z;
    bag->vel.y += lbl_3_data_219B8[11];
    bag->pos.x = bag->vel.x + bag->pos.x;
    bag->pos.y = bag->vel.y + bag->pos.y;
    bag->pos.z = bag->vel.z + bag->pos.z;
    seg.dst.x = bag->pos.x;
    seg.dst.y = -bag->pos.y;
    seg.dst.z = bag->pos.z;
    type = checkCollision(&seg, &col, 0, FALSE);
    if (type == 5) {
        col.normal.y *= -1.0f;
        fn_3_13ADC0(&bag->vel, &bag->vel, &col.normal);
        bag->pos.x = col.position.x;
        bag->pos.y = -col.position.y;
        bag->pos.z = col.position.z;
    }
    seg.dst.x = bag->pos.x;
    seg.dst.y = -bag->pos.y;
    seg.dst.z = bag->pos.z;
    if (fn_3_1373E0(&seg, &bag->vel, (VecSrcDst*)&col, lbl_3_data_219B8[15])) {
        bag->pos.x = col.position.x;
        bag->pos.y = col.position.y;
        bag->pos.z = col.position.z;
        memcpy(&bag->vel, &col.normal, sizeof(Vec));
        seg.dst.x = bag->pos.x;
        seg.dst.y = -bag->pos.y;
        seg.dst.z = bag->pos.z;
        type = checkCollision(&seg, &col, 0, FALSE);
        if (type == 5) {
            col.normal.y *= -1.0f;
            fn_3_13ADC0(&bag->vel, &bag->vel, &col.normal);
            bag->pos.x = col.position.x;
            bag->pos.y = -col.position.y;
            bag->pos.z = col.position.z;
        }
    }
    if (bag->pos.y < lbl_3_data_219B8[14]) {
        for (i = 0; i < 10; i++) {
            coin = bag->coins[i];
            g_Minigame.wallBall_coinCoordinates[coin].x = bag->pos.x;
            g_Minigame.wallBall_coinCoordinates[coin].y = bag->pos.y;
            g_Minigame.wallBall_coinCoordinates[coin].z = bag->pos.z;
            angle = random_fn_3_9EE24(0x1000);
            getComponentsFromSAng(angle + (random_fn_3_9EE24(lbl_3_data_21A04[4] * 2) - lbl_3_data_21A04[4]),
                                  &g_Minigame.wallBall_coinVelocity[coin].x, &g_Minigame.wallBall_coinVelocity[coin].z);
            scale = RandomF32_Game_Range(-lbl_3_data_219B8[9], lbl_3_data_219B8[10]);
            g_Minigame.wallBall_coinVelocity[coin].x *= scale;
            g_Minigame.wallBall_coinVelocity[coin].z *= scale;
            g_Minigame.wallBall_coinVelocity[coin].y = RandomF32_Game_Range(lbl_3_data_219B8[7], lbl_3_data_219B8[8]);
            g_Minigame.wallBall_coinsVisibleInd[coin] = 1;
            g_Minigame.wallBall_coinsVisibleFrameCounter[coin] = 0;
        }
        bag->active = FALSE;
        return;
    }
    best = 99999.9f;
    radius = lbl_3_data_219B8[15];
    for (i = 0, who = -1; i < 4; i++) {
        if (g_Minigame.minigameFielderIndex[i] < 0) {
            continue;
        }
        if (g_Minigame.starDashStunType[i] != 0 && g_Minigame.starDashStunType[i] != 3) {
            continue;
        }
        fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
        if (fielder->_203 != 0 && fielder->_204 > 3) {
            continue;
        }
        if (fielder->_16C + fielder->_00C < bag->pos.y) {
            continue;
        }
        reach = radius + lbl_3_data_47BC[fielder->_1C9];
        dz = fielder->pos.z - bag->pos.z;
        dx = fielder->pos.x - bag->pos.x;
        reach *= reach;
        dist = dx * dx + dz * dz;
        if (dist < reach && dist < best) {
            best = dist;
            who = i;
        }
    }
    if (who >= 0) {
        g_Minigame.miniGameCurrentPoints[who] += lbl_3_data_21A04[5] * 10;
        for (i = 0; i < 10; i++) {
            coin = bag->coins[i];
            g_Minigame.wallBall_coinCoordinates[coin].x = bag->pos.x;
            g_Minigame.wallBall_coinCoordinates[coin].y = bag->pos.y;
            g_Minigame.wallBall_coinCoordinates[coin].z = bag->pos.z;
            angle = random_fn_3_9EE24(0x1000);
            speed = RandomF32_Game_Range(lbl_3_data_219B8[2], lbl_3_data_219B8[3]);
            g_Minigame.wallBall_coinsVisibleInd[coin] = 3;
            getComponentsFromSAng(angle, &g_Minigame.wallBall_coinVelocity[coin].x, &g_Minigame.wallBall_coinVelocity[coin].z);
            scale = speed + RandomF32_Game_Range(-lbl_3_data_219B8[4], lbl_3_data_219B8[4]);
            g_Minigame.wallBall_coinVelocity[coin].x *= scale;
            g_Minigame.wallBall_coinVelocity[coin].z *= scale;
            g_Minigame.wallBall_coinVelocity[coin].y = RandomF32_Game_Range(lbl_3_data_219B8[0], lbl_3_data_219B8[1]);
            g_Minigame.wallBall_coinsVisibleFrameCounter[coin] = 0;
        }
        fn_3_90064(0x30A);
        bag->active = FALSE;
        lbl_3_common_bss_34C58._30 = lbl_3_data_88DC[1];
    }
}

// .text:0x00138AA4 size:0x71C mapped:0x80777B38
// 97.8%: g_Minigame, the .bss base and the object walker sit in other saved registers,
// and the inlined fn_3_137224 loop builds its bases anew.
void fn_3_138AA4(void) {
    u32 i;

    if (g_Minigame.turnOverStatus != 0) {
        return;
    }
    for (i = 0; i < lbl_3_bss_B780; i++) {
        if (i >= 4) {
            break;
        }
        switch (MG.objs[i]._3D) {
        case 0:
            fn_3_138448(&MG.objs[i]);
            break;
        case 1:
            fn_3_1382E0(&MG.objs[i]);
            break;
        case 2:
            fn_3_13802C(&MG.objs[i]);
            break;
        case 3:
            fn_3_137F14(&MG.objs[i]);
            break;
        case 4:
            fn_3_137DE4(&MG.objs[i]);
            break;
        case 5:
            fn_3_137CF8(&MG.objs[i]);
            break;
        }
    }
}

// .text:0x001384B4 size:0x5F0 mapped:0x80777548
// 98.2%: FPRs differ (the sums, deviations and center.x), and the else branch of the
// first deviation test shares its store with the then branch.
void fn_3_1384B4(Unk3520Obj* obj) {
    s32 coins[100];
    Vec center = { 0.0f, 0.0f, 20.0f };
    Vec d;
    Vec dn;
    Vec v;
    Vec forward = { 1.0f, 0.0f, 0.0f };
    u32 n;
    u32 i;
    f32 varX;
    f32 sdZ;
    f32 varZ;
    f32 sumZ;
    f32 sumX;
    f32 sdX;
    f32 angle;
    f32 len;
    f32 c;
    f32 s;
    f32 dot;
    f32 px;
    f32 pz;
    f32 ex;
    f32 ez;
    f32 fx;
    f32 fz;

    sumX = sumZ = 0.0f;
    n = 0;
    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 1) {
            d.x = g_Minigame.wallBall_coinCoordinates[i].x - center.x;
            d.y = 0.0f;
            d.z = g_Minigame.wallBall_coinCoordinates[i].z - center.z;
            PSVECNormalize(&d, &dn);
            angle = 57.29578f * (f32)acos(PSVECDotProduct(&forward, &dn));
            if (dn.z < 0.0f) {
                angle = 360.0f - angle;
            }
            if (angle >= obj->_30 && angle <= obj->_34) {
                coins[n] = i;
                n++;
                sumX += d.x;
                sumZ += d.z;
            }
        }
    }
    if (n != 0) {
        sumX /= n;
        sumZ /= n;
        varX = varZ = 0.0f;
        for (i = 0; i < n; i++) {
            d.x = g_Minigame.wallBall_coinCoordinates[coins[i]].x - center.x;
            d.z = g_Minigame.wallBall_coinCoordinates[coins[i]].z - center.z;
            varX += pow(d.x - sumX, 2.0);
            varZ += pow(d.z - sumZ, 2.0);
        }
        sdX = sqrt(varX / n);
        sdZ = sqrt(varZ / n);
        v.x = v.y = v.z = 0.0f;
        if (sdX > 7.0f) {
            v.x = sumX + sdX * (fabs(sumX) / sumX);
        } else {
            v.x = sumX;
        }
        if (sdZ > 6.25f) {
            v.z = sumZ + sdZ * (fabs(sumZ) / sumZ);
        } else {
            v.z = sumZ;
        }
        len = sqrt(pow(v.x, 2.0) + pow(v.z, 2.0));
        if (len < 5.0f) {
            PSVECNormalize(&v, &v);
            v.x *= 5.0f;
            v.z *= 5.0f;
        } else if (len > 15.0f) {
            PSVECNormalize(&v, &v);
            v.x *= 15.0f;
            v.z *= 15.0f;
        }
    } else {
        angle = 0.017453292f * (obj->_30 + (obj->_34 - obj->_30) * (rand() / 32767.0f));
        v.x = cos(angle);
        v.z = sin(angle);
        v.y = 0.0f;
        PSVECNormalize(&v, &v);
        PSVECScale(&v, 10.0f * (rand() / 32767.0f) + 5.0f, &v);
    }
    c = cos(0.017453292f * obj->_34);
    s = sin(0.017453292f * obj->_34);
    dot = v.x * c + v.z * s;
    px = c * dot;
    pz = s * dot;
    ex = v.x - px;
    ez = v.z - pz;
    fx = 3.5 * (fabs(ex) / ex);
    fz = 3.125 * (fabs(ez) / ez);
    if (fabs(ex) < fabs(fx)) {
        v.x = px + fx;
    }
    if (fabs(ez) < fabs(fz)) {
        v.z = pz + fz;
    }
    obj->_0.x = v.x + center.x;
    obj->_0.y = lbl_3_data_21A64[0];
    obj->_0.z = v.z + center.z;
    memset(&obj->_18, 0, sizeof(Vec));
    memset(&obj->_24, 0, sizeof(Vec));
    obj->_3A = 0;
    obj->_3D = 1;
}

// .text:0x00138448 size:0x6C mapped:0x807774DC
void fn_3_138448(Unk3520Obj* obj) {
    if (g_Minigame._72A == 0) {
        if (obj->_3A < 0x7FFE) {
            obj->_3A++;
        } else {
            obj->_3A = 0x7FFF;
        }
        if (obj->_3A >= obj->_38) {
            obj->_3E = 0;
            fn_3_1384B4(obj);
        }
    }
}

// .text:0x001382E0 size:0x168 mapped:0x80777374
void fn_3_1382E0(Unk3520Obj* obj) {
    u32 t;
    u32 minutes;

    t = minutes = g_Minigame._17C0 / 60 / 20;

    if (g_Minigame._72A != 0) {
        Unk3520Obj_SetDelay(obj, minutes);
    } else {
        if (obj->_3A < 0x7FFE) {
            obj->_3A++;
        } else {
            obj->_3A = 0x7FFF;
        }
        if (t > 3) {
            t = 3;
        }
        if (obj->_3A / 60 >= lbl_3_data_21AD0[lbl_3_bss_B781][t]) {
            obj->_C.x = obj->_C.z = 0.0f;
            obj->_C.y = -lbl_3_data_21A64[1];
            obj->_3D = 2;
            obj->_3A = 0;
        }
    }
}

// .text:0x0013802C size:0x2B4 mapped:0x807770C0
void fn_3_13802C(Unk3520Obj* obj) {
    if (g_Minigame._72A != 0) {
        obj->_C.y = lbl_3_data_21A64[5];
        obj->_3D = 5;
        obj->_3A = 0;
        return;
    }
    PSVECAdd(&obj->_0, &obj->_C, &obj->_0);
    if (fn_3_137B10(obj)) {
        g_Minigame._1D78[obj->_3C] = 0;
        fn_3_90064(0x30D);
    } else if (obj->_0.y <= 0.0f) {
        obj->_0.y = 0.0f;
        memset(&obj->_C, 0, sizeof(Vec));
        obj->_3A = 0;
        obj->_3D = 3;
        fn_3_1371E8();
        fn_3_137224(&obj->_0);
        g_Minigame._1D78[obj->_3C] = 0;
        fn_3_90064(0x2F7);
    }
}

// .text:0x00137F14 size:0x118 mapped:0x80776FA8
void fn_3_137F14(Unk3520Obj* obj) {
    if (g_Minigame._72A != 0) {
        obj->_C.y = lbl_3_data_21A64[5];
        obj->_3D = 5;
        obj->_3A = 0;
    } else {
        if (obj->_3E != 0) {
            obj->_3F++;
            if (obj->_3F >= 10) {
                fn_3_90064(0x303);
                obj->_3E = 0;
            }
        }
        if (obj->_3A < 0x7FFE) {
            obj->_3A++;
        } else {
            obj->_3A = 0x7FFF;
        }
        if (!fn_3_137B10(obj) && obj->_3A >= lbl_3_data_21A64[6]) {
            obj->_C.y = lbl_3_data_21A64[5];
            obj->_3D = 5;
            obj->_3A = 0;
        }
    }
}

// .text:0x00137DE4 size:0x130 mapped:0x80776E78
void fn_3_137DE4(Unk3520Obj* obj) {
    u32 t;

    PSVECAdd(&obj->_0, &obj->_C, &obj->_0);
    PSVECAdd(&obj->_18, &obj->_24, &obj->_18);
    if (obj->_3A < 0x7FFE) {
        obj->_3A++;
    } else {
        obj->_3A = 0x7FFF;
    }
    if (obj->_3A >= lbl_3_data_21A64[7]) {
        t = g_Minigame._17C0 / 60 / 20;
        if (t > 3) {
            t = 3;
        }
        Unk3520Obj_SetDelay(obj, t);
    }
}

// .text:0x00137CF8 size:0xEC mapped:0x80776D8C
void fn_3_137CF8(Unk3520Obj* obj) {
    u32 t;

    PSVECAdd(&obj->_0, &obj->_C, &obj->_0);
    if (!fn_3_137B10(obj) && obj->_0.y >= lbl_3_data_21A64[0]) {
        t = g_Minigame._17C0 / 60 / 20;
        if (t > 3) {
            t = 3;
        }
        Unk3520Obj_SetDelay(obj, t);
    }
}

// .text:0x00137B10 size:0x1E8 mapped:0x80776BA4
u8 fn_3_137B10(Unk3520Obj* obj) {
    int i;
    u8 hit = FALSE;
    Unk3520Fielder* fielder;
    f32 top;
    f32 range;
    f32 dx;
    f32 dz;
    f64 ax;
    f64 az;
    Vec v;

    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameFielderIndex[i] < 0) {
            continue;
        }
        if (g_Minigame.starDashStunType[i] != 0 && g_Minigame.starDashStunType[i] != 3) {
            continue;
        }
        if (obj->_3D != 2 && i != g_Minigame._1D6D) {
            continue;
        }
        fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
        top = fielder->_15C + (fielder->_00C + fielder->pos.y);
        range = top < obj->_0.y ? fielder->_16C : 12.0f;
        if (range < fabs(top - obj->_0.y)) {
            continue;
        }
        ax = fabs(obj->_0.x - fielder->pos.x);
        az = fabs(obj->_0.z - fielder->pos.z);
        dx = ax;
        dz = az;
        if (dx <= 3.5f && dz <= 3.125f) {
            if (i == g_Minigame._1D6D) {
                if (!hit) {
                    v.x = fielder->_038;
                    v.z = fielder->_03C;
                    v.y = 0.0f;
                    hit = TRUE;
                    PSVECScale(&v, lbl_3_data_21A64[2], &v);
                    v.y = lbl_3_data_21A64[3];
                    memcpy(&obj->_C, &v, sizeof(Vec));
                    obj->_24.x = lbl_3_data_21A64[4];
                    obj->_3A = 0;
                    obj->_3D = 4;
                }
            } else {
                g_Minigame.starDashStunType[i] = 1;
                g_Minigame._1CB8[i].x = fielder->pos.x - obj->_0.x;
                g_Minigame._1CB8[i].z = fielder->pos.z - obj->_0.z;
                obj->_3E = 1;
                obj->_3F = 0;
            }
        }
    }
    return hit;
}

// .text:0x001379A0 size:0x170 mapped:0x80776A34
// 90.7%: the unrolled fielder search walks other registers and offsets, and the
// object loop strength-reduces differently.
BOOL fn_3_1379A0(int fielderIdx) {
    Unk3520Fielder* fielder = &g_Fielders[fielderIdx];
    u32 player;
    u32 i;
    Unk3520Obj* obj;
    f32 top;
    f32 range;
    f32 dx;
    f32 dz;
    f64 ax;
    f64 az;

    for (player = 0; player < 4; player++) {
        if (g_Minigame.minigameFielderIndex[player] == fielderIdx) {
            break;
        }
    }
    if (player == g_Minigame._1D6D) {
        return FALSE;
    }
    for (i = 0; i < lbl_3_bss_B780; i++) {
        obj = &MG.objs[i];
        if (obj->_3D != 3 && obj->_3D != 5) {
            continue;
        }
        top = fielder->_15C + (fielder->_00C + fielder->pos.y);
        range = top < obj->_0.y ? fielder->_16C : 12.0f;
        if (range < fabs(top - obj->_0.y)) {
            continue;
        }
        ax = fabs(obj->_0.x - (fielder->pos.x + fielder->_030));
        az = fabs(obj->_0.z - (fielder->pos.z + fielder->_034));
        dx = ax;
        dz = az;
        if (dx < 3.5f && dz < 3.125f) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x001373E0 size:0x5C0 mapped:0x80776474
// 92.9%: the half-size constants are loaded through addi where the target loads them
// directly, and the plane intersection schedules its stores differently.
u8 fn_3_1373E0(VecSrcDst* seg, Vec* vel, VecSrcDst* out, f32 radius) {
    f32 planes[4][3] = { { -1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, -1.0f, 0.0f } };
    Vec hit;
    Vec d1;
    Vec d3;
    Vec n1;
    Vec d2;
    f32 height = 2.0f * radius;
    f32 halfX = 3.5f + radius;
    f32 halfZ = 3.125f + radius;
    f32* plane;
    f32 limit;
    f32 t;
    f32 nx;
    f32 nz;
    u32 i;
    u8 outside;
    Unk3520Obj* obj;

    for (i = 0; i < lbl_3_bss_B780; i++) {
        obj = &MG.objs[i];
        outside = TRUE;
        if (!(obj->_3D > 1 || obj->_3D == 4)) {
            continue;
        }
        limit = obj->_0.y > -seg->dst.y ? height : 12.0f;
        if (limit < fabs(obj->_0.y + seg->dst.y)) {
            continue;
        }
        PSVECSubtract(&seg->dst, &obj->_0, &d1);
        if (fabs(d1.x) > halfX) {
            continue;
        }
        if (fabs(d1.z) > halfZ) {
            continue;
        }
        if (PSVECMag(&d1) != 0.0f) {
            PSVECNormalize(&d1, &n1);
        } else {
            memset(&n1, 0, sizeof(Vec));
        }
        PSVECSubtract(&seg->dst, &seg->src, &d2);
        if (PSVECMag(&d2) != 0.0f) {
            PSVECNormalize(&d2, &d2);
        } else {
            memset(&d2, 0, sizeof(Vec));
        }
        d2.y = 0.0f;
        n1.y = 0.0f;
        if (PSVECDotProduct(&n1, &d2) > 0.0f) {
            continue;
        }
        PSVECSubtract(&seg->src, &obj->_0, &d3);
        if (fabs(d3.x) <= halfX && fabs(d3.z) <= halfZ) {
            PSVECSubtract(&seg->dst, &seg->src, &d2);
            d2.y = 0.0f;
            if (PSVECMag(&d2) != 0.0f) {
                PSVECNormalize(&d2, &d2);
                outside = FALSE;
                seg->dst.x = seg->src.x;
                seg->dst.z = seg->src.z;
                seg->src.x = 7.0f * d2.x + seg->src.x;
                seg->src.z = 6.25f * d2.z + seg->src.z;
            } else {
                nz = n1.z;
                nx = n1.x;
                if (0.8928571343421936 < fabs(nz / nx)) {
                    nz = fabs(nz) / nz;
                } else if (0.8928571343421936 > fabs(nz / nx)) {
                    nx = fabs(nx) / nx;
                } else {
                    nz = fabs(nz) / nz;
                    nx = fabs(nx) / nx;
                }
                out->src.x = nx * halfX + obj->_0.x;
                out->src.y = -seg->src.y;
                out->src.z = nz * halfZ + obj->_0.z;
                out->dst.x = -1.0f * vel->x;
                out->dst.y = vel->y;
                out->dst.z = -1.0f * vel->z;
                return TRUE;
            }
        }
        PSVECSubtract(&seg->dst, &seg->src, &d2);
        plane = d2.x > 0.0f ? planes[0] : planes[1];
        plane[2] = plane[0] * (halfX * (fabs(plane[0]) / plane[0]) + obj->_0.x);
        t = -((plane[0] * seg->src.x + plane[1] * seg->src.z) - plane[2]) / (plane[0] * d2.x + plane[1] * d2.z);
        hit.x = d2.x * t + seg->src.x;
        hit.z = d2.z * t + seg->src.z;
        hit.y = -seg->src.y;
        if (fabs(hit.z - obj->_0.z) <= halfZ && t >= 0.0f) {
            memcpy(&out->dst, vel, sizeof(Vec));
            out->dst.x *= -1.0f;
        } else {
            plane = d2.z > 0.0f ? planes[3] : planes[2];
            plane[2] = plane[1] * (obj->_0.z + halfZ * fabs(plane[1]) / plane[1]);
            t = -((plane[0] * seg->src.x + plane[1] * seg->src.z) - plane[2]) / (plane[0] * d2.x + plane[1] * d2.z);
            hit.x = d2.x * t + seg->src.x;
            hit.z = d2.z * t + seg->src.z;
            hit.y = -seg->src.y;
            memcpy(&out->dst, vel, sizeof(Vec));
            out->dst.z *= -1.0f;
        }
        if (outside) {
            memcpy(&out->src, &hit, sizeof(Vec));
        } else {
            seg->dst.y *= -1.0f;
            memcpy(&out->src, &seg->dst, sizeof(Vec));
        }
        return TRUE;
    }
    return FALSE;
}

// .text:0x00137224 size:0x1BC mapped:0x807762B8
void fn_3_137224(Vec* center) {
    u32 i;
    Vec pos;
    Vec d;
    Vec v;
    f32 scale;

    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] != 1) {
            continue;
        }
        if (g_Minigame.wallBall_coinCoordinates[i].y > lbl_3_data_219B8[14]) {
            continue;
        }
        if (g_Minigame.wallBall_coinVelocity[i].y > 0.05) {
            continue;
        }
        pos.x = g_Minigame.wallBall_coinCoordinates[i].x;
        pos.y = g_Minigame.wallBall_coinCoordinates[i].y;
        pos.z = g_Minigame.wallBall_coinCoordinates[i].z;
        PSVECSubtract(&pos, center, &d);
        scale = (36.0f - PSVECMag(&d)) / 36.0f;
        d.y = 0.0f;
        if (!PSVECMag(&d)) {
            d.z = -1.0f;
        }
        PSVECNormalize(&d, &d);
        v.x = 0.0f;
        v.z = 0.0f;
        v.y = 0.05f * (2.0 * (rand() / 32767.0f - 0.5)) + 0.3f;
        PSVECScale(&v, scale, &v);
        PSVECAdd(&v, (Vec*)&g_Minigame.wallBall_coinVelocity[i], (Vec*)&g_Minigame.wallBall_coinVelocity[i]);
    }
}

// .text:0x001371E8 size:0x3C mapped:0x8077627C
void fn_3_1371E8(void) {
    lbl_3_bss_B702 = lbl_3_data_21AF0[0];
    fn_800528AC(fn_3_1370A0);
}

// .text:0x001370A0 size:0x148 mapped:0x80776134
void fn_3_1370A0(camera_803c639c_s* camera) {
    Vec shake;
    Mtx inv;

    memset(&shake, 0, sizeof(Vec));
    shake.y = lbl_3_data_21AF4 * (2.0 * (rand() / 32767.0f - 0.5));
    PSMTXInverse(camera->view, inv);
    PSMTXMultVecSR(inv, &shake, &shake);
    camera->eye.x += shake.x;
    camera->eye.y += shake.y;
    camera->eye.z += shake.z;
    camera->target.x += shake.x;
    camera->target.y += shake.y;
    camera->target.z += shake.z;
    if (--lbl_3_bss_B702 <= 0) {
        lbl_3_bss_B702 = 0;
        fn_800528B4();
    }
}

// .text:0x00136EA4 size:0x1FC mapped:0x80775F38
void fn_3_136EA4(void) {
    if (g_Minigame.turnOverStatus != 0) {
        g_Minigame.playerIDWithPowerup[0] = -1;
        MG.box._1E = 0;
    } else if (MG.box._1E != 0) {
        fn_3_13688C(&MG.box);
    } else {
        fn_3_136CF4(&MG.box);
    }
}

// .text:0x00136CF4 size:0x1B0 mapped:0x80775D88
void fn_3_136CF4(Unk3520Box* box) {
    s8 chance;
    f32 angle;

    if (g_Minigame.playerIDWithPowerup[0] != -1) {
        if (--g_Minigame._1D58 <= 0) {
            if (g_Minigame._1D6D != g_Minigame.playerIDWithPowerup[0]) {
                fn_800115C8(g_Minigame.playerIDWithPowerup[0]);
            }
            g_Minigame.playerIDWithPowerup[0] = -1;
        }
    } else {
        box->_1C--;
        if (box->_1C <= 0) {
            chance = rand() % 100 - lbl_3_data_21B16;
            if (chance < 0) {
                box->_1E = 1;
            } else {
                box->_1E = 2;
            }
            box->pos.x = lbl_3_data_219AC.x;
            box->pos.y = lbl_3_data_219AC.y;
            box->pos.z = lbl_3_data_219AC.z;
            box->vel.y = lbl_3_data_21AF8[0];
            angle = 0.017453292f * (360.0f * (rand() / 32767.0f));
            box->vel.x = lbl_3_data_21AF8[1] * cosf_kludge(angle);
            box->vel.z = lbl_3_data_21AF8[1] * sinf_kludge(angle);
            box->_1C = lbl_3_data_21B10[1];
        }
    }
}

// .text:0x0013688C size:0x468 mapped:0x80775920
void fn_3_13688C(Unk3520Box* box) {
    VecSrcDst seg;
    CollisionStruct col;
    u32 type;
    f32 radius;
    f32 best;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 reach;
    int i;
    int who;
    Unk3520Fielder* fielder;

    seg.src.x = box->pos.x;
    seg.src.y = -box->pos.y;
    seg.src.z = box->pos.z;
    box->vel.y += lbl_3_data_21AF8[2];
    box->pos.x = box->vel.x + box->pos.x;
    box->pos.y = box->vel.y + box->pos.y;
    box->pos.z = box->vel.z + box->pos.z;
    if (box->pos.y < 0.0f) {
        box->pos.y = 0.0f;
        box->vel.y = 0.0f;
    }
    seg.dst.x = box->pos.x;
    seg.dst.y = -box->pos.y;
    seg.dst.z = box->pos.z;
    type = checkCollision(&seg, &col, 0, FALSE);
    if (type == 5) {
        col.normal.y *= -1.0f;
        fn_3_13ADC0(&box->vel, &box->vel, &col.normal);
        box->pos.x = col.position.x;
        box->pos.y = -col.position.y;
        box->pos.z = col.position.z;
    }
    seg.dst.x = box->pos.x;
    seg.dst.y = -box->pos.y;
    seg.dst.z = box->pos.z;
    if (fn_3_1373E0(&seg, &box->vel, (VecSrcDst*)&col, lbl_3_data_21AF8[3])) {
        box->pos.x = col.position.x;
        box->pos.y = col.position.y;
        box->pos.z = col.position.z;
        memcpy(&box->vel, &col.normal, sizeof(Vec));
        seg.dst.x = box->pos.x;
        seg.dst.y = -box->pos.y;
        seg.dst.z = box->pos.z;
        type = checkCollision(&seg, &col, 0, FALSE);
        if (type == 5) {
            col.normal.y *= -1.0f;
            fn_3_13ADC0(&box->vel, &box->vel, &col.normal);
            box->pos.x = col.position.x;
            box->pos.y = -col.position.y;
            box->pos.z = col.position.z;
        }
    }
    best = 99999.9f;
    radius = lbl_3_data_21AF8[3];
    for (i = 0, who = -1; i < 4; i++) {
        if (g_Minigame.minigameFielderIndex[i] < 0) {
            continue;
        }
        if (g_Minigame.starDashStunType[i] != 0 && g_Minigame.starDashStunType[i] != 3) {
            continue;
        }
        fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
        if (fielder->_203 != 0 && fielder->_204 > 3) {
            continue;
        }
        if (fielder->_16C + fielder->_00C < box->pos.y) {
            continue;
        }
        reach = radius + lbl_3_data_47BC[fielder->_1C9];
        dz = fielder->pos.z - box->pos.z;
        dx = fielder->pos.x - box->pos.x;
        reach *= reach;
        dist = dx * dx + dz * dz;
        if (dist < reach && dist < best) {
            best = dist;
            who = i;
        }
    }
    if (who >= 0) {
        g_Minigame.playerIDWithPowerup[0] = who;
        g_Minigame._1D58 = lbl_3_data_21B10[2];
        if (MG.box._1E == 2) {
            if (g_Minigame._1D6D == who) {
                fn_3_14E988(g_Minigame._1D6D);
                fn_800115C8(who);
                g_Minigame._1D6D = -1;
            }
            g_Minigame.starDashRelated_0_5Or1_5 = &lbl_3_data_21AF8[5];
            fn_3_90064(0x2F5);
            fn_3_1695A4(who, 0);
        } else {
            g_Minigame.starDashRelated_0_5Or1_5 = &lbl_3_data_21AF8[4];
            fn_3_90064(0x2F6);
            fn_3_16C394(who);
        }
        box->_1E = 0;
        box->_1C = lbl_3_data_21B10[0];
    } else {
        box->_1C--;
        if (box->_1C <= 0) {
            box->_1E = 0;
            box->_1C = lbl_3_data_21B10[0];
        }
    }
}

// .text:0x00136220 size:0x66C mapped:0x807752B4
// 99.4%: the collision-type test merges 2 and 3 into one range where the target tests
// each; some FPRs differ in the stun branches.
void fn_3_136220(void) {
    Unk3520Fielder* fielder;
    int i;
    VecSrcDst seg;
    CollisionStruct col;
    f32 xx;
    f32 zz;
    f32 len;
    f32 scale;
    f32 dx;
    f32 dz;
    f32 dist;
    u32 type;

    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameFielderIndex[i] < 0) {
            continue;
        }
        fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
        if (fielder->_20F == 0) {
            if (g_Minigame.starDashStunType[i] == 1) {
                xx = g_Minigame._1CB8[i].x * g_Minigame._1CB8[i].x;
                zz = g_Minigame._1CB8[i].z * g_Minigame._1CB8[i].z;
                len = dolsqrtf2(xx + zz);
                scale = lbl_3_data_21B18[0] / len;
                g_Minigame._1CB8[i].x *= scale;
                g_Minigame._1CB8[i].z *= scale;
                g_Minigame._1CB8[i].y = 0.0f;
                g_Minigame._1D5A[i] = 0;
                g_Minigame.starDashStunType[i] = 2;
                if (g_Minigame.playerIDWithPowerup[0] == i) {
                    fn_800115C8(g_Minigame.playerIDWithPowerup[0]);
                    g_Minigame.playerIDWithPowerup[0] = -1;
                }
                fn_3_1360BC(i);
                fn_3_90064(0x2E7);
                fn_3_90220(fielder->_17A, 10);
                fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[i], 2);
            } else if (g_Minigame.starDashStunType[i] == 2) {
                g_Minigame._1D5A[i]++;
                zz = g_Minigame._1CB8[i].z * g_Minigame._1CB8[i].z;
                xx = g_Minigame._1CB8[i].x * g_Minigame._1CB8[i].x;
                len = dolsqrtf2(xx + zz);
                if (len > 0.0f) {
                    seg.src.x = fielder->pos.x;
                    seg.src.y = -1.0f;
                    seg.src.z = fielder->pos.z;
                    seg.dst.x = 2.0f * g_Minigame._1CB8[i].x + fielder->pos.x;
                    seg.dst.y = -1.0f;
                    seg.dst.z = 2.0f * g_Minigame._1CB8[i].z + fielder->pos.z;
                    type = checkCollision(&seg, &col, 0, FALSE);
                    if (type != 0) {
                        g_Minigame._1CB8[i].x = 0.0f;
                        g_Minigame._1CB8[i].z = 0.0f;
                    }
                    fielder->pos.x += g_Minigame._1CB8[i].x;
                    fielder->pos.y += g_Minigame._1CB8[i].y;
                    fielder->pos.z += g_Minigame._1CB8[i].z;
                    g_Minigame._1CB8[i].x *= lbl_3_data_21B18[1];
                    g_Minigame._1CB8[i].z *= lbl_3_data_21B18[1];
                }
                if (g_Minigame._1D5A[i] > lbl_3_data_21B20[1]) {
                    g_Minigame.starDashStunType[i] = 3;
                    fielder->_030 = 0.0f;
                    fielder->_034 = 0.0f;
                    g_Minigame._1D5A[i] = 0;
                    fielder->_050 = 0.0f;
                }
            } else if (g_Minigame.starDashStunType[i] == 3) {
                g_Minigame._1D5A[i]++;
                if (g_Minigame._1D5A[i] > lbl_3_data_21B20[2]) {
                    g_Minigame.starDashStunType[i] = 0;
                }
            }
        }
        seg.src.x = fielder->pos.x;
        seg.src.y = -1.0f;
        seg.src.z = fielder->pos.z;
        seg.dst.x = fielder->pos.x;
        seg.dst.y = 1.0f;
        seg.dst.z = fielder->pos.z;
        type = checkCollision(&seg, &col, 0, FALSE) & 0x7F;
        if (type == 2 || type == 3 || type == 7 || type == 8 || type == 5) {
            dx = lbl_3_data_4444[8] - fielder->pos.x;
            dz = lbl_3_data_4444[8] - fielder->pos.z;
            dist = dolsqrtf2(dx * dx + dz * dz);
            if (0.0f == dist) {
                fielder->pos.x = lbl_3_data_2198C[i][0];
                fielder->pos.z = lbl_3_data_2198C[i][1];
            } else {
                dx /= dist;
                dz /= dist;
                if (dist < 7.0f) {
                    fielder->pos.x -= 0.2f * dx;
                    fielder->pos.z -= 0.2f * dz;
                } else {
                    fielder->pos.x += 0.2f * dx;
                    fielder->pos.z += 0.2f * dz;
                }
            }
        }
    }
}

// .text:0x001360BC size:0x164 mapped:0x80775150
void fn_3_1360BC(int player) {
    Unk3520Fielder* fielder;
    int count;
    int i;
    int n;
    f32 speed;
    s16 angle;

    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[player]];
    g_Minigame._1DF4_u8[player] = 1;
    count = lbl_3_data_21B20[3];
    if (g_Minigame.miniGameCurrentPoints[player] < count) {
        count = g_Minigame.miniGameCurrentPoints[player];
    }
    if (count == 0) {
        return;
    }
    for (i = 0, n = 0; i < 50; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 0) {
            g_Minigame.wallBall_coinCoordinates[i].x = fielder->pos.x;
            g_Minigame.wallBall_coinCoordinates[i].y = fielder->pos.y;
            g_Minigame.wallBall_coinCoordinates[i].z = fielder->pos.z;
            g_Minigame.wallBall_coinCoordinates[i].y = fielder->_16C;
            g_Minigame.wallBall_coinVelocity[i].y = lbl_3_data_219B8[18];
            angle = random_fn_3_9EE24(0x1000);
            getComponentsFromSAng(angle, &g_Minigame.wallBall_coinVelocity[i].x, &g_Minigame.wallBall_coinVelocity[i].z);
            speed = RandomF32_Game_Range(lbl_3_data_219B8[16], lbl_3_data_219B8[17]);
            g_Minigame.wallBall_coinVelocity[i].x *= speed;
            g_Minigame.wallBall_coinVelocity[i].z *= speed;
            g_Minigame.wallBall_coinsVisibleInd[i] = 1;
            g_Minigame.wallBall_coinsVisibleFrameCounter[i] = 0;
            g_Minigame._1D6C++;
            n++;
            if (n >= count) {
                break;
            }
        }
    }
    fn_3_90064(0x2E8);
    g_Minigame.miniGameCurrentPoints[player] -= count;
}

// .text:0x00136048 size:0x74 mapped:0x807750DC
void fn_3_136048(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        g_Minigame._1D64[i] += lbl_3_data_21A44;
        g_Minigame._1D64[i] = fn_3_9FE6C_normalizeAngle(g_Minigame._1D64[i]);
    }
}

// .text:0x00135FF4 size:0x54 mapped:0x80775088
void fn_3_135FF4(void) {
    u32 frame = lbl_3_data_21A3C[g_Minigame._1D73][0] * 60;

    if (frame == g_Minigame._17C0) {
        g_Minigame._1D72 = 1;
        g_Minigame._1D62 = 0;
        g_Minigame._1D48 = 0.0f;
        g_Minigame._1D73++;
    }
}

// .text:0x00135F4C size:0xA8 mapped:0x80774FE0
void fn_3_135F4C(void) {
    g_Minigame._1D62++;
    g_Minigame._1D48 = (f32)g_Minigame._1D62 / (f32)lbl_3_data_21A60._0;
    fn_3_135C18();
    if (g_Minigame._1D62 >= lbl_3_data_21A60._0) {
        g_Minigame._1D72 = 2;
    }
}

// .text:0x00135E98 size:0xB4 mapped:0x80774F2C
void fn_3_135E98(void) {
    g_Minigame._1D62++;
    g_Minigame._1D48 = 1.0f - (f32)g_Minigame._1D62 / (f32)lbl_3_data_21A60._0;
    fn_3_135C18();
    if (g_Minigame._1D62 >= lbl_3_data_21A60._0) {
        g_Minigame._1D72 = 0;
    }
}

// .text:0x00135E38 size:0x60 mapped:0x80774ECC
void fn_3_135E38(void) {
    u32 frame;

    fn_3_135C18();
    frame = lbl_3_data_21A3C[g_Minigame._1D73 - 1][1] * 60;
    if (frame == g_Minigame._17C0) {
        g_Minigame._1D72 = 3;
        g_Minigame._1D62 = 0;
    }
}

// .text:0x00135C18 size:0x220 mapped:0x80774CAC
void fn_3_135C18(void) {
    f32 inner;
    f32 outer;
    f32 step;
    f32 t;
    f32 x;
    f32 z;
    int i;
    int j;
    int k;

    inner = g_Minigame._1D48 * lbl_3_data_21A54[1] - lbl_3_data_21A54[0];
    step = (lbl_3_data_21A54[1] - lbl_3_data_21A54[0]) / lbl_3_data_21A60._2;
    outer = inner + lbl_3_data_21A54[0];
    for (i = 0, k = 0; i < 4; i++) {
        getComponentsFromSAng(g_Minigame._1D64[i], &x, &z);
        t = inner;
        MG.spokes[i].start.x = x * lbl_3_data_21A54[0] + lbl_3_data_21A48.x;
        MG.spokes[i].start.z = z * lbl_3_data_21A54[0] + lbl_3_data_21A48.z;
        MG.spokes[i].end.x = x * outer + lbl_3_data_21A48.x;
        MG.spokes[i].end.z = z * outer + lbl_3_data_21A48.z;
        x = (MG.spokes[i].end.x - MG.spokes[i].start.x) / inner;
        z = (MG.spokes[i].end.z - MG.spokes[i].start.z) / inner;
        for (j = 0; j < lbl_3_data_21A60._2; j++, k++) {
            MG.pieces[k].pos.x = x * t + MG.spokes[i].start.x;
            MG.pieces[k].pos.z = z * t + MG.spokes[i].start.z;
            if (t < 0.0f) {
                MG.pieces[k]._26 = 0;
            } else {
                t -= step;
                if (MG.pieces[k]._26 != 0) {
                    fn_3_156548(k, MG.pieces[k].pos.x, -MG.pieces[k].pos.y, MG.pieces[k].pos.z);
                } else {
                    fn_3_15730C(k, MG.pieces[k].pos.x, -MG.pieces[k].pos.y, MG.pieces[k].pos.z);
                    MG.pieces[k]._26 = 1;
                }
            }
        }
    }
}

// .text:0x00135A64 size:0x1B4 mapped:0x80774AF8
// 98.1%: registers only; the base of g_Minigame and its walkers take r25 to r27 in
// another order.
void fn_3_135A64(void) {
    int i;
    Unk3520Fielder* fielder;
    int j;
    int angle;
    f32 dist;

    if (g_Minigame.turnOverStatus == 0 && !(g_Minigame._1D48 < 0.3f)) {
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameFielderIndex[i] < 0) {
                continue;
            }
            if (i == g_Minigame._1D6D) {
                continue;
            }
            if (g_Minigame.starDashStunType[i] != 0) {
                continue;
            }
            fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
            if (fielder->_203 != 0 && fielder->_204 > 3) {
                continue;
            }
            angle = fn_3_9FB8C(fielder->pos.x - lbl_3_data_219AC.x, fielder->pos.z - lbl_3_data_219AC.z);
            for (j = 0; j < 4; j++) {
                if (fn_3_9FCF8(angle, g_Minigame._1D64[j]) > 0x200) {
                    continue;
                }
                dist = fn_3_9EFD0(&g_Minigame.starDashSpokes[j][0], &g_Minigame.starDashSpokes[j][1], (VecXYZ*)&fielder->pos, NULL);
                if (dist < lbl_3_data_21A54[2] + lbl_3_data_47BC[fielder->_1C9] && dist >= 0.0f) {
                    fn_3_1360BC(i);
                    g_Minigame.starDashStunType[i] = 3;
                    g_Minigame._1D5A[i] = 0;
                    fn_3_25844(g_Minigame.minigameFielderIndex[i], 2);
                    fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[i], 2);
                    break;
                }
            }
        }
    }
}

// .text:0x00135924 size:0x140 mapped:0x807749B8
void fn_3_135924(void) {
    u32 i;

    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 1 && g_Minigame.wallBall_coinCoordinates[i].y < 3.0f) {
            fn_3_13583C((Vec*)&g_Minigame.wallBall_coinCoordinates[i]);
        }
    }
}

// .text:0x0013583C size:0xE8 mapped:0x807748D0
void fn_3_13583C(Vec* pos) {
    Vec center = { 0.0f, 0.0f, 20.0f };
    Vec d;

    if (pos != NULL) {
        PSVECSubtract(pos, &center, &d);
        d.y = 0.0f;
        if (PSVECMag(&d) <= 3.5f) {
            fn_3_1357A4(pos, &d);
        }
    }
}

// .text:0x001357A4 size:0x98 mapped:0x80774838
void fn_3_1357A4(Vec* pos, Vec* dir) {
    Vec base = { 0.0f, 0.0f, 20.0f };
    Vec n;

    if (!pos || !dir) {
        return;
    }
    PSVECNormalize(dir, &n);
    PSVECScale(&n, 3.5f, &n);
    pos->x = base.x + n.x;
    pos->z = base.z + n.z;
}

// .text:0x001356F8 size:0xAC mapped:0x8077478C
// 99.0%: cpu and the aIStrength walker swap r26 and r27; fn_3_13BB30, which inlines
// this, matches.
void fn_3_1356F8(void) {
    Unk3520Cpu* cpu = (Unk3520Cpu*)&g_Minigame._1DCC;
    u8 strength;
    u32 i;

    memset(g_Minigame._1D7C, 0, 0x78);
    for (i = 0; i < 4; cpu++, i++) {
        strength = g_Minigame.minigameControlStruct.aIStrength[i];
        cpu->_4 = -1;
        cpu->_0 = RandomInt_Game(100) < lbl_3_data_21B88[strength] ? 3.0f : 1.5f;
    }
}

// .text:0x00135698 size:0x60 mapped:0x8077472C
int fn_3_135698(const void* a, const void* b) {
    if (((Unk3520Coin*)a)->valid != 0 && ((Unk3520Coin*)b)->valid == 0) {
        return -1;
    }
    if (((Unk3520Coin*)a)->valid == 0 && ((Unk3520Coin*)b)->valid != 0) {
        return 1;
    }
    if (((Unk3520Coin*)a)->score < ((Unk3520Coin*)b)->score) {
        return -1;
    }
    return ((Unk3520Coin*)a)->score > ((Unk3520Coin*)b)->score;
}

// .text:0x0013564C size:0x4C mapped:0x807746E0
int fn_3_13564C(f32 x, f32 z) {
    if (x >= 0.0f) {
        if (z >= 0.0f) {
            return 0;
        }
        return 3;
    }
    if (z >= 0.0f) {
        return 1;
    }
    return 2;
}

// .text:0x00135600 size:0x4C mapped:0x80774694
void fn_3_135600(f32* outX, f32* outZ, f32 x, f32 z) {
    Unk3520Ai* ai = (Unk3520Ai*)&g_Minigame._1DCC;

    x -= lbl_3_data_21A48.x;
    z -= lbl_3_data_21A48.z;
    *outX = x * ai->cos - z * ai->sin;
    *outZ = x * ai->sin + z * ai->cos;
}

// .text:0x00135520 size:0xE0 mapped:0x807745B4
// Written with the else-ifs and gotos, it is long enough by MWCC's measure to stay a
// call in fn_3_1350BC and fn_3_13334C, as in the target.
u32 fn_3_135520(f32 x, f32 z, f32 r) {
    if (x >= 0.0f) {
        if (z >= 0.0f) {
            if (z <= r) {
                return 1;
            } else if (x <= r) {
                return 2;
            }
            goto out;
        } else {
            if (x <= r) {
                return 1;
            } else if (z >= -r) {
                return 2;
            }
            goto out;
        }
    } else {
        if (z >= 0.0f) {
            if (x >= -r) {
                return 1;
            } else if (z <= r) {
                return 2;
            }
            goto out;
        } else {
            if (z >= -r) {
                return 1;
            } else if (x >= -r) {
                return 2;
            }
            goto out;
        }
    }
out:
    return 0;
}

// .text:0x001354BC size:0x64 mapped:0x80774550
BOOL fn_3_1354BC(s32 i, f32 x, f32 z) {
    BOOL ret = FALSE;
    Unk3520Minigame* mg = &MG;
    f64 ax = fabs(mg->objs[i]._0.x - x);
    f64 az = fabs(mg->objs[i]._0.z - z);
    f32 dx = ax;
    f32 dz = az;

    if (dx <= 4.7f && dz <= 4.325f) {
        ret = TRUE;
    }
    return ret;
}

// .text:0x001350BC size:0x400 mapped:0x80774150
// 92.1%: the inlined fn_3_1354BC forms its own g_Minigame base where the target shares
// the objs walker (with `s32 j` and MG.objs[i] there, 97.0%, but fn_3_1354BC drops to 83%).
Unk3520Coin* fn_3_1350BC(u32 player, u32 quadrant, u32 count, Unk3520Coin* coins) {
    u32 strength = g_Minigame.minigameControlStruct.aIStrength[player];
    Unk3520Coin* c;
    u32 i;
    u32 j;
    u32 k;
    f32 x;
    f32 z;
    f32 dx;
    f32 dz;
    f32 dist;
    Unk3520Fielder* fielder;

    if (count != 0) {
        i = 0;
        c = coins;
        do {
            c->valid = TRUE;
            z = g_Minigame.wallBall_coinCoordinates[c->coin].z;
            x = g_Minigame.wallBall_coinCoordinates[c->coin].x;
            dz = z - lbl_3_data_21A48.z;
            dx = x - lbl_3_data_21A48.x;
            if (dx * dx + dz * dz < 20.25f) {
                c->valid = FALSE;
            } else if (player != g_Minigame._1D6D) {
                if (g_Minigame._1D6D >= 0) {
                    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame._1D6D]];
                    dz = z - fielder->pos.z;
                    dx = x - fielder->pos.x;
                    if (dx * dx + dz * dz <= lbl_3_data_21B38[strength] * lbl_3_data_21B38[strength]) {
                        c->valid = FALSE;
                    }
                }
                if (c->valid) {
                    j = 0;
                    do {
                        if (MG.objs[j]._3D >= 1 && MG.objs[j]._3D <= 3 && fn_3_1354BC(j, x, z)) {
                            c->valid = FALSE;
                            break;
                        }
                    } while (++j < lbl_3_data_21A88[g_Minigame.soloMinigameDifficulty]);
                }
                if (c->valid && MG.box._1E == 2) {
                    dz = z - MG.box.pos.z;
                    dx = x - MG.box.pos.x;
                    if (dx * dx + dz * dz <= lbl_3_data_21B58[strength] * lbl_3_data_21B58[strength]) {
                        c->valid = FALSE;
                    }
                }
            }
            fielder = &g_Fielders[g_Minigame.minigameFielderIndex[player]];
            dz = g_Minigame.wallBall_coinCoordinates[c->coin].z - fielder->pos.z;
            dx = g_Minigame.wallBall_coinCoordinates[c->coin].x - fielder->pos.x;
            c->score = dx * dx + dz * dz;
            for (k = 0; k < g_Minigame.miniGameNumberOfParticipants; k++) {
                if (k == player) {
                    continue;
                }
                fielder = &g_Fielders[g_Minigame.minigameFielderIndex[k]];
                dz = g_Minigame.wallBall_coinCoordinates[c->coin].z - fielder->pos.z;
                dx = g_Minigame.wallBall_coinCoordinates[c->coin].x - fielder->pos.x;
                dist = dx * dx + dz * dz;
                if (dist < 36.0f && dist < c->score) {
                    c->score += 100.0f;
                }
            }
            if (g_Minigame._1D72 != 0 && player != g_Minigame._1D6D) {
                if (c->quadrant == ((quadrant + 1) & 3)) {
                    c->score += 10000.0f;
                } else if (c->quadrant == ((quadrant + 2) & 3)) {
                    c->score += 400.0f;
                }
                if (fn_3_135520(c->x, c->z, 2.0f * lbl_3_data_21A54[2])) {
                    c->valid = FALSE;
                }
            }
            c++;
        } while (++i < count);
        fn_800246D4(fn_3_135698, coins, coins, sizeof(Unk3520Coin), count);
        return coins;
    }
    return NULL;
}

// .text:0x00134D4C size:0x370 mapped:0x80773DE0
// 96.5%: FPRs only; dx and dz land in f8 and f2 where the target reuses f1 and f0.
u32 fn_3_134D4C(f32 cx, f32 cz, f32 radius, f32 px, f32 pz, f32 qx, f32 qz) {
    f32 dx = cx - px;
    f32 dz = cz - pz;
    f32 dist;
    f32 ux;
    f32 uz;
    f32 len;
    f32 t;
    f32 h;
    f32 dx2;
    f32 dz2;
    f32 ux2;
    f32 uz2;

    dx2 = dx * dx;
    dz2 = dz * dz;
    dist = dolsqrtf2(dx2 + dz2);
    ux = qx - px;
    uz = qz - pz;
    ux2 = ux * ux;
    uz2 = uz * uz;
    len = dolsqrtf2(ux2 + uz2);
    ux /= len;
    uz /= len;
    t = dx * ux + dz * uz;
    if (dist < radius) {
        return 1;
    }
    if (dist == radius && t > 0.0f) {
        return 2;
    }
    if (t > 0.0f) {
        h = t * t + (radius * radius - dist * dist);
        if (h >= 0.0f && t - dolsqrtf2(h) <= len) {
            return 3;
        }
    }
    return 0;
}

// .text:0x00134C80 size:0xCC mapped:0x80773D14
u32 fn_3_134C80(u32 player, u32 quadrant, u32 target, f32 x, f32 z) {
    if (g_Minigame._1D72 != 0 && player != g_Minigame._1D6D) {
        if (target == ((quadrant + 1) & 3) || target == ((quadrant + 2) & 3)) {
            return TRUE;
        }
    }
    return !!fn_3_134D4C(lbl_3_data_21A48.x, lbl_3_data_21A48.z, 4.5f, g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.x,
                       g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.z, x, z);
}

// .text:0x0013493C size:0x344 mapped:0x807739D0
// 99.8%: only the inlined fn_3_135600 swaps its two base registers.
int fn_3_13493C(u32 player, f32* x, f32* z, u32 depth) {
    f32 angle;
    f32 x1;
    f32 z1;
    f32 x2;
    f32 z2;
    f32 d1;
    f32 d2;
    f32 dx;
    f32 dz;
    f32 rx;
    f32 rz;

    dx = *x - g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.x;
    dz = *z - g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.z;
    angle = atan2(dz, dx);
    if (g_Minigame._1D72 != 0 && player != g_Minigame._1D6D) {
        angle += 1.5707964f;
        angle = fn_3_9FEA8(angle);
        *x = 8.0f * cosf_kludge(angle) + lbl_3_data_21A48.x;
        *z = 8.0f * sinf_kludge(angle) + lbl_3_data_21A48.z;
    } else {
        angle -= 1.5707964f;
        angle = fn_3_9FEA8(angle);
        x1 = 8.0f * cosf_kludge(angle) + lbl_3_data_21A48.x;
        z1 = 8.0f * sinf_kludge(angle) + lbl_3_data_21A48.z;
        dx = x1 - g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.x;
        dz = z1 - g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.z;
        d1 = dz + (dx * dx + dz);
        angle += 3.1415927f;
        angle = fn_3_9FEA8(angle);
        x2 = 8.0f * cosf_kludge(angle) + lbl_3_data_21A48.x;
        z2 = 8.0f * sinf_kludge(angle) + lbl_3_data_21A48.z;
        dx = x2 - g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.x;
        dz = z2 - g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.z;
        d2 = dz + (dx * dx + dz);
        if (d1 < d2) {
            *x = x1;
            *z = z1;
        } else {
            *x = x2;
            *z = z2;
        }
    }
    if (depth != 0 && fn_3_134D4C(lbl_3_data_21A48.x, lbl_3_data_21A48.z, 4.5f, g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.x,
                                  g_Fielders[g_Minigame.minigameFielderIndex[player]].pos.z, *x, *z)) {
        fn_3_13493C(player, x, z, depth - 1);
    }
    fn_3_135600(&rx, &rz, *x, *z);
    return fn_3_13564C(rx, rz);
}

// .text:0x00134918 size:0x24 mapped:0x807739AC
int fn_3_134918(const void* a, const void* b) {
    if (((Unk3520Target*)a)->dist < ((Unk3520Target*)b)->dist) {
        return -1;
    }
    return ((Unk3520Target*)a)->dist > ((Unk3520Target*)b)->dist;
}

// .text:0x00134908 size:0x10 mapped:0x8077399C
int fn_3_134908(const void* a, const void* b) {
    return ((Unk3520Target*)b)->points - ((Unk3520Target*)a)->points;
}

// .text:0x00134658 size:0x2B0 mapped:0x807736EC
// 98.0%: the first loop walks targets and g_Minigame in registers off by one.
void fn_3_134658(u32 self, f32* x, f32* z, u32* quadrant) {
    Unk3520Target targets[4];
    Unk3520Target* target = targets;
    Unk3520Target* best = targets;
    u32 i;
    u32 n = 0;
    f32 dx;
    f32 dz;

    i = 0;
    do {
        if (i != self && g_Minigame.starDashStunType[i] == 0 && g_Fielders[g_Minigame.minigameFielderIndex[i]]._20F == 0) {
            n++;
            dx = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.x - g_Fielders[g_Minigame.minigameFielderIndex[self]].pos.x;
            dz = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.z - g_Fielders[g_Minigame.minigameFielderIndex[self]].pos.z;
            target->dist = dx * dx + dz * dz;
            target->points = g_Minigame.miniGameCurrentPoints[i];
            target->player = i;
            target++;
        }
    } while (++i < 4);
    if (n == 0) {
        return;
    }
    fn_800246D4(fn_3_134918, targets, targets, sizeof(Unk3520Target), n);
    i = 0;
    do {
        if (best->dist <= 4.0f && best->points > 0) {
            *x = g_Fielders[g_Minigame.minigameFielderIndex[targets[i].player]].pos.x;
            *z = g_Fielders[g_Minigame.minigameFielderIndex[targets[i].player]].pos.z;
            *quadrant = fn_3_13564C(*x, *z);
            return;
        }
        best++;
    } while (++i < n);
    fn_800246D4(fn_3_134908, targets, targets, sizeof(Unk3520Target), n);
    if (targets[0].points > 0) {
        *x = g_Fielders[g_Minigame.minigameFielderIndex[targets[0].player]].pos.x;
        *z = g_Fielders[g_Minigame.minigameFielderIndex[targets[0].player]].pos.z;
        *quadrant = fn_3_13564C(*x, *z);
    }
}

// .text:0x001345AC size:0xAC mapped:0x80773640
s16 fn_3_1345AC(s16 angle, s16 target, int speed) {
    s16 step;

    if (angle < 0 || target < 0) {
        return target;
    }
    step = fn_3_9FCA4(target, angle) / lbl_3_data_21B8C[speed];
    if (step == 0 || __abs(step) > 1500) {
        return target;
    }
    return fn_3_9FE6C_normalizeAngle(angle + step);
}

// .text:0x001344BC size:0xF0 mapped:0x80773550
BOOL fn_3_1344BC(int a, int b) {
    f32 ax = g_Fielders[g_Minigame.minigameFielderIndex[a]].pos.x - lbl_3_data_21A48.x;
    f32 az = g_Fielders[g_Minigame.minigameFielderIndex[a]].pos.z - lbl_3_data_21A48.z;
    f32 bx = g_Fielders[g_Minigame.minigameFielderIndex[b]].pos.x - lbl_3_data_21A48.x;
    f32 bz = g_Fielders[g_Minigame.minigameFielderIndex[b]].pos.z - lbl_3_data_21A48.z;
    f32 angA = atan2(az, ax);
    f32 angB = atan2(bz, bx);

    return fn_3_9FCA4(radToShortAngle(angA), radToShortAngle(angB)) >= 0;
}

// The angle around the center from player i's fielder, turned by offset
static inline s16 Unk3520_CircleAngle(int i, int offset) {
    return fn_3_9FE6C_normalizeAngle(
        radToShortAngle(atan2(-(g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.x - lbl_3_data_21A48.x),
                              g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.z - lbl_3_data_21A48.z)) + offset);
}

// .text:0x0013334C size:0x1170 mapped:0x807723E0
// 95.7%: the loops over MG.objs and the players walk other registers, and the inlined
// fn_3_1344BC indexes g_Minigame through a walker where the target uses i.
void fn_3_13334C(void) {
    Unk3520Ai* ai = (Unk3520Ai*)&g_Minigame._1DCC;
    Unk3520Coin* coins;
    Unk3520Coin* coin;
    Unk3520Fielder* fielder;
    InputStruct* input;
    u32 count;
    int starQuadrant;
    int bagQuadrant;
    int boxQuadrant;
    u32 target;
    u32 quadrant;
    f32 tx;
    f32 tz;
    f32 x;
    f32 z;
    f32 dx;
    f32 dz;
    s16 away;
    s16 tangent;
    int offset;
    u8 strength;
    s8 character;
    s8 i;
    s8 j;

    coins = _OSAllocFromHeap(4, 50 * sizeof(Unk3520Coin));
    fn_3_133320();
    ai->sin = sin(-fn_3_9FDD8(g_Minigame._1D64[0]));
    ai->cos = cos(-fn_3_9FDD8(g_Minigame._1D64[0]));
    if (g_Minigame._72A != 0) {
        fn_3_135600(&x, &z, g_Minigame._6E8, g_Minigame._6F0);
        starQuadrant = fn_3_13564C(x, z);
    } else {
        starQuadrant = 4;
    }
    if (MG.bag.active != 0) {
        fn_3_135600(&x, &z, MG.bag.pos.x, MG.bag.pos.z);
        bagQuadrant = fn_3_13564C(x, z);
    } else {
        bagQuadrant = 4;
    }
    if (MG.box._1E == 1) {
        fn_3_135600(&x, &z, MG.box.pos.x, MG.box.pos.z);
        boxQuadrant = fn_3_13564C(x, z);
    } else {
        boxQuadrant = 4;
    }
    count = 0;
    coin = coins;
    i = 0;
    do {
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 1) {
            coin->coin = i;
            fn_3_135600(&coin->x, &coin->z, g_Minigame.wallBall_coinCoordinates[i].x, g_Minigame.wallBall_coinCoordinates[i].z);
            coin->quadrant = fn_3_13564C(coin->x, coin->z);
            coin++;
            count++;
        }
    } while (++i < 100);
    i = 0;
    do {
        character = g_Minigame.minigameControlStruct.characterIndex[i];
        if (character < 0 || character >= 4 || g_Minigame.minigameControlStruct.battingHandedness[i] == 0) {
            continue;
        }
        g_Minigame._1DC8[character] = 1;
        memset(&g_Minigame._1D7C[character], 0, sizeof(InputStruct));
        g_Minigame._1D7C[character].controlStickAngle = -1;
        input = &g_Minigame._1D7C[character];
        strength = g_Minigame.minigameControlStruct.aIStrength[i];
        fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
        fn_3_135600(&x, &z, fielder->pos.x, fielder->pos.z);
        quadrant = fn_3_13564C(x, z);
        switch (ai->cpu[i]._6) {
        case 0:
            if (lbl_803CBBC0 != 0 && g_FieldingLogic._000[i]._08 <= lbl_3_data_21B28[strength] &&
                (g_Minigame._1D72 == 0 || i == g_Minigame._1D6D || fn_3_135520(x, z, 5.0f) == 0)) {
                g_Minigame._1D7C[character].buttonInput = g_Minigame._1D7C[character].newButtonInput |= 0x200;
            }
            target = 4;
            if (i == g_Minigame._1D6D) {
                fn_3_134658(i, &tx, &tz, &target);
            }
            if (target == 4 && g_Minigame._72A != 0) {
                tx = g_Minigame._6E8;
                tz = g_Minigame._6F0;
                target = starQuadrant;
            }
            if (target == 4 && MG.bag.active != 0) {
                dz = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.z - MG.bag.pos.z;
                dx = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.x - MG.bag.pos.x;
                if (dx * dx + dz * dz <= lbl_3_data_21B78[strength] * lbl_3_data_21B78[strength]) {
                    j = 0;
                    do {
                        if (MG.objs[j]._3D >= 1 && MG.objs[j]._3D <= 3 && fn_3_1354BC(j, MG.bag.pos.x, MG.bag.pos.z)) {
                            break;
                        }
                    } while (++j < lbl_3_data_21A88[g_Minigame.soloMinigameDifficulty]);
                    if (j >= lbl_3_data_21A88[g_Minigame.soloMinigameDifficulty]) {
                        tx = MG.bag.pos.x;
                        tz = MG.bag.pos.z;
                        target = bagQuadrant;
                    }
                }
            }
            if (target == 4 && MG.box._1E == 1) {
                dz = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.z - MG.box.pos.z;
                dx = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.x - MG.box.pos.x;
                if (dx * dx + dz * dz <= lbl_3_data_21B68[strength] * lbl_3_data_21B68[strength]) {
                    j = 0;
                    do {
                        if (MG.objs[j]._3D >= 1 && MG.objs[j]._3D <= 3 && fn_3_1354BC(j, MG.box.pos.x, MG.box.pos.z)) {
                            break;
                        }
                    } while (++j < lbl_3_data_21A88[g_Minigame.soloMinigameDifficulty]);
                    if (j >= lbl_3_data_21A88[g_Minigame.soloMinigameDifficulty]) {
                        tx = MG.box.pos.x;
                        tz = MG.box.pos.z;
                        target = boxQuadrant;
                    }
                }
            }
            if (target == 4 && g_Minigame._17C4 != 0) {
                coin = fn_3_1350BC(i, quadrant, count, coins);
                if (coin != NULL && coin->valid) {
                    tx = g_Minigame.wallBall_coinCoordinates[coin->coin].x;
                    tz = g_Minigame.wallBall_coinCoordinates[coin->coin].z;
                    target = coin->quadrant;
                }
            }
            if (target != 4) {
                if (fn_3_134C80(i, quadrant, target, tx, tz)) {
                    target = fn_3_13493C(i, &tx, &tz, 2);
                }
                input->controlStickAngle = fn_3_1345AC(ai->cpu[i]._4,
                    radToShortAngle(atan2(tz - g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.z,
                                          tx - g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.x)),
                    strength);
            }
            if (g_Minigame._1D6D >= 0 && i != g_Minigame._1D6D) {
                dz = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.z - g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame._1D6D]].pos.z;
                dx = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.x - g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame._1D6D]].pos.x;
                if (dx * dx + dz * dz <= lbl_3_data_21B38[strength] * lbl_3_data_21B38[strength]) {
                    offset = fn_3_1344BC(g_Minigame._1D6D, i) ? 0 : 0x800;
                    away = radToShortAngle(atan2(dz, dx));
                    tangent = Unk3520_CircleAngle(i, offset);
                    input->controlStickAngle = fn_3_9FE6C_normalizeAngle(radToShortAngle(atan2(dz, dx)) + fn_3_9FCA4(tangent, away) / 2);
                }
            }
            if (i != g_Minigame._1D6D) {
                j = 0;
                do {
                    if (MG.objs[j]._3D >= 1 && MG.objs[j]._3D <= 3) {
                        dz = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.z - MG.objs[j]._0.z;
                        dx = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.x - MG.objs[j]._0.x;
                        if (dx * dx + dz * dz <= lbl_3_data_21B48[strength] * lbl_3_data_21B48[strength]) {
                            away = radToShortAngle(atan2(dz, dx));
                            input->controlStickAngle = fn_3_1345AC(input->controlStickAngle,
                                fn_3_9FE6C_normalizeAngle(input->controlStickAngle + fn_3_9FCA4(away, input->controlStickAngle) / 2),
                                strength);
                        }
                    }
                } while (++j < lbl_3_data_21A88[g_Minigame.soloMinigameDifficulty]);
            }
            if (MG.box._1E == 2) {
                dz = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.z - MG.box.pos.z;
                dx = g_Fielders[g_Minigame.minigameFielderIndex[i]].pos.x - MG.box.pos.x;
                if (dx * dx + dz * dz <= lbl_3_data_21B58[strength] * lbl_3_data_21B58[strength]) {
                    away = radToShortAngle(atan2(dz, dx));
                    input->controlStickAngle = fn_3_1345AC(input->controlStickAngle,
                        fn_3_9FE6C_normalizeAngle(input->controlStickAngle + fn_3_9FCA4(away, input->controlStickAngle) / 2),
                        strength);
                }
            }
            if (g_Minigame._1D72 != 0 && i != g_Minigame._1D6D) {
                if (fn_3_135520(x, z, 0.20943952f * dolsqrtf2(x * x + z * z) + ai->cpu[i]._0) == 1) {
                    ai->cpu[i]._0 = RandomInt_Game(100) < lbl_3_data_21B88[strength] ? 3.0f : 1.5f;
                    input->controlStickAngle = Unk3520_CircleAngle(i, 0);
                    ai->cpu[i]._6 = 1;
                }
            }
            break;
        case 1:
            ai->cpu[i]._7 = 1;
            ai->cpu[i]._6 = 2;
        case 2:
            input->controlStickAngle = Unk3520_CircleAngle(i, 0);
            if (ai->cpu[i]._7-- <= 0) {
                g_Minigame._1D7C[character].buttonInput |= 0x100;
                g_Minigame._1D7C[character].newButtonInput |= 0x100;
                ai->cpu[i]._6 = 3;
            }
            break;
        case 3:
            if (fielder->_203 == 0) {
                ai->cpu[i]._6 = 0;
            }
            break;
        }
        ai->cpu[i]._4 = input->controlStickAngle;
    } while (++i < 4);
    fn_800ACFB0(coins);
}

// .text:0x00133320 size:0x2C mapped:0x807723B4
void fn_3_133320(void) {
    s8 i;

    i = 0;
    do {
        g_Minigame._1DC8[i] = 0;
    } while (++i < 4);
}

// .text:0x00133200 size:0x120 mapped:0x80772294
void fn_3_133200(void) {
    u32 y;
    u32 x;
    u32 offset;

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            offset = fn_800247E4(x, y, 4, 4);
            if (offset < 32) {
                lbl_3_bss_B740[offset + 0] = lbl_3_bss_B740[offset + 2] = 255;
                lbl_3_bss_B740[offset + 1] = lbl_3_bss_B740[offset + 3] = 150;
            } else {
                lbl_3_bss_B740[offset + 0] = lbl_3_bss_B740[offset + 2] = 150;
                lbl_3_bss_B740[offset + 1] = lbl_3_bss_B740[offset + 3] = 150;
            }
        }
    }
    GXInitTexObj(&lbl_3_bss_B708, lbl_3_bss_B740, 4, 4, GX_TF_RGBA8, GX_REPEAT, GX_REPEAT, GX_FALSE);
    GXInitTexObjLOD(&lbl_3_bss_B708, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    lbl_3_data_26580 = -1;
    lbl_3_bss_B704 = 0;
}

// .text:0x001330E4 size:0x11C mapped:0x80772178
void fn_3_1330E4(void) {
    int value;
    int i;

    lbl_3_bss_B704 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_B704 & 1) == 0) {
        value = lbl_3_bss_B740[fn_800247E4(0, 0, 4, 4)];
        value += lbl_3_data_26580 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            lbl_3_bss_B740[i] = value;
        }
        DCFlushRange(lbl_3_bss_B740, 0x40);
        if (value + lbl_3_data_26580 * 2 > 255 || value + lbl_3_data_26580 * 2 < 0) {
            lbl_3_data_26580 *= -1;
        }
    }
}

// .text:0x00132EDC size:0x208 mapped:0x80771F70
void fn_3_132EDC(void* arg0, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* arg4, u8* arg5) {
    int value;
    int i;

    lbl_3_bss_B704 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_B704 & 1) == 0) {
        value = lbl_3_bss_B740[fn_800247E4(0, 0, 4, 4)];
        value += lbl_3_data_26580 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            lbl_3_bss_B740[i] = value;
        }
        DCFlushRange(lbl_3_bss_B740, 0x40);
        if (value + lbl_3_data_26580 * 2 > 255 || value + lbl_3_data_26580 * 2 < 0) {
            lbl_3_data_26580 *= -1;
        }
    }
    GXLoadTexObj(&lbl_3_bss_B708, *map);
    GXSetTexCoordGen2(*coord, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
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
}
