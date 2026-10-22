#include "C3/charPipeline.h"
#include "static/static_80021188.h"

extern void CTRL_SetQuatUnk(Control *control, f32 x, f32 y, f32 z, f32 w);
extern void CTRL_GetQuatUnk(const Control *control, f32 *x, f32 *y, f32 *z, f32 *w);

// .text:0x800B79D0 size:0x36C
void ACTSetBoneTrack(sBone *bone, struct ANIMAnimTrack *track, BOOL flag, f32 time) {
    u8 type;
    Quaternion q;

    if (track == NULL) {
        if (bone->animPipe != NULL && bone->animPipe->control != NULL) {
            bone->animPipe->control->type = 0;
            bone->animPipe->currentTrack = NULL;
        }
        return;
    }
    if (bone->animPipe == NULL) {
        bone->animPipe = _OSAllocFromHeap(0x20, sizeof(struct ANIMPipe));
        bone->animPipe->time = 0.0f;
        bone->animPipe->_04 = 0.0f;
        bone->animPipe->speed = 1.0f;
        bone->animPipe->currentTrack = NULL;
        bone->animPipe->control = NULL;
        bone->animPipe->replaceHierarchyCtrl = 0;
        bone->animPipe->_17 = 1;
        bone->animPipe->_18 = 1;
    }
    bone->animPipe->_14 = 0;
    if (flag) {
        if (bone->animPipe->control != NULL) {
            if (bone->animPipe->control->type != 0) {
                bone->_A4 = bone->animationCtrl;
            } else {
                bone->_A4 = bone->orientationCtrl;
            }
        } else {
            bone->_A4 = bone->animationCtrl;
        }
    }
    ANIMBind(bone->animPipe, &bone->animationCtrl, track, time);
    if (bone->_136 != 0) {
        bone->animPipe->currentTrack->interpolationType &= 0xFC;
    }
    type = bone->orientationCtrl.type;
    if ((type & CTRL_TRANS) && !(track->animType & 1)) {
        CTRLGetTranslation(&bone->orientationCtrl, &q.x, &q.y, &q.z);
        CTRLSetTranslation(&bone->animationCtrl, q.x, q.y, q.z);
    }
    if ((type & CTRL_SCALE) && !(track->animType & 2)) {
        CTRLGetScale(&bone->orientationCtrl, &q.x, &q.y, &q.z);
        CTRLSetScale(&bone->animationCtrl, q.x, q.y, q.z);
        if ((type & CTRL_SCALE_QUAT) && !(track->animType & 0x20)) {
            CTRL_GetQuatUnk(&bone->orientationCtrl, &q.x, &q.y, &q.z, &q.w);
        } else {
            q.x = 0.0f;
            q.y = 0.0f;
            q.z = 0.0f;
            q.w = 1.0f;
        }
        CTRL_SetQuatUnk(&bone->animationCtrl, q.x, q.y, q.z, q.w);
    }
    if ((type & CTRL_ROT_EULER) && !(track->animType & 4)) {
        CTRLGetRotation(&bone->orientationCtrl, &q.x, &q.y, &q.z);
        CTRLSetRotation(&bone->animationCtrl, q.x, q.y, q.z);
    } else if ((type & CTRL_ROT_QUAT) && !(track->animType & 8)) {
        CTRLGetQuat(&bone->orientationCtrl, &q.x, &q.y, &q.z, &q.w);
        CTRLSetQuat(&bone->animationCtrl, q.x, q.y, q.z, q.w);
    }
    if (!flag) {
        bone->_A4 = bone->animationCtrl;
    }
}
