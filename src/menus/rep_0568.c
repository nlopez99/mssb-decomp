#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_0568.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "string.h"

typedef struct Actor0568 {
    /* 0x00 */ u8 _00[0x98];
    /* 0x98 */ u8 _98;
} Actor0568;

// One animated model of the list at lbl_8036E548._0060
typedef struct ActorRef0568 {
    /* 0x00 */ Actor0568* _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ void (*_08)(struct Obj0568* obj);
    /* 0x0C */ u8 _0C[0xE - 0xC];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ Control _10;
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u8 _64[0x68 - 0x64];
    /* 0x68 */ void* _68;
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D[0x90 - 0x6D];
} ActorRef0568; // size: 0x90

typedef struct ModelList0568 {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u8 _02[0x34 - 0x2];
    /* 0x34 */ ActorRef0568 _34[1];
} ModelList0568;

// One pose block per player in lbl_8036E548
typedef struct Pose0568 {
    /* 0x00 */ u8 _00[0xCD];
    /* 0xCD */ u8 _CD;
    /* 0xCE */ u8 _CE;
    /* 0xCF */ u8 _CF;
    /* 0xD0 */ s8 _D0;
    /* 0xD1 */ u8 _D1;
    /* 0xD2 */ u8 _D2[0xD4 - 0xD2];
} Pose0568; // size: 0xD4

// A player record in lbl_8036E548
typedef struct Player0568 {
    /* 0x000 */ u8 _000[0x8];
    /* 0x008 */ void* _008;
    /* 0x00C */ u8 _00C[0x30 - 0xC];
    /* 0x030 */ Pose0568* _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x62 - 0x40];
    /* 0x062 */ s16 _062;
    /* 0x064 */ u8 _064[0x252 - 0x64];
    /* 0x252 */ u8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ u8 _254;
    /* 0x255 */ u8 _255[0x25D - 0x255];
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E[0x265 - 0x25E];
    /* 0x265 */ u8 _265;
    /* 0x266 */ u8 _266[0x27C - 0x266];
} Player0568; // size: 0x27C

extern struct {
    /* 0x0000 */ u8 _0000[0x140];
    /* 0x0140 */ Pose0568 _0140[13];
    /* 0x0C04 */ Player0568 _0C04[13];
    /* 0x2C50 */ Player0568* _2C50[13];
    /* 0x2C84 */ u8 _2C84[0x2D94 - 0x2C84];
    /* 0x2D94 */ struct {
        /* 0x00 */ u8 _00[0x28];
    }* _2D94;
    /* 0x2D98 */ u8 _2D98[0x307A - 0x2D98];
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B;
    /* 0x307C */ u8 _307C;
} lbl_8036E548;

extern struct {
    /* 0x00 */ s8 _00;
    /* 0x01 */ s8 _01;
    /* 0x02 */ s8 _02[10];
    /* 0x0C */ u8 _0C[0x14 - 0xC];
    /* 0x14 */ u8 _14[4];
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C[0x27 - 0x1C];
    /* 0x27 */ s8 _27[4];
    /* 0x2B */ u8 _2B[0x2D - 0x2B];
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E[0x40 - 0x2E];
    /* 0x40 */ u8 _40[2];
    /* 0x42 */ u8 _42[4];
    /* 0x46 */ u8 _46[2];
} lbl_2_bss_100B8;

extern struct {
    /* 0x0000 */ u8 _0000[0x4701];
    /* 0x4701 */ u8 _4701;
} lbl_8034E9A0;

extern struct {
    /* 0x000 */ u8 _000[0x396];
    /* 0x396 */ u8 _396;
    /* 0x397 */ u8 _397;
    /* 0x398 */ u8 _398;
} lbl_800EF808;

extern struct {
    /* 0x00 */ u8 _00[0x1F];
    /* 0x1F */ u8 _1F;
} lbl_80366158;

extern struct {
    /* 0x0 */ u8 _0[0x6];
    /* 0x6 */ u8 _6;
    /* 0x7 */ u8 _7;
    /* 0x8 */ u8 _8;
} lbl_2_bss_1033C;

typedef struct Task0568 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s32 _10;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ u8 _18[4];
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
    /* 0x1E */ u8 _1E;
} Task0568;

extern Mtx lbl_2_bss_1010C;

Task0568* lbl_2_bss_1224;

typedef struct Obj0568 {
    /* 0x00 */ u8 _00[0x70];
    /* 0x70 */ void* _70;
} Obj0568;

