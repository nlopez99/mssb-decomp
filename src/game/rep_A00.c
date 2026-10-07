#include "game/rep_A00.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "stl/math.h"
#include "Dolphin/mtx.h"
#include "game/rep_1838.h"
#include "game/game_batter.h"
#include "game/rep_540.h"
#include "game/rep_868.h"
#include "game/rep_1200.h"
#include "game/rep_13B8.h"
#include "game/rep_AC8.h"

typedef struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ u8 _18[0x1C - 0x18];
    /* 0x1C */ f32 _1C;
    /* 0x20 */ u8 _20[0x28 - 0x20];
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
    /* 0x2A */ u8 _2A[0x2C - 0x2A];
} UnkA00ReplayEntry; // size: 0x2C

typedef struct {
    /* 0x000 */ UnkA00ReplayEntry _000[13];
    /* 0x23C */ s16 _23C;
    /* 0x23E */ s16 _23E;
    /* 0x240 */ s16 _240[13];
    /* 0x25A */ s16 _25A;
    /* 0x25C */ u8 _25C;
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E;
    /* 0x25F */ u8 _25F;
    /* 0x260 */ s8 _260;
    /* 0x261 */ u8 _261[13];
    /* 0x26E */ u8 _26E[13];
    /* 0x27B */ s8 _27B;
    /* 0x27C */ s8 _27C;
    /* 0x27D */ u8 _27D;
    /* 0x27E */ u8 _27E;
    /* 0x27F */ s8 _27F;
    /* 0x280 */ s8 _280;
} UnkA00Replay;

extern struct {
    /* 0x0 */ UnkA00Replay* _0;
} lbl_3_common_bss_1323C;

typedef struct {
    /* 0x00 */ u8 _00[0x62];
    /* 0x62 */ s16 _62;
    /* 0x64 */ u8 _64[0x68 - 0x64];
    /* 0x68 */ s16 _68;
    /* 0x6A */ s16 _6A;
} UnkA00Actor;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ UnkA00Actor* _2C50[13];
} lbl_8036E548;

typedef struct {
    /* 0x000 */ Vec _000;
    /* 0x00C */ u8 _00C[0x218 - 0xC];
    /* 0x218 */ u8 _218;
    /* 0x219 */ u8 _219[0x268 - 0x219];
} UnkA00Fielder; // size: 0x268

extern UnkA00Fielder g_Fielders[9];

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ u8 _50[0xA6 - 0x50];
    /* 0xA6 */ s16 _A6;
} ScoresA00;

extern ScoresA00 g_Scores;

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32 _34;
    /* 0x38 */ s32 _38;
    /* 0x3C */ s32 _3C;
} UnkA00Mission; // size: 0x40

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x1E - 0x12];
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
    /* 0x22 */ u16 _22;
} UnkA00Task;

extern UnkA00Task* lbl_803CC1B8;

extern struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ s16 _14;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
} lbl_803C5090;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x00 */ u8 _00[0x9A];
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B[0xAE - 0x9B];
    /* 0xAE */ u8 _AE;
    /* 0xAF */ u8 _AF;
    /* 0xB0 */ u8 _B0;
    /* 0xB1 */ u8 _B1;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
    /* 0x42 */ u8 _42[0x46 - 0x42];
    /* 0x46 */ u8 _46;
} lbl_3_common_bss_37400;

// starMissionCompletionTracker is 0x4508 bytes; the header declares only its leading array
typedef struct {
    /* 0x0000 */ ChallengeTrackingStruct _0000[54];
    /* 0x0AF8 */ u8 _0AF8[0x16C2 - 0xAF8];
    /* 0x16C2 */ s16 _16C2;
    /* 0x16C4 */ u8 _16C4[0x441C - 0x16C4];
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ u8 _441F[0x44F1 - 0x441F];
    /* 0x44F1 */ u8 _44F1;
} UnkA00Challenge;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

typedef struct {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3[3];
} UnkA00CharEntry; // size: 0x6

extern UnkA00CharEntry lbl_800E8558[54];
extern s16 lbl_3_data_7F7C[][4];

void changeScene(u8, s16);
void fn_8001D074(s32, BOOL);
extern void fn_800B0A14_removeQueue(void);
extern UnkA00Task* fn_800B0A5C_insertQueue(void (*)(void), s32);
void fn_80052798(s32);
// rep_E08.h, rep_3090.h and m_sound.h declare these as void(void) placeholders
void fn_3_6714C(BOOL);
void fn_3_FBD58(void);
void fn_3_FBD70(void);
void fn_3_8C104(s32);
void fn_3_5A6D4(u8);
BOOL fn_3_6B4C8(void);
BOOL fn_3_6C938(s32, s32);
void fn_3_90220(s32, s32);
BOOL fn_3_165D24(void);

