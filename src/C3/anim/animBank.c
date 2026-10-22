#include "C3/charPipeline.h"
#include "charPipeline/structures/dolphinString.h"

// .text:0x800B508C size:0xE0
void ANIMGet(ANIMBank *animBank) {
    ANIMSequences *seq;
    struct ANIMAnimTrack *track;
    KeyFrame *frame;
    u32 i;

    if (animBank->userDataSize != 0 && animBank->userData != NULL) {
        animBank->userData = (void *)((u32)animBank->userData + (u32)animBank);
    }
    seq = (ANIMSequences *)(animBank + 1);
    track = (struct ANIMAnimTrack *)(seq + animBank->numSequences);
    frame = (KeyFrame *)(track + animBank->numTracks);
    animBank->animSequences = (ANIMSequences *)((u32)animBank->animSequences + (u32)animBank);
    for (i = 0; i < animBank->numSequences; i++) {
        seq[i].sequenceName = (char *)((u32)animBank + (u32)seq[i].sequenceName);
        seq[i].trackArray = (struct ANIMAnimTrack *)((u32)animBank + (u32)seq[i].trackArray);
    }
    for (i = 0; i < animBank->numTracks; i++) {
        track[i].keyFrames = (KeyFrame *)((u32)animBank + (u32)track[i].keyFrames);
    }
    for (i = 0; i < animBank->numKeyFrames; i++) {
        frame[i].setting = (char *)((u32)animBank + (u32)frame[i].setting);
        frame[i].interpolation = (char *)((u32)animBank + (u32)frame[i].interpolation);
    }
}

// .text:0x800B4FEC size:0xA0
ANIMSequences *ANIMGetSequence(ANIMBank *animBank, char *sequenceName, u16 seqNum) {
    u32 i;

    if (sequenceName != NULL) {
        for (i = 0; i < animBank->numSequences; i++) {
            if (Strcmp(animBank->animSequences[i].sequenceName, sequenceName) == 0) {
                return &animBank->animSequences[i];
            }
        }
    } else if (animBank == NULL) {
        return NULL;
    }
    return &animBank->animSequences[seqNum];
}

// .text:0x800B4F9C size:0x50
struct ANIMAnimTrack *ANIMGetTrackFromSequence(ANIMSequences *animSeq, u16 animTrackID) {
    u32 i;

    for (i = 0; i < animSeq->totalTracks; i++) {
        if (animTrackID == animSeq->trackArray[i].trackID) {
            return &animSeq->trackArray[i];
        }
    }
    return NULL;
}

// .text:0x800B4E9C size:0x100
// Differs: the target picks the start index in r7 without the copy through r0, then
// allocates two loop registers differently.
void ANIMGetKeyFrameFromTrack(struct ANIMAnimTrack *animTrack, f32 time, KeyFrame **currentFrame, KeyFrame **nextFrame, u16 *hint) {
    u16 numFrames;
    KeyFrame *frame;
    u16 i;
    u16 count;
    int start;

    start = *hint;
    start = (animTrack->keyFrames[start].time <= time) ? start : 0;
    i = start;
    numFrames = animTrack->totalFrames;
    count = numFrames;
    while (count--) {
        frame = &animTrack->keyFrames[i];
        if (frame->time <= time) {
            if (i < numFrames - 1) {
                if (animTrack->keyFrames[i + 1].time > time) {
                    if (currentFrame != NULL) {
                        *currentFrame = frame;
                    }
                    if (nextFrame != NULL) {
                        *nextFrame = &animTrack->keyFrames[i + 1];
                    }
                    *hint = i;
                    return;
                }
            } else {
                if (currentFrame != NULL) {
                    *currentFrame = frame;
                }
                if (nextFrame != NULL) {
                    *nextFrame = animTrack->keyFrames;
                }
                *hint = i;
                return;
            }
        }
        i = (i + 1) % numFrames;
    }
}