extern void fn_2_16460(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B9AA8(void* arg0);
extern void ACTSetAnimation(Actor0568* actor, void* animBank, char* sequenceName, u16 seqNum, f32 time, f32 speed);
extern void fn_800B4CA0(Actor0568* actor, f32 frame);
extern void fn_800B4C04(Actor0568* actor, f32 speed);
extern void fn_800B4AFC(Actor0568* actor, u8 flag);
extern void Set_FUN_800b2b6c(Actor0568* actor, void* arg1);
extern void fn_800BDA24(ActorRef0568* ref);
extern void fn_800BDA94(ActorRef0568* ref, Mtx view);
extern void fn_80021204(void);
extern s32 fn_8003AE70(s32 index);

// .text:0x00019778 size:0x34
void fn_2_19778(void) {
    s8 a = lbl_800EF808._398;
    s8 b = lbl_80366158._1F;
    s8 c = lbl_800EF808._396;

    lbl_2_bss_1033C._6 = a;
    lbl_2_bss_1033C._8 = b;
    lbl_2_bss_1033C._7 = c;
}

// .text:0x000195D8 size:0x4
void fn_2_195D8(void) {
}

// .text:0x00019554 size:0x84
s8 fn_2_19554(void) {
    s32 changed = 0;

    if (lbl_800EF808._398 != fn_8003AE70(0) || lbl_800EF808._397 != fn_8003AE70(1) ||
        lbl_80366158._1F != fn_8003AE70(2)) {
        changed = 1;
    }
    return changed;
}

// .text:0x00019520 size:0x34
void fn_2_19520(void) {
    s8 a = lbl_800EF808._398;
    s8 b = lbl_80366158._1F;
    s8 c = lbl_800EF808._396;

    lbl_2_bss_1033C._6 = a;
    lbl_2_bss_1033C._8 = b;
    lbl_2_bss_1033C._7 = c;
}

// .text:0x000194E8 size:0x38
void fn_2_194E8(void) {
    fn_80021204();
    gameInitOptions._25 = lbl_80366158._1F;
}

// .text:0x000194BC size:0x2C
void fn_2_194BC(Obj0568* obj) {
    if (obj->_70 != NULL) {
        fn_800B9AA8(obj->_70);
    }
}

// .text:0x0001937C size:0x140
void fn_2_1937C(ModelList0568* list, Mtx view) {
    Mtx44 proj;
    u16 i;
    Player0568* player;
    ActorRef0568* ref;
    f32 x;
    f32 y;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetCullMode(GX_CULL_BACK);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    for (i = 0; i < list->_00; i++) {
        player = lbl_8036E548._2C50[i];
        if (player == NULL) {
            continue;
        }
        ref = &list->_34[i];
        if (ref->_00 != NULL && ref->_6C != 0) {
            x = player->_034 / 1280.0f;
            y = player->_038 / 1280.0f;
            C_MTXFrustum(proj, -0.175f + y, 0.175f + y, 0.25f + x, -0.25f + x, 1.0f, 512.0f);
            GXSetProjection(proj, GX_PERSPECTIVE);
            fn_800BDA94(ref, view);
        }
    }
}

// .text:0x00019224 size:0x158
void fn_2_19224(ModelList0568* list) {
    u16 i;
    Player0568* player;
    ActorRef0568* ref;

    for (i = 0; i < list->_00; i++) {
        player = lbl_8036E548._2C50[i];
        if (player == NULL || player->_25D == 0) {
            continue;
        }
        ref = &list->_34[i];
        if (ref->_00 == NULL) {
            continue;
        }
        if (ref->_58 != 0) {
            ACTSetAnimation(ref->_00, ref->_04, NULL, ref->_0E, 0.0f, ref->_60);
        }
        if (ref->_59 != 0) {
            fn_800B4CA0(ref->_00, ref->_5C);
        }
        if (ref->_5A != 0) {
            fn_800B4C04(ref->_00, ref->_54);
        }
        if (ref->_5B & 2) {
            fn_800B4AFC(ref->_00, ref->_5B & 1);
        }
        Set_FUN_800b2b6c(ref->_00, ref->_68);
        if (ref->_6C != 0) {
            fn_800BDA24(ref);
        }
        ref->_00->_98 = 1;
        ref->_58 = 0;
        ref->_59 = 0;
        ref->_5A = 0;
        ref->_5B &= 1;
    }
}

// .text:0x000190DC size:0x148
void fn_2_190DC(ModelList0568* list, Mtx view) {
    u16 i;
    ActorRef0568* ref;

    for (i = 0; i < list->_00; i++) {
        if (&lbl_8036E548._2D94[i] == NULL) {
            continue;
        }
        ref = &list->_34[i];
        if (ref->_00 == NULL) {
            continue;
        }
        if (ref->_58 != 0) {
            ACTSetAnimation(ref->_00, ref->_04, NULL, ref->_0E, 0.0f, ref->_60);
        }
        if (ref->_59 != 0) {
            fn_800B4CA0(ref->_00, ref->_5C);
        }
        if (ref->_5A != 0) {
            fn_800B4C04(ref->_00, ref->_54);
        }
        if (ref->_5B & 2) {
            fn_800B4AFC(ref->_00, ref->_5B & 1);
        }
        Set_FUN_800b2b6c(ref->_00, ref->_68);
        if (ref->_6C != 0) {
            fn_800BDA24(ref);
        }
        ref->_00->_98 = 1;
        ref->_58 = 0;
        ref->_59 = 0;
        ref->_5A = 0;
        ref->_5B &= 1;
    }
}

// .text:0x000190B8 size:0x24
void fn_2_190B8(Obj0568* obj) {
    fn_800B9AA8(obj->_70);
}

// .text:0x00018FBC size:0xFC
void fn_2_18FBC(void) {
    Task0568* task = fn_800B0A5C_insertQueue(fn_2_188EC, 0x6000);
    s32 i;

    lbl_2_bss_100B8._19 = 0;
    lbl_2_bss_100B8._1B = 1;
    if (lbl_8034E9A0._4701 == 0) {
        for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
            lbl_2_bss_100B8._27[i] = -1;
        }
        task->_1C = 0;
    } else {
        for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
            lbl_2_bss_100B8._14[i] = 0;
        }
        task->_1C = 0;
    }
    lbl_2_bss_100B8._00 = 0;
    lbl_2_bss_100B8._01 = 0;
    for (i = 0; i < 10; i++) {
        lbl_2_bss_100B8._02[i] = -1;
    }
}

