#include "challenge/rep_0250.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"

typedef struct Task0250 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct Task0250* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16[0x18 - 0x16];
    /* 0x18 */ u16 _18;
    /* 0x1A */ u8 _1A;
} Task0250;

typedef struct SpriteDesc0250 {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15[3];
    /* 0x18 */ s32 _18;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
} SpriteDesc0250; // size: 0x20

typedef struct AramEntry0250 {
    /* 0x0 */ u32 _0[4];
} AramEntry0250; // size: 0x10

typedef struct Sprite0250 {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ f32 _48;
    /* 0x4C */ f32 _4C;
    /* 0x50 */ u8 _50[0x5C - 0x50];
    /* 0x5C */ s32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66;
} Sprite0250;

typedef struct SpriteSize0250 {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ s16 _14;
    /* 0x16 */ s16 _16;
} SpriteSize0250;

extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ Sprite0250* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} lbl_80371C30[];

extern struct {
    /* 0x00 */ u8 _00[0x69];
    /* 0x69 */ u8 _69;
    /* 0x6A */ u8 _6A[0xC0 - 0x6A];
} lbl_8039C3E0[];

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ u8 _0C;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ u8 _10;
} lbl_1_common_bss_47674;

extern struct {
    /* 0x00 */ s16 _00;
    /* 0x02 */ u8 _02[10];
    /* 0x0C */ u8 _0C;
} lbl_1_common_bss_47698;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

extern void fn_80034CEC(Task0250* task);
extern void fn_80034E20(Task0250* task, SpriteDesc0250* desc);
extern s32 fn_80035838(AramEntry0250* entry, u8 arg1);
extern void fn_80035A00(void);
extern void fn_80035CA4(s32 id);
extern void fn_80035ED0(s32 id);
extern void fn_80035EEC(s32 arg0, s32 id);
extern SpriteSize0250* fn_80035F20(u8 id, s32 arg1, u16 arg2, s16 arg3);
extern void fn_8003664C(u8 id, s32 arg1, u16 arg2, s32 arg3);
extern u16 fn_80036824(u8 id, s32 arg1, s32 arg2);
extern void fn_800111B4(void* arg0);
extern void fn_800AD038(void* arg0);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);

// .data
struct {
    /* 0x00 */ s32 _00[8];
    /* 0x20 */ char _20[5][0x20];
} lbl_1_data_AB0 = {
    { 0x00030000 },
    { " 2D   VIEWER", "MOVIE VIEWER", "TEST MOVIE 0", "TEST MOVIE 1", "TEST MOVIE 2" },
};

AramEntry0250 lbl_1_data_B70 = { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 };

u32 lbl_1_data_B80 = 0x10000;
static s32 lbl_1_data_B84 = 3000;

SpriteDesc0250 lbl_1_data_B88[2] = {
    { 0, 0, 0.0f, 0.0f, -1, { 1, 5 }, 0xFF, 0, { 0 }, 0, 1, 0 },
    { 3 },
};

static SpriteDesc0250 lbl_1_data_BC8[5] = {
    { 0, 0, 0.0f, 0.0f, -1, { 1, 5 }, 0xFF, 0, { 0 }, 0, 1, 0 },
    { 0, 0, 0.0f, 0.0f, -1, { 1, 5 }, 0xFF, 0, { 0 }, 0, 1, 0 },
    { 0, 0, 0.0f, 0.0f, -1, { 1, 5 }, 0xFF, 0, { 0 }, 0, 1, 0 },
    { 0, 2, 0.0f, 0.0f, -1, { 1, 5 }, 0xFF, 0, { 0 }, 0, 1, 0 },
    { 3 },
};

static SpriteDesc0250 lbl_1_data_C68[3] = {
    { 0, 5, 0.0f, 0.0f, -1, { 1, 5 }, 0xFF, 0, { 0 }, 0, 1, 0 },
    { 0, 4, 0.0f, 0.0f, -1, { 1, 5 }, 0xFF, 0, { 0 }, 0, 1, 0 },
    { 3 },
};

SpriteDesc0250 lbl_1_data_CC8[3] = {
    { 0, 8, 0.0f, 0.0f, -1, { 1, 5 }, 0xFF, 10, { 0 }, 0, 1, 0 },
    { 0, 9, 0.0f, 0.0f, -1, { 1, 5 }, 0xFF, 10, { 0 }, 0, 1, 0 },
    { 3 },
};

