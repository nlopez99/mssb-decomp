#include "challenge/rep_7730.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/mtxext.h"
#include "Dolphin/PPCArch.h"
#include "Dolphin/OS/OSCache.h"
#include "string.h"
#include "Dolphin/rand.h"
#include "challenge/rep_0010.h"
#include "challenge/rep_7978.h"

extern void* lbl_803CC1B8;

extern void convertTextureHeader(void* tex);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern s32 fn_80035838(void* entry, s32 arg1);
extern s32 fn_80035DD4(s32 arg0);
extern void fn_80034E20(struct SpriteTask7730* task, struct SpriteDesc7730* desc);

typedef struct AnimFrame7730 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct {
        /* 0x00 */ u8 _00[0xA];
        /* 0x0A */ u16 _0A;
    }* _0C;
} AnimFrame7730;

typedef struct AnimSet7730 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
    /* 0x08 */ AnimFrame7730* _08[1];
} AnimSet7730;

extern struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ u8* _34;
    /* 0x38 */ struct {
        /* 0x00 */ u8 _00[0x8];
        /* 0x08 */ AnimSet7730* _08;
    }* _38;
} lbl_803C4BE0[20];

typedef struct Sprite7730 {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ f32 _48;
    /* 0x4C */ f32 _4C;
    /* 0x50 */ u8 _50[0x5C - 0x50];
    /* 0x5C */ s32 _5C;
    /* 0x60 */ u8 _60[0x66 - 0x60];
    /* 0x66 */ u8 _66;
    /* 0x67 */ u8 _67;
    /* 0x68 */ u8 _68;
} Sprite7730;

extern struct {
    /* 0x00 */ Sprite7730* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} lbl_80371C30[];

typedef struct SpriteTask7730 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ u16 _14;
} SpriteTask7730;

typedef struct AnimKey7730 {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x50 - 0x8];
} AnimKey7730;

extern void fn_80034CEC(SpriteTask7730* task);
extern void fn_8000CEF0(void* anim, u8 frame, s32 arg2, u8 arg3, AnimKey7730* key);

extern void* ARAMTransfer(void* entry, int arg1, int arg2, u32 aram);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80037B18(void* arg0, Vec* arg1, f32 arg2);
extern void fn_800385F0(void* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern void fn_80035A00(void);
extern void fn_80048C14(s32 arg0);
extern void fn_80048E00(s32 arg0, s32 arg1);
extern s32 fn_80048EA8(s32 arg0);
extern void fn_80048C1C(void);
extern void fn_80048C28(void);
extern void fn_80048D4C(void);

extern void fn_800AD038(void* arg0);
extern void fn_800B1188(void);
extern void fn_800B24D4(s32 id);
extern void fn_800A7D4C(s32, void*);
extern void fn_80038CD0(u8 count, void* arg1, struct RopeNode7730* nodes, f32 arg3, f32 arg4);
extern void fn_80038B48(void* arg0, struct RopeNode7730* nodes, u8 count, Vec* force);
extern void fn_80038E2C(void* arg0);
extern void fn_1_121D4(void* arg0);
extern void fn_80037BAC(void* arg0);
extern void LITAlloc(void** light);
extern void LITInitAttn(void* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern void LITInitPos(void* light, f32 x, f32 y, f32 z);
extern void LITInitDir(void* light, f32 nx, f32 ny, f32 nz);
extern void LITInitColor(void* light, GXColor color);
extern struct ModelTable7730* ActorObjectInitTable(u16 count);
extern void fn_800BDC88(struct ModelTable7730* table, u16 first, u16 last, void* model, void* anim, void* arg5);
extern void LoadActorLayout(void* layout);
extern void convertGeometryAndSknHeader(void* geo, void* skn);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void fn_800B2C08(void* actor, s32 arg1);
extern void fn_800BD548(void* model, s32 count, ...);
extern void fn_800BDA24(struct Model7730* model);
extern void fn_80023F0C(void* src, struct Tex7730* dst, s32 srcX, s32 srcY, s32 w, s32 h, s32 dstX, s32 dstY);
extern void gOz_GXSetTexture(s32, s32, s32);
extern void SetDisplayStateTexture(void* tex, s32, s32);
extern void fn_800BD670(struct ModelTable7730* table, MtxPtr mtx);

extern u8 lbl_803CBBC0;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

typedef struct SprTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct SprTask7730* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ void* _14;
    /* 0x18 */ u8 _18[0x25 - 0x18];
    /* 0x25 */ u8 _25;
    /* 0x26 */ u8 _26[0x28 - 0x26];
    /* 0x28 */ s32 _28;
} SprTask7730;

typedef struct MenuTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ SprTask7730* _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ u8 _14;
} MenuTask7730;

typedef struct LoadTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ SprTask7730* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ struct SpriteTask7730* _14;
    /* 0x18 */ u16 _18;
    /* 0x1A */ s16 _1A;
    /* 0x1C */ s16 _1C;
    /* 0x1E */ u8 _1E;
    /* 0x1F */ u8 _1F;
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
    /* 0x24 */ u8 _24;
} LoadTask7730;

typedef struct AnimTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ SprTask7730* _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ u8* _14;
    /* 0x18 */ u8* _18;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
    /* 0x22 */ u16 _22;
    /* 0x24 */ u16 _24;
    /* 0x26 */ u16 _26;
    /* 0x28 */ u16 _28;
    /* 0x2A */ u8 _2A[0x2C - 0x2A];
    /* 0x2C */ struct Tex7730* _2C;
} AnimTask7730;

typedef struct GameTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ SprTask7730* _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ u8* _14;
    /* 0x18 */ u8* _18;
    /* 0x1C */ u32 _1C;
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
    /* 0x24 */ u8 _24;
} GameTask7730;

typedef struct ChainTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ f32 _14;
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
    /* 0x22 */ u16 _22;
    /* 0x24 */ u16 _24;
    /* 0x26 */ u16 _26;
    /* 0x28 */ u16 _28;
    /* 0x2A */ u8 _2A;
    /* 0x2B */ u8 _2B;
    /* 0x2C */ u8 _2C;
} ChainTask7730;

typedef struct WaveTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ u16 _24;
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
    /* 0x2A */ u8 _2A;
    /* 0x2B */ u8 _2B;
    /* 0x2C */ u8 _2C;
} WaveTask7730;

typedef struct CameraTask7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ u32 _2C;
} CameraTask7730;

typedef struct Actor7730 {
    /* 0x000 */ Vec _000;
    /* 0x00C */ Vec _00C;
    /* 0x018 */ u8 _018[0x50 - 0x18];
    /* 0x050 */ f32 _050;
    /* 0x054 */ u8 _054[0x58 - 0x54];
    /* 0x058 */ Mtx _058;
    /* 0x088 */ u8 _088[0xE8 - 0x88];
    /* 0x0E8 */ Vec _0E8;
    /* 0x0F4 */ Vec _0F4;
    /* 0x100 */ u8 _100[0x140 - 0x100];
    /* 0x140 */ Vec _140;
    /* 0x14C */ u8 _14C[0x154 - 0x14C];
} Actor7730; // size: 0x154

typedef struct Tex7730 {
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
} Tex7730;

typedef struct RopeNode7730 {
    /* 0x00 */ f32 _00;
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ Vec _0C;
    /* 0x18 */ Vec _18;
    /* 0x24 */ Vec _24;
    /* 0x30 */ Vec _30;
    /* 0x3C */ s32 _3C;
} RopeNode7730; // size: 0x40

typedef struct PhysNode7730 {
    /* 0x00 */ f32 _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
    /* 0x08 */ Vec _08;
    /* 0x14 */ u8 _14[0x20 - 0x14];
    /* 0x20 */ Vec _20;
    /* 0x2C */ Vec _2C;
    /* 0x38 */ u32 _38;
} PhysNode7730; // size: 0x3C

typedef struct SimParams7730 {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ f32 _24;
} SimParams7730; // size: 0x28

typedef struct RopeParams7730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x18 - 0x4];
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
    /* 0x24 */ u8 _24;
    /* 0x25 */ u8 _25;
} RopeParams7730;

typedef struct SpriteDesc7730 {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} SpriteDesc7730; // size: 0x20

typedef struct ModelActor7730 {
    /* 0x00 */ u8 _00[0x98];
    /* 0x98 */ u8 _98;
} ModelActor7730;

typedef struct Model7730 {
    /* 0x00 */ ModelActor7730* _00;
    /* 0x04 */ u8 _04[0x10 - 0x04];
    /* 0x10 */ Control _10;
    /* 0x54 */ u8 _54[0x6C - 0x54];
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D[0x90 - 0x6D];
} Model7730; // size: 0x90

typedef struct ModelTable7730 {
    /* 0x00 */ u16 count;
    /* 0x04 */ Mtx _04;
    /* 0x34 */ Model7730 models[1];
} ModelTable7730;

typedef struct DrawEntry7730 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*_04)(struct DrawEntry7730*);
    /* 0x08 */ struct Tex7730* _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ u8* _10;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
    /* 0x18 */ u8 _18;
} DrawEntry7730;

typedef struct AramEntry7730 {
    /* 0x0 */ u32 _0[4];
} AramEntry7730; // size: 0x10

static AramEntry7730 lbl_1_data_FB98[64] = {
    { 0x0000040B, 0x4023491C, 0x19135800, 0x00082928 },
    { 0x0000040B, 0x4013764C, 0x1A635000, 0x0007DB48 },
    { 0x0000040B, 0x4003E3DC, 0x1A6B3000, 0x00021420 },
    { 0x0000040B, 0x4002EC10, 0x1A6D4800, 0x00013108 },
    { 0x0000040B, 0x400E72C0, 0x1A6E8000, 0x00060768 },
    { 0x0000040B, 0x40049404, 0x1A748800, 0x00020E34 },
    { 0x0000040B, 0x40076AE0, 0x18ED7000, 0x00036BC8 },
    { 0x0000040B, 0x4010FD70, 0x1A769800, 0x0005E284 },
    { 0x0000040B, 0x400DB738, 0x1A7C8000, 0x00049AB4 },
    { 0x0000040B, 0x400E9864, 0x1A812000, 0x00059DC0 },
    { 0x0000040B, 0x400B7718, 0x1A86C000, 0x00050288 },
    { 0x0000040B, 0x400D87FC, 0x1A8BC800, 0x00047BC4 },
    { 0x0000040B, 0x400D643C, 0x1A904800, 0x0004E3AC },
    { 0x0000040B, 0x400D5C7C, 0x1A953000, 0x00048D9C },
    { 0x0000040B, 0x400B767C, 0x1A99C000, 0x00047518 },
    { 0x0000040B, 0x400441F8, 0x1A9E3800, 0x0001AA84 },
    { 0x0000040B, 0x40106568, 0x1A9FE800, 0x00068C10 },
    { 0x0000040B, 0x4010E5A0, 0x0E97A800, 0x0009BCAC },
    { 0x0000040B, 0x40016980, 0x0EA16800, 0x0000D6C4 },
    { 0x0000040B, 0x40016980, 0x0EA24000, 0x0000C944 },
    { 0x0000040B, 0x40016980, 0x0EA31000, 0x0000E700 },
    { 0x0000040B, 0x40016980, 0x0EA3F800, 0x0000D64C },
    { 0x0000040B, 0x40016980, 0x0EA4D000, 0x0000C900 },
    { 0x0000040B, 0x40016980, 0x0EA5A000, 0x0000CFFC },
    { 0x0000040B, 0x40016980, 0x0EA67000, 0x0000D720 },
    { 0x0000040B, 0x40016980, 0x0EA74800, 0x0000D6CC },
    { 0x0000040B, 0x40016980, 0x0EA82000, 0x0000D21C },
    { 0x0000040B, 0x40016980, 0x0EA8F800, 0x0000D0BC },
    { 0x0000040B, 0x40016980, 0x0EA9D000, 0x0000B544 },
    { 0x0000040B, 0x40016980, 0x0EAA8800, 0x0000C4F8 },
    { 0x0000040B, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 },
    { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 },
    { 0x0000040B, 0x4000A820, 0x18ED3800, 0x00003758 },
    { 0x0000040B, 0x4011EC24, 0x18F0E000, 0x000D8818 },
    { 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8 },
    { 0x0000040B, 0x4006C850, 0x06C96000, 0x0002C884 },
    { 0x0000040B, 0x4005B178, 0x06CC3000, 0x0003555C },
    { 0x0000040B, 0x401EB174, 0x18D43800, 0x000FB220 },
    { 0x0000040B, 0x4001ED60, 0x1AA67800, 0x0000CFF0 },
    { 0x0000040B, 0x4000BF30, 0x1AA74800, 0x000026E0 },
    { 0x0000040B, 0x40003498, 0x1AA77000, 0x00000E28 },
    { 0x0000040B, 0x4000BDE0, 0x1AA78000, 0x000024F4 },
    { 0x0000040B, 0x40006088, 0x1AA7A800, 0x00001290 },
    { 0x0000040B, 0x400049F0, 0x1AA7C000, 0x000018F4 },
    { 0x0000040B, 0x40005ECC, 0x1AA7E000, 0x00001D38 },
    { 0x0000040B, 0x40002670, 0x1AA80000, 0x00000BE8 },
    { 0x00000000, 0x00028240, 0x1AA81000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AAA9800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AAD2000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AAFA800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB23000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB4B800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB74000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB9C800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ABC5000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ABED800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC16000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC3E800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC67000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC8F800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ACB8000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ACE0800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AD09000, 0x00028240 },
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
};

