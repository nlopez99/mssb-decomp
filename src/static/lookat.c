#include "static/lookat.h"
#include "Dolphin/mtx.h"
#include "C3/control.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "math.h"

typedef struct LookBone {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct LookBone* parent;
    /* 0x10 */ u8 _10[0x60 - 0x10];
    /* 0x60 */ Control ctrl;
    /* 0xA4 */ u8 _A4[0xEC - 0xA4];
    /* 0xEC */ MtxPtr mtx;
} LookBone;

typedef struct LookModel {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ LookBone** bones;
} LookModel;

typedef struct LookModelRef {
    /* 0x0 */ LookModel* model;
} LookModelRef;

typedef struct LookSlot {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ LookModelRef ref;
    /* 0x38 */ u8 _38[0x90 - 0x38];
} LookSlot; // size: 0x90

typedef struct LookActor {
    /* 0x000 */ u8 _000[0x174];
    /* 0x174 */ u16 headBone;
    /* 0x176 */ u8 _176[0x255 - 0x176];
    /* 0x255 */ s8 slot;
    /* 0x256 */ u8 _256[0x27C - 0x256];
} LookActor; // size: 0x27C

extern struct {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ LookSlot* slots;
    /* 0x0064 */ u8 _0064[0xC04 - 0x64];
    /* 0x0C04 */ LookActor players[13];
    /* 0x2C50 */ LookActor* fielders[13];
} lbl_8036E548;

extern void fn_800B2DD0(LookModel* model, LookBone* bone);

// .text:0x80026134 size:0x2C8
void fn_80026134(s32 index, Vec* target)
{
    Control ctrl;
    Mtx m;
    Vec fwd = { 0.0f, 0.0f, 1.0f };
    Vec dir;
    Vec axis;
    Quaternion q;
    Quaternion q2;
    LookActor* fielder = lbl_8036E548.fielders[index];
    LookActor* actor;
    LookModelRef* ref;
    LookModel* model;
    LookBone* bone;
    LookBone* parent;
    int boneIndex;
    f32 angle;
    f32 angle2;
    f32 s;

    if (fielder != NULL) {
        actor = fielder;
        ref = &lbl_8036E548.slots[fielder->slot].ref;
    } else {
        actor = &lbl_8036E548.players[index];
        ref = &lbl_8036E548.slots[index].ref;
    }
    model = ref->model;
    boneIndex = actor->headBone;
    if (boneIndex != 0xFFFF) {
        bone = model->bones[boneIndex];
        memcpy(&ctrl, &bone->ctrl, sizeof(Control));
        parent = bone->parent;
        PSMTXInverse(bone->mtx, m);
        PSMTXMultVec(m, target, &dir);
        dir.x = 0.0f;
        PSVECNormalize(&dir, &dir);
        angle = acos(PSVECDotProduct(&fwd, &dir));
        if (angle < 0.000001f) {
            axis.x = 1.0f;
        } else {
            PSVECCrossProduct(&fwd, &dir, &axis);
        }
        if (angle > 1.256637f) {
            angle = 1.256637f;
        }
        angle /= 2;
        q.x = axis.x * sin(angle);
        q.y = 0.0f;
        q.z = 0.0f;
        q.w = cos(angle);
        CTRLSetQuat(&ctrl, q.x, q.y, q.z, q.w);
        CTRLBuildMatrix(&ctrl, m);
        PSMTXConcat(parent->mtx, m, m);
        PSMTXInverse(m, m);
        PSMTXMultVec(m, target, &dir);
        PSVECNormalize(&dir, &dir);
        PSVECCrossProduct(&fwd, &dir, &axis);
        angle2 = acos(PSVECDotProduct(&fwd, &dir));
        if (angle2 > 0.94247776f) {
            angle2 = 0.94247776f;
        }
        angle = angle2 / 2;
        s = sin(angle);
        q2.w = cos(angle);
        q2.x = axis.x * s;
        q2.y = axis.y * s;
        q2.z = axis.z * s;
        PSQUATMultiply(&q, &q2, &q);
        CTRLSetQuat(&bone->ctrl, q.x, q.y, q.z, q.w);
        fn_800B2DD0(model, bone);
    }
}
