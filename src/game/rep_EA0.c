#include "game/rep_EA0.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/OS/OSCache.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"
#include "game/rep_3F60.h"
#include "game/rep_D0.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0xD];
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E[0x20 - 0xE];
} UnkTexEA0; // size: 0x20

typedef struct UnkTexFileEA0 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ UnkTexEA0 _04[1];
} UnkTexFileEA0;

typedef struct {
    /* 0x00 */ u32 _00; // texture index, a UnkTexEA0* once fn_3_6750C relocates it
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ s32 _0C;
} UnkTrailEA0; // size: 0x10

typedef struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ u32 _04;
    /* 0x08 */ Vec* _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ u32* _10;
} UnkMeshEA0; // size: 0x14

typedef struct {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*_04)(void*);
    /* 0x08 */ UnkMeshEA0* _08[2];
} UnkDrawEA0; // size: 0x10

typedef struct UnkRingEA0 {
    /* 0x00 */ Vec* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
} UnkRingEA0; // size: 0x1C

typedef struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec rot;
    /* 0x1C */ u8 _1C[0x26 - 0x1C];
    /* 0x26 */ u8 visible;
    /* 0x27 */ u8 _27;
} UnkMarkerEA0; // size: 0x28

extern struct {
    /* 0x0000 */ u8 _0000[0x2D90];
    /* 0x2D90 */ UnkMarkerEA0* _2D90;
    /* 0x2D94 */ UnkMarkerEA0* _2D94;
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0xCB];
    /* 0xCB */ u8 _CB;
    /* 0xCC */ u8 _CC;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ UnkTexFileEA0* _004;
    /* 0x008 */ u8 _008[0x47A - 0x8];
    /* 0x47A */ u16 _47A[2];
} lbl_3_common_bss_35154;

extern struct {
    /* 0x00 */ u8 _00[0x4C];
    /* 0x4C */ Vec _4C;
} lbl_3_common_bss_350E4;

extern struct {
    /* 0x000 */ u8 _000[0x1D2];
    /* 0x1D2 */ u8 _1D2;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

typedef struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ Vec* _14;
    /* 0x18 */ Vec _18;
} UnkTaskEA0;

extern void* lbl_803CC1B8;

extern u8 lbl_803CBBC0;
extern f32 lbl_803CB740[2];
extern u8 lbl_800E8558[][6];
extern f32 lbl_800E84B0[13][3];

extern struct {
    /* 0x000 */ u8 _000[0x17A];
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x268 - 0x17C];
} g_Fielders[9];

// These objects lie outside the unit's ranges in splits.txt (.data 0x6820 to 0x69C0 is this unit's)
extern u8 lbl_3_data_6820[16];
extern f32 lbl_3_data_6830[2];
extern f32 lbl_3_data_6838[2];
extern f32 lbl_3_data_6840[2];
extern f32 lbl_3_data_6848[2];
extern u16 lbl_3_data_6860[8][2];
extern UnkTrailEA0 lbl_3_data_6880[12];
extern u8 lbl_3_data_6940[0x36];
extern u8 lbl_3_data_6980[0x20];
extern UnkDrawEA0 lbl_3_data_69A0[2];

extern void SetDisplayStateTexture(void*, s32, s32);
extern void fn_8001D0D0(s32, f32);
extern void fn_8001D148(s32, f32, f32, f32);
extern s32 fn_80023D4C(UnkRingEA0*, Vec*);
extern s32 fn_80023D98(UnkRingEA0*, Vec*);
extern s32 fn_80023DFC(UnkRingEA0*, Vec*);
extern void fn_80023E48(UnkRingEA0*, Vec*);
extern void fn_80023EEC(UnkRingEA0*, Vec*, s32);
typedef struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ Mtx _40;
} UnkCameraEA0;

extern UnkCameraEA0* fn_80052734(s32);
extern void fn_80052694(s32);
extern void fn_800A7D4C(s32, void*);
extern void fn_800B0A14_removeQueue(void);
extern UnkTaskEA0* fn_800B0A5C_insertQueue(void (*)(void), s32);

// MWCC lays out these statics in reverse order of declaration
static u8 lbl_3_bss_16AC[0x7C]; // unreferenced
static f32 lbl_3_bss_16A8;
static f32 lbl_3_bss_16A4;
static s32 lbl_3_bss_16A0;
static s32 lbl_3_bss_169C;
static UnkMeshEA0 lbl_3_bss_164C[2][2];
static UnkRingEA0 lbl_3_bss_1630;
static Vec lbl_3_bss_1360[60];
static u8 lbl_3_bss_11E0[0x180] ATTRIBUTE_ALIGN(32);
static u8 lbl_3_bss_1060[0x180] ATTRIBUTE_ALIGN(32);
static Vec lbl_3_bss_520[2][120] ATTRIBUTE_ALIGN(32);
static u32 lbl_3_bss_320[2][64] ATTRIBUTE_ALIGN(32);
static Vec lbl_3_bss_260[2][8] ATTRIBUTE_ALIGN(32);
static u32 lbl_3_bss_220[2][8] ATTRIBUTE_ALIGN(32);
static s32 lbl_3_bss_20C;
static s32 lbl_3_bss_208;
static UnkTexEA0* lbl_3_bss_204;
static u32 lbl_3_bss_200; // unreferenced, but it holds offset 0 of the pool

