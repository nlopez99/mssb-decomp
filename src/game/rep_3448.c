#include "game/rep_3448.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/m_sound.h"
#include "musyx/musyx.h"

typedef struct UnkTask3448 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct UnkTask3448* _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
    /* 0x22 */ u8 _22[0x24 - 0x22];
    union {
        /* 0x24 */ u8 _24_arr[4];
        struct {
            /* 0x24 */ s8 _24;
            /* 0x25 */ u8 _25;
        };
    };
} UnkTask3448;

typedef struct {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ f32 _48;
    /* 0x4C */ f32 _4C;
    /* 0x50 */ u8 _50[0x54 - 0x50];
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66[0x68 - 0x66];
    /* 0x68 */ u8 _68;
    /* 0x69 */ u8 _69;
    /* 0x6A */ u8 _6A[0x72 - 0x6A];
    /* 0x72 */ s16 _72;
} UnkSprite3448;

typedef struct {
    /* 0x00 */ UnkSprite3448* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef3448; // size: 0x8

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc3448; // size: 0x20

extern struct {
    /* 0x00 */ u8 _00[0x96];
    /* 0x96 */ u8 _96;
    /* 0x97 */ u8 _97[0xB7 - 0x97];
    /* 0xB7 */ u8 _B7;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x000 */ u8 _000[0x1D2];
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4;
} lbl_3_common_bss_34C90;

extern u8 lbl_800EFBA4[0x10];
extern struct {
    /* 0x000 */ u8 _000[0x398];
    /* 0x398 */ u8 _398;
} lbl_800EF808;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

typedef struct {
    /* 0x000 */ VecXYZ position;
    /* 0x00C */ u8 _00C[0x268 - 0xC];
} UnkFielder3448; // size: 0x268

extern UnkFielder3448 g_Fielders[9];

extern UnkSpriteRef3448 lbl_80371C30[];
extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0xAA - 0x4];
    /* 0xAA */ u8 _AA;
} g_Scores;

extern UnkSpriteDesc3448 lbl_3_data_91BC[];
extern u16 lbl_3_data_91FC[];
extern UnkSpriteDesc3448 lbl_3_data_A9F8[];
extern UnkSpriteDesc3448 lbl_3_data_B0E0[];
extern u16 lbl_3_data_B140[][2];
extern s16 lbl_3_data_213EC[10];
extern s16 lbl_3_data_21654[12];
extern s16 lbl_3_data_21672;
extern s16 lbl_3_data_21788[4];
extern u8 lbl_3_data_21798[12];
extern u8 lbl_3_data_21884[4][2];
extern UnkSpriteDesc3448 lbl_3_data_23894[];
extern u16 lbl_3_data_238F4[8];
extern UnkSpriteDesc3448 lbl_3_data_23A44[];
extern UnkSpriteDesc3448 lbl_3_data_23AE4[];
extern UnkSpriteDesc3448 lbl_3_data_23C84[];
extern UnkSpriteDesc3448 lbl_3_data_23D24[];
extern UnkSpriteDesc3448 lbl_3_data_23DA4[];
extern UnkSpriteDesc3448 lbl_3_data_23E04[];
extern UnkSpriteDesc3448 lbl_3_data_23F24[];
extern UnkSpriteDesc3448 lbl_3_data_246E4[];
extern UnkSpriteDesc3448 lbl_3_data_24B04[];
extern UnkSpriteDesc3448 lbl_3_data_24CE4[];
extern UnkSpriteDesc3448 lbl_3_data_24D44[];
extern UnkSpriteDesc3448 lbl_3_data_24DA4[];
extern UnkSpriteDesc3448 lbl_3_data_24E04[];
extern UnkSpriteDesc3448 lbl_3_data_25344[];

extern void fn_80034CEC(UnkTask3448* task);
extern void fn_80034E20(UnkTask3448* task, UnkSpriteDesc3448* desc);
extern void fn_800362F0(UnkTask3448* task, s32);
extern void fn_800363D8(UnkTask3448* task, s32, s32, s32, s32);
extern void fn_800528C0(f32 x, f32 y, f32 z, s16* screenX, s16* screenY);
extern void fn_800B0A14_removeQueue(void);
extern u32 fn_3_107C88(void);
extern s32 fn_3_107CD0(void);

static inline u32 getFrame(UnkTask3448* task, u32 i) {
    return lbl_80371C30[task->_14 + i]._00->_5C >> 16;
}

static inline BOOL isAnimDone(UnkSprite3448* sprite) {
    return sprite->_69 == 2 ? TRUE : FALSE;
}

// .text:0x00129370 size:0x60 mapped:0x80768404
void fn_3_129370(void) {
    UnkTask3448* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_A9F8);
    task->_18 = 0;
    task->_1A = 0;
    ((UnkTask3448*)lbl_803CC1B8)->_00 = fn_3_128C18;
}

// .text:0x00128C18 size:0x758 mapped:0x80767CAC
void fn_3_128C18(void) {
    return;
}

// .text:0x00128B90 size:0x88 mapped:0x80767C24
void fn_3_128B90(void) {
    UnkTask3448* task = lbl_803CC1B8;

    lbl_3_data_B0E0[0]._02 = lbl_3_data_B140[g_Minigame.GameMode_MiniGame][0];
    lbl_3_data_B0E0[1]._02 = lbl_3_data_B140[g_Minigame.GameMode_MiniGame][1];
    fn_80034E20(task, lbl_3_data_B0E0);
    task->_1C = 1;
    ((UnkTask3448*)lbl_803CC1B8)->_00 = fn_3_128A38;
}

