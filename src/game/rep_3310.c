#include "game/rep_3310.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1C0.h"
#include "game/rep_1838.h"
#include "game/rep_1D58.h"
#include "game/m_sound.h"
#include "game/rep_37A8.h"
#include "game/rep_3880.h"
#include "game/rep_3E58.h"
#include "Dolphin/mtx.h"
#include "C3/control.h"
#include "Dolphin/gx.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0x20];
    /* 0x20 */ u16 _20;
    /* 0x22 */ u8 _22[0x40 - 0x22];
    /* 0x40 */ u16 _40;
    /* 0x42 */ u8 _42[0x60 - 0x42];
    /* 0x60 */ u16 _60;
} UnkAnimFrame3310;

typedef struct {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ UnkAnimFrame3310* _0C;
} UnkAnimCtrl3310;

typedef struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ UnkAnimCtrl3310* _08;
} UnkAnimSet3310;

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
} UnkTexScroll3310;

typedef struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ UnkAnimSet3310* _14;
    /* 0x18 */ u8 _18[0xE8 - 0x18];
    /* 0xE8 */ UnkTexScroll3310* _E8;
    /* 0xEC */ Mtx* _EC;
} UnkModel3310;

typedef struct {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x14 - 0x8];
    /* 0x14 */ UnkAnimSet3310* _14;
    /* 0x18 */ UnkModel3310** _18;
    /* 0x1C */ u8 _1C[0x98 - 0x1C];
    /* 0x98 */ u8 _98;
} UnkModelSet3310;

typedef struct {
    /* 0x00 */ UnkModelSet3310* _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ u8 _08[0xE - 0x8];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ Control _10;
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u8 _64[0x6C - 0x64];
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D[0x90 - 0x6D];
} UnkActor3310; // size: 0x90

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ UnkActor3310 _34[1];
} UnkActorTable3310;

typedef struct UnkObj3310 {
    /* 0x00 */ void (*_00)(s32);
    /* 0x04 */ Vec _04;
    /* 0x10 */ Vec _10;
    /* 0x1C */ u8 _1C[0x26 - 0x1C];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} UnkObj3310; // size: 0x28

extern struct {
    /* 0x0000 */ u8 _0000[0x68];
    /* 0x0068 */ UnkActorTable3310* _0068;
    /* 0x006C */ u8 _006C[0xAC - 0x6C];
    /* 0x00AC */ void* _00AC[4];
    /* 0x00BC */ u8 _00BC[0x2D94 - 0xBC];
    /* 0x2D94 */ UnkObj3310* _2D94;
    /* 0x2D98 */ u8 _2D98[0x2DA0 - 0x2D98];
    /* 0x2DA0 */ void* _2DA0[27][3]; // layout, geometry and texture of each model
    /* 0x2EE4 */ u8 _2EE4[0x3078 - 0x2EE4];
    /* 0x3078 */ u16 _3078;
    /* 0x307A */ u8 _307A[0x307E - 0x307A];
    /* 0x307E */ u8 _307E;
} lbl_8036E548;

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 _0C[0x26 - 0xC];
    /* 0x26 */ u8 active;
    /* 0x27 */ u8 _27;
} UnkPiranha3310; // size: 0x28

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 _0C[0x18 - 0xC];
    /* 0x18 */ Vec rot; // degrees
    /* 0x24 */ u8 _24[0x3D - 0x24];
    /* 0x3D */ u8 active;
    /* 0x3E */ u8 _3E[0x40 - 0x3E];
} UnkMgMarker3310; // size: 0x40

// g_Minigame's layout in the minigames this unit serves
typedef struct UnkMgEntry3310 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec rot;
    /* 0x18 */ u8 _18[0x1A - 0x18];
    /* 0x1A */ s16 _1A;
    /* 0x1C */ s16 _1C;
    /* 0x1E */ s16 _1E;
    /* 0x20 */ u8 _20[0x26 - 0x20];
    /* 0x26 */ s16 _26;
    /* 0x28 */ s16 _28;
    /* 0x2A */ u8 _2A;
    /* 0x2B */ u8 _2B;
    /* 0x2C */ u8 _2C;
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E;
    /* 0x2F */ u8 _2F[0x33 - 0x2F];
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34[0x38 - 0x34];
} UnkMgEntry3310; // size: 0x38

typedef struct {
    /* 0x0000 */ UnkMgEntry3310 _0000[3];
    /* 0x00A8 */ UnkPiranha3310 _00A8[40];
    /* 0x06E8 */ u8 _06E8[0xBB0 - 0x6E8];
    /* 0x0BB0 */ UnkMgMarker3310 _0BB0[4];
    /* 0x0CB0 */ u8 _0CB0[0xCCE - 0xCB0];
    /* 0x0CCE */ u8 _0CCE;
    /* 0x0CCF */ u8 _0CCF[0x1A2A - 0xCCF];
    /* 0x1A2A */ u8 _1A2A;
    /* 0x1A2B */ u8 _1A2B[0x1AFF - 0x1A2B];
    /* 0x1AFF */ u8 _1AFF[4];
} UnkMinigame3310;

#define MG (*(UnkMinigame3310*)&g_Minigame)

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ u8 _08[0xC - 0x8];
    /* 0x0C */ u16 _0C;
    /* 0x0E */ s16 _0E;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11_7 : 1;
    /* 0x11 */ u8 _11_0 : 7;
} UnkAnimState3310;

extern struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ UnkAnimState3310 _10;
    /* 0x24 */ u8 _24[0x30 - 0x24];
    /* 0x30 */ void* _30;
    /* 0x34 */ u8 _34[0x60 - 0x34];
    /* 0x60 */ s32 _60;
    /* 0x64 */ u8 _64[0x6C - 0x64];
    /* 0x6C */ void* _6C;
    /* 0x70 */ void* _70;
    /* 0x74 */ void* _74;
    /* 0x78 */ void* _78;
} lbl_3_common_bss_32724;

extern f32 fn_800B4A94(UnkModelSet3310* model);
extern void fn_8001D0D0(s32 id, f32 scale);
extern void fn_8001D110(s32 id, f32 x, f32 y, f32 z);
extern void fn_800BDC88(UnkActorTable3310* actors, u16 first, u16 last, void* model, void* anim, s32 arg5);
extern void fn_800BD548(UnkActor3310* actor, s32 count, ...);

typedef struct {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
} UnkTask3310;

typedef struct {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ Vec _48;
    /* 0x54 */ u32 _54;
    /* 0x58 */ u8 _58[0x5C - 0x58];
    /* 0x5C */ u32 _5C;
} UnkSprite3310;

typedef struct {
    /* 0x00 */ UnkSprite3310* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef3310; // size: 0x8

extern UnkSpriteRef3310 lbl_80371C30[];
extern void* lbl_803CC1B8;
extern void fn_80034CEC(UnkTask3310* task);
extern void fn_80034E20(UnkTask3310* task, void* desc);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80062C24(Vec* pos);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern UnkActorTable3310* ActorObjectInitTable(u16 count);
extern void fn_80025C58(void* anim, UnkActor3310* actor);
extern void fn_80011B64(s32 i);
extern void fn_800B4CDC(UnkModelSet3310* model);
extern void fn_800B4278(UnkModelSet3310* model);
extern void fn_800ACFB0(void* data);
extern void fn_800B993C(void);
extern s32 fn_8005268C(void);
extern void fn_80033B58(void* texture, s32 index, s32, s32);
extern void fn_80024DB0(UnkAnimState3310* state);
extern void fn_80024FA4(UnkActor3310* actor, void* anim, UnkAnimState3310* state, s32 arg3);

// .data outside this unit's split
extern u8 lbl_3_data_69D0[0x520];
extern s16 lbl_3_data_217A4[12];
extern s16 lbl_3_data_21A04[8];
extern s16 lbl_3_data_21E68[26];
extern f32 lbl_3_data_21A64[9];
extern VecXYZ lbl_3_data_21520[2][7];
extern s16 lbl_3_data_21654[12];
extern Vec lbl_3_data_21380;
extern f32 lbl_3_data_2188C[7];
extern Vec lbl_3_data_21A48;
extern Vec lbl_3_data_21B94[4];
extern struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 _0C[0x30 - 0xC];
} lbl_3_data_21BC4[7];

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;
extern void minigamesSetSomePointers(void);
extern void minigamesGXStuff(void);
extern void minigamesSetSomePointers2(void);
extern void fn_80035B50(s32);
extern void fn_80018B38(void);

typedef struct {
    /* 0x00 */ u32 _00[4];
} UnkAramEntry3310; // size: 0x10

static inline void setAnim(UnkActor3310* actor, void* anim, u16 frame) {
    actor->_04 = anim;
    actor->_0E = frame;
    actor->_5C = 0.0f;
    actor->_58 = 1;
    actor->_59 = anim != NULL;
    actor->_5A = anim != NULL;
    actor->_60 = 0.0f;
    actor->_54 = 1.0f;
    actor->_5A = 1;
    actor->_5C = 0.0f;
    actor->_59 = 1;
    actor->_5B = 2;
}

