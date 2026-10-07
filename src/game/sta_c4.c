#include "game/sta_c4.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "Dolphin/rand.h"
#include "C3/control.h"
#include "musyx/musyx.h"
#include "game/rep_23E8.h"
#include "game/m_sound.h"
#include "math.h"
#include "string.h"

typedef struct StaC4Particle {
    /* 0x00 */ struct StaC4Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ u8 _1C[0x38 - 0x1C];
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 life;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 index;
} StaC4Particle;

typedef struct StaC4Emitter {
    /* 0x00 */ struct StaC4Emitter* prev;
    /* 0x04 */ struct StaC4Emitter* next;
    /* 0x08 */ BOOL (*update)(struct StaC4Emitter*);
    /* 0x0C */ StaC4Particle* particles;
    /* 0x10 */ void* _10;
} StaC4Emitter;

typedef struct {
    /* 0x00 */ f32 length;
    /* 0x04 */ u8 _04[0x10 - 0x4];
} StaC4AnimSeq; // size: 0x10

typedef struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ StaC4AnimSeq* _04;
} StaC4AnimSeqs;

typedef struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ StaC4AnimSeqs* _04;
} StaC4AnimBank;

typedef struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ u32 _04;
} StaC4TexRegs;

typedef struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ StaC4TexRegs* _04;
} StaC4TexInfo;

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ StaC4TexInfo* _10;
} StaC4TexMap;

typedef struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ StaC4TexMap* _14;
} StaC4Material;

typedef struct {
    /* 0x00 */ StaC4Material* _00;
} StaC4Materials;

typedef struct {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ StaC4Materials* _18;
} StaC4Actor;

typedef struct {
    /* 0x00 */ StaC4Actor* _00;
    /* 0x04 */ StaC4AnimBank* _04;
    /* 0x08 */ u8 _08[0xE - 0x8];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u8 _10[0x54 - 0x10];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u8 _64[0x68 - 0x64];
    /* 0x68 */ s32 _68;
    /* 0x6C */ u8 _6C[0x90 - 0x6C];
} StaC4Model; // size: 0x90

typedef struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ u8 _04[0x5C - 0x4];
} StaC4Anim; // size: 0x5C

typedef struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} StaC4Geom;

typedef struct StaC4Hit {
    /* 0x00 */ Vec x;
    /* 0x0C */ Vec n;
} StaC4Hit;

typedef struct StaC4Obj {
    /* 0x00 */ Control control;
    /* 0x3C */ u8 _3C[0x74 - 0x3C];
    /* 0x74 */ StaC4Model* _74;
    /* 0x78 */ StaC4Geom* _78;
    /* 0x7C */ void (*_7C)(struct StaC4Draw* draw);
    /* 0x80 */ void (*_80)(s32 idx, void* arg1, StaC4Hit* hit);
    /* 0x84 */ void (*_84)(void);
    /* 0x88 */ u8 _88[0x8C - 0x88];
    /* 0x8C */ void* _8C;
    /* 0x90 */ u8 _90_7 : 1;
    /* 0x90 */ u8 _90_6 : 1;
    /* 0x90 */ u8 _90_5 : 1;
    /* 0x90 */ u8 _90_0 : 5;
    /* 0x91 */ u8 _91;
    /* 0x92 */ u8 _92;
    /* 0x93 */ u8 _93;
    /* 0x94 */ s16 _94;
    /* 0x96 */ s16 _96;
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99[0x9C - 0x99];
    /* 0x9C */ f32 frame;
} StaC4Obj; // size: 0xA0

typedef struct StaC4Draw {
    /* 0x00 */ StaC4Obj obj;
    /* 0xA0 */ u8 _A0;
    /* 0xA1 */ u8 _A1;
    /* 0xA2 */ u8 _A2;
    /* 0xA3 */ u8 _A3;
    /* 0xA4 */ u8 _A4[0xE8 - 0xA4];
} StaC4Draw; // size: 0xE8

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ u8 type;
    /* 0x11 */ u8 visible;
    /* 0x12 */ u8 group;
    /* 0x13 */ u8 _13;
} StaC4Prop; // size: 0x14