// .text:0x000697CC size:0x994 mapped:0x806A8860
void fn_3_697CC(void) {
    UnkMarkerEA0* marker;
    UnkMarkerEA0* extra;
    s32 extraIdx;
    s32 scaleIdx;
    s32 state;
    s32 held;
    s32 garlic;
    s32 i;
    Vec offset;
    f32 scale;

    extra = NULL;
    lbl_8036E548._2D90[0].visible = 0;
    lbl_8036E548._2D90[7].visible = 0;
    lbl_8036E548._2D90[8].visible = 0;
    lbl_8036E548._2D90[9].visible = 0;
    lbl_8036E548._2D90[10].visible = 0;
    lbl_8036E548._2D90[11].visible = 0;
    lbl_8036E548._2D90[12].visible = 0;
    lbl_8036E548._2D90[13].visible = 0;
    lbl_8036E548._2D90[14].visible = 0;
    lbl_8036E548._2D90[15].visible = 0;
    lbl_8036E548._2D90[16].visible = 0;
    lbl_8036E548._2D90[1].visible = 0;
    lbl_8036E548._2D90[2].visible = 0;
    lbl_8036E548._2D90[3].visible = 0;
    lbl_3_common_bss_32724._CB = 0;
    if (g_GameLogic.secondaryGameMode == 6 || g_GameLogic.secondaryGameMode == 7 ||
        g_GameLogic.secondaryGameMode == 8) {
        return;
    }
    if (g_Minigame.GameMode_MiniGame == 3 && g_Minigame.barrelBatter_scoreCalculatedInd) {
        return;
    }
    if (g_GameLogic.secondaryGameMode == 0xE) {
        return;
    }
    if ((g_GameLogic.gameStatus == 1 && g_Pitcher.starPitchType == 3) ||
        (!g_Ball.warioWaluGarlicIsActive && g_GameLogic.gameStatus == 2 && g_Ball.currentStarSwing == 3)) {
        lbl_3_common_bss_32724._CB = 3;
    }
    if ((g_GameLogic.gameStatus == 1 && g_Pitcher.starPitchType == 4) ||
        (!g_Ball.warioWaluGarlicIsActive && g_GameLogic.gameStatus == 2 && g_Ball.currentStarSwing == 4)) {
        lbl_3_common_bss_32724._CB = 4;
    }
    if ((g_GameLogic.gameStatus == 1 && g_Pitcher.starPitchType == 5) ||
        (g_GameLogic.gameStatus == 2 && g_Ball.currentStarSwing == 5)) {
        lbl_3_common_bss_32724._CB = 5;
    }
    if ((g_GameLogic.gameStatus == 1 && g_Pitcher.starPitchType == 6) ||
        (g_GameLogic.gameStatus == 2 && g_Ball.currentStarSwing == 6)) {
        lbl_3_common_bss_32724._CB = 6;
    }
    if ((g_GameLogic.gameStatus == 1 && g_Pitcher.starPitchType == 7) ||
        (g_GameLogic.gameStatus == 2 && g_Ball.currentStarSwing == 7)) {
        lbl_3_common_bss_32724._CB = 7;
    }
    if ((g_GameLogic.gameStatus == 1 && g_Pitcher.starPitchType == 8) ||
        (g_GameLogic.gameStatus == 2 && g_Ball.currentStarSwing == 8)) {
        lbl_3_common_bss_32724._CB = 8;
    }
    if ((g_GameLogic.gameStatus == 1 && g_Pitcher.starPitchType == 9) ||
        (g_GameLogic.gameStatus == 2 && g_Ball.currentStarSwing == 9)) {
        lbl_3_common_bss_32724._CB = 9;
    }
    if ((g_GameLogic.gameStatus == 1 && g_Pitcher.starPitchType == 10) ||
        (g_GameLogic.gameStatus == 2 && g_Ball.currentStarSwing == 10)) {
        lbl_3_common_bss_32724._CB = 10;
    }
    marker = &lbl_8036E548._2D90[lbl_3_data_6820[lbl_3_common_bss_32724._CB]];
    if (g_Minigame.GameMode_MiniGame == 1) {
        if (g_Minigame.bOD_KingBombInd) {
            marker = &lbl_8036E548._2D94[1];
        } else {
            marker = &lbl_8036E548._2D94[0];
        }
        lbl_8036E548._2D94[0].visible = 0;
        lbl_8036E548._2D94[1].visible = 0;
    }
    fn_3_68BB4();
    marker->pos.x = g_Ball.AtBat_Contact_BallPos.x;
    marker->pos.y = -g_Ball.AtBat_Contact_BallPos.y;
    marker->pos.z = g_Ball.AtBat_Contact_BallPos.z;
    marker->rot.x = shortAngleToRad_Capped(g_Ball.matchFramesAndBallAngle.ballSpinAngle.yaw);
    marker->rot.y = shortAngleToRad_Capped(g_Ball.matchFramesAndBallAngle.ballSpinAngle.pitch);
    marker->rot.z = shortAngleToRad_Capped(g_Ball.matchFramesAndBallAngle.ballSpinAngle.roll);
    if (g_Ball.warioWaluGarlicIsActive) {
        garlic = g_Ball.currentStarSwing != 3;
        if (g_Ball.framesUntilBallHitsGround > lbl_3_common_bss_35154._47A[garlic ? 1 : 0]) {
            extraIdx = 14;
        } else {
            extraIdx = garlic + 15;
        }
        extra = &lbl_8036E548._2D90[extraIdx];
        extra->pos.x = g_Ball.warioStarHitCoords[2].x;
        extra->pos.y = -g_Ball.warioStarHitCoords[2].y;
        extra->pos.z = g_Ball.warioStarHitCoords[2].z;
        extra->visible = 1;
        extra->rot.x = marker->rot.x;
        extra->rot.y = marker->rot.y;
        extra->rot.z = marker->rot.z;
    } else if (g_Pitcher.warioWaluStarAnimationStage == 1 && (g_Pitcher.pitchTotalTimeCounter & 1)) {
        marker->pos.x = g_Pitcher.ballCurrentPosition.x + g_Pitcher.pitchX_parabolicAdjustment -
                        g_Pitcher.starPitchPositionAdjustment.x;
    }
    if (g_Ball.fielderActionOccuring) {
        marker->pos.x = g_Ball.fielderActionCatchCoords.x;
        marker->pos.y = -g_Ball.fielderActionCatchCoords.y;
        marker->pos.z = g_Ball.fielderActionCatchCoords.z;
    }
    if (g_Ball.hitNoteBlockInd) {
        marker->pos.x = lbl_3_common_bss_350E4._4C.x;
        marker->pos.y = lbl_3_common_bss_350E4._4C.y;
        marker->pos.z = lbl_3_common_bss_350E4._4C.z;
    }
    held = 0;
    if (g_Ball.ballState != 1) {
        held = 1;
    } else if (g_Ball.fielderWBallIndex >= 0 &&
               lbl_800E8558[g_Fielders[g_Ball.fielderWBallIndex]._17A][1] == 0x21) {
        held = 2;
        offset.x = g_Ball.offsetWhilePickedUpHistory[1].x;
        offset.y = g_Ball.offsetWhilePickedUpHistory[1].y;
        offset.z = g_Ball.offsetWhilePickedUpHistory[1].z;
        for (i = 2; i < 4; i++) {
            offset.x += g_Ball.offsetWhilePickedUpHistory[i].x;
            offset.y += g_Ball.offsetWhilePickedUpHistory[i].y;
            offset.z += g_Ball.offsetWhilePickedUpHistory[i].z;
        }
        offset.x /= 3.0f;
        offset.y /= 3.0f;
        offset.z /= 3.0f;
        marker->pos.x = g_Ball.AtBat_Contact_BallPos.x + offset.x;
        marker->pos.y = g_Ball.AtBat_Contact_BallPos.y + offset.y;
        marker->pos.z = g_Ball.AtBat_Contact_BallPos.z + offset.z;
        marker->pos.y = -marker->pos.y;
    }
    if ((g_GameLogic.gameStatus == 1 && g_Ball.pitchHangtimeCounter >= 0) ||
        (g_GameLogic.gameStatus == 2 && held)) {
        if (!((g_Pitcher.pitcherActionState == 4 && g_Pitcher.currentStateFrameCounter >= 1 &&
               !g_FieldingLogic._107) ||
              (g_Pitcher.pitcherActionState == 4 && !g_FieldingLogic._107 &&
               g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) ||
              ((g_Pitcher.pitcherActionState == 5 || g_Pitcher.pitcherActionState == 6) &&
               g_Pitcher.currentStateFrameCounter >= 1 && !g_FieldingLogic._107) ||
              g_Ball.collisionRelated >= 2 || g_Batter.hitByPitch || g_Pitcher.peachDaisyStarAnimationOn ||
              g_Batter.invisibleBallForPeachStarHit ||
              (g_d_GameSettings.StadiumID == 3 && g_Ball.pauseBallMovementWhenInPlant) ||
              ((g_Pitcher.pitcherActionState == 4 || g_Pitcher.pitcherActionState == 5 ||
                g_Pitcher.pitcherActionState == 6) &&
               g_Minigame.GameMode_MiniGame == 1))) {
            marker->visible = 1;
        }
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            if (g_Minigame.TF_ballDespawnedInd) {
                marker->visible = 0;
            } else if (g_Minigame.TF_framesSinceHittingPanel > 0 && g_Minigame.TF_framesSinceHittingPanel % 3 == 0) {
                marker->visible = 0;
            }
        }
        if (g_Minigame.GameMode_MiniGame == 1 && g_Minigame.bODRelated3) {
            marker->visible = 0;
            fn_3_675B8(0);
        }
    }
    state = 0;
    if (g_GameLogic.sceneID == 2) {
        state = 1;
    }
    if (g_Stats.replayInd) {
        state = 2;
    }
    if (g_Minigame.GameMode_MiniGame == 1) {
        fn_8001D0D0(0, lbl_3_data_6838[g_Minigame.bOD_KingBombInd]);
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        scale = lbl_803CB740[state];
        fn_8001D148(lbl_3_data_6820[lbl_3_common_bss_32724._CB], scale, scale, scale);
    } else {
        scale = lbl_800E84B0[lbl_3_common_bss_32724._CB][state];
        fn_8001D148(lbl_3_data_6820[lbl_3_common_bss_32724._CB], scale, scale, scale);
    }
    if (extra != NULL) {
        switch (extraIdx) {
        case 14:
            scaleIdx = 0;
            break;
        case 15:
            scaleIdx = 3;
            break;
        case 16:
            scaleIdx = 4;
            break;
        }
        scale = lbl_800E84B0[scaleIdx][state];
        fn_8001D148(extraIdx, scale, scale, scale);
        extra->visible = marker->visible;
    }
    fn_3_695F8(marker->visible);
    fn_3_692E0();
    fn_3_69184();
    fn_3_67A48();
}