// .data, in address order
UnkAramEntry3310 lbl_3_data_225F0[3] = {
    { 0x0000040B, 0x40001640, 0x08EB4800, 0x00000C38 },
    { 0x0000040B, 0x400B2D00, 0x08EB5800, 0x0006A948 },
    { 0x00000000, 0x00000686, 0x08F20800, 0x00000688 },
};
Vec lbl_3_data_22620 = { 0.0f, -0.15f, 18.5f };
f32 lbl_3_data_2262C = 0.45f;
u8 lbl_3_data_22630[4] = { 0, 1, 3, 2 };
u8 lbl_3_data_22634[4] = { 15, 15, 15, 15 };
u8 lbl_3_data_22638[4] = { 2, 0, 3, 1 };
u8 lbl_3_data_2263C[2] = { 0, 1 };
u8 lbl_3_data_2263E = 2;
u8 lbl_3_data_2263F = 6;
f32 lbl_3_data_22640[4] = { 0.75f, 0.05f, 3.0f, 0.02f };
f32 lbl_3_data_22650[3] = { 5.0f, 5.0f, 10.0f };
u8 lbl_3_data_2265C[4] = { 1, 0, 2, 3 };
f32 lbl_3_data_22660[2] = { 2.0f, 8.0f };
f32 lbl_3_data_22668 = 1.0f;
s32 lbl_3_data_2266C = 60;
u8 lbl_3_data_22670[8] = { 2, 0, 3, 4, 1, 0, 0, 0 };
f32 lbl_3_data_22678[2][2] = { { 2.0f, 2.5f }, { 1.0f, 1.0f } };
f32 lbl_3_data_22688[3] = { 0.5f, 0.0f, -0.5f };
f32 lbl_3_data_22694[6] = { 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 0.5f };
s16 lbl_3_data_226AC[6] = { 0, 0, 20, 10, 0, 0 };
u8 lbl_3_data_226B8[2] = { 15, 80 };
u8 lbl_3_data_226BC[8] = { 3, 1, 4, 2, 0, 0, 0, 0 };
f32 lbl_3_data_226C4[4] = { 1.5f, 0.7f, 1.0f, 0.5f };
f32 lbl_3_data_226D4[2] = { 1.0f, 30.0f };
f32 lbl_3_data_226DC = 4.0f;

// .bss, declared in reverse address order: MWCC lays statics out last to first
static u8 lbl_3_bss_B6C0[0x40]; // unreferenced
static f32 lbl_3_bss_B6BC;

static inline void clearObjs(void) {
    u32 i;
    UnkObj3310* obj;

    for (i = 0; i < 40; i++) {
        obj = &lbl_8036E548._2D94[i];
        obj->_26 = 0;
        obj->_00 = NULL;
    }
}

static inline void showPipes(void) {
    fn_3_11678C();
    lbl_8036E548._2D94[0xF0]._26 = 0;
    lbl_8036E548._2D94[0xF1]._26 = 0;
    lbl_8036E548._2D94[0xF2]._26 = 0;
    lbl_8036E548._2D94[0xF3]._26 = 0;
}

// .text:0x0011D2C8 size:0xE4 mapped:0x8075C35C
void fn_3_11D2C8(s32 model, s32 first, s32 count, void* anim, s32 arg4) {
    s32 i;

    for (i = first; i < first + count; i++) {
        fn_800BDC88(lbl_8036E548._0068, i, i, lbl_8036E548._2DA0[model][0], anim, arg4);
        fn_800BD548(&lbl_8036E548._0068->_34[i], 4, lbl_8036E548._00AC[0], lbl_8036E548._00AC[1],
                    lbl_8036E548._00AC[2], lbl_8036E548._00AC[3]);
        CTRLSetTranslation(&lbl_8036E548._0068->_34[i]._10, 0.0f, 0.0f, 0.0f);
        CTRLSetRotation(&lbl_8036E548._0068->_34[i]._10, 0.0f, 0.0f, 0.0f);
    }
}

// .text:0x0011D1B0 size:0x118 mapped:0x8075C244
void fn_3_11D1B0(void) {
    return;
}

// .text:0x0011CF84 size:0x22C mapped:0x8075C018
void fn_3_11CF84(void) {
    s32 i;

    if ((g_Minigame._1A3C == 0 || g_Minigame._1E2A >= 6) && g_Minigame._1A38 == 0) {
        for (i = 0; i < 4; i++) {
            fn_80011B64(i);
        }
    }
    for (i = lbl_8036E548._3078 - 1; i >= 0; i--) {
        lbl_8036E548._0068->_34[i]._6C = 0;
    }
    for (i = lbl_8036E548._3078 - 1; i >= 0; i--) {
        fn_800B4CDC(lbl_8036E548._0068->_34[i]._00);
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        for (i = lbl_8036E548._3078 - 1; i >= 0; i--) {
            fn_800B4278(lbl_8036E548._0068->_34[i]._00);
        }
        fn_800ACFB0(lbl_8036E548._0068);
        fn_800ACFB0(lbl_8036E548._2D94);
    }
    fn_800B993C();
    fn_3_90CB0();
    if (g_Minigame._1A38 == 0 || g_Minigame._1A3C != 0) {
        fn_3_11CF04();
    }
}

// .text:0x0011CF04 size:0x80 mapped:0x8075BF98
void fn_3_11CF04(void) {
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
        lbl_8036E548._3078 = 0;
    }
    lbl_8036E548._307E = 0;
    minigamesSetSomePointers();
    minigamesGXStuff();
    minigamesSetSomePointers2();
    fn_80035B50(0xD);
    fn_3_B95EC();
    fn_3_5E60();
    fn_80018B38();
    fn_3_909B0();
    fn_3_9081C();
    fn_80035B50(0x11);
}

// .text:0x0011CD00 size:0x204 mapped:0x8075BD94
void fn_3_11CD00(void) {
    lbl_8036E548._3078 = 3;
    lbl_8036E548._2D94 = _OSAllocFromHeap(0x20, lbl_8036E548._3078 * 0x28);
    lbl_8036E548._0068 = ActorObjectInitTable(lbl_8036E548._3078);
    fn_3_11D2C8(13, 0, 1, NULL, 0);
    fn_3_11D2C8(14, 1, 1, NULL, 0);
    fn_3_11D2C8(15, 2, 1, NULL, 0);
    lbl_3_common_bss_32724._10._04 = 0.5f;
    fn_80025C58(lbl_3_common_bss_32724._00, &lbl_8036E548._0068->_34[2]);
}

// .text:0x0011C5F8 size:0x708 mapped:0x8075B68C
void fn_3_11C5F8(void) {
    u16 i;

    lbl_8036E548._3078 = 0x111;
    lbl_8036E548._2D94 = _OSAllocFromHeap(0x20, lbl_8036E548._3078 * 0x28);
    lbl_8036E548._0068 = ActorObjectInitTable(lbl_8036E548._3078);
    fn_3_11D2C8(0, 0, 0x82, NULL, 0);
    fn_3_11D2C8(21, 0x82, 0x64, NULL, 0);
    fn_3_11D2C8(1, 0xE6, 7, NULL, 0);
    fn_3_11D2C8(2, 0xED, 7, NULL, 0);
    fn_3_11D2C8(3, 0xF4, 7, NULL, 0);
    fn_3_11D2C8(5, 0xFB, 1, NULL, 0);
    fn_3_11D2C8(6, 0xFC, 7, NULL, 0);
    fn_3_11D2C8(7, 0x103, 7, NULL, 0);
    fn_3_11D2C8(4, 0x10A, 7, NULL, 0);
    for (i = 0; i < 7; i++) {
        setAnim(&lbl_8036E548._0068->_34[i + 0xFC], lbl_3_common_bss_32724._70, 0);
        setAnim(&lbl_8036E548._0068->_34[i + 0x103], lbl_3_common_bss_32724._70, 2);
    }
}

// .text:0x0011C2CC size:0x32C mapped:0x8075B360
void fn_3_11C2CC(void) {
    s32 i;

    lbl_8036E548._3078 = 0x20;
    lbl_8036E548._2D94 = _OSAllocFromHeap(0x20, lbl_8036E548._3078 * 0x28);
    lbl_8036E548._0068 = ActorObjectInitTable(lbl_8036E548._3078);
    fn_3_11D2C8(8, 0, 0xF, NULL, 0);
    fn_3_11D2C8(9, 0xF, 1, NULL, 0);
    fn_3_11D2C8(10, 0x10, 0xF, NULL, 0);
    fn_3_11D2C8(16, 0x1F, 1, NULL, 0);
    for (i = 0; i < 15; i++) {
        setAnim(&lbl_8036E548._0068->_34[i + 0x10], lbl_3_common_bss_32724._74, 0);
    }
}

