#include "static/static_8005268C.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "math.h"

typedef struct CameraSet {
    /* 0x000 */ camera_803c639c_s cams[2];
    /* 0x150 */ camera_803c639c_s cams2[2];
} CameraSet;

extern CameraSet lbl_803C639C;
extern s32 lbl_803CBD10;
extern s32 lbl_803CBD14;

s32 lbl_803CB880 = 1;

// .text:0x80052F98 size:0x238
void possiblyTransitionBlackScreen(void) {
}

// .text:0x80052D70 size:0x228
void fn_80052D70(void) {
}

// .text:0x80052968 size:0x408
void fn_80052968(void) {
}

// .text:0x800528C0 size:0xA8
void fn_800528C0(f32 x, f32 y, f32 z, s16* screenX, s16* screenY) {
    Vec v;

    v.x = x;
    v.y = y;
    v.z = z;
    PSMTXMultVec(lbl_803C639C.cams[0].view, &v, &v);
    PSMTX44MultVec(lbl_803C639C.cams[0].proj, &v, &v);
    *screenX = 320.0f * v.x + 320.0f;
    *screenY = 224.0f * -v.y + 224.0f;
}

// .text:0x800528B4 size:0xC
void fn_800528B4(void) {
    lbl_803CBD10 = 0;
}

// .text:0x800528AC size:0x8
void fn_800528AC(fn_800528AC_parameter arg) {
    lbl_803CBD10 = (s32)arg;
}

// .text:0x800527C4 size:0xE8
s32 fn_800527C4(Vec* pos) {
    Vec v;

    v.x = pos->x;
    v.y = -fabs(pos->y);
    v.z = pos->z;
    PSMTXMultVec(lbl_803C639C.cams[0].view, &v, &v);
    PSMTX44MultVec(lbl_803C639C.cams[0].proj, &v, &v);
    return !((v.x > 1.0f) | (v.x < -1.0f) | (v.y > 1.0f) | (v.y < -1.0f) | (v.z > 0.0f) | (v.z < -1.0f));
}

// .text:0x800527BC size:0x8
s32 fn_800527BC(void) {
    return lbl_803CB880;
}

// .text:0x80052798 size:0x24
void fn_80052798(s32 mode) {
    if (mode < 1) {
        mode = 1;
    } else if (mode > 2) {
        mode = 2;
    }
    lbl_803CB880 = mode;
}

// .text:0x80052768 size:0x30
camera_803c639c_s* fn_80052768_getCamera(int idx) {
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 2) {
        idx = 1;
    }
    return &lbl_803C639C.cams[idx];
}

// .text:0x80052734 size:0x34
camera_803c639c_s* fn_80052734(s32 idx) {
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 2) {
        idx = 1;
    }
    return &lbl_803C639C.cams2[idx];
}

// .text:0x80052694 size:0xA0
void fn_80052694(s32 idx) {
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 2) {
        idx = 1;
    }
    lbl_803CBD14 = idx;
    GXSetProjection(lbl_803C639C.cams2[idx].proj, GX_PERSPECTIVE);
    if (lbl_803CB880 == 1) {
        GXSetScissor(0, 0, 640, 448);
    } else if (lbl_803CB880 == 2) {
        GXSetScissor(idx * 320, 0, 320, 448);
    }
}

// .text:0x8005268C size:0x8
s32 fn_8005268C(void) {
    return lbl_803CBD14;
}
