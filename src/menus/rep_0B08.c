#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_0B08.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/vec.h"
#include "stl/math.h"
#include "stdlib.h"
#include "string.h"

typedef void (*Obj0B08Fn)(struct Obj0B08* obj);

// One of 14 objects in the star-mission tracker's array at 0x1610
typedef struct Obj0B08 {
    /* 0x00 */ Vec _00;
    /* 0x0C */ Vec _0C;
    /* 0x18 */ Vec _18;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ f32 _30;
    /* 0x34 */ f32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ f32 _40;
    /* 0x44 */ f32 _44;
    /* 0x48 */ u8 _48[0x4C - 0x48];
    /* 0x4C */ f32 _4C;
    /* 0x50 */ f32 _50;
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58[0x6C - 0x58];
    /* 0x6C */ f32 _6C;
    /* 0x70 */ f32 _70;
    /* 0x74 */ Vec _74;
    /* 0x80 */ s32 _80;
    /* 0x84 */ s32 _84;
    /* 0x88 */ f32 _88;
    /* 0x8C */ f32 _8C;
    /* 0x90 */ f32 _90;
    /* 0x94 */ s16 _94;
    /* 0x96 */ s16 _96;
    /* 0x98 */ s16 _98;
    /* 0x9A */ s16 _9A;
    /* 0x9C */ s16 _9C;
    /* 0x9E */ s16 _9E;
    /* 0xA0 */ s16 _A0;
    /* 0xA2 */ s16 _A2;
    /* 0xA4 */ u8 _A4[0xAC - 0xA4];
    /* 0xAC */ s16 _AC;
    /* 0xAE */ s16 _AE;
    /* 0xB0 */ s16 _B0;
    /* 0xB2 */ s16 _B2;
    /* 0xB4 */ u8 _B4[0xB6 - 0xB4];
    /* 0xB6 */ u8 _B6;
    /* 0xB7 */ u8 _B7;
    /* 0xB8 */ u8 _B8;
    /* 0xB9 */ u8 _B9;
    /* 0xBA */ u8 _BA;
    /* 0xBB */ u8 _BB;
    /* 0xBC */ u8 _BC;
    /* 0xBD */ u8 _BD;
    /* 0xBE */ u8 _BE;
    /* 0xBF */ u8 _BF;
    /* 0xC0 */ u8 _C0;
    /* 0xC1 */ u8 _C1;
    /* 0xC2 */ u8 _C2;
    /* 0xC3 */ u8 _C3;
    /* 0xC4 */ u8 _C4;
    /* 0xC5 */ u8 _C5;
    /* 0xC6 */ s8 _C6;
    /* 0xC7 */ u8 _C7[0xCA - 0xC7];
    /* 0xCA */ u8 _CA;
    /* 0xCB */ s8 _CB;
    /* 0xCC */ s8 _CC;
    /* 0xCD */ s8 _CD;
    /* 0xCE */ s8 _CE;
    /* 0xCF */ s8 _CF;
    /* 0xD0 */ u8 _D0;
    /* 0xD1 */ u8 _D1[0xD4 - 0xD1];
    /* 0xD4 */ Obj0B08Fn _D4;
} Obj0B08; // size: 0xD8

typedef struct Item0B08 {
    /* 0x00 */ Vec _00;
    /* 0x0C */ u8 _0C[0xBC - 0xC];
} Item0B08; // size: 0xBC

typedef struct Tracker0B08 {
    /* 0x0000 */ u8 _0000[0x1610];
    /* 0x1610 */ Obj0B08 _1610[14];
    /* 0x21E0 */ Item0B08 _21E0[46];
    /* 0x43A8 */ u8 _43A8[0x441C - 0x43A8];
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ u8 _441F[0x442F - 0x441F];
    /* 0x442F */ u8 _442F;
    /* 0x4430 */ u8 _4430[0x4439 - 0x4430];
    /* 0x4439 */ u8 _4439;
    /* 0x443A */ u8 _443A[0x4448 - 0x443A];
    /* 0x4448 */ u8 _4448;
    /* 0x4449 */ u8 _4449[0x44F2 - 0x4449];
    /* 0x44F2 */ u8 _44F2;
    /* 0x44F3 */ u8 _44F3;
} Tracker0B08;

typedef struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ GXColor ambient;
} StadiumLights0B08; // size: 0x2C

extern StadiumLights0B08 lbl_800F7478[14];

typedef struct {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
} AnimEntry0B08; // size: 0x6

// A player record in lbl_8036E548
typedef struct {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ Vec _034;
    /* 0x040 */ u8 _040[0x44 - 0x40];
    /* 0x044 */ f32 _044;
    /* 0x048 */ u8 _048[0x68 - 0x48];
    /* 0x068 */ s16 _068;
    /* 0x06A */ u8 _06A[0x25D - 0x6A];
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E[0x277 - 0x25E];
    /* 0x277 */ u8 _277;
    /* 0x278 */ u8 _278[0x27C - 0x278];
} Player0B08; // size: 0x27C

extern struct {
    /* 0x0000 */ u8 _0000[0xC04];
    /* 0x0C04 */ Player0B08 _0C04[18];
} lbl_8036E548;

extern struct {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
    /* 0x4 */ s16 _4;
} lbl_2_data_2E80[6];
extern Vec lbl_2_data_2EA4[57];
extern Vec lbl_2_data_3150[];
extern struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ u8 _0C[0x14 - 0xC];
} lbl_2_data_3198[];
extern s16* lbl_2_data_3C2C[5];
extern s32 lbl_2_data_3C40[7];
extern s32 lbl_2_data_3C5C[7];
extern s16 lbl_2_data_3D30[][4];
extern f32 lbl_2_data_3EF4[6];
extern f32 lbl_2_data_3F0C[8];
extern f32 lbl_2_data_3F2C[6];
extern f32 lbl_2_data_3F44[6];
extern f32 lbl_2_data_3F5C;
extern AnimEntry0B08 lbl_2_data_3C84[];

extern struct {
    /* 0x000000 */ u8 _000000[0x1972BC];
    /* 0x1972BC */ u8 _1972BC;
    /* 0x1972BD */ u8 _1972BD[0x197746 - 0x1972BD];
    /* 0x197746 */ s16 _197746;
    /* 0x197748 */ u8 _197748[0x197756 - 0x197748];
    /* 0x197756 */ s16 _197756[14];
    /* 0x197772 */ u8 _197772[0x197843 - 0x197772];
    /* 0x197843 */ s8 _197843;
    /* 0x197844 */ u8 _197844[0x197863 - 0x197844];
    /* 0x197863 */ s8 _197863;
    /* 0x197864 */ u8 _197864[0x1978F1 - 0x197864];
    /* 0x1978F1 */ u8 _1978F1;
} *lbl_2_bss_1A824C;

extern void fn_2_8CD58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6);
extern void fn_800BD2CC(s32 arg0, GXColor color);
extern s32 fn_80062890(s32 id);
extern void fn_800B0A14_removeQueue(void);
extern s32 fn_2_8CC88(s32);
extern void fn_2_46C88(s32 arg0, s32 arg1);
extern void fn_2_8F73C(s32 arg0, s32 arg1);
extern void fn_2_9033C(s32 arg0, Vec* pos, f32 arg2);
extern void fn_2_92654(s32 arg0, s32 arg1);
extern f32 fn_2_4A18C(f32 angle);
extern f32 fn_2_4A1E8(f32 x, f32 z);
extern s16 fn_2_4A150(s16 angle);
extern s32 fn_2_4A2C4(f32 angle);
extern s16 fn_2_4A234(f32 x, f32 z);
extern s16 fn_2_4A310(s16 a, s16 b);

// Points to starMissionCompletionTracker
extern Tracker0B08* lbl_2_bss_1A8248;

static inline void scaleVec(Vec* src, Vec* dst, f32 scale) {
    dst->x = src->x * scale;
    dst->y = src->y * scale;
    dst->z = src->z * scale;
}

static inline f32 calcAngle(f32 dx, f32 dz) { return atan2(-dx, -dz); }

static inline void setObjType(Obj0B08* obj, u8 type) {
    obj->_C3 = type;
    obj->_94 = 0;
}

