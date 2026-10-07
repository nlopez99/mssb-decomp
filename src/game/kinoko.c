#include "game/kinoko.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/GX/GXFifo.h"
#include "Dolphin/os.h"
#include "string.h"

extern struct {
    u8 _00[0x28];
    u8 _28;
} lbl_80366158;

extern u8 lbl_803CBBC0;

extern void fn_80011604(s8, void*);
extern s32 fn_8005268C(void);
extern s32 fn_800247E4(s32, s32, s32, s32);
extern BOOL fn_8001B728(s32, s32, Vec*);
extern void fn_800A7D4C(s32, void*);
extern void fn_800B0A14_removeQueue(void);
extern void fn_800B0A5C_insertQueue(void (*)(void), s32);

typedef struct {
    /* 0x0000 */ RibbonEffect ribbons[6][25];
    /* 0x19C8 */ u8 _19C8[0x19D4 - 0x19C8];
    /* 0x19D4 */ s32 _19D4;
    /* 0x19D8 */ u8 _19D8[4];
    /* 0x19DC */ s8 _19DC;
    /* 0x19DD */ u8 _19DD;
} lbl_3_data_28928_s; // size 0x19E0

static lbl_3_data_28928_s lbl_3_data_28928 = { 0 };

static u8 lbl_3_data_2A308[6][4] = {
    { 0xFF, 0x00, 0x00, 0xC8 },
    { 0xFF, 0xFF, 0x00, 0xC8 },
    { 0x00, 0xFF, 0x00, 0xC8 },
    { 0x00, 0xFF, 0xFF, 0xC8 },
    { 0x00, 0x00, 0xFF, 0xC8 },
    { 0xFF, 0x00, 0xFF, 0xC8 },
};

static struct {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*_04)(void);
} lbl_3_data_2A320[2] = {
    { 0, fn_3_169984 },
    { 0, fn_3_169984 },
};

s8 lbl_3_data_2A330 = -1;

typedef struct {
    /* 0x00 */ Vec* pos;
    /* 0x04 */ u8* color;
} RibbonVertex;

typedef struct {
    /* 0x00 */ RibbonVertex v[4];
    /* 0x20 */ Vec center;
    /* 0x2C */ u8 active;
} RibbonQuad; // size 0x30

typedef struct {
    /* 0x00 */ f32 z;
    /* 0x04 */ u32 index;
} RibbonDepth;

// MWCC lays out these statics in reverse order of declaration
static RibbonQuad lbl_3_bss_BAE0[149];
static u8 lbl_3_bss_BAA0[0x40] ATTRIBUTE_ALIGN(32);
static u8 lbl_3_bss_BA60[0x40] ATTRIBUTE_ALIGN(32);
static GXTexObj lbl_3_bss_BA2C;
static GXTexObj lbl_3_bss_BA0C;
static s32 lbl_3_bss_BA08;
static GXTexObj* lbl_3_bss_BA04;
static u8* lbl_3_bss_BA00;

// .text:0x0016C394 size:0x7C mapped:0x807AB428
void fn_3_16C394(s8 arg0) {
    memset(&lbl_3_data_28928, 0, sizeof(lbl_3_data_28928));
    memset(lbl_3_bss_BAE0, 0, sizeof(lbl_3_bss_BAE0));
    lbl_3_data_28928._19DC = arg0;
    lbl_3_data_28928._19DD = 1;
    lbl_3_data_28928._19D4 = 1;
    fn_3_16B884();
    fn_800B0A5C_insertQueue(fn_3_16A07C, 0);
}