char lbl_1_data_D28[12][0x20] = {
    "TEX_TEST1", "TEX_TEST2", "TEX_TEST3", "TEX_TEST4", "TEX_TEST5", "TEX_TEST6",
    "TEX_TEST7", "TEX_TEST8", "TEX_TEST9", "TEX_TEST10", "TEX_TEST11", "GAME_TD",
};

static u8 lbl_1_data_EA8[0x64] = {
    0x00, 0x03, 0x0D, 0x0E, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x4C,
    0x83, 0xA4, 0x89, 0x46, 0x40, 0x02, 0x83, 0x26, 0x85, 0x98, 0x40, 0x02, 0x00, 0x7C, 0x00, 0x4D,
    0x00, 0x8A, 0x00, 0x3E, 0x00, 0x90, 0x40, 0x02, 0x82, 0x59, 0x8C, 0xC5, 0x40, 0x00, 0x00, 0x27,
    0x00, 0x36, 0x00, 0x24, 0x00, 0x27, 0x00, 0x24, 0x00, 0x36, 0x00, 0x27, 0x00, 0x36, 0x00, 0x24,
    0x00, 0x29, 0x00, 0x24, 0x00, 0x27, 0x00, 0x36, 0x00, 0x29, 0x40, 0x00, 0x00, 0x2A, 0x00, 0x27,
    0x00, 0x36, 0x00, 0x2A, 0x00, 0x29, 0x00, 0x36, 0x00, 0x2B, 0x00, 0x29, 0x00, 0x36, 0x00, 0x36,
    0x00, 0x2B, 0x40, 0x00,
};

static AramEntry0250 lbl_1_data_F0C[11] = {
    { 0x0000040B, 0x4005BDE4, 0x0EAB5000, 0x000161A0 },
    { 0x0000040B, 0x40002BDC, 0x0EACB800, 0x00001430 },
    { 0x0000040B, 0x40004E98, 0x0EACD000, 0x00001E18 },
    { 0x0000040B, 0x40011910, 0x0EACF000, 0x00006C30 },
    { 0x0000040B, 0x40006038, 0x0EAD6000, 0x0000338C },
    { 0x0000040B, 0x40006044, 0x0EAD9800, 0x00003390 },
    { 0x0000040B, 0x40004380, 0x0EADD000, 0x000018DC },
    { 0x0000040B, 0x4000124C, 0x0EADF000, 0x00000488 },
    { 0x0000040B, 0x40000478, 0x0EADF800, 0x00000208 },
    { 0x0000040B, 0x40002E6C, 0x0EAE0000, 0x00001510 },
    { 0x0000040B, 0x4000785C, 0x0EAE1800, 0x000023A8 },
};

u8 lbl_1_data_FBC[2] = { 1, 0 };
static u16 lbl_1_data_FBE = 3;

// .bss
static u8 lbl_1_bss_2FD0;
static Task0250* lbl_1_bss_2FCC;
static u8* lbl_1_bss_2FC8;
static s32 lbl_1_bss_2FC4;
static u16 lbl_1_bss_2FC0;
static s32 lbl_1_bss_2FBC;
static u16 lbl_1_bss_2FBA;
static u8 lbl_1_bss_2FB9;
static u8 lbl_1_bss_2FB8;
static s32 lbl_1_bss_2FB4;
static u16 lbl_1_bss_2FB2;
static u8 lbl_1_bss_2FB1;
static u8 lbl_1_bss_2FB0;
static u8 lbl_1_bss_2FAF;
static u8 lbl_1_bss_2FAE;
static u16 lbl_1_bss_2FAC;
static s8 lbl_1_bss_2FAA;
static u16 lbl_1_bss_2FA8;