Obj0B08Fn lbl_2_data_2A1E8[3] = { fn_2_71C6C, fn_2_71B80, fn_2_71A70 };
Obj0B08Fn lbl_2_data_2A1F4[3] = { fn_2_71098, fn_2_709A0, fn_2_705C0 };
Obj0B08Fn lbl_2_data_2A200[2] = { fn_2_704AC, fn_2_704A0 };
Obj0B08Fn lbl_2_data_2A208[2] = { fn_2_70110, fn_2_6FE6C };
Obj0B08Fn lbl_2_data_2A210[4] = { fn_2_6FB0C, fn_2_6F88C, fn_2_6F78C, fn_2_6F72C };
Obj0B08Fn lbl_2_data_2A220[5] = { fn_2_6F104, fn_2_6ED30, fn_2_6EA74, fn_2_6E88C, fn_2_6E880 };
Obj0B08Fn lbl_2_data_2A234[5] = { fn_2_6E1D0, fn_2_6DE54, fn_2_6DB30, fn_2_6D968, fn_2_6D878 };
Obj0B08Fn lbl_2_data_2A248[2] = { fn_2_6D754, fn_2_6D748 };
Obj0B08Fn lbl_2_data_2A250[3] = { fn_2_6D5D4, fn_2_6D4F8, fn_2_6D4E8 };
Obj0B08Fn lbl_2_data_2A25C[3] = { fn_2_6D374, fn_2_6D298, fn_2_6D288 };
Obj0B08Fn lbl_2_data_2A268[3] = { fn_2_6D164, fn_2_6D088, fn_2_6D078 };
Obj0B08Fn lbl_2_data_2A274[3] = { fn_2_6CDD4, fn_2_6CCB8, fn_2_6CBB0 };
Obj0B08Fn lbl_2_data_2A280[3] = { fn_2_6C988, fn_2_6C97C, fn_2_6C970 };
Obj0B08Fn lbl_2_data_2A28C[4] = { fn_2_6C5E0, fn_2_6C348, fn_2_6C2E8, fn_2_6C2C4 };
Obj0B08Fn lbl_2_data_2A29C[4] = { fn_2_6C190, fn_2_6C120, fn_2_6C020, fn_2_6BFC0 };
Obj0B08Fn lbl_2_data_2A2AC[3] = { fn_2_6BE80, fn_2_6BDE0, fn_2_6BDD4 };
Obj0B08Fn lbl_2_data_2A2B8[3] = { fn_2_6BCAC, fn_2_6BC0C, fn_2_6BC00 };
Obj0B08Fn lbl_2_data_2A2C4[4] = { fn_2_6BB7C, fn_2_6BAD8, fn_2_6BAAC, fn_2_6BA50 };
Obj0B08Fn lbl_2_data_2A2D4[3] = { fn_2_6B744, fn_2_6B620, fn_2_6B4FC };
Obj0B08Fn lbl_2_data_2A2E0[3] = { fn_2_6B238, fn_2_6B120, fn_2_6B024 };
Obj0B08Fn lbl_2_data_2A2EC[21] = {
    fn_2_71EFC, fn_2_71EC4, fn_2_71A38, fn_2_70588, fn_2_7045C, fn_2_6FE34, fn_2_6F6F4,
    fn_2_6E848, fn_2_6D840, fn_2_6D710, fn_2_6D4B0, fn_2_6D250, fn_2_6D040, fn_2_6CB78,
    fn_2_6C938, fn_2_6C28C, fn_2_6BF88, fn_2_6BD9C, fn_2_6BBC8, fn_2_6BA18, fn_2_6B4C4,
};
Vec lbl_2_data_2A340 = { 0.0f, 0.0f, 0.0f };

f32 lbl_2_bss_A170;

// .text:0x00071F60 size:0xD8
void fn_2_71F60(void) {
    s32 i;
    if (lbl_2_bss_1A8248->_44F2 == 1 || lbl_2_bss_1A8248->_44F2 == 2 || lbl_2_bss_1A8248->_44F2 == 3) {
        return;
    }
    for (i = 0; i < 8; i++) {
        fn_2_71F20(&lbl_2_bss_1A8248->_1610[i]);
    }
    if (lbl_2_bss_1A824C->_1972BC != 0) {
        lbl_2_bss_1A824C->_1972BC = 0;
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00071F20 size:0x40
void fn_2_71F20(Obj0B08* obj) {
    obj->_D4 = lbl_2_data_2A2EC[obj->_C3];
    obj->_D4(obj);
}

// .text:0x00071EFC size:0x24
void fn_2_71EFC(Obj0B08* obj) { fn_2_68F08(obj->_80, 0); }

// .text:0x00071EC4 size:0x38
void fn_2_71EC4(Obj0B08* obj) { lbl_2_data_2A1E8[obj->_94](obj); }

// .text:0x00071C6C size:0x258
void fn_2_71C6C(Obj0B08* obj) {
    s32 index = obj->_80;
    fn_2_68F08(index, 1);
    memcpy(&obj->_74, &lbl_2_data_2EA4[lbl_2_bss_1A8248->_1610[0]._B0], sizeof(Vec));
    fn_2_6A450(index, obj->_74.x, obj->_74.z);
    obj->_BA = 13;
    fn_2_68FBC(index, 0);
    obj->_94 = 1;
}

// .text:0x00071B80 size:0xEC
void fn_2_71B80(Obj0B08* obj) {
    fn_2_69E1C(obj->_80);
    fn_2_68260(obj);
    if (obj->_50 <= 0.0f) {
        obj->_BA = 4;
        obj->_C4 = 1;
        obj->_94 = 2;
    }
}

// .text:0x00071A70 size:0x110
void fn_2_71A70(Obj0B08* obj) {
    s32 index = obj->_80;
    fn_2_69E1C(index);
    fn_2_68260(obj);
    if (obj->_38 <= 0.0f) {
        obj->_34 = obj->_4C;
        setObjType(&lbl_2_bss_1A8248->_1610[index], 3);
    }
}

// .text:0x00071A38 size:0x38
void fn_2_71A38(Obj0B08* obj) { lbl_2_data_2A1F4[obj->_94](obj); }

// .text:0x00071098 size:0x9A0

// .text:0x000709A0 size:0x6F8

// .text:0x000705C0 size:0x3E0
void fn_2_705C0(Obj0B08* obj) {
    s32 index = obj->_80;
    Obj0B08* other;
    f32 diff;
    s32 hit;
    s32 i;
    fn_2_69E1C(index);
    fn_2_68260(obj);
    if (obj->_38 <= 0.0f) {
        obj->_34 = obj->_4C;
        setObjType(&lbl_2_bss_1A8248->_1610[index], 4);
    }
    for (i = 1; i < 7; i++) {
        hit = fn_2_68C80(index, i);
        if (hit && i == 1 && lbl_2_bss_1A8248->_44F3 == 0) {
            obj->_C4 = 2;
            obj->_CB = i;
            setObjType(&lbl_2_bss_1A8248->_1610[index], 3);
            return;
        }
        obj->_CB = -1;
    }
    if (obj->_CD == 1) {
        other = &lbl_2_bss_1A8248->_1610[obj->_CE];
        diff = fn_2_68940(obj->_CE, index);
        if (other->_C3 == 7 && (obj->_94 == 0 || obj->_94 == 1)) {
            if ((f32)fabs(diff) < 1.5707964f) {
                lbl_2_bss_1A824C->_1978F1 = 0;
            } else {
                lbl_2_bss_1A824C->_1978F1 = 2;
            }
        } else {
            lbl_2_bss_1A824C->_1978F1 = 1;
        }
        obj->_BA = 4;
        obj->_C4 = 1;
        obj->_B2 = fn_2_689CC(0);
        setObjType(&lbl_2_bss_1A8248->_1610[index], 4);
    }
}

// .text:0x00070588 size:0x38
void fn_2_70588(Obj0B08* obj) { lbl_2_data_2A200[obj->_94](obj); }

// .text:0x000704AC size:0xDC
void fn_2_704AC(Obj0B08* obj) {
    fn_2_68F08(obj->_80, 1);
    fn_2_68FBC(obj->_80, 1);
    obj->_94 = 1;
}

// .text:0x000704A0 size:0xC
void fn_2_704A0(Obj0B08* obj) { obj->_94 = 2; }

// .text:0x00070494 size:0xC
void fn_2_70494(Obj0B08* obj) { obj->_94 = 2; }

// .text:0x0007045C size:0x38
void fn_2_7045C(Obj0B08* obj) { lbl_2_data_2A208[obj->_94](obj); }

// .text:0x00070110 size:0x34C
void fn_2_70110(Obj0B08* obj) {
    s32 index = obj->_80;
    Obj0B08* other;
    f32 diff;
    s32 hit;
    s32 i;
    fn_2_68F08(obj->_80, 1);
    fn_2_68FBC(obj->_80, 1);
    if (obj->_CD == 1) {
        other = &lbl_2_bss_1A8248->_1610[obj->_CE];
        diff = fn_2_68940(obj->_CE, index);
        if (other->_C3 == 7 && (obj->_94 == 0 || obj->_94 == 1)) {
            if ((f32)fabs(diff) < 1.5707964f) {
                lbl_2_bss_1A824C->_1978F1 = 0;
            } else {
                lbl_2_bss_1A824C->_1978F1 = 2;
            }
        } else {
            lbl_2_bss_1A824C->_1978F1 = 1;
        }
    }
    for (i = 1; i < 7; i++) {
        hit = fn_2_68C80(index, i);
        if (hit && i == 1 && lbl_2_bss_1A8248->_44F3 == 0) {
            obj->_C4 = 2;
            obj->_CB = i;
            setObjType(&lbl_2_bss_1A8248->_1610[index], 3);
            return;
        }
        if (hit && i >= 2 && i <= 6) {
            obj->_CB = i;
            setObjType(&lbl_2_bss_1A8248->_1610[index], 4);
            return;
        }
        obj->_CB = -1;
    }
    obj->_94 = 1;
}

// .text:0x0006FE6C size:0x2A4
void fn_2_6FE6C(Obj0B08* obj) {
    s32 index = obj->_80;
    Obj0B08* other;
    f32 diff;
    s32 hit;
    s32 i;
    if (obj->_CD == 1) {
        other = &lbl_2_bss_1A8248->_1610[obj->_CE];
        diff = fn_2_68940(obj->_CE, index);
        if (other->_C3 == 7 && (obj->_94 == 0 || obj->_94 == 1)) {
            if ((f32)fabs(diff) < 1.5707964f) {
                lbl_2_bss_1A824C->_1978F1 = 0;
            } else {
                lbl_2_bss_1A824C->_1978F1 = 2;
            }
        } else {
            lbl_2_bss_1A824C->_1978F1 = 1;
        }
    }
    for (i = 1; i < 7; i++) {
        hit = fn_2_68C80(index, i);
        if (hit && i == 1 && lbl_2_bss_1A8248->_44F3 == 0) {
            obj->_C4 = 2;
            obj->_CB = i;
            setObjType(&lbl_2_bss_1A8248->_1610[index], 3);
            break;
        }
        if (hit && i >= 2 && i <= 6) {
            obj->_CB = i;
            setObjType(&lbl_2_bss_1A8248->_1610[index], 4);
            break;
        }
        obj->_CB = -1;
    }
}

// .text:0x0006FE34 size:0x38
void fn_2_6FE34(Obj0B08* obj) { lbl_2_data_2A210[obj->_94](obj); }

// .text:0x0006FB0C size:0x328
void fn_2_6FB0C(Obj0B08* obj) {
    s32 index = obj->_80;
    s32 target = lbl_2_bss_1A8248->_1610[0]._80;
    s32 state;
    s32 slot;
    fn_2_68F08(obj->_80, 1);
    fn_2_68FBC(obj->_80, 1);
    obj->_34 = obj->_4C;
    if (index >= 2 && index <= 6) {
        state = fn_2_68670(0);
        slot = fn_2_68690(0);
        if (state == 1 && slot == index) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 2;
            return;
        }
    }
    if (fn_2_68C80(index, target)) {
        if (index == 1) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 2;
            return;
        } else if (index >= 2 && index <= 6) {
            obj->_CB = 0;
        }
    } else {
        obj->_CB = -1;
    }
    obj->_94 = 1;
}

