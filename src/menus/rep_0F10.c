#include "header_rep_data.h"
#include "menus/rep_0F10.h"
#include "string.h"

extern struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06;
    /* 0x07 */ u8 _07[6];
    /* 0x0D */ s8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ s8 _0F;
    /* 0x10 */ s8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ s8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
} lbl_2_bss_33FBCC;

extern struct {
    /* 0x00 */ u8 _00[0x50];
    /* 0x50 */ s32 _50;
    /* 0x54 */ s32 _54;
} lbl_2_bss_F410;

typedef struct MenuTask0F10 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
} MenuTask0F10;

typedef struct MenuSprite0F10 {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66;
    /* 0x67 */ u8 _67;
    /* 0x68 */ u8 _68;
} MenuSprite0F10;

typedef struct MenuSpriteRef0F10 {
    /* 0x0 */ MenuSprite0F10* _00;
    /* 0x4 */ u8 _04[0x8 - 0x4];
} MenuSpriteRef0F10; // size: 0x8

extern MenuSpriteRef0F10 lbl_80371C30[];

extern void* lbl_803CC1B8;

extern struct {
    /* 0x0000 */ u8 _0000[0x4756];
    /* 0x4756 */ u8 _4756;
    /* 0x4757 */ u8 _4757[0x48AF - 0x4757];
    /* 0x48AF */ u8 _48AF;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0xF6];
    /* 0xF6 */ u8 _F6;
} lbl_80361B20;


typedef struct TrackerSlot0F10 {
    /* 0x0 */ s16 _0;
    /* 0x2 */ u8 _2[0x6 - 0x2];
} TrackerSlot0F10; // size: 0x6

typedef struct Tracker0F10 {
    /* 0x0000 */ u8 _0000[0x1606];
    /* 0x1606 */ s8 _1606;
    /* 0x1607 */ u8 _1607[0x40B8 - 0x1607];
    /* 0x40B8 */ TrackerSlot0F10 _40B8[9];
    /* 0x40EE */ u8 _40EE[0x43BC - 0x40EE];
    /* 0x43BC */ s16 _43BC;
    /* 0x43BE */ u8 _43BE[0x4415 - 0x43BE];
    /* 0x4415 */ u8 _4415;
    /* 0x4416 */ u8 _4416;
    /* 0x4417 */ u8 _4417[0x441B - 0x4417];
    /* 0x441B */ u8 _441B;
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E[0x444B - 0x441E];
    /* 0x444B */ s8 _444B;
    /* 0x444C */ u8 _444C[0x4508 - 0x444C];
} Tracker0F10; // size: 0x4508

extern struct {
    /* 0x0000 */ Tracker0F10 trackers[3];
    /* 0xCF18 */ u8 _CF18[0xCF5E - 0xCF18];
    /* 0xCF5E */ u8 _CF5E[3];
} lbl_80354768;

extern void fn_80034E20(MenuTask0F10* task, void* desc);
extern void changeScene(u8, s16);
extern void fn_80034CEC(MenuTask0F10* task);
extern void fn_800B0A14_removeQueue(void);

extern struct {
    /* 0x0 */ u8 _0[0x3];
    /* 0x3 */ u8 _3;
} lbl_8034E978;
extern s32 fn_80042DA8(MenuTask0F10* task, s32 index, s32 value);
extern void fn_800363D8(MenuTask0F10* task, s32 id, s32 part, s32 kind, s32 value);

static inline BOOL isAnimDone(MenuTask0F10* task, s32 index, s32 value) {
    return fn_80042DA8(task, index, value) ? TRUE : FALSE;
}

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct SpriteDesc0F10 {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} SpriteDesc0F10; // size: 0x20

