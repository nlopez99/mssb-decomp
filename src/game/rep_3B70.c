#include "game/rep_3B70.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/mtx.h"

typedef struct UnkQuad3B70 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*draw)(struct UnkQuad3B70* quad);
    /* 0x08 */ Mtx mtx;
    /* 0x38 */ f32 proj[7];
    /* 0x54 */ Vec verts[4];
    /* 0x84 */ u8* count;
} UnkQuad3B70; // size: 0x88

typedef struct {
    /* 0x0 */ s32 size;
    /* 0x4 */ u32 alpha;
} UnkQuadParams3B70;

typedef struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ Mtx _40;
} UnkCamera3B70;

extern struct {
    /* 0x000 */ u8 _000[0x440];
    /* 0x440 */ Vec _440;
} lbl_3_common_bss_35154;

extern u8 lbl_803CBBC0;

// This unit's .data (0x271A8 to 0x273E0) lies outside its ranges in splits.txt.
// The target reaches it from one pool base, so these must become statics:
// lbl_3_data_271A8 is u8[2] counts followed by the quads at 0x271AC.
extern struct {
    /* 0x000 */ u8 counts[2];
    /* 0x004 */ UnkQuad3B70 quads[2][2];
} lbl_3_data_271A8;
extern UnkQuadParams3B70 lbl_3_data_273CC;
extern UnkQuadParams3B70 lbl_3_data_273D4;

extern UnkCamera3B70* fn_80052734(s32);
extern void fn_80024390(UnkCamera3B70* camera, f32* proj, s32);
extern void fn_800340F4(Mtx m);
extern void fn_800A7D4C(s32, void*);

// .text:0x0015C3F8 size:0x1FC mapped:0x8079B48C
// Matches with the .data above defined here as statics; as externs each object gets
// its own lis/addi instead of the target's single pool base.
void fn_3_15C3F8(void) {
    Mtx m;
    UnkQuad3B70* quad;
    u8* count;
    f32 half;
    s32 state;
    s32 i;

    count = &lbl_3_data_271A8.counts[lbl_803CBBC0];
    quad = &lbl_3_data_271A8.quads[(*count)++][lbl_803CBBC0];
    quad->count = count;
    fn_80024390(fn_80052734(0), quad->proj, 0);
    PSMTXTrans(quad->mtx, lbl_3_common_bss_35154._440.x, lbl_3_common_bss_35154._440.y, lbl_3_common_bss_35154._440.z);
    PSMTXConcat(fn_80052734(0)->_40, quad->mtx, quad->mtx);

    if (g_GameLogic.bOD_framesInLiveBallScene >= 0) {
        state = 2;
    } else {
        state = g_Ball.framesSinceHit > 0;
    }
    if (state == 2) {
        half = scaleValue(lbl_3_data_273D4.size / 100000.0f, 0.5f);
    } else {
        half = scaleValue(lbl_3_data_273CC.size / 100000.0f, 0.5f);
    }

    fn_800340F4(m);
    quad->verts[0].x = quad->verts[0].y = quad->verts[1].y = quad->verts[3].x = -half;
    quad->verts[2].x = quad->verts[2].y = quad->verts[3].y = quad->verts[1].x = half;
    quad->verts[0].z = quad->verts[1].z = quad->verts[2].z = quad->verts[3].z = 0.0f;
    for (i = 0; i < 4; i++) {
        PSMTXMultVec(m, &quad->verts[i], &quad->verts[i]);
    }
    fn_800A7D4C(11, quad);
}
