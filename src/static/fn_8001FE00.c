#include "static/fn_8001FE00.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"
#include "Dolphin/os.h"
#include "Dolphin/rand.h"
#include "static/fn_80021AC8.h"

typedef struct SceneSprite {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ u32 flags;
    /* 0x58 */ u32 color;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x68 - 0x60];
    /* 0x68 */ u8 _68;
    /* 0x69 */ u8 _69;
} SceneSprite;

typedef struct SceneSlot {
    /* 0x00 */ SceneSprite* sprite;
    /* 0x04 */ u32 _04;
} SceneSlot;

typedef struct SceneTask {
    /* 0x00 */ void (*func)(void);
    /* 0x04 */ u8 _04[0x14 - 0x04];
    /* 0x14 */ u16 slot;
    /* 0x16 */ u8 _16[2];
    /* 0x18 */ s16 _18;
    /* 0x1A */ s16 _1A;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ s16 _1E;
} SceneTask;

// The scene fader's state
typedef struct SceneState {
    /* 0x00 */ void* tex;
    /* 0x04 */ void* image;
    /* 0x08 */ u8 _08[0xC - 0x8];
    /* 0x0C */ s16 _0C;
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u8 scene;
    /* 0x11 */ u8 next;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ s8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 step;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
} SceneState;

typedef struct SceneChoice {
    /* 0x0 */ s8 stadium;
    /* 0x1 */ s8 weight;
    /* 0x2 */ s8 weightSeen;
} SceneChoice;

extern SceneChoice lbl_800E86BC[17];
extern SceneState lbl_8037169C;
extern SceneSlot lbl_80371C30[];
extern SceneTask* lbl_803CC1B8;
extern SoundFile lbl_800EEFD0[0x3E];
extern u8 lbl_800EF3B0[0xC0];
extern u8 lbl_800EF470[0x40];
extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

// static/spani_default.h declares fn_80035838 returning u8, which its definition needs;
// this caller uses the result unmasked, as from an s32
s32 fn_80035838(void* entry, u8 id);
void fn_80034CEC(struct SpaniTask* task);
void fn_80034E20(struct SpaniTask* task, struct SpaniDesc* desc);
void* fn_800B0A5C_insertQueue(void (*callback)(void), u16 priority);
void fn_800B0A14_removeQueue(void);
void fn_800ACF14(void* data);
void* fn_800ACF34(u32 align, u32 size);
void convertTextureHeader(void* tex);
void fn_8000FE08(s32 id, s32 arg1, s32 arg2);
void fn_800B2160(s32 mode);

typedef struct SceneVtx {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u32 color;
    /* 0x10 */ s16 s;
    /* 0x12 */ s16 t;
} SceneVtx; // size: 0x14

void DrawSprite_TexObj(SceneVtx* vtx, void* tex, s32 arg2);
extern f32 lbl_803CBBDC;
extern f32 lbl_803CBBE0;

s16 lbl_803CB7C8[2] = { 0x15, 0x9 };
u8 lbl_803CB7CC[7] = { 0, 1, 2, 3, 4, 5, 6 };

static inline SoundFile* SceneFileAt(s32 id) {
    return &lbl_800EEFD0[id];
}

// .text:0x80021064 size:0x124
void fn_80021064(void) {
    SceneTask* task = lbl_803CC1B8;

    fn_80034E20((struct SpaniTask*)task, (struct SpaniDesc*)lbl_800EF3B0);
    lbl_80371C30[task->slot].sprite->flags &= ~2;
    lbl_80371C30[task->slot + 1].sprite->flags &= ~2;
    lbl_80371C30[task->slot + 2].sprite->flags &= ~2;
    lbl_80371C30[task->slot + 3].sprite->flags &= ~2;
    lbl_80371C30[task->slot + 4].sprite->flags &= ~2;
    lbl_8037169C._0E = 0;
    lbl_8037169C.scene = 0;
    lbl_8037169C.next = 0;
    lbl_8037169C._13 = 0;
    lbl_8037169C._12 = 0;
    lbl_8037169C._16 = 0;
    lbl_8037169C._17 = 0;
    lbl_8037169C.tex = NULL;
    lbl_8037169C.step = 0;
    lbl_8037169C._1A = 0;
    lbl_8037169C._1B = 0xFF;
    task->_1C = 0;
    task->_1E = 0;
    task->_18 = 0;
    task->_1A = 0;
    lbl_803CC1B8->func = fn_800206FC;
}

// .text:0x800206FC size:0x968
void fn_800206FC(void) {
}