// .text:0x00128A38 size:0x158 mapped:0x80767ACC
void fn_3_128A38(void) {
    UnkTask3448* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0) {
        goto remove;
    }
    if (task->_1C == 1) {
        if (lbl_80371C30[task->_14]._00->_5C >> 16 >= 10) {
            lbl_80371C30[task->_14]._00->_68 = 0;
            task->_1C++;
        }
    } else if (task->_1C == 2) {
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            if (lbl_3_common_bss_34C90._1D2 == 5) {
                lbl_80371C30[task->_14]._00->_68 = 1;
                task->_1C++;
            }
        } else if (lbl_3_common_bss_34C90._1D4 == 5) {
            lbl_80371C30[task->_14]._00->_68 = 1;
            task->_1C++;
        }
    } else if (task->_1C == 3) {
        if (lbl_80371C30[task->_14]._00->_5C >> 16 >= 20) {
            goto remove;
        }
    }
    return;

remove:
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}

// .text:0x00127B68 size:0xED0 mapped:0x80766BFC
void fn_3_127B68(void) {
    return;
}

// .text:0x001274B4 size:0x6B4 mapped:0x80766548
void fn_3_1274B4(void) {
    return;
}

// .text:0x00126604 size:0xEB0 mapped:0x80765698
void fn_3_126604(void) {
    return;
}

// .text:0x001258C0 size:0xD44 mapped:0x80764954
void fn_3_1258C0(void) {
    return;
}

// .text:0x00125850 size:0x70 mapped:0x807648E4
void fn_3_125850(void) {
    UnkTask3448* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_91BC);
    g_Minigame.bODRelated = 0;
    task->_18 = 0;
    task->_1A = 0;
    task->_1C = 0;
    ((UnkTask3448*)lbl_803CC1B8)->_00 = fn_3_125604;
}

