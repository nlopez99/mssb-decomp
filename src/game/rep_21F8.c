#include "game/rep_21F8.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "game/rep_1E08.h"

typedef struct UnkKey21F8 {
    /* 0x0 */ f32 _0;
    /* 0x4 */ f32 _4;
    /* 0x8 */ u16 _8;
    /* 0xA */ u8 _A;
    /* 0xB */ u8 _B;
} UnkKey21F8; // size: 0xC

typedef struct UnkAnim21F8 {
    /* 0x00 */ f32 _00[4];
    /* 0x10 */ u16 _10;
    /* 0x12 */ u16 _12;
    /* 0x14 */ UnkKey21F8* keys[8];
    /* 0x34 */ u8 counts[8];
    /* 0x3C */ u8 current[8];
} UnkAnim21F8; // size: 0x44

typedef struct UnkEffect21F8 {
    /* 0x00 */ UnkAnim21F8* anims;
    /* 0x04 */ void** _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 time;
} UnkEffect21F8; // size: 0x18

UnkKey21F8 lbl_3_data_17898[2] = {
    { 1.0f, 0.5f, 0x1000, 1, 1 },
    { 2.0f, 0.0f, 0xE, 0, 0 },
};
UnkKey21F8 lbl_3_data_178B0[3] = {
    { 1.0f, 1.0f, 0x1000, 1, 1 },
    { 2.0f, 1.8f, 0x1002, 0, 1 },
    { 0.2f, 0.0f, 0xE, 0, 0 },
};
UnkKey21F8 lbl_3_data_178D4[2] = {
    { 1.0f, 0.5f, 0x1000, 1, 1 },
    { 2.0f, 0.0f, 0x10, 0, 0 },
};
UnkKey21F8 lbl_3_data_178EC[3] = {
    { 1.0f, 1.0f, 0x1000, 1, 1 },
    { 2.0f, 1.8f, 0x1002, 0, 1 },
    { 0.2f, 0.0f, 0x10, 0, 0 },
};
UnkKey21F8 lbl_3_data_17910[2] = {
    { 0.0f, 2.0f, 0x1000, 0, 1 },
    { -2.0f, 0.0f, 0xA, 0, 0 },
};
UnkKey21F8 lbl_3_data_17928[2] = {
    { 0.0f, 2.0f, 0x1000, 0, 1 },
    { -2.0f, 0.0f, 0xC, 0, 0 },
};
UnkKey21F8 lbl_3_data_17940[16] = {
    { 0.31415927f, 0.0f, 0, 0, 0 }, { 1.8849558f, 0.0f, 0, 0, 0 }, { 3.4557521f, 0.0f, 0, 0, 0 },
    { 5.0265484f, 0.0f, 0, 0, 0 },  { 1.2566371f, 0.0f, 0, 0, 0 }, { 2.8274336f, 0.0f, 0, 0, 0 },
    { 4.3982296f, 0.0f, 0, 0, 0 },  { 5.969026f, 0.0f, 0, 0, 0 },  { 0.9424779f, 0.0f, 0, 0, 0 },
    { 2.5132742f, 0.0f, 0, 0, 0 },  { 4.0840707f, 0.0f, 0, 0, 0 }, { 5.654867f, 0.0f, 0, 0, 0 },
    { 1.5707964f, 0.0f, 0, 0, 0 },  { 3.1415927f, 0.0f, 0, 0, 0 }, { 4.712389f, 0.0f, 0, 0, 0 },
    { 6.2831855f, 0.0f, 0, 0, 0 },
};
UnkKey21F8 lbl_3_data_17A00[4] = {
    { 0.62831855f, 0.0f, 0, 0, 0 },
    { 0.5654867f, 0.0f, 0, 0, 0 },
    { -0.5654867f, 0.0f, 0, 0, 0 },
    { -0.62831855f, 0.0f, 0, 0, 0 },
};
UnkKey21F8 lbl_3_data_17A30[3] = {
    { 1.0f, 0.0f, 0, 0, 0 },
    { 1.0f, 1.0f, 0x100A, 0, 1 },
    { 0.0f, 0.0f, 0xE, 0, 0 },
};
UnkKey21F8 lbl_3_data_17A54[3] = {
    { 1.0f, 0.0f, 0, 0, 0 },
    { 1.0f, 1.0f, 0x100C, 0, 1 },
    { 0.0f, 0.0f, 0x10, 0, 0 },
};
UnkKey21F8 lbl_3_data_17A78[2] = {
    { 1.0f, 0.2f, 0x1000, 0, 1 },
    { 0.4f, 0.0f, 0x10, 0, 0 },
};
UnkKey21F8 lbl_3_data_17A90[2] = {
    { 3.0f, 2.0f, 0x1000, 0, 1 },
    { 5.0f, 0.0f, 0x10, 0, 0 },
};
UnkKey21F8 lbl_3_data_17AA8[2] = {
    { 1.0f, 1.0f, 0x1000, 0, 1 },
    { 0.0f, 0.0f, 0x10, 0, 0 },
};
UnkAnim21F8 lbl_3_data_17AC0 = {
    { -1.0f, -0.5f, 1.0f, 1.0f },
    0,
    0,
    { lbl_3_data_17898, lbl_3_data_178B0, lbl_3_data_17910, NULL, NULL, lbl_3_data_17A00, lbl_3_data_17940,
      lbl_3_data_17A54 },
    { 2, 3, 2, 0, 0, 1, 1, 3 },
    { 0 },
};
static UnkEffect21F8 lbl_3_data_17B04[4] = {
    { &lbl_3_data_17AC0, NULL, 0x11, 1, 16.0f, 0.0f },
    { &lbl_3_data_17AC0, NULL, 0x11, 1, 16.0f, 0.0f },
    { &lbl_3_data_17AC0, NULL, 0x12, 1, 16.0f, 0.0f },
    { &lbl_3_data_17AC0, NULL, 0x12, 1, 16.0f, 0.0f },
};
s32 lbl_3_data_17B64[7] = { 0, 0, 0, 0, 0, 0, 0xFF };
static u8 lbl_3_data_17B80 = 1;
static f32 lbl_3_data_17B84[4] = { 4.0f, 2.0f, 1.0f, 0.9f };

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ void* _004[1];
} lbl_3_common_bss_35154;