// .text:0x00009AB0 size:0x3F0
// Differs only in registers: task takes r28 and the BC8 base r29, the target the
// reverse; locals, declaration order and fn_1_90E4's form did not change it.
void fn_1_9AB0(void) {
    Task0250* task = lbl_803CC1B8;

    switch (task->_10) {
    case 0:
        fn_800111B4(lbl_1_data_EA8);
        lbl_1_bss_2FC8 = lbl_1_data_EA8 + 4;
        fn_1_8C9C();
        task->_1A = 0;
        lbl_1_bss_2FC4 = 0;
        lbl_1_bss_2FAA = 0;
        lbl_1_bss_2FAF = 0;
        lbl_1_bss_2FB1 = 1;
        lbl_1_bss_2FD0 = 0;
        ((Task0250*)lbl_803CC1B8)->_10 = 1;
        break;
    case 1:
        if (lbl_1_bss_2FC4 > 11) {
            task->_10 = 2;
        } else if (fn_80035838(&lbl_1_data_F0C[lbl_1_bss_2FC4], lbl_1_bss_2FC4) != 0) {
            lbl_1_bss_2FC4++;
        }
        break;
    case 2:
        fn_1_97E4();
        switch (lbl_1_bss_2FAA) {
        case 0:
            if (lbl_1_bss_2FD0 == 0) {
                lbl_1_bss_2FD0 = 1;
                break;
            }
            if (lbl_1_bss_2FAF == 1) {
                if (--lbl_1_data_B84 < 0) {
                    lbl_1_data_B84 = 3000;
                }
                if (lbl_1_data_B84 % 10 == 0) {
                    fn_1_90E4(lbl_1_data_B84);
                }
            }
            lbl_1_bss_2FD0 = 2;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            if (lbl_1_bss_2FD0 == 0) {
                lbl_1_bss_2FD0 = 1;
                break;
            }
            if (lbl_1_bss_2FD0 == 1) {
                fn_1_97B8();
            }
            lbl_1_bss_2FD0 = 2;
            break;
        case 11:
            if (lbl_1_bss_2FD0 == 0) {
                lbl_1_bss_2FD0 = 1;
                break;
            }
            lbl_1_bss_2FD0 = 2;
            break;
        case 10:
            if (lbl_1_bss_2FD0 == 0) {
                lbl_1_bss_2FD0 = 1;
                break;
            }
            if (lbl_1_bss_2FD0 == 1) {
                if (lbl_1_bss_2FAF == 1 || lbl_1_bss_2FAF == 3) {
                    fn_1_90B8();
                } else {
                    fn_1_90B8();
                }
            }
            lbl_1_bss_2FD0 = 2;
            break;
        }
        break;
    }
}

// .text:0x000097E4 size:0x2CC
void fn_1_97E4(void) {
    Task0250* task = lbl_803CC1B8;

    switch (lbl_803C77B8[0]._04) {
    case 0x100:
        lbl_1_bss_2FB0 = 0;
        lbl_1_bss_2FB1 = 0;
        lbl_1_bss_2FD0 = 0;
        if (++lbl_1_bss_2FAF == 3) {
            lbl_1_bss_2FAF = 0;
        }
        if (lbl_1_bss_2FAA != 11) {
            fn_80034CEC(lbl_1_bss_2FCC);
        }
        lbl_1_bss_2FAE = 0;
        break;
    case 0x200:
        fn_80034CEC(lbl_1_bss_2FCC);
        fn_80035A00();
        fn_800AD038(lbl_80366158._08);
        task->_0C->_10 = 1;
        break;
    case 0x800:
        lbl_1_data_FBC[0] = 1;
        break;
    case 0x400:
        lbl_1_data_FBC[0] = 0;
        break;
    case 0x20:
        lbl_1_data_B80 = 0;
        break;
    case 0x1000:
        lbl_1_data_B80 = 0x10000;
        break;
    case 8:
        if (task->_1A != 0) {
            task->_1A--;
        } else {
            task->_1A = 1;
        }
        break;
    case 4:
        task->_1A++;
        if (task->_1A == 2) {
            task->_1A = 0;
        }
        break;
    case 1:
        switch (task->_1A) {
        case 0:
            lbl_1_bss_2FB8 = 0;
            lbl_1_bss_2FAA++;
            if (lbl_1_bss_2FAA >= 12) {
                lbl_1_bss_2FAA = 0;
            }
            break;
        case 1:
            lbl_1_data_B80 += 1000;
            if (lbl_1_data_B80 > 0x70000) {
                lbl_1_data_B80 = 0x70000;
            }
            break;
        }
        lbl_1_bss_2FD0 = 0;
        break;
    case 2:
        switch (task->_1A) {
        case 0:
            lbl_1_bss_2FB8 = 0;
            lbl_1_bss_2FAA--;
            if (lbl_1_bss_2FAA < 0) {
                lbl_1_bss_2FAA = 11;
            }
            break;
        case 1:
            lbl_1_data_B80 -= 1000;
            if (lbl_1_data_B80 >= (u32)-1000) {
                lbl_1_data_B80 = 0;
            }
            break;
        }
        lbl_1_bss_2FD0 = 0;
        break;
    case 3:
    case 0x10:
    case 0x40:
        break;
    }
}

