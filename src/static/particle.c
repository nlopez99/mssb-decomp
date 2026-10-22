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
    /* 0x3C */ s32 _3C;
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
    union {
        /* 0x44 */ s8 dcolor[4];
        /* 0x44 */ u32 drgba;
    };
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 remaining;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 tex;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 texCoords;
} DriftParticle;

// The particles fn_8002C56C moves along an arc in three phases
typedef struct ArcParticle {
    /* 0x00 */ Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ f32 w;
    /* 0x20 */ f32 h;
    /* 0x24 */ f32 velScale;
    /* 0x28 */ f32 velScaleEnd;
    /* 0x2C */ f32 posScale;
    union {
        /* 0x30 */ u32 rgba;
        /* 0x30 */ u8 color[4];
    };
    /* 0x34 */ f32 spin;
    /* 0x38 */ u16 texCoords;
    /* 0x3A */ u16 delay;
    /* 0x3C */ u16 t[3];
    /* 0x42 */ u16 dur[3];
    /* 0x48 */ u16 fade;
} ArcParticle;

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

typedef struct RibbonEmitter {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ TexFile* file;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ f32 _18[12];
    /* 0x48 */ void* _48;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 _4F;
    /* 0x50 */ s32 _50;
    /* 0x54 */ u8 _54;
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
} RibbonEmitter;

typedef struct RibbonLink {
    /* 0x00 */ struct RibbonLink* next;
    /* 0x04 */ struct RibbonLink* prev;
    /* 0x08 */ Vec pts[7];
} RibbonLink;

typedef struct RibbonParticle {
    /* 0x00 */ RibbonLink* next;
    /* 0x04 */ RibbonLink* tail;
    /* 0x08 */ Vec pts[4];
    /* 0x38 */ f32 grav;
    union {
        /* 0x3C */ u32 rgba;
        /* 0x3C */ u8 color[4];
    };
    /* 0x40 */ Vec vel;
    /* 0x4C */ f32 drag;
    /* 0x50 */ s16 _50;
    /* 0x52 */ s16 _52;
    /* 0x54 */ u16 _54;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 links;
    /* 0x58 */ u8 head;
    /* 0x59 */ u8 linkHead;
    /* 0x5A */ u8 len;
    /* 0x5B */ u8 filled;
} RibbonParticle;

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
    union {
        /* 0x40 */ s32 rgba;
        /* 0x40 */ u8 color[4];
    };
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

extern LightFlashTask* lbl_803CBC70;
extern LightFlashTask* lbl_803CC1B8;
extern StadiumLights lbl_800F7478[14];
extern u8 lbl_80367318[];
extern s32 lbl_803CB800;
extern f32 lbl_803CB804;
extern f32 lbl_803CB80C;
extern s32 lbl_803CB7F8;
extern s32 lbl_803CB808;
extern f32 lbl_803CB7FC;
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
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), u16 priority);
extern void fn_8003A540(s32 value);
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
static Vec lbl_8017EC90[18];
static u32 lbl_8017EC48[18];
static f32 lbl_8017EC00[18];

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

static inline void stepDrift(DriftParticle* p)
{
    s32 i;
    s32 c;

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
}

