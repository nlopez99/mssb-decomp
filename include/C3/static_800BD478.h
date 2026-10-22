#ifndef _C3_STATIC_800BD478_H_
#define _C3_STATIC_800BD478_H_

#include "C3/charPipeline.h"

typedef struct ActorLayoutBones {
    /* 0x00 */ ActorLayout layout;
    /* 0x20 */ ActorBone bones[1];
} ActorLayoutBones;

// This game's actor: the SDK's with more fields after it
typedef struct ActorEx {
    /* 0x00 */ u8 _00[0x99];
    /* 0x99 */ u8 _99;
} ActorEx;

typedef struct ActorAnimState {
    /* 0x00 */ Actor* actor;
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ Control control;
    /* 0x54 */ u8 _54[0x64 - 0x54];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u16 _66;
} ActorAnimState;

typedef struct ActorSlot {
    /* 0x00 */ ActorEx* actor;
    /* 0x04 */ u32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s16 _0C;
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11[0x54 - 0x11];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u16 _64;
    /* 0x66 */ u16 _66;
    /* 0x68 */ s32 _68;
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D;
    /* 0x70 */ s32 _70[8];
} ActorSlot; // size: 0x90

typedef struct ActorGroup {
    /* 0x00 */ u16 count;
    /* 0x02 */ u8 _02[2];
    /* 0x04 */ Mtx mtx;
    /* 0x34 */ ActorSlot slots[1];
} ActorGroup;

void fn_800BD478(Actor** actor, ActorLayoutBones* layout);
void fn_800BD548(void);
void fn_800BD670(void);
void fn_800BD8C4(void);
void fn_800BDA24(ActorAnimState* state);
void fn_800BDA94(void);
void fn_800BDC88(ActorGroup* group, u16 index, s16 arg2, s32 arg3, u32 arg4, s32 arg5);
ActorGroup* ActorObjectInitTable(u16 count);

#endif // _C3_STATIC_800BD478_H_