// .text:0x0006F88C size:0x280
void fn_2_6F88C(Obj0B08* obj) {
    s32 index = obj->_80;
    s32 target = lbl_2_bss_1A8248->_1610[0]._80;
    s32 state;
    s32 slot;
    if (index >= 2 && index <= 6) {
        state = fn_2_68670(0);
        slot = fn_2_68690(0);
        if (state == 1 && slot == index) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 2;
            return;
        }
    }
    if (fn_2_68C80(index, target)) {
        if (index == 1) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 2;
        } else if (index >= 2 && index <= 6) {
            obj->_CB = 0;
        }
    } else {
        obj->_CB = -1;
    }
}

// .text:0x0006F78C size:0x100
void fn_2_6F78C(Obj0B08* obj) {
    f32 diff;
    obj->_4C = atan2(-(lbl_2_bss_1A8248->_1610[0]._00.x - obj->_00.x), -(lbl_2_bss_1A8248->_1610[0]._00.z - obj->_00.z));
    diff = fn_2_4A18C(obj->_34 - obj->_4C);
    if ((diff < 0.02 && diff > 0.0f) || (diff > -0.02 && diff < 0.0f)) {
        obj->_94 = 3;
    } else if (diff < 0.0f) {
        obj->_34 += 0.05235988f;
    } else {
        obj->_34 -= 0.05235988f;
    }
    obj->_4C = obj->_34;
}

// .text:0x0006F72C size:0x60
void fn_2_6F72C(Obj0B08* obj) {
    f32 dist = fabs(PSVECDistance(&lbl_2_bss_1A8248->_1610[0]._00, &obj->_00));
    if (dist > 1.6f) {
        obj->_94 = 1;
    }
}

// .text:0x0006F6F4 size:0x38
void fn_2_6F6F4(Obj0B08* obj) { lbl_2_data_2A220[obj->_94](obj); }

// .text:0x0006F104 size:0x5F0

// .text:0x0006ED30 size:0x3D4
void fn_2_6ED30(Obj0B08* obj) {
    s32 index = obj->_80;
    s32 target = lbl_2_bss_1A8248->_1610[0]._80;
    s32 state;
    s32 slot;
    fn_2_69E1C(index);
    if (index >= 2 && index <= 6) {
        state = fn_2_68670(0);
        slot = fn_2_68690(0);
        if (state == 1 && slot == index) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 3;
            return;
        }
    }
    if (fn_2_68C80(index, target)) {
        if (index == 1 && lbl_2_bss_1A8248->_44F3 == 0) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 3;
            return;
        } else if (index >= 2 && index <= 6) {
            obj->_CB = 0;
        } else {
            obj->_CB = -1;
        }
    } else {
        obj->_CB = -1;
    }
    if (obj->_50 <= 0.0f) {
        obj->_AE = obj->_B2;
        obj->_B2 = obj->_B0;
        if (rand() % 100 < 10) {
            fn_2_68FBC(index, 1);
            obj->_A2 = rand() % 180 + 60;
            obj->_94 = 2;
        } else {
            obj->_94 = 0;
        }
    }
}

// .text:0x0006EA74 size:0x2BC
void fn_2_6EA74(Obj0B08* obj) {
    s32 index = obj->_80;
    s32 target = lbl_2_bss_1A8248->_1610[0]._80;
    s32 state;
    s32 slot;
    if (index >= 2 && index <= 6) {
        state = fn_2_68670(0);
        slot = fn_2_68690(0);
        if (state == 1 && slot == index) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 3;
            return;
        }
    }
    if (fn_2_68C80(index, target)) {
        if (index == 1 && lbl_2_bss_1A8248->_44F3 == 0) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 3;
            return;
        } else if (index >= 2 && index <= 6) {
            obj->_CB = 0;
        } else {
            obj->_CB = -1;
        }
    } else {
        obj->_CB = -1;
    }
    if (obj->_A2-- == 0) {
        obj->_94 = 0;
    }
}

// .text:0x0006E88C size:0x1E8
void fn_2_6E88C(Obj0B08* obj) {
    f32 step;
    f32 diff;
    f32 absDiff;
    obj->_4C = atan2(-(lbl_2_bss_1A8248->_1610[0]._00.x - obj->_00.x), -(lbl_2_bss_1A8248->_1610[0]._00.z - obj->_00.z));
    diff = fn_2_4A18C(obj->_34 - obj->_4C);
    absDiff = fabs(diff);
    if (absDiff > 2.268928f) {
        step = 1.5707964f;
    } else if (absDiff > 1.5707964f) {
        step = 0.69813174f;
    } else if (absDiff > 0.69813174f) {
        step = 0.34906587f;
    } else if (absDiff > 0.34906587f) {
        step = 0.17453294f;
    } else if (absDiff > 0.17453294f) {
        step = 0.08726647f;
    } else if (absDiff > 0.08726647f) {
        step = 0.034906585f;
    } else if (absDiff > 0.034906585f) {
        step = 0.017453292f;
    } else if (absDiff > 0.017453292f) {
        step = 0.008726646f;
    } else if (absDiff < 0.017453292f) {
        step = 0.0034906587f;
    }
    if ((diff < 0.02 && diff > 0.0f) || (diff > -0.02 && diff < 0.0f)) {
    } else if (diff < 0.0f) {
        obj->_34 += step;
    } else {
        obj->_34 -= step;
    }
    obj->_4C = obj->_34;
}

// .text:0x0006E880 size:0xC
void fn_2_6E880(Obj0B08* obj) { obj->_94 = 4; }

// .text:0x0006E848 size:0x38
void fn_2_6E848(Obj0B08* obj) { lbl_2_data_2A234[obj->_94](obj); }

// .text:0x0006E1D0 size:0x678

// .text:0x0006DE54 size:0x37C
void fn_2_6DE54(Obj0B08* obj) {
    s32 index = obj->_80;
    s32 target = lbl_2_bss_1A8248->_1610[0]._80;
    s32 state;
    s32 slot;
    fn_2_69E1C(index);
    if (index >= 2 && index <= 6) {
        state = fn_2_68670(0);
        slot = fn_2_68690(0);
        if (state == 1 && slot == index) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 4;
            return;
        }
    }
    if (fn_2_68C80(index, target)) {
        if (index == 1) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 3;
            return;
        } else if (index >= 2 && index <= 6) {
            obj->_CB = 0;
            obj->_CF = -1;
            obj->_94 = 0;
        }
    } else {
        obj->_CB = -1;
    }
    if (obj->_50 <= 0.0f) {
        obj->_AE = obj->_B2;
        obj->_B2 = obj->_B0;
        obj->_A2 = 120;
        fn_2_68FBC(index, 1);
        obj->_BA = 9;
        obj->_38 = obj->_50 = 0.0f;
        obj->_94 = 2;
    }
}

// .text:0x0006DB30 size:0x324
void fn_2_6DB30(Obj0B08* obj) {
    s32 index = obj->_80;
    s32 target = lbl_2_bss_1A8248->_1610[0]._80;
    s32 state;
    s32 slot;
    fn_2_69E1C(index);
    if (index >= 2 && index <= 6) {
        if (index == 2) {
            index = 2;
        }
        state = fn_2_68670(0);
        slot = fn_2_68690(0);
        if (state == 1 && slot == index) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 4;
            return;
        }
    }
    if (fn_2_68C80(index, target)) {
        if (index == 1) {
            fn_2_68FBC(index, 1);
            obj->_C4 = 2;
            obj->_CB = 0;
            obj->_94 = 4;
            return;
        } else if (index >= 2 && index <= 6) {
            if (lbl_2_bss_1A8248->_1610[index]._B2 == *lbl_2_data_3C2C[index - 2]) {
                obj->_CB = 0;
                obj->_A2 = 120;
                obj->_CF = 0;
            } else {
                obj->_CB = 0;
                obj->_CF = -1;
                obj->_94 = 0;
            }
        }
    } else {
        obj->_CB = -1;
    }
    if (obj->_A2-- == 0) {
        obj->_94 = 0;
    }
}

// .text:0x0006D968 size:0x1C8
void fn_2_6D968(Obj0B08* obj) {
    s32 index = obj->_80;
    f32 diff;
    obj->_4C = atan2(-(lbl_2_bss_1A8248->_1610[0]._00.x - obj->_00.x), -(lbl_2_bss_1A8248->_1610[0]._00.z - obj->_00.z));
    diff = fn_2_4A18C(obj->_34 - obj->_4C);
    if ((diff < 0.02 && diff > 0.0f) || (diff > -0.02 && diff < 0.0f)) {
        obj->_94 = 4;
    } else if (diff < 0.0f) {
        obj->_34 += 0.05235988f;
    } else {
        obj->_34 -= 0.05235988f;
    }
    obj->_4C = obj->_34;
    if (fn_2_68670(0) == 0) {
        obj->_A2 = 120;
        fn_2_68FBC(index, 1);
        obj->_BA = 9;
        obj->_38 = obj->_50 = 0.0f;
        obj->_94 = 2;
    }
}

// .text:0x0006D878 size:0xF0
void fn_2_6D878(Obj0B08* obj) {
    s32 index = obj->_80;
    if (fn_2_68670(0) == 0) {
        obj->_A2 = 120;
        fn_2_68FBC(index, 1);
        obj->_BA = 9;
        obj->_38 = obj->_50 = 0.0f;
        obj->_94 = 2;
    }
}

