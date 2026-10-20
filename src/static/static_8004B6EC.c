#include "static/static_8004B6EC.h"
#include "static/anim.h"
#include "static/static_8004AC00.h"
#include "static/particle.h"
#include "Dolphin/mtx.h"
#include "C3/control.h"
#include "static/UnknownHomes_Static.h"

typedef struct EffectPlayer {
    /* 0x000 */ u8 _000[0x2C];
    /* 0x02C */ u8* _2C;
    /* 0x030 */ u8* _30;
    /* 0x034 */ u8 _034[0x62 - 0x34];
    /* 0x062 */ s16 _62;
    /* 0x064 */ u8 _064[0x18A - 0x64];
    /* 0x18A */ u16 _18A;
    /* 0x18C */ u8 _18C[0x196 - 0x18C];
    /* 0x196 */ u16 _196;
    /* 0x198 */ u8 _198[0x1DA - 0x198];
    /* 0x1DA */ u16 _1DA;
    /* 0x1DC */ u16 _1DC;
    /* 0x1DE */ u8 _1DE[0x1F6 - 0x1DE];
    /* 0x1F6 */ u16 _1F6;
    /* 0x1F8 */ u16 _1F8;
    /* 0x1FA */ u16 _1FA;
    /* 0x1FC */ u8 _1FC[0x252 - 0x1FC];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ s8 _254;
    /* 0x255 */ u8 _255[0x25A - 0x255];
    /* 0x25A */ u8 _25A;
    /* 0x25B */ u8 _25B;
    /* 0x25C */ u8 _25C[0x274 - 0x25C];
    /* 0x274 */ u8 _274;
    /* 0x275 */ u8 _275[0x278 - 0x275];
    /* 0x278 */ u8 _278;
} EffectPlayer;

typedef struct EffectParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 _0C[13];
    /* 0x40 */ s32 _40;
    /* 0x44 */ s32 _44;
    /* 0x48 */ s32 _48;
    /* 0x4C */ s32 _4C;
} EffectParams; // size: 0x50

typedef struct EffectOffset {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 z;
} EffectOffset;

typedef struct EffectActor {
    /* 0x000 */ u8 _000[0x40];
    /* 0x040 */ Vec rot;
    /* 0x04C */ u8 _04C[0x252 - 0x4C];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ s8 _254;
} EffectActor;

typedef struct EffectActorRef {
    /* 0x00 */ void* _00;
} EffectActorRef;

u16 lbl_800FC388[4][2] = { { 2, 3 }, { 6, 7 }, { 6, 7 }, { 4, 5 } };

EffectParams lbl_800FC398 = {
    0, 7, 3, { 100000, 30000, 10000, 12, 8, 110000, 50000, 0, 60, 4500000, 20000000, 0, 2000000 },
    0xFFFFFF00, 0, 75000, 0,
};
EffectParams lbl_800FC3E8 = {
    0, 7, 10, { 18000, 20000, 60000, 12, 6, 109000, 101000, 0, 60, 4500000, 9400000, -1000000, 4500000 },
    0xFFFFFF00, 0, 75000, 0,
};
EffectParams lbl_800FC438 = {
    0, 4, 1, { 60000, 10000, 50000, 30, 8, 104000, 105999, 0, 90, 12800000, 10000000, 1000000, 6000000 },
    0x3C3C3C00, 0, 75000, 0,
};
EffectParams* lbl_800FC488[3] = { &lbl_800FC398, &lbl_800FC3E8, &lbl_800FC438 };
EffectOffset lbl_800FC494[54] = { 0 };

extern BOOL fn_8001B728(s32 idx, s32 kind, Vec* pos);
extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern void fn_8001D180(s32 idx, s32 arg1, s32 arg2);
extern void fn_800B2B74(void* actor, u16 id);
extern void fn_800B2BA8(void* dst, u16 id, void* src, u16 index);
extern void fn_800B2BE4(void* actor, u16 id);

