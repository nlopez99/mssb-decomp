#include "game/rep_3F60.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0xEC];
    /* 0xEC */ MtxPtr _EC;
} UnkBone3F60;

typedef struct {
    /* 0x00 */ u8 _00[6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x18 - 0x08];
    /* 0x18 */ UnkBone3F60** _18;
    /* 0x1C */ u8 _1C[0x98 - 0x1C];
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
} UnkActor3F60;

typedef struct {
    /* 0x00 */ UnkActor3F60* _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ u8 _08[0x0E - 0x08];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u8 _10[0x60 - 0x10];
    /* 0x60 */ f32 _60;
    /* 0x64 */ u8 _64[0x90 - 0x64];
} UnkModel3F60; // size: 0x90

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ u8 _08[0x0C - 0x08];
    /* 0x0C */ u16 _0C;
    /* 0x0E */ u8 _0E[0x18 - 0x0E];
    /* 0x18 */ u16 _18;
    /* 0x1A */ u8 _1A[0x20 - 0x1A];
    /* 0x20 */ void* _20;
    /* 0x24 */ u8 _24[0x5C - 0x24];
} UnkAnim3F60; // size: 0x5C

typedef struct UnkDraw3F60 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*_04)(struct UnkDraw3F60*);
    /* 0x08 */ VecXYZ _08;
    /* 0x14 */ f32 _14;
    /* 0x18 */ u32 _18;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
    /* 0x1E */ u8 _1E;
    /* 0x1F */ u8 _1F;
} UnkDraw3F60; // size: 0x20

typedef struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u16 _12;
    /* 0x14 */ VecXYZ _14;
    /* 0x20 */ f32 _20;
    /* 0x24 */ u16 _24;
    /* 0x26 */ u16 _26;
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
    /* 0x2A */ u8 _2A;
    /* 0x2B */ u8 _2B;
    /* 0x2C */ u8 _2C;
} UnkTask3F60;

typedef struct UnkPlayer3F60 {
    /* 0x000 */ u8 _000[0x252];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ s8 _254;
} UnkPlayer3F60;

extern struct {
    /* 0x000 */ u8 _000[0x10];
    /* 0x010 */ struct {
        /* 0x00 */ u8 _00[0x34];
        /* 0x34 */ UnkModel3F60 _34[1];
    }* _010;
    /* 0x014 */ u8 _014[0x20 - 0x14];
    /* 0x020 */ UnkAnim3F60 _020[1];
    /* 0x07C */ u8 _07C[0x479 - 0x7C];
    /* 0x479 */ u8 _479;
} lbl_3_common_bss_35154;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ UnkPlayer3F60* _2C50[13];
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern u8 lbl_803CBBC0;
extern UnkTask3F60* lbl_803CC1B8;

extern s32 fn_8005268C(void);
extern camera_803c639c_s* fn_80052734(s32);
extern void fn_80024DB0(UnkAnim3F60*);
extern void fn_80024FA4(UnkModel3F60*, void*, UnkAnim3F60*, s32);
extern void fn_800A7D4C(s32, void*);
extern void fn_800B0A14_removeQueue(void);
extern UnkTask3F60* fn_800B0A5C_insertQueue(void (*)(void), u16);
extern void fn_800B4C04(UnkActor3F60*, f32);
extern void fn_800B4CA0(UnkActor3F60*, f32);
extern void fn_800BDA24(UnkModel3F60*);
extern void fn_800BDA94(UnkModel3F60*, Mtx);
// C3/actor.h's prototype takes Actor*, which this file's actor type does not convert to
extern void ACTSetAnimation(UnkActor3F60*, void*, char*, u16, f32, f32);

static s32 lbl_3_data_285A8[54] = {
    -250000, -250000, -250000, -200000, -200000, -200000, -250000, -240000, -240000,
    -250000, -200000, -150000, -200000, -200000, -250000, -350000, -200000, -250000,
    -200000, -200000, -250000, -200000, -200000, -200000, -180000, -180000, -180000,
    -250000, -200000, -200000, -200000, -200000, -200000, -250000, -250000, -250000,
    -250000, -180000, -280000, -200000, -200000, -200000, -250000, -250000, -200000,
    -200000, -200000, -200000, -250000, -250000, -250000, -250000, -250000, -250000,
};

static struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[4][3];
    /* 0x34 */ s32 _34;
    /* 0x38 */ s32 _38;
    /* 0x3C */ s32 _3C;
    /* 0x40 */ s32 _40;
    /* 0x44 */ s32 _44;
} lbl_3_data_28680 = {
    0,
    {
        { 50000, 0, 0 },
        { 50000, 0, 0 },
        { 50000, 0, 0 },
        { 0, 0, 0 },
    },
    300000,
    100000,
    300000,
    100000,
    300000,
};

static UnkDraw3F60 lbl_3_data_286C8[9][2] = {
    { { 0, fn_3_168A6C }, { 0, fn_3_168A6C } },
    { { 0, fn_3_168A6C }, { 0, fn_3_168A6C } },
    { { 0, fn_3_168A6C }, { 0, fn_3_168A6C } },
    { { 0, fn_3_168A6C }, { 0, fn_3_168A6C } },
    { { 0, fn_3_168A6C }, { 0, fn_3_168A6C } },
    { { 0, fn_3_168A6C }, { 0, fn_3_168A6C } },
    { { 0, fn_3_168A6C }, { 0, fn_3_168A6C } },
    { { 0, fn_3_168A6C }, { 0, fn_3_168A6C } },
    { { 0, fn_3_168A6C }, { 0, fn_3_168A6C } },
};

// The explicit initializers keep these in .data; without them MWCC puts them in .bss
static u8 lbl_3_data_28908[9] = { 0 };
static u8 lbl_3_data_28914[9] = { 0 };
static u16 lbl_3_data_2891E = 9;
static u16 lbl_3_data_28920 = 9;
static u16 lbl_3_data_28922 = 9;

// .text:0x00169150 size:0x2C mapped:0x807A81E4
void fn_3_169150(void) {
    fn_800B0A5C_insertQueue(fn_3_1690C0, 0);
}

// .text:0x001690C0 size:0x90 mapped:0x807A8154
void fn_3_1690C0(void) {
    int i;

    memset(lbl_3_data_28908, 0, sizeof(lbl_3_data_28908));
    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    i = 8;
    do {
        lbl_3_data_28914[i] &= 0xFD;
    } while (i--);
    fn_800B0A14_removeQueue();
}

// .text:0x00168FA0 size:0x120 mapped:0x807A8034
void fn_3_168FA0(s32 idx, BOOL arg1) {
    UnkTask3F60* task;

    if (lbl_8036E548._2C50[idx] != NULL) {
        task = fn_800B0A5C_insertQueue(fn_3_168DFC, lbl_803CC1B8->_12 + 1);
        task->_29 = idx;
        task->_24 = 0;
        task->_20 = (f32)lbl_3_data_28680._34 / 100000.0f;
        getAnimRelatedCoordinates(idx, lbl_3_data_2891E, &task->_14);
        if (arg1) {
            task->_2A = 1;
            task->_28 = 3;
            task->_2B = 6;
        } else {
            task->_2A = 0;
            task->_28 = 2;
            task->_2B = 5;
        }
    }
}