// .text:0x0006D840 size:0x38
void fn_2_6D840(Obj0B08* obj) { lbl_2_data_2A248[obj->_94](obj); }

// .text:0x0006D754 size:0xEC
void fn_2_6D754(Obj0B08* obj) {
    fn_2_68F08(obj->_80, 1);
    fn_2_68FBC(obj->_80, 1);
    obj->_34 = obj->_4C = 0.0f;
    obj->_94 = 1;
}

// .text:0x0006D748 size:0xC
void fn_2_6D748(Obj0B08* obj) { obj->_94 = 1; }

// .text:0x0006D710 size:0x38
void fn_2_6D710(Obj0B08* obj) { lbl_2_data_2A250[obj->_94](obj); }

// .text:0x0006D5D4 size:0x13C
void fn_2_6D5D4(Obj0B08* obj) {
    fn_2_68F08(obj->_80, 1);
    if (obj->_84 == 0) {
        fn_80062890(lbl_2_data_3C40[lbl_2_bss_1A8248->_441C]);
    } else if (obj->_84 == 1) {
        fn_80062890(lbl_2_data_3C40[6]);
    }
    obj->_4C = obj->_34 = 0.0f;
    fn_2_68FBC(obj->_80, 2);
    obj->_94 = 1;
}

// .text:0x0006D4F8 size:0xDC
void fn_2_6D4F8(Obj0B08* obj) {
    if (fn_2_8CC88(obj->_84) != 0) {
        fn_2_68FBC(obj->_80, 5);
        obj->_A2 = 30;
        obj->_94 = 2;
    }
}

// .text:0x0006D4E8 size:0x10
void fn_2_6D4E8(Obj0B08* obj) { obj->_A2--; }

// .text:0x0006D4B0 size:0x38
void fn_2_6D4B0(Obj0B08* obj) { lbl_2_data_2A25C[obj->_94](obj); }

// .text:0x0006D374 size:0x13C
void fn_2_6D374(Obj0B08* obj) {
    fn_2_68F08(obj->_80, 1);
    if (obj->_84 == 0) {
        fn_80062890(lbl_2_data_3C5C[lbl_2_bss_1A8248->_441C]);
    } else if (obj->_84 == 1) {
        fn_80062890(lbl_2_data_3C5C[6]);
    }
    obj->_4C = obj->_34 = 0.0f;
    fn_2_68FBC(obj->_80, 3);
    obj->_94 = 1;
}

// .text:0x0006D298 size:0xDC
void fn_2_6D298(Obj0B08* obj) {
    if (fn_2_8CC88(obj->_84) != 0) {
        fn_2_68FBC(obj->_80, 6);
        obj->_A2 = 30;
        obj->_94 = 2;
    }
}

// .text:0x0006D288 size:0x10
void fn_2_6D288(Obj0B08* obj) { obj->_A2--; }

// .text:0x0006D250 size:0x38
void fn_2_6D250(Obj0B08* obj) { lbl_2_data_2A268[obj->_94](obj); }

// .text:0x0006D164 size:0xEC
void fn_2_6D164(Obj0B08* obj) {
    fn_2_68F08(obj->_80, 1);
    obj->_4C = obj->_34 = 0.0f;
    fn_2_68FBC(obj->_80, 4);
    obj->_94 = 1;
}

// .text:0x0006D088 size:0xDC
void fn_2_6D088(Obj0B08* obj) {
    if (fn_2_8CC88(obj->_84) != 0) {
        fn_2_68FBC(obj->_80, 7);
        obj->_A2 = 30;
        obj->_94 = 2;
    }
}

// .text:0x0006D078 size:0x10
void fn_2_6D078(Obj0B08* obj) { obj->_A2--; }

// .text:0x0006D040 size:0x38
void fn_2_6D040(Obj0B08* obj) { lbl_2_data_2A274[obj->_94](obj); }

// .text:0x0006CDD4 size:0x26C
void fn_2_6CDD4(Obj0B08* obj) {
    s32 index = obj->_80;
    fn_2_68F08(obj->_80, 1);
    memcpy(&obj->_74, &lbl_2_data_2EA4[lbl_2_bss_1A8248->_1610[0]._B0], sizeof(Vec));
    fn_2_6A450(index, obj->_74.x, obj->_74.z);
    obj->_BA = 12;
    fn_2_69E1C(index);
    fn_2_68FBC(index, 0);
    obj->_94 = 1;
}

// .text:0x0006CCB8 size:0x11C
void fn_2_6CCB8(Obj0B08* obj) {
    s32 i;
    fn_2_69E1C(obj->_80);
    if (obj->_50 <= 0.0f) {
        obj->_BA = 4;
        obj->_C4 = 1;
        for (i = 0; i < 4; i++) {
            if (lbl_2_bss_1A8248->_1610[0]._B0 == lbl_2_data_3D30[lbl_2_bss_1A8248->_1610[0]._B2][i]) {
                lbl_2_bss_1A8248->_4448 = i;
            }
        }
        lbl_2_bss_1A8248->_1610[0]._B2 = lbl_2_bss_1A8248->_1610[0]._B0;
        obj->_94 = 2;
    }
}

// .text:0x0006CBB0 size:0x108
void fn_2_6CBB0(Obj0B08* obj) {
    s32 index = obj->_80;
    fn_2_69E1C(index);
    fn_2_68260(obj);
    if (obj->_38 <= 0.0f) {
        setObjType(&lbl_2_bss_1A8248->_1610[index], 3);
    }
}

// .text:0x0006CB78 size:0x38
void fn_2_6CB78(Obj0B08* obj) { lbl_2_data_2A280[obj->_94](obj); }

// .text:0x0006C988 size:0x1F0
void fn_2_6C988(Obj0B08* obj) {
    Mtx m;
    Vec offset;
    Vec v;
    Tracker0B08* tracker;
    fn_2_68F08(obj->_80, 1);
    tracker = lbl_2_bss_1A8248;
    PSVECSubtract(&lbl_2_data_2EA4[tracker->_1610[0]._B0], &lbl_2_data_2EA4[tracker->_1610[0]._AE], &offset);
    PSVECScale(&offset, 0.5f, &offset);
    PSMTXRotRad(m, 'Y', tracker->_1610[0]._4C);
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = -1.2f;
    PSMTXMultVec(m, &v, &v);
    PSVECAdd(&offset, &v, &offset);
    memcpy(&obj->_00, &lbl_2_data_2EA4[lbl_2_bss_1A8248->_1610[0]._AE], sizeof(Vec));
    PSVECAdd(&obj->_00, &offset, &obj->_00);
    fn_2_68FBC(obj->_80, 1);
    obj->_4C = atan2(-(tracker->_1610[0]._00.x - obj->_00.x), -(tracker->_1610[0]._00.z - obj->_00.z));
    fn_2_46C88(obj->_80, 0);
    obj->_94 = 1;
}

// .text:0x0006C97C size:0xC
void fn_2_6C97C(Obj0B08* obj) { obj->_94 = 2; }

// .text:0x0006C970 size:0xC
void fn_2_6C970(Obj0B08* obj) { obj->_94 = 2; }

// .text:0x0006C938 size:0x38
void fn_2_6C938(Obj0B08* obj) { lbl_2_data_2A28C[obj->_94](obj); }

// .text:0x0006C5E0 size:0x358
void fn_2_6C5E0(Obj0B08* obj) {
    s32 index = obj->_80;
    s32 flag;
    Vec pos;
    fn_2_68F08(index, 1);
    obj->_BA = 11;
    if (lbl_2_bss_1A8248->_4439 == 1) {
        memcpy(&obj->_74, &lbl_2_data_2EA4[40], sizeof(Vec));
        flag = 1;
    } else if (obj->_00.x > lbl_2_data_2EA4[40].x && obj->_00.z > lbl_2_data_2EA4[40].z) {
        memcpy(&obj->_74, &lbl_2_data_2EA4[42], sizeof(Vec));
        flag = 0;
    } else {
        memcpy(&obj->_74, &lbl_2_data_2EA4[40], sizeof(Vec));
        flag = 1;
    }
    fn_2_6A450(index, obj->_74.x, obj->_74.z);
    fn_2_68FBC(index, 0);
    if (lbl_2_bss_1A824C->_197843 == 0) {
        pos.x = 2.0f * obj->_00.x;
        pos.y = 2.0f * (0.3f + obj->_00.y);
        pos.z = 2.0f * obj->_00.z;
        fn_2_9033C(0x1C, &pos, 0.0f);
        fn_2_92654(0x1C, 10);
        fn_2_8F73C(0x1C, 1);
    }
    if (flag == 1) {
        obj->_94 = 1;
    } else {
        obj->_94 = 2;
    }
}

// .text:0x0006C348 size:0x298
void fn_2_6C348(Obj0B08* obj) {
    s32 index = obj->_80;
    fn_2_69E1C(index);
    if (obj->_50 <= 0.0f) {
        if (lbl_2_bss_1A8248->_4439 == 1) {
            obj->_BA = 4;
            obj->_C4 = 1;
            obj->_94 = 3;
        } else {
            memcpy(&obj->_74, &lbl_2_data_2EA4[42], sizeof(Vec));
            fn_2_6A450(index, 0.2f + obj->_74.x, 0.5f + obj->_74.z);
            fn_2_68FBC(index, 0);
            obj->_94 = 2;
        }
    }
}

// .text:0x0006C2E8 size:0x60
void fn_2_6C2E8(Obj0B08* obj) {
    fn_2_69E1C(obj->_80);
    if (obj->_50 <= 0.0f) {
        obj->_BA = 4;
        obj->_C4 = 1;
        obj->_94 = 3;
    }
}

// .text:0x0006C2C4 size:0x24
void fn_2_6C2C4(Obj0B08* obj) {
    lbl_2_bss_1A8248->_442F = 0;
    setObjType(&lbl_2_bss_1A8248->_1610[1], 0);
}