static char lbl_1_data_FF98[47][20] = {
    "game_td",
    "result",
    "operation",
    "game_toy",
    "game_slot",
    "score",
    "rule_toy",
    "rule_mini_01",
    "rule_mini_02",
    "rule_mini_03",
    "rule_mini_05",
    "rule_mini_04",
    "rule_mini_06",
    "rule_mini_07",
    "training",
    "common",
    "logo_all",
    "logo_00",
    "logo_01",
    "logo_02",
    "logo_03",
    "logo_04",
    "logo_05",
    "logo_06",
    "logo_07",
    "logo_08",
    "logo_09",
    "logo_10",
    "logo_11",
    "chara_sel",
    "select",
    "dictionary",
    "score",
    "end",
    "option",
    "logo_all",
    "title",
    "comingsoon",
    "bg_test",
    "load",
    "fade00",
    "fade01",
    "fade02",
    "fade03",
    "fade04",
    "fade05",
    "fade06",
};

// Read by fn_80034E20; a _00 of 3 ends the list.
static SpriteDesc7730 lbl_1_data_10344[2] = {
    { 0, 0, 0.0f, 0.0f, -1, { 1, 4 }, 0xFF, { 0, 0, 0 } },
    { 3 },
};

static u32 lbl_1_data_10384[56] = {
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
    0xFF0000FF, 0x00FF00FF, 0xFFFF00FF, 0x0000FFFF, 0xFF00FFFF, 0x00FFFFFF, 0xFFFFFFFF,
};
static s32 lbl_1_data_10464 = 100;
static f32 lbl_1_data_10468 = 200.0f;
static f32 lbl_1_data_1046C = 100.0f;
static f32 lbl_1_data_10470 = 20.0f;
static s32 lbl_1_data_10474 = 10;
static f32 lbl_1_data_10478 = 1.0f;
static f32 lbl_1_data_1047C = 1.0f;
static Vec lbl_1_data_10480 = { 0.0f, -1.0f, 0.0f };
static Vec lbl_1_data_1048C = { 0.0f, 0.0f, -5.0f };
static Vec lbl_1_data_10498 = { 0.0f, 0.0f, 0.0f };

static f32 lbl_1_data_104A4 = 50.0f;

static void (*lbl_1_data_104A8[4])(void) = { fn_1_1F2D8, fn_1_24410, fn_1_22644, fn_1_2040C };
static f32 lbl_1_data_104B8 = 0.3f;
static f32 lbl_1_data_104BC = 0.031496063f;
static f32 lbl_1_data_104C0 = 1.0f;
static f32 lbl_1_data_104C4 = 0.98f;
static f32 lbl_1_data_104C8 = 0.05f;
static s32 lbl_1_data_104CC = 0x400;

static f32 lbl_1_data_104D0[3] = { 0.125f, 0.125f, 0.125f };

static u32 lbl_1_data_104DC[6] = { 0xFF8080FF, 0x80FF80FF, 0x8080FFFF, 0xFFFF80FF, 0xFF80FFFF, 0x80FFFFFF };

static u32 lbl_1_data_104F4[5] = {
    0x0000040B, 0x40000528, 0x09438800, 0x00000424,
    0x3E000000,
};

static void (*lbl_1_data_10508[2])(GameTask7730*) = { fn_1_1FD78, fn_1_1F418 };

static void (*lbl_1_data_10510[2])(GameTask7730*) = { fn_1_1F900, fn_1_1F618 };

