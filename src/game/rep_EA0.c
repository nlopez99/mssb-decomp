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

typedef struct {
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

extern UnkTaskEA0* lbl_803CC1B8;

extern u8 lbl_803CBBC0;
extern f32 lbl_803CB740[2];
extern u8 lbl_800E8558[][6];

// These objects lie outside the unit's ranges in splits.txt (.data 0x6820 to 0x69C0 is this unit's)
extern u8 lbl_3_data_6820[16];
extern f32 lbl_3_data_6830[2];
extern f32 lbl_3_data_6838[2];
extern f32 lbl_3_data_6840[2];
extern f32 lbl_3_data_6848[2];
extern UnkTrailEA0 lbl_3_data_6880[12];
extern u8 lbl_3_data_6940[0x36];
extern UnkDrawEA0 lbl_3_data_69A0[2];

extern void SetDisplayStateTexture(void*, s32, s32);
extern void fn_8001D0D0(s32, f32);
extern void fn_8001D148(s32, f32, f32, f32);
extern s32 fn_80023D4C(UnkRingEA0*, Vec*);
extern s32 fn_80023D98(UnkRingEA0*, Vec*);
extern s32 fn_80023DFC(UnkRingEA0*, Vec*);
extern void fn_80023E48(UnkRingEA0*, Vec*);
extern void fn_80023EEC(UnkRingEA0*, Vec*, s32);
extern void* fn_80052734(s32);
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
    return;
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
void fn_3_68BB4(void) {
    return;
}

// .text:0x000685F0 size:0x5C4 mapped:0x806A7684
void fn_3_685F0(void) {
    return;
}

// .text:0x00067EF0 size:0x700 mapped:0x806A6F84
void fn_3_67EF0(void) {
    return;
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
    return;
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
    i = 119;
    do {
        dst -= 3;
        memcpy(dst, src, 3);
        src += 3;
    } while (i--);
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
