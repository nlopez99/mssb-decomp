#include "game/rep_2940.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_F80.h"
#include "game/rep_FE0.h"
#include "game/rep_1838.h"
#include "Dolphin/rand.h"
#include "game/rep_3310.h"
#include "game/rep_EA0.h"
#include "game/rep_2BF8.h"
#include "game/rep_3880.h"
#include "game/rep_3CE0.h"

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

typedef struct Unk2940Obj {
    /* 0x00 */ void (*_00)(s32);
    /* 0x04 */ VecXYZ _04;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ u8 _18[0x26 - 0x18];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} Unk2940Obj; // size: 0x28

extern struct {
    /* 0x0000 */ u8 _0000[0x2294];
    /* 0x2294 */ f32 _2294;
    /* 0x2298 */ f32 _2298;
    /* 0x229C */ f32 _229C;
    /* 0x22A0 */ u8 _22A0[0x22A4 - 0x22A0];
    /* 0x22A4 */ f32 _22A4;
    /* 0x22A8 */ u8 _22A8[0x24BD - 0x22A8];
    /* 0x24BD */ u8 _24BD;
    /* 0x24BE */ u8 _24BE[0x2C50 - 0x24BE];
    /* 0x2C50 */ Unk2940Actor* _2C50[13];
    /* 0x2C84 */ u8 _2C84[0x2D68 - 0x2C84];
    /* 0x2D68 */ s16 _2D68;
    /* 0x2D6A */ u8 _2D6A[0x2D94 - 0x2D6A];
    /* 0x2D94 */ Unk2940Obj* _2D94;
    /* 0x2D98 */ u8 _2D98[0x307A - 0x2D98];
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B[0x3087 - 0x307B];
    /* 0x3087 */ u8 _3087;
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
f32 lbl_3_data_18D98[14] = {
    1.0f, 1.2f, 18.8f, 0.15f, 19.5f, 0.7f, 0.0f, 0.15f, 38.8f, 0.0f, -18.8f, 0.15f, 19.5f, -0.7f,
};
f32 lbl_3_data_18DD0 = 0.2f;
VecXYZ lbl_3_data_18DD4[4] = {
    { -225.0f, -30.0f, 0.0f },
    { -75.0f, -30.0f, 0.0f },
    { 75.0f, -30.0f, 0.0f },
    { 225.0f, -30.0f, 0.0f },
};
VecXYZ lbl_3_data_18E04[4][4] = {
    { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { { -1.2f, 0.0f, 0.0f }, { 1.2f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { { -2.4f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 2.4f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { { -3.6f, 0.0f, 0.0f }, { -1.2f, 0.0f, 0.0f }, { 1.2f, 0.0f, 0.0f }, { 3.6f, 0.0f, 0.0f } },
};
f32 lbl_3_data_18EC4[3] = { -1.5f, 0.0f, 1.5f };

extern s16 lbl_3_data_18BB0[2][2];
extern u8 lbl_3_data_18910[8];

extern void fn_8001D0D0(s32 id, f32 scale);
typedef struct Unk2940Pos {
    /* 0x00 */ f32 _0;
    /* 0x04 */ f32 _4;
    /* 0x08 */ f32 _8;
    /* 0x0C */ f32 _C;
} Unk2940Pos;
extern Unk2940Pos lbl_3_data_2130C[];
extern s16 lbl_3_data_2137C;
extern struct {
    /* 0x000 */ u8 _000[0x104];
    /* 0x104 */ u8 _104;
} lbl_80353A90;
extern struct {
    /* 0x000 */ u8 _000[0x1D2];
    /* 0x1D2 */ u8 _1D2;
} lbl_3_common_bss_34C90;
extern VecXZ lbl_3_data_217D8[4];

extern Unk2940Actor* fn_800111FC(Unk2940Actor* actor, int arg1);
extern int fn_8004ACC4(int arg0);

extern void fn_3_6A250(void);
extern void fn_3_6A25C(void);
extern void fn_3_6B674(void);
// rep_3448, being written in parallel
extern void fn_3_12D1F4(void);

// .text:0x000E19E8 size:0x278 mapped:0x80720A7C
void fn_3_E19E8(void) {
    lbl_8036E548._3087 = 1;
    if (g_GameLogic.gameStatus == 5 && g_GameLogic._125 == 5) {
        fn_3_11D1B0();
    }
    if (g_GameLogic.gameStatus == 0x1B) {
        return;
    }
    if (lbl_8036E548._307A == 0) {
        fn_3_E12F8();
    } else if ((u8)(g_GameLogic.gameStatus - 0x1C) <= 2 || g_GameLogic.gameStatus == 0x1F) {
        if (g_GameLogic.gameStatus == 0x1E) {
            fn_3_E11E0();
        }
    } else if (g_GameLogic.gameStatus == 0x0E || g_GameLogic.gameStatus == 0x22 || g_GameLogic.gameStatus == 0x24 ||
               g_GameLogic.gameStatus == 0x26 || g_GameLogic.gameStatus == 0x27) {
        lbl_8036E548._3087 = g_d_GameSettings.GameModeSelected != 6;
        fn_3_E07DC();
        fn_3_116B74();
    } else if (g_GameLogic.gameStatus == 4) {
        return;
    } else if (g_GameLogic.gameStatus != 5) {
        fn_3_697CC();
        fn_3_685F0();
        fn_3_E1478();
        fn_3_6B674();
        if (g_d_GameSettings.GameModeSelected == 6) {
            fn_3_E0668();
        } else {
            fn_3_11AC6C();
        }
        fn_3_6AB58();
    }
    if (g_d_GameSettings.GameModeSelected == 6) {
        fn_3_EDD10();
    } else {
        fn_3_12D1F4();
    }
}

// .text:0x000E1964 size:0x84 mapped:0x807209F8
void fn_3_E1964(void) {
    fn_3_E0758();
}

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
        character = g_Minigame.minigameControlStruct.characterIndex[i];
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
        if (g_Minigame.minigameControlStruct._24[i] == 0) {
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
    VecXYZ* pos;

    lbl_8036E548._2D68 = -1;
    for (i = 0; i < 4; i++) {
        actor = lbl_8036E548._2C50[i];
        if (actor == NULL) {
            continue;
        }
        actor->_25D = 0;
        if (g_Minigame._1A13[i] != 0) {
            continue;
        }
        if (g_Minigame._19E8[i]._2 < 0) {
            continue;
        }
        if (g_Minigame._19E8[i]._7 == 0) {
            continue;
        }
        if (g_Minigame._19DA[i] < 0) {
            continue;
        }
        if (!g_d_GameSettings.exhibitionMatchInd) {
            if (g_Minigame._19DA[i] >= 1) {
                continue;
            }
        } else if (g_Minigame._19E6 == 1 && g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD &&
                   g_Minigame._1A3C == 0 && g_Minigame._19DA[i] >= 1) {
            continue;
        }
        pos = &lbl_3_data_18DD4[i];
        actor->_25D = 1;
        actor->_034 = pos->x;
        actor->_038 = -pos->y;
        actor->_03C = pos->z;
        actor->_040 = 0.0f;
        actor->_044 = 0.0f;
        actor->_048 = 0.0f;
    }
}

// .text:0x000E07DC size:0xA04 mapped:0x8071F870
// Remaining: the target holds &lbl_8036E548 in a saved register across the stadium block's
// call (and stores _24BD after the search loop), and register numbers elsewhere.
void fn_3_E07DC(void) {
    Unk2940Actor* actor;
    VecXYZ pos;
    s32 ids[4];
    s32* p;
    BOOL start;
    BOOL show = TRUE;
    int count;
    BOOL won;
    int best;
    int stadium;
    int i;
    int slot;
    int n;

    start = FALSE;
    won = g_Minigame.challenge_minigame_haven_tWonYetIndicator;
    if (g_d_GameSettings.minigamesEnabled) {
        if (g_GameLogic.gameStatus == 0xE && g_GameLogic._125 == 0) {
            start = TRUE;
        }
    } else if (g_GameLogic.gameStatus == 0xE &&
               (g_GameLogic._125 < 4 || (g_GameLogic._125 == 4 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 0))) {
        start = TRUE;
    }
    if (g_GameLogic.gameStatus == 0xF || start) {
        for (i = 0; i < 4; i++) {
            if (lbl_8036E548._2C50[i] != NULL) {
                lbl_8036E548._2C50[i]->_25D = 0;
            }
        }
        return;
    }
    if (g_GameLogic.gameStatus == 0x27) {
        won = TRUE;
        if (g_Minigame._1A3D == 1) {
            won = FALSE;
            if (g_Minigame._1E22[0] == g_Minigame._1E22[1] && g_Minigame._1E22[0] == g_Minigame._1E22[2] &&
                g_Minigame._1E22[0] == g_Minigame._1E22[3]) {
                won = TRUE;
            }
        } else {
            for (i = 0; i < 4; i++) {
                if (g_Minigame.minigameControlStruct._1C[i] != 1) {
                    won = FALSE;
                    break;
                }
            }
        }
    }
    start = FALSE;
    if (g_d_GameSettings.minigamesEnabled) {
        if ((g_GameLogic.gameStatus == 0xE && g_GameLogic.FrameCountOfCurrentPitch == 1) ||
            (g_GameLogic.gameStatus == 0x27 && g_GameLogic.FrameCountOfCurrentPitch == 1)) {
            start = TRUE;
        }
    } else if (g_GameLogic.gameStatus == 0xE && g_GameLogic._125 == 4 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
        start = TRUE;
    }
    if (start) {
        count = 0;
        if (g_GameLogic.gameStatus == 0x27 || g_Minigame._1A3E) {
            best = -1;
            for (i = 0; i < 4; i++) {
                if (g_Minigame._1E22[i] > best) {
                    best = g_Minigame._1E22[i];
                }
            }
            if (g_Minigame._1A3D == 1) {
                for (i = 0; i < 4; i++) {
                    if (g_Minigame._1E08[i][0] == g_Minigame._1908 && g_Minigame._1E08[i][1] == 0) {
                        ids[0] = g_Minigame._1908;
                        count = 1;
                        break;
                    }
                }
            } else {
                p = ids;
                for (i = 0; i < 4; i++) {
                    if (g_Minigame._1E22[i] == best) {
                        *p++ = i;
                        count++;
                    }
                }
            }
        } else if (!g_d_GameSettings.minigamesEnabled) {
            ids[0] = 9;
            count = 1;
            if (lbl_80353A90._104 >= 2) {
                show = FALSE;
            }
        } else if (g_Minigame.miniGameNumberOfParticipants > 1) {
            p = ids;
            for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
                if (g_Minigame.minigameControlStruct._1C[i] == 1) {
                    count++;
                    *p++ = g_Minigame.minigameControlStruct.characterIndex[i];
                }
            }
            lbl_80353A90._104 = 0;
        } else if (g_Minigame.soloMinigameDifficulty == 3) {
            if (g_Minigame._1A43 == 1 || g_Minigame._19AA) {
                count = 1;
                ids[0] = g_Minigame.minigameControlStruct.characterIndex[0];
            }
        } else {
            ids[0] = g_Minigame.minigameControlStruct.characterIndex[0];
            if (g_Minigame._1A37 == 1) {
                count = 1;
                lbl_80353A90._104 = 0;
            }
        }
        if (!won || count == 1) {
            fn_3_14A070(ids, count);
            if (show && g_d_GameSettings.minigamesEnabled) {
                if (count == 1) {
                    count = 2;
                    ids[1] = ids[0];
                } else if (count == 2) {
                    count = 4;
                    ids[2] = ids[0];
                    ids[3] = ids[1];
                }
                fn_3_15FA58(count, ids);
            }
        }
    }
    if (!won && ((g_GameLogic.gameStatus == 0xE && g_GameLogic.FrameCountOfCurrentPitch == lbl_3_data_2137C &&
                  lbl_80353A90._104 <= 1) ||
                 (g_GameLogic.gameStatus == 0x27 && g_GameLogic.FrameCountOfCurrentPitch == lbl_3_data_2137C))) {
        start = TRUE;
        if (g_GameLogic.gameStatus == 0x27 && g_Minigame._1A3D == 1) {
            start = FALSE;
            for (i = 0; i < 4; i++) {
                if (g_Minigame._1E08[i][0] == g_Minigame._1908 && g_Minigame._1E08[i][1] == 0) {
                    start = TRUE;
                    break;
                }
            }
        }
        if (start) {
            if (g_d_GameSettings.minigamesEnabled) {
                fn_3_15F9AC();
            }
            fn_3_149BA8();
        }
    }
    if (!g_d_GameSettings.minigamesEnabled) {
        lbl_8036E548._24BD = 1;
        for (stadium = 0; stadium < 6; stadium++) {
            if (g_d_GameSettings.StadiumID == lbl_3_data_18910[stadium]) {
                break;
            }
        }
        fn_3_9F79C(lbl_3_data_2130C[stadium]._C, lbl_3_data_2130C[stadium]._0, lbl_3_data_2130C[stadium]._8, &pos.x, &pos.z);
        pos.y = lbl_3_data_2130C[stadium]._4;
        lbl_8036E548._2294 = pos.x + lbl_3_data_18E04[0][0].x;
        lbl_8036E548._2298 = pos.y + lbl_3_data_18E04[0][0].y;
        lbl_8036E548._229C = pos.z + lbl_3_data_18E04[0][0].z;
        lbl_8036E548._2298 = -lbl_8036E548._2298;
        lbl_8036E548._22A4 = lbl_3_data_2130C[stadium]._C;
        return;
    }
    slot = 0;
    n = g_Minigame.miniGameNumberOfParticipants;
    for (i = 0; i < 4; i++) {
        actor = lbl_8036E548._2C50[i];
        if (actor == NULL) {
            continue;
        }
        actor->_25D = 0;
        if (g_GameLogic.gameStatus == 0x22 && (lbl_3_common_bss_34C90._1D2 == 7 || g_GameLogic.framesOfExitingToMenu)) {
            continue;
        }
        if (g_Minigame.minigameControlStruct.characterIndex[slot] != i) {
            continue;
        }
        if (g_Minigame._1A3D == 1) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] != g_Minigame._1908) {
                continue;
            }
            n = 1;
        }
        actor->_25D = 1;
        fn_3_9F79C(lbl_3_data_2130C[g_Minigame.GameMode_MiniGame]._C, lbl_3_data_2130C[g_Minigame.GameMode_MiniGame]._0,
                   lbl_3_data_2130C[g_Minigame.GameMode_MiniGame]._8, &pos.x, &pos.z);
        pos.y = lbl_3_data_2130C[g_Minigame.GameMode_MiniGame]._4;
        actor->_034 = pos.x + lbl_3_data_18E04[n - 1][slot].x;
        actor->_038 = pos.y + lbl_3_data_18E04[n - 1][slot].y;
        actor->_03C = pos.z + lbl_3_data_18E04[n - 1][slot].z;
        actor->_038 = -actor->_038;
        actor->_044 = lbl_3_data_2130C[g_Minigame.GameMode_MiniGame]._C;
        if (g_GameLogic.gameStatus == 0x27 || g_Minigame._1A3E) {
            if (g_Minigame._1A3D > 1) {
                if (g_Minigame.minigameControlStruct._1C[i] == 1) {
                    actor->_03C += lbl_3_data_18EC4[0];
                } else {
                    actor->_03C += lbl_3_data_18EC4[2];
                }
            }
        } else if (won) {
            if (g_Minigame.minigameControlStruct._4[i] == 0x26) {
                actor->_03C += lbl_3_data_18EC4[1];
            } else {
                actor->_03C += lbl_3_data_18EC4[0];
            }
        } else if (g_Minigame.minigameControlStruct._20[i] == 1) {
            actor->_03C += lbl_3_data_18EC4[0];
        } else {
            actor->_03C += lbl_3_data_18EC4[2];
        }
        slot++;
    }
}

// .text:0x000E0758 size:0x84 mapped:0x8071F7EC
void fn_3_E0758(void) {
    Unk2940Obj* obj;
    int i;

    for (i = 0; i < 30; i++) {
        obj = &lbl_8036E548._2D94[i];
        fn_8001D0D0(i, lbl_3_data_18D98[0]);
        obj->_14 = shortAngleToRad_Capped(rand() % 4096);
    }
}

// .text:0x000E0668 size:0xF0 mapped:0x8071F6FC
void fn_3_E0668(void) {
    Unk2940Obj* obj;
    int i;

    for (i = 0; i < 30; i++) {
        obj = &lbl_8036E548._2D94[i];
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 0) {
            obj->_26 = 0;
        } else if (g_Minigame.wallBall_coinsVisibleFrameCounter[0] > lbl_3_data_18BB0[g_Minigame._199E][1] &&
                   (g_Minigame.wallBall_coinsVisibleFrameCounter[0] & 1)) {
            obj->_26 = 0;
        } else {
            obj->_26 = 1;
            obj->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
            obj->_04.y = -g_Minigame.wallBall_coinCoordinates[i].y;
            obj->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
            obj->_14 = fn_3_9FEA8(obj->_14 + lbl_3_data_18DD0);
        }
    }
}
