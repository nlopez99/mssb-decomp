#include "game/rep_28A8.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"
#include "game/rep_540.h"
#include "game/rep_1C0.h"
#include "game/rep_AC8.h"
#include "game/rep_1188.h"
#include "game/rep_1200.h"
#include "game/rep_1E08.h"
#include "game/rep_2940.h"
#include "game/rep_868.h"
#include "game/rep_1CB8.h"
#include "game/rep_3310.h"
#include "game/rep_3880.h"
#include "game/rep_3CE0.h"
#include "game/rep_1038.h"
#include "game/game_batter.h"
#include "game/sta_c6.h"
#include "game/rep_1A80.h"
#include "game/rep_31A0.h"
#include "game/rep_CC8.h"
#include "game/rep_D18.h"
#include "game/rep_DB8.h"
#include "game/rep_3090.h"
#include "game/m_sound.h"
#include "musyx/musyx.h"
#include "Dolphin/rand.h"
#include "game/rep_3D50.h"

extern struct {
    /* 0x000 */ s32 _000;
    /* 0x004 */ u16 _004;
    /* 0x006 */ u16 _006;
    /* 0x008 */ u16 _008;
    /* 0x00A */ u8 _00A[0xC - 0xA];
    /* 0x00C */ s16 _00C;
    /* 0x00E */ s16 _00E;
    /* 0x010 */ s16 _010;
    /* 0x012 */ s16 _012;
    /* 0x014 */ u8 _014[0x1D0 - 0x14];
    /* 0x1D0 */ u8 _1D0;
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4;
    /* 0x1D5 */ u8 _1D5;
    /* 0x1D6 */ u8 _1D6[0x1D9 - 0x1D6];
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ s8 _1DA;
    /* 0x1DB */ u8 _1DB[0x220 - 0x1DB];
    /* 0x220 */ u8 _220;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6;
} g_UnkSimulation_31AC0;

extern struct {
    /* 0x00 */ int _00;
    /* 0x04 */ u8 _04[0xAA - 0x4];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB;
    /* 0xAC */ u8 _AC;
    /* 0xAD */ u8 _AD[0xC5 - 0xAD];
    /* 0xC5 */ u8 _C5;
} g_Scores;

extern struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ s16 _40;
} lbl_3_common_bss_37400;

extern struct {
    /* 0x00 */ u8 _00[0xD5];
    /* 0xD5 */ u8 _D5;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} g_RunningLogic;

typedef struct {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
    /* 0x008 */ f32 z;
    /* 0x00C */ u8 _00C[0x1C9 - 0xC];
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA[0x1EC - 0x1CA];
    /* 0x1EC */ u8 _1EC;
    /* 0x1ED */ u8 _1ED;
    /* 0x1EE */ u8 _1EE;
    /* 0x1EF */ u8 _1EF[0x20D - 0x1EF];
    /* 0x20D */ u8 _20D;
    /* 0x20E */ u8 _20E[0x268 - 0x20E];
} Unk28A8Fielder; // size: 0x268

extern Unk28A8Fielder g_Fielders[9];

extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern struct {
    /* 0x0000 */ u8 _0000[0x2D8E];
    /* 0x2D8E */ u8 _2D8E;
    /* 0x2D8F */ u8 _2D8F[0x307A - 0x2D8F];
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B[0x307E - 0x307B];
    /* 0x307E */ u8 _307E;
} lbl_8036E548;

extern u8 lbl_800EFBA4[0x10];
extern struct {
    /* 0x000 */ u8 _000[0x398];
    /* 0x398 */ u8 _398;
} lbl_800EF808;

extern s16 lbl_3_data_49DC[44];
extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];
extern u8 lbl_3_data_88DC[2];
extern u8 lbl_3_data_21270[8];
extern u8 lbl_3_common_bss_32234[6];

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 z;
    /* 0x8 */ f32 radius[2];
} Unk28A8Spawn; // size: 0x10


u8 lbl_3_data_188E8[0x14] = { 0, 1, 2, 3, 4, 5, 0, 2, 3, 4, 5, 0, 0, 2, 3, 5, 0, 0, 0, 0 };
u8 lbl_3_data_188FC[0x10] = { 0, 2, 1, 3, 4, 5, 0, 1, 3, 4, 0, 1, 3, 4, 0, 0 };
u8 aILevel[4] = { 3, 2, 1, 0 };
u8 lbl_3_data_18910[8] = { 6, 0, 4, 5, 2, 3, 1, 0 };
u8 lbl_3_data_18918[8] = { 0, 2, 2, 2, 2, 2, 2, 0 };
u8 lbl_3_data_18920[0x24] = {
    4, 4, 4, 4, 4, 1, 1, 1, 1, 2, 4, 4, 4, 1, 4, 1, 1, 1,
    1, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,
};
u8 lbl_3_data_18944[8] = { 3, 0, 0, 0, 3, 3, 0, 0 };
u8 lbl_3_data_1894C[0x2C] = {
    0x03, 0x13, 0x30, 0x32, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x0C,
    0x2A, 0x14, 0x2B, 0xFF, 0xFF, 0x05, 0x10, 0x2C, 0x2D, 0x2E, 0x2F, 0xFF, 0x00, 0x00,
};
u8 lbl_3_data_18978[8] = { 0, 1, 2, 3, 3, 0, 0, 0 };
static u8 lbl_3_data_18980[3] = { 2, 0, 0 };
f32 lbl_3_data_18984[6] = { 0.0f, 70.0f, 12.0f, 40.0f, -12.0f, 40.0f };
static s16 lbl_3_data_1899C[4] = { 120, 90, 20, 0 };
static u8 lbl_3_data_189A4[8] = { 10, 20, 30, 40, 50, 10, 0, 0 };
static u8 lbl_3_data_189AC[9] = { 0, 2, 3, 4, 5, 6, 9, 10, 11 };
static s16 lbl_3_data_189B8[6] = { 10, 20, 30, 10, 100, 0 };
s16 lbl_3_data_189C4[3][7] = {
    { 0, 2, 3, 4, 5, 6, 7 },
    { 5, 0, 3, 2, 7, 4, 6 },
    { 4, 0, 6, 3, 5, 7, 2 },
};
static u8 lbl_3_data_189F0[3][3][3][8] = {
    {
        { { 20, 0, 13, 20, 0, 2, 5, 40 }, { 20, 0, 15, 15, 12, 3, 10, 25 }, { 30, 0, 25, 0, 20, 5, 10, 10 } },
        { { 10, 0, 5, 10, 0, 0, 5, 70 }, { 20, 0, 15, 15, 12, 3, 10, 25 }, { 30, 0, 25, 0, 20, 5, 10, 10 } },
        { { 5, 0, 5, 5, 0, 0, 5, 80 }, { 20, 0, 15, 15, 12, 3, 10, 25 }, { 30, 0, 25, 0, 20, 5, 10, 10 } },
    },
    {
        { { 20, 0, 13, 20, 0, 2, 5, 40 }, { 20, 0, 15, 15, 12, 3, 10, 25 }, { 30, 0, 25, 0, 20, 5, 10, 10 } },
        { { 10, 0, 5, 10, 0, 0, 5, 70 }, { 20, 0, 15, 15, 12, 3, 10, 25 }, { 30, 0, 25, 0, 20, 5, 10, 10 } },
        { { 5, 0, 5, 5, 0, 0, 5, 80 }, { 20, 0, 15, 15, 12, 3, 10, 25 }, { 30, 0, 25, 0, 20, 5, 10, 10 } },
    },
    {
        { { 20, 0, 11, 30, 0, 0, 0, 39 }, { 15, 0, 15, 30, 30, 0, 0, 10 }, { 20, 0, 20, 30, 30, 0, 0, 0 } },
        { { 10, 0, 10, 20, 0, 0, 10, 50 }, { 15, 0, 5, 20, 40, 0, 10, 10 }, { 10, 0, 10, 10, 50, 10, 10, 0 } },
        { { 10, 0, 10, 15, 0, 0, 5, 60 }, { 15, 0, 5, 20, 30, 5, 10, 10 }, { 10, 0, 10, 10, 50, 10, 10, 0 } },
    },
};
static Unk28A8Spawn lbl_3_data_18AC8[10] = {
    { 17.7f, 37.1f, { 9.0f, 14.0f } },
    { 0.0f, 52.0f, { 9.0f, 14.0f } },
    { -17.7f, 37.1f, { 9.0f, 14.0f } },
    { 34.2f, 53.6f, { 9.0f, 14.0f } },
    { 20.0f, 71.0f, { 9.0f, 14.0f } },
    { 0.0f, 76.8f, { 9.0f, 14.0f } },
    { -20.0f, 71.0f, { 9.0f, 14.0f } },
    { -34.2f, 53.6f, { 9.0f, 14.0f } },
    { 21.0f, 96.5f, { 9.0f, 15.0f } },
    { -21.0f, 96.5f, { 9.0f, 15.0f } },
};
static u8 lbl_3_data_18B68[0x20] = {
    0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    1, 0, 1, 1, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0,
};
static f32 lbl_3_data_18B88[5] = { 0.84f, 0.88f, 0.92f, 0.96f, 1.0f };
static f32 lbl_3_data_18B9C[5] = { 0.004f, 0.985f, 0.65f, 0.5f, 1.5f };
s16 lbl_3_data_18BB0[2][2] = { { 240, 180 }, { 180, 150 } };
static s16 lbl_3_data_18BB8[24][3] = {
    { 10, 0, 0 },     { 20, 0, 0 },    { 30, 0, 0 },     { 40, 0, -20 },  { 40, -40, 0 },  { 30, -10, -10 },
    { 60, -20, -20 }, { 90, -30, -30 }, { 120, -40, -40 }, { 0, 0, 0 },   { 0, 0, 0 },     { 0, 0, 0 },
    { 200, 0, 0 },    { 50, 0, 0 },    { 100, 0, 0 },    { 30, 0, 0 },    { 0, 0, 0 },     { 0, 0, 0 },
    { -90, 30, 30 },  { 0, 0, 0 },     { -50, 0, 50 },   { 0, 0, 0 },     { -30, 30, 0 },  { 20, -20, 0 },
};
s16 lbl_3_data_18C48[10] = { 100, 180, 600, 279, 3, 1, 60, 70, 2, 0 };
extern u8 lbl_803CBC3C[];

extern void fn_3_1DD48(void);
extern void Set_803cb848(int);
extern int fn_3_6C938(int, int);
extern void changeScene(u8, s16);
extern void fn_8004CC18(void);
extern void fn_3_1E328(void);
extern void fn_800203E0(int, int);
extern BOOL fn_80016F7C(void);
extern void fn_3_E1964(void);
extern void fn_3_1E154(void);
extern void possiblyTransitionBlackScreen(void);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);

static inline void playStadiumSound(s32 sound) {
    SND_VOICEID voice;
    u8 vol;
    s32 stadium = g_d_GameSettings.StadiumID;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][0];
    } else {
        vol = lbl_3_data_8404[stadium][sound][0];
    }
    voice = sndFXStartEx(lbl_3_data_81DC[stadium] + sound, vol, 63, 0);
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][1];
    } else {
        vol = lbl_3_data_8404[stadium][sound][1];
    }
    sndFXCtrl(voice, 91, vol);
}

