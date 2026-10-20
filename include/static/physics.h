#ifndef __STATIC_PHYSICS_H_
#define __STATIC_PHYSICS_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

void fn_80037054(void);
void fn_8003731C(void);
void fn_80037768(struct RigidBody* body, s32 axis, s32 steps, f32 length, f32 center, f32 radius, f32 mass);
void fn_80037964(void);
void fn_80037984(void);
void fn_80037AA0(struct RigidBody* body, s32 fielder, void (*callback)(s32), u16 bone, void* anim);
void fn_80037B18(struct RigidBody* body, Vec* force, f32 scale);
void fn_80037BAC(void);
void fn_8003819C(void);
MtxPtr fn_800383BC(struct RigidBody* body);
void fn_80038418(struct RigidBody* body, Vec* pos, Quaternion* rot, Vec* prevPos, Quaternion* prevRot);
void fn_800385F0(struct RigidBody* body, f32 length, f32 center, f32 radius, f32 mass);
void fn_800387B0(void);
void fn_80038B48(void);
void fn_80038CD0(void);
void fn_80038E2C(struct RopeParams* params);
void fn_80038EC4(void);
void fn_80038F08(void);
void fn_80039310(void);
void fn_80039A4C(void);

#endif // !__STATIC_PHYSICS_H_