// .text:0x000097B8 size:0x2C
void fn_1_97B8(void) {
    fn_800B0A5C_insertQueue(fn_1_973C, 2);
}

// .text:0x0000973C size:0x7C
void fn_1_973C(void) {
    Task0250* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_1_data_B88);
    lbl_80371C30[task->_14]._00->_66 = lbl_1_bss_2FAA;
    task->_18 = 0;
    ((Task0250*)lbl_803CC1B8)->_00 = fn_1_96D4;
}

// .text:0x000096D4 size:0x68
void fn_1_96D4(void) {
    Task0250* task = lbl_803CC1B8;
    task->_18++;
    if ((lbl_803C77B8[0]._02 & 1) || (lbl_803C77B8[0]._02 & 2)) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
    lbl_1_bss_2FB9 = lbl_1_bss_2FAA;
}

// .text:0x000096D0 size:0x4
void fn_1_96D0(void) {
}

// .text:0x000096A4 size:0x2C
void fn_1_96A4(void) {
    fn_800B0A5C_insertQueue(fn_1_9380, 2);
}

// .text:0x00009380 size:0x324
void fn_1_9380(void) {
    Task0250* task = lbl_803CC1B8;
    u8 id = lbl_1_data_BC8[0]._14;
    SpriteSize0250* size;
    s32 n;
    u16 frame;

    lbl_1_bss_2FCC = task;
    if (lbl_1_bss_2FAF == 0) {
        fn_80034E20(task, lbl_1_data_BC8);
        frame = fn_80036824(id, 1, 4);
        fn_8003664C(id, 0, frame, 2);
        fn_8003664C(id, 1, 0x11, 3);
    } else if (lbl_1_bss_2FAF == 1) {
        fn_80034E20(task, lbl_1_data_BC8);
        n = lbl_1_data_B84;
        lbl_80371C30[lbl_1_bss_2FCC->_14]._00->_5C = 0x80000;
        fn_8003664C(id, 0, n / 1000 + 10, 4);
        n %= 1000;
        lbl_80371C30[lbl_1_bss_2FCC->_14 + 1]._00->_5C = 0xC0000;
        fn_8003664C(id, 1, n / 100 + 10, 5);
        n %= 100;
        lbl_80371C30[lbl_1_bss_2FCC->_14 + 2]._00->_5C = 0x100000;
        fn_8003664C(id, 2, n / 10 + 10, 6);
    } else {
        fn_80034E20(task, lbl_1_data_C68);
        size = fn_80035F20(lbl_1_data_C68[0]._14, 1, lbl_1_bss_2FC0, -1);
        lbl_80371C30[task->_14]._00->_48 = size->_14 / 2;
        lbl_80371C30[task->_14]._00->_4C = size->_16 / 2;
        fn_80035ED0(1);
        fn_8003664C(lbl_1_data_C68[0]._14, 0, lbl_1_data_FBE, 1);
        if (++lbl_1_bss_2FC0 > 7) {
            lbl_1_bss_2FC0 = 0;
        }
        if (++lbl_1_data_FBE > 9) {
            lbl_1_data_FBE = 0;
        }
    }
    task->_18 = 0;
    ((Task0250*)lbl_803CC1B8)->_00 = fn_1_9290;
}