// .text:0x000DFBAC size:0xABC mapped:0x8071EC40
void fn_3_DFBAC(void) {
    s32 i;

    g_GameLogic.hudElementLoadingInd = 0;
    g_GameLogic.hudLoadingRelated = 0;
    g_Minigame._19A1 = 0;
    g_Minigame._1925 = 0;
    for (i = 0; i < 4; i++) {
        g_Minigame.miniGameLatestPoints[i] = 0;
    }
    if (g_Ball.totalFramesAtPlay < 0x7FFE) {
        g_Ball.totalFramesAtPlay++;
    } else {
        g_Ball.totalFramesAtPlay = 0x7FFF;
    }
    switch (g_GameLogic.gameStatus) {
    case GAME_STATUS_0x1B:
        fn_3_DF820();
        break;
    case GAME_STATUS_TOY_STADIUM_LOAD:
        fn_3_10F3D8();
        break;
    case GAME_STATUS_TOY_STADIUM_CHARACTER_SELECT:
        fn_3_10E60C();
        break;
    case GAME_STATUS_MINIGAME_READY:
        fn_3_10B8D0();
        break;
    case GAME_STATUS_MINIGAME_POST_MENU:
        fn_3_DC6E8();
        break;
    case GAME_STATUS_0x25:
        fn_3_DF6D4();
        break;
    case GAME_STATUS_DEFAULT:
        fn_3_DE744();
        break;
    case GAME_STATUS_AT_BAT:
        fn_3_DDFA0();
        break;
    case GAME_STATUS_LIVE_BALL:
        fn_3_DD9A4();
        break;
    case GAME_STATUS_INNING_TRANSITION:
        fn_3_DD1A8();
        break;
    case GAME_STATUS_GAME_START_MOVIE:
        fn_3_DF3D8();
        break;
    case GAME_STATUS_TRANSITION_TO_MINIGAME_START:
        fn_3_DF25C();
        break;
    case GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY:
        fn_3_DF00C();
        break;
    case GAME_STATUS_TRANSITION:
        fn_3_DE610();
        break;
    case GAME_STATUS_END_OF_GAME:
        fn_3_DD000();
        break;
    case GAME_STATUS_MVP_END_GAME:
        fn_3_10A0A0();
        break;
    case GAME_STATUS_0x24:
        fn_3_109254();
        break;
    case GAME_STATUS_PAUSED:
        fn_3_DCC80();
        break;
    case GAME_STATUS_HOW_TO_PLAY_SCREEN:
        lbl_803CBC3C[0] = 1;
        if (lbl_3_common_bss_34C90._012 < 0x7FFE) {
            lbl_3_common_bss_34C90._012++;
        } else {
            lbl_3_common_bss_34C90._012 = 0x7FFF;
        }
        lbl_3_common_bss_34C90._004 = g_Controls[lbl_3_common_bss_34C90._000].buttonInput;
        lbl_3_common_bss_34C90._006 = g_Controls[lbl_3_common_bss_34C90._000].newButtonInput;
        lbl_3_common_bss_34C90._008 = g_Controls[lbl_3_common_bss_34C90._000]._08;
        fn_3_ACAF8();
        break;
    }
    if (g_Minigame._19CD == 1) {
        fn_3_DE308(g_Minigame._1921 + 4);
        g_Minigame._19CD = 2;
    }
    for (i = 0; i < 4; i++) {
        g_Minigame.miniGameCurrentPoints[i] += g_Minigame.miniGameLatestPoints[i];
        if (g_Minigame.miniGameCurrentPoints[i] > 999) {
            g_Minigame.miniGameCurrentPoints[i] = 999;
        }
        if (g_Minigame.miniGameCurrentPoints[i] < 0) {
            g_Minigame.miniGameCurrentPoints[i] = 0;
        }
    }
    if (lbl_3_common_bss_34C58._30) {
        lbl_3_common_bss_34C58._30--;
    }
    fn_3_DE4FC();
}

// .text:0x000DFA20 size:0x18C mapped:0x8071EAB4
void fn_3_DFA20(void) {
    int i;

    g_GameLogic.secondaryGameMode = SECONDARY_GAME_MODE_TOY_FIELD;
    fn_800B0A5C_insertQueue(possiblyTransitionBlackScreen, 2);
    fn_800B0A5C_insertQueue(fn_3_5BAC, 4);
    g_d_GameSettings._33 = 0;
    g_Minigame.GameMode_MiniGame = MINI_GAME_ID_NONE;
    g_Minigame._19DF = 30;
    g_Minigame._1A2C = -1;
    g_Minigame._1A0C = -1;
    g_Minigame._19E6 = 2;
    g_Minigame._19E7 = 1;
    g_Minigame._1A3C = 0;
    g_Minigame._19A7 = lbl_3_data_21270[0];
    g_Minigame._1A38 = 0;
    g_Minigame._1A39 = 0;
    g_Minigame.battingHandedness[5] = 0;
    for (i = 0; i < 4; i++) {
        g_Minigame._19DA[i] = -1;
        g_Minigame._19E8[i]._0 = -1;
        g_Minigame._19E8[i]._2 = -1;
        g_Minigame._19E8[i]._3 = -1;
        g_Minigame._1A0F[i] = -1;
        g_Minigame._19D2[i] = 20;
        g_Minigame._1A13[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        g_Minigame.minigameControlStruct.characterIndex[i] = -1;
        g_Minigame.minigameControlStruct.battingHandedness[i] = 0;
    }
    g_Minigame.miniGameNumberOfParticipants = 0;
    lbl_3_common_bss_34C58._30 = 0;
    fn_3_DF8D4();
    if (!g_d_GameSettings.exhibitionMatchInd) {
        g_Minigame._190A = 1;
        fn_3_5A6D4(GAME_STATUS_0x25);
    } else {
        fn_3_5A6D4(GAME_STATUS_0x1B);
    }
}

// .text:0x000DF8D4 size:0x14C mapped:0x8071E968
void fn_3_DF8D4(void) {
    int i;

    for (i = 0; i < 4; i++) {
        g_Minigame.miniGameCurrentPoints[i] = lbl_3_data_18C48[0];
        g_Minigame.minigameControlStruct._1C[i] = 0;
        g_Minigame.minigameControlStruct._28[i] = -1;
        g_Minigame.minigameFielderIndex[i] = -1;
        g_Minigame._18FC[i] = -1;
        g_Minigame.minigameControlStruct._14[i] = -1;
        g_Minigame.minigameControlStruct._18[i] = i;
        g_Minigame._19BE[i][0] = 0xFF;
    }
    for (i = 0; i < 4; i++) {
        g_Minigame._1914_arr[i] = 0;
    }
    g_Minigame.turnNumberWithinRound = 0;
    g_Minigame._1939 = 0;
    g_Minigame._190D = 3;
    g_Minigame._19A6 = 0;
    g_Minigame.challenge_minigame_haven_tWonYetIndicator = 1;
    g_Minigame._19A9 = 0;
    g_Minigame._1911 = 0;
    g_Minigame.toyField_pointMultiplier = 1;
    g_Minigame.toyfield_waitFor_CoinsX2_AnimationToEnd = 0;
    g_Minigame._19CD = 0;
    g_Minigame._19CE = 0;
    g_Minigame._19CF = 0;
    g_Minigame.toyField_selectedTurns = lbl_3_data_189A4[g_Minigame._1A24[0]];
    g_Minigame.toyField_turnNumber = 0;
    if (!g_d_GameSettings.exhibitionMatchInd) {
        g_Minigame.toyField_selectedTurns = lbl_3_data_189A4[5];
    }
    fn_3_754B8();
    initializeInMemBatter();
    fn_3_FBA8();
    fn_3_595C4();
    fn_3_1E328();
}

// .text:0x000DF820 size:0xB4 mapped:0x8071E8B4
void fn_3_DF820(void) {
    int i;

    fn_3_10C81C();
    for (i = 0; i < 4; i++) {
        if (g_Minigame._19E8[i]._0 != g_Minigame._19E8[i]._2) {
            break;
        }
    }
    if (i >= 4) {
        fn_3_5A6D4(GAME_STATUS_TOY_STADIUM_LOAD);
    }
}

// .text:0x000DF6D4 size:0x14C mapped:0x8071E768
void fn_3_DF6D4(void) {
    switch (g_GameLogic._125) {
    case 0:
        fn_3_DF608();
        g_GameLogic._125++;
    }
    g_Minigame._190A = 1;
    g_Minigame._19DA[g_d_GameSettings._35] = g_d_GameSettings._35;
    lbl_3_common_bss_37400._40 = g_d_GameSettings._35;
    g_Minigame.GameMode_MiniGame = g_d_GameSettings._33;
    g_Minigame._19DF = 30;
    fn_3_5A6D4(GAME_STATUS_0x1B);
}

// .text:0x000DF608 size:0xCC mapped:0x8071E69C
void fn_3_DF608(void) {
    int i;
    int j;

    g_Minigame._19DA[g_d_GameSettings._35] = 0;
    j = 0;
    for (i = 0; i < 4; i++) {
        if (g_d_GameSettings._35 != i) {
            g_Minigame.minigameControlStruct.aIStrength[i] = lbl_3_data_18980[j];
            j++;
        }
    }
    g_Minigame.miniGameNumberOfParticipants = lbl_3_data_18944[g_Minigame.GameMode_MiniGame] + 1;
    g_Minigame._1907 = 1;
    g_Minigame.multiPlayerInd = 1;
    g_Scores._AA = 1;
}

// .text:0x000DF3D8 size:0x230 mapped:0x8071E46C
void fn_3_DF3D8(void) {
    switch (g_GameLogic._125) {
    case 0:
        fn_3_E8AC8();
        fn_800203E0(7, 0);
        g_Minigame.toyField_selectedTurns = lbl_3_data_189A4[g_Minigame._1A24[0]];
        if (!g_d_GameSettings.exhibitionMatchInd) {
            g_Minigame.toyField_selectedTurns = lbl_3_data_189A4[5];
        }
        lbl_8036E548._307E = 1;
        lbl_8036E548._2D8E = 0;
        lbl_8036E548._307A = 3;
        if (g_Minigame._190A) {
            g_GameLogic._125 = 1;
        } else {
            fn_3_59B20();
            g_GameLogic._125 = 2;
        }
        break;
    case 1:
        fn_3_10C81C();
        if (g_Minigame._1A0F[0] < 0) {
            fn_3_59B20();
            g_GameLogic._125 = 2;
        }
        break;
    case 2:
        if (!fn_3_59AE4()) {
            break;
        }
        g_GameLogic._125 = 3;
    case 3:
        if (fn_80016F7C()) {
            if (g_Minigame._1A38) {
                g_GameLogic._125 = 6;
            } else {
                g_GameLogic._125 = 4;
            }
            lbl_3_common_bss_34C58._2C = 0;
        }
        break;
    case 4:
        if (fn_3_90DD8()) {
            g_GameLogic._125 = 6;
        }
        break;
    case 6:
        if (lbl_8037169C._12 && (g_GameLogic.FrameCountOfCurrentPitch >= 240 || fn_3_FD9FC()) && fn_3_6C938(1, 0x1300)) {
            g_GameLogic._125 = 7;
        }
        break;
    case 7:
        changeScene(3, 6);
        if (lbl_8037169C._13) {
            fn_3_FBD70();
            fn_3_FBD58();
            g_GameLogic._125 = 8;
        }
        break;
    case 8:
        fn_3_E1964();
        g_Minigame._1A38 = 0;
        g_Minigame._19A2 = 0;
        lbl_8036E548._307A = 1;
        fn_3_5A6D4(GAME_STATUS_TRANSITION_TO_MINIGAME_START);
        break;
    }
}

// .text:0x000DF25C size:0x17C mapped:0x8071E2F0
void fn_3_DF25C(void) {
    s32 i;
    s32 j;
    s32 k;
    int r;
    int remaining;

    g_Scores._AC = fn_3_5C530(++g_Scores._00);
    g_Strikes.outs = 0;
    g_Strikes.storedOuts = 0;
    lbl_3_common_bss_32724._D5 = 1;
    g_Minigame.turnNumberWithinRound = 0;
    g_Minigame._190D = 3;
    g_Minigame.panelHitInd = 0;
    g_Minigame._19A5 = 1;
    g_Minigame._190F = 0;
    g_Minigame._1910 = 3;
    g_Minigame._1911 = 0;
    for (i = 0; i < 4; i++) {
        g_Minigame._1914_arr[i] = 0;
    }
    for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        g_Minigame.minigameControlStruct._18[i] = i;
    }
    remaining = g_Minigame.miniGameNumberOfParticipants;
    k = 0;
    for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        r = random_fn_3_9EE24(remaining);
        for (j = 0; j < g_Minigame.miniGameNumberOfParticipants; j++) {
            if (g_Minigame.minigameControlStruct._18[j] >= 0) {
                if (r == 0) {
                    g_Minigame.minigameControlStruct._14[k] = j;
                    remaining--;
                    k++;
                    g_Minigame.minigameControlStruct._18[j] = -1;
                    break;
                }
                r--;
            }
        }
    }
    changeScene(1, 6);
    fn_3_5A6D4(GAME_STATUS_INNING_TRANSITION);
}