// .text:0x8004BEB0 size:0x1E4
void fn_8004BEB0(void* actor, s32 a, s32 b, f32 t) {
    EffectActor* p = actor;
    Vec pos;
    Vec dir;
    Mtx m;
    Control ctrl;
    EffectOffset* ofs;

    if (lbl_80366158._28 == 1) {
        return;
    }
    if (t < lbl_800FBCA8[p->_252] || t > lbl_800FBD14[p->_252]) {
        return;
    }
    pos.x = lbl_800FC494[p->_252].x / 100000.0f;
    ofs = &lbl_800FC494[p->_252];
    pos.y = ofs->y / 100000.0f;
    pos.z = ofs->z / 100000.0f;
    fn_8001B728(p->_254, 4, &pos);
    ctrl.type = 0;
    CTRLSetRotation(&ctrl, p->rot.x, p->rot.y, p->rot.z);
    CTRLBuildMatrix(&ctrl, m);
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 1.0f;
    PSMTXMultVec(m, &dir, &dir);
    lbl_800FC488[0]->_00 = lbl_800FC488[1]->_00 = lbl_800FC488[2]->_00 = lbl_803CBD0C;
    fn_80030D88(&pos, &dir, (struct EffectParams*)lbl_800FC488[0], 5);
    fn_80030D88(&pos, &dir, (struct EffectParams*)lbl_800FC488[1], 5);
    fn_80030D88(&pos, &dir, (struct EffectParams*)lbl_800FC488[2], 5);
}

// .text:0x8004BD6C size:0x144
s32 fn_8004BD6C(EffectPlayer* player, EffectActorRef* ref) {
    u16 a;
    u16 b;
    s32 i;
    s32 j;

    switch (player->_252) {
    case 38:
        a = player->_18A;
        i = 2;
        b = player->_196;
        j = 3;
        break;
    case 18:
        a = player->_1F6;
        i = 4;
        b = player->_1F8;
        j = 5;
        break;
    case 40:
        a = player->_1DA;
        i = 6;
        b = player->_1DC;
        j = 7;
        break;
    case 41:
        a = player->_1DA;
        i = 6;
        b = player->_1DC;
        j = 7;
        break;
    default:
        return 0;
    }
    fn_8001D180(player->_254, 0, 0);
    fn_8001D180(player->_254, 1, 0);
    fn_8001D180(player->_254, i, 0);
    fn_8001D180(player->_254, j, 0);
    if (a != 0xFFFF) {
        fn_800B2B74(ref->_00, a);
    }
    if (b != 0xFFFF) {
        fn_800B2B74(ref->_00, b);
    }
    return 0;
}

// .text:0x8004BAEC size:0x280
void fn_8004BAEC(EffectPlayer* player) {
    s32 side;
    s32 i;
    u16 ids[2];
    struct AnimSub* anims[2];
    u8* model;

    if (player != NULL) {
        fn_8001D180(player->_254, 0, 0);
        fn_8001D180(player->_254, 1, 0);
        switch (player->_252) {
        case 38:
            i = 0;
            break;
        case 18:
            i = 3;
            break;
        }
        if ((player->_62 >= 0x69 && player->_62 < 0x75) || player->_62 == -1) {
            fn_8001D180(player->_254, lbl_800FC388[i][0], 0);
            fn_8001D180(player->_254, lbl_800FC388[i][1], 0);
            return;
        }
        model = player->_30;
        if (model != NULL) {
            if (g_d_GameSettings.GameModeSelected == 6 || g_d_GameSettings.GameModeSelected == 7) {
                if (player->_278 != 0) {
                    side = !player->_25B;
                } else {
                    side = !player->_25A;
                }
            } else if (player->_254 >= 9) {
                side = !player->_25B;
            } else {
                side = !player->_25A;
            }
            anims[side] = model[0x5D] != 0 ? (struct AnimSub*)(model + 0x10) : NULL;
            anims[!side] = player->_30[0xC1] != 0 ? (struct AnimSub*)(player->_30 + 0x74) : NULL;
            ids[side] = lbl_800FC388[i][0];
            ids[!side] = lbl_800FC388[i][1];
            for (i = 0; i < 2; i++) {
                if (((anims[i] != NULL ? fn_80024D2C(anims[i]) : 0) & 0x20000000) &&
                    (player->_274 != 0 || player->_278 != 0)) {
                    fn_8001D180(player->_254, ids[i], 1);
                } else {
                    fn_8001D180(player->_254, ids[i], 0);
                }
            }
        }
    }
}