// .text:0x0016B884 size:0xB10 mapped:0x807AA918
void fn_3_16B884(void) {
    u32 i;
    u8 alpha;
    int color;

    color = 0;
    lbl_3_data_28928.ribbons[0][0].colorFrom = color++;
    lbl_3_data_28928.ribbons[0][0].colorTo = color;
    fn_3_16B5B4(&lbl_3_data_28928.ribbons[0][0], 28, 0);
    lbl_3_data_28928.ribbons[1][0].colorFrom = color++;
    lbl_3_data_28928.ribbons[1][0].colorTo = color;
    fn_3_16B5B4(&lbl_3_data_28928.ribbons[1][0], 32, 0);
    lbl_3_data_28928.ribbons[2][0].colorFrom = color++;
    lbl_3_data_28928.ribbons[2][0].colorTo = color;
    fn_3_16B5B4(&lbl_3_data_28928.ribbons[2][0], 4, 0);
    lbl_3_data_28928.ribbons[3][0].colorFrom = color++;
    lbl_3_data_28928.ribbons[3][0].colorTo = color;
    fn_3_16B5B4(&lbl_3_data_28928.ribbons[3][0], 7, 0);
    lbl_3_data_28928.ribbons[4][0].colorFrom = color++;
    lbl_3_data_28928.ribbons[4][0].colorTo = color;
    fn_3_16B5B4(&lbl_3_data_28928.ribbons[4][0], 18, 0);
    lbl_3_data_28928.ribbons[5][0].colorFrom = color++;
    lbl_3_data_28928.ribbons[5][0].colorTo = 0;
    fn_3_16B5B4(&lbl_3_data_28928.ribbons[5][0], 24, 0);
    for (i = 1; i < 25; i++) {
        alpha = (24 - i) * 8;
        memcpy(&lbl_3_data_28928.ribbons[0][i], &lbl_3_data_28928.ribbons[0][i - 1], sizeof(RibbonEffect));
        lbl_3_data_28928.ribbons[0][i].color[3] = alpha;
        memcpy(&lbl_3_data_28928.ribbons[1][i], &lbl_3_data_28928.ribbons[1][i - 1], sizeof(RibbonEffect));
        lbl_3_data_28928.ribbons[1][i].color[3] = alpha;
        memcpy(&lbl_3_data_28928.ribbons[2][i], &lbl_3_data_28928.ribbons[2][i - 1], sizeof(RibbonEffect));
        lbl_3_data_28928.ribbons[2][i].color[3] = alpha;
        memcpy(&lbl_3_data_28928.ribbons[3][i], &lbl_3_data_28928.ribbons[3][i - 1], sizeof(RibbonEffect));
        lbl_3_data_28928.ribbons[3][i].color[3] = alpha;
        memcpy(&lbl_3_data_28928.ribbons[4][i], &lbl_3_data_28928.ribbons[4][i - 1], sizeof(RibbonEffect));
        lbl_3_data_28928.ribbons[4][i].color[3] = alpha;
        memcpy(&lbl_3_data_28928.ribbons[5][i], &lbl_3_data_28928.ribbons[5][i - 1], sizeof(RibbonEffect));
        lbl_3_data_28928.ribbons[5][i].color[3] = alpha;
    }
}

// .text:0x0016B5B4 size:0x2D0 mapped:0x807AA648
void fn_3_16B5B4(RibbonEffect* ribbon, s8 id, int frame) {
    f32 t = frame / 5.0f;

    ribbon->color[0] = (1.0 - t) * lbl_3_data_2A308[ribbon->colorFrom][0] + t * lbl_3_data_2A308[ribbon->colorTo][0];
    ribbon->color[1] = (1.0 - t) * lbl_3_data_2A308[ribbon->colorFrom][1] + t * lbl_3_data_2A308[ribbon->colorTo][1];
    ribbon->color[2] = (1.0 - t) * lbl_3_data_2A308[ribbon->colorFrom][2] + t * lbl_3_data_2A308[ribbon->colorTo][2];
    ribbon->color[3] = (1.0 - t) * lbl_3_data_2A308[ribbon->colorFrom][3] + t * lbl_3_data_2A308[ribbon->colorTo][3];
    ribbon->_2A = 1;
    fn_3_16B488(&ribbon->pos, id);
}

// .text:0x0016B488 size:0x12C mapped:0x807AA51C
void fn_3_16B488(Vec* pos, s8 id) {
    if (pos == NULL) {
        OSErrorLine(284, "Ribbon Effect Pos Data None\n");
    }
    memset(pos, 0, sizeof(Vec));
    if (!fn_8001B728(lbl_3_data_28928._19DC, id, pos)) {
        switch (id) {
        case 28:
            fn_8001B728(lbl_3_data_28928._19DC, 30, pos);
            break;
        case 32:
            fn_8001B728(lbl_3_data_28928._19DC, 34, pos);
            break;
        case 7:
            fn_8001B728(lbl_3_data_28928._19DC, 5, pos);
            break;
        case 18:
            fn_8001B728(lbl_3_data_28928._19DC, 19, pos);
            break;
        case 24:
            fn_8001B728(lbl_3_data_28928._19DC, 25, pos);
            break;
        }
    }
}