// .data 0x1D28-0x3A40: only this unit uses it (and the functions at 0x249E8), but
// splits.txt does not assign it here yet
extern u8 lbl_3_data_1D28[0x1F8];
extern s32 lbl_3_data_1F74[33];
extern s32 lbl_3_data_1FF8[55];
extern s32 lbl_3_data_2368[6];
extern s32 lbl_3_data_2380[6];
extern UnkA00Mission lbl_3_data_2398[33];

s32 lbl_3_data_3A40[55] = {
    0x78, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x79, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
    0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
};
s32 lbl_3_data_3B1C[6] = { 0x11C, 0x11D, 0x11E, 0x11A, 0x11F, 0x11B };
s32 lbl_3_data_3B34[6] = { 0x11C, 0x11D, 0x11E, 0x11A, 0x11F, 0x11B };
s32 lbl_3_data_3B4C[54] = {
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x4E, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x34, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
};

static int lbl_3_bss_A0[10];
static int lbl_3_bss_9C;

void fn_3_21AA8(void);
void fn_3_8C07C(void);
void fn_3_7C1FC(BOOL);

static inline void resetReplay(u8 mode) {
    int i;

    for (i = 0; i < 13; i++) {
        lbl_3_common_bss_1323C._0->_240[i] = -1;
        memset(&lbl_3_common_bss_1323C._0->_000[i], 0, sizeof(UnkA00ReplayEntry));
        lbl_3_common_bss_1323C._0->_261[i] = 0;
    }
    fn_3_6714C(FALSE);
    lbl_3_common_bss_1323C._0->_25C = 1;
    lbl_3_common_bss_1323C._0->_23C = 0;
    lbl_3_common_bss_1323C._0->_27C = 0;
    lbl_3_common_bss_1323C._0->_25D = mode;
    lbl_3_common_bss_1323C._0->_25F = 1;
    lbl_3_common_bss_1323C._0->_27D = 0;
    lbl_3_common_bss_1323C._0->_27E = 0;
    lbl_3_common_bss_1323C._0->_25A = 0;
    lbl_3_common_bss_1323C._0->_280 = 1;
}

void fn_3_147DFC(void);

// .text:0x00024708 size:0x2E0 mapped:0x8066379C
void fn_3_24708(void) {
    UnkA00Actor* actor;
    InMemRunnerType* runner;
    int i;
    f32 dist;
    f32 diff;
    Mtx mtx;
    Vec offset;

    for (i = 0; i < 13; i++) {
        actor = lbl_8036E548._2C50[i];
        if (actor == NULL) {
            continue;
        }
        if (lbl_3_common_bss_1323C._0->_000[i]._29 != 1) {
            continue;
        }
        if (lbl_3_common_bss_1323C._0->_27F == 3 && lbl_3_common_bss_1323C._0->_000[i]._1C > actor->_68) {
        } else if (i <= 8) {
            dist = PSVECDistance(&g_Fielders[i]._000, &lbl_3_common_bss_1323C._0->_000[i]._00);
        } else if (i <= 12) {
            runner = &g_Runners[i - 9];
            lbl_3_common_bss_1323C._0->_000[i]._10 =
                atan2(-(lbl_3_common_bss_1323C._0->_000[i]._00.x - runner->position.x),
                      -(lbl_3_common_bss_1323C._0->_000[i]._00.z - runner->position.z));
            PSMTXRotRad(mtx, 'Y', lbl_3_common_bss_1323C._0->_000[i]._0C);
            offset.x = 0.0f;
            offset.y = 0.0f;
            offset.z = lbl_3_common_bss_1323C._0->_000[i]._14;
            PSMTXMultVec(mtx, &offset, &offset);
            runner->position.x -= offset.x;
            runner->position.z -= offset.z;
            diff = fn_3_9FEA8(lbl_3_common_bss_1323C._0->_000[i]._0C - lbl_3_common_bss_1323C._0->_000[i]._10);
            if (!((diff < 0.02 && diff > 0.0f) || (diff > -0.02 && diff < 0.0f))) {
                if (diff < 0.0f) {
                    lbl_3_common_bss_1323C._0->_000[i]._0C += 0.017453292f;
                } else {
                    lbl_3_common_bss_1323C._0->_000[i]._0C -= 0.017453292f;
                }
            }
            runner->runningAngle = lbl_3_common_bss_1323C._0->_000[i]._0C;
            dist = PSVECDistance((Vec*)&runner->position, &lbl_3_common_bss_1323C._0->_000[i]._00);
        }
        if (lbl_3_common_bss_1323C._0->_27F == 3) {
            if (actor->_68 == 0) {
                lbl_3_common_bss_1323C._0->_000[i]._28 = 1;
                lbl_3_common_bss_1323C._0->_000[i]._29 = 0;
            }
        } else if (dist < 3.0f) {
            lbl_3_common_bss_1323C._0->_000[i]._28 = 1;
            lbl_3_common_bss_1323C._0->_000[i]._29 = 0;
        }
    }
}