// .text:0x0011C02C size:0x2A0 mapped:0x8075B0C0
void fn_3_11C02C(void) {
    lbl_8036E548._3078 = 0xA7;
    lbl_8036E548._2D94 = _OSAllocFromHeap(0x20, lbl_8036E548._3078 * 0x28);
    lbl_8036E548._0068 = ActorObjectInitTable(lbl_8036E548._3078);
    fn_3_11D2C8(0, 0, 0x82, NULL, 0);
    fn_3_11D2C8(11, 0x82, 0x23, NULL, 0);
    fn_3_11D2C8(12, 0xA5, 1, NULL, 0);
    fn_3_11D2C8(26, 0xA6, 1, NULL, 0);
}

// .text:0x0011BBA4 size:0x488 mapped:0x8075AC38
void fn_3_11BBA4(void) {
    lbl_8036E548._3078 = 0xEE;
    lbl_8036E548._2D94 = _OSAllocFromHeap(0x20, lbl_8036E548._3078 * 0x28);
    lbl_8036E548._0068 = ActorObjectInitTable(lbl_8036E548._3078);
    fn_3_11D2C8(0, 0, 0x82, NULL, 0);
    fn_3_11D2C8(21, 0x82, 0x64, NULL, 0);
    fn_3_11D2C8(22, 0xE6, 1, NULL, 0);
    fn_3_11D2C8(23, 0xE7, 1, NULL, 0);
    fn_3_11D2C8(24, 0xE8, 1, NULL, 0);
    fn_3_11D2C8(25, 0xE9, 4, NULL, 0);
    fn_3_11D2C8(26, 0xED, 1, NULL, 0);
}

// .text:0x0011B75C size:0x448 mapped:0x8075A7F0
void fn_3_11B75C(void) {
    lbl_8036E548._3078 = 0xF4;
    lbl_8036E548._2D94 = _OSAllocFromHeap(0x20, lbl_8036E548._3078 * 0x28);
    lbl_8036E548._0068 = ActorObjectInitTable(lbl_8036E548._3078);
    fn_3_11D2C8(0, 0, 0x82, NULL, 0);
    fn_3_11D2C8(17, 0x82, 3, lbl_3_common_bss_32724._78, lbl_3_common_bss_32724._60);
    fn_3_11D2C8(18, 0x85, 0x32, NULL, 0);
    fn_3_11D2C8(13, 0xB7, 0x32, NULL, 0);
    fn_3_11D2C8(19, 0xE9, 7, NULL, 0);
    fn_3_11D2C8(20, 0xF0, 4, NULL, 0);
}

// .text:0x0011AC6C size:0xAF0 mapped:0x80759D00
// 99.85%: only registers differ, in the inlined fn_3_117494 (as in fn_3_116B74).
void fn_3_11AC6C(void) {
    UnkObj3310* obj;
    s32 i;

    if (g_GameLogic.gameStatus >= 0x1B && g_GameLogic.gameStatus <= 0x29) {
        if (lbl_8036E548._3078 != 0) {
            for (i = 0; i < lbl_8036E548._3078; i++) {
                obj = &lbl_8036E548._2D94[i];
                if (obj != NULL) {
                    obj->_26 = 0;
                }
            }
        }
        return;
    }
    switch (g_Minigame.GameMode_MiniGame) {
    case MINI_GAME_ID_BOBOMB_DERBY:
        fn_3_11AB2C();
        break;
    case MINI_GAME_ID_WALLBALL:
        fn_3_11A408();
        fn_3_11A210();
        break;
    case MINI_GAME_ID_BARREL_BATTER:
        fn_3_119F6C();
        fn_3_119D34();
        break;
    case MINI_GAME_ID_CHAINCHOMP_SPRINT:
        fn_3_119934();
        fn_3_119878();
        break;
    case MINI_GAME_ID_STAR_DASH:
        fn_3_118164();
        fn_3_1180A4();
        fn_3_117FC8();
        fn_3_11874C();
        fn_3_117AE4();
        fn_3_1179EC();
        fn_3_117494();
        break;
    case MINI_GAME_ID_PIRANHA_PANIC:
        fn_3_1194FC();
        fn_3_1192B8();
        fn_3_11874C();
        fn_3_11887C();
        fn_3_1183FC();
        break;
    }
}

// .text:0x0011AB2C size:0x140 mapped:0x80759BC0
void fn_3_11AB2C(void) {
    s32 id = 2;
    UnkObj3310* obj;
    UnkAnimState3310* state;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        id = 0;
    }
    obj = &lbl_8036E548._2D94[id];
    if (obj != NULL) {
        obj->_26 = 1;
        fn_3_11A92C(obj, id);
        if (g_Pitcher.pitcherActionState >= 2 && lbl_80366158._28 == 0) {
            state = &lbl_3_common_bss_32724._10;
            if (state != NULL) {
                lbl_3_common_bss_32724._10._11_7 = 1;
            }
            fn_80024DB0(state);
            fn_80024FA4(&lbl_8036E548._0068->_34[id], lbl_3_common_bss_32724._30, state, -1);
        } else if (g_Pitcher.pitcherActionState < 2 && lbl_3_common_bss_32724._10._0E == 0) {
            lbl_3_common_bss_32724._10._0C = 0;
            lbl_3_common_bss_32724._10._00 = lbl_3_common_bss_32724._10._0C;
            lbl_3_common_bss_32724._10._0E = 1;
        }
    }
}

// .text:0x0011A92C size:0x200 mapped:0x807599C0
void fn_3_11A92C(UnkObj3310* obj, s32 id) {
    Vec pos;

    obj->_04.x = lbl_3_data_22620.x;
    obj->_04.y = lbl_3_data_22620.y;
    obj->_04.z = lbl_3_data_22620.z;
    obj->_10.x = 0.0f;
    obj->_10.y = 0.0f;
    obj->_10.z = 0.0f;
    fn_8001D0D0(id, lbl_3_data_2262C);
    if (g_Minigame.pauseInd == 0 && g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
        if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY) {
            if (g_Pitcher.pitcherActionState >= 3) {
                if (g_Pitcher.currentStateFrameCounter == 1 && g_Pitcher.pitcherActionState == 3) {
                    lbl_3_bss_B6BC = 3.0f;
                    pos.x = lbl_3_data_21380.x;
                    pos.y = -lbl_3_data_21380.y;
                    pos.z = lbl_3_data_21380.z - 0.5f;
                    fn_80062C24(&pos);
                    fn_3_90064(0x2D6);
                }
                obj->_04.z += lbl_3_bss_B6BC;
                lbl_3_bss_B6BC -= 0.2 * (obj->_04.z - lbl_3_data_22620.z);
            }
        } else if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER) {
            if (g_Pitcher.currentStateFrameCounter == 1) {
                if (g_Pitcher.pitcherActionState == 1) {
                    fn_3_14B9A0(lbl_3_data_217A4[6] + lbl_3_data_217A4[7], &lbl_3_data_22620);
                    fn_3_90064(0x30E);
                } else if (g_Pitcher.pitcherActionState == 3) {
                    pos.x = lbl_3_data_21380.x;
                    pos.y = 0.4f + lbl_3_data_21380.y;
                    pos.z = lbl_3_data_21380.z - 0.5f;
                    fn_3_14A90C(&pos);
                }
            }
        }
    }
}