static char lbl_2_data_2E9F8[4][32] = { "BAT FIRST", "BAT LAST", "FL", "PC" };
static char lbl_2_data_2EA78[4][4] = { "RR", "RL", "LR", "LL" };
static char lbl_2_data_2EA88[2][32] = { "OFF", "ON" };
static char lbl_2_data_2EAC8[5][32] = {
    "SELECT DEBUG MENU",
    "HIDE CHARA SET",
    "STAR PLAYER SET",
    "KOOPA STA FLAG SET",
    "CHALLE LEVEL FREE SET",
};
static char lbl_2_data_2EB68[8][32] = {
    "1P >",
    "COM1>",
    "2P >",
    "COM2>",
    "3P >",
    "COM3>",
    "4P >",
    "COM4>",
};
static u32 lbl_2_data_2EC68[8] = { 0xFF0F, 0x880F, 0x0FFF, 0x088F, 0xF0FF, 0x808F, 0xF00F, 0x800F };
static s16 lbl_2_data_2EC88[12] = { 0, 4, 10, 6, 2, 9, 1, 5, 11, 17, 3, 19 };
static u8 lbl_2_data_2ECA0[0x44] = {
    0x00, 0x02, 0x06, 0x08, 0x04, 0x0A, 0x01, 0x03, 0x07, 0x05, 0x09, 0x0B, 0x00, 0x00, 0x06, 0x02,
    0x08, 0x04, 0x0A, 0x05, 0x0B, 0x03, 0x09, 0x01, 0x07, 0x00, 0x00, 0x00, 0x02, 0x05, 0x04, 0x03,
    0x08, 0x03, 0x04, 0x05, 0x02, 0x06, 0x00, 0x01, 0x08, 0x06, 0x07, 0x01, 0x02, 0x00, 0x07, 0x04,
    0x04, 0x03, 0x01, 0x02, 0x05, 0x01, 0x02, 0x04, 0x06, 0x08, 0x07, 0x06, 0x08, 0x05, 0x03, 0x03,
    0x05, 0x07, 0x04, 0x06,
};
static SpriteDesc0F10 lbl_2_data_2ECE4[70] = {
    { 0, 0xE, { 0, 0, -1 }, { 0x01, 0x14 }, 255, { 0x8000000, 0, 0x10000 } },
    { 0, 0xF, { 0, 0, -1 }, { 0x01, 0x13 }, 0, { 0x8000000, 0, 0x10002 } },
    { 0, 0xF, { 0, 0, -1 }, { 0x01, 0x13 }, 0, { 0x8000000, 0, 0x10001 } },
    { 0, 0xF, { 0, 0, -1 }, { 0x01, 0x13 }, 0, { 0x8000000, 0, 0x10000 } },
    { 0, 0x11, { 0, 0, -1 }, { 0x01, 0x07 }, 0, { 0x8000000, 0, 0x10002 } },
    { 0, 0x11, { 0, 0, -1 }, { 0x01, 0x07 }, 0, { 0x8000000, 0, 0x10001 } },
    { 0, 0x11, { 0, 0, -1 }, { 0x01, 0x07 }, 0, { 0x8000000, 0, 0x10000 } },
    { 0, 0x12, { 0, 0, -1 }, { 0x01, 0x08 }, 0, { 0x8000000, 0, 0x10002 } },
    { 0, 0x12, { 0, 0, -1 }, { 0x01, 0x08 }, 0, { 0x8000000, 0, 0x10001 } },
    { 0, 0x12, { 0, 0, -1 }, { 0x01, 0x08 }, 0, { 0x8000000, 0, 0x10000 } },
    { 0, 0xB, { 0, 0, -1 }, { 0x01, 0x14 }, 255, { 0x8000000, 0, 0x10000 } },
    { 0, 0xC, { 0, 0, -1 }, { 0x01, 0x08 }, 10, { 0x8000000, 0, 0x10005 } },
    { 0, 0xC, { 0, 0, -1 }, { 0x01, 0x08 }, 10, { 0x8000000, 0, 0x10004 } },
    { 0, 0xC, { 0, 0, -1 }, { 0x01, 0x08 }, 10, { 0x8000000, 0, 0x10003 } },
    { 0, 0xA, { 0, 0, -1 }, { 0x01, 0x07 }, 1, { 0x8000000, 0, 0x10002 } },
    { 0, 0xA, { 0, 0, -1 }, { 0x01, 0x07 }, 1, { 0x8000000, 0, 0x10003 } },
    { 0, 0xA, { 0, 0, -1 }, { 0x01, 0x07 }, 1, { 0x8000000, 0, 0x10004 } },
    { 0, 0xA, { 0, 0, -1 }, { 0x01, 0x07 }, 2, { 0x8000000, 0, 0x10002 } },
    { 0, 0xA, { 0, 0, -1 }, { 0x01, 0x07 }, 2, { 0x8000000, 0, 0x10003 } },
    { 0, 0xA, { 0, 0, -1 }, { 0x01, 0x07 }, 2, { 0x8000000, 0, 0x10004 } },
    { 0, 0xA, { 0, 0, -1 }, { 0x01, 0x07 }, 3, { 0x8000000, 0, 0x10002 } },
    { 0, 0xA, { 0, 0, -1 }, { 0x01, 0x07 }, 3, { 0x8000000, 0, 0x10003 } },
    { 0, 0xA, { 0, 0, -1 }, { 0x01, 0x07 }, 3, { 0x8000000, 0, 0x10004 } },
    { 0, 0x16, { 0, 0, -1 }, { 0x01, 0x07 }, 1, { 0x8000000, 0, 0x10001 } },
    { 0, 0x16, { 0, 0, -1 }, { 0x01, 0x07 }, 2, { 0x8000000, 0, 0x10001 } },
    { 0, 0x16, { 0, 0, -1 }, { 0x01, 0x07 }, 3, { 0x8000000, 0, 0x10001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 23, { 0x1000000, 0, 0x10000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 23, { 0x1000000, 0, 0x10001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 23, { 0x1000000, 0, 0x10002 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 23, { 0x1000000, 0, 0x10003 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 23, { 0x1000000, 0, 0x10004 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 23, { 0x1000000, 0, 0x10005 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 23, { 0x1000000, 0, 0x10006 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 23, { 0x1000000, 0, 0x10007 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 24, { 0x1000000, 0, 0x10000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 24, { 0x1000000, 0, 0x10001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 24, { 0x1000000, 0, 0x10002 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 24, { 0x1000000, 0, 0x10003 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 24, { 0x1000000, 0, 0x10004 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 24, { 0x1000000, 0, 0x10005 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 24, { 0x1000000, 0, 0x10006 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 24, { 0x1000000, 0, 0x10007 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 25, { 0x1000000, 0, 0x10000 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 25, { 0x1000000, 0, 0x10001 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 25, { 0x1000000, 0, 0x10002 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 25, { 0x1000000, 0, 0x10003 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 25, { 0x1000000, 0, 0x10004 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 25, { 0x1000000, 0, 0x10005 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 25, { 0x1000000, 0, 0x10006 } },
    { 0, 0x83, { 0, 0, -1 }, { 0x00, 0x07 }, 25, { 0x1000000, 0, 0x10007 } },
    { 0, 0x17, { 0, 0, -1 }, { 0x01, 0x07 }, 1, { 0x8000000, 0, 0x10005 } },
    { 0, 0x17, { 0, 0, -1 }, { 0x01, 0x07 }, 2, { 0x8000000, 0, 0x10005 } },
    { 0, 0x17, { 0, 0, -1 }, { 0x01, 0x07 }, 3, { 0x8000000, 0, 0x10005 } },
    { 0, 0x19, { 0, 0, -1 }, { 0x00, 0x07 }, 1, { 0x8000000, 0, 0x10006 } },
    { 0, 0x19, { 0, 0, -1 }, { 0x00, 0x07 }, 2, { 0x8000000, 0, 0x10006 } },
    { 0, 0x19, { 0, 0, -1 }, { 0x00, 0x07 }, 3, { 0x8000000, 0, 0x10006 } },
    { 0, 0x8, { 0, 0, -1 }, { 0x01, 0x07 }, 1, { 0x8000000, 0, 0x10007 } },
    { 0, 0x8, { 0, 0, -1 }, { 0x01, 0x07 }, 2, { 0x8000000, 0, 0x10007 } },
    { 0, 0x8, { 0, 0, -1 }, { 0x01, 0x07 }, 3, { 0x8000000, 0, 0x10007 } },
    { 0, 0x7, { 0, 0, -1 }, { 0x02, 0x07 }, 1, { 0x8000000, 0, 0x10008 } },
    { 0, 0x7, { 0, 0, -1 }, { 0x02, 0x07 }, 2, { 0x8000000, 0, 0x10008 } },
    { 0, 0x7, { 0, 0, -1 }, { 0x02, 0x07 }, 3, { 0x8000000, 0, 0x10008 } },
    { 0, 0x2, { 0, 0, -1 }, { 0x01, 0x14 }, 255, { 0x8000000, 0, 0x10000 } },
    { 0, 0x3, { 0, 0, -1 }, { 0x01, 0x07 }, 62, { 0x8000000, 0, 0x10002 } },
    { 0, 0x3, { 0, 0, -1 }, { 0x01, 0x07 }, 62, { 0x8000000, 0, 0x10001 } },
    { 0, 0x3, { 0, 0, -1 }, { 0x01, 0x07 }, 62, { 0x8000000, 0, 0x10000 } },
    { 0, 0x0, { 0, 0, -1 }, { 0x02, 0x07 }, 1, { 0x8000000, 0, 0x10000 } },
    { 0, 0x0, { 0, 0, -1 }, { 0x02, 0x07 }, 2, { 0x8000000, 0, 0x10000 } },
    { 0, 0x0, { 0, 0, -1 }, { 0x02, 0x07 }, 3, { 0x8000000, 0, 0x10000 } },
    { 3 },
};
static SpriteDesc0F10 lbl_2_data_2F5A4[9] = {
    { 0, 0xD1, { 0, 0, -1 }, { 0x01, 0x02 }, 255, { 0x1000000, 0, 0x10000 } },
    { 0, 0xD8, { 0, 0, -1 }, { 0x01, 0x02 }, 255, { 0x1000000, 0, 0x10000 } },
    { 0, 0xC0, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10000 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10005 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10004 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10003 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10002 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10001 } },
    { 3 },
};
static SpriteDesc0F10 lbl_2_data_2F6C4[8] = {
    { 0, 0xD1, { 0, 0, -1 }, { 0x01, 0x02 }, 255, { 0x1000000, 0, 0x10000 } },
    { 0, 0xD7, { 0, 0, -1 }, { 0x01, 0x02 }, 255, { 0x1000000, 0, 0x10000 } },
    { 0, 0xC0, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10000 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10004 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10003 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10002 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10001 } },
    { 3 },
};
static SpriteDesc0F10 lbl_2_data_2F7C4[6] = {
    { 0, 0xD1, { 0, 0, -1 }, { 0x01, 0x02 }, 255, { 0x1000000, 0, 0x10000 } },
    { 0, 0xD6, { 0, 0, -1 }, { 0x01, 0x02 }, 255, { 0x1000000, 0, 0x10000 } },
    { 0, 0xBF, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10000 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10002 } },
    { 0, 0xCE, { 0, 0, -1 }, { 0x01, 0x02 }, 1, { 0x1000000, 0, 0x10001 } },
    { 3 },
};
static char lbl_2_data_2F884[6][32] = {
    "FIRST",
    "CONTINUE",
    "STRONG FIRST",
    "COPY",
    "DELETE",
    "CANCEL",
};
static u8 lbl_2_data_2F944[0x20] = {
    0x00, 0x00, 0x04, 0x0B, 0x40, 0x0B, 0x2C, 0xB8, 0x18, 0xE3, 0xF0, 0x00, 0x00, 0x05, 0x34, 0x54,
    0x00, 0x00, 0x04, 0x0B, 0x40, 0x37, 0xCF, 0x5C, 0x18, 0xB3, 0xA8, 0x00, 0x00, 0x20, 0x8A, 0xF0,
};
static u8 lbl_2_data_2F964[6] = { 0, 4, 10, 2, 6, 9 };

// .text:0x0008ABFC size:0x88
void fn_2_8ABFC(void) {
    MenuTask0F10* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_2_data_2ECE4);
    fn_2_8A008(task);
    if (lbl_8034E9A0._4756 == 1) {
        lbl_2_bss_F410._50 = lbl_80361B20._F6;
    }
    ((MenuTask0F10*)lbl_803CC1B8)->_00 = fn_2_8A824;
}

// .text:0x0008A824 size:0x3D8
void fn_2_8A824(void) {
    MenuTask0F10* task = lbl_803CC1B8;
    s32 done;
    s32 total;
    s32 i;

    switch (lbl_2_bss_33FBCC._17) {
    case 0x49:
        fn_2_89038(task);
        break;
    case 0x4A:
        fn_2_88D90(task);
        break;
    case 0x4B:
        fn_2_887F8(task);
        break;
    case 0x4C:
        fn_2_883C8(task);
        break;
    case 0x4D:
        fn_2_88250(task);
        break;
    case 0x4E:
        fn_2_87FB0(task);
        break;
    case 0x4F:
        fn_2_87998(task);
        break;
    case 0x50:
        if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
            fn_2_8A008(task);
            lbl_2_bss_33FBCC._18 = 1;
            lbl_2_bss_33FBCC._19 = 1;
        }
        if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
            done = 0;
            total = 0;
            for (i = 0; i < 3; i++) {
                if (lbl_80354768._CF5E[i] != 0) {
                    if (lbl_80354768.trackers[i]._444B != -1) {
                        total++;
                        done += isAnimDone(task, i + 50, 10);
                    } else if (lbl_80354768.trackers[i]._1606 == 0) {
                        total++;
                        done += isAnimDone(task, i + 53, 14);
                    }
                }
            }
            if (done == total) {
                lbl_2_bss_33FBCC._17 = 0;
                lbl_2_bss_33FBCC._18 = 0;
                lbl_2_bss_33FBCC._19 = 0;
            }
        }
        break;
    }
    for (i = 0; i < 3; i++) {
        if (lbl_2_bss_F410._50 == i) {
            lbl_80371C30[task->_14 + 63 + i]._00->_54 |= 2;
        } else {
            lbl_80371C30[task->_14 + 63 + i]._00->_54 &= ~2;
        }
    }
    if (lbl_2_bss_33FBCC._1A != 0) {
        lbl_2_bss_33FBCC._1A = 0;
        lbl_2_bss_33FBCC._17 = 0;
        lbl_2_bss_33FBCC._18 = 0;
        lbl_2_bss_33FBCC._19 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        lbl_8034E978._3 = 0;
    }
}

// .text:0x0008A008 size:0x81C
void fn_2_8A008(MenuTask0F10* task) {
    s32 flags[3];
    s32 i;
    s32 k;
    s32 n;
    s32 face;

    memset(flags, 0, 3);
    for (i = 0; i < 3; i++) {
        if (lbl_80354768._CF5E[i] != 0) {
            lbl_80371C30[task->_14 + 4 + i]._00->_64 = 17;
            fn_800363D8(task, i + 56, 1, 5, i);
            if (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B == 0) {
                lbl_80371C30[task->_14 + 59 + i]._00->_54 |= 2;
                fn_800363D8(task, i + 59, 1, 4, lbl_80354768.trackers[i]._4416);
                lbl_80371C30[task->_14 + 59 + i]._00->_5C = 0;
                lbl_80371C30[task->_14 + 59 + i]._00->_68 = 1;
                fn_800363D8(task, i + 4, 1, 6, lbl_80354768.trackers[i]._4416);
                lbl_80371C30[task->_14 + 11 + i]._00->_54 &= ~2;
                lbl_80371C30[task->_14 + 23 + i]._00->_54 &= ~2;
                lbl_80371C30[task->_14 + 50 + i]._00->_54 &= ~2;
                lbl_80371C30[task->_14 + 53 + i]._00->_54 &= ~2;
            } else {
                lbl_80371C30[task->_14 + 59 + i]._00->_54 &= ~2;
                lbl_80371C30[task->_14 + 11 + i]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 23 + i]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 56 + i]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 50 + i]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 53 + i]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 14 + i * 3]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 15 + i * 3]._00->_54 |= 2;
                lbl_80371C30[task->_14 + 16 + i * 3]._00->_54 |= 2;
                for (k = 0; k < 6; k++) {
                    if (lbl_2_data_2F964[k] == lbl_80354768.trackers[i]._441D) {
                        face = k;
                    }
                }
                // The target stores the field back unchanged here
                lbl_80354768.trackers[i]._441D = lbl_80354768.trackers[i]._441D;
                lbl_80371C30[task->_14 + 11 + i]._00->_5C = 0;
                fn_800363D8(task, i + 11, 1, 84, face);
                lbl_80371C30[task->_14 + 11 + i]._00->_58 = (lbl_80371C30[task->_14 + 11 + i]._00->_58 & ~0xFF) | 0xFF;
                lbl_80371C30[task->_14 + 11 + i]._00->_68 = 1;
                if (lbl_80354768.trackers[i]._444B != -1) {
                    lbl_80371C30[task->_14 + 50 + i]._00->_54 |= 2;
                    lbl_80371C30[task->_14 + 50 + i]._00->_5C = 0;
                    fn_800363D8(task, i + 50, 4, 100, lbl_80354768.trackers[i]._444B);
                    lbl_80371C30[task->_14 + 50 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 53 + i]._00->_54 &= ~2;
                    lbl_80371C30[task->_14 + 53 + i]._00->_68 = 0;
                } else {
                    lbl_80371C30[task->_14 + 53 + i]._00->_54 |= 2;
                    lbl_80371C30[task->_14 + 53 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 50 + i]._00->_54 &= ~2;
                }
                fn_800363D8(task, i + 4, 1, 6, lbl_80354768.trackers[i]._4415);
                for (k = 0, n = 0; k < 9; k++) {
                    if (lbl_80354768.trackers[i]._40B8[k]._0 != lbl_80354768.trackers[i]._441D) {
                        lbl_80371C30[task->_14 + 26 + i * 8 + n]._00->_5C = lbl_80354768.trackers[i]._40B8[k]._0 << 16;
                        n++;
                    }
                }
            }
        } else {
            lbl_80371C30[task->_14 + 4 + i]._00->_64 = 1;
            lbl_80371C30[task->_14 + 4 + i]._00->_5C = 0;
            lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
            fn_800363D8(task, i + 4, 1, 6, 4);
            lbl_80371C30[task->_14 + 11 + i]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 23 + i]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 56 + i]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 50 + i]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 53 + i]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 59 + i]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 14 + i * 3]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 15 + i * 3]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 16 + i * 3]._00->_54 &= ~2;
        }
        if (lbl_2_bss_F410._50 == i) {
            lbl_80371C30[task->_14 + 63 + i]._00->_54 |= 2;
        } else {
            lbl_80371C30[task->_14 + 63 + i]._00->_54 &= ~2;
        }
    }
}

// .text:0x00089F70 size:0x98
void fn_2_89F70(void) {
    MenuTask0F10* task = lbl_803CC1B8;
    SpriteDesc0F10* desc;

    switch (lbl_2_bss_33FBCC._05) {
    case 0:
        desc = lbl_2_data_2F7C4;
        break;
    case 1:
    case 2:
        desc = lbl_2_data_2F6C4;
        break;
    case 3:
        desc = lbl_2_data_2F5A4;
        break;
    }
    fn_80034E20(task, desc);
    lbl_2_bss_33FBCC._0E = 0;
    ((MenuTask0F10*)lbl_803CC1B8)->_00 = fn_2_8975C;
}

// .text:0x0008975C size:0x814
void fn_2_8975C(void) {
    MenuTask0F10* task = lbl_803CC1B8;
    s32 count;
    s32 i;
    s32 done;
    s32 total;
    s32 a;
    s32 b;

    switch (lbl_2_bss_33FBCC._05) {
    case 0:
        count = 2;
        break;
    case 1:
    case 2:
        count = 4;
        break;
    case 3:
        count = 5;
        break;
    }
    switch (lbl_2_bss_33FBCC._22) {
    case 0x51:
        if (lbl_2_bss_33FBCC._20 == 0) {
            lbl_80371C30[task->_14 + 1]._00->_68 = 1;
            switch (lbl_2_bss_33FBCC._05) {
            case 0:
                fn_800363D8(task, 3, 1, 0xCF, 0x13);
                fn_800363D8(task, 4, 1, 0xCF, 0x18);
                break;
            case 1:
                fn_800363D8(task, 3, 1, 0xCF, 0x14);
                fn_800363D8(task, 4, 1, 0xCF, 0x16);
                fn_800363D8(task, 5, 1, 0xCF, 0x17);
                fn_800363D8(task, 6, 1, 0xCF, 0x18);
                break;
            case 2:
                fn_800363D8(task, 3, 1, 0xCF, 0x15);
                fn_800363D8(task, 4, 1, 0xCF, 0x16);
                fn_800363D8(task, 5, 1, 0xCF, 0x17);
                fn_800363D8(task, 6, 1, 0xCF, 0x18);
                break;
            case 3:
                fn_800363D8(task, 3, 1, 0xCF, 0x14);
                fn_800363D8(task, 4, 1, 0xCF, 0x15);
                fn_800363D8(task, 5, 1, 0xCF, 0x16);
                fn_800363D8(task, 6, 1, 0xCF, 0x17);
                fn_800363D8(task, 7, 1, 0xCF, 0x18);
                break;
            }
            for (i = 0; i < count; i++) {
                lbl_80371C30[task->_14 + 3 + i]._00->_68 = 1;
            }
            lbl_2_bss_33FBCC._20 = 1;
            lbl_2_bss_33FBCC._21 = 1;
        }
        if (lbl_2_bss_33FBCC._21 != 0) {
            done = 0;
            total = 0;
            for (i = 0; i < count; i++) {
                if (i == 0) {
                    total++;
                    done += isAnimDone(task, i + 3, 8);
                } else {
                    total++;
                    done += isAnimDone(task, i + 3, 3);
                }
            }
            if (done == total) {
                lbl_2_bss_33FBCC._20 = 0;
                lbl_2_bss_33FBCC._21 = 0;
                lbl_2_bss_33FBCC._22 = 0;
            }
        }
        break;
    case 0x52:
        if (lbl_2_bss_33FBCC._20 == 0) {
            lbl_80371C30[task->_14]._00->_68 = 4;
            lbl_80371C30[task->_14 + 1]._00->_68 = 4;
            for (i = 0; i < count; i++) {
                lbl_80371C30[task->_14 + 3 + i]._00->_5C = 0x30000;
                lbl_80371C30[task->_14 + 3 + i]._00->_68 = 4;
            }
            lbl_2_bss_33FBCC._20 = 1;
            lbl_2_bss_33FBCC._21 = 1;
        }
        if (lbl_2_bss_33FBCC._21 != 0 && isAnimDone(task, 1, 0) == TRUE) {
            lbl_2_bss_33FBCC._20 = 0;
            lbl_2_bss_33FBCC._21 = 0;
            lbl_2_bss_33FBCC._22 = 0;
        }
        break;
    case 0x53:
        if (lbl_2_bss_33FBCC._20 == 0) {
            a = fn_2_895F8(FALSE);
            b = fn_2_895F8(TRUE);
            lbl_80371C30[task->_14 + 3 + a]._00->_5C = 0x80000;
            lbl_80371C30[task->_14 + 3 + a]._00->_68 = 0;
            lbl_80371C30[task->_14 + 3 + b]._00->_5C = 0x30000;
            lbl_80371C30[task->_14 + 3 + b]._00->_68 = 0;
            lbl_2_bss_33FBCC._20 = 1;
            lbl_2_bss_33FBCC._21 = 1;
        }
        if (lbl_2_bss_33FBCC._21 != 0) {
            fn_2_895F8(FALSE);
            fn_2_895F8(TRUE);
            lbl_2_bss_33FBCC._20 = 0;
            lbl_2_bss_33FBCC._21 = 0;
            lbl_2_bss_33FBCC._22 = 0;
        }
        break;
    }
    if (lbl_2_bss_33FBCC._0E != 0 && lbl_2_bss_33FBCC._21 == 0) {
        lbl_2_bss_33FBCC._0E = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000895F8 size:0x164
s32 fn_2_895F8(u8 useSaved) {
    s32 result;
    s32 v = lbl_2_bss_F410._54;
    s32 saved = lbl_2_bss_33FBCC._1C;

    result = 0;
    v = useSaved ? saved : v;
    switch (lbl_2_bss_33FBCC._05) {
    case 0:
        switch (v) {
        case 0:
            result = 0;
            break;
        case 5:
            result = 1;
            break;
        }
        break;
    case 1:
        switch (v) {
        case 1:
            result = 0;
            break;
        case 3:
            result = 1;
            break;
        case 4:
            result = 2;
            break;
        case 5:
            result = 3;
            break;
        }
        break;
    case 2:
        switch (v) {
        case 2:
            result = 0;
            break;
        case 3:
            result = 1;
            break;
        case 4:
            result = 2;
            break;
        case 5:
            result = 3;
            break;
        }
        break;
    case 3:
        switch (v) {
        case 1:
            result = 0;
            break;
        case 2:
            result = 1;
            break;
        case 3:
            result = 2;
            break;
        case 4:
            result = 3;
            break;
        case 5:
            result = 4;
            break;
        }
        break;
    }
    return result;
}

// .text:0x00089038 size:0x5C0
void fn_2_89038(MenuTask0F10* task) {
    s8 digits[3];
    s32 i;
    s32 j;
    s32 done;
    s32 total;
    s32 value;

    if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                value = lbl_80354768.trackers[i]._43BC;
                digits[0] = value / 100;
                digits[1] = (value - digits[0] * 100) / 10;
                digits[2] = value - (u8)digits[0] * 100 - (u8)digits[1] * 10;
                for (j = 0; j < 3; j++) {
                    lbl_80371C30[task->_14 + 14 + i * 3 + j]._00->_54 |= 2;
                    lbl_80371C30[task->_14 + 14 + i * 3 + j]._00->_5C = 0;
                    fn_800363D8(task, 14 + i * 3 + j, 1, 13, digits[j]);
                    lbl_80371C30[task->_14 + 14 + i * 3 + j]._00->_68 = 1;
                }
                if (lbl_2_bss_F410._50 == i) {
                    lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 7 + i]._00->_64 = 19;
                    lbl_80371C30[task->_14 + 7 + i]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
                } else {
                    lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 7 + i]._00->_64 = 18;
                    lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
                    if (lbl_80354768.trackers[i]._1606 == 0 ||
                        (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B != 0)) {
                        lbl_80371C30[task->_14 + 11 + i]._00->_5C = 0x1A0000;
                        lbl_80371C30[task->_14 + 11 + i]._00->_68 = 0;
                        if (lbl_80354768.trackers[i]._444B != -1) {
                            lbl_80371C30[task->_14 + 50 + i]._00->_54 |= 2;
                            lbl_80371C30[task->_14 + 50 + i]._00->_5C = 0;
                            fn_800363D8(task, i + 50, 4, 100, lbl_80354768.trackers[i]._444B);
                            lbl_80371C30[task->_14 + 50 + i]._00->_68 = 1;
                        } else {
                            lbl_80371C30[task->_14 + 53 + i]._00->_54 &= ~2;
                            lbl_80371C30[task->_14 + 53 + i]._00->_68 = 0;
                            lbl_80371C30[task->_14 + 53 + i]._00->_54 |= 2;
                            lbl_80371C30[task->_14 + 53 + i]._00->_68 = 1;
                            lbl_80371C30[task->_14 + 50 + i]._00->_54 &= ~2;
                        }
                    }
                }
            } else if (lbl_2_bss_F410._50 == i) {
                lbl_80371C30[task->_14 + 7 + i]._00->_64 = 19;
                lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
            }
        }
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
        done = 0;
        total = 0;
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                for (j = 0; j < 3; j++) {
                    total++;
                    done += isAnimDone(task, 14 + i * 3 + j, 21);
                }
                if (lbl_80354768.trackers[i]._1606 == 0 ||
                    (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B != 0)) {
                    if (lbl_2_bss_F410._50 == i) {
                        total++;
                        done += isAnimDone(task, i + 11, 21);
                    }
                    if (lbl_80354768.trackers[i]._444B != -1) {
                        total++;
                        done += isAnimDone(task, i + 50, 10);
                    } else {
                        total++;
                        done += isAnimDone(task, i + 53, 14);
                    }
                }
            }
        }
        if (done == total) {
            lbl_2_bss_33FBCC._18 = 0;
            lbl_2_bss_33FBCC._17 = 0;
            lbl_2_bss_33FBCC._19 = 0;
        }
    }
}

