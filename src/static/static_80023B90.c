#include "static/static_80023B90.h"
#include "Dolphin/mtx.h"

typedef struct LightDesc {
    /* 0x0 */ u16 height;
    /* 0x2 */ u16 pitch;
    /* 0x4 */ u16 yaw;
    /* 0x6 */ u8 r;
    /* 0x7 */ u8 g;
    /* 0x8 */ u8 b;
} LightDesc;

typedef struct LightPos {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 r;
    /* 0x0D */ u8 g;
    /* 0x0E */ u8 b;
} LightPos;

// .text:0x80023B90 size:0x164
void fn_80023B90(LightDesc* desc, LightPos* light) {
    Vec side = { 1.0f, 0.0f, 0.0f };
    Vec up = { 0.0f, 1.0f, 0.0f };
    Mtx m;
    Mtx rot;

    PSMTXRotAxisRad(rot, &side, 3.1415925f * desc->pitch / 2048.0f);
    PSMTXConcat(m, rot, m);
    PSMTXRotAxisRad(m, &up, 3.1415925f * (desc->yaw + 0x800) / 2048.0f);
    PSMTXConcat(m, rot, m);
    up.y = desc->height;
    PSMTXMultVec(m, &up, &up);
    light->pos.x = up.x;
    light->pos.y = up.y;
    light->pos.z = up.z;
    light->r = desc->r;
    light->g = desc->g;
    light->b = desc->b;
}
