#include "static/anim.h"
#include "Dolphin/os.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"

typedef struct AnimItem {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
    /* 0x0C */ void* ptrs[1]; // AnimGroup.ptrCount of them
} AnimItem;

typedef struct AnimGroup {
    /* 0x0 */ u16 ptrCount;
    /* 0x2 */ u16 itemCount;
    /* 0x4 */ s32 itemSize;
    /* 0x8 */ AnimItem* items;
} AnimGroup; // size: 0xC

typedef struct AnimEntry {
    /* 0x0 */ u8 _00[0xC];
    /* 0xC */ void* _0C;
} AnimEntry; // size: 0x10

// A file loaded from disc: its pointers are offsets from the start until fn_80025DDC relocates them
typedef struct AnimFile {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 groupCount;
    /* 0x04 */ u16 entryCount;
    /* 0x06 */ u16 _06;
    /* 0x08 */ AnimGroup* groups;
    /* 0x0C */ AnimEntry* entries;
    /* 0x10 */ s32 _10;
} AnimFile;

#define RELOCATE(base, ptr) ((void*)((u32)(base) + (u32)(ptr)))

typedef struct AnimClipSrc {
    /* 0x0 */ u16 _00;
    /* 0x2 */ u16 _02;
    // data follows
} AnimClipSrc;

typedef struct AnimClip {
    /* 0x0 */ u16 _00;
    /* 0x2 */ u16 _02;
    /* 0x4 */ void* data;
} AnimClip; // size: 0x8

typedef struct AnimSub {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ s16 _08;
    /* 0x0A */ s16 _0A;
    /* 0x0C */ s16 _0C;
    /* 0x0E */ s16 _0E;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 active : 1;
    /* 0x11 */ u8 _11_1 : 2;
    /* 0x11 */ u8 _11_3 : 2;
    /* 0x11 */ u8 _11_5 : 3;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ s32 _14;
    /* 0x18 */ AnimClip clip;
} AnimSub; // size: 0x20

typedef struct AnimHdr {
    /* 0x0 */ u32 clipCount;
    /* 0x4 */ AnimClipSrc** clips;
    /* 0x8 */ s8** sets;
    /* 0xC */ u32 setCount;
} AnimHdr;

typedef struct AnimState {
    /* 0x00 */ AnimHdr* hdr;
    /* 0x04 */ AnimClipSrc** clips;
    /* 0x08 */ s8** sets;
    /* 0x0C */ AnimSub sub;
    /* 0x2C */ void* file;
    /* 0x30 */ s8* setPtrs[10];
    /* 0x58 */ s8 current;
    /* 0x59 */ u8 _59;
} AnimState;

extern AnimClip lbl_803CB7F0;

static inline void AnimSub_Init(AnimSub* sub)
{
    if (sub != NULL) {
        sub->_00 = 0.0f;
        sub->_04 = 0.5f;
        sub->_08 = 1;
        sub->_0A = 0;
        sub->_0C = 0;
        sub->_0E = -1;
        sub->_10 = 1;
        sub->_14 = 0;
    }
}

static inline void AnimSub_Set11_1(AnimSub* sub, u8 value)
{
    if (sub != NULL) {
        sub->_11_1 = value;
    }
}

static inline void AnimSub_Set11_3(AnimSub* sub, u8 value)
{
    if (sub != NULL) {
        sub->_11_3 = value;
    }
}

typedef union AnimKey {
    u32 raw;
    struct {
        u32 flags : 4;
        u32 frame : 12;
        u32 value : 16;
    } f;
} AnimKey;

typedef struct AnimTrack {
    /* 0x0 */ u16 _00;
    /* 0x2 */ u16 count;
    /* 0x4 */ AnimKey* keys;
} AnimTrack; // size: 0x8

typedef struct AnimPlayer {
    /* 0x00 */ f32 frame;
    /* 0x04 */ u8 _04[0xA - 0x4];
    /* 0x0A */ u16 track;
    /* 0x0C */ u8 _0C[0x18 - 0xC];
    /* 0x18 */ AnimTrack tracks[1];
} AnimPlayer;

// .text:0x80025FFC size:0x134
// 98.64%: the target tests state == NULL with bne over a separate blr where this
// compiles to beqlr; the rest matches. Nested ifs, && chains and an inline helper all gave beqlr.
void fn_80025FFC(void* file, AnimState* state)
{
    AnimSub* sub;
    u32 i;

    if (file == NULL) {
        return;
    }
    if (state == NULL) {
        return;
    }
    if (state->hdr == NULL) {
        return;
    }
    state->file = file;
    state->hdr->clips = RELOCATE(state->hdr, state->hdr->clips);
    state->hdr->sets = RELOCATE(state->hdr, state->hdr->sets);
    state->clips = state->hdr->clips;
    for (i = 0; i < state->hdr->clipCount; i++) {
        state->clips[i] = RELOCATE(state->hdr, state->clips[i]);
    }
    state->sets = state->hdr->sets;
    for (i = 0; i < state->hdr->setCount; i++) {
        state->sets[i] = RELOCATE(state->hdr, state->sets[i]);
        state->setPtrs[i] = state->sets[i];
    }
    sub = &state->sub;
    AnimSub_Init(sub);
    sub->clip = lbl_803CB7F0;
    state->current = -0x80;
    state->_59 = 1;
}

// .text:0x80025EEC size:0x110
// 95.59%: the target tests the new sub->active bit from the register it merged, before the
// stb; this stores, reloads and tests.
void fn_80025EEC(AnimState* state, int set, int index)
{
    AnimSub* sub = &state->sub;
    s8 clip = state->setPtrs[set][index];

    if (state->current == -0x80 || clip != state->current) {
        sub->active = clip > -1;
        if (sub->active) {
            AnimClipSrc* src = state->clips[clip];
            sub->_0A = 0;
            sub->clip._00 = src->_00;
            sub->clip._02 = src->_02;
            sub->clip.data = src + 1;
        } else {
            sub->clip = lbl_803CB7F0;
        }
        AnimSub_Init(sub);
        AnimSub_Set11_1(sub, 3);
        AnimSub_Set11_3(sub, 3);
        state->current = clip;
    }
}

// .text:0x80025DDC size:0x110
void fn_80025DDC(AnimFile* file)
{
    AnimItem* item;
    AnimGroup* group;
    int i;
    int j;
    int k;

    file->_10 = 0;
    if (file->entries != NULL) {
        file->entries = RELOCATE(file, file->entries);
    }
    if (file->groups != NULL) {
        file->groups = RELOCATE(file, file->groups);
    }
    if (file->groups != NULL) {
        for (i = 0; i < file->groupCount; i++) {
            group = &file->groups[i];
            group->items = RELOCATE(file, group->items);
            item = group->items;
            for (j = 0; j < group->itemCount; j++) {
                item->_08 = RELOCATE(file, item->_08);
                for (k = 0; k < group->ptrCount; k++) {
                    item->ptrs[k] = RELOCATE(file, item->ptrs[k]);
                }
                item = (AnimItem*)((u8*)item + group->itemSize);
            }
        }
    }
    if (file->entries != NULL) {
        for (i = 0; i < file->entryCount; i++) {
            file->entries[i]._0C = RELOCATE(file, file->entries[i]._0C);
        }
    }
}

// .text:0x80024D2C size:0x84
u32 fn_80024D2C(AnimPlayer* anim)
{
    AnimTrack* track = &anim->tracks[anim->track];
    int i = track->count;

    while (i-- != 0) {
        if (track->keys[i].f.frame <= anim->frame) {
            return track->keys[i].raw & 0xF0000000;
        }
    }
    return 0;
}
