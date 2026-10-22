#include "Dolphin/os.h"
#include "C3/charPipeline.h"
#include "stl/math.h"

void GetData(u8 type, void *src, f32 *dst, u8 count, f32 scale);
void Squad(Quaternion *p, Quaternion *a, Quaternion *b, Quaternion *q, Quaternion *d, f32 t);
void CTRL_SetQuatUnk(Control *control, f32 x, f32 y, f32 z, f32 w);

// Quaternion keys are s16 fractions of 1/16384, ease values likewise.
f32 lbl_803CBB48 = 1.0f / 16384.0f;
f32 lbl_803CBB4C = 1.0f / 16384.0f;
u8 lbl_803CBB50 = GX_S16;
u8 lbl_803CBB51 = GX_S16;

static inline f32 sinF(f32 x) {
    return sin(x);
}

static inline f32 acosF(f32 x) {
    return acos(x);
}

static inline void QuatSlerp(Quaternion *p, Quaternion *q, Quaternion *r, f32 t) {
    f32 cosom;
    f32 omega;
    f32 tomega;
    f32 sinom;
    f32 sclp;
    f32 sclq;

    cosom = p->x * q->x + p->y * q->y + p->z * q->z + p->w * q->w;
    if ((1.0f + cosom) > 0.000001f) {
        if ((1.0f - cosom) > 0.000001f) {
            omega = acosF(cosom);
            tomega = t * omega;
            sinom = 1.0f / sinF(omega);
            sclp = sinom * sinF(omega - tomega);
            sclq = sinom * sinF(tomega);
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
        sclp = sinF(1.5707964f - 1.5707964f * t);
        sclq = sinF(1.5707964f * t);
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

static inline f32 BezierF(f32 p0, f32 c0, f32 c1, f32 p1, f32 t) {
    f32 tt = t * t;
    f32 ttt = t * tt;
    f32 s = 1.0f - t;

    return s * (3.0f * tt * (c1 + p1) + s * (s * p0 + 3.0f * t * (c0 + p0))) + ttt * p1;
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
    KeyFrame *frame;
    KeyFrame *currentFrame;
    KeyFrame *nextFrame;
    f32 scale;

    if (animPipe == NULL || animPipe->currentTrack == NULL) {
        return;
    }
    ANIMGetKeyFrameFromTrack(animPipe->currentTrack, animPipe->time, &currentFrame, &nextFrame, &animPipe->_14);
    if (animPipe->currentTrack->animType & 0x10) {
        frame = currentFrame;
        scale = 1.0f / (1 << (animPipe->currentTrack->quantizeInfo & 0xF));
        ((f32 *)frame->setting)[0] *= scale;
        ((f32 *)frame->setting)[1] *= scale;
        ((f32 *)frame->setting)[2] *= scale;
        ((f32 *)frame->setting)[3] *= scale;
        ((f32 *)frame->setting)[4] *= scale;
        ((f32 *)frame->setting)[5] *= scale;
        ((f32 *)frame->setting)[6] *= scale;
        ((f32 *)frame->setting)[7] *= scale;
        ((f32 *)frame->setting)[8] *= scale;
        ((f32 *)frame->setting)[9] *= scale;
        ((f32 *)frame->setting)[10] *= scale;
        ((f32 *)frame->setting)[11] *= scale;
        CTRLSetMatrix(animPipe->control, (MtxPtr)frame->setting);
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
                animPipe->time -= animPipe->currentTrack->animTime;
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
// Differs: the target compares dt against 0.0f in the other operand order and keeps a
// second copy of t (f29) for Squad.
void DoQuatAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame) {
    u8 type;
    int stride;
    u32 offset;
    u32 mode;
    f32 t;
    f32 dt;
    f32 easeIn;
    f32 easeOut;
    f32 sum;
    f32 a;
    f32 b;
    f32 k;
    f32 speed;
    Quaternion out;
    Quaternion cur;
    Quaternion next;
    Quaternion curTangent;
    Quaternion nextTangent;

    type = animPipe->currentTrack->quantizeInfo >> 4;
    stride = getCompSize(type) * 3;
    offset = 0;
    if (animPipe->currentTrack->animType & 2) {
        offset = getCompSize(type) * 3;
        if (animPipe->currentTrack->animType & 0x20) {
            offset += getCompSize(type) * 4;
        }
    }
    GetData(lbl_803CBB50, currentFrame->setting + offset, (f32 *)&cur, 4, lbl_803CBB48);
    GetData(lbl_803CBB50, nextFrame->setting + offset, (f32 *)&next, 4, lbl_803CBB48);
    t = getFrameT(animPipe, currentFrame, nextFrame);
    offset = 0;
    if (animPipe->currentTrack->animType & 2) {
        mode = (animPipe->currentTrack->interpolationType >> 2) & 3;
        if (mode == 2) {
            offset = stride * 2;
        }
        if (mode == 3) {
            offset = stride * 2 + 4;
        }
    }
    switch ((animPipe->currentTrack->interpolationType >> 4) & 7) {
    case 5:
        GetData(lbl_803CBB51, nextFrame->interpolation + offset + 0x10, &easeIn, 1, lbl_803CBB4C);
        GetData(lbl_803CBB51, currentFrame->interpolation + offset + 0x12, &easeOut, 1, lbl_803CBB4C);
        a = easeOut;
        b = easeIn;
        sum = a + b;
        if (t != 0.0f && t != 1.0f && sum != 0.0f) {
            if (sum > 1.0f) {
                k = 1.0f / sum;
                a *= k;
                b *= k;
                speed = 0.5f - k;
            } else {
                speed = 0.5f - 1.0f / sum;
            }
            if (t < a) {
                t = t * (t * (speed / a));
            } else if (t < 1.0f - b) {
                t = speed * (2.0f * t - a);
            } else {
                t = 1.0f - (1.0f - t) * ((1.0f - t) * (speed / b));
            }
        }
    case 4:
        GetData(lbl_803CBB50, currentFrame->interpolation + offset + 8, (f32 *)&curTangent, 4, lbl_803CBB48);
        GetData(lbl_803CBB50, nextFrame->interpolation + offset, (f32 *)&nextTangent, 4, lbl_803CBB48);
        Squad(&cur, &curTangent, &nextTangent, &next, &out, t);
        break;
    case 6:
        QuatSlerp(&cur, &next, &out, t);
        break;
    case 0:
        out = cur;
        break;
    default:
        OSPanic("animPipe.c", 225, "Unknown pInterpolation pSetting!");
        break;
    }
    CTRLSetQuat(animPipe->control, out.x, out.y, out.z, out.w);
}

// .text:0x800B6E0C size:0x3B4
// Differs: dt is compared with 0.0f in the other operand order, and registers in the
// linear and Bezier cases.
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

    scale = 1.0f / (1 << (animPipe->currentTrack->quantizeInfo & 0xF));
    type = animPipe->currentTrack->quantizeInfo >> 4;
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
        for (i = 0; i < 3; i++) {
            out[i] = BezierF(cur[i], curTangent[i], nextTangent[i], next[i], t);
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
// Differs: registers and the Hermite case's scheduling; its three identity quaternions
// are the .rodata at the start of the unit's range.
void DoScaleAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame, u8 flag) {
    f32 cur[3];
    f32 next[3];
    f32 out[3];
    f32 curTangent[3];
    f32 nextTangent[3];
    Quaternion curQ = { 0.0f, 0.0f, 0.0f, 1.0f };
    Quaternion nextQ = { 0.0f, 0.0f, 0.0f, 1.0f };
    Quaternion outQ = { 0.0f, 0.0f, 0.0f, 1.0f };
    f32 curEase;
    f32 nextEase;
    int stride;
    u8 type;
    f32 scale;
    f32 t;
    f32 tt;
    f32 ttt;
    f32 s;
    f32 sum;
    f32 k;
    f32 speed;
    f32 a;
    f32 b;
    f32 h00;
    f32 h01;
    f32 h10;
    f32 h11;
    char *p;
    int i;

    scale = 1.0f / (1 << (animPipe->currentTrack->quantizeInfo & 0xF));
    type = animPipe->currentTrack->quantizeInfo >> 4;
    stride = getCompSize(type) * 3;
    GetData(type, currentFrame->setting, cur, 3, scale);
    GetData(type, nextFrame->setting, next, 3, scale);
    if (animPipe->currentTrack->animType & 0x20) {
        GetData(type, currentFrame->setting + stride, (f32 *)&curQ, 4, scale);
        GetData(type, nextFrame->setting + stride, (f32 *)&nextQ, 4, scale);
    }
    t = getFrameT(animPipe, currentFrame, nextFrame);
    switch ((animPipe->currentTrack->interpolationType >> 2) & 3) {
    case 0:
        out[0] = cur[0];
        out[1] = cur[1];
        out[2] = cur[2];
        if (animPipe->currentTrack->animType & 0x20) {
            outQ.x = curQ.x;
            outQ.y = curQ.y;
            outQ.z = curQ.z;
            outQ.w = curQ.w;
        }
        break;
    case 1:
        s = 1.0f - t;
        out[0] = t * next[0] + s * cur[0];
        out[1] = t * next[1] + s * cur[1];
        out[2] = t * next[2] + s * cur[2];
        if (animPipe->currentTrack->animType & 0x20) {
            QuatSlerp(&curQ, &nextQ, &outQ, t);
        }
        break;
    case 2:
        GetData(type, currentFrame->interpolation + stride, curTangent, 3, scale);
        GetData(type, nextFrame->interpolation, nextTangent, 3, scale);
        for (i = 0; i < 3; i++) {
            out[i] = BezierF(cur[i], curTangent[i], nextTangent[i], next[i], t);
        }
        if (animPipe->currentTrack->animType & 0x20) {
            QuatSlerp(&curQ, &nextQ, &outQ, t);
        }
        break;
    case 3:
        p = currentFrame->interpolation + stride;
        GetData(type, p, curTangent, 3, scale);
        GetData(lbl_803CBB51, p + stride + 2, &curEase, 1, lbl_803CBB4C);
        GetData(type, nextFrame->interpolation, nextTangent, 3, scale);
        GetData(lbl_803CBB51, nextFrame->interpolation + stride * 2, &nextEase, 1, lbl_803CBB4C);
        a = curEase;
        b = nextEase;
        sum = a + b;
        if (t != 0.0f && t != 1.0f && sum != 0.0f) {
            if (sum > 1.0f) {
                k = 1.0f / sum;
                a *= k;
                b *= k;
                speed = 0.5f - k;
            } else {
                speed = 0.5f - 1.0f / sum;
            }
            if (t < a) {
                t = t * (t * (speed / a));
            } else if (t < 1.0f - b) {
                t = speed * (2.0f * t - a);
            } else {
                t = 1.0f - (1.0f - t) * ((1.0f - t) * (speed / b));
            }
        }
        tt = t * t;
        ttt = tt * t;
        h00 = 2.0f * ttt - 3.0f * tt;
        h01 = -h00;
        h00 = 1.0f + h00;
        h10 = ttt + (t - 2.0f * tt);
        h11 = -tt + ttt;
        for (i = 0; i < 3; i++) {
            out[i] = h11 * nextTangent[i] + (h10 * curTangent[i] + (h00 * cur[i] + h01 * next[i]));
        }
        if (animPipe->currentTrack->animType & 0x20) {
            QuatSlerp(&curQ, &nextQ, &outQ, t);
        }
        break;
    default:
        OSPanic("animPipe.c", 424, "Unknown pInterpolation pSetting!(\226\242\222m\202\314\225\342\212\324\203^\203C\203v\202\252\216w\222\350\202\263\202\352\202\304\202\242\202\334\202\267)");
        break;
    }
    CTRLSetScale(animPipe->control, out[0], out[1], out[2]);
    CTRL_SetQuatUnk(animPipe->control, outQ.x, outQ.y, outQ.z, outQ.w);
}

// .text:0x800B5DA8 size:0x634
// Differs: the target extracts the interpolation modes with srawi/clrlwi (a signed
// shift) where this has rlwinm; the Hermite case's scheduling; registers.
void DoTranslationAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame) {
    f32 cur[3];
    f32 next[3];
    f32 out[3];
    f32 curTangent[3];
    f32 nextTangent[3];
    f32 curEase;
    f32 nextEase;
    u8 type;
    int stride;
    u32 offset;
    u32 mode;
    f32 scale;
    f32 t;
    f32 tt;
    f32 ttt;
    f32 s;
    f32 sum;
    f32 k;
    f32 speed;
    f32 a;
    f32 b;
    f32 h00;
    f32 h01;
    f32 h10;
    f32 h11;
    char *p;
    int i;

    scale = 1.0f / (1 << (animPipe->currentTrack->quantizeInfo & 0xF));
    type = animPipe->currentTrack->quantizeInfo >> 4;
    stride = getCompSize(type) * 3;
    offset = 0;
    if (animPipe->currentTrack->animType & 2) {
        offset = getCompSize(type) * 3;
        if (animPipe->currentTrack->animType & 0x20) {
            offset += getCompSize(type) * 4;
        }
    }
    if (animPipe->currentTrack->animType & 4) {
        offset += stride;
    }
    if (animPipe->currentTrack->animType & 8) {
        offset += 8;
    }
    GetData(type, currentFrame->setting + offset, cur, 3, scale);
    GetData(type, nextFrame->setting + offset, next, 3, scale);
    t = getFrameT(animPipe, currentFrame, nextFrame);
    offset = 0;
    if (animPipe->currentTrack->animType & 2) {
        mode = (animPipe->currentTrack->interpolationType >> 2) & 3;
        if (mode == 2) {
            offset = stride * 2;
        }
        if (mode == 3) {
            offset = stride * 2 + 4;
        }
    }
    if (animPipe->currentTrack->animType & 8) {
        mode = (animPipe->currentTrack->interpolationType >> 4) & 7;
        if (mode == 4) {
            offset += 0x10;
        }
        if (mode == 5) {
            offset += 0x14;
        }
    } else if (animPipe->currentTrack->animType & 4) {
        mode = (animPipe->currentTrack->interpolationType >> 4) & 7;
        if (mode == 2) {
            offset += stride * 2;
        }
        if (mode == 3) {
            offset += stride * 2;
            offset += 4;
        }
    }
    switch (animPipe->currentTrack->interpolationType & 3) {
    case 0:
        out[0] = cur[0];
        out[1] = cur[1];
        out[2] = cur[2];
        break;
    case 1:
        s = 1.0f - t;
        out[0] = t * next[0] + s * cur[0];
        out[1] = t * next[1] + s * cur[1];
        out[2] = t * next[2] + s * cur[2];
        break;
    case 2:
        GetData(type, currentFrame->interpolation + offset + stride, curTangent, 3, scale);
        GetData(type, nextFrame->interpolation + offset, nextTangent, 3, scale);
        for (i = 0; i < 3; i++) {
            out[i] = BezierF(cur[i], curTangent[i], nextTangent[i], next[i], t);
        }
        break;
    case 3:
        p = currentFrame->interpolation + offset + stride;
        GetData(type, p, curTangent, 3, scale);
        GetData(lbl_803CBB51, p + stride + 2, &curEase, 1, lbl_803CBB4C);
        p = nextFrame->interpolation + offset;
        GetData(type, p, nextTangent, 3, scale);
        GetData(lbl_803CBB51, p + stride * 2, &nextEase, 1, lbl_803CBB4C);
        a = curEase;
        b = nextEase;
        sum = a + b;
        if (t != 0.0f && t != 1.0f && sum != 0.0f) {
            if (sum > 1.0f) {
                k = 1.0f / sum;
                a *= k;
                b *= k;
                speed = 0.5f - k;
            } else {
                speed = 0.5f - 1.0f / sum;
            }
            if (t < a) {
                t = t * (t * (speed / a));
            } else if (t < 1.0f - b) {
                t = speed * (2.0f * t - a);
            } else {
                t = 1.0f - (1.0f - t) * ((1.0f - t) * (speed / b));
            }
        }
        tt = t * t;
        ttt = tt * t;
        h00 = 2.0f * ttt - 3.0f * tt;
        h01 = -h00;
        h00 = 1.0f + h00;
        h10 = ttt + (t - 2.0f * tt);
        h11 = -tt + ttt;
        for (i = 0; i < 3; i++) {
            out[i] = h11 * nextTangent[i] + (h10 * curTangent[i] + (h00 * cur[i] + h01 * next[i]));
        }
        break;
    default:
        OSPanic("animPipe.c", 546, "Unknown pInterpolation pSetting!(\226\242\222m\202\314\225\342\212\324\203^\203C\203v\202\252\216w\222\350\202\263\202\352\202\304\202\242\202\334\202\267)");
        break;
    }
    CTRLSetTranslation(animPipe->control, out[0], out[1], out[2]);
}

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
// Differs: registers only, in the third slerp (omega and t * omega in f20/f22 where this
// has f21/f20).
void Squad(Quaternion *p, Quaternion *a, Quaternion *b, Quaternion *q, Quaternion *d, f32 t) {
    Quaternion pq;
    Quaternion ab;
    f32 t2;

    t2 = 2.0f * (1.0f - t) * t;
    QuatSlerp(p, q, &pq, t);
    QuatSlerp(a, b, &ab, t);
    QuatSlerp(&pq, &ab, d, t2);
}