// .text:0x0011A408 size:0x524 mapped:0x8075949C
// 98.84%: the setAnim block of the note-block case and the frame threshold
// (srwi against srawi) differ, and the branches after them shift by one instruction.
void fn_3_11A408(void) {
    UnkObj3310* obj;
    UnkObj3310* shadow;
    UnkModelSet3310* model;
    UnkTexScroll3310* scroll;
    u32 j;
    u8 frame;
    Vec pos;
    MaybeWallBallStruct* wall;
    s32 i;
    s32 id;
    u8 big = FALSE;

    lbl_8036E548._2D94[0xFB]._26 = 0;
    for (i = 0; i < 7; i++) {
        wall = &g_Minigame.wallBallWalls[i];
        lbl_8036E548._2D94[i + 0xE6]._26 = 0;
        lbl_8036E548._2D94[i + 0xED]._26 = 0;
        lbl_8036E548._2D94[i + 0xF4]._26 = 0;
        lbl_8036E548._2D94[i + 0xFC]._26 = 0;
        lbl_8036E548._2D94[i + 0x103]._26 = 0;
        lbl_8036E548._2D94[i + 0x10A]._26 = 0;
        if (g_Minigame.wallBallWalls[i]._28 == 0) {
            continue;
        } else if (g_Minigame.wallBallWalls[i]._28 == 4) {
            id = i + 0xFC + (wall->coinGenerationCategory == 2) * 7;
            if (wall->coinGenerationCategory == 2) {
                if (g_Minigame.wallBall_hitNoteBlock == 1) {
                    pos.x = wall->_0.x;
                    pos.y = g_Ball.AtBat_Contact_BallPos.y;
                    pos.z = wall->_0.z;
                    fn_3_11A38C(id, 3);
                    fn_3_151710((struct UnkModelRef3880*)&lbl_8036E548._0068->_34[id], &pos);
                    fn_3_90064(0x2EB);
                } else {
                    setAnim(&lbl_8036E548._0068->_34[id], lbl_3_common_bss_32724._70, wall->coinGenerationCategory);
                    fn_3_90064(0x2EC);
                }
            } else if (wall->coinGenerationCategory == 0) {
                setAnim(&lbl_8036E548._0068->_34[id], lbl_3_common_bss_32724._70, wall->coinGenerationCategory);
                fn_3_90064(0x2E2);
            } else {
                if (wall->coinGenerationCategory == 1) {
                    big = TRUE;
                }
                fn_3_90064(0x2FF);
            }
            fn_3_14C348((Vec*)&wall->_0, big);
            if (big) {
                wall->_28 = 0;
                continue;
            }
            wall->_28 = 5;
        } else if (g_Minigame.wallBallWalls[i]._28 == 5) {
            id = i + 0xFC + (wall->coinGenerationCategory == 2) * 7;
            frame = fn_3_11A350(id);
            if (frame < (lbl_3_data_22634[wall->coinGenerationCategory] >> 1) && frame % 2 == 0) {
                model = lbl_8036E548._0068->_34[id]._00;
                for (j = 0; j < model->_06; j++) {
                    scroll = model->_18[j]->_E8;
                    if (scroll != NULL) {
                        scroll->_00 += scroll->_08;
                    }
                }
                continue;
            }
        } else {
            if (wall->coinGenerationCategory == 0) {
                if (wall->_24 > lbl_3_data_21654[wall->coinGenerationCategory + 4] / 2) {
                    id = i + 0xED;
                } else {
                    id = 0xFB;
                }
            } else if (wall->coinGenerationCategory == 1) {
                id = i + 0xF4;
            } else {
                id = i + 0x10A;
                fn_3_1666B0((Vec*)&wall->_0);
            }
        }
        obj = &lbl_8036E548._2D94[id];
        obj->_26 = 1;
        obj->_04.x = wall->_0.x;
        obj->_04.y = -wall->_0.y;
        obj->_04.z = wall->_0.z;
        obj->_10.x = 0.0f;
        obj->_10.y = 0.0f;
        obj->_10.z = 0.0f;
        obj->_10.x = wall->_18;
        fn_8001D0D0(id, 1.75f);
        if (-obj->_04.y <= lbl_3_data_21520[0][7].y && wall->_28 < 4) {
            shadow = &lbl_8036E548._2D94[i + 0xE6];
            shadow->_26 = 1;
            shadow->_04.x = obj->_04.x;
            shadow->_04.y = -obj->_04.y;
            shadow->_04.z = obj->_04.z;
            shadow->_04.y = -0.03f;
            shadow->_10.x = 0.0f;
            shadow->_10.y = 0.0f;
            shadow->_10.z = 0.0f;
            fn_8001D0D0(i + 0xE6, 1.75f * (1.0f - -obj->_04.y / lbl_3_data_21520[0][7].y));
        }
    }
}

// .text:0x0011A38C size:0x7C mapped:0x80759420
void fn_3_11A38C(s32 i, u16 frame) {
    UnkActor3310* actor = &lbl_8036E548._0068->_34[i];
    void* anim = lbl_3_common_bss_32724._70;

    setAnim(actor, anim, frame);
}

// .text:0x0011A350 size:0x3C mapped:0x807593E4
u32 fn_3_11A350(s32 i) {
    return fn_800B4A94(lbl_8036E548._0068->_34[i]._00);
}

// .text:0x0011A210 size:0x140 mapped:0x807592A4
void fn_3_11A210(void) {
    UnkObj3310* coin;
    UnkObj3310* shadow;
    s32 i;

    for (i = 0; i < 100; i++) {
        coin = &lbl_8036E548._2D94[i + 0x82];
        coin->_26 = 0;
        coin->_00 = NULL;
        shadow = &lbl_8036E548._2D94[i];
        shadow->_26 = 0;
        shadow->_00 = NULL;
        if (g_Minigame.wallBall_coinsVisibleInd[i]) {
            coin->_26 = 1;
            coin->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
            coin->_04.y = -g_Minigame.wallBall_coinCoordinates[i].y;
            coin->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
            fn_8001D0D0(i + 0x82, 1.75f);
            if (g_Minigame.wallBall_coinsVisibleFrameCounter[i] <= 1) {
                coin->_10.y = RandomF32_Game_Range(-3.1415927f, 3.1415927f);
            } else {
                coin->_10.y = fn_3_9FEA8(0.05f + coin->_10.y);
            }
            shadow->_26 = 1;
            shadow->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
            shadow->_04.y = -0.05f;
            shadow->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
            fn_8001D0D0(i, 4.325f);
        }
    }
}

// .text:0x0011A20C size:0x4 mapped:0x807592A0
void fn_3_11A20C(void) {
    return;
}

// .text:0x00119F6C size:0x2A0 mapped:0x80759000
void fn_3_119F6C(void) {
    UnkObj3310* obj;
    UnkObj3310* exploded;
    UnkObj3310* bombObj;
    BB_barrelStruct* barrel;
    s32 i;
    u8 bomb = FALSE;
    UnkModelSet3310* model;
    u32 j;
    UnkTexScroll3310* scroll;
    u32 frame;
    UnkActor3310* actor;

    bombObj = &lbl_8036E548._2D94[0xF];
    bombObj->_26 = 0;
    for (i = 0; i < 15; i++) {
        exploded = &lbl_8036E548._2D94[i + 0x10];
        barrel = &g_Minigame.barrels[i];
        obj = &lbl_8036E548._2D94[i];
        exploded->_26 = 0;
        obj->_26 = 0;
        if (g_Minigame.barrels[i].barrelState == 0) {
            continue;
        }
        if (g_Minigame.barrels[i].barrelState == 4) {
            obj = exploded;
            if (barrel->animationCounter == 0) {
                setAnim(&lbl_8036E548._0068->_34[i + 0x10], lbl_3_common_bss_32724._74, 0);
                fn_3_14DC80(i);
                fn_3_90064(0x2E3);
            }
            actor = &lbl_8036E548._0068->_34[i + 0x10];
            frame = fn_800B4A94(actor->_00);
            if (frame <= lbl_3_data_2263F) {
                if (!(frame & 1)) {
                    model = lbl_8036E548._0068->_34[i + 0x10]._00;
                    for (j = 0; j < model->_06; j++) {
                        scroll = model->_18[j]->_E8;
                        if (scroll != NULL) {
                            scroll->_00 += scroll->_08;
                        }
                    }
                    exploded->_26 = 0;
                    continue;
                } else if (frame == 0) {
                    fn_3_14CB28(i);
                }
            }
        } else if (barrel->barrelColour == 3 && i == g_Minigame.bB_bombBarrelID) {
            bomb = TRUE;
            obj = bombObj;
        }
        obj->_26 = 1;
        obj->_04.x = barrel->currentPos.x;
        obj->_04.y = -barrel->currentPos.y;
        obj->_04.z = barrel->currentPos.z;
        obj->_10.x = 0.0f;
        obj->_10.y = 0.0f;
        obj->_10.z = 0.0f;
        if (bomb) {
            fn_8001D0D0(0xF, 0.75f);
        } else {
            fn_8001D0D0(i, 0.75f);
        }
        if (bomb) {
            bomb = FALSE;
            obj->_00 = fn_3_119E30;
        } else if (barrel->barrelState != 4) {
            obj->_00 = fn_3_119EE0;
        } else {
            obj->_00 = NULL;
        }
    }
}

// .text:0x00119EE0 size:0x8C mapped:0x80758F74
// 82.09%: the target loads the model with `addi r0,table,0x34; lwzx r3,i*0x90,r0`; the spellings
// tried give `lwz 0x34(table + i*0x90)` or add 0x34 to the index instead.
void fn_3_119EE0(s32 i) {
    UnkAnimCtrl3310* ctrl = lbl_8036E548._0068->_34[i]._00->_18[0]->_14->_08;

    ctrl->_0C->_20 = lbl_3_data_22638[g_Minigame.barrels[i].barrelColour] * 3;
    ctrl->_0C->_40 = lbl_3_data_22638[g_Minigame.barrels[i].barrelColour] * 3 + 1;
    ctrl->_0C->_60 = lbl_3_data_22638[g_Minigame.barrels[i].barrelColour] * 3 + 2;
}