// .text:0x0006C28C size:0x38
void fn_2_6C28C(Obj0B08* obj) { lbl_2_data_2A29C[obj->_94](obj); }

// .text:0x0006C190 size:0xFC
void fn_2_6C190(Obj0B08* obj) {
    fn_2_68F08(obj->_80, 1);
    fn_2_68FBC(obj->_80, 1);
    obj->_34 = obj->_4C;
    fn_2_46C88(lbl_2_bss_1A8248->_441E, 0);
    obj->_94 = 1;
}

// .text:0x0006C120 size:0x70
void fn_2_6C120(Obj0B08* obj) {
    f32 dist = fabs(PSVECDistance(&lbl_2_bss_1A8248->_1610[0]._00, &obj->_00));
    if (dist < 1.6f && dist != 0.0f) {
        obj->_94 = 2;
    }
}

// .text:0x0006C020 size:0x100
void fn_2_6C020(Obj0B08* obj) {
    f32 diff;
    obj->_4C = atan2(-(lbl_2_bss_1A8248->_1610[0]._00.x - obj->_00.x), -(lbl_2_bss_1A8248->_1610[0]._00.z - obj->_00.z));
    diff = fn_2_4A18C(obj->_34 - obj->_4C);
    if ((diff < 0.02 && diff > 0.0f) || (diff > -0.02 && diff < 0.0f)) {
        obj->_94 = 3;
    } else if (diff < 0.0f) {
        obj->_34 += 0.05235988f;
    } else {
        obj->_34 -= 0.05235988f;
    }
    obj->_4C = obj->_34;
}

// .text:0x0006BFC0 size:0x60
void fn_2_6BFC0(Obj0B08* obj) {
    f32 dist = fabs(PSVECDistance(&lbl_2_bss_1A8248->_1610[0]._00, &obj->_00));
    if (dist > 1.6f) {
        obj->_94 = 1;
    }
}

// .text:0x0006BF88 size:0x38
void fn_2_6BF88(Obj0B08* obj) { lbl_2_data_2A2AC[obj->_94](obj); }

// .text:0x0006BE80 size:0x108
void fn_2_6BE80(Obj0B08* obj) {
    fn_2_68F08(obj->_80, 0);
    fn_2_68FBC(obj->_80, 1);
    fn_2_68D90(obj->_80, 0xFF);
    obj->_8C = 0.0f;
    obj->_94 = 1;
}

// .text:0x0006BDE0 size:0xA0
void fn_2_6BDE0(Obj0B08* obj) {
    s32 alpha;
    fn_2_68F08(obj->_80, 1);
    obj->_8C += 0.1;
    alpha = 256.0f * obj->_8C;
    if (alpha < 0xFF) {
        fn_2_68D90(obj->_80, alpha);
    } else {
        fn_2_68D90(obj->_80, 0xFF);
        obj->_94 = 2;
    }
}

// .text:0x0006BDD4 size:0xC
void fn_2_6BDD4(Obj0B08* obj) { obj->_94 = 2; }

// .text:0x0006BD9C size:0x38
void fn_2_6BD9C(Obj0B08* obj) { lbl_2_data_2A2B8[obj->_94](obj); }

// .text:0x0006BCAC size:0xF0
void fn_2_6BCAC(Obj0B08* obj) {
    fn_2_68F08(obj->_80, 0);
    fn_2_68F24(obj->_80, 9);
    obj->_34 = obj->_4C = 0.0f;
    fn_2_68D90(obj->_80, 0xFF);
    obj->_8C = 0.0f;
    obj->_94 = 1;
}

// .text:0x0006BC0C size:0xA0
void fn_2_6BC0C(Obj0B08* obj) {
    s32 alpha;
    fn_2_68F08(obj->_80, 1);
    obj->_8C += 0.1;
    alpha = 256.0f * obj->_8C;
    if (alpha < 0xFF) {
        fn_2_68D90(obj->_80, alpha);
    } else {
        fn_2_68D90(obj->_80, 0xFF);
        obj->_94 = 2;
    }
}

// .text:0x0006BC00 size:0xC
void fn_2_6BC00(Obj0B08* obj) { obj->_94 = 2; }

// .text:0x0006BBC8 size:0x38
void fn_2_6BBC8(Obj0B08* obj) { lbl_2_data_2A2C4[obj->_94](obj); }

// .text:0x0006BB7C size:0x4C
void fn_2_6BB7C(Obj0B08* obj) {
    fn_2_68F08(obj->_80, 1);
    fn_2_68D90(obj->_80, 0xFF);
    obj->_8C = 1.0f;
    obj->_94 = 1;
}

// .text:0x0006BAD8 size:0xA4
void fn_2_6BAD8(Obj0B08* obj) {
    s32 alpha;
    obj->_8C -= 0.1;
    alpha = 255.0f * obj->_8C;
    if (alpha > 1) {
        fn_2_68D90(obj->_80, alpha);
    } else {
        fn_2_68D90(obj->_80, 0);
        fn_2_68F08(obj->_80, 0);
        obj->_94 = 2;
    }
}

// .text:0x0006BAAC size:0x2C
void fn_2_6BAAC(Obj0B08* obj) {
    fn_2_68D90(obj->_80, 0xFF);
    obj->_94 = 3;
}

// .text:0x0006BA50 size:0x5C
void fn_2_6BA50(Obj0B08* obj) {
    GXColor color = lbl_800F7478[0].ambient;
    color.a = 0xFF;
    fn_800BD2CC(0, color);
    obj->_94 = 2;
}

// .text:0x0006BA18 size:0x38
void fn_2_6BA18(Obj0B08* obj) { lbl_2_data_2A2D4[obj->_94](obj); }

// .text:0x0006B744 size:0x2D4
void fn_2_6B744(Obj0B08* obj) {
    s32 index = obj->_80;
    Vec pos;
    fn_2_68F08(index, 1);
    obj->_BA = 12;
    obj->_D0 = 1;
    obj->_90 = 0.0f;
    obj->_00.y = 0.0f;
    if (lbl_2_bss_1A8248->_1610[index]._B0 == 0x30) {
        memcpy(&pos, &lbl_2_data_3198[25]._00, sizeof(Vec));
        PSVECScale(&pos, 0.5f, &pos);
        memcpy(&obj->_74, &pos, sizeof(Vec));
    } else {
        memcpy(&pos, &lbl_2_data_3198[26]._00, sizeof(Vec));
        PSVECScale(&pos, 0.5f, &pos);
        memcpy(&obj->_74, &pos, sizeof(Vec));
    }
    fn_2_6A450(index, obj->_74.x, obj->_74.z);
    fn_2_68FBC(index, 8);
    obj->_94 = 1;
}

// .text:0x0006B620 size:0x124
void fn_2_6B620(Obj0B08* obj) {
    s32 index = obj->_80;
    fn_2_69E1C(index);
    fn_2_698EC(index, 1.5f);
    if (obj->_50 <= 0.0f) {
        obj->_BA = 4;
        obj->_C4 = 1;
        obj->_94 = 2;
    }
}

// .text:0x0006B4FC size:0x124
void fn_2_6B4FC(Obj0B08* obj) {
    s32 index = obj->_80;
    fn_2_698EC(index, 1.5f);
    if (obj->_D0 == 0) {
        setObjType(&lbl_2_bss_1A8248->_1610[index], 0);
    }
}

// .text:0x0006B4C4 size:0x38
void fn_2_6B4C4(Obj0B08* obj) { lbl_2_data_2A2E0[obj->_94](obj); }

// .text:0x0006B238 size:0x28C
void fn_2_6B238(Obj0B08* obj) {
    s32 index = obj->_80;
    fn_2_68F08(index, 1);
    obj->_BA = 14;
    obj->_D0 = 1;
    obj->_90 = 0.0f;
    obj->_00.y = 0.0f;
    if (lbl_2_bss_1A8248->_1610[index]._B0 == 0x30) {
        memcpy(&obj->_74, &lbl_2_data_2EA4[50], sizeof(Vec));
    } else {
        memcpy(&obj->_74, &lbl_2_data_2EA4[18], sizeof(Vec));
    }
    fn_2_6A450(index, obj->_74.x, obj->_74.z);
    fn_2_68FBC(index, 8);
    obj->_94 = 1;
}

// .text:0x0006B120 size:0x118
void fn_2_6B120(Obj0B08* obj) {
    s32 index = obj->_80;
    fn_2_69E1C(index);
    fn_2_698EC(index, 0.0f);
    if (obj->_50 <= 0.0f) {
        obj->_BA = 4;
        obj->_94 = 2;
    }
}

// .text:0x0006B024 size:0xFC
void fn_2_6B024(Obj0B08* obj) {
    fn_2_698EC(obj->_80, 0.0f);
    if (obj->_D0 == 0) {
        obj->_C4 = 1;
    }
}

// .text:0x0006AFD4 size:0x50
s32 fn_2_6AFD4(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    if (obj->_C4 == 1) {
        obj->_C4 = 0;
        return 1;
    }
    if (obj->_C4 == 2) {
        obj->_C4 = 0;
        return 2;
    }
    return 0;
}

// .text:0x0006AF9C size:0x38
s32 fn_2_6AF9C(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    if (obj->_D0 == 0) {
        obj->_D0 = 0;
        return 1;
    }
    return 0;
}

// .text:0x0006AF80 size:0x1C
void fn_2_6AF80(s32 index, u8 value) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    obj->_C4 = value;
}

