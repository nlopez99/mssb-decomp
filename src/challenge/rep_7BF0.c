#include "challenge/rep_7BF0.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"
#include "Dolphin/gx.h"
#include "Dolphin/pad.h"

// A rigid-body simulation viewer: a bat swung by the settings in its menus

// rep_7978's debug camera
typedef struct Camera7BF0 {
    /* 0x00 */ Mtx _00;
    /* 0x30 */ Mtx44 _30;
    /* 0x70 */ Vec _70;
    /* 0x7C */ Vec _7C;
    /* 0x88 */ Vec _88;
    /* 0x94 */ u8 _94[0xA4 - 0x94];
    /* 0xA4 */ f32 _A4;
    /* 0xA8 */ f32 _A8;
    /* 0xAC */ f32 _AC;
    /* 0xB0 */ f32 _B0;
    /* 0xB4 */ f32 _B4;
    /* 0xB8 */ f32 _B8;
    /* 0xBC */ f32 _BC;
    /* 0xC0 */ u8 _C0[0xD8 - 0xC0];
    /* 0xD8 */ void* _D8;
} Camera7BF0; // size: 0xDC

typedef struct Sim7BF0 {
    /* 0x000 */ Vec _00;
    /* 0x00C */ Vec _0C;
    /* 0x018 */ u8 _18[0x28 - 0x18];
    /* 0x028 */ f32 _28;
    /* 0x02C */ u8 _2C[0x50 - 0x2C];
    /* 0x050 */ f32 _50;
    /* 0x054 */ u8 _54[0x58 - 0x54];
    /* 0x058 */ Mtx _58;
    /* 0x088 */ Mtx _88;
    /* 0x0B8 */ Mtx _B8;
    /* 0x0E8 */ Vec _E8;
    /* 0x0F4 */ Quaternion _F4;
    /* 0x104 */ Vec _104;
    /* 0x110 */ u8 _110[0x11C - 0x110];
    /* 0x11C */ Vec _11C;
    /* 0x128 */ Vec _128;
    /* 0x134 */ u8 _134[0x140 - 0x134];
    /* 0x140 */ Vec _140;
    /* 0x14C */ u8 _14C[0x154 - 0x14C];
} Sim7BF0; // size: 0x154

typedef struct Menu7BF0 {
    /* 0x00 */ char* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ struct MenuItem7BF0* _18;
} Menu7BF0; // size: 0x1C

// One line of a debug menu: an integer setting, or a button that runs _28
typedef struct MenuItem7BF0 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ char* _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32* _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 (*_28)(Menu7BF0* menu, u16 pressed);
} MenuItem7BF0; // size: 0x2C

typedef struct Settings7BF0 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32 _34;
    /* 0x38 */ s8 _38;
    /* 0x39 */ s8 _39;
} Settings7BF0; // size: 0x3C

typedef struct Env7BF0 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
} Env7BF0; // size: 0x24

typedef struct Task7BF0Parent {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u16 _10;
} Task7BF0Parent;

typedef struct Task7BF0 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ Task7BF0Parent* _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ u8 _14;
    /* 0x15 */ s8 _15;
} Task7BF0;

extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

