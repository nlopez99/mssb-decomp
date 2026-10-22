#include "Dolphin/os.h"
#include "C3/act.h"
#include "static/static_80021188.h"

#define ALIGN32(x) (((x) + 0x1F) & ~0x1F)

typedef struct UnkBF068 {
    /* 0x00 */ u8 _00[8];
    /* 0x08 */ void *_08;
} UnkBF068;

// An actor layout file: the header, then one ActorBone per bone.
typedef struct ActorLayoutFile {
    /* 0x00 */ ActorLayout header;
    /* 0x20 */ ActorBone bones[1];
} ActorLayoutFile;

// What fn_800B472C draws: a layout placed by two matrices.
typedef struct ActorDraw {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ Mtx world;
    /* 0x38 */ Mtx camera;
    /* 0x68 */ ActorLayout *layout;
} ActorDraw;

extern UnkBF068 *fn_800BF068(void);
extern BOOL fn_800B7D3C(s32 arg, Vec *corners, Mtx mtx);
extern void fn_800B84AC(Control *control, Control *r3, Control *r4, f32 weight);
extern void CTRLBuildMatrix_FlipY(Control *control, Mtx m);
extern void CTRLBuildMatrix_FlipX(Control *control, Mtx m);

static inline f32 getBoneWeight(u16 flags, f32 weight) {
    switch (flags & 3) {
    case 0:
        return 1.0f;
    case 1:
        return weight;
    case 2:
        return weight * weight;
    default:
        return 1.0f;
    }
}

// A half turn about y.
Mtx lbl_80111640 = {
    { -1.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, -1.0f, 0.0f },
};
extern void fn_800BF2A8(sBone **bones, sHdr *hdr, char *positionArray);
extern void fn_800BC824(DODisplayLayout *layout, void *data);
extern void fn_800B4CDC(Actor *actor);

static inline void freeDisplayObj(struct DODisplayObj *dispObj) {
    if (dispObj->displayData) {
        fn_800ACFB0(dispObj->displayData);
    }
    if (dispObj->lightingData) {
        fn_800ACFB0(dispObj->lightingData);
    }
    if (dispObj->textureData) {
        fn_800ACFB0(dispObj->textureData);
    }
    if (dispObj->colorData) {
        fn_800ACFB0(dispObj->colorData);
    }
    if (dispObj->positionData) {
        fn_800ACFB0(dispObj->positionData);
    }
    fn_800ACFB0(dispObj);
}


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
// Differs: the target copies the first bone's address from r0 into r4 (one extra mr).
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
void fn_800B472C(struct ActorDraw *draw) {
    MtxPtr world = draw->world;
    MtxPtr camera = draw->camera;
    int i;
    ActorLayout *layout;
    struct DODisplayObj *obj;
    DODisplayDataPtr pal;
    Vec corners[8];
    Mtx mtx;

    layout = draw->layout;
    pal = (DODisplayDataPtr)layout->geoPaletteName;
    for (i = 0; i < layout->totalBones; i++) {
        if (((ActorLayoutFile *)layout)->bones[i].geoFileID != 0xFFFF) {
            obj = (struct DODisplayObj *)pal->descriptorArray[((ActorLayoutFile *)layout)->bones[i].geoFileID].layout;
            CTRLBuildMatrix(((ActorLayoutFile *)layout)->bones[i].orientationCtrl, obj->worldMatrix);
            PSMTXConcat(world, obj->worldMatrix, obj->worldMatrix);
            PSMTXConcat(camera, obj->worldMatrix, mtx);
            corners[0].x = obj->xMax;
            corners[0].y = obj->yMax;
            corners[0].z = obj->zMin;
            corners[1].x = obj->xMin;
            corners[1].y = obj->yMax;
            corners[1].z = obj->zMin;
            corners[2].x = obj->xMin;
            corners[2].y = obj->yMax;
            corners[2].z = obj->zMax;
            corners[3].x = obj->xMax;
            corners[3].y = obj->yMax;
            corners[3].z = obj->zMax;
            corners[4].x = obj->xMax;
            corners[4].y = obj->yMin;
            corners[4].z = obj->zMin;
            corners[5].x = obj->xMin;
            corners[5].y = obj->yMin;
            corners[5].z = obj->zMin;
            corners[6].x = obj->xMin;
            corners[6].y = obj->yMin;
            corners[6].z = obj->zMax;
            corners[7].x = obj->xMax;
            corners[7].y = obj->yMin;
            corners[7].z = obj->zMax;
            if (fn_800B7D3C(0, corners, mtx) != 0) {
                if (((ActorLayoutFile *)layout)->bones[i].pad16 & 1) {
                    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
                } else {
                    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
                }
                switch (((ActorLayoutFile *)layout)->bones[i].pad16 & 6) {
                case 2:
                    GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_CLEAR);
                    break;
                case 4:
                    GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTCOL, GX_BL_ZERO, GX_LO_CLEAR);
                    break;
                default:
                    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
                    break;
                }
                DOVARender(obj, camera, 0, NULL);
            }
        }
    }
}

