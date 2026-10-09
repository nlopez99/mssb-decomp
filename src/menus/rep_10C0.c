#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_10C0.h"
#include "menus/rep_08E8.h"
#include "menus/rep_0B08.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/pad.h"
#include "Dolphin/vec.h"
#include "string.h"

// The menus' camera
typedef struct Camera10C0 {
    /* 0x00 */ Mtx _00;
    /* 0x30 */ u16 _30;
    /* 0x32 */ u16 _32;
    /* 0x34 */ f32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ Vec _40;
    /* 0x4C */ Vec _4C;
    /* 0x58 */ s32 _58;
} Camera10C0; // size: 0x5C

typedef struct CameraBlend10C0 {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
} CameraBlend10C0; // size: 0x18

extern struct {
    /* 0x000000 */ u8 _000000[0x197608];
    /* 0x197608 */ Vec _197608;
    /* 0x197614 */ Vec _197614;
    /* 0x197620 */ Vec _197620;
    /* 0x19762C */ Vec _19762C;
    /* 0x197638 */ Vec _197638;
    /* 0x197644 */ Vec _197644;
    /* 0x197650 */ Vec _197650;
    /* 0x19765C */ Vec _19765C;
    /* 0x197668 */ CameraBlend10C0 _197668;
    /* 0x197680 */ u8 _197680[0x19774A - 0x197680];
    /* 0x19774A */ s16 _19774A;
    /* 0x19774C */ u8 _19774C[0x197845 - 0x19774C];
    /* 0x197845 */ u8 _197845;
    /* 0x197846 */ u8 _197846[0x197848 - 0x197846];
    /* 0x197848 */ u8 _197848;
    /* 0x197849 */ u8 _197849;
    /* 0x19784A */ u8 _19784A[0x197855 - 0x19784A];
    /* 0x197855 */ u8 _197855;
    /* 0x197856 */ u8 _197856;
    /* 0x197857 */ u8 _197857[0x197863 - 0x197857];
    /* 0x197863 */ s8 _197863;
} *lbl_2_bss_1A824C;

// A camera preset: position, target, angles and zoom
typedef struct CameraPreset10C0 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec target;
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
} CameraPreset10C0; // size: 0x24

extern Camera10C0 lbl_2_bss_1A81D4;
extern CameraPreset10C0 lbl_2_data_38E0[20];
extern CameraBlend10C0 lbl_2_data_3BB0[3];

