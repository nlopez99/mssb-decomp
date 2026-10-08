#include "game/rep_1FD8.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/rand.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtxext.h"
#include "C3/control.h"
#include "C3/geoPalette.h"
#include "game/rep_1D58.h"

typedef struct Rep1FD8Sprite {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ Vec _48;
    /* 0x54 */ u32 _54;
    /* 0x58 */ u8 _58[0x5C - 0x58];
    /* 0x5C */ s32 _5C;
    /* 0x60 */ u8 _60[0x69 - 0x60];
    /* 0x69 */ u8 _69;
} Rep1FD8Sprite;

typedef struct Rep1FD8SpriteRef {
    /* 0x00 */ Rep1FD8Sprite* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} Rep1FD8SpriteRef; // size: 0x8

typedef struct Rep1FD8Task {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ u16 _14;
} Rep1FD8Task;

typedef struct Rep1FD8Particle {
    /* 0x00 */ struct Rep1FD8Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ f32 grow;
    /* 0x20 */ f32 growScale;
    /* 0x24 */ f32 alpha;
    /* 0x28 */ u8 _28[0x38 - 0x28];
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 life;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 duration;
} Rep1FD8Particle;

typedef struct Rep1FD8Spawner {
    /* 0x00 */ u8 _00[0x0C];
    /* 0x0C */ Rep1FD8Particle* particles;
    /* 0x10 */ void* _10;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ Vec pos;
    /* 0x24 */ u8 idx;
    /* 0x25 */ u8 _25;
} Rep1FD8Spawner;

extern u32 fn_8005268C(void);
extern camera_803c639c_s* fn_80052734(s32 idx);
extern void fn_80033CC8(Rep1FD8Particle* p, void* texture);
extern void fn_8003403C(f32 width, f32 height);
extern void fn_80033620(Rep1FD8Spawner* emitter);
extern Rep1FD8Spawner* fn_80033A24(BOOL (*update)(Rep1FD8Spawner*), s32, s32, s32, s32, s32);
extern Rep1FD8Task* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800528C0(f32 x, f32 y, f32 z, s16* screenX, s16* screenY);
extern Rep1FD8SpriteRef lbl_80371C30[];
extern void* lbl_803CC1B8;
extern void fn_800B0A14_removeQueue(void);
extern void fn_80034CEC(Rep1FD8Task* task);
extern void fn_8003A8A0(struct DODisplayObj* obj, MtxPtr view, s32 arg2);

static const u8 lbl_3_rodata_2028[3] = { 0xA0, 0x46, 0x00 };
static const Vec lbl_3_rodata_202C[6] = {
    { -19.3f, -14.5f, 86.0f },
    { 19.3f, -14.5f, 86.0f },
    { -15.92f, -18.8f, 112.16f },
    { 15.92f, -18.8f, 112.16f },
    { -36.5f, -17.9f, -22.8f },
    { 36.5f, -17.9f, -22.8f },
};

// .bss, declared in reverse address order (MWCC lays .bss statics out last to first)
static void* lbl_3_bss_9F0C[5];
static u8 lbl_3_bss_9E54[0xB8];
static Rep1FD8Task* lbl_3_bss_9E50;
static u8 lbl_3_bss_9E48[8];
static Vec lbl_3_bss_9DE8[8];
static u8 lbl_3_bss_9DE7;
static u8 lbl_3_bss_9DE6;
static u8 lbl_3_bss_9DE5;
static u8 lbl_3_bss_9DE4;
static u8 lbl_3_bss_9DE3;
static u8 lbl_3_bss_9DE2;
static u8 lbl_3_bss_9DE1;
static u8 lbl_3_bss_9DE0;
static u8 lbl_3_bss_9DA0[0x40];
static s32 lbl_3_bss_9D9C;
static u8* lbl_3_bss_9D98;
static StadiumObject1D58* lbl_3_bss_9D94;
static s32 lbl_3_bss_9D90;
static s32 lbl_3_bss_9D8C;
static s32 lbl_3_bss_9D88;
static s32 lbl_3_bss_9D84;
static u8 lbl_3_bss_9D82;
static u8 lbl_3_bss_9D81;
static u8 lbl_3_bss_9D80;

// .text:0x000C8650 size:0xD2C mapped:0x807076E4
void fn_3_C8650(void) {
    return;
}

// .text:0x000C82B4 size:0x39C mapped:0x80707348
void fn_3_C82B4(void) {
    return;
}

// .text:0x000C823C size:0x78 mapped:0x807072D0
struct StadiumObjectCollision* fn_3_C823C(s32 idx, MtxPtr mtx) {
    return NULL;
}

// .text:0x000C805C size:0x1E0 mapped:0x807070F0
void fn_3_C805C(void) {
    return;
}

// .text:0x000C7A0C size:0x650 mapped:0x80706AA0
void fn_3_C7A0C(void) {
    return;
}

