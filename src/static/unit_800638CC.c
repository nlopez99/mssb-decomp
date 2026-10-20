#include "static/unit_800638CC.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

// Per-fielder position tracking and the spark effects drawn from it

typedef struct MbTrack {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec prev;
    /* 0x18 */ u32 _18;
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

typedef struct MbFielder {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ Vec _034;
    /* 0x040 */ u8 _040[0x252 - 0x40];
    /* 0x252 */ s8 charId;
    /* 0x253 */ u8 _253[0x276 - 0x253];
    /* 0x276 */ u8 _276;
} MbFielder;

typedef struct MbFielders {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ MbFielder* fielders[9];
} MbFielders;

extern MbTrack lbl_802E4BC0[9];
extern MbFielders lbl_8036E548;
extern s32 lbl_803CBD0C;

extern BOOL fn_8001B728(s32 fielder, s32 bone, Vec* out);
extern void fn_8002B7F8(Vec* pos, MbSpark* params, u8 glow);
extern u8 fn_800527C4(Vec* pos);

s8 lbl_80108D30[10] = { -1, 7, 8, 13, 15, 28, 29, 30, 31, 32 };
s8 lbl_80108D3C[10] = { -1, 7, 8, 13, 15, 28, 29, 30, 31, 32 };
MbSpark lbl_80108D48 = {
    0, 9, 4, 30, 15, { 0.6f, 1.4f, 0.6f }, { 1.2f, 1.2f, 2.0f }, { 0, 255, 0 }, 0.02f, 0.0f, 360.0f,
    8, 1, 90, 50, { 0.0f, 2.0f, 2.8f }, { 255, 200, 0 }, 14,
};
f32 lbl_803CB898 = 1.0f;
f32 lbl_803CB89C = 1.5f;
f32 lbl_803CB8A0 = 0.7f;
f32 lbl_803CB8A4 = 0.7f;
f32 lbl_803CB8A8 = 1.0f;
f32 lbl_803CB8AC = 0.5f;
f32 lbl_803CB8B0 = 0.25f;
f32 lbl_803CB8B4 = 0.35f;
f32 lbl_803CB8B8 = 0.1f;
s8 lbl_803CB8BC[5] = { -1, 2, 9, 10, 11 };
s8 lbl_803CB8C4 = -1;
s8 lbl_803CB8C8[3] = { -1, 14, 37 };

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
s32 fn_800639BC(s8 fielder, Vec* pos, Vec* prev) {
    Vec diff;
    Vec bone;
    MbTrack* t;
    s32 ret;
    MbFielder* f;
    s32 i;
    s8 c;
    f32 size;
    f32 spread;
    f32 depth;

    f = lbl_8036E548.fielders[fielder];
    t = &lbl_802E4BC0[fielder];
    ret = 0;
    for (i = 0; i < 3; i++) {
        if (f->charId == lbl_803CB8C8[i]) {
            return 0;
        }
    }
    if (!fn_800527C4(&f->_034)) {
        return 0;
    }
    size = lbl_803CB898;
    spread = lbl_803CB8A4;
    for (i = 0; i < 5; i++) {
        if (f->charId == lbl_803CB8BC[i]) {
            size = lbl_803CB89C;
            spread = lbl_803CB8A8;
        }
    }
    for (i = 0; i < 10; i++) {
        if (f->charId == lbl_80108D30[i]) {
            size = lbl_803CB8A0;
            spread = lbl_803CB8AC;
        }
    }
    PSVECSubtract(pos, prev, &diff);
    if (!PSVECMag(&diff)) {
        if (t->_18 == 0) {
            bone.x = bone.y = bone.z = 0.0f;
            if (fn_8001B728(fielder, 0x23, &bone)) {
                bone.y = 0.0f;
                fn_80064430(&bone, 0, size, 0.0f);
            }
            bone.x = bone.y = bone.z = 0.0f;
            if (fn_8001B728(fielder, 0x1F, &bone)) {
                bone.y = 0.0f;
                fn_80064430(&bone, 0, size, 0.0f);
            }
            ret = 1;
            t->_18++;
        } else if (t->_18 >= 15) {
            t->_18 = 0;
        } else {
            t->_18++;
        }
    } else {
        c = f->charId;
        if (c == 13 || (c >= 29 && c <= 32)) {
            f32 deep;

            depth = lbl_803CB8B0;
            deep = lbl_803CB8B4;
            if (c == lbl_803CB8C4) {
                depth = deep;
            }
            for (i = 0; i < 10; i++) {
                if (c == lbl_80108D3C[i]) {
                    depth = lbl_803CB8B8;
                }
            }
            t->_18 = 0;
            bone.x = bone.y = bone.z = 0.0f;
            if (fn_8001B728(fielder, 0x23, &bone)) {
                if (bone.y >= -depth && t->pos.y < -depth) {
                    bone.y = 0.0f;
                    fn_80064430(&bone, 1, size, spread);
                    ret = 3;
                }
                t->pos = bone;
            }
            bone.x = bone.y = bone.z = 0.0f;
            if (fn_8001B728(fielder, 0x1F, &bone)) {
                if (bone.y >= -depth && t->prev.y < -depth) {
                    bone.y = 0.0f;
                    fn_80064430(&bone, 1, size, spread);
                    ret = 3;
                }
                t->prev = bone;
            }
        } else {
            bone.x = bone.y = bone.z = 0.0f;
            if ((t->_1C & 4) && !(f->_276 & 4)) {
                fn_8001B728(fielder, 0x23, &bone);
                bone.y = 0.0f;
                fn_80064430(&bone, 1, size, spread);
                ret = 3;
            }
            bone.x = bone.y = bone.z = 0.0f;
            if ((t->_1C & 2) && !(f->_276 & 2)) {
                fn_8001B728(fielder, 0x1F, &bone);
                bone.y = 0.0f;
                fn_80064430(&bone, 1, size, spread);
                ret = 3;
            }
            t->_1C = f->_276;
        }
    }
    return ret;
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

