#ifndef __STATIC_PARTICLE_H_
#define __STATIC_PARTICLE_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "Dolphin/gx.h"

struct Emitter;
struct Particle;
struct ZSortEntry;
struct TexFile;
struct EffectParams;

BOOL fn_80026E58(void* e);
void fn_80027300(struct Emitter* e, Vec* pos, Vec* dir, struct EffectParams* params, f32 scale);
void fn_80027674(Vec* pos, Vec* dir, struct EffectParams* params, f32 scale, u8 id);
void fn_80027918(u8 id, f32 v);
void fn_8002852C(void);
BOOL fn_80028F48(void* e);
void fn_8002955C(Vec* pos, s32 arg1, struct EffectParams* params);
void fn_800297F0(struct Emitter* e, Vec* pos, s32 arg1, struct EffectParams* params);
void fn_8002BC84(struct Emitter* e, Vec* pos, Vec* dir, struct EffectParams* params);
void fn_8002A1CC(Vec* pos, Vec* dir);
void fn_8002C2D0(Vec* pos, Vec* dir, struct EffectParams* params);
void fn_8002CDD0(Vec* pos);
void fn_8002DC68(Vec* pos);
BOOL fn_8002F1AC(Vec* pos, s32 key);
void fn_8002FDB8(struct Emitter* e, Vec* pos, Vec* dir, Vec* back, struct EffectParams* params);
void fn_80030470(Vec* pos, Vec* dir, Vec* back, struct EffectParams* params, s32 id);
void fn_80030720(struct Emitter* e, Vec* pos, s32 arg1, struct EffectParams* params);
void fn_80030D88(Vec* pos, s32 arg1, struct EffectParams* params, s32 id);
BOOL fn_8002E3DC(void* e);
BOOL fn_8002E828(void* e);
BOOL fn_80031034(void* e);
void fn_800317C4(struct Emitter* e, Vec* pos, struct EffectParams* params);
void fn_80031CA4(Vec* pos, struct EffectParams* params);
struct Particle* fn_80031F34(struct Particle* list, s32 n);
s32 fn_80032038(struct ZSortEntry* a, struct ZSortEntry* b);
void fn_80032064(Vec* pos, Vec* dir);
void fn_80032284(Vec* pos);
void fn_800324EC(u16 joint, s32 player, s32 other, Vec* dir);
BOOL fn_800328E0(void* e);
void fn_800330CC(s32 n, u32 arg1, Vec* start, Vec* end, f32 arg4, s32 arg5, s32 arg6, f32 arg7);
f32 fn_800335BC(s32 angle);
f32 fn_800335EC(s32 angle);
void fn_80033620(struct Emitter* e);
void fn_80033794(struct Particle* list);
struct Emitter* fn_800337CC(struct Emitter* e, s32 n, BOOL all);
void pitchingMachinePitching(u8 id);
BOOL fn_80033928(u8 id);
void fn_80033964(struct Emitter* e);
struct Emitter* fn_800339F0(struct Emitter* e, u8 id);
struct Emitter* fn_80033A24(BOOL (*update)(void*), u8 priority, s32 kind, s32 n, BOOL all, u8 id);
void fn_80033B58(struct TexFile* file, s32 index, GXTexWrapMode wrapS, GXTexWrapMode wrapT);
void fn_80033F64(f32 w, f32 h, f32 angle);
void fn_8003403C(f32 w, f32 h);
void fn_800340F4(Mtx m);
void fn_80034120(Mtx m);
void fn_8003414C(Mtx m);
void minigamesSetSomePointers(void);
void minigamesSetSomePointers2(void);

#endif // !__STATIC_PARTICLE_H_
