#include "game/rep_2308.h"
#include "game/rep_1F58.h"
#include "game/rep_3AE8.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0x98];
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
} Unk2308Actor;

typedef struct {
    /* 0x00 */ Unk2308Actor* _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ u8 _08[0xE - 0x8];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u8 _10[0x60 - 0x10];
    /* 0x60 */ f32 _60;
} Unk2308Model;

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ u8 _08[0xC - 0x8];
    /* 0x0C */ u16 _0C;
    /* 0x0E */ u8 _0E[0x18 - 0xE];
    /* 0x18 */ u16 _18;
    /* 0x1A */ u8 _1A[0x20 - 0x1A];
    /* 0x20 */ u32 _20;
    /* 0x24 */ u8 _24[0x5C - 0x24];
} Unk2308Anim; // size: 0x5C

typedef struct {
    /* 0x00 */ u8 _00[0xC4];
    /* 0xC4 */ Unk2308Model _C4;
} Unk2308Models;

typedef struct Unk2308Draw {
    /* 0x00 */ s32 _00;
    /* 0x04 */ void (*_04)(struct Unk2308Draw*);
    /* 0x08 */ Vec _08;
    /* 0x14 */ Quaternion _14;
    /* 0x24 */ u32 _24;
} Unk2308Draw; // size: 0x28

typedef struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ Vec _14;
    /* 0x20 */ Quaternion _20;
    /* 0x30 */ u16 _30;
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34;
} Unk2308Task;

typedef struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ Mtx _40;
} Unk2308Camera;

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ VecXYZ _34;
} Unk2308Player;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ Unk2308Player* _2C50[13];
} lbl_8036E548;

extern struct {
    /* 0x000 */ u8 _000[0x10];
    /* 0x010 */ Unk2308Models* _010;
    /* 0x014 */ u8 _014[0xD8 - 0x14];
    /* 0x0D8 */ Unk2308Anim _0D8[3];
    /* 0x1EC */ u8 _1EC[0x3AC - 0x1EC];
    /* 0x3AC */ u32 _3AC;
    /* 0x3B0 */ u8 _3B0[0x428 - 0x3B0];
    /* 0x428 */ Vec _428;
    /* 0x434 */ u8 _434[0x467 - 0x434];
    /* 0x467 */ s8 _467;
} lbl_3_common_bss_35154;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern Unk2308Task* lbl_803CC1B8;
extern u8 lbl_803CBBC0;

extern void ACTSetAnimation(Unk2308Actor* actor, void* animBank, char* sequenceName, u16 seqNum, f32 time, f32 speed);
extern void fn_80024DB0(Unk2308Anim*);
extern void fn_80024FA4(Unk2308Model*, u32, Unk2308Anim*, s32);
extern s32 fn_8005268C(void);
extern Unk2308Camera* fn_80052734(s32);
extern void fn_800A7D4C(s32, void*);
extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B4C04(Unk2308Actor*, f32);
extern void fn_800B4CA0(Unk2308Actor*, f32);
extern void fn_800BDA24(Unk2308Model*);
extern void fn_800BDA94(Unk2308Model*, Mtx);

s32 lbl_3_data_17D08[2] = { 23000, 8 };
Unk2308Task* lbl_3_data_17D10[2] = { NULL, NULL };
Unk2308Draw lbl_3_data_17D18[2][2] = {
    { { 0, fn_3_CABF0 }, { 0, fn_3_CABF0 } },
    { { 0, fn_3_CABF0 }, { 0, fn_3_CABF0 } },
};
s32 lbl_3_data_17DB8[2] = { 3, 0 };

// .text:0x000CB284 size:0xC0 mapped:0x8070A318
void fn_3_CB284(s32 idx, s32 windup, f32 proportion) {
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES ||
        (g_Minigame.GameMode_MiniGame != MINI_GAME_ID_BOBOMB_DERBY &&
         g_Minigame.GameMode_MiniGame != MINI_GAME_ID_BARREL_BATTER)) {
        if (lbl_3_common_bss_35154._467 && windup == 35) {
            lbl_3_common_bss_35154._428.x = lbl_8036E548._2C50[idx]->_34.x;
            lbl_3_common_bss_35154._428.y = -lbl_8036E548._2C50[idx]->_34.y;
            lbl_3_common_bss_35154._428.z = lbl_8036E548._2C50[idx]->_34.z;
            lbl_3_common_bss_35154._3AC |= 0x10;
        }
        fn_3_C1344(idx, 100.0f * proportion, 100.0f, windup == 30);
    }
}

// .text:0x000CB234 size:0x50 mapped:0x8070A2C8
void fn_3_CB234(s32 idx, s32 arg1) {
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES ||
        (g_Minigame.GameMode_MiniGame != MINI_GAME_ID_BOBOMB_DERBY &&
         g_Minigame.GameMode_MiniGame != MINI_GAME_ID_BARREL_BATTER)) {
        fn_3_C11CC(idx, arg1);
    }
}

// .text:0x000CB1B0 size:0x84 mapped:0x8070A244
void fn_3_CB1B0(s32 idx, u8 starPitchType, s32 windup) {
    if ((g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES ||
         (g_Minigame.GameMode_MiniGame != MINI_GAME_ID_BOBOMB_DERBY &&
          g_Minigame.GameMode_MiniGame != MINI_GAME_ID_BARREL_BATTER)) &&
        windup == 35) {
        lbl_3_common_bss_35154._467 = starPitchType;
        lbl_3_common_bss_35154._428.x = lbl_8036E548._2C50[idx]->_34.x;
        lbl_3_common_bss_35154._428.y = -lbl_8036E548._2C50[idx]->_34.y;
        lbl_3_common_bss_35154._428.z = lbl_8036E548._2C50[idx]->_34.z;
        lbl_3_common_bss_35154._3AC |= 0x10;
    }
}

