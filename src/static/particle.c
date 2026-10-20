#include "static/particle.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct Particle {
    /* 0x00 */ struct Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ u8 _10[0x10];
    /* 0x20 */ s32 _20;
    /* 0x24 */ u8 _24[0x26];
    /* 0x4A */ s16 _4A;
} Particle;

typedef struct Emitter {
    /* 0x00 */ struct Emitter* prev;
    /* 0x04 */ struct Emitter* next;
    /* 0x08 */ u32 active;
    /* 0x0C */ Particle* particles;
    /* 0x10 */ u8 _10[0x4];
    /* 0x14 */ u16 _14_hi : 4;
    /* 0x14 */ u16 count : 12;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17_hi : 1;
    /* 0x17 */ u8 id : 7;
    /* 0x18 */ Vec _18;
    /* 0x24 */ Vec _24;
    /* 0x30 */ Vec _30;
    /* 0x3C */ u8 _3C[0x4];
    /* 0x40 */ u16 _40;
} Emitter;

typedef struct EmitterList {
    /* 0x0 */ Emitter* prev;
    /* 0x4 */ Emitter* next;
} EmitterList;

typedef struct UnkParticleState {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} UnkParticleState;

extern Particle* lbl_803CBC74;
extern Emitter* lbl_803CBC80;
extern EmitterList lbl_803CBC84;
extern f32 lbl_8017ED68[];
extern Mtx lbl_8017FF78;
extern Mtx lbl_8017FFE0;
extern UnkParticleState lbl_80366158;

// .text:0x800348C8 size:0x304

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
    if (e->active == 0) {
        return;
    }
    if (e->prev != NULL) {
        e->prev->next = e->next;
    }
    if (e->next != NULL) {
        e->next->prev = e->prev;
    }
    e->active = 0;
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

    if (e == NULL) {
        return e;
    }
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

// .text:0x80032038 size:0x2C
s32 fn_80032038(Particle* a, Particle* b)
{
    if (a->pos.x > b->pos.x) {
        return 1;
    }
    if (a->pos.x < b->pos.x) {
        return -1;
    }
    return 0;
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

// .text:0x80027918 size:0x50
void fn_80027918(u8 id, f32 v)
{
    Emitter* e = NULL;
    while ((e = fn_800339F0(e, id)) != NULL) {
        e->_18.y = v;
    }
}
