#ifndef _C3_ACT_H_
#define _C3_ACT_H_

#include "C3/charPipeline.h"

void fn_800B2AC8(ActorLayout *layout);
void fn_800B2B4C(Actor *actor, f32 value);
void fn_800B2B54(Actor *actor, u16 boneIndex, u8 value);
void Set_FUN_800b2b6c(Actor *actor, u16 *value);
void fn_800B2B74(Actor *actor, u16 boneIndex);
struct DODisplayObj *fn_800B2BA8(Actor *actor, u16 boneIndex, Actor *src, u16 srcIndex);
void fn_800B2BE4(Actor *actor, u16 boneIndex);
void fn_800B2BFC(Actor *actor, u16 a, u16 b);
void fn_800B2C08(Actor *actor, u16 value);
void fn_800B2C10(Actor *actor, u16 boneIndex, Vec *v);
void fn_800B2C44(Actor *actor, u16 boneIndex, Vec *v);
void fn_800B2C88(Actor *actor, u16 boneIndex, Mtx m);
void fn_800B2D5C(Actor *actor);
void fn_800B2DD0(Actor *actor, sBone *bone);
void fn_800B313C(Actor *actor);
void fn_800B34B4(Actor *actor, sBone *bone, MtxPtr parentMtx);
void f_BuildBoneSkinOrientationMatrix(sBone *bone, MtxPtr parent);
void fn_800B3A78(Actor *actor, MtxPtr camera, u8 numLights, ...);
u8 fn_800B3C04(s32 arg, Actor *actor, Mtx camera);
void fn_800B3F20(Actor *actor);
BOOL fn_800B4048(Actor **actor, ActorLayout *layout, u16 actorID);
void fn_800B4084(sBone *parent, ActorBone *layoutBone, Actor *actor, u16 *index, sBone *boneMem);
void fn_800B4278(Actor *actor);
Actor *fn_800B43A0(ActorLayout *layout);
void fn_800B4724(Actor *actor, sHdr *skHeader);
void fn_800B472C(struct ActorDraw *draw);
void haveActLayoutPointToGeoHeader(ActorLayout *layout, char *geoPalette);
void LoadActorLayout(ActorLayout *layout);
void fn_800B49E4(ActorLayout *layout);

#endif // _C3_ACT_H_