// .text:0x00018650 size:0xF8
s32 fn_2_18650(s32 index) {
    s32 next = (lbl_2_bss_100B8._00 + 1) % 10;

    if (next != lbl_2_bss_100B8._01) {
        if (lbl_2_bss_1224 == NULL) {
            lbl_2_bss_1224 = fn_800B0A5C_insertQueue(fn_2_18398, 0xFFFF);
            if (lbl_2_bss_1224 != NULL) {
                lbl_2_bss_1224->_1C = 0;
                lbl_2_bss_1224->_1D = 0;
            } else {
                return 0;
            }
        }
        lbl_2_bss_100B8._02[lbl_2_bss_100B8._00] = index;
        lbl_2_bss_100B8._00 = next;
        lbl_2_bss_100B8._42[index] = 1;
        return 1;
    }
    return 0;
}

// .text:0x00016F0C size:0x6C
void fn_2_16F0C(u8 index) {
    s8 a = lbl_8036E548._0C04[index]._252;
    Player0568* player = &lbl_8036E548._0C04[index];
    s8 b = lbl_8036E548._0C04[index]._254;

    if (lbl_8036E548._0140[index]._D0 == -1) {
        lbl_8036E548._0140[index]._CF = a;
        lbl_8036E548._0140[index]._D1 = lbl_8036E548._0140[index]._D0;
        lbl_8036E548._0140[index]._D0 = b;
        lbl_8036E548._0140[index]._CD = player->_265;
    }
    player->_030 = &lbl_8036E548._0140[index];
}

// .text:0x00016D38 size:0x70
void fn_2_16D38(void) {
    s32 i;

    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        memset(lbl_8036E548._0C04[i]._008, 0, 0x5C);
    }
}

// .text:0x00016CE0 size:0x58
void fn_2_16CE0(void) {
    Player0568* player;
    s32 i;

    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        player = lbl_8036E548._2C50[i];
        if (player != NULL && player->_062 == 0x6B) {
            lbl_2_bss_100B8._40[i] = 1;
        }
    }
}

// .text:0x00016A74 size:0x24
void fn_2_16A74(s32 index, s32 flag) {
    lbl_8036E548._0C04[index]._25D = flag != 0;
}

// .text:0x00016A5C size:0x18
u8 fn_2_16A5C(s32 index) {
    return lbl_8036E548._0C04[index]._25D;
}

// .text:0x00016A48 size:0x14
void fn_2_16A48(s32 index, u8 value) {
    lbl_2_bss_100B8._46[index] = value;
}

// .text:0x00016A34 size:0x14
u8 fn_2_16A34(s32 index) {
    return lbl_2_bss_100B8._46[index];
}

// .text:0x00016870 size:0x1C4
void fn_2_16870(void) {
    s32 i;

    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        if (lbl_2_bss_100B8._14[i] != 0 && fn_2_18650(i)) {
            lbl_2_bss_100B8._14[i] = 0;
        }
    }
    lbl_8036E548._307A = 5;
    lbl_8036E548._307C = 1;
    fn_2_16460();
    PSMTXCopy(lbl_2_bss_1010C, fn_80052768_getCamera(0)->view);
    fn_2_16CE0();
}