// .text:0x000C77AC size:0x260 mapped:0x80706840
void fn_3_C77AC(void) {
    return;
}

// .text:0x000C75B8 size:0x1F4 mapped:0x8070664C
void fn_3_C75B8(void) {
    return;
}

// .text:0x000C749C size:0x11C mapped:0x80706530
void fn_3_C749C(void) {
    return;
}

// .text:0x000C7444 size:0x58 mapped:0x807064D8
void fn_3_C7444(void) {
    return;
}

// .text:0x000C71CC size:0x278 mapped:0x80706260
void fn_3_C71CC(void) {
    return;
}

// .text:0x000C63D0 size:0xDFC mapped:0x80705464
void fn_3_C63D0(void) {
    return;
}

// .text:0x000C625C size:0x174 mapped:0x807052F0
void fn_3_C625C(void) {
    return;
}

// .text:0x000C5DDC size:0x480 mapped:0x80704E70
void fn_3_C5DDC(void) {
    return;
}

// .text:0x000C5CE0 size:0xFC mapped:0x80704D74
void fn_3_C5CE0(void) {
    return;
}

// .text:0x000C597C size:0x364 mapped:0x80704A10
void fn_3_C597C(void) {
    return;
}

// .text:0x000C56E8 size:0x294 mapped:0x8070477C
void fn_3_C56E8(void) {
    return;
}

// .text:0x000C54D0 size:0x218 mapped:0x80704564
void fn_3_C54D0(void) {
    return;
}

// .text:0x000C5304 size:0x1CC mapped:0x80704398
void fn_3_C5304(void) {
    return;
}

// .text:0x000C4F00 size:0x404 mapped:0x80703F94
void fn_3_C4F00(void) {
    return;
}

// .text:0x000C4CF4 size:0x20C mapped:0x80703D88
void fn_3_C4CF4(void) {
    return;
}

// .text:0x000C4B80 size:0x174 mapped:0x80703C14
void fn_3_C4B80(void) {
    return;
}

// .text:0x000C48D0 size:0x2B0 mapped:0x80703964
void fn_3_C48D0(void) {
    return;
}

// .text:0x000C4724 size:0x1AC mapped:0x807037B8
void fn_3_C4724(void) {
    return;
}

// .text:0x000C444C size:0x2D8 mapped:0x807034E0
void fn_3_C444C(void) {
    return;
}

// .text:0x000C42A4 size:0x1A8 mapped:0x80703338
void fn_3_C42A4(void) {
    return;
}

// .text:0x000C414C size:0x158 mapped:0x807031E0
void fn_3_C414C(void) {
    return;
}

// .text:0x000C40EC size:0x60 mapped:0x80703180
void fn_3_C40EC(void) {
    return;
}

// .text:0x000C4068 size:0x84 mapped:0x807030FC
void fn_3_C4068(void) {
    return;
}

// .text:0x000C3F70 size:0xF8 mapped:0x80703004
void fn_3_C3F70(void) {
    return;
}

// .text:0x000C3E94 size:0xDC mapped:0x80702F28
void fn_3_C3E94(Vec* pos, s32 i) {
    s16 x;
    s16 y;

    fn_800528C0(pos->x, pos->y, pos->z, &x, &y);
    lbl_80371C30[lbl_3_bss_9E50->_14 + i]._00->_48.x = x;
    lbl_80371C30[lbl_3_bss_9E50->_14 + i]._00->_48.y = y;
    lbl_80371C30[lbl_3_bss_9E50->_14 + i]._00->_48.z = 0.0f;
}

static inline BOOL isSpriteDone(Rep1FD8Task* task, s32 i) {
    return lbl_80371C30[task->_14 + i]._00->_69 == 2 ? TRUE : FALSE;
}

// .text:0x000C3C2C size:0x268 mapped:0x80702CC0
void fn_3_C3C2C(void) {
    Rep1FD8Task* task = lbl_803CC1B8;
    s32 i;

    for (i = 0; i < 8; i++) {
        switch (lbl_3_bss_9E48[i]) {
        case 1:
            fn_3_C3E94(&lbl_3_bss_9DE8[i], i);
            lbl_80371C30[task->_14 + i]._00->_5C = 0;
            lbl_80371C30[task->_14 + i]._00->_54 |= 2;
            lbl_3_bss_9E48[i] = 2;
            break;
        case 2:
            fn_3_C3E94(&lbl_3_bss_9DE8[i], i);
            if (isSpriteDone(task, i)) {
                lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                lbl_3_bss_9E48[i] = 0;
            }
            break;
        }
    }
    if (lbl_3_bss_9DE7) {
        fn_800B0A14_removeQueue();
        fn_80034CEC(lbl_3_bss_9E50);
        lbl_3_bss_9DE7 = 0;
    }
}

