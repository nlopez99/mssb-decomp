#include "static/particle.h"
#include "static/sub.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "math.h"
#include "Dolphin/rand.h"

typedef struct Particle {
    /* 0x00 */ struct Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ u8 _24[0x14];
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    union {
        /* 0x40 */ s32 _40;
        /* 0x40 */ u8 color[4];
    };
    /* 0x44 */ u8 _44[0x4];
    /* 0x48 */ s16 _48;
    /* 0x4A */ s16 _4A;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 _4F;
    /* 0x50 */ u8 _50[0x10];
} Particle; // size: 0x60

typedef struct Emitter {
    /* 0x00 */ struct Emitter* prev;
    /* 0x04 */ struct Emitter* next;
    /* 0x08 */ BOOL (*update)(void* e);
    /* 0x0C */ Particle* particles;
    /* 0x10 */ s32 _10;
    /* 0x14 */ u16 _14_hi : 4;
    /* 0x14 */ u16 count : 12;
    /* 0x16 */ u8 priority;
    /* 0x17 */ u8 _17_hi : 1;
    /* 0x17 */ u8 id : 7;
    union {
        /* 0x18 */ Vec _18;
        /* 0x18 */ u8 state;
        struct {
            /* 0x18 */ struct Particle* list;
            /* 0x1C */ u16 count;
        } glow;
    };
    /* 0x24 */ Vec _24;
    union {
        /* 0x30 */ Vec _30;
        /* 0x30 */ s32 fadeAge;
    };
    /* 0x3C */ u8 _3C[0x4];
    /* 0x40 */ u16 _40;
    /* 0x42 */ u8 _42[0x1E];
} Emitter; // size: 0x60

typedef struct TexFile {
    /* 0x0 */ u32 count;
    /* 0x4 */ TextureDesc tex[1];
} TexFile;

typedef struct EffectParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 _0C[13];
    /* 0x40 */ s32 _40;
    /* 0x44 */ s32 _44;
    /* 0x48 */ s32 _48;
    /* 0x4C */ s32 _4C;
} EffectParams; // size: 0x50

typedef struct FlareParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18[8];
    /* 0x38 */ s32 r;
    /* 0x3C */ s32 g;
    /* 0x40 */ s32 b;
} FlareParams; // size: 0x44

typedef struct ZSortEntry {
    /* 0x0 */ Particle* p;
    /* 0x4 */ f32 z;
} ZSortEntry; // size: 0x8

// The fields fn_800330CC's emitters add after the common header
typedef struct ArcEmitter {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s32 _10;
    /* 0x14 */ u8 _14[0x4];
    /* 0x18 */ Vec start;
    /* 0x24 */ Vec end;
    /* 0x30 */ f32 _30;
    /* 0x34 */ s32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ u32 _40;
    /* 0x44 */ f32 _44;
} ArcEmitter;

// The particles fn_8002AC68 draws
typedef struct SparkParticle {
    /* 0x00 */ Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ f32 growA;
    /* 0x14 */ f32 growB;
    /* 0x18 */ s16 fadeA;
    /* 0x1A */ s16 fadeB;
    /* 0x1C */ s16 switchAge;
    /* 0x1E */ s16 life;
    /* 0x20 */ u8 _20[0x38 - 0x20];
    /* 0x38 */ f32 w;
    /* 0x3C */ f32 h;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 remaining;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 tex;
    /* 0x4E */ u8 texCoord;
} SparkParticle;

// The particles fn_8002A85C draws
typedef struct GlowParticle {
    /* 0x00 */ Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ f32 growHA;
    /* 0x14 */ f32 growHB;
    /* 0x18 */ f32 growWA;
    /* 0x1C */ f32 growWB;
    /* 0x20 */ s16 fadeA;
    /* 0x22 */ s16 fadeB;
    /* 0x24 */ s16 switchAge;
    /* 0x26 */ s16 life;
    /* 0x28 */ u8 _28[0x38 - 0x28];
    /* 0x38 */ f32 w;
    /* 0x3C */ f32 h;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 remaining;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 tex;
    /* 0x4E */ u8 texCoord;
} GlowParticle;

// The particles fn_8002D82C moves and draws
typedef struct DriftParticle {
    /* 0x00 */ Particle* next;
    /* 0x04 */ f32 pos[3];
    /* 0x10 */ f32 vel[3];
    /* 0x1C */ f32 accel[3];
    /* 0x28 */ f32 force[3];
    /* 0x34 */ f32 mass;
    /* 0x38 */ f32 w;
    /* 0x3C */ f32 h;
    union {
        /* 0x40 */ u32 rgba;
        /* 0x40 */ u8 color[4];
    };
    /* 0x44 */ s8 dcolor[4];
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 remaining;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 tex;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 texCoords;
} DriftParticle;

// The particles fn_800317C4 starts
typedef struct SwirlParticle {
    /* 0x00 */ Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ f32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ s32 rgba;
    /* 0x44 */ u8 _44;
    /* 0x45 */ u8 _45[0x48 - 0x45];
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 remaining;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 tex;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 _4F;
} SwirlParticle;

// What fn_8002A1CC's callers pass
typedef struct StreakParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 tex;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 undelayed;
    /* 0x10 */ s32 delay;
    /* 0x14 */ s32 life[2];
    /* 0x1C */ s32 speed[2];
    /* 0x24 */ s32 accel[2];
    /* 0x2C */ s32 width[2];
    /* 0x34 */ s32 length[2];
    /* 0x3C */ s32 widthEnd[2];
    /* 0x44 */ s32 lengthEnd[2];
    /* 0x4C */ u32 rgba;
} StreakParams; // size: 0x50

// The particles fn_80029CC8 draws as streaks toward the emitter's point
typedef struct StreakParticle {
    /* 0x00 */ Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ Vec accel;
    /* 0x28 */ f32 width;
    /* 0x2C */ f32 length;
    /* 0x30 */ f32 dwidth;
    /* 0x34 */ f32 dlength;
    /* 0x38 */ u8 _38[0x40 - 0x38];
    union {
        /* 0x40 */ u32 rgba;
        /* 0x40 */ u8 color[4];
    };
    /* 0x44 */ u8 alpha;
    /* 0x45 */ u8 _45;
    /* 0x46 */ s16 life;
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 remaining;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 tex;
} StreakParticle;

// What fn_8002955C's callers pass
typedef struct PuffParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 tex;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 life[2];
    /* 0x14 */ s32 speed[2];
    /* 0x1C */ s32 spin[2];
    /* 0x24 */ s32 size[2];
    /* 0x2C */ s32 gravity;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32 _34;
    /* 0x38 */ s32 _38;
    /* 0x3C */ s32 _3C;
    /* 0x40 */ s32 pitch[2];
    /* 0x48 */ s32 yaw[2];
    /* 0x50 */ s32 _50;
} PuffParams; // size: 0x54

// The particles fn_800297F0 starts
typedef struct PuffParticle {
    /* 0x00 */ Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ Vec accel;
    /* 0x28 */ f32 phase;
    /* 0x2C */ f32 spin;
    /* 0x30 */ f32 size;
    union {
        /* 0x34 */ s32 _34;
        /* 0x34 */ u8 color[4];
    };
    /* 0x38 */ s16 delay;
    /* 0x3A */ s16 life;
    /* 0x3C */ u8 tex;
    /* 0x3D */ s8 fadeIn;
    /* 0x3E */ s8 fadeOut;
    /* 0x3F */ u8 fadeAge;
    /* 0x40 */ u8 maxAlpha;
    /* 0x41 */ u8 additive;
    /* 0x42 */ u8 depthTest;
} PuffParticle;

// What fn_80026998's callers pass
typedef struct SmokeParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 tex;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 life;
    /* 0x10 */ Vec vel;
    /* 0x1C */ f32 velScale;
    /* 0x20 */ Vec accel;
    /* 0x2C */ f32 accelScale;
    /* 0x30 */ f32 size[2];
    /* 0x38 */ s32 alpha[2];
    /* 0x40 */ Vec pos;
    /* 0x4C */ u8 r;
    /* 0x4D */ u8 g;
    /* 0x4E */ u8 b;
} SmokeParams; // size: 0x50

// The particles fn_80026998 starts
typedef struct SmokeParticle {
    /* 0x00 */ Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ Vec accel;
    /* 0x28 */ u8 _28[0x38 - 0x28];
    /* 0x38 */ f32 w;
    /* 0x3C */ f32 h;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 remaining;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 tex;
    /* 0x4E */ u8 _4E[0x50 - 0x4E];
    /* 0x50 */ f32 grow;
    /* 0x54 */ s32 fade;
} SmokeParticle;

// What fn_8002B7F8's callers pass: the glow ring first, then the sparks
typedef struct SparkParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 glowTex;
    /* 0x08 */ s32 glowCount;
    /* 0x0C */ s32 glowLife;
    /* 0x10 */ s32 glowSwitch;
    /* 0x14 */ f32 glowH[3];
    /* 0x20 */ f32 glowW[3];
    /* 0x2C */ s32 glowAlpha[3];
    /* 0x38 */ f32 radius;
    /* 0x3C */ f32 angle;
    /* 0x40 */ f32 arc;
    /* 0x44 */ s32 sparkTex;
    /* 0x48 */ s32 sparkCount;
    /* 0x4C */ s32 sparkLife;
    /* 0x50 */ s32 sparkSwitch;
    /* 0x54 */ f32 size[3];
    /* 0x60 */ s32 alpha[3];
} SparkParams; // size: 0x6C

// The emitters and particles fn_80027300 sets up
typedef struct BurstEmitter {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s32 _10;
    /* 0x14 */ u8 _14[0x4];
    /* 0x18 */ Vec* dir;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ s16 _20;
} BurstEmitter;

typedef struct BurstParticle {
    /* 0x00 */ struct BurstParticle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
    union {
        /* 0x1C */ s32 _1C;
        /* 0x1C */ u8 color[4];
    };
    /* 0x20 */ s16 _20;
    /* 0x22 */ s16 _22;
    /* 0x24 */ s16 _24;
    /* 0x26 */ s16 _26;
    /* 0x28 */ s16 _28;
    /* 0x2A */ u8 _2A;
} BurstParticle;

// The particles fn_8002F258 starts
typedef struct TrailParticle {
    /* 0x00 */ Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec start;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ s32 id;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ u8 _2C[0x40 - 0x2C];
    union {
        /* 0x40 */ u32 rgba;
        /* 0x40 */ u8 color[4];
    };
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 _48;
    /* 0x4A */ s16 _4A;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
} TrailParticle;

typedef struct EmitterList {
    /* 0x0 */ Emitter* prev;
    /* 0x4 */ Emitter* next;
} EmitterList;

typedef struct UnkParticleState {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} UnkParticleState;

extern Particle* lbl_803CBC74;
extern u8 lbl_803CBC78;
extern s32 lbl_803CBC7C;
extern Emitter* lbl_803CBC80;
extern EmitterList lbl_803CBC84;
extern UnkParticleState lbl_80366158;

extern void fn_800118AC(Mtx src, Mtx dst);
typedef struct LightData {
    /* 0x0 */ u8 _00[6];
    /* 0x6 */ u8 r;
    /* 0x7 */ u8 g;
    /* 0x8 */ u8 b;
    /* 0x9 */ u8 _09;
} LightData; // size: 0xA

typedef struct StadiumLights {
    /* 0x00 */ LightData lights[4];
    /* 0x28 */ GXColor ambient;
} StadiumLights; // size: 0x2C

typedef struct LightFlashTask {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ LightData light;
    /* 0x1E */ u8 r;
    /* 0x1F */ u8 g;
    /* 0x20 */ u8 b;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 timer;
    /* 0x24 */ u8 duration;
} LightFlashTask;

extern struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ u8 _04[0x14 - 0x04];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
} lbl_803C5090;

extern LightFlashTask* lbl_803CC1B8;
extern StadiumLights lbl_800F7478[14];
extern u8 lbl_80367318[];
extern s32 lbl_803CBC70;
extern s32 lbl_803CB800;
extern f32 lbl_803CB804;
extern f32 lbl_803CB80C;
extern s32 lbl_803CBD0C;
extern s32 fn_8005268C(void);
extern MtxPtr fn_80052734(s32 index);
extern u16 lbl_800F7840[16];
extern void SetFogNone(void);
extern u16 lbl_800F7860[7][2];
extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ void* _2C50[13];
} lbl_8036E548;
extern BOOL getAnimRelatedCoordinates(int player, int joint, Vec* out);
extern FlareParams lbl_800F787C;
extern f32 lbl_800F78C0[4][2];
extern void fn_80023B90(LightData* data, void* light);
extern void fn_800B0A14_removeQueue(void);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800ACFB0(void* data);
extern void fn_800C07BC(void* base, void* work, s32 count, s32 size, s32 (*compare)(ZSortEntry*, ZSortEntry*));

