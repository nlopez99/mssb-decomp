#include "static/unit_800638CC.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

// Per-fielder position tracking and the spark effects drawn from it

typedef struct MbTrack {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec prev;
    /* 0x18 */ s32 _18;
    /* 0x1C */ u8 _1C;
} MbTrack; // size: 0x20

// fn_8002B7F8's parameter block (static/particle.c names its fields differently)
typedef struct MbSpark {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 glowTex;
    /* 0x08 */ s32 glowCount;
    /* 0x0C */ s32 glowLife;
    /* 0x10 */ s32 glowSwitch;
    /* 0x14 */ f32 glowH[3];
    /* 0x20 */ f32 glowW[3];
    /* 0x2C */ s32 glowAlpha[3];
    /* 0x38 */ f32 radius;
    /* 0x3C */ f32 angle;
    /* 0x40 */ f32 arc;
    /* 0x44 */ s32 sparkTex;
    /* 0x48 */ s32 sparkCount;
    /* 0x4C */ s32 sparkLife;
    /* 0x50 */ s32 sparkSwitch;
    /* 0x54 */ f32 size[3];
    /* 0x60 */ s32 alpha[3];
    /* 0x6C */ s32 _6C;
} MbSpark; // size: 0x70

extern MbTrack lbl_802E4BC0[9];
extern MbSpark lbl_80108D48;
extern s32 lbl_803CBD0C;

extern void fn_8002B7F8(Vec* pos, MbSpark* params, u8 glow);

// .text:0x80064430 size:0x104
void fn_80064430(Vec* pos, u8 glow, f32 size, f32 spread) {
    MbSpark params;

    memcpy(&params, &lbl_80108D48, sizeof(MbSpark));
    params._00 = lbl_803CBD0C;
    params.glowH[0] *= spread;
    params.glowH[1] *= spread;
    params.glowH[2] *= spread;
    params.glowW[0] *= spread;
    params.glowW[1] *= spread;
    params.glowW[2] *= spread;
    params.radius *= spread;
    params.size[0] *= size;
    params.size[1] *= size;
    params.size[2] *= size;
    fn_8002B7F8(pos, &params, glow);
}

// .text:0x80064344 size:0xEC
void fn_80064344(Vec* pos, Vec* vel) {
    MbSpark params;
    f32 scale = 3.0f * PSVECMag(vel);

    memcpy(&params, &lbl_80108D48, sizeof(MbSpark));
    params._00 = lbl_803CBD0C;
    params.glowH[0] *= scale;
    params.glowH[1] *= scale;
    params.glowH[2] *= scale;
    params.glowW[0] *= scale;
    params.glowW[1] *= scale;
    params.glowW[2] *= scale;
    params.radius *= scale;
    params.size[0] *= scale;
    params.size[1] *= scale;
    params.size[2] *= scale;
    fn_8002B7F8(pos, &params, 1);
}

// .text:0x800639BC size:0x988
void fn_800639BC(void) {
}

// .text:0x80063958 size:0x64
void fn_80063958(s8 index) {
    MbTrack* t = &lbl_802E4BC0[index];

    memset(&t->pos, 0, sizeof(Vec));
    memset(&t->prev, 0, sizeof(Vec));
    t->_18 = 0;
    t->_1C = 0;
}

// .text:0x800638CC size:0x8C
void fn_800638CC(void) {
    u32 i;

    for (i = 0; i < 9; i++) {
        fn_80063958(i);
    }
}