// .text:0x0006AE08 size:0x178
void fn_2_6AE08(void) {
    Obj0B08* obj;
    s32 i;
    for (i = 0; i < 8; i++) {
        obj = &lbl_2_bss_1A8248->_1610[i];
        memset(obj, 0, sizeof(Obj0B08));
        obj->_80 = i;
        obj->_84 = i;
        obj->_8C = 0.0f;
        obj->_B6 = 10;
        obj->_40 = 0.0003f * obj->_B6 + 0.1f;
        obj->_B8 = 10;
        obj->_B7 = 15;
        obj->_44 = obj->_40 / obj->_B7;
        obj->_BB = 0;
        obj->_C0 = 0;
        obj->_96 = i;
        obj->_98 = -1;
        obj->_BC = 1;
        obj->_C3 = 0;
        obj->_94 = 0;
        obj->_C6 = -1;
        obj->_C4 = 0;
        obj->_C5 = 0;
        obj->_88 = 0.0f;
        obj->_C1 = 0;
        obj->_BA = 12;
        obj->_AC = 0;
        obj->_CA = 0xFF;
        obj->_CB = -1;
        obj->_CC = -1;
    }
}

// .text:0x0006ACF4 size:0x114
void fn_2_6ACF4(void) {
    Obj0B08* obj;
    s32 i;
    for (i = 0; i < 8; i++) {
        obj = &lbl_2_bss_1A8248->_1610[i];
        obj->_80 = i;
        obj->_84 = i;
        obj->_8C = 0.0f;
        obj->_B6 = 10;
        obj->_40 = 0.0003f * obj->_B6 + 0.1f;
        obj->_B8 = 10;
        obj->_B7 = 15;
        obj->_44 = obj->_40 / obj->_B7;
        obj->_BB = 0;
        obj->_C0 = 0;
        obj->_96 = i;
        obj->_98 = -1;
        obj->_BC = 1;
        obj->_C3 = 0;
        obj->_94 = 0;
        obj->_C6 = -1;
        obj->_C4 = 0;
        obj->_C5 = 0;
        obj->_88 = 0.0f;
        obj->_C1 = 0;
        obj->_AC = 0;
        obj->_CA = 0xFF;
        obj->_CB = -1;
        obj->_CC = -1;
    }
}

// .text:0x0006ACF0 size:0x4
void fn_2_6ACF0(void) {}

// .text:0x0006ABFC size:0xF4
void fn_2_6ABFC(s32 index, s32 point) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    if (index < 2) {
        memcpy(&obj->_00, &lbl_2_data_2EA4[point], sizeof(Vec));
    } else if (index >= 2 && index <= 6) {
        memcpy(&obj->_00, &lbl_2_data_2EA4[point], sizeof(Vec));
    } else {
        memcpy(&obj->_00, &lbl_2_data_3150[index - 7], sizeof(Vec));
    }
    obj->_0C.x = 0.0f;
    obj->_0C.y = 0.0f;
    obj->_0C.z = 0.0f;
    obj->_18.x = 0.0f;
    obj->_18.y = 0.0f;
    obj->_18.z = 0.0f;
    obj->_6C = obj->_00.x;
    obj->_70 = obj->_00.z;
    obj->_38 = 0.0f;
    obj->_BB = 0;
    obj->_30 = obj->_34 = obj->_4C;
}

// .text:0x0006AB3C size:0xC0
void fn_2_6AB3C(s32 index, Vec* pos, f32 angle) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    memcpy(&obj->_00, pos, sizeof(Vec));
    obj->_0C.x = 0.0f;
    obj->_0C.y = 0.0f;
    obj->_0C.z = 0.0f;
    obj->_18.x = 0.0f;
    obj->_18.y = 0.0f;
    obj->_18.z = 0.0f;
    obj->_30 = angle;
    obj->_6C = obj->_00.x;
    obj->_70 = obj->_00.z;
    obj->_38 = 0.0f;
    obj->_BB = 0;
    obj->_30 = obj->_34 = calcAngle(-obj->_00.x, -obj->_00.z);
}

// .text:0x0006AABC size:0x80
void fn_2_6AABC(s32 index, Vec* pos) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    memcpy(&obj->_00, pos, sizeof(Vec));
    obj->_0C.x = 0.0f;
    obj->_0C.y = 0.0f;
    obj->_0C.z = 0.0f;
    obj->_18.x = 0.0f;
    obj->_18.y = 0.0f;
    obj->_18.z = 0.0f;
    obj->_6C = obj->_00.x;
    obj->_70 = obj->_00.z;
    obj->_38 = 0.0f;
    obj->_BB = 0;
}

// .text:0x0006AAB8 size:0x4
void fn_2_6AAB8(void) {}

// .text:0x0006A87C size:0x23C
void fn_2_6A87C(void) {
    lbl_2_bss_1A8248->_1610[0]._BB = 0;
    fn_2_6A708();
    fn_2_6A628();
}

// .text:0x0006A708 size:0x174
void fn_2_6A708(void) {
    Vec pos;
    Vec delta;
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[0];
    memcpy(&pos, &obj->_00, sizeof(Vec));
    PSVECSubtract(&pos, &lbl_2_data_2A340, &delta);
    delta.x *= -1.0f;
    delta.z *= -1.0f;
    pos.x += lbl_803C77B8[lbl_2_bss_1A824C->_197863]._10 / 768.0f;
    pos.z += lbl_803C77B8[lbl_2_bss_1A824C->_197863]._11 / 768.0f;
    if (0.0f != delta.x || 0.0f != delta.z) {
        lbl_2_bss_A170 = fn_2_4A1E8(delta.z, delta.x);
    }
    memcpy(&lbl_2_data_2A340, &obj->_00, sizeof(Vec));
    obj->_00.x = pos.x;
    obj->_00.y = pos.y;
    obj->_00.z = pos.z;
    obj->_4C = lbl_2_bss_A170;
}

// .text:0x0006A628 size:0xE0
void fn_2_6A628(void) {
    Mtx m;
    Vec v;
    Tracker0B08* tracker = lbl_2_bss_1A8248;
    if (!(tracker->_1610[0]._38 <= 0.0f)) {
        PSMTXRotRad(m, 'Y', tracker->_1610[0]._4C);
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = -tracker->_1610[0]._38;
        PSMTXMultVec(m, &v, &v);
        tracker->_1610[0]._18.x = v.x;
        tracker->_1610[0]._18.z = v.z;
        tracker->_1610[0]._00.x += tracker->_1610[0]._18.x;
        tracker->_1610[0]._00.z += tracker->_1610[0]._18.z;
    }
    tracker->_1610[0]._0C.x = tracker->_1610[0]._00.x;
    tracker->_1610[0]._0C.z = tracker->_1610[0]._00.z;
    if (0.0f == tracker->_1610[0]._38) {
        tracker->_1610[0]._24 = 0.0f;
        tracker->_1610[0]._2C = 0.0f;
    }
}

// .text:0x0006A5A8 size:0x80
void fn_2_6A5A8(s32 index) {
    lbl_2_bss_1A8248->_1610[index]._0C.x = lbl_2_bss_1A8248->_1610[index]._00.x;
    lbl_2_bss_1A8248->_1610[index]._0C.y = lbl_2_bss_1A8248->_1610[index]._00.y;
    lbl_2_bss_1A8248->_1610[index]._0C.z = lbl_2_bss_1A8248->_1610[index]._00.z;
    lbl_2_bss_1A8248->_1610[index]._18.x = 0.0f;
    lbl_2_bss_1A8248->_1610[index]._18.y = 0.0f;
    lbl_2_bss_1A8248->_1610[index]._18.z = 0.0f;
    lbl_2_bss_1A8248->_1610[index]._38 = 0.0f;
    lbl_2_bss_1A8248->_1610[index]._50 = 0.0f;
}

// .text:0x0006A450 size:0x158
void fn_2_6A450(s32 index, f32 x, f32 z) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    f32 dx;
    f32 dz;
    obj->_0C.x = x;
    obj->_0C.z = z;
    dx = x - obj->_00.x;
    dz = z - obj->_00.z;
    if (0.0f == dx && 0.0f == dz) {
        obj->_50 = obj->_38 = 0.0f;
    } else {
        obj->_50 = dolsqrtf2(dx * dx + dz * dz);
    }
    obj->_BB = 1;
}

// .text:0x00069E1C size:0x634
void fn_2_69E1C(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    Mtx m;
    Vec v;
    s16 angle;
    s16 target;
    f32 dz;
    f32 dx;
    f32 sqx;
    f32 sqz;
    f32 dist;
    f32 step;
    f32 diff;
    f32 absDiff;
    if (obj->_50 > 0.0f) {
        angle = fn_2_4A2C4(obj->_4C);
        target = fn_2_4A2C4(obj->_54);
        fn_2_4A310(angle, target);
        obj->_BC = 0;
        obj->_BD = 0;
        if (obj->_9E < 0x7FFE) {
            obj->_9E++;
        } else {
            obj->_9E = 0x7FFF;
        }
    } else {
        obj->_BC = 1;
        if (obj->_9E > 45) {
            obj->_9E = 45;
        }
        if (obj->_9E != 0) {
            obj->_9E--;
        }
    }
    switch (obj->_BA) {
    case 0:
        fn_2_69710(index);
        break;
    case 1:
    case 5:
        obj->_38 -= 0.0005f;
        break;
    case 2:
    case 6:
        obj->_38 -= 0.001f;
        break;
    case 3:
    case 7:
        obj->_38 -= 0.002f;
        break;
    case 4:
    case 8:
        obj->_BA += 20;
        break;
    case 24:
    case 28:
        obj->_38 -= 0.005f;
        break;
    case 9:
        obj->_38 = 0.0f;
        break;
    case 10:
        obj->_38 = 0.08f;
        break;
    case 11:
        obj->_38 = 0.12f;
        break;
    case 12:
        if (index == 0) {
            obj->_38 = lbl_2_data_3F44[lbl_2_bss_1A8248->_441C];
        } else {
            obj->_38 = 0.04f;
        }
        break;
    case 13:
        obj->_38 = 0.012f;
        break;
    case 14:
        obj->_38 = 0.025f;
        break;
    }
    if (obj->_38 <= 0.0f) {
        obj->_38 = 0.0f;
    }
    obj->_50 -= obj->_38;
    dx = obj->_00.x - obj->_0C.x;
    dz = obj->_00.z - obj->_0C.z;
    sqx = dx * dx;
    sqz = dz * dz;
    dist = dolsqrtf2(sqx + sqz);
    if (dist < obj->_38) {
        obj->_50 = -1.0f;
    }
    if (!(obj->_38 <= 0.0f)) {
        if (obj->_BA != 4 && obj->_BA != 0x18 && obj->_50 > 0.0f) {
            obj->_4C = atan2(-(obj->_0C.x - obj->_00.x), -(obj->_0C.z - obj->_00.z));
        }
        PSMTXRotRad(m, 'Y', obj->_34);
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = -obj->_38;
        PSMTXMultVec(m, &v, &v);
        obj->_18.x = v.x;
        obj->_18.z = v.z;
        obj->_00.x += obj->_18.x;
        obj->_00.z += obj->_18.z;
        if (obj->_BA != 4 && obj->_BA != 0x18 && obj->_50 > 0.0f) {
            obj->_4C = atan2(-(obj->_0C.x - obj->_00.x), -(obj->_0C.z - obj->_00.z));
            diff = fn_2_4A18C(obj->_34 - obj->_4C);
            absDiff = fabs(diff);
            if (absDiff > 2.268928f) {
                step = 1.5707964f;
            } else if (absDiff > 1.5707964f) {
                step = 0.69813174f;
            } else if (absDiff > 0.69813174f) {
                step = 0.34906587f;
            } else if (absDiff > 0.34906587f) {
                step = 0.17453294f;
            } else if (absDiff > 0.17453294f) {
                step = 0.08726647f;
            } else if (absDiff > 0.08726647f) {
                step = 0.034906585f;
            } else if (absDiff > 0.034906585f) {
                step = 0.017453292f;
            } else if (absDiff > 0.017453292f) {
                step = 0.008726646f;
            } else if (absDiff < 0.017453292f) {
                step = 0.0034906587f;
            }
            if ((diff < 0.02 && diff > 0.0f) || (diff > -0.02 && diff < 0.0f)) {
            } else if (diff < 0.0f) {
                obj->_34 += step;
            } else {
                obj->_34 -= step;
            }
            obj->_4C = obj->_34;
        }
    }
    if (0.0f == obj->_38 && obj->_BD == 0) {
        obj->_BC = 1;
    }
}

