#include "Dolphin/os.h"
#include "C3/charPipeline.h"
#include "stl/math.h"

void GetData(u8 type, void *src, f32 *dst, u8 count, f32 scale);

static inline void QuatSlerp(Quaternion *p, Quaternion *q, Quaternion *r, f32 t) {
    f32 cosom;
    f32 omega;
    f32 sinom;
    f32 sclp;
    f32 sclq;

    cosom = p->x * q->x + p->y * q->y + p->z * q->z + p->w * q->w;
    if ((1.0f + cosom) > 0.000001f) {
        if ((1.0f - cosom) > 0.000001f) {
            omega = acos(cosom);
            sinom = 1.0f / sin(omega);
            sclp = sinom * sin(omega - t * omega);
            sclq = sinom * sin(t * omega);
        } else {
            sclp = 1.0f - t;
            sclq = t;
        }
        r->x = sclp * p->x + sclq * q->x;
        r->y = sclp * p->y + sclq * q->y;
        r->z = sclp * p->z + sclq * q->z;
        r->w = sclp * p->w + sclq * q->w;
    } else {
        r->x = -q->y;
        r->y = q->x;
        r->z = -q->w;
        r->w = q->z;
        sclp = sin(1.5707964f - 1.5707964f * t);
        sclq = sin(1.5707964f * t);
        r->x = sclp * p->x + sclq * r->x;
        r->y = sclp * p->y + sclq * r->y;
        r->z = sclp * p->z + sclq * r->z;
        r->w = sclp * p->w + sclq * r->w;
    }
}

static inline f32 getFrameT(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame) {
    f32 dt = animPipe->time - currentFrame->time;

    if (dt == 0.0f) {
        return 0.0f;
    }
    if (nextFrame->time > currentFrame->time) {
        return dt / (nextFrame->time - currentFrame->time);
    }
    if (animPipe->currentTrack->animTime >= currentFrame->time) {
        return 1.0f;
    }
    return dt / (animPipe->currentTrack->animTime - currentFrame->time);
}

static inline int getCompSize(u8 type) {
    switch (type) {
    case GX_U8:
    case GX_S8:
        return 1;
    case GX_U16:
    case GX_S16:
        return 2;
    case GX_F32:
        return 4;
    default:
        return 0;
    }
}
void DoQuatAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame);
void DoEulerAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame);
void DoScaleAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame, u8 flag);
void DoTranslationAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame);

// .text:0x800B79A0 size:0x30
void ANIMBind(struct ANIMPipe *animPipe, Control *control, struct ANIMAnimTrack *animTrack, f32 time) {
    if (animTrack != NULL) {
        control->type = 0;
        animPipe->control = control;
        animPipe->currentTrack = animTrack;
        animPipe->time = time;
        animPipe->_04 = time;
        animPipe->replaceHierarchyCtrl = animTrack->replaceHierarchyCtrl;
        animPipe->_14 = 0;
    }
}

// .text:0x800B7718 size:0x288
void ANIMTick(struct ANIMPipe *animPipe, u8 flag) {
    KeyFrame *currentFrame;
    KeyFrame *nextFrame;
    f32 scale;

    if (animPipe == NULL || animPipe->currentTrack == NULL) {
        return;
    }
    ANIMGetKeyFrameFromTrack(animPipe->currentTrack, animPipe->time, &currentFrame, &nextFrame, &animPipe->_14);
    if (animPipe->currentTrack->animType & 0x10) {
        scale = 1.0f / (1 << (animPipe->currentTrack->quantizeInfo & 0xF));
        ((f32 *)currentFrame->setting)[0] *= scale;
        ((f32 *)currentFrame->setting)[1] *= scale;
        ((f32 *)currentFrame->setting)[2] *= scale;
        ((f32 *)currentFrame->setting)[3] *= scale;
        ((f32 *)currentFrame->setting)[4] *= scale;
        ((f32 *)currentFrame->setting)[5] *= scale;
        ((f32 *)currentFrame->setting)[6] *= scale;
        ((f32 *)currentFrame->setting)[7] *= scale;
        ((f32 *)currentFrame->setting)[8] *= scale;
        ((f32 *)currentFrame->setting)[9] *= scale;
        ((f32 *)currentFrame->setting)[10] *= scale;
        ((f32 *)currentFrame->setting)[11] *= scale;
        CTRLSetMatrix(animPipe->control, (MtxPtr)currentFrame->setting);
        return;
    }
    if (animPipe->currentTrack->animType & 2) {
        DoScaleAnimation(animPipe, currentFrame, nextFrame, flag);
    }
    if (animPipe->currentTrack->animType & 8) {
        DoQuatAnimation(animPipe, currentFrame, nextFrame);
    } else if (animPipe->currentTrack->animType & 4) {
        DoEulerAnimation(animPipe, currentFrame, nextFrame);
    }
    if (animPipe->currentTrack->animType & 1) {
        DoTranslationAnimation(animPipe, currentFrame, nextFrame);
    }
    animPipe->_04 = animPipe->time;
    if (animPipe->_17 == 1) {
        animPipe->time += animPipe->speed;
        if (animPipe->time > animPipe->currentTrack->animTime) {
            if (animPipe->_18 != 0) {
                animPipe->time = animPipe->time - animPipe->currentTrack->animTime;
            } else {
                animPipe->time = animPipe->currentTrack->animTime;
            }
        }
    } else {
        animPipe->time -= animPipe->speed;
        if (animPipe->time < 0.0f) {
            if (animPipe->_18 != 0) {
                animPipe->time = animPipe->time + animPipe->currentTrack->animTime;
            } else {
                animPipe->time = 0.0f;
            }
        }
    }
}

