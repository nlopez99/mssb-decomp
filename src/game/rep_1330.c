#include "game/rep_1330.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_720.h"
#include "game/rep_EA0.h"
#include "game/rep_1D58.h"
#include "game/rep_1E08.h"
#include "game/m_sound.h"
#include "game/rep_9B0.h"
#include "game/rep_3090.h"
#include "musyx/musyx.h"
#include "string.h"

typedef struct {
    /* 0x0 */ s16 controlStickAngle;
    /* 0x2 */ u16 buttonInput;
    /* 0x4 */ u16 newButtonInput;
    /* 0x6 */ s8 right_left;
    /* 0x7 */ s8 up_down;
} ReplayInput; // size: 0x8

extern ReplayState g_ReplayCopies;
extern ReplayInput g_ReplayLogic[][2];

extern u8 g_Scores[0xC8];
extern u8 g_RunningLogic[0x20];
extern u8 g_Fielders[0x15A8];
// Main-DOL bss objects that symbols.txt still covers with lbl_8034E9A0 (+0x4C28, +0x4E44)
extern u8 lbl_803535C8[0x21C];
extern u8 lbl_803537E4[0x2AC];
extern u8 lbl_3_common_bss_32234[0x6];
extern u8 lbl_3_common_bss_32230[0x4];
extern u8 lbl_3_common_bss_32220[0xE];
extern u8 g_UnkThrowing_31ACC[];
extern u8 g_UnkAnimation_31EAC[];
extern u8 lbl_3_common_bss_321A0[0x80];

extern struct {
    /* 0x00 */ u8 _00[0xC8];
    /* 0xC8 */ u8 _C8;
} lbl_3_common_bss_32724;

void changeScene(u8, s16);
void fn_80052798(s32);
void fn_8001B224(void);

static SND_VOICEID lbl_3_bss_1748[6];

// .text:0x0007C9D8 size:0x4B8 mapped:0x806BBA6C
void fn_3_7C9D8(BOOL keepCopies) {
    int i;

    if (!keepCopies) {
        fn_3_7C7AC();
    }
    memcpy(&g_GameLogic, &g_Stats._44.gameLogic, sizeof(g_Stats._44.gameLogic));
    memcpy(&g_Strikes, &g_Stats._44.strikes, sizeof(g_Stats._44.strikes));
    memcpy(g_Scores, g_Stats._44.scores, sizeof(g_Stats._44.scores));
    memcpy(&g_Ball, &g_Stats._44.ball, sizeof(g_Stats._44.ball));
    memcpy(&g_Pitcher, &g_Stats._44.pitcher, sizeof(g_Stats._44.pitcher));
    memcpy(&g_Batter, &g_Stats._44.batter, sizeof(g_Stats._44.batter));
    memcpy(&g_AiLogic, &g_Stats._44.aiLogic, sizeof(g_Stats._44.aiLogic));
    memcpy(&g_FieldingLogic, &g_Stats._44.fieldingLogic, sizeof(g_Stats._44.fieldingLogic));
    memcpy(g_RunningLogic, g_Stats._44.runningLogic, sizeof(g_Stats._44.runningLogic));
    memcpy(g_Fielders, g_Stats._44.fielders, sizeof(g_Stats._44.fielders));
    memcpy(g_Runners, g_Stats._44.runners, sizeof(g_Stats._44.runners));
    memcpy(lbl_803537E4, g_Stats._44._4128, sizeof(g_Stats._44._4128));
    memcpy(lbl_803535C8, g_Stats._44._43D4, sizeof(g_Stats._44._43D4));
    memcpy(lbl_3_common_bss_32234, g_Stats._44._3D88, sizeof(g_Stats._44._3D88));
    memcpy(lbl_3_common_bss_32230, g_Stats._44._3D8E, sizeof(g_Stats._44._3D8E));
    memcpy(lbl_3_common_bss_32220, g_Stats._44._3D92, sizeof(g_Stats._44._3D92));
    memcpy(g_UnkThrowing_31ACC, g_Stats._44._3DA0, sizeof(g_Stats._44._3DA0));
    memcpy(g_UnkAnimation_31EAC, g_Stats._44._3DB4, sizeof(g_Stats._44._3DB4));
    memcpy(lbl_3_common_bss_321A0, g_Stats._44._40A8, sizeof(g_Stats._44._40A8));
    g_Stats.replayInd = 1;
    g_Stats.playFrameCounter = 0;
    fn_3_7C4E4();
    fn_3_1CBCC();
    fn_3_8FC0C();
    lbl_3_common_bss_32724._C8 = 0;
    fn_8001B224();
    fn_3_B908C();
    for (i = 0; i < 13; i++) {
        fn_3_21C7C(i, 1);
    }
    lbl_3_common_bss_34C58._34 = 0;
}

