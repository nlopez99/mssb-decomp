#include "challenge/rep_7978.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/mtx.h"
#include "Dolphin/gx.h"
#include "Dolphin/pad.h"

// A free-flying debug camera driven by the first controller
typedef struct Camera7978 {
    /* 0x00 */ Mtx _00;
    /* 0x30 */ Mtx44 _30;
    /* 0x70 */ Vec _70;
    /* 0x7C */ Vec _7C;
    /* 0x88 */ Vec _88;
    /* 0x94 */ u8 _94[0xA4 - 0x94];
    /* 0xA4 */ f32 _A4;
    /* 0xA8 */ f32 _A8;
    /* 0xAC */ f32 _AC;
    /* 0xB0 */ f32 _B0;
    /* 0xB4 */ f32 _B4;
    /* 0xB8 */ f32 _B8;
    /* 0xBC */ f32 _BC;
    /* 0xC0 */ f32 _C0;
    /* 0xC4 */ f32 _C4;
    /* 0xC8 */ f32 _C8;
    /* 0xCC */ f32 _CC;
    /* 0xD0 */ f32 _D0;
    /* 0xD4 */ f32 _D4;
    /* 0xD8 */ void (*_D8)(struct Camera7978* cam, u16 held, u16 pressed, u16 repeat, s8* stick);
} Camera7978;

static inline void fn_1_7978_lookAt(Camera7978* cam) {
    Vec target;

    PSVECAdd(&cam->_70, &cam->_7C, &target);
    C_MTXLookAt(cam->_00, &cam->_70, &cam->_88, &target);
}

static inline void fn_1_7978_frustum(Camera7978* cam) {
    C_MTXFrustum(cam->_30, cam->_BC * (cam->_C8 * cam->_C0) / 1280.0f, cam->_BC * (cam->_CC * cam->_C0) / 1280.0f,
                 cam->_BC * (cam->_D0 * cam->_C0) / 1280.0f, cam->_BC * (cam->_D4 * cam->_C0) / 1280.0f, cam->_C0,
                 cam->_C4);
}

// .text:0x6B0 size:0x188
void fn_1_273D8(Camera7978* cam) {
    cam->_AC = 5.0f;
    cam->_B0 = 120.0f;
    cam->_D8 = NULL;
    cam->_A4 = 0.0f;
    cam->_A8 = 0.0f;
    cam->_70.x = cam->_70.y = cam->_70.z = 0.0f;
    cam->_7C.x = cam->_7C.y = 0.0f;
    cam->_7C.z = 1.0f;
    cam->_88.x = 0.0f;
    cam->_88.y = 1.0f;
    cam->_88.z = 0.0f;
    fn_1_7978_lookAt(cam);
    cam->_B4 = 1.0f;
    cam->_B8 = 1.0f;
    cam->_BC = 1.0f / cam->_B8;
    cam->_C0 = 1.0f;
    cam->_C4 = 512.0f;
    cam->_C8 = 240.0f;
    cam->_CC = -240.0f;
    cam->_D0 = -320.0f;
    cam->_D4 = 320.0f;
    fn_1_7978_frustum(cam);
}

// .text:0x608 size:0xA8
void fn_1_27330(Camera7978* cam) {
    fn_1_7978_lookAt(cam);
    fn_1_7978_frustum(cam);
}

// .text:0x5B4 size:0x54
void fn_1_272DC(Camera7978* cam, s32 id) {
    GXSetProjection(cam->_30, GX_PERSPECTIVE);
    GXLoadPosMtxImm(cam->_00, id);
    GXSetCurrentMtx(id);
}

// .text:0x0 size:0x5B4
void fn_1_26D28(Camera7978* cam, u16 held, u16 pressed, u16 repeat, s8* stick) {
    Mtx m;
    Quaternion q;
    Vec v;

    if (cam->_D8 == NULL || cam->_D8 == fn_1_26D28) {
        if (pressed & PAD_TRIGGER_Z) {
            fn_1_273D8(cam);
        } else {
            cam->_A4 -= 3.1415927f * cam->_B0 / 180.0f * stick[2] / 128.0f / 60.0f;
            cam->_A8 -= 3.1415927f * cam->_B0 / 180.0f * stick[3] / 128.0f / 60.0f;
            while (cam->_A4 < -3.1415927f) {
                cam->_A4 += 6.2831855f;
            }
            while (cam->_A4 >= 3.1415927f) {
                cam->_A4 -= 6.2831855f;
            }
            if (cam->_A8 < -3.1385248f) {
                cam->_A8 = -3.1385248f;
            } else if (cam->_A8 > 3.1385248f) {
                cam->_A8 = 3.1385248f;
            }
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 1.0f;
            PSVECCrossProduct(&v, &cam->_88, &cam->_7C);
            PSVECNormalize(&cam->_7C, &cam->_7C);
            C_QUATRotAxisRad(&q, &cam->_7C, cam->_A8);
            PSMTXQuat(m, &q);
            PSMTXMultVec(m, &v, &cam->_7C);
            C_QUATRotAxisRad(&q, &cam->_88, cam->_A4);
            PSMTXQuat(m, &q);
            PSMTXMultVec(m, &cam->_7C, &cam->_7C);
            v.x = -cam->_AC * stick[0] / 128.0f / 60.0f;
            v.z = cam->_AC * stick[1] / 128.0f / 60.0f;
            v.y = cam->_AC * (u8)stick[4] / 150.0f / 60.0f;
            v.y -= cam->_AC * (u8)stick[5] / 150.0f / 60.0f;
            PSMTXMultVec(m, &v, &v);
            PSVECAdd(&cam->_70, &v, &cam->_70);
            cam->_B8 += cam->_B4 * ((held & PAD_BUTTON_X) != 0) / 60.0f;
            cam->_B8 -= cam->_B4 * ((held & PAD_BUTTON_Y) != 0) / 60.0f;
            cam->_B8 = 0.1f * (cam->_B8 == 0.0f) + cam->_B8 * (cam->_B8 != 0.0f);
            cam->_BC = 1.0f / cam->_B8;
        }
    } else {
        cam->_D8(cam, held, pressed, repeat, stick);
    }
}