// .text:0x000695F8 size:0x1D4 mapped:0x806A868C
void fn_3_695F8(BOOL show) {
    UnkMarkerEA0* marker;
    s32 code;

    marker = &lbl_8036E548._2D90[1];
    marker->visible = 0;
    marker->pos.x = g_Ball.AtBat_Contact_BallPos.x;
    marker->pos.y = -g_Ball.physicsSubstruct.twoFrameLookback[1] - 0.04f;
    marker->pos.z = g_Ball.AtBat_Contact_BallPos.z;
    if (g_Ball.warioWaluGarlicIsActive) {
        if (g_Ball.framesSinceHit & 1) {
            marker->pos.x = g_Ball.warioStarHitCoords[2].x;
            marker->pos.z = g_Ball.warioStarHitCoords[2].z;
        }
    } else if (g_Pitcher.warioWaluStarAnimationStage == 1 && (g_Pitcher.pitchTotalTimeCounter & 1)) {
        marker->pos.x = g_Pitcher.ballCurrentPosition.x + g_Pitcher.pitchX_parabolicAdjustment -
                        g_Pitcher.starPitchPositionAdjustment.x;
    }
    if (g_Ball.fielderActionOccuring) {
        marker->pos.x = g_Ball.fielderActionCatchCoords.x;
        marker->pos.y = -g_Ball.fielderActionCatchCoords.y;
        marker->pos.z = g_Ball.fielderActionCatchCoords.z;
    }
    if (g_Ball.hitNoteBlockInd) {
        marker->pos.x = lbl_3_common_bss_350E4._4C.x;
        marker->pos.z = lbl_3_common_bss_350E4._4C.z;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        fn_8001D148(1, lbl_3_data_6830[1], 1.0f, lbl_3_data_6830[1]);
    } else {
        fn_8001D148(1, lbl_3_data_6830[0], 1.0f, lbl_3_data_6830[0]);
    }
    if (show) {
        code = g_Ball.collisionCode & 0x7F;
        if (code == 1 || code == 6 || code == 9 || code == 10 || (code >= 0x70 && code < 0x79)) {
            marker->visible = 1;
        }
    }
}

