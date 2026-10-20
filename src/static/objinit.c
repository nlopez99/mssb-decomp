#include "static/objinit.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"
#include "Dolphin/os.h"
#include "string.h"
#include "C3/control.h"
#include "C3/unktypes.h"
#include "charPipeline/structures/Tree.h"
#include "charPipeline/structures/List.h"

#define ALIGN32(x) (((x) + 0x1F) & ~0x1F)

// The game's display object: the SDK's with its own fields after the shader
typedef struct ObjDisplayLayout {
    /* 0x00 */ PositionData* positionData;
    /* 0x04 */ ColorData* colorData;
    /* 0x08 */ TextureData* textureData;
    /* 0x0C */ LightingData* lightingData;
    /* 0x10 */ DisplayData* displayData;
    /* 0x14 */ u8 numTextureChannels;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16[0x1C - 0x16];
    /* 0x1C */ u8 _1C[4];
    /* 0x20 */ u8 _20[4];
    /* 0x24 */ u8 _24[4];
    /* 0x28 */ u8 _28[4];
    /* 0x2C */ u8 _2C[4];
    /* 0x30 */ u8 _30[4];
} ObjDisplayLayout;

typedef struct ObjDisplay {
    /* 0x00 */ PositionData* positionData;
    /* 0x04 */ ColorData* colorData;
    /* 0x08 */ TextureData* textureData;
    /* 0x0C */ LightingData* lightingData;
    /* 0x10 */ DisplayData* displayData;
    /* 0x14 */ u8 numTextureChannels;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 visibility;
    /* 0x18 */ Mtx worldMatrix;
    /* 0x48 */ u8 _48[4];
    /* 0x4C */ void* shaderFunc;
    /* 0x50 */ void* shaderData;
    /* 0x54 */ u8 _54[4];
    /* 0x58 */ u8 _58[4];
    /* 0x5C */ u8 _5C[4];
    /* 0x60 */ u8 _60[4];
    /* 0x64 */ u8 _64[4];
    /* 0x68 */ u8 _68[4];
    /* 0x6C */ u8 _6C[0x80 - 0x6C];
} ObjDisplay; // size: 0x80

typedef struct ObjDescriptor {
    /* 0x00 */ ObjDisplayLayout* layout;
    /* 0x04 */ char* name;
} ObjDescriptor;

typedef struct ObjPalette {
    /* 0x00 */ u32 versionNumber;
    /* 0x04 */ u32 userDataSize;
    /* 0x08 */ void* userData;
    /* 0x0C */ u32 numDescriptors;
    /* 0x10 */ ObjDescriptor* descriptorArray;
} ObjPalette;

typedef struct ObjLayoutBone {
    /* 0x00 */ Control* orientationCtrl;
    /* 0x04 */ DSBranch branch;
    /* 0x14 */ u16 geoFileID;
    /* 0x16 */ u16 boneID;
    /* 0x18 */ u8 inheritanceFlag;
    /* 0x19 */ u8 drawingPriority;
    /* 0x1A */ u16 pad16;
} ObjLayoutBone;

typedef struct ObjLayout {
    /* 0x00 */ u32 versionNumber;
    /* 0x04 */ u16 actorID;
    /* 0x06 */ u16 totalBones;
    /* 0x08 */ DSTree hierarchy;
    /* 0x10 */ ObjPalette* pal;
    /* 0x14 */ u16 skinFileID;
} ObjLayout;

typedef struct ObjBoneAnim {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ void* _10;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
} ObjBoneAnim;

typedef struct ObjBone {
    /* 0x000 */ u16 boneID;
    /* 0x002 */ u8 inheritanceFlag;
    /* 0x003 */ u8 drawingPriority;
    /* 0x004 */ DSBranch branch;
    /* 0x014 */ ObjDisplay* dispObj;
    /* 0x018 */ ObjDisplay* _18;
    /* 0x01C */ Control orientationCtrl;
    /* 0x060 */ Control animCtrl;
    /* 0x0A4 */ Control _A4;
    /* 0x0E8 */ ObjBoneAnim* anim;
    /* 0x0EC */ MtxPtr forwardMtx;
    /* 0x0F0 */ MtxPtr skinMtx;
    /* 0x0F4 */ MtxPtr skinInvTransposeMtx;
    /* 0x0F8 */ MtxPtr orientationInvMtx;
    /* 0x0FC */ DSLink drawPriorityLink;
    /* 0x104 */ u8 _104[0x134 - 0x104];
    /* 0x134 */ u16 _134;
    /* 0x136 */ u8 _136;
    /* 0x137 */ u8 _137;
    /* 0x138 */ u8 _138[0x140 - 0x138];
} ObjBone; // size: 0x140

