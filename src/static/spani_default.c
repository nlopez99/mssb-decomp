#include "static/spani_default.h"
#include "Dolphin/os.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct SpaniObj {
    /* 0x00 */ struct SpaniObj* parent;
    /* 0x04 */ struct SpaniObj* next;
    /* 0x08 */ struct SpaniObj* child;
    /* 0x0C */ Mtx mtx;
    /* 0x3C */ u8 _3C[0x48 - 0x3C];
    /* 0x48 */ Vec _48;
    /* 0x54 */ u32 _54;
    /* 0x58 */ u8 color[4];
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66;
    /* 0x67 */ u8 _67;
    /* 0x68 */ u8 _68;
    /* 0x69 */ u8 _69[0x72 - 0x69];
    /* 0x72 */ s16 _72;
    /* 0x74 */ u8 _74[4];
    /* 0x78 */ Mtx _78;
    /* 0xA8 */ u8 _A8;
    /* 0xA9 */ u8 _A9[0xAC - 0xA9];
    /* 0xAC */ u16 _AC[10];
} SpaniObj; // size: 0xC0

typedef struct SpaniTask {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ u16 _14; // first slot in lbl_80371C30
    /* 0x16 */ u16 _16; // slot count
} SpaniTask;

typedef struct SpaniSlot {
    /* 0x0 */ SpaniObj* obj;
    /* 0x4 */ SpaniTask* task;
} SpaniSlot; // size: 0x8

typedef struct SabEntry {
    /* 0x00 */ Mtx mtx;
    /* 0x30 */ struct SabFile* _30;
    /* 0x34 */ void* _34;
    /* 0x38 */ struct SabFile* _38;
} SabEntry; // size: 0x3C

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct SpaniDesc {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12; // index of the parent in the list, 0xFF for none
    /* 0x14 */ s32 _14[3];
} SpaniDesc; // size: 0x20

// Passed to the callback fn_80034BCC
typedef struct SpaniHook {
    /* 0x00 */ u8 _00[0x64];
    /* 0x64 */ MtxPtr mtx;
    /* 0x68 */ u8 color[4];
    /* 0x6C */ s16* ids;
} SpaniHook;

// Filled by fn_8000CEF0
typedef struct SabInfo {
    /* 0x00 */ u8 _00[0x04];
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05;
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x0A - 0x08];
    /* 0x0A */ u16 _0A;
    /* 0x0C */ u8 _0C[0x14 - 0x0C];
    /* 0x14 */ s16 x;
    /* 0x16 */ s16 y;
    /* 0x18 */ u8 _18[0x1C - 0x18];
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ u8 _24[0x50 - 0x24];
} SabInfo; // size: 0x50

typedef struct SabPart {
    /* 0x00 */ u16 count;
    /* 0x02 */ u16 _02;
    /* 0x04 */ SabInfo info[1];
} SabPart;

typedef struct SabAnim {
    /* 0x00 */ s32 count;
    /* 0x04 */ s32 _04;
    /* 0x08 */ SabPart* parts[1];
} SabAnim;

typedef struct SabTable {
    /* 0x00 */ s32 count;
    /* 0x04 */ s32 _04;
    /* 0x08 */ SabAnim* anims[1];
} SabTable;

typedef struct SabFile {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ SabTable* table;
} SabFile;

extern u32 fn_8000CEF0(SabFile* sab, u16 id, s32 arg2, s32 arg3, SabInfo* out);
extern void fn_8000CC4C(SabFile* sab, SabPart* part, void* src, s32 offset, s32 size);
extern void convertTextureHeader(void* tex);
extern void fn_8000B9C8(SabFile* sab);
extern void fn_800ACFB0(void* data);
extern void fn_80011140(void);

extern SpaniObj* fn_80034F50(SpaniDesc* desc);

extern SpaniSlot lbl_80371C30[];
extern SpaniObj lbl_8039C3E0[0x360];
extern SabEntry lbl_803C4BE0[20];
extern u8 lbl_803C5F74[0xB4];