// .text:0x800328E0 size:0x7EC
// 99.85%: registers only, in the respawn's second lookup of a: the target computes a + 0x600
// and its absolute value in r6 (r3 here); __abs, abs and hand-written forms change nothing.
BOOL fn_800328E0(void* arg)
{
    ArcEmitter* e = arg;
    s32 r;
    DriftParticle* p = (DriftParticle*)((Emitter*)e)->particles;
    s32 alive = 0;
    s32 a;
    s32 i;
    Quaternion q;
    Vec up = { 0.0f, 1.0f, 0.0f };
    Vec dir;
    Vec axis;
    Vec v;
    Mtx m;
    f32 s;
    f32 angle;
    f32 c2;
    f32 c1;
    f32 speed;
    f32 k;

    fn_8003403C(p->w, p->h);
    memcpy(&dir, &e->end, sizeof(Vec));
    angle = acos(PSVECDotProduct(&up, &dir));
    PSVECCrossProduct(&up, &dir, &axis);
    angle *= 0.5f;
    s = sin(angle);
    q.w = cos(angle);
    q.x = axis.x * s;
    q.y = axis.y * s;
    q.z = axis.z * s;
    PSMTXQuat(m, &q);
    do {
        if (p->delay > 0) {
            p->delay -= (lbl_80366158._28 == 0);
        } else if (p->remaining != 0) {
            if (lbl_80366158._28 == 0) {
                p->force[2] = 0.0f;
                p->force[0] = 0.0f;
                p->force[1] = 0.16344418f * p->mass;
                p->force[0] += 0.001f * (-p->vel[0] * p->mass);
                p->force[1] += 0.001f * (-p->vel[1] * p->mass);
                p->force[2] += 0.001f * (-p->vel[2] * p->mass);
                stepDrift(p);
                if (p->vel[1] > 0.0f && p->pos[1] >= e->_3C) {
                    p->vel[1] *= e->_38;
                    p->remaining--;
                }
                if (fabs(p->pos[0]) > 300.0 || fabs(p->pos[2]) > 300.0) {
                    p->remaining = 0;
                }
            }
            fn_80033CC8((Particle*)p, (TexFile*)e->_10);
        } else if (e->_34 != 0) {
            k = lbl_803CB7FC;
            a = 512.0f * (1.0f - k) + 512.0f * k * rand() / 32767.0f;
            i = a;
            if (i < 0) {
                i = -i;
            }
            i &= 0x7FF;
            if (i >= 0x401) {
                i = 0x800 - i;
            }
            c1 = lbl_8017ED68[i];
            i = __abs(a + 0x600);
            i &= 0x7FF;
            if (i >= 0x401) {
                i = 0x800 - i;
            }
            c2 = lbl_8017ED68[i];
            r = rand();
            speed = e->_30 / 60.0f * ((rand() & 0xF) + 90) / 100.0f;
            speed /= 0.001f;
            p->mass = 0.001f;
            p->pos[0] = e->start.x;
            p->pos[1] = e->start.y;
            p->pos[2] = e->start.z;
            i = r;
            if (i < 0) {
                i = -i;
            }
            i &= 0x7FF;
            if (i >= 0x401) {
                i = 0x800 - i;
            }
            v.x = speed * c1 * lbl_8017ED68[i];
            v.y = -speed * c2;
            v.z = speed * c1 * fn_800335EC(r);
            v.y += 0.16344418f;
            PSMTXMultVec(m, &v, &v);
            p->vel[0] = v.x;
            p->vel[1] = v.y;
            p->vel[2] = v.z;
            p->w = e->_44;
            p->h = e->_44;
            p->rgba = e->_40;
            p->drgba = 0;
            p->remaining = 2;
            p->delay = r & lbl_803CB7F8;
            p->tex = 0xFF;
        } else {
            goto next;
        }
        alive++;
    next:
        p = (DriftParticle*)p->next;
    } while (p != NULL);
    if (e->_34 > 0) {
        e->_34--;
    }
    return alive == 0;
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

// .text:0x80031034 size:0x790
// 99.65%: registers only, in the inlined fn_80031F34. With that helper returning `list`
// (reassigned to the sorted head) this reaches 99.93%, leaving only n in r27 for the target's r22.
BOOL fn_80031034(void* arg)
{
    Emitter* e = arg;
    s32 alive = 0;
    s32 blend;
    Particle* prev;
    SwirlParticle* dead;
    SwirlParticle* tail;
    SwirlParticle* p;
    s32 alpha;
    s32 i;
    f32 r;
    f32 ofs;
    Vec a;
    Vec b;

    GXLoadPosMtxImm(lbl_8017FFE0, GX_PNMTX0);
    GXSetZMode(GX_TRUE, GX_LEQUAL, e->state);
    blend = -1;
    p = (SwirlParticle*)fn_80031F34(e->particles, e->count);
    e->particles = (Particle*)p;
    prev = (Particle*)&e->particles;
    tail = NULL;
    dead = NULL;
    do {
        if (blend != p->_4F) {
            blend = p->_4F;
            if (p->_4F != 0) {
                GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
            } else {
                GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
            }
        }
        if (p->_44 == 0) {
            if (p->_38 * p->_38 > p->_3C * p->_3C) {
                r = p->_1C * p->_38 / 2.0f;
            } else {
                r = p->_1C * p->_3C / 2.0f;
            }
            ofs = r;
            if (r > 0.0f) {
                ofs = -r;
            }
            ofs *= p->_34;
            lbl_80180010[0].x = -p->_1C * p->_38 / 2.0f;
            lbl_80180010[0].y = ofs - p->_1C * p->_3C / 2.0f;
            lbl_80180010[0].z = 0.0f;
            lbl_80180010[1].x = -p->_1C * p->_3C / 2.0f;
            lbl_80180010[1].y = p->_1C * p->_38 / 2.0f + ofs;
            lbl_80180010[1].z = 0.0f;
            lbl_80180010[2].x = p->_1C * p->_38 / 2.0f;
            lbl_80180010[2].y = p->_1C * p->_3C / 2.0f + ofs;
            lbl_80180010[2].z = 0.0f;
            lbl_80180010[3].x = p->_1C * p->_3C / 2.0f;
            lbl_80180010[3].y = ofs - p->_1C * p->_38 / 2.0f;
            lbl_80180010[3].z = 0.0f;
        } else {
            a.x = p->_38 / 2.0f;
            a.y = p->_3C / 2.0f;
            a.z = 0.0f;
            b.x = p->_3C / 2.0f;
            b.y = -p->_38 / 2.0f;
            b.z = 0.0f;
            PSVECAdd(&a, &b, &b);
            PSVECNormalize(&b, &b);
            PSVECScale(&b, p->_34, &b);
            lbl_80180010[0].x = b.x - p->_1C * p->_38 / 2.0f;
            lbl_80180010[0].y = b.y - p->_1C * p->_3C / 2.0f;
            lbl_80180010[0].z = 0.0f;
            lbl_80180010[1].x = b.x - p->_1C * p->_3C / 2.0f;
            lbl_80180010[1].y = p->_1C * p->_38 / 2.0f + b.y;
            lbl_80180010[1].z = 0.0f;
            lbl_80180010[2].x = p->_1C * p->_38 / 2.0f + b.x;
            lbl_80180010[2].y = p->_1C * p->_3C / 2.0f + b.y;
            lbl_80180010[2].z = 0.0f;
            lbl_80180010[3].x = p->_1C * p->_3C / 2.0f + b.x;
            lbl_80180010[3].y = b.y - p->_1C * p->_38 / 2.0f;
            lbl_80180010[3].z = 0.0f;
        }
        if (p->_2C <= p->remaining) {
            if (lbl_80366158._28 == 0) {
                p->_1C *= p->_20;
            }
            alpha = p->_30 * (p->delay - p->remaining) / (p->delay - p->_2C);
        } else {
            if (lbl_80366158._28 == 0) {
                p->_1C *= p->_24;
            }
            alpha = p->_30 * p->remaining / p->_2C;
        }
        for (i = 0; i < 4; i++) {
            PSMTXMultVec(lbl_8017FF78, &lbl_80180010[i], &lbl_80180010[i]);
        }
        fn_80033CC8((Particle*)p, (TexFile*)e->_10);
        if (alpha < 0) {
            p->remaining = 0;
        } else if (lbl_80366158._28 == 0) {
            p->pos.x += p->vel.x;
            p->pos.y += p->vel.y;
            p->pos.z += p->vel.z;
            p->vel.x *= p->_28;
            p->vel.y *= p->_28;
            p->vel.z *= p->_28;
            p->color[3] = alpha;
            p->remaining--;
        }
        if (p->remaining == 0) {
            prev->next = p->next;
            if (tail != NULL) {
                tail->next = (Particle*)p;
            } else {
                dead = p;
            }
            tail = p;
            p->next = NULL;
            e->count--;
        } else {
            prev = (Particle*)p;
            alive++;
        }
        p = (SwirlParticle*)prev->next;
    } while (p != NULL);
    if (dead != NULL) {
        fn_80033794((Particle*)dead);
    }
    return alive == 0;
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

// .text:0x8002DCE4 size:0x6F8
void fn_8002DCE4(Vec* start, Vec* end, DriftParams* params)
{
    f32 speed;
    f32 sizeMin;
    f32 sizeRange;
    f32 yawMin;
    f32 yawMax;
    f32 pitchMin;
    f32 pitchMax;
    f32 angleBase;
    f32 angleRange;
    Vec d;
    Emitter* e;
    DriftParticle* p;
    s32 a;
    f32 size;
    f32 w;
    f32 h;
    s32 i;
    s32 sign = 1;

    yawMin = params->yaw[0] / 100000.0f;
    yawMax = params->yaw[1] / 100000.0f;
    pitchMin = params->pitch[0] / 100000.0f;
    pitchMax = params->pitch[1] / 100000.0f;
    sizeMin = params->size[0] / 100000.0f;
    sizeRange = params->size[1] / 100000.0f - sizeMin;
    angleBase = 45.0f + params->angle[0] / 100000.0f;
    angleRange = (params->angle[1] - params->angle[0]) / 100000.0f;
    PSVECSubtract(end, start, &d);
    speed = params->speed / 100000.0f;
    e = fn_80033A24(fn_8002D82C, 0x80, 0, params->count, TRUE, 9);
    if (e != NULL) {
        e->_10 = params->file;
        e->fadeAge = params->fadeAge;
        memcpy(&e->_18, end, sizeof(Vec));
        memcpy(&e->_24, end, sizeof(Vec));
        p = (DriftParticle*)e->particles;
        do {
            p->delay = rand() % params->delay;
            p->remaining = params->life - p->delay - rand() % params->lifeVar;
            p->pos[0] = start->x;
            p->pos[1] = start->y;
            p->pos[2] = start->z;
            p->vel[0] = d.x / (f32)(p->remaining - 1);
            p->vel[1] = d.y / (f32)(p->remaining - 1);
            p->vel[2] = d.z / (f32)(p->remaining - 1);
            fn_800332B8(NULL, (Vec*)p->force, yawMin, yawMax, pitchMin, pitchMax);
            PSVECScale((Vec*)p->force, speed * (0.5f * (rand() % 256) + 0.75f), (Vec*)p->force);
            p->force[0] *= sign;
            sign = -sign;
            PSVECScale((Vec*)p->force, 0.5f * -p->remaining, (Vec*)p->accel);
            PSVECAdd((Vec*)p->vel, (Vec*)p->accel, (Vec*)p->vel);
            p->mass = 1.0f;
            if (angleRange) {
                a = 2048.0f * (angleBase + angleRange * rand() / 32767.0f) / 360.0f + 0.5f;
                size = 1.4142135f * ((sizeMin + sizeRange * rand() / 32767.0f) / 2.0f);
                i = a;
                if (i < 0) {
                    i = -i;
                }
                i &= 0x7FF;
                if (i >= 0x401) {
                    i = 0x800 - i;
                }
                w = size * lbl_8017ED68[i];
                h = size * fn_800335EC(a);
                p->w = w;
                p->h = h;
                p->texCoords = (rand() & 1) ? 0x1B : 0xE4;
            } else {
                p->h = p->w = (sizeMin + sizeRange * rand() / 32767.0f) / 2.0f;
                p->texCoords = 0xB1;
            }
            p->rgba = 0xFFFFFFFF;
            p->drgba = 0;
            p->tex = params->tex;
            p = (DriftParticle*)p->next;
        } while (p != NULL);
    }
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
                    stepDrift(p);
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

// .text:0x8002CE4C size:0x9E0
// 99.87%: registers only, in the w/h lookups: the target keeps size in f2 and the second
// index in r4 (f1 and r0 here); the lookup and size forms of fn_8002DCE4 change nothing.
void fn_8002CE4C(Vec* start, Vec* end, ArcParams* params)
{
    f32 splitMin;
    f32 splitRange;
    f32 yawMin;
    f32 yawMax;
    f32 pitchMin;
    f32 pitchMax;
    f32 velMin;
    f32 velRange;
    f32 angleMin;
    f32 angleRange;
    f32 sizeMin;
    f32 sizeRange;
    f32 spinMin;
    f32 spinRange;
    f32 vsMin;
    f32 vsRange;
    f32 veMin;
    f32 veRange;
    f32 psMin;
    f32 psRange;
    f32 distMin;
    f32 distRange;
    s32 rise;
    s32 riseRange;
    s32 holdMin;
    s32 holdRange;
    s32 fadeMin;
    s32 fadeRange;
    s32 d;
    s32 a;
    s32 i;
    f32 size;
    f32 w;
    f32 h;
    Vec dir;
    Emitter* e;
    ArcParticle* p;
    s32 sign = 1;

    e = fn_80033A24(fn_8002C56C, 0x80, 0, params->count, TRUE, 10);
    if (e != NULL) {
        rise = params->frames * (params->rise[0] / 100000.0f);
        riseRange = params->frames * (params->rise[1] / 100000.0f) - rise;
        splitMin = params->split[0] / 100000.0f;
        splitRange = (params->split[1] - params->split[0]) / 100000.0f;
        holdMin = params->hold[0];
        holdRange = params->hold[1] - holdMin;
        fadeMin = params->fade[0];
        fadeRange = params->fade[1] - fadeMin;
        yawMin = params->yaw[0] / 100000.0f;
        yawMax = params->yaw[1] / 100000.0f;
        pitchMin = params->pitch[0] / 100000.0f;
        pitchMax = params->pitch[1] / 100000.0f;
        angleMin = params->angle[0] / 100000.0f;
        angleRange = (params->angle[1] - params->angle[0]) / 100000.0f;
        velMin = params->vel[0] / 100000.0f;
        velRange = (params->vel[1] - params->vel[0]) / 100000.0f;
        vsMin = params->velScale[0] / 100000.0f;
        vsRange = (params->velScale[1] - params->velScale[0]) / 100000.0f;
        veMin = params->velScaleEnd[0] / 100000.0f;
        veRange = (params->velScaleEnd[1] - params->velScaleEnd[0]) / 100000.0f;
        sizeMin = params->size[0] / 100000.0f;
        sizeRange = (params->size[1] - params->size[0]) / 100000.0f;
        spinMin = params->spin[0] / 100000.0f;
        spinRange = (params->spin[1] - params->spin[0]) / 100000.0f;
        psMin = params->posScale[0] / 100000.0f;
        psRange = (params->posScale[1] - params->posScale[0]) / 100000.0f;
        distMin = params->dist[0] / 100000.0f;
        distRange = (params->dist[1] - params->dist[0]) / 100000.0f;
        e->_10 = params->file;
        e->_3C = params->tex;
        e->_40 = params->frames;
        e->_18.x = start->x;
        e->_18.y = start->y;
        e->_18.z = start->z;
        e->_24.x = end->x;
        e->_24.y = end->y;
        e->_24.z = end->z;
        PSVECSubtract(end, start, &e->_30);
        p = (ArcParticle*)e->particles;
        do {
            p->delay = params->delay * rand() / 32767;
            d = rise + riseRange * rand() / 32767;
            p->t[0] = p->dur[0] = d * (splitMin + splitRange * rand() / 32767.0f);
            p->t[1] = p->dur[1] = d - p->dur[0];
            p->t[2] = p->dur[2] = holdMin + holdRange * rand() / 32767;
            p->vel.x = velMin + velRange * rand() / 32767.0f;
            p->vel.y = 0.0f;
            p->vel.z = 0.0f;
            fn_800332B8(&p->vel, &p->vel, yawMin, yawMax, pitchMin, pitchMax);
            p->vel.x *= sign;
            sign *= -1;
            PSVECNormalize(&p->vel, &dir);
            PSVECScale(&dir, distMin + distRange * rand() / 32767.0f, &p->pos);
            p->velScale = vsMin + vsRange * rand() / 32767.0f;
            p->velScaleEnd = veMin + veRange * rand() / 32767.0f - p->velScale;
            p->posScale = psMin + psRange * rand() / 32767.0f;
            p->spin = spinMin + spinRange * rand() / 32767.0f;
            a = 0.5f + 2048.0f * (angleMin + angleRange * rand() / 32767.0f) / 360.0f;
            size = 1.4142135f * ((sizeMin + sizeRange * rand() / 32767.0f) / 2.0f);
            i = a;
            if (i < 0) {
                i = -i;
            }
            i &= 0x7FF;
            if (i >= 0x401) {
                i = 0x800 - i;
            }
            w = size * lbl_8017ED68[i];
            h = size * fn_800335EC(a);
            p->w = w;
            p->h = h;
            p->rgba = 0xFFFFFFFF;
            p->texCoords = (rand() & 1) ? 0x123 : 0x321;
            p->fade = fadeMin + fadeRange * rand() / 32767;
            p = (ArcParticle*)p->next;
        } while (p != NULL);
    }
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

static inline f32 arcEase(u16 t, u16 dur)
{
    f32 x = (f32)t / (f32)dur;
    f32 frac = x - (s32)x;
    f32 whole = x - frac;
    s32 n;
    s32 i;

    if (frac > 1.0f) {
        frac -= (s32)frac;
    }
    n = lbl_803CB808;
    while (n != 0) {
        n--;
        i = __abs((s32)(1024.0f * frac)) & 0x7FF;
        if (i >= 0x401) {
            i = 0x800 - i;
        }
        frac = (1.0f - lbl_8017ED68[i]) / 2;
    }
    return whole + frac;
}

// .text:0x8002C56C size:0x864
// 99.98%: the target loads dur[1] before dur[2] for the sum (r8, r9); sum orders, statement
// orders and counter types change nothing.
BOOL fn_8002C56C(void* arg)
{
    Emitter* e = arg;
    ArcParticle* p = (ArcParticle*)e->particles;
    s32 alive = 0;
    f32 (*uv)[2] = lbl_800F78C0;
    TexFile* file = (TexFile*)e->_10;
    s32 index = e->_3C;
    TextureDesc* tex;
    Vec v;
    Vec b;
    Vec a;
    GXTexObj texObj;
    Mtx m;
    GXTlutObj tlutObj;
    Mtx rot;
    u32 elapsed;
    u32 total;
    u16 deg;
    f32 s;
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
    if (lbl_80366158._28 == 0 && e->_40 != 0) {
        e->_40--;
    }
    do {
        if (p->t[2] != 0) {
            alive++;
            total = p->dur[0] + p->dur[1] + p->dur[2];
            elapsed = total - (p->t[0] + p->t[1] + p->t[2]);
            if (p->delay != 0) {
                p->delay -= (lbl_80366158._28 == 0);
            } else {
                if (p->t[0] != 0) {
                    s = 1.0f - arcEase(p->t[0], p->dur[0]);
                    PSVECAdd(&e->_30, &p->pos, &a);
                    PSVECScale(&a, p->posScale * s, &v);
                    PSVECScale(&p->vel, p->velScale * s, &b);
                    p->t[0] -= (lbl_80366158._28 == 0);
                } else if (p->t[1] != 0) {
                    s = arcEase(p->t[1], p->dur[1]);
                    PSVECAdd(&e->_30, &p->pos, &a);
                    PSVECScale(&a, 1.0 - s + p->posScale * s, &v);
                    PSVECScale(&p->vel, p->velScale * s, &b);
                    p->t[1] -= (lbl_80366158._28 == 0);
                } else {
                    s = arcEase(p->t[2], p->dur[2]);
                    PSVECAdd(&e->_30, &p->pos, &a);
                    memcpy(&v, &a, sizeof(Vec));
                    PSVECScale(&p->vel, p->velScaleEnd * (1.0f - s), &b);
                    p->t[2] -= (lbl_80366158._28 == 0);
                }
                if ((u16)(total - elapsed) < p->fade) {
                    p->color[3] = (u16)(total - elapsed) * 255 / p->fade;
                }
                deg = p->spin * elapsed;
                if (deg != 0) {
                    PSMTXRotAxisRad(rot, &a, 0.017453292f * deg);
                    PSMTXMultVec(rot, &b, &b);
                }
                PSVECAdd(&e->_18, &v, &v);
                PSVECAdd(&v, &b, &v);
                PSMTXMultVec(lbl_8017FFE0, &v, &v);
                GXBegin(GX_QUADS, GX_VTXFMT0, 4);
                GXPosition3f32(v.x - p->w, v.y - p->h, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(uv[p->texCoords & 0xF][0], uv[p->texCoords & 0xF][1]);
                GXPosition3f32(v.x + p->h, v.y - p->w, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(uv[(p->texCoords >> 4) & 0xF][0], uv[(p->texCoords >> 4) & 0xF][1]);
                GXPosition3f32(v.x + p->w, v.y + p->h, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(uv[(p->texCoords >> 8) & 0xF][0], uv[(p->texCoords >> 8) & 0xF][1]);
                GXPosition3f32(v.x - p->h, v.y + p->w, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(uv[(p->texCoords >> 12) & 0xF][0], uv[(p->texCoords >> 12) & 0xF][1]);
            }
        }
        p = (ArcParticle*)p->next;
    } while (p != NULL);
    GXLoadPosMtxImm(lbl_8017FFE0, GX_PNMTX0);
    return alive == 0;
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
// to r30 after the glow test, where this build allocates it to r30 directly. Inline helpers for
// the block, the glow attach or the call, early returns and Emitter-typed buffers kept it.
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
// 99.83%: registers only: the target gives the two table lookups other scratch registers
// (r0, r6), the residue fn_800332B8's and fn_800328E0's lookups show too. Writing the second
// as `i = __abs(ang + 0x600); i &= 0x7FF;` gained a little; no form tried reaches r0/r6.
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
            s = p->size / 2;
            ang = 2048.0f * p->phase;
            i = __abs(ang) & 0x7FF;
            if (i >= 0x401) {
                i = 0x800 - i;
            }
            c = s * lbl_8017ED68[i];
            i = __abs(ang + 0x600);
            i &= 0x7FF;
            if (i >= 0x401) {
                i = 0x800 - i;
            }
            s *= lbl_8017ED68[i];
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

static inline void pushRibbon(RibbonParticle* p, Vec* pos)
{
    RibbonLink* l;

    p->head = (p->head + 1) % 4;
    if (p->links != 0) {
        l = p->tail;
        p->linkHead = (p->linkHead + 1) % 7;
        while (l->prev != (RibbonLink*)p) {
            memcpy(&l->pts[p->linkHead], &l->prev->pts[p->linkHead], sizeof(Vec));
            l = l->prev;
        }
        memcpy(&l->pts[p->linkHead], &p->pts[p->head], sizeof(Vec));
    }
    memcpy(&p->pts[p->head], pos, sizeof(Vec));
    if (p->filled < p->len) {
        p->filled++;
    }
}

// .text:0x80028628 size:0x920
void fn_80028628(Vec* start, Vec* end, RibbonParams* params, RibbonShape* shape, u32* colors, void* arg5, BOOL flash)
{
    Mtx m;
    Vec up = { 0.0f, 0.0f, 1.0f };
    Vec flat;
    Vec axis;
    Vec dir;
    Vec pos;
    Quaternion q;
    f32 speed;
    f32 grav;
    f32 drag;
    f32 k;
    s32 n;
    s32 c;
    s32 j;
    RibbonEmitter* e;
    RibbonParticle* p;
    RibbonLink* l;
    RibbonPoint* rec;
    LightFlashTask* task;

    n = (params->len + 2) / 7 + 1;
    if (n < 1) {
        n = 1;
    }
    e = (RibbonEmitter*)fn_80033A24(fn_80027968, 0x12, 0, shape->count * n, TRUE, 4);
    if (e == NULL) {
        return;
    }
    PSVECSubtract(end, start, &dir);
    speed = params->_08 / 100000.0f;
    grav = params->_14 / 100000.0f;
    drag = params->_18 / 100000.0f;
    PSVECNormalize(&dir, &dir);
    memcpy(&flat, &dir, sizeof(Vec));
    flat.y = 0.0f;
    if (PSVECMag(&flat)) {
        PSVECNormalize(&flat, &flat);
        PSVECCrossProduct(&up, &flat, &axis);
        if (!PSVECMag(&axis) || axis.y > 0.0f) {
            axis.x = 0.0f;
            axis.y = 1.0f;
            axis.z = 0.0f;
        } else {
            axis.x = 0.0f;
            axis.y = -1.0f;
            axis.z = 0.0f;
        }
        C_QUATRotAxisRad(&q, &axis, acos(PSVECDotProduct(&up, &flat)));
        PSMTXQuat(m, &q);
    } else {
        PSMTXRotRad(m, 'x', 1.5707964f);
    }
    p = (RibbonParticle*)((Emitter*)e)->particles;
    rec = shape->pts;
    axis.x = 0.0f;
    axis.y = -1.0f;
    k = params->_0C / 100000.0f / (params->_10 / 100000.0f);
    axis.z = 0.0f;
    if (flash) {
        if (lbl_803CBC70 != NULL) {
            task = lbl_803CBC70;
        } else {
            task = fn_800B0A5C_insertQueue(fn_8002852C, 5);
            lbl_803CBC70 = task;
            *(s16*)&task->light._00[0] = 200;
            *(s16*)&task->light._00[2] = 2152;
            *(s16*)&task->light._00[4] = 1426;
            ((u8*)task)[0x25] = 1;
        }
        if (colors != NULL) {
            *(u32*)&task->r = colors[rec->color];
        } else {
            c = rec->color;
            *(u32*)&task->r = (c & 0xF) | ((c << 4) & 0xF0) | ((c << 4) & 0xF00) | ((c << 8) & 0xF000) | ((c << 8) & 0xF0000) | ((c << 12) & 0xF00000) | ((c << 12) & 0xF000000) | ((c << 16) & 0xF0000000);
        }
        c = task->r + params->_44;
        if (c > 255) {
            c = 255;
        }
        task->r = c;
        c = task->g + params->_44;
        if (c > 255) {
            c = 255;
        }
        task->g = c;
        c = task->b + params->_44;
        if (c > 255) {
            c = 255;
        }
        task->b = c;
        task->_21 = params->_3C;
        task->timer = task->duration = params->_40;
        task->_22 = 1;
        fn_8003A540(1);
    }
    e->_54 = params->_28;
    e->file = params->file;
    e->_48 = arg5;
    e->_4C = e->_4D = params->_30;
    e->_4E = params->_2C;
    e->_4F = 0;
    e->_55 = params->_34;
    e->_56 = params->_38;
    while (p != NULL) {
        flat.x = (rec->x - (f32)(shape->w / 2)) / shape->w;
        flat.y = (rec->y - (f32)(shape->h / 2)) / shape->h;
        if (shape->is3D) {
            flat.z = (rec->z - (f32)(shape->d / 2)) / shape->d;
        } else {
            flat.z = 0.0f;
        }
        PSMTXMultVec(m, &flat, &flat);
        p->vel.x = -flat.x * k;
        p->vel.y = -flat.y * k;
        p->vel.z = -flat.z * k;
        pos.x = start->x;
        pos.y = start->y;
        pos.z = start->z;
        p->grav = -grav;
        p->drag = drag;
        p->_52 = 100.0f * speed;
        if (colors != NULL) {
            p->rgba = colors[rec->color];
        } else {
            c = rec->color;
            p->rgba = (c & 0xF) | ((c << 4) & 0xF0) | ((c << 4) & 0xF00) | ((c << 8) & 0xF000) | ((c << 8) & 0xF0000) | ((c << 12) & 0xF00000) | ((c << 12) & 0xF000000) | ((c << 16) & 0xF0000000);
        }
        p->color[3] = params->_1C;
        p->_56 = params->_20;
        p->_50 = (params->_1C + params->_20 - 1) / params->_20;
        j = params->len;
        memset(p->pts, 0, sizeof(p->pts));
        p->len = j;
        p->head = 0;
        l = (RibbonLink*)p;
        p->filled = 0;
        p->links = (j + 2) / 7;
        p->linkHead = 0;
        for (j = p->links; j-- != 0;) {
            l->next->prev = l;
            l = l->next;
            memset(l->pts, 0, sizeof(l->pts));
        }
        p->tail = l;
        pushRibbon(p, &pos);
        rec++;
        p->_54 = params->_04;
        p = (RibbonParticle*)p->tail->next;
    }
    e->_50 = 2;
    e->_18[0] = -92.5f;
    e->_18[1] = -36.0f;
    e->_18[2] = 53.0f;
    e->_18[3] = -47.5f;
    e->_18[4] = 0.0f;
    e->_18[5] = 118.0f;
    e->_18[6] = 29.0f;
    e->_18[7] = -36.0f;
    e->_18[8] = 66.0f;
    e->_18[9] = 83.0f;
    e->_18[10] = 0.0f;
    e->_18[11] = 122.0f;
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

// .text:0x80027968 size:0xBC4
// 99.58%: registers only: the target keeps spawn in r30 and alive in r21, which shifts the
// identity matrix copy; declaration orders found so far reach r30 for neither.
BOOL fn_80027968(void* arg)
{
    RibbonEmitter* e = arg;
    Mtx m = { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };
    s32 n;
    Vec pos;
    RibbonParticle* p;
    Vec v;
    s32 alive;
    BOOL spawn;
    RibbonLink* l;
    Vec* pt;
    s32 c;
    u32* col;
    s32 i;
    f32* wid;
    BOOL vertical;
    s32 k;
    f32 w;
    Emitter* em;
    f32 half;
    union {
        u32 rgba;
        u8 c[4];
    } color;

    alive = 0;
    i = 0;
    spawn = FALSE;
    p = (RibbonParticle*)((Emitter*)e)->particles;
    if (e->_48 != NULL) {
        if (e->_4D-- == 0) {
            spawn = TRUE;
            e->_4D = e->_4C;
            e->_4F = (e->_4F + 1) % e->_4E;
        }
    }
    GXSetCullMode(GX_CULL_NONE);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR0A0);
    if (e->file != NULL) {
        fn_80033B58(e->file, p->_54, GX_CLAMP, GX_CLAMP);
    }
    do {
        if (p->_50 > 0) {
            if (lbl_80366158._28 == 0) {
                PSVECScale(&p->vel, p->grav, &pos);
                PSVECAdd(&p->vel, &pos, &p->vel);
                p->vel.y += p->drag;
            }
            PSMTXMultVec(lbl_8017FFE0, &p->vel, &v);
            v.x -= lbl_8017FFE0[0][3];
            v.y -= lbl_8017FFE0[1][3];
            v.z -= lbl_8017FFE0[2][3];
            vertical = fabs(v.x) < fabs(v.y);
            pt = lbl_8017EC90;
            col = lbl_8017EC48;
            wid = lbl_8017EC00;
            color.rgba = p->rgba;
            n = p->filled;
            w = p->_52 / 100.0f * 0.5f * e->_54 / 100.0f;
            while (n-- != 0) {
                if (n < p->filled && n >= 0) {
                    if (n < 4) {
                        memcpy(&pos, &p->pts[(p->head - n + 4) % 4], sizeof(Vec));
                    } else {
                        k = n - 4;
                        l = p->next;
                        while (k >= 7) {
                            l = l->next;
                            k -= 7;
                        }
                        memcpy(&pos, &l->pts[(p->linkHead - k + 7) % 7], sizeof(Vec));
                    }
                }
                PSMTXMultVec(lbl_8017FFE0, &pos, pt);
                pt++;
                color.c[3] = p->color[3] * (p->filled - 1 - n) / p->filled;
                *col++ = color.rgba;
                *wid++ = w * (p->filled - 1 - n) / p->filled;
            }
            PSVECAdd(&pos, &p->vel, &pos);
            PSMTXMultVec(lbl_8017FFE0, &pos, &v);
            pt = lbl_8017EC90;
            col = lbl_8017EC48;
            wid = lbl_8017EC00;
            GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, (p->filled + 1) * 2);
            if (vertical) {
                for (k = 0; k < p->filled; k++) {
                    GXPosition3f32(pt->x - *wid, pt->y, pt->z);
                    GXColor1u32(*col);
                    GXTexCoord2f32(0.0f, 0.5f);
                    GXPosition3f32(pt->x + *wid, pt->y, pt->z);
                    GXColor1u32(*col);
                    GXTexCoord2f32(1.0f, 0.5f);
                    pt++;
                    wid++;
                    col++;
                }
                GXPosition3f32(v.x - w, v.y, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(0.0f, 0.5f);
                GXPosition3f32(v.x + w, v.y, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(1.0f, 0.5f);
            } else {
                for (k = 0; k < p->filled; k++) {
                    GXPosition3f32(pt->x, pt->y - *wid, pt->z);
                    GXColor1u32(*col);
                    GXTexCoord2f32(0.0f, 0.5f);
                    GXPosition3f32(pt->x, pt->y + *wid, pt->z);
                    GXColor1u32(*col);
                    GXTexCoord2f32(1.0f, 0.5f);
                    pt++;
                    wid++;
                    col++;
                }
                GXPosition3f32(v.x, v.y - w, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(0.0f, 0.5f);
                GXPosition3f32(v.x, v.y + w, v.z);
                GXColor1u32(p->rgba);
                GXTexCoord2f32(1.0f, 0.5f);
            }
            half = p->_52 / 100.0f * 0.5f;
            GXBegin(GX_QUADS, GX_VTXFMT0, 4);
            GXPosition3f32(v.x - half, v.y - half, v.z);
            GXColor1u32(p->rgba);
            GXTexCoord2f32(0.0f, 0.0f);
            GXPosition3f32(v.x - half, v.y + half, v.z);
            GXColor1u32(p->rgba);
            GXTexCoord2f32(0.0f, 1.0f);
            GXPosition3f32(v.x + half, v.y + half, v.z);
            GXColor1u32(p->rgba);
            GXTexCoord2f32(1.0f, 1.0f);
            GXPosition3f32(v.x + half, v.y - half, v.z);
            GXColor1u32(p->rgba);
            GXTexCoord2f32(1.0f, 0.0f);
            if (spawn && e->_4F == i % e->_4E && lbl_80366158._28 == 0) {
                PSVECScale(&p->vel, -1.0f, &v);
                color.c[3] = 0;
                color.c[0] = e->_55 + e->_56 * p->color[0] / 255;
                color.c[1] = e->_55 + e->_56 * p->color[1] / 255;
                color.c[2] = e->_55 + e->_56 * p->color[2] / 255;
                ((EffectParams*)e->_48)->_40 = color.rgba;
                fn_80030D88(&pos, &v, e->_48, 5);
                em = fn_800339F0(NULL, 5);
                if (em != NULL) {
                    em->state = 0;
                }
            }
            if (lbl_80366158._28 == 0) {
                for (k = 0; k < e->_50; k++) {
                    if (pos.x >= e->_18[k * 6 + 0] && pos.y >= e->_18[k * 6 + 1] && pos.z >= e->_18[k * 6 + 2] &&
                        pos.x <= e->_18[k * 6 + 3] && pos.y <= e->_18[k * 6 + 4] && pos.z <= e->_18[k * 6 + 5]) {
                        break;
                    }
                }
                if (k < e->_50) {
                    p->_50 = 0;
                } else {
                    pushRibbon(p, &pos);
                    c = p->color[3] - p->_56;
                    if (c < 0) {
                        c = 0;
                    }
                    p->color[3] = c;
                    p->_50--;
                }
            }
            alive++;
        }
        i++;
        p = (RibbonParticle*)p->tail->next;
    } while (p != NULL);
    GXLoadPosMtxImm(lbl_8017FFE0, GX_PNMTX0);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    return alive == 0;
}

// .text:0x80027918 size:0x50
void fn_80027918(u8 id, f32 v)
{
    RibbonEmitter* e = NULL;
    while ((e = (RibbonEmitter*)fn_800339F0((Emitter*)e, id)) != NULL) {
        e->_18[1] = v;
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