// .text:0x800B4724 size:0x8
void fn_800B4724(Actor *actor, sHdr *skHeader) {
    actor->skHeader = skHeader;
}

// .text:0x800B43A0 size:0x384
// Differs: registers only, in the allocation size's sum (totalBones loaded into r0, not r4).
Actor *fn_800B43A0(ActorLayout *layout) {
    Actor *actor;
    u32 boneArraySize;
    u32 forwardSize;
    u32 skinSize;
    u32 orientSize;
    u32 invTransposeSize;
    u32 vertSize;
    u16 boneCount;
    u32 size;
    sBone *bones;
    Actor header;
    Mtx m;
    u16 compSize;
    s32 diff;

    skinSize = 0;
    orientSize = 0;
    invTransposeSize = 0;
    vertSize = 0;
    boneCount = 0;
    boneArraySize = ALIGN32(layout->totalBones * sizeof(sBone *));
    forwardSize = ALIGN32(layout->totalBones * sizeof(Mtx));
    if (layout->skinFileID != 0xFFFF) {
        DOGet(&header.skinObject, (DODisplayDataPtr)layout->geoPaletteName, layout->skinFileID);
        size = ALIGN32(layout->totalBones * sizeof(Mtx));
        skinSize = size;
        orientSize = size;
        if (header.skinObject->lightingData != NULL) {
            invTransposeSize = size;
        }
        switch ((u8)(header.skinObject->positionData->quantizeInfo >> 4)) {
        case 0:
        case 1:
            compSize = 1;
            break;
        case 2:
        case 3:
            compSize = 2;
            break;
        case 4:
            compSize = 4;
            break;
        default:
            compSize = 0;
            break;
        }
        vertSize = ALIGN32(header.skinObject->positionData->numPositions * (header.skinObject->positionData->compCount * compSize));
    }
    actor = _OSAllocFromHeap(0x20, sizeof(Actor) + boneArraySize + forwardSize + skinSize + orientSize + vertSize + invTransposeSize + ALIGN32(layout->totalBones * sizeof(sBone)));
    actor->boneArray = (sBone **)(actor + 1);
    actor->forwardMtxArray = (MtxPtr)((u8 *)actor->boneArray + boneArraySize);
    actor->skinObject = header.skinObject;
    actor->skHeader = NULL;
    PSMTXIdentity(m);
    actor->actorID = layout->actorID;
    actor->layout = layout;
    actor->totalBones = layout->totalBones;
    DSInitTree(&actor->hierarchy, (Ptr)(sBone *)NULL, &((sBone *)NULL)->branch);
    DSInitList(&actor->drawPriorityList, (Ptr)(sBone *)NULL, &((sBone *)NULL)->drawPriorityLink);
    actor->pal = NULL;
    if (layout->geoPaletteName != NULL) {
        actor->pal = (DODisplayDataPtr)layout->geoPaletteName;
    }
    if (layout->skinFileID != 0xFFFF) {
        DOSetWorldMatrix(actor->skinObject, m);
        actor->skinMtxArray = (MtxPtr)((u8 *)actor->forwardMtxArray + forwardSize);
        actor->orientationInvMtxArray = (MtxPtr)((u8 *)actor->skinMtxArray + skinSize);
        diff = actor->skinObject->lightingData->normalArray - actor->skinObject->positionData->positionArray;
        actor->skinObject->positionData->positionArray = (char *)actor->orientationInvMtxArray + orientSize;
        actor->skinObject->lightingData->normalArray = actor->skinObject->positionData->positionArray + diff;
        if (actor->skinObject->lightingData != NULL) {
            actor->skinInvTransposeMtxArray = (MtxPtr)(actor->skinObject->positionData->positionArray + vertSize);
        } else {
            actor->skinInvTransposeMtxArray = NULL;
        }
    } else {
        actor->skinObject = NULL;
        actor->skinMtxArray = NULL;
        actor->orientationInvMtxArray = NULL;
        actor->skinInvTransposeMtxArray = NULL;
    }
    bones = (sBone *)((u8 *)actor->forwardMtxArray + forwardSize + skinSize + orientSize + vertSize + invTransposeSize);
    actor->worldControl.type = 0;
    if (layout->hierarchy.Root != NULL) {
        fn_800B4084(NULL, (ActorBone *)layout->hierarchy.Root, actor, &boneCount, bones);
    }
    if (boneCount != actor->totalBones) {
        OSPanic("act.c", 496, "Incorrect number of bones in actor");
    }
    if (actor->skinObject != NULL) {
        f_BuildBoneSkinOrientationMatrix((sBone *)actor->hierarchy.Root, m);
    }
    ACTSort(actor);
    actor->_80 = 0;
    actor->_82 = 0;
    actor->_84 = 0;
    actor->_88 = NULL;
    actor->_8C = 1.0f;
    actor->_90 = 0.0f;
    actor->_99 = 0;
    actor->_98 = 0;
    actor->_94 = NULL;
    return actor;
}

