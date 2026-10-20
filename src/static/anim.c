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

// Binds animation data to one value of a model: fn_80025C58 resolves target and saves its value
typedef struct AnimEntry {
    /* 0x0 */ u16 index;
    /* 0x2 */ u8 type; // low 7 bits
    /* 0x3 */ u8 _03;  // high nibble: subtype
    /* 0x4 */ u32* target;
    /* 0x8 */ u32 saved;
    /* 0xC */ void* _0C;
} AnimEntry; // size: 0x10

typedef struct ModelNode {
    /* 0x00 */ u32* _00;
    /* 0x04 */ u32* _04;
    /* 0x08 */ u8* _08; // 0x10-byte elements
    /* 0x0C */ u32* _0C;
} ModelNode;

typedef struct ModelNodeRef {
    /* 0x0 */ ModelNode* node;
    /* 0x4 */ u8 _04[4];
} ModelNodeRef; // size: 0x8

typedef struct ModelRoot {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ ModelNodeRef* nodes;
} ModelRoot;

typedef struct ModelSkin {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u8* _08;
    /* 0x0C */ u8* _0C;
    /* 0x10 */ u8* mats; // 0x44-byte elements
} ModelSkin;

typedef struct ModelData {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ ModelRoot* root;
    /* 0x14 */ u8 _14[0x7C - 0x14];
    /* 0x7C */ ModelSkin* skin;
} ModelData;

typedef struct Model {
    /* 0x00 */ ModelData* data;
} Model;

// A file loaded from disc: its pointers are offsets from the start until fn_80025DDC relocates them
typedef struct AnimFile {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 groupCount;
    /* 0x04 */ u16 entryCount;
    /* 0x06 */ u16 _06;
    /* 0x08 */ AnimGroup* groups;
    /* 0x0C */ AnimEntry* entries;
    /* 0x10 */ struct Model* model;
} AnimFile;

#define RELOCATE(base, ptr) ((void*)((u32)(base) + (u32)(ptr)))

typedef struct AnimClipSrc {
    /* 0x0 */ u16 _00;
    /* 0x2 */ u16 _02;
    // data follows
} AnimClipSrc;

typedef union AnimKey {
    u32 raw;
    struct {
        u32 flags : 4;
        u32 frame : 12;
        u32 value : 16;
    } f;
} AnimKey;

typedef struct AnimClip {
    /* 0x0 */ u16 length;
    /* 0x2 */ u16 keyCount;
    /* 0x4 */ AnimKey* keys;
} AnimClip; // size: 0x8

// Plays one clip: the current frame, the key it has reached and the loops left
typedef struct AnimSub {
    /* 0x00 */ f32 frame;
    /* 0x04 */ f32 speed;
    /* 0x08 */ s16 _08;
    /* 0x0A */ u16 clipIndex;
    /* 0x0C */ u16 key;
    /* 0x0E */ s16 loops; // -1 loops forever
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 active : 1;
    /* 0x11 */ u8 _11_1 : 2;
    /* 0x11 */ u8 _11_3 : 2;
    /* 0x11 */ u8 _11_5 : 3;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ s32 _14;
    /* 0x18 */ AnimClip clips[1];
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
        sub->frame = 0.0f;
        sub->speed = 0.5f;
        sub->_08 = 1;
        sub->clipIndex = 0;
        sub->key = 0;
        sub->loops = -1;
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
    sub->clips[0] = lbl_803CB7F0;
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
            sub->clipIndex = 0;
            sub->clips[0].length = src->_00;
            sub->clips[0].keyCount = src->_02;
            sub->clips[0].keys = (AnimKey*)(src + 1);
        } else {
            sub->clips[0] = lbl_803CB7F0;
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

    file->model = NULL;
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

// .text:0x80025C58 size:0x184
// 97.58%, registers only: the target keeps skin and mats in one register and copies the
// zeros it stores (li r0,0; mr r5,r0), which no declaration order here reproduces.
void fn_80025C58(AnimFile* file, Model* model)
{
    u32 defValue;
    u32 value;
    ModelRoot* root;
    ModelSkin* skin;
    u32* defTarget;
    int i;
    AnimEntry* entry;
    u32 sub;
    int type;
    u32* target;
    u8* mats;

    if (file->entries == NULL) {
        return;
    }
    file->model = model;
    skin = model->data->skin;
    root = model->data->root;
    if (skin == NULL) {
        defValue = 0;
        mats = NULL;
    } else {
        if (skin->_08 != NULL) {
            defTarget = (u32*)(skin->_08 + 0x30);
            defValue = *defTarget;
        } else if (skin->_0C != NULL) {
            defTarget = (u32*)(skin->_0C + 0x60);
            defValue = *defTarget;
        } else {
            defTarget = NULL;
            defValue = 0;
        }
        mats = skin->mats;
    }
    entry = file->entries;
    for (i = 0; i < file->entryCount; i++) {
        type = entry->type & 0x7F;
        sub = (entry->_03 >> 4) & 0xF;
        switch (type) {
        case 0:
            target = (u32*)(mats + entry->index * 0x44 + 0x30);
            value = *target;
            break;
        case 1:
            if (sub == 6) {
                target = defTarget;
                value = defValue;
            } else {
                target = root->nodes[entry->index].node->_00;
                value = *target;
            }
            break;
        case 2:
            target = root->nodes[entry->index].node->_0C;
            value = *target;
            break;
        case 3:
            target = root->nodes[entry->index].node->_04;
            value = *target;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            target = (u32*)(root->nodes[entry->index].node->_08 + (type - 4) * 0x10);
            value = *target;
            break;
        }
        entry->target = target;
        entry->saved = value;
        entry++;
    }
}

// .text:0x80024DB0 size:0x1F4
int fn_80024DB0(AnimSub* anim)
{
    AnimClip* clip = &anim->clips[anim->clipIndex];
    u32 atStart;
    u16 key;
    int ended;

    if (anim->loops == 0) {
        return 0;
    }
    if (!anim->active) {
        return 0;
    }
    atStart = 0.0f == anim->frame;
    key = anim->key;
    anim->frame += anim->speed;
    AnimSub_Set11_1(anim, 3);
    ended = anim->frame >= clip->length;
    if (ended) {
        if (anim->loops > 0) {
            anim->loops--;
        }
        if (anim->loops != 0) {
            anim->frame -= clip->length;
            anim->key = clip->keyCount;
            do {
                anim->key--;
            } while (clip->keys[anim->key].f.frame > anim->frame);
        } else {
            anim->frame = clip->length;
        }
    } else if (anim->key < clip->keyCount - 1) {
        while (anim->frame >= clip->keys[anim->key + 1].f.frame) {
            anim->key++;
        }
    }
    if (atStart || key != anim->key) {
        AnimSub_Set11_3(anim, 3);
    }
    return ended;
}

// .text:0x80024D2C size:0x84
u32 fn_80024D2C(AnimSub* anim)
{
    AnimClip* track = &anim->clips[anim->clipIndex];
    int i = track->keyCount;

    while (i-- != 0) {
        if (track->keys[i].f.frame <= anim->frame) {
            return track->keys[i].raw & 0xF0000000;
        }
    }
    return 0;
}