// .text:0x0007C7AC size:0x22C mapped:0x806BB840
void fn_3_7C7AC(void) {
    memcpy(&g_ReplayCopies.gameLogic, &g_GameLogic, sizeof(g_ReplayCopies.gameLogic));
    memcpy(&g_ReplayCopies.strikes, &g_Strikes, sizeof(g_ReplayCopies.strikes));
    memcpy(g_ReplayCopies.scores, g_Scores, sizeof(g_ReplayCopies.scores));
    memcpy(&g_ReplayCopies.ball, &g_Ball, sizeof(g_ReplayCopies.ball));
    memcpy(&g_ReplayCopies.pitcher, &g_Pitcher, sizeof(g_ReplayCopies.pitcher));
    memcpy(&g_ReplayCopies.batter, &g_Batter, sizeof(g_ReplayCopies.batter));
    memcpy(&g_ReplayCopies.aiLogic, &g_AiLogic, sizeof(g_ReplayCopies.aiLogic));
    memcpy(&g_ReplayCopies.fieldingLogic, &g_FieldingLogic, sizeof(g_ReplayCopies.fieldingLogic));
    memcpy(g_ReplayCopies.runningLogic, g_RunningLogic, sizeof(g_ReplayCopies.runningLogic));
    memcpy(g_ReplayCopies.fielders, g_Fielders, sizeof(g_ReplayCopies.fielders));
    memcpy(g_ReplayCopies.runners, g_Runners, sizeof(g_ReplayCopies.runners));
    memcpy(g_ReplayCopies._4128, lbl_803537E4, sizeof(g_ReplayCopies._4128));
    memcpy(g_ReplayCopies._43D4, lbl_803535C8, sizeof(g_ReplayCopies._43D4));
    memcpy(g_ReplayCopies._3D88, lbl_3_common_bss_32234, sizeof(g_ReplayCopies._3D88));
    memcpy(g_ReplayCopies._3D8E, lbl_3_common_bss_32230, sizeof(g_ReplayCopies._3D8E));
    memcpy(g_ReplayCopies._3D92, lbl_3_common_bss_32220, sizeof(g_ReplayCopies._3D92));
    memcpy(g_ReplayCopies._3DA0, g_UnkThrowing_31ACC, sizeof(g_ReplayCopies._3DA0));
    memcpy(g_ReplayCopies._3DB4, g_UnkAnimation_31EAC, sizeof(g_ReplayCopies._3DB4));
    memcpy(g_ReplayCopies._40A8, lbl_3_common_bss_321A0, sizeof(g_ReplayCopies._40A8));
}

// .text:0x0007C4E4 size:0x2C8 mapped:0x806BB578
// The stats pointer and the split magnitude statements compile the same as plain g_Stats
// and one expression, but keep this function above -inline auto's size limit, so
// fn_3_7C9D8 calls it instead of inlining it.
void fn_3_7C4E4(void) {
    g_Stats_s* stats = &g_Stats;
    int i;
    f32 magnitude;

    if (stats->playFrameCounter >= stats->_28) {
        fn_3_7C1FC(TRUE);
        return;
    }
    if (stats->playFrameCounter + 7 == stats->_28 && stats->_3C != 2 && stats->_3C != 13) {
        changeScene(3, 6);
    }
    for (i = 0; i < 2; i++) {
        g_Controls[g_Stats._3F[i]].buttonInput = g_ReplayLogic[stats->playFrameCounter][i].buttonInput;
        g_Controls[g_Stats._3F[i]].newButtonInput = g_ReplayLogic[stats->playFrameCounter][i].newButtonInput;
        g_Controls[g_Stats._3F[i]].right_left = g_ReplayLogic[stats->playFrameCounter][i].right_left;
        g_Controls[g_Stats._3F[i]].up_down = g_ReplayLogic[stats->playFrameCounter][i].up_down;
        g_Controls[g_Stats._3F[i]].controlStickAngle = g_ReplayLogic[stats->playFrameCounter][i].controlStickAngle;
        magnitude = dolsqrtf2(SQ((f32)g_Controls[g_Stats._3F[i]].right_left) +
                              SQ((f32)g_Controls[g_Stats._3F[i]].up_down));
        magnitude -= 16.0f;
        if (magnitude > 56.0f) {
            magnitude = 56.0f;
        }
        magnitude = 64.0f * magnitude;
        magnitude /= 56.0f;
        g_Controls[g_Stats._3F[i]].controlStickMagnitude = magnitude;
    }
    stats->playFrameCounter++;
}

