#include "game/rep_FE0.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"

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
    /* 0x25E */ u8 _25E[0x275 - 0x25E];
    /* 0x275 */ u8 _275;
} UnkFE0Actor;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ UnkFE0Actor* _2C50[13];
} lbl_8036E548;

typedef struct {
    /* 0x000 */ f32 _000;
    /* 0x004 */ f32 _004;
    /* 0x008 */ f32 _008;
    /* 0x00C */ f32 _00C;
    /* 0x010 */ u8 _010[0x48 - 0x10];
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x1C7 - 0x4C];
    /* 0x1C7 */ u8 _1C7;
    /* 0x1C8 */ u8 _1C8[0x1E6 - 0x1C8];
    /* 0x1E6 */ u8 _1E6;
    /* 0x1E7 */ u8 _1E7[0x1FC - 0x1E7];
    /* 0x1FC */ u8 _1FC;
    /* 0x1FD */ u8 _1FD[0x205 - 0x1FD];
    /* 0x205 */ u8 _205;
    /* 0x206 */ u8 _206[0x20A - 0x206];
    /* 0x20A */ u8 _20A;
    /* 0x20B */ u8 _20B[0x263 - 0x20B];
    /* 0x263 */ u8 _263;
    /* 0x264 */ u8 _264[0x268 - 0x264];
} UnkFE0Fielder; // size: 0x268

typedef struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ f32 _28;
    /* 0x2C */ u8 _2C[0x42 - 0x2C];
    /* 0x42 */ u8 _42;
    /* 0x43 */ u8 _43[0x54 - 0x43];
} UnkFE0Animation; // size: 0x54

typedef struct {
    /* 0x000 */ u8 _000[0x261];
    /* 0x261 */ u8 _261[9];
} UnkFE0Replay;

extern UnkFE0Fielder g_Fielders[9];
extern UnkFE0Animation g_UnkAnimation_31EAC[9];
extern u8 lbl_3_data_69C0[16];
extern struct {
    /* 0x0 */ UnkFE0Replay* _0;
} lbl_3_common_bss_1323C;

// .text:0x0006B144 size:0x384 mapped:0x806AA1D8
void fn_3_6B144(void) {
    int i;
    UnkFE0Actor* actor;
    f32 angle;

    if (g_GameLogic.gameStatus != GAME_STATUS_DEFAULT && g_GameLogic.gameStatus != GAME_STATUS_AT_BAT &&
        g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL && g_GameLogic.gameStatus != GAME_STATUS_TRANSITION &&
        g_GameLogic.gameStatus != GAME_STATUS_INNING_TRANSITION &&
        g_GameLogic.gameStatus != GAME_STATUS_STAR_CHANCE_VS &&
        g_GameLogic.gameStatus != GAME_STATUS_TRANSITION_MINIGAME_TO_BATTING &&
        (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD || g_GameLogic.gameStatus != GAME_STATUS_PAUSED)) {
        for (i = 0; i < 9; i++) {
            if (lbl_8036E548._2C50[i] != NULL) {
                lbl_8036E548._2C50[i]->_25D = 0;
            }
        }
        return;
    }

    for (i = 0; i < 9; i++) {
        if (lbl_8036E548._2C50[i] == NULL) {
            continue;
        }
        actor = lbl_8036E548._2C50[i];
        actor->_25D = 0;
        actor->_275 = g_Fielders[i]._1E6;
        if (g_GameLogic.gameStatus == GAME_STATUS_INNING_TRANSITION) {
            continue;
        }
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
            if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_BASERUNNING) {
                continue;
            }
            if (g_Practice.practiceLevel == 4) {
                continue;
            }
            if ((g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_PITCHING ||
                 g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_PRACTICE_BATTING) &&
                i > 0) {
                continue;
            }
        }
        actor->_25D = 1;
        if (g_UnkAnimation_31EAC[i]._42 == 0) {
            actor->_034 = g_Fielders[i]._000;
            actor->_038 = -g_Fielders[i]._004 - g_Fielders[i]._00C;
            actor->_03C = g_Fielders[i]._008;
        }
        angle = fn_3_6AF9C(i);
        if (g_Fielders[i]._20A != 0) {
            angle = g_UnkAnimation_31EAC[i]._28;
        }
        actor->_044 = angle;
        actor->_040 = 0.0f;
        actor->_048 = 0.0f;
        g_UnkAnimation_31EAC[i]._28 = angle;
        if (g_Fielders[i]._263 != 0) {
            actor->_25D = 2;
        }
        if (g_Stats.replayInd != 0) {
            actor->_25D = lbl_3_common_bss_1323C._0->_261[i];
        } else if (i == 1) {
            if (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT || g_GameLogic.gameStatus == GAME_STATUS_DEFAULT ||
                g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY ||
                g_GameLogic.gameStatus == GAME_STATUS_STAR_CHANCE_VS || g_GameLogic.sceneID == SCENE_ID_AT_BAT) {
                actor->_25D = 2;
            }
            if (g_GameLogic.sceneID == SCENE_ID_REPLAY_AT_BAT) {
                actor->_25D = 1;
            }
        } else if (lbl_3_data_69C0[i] != 0) {
            if (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT || g_GameLogic.gameStatus == GAME_STATUS_DEFAULT ||
                g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY ||
                g_GameLogic.gameStatus == GAME_STATUS_STAR_CHANCE_VS || g_GameLogic.sceneID == SCENE_ID_AT_BAT) {
                actor->_25D = 2;
            }
            if (g_GameLogic.sceneID == SCENE_ID_REPLAY_AT_BAT) {
                actor->_25D = 1;
            }
        }
        if (g_Fielders[i]._205 == 1 || g_Fielders[i]._205 == 2 || g_Fielders[i]._205 == 3 ||
            g_Fielders[i]._205 == 4 || g_Fielders[i]._205 == 5 || g_Fielders[i]._205 == 6) {
            actor->_25D = 3;
        }
    }
}

// .text:0x0006AF9C size:0x1A8 mapped:0x806AA030
f32 fn_3_6AF9C(int idx) {
    UnkFE0Fielder* fielder = &g_Fielders[idx];
    UnkFE0Animation* anim = &g_UnkAnimation_31EAC[idx];
    f32 angle = fn_3_9FEA8(-fielder->_048 - HALF_PI);
    int target;
    int cur;
    int diff;

    if (fielder->_1FC != 0) {
        return angle;
    }
    target = radToShortAngle(angle);
    cur = radToShortAngle(anim->_28);
    diff = fn_3_9FCA4(cur, target);
    if (diff > 0x800) {
        diff -= 0x1000;
    } else if (diff <= -0x800) {
        diff += 0x1000;
    }
    if (diff > 0x600) {
        if (fielder->_1C7 == 0) {
            cur -= 0x280;
        } else {
            cur += 0x280;
        }
    } else if (diff < -0x600) {
        if (fielder->_1C7 == 0) {
            cur -= 0x280;
        } else {
            cur += 0x280;
        }
    } else if (diff > 0x200) {
        cur -= 0x180;
    } else if (diff < -0x200) {
        cur += 0x180;
    } else if (diff > 0x180) {
        cur -= 0x100;
    } else if (diff < -0x180) {
        cur += 0x100;
    } else if (diff > 0xC0) {
        cur -= 0x80;
    } else if (diff < -0xC0) {
        cur += 0x80;
    } else if (diff > 0x60) {
        cur -= 0x40;
    } else if (diff < -0x60) {
        cur += 0x40;
    } else {
        return angle;
    }
    return shortAngleToRad(cur);
}