// .text:0x00024630 size:0xD8 mapped:0x806636C4
void fn_3_24630(void) {
    s32 i;

    fn_80052798(1);
    for (i = 0; i < 13; i++) {
        lbl_3_common_bss_1323C._0->_261[i] = 0;
    }
    lbl_3_common_bss_1323C._0->_25C = 0;
}

// .text:0x00024598 size:0x98 mapped:0x8066362C
void fn_3_24598(void) {
    if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
        lbl_3_common_bss_1323C._0->_23C++;
    } else {
        lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
    }
    if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E - 7) {
        changeScene(3, 6);
    }
    if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
        g_GameLogic._125++;
    }
}

// .text:0x000240F8 size:0x4A0 mapped:0x8066318C
void fn_3_240F8(void) {
    return;
}

// .text:0x00023CEC size:0x40C mapped:0x80662D80
void fn_3_23CEC(void) {
    int i;
    GameInitVariables* settings = &g_d_GameSettings;
    GameControlsStruct* logic = &g_GameLogic;
    UnkA00Actor* actor;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            changeScene(1, 6);
            logic->_125 = 1;
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        }
        break;
    case 1:
        resetReplay(3);
        fn_3_FBDAC(lbl_3_data_1FF8[g_Runners[0].charID]);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        logic->_125 = 2;
        break;
    case 2:
        fn_3_24708();
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 7 &&
            settings->GameModeSelected != GAME_TYPE_DEMO) {
            if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
                lbl_3_common_bss_1323C._0->_27C = 1;
                lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 8;
                changeScene(3, 6);
            }
        } else if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E - 7) {
            changeScene(3, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            logic->_125 = 4;
        }
        for (i = 0; i < 13; i++) {
            if (i == 0 || i == 1 || i == 9) {
                fn_8001D074(i, TRUE);
            } else {
                fn_8001D074(i, FALSE);
            }
        }
        break;
    case 4:
        fn_3_24630();
        fn_3_FBD70();
        fn_3_FBD58();
        fn_3_7C1FC(TRUE);
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        break;
    }
    actor = lbl_8036E548._2C50[9];
    if (actor->_62 == 0x3C &&
        actor->_6A == lbl_3_data_7F7C[lbl_800E8558[g_Batter.charID]._2][0]) {
        fn_3_90220(g_Batter.charID, 0);
    }
}

// .text:0x00023890 size:0x45C mapped:0x80662924
void fn_3_23890(void) {
    int i;
    UnkA00Task* task = lbl_803CC1B8;
    GameControlsStruct* logic = &g_GameLogic;
    GameInitVariables* settings = &g_d_GameSettings;
    UnkA00Task* fade;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            g_pCamera->_AAA = 1;
            g_pCamera->_AAE = 2;
            fn_800B0A5C_insertQueue(fn_3_21DE4, 6);
            logic->_125 = 1;
        }
        break;
    case 1:
        resetReplay(4);
        fn_3_FBDAC(0x4C);
        logic->_125 = 2;
        break;
    case 2:
        changeScene(1, 6);
        lbl_3_common_bss_1323C._0->_27E = 1;
        fade = fn_800B0A5C_insertQueue(fn_3_21AA8, 4);
        task->_10 = 0;
        fade->_22 = 0;
        fade->_1E = 0;
        logic->_125 = 3;
        break;
    case 3:
        fn_3_24708();
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 31 &&
            settings->GameModeSelected != GAME_TYPE_DEMO && g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60 &&
            lbl_3_common_bss_32724._B1 == 0) {
            lbl_3_common_bss_1323C._0->_27C = 1;
            lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 31;
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E - 31) {
            lbl_3_common_bss_32724._B1 = 1;
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            logic->_125 = 5;
        }
        for (i = 0; i < 13; i++) {
            if (i == 0 || i == 1 || i == 9) {
                fn_8001D074(i, TRUE);
            } else {
                fn_8001D074(i, FALSE);
            }
        }
        break;
    case 4:
        break;
    case 5:
        lbl_3_common_bss_1323C._0->_27E = 0;
        fn_3_24630();
        fn_3_FBD70();
        fn_3_FBD58();
        logic->_125 = 6;
        break;
    case 6:
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        fn_3_8C07C();
        if (lbl_3_common_bss_1323C._0->_27C) {
            fn_3_5A6D4(g_GameLogic.gameStatus_prev);
            g_Stats._39 = 2;
        } else {
            fn_3_5A6D4(g_GameLogic.gameStatus_prev);
            g_Stats._39 = 2;
        }
        break;
    }
}

