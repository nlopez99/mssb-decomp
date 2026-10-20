#include "static/spani_default.h"
#include "Dolphin/os.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct SpaniColor {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 a;
} SpaniColor;

typedef struct SpaniObj {
    /* 0x00 */ struct SpaniObj* parent;
    /* 0x04 */ struct SpaniObj* next;
    /* 0x08 */ struct SpaniObj* child;
    /* 0x0C */ Mtx mtx;
    /* 0x3C */ Vec _3C;
    /* 0x48 */ Vec _48;
    /* 0x54 */ u32 _54;
    /* 0x58 */ SpaniColor color;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ s32 _60;
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66; // index into lbl_803C4BE0
    /* 0x67 */ u8 _67;
    /* 0x68 */ u8 _68;
    /* 0x69 */ u8 _69;
    /* 0x6A */ u8 _6A[0x6C - 0x6A];
    /* 0x6C */ f32 _6C;
    /* 0x70 */ u8 _70;
    /* 0x71 */ u8 _71;
    /* 0x72 */ s16 _72;
    union {
        /* 0x74 */ SpaniColor _74;
        /* 0x74 */ u32 _74_rgba;
    };
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
    /* 0x30 */ void* _30; // the loaded file: a SAB file, or two offsets to the texture and SAB parts
    /* 0x34 */ void* _34;
    /* 0x38 */ struct SabFile* _38;
} SabEntry; // size: 0x3C

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct SpaniDesc {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ SpaniColor color;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ s16 _12; // index of the parent in the list, 0xFF for none
    /* 0x14 */ u8 _14; // id in lbl_8023D6C0
    /* 0x15 */ u8 _15[0x18 - 0x15];
    /* 0x18 */ f32 _18;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
    /* 0x1E */ s16 _1E;
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
    /* 0x00 */ u16 width;
    /* 0x02 */ u16 height;
    /* 0x04 */ u8 _04[0x8 - 0x4];
    /* 0x08 */ SabTable* table;
} SabFile;

extern u32 fn_8000CEF0(SabFile* sab, u16 id, s32 arg2, s32 arg3, SabInfo* out);
extern void fn_8000CC4C(SabFile* sab, SabPart* part, void* src, s32 offset, s32 size);
extern void convertTextureHeader(void* tex);
extern void fn_8000B9C8(SabFile* sab);
extern void fn_800ACFB0(void* data);
extern void fn_80011140(void);


extern SpaniSlot lbl_80371C30[];
extern SpaniObj lbl_8039C3E0[0x360];
extern SabEntry lbl_803C4BE0[20];
extern u8 lbl_803C5F74[0xB4];
extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;
extern struct {
    /* 0x00 */ u8 _00[0x84];
    /* 0x84 */ s32 _84;
    /* 0x88 */ s32 _88;
} lbl_80366188;
extern f32 lbl_803CBBDC;
extern f32 lbl_803CBBE0;
extern u8 lbl_803CBBE4;
extern void fn_800B2854(void* buf, u32 size, Mtx44 proj, s32 arg3, s32 count, s32* kinds, s32 arg6);
extern void fn_800B27A4(s32 arg0);
extern void fn_800B0D38(s32 arg0, s32 arg1);
extern void fn_8000A094(s32 (*callback)(SpaniHook* hook));
extern void fn_8000F534(SpaniObj* obj, s32 arg1);
extern u8 fn_8000D838(u32* frame, SabFile* sab, u16 anim, Mtx m, s32 arg4, u32 color, u32* out, void* tex);
extern camera_803c639c_s* fn_80052734(s32 idx);
extern void fn_800B216C(s32 arg0, s32 arg1, s32 arg2);
extern void fn_800B21A8(u8 arg0);
extern void fn_800B24D4(u8 arg0);
extern void fn_800B27DC(Mtx44 m, s32 arg1);
extern void DrawTextOnCondition(u8 arg0);
extern void* ARAMTransfer(void* entry, int arg1, int arg2, u32 aram);

