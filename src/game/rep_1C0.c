#include "game/rep_1C0.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/GX/GXFifo.h"
#include "Dolphin/os.h"
#include "C3/actor.h"
#include "C3/control.h"
#include "C3/geoPalette.h"
#include "game/rep_D0.h"

typedef struct {
    /* 0x00 */ DODisplayLayout base;
    /* 0x18 */ Mtx mtx;
    /* 0x48 */ u8 _48[0x54 - 0x48];
    /* 0x54 */ f32 _54;
    /* 0x58 */ f32 _58;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ f32 _64;
    /* 0x68 */ f32 _68;
} StadiumDisplayLayout;

typedef struct {
    /* 0x00 */ ActorLayout layout;
    /* 0x20 */ ActorBone bones[1];
} StadiumActorLayout;

typedef struct StadiumTex {
    /* 0x00 */ void* image;
    /* 0x04 */ u8 _04[0x8 - 0x4];
    /* 0x08 */ u16 height;
    /* 0x0A */ u16 width;
    /* 0x0C */ u8 _0C[0x20 - 0xC];
} StadiumTex; // size: 0x20

typedef struct StadiumFile {
    /* 0x00 */ u32 layout0;
    /* 0x04 */ u32 layout1;
    /* 0x08 */ u32 collision;
    /* 0x0C */ u32 geo0;
    /* 0x10 */ u32 geo1;
    /* 0x14 */ u32 tex;
    /* 0x18 */ u8 _18[0x28 - 0x18];
    /* 0x28 */ u32 _28;
    /* 0x2C */ u32 collision2;
    /* 0x30 */ u32 _30;
} StadiumFile;

typedef struct {
    /* 0x00 */ u32 _00[4];
} StadiumAramEntry; // size: 0x10

typedef struct {
    /* 0x00 */ u8 id;
    /* 0x01 */ u8 frame;
    /* 0x02 */ u8 timer;
} StadiumTileAnim; // size: 0x3

typedef struct {
    /* 0x00 */ void* src;
    /* 0x04 */ StadiumTex* dst;
    /* 0x08 */ u8* pos;
    /* 0x0C */ u8* frames;
    /* 0x10 */ StadiumTileAnim* entries;
    /* 0x14 */ u16 count;
    /* 0x16 */ u16 delay;
    /* 0x18 */ u16 numFrames;
} StadiumTiles;

typedef struct DrawTask1C0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ void (*draw)(struct DrawTask1C0* task);
} DrawTask1C0; // size: 0x8

typedef struct DrawTaskArg1C0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ void (*draw)(struct DrawTaskArg1C0* task);
    /* 0x08 */ s32 arg;
} DrawTaskArg1C0; // size: 0xC

typedef struct DrawTaskTiles1C0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ void (*draw)(struct DrawTaskTiles1C0* task);
    /* 0x08 */ StadiumTiles* tiles[2];
} DrawTaskTiles1C0; // size: 0x10

extern struct {
    /* 0x0000 */ u8 _0000[0x4];
    /* 0x0004 */ StadiumFile* _0004;
    /* 0x0008 */ u8 _0008[0x307E - 0x8];
    /* 0x307E */ u8 _307E;
} lbl_8036E548;

extern struct {
    /* 0x000 */ u8 _000[0x798];
    /* 0x798 */ u16** _798;
} lbl_80366B18;

extern struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
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

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
    /* 0x0C */ void* _0C;
} lbl_3_common_bss_350E4;

extern struct {
    /* 0x000 */ u8 _000[0x3B4];
    /* 0x3B4 */ void* _3B4;
    /* 0x3B8 */ u8 _3B8[0x3E0 - 0x3B8];
    /* 0x3E0 */ u8 _3E0;
} lbl_3_common_bss_35154;

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ u8 _50[0xAA - 0x50];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB[0xAD - 0xAB];
    /* 0xAD */ u8 _AD;
} g_Scores;

extern u8 lbl_803CBBC0;

extern u32 fn_80009028(void);
extern void fn_80023F0C(void* src, StadiumTex* dst, s32 srcX, s32 srcY, s32 w, s32 h, s32 dstX, s32 dstY);
extern void fn_80035CA4(s32 id);
extern void fn_8003A2C0(void);
extern void fn_8003AD84(void* tex);
extern void fn_8003AE5C(u8 arg);
extern void fn_80052694(s32 idx);
extern camera_803c639c_s* fn_80052734(s32 idx);
extern s32 fn_800527BC(void);
extern void* ARAMTransfer(StadiumAramEntry* entry, int arg1, int arg2, u32 aram);
extern void fn_800A7D4C(s32, void*);
extern void fn_800ACFB0(void* data);
extern void fn_800B2AC8(void* layout);
extern void fn_800B49E4(void* layout);
extern BOOL fn_800B7D3C(s32 arg, Vec* corners, Mtx mtx);
extern void SetFog(GXFogType type, f32 startZ, f32 endZ, f32 nearZ, f32 farZ, GXColor color);
extern void fn_800BCDBC(void* geo);
extern void fn_800BCE38(void* geo);
extern void fn_800BD190(void* geo, void* tex);
extern void fn_800BF038(void (*callback)(void));
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void convertTextureHeader(void* tex);
extern void fn_3_B8C08(Mtx view);
extern void fn_3_BCA20(void);
extern void fn_3_BD1D8(Mtx view);
extern void fn_3_BD434(u8 stadium, u8 mode);

