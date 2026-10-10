#include "challenge/rep_0138.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "string.h"
#include "stdarg.h"
#include "C3/control.h"

extern void fn_80048C1C(void);
extern void fn_80048C28(void);
extern void fn_80048D4C(void);
extern void LITXForm(void* light, Mtx view);
extern void SetFog(GXFogType type, f32 startZ, f32 endZ, f32 nearZ, f32 farZ, GXColor color);
extern void SetFogNoneAgain(void);
extern void fn_800B806C(s32 arg0, f32 top, f32 bottom, f32 left, f32 right, f32 nearZ, f32 farZ, f32 arg7);
extern void fn_80048C14(s32 arg0);
extern void fn_80048E00(s32 arg0, s32 arg1);
extern s32 fn_80048EA8(s32 arg0);
extern void fn_800B49E4(void* layout);
extern void fn_800BCE38(void* geo);
extern void fn_800BD190(void* geo, void* tex);
extern void convertTextureHeader(void* tex);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void fn_800AD038(void* arg0);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800B472C(void* arg0);
extern void fn_800A7D4C(s32 arg0, void* arg1);
extern void fn_1_196C(void);
extern void* ARAMTransfer(void* entry, s32 arg1, s32 arg2, u32 aram);
extern void fn_800B9AA8(void* light);
extern void LITAlloc(void** light);
extern void LITInitAttn(void* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern void LITInitColor(void* light, GXColor color);
extern void LITInitDir(void* light, f32 nx, f32 ny, f32 nz);
extern void LITInitPos(void* light, f32 x, f32 y, f32 z);
extern void makeLookAtMatrix(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);
extern void fn_80011640(Mtx src, Mtx dst);
extern void fn_800B9950(s32 arg0, f32 arg1, f32 arg2);
extern s32 fn_800B7D3C(s32 arg0, Vec* corners, Mtx mtx);
extern void DOVARender(struct DObj0138* obj, MtxPtr camera, u8 numLights, va_list* list);
extern void fn_800B996C(void (*callback)(GXTevStageID, GXIndTexStageID, GXIndTexMtxID, GXTexCoordID, GXTexMapID));
extern u8 lbl_803CBBC0;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

typedef struct Task0138 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct Task0138* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ void* _14;
    /* 0x18 */ s16 _18;
} Task0138;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern Task0138* lbl_803CC1B8;

typedef struct VtxArray0138 {
    /* 0x0 */ s16* _0;
    /* 0x4 */ u8 _4[0x6 - 0x4];
    /* 0x6 */ u8 _6; // low nibble: fraction bits, high nibble: component type
    /* 0x7 */ u8 _7; // components per element
} VtxArray0138;

typedef struct DispEntry0138 {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1[0x4 - 0x1];
    /* 0x4 */ u32 _4; // vertex descriptor, two bits per attribute
    /* 0x8 */ u8* _8; // display list
    /* 0xC */ u32 _C; // display list size
} DispEntry0138; // size: 0x10

typedef struct Disp0138 {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ DispEntry0138* _4;
    /* 0x8 */ u16 _8;
} Disp0138;

typedef struct DObj0138 {
    /* 0x00 */ VtxArray0138* _00;
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ VtxArray0138* _0C;
    /* 0x10 */ Disp0138* _10;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ Mtx _18;
    /* 0x48 */ u8 _48[0x54 - 0x48];
    /* 0x54 */ f32 _54;
    /* 0x58 */ f32 _58;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ f32 _64;
    /* 0x68 */ f32 _68;
} DObj0138;

typedef struct GeoEntry0138 {
    /* 0x0 */ DObj0138* _0;
    /* 0x4 */ u32 _4;
} GeoEntry0138;

typedef struct Geo0138 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ GeoEntry0138* _10;
} Geo0138;

typedef struct LayoutEntry0138 {
    /* 0x00 */ Control* _00;
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16[0x1A - 0x16];
    /* 0x1A */ u16 _1A;
} LayoutEntry0138; // size: 0x1C

typedef struct Layout0138 {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _6;
    /* 0x08 */ u8 _08[0x10 - 0x8];
    /* 0x10 */ Geo0138* _10;
    /* 0x14 */ u8 _14[0x20 - 0x14];
    /* 0x20 */ LayoutEntry0138 _20[1];
} Layout0138;

typedef struct File0138 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ u32 _04;
    /* 0x08 */ u32 _08;
    /* 0x0C */ u32 _0C;
    /* 0x10 */ u32 _10;
    /* 0x14 */ u32 _14;
} File0138;

typedef struct Draw0138 {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ void (*_04)(void* arg0);
    /* 0x08 */ Mtx _08;
    /* 0x38 */ Mtx _38;
    /* 0x68 */ Layout0138* _68;
} Draw0138; // size: 0x6C

extern struct {
    /* 0x000 */ Mtx _000;
    /* 0x030 */ u16 _030;
    /* 0x032 */ u16 _032;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ Vec _03C;
    /* 0x048 */ Vec _048;
    /* 0x054 */ f32 _054;
    /* 0x058 */ void* _058;
    /* 0x05C */ Draw0138 _05C[4];
    /* 0x20C */ u8 _20C[0x21C - 0x20C];
    /* 0x21C */ void* _21C;
    /* 0x220 */ u8 _220[0x224 - 0x220];
    /* 0x224 */ u32* _224;
    /* 0x228 */ s16 _228;
    /* 0x22A */ s16 _22A;
    /* 0x22C */ s16 _22C;
    /* 0x22E */ s16 _22E;
    /* 0x230 */ s8 _230;
    /* 0x231 */ s8 _231;
    /* 0x232 */ u8 _232;
    /* 0x233 */ s8 _233;
    /* 0x234 */ u8 _234;
    /* 0x235 */ s8 _235;
    /* 0x236 */ u8 _236[0x238 - 0x236];
    /* 0x238 */ s8 _238;
    /* 0x239 */ u8 _239;
    /* 0x23A */ u16 _23A;
    /* 0x23C */ s8 _23C;
} lbl_1_common_bss_472B4;

extern struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
} lbl_1_data_200;

typedef struct Fog0138 {
    /* 0x0 */ GXColor color;
    /* 0x4 */ f32 start;
    /* 0x8 */ f32 end;
} Fog0138;

typedef struct Callback0138 {
    /* 0x0 */ s32 _0;
    /* 0x4 */ void (*_4)(void);
} Callback0138;

