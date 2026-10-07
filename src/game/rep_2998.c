#include "game/rep_2998.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"
#include "Dolphin/rand.h"
#include "C3/control.h"
#include "C3/geoPalette.h"
#include "musyx/musyx.h"
#include "game/m_sound.h"
#include "game/rep_540.h"
#include "game/rep_1838.h"
#include "game/rep_23E8.h"
#include "game/rep_AC8.h"
#include "math.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0xEC];
    /* 0xEC */ MtxPtr _EC;
} Rep2998Bone;

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ DODisplayData* pal;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ Rep2998Bone** _18;
} Rep2998Actor;

typedef struct {
    /* 0x00 */ Rep2998Actor* _00;
    /* 0x04 */ u8 _04[0x54 - 0x04];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
} Rep2998Model;

typedef struct Rep2998Obj {
    /* 0x00 */ Control control;
    /* 0x3C */ u8 _3C[0x74 - 0x3C];
    /* 0x74 */ Rep2998Model* _74;
    /* 0x78 */ void* _78;
    /* 0x7C */ void (*_7C)(struct Rep2998Obj* obj);
    /* 0x80 */ void (*_80)(u32 idx);
    /* 0x84 */ void (*_84)(struct Rep2998Obj* obj);
    /* 0x88 */ u8 _88[0x8C - 0x88];
    /* 0x8C */ void* _8C;
    /* 0x90 */ u8 _90_7 : 1;
    /* 0x90 */ u8 _90_6 : 1;
    /* 0x90 */ u8 _90_5 : 1;
    /* 0x90 */ u8 _90_0 : 5;
    /* 0x91 */ u8 _91;
    /* 0x92 */ u8 _92;
    /* 0x93 */ u8 _93;
    /* 0x94 */ s16 _94;
    /* 0x96 */ s16 _96;
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B;
    /* 0x9C */ u8 _9C;
    /* 0x9D */ u8 _9D;
    /* 0x9E */ u8 _9E;
    /* 0x9F */ u8 _9F;
    /* 0xA0 */ Vec _A0;
    /* 0xAC */ void* _AC;
    /* 0xB0 */ f32 _B0;
    /* 0xB4 */ f32 _B4;
    /* 0xB8 */ f32 _B8;
    /* 0xBC */ f32 _BC;
    /* 0xC0 */ f32 _C0;
    /* 0xC4 */ u8 _C4;
    /* 0xC5 */ u8 _C5;
    /* 0xC6 */ u8 _C6;
    /* 0xC7 */ u8 _C7;
    /* 0xC8 */ u8 _C8;
    /* 0xC9 */ u8 _C9;
    /* 0xCA */ u8 _CA;
    /* 0xCB */ s8 _CB;
    /* 0xCC */ u8 _CC[0xE8 - 0xCC];
} Rep2998Obj; // size: 0xE8

typedef struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
} Rep2998Prop; // size: 0x1C

extern struct {
    /* 0x00 */ Rep2998Obj* _00;
    /* 0x04 */ u8* _04;
    /* 0x08 */ u8 _08[0x18 - 0x08];
    /* 0x18 */ void (*_18)(void);
    /* 0x1C */ void (*_1C)(void);
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32* _34;
    /* 0x38 */ u8 _38[0x3C - 0x38];
    /* 0x3C */ u32* _3C;
    /* 0x40 */ u16* _40;
    /* 0x44 */ u32* _44;
    /* 0x48 */ u8* _48;
    /* 0x4C */ u8 _4C[0x64 - 0x4C];
    /* 0x64 */ s16 _64;
    /* 0x66 */ s16 _66;
    /* 0x68 */ u8 _68[0x6D - 0x68];
    /* 0x6D */ u8 _6D;
} lbl_3_common_bss_350E4;

extern struct {
    /* 0x00 */ u8 _00[0x6C];
    /* 0x6C */ u8* _6C;
} lbl_8036E548;

extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];
extern Rep2998Prop lbl_3_data_18ED0[11];
extern u8 lbl_3_data_19004[0x14];

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void AnimateActorBones(Rep2998Actor* actor);
extern void fn_800B4A94(Rep2998Actor* actor);
extern void fn_800B4AFC(Rep2998Actor* actor, u8 flag);
extern void fn_800B4BC8(Rep2998Actor* actor, s32 arg1);
extern void fn_800B4C04(Rep2998Actor* actor, f32 speed);
extern f32 fn_800B4C40(Rep2998Actor* actor);
extern void fn_800B4CA0(Rep2998Actor* actor, f32 frame);

