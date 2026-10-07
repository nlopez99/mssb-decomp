#include "game/rep_2940.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
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
    /* 0x253 */ u8 _253[0x25A - 0x253];
    /* 0x25A */ s8 _25A;
    /* 0x25B */ s8 _25B;
    /* 0x25C */ u8 _25C;
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E[0x275 - 0x25E];
    /* 0x275 */ u8 _275;
    /* 0x276 */ u8 _276[0x278 - 0x276];
    /* 0x278 */ u8 _278;
} Unk2940Actor;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ Unk2940Actor* _2C50[13];
    /* 0x2C84 */ u8 _2C84[0x2D68 - 0x2C84];
    /* 0x2D68 */ s16 _2D68;
} lbl_8036E548;

typedef struct {
    /* 0x000 */ f32 _000;
    /* 0x004 */ f32 _004;
    /* 0x008 */ f32 _008;
    /* 0x00C */ f32 _00C;
    /* 0x010 */ u8 _010[0x1E6 - 0x10];
    /* 0x1E6 */ u8 _1E6;
    /* 0x1E7 */ u8 _1E7[0x20F - 0x1E7];
    /* 0x20F */ u8 _20F;
    /* 0x210 */ u8 _210[0x263 - 0x210];
    /* 0x263 */ u8 _263;
    /* 0x264 */ u8 _264[0x268 - 0x264];
} Unk2940Fielder; // size: 0x268

typedef struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ f32 _28;
    /* 0x2C */ u8 _2C[0x42 - 0x2C];
    /* 0x42 */ u8 _42;
    /* 0x43 */ u8 _43[0x54 - 0x43];
} Unk2940Animation; // size: 0x54

extern Unk2940Fielder g_Fielders[9];
extern Unk2940Animation g_UnkAnimation_31EAC[9];
extern VecXYZ lbl_3_data_18DD4[4];
extern VecXZ lbl_3_data_217D8[4];

extern Unk2940Actor* fn_800111FC(Unk2940Actor* actor, int arg1);
extern int fn_8004ACC4(int arg0);
// rep_FE0.h declares this as void(void).
extern f32 fn_3_6AF9C(int fielder);

extern void fn_3_6A250(void);
extern void fn_3_6A25C(void);

// .text:0x000E1478 size:0x4EC mapped:0x8072050C
void fn_3_E1478(void) {
    int i;
    int runner;
    s8 character;
    s8 fielderIdx;
    u8 status;
    Unk2940Actor* actor;
    Unk2940Actor* player;
    Unk2940Animation* anim;
    Unk2940Fielder* fielder;
    InMemRunnerType* runnerData;
    int f;
    f32 angle;

    if (g_GameLogic.gameStatus != GAME_STATUS_DEFAULT && g_GameLogic.gameStatus != GAME_STATUS_AT_BAT &&
        g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL && g_GameLogic.gameStatus != GAME_STATUS_TRANSITION &&
        g_GameLogic.gameStatus != GAME_STATUS_INNING_TRANSITION && g_GameLogic.gameStatus != GAME_STATUS_PAUSED &&
        g_GameLogic.gameStatus != GAME_STATUS_HOW_TO_PLAY_SCREEN &&
        g_GameLogic.gameStatus != GAME_STATUS_TRANSITION_MINIGAME_TO_BATTING &&
        (g_Minigame.GameMode_MiniGame != MINI_GAME_ID_WALLBALL ||
         g_GameLogic.gameStatus != GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY)) {
        fn_3_E12F8();
        return;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8036E548._2C50[i] != NULL) {
            lbl_8036E548._2C50[i]->_25D = 0;
        }
    }

    for (i = 0; i < 4; i++) {
        character = g_Minigame.minigameControlStruct[0].characterIndex[i];
        if (character < 0) {
            continue;
        }
        status = g_GameLogic.gameStatus;
        if (status == GAME_STATUS_INNING_TRANSITION) {
            if (lbl_8036E548._2C50[character] != NULL) {
                lbl_8036E548._2C50[character]->_25D = 0;
            }
            continue;
        }
        if (g_Minigame.minigameControlStruct[0]._24[i] == 0) {
            fielderIdx = g_Minigame.minigameFielderIndex[i];
            if (fielderIdx < 0) {
                return;
            }
            f = fielderIdx;
            actor = lbl_8036E548._2C50[character];
            if (actor == NULL) {
                continue;
            }
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
                switch (status) {
                    case GAME_STATUS_DEFAULT:
                    case GAME_STATUS_AT_BAT:
                    case GAME_STATUS_LIVE_BALL:
                    case GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY:
                        actor = fn_800111FC(actor, 1);
                        break;
                    case GAME_STATUS_PAUSED:
                    case GAME_STATUS_0xC:
                    case GAME_STATUS_HOW_TO_PLAY_SCREEN:
                        break;
                    default:
                        actor = fn_800111FC(actor, 0);
                        break;
                }
            }
            actor->_25D = 1;
            actor->_278 = 0;
            anim = &g_UnkAnimation_31EAC[f];
            fielder = &g_Fielders[f];
            if (anim->_42 == 0) {
                actor->_034 = fielder->_000;
                actor->_038 = -fielder->_004 - fielder->_00C;
                actor->_03C = fielder->_008;
            }
            angle = fn_3_6AF9C(f);
            actor->_044 = angle;
            actor->_040 = 0.0f;
            actor->_048 = 0.0f;
            anim->_28 = angle;
            actor->_275 = fielder->_1E6;
            if (g_Fielders[i]._263 != 0) {
                actor->_25D = 2;
            }
            if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_STAR_DASH && fielder->_20F == 0 &&
                g_Minigame.starDashStunType[i] == 3 && (g_d_GameSettings.FrameCountWhileNotAtMainMenu & 1)) {
                actor->_25D = 2;
            }
        } else {
            if (g_Minigame.rosterID == i) {
                runner = 0;
            } else {
                runner = i;
                if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY ||
                    g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER) {
                    continue;
                }
            }
            if (lbl_8036E548._2C50[character] == NULL) {
                continue;
            }
            player = fn_800111FC(lbl_8036E548._2C50[character], 0);
            if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY &&
                (g_d_GameSettings._33 == 0 || g_d_GameSettings._33 == 1 || g_d_GameSettings._33 == 2)) {
                continue;
            }
            if (g_Minigame.rosterID == i) {
                player->_278 = 1;
            }
            player->_25D = 1;
            runnerData = &g_Runners[runner];
            player->_034 = runnerData->position.x;
            player->_038 = runnerData->position.y;
            player->_03C = runnerData->position.z;
            player->_040 = 0.0f;
            player->_044 = runnerData->runningAngle;
            player->_048 = 0.0f;
            if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_CHAINCHOMP_SPRINT) {
                player->_034 += lbl_3_data_217D8[i].x;
                player->_03C += lbl_3_data_217D8[i].z;
                if (g_Minigame._1B15[i] == 3 && (g_d_GameSettings.FrameCountWhileNotAtMainMenu & 1)) {
                    player->_25D = 2;
                }
            }
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && runner == 0 &&
                g_Pitcher.strikeOutOrWalk == 3) {
                if (player->_252 == 0x30 || player->_252 == 0x31 || player->_252 == 0x32 || player->_252 == 0x33) {
                    player->_25D = 2;
                    if (fn_8004ACC4(1)) {
                        fn_3_6A2A4(player->_252);
                    }
                }
            }
            player->_275 = runnerData->someCollisionCheck;
        }
    }
}