extern void fn_80011640(Mtx src, Mtx dst);
extern void fn_800B806C(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
extern void makeLookAtMatrix(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);

// .text:0x000021D8 size:0x18
void fn_2_94854(s32 arg0) {
    lbl_2_bss_1A824C->_197849 = arg0;
}

// .text:0x00002060 size:0x178
void fn_2_946DC(s32 index) {
    lbl_2_bss_1A824C->_197668._00 = lbl_2_data_3BB0[index]._00;
    lbl_2_bss_1A824C->_197668._04 = lbl_2_data_3BB0[index]._04;
    lbl_2_bss_1A824C->_197668._08 = lbl_2_data_3BB0[index]._08;
    lbl_2_bss_1A824C->_197668._0C = lbl_2_data_3BB0[index]._0C;
    lbl_2_bss_1A824C->_197668._10 = lbl_2_data_3BB0[index]._10;
    lbl_2_bss_1A824C->_197668._14 = lbl_2_data_3BB0[index]._14;
    lbl_2_bss_1A824C->_197620.x = lbl_2_bss_1A81D4._4C.x;
    lbl_2_bss_1A824C->_197620.y = lbl_2_bss_1A81D4._4C.y;
    lbl_2_bss_1A824C->_197620.z = lbl_2_bss_1A81D4._4C.z;
    lbl_2_bss_1A824C->_19762C.x = lbl_2_bss_1A81D4._4C.x + 0.00001f;
    lbl_2_bss_1A824C->_19762C.y = lbl_2_bss_1A81D4._4C.y + 0.00001f;
    lbl_2_bss_1A824C->_19762C.z = lbl_2_bss_1A81D4._4C.z + 0.00001f;
    lbl_2_bss_1A824C->_197638.x = lbl_2_bss_1A81D4._40.x + 0.00001f;
    lbl_2_bss_1A824C->_197638.y = lbl_2_bss_1A81D4._40.y + 0.00001f;
    lbl_2_bss_1A824C->_197638.z = lbl_2_bss_1A81D4._40.z + 0.00001f;
    lbl_2_bss_1A824C->_197644.x = lbl_2_bss_1A81D4._40.x + 0.00002f;
    lbl_2_bss_1A824C->_197644.y = lbl_2_bss_1A81D4._40.y + 0.00002f;
    lbl_2_bss_1A824C->_197644.z = lbl_2_bss_1A81D4._40.z + 0.00002f;
}

// .text:0x00001FB8 size:0xA8
void fn_2_94634(s32 index) {
    lbl_2_bss_1A824C->_197668._00 = lbl_2_data_3BB0[index]._00;
    lbl_2_bss_1A824C->_197668._04 = lbl_2_data_3BB0[index]._04;
    lbl_2_bss_1A824C->_197668._08 = lbl_2_data_3BB0[index]._08;
    lbl_2_bss_1A824C->_197668._0C = lbl_2_data_3BB0[index]._0C;
    lbl_2_bss_1A824C->_197668._10 = lbl_2_data_3BB0[index]._10;
    lbl_2_bss_1A824C->_197668._14 = lbl_2_data_3BB0[index]._14;
    if (index == 0) {
        lbl_2_bss_1A824C->_197855 = 0;
    } else {
        lbl_2_bss_1A824C->_197855 = 1;
    }
}

// .text:0x00001FA0 size:0x18
void fn_2_9461C(s32 arg0) {
    lbl_2_bss_1A824C->_19774A = arg0;
}

// .text:0x00001F88 size:0x18
void fn_2_94604(s32 arg0) {
    lbl_2_bss_1A824C->_197856 = arg0;
}

// .text:0x000015E8 size:0x9A0
void fn_2_93C64(void) {
    Mtx44 proj;
    Vec v;
    Vec offset;
    Vec target;
    Camera10C0* camera;
    u8 idx;

    camera = &lbl_2_bss_1A81D4;
    idx = lbl_2_bss_1A824C->_197849;
    if (lbl_2_bss_1A824C->_197856 == 1) {
        memcpy(&v, &lbl_2_data_38E0[idx].pos, sizeof(Vec));
        fn_2_68DE8(lbl_2_bss_1A824C->_19774A, &offset);
        PSVECAdd(&offset, &v, &v);
        memcpy(&camera->_4C, &v, sizeof(Vec));
    } else {
        memcpy(&v, &lbl_2_data_38E0[idx].pos, sizeof(Vec));
        memcpy(&camera->_4C, &v, sizeof(Vec));
    }
    if (lbl_2_bss_1A824C->_197848 == 0) {
        if (camera->_4C.x <= -10.0f) {
            camera->_4C.x = -10.0f;
        }
        if (camera->_4C.x >= 11.0f) {
            camera->_4C.x = 11.0f;
        }
        if (camera->_4C.z <= -50.0f) {
            camera->_4C.z = -50.0f;
        }
        if (camera->_4C.z >= -22.0f) {
            camera->_4C.z = -22.0f;
        }
        memcpy(&lbl_2_bss_1A824C->_197650, &camera->_4C, sizeof(Vec));
    }
    memcpy(&lbl_2_bss_1A824C->_197608, &camera->_4C, sizeof(Vec));
    lbl_2_bss_1A824C->_197620.x = lbl_2_bss_1A824C->_197608.x;
    lbl_2_bss_1A824C->_197620.y = lbl_2_bss_1A824C->_197608.y;
    lbl_2_bss_1A824C->_197620.z = lbl_2_bss_1A824C->_197608.z;
    lbl_2_bss_1A824C->_19762C.x = lbl_2_bss_1A824C->_197608.x + 0.00001f;
    lbl_2_bss_1A824C->_19762C.y = lbl_2_bss_1A824C->_197608.y + 0.00001f;
    lbl_2_bss_1A824C->_19762C.z = lbl_2_bss_1A824C->_197608.z + 0.00001f;
    if (lbl_2_bss_1A824C->_19774A != -1) {
        fn_2_68DE8(lbl_2_bss_1A824C->_19774A, &target);
    } else {
        memcpy(&target, &lbl_2_data_38E0[idx].target, sizeof(Vec));
    }
    memcpy(&lbl_2_bss_1A824C->_19765C, &target, sizeof(Vec));
    if (lbl_2_bss_1A824C->_197848 == 0) {
        if (target.x <= -10.0f) {
            target.x = -10.0f;
        } else if (target.x >= 11.0f) {
            target.x = 11.0f;
        } else {
            lbl_2_bss_1A824C->_19765C.x = target.x;
        }
        if (target.z <= -24.0f) {
            target.z = -24.0f;
        } else if (target.z >= 8.0f) {
            target.z = 8.0f;
        } else {
            lbl_2_bss_1A824C->_19765C.z = target.z;
        }
    }
    memcpy(&lbl_2_bss_1A824C->_197614, &target, sizeof(Vec));
    lbl_2_bss_1A824C->_197638.x = lbl_2_bss_1A824C->_197614.x + 0.00001f;
    lbl_2_bss_1A824C->_197638.y = lbl_2_bss_1A824C->_197614.y + 0.00001f;
    lbl_2_bss_1A824C->_197638.z = lbl_2_bss_1A824C->_197614.z + 0.00001f;
    lbl_2_bss_1A824C->_197644.x = lbl_2_bss_1A824C->_197614.x + 0.00002f;
    lbl_2_bss_1A824C->_197644.y = lbl_2_bss_1A824C->_197614.y + 0.00002f;
    lbl_2_bss_1A824C->_197644.z = lbl_2_bss_1A824C->_197614.z + 0.00002f;
    fn_2_927C8(&camera->_4C, &target);
    memcpy(&lbl_2_bss_1A824C->_197614, &target, sizeof(Vec));
    fn_2_92CB0();
    memcpy(&camera->_4C, &lbl_2_bss_1A824C->_197608, sizeof(Vec));
    memcpy(&camera->_40, &lbl_2_bss_1A824C->_197614, sizeof(Vec));
    C_MTXFrustum(proj, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
    GXSetProjection(proj, GX_PERSPECTIVE);
    fn_800B806C(0, -240.0f, 240.0f, -320.0f, 320.0f, -512.0f, -1.0f, 1280.0f);
    camera->_58 = 0;
    camera->_38 = 0.0f;
    camera->_30 = lbl_2_data_38E0[idx]._18;
    camera->_32 = lbl_2_data_38E0[idx]._1C;
    camera->_3C = lbl_2_data_38E0[idx]._20;
}

// .text:0x0000157C size:0x6C
void fn_2_93BF8(Camera10C0* camera) {
    switch (lbl_2_bss_1A824C->_197845) {
    case 0:
        fn_2_932DC(camera);
        break;
    case 1:
        fn_2_92F2C(camera);
        break;
    }
    fn_80011640(camera->_00, camera->_00);
}

// .text:0x00000C60 size:0x91C
void fn_2_932DC(Camera10C0* camera) {
    Mtx rotX;
    Mtx rotY;
    Mtx rot;
    Vec up = { 0.0f, 1.0f, 0.0f };
    Vec forward = { 0.0f, 0.0f, 1.0f };
    Vec v;
    Vec offset;
    Vec target;
    f32 cosY;
    f32 sinY;
    s32 idx;

    idx = lbl_2_bss_1A824C->_197849;
    camera->_30 = lbl_2_data_38E0[idx]._18;
    camera->_32 = lbl_2_data_38E0[idx]._1C;
    camera->_34 = 0.0f;
    camera->_38 = 0.0f;
    v.x = camera->_30;
    v.y = camera->_32;
    v.z = 0.0f;
    PSVECScale(&v, 0.0000958738f, &v);
    PSMTXRotRad(rotX, 'X', v.x);
    PSMTXRotRad(rotY, 'Y', v.y);
    sinY = rotY[0][2];
    cosY = rotY[0][0];
    PSMTXConcat(rotY, rotX, rot);
    PSMTXMultVec(rot, &forward, &camera->_40);
    camera->_4C.x += camera->_38 * sinY - camera->_34 * cosY;
    camera->_4C.z += camera->_38 * cosY + camera->_34 * sinY;
    camera->_40.x += camera->_4C.x;
    camera->_40.y += camera->_4C.y;
    camera->_40.z += camera->_4C.z;
    if (lbl_2_bss_1A824C->_197856 == 1) {
        memcpy(&v, &lbl_2_data_38E0[idx].pos, sizeof(Vec));
        fn_2_68DE8(lbl_2_bss_1A824C->_19774A, &offset);
        PSVECAdd(&offset, &v, &v);
        memcpy(&camera->_4C, &v, sizeof(Vec));
    } else {
        memcpy(&v, &lbl_2_data_38E0[idx].pos, sizeof(Vec));
        memcpy(&camera->_4C, &v, sizeof(Vec));
    }
    if (lbl_2_bss_1A824C->_197848 == 0) {
        if (camera->_4C.x <= -10.0f) {
            camera->_4C.x = -10.0f;
        }
        if (camera->_4C.x >= 11.0f) {
            camera->_4C.x = 11.0f;
        }
        if (camera->_4C.z <= -50.0f) {
            camera->_4C.z = -50.0f;
        }
        if (camera->_4C.z >= -22.0f) {
            camera->_4C.z = -22.0f;
        }
    }
    memcpy(&lbl_2_bss_1A824C->_197608, &camera->_4C, sizeof(Vec));
    if (lbl_2_bss_1A824C->_19774A != -1) {
        fn_2_68DE8(lbl_2_bss_1A824C->_19774A, &target);
    } else {
        memcpy(&target, &lbl_2_data_38E0[idx].target, sizeof(Vec));
    }
    if (lbl_2_bss_1A824C->_197848 == 0) {
        if (target.x <= -10.0f) {
            target.x = -10.0f;
        } else if (target.x >= 11.0f) {
            target.x = 11.0f;
        } else {
            lbl_2_bss_1A824C->_19765C.x = target.x;
        }
        if (target.z <= -24.0f) {
            target.z = -24.0f;
        } else if (target.z >= 8.0f) {
            target.z = 8.0f;
        } else {
            lbl_2_bss_1A824C->_19765C.z = target.z;
        }
    }
    memcpy(&lbl_2_bss_1A824C->_197614, &target, sizeof(Vec));
    fn_2_927C8(&camera->_4C, &target);
    memcpy(&lbl_2_bss_1A824C->_197614, &target, sizeof(Vec));
    fn_2_92CB0();
    memcpy(&camera->_4C, &lbl_2_bss_1A824C->_197608, sizeof(Vec));
    memcpy(&camera->_40, &lbl_2_bss_1A824C->_197614, sizeof(Vec));
    camera->_3C = lbl_2_data_38E0[idx]._20;
    makeLookAtMatrix(camera->_00, &camera->_4C, &up, &camera->_40);
}

// .text:0x000008B0 size:0x3B0
void fn_2_92F2C(Camera10C0* camera) {
    Mtx rotX;
    Mtx rotY;
    Mtx rot;
    Vec up = { 0.0f, 1.0f, 0.0f };
    Vec angles;
    Vec forward = { 0.0f, 0.0f, 1.0f };
    f32 cosY;
    f32 sinY;

    if (!(lbl_803C77B8[lbl_2_bss_1A824C->_197863]._00 & PAD_TRIGGER_Z)) {
        camera->_30 -= lbl_803C77B8[lbl_2_bss_1A824C->_197863]._13;
        camera->_32 += lbl_803C77B8[lbl_2_bss_1A824C->_197863]._12;
        camera->_34 = lbl_803C77B8[lbl_2_bss_1A824C->_197863]._10 / -256.0f;
        camera->_38 = lbl_803C77B8[lbl_2_bss_1A824C->_197863]._11 * 0.00390625f;
        camera->_4C.y += lbl_803C77B8[lbl_2_bss_1A824C->_197863]._15 * 0.0009765625f;
        camera->_4C.y -= lbl_803C77B8[lbl_2_bss_1A824C->_197863]._14 * 0.0009765625f;
    }
    if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & PAD_BUTTON_Y) {
        camera->_3C -= 0.01f;
    } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & PAD_BUTTON_X) {
        camera->_3C += 0.01f;
    }
    angles.x = camera->_30;
    angles.y = camera->_32;
    angles.z = 0.0f;
    PSVECScale(&angles, 0.0000958738f, &angles);
    PSMTXRotRad(rotX, 'X', angles.x);
    PSMTXRotRad(rotY, 'Y', angles.y);
    sinY = rotY[0][2];
    cosY = rotY[0][0];
    PSMTXConcat(rotY, rotX, rot);
    PSMTXMultVec(rot, &forward, &camera->_40);
    camera->_4C.x += camera->_38 * sinY - camera->_34 * cosY;
    camera->_4C.z += camera->_38 * cosY + camera->_34 * sinY;
    camera->_40.x += camera->_4C.x;
    camera->_40.y += camera->_4C.y;
    camera->_40.z += camera->_4C.z;
    makeLookAtMatrix(camera->_00, &camera->_4C, &up, &camera->_40);
}