extern void fn_800AD038(void* arg0);
extern void fn_800A97D0(s32 arg0, s32 arg1);
extern void fn_800B0A14_removeQueue(void);
extern void fn_800B806C(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
extern void fn_80048820(Menu7BF0* menu, u16 held, u16 pressed, u16 repeat, u8 trigger);
extern void fn_80048BEC(Menu7BF0* menu, s32 arg1, s32 arg2);
extern void fn_80037768(Sim7BF0* sim, s32 arg1, s32 count, f32 length, f32 center, f32 radius, f32 mass);
extern void fn_800383BC(Sim7BF0* sim);
extern void fn_80037054(Sim7BF0* sim, Env7BF0* env);
extern void gOz_GXSetTexture(s32, s32, s32);
extern void fn_1_AF4(s32 arg0, s32 arg1, f32 arg2);
extern void fn_1_26D28(Camera7BF0* cam, u16 held, u16 pressed, u16 repeat, s8* stick);
extern void fn_1_272DC(Camera7BF0* cam, s32 id);
extern void fn_1_27330(Camera7BF0* cam);
extern void fn_1_273D8(Camera7BF0* cam);

static Settings7BF0 lbl_1_data_11300 = {
    150000, 50000, 6250, 12500, 5000, 500000, 2000000, 0, 0, 0, 0, 0, 0, 19, 0, 0,
};
Env7BF0 lbl_1_data_1133C = { 100000000, 100, 100, 980665, 100, 100, 1000, 314000, 0 };
static Vec lbl_1_data_11360[8] = {
    { -0.5f, -0.5f, -0.5f }, { 0.5f, -0.5f, -0.5f }, { 0.5f, 0.5f, -0.5f }, { -0.5f, 0.5f, -0.5f },
    { -0.5f, -0.5f, 0.5f },  { 0.5f, -0.5f, 0.5f },  { 0.5f, 0.5f, 0.5f },  { -0.5f, 0.5f, 0.5f },
};
static u32 lbl_1_data_113C0[6] = { 0xFF0000FF, 0x00FF00FF, 0x0000FFFF, 0xFFFF00FF, 0xFF00FFFF, 0x00FFFFFF };
static u8 lbl_1_data_113E0[0x40] ATTRIBUTE_ALIGN(32) = {
    0x80, 0x00, 0x18, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x01, 0x07, 0x01, 0x06, 0x01,
    0x05, 0x01, 0x00, 0x02, 0x04, 0x02, 0x05, 0x02, 0x01, 0x02, 0x01, 0x03, 0x05, 0x03, 0x06, 0x03, 0x02,
    0x03, 0x02, 0x04, 0x06, 0x04, 0x07, 0x04, 0x03, 0x04, 0x03, 0x05, 0x07, 0x05, 0x04, 0x05, 0x00, 0x05,
    0x00,
};
static char* lbl_1_data_11420 = "MAIN MENU";
static char* lbl_1_data_11424[3] = {
    "A:Sim Start X:Sim Step",
    "A:Sim Start X:SimStep B:Reset",
    "A:Sim Stop  B:Reset",
};
static MenuItem7BF0 lbl_1_data_11430[3] = {
    { 8, "BACK TO PREV MENU", 0, 0, 0, 0, 0, NULL, 256, -1, fn_1_28AE0 },
    { 8, "BAT MENU", 0, 0, 0, 0, 0, NULL, 256, 1, fn_1_28AE0 },
    { 0 },
};
static MenuItem7BF0 lbl_1_data_114B4[26] = {
    { 8, "MAIN MENU", 0, 0, 0, 0, 0, NULL, 256, 0, fn_1_28AE0 },
    { 8, NULL, 0, 0, 0, 0, 0, NULL, 1792, 0, fn_1_289E0 },
    { 0, "SIM NUM  ", 1, 100, 1, 10, 20, &lbl_1_data_11300._34 },
    { 1, "LENGTH   ", 0, 1000000, 1000, 100, 10000, &lbl_1_data_11300._00 },
    { 1, "CENTER   ", 0, 1000000, 1000, 100, 10000, &lbl_1_data_11300._04 },
    { 1, "RADIUS   ", 0, 1000000, 1000, 100, 10000, &lbl_1_data_11300._08 },
    { 1, "MASS     ", 0, 1000000, 1000, 100, 10000, &lbl_1_data_11300._0C },
    { 1, "FIRST POS", -10000000, 10000000, 1000, 100, 10000, &lbl_1_data_11300._14 },
    { 1, "FIRST ROT", -18000000, 18000000, 100000, 10000, 1000000, &lbl_1_data_11300._18 },
    { 1, "VEL   X  ", -10000000, 10000000, 100, 1000, 10000, &lbl_1_data_11300._1C },
    { 1, "VEL   Y  ", -10000000, 10000000, 100, 1000, 10000, &lbl_1_data_11300._20 },
    { 1, "VEL   Z  ", -10000000, 10000000, 100, 1000, 10000, &lbl_1_data_11300._24 },
    { 1, "OMEGA X  ", -10000000, 10000000, 100, 1000, 10000, &lbl_1_data_11300._28 },
    { 1, "OMEGA Y  ", -10000000, 10000000, 100, 1000, 10000, &lbl_1_data_11300._2C },
    { 1, "OMEGA Z  ", -10000000, 10000000, 100, 1000, 10000, &lbl_1_data_11300._30 },
    { 1, "AIR REG  ", -10000000, 10000000, 10, 100, 1000, &lbl_1_data_11300._10 },
    { 1, "ENV K    ", -100000000, 100000000, 10000, 100000, 1000000, &lbl_1_data_1133C._00 },
    { 1, "ENV D    ", -100000000, 100000000, 100, 1000, 10000, &lbl_1_data_1133C._04 },
    { 1, "ENV E    ", -100000000, 100000000, 10, 100, 1000, &lbl_1_data_1133C._08 },
    { 1, "ENV MK   ", 0, 100000000, 1000, 10000, 100000, &lbl_1_data_1133C._20 },
    { 1, "ENV R CAP", 0, 100000000, 1000, 10000, 100000, &lbl_1_data_1133C._0C },
    { 1, "ENV R CUT", 0, 100000000, 10, 100, 1000, &lbl_1_data_1133C._10 },
    { 1, "ENV M CUT", 0, 100000000, 1000, 10000, 100000, &lbl_1_data_1133C._14 },
    { 1, "ENV S CAP", 0, 100000000, 100, 1000, 10000, &lbl_1_data_1133C._18 },
    { 1, "ENV O CAP", 0, 100000000, 1000, 10000, 100000, &lbl_1_data_1133C._1C },
    { 0 },
};
static MenuItem7BF0* lbl_1_data_1192C[2] = { lbl_1_data_11430, lbl_1_data_114B4 };

static Camera7BF0 lbl_1_bss_471D8;
static Menu7BF0 lbl_1_bss_471BC;
static Sim7BF0 lbl_1_bss_47068;

// .text:0x1510 size:0x1C0
// Only register numbers differ, in the inlined fn_1_2935C and fn_1_28C34 code;
// no statement order or title argument changed them.
void fn_1_29A9C(void) {
    fn_1_2935C(&lbl_1_bss_47068);
    fn_1_273D8(&lbl_1_bss_471D8);
    lbl_1_data_11300._38 = 0;
    fn_1_28C34(&lbl_1_bss_471BC, 0, NULL);
    fn_800B806C(0, -240.0f, 240.0f, -320.0f, 320.0f, -512.0f, -1.0f, 1280.0f);
    ((Task7BF0*)lbl_803CC1B8)->_00 = fn_1_295E8;
}

// .text:0x14BC size:0x54
void fn_1_29A48(void) {
    fn_800AD038(lbl_80366158._08);
    fn_800A97D0(0x10, 0x1E);
    ((Task7BF0*)lbl_803CC1B8)->_0C->_10 = 1;
    fn_800B0A14_removeQueue();
}

// .text:0x105C size:0x460
void fn_1_295E8(void) {
    Task7BF0* task = lbl_803CC1B8;

    fn_1_2948C(task);
    fn_1_2905C();
    fn_1_29414(task);
}

static inline void fn_1_7BF0_menuControl(Menu7BF0* menu, u16 held, u16 pressed, u16 repeat) {
    fn_80048820(menu, held, pressed, repeat, (held & PAD_BUTTON_Y) ? 0x91 : ((held & PAD_BUTTON_X) ? 0x50 : 0));
}

// .text:0xF00 size:0x15C
void fn_1_2948C(Task7BF0* task) {
    u16 held = lbl_803C77B8[0]._00;
    u16 pressed = lbl_803C77B8[0]._02;
    u16 repeat = lbl_803C77B8[0]._04;

    if (pressed & PAD_BUTTON_START) {
        task->_14 ^= 1;
        if (task->_14 != 0) {
            fn_800A97D0(0x20, 0);
        } else {
            fn_800A97D0(0x10, 0x1E);
        }
    } else if (task->_14 != 0) {
        fn_1_7BF0_menuControl(&lbl_1_bss_471BC, lbl_803C77B8[0]._00, lbl_803C77B8[0]._02, repeat);
        held &= ~(PAD_BUTTON_X | PAD_BUTTON_Y);
        pressed &= ~(PAD_BUTTON_X | PAD_BUTTON_Y);
        repeat &= ~(PAD_BUTTON_X | PAD_BUTTON_Y);
    } else if (pressed & PAD_BUTTON_B) {
        fn_1_29A48();
    }
    fn_1_26D28(&lbl_1_bss_471D8, held, pressed, repeat, &lbl_803C77B8[0]._10);
    fn_1_27330(&lbl_1_bss_471D8);
}

// .text:0xE88 size:0x78
void fn_1_29414(Task7BF0* task) {
    if (task->_14 != 0) {
        fn_80048BEC(&lbl_1_bss_471BC, 0, 0);
    }
    fn_1_272DC(&lbl_1_bss_471D8, 0);
    fn_1_AF4(10, 10, 1.0f);
    fn_1_28CE8(task);
}

// .text:0xDD0 size:0xB8
void fn_1_2935C(Sim7BF0* sim) {
    fn_80037768(sim, 2, lbl_1_data_11300._34, lbl_1_data_11300._00 / 100000.0f, lbl_1_data_11300._04 / 100000.0f,
                lbl_1_data_11300._08 / 100000.0f, lbl_1_data_11300._0C / 100000.0f);
}

// .text:0xAD0 size:0x300
void fn_1_2905C(void) {
    Mtx m;

    switch (lbl_1_data_11300._38) {
    case 0:
        fn_1_2935C(&lbl_1_bss_47068);
        lbl_1_bss_47068._E8.x = 0.0f;
        lbl_1_bss_47068._E8.y = lbl_1_data_11300._14 / 100000.0f;
        lbl_1_bss_47068._E8.z = 0.0f;
        lbl_1_bss_47068._11C.x = lbl_1_data_11300._1C / 100000.0f;
        lbl_1_bss_47068._11C.y = lbl_1_data_11300._20 / 100000.0f;
        lbl_1_bss_47068._11C.z = lbl_1_data_11300._24 / 100000.0f;
        PSMTXMultVec(lbl_1_bss_47068._B8, &lbl_1_bss_47068._11C, &lbl_1_bss_47068._128);
        lbl_1_bss_47068._140.x = lbl_1_data_11300._28 / 100000.0f;
        lbl_1_bss_47068._140.y = lbl_1_data_11300._2C / 100000.0f;
        lbl_1_bss_47068._140.z = lbl_1_data_11300._30 / 100000.0f;
        PSMTXRotRad(m, 'X', 0.017453292f * (lbl_1_data_11300._18 / 100000.0f));
        C_QUATMtx(&lbl_1_bss_47068._F4, m);
        fn_800383BC(&lbl_1_bss_47068);
        break;
    case 1:
        if (lbl_1_data_11300._39 == 0) {
            break;
        }
        lbl_1_data_11300._39 = 0;
    case 2:
        lbl_1_bss_47068._50 = lbl_1_data_11300._10 / 100000.0f;
        fn_80037054(&lbl_1_bss_47068, &lbl_1_data_1133C);
        break;
    }
}

// .text:0x75C size:0x374
void fn_1_28CE8(Task7BF0* task) {
    Mtx m;
    Vec v;
    f32 radius = lbl_1_data_11300._08 / 100000.0f;

    PSMTXScale(m, radius, radius, lbl_1_data_11300._00 / 100000.0f);
    PSMTXConcat(lbl_1_bss_47068._58, m, m);
    PSMTXConcat(lbl_1_bss_471D8._00, m, m);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    gOz_GXSetTexture(4, 0, 0);
    GXBegin(GX_LINES, GX_VTXFMT0, 6);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXColor1u32(0xFF0000FF);
    GXPosition3f32(1.0f, 0.0f, 0.0f);
    GXColor1u32(0xFF0000FF);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXColor1u32(0x00FF00FF);
    GXPosition3f32(0.0f, 1.0f, 0.0f);
    GXColor1u32(0x00FF00FF);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXColor1u32(0x0000FFFF);
    GXPosition3f32(0.0f, 0.0f, 1.0f);
    GXColor1u32(0x0000FFFF);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
    GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetArray(GX_VA_POS, lbl_1_data_11360, sizeof(Vec));
    GXSetArray(GX_VA_CLR0, lbl_1_data_113C0, sizeof(u32));
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetCullMode(GX_CULL_BACK);
    GXCallDisplayList(lbl_1_data_113E0, sizeof(lbl_1_data_113E0));
    PSMTXMultVec(lbl_1_bss_47068._58, &lbl_1_bss_47068._00, &v);
    PSMTXMultVec(lbl_1_bss_47068._58, &lbl_1_bss_47068._0C, &v);
    PSVECCrossProduct(&lbl_1_bss_47068._00, &lbl_1_bss_47068._140, &v);
    PSMTXMultVec(lbl_1_bss_47068._88, &v, &v);
    PSVECCrossProduct(&lbl_1_bss_47068._0C, &lbl_1_bss_47068._140, &v);
    PSMTXMultVec(lbl_1_bss_47068._88, &v, &v);
    PSVECScale(&lbl_1_bss_47068._104, lbl_1_bss_47068._28, &v);
}

// .text:0x6A8 size:0xB4
void fn_1_28C34(Menu7BF0* menu, s32 index, char* title) {
    menu->_00 = title != NULL ? title : lbl_1_data_11420;
    menu->_08 = 16;
    menu->_0C = 0;
    menu->_10 = 0;
    menu->_14 = 1;
    menu->_18 = lbl_1_data_1192C[index];
    if (index == 1 && lbl_1_data_114B4[1]._04 == NULL) {
        lbl_1_data_114B4[1]._04 = lbl_1_data_11424[lbl_1_data_11300._38];
    }
    menu->_04 = 0;
    while (menu->_18[menu->_04]._04 != NULL) {
        menu->_04++;
    }
}

// .text:0x554 size:0x154
s32 fn_1_28AE0(Menu7BF0* menu, u16 pressed) {
    Task7BF0* task = lbl_803CC1B8;

    task->_15 = menu->_18[menu->_10]._24;
    if (task->_15 < 0) {
        fn_1_29A48();
    } else {
        fn_1_28C34(menu, task->_15, menu->_18[menu->_10]._04);
    }
    return 0;
}

// .text:0x454 size:0x100
s32 fn_1_289E0(Menu7BF0* menu, u16 pressed) {
    switch (lbl_1_data_11300._38) {
    case 0:
        if (pressed & PAD_BUTTON_A) {
            lbl_1_data_11300._38 = 2;
        } else if (pressed & PAD_BUTTON_X) {
            lbl_1_data_11300._39 = 1;
            lbl_1_data_11300._38 = 1;
        }
        break;
    case 1:
        if (pressed & PAD_BUTTON_A) {
            lbl_1_data_11300._38 = 2;
        } else if (pressed & PAD_BUTTON_B) {
            lbl_1_data_11300._38 = 0;
        } else if (pressed & PAD_BUTTON_X) {
            lbl_1_data_11300._39 = 1;
        }
        break;
    case 2:
        if (pressed & PAD_BUTTON_A) {
            lbl_1_data_11300._38 = 1;
        } else if (pressed & PAD_BUTTON_B) {
            lbl_1_data_11300._38 = 0;
        }
        break;
    }
    menu->_18[menu->_10]._04 = lbl_1_data_11424[lbl_1_data_11300._38];
    return 0;
}

// .text:0x434 size:0x20
void fn_1_289C0(Camera7BF0* cam) {
    fn_1_273D8(cam);
}

// .text:0x0 size:0x434
void fn_1_2858C(Camera7BF0* cam, u16 held, u16 pressed, u16 repeat, s8* stick) {
    Mtx m;
    Quaternion q;
    Vec v;

    if (pressed & PAD_TRIGGER_Z) {
        fn_1_273D8(cam);
        return;
    }
    cam->_A4 -= 3.1415927f * cam->_B0 / 180.0f * stick[2] / 128.0f / 60.0f;
    cam->_A8 += 3.1415927f * cam->_B0 / 180.0f * stick[3] / 128.0f / 60.0f;
    while (cam->_A4 < -3.1415927f) {
        cam->_A4 += 6.2831855f;
    }
    while (cam->_A4 >= 3.1415927f) {
        cam->_A4 -= 6.2831855f;
    }
    if (cam->_A8 < -3.1385248f) {
        cam->_A8 = -3.1385248f;
    } else if (cam->_A8 > 3.1385248f) {
        cam->_A8 = 3.1385248f;
    }
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 1.0f;
    PSVECCrossProduct(&v, &cam->_88, &cam->_7C);
    PSVECNormalize(&cam->_7C, &cam->_7C);
    C_QUATRotAxisRad(&q, &cam->_7C, cam->_A8);
    PSMTXQuat(m, &q);
    PSMTXMultVec(m, &v, &cam->_7C);
    C_QUATRotAxisRad(&q, &cam->_88, cam->_A4);
    PSMTXQuat(m, &q);
    PSMTXMultVec(m, &cam->_7C, &cam->_7C);
    v.x = cam->_AC * -stick[0] / 128.0f / 60.0f;
    v.z = cam->_AC * stick[1] / 128.0f / 60.0f;
    v.y -= cam->_AC * (u8)stick[4] / 150.0f / 60.0f;
    v.y += cam->_AC * (u8)stick[5] / 150.0f / 60.0f;
    PSMTXMultVec(m, &v, &v);
    PSVECAdd(&cam->_70, &v, &cam->_70);
    cam->_B8 += cam->_B4 * ((held & PAD_BUTTON_X) != 0) / 60.0f;
    cam->_B8 -= cam->_B4 * ((held & PAD_BUTTON_Y) != 0) / 60.0f;
    cam->_B8 = 0.1f * (cam->_B8 == 0.0f) + cam->_B8 * (cam->_B8 != 0.0f);
    cam->_BC = 1.0f / cam->_B8;
}
