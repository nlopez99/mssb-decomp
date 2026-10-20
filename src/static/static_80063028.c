#include "static/static_80063028.h"
#include "Dolphin/mtx.h"
#include "C3/control.h"
#include "static/UnknownHomes_Static.h"
#include "math.h"

typedef struct FlipBone {
    /* 0x00 */ u8 _00[0x60];
    /* 0x60 */ Control ctrl;
    /* 0xA4 */ Control blend;
} FlipBone;

typedef struct FlipOwner {
    /* 0x00 */ u8 _00[0x94];
    /* 0x94 */ s32 (*buildMtx)(u16* id, FlipBone* bone, MtxPtr m);
} FlipOwner;

extern void fn_800B84AC(Control* a, Control* b, Control* out);
s32 lbl_803CB890 = 1;

extern void CTRLBuildMatrix_Flip(Control* ctrl, MtxPtr m, s32 flip);

// .text:0x800638B4 size:0x18
s32 fn_800638B4(void* arg0, FlipOwner** owner) {
    (*owner)->buildMtx = fn_800637DC;
    return 0;
}

// .text:0x800637DC size:0xD8
s32 fn_800637DC(u16* id, FlipBone* bone, MtxPtr m) {
    switch (*id) {
    case 0x47:
        fn_800B84AC(&bone->ctrl, &bone->blend, &bone->ctrl);
        CTRLBuildMatrix_Flip(&bone->ctrl, m, 0);
        return 1;
    case 0x40:
        fn_800B84AC(&bone->ctrl, &bone->blend, &bone->ctrl);
        fn_80063028(&bone->ctrl, m, 4);
        return 1;
    case 0x41:
        fn_800B84AC(&bone->ctrl, &bone->blend, &bone->ctrl);
        CTRLBuildMatrix_Flip(&bone->ctrl, m, 1);
        return 1;
    }
    return 0;
}

// .text:0x800637D4 size:0x8
s32 fn_800637D4(void) {
    return 0;
}

// .text:0x800637BC size:0x18
s32 fn_800637BC(void* arg0, FlipOwner** owner) {
    (*owner)->buildMtx = fn_80063718;
    return 0;
}

// .text:0x80063718 size:0xA4
s32 fn_80063718(u16* id, FlipBone* bone, MtxPtr m) {
    switch (*id) {
    case 0x4A:
        fn_800B84AC(&bone->ctrl, &bone->blend, &bone->ctrl);
        fn_800633AC(&bone->ctrl, m, lbl_803CB890);
        return 1;
    case 0x4B:
        fn_800B84AC(&bone->ctrl, &bone->blend, &bone->ctrl);
        fn_800633AC(&bone->ctrl, m, lbl_803CB890);
        return 1;
    }
    return 0;
}