// .text:0x0016A07C size:0x140C mapped:0x807A9110
// 99.81%: in the trail-shift loop the target gives i, the destination pointer and the
// source pointer r19, r20 and r21; this build gives them r21, r19 and r20.
void fn_3_16A07C(void) {
    u32 count;
    u32 i;
    u8 alpha;

    if (g_d_GameSettings._55 != 0 || g_Minigame._1A40 != 0) {
        fn_800B0A14_removeQueue();
        memset(&lbl_3_data_28928, 0, sizeof(lbl_3_data_28928));
        return;
    }
    if (g_Minigame.playerIDWithPowerup[0] == -1 || !lbl_3_data_28928._19DD) {
        fn_800B0A14_removeQueue();
        memset(&lbl_3_data_28928, 0, sizeof(lbl_3_data_28928));
        return;
    }
    if (lbl_80366158._28 == 0) {
        lbl_3_data_28928._19D4++;
        for (i = 24; i != 0; i--) {
            alpha = (24 - i) * 8;
            memcpy(&lbl_3_data_28928.ribbons[0][i], &lbl_3_data_28928.ribbons[0][i - 1], sizeof(RibbonEffect));
            lbl_3_data_28928.ribbons[0][i].color[3] = alpha;
            memcpy(&lbl_3_data_28928.ribbons[1][i], &lbl_3_data_28928.ribbons[1][i - 1], sizeof(RibbonEffect));
            lbl_3_data_28928.ribbons[1][i].color[3] = alpha;
            memcpy(&lbl_3_data_28928.ribbons[2][i], &lbl_3_data_28928.ribbons[2][i - 1], sizeof(RibbonEffect));
            lbl_3_data_28928.ribbons[2][i].color[3] = alpha;
            memcpy(&lbl_3_data_28928.ribbons[3][i], &lbl_3_data_28928.ribbons[3][i - 1], sizeof(RibbonEffect));
            lbl_3_data_28928.ribbons[3][i].color[3] = alpha;
            memcpy(&lbl_3_data_28928.ribbons[4][i], &lbl_3_data_28928.ribbons[4][i - 1], sizeof(RibbonEffect));
            lbl_3_data_28928.ribbons[4][i].color[3] = alpha;
            memcpy(&lbl_3_data_28928.ribbons[5][i], &lbl_3_data_28928.ribbons[5][i - 1], sizeof(RibbonEffect));
            lbl_3_data_28928.ribbons[5][i].color[3] = alpha;
        }
        if (lbl_3_data_28928._19D4 % 5 == 0) {
            if (++lbl_3_data_28928.ribbons[0][0].colorFrom >= 6) {
                lbl_3_data_28928.ribbons[0][0].colorFrom -= 6;
            }
            if (++lbl_3_data_28928.ribbons[0][0].colorTo >= 6) {
                lbl_3_data_28928.ribbons[0][0].colorTo -= 6;
            }
            if (++lbl_3_data_28928.ribbons[1][0].colorFrom >= 6) {
                lbl_3_data_28928.ribbons[1][0].colorFrom -= 6;
            }
            if (++lbl_3_data_28928.ribbons[1][0].colorTo >= 6) {
                lbl_3_data_28928.ribbons[1][0].colorTo -= 6;
            }
            if (++lbl_3_data_28928.ribbons[2][0].colorFrom >= 6) {
                lbl_3_data_28928.ribbons[2][0].colorFrom -= 6;
            }
            if (++lbl_3_data_28928.ribbons[2][0].colorTo >= 6) {
                lbl_3_data_28928.ribbons[2][0].colorTo -= 6;
            }
            if (++lbl_3_data_28928.ribbons[3][0].colorFrom >= 6) {
                lbl_3_data_28928.ribbons[3][0].colorFrom -= 6;
            }
            if (++lbl_3_data_28928.ribbons[3][0].colorTo >= 6) {
                lbl_3_data_28928.ribbons[3][0].colorTo -= 6;
            }
            if (++lbl_3_data_28928.ribbons[4][0].colorFrom >= 6) {
                lbl_3_data_28928.ribbons[4][0].colorFrom -= 6;
            }
            if (++lbl_3_data_28928.ribbons[4][0].colorTo >= 6) {
                lbl_3_data_28928.ribbons[4][0].colorTo -= 6;
            }
            if (++lbl_3_data_28928.ribbons[5][0].colorFrom >= 6) {
                lbl_3_data_28928.ribbons[5][0].colorFrom -= 6;
            }
            if (++lbl_3_data_28928.ribbons[5][0].colorTo >= 6) {
                lbl_3_data_28928.ribbons[5][0].colorTo -= 6;
            }
        }
        fn_3_16B5B4(&lbl_3_data_28928.ribbons[0][0], 28, lbl_3_data_28928._19D4 % 5);
        fn_3_16B5B4(&lbl_3_data_28928.ribbons[1][0], 32, lbl_3_data_28928._19D4 % 5);
        fn_3_16B5B4(&lbl_3_data_28928.ribbons[2][0], 4, lbl_3_data_28928._19D4 % 5);
        fn_3_16B5B4(&lbl_3_data_28928.ribbons[3][0], 7, lbl_3_data_28928._19D4 % 5);
        fn_3_16B5B4(&lbl_3_data_28928.ribbons[4][0], 18, lbl_3_data_28928._19D4 % 5);
        fn_3_16B5B4(&lbl_3_data_28928.ribbons[5][0], 24, lbl_3_data_28928._19D4 % 5);
    }
    fn_3_169E70(lbl_3_data_28928.ribbons[0]);
    fn_3_169E70(lbl_3_data_28928.ribbons[1]);
    fn_3_169E70(lbl_3_data_28928.ribbons[2]);
    fn_3_169E70(lbl_3_data_28928.ribbons[3]);
    fn_3_169E70(lbl_3_data_28928.ribbons[4]);
    fn_3_169E70(lbl_3_data_28928.ribbons[5]);
    count = 0;
    memset(lbl_3_bss_BAE0, 0, sizeof(lbl_3_bss_BAE0));
    fn_3_169D00(lbl_3_data_28928.ribbons[0], &count);
    fn_3_169D00(lbl_3_data_28928.ribbons[1], &count);
    fn_3_169D00(lbl_3_data_28928.ribbons[2], &count);
    fn_3_169D00(lbl_3_data_28928.ribbons[3], &count);
    fn_3_169D00(lbl_3_data_28928.ribbons[4], &count);
    fn_3_169D00(lbl_3_data_28928.ribbons[5], &count);
    fn_800A7D4C(1, &lbl_3_data_2A320[lbl_803CBBC0]);
}

