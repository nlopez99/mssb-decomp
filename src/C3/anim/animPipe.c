#include "C3/charPipeline.h"

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
void DoEulerAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame) {}

// .text:0x800B63DC size:0xA30
void DoScaleAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame, u8 flag) {}

// .text:0x800B5DA8 size:0x634
void DoTranslationAnimation(struct ANIMPipe *animPipe, KeyFrame *currentFrame, KeyFrame *nextFrame) {}

// .text:0x800B560C size:0x79C
void GetData(void) {}

// .text:0x800B516C size:0x4A0
void Squad(void) {}