Mtx lbl_800F78E0[4] = {
    { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } },
    { { 0.399218738f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.399218738f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.399218738f, -511.0f } },
    { { 0.00156250002f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.00156250002f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.00156250002f, -2.0f } },
    { { 0.200390622f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.200390622f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.200390622f, -256.5f } },
};

SpaniObj* lbl_803CBC9C;
s32 lbl_803CBC98;
void* lbl_803CBC94;
u8 lbl_803CBC91;
u8 lbl_803CBC90;

s32 lbl_803CB810 = -1;
s32 lbl_803CB814 = 0x360;

s16 lbl_8023D6C0[0x360];
u8 lbl_801F86C0[0x45000];
Mtx44 lbl_801F8680;
Mtx44 lbl_801F8640;

// .text:0x80036A3C size:0x24C mapped:0x80036A3C
void fn_80036A3C(void) {
    s32 kinds[23];
    s32 i;

    C_MTXFrustum(lbl_801F8680, -0.175f, 0.175f, -0.25f, 0.25f, 1.0f, 512.0f);
    for (i = 0; i < 23; i++) {
        switch (i) {
        case 12:
            kinds[i] = 9;
            break;
        case 11:
            kinds[i] = 10;
            break;
        case 10:
        case 13:
        case 14:
            kinds[i] = 11;
            break;
        case 0:
            kinds[i] = 13;
            break;
        default:
            kinds[i] = 12;
            break;
        }
    }
    fn_800B2854(lbl_801F86C0, sizeof(lbl_801F86C0), lbl_801F8680, 0, 23, kinds, 0);
    fn_800B27A4(10);
    for (i = 13; i < 23; i++) {
        fn_800B0D38(i, 2);
    }
    for (i = 0; i < 0x360; i++) {
        lbl_8023D6C0[i] = -1;
    }
    lbl_803CBBE4 = 0;
    lbl_803CBBE0 = 2.0f;
    lbl_803CBBDC = 1280.0f;
    memset(lbl_8039C3E0, 0, sizeof(lbl_8039C3E0));
    lbl_80366188._84 = 0;
    lbl_80366188._88 = 0;
}

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
    s32 k;
    SabPart** pp;
    SabAnim* a;
    SabPart* p;
    s32 m;
    SabInfo* info;

    if (i == -1) {
        OSPanic("spani_default.c", 298, "It is a number not registered. \n");
    }
    a = (SabAnim*)((u32*)lbl_803C4BE0[i]._38->table)[anim + 2];
    k = a->count;
    pp = &a->parts[--k];
    do {
        p = *pp--;
        m = p->count;
        info = &p->info[m];
        do {
            m--;
            info--;
            if (m == frame) {
                return info->_06;
            }
        } while (m != 0);
    } while (--k != 0);
    return 0;
}

// .text:0x8003664C size:0x1D8 mapped:0x8003664C
void fn_8003664C(s32 id, s32 index, s16 value, u32 sel) {
    s32 i = fn_80035DD4(id);
    u32 k;
    SabPart** pp;
    SabAnim* a;
    SabPart* p;
    s32 m;
    SabInfo* info;

    if (i == -1) {
        OSPanic("spani_default.c", 350, "It is a number not registered. \n");
    }
    a = (SabAnim*)((u32*)lbl_803C4BE0[i]._38->table)[lbl_8039C3E0[index]._64 + 2];
    k = a->count;
    pp = &a->parts[--k];
    do {
        p = *pp--;
        m = p->count;
        info = &p->info[m];
        do {
            m--;
            info--;
            if (info->_04 != 0 && k == sel) {
                info->_06 = value;
            }
        } while (m != 0);
    } while (--k != 0);
}

// .text:0x8003656C size:0xE0 mapped:0x8003656C
void fn_8003656C(SpaniTask* task, s32 id, s32 part, u16 kind, s32 value) {
    SabInfo info;
    s32 v;
    SpaniObj* obj = lbl_80371C30[task->_14 + id].obj;
    u16 anim = obj->_64;
    u8 n = obj->_66;
    SabFile* sab = lbl_803C4BE0[n]._38;
    SabPart* p;

    if (fn_8000CEF0(sab, kind, 0, value, &info) != 0) {
        v = info._1C;
    } else {
        v = 0;
    }
    p = (SabPart*)((u32*)((u32*)lbl_803C4BE0[n]._38->table)[anim + 2])[part + 2];
    fn_8000CC4C(sab, p, &v, (u32)&((SabInfo*)((u8*)p + 4))->_1C - (u32)((u8*)p + 4), 4);
}