// .text:0x000DF00C size:0x250 mapped:0x8071E0A0
void fn_3_DF00C(void) {
    s32 i;

    switch (g_GameLogic._125) {
    case 0:
        if (g_Minigame._19A6 == 1) {
            if (!fn_3_E8AC8()) {
                break;
            }
            g_Minigame._19A6 = 0;
        }
        if (g_Minigame._19A2) {
            g_Minigame._19A2--;
        }
        for (i = 0; i < 4; i++) {
            g_Minigame.minigameFielderIndex[i] = -1;
        }
        fn_3_DEB90();
        fn_3_F578();
        fn_3_753E8(FALSE);
        setBatterContactConstants();
        fn_3_58E50();
        fn_3_2E87C();
        fn_3_1E154();
        fn_3_E1370(0);
        lbl_3_common_bss_32234[1] = 1;
        g_GameLogic.pre_PostMiniGameInd = 1;
        g_Strikes.strikes = 0;
        g_GameLogic.minigameLastTurnSuccessInd = 1;
        g_Strikes.balls = 0;
        lbl_803CBC3C[2] = 0;
        g_GameLogic._125++;
        break;
    case 1:
        if (g_Minigame._19C7) {
            if (someAnimationIndFunction()) {
                lbl_3_common_bss_32234[1] = 1;
                g_GameLogic._125++;
            }
        } else {
            g_GameLogic._125++;
        }
        break;
    default:
        fn_3_DE744();
        g_Minigame._190F++;
        if (g_Minigame._190F == 1) {
            g_Minigame._1911 = 1;
        }
        if (g_Minigame.toyField_turnNumber < 0x7FFE) {
            g_Minigame.toyField_turnNumber++;
        } else {
            g_Minigame.toyField_turnNumber = 0x7FFF;
        }
        if (g_Minigame.toyField_turnNumber < g_Minigame.toyField_selectedTurns && g_Minigame.toyField_turnNumber % 10 == 1) {
            g_Minigame.toyField_next_CoinsX2_TurnNumber = random_fn_3_9EE24(6) + 4 + g_Minigame.toyField_turnNumber;
        }
        if (g_Minigame.toyField_next_CoinsX2_TurnNumber == g_Minigame.toyField_turnNumber) {
            g_Minigame.toyField_pointMultiplier = 2;
        } else {
            g_Minigame.toyField_pointMultiplier = 1;
        }
        break;
    }
}

// .text:0x000DEB90 size:0x47C mapped:0x8071DC24
void fn_3_DEB90(void) {
    int i;
    s8 j;
    int r;
    s32 k;

    g_Minigame._19C7 = 0;
    if (g_Minigame.toyField_turnNumber == 0) {
        g_Minigame._19C7 = 1;
        r = random_fn_3_9EE24(3);
        for (i = 0; i < 4; i++) {
            if (g_Minigame.rosterID != i) {
                if (r == 0) {
                    g_Minigame.minigamePlayerSelectedOrder = i;
                    break;
                }
                r--;
            }
        }
        k = 1;
        for (i = 0; i < 4; i++) {
            if (g_Minigame.rosterID != i && g_Minigame.minigamePlayerSelectedOrder != i) {
                g_Minigame.minigameControlStruct._28[k] = i;
                k++;
            }
        }
    } else {
        if ((u8)g_Minigame.rosterID == g_Minigame._19C6) {
            fn_3_59918(21, 0);
        } else {
            if (g_Minigame.minigameControlStruct._28[1] == g_Minigame._19C6) {
                g_Minigame.minigamePlayerSelectedOrder = g_Minigame.minigameControlStruct._28[2];
            } else if (g_Minigame.minigameControlStruct._28[2] == g_Minigame._19C6) {
                g_Minigame.minigamePlayerSelectedOrder = g_Minigame.minigameControlStruct._28[1];
            } else if (g_Minigame._19BE[g_Minigame.minigameControlStruct._28[1]][1] < g_Minigame._19BE[g_Minigame.minigameControlStruct._28[2]][1]) {
                g_Minigame.minigamePlayerSelectedOrder = g_Minigame.minigameControlStruct._28[2];
            } else if (g_Minigame._19BE[g_Minigame.minigameControlStruct._28[1]][1] > g_Minigame._19BE[g_Minigame.minigameControlStruct._28[2]][1]) {
                g_Minigame.minigamePlayerSelectedOrder = g_Minigame.minigameControlStruct._28[1];
            } else {
                r = random_fn_3_9EE24(2) + 1;
                g_Minigame.minigamePlayerSelectedOrder = g_Minigame.minigameControlStruct._28[r];
            }
            g_Minigame.rosterID = g_Minigame._19C6;
            g_Minigame._19C7 = 1;
        }
        k = 1;
        for (j = 0; j < 4; j++) {
            if (j != g_Minigame.minigamePlayerSelectedOrder && j != g_Minigame.rosterID) {
                g_Minigame.minigameControlStruct._28[k] = j;
                k++;
            }
        }
    }
    g_Minigame.minigameControlStruct._24[g_Minigame.rosterID] = 1;
    setInMemBatterConstants(g_Minigame.rosterID);
    g_Minigame._19C6 = g_Minigame.rosterID;
    g_Minigame.minigameControlStruct._28[0] = g_Minigame.minigamePlayerSelectedOrder;
    g_Minigame.minigameControlStruct._24[g_Minigame.minigamePlayerSelectedOrder] = 0;
    g_Minigame.minigameFielderIndex[g_Minigame.minigamePlayerSelectedOrder] = 0;
    g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigamePlayerSelectedOrder]]._20D = g_Minigame.minigameControlStruct._28[0];
    g_Minigame.minigameControlStruct._24[g_Minigame.minigameControlStruct._28[1]] = 0;
    g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[1]] = 3;
    g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[1]]]._20D = g_Minigame.minigameControlStruct._28[1];
    g_Minigame.minigameControlStruct._24[g_Minigame.minigameControlStruct._28[2]] = 0;
    g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[2]] = 4;
    g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[2]]]._20D = g_Minigame.minigameControlStruct._28[2];
    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameControlStruct._28[0] == i) {
            if (g_Minigame._19BE[i][0] == 0) {
                if (g_Minigame._19BE[i][1] < 0xFE) {
                    g_Minigame._19BE[i][1]++;
                } else {
                    g_Minigame._19BE[i][1] = 0xFF;
                }
            } else {
                g_Minigame._19BE[i][0] = 0;
                g_Minigame._19BE[i][1] = 1;
            }
        } else if (g_Minigame.rosterID == i) {
            if (g_Minigame._19BE[i][0] == 1) {
                if (g_Minigame._19BE[i][1] < 0xFE) {
                    g_Minigame._19BE[i][1]++;
                } else {
                    g_Minigame._19BE[i][1] = 0xFF;
                }
            } else {
                g_Minigame._19BE[i][0] = 1;
                g_Minigame._19BE[i][1] = 1;
            }
        } else if (g_Minigame._19BE[i][0] == 2) {
            if (g_Minigame._19BE[i][1] < 0xFE) {
                g_Minigame._19BE[i][1]++;
            } else {
                g_Minigame._19BE[i][1] = 0xFF;
            }
        } else {
            g_Minigame._19BE[i][0] = 2;
            g_Minigame._19BE[i][1] = 1;
        }
    }
    g_Minigame.turnNumberWithinRound = 0;
    g_Minigame.minigameControlStruct._14[0] = g_Minigame.rosterID;
    g_Minigame.minigameControlStruct._14[1] = g_Minigame.minigamePlayerSelectedOrder;
    g_Minigame.minigameControlStruct._14[2] = g_Minigame.minigameControlStruct._28[1];
    g_Minigame.minigameControlStruct._14[3] = g_Minigame.minigameControlStruct._28[2];
}

