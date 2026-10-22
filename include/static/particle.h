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
struct SparkParticle;
struct GlowParticle;
struct FlareParams;
struct SparkParams;
struct SmokeParams;
struct PuffParams;
struct StreakParams;

// What fn_8002CE4C's callers pass
typedef struct ArcParams {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 tex;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 delay;
    /* 0x10 */ s32 frames;
    /* 0x14 */ s32 rise[2];
    /* 0x1C */ s32 split[2];
    /* 0x24 */ s32 hold[2];
    /* 0x2C */ s32 fade[2];
    /* 0x34 */ s32 size[2];
    /* 0x3C */ s32 yaw[2];
    /* 0x44 */ s32 pitch[2];
    /* 0x4C */ s32 vel[2];
    /* 0x54 */ s32 angle[2];
    /* 0x5C */ s32 spin[2];
    /* 0x64 */ s32 velScale[2];
    /* 0x6C */ s32 velScaleEnd[2];
    /* 0x74 */ s32 posScale[2];
    /* 0x7C */ s32 dist[2];
} ArcParams; // size: 0x84

// What fn_80028628's callers pass
typedef struct RibbonParams {
    /* 0x00 */ void* file;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 len;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32 _34;
    /* 0x38 */ s32 _38;
    /* 0x3C */ s32 _3C;
    /* 0x40 */ s32 _40;
    /* 0x44 */ s32 _44;
} RibbonParams; // size: 0x48

typedef struct RibbonPoint {
    /* 0x0 */ u16 color;
    /* 0x2 */ u16 x;
    /* 0x4 */ u16 y;
    /* 0x6 */ u16 z;
} RibbonPoint;

typedef struct RibbonShape {
    /* 0x0 */ u16 is3D : 1;
    /* 0x0 */ u16 count : 15;
    /* 0x2 */ u16 w;
    /* 0x4 */ u16 h;
    /* 0x6 */ u16 d;
    /* 0x8 */ RibbonPoint pts[1];
} RibbonShape;

// What fn_8002DCE4's callers pass
typedef struct DriftParams {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 tex;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 life;
    /* 0x10 */ s32 size[2];
    /* 0x18 */ s32 speed;
    /* 0x1C */ s32 delay;
    /* 0x20 */ s32 lifeVar;
    /* 0x24 */ s32 yaw[2];
    /* 0x2C */ s32 pitch[2];
    /* 0x34 */ s32 fadeAge;
    /* 0x38 */ s32 _38[2];
    /* 0x40 */ s32 angle[2];
} DriftParams; // size: 0x48

BOOL fn_800263FC(void* e);
void fn_80026998(struct SmokeParams* params);
BOOL fn_80026E58(void* e);
void fn_80027300(struct Emitter* e, Vec* pos, Vec* dir, struct EffectParams* params, f32 scale);
void fn_80027674(Vec* pos, Vec* dir, struct EffectParams* params, f32 scale, u8 id);
void fn_80027918(u8 id, f32 v);
BOOL fn_80027968(void* e);
void fn_8002852C(void);
void fn_80028628(Vec* start, Vec* end, RibbonParams* params, RibbonShape* shape, u32* colors, void* arg5, BOOL flash);
BOOL fn_80028F48(void* e);
void fn_8002955C(Vec* pos, Vec* dir, struct PuffParams* params);
void fn_800297F0(struct Emitter* e, Vec* pos, Vec* dir, struct PuffParams* params);
BOOL fn_80029CC8(void* e);
void fn_8002BC84(struct Emitter* e, Vec* pos, Vec* dir, struct EffectParams* params);
void fn_8002A1CC(Vec* pos, struct StreakParams* params);
u8 fn_8002A85C(struct Emitter* e, struct GlowParticle* p);
u8 fn_8002AC68(struct Emitter* e, struct SparkParticle* p);
BOOL fn_8002B014(struct Emitter* e);
void fn_8002B400(struct Emitter* e, struct SparkParams* params, Vec* pos);
void fn_8002B7F8(Vec* pos, struct SparkParams* params, u8 glow);
void fn_8002C2D0(Vec* pos, Vec* dir, struct EffectParams* params);
BOOL fn_8002C56C(void* e);
void fn_8002CE4C(Vec* start, Vec* end, ArcParams* params);
void fn_8002CDD0(Vec* pos);
BOOL fn_8002D82C(void* e);
void fn_8002DC68(Vec* pos);
void fn_8002DCE4(Vec* start, Vec* end, DriftParams* params);
BOOL fn_8002F1AC(Vec* pos, s32 key);
BOOL fn_8002ECA0(void* e);
void fn_8002F258(Vec* pos, s32 id, struct FlareParams* params);
void fn_8002F5F4(Vec* pos, Vec* dir, struct EffectParams* params);
BOOL fn_8002F9FC(void* e);
void fn_8002FDB8(struct Emitter* e, Vec* pos, Vec* dir, Vec* back, struct EffectParams* params);
void fn_80030470(Vec* pos, Vec* dir, Vec* back, struct EffectParams* params, s32 id);
void fn_80030720(struct Emitter* e, Vec* pos, Vec* dir, struct EffectParams* params);
void fn_80030D88(Vec* pos, Vec* dir, struct EffectParams* params, s32 id);
BOOL fn_8002E3DC(void* e);
BOOL fn_8002E828(void* e);
BOOL fn_80031034(void* e);
void fn_800317C4(struct Emitter* e, Vec* pos, struct EffectParams* params);
void fn_80031CA4(Vec* pos, struct EffectParams* params);
struct Particle* fn_80031F34(struct Particle* list, s32 n);
s32 fn_80032038(struct ZSortEntry* a, struct ZSortEntry* b);
void fn_80032064(Vec* pos, struct StreakParams* dir);
void fn_80032284(Vec* pos);
void fn_800324EC(u16 joint, s32 player, s32 other, struct StreakParams* dir);
BOOL fn_800328E0(void* e);
void fn_800330CC(s32 n, u32 arg1, Vec* start, Vec* end, f32 arg4, s32 arg5, s32 arg6, f32 arg7);
void fn_800332B8(Vec* dirIn, Vec* out, f32 yawMin, f32 yawMax, f32 pitchMin, f32 pitchMax);
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
void fn_80033CC8(struct Particle* p, struct TexFile* file);
void fn_80033F64(f32 w, f32 h, f32 angle);
void fn_8003403C(f32 w, f32 h);
void fn_800340F4(Mtx m);
void fn_80034120(Mtx m);
void fn_8003414C(Mtx m);
void minigamesSetSomePointers(void);
void minigamesSetSomePointers2(void);

#endif // !__STATIC_PARTICLE_H_
