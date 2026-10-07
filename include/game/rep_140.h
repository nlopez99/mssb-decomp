#ifndef __GAME_rep_140_H_
#define __GAME_rep_140_H_

#include "mssbTypes.h"
#include "game/UnknownHomes_Game.h"

struct VecRing;

f32 fn_3_14A4(f32 frame, const f32* timings, const f32* values, const f32* curvature, int keyCount);
void fn_3_155C(f32* timings, f32* values, f32* curve, int count);
void fn_3_19B0(f32 distance, VecXZ* out, const f32* valuesX, const f32* valuesZ, const f32* endLengths,
               const f32* curvatureX, const f32* curvatureZ, int keyCount);
void fn_3_1B24(f32* valuesX, f32* valuesZ, f32* timings, f32* curveX, f32* curveZ, int count);
void running_roundBasePosition(f32 frame, VecXZ* outPos, VecXZ* points, int count);
void fn_3_28E4(Vec* out, Vec* points, int count, f32 distance);
void fn_3_2D6C(Vec* out, struct VecRing* ring, int outCount);
void fn_3_310C(Vec* out, Vec* points, int count, int outCount);

#endif // !__GAME_rep_140_H_