typedef struct {
    /* 0x00 */ Vec min;
    /* 0x0C */ Vec max;
} StaC4Bounds; // size: 0x18

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 timer;
    /* 0x12 */ u16 _12;
    /* 0x14 */ u16 _14;
} StaC4Task;

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 timer;
    /* 0x12 */ u16 _12;
    /* 0x14 */ StaC4Draw* draw;
} StaC4FlashTask;

typedef struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u16 _12;
    /* 0x14 */ Vec vel;
    /* 0x20 */ Vec offset;
    /* 0x2C */ s32 idx;
    /* 0x30 */ u8 bounced;
} StaC4ShakeTask;

typedef struct {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ f32 _48;
    /* 0x4C */ f32 _4C;
    /* 0x50 */ f32 _50;
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ s32 _5C;
    /* 0x60 */ u8 _60[0x69 - 0x60];
    /* 0x69 */ u8 _69;
} StaC4Sprite;

typedef struct {
    /* 0x00 */ StaC4Sprite* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} StaC4SpriteRef; // size: 0x8

typedef struct StaC4Tex {
    /* 0x00 */ void* image;
    /* 0x04 */ void* tlut;
    /* 0x08 */ u16 height;
    /* 0x0A */ u16 width;
    /* 0x0C */ u8 wrapS;
    /* 0x0D */ u8 wrapT;
    /* 0x0E */ u8 minFilter;
    /* 0x0F */ u8 magFilter;
    /* 0x10 */ f32 lodBias;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 minLOD;
    /* 0x16 */ u8 maxLOD;
    /* 0x17 */ u8 format;
    /* 0x18 */ u16 tlutEntries;
    /* 0x1A */ u8 tlutFormat;
} StaC4Tex;

extern struct {
    /* 0x00 */ StaC4Draw* _00;
    /* 0x04 */ u8* _04;
    /* 0x08 */ void* _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ void* _10;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ void (*_18)(void);
    /* 0x1C */ void (*_1C)(void);
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32* _34;
    /* 0x38 */ u8 _38[0x3C - 0x38];
    /* 0x3C */ s32* _3C;
    /* 0x40 */ u16* _40;
    /* 0x44 */ s32* _44;
    /* 0x48 */ StaC4Bounds* _48;
    /* 0x4C */ Vec _4C;
    /* 0x58 */ Vec _58;
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[0x6B - 0x66];
    /* 0x6B */ u8 _6B;
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D;
} lbl_3_common_bss_350E4;

extern struct {
    /* 0x00 */ u8 _00[0x6C];
    /* 0x6C */ struct {
        /* 0x00 */ u8 _00[0x34];
        /* 0x34 */ StaC4Model _34[1];
    }* _6C;
} lbl_8036E548;

extern StaC4SpriteRef lbl_80371C30[];
extern void* lbl_803CC1B8;

extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];

// Only this unit reads these; they lie outside its splits.txt ranges.
extern void (*lbl_3_data_1BA88[4])(s32 idx, void* arg1, StaC4Hit* hit);
extern StaC4Prop lbl_3_data_1BA98[50];

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_80033620(StaC4Emitter* emitter);
extern void fn_8003403C(f32, f32);
extern void fn_80033CC8(StaC4Particle* particle, void* arg1);
extern StaC4Emitter* fn_80033A24(BOOL (*update)(StaC4Emitter*), s32, s32, s32, s32, s32);
extern s32 fn_800247E4(s32 x, s32 y, s32 width, s32 bytes);
extern void fn_800528C0(s16* x, s16* y, f32, f32, f32);
extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), u16);
extern void fn_80034CEC(StaC4Task* task);
extern void AnimateActorBones(StaC4Actor* actor);
extern void ACTSetAnimation(StaC4Actor* actor, StaC4AnimBank* animBank, char* sequenceName, u16 seqNum, f32 time, f32 speed);
extern void fn_800B4CA0(StaC4Actor*, f32);
extern void fn_800B4C04(StaC4Actor*, f32);
extern void fn_800B4AFC(StaC4Actor*, s32);
extern void fn_3_B8414(Vec* min, Vec* max);
extern void fn_3_B8464(Mtx m, StaC4Geom* geom);
extern void fn_3_B8574(void);
extern void fn_3_B9510(s32 idx);
extern u8* fn_3_B9534(u16 width, u16 height, GXTexObj* obj);