// .text:0x000692E0 size:0x318 mapped:0x806A8374
void fn_3_692E0(void) {
    VecSrcDst line;
    CollisionStruct col;
    UnkMarkerEA0* marker;
    s32 idx;
    u32 code;
    f32 height;
    f32 rot;
    f32 scale;

    lbl_8036E548._2D90[2].visible = 0;
    lbl_8036E548._2D90[3].visible = 0;
    if (g_Stats.replayInd || g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD || g_Minigame.GameMode_MiniGame ||
        g_Ball.pauseBallMovementWhenInPlant || g_Ball.frameCountdownAfterLeavingPlant) {
        return;
    }
    if (g_Ball.deadBallReason ||
        (g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE &&
         !gameInitOptions.controlOptions[g_GameLogic.teams[g_GameLogic.teamFielding]].dropSpot) ||
        g_GameLogic.sceneID != 2 || g_FieldingLogic._107 || g_Ball.AtBat_ContactResult || g_Ball.maxYOfHit < 2.0f ||
        g_Ball.currentStarSwing2 == 0xB || g_Ball.currentStarSwing2 == 0xC) {
        return;
    }
    if (g_Ball.warioWaluGarlicIsActive) {
        return;
    }
    if (g_FieldingLogic._144) {
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE &&
            (g_Practice.practiceType_2 == 1 || g_Practice.practiceLevel == 4)) {
            idx = 2;
        } else {
            idx = 3;
        }
    } else {
        idx = 2;
    }
    marker = &lbl_8036E548._2D90[idx];
    marker->visible = 1;
    line.src.x = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
    line.src.y = -1.0f;
    line.src.z = g_Ball.physicsSubstruct.hitLandingSpotDistFromHome;
    line.dst.x = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
    line.dst.y = 1.0f;
    line.dst.z = g_Ball.physicsSubstruct.hitLandingSpotDistFromHome;
    code = checkCollision(&line, &col, 0, FALSE);
    if (code == 1 || code == 6 || code == 9 || code == 10 || code == 0x32) {
        marker->pos.y = col.position.y - 0.06f;
    } else {
        marker->pos.y = -0.06f;
    }
    marker->pos.x = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
    marker->pos.z = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z;
    rot = marker->rot.y;
    height = 30.0f - g_Ball.AtBat_Contact_BallPos.y;
    if (height < 1.0f) {
        height = 1.0f;
    }
    height *= 0.003f;
    marker->rot.y = fn_3_9FEA8(rot + height);
    scale = LinearInterpolateToNewRange(g_Ball.framesUntilBallHitsGround, 0.0f, 120.0f, lbl_3_data_6840[0],
                                        lbl_3_data_6840[1]);
    fn_8001D148(idx, scale, scale, scale);
}

// .text:0x00069184 size:0x15C mapped:0x806A8218
void fn_3_69184(void) {
    UnkMarkerEA0* marker;

    if (g_Batter.trimmedBat == 1) {
        marker = &lbl_8036E548._2D90[6];
    } else {
        marker = &lbl_8036E548._2D90[5];
    }
    marker->visible = 0;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        if (g_GameLogic.secondaryGameMode == 0xA) {
            return;
        }
        if (g_Practice.practiceLevel != 4 && g_Practice.practiceType_2 != 1) {
            return;
        }
    } else if (g_Batter.easyBatting == 0) {
        return;
    }
    if (g_Stats.replayInd != 0) {
        return;
    }
    if (g_GameLogic.gameStatus != 0 && g_GameLogic.gameStatus != 1) {
        return;
    }
    if (g_GameLogic.sceneID != 1) {
        return;
    }
    marker->visible = 1;
    if (g_Batter.batterHand != 0) {
        marker->pos.x = -g_Batter.batPosition2.x;
        marker->rot.y = 3.1415927f;
    } else {
        marker->pos.x = g_Batter.batPosition2.x;
        marker->rot.y = 0.0f;
    }
    marker->pos.z = g_Batter.batPosition2.z + lbl_3_data_6848[1];
    marker->pos.y = lbl_3_data_6848[0];
}

// .text:0x0006916C size:0x18 mapped:0x806A8200
void fn_3_6916C(void) {
    lbl_3_common_bss_32724._CB = 0;
    lbl_3_common_bss_32724._CC = 0;
}

// .text:0x000690FC size:0x70 mapped:0x806A8190
void fn_3_690FC(void) {
    lbl_8036E548._2D90[0].visible = 0;
    lbl_8036E548._2D90[1].visible = 0;
    lbl_8036E548._2D90[2].visible = 0;
    lbl_8036E548._2D90[3].visible = 0;
    lbl_8036E548._2D90[5].visible = 0;
    lbl_8036E548._2D90[6].visible = 0;
    lbl_8036E548._2D90[7].visible = 0;
    lbl_8036E548._2D90[8].visible = 0;
    lbl_8036E548._2D90[9].visible = 0;
    lbl_8036E548._2D90[10].visible = 0;
    lbl_8036E548._2D90[12].visible = 0;
    lbl_8036E548._2D90[13].visible = 0;
}