// .text:0x00125604 size:0x24C mapped:0x80764698
void fn_3_125604(void) {
    UnkTask3448* task = lbl_803CC1B8;

    if (g_Minigame._1A40 == 0) {
        if (task->_18 < 0xFFFE) {
            task->_18++;
        } else {
            task->_18 = 0xFFFF;
        }
        if (task->_1C == 0) {
            if (g_Minigame._1A41 != 0 && --g_Minigame.someGraphicFrameCountdown <= 0) {
                lbl_80371C30[task->_14]._00->_64 = lbl_3_data_91FC[g_Minigame._1A41];
                lbl_80371C30[task->_14]._00->_54 |= 2;
                lbl_80371C30[task->_14]._00->_68 = 1;
                lbl_80371C30[task->_14]._00->_5C = 0;
                if (g_Minigame._1A41 == 4) {
                    fn_800363D8(task, 0, 1, 0x13C, g_Scores._00 - 1);
                    fn_3_90064(0x2F8);
                }
                task->_1C = g_Minigame._1A41;
                task->_18 = 0;
                g_Minigame.bODRelated = 1;
                g_Minigame._1A41 = 0;
            }
        } else {
            if (lbl_80371C30[task->_14]._00->_69 == 2) {
                if (task->_1C == 4) {
                    fn_800362F0(task, 0);
                }
                lbl_80371C30[task->_14]._00->_54 &= ~2;
                g_Minigame.bODRelated = 0;
                g_Minigame._1A41 = 0;
                task->_1C = 0;
            }
            if (task->_1C == 2) {
                if (task->_18 == 70) {
                    sndFXStartEx(0x1BD, lbl_800EFBA4[6], 0x3F, 0);
                }
            } else if (task->_1C == 1) {
                if (task->_18 == 1 && lbl_800EF808._398 == 1) {
                    fn_3_90064(0x2EE);
                }
            }
        }
    } else {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x001254F8 size:0x10C mapped:0x8076458C
void fn_3_1254F8(void) {
    UnkTask3448* task = lbl_803CC1B8;

    if (g_GameLogic.gameStatus != GAME_STATUS_GAME_START_MOVIE) {
        g_Minigame._1E02 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        g_Minigame._1E02 = 1;
        fn_80034E20(task, lbl_3_data_23894);
        lbl_80371C30[task->_14]._00->_64 = lbl_3_data_238F4[g_Minigame.GameMode_MiniGame];
        if (g_Minigame._1A3C != 0 && g_Minigame._1E2A >= 6) {
            lbl_80371C30[task->_14 + 1]._00->_54 |= 2;
        }
        task->_1C = 1;
        break;
    case 1:
        break;
    }
}

// .text:0x00125480 size:0x78 mapped:0x80764514
s32 fn_3_125480(UnkTask3448* task) {
    UnkSprite3448* sprite;
    u32 i;

    for (i = 0; i < task->_16; i++) {
        sprite = lbl_80371C30[task->_14 + i]._00;
        if (sprite->_68 == 1) {
            if (sprite->_69 != 2) {
                return 1;
            }
        } else if (sprite->_68 == 4 && sprite->_5C >> 16 != 0) {
            return 1;
        }
    }
    return 0;
}

// .text:0x00125424 size:0x5C mapped:0x807644B8
u32 fn_3_125424(UnkTask3448* task, s32 i, u32 frame) {
    UnkSprite3448* sprite = lbl_80371C30[task->_14 + i]._00;

    if (sprite->_5C >> 16 < frame) {
        sprite->_68 = 1;
        return 0;
    }
    if (sprite->_5C >> 16 > frame) {
        sprite->_68 = 4;
        return 0;
    }
    sprite->_68 = 0;
    return 1;
}

// .text:0x0012536C size:0xB8 mapped:0x80764400
u32 fn_3_12536C(void) {
    if (lbl_3_common_bss_32724._96 != 0 || lbl_3_common_bss_32724._B7 != 0) {
        return 1;
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_MINIGAME_POSTGAME) {
        return 1;
    }
    if (g_Minigame.pauseInd != 0) {
        if (lbl_3_common_bss_34C90._1D2 == 7 || lbl_3_common_bss_34C90._1D2 == 9) {
            return 1;
        }
        if (lbl_3_common_bss_34C90._1D2 == 13) {
            return 1;
        }
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_MVP_END_GAME && g_GameLogic.FrameCountOfCurrentPitch == 0) {
        return 1;
    }
    return 0;
}

// .text:0x00124CE0 size:0x68C mapped:0x80763D74
void fn_3_124CE0(void) {
    return;
}

// .text:0x00124738 size:0x5A8 mapped:0x807637CC
void fn_3_124738(void) {
    UnkTask3448* task = lbl_803CC1B8;
    int n;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_23A44);
        if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER) {
            fn_800363D8(task, 1, 4, 0x14D, 1);
        }
        task->_1C = 1;
        break;
    case 1:
        if (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT && g_GameLogic.FrameCountOfCurrentPitch == 0) {
            if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY) {
                task->_24 = g_Minigame.bODRoundStartingNumPitches - g_Minigame.miniGameTurnCounter;
                task->_25 = g_Minigame.miniGameTurnCounter;
            } else {
                task->_24 = g_Minigame.bB_pitchesRemainingInTurn;
            }
        }
        n = task->_24;
        if (n > 99) {
            n = 99;
        }
        if (n > 1) {
            lbl_80371C30[task->_14 + 1]._00->_5C = 0;
            if (n >= 10) {
                fn_800363D8(task, 1, 1, 0x14E, (n % 100) / 10);
            } else {
                fn_800363D8(task, 1, 1, 0x14E, 10);
            }
            fn_800363D8(task, 1, 2, 0x14E, n % 10);
            lbl_80371C30[task->_14 + 2]._00->_68 = 0;
            lbl_80371C30[task->_14 + 2]._00->_5C = 0;
        } else {
            lbl_80371C30[task->_14 + 1]._00->_5C = 1 << 16;
            lbl_80371C30[task->_14 + 2]._00->_68 = 1;
        }
        if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY) {
            if (g_Minigame.multiPlayerInd == 0 && g_Minigame._1A3C == 0 &&
                g_Minigame.soloMinigameDifficulty == MINIGAME_DIFFICULTY_SOLO_NON_CHALLENGE) {
                if (g_Minigame.bODRoundStartingNumPitches <= task->_25 && task->_25 < 19) {
                    lbl_80371C30[task->_14 + 1]._00->_5C = 1 << 16;
                    lbl_80371C30[task->_14 + 2]._00->_68 = 0;
                    lbl_80371C30[task->_14 + 2]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 3]._00->_68 = 1;
                } else {
                    lbl_80371C30[task->_14 + 3]._00->_68 = 0;
                    lbl_80371C30[task->_14 + 3]._00->_5C = 0;
                }
            }
            if (g_GameLogic.gameStatus == GAME_STATUS_DEFAULT || g_GameLogic.gameStatus == GAME_STATUS_AT_BAT) {
                if (task->_24 <= 1 && g_Pitcher.pitcherActionState >= PITCHER_ACTION_STATE_NO_CONTACT) {
                    lbl_80371C30[task->_14]._00->_68 = 1;
                } else {
                    fn_3_125424(task, 0, 14);
                }
            } else if (getFrame(task, 0) != 0 && fn_3_125424(task, 0, 24)) {
                lbl_80371C30[task->_14]._00->_5C = 0;
            }
        } else if (g_Minigame.bB_pitchesRemainingInTurn == 0 && g_GameLogic.gameStatus != GAME_STATUS_DEFAULT &&
                   g_GameLogic.gameStatus != GAME_STATUS_AT_BAT && g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL) {
            lbl_80371C30[task->_14]._00->_68 = 1;
        } else {
            fn_3_125424(task, 0, 14);
        }
        break;
    }
}

// .text:0x001243A4 size:0x394 mapped:0x80763438
void fn_3_1243A4(void) {
    UnkTask3448* task = lbl_803CC1B8;
    u32 score;
    u32 total;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_23AE4);
        switch (g_Minigame.GameMode_MiniGame) {
        case MINI_GAME_ID_BOBOMB_DERBY:
            lbl_80371C30[task->_14]._00->_5C = 0 << 16;
            break;
        case MINI_GAME_ID_WALLBALL:
            lbl_80371C30[task->_14]._00->_5C = 1 << 16;
            break;
        case MINI_GAME_ID_BARREL_BATTER:
            lbl_80371C30[task->_14]._00->_5C = 2 << 16;
            break;
        }
        task->_1C = 1;
        break;
    case 1:
        switch (g_Minigame.GameMode_MiniGame) {
        case MINI_GAME_ID_BOBOMB_DERBY:
            score = g_Scores._00;
            total = g_Scores._AA;
            break;
        case MINI_GAME_ID_WALLBALL:
            score = g_Scores._00;
            total = g_Scores._AA;
            break;
        case MINI_GAME_ID_BARREL_BATTER:
            score = g_Scores._00;
            total = g_Scores._AA;
            break;
        }
        if (total > 9) {
            total = 9;
        }
        if (score > total) {
            score = total;
        }
        fn_800363D8(task, 2, 1, 0x140, score);
        fn_800363D8(task, 2, 4, 0x140, total);
        switch (g_Minigame.GameMode_MiniGame) {
        case MINI_GAME_ID_BOBOMB_DERBY:
            if (g_GameLogic.gameStatus == GAME_STATUS_DEFAULT || g_GameLogic.gameStatus == GAME_STATUS_AT_BAT) {
                lbl_80371C30[task->_14 + 1]._00->_68 = 1;
            } else {
                lbl_80371C30[task->_14 + 1]._00->_68 = 4;
            }
            break;
        case MINI_GAME_ID_WALLBALL:
            lbl_80371C30[task->_14 + 1]._00->_68 = 1;
            break;
        case MINI_GAME_ID_BARREL_BATTER:
            lbl_80371C30[task->_14 + 1]._00->_68 = 1;
            break;
        }
        if (lbl_80366158._28 != 0) {
            lbl_80371C30[task->_14 + 2]._00->_68 = 0;
        } else {
            lbl_80371C30[task->_14 + 2]._00->_68 = 1;
        }
        break;
    }
}