// .text:0x800633AC size:0x36C
// Registers only, in the z rotation block: the target assigns its temporaries f1-f8 in another order
void fn_800633AC(Control* ctrl, Mtx m, s32 flip) {
    Mtx rot;
    Mtx scale;
    Mtx scaleQuat;
    Mtx invQuat;
    Mtx result;
    Mtx mirror;
    Mtx flipMtx;
    f32 t;
    f32 t2;

    if (ctrl->type & CTRL_MTX) {
        PSMTXCopy(ctrl->controlParams.m, m);
        return;
    }
    PSMTXScale(mirror, 1.0f, -1.0f, 1.0f);
    PSMTXIdentity(flipMtx);
    if (flip & 1) {
        PSMTXRotRad(flipMtx, 'X', 3.1415927f);
    }
    if (flip & 2) {
        PSMTXRotRad(flipMtx, 'Y', 3.1415927f);
    }
    if (flip & 4) {
        PSMTXRotRad(flipMtx, 'Z', 3.1415927f);
    }
    PSMTXIdentity(m);
    PSMTXIdentity(rot);
    PSMTXIdentity(scale);
    PSMTXIdentity(scaleQuat);
    PSMTXIdentity(invQuat);
    PSMTXIdentity(result);
    if (ctrl->type & CTRL_ROT_QUAT) {
        PSMTXQuat(rot, &ctrl->controlParams.srt.r);
    } else if (ctrl->type & CTRL_ROT_EULER) {
        if (ctrl->controlParams.srt.r.x != 0.0f) {
            f32 s;
            f32 theta;
            f32 c;

            theta = 0.017453292f * ctrl->controlParams.srt.r.x;
            s = sin(theta);
            c = cos(theta);
            rot[0][0] = 1.0f;
            rot[0][1] = 0.0f;
            rot[0][2] = 0.0f;
            rot[0][3] = 0.0f;
            rot[1][0] = 0.0f;
            rot[1][1] = c;
            rot[1][2] = -s;
            rot[1][3] = 0.0f;
            rot[2][0] = 0.0f;
            rot[2][1] = s;
            rot[2][2] = c;
            rot[2][3] = 0.0f;
        }
        if (ctrl->controlParams.srt.r.y != 0.0f) {
            f32 theta;
            f32 s;
            f32 c;

            theta = 0.017453292f * ctrl->controlParams.srt.r.y;
            s = sin(theta);
            c = cos(theta);
            rot[0][0] = c;
            rot[0][1] = rot[2][1] * s;
            rot[0][2] = rot[2][2] * s;
            rot[2][0] = -s;
            rot[2][1] = rot[2][1] * c;
            rot[2][2] = rot[2][2] * c;
        }
        if (ctrl->controlParams.srt.r.z != 0.0f) {
            f32 theta;
            f32 s;
            f32 c;

            theta = 0.017453292f * ctrl->controlParams.srt.r.z;
            s = sin(theta);
            c = cos(theta);
            rot[1][0] = rot[0][0] * s;
            rot[0][0] = rot[0][0] * c;
            t = rot[0][1];
            t2 = rot[1][1];
            rot[1][1] = t * s + t2 * c;
            rot[0][1] = t * c - t2 * s;
            t = rot[0][2];
            t2 = rot[1][2];
            rot[0][2] = t * c - m[1][2] * s;
            rot[1][2] = t * s + t2 * c;
        }
    }
    if (ctrl->type & CTRL_SCALE) {
        scale[0][0] = ctrl->controlParams.srt.s.x;
        scale[1][1] = ctrl->controlParams.srt.s.y;
        scale[2][2] = ctrl->controlParams.srt.s.z;
        if (ctrl->type & CTRL_SCALE_QUAT) {
            PSMTXQuat(scaleQuat, &ctrl->controlParams.q);
            PSMTXInverse(scaleQuat, invQuat);
        }
    }
    if (ctrl->type & CTRL_TRANS) {
        rot[0][3] = ctrl->controlParams.srt.t.x;
        rot[1][3] = ctrl->controlParams.srt.t.y;
        rot[2][3] = ctrl->controlParams.srt.t.z;
    }
    PSMTXConcat(result, flipMtx, result);
    PSMTXConcat(invQuat, result, result);
    PSMTXConcat(scale, result, result);
    PSMTXConcat(scaleQuat, result, result);
    PSMTXConcat(rot, result, result);
    PSMTXConcat(result, mirror, result);
    PSMTXConcat(mirror, result, result);
    PSMTXCopy(result, m);
}