// .text:0x000DE744 size:0x44C mapped:0x8071D7D8
void fn_3_DE744(void) {
    s32 i;

    fn_3_DDF1C();
    fn_3_6C0E0();
    g_Runners[0].positionStored.x = g_Runners[0].position.x;
    g_Runners[0].positionStored.y = g_Runners[0].position.y;
    g_Runners[0].positionStored.z = g_Runners[0].position.z;
    g_Runners[0].unused_AIRelated = 1;
    g_Runners[0].battingHand = g_Batter.batterHand;
    g_Runners[0].batterStayInBattersBoxReason = 1;
    g_Runners[0].position.x = g_Batter.batterPos.x;
    g_Runners[0].position.y = 0.0f;
    g_Runners[0].position.z = g_Batter.batterPos.z;
    g_Runners[0].runningAngle = 3.1415927f;
    g_GameLogic.CountdownUntilFade = 10000;
    g_Strikes.storedOuts = g_Strikes.outs;
    g_Strikes.outs = 0;
    g_Strikes.storedOuts = 0;
    g_Ball.totalFramesAtPlay = 0;
    lbl_3_common_bss_34C90._1D5 = 0;
    g_Scores._C5 = 0;
    g_Minigame.turnOverStatus = 0;
    g_Minigame.pointsTargetReachedInd = 0;
    g_Minigame.toyFieldBallStateResult2 = 0;
    g_Minigame.framesSincePanelHit = 0;
    g_Minigame._1921 = 0;
    g_Minigame._1914_arr[0] = 1;
    g_Minigame.toyFieldStateInd_collisionRelated = 0;
    g_Minigame._1939 = 0;
    g_Minigame.panelHitInd = 0;
    g_Minigame._19A0 = 0;
    g_Minigame._1934 = 0;
    g_Minigame._18BA = 0;
    g_Minigame._19A3 = 0;
    g_Minigame.TF_framesSinceHittingPanel = 0;
    g_Minigame.TF_ballDespawnedInd = 0;
    g_Minigame._190E = 0;
    g_Minigame.maybeTFCollisionResultState = 0;
    g_Minigame.toyFieldBallStateResult = 0;
    g_Minigame._19BC = 0;
    g_Minigame._19D0 = 0;
    g_Minigame._19CD = 0;
    g_Minigame._19CF = 0;
    if (g_Minigame._19CE == 3) {
        fn_3_E67F4();
    }
    g_Minigame._19CE = 0;
    for (i = 0; i < 4; i++) {
        g_Minigame.minigamePoints_current_Latest[i][0] = g_Minigame.miniGameCurrentPoints[i];
        g_Minigame.minigamePoints_current_Latest[i][1] = 0;
        g_Minigame._1935[i] = -1;
    }
    for (i = 0; i < 100; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame._1914_arr[i]) {
            g_Minigame._191C[i] = i;
        } else {
            g_Minigame._191C[i] = -1;
        }
        g_Minigame._1918[i] = g_Minigame._1914_arr[i];
    }
    g_FieldingLogic._10E = 0;
    g_FieldingLogic._0EE = 0;
    g_FieldingLogic._10F = 0;
    g_FieldingLogic._110 = 0;
    g_FieldingLogic._128 = 0;
    g_FieldingLogic._129 = 0;
    g_FieldingLogic._0E4 = 0;
    g_RunningLogic._13 = 0;
    if (g_GameLogic.pre_PostMiniGameInd) {
        g_GameLogic.minigameLastTurnSuccessInd = 1;
        g_GameLogic.hudElementLoadingInd = 1;
    } else {
        g_GameLogic.minigameLastTurnSuccessInd = 0;
    }
    g_GameLogic.pre_PostMiniGameInd = 0;
    changeScene(1, 6);
    fn_3_5A6D4(GAME_STATUS_AT_BAT);
}

// .text:0x000DE610 size:0x134 mapped:0x8071D6A4
void fn_3_DE610(void) {
    g_Minigame.panelHitInd = 0;
    if (g_Minigame._19A6 != 0) {
        g_Minigame._19A6--;
        if (g_Pitcher.strikeOutOrWalk == 2 || g_Pitcher.strikeOutOrWalk == 3) {
            g_Minigame._19A6 = 3;
        }
    }
    g_Strikes.outs = 0;
    g_Strikes.storedOuts = 0;
    g_Minigame._19A5 = 1;
    if ((g_Minigame.rosterID != g_Minigame._19C6 || g_Minigame.minigameControlStruct._1C[g_Minigame.rosterID] == 1) &&
        g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns) {
        lbl_3_common_bss_34C90._1D2 = 0;
        fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    } else if (g_Minigame.toyField_turnNumber < g_Minigame.toyField_selectedTurns && g_Minigame.toyField_turnNumber % 10 == 0) {
        fn_3_5A6D4(GAME_STATUS_INNING_TRANSITION);
    } else {
        fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
    }
}

// .text:0x000DE4FC size:0x114 mapped:0x8071D590
void fn_3_DE4FC(void) {
    s32 i;
    s32 j;
    s16 points;
    s32 rank;

    for (i = 0; i < 4; i++) {
        g_Minigame.minigameControlStruct._1C[i] = 0;
        g_Minigame.minigameControlStruct._20[i] = 0;
    }
    for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        points = g_Minigame.miniGameCurrentPoints[i];
        rank = 1;
        for (j = 0; j < g_Minigame.miniGameNumberOfParticipants; j++) {
            if (g_Minigame.miniGameCurrentPoints[j] > points) {
                rank++;
            }
        }
        g_Minigame.minigameControlStruct._1C[i] = rank;
        g_Minigame.minigameControlStruct._20[i] = rank;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameControlStruct._1C[i] > 1) {
            break;
        }
    }
    if (i >= 4 && g_Minigame.miniGameNumberOfParticipants > 1) {
        g_Minigame.challenge_minigame_haven_tWonYetIndicator = 1;
    } else {
        g_Minigame.challenge_minigame_haven_tWonYetIndicator = 0;
    }
}

// .text:0x000DE308 size:0x1F4 mapped:0x8071D39C
void fn_3_DE308(int type) {
    s32 i;

    if (type == 20 || type == 21) {
        g_Minigame.miniGameLatestPoints[g_Minigame.rosterID] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][0];
        g_Minigame.miniGameLatestPoints[g_Minigame.minigamePlayerSelectedOrder] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][1];
        g_Minigame.miniGameLatestPoints[g_Fielders[g_Ball.fielderWBallIndex]._20D] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][2];
    } else {
        g_Minigame.miniGameLatestPoints[g_Minigame.rosterID] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][0];
        g_Minigame.miniGameLatestPoints[g_Minigame.minigamePlayerSelectedOrder] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][1];
        g_Minigame.miniGameLatestPoints[g_Minigame.minigameControlStruct._28[1]] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][2];
        g_Minigame.miniGameLatestPoints[g_Minigame.minigameControlStruct._28[2]] += g_Minigame.toyField_pointMultiplier * lbl_3_data_18BB8[type][2];
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame.miniGameLatestPoints[i] != 0) {
            g_Minigame.minigamePoints_current_Latest[i][0] = g_Minigame.miniGameCurrentPoints[i];
            g_Minigame.minigamePoints_current_Latest[i][1] = g_Minigame.miniGameLatestPoints[i];
        }
    }
}

// .text:0x000DDFA0 size:0x368 mapped:0x8071D034
void fn_3_DDFA0(void) {
    if (g_Pitcher.pitchTotalTimeCounter <= 0 && !lbl_3_common_bss_34C90._1D5) {
        fn_3_DCF44();
    }
    if (lbl_3_common_bss_34C90._1D5) {
        fn_3_DCED0();
    } else {
        fn_3_75560();
        atBat_batter();
        fn_3_2EA24();
        if (g_Minigame.toyFieldBallStateResult2 == 0 && g_Pitcher.strikeOutOrWalk != 0) {
            if (g_Pitcher.strikeOutOrWalk == 1) {
                g_Minigame.toyFieldBallStateResult2 = 2;
            } else if (g_Pitcher.strikeOutOrWalk == 2) {
                g_Minigame.toyFieldBallStateResult2 = 7;
            } else {
                g_Minigame.toyFieldBallStateResult2 = 8;
            }
        }
        if (g_Minigame.toyFieldBallStateResult2) {
            fn_3_DA834();
        }
        if (g_Minigame.turnOverStatus) {
            fn_3_DDD60();
        }
    }
}

// .text:0x000DDF1C size:0x84 mapped:0x8071CFB0
void fn_3_DDF1C(void) {
    fn_3_6EBB4(g_Minigame.minigamePlayerSelectedOrder);
    fn_3_F1DC();
    fn_3_751B4();
    setDefaultInMemBatter();
    fn_3_58870();
    fn_3_1DEB8();
    fn_3_BF1AC();
    Set_803cb848(1);
    fn_3_BF158();
    g_FieldingLogic._0AE = 0;
    g_GameLogic.homeRunWordAnimationCompletedInd = 0;
    g_UnkSimulation_31AC0._5 = 0;
    g_UnkSimulation_31AC0._6 = 4;
}

// .text:0x000DDD60 size:0x1BC mapped:0x8071CDF4
void fn_3_DDD60(void) {
    if (g_Minigame.turnOverStatus == 1) {
        g_Minigame.turnOverStatus = 2;
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[0];
    }
    g_GameLogic.CountdownUntilFade--;
    if (g_Minigame._19A0 && g_GameLogic.CountdownUntilFade < lbl_3_data_1899C[1]) {
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[1];
    }
    if (g_GameLogic.CountdownUntilFade == lbl_3_data_1899C[1] - 10) {
        if (g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns &&
            g_Minigame.minigameControlStruct._1C[g_Minigame.rosterID] == 1) {
            fn_3_59918(13, 0);
        } else if ((u8)g_Minigame.rosterID != g_Minigame._19C6) {
            if (g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns) {
                fn_3_59918(13, 0);
            } else {
                fn_3_59918(5, 0);
            }
        }
    }
    if (g_GameLogic.CountdownUntilFade == 7) {
        changeScene(3, 6);
    }
    if (g_GameLogic.CountdownUntilFade <= 0) {
        fn_3_DD37C();
    }
}

// .text:0x000DD9A4 size:0x3BC mapped:0x8071CA38
void fn_3_DD9A4(void) {
    s16 frames = g_Minigame.TF_framesSinceHittingPanel;

    if (frames != 0 && g_Ball.fielderWBallIndex < 0) {
        if (frames < lbl_3_data_18C48[6]) {
            g_Minigame.TF_framesSinceHittingPanel = frames + 1;
        } else if (!g_Minigame.TF_ballDespawnedInd) {
            g_Minigame.TF_ballDespawnedInd = 1;
            playStadiumSound(0x15);
        }
    }
    ballPhysica();
    fn_3_2F484();
    if (g_Minigame._19CF) {
        if (!g_Minigame._19CE) {
            fn_3_DC240();
        }
    } else if (g_Minigame.toyFieldBallStateResult && !g_Minigame.toyFieldBallStateResult2) {
        fn_3_DC240();
    } else if (!g_Minigame.toyFieldBallStateResult2) {
        fn_3_DC380();
    }
    if (g_Minigame.toyFieldBallStateResult2) {
        fn_3_DA834();
    }
    if (g_Minigame.turnOverStatus) {
        fn_3_DD3FC();
    }
}