// .text:0x00123EBC size:0x4E8 mapped:0x80762F50
void fn_3_123EBC(void) {
    return;
}

// .text:0x00123990 size:0x52C mapped:0x80762A24
void fn_3_123990(void) {
    UnkTask3448* task = lbl_803CC1B8;
    u32 i;
    s8 ch;
    s16 x;
    s16 y;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_23C84);
        i = 0;
        do {
            switch (g_Minigame.GameMode_MiniGame) {
            case MINI_GAME_ID_WALLBALL:
                lbl_80371C30[task->_14 + i]._00->_64 = 0xB3;
                break;
            case MINI_GAME_ID_CHAINCHOMP_SPRINT:
                lbl_80371C30[task->_14 + i]._00->_64 = 0xB5;
                break;
            case MINI_GAME_ID_PIRANHA_PANIC:
                lbl_80371C30[task->_14 + i]._00->_64 = 0xB4;
                break;
            case MINI_GAME_ID_STAR_DASH:
                lbl_80371C30[task->_14 + i]._00->_64 = 0xB6;
                break;
            }
        } while (++i < 4);
        i = 0;
        do {
            ch = g_Minigame.minigameControlStruct.characterIndex[i];
            if (ch < 0) {
                lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
            } else if (g_Minigame.minigameControlStruct.battingHandedness[i] != 0) {
                fn_800363D8(task, i, 1, 6, ch + 4);
            } else {
                fn_800363D8(task, i, 1, 6, ch);
            }
        } while (++i < 4);
        task->_1C = 1;
        break;
    case 1:
        i = 0;
        do {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                switch (g_Minigame.GameMode_MiniGame) {
                case MINI_GAME_ID_WALLBALL:
                    fn_800528C0(g_Pitcher.pitcher.x, 0.0f, g_Pitcher.pitcher.z, &x, &y);
                    if (i == g_Minigame.minigamePlayerSelectedOrder && g_Pitcher.pitcherActionState == PITCHER_ACTION_STATE_PRE_PITCH) {
                        lbl_80371C30[task->_14 + i]._00->_54 |= 2;
                    } else {
                        lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                    }
                    break;
                case MINI_GAME_ID_CHAINCHOMP_SPRINT:
                    fn_800528C0(g_Runners[i].position.x, g_Runners[i].position.y, g_Runners[i].position.z, &x, &y);
                    if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_MINIGAME_TO_BATTING) {
                        lbl_80371C30[task->_14 + i]._00->_54 |= 2;
                    } else {
                        lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                    }
                    break;
                case MINI_GAME_ID_PIRANHA_PANIC:
                case MINI_GAME_ID_STAR_DASH:
                    fn_800528C0(g_Fielders[g_Minigame.minigameFielderIndex[i]].position.x,
                                g_Fielders[g_Minigame.minigameFielderIndex[i]].position.y,
                                g_Fielders[g_Minigame.minigameFielderIndex[i]].position.z, &x, &y);
                    if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_MINIGAME_TO_BATTING) {
                        lbl_80371C30[task->_14 + i]._00->_54 |= 2;
                    } else {
                        lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                    }
                    break;
                default:
                    x = 650;
                    y = 490;
                    lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                    break;
                }
                lbl_80371C30[task->_14 + i]._00->_48 = x;
                lbl_80371C30[task->_14 + i]._00->_4C = y;
            }
        } while (++i < 4);
        break;
    }
}

// .text:0x001235B8 size:0x3D8 mapped:0x8076264C
void fn_3_1235B8(void) {
    UnkTask3448* task = lbl_803CC1B8;
    u32 n;
    u32 digit;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_23D24);
        task->_1C = 1;
        break;
    case 1:
        if (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT &&
            g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] >= 2) {
            lbl_80371C30[task->_14]._00->_5C = (g_Batter.batterHand != 0) << 16;
            n = g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0];
            if (n > 99) {
                n = 99;
            }
            if (n < 10) {
                lbl_80371C30[task->_14 + 1]._00->_68 = 1;
                digit = n % 10;
                fn_800363D8(task, 1, 4, 0x104, digit);
                fn_800363D8(task, 1, 5, 0x104, digit);
                fn_800363D8(task, 1, 6, 0x104, digit);
                lbl_80371C30[task->_14 + 2]._00->_68 = 0;
                lbl_80371C30[task->_14 + 2]._00->_5C = 0;
            } else {
                lbl_80371C30[task->_14 + 2]._00->_68 = 1;
                digit = n % 10;
                fn_800363D8(task, 2, 4, 0x104, digit);
                fn_800363D8(task, 2, 5, 0x104, digit);
                fn_800363D8(task, 2, 6, 0x104, digit);
                digit = (n % 100) / 10;
                fn_800363D8(task, 2, 7, 0x104, digit);
                fn_800363D8(task, 2, 8, 0x104, digit);
                fn_800363D8(task, 2, 9, 0x104, digit);
                lbl_80371C30[task->_14 + 1]._00->_68 = 0;
                lbl_80371C30[task->_14 + 1]._00->_5C = 0;
            }
        } else {
            lbl_80371C30[task->_14 + 1]._00->_68 = 4;
            lbl_80371C30[task->_14 + 2]._00->_68 = 4;
        }
        break;
    }
}