// .text:0x80063028 size:0x384
// Registers only, in the z rotation block: the target assigns its temporaries f1-f8 in another order
void fn_80063028(Control* ctrl, Mtx m, s32 flip) {
    Mtx trans;
    Mtx rot;
    Mtx scale;
    Mtx scaleQuat;
    Mtx invQuat;
    Mtx result;
    Mtx mirror;
    Mtx flipMtx;
    f32 t;
    f32 t2;

    if (ctrl->type & CTRL_MTX) {
        PSMTXCopy(ctrl->controlParams.m, m);
        return;
    }
    PSMTXScale(mirror, 1.0f, -1.0f, 1.0f);
    PSMTXIdentity(flipMtx);
    if (flip & 1) {
        PSMTXRotRad(flipMtx, 'X', 3.1415927f);
    }
    if (flip & 2) {
        PSMTXRotRad(flipMtx, 'Y', 3.1415927f);
    }
    if (flip & 4) {
        PSMTXRotRad(flipMtx, 'Z', 3.1415927f);
    }
    PSMTXIdentity(m);
    PSMTXIdentity(trans);
    PSMTXIdentity(rot);
    PSMTXIdentity(scale);
    PSMTXIdentity(scaleQuat);
    PSMTXIdentity(invQuat);
    PSMTXIdentity(result);
    if (ctrl->type & CTRL_ROT_QUAT) {
        PSMTXQuat(rot, &ctrl->controlParams.srt.r);
    } else if (ctrl->type & CTRL_ROT_EULER) {
        if (ctrl->controlParams.srt.r.x != 0.0f) {
            f32 s;
            f32 theta;
            f32 c;

            theta = 0.017453292f * ctrl->controlParams.srt.r.x;
            s = sin(theta);
            c = cos(theta);
            rot[0][0] = 1.0f;
            rot[0][1] = 0.0f;
            rot[0][2] = 0.0f;
            rot[0][3] = 0.0f;
            rot[1][0] = 0.0f;
            rot[1][1] = c;
            rot[1][2] = -s;
            rot[1][3] = 0.0f;
            rot[2][0] = 0.0f;
            rot[2][1] = s;
            rot[2][2] = c;
            rot[2][3] = 0.0f;
        }
        if (ctrl->controlParams.srt.r.y != 0.0f) {
            f32 theta;
            f32 s;
            f32 c;

            theta = 0.017453292f * ctrl->controlParams.srt.r.y;
            s = sin(theta);
            c = cos(theta);
            rot[0][0] = c;
            rot[0][1] = rot[2][1] * s;
            rot[0][2] = rot[2][2] * s;
            rot[2][0] = -s;
            rot[2][1] = rot[2][1] * c;
            rot[2][2] = rot[2][2] * c;
        }
        if (ctrl->controlParams.srt.r.z != 0.0f) {
            f32 theta;
            f32 s;
            f32 c;

            theta = 0.017453292f * ctrl->controlParams.srt.r.z;
            s = sin(theta);
            c = cos(theta);
            rot[1][0] = rot[0][0] * s;
            rot[0][0] = rot[0][0] * c;
            t = rot[0][1];
            t2 = rot[1][1];
            rot[1][1] = t * s + t2 * c;
            rot[0][1] = t * c - t2 * s;
            t = rot[0][2];
            t2 = rot[1][2];
            rot[0][2] = t * c - m[1][2] * s;
            rot[1][2] = t * s + t2 * c;
        }
    }
    if (ctrl->type & CTRL_SCALE) {
        scale[0][0] = ctrl->controlParams.srt.s.x;
        scale[1][1] = ctrl->controlParams.srt.s.y;
        scale[2][2] = ctrl->controlParams.srt.s.z;
        if (ctrl->type & CTRL_SCALE_QUAT) {
            PSMTXQuat(scaleQuat, &ctrl->controlParams.q);
            PSMTXInverse(scaleQuat, invQuat);
        }
    }
    if (ctrl->type & CTRL_TRANS) {
        trans[0][3] = ctrl->controlParams.srt.t.x;
        trans[1][3] = ctrl->controlParams.srt.t.y;
        trans[2][3] = ctrl->controlParams.srt.t.z;
    }
    PSMTXConcat(result, flipMtx, result);
    PSMTXConcat(invQuat, result, result);
    PSMTXConcat(scale, result, result);
    PSMTXConcat(scaleQuat, result, result);
    PSMTXConcat(rot, mirror, rot);
    PSMTXConcat(mirror, rot, rot);
    PSMTXConcat(rot, result, result);
    PSMTXConcat(trans, result, result);
    PSMTXCopy(result, m);
}