static const Vec lbl_3_rodata_2FB8 = { 0.0f, 0.5f, 60.0f };

// MWCC lays out .bss statics in reverse order of declaration
static u8 lbl_3_bss_B664;
static void* lbl_3_bss_B660;
static GXTexObj lbl_3_bss_B640;
static u8* lbl_3_bss_B63C;
static u8 lbl_3_bss_B630[9];
static u16 lbl_3_bss_B62C;
static StaC4Task* lbl_3_bss_B628;
static u8 lbl_3_bss_B620[6];
static Vec lbl_3_bss_B5D8[6];
static u8 lbl_3_bss_B5D4;
static StaC4Anim lbl_3_bss_B578;
static s32 lbl_3_bss_B574;
static u8 lbl_3_bss_B570;

// .text:0x000FBBA0 size:0x130 mapped:0x8073AC34
void fn_3_FBBA0(StaC4Tex* tex) {
    GXTexObj obj;
    GXTlutObj tlut;

    if (tex->tlut != NULL) {
        GXInitTexObjCI(&obj, tex->image, tex->width, tex->height, tex->format, tex->wrapS, tex->wrapT,
                       tex->minLOD != tex->maxLOD, GX_TLUT0);
        GXInitTlutObj(&tlut, tex->tlut, tex->tlutFormat, tex->tlutEntries);
        GXLoadTlut(&tlut, GX_TLUT0);
    } else {
        GXInitTexObj(&obj, tex->image, tex->width, tex->height, tex->format, tex->wrapS, tex->wrapT,
                     tex->minLOD != tex->maxLOD);
    }
    GXInitTexObjLOD(&obj, tex->minFilter, tex->magFilter, tex->minLOD, tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE,
                    GX_ANISO_1);
    GXLoadTexObj(&obj, GX_TEXMAP0);
}

// .text:0x000FB3D8 size:0x7C8 mapped:0x8073A46C
void fn_3_FB3D8(void) {
    return;
}

// .text:0x000FA58C size:0xE4C mapped:0x80739620
void fn_3_FA58C(void) {
    return;
}

// .text:0x000FA3C0 size:0x1CC mapped:0x80739454
void fn_3_FA3C0(void) {
    Mtx m;
    StaC4Prop* prop;
    StaC4Draw* draw;
    s32 size;
    s32 count;
    s32 i;
    s32 j;
    u16 next;

    size = lbl_3_common_bss_350E4._30 * sizeof(StaC4Bounds) + lbl_3_common_bss_350E4._30 * sizeof(s32) +
           lbl_3_common_bss_350E4._30 * sizeof(s32) + lbl_3_common_bss_350E4._30 * sizeof(u16);
    if (lbl_3_common_bss_350E4._48 == NULL) {
        lbl_3_common_bss_350E4._48 = _OSAllocFromHeap(4, size);
        lbl_3_common_bss_350E4._3C = (s32*)(lbl_3_common_bss_350E4._48 + lbl_3_common_bss_350E4._30);
        lbl_3_common_bss_350E4._44 = lbl_3_common_bss_350E4._3C + lbl_3_common_bss_350E4._30;
        lbl_3_common_bss_350E4._40 = (u16*)(lbl_3_common_bss_350E4._44 + lbl_3_common_bss_350E4._30);
    }
    memset(lbl_3_common_bss_350E4._48, 0, size);
    count = 0;
    for (i = 0; i < 10; i++) {
        lbl_3_common_bss_350E4._40[count] = lbl_3_common_bss_350E4._40[count - 1] + lbl_3_common_bss_350E4._3C[count - 1];
        next = lbl_3_common_bss_350E4._40[count];
        fn_3_B8574();
        prop = lbl_3_data_1BA98;
        for (j = 0; j < lbl_3_common_bss_350E4._30; j++, prop++) {
            if (i == prop->group && lbl_3_common_bss_350E4._00[j].obj._90_6) {
                lbl_3_common_bss_350E4._44[next++] = j;
                lbl_3_common_bss_350E4._3C[count]++;
                draw = &lbl_3_common_bss_350E4._00[j];
                CTRLBuildMatrix(&draw->obj.control, m);
                fn_3_B8464(m, draw->obj._78);
            }
        }
        if (lbl_3_common_bss_350E4._3C[count] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[count].min, &lbl_3_common_bss_350E4._48[count].max);
            count++;
        }
    }
    lbl_3_common_bss_350E4._64 = count;
}