// .text:0x00119E30 size:0xB0 mapped:0x80758EC4
// 92.61%: the target loads the model with `addi r0,table,0x34; lwzx r3,i*0x90,r0`; the spellings
// tried give `lwz 0x34(table + i*0x90)` or add 0x34 to the index instead.
void fn_3_119E30(s32 i) {
    UnkAnimCtrl3310* ctrl;

    if (g_Minigame.barrels[g_Minigame.bB_bombBarrelID].animationCounter % lbl_3_data_2263E == 0) {
        ctrl = lbl_8036E548._0068->_34[i]._00->_18[0]->_14->_08;
        ctrl->_0C->_20 = !lbl_3_data_2263C[ctrl->_0C->_20];
        ctrl->_0C->_40 = !lbl_3_data_2263C[ctrl->_0C->_40];
        ctrl->_0C->_60 = !lbl_3_data_2263C[ctrl->_0C->_60];
    }
}

// .text:0x00119D34 size:0xFC mapped:0x80758DC8
void fn_3_119D34(void) {
    UnkObj3310* obj = &lbl_8036E548._2D94[0x1F];

    obj->_26 = 1;
    fn_3_11A92C(obj, 0x1F);
    if (lbl_80366158._28 == 0 && g_GameLogic.gameStatus == GAME_STATUS_AT_BAT &&
        g_Pitcher.pitchTotalTimeCounter == lbl_3_data_217A4[7]) {
        fn_3_119C34();
        fn_3_90064(0x2E6);
    }
}

// .text:0x00119D28 size:0xC mapped:0x80758DBC
f32 fn_3_119D28(void) {
    return lbl_3_data_2262C;
}

// .text:0x00119CA8 size:0x80 mapped:0x80758D3C
void fn_3_119CA8(s32 i) {
    UnkActor3310* actor = &lbl_8036E548._0068->_34[i];
    void* anim = lbl_3_common_bss_32724._74;

    setAnim(actor, anim, 0);
}

// .text:0x00119C34 size:0x74 mapped:0x80758CC8
void fn_3_119C34(void) {
    UnkActor3310* actor = &lbl_8036E548._0068->_34[31];
    void* anim = lbl_3_common_bss_32724._74;

    setAnim(actor, anim, 1);
}

// .text:0x00119934 size:0x300 mapped:0x807589C8
void fn_3_119934(void) {
    UnkObj3310* obj;
    s32 i;
    UnkObj3310* special;
    s32 kind;
    u8 state;
    Vec dir;
    f32 angle;

    special = &lbl_8036E548._2D94[0xA5];
    special->_26 = 0;
    for (i = 0; i < 15; i++) {
        obj = &lbl_8036E548._2D94[i + 0x82];
        obj->_26 = 0;
        state = g_Minigame.wallBall_coinsVisibleInd[i];
        kind = g_Minigame._1B1A[state - 1] - 2;
        if (kind == 2) {
            if (state >= 1 && state <= 6) {
                special->_26 = 1;
                special->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
                special->_04.y = g_Minigame.wallBall_coinCoordinates[i].y;
                special->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
                fn_8001D0D0(0xA5, lbl_3_data_22650[kind]);
                special->_10.y += 0.005f;
                if (special->_10.y > 3.1415927f) {
                    special->_10.y -= 6.2831855f;
                }
            }
        } else if (state >= 1 && state <= 6) {
            obj->_26 = 1;
            obj->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
            obj->_04.y = g_Minigame.wallBall_coinCoordinates[i].y;
            obj->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
            fn_8001D0D0(i + 0x82, lbl_3_data_22650[kind]);
            obj->_10.y += 0.005f;
            if (obj->_10.y > 3.1415927f) {
                obj->_10.y -= 6.2831855f;
            }
        }
    }
    for (i = 15; i < 35; i++) {
        obj = &lbl_8036E548._2D94[i + 0x82];
        obj->_26 = 0;
        if (g_Minigame.turnOverStatus == 0 && g_Minigame.wallBall_coinsVisibleInd[i] == 1) {
            obj->_26 = 1;
            obj->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
            obj->_04.y = -g_Minigame.wallBall_coinCoordinates[i].y;
            obj->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
            fn_8001D0D0(i + 0x82, 5.0f);
            if (g_Minigame.wallBall_coinsVisibleFrameCounter[i] == 0) {
                obj->_10.x = RandomF32_Game_Range(-3.1415927f, 3.1415927f);
                memcpy(&dir, &g_Minigame.wallBall_coinVelocity[i], sizeof(Vec));
                dir.y = 0.0f;
                PSVECNormalize(&dir, &dir);
                angle = acosf_kludge(dir.x);
                if (dir.z < 0.0f) {
                    angle = 6.2831855f - angle;
                }
                obj->_10.y = angle;
            } else if (lbl_80366158._28 == 0) {
                memcpy(&dir, &g_Minigame.wallBall_coinVelocity[i], sizeof(Vec));
                dir.y = 0.0f;
                obj->_10.x += (0.05f * PSVECMag(&dir)) / lbl_3_data_2188C[3];
            }
        }
    }
}

// .text:0x00119878 size:0xBC mapped:0x8075890C
void fn_3_119878(void) {
    MiniGameStruct* mg = &g_Minigame;
    UnkObj3310* obj = &lbl_8036E548._2D94[0xA6];
    obj->_26 = 0;
    obj->_00 = NULL;
    if (mg->_CCE[0] != 0 &&
        (mg->_CCC > 60 || mg->_CCC % 2 != 0 || mg->_1B19 == 2 || mg->_1B19 == 3)) {
        obj->_26 = 1;
        obj->_00 = fn_3_11741C;
        obj->_04.x = mg->_CB0;
        obj->_04.y = -mg->_CB4;
        obj->_04.z = mg->_CB8;
        fn_8001D0D0(0xA6, 3.5f);
    }
}

// .text:0x00119854 size:0x24 mapped:0x807588E8
f32 fn_3_119854(u8 index) {
    if (index > 2) {
        index = 2;
    }
    return lbl_3_data_22650[index];
}

// .text:0x001194FC size:0x358 mapped:0x80758590
void fn_3_1194FC(void) {
    Vec dir;
    Vec fwd = { 0.0f, 0.0f, 1.0f };
    UnkObj3310* obj;
    UnkObj3310* alt;
    UnkObj3310* shadow;
    s32 i;
    u8 state;
    s32 base;
    f32 angle;
    f32 scale;

    for (i = 0; i < 50; i++) {
        obj = &lbl_8036E548._2D94[i + 0x85];
        obj->_26 = 0;
        obj->_00 = NULL;
        alt = &lbl_8036E548._2D94[i + 0xB7];
        alt->_26 = 0;
        alt->_00 = NULL;
        shadow = &lbl_8036E548._2D94[i + 0x28];
        shadow->_26 = 0;
        shadow->_00 = NULL;
        state = g_Minigame.wallBall_coinsVisibleInd[i];
        if (state != 0 && state != 3 && state != 4) {
            if (g_Minigame._1B84[i] == 5) {
                alt->_00 = NULL;
                obj = alt;
                base = 0xB7;
            } else {
                base = 0x85;
                obj->_00 = fn_3_1194AC;
            }
            obj->_26 = 1;
            obj->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
            obj->_04.y = -g_Minigame.wallBall_coinCoordinates[i].y;
            obj->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
            if (g_Minigame.wallBall_coinsVisibleInd[i] == 2) {
                scale = lbl_3_data_22660[0] - (g_Minigame._1C4C[i] * (lbl_3_data_22660[0] - lbl_3_data_22668)) / lbl_3_data_2266C;
                if (lbl_80366158._28 == 0) {
                    fn_8001D110(base + i, lbl_3_data_22660[0], scale, lbl_3_data_22660[0]);
                    if ((g_Minigame._1C4C[i] += -2 * g_Minigame._1C1A[i] + 1) >= 60) {
                        g_Minigame._1C1A[i] = g_Minigame._1C1A[i] == 0;
                    }
                    g_Minigame._1C4C[i] += -2 * g_Minigame._1C1A[i] + 1;
                }
                obj->_10.x = 0.0f;
                obj->_10.y = 0.0f;
                obj->_10.z = 0.0f;
                if (g_Minigame._1B84[i] == 5) {
                    obj->_04.y -= 0.5f;
                }
            } else {
                fn_8001D0D0(base + i, lbl_3_data_22660[0]);
                if (g_Minigame.wallBall_coinsVisibleInd[i] != 6) {
                    dir.x = g_Minigame.wallBall_coinVelocity[i].x;
                    dir.y = 0.0f;
                    dir.z = g_Minigame.wallBall_coinVelocity[i].z;
                    PSVECNormalize(&dir, &dir);
                    angle = acosf_kludge(PSVECDotProduct(&fwd, &dir));
                    if (dir.x < 0.0f) {
                        angle = 6.2831855f - angle;
                    }
                    if (lbl_80366158._28 == 0) {
                        obj->_10.y = angle;
                        obj->_10.x += -0.17453292f;
                    }
                }
                if (g_Minigame._1B84[i] == 5 && g_Minigame.wallBall_coinsVisibleFrameCounter[i] == 1) {
                    fn_3_15521C(i, &obj->_04, &obj->_10);
                }
                if (g_Minigame._1B84[i] == 5) {
                    obj->_00 = fn_3_119468;
                }
                shadow->_26 = 1;
                shadow->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
                shadow->_04.y = -0.05f;
                shadow->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
                fn_8001D0D0(i + 0x28, lbl_3_data_22660[1]);
            }
        }
    }
}