// .text:0x001231D4 size:0x3E4 mapped:0x80762268
void fn_3_1231D4(void) {
    UnkTask3448* task = lbl_803CC1B8;
    UnkTask3448* parent = ((UnkTask3448*)lbl_803CC1B8)->_0C;
    u32 n;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_23DA4);
        task->_1C = 1;
        break;
    case 1:
        lbl_80371C30[task->_14]._00->_68 = 4;
        if (parent->_1A == 1 && g_Minigame.bOD_KingBombInd != 0) {
            if (g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] >= 2) {
                lbl_80371C30[task->_14]._00->_64 = 0x164;
                lbl_80371C30[task->_14 + 1]._00->_72 = 0;
            } else {
                lbl_80371C30[task->_14]._00->_64 = 0x163;
                lbl_80371C30[task->_14 + 1]._00->_72 = 0;
            }
            n = lbl_3_data_213EC[7];
            if (n > 9999) {
                n = 9999;
            }
            if (n >= 1000) {
                fn_800363D8(task, 1, 4, 0x167, (n % 10000) / 1000);
            } else if (n >= 100) {
                fn_800363D8(task, 1, 4, 0x167, 11);
            } else {
                fn_800363D8(task, 1, 4, 0x167, 10);
            }
            if (n >= 100) {
                fn_800363D8(task, 1, 3, 0x167, (n % 1000) / 100);
            } else if (n >= 10) {
                fn_800363D8(task, 1, 3, 0x167, 11);
            } else {
                fn_800363D8(task, 1, 3, 0x167, 10);
            }
            if (n >= 10) {
                fn_800363D8(task, 1, 2, 0x167, (n % 100) / 10);
            } else {
                fn_800363D8(task, 1, 2, 0x167, 11);
            }
            fn_800363D8(task, 1, 1, 0x167, n % 10);
            task->_1C = 2;
        }
        break;
    case 2:
        lbl_80371C30[task->_14]._00->_68 = 1;
        if (parent->_1A != 1) {
            task->_1C = 1;
        }
        break;
    }
}

// .text:0x00122D24 size:0x4B0 mapped:0x80761DB8
void fn_3_122D24(void) {
    UnkTask3448* task = lbl_803CC1B8;
    UnkTask3448* parent = ((UnkTask3448*)lbl_803CC1B8)->_0C;
    u32 n;
    u32 points;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_23E04);
        task->_1C = 1;
        break;
    case 1:
        lbl_80371C30[task->_14]._00->_68 = 4;
        if (parent->_1A == 1 && g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0] >= 2) {
            if (g_Minigame.bOD_KingBombInd != 0) {
                lbl_80371C30[task->_14]._00->_64 = 0x164;
                lbl_80371C30[task->_14 + 1]._00->_72 = 1;
            } else {
                lbl_80371C30[task->_14]._00->_64 = 0x163;
                lbl_80371C30[task->_14 + 1]._00->_72 = 0;
            }
            n = g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0];
            if (n > 99) {
                n = 99;
            }
            if (n >= 10) {
                fn_800363D8(task, 1, 6, 0x166, (n % 100) / 10);
            } else {
                fn_800363D8(task, 1, 6, 0x166, 10);
            }
            fn_800363D8(task, 1, 5, 0x166, n % 10);
            points = lbl_3_data_213EC[8] * g_Minigame.bODCharacterHRStreakTracker[g_Minigame.rosterID][0];
            if (points > 9999) {
                points = 9999;
            }
            if (points >= 1000) {
                fn_800363D8(task, 1, 4, 0x167, (points % 10000) / 1000);
            } else if (points >= 100) {
                fn_800363D8(task, 1, 4, 0x167, 11);
            } else {
                fn_800363D8(task, 1, 4, 0x167, 10);
            }
            if (points >= 100) {
                fn_800363D8(task, 1, 3, 0x167, (points % 1000) / 100);
            } else if (points >= 10) {
                fn_800363D8(task, 1, 3, 0x167, 11);
            } else {
                fn_800363D8(task, 1, 3, 0x167, 10);
            }
            if (points >= 10) {
                fn_800363D8(task, 1, 2, 0x167, (points % 100) / 10);
            } else {
                fn_800363D8(task, 1, 2, 0x167, 11);
            }
            fn_800363D8(task, 1, 1, 0x167, points % 10);
            task->_1C = 2;
        }
        break;
    case 2:
        lbl_80371C30[task->_14]._00->_68 = 1;
        if (parent->_1A != 1) {
            task->_1C = 1;
        }
        break;
    }
}

// .text:0x001226D4 size:0x650 mapped:0x80761768
void fn_3_1226D4(void) {
    return;
}

