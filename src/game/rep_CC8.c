#include "game/rep_CC8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"

typedef struct {
    /* 0x000 */ u8 _000[0xC];
    /* 0x00C */ s32 _00C;
    /* 0x010 */ u8 _010[0x252 - 0x10];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253[0x27C - 0x253];
} UnkCC8Player; // size: 0x27C

extern struct {
    /* 0x000 */ u8 _000[0xC04];
    /* 0xC04 */ UnkCC8Player _C04[4];
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0xC4];
    /* 0xC4 */ u8 _C4;
    /* 0xC5 */ u8 _C5;
} g_Scores;

extern struct {
    /* 0x00 */ u8 _00[0xD3];
    /* 0xD3 */ u8 _D3;
} lbl_3_common_bss_32724;

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
} UnkCC8Task;

extern UnkCC8Task* lbl_803CC1B8;

extern u8 lbl_800F1D78[][16];

extern void fn_80017D28(s32);
extern BOOL fn_80022B68(void);
extern void fn_80022CB4(void*, s32, s32, s32, void (*)(s32, s32, s32), void*);
extern void fn_8001AAA4(void);
extern void fn_3_6AEC0(void);

// .text:0x00059BCC size:0x60 mapped:0x80698C60
BOOL fn_3_59BCC(s32 arg0) {
    UnkCC8Task* task = lbl_803CC1B8;

    if (arg0 < 1) {
        return FALSE;
    }
    if (arg0 == 1) {
        fn_8001AAA4();
    }
    if (task->_10 != 0) {
        fn_3_6AEC0();
        return TRUE;
    }
    return FALSE;
}

// .text:0x00059B20 size:0xAC mapped:0x80698BB4
void fn_3_59B20(void) {
    int i;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        for (i = 0; i < 4; i++) {
            UnkCC8Player* player = &lbl_8036E548._C04[i];
            fn_80022CB4(lbl_800F1D78[player->_252 * 19 + 1], player->_00C, 0, 0, fn_3_59AC0, player);
        }
    }
}

// .text:0x00059AE4 size:0x3C mapped:0x80698B78
BOOL fn_3_59AE4(void) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        return fn_80022B68();
    }
    return TRUE;
}

// .text:0x00059AC0 size:0x24 mapped:0x80698B54
void fn_3_59AC0(s32 arg0, s32 arg1, s32 arg2) {
    fn_80017D28(arg2);
}

// .text:0x00059A90 size:0x30 mapped:0x80698B24
void fn_3_59A90(void) {
    g_UnkSound_32718._02[0] = 0;
    g_UnkSound_32718._02[1] = 0;
    g_UnkSound_32718._02[2] = 0;
    g_UnkSound_32718._02[3] = 0;
    g_UnkSound_32718._02[4] = 0;
    g_UnkSound_32718._00 = 0;
    g_UnkSound_32718._07 = 0;
    g_UnkSound_32718._08 = 0;
}

// .text:0x00059918 size:0x178 mapped:0x806989AC
void fn_3_59918(int arg0, int arg1) {
    int i;

    if (g_Stats.replayInd != 0) {
        return;
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY && g_Ball.deadBallReason != 2) {
        return;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE &&
        (g_Practice.practiceLevel == 7 || g_Practice.practiceLevel == 6)) {
        if (arg0 == 5) {
            return;
        }
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice._186 != 0) {
        return;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && arg0 == 5) {
        if (lbl_3_common_bss_32724._D3 != 0) {
            return;
        }
        lbl_3_common_bss_32724._D3 = 1;
    }
    if (g_GameLogic.playOver != 0) {
        return;
    }
    if (g_Scores._C5 != 0) {
        return;
    }
    if (arg0 == 4) {
        if (g_Scores._C4 != 0) {
            return;
        }
        g_Scores._C4 = 1;
    }
    if (arg0 == 13 || arg0 == 17) {
        if (g_Scores._C5 != 0) {
            return;
        }
        g_Scores._C5 = 1;
        g_GameLogic.gameOverInd = 1;
    }
    for (i = 0; i < 5; i++) {
        if (g_UnkSound_32718._02[i] == 0) {
            g_UnkSound_32718._02[i] = arg0;
            return;
        }
    }
}
