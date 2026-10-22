#include "C3/static_800BD478.h"
#include "string.h"

extern void OSReport(const char* msg, ...);
extern void* _OSAllocFromHeap(u32 align, u32 size);

extern void fn_800BC824(struct DODisplayObj* dispObj, GXTexObj* texObj);
extern struct { u8 _00[8]; GXTexObj* _08; }* fn_800BF068(void);
extern void fn_800B2BFC(Actor* actor, u16 arg1, u16 arg2);
extern void AnimateActorBones(Actor* actor);
extern void fn_800B3F20(Actor* actor);
extern void fn_800B313C(Actor* actor);
extern void fn_800B4048(ActorSlot* slot, s32 arg1, s32 index);
extern void fn_800B4724(ActorEx* actor, s32 arg1);

// .text:0x800BD478 size:0xD0
void fn_800BD478(Actor** actor, ActorLayoutBones* layout) {
    struct DODisplayObj* dispObj;
    s32 i;
    s32 j;

    for (i = 0; i < layout->layout.totalBones; i++) {
        if (layout->bones[i].pad16 & 0x18) {
            for (j = 0; j < (*actor)->totalBones; j++) {
                if (layout->bones[i].boneID == (*actor)->boneArray[j]->boneID) {
                    if (layout->bones[i].geoFileID != 0xFFFF) {
                        dispObj = (*actor)->boneArray[j]->dispObj;
                        if (dispObj != NULL) {
                            fn_800BC824(dispObj, fn_800BF068()->_08);
                        }
                    }
                    break;
                }
            }
        }
    }
}

// .text:0x800BD548 size:0x128
void fn_800BD548(void) {}

// .text:0x800BD670 size:0x254
void fn_800BD670(void) {}

// .text:0x800BD8C4 size:0x160
void fn_800BD8C4(void) {}

// .text:0x800BDA24 size:0x70
void fn_800BDA24(ActorAnimState* state) {
    Actor* actor = state->actor;

    memcpy(&state->actor->worldControl, &state->control, sizeof(Control));
    fn_800B2BFC(state->actor, state->_64, state->_66);
    AnimateActorBones(actor);
    fn_800B3F20(actor);
    fn_800B313C(actor);
}

// .text:0x800BDA94 size:0x1F4
void fn_800BDA94(void) {}

// .text:0x800BDC88 size:0xEC
void fn_800BDC88(ActorGroup* group, u16 index, s16 arg2, s32 arg3, u32 arg4, s32 arg5) {
    fn_800B4048(&group->slots[index], arg3, index);
    fn_800B4724(group->slots[index].actor, arg5);
    group->slots[index]._0E = 0;
    group->slots[index]._54 = 1.0f;
    group->slots[index]._64 = 0;
    group->slots[index]._66 = 0;
    group->slots[index]._68 = 0;
    group->slots[index]._6D = 0;
    group->slots[index]._70[0] = 0;
    group->slots[index]._70[1] = 0;
    group->slots[index]._70[2] = 0;
    group->slots[index]._70[3] = 0;
    group->slots[index]._70[4] = 0;
    group->slots[index]._70[5] = 0;
    group->slots[index]._70[6] = 0;
    group->slots[index]._70[7] = 0;
    group->slots[index]._0C = arg2;
    group->slots[index]._6C = 1;
    if (arg4 != 0) {
        group->slots[index]._04 = arg4;
        group->slots[index]._58 = 1;
        group->slots[index]._5A = 1;
        group->slots[index]._59 = 1;
        group->slots[index]._60 = 0.0f;
        if (group->slots[index].actor != NULL) {
            group->slots[index].actor->_99 = 0;
        }
    }
    group->slots[index]._08 = 0;
}

// .text:0x800BDD74 size:0x118
ActorGroup* ActorObjectInitTable(u16 count) {
    ActorGroup* group;
    u16 i;

    if (count == 0) {
        OSReport("Warning : ActorObjectInitTable関数が引数0で呼ばれました。テーブルは作成されずにリターンします。\n");
        return NULL;
    }
    group = _OSAllocFromHeap(0x20, count * sizeof(ActorSlot) + 0x34);
    group->count = count;
    PSMTXIdentity(group->mtx);
    for (i = 0; i < group->count; i++) {
        group->slots[i].actor = NULL;
        group->slots[i]._04 = 0;
        group->slots[i]._08 = 0;
        group->slots[i]._0E = 0;
        group->slots[i]._54 = 1.0f;
        group->slots[i]._5C = 0.0f;
        group->slots[i]._60 = 0.0f;
        group->slots[i]._64 = 0;
        group->slots[i]._66 = 0;
        group->slots[i]._68 = 0;
        group->slots[i]._6D = 0;
        group->slots[i]._70[0] = 0;
        group->slots[i]._70[1] = 0;
        group->slots[i]._70[2] = 0;
        group->slots[i]._70[3] = 0;
        group->slots[i]._70[4] = 0;
        group->slots[i]._70[5] = 0;
        group->slots[i]._70[6] = 0;
        group->slots[i]._70[7] = 0;
        group->slots[i]._0C = 0;
        group->slots[i]._6C = 0;
        group->slots[i]._58 = 0;
        group->slots[i]._5A = 0;
        group->slots[i]._59 = 0;
        group->slots[i]._5B = 1;
        group->slots[i]._10 = 0;
        group->slots[i]._0C = i;
    }
    return group;
}