typedef struct ObjActor {
    /* 0x00 */ ObjLayout* layout;
    /* 0x04 */ u16 actorID;
    /* 0x06 */ u16 totalBones;
    /* 0x08 */ DSTree hierarchy;
    /* 0x10 */ ObjPalette* pal;
    /* 0x14 */ ObjDisplay* skinObject;
    /* 0x18 */ ObjBone** boneArray;
    /* 0x1C */ Control worldControl;
    /* 0x60 */ MtxPtr forwardMtxArray;
    /* 0x64 */ MtxPtr skinMtxArray;
    /* 0x68 */ MtxPtr skinInvTransposeMtxArray;
    /* 0x6C */ MtxPtr orientationInvMtxArray;
    /* 0x70 */ DSList drawPriorityList;
    /* 0x7C */ void* skHeader;
    /* 0x80 */ u16 _80;
    /* 0x82 */ u16 _82;
    /* 0x84 */ u16 _84;
    /* 0x88 */ u32 _88;
    /* 0x8C */ f32 _8C;
    /* 0x90 */ f32 _90;
    /* 0x94 */ u32 _94;
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A[0xA0 - 0x9A];
} ObjActor; // size: 0xA0

// One display object: an actor with its animation and transform
typedef struct ObjInst {
    /* 0x00 */ ObjActor* actor;
    /* 0x04 */ void* anim;
    /* 0x08 */ void* _08;
    /* 0x0C */ s16 id;
    /* 0x0E */ s16 _0E;
    /* 0x10 */ Control control;
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u16 _64;
    /* 0x66 */ u16 _66;
    /* 0x68 */ u32 _68;
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D;
    /* 0x70 */ u32 _70;
    /* 0x74 */ u32 _74;
    /* 0x78 */ u32 _78;
    /* 0x7C */ u32 _7C;
    /* 0x80 */ u32 _80;
    /* 0x84 */ u32 _84;
    /* 0x88 */ u32 _88;
    /* 0x8C */ u32 _8C;
} ObjInst; // size: 0x90

typedef struct ObjGroup {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ ObjInst insts[1];
} ObjGroup;

static inline void* ObjAlloc(u8** mem, u32 size) {
    void* p = *mem;
    *mem += size;
    return p;
}

static inline u8* GetDisplayObj(ObjDisplay** obj, ObjPalette* pal, u16 id, u8* mem) {
    u8** heap = &mem;
    u8* result;
    ObjDisplayLayout* layout;

    if (id >= pal->numDescriptors) {
        OSReport("Display object id %d is greater than number of objects %d", id, pal->numDescriptors);
        *obj = NULL;
        result = mem;
    } else {
        layout = pal->descriptorArray[id].layout;
        *obj = ObjAlloc(heap, sizeof(ObjDisplay));
        result = *heap = fn_80023078(*obj, layout, *heap);
    }
    return result;
}

extern struct {
    /* 0x00 */ u8 _00[0x60];
    /* 0x60 */ void* _60;
} lbl_8036E548;

void* lbl_8017EBB0[20];
void* lbl_8017EB40[28];
u32 lbl_803CBC5C;
u32 lbl_803CBC58;


// .text:0x80023B04 size:0x8C
void fn_80023B04(s32 count) {
    s32 i;

    lbl_8017EBB0[0] = _OSAllocFromHeap(0x20, count * 0x86A0);
    i = 1;
    do {
        lbl_8017EBB0[i] = (u8*)lbl_8017EBB0[i - 1] + 0x86A0;
        i++;
    } while (i < count);
    lbl_803CBC5C = 0x86A0;
    lbl_8036E548._60 = ActorObjectInitTable(13);
}

// .text:0x80023AA4 size:0x60
void* fn_80023AA4(void) {
    u32 i;

    lbl_8017EB40[0] = _OSAllocFromHeap(0x20, 28 * 0x1BC0);
    i = 1;
    do {
        lbl_8017EB40[i] = (u8*)lbl_8017EB40[i - 1] + 0x1BC0;
        i++;
    } while (i < 28);
    return ActorObjectInitTable(28);
}