// .text:0x00169E70 size:0x20C mapped:0x807A8F04
void fn_3_169E70(RibbonEffect* ribbon) {
    Vec dir;
    Vec prevPos;
    Vec nextPos;
    Vec tangent;
    Vec side;
    camera_803c639c_s* camera;
    u32 i;

    camera = fn_80052768_getCamera(0);
    for (i = 0; i < 25; i++) {
        if (ribbon[i]._2A) {
            dir.x = camera->view[2][0];
            dir.y = camera->view[2][1];
            dir.z = camera->view[2][2];
            if (!PSVECMag(&dir)) {
                dir.x = 0.0f;
                dir.y = 0.0f;
                dir.z = 1.0f;
            } else {
                PSVECNormalize(&dir, &dir);
            }
            if (i == 0) {
                memcpy(&prevPos, &ribbon[i].pos, sizeof(Vec));
            } else {
                memcpy(&prevPos, &ribbon[i - 1].pos, sizeof(Vec));
            }
            if (i == 24) {
                memcpy(&nextPos, &ribbon[i].pos, sizeof(Vec));
            } else {
                memcpy(&nextPos, &ribbon[i + 1].pos, sizeof(Vec));
            }
            PSVECSubtract(&prevPos, &nextPos, &tangent);
            if (!PSVECMag(&tangent)) {
                tangent.z = 0.0f;
                tangent.y = 0.0f;
                tangent.x = 1.0f;
            }
            PSVECNormalize(&tangent, &tangent);
            PSVECCrossProduct(&tangent, &dir, &side);
            if (!PSVECMag(&side)) {
                side.z = 0.0f;
                side.y = 0.0f;
                side.x = -1.0f;
            }
            PSVECNormalize(&side, &side);
            PSVECScale(&side, -0.15f, &ribbon[i]._0C);
            PSVECScale(&side, 0.15f, &ribbon[i]._18);
            PSVECAdd(&ribbon[i]._0C, &ribbon[i].pos, &ribbon[i]._0C);
            PSVECAdd(&ribbon[i]._18, &ribbon[i].pos, &ribbon[i]._18);
        }
    }
}