// .text:0x001194AC size:0x50 mapped:0x80758540
// 68.00%: the target loads the model with `addi r0,table,0x34; lwzx r3,i*0x90,r0`; the spellings
// tried give `lwz 0x34(table + i*0x90)` or add 0x34 to the index instead.
void fn_3_1194AC(s32 i) {
    lbl_8036E548._0068->_34[i]._00->_18[0]->_14->_08->_0C->_20 = lbl_3_data_2265C[MG._1AFF[i]];
}

// .text:0x00119468 size:0x44 mapped:0x807584FC
void fn_3_119468(s32 i) {
    UnkModelSet3310* model = lbl_8036E548._0068->_34[i]._00;
    if (model->_98 & 9) {
        fn_3_14225C();
    }
}

// .text:0x001192B8 size:0x1B0 mapped:0x8075834C
// 91.03%: the int-to-float conversions of _1A and lbl_3_data_21E68[6] and the loads
// of the two scale rows are scheduled in another order.
void fn_3_1192B8(void) {
    UnkObj3310* obj;
    s32 i;
    s32 id;
    f32 t;
    f32 scale;

    for (i = 0; i < 3; i++) {
        id = i + 0x82;
        obj = &lbl_8036E548._2D94[id];
        obj->_26 = 0;
        if (MG._0000[i]._2A != 0) {
            obj->_26 = 1;
            obj->_04.x = MG._0000[i].pos.x;
            obj->_04.y = -MG._0000[i].pos.y;
            obj->_04.z = MG._0000[i].pos.z;
            if (MG._0000[i]._2A != 3) {
                fn_8001D0D0(id, lbl_3_data_22678[0][MG._0000[i]._2B]);
            } else {
                t = (f32)MG._0000[i]._1A / (f32)lbl_3_data_21E68[6];
                scale = (1.0f - t) * lbl_3_data_22678[0][MG._0000[i]._2B] + lbl_3_data_22678[1][MG._0000[i]._2B] * t;
                fn_8001D0D0(id, scale);
            }
            if (MG._0000[i]._2B == 0) {
                obj->_10.y = MG._0000[i].rot.y;
                obj->_10.x = 0.0f;
                obj->_10.z = 0.0f;
            } else {
                obj->_10.y = lbl_3_data_22688[i];
            }
            if (MG._0000[i]._2A == 4 && MG._0000[i]._1C <= 0 && (MG._0000[i]._1A & 1)) {
                obj->_26 = 0;
            }
            obj->_00 = fn_3_11897C;
            fn_3_118B18(i);
        }
    }
}

// .text:0x00118B18 size:0x7A0 mapped:0x80757BAC
// 92.53%: the target saves r27-r31 and keeps i * 0x38 in r29 to address the entry again
// for the final rot stores; the base reuses the entry pointer, so one register fewer.
void fn_3_118B18(s32 i) {
    UnkMgEntry3310* entry = &MG._0000[i];
    s16 frame;

    entry->_28++;
    if (entry->_2A == 1) {
        if (entry->_1A <= 1) {
            fn_3_1189C8(i, 2, 0, 0, 0);
            fn_8001D0D0(i + 0x82, 0.01f);
        } else {
            fn_8001D0D0(i + 0x82, LinearInterpolateToNewRange(entry->_1A, 0.0f, lbl_3_data_21E68[5],
                                                              lbl_3_data_22678[1][entry->_2B],
                                                              lbl_3_data_22678[0][entry->_2B]));
        }
        if (entry->_1C == 1) {
            fn_3_1189C8(i, 0, 0, 6, 1);
        }
    } else if (entry->_2A == 4) {
        if (entry->_1A <= 1) {
            fn_3_1189C8(i, 4, 0, 0, 0);
        }
    } else if (entry->_1E == 2) {
        if (entry->_2B == 0) {
            fn_3_1189C8(i, 1, 0, 0, 0);
        } else {
            fn_3_1189C8(i, 5, 0, 0, 0);
        }
    } else if (entry->_1E == lbl_3_data_21E68[7]) {
        if (entry->_33 != 0) {
            fn_3_1189C8(i, 0, 0, 6, 1);
        }
    } else {
        if (entry->_2E != 0 && (entry->_26 == 1 || entry->_2B != 0)) {
            frame = lbl_3_data_226B8[0] - lbl_3_data_21E68[13] - 1;
            if (entry->_2B == 0) {
                fn_3_143770(entry);
            }
            fn_3_1189C8(i, 3, frame, 2, 0);
        }
        if (entry->_33 == 3 && entry->_28 == lbl_3_data_226B8[1] - lbl_3_data_226AC[3]) {
            fn_3_1189C8(i, 0, 0, 6, 1);
            MG._0000[i].rot.z = 0.0f;
            MG._0000[i].rot.x = 0.0f;
            MG._0000[i].rot.y = lbl_3_data_22688[i];
        }
    }
}

// .text:0x001189C8 size:0x150 mapped:0x80757A5C
void fn_3_1189C8(s32 i, s32 anim, s32 frame, s32 duration, u8 loop) {
    UnkMgEntry3310* entry = &MG._0000[i];
    UnkActor3310* actor = &lbl_8036E548._0068->_34[i + 0x82];
    f32 rate = 0.0f;
    void* data;

    if (duration != 0) {
        rate = 1.0f / duration;
    }
    data = lbl_3_common_bss_32724._78;
    actor->_04 = data;
    actor->_0E = anim;
    actor->_5C = 0.0f;
    actor->_58 = 1;
    actor->_59 = data != NULL;
    actor->_5A = data != NULL;
    actor->_60 = rate;
    actor->_54 = lbl_3_data_22694[anim];
    actor->_5A = 1;
    actor->_5C = frame + lbl_3_data_226AC[anim];
    actor->_59 = 1;
    if (loop) {
        actor->_5B = 3;
    } else {
        actor->_5B = 2;
    }
    entry->_33 = anim;
    entry->_28 = frame;
}

// .text:0x0011897C size:0x4C mapped:0x80757A10
// 65.74%: the target loads the model with `addi r0,table,0x34; lwzx r3,i*0x90,r0`; the spellings
// tried give `lwz 0x34(table + i*0x90)` or add 0x34 to the index instead.
void fn_3_11897C(s32 i) {
    lbl_8036E548._0068->_34[i]._00->_14->_08->_0C->_20 = lbl_3_data_22670[MG._0000[i - 0x82]._2C];
}

// .text:0x0011887C size:0x100 mapped:0x80757910
void fn_3_11887C(void) {
    UnkObj3310* obj;
    s32 i;
    s32 id;

    for (i = 0; i < 7; i++) {
        id = i + 0xE9;
        obj = &lbl_8036E548._2D94[id];
        obj->_26 = 1;
        if (i < 4) {
            obj->_04.x = lbl_3_data_21B94[i].x;
            obj->_04.y = -lbl_3_data_21B94[i].y;
            obj->_04.z = lbl_3_data_21B94[i].z;
            obj->_04.y = 0.0f;
            fn_8001D110(id, lbl_3_data_226C4[2], lbl_3_data_226C4[3], lbl_3_data_226C4[2]);
            obj->_00 = fn_3_11881C;
        } else {
            obj->_04.x = lbl_3_data_21BC4[i - 4].pos.x;
            obj->_04.y = -lbl_3_data_21BC4[i - 4].pos.y;
            obj->_04.z = lbl_3_data_21BC4[i - 4].pos.z;
            fn_8001D110(id, lbl_3_data_226C4[0], lbl_3_data_226C4[1], lbl_3_data_226C4[0]);
            obj->_00 = fn_3_11881C;
        }
    }
}

// .text:0x0011881C size:0x60 mapped:0x807578B0
// 69.96%: the target loads the model with `addi r0,table,0x34; lwzx r3,i*0x90,r0`; the spellings
// tried give `lwz 0x34(table + i*0x90)` or add 0x34 to the index instead.
void fn_3_11881C(s32 i) {
    u8 v;
    if (i - 0xE9 < 4) {
        v = lbl_3_data_226BC[i - 0xE9];
    } else {
        v = lbl_3_data_226BC[4];
    }
    lbl_8036E548._0068->_34[i]._00->_18[0]->_14->_08->_0C->_20 = v;
}

// .text:0x0011874C size:0xD0 mapped:0x807577E0
void fn_3_11874C(void) {
    s32 i;
    UnkObj3310* obj;
    Vec* pos;

    if (g_GameLogic.secondaryGameMode != SECONDARY_GAME_MODE_STAR_DASH) {
        for (i = 0; i < 40; i++) {
            obj = &lbl_8036E548._2D94[i];
            pos = &MG._00A8[i].pos;
            obj->_26 = 0;
            obj->_00 = NULL;
            if (MG._00A8[i].active) {
                obj->_26 = 1;
                obj->_04.x = pos->x;
                obj->_04.z = pos->z;
                obj->_04.y = -0.01f;
                fn_8001D110(i, lbl_3_data_226D4[1], 1.0f, lbl_3_data_226D4[1]);
            }
        }
    }
}