static Fog0138 lbl_1_data_2A8[15][8] = {
    {
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0x42, 0x20, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x00, 0x70, 0x01, 0x0A }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 5.87809954e-39f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 5.87809954e-39f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 7.70371978e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0x42, 0x28, 0x00, 0x00 }, 1.5f, 1.5f },
        { { 0x0F, 0xA0, 0x01, 0xC0 }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.26224486e-29f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 1.02555288e-29f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 5.77778983e-34f },
    },
    {
        { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f },
        { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f },
        { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f },
        { { 0x42, 0x28, 0x00, 0x00 }, 1.5f, 1.5f },
        { { 0x0F, 0xA0, 0x01, 0xC0 }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.26224486e-29f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 1.02555288e-29f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 7.37270057e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0x42, 0x20, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x0B, 0x70, 0x01, 0xC0 }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 3.69791715e-32f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 3.69791715e-32f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 6.74075481e-34f },
    },
    {
        { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f },
        { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f },
        { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f },
        { { 0x42, 0x20, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x0B, 0x70, 0x01, 0xC0 }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 3.69791715e-32f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 3.69791715e-32f },
        { { 0x00, 0x00, 0x00, 0x00 }, 2.35095283e-38f, 6.74075481e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f },
        { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f },
        { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f },
        { { 0x42, 0x48, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x0B, 0x80, 0x01, 0xC0 }, 50.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.17555713e-38f, 50.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 4.93064397e-32f },
        { { 0x39, 0x2B, 0x92, 0xA6 }, 0.0f, 6.01853108e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0x42, 0x20, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x00, 0x70, 0x01, 0x0A }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 5.87809954e-39f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 5.87809954e-39f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 7.70371978e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0x42, 0x20, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x00, 0x70, 0x01, 0x0A }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 5.87809954e-39f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 5.87809954e-39f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 7.70371978e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0x42, 0x28, 0x00, 0x00 }, 1.5f, 1.5f },
        { { 0x0F, 0xA0, 0x01, 0xC0 }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.26224486e-29f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 1.02555288e-29f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 5.77778983e-34f },
    },
    {
        { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f },
        { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f },
        { { 0xFF, 0xDC, 0x96, 0x00 }, 0.0f, 512.0f },
        { { 0x42, 0x28, 0x00, 0x00 }, 1.5f, 1.5f },
        { { 0x0F, 0xA0, 0x01, 0xC0 }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.26224486e-29f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 1.02555288e-29f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 7.37270057e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0x42, 0x20, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x0B, 0x70, 0x01, 0xC0 }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 3.69791715e-32f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 3.69791715e-32f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 6.74075481e-34f },
    },
    {
        { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f },
        { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f },
        { { 0x96, 0xAA, 0xDC, 0x02 }, 80.0f, 300.0f },
        { { 0x42, 0x20, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x0B, 0x70, 0x01, 0xC0 }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 3.69791715e-32f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 3.69791715e-32f },
        { { 0x00, 0x00, 0x00, 0x00 }, 2.35095283e-38f, 6.74075481e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f },
        { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f },
        { { 0xAA, 0xBE, 0xD2, 0x07 }, 0.0f, 380.0f },
        { { 0x42, 0x48, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x0B, 0x80, 0x01, 0xC0 }, 50.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.17555713e-38f, 50.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 4.93064397e-32f },
        { { 0x39, 0x2B, 0x92, 0xA6 }, 0.0f, 6.01853108e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0x42, 0x20, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x00, 0x70, 0x01, 0x0A }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 5.87809954e-39f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 5.87809954e-39f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 7.70371978e-34f },
    },
    {
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0xAA, 0xBE, 0xD2, 0x00 }, 80.0f, 450.0f },
        { { 0x42, 0x20, 0x00, 0x00 }, 1.0f, 1.0f },
        { { 0x00, 0x70, 0x01, 0x0A }, 80.0f, 1.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 5.87809954e-39f, 80.0f },
        { { 0x3F, 0x80, 0x00, 0x00 }, 1.0f, 5.87809954e-39f },
        { { 0x37, 0xF4, 0x03, 0xC5 }, 0.0f, 7.70371978e-34f },
    },
};
static void* lbl_1_data_848[3] = { 0 };
static s32 lbl_1_data_854 = 0x40;
static GXColor lbl_1_data_858 = { 0xFF, 0x80, 0x80, 0x00 };
static u8 lbl_1_data_85C = 1;
static void (*lbl_1_data_860[7])(void) = { fn_1_85A8, fn_1_8368, fn_1_7FF8, fn_1_85A8, NULL, fn_1_7EF8, NULL };
static f32 lbl_1_data_87C[4] = { 0.0f, 1.0f, 0.0f, 0.0f };
static Callback0138 lbl_1_data_88C[2] = { { 0, fn_1_78E4 }, { 0, fn_1_78E4 } };
static s32 lbl_1_data_89C[2] = { 0, 0xFFFFFF0A };
static Callback0138 lbl_1_data_8A4[2] = { { 0, fn_1_786C }, { 0, fn_1_786C } };
static Callback0138 lbl_1_data_8B4[2] = { { 0, fn_1_7848 }, { 0, fn_1_7848 } };
static GXCullMode lbl_1_data_8C4 = GX_CULL_BACK;
static u8 lbl_1_data_8C8 = 1;
static s32 lbl_1_data_8CC = 7;
static u32 lbl_1_data_8D0[21 * 4] = {
    0x0000040B, 0x40168A6C, 0x06CFD000, 0x000C69A8,
    0x0000040B, 0x401331E0, 0x06DC4000, 0x000B67C4,
    0x0000040B, 0x4011924C, 0x06E7A800, 0x000A5764,
    0x0000040B, 0x400FBAE0, 0x06F20000, 0x000BE038,
    0x0000040B, 0x400E5AC0, 0x06FDE800, 0x000B4FB8,
    0x0000040B, 0x40131200, 0x07093800, 0x000A317C,
    0x0000040B, 0x4011B660, 0x07137000, 0x000D0294,
    0x0000040B, 0x4011B660, 0x07137000, 0x000D0294,
    0x0000040B, 0x4011B660, 0x07137000, 0x000D0294,
    0x0000040B, 0x40141C60, 0x07207800, 0x000CE904,
    0x0000040B, 0x4013CA40, 0x072D6800, 0x000CA560,
    0x0000040B, 0x40141C60, 0x07207800, 0x000CE904,
    0x0000040B, 0x4016C138, 0x073A1000, 0x000ED41C,
    0x0000040B, 0x401157B8, 0x0748E800, 0x000CA83C,
    0x0000040B, 0x4016C138, 0x073A1000, 0x000ED41C,
    0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510,
    0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510,
    0x0000040B, 0x400EB1C0, 0x07559800, 0x000A3510,
    0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390,
    0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390,
    0x0000040B, 0x400D04E0, 0x075FD000, 0x00087390,
};
static u8 lbl_1_data_A20 = 3;
static f32 lbl_1_data_A24[4] = { 0.0625f, 0.25f, 0.5f, 1.0f };
static f32 lbl_1_data_A34 = 2.0f;
static GXTexFilter lbl_1_data_A38 = GX_LIN_MIP_LIN;
static Vec lbl_1_data_A3C = { 0.0f, 0.0f, -1.0f };
static Vec lbl_1_data_A48[3] = { { 0.0f, 0.0f, -1.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
static u8 lbl_1_data_A6C = 1;
static u8 lbl_1_data_A6D = 1;
static f32 lbl_1_data_A70 = 1.0f;
static f32 lbl_1_data_A74[2][3] = { { 0.5f, 0.0f, 0.0f }, { 0.0f, 0.5f, 0.0f } };

static u16 lbl_1_bss_520[0x1544] ATTRIBUTE_ALIGN(32);
static GXTexObj lbl_1_bss_4E4;
static Fog0138* lbl_1_bss_4E0;
static u8 lbl_1_bss_2E0[0x200];
static u8 lbl_1_bss_E0[0x200];
static u8 lbl_1_bss_DC;
static GXIndTexScale lbl_1_bss_D8;
static GXIndTexScale lbl_1_bss_D4;
static u8 lbl_1_bss_D1;
static u8 lbl_1_bss_D0;
static u8 lbl_1_bss_C8[8];
static s32 lbl_1_bss_C4;
static u8 lbl_1_bss_C2;
static u8 lbl_1_bss_C1;
static u8 lbl_1_bss_C0;

// .text:0x37D0 size:0x7C
void fn_1_85A8(void) {
    if (lbl_803C77B8[0]._04 & 1) {
        if (--lbl_1_common_bss_472B4._22E < -1) {
            lbl_1_common_bss_472B4._22E = lbl_1_common_bss_472B4._22A - 1;
        }
    } else if (lbl_803C77B8[0]._04 & 2) {
        if (++lbl_1_common_bss_472B4._22E >= lbl_1_common_bss_472B4._22A) {
            lbl_1_common_bss_472B4._22E = -1;
        }
    }
}

// .text:0x3590 size:0x240
void fn_1_8368(void) {
    if (lbl_803C77B8[0]._04 & 1) {
        if (--lbl_1_common_bss_472B4._22E < -1) {
            lbl_1_common_bss_472B4._22E = lbl_1_common_bss_472B4._228 - 1;
        }
    } else if (lbl_803C77B8[0]._04 & 2) {
        if (++lbl_1_common_bss_472B4._22E >= lbl_1_common_bss_472B4._228) {
            lbl_1_common_bss_472B4._22E = -1;
        }
    } else if (lbl_803C77B8[0]._02 & 0x400) {
        lbl_1_common_bss_472B4._239 ^= 1;
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        lbl_1_common_bss_472B4._238 ^= 1;
    }
    lbl_1_data_200._00 += lbl_803C77B8[0]._10 / 128.0f;
    lbl_1_data_200._08 += lbl_803C77B8[0]._11 / 128.0f;
    lbl_1_data_200._0C += lbl_803C77B8[0]._12 / 128.0f;
    lbl_1_data_200._14 += lbl_803C77B8[0]._13 / 128.0f;
    if (!(lbl_803C77B8[0]._00 & 0x100)) {
        lbl_1_data_200._04 -= lbl_803C77B8[0]._15 / 1024.0f;
        lbl_1_data_200._04 += lbl_803C77B8[0]._14 / 1024.0f;
    } else {
        lbl_1_data_200._10 -= lbl_803C77B8[0]._15 / 1024.0f;
        lbl_1_data_200._10 += lbl_803C77B8[0]._14 / 1024.0f;
    }
}

// .text:0x3220 size:0x370
void fn_1_7FF8(void) {
    switch (lbl_803C77B8[0]._04) {
    case 8:
        if (--lbl_1_common_bss_472B4._23C < 0) {
            lbl_1_common_bss_472B4._23C = 5;
        }
        break;
    case 4:
        if (++lbl_1_common_bss_472B4._23C >= 6) {
            lbl_1_common_bss_472B4._23C = 0;
        }
        break;
    case 1:
        switch (lbl_1_common_bss_472B4._23C) {
        case 0:
            switch (--lbl_1_bss_4E0->color.a) {
            case 0xFF:
                lbl_1_bss_4E0->color.a = 7;
                break;
            case 3:
                lbl_1_bss_4E0->color.a = 2;
                break;
            case 1:
                lbl_1_bss_4E0->color.a = 0;
                break;
            }
            break;
        case 1:
            lbl_1_bss_4E0->color.r--;
            break;
        case 2:
            lbl_1_bss_4E0->color.g--;
            break;
        case 3:
            lbl_1_bss_4E0->color.b--;
            break;
        case 4:
            if ((lbl_1_bss_4E0->start -= 1.0f) < 0.0f) {
                lbl_1_bss_4E0->start = 0.0f;
            }
            break;
        case 5:
            if ((lbl_1_bss_4E0->end -= 1.0f) < 0.0f) {
                lbl_1_bss_4E0->end = 0.0f;
            }
            break;
        }
        break;
    case 2:
        switch (lbl_1_common_bss_472B4._23C) {
        case 0:
            switch (++lbl_1_bss_4E0->color.a) {
            case 1:
                lbl_1_bss_4E0->color.a = 2;
                break;
            case 3:
                lbl_1_bss_4E0->color.a = 4;
                break;
            case 8:
                lbl_1_bss_4E0->color.a = 0;
                break;
            }
            break;
        case 1:
            lbl_1_bss_4E0->color.r++;
            break;
        case 2:
            lbl_1_bss_4E0->color.g++;
            break;
        case 3:
            lbl_1_bss_4E0->color.b++;
            break;
        case 4:
            if ((lbl_1_bss_4E0->start += 1.0f) > 512.0f) {
                lbl_1_bss_4E0->start = 512.0f;
            }
            break;
        case 5:
            if ((lbl_1_bss_4E0->end += 1.0f) > 512.0f) {
                lbl_1_bss_4E0->end = 512.0f;
            }
            break;
        }
        break;
    }
}

// .text:0x3120 size:0x100
void fn_1_7EF8(void) {
    switch (lbl_803C77B8[0]._04) {
    case 4:
    case 8:
        lbl_1_bss_C2 = !lbl_1_bss_C2;
        break;
    case 1:
        fn_80048E00(lbl_1_bss_C2, fn_80048EA8(lbl_1_bss_C2) - 1);
        break;
    case 2:
        fn_80048E00(lbl_1_bss_C2, fn_80048EA8(lbl_1_bss_C2) + 1);
        break;
    case 0x100:
        lbl_1_data_85C = !lbl_1_data_85C;
        if (lbl_1_data_85C) {
            fn_80048C14(0x3F);
        } else {
            fn_80048C14(0);
        }
        break;
    }
}

// .text:0x302C size:0xF4
void fn_1_7E04(f32 zoom) {
    Mtx44 proj;
    f32 scale = 1.0f / zoom;

    C_MTXFrustum(proj, -0.175f * scale, 0.175f * scale, 0.25f * scale, -0.25f * scale, 1.0f, 512.0f);
    GXSetProjection(proj, GX_PERSPECTIVE);
    fn_800B806C(0, -240.0f * scale, 240.0f * scale, -320.0f * scale, 320.0f * scale, -512.0f, -1.0f, 1280.0f);
}

// .text:0x2B88 size:0x4A4
// Only the inlined fn_1_7E04 differs: the common block and 1.0f's addresses
// come in r4 and r3 in the target, swapped here.
void fn_1_7960(void) {
    Vec rot;
    Vec target = { 0.0f, 0.0f, 100.0f };
    f32 cosY;
    f32 sinY;
    Mtx rotX;
    Mtx rotY;
    Mtx rotXY;

    lbl_1_common_bss_472B4._030 -= lbl_803C77B8[0]._13 * 2;
    lbl_1_common_bss_472B4._032 += lbl_803C77B8[0]._12 * 2;
    lbl_1_common_bss_472B4._034 = lbl_803C77B8[0]._10 / -128.0f;
    lbl_1_common_bss_472B4._038 = lbl_803C77B8[0]._11 / 128.0f;
    if (lbl_803C77B8[0]._00 & 0x10) {
        lbl_1_common_bss_472B4._054 -= lbl_803C77B8[0]._14 / 4096.0f;
        lbl_1_common_bss_472B4._054 += lbl_803C77B8[0]._15 / 4096.0f;
    } else {
        lbl_1_common_bss_472B4._048.y -= lbl_803C77B8[0]._15 / 1024.0f;
        lbl_1_common_bss_472B4._048.y += lbl_803C77B8[0]._14 / 1024.0f;
    }
    rot.x = lbl_1_common_bss_472B4._030;
    rot.y = lbl_1_common_bss_472B4._032;
    rot.z = 0.0f;
    PSVECScale(&rot, 0.0000958738f, &rot);
    PSMTXRotRad(rotX, 'X', rot.x);
    PSMTXRotRad(rotY, 'Y', rot.y);
    sinY = rotY[0][2];
    cosY = rotY[0][0];
    PSMTXConcat(rotY, rotX, rotXY);
    PSMTXMultVec(rotXY, &target, &lbl_1_common_bss_472B4._03C);
    lbl_1_common_bss_472B4._048.x += lbl_1_common_bss_472B4._038 * sinY - lbl_1_common_bss_472B4._034 * cosY;
    lbl_1_common_bss_472B4._048.z += lbl_1_common_bss_472B4._038 * cosY + lbl_1_common_bss_472B4._034 * sinY;
    lbl_1_common_bss_472B4._03C.x += lbl_1_common_bss_472B4._048.x;
    lbl_1_common_bss_472B4._03C.y += lbl_1_common_bss_472B4._048.y;
    lbl_1_common_bss_472B4._03C.z += lbl_1_common_bss_472B4._048.z;
    makeLookAtMatrix(lbl_1_common_bss_472B4._000, &lbl_1_common_bss_472B4._048, (Vec*)lbl_1_data_87C, &lbl_1_common_bss_472B4._03C);
    fn_1_7E04(lbl_1_common_bss_472B4._054);
    fn_1_54E0(lbl_1_common_bss_472B4._000);
    fn_80011640(lbl_1_common_bss_472B4._000, lbl_1_common_bss_472B4._000);
    if (lbl_1_bss_C0 != 0) {
        fn_800B9950(3, (0xFFFF - lbl_1_common_bss_472B4._032) / 32768.0f, (s16)lbl_1_common_bss_472B4._030 / 32768.0f);
    } else {
        fn_800B9950(3, 0.0f, 0.0f);
    }
}

// .text:0x2B0C size:0x7C
void fn_1_78E4(void) {
    GXSetCopyClear(lbl_1_data_858, 0xFFFFFF);
    if (lbl_1_bss_C4 != 0) {
        GXSetCullMode(GX_CULL_NONE);
    } else {
        GXSetCullMode(GX_CULL_BACK);
    }
    SetFogNoneAgain();
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
}

// .text:0x2A94 size:0x78
void fn_1_786C(void) {
    fn_80048D4C();
    GXSetCopyClear(lbl_1_data_858, 0xFFFFFF);
    SetFog(lbl_1_bss_4E0->color.a, lbl_1_bss_4E0->start, lbl_1_bss_4E0->end, 1.0f, 512.0f, lbl_1_bss_4E0->color);
}

// .text:0x2A70 size:0x24
void fn_1_7848(void) {
    fn_80048C28();
    fn_80048C1C();
}

// .text:0x2A14 size:0x5C
void fn_1_77EC(void* arg0) {
    GXSetCullMode(lbl_1_data_8C4);
    fn_1_73B8(arg0, 3, lbl_1_data_848[0], lbl_1_data_848[1], lbl_1_data_848[2]);
}

// .text:0x25E0 size:0x434
// Registers differ (draw, count and the loop pointers take other saved registers);
// declaration-order batches and a permuter session found no match.
void fn_1_73B8(void* arg0, u8 count, ...) {
    u16 idx;
    Draw0138* draw = arg0;
    MtxPtr world;
    Layout0138* layout;
    DObj0138* obj;
    Geo0138* geo;
    MtxPtr camera;
    s32 i;
    s32 end;

    Mtx mtx;
    Vec corners[8];
    va_list args;

    layout = draw->_68;
    geo = layout->_10;
    if (lbl_1_data_8C8 == 1) {
        memset(lbl_1_bss_2E0, 0, sizeof(lbl_1_bss_2E0));
        lbl_1_data_8C8 = 0;
    } else if (lbl_1_data_8C8 == 2) {
        memset(lbl_1_bss_2E0, 1, sizeof(lbl_1_bss_2E0));
        lbl_1_data_8C8 = 0;
    }
    end = layout->_6;
    lbl_1_common_bss_472B4._22C = 0;
    if (lbl_1_common_bss_472B4._22E < 0) {
        i = 0;
    } else {
        i = lbl_1_common_bss_472B4._22E;
        end = lbl_1_common_bss_472B4._22E + 1;
    }
    world = draw->_08;
    camera = draw->_38;
    for (; i < end; i++) {
        if (lbl_1_bss_2E0[i] == 0 && (idx = layout->_20[i]._14) != 0xFFFF) {
            if (layout->_20[i]._1A & 1) {
                GXSetZMode(GX_FALSE, GX_ALWAYS, GX_TRUE);
            } else {
                GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
            }
            switch (layout->_20[i]._1A & 6) {
            case 2:
                GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_CLEAR);
                break;
            case 4:
                GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTCOL, GX_BL_ZERO, GX_LO_CLEAR);
                break;
            default:
                GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
                break;
            }
            obj = geo->_10[idx]._0;
            CTRLBuildMatrix(layout->_20[i]._00, obj->_18);
            PSMTXConcat(world, obj->_18, obj->_18);
            PSMTXConcat(camera, obj->_18, mtx);
            corners[0].x = obj->_58;
            corners[0].y = obj->_60;
            corners[0].z = obj->_64;
            corners[1].x = obj->_54;
            corners[1].y = obj->_60;
            corners[1].z = obj->_64;
            corners[2].x = obj->_54;
            corners[2].y = obj->_60;
            corners[2].z = obj->_68;
            corners[3].x = obj->_58;
            corners[3].y = obj->_60;
            corners[3].z = obj->_68;
            corners[4].x = obj->_58;
            corners[4].y = obj->_5C;
            corners[4].z = obj->_64;
            corners[5].x = obj->_54;
            corners[5].y = obj->_5C;
            corners[5].z = obj->_64;
            corners[6].x = obj->_54;
            corners[6].y = obj->_5C;
            corners[6].z = obj->_68;
            corners[7].x = obj->_58;
            corners[7].y = obj->_5C;
            corners[7].z = obj->_68;
            if (fn_800B7D3C(0, corners, mtx) != 0) {
                lbl_1_common_bss_472B4._22C++;
                va_start(args, count);
                DOVARender(obj, camera, count, &args);
            }
        }
    }
    if (lbl_1_bss_C1 != 0) {
        end = layout->_6;
        if (lbl_1_common_bss_472B4._22E < 0) {
            i = 0;
        } else {
            i = lbl_1_common_bss_472B4._22E;
            end = lbl_1_common_bss_472B4._22E + 1;
        }
        for (; i < end; i++) {
            if (lbl_1_bss_2E0[i] == 0 && layout->_20[i]._14 != 0xFFFF) {
                obj = geo->_10[layout->_20[i]._14]._0;
                CTRLBuildMatrix(layout->_20[i]._00, obj->_18);
                PSMTXConcat(world, obj->_18, obj->_18);
                PSMTXConcat(camera, obj->_18, mtx);
                corners[0].x = obj->_58;
                corners[0].y = obj->_60;
                corners[0].z = obj->_64;
                corners[1].x = obj->_54;
                corners[1].y = obj->_60;
                corners[1].z = obj->_64;
                corners[2].x = obj->_54;
                corners[2].y = obj->_60;
                corners[2].z = obj->_68;
                corners[3].x = obj->_58;
                corners[3].y = obj->_60;
                corners[3].z = obj->_68;
                corners[4].x = obj->_58;
                corners[4].y = obj->_5C;
                corners[4].z = obj->_64;
                corners[5].x = obj->_54;
                corners[5].y = obj->_5C;
                corners[5].z = obj->_64;
                corners[6].x = obj->_54;
                corners[6].y = obj->_5C;
                corners[6].z = obj->_68;
                corners[7].x = obj->_58;
                corners[7].y = obj->_5C;
                corners[7].z = obj->_68;
                if (fn_800B7D3C(0, corners, mtx) != 0) {
                    fn_1_4E98(obj, camera);
                }
            }
        }
    }
}