// .text:0x000F9E78 size:0x548 mapped:0x80738F0C
void fn_3_F9E78(s32 idx, void* arg1, StaC4Hit* hit) {
    f32 x;
    f32 y;
    f32 z;
    StaC4Draw* draw = &lbl_3_common_bss_350E4._00[idx];
    StaC4Draw* entry;
    StaC4Model* model;
    StaC4ShakeTask* shake;
    StaC4FlashTask* flash;
    s32 i;

    fn_3_F9164(draw);
    if (draw->_A2 == 0) {
        for (i = 0; i < 9; i++) {
            if (lbl_3_bss_B630[i] == 0xFF) {
                entry = &lbl_3_common_bss_350E4._00[lbl_3_bss_B62C + i];
                entry->obj._74 = &lbl_8036E548._6C->_34[i + 5];
                entry->obj._78 = NULL;
                entry->obj._7C = fn_3_F9D94;
                entry->obj._80 = NULL;
                entry->obj._90_6 = 0;
                entry->obj._90_7 = 1;
                entry->obj._74->_5B = 2;
                entry->obj._74->_5C = 0.0f;
                entry->obj._74->_59 = 1;
                entry->obj._74->_54 = 1.0f;
                entry->obj._74->_5A = 1;
                entry->obj._74->_68 = 0;
                model = entry->obj._74;
                ACTSetAnimation(model->_00, model->_04, NULL, model->_0E, 0.0f, model->_60);
                fn_800B4CA0(model->_00, model->_5C);
                fn_800B4C04(model->_00, model->_54);
                fn_800B4AFC(model->_00, model->_5B & 1);
                entry->obj.frame = 0.0f;
                entry->obj.control.type = 0;
                CTRLSetTranslation(&entry->obj.control, lbl_3_data_1BA98[idx].pos.x, lbl_3_data_1BA98[idx].pos.y,
                                   lbl_3_data_1BA98[idx].pos.z);
                CTRLSetRotation(&entry->obj.control, 0.0f, lbl_3_data_1BA98[idx].rotY, 0.0f);
                lbl_3_bss_B630[i] = entry->_A0;
                break;
            }
        }
        draw = &lbl_3_common_bss_350E4._00[idx];
        draw->obj._74 = NULL;
        draw->obj._78 = NULL;
        draw->obj._7C = NULL;
        draw->obj._80 = NULL;
        draw->obj._90_7 = 0;
        draw->obj._90_6 = 0;
        if (gameInitOptions.starSkillsSetting) {
            CTRLGetTranslation(&draw->obj.control, &x, &y, &z);
            fn_3_CB7E8(x, y, z);
        }
        lbl_3_common_bss_350E4._00[lbl_3_bss_B62C + idx + 9].obj._90_7 = 0;
        return;
    }
    if (draw->_A2 == 2) {
        fn_3_F963C(idx, hit);
    }
    draw->obj._74 = &lbl_8036E548._6C->_34[draw->_A2];
    draw->obj._80 = lbl_3_data_1BA88[draw->_A2];
    draw->obj._90_6 = draw->obj._90_7 && draw->obj._78 != NULL;
    draw->obj._90_5 = 0;
    flash = fn_800B0A5C_insertQueue(fn_3_F92FC, 0);
    flash->timer = 90;
    flash->draw = draw;
}

// .text:0x000F9D94 size:0xE4 mapped:0x80738E28
void fn_3_F9D94(StaC4Draw* draw) {
    StaC4Model* model = draw->obj._74;
    s32 i;

    if (draw->obj.frame >= model->_04->_04->_04[model->_0E].length) {
        draw->obj._90_7 = 0;
        draw->obj._74 = NULL;
        draw->obj._78 = NULL;
        draw->obj._7C = NULL;
        draw->obj._80 = NULL;
        draw->obj._90_6 = 0;
        for (i = 0; i < 9; i++) {
            if (lbl_3_bss_B630[i] == draw->_A0) {
                lbl_3_bss_B630[i] = 0xFF;
                return;
            }
        }
    } else {
        AnimateActorBones(model->_00);
        draw->obj.frame += 1.0f;
    }
}