// Differs: the target reloads lbl_8017EBB0 and the slot index for the second lookup and keeps
// slot in r27; the build keeps base and index in r30/r31 (c.f. fn_800238E0, which matches).
// .text:0x8002399C size:0x108
void fn_8002399C(ObjInst* inst, u16 slot, s16 id, ObjLayout* layout, void* anim, void* skin) {
    memset(lbl_8017EBB0[slot], 0, lbl_803CBC5C);
    layout->actorID = id;
    inst->actor = f_InitActorWithLayout(layout, lbl_8017EBB0[slot]);
    fn_800B4724(inst->actor, skin);
    inst->_0E = 0;
    inst->_54 = 1.0f;
    inst->_64 = 0;
    inst->_66 = 0;
    inst->_68 = 0;
    inst->_6D = 0;
    inst->_70 = 0;
    inst->_74 = 0;
    inst->_78 = 0;
    inst->_7C = 0;
    inst->_80 = 0;
    inst->_84 = 0;
    inst->_88 = 0;
    inst->_8C = 0;
    inst->id = id;
    inst->_6C = 1;
    if (anim != NULL) {
        inst->anim = anim;
        inst->_58 = 1;
        inst->_5A = 1;
        inst->_59 = 1;
        inst->_60 = 0.0f;
        if (inst->actor != NULL) {
            inst->actor->_99 = 0;
        }
    }
    inst->_08 = 0;
}

// .text:0x800238E0 size:0xBC
void fn_800238E0(ObjGroup* group, u16 slot, s16 id, ObjLayout* layout) {
    memset(lbl_8017EB40[slot], 0, lbl_803CBC58);
    layout->actorID = id;
    group->insts[slot].actor = f_InitActorWithLayout(layout, lbl_8017EB40[slot]);
    group->insts[slot]._0E = 0;
    group->insts[slot]._54 = 1.0f;
    group->insts[slot]._64 = 0;
    group->insts[slot]._66 = 0;
    group->insts[slot]._68 = 0;
    group->insts[slot]._6D = 0;
    group->insts[slot]._70 = 0;
    group->insts[slot]._74 = 0;
    group->insts[slot]._78 = 0;
    group->insts[slot]._7C = 0;
    group->insts[slot]._80 = 0;
    group->insts[slot]._84 = 0;
    group->insts[slot]._88 = 0;
    group->insts[slot]._8C = 0;
    group->insts[slot].id = id;
    group->insts[slot]._6C = 1;
    group->insts[slot]._08 = 0;
}

// .text:0x8002360C size:0x2D4
void BuildBoneSkinOrientationMatrix(ObjBone* bone, MtxPtr parent) {
    Mtx m;
    Mtx world;

    for (; bone != NULL; bone = (ObjBone*)bone->branch.Next) {
        if (bone->inheritanceFlag == 1) {
            CTRLBuildMatrix(&bone->orientationCtrl, m);
            PSMTXConcat(parent, m, world);
            PSMTXInverse(world, bone->orientationInvMtx);
        } else {
            CTRLBuildInverseMatrix(&bone->orientationCtrl, bone->orientationInvMtx);
        }
        if (bone->branch.Children != NULL) {
            BuildBoneSkinOrientationMatrix((ObjBone*)bone->branch.Children, world);
        }
    }
}

