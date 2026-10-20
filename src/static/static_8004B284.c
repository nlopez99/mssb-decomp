#include "static/static_8004B284.h"
#include "static/static_8004AC00.h"
#include "static/particle.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "math.h"

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
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ Vec pos;
    /* 0x040 */ u8 _040[0x4];
    /* 0x044 */ f32 angle;
    /* 0x048 */ u8 _048[0x252 - 0x48];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ s8 _254;
} EffectActor;

static EffectParams lbl_800FBF10 = { 0, 4, 2, { 80000, 30000, 78000, 50, 5, 109000, 101000, 0, 40, 12800000, 8000000, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 };
static EffectParams lbl_800FBF60 = { 0, 4, 2, { 80000, 30000, 78000, 60, 10, 109000, 101000, 0, 40, 12800000, 8000000, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 };
static EffectParams lbl_800FBFB0 = { 0, 4, 2, { 80000, 30000, 78000, 60, 10, 109000, 101000, 0, 40, 12800000, 8000000, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 };
static PuffParams lbl_800FC000 = { 0, 29, 15, { 20, 30 }, { 13000, 15000 }, { -3000000, 3000000 }, { 50000, 60000 }, 0, -1, 5, 10, 0, { 0, 3000000 }, { 0, 4500000 }, 1 };
static PuffParams lbl_800FC054 = { 0, 29, 15, { 20, 30 }, { 13000, 15000 }, { -3000000, 3000000 }, { 50000, 60000 }, 0, -1, 5, 10, 0, { 0, 3000000 }, { 0, 4500000 }, 1 };
static PuffParams lbl_800FC0A8 = { 0, 29, 15, { 20, 30 }, { 13000, 15000 }, { -3000000, 3000000 }, { 50000, 60000 }, 0, -1, 5, 10, 0, { 0, 3000000 }, { 0, 4500000 }, 1 };
u8 lbl_800FC0FC[13][3] = {
    { 255, 182, 100 }, { 255, 204, 147 }, { 220, 170, 136 }, { 255, 204, 147 }, { 220, 170, 136 }, { 128, 128, 128 }, { 255, 204, 147 }, { 255, 204, 147 }, { 152, 134, 109 }, { 152, 134, 109 }, { 255, 226, 172 }, { 255, 232, 151 }, { 200, 210, 220 },
};
static u16 lbl_800FC124[32][7] = {
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
    { 34, 4, 34, 4, 4, 4, 34 },
};

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern BOOL getAnimRelatedCoordinates(int, int, Vec*);
extern s32 fn_800698F8(s32 charID);

// .text:0x8004B284 size:0x468
void fn_8004B284(void* actor, s32 action, s32 color, f32 t) {
    EffectActor* p = actor;
    f32 rem;
    s32 slot;
    s32 group;
    Vec pos;
    Vec dir;
    EffectParams* params;
    PuffParams* puff;

    if (lbl_80366158._28 == 1) {
        return;
    }
    switch (action) {
    case 0x32:
        slot = 0;
        rem = lbl_800FB804[p->_252] - t;
        t -= lbl_800FB798[p->_252];
        break;
    case 0x33:
        slot = 1;
        rem = lbl_800FB8DC[p->_252] - t;
        t -= lbl_800FB870[p->_252];
        break;
    case 0x34:
        slot = 2;
        rem = lbl_800FB9B4[p->_252] - t;
        t -= lbl_800FB948[p->_252];
        break;
    case 0x1A:
        slot = 4;
        rem = lbl_800FBA8C[p->_252] - t;
        t -= lbl_800FBA20[p->_252];
        break;
    case 0x1B:
        slot = 5;
        rem = lbl_800FBB64[p->_252] - t;
        t -= lbl_800FBAF8[p->_252];
        break;
    case 0x30:
        slot = 6;
        rem = lbl_800FBC3C[p->_252] - t;
        t -= lbl_800FBBD0[p->_252];
        break;
    }
    if (t < 0.0f || rem < 0.0f) {
        return;
    }
    dir.x = -sin(p->angle);
    dir.z = -cos(p->angle);
    dir.y = 0.0f;
    group = fn_800698F8(p->_252);
    if (!getAnimRelatedCoordinates(p->_254, lbl_800FC124[group][slot], &pos)) {
        memcpy(&pos, &p->pos, sizeof(Vec));
    }
    params = NULL;
    switch (action) {
    case 0x32:
    case 0x33:
    case 0x34:
        params = &lbl_800FBF10;
        break;
    case 0x1A:
    case 0x1B:
        params = &lbl_800FBF60;
        break;
    case 0x30:
        params = &lbl_800FBFB0;
        break;
    }
    puff = NULL;
    switch (action) {
    case 0x32:
    case 0x33:
    case 0x34:
        puff = &lbl_800FC000;
        break;
    case 0x1A:
    case 0x1B:
        puff = &lbl_800FC054;
        break;
    case 0x30:
        puff = &lbl_800FC0A8;
        break;
    }
    params->_00 = lbl_803CBD0C;
    params->_40 = (lbl_800FC0FC[color][0] << 24) | ((lbl_800FC0FC[color][1] << 16) & 0xFF0000) |
                  ((lbl_800FC0FC[color][2] << 8) & 0xFF00);
    puff->_00 = lbl_803CBD0C;
    switch (color) {
    case 1:
    case 3:
    case 7:
        fn_8002955C(&pos, &dir, (struct PuffParams*)puff);
    case 0:
    case 2:
    case 5:
    case 6:
    case 8:
    case 10:
    case 11:
    case 12:
        fn_80030D88(&pos, &dir, (struct EffectParams*)params, 5);
        break;
    }
}