// .text:0x000F9B9C size:0x1F8 mapped:0x80738C30
void fn_3_F9B9C(s32 idx, void* arg1, StaC4Hit* hit) {
    StaC4Draw* draw = &lbl_3_common_bss_350E4._00[idx];
    StaC4FlashTask* flash;

    draw->_A1 = draw->_A2;
    if (draw->_A1 == 0) {
        fn_3_F9E78(idx, arg1, hit);
        return;
    }
    if (draw->_A1 == 2) {
        fn_3_F963C(idx, hit);
    }
    draw->obj._74 = &lbl_8036E548._6C->_34[draw->_A2];
    draw->obj._80 = lbl_3_data_1BA88[draw->_A2];
    draw->obj._90_6 = draw->obj._90_7 && draw->obj._78 != NULL;
    draw->obj._80(idx, arg1, hit);
    draw->obj._90_5 = 0;
    flash = fn_800B0A5C_insertQueue(fn_3_F92FC, 0);
    flash->timer = 90;
    flash->draw = draw;
}

// .text:0x000F99F0 size:0x1AC mapped:0x80738A84
void fn_3_F99F0(s32 idx, void* arg1, StaC4Hit* hit) {
    fn_3_F9164(&lbl_3_common_bss_350E4._00[idx]);
}

// .text:0x000F976C size:0x284 mapped:0x80738800
void fn_3_F976C(s32 idx, void* arg1, StaC4Hit* hit) {
    fn_3_F9164(&lbl_3_common_bss_350E4._00[idx]);
    fn_3_F963C(idx, hit);
}

// .text:0x000F963C size:0x130 mapped:0x807386D0
void fn_3_F963C(s32 idx, StaC4Hit* hit) {
    StaC4ShakeTask* task;

    lbl_3_common_bss_350E4._6B = 1;
    task = fn_800B0A5C_insertQueue(fn_3_F934C, ((StaC4Task*)lbl_803CC1B8)->_12 + 1);
    memcpy(&lbl_3_common_bss_350E4._4C, &g_Ball, sizeof(Vec));
    memcpy(&lbl_3_common_bss_350E4._58, &g_Ball.physicsSubstruct.velocity, sizeof(Vec));
    lbl_3_common_bss_350E4._4C.y = -lbl_3_common_bss_350E4._4C.y;
    lbl_3_common_bss_350E4._58.y = -lbl_3_common_bss_350E4._58.y;
    if (hit != NULL) {
        PSVECScale(&hit->n, -1.0f, &task->vel);
    }
    memset(&task->offset, 0, sizeof(Vec));
    task->idx = idx;
    task->bounced = 0;
    lbl_3_common_bss_350E4._00[task->idx].obj._90_6 = 0;
}