// .text:0x00118614 size:0x138 mapped:0x807576A8
void fn_3_118614(void) {
    UnkTask3310* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_3_data_69D0);
    for (i = 0; i < 40; i++) {
        lbl_80371C30[task->_14 + i]._00->_5C = 0x20000;
    }
    ((UnkTask3310*)lbl_803CC1B8)->_00 = fn_3_118508;
}

// .text:0x00118508 size:0x10C mapped:0x8075759C
void fn_3_118508(void) {
    UnkTask3310* task = lbl_803CC1B8;
    s32 i;

    if (g_GameLogic.gameStatus == GAME_STATUS_TRANSITION_MINIGAME_POSTGAME) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        return;
    }
    for (i = 0; i < 40; i++) {
        if (!MG._00A8[i].active) {
            lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
        } else {
            lbl_80371C30[task->_14 + i]._00->_54 |= 2;
            lbl_80371C30[task->_14 + i]._00->_48.x = MG._00A8[i].pos.x;
            lbl_80371C30[task->_14 + i]._00->_48.y = -MG._00A8[i].pos.y;
            lbl_80371C30[task->_14 + i]._00->_48.z = MG._00A8[i].pos.z;
        }
    }
}

// .text:0x001183FC size:0x10C mapped:0x80757490
void fn_3_1183FC(void) {
    s32 i;
    UnkObj3310* obj;

    for (i = 0; i < 4; i++) {
        obj = &lbl_8036E548._2D94[i + 0xF0];
        obj->_04.x = lbl_3_data_21B94[i].x;
        obj->_04.y = -lbl_3_data_21B94[i].y;
        obj->_04.z = lbl_3_data_21B94[i].z;
        obj->_04.y = 0.0f;
        obj->_04.z -= lbl_3_data_226DC;
        obj->_26 = 1;
    }
}

// .text:0x00118358 size:0xA4 mapped:0x807573EC
void fn_3_118358(s32 i, Vec* out) {
    UnkActor3310* actor = &lbl_8036E548._0068->_34[i + 0x82];
    UnkModel3310* model = actor->_00->_18[17];
    if (i < 0 || i > 2) {
        return;
    }
    if (out != NULL) {
        memset(out, 0, sizeof(Vec));
        PSMTXMultVec(*model->_EC, out, out);
        out->y *= -1.0f;
    }
}

// .text:0x00118164 size:0x1F4 mapped:0x807571F8
void fn_3_118164(void) {
    UnkObj3310* coin;
    UnkObj3310* shadow;
    s32 i;
    s32 id;

    for (i = 0; i < 100; i++) {
        id = i + 0x82;
        coin = &lbl_8036E548._2D94[id];
        coin->_26 = 0;
        shadow = &lbl_8036E548._2D94[i];
        shadow->_26 = 0;
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 1 || g_Minigame.wallBall_coinsVisibleInd[i] == 3) {
            coin->_26 = 1;
            coin->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
            coin->_04.y = -g_Minigame.wallBall_coinCoordinates[i].y;
            coin->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
            coin->_10.x = 0.0f;
            coin->_10.z = 0.0f;
            fn_8001D0D0(id, 2.0f);
            if (g_Minigame.wallBall_coinsVisibleFrameCounter[i] <= 1) {
                coin->_10.y = RandomF32_Game_Range(-3.1415927f, 3.1415927f);
            } else if (g_Minigame.wallBall_coinsVisibleInd[i] == 1) {
                coin->_10.y = fn_3_9FEA8(0.05f + coin->_10.y);
            } else {
                coin->_10.y = fn_3_9FEA8(10.0f + coin->_10.y);
            }
            shadow->_26 = 1;
            shadow->_00 = NULL;
            shadow->_04.x = g_Minigame.wallBall_coinCoordinates[i].x;
            shadow->_04.y = -0.05f;
            shadow->_04.z = g_Minigame.wallBall_coinCoordinates[i].z;
            fn_8001D0D0(i, 5.0f);
            if (g_Minigame.wallBall_coinsVisibleFrameCounter[i] > lbl_3_data_21A04[3] - 180 &&
                g_Minigame.wallBall_coinsVisibleInd[i] == 1 && (g_d_GameSettings.FrameCountWhileNotAtMainMenu & 1)) {
                coin->_26 = 0;
                shadow->_26 = 0;
            }
            if (g_Minigame.wallBall_coinsVisibleInd[i] == 3 && (g_d_GameSettings.FrameCountWhileNotAtMainMenu & 1)) {
                coin->_26 = 0;
                shadow->_26 = 0;
            }
        }
    }
}

// .text:0x001180A4 size:0xC0 mapped:0x80757138
void fn_3_1180A4(void) {
    UnkObj3310* objs = lbl_8036E548._2D94;

    objs[0x64]._26 = 0;
    objs[0xE6]._26 = 0;
    if (g_Minigame._B6C._40[0] == 1) {
        objs[0xE6]._26 = 1;
        objs[0xE6]._04.x = g_Minigame._B6C._0.x;
        objs[0xE6]._04.y = -g_Minigame._B6C._0.y;
        objs[0xE6]._04.z = g_Minigame._B6C._0.z;
        objs[0xE6]._10.x = 0.0f;
        objs[0xE6]._10.y = 0.0f;
        objs[0xE6]._10.z = 0.0f;
        objs[0x64]._26 = 1;
        objs[0x64]._00 = NULL;
        objs[0x64]._04.x = g_Minigame._B6C._0.x;
        objs[0x64]._04.y = -0.05f;
        objs[0x64]._04.z = g_Minigame._B6C._0.z;
        fn_8001D0D0(0x64, 10.0f);
    }
}

// .text:0x00117FC8 size:0xDC mapped:0x8075705C
void fn_3_117FC8(void) {
    UnkObj3310* obj = &lbl_8036E548._2D94[0xE8];

    obj->_26 = 0;
    lbl_8036E548._2D94[0x65]._26 = 0;
    if (g_Minigame._72A) {
        obj->_26 = 1;
        obj->_04.x = g_Minigame._6E8;
        obj->_04.y = -g_Minigame._6EC;
        obj->_04.z = g_Minigame._6F0;
        fn_8001D0D0(0xE8, 3.0f);
        if (g_Minigame._724 == 0) {
            obj->_10.y = RandomF32_Game_Range(-3.1415927f, 3.1415927f);
        } else {
            obj->_10.y = fn_3_9FEA8(0.1f + obj->_10.y);
        }
        obj->_00 = fn_3_117B78;
    }
}