// .text:0x00068BB4 size:0x548 mapped:0x806A7C48
#define SPIN g_Ball.matchFramesAndBallAngle.ballSpinAngle
void fn_3_68BB4(void) {
    if (lbl_80366158._28 && lbl_3_common_bss_32724._CB != 7 && lbl_3_common_bss_32724._CB != 8) {
        return;
    }
    if (g_GameLogic.gameStatus == 1) {
        if (g_Minigame.GameMode_MiniGame == 1) {
            if (g_Pitcher.pitcherActionState == 3) {
                SPIN.yaw += 50;
            } else {
                SPIN.yaw = 0;
            }
            SPIN.pitch = 0;
            SPIN.roll = 0;
        } else if (lbl_3_common_bss_32724._CB == 9 || lbl_3_common_bss_32724._CB == 10) {
            SPIN.yaw += 300;
            SPIN.pitch += 100;
            SPIN.roll = 0;
        } else if (lbl_3_common_bss_32724._CB == 7 || lbl_3_common_bss_32724._CB == 8) {
            if (g_Pitcher.bulletPitchStageCode == 1) {
                SPIN.yaw = radToShortAngle(3.1415927f + (6.2831855f - g_Pitcher.bulletPitchLoopAngleRadians));
            } else {
                SPIN.yaw = 0;
            }
            SPIN.pitch = 0;
            SPIN.roll = 0;
        } else if (lbl_3_common_bss_32724._CB == 5 || lbl_3_common_bss_32724._CB == 6) {
            SPIN.yaw = 0;
            SPIN.roll = 0;
            if (g_Pitcher.handedness) {
                SPIN.pitch += 200;
            } else {
                SPIN.pitch -= 200;
            }
        } else if (lbl_3_common_bss_32724._CB == 11 || lbl_3_common_bss_32724._CB == 12) {
            SPIN.yaw = 0;
            SPIN.pitch = 0;
            SPIN.roll = 0;
        } else {
            SPIN.yaw -= 600;
            SPIN.pitch = 0;
            SPIN.roll = 0;
        }
    } else if (g_GameLogic.gameStatus == 2) {
        if (g_Minigame.GameMode_MiniGame == 1) {
            if (g_Ball.AtBat_ContactResult == 0) {
                SPIN.yaw += (s32)(400.0f * g_Ball.ballVelocity);
            } else {
                SPIN.yaw -= (s32)(400.0f * g_Ball.ballVelocity);
            }
            SPIN.pitch = 0;
            SPIN.roll = 0;
        } else if (g_Ball.fielderWBallIndex >= 0) {
            SPIN.yaw = SPIN.pitch = SPIN.roll = 0;
        } else if (lbl_3_common_bss_32724._CB == 9 || lbl_3_common_bss_32724._CB == 10) {
            SPIN.pitch = -(g_Ball.ballTravelAngle - 0x400);
            SPIN.roll = 0;
            SPIN.yaw += (s32)(200.0f * g_Ball.ballVelocity);
        } else if (lbl_3_common_bss_32724._CB == 7 || lbl_3_common_bss_32724._CB == 8) {
            SPIN.pitch = fn_3_9FE6C_normalizeAngle(0xC00 - g_Ball.Hit_HorizontalAngle);
            SPIN.yaw = 0;
            SPIN.roll = 0;
        } else if (lbl_3_common_bss_32724._CB == 5 || lbl_3_common_bss_32724._CB == 6) {
            SPIN.yaw = 0;
            SPIN.roll = 0;
            if (g_Batter.batterHand) {
                SPIN.pitch -= 200;
            } else {
                SPIN.pitch += 200;
            }
        } else if (lbl_3_common_bss_32724._CB == 11 || lbl_3_common_bss_32724._CB == 12) {
            SPIN.yaw = 0;
            SPIN.pitch = 0;
            SPIN.roll = 0;
        } else {
            SPIN.roll = 0;
            SPIN.pitch = 0x800 - g_Ball.ballTravelAngle;
            if (g_Ball.AtBat_ContactResult == 0) {
                SPIN.yaw += (s32)(400.0f * g_Ball.ballVelocity);
            } else if (g_Ball.ballState == 2 && !g_Ball.thrownBallHasHitGround) {
                SPIN.yaw += (s32)(800.0f * g_Ball.ballVelocity);
            } else {
                SPIN.yaw -= (s32)(400.0f * g_Ball.ballVelocity);
            }
        }
    } else {
        SPIN.yaw = SPIN.pitch = SPIN.roll = 0;
    }
    SPIN.yaw = fn_3_9FE6C_normalizeAngle(SPIN.yaw);
    SPIN.pitch = fn_3_9FE6C_normalizeAngle(SPIN.pitch);
    SPIN.roll = fn_3_9FE6C_normalizeAngle(SPIN.roll);
}
#undef SPIN

// .text:0x000685F0 size:0x5C4 mapped:0x806A7684
void fn_3_685F0(void) {
    if (g_Minigame.GameMode_MiniGame == 4 || g_Minigame.GameMode_MiniGame == 5 || g_Minigame.GameMode_MiniGame == 6) {
        return;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        if (g_GameLogic.secondaryGameMode == 0xA) {
            fn_3_675B8(0);
            return;
        }
        if (g_Practice.tutorialState == 2) {
            fn_3_675B8(0);
            return;
        }
        if (g_Practice._19F && (lbl_3_common_bss_34C90._1D2 == 7 || lbl_3_common_bss_34C90._1D2 == 9 ||
                                lbl_3_common_bss_34C90._1D2 == 11)) {
            fn_3_675B8(0);
            return;
        }
    }
    if (g_Ball.pitchHangtimeCounter == 1) {
        if (g_Pitcher.starPitchType != 0) {
            if (g_Pitcher.starPitchType == 5 || g_Pitcher.starPitchType == 6) {
                fn_3_67620(5, 45);
            } else if (g_Pitcher.starPitchType == 9 || g_Pitcher.starPitchType == 10) {
                fn_3_67620(6, 120);
            } else {
                fn_3_675B8(0);
            }
        } else if (g_Pitcher.starPitchType == 0 && g_Pitcher.ballHaloTrainInd_unused) {
            fn_3_67620(10, 45);
        } else if (g_Pitcher.ChargePitchType == 3) {
            fn_3_67620(2, 45);
        } else if (g_Pitcher.ChargePitchType != 0) {
            fn_3_67620(1, 45);
        } else {
            fn_3_67620(1, 45);
        }
    } else if (g_Ball.pitchHangtimeCounter >= 1 && g_Ball.framesSinceHit <= 0) {
        if (lbl_3_common_bss_32724._CC && g_Pitcher.pitcherActionState == 4) {
            fn_3_675B8(0);
        }
    } else if (g_Ball.framesSinceHit == 1) {
        fn_3_675B8(0);
    } else if (g_Ball.framesSinceHit == 2) {
        if (g_Minigame.GameMode_MiniGame == 1) {
            if (g_Ball.bODQualifyingHitInd) {
                fn_3_67620(3, 180);
            } else {
                fn_3_675B8(0);
            }
        } else if (g_Ball.currentStarSwing != 0) {
            if (g_Ball.currentStarSwing == 5 || g_Ball.currentStarSwing == 6) {
                fn_3_67620(5, 90);
            } else if (g_Ball.currentStarSwing == 9 || g_Ball.currentStarSwing == 10) {
                fn_3_67620(7, 180);
            } else {
                fn_3_675B8(0);
            }
        } else if (!g_Batter.captainStarSwingActivated && g_Batter.didNonCaptainStarSwingConnect) {
            fn_3_67620(11, 90);
        } else if (g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy) {
            fn_3_67620(4, 90);
        } else {
            fn_3_67620(3, 90);
        }
    } else if (g_Ball.framesSinceHit > 0) {
        if (lbl_3_common_bss_32724._CC) {
            if (g_GameLogic.gameStatus != 2) {
                fn_3_675B8(0);
            }
            if (g_Minigame.GameMode_MiniGame == 3) {
                if (g_Minigame.barrelBatter_scoreCalculatedInd) {
                    fn_3_675B8(0);
                }
            } else if (g_Ball.timeSinceBallPickedUp == 0) {
                fn_3_675B8(0);
            } else if (g_Ball.numFieldersWhoHandledBallDuringPlay == 1 && g_Ball.numberOfThrowsDuringPlay == 0) {
                fn_3_675B8(0);
            } else if (g_Ball.ballVelocity == 0.0f) {
                fn_3_675B8(0);
            }
        }
        if (g_Ball.framesSinceThrowStarted == 1) {
            if (g_FieldingLogic._13E) {
                fn_3_168FA0(g_Ball.fielderBeingThrownTo, FALSE);
                fn_3_168FA0(g_Ball.throwingFielder, FALSE);
                fn_3_67620(8, 90);
            } else if (g_Ball.IsAntichemistryThrow) {
                fn_3_168FA0(g_Ball.fielderBeingThrownTo, TRUE);
                fn_3_168FA0(g_Ball.throwingFielder, TRUE);
                fn_3_67620(9, 90);
            } else if (g_FieldingLogic._140) {
                fn_3_67620(2, 90);
            } else if (g_FieldingLogic._13D || g_FieldingLogic.throwSpeedType == 1) {
                fn_3_67620(1, 90);
            }
        }
    }
}