static AramEntry7730 lbl_1_data_10518[21] = {
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

static s16 (*lbl_1_data_10668[1])(s16, u16, u16, u16) = { fn_1_1DE60 };

static void (*lbl_1_data_1066C[1])(s16) = { fn_1_1DE5C };

static s32 lbl_1_data_10670[1] = { 4 };

static AramEntry7730 lbl_1_data_10674[21] = {
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

static u8 lbl_1_data_107C4[32] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    1, 2, 3, 4, 5, 6, 7, 8,
    2, 3, 4, 5, 6, 7, 8, 9,
    3, 4, 5, 6, 7, 8, 9, 10,
};

static DrawEntry7730 lbl_1_data_107E4[2] = {
    { 0, fn_1_1D694 },
    { 0, fn_1_1D694 },
};

// .bss statics, declared in reverse address order (MWCC lays them out in reverse)
static Mtx44 lbl_1_bss_47010;
static struct {
    /* 0x0000 */ SimParams7730 _0000;
    /* 0x0028 */ u8 _0028[0x17A8 - 0x28];
} lbl_1_bss_45868;
static RopeNode7730 lbl_1_bss_43F68[100];
static Mtx lbl_1_bss_43F38;
static struct {
    /* 0x00 */ Mtx _00;
    /* 0x30 */ s16 _30;
    /* 0x32 */ s16 _32;
    /* 0x34 */ u8 _34[0x38 - 0x34];
    /* 0x38 */ f32 _38;
    /* 0x3C */ Vec _3C;
    /* 0x48 */ Vec _48;
    /* 0x54 */ u8 _54[0x58 - 0x54];
} lbl_1_bss_43EE0;
static Vec lbl_1_bss_F6E0[160][112];
static f32 lbl_1_bss_76E0[2][32 * 128];
static f32 lbl_1_bss_74E0[128];
static RopeNode7730 lbl_1_bss_6FE0[20];
static SimParams7730 lbl_1_bss_6FB8;
static u8 lbl_1_bss_6FB4[4];
static Vec lbl_1_bss_6FA8;
static void* lbl_1_bss_6FA4;
static GXTexObj lbl_1_bss_6EA4[8];
static GXTlutObj lbl_1_bss_6E44[8];
static u32 lbl_1_bss_6E24[8];
static Camera7978 lbl_1_bss_6D48;
static Actor7730 lbl_1_bss_6BF4;
static struct {
    /* 0x0 */ f32 _0;
    /* 0x4 */ Vec _4;
} lbl_1_bss_6BE4;
static ModelTable7730* lbl_1_bss_6BE0;
static s32 lbl_1_bss_6BDC;
static s32 lbl_1_bss_6BD8;

// .text:0x00026AF8 size:0x84
void fn_1_26AF8(void) {
    LoadTask7730* task = lbl_803CC1B8;

    task->_1E = 0;
    task->_20 = 0;
    task->_21 = 0;
    task->_1F = 0;
    task->_22 = 0;
    while (lbl_1_data_FB98[task->_1F]._0[0] != 0) {
        task->_1F++;
    }
    fn_80035A00();
    ((LoadTask7730*)lbl_803CC1B8)->_00 = fn_1_26928;
}

// .text:0x00026A34 size:0xC4
void fn_1_26A34(void) {
    GXSetProjection(lbl_1_bss_47010, GX_PERSPECTIVE);
    GXClearVtxDesc();
    GXSetCullMode(GX_CULL_NONE);
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
}

// .text:0x00026928 size:0x10C
void fn_1_26928(void) {
    LoadTask7730* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._04 & 2) {
        task->_20++;
        if (task->_20 == task->_1F) {
            task->_20 = 0;
        }
    } else if (lbl_803C77B8[0]._04 & 1) {
        if (task->_20 == 0) {
            task->_20 = task->_1F;
        }
        task->_20--;
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        task->_1E = 0;
        ((LoadTask7730*)lbl_803CC1B8)->_00 = fn_1_267F4;
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        fn_800AD038(lbl_80366158._08);
        ((LoadTask7730*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
    } else if (lbl_803C77B8[0]._02 & 0x1000) {
        task->_00 = fn_1_25C68;
    }
    fn_800B24D4(4);
    fn_800B1188();
}

// .text:0x000267F4 size:0x134
void fn_1_267F4(void) {
    LoadTask7730* task = lbl_803CC1B8;
    s32 id;

    switch (task->_1E) {
    case 0:
        if (fn_80035838(&lbl_1_data_FB98[task->_20], 0) != 0) {
            task->_1E++;
        }
        break;
    case 1:
        task->_14 = fn_800B0A5C_insertQueue(fn_1_267BC, 1);
        task->_14->_10 = 0;
        id = fn_80035DD4(0);
        if (id == -1) {
            OSPanic("spr.c", 245, "It is a number not registered. \n");
        }
        task->_18 = lbl_803C4BE0[id]._38->_08->_00;
        fn_80034E20(task->_14, lbl_1_data_10344);
        task->_21 = 0;
        task->_22 = 0;
        task->_24 = 0;
        task->_1A = 0;
        task->_1C = 0;
        ((LoadTask7730*)lbl_803CC1B8)->_00 = fn_1_25F98;
        break;
    }
}

// .text:0x000267BC size:0x38
void fn_1_267BC(void) {
    if (((SprTask7730*)lbl_803CC1B8)->_10 != 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00025F98 size:0x824
// 99.85%: in case 3 the target keeps the sprite index's shift in r6 and the key in r0;
// the base swaps them.
void fn_1_25F98(void) {
    LoadTask7730* task = lbl_803CC1B8;
    AnimKey7730 key;
    s32 i;

    for (i = 0; i < 6; i++) {
        switch (i) {
        case 0:
            if (i == task->_22) {
                if (lbl_803C77B8[0]._04 & 2) {
                    fn_80034CEC(task->_14);
                    task->_21++;
                    if (task->_21 == task->_18) {
                        task->_21 = 0;
                    }
                    task->_24 = 0;
                    lbl_1_data_10344[0]._02 = task->_21;
                    fn_80034E20(task->_14, lbl_1_data_10344);
                } else if (lbl_803C77B8[0]._04 & 1) {
                    fn_80034CEC(task->_14);
                    if (task->_21 == 0) {
                        task->_21 = task->_18;
                    }
                    task->_21--;
                    task->_24 = 0;
                    lbl_1_data_10344[0]._02 = task->_21;
                    fn_80034E20(task->_14, lbl_1_data_10344);
                } else if (lbl_803C77B8[0]._02 & 0x100) {
                    lbl_80371C30[task->_14->_14]._00->_68 = 1;
                } else if (lbl_803C77B8[0]._02 & 0x200) {
                    lbl_80371C30[task->_14->_14]._00->_68 = 0;
                } else if (lbl_803C77B8[0]._02 & 0x400) {
                    lbl_80371C30[task->_14->_14]._00->_5C = 0;
                }
            }
            break;
        case 1:
            if (i == task->_22) {
                if (lbl_803C77B8[0]._02 & 0x100) {
                    task->_23 = !task->_23;
                }
                if (task->_23 != 0) {
                    lbl_80371C30[task->_14->_14]._00->_68 = 0;
                } else {
                    lbl_80371C30[task->_14->_14]._00->_68 = 1;
                }
                if (lbl_803C77B8[0]._04 & 2) {
                    if (task->_23 != 0) {
                        lbl_80371C30[task->_14->_14]._00->_68 = 1;
                    }
                } else if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_23 != 0) {
                        lbl_80371C30[task->_14->_14]._00->_68 = 4;
                    }
                }
            }
            break;
        case 2:
            if (i == task->_22) {
                if (lbl_803C77B8[0]._04 & 2) {
                    task->_24++;
                } else if (lbl_803C77B8[0]._04 & 1) {
                    task->_24--;
                }
            }
            fn_8000CEF0(lbl_803C4BE0[lbl_80371C30[task->_14->_14]._00->_66]._38, task->_21, 0, task->_24, &key);
            break;
        case 3:
            if (i == task->_22) {
                if (lbl_803C77B8[0]._04 & 2) {
                    key._06++;
                } else if (lbl_803C77B8[0]._04 & 1) {
                    key._06--;
                }
                lbl_803C4BE0[lbl_80371C30[task->_14->_14]._00->_66]._38->_08->_08[task->_21]->_0C->_0A = key._06;
            }
            break;
        case 4:
            if (i == task->_22) {
                if (lbl_803C77B8[0]._04 & 0x800) {
                    task->_1A = 0;
                } else if (lbl_803C77B8[0]._04 & 0x400) {
                    task->_1A = 320;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_1A += 8;
                } else if (lbl_803C77B8[0]._04 & 1) {
                    task->_1A -= 8;
                }
                lbl_1_data_10344[0]._04 = task->_1A;
                lbl_80371C30[task->_14->_14]._00->_48 = task->_1A;
            }
            break;
        case 5:
            if (i == task->_22) {
                if (lbl_803C77B8[0]._04 & 0x800) {
                    task->_1C = 0;
                } else if (lbl_803C77B8[0]._04 & 0x400) {
                    task->_1C = 224;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_1C += 8;
                } else if (lbl_803C77B8[0]._04 & 1) {
                    task->_1C -= 8;
                }
                lbl_1_data_10344[0]._08 = task->_1C;
                lbl_80371C30[task->_14->_14]._00->_4C = task->_1C;
            }
            break;
        }
    }
    if (lbl_803C77B8[0]._02 & 4) {
        task->_22++;
        if (task->_22 == 6) {
            task->_22 = 0;
        }
    } else if (lbl_803C77B8[0]._02 & 8) {
        if (task->_22 == 0) {
            task->_22 = 6;
        }
        task->_22--;
    }
    if (lbl_803C77B8[0]._02 & 0x1000) {
        fn_80034CEC(task->_14);
        task->_14->_10 = 1;
        ((LoadTask7730*)lbl_803CC1B8)->_00 = fn_1_26928;
        fn_80035A00();
    }
    {
        Mtx m = {
            { 1.0f, 0.0f, 0.0f, 0.0f },
            { 0.0f, 1.0f, 0.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f, 0.0f },
        };

        if (lbl_1_bss_6BD8 != 0) {
            GXClearVtxDesc();
            GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
            GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 0);
            GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
            GXSetNumChans(0);
            GXSetNumTexGens(1);
            GXSetNumTevStages(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
            GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
            GXLoadPosMtxImm(m, GX_PNMTX0);
            GXSetCurrentMtx(GX_PNMTX0);
            SetDisplayStateTexture(lbl_803C4BE0[lbl_80371C30[task->_14->_14]._00->_66]._34 + lbl_1_bss_6BDC * 32 + 4, 0, 0);
            GXBegin(GX_QUADS, GX_VTXFMT0, 4);
            GXPosition3f32(-0.5f, -0.35f, -2.0f);
            GXTexCoord2s16(0, 0);
            GXPosition3f32(-0.5f, 0.35f, -2.0f);
            GXTexCoord2s16(0, 1);
            GXPosition3f32(0.5f, 0.35f, -2.0f);
            GXTexCoord2s16(1, 1);
            GXPosition3f32(0.5f, -0.35f, -2.0f);
            GXTexCoord2s16(1, 0);
        }
    }
}

// .text:0x00025C68 size:0x330
void fn_1_25C68(void) {
    ChainTask7730* task = lbl_803CC1B8;
    u32 color;

    color = 0;
    GXSetCopyClear(*(GXColor*)&color, 0xFFFFFF);
    C_MTXFrustum(lbl_1_bss_47010, -224.0f, 224.0f, -320.0f, 320.0f, 1.0f, 512.0f);
    C_MTXLookAt(lbl_1_bss_43F38, &lbl_1_data_1048C, &lbl_1_data_10480, &lbl_1_data_10498);
    task->_18 = 64.0f * lbl_1_data_10468;
    task->_1C = 64.0f * lbl_1_data_1046C;
    task->_1A = lbl_1_data_10470;
    task->_1E = 32;
    task->_2A = lbl_1_data_10474;
    task->_22 = 10;
    task->_2B = 20;
    task->_20 = 64.0f * lbl_1_data_1047C;
    task->_24 = 64.0f * lbl_1_data_10478;
    task->_14 = 0.5f;
    task->_26 = 100;
    task->_28 = 10;
    fn_1_24A8C();
    ((ChainTask7730*)lbl_803CC1B8)->_00 = fn_1_25064;
    task->_2C = 0;
}

// .text:0x00025064 size:0xC04
void fn_1_25064(void) {
    ChainTask7730* task = lbl_803CC1B8;
    s32 i;
    u32 color;
    s32 big;
    s32 small;

    if (lbl_803C77B8[0]._00 & 0x20) {
        big = 4;
        small = 1;
    } else {
        big = 64;
        small = 10;
    }
    for (i = 0; i < 11; i++) {
        switch (i) {
        case 0:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_2B--;
                    fn_1_24A8C();
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_2B++;
                    fn_1_24A8C();
                }
            }
            break;
        case 1:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_2A--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_2A++;
                }
                if (task->_2A == 0) {
                    task->_2A = 1;
                }
            }
            break;
        case 2:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_18 -= big;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_18 += big;
                }
            }
            break;
        case 3:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_1C -= big;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_1C += big;
                }
            }
            break;
        case 4:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_1A -= small;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_1A += small;
                }
            }
            break;
        case 5:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_24 -= big;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_24 += big;
                }
            }
            break;
        case 6:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_22--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_22++;
                }
            }
            break;
        case 7:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_20 -= small;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_20 += small;
                }
            }
            break;
        case 8:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_26 -= small;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_26 += small;
                }
            }
            break;
        case 9:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_1E -= big;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_1E += big;
                }
            }
            break;
        case 10:
            if (i == task->_2C) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_28 -= small;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_28 += small;
                }
            }
            break;
        }
    }
    if (lbl_803C77B8[0]._04 & 8) {
        if (task->_2C == 0) {
            task->_2C = 11;
        }
        task->_2C--;
    } else if (lbl_803C77B8[0]._04 & 4) {
        task->_2C++;
        if (task->_2C == 11) {
            task->_2C = 0;
        }
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        fn_1_24A8C();
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        color = 0x11775500;
        GXSetCopyClear(*(GXColor*)&color, 0xFFFFFF);
        ((MenuTask7730*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
    }
    fn_1_247A0();
    fn_1_26A34();
    GXLoadPosMtxImm(lbl_1_bss_43F38, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    fn_1_AF4(11, 11, 50.0f);
    fn_1_248BC(task->_2B);
}

// .text:0x00024C4C size:0x418
void fn_1_24C4C(PhysNode7730* nodes, s32 count, Vec* external, f32 k, f32 damping, f32 rest, f32 drag) {
    ChainTask7730* task = lbl_803CC1B8;
    Vec d;
    Vec dv;
    Vec spring;
    f32 first;
    f32 mag;
    f32 len;
    f32 friction;
    f32 force;
    s32 i;
    PhysNode7730* prev;
    s32 j;

    first = 1.0f;
    i = count;
    while (i-- != 0) {
        if (nodes[i]._38 != 0) {
            nodes[i]._2C.z = 0.0f;
            nodes[i]._2C.y = 0.0f;
            nodes[i]._2C.x = 0.0f;
        } else {
            nodes[i]._2C.z = 0.0f;
            nodes[i]._2C.x = 0.0f;
            nodes[i]._2C.y = -9.80665f * nodes[i]._00;
        }
        mag = PSVECMag(&nodes[i]._20);
        if (mag) {
            PSVECScale(&nodes[i]._20, -1.0f * drag, &d);
            PSVECNormalize(&d, &d);
            PSVECScale(&d, task->_20 / 10000.0f * (mag * mag), &d);
            PSVECAdd(&nodes[i]._2C, &d, &nodes[i]._2C);
        }
        if (first) {
            PSVECAdd(&nodes[i]._2C, external, &nodes[i]._2C);
            first = 0.0f;
        }
    }
    j = count;
    while (--j != 0) {
        prev = &nodes[j - 1];
        PSVECSubtract(&nodes[j]._08, &prev->_08, &d);
        PSVECSubtract(&nodes[j]._20, &prev->_20, &dv);
        PSVECScale(&dv, drag, &dv);
        len = PSVECMag(&d);
        mag = damping * (PSVECDotProduct(&dv, &d) / len);
        PSVECNormalize(&d, &spring);
        force = k * (len - rest);
        PSVECScale(&spring, -(force + mag), &spring);
        if (nodes[j]._38 == 0) {
            PSVECAdd(&nodes[j]._2C, &spring, &nodes[j]._2C);
        }
        PSVECScale(&spring, -1.0f, &spring);
        if (prev->_38 == 0) {
            PSVECAdd(&prev->_2C, &spring, &prev->_2C);
        }
    }
    i = count;
    while (i-- != 0) {
        if (nodes[i]._38 == 0 && nodes[i]._08.y <= task->_28 / 1000.0f && PSVECMag(&nodes[i]._20) != 0.0f) {
            friction = task->_1E / 64.0f * nodes[i]._2C.y;
            if (friction < 0.0f) {
                friction = -friction;
            }
            memcpy(&d, &nodes[i]._2C, sizeof(Vec));
            d.y = 0.0f;
            mag = PSVECMag(&d);
            if (mag) {
                PSVECNormalize(&d, &d);
                if (friction > mag) {
                    PSVECScale(&d, -mag, &d);
                } else {
                    PSVECScale(&d, -friction, &d);
                }
                PSVECAdd(&d, &nodes[i]._2C, &nodes[i]._2C);
            }
        }
    }
}

// .text:0x00024A8C size:0x1C0
// 92.90%: the final call's argument setup is scheduled differently (the target converts
// task->_24 after loading 0.015625f and the pool addresses). Writing it `/ 64.0f` matches the
// inlined copies in fn_1_25064 and fn_1_25C68 but drops this function to 89.78%.
void fn_1_24A8C(void) {
    ChainTask7730* task = lbl_803CC1B8;
    f32 dt;

    fn_80038E2C(&lbl_1_bss_45868);
    lbl_1_bss_45868._0000._00 = task->_1A;
    lbl_1_bss_45868._0000._04 = task->_14;
    lbl_1_bss_45868._0000._08 = task->_18 / 64.0f;
    lbl_1_bss_45868._0000._0C = task->_1C / 64.0f;
    lbl_1_bss_45868._0000._10 = task->_1E / 64.0f;
    lbl_1_bss_45868._0000._14 = task->_20 / 10000.0f;
    lbl_1_bss_45868._0000._20 = task->_2A;
    dt = 1.0f / lbl_1_bss_45868._0000._20;
    lbl_1_bss_45868._0000._18 = dt;
    lbl_1_bss_45868._0000._1C = dt * dt;
    lbl_1_bss_45868._0000._24 = 1.0f / (2.0f * dt);
    if (lbl_803C77B8[0]._00 & 0x40) {
        lbl_1_bss_45868._0000._20 = 1;
    }
    fn_80038CD0(task->_2B, &lbl_1_bss_45868, lbl_1_bss_43F68, 10.0f, task->_24 * 0.015625f);
}

// .text:0x000248BC size:0x1D0
void fn_1_248BC(s32 count) {
    u8 width;
    GXTexOffset texOffsets;
    s32 i;

    GXGetLineWidth(&width, &texOffsets);
    GXSetLineWidth(24, texOffsets);
    GXBegin(GX_LINESTRIP, GX_VTXFMT0, count);
    i = count;
    while (i-- != 0) {
        GXPosition3f32(lbl_1_bss_43F68[i]._0C.x, lbl_1_bss_43F68[i]._0C.y, lbl_1_bss_43F68[i]._0C.z);
        GXColor1u32(lbl_1_data_10384[i]);
    }
    GXSetLineWidth(width, texOffsets);
    GXBegin(GX_LINES, GX_VTXFMT0, count * 4);
    i = count;
    while (i-- != 0) {
        GXPosition3f32(lbl_1_bss_43F68[i]._0C.x, lbl_1_bss_43F68[i]._0C.y, lbl_1_bss_43F68[i]._0C.z);
        GXColor1u32(lbl_1_data_10384[i]);
        GXPosition3f32(lbl_1_data_104A4 * lbl_1_bss_43F68[i]._30.x + lbl_1_bss_43F68[i]._0C.x,
                       lbl_1_data_104A4 * lbl_1_bss_43F68[i]._30.y + lbl_1_bss_43F68[i]._0C.y,
                       lbl_1_data_104A4 * lbl_1_bss_43F68[i]._30.z + lbl_1_bss_43F68[i]._0C.z);
        GXColor1u32(lbl_1_data_10384[i]);
        GXPosition3f32(lbl_1_bss_43F68[i]._0C.x, lbl_1_bss_43F68[i]._0C.y, lbl_1_bss_43F68[i]._0C.z);
        GXColor1u32(lbl_1_data_10384[i] ^ 0xFFFFFF00);
        GXPosition3f32(lbl_1_data_104A4 * lbl_1_bss_43F68[i]._24.x + lbl_1_bss_43F68[i]._0C.x,
                       lbl_1_data_104A4 * lbl_1_bss_43F68[i]._24.y + lbl_1_bss_43F68[i]._0C.y,
                       lbl_1_data_104A4 * lbl_1_bss_43F68[i]._24.z + lbl_1_bss_43F68[i]._0C.z);
        GXColor1u32(lbl_1_data_10384[i] ^ 0xFFFFFF00);
    }
}

// .text:0x000247A0 size:0x11C
void fn_1_247A0(void) {
    ChainTask7730* task = lbl_803CC1B8;
    Vec force;

    force.x = task->_22 * (lbl_803C77B8[0]._10 * lbl_1_bss_43F68[task->_2B - 1]._00);
    force.y = task->_22 * (lbl_803C77B8[0]._13 * lbl_1_bss_43F68[task->_2B - 1]._00);
    force.z = task->_22 * (lbl_803C77B8[0]._11 * lbl_1_bss_43F68[task->_2B - 1]._00);
    fn_80038B48(&lbl_1_bss_45868, lbl_1_bss_43F68, task->_2B, &force);
}

// .text:0x00024778 size:0x28
void fn_1_24778(void) {
    ((MenuTask7730*)lbl_803CC1B8)->_14 = 0;
    ((MenuTask7730*)lbl_803CC1B8)->_00 = fn_1_246AC;
}

// .text:0x000246AC size:0xCC
void fn_1_246AC(void) {
    MenuTask7730* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._04 & 8) {
        if (task->_14 == 0) {
            task->_14 = 4;
        }
        task->_14--;
    } else if (lbl_803C77B8[0]._04 & 4) {
        task->_14++;
        if (task->_14 == 4) {
            task->_14 = 0;
        }
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        task->_00 = lbl_1_data_104A8[task->_14];
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00024410 size:0x29C
void fn_1_24410(void) {
    WaveTask7730* task = lbl_803CC1B8;
    s32 i;
    s32 j;
    s32 idx;

    fn_1_23AD8(lbl_1_bss_47010, &lbl_1_bss_43EE0._48, &lbl_1_bss_43EE0._3C);
    lbl_1_bss_43EE0._30 = 0;
    lbl_1_bss_43EE0._38 = 0.0f;
    lbl_1_bss_43EE0._32 = 0;
    task->_27 = 64;
    task->_29 = 64;
    task->_28 = 64;
    task->_2A = 0;
    task->_14 = 500.0f;
    task->_18 = 32.0f;
    task->_24 = 0;
    task->_1C = 0.15f;
    task->_20 = 0.08f;
    task->_2B = 1;
    for (i = 0; i < 128; i++) {
        lbl_1_bss_74E0[i] = cos(3.1415925f * (2.0f * (i / 128.0f)));
    }
    task->_2C = 0;
    memset(lbl_1_bss_76E0, 0, sizeof(lbl_1_bss_76E0));
    for (j = 0; j < 32; j++) {
        idx = (rand() % 32) * 128;
        idx += rand() % 128;
        lbl_1_bss_76E0[0][idx] = 1.0f;
    }
    ((WaveTask7730*)lbl_803CC1B8)->_00 = fn_1_23B54;
}

// .text:0x00023B54 size:0x8BC
// 98.05%: registers differ in the inlined fn_1_22F4C (index offsets) and in the height
// loop (16.0f and the conversion constant swap f1/f2).
void fn_1_23B54(void) {
    WaveTask7730* task = lbl_803CC1B8;
    s32 i;
    s32 idx;
    s32 j;
    s32 n;
    s32 frame;
    f32 x;
    f32 fx;
    f32 fy;
    f32 y;
    f32 max;
    f32 min;
    Vec* p;

    for (i = 0; i < 8; i++) {
        switch (i) {
        case 0:
            if (i == task->_26) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_27 == 2) {
                        task->_27 = 112;
                    }
                    task->_27--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    if (task->_27 == 112) {
                        task->_27 = 2;
                    }
                    task->_27++;
                }
            }
            break;
        case 1:
            if (i == task->_26) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_28 == 2) {
                        task->_28 = 160;
                    }
                    task->_28--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    if (task->_28 == 160) {
                        task->_28 = 2;
                    }
                    task->_28++;
                }
            }
            break;
        case 2:
            if (i == task->_26 && (lbl_803C77B8[0]._04 & 3)) {
                task->_2A = !task->_2A;
            }
            break;
        case 3:
            if (i == task->_26) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_14 > 1.0f) {
                        task->_14 -= 1.0f;
                    }
                } else if (lbl_803C77B8[0]._04 & 2) {
                    if (task->_14 < 512.0f) {
                        task->_14 += 1.0f;
                    }
                }
            }
            break;
        case 4:
            if (i == task->_26) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_18 > 1.0f) {
                        task->_18 -= 1.0f;
                    }
                } else if (lbl_803C77B8[0]._04 & 2) {
                    if (task->_18 < 512.0f) {
                        task->_18 += 1.0f;
                    }
                }
            }
            break;
        case 5:
            if (i == task->_26 && (lbl_803C77B8[0]._04 & 3)) {
                task->_2B = !task->_2B;
            }
            break;
        case 6:
            if (i == task->_26) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_1C > 0.0f) {
                        task->_1C -= 0.001f;
                    }
                } else if (lbl_803C77B8[0]._04 & 2) {
                    if (task->_1C < 1.0f) {
                        task->_1C += 0.001f;
                    }
                }
            }
            break;
        case 7:
            if (i == task->_26) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_20 > 0.0f) {
                        task->_20 -= 0.001f;
                    }
                } else if (lbl_803C77B8[0]._04 & 2) {
                    if (task->_20 < 1.0f) {
                        task->_20 += 0.001f;
                    }
                }
            }
            break;
        }
    }
    if (lbl_803C77B8[0]._04 & 8) {
        if (task->_26 == 0) {
            task->_26 = 8;
        }
        task->_26--;
    } else if (lbl_803C77B8[0]._04 & 4) {
        task->_26++;
        if (task->_26 == 8) {
            task->_26 = 0;
        }
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        ((WaveTask7730*)lbl_803CC1B8)->_00 = fn_1_24778;
    } else if (lbl_803C77B8[0]._04 & 0x100) {
        for (j = 0; j < 16; j++) {
            idx = (rand() % 32) * 128;
            idx += rand() % 128;
            lbl_1_bss_76E0[0][idx] += task->_1C;
        }
    }
    fn_1_121D4(&lbl_1_bss_43EE0);
    if (task->_2A == 0) {
        task->_29 = fn_1_23098(lbl_1_bss_47010, lbl_1_bss_43EE0._00, task->_27, task->_28, task->_18, task->_14);
        if (task->_2B != 0) {
            frame = task->_2C++;
            fn_1_22F4C(32, 128, lbl_1_bss_76E0[1 - (frame & 1)], lbl_1_bss_76E0[frame & 1],
                       lbl_1_bss_76E0[1 - (frame & 1)]);
            max = -100.0f;
            min = 100.0f;
            for (i = 0; i < task->_28; i++) {
                p = lbl_1_bss_F6E0[i];
                for (j = 0; j < task->_29; j++) {
                    x = p->x;
                    y = p->y;
                    idx = task->_2C;
                    if (x < 0.0f) {
                        n = -x;
                    } else {
                        n = x;
                    }
                    n = n / 2 * 2;
                    if (x < 0.0f) {
                        fx = x + (n + 2);
                    } else {
                        fx = x - n;
                    }
                    fx = 64.0f * fx;
                    if (y < 0.0f) {
                        n = -y;
                    } else {
                        n = y;
                    }
                    n = n / 2 * 2;
                    if (y < 0.0f) {
                        fy = y + (n + 2);
                    } else {
                        fy = y - n;
                    }
                    fy = 16.0f * fy;
                    p->z = lbl_1_bss_76E0[idx & 1][(s32)fx + ((s32)fy << 7)];
                    if (p->z < min) {
                        min = p->z;
                    } else if (p->z > max) {
                        max = p->z;
                    }
                    p++;
                }
            }
        } else {
            max = min = 0.0f;
            for (i = 0; i < task->_28; i++) {
                p = lbl_1_bss_F6E0[i];
                for (j = 0; j < task->_29; j++) {
                    p->z = min;
                    p++;
                }
            }
        }
    }
    fn_1_23804(10, 10, task->_29, task->_28, max, min);
    task->_24++;
}