// Differs: registers only (the size sums in r25-r29 swapped) and the order of the skin and
// cursor stores in GetDisplayObj; the frame matches with the local ObjActor.
// .text:0x800232E0 size:0x32C
ObjActor* f_InitActorWithLayout(ObjLayout* layout, u8* mem) {
    ObjActor* actor;
    u32 boneArraySize;
    u32 forwardSize;
    u32 skinSize;
    u32 invTransposeSize;
    u32 orientSize;
    u16 boneCount;
    u32 size;
    u8* bones;
    ObjActor header;
    Mtx m;
    // the skin pointer lives in a whole local actor, as the original's frame shows
    ObjDisplay** skin = &header.skinObject;

    skinSize = 0;
    invTransposeSize = 0;
    orientSize = 0;
    boneCount = 0;
    boneArraySize = ALIGN32(layout->totalBones * sizeof(ObjBone*));
    forwardSize = ALIGN32(layout->totalBones * sizeof(Mtx));
    if (layout->skinFileID != 0xFFFF) {
        mem = GetDisplayObj(skin, layout->pal, layout->skinFileID, mem);
        size = ALIGN32(layout->totalBones * sizeof(Mtx));
        skinSize = size;
        invTransposeSize = size;
        if ((*skin)->lightingData != NULL) {
            orientSize = size;
        }
    }
    actor = (ObjActor*)mem;
    mem += ALIGN32(boneArraySize + forwardSize + skinSize + invTransposeSize + orientSize + ALIGN32(layout->totalBones * sizeof(ObjBone)) + sizeof(ObjActor));
    actor->boneArray = (ObjBone**)(actor + 1);
    actor->forwardMtxArray = (MtxPtr)((u8*)actor->boneArray + boneArraySize);
    actor->skinObject = *skin;
    actor->skHeader = NULL;
    PSMTXIdentity(m);
    actor->actorID = layout->actorID;
    actor->layout = layout;
    actor->totalBones = layout->totalBones;
    DSInitTree(&actor->hierarchy, (Ptr)(ObjBone*)NULL, &((ObjBone*)NULL)->branch);
    DSInitList(&actor->drawPriorityList, (Ptr)(ObjBone*)NULL, &((ObjBone*)NULL)->drawPriorityLink);
    actor->pal = NULL;
    if (layout->pal != NULL) {
        actor->pal = layout->pal;
    }
    if (layout->skinFileID != 0xFFFF) {
        DOSetWorldMatrix(actor->skinObject, m);
        actor->skinMtxArray = (MtxPtr)((u8*)actor->forwardMtxArray + forwardSize);
        actor->orientationInvMtxArray = (MtxPtr)((u8*)actor->skinMtxArray + skinSize);
        {
            PositionData* pos = actor->skinObject->positionData;
            ObjPalette* pal = layout->pal;
            s32 diff = (u32)actor->skinObject->lightingData->normalArray - (u32)pos->positionArray;
            ObjDescriptor* desc = pal->descriptorArray;
            u32 i;

            for (i = 0; i < pal->numDescriptors; i++, desc++) {
                PositionData* p = desc->layout->positionData;
                if (p->compCount == 6) {
                    char* array = p->positionArray;
                    pos->positionArray = array;
                    actor->skinObject->lightingData->normalArray = array + diff;
                    break;
                }
            }
        }
        if (actor->skinObject->lightingData != NULL) {
            actor->skinInvTransposeMtxArray = (MtxPtr)((u8*)actor->orientationInvMtxArray + invTransposeSize);
        } else {
            actor->skinInvTransposeMtxArray = NULL;
        }
    } else {
        actor->skinObject = NULL;
        actor->skinMtxArray = NULL;
        actor->orientationInvMtxArray = NULL;
        actor->skinInvTransposeMtxArray = NULL;
    }
    bones = (u8*)actor->forwardMtxArray + (forwardSize + skinSize + invTransposeSize + orientSize);
    actor->worldControl.type = 0;
    if (layout->hierarchy.Root != NULL) {
        f_InitBone(NULL, (ObjLayoutBone*)layout->hierarchy.Root, actor, &boneCount, bones, mem);
    }
    if (boneCount != actor->totalBones) {
        OSPanic("objinit.c", 521, "Incorrect number of bones in actor");
    }
    if (actor->skinObject != NULL) {
        BuildBoneSkinOrientationMatrix((ObjBone*)actor->hierarchy.Root, m);
    }
    ACTSort(actor);
    actor->_80 = 0;
    actor->_82 = 0;
    actor->_84 = 0;
    actor->_88 = 0;
    actor->_8C = 1.0f;
    actor->_90 = 0.0f;
    actor->_99 = 0;
    actor->_98 = 0;
    actor->_94 = 0;
    return actor;
}