// .text:0x00067EF0 size:0x700 mapped:0x806A6F84
s32 fn_3_67EF0(UnkRingEA0* ring, s32 count, Vec* pos, u32* colors, u32 color, Vec* pos2, u32* colors2, Vec* dir,
               f32 width) {
    Mtx m;
    Vec pts[4];
    Vec dir2[2];
    s32 idx;
    s32 k;
    s32 i;
    s32 side;
    f32 angle;
    u8 alpha = color & 0xFF;
    u8 first;
    s32 fade;

    colors[0] = color;
    PSMTXCopy(fn_80052734(0)->_40, m);
    idx = 1;
    k = 0;
    fn_80023DFC(ring, &pts[0]);
    PSMTXMultVec(m, &pts[0], &pts[0]);
    while (fn_80023D98(ring, &pts[idx])) {
        PSMTXMultVec(m, &pts[idx], &pts[idx]);
        if (pts[idx].z == pts[!idx].z) {
            memcpy(&pts[2], &pts[!idx], sizeof(Vec));
            memcpy(&pts[3], &pts[idx], sizeof(Vec));
        } else if (pts[!idx].z != 0.0f) {
            pts[2].x = pts[!idx].x * pts[idx].z / pts[!idx].z;
            pts[2].y = pts[!idx].y * pts[idx].z / pts[!idx].z;
            pts[2].z = pts[!idx].z;
            memcpy(&pts[3], &pts[idx], sizeof(Vec));
        } else {
            memcpy(&pts[2], &pts[!idx], sizeof(Vec));
            pts[3].x = pts[idx].x * pts[!idx].z / pts[idx].z;
            pts[3].y = pts[idx].y * pts[!idx].z / pts[idx].z;
            pts[3].z = pts[idx].z;
        }
        PSVECSubtract(&pts[2], &pts[3], &dir2[0]);
        dir2[0].z = 0.0f;
        if (PSVECMag(&dir2[0])) {
            PSVECNormalize(&dir2[0], &dir2[1]);
            memcpy(&pos[k * 2], &pts[!idx], sizeof(Vec));
            PSVECScale(&dir2[1], width, &pos[k * 2 + 1]);
            idx ^= 1;
            k++;
        }
    }
    memcpy(&pos[k * 2], &pts[!idx], sizeof(Vec));
    memcpy(&pos[k * 2 + 1], &pts[!idx], sizeof(Vec));
    colors[k] = 0xFFFFFF00;
    k = k * alpha / 255;
    PSVECNormalize(&pos[1], &dir2[0]);
    PSVECSubtract(&pos[0], &pos[2], &pts[0]);
    if (PSVECMag(&pts[0])) {
        PSVECNormalize(&pts[0], &pts[0]);
    }
    angle = acos(PSVECDotProduct(&pts[0], &dir2[0]));
    dir2[0].z = -dir2[0].y;
    dir2[0].y = dir2[0].x;
    dir2[0].x = dir2[0].z;
    dir2[0].z = 0.0f;
    color &= 0xFFFFFF00;
    for (i = 0; i < k; i++) {
        memcpy(&pts[0], &pos[i * 2], sizeof(Vec));
        if (dir != NULL) {
            PSVECScale(dir, width * (k - i) / k, &dir2[1]);
        } else {
            PSVECScale(&pos[i * 2 + 1], (f32)(k - i) / k, &dir2[1]);
            dir2[1].z = -dir2[1].y;
            dir2[1].y = dir2[1].x;
            dir2[1].x = dir2[1].z;
            dir2[1].z = 0.0f;
        }
        PSVECAdd(&pts[0], &dir2[1], &pos[i * 2]);
        PSVECSubtract(&pts[0], &dir2[1], &pos[i * 2 + 1]);
        colors[i] = color | (u8)(alpha * (k - i) / k);
    }
    if (pos[0].z >= pos[(k - 1) * 2].z) {
        side = -1;
    } else {
        side = 1;
    }
    PSMTXRotAxisRad(m, &dir2[0], angle * -side);
    for (i = 0; i < 2; i++) {
        if (dir != NULL) {
            PSVECScale(dir, width, &dir2[0]);
            pts[2].x = dir2[0].x;
            dir2[0].x = -dir2[0].y;
            dir2[0].y = pts[2].x;
        } else {
            PSVECSubtract(&pos[i], &pos[i + 2], &dir2[0]);
            if (PSVECMag(&dir2[0])) {
                PSVECNormalize(&dir2[0], &dir2[0]);
            } else {
                dir2[0].y = 0.0f;
                dir2[0].z = 0.0f;
                dir2[0].x = 1.0f;
            }
            PSVECScale(&dir2[0], width, &dir2[0]);
        }
        PSMTXMultVec(m, &dir2[0], &dir2[0]);
        PSVECAdd(&pos[i], &dir2[0], &pos2[i]);
        memcpy(&pos2[i + 2], &pos[i], sizeof(Vec));
        PSVECSubtract(&pos[i], &dir2[0], &pos2[i + 4]);
    }
    colors2[0] = colors[0];
    colors2[1] = colors[0];
    colors2[2] = colors[0];
    if (angle > 1.5707964f) {
        angle = 3.1415927f - angle;
    }
    angle /= 1.5707964f;
    first = colors[0];
    colors2[1] &= 0xFFFFFF00;
    colors2[2] &= 0xFFFFFF00;
    fade = first * angle;
    colors[0] &= 0xFFFFFF00;
    colors2[1] |= (u8)fade;
    colors2[2] |= (u8)fade;
    colors[0] |= (u8)(first - fade);
    memset(&pos[k * 2], 0, (count - k) * (2 * sizeof(Vec)));
    memset(&colors[k], 0, (count - k) * sizeof(u32));
    DCStoreRangeNoSync(pos, count * 2 * sizeof(Vec));
    DCStoreRangeNoSync(colors, count * sizeof(u32));
    DCStoreRangeNoSync(pos2, 6 * sizeof(Vec));
    DCStoreRangeNoSync(colors2, 6 * sizeof(u32));
    return side;
}

