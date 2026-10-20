#include "static/static_8005268C.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "math.h"
#include "string.h"

typedef struct CameraSet {
    /* 0x000 */ camera_803c639c_s cams[2];
    /* 0x150 */ camera_803c639c_s cams2[2];
} CameraSet;

typedef struct CameraCtrl {
    /* 0x00 */ Vec _00;
    /* 0x0C */ Vec _0C;
    /* 0x18 */ u8 _18[0x24 - 0x18];
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ u8 _30[0x3C - 0x30];
    /* 0x3C */ u8 _3C;
    /* 0x3D */ u8 _3D;
} CameraCtrl;

extern CameraSet lbl_803C639C;
extern CameraCtrl lbl_803C60BC;
extern struct CamTask {
    /* 0x00 */ void (*func)(void);
}* lbl_803CC1B8;
extern void makeLookAtMatrix(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);
extern void fn_80011640(Mtx src, Mtx dst);
extern void fn_800369DC(f32 zoom);
extern void fn_800B806C(s32 arg0, f32 top, f32 bottom, f32 left, f32 right, f32 nearZ, f32 farZ, f32 arg7);
extern fn_800528AC_parameter lbl_803CBD10;
extern s32 lbl_803CBD14;

s32 lbl_803CB880 = 1;

// .text:0x80052F98 size:0x238
void possiblyTransitionBlackScreen(void) {
    camera_803c639c_s* cam;
    s32 i;
    f32 scale;

    lbl_803CB880 = 1;
    for (i = 0; i < 2; i++) {
        cam = &lbl_803C639C.cams[i];
        cam->eye.x = 0.0f;
        cam->eye.y = -1.0f;
        cam->eye.z = -5.0f;
        cam->target.x = 0.0f;
        cam->target.y = -1.0f;
        cam->target.z = -4.0f;
        cam->Up.x = 0.0f;
        cam->Up.y = 1.0f;
        cam->Up.z = 0.0f;
        cam->zoom = 1.0f;
        scale = 1.0f / cam->zoom;
        C_MTXFrustum(cam->proj, -0.175f * scale, 0.175f * scale, 0.25f * scale, -0.25f * scale, 1.0f, 512.0f);
        fn_800B806C(0, -240.0f * scale, 240.0f * scale, -320.0f * scale, 320.0f * scale, -512.0f, -1.0f, 1280.0f);
    }
    lbl_803C60BC._00.x = 0.0f;
    lbl_803C60BC._00.y = -1.0f;
    lbl_803C60BC._00.z = 0.0f;
    lbl_803C60BC._0C.x = 0.0f;
    lbl_803C60BC._0C.y = -1.0f;
    lbl_803C60BC._0C.z = 1.0f;
    lbl_803C60BC._24 = -3.1415927f;
    lbl_803C60BC._28 = 0.0f;
    lbl_803C60BC._2C = 0.0f;
    lbl_803C60BC._3C = 1;
    lbl_803C60BC._3D = 0;
    lbl_803CBD10 = 0;
    lbl_803CC1B8->func = fn_80052968;
}

// .text:0x80052D70 size:0x228
void fn_80052D70(void) {
    camera_803c639c_s* cam;
    s32 i;
    f32 scale;

    lbl_803CB880 = 1;
    for (i = 0; i < 2; i++) {
        cam = &lbl_803C639C.cams[i];
        cam->eye.x = 0.0f;
        cam->eye.y = -1.0f;
        cam->eye.z = -5.0f;
        cam->target.x = 0.0f;
        cam->target.y = -1.0f;
        cam->target.z = -4.0f;
        cam->Up.x = 0.0f;
        cam->Up.y = 1.0f;
        cam->Up.z = 0.0f;
        cam->zoom = 1.0f;
        scale = 1.0f / cam->zoom;
        C_MTXFrustum(cam->proj, -0.175f * scale, 0.175f * scale, 0.25f * scale, -0.25f * scale, 1.0f, 512.0f);
        fn_800B806C(0, -240.0f * scale, 240.0f * scale, -320.0f * scale, 320.0f * scale, -512.0f, -1.0f, 1280.0f);
    }
    lbl_803C60BC._00.x = 0.0f;
    lbl_803C60BC._00.y = -1.0f;
    lbl_803C60BC._00.z = 0.0f;
    lbl_803C60BC._0C.x = 0.0f;
    lbl_803C60BC._0C.y = -1.0f;
    lbl_803C60BC._0C.z = 1.0f;
    lbl_803C60BC._24 = -3.1415927f;
    lbl_803C60BC._28 = 0.0f;
    lbl_803C60BC._2C = 0.0f;
    lbl_803C60BC._3C = 1;
    lbl_803C60BC._3D = 0;
    lbl_803CBD10 = 0;
}