// .text:0x00023AD8 size:0x7C
void fn_1_23AD8(Mtx44 m, Vec* eye, Vec* at) {
    eye->x = 0.0f;
    eye->y = 0.0f;
    eye->z = -10.0f;
    at->x = 0.0f;
    at->y = 0.0f;
    at->z = 0.0f;
    C_MTXFrustum(m, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
}

// .text:0x00023804 size:0x2D4
void fn_1_23804(s32 arg0, s32 arg1, s32 rows, s32 cols, f32 arg4, f32 arg5) {
    s32 n;

    fn_1_26A34();
    GXLoadPosMtxImm(lbl_1_bss_43EE0._00, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    n = cols;
    while (--rows != 0) {
        cols = n;
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, n * 2);
        while (cols-- != 0) {
            GXPosition3f32(lbl_1_bss_F6E0[cols][rows].x, lbl_1_bss_F6E0[cols][rows].z, lbl_1_bss_F6E0[cols][rows].y);
            GXColor1u32((rows & 1) ? 0xFFFFFFFF : 0x0000FFFF);
            GXPosition3f32(lbl_1_bss_F6E0[cols][rows - 1].x, lbl_1_bss_F6E0[cols][rows - 1].z, lbl_1_bss_F6E0[cols][rows - 1].y);
            if (rows & 1) {
                GXColor1u32(0x0000FFFF);
            } else {
                GXColor1u32(0xFFFFFFFF);
            }
        }
    }
    GXBegin(GX_LINESTRIP, GX_VTXFMT0, 8);
    GXPosition3f32(-25.0f, 0.0f, -25.0f);
    GXColor1u32(0xFF0000FF);
    GXPosition3f32(-25.0f, 0.0f, 25.0f);
    GXColor1u32(0xFF0000FF);
    GXPosition3f32(-25.0f, 0.0f, 25.0f);
    GXColor1u32(0x0000FFFF);
    GXPosition3f32(25.0f, 0.0f, 25.0f);
    GXColor1u32(0x0000FFFF);
    GXPosition3f32(25.0f, 0.0f, 25.0f);
    GXColor1u32(0xFF0000FF);
    GXPosition3f32(25.0f, 0.0f, -25.0f);
    GXColor1u32(0xFF0000FF);
    GXPosition3f32(25.0f, 0.0f, -25.0f);
    GXColor1u32(0x0000FFFF);
    GXPosition3f32(-25.0f, 0.0f, -25.0f);
    GXColor1u32(0x0000FFFF);
}

// .text:0x00023098 size:0x76C
// 93.07%: the target subtracts frsp(-far) where this folds -near - -far into -near + far,
// so far stays live (five saved FPRs, not four); an f64 local for -far gives the frsp and
// four FPRs but other registers (92.79%).
s32 fn_1_23098(Mtx44 proj, Mtx view, s32 rows, s32 cols, f32 near, f32 far) {
    Mtx44 m;
    Mtx inv;
    Vec hit[4];
    Vec start[4];
    Vec normal;
    Vec origin;
    f32 t[4];
    f32 d;
    f32 nh;
    f32 fh;
    f32 nw;
    f32 fw;
    f32 dy;
    s32 i;
    s32 n;
    s32 last;
    s32 c;
    Vec* row;

    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    normal.x = 0.0f;
    normal.y = -1.0f;
    normal.z = 0.0f;
    PSMTXMultVec(view, &origin, &origin);
    PSMTXMultVec(view, &normal, &normal);
    PSVECSubtract(&normal, &origin, &normal);
    PSVECNormalize(&normal, &normal);
    d = -PSVECDotProduct(&normal, &origin);
    nh = (448.0f * near / 1280.0f) * 0.5f;
    fh = (448.0f * far / 1280.0f) * 0.5f;
    nw = (640.0f * near / 1280.0f) * 0.5f;
    fw = (640.0f * far / 1280.0f) * 0.5f;
    start[0].x = nw;
    start[0].y = 0.0f;
    start[0].z = -near;
    start[1].x = fw;
    start[1].y = 0.0f;
    start[1].z = -far;
    start[2].x = fw;
    start[2].y = fh;
    start[2].z = -far;
    start[3].x = fw;
    start[3].y = -fh;
    start[3].z = -far;
    hit[0].x = 0.0f;
    hit[0].y = nh;
    hit[0].z = 0.0f;
    hit[1].x = 0.0f;
    hit[1].y = fh;
    hit[1].z = 0.0f;
    hit[2].x = nw - fw;
    hit[2].y = nh - fh;
    hit[2].z = -near - -far;
    hit[3].x = nw - fw;
    hit[3].y = -(nh - fh);
    hit[3].z = -near - -far;
    for (i = 0; i < 4; i++) {
        t[i] = PSVECDotProduct(&normal, &hit[i]);
        if (t[i] == 0.0f) {
            hit[i].z = 0.0f;
        } else {
            t[i] = -(d + PSVECDotProduct(&normal, &start[i])) / t[i];
            PSVECScale(&hit[i], t[i], &hit[i]);
            PSVECAdd(&start[i], &hit[i], &hit[i]);
        }
        if (t[i] < 0.0f) {
            t[i] = -t[i];
        }
    }
    if (hit[2].z <= -near && hit[2].z >= -far && hit[3].z <= -near && hit[3].z >= -far) {
        memcpy(&hit[0], &hit[2], sizeof(Vec));
        memcpy(&hit[1], &hit[3], sizeof(Vec));
    } else if (!(t[0] <= 1.0f && t[1] <= 1.0f)) {
        if (t[0] <= 1.0f || t[1] <= 1.0f) {
            if (hit[2].z <= -near && hit[2].z >= -far) {
                memcpy(&hit[3], &hit[2], sizeof(Vec));
            }
            if (t[0] < 1.0f) {
                memcpy(&hit[1], &hit[3], sizeof(Vec));
            } else {
                memcpy(&hit[0], &hit[3], sizeof(Vec));
            }
        } else {
            return 0;
        }
    }
    PSMTXInverse(view, inv);
    c = cols - 1;
    PSMTXMultVec(inv, &hit[1], &hit[2]);
    lbl_1_bss_F6E0[c][0].x = hit[2].x;
    lbl_1_bss_F6E0[c][0].y = hit[2].z;
    hit[2].x = -hit[1].x;
    hit[2].y = hit[1].y;
    hit[2].z = hit[1].z;
    PSMTXMultVec(inv, &hit[2], &hit[2]);
    lbl_1_bss_F6E0[0][0].x = hit[2].x;
    lbl_1_bss_F6E0[0][0].y = hit[2].z;
    PSMTXMultVec(inv, &hit[0], &hit[2]);
    lbl_1_bss_F6E0[c][1].x = hit[2].x;
    lbl_1_bss_F6E0[c][1].y = hit[2].z;
    hit[2].x = -hit[0].x;
    hit[2].y = hit[0].y;
    hit[2].z = hit[0].z;
    PSMTXMultVec(inv, &hit[2], &hit[2]);
    lbl_1_bss_F6E0[0][1].x = hit[2].x;
    lbl_1_bss_F6E0[0][1].y = hit[2].z;
    PSMTX44Identity(m);
    memcpy(m, view, sizeof(Mtx));
    PSMTX44Concat(proj, m, m);
    C_MTX44Inverse(m, m);
    PSMTX44MultVec(proj, &hit[0], &hit[0]);
    PSMTX44MultVec(proj, &hit[1], &hit[1]);
    dy = hit[0].y - hit[1].y;
    if (dy < 0.0f) {
        dy = -dy;
    }
    n = rows * (dy + 2.0f / rows) / 2.0f;
    if (n < 2) {
        n = 2;
    }
    last = n - 1;
    lbl_1_bss_F6E0[0][last].x = lbl_1_bss_F6E0[0][1].x;
    lbl_1_bss_F6E0[0][last].y = lbl_1_bss_F6E0[0][1].y;
    lbl_1_bss_F6E0[c][last].x = lbl_1_bss_F6E0[c][1].x;
    lbl_1_bss_F6E0[c][last].y = lbl_1_bss_F6E0[c][1].y;
    PSVECSubtract(&hit[0], &hit[1], &hit[2]);
    i = last;
    while (--i != 0) {
        PSVECScale(&hit[2], (f32)i / (f32)last, &hit[3]);
        PSVECAdd(&hit[1], &hit[3], &hit[3]);
        PSMTX44MultVec(m, &hit[3], &origin);
        lbl_1_bss_F6E0[c][i].x = origin.x;
        lbl_1_bss_F6E0[c][i].y = origin.z;
        hit[3].x = -hit[3].x;
        PSMTX44MultVec(m, &hit[3], &origin);
        lbl_1_bss_F6E0[0][i].x = origin.x;
        lbl_1_bss_F6E0[0][i].y = origin.z;
    }
    hit[0].y = 0.0f;
    hit[1].y = 0.0f;
    for (i = 0; i < n; i++) {
        row = lbl_1_bss_F6E0[cols - 1];
        hit[0].x = lbl_1_bss_F6E0[0][i].x;
        hit[0].z = lbl_1_bss_F6E0[0][i].y;
        hit[1].x = row[i].x - hit[0].x;
        hit[1].z = row[i].y - hit[0].z;
        last = cols - 1;
        while (--last != 0) {
            PSVECScale(&hit[1], (f32)last / (f32)(cols - 1), &hit[2]);
            PSVECAdd(&hit[0], &hit[2], &hit[2]);
            lbl_1_bss_F6E0[last][i].x = hit[2].x;
            lbl_1_bss_F6E0[last][i].y = hit[2].z;
        }
    }
    return n;
}

// .text:0x00022F4C size:0x14C
void fn_1_22F4C(s32 rows, s32 cols, f32* out, f32* cur, f32* prev) {
    s32 y;
    s32 x;
    f64 c;
    f32 a;
    f32 b;

    c = (1.0 / 60.0) * lbl_1_data_104C0 / lbl_1_data_104BC;
    c = c * c;
    a = c;
    b = 2.0 - 4.0 * c;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            out[y * cols + x] = b * cur[y * cols + x] +
                     a * (cur[x + cols * ((y + rows - 1) % rows)] + cur[x + cols * ((y + 1) % rows)] +
                          cur[(x + cols - 1) % cols + y * cols] + cur[(x + 1) % cols + y * cols]) -
                     prev[y * cols + x];
            out[y * cols + x] *= lbl_1_data_104C4;
        }
    }
}