// .text:0x00169D00 size:0x170 mapped:0x807A8D94
void fn_3_169D00(RibbonEffect* ribbon, u32* count) {
    RibbonEffect* prev;
    u32 i;

    for (i = 24; i != 0 && *count < 149; i--) {
        if (ribbon[i]._2A) {
            prev = &ribbon[i - 1];
            PSVECAdd(&ribbon[i].pos, &prev->pos, &lbl_3_bss_BAE0[*count].center);
            PSVECScale(&lbl_3_bss_BAE0[*count].center, 0.5f, &lbl_3_bss_BAE0[*count].center);
            lbl_3_bss_BAE0[*count].v[0].pos = &prev->_0C;
            lbl_3_bss_BAE0[*count].v[0].color = prev->color;
            lbl_3_bss_BAE0[*count].v[1].pos = &prev->_18;
            lbl_3_bss_BAE0[*count].v[1].color = prev->color;
            lbl_3_bss_BAE0[*count].v[2].pos = &ribbon[i]._18;
            lbl_3_bss_BAE0[*count].v[2].color = ribbon[i].color;
            lbl_3_bss_BAE0[*count].v[3].pos = &ribbon[i]._0C;
            lbl_3_bss_BAE0[*count].v[3].color = ribbon[i].color;
            lbl_3_bss_BAE0[*count].active = 1;
            (*count)++;
        }
    }
}

// .text:0x00169984 size:0x37C mapped:0x807A8A18
void fn_3_169984(void) {
    RibbonDepth depths[149];
    Mtx view;
    Vec center;
    RibbonDepth tmp;
    u32 front;
    u32 back;
    u32 i;
    u32 j;
    RibbonQuad* quad;
    int k;

    PSMTXCopy(fn_80052768_getCamera(fn_8005268C())->view, view);
    front = 0;
    back = 148;
    for (i = 0; i < 149; i++) {
        if (!lbl_3_bss_BAE0[i].active) {
            depths[back].index = i;
            depths[back].z = -1.0f;
            back--;
        } else {
            PSMTXMultVec(view, &lbl_3_bss_BAE0[i].center, &center);
            depths[front].z = center.z;
            depths[front].index = i;
            front++;
        }
    }
    for (j = 0; j < 148; j++) {
        for (i = j + 1; i < 149; i++) {
            if (depths[j].z > depths[i].z) {
                memcpy(&tmp, &depths[j], sizeof(RibbonDepth));
                memcpy(&depths[j], &depths[i], sizeof(RibbonDepth));
                memcpy(&depths[i], &tmp, sizeof(RibbonDepth));
            }
        }
    }
    fn_3_169804();
    for (i = 0; i < 149; i++) {
        quad = &lbl_3_bss_BAE0[depths[i].index];
        if (quad->active) {
            GXBegin(GX_QUADS, GX_VTXFMT0, 4);
            for (k = 0; k < 4; k++) {
                GXPosition3f32(quad->v[k].pos->x, quad->v[k].pos->y, quad->v[k].pos->z);
                GXColor1u32(*(u32*)quad->v[k].color);
            }
            GXEnd();
        }
    }
}

// .text:0x00169804 size:0x180 mapped:0x807A8898
void fn_3_169804(void) {
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
    GXSetCullMode(GX_CULL_BACK);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_RASC);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXLoadPosMtxImm(fn_80052768_getCamera(fn_8005268C())->view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetProjection(fn_80052768_getCamera(fn_8005268C())->proj, GX_PERSPECTIVE);
}