// .text:0x00122334 size:0x3A0 mapped:0x807613C8
void fn_3_122334(void) {
    UnkTask3448* task = lbl_803CC1B8;
    MiniGameStruct* minigame = &g_Minigame;
    s32 diff;
    s32 step;
    u32 n;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_23F24);
        task->_1C = 1;
        break;
    case 1:
        if (minigame->_1DF7 != 0) {
            task->_1E = 1;
        }
        if (g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL) {
            if (task->_1E != 0) {
                lbl_80371C30[task->_14]._00->_68 = 1;
            } else {
                fn_3_125424(task, 0, 10);
            }
            if (g_Ball.deadBallReason != 0 && g_Ball.bODQualifyingHitInd != 0) {
                diff = g_Ball.Hit_HorizontalPower - task->_20;
                if (diff != 0) {
                    step = diff / 4;
                    if (step != 0) {
                        task->_20 += step;
                    } else {
                        task->_20 += diff / __abs(diff);
                    }
                }
            } else if (g_Ball.AtBat_ContactResult != 1 && g_Ball.hitWallInd == 0) {
                task->_20 = g_Ball.ballDistanceFromHome;
            }
            n = task->_20;
            if (n > 999) {
                n = 999;
            }
            if (n >= 100) {
                fn_800363D8(task, 0, 3, 0x169, (n % 1000) / 100);
            } else {
                fn_800363D8(task, 0, 3, 0x169, 10);
            }
            if (n >= 10) {
                fn_800363D8(task, 0, 2, 0x169, (n % 100) / 10);
            } else {
                fn_800363D8(task, 0, 2, 0x169, 10);
            }
            fn_800363D8(task, 0, 1, 0x169, n % 10);
        } else {
            lbl_80371C30[task->_14]._00->_68 = 0;
            lbl_80371C30[task->_14]._00->_5C = 0;
            task->_1E = 0;
            task->_20 = 0;
        }
        break;
    }
}

// .text:0x00121908 size:0xA2C mapped:0x8076099C
void fn_3_121908(void) {
    return;
}

// .text:0x00121304 size:0x604 mapped:0x80760398
void fn_3_121304(void) {
    return;
}

// .text:0x00120FF8 size:0x30C mapped:0x8076008C
void fn_3_120FF8(void) {
    UnkTask3448* task = lbl_803CC1B8;
    u32 n;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_246E4);
        lbl_80371C30[task->_14 + 2]._00->_5C = 13 << 16;
        task->_1E = task->_20 = g_Scores._AA;
        task->_1C = 1;
        break;
    case 1:
        if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_PREPARE_NEXT_PLAY) {
            task->_1E = g_Scores._AA - (g_Scores._00 - 1);
        }
        n = task->_1E;
        if (n > 9) {
            n = 9;
        }
        fn_800363D8(task, 1, 1, 0x14E, n % 10);
        fn_3_125424(task, 0, 10);
        if (task->_20 != task->_1E) {
            if (task->_20 < task->_1E) {
                lbl_80371C30[task->_14 + 2]._00->_68 = 1;
                lbl_80371C30[task->_14 + 2]._00->_5C = 0;
            } else if (task->_20 - task->_1E == 2) {
                lbl_80371C30[task->_14 + 3]._00->_68 = 1;
                lbl_80371C30[task->_14 + 3]._00->_5C = 0;
                lbl_80371C30[task->_14]._00->_68 = 1;
                task->_1C = 2;
            }
            task->_20 = task->_1E;
        }
        break;
    case 2:
        if (isAnimDone(lbl_80371C30[task->_14]._00)) {
            lbl_80371C30[task->_14]._00->_5C = 10 << 16;
            task->_1C = 1;
        }
        break;
    }
}

// .text:0x00120F5C size:0x9C mapped:0x8075FFF0
s32 fn_3_120F5C(void) {
    s16 mult = 1;

    if ((g_Minigame.multiPlayerInd != 0 || g_Minigame._1A3C != 0 || g_Minigame.soloMinigameDifficulty != MINIGAME_DIFFICULTY_SOLO_NON_CHALLENGE) &&
        g_Scores._00 == g_Scores._AA) {
        mult = lbl_3_data_21672;
    }
    if (g_Minigame.wallBall_hitNoteBlock == 1) {
        return lbl_3_data_21654[10] * mult;
    }
    return g_Minigame.miniGameLatestPoints[g_Minigame.minigamePlayerSelectedOrder] * mult;
}

// .text:0x0012089C size:0x6C0 mapped:0x8075F930
void fn_3_12089C(void) {
    return;
}

// .text:0x0012026C size:0x630 mapped:0x8075F300
void fn_3_12026C(void) {
    return;
}