// .text:0x000234BC size:0x3D4 mapped:0x80662550
void fn_3_234BC(void) {
    int i;
    GameInitVariables* settings = &g_d_GameSettings;
    GameControlsStruct* logic = &g_GameLogic;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            if (g_GameLogic.playOverInd == 0 && !fn_3_21F14()) {
                lbl_3_common_bss_1323C._0->_25C = 0;
                changeScene(1, 6);
                fn_3_FBD58();
                fn_3_5A6D4(0);
            } else {
                fn_3_F1DC();
                fn_3_751B4();
                setDefaultInMemBatter();
                fn_3_8913C();
                fn_3_58870();
                fn_3_1DEB8();
                g_Pitcher.playStartOfGameAnimation = 0;
                g_GameLogic.scoutFlag_VsScreenInd = 1;
                logic->_125 = 1;
            }
        }
        break;
    case 1:
        resetReplay(0);
        if (g_GameLogic.playOverInd == 1) {
            fn_3_FBDAC(0x6A);
        } else {
            fn_3_FBDAC(lbl_3_data_1F74[lbl_3_common_bss_1323C._0->_260]);
        }
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        logic->_125 = 2;
        break;
    case 2:
        fn_3_24708();
        if (lbl_3_common_bss_1323C._0->_23C == 9) {
            changeScene(1, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 7 &&
            settings->GameModeSelected != GAME_TYPE_DEMO && g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
            lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 8;
            changeScene(3, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            logic->_125 = 3;
        }
        break;
    case 3:
        fn_3_24630();
        fn_3_FBD70();
        fn_3_FBD58();
        fn_3_5A6D4(0);
        break;
    }
}

// .text:0x000230D4 size:0x3E8 mapped:0x80662168
void fn_3_230D4(void) {
    int i;
    GameInitVariables* settings = &g_d_GameSettings;
    GameControlsStruct* logic = &g_GameLogic;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            changeScene(1, 6);
            fn_3_24630();
            fn_3_FBD70();
            fn_3_FBD58();
            fn_3_5A6D4(0);
        }
        break;
    case 1:
        changeScene(1, 6);
        resetReplay(1);
        fn_3_FBDAC(0x6B);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        logic->_125 = 2;
        break;
    case 2:
        if (lbl_3_common_bss_1323C._0->_23C == 9) {
            changeScene(1, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 7 &&
            settings->GameModeSelected != GAME_TYPE_DEMO && g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
            lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 8;
            changeScene(3, 6);
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            fn_3_24630();
            fn_3_FBD70();
            fn_3_FBD58();
            fn_3_5A6D4(0);
        }
        break;
    }
}