// .text:0x00088D90 size:0x2A8
void fn_2_88D90(MenuTask0F10* task) {
    s32 i;
    BOOL done;

    if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        for (i = 0; i < 3; i++) {
            lbl_80371C30[task->_14 + 4 + i]._00->_68 = 4;
            if (lbl_80354768._CF5E[i] != 0) {
                lbl_80371C30[task->_14 + 14 + i * 3]._00->_68 = 4;
                lbl_80371C30[task->_14 + 15 + i * 3]._00->_68 = 4;
                lbl_80371C30[task->_14 + 16 + i * 3]._00->_68 = 4;
                lbl_80371C30[task->_14 + 56 + i]._00->_68 = 4;
                if (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B == 0) {
                    lbl_80371C30[task->_14 + 59 + i]._00->_68 = 4;
                } else {
                    lbl_80371C30[task->_14 + 23 + i]._00->_68 = 4;
                    lbl_80371C30[task->_14 + 11 + i]._00->_5C = 0x160000;
                    lbl_80371C30[task->_14 + 11 + i]._00->_68 = 4;
                    if (lbl_80354768.trackers[i]._444B != -1) {
                        lbl_80371C30[task->_14 + 50 + i]._00->_68 = 4;
                    }
                }
            }
        }
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
        done = isAnimDone(task, 0, 0);
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) == 3) {
            changeScene(3, 6);
        }
        if (done == TRUE) {
            lbl_8034E9A0._48AF = 1;
            lbl_2_bss_33FBCC._1A = 1;
            lbl_2_bss_33FBCC._17 = 0;
            lbl_2_bss_33FBCC._18 = 0;
            lbl_2_bss_33FBCC._19 = 0;
        }
    }
}