// .text:0x80020624 size:0xD8
void fn_80020624(void) {
    SceneTask* task = lbl_803CC1B8;

    if (lbl_8037169C._16 != 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    fn_80034E20((struct SpaniTask*)task, (struct SpaniDesc*)lbl_800EF470);
    if (lbl_8037169C.scene == 7) {
        lbl_80371C30[task->slot].sprite->_68 = 1;
        lbl_80371C30[task->slot].sprite->_5C = 0;
    }
    lbl_80371C30[task->slot].sprite->flags |= 2;
    lbl_8037169C._16 = 1;
    lbl_803CC1B8->func = fn_8002059C;
}

// .text:0x8002059C size:0x88
void fn_8002059C(void) {
    SceneTask* task = lbl_803CC1B8;

    if (lbl_8037169C.scene == 7 && lbl_80371C30[task->slot].sprite->_69 == 2) {
        lbl_8037169C._12 = 1;
        lbl_8037169C.scene = 0;
    } else {
        lbl_8037169C._12 = 0;
        return;
    }
    lbl_8037169C._16 = 0;
    fn_80034CEC((struct SpaniTask*)task);
    fn_800B0A14_removeQueue();
}

// .text:0x800204CC size:0xD0
void changeScene(u8 scene, s16 arg1) {
    if (scene == 7) {
        lbl_8037169C._0C = arg1;
        lbl_8037169C.scene = 7;
        fn_800B0A5C_insertQueue(fn_80020624, 2);
        return;
    }
    if (scene == 1 || scene == 6 || scene == 13) {
        if (lbl_8037169C.scene >= 4 && lbl_8037169C.scene <= 6) {
            scene = 6;
        } else if (lbl_8037169C.scene >= 10 && lbl_8037169C.scene <= 12) {
            scene = 10;
        } else if (lbl_8037169C.scene >= 13 && lbl_8037169C.scene <= 15) {
            scene = 13;
        } else {
            scene = 1;
        }
    }
    lbl_8037169C.next = scene;
    lbl_8037169C._0C = arg1;
}

// .text:0x800203E0 size:0xEC
void fn_800203E0(u8 scene, s8 arg1) {
    if (arg1 >= 0) {
        lbl_8037169C._14 = arg1;
    }
    if (scene == 7) {
        lbl_8037169C.scene = 7;
        lbl_8037169C._0C = 1;
        fn_800B0A5C_insertQueue(fn_80020624, 2);
        return;
    }
    if (scene == 1 || scene == 6 || scene == 13) {
        if (lbl_8037169C.scene >= 4 && lbl_8037169C.scene <= 6) {
            scene = 6;
        } else if (lbl_8037169C.scene >= 10 && lbl_8037169C.scene <= 12) {
            scene = 10;
        } else if (lbl_8037169C.scene >= 13 && lbl_8037169C.scene <= 15) {
            scene = 13;
        } else {
            scene = 1;
        }
    }
    lbl_8037169C.next = scene;
    lbl_8037169C._0C = 1;
}

// .text:0x80020388 size:0x58
BOOL fn_80020388(void) {
    return fn_80035838(&lbl_800EEFD0[lbl_803CB7CC[g_d_GameSettings.StadiumID] + 38], 13) != 0;
}

// .text:0x80020278 size:0x110
BOOL fn_80020278(s32 id) {
    SoundFile* file;

    if (lbl_8037169C.step == 0) {
        file = SceneFileAt(id + 45);
        lbl_8037169C.tex = fn_800ACF34(0x20, file->size & 0x0FFFFFFF);
        ARAMTransfer(file, lbl_8037169C.tex, 1, 0);
        lbl_8037169C._18 = id;
        lbl_8037169C._1A = 0;
        lbl_8037169C.step++;
    } else if (lbl_8037169C.step == 1) {
        if (lbl_803C6CF8._715 != 1) {
            return FALSE;
        }
        convertTextureHeader(lbl_8037169C.tex);
        lbl_8037169C.image = (u8*)lbl_8037169C.tex + (*(u16*)((u8*)lbl_8037169C.tex + 0x20) << 5) + 4;
        lbl_8037169C.step = 2;
        return TRUE;
    }
    return FALSE;
}

// .text:0x8002024C size:0x2C
void fn_8002024C(void) {
    fn_800ACF14(lbl_8037169C.tex);
}

// .text:0x80020218 size:0x34
BOOL fn_80020218(void) {
    if (lbl_8037169C.scene == 13 || lbl_8037169C.scene == 14 || lbl_8037169C.scene == 15) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x80020048 size:0x1D0
s16 calledWhenStartingMatch(void) {
    struct {
        s16 weight;
        s16 id;
    } list[10];
    s32 i;
    s32 n;
    s32 total;
    s32 r;

    if (g_d_GameSettings._00 == 0) {
        g_d_GameSettings._00 |= 1;
        return 0;
    }
    for (i = 0; i < 10; i++) {
        list[i].weight = 0;
        list[i].id = -1;
    }
    i = 0;
    n = 0;
    total = 0;
    for (; i < 17; i++) {
        if ((lbl_800E86BC[i].stadium < 0 || g_d_GameSettings.StadiumID == lbl_800E86BC[i].stadium) && lbl_8037169C._1B != i) {
            if (g_d_GameSettings._00 & (1 << i)) {
                list[n].weight = lbl_800E86BC[i].weightSeen;
            } else {
                list[n].weight = lbl_800E86BC[i].weight;
            }
            total += list[n].weight;
            list[n].id = i;
            n++;
        }
    }
    r = rand() % total;
    for (i = 0; i < n; i++) {
        r -= list[i].weight;
        if (r < 0) {
            g_d_GameSettings._00 |= 1 << list[i].id;
            return list[i].id;
        }
    }
    return 0;
}

// Differs: the target adds 0.0f + 640.0f and 0.0f + 256.0f at run time (the build folds them),
// and float registers of the vertex copies shift by one.
// .text:0x8001FE00 size:0x248
void fn_8001FE00(SceneTask* task) {
    SceneVtx vtx[4];
    struct {
        Vec pos;
        f32 w;
    } quad[4];
    Mtx trans;
    Mtx m;
    f32 x;
    f32 y;
    f32 scale;
    f32 z;
    s32 alpha;
    u32 color;
    SceneSprite* sprite;

    if (lbl_8037169C.step < 2) {
        return;
    }
    if (lbl_8037169C.scene == 13) {
        lbl_8037169C._1A = lbl_8037169C._0E;
    } else {
        alpha = lbl_8037169C._1A + 16;
        if (alpha > 255) {
            alpha = 255;
        }
        lbl_8037169C._1A = alpha;
    }
    sprite = lbl_80371C30[task->slot + 4].sprite;
    sprite->color = (sprite->color & 0xFFFFFF00) | lbl_8037169C._1A;
    fn_8000FE08(task->_1C, 0, lbl_8037169C._18 + 0x92);
    fn_800B2160(1);
    PSMTXTrans(trans, -320.0f, -224.0f, 0.0f);
    scale = lbl_803CBBE0 / lbl_803CBBDC;
    x = 0.0f;
    y = 0.0f;
    quad[0].pos.x = x;
    quad[0].pos.y = y;
    quad[0].pos.z = 0.0f;
    quad[1].pos.x = x + 640.0f;
    quad[1].pos.y = y;
    quad[1].pos.z = 0.0f;
    quad[2].pos.x = x;
    quad[2].pos.y = y + 256.0f;
    quad[2].pos.z = 0.0f;
    quad[3].pos.x = x + 640.0f;
    quad[3].pos.y = y + 256.0f;
    quad[3].pos.z = 0.0f;
    PSMTXScale(m, scale, scale, 1.0f);
    PSMTXConcat(m, trans, m);
    PSMTXMultVec(m, &quad[0].pos, &quad[0].pos);
    PSMTXMultVec(m, &quad[1].pos, &quad[1].pos);
    PSMTXMultVec(m, &quad[2].pos, &quad[2].pos);
    PSMTXMultVec(m, &quad[3].pos, &quad[3].pos);
    z = -lbl_803CBBE0;
    color = lbl_8037169C._1A - 0x100;
    vtx[0].pos.x = quad[0].pos.x;
    vtx[0].pos.y = quad[0].pos.y;
    vtx[0].pos.z = z;
    vtx[0].color = color;
    vtx[1].pos.x = quad[2].pos.x;
    vtx[1].pos.y = quad[2].pos.y;
    vtx[1].pos.z = z;
    vtx[1].color = color;
    vtx[2].pos.x = quad[3].pos.x;
    vtx[2].pos.y = quad[3].pos.y;
    vtx[2].pos.z = z;
    vtx[2].color = color;
    vtx[3].pos.x = quad[1].pos.x;
    vtx[3].pos.y = quad[1].pos.y;
    vtx[3].pos.z = z;
    vtx[3].color = color;
    vtx[0].s = 0;
    vtx[0].t = 0;
    vtx[1].s = 0;
    vtx[1].t = 0x400;
    vtx[2].s = 0x400;
    vtx[2].t = 0x400;
    vtx[3].s = 0x400;
    vtx[3].t = 0;
    DrawSprite_TexObj(vtx, lbl_8037169C.image, 0);
}