// .text:0x800B4278 size:0x128
void fn_800B4278(Actor *actor) {
    struct DODisplayObj *dispObj;
    int i;
    struct DODisplayObj *skin;

    skin = actor->skinObject;
    fn_800B4CDC(actor);
    for (i = actor->totalBones - 1; i >= 0; i--) {
        dispObj = actor->boneArray[i]->dispObj;
        if (dispObj != NULL) {
            freeDisplayObj(dispObj);
        }
    }
    fn_800ACFB0(actor);
    if (skin != NULL) {
        freeDisplayObj(actor->skinObject);
    }
}

// .text:0x800B4084 size:0x1F4
void fn_800B4084(sBone *parent, ActorBone *layoutBone, Actor *actor, u16 *index, sBone *boneMem) {
    sBone *bone;

    while (layoutBone != NULL) {
        bone = &boneMem[*index];
        bone->branch.Children = NULL;
        DSInsertBranchBelow(&actor->hierarchy, (Ptr)parent, (Ptr)bone);
        actor->boneArray[*index] = bone;
        bone->boneID = layoutBone->boneID;
        bone->inheritanceFlag = layoutBone->inheritanceFlag;
        bone->drawingPriority = layoutBone->drawingPriority;
        bone->orientationCtrl.type = 0;
        if (layoutBone->orientationCtrl != NULL) {
            bone->orientationCtrl = *layoutBone->orientationCtrl;
        }
        bone->dispObj = NULL;
        if (layoutBone->geoFileID != 0xFFFF) {
            DOGet(&bone->dispObj, actor->pal, layoutBone->geoFileID);
        }
        bone->_18 = bone->dispObj;
        bone->animPipe = NULL;
        bone->animationCtrl.type = 0;
        bone->_A4.type = 0;
        bone->_134 = 1;
        bone->_136 = 0;
        bone->_137 = 0;
        bone->forwardMtx = actor->forwardMtxArray + *index * 3;
        PSMTXIdentity(bone->forwardMtx);
        if (actor->skinObject != NULL) {
            bone->skinMtx = actor->skinMtxArray + *index * 3;
            PSMTXIdentity(bone->skinMtx);
            bone->orientationInvMtx = actor->orientationInvMtxArray + *index * 3;
            PSMTXIdentity(bone->orientationInvMtx);
            if (actor->skinObject->lightingData != NULL) {
                bone->skinInvTransposeMtx = actor->skinInvTransposeMtxArray + *index * 3;
                PSMTXIdentity(bone->skinInvTransposeMtx);
            } else {
                bone->skinInvTransposeMtx = NULL;
            }
        } else {
            bone->skinMtx = NULL;
            bone->orientationInvMtx = NULL;
            bone->skinInvTransposeMtx = NULL;
        }
        (*index)++;
        if (layoutBone->branch.Children != NULL) {
            fn_800B4084(bone, (ActorBone *)layoutBone->branch.Children, actor, index, boneMem);
        }
        layoutBone = (ActorBone *)layoutBone->branch.Next;
    }
}

// .text:0x800B4048 size:0x3C
BOOL fn_800B4048(Actor **actor, ActorLayout *layout, u16 actorID) {
    layout->actorID = actorID;
    *actor = fn_800B43A0(layout);
    return TRUE;
}

// .text:0x800B3F20 size:0x128
void fn_800B3F20(Actor *actor) {
    Mtx m;
    Vec b;
    Vec a;

    if (actor->_80 != actor->_82) {
        CTRLBuildMatrix(&actor->worldControl, m);
        if (actor->_88 != NULL) {
            PSMTXConcat(m, lbl_80111640, m);
        }
        fn_800B34B4(actor, actor->boneArray[actor->_80], m);
        fn_800B34B4(actor, actor->boneArray[actor->_82], m);
        fn_800B2C44(actor, actor->_82, &a);
        fn_800B2C44(actor, actor->_80, &b);
        b.x = b.x - (a.x - b.x);
        b.z = b.z - (a.z - b.z);
        CTRLSetTranslation(&actor->worldControl, b.x, b.y, b.z);
    }
}

// .text:0x800B3C04 size:0x31C
void fn_800B3C04(void) {}