// .text:0x000887F8 size:0x598
void fn_2_887F8(MenuTask0F10* task) {
    s32 digits[3];
    s32 i;
    s32 j;
    s32 done;
    s32 total;
    s32 value;

    if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
        fn_2_8A008(task);
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                if (lbl_2_bss_F410._50 == i) {
                    value = lbl_80354768.trackers[i]._43BC;
                    digits[0] = value / 100;
                    digits[1] = (value - digits[0] * 100) / 10;
                    digits[2] = (value - digits[0] * 100) - digits[1] * 10;
                    for (j = 0; j < 3; j++) {
                        lbl_80371C30[task->_14 + 14 + i * 3 + j]._00->_54 |= 2;
                        lbl_80371C30[task->_14 + 14 + i * 3 + j]._00->_5C = 0;
                        fn_800363D8(task, 14 + i * 3 + j, 1, 13, digits[j]);
                        lbl_80371C30[task->_14 + 14 + i * 3 + j]._00->_68 = 1;
                    }
                    lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 7 + i]._00->_64 = 19;
                    lbl_80371C30[task->_14 + 7 + i]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
                } else {
                    lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 7 + i]._00->_64 = 18;
                    lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 11 + i]._00->_5C = 0x1A0000;
                    lbl_80371C30[task->_14 + 11 + i]._00->_68 = 0;
                }
                if (lbl_80354768.trackers[i]._444B != -1) {
                    lbl_80371C30[task->_14 + 50 + i]._00->_54 |= 2;
                    lbl_80371C30[task->_14 + 50 + i]._00->_5C = 0;
                    fn_800363D8(task, i + 50, 4, 100, lbl_80354768.trackers[i]._444B);
                    lbl_80371C30[task->_14 + 50 + i]._00->_68 = 1;
                } else {
                    lbl_80371C30[task->_14 + 53 + i]._00->_54 &= ~2;
                    lbl_80371C30[task->_14 + 53 + i]._00->_68 = 0;
                    lbl_80371C30[task->_14 + 53 + i]._00->_54 |= 2;
                    lbl_80371C30[task->_14 + 53 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 50 + i]._00->_54 &= ~2;
                }
            }
        }
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_5C = 0;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_68 = 1;
        lbl_80371C30[task->_14 + 4 + lbl_2_bss_F410._50]._00->_54 |= 2;
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
        done = 0;
        total = 0;
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                if (lbl_2_bss_F410._50 == i) {
                    for (j = 0; j < 3; j++) {
                        total++;
                        done += isAnimDone(task, 14 + i * 3 + j, 21);
                    }
                }
                if (lbl_80354768.trackers[i]._444B != -1) {
                    total++;
                    done += isAnimDone(task, i + 50, 10);
                } else {
                    total++;
                    done += isAnimDone(task, i + 53, 14);
                }
            }
        }
        if (done == total) {
            lbl_2_bss_33FBCC._18 = 0;
            lbl_2_bss_33FBCC._17 = 0;
            lbl_2_bss_33FBCC._19 = 0;
        }
    }
}

