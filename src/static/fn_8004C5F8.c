#include "static/fn_8004C5F8.h"
#include "static/fn_8004AC00.h"
#include "static/fn_8004B284.h"
#include "static/particle.h"
#include "static/UnknownHomes_Static.h"

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

typedef struct PuffParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 tex;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 life[2];
    /* 0x14 */ s32 speed[2];
    /* 0x1C */ s32 spin[2];
    /* 0x24 */ s32 size[2];
    /* 0x2C */ s32 gravity;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32 _34;
    /* 0x38 */ s32 _38;
    /* 0x3C */ s32 _3C;
    /* 0x40 */ s32 pitch[2];
    /* 0x48 */ s32 yaw[2];
    /* 0x50 */ s32 _50;
} PuffParams; // size: 0x54

typedef struct EffectActor {
    /* 0x000 */ u8 _000[0x44];
    /* 0x044 */ f32 angle;
    /* 0x048 */ u8 _048[0x254 - 0x48];
    /* 0x254 */ s8 _254;
    /* 0x255 */ u8 _255[0x276 - 0x255];
    /* 0x276 */ u8 _276;
    /* 0x277 */ u8 _277[0x27A - 0x277];
    /* 0x27A */ u8 _27A;
} EffectActor;

static EffectParams lbl_800FC890 = { 0, 4, 4, { 40000, 10000, 10000, 60, 15, 110000, 102000, 0, 40, 12800000, 1000000, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 };
static EffectParams lbl_800FC8E0 = { 0, 4, 7, { 64999, 10000, 10000, 60, 15, 110000, 101000, 0, 40, 12800000, 3000000, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 };
static EffectParams lbl_800FC930 = { 0, 4, 3, { 64999, 0, 10000, 30, 5, 129999, 104999, 0, 60, 12800000, 6000000, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 };
static PuffParams lbl_800FC980 = { 0, 29, 10, { 10, 12 }, { 15000, 20000 }, { -3000000, 3000000 }, { 35000, 40000 }, 500, -1, 5, 10, 0, { 0, 3000000 }, { 0, 4500000 }, 1 };
static PuffParams lbl_800FC9D4 = { 0, 29, 15, { 10, 20 }, { 20000, 21000 }, { -3000000, 3000000 }, { 40000, 45000 }, 500, -1, 5, 10, 0, { 1000000, 3000000 }, { 1000000, 4500000 }, 1 };

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern u8 lbl_803CBBC0;

extern BOOL getAnimRelatedCoordinates(int, int, Vec*);

// .text:0x8004C5F8 size:0x404
void fn_8004C5F8(void* actor, s32 a, s32 color, f32 t) {
    EffectParams* params;
    PuffParams* puff;
    s32 lit;
    Vec dir;
    Vec pos;
    EffectActor* p = actor;

    if (lbl_80366158._28 == 1) {
        return;
    }
    dir.x = fn_800335EC(0.5f + 1024.0f * p->angle / 3.1415927f);
    dir.z = fn_800335BC(0.5f + 1024.0f * p->angle / 3.1415927f);
    dir.y = 0.0f;
    lit = p->_276 & 1;
    switch (color) {
    case 1:
    case 3:
    case 7:
        if (lit) {
            puff = &lbl_800FC9D4;
            params = p->_27A != 0 ? &lbl_800FC930 : &lbl_800FC8E0;
            params->_00 = lbl_803CBD0C;
            params->_40 = (lbl_800FC0FC[color][0] << 24) | ((lbl_800FC0FC[color][1] << 16) & 0xFF0000) |
                          ((lbl_800FC0FC[color][2] << 8) & 0xFF00);
        } else {
            puff = &lbl_800FC980;
        }
        puff->_00 = lbl_803CBD0C;
        if (lit && p->_27A != 0) {
            p->_27A = 0;
            if (lbl_803CBBC0 != 0) {
                getAnimRelatedCoordinates(p->_254, 30, &pos);
                pos.y = 0.0f;
                fn_80030D88(&pos, &dir, (struct EffectParams*)params, 5);
            } else {
                getAnimRelatedCoordinates(p->_254, 34, &pos);
                pos.y = 0.0f;
                fn_80030D88(&pos, &dir, (struct EffectParams*)params, 5);
            }
        }
        if ((p->_276 & 0xA) == 2) {
            getAnimRelatedCoordinates(p->_254, 30, &pos);
            pos.y = 0.0f;
            if (lit && p->_27A == 0) {
                fn_80030D88(&pos, &dir, (struct EffectParams*)params, 5);
            }
            fn_8002955C(&pos, &dir, (struct PuffParams*)puff);
        }
        if ((p->_276 & 0x14) == 4) {
            getAnimRelatedCoordinates(p->_254, 34, &pos);
            pos.y = 0.0f;
            if (lit && p->_27A == 0) {
                fn_80030D88(&pos, &dir, (struct EffectParams*)params, 5);
            }
            fn_8002955C(&pos, &dir, (struct PuffParams*)puff);
        }
        break;
    case 0:
    case 2:
    case 5:
    case 6:
    case 8:
    case 10:
    case 11:
    case 12:
        if (!lit) {
            params = &lbl_800FC890;
        } else if (p->_27A != 0) {
            params = &lbl_800FC930;
        } else {
            params = &lbl_800FC8E0;
        }
        params->_00 = lbl_803CBD0C;
        params->_40 = (lbl_800FC0FC[color][0] << 24) | ((lbl_800FC0FC[color][1] << 16) & 0xFF0000) |
                      ((lbl_800FC0FC[color][2] << 8) & 0xFF00);
        if (lit && p->_27A != 0) {
            p->_27A = 0;
            if (lbl_803CBBC0 != 0) {
                getAnimRelatedCoordinates(p->_254, 30, &pos);
                pos.y = 0.0f;
                fn_80030D88(&pos, &dir, (struct EffectParams*)params, 5);
                return;
            }
            getAnimRelatedCoordinates(p->_254, 34, &pos);
            pos.y = 0.0f;
            fn_80030D88(&pos, &dir, (struct EffectParams*)params, 5);
            return;
        }
        if ((p->_276 & 0xA) == 2) {
            getAnimRelatedCoordinates(p->_254, 30, &pos);
            pos.y = 0.0f;
            fn_80030D88(&pos, &dir, (struct EffectParams*)params, 5);
        }
        if ((p->_276 & 0x14) == 4) {
            getAnimRelatedCoordinates(p->_254, 34, &pos);
            pos.y = 0.0f;
            fn_80030D88(&pos, &dir, (struct EffectParams*)params, 5);
        }
        break;
    }
}