// .text:0x24A8 size:0x138
void fn_1_7280(void) {
    Draw0138* draw;

    draw = &lbl_1_common_bss_472B4._05C[lbl_803CBBC0];
    PSMTXCopy(lbl_1_common_bss_472B4._000, draw->_38);
    fn_800A7D4C(0, &lbl_1_data_8B4[lbl_803CBBC0]);
    fn_800A7D4C(0, draw);
    fn_800A7D4C(0, &lbl_1_data_8A4[lbl_803CBBC0]);
    draw = &lbl_1_common_bss_472B4._05C[lbl_803CBBC0] + 2;
    PSMTXRotRad(draw->_08, 'Y', 0.0000958738f * lbl_1_common_bss_472B4._23A);
    PSMTXCopy(lbl_1_common_bss_472B4._000, draw->_38);
    fn_800A7D4C(0, draw);
    fn_800A7D4C(0, &lbl_1_data_88C[lbl_803CBBC0]);
}

// .text:0x23A4 size:0x104
// MWCC inlines fn_1_4DD8 here, where the target calls it; with that call it
// matches (body checked against a copy without fn_1_4DD8's definition).
void fn_1_717C(File0138* file) {
    void* geo;
    Layout0138* layout;
    u8* tex;

    layout = (Layout0138*)((u8*)file + file->_00);
    geo = (u8*)file + file->_0C;
    tex = (u8*)file + file->_14;

    fn_1_4DD8((u16*)((u8*)file + file->_08));
    fn_800B49E4(layout);
    fn_800BCE38(geo);
    convertTextureHeader(tex);
    lbl_1_common_bss_472B4._058 = tex + 4;
    fn_800BD190(geo, tex);
    haveActLayoutPointToGeoHeader(layout, geo);
    lbl_1_common_bss_472B4._22A = layout->_6;
    lbl_1_common_bss_472B4._05C[1]._68 = layout;
    lbl_1_common_bss_472B4._05C[0]._68 = layout;
    layout = (Layout0138*)((u8*)file + file->_04);
    geo = (u8*)file + file->_10;
    fn_800B49E4(layout);
    fn_800BCE38(geo);
    fn_800BD190(geo, tex);
    haveActLayoutPointToGeoHeader(layout, geo);
    lbl_1_common_bss_472B4._05C[3]._68 = layout;
    lbl_1_common_bss_472B4._05C[2]._68 = layout;
}