Mtx lbl_800F78E0[4] = {
    { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } },
    { { 0.399218738f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.399218738f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.399218738f, -511.0f } },
    { { 0.00156250002f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.00156250002f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.00156250002f, -2.0f } },
    { { 0.200390622f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.200390622f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.200390622f, -256.5f } },
};

SpaniObj* lbl_803CBC9C;

s32 lbl_803CB810 = -1;
s32 lbl_803CB814 = 0x360;

s16 lbl_8023D6C0[0x360];
u8 lbl_801F86C0[0x45000];
Mtx44 lbl_801F8680;
Mtx44 lbl_801F8640;

// .text:0x800369DC size:0x60 mapped:0x800369DC
void fn_800369DC(f32 zoom) {
    f32 inv;

    if (zoom != 0.0f) {
        inv = 1.0f / zoom;
        C_MTXFrustum(lbl_801F8640, -0.175f * inv, 0.175f * inv, 0.25f * inv, -0.25f * inv, 1.0f, 512.0f);
    }
}

// .text:0x80036824 size:0x1B8 mapped:0x80036824
u16 fn_80036824(s32 id, s32 anim, u16 frame) {
    s32 i = fn_80035DD4(id);
    SabAnim* a;
    SabPart* p;
    s32 k;
    s32 m;

    if (i == -1) {
        OSPanic("spani_default.c", 298, "It is a number not registered. \n");
    }
    a = lbl_803C4BE0[i]._38->table->anims[anim];
    k = a->count - 1;
    do {
        p = a->parts[k];
        m = p->count;
        do {
            m--;
            if (m == frame) {
                return p->info[m]._06;
            }
        } while (m != 0);
    } while (--k != 0);
    return 0;
}

// .text:0x8003656C size:0xE0 mapped:0x8003656C
void fn_8003656C(SpaniTask* task, s32 id, s32 part, u16 kind, s32 value) {
    SabInfo info;
    s32 v;
    SpaniObj* obj = lbl_80371C30[task->_14 + id].obj;
    u16 anim = obj->_64;
    SabEntry* e = &lbl_803C4BE0[obj->_66];
    SabFile* sab = e->_38;
    SabPart* p;

    if (fn_8000CEF0(sab, kind, 0, value, &info) != 0) {
        v = info._1C;
    } else {
        v = 0;
    }
    p = e->_38->table->anims[anim]->parts[part];
    fn_8000CC4C(sab, p, &v, (u32)&p->info[0]._1C - (u32)&p->info[0], 4);
}

// .text:0x8003649C size:0xD0 mapped:0x8003649C
void fn_8003649C(SpaniTask* task, s32 id, s32 part, u16 kind, s32 value) {
    SabInfo info;
    u16 v;
    SpaniObj* obj = lbl_80371C30[task->_14 + id].obj;
    u16 anim = obj->_64;
    SabEntry* e = &lbl_803C4BE0[obj->_66];
    SabPart* p;

    if (fn_8000CEF0(e->_38, kind, 0, value, &info) != 0) {
        v = info._06;
    } else {
        v = 0;
    }
    p = e->_38->table->anims[anim]->parts[part];
    fn_8000CC4C(e->_38, p, &v, (u32)&p->info[0]._06 - (u32)&p->info[0], 2);
}

// .text:0x800363D8 size:0xC4 mapped:0x800363D8
void fn_800363D8(SpaniTask* task, s32 id, u32 part, u16 kind, s32 value) {
    SabInfo info;
    u16 v;

    if (part < 10) {
        SpaniObj* obj = lbl_80371C30[task->_14 + id].obj;
        if (fn_8000CEF0(lbl_803C4BE0[obj->_66]._38, kind, 0, value, &info) != 0) {
            v = info._06;
        } else {
            v = 0;
        }
        lbl_80371C30[task->_14 + id].obj->_AC[part] = v;
    }
}

