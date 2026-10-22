#ifndef _C3_ACTORANIM_H_
#define _C3_ACTORANIM_H_

#include "C3/charPipeline.h"

f32 fn_800B4A44(Actor *actor, u16 boneIndex);
f32 fn_800B4A94(Actor *actor);
void fn_800B4AFC(Actor *actor, u8 value);
void AnimateActorBones(Actor *actor);
void fn_800B4BC8(Actor *actor, u8 value);
void fn_800B4C04(Actor *actor, f32 speed);
f32 fn_800B4C40(Actor *actor);
void fn_800B4CA0(Actor *actor, f32 time);
void fn_800B4CDC(Actor *actor);

#endif // _C3_ACTORANIM_H_
