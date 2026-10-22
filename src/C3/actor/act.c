#include "C3/act.h"

typedef struct UnkBF068 {
    /* 0x00 */ u8 _00[8];
    /* 0x08 */ void *_08;
} UnkBF068;

// An actor layout file: the header, then one ActorBone per bone.
typedef struct ActorLayoutFile {
    /* 0x00 */ ActorLayout header;
    /* 0x20 */ ActorBone bones[1];
} ActorLayoutFile;

extern UnkBF068 *fn_800BF068(void);
extern void fn_800BF2A8(sBone **bones, sHdr *hdr, char *positionArray);
extern void fn_800BC824(DODisplayLayout *layout, void *data);


// .text:0x800B49E4 size:0x60
void fn_800B49E4(ActorLayout *layout) {
    int i;

    layout->hierarchy.Offset = (u32)layout + layout->hierarchy.Offset;
    layout->hierarchy.Root = (Ptr)((u32)layout + (u32)layout->hierarchy.Root);
    layout->geoPaletteName = (char *)((u32)layout + (u32)layout->geoPaletteName);
    layout->userData = (char *)((u32)layout + (u32)layout->userData);
    for (i = 0; i < layout->totalBones; i++) {
        ((ActorLayoutFile *)layout)->bones[i].orientationCtrl = (Control *)((u32)layout + (u32)((ActorLayoutFile *)layout)->bones[i].orientationCtrl);
    }
}

// .text:0x800B4910 size:0xD4
void LoadActorLayout(ActorLayout *layout) {
    ActorBone *bone;
    u32 i;

    if (layout->userDataSize != 0 && layout->userData != NULL) {
        layout->userData = (char *)((u32)layout->userData + (u32)layout);
    }
    if (layout->hierarchy.Root != NULL) {
        layout->hierarchy.Root = (Ptr)((u32)layout->hierarchy.Root + (u32)layout);
    }
    if (layout->geoPaletteName != NULL) {
        layout->geoPaletteName = (char *)((u32)layout->geoPaletteName + (u32)layout);
    }
    bone = (ActorBone *)(layout + 1);
    for (i = 0; i < layout->totalBones; i++) {
        if (bone->orientationCtrl != NULL) {
            bone->orientationCtrl = (Control *)((u32)layout + (u32)bone->orientationCtrl);
        }
        if (bone->branch.Prev != NULL) {
            bone->branch.Prev = (Ptr)((u32)layout + (u32)bone->branch.Prev);
        }
        if (bone->branch.Next != NULL) {
            bone->branch.Next = (Ptr)((u32)layout + (u32)bone->branch.Next);
        }
        if (bone->branch.Parent != NULL) {
            bone->branch.Parent = (Ptr)((u32)layout + (u32)bone->branch.Parent);
        }
        if (bone->branch.Children != NULL) {
            bone->branch.Children = (Ptr)((u32)layout + (u32)bone->branch.Children);
        }
        bone++;
    }
}

// .text:0x800B4908 size:0x8
void haveActLayoutPointToGeoHeader(ActorLayout *layout, char *geoPalette) {
    layout->geoPaletteName = geoPalette;
}

// .text:0x800B472C size:0x1DC
void fn_800B472C(void) {}

// .text:0x800B4724 size:0x8
void fn_800B4724(Actor *actor, sHdr *skHeader) {
    actor->skHeader = skHeader;
}

// .text:0x800B43A0 size:0x384
void fn_800B43A0(void) {}

// .text:0x800B4278 size:0x128
void fn_800B4278(void) {}

// .text:0x800B4084 size:0x1F4
void fn_800B4084(void) {}

// .text:0x800B4048 size:0x3C
void fn_800B4048(void) {}

// .text:0x800B3F20 size:0x128
void fn_800B3F20(void) {}

// .text:0x800B3C04 size:0x31C
void fn_800B3C04(void) {}

// .text:0x800B3A78 size:0x18C
void fn_800B3A78(void) {}

// .text:0x800B37A4 size:0x2D4
void f_BuildBoneSkinOrientationMatrix(void) {}

// .text:0x800B34B4 size:0x2F0
void fn_800B34B4(void) {}

// .text:0x800B313C size:0x378
void fn_800B313C(void) {}

// .text:0x800B2DD0 size:0x36C
void fn_800B2DD0(void) {}

