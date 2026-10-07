#include "game/rep_1090.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/rep_F80.h"

typedef struct {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ f32 _040;
    /* 0x044 */ f32 _044;
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x252 - 0x4C];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253[0x25D - 0x253];
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E[0x275 - 0x25E];
    /* 0x275 */ u8 _275;
    /* 0x276 */ u8 _276[0x278 - 0x276];
    /* 0x278 */ u8 _278;
} Unk1090Actor;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ Unk1090Actor* _2C50[13];
    /* 0x2C84 */ u8 _2C84[0x2D77 - 0x2C84];
    /* 0x2D77 */ u8 _2D77;
} lbl_8036E548;

extern struct {
    /* 0x000 */ u8* _000;
} lbl_3_common_bss_1323C;

extern u8 lbl_3_data_6EF0[8];

extern int fn_8004ACC4(int arg0);
extern int fn_8004ACDC(int arg0);
extern void fn_3_6A250(void);
extern void fn_3_6A254(void);
extern void fn_3_6A25C(void);
extern void fn_3_E07DC(void);

static inline void fn_3_6C454(void);

// .text:0x0006C4D0 size:0x384 mapped:0x806AB564
void fn_3_6C4D0(void) {
    Unk1090Actor* actor;
    int i;
    s8 id;

    if (lbl_8036E548._2D77) {
        fn_3_6C454();
        return;
    }
    if (g_GameLogic.gameStatus != GAME_STATUS_DEFAULT && g_GameLogic.gameStatus != GAME_STATUS_AT_BAT &&
        g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL && g_GameLogic.gameStatus != GAME_STATUS_TRANSITION &&
        g_GameLogic.gameStatus != GAME_STATUS_STAR_CHANCE_VS) {
        fn_3_6C454();
        if (g_GameLogic.gameStatus == GAME_STATUS_MVP_END_GAME) {
            fn_3_E07DC();
        }
        return;
    }
    if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_PITCHING) {
        fn_3_6C454();
        return;
    }
    for (i = 0; i < 4; i++) {
        actor = lbl_8036E548._2C50[i + 9];
        if (actor == NULL) {
            continue;
        }
        actor->_275 = g_Runners[i].someCollisionCheck;
        if (i == 0) {
            actor->_278 = 1;
        }
        if (g_Runners[i].runningToDugoutStage == 3) {
            actor->_25D = 0;
            continue;
        }
        if (i == 0 && g_Pitcher.strikeOutOrWalk == 3) {
            id = actor->_252;
            if (id == 0x26) {
                if (fn_8004ACDC(1)) {
                    fn_3_6A254();
                }
            } else if (id == 0x30 || id == 0x31 || id == 0x32 || id == 0x33) {
                actor->_25D = 2;
                if (fn_8004ACC4(1)) {
                    fn_3_6A2A4(actor->_252);
                }
                continue;
            }
        }
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 0 || g_Runners[i].rosterID < 0) {
            actor->_25D = 0;
        } else if (g_Runners[i].runningToDugoutStage == 3) {
            actor->_25D = 0;
        } else {
            actor->_25D = 1;
            actor->_034 = g_Runners[i].position.x;
            actor->_038 = g_Runners[i].position.y;
            actor->_03C = g_Runners[i].position.z;
            actor->_040 = 0.0f;
            actor->_044 = g_Runners[i].runningAngle;
            actor->_048 = 0.0f;
        }
        if (g_Stats.replayInd) {
            actor->_25D = lbl_3_common_bss_1323C._000[i + 0x261];
        } else if (lbl_3_data_6EF0[i] && g_GameLogic.sceneID != SCENE_ID_REPLAY_AT_BAT &&
                   g_GameLogic.secondaryGameMode != SECONDARY_GAME_MODE_PRACTICE_BASERUNNING &&
                   (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT || g_GameLogic.gameStatus == GAME_STATUS_DEFAULT ||
                    g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY ||
                    g_GameLogic.sceneID == SCENE_ID_AT_BAT)) {
            actor->_25D = 0;
        }
    }
}

// .text:0x0006C454 size:0x78 mapped:0x806AB4E8
static inline void fn_3_6C454(void) {
    int i;

    for (i = 0; i < 4; i++) {
        if (lbl_8036E548._2C50[i + 9] != NULL) {
            lbl_8036E548._2C50[i + 9]->_25D = 0;
        }
    }
    fn_3_6A25C();
    fn_3_6A250();
}