// .text:0x000E1370 size:0x108 mapped:0x80720404
void fn_3_E1370(int arg0) {
    Unk2940Actor* actor;
    int i;

    for (i = 0; i < 4; i++) {
        if (arg0 == 3) {
            actor = lbl_8036E548._2C50[i];
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
                actor = lbl_8036E548._2C50[9];
                if (i >= 1) {
                    return;
                }
            }
            if (actor != NULL) {
                actor->_25A = g_Minigame._19E8[i]._4 / 2;
                actor->_25B = g_Minigame._19E8[i]._4 % 2;
            }
        }
    }
}

// .text:0x000E12F8 size:0x78 mapped:0x8072038C
void fn_3_E12F8(void) {
    int i;

    for (i = 0; i < 4; i++) {
        if (lbl_8036E548._2C50[i] != NULL) {
            lbl_8036E548._2C50[i]->_25D = 0;
        }
    }
    fn_3_6A25C();
    fn_3_6A250();
}

// .text:0x000E11E0 size:0x118 mapped:0x80720274
void fn_3_E11E0(void) {
    int i;
    Unk2940Actor* actor;

    lbl_8036E548._2D68 = -1;
    for (i = 0; i < 4; i++) {
        actor = lbl_8036E548._2C50[i];
        if (actor != NULL) {
            actor->_25D = 0;
            if (g_Minigame._1A13[i] == 0 && g_Minigame._19E8[i]._2 >= 0 && g_Minigame._19E8[i]._7 != 0 &&
                g_Minigame._19DA[i] >= 0) {
                if (!g_d_GameSettings.exhibitionMatchInd) {
                    if (g_Minigame._19DA[i] >= 1) {
                        continue;
                    }
                } else if (g_Minigame._19E6 == 1 && g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD &&
                           g_Minigame._1A3C == 0 && g_Minigame._19DA[i] >= 1) {
                    continue;
                }
                actor->_25D = 1;
                actor->_034 = lbl_3_data_18DD4[i].x;
                actor->_038 = -lbl_3_data_18DD4[i].y;
                actor->_03C = lbl_3_data_18DD4[i].z;
                actor->_040 = 0.0f;
                actor->_044 = 0.0f;
                actor->_048 = 0.0f;
            }
        }
    }
}