// rep_1D58.h declares these as void(void) placeholders
extern s16 fn_3_B7F70(s16 range);
extern s32 fn_3_B7FC8(u32 id, s32 arg1);
extern void fn_3_B8414(void* a, void* b);
extern void fn_3_B8464(MtxPtr m, void* arg1);
extern void fn_3_B8574(void);
extern void fn_3_B939C(void);
extern void fn_3_B97DC(void* model, void* anim);
extern void fn_3_B98E8(void* model);
extern void fn_3_B9D68(u8* types, s32 count, void** files, s32* indices);

// MWCC lays out .bss statics in reverse order of declaration
static void* lbl_3_bss_AE18[14];
static u8 lbl_3_bss_AE14;
static u8 lbl_3_bss_AE13;
static u8 lbl_3_bss_AE12;
static u8 lbl_3_bss_AE11;
static u8 lbl_3_bss_AE10;
static s32 lbl_3_bss_AE0C;
static s32 lbl_3_bss_AE08;
static s32 lbl_3_bss_AE04;
static u8 lbl_3_bss_AE01;
static u8 lbl_3_bss_AE00;

// .text:0x000E4FC4 size:0x8B8 mapped:0x80724058
void fn_3_E4FC4(void) {
    return;
}

// .text:0x000E4EF4 size:0xD0 mapped:0x80723F88
void fn_3_E4EF4(void) {
    return;
}

// .text:0x000E4CB0 size:0x244 mapped:0x80723D44
void fn_3_E4CB0(void) {
    return;
}

// .text:0x000E4BE8 size:0xC8 mapped:0x80723C7C
void* fn_3_E4BE8(s32 idx, MtxPtr mtx) {
    Rep2998Obj* obj;
    Mtx bone;

    obj = &lbl_3_common_bss_350E4._00[idx];
    CTRLBuildMatrix(&obj->control, mtx);
    if (obj->_9D == 0) {
        if (obj->_C8 == 0 || obj->_C4 == 0 || obj->_C4 == 5 || obj->_C4 == 4) {
            return NULL;
        }
        PSMTXCopy(obj->_74->_00->_18[16]->_EC, bone);
        PSMTXConcat(mtx, bone, mtx);
    }
    return lbl_3_common_bss_350E4._00[idx]._78;
}

// .text:0x000E4A38 size:0x1B0 mapped:0x80723ACC
void fn_3_E4A38(void) {
    return;
}

// .text:0x000E48D0 size:0x168 mapped:0x80723964
void fn_3_E48D0(Rep2998Obj* obj) {
    fn_3_E4658(obj);
    fn_3_E4554(obj);
    obj->_C5 = 0;
    obj->_C4 = 0;
    obj->_C7 = 0;
    obj->_C8 = 0;
    if (obj->_CA) {
        fn_3_65F4();
        obj->_CA = 0;
        obj->_C0 = 0.0f;
    }
}

// .text:0x000E4760 size:0x170 mapped:0x807237F4
void fn_3_E4760(Rep2998Obj* obj) {
    fn_3_E48D0(obj);
    obj->_C9 = 0;
}

// .text:0x000E4658 size:0x108 mapped:0x807236EC
void fn_3_E4658(Rep2998Obj* obj) {
    obj->control.type = 0;
    CTRLSetTranslation(&obj->control, lbl_3_data_18ED0[obj->_9C]._00.x, 0.24f + lbl_3_data_18ED0[obj->_9C]._00.y,
                       lbl_3_data_18ED0[obj->_9C]._00.z);
    PSVECScale(&lbl_3_data_18ED0[obj->_9C]._00, 1.0f, &obj->_A0);
    obj->_A0.y -= 0.24f;
    fn_3_E45F0(obj);
    fn_3_E45A8(obj);
}

// .text:0x000E45F0 size:0x68 mapped:0x80723684
void fn_3_E45F0(Rep2998Obj* obj) {
    CTRLSetRotation(&obj->control, 0.0f, lbl_3_data_18ED0[obj->_9C]._0C, 0.0f);
    obj->_B0 = lbl_3_data_18ED0[obj->_9C]._0C;
}

// .text:0x000E45A8 size:0x48 mapped:0x8072363C
void fn_3_E45A8(Rep2998Obj* obj) {
    CTRLSetScale(&obj->control, 0.2f, 0.2f, 0.2f);
    obj->_B4 = 0.2f;
}

// .text:0x000E4554 size:0x54 mapped:0x807235E8
void fn_3_E4554(Rep2998Obj* obj) {
    fn_3_E25D0(obj, 0);
}

// .text:0x000E3B88 size:0x9CC mapped:0x80722C1C
void fn_3_E3B88(void) {
    return;
}

// .text:0x000E3914 size:0x274 mapped:0x807229A8
void fn_3_E3914(void) {
    return;
}

// .text:0x000E3764 size:0x1B0 mapped:0x807227F8
void fn_3_E3764(void) {
    return;
}

