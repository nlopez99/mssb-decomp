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
#include "game/rep_D0.h"
#include "game/rep_1C0.h"
#include "game/sta_c0.h"
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

typedef struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ void* _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ u8* _10;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
    /* 0x18 */ u16 _18;
} StaC4Tiles; // size: 0x1C

typedef struct {
    /* 0x00 */ u8 id;
    /* 0x01 */ u8 value[2];
} StaC4MaterialSwap; // size: 0x3

typedef struct {
    /* 0x00 */ StaC4MaterialSwap _00[2][2][2];
    /* 0x18 */ void* _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ u8 _20;
} StaC4Swaps;

typedef struct StaC4View {
    /* 0x00 */ u8 _00[0x38];
    /* 0x38 */ Mtx _38;
} StaC4View;

extern struct {
    /* 0x00 */ StaC4Draw* _00;
    /* 0x04 */ u8* _04;
    /* 0x08 */ StaC4Tiles* _08;
    /* 0x0C */ StaC4Tiles* _0C;
    /* 0x10 */ StaC4Swaps* _10;
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
    /* 0x3C */ u32* _3C;
    /* 0x40 */ u16* _40;
    /* 0x44 */ s32* _44;
    /* 0x48 */ Vec* _48;
    /* 0x4C */ Vec _4C;
    /* 0x58 */ Vec _58;
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[0x6B - 0x66];
    /* 0x6B */ u8 _6B;
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D;
} lbl_3_common_bss_350E4;

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ StaC4Model _34[1];
} StaC4ActorTable;

extern struct {
    /* 0x00 */ u8 _00[0x6C];
    /* 0x6C */ StaC4ActorTable* _6C;
} lbl_8036E548;

extern StaC4SpriteRef lbl_80371C30[];
extern void* lbl_803CC1B8;

extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_10E9C[0xE0];
extern u8 lbl_3_data_10F7C[8];
extern u8 lbl_3_data_10F84[4];
extern u8 lbl_3_data_10F88[0x80];
extern u8 lbl_3_data_11008[0x40];
extern u8 lbl_3_data_110A8[0x20][3];
extern u8 lbl_3_data_11138[0x10][3];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];

// Only this unit reads these; they lie outside its splits.txt ranges.
extern void (*lbl_3_data_1BA88[4])(s32 idx, void* arg1, StaC4Hit* hit);
extern StaC4Prop lbl_3_data_1BA98[50];
extern u8 lbl_3_data_1BE80[17];
extern Vec lbl_3_data_1BF6C[21];
extern u8 lbl_3_data_1C068[20][3];