// .text:0x00169600 size:0x204 mapped:0x807A8694
void fn_3_169600(void) {
    u32 y;
    u32 x;
    u32 offset;

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            offset = fn_800247E4(x, y, 4, 4);
            if (offset < 32) {
                lbl_3_bss_BAA0[offset + 0] = lbl_3_bss_BAA0[offset + 2] = 255;
                lbl_3_bss_BAA0[offset + 1] = lbl_3_bss_BAA0[offset + 3] = 155;
            } else {
                lbl_3_bss_BAA0[offset + 0] = lbl_3_bss_BAA0[offset + 2] = 0;
                lbl_3_bss_BAA0[offset + 1] = lbl_3_bss_BAA0[offset + 3] = 255;
            }
        }
    }
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            offset = fn_800247E4(x, y, 4, 4);
            if (offset < 32) {
                lbl_3_bss_BA60[offset + 0] = lbl_3_bss_BA60[offset + 2] = 255;
                lbl_3_bss_BA60[offset + 1] = lbl_3_bss_BA60[offset + 3] = 0;
            } else {
                lbl_3_bss_BA60[offset + 0] = lbl_3_bss_BA60[offset + 2] = 155;
                lbl_3_bss_BA60[offset + 1] = lbl_3_bss_BA60[offset + 3] = 255;
            }
        }
    }
    GXInitTexObj(&lbl_3_bss_BA2C, lbl_3_bss_BAA0, 4, 4, GX_TF_RGBA8, GX_REPEAT, GX_REPEAT, GX_FALSE);
    GXInitTexObjLOD(&lbl_3_bss_BA2C, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXInitTexObj(&lbl_3_bss_BA0C, lbl_3_bss_BA60, 4, 4, GX_TF_RGBA8, GX_REPEAT, GX_REPEAT, GX_FALSE);
    GXInitTexObjLOD(&lbl_3_bss_BA0C, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    lbl_3_data_2A330 = -1;
    lbl_3_bss_BA08 = 0;
}

// .text:0x001695A4 size:0x5C mapped:0x807A8638
void fn_3_1695A4(s8 arg0, u8 arg1) {
    if (!arg1) {
        lbl_3_bss_BA00 = lbl_3_bss_BAA0;
        lbl_3_bss_BA04 = &lbl_3_bss_BA2C;
    } else {
        lbl_3_bss_BA00 = lbl_3_bss_BA60;
        lbl_3_bss_BA04 = &lbl_3_bss_BA0C;
    }
    fn_80011604(arg0, fn_3_16917C);
}

// .text:0x001695A0 size:0x4 mapped:0x807A8634
void fn_3_1695A0(void) {}

// .text:0x0016943C size:0x164 mapped:0x807A84D0
void fn_3_16943C(void) {
    int value;
    int i;

    lbl_3_bss_BA08 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_BA08 & 1) == 0) {
        value = lbl_3_bss_BA00[fn_800247E4(0, 0, 4, 4)];
        value += lbl_3_data_2A330 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            lbl_3_bss_BA00[i] = value;
        }
        DCFlushRange(lbl_3_bss_BA00, 4);
        if (value + lbl_3_data_2A330 * 2 > 255 || value + lbl_3_data_2A330 * 2 < 0) {
            lbl_3_data_2A330 *= -1;
        }
    }
}

// .text:0x0016917C size:0x2C0 mapped:0x807A8210
void fn_3_16917C(void* arg0, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* arg4, u8* arg5) {
    int value;
    int i;

    lbl_3_bss_BA08 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_BA08 & 1) == 0) {
        value = lbl_3_bss_BA00[fn_800247E4(0, 0, 4, 4)];
        value += lbl_3_data_2A330 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            lbl_3_bss_BA00[i] = value;
        }
        DCFlushRange(lbl_3_bss_BA00, 4);
        if (value + lbl_3_data_2A330 * 2 > 255 || value + lbl_3_data_2A330 * 2 < 0) {
            lbl_3_data_2A330 *= -1;
        }
    }
    GXLoadTexObj(lbl_3_bss_BA04, *map);
    GXSetTexCoordGen2(*coord, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTevOrder(*stage, *coord, *map, GX_COLOR_NULL);
    if (lbl_3_bss_BA00 == lbl_3_bss_BAA0) {
        GXSetTevColorIn(*stage, GX_CC_CPREV, GX_CC_TEXC, GX_CC_TEXA, GX_CC_ZERO);
        GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    } else {
        GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_TEXA, GX_CC_CPREV);
        GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    }
    (*stage)++;
    (*coord)++;
    (*map)++;
    (*arg4)++;
    (*arg5)++;
}