// .text:0x000E3668 size:0xFC mapped:0x807226FC
void fn_3_E3668(void) {
    return;
}

// .text:0x000E3284 size:0x3E4 mapped:0x80722318
void fn_3_E3284(void) {
    return;
}

// .text:0x000E3044 size:0x240 mapped:0x807220D8
void fn_3_E3044(void) {
    return;
}

// .text:0x000E2F4C size:0xF8 mapped:0x80721FE0
void fn_3_E2F4C(void) {
    return;
}

// .text:0x000E2E78 size:0xD4 mapped:0x80721F0C
void fn_3_E2E78(Rep2998Obj* obj) {
    if (obj->_C5 == 0) {
        obj->_C8 = 0;
        obj->_C4 = 0;
    } else {
        obj->_B4 -= 1.0857142857142859 / obj->_C6;
        obj->_A0.y = -(1.2 * obj->_B4);
        CTRLSetTranslation(&obj->control, obj->_A0.x, -obj->_A0.y, obj->_A0.z);
        CTRLSetScale(&obj->control, obj->_B4, obj->_B4, obj->_B4);
        obj->_C5--;
    }
}

// .text:0x000E2B70 size:0x308 mapped:0x80721C04
void fn_3_E2B70(void) {
    return;
}

// .text:0x000E29B4 size:0x1BC mapped:0x80721A48
void fn_3_E29B4(void) {
    return;
}

// .text:0x000E28DC size:0xD8 mapped:0x80721970
BOOL fn_3_E28DC(Rep2998Obj* obj) {
    Vec pos = obj->_A0;
    Vec d;

    PSVECSubtract((Vec*)&g_Ball.AtBat_Contact_BallPos, &pos, &d);
    d.y = 0.0f;
    if (2.5 >= PSVECMag(&d)) {
        fn_3_E25D0(obj, 6);
        return TRUE;
    }
    return FALSE;
}

// .text:0x000E266C size:0x270 mapped:0x80721700
void fn_3_E266C(void) {
    return;
}

// .text:0x000E25D0 size:0x9C mapped:0x80721664
void fn_3_E25D0(Rep2998Obj* obj, u32 anim) {
    obj->_AC = lbl_3_bss_AE18[anim];
    fn_3_B97DC(obj->_74, obj->_AC);
    if (anim != 0 && anim != 2 && anim != 3) {
        obj->_74->_5B = 2;
        fn_800B4AFC(obj->_74->_00, obj->_74->_5B & 1);
    }
    obj->_B8 = obj->_74->_5C;
    obj->_CB = anim;
}

// .text:0x000E2324 size:0x2AC mapped:0x807213B8
void fn_3_E2324(void) {
    return;
}

// .text:0x000E22A4 size:0x80 mapped:0x80721338
void fn_3_E22A4(Rep2998Obj* obj) {
    DisplayStateList* state = obj->_74->_00->pal->descriptorArray[0].layout->displayData->displayStateList;
    u8 value;

    state->setting &= ~0x1FFF;
    if (obj->_C4 != 0) {
        value = obj->_C8 + 1;
        if (obj->_C4 == 1 || obj->_C4 == 5) {
            if (obj->_C5 % 2 == 0) {
                value = 0;
            }
        }
        state->setting |= value;
    }
}

// .text:0x000E2118 size:0x18C mapped:0x807211AC
void fn_3_E2118(void) {
    return;
}

// .text:0x000E2034 size:0xE4 mapped:0x807210C8
void fn_3_E2034(Rep2998Obj* obj) {
    Vec d;
    Vec fwd = { 0.0f, 0.0f, -1.0f };
    f32 angle;

    PSVECSubtract((Vec*)&g_Ball.AtBat_Contact_BallPos, &obj->_A0, &d);
    d.y = 0.0f;
    PSVECNormalize(&d, &d);
    PSVECNormalize(&fwd, &fwd);
    angle = 57.29578f * (f32)acos(PSVECDotProduct(&d, &fwd));
    if (d.x < 0.0f) {
        angle = 360.0f - angle;
    }
    obj->_B0 = -angle;
    CTRLSetRotation(&obj->control, 0.0f, obj->_B0, 0.0f);
}

// .text:0x000E1FA8 size:0x8C mapped:0x8072103C
void fn_3_E1FA8(Rep2998Obj* obj) {
    Rep2998Model* model = obj->_74;
    Rep2998Actor* actor = model->_00;

    if (model->_5C + model->_54 > 900.0f) {
        model->_5C = 180.0f;
        model->_59 = 1;
        fn_800B4CA0(actor, model->_5C);
    }
    AnimateActorBones(actor);
    model->_5C += model->_54;
}

// .text:0x000E1DB8 size:0x1F0 mapped:0x80720E4C
void fn_3_E1DB8(void) {
    return;
}