// .text:0x000DD3FC size:0x5A8 mapped:0x8071C490
void fn_3_DD3FC(void) {
    s32 i;

    if (g_Minigame.turnOverStatus == 1) {
        g_Minigame.turnOverStatus = 2;
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[0];
        if (g_Minigame.toyFieldBallStateResult2 == 1 && !g_Ball.maybebuntOn2Strikes) {
            g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[2];
        }
    }
    g_GameLogic.CountdownUntilFade--;
    if (g_Minigame._19A0 && !g_Minigame._19CE && g_GameLogic.CountdownUntilFade < lbl_3_data_1899C[1]) {
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[1];
    }
    if (g_Minigame._1939 && g_GameLogic.CountdownUntilFade < lbl_3_data_1899C[1]) {
        g_GameLogic.CountdownUntilFade = lbl_3_data_1899C[1];
    }
    if (g_Minigame._19CE && g_Minigame._19CE < 3) {
        if (g_GameLogic.CountdownUntilFade <= lbl_3_data_1899C[1] - 10) {
            g_GameLogic.CountdownUntilFade++;
        }
        if (g_Minigame._19CE == 1) {
            fn_3_DE308(12);
            g_Minigame._19BA = 0;
            g_Minigame._19CE = 2;
            for (i = 0; i < 4; i++) {
                if (g_Minigame._1918[i]) {
                    g_Minigame._1914_arr[i] = 0;
                }
            }
            if (lbl_800EF808._398 == 1) {
                playStadiumSound(0x1A);
            }
        }
        if (g_Minigame._19BA < 0x7FFE) {
            g_Minigame._19BA++;
        } else {
            g_Minigame._19BA = 0x7FFF;
        }
        if (g_Minigame._19BA > lbl_3_data_18C48[3]) {
            g_Minigame._19CE = 3;
        }
    }
    if (!g_Minigame.TF_ballDespawnedInd && g_Ball.fielderWBallIndex < 0 && !g_Ball.deadBallReason && g_Ball.AtBat_ContactResult >= 0 &&
        g_GameLogic.CountdownUntilFade <= lbl_3_data_1899C[1] - 10 + lbl_3_data_49DC[11]) {
        g_GameLogic.CountdownUntilFade++;
    }
    if (g_GameLogic.CountdownUntilFade == lbl_3_data_1899C[1] - 10) {
        if (g_Minigame._19CD == 1 || g_Minigame._19CD == 2 || (g_Minigame._19CD != 3 && g_Minigame._1921)) {
            g_GameLogic.CountdownUntilFade++;
        } else if (g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns &&
                   g_Minigame.minigameControlStruct._1C[g_Minigame.rosterID] == 1) {
            fn_3_59918(13, 0);
        } else if ((u8)g_Minigame.rosterID != g_Minigame._19C6) {
            if (g_Minigame.toyField_turnNumber >= g_Minigame.toyField_selectedTurns) {
                fn_3_59918(13, 0);
            } else {
                fn_3_59918(5, 0);
            }
        }
        if (g_Minigame._19BC < 0x7FFE) {
            g_Minigame._19BC++;
        } else {
            g_Minigame._19BC = 0x7FFF;
        }
    }
    if (g_GameLogic.CountdownUntilFade == 7) {
        changeScene(3, 6);
    }
    if (g_GameLogic.CountdownUntilFade <= 0) {
        fn_3_DD37C();
    }
}

// .text:0x000DD37C size:0x80 mapped:0x8071C410
void fn_3_DD37C(void) {
    if (g_Minigame._19CE) {
        fn_3_FBD70();
        fn_3_FBD58();
    }
    g_GameLogic.pre_PostMiniGameInd = 1;
    g_GameLogic.minigameLastTurnSuccessInd = 1;
    g_GameLogic.hudLoadingRelated = 1;
    fn_3_1DD48();
    if (!g_Minigame.pointsTargetReachedInd) {
        fn_3_2E87C();
        fn_3_5A6D4(GAME_STATUS_DEFAULT);
    } else {
        fn_3_5A6D4(GAME_STATUS_TRANSITION);
    }
}

static inline BOOL isSceneSkipped(void) {
    BOOL done = FALSE;

    if (g_GameLogic.FrameCountOfCurrentPitch >= lbl_3_data_18C48[2]) {
        done = TRUE;
    } else if (g_GameLogic.FrameCountOfCurrentAtBat_Copy >= lbl_3_data_18C48[1] && fn_3_6C938(1, 0x1100)) {
        done = TRUE;
    }
    return done;
}

// .text:0x000DD1A8 size:0x1D4 mapped:0x8071C23C
void fn_3_DD1A8(void) {
    s32 i;
    s8 id;

    switch (g_GameLogic._125) {
    case 0:
        if (g_Minigame.toyField_turnNumber == 0) {
            if (random_fn_3_9EE24(100) < lbl_3_data_18C48[7] || g_Minigame._1907 == 4) {
                i = 0;
                do {
                    id = random_fn_3_9EE24(4);
                    g_Minigame.rosterID = id;
                    i++;
                } while (i < 100 && g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.rosterID] != 0);
            } else {
                i = 0;
                do {
                    id = random_fn_3_9EE24(4);
                    g_Minigame.rosterID = id;
                    i++;
                } while (i < 100 && g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.rosterID] == 0);
            }
        }
        changeScene(1, 6);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125 = 1;
        break;
    case 1:
        if (isSceneSkipped()) {
            g_GameLogic._125 = 2;
            changeScene(3, 6);
        }
        break;
    case 2:
        if (lbl_8037169C._13) {
            fn_3_FBD70();
            fn_3_FBD58();
            fn_3_5A6D4(GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY);
        }
        break;
    }
}

// .text:0x000DD000 size:0x1A8 mapped:0x8071C094
void fn_3_DD000(void) {
    switch (g_GameLogic._125) {
    case 0:
        changeScene(1, 6);
        g_GameLogic._125 = 1;
        break;
    case 1:
        if (g_GameLogic.FrameCountOfCurrentPitch > 1800) {
            g_GameLogic._125 = 2;
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        } else if (g_GameLogic.FrameCountOfCurrentPitch > 300 && fn_3_6C938(1, 0x1100)) {
            g_GameLogic._125 = 2;
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        }
        break;
    case 2:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 30) {
            if (g_Minigame._190A) {
                g_GameLogic._125 = 4;
            } else {
                g_GameLogic._125 = 3;
            }
        }
        break;
    case 3:
        lbl_3_common_bss_34C90._1D1 = 0;
        lbl_3_common_bss_34C90._1D2 = 0;
        fn_3_5A6D4(0x22);
        break;
    case 4:
        changeScene(4, 6);
        if (lbl_8037169C._13) {
            g_GameLogic._125 = 10;
        }
        break;
    case 5:
        if (g_Minigame.challenge_minigame_haven_tWonYetIndicator) {
            g_d_GameSettings._38 = 0;
        } else {
            g_d_GameSettings._38 = g_Minigame.minigameControlStruct._1C[g_d_GameSettings._35];
        }
        g_GameLogic.framesOfExitingToMenu = 1;
        break;
    }
}

// .text:0x000DCF44 size:0xBC mapped:0x8071BFD8
void fn_3_DCF44(void) {
    s32 i;

    for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0 && !g_Minigame.minigameControlStruct.battingHandedness[i] &&
            (g_Controls[g_Minigame.minigameControlStruct.characterIndex[i]].newButtonInput & INPUT_BUTTON_START)) {
            lbl_3_common_bss_34C90._1D5 = 1;
            lbl_3_common_bss_34C90._000 = g_Minigame.minigameControlStruct.characterIndex[i];
            fn_3_AFD80(0);
            fn_3_59918(14, 0);
            break;
        }
    }
}

// .text:0x000DCED0 size:0x74 mapped:0x8071BF64
void fn_3_DCED0(void) {
    if (lbl_3_common_bss_34C90._00C < 0x7FFE) {
        lbl_3_common_bss_34C90._00C++;
    } else {
        lbl_3_common_bss_34C90._00C = 0x7FFF;
    }
    lbl_803CBC3C[0] = 1;
    if (lbl_3_common_bss_34C90._00C > 60) {
        fn_3_AFD80(1);
        fn_3_5A6D4(GAME_STATUS_PAUSED);
    } else {
        fn_3_2EA24();
    }
}

// .text:0x000DCC80 size:0x250 mapped:0x8071BD14
void fn_3_DCC80(void) {
    if (lbl_3_common_bss_34C90._00C < 0x7FFE) {
        lbl_3_common_bss_34C90._00C++;
    } else {
        lbl_3_common_bss_34C90._00C = 0x7FFF;
    }
    if (lbl_3_common_bss_34C90._012 < 0x7FFE) {
        lbl_3_common_bss_34C90._012++;
    } else {
        lbl_3_common_bss_34C90._012 = 0x7FFF;
    }
    lbl_803CBC3C[0] = 1;
    lbl_3_common_bss_34C90._004 = g_Controls[lbl_3_common_bss_34C90._000].buttonInput;
    lbl_3_common_bss_34C90._006 = g_Controls[lbl_3_common_bss_34C90._000].newButtonInput;
    lbl_3_common_bss_34C90._008 = g_Controls[lbl_3_common_bss_34C90._000]._08;
    switch (lbl_3_common_bss_34C90._1D2) {
    case 0:
        lbl_3_common_bss_34C90._1DA = 0;
        lbl_3_common_bss_34C90._1D5 = 0;
        lbl_3_common_bss_34C90._1D0 = 0x11;
        lbl_3_common_bss_34C90._1D2 = 1;
        break;
    case 1:
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D2 = 2;
        break;
    case 2:
        if (lbl_3_common_bss_34C90._012 >= 20) {
            lbl_3_common_bss_34C90._1D2 = 3;
        }
        break;
    case 3:
        fn_3_DCA68();
        lbl_3_common_bss_34C90._012 = 0;
        break;
    case 4:
        lbl_3_common_bss_34C90._1D9 = 1;
        lbl_3_common_bss_34C90._1D2 = 5;
        break;
    case 5:
        if (lbl_3_common_bss_34C90._1D9 == 3) {
            fn_3_5A6D4(GAME_STATUS_AT_BAT);
        }
        break;
    case 6:
        lbl_3_common_bss_34C90._1D9 = 1;
        lbl_3_common_bss_34C90._1D2 = 7;
        break;
    case 7:
        if (lbl_3_common_bss_34C90._1D9 == 3) {
            lbl_3_common_bss_34C90._220 = 2;
            lbl_3_common_bss_34C90._1D2 = 0;
            fn_3_5A6D4(GAME_STATUS_HOW_TO_PLAY_SCREEN);
        }
        break;
    case 8:
        fn_3_107E80();
        break;
    case 9:
        switch (fn_3_5B380(lbl_3_common_bss_34C90._006)) {
        case 1:
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            lbl_3_common_bss_34C90._1D2 = 10;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 3;
            break;
        }
        break;
    case 10:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
            changeScene(4, 6);
        }
        if (lbl_8037169C._13) {
            lbl_3_common_bss_34C90._1D9 = 2;
            g_d_GameSettings._13 = 1;
            fn_8004CC18();
            g_GameLogic.framesOfExitingToMenu = 1;
        }
        break;
    }
}

// .text:0x000DCA68 size:0x218 mapped:0x8071BAFC
void fn_3_DCA68(void) {
    if (lbl_3_common_bss_34C90._006 & PAD_BUTTON_START) {
        lbl_3_common_bss_34C90._1D2 = 4;
        sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
    } else if (lbl_3_common_bss_34C90._006 & PAD_BUTTON_A) {
        if (lbl_3_common_bss_34C90._1DA == 0) {
            lbl_3_common_bss_34C90._1D2 = 4;
            sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
        } else if (lbl_3_common_bss_34C90._1DA == 1) {
            lbl_3_common_bss_34C90._1D2 = 8;
            lbl_3_common_bss_34C90._1D4 = 0;
            sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
        } else if (lbl_3_common_bss_34C90._1DA == 2) {
            lbl_3_common_bss_34C90._1D2 = 6;
            sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
        } else if (lbl_3_common_bss_34C90._1DA == 3) {
            fn_3_5B408();
            lbl_3_common_bss_34C90._1D2 = 9;
            sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
        }
    } else if (lbl_3_common_bss_34C90._006 & PAD_BUTTON_B) {
        if (lbl_3_common_bss_34C90._1DA != 0) {
            lbl_3_common_bss_34C90._1DA = 0;
        } else {
            lbl_3_common_bss_34C90._1D2 = 4;
        }
        sndFXStart(0x1B9, lbl_800EFBA4[2], 0x3F);
    } else if (lbl_3_common_bss_34C90._008 & PAD_BUTTON_UP) {
        if (lbl_3_common_bss_34C90._1DA > 0) {
            lbl_3_common_bss_34C90._1DA--;
        } else {
            lbl_3_common_bss_34C90._1DA = 3;
        }
        sndFXStart(0x1B7, lbl_800EFBA4[0], 0x3F);
    } else if (lbl_3_common_bss_34C90._008 & PAD_BUTTON_DOWN) {
        lbl_3_common_bss_34C90._1DA++;
        if (lbl_3_common_bss_34C90._1DA >= 4) {
            lbl_3_common_bss_34C90._1DA = 0;
        }
        sndFXStart(0x1B7, lbl_800EFBA4[0], 0x3F);
    }
}

