#include "C3/actorAnim.h"
#include "static/static_80021188.h"



// .text:0x800B4D64 size:0x138
// Differs: scheduling only; the target sets up time and track before the blend test.
void ACTSetAnimation(Actor *actor, ANIMBank *animBank, char *sequenceName, u16 seqNum, f32 time, f32 speed) {
    u16 i;
    ANIMSequences *seq;
    struct ANIMAnimTrack *track;
    sBone *bone;
    BOOL blend;

    seq = ANIMGetSequence(animBank, sequenceName, seqNum);
    track = NULL;
    for (i = 0; i < actor->totalBones; i++) {
        if (seq != NULL) {
            track = ANIMGetTrackFromSequence(seq, actor->boneArray[i]->boneID);
        }
        bone = actor->boneArray[i];
        blend = FALSE;
        if (actor->_8C < 1.0f && bone->_134 != 0) {
            blend = TRUE;
        }
        ACTSetBoneTrack(bone, track, blend, time);
        if (actor->boneArray[i]->_134 & 0x1C) {
            actor->boneArray[i]->_134 |= 0x20;
        } else {
            actor->boneArray[i]->_134 &= 0xFFDF;
        }
    }
    actor->_8C = (speed != 0.0f) ? 0.0f : 1.0f;
    actor->_90 = speed;
}

// .text:0x800B4CDC size:0x88
void fn_800B4CDC(Actor *actor) {
    int i;

    for (i = actor->totalBones - 1; i >= 0; i--) {
        if (actor->boneArray[i]->animPipe != NULL) {
            fn_800ACFB0(actor->boneArray[i]->animPipe);
            actor->boneArray[i]->animPipe = NULL;
        }
    }
}

// .text:0x800B4CA0 size:0x3C
void fn_800B4CA0(Actor *actor, f32 time) {
    u32 i;
    struct ANIMPipe *pipe;

    for (i = 0; i < actor->totalBones; i++) {
        pipe = actor->boneArray[i]->animPipe;
        if (pipe != NULL) {
            pipe->time = time;
        }
    }
}

// .text:0x800B4C40 size:0x60
f32 fn_800B4C40(Actor *actor) {
    u32 i;
    struct ANIMPipe *pipe;

    for (i = 0; i < actor->totalBones; i++) {
        pipe = actor->boneArray[i]->animPipe;
        if (pipe != NULL && pipe->currentTrack != NULL) {
            return actor->boneArray[i]->animPipe->time;
        }
    }
    return 0.0f;
}

// .text:0x800B4C04 size:0x3C
void fn_800B4C04(Actor *actor, f32 speed) {
    u32 i;
    struct ANIMPipe *pipe;

    for (i = 0; i < actor->totalBones; i++) {
        pipe = actor->boneArray[i]->animPipe;
        if (pipe != NULL) {
            pipe->speed = speed;
        }
    }
}

// .text:0x800B4BC8 size:0x3C
void fn_800B4BC8(Actor *actor, u8 value) {
    u32 i;
    struct ANIMPipe *pipe;

    for (i = 0; i < actor->totalBones; i++) {
        pipe = actor->boneArray[i]->animPipe;
        if (pipe != NULL) {
            pipe->_17 = value;
        }
    }
}

// .text:0x800B4B38 size:0x90
void AnimateActorBones(Actor *actor) {
    u32 i;

    actor->_8C += actor->_90;
    if (actor->_8C > 1.0f) {
        actor->_8C = 1.0f;
    }
    for (i = 0; i < actor->totalBones; i++) {
        ANIMTick(actor->boneArray[i]->animPipe, actor->_99);
    }
}

// .text:0x800B4AFC size:0x3C
void fn_800B4AFC(Actor *actor, u8 value) {
    u32 i;
    struct ANIMPipe *pipe;

    for (i = 0; i < actor->totalBones; i++) {
        pipe = actor->boneArray[i]->animPipe;
        if (pipe != NULL) {
            pipe->_18 = value;
        }
    }
}

// .text:0x800B4A94 size:0x68
f32 fn_800B4A94(Actor *actor) {
    u32 i;
    struct ANIMPipe *pipe;
    struct ANIMAnimTrack *track;

    for (i = 0; i < actor->totalBones; i++) {
        pipe = actor->boneArray[i]->animPipe;
        if (pipe != NULL) {
            if (pipe->_17 == 0) {
                return pipe->time;
            }
            track = pipe->currentTrack;
            if (track != NULL) {
                return track->animTime - pipe->time;
            }
        }
    }
    return 0.0f;
}

// .text:0x800B4A44 size:0x50
f32 fn_800B4A44(Actor *actor, u16 boneIndex) {
    struct ANIMPipe *pipe = actor->boneArray[boneIndex]->animPipe;
    struct ANIMAnimTrack *track;

    if (pipe != NULL) {
        if (pipe->_17 == 0) {
            return pipe->time;
        }
        track = pipe->currentTrack;
        if (track != NULL) {
            return track->animTime - pipe->time;
        }
    }
    return 0.0f;
}