// .text:0x8003649C size:0xD0 mapped:0x8003649C
void fn_8003649C(SpaniTask* task, s32 id, s32 part, u16 kind, s32 value) {
    SabInfo info;
    u16 v;
    SpaniObj* obj = lbl_80371C30[task->_14 + id].obj;
    u16 anim = obj->_64;
    u8 n = obj->_66;
    SabPart* p;

    if (fn_8000CEF0(lbl_803C4BE0[n]._38, kind, 0, value, &info) != 0) {
        v = info._06;
    } else {
        v = 0;
    }
    p = (SabPart*)((u32*)((u32*)lbl_803C4BE0[n]._38->table)[anim + 2])[part + 2];
    fn_8000CC4C(lbl_803C4BE0[n]._38, p, &v, (u32)&((SabInfo*)((u8*)p + 4))->_06 - (u32)((u8*)p + 4), 2);
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

// .text:0x80035F20 size:0x214 mapped:0x80035F20
SabInfo* fn_80035F20(s32 id, s32 index, u16 frame, s16 sel) {
    s32 i = fn_80035DD4(id);
    u32 k;
    SabPart** pp;
    SabAnim* a;
    SabPart* p;
    s32 m;
    SabInfo* info;

    if (i == -1) {
        OSPanic("spani_default.c", 796, "It is a number not registered. \n");
    }
    a = (SabAnim*)((u32*)lbl_803C4BE0[i]._38->table)[lbl_8039C3E0[index]._64 + 2];
    k = a->count;
    pp = &a->parts[--k];
    if (sel == -1) {
        p = *pp;
        m = p->count;
        info = &p->info[m];
        do {
            m--;
            info--;
        } while (m != 0);
        return &info[frame];
    }
    do {
        p = *pp--;
        m = p->count;
        info = &p->info[m];
        do {
            if (k == sel) {
                goto found;
            }
            m--;
            info--;
        } while (m != 0);
    } while (--k != 0);
found:
    while (m != 0) {
        m--;
        info--;
    }
    return info;
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
        lbl_8023D6C0[i] = -1;
        lbl_803C4BE0[i]._30 = NULL;
        lbl_803C4BE0[i]._34 = NULL;
        lbl_803C4BE0[i]._38 = NULL;
        PSMTXIdentity(lbl_803C4BE0[i].mtx);
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
        if (i > 1U) {
            fn_80035CA4(i);
        }
    }
}

static inline s8 findFreeSab(void) {
    u8 i = 0;

    do {
        if (lbl_803C4BE0[i]._30 == NULL) {
            return i;
        }
    } while (++i < 20);
    return -1;
}

// .text:0x80035838 size:0x1C8 mapped:0x80035838
u8 fn_80035838(void* entry, u8 id) {
    s32 done = FALSE;
    u32* file;
    s32 i;

    if (lbl_803CBC90 == 2) {
        lbl_803CBC90 = 0;
        lbl_803CBC94 = NULL;
        lbl_803CB810 = -1;
    }
    switch (lbl_803CBC90) {
    case 0:
        lbl_803CBC91 = findFreeSab();
        if (lbl_803CBC91 == -1) {
            OSReport(" SabNo = %d not to add  \n", lbl_803CBC91);
            OSPanic("spani_default.c", 1114, "gasSpani No Empty \n");
        }
        lbl_8023D6C0[lbl_803CBC91] = id;
        file = ARAMTransfer(entry, 0, 0, 0);
        lbl_803C4BE0[lbl_803CBC91]._30 = file;
        lbl_803CBC94 = entry;
        lbl_803CB810 = id;
        lbl_803CBC90++;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            i = lbl_803CBC91;
            file = lbl_803C4BE0[i]._30;
            lbl_803C4BE0[i]._34 = (u8*)file + file[0];
            lbl_803C4BE0[i]._38 = (SabFile*)((u8*)file + file[1]);
            convertTextureHeader(lbl_803C4BE0[i]._34);
            fn_8000B9C8(lbl_803C4BE0[i]._38);
            done = TRUE;
            lbl_803CBC90++;
        }
        break;
    }
    return done;
}