// .text:0x00000634 size:0x27C
void fn_2_92CB0(void) {
    Vec result;
    Vec prevPos;
    Vec cur;
    Vec prevTarget;
    Vec pos;

    if (lbl_2_bss_1A824C->_197855 != 0) {
        pos.x = lbl_2_bss_1A824C->_197608.x;
        pos.y = lbl_2_bss_1A824C->_197608.y;
        pos.z = lbl_2_bss_1A824C->_197608.z;
        prevPos.x = lbl_2_bss_1A824C->_19762C.x;
        prevPos.y = lbl_2_bss_1A824C->_19762C.y;
        prevPos.z = lbl_2_bss_1A824C->_19762C.z;
        cur.x = pos.x;
        cur.y = pos.y;
        cur.z = pos.z;
        prevTarget.x = lbl_2_bss_1A824C->_197620.x;
        prevTarget.y = lbl_2_bss_1A824C->_197620.y;
        prevTarget.z = lbl_2_bss_1A824C->_197620.z;
        result = fn_2_9267C(prevPos, cur, prevTarget, 0.01f, lbl_2_bss_1A824C->_197668._00,
                            lbl_2_bss_1A824C->_197668._04, lbl_2_bss_1A824C->_197668._08);
        lbl_2_bss_1A824C->_197608.x = result.x;
        lbl_2_bss_1A824C->_197608.y = result.y;
        lbl_2_bss_1A824C->_197608.z = result.z;
        lbl_2_bss_1A824C->_19762C.x = result.x;
        lbl_2_bss_1A824C->_19762C.y = result.y;
        lbl_2_bss_1A824C->_19762C.z = result.z;
        lbl_2_bss_1A824C->_197620.x = pos.x;
        lbl_2_bss_1A824C->_197620.y = pos.y;
        lbl_2_bss_1A824C->_197620.z = pos.z;
    }
}

