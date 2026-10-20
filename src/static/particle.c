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
    /* 0x30 */ Vec _30;
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
} EffectParams; // size: 0x40

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
    /* 0x44 */ u8 _44[0x4A - 0x44];
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
    /* 0x44 */ u8 _44[0x4A - 0x44];
    /* 0x4A */ s16 remaining;
} GlowParticle;

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
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s16 _20;
    /* 0x22 */ s16 _22;
    /* 0x24 */ s16 _24;
    /* 0x26 */ s16 _26;
    /* 0x28 */ s16 _28;
    /* 0x2A */ s8 _2A;
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
    /* 0x40 */ u8 color[4];
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
// 97.41%: registers in the inlined table lookups differ (the target negates pitch in place),
// and one fcmpu against 0.0f has its operands swapped.
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
    out->y = fn_800335EC(yaw);
    pitch = 2048.0f * (pitchMin / 360.0f) + 0.5f;
    if (pitchMax != pitchMin) {
        pitch += rand() % (s32)(2048.0f * ((pitchMax - pitchMin) / 360.0f) + 0.5f);
    }
    out->z = out->x * fn_800335EC(pitch);
    out->x *= fn_800335BC(pitch);
    if (dirIn != NULL && PSVECMag(dirIn) != 0.0f) {
        angle = acos(PSVECDotProduct(&up, dirIn));
        PSVECCrossProduct(&up, dirIn, &axis);
        if (PSVECMag(&axis) != 0.0f) {
            C_QUATRotAxisRad(&q, &axis, angle);
            PSMTXQuat(m, &q);
            PSMTXMultVec(m, out, out);
        }
        PSVECScale(out, PSVECMag(dirIn), out);
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
void fn_800324EC(u16 joint, s32 player, s32 other, Vec* dir)
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
void fn_80032064(Vec* pos, Vec* dir)
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

// .text:0x8002955C size:0x294
void fn_8002955C(Vec* pos, s32 arg1, EffectParams* params)
{
    Emitter* e = fn_800339F0(NULL, 12);

    if (e != NULL) {
        u8 tmp[sizeof(Emitter)];
        Emitter* added = fn_800337CC((Emitter*)tmp, params->count, TRUE);
        if (added != NULL) {
            Particle* p;
            fn_800297F0(added, pos, arg1, params);
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
            fn_800297F0(e, pos, arg1, params);
        }
    }
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
// 27.88%: first draft; the base's frame is 0x40 bytes larger and the loop body differs.
// Not yet compared in detail.
void fn_80027300(Emitter* e, Vec* pos, Vec* dir, EffectParams* params, f32 scale)
{
    BurstEmitter* be = (BurstEmitter*)e;
    BurstParticle* p;
    f32 step;
    f32 yaw;
    f32 pitch;
    f32 speed;
    f32 speedRange;
    f32 size;
    f32 sizeRange;
    f32 grow;
    s32 lifeRange;
    s32 fadeRange;

    be->_10 = params->_00;
    be->_1C = 1.0f;
    be->_20 = params->_04;
    be->dir = dir;
    p = (BurstParticle*)e->particles;
    pitch = -180.0f;
    speed = params->_0C[5] / 100000.0f;
    yaw = -180.0f;
    lifeRange = params->_0C[2] - params->_0C[1];
    fadeRange = params->_0C[4] - params->_0C[3];
    size = params->_0C[7] / 100000.0f;
    step = 360.0f / (s32)sqrt(params->count);
    grow = params->_0C[0] / 100000.0f;
    speedRange = params->_0C[6] / 100000.0f - speed;
    sizeRange = params->_0C[8] / 100000.0f - size;
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
        p->_10 = speed + (speedRange * (f32)rand()) / 32767.0f;
        p->_14 = size + (sizeRange * (f32)rand()) / 32767.0f;
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
