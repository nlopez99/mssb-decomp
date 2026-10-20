#ifndef __STATIC_OBJINIT_H_
#define __STATIC_OBJINIT_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

u8* f_InitBone(struct ObjBone* parent, struct ObjLayoutBone* lbone, struct ObjActor* actor, u16* count, u8* bones, u8* mem);
u8* fn_80023078(struct ObjDisplay* obj, struct ObjDisplayLayout* layout, u8* mem);
struct ObjActor* f_InitActorWithLayout(struct ObjLayout* layout, u8* mem);
void BuildBoneSkinOrientationMatrix(struct ObjBone* bone, MtxPtr parent);
void fn_800238E0(struct ObjGroup* group, u16 slot, s16 id, struct ObjLayout* layout);
void fn_8002399C(struct ObjInst* inst, u16 slot, s16 id, struct ObjLayout* layout, void* anim, void* skin);
void* fn_80023AA4(void);
void fn_80023B04(s32 count);

// Defined in units not yet split
void* _OSAllocFromHeap(u32 align, u32 size);
void* ActorObjectInitTable(s32 count);
void fn_800B4724(struct ObjActor* actor, void* skin);
void DOSetWorldMatrix(struct ObjDisplay* obj, MtxPtr m);
void ACTSort(struct ObjActor* actor);

#endif // !__STATIC_OBJINIT_H_