// .text:0x000C3A38 size:0x1F4 mapped:0x80702ACC
void fn_3_C3A38(void) {
    return;
}

// .text:0x000C39C8 size:0x70 mapped:0x80702A5C
void fn_3_C39C8(void) {
    Rep1FD8Spawner* spawner;
    u32 i;

    for (i = 0; i < 6; i++) {
        spawner = fn_80033A24(fn_3_C30F0, 128, 0, 21, 1, 0);
        if (spawner != NULL) {
            fn_3_C366C(spawner, i);
        }
    }
}

// .text:0x000C366C size:0x35C mapped:0x80702700
void fn_3_C366C(Rep1FD8Spawner* spawner, u8 idx) {
    Rep1FD8Particle* p = spawner->particles;
    s32 i;
    f32 angle;
    s32 life;

    spawner->_10 = lbl_3_bss_9F0C[0];
    spawner->pos = lbl_3_rodata_202C[idx];
    spawner->idx = idx;
    for (i = 0; p != NULL; i++, p = p->next) {
        angle = rand() % 360;
        angle = 0.017453292f * angle;
        p->vel.x = 0.01 * cosf_kludge(angle);
        p->vel.z = 0.01 * sinf_kludge(angle);
        p->vel.y = 0.08f;
        p->delay = i * 4;
        p->grow = 0.5f;
        p->grow += (u32)rand() % 2500 / 1000.0;
        p->_38 = p->grow;
        p->_3C = 2.0 * p->grow;
        p->growScale = rand() % 101 / 100.0;
        p->pos.x = spawner->pos.x;
        p->pos.y = spawner->pos.y;
        p->pos.z = spawner->pos.z;
        p->color[0] = lbl_3_rodata_2028[0];
        p->color[1] = lbl_3_rodata_2028[1];
        p->color[2] = lbl_3_rodata_2028[2];
        p->color[3] = p->alpha = 255.0f;
        life = rand() % 24 + 72;
        p->life = life;
        p->duration = life;
        p->_4D = 29;
        p->_4E = 0;
    }
}

// .text:0x000C30F0 size:0x57C mapped:0x80702184
BOOL fn_3_C30F0(Rep1FD8Spawner* spawner) {
    Rep1FD8Particle* p = spawner->particles;
    Vec pos;

    if (g_GameLogic.gameStatus >= 27 && g_GameLogic.gameStatus <= 33) {
        return FALSE;
    }
    if (g_GameLogic.gameStatus == 2 || g_GameLogic.gameStatus == 1) {
        pos = spawner->pos;
        if (!fn_3_C2AA0(&pos, 4.0f, 4.0f)) {
            return FALSE;
        }
    }
    fn_80033620(spawner);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_CLEAR);
    do {
        if (p->delay <= 0 && p->life != 0) {
            fn_8003403C(p->_38, p->_3C);
            fn_80033CC8(p, spawner->_10);
            if (fn_8005268C() == 0) {
                fn_3_C2EDC(p);
            }
        }
        p->delay -= fn_8005268C() == 0;
        if (p->life == 0) {
            fn_3_C2C80(p, spawner);
        }
        p = p->next;
    } while (p != NULL);
    return FALSE;
}

// .text:0x000C2EDC size:0x214 mapped:0x80701F70
void fn_3_C2EDC(Rep1FD8Particle* p) {
    p->_38 += p->growScale * (3.0 * p->grow / p->duration);
    p->_3C += p->growScale * (2.0 * p->grow / p->duration);
    p->alpha += -255.0f / p->duration;
    if (p->alpha < 0.0f) {
        p->alpha = 0.0f;
    }
    p->color[3] = p->alpha;
    p->color[0] = lbl_3_rodata_2028[0] * (p->color[3] / 255.0);
    p->color[1] = lbl_3_rodata_2028[1] * (p->color[3] / 255.0);
    p->color[2] = lbl_3_rodata_2028[2] * (p->color[3] / 255.0);
    p->pos.x += p->vel.x;
    p->pos.y -= p->vel.y;
    p->pos.z += p->vel.z;
    p->life--;
}

// .text:0x000C2C80 size:0x25C mapped:0x80701D14
void fn_3_C2C80(Rep1FD8Particle* p, Rep1FD8Spawner* spawner) {
    f32 angle = 0.017453292f * (rand() % 360);

    p->vel.x = 0.01 * cosf_kludge(angle);
    p->vel.z = 0.01 * sinf_kludge(angle);
    p->vel.y = 0.08f;
    p->grow = 0.5f;
    p->grow += (u32)rand() % 2500 / 1000.0;
    p->_38 = p->grow;
    p->_3C = 2.0 * p->grow;
    p->growScale = rand() % 101 / 100.0;
    p->duration = p->life = rand() % 24 + 72;
    p->pos.x = spawner->pos.x;
    p->pos.y = spawner->pos.y;
    p->pos.z = spawner->pos.z;
    p->color[0] = lbl_3_rodata_2028[0];
    p->color[1] = lbl_3_rodata_2028[1];
    p->color[2] = lbl_3_rodata_2028[2];
    p->color[3] = p->alpha = 255.0f;
    p->life = p->duration;
    p->delay = 0;
}