// .text:0x800B71C0 size:0x558
void DoQuatAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame) {}

// .text:0x800B6E0C size:0x3B4
// Differs: the Hermite case's three components are scheduled together where the target
// stores each before computing the next, plus registers; its string offsets wait on the
// 0x30 bytes of .rodata the target has before "animPipe.c".
void DoEulerAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame) {
    f32 cur[3];
    f32 next[3];
    f32 out[3];
    f32 curTangent[3];
    f32 nextTangent[3];
    int stride;
    u8 type;
    int size;
    u32 mode;
    u32 settingOffset;
    u32 interpOffset;
    f32 scale;
    f32 t;
    f32 dt;
    f32 tt;
    f32 ttt;
    f32 s;
    int i;

    type = animPipe->currentTrack->quantizeInfo >> 4;
    scale = 1.0f / (1 << (animPipe->currentTrack->quantizeInfo & 0xF));
    size = getCompSize(type);
    stride = size * 3;
    settingOffset = 0;
    if (animPipe->currentTrack->animType & 2) {
        settingOffset = stride;
    }
    GetData(type, currentFrame->setting + settingOffset, cur, 3, scale);
    GetData(type, nextFrame->setting + settingOffset, next, 3, scale);
    t = getFrameT(animPipe, currentFrame, nextFrame);
    interpOffset = 0;
    if (animPipe->currentTrack->animType & 2) {
        mode = (animPipe->currentTrack->interpolationType >> 2) & 3;
        if (mode == 2) {
            interpOffset = stride * 2;
        }
        if (mode == 3) {
            interpOffset = stride * 2 + 4;
        }
    }
    switch ((animPipe->currentTrack->interpolationType >> 4) & 7) {
    case 0:
        out[0] = cur[0];
        out[1] = cur[1];
        out[2] = cur[2];
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            if (cur[i] - next[i] > 180.0f) {
                cur[i] -= 360.0f;
            } else if (cur[i] - next[i] < -180.0f) {
                next[i] -= 360.0f;
            }
            out[i] = t * next[i] + (1.0f - t) * cur[i];
        }
        break;
    case 2:
        GetData(type, currentFrame->interpolation + interpOffset + stride, curTangent, 3, scale);
        GetData(type, nextFrame->interpolation + interpOffset, nextTangent, 3, scale);
        tt = t * t;
        ttt = t * tt;
        s = 1.0f - t;
        for (i = 0; i < 3; i++) {
            out[i] = s * (3.0f * tt * (nextTangent[i] + next[i]) + s * (s * cur[i] + 3.0f * t * (curTangent[i] + cur[i]))) + ttt * next[i];
        }
        break;
    case 3:
        OSPanic("animPipe.c", 301, "Hermite pInterpolation not yet supported for Euler angles(Hermite\225\342\212\324\202\315\203I\203C\203\211\201[\212p\220\247\214\344\202\305\202\315\203T\203|\201[\203g\202\263\202\352\202\304\202\242\202\334\202\271\202\361)");
        break;
    default:
        OSPanic("animPipe.c", 304, "Unknown pInterpolation pSetting!(\226\242\222m\202\314\225\342\212\324\203^\203C\203v\202\252\216w\222\350\202\263\202\352\202\304\202\242\202\334\202\267)");
        break;
    }
    CTRLSetRotation(animPipe->control, out[0], out[1], out[2]);
}

// .text:0x800B63DC size:0xA30
void DoScaleAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame, u8 flag) {}

// .text:0x800B5DA8 size:0x634
void DoTranslationAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame) {}

// .text:0x800B560C size:0x79C
void GetData(u8 type, void *src, f32 *dst, u8 count, f32 scale) {
    u8 i;

    switch (type) {
    case GX_U8:
        for (i = 0; i < count; i++) {
            dst[i] = scale * ((u8 *)src)[i];
        }
        break;
    case GX_S8:
        for (i = 0; i < count; i++) {
            dst[i] = scale * ((s8 *)src)[i];
        }
        break;
    case GX_U16:
        for (i = 0; i < count; i++) {
            dst[i] = scale * ((u16 *)src)[i];
        }
        break;
    case GX_S16:
        for (i = 0; i < count; i++) {
            dst[i] = scale * ((s16 *)src)[i];
        }
        break;
    case GX_F32:
        for (i = 0; i < count; i++) {
            dst[i] = ((f32 *)src)[i];
        }
        break;
    }
}

// .text:0x800B516C size:0x4A0
void Squad(Quaternion *p, Quaternion *a, Quaternion *b, Quaternion *q, Quaternion *d, f32 t) {
    Quaternion pq;
    Quaternion ab;
    f32 t2;

    t2 = 2.0f * (1.0f - t) * t;
    QuatSlerp(p, q, &pq, t);
    QuatSlerp(a, b, &ab, t);
    QuatSlerp(&pq, &ab, d, t2);
}