// .text:0x0011FDB0 size:0x4BC mapped:0x8075EE44
void fn_3_11FDB0(void) {
    UnkTask3448* task = lbl_803CC1B8;
    u32 i;
    u32 j;
    u32 max;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_24B04);
        lbl_80371C30[task->_14]._00->_64 = g_Batter.batterHand != 0 ? 0x11F : 0x120;
        for (i = 0; i < 10; i++) {
            for (j = 1; j <= 4; j++) {
                fn_800363D8(task, i + 3, j, 0x121, i);
            }
        }
        task->_1C = 1;
        break;
    case 1:
        if (g_Minigame.bB_bombBarrelID >= 0 && g_Minigame.bB_bombBarrelID < 15) {
            max = 10;
        } else {
            max = g_Minigame.barrelBatterChargeMeter;
            if (max > 10) {
                max = 10;
            }
        }
        if (task->_1E < max) {
            task->_1E++;
        } else {
            task->_1E = max;
        }
        if (task->_1E <= 3) {
            i = 0;
            do {
                lbl_80371C30[task->_14 + 3 + i]._00->_64 = 0x122;
            } while (++i < 10);
            lbl_80371C30[task->_14 + 13]._00->_64 = 0x126;
        } else if (task->_1E <= 6) {
            i = 0;
            do {
                lbl_80371C30[task->_14 + 3 + i]._00->_64 = 0x123;
            } while (++i < 10);
            lbl_80371C30[task->_14 + 13]._00->_64 = 0x127;
        } else {
            i = 0;
            do {
                lbl_80371C30[task->_14 + 3 + i]._00->_64 = 0x124;
            } while (++i < 10);
            lbl_80371C30[task->_14 + 13]._00->_64 = 0x128;
        }
        for (i = 0; i < task->_1E; i++) {
            lbl_80371C30[task->_14 + 3 + i]._00->_58 = (lbl_80371C30[task->_14 + 3 + i]._00->_58 & ~0xFF) | 0xFF;
        }
        for (; i < 10; i++) {
            lbl_80371C30[task->_14 + 3 + i]._00->_58 &= ~0xFF;
        }
        break;
    }
    if (task->_1E >= lbl_3_data_21788[2] && g_Minigame.pauseInd == 0 &&
        g_d_GameSettings.FrameCountWhileNotAtMainMenu % 45 == 0) {
        fn_3_90064(0x2FC);
    }
}

// .text:0x0011FA58 size:0x358 mapped:0x8075EAEC
void fn_3_11FA58(void) {
    UnkTask3448* task = lbl_803CC1B8;
    u32 n;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_24CE4);
        task->_1C = 1;
        break;
    case 1:
        lbl_80371C30[task->_14]._00->_5C = (g_Batter.batterHand == 0) << 16;
        lbl_80371C30[task->_14 + 1]._00->_68 = 0;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0;
        if (g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL && g_Minigame.barrelBatter_scoreCalculatedInd != 0 &&
            g_Minigame._1DF4_s16 > 0) {
            n = g_Minigame._1DF4_s16;
            g_Minigame._1DF4_s16 = 0;
            if (n > 9999) {
                n = 9999;
            }
            fn_800363D8(task, 1, 4, 0x11B, n >= 1000 ? (n % 10000) / 1000 : 10);
            fn_800363D8(task, 1, 3, 0x11B, n >= 100 ? (n % 1000) / 100 : 10);
            fn_800363D8(task, 1, 2, 0x11B, n >= 10 ? (n % 100) / 10 : 10);
            fn_800363D8(task, 1, 1, 0x11B, n % 10);
            lbl_80371C30[task->_14 + 1]._00->_68 = 1;
            task->_1C = 2;
        }
        break;
    case 2:
        if (lbl_80371C30[task->_14 + 1]._00->_69 == 2 && g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL) {
            task->_1C = 1;
        }
        break;
    }
}

// .text:0x0011F778 size:0x2E0 mapped:0x8075E80C
void fn_3_11F778(void) {
    UnkTask3448* task = lbl_803CC1B8;
    u32 n;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_24D44);
        task->_1C = 1;
        break;
    case 1:
        lbl_80371C30[task->_14]._00->_5C = (g_Batter.batterHand == 0) << 16;
        lbl_80371C30[task->_14 + 1]._00->_68 = 0;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0;
        if (g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL && g_Minigame.barrelBatter_scoreCalculatedInd != 0 &&
            g_Minigame.barrelBatter_barrelsHit >= 2) {
            n = g_Minigame.barrelBatter_barrelsHit;
            if (n > 99) {
                n = 99;
            }
            if (n < 10) {
                lbl_80371C30[task->_14 + 1]._00->_64 = 0x12A;
            } else {
                lbl_80371C30[task->_14 + 1]._00->_64 = 0x129;
            }
            fn_800363D8(task, 1, 5, 0x12C, (n % 100) / 10);
            fn_800363D8(task, 1, 4, 0x12C, n % 10);
            lbl_80371C30[task->_14 + 1]._00->_68 = 1;
            task->_1C = 2;
        }
        break;
    case 2:
        if (lbl_80371C30[task->_14 + 1]._00->_69 == 2 && g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL) {
            task->_1C = 1;
        }
        break;
    }
}

// .text:0x0011F508 size:0x270 mapped:0x8075E59C
void fn_3_11F508(void) {
    UnkTask3448* task = lbl_803CC1B8;
    u32 n;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_24DA4);
        task->_1C = 1;
        break;
    case 1:
        lbl_80371C30[task->_14]._00->_5C = (g_Batter.batterHand == 0) << 16;
        lbl_80371C30[task->_14 + 1]._00->_68 = 0;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0;
        if (g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL && g_Minigame.barrelBatter_scoreCalculatedInd != 0 &&
            g_Minigame.bB_bombBarrelHitInd != 0) {
            n = lbl_3_data_21798[6];
            if (n > 9) {
                n = 9;
            }
            fn_800363D8(task, 1, 2, 0x12F, n % 10);
            lbl_80371C30[task->_14 + 1]._00->_68 = 1;
            task->_1C = 2;
        }
        break;
    case 2:
        if (lbl_80371C30[task->_14 + 1]._00->_69 == 2 && g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL) {
            task->_1C = 1;
        }
        break;
    }
}

// .text:0x0011F4B4 size:0x54 mapped:0x8075E548
void fn_3_11F4B4(s32 player, s32 bonus) {
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_CHAINCHOMP_SPRINT) {
        g_Minigame._1DF4_arr[player] += lbl_3_data_21884[bonus ? 2 : 0][1];
    }
}