// .text:0x000C2AA0 size:0x1E0 mapped:0x80701B34
// 93.77%, as sta_c2's identical fn_3_CD968: the target loads pos->x before pos->y for the
// corners and computes them in other FPRs.
u8 fn_3_C2AA0(Vec* pos, f32 width, f32 height) {
    Vec out;
    Vec corners[4];
    camera_803c639c_s* camera;
    u32 i;
    u8 code;
    u8 all = 0;
    f32 left;
    f32 right;
    f32 bottom;
    f32 top;

    camera = fn_80052734(fn_8005268C());
    PSMTXMultVec(camera->view, pos, pos);
    if (pos->z > -1.0f || pos->z < -512.0f) {
        return FALSE;
    }
    bottom = pos->y - height * 0.5f;
    right = pos->x + width * 0.5f;
    left = pos->x - width * 0.5f;
    top = pos->y + height * 0.5f;
    corners[0].z = corners[1].z = corners[2].z = corners[3].z = pos->z;
    corners[0].x = corners[3].x = left;
    corners[1].x = corners[2].x = right;
    corners[0].y = corners[1].y = bottom;
    corners[3].y = corners[2].y = top;
    for (i = 0; i < 4; i++) {
        PSMTX44MultVec(camera->proj, &corners[i], &out);
        code = out.x < -1.0f;
        code |= (out.x > 1.0f) << 1;
        code |= (out.y < -1.0f) << 2;
        code |= (out.y > 1.0f) << 3;
        if (code == 0) {
            return TRUE;
        }
        all &= code;
    }
    if ((all & 3U) == 1 || (all & 3U) == 2) {
        return FALSE;
    }
    if ((all & 0xCU) == 4 || (all & 0xCU) == 8) {
        return FALSE;
    }
    return TRUE;
}

// .text:0x000C298C size:0x114 mapped:0x80701A20
void fn_3_C298C(void) {
    return;
}

// .text:0x000C2974 size:0x18 mapped:0x80701A08
void fn_3_C2974(void) {
    lbl_3_bss_9DE7 = 1;
    lbl_3_bss_9D82 = 1;
}

// .text:0x000C2644 size:0x330 mapped:0x807016D8
void fn_3_C2644(void) {
    return;
}

// .text:0x000C24A0 size:0x1A4 mapped:0x80701534
void fn_3_C24A0(void) {
    return;
}

// .text:0x000C23E0 size:0xC0 mapped:0x80701474
void fn_3_C23E0(void) {
    return;
}

// .text:0x000C2310 size:0xD0 mapped:0x807013A4
void fn_3_C2310(StadiumModel1D58* model, Mtx view) {
    Mtx mv;
    Mtx m;
    ModelActor1D58* actor;
    ModelBone1D58* bone;

    CTRLBuildMatrix(&lbl_3_bss_9D94->control, m);
    PSMTXConcat(view, m, mv);
    actor = model->actor;
    bone = actor->drawHead;
    if (actor->skinObject != NULL) {
        if (actor->_7C != NULL) {
            fn_8003A8A0(actor->skinObject, mv, 1);
        } else {
            DOVARenderSkin(actor->skinObject, mv, actor->skinMtxArray, actor->skinInvTransposeMtxArray, 0, NULL);
        }
    }
    while (bone != NULL) {
        if (bone->_014 != NULL) {
            DOSetWorldMatrix(bone->_014, bone->_0EC);
            fn_8003A8A0(bone->_014, mv, 0);
        }
        bone = bone->_100;
    }
}

// .text:0x000C2244 size:0xCC mapped:0x807012D8
void fn_3_C2244(void) {
    return;
}

// .text:0x000C1C18 size:0x62C mapped:0x80700CAC
void fn_3_C1C18(void) {
    return;
}

// .text:0x000C19C8 size:0x250 mapped:0x80700A5C
void fn_3_C19C8(void) {
    return;
}

// .text:0x000C1974 size:0x54 mapped:0x80700A08
void fn_3_C1974(u8* stadium) {
    Rep1FD8Task* task = fn_800B0A5C_insertQueue(fn_3_C2644, 4);

    task->_10 = 0;
    lbl_3_bss_9D98 = stadium + 0x3C4;
    lbl_3_bss_9D9C = 0;
}

// .text:0x000C1964 size:0x10 mapped:0x807009F8
void fn_3_C1964(void) {
    lbl_3_bss_9D9C = 1;
}
