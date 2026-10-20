#include "static/particle.h"
#include "static/sub.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "math.h"

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
    /* 0x4E */ u8 _4E[0x12];
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
    s32 i = __abs(angle) & 0x7FF;
    if (i >= 0x401) {
        i = 0x800 - i;
    }
    return lbl_8017ED68[i];
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
// 98.80%: the target copies params to r7 before arg1 to r5 at entry; this copies them
// the other way round. The rest matches.
void fn_80030D88(Vec* pos, s32 arg1, EffectParams* params, s32 id)
{
    if (params->count > 0) {
        Emitter* e = fn_800339F0(NULL, id);

        if (e != NULL) {
            u8 tmp[sizeof(Emitter)];
            Emitter* added = fn_800337CC((Emitter*)tmp, params->count, TRUE);
            if (added != NULL) {
                Particle* p;
                fn_80030720(added, pos, arg1, params);
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
                fn_80030720(e, pos, arg1, params);
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