// .text:0x000F934C size:0x2F0 mapped:0x807383E0
void fn_3_F934C(void) {
    StaC4ShakeTask* task = lbl_803CC1B8;
    Vec* pos = &lbl_3_common_bss_350E4._4C;
    Vec* vel = &lbl_3_common_bss_350E4._58;
    Vec tmp;
    Vec offset;
    f32 mag;
    f32 speed;

    memcpy(&tmp, vel, sizeof(Vec));
    PSVECScale(&task->vel, PSVECDotProduct(&task->vel, &tmp), &tmp);
    PSVECAdd(&task->offset, &tmp, &offset);
    mag = PSVECMag(&offset);
    PSVECAdd(pos, vel, &tmp);
    if (task->bounced) {
        speed = PSVECMag(vel) + 0.1f * mag;
    } else {
        speed = PSVECMag(vel) - 0.1f * mag;
    }
    memcpy(&task->offset, &offset, sizeof(Vec));
    memcpy(pos, &tmp, sizeof(Vec));
    if (task->bounced && (fabs(PSVECMag(&offset)) <= 0.000001f ||
                          (task->vel.x * offset.x >= 0.0f && task->vel.y * offset.y >= 0.0f &&
                           task->vel.z * offset.z >= 0.0f))) {
        memset(&task->offset, 0, sizeof(Vec));
        lbl_3_common_bss_350E4._6B = 0;
        fn_800B0A14_removeQueue();
    } else if (speed <= 0.0f) {
        task->bounced = 1;
        PSVECScale(&task->vel, -1.0f, &task->vel);
        PSVECScale(&task->vel, 0.1f * mag, vel);
    } else {
        PSVECNormalize(vel, &tmp);
        PSVECScale(&tmp, speed, vel);
    }
    CTRLSetTranslation(&lbl_3_common_bss_350E4._00[task->idx].obj.control,
                       task->offset.x + lbl_3_data_1BA98[task->idx].pos.x,
                       task->offset.y + lbl_3_data_1BA98[task->idx].pos.y,
                       task->offset.z + lbl_3_data_1BA98[task->idx].pos.z);
    CTRLGetTranslation(&lbl_3_common_bss_350E4._00[task->idx + (lbl_3_bss_B62C + 9)].obj.control, &tmp.x, &tmp.y,
                       &tmp.z);
    CTRLSetTranslation(&lbl_3_common_bss_350E4._00[task->idx + (lbl_3_bss_B62C + 9)].obj.control,
                       task->offset.x + lbl_3_data_1BA98[task->idx].pos.x, tmp.y,
                       task->offset.z + lbl_3_data_1BA98[task->idx].pos.z);
}

// .text:0x000F92FC size:0x50 mapped:0x80738390
void fn_3_F92FC(void) {
    StaC4FlashTask* task = lbl_803CC1B8;

    if (task->timer-- == 0) {
        task->draw->obj._90_5 = 1;
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000F9164 size:0x198 mapped:0x807381F8
void fn_3_F9164(StaC4Draw* draw) {
    s32 sound;
    s32 slot;
    u32 stadium;
    SND_VOICEID voice;
    u8 vol;

    switch (draw->_A2) {
    case 0:
        sound = 2;
        slot = g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy;
        break;
    case 1:
        sound = 1;
        slot = g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy + 2;
        break;
    case 2:
        sound = 0;
        slot = g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy + 4;
        break;
    }
    stadium = g_d_GameSettings.StadiumID;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][0];
    } else {
        vol = lbl_3_data_8404[stadium][sound][0];
    }
    voice = sndFXStartEx(lbl_3_data_81DC[stadium] + sound, vol, 63, 0);
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][1];
    } else {
        vol = lbl_3_data_8404[stadium][sound][1];
    }
    sndFXCtrl(voice, 91, vol);
    lbl_3_bss_B5D8[slot].x = g_Ball.AtBat_Contact_BallPos.x;
    lbl_3_bss_B5D8[slot].y = -g_Ball.AtBat_Contact_BallPos.y;
    lbl_3_bss_B5D8[slot].z = g_Ball.AtBat_Contact_BallPos.z;
    lbl_3_bss_B620[slot] = 1;
}

// .text:0x000F9088 size:0xDC mapped:0x8073811C
void fn_3_F9088(Vec* pos, s32 i) {
    s16 x;
    s16 y;

    fn_800528C0(&x, &y, pos->x, pos->y, pos->z);
    lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_48 = x;
    lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_4C = y;
    lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_50 = 0.0f;
}

// .text:0x000F8E20 size:0x268 mapped:0x80737EB4
void fn_3_F8E20(void) {
    StaC4Task* task = lbl_803CC1B8;
    s16 x;
    s16 y;
    s32 i;

    for (i = 0; i < 6; i++) {
        switch (lbl_3_bss_B620[i]) {
        case 1:
            fn_800528C0(&x, &y, lbl_3_bss_B5D8[i].x, lbl_3_bss_B5D8[i].y, lbl_3_bss_B5D8[i].z);
            lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_48 = x;
            lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_4C = y;
            lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_50 = 0.0f;
            lbl_80371C30[task->_14 + i]._00->_5C = 0;
            lbl_80371C30[task->_14 + i]._00->_54 |= 2;
            lbl_3_bss_B620[i] = 2;
            break;
        case 2:
            fn_800528C0(&x, &y, lbl_3_bss_B5D8[i].x, lbl_3_bss_B5D8[i].y, lbl_3_bss_B5D8[i].z);
            lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_48 = x;
            lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_4C = y;
            lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_50 = 0.0f;
            if (lbl_80371C30[task->_14 + i]._00->_69 == 2) {
                lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                lbl_3_bss_B620[i] = 0;
            }
            break;
        }
    }
    if (lbl_3_bss_B5D4) {
        fn_800B0A14_removeQueue();
        fn_80034CEC(lbl_3_bss_B628);
        lbl_3_bss_B5D4 = 0;
    }
}