// .text:0x800B2D5C size:0x74
void fn_800B2D5C(Actor *actor) {
    GQRSetup5(8, 4, 8, 4);
    if (actor->skinObject->positionData->quantizeInfo == 0x40) {
        SKNIt(actor->boneArray, actor->skHeader, actor->skinObject->positionData->positionArray);
    } else {
        fn_800BF2A8(actor->boneArray, actor->skHeader, actor->skinObject->positionData->positionArray);
    }
}

// .text:0x800B2CBC size:0xA0
void ACTSort(Actor *actor) {
    u16 i;
    sBone *bone;
    sBone *cursor;

    actor->drawPriorityList.Head = NULL;
    actor->drawPriorityList.Tail = NULL;
    for (i = 0; i < actor->totalBones; i++) {
        bone = actor->boneArray[i];
        if (bone->dispObj) {
            cursor = (sBone *)actor->drawPriorityList.Head;
            while (cursor) {
                if (cursor->drawingPriority > actor->boneArray[i]->drawingPriority) {
                    break;
                }
                cursor = (sBone *)cursor->drawPriorityLink.Next;
            }
            DSInsertListObject(&actor->drawPriorityList, (Ptr)cursor, (Ptr)bone);
        }
    }
}

// .text:0x800B2C88 size:0x34
void fn_800B2C88(Actor *actor, u16 boneIndex, Mtx m) {
    PSMTXCopy(actor->forwardMtxArray + boneIndex * 3, m);
}

// .text:0x800B2C44 size:0x44
void fn_800B2C44(Actor *actor, u16 boneIndex, Vec *v) {
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
    PSMTXMultVec(actor->forwardMtxArray + boneIndex * 3, v, v);
}

// .text:0x800B2C10 size:0x34
void fn_800B2C10(Actor *actor, u16 boneIndex, Vec *v) {
    PSMTXMultVec(actor->forwardMtxArray + boneIndex * 3, v, v);
}

// .text:0x800B2C08 size:0x8
void fn_800B2C08(Actor *actor, u16 value) {
    actor->_84 = value;
}

// .text:0x800B2BFC size:0xC
void fn_800B2BFC(Actor *actor, u16 a, u16 b) {
    actor->_80 = a;
    actor->_82 = b;
}

// .text:0x800B2BE4 size:0x18
void fn_800B2BE4(Actor *actor, u16 boneIndex) {
    sBone *bone = actor->boneArray[boneIndex];
    bone->dispObj = bone->_18;
}

// .text:0x800B2BA8 size:0x3C
struct DODisplayObj *fn_800B2BA8(Actor *actor, u16 boneIndex, Actor *src, u16 srcIndex) {
    sBone *bone = actor->boneArray[boneIndex];
    struct DODisplayObj *old = bone->dispObj;
    if (src != NULL) {
        bone->dispObj = src->boneArray[srcIndex]->dispObj;
        return old;
    }
    bone->dispObj = NULL;
    return old;
}

// .text:0x800B2B74 size:0x34
void fn_800B2B74(Actor *actor, u16 boneIndex) {
    DSInsertListObject(&actor->drawPriorityList, actor->drawPriorityList.Tail, (Ptr)actor->boneArray[boneIndex]);
}

// .text:0x800B2B6C size:0x8
void Set_FUN_800b2b6c(Actor *actor, u32 value) {
    actor->_88 = value;
}

// .text:0x800B2B54 size:0x18
void fn_800B2B54(Actor *actor, u16 boneIndex, u8 value) {
    actor->boneArray[boneIndex]->_134 = value;
}

// .text:0x800B2B4C size:0x8
void fn_800B2B4C(Actor *actor, f32 value) {
    actor->_90 = value;
}

// .text:0x800B2AC8 size:0x84
void fn_800B2AC8(ActorLayout *layout) {
    int i;
    DODisplayDataPtr pal;
    DODisplayLayout *dispLayout;

    pal = (DODisplayDataPtr)layout->geoPaletteName;
    for (i = 0; i < layout->totalBones; i++) {
        if (((ActorLayoutFile *)layout)->bones[i].pad16 & 0x18) {
            if (((ActorLayoutFile *)layout)->bones[i].geoFileID != 0xFFFF) {
                dispLayout = pal->descriptorArray[((ActorLayoutFile *)layout)->bones[i].geoFileID].layout;
                fn_800BC824(dispLayout, fn_800BF068()->_08);
            }
        }
    }
}
