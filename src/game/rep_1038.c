#include "game/rep_1038.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_EA0.h"
#include "game/rep_F80.h"
#include "game/rep_FE0.h"
#include "game/rep_1090.h"
#include "game/rep_1D58.h"

typedef struct {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ f32 _040;
    /* 0x044 */ f32 _044;
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x25D - 0x4C];
    /* 0x25D */ u8 _25D;
} Unk1038Actor;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ Unk1038Actor* _2C50[13];
    /* 0x2C84 */ u8 _2C84[0x2D68 - 0x2C84];
    /* 0x2D68 */ s16 _2D68;
    /* 0x2D6A */ u8 _2D6A[0x307A - 0x2D6A];
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B[0x307E - 0x307B];
    /* 0x307E */ u8 _307E;
} lbl_8036E548;

typedef struct {
    /* 0x000 */ f32 _000;
    /* 0x004 */ f32 _004;
    /* 0x008 */ f32 _008;
    /* 0x00C */ u8 _00C[0x48 - 0xC];
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x178 - 0x4C];
    /* 0x178 */ s16 _178;
    /* 0x17A */ u8 _17A[0x268 - 0x17A];
} Unk1038Fielder; // size: 0x268

typedef struct {
    /* 0x000 */ u8 _000[0x240];
    /* 0x240 */ s16 _240[13];
    /* 0x25A */ u8 _25A[0x25C - 0x25A];
    /* 0x25C */ u8 _25C;
    /* 0x25D */ u8 _25D[0x261 - 0x25D];
    /* 0x261 */ u8 _261[13];
    /* 0x26E */ u8 _26E[13];
} Unk1038Replay;

extern Unk1038Fielder g_Fielders[9];
extern struct {
    /* 0x0 */ Unk1038Replay* _0;
} lbl_3_common_bss_1323C;
extern struct {
    /* 0x00 */ u8 _00[0x90];
    /* 0x90 */ s16 _90;
    /* 0x92 */ s16 _92;
    /* 0x94 */ u8 _94[0x9E - 0x94];
    /* 0x9E */ s16 _9E;
    /* 0xA0 */ s16 _A0;
    /* 0xA2 */ s16 _A2;
    /* 0xA4 */ u8 _A4[0xA9 - 0xA4];
    /* 0xA9 */ u8 _A9;
    /* 0xAA */ u8 _AA[0xAE - 0xAA];
    /* 0xAE */ u8 _AE;
    /* 0xAF */ u8 _AF[0xB5 - 0xAF];
    /* 0xB5 */ u8 _B5;
    /* 0xB6 */ u8 _B6[0xD3 - 0xB6];
    /* 0xD3 */ u8 _D3;
} lbl_3_common_bss_32724;
extern struct {
    /* 0x00 */ u8 _00[0xC3];
    /* 0xC3 */ u8 _C3;
} g_Scores;
extern VecXYZ lbl_3_data_18DD4[4];

extern void fn_3_674E0(void);
extern void fn_3_6AEE0(void);
extern void fn_3_6B674(void);
extern void fn_3_973EC(void);
extern void fn_3_97800(void);
extern void fn_3_15A9F4(void);

// .text:0x0006C1D8 size:0x238 mapped:0x806AB26C
void fn_3_6C1D8(void) {
    u8 status;
    u8 mode;

    status = g_GameLogic.gameStatus;
    if (status == GAME_STATUS_LOAD_GAME) {
        return;
    }
    mode = g_d_GameSettings.GameModeSelected;
    if (mode == GAME_TYPE_PRACTICE && g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_MENU &&
        g_Practice.practiceType_1 == 6) {
        fn_3_6C000();
    } else if (status != GAME_STATUS_GAME_START_MOVIE && lbl_8036E548._307A != 0) {
        if (lbl_3_common_bss_1323C._0->_25C != 0) {
            fn_3_6BEA4();
        } else if ((status == GAME_STATUS_PAUSED || status == GAME_STATUS_0xC ||
                    g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_MENU ||
                    g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_LOAD_PRACTICE_SCREEN ||
                    (mode == GAME_TYPE_PRACTICE && g_Practice.tutorialState == 0)) &&
                   (mode != GAME_TYPE_TOY_FIELD || status != GAME_STATUS_PAUSED)) {
            fn_3_690FC();
            fn_3_6AEE0();
            fn_3_6C454();
            fn_3_6C410();
            g_UnkSound_32718._07 = 0;
        } else {
            fn_3_697CC();
            fn_3_685F0();
            fn_3_6B144();
            fn_3_6C4D0();
            fn_3_6C428();
            fn_3_6B674();
            fn_3_6AB58();
        }
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        fn_3_15A9F4();
    } else {
        fn_3_973EC();
    }
}