// .text:0x00067C34 size:0x2BC mapped:0x806A6CC8
void fn_3_67C34(void* arg) {
    UnkDrawEA0* draw = arg;
    Mtx m = {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
    };
    int i;

    fn_80052694(0);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
    GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
    GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 14);
    GXSetCullMode(GX_CULL_NONE);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetColorUpdate(GX_TRUE);
    GXSetNumChans(1);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEXCOORD0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumIndStages(0);
    GXSetTevDirect(GX_TEVSTAGE0);
    if (lbl_3_bss_204 != NULL) {
        lbl_3_bss_204->_0D = 0;
        SetDisplayStateTexture(lbl_3_bss_204, 0, 0);
    }
    if (lbl_3_bss_204 != NULL) {
        GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
    } else {
        GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    }
    GXSetZCompLoc(GX_FALSE);
    GXInvalidateVtxCache();
    for (i = 0; i < 2; i++) {
        GXSetArray(GX_VA_POS, draw->_08[i]->_08, sizeof(Vec));
        GXSetArray(GX_VA_CLR0, draw->_08[i]->_10, sizeof(u32));
        GXSetArray(GX_VA_TEX0, draw->_08[i]->_0C, 4);
        GXCallDisplayList(draw->_08[i]->_00, draw->_08[i]->_04);
    }
}

// .text:0x00067A48 size:0x1EC mapped:0x806A6ADC
void fn_3_67A48(void) {
    Vec pos;
    Vec last;
    BOOL add;
    UnkTaskEA0* task;

    if (lbl_3_bss_16A8 > 0.0f) {
        if (lbl_80366158._28 == 0) {
            add = TRUE;
            if (g_Ball.fielderActionOccuring) {
                pos.x = g_Ball.fielderActionCatchCoords.x;
                pos.y = -g_Ball.fielderActionCatchCoords.y;
                pos.z = g_Ball.fielderActionCatchCoords.z;
            } else {
                pos.x = g_Ball.AtBat_Contact_BallPos.x;
                pos.y = -g_Ball.AtBat_Contact_BallPos.y;
                pos.z = g_Ball.AtBat_Contact_BallPos.z;
            }
            if (lbl_3_bss_1630._08 != 0) {
                fn_80023D4C(&lbl_3_bss_1630, &last);
                if (memcmp(&pos, &last, sizeof(Vec)) == 0) {
                    add = FALSE;
                }
            }
            if (add) {
                fn_80023E48(&lbl_3_bss_1630, &pos);
            }
        }
        if (lbl_3_bss_1630._08 >= 2) {
            task = fn_800B0A5C_insertQueue(fn_3_678B8, 1000);
            if (lbl_3_bss_16A0 == 6 || lbl_3_bss_16A0 == 7) {
                task->_14 = &task->_18;
                task->_18.x = 1.0f;
                task->_18.y = 0.0f;
                task->_18.z = 0.0f;
            } else {
                task->_14 = NULL;
            }
            fn_800A7D4C(0, &lbl_3_data_69A0[lbl_803CBBC0]);
            if (lbl_80366158._28 == 0) {
                if (lbl_3_bss_20C != 0) {
                    lbl_3_bss_20C -= lbl_3_bss_20C > 0;
                } else if (--lbl_3_bss_208 != 0) {
                    lbl_3_bss_16A8 -= lbl_3_bss_16A4;
                } else {
                    lbl_3_bss_16A8 = 0.0f;
                }
            }
        }
    }
}