// .text:0x8004B7F4 size:0x2F8
void fn_8004B7F4(EffectPlayer* player) {
    s32 i;
    s32 side;
    u16 ids[2];
    struct AnimSub* anims[2];
    u8* model;

    switch (player->_252) {
    case 40:
        i = 1;
        break;
    case 41:
        i = 2;
        break;
    }
    if ((player->_62 >= 0x69 && player->_62 < 0x75) || player->_62 == -1) {
        fn_8001D180(player->_254, lbl_800FC388[i][0], 0);
        fn_8001D180(player->_254, lbl_800FC388[i][1], 0);
        fn_8001D180(player->_254, 0, 0);
        fn_8001D180(player->_254, 1, 0);
        return;
    }
    if (g_d_GameSettings.GameModeSelected == 6) {
        if (player->_278 != 0) {
            side = !player->_25B;
            fn_8001D180(player->_254, !side, 0);
        } else {
            side = !player->_25A;
            fn_8001D180(player->_254, !side, 1);
        }
    } else if (g_d_GameSettings.GameModeSelected == 7) {
        side = !player->_25B;
        fn_8001D180(player->_254, !side, 0);
    } else if (player->_254 >= 9) {
        side = !player->_25B;
        fn_8001D180(player->_254, !side, 0);
    } else {
        side = !player->_25A;
        fn_8001D180(player->_254, !side, 1);
    }
    fn_8001D180(player->_254, side, 0);
    model = player->_30;
    ids[side] = lbl_800FC388[i][0];
    ids[!side] = lbl_800FC388[i][1];
    if (model != NULL) {
        if (player->_278 == 0) {
            fn_8001D180(player->_254, ids[0], 0);
            fn_8001D180(player->_254, ids[1], 0);
            return;
        }
        anims[side] = (struct AnimSub*)(model + 0x10);
        anims[!side] = (struct AnimSub*)(model + 0x74);
        i = 1;
        do {
            if (fn_80024D2C(anims[i]) & 0x20000000) {
                fn_8001D180(player->_254, ids[i], 1);
            } else {
                fn_8001D180(player->_254, ids[i], 0);
            }
        } while (i-- != 0);
    }
}

// .text:0x8004B7B4 size:0x40
s32 fn_8004B7B4(EffectPlayer* player, EffectActorRef* ref) {
    if (player->_1FA != 0xFFFF) {
        fn_800B2BA8(ref->_00, player->_1FA, NULL, 0);
    }
    return 0;
}

// .text:0x8004B6EC size:0xC8
void fn_8004B6EC(EffectPlayer* player, EffectActorRef* ref) {
    BOOL done;

    if (player == NULL || player->_2C == NULL) {
        done = TRUE;
    } else {
        done = ((fn_80024D2C((struct AnimSub*)(player->_2C + 0x10)) >> 28) & 1) ^ 1;
    }
    if (done) {
        if (player->_1F8 != 0xFFFF) {
            fn_800B2BE4(ref->_00, player->_1F8);
        }
        if (player->_1FA != 0xFFFF) {
            fn_800B2BA8(ref->_00, player->_1FA, NULL, 0);
        }
    } else {
        if (player->_1F8 != 0xFFFF) {
            fn_800B2BA8(ref->_00, player->_1F8, NULL, 0);
        }
        if (player->_1FA != 0xFFFF) {
            fn_800B2BE4(ref->_00, player->_1FA);
        }
    }
}