// .text:0x00168DFC size:0x1A4 mapped:0x807A7E90
void fn_3_168DFC(void) {
    UnkTask3F60* task = lbl_803CC1B8;
    UnkDraw3F60* draw;
    UnkPlayer3F60* player;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    if (lbl_3_data_28908[task->_29] != 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    lbl_3_data_28908[task->_29] = 1;
    player = lbl_8036E548._2C50[task->_29];
    draw = &lbl_3_data_286C8[task->_29][lbl_803CBBC0];
    draw->_04 = fn_3_168A6C;
    draw->_18 = task->_24;
    draw->_08.x = task->_14.x;
    draw->_08.y = task->_14.y + (f32)lbl_3_data_285A8[player->_252] / 100000.0f;
    draw->_08.z = task->_14.z;
    draw->_14 = task->_20;
    draw->_1C = task->_28;
    draw->_1E = task->_2B;
    draw->_1D = task->_2A;
    if (lbl_80366158._28 == 0) {
        task->_24++;
    }
    fn_800A7D4C(0, draw);
    if (task->_24 >= lbl_3_common_bss_35154._020[task->_2B]._18) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00168CD8 size:0x124 mapped:0x807A7D6C
void fn_3_168CD8(UnkPlayer3F60* player, u16 arg1, s32 arg2, f32 frame) {
    s32 idx = player->_254;
    UnkTask3F60* task;

    if (frame == (f32)lbl_3_data_28680._38 / 100000.0f && player != NULL) {
        task = fn_800B0A5C_insertQueue(fn_3_168DFC, lbl_803CC1B8->_12 + 1);
        task->_29 = idx;
        task->_24 = 0;
        task->_20 = (f32)lbl_3_data_28680._3C / 100000.0f;
        getAnimRelatedCoordinates(idx, lbl_3_data_28920, &task->_14);
        task->_2A = 2;
        task->_28 = 4;
        task->_2B = 7;
    }
}

// .text:0x00168A6C size:0x26C mapped:0x807A7B00
void fn_3_168A6C(UnkDraw3F60* draw) {
    void* animData;
    UnkAnim3F60* anim;
    UnkModel3F60* model;
    MtxPtr view;
    Mtx m;
    Mtx tmp;

    model = &lbl_3_common_bss_35154._010->_34[draw->_1C];
    anim = &lbl_3_common_bss_35154._020[draw->_1E];
    animData = lbl_3_common_bss_35154._020[draw->_1E]._20;
    view = fn_80052734(fn_8005268C())->view;
    PSMTXTrans(m, (f32)lbl_3_data_28680._04[draw->_1D][0] / 100000.0f,
               (f32)lbl_3_data_28680._04[draw->_1D][1] / 100000.0f,
               (f32)lbl_3_data_28680._04[draw->_1D][2] / 100000.0f);
    PSMTXInverse(view, tmp);
    tmp[0][3] = tmp[1][3] = tmp[2][3] = 0.0f;
    PSMTXConcat(tmp, m, m);
    PSMTXScaleApply(m, m, draw->_14, draw->_14, draw->_14);
    PSMTXRotRad(tmp, 'Y', PI);
    PSMTXConcat(tmp, m, m);
    PSMTXTransApply(m, m, draw->_08.x, draw->_08.y, draw->_08.z);
    PSMTXConcat(view, m, m);
    anim->_00 = 0.0f;
    anim->_0C = 0;
    anim->_04 = draw->_18;
    fn_80024DB0(anim);
    fn_80024FA4(model, animData, anim, -1);
    model->_00->_99 = 1;
    ACTSetAnimation(model->_00, model->_04, NULL, model->_0E, 0.0f, model->_60);
    fn_800B4CA0(model->_00, draw->_18);
    fn_800B4C04(model->_00, 1.0f);
    fn_800BDA24(model);
    model->_00->_98 = 0xFF;
    fn_800BDA94(model, m);
}

// .text:0x0016892C size:0x140 mapped:0x807A79C0
void fn_3_16892C(UnkPlayer3F60* player, u16 arg1, s32 arg2, f32 frame) {
    s32 idx = player->_254;
    UnkTask3F60* task;

    if (frame == (f32)lbl_3_data_28680._40 / 100000.0f && !(lbl_3_data_28914[idx] & 1)) {
        lbl_3_data_28914[idx] |= 1;
        if (player != NULL) {
            task = fn_800B0A5C_insertQueue(fn_3_168704, lbl_803CC1B8->_12 + 1);
            task->_29 = idx;
            task->_24 = 0;
            task->_20 = (f32)lbl_3_data_28680._44 / 100000.0f;
            task->_26 = arg1;
            task->_2A = 3;
            task->_28 = 5;
            task->_2B = 8;
            task->_2C = 9;
        }
    }
    lbl_3_data_28914[idx] |= 2;
}

// .text:0x00168704 size:0x228 mapped:0x807A7798
void fn_3_168704(void) {
    UnkTask3F60* task = lbl_803CC1B8;
    UnkDraw3F60* draw;
    UnkPlayer3F60* player;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    if (lbl_3_data_28908[task->_29] != 0) {
        if (lbl_80366158._28 != 0) {
            lbl_3_data_28914[task->_29] &= ~1;
        }
        fn_800B0A14_removeQueue();
        return;
    }
    if (!(lbl_3_data_28914[task->_29] & 2)) {
        lbl_3_data_28914[task->_29] &= ~1;
        fn_800B0A14_removeQueue();
        return;
    }
    lbl_3_data_28908[task->_29] = 1;
    player = lbl_8036E548._2C50[task->_29];
    draw = &lbl_3_data_286C8[task->_29][lbl_803CBBC0];
    draw->_04 = fn_3_168414;
    draw->_18 = task->_24;
    getAnimRelatedCoordinates(task->_29, lbl_3_data_28922, &draw->_08);
    draw->_08.y += (f32)lbl_3_data_285A8[player->_252] / 100000.0f;
    draw->_14 = (f32)lbl_3_data_28680._34 / 100000.0f;
    draw->_1C = task->_28;
    draw->_1E = task->_2B;
    draw->_1F = task->_2C;
    draw->_1D = task->_2A;
    if (lbl_80366158._28 == 0) {
        task->_24++;
    }
    fn_800A7D4C(0, draw);
    task->_24 %= 60;
}

// .text:0x00168414 size:0x2F0 mapped:0x807A74A8
void fn_3_168414(UnkDraw3F60* draw) {
    void* animData[2];
    UnkAnim3F60* anims[2];
    UnkModel3F60* model;
    MtxPtr view;
    UnkBone3F60* bone;
    Mtx m;
    Mtx tmp;
    int i;

    model = &lbl_3_common_bss_35154._010->_34[draw->_1C];
    anims[0] = &lbl_3_common_bss_35154._020[draw->_1E];
    anims[1] = &lbl_3_common_bss_35154._020[draw->_1F];
    animData[0] = lbl_3_common_bss_35154._020[draw->_1E]._20;
    animData[1] = lbl_3_common_bss_35154._020[draw->_1F]._20;
    view = fn_80052734(fn_8005268C())->view;
    PSMTXTrans(m, (f32)lbl_3_data_28680._04[draw->_1D][0] / 100000.0f,
               (f32)lbl_3_data_28680._04[draw->_1D][1] / 100000.0f,
               (f32)lbl_3_data_28680._04[draw->_1D][2] / 100000.0f);
    PSMTXScaleApply(m, m, draw->_14, draw->_14, draw->_14);
    PSMTXTransApply(m, m, draw->_08.x, draw->_08.y, draw->_08.z);
    PSMTXConcat(view, m, m);
    for (i = 0; i < 2; i++) {
        anims[i]->_00 = 0.0f;
        anims[i]->_0C = 0;
        anims[i]->_04 = draw->_18;
        fn_80024DB0(anims[i]);
        fn_80024FA4(model, animData[i], anims[i], -1);
    }
    model->_00->_99 = 1;
    ACTSetAnimation(model->_00, model->_04, NULL, model->_0E, 0.0f, model->_60);
    fn_800B4CA0(model->_00, draw->_18 + 15);
    fn_800B4C04(model->_00, 1.0f);
    fn_800BDA24(model);
    for (i = 0; i < model->_00->_06; i++) {
        switch (i) {
        case 1:
        case 2:
        case 3:
        case 4:
            bone = model->_00->_18[i];
            PSMTXConcat(view, bone->_EC, tmp);
            PSMTXInverse(tmp, tmp);
            tmp[0][3] = tmp[1][3] = tmp[2][3] = 0.0f;
            PSMTXConcat(bone->_EC, tmp, bone->_EC);
            break;
        }
    }
    model->_00->_98 = 0xFF;
    fn_800BDA94(model, m);
}