// .text:0x80052968 size:0x408
// 99.92%: the view of the second camera-0 block in split-screen mode is kept
// in r30 where the target uses r29; declaration orders change nothing.
void fn_80052968(void) {
    camera_803c639c_s* cam;
    MtxPtr view;
    f32 scale;

    if (lbl_803CB880 == 1) {
        if (lbl_803CBD10 != NULL) {
            lbl_803CBD10(&lbl_803C639C.cams[0]);
        }
        makeLookAtMatrix(lbl_803C639C.cams[0].view, &lbl_803C639C.cams[0].eye, &lbl_803C639C.cams[0].Up, &lbl_803C639C.cams[0].target);
        scale = 1.0f / lbl_803C639C.cams[0].zoom;
        C_MTXFrustum(lbl_803C639C.cams[0].proj, -0.175f * scale, 0.175f * scale, 0.25f * scale, -0.25f * scale, 1.0f, 512.0f);
        fn_800B806C(0, -240.0f * scale, 240.0f * scale, -320.0f * scale, 320.0f * scale, -512.0f, -1.0f, 1280.0f);
        fn_80011640(lbl_803C639C.cams[0].view, lbl_803C639C.cams[0].view);
        scale = 1.0f / lbl_803C639C.cams[0].zoom;
        C_MTXFrustum(lbl_803C639C.cams[0].proj, -0.175f * scale, 0.175f * scale, 0.25f * scale, -0.25f * scale, 1.0f, 512.0f);
        fn_800B806C(0, -240.0f * scale, 240.0f * scale, -320.0f * scale, 320.0f * scale, -512.0f, -1.0f, 1280.0f);
    } else if (lbl_803CB880 == 2) {
        if (lbl_803CBD10 != NULL) {
            lbl_803CBD10(&lbl_803C639C.cams[1]);
        }
        cam = &lbl_803C639C.cams[1];
        view = cam->view;
        makeLookAtMatrix(view, &cam->eye, &cam->Up, &cam->target);
        scale = 1.0f / lbl_803C639C.cams[1].zoom;
        C_MTXFrustum(cam->proj, -0.175f * scale, 0.175f * scale, 0.25f * scale, -0.25f * scale, 1.0f, 512.0f);
        fn_800B806C(0, -240.0f * scale, 240.0f * scale, -320.0f * scale, 320.0f * scale, -512.0f, -1.0f, 1280.0f);
        fn_80011640(view, view);
        scale = 1.0f / lbl_803C639C.cams[1].zoom;
        C_MTXFrustum(cam->proj, -0.175f * scale, 0.175f * scale, 0.375f * scale, -0.125f * scale, 1.0f, 512.0f);
        fn_800B806C(1, -240.0f * scale, 240.0f * scale, -160.0f * scale, 160.0f * scale, -512.0f, -1.0f, 1280.0f);
        if (lbl_803CBD10 != NULL) {
            lbl_803CBD10(&lbl_803C639C.cams[0]);
        }
        view = lbl_803C639C.cams[0].view;
        makeLookAtMatrix(view, &lbl_803C639C.cams[0].eye, &lbl_803C639C.cams[0].Up, &lbl_803C639C.cams[0].target);
        scale = 1.0f / lbl_803C639C.cams[0].zoom;
        C_MTXFrustum(lbl_803C639C.cams[0].proj, -0.175f * scale, 0.175f * scale, 0.25f * scale, -0.25f * scale, 1.0f, 512.0f);
        fn_800B806C(0, -240.0f * scale, 240.0f * scale, -320.0f * scale, 320.0f * scale, -512.0f, -1.0f, 1280.0f);
        fn_80011640(view, view);
        scale = 1.0f / lbl_803C639C.cams[0].zoom;
        C_MTXFrustum(lbl_803C639C.cams[0].proj, -0.175f * scale, 0.175f * scale, 0.125f * scale, -0.375f * scale, 1.0f, 512.0f);
        fn_800B806C(0, -240.0f * scale, 240.0f * scale, -160.0f * scale, 160.0f * scale, -512.0f, -1.0f, 1280.0f);
    }
    memcpy(lbl_803C639C.cams2, lbl_803C639C.cams, sizeof(lbl_803C639C.cams));
    fn_800369DC(lbl_803C639C.cams[0].zoom);
}

// .text:0x800528C0 size:0xA8
// 95.83%: the target loads v.x before 320.0f and keeps the constant in f1;
// operand orders of the two fmadds change nothing.
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
    lbl_803CBD10 = arg;
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