// .text:0x000DC6E8 size:0x380 mapped:0x8071B77C
void fn_3_DC6E8(void) {
    BOOL started;

    if (lbl_3_common_bss_34C90._012 < 0x7FFE) {
        lbl_3_common_bss_34C90._012++;
    } else {
        lbl_3_common_bss_34C90._012 = 0x7FFF;
    }
    switch (lbl_3_common_bss_34C90._1D2) {
    case 0:
        lbl_3_common_bss_34C90._1DA = 0;
        lbl_3_common_bss_34C90._1D0 = 0x12;
        lbl_3_common_bss_34C90._1D2 = 1;
        break;
    case 1:
        lbl_3_common_bss_34C90._012 = 0;
        lbl_3_common_bss_34C90._1D2 = 2;
        break;
    case 2:
        if (lbl_3_common_bss_34C90._012 >= 20) {
            lbl_3_common_bss_34C90._1D2 = 3;
        }
        break;
    case 3:
        fn_3_DC5A4();
        lbl_3_common_bss_34C90._012 = 0;
        break;
    case 4:
        if (lbl_3_common_bss_34C90._012 >= 20) {
            changeScene(3, 6);
        }
        if (lbl_8037169C._13) {
            lbl_3_common_bss_34C90._1D2 = 5;
        }
        break;
    case 5:
        lbl_8036E548._307A = 0;
        lbl_3_common_bss_34C90._1D9 = 2;
        started = FALSE;
        if (lbl_3_common_bss_34C90._1DA == 0) {
            fn_3_5A6D4(GAME_STATUS_GAME_START_MOVIE);
            g_Minigame._1A38 = 1;
            started = TRUE;
        } else if (lbl_3_common_bss_34C90._1DA == 1) {
            g_Minigame._19DF = 30;
            fn_3_5A6D4(GAME_STATUS_TOY_STADIUM_LOAD);
            started = TRUE;
        }
        if (started) {
            fn_3_DF8D4();
            fn_3_15F998();
            fn_3_147DFC();
            if (lbl_3_common_bss_34C90._1DA == 1) {
                fn_3_11CF84();
            }
        }
        break;
    case 9:
        switch (fn_3_5B380(g_Controls[lbl_3_common_bss_34C90._000].newButtonInput)) {
        case 1:
            fn_3_15F998();
            fn_3_147DFC();
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            lbl_3_common_bss_34C90._1D2 = 10;
            break;
        case 2:
            lbl_3_common_bss_34C90._1D2 = 3;
            break;
        }
        break;
    case 10:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 45) {
            changeScene(4, 6);
        }
        if (lbl_8037169C._13) {
            lbl_3_common_bss_34C90._1D9 = 2;
            fn_8004CC18();
            g_GameLogic.framesOfExitingToMenu = 1;
        }
        break;
    }
}

// .text:0x000DC5A4 size:0x144 mapped:0x8071B638
void fn_3_DC5A4(void) {
    int pad;

    if ((pad = fn_3_6C938(1, 0x100)) != 0) {
        lbl_3_common_bss_34C90._000 = pad - 1;
        if (lbl_3_common_bss_34C90._1DA == 2) {
            fn_3_5B408();
            lbl_3_common_bss_34C90._1D2 = 9;
        } else {
            lbl_3_common_bss_34C90._1D2 = 4;
        }
        sndFXStart(0x1B8, lbl_800EFBA4[1], 0x3F);
    } else if (fn_3_6C938(1, 8)) {
        if (lbl_3_common_bss_34C90._1DA != 0) {
            lbl_3_common_bss_34C90._1DA--;
        } else {
            lbl_3_common_bss_34C90._1DA = 2;
        }
        sndFXStart(0x1B7, lbl_800EFBA4[0], 0x3F);
    } else if (fn_3_6C938(1, 4)) {
        lbl_3_common_bss_34C90._1DA++;
        if (lbl_3_common_bss_34C90._1DA >= 3) {
            lbl_3_common_bss_34C90._1DA = 0;
        }
        sndFXStart(0x1B7, lbl_800EFBA4[0], 0x3F);
    }
}

