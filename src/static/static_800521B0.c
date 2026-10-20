#include "static/static_800521B0.h"
#include "static/UnknownHomes_Static.h"
#include "static/static_80021188.h"

typedef struct FadeAnim {
    /* 0x00 */ s32 anim;
    /* 0x04 */ u8 _04[0x59 - 0x4];
    /* 0x59 */ u8 useFrame;
    /* 0x5A */ u8 _5A[2];
    /* 0x5C */ f32 frame;
} FadeAnim;

typedef struct FadeActor {
    /* 0x000 */ u8 _000[0x62];
    /* 0x062 */ s16 motion;
    /* 0x064 */ u8 _064[0x252 - 0x64];
    /* 0x252 */ s8 charID;
    /* 0x253 */ u8 _253[0x25C - 0x253];
    /* 0x25C */ u8 _25C;
    /* 0x25D */ u8 _25D[0x277 - 0x25D];
    /* 0x277 */ u8 alpha;
} FadeActor;

typedef struct FadeTask {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ FadeAnim* anim;
    /* 0x18 */ FadeActor* actor;
    /* 0x1C */ s8 charID;
} FadeTask;

extern FadeTask* lbl_803CC1B8;
extern f32 fn_800B4C40(s32 anim);

s16 lbl_800FEB08[5][4] = {
    { -1, -1, 30, 64 },
    { -1, -1, 0, 30 },
    { 0, 15, 55, 85 },
    { -1, -1, 0, 60 },
    { 36, 52, 0x7FFF, 0x7FFF },
};

static inline u8 calcFadeAlpha(f32 frame, s32 kind) {
    s16* tbl = lbl_800FEB08[kind];
    s32 i;

    if (tbl != NULL) {
        for (i = 0; i < 4; i++) {
            if (frame < tbl[i]) {
                switch (i) {
                case 2:
                    return 0;
                case 3:
                    return 255.0f * (frame - lbl_800FEB08[kind][i - 1]) / (tbl[i] - lbl_800FEB08[kind][i - 1]);
                case 0:
                    return 0xFF;
                case 1:
                    return 255.0f * (tbl[i] - frame) / (tbl[i] - lbl_800FEB08[kind][i - 1]);
                }
            }
        }
    }
    return 0xFF;
}

// .text:0x80052634 size:0x58
void* fn_80052634(FadeActor* actor, FadeAnim* anim) {
    FadeTask* task = fn_800B0A5C_insertQueue((void (*)(void))fn_800521B0, 4);

    task->actor = actor;
    task->anim = anim;
    task->charID = actor->charID;
    return task;
}

// .text:0x8005240C size:0x228
void fn_8005240C(FadeActor* actor, FadeAnim* anim) {
    f32 frame;
    u16 kind;

    if (anim->useFrame) {
        frame = anim->frame;
    } else {
        frame = fn_800B4C40(anim->anim);
    }
    switch (actor->motion) {
    case 0x67:
        if (actor->charID == 14) {
            kind = 0;
        } else {
            kind = 1;
        }
        break;
    case 0x47:
        kind = 2;
        break;
    case 0x48:
        kind = 3;
        break;
    case 0x60:
        kind = 4;
        break;
    default:
        actor->alpha = 0xFF;
        return;
    }
    actor->alpha = calcFadeAlpha(frame, kind);
}

// .text:0x800521B0 size:0x25C
void fn_800521B0(void) {
    FadeActor* actor = lbl_803CC1B8->actor;
    FadeAnim* anim = lbl_803CC1B8->anim;
    f32 frame;
    s32 kind;

    if (!actor->_25C || actor->charID != lbl_803CC1B8->charID) {
        fn_800B0A14_removeQueue();
        return;
    }
    if (anim->useFrame) {
        frame = anim->frame;
    } else {
        frame = fn_800B4C40(anim->anim);
    }
    switch (actor->motion) {
    case 0x67:
        if (actor->charID == 14) {
            kind = 0;
        } else {
            kind = 1;
        }
        break;
    case 0x47:
        kind = 2;
        break;
    case 0x48:
        kind = 3;
        break;
    case 0x60:
        kind = 4;
        break;
    default:
        actor->alpha = 0xFF;
        return;
    }
    actor->alpha = calcFadeAlpha(frame, kind);
}
