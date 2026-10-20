#include "static/static_8004C094.h"
#include "static/static_8004AC00.h"
#include "static/static_8004B284.h"
#include "static/particle.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

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

// One emitter's timing: a burst every period from start until end
typedef struct EffectBurst {
    /* 0x000 */ EffectParams base;
    /* 0x050 */ s32 start[3];
    /* 0x05C */ s32 end[3];
    /* 0x068 */ s32 period[3];
    /* 0x074 */ s32 window[3];
    /* 0x080 */ EffectParams sub[3];
} EffectBurst; // size: 0x170

typedef struct EffectActor {
    /* 0x000 */ u8 _000[0x252];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ s8 _254;
    /* 0x255 */ u8 _255[0x25D - 0x255];
    /* 0x25D */ u8 _25D;
} EffectActor;

EffectBurst lbl_800FC720 = {
    { 0, 4, 20, { 80000, 30000, 78000, 60, 10, 109000, 101000, 0, 40, 12800000, 0, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 },
    { 500000, 2050000, 200000 },
    { 1100000, 2300000, 500000 },
    { 450000, 400000, 400000 },
    { 1100000, 2400000, 600000 },
    {
        { 0, 4, 20, { 60000, 20000, 88000, 28, 4, 109000, 101000, 0, 128, 10100000, 0, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 },
        { 0, 4, 20, { 60000, 20000, 88000, 28, 4, 109000, 101000, 0, 128, 10100000, 0, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 },
        { 0, 4, 20, { 60000, 20000, 88000, 28, 4, 109000, 101000, 0, 128, 10100000, 0, 0, 0 }, 0xFFFFFF00, 0, 75000, 0 },
    },
};

EffectParams* lbl_803CB860 = &lbl_800FC720.base;
u8 lbl_803CB864[2][3] = { { 255, 255, 255 }, { 255, 182, 100 } };

extern BOOL fn_8001B728(s32 idx, s32 kind, Vec* pos);

// .text:0x8004C510 size:0xE8
void fn_8004C510(void* actor, s32 a, s32 color, f32 t) {
    EffectActor* p = actor;
    Vec pos;

    if (t == 0.0f) {
        fn_80062D94(actor, a, color, t);
        return;
    }
    if (t == lbl_800FBD80[p->_252]) {
        pos.x = 0.0f;
        pos.y = 0.0f;
        pos.z = 0.0f;
        fn_8001B728(p->_254, 4, &pos);
        pos.y = 0.0f;
        lbl_803CB860->_00 = lbl_803CBD0C;
        lbl_803CB860->_40 = (lbl_800FC0FC[color][0] << 24) | ((lbl_800FC0FC[color][1] << 16) & 0xFF0000) |
                            ((lbl_800FC0FC[color][2] << 8) & 0xFF00);
        fn_80031CA4(&pos, (struct EffectParams*)lbl_803CB860);
    }
}

// .text:0x8004C19C size:0x374
// 93.97%: the target keeps each array's address apart from its constant index
// (addi r3,r31,116; lwz r3,8(r3) for window[2]) and walks end, period, sub and
// each colour byte with its own pointer in the loop; no helper form found yet.
void fn_8004C19C(void* actor, s32 action, s32 color, f32 t) {
    EffectActor* p = actor;
    EffectBurst* b = &lbl_800FC720;
    s32* start;
    s32* end;
    s32* period;
    EffectParams* sub;
    u8* c;
    f32 fe;
    f32 fs;
    f32 fp;
    f32 d;
    Vec pos;
    s32 i;

    if ((u8)p->_252 == 18) {
        if (action == 0x48) {
            if (t < b->window[2] / 100000.0f) {
                p->_25D = 2;
            }
            fe = b->end[2] / 100000.0f;
            fs = b->start[2] / 100000.0f;
            fp = b->period[2] / 100000.0f;
            if (t < fe) {
                d = t - fs;
                if (d >= 0.0f) {
                    while (d >= fp) {
                        d -= fp;
                    }
                    if (d == 0.0f) {
                        pos.x = 0.0f;
                        pos.y = 0.0f;
                        pos.z = 0.0f;
                        fn_8001B728(p->_254, 4, &pos);
                        pos.y = 0.0f;
                        b->sub[2]._00 = lbl_803CBD0C;
                        b->sub[2]._40 = (lbl_800FC0FC[color][0] << 24) | ((lbl_800FC0FC[color][1] << 16) & 0xFF0000) |
                                        ((lbl_800FC0FC[color][2] << 8) & 0xFF00);
                        fn_80031CA4(&pos, (struct EffectParams*)&b->sub[2]);
                    }
                }
            }
        } else {
            if (t >= b->window[0] / 100000.0f && t < b->window[1] / 100000.0f) {
                p->_25D = 2;
            }
            start = b->start;
            c = lbl_800FC0FC[color];
            period = b->period;
            end = b->end;
            sub = b->sub;
            for (i = 0; i < 2; i++) {
                fe = *end / 100000.0f;
                fs = *start / 100000.0f;
                fp = *period / 100000.0f;
                if (!(t >= fe)) {
                    d = t - fs;
                    if (d >= 0.0f) {
                        while (d >= fp) {
                            d -= fp;
                        }
                        if (d == 0.0f) {
                            pos.x = 0.0f;
                            pos.y = 0.0f;
                            pos.z = 0.0f;
                            fn_8001B728(p->_254, 4, &pos);
                            pos.y = 0.0f;
                            sub->_00 = lbl_803CBD0C;
                            sub->_40 = (c[0] << 24) | ((c[1] << 16) & 0xFF0000) | ((c[2] << 8) & 0xFF00);
                            fn_80031CA4(&pos, (struct EffectParams*)sub);
                        }
                    }
                }
                period++;
                end++;
                sub++;
                start++;
            }
        }
    }
}

// .text:0x8004C108 size:0x94
void fn_8004C108(Vec* pos, u8 kind) {
    EffectParams params;
    EffectParams* pp = &params;

    if (pos != NULL) {
        memcpy(pp, lbl_803CB860, sizeof(EffectParams));
        params._00 = lbl_803CBD0C;
        params._40 = (lbl_803CB864[kind][0] << 24) | ((lbl_803CB864[kind][1] << 16) & 0xFF0000) |
                     ((lbl_803CB864[kind][2] << 8) & 0xFF00);
        fn_80031CA4(pos, (struct EffectParams*)pp);
    }
}

// .text:0x8004C094 size:0x74
void fn_8004C094(Vec* pos) {
    EffectParams params;
    EffectParams* pp = &params;

    if (pos != NULL) {
        memcpy(pp, lbl_803CB860, sizeof(EffectParams));
        params._00 = lbl_803CBD0C;
        params._0C[0] = 120000;
        params._0C[1] = 60000;
        fn_80031CA4(pos, (struct EffectParams*)pp);
    }
}