// .text:0x000F8D00 size:0x120 mapped:0x80737D94
void fn_3_F8D00(void) {
    Mtx23 mtx;
    u32 x;
    u32 y;
    s32 offset;

    mtx[0][0] = 0.5f;
    mtx[0][1] = 0.0f;
    mtx[0][2] = 0.0f;
    mtx[1][0] = 0.0f;
    mtx[1][1] = 0.5f;
    mtx[1][2] = 0.0f;
    GXSetIndTexMtx(GX_ITM_0, mtx, 2);
    lbl_3_bss_B63C = fn_3_B9534(0x80, 0x80, &lbl_3_bss_B640);
    if (lbl_3_bss_B63C == NULL) {
        OSErrorLine(1759, "error\n");
    }
    for (y = 0; y < 0x80; y++) {
        for (x = 0; x < 0x80; x++) {
            offset = fn_800247E4(x, y, 0x80, 2);
            lbl_3_bss_B63C[offset] = (u8)(rand() % 4) + 0x7E;
        }
    }
}

// .text:0x000F8BA8 size:0x158 mapped:0x80737C3C
void fn_3_F8BA8(StaC4Draw* draw) {
    StaC4TexRegs* regs = draw->obj._74->_00->_18->_00->_14->_10->_04;
    u32 x;
    u32 y;
    s8 prev;
    s8 next;
    s32 offset;

    if (draw->_A3 != 0 && draw->_A3 % 3 == 0) {
        draw->_A2++;
        if (draw->_A2 > 25) {
            draw->_A2 = 10;
            draw->_A3 = 0;
        }
        regs->_04 &= ~0x1FFF;
        regs->_04 |= draw->_A2;
        for (x = 0; x < 0x80; x++) {
            for (y = 0; y < 0x80; y++) {
                if (y == 0) {
                    offset = fn_800247E4(x, 0x7F, 0x80, 2);
                    prev = lbl_3_bss_B63C[offset];
                }
                offset = fn_800247E4(x, y, 0x80, 2);
                next = lbl_3_bss_B63C[offset];
                lbl_3_bss_B63C[offset] = prev;
                prev = next;
            }
        }
        DCFlushRange(lbl_3_bss_B63C, 0x8000);
    }
    draw->_A3++;
}

// .text:0x000F8B34 size:0x74 mapped:0x80737BC8
void fn_3_F8B34(void) {
    fn_3_B9510(0);
    GXLoadTexObj(&lbl_3_bss_B640, GX_TEXMAP7);
    GXSetIndTexOrder(GX_IND_TEX_STAGE_0, GX_TEXCOORD0, GX_TEXMAP7);
    GXSetNumIndStages(1);
    GXSetIndTexCoordScale(GX_IND_TEX_STAGE_0, GX_ITS_1, GX_ITS_1);
    GXSetTevIndWarp(GX_TEVSTAGE0, GX_IND_TEX_STAGE_0, GX_FALSE, GX_FALSE, GX_ITM_0);
}

// .text:0x000F8B30 size:0x4 mapped:0x80737BC4
void fn_3_F8B30(void) {
    return;
}

// .text:0x000F8B04 size:0x2C mapped:0x80737B98
void fn_3_F8B04(void) {
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
}

// .text:0x000F8ABC size:0x48 mapped:0x80737B50
void fn_3_F8ABC(void) {
    StaC4Emitter* emitter = fn_80033A24(fn_3_F85B0, 0xF0, 0xD, 0x2A, 1, 0x7F);

    if (emitter != NULL) {
        fn_3_F8878(emitter);
    }
}