// .bss, from the highest address down
static Emitter lbl_801F8040[16];
static Particle lbl_80180040[0x1400];
static Vec lbl_80180010[4];
static Mtx lbl_8017FFE0 ATTRIBUTE_ALIGN(32);
static Mtx lbl_8017FFA8;
static Mtx lbl_8017FF78;
static u8 lbl_8017FD6C[0x20C];
static f32 lbl_8017ED68[0x401];
static u8 lbl_8017EC00[0x168];

static inline void initParticles(void)
{
    s32 i;
    memset(lbl_80180040, 0, sizeof(lbl_80180040));
    for (i = 0; i < 0x13FF; i++) {
        lbl_80180040[i].next = &lbl_80180040[i + 1];
    }
    lbl_803CBC74 = lbl_80180040;
}

static inline void initCosTable(void)
{
    s32 i;
    for (i = 0; i < 0x401; i++) {
        lbl_8017ED68[i] = cos(3.141592654 * i / 1025.0);
    }
}

static inline void initTrail(Emitter* e, Vec* pos, s32 id, FlareParams* params)
{
    TrailParticle* p;

    e->_10 = params->_00;
    p = (TrailParticle*)e->particles;
    p->pos.x = pos->x;
    p->pos.y = pos->y;
    p->pos.z = pos->z;
    p->start.x = pos->x;
    p->start.y = pos->y;
    p->start.z = pos->z;
    p->_1C = params->_08 / 100000.0f;
    p->_24 = params->_0C;
    p->id = id;
    p->color[3] = 0xFF;
    p->color[2] = 0xFF;
    p->color[1] = 0xFF;
    p->color[0] = 0xFF;
    p->_48 = 1;
    p->_28 = p->_4A = params->_10;
    p->_4C = 1;
    p->_4D = params->_04;
}

static inline void initSmoke(Emitter* e, SmokeParams* params)
{
    SmokeParticle* p;

    e->_10 = params->_00;
    p = (SmokeParticle*)e->particles;
    do {
        p->tex = params->tex;
        p->remaining = params->life;
        p->delay = 0;
        p->vel.x = params->vel.x * params->velScale;
        p->vel.y = params->vel.y * params->velScale;
        p->vel.z = params->vel.z * params->velScale;
        p->accel.x = params->accel.x * params->accelScale;
        p->accel.y = params->accel.y * params->accelScale;
        p->accel.z = params->accel.z * params->accelScale;
        p->w = p->h = params->size[0];
        p->color[0] = params->r;
        p->color[1] = params->g;
        p->color[2] = params->b;
        p->color[3] = params->alpha[0];
        memcpy(&p->pos, &params->pos, sizeof(Vec));
        p->grow = (params->size[1] - params->size[0]) / params->life;
        p->fade = (params->alpha[1] - params->alpha[0]) / params->life;
        p = (SmokeParticle*)p->next;
    } while (p != NULL);
}

// .text:0x800348C8 size:0x304
void minigamesSetSomePointers2(void)
{
    s32 i;

    memset(lbl_80180040, 0, sizeof(lbl_80180040));
    for (i = 0; i < 0x13FF; i++) {
        lbl_80180040[i].next = &lbl_80180040[i + 1];
    }
    lbl_803CBC74 = lbl_80180040;
    lbl_803CBC78 = 0;
    lbl_803CBC84.prev = NULL;
    lbl_803CBC84.next = NULL;
    memset(lbl_801F8040, 0, sizeof(lbl_801F8040));
    for (i = 0; i < 15; i++) {
        lbl_801F8040[i].next = &lbl_801F8040[i + 1];
    }
    lbl_803CBC80 = lbl_801F8040;
    initCosTable();
    lbl_803CBC7C = 0;
}