// .text:0x00022C20 size:0x4B4 mapped:0x80661CB4
void fn_3_22C20(void) {
    int i;
    GameInitVariables* settings = &g_d_GameSettings;
    lbl_3_common_bss_32A94_s* bss = &lbl_3_common_bss_32A94;
    GameControlsStruct* logic = &g_GameLogic;
    UnkA00Challenge* challenge;
    s16 team;
    s16 charID;

    switch (logic->_125) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_147DFC();
            lbl_3_common_bss_32724._9A = 0;
            logic->_125 = 1;
        }
        break;
    case 1:
        if (fn_3_6B4C8()) {
            logic->_125 = 2;
        }
        break;
    case 2:
        fn_3_8C104(-1);
        resetReplay(2);
        challenge = (UnkA00Challenge*)starMissionCompletionTracker;
        if (bss->_8A) {
            fn_3_FBDAC(lbl_3_data_2368[challenge->_441C]);
        } else {
            fn_3_FBDAC(lbl_3_data_2380[challenge->_441C]);
        }
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        logic->_125 = 3;
        break;
    case 3:
        if (lbl_3_common_bss_1323C._0->_23C == 9) {
            changeScene(1, 0x5A);
        }
        if (lbl_3_common_bss_1323C._0->_23C < 0x7FFE) {
            lbl_3_common_bss_1323C._0->_23C++;
        } else {
            lbl_3_common_bss_1323C._0->_23C = 0x7FFF;
        }
        for (i = 0; i < 13; i++) {
            fn_8001D074(i, TRUE);
        }
        if (fn_3_6C938(1, 0x1100) && lbl_3_common_bss_1323C._0->_23C < lbl_3_common_bss_1323C._0->_23E - 91 &&
            settings->GameModeSelected != GAME_TYPE_DEMO) {
            if (lbl_3_common_bss_1323C._0->_280 == 1 && g_GameLogic.FrameCountOfCurrentAtBat_Copy > 60) {
                lbl_3_common_bss_1323C._0->_23C = lbl_3_common_bss_1323C._0->_23E - 92;
                changeScene(3, 0x5A);
                lbl_3_common_bss_34C58._2A = 1;
                lbl_3_common_bss_34C58._24 = 0x5A;
            }
        } else if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E - 91) {
            changeScene(3, 0x5A);
            lbl_3_common_bss_34C58._2A = 1;
            lbl_3_common_bss_34C58._24 = 0x5A;
        }
        if (lbl_3_common_bss_1323C._0->_23C == lbl_3_common_bss_1323C._0->_23E) {
            logic->_125 = 4;
        }
        break;
    case 4:
        if (lbl_8037169C._13) {
            fn_3_24630();
            fn_3_FBD70();
            fn_3_FBD58();
            logic->_125 = 5;
        }
        break;
    case 5:
        logic->_128 = 1;
        logic->framesOfExitingToMenu = 1;
        break;
    }
    team = lbl_3_common_bss_37400._40;
    charID = inMemRoster[team][g_GameLogic.Team_CaptainRosterLoc[team]].stats.CharID;
    if (lbl_3_common_bss_1323C._0->_23C == lbl_3_data_7F7C[lbl_800E8558[charID]._2][3]) {
        fn_3_90220(charID, 7);
    }
}

// .text:0x00022C10 size:0x10 mapped:0x80661CA4
void fn_3_22C10(void) {
    int i;

    for (i = 13; i != 0; i--) {
    }
}

// .text:0x00022ABC size:0x154 mapped:0x80661B50
int fn_3_22ABC(void) {
    BOOL close = FALSE;
    int n;
    ScoresA00* scores = &g_Scores;

    n = 0;
    if (g_Runners[1].rosterID != -1) {
        n++;
    }
    if (g_Runners[2].rosterID != -1) {
        n++;
    }
    if (g_Runners[3].rosterID != -1) {
        n++;
    }
    if (__abs(scores->_A6) <= 4 && n == 3 && scores->_04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] <= scores->_04[g_GameLogic.awayTeamBattingInd_battingTeam][0]) {
        close = TRUE;
    }
    n = 0;
    if (g_Runners[2].rosterID != -1) {
        n++;
    }
    if (g_Runners[3].rosterID != -1) {
        n++;
    }
    if (__abs(scores->_A6) <= n && n > 0 && scores->_04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] <= scores->_04[g_GameLogic.awayTeamBattingInd_battingTeam][0]) {
        close = TRUE;
    }
    if (close) {
        if (g_Batter.aiControlledInd) {
            return 1;
        }
        return 2;
    }
    return -1;
}

// .text:0x00022A20 size:0x9C mapped:0x80661AB4
BOOL fn_3_22A20(void) {
    BOOL ret;

    if (g_Batter.aiControlledInd) {
        ret = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] >=
              g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0];
    } else {
        ret = g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] >=
              g_Scores._04[g_GameLogic.awayTeamBattingInd_battingTeam][0];
        ret = !ret;
    }
    return ret;
}

// .text:0x00022948 size:0xD8 mapped:0x806619DC
void fn_3_22948(void) {
    s32 i;

    for (i = 0; i < 33; i++) {
        lbl_3_data_2398[i]._34 = 0;
        lbl_3_data_2398[i]._38 = 0;
        lbl_3_data_2398[i]._3C = 0;
    }
    lbl_3_common_bss_1323C._0->_27B = 0;
}