extern void fn_80034120(Mtx m);

static u8 lbl_3_bss_9F34;
static f32 lbl_3_bss_9F30;
static Vec lbl_3_bss_9F24;
static u8 lbl_3_bss_9F20;

// .text:0x000C9734 size:0x10 mapped:0x807087C8
void fn_3_C9734(void) {
    lbl_3_bss_9F34 = 2;
}

// .text:0x000C9590 size:0x1A4 mapped:0x80708624
f32 fn_3_C9590(UnkAnim21F8* anim, int frame, Mtx m, f32 t) {
    Mtx rot;
    f32 angle;

    PSMTXIdentity(m);
    m[0][0] = fn_3_BFDA4(anim->keys[0], anim->counts[0], frame, anim->current[0], &anim->current[0], t);
    m[1][1] = fn_3_BFDA4(anim->keys[1], anim->counts[1], frame, anim->current[1], &anim->current[1], t);
    if (anim->keys[2] != NULL) {
        angle = fn_3_BFDA4(anim->keys[2], anim->counts[2], frame, anim->current[2], &anim->current[2], t);
    } else {
        angle = 0.0f;
    }
    m[0][3] = angle;
    if (anim->keys[5] != NULL) {
        angle = fn_3_BFDA4(anim->keys[5], anim->counts[5], frame, anim->current[5], &anim->current[5], t);
    } else {
        angle = 0.0f;
    }
    if (angle) {
        PSMTXRotRad(rot, 'Y', angle);
        PSMTXConcat(rot, m, m);
    }
    if (anim->keys[6] != NULL) {
        angle = fn_3_BFDA4(anim->keys[6], anim->counts[6], frame, anim->current[6], &anim->current[6], t);
    } else {
        angle = 0.0f;
    }
    if (angle) {
        PSMTXRotRad(rot, 'Z', angle);
        PSMTXConcat(rot, m, m);
    }
    return fn_3_BFDA4(anim->keys[7], anim->counts[7], frame, anim->current[7], &anim->current[7], t);
}

// .text:0x000C937C size:0x214 mapped:0x80708410
BOOL fn_3_C937C(void) {
    Mtx scale;
    Mtx base = { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };
    Mtx m;

    switch (lbl_3_bss_9F34) {
    case 0:
        lbl_3_bss_9F34 = 1;
        lbl_3_bss_9F30 = 0.0f;
    case 1:
        lbl_3_bss_9F30 += 1.0f;
        if (lbl_3_bss_9F30 >= 16.0f) {
            lbl_3_bss_9F34 = 2;
        }
        break;
    }
    fn_80034120(m);
    PSMTXConcat(m, base, m);
    PSMTXScale(scale, lbl_3_data_17B84[lbl_3_bss_9F20], lbl_3_data_17B84[lbl_3_bss_9F20],
               lbl_3_data_17B84[lbl_3_bss_9F20]);
    PSMTXConcat(m, scale, m);
    lbl_3_data_17B04[lbl_3_bss_9F20].time = lbl_3_bss_9F30;
    lbl_3_data_17B04[lbl_3_bss_9F20]._04 = lbl_3_common_bss_35154._004;
    if (lbl_3_data_17B80) {
        GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    }
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_DSTALPHA, GX_LO_CLEAR);
    fn_3_BF8F8(&lbl_3_data_17B04[lbl_3_bss_9F20], m, &lbl_3_bss_9F24, fn_3_C9590);
    if (lbl_3_data_17B80) {
        GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    }
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    return lbl_3_bss_9F34 == 2;
}