// .text:0x000F8878 size:0x244 mapped:0x8073790C
void fn_3_F8878(StaC4Emitter* emitter) {
    s16 delay;
    StaC4Particle* p = emitter->particles;
    u32 i;
    f32 prev;
    f32 angle;

    emitter->_10 = lbl_3_bss_B660;
    i = 0;
    delay = 0;
    for (; p != NULL; p = p->next) {
        p->vel.y = 0.123f;
        if (!(i & 1)) {
            angle = (i % 6) * 60;
            if ((i / 6) % 2 == 1) {
                angle += 30.0f;
            }
        } else {
            angle = 180.0f + prev;
        }
        prev = angle;
        p->vel.x = 0.05 * cosf_kludge(0.017453292f * angle);
        p->vel.z = 0.05 * sinf_kludge(0.017453292f * angle);
        p->delay = delay;
        delay += 3;
        p->index = i;
        i++;
        p->pos.x = lbl_3_rodata_2FB8.x;
        p->pos.y = lbl_3_rodata_2FB8.y - 2.0;
        p->pos.z = lbl_3_rodata_2FB8.z;
        p->_38 = 0.75f;
        p->_3C = 4.0f;
        p->color[3] = p->color[0] = p->color[1] = p->color[2] = 0xFF;
        p->life = 0x80;
        p->_4D = 0x1B;
        p->_4E = 0;
    }
}

// .text:0x000F85B0 size:0x2C8 mapped:0x80737644
BOOL fn_3_F85B0(StaC4Emitter* emitter) {
    StaC4Particle* p = emitter->particles;

    if (g_GameLogic.gameStatus >= GAME_STATUS_0x1B && g_GameLogic.gameStatus <= GAME_STATUS_MINIGAME_READY) {
        return FALSE;
    }
    fn_80033620(emitter);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    do {
        if (p->delay <= 0 && p->life != 0) {
            fn_8003403C(p->_38, p->_3C);
            fn_80033CC8(p, emitter->_10);
            if (-p->delay < 0x40) {
                p->color[3] += -2.390625;
                p->_38 += 0.05078125;
            } else {
                p->_38 += 0.046875;
                p->color[3] += -1.59375f;
                if (p->color[3] > 102.0) {
                    p->color[3] = 0;
                }
            }
            p->pos.x += p->vel.x;
            p->pos.y -= p->vel.y;
            p->pos.z += p->vel.z;
            p->vel.y -= 0.003;
            p->life--;
        }
        p->delay--;
        if (p->life == 0) {
            fn_3_F8524(p);
        }
    } while ((p = p->next) != NULL);
    return FALSE;
}

// .text:0x000F8524 size:0x8C mapped:0x807375B8
void fn_3_F8524(StaC4Particle* p) {
    if (p->index < 42) {
        p->vel.y = 0.123f;
        p->pos.x = lbl_3_rodata_2FB8.x;
        p->pos.y = lbl_3_rodata_2FB8.y - 2.0;
        p->pos.z = lbl_3_rodata_2FB8.z;
        p->_38 = 0.75f;
        p->_3C = 4.0f;
    }
    p->color[3] = p->color[0] = p->color[1] = p->color[2] = 0xFF;
    p->life = 0x80;
    p->delay = 0;
}

// .text:0x000F8454 size:0xD0 mapped:0x807374E8
void fn_3_F8454(void) {
    if (g_GameLogic.gameStatus == GAME_STATUS_PAUSED) {
        if (lbl_3_bss_B664 == 0) {
            fn_3_8B890(lbl_3_bss_B574);
            lbl_3_bss_B664 = 1;
        }
    } else if (lbl_3_bss_B664 != 0) {
        lbl_3_bss_B574 = fn_3_8BBC4(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 3, NULL, NULL, 2);
        lbl_3_bss_B664 = 0;
    } else {
        fn_3_8BA60(lbl_3_bss_B574, NULL, NULL);
    }
}

// .text:0x000F8444 size:0x10 mapped:0x807374D8
void fn_3_F8444(void) {
    lbl_3_bss_B5D4 = 1;
}