// .text:0x000003B8 size:0x27C
void fn_2_92A34(Vec* arg0, Vec* pos) {
    Vec result;
    Vec prevPos;
    Vec cur;
    Vec prevTarget;

    if (lbl_2_bss_1A824C->_197855 != 0) {
        pos->x = fn_2_4A18C(pos->x);
        pos->y = fn_2_4A18C(pos->y);
        prevPos.x = lbl_2_bss_1A824C->_197644.x;
        prevPos.y = lbl_2_bss_1A824C->_197644.y;
        prevPos.z = lbl_2_bss_1A824C->_197644.z;
        cur.x = pos->x;
        cur.y = pos->y;
        cur.z = 0.0f;
        prevTarget.x = lbl_2_bss_1A824C->_197638.x;
        prevTarget.y = lbl_2_bss_1A824C->_197638.y;
        prevTarget.z = lbl_2_bss_1A824C->_197638.z;
        result = fn_2_9267C(prevPos, cur, prevTarget, 0.01f, lbl_2_bss_1A824C->_197668._0C,
                            lbl_2_bss_1A824C->_197668._10, lbl_2_bss_1A824C->_197668._14);
        lbl_2_bss_1A824C->_197638.x = pos->x;
        lbl_2_bss_1A824C->_197638.y = pos->y;
        lbl_2_bss_1A824C->_197638.z = 0.0f;
        lbl_2_bss_1A824C->_197644.x = result.x;
        lbl_2_bss_1A824C->_197644.y = result.y;
        lbl_2_bss_1A824C->_197644.z = result.z;
        pos->x = result.x;
        pos->y = result.y;
    }
}