// .text:0x00022DF4 size:0x158
void fn_1_22DF4(RopeParams7730* params) {
    params->_18 = 0.01f;
    params->_1C = 20.0f;
    params->_25 = 0;
    params->_20 = 10;
    params->_21 = 10;
    params->_22 = 1;
    params->_23 = 0;
    params->_24 = 0;
    fn_80038E2C(&lbl_1_bss_6FB8);
    fn_1_21180(params);
}

// .text:0x00022874 size:0x580
// 99.77%: only volatile registers in the setup of the three step products differ.
s32 fn_1_22874(RopeParams7730* params) {
    RopeParams7730* task = lbl_803CC1B8;
    s32 step;
    f32 coarse;
    f32 medium;
    f32 fine;
    s32 i;
    u8 count;

    if (lbl_803C77B8[0]._00 & 0x20) {
        step = 100;
    } else if (lbl_803C77B8[0]._15 >= 0x50) {
        step = 1;
    } else {
        step = 10;
    }
    coarse = 0.001f * step;
    medium = 0.01f * step;
    fine = 0.0001f * step;
    for (i = 0; i < 14; i++) {
        switch (i) {
        case 0:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_20--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_20++;
                }
                if (task->_20 == 0) {
                    task->_20++;
                }
            }
            break;
        case 1:
            count = task->_21;
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_21--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_21++;
                }
                if (task->_21 < 2) {
                    task->_21++;
                }
            }
            break;
        case 2:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    lbl_1_bss_6FB8._00 -= coarse;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    lbl_1_bss_6FB8._00 += coarse;
                }
            }
            break;
        case 3:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_18 -= medium;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_18 += medium;
                }
            }
            break;
        case 4:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    lbl_1_bss_6FB8._08 -= medium;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    lbl_1_bss_6FB8._08 += medium;
                }
            }
            break;
        case 5:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    lbl_1_bss_6FB8._0C -= medium;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    lbl_1_bss_6FB8._0C += medium;
                }
            }
            break;
        case 6:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    lbl_1_bss_6FB8._10 -= medium;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    lbl_1_bss_6FB8._10 += medium;
                }
            }
            break;
        case 7:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    lbl_1_bss_6FB8._14 -= fine;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    lbl_1_bss_6FB8._14 += fine;
                }
            }
            break;
        case 8:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_1C -= step;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_1C += step;
                }
            }
            break;
        case 9:
            if (i == task->_25 && (lbl_803C77B8[0]._04 & 3)) {
                task->_22 = !task->_22;
            }
            break;
        case 10:
            if (i == task->_25 && (lbl_803C77B8[0]._04 & 3)) {
                task->_23 = !task->_23;
            }
            break;
        case 11:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    lbl_1_data_104D0[0] -= 0.125;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    lbl_1_data_104D0[0] += 0.125;
                }
            }
            break;
        case 12:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    lbl_1_data_104D0[1] -= 0.125;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    lbl_1_data_104D0[1] += 0.125;
                }
            }
            break;
        case 13:
            if (i == task->_25) {
                if (lbl_803C77B8[0]._04 & 1) {
                    lbl_1_data_104D0[2] -= 0.125;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    lbl_1_data_104D0[2] += 0.125;
                }
            }
            break;
        }
    }
    if (lbl_803C77B8[0]._04 & 8) {
        if (task->_25 == 0) {
            task->_25 = 14;
        }
        task->_25--;
    } else if (lbl_803C77B8[0]._04 & 4) {
        task->_25++;
        if (task->_25 == 14) {
            task->_25 = 0;
        }
    }
    return count != task->_21;
}

// .text:0x00022644 size:0x230
void fn_1_22644(void) {
    SprTask7730* task = lbl_803CC1B8;

    fn_800AD038(lbl_80366158._08);
    task->_25 = 0;
    fn_1_22DF4(lbl_803CC1B8);
    fn_1_23AD8(lbl_1_bss_47010, &lbl_1_bss_43EE0._48, &lbl_1_bss_43EE0._3C);
    ((SprTask7730*)lbl_803CC1B8)->_00 = fn_1_225B8;
}

// .text:0x000225B8 size:0x8C
void fn_1_225B8(void) {
    SprTask7730* task = lbl_803CC1B8;
    SprTask7730* child;

    switch (task->_25) {
    case 0:
        child = fn_800B0A5C_insertQueue(fn_1_20BD8, 1);
        child->_25 = 0;
        child->_10 = 0;
        task->_25++;
        break;
    case 1:
        if (task->_10 != 0) {
            task->_00 = fn_1_21408;
        }
        break;
    }
}

// .text:0x00021CE8 size:0x8D0
void fn_1_21CE8(void) {
    RopeParams7730* task = lbl_803CC1B8;
    Vec force;
    f32 scale;

    if (fn_1_22874(task) || (lbl_803C77B8[0]._02 & 0x100)) {
        fn_1_21180(task);
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        ((SprTask7730*)lbl_803CC1B8)->_00 = fn_1_21408;
    }
    if (task->_23 != 0) {
        if (lbl_803C77B8[3]._15 >= 0x50) {
            scale = 0.0001f * task->_1C;
        } else {
            scale = 0.00001f * task->_1C;
        }
        lbl_1_bss_6FE0[task->_21 - 1]._0C.x += lbl_803C77B8[3]._10 * scale;
        lbl_1_bss_6FE0[task->_21 - 1]._0C.y += lbl_803C77B8[3]._13 * scale;
        lbl_1_bss_6FE0[task->_21 - 1]._0C.z += lbl_803C77B8[3]._11 * scale;
        memcpy(&lbl_1_bss_6FE0[task->_21 - 1]._18, &lbl_1_bss_6FE0[task->_21 - 1]._0C, sizeof(Vec));
        force.x = 0.0f;
        force.y = 0.0f;
        force.z = 0.0f;
    } else {
        force.x = task->_1C * (lbl_803C77B8[3]._10 * lbl_1_bss_6FE0[task->_21 - 1]._00);
        force.y = task->_1C * (lbl_803C77B8[3]._13 * lbl_1_bss_6FE0[task->_21 - 1]._00);
        force.z = task->_1C * (lbl_803C77B8[3]._11 * lbl_1_bss_6FE0[task->_21 - 1]._00);
    }
    fn_80038B48(&lbl_1_bss_6FB8, lbl_1_bss_6FE0, task->_21, &force);
    fn_1_26A34();
    GXLoadPosMtxImm(lbl_1_bss_43EE0._00, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    fn_1_21040();
    fn_1_21298(task);
    fn_1_20950(lbl_1_bss_6FE0, task->_21 - 1, lbl_1_bss_43EE0._00);
}

// .text:0x00021408 size:0x8E0
void fn_1_21408(void) {
    RopeParams7730* task = lbl_803CC1B8;
    Vec force;
    f32 scale;

    if (lbl_803C77B8[0]._02 & 0x1000) {
        task->_00 = fn_1_21CE8;
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        fn_1_21180(task);
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        lbl_1_bss_6BE0 = NULL;
        task->_00 = fn_1_24778;
    }
    fn_1_121D4(&lbl_1_bss_43EE0);
    if (task->_23 != 0) {
        if (lbl_803C77B8[3]._15 >= 0x50) {
            scale = 0.0001f * task->_1C;
        } else {
            scale = 0.00001f * task->_1C;
        }
        lbl_1_bss_6FE0[task->_21 - 1]._0C.x += lbl_803C77B8[3]._10 * scale;
        lbl_1_bss_6FE0[task->_21 - 1]._0C.y += lbl_803C77B8[3]._13 * scale;
        lbl_1_bss_6FE0[task->_21 - 1]._0C.z += lbl_803C77B8[3]._11 * scale;
        memcpy(&lbl_1_bss_6FE0[task->_21 - 1]._18, &lbl_1_bss_6FE0[task->_21 - 1]._0C, sizeof(Vec));
        force.x = 0.0f;
        force.y = 0.0f;
        force.z = 0.0f;
    } else {
        force.x = task->_1C * (lbl_803C77B8[3]._10 * lbl_1_bss_6FE0[task->_21 - 1]._00);
        force.y = task->_1C * (lbl_803C77B8[3]._13 * lbl_1_bss_6FE0[task->_21 - 1]._00);
        force.z = task->_1C * (lbl_803C77B8[3]._11 * lbl_1_bss_6FE0[task->_21 - 1]._00);
    }
    fn_80038B48(&lbl_1_bss_6FB8, lbl_1_bss_6FE0, task->_21, &force);
    fn_1_26A34();
    GXLoadPosMtxImm(lbl_1_bss_43EE0._00, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    fn_1_21040();
    fn_1_21298(task);
    if (lbl_1_bss_6BE0 != NULL) {
        fn_1_20950(lbl_1_bss_6FE0, task->_21 - 1, lbl_1_bss_43EE0._00);
    }
}

// .text:0x00021298 size:0x170
void fn_1_21298(RopeParams7730* params) {
    s32 i;

    if (params->_22 != 0) {
        GXBegin(GX_LINESTRIP, GX_VTXFMT0, (params->_21 - 1) * 2);
        i = params->_21;
        while (--i != 0) {
            GXPosition3f32(lbl_1_bss_6FE0[i]._0C.x, 0.0f, lbl_1_bss_6FE0[i]._0C.z);
            GXColor1u32(0x80);
            GXPosition3f32(lbl_1_bss_6FE0[i - 1]._0C.x, 0.0f, lbl_1_bss_6FE0[i - 1]._0C.z);
            GXColor1u32(0x80);
        }
    }
    if (params->_24 != 0) {
        GXBegin(GX_LINESTRIP, GX_VTXFMT0, (params->_21 - 1) * 2);
        i = params->_21;
        while (--i != 0) {
            GXPosition3f32(lbl_1_bss_6FE0[i]._0C.x, -lbl_1_bss_6FE0[i]._0C.y, lbl_1_bss_6FE0[i]._0C.z);
            GXColor1u32(lbl_1_data_104DC[i % 6]);
            GXPosition3f32(lbl_1_bss_6FE0[i - 1]._0C.x, -lbl_1_bss_6FE0[i - 1]._0C.y, lbl_1_bss_6FE0[i - 1]._0C.z);
            GXColor1u32(lbl_1_data_104DC[i % 6]);
        }
    }
}

// .text:0x00021180 size:0x118
void fn_1_21180(RopeParams7730* params) {
    f32 dt;
    s32 last;

    lbl_1_bss_6FB8._20 = params->_20;
    dt = (1.0f / lbl_1_bss_6FB8._20) / 60.0f;
    lbl_1_bss_6FB8._18 = dt;
    lbl_1_bss_6FB8._1C = dt * dt;
    lbl_1_bss_6FB8._24 = 1.0f / (2.0f * dt);
    if (lbl_803C77B8[0]._00 & 0x400) {
        lbl_1_bss_6FB8._20 = 1;
    }
    fn_80038CD0(params->_21, &lbl_1_bss_6FB8, lbl_1_bss_6FE0, 0.2f, params->_18);
    last = params->_21 - 1;
    lbl_1_bss_6FA8.x = lbl_1_bss_6FE0[last]._0C.x;
    lbl_1_bss_6FA8.y = lbl_1_bss_6FE0[last]._0C.y;
    lbl_1_bss_6FA8.z = lbl_1_bss_6FE0[last]._0C.z;
    lbl_1_bss_6FE0[last]._3C = params->_23;
}

// .text:0x00021040 size:0x140
void fn_1_21040(void) {
    s32 i;
    u32 color;

    GXBegin(GX_LINES, GX_VTXFMT0, 44);
    for (i = 0; i < 11; i++) {
        color = 0xFFFFFFFF;
        if (i == 5) {
            color = 0xFF0000FF;
        }
        GXPosition3f32((i - 5) * 10, 0.0f, -50.0f);
        GXColor1u32(color);
        GXPosition3f32((i - 5) * 10, 0.0f, 50.0f);
        GXColor1u32(color);
        if (i == 5) {
            color = 0x00FF00FF;
        }
        GXPosition3f32(-50.0f, 0.0f, (i - 5) * 10);
        GXColor1u32(color);
        GXPosition3f32(50.0f, 0.0f, (i - 5) * 10);
        GXColor1u32(color);
    }
}

// .text:0x00020F8C size:0xB4
void fn_1_20F8C(void) {
    SprTask7730* parent = ((SprTask7730*)lbl_803CC1B8)->_0C;

    switch (((SprTask7730*)lbl_803CC1B8)->_10) {
    case 0:
        if (lbl_803C6CF8._715 == 1) {
            parent->_14 = ARAMTransfer(lbl_1_data_104F4, 0, 0, 0);
            ((SprTask7730*)lbl_803CC1B8)->_10++;
        }
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            parent->_10 = 1;
        }
        break;
    }
}

// .text:0x00020E00 size:0x18C
void fn_1_20E00(SprTask7730* task) {
    GXColor color = { 0x80, 0x80, 0xFF, 0xFF };
    u16 i;
    u8* layout;
    u8* geo;

    LITAlloc(&lbl_1_bss_6FA4);
    LITInitAttn(lbl_1_bss_6FA4, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_1_bss_6FA4, 5.0f, 5.0f, 5.0f);
    LITInitDir(lbl_1_bss_6FA4, 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_1_bss_6FA4, color);
    layout = (u8*)task->_14 + ((u32*)task->_14)[0];
    geo = (u8*)task->_14 + ((u32*)task->_14)[1];
    lbl_1_bss_6BE0 = ActorObjectInitTable(20);
    LoadActorLayout(layout);
    convertGeometryAndSknHeader(geo, NULL);
    haveActLayoutPointToGeoHeader(layout, geo);
    for (i = 0; i < 20; i++) {
        fn_800BDC88(lbl_1_bss_6BE0, i, i, layout, NULL, NULL);
        fn_800B2C08(lbl_1_bss_6BE0->models[i]._00, 0);
        fn_800BD548(&lbl_1_bss_6BE0->models[i], 1, lbl_1_bss_6FA4);
    }
}

// .text:0x00020DC8 size:0x38
void fn_1_20DC8(void) {
    SprTask7730* task = fn_800B0A5C_insertQueue(fn_1_20BD8, 1);
    task->_25 = 0;
    task->_10 = 0;
}

// .text:0x00020BD8 size:0x1F0
void fn_1_20BD8(void) {
    SprTask7730* task = lbl_803CC1B8;
    SprTask7730* child;

    switch (task->_25) {
    case 0:
        child = fn_800B0A5C_insertQueue(fn_1_20F8C, 1);
        child->_10 = 0;
        task->_25++;
        break;
    case 1:
        if (task->_10 != 0) {
            fn_1_20E00(task);
            task->_0C->_10 = 1;
            fn_800B0A14_removeQueue();
        }
        break;
    }
}

// .text:0x00020950 size:0x288
void fn_1_20950(RopeNode7730* nodes, s32 count, Mtx mtx) {
    Vec dir;
    Vec v;
    Quaternion q;
    Quaternion q2;
    Mtx m;
    f32 angle;
    Model7730* model;
    s32 i;

    i = 20;
    while (i-- != 0) {
        model = &lbl_1_bss_6BE0->models[i];
        model->_6C = i < count;
        if (i < count) {
            PSVECSubtract(&nodes[i + 1]._0C, &nodes[i]._0C, &dir);
            PSVECScale(&dir, 0.5f, &v);
            PSVECAdd(&nodes[i]._0C, &v, &v);
            CTRLSetTranslation(&model->_10, v.x, -v.y, v.z);
            if (PSVECMag(&dir)) {
                PSVECNormalize(&dir, &dir);
                dir.y = -dir.y;
                v.x = 1.0f;
                v.y = 0.0f;
                v.z = 0.0f;
                C_QUATRotAxisRad(&q, &v, 3.1415925f * (2.5 + (i & 1)) / 6.0);
                angle = acos(PSVECDotProduct(&dir, &v));
                PSVECCrossProduct(&v, &dir, &v);
                if (PSVECMag(&v)) {
                    C_QUATRotAxisRad(&q2, &v, angle);
                    PSQUATMultiply(&q2, &q, &q);
                }
                CTRLSetQuat(&model->_10, q.x, q.y, q.z, q.w);
            }
            CTRLSetScale(&model->_10, lbl_1_data_104D0[0], lbl_1_data_104D0[1], lbl_1_data_104D0[2]);
            fn_800BDA24(model);
        }
        PSMTXTrans(m, 0.0f, 0.0f, 0.0f);
        PSMTXConcat(mtx, m, m);
        model->_00->_98 |= 3;
    }
    fn_800BD670(lbl_1_bss_6BE0, mtx);
}

// .text:0x00020890 size:0xC0
void fn_1_20890(void) {
    Mtx m;

    C_MTXOrtho(lbl_1_bss_47010, 0.0f, 448.0f, 0.0f, 640.0f, 0.5f, -1.0f);
    GXSetProjection(lbl_1_bss_47010, GX_ORTHOGRAPHIC);
    PSMTXIdentity(m);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXLoadTexMtxImm(m, GX_TEXMTX0, GX_MTX2x4);
    fn_80048C14(3);
    fn_80048E00(0, 32);
    fn_80048E00(1, 0);
}

// .text:0x000207D4 size:0xBC
void fn_1_207D4(void) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 8);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
}

