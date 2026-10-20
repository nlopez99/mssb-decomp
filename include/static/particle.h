#ifndef __STATIC_PARTICLE_H_
#define __STATIC_PARTICLE_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct Emitter;
struct Particle;
struct ZSortEntry;

void fn_80027918(u8 id, f32 v);
void fn_8002852C(void);
void fn_8002CDD0(Vec* pos);
void fn_8002DC68(Vec* pos);
BOOL fn_8002F1AC(Vec* pos, s32 key);
struct Particle* fn_80031F34(struct Particle* list, s32 n);
s32 fn_80032038(struct ZSortEntry* a, struct ZSortEntry* b);
f32 fn_800335BC(s32 angle);
f32 fn_800335EC(s32 angle);
void fn_80033794(struct Particle* list);
struct Emitter* fn_800337CC(struct Emitter* e, s32 n, BOOL all);
void pitchingMachinePitching(u8 id);
BOOL fn_80033928(u8 id);
void fn_80033964(struct Emitter* e);
struct Emitter* fn_800339F0(struct Emitter* e, u8 id);
struct Emitter* fn_80033A24(BOOL (*update)(void*), u8 priority, s32 kind, s32 n, BOOL all, u8 id);
void fn_80033F64(f32 w, f32 h, f32 angle);
void fn_8003403C(f32 w, f32 h);
void fn_800340F4(Mtx m);
void fn_80034120(Mtx m);
void fn_8003414C(Mtx m);
void minigamesSetSomePointers(void);
void minigamesSetSomePointers2(void);

#endif // !__STATIC_PARTICLE_H_