// .text:0x0000014C size:0x26C
void fn_2_927C8(Vec* arg0, Vec* pos) {
    Vec result;
    Vec prevPos;
    Vec cur;
    Vec prevTarget;
    Vec unused;

    if (lbl_2_bss_1A824C->_197855 != 0) {
        memcpy(&unused, pos, sizeof(Vec));
        prevPos.x = lbl_2_bss_1A824C->_197644.x;
        prevPos.y = lbl_2_bss_1A824C->_197644.y;
        prevPos.z = lbl_2_bss_1A824C->_197644.z;
        memcpy(&cur, pos, sizeof(Vec));
        prevTarget.x = lbl_2_bss_1A824C->_197638.x;
        prevTarget.y = lbl_2_bss_1A824C->_197638.y;
        prevTarget.z = lbl_2_bss_1A824C->_197638.z;
        result = fn_2_9267C(prevPos, cur, prevTarget, 0.01f, lbl_2_bss_1A824C->_197668._0C,
                            lbl_2_bss_1A824C->_197668._10, lbl_2_bss_1A824C->_197668._14);
        lbl_2_bss_1A824C->_197638.x = pos->x;
        lbl_2_bss_1A824C->_197638.y = pos->y;
        lbl_2_bss_1A824C->_197638.z = pos->z;
        lbl_2_bss_1A824C->_197644.x = result.x;
        lbl_2_bss_1A824C->_197644.y = result.y;
        lbl_2_bss_1A824C->_197644.z = result.z;
        pos->x = result.x;
        pos->y = result.y;
        pos->z = result.z;
    }
}

// .text:0x00000000 size:0x14C
Vec fn_2_9267C(Vec a, Vec b, Vec c, f32 scale, f32 p2, f32 p3, f32 p4) {
    Vec ab;
    Vec scaled;
    Vec cb;
    f32 dist;
    f32 t;

    PSVECSubtract(&a, &b, &ab);
    dist = PSVECDistance(&a, &b);
    PSVECSubtract(&c, &b, &cb);
    PSVECScale(&cb, scale, &scaled);
    t = p2 * (p4 - dist) + p3 * (PSVECDotProduct(&scaled, &ab) / dist);
    PSVECNormalize(&ab, &ab);
    PSVECScale(&ab, t * scale, &ab);
    PSVECAdd(&a, &ab, &a);
    return a;
}