// .text:0x00117B78 size:0x450 mapped:0x80756C0C
// 94.91%: the quad's corner sums and stores are scheduled in another order, and the uv
// table and object pointer get other registers.
void fn_3_117B78(s32 i) {
    UnkObj3310* obj = &lbl_8036E548._2D94[i];
    u32 j;
    f32 size = 1.5f;
    GXColor color;
    Vec tmp;
    f32 uv[4][2] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
    Vec quad[4];

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
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
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);

    quad[0].x = quad[3].x = -size;
    quad[0].z = quad[1].z = size;
    quad[1].x = quad[2].x = size;
    quad[2].z = quad[3].z = -size;
    for (j = 0; j < 4; j++) {
        memcpy(&tmp, &quad[j], sizeof(Vec));
        quad[j].x = tmp.x * cosf_kludge(-obj->_10.y) + tmp.z * -sinf_kludge(-obj->_10.y);
        quad[j].z = tmp.x * sinf_kludge(-obj->_10.y) + tmp.z * cosf_kludge(-obj->_10.y);
    }
    quad[0].x += obj->_04.x;
    quad[1].x += obj->_04.x;
    quad[2].x += obj->_04.x;
    quad[3].x += obj->_04.x;
    quad[0].z += obj->_04.z;
    quad[1].z += obj->_04.z;
    quad[2].z += obj->_04.z;
    quad[3].z += obj->_04.z;
    quad[3].y = -0.060000002f;
    quad[2].y = -0.060000002f;
    quad[1].y = -0.060000002f;
    quad[0].y = -0.060000002f;
    color.r = color.g = color.b = 0;
    color.a = 155;
    GXLoadPosMtxImm(fn_80052768_getCamera(fn_8005268C())->view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetProjection(fn_80052768_getCamera(fn_8005268C())->proj, GX_PERSPECTIVE);
    fn_80033B58(lbl_3_common_bss_32724._6C, 0x14, 0, 0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (j = 0; j < 4; j++) {
        GXPosition3f32(quad[j].x, quad[j].y, quad[j].z);
        GXColor1u32(*(u32*)&color);
        GXTexCoord2f32(uv[j][0], uv[j][1]);
    }
}

// .text:0x00117AE4 size:0x94 mapped:0x80756B78
void fn_3_117AE4(void) {
    UnkObj3310* obj = &lbl_8036E548._2D94[0xE7];

    obj->_26 = 1;
    obj->_04.x = lbl_3_data_21A48.x;
    obj->_04.z = lbl_3_data_21A48.z;
    obj->_04.y = 0.0f;
    obj->_10.x = 0.0f;
    obj->_10.z = 0.0f;
    obj->_10.y = shortAngleToRad(0x1000 - g_Minigame._1D64[0]);
    fn_8001D0D0(0xE7, 3.0f);
}

// .text:0x001179EC size:0xF8 mapped:0x80756A80
void fn_3_1179EC(void) {
    UnkObj3310* obj;
    UnkMgMarker3310* marker;
    s32 id;
    u32 i;

    for (i = 0; i < 4; i++) {
        id = i + 0xE9;
        obj = &lbl_8036E548._2D94[id];
        marker = &MG._0BB0[i];
        obj->_26 = 0;
        obj->_00 = NULL;
        if (MG._0BB0[i].active) {
            obj->_26 = 1;
            obj->_04.x = marker->pos.x;
            obj->_04.y = -marker->pos.y;
            obj->_04.z = marker->pos.z;
            obj->_10.x = 0.017453292f * marker->rot.x;
            obj->_10.y = 0.017453292f * marker->rot.y;
            obj->_10.z = 0.017453292f * marker->rot.z;
            fn_8001D0D0(id, 2.5f);
            obj->_00 = fn_3_117588;
        }
    }
}

// .text:0x00117588 size:0x464 mapped:0x8075661C
// 97.60%: the quad corners and the scale terms are computed in another order and FPRs differ.
void fn_3_117588(s32 i) {
    GXColor color;
    f32 uv[4][2] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
    Vec quad[4];
    UnkObj3310* obj = &lbl_8036E548._2D94[i];
    UnkMgMarker3310* marker = &MG._0BB0[i - 0xE9];
    f32 scale = 2.5f * (1.0f - (-obj->_04.y * 0.5f) / lbl_3_data_21A64[0]);
    f32 hx;
    f32 hz;
    UnkModelSet3310* model;
    s32 frame;
    s32 j;
    u8 state;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
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
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);

    hx = 2.8f * scale * 0.5f;
    hz = 2.5f * scale * 0.5f;
    quad[0].x = quad[3].x = -hx + obj->_04.x;
    quad[1].x = quad[2].x = hx + obj->_04.x;
    quad[2].z = quad[3].z = -hz + obj->_04.z;
    quad[0].z = quad[1].z = hz + obj->_04.z;
    quad[0].y = quad[1].y = quad[2].y = quad[3].y = -0.060000002f;
    color.r = color.g = color.b = 0;
    color.a = 155;
    GXLoadPosMtxImm(fn_80052768_getCamera(fn_8005268C())->view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetProjection(fn_80052768_getCamera(fn_8005268C())->proj, GX_PERSPECTIVE);
    fn_80033B58(lbl_3_common_bss_32724._6C, 0x13, 0, 0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (j = 0; j < 4; j++) {
        GXPosition3f32(quad[j].x, quad[j].y, quad[j].z);
        GXColor1u32(*(u32*)&color);
        GXTexCoord2f32(uv[j][0], uv[j][1]);
    }
    state = marker->active;
    model = lbl_8036E548._0068->_34[i]._00;
    if (state == 1 || state == 5) {
        frame = 0;
    } else {
        frame = 1;
    }
    for (j = 0; j < model->_06; j++) {
        model->_18[j]->_14->_08->_0C->_20 = frame;
    }
}

// .text:0x00117494 size:0xF4 mapped:0x80756528
void fn_3_117494(void) {
    MiniGameStruct* mg = &g_Minigame;
    UnkObj3310* objs = lbl_8036E548._2D94;

    objs[0xED]._26 = 0;
    objs[0x65]._26 = 0;
    objs[0xED]._00 = NULL;
    if (mg->_CCE[0] != 0 && (mg->_CCC > 60 || mg->_CCC % 2 != 0)) {
        objs[0xED]._26 = 1;
        objs[0xED]._00 = fn_3_11741C;
        objs[0xED]._04.x = mg->_CB0;
        objs[0xED]._04.y = -mg->_CB4;
        objs[0xED]._04.z = mg->_CB8;
        fn_8001D0D0(0xED, 2.5f);
        objs[0x65]._26 = 1;
        objs[0x65]._04.x = mg->_CB0;
        objs[0x65]._04.y = -0.05f;
        objs[0x65]._04.z = mg->_CB8;
        fn_8001D0D0(0x65, 12.5f);
    }
}

// .text:0x0011741C size:0x78 mapped:0x807564B0
void fn_3_11741C(s32 i) {
    UnkModelSet3310* model = lbl_8036E548._0068->_34[i]._00;
    s32 frame = MG._0CCE == 1 ? 0 : 2;
    s32 j;

    for (j = 0; j < model->_06; j++) {
        model->_18[j]->_14->_08->_0C->_20 = frame;
    }
}

// .text:0x00116B74 size:0x8A8 mapped:0x80755C08
// 99.62%: only registers differ: in the inlined fn_3_117494 the target keeps the object
// table in r26 and &g_Minigame in r27, the base the reverse.
void fn_3_116B74(void) {
    switch (g_Minigame.GameMode_MiniGame) {
    case MINI_GAME_ID_BOBOMB_DERBY:
        fn_3_116B38();
        break;
    case MINI_GAME_ID_WALLBALL:
        fn_3_1169D0();
        break;
    case MINI_GAME_ID_BARREL_BATTER:
        fn_3_116B38();
        fn_3_119F6C();
        break;
    case MINI_GAME_ID_CHAINCHOMP_SPRINT:
        fn_3_119934();
        fn_3_117494();
        break;
    case MINI_GAME_ID_STAR_DASH:
        fn_3_118164();
        fn_3_117FC8();
        clearObjs();
        fn_3_1179EC();
        fn_3_117494();
        break;
    case MINI_GAME_ID_PIRANHA_PANIC:
        fn_3_1194FC();
        fn_3_116840();
        clearObjs();
        showPipes();
        break;
    }
}

// .text:0x00116B38 size:0x3C mapped:0x80755BCC
void fn_3_116B38(void) {
    UnkObj3310* obj;
    s32 i = 2;
    if (MG._1A2A == 3) {
        i = 31;
    }
    obj = &lbl_8036E548._2D94[i];
    obj->_26 = 0;
}

// .text:0x001169D0 size:0x168 mapped:0x80755A64
void fn_3_1169D0(void) {
    s32 i;

    lbl_8036E548._2D94[0xFB]._26 = 0;
    for (i = 0; i < 7; i++) {
        lbl_8036E548._2D94[i + 0xE6]._26 = 0;
        lbl_8036E548._2D94[i + 0xED]._26 = 0;
        lbl_8036E548._2D94[i + 0xF4]._26 = 0;
        lbl_8036E548._2D94[i + 0xFC]._26 = 0;
        lbl_8036E548._2D94[i + 0x103]._26 = 0;
        lbl_8036E548._2D94[i + 0x10A]._26 = 0;
    }
}

// .text:0x00116840 size:0x190 mapped:0x807558D4
void fn_3_116840(void) {
    s32 i;
    UnkObj3310* obj;

    for (i = 0; i < 3; i++) {
        obj = &lbl_8036E548._2D94[i + 0x82];
        obj->_26 = 0;
        if (MG._0000[i]._2A) {
            obj->_26 = 1;
            obj->_04.x = MG._0000[i].pos.x;
            obj->_04.y = -MG._0000[i].pos.y;
            obj->_04.z = MG._0000[i].pos.z;
            fn_8001D0D0(i + 0x82, lbl_3_data_22678[0][MG._0000[i]._2B]);
            obj->_10.y = lbl_3_data_22688[i];
            obj->_00 = fn_3_11897C;
            if (MG._0000[i]._1C == 1) {
                fn_3_1189C8(i, 0, 0, 6, 1);
                MG._0000[i]._1C++;
            }
        }
    }
}

// .text:0x0011678C size:0xB4 mapped:0x80755820
void fn_3_11678C(void) {
    UnkObj3310* obj;
    s32 i;

    for (i = 0; i < 7; i++) {
        obj = &lbl_8036E548._2D94[i + 0xE9];
        obj->_26 = 0;
        if (i >= 4) {
            obj->_26 = 1;
            obj->_04.x = lbl_3_data_21BC4[i - 4].pos.x;
            obj->_04.y = -lbl_3_data_21BC4[i - 4].pos.y;
            obj->_04.z = lbl_3_data_21BC4[i - 4].pos.z;
            fn_8001D110(i + 0xE9, lbl_3_data_226C4[0], lbl_3_data_226C4[1], lbl_3_data_226C4[0]);
            obj->_00 = fn_3_11881C;
        }
    }
}