// .text:0x0011F480 size:0x34 mapped:0x8075E514
void fn_3_11F480(void) {
    u32 i;

    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_CHAINCHOMP_SPRINT) {
        i = 0;
        do {
            g_Minigame._1DF4_arr[i] = g_Minigame.miniGameCurrentPoints[i];
        } while (++i < 4);
    }
}

// .text:0x0011F02C size:0x454 mapped:0x8075E0C0
// 99.73%: the target keeps i in r19 and leaderPoints in r21, the base the reverse.
void fn_3_11F02C(void) {
    u32 i;
    UnkTask3448* task = lbl_803CC1B8;
    s32 leader;
    s16* leaderPoints;
    u32 tied;
    s32 diff;
    u32 n;
    u32 playSound = 0;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_24E04);
        i = 0;
        do {
            fn_800363D8(task, i + 9, 1, 0x65, i);
            lbl_80371C30[task->_14 + 0x11 + i]._00->_5C = inMemRoster[0][i].stats.CharID << 16;
        } while (++i < 4);
        i = 0;
        do {
            lbl_80371C30[task->_14 + 0x25 + i]._00->_54 &= ~2;
        } while (++i < 4);
        task->_1C = 1;
        break;
    case 1:
        leader = fn_3_107CD0();
        tied = fn_3_107C88();
        leaderPoints = g_Minigame.minigamePoints_current_Latest[leader];
        i = 0;
        do {
            if (g_Minigame._1DFC[i] != 0) {
                g_Minigame._1DFC[i] = 0;
                lbl_80371C30[task->_14 + 1 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 1 + i]._00->_68 = 1;
            }
            if (g_Minigame._1DF4_arr[i] > g_Minigame.miniGameCurrentPoints[i]) {
                g_Minigame._1DF4_arr[i] = g_Minigame.miniGameCurrentPoints[i];
            }
            diff = g_Minigame._1DF4_arr[i] - g_Minigame.minigamePoints_current_Latest[i][0];
            if (diff > 0) {
                g_Minigame.minigamePoints_current_Latest[i][0]++;
                playSound = 1;
                task->_24_arr[i] = 1;
            } else if (diff < 0) {
                playSound = 1;
                g_Minigame.minigamePoints_current_Latest[i][0]--;
            } else if (task->_24_arr[i] != 0) {
                task->_24_arr[i] = 0;
                lbl_80371C30[task->_14 + 0x19 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 0x19 + i]._00->_68 = 1;
                lbl_80371C30[task->_14 + 0x1D + i * 2]._00->_5C = 0;
                lbl_80371C30[task->_14 + 0x1E + i * 2]._00->_5C = 0;
            }
            n = g_Minigame.minigamePoints_current_Latest[i][0];
            if (n > 99) {
                n = 99;
            }
            fn_800363D8(task, 0x1D + i * 2, 1, 0x66, (n % 100) / 10);
            fn_800363D8(task, 0x1E + i * 2, 1, 0x66, n % 10);
            if (tied == 0 && g_Minigame.minigamePoints_current_Latest[i][0] == leaderPoints[0]) {
                lbl_80371C30[task->_14 + 0x25 + i]._00->_54 |= 2;
            } else {
                lbl_80371C30[task->_14 + 0x25 + i]._00->_54 &= ~2;
            }
        } while (++i < 4);
        break;
    }
    if (playSound) {
        sndFXStartEx(0x1C0, lbl_800EFBA4[9], 0x3F, 0);
    }
}

// .text:0x0011EC28 size:0x404 mapped:0x8075DCBC
void fn_3_11EC28(void) {
    UnkTask3448* task = lbl_803CC1B8;
    u32 i;
    s16 x;
    s16 y;

    if (fn_3_12536C()) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    switch (task->_1C) {
    case 0:
        fn_80034E20(task, lbl_3_data_25344);
        task->_1C = 1;
        break;
    case 1:
        i = 0;
        do {
            lbl_80371C30[task->_14 + i]._00->_68 = 0;
            lbl_80371C30[task->_14 + i]._00->_5C = 0;
        } while (++i < 8);
        if (g_Minigame._1E00 != 0) {
            i = 0;
            g_Minigame._1E00 = 0;
            if (g_Minigame._1B33 != 0) {
                do {
                    if (g_Minigame._1B2F[i] == 1) {
                        lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
                        fn_800528C0(g_Runners[i].position.x, g_Runners[i].position.y, g_Runners[i].position.z, &x, &y);
                        if (x < 80) {
                            x = 80;
                        } else if (x > 560) {
                            x = 560;
                        }
                        lbl_80371C30[task->_14 + 4 + i]._00->_48 = x;
                        lbl_80371C30[task->_14 + 4 + i]._00->_4C = y;
                    }
                } while (++i < 4);
            } else {
                do {
                    lbl_80371C30[task->_14 + i]._00->_68 = 1;
                    fn_800528C0(g_Runners[i].position.x, g_Runners[i].position.y, g_Runners[i].position.z, &x, &y);
                    if (x < 80) {
                        x = 80;
                    } else if (x > 560) {
                        x = 560;
                    }
                    lbl_80371C30[task->_14 + i]._00->_48 = x;
                    lbl_80371C30[task->_14 + i]._00->_4C = y;
                } while (++i < 4);
            }
            task->_1C = 2;
        }
        break;
    case 2:
        i = 0;
        do {
            if (lbl_80371C30[task->_14 + i]._00->_68 != 0 && lbl_80371C30[task->_14 + i]._00->_69 != 2) {
                break;
            }
        } while (++i < 8);
        if (i >= 8) {
            task->_1C = 1;
        }
        break;
    }
}