// .text:0x800B3A78 size:0x18C
void fn_800B3A78(Actor *actor, MtxPtr camera, u8 numLights, ...) {
    va_list list;
    sBone *bone;

    if (actor->_98 & 9) {
        if (actor->skinObject != NULL) {
            fn_800B2D5C(actor);
            GXInvalidateVtxCache();
            va_start(list, numLights);
            if (actor->skHeader != NULL) {
                DOVARender(actor->skinObject, camera, numLights, &list);
            } else {
                DOVARenderSkin(actor->skinObject, camera, actor->skinMtxArray, actor->skinInvTransposeMtxArray, numLights, &list);
            }
            va_end(list);
        }
        for (bone = (sBone *)actor->drawPriorityList.Head; bone != NULL; bone = (sBone *)bone->drawPriorityLink.Next) {
            if (bone->dispObj != NULL) {
                DOSetWorldMatrix(bone->dispObj, bone->forwardMtx);
            }
            va_start(list, numLights);
            DOVARender(bone->dispObj, camera, numLights, &list);
            va_end(list);
        }
    }
}

// .text:0x800B37A4 size:0x2D4
void f_BuildBoneSkinOrientationMatrix(sBone *bone, MtxPtr parent) {
    Mtx m;
    Mtx world;

    for (; bone != NULL; bone = (sBone *)bone->branch.Next) {
        if (bone->inheritanceFlag == 1) {
            CTRLBuildMatrix(&bone->orientationCtrl, m);
            PSMTXConcat(parent, m, world);
            PSMTXInverse(world, bone->orientationInvMtx);
        } else {
            CTRLBuildInverseMatrix(&bone->orientationCtrl, bone->orientationInvMtx);
        }
        if (bone->branch.Children != NULL) {
            f_BuildBoneSkinOrientationMatrix((sBone *)bone->branch.Children, world);
        }
    }
}

// .text:0x800B34B4 size:0x2F0
// Differs: prologue scheduling only (the target interleaves the parameter copies
// with the first loads).
void fn_800B34B4(Actor *actor, sBone *bone, MtxPtr parentMtx) {
    f32 weight;
    sBone *parent;
    u16 i;
    sBone *other;
    Mtx m;
    Mtx orient;
    Mtx rot;

    weight = getBoneWeight(bone->_134, actor->_8C);
    for (i = 0; i < actor->totalBones && bone->boneID != actor->boneArray[i]->boneID; i++) {
    }
    parent = (sBone *)bone->branch.Parent;
    if (parent != NULL) {
        fn_800B34B4(actor, parent, parentMtx);
    }
    if (bone->_134 & 0x20) {
        if (bone->_134 & 4) {
            bone->_A4.controlParams.srt.t.x = bone->animationCtrl.controlParams.srt.t.x;
        }
        if (bone->_134 & 8) {
            bone->_A4.controlParams.srt.t.y = bone->animationCtrl.controlParams.srt.t.y;
        }
        if (bone->_134 & 0x10) {
            bone->_A4.controlParams.srt.t.z = bone->animationCtrl.controlParams.srt.t.z;
        }
    }
    if (bone->animationCtrl.type != 0) {
        if (actor->_88 == NULL) {
            fn_800B84AC(&bone->animationCtrl, &bone->_A4, &bone->animationCtrl, weight);
            CTRLBuildMatrix(&bone->animationCtrl, m);
        } else if (actor->_94 == NULL || !actor->_94(bone, actor->boneArray[actor->_88[i]], m, weight)) {
            other = actor->boneArray[actor->_88[i]];
            fn_800B84AC(&other->animationCtrl, &other->_A4, &other->animationCtrl, weight);
            if (bone->branch.Parent != NULL) {
                CTRLBuildMatrix_FlipY(&other->animationCtrl, m);
            } else {
                CTRLBuildMatrix_FlipX(&other->animationCtrl, m);
            }
            switch (bone->_137) {
            case 1:
                PSMTXRotRad(rot, 'X', 3.1415927f);
                PSMTXConcat(m, rot, m);
                break;
            case 2:
                PSMTXRotRad(rot, 'Y', 3.1415927f);
                PSMTXConcat(m, rot, m);
                break;
            case 3:
                PSMTXRotRad(rot, 'Z', 3.1415927f);
                PSMTXConcat(m, rot, m);
                break;
            }
        }
        if (bone->animPipe->replaceHierarchyCtrl == 0) {
            CTRLBuildMatrix(&bone->orientationCtrl, orient);
            PSMTXConcat(orient, m, m);
        }
    } else {
        CTRLBuildMatrix(&bone->orientationCtrl, m);
    }
    if (bone->inheritanceFlag == 1 && parent != NULL) {
        PSMTXConcat(parent->forwardMtx, m, bone->forwardMtx);
    } else {
        PSMTXConcat(parentMtx, m, bone->forwardMtx);
    }
}

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
void Set_FUN_800b2b6c(Actor *actor, u16 *value) {
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