// .text:0x0007C1FC size:0x2E8 mapped:0x806BB290
void fn_3_7C1FC(BOOL arg0) {
    g_Stats_s* stats = &g_Stats;

    stats->replayInd = 0;
    stats->_39 = 0;
    memcpy(&g_GameLogic, &g_ReplayCopies.gameLogic, sizeof(g_ReplayCopies.gameLogic));
    memcpy(&g_Strikes, &g_ReplayCopies.strikes, sizeof(g_ReplayCopies.strikes));
    memcpy(g_Scores, g_ReplayCopies.scores, sizeof(g_ReplayCopies.scores));
    memcpy(&g_Ball, &g_ReplayCopies.ball, sizeof(g_ReplayCopies.ball));
    memcpy(&g_Pitcher, &g_ReplayCopies.pitcher, sizeof(g_ReplayCopies.pitcher));
    memcpy(&g_Batter, &g_ReplayCopies.batter, sizeof(g_ReplayCopies.batter));
    memcpy(&g_AiLogic, &g_ReplayCopies.aiLogic, sizeof(g_ReplayCopies.aiLogic));
    memcpy(&g_FieldingLogic, &g_ReplayCopies.fieldingLogic, sizeof(g_ReplayCopies.fieldingLogic));
    memcpy(g_RunningLogic, g_ReplayCopies.runningLogic, sizeof(g_ReplayCopies.runningLogic));
    memcpy(g_Fielders, g_ReplayCopies.fielders, sizeof(g_ReplayCopies.fielders));
    memcpy(g_Runners, g_ReplayCopies.runners, sizeof(g_ReplayCopies.runners));
    memcpy(lbl_803537E4, g_ReplayCopies._4128, sizeof(g_ReplayCopies._4128));
    memcpy(lbl_803535C8, g_ReplayCopies._43D4, sizeof(g_ReplayCopies._43D4));
    memcpy(lbl_3_common_bss_32234, g_ReplayCopies._3D88, sizeof(g_ReplayCopies._3D88));
    memcpy(lbl_3_common_bss_32230, g_ReplayCopies._3D8E, sizeof(g_ReplayCopies._3D8E));
    memcpy(lbl_3_common_bss_32220, g_ReplayCopies._3D92, sizeof(g_ReplayCopies._3D92));
    memcpy(g_UnkThrowing_31ACC, g_ReplayCopies._3DA0, sizeof(g_ReplayCopies._3DA0));
    memcpy(g_UnkAnimation_31EAC, g_ReplayCopies._3DB4, sizeof(g_ReplayCopies._3DB4));
    memcpy(lbl_3_common_bss_321A0, g_ReplayCopies._40A8, sizeof(g_ReplayCopies._40A8));
    // _3C is loaded twice, once from a fresh g_Stats address and once through stats
    if (g_Stats._3C != 2 && stats->_3C != 13) {
        fn_3_FBD70();
        if (arg0) {
            fn_3_FBD58();
            fn_3_1CBCC();
        }
    }
    fn_80052798(1);
    lbl_3_common_bss_34C58._2A = 1;
    lbl_3_common_bss_34C58._24 = 1;
    fn_3_8C07C();
    lbl_3_common_bss_34C58._33 = 2;
    fn_3_675B8(0);
    fn_3_BF1AC();
    fn_3_BF158();
    fn_3_B902C();
    if (lbl_3_bss_1748[0] != 0) {
        sndFXKeyOff(lbl_3_bss_1748[0]);
    }
}