// .text:0x000699D4 size:0x448
void fn_2_699D4(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    Mtx m;
    Vec v;
    f32 dz;
    f32 dx;
    f32 sqx;
    f32 sqz;
    f32 dist;
    f32 step;
    f32 diff;
    f32 absDiff;
    if (obj->_38 <= 0.0f) {
        obj->_38 = 0.0f;
    }
    obj->_50 -= obj->_38;
    dx = obj->_00.x - obj->_0C.x;
    dz = obj->_00.z - obj->_0C.z;
    sqx = dx * dx;
    sqz = dz * dz;
    dist = dolsqrtf2(sqx + sqz);
    if (dist < obj->_38) {
        obj->_50 = -1.0f;
    }
    if (obj->_BA != 4 && obj->_BA != 0x18 && obj->_50 > 0.0f) {
        obj->_4C = atan2(-(obj->_0C.x - obj->_00.x), -(obj->_0C.z - obj->_00.z));
    }
    PSMTXRotRad(m, 'Y', obj->_34);
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    PSMTXMultVec(m, &v, &v);
    obj->_18.x = v.x;
    obj->_18.z = v.z;
    obj->_00.x += obj->_18.x;
    obj->_00.z += obj->_18.z;
    if (obj->_BA != 4 && obj->_BA != 0x18 && obj->_50 > 0.0f) {
        obj->_4C = atan2(-(obj->_0C.x - obj->_00.x), -(obj->_0C.z - obj->_00.z));
        diff = fn_2_4A18C(obj->_34 - obj->_4C);
        absDiff = fabs(diff);
        if (absDiff > 2.268928f) {
            step = 1.5707964f;
        } else if (absDiff > 1.5707964f) {
            step = 0.69813174f;
        } else if (absDiff > 0.69813174f) {
            step = 0.34906587f;
        } else if (absDiff > 0.34906587f) {
            step = 0.17453294f;
        } else if (absDiff > 0.17453294f) {
            step = 0.08726647f;
        } else if (absDiff > 0.08726647f) {
            step = 0.034906585f;
        } else if (absDiff > 0.034906585f) {
            step = 0.017453292f;
        } else if (absDiff > 0.017453292f) {
            step = 0.008726646f;
        } else if (absDiff < 0.017453292f) {
            step = 0.0034906587f;
        }
        if ((diff < 0.02 && diff > 0.0f) || (diff > -0.02 && diff < 0.0f)) {
        } else if (diff < 0.0f) {
            obj->_34 += step;
        } else {
            obj->_34 -= step;
        }
        obj->_4C = obj->_34;
    }
    if (0.0f == obj->_38 && obj->_BD == 0) {
        obj->_BC = 1;
    }
}

// .text:0x000698EC size:0xE8
void fn_2_698EC(s32 index, f32 limit) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    f32 height;
    if (obj->_D0 != 0) {
        height = -sinf_kludge(obj->_90) * 1.6f;
        obj->_90 += 0.07f;
        if (obj->_00.y > limit) {
            obj->_90 = 0.0f;
            height = 0.0f;
            obj->_D0 = 0;
            if (obj->_C3 == 0x13) {
                fn_2_68F08(obj->_80, 0);
            }
        }
        obj->_00.y = height;
    } else {
        obj->_00.y = 0.0f;
    }
}

// .text:0x00069710 size:0x1DC
void fn_2_69710(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    s16 angle;
    s16 target;
    s16 diff;
    if (obj->_9C == 0) {
        angle = fn_2_4A2C4(obj->_4C);
        target = fn_2_4A2C4(obj->_30);
        diff = fn_2_4A150(angle - target);
        if (diff < 0x200) {
            obj->_BE = 0;
        } else if (diff < 0x600) {
            obj->_BE = 3;
        } else if (diff < 0xA00) {
            obj->_BE = 1;
        } else if (diff < 0xE00) {
            obj->_BE = 2;
        } else {
            obj->_BE = 0;
        }
        if (obj->_BC != 1) {
            if (obj->_BE == 1) {
                obj->_BE = 5;
            } else {
                obj->_BE = 4;
            }
        }
    }
    if (obj->_BE == 4 || obj->_BE == 5) {
        obj->_38 += 0.5f * obj->_44;
    } else {
        obj->_38 += obj->_44;
    }
    if (obj->_C1 == 0 && obj->_C2 != 0 && obj->_A0 == 0) {
        obj->_A0 = 30;
    }
    if (obj->_C1 != 0) {
        if (obj->_38 > obj->_40) {
            obj->_38 = obj->_40;
        }
        obj->_A0 = 0;
    } else if (obj->_A0 != 0) {
        if (obj->_38 >= obj->_40) {
            obj->_38 = obj->_40;
        } else {
            obj->_A0 = 0;
        }
    } else if (obj->_38 > 0.12f) {
        obj->_38 = 0.12f;
    }
}

// .text:0x000696D4 size:0x3C
void fn_2_696D4(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    if (obj->_A0 != 0) {
        obj->_38 = obj->_3C;
    } else {
        obj->_38 = 0.0f;
    }
}

// .text:0x00069554 size:0x180
s32 fn_2_69554(s32 index, f32 x, f32 z) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    f32 dz;
    f32 dx;
    f32 sqx;
    f32 sqz;
    f32 dist;
    f32 speed;
    s32 half;
    if (x == obj->_00.x && z == obj->_00.z) {
        return 1;
    }
    dz = z - obj->_00.z;
    dx = x - obj->_00.x;
    sqx = dx * dx;
    sqz = dz * dz;
    dist = dolsqrtf2(sqx + sqz);
    half = obj->_B7 / 2;
    if (0.0f == obj->_40) {
        speed = 1.0f;
    } else {
        speed = obj->_40;
    }
    return half + (s32)(dist / speed);
}

// .text:0x000692D0 size:0x284
void fn_2_692D0(s32 index, f32 dx, f32 dz, s32 frames, f32* outX, f32* outZ, f32* outDist) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    f32 dist = 0.0f;
    f32 speed = obj->_38;
    f32 len;
    f32 nx;
    f32 nz;
    s16 angle;
    s32 i;
    if (0.0f == dx && 0.0f == dz) {
        *outX = obj->_00.x;
        *outZ = obj->_00.z;
        *outDist = dist;
        return;
    }
    len = dolsqrtf2(dx * dx + dz * dz);
    nx = dx / len;
    nz = dz / len;
    angle = fn_2_4A234(nx, nz);
    if (!(obj->_38 < 0.05f) && obj->_9A >= 0 && fn_2_4A310(angle, obj->_9A) > 0x2A8) {
        speed = 0.0f;
    }
    for (i = 0; i <= obj->_B7; i++) {
        speed += obj->_44;
        if (speed > obj->_40) {
            dist += obj->_40;
            break;
        }
        dist += speed;
    }
    frames -= i + 1;
    dist = obj->_40 * frames + dist;
    *outDist = dist;
    *outX = nx * dist + obj->_00.x;
    *outZ = nz * dist + obj->_00.z;
}

// .text:0x00069070 size:0x260
f32 fn_2_69070(s32 index, f32 x, f32 z) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    f32 dz;
    f32 dx;
    f32 sqx;
    f32 sqz;
    f32 proj;
    f32 dist;
    if (obj->_38 < 0.01f) {
        dx = obj->_00.x - x;
        dz = obj->_00.z - z;
        sqx = dx * dx;
        sqz = dz * dz;
        return dolsqrtf2(sqx + sqz);
    }
    dx = x - obj->_00.x;
    dz = z - obj->_00.z;
    proj = obj->_24 * dx + obj->_2C * dz;
    dist = dx * dx + dz * dz - proj * proj;
    if (dist < 0.0f) {
        return 0.0f;
    }
    return dolsqrtf2(dist);
}