// .text:0x000883C8 size:0x430
void fn_2_883C8(MenuTask0F10* task) {
    s32 done;
    s32 total;
    s32 i;

    if ((lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) && lbl_2_bss_33FBCC._0D != lbl_2_bss_F410._50) {
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                if (lbl_2_bss_F410._50 == i) {
                    lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 7 + i]._00->_64 = 19;
                    lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
                    if (lbl_80354768.trackers[i]._1606 == 0 ||
                        (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B != 0)) {
                        lbl_80371C30[task->_14 + 11 + i]._00->_5C = 0x1A0000;
                        lbl_80371C30[task->_14 + 11 + i]._00->_68 = 4;
                    }
                } else if (lbl_2_bss_33FBCC._0D == i && i != lbl_2_bss_33FBCC._0F) {
                    lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 7 + i]._00->_64 = 18;
                    lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
                    if (lbl_80354768.trackers[i]._1606 == 0 ||
                        (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B != 0)) {
                        lbl_80371C30[task->_14 + 11 + i]._00->_5C = 0x160000;
                        lbl_80371C30[task->_14 + 11 + i]._00->_68 = 1;
                    }
                }
            } else if (lbl_2_bss_F410._50 == i) {
                lbl_80371C30[task->_14 + 7 + i]._00->_64 = 19;
                lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
            } else {
                lbl_80371C30[task->_14 + 7 + i]._00->_64 = 18;
                lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
            }
        }
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if ((lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) && lbl_2_bss_33FBCC._0D != lbl_2_bss_F410._50) {
        done = 0;
        total = 0;
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                if (lbl_2_bss_F410._50 == i) {
                    if (lbl_80354768.trackers[i]._1606 == 0 ||
                        (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B != 0)) {
                        total++;
                        done += isAnimDone(task, i + 11, 22);
                    }
                } else if (lbl_2_bss_33FBCC._0D == i && i != lbl_2_bss_33FBCC._0F) {
                    if (lbl_80354768.trackers[i]._1606 == 0 ||
                        (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B != 0)) {
                        total++;
                        done += isAnimDone(task, i + 11, 26);
                    }
                }
            }
        }
        if (done == total) {
            lbl_2_bss_33FBCC._0D = lbl_2_bss_F410._50;
            lbl_2_bss_33FBCC._17 = 0;
            lbl_2_bss_33FBCC._18 = 0;
            lbl_2_bss_33FBCC._19 = 0;
        }
    }
}