// .text:0x203C size:0x368
void fn_1_6E14(void) {
    fn_1_7960();
    if (lbl_1_common_bss_472B4._238 == 0) {
        fn_1_7280();
    } else {
        fn_1_196C();
    }
    if (lbl_803C77B8[0]._02 & 0x1000) {
        SetFogNoneAgain();
        lbl_803CC1B8->_00 = fn_1_66C4;
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        lbl_1_common_bss_472B4._235 = 0;
        lbl_1_common_bss_472B4._238 = 0;
        lbl_1_common_bss_472B4._232 ^= 1;
        lbl_1_common_bss_472B4._22E = -1;
    }
    if (lbl_1_common_bss_472B4._232 != 0) {
        switch (lbl_803C77B8[0]._04) {
        case 8:
            if (--lbl_1_common_bss_472B4._233 < 0) {
                lbl_1_common_bss_472B4._233 = 7;
            }
            break;
        case 4:
            if (++lbl_1_common_bss_472B4._233 >= 8) {
                lbl_1_common_bss_472B4._233 = 0;
            }
            break;
        case 0x100:
            switch (lbl_1_common_bss_472B4._233) {
            case 0:
                lbl_1_common_bss_472B4._235 = 1;
                lbl_1_common_bss_472B4._232 = 0;
                break;
            case 1:
                lbl_1_common_bss_472B4._22E = -1;
                lbl_1_common_bss_472B4._235 = 1;
                lbl_1_common_bss_472B4._232 = 0;
                break;
            case 2:
                lbl_1_common_bss_472B4._235 = 1;
                lbl_1_common_bss_472B4._232 = 0;
                break;
            case 3:
                lbl_1_common_bss_472B4._235 = 1;
                lbl_1_common_bss_472B4._232 = 0;
                break;
            case 4:
                lbl_1_common_bss_472B4._234 ^= 1;
                break;
            case 5:
                lbl_1_common_bss_472B4._235 = 1;
                lbl_1_common_bss_472B4._232 = 0;
                break;
            case 6:
                lbl_1_bss_C0 ^= 1;
                break;
            case 7:
                lbl_1_bss_C1 ^= 1;
                break;
            }
            break;
        }
    }
    if (lbl_1_common_bss_472B4._235 != 0) {
        lbl_1_data_860[lbl_1_common_bss_472B4._233]();
    }
    if (lbl_1_bss_C0 != 0) {
        fn_800B996C(fn_1_5544);
    } else {
        fn_800B996C(NULL);
    }
}