// .text:0x00022944 size:0x4 mapped:0x806619D8
void fn_3_22944(void) {
    return;
}

// .text:0x00022850 size:0xF4 mapped:0x806618E4
void fn_3_22850(void) {
    s32 i;

    for (i = 0; i < 33; i++) {
        lbl_3_data_2398[i]._38 = 0;
        lbl_3_data_2398[i]._3C = 0;
    }
    lbl_3_common_bss_1323C._0->_27B = 0;
}

// .text:0x0002281C size:0x34 mapped:0x806618B0
BOOL fn_3_2281C(int i) {
    UnkA00Actor* actor = lbl_8036E548._2C50[i];

    if (actor == NULL) {
        return TRUE;
    }
    if (actor->_68 == 0) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x0002273C size:0xE0 mapped:0x806617D0
BOOL fn_3_2273C(void) {
    int i;

    for (i = 0; i < 9; i++) {
        if (g_Fielders[i]._218 == 0) {
            if (lbl_8036E548._2C50[i] == NULL) {
                return TRUE;
            }
            if (lbl_8036E548._2C50[i]->_68 == 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// .text:0x00021F14 size:0x828 mapped:0x80660FA8
BOOL fn_3_21F14(void) {
    return;
}

// .text:0x00021DE4 size:0x130 mapped:0x80660E78
void fn_3_21DE4(void) {
    UnkA00Task* task = lbl_803CC1B8;

    switch (lbl_3_bss_9C) {
    case 0:
        task->_1E = 0;
        task->_20 = 0xFF;
        lbl_803C5090._1D = 9;
        lbl_803C5090._00 = 1.0f;
        lbl_803C5090._14 = 0x1C0;
        lbl_803C5090._19 = 1;
        lbl_803C5090._18 = 0;
        lbl_803C5090._1A = 0xFF;
        lbl_803C5090._1B = 0xFF;
        lbl_803C5090._1C = 0xFF;
        lbl_803C5090._17 = 0xFF;
        lbl_3_bss_9C++;
        break;
    case 1:
        lbl_803C5090._1D = 8;
        lbl_803C5090._00 = 1.0f;
        lbl_803C5090._14 = 0x1C0;
        lbl_803C5090._19 = 1;
        lbl_803C5090._18 = 0;
        lbl_803C5090._1A = 0xFF;
        lbl_803C5090._1B = 0xFF;
        lbl_803C5090._1C = 0xFF;
        lbl_803C5090._17 = 0xFF;
        task->_1E++;
        if (g_pCamera->_AAE <= task->_1E) {
            g_pCamera->_AAA = 0;
            fn_800B0A14_removeQueue();
            lbl_3_bss_9C = 0;
        }
        break;
    case 2:
        break;
    }
}

// .text:0x00021C90 size:0x154 mapped:0x80660D24
void fn_3_21C90(void) {
    UnkA00Task* task = lbl_803CC1B8;

    switch (lbl_3_bss_A0[0]) {
    case 0:
        task->_1E = 0;
        task->_20 = 0xFF;
        lbl_803C5090._1D = 9;
        lbl_803C5090._00 = 1.0f;
        lbl_803C5090._14 = 0x1C0;
        lbl_803C5090._19 = 1;
        lbl_803C5090._18 = 0;
        lbl_803C5090._1A = 0xFF;
        lbl_803C5090._1B = 0xFF;
        lbl_803C5090._1C = 0xFF;
        lbl_803C5090._17 = task->_20;
        lbl_3_bss_A0[0]++;
        break;
    case 1:
        lbl_803C5090._1D = 8;
        lbl_803C5090._00 = 1.0f;
        lbl_803C5090._14 = 0x1C0;
        lbl_803C5090._19 = 1;
        lbl_803C5090._18 = 0;
        lbl_803C5090._1A = 0xFF;
        lbl_803C5090._1B = 0xFF;
        lbl_803C5090._1C = 0xFF;
        lbl_803C5090._17 = task->_20;
        task->_1E++;
        if (g_pCamera->_AAC <= task->_1E) {
            g_pCamera->_AA8 = 0;
            fn_800B0A14_removeQueue();
            lbl_3_bss_A0[0] = 0;
        } else {
            task->_20 = 0xFF - task->_1E * 0xFF / g_pCamera->_AAC;
        }
        break;
    case 2:
        break;
    }
}