// .text:0x80023078 size:0x268
u8* fn_80023078(ObjDisplay* obj, ObjDisplayLayout* layout, u8* mem) {
    u8** heap = &mem;
    u16 i;
    u32 n;

    if (layout->positionData != NULL) {
        obj->positionData = ObjAlloc(heap, 0x20);
        *obj->positionData = *layout->positionData;
    } else {
        obj->positionData = NULL;
    }
    if (layout->colorData != NULL) {
        obj->colorData = ObjAlloc(heap, 0x20);
        *obj->colorData = *layout->colorData;
    } else {
        obj->colorData = NULL;
    }
    if (layout->textureData != NULL && layout->numTextureChannels != 0) {
        obj->textureData = (TextureData*)*heap;
        n = layout->numTextureChannels;
        obj->numTextureChannels = n;
        *heap += ALIGN32(n * sizeof(TextureData));
        for (i = 0; i < layout->numTextureChannels; i++) {
            obj->textureData[i] = layout->textureData[i];
        }
    } else {
        obj->textureData = NULL;
        obj->numTextureChannels = 0;
    }
    if (layout->lightingData != NULL) {
        obj->lightingData = ObjAlloc(heap, 0x20);
        *obj->lightingData = *layout->lightingData;
    } else {
        obj->lightingData = NULL;
    }
    if (layout->displayData != NULL) {
        obj->displayData = ObjAlloc(heap, 0x20);
        *obj->displayData = *layout->displayData;
    } else {
        obj->displayData = NULL;
    }
    obj->visibility = 1;
    PSMTXIdentity(obj->worldMatrix);
    obj->shaderFunc = NULL;
    obj->shaderData = NULL;
    obj->_15 = layout->_15;
    memcpy(obj->_58, layout->_20, 4);
    memcpy(obj->_54, layout->_1C, 4);
    memcpy(obj->_60, layout->_28, 4);
    memcpy(obj->_5C, layout->_24, 4);
    memcpy(obj->_68, layout->_30, 4);
    memcpy(obj->_64, layout->_2C, 4);
    return mem;
}

// .text:0x80022DAC size:0x2CC
u8* f_InitBone(ObjBone* parent, ObjLayoutBone* lbone, ObjActor* actor, u16* count, u8* bones, u8* mem) {
    ObjBone* bone;

    for (; lbone != NULL; lbone = (ObjLayoutBone*)lbone->branch.Next) {
        bone = (ObjBone*)(bones + *count * sizeof(ObjBone));
        bone->branch.Children = NULL;
        DSInsertBranchBelow(&actor->hierarchy, (Ptr)parent, (Ptr)bone);
        actor->boneArray[*count] = bone;
        bone->boneID = lbone->boneID;
        bone->inheritanceFlag = lbone->inheritanceFlag;
        bone->drawingPriority = lbone->drawingPriority;
        bone->orientationCtrl.type = 0;
        if (lbone->orientationCtrl != NULL) {
            bone->orientationCtrl = *lbone->orientationCtrl;
        }
        bone->dispObj = NULL;
        if (lbone->geoFileID != 0xFFFF) {
            mem = GetDisplayObj(&bone->dispObj, actor->pal, lbone->geoFileID, mem);
        }
        bone->_18 = bone->dispObj;
        bone->anim = NULL;
        bone->animCtrl.type = 0;
        bone->_A4.type = 0;
        bone->anim = (ObjBoneAnim*)mem;
        mem += 0x20;
        bone->anim->_00 = 0.0f;
        bone->anim->_04 = 0.0f;
        bone->anim->_08 = 1.0f;
        bone->anim->_0C = NULL;
        bone->anim->_10 = NULL;
        bone->anim->_16 = 0;
        bone->anim->_17 = 1;
        bone->anim->_18 = 1;
        bone->anim->_14 = 0;
        bone->_134 = 1;
        bone->_136 = 0;
        bone->_137 = 0;
        bone->forwardMtx = (MtxPtr)((u8*)actor->forwardMtxArray + *count * sizeof(Mtx));
        PSMTXIdentity(bone->forwardMtx);
        if (actor->skinObject != NULL) {
            bone->skinMtx = (MtxPtr)((u8*)actor->skinMtxArray + *count * sizeof(Mtx));
            PSMTXIdentity(bone->skinMtx);
            bone->orientationInvMtx = (MtxPtr)((u8*)actor->orientationInvMtxArray + *count * sizeof(Mtx));
            PSMTXIdentity(bone->orientationInvMtx);
            if (actor->skinObject->lightingData != NULL) {
                bone->skinInvTransposeMtx = (MtxPtr)((u8*)actor->skinInvTransposeMtxArray + *count * sizeof(Mtx));
                PSMTXIdentity(bone->skinInvTransposeMtx);
            } else {
                bone->skinInvTransposeMtx = NULL;
            }
        } else {
            bone->skinMtx = NULL;
            bone->orientationInvMtx = NULL;
            bone->skinInvTransposeMtx = NULL;
        }
        (*count)++;
        if (lbone->branch.Children != NULL) {
            mem = f_InitBone(bone, (ObjLayoutBone*)lbone->branch.Children, actor, count, bones, mem);
        }
    }
    return mem;
}
