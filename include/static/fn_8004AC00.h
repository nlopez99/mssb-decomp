#ifndef __STATIC_FN_8004AC00_H_
#define __STATIC_FN_8004AC00_H_

#include "mssbTypes.h"

typedef void (*EffectHandler)(void* actor, s32 a, s32 b, f32 t);

void fn_8004AC00(void* actor, s32 a, s32 b, f32 t);
s32 fn_8004ACC4(s32 clear);
s32 fn_8004ACDC(s32 clear);
void fn_8004ACF4(void* actor, s32 a, s32 b, f32 t);
s32 fn_8004AD54(s32 stadium, s32 flags);
void fn_8004AE18(s32 player);
void fn_8004AFA8(s32 player);
void fn_8004B1B8(s32 v);
void fn_8004B1C0(s32 kind, void* actor, s32 a, s32 b, f32 t);
void fn_8004B208(void* actor, s32 action, s32 b, f32 t);
void fn_8004B270(void);

// Handlers in units not set up yet
void fn_8004C5F8(void* actor, s32 a, s32 b, f32 t);
void fn_80062C60(void* actor, s32 a, s32 b, f32 t);
void fn_80062E6C(void* actor, s32 a, s32 b, f32 t);
void fn_8006C3F8(void* actor, s32 a, s32 b, f32 t);
void fn_8006C444(void* actor, s32 a, s32 b, f32 t);

#endif