// .text:0x00068FBC size:0xB4
void fn_2_68FBC(s32 index, s32 anim) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    AnimEntry0B08* entry = &lbl_2_data_3C84[anim];
    if (lbl_2_bss_1A824C->_197756[obj->_80] != anim) {
        fn_2_8CD58(obj->_80, entry->_0, entry->_4, 1, entry->_2, 0, 0);
        lbl_2_bss_1A824C->_197756[obj->_80] = anim;
    }
}

// .text:0x00068F24 size:0x98
void fn_2_68F24(s32 index, s32 anim) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    AnimEntry0B08* entry = &lbl_2_data_3C84[anim];
    fn_2_8CD58(obj->_80, entry->_0, entry->_4, 1, entry->_2, 0, 0);
    lbl_2_bss_1A824C->_197756[obj->_80] = anim;
}

// .text:0x00068F08 size:0x1C
void fn_2_68F08(int index, s8 value) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    obj->_C0 = value;
}

// .text:0x00068E68 size:0xA0
void fn_2_68E68(void) {
    Obj0B08* obj;
    Player0B08* player;
    s32 i;
    for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
        player = &lbl_8036E548._0C04[i];
        obj = &lbl_2_bss_1A8248->_1610[i];
        memcpy(&player->_034, &obj->_00, sizeof(Vec));
        player->_044 = obj->_4C;
        player->_25D = obj->_C0;
        player->_277 = obj->_CA;
    }
}

// .text:0x00068DE8 size:0x80
void fn_2_68DE8(s32 index, Vec* out) {
    if (index != -1) {
        memcpy(out, &lbl_2_bss_1A8248->_1610[index]._00, sizeof(Vec));
        PSVECScale(out, 2.0f, out);
    } else {
        out->x = out->y = out->z = 0.0f;
    }
}

// .text:0x00068DAC size:0x3C
void fn_2_68DAC(s32 index, Vec* pos) { memcpy(pos, &lbl_2_bss_1A8248->_1610[index]._00, sizeof(Vec)); }

// .text:0x00068D90 size:0x1C
void fn_2_68D90(s32 index, u8 value) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    obj->_CA = value;
}

// .text:0x00068C80 size:0x110
u8 fn_2_68C80(s32 index, s32 target) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    Obj0B08* other = &lbl_2_bss_1A8248->_1610[target];
    f32 dist = PSVECDistance(&obj->_00, &other->_00);
    f32 a;
    f32 b;
    if (index == 0) {
        a = lbl_2_data_3EF4[lbl_2_bss_1A8248->_441C];
        b = lbl_2_data_3F0C[target];
    } else {
        a = lbl_2_data_3F0C[index];
        b = lbl_2_data_3EF4[lbl_2_bss_1A8248->_441C];
    }
    if (dist < a + b && obj->_C0 != 0 && other->_C0 != 0) {
        return 1;
    }
    return 0;
}

// .text:0x00068B54 size:0x12C
u8 fn_2_68B54(s32 index, s32 target) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    Obj0B08* other = &lbl_2_bss_1A8248->_1610[target];
    f32 dist = PSVECDistance(&obj->_00, &other->_00);
    f32 a;
    f32 b;
    if (index == 0) {
        a = lbl_2_data_3EF4[lbl_2_bss_1A8248->_441C] + lbl_2_data_3F2C[lbl_2_bss_1A8248->_441C];
        b = lbl_2_data_3F0C[target];
    } else {
        a = lbl_2_data_3F0C[index];
        b = lbl_2_data_3EF4[lbl_2_bss_1A8248->_441C] + lbl_2_data_3F2C[lbl_2_bss_1A8248->_441C];
    }
    if (dist < a + b && obj->_C0 != 0 && other->_C0 != 0) {
        return 1;
    }
    return 0;
}

// .text:0x00068A88 size:0xCC
s32 fn_2_68A88(s32 index, s32 item) {
    Vec pos;
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    Item0B08* it = &lbl_2_bss_1A8248->_21E0[item];
    f32 dist;
    f32 a;
    f32 b;
    scaleVec(&it->_00, &pos, 0.5f);
    dist = PSVECDistance(&obj->_00, &pos);
    a = lbl_2_data_3EF4[lbl_2_bss_1A8248->_441C];
    b = lbl_2_data_3F5C;
    if (dist < a + b && obj->_C0 != 0) {
        return 1;
    }
    return 0;
}

// .text:0x000689CC size:0xBC
s16 fn_2_689CC(s32 index) {
    Vec pos;
    Vec point;
    s32 i;
    s32 bestIndex = 0;
    f32 dist;
    f32 best = 10000.0f;
    memcpy(&pos, &lbl_2_bss_1A8248->_1610[index]._00, sizeof(Vec));
    for (i = 0; i < 51; i++) {
        memcpy(&point, &lbl_2_data_2EA4[i], sizeof(Vec));
        dist = PSVECDistance(&pos, &point);
        if (dist < best) {
            best = dist;
            bestIndex = i;
        }
    }
    return bestIndex;
}

// .text:0x00068940 size:0x8C
f32 fn_2_68940(s32 index, s32 target) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    Obj0B08* other = &lbl_2_bss_1A8248->_1610[target];
    f32 angle = atan2(-(other->_00.x - obj->_00.x), -(other->_00.z - obj->_00.z));
    return fn_2_4A18C(obj->_4C) - angle;
}

// .text:0x000688A4 size:0x9C
f32 fn_2_688A4(s32 index, s32 point) {
    Vec pos;
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    f32 angle;
    memcpy(&pos, &lbl_2_data_2EA4[point], sizeof(Vec));
    angle = atan2(-(pos.x - obj->_00.x), -(pos.z - obj->_00.z));
    return fn_2_4A18C(obj->_4C) - angle;
}

// .text:0x000687A4 size:0x100
s32 fn_2_687A4(s32 index, s32 target, s32 point) {
    Vec pos;
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    Obj0B08* other = &lbl_2_bss_1A8248->_1610[target];
    f32 angle;
    f32 diff;
    angle = atan2(-(other->_00.x - obj->_00.x), -(other->_00.z - obj->_00.z));
    memcpy(&pos, &lbl_2_data_2EA4[point], sizeof(Vec));
    diff = atan2(-(pos.x - obj->_00.x), -(pos.z - obj->_00.z));
    angle -= diff;
    if (angle < 1.2217306f && angle > -1.2217306f) {
        return 1;
    }
    return 0;
}

// .text:0x000686EC size:0xB8
s32 fn_2_686EC(s32 index, s32 target) {
    f32 diff = fn_2_68940(index, target);
    if (diff < 1.2217306f && diff > -1.2217306f) {
        return 1;
    }
    return 0;
}

// .text:0x000686D0 size:0x1C
void fn_2_686D0(s32 index, s8 value) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    obj->_CF = value;
}

// .text:0x000686B0 size:0x20
s32 fn_2_686B0(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    return obj->_CB;
}

// .text:0x00068690 size:0x20
s32 fn_2_68690(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    return obj->_CC;
}

// .text:0x00068670 size:0x20
s32 fn_2_68670(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    return obj->_CD;
}

// .text:0x00068654 size:0x1C
void fn_2_68654(s32 index, s8 value) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    obj->_CD = value;
}

// .text:0x00068638 size:0x1C
void fn_2_68638(s32 index, s8 value) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    obj->_CE = value;
}

// .text:0x000684D0 size:0x168
s32 fn_2_684D0(s32 index) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[index];
    s32 i;
    obj->_CC = -1;
    for (i = 1; i < 7; i++) {
        if (fn_2_68B54(index, i) && i >= 2 && i <= 6) {
            obj->_CC = i;
            break;
        }
        obj->_CC = -1;
    }
    return obj->_CC;
}

// .text:0x000683EC size:0xE4
void fn_2_683EC(void) {
    Obj0B08* obj;
    Tracker0B08* tracker = lbl_2_bss_1A8248;
    tracker->_1610[1]._00.x = tracker->_1610[0]._00.x;
    tracker->_1610[1]._00.y = tracker->_1610[0]._00.y;
    tracker->_1610[1]._00.z = tracker->_1610[0]._00.z;
    obj = &lbl_2_bss_1A8248->_1610[1];
    fn_2_6AABC(1, &lbl_2_data_2EA4[lbl_2_bss_1A8248->_1610[0]._B2]);
    obj->_30 = obj->_34 = obj->_4C;
    lbl_2_bss_1A8248->_1610[1]._B2 = lbl_2_bss_1A8248->_1610[0]._B2;
    setObjType(&lbl_2_bss_1A8248->_1610[1], 6);
    lbl_2_bss_1A8248->_442F = 1;
}

// .text:0x0006832C size:0xC0
void fn_2_6832C(void) {
    Obj0B08* obj = &lbl_2_bss_1A8248->_1610[1];
    fn_2_6AABC(1, &lbl_2_data_2EA4[5]);
    obj->_30 = obj->_34 = obj->_4C;
    lbl_2_bss_1A8248->_1610[1]._B2 = 5;
    setObjType(&lbl_2_bss_1A8248->_1610[1], 6);
    lbl_2_bss_1A8248->_442F = 1;
}

// .text:0x00068308 size:0x24
void fn_2_68308(void) {
    setObjType(&lbl_2_bss_1A8248->_1610[1], 0);
    lbl_2_bss_1A8248->_442F = 0;
}

// .text:0x00068260 size:0xA8
void fn_2_68260(Obj0B08* obj) {
    u8 stage = lbl_2_bss_1A8248->_441C;
    s32 base = lbl_2_data_2E80[stage]._0 * 2;
    s32 a = base - lbl_2_data_2E80[stage]._4 * 2;
    s32 b = base - lbl_2_data_2E80[stage]._2 * 2;
    Player0B08* player;
    if (obj->_80 == 0 && (player = &lbl_8036E548._0C04[0]) != NULL) {
        if (player->_068 == a || player->_068 == b) {
            if (stage == 5) {
                fn_80062890(1);
            } else {
                fn_80062890(0);
            }
        }
    }
}