// .text:0x8003452C size:0x39C
void minigamesGXStuff(void)
{
    GXTexObj texObj;
    Emitter* e;
    Emitter* dead;
    BOOL finished;

    if (lbl_803CBC78 != 0) {
        lbl_803CBC78 = 0;
        e = lbl_803CBC84.next;
        while (e != NULL) {
            dead = e;
            e = e->next;
            fn_80033964(dead);
        }
        lbl_803CBC84.next = NULL;
        return;
    }
    if (lbl_803CBC84.next == NULL) {
        return;
    }
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetCullMode(GX_CULL_NONE);
    GXInitTexObj(&texObj, lbl_800F7840, 4, 4, GX_TF_RGB565, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&texObj, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXLoadTexObj(&texObj, GX_TEXMAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_RASA, GX_CA_TEXA, GX_CA_ZERO);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetProjection(fn_80052734(fn_8005268C()), GX_PERSPECTIVE);
    GXLoadPosMtxImm(lbl_8017FFE0, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    SetFogNone();
    e = lbl_803CBC84.next;
    while (e != NULL) {
        if (e->update != NULL) {
            finished = e->update(e);
            if (finished) {
                dead = e;
            }
        }
        e = e->next;
        if (finished) {
            fn_80033964(dead);
        }
    }
}

// .text:0x80034220 size:0x30C
void minigamesSetSomePointers(void)
{
    s32 i;

    lbl_803CBC78 = 1;
    initParticles();
    lbl_803CBC78 = 0;
    lbl_803CBC84.prev = NULL;
    lbl_803CBC84.next = NULL;
    memset(lbl_801F8040, 0, sizeof(lbl_801F8040));
    for (i = 0; i < 15; i++) {
        lbl_801F8040[i].next = &lbl_801F8040[i + 1];
    }
    lbl_803CBC80 = lbl_801F8040;
    initCosTable();
    lbl_803CBC7C = 0;
}

// .text:0x8003414C size:0xD4
void fn_8003414C(Mtx m)
{
    PSMTXCopy(m, lbl_8017FFE0);
    fn_800118AC(m, lbl_8017FFA8);
    PSMTXCopy(lbl_8017FFA8, lbl_8017FF78);
    lbl_8017FF78[2][3] = 0.0f;
    lbl_8017FF78[1][3] = 0.0f;
    lbl_8017FF78[0][3] = 0.0f;
    fn_8003403C(1.0f, 1.0f);
}

// .text:0x80034120 size:0x2C
void fn_80034120(Mtx m)
{
    PSMTXCopy(lbl_8017FFE0, m);
}

// .text:0x800340F4 size:0x2C
void fn_800340F4(Mtx m)
{
    PSMTXCopy(lbl_8017FF78, m);
}

// .text:0x8003403C size:0xB8
void fn_8003403C(f32 w, f32 h)
{
    s32 i;

    lbl_80180010[0].x = 0.5f * -w;
    lbl_80180010[0].y = 0.5f * -h;
    lbl_80180010[0].z = 0.0f;
    lbl_80180010[1].x = 0.5f * w;
    lbl_80180010[1].y = 0.5f * -h;
    lbl_80180010[1].z = 0.0f;
    lbl_80180010[2].x = 0.5f * w;
    lbl_80180010[2].y = 0.5f * h;
    lbl_80180010[2].z = 0.0f;
    lbl_80180010[3].x = 0.5f * -w;
    lbl_80180010[3].y = 0.5f * h;
    lbl_80180010[3].z = 0.0f;
    for (i = 0; i < 4; i++) {
        PSMTXMultVec(lbl_8017FF78, &lbl_80180010[i], &lbl_80180010[i]);
    }
}

// .text:0x80033F64 size:0xD8
void fn_80033F64(f32 w, f32 h, f32 angle)
{
    Mtx m;
    Mtx rot;
    s32 i;

    lbl_80180010[0].x = 0.5f * -w;
    lbl_80180010[0].y = 0.5f * -h;
    lbl_80180010[0].z = 0.0f;
    lbl_80180010[1].x = 0.5f * w;
    lbl_80180010[1].y = 0.5f * -h;
    lbl_80180010[1].z = 0.0f;
    lbl_80180010[2].x = 0.5f * w;
    lbl_80180010[2].y = 0.5f * h;
    lbl_80180010[2].z = 0.0f;
    lbl_80180010[3].x = 0.5f * -w;
    lbl_80180010[3].y = 0.5f * h;
    lbl_80180010[3].z = 0.0f;
    PSMTXRotRad(rot, 'z', 0.017453292f * angle);
    PSMTXConcat(lbl_8017FF78, rot, m);
    for (i = 0; i < 4; i++) {
        PSMTXMultVec(m, &lbl_80180010[i], &lbl_80180010[i]);
    }
}

// .text:0x80033CC8 size:0x29C
void fn_80033CC8(Particle* p, TexFile* file)
{
    s32 i;

    fn_80033B58(file, p->_4D, GX_CLAMP, GX_CLAMP);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (i = 0; i < 4; i++) {
        GXPosition3f32(p->pos.x + lbl_80180010[i].x, p->pos.y + lbl_80180010[i].y, p->pos.z + lbl_80180010[i].z);
        GXColor1u32(p->_40);
        GXTexCoord2f32(lbl_800F7860[p->_4E + i][0], lbl_800F7860[p->_4E + i][1]);
    }
    GXEnd();
}

// .text:0x80033B58 size:0x170
void fn_80033B58(TexFile* file, s32 index, GXTexWrapMode wrapS, GXTexWrapMode wrapT)
{
    GXTexObj texObj;
    GXTlutObj tlutObj;
    TextureDesc* tex;

    if (file == NULL) {
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
        return;
    }
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR0A0);
    tex = &file->tex[file->tex[index]._1C];
    if (tex->tlut != NULL) {
        GXInitTexObjCI(&texObj, tex->image, tex->width, tex->height, tex->format, wrapS, wrapT, GX_FALSE, GX_TLUT0);
        GXInitTlutObj(&tlutObj, tex->tlut, tex->tlutFormat, tex->tlutCount);
        GXLoadTlut(&tlutObj, GX_TLUT0);
    } else {
        GXInitTexObj(&texObj, tex->image, tex->width, tex->height, tex->format, wrapS, wrapT, GX_FALSE);
    }
    GXInitTexObjLOD(&texObj, GX_LINEAR, GX_LINEAR, tex->minLOD, tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXLoadTexObj(&texObj, GX_TEXMAP1);
}

// .text:0x80033A24 size:0x134
Emitter* fn_80033A24(BOOL (*update)(void*), u8 priority, s32 kind, s32 n, BOOL all, u8 id)
{
    Emitter* e = fn_800337CC(lbl_803CBC80, n, all);
    Emitter* prev;

    if (e == NULL) {
        return NULL;
    }
    prev = (Emitter*)&lbl_803CBC84;
    lbl_803CBC80 = lbl_803CBC80->next;
    e->update = update;
    e->priority = priority;
    e->id = id;
    e->_17_hi = 1;
    e->_14_hi = kind;
    e->next = NULL;
    e->prev = NULL;
    while (prev->next != NULL && prev->next->priority < e->priority) {
        prev = prev->next;
    }
    e->next = prev->next;
    if (e->next != NULL) {
        e->next->prev = e;
    }
    e->prev = prev;
    prev->next = e;
    return e;
}

// .text:0x800339F0 size:0x34
Emitter* fn_800339F0(Emitter* e, u8 id)
{
    if (e == NULL) {
        e = (Emitter*)&lbl_803CBC84;
    }
    while ((e = e->next) != NULL) {
        if (e->id == id) {
            break;
        }
    }
    return e;
}

// .text:0x80033964 size:0x8C
void fn_80033964(Emitter* e)
{
    if (e->update == NULL) {
        return;
    }
    if (e->prev != NULL) {
        e->prev->next = e->next;
    }
    if (e->next != NULL) {
        e->next->prev = e->prev;
    }
    e->update = NULL;
    fn_80033794(e->particles);
    e->prev = NULL;
    e->next = lbl_803CBC80;
    lbl_803CBC80 = e;
}

// .text:0x80033928 size:0x3C
BOOL fn_80033928(u8 id)
{
    Emitter* e;
    for (e = lbl_803CBC84.next; e != NULL; e = e->next) {
        if (e->id == id) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x8003385C size:0xCC
void pitchingMachinePitching(u8 id)
{
    Emitter* e = lbl_803CBC84.next;
    while (e != NULL) {
        Emitter* found = (e->id == id) ? e : NULL;
        e = e->next;
        if (found != NULL) {
            fn_80033964(found);
        }
    }
}

// .text:0x800337CC size:0x90
Emitter* fn_800337CC(Emitter* e, s32 n, BOOL all)
{
    s32 count = 0;
    Particle* p = lbl_803CBC74;
    Particle* last = NULL;

    if (e != NULL) {
        while (p != NULL && n != 0) {
            last = p;
            p = p->next;
            count++;
            n--;
        }
        if (all && n != 0) {
            return NULL;
        }
        e->count = count;
        if (count != 0) {
            e->particles = lbl_803CBC74;
            lbl_803CBC74 = p;
            if (last != NULL) {
                last->next = NULL;
            }
        } else {
            e->particles = NULL;
        }
    }
    return e;
}

// .text:0x80033794 size:0x38
void fn_80033794(Particle* list)
{
    Particle* p = list;
    while (p != NULL && p->next != NULL) {
        p = p->next;
    }
    if (p != NULL) {
        p->next = lbl_803CBC74;
        lbl_803CBC74 = list;
    }
}

// .text:0x80033620 size:0x174
void fn_80033620(Emitter* e)
{
    Particle* p;
    Particle* q;
    Particle* best;
    u32 i = 0;
    f32 bestZ;
    Vec v;
    Vec w;
    Particle tmp;

    for (p = e->particles; p != NULL && e->count > i; p = p->next, i++) {
        q = p->next;
        if (p->_48 <= 0 && p->_4A != 0) {
            PSMTXMultVec(lbl_8017FFE0, &p->pos, &v);
            bestZ = v.z;
            best = NULL;
            for (; q != NULL; q = q->next) {
                if (q->_48 <= 0 && q->_4A != 0) {
                    PSMTXMultVec(lbl_8017FFE0, &q->pos, &w);
                    if (bestZ > w.z) {
                        best = q;
                        bestZ = w.z;
                    }
                }
            }
            if (best != NULL) {
                Particle* pNext = p->next;
                Particle* bestNext = best->next;
                tmp = *p;
                *p = *best;
                *best = tmp;
                p->next = pNext;
                best->next = bestNext;
            }
        }
    }
}

// .text:0x800335EC size:0x34
f32 fn_800335EC(s32 angle)
{
    s32 i = __abs(angle + 0x600) & 0x7FF;
    if (i >= 0x401) {
        i = 0x800 - i;
    }
    return lbl_8017ED68[i];
}

// .text:0x800335BC size:0x30
f32 fn_800335BC(s32 angle)
{
    s32 i;
    if (angle < 0) {
        angle = -angle;
    }
    i = angle & 0x7FF;
    if (i >= 0x401) {
        i = 0x800 - i;
    }
    return lbl_8017ED68[i];
}

// .text:0x800332B8 size:0x304
// 98.06%: the last table lookup negates a copy of pitch (the target negates it in place),
// and the target keeps angle on the stack. With every lookup a call of fn_800335BC or
// fn_800335EC it is small enough to be inlined into fn_800297F0 and fn_80027300.
void fn_800332B8(Vec* dirIn, Vec* out, f32 yawMin, f32 yawMax, f32 pitchMin, f32 pitchMax)
{
    Mtx m;
    Vec axis;
    Vec up = { 1.0f, 0.0f, 0.0f };
    Vec dir;
    Quaternion q;
    s32 base;
    s32 yaw;
    s32 pitch;
    s32 i;
    f32 angle;

    if (dirIn != NULL) {
        memcpy(&dir, dirIn, sizeof(Vec));
        dirIn = &dir;
    }
    base = 2048.0f * (yawMin / 360.0f) + 0.5f;
    if (yawMax != yawMin) {
        yaw = base + rand() % (s32)(2048.0f * ((yawMax - yawMin) / 360.0f) + 0.5f);
    } else {
        yaw = base;
    }
    out->x = fn_800335BC(yaw);
    i = __abs(yaw + 0x600) & 0x7FF;
    if (i >= 0x401) {
        i = 0x800 - i;
    }
    out->y = lbl_8017ED68[i];
    pitch = 2048.0f * (pitchMin / 360.0f) + 0.5f;
    if (pitchMax != pitchMin) {
        pitch += rand() % (s32)(2048.0f * ((pitchMax - pitchMin) / 360.0f) + 0.5f);
    }
    i = __abs(pitch + 0x600) & 0x7FF;
    if (i >= 0x401) {
        i = 0x800 - i;
    }
    out->z = out->x * lbl_8017ED68[i];
    out->x *= fn_800335BC(pitch);
    if (dirIn != NULL && PSVECMag(dirIn)) {
        angle = acos(PSVECDotProduct(&up, dirIn));
        PSVECCrossProduct(&up, dirIn, &axis);
        if (PSVECMag(&axis)) {
            C_QUATRotAxisRad(&q, &axis, angle);
            PSMTXQuat(m, &q);
            PSMTXMultVec(m, out, out);
        } else {
            PSVECScale(out, PSVECMag(dirIn), out);
        }
    }
}

// .text:0x800330CC size:0x1EC
void fn_800330CC(s32 n, u32 arg1, Vec* start, Vec* end, f32 arg4, s32 arg5, s32 arg6, f32 arg7)
{
    ArcEmitter* e = (ArcEmitter*)fn_80033A24(fn_800328E0, 0x80, 0, n, TRUE, 1);

    if (e != NULL) {
        e->_10 = arg6;
        memcpy(&e->start, start, sizeof(Vec));
        memcpy(&e->end, end, sizeof(Vec));
        e->_30 = arg4;
        e->_34 = arg5;
        e->_38 = -0.4f;
        e->_3C = -0.0001f;
        e->_40 = arg1;
        e->_44 = arg7;
    }
}

// .text:0x800324EC size:0x3F4
// 99.57%: the target tests the first player's pointer with bne over a b to the end; this
// branches with beq. Only branch targets differ after it.
void fn_800324EC(u16 joint, s32 player, s32 other, StreakParams* dir)
{
    Vec pos;
    Vec v;
    u32 colors[32];
    FlareParams* params;
    Emitter* e;
    Particle* p;
    u32 i;

    if (player >= 0 && player < 13) {
        if (lbl_8036E548._2C50[player] == NULL) {
            return;
        }
        getAnimRelatedCoordinates(player, joint, &pos);
        if (other >= 0 && other < 13 && lbl_8036E548._2C50[other] != NULL) {
            getAnimRelatedCoordinates(other, joint, &v);
            PSVECSubtract(&v, &pos, &v);
            PSVECScale(&v, 0.5f, &v);
            PSVECAdd(&pos, &v, &pos);
        }
        v.x = lbl_8017FFE0[0][3];
        v.y = lbl_8017FFE0[1][3];
        v.z = lbl_8017FFE0[2][3];
        colors[0] = (lbl_800F787C.r << 24) | (lbl_800F787C.g << 16) | (lbl_800F787C.b << 8) | 0xFF;
        for (i = 1; i < 32; i++) {
            colors[i] = colors[0];
        }
        params = &lbl_800F787C;
        params->_00 = lbl_803CBD0C;
        e = fn_80033A24(fn_8002E828, 0x80, 0, 1, TRUE, 6);
        if (e != NULL) {
            e->_10 = params->_00;
            p = e->particles;
            p->pos.x = pos.x;
            p->pos.y = pos.y;
            p->pos.z = pos.z;
            p->_40 = -0x100;
            p->_18 = params->_10;
            p->_1C = p->_4A = params->_14;
            p->_20 = params->_14 / 2;
            p->_38 = p->_3C = p->_10 = params->_08 / 100000.0f;
            p->_14 = params->_0C / 100000.0f;
            p->_4D = params->_04;
        }
        if (dir != NULL) {
            fn_8002A1CC(&pos, dir);
        }
    }
}

// .text:0x80032284 size:0x268
void fn_80032284(Vec* pos)
{
    FlareParams params;
    Emitter* e;
    Particle* p;

    memcpy(&params, &lbl_800F787C, sizeof(FlareParams));
    params._00 = lbl_803CBD0C;
    params._10 = 255;
    params._08 = 500000;
    params._0C = 700000;
    params._14 = 32;
    e = fn_80033A24(fn_8002E3DC, 0x80, 0, 1, TRUE, 7);
    if (e != NULL) {
        e->_10 = params._00;
        p = e->particles;
        p->pos.x = pos->x;
        p->pos.y = pos->y;
        p->pos.z = pos->z;
        p->_40 = -0x100;
        p->color[3] = params._10;
        p->_18 = params._10;
        p->_1C = p->_4A = params._14;
        p->_20 = params._14 / 2;
        p->_38 = p->_3C = p->_10 = params._08 / 100000.0f;
        p->_14 = params._0C / 100000.0f;
        p->_4D = params._04;
    }
}

// .text:0x80032064 size:0x220
void fn_80032064(Vec* pos, StreakParams* dir)
{
    FlareParams* params = &lbl_800F787C;
    Emitter* e;
    Particle* p;

    params->_00 = lbl_803CBD0C;
    e = fn_80033A24(fn_8002E828, 0x80, 0, 1, TRUE, 6);
    if (e != NULL) {
        e->_10 = params->_00;
        p = e->particles;
        p->pos.x = pos->x;
        p->pos.y = pos->y;
        p->pos.z = pos->z;
        p->_40 = -0x100;
        p->_18 = params->_10;
        p->_1C = p->_4A = params->_14;
        p->_20 = params->_14 / 2;
        p->_38 = p->_3C = p->_10 = params->_08 / 100000.0f;
        p->_14 = params->_0C / 100000.0f;
        p->_4D = params->_04;
    }
    fn_8002A1CC(pos, dir);
}

// .text:0x80032038 size:0x2C
s32 fn_80032038(ZSortEntry* a, ZSortEntry* b)
{
    if (a->z > b->z) {
        return 1;
    }
    if (a->z < b->z) {
        return -1;
    }
    return 0;
}

// .text:0x80031F34 size:0x104
// 92.91%: the target keeps n and the countdown copy in separate registers from the start
// (r25, r26) and has a 0x10-byte larger frame; loop and local variants did not reproduce it.
Particle* fn_80031F34(Particle* list, s32 n)
{
    s32 i = 0;
    s32 count = n;
    ZSortEntry* entries;
    ZSortEntry* ent;
    Particle* p;
    Vec v;
    Particle* head;
    ZSortEntry* e2;

    if (n != 0) {
        entries = _OSAllocFromHeap(32, n * (2 * sizeof(ZSortEntry)));
        ent = entries;
        for (p = list; p != NULL; p = p->next) {
            if (i >= n) {
                OSReport("zsort particle err.\n");
                break;
            }
            ent->p = p;
            PSMTXMultVec(lbl_8017FFE0, &p->pos, &v);
            i++;
            ent->z = v.z;
            ent++;
        }
        fn_800C07BC(entries, entries + n, n, sizeof(ZSortEntry), fn_80032038);
        head = entries[0].p;
        e2 = entries;
        while (--count != 0) {
            e2->p->next = e2[1].p;
            e2++;
        }
        e2->p->next = NULL;
        fn_800ACFB0(entries);
    }
    return head;
}

// .text:0x80031CA4 size:0x290
void fn_80031CA4(Vec* pos, EffectParams* params)
{
    Emitter* e = fn_800339F0(NULL, 5);

    if (e != NULL) {
        u8 tmp[sizeof(Emitter)];
        Emitter* added = fn_800337CC((Emitter*)tmp, params->count, TRUE);
        if (added != NULL) {
            Particle* p;
            fn_800317C4(added, pos, params);
            p = e->particles;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = added->particles;
            e->count += added->count;
        }
    } else {
        e = fn_80033A24(fn_80031034, 0x11, 0, params->count, TRUE, 5);
        if (e != NULL) {
            e->state = 0;
            fn_800317C4(e, pos, params);
        }
    }
}

// .text:0x800317C4 size:0x4E0
void fn_800317C4(Emitter* e, Vec* pos, EffectParams* params)
{
    s32 a;
    SwirlParticle* p = (SwirlParticle*)e->particles;
    s32 i;
    s32 angle;
    s32 j;
    s32 k;
    f32 s;
    f32 c;
    f32 v;
    f32 w;
    f32 tilt;

    e->_10 = params->_00;
    for (i = 0, a = 0; i < e->count; a += 0x5000, i++) {
        angle = (a / e->count + 5) / 10;
        j = __abs(angle + 0x600) & 0x7FF;
        if (j >= 0x401) {
            j = 0x800 - j;
        }
        s = lbl_8017ED68[j];
        c = fn_800335BC(angle);
        p->pos.x = pos->x;
        p->pos.y = pos->y;
        p->pos.z = pos->z;
        k = lbl_803CB800;
        v = params->_0C[1] / 100000.0f * (1.0f - 0.01f * k + 0.02 * k * (rand() % 256) / 256.0);
        p->vel.x = s * v;
        p->vel.y = 0.0f;
        p->vel.z = c * v;
        p->_34 = 0.0f;
        tilt = 3.1415927f * (params->_0C[9] / 100000.0f) / 180.0f * (0x80 - rand() % 256) / 128.0f + 3.1415927f * (params->_44 / 100000.0f) / 180.0f;
        s = sin(tilt);
        c = cos(tilt);
        w = params->_0C[0] / 100000.0f;
        p->_38 = w * (s - c);
        p->_3C = w * (c + s);
        p->_1C = 0.01f * (8 - rand() % 16) + params->_0C[0] / 100000.0f;
        p->_20 = params->_0C[5] / 100000.0f;
        p->_24 = params->_0C[6] / 100000.0f;
        p->_2C = params->_0C[3] - params->_0C[4];
        k = lbl_803CB800;
        p->_28 = params->_0C[2] / 100000.0f * (1.0f - 0.01f * k + 0.02 * k * (rand() % 256) / 256.0);
        p->rgba = params->_40;
        p->_30 = params->_0C[8];
        p->_34 = params->_48 / 100000.0f;
        p->_44 = params->_4C;
        p->delay = p->remaining = params->_0C[3];
        p->_4C = 1;
        p->_4E = 0;
        p->tex = params->_04;
        p->_4F = params->_0C[7];
        p = (SwirlParticle*)p->next;
    }
}

// .text:0x80030D88 size:0x2AC
// 98.80%: the target copies params to r7 before dir to r5 at entry; this copies them
// the other way round. The rest matches.
void fn_80030D88(Vec* pos, Vec* dir, EffectParams* params, s32 id)
{
    if (params->count > 0) {
        Emitter* e = fn_800339F0(NULL, id);

        if (e != NULL) {
            u8 tmp[sizeof(Emitter)];
            Emitter* added = fn_800337CC((Emitter*)tmp, params->count, TRUE);
            if (added != NULL) {
                Particle* p;
                fn_80030720(added, pos, dir, params);
                p = e->particles;
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = added->particles;
                e->count += added->count;
            }
        } else {
            e = fn_80033A24(fn_80031034, 0x11, 0, params->count, TRUE, id);
            if (e != NULL) {
                e->state = 0;
                fn_80030720(e, pos, dir, params);
            }
        }
    }
}

// .text:0x80030720 size:0x668
void fn_80030720(Emitter* e, Vec* pos, Vec* dir, EffectParams* params)
{
    SwirlParticle* p = (SwirlParticle*)e->particles;
    Mtx rot;
    Mtx m;
    Vec d;
    Vec n;
    Vec up = { 0.0f, -1.0f, 0.0f };
    Vec axis;
    Quaternion q;
    s32 i;
    s32 k;
    f32 mag;
    f32 lo;
    f32 yaw;
    f32 v;
    f32 w;
    f32 s;
    f32 c;
    f32 tilt;

    e->_10 = params->_00;
    PSVECNormalize(dir, &n);
    PSVECCrossProduct(&up, &n, &axis);
    mag = PSVECMag(&axis);
    for (i = 0; i < e->count; i++) {
        if (i & 1) {
            yaw = -yaw;
        } else {
            if (mag == 0.0f) {
                PSMTXIdentity(m);
            } else {
                f32 half;
                lo = 6.2831855f * (params->_0C[11] / 100000.0f) / 360.0f;
                half = (6.2831855f * (params->_0C[12] / 100000.0f) / 360.0f - lo) / 2;
                C_QUATRotAxisRad(&q, &axis, -(half * (8 - rand() % 16) / 8.0f + (lo + half)));
                PSMTXQuat(m, &q);
            }
            yaw = 6.2831855f * (params->_0C[10] / 100000.0f) / 360.0f * (8 - rand() % 16) / 8.0f;
        }
        PSMTXRotRad(rot, 'Y', yaw);
        PSMTXConcat(rot, m, rot);
        PSMTXMultVec(rot, &n, &d);
        p->pos.x = pos->x;
        p->pos.y = pos->y;
        p->pos.z = pos->z;
        k = lbl_803CB800;
        v = params->_0C[1] / 100000.0f * (1.0f - 0.01f * k + 0.02 * k * (rand() % 256) / 256.0);
        p->vel.x = d.x * v;
        p->vel.y = d.y;
        p->vel.z = d.z * v;
        p->_34 = 0.0f;
        tilt = 3.1415927f * (params->_0C[9] / 100000.0f) / 180.0f * (0x80 - rand() % 256) / 128.0f + 3.1415927f * (params->_44 / 100000.0f) / 180.0f;
        s = sin(tilt);
        c = cos(tilt);
        w = params->_0C[0] / 100000.0f;
        p->_38 = w * (s - c);
        p->_3C = w * (c + s);
        p->_1C = 0.01f * (8 - rand() % 16) + params->_0C[0] / 100000.0f;
        p->_20 = params->_0C[5] / 100000.0f;
        p->_24 = params->_0C[6] / 100000.0f;
        p->_2C = params->_0C[3] - params->_0C[4];
        k = lbl_803CB800;
        p->_28 = params->_0C[2] / 100000.0f * (1.0f - 0.01f * k + 0.02 * k * (rand() % 256) / 256.0);
        p->rgba = params->_40;
        p->_30 = params->_0C[8];
        p->_34 = params->_48 / 100000.0f;
        p->_44 = params->_4C;
        p->delay = p->remaining = params->_0C[3];
        p->_4C = 1;
        p->_4E = 0;
        p->tex = params->_04;
        p->_4F = params->_0C[7];
        p = (SwirlParticle*)p->next;
    }
}

// .text:0x80030470 size:0x2B0
void fn_80030470(Vec* pos, Vec* dir, Vec* back, EffectParams* params, s32 id)
{
    Emitter* e = fn_800339F0(NULL, id);

    if (e != NULL) {
        u8 tmp[sizeof(Emitter)];
        Emitter* added = fn_800337CC((Emitter*)tmp, params->count, TRUE);
        if (added != NULL) {
            Particle* p;
            fn_8002FDB8(added, pos, dir, back, params);
            p = e->particles;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = added->particles;
            e->count += added->count;
        }
    } else {
        e = fn_80033A24(fn_80031034, 0x11, 0, params->count, TRUE, id);
        if (e != NULL) {
            e->state = 0;
            fn_8002FDB8(e, pos, dir, back, params);
        }
    }
}

// .text:0x8002FDB8 size:0x6B8
void fn_8002FDB8(Emitter* e, Vec* pos, Vec* dir, Vec* back, EffectParams* params)
{
    SwirlParticle* p;
    Mtx rot;
    Mtx m;
    Vec a;
    Vec n;
    Vec axis;
    Vec up = { 0.0f, -1.0f, 0.0f };
    Quaternion q;
    s32 i;
    f32 k;
    f32 mag;
    f32 tilt;
    f32 yaw;

    e->_10 = params->_00;
    PSVECNormalize(dir, &n);
    PSVECCrossProduct(&up, &n, &axis);
    mag = PSVECMag(&axis);
    p = (SwirlParticle*)e->particles;
    for (i = 0; i < e->count; i++) {
        if (i & 1) {
            yaw = -tilt;
        } else {
            if (mag == 0.0f) {
                PSMTXIdentity(m);
            } else {
                f32 half;
                tilt = 6.2831855f * (params->_0C[11] / 100000.0f) / 360.0f;
                half = (6.2831855f * (params->_0C[12] / 100000.0f) / 360.0f - tilt) / 2;
                C_QUATRotAxisRad(&q, &axis, -(half * (8 - rand() % 16) / 8.0f + (tilt + half)));
                PSMTXQuat(m, &q);
            }
            yaw = 6.2831855f * (params->_0C[10] / 100000.0f) / 360.0f * (8 - rand() % 16) / 8.0f;
        }
        PSMTXRotRad(rot, 'Y', yaw);
        PSMTXConcat(rot, m, rot);
        PSMTXMultVec(rot, dir, &n);
        p->pos.x = pos->x;
        p->pos.y = pos->y;
        p->pos.z = pos->z;
        p->vel.x = back->x * params->_0C[1];
        p->vel.y = back->y * params->_0C[1];
        p->vel.z = back->z * params->_0C[1];
        PSVECAdd(pos, &n, &n);
        PSMTXMultVec(lbl_8017FFE0, pos, &a);
        PSMTXMultVec(lbl_8017FFE0, &n, &n);
        if (a.z != n.z) {
            if (n.z != 0.0f) {
                n.x *= a.z / n.z;
                n.y *= a.z / n.z;
                n.z = a.z;
            } else {
                a.x *= n.z / a.z;
                a.y *= n.z / a.z;
                a.z = n.z;
            }
        }
        PSVECSubtract(&a, &n, &n);
        if (PSVECMag(&n)) {
            PSVECNormalize(&n, &n);
        } else {
            n.x = 0.0f;
            n.y = 1.0f;
            n.z = 0.0f;
        }
        a.x = -n.y;
        a.y = n.x;
        a.z = n.z;
        PSVECAdd(&n, &a, &n);
        tilt = 6.2831855f * (params->_0C[9] / 100000.0f) / 360.0f * (8 - rand() % 16) / 8.0f;
        PSMTXRotRad(rot, 'Y', tilt);
        PSMTXMultVec(rot, &n, &n);
        p->_38 = n.x;
        p->_3C = n.y;
        p->_1C = 0.01f * (8 - rand() % 16) + params->_0C[0] / 100000.0f;
        p->_20 = params->_0C[5] / 100000.0f;
        p->_24 = params->_0C[6] / 100000.0f;
        p->_2C = params->_0C[3] - params->_0C[4];
        k = lbl_803CB804;
        p->_28 = params->_0C[2] / 100000.0f * (1.0f - 0.01f * k + 0.02 * k * (rand() % 256) / 256.0);
        p->rgba = params->_40;
        p->_30 = params->_0C[8];
        p->_34 = params->_48 / 100000.0f;
        p->_44 = params->_4C;
        p->delay = p->remaining = params->_0C[3];
        p->_4C = 1;
        p->_4E = 0;
        p->tex = params->_04;
        p->_4F = params->_0C[7];
        p = (SwirlParticle*)p->next;
    }
}

// .text:0x8002F9FC size:0x3BC
BOOL fn_8002F9FC(void* arg)
{
    Emitter* e = arg;
    Particle* p = e->particles;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    do {
        fn_8003403C(p->_38, p->_3C);
        if (p->_4F != 0) {
            GXSetBlendMode(GX_BM_SUBTRACT, GX_BL_ONE, GX_BL_ONE, GX_LO_CLEAR);
        } else {
            GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
        }
        fn_80033CC8(p, (TexFile*)e->_10);
        p = p->next;
    } while (p != NULL);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    return TRUE;
}

// .text:0x8002F5F4 size:0x408
// 85.50%: first draft; the target keeps params in r28 and schedules the float setup
// differently, and the per-particle stores differ. Not yet compared in detail.
void fn_8002F5F4(Vec* pos, Vec* dir, EffectParams* params)
{
    f32 scale = params->_0C[3] / 100000.0f;
    f32 start = (-params->_0C[4] * scale) / (params->count - 1);
    f32 range = (start + scale) - start;
    Emitter* e = fn_80033A24(fn_8002F9FC, 0x80, 0, params->count * 2, TRUE, 8);

    if (e != NULL) {
        s32 i = 0;
        Particle* p;
        Particle* q;
        Vec v;
        f32 size;
        s32 c;

        e->_10 = params->_00;
        p = e->particles;
        do {
            PSVECScale(dir, start + (i * range) / (params->count - 1), &v);
            PSVECAdd(pos, &v, &v);
            p->pos.x = v.x;
            p->pos.y = v.y;
            p->pos.z = v.z;
            if (i >= params->count - params->_0C[0]) {
                size = params->_0C[2] / 100000.0f +
                       ((params->_0C[1] / 100000.0f - params->_0C[2] / 100000.0f) * (params->count - i - 1)) / params->_0C[0];
            } else {
                size = params->_0C[1] / 100000.0f;
            }
            p->_38 = p->_3C = size;
            c = params->_0C[5];
            p->_40 = (c << 24) | (c << 16) | (c << 8) | 0xFF;
            p->_4D = params->_04;
            p->_4E = 0;
            p->_4F = 1;
            q = p->next;
            q->pos.x = v.x;
            q->pos.y = v.y;
            q->pos.z = v.z;
            q->_38 = q->_3C = size;
            c = params->_0C[5];
            q->_40 = (c << 24) | (c << 16) | (c << 8) | 0xFF;
            q->_4D = params->_0C[6 + i];
            q->_4E = 0;
            q->_4F = 0;
            p = q->next;
            i++;
        } while (p != NULL);
    }
}

// .text:0x8002F258 size:0x39C
void fn_8002F258(Vec* pos, s32 id, FlareParams* params)
{
    Emitter* e = fn_800339F0(NULL, 6);

    if (e != NULL) {
        u8 tmp[sizeof(Emitter)];
        Emitter* added = fn_800337CC((Emitter*)tmp, 1, TRUE);
        if (added != NULL) {
            Particle* p;
            initTrail(added, pos, id, params);
            p = e->particles;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = added->particles;
            e->count++;
        }
    } else {
        e = fn_80033A24(fn_8002ECA0, 0x10, 0, 1, TRUE, 6);
        if (e != NULL) {
            initTrail(e, pos, id, params);
        }
    }
}

// .text:0x8002F1AC size:0xAC
BOOL fn_8002F1AC(Vec* pos, s32 key)
{
    Emitter* e = fn_800339F0(NULL, 6);
    Particle* p;

    if (e != NULL && lbl_80366158._28 == 0) {
        for (p = e->particles; p != NULL; p = p->next) {
            if (p->_20 == key) {
                memcpy(&p->pos, pos, sizeof(Vec));
                p->_4A++;
                return TRUE;
            }
        }
    }
    return FALSE;
}

// .text:0x8002ECA0 size:0x50C
BOOL fn_8002ECA0(void* arg)
{
    Emitter* e = arg;
    TrailParticle* p = (TrailParticle*)e->particles;
    s32 alive = 0;
    Particle* dead;
    Particle* tail;
    Particle* prev = (Particle*)&e->particles;
    GXTexObj texObj;
    Vec d;
    GXTlutObj tlutObj;
    TexFile* file;
    s32 index;
    TextureDesc* tex;
    GXPrimitive prim;
    s32 alpha;

    tail = NULL;
    dead = NULL;
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    do {
        PSVECSubtract(&p->pos, &p->start, &d);
        file = (TexFile*)e->_10;
        index = p->_4D;
        if (file == NULL) {
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
        } else {
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR0A0);
            tex = &file->tex[file->tex[index]._1C];
            if (tex->tlut != NULL) {
                GXInitTexObjCI(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE, GX_TLUT0);
                GXInitTlutObj(&tlutObj, tex->tlut, tex->tlutFormat, tex->tlutCount);
                GXLoadTlut(&tlutObj, GX_TLUT0);
            } else {
                GXInitTexObj(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE);
            }
            GXInitTexObjLOD(&texObj, GX_LINEAR, GX_LINEAR, tex->minLOD, tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
            GXLoadTexObj(&texObj, GX_TEXMAP1);
        }
        if (PSVECMag(&d)) {
            PSVECNormalize(&d, &d);
            PSVECScale(&d, p->_1C / 2, &d);
            prim = GX_TRIANGLESTRIP;
        } else {
            d.x = 0.0f;
            prim = GX_QUADS;
            d.y = 0.0f;
            d.z = -p->_1C / 2;
        }
        alpha = p->_24 * p->_4A / p->_28;
        if (alpha > p->_24) {
            alpha = p->_24;
        }
        p->color[3] = alpha;
        GXBegin(prim, GX_VTXFMT0, 8);
        GXPosition3f32(p->pos.x + d.x - d.z, p->pos.y, p->pos.z + d.z + d.x);
        GXColor1u32(p->rgba);
        GXTexCoord2f32(0.0f, 0.0f);
        GXPosition3f32(p->pos.x + d.x + d.z, p->pos.y, p->pos.z + d.z - d.x);
        GXColor1u32(p->rgba);
        GXTexCoord2f32(1.0f, 0.0f);
        GXPosition3f32(p->pos.x - d.z, p->pos.y, p->pos.z + d.x);
        GXColor1u32(p->rgba);
        GXTexCoord2f32(0.0f, 0.25f);
        GXPosition3f32(p->pos.x + d.z, p->pos.y, p->pos.z - d.x);
        GXColor1u32(p->rgba);
        GXTexCoord2f32(1.0f, 0.25f);
        GXPosition3f32(p->start.x - d.z, p->start.y, p->start.z + d.x);
        GXColor1u32(p->rgba);
        GXTexCoord2f32(0.0f, 0.75f);
        GXPosition3f32(p->start.x + d.z, p->start.y, p->start.z - d.x);
        GXColor1u32(p->rgba);
        GXTexCoord2f32(1.0f, 0.75f);
        GXPosition3f32(p->start.x - d.x - d.z, p->start.y, p->start.z - d.z + d.x);
        GXColor1u32(p->rgba);
        GXTexCoord2f32(0.0f, 1.0f);
        GXPosition3f32(p->start.x - d.x + d.z, p->start.y, p->start.z - d.z - d.x);
        GXColor1u32(p->rgba);
        GXTexCoord2f32(1.0f, 1.0f);
        p->_4A -= (lbl_80366158._28 == 0);
        if (p->_4A == 0) {
            prev->next = p->next;
            if (tail != NULL) {
                tail->next = (Particle*)p;
            } else {
                dead = (Particle*)p;
            }
            tail = (Particle*)p;
            p->next = NULL;
            e->count--;
        } else {
            prev = (Particle*)p;
            alive++;
        }
        p = (TrailParticle*)prev->next;
    } while (p != NULL);
    if (dead != NULL) {
        fn_80033794(dead);
    }
    return alive == 0;
}

// .text:0x8002E828 size:0x478
BOOL fn_8002E828(void* arg)
{
    Emitter* e = arg;
    Particle* p = e->particles;
    s32 alive = 0;

    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    do {
        p->_4A -= (p->_4A > 0) & (lbl_80366158._28 == 0);
        if (p->_4A > p->_20) {
            p->color[3] = p->_18 * (p->_1C - p->_4A) / p->_20;
        } else {
            p->color[3] = p->_18 * p->_4A / p->_20;
        }
        p->_38 = p->_3C = p->_10 + ((p->_14 - p->_10) * (f32)(p->_1C - p->_4A)) / (f32)p->_1C;
        fn_8003403C(p->_38, p->_3C);
        fn_80033CC8(p, (TexFile*)e->_10);
        alive += p->_4A > 0;
        p = p->next;
    } while (p != NULL);
    return alive == 0;
}

// .text:0x8002E3DC size:0x44C
BOOL fn_8002E3DC(void* arg)
{
    Emitter* e = arg;
    Particle* p = e->particles;
    s32 alive = 0;

    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    do {
        if (lbl_80366158._28 == 0) {
            p->_4A -= (p->_4A > 0) & (lbl_80366158._28 == 0);
            p->color[3] -= p->_18 / p->_1C;
            p->_38 = p->_3C = (p->_14 - p->_10) * ((f32)(p->_1C - p->_4A) / (f32)p->_1C) + p->_10;
        }
        fn_8003403C(p->_38, p->_3C);
        fn_80033CC8(p, (TexFile*)e->_10);
        alive += p->_4A > 0;
        p = p->next;
    } while (p != NULL);
    return alive == 0;
}

// .text:0x8002DC68 size:0x7C
void fn_8002DC68(Vec* pos)
{
    Emitter* e = fn_800339F0(NULL, 9);
    if (e != NULL) {
        memcpy(&e->_24, &e->_18, sizeof(Vec));
        memcpy(&e->_18, pos, sizeof(Vec));
    }
}

// .text:0x8002D82C size:0x43C
// 99.67%: registers only, in the colour and physics loop: the target sets the float
// pointer (r5) before the index (r4); statement and type variants did not change it.
BOOL fn_8002D82C(void* arg)
{
    Emitter* e = arg;
    DriftParticle* p = (DriftParticle*)e->particles;
    s32 alive = 0;
    f32 (*uv)[2] = lbl_800F78C0;
    TexFile* file = (TexFile*)e->_10;
    s32 index = p->tex;
    GXTexObj texObj;
    Vec v;
    GXTlutObj tlutObj;
    TextureDesc* tex;
    Mtx m;
    s32 i;
    s32 c;

    if (file == NULL) {
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    } else {
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR0A0);
        tex = &file->tex[file->tex[index]._1C];
        if (tex->tlut != NULL) {
            GXInitTexObjCI(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE, GX_TLUT0);
            GXInitTlutObj(&tlutObj, tex->tlut, tex->tlutFormat, tex->tlutCount);
            GXLoadTlut(&tlutObj, GX_TLUT0);
        } else {
            GXInitTexObj(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE);
        }
        GXInitTexObjLOD(&texObj, GX_LINEAR, GX_LINEAR, tex->minLOD, tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
        GXLoadTexObj(&texObj, GX_TEXMAP1);
    }
    PSMTXIdentity(m);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCullMode(GX_CULL_NONE);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
    do {
        if (p->remaining != 0) {
            alive++;
            if (p->delay != 0) {
                p->delay -= (lbl_80366158._28 == 0);
            } else {
                PSMTXMultVec(lbl_8017FFE0, (Vec*)p->pos, &v);
                GXBegin(GX_QUADS, GX_VTXFMT0, 4);
                GXPosition3f32(v.x - p->w, v.y - p->h, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(uv[p->texCoords & 3][0], uv[p->texCoords & 3][1]);
                GXPosition3f32(v.x + p->h, v.y - p->w, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(uv[(p->texCoords >> 2) & 3][0], uv[(p->texCoords >> 2) & 3][1]);
                GXPosition3f32(v.x + p->w, v.y + p->h, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(uv[(p->texCoords >> 4) & 3][0], uv[(p->texCoords >> 4) & 3][1]);
                GXPosition3f32(v.x - p->h, v.y + p->w, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(uv[(p->texCoords >> 6) & 3][0], uv[(p->texCoords >> 6) & 3][1]);
                if (lbl_80366158._28 == 0) {
                    p->remaining--;
                    for (i = 0; i < 3; i++) {
                        c = p->color[i] + p->dcolor[i];
                        if (c < 0) {
                            c = 0;
                        } else if (c > 255) {
                            c = 255;
                        }
                        p->color[i] = c;
                        p->accel[i] = p->force[i] / p->mass;
                        p->vel[i] += p->accel[i];
                        p->pos[i] += p->vel[i];
                    }
                    c = p->color[i] + p->dcolor[i];
                    if (c < 0) {
                        c = 0;
                    } else if (c > 255) {
                        c = 255;
                    }
                    p->color[i] = c;
                    if (p->remaining <= e->fadeAge && (u8)p->dcolor[3] == 0) {
                        p->dcolor[3] = -0x100 / p->remaining;
                    }
                }
            }
        }
        p = (DriftParticle*)p->next;
    } while (p != NULL);
    GXLoadPosMtxImm(lbl_8017FFE0, GX_PNMTX0);
    return alive == 0;
}

// .text:0x8002CDD0 size:0x7C
void fn_8002CDD0(Vec* pos)
{
    Emitter* e = fn_800339F0(NULL, 10);
    if (e != NULL && e->_40 != 0) {
        e->_24.x = pos->x;
        e->_24.y = pos->y;
        e->_24.z = pos->z;
        PSVECSubtract(&e->_24, &e->_18, &e->_30);
    }
}

// .text:0x8002C2D0 size:0x29C
void fn_8002C2D0(Vec* pos, Vec* dir, EffectParams* params)
{
    Emitter* e = fn_800339F0(NULL, 5);

    if (e != NULL) {
        u8 tmp[sizeof(Emitter)];
        Emitter* added = fn_800337CC((Emitter*)tmp, params->count, TRUE);
        if (added != NULL) {
            Particle* p;
            fn_8002BC84(added, pos, dir, params);
            p = e->particles;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = added->particles;
            e->count += added->count;
        }
    } else {
        e = fn_80033A24(fn_80031034, 0x11, 0, params->count, TRUE, 5);
        if (e != NULL) {
            e->state = 0;
            fn_8002BC84(e, pos, dir, params);
        }
    }
}

// .text:0x8002BC84 size:0x64C
void fn_8002BC84(Emitter* e, Vec* pos, Vec* dir, EffectParams* params)
{
    SwirlParticle* p = (SwirlParticle*)e->particles;
    Vec v[2] = { { 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
    Mtx m;
    f32 angle;
    f32 speed;
    f32 speedRange;
    f32 w;
    f32 rot;
    f32 s;
    f32 c;

    e->_10 = params->_00;
    speed = params->_0C[10] / 100000.0f;
    speedRange = (params->_0C[11] - params->_0C[10]) / 100000.0f;
    PSVECNormalize(dir, &v[1]);
    rot = acos(PSVECDotProduct(&v[0], &v[1]));
    PSVECCrossProduct(&v[0], &v[1], &v[1]);
    PSMTXRotAxisRad(m, &v[1], rot);
    angle = 360.0f * rand() / params->count / 32767.0f;
    w = params->_0C[0] / 100000.0f;
    do {
        if (params->count == 1) {
            memcpy(&p->pos, pos, sizeof(Vec));
            memcpy(&p->vel, dir, sizeof(Vec));
            PSVECScale(&p->vel, params->_0C[1] / 100000.0f * (0.95f + 0.1f * rand() / 32767.0f), &p->vel);
        } else {
            v[1].x = 0.0f;
            v[1].y = cos(angle);
            v[1].z = sin(angle);
            angle += 360.0f / params->count;
            PSMTXMultVec(m, &v[1], &v[1]);
            PSVECScale(&v[1], params->_0C[12] / 100000.0f, &v[1]);
            PSVECAdd(pos, &v[1], &p->pos);
            PSVECScale(&v[1], speed + speedRange * rand() / 32767.0f, &p->vel);
            PSVECScale(dir, params->_0C[1] / 100000.0f * (0.95f + 0.1f * rand() / 32767.0f), &v[1]);
            PSVECAdd(&p->vel, &v[1], &p->vel);
        }
        rot = 3.1415927f * (params->_0C[8] / 100000.0f) / 180.0f * (0x3FFF - rand()) / 32767.0f;
        s = sin(rot);
        c = cos(rot);
        p->_38 = w * (s - c);
        p->_3C = w * (c + s);
        p->_1C = 0.01f * (8 - rand() % 16) + params->_0C[0] / 100000.0f;
        p->_20 = params->_0C[5] / 100000.0f;
        p->_24 = params->_0C[6] / 100000.0f;
        p->_2C = params->_0C[3] - params->_0C[4];
        rot = lbl_803CB80C;
        p->_28 = params->_0C[2] / 100000.0f * (1.0f - 0.01f * rot + 0.02 * rot * (rand() % 256) / 256.0);
        p->rgba = params->_0C[9];
        p->_30 = params->_0C[7];
        p->_34 = 0.0f;
        p->_44 = 0;
        p->delay = p->remaining = params->_0C[3];
        p->_4C = 1;
        p->_4E = 0;
        p->tex = params->_04;
        p->_4F = 0;
        p = (SwirlParticle*)p->next;
    } while (p != NULL);
}

// .text:0x8002B7F8 size:0x48C
// 99.60%: registers only; the target leaves the first fn_800337CC result in r4 and copies it
// to r30 after the glow test, where this build allocates it to r30 directly.
void fn_8002B7F8(Vec* pos, SparkParams* params, u8 glow)
{
    u8 tmp[sizeof(Emitter)];
    u8 tmp2[sizeof(Emitter)];
    Emitter* e;

    if (g_d_GameSettings._55 != 0) {
        return;
    }
    e = fn_800339F0(NULL, 14);
    if (e != NULL) {
        Emitter* added = fn_800337CC((Emitter*)tmp, params->sparkCount, TRUE);
        if (added != NULL) {
            Particle* p;
            if (glow && params->glowCount != 0) {
                Emitter* g = fn_800337CC((Emitter*)tmp2, params->glowCount, TRUE);
                if (g == NULL) {
                    added->glow.list = NULL;
                    added->glow.count = 0;
                } else {
                    added->glow.list = g->particles;
                    added->glow.count = g->count;
                }
            } else {
                added->glow.list = NULL;
                added->glow.count = 0;
            }
            fn_8002B400(added, params, pos);
            p = e->particles;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = added->particles;
            e->count += params->sparkCount;
            p = e->glow.list;
            if (p != NULL) {
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = added->glow.list;
            } else {
                e->glow.list = added->glow.list;
            }
            e->glow.count += added->glow.count;
        }
    } else {
        e = fn_80033A24((BOOL (*)(void*))fn_8002B014, 0x80, 0, params->sparkCount, TRUE, 14);
        if (e != NULL) {
            e->_10 = params->_00;
            if (glow) {
                Emitter* g = fn_800337CC((Emitter*)tmp, params->glowCount, TRUE);
                if (g == NULL) {
                    return;
                }
                e->glow.list = g->particles;
                e->glow.count = params->glowCount;
            } else {
                e->glow.list = NULL;
                e->glow.count = 0;
            }
            fn_8002B400(e, params, pos);
        }
    }
}

// .text:0x8002B400 size:0x3F8
// 98.46%: registers only, in the spark loop's scratch registers (an extra li for the 2
// stored to _4C shifts them by one); declaration orders and forms of the zero tried.
void fn_8002B400(Emitter* e, SparkParams* params, Vec* pos)
{
    SparkParticle* p = (SparkParticle*)e->particles;
    s16 delay;
    GlowParticle* q;
    s32 i = 0;

    do {
        p->texCoord = delay = 0;
        p->remaining = params->sparkLife;
        p->tex = params->sparkTex;
        p->w = p->h = params->size[0];
        p->color[2] = 0xFF;
        p->color[1] = 0xFF;
        p->color[0] = 0xFF;
        p->color[3] = params->alpha[0];
        p->_4C = 2;
        p->pos.x = pos->x;
        p->pos.y = -0.1 + -pos->y;
        p->pos.z = pos->z;
        p->switchAge = params->sparkSwitch;
        p->life = params->sparkLife;
        p->growA = (params->size[1] - params->size[0]) / p->switchAge;
        p->fadeA = (params->alpha[1] - params->alpha[0]) / p->switchAge;
        p->growB = (params->size[2] - params->size[1]) / (p->life - p->switchAge);
        p->fadeB = (params->alpha[2] - params->alpha[1]) / (p->life - p->switchAge);
        p->delay = delay;
        p = (SparkParticle*)p->next;
    } while (p != NULL);

    for (q = (GlowParticle*)e->glow.list; q != NULL; q = (GlowParticle*)q->next) {
        q->texCoord = 0;
        q->remaining = params->glowLife;
        q->tex = params->glowTex;
        q->w = params->glowW[0];
        q->h = params->glowH[0];
        q->color[2] = 0xFF;
        q->color[1] = 0xFF;
        q->color[0] = 0xFF;
        q->color[3] = params->glowAlpha[0];
        q->_4C = 1;
        q->pos.x = params->radius * (f32)cos(0.017453292f * params->angle + i * (0.017453292f * (params->arc / params->glowCount))) + pos->x;
        q->pos.y = -0.1 + (-pos->y - q->h * 0.5f);
        q->pos.z = params->radius * (f32)sin(0.017453292f * params->angle + i * (0.017453292f * (params->arc / params->glowCount))) + pos->z;
        i++;
        q->switchAge = params->glowSwitch;
        q->life = params->glowLife;
        q->growHA = (params->glowH[1] - params->glowH[0]) / q->switchAge;
        q->growWA = (params->glowW[1] - params->glowW[0]) / q->switchAge;
        q->fadeA = (params->glowAlpha[1] - params->glowAlpha[0]) / q->switchAge;
        q->growHB = (params->glowH[2] - params->glowH[1]) / (q->life - q->switchAge);
        q->growWB = (params->glowW[2] - params->glowW[1]) / (q->life - q->switchAge);
        q->fadeB = (params->glowAlpha[2] - params->glowAlpha[1]) / (q->life - q->switchAge);
        q->delay = delay;
        delay += 2;
    }
}

// .text:0x8002B014 size:0x3EC
// 94.55%: registers differ through the inlined fn_80031F34, whose own copy keeps n and its
// countdown in separate registers (see its comment); the control flow matches.
BOOL fn_8002B014(Emitter* e)
{
    s32 alive = 0;
    Particle* p;
    Particle* prev;
    Particle* tail;
    Particle* dead;

    if (e->count != 0) {
        p = e->particles = fn_80031F34(e->particles, e->count);
        prev = (Particle*)&e->particles;
        tail = NULL;
        dead = NULL;
        do {
            if (p->_4A != 0) {
                if (p->_48 <= 0) {
                    if (fn_8002AC68(e, (SparkParticle*)p)) {
                        prev->next = p->next;
                        if (tail != NULL) {
                            tail->next = p;
                        } else {
                            dead = p;
                        }
                        tail = p;
                        p->next = NULL;
                        e->count--;
                    } else {
                        prev = p;
                        alive++;
                    }
                } else {
                    prev = p;
                    p->_48--;
                    alive++;
                }
            }
            p = prev->next;
        } while (p != NULL);
        if (dead != NULL) {
            for (p = dead; p != NULL; p = p->next) {
                p->_4C = 0;
                p->_48 = 0;
            }
            fn_80033794(dead);
        }
    }
    if (e->glow.count != 0) {
        p = e->glow.list = fn_80031F34(e->glow.list, e->glow.count);
        prev = (Particle*)&e->glow.list;
        tail = NULL;
        dead = NULL;
        do {
            if (p->_4A != 0) {
                if (p->_48 <= 0) {
                    if (fn_8002A85C(e, (GlowParticle*)p)) {
                        prev->next = p->next;
                        if (tail != NULL) {
                            tail->next = p;
                        } else {
                            dead = p;
                        }
                        tail = p;
                        p->next = NULL;
                        e->glow.count--;
                    } else {
                        prev = p;
                        alive++;
                    }
                } else {
                    prev = p;
                    p->_48--;
                    alive++;
                }
            }
            p = prev->next;
        } while (p != NULL);
        if (dead != NULL) {
            for (p = dead; p != NULL; p = p->next) {
                p->_4C = 0;
                p->_48 = 0;
            }
            fn_80033794(dead);
        }
    }
    return alive == 0;
}

// .text:0x8002AC68 size:0x3AC
// 99.49%: the target keeps the texture file in r30 and the texture index in r29 through the
// inlined fn_80033B58; this swaps them. Locals for either did not move it.
u8 fn_8002AC68(Emitter* e, SparkParticle* p)
{
    Vec quad[4];
    s32 i;
    s32 alpha;

    quad[0].x = -p->w / 2;
    quad[0].z = p->h / 2;
    quad[1].x = p->w / 2;
    quad[1].z = p->h / 2;
    quad[2].x = p->w / 2;
    quad[2].z = -p->h / 2;
    quad[3].x = -p->w / 2;
    quad[3].z = -p->h / 2;
    quad[0].y = quad[1].y = quad[2].y = quad[3].y = 0.0f;
    fn_80033B58((TexFile*)e->_10, p->tex, GX_CLAMP, GX_CLAMP);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_DSTALPHA, GX_LO_CLEAR);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (i = 0; i < 4; i++) {
        GXPosition3f32(p->pos.x + quad[i].x, p->pos.y + quad[i].y, p->pos.z + quad[i].z);
        GXColor1u32(*(u32*)p->color);
        GXTexCoord2f32(lbl_800F7860[p->texCoord + i][0], lbl_800F7860[p->texCoord + i][1]);
    }
    GXEnd();
    alpha = p->color[3];
    if (p->life - p->remaining < p->switchAge) {
        p->w += p->growA;
        p->h = p->w;
        alpha += p->fadeA;
    } else {
        p->w += p->growB;
        p->h = p->w;
        alpha += p->fadeB;
    }
    if (alpha < 0) {
        alpha = 0;
    }
    if (alpha > 255) {
        alpha = 255;
    }
    p->color[3] = alpha;
    p->remaining--;
    return p->remaining == 0;
}

// .text:0x8002A85C size:0x40C
u8 fn_8002A85C(Emitter* e, GlowParticle* p)
{
    s32 alpha;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_DSTALPHA, GX_LO_CLEAR);
    fn_8003403C(p->w, p->h);
    fn_80033CC8((Particle*)p, (TexFile*)e->_10);
    alpha = p->color[3];
    if (p->life - p->remaining < p->switchAge) {
        p->w += p->growWA;
        p->h += p->growHA;
        alpha += p->fadeA;
        p->pos.y -= p->growHA / 2;
    } else {
        p->w += p->growWB;
        p->h += p->growHB;
        alpha += p->fadeB;
        p->pos.y -= p->growHB / 2;
    }
    if (alpha < 0) {
        alpha = 0;
    }
    if (alpha > 255) {
        alpha = 255;
    }
    p->color[3] = alpha;
    p->remaining--;
    return p->remaining == 0;
}

// .text:0x8002A1CC size:0x690
// 95.07%: first draft; the head's parameter loads come in another order and the
// emitter and particle sit one saved register off. Not yet tuned.
void fn_8002A1CC(Vec* pos, StreakParams* params)
{
    Emitter* e = fn_80033A24(fn_80029CC8, 0x80, 0, params->count, TRUE, 11);
    StreakParticle* p;
    f32 step;
    f32 yaw;
    f32 speed;
    f32 accel;
    f32 width;
    f32 widthRange;
    f32 widthEnd;
    f32 widthEndRange;
    f32 length;
    f32 lengthRange;
    f32 lengthEnd;
    f32 lengthEndRange;
    f32 pitch;
    f32 accelRange;
    f32 speedRange;
    s32 n;
    s32 lifeRange;

    if (e != NULL) {
        e->_10 = params->_00;
        memcpy(&e->_18, pos, sizeof(Vec));
        speed = params->speed[0] / 100000.0f;
        accel = params->accel[0] / 100000.0f;
        width = params->width[0] / 100000.0f;
        widthEnd = params->widthEnd[0] / 100000.0f;
        length = params->length[0] / 100000.0f;
        speedRange = params->speed[1] / 100000.0f - speed;
        accelRange = params->accel[1] / 100000.0f - accel;
        widthRange = params->width[1] / 100000.0f - width;
        widthEndRange = params->widthEnd[1] / 100000.0f - widthEnd;
        lengthRange = params->length[1] / 100000.0f - length;
        n = params->undelayed;
        lifeRange = params->life[1] - params->life[0];
        lengthEnd = params->lengthEnd[0] / 100000.0f;
        lengthEndRange = params->lengthEnd[1] / 100000.0f - lengthEnd;
        yaw = pitch = -180.0f;
        p = (StreakParticle*)e->particles;
        step = 360.0f / (s32)(f32)sqrt(params->undelayed);
        do {
            p->tex = params->tex;
            if (n-- != 0) {
                p->delay = 0;
            } else {
                p->delay = (params->delay * rand()) / 32767;
            }
            p->life = p->remaining = params->life[0] + (lifeRange * rand()) / 32767;
            memcpy(&p->pos, pos, sizeof(Vec));
            fn_800332B8(NULL, &p->vel, yaw, yaw + step, pitch, pitch + step);
            yaw += step;
            if (yaw >= 180.0f) {
                pitch += step;
                yaw -= 360.0f;
                if (pitch >= 180.0f) {
                    pitch -= 360.0f;
                }
            }
            PSVECScale(&p->vel, accel + (accelRange * rand()) / 32767.0f, &p->accel);
            PSVECScale(&p->vel, speed + (speedRange * rand()) / 32767.0f, &p->vel);
            p->width = width + (widthRange * rand()) / 32767.0f;
            p->length = length + (lengthRange * rand()) / 32767.0f;
            p->dwidth = widthEnd + (widthEndRange * rand()) / 32767.0f - p->width;
            p->dlength = lengthEnd + (lengthEndRange * rand()) / 32767.0f - p->length;
            p->rgba = params->rgba;
            p->alpha = p->color[3];
            p = (StreakParticle*)p->next;
        } while (p != NULL);
    }
}

// .text:0x80029CC8 size:0x504
// 97.19%: stack layout and saved registers: the target puts side and dir between quad and
// texObj and keeps &side and &quad[1..3] in four saved registers (this build: three).
BOOL fn_80029CC8(void* arg)
{
    Emitter* e = arg;
    Mtx m = { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };
    s32 alive;
    Vec quad[4];
    Vec side;
    Vec dir;
    GXTexObj texObj;
    Vec target;
    Vec v;
    GXTlutObj tlutObj;
    TexFile* file;
    StreakParticle* p;
    s32 index;
    TextureDesc* tex;
    s32 t;
    f32 width;

    alive = e->count;
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
    PSMTXMultVec(lbl_8017FFE0, &e->_18, &target);
    file = (TexFile*)e->_10;
    p = (StreakParticle*)e->particles;
    index = p->tex;
    if (file == NULL) {
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    } else {
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR0A0);
        tex = &file->tex[file->tex[index]._1C];
        if (tex->tlut != NULL) {
            GXInitTexObjCI(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE, GX_TLUT0);
            GXInitTlutObj(&tlutObj, tex->tlut, tex->tlutFormat, tex->tlutCount);
            GXLoadTlut(&tlutObj, GX_TLUT0);
        } else {
            GXInitTexObj(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE);
        }
        GXInitTexObjLOD(&texObj, GX_LINEAR, GX_LINEAR, tex->minLOD, tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
        GXLoadTexObj(&texObj, GX_TEXMAP1);
    }
    for (; p != NULL; p = (StreakParticle*)p->next) {
        if (p->delay != 0) {
            p->delay--;
        } else if (p->remaining != 0) {
            PSVECAdd(&p->vel, &p->accel, &p->vel);
            PSVECAdd(&p->pos, &p->vel, &p->pos);
            p->color[3] = p->alpha * p->remaining / p->life;
            if (target.z <= -1.0f) {
                PSMTXMultVec(lbl_8017FFE0, &p->pos, &v);
                dir.z = v.z;
                dir.x = target.x * v.z / target.z;
                dir.y = target.y * v.z / target.z;
                PSVECSubtract(&v, &dir, &dir);
                dir.z = 0.0f;
                side.x = -dir.y;
                side.y = dir.x;
                side.z = 0.0f;
                t = p->life - p->remaining;
                width = p->width + p->dwidth * t / p->life;
                PSVECScale(&dir, p->length + p->dlength * t / p->life, &dir);
                PSVECScale(&side, width / 2, &side);
                PSVECAdd(&v, &side, &quad[0]);
                PSVECSubtract(&v, &side, &quad[1]);
                PSVECSubtract(&quad[1], &dir, &quad[2]);
                PSVECSubtract(&quad[0], &dir, &quad[3]);
                GXBegin(GX_QUADS, GX_VTXFMT0, 4);
                GXPosition3f32(quad[0].x, quad[0].y, quad[0].z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(0.0f, 1.0f);
                GXPosition3f32(quad[1].x, quad[1].y, quad[1].z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(0.0f, 0.0f);
                GXPosition3f32(quad[2].x, quad[2].y, quad[2].z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(1.0f, 0.0f);
                GXPosition3f32(quad[3].x, quad[3].y, quad[3].z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(1.0f, 1.0f);
            }
            p->remaining--;
        } else {
            alive--;
        }
    }
    GXLoadPosMtxImm(lbl_8017FFE0, GX_PNMTX0);
    return alive == 0;
}

// .text:0x800297F0 size:0x4D8
void fn_800297F0(Emitter* e, Vec* pos, Vec* dir, PuffParams* params)
{
    PuffParticle* p;
    s32 lifeRange;
    f32 yaw;
    f32 speed;
    f32 speedRange;
    f32 size;
    f32 sizeRange;
    f32 spin;
    f32 spinRange;
    f32 gravity;
    f32 yawStep;
    f32 pitchStep;
    f32 pitch;
    f32 step;
    s32 fade;
    u8 alpha;

    e->_10 = params->_00;
    lifeRange = params->life[1] - params->life[0];
    p = (PuffParticle*)e->particles;
    speed = params->speed[0] / 100000.0f;
    speedRange = params->speed[1] / 100000.0f - speed;
    size = params->size[0] / 100000.0f;
    sizeRange = params->size[1] / 100000.0f - size;
    spin = params->spin[0] / 100000.0f / 360.0f;
    spinRange = params->spin[1] / 100000.0f / 360.0f - spin;
    gravity = params->gravity / 100000.0f;
    if (dir != NULL) {
        yaw = params->yaw[0] / 100000.0f;
        yawStep = (params->yaw[1] - params->yaw[0]) / 100000.0f;
        pitch = params->pitch[0] / 100000.0f;
        pitchStep = (params->pitch[1] - params->pitch[0]) / 100000.0f;
    } else {
        step = 360.0f / (s32)(f32)sqrt(params->count);
        yaw = pitch = -180.0f;
        pitchStep = step;
        yawStep = step;
    }
    alpha = params->_30;
    if (params->_38 != 0) {
        fade = (alpha + params->_38 - 1) / params->_38;
    } else {
        fade = 0;
    }
    do {
        p->tex = params->tex;
        p->delay = 0;
        p->life = params->life[0] + (lifeRange * rand()) / 32767;
        p->size = size + (sizeRange * rand()) / 32767.0f;
        p->pos.x = pos->x;
        p->pos.y = pos->y - p->size / 2;
        p->pos.z = pos->z;
        fn_800332B8(dir, &p->vel, yaw, yaw + yawStep, pitch, pitch + pitchStep);
        if (dir == NULL) {
            yaw += yawStep;
            if (yaw >= 180.0f) {
                pitch += pitchStep;
                yaw -= 360.0f;
                if (pitch >= 180.0f) {
                    pitch -= 360.0f;
                }
            }
        } else {
            pitch = -(pitch + pitchStep);
        }
        PSVECScale(&p->vel, speed + (speedRange * rand()) / 32767.0f, &p->vel);
        p->accel.x = 0.0f;
        p->accel.z = 0.0f;
        p->accel.y = gravity;
        p->phase = p->spin = spin + (spinRange * rand()) / 32767.0f;
        p->_34 = params->_30;
        p->maxAlpha = alpha;
        p->fadeIn = params->_34;
        p->fadeOut = params->_38;
        p->fadeAge = fade;
        p->additive = params->_3C;
        p->depthTest = params->_50;
        p = (PuffParticle*)p->next;
    } while (p != NULL);
}

// .text:0x8002955C size:0x294
void fn_8002955C(Vec* pos, Vec* dir, PuffParams* params)
{
    Emitter* e = fn_800339F0(NULL, 12);

    if (e != NULL) {
        u8 tmp[sizeof(Emitter)];
        Emitter* added = fn_800337CC((Emitter*)tmp, params->count, TRUE);
        if (added != NULL) {
            Particle* p;
            fn_800297F0(added, pos, dir, params);
            p = e->particles;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = added->particles;
            e->count += added->count;
        }
    } else {
        e = fn_80033A24(fn_80028F48, 0x80, 0, params->count, TRUE, 12);
        if (e != NULL) {
            fn_800297F0(e, pos, dir, params);
        }
    }
}

// .text:0x80028F48 size:0x614
// 99.77%: registers only: the target keeps half in f30 and gives the two table lookups
// other scratch registers (r0, r6), the residue fn_800332B8's yaw lookups show too.
BOOL fn_80028F48(void* arg)
{
    Emitter* e = arg;
    Particle* prev;
    Particle* dead;
    Particle* tail;
    PuffParticle* p = (PuffParticle*)e->particles;
    s32 lastBlend = -1;
    s32 lastDepth = -1;
    s32 lastTex = -1;
    Mtx m = { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };
    GXTexObj texObj;
    Vec v;
    GXTlutObj tlutObj;
    TexFile* file;
    s32 index;
    TextureDesc* tex;
    s32 a;
    s32 ang;
    s32 i;
    f32 half;
    f32 c;
    f32 s;

    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    prev = (Particle*)&e->particles;
    tail = NULL;
    dead = NULL;
    do {
        if (p->delay != 0) {
            p->delay -= (lbl_80366158._28 == 0);
        } else if (p->life > 0) {
            index = p->tex;
            if (index != lastTex) {
                file = (TexFile*)e->_10;
                lastTex = index;
                if (file == NULL) {
                    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
                } else {
                    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR0A0);
                    tex = &file->tex[file->tex[index]._1C];
                    if (tex->tlut != NULL) {
                        GXInitTexObjCI(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE, GX_TLUT0);
                        GXInitTlutObj(&tlutObj, tex->tlut, tex->tlutFormat, tex->tlutCount);
                        GXLoadTlut(&tlutObj, GX_TLUT0);
                    } else {
                        GXInitTexObj(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE);
                    }
                    GXInitTexObjLOD(&texObj, GX_LINEAR, GX_LINEAR, tex->minLOD, tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
                    GXLoadTexObj(&texObj, GX_TEXMAP1);
                }
            }
            if (p->additive != lastBlend) {
                lastBlend = p->additive;
                if (p->additive != 0) {
                    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
                } else {
                    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
                }
            }
            if (p->depthTest != lastDepth) {
                lastDepth = p->depthTest;
                if (p->depthTest != 0) {
                    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
                } else {
                    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
                }
            }
            if (lbl_80366158._28 == 0) {
                PSVECAdd(&p->vel, &p->accel, &p->vel);
                PSVECAdd(&p->pos, &p->vel, &p->pos);
                if (p->pos.y >= -p->size) {
                    p->pos.y = -p->size;
                    p->vel.y = -0.5f * p->vel.y;
                }
                p->phase += p->spin;
                if (p->phase > 2048.0f) {
                    p->phase -= 2048.0f;
                }
                if (p->life < p->fadeAge) {
                    a = p->color[3] - p->fadeOut;
                    a = a < 0 ? 0 : a;
                    p->color[3] = a;
                } else if (p->fadeIn != 0 && p->color[3] < p->maxAlpha) {
                    a = p->color[3] + p->fadeIn;
                    if (a > p->maxAlpha) {
                        a = p->maxAlpha;
                    }
                    p->color[3] = a;
                }
            }
            PSMTXMultVec(lbl_8017FFE0, &p->pos, &v);
            half = p->size / 2;
            ang = 2048.0f * p->phase;
            i = __abs(ang) & 0x7FF;
            if (i >= 0x401) {
                i = 0x800 - i;
            }
            c = half * lbl_8017ED68[i];
            s = half * fn_800335EC(ang);
            GXBegin(GX_QUADS, GX_VTXFMT0, 4);
            GXPosition3f32(v.x + c, v.y + s, v.z);
            GXColor1u32(p->_34);
            GXTexCoord2f32(0.0f, 0.0f);
            GXPosition3f32(v.x + s, v.y - c, v.z);
            GXColor1u32(p->_34);
            GXTexCoord2f32(0.0f, 1.0f);
            GXPosition3f32(v.x - c, v.y - s, v.z);
            GXColor1u32(p->_34);
            GXTexCoord2f32(1.0f, 1.0f);
            GXPosition3f32(v.x - s, v.y + c, v.z);
            GXColor1u32(p->_34);
            GXTexCoord2f32(1.0f, 0.0f);
            p->life -= (lbl_80366158._28 == 0);
        }
        if (p->life == 0) {
            prev->next = p->next;
            if (tail != NULL) {
                tail->next = (Particle*)p;
            } else {
                dead = (Particle*)p;
            }
            tail = (Particle*)p;
            p->next = NULL;
            e->count--;
        } else {
            prev = (Particle*)p;
        }
        p = (PuffParticle*)prev->next;
    } while (p != NULL);
    if (dead != NULL) {
        fn_80033794(dead);
    }
    GXLoadPosMtxImm(lbl_8017FFE0, GX_PNMTX0);
    return e->count == 0;
}

// .text:0x8002852C size:0xFC
void fn_8002852C(void)
{
    LightFlashTask* task = lbl_803CC1B8;

    if (--task->timer == 0) {
        lbl_803CBC70 = 0;
        fn_80023B90(lbl_800F7478[g_d_GameSettings._54].lights, lbl_80367318);
        fn_800B0A14_removeQueue();
        return;
    }
    task->light.r = task->r;
    task->light.g = task->g;
    task->light.b = task->b;
    fn_80023B90(&task->light, lbl_80367318);
    lbl_803C5090._1D = 9;
    lbl_803C5090._00 = 1.0f;
    lbl_803C5090._14 = 448;
    lbl_803C5090._19 = task->_22;
    lbl_803C5090._18 = 1;
    lbl_803C5090._1A = task->r;
    lbl_803C5090._1B = task->g;
    lbl_803C5090._1C = task->b;
    lbl_803C5090._17 = task->_21 * task->timer / task->duration;
}

// .text:0x80027918 size:0x50
// 99.75%: the target stores through the register the inlined fn_800339F0 returns in (r3);
// this stores through its copy (r4). Loop forms and fn_800339F0 variants did not move it.
void fn_80027918(u8 id, f32 v)
{
    Emitter* e = NULL;
    while ((e = fn_800339F0(e, id)) != NULL) {
        e->_18.y = v;
    }
}

// .text:0x80027674 size:0x2A4
void fn_80027674(Vec* pos, Vec* dir, EffectParams* params, f32 scale, u8 id)
{
    Emitter* e = fn_800339F0(NULL, id);

    if (e != NULL) {
        u8 tmp[sizeof(Emitter)];
        Emitter* added = fn_800337CC((Emitter*)tmp, params->count, TRUE);
        if (added != NULL) {
            Particle* p;
            fn_80027300(added, pos, dir, params, scale);
            p = e->particles;
            while (p != NULL && p->next != NULL) {
                p = p->next;
            }
            p->next = added->particles;
            e->count += added->count;
        }
    } else {
        e = fn_80033A24(fn_80026E58, 0x80, 1, params->count, TRUE, id);
        if (e != NULL) {
            fn_80027300(e, pos, dir, params, scale);
        }
    }
}

// .text:0x80027300 size:0x374
void fn_80027300(Emitter* e, Vec* pos, Vec* dir, EffectParams* params, f32 scale)
{
    BurstEmitter* be = (BurstEmitter*)e;
    BurstParticle* p;
    f32 step;
    f32 yaw;
    f32 grow;
    f32 speed;
    f32 speedRange;
    f32 size;
    f32 sizeRange;
    f32 pitch;
    s32 lifeRange;
    s32 fadeRange;

    be->_10 = params->_00;
    be->_1C = 1.0f;
    be->_20 = params->_04;
    be->dir = dir;
    p = (BurstParticle*)e->particles;
    step = 360.0f / (s32)(f32)sqrt(params->count);
    lifeRange = params->_0C[2] - params->_0C[1];
    fadeRange = params->_0C[4] - params->_0C[3];
    speed = params->_0C[5] / 100000.0f;
    speedRange = params->_0C[6] / 100000.0f - speed;
    size = params->_0C[7] / 100000.0f;
    sizeRange = params->_0C[8] / 100000.0f - size;
    grow = params->_0C[0] / 100000.0f;
    yaw = pitch = -180.0f;
    do {
        fn_800332B8(NULL, &p->pos, yaw, yaw + step, pitch, pitch + step);
        yaw += step;
        if (yaw >= 180.0f) {
            pitch += step;
            yaw -= 360.0f;
            if (pitch >= 180.0f) {
                pitch -= 360.0f;
            }
        }
        PSVECScale(&p->pos, scale, &p->pos);
        PSVECAdd(pos, &p->pos, &p->pos);
        p->_10 = speed + (speedRange * rand()) / 32767.0f;
        p->_14 = size + (sizeRange * rand()) / 32767.0f;
        p->_18 = grow;
        p->_1C = params->_0C[12];
        p->_22 = p->_20 = params->_0C[1] + (lifeRange * rand()) / 32767;
        p->_24 = params->_0C[3] + (fadeRange * rand()) / 32767;
        p->_2A = params->_0C[9];
        p->_26 = params->_0C[10];
        p->_28 = params->_0C[11];
        p->_1C = params->_0C[12];
        p = p->next;
    } while (p != NULL);
}

// .text:0x80026E58 size:0x4A8
BOOL fn_80026E58(void* arg)
{
    Emitter* e = arg;
    BurstEmitter* be = arg;
    BurstParticle* p;
    s32 done = 0;
    Mtx m = { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };
    GXTexObj texObj;
    Vec d;
    Vec c;
    GXTlutObj tlutObj;
    TexFile* file;
    s32 index;
    TextureDesc* tex;
    s32 alpha;

    p = (BurstParticle*)e->particles;
    if (be->_1C > 0.0f) {
        GXLoadPosMtxImm(m, GX_PNMTX0);
        GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
        file = (TexFile*)e->_10;
        index = be->_20;
        if (file == NULL) {
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
        } else {
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR0A0);
            tex = &file->tex[file->tex[index]._1C];
            if (tex->tlut != NULL) {
                GXInitTexObjCI(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE, GX_TLUT0);
                GXInitTlutObj(&tlutObj, tex->tlut, tex->tlutFormat, tex->tlutCount);
                GXLoadTlut(&tlutObj, GX_TLUT0);
            } else {
                GXInitTexObj(&texObj, tex->image, tex->width, tex->height, tex->format, GX_CLAMP, GX_CLAMP, GX_FALSE);
            }
            GXInitTexObjLOD(&texObj, GX_LINEAR, GX_LINEAR, tex->minLOD, tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
            GXLoadTexObj(&texObj, GX_TEXMAP1);
        }
        c.x = be->dir->x;
        c.y = be->dir->y;
        c.z = be->dir->z;
        do {
            if (p->_24 > 0) {
                p->_24 -= (lbl_80366158._28 == 0);
            } else if (p->_20 > 0) {
                if (lbl_80366158._28 == 0) {
                    p->_10 += p->_14;
                    PSVECSubtract(&p->pos, &c, &d);
                    PSVECScale(&d, p->_10, &d);
                    PSVECAdd(&c, &d, &p->pos);
                }
                PSMTXMultVec(lbl_8017FFE0, &p->pos, &d);
                if (p->_20 > p->_22 - p->_26) {
                    alpha = p->_2A * (p->_22 - p->_20) / p->_26;
                } else if (p->_28 != 0) {
                    alpha = p->_2A * p->_20 / p->_28;
                } else {
                    alpha = p->_2A;
                }
                if (alpha > p->_2A) {
                    alpha = p->_2A;
                }
                p->color[3] = alpha * be->_1C;
                GXBegin(GX_QUADS, GX_VTXFMT0, 4);
                GXPosition3f32(d.x - p->_18, d.y - p->_18, d.z);
                GXColor1u32(p->_1C);
                GXTexCoord2f32(0.0f, 0.0f);
                GXPosition3f32(d.x - p->_18, d.y + p->_18, d.z);
                GXColor1u32(p->_1C);
                GXTexCoord2f32(0.0f, 1.0f);
                GXPosition3f32(d.x + p->_18, d.y + p->_18, d.z);
                GXColor1u32(p->_1C);
                GXTexCoord2f32(1.0f, 1.0f);
                GXPosition3f32(d.x + p->_18, d.y - p->_18, d.z);
                GXColor1u32(p->_1C);
                GXTexCoord2f32(1.0f, 0.0f);
                p->_20 -= (lbl_80366158._28 == 0);
            } else {
                done++;
            }
            p = p->next;
        } while (p != NULL);
        GXLoadPosMtxImm(lbl_8017FFE0, GX_PNMTX0);
    }
    return done == e->count || be->_1C == 0.0f;
}

// .text:0x80026998 size:0x4C0
void fn_80026998(SmokeParams* params)
{
    Emitter* e;

    if (params == NULL) {
        return;
    }
    e = fn_800339F0(NULL, 15);
    if (e != NULL) {
        u8 tmp[sizeof(Emitter)];
        Emitter* added = fn_800337CC((Emitter*)tmp, params->count, TRUE);
        if (added != NULL) {
            Particle* p;
            initSmoke(added, params);
            p = e->particles;
            if (p != NULL) {
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = added->particles;
            } else {
                e->particles = added->particles;
            }
            e->count += added->count;
        }
    } else {
        e = fn_80033A24(fn_800263FC, 0x80, 0, params->count, TRUE, 15);
        if (e != NULL) {
            initSmoke(e, params);
        }
    }
}

// .text:0x800263FC size:0x59C
// 97.60%: registers differ through the inlined fn_80031F34 (see its comment): the target
// keeps its list walk, the sorted head and p all in r28.
BOOL fn_800263FC(void* arg)
{
    Emitter* e = arg;
    s32 alive = 0;
    s32 alpha;
    SmokeParticle* p;
    Particle* prev;
    Particle* tail;
    Particle* dead;

    p = (SmokeParticle*)(e->particles = fn_80031F34(e->particles, e->count));
    prev = (Particle*)&e->particles;
    tail = NULL;
    dead = NULL;
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_DSTALPHA, GX_LO_CLEAR);
    do {
        if (p->remaining != 0) {
            fn_8003403C(p->w, p->h);
            fn_80033CC8((Particle*)p, (TexFile*)e->_10);
            p->w += p->grow;
            p->h = p->w;
            alpha = p->color[3] + p->fade;
            if (alpha > 255) {
                alpha = 255;
            } else if (alpha < 0) {
                alpha = 0;
            }
            p->color[3] = alpha;
            p->pos.x += p->vel.x;
            p->pos.y -= p->vel.y;
            p->pos.z += p->vel.z;
            p->vel.x += p->accel.x;
            p->vel.y += p->accel.y;
            p->vel.z += p->accel.z;
            p->remaining--;
            if (p->remaining == 0) {
                prev->next = p->next;
                if (tail != NULL) {
                    tail->next = (Particle*)p;
                } else {
                    dead = (Particle*)p;
                }
                tail = (Particle*)p;
                p->next = NULL;
                e->count--;
            } else {
                prev = (Particle*)p;
                alive++;
            }
        }
        p = (SmokeParticle*)prev->next;
    } while (p != NULL);
    if (dead != NULL) {
        Particle* q;
        for (q = dead; q != NULL; q = q->next) {
            q->_4C = 0;
            q->_48 = 0;
        }
        fn_80033794(dead);
    }
    return alive == 0;
}
