#include "game/rep_4138.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/GX/GXFifo.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

extern struct {
    /* 0x0000 */ u8 _0000[0x3088];
    /* 0x3088 */ u8 _3088;
} lbl_8036E548;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04;
    /* 0x06 */ u8 _06[0x2A - 0x06];
    /* 0x2A */ s16 _2A;
} g_Scores;

extern u8 lbl_803CBBC0;

extern f32 lbl_3_data_2A448[4][3];
extern f32 lbl_3_data_2A478[4][2];
extern struct {
    u32 _00;
    void (*_04)(void);
} lbl_3_data_2A498[2];

extern void fn_80033B58(void*, s32, s32, s32);
extern s32 fn_8005268C(void);
extern void fn_800A7D4C(s32, void*);
extern void fn_800B0A14_removeQueue(void);
extern void fn_800B0A5C_insertQueue(void (*)(void), s32);

// MWCC lays out these statics in reverse order of declaration
static s32 lbl_3_bss_D6F0[6];
static u8 lbl_3_bss_D6EC;
static s32 lbl_3_bss_D6E8;
static u16* lbl_3_bss_D6E4;
static u8 lbl_3_bss_D6E0; // unused here, but it holds offset 0 of the pool

// .text:0x0016D810 size:0x1A0 mapped:0x807AC8A4
void fn_3_16D810(s32 digit, f32 x, f32 y) {
    GXColor color = { 0xFF, 0xFF, 0xFF, 0xFF };
    f32 u = 50.0f * digit / 512.0f;
    s32 i;

    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (i = 0; i < 4; i++) {
        GXPosition3f32(x + lbl_3_data_2A448[i][0], y + lbl_3_data_2A448[i][1], lbl_3_data_2A448[i][2]);
        GXColor1u32(*(u32*)&color);
        GXTexCoord2f32(u + lbl_3_data_2A478[i][0], lbl_3_data_2A478[i][1]);
    }
    GXEnd();
}

// .text:0x0016D9B0 size:0x1BC mapped:0x807ACA44
void fn_3_16D9B0(void) {
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetCullMode(GX_CULL_NONE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_TEXA, GX_CA_RASA, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXLoadPosMtxImm(fn_80052768_getCamera(fn_8005268C())->view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetProjection(fn_80052768_getCamera(fn_8005268C())->proj, GX_PERSPECTIVE);
    fn_80033B58(lbl_3_bss_D6E4, lbl_3_bss_D6E8, 0, 0);
}

// .text:0x0016DB6C size:0x458 mapped:0x807ACC00
void fn_3_16DB6C(u8 idx) {
    f32 x;
    f32 y;
    s32 value;
    s32 tens;

    switch (idx) {
    case 0:
        x = -15.438f;
        y = -12.96f;
        value = lbl_3_bss_D6F0[0];
        break;
    case 1:
        x = -10.878f;
        y = -12.96f;
        value = lbl_3_bss_D6F0[2];
        break;
    case 2:
        x = -6.318f;
        y = -12.96f;
        value = lbl_3_bss_D6F0[1];
        break;
    case 3:
        x = -15.438f;
        y = -9.0f;
        value = lbl_3_bss_D6F0[4];
        break;
    case 4:
        x = -10.878f;
        y = -9.0f;
        value = lbl_3_bss_D6F0[3];
        break;
    case 5:
        x = -6.318f;
        y = -9.0f;
        value = lbl_3_bss_D6F0[5];
        break;
    default:
        return;
    }
    tens = (value % 100) / 10;
    if (tens != 0) {
        fn_3_16D810(tens, x, y);
    }
    x += 1.8f;
    fn_3_16D810(value % 10, x, y);
}

// .text:0x0016DFC4 size:0x1DC mapped:0x807AD058
void fn_3_16DFC4(void) {
    u32 i;

    fn_3_16D9B0();
    for (i = 0; i < 6; i++) {
        fn_3_16DB6C(i);
    }
}

// .text:0x0016E1A0 size:0x4C mapped:0x807AD234
void fn_3_16E1A0(void) {
    lbl_3_bss_D6F0[0] = g_Scores._2A;
    lbl_3_bss_D6F0[1] = g_Scores._04;
    lbl_3_bss_D6F0[2] = g_Scores._00;
    lbl_3_bss_D6F0[3] = g_Strikes.strikes;
    lbl_3_bss_D6F0[4] = g_Strikes.balls;
    lbl_3_bss_D6F0[5] = g_Strikes.outs;
}

// .text:0x0016E1EC size:0x110 mapped:0x807AD280
void fn_3_16E1EC(void) {
    if (lbl_3_bss_D6EC | !lbl_8036E548._3088 | !lbl_3_bss_D6E4) {
        lbl_3_bss_D6E4 = NULL;
        lbl_3_bss_D6E8 = -1;
        lbl_3_bss_D6EC = 0;
        fn_800B0A14_removeQueue();
    }
    if ((g_GameLogic.gameStatus != GAME_STATUS_HOMERUN_END) & (g_GameLogic.gameStatus != GAME_STATUS_HOMERUN_LAP)) {
        fn_3_16E1A0();
    }
    fn_800A7D4C(1, &lbl_3_data_2A498[lbl_803CBBC0]);
}

// .text:0x0016E2FC size:0x2C mapped:0x807AD390
void fn_3_16E2FC(u16* arg0, s32 arg1) {
    if (arg0 == NULL) {
        return;
    }
    if (*arg0 - 1 < arg1) {
        return;
    }
    lbl_3_bss_D6E4 = arg0;
    lbl_3_bss_D6E8 = arg1;
}

// .text:0x0016E328 size:0x10 mapped:0x807AD3BC
void fn_3_16E328(void) {
    lbl_3_bss_D6EC = 1;
}

// .text:0x0016E338 size:0x6C mapped:0x807AD3CC
void fn_3_16E338(u16* arg0, s32 arg1) {
    if (arg0 != NULL && *arg0 - 1 >= arg1) {
        lbl_3_bss_D6E4 = arg0;
        lbl_3_bss_D6E8 = arg1;
        lbl_3_bss_D6EC = 0;
        memset(lbl_3_bss_D6F0, 0, sizeof(lbl_3_bss_D6F0));
        fn_800B0A5C_insertQueue(fn_3_16E1EC, 5);
    }
}