// .text:0x800362F0 size:0xE8 mapped:0x800362F0
void fn_800362F0(SpaniTask* task, s32 id) {
    s32 i;

    for (i = 0; i < 10; i++) {
        lbl_80371C30[task->_14 + id].obj->_AC[i] = 0xFFFF;
    }
}

// .text:0x80036270 size:0x80 mapped:0x80036270
void fn_80036270(SpaniTask* task, s32 id, s32 arg2, s32 arg3, s16* x, s16* y) {
    SabInfo info;
    SpaniObj* obj = lbl_80371C30[task->_14 + id].obj;

    fn_8000CEF0(lbl_803C4BE0[obj->_66]._38, obj->_64, arg2, arg3, &info);
    *x = info.x;
    *y = info.y;
}

// .text:0x80036214 size:0x5C mapped:0x80036214
s32 fn_80036214(SpaniTask* task, s32 id, s32 arg2, s32 arg3) {
    SabInfo info;
    SpaniObj* obj = lbl_80371C30[task->_14 + id].obj;

    fn_8000CEF0(lbl_803C4BE0[obj->_66]._38, obj->_64, arg2, arg3, &info);
    return info._1C;
}

// .text:0x80036134 size:0xE0 mapped:0x80036134
void fn_80036134(SpaniTask* task, s32 id, s32 arg2, s32 id2) {
    SabInfo info;
    SpaniObj* obj = lbl_80371C30[task->_14 + id].obj;

    fn_8000CEF0(lbl_803C4BE0[obj->_66]._38, obj->_64, arg2, obj->_5C >> 16, &info);
    lbl_80371C30[task->_14 + id2].obj->_48.x = info.x;
    lbl_80371C30[task->_14 + id2].obj->_48.y = info.y;
}

// .text:0x80035EEC size:0x34 mapped:0x80035EEC
void fn_80035EEC(u32 frame, s32 index) {
    if (lbl_8039C3E0[index]._5C > (frame << 16)) {
        lbl_8039C3E0[index]._5C = frame << 16;
        lbl_8039C3E0[index]._68 = 0;
    }
}

// .text:0x80035ED0 size:0x1C mapped:0x80035ED0
void fn_80035ED0(s32 index) {
    lbl_8039C3E0[index]._54 = 0;
}

// .text:0x80035DD4 size:0xFC mapped:0x80035DD4
s32 fn_80035DD4(s32 id) {
    s32 i;

    for (i = 0; i < 0x360; i++) {
        if (id == lbl_8023D6C0[i]) {
            return i;
        }
    }
    return -1;
}

// .text:0x80035CA4 size:0x130 mapped:0x80035CA4
void fn_80035CA4(s32 id) {
    s32 i = fn_80035DD4(id);

    if (i != -1) {
        SabEntry* e = &lbl_803C4BE0[i];
        e->_30 = NULL;
        e->_34 = NULL;
        lbl_8023D6C0[i] = -1;
        e->_38 = NULL;
        PSMTXIdentity(e->mtx);
    }
}

// .text:0x80035B50 size:0x154 mapped:0x80035B50
void fn_80035B50(s32 id) {
    s32 i = fn_80035DD4(id);

    if (i != -1) {
        lbl_8023D6C0[i] = -1;
        fn_800ACFB0(lbl_803C4BE0[i]._30);
        lbl_803C4BE0[i]._30 = NULL;
        lbl_803C4BE0[i]._34 = NULL;
        lbl_803C4BE0[i]._38 = NULL;
        PSMTXIdentity(lbl_803C4BE0[i].mtx);
    }
}

// .text:0x80035A00 size:0x150 mapped:0x80035A00
void fn_80035A00(void) {
    s32 i;

    for (i = 0; i < 25; i++) {
        if (i > 1) {
            fn_80035CA4(i);
        }
    }
}

static inline s8 findFreeSab(void) {
    u8 i;

    for (i = 0; i < 20; i++) {
        if (lbl_803C4BE0[i]._30 == NULL) {
            return i;
        }
    }
    return -1;
}