// .text:0x00088250 size:0x178
void fn_2_88250(MenuTask0F10* task) {
    if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._0F]._00->_64 = 20;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._0F]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._0F]._00->_5C = 0;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._0F]._00->_68 = 1;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_64 = 19;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_68 = 1;
        lbl_80371C30[task->_14 + 66 + lbl_2_bss_33FBCC._0F]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 66 + lbl_2_bss_33FBCC._0F]._00->_68 = 1;
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
        lbl_2_bss_33FBCC._17 = 0;
        lbl_2_bss_33FBCC._18 = 0;
        lbl_2_bss_33FBCC._19 = 0;
    }
}

// .text:0x00087FB0 size:0x2A0
void fn_2_87FB0(MenuTask0F10* task) {
    s32 i;
    s32 done;
    s32 total;

    if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
        fn_2_8A008(task);
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._10]._00->_64 = 18;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._10]._00->_5C = 0;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._10]._00->_68 = 1;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_64 = 18;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_68 = 1;
        lbl_80371C30[task->_14 + 4 + lbl_2_bss_33FBCC._10]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 66 + lbl_2_bss_33FBCC._10]._00->_54 &= ~2;
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._0D = lbl_2_bss_33FBCC._10;
        lbl_2_bss_F410._50 = lbl_2_bss_33FBCC._10;
        lbl_2_bss_33FBCC._10 = -1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
        done = 0;
        total = 0;
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                if (lbl_80354768.trackers[i]._444B != -1) {
                    total++;
                    done += isAnimDone(task, i + 50, 10);
                } else if (lbl_80354768.trackers[i]._1606 == 0) {
                    total++;
                    done += isAnimDone(task, i + 53, 14);
                }
            }
        }
        if (done == total) {
            lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_64 = 19;
            lbl_80371C30[task->_14 + 7 + lbl_2_bss_F410._50]._00->_68 = 1;
            lbl_2_bss_33FBCC._17 = 0;
            lbl_2_bss_33FBCC._18 = 0;
            lbl_2_bss_33FBCC._19 = 0;
        }
    }
}