// .text:0x000678B8 size:0x190 mapped:0x806A694C
void fn_3_678B8(void) {
    UnkTaskEA0* task = lbl_803CC1B8;
    s32 side;

    side = fn_3_67EF0(&lbl_3_bss_1630, 60, lbl_3_bss_520[lbl_803CBBC0], lbl_3_bss_320[lbl_803CBBC0],
                     (u32)lbl_3_bss_16A8 | 0xFFFFFF00, lbl_3_bss_260[lbl_803CBBC0], lbl_3_bss_220[lbl_803CBBC0],
                     task->_14, lbl_3_data_6880[lbl_3_bss_16A0]._04);
    side = (side + 1) >> 1;
    lbl_3_bss_164C[lbl_803CBBC0][0]._08 = lbl_3_bss_520[lbl_803CBBC0];
    lbl_3_bss_164C[lbl_803CBBC0][0]._0C = lbl_3_data_6860;
    lbl_3_bss_164C[lbl_803CBBC0][0]._10 = lbl_3_bss_320[lbl_803CBBC0];
    lbl_3_bss_164C[lbl_803CBBC0][1]._08 = lbl_3_bss_260[lbl_803CBBC0];
    lbl_3_bss_164C[lbl_803CBBC0][1]._0C = lbl_3_data_6860;
    lbl_3_bss_164C[lbl_803CBBC0][1]._10 = lbl_3_bss_220[lbl_803CBBC0];
    lbl_3_bss_164C[lbl_803CBBC0][1]._04 = sizeof(lbl_3_data_6980);
    lbl_3_bss_164C[lbl_803CBBC0][1]._00 = lbl_3_data_6980;
    if (side) {
        lbl_3_bss_164C[lbl_803CBBC0][0]._04 = sizeof(lbl_3_bss_1060);
        lbl_3_data_69A0[lbl_803CBBC0]._08[0] = &lbl_3_bss_164C[lbl_803CBBC0][1];
        lbl_3_bss_164C[lbl_803CBBC0][0]._00 = lbl_3_bss_1060;
        lbl_3_data_69A0[lbl_803CBBC0]._08[1] = &lbl_3_bss_164C[lbl_803CBBC0][0];
    } else {
        lbl_3_bss_164C[lbl_803CBBC0][0]._04 = sizeof(lbl_3_bss_11E0);
        lbl_3_data_69A0[lbl_803CBBC0]._08[0] = &lbl_3_bss_164C[lbl_803CBBC0][0];
        lbl_3_bss_164C[lbl_803CBBC0][0]._00 = lbl_3_bss_11E0;
        lbl_3_data_69A0[lbl_803CBBC0]._08[1] = &lbl_3_bss_164C[lbl_803CBBC0][1];
    }
    fn_800B0A14_removeQueue();
}

// .text:0x00067620 size:0x298 mapped:0x806A66B4
void fn_3_67620(s32 type, u16 frames) {
    u8* p;
    u8* start;
    u8* src;
    u8* dst;
    int i;

    lbl_3_bss_16A0 = type;
    if (type == 10) {
        lbl_3_data_6880[type]._00 =
            (u32)&lbl_3_common_bss_35154._004->_04[lbl_3_data_6940[g_Pitcher.charID] + 33];
    } else if (type == 11) {
        lbl_3_data_6880[type]._00 =
            (u32)&lbl_3_common_bss_35154._004->_04[lbl_3_data_6940[g_Batter.charID] + 33];
    }
    lbl_3_bss_16A8 = 255.0f;
    if (frames == 0) {
        lbl_3_bss_20C = -1;
        lbl_3_bss_16A4 = 0.0f;
    } else if (lbl_3_data_6880[type]._00 != 0) {
        lbl_3_bss_20C = frames - 8;
        lbl_3_bss_208 = 8;
        lbl_3_bss_16A4 = 255.0f / 8;
    } else {
        lbl_3_bss_20C = 0;
        lbl_3_bss_208 = frames;
        lbl_3_bss_16A4 = lbl_3_bss_16A8 / lbl_3_bss_208;
    }
    lbl_3_bss_204 = (UnkTexEA0*)lbl_3_data_6880[type]._00;
    fn_80023EEC(&lbl_3_bss_1630, lbl_3_bss_1360, lbl_3_data_6880[type]._0C);

    p = lbl_3_bss_11E0;
    i = 1;
    p[0] = GX_TRIANGLESTRIP | GX_VTXFMT0;
    start = p;
    p[1] = 0;
    p[2] = 120;
    p[3] = 0;
    p[4] = 0;
    p[5] = 2;
    p[6] = 1;
    p[7] = 0;
    p[8] = 3;
    p += 9;
    do {
        p[0] = i * 2;
        p[1] = i;
        p[2] = 6 - (i & 1) * 2;
        p[3] = i * 2 + 1;
        p[4] = i;
        p[5] = 7 - (i & 1) * 2;
        p += 6;
    } while (++i < 60);
    DCStoreRangeNoSync(start, p - start);

    src = lbl_3_bss_11E0;
    memcpy(lbl_3_bss_1060, src, 3);
    dst = lbl_3_bss_1060;
    src += 3;
    dst += 3 + 120 * 3;
    i = 120;
    while (i--) {
        dst -= 3;
        memcpy(dst, src, 3);
        src += 3;
    }
    DCStoreRangeNoSync(lbl_3_bss_1060, 3 + 120 * 3);
    lbl_3_common_bss_32724._CC = 1;
}

// .text:0x000675B8 size:0x68 mapped:0x806A664C
void fn_3_675B8(u16 frames) {
    if (frames == 0) {
        lbl_3_common_bss_32724._CC = 0;
        lbl_3_bss_16A8 = 0.0f;
        return;
    }
    lbl_3_bss_20C = frames;
    lbl_3_bss_16A4 = lbl_3_bss_16A8 / frames;
}

// .text:0x0006750C size:0xAC mapped:0x806A65A0
void fn_3_6750C(UnkTexFileEA0* file) {
    int i;

    for (i = 1; i < 12; i++) {
        lbl_3_data_6880[i]._00 = (u32)&file->_04[lbl_3_data_6880[i]._00];
        if (lbl_3_data_6880[i]._08 == 0.0f) {
            lbl_3_data_6880[i]._08 = 1.0f;
        } else {
            lbl_3_data_6880[i]._08 = lbl_3_data_6880[i]._08 / lbl_3_data_6880[i]._04;
        }
        lbl_3_data_6880[i]._0C = lbl_3_data_6880[i]._0C * 60 / 100;
        if (lbl_3_data_6880[i]._0C < 2) {
            lbl_3_data_6880[i]._0C = 2;
        }
    }
    lbl_3_bss_169C = 0;
}