// .text:0x80035750 size:0xE8 mapped:0x80035750
void fn_80035750(SabFile* sab, void* tex, s16 id) {
    s32 i = findFreeSab();

    if (i == -1) {
        OSReport(" SabNo = %d not to add  \n", i);
        OSPanic("spani_default.c", 1180, "gasSpani No Empty \n");
    }
    lbl_803C4BE0[i]._30 = sab;
    lbl_803C4BE0[i]._34 = tex;
    lbl_803C4BE0[i]._38 = sab;
    lbl_8023D6C0[i] = id;
    convertTextureHeader(lbl_803C4BE0[i]._34);
    fn_8000B9C8(lbl_803C4BE0[i]._38);
}

// .text:0x800356B8 size:0x98 mapped:0x800356B8
void fn_800356B8(void) {
    s32 i;

    for (i = 0; i < 0x360; i++) {
        lbl_8039C3E0[i].parent = NULL;
        lbl_8039C3E0[i].next = NULL;
        lbl_8039C3E0[i].child = NULL;
        lbl_8039C3E0[i]._54 = 0;
        PSMTXIdentity(lbl_8039C3E0[i].mtx);
        lbl_80371C30[i].obj = NULL;
        lbl_80371C30[i].task = NULL;
    }
    fn_80011140();
    lbl_803C5F74[0] = 0;
}

// .text:0x80034E20 size:0x130 mapped:0x80034E20
void fn_80034E20(SpaniTask* task, SpaniDesc* desc) {
    s32 n = 0;
    s32 i;
    s32 j;
    SpaniSlot* base;
    SpaniObj* o;

    for (i = 0; i < 0x360; i++) {
        if (lbl_80371C30[i].obj == NULL) {
            task->_14 = i;
            base = &lbl_80371C30[i];
            base->task = task;
            break;
        }
    }
    for (; desc->_00 != 3; desc++, n++) {
        lbl_80371C30[n + i].obj = fn_80034F50(desc);
        o = lbl_80371C30[n + i].obj;
        if (desc->_12 == 0xFF || n == 0) {
            o->parent = NULL;
        } else {
            o->parent = base[desc->_12].obj;
            o->next = o->parent->child;
            o->parent->child = o;
        }
        for (j = 0; j < 10; j++) {
            o->_AC[j] = 0xFFFF;
        }
    }
    task->_16 = n;
}

// .text:0x80034CEC size:0x134 mapped:0x80034CEC
void fn_80034CEC(SpaniTask* task) {
    SpaniObj* o;
    s32 first = task->_14;
    s32 i;
    s32 j;

    for (i = 0; i < task->_16; i++) {
        o = lbl_80371C30[first + i].obj;
        if (o != NULL) {
            o->_54 = 0;
        }
    }
    for (j = first, i += first; i < 0x360; i++, j++) {
        lbl_80371C30[j].obj = lbl_80371C30[i].obj;
        lbl_80371C30[j].task = lbl_80371C30[i].task;
        if (lbl_80371C30[j].task != NULL) {
            lbl_80371C30[j].task->_14 = j;
        }
    }
    for (; j < 0x360; j++) {
        lbl_80371C30[j].obj = NULL;
        lbl_80371C30[j].task = NULL;
    }
}

// .text:0x80034BCC size:0x120 mapped:0x80034BCC
s32 fn_80034BCC(SpaniHook* hook) {
    SpaniObj* o;

    for (o = lbl_803CBC9C->child; o != NULL; o = o->next) {
        if (o->parent->_64 == hook->ids[0] && o->_72 == hook->ids[1]) {
            PSMTXCopy(hook->mtx, o->_78);
            o->_74[0] = hook->color[0] * o->color[0] / 255;
            o->_74[1] = hook->color[1] * o->color[1] / 255;
            o->_74[2] = hook->color[2] * o->color[2] / 255;
            o->_74[3] = hook->color[3] * o->color[3] / 255;
            o->_A8 = 1;
        }
    }
    return 0;
}
