#ifndef __STATIC_PHYSICS_H_
#define __STATIC_PHYSICS_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

s32 fn_80037054(struct RigidBody* body, struct PhysEnv* env);
s32 fn_8003731C(struct RigidBody* body, struct PhysEnv* env);
void fn_80037768(struct RigidBody* body, s32 axis, s32 steps, f32 length, f32 center, f32 radius, f32 mass);
void fn_80037964(void);
void fn_80037984(void);
void fn_80037AA0(struct RigidBody* body, s32 fielder, void (*callback)(s32), u16 bone, void* anim);
void fn_80037B18(struct RigidBody* body, Vec* force, f32 scale);
s32 fn_80037BAC(struct RigidBody* body);
void fn_8003819C(struct RigidBody* body);
MtxPtr fn_800383BC(struct RigidBody* body);
void fn_80038418(struct RigidBody* body, Vec* pos, Quaternion* rot, Vec* prevPos, Quaternion* prevRot);
void fn_800385F0(struct RigidBody* body, f32 length, f32 center, f32 radius, f32 mass);
void fn_800387B0(struct RopeParams* params, struct RopeNode* nodes, s32 count, Vec* force);
void fn_80038B48(struct RopeParams* params, struct RopeNode* nodes, s32 count, Vec* force);
struct RopeNode* fn_80038CD0(s32 count, struct RopeParams* params, struct RopeNode* nodes, f32 height, f32 mass);
void fn_80038E2C(struct RopeParams* params);
void fn_80038EC4(struct PhysActor* actor, struct PhysModel** ref, s32 index);
void fn_80038F08(struct PhysActor* actor, struct PhysModel* model, u8 index);
void fn_80039310(struct PhysState* st, f32 floor, f32 restEnergy);
void fn_80039A4C(void);

#endif // !__STATIC_PHYSICS_H_