// .text:0x80035750 size:0xE8 mapped:0x80035750
void fn_80035750(SabFile* sab, void* tex, s16 id) {
    s32 i = findFreeSab();

    if (i == -1) {
        OSReport(" SabNo = %d not to add  \n", i);
        OSPanic("spani_default.c", 1180, "gasSpani No Empty \n");
    }
    lbl_8023D6C0[i] = id;
    lbl_803C4BE0[i]._30 = sab;
    lbl_803C4BE0[i]._34 = tex;
    lbl_803C4BE0[i]._38 = sab;
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

// .text:0x80035168 size:0x550 mapped:0x80035168
void fn_80035168(void) {
    Mtx* depths = lbl_800F78E0;
    SpaniObj* o;
    s32 i;
    MtxPtr depth;
    u32 color;
    u32 out;
    Mtx m;
    Mtx tmp;
    s32 j;
    SabFile* sab;
    SabPart* p;
    u8 k;

    if (lbl_803C77B8[0]._00 & 0x1000) {
        if (lbl_803C77B8[3]._04 & 1) {
            if (lbl_803CB814 > lbl_803CBC98) {
                lbl_803CB814--;
            }
        } else if ((lbl_803C77B8[3]._04 & 2) && lbl_803CB814 < 0x360) {
            lbl_803CB814++;
        }
        if (lbl_803C77B8[3]._04 & 4) {
            if (lbl_803CBC98 > 0) {
                lbl_803CBC98--;
            }
        } else if ((lbl_803C77B8[3]._04 & 8) && lbl_803CBC98 < lbl_803CB814) {
            lbl_803CBC98++;
        }
    }
    fn_8000A094(fn_80034BCC);
    for (i = lbl_803CBC98, o = &lbl_8039C3E0[i]; i < lbl_803CB814; i++, o++) {
        if (o->_54 == 0) {
            continue;
        }
        if (!(o->_54 & 2)) {
            if (o->_54 & 4) {
                fn_8000F534(o, 0);
            }
            continue;
        }
        if (o->parent != NULL && o->_A8 == 0) {
            if (o->_54 & 4) {
                fn_8000F534(o, 0);
            }
            continue;
        }
        fn_800B24D4(o->_67);
        if (o->_70 != 0) {
            fn_800B27DC(lbl_801F8640, 0);
            depth = depths[0];
            fn_800B21A8(o->_71);
        } else {
            fn_800B27DC(lbl_801F8680, 0);
            if (o->_67 == 0x15) {
                depth = depths[3];
                lbl_803CBBE0 = 256.5f;
                fn_800B216C(1, 3, 0);
            } else {
                if (o->_67 >= 0xF && o->_67 <= 0x16) {
                    depth = depths[1];
                    lbl_803CBBE0 = 511.0f;
                } else {
                    depth = depths[2];
                    lbl_803CBBE0 = 2.0f;
                }
                fn_800B21A8(o->_71);
            }
        }
        o->_3C.x = o->_48.x;
        o->_3C.y = o->_48.y;
        o->_3C.z = o->_48.z;
        if (o->_70 != 0) {
            PSMTXScale(o->mtx, -o->_6C, o->_6C, 1.0f);
            PSMTXInverse(fn_80052734(0)->view, tmp);
            tmp[2][3] = 0.0f;
            tmp[1][3] = 0.0f;
            tmp[0][3] = 0.0f;
            PSMTXConcat(tmp, o->mtx, o->mtx);
            PSMTXTrans(tmp, o->_3C.x, o->_3C.y, o->_3C.z);
            PSMTXConcat(tmp, o->mtx, o->mtx);
            PSMTXConcat(fn_80052734(0)->view, o->mtx, o->mtx);
            o->_74 = o->color;
        } else {
            if (o->parent == NULL) {
                o->_3C.x -= (f32)(lbl_803C4BE0[o->_66]._38->width >> 1);
                o->_3C.y -= (f32)(lbl_803C4BE0[o->_66]._38->height >> 1);
                o->_74 = o->color;
                PSMTXIdentity(o->_78);
            }
            o->_3C.z = 0.0f;
            PSMTXTrans(o->mtx, o->_3C.x, o->_3C.y, 0.0f);
            PSMTXConcat(o->_78, o->mtx, o->mtx);
        }
        color = o->_74_rgba;
        lbl_803CBBE4 = o->_70;
        for (j = 0; j < 10; j++) {
            if (o->_AC[j] != 0xFFFF) {
                sab = lbl_803C4BE0[o->_66]._38;
                p = (SabPart*)((u32*)((u32*)sab->table)[o->_64 + 2])[j + 2];
                fn_8000CC4C(sab, p, &o->_AC[j], (u32)&((SabInfo*)((u8*)p + 4))->_06 - (u32)((u8*)p + 4), 2);
            }
        }
        if (o->parent == NULL) {
            PSMTXConcat(depth, o->mtx, m);
        } else {
            PSMTXCopy(o->mtx, m);
        }
        lbl_803CBC9C = o;
        if (!(o->_54 & 4)) {
            o->_69 = fn_8000D838(&o->_5C, lbl_803C4BE0[o->_66]._38, o->_64, m, 0, color, &out, lbl_803C4BE0[o->_66]._34);
        }
        o->_A8 = 0;
        if (o->_68 == 1) {
            switch (o->_69) {
            case 0:
                o->_5C += o->_60;
                break;
            case 1:
                o->_5C = 0;
                break;
            case 2:
            case 3:
                break;
            default:
                o->_5C += o->_60;
                break;
            }
        } else if (o->_68 == 4) {
            if (o->_5C > o->_60) {
                o->_5C -= o->_60;
            } else {
                o->_5C = 0;
            }
        }
        if (o->_54 & 4) {
            fn_8000F534(o, 1);
        }
    }
    for (k = 1; k < 9; k++) {
        fn_800B24D4(k);
        fn_800B21A8(0);
        DrawTextOnCondition(k);
    }
    fn_800B24D4(2);
}

// .text:0x80034F50 size:0x218 mapped:0x80034F50
SpaniObj* fn_80034F50(SpaniDesc* desc) {
    s32 i;
    s32 j;
    SpaniObj* o;

    for (i = 0; i < 0x360; i++) {
        if (lbl_8039C3E0[i]._54 == 0) {
            for (j = 0; j < 0x360; j++) {
                if (desc->_14 == lbl_8023D6C0[j]) {
                    break;
                }
            }
            o = &lbl_8039C3E0[i];
            o->_54 = 1;
            if (desc->_00 == 1) {
                o->_54 |= 4;
            }
            o->color = desc->color;
            o->_74 = desc->color;
            o->_64 = desc->_02;
            o->_67 = desc->_11;
            o->_66 = j;
            o->_48.x = desc->x;
            o->_48.y = desc->y;
            o->_48.z = 0.0f;
            o->_6C = desc->_18;
            o->_70 = desc->_1C;
            o->next = NULL;
            o->child = NULL;
            o->_72 = desc->_1E;
            o->_71 = desc->_1D;
            if (desc->_10 == 2) {
                o->_68 = 0;
            } else if (desc->_10 == 3) {
                o->_68 = 1;
            } else {
                o->_68 = desc->_10;
                o->_54 |= 2;
            }
            o->_5C = 0;
            o->_60 = 0x10000;
            o->_A8 = 0;
            PSMTXIdentity(o->mtx);
            return o;
        }
    }
    return NULL;
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
            o->_74.r = hook->color[0] * o->color.r / 255;
            o->_74.g = hook->color[1] * o->color.g / 255;
            o->_74.b = hook->color[2] * o->color.b / 255;
            o->_74.a = hook->color[3] * o->color.a / 255;
            o->_A8 = 1;
        }
    }
    return 0;
}