// .text:0x00020640 size:0x194
void fn_1_20640(GameTask7730* task, u32* ids) {
    s32 i;
    u32 id;
    u32 tlut;

    GXSetNumTevStages(task->_22);
    GXSetNumTexGens(task->_22);
    for (i = 0; i < task->_22; i++) {
        GXSetTexCoordGen2(i, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
        if (i != 0) {
            GXSetTevColorIn(i, GX_CC_CPREV, GX_CC_TEXC, GX_CC_RASA, GX_CC_ZERO);
            GXSetTevColorOp(i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            GXSetTevAlphaIn(i, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
            GXSetTevAlphaOp(i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        } else {
            GXSetTevColorIn(i, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
            GXSetTevColorOp(i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            GXSetTevAlphaIn(i, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
            GXSetTevAlphaOp(i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        }
        id = ids[i];
        tlut = id & 0x7FFFFFFF;
        GXLoadTexObj(&lbl_1_bss_6EA4[id], i);
        if (id & 0x80000000) {
            GXLoadTlut(&lbl_1_bss_6E44[tlut], i);
        }
    }
}

// .text:0x0002051C size:0x124
GXBool fn_1_2051C(Tex7730* tex, GXTexObj* obj, GXTlutObj* tlutObj, GXTlut tlutName) {
    GXBool mipmap = tex->minLOD != tex->maxLOD;

    if (tex->tlut != NULL) {
        GXInitTexObjCI(obj, tex->image, tex->width, tex->height, tex->format, tex->wrapS, tex->wrapT, mipmap,
                       tlutName);
        GXInitTlutObj(tlutObj, tex->tlut, tex->tlutFormat, tex->tlutEntries);
    } else {
        GXInitTexObj(obj, tex->image, tex->width, tex->height, tex->format, tex->wrapS, tex->wrapT, mipmap);
    }
    GXInitTexObjLOD(obj, tex->minFilter, tex->magFilter, tex->minLOD, tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE,
                    GX_ANISO_1);
    return tex->tlut != NULL;
}

// .text:0x0002040C size:0x110
void fn_1_2040C(void) {
    GameTask7730* task = lbl_803CC1B8;
    Mtx m;

    task->_1C = 0;
    task->_23 = 0;
    task->_24 = 0;
    task->_20 = 0;
    task->_21 = 0;
    task->_22 = 1;
    C_MTXOrtho(lbl_1_bss_47010, 0.0f, 448.0f, 0.0f, 640.0f, 0.5f, -1.0f);
    GXSetProjection(lbl_1_bss_47010, GX_ORTHOGRAPHIC);
    PSMTXIdentity(m);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXLoadTexMtxImm(m, GX_TEXMTX0, GX_MTX2x4);
    fn_80048C14(3);
    fn_80048E00(0, 32);
    fn_80048E00(1, 0);
    fn_800AD038(lbl_80366158._08);
    ((GameTask7730*)lbl_803CC1B8)->_00 = fn_1_2004C;
}

// .text:0x000202A4 size:0x168
void fn_1_202A4(void) {
    GameTask7730* task = lbl_803CC1B8;
    u32 color;

    fn_80048C1C();
    lbl_1_data_10508[task->_20](task);
    if (lbl_803C77B8[0]._02 & 0x200) {
        color = 0x11775500;
        GXSetCopyClear(*(GXColor*)&color, 0xFFFFFF);
        ((GameTask7730*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
    }
    fn_80048D4C();
    fn_1_207D4();
    lbl_1_data_10510[task->_20](task);
    fn_80048C28();
}

// .text:0x0002004C size:0x258
void fn_1_2004C(void) {
    u32 i;
    GameTask7730* task = lbl_803CC1B8;
    s32 ids[9] = { 5, 6, 7, 8, 9, 13, 0x60, 0x61, 0x55 };

    switch (task->_21) {
    case 0:
        task->_18 = ARAMTransfer(lbl_1_data_10518, 0, 0, 0);
        task->_21++;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            task->_14 = task->_18 + *(s32*)(task->_18 + 0x14);
            convertTextureHeader(task->_14);
            for (i = 0; i < 8; i++) {
                lbl_1_bss_6E24[i] = i;
                if (fn_1_2051C((Tex7730*)(task->_14 + ids[i] * 32 + 4), &lbl_1_bss_6EA4[i], &lbl_1_bss_6E44[i], i)) {
                    lbl_1_bss_6E24[i] |= 0x80000000;
                }
            }
            task->_21 = 0;
            ((GameTask7730*)lbl_803CC1B8)->_00 = fn_1_202A4;
        }
        break;
    }
}

// .text:0x0001FD78 size:0x2D4
void fn_1_1FD78(GameTask7730* task) {
    s32 value;
    u8 sel;
    u32 step;
    s32 i;

    step = 1;
    if (lbl_803C77B8[0]._00 & 0x20) {
        step = 100;
    }
    for (i = 0; i < 6; i++) {
        sel = task->_21;
        switch (i) {
        case 0:
            if (i == sel) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_20 == 0) {
                        task->_20 = 2;
                    }
                    task->_20--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_20++;
                    if (task->_20 == 2) {
                        task->_20 = 0;
                    }
                }
            }
            break;
        case 1:
            value = fn_80048EA8(0);
            if (i == task->_21) {
                if (lbl_803C77B8[0]._04 & 1) {
                    value--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    value++;
                }
                fn_80048E00(0, value);
            }
            break;
        case 2:
            value = fn_80048EA8(1);
            if (i == task->_21) {
                if (lbl_803C77B8[0]._04 & 1) {
                    value--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    value++;
                }
                fn_80048E00(1, value);
            }
            break;
        case 3:
            if (i == sel) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_1C <= step) {
                        task->_1C = 0;
                    } else {
                        task->_1C -= step;
                    }
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_1C += step;
                    if (task->_1C > 0x1000) {
                        task->_1C = 0x1000;
                    }
                }
            }
            break;
        case 4:
            if (i == sel) {
                if (lbl_803C77B8[0]._04 & 1) {
                    task->_23--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_23++;
                }
            }
            break;
        case 5:
            if (i == sel) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_22 > 1) {
                        task->_22--;
                    }
                } else if (lbl_803C77B8[0]._04 & 2) {
                    if (task->_22 < 4) {
                        task->_22++;
                    }
                }
            }
            break;
        }
    }
    if (lbl_803C77B8[0]._04 & 8) {
        if (task->_21 == 0) {
            task->_21 = 6;
        }
        task->_21--;
    } else if (lbl_803C77B8[0]._04 & 4) {
        task->_21++;
        if (task->_21 == 6) {
            task->_21 = 0;
        }
    }
}