// .text:0x000DC380 size:0x224 mapped:0x8071B414
void fn_3_DC380(void) {
    s32 code;
    s16 result;
    Unk28A8Fielder* fielder;

    if (g_Ball.framesSinceLastBounce == 0 && g_Ball.ballBounceState != 3) {
        code = g_Ball.collisionCode;
        if (code >= 0x80) {
            code -= 0x80;
        }
        if (code >= 0x70 && code < 0x79) {
            g_Minigame.maybeTFCollisionResultState = lbl_3_data_189AC[code - 0x70];
        }
    }
    result = g_Ball.AtBat_ContactResult;
    if (result == -1) {
        g_Minigame.toyFieldBallStateResult = 1;
    } else if (g_Minigame.toyFieldStateInd_collisionRelated) {
        g_Minigame.toyFieldBallStateResult = lbl_3_data_189AC[g_Minigame.toyFieldStateInd_collisionRelated - 0x70];
    } else if (g_Ball.deadBallReason) {
        if (g_Ball.deadBallReason == 1) {
            g_Minigame.toyFieldBallStateResult = 6;
        } else if (g_Ball.deadBallReason == 3) {
            g_Minigame.toyFieldBallStateResult = 4;
        } else {
            g_Minigame.toyFieldBallStateResult = 1;
        }
        g_Minigame.turnOverStatus = 1;
    } else if (result != 0) {
        if (g_Ball.ballState == 1) {
            fielder = &g_Fielders[g_Ball.fielderWBallIndex];
            if (fielder->_1EE || fielder->_1EC) {
                return;
            }
        } else if (!(g_Ball.ballVelocity < 0.003f || g_Ball.groundRuleDoubleInd || g_Ball.ballStoppingCode1ReallySlow2Stopped == 2)) {
            return;
        }
        if (result == 3) {
            g_Minigame.toyFieldBallStateResult = 2;
        } else {
            if (g_Minigame.maybeTFCollisionResultState == 0) {
                if (fn_3_B7E10(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
                    g_Minigame.toyFieldBallStateResult = 1;
                } else {
                    g_Minigame.toyFieldBallStateResult = 2;
                }
            } else {
                g_Minigame.toyFieldBallStateResult = g_Minigame.maybeTFCollisionResultState;
            }
            g_Minigame.lastKnownBallPosX = g_Ball.AtBat_Contact_BallPos.x;
            g_Minigame.lastKnownBallPosZ = g_Ball.AtBat_Contact_BallPos.z;
            g_Minigame.TF_framesSinceHittingPanel = 1;
        }
    }
}

// .text:0x000DC240 size:0x140 mapped:0x8071B2D4
void fn_3_DC240(void) {
    g_Minigame.toyFieldBallStateResult2 = g_Minigame.toyFieldBallStateResult;
    if (fn_3_E5924()) {
        if (g_Minigame._19CF == 0) {
            g_Minigame.toyFieldBallStateResult2 = 12;
        }
        if (g_Minigame._19CF > 60) {
            g_Minigame._19CE = 1;
        } else if (g_Minigame._19CF < 0xFE) {
            g_Minigame._19CF++;
        } else {
            g_Minigame._19CF = 0xFF;
        }
    } else if (g_Minigame.toyFieldBallStateResult2 == 2 || g_Ball.maybebuntOn2Strikes) {
        if (!g_Ball.maybebuntOn2Strikes) {
            fn_3_59918(1, 0);
        }
        g_Minigame._19C6 = g_Minigame.minigamePlayerSelectedOrder;
        if (g_Ball.fielderWBallIndex >= 0) {
            g_Minigame._19C6 = g_Fielders[g_Ball.fielderWBallIndex]._20D;
        }
    } else if (g_Minigame.toyFieldBallStateResult2 == 1) {
        fn_3_A0F0();
    } else if (g_Minigame.toyFieldBallStateResult2 == 6) {
        fn_3_59918(15, 0);
    }
}

// .text:0x000DA834 size:0x1A0C mapped:0x807198C8
void fn_3_DA834(void) {
    s32 i;
    s32 j;
    s32 n;

    if (g_Minigame.framesSincePanelHit < 0x7FFE) {
        g_Minigame.framesSincePanelHit++;
    } else {
        g_Minigame.framesSincePanelHit = 0x7FFF;
    }
    if (g_Minigame.framesSincePanelHit <= 1) {
        if (g_Minigame.toyFieldBallStateResult2 == 1 && !g_Ball.maybebuntOn2Strikes) {
            g_Minigame.turnOverStatus = 1;
            fn_3_DE308(11);
            return;
        }
        g_Minigame.panelHitInd = 1;
        if (g_Minigame.toyFieldBallStateResult2 >= 1 && g_Minigame.toyFieldBallStateResult2 <= 8) {
            g_Minigame.turnOverStatus = 1;
            switch (g_Minigame.toyFieldBallStateResult2) {
            case 1:
                fn_3_DE308(22);
                break;
            case 2:
                if (g_Pitcher.strikeOutOrWalk == 1 || g_Ball.maybebuntOn2Strikes) {
                    fn_3_DE308(22);
                } else if (g_Minigame.toyFieldStateInd_collisionRelated == 0x71) {
                    fn_3_DE308(9);
                } else {
                    fn_3_DE308(10);
                }
                break;
            case 3:
                fn_3_DE308(0);
                break;
            case 4:
                fn_3_DE308(1);
                break;
            case 5:
                fn_3_DE308(2);
                break;
            case 6:
                if (g_Ball.deadBallReason == 1) {
                    fn_3_DE308(4);
                } else {
                    fn_3_DE308(3);
                }
                break;
            case 7:
                fn_3_DE308(23);
                break;
            case 8:
                fn_3_DE308(23);
                break;
            }
            if (g_Minigame.toyFieldBallStateResult2 >= 3 && g_Minigame.toyFieldBallStateResult2 <= 6) {
                playStadiumSound(0);
            }
            if (g_Minigame.toyFieldBallStateResult2 == 2 || g_Ball.maybebuntOn2Strikes) {
                if (g_Ball.fielderWBallIndex >= 0) {
                    g_Minigame._19C6 = g_Fielders[g_Ball.fielderWBallIndex]._20D;
                } else {
                    g_Minigame._19C6 = g_Minigame.minigamePlayerSelectedOrder;
                }
            }
        } else if (g_Minigame.toyFieldBallStateResult2 == 11) {
            fn_3_D9A30();
            fn_3_D9868();
            g_Minigame.TF_framesSinceHittingPanel = 1;
        } else if (g_Minigame.toyFieldBallStateResult2 == 9 || g_Minigame.toyFieldBallStateResult2 == 10) {
            if (g_Minigame.lastKnownBallPosX < 0.0f) {
                fn_3_DA640(30, 6);
            } else {
                fn_3_DA640(30, 4);
            }
            g_Minigame.TF_framesSinceHittingPanel = 1;
            g_Minigame._199E = 0;
        } else {
            g_Minigame.turnOverStatus = 1;
        }
        if (g_Minigame.toyFieldBallStateResult2 >= 3 && g_Minigame.toyFieldBallStateResult2 <= 6) {
            n = g_Minigame.toyFieldBallStateResult2 - 2;
            for (j = 0; j < n; j++) {
                if (g_Minigame._1914_arr[3]) {
                    g_Minigame._1921++;
                }
                for (i = 3; i > 0; i--) {
                    g_Minigame._1914_arr[i] = g_Minigame._1914_arr[i - 1];
                    g_Minigame._1914_arr[i - 1] = 0;
                }
            }
            for (i = 0; i < 4; i++) {
                if (g_Minigame._191C[i] >= 0) {
                    g_Minigame._191C[i] += n;
                    if (g_Minigame._191C[i] >= 4) {
                        g_Minigame._191C[i] = 4;
                    }
                }
            }
        }
        if (g_Minigame.toyFieldBallStateResult2 == 7 || g_Minigame.toyFieldBallStateResult2 == 8) {
            if (g_Minigame._1914_arr[3]) {
                g_Minigame._1921++;
            }
            for (n = 1; n < 4; n++) {
                if (!g_Minigame._1914_arr[n]) {
                    break;
                }
            }
            for (i = n; i >= 1; i--) {
                g_Minigame._1914_arr[i] = g_Minigame._1914_arr[i - 1];
                g_Minigame._1914_arr[i - 1] = 0;
            }
            for (i = 0; i < 4; i++) {
                if (g_Minigame._191C[i] < 0) {
                    break;
                }
                g_Minigame._191C[i]++;
                if (g_Minigame._191C[i] >= 4) {
                    g_Minigame._191C[i] = 4;
                }
            }
        }
        for (i = 0; i < 4; i++) {
            if (g_Ball.fielderWBallIndex >= 0 && g_Minigame.minigameFielderIndex[i] == g_Ball.fielderWBallIndex) {
                if (g_Ball.AtBat_ContactResult == 3) {
                    fn_3_DE308(20);
                } else {
                    fn_3_DE308(21);
                }
                break;
            }
        }
        g_Minigame.pointsTargetReachedInd = 1;
    } else {
        if (g_Minigame.toyFieldBallStateResult2 == 11) {
            if (g_Minigame._1934 == 0) {
                if (g_Minigame._18B8 < 0x7FFE) {
                    g_Minigame._18B8++;
                } else {
                    g_Minigame._18B8 = 0x7FFF;
                }
                for (i = 0; i < 3; i++) {
                    if (g_Minigame._1927[i] == 0) {
                        if (g_Minigame._18B8 > lbl_3_data_189B8[i]) {
                            g_Minigame._1927[i] = 1;
                        }
                    } else if (g_Minigame._1927[i] == 1) {
                        if (i == 0) {
                            if (g_Minigame._18B8 > lbl_3_data_189B8[3]) {
                                g_Minigame._1927[i] = 2;
                            }
                        } else if (i == 2) {
                            if (g_Minigame._1931[i - 1] == 3) {
                                g_Minigame._1927[i] = 2;
                            }
                        } else if (g_Minigame._1931[i - 1] >= 2) {
                            g_Minigame._1927[i] = 2;
                        }
                    }
                }
            } else if (g_Minigame._1934 == 1) {
            } else if (g_Minigame._1934 == 2) {
                fn_3_D8CD0();
                g_Minigame._1934 = 3;
            } else {
                if (g_Minigame._192D == 6) {
                    g_Minigame._19A6 = 3;
                    if (g_Minigame._18BA == 1) {
                        fn_3_E8AC8();
                    }
                }
                if (g_Minigame._18BA < 0x7FFE) {
                    g_Minigame._18BA++;
                } else {
                    g_Minigame._18BA = 0x7FFF;
                }
            }
        }
        if (g_Minigame.toyFieldBallStateResult2 == 9 || g_Minigame.toyFieldBallStateResult2 == 10) {
            fn_3_D9EA0();
        }
    }
}

// .text:0x000DA640 size:0x1F4 mapped:0x807196D4
void fn_3_DA640(s32 count, s32 idx) {
    f32 x;
    f32 z;
    s32 i;
    f32 radius;
    f32 dist;
    int ang;
    int r;
    f32 speed;

    g_Minigame._1939 = count;
    g_Minigame.panelHitInd = 1;
    radius = lbl_3_data_18AC8[idx].radius[0];
    g_Minigame.wallBall_coinsVisibleFrameCounter[0] = 0;
    if (count >= 20) {
        radius = lbl_3_data_18AC8[idx].radius[1];
    }
    for (i = 0; i < count; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 1;
        g_Minigame.wallBall_coinCoordinates[i].y = 0.8f;
        r = rand();
        dist = 0.001f * (r % (int)(1000.0f * radius));
        ang = rand() % 4096;
        ang = fn_3_9FE6C_normalizeAngle(ang);
        getComponentsFromSAng(ang, &x, &z);
        g_Minigame.wallBall_coinCoordinates[i].x = x * dist + lbl_3_data_18AC8[idx].x;
        g_Minigame.wallBall_coinCoordinates[i].z = z * dist + lbl_3_data_18AC8[idx].z;
        speed = RandomF32_Game_Range(0.0f, 0.03f);
        g_Minigame.wallBall_coinVelocity[i].x = x * speed;
        g_Minigame.wallBall_coinVelocity[i].z = z * speed;
        g_Minigame.wallBall_coinVelocity[i].y = RandomF32_Game_Range(0.08f, 0.12f);
    }
}

// .text:0x000D9EA0 size:0x7A0 mapped:0x80718F34
void fn_3_D9EA0(void) {
    s32 i;
    Unk28A8Fielder* fielder;
    f32 dx;
    f32 dz;
    f32 dist0;
    f32 dist1;
    f32 dist2;
    s32 closest;
    f32 dx2;
    f32 dz2;

    if (g_Minigame._1939) {
        if (g_Minigame.wallBall_coinsVisibleFrameCounter[0] < 0x7FFE) {
            g_Minigame.wallBall_coinsVisibleFrameCounter[0]++;
        } else {
            g_Minigame.wallBall_coinsVisibleFrameCounter[0] = 0x7FFF;
        }
        for (i = 0; i < 100; i++) {
            if (g_Minigame.wallBall_coinsVisibleInd[i]) {
                if (g_Minigame.wallBall_coinsVisibleFrameCounter[0] > lbl_3_data_18BB0[g_Minigame._199E][0]) {
                    g_Minigame.wallBall_coinsVisibleInd[i] = 0;
                } else {
                    g_Minigame.wallBall_coinVelocity[i].y -= lbl_3_data_18B9C[0];
                    g_Minigame.wallBall_coinVelocity[i].x *= lbl_3_data_18B9C[1];
                    g_Minigame.wallBall_coinVelocity[i].y *= lbl_3_data_18B9C[1];
                    g_Minigame.wallBall_coinVelocity[i].z *= lbl_3_data_18B9C[1];
                    g_Minigame.wallBall_coinCoordinates[i].x += g_Minigame.wallBall_coinVelocity[i].x;
                    g_Minigame.wallBall_coinCoordinates[i].y += g_Minigame.wallBall_coinVelocity[i].y;
                    g_Minigame.wallBall_coinCoordinates[i].z += g_Minigame.wallBall_coinVelocity[i].z;
                    if (g_Minigame.wallBall_coinCoordinates[i].y <= lbl_3_data_18B9C[3]) {
                        g_Minigame.wallBall_coinCoordinates[i].y = lbl_3_data_18B9C[3];
                        g_Minigame.wallBall_coinVelocity[i].y = -g_Minigame.wallBall_coinVelocity[i].y;
                        g_Minigame.wallBall_coinVelocity[i].x *= lbl_3_data_18B9C[2];
                        g_Minigame.wallBall_coinVelocity[i].y *= lbl_3_data_18B9C[2];
                        g_Minigame.wallBall_coinVelocity[i].z *= lbl_3_data_18B9C[2];
                    }
                }
            }
        }
        for (i = 0; i < 100; i++) {
            if (g_Minigame.wallBall_coinsVisibleInd[i]) {
                dist1 = dist2 = 999.9f;
                fielder = &g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[0]]];
                dx = g_Minigame.wallBall_coinCoordinates[i].x - fielder->x;
                dz = g_Minigame.wallBall_coinCoordinates[i].z - fielder->z;
                dx2 = dx * dx;
                dz2 = dz * dz;
                dist0 = dolsqrtf2(dx2 + dz2);
                if (g_Minigame.minigameControlStruct._28[1] >= 0) {
                    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[1]]];
                    dx = g_Minigame.wallBall_coinCoordinates[i].x - fielder->x;
                    dz = g_Minigame.wallBall_coinCoordinates[i].z - fielder->z;
                    dx2 = dx * dx;
                    dz2 = dz * dz;
                    dist1 = dolsqrtf2(dx2 + dz2);
                }
                if (g_Minigame.minigameControlStruct._28[2] >= 0) {
                    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._28[2]]];
                    dx = g_Minigame.wallBall_coinCoordinates[i].x - fielder->x;
                    dz = g_Minigame.wallBall_coinCoordinates[i].z - fielder->z;
                    dx2 = dx * dx;
                    dz2 = dz * dz;
                    dist2 = dolsqrtf2(dx2 + dz2);
                }
                if (dist0 < dist2) {
                    if (dist0 < dist1) {
                        dist1 = dist0;
                        closest = g_Minigame.minigameControlStruct._28[0];
                    } else {
                        closest = g_Minigame.minigameControlStruct._28[1];
                    }
                } else if (dist1 < dist2) {
                    closest = g_Minigame.minigameControlStruct._28[1];
                } else {
                    dist1 = dist2;
                    closest = g_Minigame.minigameControlStruct._28[2];
                }
                if (dist1 < lbl_3_data_18B88[g_Fielders[g_Minigame.minigameFielderIndex[closest]]._1C9]) {
                    g_Minigame.wallBall_coinsVisibleInd[i] = 0;
                    g_Minigame.miniGameCurrentPoints[closest] += lbl_3_data_18C48[8] * g_Minigame.toyField_pointMultiplier;
                    if (--g_Minigame._1939 == 0 && !g_Minigame.turnOverStatus) {
                        g_Minigame.turnOverStatus = 1;
                    }
                    if (!lbl_3_common_bss_34C58._30) {
                        playStadiumSound(0xC);
                        lbl_3_common_bss_34C58._30 = lbl_3_data_88DC[0];
                    }
                }
            }
        }
        if (g_Minigame.wallBall_coinsVisibleFrameCounter[0] > lbl_3_data_18BB0[g_Minigame._199E][0]) {
            if (!g_Minigame.turnOverStatus) {
                g_Minigame.turnOverStatus = 1;
            }
            if (g_Minigame._1939) {
                g_Minigame.miniGameLatestPoints[g_Minigame.rosterID] = g_Minigame._1939 * g_Minigame.toyField_pointMultiplier;
                g_Minigame.minigamePoints_current_Latest[g_Minigame.rosterID][0] = g_Minigame.miniGameCurrentPoints[g_Minigame.rosterID];
                g_Minigame.minigamePoints_current_Latest[g_Minigame.rosterID][1] = g_Minigame.miniGameLatestPoints[g_Minigame.rosterID];
                g_Minigame._1939 = 0;
            }
        }
    }
}

