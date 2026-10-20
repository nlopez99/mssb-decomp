#ifndef __STATIC_SUB_H_
#define __STATIC_SUB_H_

#include "mssbTypes.h"
#include "static/UnknownHomes_Static.h"

void fn_80024390(camera_803c639c_s* camera, f32* p, s32 type);
void fn_800245EC(camera_803c639c_s* camera, Mtx view, Vec* points, f32* out, s32 count, s32 arg5);
void fn_800246D4(int (*compare)(const void*, const void*), void* src, void* dst, int size, int count);
s32 fn_800247E4(s32 x, s32 y, s32 width, s32 bytes);
int challengeStarRelatedInd(int character, int mission);
int multBottomBits_asFloat(int color, int factor);
int byteWiseMultiply(int value, int factors);
int LERPToNewRange_Float(int value, int inMin, int inMax, int outMin, int outMax);
f32 LinearInterpolateToNewRange(f32 value, f32 prevMin, f32 prevMax, f32 nextMin, f32 nextMax);

#endif // !__STATIC_SUB_H_