// .text:0x0001F900 size:0x478
void fn_1_1F900(GameTask7730* task) {
    u32 ids[4];
    s32 i;
    s32 j;
    s32 k;
    s32 x;
    s32 y;
    u32 tlut;

    for (i = 0; i < task->_1C; i++) {
        k = i % 480 % 48;
        x = k % 8;
        y = k / 8;
        for (j = 0; j < task->_22; j++) {
            ids[j] = lbl_1_bss_6E24[(x + y) % 8];
        }
        GXSetNumTevStages(task->_22);
        GXSetNumTexGens(task->_22);
        for (j = 0; j < task->_22; j++) {
            GXSetTexCoordGen2(j, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            if (j != 0) {
                GXSetTevColorIn(j, GX_CC_CPREV, GX_CC_TEXC, GX_CC_RASA, GX_CC_ZERO);
                GXSetTevColorOp(j, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                GXSetTevAlphaIn(j, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                GXSetTevAlphaOp(j, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            } else {
                GXSetTevColorIn(j, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
                GXSetTevColorOp(j, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                GXSetTevAlphaIn(j, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
                GXSetTevAlphaOp(j, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            }
            tlut = ids[j] & 0x7FFFFFFF;
            GXLoadTexObj(&lbl_1_bss_6EA4[ids[j]], j);
            if (ids[j] & 0x80000000) {
                GXLoadTlut(&lbl_1_bss_6E44[tlut], j);
            }
        }
        GXBegin(GX_QUADS, GX_VTXFMT0, 4);
        GXPosition3f32(x * task->_23, y * task->_23, 0.0f);
        GXColor1u32(0xFFFFFF80);
        GXTexCoord2s16(0, 0);
        GXPosition3f32(x * task->_23, y * task->_23 + task->_23, 0.0f);
        GXColor1u32(0xFFFFFF80);
        GXTexCoord2s16(0, 0x100);
        GXPosition3f32(x * task->_23 + task->_23, y * task->_23 + task->_23, 0.0f);
        GXColor1u32(0xFFFFFF80);
        GXTexCoord2s16(0x100, 0x100);
        GXPosition3f32(x * task->_23 + task->_23, y * task->_23, 0.0f);
        GXColor1u32(0xFFFFFF80);
        GXTexCoord2s16(0x100, 0);
    }
}

// .text:0x0001F618 size:0x2E8
// 97.62%: same instructions, callee-saved registers assigned in another order (task in
// r26, the count in r27 in the target).
void fn_1_1F618(GameTask7730* task) {
    s32 i;
    u32 ids[1];
    f32 z;
    s32 j;
    u32 tlut;

    i = task->_1C;
    while (i-- != 0) {
        ids[0] = i % 4;
        GXSetNumTevStages(task->_22);
        GXSetNumTexGens(task->_22);
        for (j = 0; j < task->_22; j++) {
            GXSetTexCoordGen2(j, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            if (j != 0) {
                GXSetTevColorIn(j, GX_CC_CPREV, GX_CC_TEXC, GX_CC_RASA, GX_CC_ZERO);
                GXSetTevColorOp(j, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                GXSetTevAlphaIn(j, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
                GXSetTevAlphaOp(j, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            } else {
                GXSetTevColorIn(j, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
                GXSetTevColorOp(j, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
                GXSetTevAlphaIn(j, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
                GXSetTevAlphaOp(j, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
            }
            tlut = ids[j] & 0x7FFFFFFF;
            GXLoadTexObj(&lbl_1_bss_6EA4[ids[j]], j);
            if (ids[j] & 0x80000000) {
                GXLoadTlut(&lbl_1_bss_6E44[tlut], j);
            }
        }
        GXBegin(GX_QUADS, GX_VTXFMT0, 4);
        z = 0.5f - 0.0001f * i;
        GXPosition3f32(0.0f, 0.0f, z);
        GXColor1u32(0xFFFFFF80);
        GXTexCoord2s16(0, 0);
        GXPosition3f32(0.0f, 448.0f, z);
        GXColor1u32(0xFFFFFF80);
        GXTexCoord2s16(0, 0x100);
        GXPosition3f32(640.0f, 448.0f, z);
        GXColor1u32(0xFFFFFF80);
        GXTexCoord2s16(0x100, 0x100);
        GXPosition3f32(640.0f, 0.0f, z);
        GXColor1u32(0xFFFFFF80);
        GXTexCoord2s16(0x100, 0);
    }
}

// .text:0x0001F418 size:0x200
void fn_1_1F418(GameTask7730* task) {
    s32 i;
    s32 value;
    u8 sel;

    for (i = 0; i < 4; i++) {
        sel = task->_21;
        switch (i) {
        case 0:
            if (i == sel) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_20 == 0) {
                        task->_20 = 2;
                    }
                    task->_20--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_20++;
                    if (task->_20 == 2) {
                        task->_20 = 0;
                    }
                }
            }
            break;
        case 1:
            value = fn_80048EA8(0);
            if (i == task->_21) {
                if (lbl_803C77B8[0]._04 & 1) {
                    value--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    value++;
                }
                fn_80048E00(0, value);
            }
            break;
        case 2:
            value = fn_80048EA8(1);
            if (i == task->_21) {
                if (lbl_803C77B8[0]._04 & 1) {
                    value--;
                } else if (lbl_803C77B8[0]._04 & 2) {
                    value++;
                }
                fn_80048E00(1, value);
            }
            break;
        case 3:
            if (i == sel) {
                if (lbl_803C77B8[0]._04 & 1) {
                    if (task->_1C != 0) {
                        task->_1C--;
                    }
                } else if (lbl_803C77B8[0]._04 & 2) {
                    task->_1C++;
                }
            }
            break;
        }
    }
    if (lbl_803C77B8[0]._04 & 8) {
        if (task->_21 == 0) {
            task->_21 = 4;
        }
        task->_21--;
    } else if (lbl_803C77B8[0]._04 & 4) {
        task->_21++;
        if (task->_21 == 4) {
            task->_21 = 0;
        }
    }
}

// .text:0x0001F2D8 size:0x140
void fn_1_1F2D8(void) {
    fn_1_273D8(&lbl_1_bss_6D48);
    ((CameraTask7730*)lbl_803CC1B8)->_00 = fn_1_1F05C;
    ((CameraTask7730*)lbl_803CC1B8)->_2C = 0;
    ((CameraTask7730*)lbl_803CC1B8)->_28 = 0;
    ((CameraTask7730*)lbl_803CC1B8)->_14 = 2.0f;
    ((CameraTask7730*)lbl_803CC1B8)->_18 = 0.2f;
    ((CameraTask7730*)lbl_803CC1B8)->_1C = 0.2f;
    ((CameraTask7730*)lbl_803CC1B8)->_20 = 1.0f;
    ((CameraTask7730*)lbl_803CC1B8)->_24 = 1.0f;
    fn_1_1F23C(&lbl_1_bss_6BF4);
    ((CameraTask7730*)lbl_803CC1B8)->_10 = 0;
    lbl_1_bss_6BE4._0 = 0.0f;
    lbl_1_bss_6BE4._4.x = 0.0f;
    lbl_1_bss_6BE4._4.y = 0.0f;
    lbl_1_bss_6BE4._4.z = 0.0f;
}

// .text:0x0001F23C size:0x9C
void fn_1_1F23C(Actor7730* actor) {
    fn_800385F0(&lbl_1_bss_6BF4, ((CameraTask7730*)lbl_803CC1B8)->_14, ((CameraTask7730*)lbl_803CC1B8)->_18,
                ((CameraTask7730*)lbl_803CC1B8)->_1C, ((CameraTask7730*)lbl_803CC1B8)->_20);
    actor->_050 = -((CameraTask7730*)lbl_803CC1B8)->_24;
    actor->_0E8.y += 2.0f;
    ((CameraTask7730*)lbl_803CC1B8)->_2C &= ~2;
    ((CameraTask7730*)lbl_803CC1B8)->_2C |= 2;
}

// .text:0x0001F05C size:0x1E0
void fn_1_1F05C(void) {
    CameraTask7730* task;

    if (((CameraTask7730*)lbl_803CC1B8)->_2C & 1) {
        ((CameraTask7730*)lbl_803CC1B8)->_10 = fn_1_1E90C(((CameraTask7730*)lbl_803CC1B8)->_10, lbl_803C77B8[0]._00,
                                                          lbl_803C77B8[0]._02, lbl_803C77B8[0]._04);
    } else {
        fn_1_26D28(&lbl_1_bss_6D48, lbl_803C77B8[0]._00, lbl_803C77B8[0]._02, lbl_803C77B8[0]._04,
                   &lbl_803C77B8[0]._10);
    }
    if (lbl_803C77B8[0]._02 & 0x200) {
        task = lbl_803CC1B8;
        if (task->_2C & 1) {
            task->_00 = fn_1_24778;
        } else {
            task->_2C ^= 1;
        }
    } else if (lbl_803C77B8[0]._02 & 0x1000) {
        ((CameraTask7730*)lbl_803CC1B8)->_2C ^= 1;
    }
    fn_1_27330(&lbl_1_bss_6D48);
    task = lbl_803CC1B8;
    switch (task->_28) {
    case 0:
        if (task->_2C & 4) {
            task->_2C ^= 4;
            fn_1_1DD94();
        }
        fn_80037BAC(&lbl_1_bss_6BF4);
        break;
    }
    task = lbl_803CC1B8;
    if (task->_2C & 1) {
        fn_1_1E8C0(task->_10);
    }
    fn_1_1EFF4();
}

// .text:0x0001EFF4 size:0x68
void fn_1_1EFF4(void) {
    fn_1_272DC(&lbl_1_bss_6D48, 0);
    fn_1_AF4(20, 20, 1.0f);
    if (((CameraTask7730*)lbl_803CC1B8)->_2C & 2) {
        fn_1_1E5D0(&lbl_1_bss_6BF4);
    }
}

// .text:0x0001E90C size:0x6E8
s16 fn_1_1E90C(s16 sel, u16 held, u16 pressed, u16 repeat) {
    f32 a = ((CameraTask7730*)lbl_803CC1B8)->_14;
    f32 b = ((CameraTask7730*)lbl_803CC1B8)->_18;
    f32 c = ((CameraTask7730*)lbl_803CC1B8)->_1C;
    f32 d = ((CameraTask7730*)lbl_803CC1B8)->_20;
    f32 e = ((CameraTask7730*)lbl_803CC1B8)->_24;
    s16 next;
    s32 count;

    next = lbl_1_data_10668[((CameraTask7730*)lbl_803CC1B8)->_28](sel - 8, held, pressed, repeat) + 8;
    if (sel != next) {
        count = lbl_1_data_10670[((CameraTask7730*)lbl_803CC1B8)->_28] + 8;
        sel = (next + count) % count;
    } else if (pressed & 0x100) {
        switch (sel) {
        case 0:
            break;
        case 1:
            fn_1_1F23C(&lbl_1_bss_6BF4);
            break;
        case 2:
            ((CameraTask7730*)lbl_803CC1B8)->_2C ^= 4;
            break;        case 3:
            break;
        }
    } else if (repeat & 1) {
        switch (sel) {
        case 0:
            ((CameraTask7730*)lbl_803CC1B8)->_28 = (((CameraTask7730*)lbl_803CC1B8)->_28 + 7) % 8;
            break;
        case 3:
            a = fn_1_1DD48(held, 1, a, 0.0001f, 0.01f, 0.1f, 1.0f, 10.0f);
            break;
        case 4:
            b = fn_1_1DD48(held, 1, b, 0.0001f, 0.01f, 0.1f, 0.0f, 1.0f);
            break;
        case 5:
            c = fn_1_1DD48(held, 1, c, 0.0001f, 0.01f, 0.1f, 1.0f, 10.0f);
            break;
        case 7:
            e = fn_1_1DD48(held, 1, e, 0.0001f, 0.01f, 0.1f, 0.0f, 10.0f);
            break;
        }
    } else if (repeat & 2) {
        switch (sel) {
        case 0:
            ((CameraTask7730*)lbl_803CC1B8)->_28 = (((CameraTask7730*)lbl_803CC1B8)->_28 + 1) % 8;
            break;
        case 3:
            a = fn_1_1DD48(held, 0, a, 0.0001f, 0.01f, 0.1f, 1.0f, 10.0f);
            break;
        case 4:
            b = fn_1_1DD48(held, 0, b, 0.0001f, 0.01f, 0.1f, 0.0f, 1.0f);
            break;
        case 5:
            c = fn_1_1DD48(held, 0, c, 0.0001f, 0.01f, 0.1f, 1.0f, 10.0f);
            break;
        case 6:
            d = fn_1_1DD48(held, 0, d, 0.0001f, 0.01f, 0.1f, 0.0f, 10.0f);
            break;
        case 7:
            e = fn_1_1DD48(held, 0, e, 0.0001f, 0.01f, 0.1f, 0.0f, 10.0f);
            break;
        }
    } else if (repeat & 8) {
        if (sel < 8) {
            count = lbl_1_data_10670[((CameraTask7730*)lbl_803CC1B8)->_28];
            sel = (count + 8 + sel - 1) % (count + 8);
        }
    } else if (repeat & 4) {
        if (sel < 8) {
            sel = (sel + 1) % (lbl_1_data_10670[((CameraTask7730*)lbl_803CC1B8)->_28] + 8);
        }
    }
    ((CameraTask7730*)lbl_803CC1B8)->_14 = a;
    ((CameraTask7730*)lbl_803CC1B8)->_18 = b;
    ((CameraTask7730*)lbl_803CC1B8)->_1C = c;
    ((CameraTask7730*)lbl_803CC1B8)->_20 = d;
    ((CameraTask7730*)lbl_803CC1B8)->_24 = e;
    return sel;
}

// .text:0x0001E8C0 size:0x4C
void fn_1_1E8C0(s32 arg0) {
    lbl_1_data_1066C[((SprTask7730*)lbl_803CC1B8)->_28](arg0 - 8);
}

// .text:0x0001E5D0 size:0x2F0
void fn_1_1E5D0(Actor7730* actor) {
    Vec v[2];

    fn_1_F2C(4, 0, 0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
    PSMTXMultVec(actor->_058, &actor->_00C, &v[0]);
    PSMTXMultVec(actor->_058, &actor->_000, &v[1]);
    GXBegin(GX_LINES, GX_VTXFMT0, 2);
    GXPosition3f32(v[0].x, v[0].y, v[0].z);
    GXColor4u8(0xFF, 0x40, 0x40, 0xFF);
    GXPosition3f32(v[1].x, v[1].y, v[1].z);
    GXColor4u8(0x40, 0xFF, 0x40, 0xFF);
    GXBegin(GX_LINES, GX_VTXFMT0, 4);
    PSVECScale(&actor->_0E8, 1.0f, &v[0]);
    PSVECAdd(&v[0], &actor->_0F4, &v[1]);
    GXPosition3f32(v[0].x, v[0].y, v[0].z);
    GXColor4u8(0xFF, 0, 0, 0xFF);
    GXPosition3f32(v[1].x, v[1].y, v[1].z);
    GXColor4u8(0xFF, 0, 0, 0xFF);
    PSVECScale(&actor->_140, 1.0f, &v[1]);
    PSVECAdd(&v[0], &v[1], &v[1]);
    GXPosition3f32(v[0].x, v[0].y, v[0].z);
    GXColor4u8(0, 0, 0xFF, 0xFF);
    GXPosition3f32(v[1].x, v[1].y, v[1].z);
    GXColor4u8(0, 0, 0xFF, 0xFF);
    if (((CameraTask7730*)lbl_803CC1B8)->_28 == 0) {
        PSVECSubtract(&actor->_000, &actor->_00C, &v[0]);
        PSVECScale(&v[0], lbl_1_bss_6BE4._0, &v[0]);
        PSVECAdd(&actor->_00C, &v[0], &v[0]);
        PSMTXMultVec(actor->_058, &v[0], &v[0]);
        v[1].x = lbl_1_bss_6BE4._4.x;
        v[1].y = lbl_1_bss_6BE4._4.y;
        v[1].z = lbl_1_bss_6BE4._4.z;
        PSVECAdd(&v[0], &v[1], &v[1]);
        GXBegin(GX_LINES, GX_VTXFMT0, 2);
        GXPosition3f32(v[0].x, v[0].y, v[0].z);
        GXColor4u8(0xFF, 0, 0xFF, 0xFF);
        GXPosition3f32(v[1].x, v[1].y, v[1].z);
        GXColor4u8(0xFF, 0, 0xFF, 0xFF);
    }
}

// .text:0x0001E290 size:0x340
// 98.85%: in each inlined fn_1_1DD48 the target loads 0.01f before the field and forms
// lbl_1_bss_6BF4's address in r5, not r6.
s16 fn_1_1E290(s16 sel, u16 held, u16 pressed, u16 repeat) {
    if (sel < 0 || sel >= 3) {
        return sel;
    }
    {
        if (repeat & 1) {
            switch (sel) {
            case 0:
                lbl_1_bss_6BF4._140.x = fn_1_1DD48(held, 1, lbl_1_bss_6BF4._140.x, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            case 1:
                lbl_1_bss_6BF4._140.y = fn_1_1DD48(held, 1, lbl_1_bss_6BF4._140.y, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            case 2:
                lbl_1_bss_6BF4._140.z = fn_1_1DD48(held, 1, lbl_1_bss_6BF4._140.z, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            }
        } else if (repeat & 2) {
            switch (sel) {
            case 0:
                lbl_1_bss_6BF4._140.x = fn_1_1DD48(held, 0, lbl_1_bss_6BF4._140.x, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            case 1:
                lbl_1_bss_6BF4._140.y = fn_1_1DD48(held, 0, lbl_1_bss_6BF4._140.y, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            case 2:
                lbl_1_bss_6BF4._140.z = fn_1_1DD48(held, 0, lbl_1_bss_6BF4._140.z, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            }
        } else if (repeat & 8) {
            sel--;
        } else if (repeat & 4) {
            sel++;
        }
    }
    return sel;
}

// .text:0x0001E28C size:0x4
void fn_1_1E28C(void) {}

// .text:0x0001DE60 size:0x42C
// 99.03%: as in fn_1_1E290, each inlined fn_1_1DD48 loads 0.01f before the field in the
// target, which also takes lbl_1_bss_6BE4's address into r5.
s16 fn_1_1DE60(s16 sel, u16 held, u16 pressed, u16 repeat) {
    if (sel < 0 || sel >= 4) {
        return sel;
    }
    {
        if (repeat & 1) {
            switch (sel) {
            case 0:
                lbl_1_bss_6BE4._0 = fn_1_1DD48(held, 1, lbl_1_bss_6BE4._0, 0.0001f, 0.01f, 0.1f, 0.0f, 1.0f);
                break;
            case 1:
                lbl_1_bss_6BE4._4.x = fn_1_1DD48(held, 1, lbl_1_bss_6BE4._4.x, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            case 2:
                lbl_1_bss_6BE4._4.y = fn_1_1DD48(held, 1, lbl_1_bss_6BE4._4.y, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            case 3:
                lbl_1_bss_6BE4._4.z = fn_1_1DD48(held, 1, lbl_1_bss_6BE4._4.z, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            }
        } else if (repeat & 2) {
            switch (sel) {
            case 0:
                lbl_1_bss_6BE4._0 = fn_1_1DD48(held, 0, lbl_1_bss_6BE4._0, 0.0001f, 0.01f, 0.1f, 0.0f, 1.0f);
                break;
            case 1:
                lbl_1_bss_6BE4._4.x = fn_1_1DD48(held, 0, lbl_1_bss_6BE4._4.x, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            case 2:
                lbl_1_bss_6BE4._4.y = fn_1_1DD48(held, 0, lbl_1_bss_6BE4._4.y, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            case 3:
                lbl_1_bss_6BE4._4.z = fn_1_1DD48(held, 0, lbl_1_bss_6BE4._4.z, 0.0001f, 0.01f, 0.1f, -10.0f, 10.0f);
                break;
            }
        } else if (repeat & 8) {
            sel--;
        } else if (repeat & 4) {
            sel++;
        }
    }
    return sel;
}

// .text:0x0001DE5C size:0x4
void fn_1_1DE5C(s16 arg0) {}

// .text:0x0001DE50 size:0xC
f32 fn_1_1DE50(void) { return lbl_1_bss_6BE4._0; }

// .text:0x0001DE40 size:0x10
f32 fn_1_1DE40(void) { return lbl_1_bss_6BE4._4.x; }

// .text:0x0001DE30 size:0x10
f32 fn_1_1DE30(void) { return lbl_1_bss_6BE4._4.y; }

// .text:0x0001DE20 size:0x10
f32 fn_1_1DE20(void) { return lbl_1_bss_6BE4._4.z; }

// .text:0x0001DE14 size:0xC
void fn_1_1DE14(f32 v) { lbl_1_bss_6BE4._0 = v; }

// .text:0x0001DE04 size:0x10
void fn_1_1DE04(f32 v) { lbl_1_bss_6BE4._4.x = v; }

// .text:0x0001DDF4 size:0x10
void fn_1_1DDF4(f32 v) { lbl_1_bss_6BE4._4.y = v; }

// .text:0x0001DDE4 size:0x10
void fn_1_1DDE4(f32 v) { lbl_1_bss_6BE4._4.z = v; }

// .text:0x0001DD94 size:0x50
void fn_1_1DD94(void) {
    Vec v;

    v.x = lbl_1_bss_6BE4._4.x;
    v.y = lbl_1_bss_6BE4._4.y;
    v.z = lbl_1_bss_6BE4._4.z;
    fn_80037B18(&lbl_1_bss_6BF4, &v, lbl_1_bss_6BE4._0);
}

// .text:0x0001DD48 size:0x4C
f32 fn_1_1DD48(u16 buttons, s32 negate, f32 value, f32 step, f32 normal, f32 fast, f32 min, f32 max) {
    f32 delta = normal;

    if (buttons & 0x40) {
        delta = step;
    } else if (buttons & 0x20) {
        delta = fast;
    }
    if (negate) {
        delta = -delta;
    }
    value += delta;
    if (value < min) {
        value = min;
    }
    if (value > max) {
        value = max;
    }
    return value;
}

// .text:0x0001DCE4 size:0x64
void fn_1_1DCE4(void) {
    SprTask7730* task = lbl_803CC1B8;

    task->_14 = ARAMTransfer(lbl_1_data_10674, 0, 0, 0);
    ((SprTask7730*)lbl_803CC1B8)->_00 = fn_1_1DA54;
}

// .text:0x0001DA54 size:0x290
void fn_1_1DA54(void) {
    AnimTask7730* task = lbl_803CC1B8;
    u32 size;

    if (lbl_803C6CF8._715 == 1) {
        task->_18 = task->_14 + *(u32*)(task->_14 + 0x14);
        convertTextureHeader(task->_18);
        task->_28 = 2;
        task->_1C = 3;
        task->_1E = 0;
        task->_22 = 3;
        task->_20 = 3;
        task->_24 = 0;
        task->_26 = 0;
        task->_2C = _OSAllocFromHeap(32, 32);
        memcpy(task->_2C, task->_18 + 0x44, 32);
        if (task->_2C->tlut != NULL) {
            switch (task->_2C->tlutFormat) {
            case GX_TL_IA8:
            case GX_TL_RGB565:
            case GX_TL_RGB5A3:
                size = task->_2C->tlutEntries * 2;
                task->_2C->tlut = _OSAllocFromHeap(32, size);
                memcpy(task->_2C->tlut, ((Tex7730*)(task->_18 + 0x44))->tlut, size);
                break;
            }
            DCStoreRangeNoSync(task->_2C->tlut, size);
            switch (task->_2C->format) {
            case GX_TF_C4:
                size = ((task->_2C->width + 7) / 8 * 8) * ((task->_2C->height + 7) / 8 * 8);
                break;
            case GX_TF_C8:
                size = ((task->_2C->width + 7) / 8 * 8) * ((task->_2C->height + 3) / 4 * 4);
                break;
            default:
                fn_800AD038(lbl_80366158._08);
                ((AnimTask7730*)lbl_803CC1B8)->_0C->_10 = 1;
                fn_800B0A14_removeQueue();
                return;
            }
        } else {
            switch (task->_2C->format) {
            case GX_TF_CMPR:
                size = ((task->_2C->width + 7) / 8 * 8) * ((task->_2C->height + 7) / 8 * 8);
                break;
            default:
                fn_800AD038(lbl_80366158._08);
                ((AnimTask7730*)lbl_803CC1B8)->_0C->_10 = 1;
                fn_800B0A14_removeQueue();
                return;
            }
        }
        task->_2C->image = _OSAllocFromHeap(32, size);
        memcpy(task->_2C->image, ((Tex7730*)(task->_18 + 0x44))->image, size);
        DCStoreRangeNoSync(task->_2C->image, size);
        PPCSync();
        ((AnimTask7730*)lbl_803CC1B8)->_00 = fn_1_1D944;
    }
}

// .text:0x0001D944 size:0x110
void fn_1_1D944(void) {
    AnimTask7730* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._02 & 0x200) {
        fn_800AD038(lbl_80366158._08);
        ((AnimTask7730*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        return;
    }
    if (--task->_20 == 0) {
        task->_20 = task->_22;
        task->_1E = (task->_1E + 1) % task->_1C;
    }
    lbl_1_data_107E4[lbl_803CBBC0]._0C = task->_18 + (task->_28 + task->_1E) * 32 + 4;
    lbl_1_data_107E4[lbl_803CBBC0]._14 = task->_24;
    lbl_1_data_107E4[lbl_803CBBC0]._16 = task->_26;
    lbl_1_data_107E4[lbl_803CBBC0]._18 = 1;
    lbl_1_data_107E4[lbl_803CBBC0]._10 = lbl_1_data_107C4;
    lbl_1_data_107E4[lbl_803CBBC0]._08 = task->_2C;
    fn_800A7D4C(0, &lbl_1_data_107E4[lbl_803CBBC0]);
}

// .text:0x0001D694 size:0x2B0
void fn_1_1D694(DrawEntry7730* entry) {
    Mtx proj; // a 3x4 matrix in the original (its frame), though C_MTXOrtho writes 4x4
    Mtx m;

    if (entry->_18 != 0) {
        fn_1_1D590(entry->_0C, entry->_08, entry->_10, 32, 64);
    }
    C_MTXOrtho(proj, 0.0f, 448.0f, 0.0f, 640.0f, 0.0f, 1.0f);
    PSMTXIdentity(m);
    GXSetProjection(proj, GX_ORTHOGRAPHIC);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    gOz_GXSetTexture(0, 0, 0);
    SetDisplayStateTexture(entry->_08, 0, 0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(0.0f, 0.0f, -0.5f);
    GXColor1u32(0xFFFFFFFF);
    GXTexCoord2s16(0, 0);
    GXPosition3f32(0.0f, entry->_08->height, -0.5f);
    GXColor1u32(0xFFFFFFFF);
    GXTexCoord2s16(0, 1);
    GXPosition3f32(entry->_08->width, entry->_08->height, -0.5f);
    GXColor1u32(0xFFFFFFFF);
    GXTexCoord2s16(1, 1);
    GXPosition3f32(entry->_08->width, 0.0f, -0.5f);
    GXColor1u32(0xFFFFFFFF);
    GXTexCoord2s16(1, 0);
}

// .text:0x0001D590 size:0x104
void fn_1_1D590(void* src, Tex7730* tex, u8* map, s32 tileW, s32 tileH) {
    s32 y;
    s32 x;
    s32 rows;
    s32 cols;

    memset(tex->image, 0, tex->width * tex->height);
    rows = tex->height / tileH;
    cols = tex->width / tileW;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            if (x & lbl_803CBBC0) {
                fn_80023F0C(src, tex, tileW * (map[y * cols + x] % cols), tileH * (map[y * cols + x] / cols), tileW,
                            tileH, x * tileW, y * tileH);
            }
        }
    }
    DCStoreRange(tex->image, tex->width * tex->height);
}
