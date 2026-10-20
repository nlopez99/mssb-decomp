#include "static/anim.h"
#include "Dolphin/os.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct AnimRange {
    /* 0x0 */ u16 start;
    /* 0x2 */ u16 count; // 0 ends the list
} AnimRange;

typedef struct AnimItem {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ u8 entry; // AnimEntry.index it animates
    /* 0x05 */ u8 type;  // bit 7: only on the second pass; low 7 bits: AnimEntry.type
    /* 0x06 */ u8 elemCount;
    /* 0x07 */ u8 elemSize;
    /* 0x08 */ AnimRange* _08;
    /* 0x0C */ void* ptrs[1]; // AnimGroup.ptrCount of them, one per clip
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

extern u8 lbl_803CBBC0;
extern s32 lbl_803CBC68;

static inline int AnimSub_Get11_1(AnimSub* sub)
{
    if (sub != NULL) {
        return sub->_11_1 & (1 << (lbl_803CBBC0 != 0));
    }
    return 0;
}

static inline int AnimSub_Get11_3(AnimSub* sub)
{
    if (sub != NULL) {
        return sub->_11_3 & (1 << (lbl_803CBBC0 != 0));
    }
    return 0;
}

static inline void AnimSub_Clear11_1(AnimSub* sub)
{
    if (sub != NULL) {
        sub->_11_1 = sub->_11_1 & (1 << (lbl_803CBBC0 == 0));
    }
}

static inline void AnimSub_Clear11_3(AnimSub* sub)
{
    if (sub != NULL) {
        sub->_11_3 = sub->_11_3 & (1 << (lbl_803CBBC0 == 0));
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

// .text:0x80024FA4 size:0xCB4
// Blends the current and next key's clips into the model's arrays and flushes them.
// 66.48%, a first draft from the assembly: this build is 0x23C bytes longer; its byte and
// s16 blend loops unroll by 8 where the target's unroll by 4, and it keeps anim on the stack.
void fn_80024FA4(Model* model, AnimFile* file, AnimSub* anim, int clipOverride)
{
    AnimClip* clip = &anim->clips[anim->clipIndex];
    u8 last = 0;
    ModelRoot* root;
    ModelSkin* skin;
    void* defData;
    u8* mats;
    AnimKey* keys;
    u16 key;
    u16 keyCount;
    int next;
    f32 t0;
    f32 t1;
    f32 ease0;
    f32 ease1;
    f32 frame;
    f32 w;
    f32 invW;
    int mode;
    int a8, b8, a16, b16;
    int clipA;
    int clipB;
    int offA;
    int offB;
    int g;
    int groupOffset;

    if (file == NULL || file->entries == NULL) {
        return;
    }
    if (AnimSub_Get11_1(anim) == 0 && AnimSub_Get11_3(anim) == 0) {
        return;
    }
    key = anim->key;
    keyCount = clip->keyCount;
    if (key == keyCount || (last = clip->keys[key + 1].f.flags >> 2 & 1)) {
        if (AnimSub_Get11_3(anim) == 0) {
            return;
        }
    }
    skin = model->data->skin;
    root = model->data->root;
    if (skin == NULL) {
        defData = NULL;
        mats = NULL;
    } else {
        if (skin->_08 != NULL) {
            defData = *(void**)(skin->_08 + 0x30);
        } else if (skin->_0C != NULL) {
            defData = *(void**)(skin->_0C + 0x60);
        } else {
            defData = NULL;
        }
        mats = skin->mats;
    }
    keys = clip->keys;
    next = key + 1;
    t0 = keys[key].f.frame;
    if (next == keyCount) {
        t1 = 0.0f;
        last = 1;
    } else {
        t1 = keys[next].f.frame;
    }
    if (last) {
        mode = 0;
    } else {
        if (keys[key].f.flags & 8) {
            ease0 = 1.0f - ((u8*)&keys[key])[2] / 100.0f;
        } else {
            ease0 = 0.0f;
        }
        if (keys[next].f.flags & 8) {
            ease1 = ((u8*)&keys[key])[6] / 100.0f;
        } else {
            ease1 = 1.0f;
        }
        frame = anim->frame;
        if (frame == t0) {
            w = ease0;
            mode = 0;
        } else if (frame == t1) {
            w = ease1;
            mode = 1;
        } else {
            mode = 2;
            w = (frame - t0) / (t1 - t0) * (ease1 - ease0) + ease0;
        }
        if (w != 1.0f && w != 0.0f) {
            mode = 2;
        }
        a8 = 16777216.0f * (1.0f - w);
        a16 = 65536.0f * (1.0f - w);
        b8 = 0x1000000 - a8;
        b16 = 0x10000 - a16;
    }
    if ((keys[key].f.flags & 2) && clipOverride != -1) {
        clipA = clipOverride;
    } else {
        clipA = ((u8*)&keys[key])[3];
    }
    if (last) {
        clipB = clipA;
    } else if ((keys[next].f.flags & 2) && clipOverride != -1) {
        clipB = clipOverride;
    } else {
        clipB = ((u8*)&keys[key])[7];
    }
    offA = clipA * 4;
    invW = 1.0f - w;
    offB = clipB * 4;
    for (g = 0, groupOffset = 0; g < file->groupCount; g++, groupOffset += sizeof(AnimGroup)) {
        AnimGroup* group = (AnimGroup*)((u8*)file->groups + groupOffset);
        AnimItem* item = group->items;
        int j;
        int e = 0;
        int entryOffset = 0;

        for (j = 0; j < group->itemCount; j++) {
            AnimEntry* found;
            u32 second;
            void* flushData;
            u32 flushSize;
            u32 nib;
            int type;

            if (AnimSub_Get11_1(anim) == 0) {
                item = (AnimItem*)((u8*)item + group->itemSize);
                continue;
            }
            second = item->type >> 7 & 1;
            if (second && AnimSub_Get11_3(anim) == 0) {
                item = (AnimItem*)((u8*)item + group->itemSize);
                continue;
            }
            found = NULL;
            do {
                AnimEntry* entry = (AnimEntry*)((u8*)file->entries + entryOffset);
                if (item->entry == entry->index && (item->type & 0x7F) == (entry->type & 0x7F)) {
                    found = entry;
                    break;
                }
                e++;
                entryOffset += sizeof(AnimEntry);
            } while (e < file->entryCount);
            if (found == NULL) {
                break;
            }
            {
                int count = item->elemCount;
                int size = item->elemSize;
                u8* dst = *(u8**)((u8*)found + ((found->type >> 5) & 4) + 8);
                int off = 0;
                u8* srcA = *(u8**)((u8*)item->ptrs + offA);
                u8* srcB = *(u8**)((u8*)item->ptrs + offB);
                int r;
                int k;
                int c;

                if (second || last || mode == 0) {
                    int stride = size * count;
                    for (r = 0; item->_08[r].count != 0; r++) {
                        int n = item->_08[r].count * stride;
                        memcpy(dst + item->_08[r].start * stride, srcA + off, n);
                        off += n;
                    }
                } else {
                    switch (mode) {
                    case 1: {
                        int stride = size * count;
                        for (r = 0; item->_08[r].count != 0; r++) {
                            int n = item->_08[r].count * stride;
                            memcpy(dst + item->_08[r].start * stride, srcB + off, n);
                            off += n;
                        }
                        break;
                    }
                    case 2:
                        if ((item->type & 0x7F) == 3) {
                            for (r = 0; item->_08[r].count != 0; r++) {
                                for (k = 0; k < item->_08[r].count; k++) {
                                    u16* d = (u16*)(dst + count * (item->_08[r].start + k) * 2);
                                    u16 va = *(u16*)(srcA + off);
                                    u16 vb = *(u16*)(srcB + off);
                                    *d = (int)((va & 0xF) * invW + (vb & 0xF) * w) & 0xF;
                                    *d |= (int)((*(u16*)(srcA + off) & 0xF0) * invW + (*(u16*)(srcB + off) & 0xF0) * w) & 0xF0;
                                    *d |= (int)((*(u16*)(srcA + off) & 0xF00) * invW + (*(u16*)(srcB + off) & 0xF00) * w) & 0xF00;
                                    *d |= (int)((*(u16*)(srcA + off) & 0xF000) * invW + (*(u16*)(srcB + off) & 0xF000) * w) & 0xF000;
                                    off += size * count;
                                }
                            }
                        } else if (size == 1) {
                            for (r = 0; item->_08[r].count != 0; r++) {
                                for (k = 0; k < item->_08[r].count; k++) {
                                    s8* d = (s8*)(dst + (item->_08[r].start + k) * (count * size));
                                    for (c = 0; c < count; c++) {
                                        *d++ = (a8 * srcA[off] + (b8 * srcB[off] + (lbl_803CBC68 << 24))) / 0x1000000;
                                        off += size;
                                    }
                                }
                            }
                        } else if (size == 2) {
                            for (r = 0; item->_08[r].count != 0; r++) {
                                for (k = 0; k < item->_08[r].count; k++) {
                                    s16* pa = (s16*)(srcA + off);
                                    s16* pb = (s16*)(srcB + off);
                                    int d = count * (item->_08[r].start + k) * 2;
                                    for (c = 0; c < count; c++) {
                                        off += size;
                                        *(s16*)(dst + d) = (a16 * *pa++ + (b16 * *pb++ + (lbl_803CBC68 << 16))) / 0x10000;
                                        d += 2;
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
            }
            nib = (found->_03 >> 4) & 0xF;
            type = found->type & 0x7F;
            flushSize = nib * (found->_03 & 0xF);
            item = (AnimItem*)((u8*)item + group->itemSize);
            switch (type) {
            case 0:
                flushData = *(void**)(mats + found->index * 0x44 + 0x30);
                flushSize *= *(u16*)(mats + found->index * 0x44 + 0x42);
                break;
            case 1:
                if (nib == 6) {
                    flushData = defData;
                } else {
                    flushData = *(void**)root->nodes[found->index].node->_00;
                }
                flushSize *= ((u16*)root->nodes[found->index].node->_00)[2];
                break;
            case 2:
                flushData = *(void**)root->nodes[found->index].node->_0C;
                flushSize *= ((u16*)root->nodes[found->index].node->_0C)[2];
                break;
            case 3:
                flushData = *(void**)root->nodes[found->index].node->_04;
                flushSize *= ((u16*)root->nodes[found->index].node->_04)[2];
                break;
            case 4:
            case 5:
            case 6:
            case 7:
                flushData = *(void**)(root->nodes[found->index].node->_08 + (type - 4) * 0x10);
                flushSize *= *(u16*)(root->nodes[found->index].node->_08 + (type - 4) * 0x10 + 4);
                break;
            }
            DCFlushRangeNoSync(flushData, flushSize);
        }
    }
    AnimSub_Clear11_1(anim);
    AnimSub_Clear11_3(anim);
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