extern void* _OSAllocFromHeap(u32 align, u32 size);
// Outside this unit's .text range, but only this unit references it.
extern void fn_3_FBCD0(void);
extern void fn_8003A144(void);
extern void fn_80035750(void* arg0, void* arg1, s32 arg2);
extern void fn_80034E20(StaC4Task* task, void* desc);
extern StaC4ActorTable* ActorObjectInitTable(u16 count);
extern void fn_800BDC88(StaC4ActorTable* actors, u16 first, u16 last, void* model, void* anim, s32 arg5);
extern void fn_800BD548(StaC4Model* model, s32 count, ...);
extern void fn_80025C58(void* anim, StaC4Model* model);
extern void fn_80025DDC(void* anim);
extern void fn_80025FFC(void* anim, StaC4Anim* state);
extern void fn_80025EEC(StaC4Anim* state, s32, s32);
extern void fn_3_B97C8(void (*callback)(void));
extern void fn_3_B97DC(StaC4Model* model, void* anim);
extern void fn_3_B9D68(u8* types, s32 count, void** files, s32* indices);
extern StaC4Tex* fn_80039AB4(void);
extern void fn_800245EC(camera_803c639c_s* camera, Mtx view, Vec* points, f32* out, s32 count, s32 arg5);
extern void fn_800ACFB0(void* data);
extern void fn_80033620(StaC4Emitter* emitter);
extern void fn_8003403C(f32, f32);
extern void fn_80033CC8(StaC4Particle* particle, void* arg1);
extern StaC4Emitter* fn_80033A24(BOOL (*update)(StaC4Emitter*), s32, s32, s32, s32, s32);
extern s32 fn_800247E4(s32 x, s32 y, s32 width, s32 bytes);
extern void fn_800528C0(f32 x, f32 y, f32 z, s16* screenX, s16* screenY);
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
void fn_3_FB3D8(StaC4View* view) {
    f32 center[21][2];
    Vec diff;
    Vec step;
    GXTexObj obj;
    GXTlutObj tlut;
    StaC4Tex* tex;
    f32* uv;
    Vec* pos;
    s32 n;
    MtxPtr mtx;
    camera_803c639c_s* camera;
    f32 minY;
    f32 minX;
    f32 maxY;
    f32 maxX;
    f32 y;
    f32 x;
    f32 width;
    f32 height;
    s32 i;
    s32 j;
    s32 b;
    s32 c;

    fn_8003A144();
    uv = _OSAllocFromHeap(4, 420 * (2 * sizeof(f32) + sizeof(Vec)));
    pos = (Vec*)(uv + 420 * 2);
    n = 0;
    for (i = 0; i < 21; i++) {
        if (i == 20) {
            continue;
        }
        PSVECSubtract(&lbl_3_data_1BF6C[i], &lbl_3_data_1BF6C[20], &diff);
        for (j = 1; j <= 20; j++) {
            PSVECScale(&diff, j / 22.0f, &step);
            PSVECAdd(&lbl_3_data_1BF6C[20], &step, &pos[n]);
            n++;
        }
    }
    camera = fn_80052768_getCamera(0);
    mtx = view->_38;
    fn_800245EC(camera, mtx, lbl_3_data_1BF6C, center[0], 21, 1);
    fn_800245EC(fn_80052768_getCamera(0), mtx, pos, uv, 400, 1);
    minX = minY = 16777215.0f;
    maxX = maxY = -minX;
    for (i = 0; i < 800; i += 2) {
        x = uv[i];
        if (minX > x) {
            minX = x;
        }
        if (maxX < x) {
            maxX = x;
        }
        y = uv[i + 1];
        if (minY > y) {
            minY = y;
        }
        if (maxY < y) {
            maxY = y;
        }
    }
    width = 0.005f * (maxX - minX);
    height = 0.005f * (maxY - minY);
    for (i = 0; i < 800; i += 2) {
        uv[i] += width * (rand() % 256) / 256.0f - 0.0025f;
        uv[i + 1] += height * (rand() % 256) / 256.0f - 0.0025f;
    }
    tex = fn_80039AB4();
    fn_3_FBBA0(tex);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetCullMode(GX_CULL_NONE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_OR);
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetNumTevStages(1);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetChanCtrl(GX_COLOR0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_ALPHA0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
    GXLoadPosMtxImm(mtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    for (i = 0; i < 20; i++) {
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, 43);
        GXPosition3f32(lbl_3_data_1BF6C[lbl_3_data_1C068[i][0]].x, 0.01f + lbl_3_data_1BF6C[lbl_3_data_1C068[i][0]].y,
                       lbl_3_data_1BF6C[lbl_3_data_1C068[i][0]].z);
        GXColor1u32(0xFFFFFFFF);
        GXTexCoord2f32(center[lbl_3_data_1C068[i][0]][0], center[lbl_3_data_1C068[i][0]][1]);
        b = lbl_3_data_1C068[i][1];
        c = lbl_3_data_1C068[i][2];
        for (j = 0; j < 20; j++) {
            GXPosition3f32(pos[b * 20 + j].x, 0.01f + pos[b * 20 + j].y, pos[b * 20 + j].z);
            GXColor1u32(0xFFFFFFFF);
            GXTexCoord2f32(uv[(b * 20 + j) * 2], uv[(b * 20 + j) * 2 + 1]);
            GXPosition3f32(pos[c * 20 + j].x, 0.01f + pos[c * 20 + j].y, pos[c * 20 + j].z);
            GXColor1u32(0xFFFFFFFF);
            GXTexCoord2f32(uv[(c * 20 + j) * 2], uv[(c * 20 + j) * 2 + 1]);
        }
        GXPosition3f32(lbl_3_data_1BF6C[b].x, 0.01f + lbl_3_data_1BF6C[b].y, lbl_3_data_1BF6C[b].z);
        GXColor1u32(0xFFFFFFFF);
        GXTexCoord2f32(center[b][0], center[b][1]);
        GXPosition3f32(lbl_3_data_1BF6C[c].x, 0.01f + lbl_3_data_1BF6C[c].y, lbl_3_data_1BF6C[c].z);
        GXColor1u32(0xFFFFFFFF);
        GXTexCoord2f32(center[c][0], center[c][1]);
    }
    fn_800ACFB0(uv);
}

// .text:0x000FA58C size:0xE4C mapped:0x80739620
void fn_3_FA58C(void** files) {
    StaC4Swaps* swaps;
    StaC4Tiles* tiles;
    StaC4Prop* prop;
    s32* indices;
    StaC4Draw* entry;
    StaC4Draw* draw;
    u8* slot;
    void (*draw3D)(void);
    u32 size;
    s32 i;
    s32 k;
    BOOL end;
    s32 count;

    draw3D = fn_3_FBCD0;
    count = 0;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        draw3D = NULL;
    }
    lbl_3_common_bss_350E4._18 = draw3D;
    lbl_3_common_bss_350E4._1C = fn_3_F8454;
    lbl_3_bss_B664 = 1;
    indices = lbl_3_common_bss_350E4._34 = _OSAllocFromHeap(4, 17 * sizeof(s32));
    fn_3_B9D68(lbl_3_data_1BE80, 17, files, indices);
    lbl_3_bss_B660 = files[0];
    fn_80035750(files[indices[16]], files[indices[15]], 5);
    lbl_3_bss_B628 = fn_800B0A5C_insertQueue(fn_3_F8E20, 2);
    fn_80034E20(lbl_3_bss_B628, lbl_3_data_10E9C);
    lbl_8036E548._6C = ActorObjectInitTable(16);
    fn_800BDC88(lbl_8036E548._6C, 0, 0, files[indices[1]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 1, 1, files[indices[3]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 2, 2, files[indices[4]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 3, 3, files[indices[5]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 4, 4, files[indices[6]], NULL, 0);
    for (i = 0; i < 9; i++) {
        fn_800BDC88(lbl_8036E548._6C, i + 5, i + 5, files[indices[2]], files[indices[2] + 2], 0);
        fn_3_B97DC(&lbl_8036E548._6C->_34[i + 5], files[indices[2] + 2]);
        lbl_8036E548._6C->_34[i + 5]._58 = 0;
    }
    fn_800BDC88(lbl_8036E548._6C, 14, 14, files[indices[7]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 15, 15, files[indices[8]], NULL, 0);
    lbl_3_common_bss_350E4._6D = 16;
    for (i = 0; i < 16; i++) {
        fn_800BD548(&lbl_8036E548._6C->_34[i], 4, lbl_3_common_bss_350E4._20, lbl_3_common_bss_350E4._24,
                    lbl_3_common_bss_350E4._28, lbl_3_common_bss_350E4._2C);
    }
    if (files[indices[13]] != NULL) {
        fn_80025DDC(files[indices[13]]);
        fn_80025C58(files[indices[13]], &lbl_8036E548._6C->_34[15]);
        lbl_3_bss_B578._00 = files[indices[14]];
        fn_80025FFC(files[indices[13]], &lbl_3_bss_B578);
        fn_80025EEC(&lbl_3_bss_B578, 0, 0);
    }

    lbl_3_common_bss_350E4._30 = 52;
    size = (52 * sizeof(StaC4Draw)) + (g_d_GameSettings.miniGameStadiumIndicator == 0 ? 0xEC : 0);
    lbl_3_common_bss_350E4._00 = _OSAllocFromHeap(0x20, size);
    memset(lbl_3_common_bss_350E4._00, 0, size);
    lbl_3_common_bss_350E4._04 = _OSAllocFromHeap(0x20, size);
    memset(lbl_3_common_bss_350E4._04, 0, size);
    if (g_d_GameSettings.miniGameStadiumIndicator == 0) {
        lbl_3_common_bss_350E4._08 = (StaC4Tiles*)(lbl_3_common_bss_350E4._04 + 52 * sizeof(StaC4Draw));
        lbl_3_common_bss_350E4._0C = lbl_3_common_bss_350E4._08 + 1;
        lbl_3_common_bss_350E4._08->_10 = (u8*)(lbl_3_common_bss_350E4._0C + 1);
        lbl_3_common_bss_350E4._0C->_10 = lbl_3_common_bss_350E4._08->_10 + 0x60;
        lbl_3_common_bss_350E4._10 = (StaC4Swaps*)(lbl_3_common_bss_350E4._0C->_10 + 0x30);
    } else {
        lbl_3_common_bss_350E4._08 = NULL;
        lbl_3_common_bss_350E4._0C = NULL;
        lbl_3_common_bss_350E4._10 = NULL;
    }

    draw = lbl_3_common_bss_350E4._00;
    entry = draw;
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
        slot = lbl_3_bss_B630;
        end = FALSE;
        lbl_3_bss_B62C = 0xFFFF;
        for (i = 0; i < 52; i++) {
            entry->_A0 = i;
            prop = &lbl_3_data_1BA98[i];
            if (prop->type == 5) {
                entry->_A1 = prop->type;
                if (lbl_3_bss_B62C == 0xFFFF) {
                    lbl_3_bss_B62C = i;
                }
                *slot++ = 0xFF;
                draw->obj._74 = &lbl_8036E548._6C->_34[i + 5];
                draw->obj._78 = NULL;
                draw->obj._7C = NULL;
                draw->obj._80 = NULL;
                draw->obj._90_7 = 0;
                draw->obj._90_6 = 0;
                draw->obj._90_5 = 0;
                draw->obj.control.type = 0;
            } else if (end) {
                entry->_A1 = 0;
                entry->_A2 = 0;
                draw->obj._74 = &lbl_8036E548._6C->_34[0];
                draw->obj._78 = files[indices[9]];
                draw->obj._7C = NULL;
                draw->obj._80 = NULL;
                draw->obj._90_7 = 0;
                draw->obj._90_6 = 0;
                draw->obj._90_5 = 1;
                draw->obj.control.type = 0;
                CTRLSetTranslation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
                CTRLSetRotation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
            } else {
                end = prop->type == 4;
                if (end) {
                    prop = lbl_3_data_1BA98;
                    for (k = 0; k < lbl_3_bss_B62C; prop++, k++) {
                        entry->_A1 = 0;
                        entry->_A2 = 0;
                        draw->obj._74 = &lbl_8036E548._6C->_34[4];
                        draw->obj._78 = NULL;
                        draw->obj._7C = NULL;
                        draw->obj._80 = NULL;
                        draw->obj._90_7 = prop->visible;
                        draw->obj._90_6 = 0;
                        draw->obj.control.type = 0;
                        CTRLSetTranslation(&draw->obj.control, prop->pos.x, -0.02f, prop->pos.z);
                        CTRLSetRotation(&draw->obj.control, 0.0f, prop->rotY, 0.0f);
                        draw->obj._92 = 0xFF;
                        draw->obj._90_5 = 0;
                        draw->obj._84 = NULL;
                        draw->obj._8C = NULL;
                        draw->obj._94 = 0;
                        draw->obj._96 = -1;
                        draw->obj._98 = 1;
                        i++;
                        entry = ++draw;
                    }
                    count = i;
                    i--;
                    draw--;
                } else {
                    entry->_A1 = prop->type;
                    entry->_A2 = prop->_13;
                    if (entry->_A1 == 3) {
                        if (entry->_A2 == 8) {
                            entry->_A2 = rand() % 3;
                        }
                    } else if (entry->_A1 == 0 && entry->_A2 == 8) {
                        entry->_A2 = rand() % 3;
                    } else {
                        entry->_A2 = entry->_A1;
                    }
                    draw->obj._74 = &lbl_8036E548._6C->_34[entry->_A1];
                    draw->obj._78 = files[indices[entry->_A2 + 9]];
                    draw->obj._7C = NULL;
                    draw->obj._80 = lbl_3_data_1BA88[entry->_A1];
                    draw->obj._90_7 = prop->visible;
                    draw->obj._90_6 = draw->obj._90_7 && draw->obj._78 != NULL;
                    draw->obj.control.type = 0;
                    CTRLSetTranslation(&draw->obj.control, prop->pos.x, prop->pos.y, prop->pos.z);
                    CTRLSetRotation(&draw->obj.control, 0.0f, prop->rotY, 0.0f);
                    draw->obj._90_5 = 1;
                }
            }
            draw->obj._92 = 0xFF;
            draw->obj._84 = NULL;
            draw->obj._8C = NULL;
            draw->obj._94 = 0;
            draw->obj._96 = -1;
            draw->obj._98 = 1;
            entry = ++draw;
        }
    }

    draw = &lbl_3_common_bss_350E4._00[count];
    draw->_A0 = 0x33;
    draw->_A1 = 6;
    draw->_A2 = 10;
    fn_3_F8ABC();
    draw->obj._74 = &lbl_8036E548._6C->_34[14];
    draw->obj._78 = NULL;
    draw->obj._7C = fn_3_F8BA8;
    draw->obj._80 = NULL;
    draw->obj._90_7 = 1;
    draw->obj._90_6 = draw->obj._90_7 && draw->obj._78 != NULL;
    draw->obj.control.type = 0;
    CTRLSetTranslation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
    CTRLSetRotation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
    draw->obj._90_5 = 1;
    draw->obj._92 = 0xFF;
    draw->obj._84 = fn_3_F8B34;
    draw->obj._8C = NULL;
    draw->obj._94 = 0;
    draw->obj._96 = -1;
    draw->obj._98 = 1;
    fn_3_F8D00();
    draw++;

    draw->_A0 = 0x33;
    draw->_A1 = 7;
    draw->obj._74 = &lbl_8036E548._6C->_34[15];
    draw->obj._78 = NULL;
    draw->obj._7C = NULL;
    draw->obj._80 = NULL;
    draw->obj._90_7 = 1;
    draw->obj._90_6 = draw->obj._90_7 && draw->obj._78 != NULL;
    draw->obj.control.type = 0;
    CTRLSetTranslation(&draw->obj.control, 0.0f, -0.01f, 0.0f);
    CTRLSetRotation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
    draw->obj._90_5 = 1;
    draw->obj._92 = 0xFF;
    draw->obj._84 = NULL;
    draw->obj._8C = &lbl_3_bss_B578;
    draw->obj._94 = 0;
    draw->obj._96 = -1;
    draw->obj._98 = 1;

    if (g_d_GameSettings.miniGameStadiumIndicator == 0) {
        lbl_3_common_bss_350E4._08->_0C = lbl_3_data_10F7C;
        lbl_3_common_bss_350E4._08->_08 = lbl_3_data_10F88;
        lbl_3_common_bss_350E4._08->_00 = (u8*)g_UNK_StadiumDetails._00 + 0x60;
        lbl_3_common_bss_350E4._08->_04 = (u8*)g_UNK_StadiumDetails._00 + 0x40;
        lbl_3_common_bss_350E4._08->_14 = 0x20;
        lbl_3_common_bss_350E4._08->_18 = 6;
        lbl_3_common_bss_350E4._08->_16 = 5;
        for (i = 0; i < 0x20; i++) {
            lbl_3_common_bss_350E4._08->_10[i * 3] = lbl_3_data_110A8[i][0];
            if (lbl_3_data_110A8[i][1] < 6) {
                lbl_3_common_bss_350E4._08->_10[i * 3 + 1] = lbl_3_data_110A8[i][1];
            } else {
                lbl_3_common_bss_350E4._08->_10[i * 3 + 1] = rand() % 6;
            }
            if (lbl_3_data_110A8[i][2] < 5) {
                lbl_3_common_bss_350E4._08->_10[i * 3 + 2] = lbl_3_data_110A8[i][2];
            } else {
                tiles = lbl_3_common_bss_350E4._08;
                tiles->_10[i * 3 + 2] = rand() % tiles->_16;
            }
        }

        lbl_3_common_bss_350E4._0C->_0C = lbl_3_data_10F84;
        lbl_3_common_bss_350E4._0C->_08 = lbl_3_data_11008;
        lbl_3_common_bss_350E4._0C->_00 = (u8*)g_UNK_StadiumDetails._00 + 0xA0;
        lbl_3_common_bss_350E4._0C->_04 = (u8*)g_UNK_StadiumDetails._00 + 0x80;
        lbl_3_common_bss_350E4._0C->_14 = 0x10;
        lbl_3_common_bss_350E4._0C->_18 = 2;
        lbl_3_common_bss_350E4._0C->_16 = 8;
        for (i = 0; i < 0x10; i++) {
            lbl_3_common_bss_350E4._0C->_10[i * 3] = lbl_3_data_11138[i][0];
            if (lbl_3_data_11138[i][1] < 2) {
                lbl_3_common_bss_350E4._0C->_10[i * 3 + 1] = lbl_3_data_11138[i][1];
            } else {
                lbl_3_common_bss_350E4._0C->_10[i * 3 + 1] = rand() % 6;
            }
            if (lbl_3_data_11138[i][2] < 8) {
                lbl_3_common_bss_350E4._0C->_10[i * 3 + 2] = lbl_3_data_11138[i][2];
            } else {
                tiles = lbl_3_common_bss_350E4._0C;
                tiles->_10[i * 3 + 2] = rand() % tiles->_16;
            }
        }

        fn_3_35E4(fn_3_C9878);
        swaps = lbl_3_common_bss_350E4._10;
        swaps->_18 = g_UNK_StadiumDetails._00;
        swaps->_20 = 2;
        swaps->_1C = cos(1.3962634801864624);
        swaps->_00[0][0][0].id = 8;
        swaps->_00[0][0][0].value[0] = 2;
        swaps->_00[0][0][0].value[1] = 7;
        swaps->_00[0][0][1].id = 4;
        swaps->_00[0][0][1].value[0] = 7;
        swaps->_00[0][0][1].value[1] = 4;
        swaps->_00[0][1][0].id = 9;
        swaps->_00[0][1][0].value[0] = 2;
        swaps->_00[0][1][0].value[1] = 7;
        swaps->_00[0][1][1].id = 10;
        swaps->_00[0][1][1].value[0] = 7;
        swaps->_00[0][1][1].value[1] = 4;
        swaps->_00[1][0][0].id = 8;
        swaps->_00[1][0][0].value[0] = 2;
        swaps->_00[1][0][0].value[1] = 7;
        swaps->_00[1][0][1].id = 4;
        swaps->_00[1][0][1].value[0] = 7;
        swaps->_00[1][0][1].value[1] = 4;
        swaps->_00[1][1][0].id = 9;
        swaps->_00[1][1][0].value[0] = 2;
        swaps->_00[1][1][0].value[1] = 7;
        swaps->_00[1][1][1].id = 10;
        swaps->_00[1][1][1].value[0] = 7;
        swaps->_00[1][1][1].value[1] = 4;
    }

    lbl_3_common_bss_350E4._48 = NULL;
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
        fn_3_FA3C0();
    }
    fn_3_B97C8(fn_3_F8444);
}

// .text:0x000FA3C0 size:0x1CC mapped:0x80739454
void fn_3_FA3C0(void) {
    Mtx m;
    StaC4Prop* prop;
    StaC4Draw* draw;
    s32 i;
    s32 j;
    s32 count;
    s32 next;
    s32 size;

    size = (lbl_3_common_bss_350E4._30 * sizeof(u16)) + (lbl_3_common_bss_350E4._30 * sizeof(u32)) +
           (lbl_3_common_bss_350E4._30 * sizeof(s32)) + (lbl_3_common_bss_350E4._30 * (2 * sizeof(Vec)));
    if (lbl_3_common_bss_350E4._48 == NULL) {
        lbl_3_common_bss_350E4._48 = _OSAllocFromHeap(4, size);
        lbl_3_common_bss_350E4._3C = (u32*)(lbl_3_common_bss_350E4._48 + lbl_3_common_bss_350E4._30 * 2);
        lbl_3_common_bss_350E4._44 = (s32*)(lbl_3_common_bss_350E4._3C + lbl_3_common_bss_350E4._30);
        lbl_3_common_bss_350E4._40 = (u16*)(lbl_3_common_bss_350E4._44 + lbl_3_common_bss_350E4._30);
    }
    memset(lbl_3_common_bss_350E4._48, 0, size);
    count = 0;
    for (i = 0; i < 10; i++) {
        next = lbl_3_common_bss_350E4._40[count] = lbl_3_common_bss_350E4._40[count - 1] + lbl_3_common_bss_350E4._3C[count - 1];
        fn_3_B8574();
        prop = lbl_3_data_1BA98;
        for (j = 0; j < lbl_3_common_bss_350E4._30; prop++, j++) {
            if (i == prop->group && lbl_3_common_bss_350E4._00[j].obj._90_6) {
                lbl_3_common_bss_350E4._44[next] = j;
                next++;
                lbl_3_common_bss_350E4._3C[count]++;
                draw = &lbl_3_common_bss_350E4._00[j];
                CTRLBuildMatrix(&draw->obj.control, m);
                fn_3_B8464(m, draw->obj._78);
            }
        }
        if (lbl_3_common_bss_350E4._3C[count] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[count * 2], &lbl_3_common_bss_350E4._48[count * 2 + 1]);
            count++;
        }
    }
    lbl_3_common_bss_350E4._64 = count;
}

static inline void setAnimMode(StaC4Model* model, u8 mode) {
    model->_5B = mode;
}

static inline void setAnimFrame(StaC4Model* model, f32 frame) {
    model->_5C = frame;
    model->_59 = 1;
}

static inline void setAnimSpeed(StaC4Model* model, f32 speed) {
    model->_54 = speed;
    model->_5A = 1;
}

static inline void startAnim(StaC4Model* model) {
    ACTSetAnimation(model->_00, model->_04, NULL, model->_0E, 0.0f, model->_60);
    fn_800B4CA0(model->_00, model->_5C);
    fn_800B4C04(model->_00, model->_54);
    fn_800B4AFC(model->_00, model->_5B & 1);
}

// .text:0x000F9E78 size:0x548 mapped:0x80738F0C
void fn_3_F9E78(s32 idx, void* arg1, StaC4Hit* hit) {
    Vec pos;
    StaC4Draw* draw = &lbl_3_common_bss_350E4._00[idx];
    StaC4Draw* entry;
    StaC4ShakeTask* shake;
    StaC4FlashTask* flash;
    s32 i;

    fn_3_F99F0(idx, arg1, hit);
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
                setAnimMode(entry->obj._74, 2);
                setAnimFrame(entry->obj._74, 0.0f);
                setAnimSpeed(entry->obj._74, 1.0f);
                entry->obj._74->_68 = 0;
                startAnim(entry->obj._74);
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
            CTRLGetTranslation(&draw->obj.control, &pos.x, &pos.y, &pos.z);
            fn_3_CB7E8(pos.x, pos.y, pos.z);
        }
        lbl_3_common_bss_350E4._00[lbl_3_bss_B62C + 9 + idx].obj._90_7 = 0;
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
    fn_3_F99F0(idx, arg1, hit);
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
    s32 shadow;

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
                          !(task->vel.x * offset.x < 0.0f || task->vel.y * offset.y < 0.0f ||
                            task->vel.z * offset.z < 0.0f))) {
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
    shadow = task->idx + lbl_3_bss_B62C + 9;
    CTRLGetTranslation(&lbl_3_common_bss_350E4._00[shadow].obj.control, &tmp.x, &tmp.y, &tmp.z);
    CTRLSetTranslation(&lbl_3_common_bss_350E4._00[shadow].obj.control,
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
    u32 stadium;
    s32 slot;
    s32 sound;
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
    lbl_3_bss_B620[slot] = 1;
    lbl_3_bss_B5D8[slot].x = g_Ball.AtBat_Contact_BallPos.x;
    lbl_3_bss_B5D8[slot].y = -g_Ball.AtBat_Contact_BallPos.y;
    lbl_3_bss_B5D8[slot].z = g_Ball.AtBat_Contact_BallPos.z;
}

// .text:0x000F9088 size:0xDC mapped:0x8073811C
void fn_3_F9088(Vec* pos, s32 i) {
    s16 x;
    s16 y;

    fn_800528C0(pos->x, pos->y, pos->z, &x, &y);
    lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_48 = x;
    lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_4C = y;
    lbl_80371C30[lbl_3_bss_B628->_14 + i]._00->_50 = 0.0f;
}

static inline BOOL isSpriteDone(StaC4Task* task, s32 i) {
    return lbl_80371C30[task->_14 + i]._00->_69 == 2 ? TRUE : FALSE;
}

// .text:0x000F8E20 size:0x268 mapped:0x80737EB4
void fn_3_F8E20(void) {
    StaC4Task* task = lbl_803CC1B8;
    s32 i;

    for (i = 0; i < 6; i++) {
        switch (lbl_3_bss_B620[i]) {
        case 1:
            fn_3_F9088(&lbl_3_bss_B5D8[i], i);
            lbl_80371C30[task->_14 + i]._00->_5C = 0;
            lbl_80371C30[task->_14 + i]._00->_54 |= 2;
            lbl_3_bss_B620[i] = 2;
            break;
        case 2:
            fn_3_F9088(&lbl_3_bss_B5D8[i], i);
            if (isSpriteDone(task, i)) {
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