// .text:0x1A70 size:0x5CC
// MWCC inlines fn_1_4DD8 into the inlined fn_1_717C here, where the target calls
// it; with fn_1_4DD8 external it scores 98.88% (task and width registers swapped).
void fn_1_6848(void) {
    Task0138* task = lbl_803CC1B8;

    switch (task->_10) {
    case 0:
        fn_800B9AA8(NULL);
        fn_1_6578(&lbl_1_bss_4E4, lbl_1_bss_520, lbl_1_data_854, lbl_1_data_854);
        fn_800B996C(fn_1_5544);
        LITAlloc(&lbl_1_data_848[0]);
        LITAlloc(&lbl_1_data_848[1]);
        LITAlloc(&lbl_1_data_848[2]);
        {
        GXColor colors[3] = { { 0xFF, 0x00, 0x00, 0xFF }, { 0x00, 0x00, 0xFF, 0xFF }, { 0x00, 0xFF, 0x00, 0xFF } };
        LITInitAttn(lbl_1_data_848[0], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        LITInitPos(lbl_1_data_848[0], 10000.0f, -200.0f, 0.0f);
        LITInitDir(lbl_1_data_848[0], 0.0f, 0.0f, 0.0f);
        LITInitColor(lbl_1_data_848[0], colors[0]);
        LITInitAttn(lbl_1_data_848[1], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        LITInitPos(lbl_1_data_848[1], 0.0f, -200.0f, 10000.0f);
        LITInitDir(lbl_1_data_848[1], 0.0f, 0.0f, 0.0f);
        LITInitColor(lbl_1_data_848[1], colors[1]);
        LITInitAttn(lbl_1_data_848[2], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        LITInitPos(lbl_1_data_848[2], 10000.0f, -200.0f, 10000.0f);
        LITInitDir(lbl_1_data_848[2], 0.0f, 0.0f, 0.0f);
        LITInitColor(lbl_1_data_848[2], colors[2]);
        }
        task->_10 = 1;
    case 1:
        switch (lbl_803C77B8[0]._04) {
        case 8:
            if (--lbl_1_common_bss_472B4._230 < 0) {
                lbl_1_common_bss_472B4._230 = lbl_1_data_8CC - 1;
            }
            break;
        case 4:
            if (++lbl_1_common_bss_472B4._230 >= lbl_1_data_8CC) {
                lbl_1_common_bss_472B4._230 = 0;
            }
            break;
        case 0x200:
            if (++lbl_1_common_bss_472B4._231 > 2) {
                lbl_1_common_bss_472B4._231 = 0;
            }
            break;
        case 0x100:
            task->_10 = 2;
            break;
        case 0x1000:
            fn_800B996C(NULL);
            task->_0C->_10 = 1;
            break;
        }
        break;
    case 2:
        task->_18 = lbl_1_common_bss_472B4._231 + lbl_1_common_bss_472B4._230 * 3;
        task->_14 = ARAMTransfer(&lbl_1_data_8D0[task->_18 * 4], 0, 0, 0);
        task->_10 = 3;
        lbl_1_bss_4E0 = &lbl_1_data_2A8[lbl_1_common_bss_472B4._230][lbl_1_common_bss_472B4._231];
        break;
    case 3:
        if (lbl_803C6CF8._715 == 1) {
            fn_1_717C(task->_14);
            DCFlushRangeNoSync(task->_14, lbl_1_data_8D0[task->_18 * 4 + 1] & 0x0FFFFFFF);
            lbl_803CC1B8->_00 = fn_1_6E14;
        }
        break;
    }
}

// .text:0x18EC size:0x184
void fn_1_66C4(void) {
    Task0138* task = lbl_803CC1B8;
    s32 save230;
    s32 save231;

    fn_800AD038(lbl_80366158._08);
    task->_10 = 0;
    save230 = lbl_1_common_bss_472B4._230;
    save231 = lbl_1_common_bss_472B4._231;
    memset(&lbl_1_common_bss_472B4, 0, 0x240);
    lbl_1_common_bss_472B4._230 = save230;
    lbl_1_common_bss_472B4._231 = save231;
    lbl_1_common_bss_472B4._21C = _OSAllocFromHeap(0x20, 0x80000);
    lbl_1_common_bss_472B4._048.y = -6.0f;
    lbl_1_common_bss_472B4._048.z = -10.666667f;
    lbl_1_common_bss_472B4._030 = 0xF36C;
    lbl_1_common_bss_472B4._054 = 0.63f;
    lbl_1_common_bss_472B4._22E = -1;
    lbl_1_common_bss_472B4._234 = 0;
    PSMTXIdentity(lbl_1_common_bss_472B4._05C[0]._08);
    lbl_1_common_bss_472B4._05C[0]._04 = fn_1_77EC;
    lbl_1_common_bss_472B4._05C[1] = lbl_1_common_bss_472B4._05C[0];
    lbl_1_common_bss_472B4._05C[2]._04 = fn_800B472C;
    lbl_1_common_bss_472B4._05C[3] = lbl_1_common_bss_472B4._05C[2];
    lbl_803CC1B8->_00 = fn_1_6848;
}

// .text:0x17A0 size:0x14C
void fn_1_6578(GXTexObj* obj, u16* image, s32 width, s32 height) {
    GXTexFilter filter;
    f32* scale;
    s32 w = width;
    s32 h = height;
    s32 offset = 0;
    s32 i;

    if (lbl_1_data_A20 == 0) {
        width /= 4;
        height /= 4;
        fn_1_6050(image, width, height, 1.0f);
        filter = GX_LINEAR;
    } else {
        scale = lbl_1_data_A24;
        for (i = 0; i <= lbl_1_data_A20; i++) {
            fn_1_6050(image + offset, w, h, *scale);
            offset += w * h;
            w /= 2;
            h /= 2;
            scale++;
        }
        filter = lbl_1_data_A38;
    }
    GXInitTexObj(obj, image, width, height, GX_TF_IA8, GX_REPEAT, GX_REPEAT, lbl_1_data_A20);
    GXInitTexObjLOD(obj, filter, GX_LINEAR, 0.0f, lbl_1_data_A20, lbl_1_data_A34, GX_FALSE, GX_FALSE, GX_ANISO_1);
}

// .text:0x1278 size:0x528
// Only commutative operands are swapped: ny * 0.5f + 0.5f and the angle's
// products put the constant first here, the variable first in the target.
void fn_1_6050(u16* image, s32 width, s32 height, f32 scale) {
    f32 a;
    s32 size;
    u8 hi;
    f32 nx;
    s32 y;
    f32 ny;
    f32 tx;
    f32 z2;
    f32 ty;
    f32 angle;
    u8 lo;
    f32 s;
    s32 x;
    f32 b;

    Mtx m;
    Vec dir;
    Vec flat;
    Vec axis;
    Quaternion q;

    size = width * 2 * height;
    memset(image, 0, size);
    for (y = 0; y < height; y++) {
        ny = 2.0f * ((f32)y / height - 0.5f);
        ty = ny * 0.5f + 0.5f;
        for (x = 0; x < width; x++) {
            nx = 2.0f * ((f32)x / width - 0.5f);
            tx = nx * 0.5f + 0.5f;
            if (y == height / 2) {
                z2 = 1.0f - nx * nx;
            } else {
                z2 = 1.0f - nx * nx - ny * ny;
            }
            if (z2 < 0.0f) {
                dir.x = nx;
                dir.y = ny;
                dir.z = 0.0f;
                PSVECNormalize(&dir, &dir);
            } else {
                dir.z = -sqrt(z2);
                dir.x = nx;
                dir.y = ny;
            }
            if (scale != 1.0f) {
                PSVECCrossProduct(&lbl_1_data_A3C, &dir, &axis);
                if (PSVECMag(&axis)) {
                    PSVECNormalize(&axis, &axis);
                    angle = (f32)acos(PSVECDotProduct(&lbl_1_data_A3C, &dir)) * scale * 0.5f;
                    s = sin(angle);
                    q.w = cos(angle);
                    q.x = axis.x * s;
                    q.y = axis.y * s;
                    q.z = axis.z * s;
                    PSMTXQuat(m, &q);
                    PSMTXMultVec(m, &lbl_1_data_A3C, &dir);
                }
            }
            flat.x = dir.x;
            flat.y = 0.0f;
            flat.z = dir.z;
            if (!PSVECMag(&flat)) {
                a = b = 0.0f;
            } else {
                PSVECNormalize(&flat, &flat);
                if (ny == 0.0f) {
                    a = 0.5f;
                } else {
                    a = acos(PSVECDotProduct(&flat, &dir));
                    PSVECCrossProduct(&flat, &dir, &axis);
                    if (!PSVECMag(&axis)) {
                        a = 0.0f;
                    } else if (axis.x < 0.0f) {
                        a = -a;
                    }
                    a /= 3.1415927f;
                    a += 0.5f;
                }
                if (nx == 0.0f) {
                    b = 0.5f;
                } else {
                    b = acos(PSVECDotProduct(&lbl_1_data_A3C, &flat));
                    PSVECCrossProduct(&lbl_1_data_A3C, &flat, &axis);
                    if (!PSVECMag(&axis)) {
                        b = 0.0f;
                    } else if (axis.y > 0.0f) {
                        b = -b;
                    }
                    b /= 3.1415927f;
                    b += 0.5f;
                }
                b -= tx;
                a -= ty;
            }
            lo = 128.0f * a + 128.0f;
            hi = 128.0f * b + 128.0f;
            image[(x / 4) * 16 + (y / 4) * width * 4 + (y % 4) * 4 + x % 4] = (hi << 8) | lo;
        }
    }
    DCFlushRange(image, size);
}

// .text:0xCE8 size:0x590
// Float registers differ (scale and the angle take other saved registers);
// otherwise the same code as fn_1_6050, which differs in operand order only.
void fn_1_5AC0(u16* image, s32 width, s32 height, f32 scale) {
    f32 tx;
    s32 y;
    f32 b;
    u8 inside;
    s32 size;
    f32 s;
    f32 nx;
    u8 hi;
    s32 x;
    f32 ny;
    f32 a;
    u8 lo;
    f32 ty;
    f32 z2;
    f32 angle;

    Mtx m;
    Vec dir;
    Vec flat;
    Vec axis;
    Quaternion q;

    size = width * 2 * height;
    memset(image, 0, size);
    for (y = 0; y < height; y++) {
        ny = 2.0f * ((f32)y / height - 0.5f);
        ty = ny * 0.5f + 0.5f;
        for (x = 0; x < width; x++) {
            nx = 2.0f * ((f32)x / width - 0.5f);
            tx = nx * 0.5f + 0.5f;
            inside = (ny > 0.2f) & (ny < 0.8f) & (nx > 0.2f) & (nx < 0.8f);
            if (y == height / 2) {
                z2 = 1.0f - nx * nx;
            } else {
                z2 = 1.0f - nx * nx - ny * ny;
            }
            if (z2 < 0.0f) {
                dir.x = nx;
                dir.y = ny;
                dir.z = 0.0f;
                PSVECNormalize(&dir, &dir);
            } else {
                dir.z = -sqrt(z2);
                dir.x = nx;
                dir.y = ny;
            }
            if (inside && scale != 1.0f) {
                PSVECCrossProduct(&lbl_1_data_A48[0], &dir, &axis);
                if (PSVECMag(&axis)) {
                    PSVECNormalize(&axis, &axis);
                    angle = (f32)acos(PSVECDotProduct(&lbl_1_data_A48[0], &dir)) * scale * 0.5f;
                    s = sin(angle);
                    q.w = cos(angle);
                    q.x = axis.x * s;
                    q.y = axis.y * s;
                    q.z = axis.z * s;
                    PSMTXQuat(m, &q);
                    PSMTXMultVec(m, &lbl_1_data_A48[0], &dir);
                }
            }
            flat.x = dir.x;
            flat.y = 0.0f;
            flat.z = dir.z;
            if (!PSVECMag(&flat)) {
                a = b = 0.0f;
            } else {
                PSVECNormalize(&flat, &flat);
                if (ny == 0.0f) {
                    a = 0.5f;
                } else {
                    a = acos(PSVECDotProduct(&flat, &dir));
                    PSVECCrossProduct(&flat, &dir, &axis);
                    if (!PSVECMag(&axis)) {
                        a = 0.0f;
                    } else if (axis.x < 0.0f) {
                        a = -a;
                    }
                    a /= 3.1415927f;
                    a += 0.5f;
                }
                if (nx == 0.0f) {
                    b = 0.5f;
                } else {
                    b = acos(PSVECDotProduct(&lbl_1_data_A48[0], &flat));
                    PSVECCrossProduct(&lbl_1_data_A48[0], &flat, &axis);
                    if (!PSVECMag(&axis)) {
                        b = 0.0f;
                    } else if (axis.y > 0.0f) {
                        b = -b;
                    }
                    b /= 3.1415927f;
                    b += 0.5f;
                }
                b -= tx;
                a -= ty;
            }
            lo = 128.0f * a + 128.0f;
            hi = 128.0f * b + 128.0f;
            image[(x / 4) * 16 + (y / 4) * width * 4 + (y % 4) * 4 + x % 4] = (hi << 8) | lo;
        }
    }
    DCFlushRange(image, size);
}

// .text:0xB4C size:0x19C
// Registers differ in every case, and the target adds the tile offset as the
// left operand last; no statement split or declaration order reproduced it.
s32 fn_1_5924(s32 width, s32 x, s32 y, s32 bpp, s32 arg4) {
    s32 offset;
    s32 row;
    s32 col;

    switch (bpp) {
    case 4:
        row = (y / 8) * width * 8;
        row += (y % 8) * 8;
        row += x % 8;
        offset = (x / 8) * 32 + row;
        return offset;
    case 8:
        row = (y / 4) * width * 4;
        row += (y % 4) * 8;
        row += x % 8;
        offset = (x / 8) * 32 + row;
        return offset;
    case 16:
        row = (y / 4) * width * 4;
        row += (y % 4) * 4;
        row += x % 4;
        offset = (x / 4) * 16 + row;
        return offset;
    case 32:
        row = (y / 4) * width * 4;
        row += (y % 4) * 8;
        row += x % 4;
        offset = (x / 8) * 16 + row;
        if (arg4 != 0) {
            offset += 16;
        }
        return offset;
    }
    return offset;
}

// .text:0x8C0 size:0x28C
void fn_1_5698(void) {
    Mtx44 proj;
    Mtx view;

    C_MTXOrtho(proj, 0.0f, 448.0f, 0.0f, 640.0f, -0.0f, -0.5f);
    GXSetProjection(proj, GX_ORTHOGRAPHIC);
    PSMTXIdentity(view);
    GXLoadPosMtxImm(view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetCullMode(GX_CULL_NONE);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 2);
    GXSetNumChans(0);
    GXSetNumTevStages(1);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_TEXA);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXLoadTexObj(&lbl_1_bss_4E4, GX_TEXMAP0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(0.0f, 100.0f, 0.0f);
    GXTexCoord2u16(0, 0);
    GXPosition3f32(0.0f, 356.0f, 0.0f);
    GXTexCoord2u16(0, 4);
    GXPosition3f32(256.0f, 356.0f, 0.0f);
    GXTexCoord2u16(4, 4);
    GXPosition3f32(256.0f, 100.0f, 0.0f);
    GXTexCoord2u16(4, 0);
    GXEnd();
    GXSetNumIndStages(0);
    GXSetTevDirect(GX_TEVSTAGE0);
}

// .text:0x76C size:0x154
void fn_1_5544(GXTevStageID stage, GXIndTexStageID indStage, GXIndTexMtxID mtx, GXTexCoordID coord, GXTexMapID map) {
    GXLoadTexObj(&lbl_1_bss_4E4, map);
    if (lbl_1_bss_DC != 0) {
        if (lbl_1_bss_DC & 2) {
            map--;
        }
        if (lbl_1_bss_DC & 4) {
            coord--;
        }
        GXSetTevOrder(stage, coord, map, GX_COLOR_NULL);
        GXSetTevColorIn(stage, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
        GXSetTevColorOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_TEXA);
        GXSetTevAlphaOp(stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    } else {
        GXSetNumIndStages(1);
        GXSetIndTexMtx(mtx, lbl_1_data_A74, lbl_1_data_A70);
        GXSetIndTexOrder(indStage, coord, map);
        GXSetIndTexCoordScale(indStage, lbl_1_bss_D8, lbl_1_bss_D4);
        GXSetTevIndWarp(stage, indStage, lbl_1_data_A6D, lbl_1_bss_D1, mtx);
    }
}

// .text:0x768 size:0x4
void fn_1_5540(void) {
}

// .text:0x708 size:0x60
void fn_1_54E0(MtxPtr view) {
    s32 i;

    for (i = 0; i < 3; i++) {
        LITXForm(lbl_1_data_848[i], view);
    }
}

// .text:0xC0 size:0x648
// Draft: the opcode cases' block order, the per-vertex inner switches' compare
// trees and the position/normal reads (scheduled differently) still differ.
void fn_1_4E98(DObj0138* obj, MtxPtr camera) {
    Mtx mtx;
    s32 desc[21];
    s32 i;
    s32 attr;
    u32 vcd;
    s32 shift;
    s32 type;
    u8* dl;
    u32 done;
    s32 handled;
    s32 size;
    u16 count;
    u16 posIdx;
    u16 nrmIdx;
    f32 scale;
    f32 x;
    f32 y;
    f32 z;
    s16* v;
    VtxArray0138* arr;

    if (obj->_0C == NULL || obj->_00 == NULL || obj->_10 == NULL) {
        return;
    }
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetCullMode(GX_CULL_NONE);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetNumChans(1);
    GXSetNumTevStages(1);
    GXSetNumTexGens(0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    PSMTXConcat(camera, obj->_18, mtx);
    GXLoadPosMtxImm(mtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    for (i = 0; i < obj->_10->_8; i++) {
        switch (obj->_10->_4[i]._0) {
        case 2:
            memset(desc, 0, sizeof(desc));
            vcd = obj->_10->_4[i]._4;
            shift = 2;
            for (attr = GX_VA_POS; attr <= GX_VA_TEX7; attr++) {
                type = (vcd >> shift) & 3;
                if (type != 0) {
                    desc[attr] = type;
                }
                shift += 2;
            }
            break;
        }
        dl = obj->_10->_4[i]._8;
        if (dl == NULL) {
            continue;
        }
        for (done = 0; done < obj->_10->_4[i]._C;) {
            handled = FALSE;
            switch (*dl) {
            case 0x00:
                handled = TRUE;
                dl += 1;
                done += 1;
                break;
            case 0x08:
                handled = TRUE;
                dl += 6;
                done += 6;
                break;
            case 0x10:
                handled = TRUE;
                size = *(u16*)dl * 4 + 5;
                dl += size;
                done += size;
                break;
            case 0x20:
            case 0x28:
            case 0x30:
            case 0x38:
                handled = TRUE;
                dl += 5;
                break;
            case 0x40:
            case 0x48:
                handled = TRUE;
                dl += 1;
                done += 1;
                break;
            case 0x61:
                handled = TRUE;
                dl += 5;
                done += 5;
                break;
            case 0x80:
            case 0x90:
            case 0x98:
            case 0xA0:
            case 0xA8:
            case 0xB0:
            case 0xB8:
                break;
            }
            if (handled) {
                continue;
            }
            count = *(u16*)(dl + 1);
            dl += 3;
            done += 3;
            GXBegin(GX_LINES, GX_VTXFMT0, count * 2);
            while (count-- != 0) {
                for (attr = GX_VA_POS; attr <= GX_VA_TEX7; attr++) {
                    if (desc[attr] == 0) {
                        continue;
                    }
                    switch (attr) {
                    case GX_VA_POS:
                        switch (desc[attr]) {
                        case 2:
                            posIdx = *dl;
                            break;
                        case 3:
                            posIdx = *(u16*)dl;
                            break;
                        }
                        break;
                    case GX_VA_NRM:
                        switch (desc[attr]) {
                        case 2:
                            nrmIdx = *dl;
                            break;
                        case 3:
                            nrmIdx = *(u16*)dl;
                            break;
                        }
                        break;
                    }
                    switch (desc[attr]) {
                    case 2:
                        dl += 1;
                        done += 1;
                        break;
                    case 3:
                        dl += 2;
                        done += 2;
                        break;
                    }
                }
                arr = obj->_00;
                scale = 1 << (arr->_6 & 0xF);
                switch ((arr->_6 >> 4) & 0xF) {
                case 3:
                    v = &arr->_0[arr->_7 * posIdx];
                    x = v[0] / scale;
                    y = v[1] / scale;
                    z = v[2] / scale;
                    break;
                }
                GXPosition3f32(x, y, z);
                GXColor1u32(0xFF0000FF);
                arr = obj->_0C;
                scale = 1 << (arr->_6 & 0xF);
                switch ((arr->_6 >> 4) & 0xF) {
                case 3:
                    v = &arr->_0[arr->_7 * nrmIdx];
                    x += v[0] / scale;
                    y += v[1] / scale;
                    z += v[2] / scale;
                    break;
                }
                GXPosition3f32(x, y, z);
                GXColor1u32(0x0000FFFF);
            }
        }
    }
}

// .text:0x0 size:0xC0
void fn_1_4DD8(u16* data) {
    s32 i;
    u32* table;

    lbl_1_common_bss_472B4._228 = data[0];
    lbl_1_common_bss_472B4._224 = (u32*)(data + 2);
    table = lbl_1_common_bss_472B4._224;
    for (i = lbl_1_common_bss_472B4._228; i >= 0; i--) {
        *table++ += (u32)data;
    }
}