// .text:0x000CAF9C size:0x214 mapped:0x8070A030
void fn_3_CAF9C(void) {
    Vec pos;
    Vec vel;
    Vec accel;
    Unk2308Task* task;
    s32 n;
    s32 i;

    task = fn_800B0A5C_insertQueue(fn_3_CAE00, 1);
    task->_30 = 0;
    task->_33 = g_Pitcher.rosterID;
    memcpy(&pos, &g_Pitcher.ballCurrentPosition, sizeof(Vec));
    memcpy(&vel, &g_Pitcher.ballVelocity, sizeof(Vec));
    memcpy(&accel, &g_Pitcher.pitchCurveVeloV1, sizeof(Vec));

    n = lbl_3_data_17D08[1];
    while (n--) {
        fn_3_15C024(&pos, &vel, &accel, 0);
    }

    task->_14.x = pos.x;
    task->_14.y = -pos.y;
    task->_14.z = pos.z;

    pos.x -= g_Pitcher.ballCurrentPosition.x;
    pos.y -= g_Pitcher.ballCurrentPosition.y;
    pos.z -= g_Pitcher.ballCurrentPosition.z;
    pos.y = -pos.y;
    PSVECNormalize(&pos, &pos);

    vel.x = -1.0f;
    vel.y = 0.0f;
    vel.z = 0.0f;
    PSVECCrossProduct(&vel, &pos, (Vec*)&task->_20);
    task->_20.w = acos(PSVECDotProduct(&vel, &pos)) / 2.0f;
    if (PSVECMag((Vec*)&task->_20)) {
        PSVECNormalize((Vec*)&task->_20, (Vec*)&task->_20);
        PSVECScale((Vec*)&task->_20, sin(task->_20.w), (Vec*)&task->_20);
    }
    task->_20.w = cos(task->_20.w);
    task->_34 = i = 0;

    for (; i < 2; i++) {
        if (lbl_3_data_17D10[i] == NULL) {
            lbl_3_data_17D10[i] = task;
            task->_32 = i;
            break;
        }
    }
}

// .text:0x000CAE00 size:0x19C mapped:0x80709E94
void fn_3_CAE00(void) {
    Unk2308Task* task = lbl_803CC1B8;
    Unk2308Player* player = lbl_8036E548._2C50[task->_33];

    if (task->_34 == 0 && player != NULL) {
        fn_800A7D4C(0, &lbl_3_data_17D18[task->_32][lbl_803CBBC0]);
        lbl_3_data_17D18[task->_32][lbl_803CBBC0]._24 = task->_30;
        lbl_3_data_17D18[task->_32][lbl_803CBBC0]._08.x = task->_14.x;
        lbl_3_data_17D18[task->_32][lbl_803CBBC0]._08.y = task->_14.y;
        lbl_3_data_17D18[task->_32][lbl_803CBBC0]._08.z = task->_14.z;
        lbl_3_data_17D18[task->_32][lbl_803CBBC0]._14 = task->_20;
        if (lbl_80366158._28 == 0) {
            task->_30++;
        }
    } else {
        lbl_3_data_17D10[task->_32] = NULL;
        fn_800B0A14_removeQueue();
    }

    if (task->_30 >= lbl_3_common_bss_35154._0D8[0]._18) {
        lbl_3_data_17D10[task->_32] = NULL;
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000CABF0 size:0x210 mapped:0x80709C84
void fn_3_CABF0(Unk2308Draw* draw) {
    u32 ids[3];
    Unk2308Anim* anims[3];
    Mtx mtx;
    Unk2308Model* model;
    f32 scale;
    s32 i;

    scale = lbl_3_data_17D08[0] / 100000.0f;
    model = &lbl_3_common_bss_35154._010->_C4;
    ids[0] = lbl_3_common_bss_35154._0D8[0]._20;
    anims[0] = &lbl_3_common_bss_35154._0D8[0];
    ids[1] = lbl_3_common_bss_35154._0D8[1]._20;
    anims[1] = &lbl_3_common_bss_35154._0D8[1];
    ids[2] = lbl_3_common_bss_35154._0D8[2]._20;
    anims[2] = &lbl_3_common_bss_35154._0D8[2];

    PSMTXQuat(mtx, &draw->_14);
    PSMTXScaleApply(mtx, mtx, scale, scale, scale);
    PSMTXTransApply(mtx, mtx, draw->_08.x, draw->_08.y, draw->_08.z);
    PSMTXConcat(fn_80052734(fn_8005268C())->_40, mtx, mtx);

    i = 2;
    do {
        anims[i]->_00 = 0.0f;
        anims[i]->_0C = 0;
        anims[i]->_04 = draw->_24;
        fn_80024DB0(anims[i]);
        fn_80024FA4(model, ids[i], anims[i], -1);
    } while (i--);

    model->_00->_99 = 1;
    ACTSetAnimation(model->_00, model->_04, NULL, model->_0E, 0.0f, model->_60);
    fn_800B4CA0(model->_00, draw->_24);
    fn_800B4C04(model->_00, 1.0f);
    fn_800BDA24(model);
    model->_00->_98 = 0xFF;
    fn_800BDA94(model, mtx);
}

// .text:0x000CABB4 size:0x3C mapped:0x80709C48
void fn_3_CABB4(void) {
    if (lbl_3_data_17D10[0] != NULL) {
        lbl_3_data_17D10[0]->_34 = 1;
    }
    if (lbl_3_data_17D10[1] != NULL) {
        lbl_3_data_17D10[1]->_34 = 1;
    }
}