// .text:0x0006C150 size:0x88 mapped:0x806AB1E4
void fn_3_6C150(void) {
    lbl_3_common_bss_32724._9E = -1;
    lbl_3_common_bss_32724._A0 = -1;
    lbl_3_common_bss_32724._A2 = -1;
    fn_3_6916C();
    fn_3_674E0();
    fn_3_97800();
    if (g_d_GameSettings.minigamesEnabled) {
        lbl_8036E548._307E = 0;
    } else if (g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
        lbl_8036E548._307A = 1;
        lbl_8036E548._307E = 1;
    }
}

// .text:0x0006C13C size:0x14 mapped:0x806AB1D0
void fn_3_6C13C(void) {
    g_Scores._C3 = 0;
}

// .text:0x0006C108 size:0x34 mapped:0x806AB19C
void fn_3_6C108(void) {
    fn_3_B93C8(1);
    lbl_3_common_bss_32724._AE = 0;
}

// .text:0x0006C0E0 size:0x28 mapped:0x806AB174
void fn_3_6C0E0(void) {
    lbl_3_common_bss_32724._90 = -1;
    lbl_3_common_bss_32724._92 = 0;
    lbl_3_common_bss_32724._A9 = 0;
    lbl_3_common_bss_32724._D3 = 0;
    lbl_3_common_bss_32724._B5 = 0;
}

// .text:0x0006C000 size:0xE0 mapped:0x806AB094
void fn_3_6C000(void) {
    int i;
    Unk1038Actor* actor;

    lbl_8036E548._2D68 = -1;
    for (i = 0; i < 13; i++) {
        if (lbl_8036E548._2C50[i] != NULL) {
            lbl_8036E548._2C50[i]->_25D = 0;
        }
    }
    if (g_Practice.practiceState != PRACTICE_STATE_6 && g_Practice.practiceState > PRACTICE_STATE_1) {
        actor = lbl_8036E548._2C50[9];
        if (actor == NULL) {
            return;
        }
        if (g_Minigame._1A13[0] == 0 && g_Minigame._19E8[0]._2 >= 0 && g_Minigame._19E8[0]._7 != 0 &&
            g_Minigame._19DA[0] >= 0) {
        actor->_25D = 1;
        actor->_034 = lbl_3_data_18DD4[0].x;
        actor->_038 = -lbl_3_data_18DD4[0].y;
        actor->_03C = lbl_3_data_18DD4[0].z;
        actor->_040 = 0.0f;
        actor->_044 = 0.0f;
        actor->_048 = 0.0f;
        }
    }
}

// .text:0x0006BEA4 size:0x15C mapped:0x806AAF38
void fn_3_6BEA4(void) {
    int i;
    Unk1038Actor* actor;

    fn_3_690FC();
    fn_3_6AEE0();
    fn_3_6C454();
    g_UnkSound_32718._07 = 0;
    for (i = 0; i < 13; i++) {
        if (lbl_3_common_bss_1323C._0->_240[i] < 0) {
            continue;
        }
        actor = lbl_8036E548._2C50[i];
        if (actor == NULL) {
            continue;
        }
        actor->_25D = lbl_3_common_bss_1323C._0->_261[i];
        if (i <= 8) {
            lbl_3_common_bss_1323C._0->_26E[i] = 0;
            if (g_Fielders[i]._178 != -1) {
                actor->_034 = g_Fielders[i]._000;
                actor->_038 = g_Fielders[i]._004;
                actor->_03C = g_Fielders[i]._008;
                actor->_044 = g_Fielders[i]._048;
            }
        } else if (i <= 12) {
            InMemRunnerType* runner = &g_Runners[i - 9];

            lbl_3_common_bss_1323C._0->_26E[i] = 0;
            if (runner->rosterID != -1) {
                actor->_034 = runner->position.x;
                actor->_038 = runner->position.y;
                actor->_03C = runner->position.z;
                actor->_044 = runner->runningAngle;
            }
        }
        actor->_040 = 0.0f;
        actor->_048 = 0.0f;
    }
}