// .text:0x00009290 size:0xF0
void fn_1_9290(void) {
    Task0250* task = lbl_803CC1B8;

    task->_18++;
    if (lbl_1_bss_2FAF == 0) {
        fn_80035EEC(3, 0);
        fn_80035EEC(7, 1);
        fn_80035ED0(2);
    } else if (lbl_1_bss_2FAF == 1) {
        fn_80035EEC(11, 0);
        fn_80035EEC(15, 1);
        fn_80035EEC(19, 2);
    } else {
        fn_80035ED0(2);
        fn_80035ED0(3);
    }
    if (lbl_1_bss_2FB9 != lbl_1_bss_2FAA) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
    if (lbl_803C77B8[0]._02 & 0x200) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000090E4 size:0x1AC
void fn_1_90E4(s32 n) {
    fn_80034CEC(lbl_1_bss_2FCC);
    fn_80034E20(lbl_1_bss_2FCC, lbl_1_data_BC8);
    lbl_80371C30[lbl_1_bss_2FCC->_14]._00->_5C = 0x80000;
    fn_8003664C(lbl_1_data_BC8[0]._14, 0, n / 1000 + 10, 4);
    n %= 1000;
    lbl_80371C30[lbl_1_bss_2FCC->_14 + 1]._00->_5C = 0xC0000;
    fn_8003664C(lbl_1_data_BC8[0]._14, 1, n / 100 + 10, 5);
    n %= 100;
    lbl_80371C30[lbl_1_bss_2FCC->_14 + 2]._00->_5C = 0x100000;
    fn_8003664C(lbl_1_data_BC8[0]._14, 2, n / 10 + 10, 6);
}

// .text:0x000090B8 size:0x2C
void fn_1_90B8(void) {
    fn_800B0A5C_insertQueue(fn_1_8F34, 2);
}

// .text:0x00008F34 size:0x184
void fn_1_8F34(void) {
    Task0250* task = lbl_803CC1B8;
    SpriteSize0250* size;

    if (lbl_803C77B8[0]._02 & 0x200) {
        fn_80034CEC(lbl_1_bss_2FCC);
        fn_800B0A14_removeQueue();
        return;
    }
    lbl_1_bss_2FCC = task;
    fn_80034E20(task, lbl_1_data_CC8);
    if (lbl_1_bss_2FAF == 1 || lbl_1_bss_2FAF == 3) {
        size = fn_80035F20(lbl_1_data_CC8[0]._14, 1, lbl_1_bss_2FAC, lbl_1_bss_2FAC + 2);
        lbl_80371C30[task->_14]._00->_48 = size->_14;
        lbl_80371C30[task->_14]._00->_4C = size->_16;
        fn_80035ED0(1);
        if (++lbl_1_bss_2FAC > 3) {
            lbl_1_bss_2FAC = 0;
        }
    } else {
        lbl_80371C30[task->_14]._00->_64 = 7;
        fn_80035ED0(1);
        fn_80035ED0(2);
        fn_80035ED0(3);
    }
    ((Task0250*)lbl_803CC1B8)->_00 = fn_1_8DBC;
}

// .text:0x00008DBC size:0x178
void fn_1_8DBC(void) {
    Task0250* task = lbl_803CC1B8;

    task->_18++;
    if (lbl_1_bss_2FAF == 1 || lbl_1_bss_2FAF == 3) {
        if (lbl_8039C3E0[0]._69 == 1) {
            if (lbl_1_bss_2FAE == 0) {
                fn_800B0A14_removeQueue();
                lbl_1_bss_2FAE = 1;
                return;
            }
            fn_1_8CD4();
        }
        fn_80035ED0(2);
        fn_80035ED0(3);
    }
    if ((lbl_803C77B8[0]._02 & 1) || (lbl_803C77B8[0]._02 & 2)) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00008CD4 size:0xE8
void fn_1_8CD4(void) {
    SpriteSize0250* size = fn_80035F20(lbl_1_data_CC8[0]._14, 1, lbl_1_bss_2FAC, lbl_1_bss_2FAC + 2);

    lbl_80371C30[lbl_1_bss_2FCC->_14]._00->_48 = size->_14;
    lbl_80371C30[lbl_1_bss_2FCC->_14]._00->_4C = size->_16;
    fn_80035ED0(1);
    if (++lbl_1_bss_2FAC > 3) {
        lbl_1_bss_2FAC = 0;
    }
}

// .text:0x00008C9C size:0x38
void fn_1_8C9C(void) {
    s32 i;

    lbl_1_common_bss_47698._00 = 0;
    i = 10;
    do {
        lbl_1_common_bss_47698._02[i] = 0;
    } while (--i != 0);
    lbl_1_common_bss_47698._0C = 0;
}

// .text:0x00008B90 size:0x10C
void fn_1_8B90(void) {
    switch (lbl_1_common_bss_47674._00) {
    case 0:
        lbl_1_common_bss_47674._00++;
        break;
    case 1:
        fn_1_8A90();
        break;
    }
}

// .text:0x00008B8C size:0x4
void fn_1_8B8C(void) {
}

// .text:0x00008A90 size:0xFC
void fn_1_8A90(void) {
    Task0250* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._02 & 8) {
        if (--lbl_1_common_bss_47674._04 < 0) {
            lbl_1_common_bss_47674._04 = 1;
        }
    } else if (lbl_803C77B8[0]._02 & 4) {
        if (++lbl_1_common_bss_47674._04 == 2) {
            lbl_1_common_bss_47674._04 = 0;
        }
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        if (lbl_1_common_bss_47674._04 == 0) {
            task->_00 = fn_1_9AB0;
        } else {
            task->_00 = fn_1_88D0;
        }
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        lbl_1_common_bss_47674._00 = 0;
        fn_80035CA4(6);
        task->_0C->_10 = 1;
    }
}

// .text:0x000088D0 size:0x1C0
void fn_1_88D0(void) {
    switch (lbl_1_common_bss_47674._0C) {
    case 0:
        if (fn_80035838(&lbl_1_data_B70, 6) != 0) {
            lbl_1_common_bss_47674._0D = 0;
            lbl_1_common_bss_47674._10 = 3;
            lbl_1_common_bss_47674._0C++;
        }
        break;
    case 1:
        fn_1_8770();
        break;
    }
}

// .text:0x000088CC size:0x4
void fn_1_88CC(void) {
}

// .text:0x00008770 size:0x15C
void fn_1_8770(void) {
    if (lbl_803C77B8[0]._02 & 8) {
        if (--lbl_1_common_bss_47674._08 < 0) {
            lbl_1_common_bss_47674._08 = 2;
        }
    } else if (lbl_803C77B8[0]._02 & 4) {
        if (++lbl_1_common_bss_47674._08 == 3) {
            lbl_1_common_bss_47674._08 = 0;
        }
    } else if (lbl_803C77B8[0]._02 & 0x100) {
        if (lbl_1_common_bss_47674._0E == 0) {
            lbl_1_common_bss_47674._0D = 1;
            lbl_1_common_bss_47674._0E = 1;
        } else {
            lbl_1_common_bss_47674._0D = 2;
        }
        fn_1_86E4();
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        lbl_1_common_bss_47674._0C = 0;
        ((Task0250*)lbl_803CC1B8)->_00 = fn_1_8B90;
    }
}

// .text:0x000086E4 size:0x8C
void fn_1_86E4(void) {
    if (lbl_1_common_bss_47674._0D == 0) {
        return;
    }
    switch (lbl_1_common_bss_47674._08) {
    case 0:
        if (lbl_1_common_bss_47674._0F == lbl_1_common_bss_47674._10) {
            return;
        }
        lbl_1_common_bss_47674._10 = lbl_1_common_bss_47674._0F;
        lbl_1_common_bss_47674._0F = 0;
        break;
    case 1:
        lbl_1_common_bss_47674._10 = lbl_1_common_bss_47674._0F;
        lbl_1_common_bss_47674._0F = 1;
        break;
    case 2:
        lbl_1_common_bss_47674._10 = lbl_1_common_bss_47674._0F;
        lbl_1_common_bss_47674._0F = 2;
        break;
    }
    lbl_1_common_bss_47674._0D = 0;
}

// .text:0x000086BC size:0x28
void fn_1_86BC(void) {
    ((Task0250*)lbl_803CC1B8)->_18 = 0;
    ((Task0250*)lbl_803CC1B8)->_00 = fn_1_8624;
}

// .text:0x00008624 size:0x98
void fn_1_8624(void) {
    Task0250* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._02 & 0x100) {
        lbl_80371C30[task->_14]._00->_5C = 0;
        task->_18 = 0;
    }
    if (lbl_1_common_bss_47674._0F != 0 || lbl_1_common_bss_47674._0C == 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
    task->_18++;
}