StadiumEnv lbl_3_data_23C[15] = {
    { { { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f } },
      { { 40.0f, 1.0f, 1.0f, 0x00, 0x70, 0x010A }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x80 },
    { { { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f } },
      { { 42.0f, 1.5f, 1.5f, 0x0F, 0xA0, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0F, 0x80, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0F, 0x50, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x40 },
    { { { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f }, { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f }, { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f } },
      { { 42.0f, 1.5f, 1.5f, 0x0F, 0xA0, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0F, 0x80, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0F, 0x50, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x75 },
    { { { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f } },
      { { 40.0f, 1.0f, 1.0f, 0x0B, 0x70, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0B, 0x40, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0B, 0x40, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x60 },
    { { { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f }, { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f }, { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f } },
      { { 40.0f, 1.0f, 1.0f, 0x0B, 0x70, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0B, 0x40, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0B, 0x40, 0x01C0 } },
      0.0f, { 0x00, 0xFF, 0xFF, 0x00 }, 0x08, 0x60 },
    { { { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f }, { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f }, { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f } },
      { { 50.0f, 1.0f, 1.0f, 0x0B, 0x80, 0x01C0 }, { 50.0f, 1.0f, 1.0f, 0x00, 0x80, 0x01C0 }, { 50.0f, 1.0f, 1.0f, 0x0B, 0x80, 0x01C0 } },
      0.00016362462f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x48 },
    { { { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f } },
      { { 40.0f, 1.0f, 1.0f, 0x00, 0x70, 0x010A }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x80 },
    { { { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f } },
      { { 40.0f, 1.0f, 1.0f, 0x00, 0x70, 0x010A }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x80 },
    { { { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f } },
      { { 42.0f, 1.5f, 1.5f, 0x0F, 0xA0, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0F, 0x80, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0F, 0x50, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x40 },
    { { { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f }, { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f }, { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f } },
      { { 42.0f, 1.5f, 1.5f, 0x0F, 0xA0, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0F, 0x80, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0F, 0x50, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x75 },
    { { { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f } },
      { { 40.0f, 1.0f, 1.0f, 0x0B, 0x70, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0B, 0x40, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0B, 0x40, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x60 },
    { { { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f }, { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f }, { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f } },
      { { 40.0f, 1.0f, 1.0f, 0x0B, 0x70, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0B, 0x40, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x0B, 0x40, 0x01C0 } },
      0.0f, { 0x00, 0xFF, 0xFF, 0x00 }, 0x08, 0x60 },
    { { { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f }, { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f }, { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f } },
      { { 50.0f, 1.0f, 1.0f, 0x0B, 0x80, 0x01C0 }, { 50.0f, 1.0f, 1.0f, 0x00, 0x80, 0x01C0 }, { 50.0f, 1.0f, 1.0f, 0x0B, 0x80, 0x01C0 } },
      0.00016362462f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x48 },
    { { { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f } },
      { { 40.0f, 1.0f, 1.0f, 0x00, 0x70, 0x010A }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x80 },
    { { { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f }, { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f } },
      { { 40.0f, 1.0f, 1.0f, 0x00, 0x70, 0x010A }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 }, { 80.0f, 1.0f, 1.0f, 0x00, 0x40, 0x01C0 } },
      2.9088822e-05f, { 0x00, 0x00, 0x00, 0x00 }, 0x08, 0x80 },
};
static DrawTask1C0 lbl_3_data_7DC[2] = {
    { 2, fn_3_3818 },
    { 2, fn_3_3818 },
};
StadiumAramEntry lbl_3_data_7EC[21] = {
    { 0x0000040B, 0x40168A6C, 0x06CFD000, 0x000C69A8 },
    { 0x0000040B, 0x401331E0, 0x06DC4000, 0x000B67C4 },
    { 0x0000040B, 0x4011924C, 0x06E7A800, 0x000A5764 },
    { 0x0000040B, 0x400FBAE0, 0x06F20000, 0x000BE038 },
    { 0x0000040B, 0x400E5AC0, 0x06FDE800, 0x000B4FB8 },
    { 0x0000040B, 0x40131200, 0x07093800, 0x000A317C },
    { 0x0000040B, 0x4011B660, 0x07137000, 0x000D0294 },
    { 0x0000040B, 0x4011B660, 0x07137000, 0x000D0294 },
    { 0x0000040B, 0x4011B660, 0x07137000, 0x000D0294 },
    { 0x0000040B, 0x40141C60, 0x07207800, 0x000CE904 },
    { 0x0000040B, 0x4013CA40, 0x072D6800, 0x000CA560 },
    { 0x0000040B, 0x40141C60, 0x07207800, 0x000CE904 },
    { 0x0000040B, 0x4016C138, 0x073A1000, 0x000ED41C },
    { 0x0000040B, 0x401157B8, 0x0748E800, 0x000CA83C },
    { 0x0000040B, 0x4016C138, 0x073A1000, 0x000ED41C },
    { 0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510 },
    { 0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510 },
    { 0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510 },
    { 0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390 },
    { 0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390 },
    { 0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390 },
};
static DrawTaskTiles1C0 lbl_3_data_93C[2] = {
    { 2, fn_3_5C68 },
    { 2, fn_3_5C68 },
};
u32 lbl_3_data_95C = 0xFFFFFF0A;
static DrawTask1C0 lbl_3_data_960[5][2] = {
    { { 2, fn_3_5BF0 }, { 2, fn_3_5BF0 } },
    { { 2, fn_3_5BF0 }, { 2, fn_3_5BF0 } },
    { { 2, fn_3_5BF0 }, { 2, fn_3_5BF0 } },
    { { 2, fn_3_5BF0 }, { 2, fn_3_5BF0 } },
    { { 2, fn_3_5BF0 }, { 0, fn_3_5BF0 } },
};
static DrawTaskArg1C0 lbl_3_data_9B0[4][2] = {
    { { 2, fn_3_5BCC, 0 }, { 2, fn_3_5BCC, 0 } },
    { { 2, fn_3_5BCC, 1 }, { 2, fn_3_5BCC, 1 } },
    { { 2, fn_3_5BCC, 2 }, { 2, fn_3_5BCC, 2 } },
    { { 2, fn_3_5BCC, 3 }, { 2, fn_3_5BCC, 3 } },
};
void (*lbl_3_data_A10[2])(MtxPtr view, s32, s32) = { 0 };

static void (*lbl_3_bss_18)(void);

// .text:0x000064DC size:0x54 mapped:0x80645570
void fn_3_64DC(void) {
    ARAMTransfer(&lbl_3_data_7EC[g_d_GameSettings.StadiumID * 3 + g_d_GameSettings.miniGameStadiumIndicator], 0, 0, 0);
}

// .text:0x00006424 size:0xB8 mapped:0x806454B8
s16 fn_3_6424(u8* data, CollisionBox** out) {
    s16 count;
    u32* p;
    s32 i;

    count = *(u16*)data;
    *out = (CollisionBox*)(data + 4);
    p = (u32*)(data + 4);
    for (i = count; i >= 0; i--) {
        *p++ += (u32)data;
    }
    return count;
}

// .text:0x00005EC0 size:0x564 mapped:0x80644F54
void fn_3_5EC0(StadiumFile* file) {
    u8* layout;
    u8* geo;
    u8* tex;
    u8* data;
    s32 i;

    layout = (u8*)file + file->layout0;
    geo = (u8*)file + file->geo0;
    tex = (u8*)file + file->tex;
    g_UNK_StadiumDetails.numCollisionBoxes =
        fn_3_6424((u8*)file + file->collision, &g_UNK_StadiumDetails.pCollisionBoxes);
    fn_800B49E4(layout);
    fn_800BCE38(geo);
    convertTextureHeader(tex);
    fn_800BD190(geo, tex);
    haveActLayoutPointToGeoHeader(layout, geo);
    fn_800B2AC8(layout);
    g_UNK_StadiumDetails._04 = tex;
    PSMTXIdentity(g_UNK_StadiumDetails.tasks[1][0]._08);
    g_UNK_StadiumDetails.tasks[1][0].type = 2;
    g_UNK_StadiumDetails.tasks[1][0].draw = fn_3_3638;
    g_UNK_StadiumDetails.tasks[1][0].layout = layout;
    g_UNK_StadiumDetails.tasks[1][1] = g_UNK_StadiumDetails.tasks[1][0];
    g_UNK_StadiumDetails.tasks[3][0] = g_UNK_StadiumDetails.tasks[1][0];
    g_UNK_StadiumDetails.tasks[3][1] = g_UNK_StadiumDetails.tasks[1][0];
    for (i = 0; i < 0; i++) {
        g_UNK_StadiumDetails.tasks[i + 6][0] = g_UNK_StadiumDetails.tasks[1][0];
        g_UNK_StadiumDetails.tasks[i + 6][1] = g_UNK_StadiumDetails.tasks[1][0];
    }

    layout = (u8*)file + file->layout1;
    geo = (u8*)file + file->geo1;
    fn_800B49E4(layout);
    fn_800BCE38(geo);
    fn_800BD190(geo, tex);
    haveActLayoutPointToGeoHeader(layout, geo);
    g_UNK_StadiumDetails.tasks[0][0].type = 2;
    g_UNK_StadiumDetails.tasks[0][0].draw = fn_3_3638;
    g_UNK_StadiumDetails.tasks[0][0].layout = layout;
    g_UNK_StadiumDetails.tasks[0][1] = g_UNK_StadiumDetails.tasks[0][0];
    g_UNK_StadiumDetails.tasks[2][0] = g_UNK_StadiumDetails.tasks[0][0];
    g_UNK_StadiumDetails.tasks[2][1] = g_UNK_StadiumDetails.tasks[0][0];
    for (i = 0; i < 0; i++) {
        g_UNK_StadiumDetails.tasks[i + 4][0] = g_UNK_StadiumDetails.tasks[0][0];
        g_UNK_StadiumDetails.tasks[i + 4][1] = g_UNK_StadiumDetails.tasks[0][0];
    }

    g_UNK_StadiumDetails.env =
        lbl_3_data_23C[g_d_GameSettings.StadiumID + g_d_GameSettings.miniGameStadiumIndicator * 7];
    g_UNK_StadiumDetails._00 = tex + 4;
    g_UNK_StadiumDetails._774 = 0;
    fn_8003AE5C(g_UNK_StadiumDetails.env._5D);

    data = (u8*)file + file->_28;
    convertTextureHeader(data);
    lbl_3_common_bss_35154._3B4 = data + 4;
    fn_3_BD434(g_d_GameSettings.StadiumID, g_d_GameSettings.miniGameStadiumIndicator);

    if (file->collision2 != 0) {
        g_UNK_StadiumDetails._77C = fn_3_6424((u8*)file + file->collision2, &g_UNK_StadiumDetails._778);
    } else {
        g_UNK_StadiumDetails._77C = 0;
    }

    if (file->_30 != 0) {
        data = (u8*)file + file->_30;
        convertTextureHeader(data);
        fn_8003AD84(data);
    }
    fn_800BF038(fn_3_35F0);
}

// .text:0x00005E60 size:0x60 mapped:0x80644EF4
void fn_3_5E60(void) {
    StadiumFile* file = lbl_8036E548._0004;

    fn_80035CA4(5);
    fn_800BCDBC((u8*)file + file->geo1);
    fn_800BCDBC((u8*)file + file->geo0);
    fn_800ACFB0(lbl_8036E548._0004);
}

// .text:0x00005C68 size:0x1F8 mapped:0x80644CFC
void fn_3_5C68(DrawTaskTiles1C0* task) {
    static const GXColor black = { 0, 0, 0, 0 };
    StadiumTiles* tiles;
    s32 j;
    s32 i;
    s32 changed;
    s32 frame;
    s32 dstX;
    s32 dstY;
    s32 srcX;
    s32 srcY;

    GXSetCullMode(GX_CULL_BACK);
    SetFog(GX_FOG_NONE, 0.0f, 0.0f, 0.0f, 0.0f, black);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    i = 2;
    while (i--) {
        tiles = task->tiles[i];
        if (tiles == NULL) {
            continue;
        }
        changed = 0;
        for (j = 0; j < tiles->count; j++) {
            if (tiles->entries[j].timer-- == 0) {
                tiles->entries[j].frame = (tiles->entries[j].frame + 1) % tiles->numFrames;
                dstY = (j / 8) * 64;
                dstX = (j % 8) * 32;
                frame = tiles->frames[tiles->entries[j].frame];
                if (i != 0) {
                    srcX = ((u8(*)[2][2])tiles->pos)[tiles->entries[j].id][frame][0] * 32;
                    srcY = ((u8(*)[2][2])tiles->pos)[tiles->entries[j].id][frame][1] * 64;
                } else {
                    srcX = ((u8(*)[4][2])tiles->pos)[tiles->entries[j].id][frame][0] * 32;
                    srcY = ((u8(*)[4][2])tiles->pos)[tiles->entries[j].id][frame][1] * 64;
                }
                fn_80023F0C(tiles->src, tiles->dst, srcX, srcY, 32, 64, dstX, dstY);
                tiles->entries[j].timer = tiles->delay;
                changed++;
            }
        }
        if (changed) {
            DCStoreRange(tiles->dst->image, tiles->dst->width * tiles->dst->height);
        }
    }
    if (lbl_3_bss_18 != NULL) {
        lbl_3_bss_18();
    }
    GXSetZCompLoc(GX_FALSE);
}

// .text:0x00005BF0 size:0x78 mapped:0x80644C84
void fn_3_5BF0(DrawTask1C0* task) {
    StadiumFog* fog = &g_UNK_StadiumDetails.env.fog[0];

    if (lbl_3_bss_18 != NULL) {
        lbl_3_bss_18();
    }
    SetFog(fog->color.a, fog->start, fog->end, 1.0f, 512.0f, fog->color);
}

// .text:0x00005BCC size:0x24 mapped:0x80644C60
void fn_3_5BCC(DrawTaskArg1C0* task) {
    fn_80052694(task->arg);
}

// .text:0x00005BAC size:0x20 mapped:0x80644C40
void fn_3_5BAC(void) {
    fn_3_567C();
}

// .text:0x0000567C size:0x530 mapped:0x80644710
void fn_3_567C(void) {
}

// .text:0x00005518 size:0x164 mapped:0x806445AC
void fn_3_5518(void) {
    Mtx44 proj;
    Mtx mtx;
    s16 texIds[7] = { 0x49, 0x95, 0x1DB, 0x121, 0x1B2, 0xFB, 0 };
    StadiumTex* textures = g_UNK_StadiumDetails._00;
    StadiumTex* tex = &textures[texIds[g_d_GameSettings.StadiumID]];
    void* image;

    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    GXSetScissor(0, 0, 640, 448);
    C_MTXOrtho(proj, 0.0f, 480.0f, 0.0f, 640.0f, 0.5f, 1.5f);
    GXSetProjection(proj, GX_ORTHOGRAPHIC);
    GXSetCullMode(GX_CULL_NONE);
    PSMTXIdentity(mtx);
    GXLoadPosMtxImm(mtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetTexCopySrc(0, 0, 512, 480);
    GXSetTexCopyDst(512, 480, GX_CTF_R4, GX_FALSE);
    fn_3_4A38(g_d_GameSettings.StadiumID);
    image = tex->image;
    GXDrawDone();
    GXCopyTex(image, GX_TRUE);
    GXPixModeSync();
}

// .text:0x000053E0 size:0x138 mapped:0x80644474
void fn_3_53E0(u16* text, s16* u, s16* v, s16* w, s16* h, s16* page) {
    s32 code = *text;
    u16 idx;

    if (code & 0x4000) {
        return;
    }
    if (code & 0x8000) {
        code &= 0x7FFF;
        *page = code / 2116;
        idx = code % 2116;
        *u = idx % 46;
        *v = (idx / 46) * 22;
        *u *= 22;
        *w = 22;
        *h = 22;
    } else {
        *u = code % 92;
        *v = (code / 92) * 22;
        *u = (*u % 2 + *u / 2 * 2) * 11;
        *w = 11;
        *h = 22;
        *page = 0;
    }
}

// .text:0x00004F90 size:0x450 mapped:0x80644024
void fn_3_4F90(GXTexObj* obj, s16 x, s16 y, s16 value, u8 digits, GXColor c1, GXColor c2, u8 flag) {
    u16** glyphs = lbl_80366B18._798 + 1;
    s16 count;
    s16 digit;
    s16 num;
    s16 width;
    s16 u;
    s16 v;
    s16 w;
    s16 h;
    s16 page;
    s32 i;

    if (value > 99) {
        value = 99;
    }
    count = (value >= 10) + 1;
    if (flag) {
        if (value != 0) {
            count++;
        } else {
            count = 1;
        }
    }
    if (count > digits) {
        width = digits * 16 / count;
    } else {
        width = 16;
    }
    x = x + digits * 16 - width;
    num = value;
    if (flag) {
        GXClearVtxDesc();
        GXSetTevColor(GX_TEVREG0, c1);
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_C0, GX_CC_C0);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
        GXSetNumTexGens(0);
        GXSetNumChans(1);
        GXSetNumTevStages(1);
        GXSetLineWidth(18, GX_TO_ZERO);
        GXBegin(GX_LINES, GX_VTXFMT0, 4);
        GXPosition3f32(x, y, -0.5f);
        GXPosition3f32(x + width, y + 18, -0.5f);
        GXPosition3f32(x + width, y, -0.5f);
        GXPosition3f32(x, y + 18, -0.5f);
        GXEnd();
        GXSetLineWidth(6, GX_TO_ZERO);
        x -= width;
        count--;
    }
    for (i = 0; i < count; i++) {
        digit = num % 10;
        fn_3_53E0(glyphs[digit], &u, &v, &w, &h, &page);
        fn_3_42CC(obj, x, y, x + width, y + 18, u, v, w, h, c1, c2, 0);
        x -= width;
        num /= 10;
    }
}

// .text:0x00004A38 size:0x558 mapped:0x80643ACC
void fn_3_4A38(u8 stadium) {
    GXColor colors[7][2] = {
        { { 0x66, 0x66, 0x66, 0xFF }, { 0x00, 0x00, 0x00, 0xFF } },
        { { 0x66, 0x66, 0x66, 0xFF }, { 0x00, 0x00, 0x00, 0xFF } },
        { { 0x66, 0x66, 0x66, 0xFF }, { 0x00, 0x00, 0x00, 0xFF } },
        { { 0x66, 0x66, 0x66, 0xFF }, { 0x00, 0x00, 0x00, 0xFF } },
        { { 0x66, 0x66, 0x66, 0xFF }, { 0x00, 0x00, 0x00, 0xFF } },
        { { 0x66, 0x66, 0x66, 0xFF }, { 0x00, 0x00, 0x00, 0xFF } },
        { { 0x66, 0x66, 0x66, 0xFF }, { 0x00, 0x00, 0x00, 0xFF } },
    };
    s16 texIds[7] = { 0x48, 0x94, 0x1FA, 0x120, 0x1B1, 0xFC, 0x48 };
    s16 unk26C[7] = { 0 };
    s16 unk27C[7][2] = { { 0x10, 0x12 }, { 0x10, 0x12 }, { 0x10, 0x12 }, { 0x10, 0x12 },
                         { 0x10, 0x12 }, { 0x10, 0x12 }, { 0x10, 0x12 } };
    s16 unk298[2][2] = { { 0x20, 0x10 } };
    s16 unk2A0[7][2] = { { 0x6, 0xC0 }, { 0x0, 0x8A } };
    s16 unk2BC[7][2] = { { 0x6, 0xD6 }, { 0x0, 0x9F } };
    s16 unk2D8[7][2] = { 0 };
    s16 innings[7] = { 10, 9 };
    s16 awayPos[7][2] = { { 0x1C, 0xC0 }, { 0x12, 0x8A } };
    s16 homePos[7][2] = { { 0x1C, 0xD6 }, { 0x12, 0x9F } };
    s16 awayTotalPos[7][2] = { { 0xFA, 0xC0 }, { 0xB4, 0x8A } };
    s16 homeTotalPos[7][2] = { { 0xFA, 0xD6 }, { 0xB4, 0x9F } };
    u8 totalDigits[7] = { 1, 1 };
    s16 spacing[7][2] = { { 0x16, 0x12 }, { 0x12, 0x12 } };
    s16 unk398[7][2] = { 0 };
    s16 unk3B4[7][2] = { 0 };
    s16 unk3D0[7][2] = { { 0x16, 0x12 }, { 0x12, 0x12 } };
    s16 unk3EC[7][2] = { { 0x0, 0x110 }, { 0xC6, 0x8A } };
    s16 unk408[7][2] = { { 0x0, 0x12A }, { 0xC6, 0x9F } };
    u8 unk424[7] = { 1, 1 };
    s16 unk42C[7][2] = { { 0x18, 0x110 }, { 0xD8, 0x8A } };
    s16 unk448[7][2] = { { 0x18, 0x12A }, { 0xD8, 0x9F } };
    s16 unk464[7][2] = { { 0x0, 0x150 }, { 0x0, 0x16A }, { 0x0, 0x184 }, { 0x105, 0x75 }, { 0x105, 0x8B }, { 0x105, 0xA1 } };
    s16 unk480[7][2] = { 0 };
    s16 unk49C[7][2] = { 0 };
    s16 unk4B8[7][2] = { { 0x10, 0x12 }, { 0x10, 0x10 } };
    s16 unk4D4[7][2] = { { 0x1A, 0x12 }, { 0x15, 0x12 } };
    GXTexObj obj;
    s32 start;
    s32 i;
    s32 last;
    s32 offset;
    u8 skip;

    GXInitTexObjLOD(&obj, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    start = 1;
    if (g_Scores._00 >= innings[stadium] + 1) {
        start = innings[stadium] + 1;
    }

    last = g_Scores._00;
    offset = 0;
    for (i = start; i <= last; i++) {
        if (i == g_Scores._00 && g_Scores._04[0][i] == 0 && g_Scores._AD == 0 &&
            g_GameLogic.EventTriggers_EndOfGame == 0) {
            break;
        }
        fn_3_4F90(&obj, awayPos[stadium][0] + offset, awayPos[stadium][1], g_Scores._04[0][i], 1,
                  colors[stadium][0], colors[stadium][1], 0);
        offset += spacing[stadium][0];
    }
    fn_3_4F90(&obj, awayTotalPos[stadium][0], awayTotalPos[stadium][1], g_Scores._04[0][0], totalDigits[stadium],
              colors[stadium][0], colors[stadium][1], 0);

    if (g_GameLogic.EventTriggers_EndOfGame == 0) {
        last = g_Scores._00 + g_Scores._AD;
    } else {
        last = g_Scores._AA + 1;
    }
    offset = 0;
    for (; start < last; start++) {
        if (start >= g_Scores._AA && g_Scores._04[1][0] > g_Scores._04[0][0]) {
            skip = TRUE;
        } else {
            skip = FALSE;
        }
        if (start == g_Scores._00 && g_Scores._04[1][start] == 0 && !skip &&
            g_GameLogic.EventTriggers_EndOfGame == 0) {
            break;
        }
        fn_3_4F90(&obj, homePos[stadium][0] + offset, homePos[stadium][1], g_Scores._04[1][start], 1,
                  colors[stadium][0], colors[stadium][1], skip);
        offset += spacing[stadium][0];
    }
    fn_3_4F90(&obj, homeTotalPos[stadium][0], homeTotalPos[stadium][1], g_Scores._04[1][0], totalDigits[stadium],
              colors[stadium][0], colors[stadium][1], 0);
}

// .text:0x00004A38 size:0x558 mapped:0x80643ACC

// .text:0x00004984 size:0xB4 mapped:0x80643A18
void fn_3_4984(void) {
    Mtx mtx;
    Mtx44 proj;

    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    GXSetScissor(0, 0, 640, 448);
    C_MTXOrtho(proj, 0.0f, 480.0f, 0.0f, 640.0f, 0.5f, 1.5f);
    GXSetProjection(proj, GX_ORTHOGRAPHIC);
    GXSetCullMode(GX_CULL_NONE);
    PSMTXIdentity(mtx);
    GXLoadPosMtxImm(mtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
}

// .text:0x000042CC size:0x6B8 mapped:0x80643360
void fn_3_42CC(GXTexObj* obj, s16 x0, s16 y0, s16 x1, s16 y1, s16 u, s16 v, s16 w, s16 h, GXColor c1,
               GXColor c2, u8 flag) {
    f32 left = x0;
    f32 top = y0;
    f32 right = x1;
    f32 bottom = y1;
    // GXTexture.h declares these u32; the SDK returns u16, which the casts restore
    u32 width = GXGetTexObjWidth(obj);
    u32 height = GXGetTexObjHeight(obj);
    f32 s0 = (f32)u / (u16)width;
    f32 t0 = (f32)v / (u16)height;
    f32 s1 = (f32)(u + w) / (u16)width;
    f32 t1 = (f32)(v + h) / (u16)height;

    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetTevColor(GX_TEVREG0, c1);
    GXSetTevColor(GX_TEVREG1, c2);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    if (!(flag & 1)) {
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_C0, GX_CC_C1);
    } else {
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ONE, GX_CC_C0, GX_CC_C1);
    }
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_OR);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(left - 1.0f, top - 1.0f, -0.5f);
    GXPosition3f32(right + 1.0f, top - 1.0f, -0.5f);
    GXPosition3f32(right + 1.0f, bottom + 1.0f, -0.5f);
    GXPosition3f32(left - 1.0f, bottom + 1.0f, -0.5f);
    GXEnd();

    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetNumChans(0);
    GXSetNumTexGens(1);
    GXSetNumTevStages(2);
    if (!(flag & 1)) {
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_TEXA, GX_CC_ZERO);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
        GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_C0, GX_CC_C1);
        GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
        GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
        GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    } else {
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_TEXA, GX_CC_ONE);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
        GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_C0, GX_CC_C1);
        GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
        GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
        GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    }
    GXLoadTexObj(obj, GX_TEXMAP0);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_OR);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(left, top, -0.5f);
    GXTexCoord2f32(s0, t0);
    GXPosition3f32(right, top, -0.5f);
    GXTexCoord2f32(s1, t0);
    GXPosition3f32(right, bottom, -0.5f);
    GXTexCoord2f32(s1, t1);
    GXPosition3f32(left, bottom, -0.5f);
    GXTexCoord2f32(s0, t1);
    GXEnd();
}

// .text:0x00003EE8 size:0x3E4 mapped:0x80642F7C
void fn_3_3EE8(StadiumTex* tex, s16 x0, s16 y0, s16 x1, s16 y1, s16 u, s16 v, s16 w, s16 h) {
    GXTexObj obj;
    u16 height = tex->height;
    u16 width = tex->width;
    f32 left = x0;
    f32 top = y0;
    f32 right = x1;
    f32 bottom = y1;
    f32 s0 = (f32)u / width;
    f32 t0 = (f32)v / height;
    f32 s1 = (f32)(u + w) / width;
    f32 t1 = (f32)(v + h) / height;
    GXColor color = { 0xFF, 0xFF, 0xFF, 0xFF };

    GXInitTexObj(&obj, tex->image, width, height, GX_TF_I4, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&obj, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(0);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTevColor(GX_TEVREG0, color);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_OR);
    GXLoadTexObj(&obj, GX_TEXMAP0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(left, top, -0.5f);
    GXTexCoord2f32(s0, t0);
    GXPosition3f32(right, top, -0.5f);
    GXTexCoord2f32(s1, t0);
    GXPosition3f32(right, bottom, -0.5f);
    GXTexCoord2f32(s1, t1);
    GXPosition3f32(left, bottom, -0.5f);
    GXTexCoord2f32(s0, t1);
    GXEnd();
}

// .text:0x00003BE8 size:0x300 mapped:0x80642C7C
void fn_3_3BE8(StadiumTex* tex, s16 x0, s16 y0, s16 x1, s16 y1, s16 u, s16 v, s16 w, s16 h) {
    GXTexObj obj;
    f32 left = x0;
    f32 top = y0;
    f32 right = x1;
    f32 bottom = y1;
    GXColor color = { 0xFF, 0xFF, 0xFF, 0xFF };

    GXInitTexObj(&obj, tex->image, tex->width, tex->height, GX_TF_I4, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&obj, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, 9);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(0);
    GXSetNumTexGens(1);
    GXSetTevColor(GX_TEVREG0, color);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_OR);
    GXLoadTexObj(&obj, GX_TEXMAP0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(left, top, -0.5f);
    GXTexCoord2s16(u, v);
    GXPosition3f32(right, top, -0.5f);
    GXTexCoord2s16(u + w, v);
    GXPosition3f32(right, bottom, -0.5f);
    GXTexCoord2s16(u + w, v + h);
    GXPosition3f32(left, bottom, -0.5f);
    GXTexCoord2s16(u, v + h);
    GXEnd();
}

// .text:0x00003904 size:0x2E4 mapped:0x80642998
void fn_3_3904(void) {
}

// .text:0x000038E8 size:0x1C mapped:0x8064297C
void fn_3_38E8(void (*draw)(MtxPtr view, s32, s32)) {
    lbl_3_data_A10[lbl_803CBBC0] = draw;
}

// .text:0x00003818 size:0xD0 mapped:0x806428AC
void fn_3_3818(DrawTask1C0* task) {
    s32 i;

    if (lbl_3_data_A10[!lbl_803CBBC0] != NULL) {
        i = fn_800527BC() - 1;
        do {
            fn_80052694(i);
            lbl_3_data_A10[!lbl_803CBBC0](fn_80052734(i)->view, 0, 0);
        } while (i--);
        lbl_3_data_A10[!lbl_803CBBC0] = NULL;
    }
}

// .text:0x00003638 size:0x1E0 mapped:0x806426CC
void fn_3_3638(StadiumDrawTask* task) {
    Vec corners[8];
    Mtx mtx;
    MtxPtr world;
    MtxPtr camera;
    s32 i;
    StadiumActorLayout* layout;
    StadiumDisplayLayout* disp;
    DODisplayDataPtr pal;

    world = task->_08;
    camera = task->_38;
    layout = task->layout;
    pal = (DODisplayDataPtr)layout->layout.geoPaletteName;
    for (i = 0; i < layout->layout.totalBones; i++) {
        if (layout->bones[i].geoFileID == 0xFFFF) {
            continue;
        }
        disp = (StadiumDisplayLayout*)pal->descriptorArray[layout->bones[i].geoFileID].layout;
        CTRLBuildMatrix(layout->bones[i].orientationCtrl, disp->mtx);
        PSMTXConcat(world, disp->mtx, disp->mtx);
        PSMTXConcat(camera, disp->mtx, mtx);
        corners[0].x = disp->_58;
        corners[0].y = disp->_60;
        corners[0].z = disp->_64;
        corners[1].x = disp->_54;
        corners[1].y = disp->_60;
        corners[1].z = disp->_64;
        corners[2].x = disp->_54;
        corners[2].y = disp->_60;
        corners[2].z = disp->_68;
        corners[3].x = disp->_58;
        corners[3].y = disp->_60;
        corners[3].z = disp->_68;
        corners[4].x = disp->_58;
        corners[4].y = disp->_5C;
        corners[4].z = disp->_64;
        corners[5].x = disp->_54;
        corners[5].y = disp->_5C;
        corners[5].z = disp->_64;
        corners[6].x = disp->_54;
        corners[6].y = disp->_5C;
        corners[6].z = disp->_68;
        corners[7].x = disp->_58;
        corners[7].y = disp->_5C;
        corners[7].z = disp->_68;
        if (fn_800B7D3C(task->_6C, corners, mtx)) {
            if (layout->bones[i].pad16 & 1) {
                GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
            } else {
                GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
            }
            switch (layout->bones[i].pad16 & 6) {
            case 2:
                GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_CLEAR);
                break;
            case 4:
                GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTCOL, GX_BL_ZERO, GX_LO_CLEAR);
                break;
            case 3:
            default:
                GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
                break;
            }
            DOVARender((struct DODisplayObj*)disp, camera, 0, NULL);
        }
    }
}

// .text:0x000035F0 size:0x48 mapped:0x80642684
void fn_3_35F0(void) {
    if (fn_80009028() == 0) {
        GXSetCopyClear(g_UNK_StadiumDetails.env.clearColor, 0xFFFFFF);
    }
}

// .text:0x000035E4 size:0xC mapped:0x80642678
void fn_3_35E4(void (*callback)(void)) {
    lbl_3_bss_18 = callback;
}

// .text:0x000035D4 size:0x10 mapped:0x80642668
void (*setFanObjPtr(void))(void) {
    return lbl_3_bss_18;
}