// .text:0x000D9A30 size:0x470 mapped:0x80718AC4
void fn_3_D9A30(void) {
    int phase;
    int rank;
    s32 i;
    int flags;
    int third;
    s16 points;
    BOOL same;
    s32 j;

    phase = 0;
    rank = 1;
    same = FALSE;
    third = g_Minigame.toyField_selectedTurns / 3;
    if (third * 2 > g_Minigame.toyField_turnNumber) {
        phase = 2;
    } else if (third > g_Minigame.toyField_turnNumber) {
        phase = 1;
    }
    flags = 0;
    points = g_Minigame.miniGameCurrentPoints[g_Minigame.rosterID];
    for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
        if (i == g_Minigame.rosterID) {
            continue;
        }
        if (points < g_Minigame.miniGameCurrentPoints[i]) {
            flags |= 1;
        }
        if (points > g_Minigame.miniGameCurrentPoints[i]) {
            flags |= 0x10;
        }
    }
    if (!(flags & 1)) {
        rank = 0;
    } else if (!(flags & 0x10)) {
        rank = 2;
    }
    g_Minigame._192D = RandomIndexFromWeights(lbl_3_data_189F0[g_Minigame.miniGameNumberOfParticipants - 2][phase][rank], 8);
    if (!g_d_GameSettings.exhibitionMatchInd && g_Minigame.rosterID == lbl_3_common_bss_37400._40) {
        fn_3_1608F0(7, g_Minigame._192D, 0);
    }
    if (g_Minigame._192D == 7) {
        if (!g_Minigame._1914_arr[1] && !g_Minigame._1914_arr[2] && !g_Minigame._1914_arr[3]) {
            g_Minigame._192D = 8;
        } else if (rand() % 100 < lbl_3_data_189B8[5]) {
            g_Minigame._192D = 8;
        }
        if (g_Minigame._192D == 8 && rand() % 99 < lbl_3_data_189B8[4]) {
            same = TRUE;
        }
    }
    for (i = 0; i < 3; i++) {
        g_Minigame._192A[i] = random_fn_3_9EE24(7);
        g_Minigame._1927[i] = 0;
        if (g_Minigame._192D == 8) {
            if (same) {
                if (i == 0) {
                    g_Minigame._192E[0] = lbl_3_data_189C4[i][random_fn_3_9EE24(7)];
                } else if (i == 1) {
                    g_Minigame._192E[1] = g_Minigame._192E[0];
                } else {
                    for (j = 0; j < 7; j++) {
                        if (g_Minigame._192E[0] == lbl_3_data_189C4[2][j]) {
                            break;
                        }
                    }
                    if (++j >= 7) {
                        j = 0;
                    }
                    g_Minigame._192E[2] = lbl_3_data_189C4[2][j];
                }
            } else {
                g_Minigame._192E[i] = lbl_3_data_189C4[i][random_fn_3_9EE24(7)];
                if (i == 2 && g_Minigame._192E[0] == g_Minigame._192E[1] && g_Minigame._192E[0] == g_Minigame._192E[2]) {
                    for (j = 0; j < 7; j++) {
                        if (g_Minigame._192E[2] == lbl_3_data_189C4[2][j]) {
                            break;
                        }
                    }
                    if (++j >= 7) {
                        j = 0;
                    }
                    g_Minigame._192E[2] = lbl_3_data_189C4[2][j];
                }
            }
        } else {
            g_Minigame._192E[i] = g_Minigame._192D;
        }
    }
    g_Minigame._18B8 = 0;
}

// .text:0x000D9868 size:0x1C8 mapped:0x807188FC
void fn_3_D9868(void) {
    UnkRank31A0 ranks[4];
    u32 count;
    u32 i;
    s32 k;

    fn_3_1079C8(ranks, 0);
    count = 0;
    i = 0;
    do {
        if (ranks[i].rank == 0) {
            count++;
        }
    } while (++i < g_Minigame.miniGameNumberOfParticipants);
    switch (g_Minigame._192D) {
    case 0:
        g_Minigame._1935[0] = g_Minigame.rosterID;
        i = 0;
        k = 1;
        do {
            if (i != g_Minigame.rosterID) {
                g_Minigame._1935[k++] = i;
            }
        } while (++i < g_Minigame.miniGameNumberOfParticipants);
        break;
    case 3:
        g_Minigame._1935[0] = g_Minigame.rosterID;
        do {
            g_Minigame._1935[1] = random_fn_3_9EE24(g_Minigame.miniGameNumberOfParticipants);
        } while (g_Minigame._1935[1] == g_Minigame._1935[0]);
        break;
    case 4:
    case 5:
        g_Minigame._1935[0] = g_Minigame.rosterID;
        if (count == 1 && ranks[0].id == g_Minigame.rosterID) {
            count = 0;
            i = 0;
            do {
                if (ranks[i].rank == 1) {
                    count++;
                }
            } while (++i < g_Minigame.miniGameNumberOfParticipants);
            g_Minigame._1935[1] = ranks[random_fn_3_9EE24(count) + 1].id;
        } else {
            do {
                g_Minigame._1935[1] = ranks[random_fn_3_9EE24(count)].id;
            } while (g_Minigame._1935[1] == g_Minigame._1935[0]);
        }
        break;
    }
}

// .text:0x000D8CD0 size:0xB98 mapped:0x80717D64
void fn_3_D8CD0(void) {
    int points;
    s16 tmp;
    s32 i;

    g_Minigame._18BA = 0;
    if (g_Minigame._192D == 0 || g_Minigame._192D == 3 || g_Minigame._192D == 4 || g_Minigame._192D == 5) {
        switch (g_Minigame._192D) {
        case 0:
            g_Minigame.miniGameLatestPoints[g_Minigame._1935[0]] = 0;
            i = 1;
            do {
                points = lbl_3_data_18BB8[15][0] * g_Minigame.toyField_pointMultiplier;
                if (g_Minigame.miniGameCurrentPoints[g_Minigame._1935[i]] < points) {
                    points = g_Minigame.miniGameCurrentPoints[g_Minigame._1935[i]];
                }
                g_Minigame.miniGameLatestPoints[g_Minigame._1935[0]] += points;
                g_Minigame.miniGameLatestPoints[g_Minigame._1935[i]] = -points;
            } while (++i < g_Minigame.miniGameNumberOfParticipants);
            playStadiumSound(1);
            break;
        case 3:
            points = lbl_3_data_18BB8[13][0] * g_Minigame.toyField_pointMultiplier;
            if (g_Minigame.miniGameCurrentPoints[g_Minigame._1935[1]] < points) {
                points = g_Minigame.miniGameCurrentPoints[g_Minigame._1935[1]];
            }
            g_Minigame.miniGameLatestPoints[g_Minigame._1935[0]] = points;
            g_Minigame.miniGameLatestPoints[g_Minigame._1935[1]] = -points;
            playStadiumSound(1);
            break;
        case 4:
            points = lbl_3_data_18BB8[14][0] * g_Minigame.toyField_pointMultiplier;
            if (g_Minigame.miniGameCurrentPoints[g_Minigame._1935[1]] < points) {
                points = g_Minigame.miniGameCurrentPoints[g_Minigame._1935[1]];
            }
            g_Minigame.miniGameLatestPoints[g_Minigame._1935[0]] = points;
            g_Minigame.miniGameLatestPoints[g_Minigame._1935[1]] = -points;
            playStadiumSound(1);
            break;
        case 5:
            tmp = g_Minigame.miniGameCurrentPoints[g_Minigame._1935[0]];
            g_Minigame.miniGameCurrentPoints[g_Minigame._1935[0]] = g_Minigame.miniGameCurrentPoints[g_Minigame._1935[1]];
            g_Minigame.miniGameCurrentPoints[g_Minigame._1935[1]] = tmp;
            playStadiumSound(10);
            break;
        }
        if (g_Minigame._192D != 5) {
            for (i = 0; i < 4; i++) {
                if (g_Minigame.miniGameLatestPoints[i] != 0) {
                    g_Minigame.minigamePoints_current_Latest[i][0] = g_Minigame.miniGameCurrentPoints[i];
                    g_Minigame.minigamePoints_current_Latest[i][1] = g_Minigame.miniGameLatestPoints[i];
                }
            }
        }
    } else if (g_Minigame._192D == 7) {
        g_Minigame.toyFieldBallStateResult2 = 2;
        playStadiumSound(9);
        fn_3_DE308(18);
    } else if (g_Minigame._192D == 2) {
        g_Minigame._19A2 = 2;
        g_Minigame._19C6 = g_Minigame.rosterID;
        playStadiumSound(5);
        fn_3_DE308(16);
        for (i = 1; i < 4; i++) {
            g_Minigame._1914_arr[i] = 1;
        }
    } else if (g_Minigame._192D == 6) {
        g_Minigame._19C6 = g_Minigame.rosterID;
        playStadiumSound(11);
        fn_3_DE308(17);
    }
    g_Minigame.turnOverStatus = 1;
    if (g_Minigame._192D == 7 || g_Minigame._192D == 8) {
        g_Strikes.outs++;
        fn_3_59918(1, 0);
        if (g_Minigame.rosterID == g_Minigame._19C6) {
            g_Minigame._19C6 = g_Minigame.minigamePlayerSelectedOrder;
        }
    }
    if (g_Minigame._192D == 2) {
        g_Minigame._1910 = g_Minigame._190D;
    } else {
        g_Minigame.pointsTargetReachedInd = 1;
    }
}

// .text:0x000D8A10 size:0x2C0 mapped:0x80717AA4
void fn_3_D8A10(void) {
    s32 i;

    if (g_Minigame._19CE == 1) {
        fn_3_DE308(12);
        g_Minigame._19BA = 0;
        g_Minigame._19CE = 2;
        for (i = 0; i < 4; i++) {
            if (g_Minigame._1918[i]) {
                g_Minigame._1914_arr[i] = 0;
            }
        }
        if (lbl_800EF808._398 == 1) {
            playStadiumSound(0x1A);
        }
    }
    if (g_Minigame._19BA < 0x7FFE) {
        g_Minigame._19BA++;
    } else {
        g_Minigame._19BA = 0x7FFF;
    }
    if (g_Minigame._19BA > lbl_3_data_18C48[3]) {
        g_Minigame._19CE = 3;
    }
}