// .text:0x00087998 size:0x618
void fn_2_87998(MenuTask0F10* task) {
    u8 digits[3];
    s32 done;
    s32 total;
    s32 i;
    s32 j;
    s32 value;

    if (lbl_2_bss_33FBCC._18 == 0 ? TRUE : FALSE) {
        fn_2_8A008(task);
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                if (lbl_2_bss_F410._50 == i) {
                    lbl_80371C30[task->_14 + 56 + i]._00->_54 |= 2;
                    fn_800363D8(task, i + 56, 1, 5, i);
                    value = lbl_80354768.trackers[i]._43BC;
                    digits[0] = value / 100;
                    digits[1] = (value - digits[0] * 100) / 10;
                    digits[2] = (value - digits[0] * 100) - digits[1] * 10;
                    for (j = 0; j < 3; j++) {
                        lbl_80371C30[task->_14 + 14 + i * 3 + j]._00->_54 |= 2;
                        lbl_80371C30[task->_14 + 14 + i * 3 + j]._00->_5C = 0;
                        fn_800363D8(task, 14 + i * 3 + j, 1, 13, digits[j]);
                        lbl_80371C30[task->_14 + 14 + i * 3 + j]._00->_68 = 1;
                    }
                    lbl_80371C30[task->_14 + 11 + i]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 11 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 7 + i]._00->_64 = 19;
                    lbl_80371C30[task->_14 + 7 + i]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
                } else {
                    lbl_80371C30[task->_14 + 4 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 7 + i]._00->_64 = 18;
                    lbl_80371C30[task->_14 + 7 + i]._00->_68 = 1;
                    lbl_80371C30[task->_14 + 11 + i]._00->_5C = 0x1A0000;
                    lbl_80371C30[task->_14 + 11 + i]._00->_68 = 0;
                }
                if ((lbl_80354768.trackers[i]._444B == -1 && lbl_80354768.trackers[i]._1606 == 0) ||
                    (lbl_80354768.trackers[i]._444B == -1 && lbl_80354768.trackers[i]._1606 != 0 &&
                     lbl_80354768.trackers[i]._441B != 0)) {
                    lbl_80371C30[task->_14 + 53 + i]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 53 + i]._00->_68 = 1;
                }
            }
        }
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._10]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._10]._00->_5C = 0;
        lbl_80371C30[task->_14 + 7 + lbl_2_bss_33FBCC._10]._00->_68 = 1;
        lbl_80371C30[task->_14 + 4 + lbl_2_bss_33FBCC._10]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 66 + lbl_2_bss_33FBCC._10]._00->_54 &= ~2;
        lbl_2_bss_33FBCC._10 = -1;
        lbl_2_bss_33FBCC._18 = 1;
        lbl_2_bss_33FBCC._19 = 1;
    }
    if (lbl_2_bss_33FBCC._19 == 1 ? TRUE : FALSE) {
        done = 0;
        total = 0;
        for (i = 0; i < 3; i++) {
            if (lbl_80354768._CF5E[i] != 0) {
                if (lbl_2_bss_F410._50 == i) {
                    if (lbl_80354768.trackers[i]._1606 == 0 ||
                        (lbl_80354768.trackers[i]._1606 != 0 && lbl_80354768.trackers[i]._441B != 0)) {
                        total++;
                        done += isAnimDone(task, i + 11, 21);
                    }
                    for (j = 0; j < 3; j++) {
                        total++;
                        done += isAnimDone(task, 14 + i * 3 + j, 21);
                    }
                }
                if (lbl_80354768.trackers[i]._444B != -1) {
                    total++;
                    done += isAnimDone(task, i + 50, 10);
                }
                if ((lbl_80354768.trackers[i]._444B == -1 && lbl_80354768.trackers[i]._1606 == 0) ||
                    (lbl_80354768.trackers[i]._444B == -1 && lbl_80354768.trackers[i]._1606 != 0 &&
                     lbl_80354768.trackers[i]._441B != 0)) {
                    total++;
                    done += isAnimDone(task, i + 53, 14);
                }
            }
        }
        if (done == total) {
            lbl_2_bss_33FBCC._18 = 0;
            lbl_2_bss_33FBCC._17 = 0;
            lbl_2_bss_33FBCC._19 = 0;
        }
    }
}
