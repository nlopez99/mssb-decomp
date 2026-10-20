#include "static/orderchange.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "Dolphin/os.h"
#include "string.h"
#include "static/static_8004157C.h"
#include "static/spani_default.h"

typedef struct Scene {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u16 _04;
    /* 0x06 */ u16 _06;
    /* 0x08 */ u16 _08;
} Scene;

typedef struct Sprite {
    /* 0x00 */ u8 _00[0x5C];
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x68 - 0x60];
    /* 0x68 */ u8 _68;
} Sprite;

typedef struct SpriteRef {
    /* 0x00 */ Sprite* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} SpriteRef; // size: 0x8

typedef struct SpriteGroup {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ u16 _14;
} SpriteGroup;

struct DebugMenu;

typedef struct DebugMenuItem {
    /* 0x00 */ s32 type;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 min;
    /* 0x0C */ s32 max;
    /* 0x10 */ s32 step[3];
    /* 0x1C */ void* value;
    /* 0x20 */ u32 mask;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 (*callback)(struct DebugMenu* menu, u16 buttons);
} DebugMenuItem; // size: 0x2C

typedef struct DebugMenu {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 count;
    /* 0x08 */ s32 rows;
    /* 0x0C */ s32 top;
    /* 0x10 */ s32 cursor;
    /* 0x14 */ s32 wrap;
    /* 0x18 */ DebugMenuItem* items;
} DebugMenu;

extern Scene* lbl_803CBBCC;
extern SpriteRef lbl_80371C30[];
extern u32 lbl_803CB750;
extern u8 lbl_800EFBA4[16];

typedef struct RosterEntry {
    /* 0x00 */ u8 _00[0x1E];
    /* 0x1E */ u8 _1E[2];
    /* 0x20 */ s32 _20;
    /* 0x24 */ s16 charId;
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
    /* 0x28 */ u8 _28[2];
    /* 0x2A */ u8 _2A[2];
    /* 0x2C */ u8 _2C;
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E;
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u8 _30;
    /* 0x31 */ u8 _31;
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34;
    /* 0x35 */ u8 _35[2];
    /* 0x37 */ u8 bars[4];
    /* 0x3B */ u8 chemistry[0x36];
    /* 0x71 */ u8 _71;
    /* 0x72 */ u8 _72[2];
    /* 0x74 */ u16 _74[21];
    /* 0x9E */ u8 _9E[2];
} RosterEntry; // size: 0xA0

extern RosterEntry inMemRoster[2][9];
extern RosterEntry lbl_803C5144[2];
extern u8 lbl_80361B20[];
extern s8 lbl_800E86F0[12];

typedef struct OrderSlot {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01;
    /* 0x02 */ s8 charId;
    /* 0x03 */ u8 _03;
} OrderSlot; // size: 0x4

extern OrderSlot lbl_80354720[][9];

// The pause menu's state, inside lbl_803297E0
typedef struct PauseMenu {
    /* 0x00 */ u16 state;
    /* 0x02 */ s8 team;
    /* 0x03 */ u8 player;
    /* 0x04 */ u8 _04[2];
    /* 0x06 */ u8 _06[2];
    /* 0x08 */ u8 _08[2];
    /* 0x0A */ u8 _0A;
    /* 0x0B */ u8 _0B;
    /* 0x0C */ u8 _0C[2];
    /* 0x0E */ s8 slot[2];
    /* 0x10 */ s8 prevSlot[2];
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ u8 _14[2];
    /* 0x16 */ u8 _16[2];
    /* 0x18 */ u8 _18[2];
    /* 0x1A */ u8 _1A[2];
    /* 0x1C */ u8 _1C[2];
    /* 0x1E */ u8 _1E[2];
    /* 0x20 */ u8 _20[2];
    /* 0x22 */ u8 _22[0x27 - 0x22];
    /* 0x27 */ u8 _27;
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29[2];
    /* 0x2B */ u8 _2B[2];
    /* 0x2D */ u8 _2D[2];
    /* 0x2F */ u8 _2F[2];
    /* 0x31 */ u8 _31[0x33 - 0x31];
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34[0x38 - 0x34];
    /* 0x38 */ u8 _38;
    /* 0x39 */ u8 _39;
    /* 0x3A */ u8 _3A;
    /* 0x3B */ u8 _3B;
    /* 0x3C */ u8 _3C;
    /* 0x3D */ s8 starCursor;
    /* 0x3E */ s8 prevStarCursor;
    /* 0x3F */ u8 _3F;
    /* 0x40 */ s16 _40;
    /* 0x42 */ u8 _42[0x45 - 0x42];
    /* 0x45 */ u8 _45;
    /* 0x46 */ u8 _46[0x5A - 0x46];
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B[2];
    /* 0x5D */ s8 prevRow;
    /* 0x5E */ s8 row;
    /* 0x5F */ s8 prevStar;
    /* 0x60 */ s8 star;
    /* 0x61 */ u8 inStars;
    /* 0x62 */ u8 starCount;
    /* 0x63 */ u8 _63;
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[2];
    /* 0x68 */ u8 _68;
    /* 0x69 */ u8 _69;
    /* 0x6A */ u8 _6A[2];
} PauseMenu;

typedef struct PadButtons {
    /* 0x0 */ u16 held;
    /* 0x2 */ u16 pressed;
    /* 0x4 */ u16 repeat;
} PadButtons; // size: 0x6

extern union {
    PadButtons pads[4];
    struct {
        /* 0x00 */ u8 _00[0x18];
        /* 0x18 */ u8 swap[2][2];
    } t;
    struct {
        /* 0x0000 */ u8 _0000[0xCF38];
        /* 0xCF38 */ PauseMenu pause;
    } s;
} lbl_803297E0;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[6];
    /* 0x07 */ u8 _07[0x55 - 0x07];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[2];
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B[2];
    /* 0x5D */ u8 _5D;
} lbl_803C66B0;

extern union {
    RosterEntry roster[2][9];
    struct {
    /* 0x0000 */ u8 _0000[0x46F8];
    /* 0x46F8 */ s8 port[4];
    /* 0x46FC */ u8 _46FC[0x4705 - 0x46FC];
    /* 0x4705 */ u8 _4705;
    /* 0x4706 */ u8 _4706[0x4720 - 0x4706];
    /* 0x4720 */ s32 _4720[2];
    /* 0x4728 */ u8 _4728[0x472C - 0x4728];
    /* 0x472C */ PadButtons pads[4];
    /* 0x4744 */ u8 _4744[0x47F9 - 0x4744];
    /* 0x47F9 */ u8 _47F9[2][9][9];
    /* 0x489B */ u8 _489B[2][9];
    /* 0x48AD */ u8 _48AD;
    /* 0x48AE */ u8 _48AE;
    /* 0x48AF */ u8 _48AF;
    /* 0x48B0 */ u8 _48B0;
    /* 0x48B1 */ u8 _48B1;
    } s;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0x36];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
} lbl_803C5EA4;

typedef struct StarOrder {
    /* 0x0 */ s16 charId;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
} StarOrder; // size: 0x6

typedef struct StarChar {
    /* 0x00 */ u8 _00[5];
    /* 0x05 */ s8 kind;
    /* 0x06 */ u8 _06[0x34 - 0x06];
} StarChar; // size: 0x34

extern union {
    StarChar chars[1];
    struct {
        /* 0x0000 */ u8 _0000[0x40B8];
        /* 0x40B8 */ StarOrder order[9];
        /* 0x40EE */ u8 _40EE[0x4445 - 0x40EE];
        /* 0x4445 */ u8 _4445;
    } s;
} starMissionCompletionTracker;

extern s16 lbl_8010B42C[];

u8 lbl_802E4B14[2][9];
u8 lbl_802E4B00[2][9];

extern void characterSelectScreen(s32 team);
extern void unsure_FillRosterPositions(s32 team);
extern void SetMenuNumber(void);
extern void fn_800B0A14_removeQueue(void);
extern void fn_8004CC2C(void);
extern s32 fn_8004CA6C(u16 buttons);
extern void fn_8004D0F0(void);
extern void fn_800671FC(void);
extern void fn_80069854(void);
extern void fn_80062A74(void);
extern void fn_80021410(void);
extern void changeScene(s32 arg0, s32 arg1);

u8 lbl_803CBCD0[2][4];
u8 lbl_803CBCCC[4];
u8 lbl_803CBCC9;
u8 lbl_803CBCC8;

extern struct {
    /* 0x0 */ u8 _0[4];
    /* 0x4 */ u8 _4;
} lbl_803CBD24;

extern struct {
    /* 0x00 */ u8 _00[0x24];
    /* 0x24 */ u8 _24;
    /* 0x25 */ u8 _25;
    /* 0x26 */ u8 _26;
} lbl_8034E978;
extern void fn_800625A4(s32 arg0, s32 arg1);

extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);

// .text:0x80048BEC size:0x28
void fn_80048BEC(DebugMenu* menu) {
    s32 n = menu->rows;
    s32 i;

    if (menu->count < n) {
        n = menu->count;
    }
    for (i = n; i > 0; i--) {
    }
}

// .text:0x80048820 size:0x3CC
s32 fn_80048820(DebugMenu* menu, u16 held, u16 pressed, u16 repeat, u8 trigger) {
    s32 step = 0;
    s32 speed;
    s32 rows;
    DebugMenuItem* item;

    if (trigger >= 0x91) {
        speed = 2;
    } else if (trigger >= 0x50) {
        speed = 1;
    } else {
        speed = 0;
    }
    rows = menu->count < menu->rows ? menu->count : menu->rows;
    if (repeat & 8) {
        menu->cursor--;
        if (menu->wrap != 0) {
            if (menu->cursor < 0) {
                menu->cursor += menu->count;
                menu->top = menu->count - rows;
            }
            if (menu->cursor < menu->top) {
                menu->top = menu->cursor;
            }
        } else {
            if (menu->cursor < 0) {
                menu->cursor = 0;
            }
            if (menu->cursor < menu->top) {
                menu->top = menu->cursor;
            }
        }
    } else if (repeat & 4) {
        menu->cursor++;
        if (menu->wrap != 0) {
            if (menu->cursor >= menu->count) {
                menu->cursor -= menu->count;
                menu->top = 0;
            }
            while (menu->cursor - menu->top >= rows) {
                menu->top++;
            }
        } else {
            if (menu->cursor >= menu->count) {
                menu->cursor = menu->count - 1;
            }
            while (menu->cursor - menu->top >= rows) {
                menu->top++;
            }
        }
    } else if (repeat & 1) {
        item = &menu->items[menu->cursor];
        step = -item->step[speed];
        if (item->value != NULL) {
            switch (item->type) {
            case 2:
                step += *(s8*)item->value;
                if (step < item->min) {
                    step = item->min;
                }
                *(s8*)item->value = step;
                break;
            case 3:
            case 4:
            case 5:
                step += *(u8*)item->value;
                if (step < item->min) {
                    step = item->min;
                }
                *(u8*)item->value = step;
                break;
            case 6:
            case 7:
            case 8:
                break;
            default:
                step += *(s32*)item->value;
                if (step < item->min) {
                    step = item->min;
                }
                *(s32*)item->value = step;
                break;
            }
        }
    } else if (repeat & 2) {
        item = &menu->items[menu->cursor];
        step = item->step[speed];
        if (item->value != NULL) {
            switch (item->type) {
            case 2:
                step += *(s8*)item->value;
                if (step > item->max) {
                    step = item->max;
                }
                *(s8*)item->value = step;
                break;
            case 3:
            case 4:
            case 5:
                step += *(u8*)item->value;
                if (step > item->max) {
                    step = item->max;
                }
                *(u8*)item->value = step;
                break;
            case 6:
            case 7:
            case 8:
                break;
            default:
                step += *(s32*)item->value;
                if (step > item->max) {
                    step = item->max;
                }
                *(s32*)item->value = step;
                break;
            }
        }
    }
    item = &menu->items[menu->cursor];
    if (item->callback != NULL) {
        if (item->value != NULL) {
            if (repeat & item->mask) {
                return item->callback(menu, repeat);
            }
        } else {
            switch (item->type) {
            case 6:
                if (held & item->mask) {
                    return item->callback(menu, held);
                }
                break;
            case 7:
                if (pressed & item->mask) {
                    return item->callback(menu, pressed);
                }
                break;
            case 8:
                if (repeat & item->mask) {
                    return item->callback(menu, repeat);
                }
                break;
            }
        }
    }
    return 0;
}

// .text:0x80048764 size:0xBC
void fn_80048764(void) {
    switch (lbl_803CBBCC->_04) {
    case 0:
        if (lbl_803C66B0._55 == 0 && lbl_803C66B0._56 == 0) {
            fn_800486E0(0x1000, -1, 0);
            lbl_803CBBCC->_04++;
        }
        break;
    case 1:
        break;
    }
}

// .text:0x800486E0 size:0x84
void fn_800486E0(s32 priority, s8 team, u8 player) {
    fn_800B0A5C_insertQueue(pauseMenuSelection, priority);
    lbl_803297E0.s.pause.state = 0;
    lbl_803297E0.s.pause.team = team;
    lbl_803297E0.s.pause._0A = 0;
    if (g_d_GameSettings._06 != 2) {
        lbl_803297E0.s.pause.player = 0;
    } else {
        lbl_803297E0.s.pause.player = player;
    }
}

// .text:0x80047FE4 size:0x6FC
void pauseMenuSelection(void) {
    PadButtons pad;
    s32 i;
    u8 kind;

    switch (lbl_803297E0.s.pause.state) {
    case 0:
        fn_80047CE0();
        break;
    case 1:
        lbl_803297E0.s.pause.slot[0] = lbl_803297E0.s.pause.slot[1] = 0;
        lbl_803297E0.s.pause._12[0] = lbl_803297E0.s.pause._12[1] = 0;
        lbl_803297E0.s.pause.state++;
        break;
    case 2:
        for (i = 0; i < 2; i++) {
            fn_8004617C(i);
        }
        break;
    case 3:
        starMenuCursor();
        break;
    case 4:
        memset(&pad, 0, sizeof(pad));
        if (lbl_803C66B0._5D == 0) {
            pad.held = lbl_803297E0.pads[lbl_8034E9A0.s.port[0]].held;
            pad.pressed = lbl_803297E0.pads[lbl_8034E9A0.s.port[0]].pressed;
            pad.repeat = lbl_803297E0.pads[lbl_8034E9A0.s.port[0]].repeat;
            if (pad.pressed & 0x200) {
                lbl_803297E0.s.pause._45 = 3;
                sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                lbl_803297E0.s.pause.state = 10;
            }
        }
        break;
    case 5:
        challengeStarMenu();
        break;
    case 6:
        switch (lbl_803CBCC9) {
        case 0:
            fn_800B0A5C_insertQueue(fn_8004D0F0, 0x3000);
            lbl_803CBCC9++;
            break;
        case 1:
            switch (fn_8004CA6C(lbl_8034E9A0.s.pads[lbl_8034E9A0.s.port[lbl_803CBD24._4]].pressed)) {
            case 0:
                break;
            case 1:
                fn_8004CC2C();
                break;
            case 3:
                characterSelectScreen(0);
                characterSelectScreen(1);
                fn_800671FC();
                lbl_8034E978._26 = 1;
                changeScene(0xF, 6);
                lbl_803CBD24._4 = 0;
                lbl_803CBCC9 = 0;
                lbl_803297E0.s.pause.state = 10;
                break;
            case 2:
                fn_8004CC2C();
                break;
            case 4:
                lbl_803CBD24._4 = 0;
                lbl_803CBCC9 = 0;
                lbl_803297E0.s.pause._27 = 0;
                lbl_803297E0.s.pause.state = 2;
                break;
            }
            break;
        }
        break;
    case 10:
        if (lbl_803297E0.s.pause._27 != 0) {
            lbl_8034E9A0.s._48AD = 1;
            lbl_803C66B0._00 = 0;
            memset(lbl_803C66B0._01, 0, sizeof(lbl_803C66B0._01));
            lbl_803297E0.s.pause._16[0] = lbl_803297E0.s.pause._16[1] = lbl_803297E0.s.pause._18[0] = lbl_803297E0.s.pause._18[1] = 0;
            fn_80062A74();
            fn_80021410();
            fn_80035CA4(0xF);
            fn_80035CA4(0x12);
            fn_80035CA4(9);
            fn_80035CA4(6);
            lbl_8034E9A0.s._48AF = 1;
            lbl_8034E9A0.s._48B1 = 1;
            lbl_803297E0.s.pause._27 = 0;
            fn_80042D38(4);
        } else {
            if (lbl_8034E978._24 != 0) {
                break;
            }
            if (g_d_GameSettings.GameModeSelected == 5) {
                kind = lbl_803297E0.s.pause._6A[lbl_803297E0.s.pause.player];
                if (kind != 2 && kind != 3) {
                    for (i = 0; i < 9; i++) {
                        starMissionCompletionTracker.s.order[i].charId = inMemRoster[0][i].charId;
                        starMissionCompletionTracker.s.order[i]._2 = lbl_80354720[0][i]._01;
                        starMissionCompletionTracker.s.order[i]._3 = lbl_80354720[0][i].charId;
                        starMissionCompletionTracker.s.order[i]._4 = inMemRoster[0][i]._27 + inMemRoster[0][i]._26 * 2;
                    }
                    lbl_803297E0.s.pause._69 = 0;
                }
            }
            if (g_d_GameSettings.GameModeSelected == 5 && g_d_GameSettings._06 == 2 && lbl_803297E0.s.pause._6A[lbl_803297E0.s.pause.player] == 2 &&
                lbl_803297E0.s.pause._45 != 0) {
                break;
            }
            lbl_803297E0.s.pause._08[0] = 0;
            lbl_803297E0.s.pause._04[0] = lbl_803297E0.s.pause._04[1] = 0;
            lbl_803297E0.s.pause._16[0] = lbl_803297E0.s.pause._16[1] = lbl_803297E0.s.pause._18[0] = lbl_803297E0.s.pause._18[1] = 0;
            fn_80069854();
            if (g_d_GameSettings._06 != 2 && g_d_GameSettings.GameModeSelected == 5) {
                fn_80042D38(0xD);
            } else if (g_d_GameSettings._06 == 2) {
                if (lbl_803297E0.s.pause._6A[lbl_803297E0.s.pause.player] == 2 ||
                    lbl_803297E0.s.pause._6A[lbl_803297E0.s.pause.player] == 3 ||
                    (lbl_803C66B0._55 == 0 && lbl_803C66B0._56 == 0)) {
                    lbl_803297E0.s.pause._0A = 1;
                    lbl_803297E0.s.pause._08[0] = 0;
                } else {
                    break;
                }
            } else {
                fn_80042D38(0xC);
            }
        }
        kind = lbl_803297E0.s.pause._6A[lbl_803297E0.s.pause.player];
        if (kind != 2 && kind != 3) {
            lbl_803297E0.s.pause._0C[1] = 1;
        }
        lbl_803297E0.s.pause.state = 0;
        fn_800B0A14_removeQueue();
        break;
    case 12:
        if (lbl_803C66B0._55 == 0 && lbl_803C66B0._56 == 0) {
            memset(lbl_8034E9A0.s._489B, 0, sizeof(lbl_8034E9A0.s._489B));
            lbl_803297E0.s.pause._16[0] = lbl_803297E0.s.pause._16[1] = 0;
            lbl_803297E0.s.pause._0C[1] = 1;
            lbl_803297E0.s.pause.state = 13;
        }
        break;
    case 13:
        lbl_803297E0.s.pause.state = 0;
        lbl_803297E0.s.pause._29[0] = lbl_803297E0.s.pause._29[1] = 0;
        lbl_803297E0.s.pause._16[0] = lbl_803297E0.s.pause._16[1] = lbl_803297E0.s.pause._18[0] = lbl_803297E0.s.pause._18[1] = 0;
        lbl_803C5EA4._36 = 1;
        lbl_803C5EA4._37 = lbl_803C5EA4._38;
        lbl_803C5EA4._38 = 0;
        fn_80042D38(10);
        fn_800B0A14_removeQueue();
        break;
    case 14:
        if (lbl_803C66B0._55 == 0 && lbl_803C66B0._56 == 0) {
            lbl_803297E0.s.pause.state = 10;
        }
        break;
    }
}

// .text:0x80047CE0 size:0x304
void fn_80047CE0(void) {
    s32 i;
    u8 kind;

    lbl_8034E9A0.s._4720[0] = 0;
    lbl_8034E9A0.s._4720[1] = 0;
    for (i = 0; i < 2; i++) {
        lbl_803297E0.s.pause._1A[i] = g_d_GameSettings._06 == 2 ? TRUE : FALSE;
    }
    lbl_803297E0.s.pause._06[0] = lbl_803297E0.s.pause._06[1] = 0xFF;
    lbl_803297E0.s.pause._04[0] = lbl_803297E0.s.pause._04[1] = 0;
    lbl_803297E0.s.pause._08[1] = lbl_803297E0.s.pause._08[0] = 0;
    lbl_803297E0.s.pause._0B = 0;
    lbl_803297E0.s.pause.slot[0] = lbl_803297E0.s.pause.slot[1] = lbl_803297E0.s.pause.prevSlot[0] = lbl_803297E0.s.pause.prevSlot[1] = 0;
    lbl_803297E0.s.pause._12[0] = lbl_803297E0.s.pause._12[1] = lbl_803297E0.s.pause._14[0] = lbl_803297E0.s.pause._14[1] = 0;
    lbl_803297E0.s.pause._1A[0] = lbl_803297E0.s.pause._1A[1] = lbl_803297E0.s.pause._1C[0] = lbl_803297E0.s.pause._1C[1] = 0;
    lbl_803297E0.s.pause._16[0] = lbl_803297E0.s.pause._16[1] = 0;
    lbl_803297E0.s.pause._1E[0] = lbl_803297E0.s.pause._1E[1] = 0;
    lbl_803297E0.s.pause._20[0] = lbl_803297E0.s.pause._20[1] = 0;
    lbl_8034E9A0.s._4705 = 1;
    lbl_803C66B0._59 = 0;
    lbl_803C66B0._5A = 1;
    if (g_d_GameSettings._06 != 2) {
        if (g_d_GameSettings.GameModeSelected != 5 && lbl_803CBBCC->_06 == 10) {
            characterSelectScreen(0);
            characterSelectScreen(1);
        } else if (g_d_GameSettings.GameModeSelected == 5 && starMissionCompletionTracker.s._4445 == 0) {
            fn_800415A8();
            unsure_FillRosterPositions(1);
            characterSelectScreen(1);
        }
        lbl_803297E0.s.pause._6A[1] = 0;
        lbl_803297E0.s.pause._6A[lbl_803297E0.s.pause.player] = 0;
        lbl_803C5EA4._36 = 1;
        lbl_803C5EA4._37 = lbl_803C5EA4._38;
        lbl_803C5EA4._38 = 1;
    } else if (lbl_803297E0.s.pause._6A[lbl_803297E0.s.pause.player] == 0) {
        lbl_803297E0.s.pause._1A[0] = lbl_803297E0.s.pause._1A[1] = 1;
    } else {
        lbl_803297E0.s.pause._1A[0] = lbl_803297E0.s.pause._1A[1] = 0;
    }
    SetMenuNumber();
    if (g_d_GameSettings._06 != 2 && lbl_803CBBCC->_06 != 10 && g_d_GameSettings._10 == 0 &&
        g_d_GameSettings.GameModeSelected != 5) {
        lbl_803297E0.s.pause._0B = 1;
        lbl_803297E0.s.pause._16[0] = 1;
        fn_800625A4(0, 0x39);
        fn_800625A4(1, 0x39);
        lbl_803297E0.s.pause.state = 1;
        return;
    }
    kind = lbl_803297E0.s.pause._6A[lbl_803297E0.s.pause.player];
    if (kind != 2 && kind != 3) {
        fn_800625A4(0, 0x38);
        if (g_d_GameSettings._06 != 2) {
            fn_800625A4(1, 0x38);
        } else if (g_d_GameSettings._06 == 2) {
            fn_800625A4(1, 0x38);
        }
        lbl_803297E0.s.pause.state = 1;
    } else if (kind == 2) {
        lbl_803297E0.s.pause._45 = 1;
        lbl_803297E0.s.pause.state = 4;
    } else {
        lbl_803297E0.s.pause._5A = 1;
        lbl_803297E0.s.pause.state = 5;
    }
}

// .text:0x800471F4 size:0xAEC
static inline void CopyRoster(RosterEntry* dst, RosterEntry* src) {
    memcpy(dst->_00, src->_00, sizeof(dst->_00));
    dst->charId = src->charId;
    dst->_26 = src->_26;
    dst->_27 = src->_27;
    memcpy(dst->_28, src->_28, sizeof(dst->_28));
    memcpy(dst->_2A, src->_2A, sizeof(dst->_2A));
    dst->_2C = src->_2C;
    dst->_2D = src->_2D;
    dst->_2E = src->_2E;
    dst->_2F = src->_2F;
    dst->_30 = src->_30;
    dst->_31 = src->_31;
    dst->_32 = src->_32;
    dst->_33 = src->_33;
    dst->_34 = src->_34;
    memcpy(dst->_35, src->_35, sizeof(dst->_35));
    dst->_20 = src->_20;
    memcpy(dst->bars, src->bars, sizeof(dst->bars));
    memcpy(dst->chemistry, src->chemistry, sizeof(dst->chemistry));
    dst->_71 = src->_71;
    dst->_74[0] = src->_74[0];
    dst->_74[1] = src->_74[1];
    dst->_74[2] = src->_74[2];
    dst->_74[3] = src->_74[3];
    dst->_74[4] = src->_74[4];
    dst->_74[5] = src->_74[5];
    dst->_74[6] = src->_74[6];
    dst->_74[7] = src->_74[7];
    dst->_74[8] = src->_74[8];
    dst->_74[9] = src->_74[9];
    dst->_74[10] = src->_74[10];
    dst->_74[11] = src->_74[11];
    dst->_74[12] = src->_74[12];
    dst->_74[13] = src->_74[13];
    dst->_74[14] = src->_74[14];
    dst->_74[15] = src->_74[15];
    dst->_74[16] = src->_74[16];
    dst->_74[17] = src->_74[17];
    dst->_74[18] = src->_74[18];
    dst->_74[19] = src->_74[19];
    dst->_74[20] = src->_74[20];
}

// Draft: the target keeps the field addresses of the loops' entries in saved registers and
// on the stack
u8 fn_800471F4(u8 mode, u8 player) {
    s32 i;
    u8 tmp;

    if (mode == 0) {
        for (i = 0; i < 9; i++) {
            if (i == lbl_803297E0.s.pause.slot[player] - 1) {
                lbl_803CBCCC[player] = i;
                CopyRoster(&lbl_803C5144[player], &inMemRoster[player][lbl_803CBCCC[player]]);
                lbl_803CBCD0[player][2] = lbl_80354720[player][lbl_803CBCCC[player]].charId;
                memcpy(lbl_802E4B14[player], lbl_8034E9A0.s._47F9[player][lbl_803CBCCC[player]], 9);
                memcpy(lbl_802E4B00[player], lbl_8034E9A0.s._489B[player], 9);
            }
        }
    } else {
        for (i = 0; i < 9; i++) {
            if (i == lbl_803297E0.s.pause.slot[player] - 1) {
                if (lbl_803297E0.s.pause._1A[player] == 0) {
                    CopyRoster(&inMemRoster[player][lbl_803CBCCC[player]], &inMemRoster[player][i]);
                    lbl_80354720[player][lbl_803CBCCC[player]].charId = lbl_80354720[player][i].charId;
                    memcpy(lbl_8034E9A0.s._47F9[player][lbl_803CBCCC[player]], lbl_8034E9A0.s._47F9[player][i], 9);
                    CopyRoster(&inMemRoster[player][i], &lbl_803C5144[player]);
                    tmp = lbl_802E4B14[player][i];
                    lbl_802E4B14[player][i] = lbl_802E4B14[player][lbl_803CBCCC[player]];
                    lbl_80354720[player][i].charId = lbl_803CBCD0[player][2];
                    lbl_802E4B14[player][lbl_803CBCCC[player]] = tmp;
                    memcpy(lbl_8034E9A0.s._47F9[player][i], lbl_802E4B14[player], 9);
                    tmp = lbl_802E4B00[player][i];
                    lbl_802E4B00[player][i] = lbl_802E4B00[player][lbl_803CBCCC[player]];
                    lbl_802E4B00[player][lbl_803CBCCC[player]] = tmp;
                    memcpy(lbl_8034E9A0.s._489B[player], lbl_802E4B00[player], 9);
                    lbl_803297E0.t.swap[player][0] = lbl_803CBCCC[player];
                    lbl_803297E0.t.swap[player][1] = i;
                } else {
                    lbl_803297E0.t.swap[player][0] = lbl_803CBCCC[player];
                    lbl_80354720[player][lbl_803CBCCC[player]].charId = lbl_80354720[player][i].charId;
                    lbl_803297E0.t.swap[player][1] = i;
                    lbl_80354720[player][i].charId = lbl_803CBCD0[player][2];
                }
            }
        }
    }
    return lbl_803CBCCC[player];
}

// .text:0x8004617C size:0x1078
// The masking by 0x200 keeps the repeat buttons in r4 in the target and reloads held first
void fn_8004617C(s32 team) {
    PadButtons pad;
    s32 i;
    s32 player;
    u8 locked;
    s8 slot;

    if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
        return;
    }
    if (g_d_GameSettings._06 != 2) {
        if (g_d_GameSettings._10 == 1) {
            if (team > 1) {
                return;
            }
            player = team;
        } else if (g_d_GameSettings._10 == 0) {
            if (team != 0) {
                return;
            }
            if (lbl_803297E0.s.pause._0B == 0) {
                player = 0;
            } else {
                player = 1;
            }
        }
    } else {
        player = team;
    }
    memset(&pad, 0, sizeof(pad));
    pad.held = lbl_803297E0.s.pause.team == -1 ? lbl_8034E9A0.s.pads[team].held : lbl_803297E0.pads[team].held;
    pad.pressed = lbl_803297E0.s.pause.team == -1 ? lbl_8034E9A0.s.pads[team].pressed : lbl_803297E0.pads[team].pressed;
    pad.repeat = lbl_803297E0.s.pause.team == -1 ? lbl_8034E9A0.s.pads[team].repeat : lbl_803297E0.pads[team].repeat;
    locked = lbl_803297E0.s.pause._16[player];
    if (locked != 0) {
        pad.repeat &= 0x200;
        pad.held &= 0x200;
        pad.pressed &= 0x200;
    }
    if (pad.pressed & 0x10) {
        if (lbl_803297E0.s.pause._29[player] != 0) {
            lbl_803297E0.s.pause._29[player] = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        } else if (lbl_803297E0.s.pause.slot[player] != 0) {
            lbl_803297E0.s.pause._29[player] = 1;
            lbl_803297E0.s.pause._2D[player] = 1;
            lbl_803297E0.s.pause._2F[player] = 0;
            sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
        }
    } else if (pad.repeat & 8) {
        if (lbl_803297E0.s.pause._29[player] == 0 && (g_d_GameSettings.GameModeSelected != 5 || lbl_803297E0.s.pause._38 == 0) && locked == 0) {
            fn_80044C98(0, player);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad.repeat & 4) {
        if (lbl_803297E0.s.pause._29[player] == 0 && (g_d_GameSettings.GameModeSelected != 5 || lbl_803297E0.s.pause._38 == 0) && locked == 0) {
            fn_80044C98(1, player);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad.repeat & 1) {
        if (lbl_803297E0.s.pause._29[player] != 0) {
            if (lbl_803297E0.s.pause._2F[player] == 1) {
                lbl_803297E0.s.pause._2F[player] = 0;
                lbl_803297E0.s.pause._2B[player] = 0;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        } else if ((g_d_GameSettings.GameModeSelected != 5 || lbl_803297E0.s.pause._38 == 0) && locked == 0) {
            fn_80043880(0, player);
        }
    } else if (pad.repeat & 2) {
        if (lbl_803297E0.s.pause._29[player] != 0) {
            if (lbl_803297E0.s.pause._2F[player] == 0) {
                lbl_803297E0.s.pause._2F[player] = 1;
                lbl_803297E0.s.pause._2B[player] = 0;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        } else if ((g_d_GameSettings.GameModeSelected != 5 || lbl_803297E0.s.pause._38 == 0) && locked == 0) {
            fn_80043880(1, player);
        }
    } else if (pad.pressed & 0x20) {
        if (lbl_803297E0.s.pause._29[player] != 0) {
            lbl_803297E0.s.pause._29[player] = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            return;
        }
        if (lbl_803297E0.s.pause._6A[player] != 1 && (g_d_GameSettings.GameModeSelected != 5 || lbl_803297E0.s.pause._38 == 0) && g_d_GameSettings._06 != 2 &&
            lbl_803297E0.s.pause._1A[player] != 1) {
            lbl_803297E0.s.pause._1C[(u8)player] = lbl_803297E0.s.pause._1A[(u8)player];
            if (g_d_GameSettings._06 != 2) {
                lbl_803297E0.s.pause._12[(u8)player]++;
                if ((s8)lbl_803297E0.s.pause._12[(u8)player] > 1) {
                    lbl_803297E0.s.pause._12[(u8)player] = 1;
                }
                if (lbl_803297E0.s.pause._1A[(u8)player] != 1) {
                    lbl_803297E0.s.pause._1A[(u8)player] = 1;
                }
                fn_800625A4((u8)player, 0x3C);
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                return;
            }
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
        }
    } else if (pad.pressed & 0x40) {
        if (lbl_803297E0.s.pause._29[player] != 0) {
            lbl_803297E0.s.pause._29[player] = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            return;
        }
        if (lbl_803297E0.s.pause._6A[player] != 1 && (g_d_GameSettings.GameModeSelected != 5 || lbl_803297E0.s.pause._38 == 0) && g_d_GameSettings._06 != 2 &&
            lbl_803297E0.s.pause._1A[player] != 0) {
            lbl_803297E0.s.pause._1C[(u8)player] = lbl_803297E0.s.pause._1A[(u8)player];
            if (g_d_GameSettings._06 != 2) {
                lbl_803297E0.s.pause._12[(u8)player]--;
                if ((s8)lbl_803297E0.s.pause._12[(u8)player] < 0) {
                    lbl_803297E0.s.pause._12[(u8)player] = 0;
                }
                if (lbl_803297E0.s.pause._1A[(u8)player] != 0) {
                    lbl_803297E0.s.pause._1A[(u8)player] = 0;
                }
                fn_800625A4((u8)player, 0x3C);
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                return;
            }
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
        }
    } else if (pad.pressed & 0x400) {
        if (lbl_803297E0.s.pause._29[player] != 0) {
            lbl_803297E0.s.pause._29[player] = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            return;
        }
        if (lbl_803297E0.s.pause.slot[player] != 0 && lbl_803297E0.s.pause._6A[player] != 1 && (g_d_GameSettings.GameModeSelected != 5 || lbl_803297E0.s.pause._38 == 0) &&
            g_d_GameSettings._06 != 2 && locked == 0) {
            lbl_803297E0.s.pause._20[player] = 1;
        }
    } else if (pad.pressed & 0x800) {
        if (lbl_803297E0.s.pause._29[player] != 0) {
            lbl_803297E0.s.pause._29[player] = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            return;
        }
        slot = lbl_803297E0.s.pause.slot[player];
        if (slot != 0 && g_d_GameSettings._06 != 2) {
            if (g_d_GameSettings.GameModeSelected == 5) {
                if (lbl_803297E0.s.pause._39 == 0) {
                    lbl_803297E0.s.pause._40 = inMemRoster[0][lbl_803297E0.s.pause.slot[0] - 1].charId;
                    lbl_803297E0.s.pause._39 = 1;
                    lbl_803297E0.s.pause._3A = 1;
                    lbl_803297E0.s.pause.prevStarCursor = 0;
                    lbl_803297E0.s.pause.starCursor = 0;
                    lbl_803297E0.s.pause._3C = 1;
                    lbl_803297E0.s.pause.state = 3;
                    sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
                }
            } else if (lbl_80361B20[inMemRoster[player][slot - 1].charId] != 0 && lbl_803297E0.s.pause._66[player] == 0) {
                lbl_803297E0.s.pause._66[player] = 1;
                sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
            }
        }
    } else if (pad.pressed & 0x100) {
        if (lbl_803297E0.s.pause._29[player] != 0) {
            lbl_803297E0.s.pause._29[player] = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            return;
        }
        if (locked != 0 || lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
            return;
        }
        if (g_d_GameSettings._06 == 2 && lbl_803297E0.s.pause.slot[player] != 0 && lbl_803297E0.s.pause._6A[player] == 1) {
            sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            return;
        }
        if (g_d_GameSettings.GameModeSelected == 5 && lbl_803297E0.s.pause._38 != 0 && lbl_80361B20[0xE4] == 0) {
            lbl_803297E0.s.pause._38 = 0;
            lbl_803297E0.s.pause._33 = 1;
            fn_800625A4(0, 0x46);
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            return;
        }
        slot = lbl_803297E0.s.pause.slot[player];
        if (slot == 0) {
            if (lbl_803297E0.s.pause._16[0] != 0 && lbl_803297E0.s.pause._16[1] != 0) {
                lbl_803297E0.s.pause.state = 14;
            }
            if (lbl_803297E0.s.pause.slot[player] != 0) {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                return;
            }
            if (g_d_GameSettings._06 == 2) {
                fn_800625A4(player, 0x43);
                lbl_803297E0.s.pause.state = 14;
            } else if (g_d_GameSettings.GameModeSelected == 5) {
                fn_800625A4(0, 0x43);
                lbl_803297E0.s.pause.state = 14;
            } else if (g_d_GameSettings._10 == 0 && lbl_803297E0.s.pause._16[0] == 0) {
                if (g_d_GameSettings._06 == 2) {
                    lbl_803297E0.s.pause.state = 10;
                    fn_800625A4(player, 0x33);
                } else {
                    lbl_803297E0.s.pause._08[0] = 1;
                    lbl_803297E0.s.pause._04[player] = 0;
                    lbl_803297E0.s.pause._0B = 1;
                    lbl_803297E0.s.pause._16[0] = 1;
                    fn_800625A4(player, 0x3F);
                }
                lbl_803297E0.s.pause._16[0] = 1;
            } else if (g_d_GameSettings._10 == 0 && lbl_803297E0.s.pause._16[1] == 0) {
                lbl_803297E0.s.pause._16[1] = 1;
                if (lbl_803297E0.s.pause._16[0] != 0 && lbl_803297E0.s.pause._16[1] != 0) {
                    fn_800625A4(0, 0x43);
                    fn_800625A4(1, 0x43);
                    lbl_803297E0.s.pause.state = 14;
                }
            } else if (g_d_GameSettings._10 == 1) {
                lbl_803297E0.s.pause._16[player] = 1;
                if (lbl_803297E0.s.pause._16[0] != 0 && lbl_803297E0.s.pause._16[1] != 0) {
                    if (lbl_803297E0.s.pause._18[player ^ 1] != 0) {
                        lbl_803297E0.s.pause._16[player] = 0;
                        return;
                    }
                    fn_800625A4(0, 0x43);
                    fn_800625A4(1, 0x43);
                    lbl_803297E0.s.pause.state = 14;
                } else {
                    lbl_803297E0.s.pause._18[player] = 1;
                    fn_800625A4(player, 0x41);
                }
            }
        } else if (lbl_803297E0.s.pause._04[player] == 0) {
            lbl_803297E0.s.pause.prevSlot[player] = slot;
            lbl_803297E0.s.pause._06[player] = fn_800471F4(lbl_803297E0.s.pause._04[player], player);
            lbl_803297E0.s.pause._04[player] = 1;
            fn_800625A4(player, 0x3B);
            lbl_803CBCC8 = 1;
        } else {
            lbl_803297E0.s.pause.prevSlot[player] = slot;
            lbl_803297E0.s.pause._06[player] = fn_800471F4(lbl_803297E0.s.pause._04[player], player);
            lbl_803297E0.s.pause._04[player] = 0;
            fn_800625A4(player, 0x3B);
            lbl_803297E0.s.pause._1E[player] = 1;
        }
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    } else if (pad.pressed & 0x200) {
        if (lbl_803297E0.s.pause._29[player] != 0) {
            lbl_803297E0.s.pause._29[player] = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            return;
        }
        if (g_d_GameSettings.GameModeSelected == 5 && lbl_803297E0.s.pause._38 != 0) {
            lbl_803297E0.s.pause._38 = 0;
            lbl_803297E0.s.pause._33 = 1;
            fn_800625A4(0, 0x46);
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            return;
        }
        if (lbl_803297E0.s.pause._04[player] != 0) {
            lbl_803297E0.s.pause._16[player] = 0;
            lbl_803297E0.s.pause._04[player] = 0;
            if (lbl_803297E0.s.pause.slot[player] != lbl_803297E0.s.pause.prevSlot[player]) {
                fn_800625A4(player, 0x44);
            } else {
                lbl_803297E0.s.pause._06[player] = 0xFF;
            }
        } else if (lbl_803297E0.s.pause.slot[player] == 0) {
            if (lbl_803297E0.s.pause._04[player] != 0) {
                lbl_803297E0.s.pause._04[player] = 0;
                fn_800625A4(player, 0x3B);
            } else if (lbl_803297E0.s.pause.slot[player] != 0) {
                lbl_803297E0.s.pause._14[player] = lbl_803297E0.s.pause._12[player];
                lbl_803297E0.s.pause.slot[player] = 0;
                fn_800625A4(player, 0x3C);
            } else if (g_d_GameSettings._10 == 0 && lbl_803297E0.s.pause._0B != 0) {
                lbl_803297E0.s.pause._16[0] = 0;
                lbl_803297E0.s.pause._12[lbl_803297E0.s.pause._0B] = 0;
                lbl_803297E0.s.pause.slot[lbl_803297E0.s.pause._0B] = 0;
                lbl_803297E0.s.pause._0B = 0;
                lbl_803297E0.s.pause._08[0] = 0;
                lbl_803297E0.s.pause._12[lbl_803297E0.s.pause._0B] = 0;
                lbl_803297E0.s.pause.slot[lbl_803297E0.s.pause._0B] = 0;
                fn_800625A4(player, 0x40);
            } else if (locked != 0) {
                fn_800625A4(player, 0x42);
                lbl_803297E0.s.pause._16[player] = 0;
                lbl_803297E0.s.pause._18[player] = 0;
            } else {
                for (i = 0; i < 2; i++) {
                    lbl_803297E0.s.pause._12[i] = 0;
                    lbl_803297E0.s.pause.slot[i] = 0;
                }
                lbl_803297E0.s.pause._0B = 0;
                if (g_d_GameSettings._06 != 2) {
                    fn_800625A4(0, 0x3A);
                    fn_800625A4(1, 0x3A);
                    lbl_803297E0.s.pause.state = 12;
                } else {
                    fn_800625A4(player, 0x43);
                    lbl_803297E0.s.pause.state = 14;
                }
            }
        } else if (lbl_803297E0.s.pause.slot[player] != 0) {
            lbl_803297E0.s.pause.prevSlot[player] = lbl_803297E0.s.pause.slot[player];
            lbl_803297E0.s.pause.slot[player] = 0;
            fn_800625A4(player, 0x3E);
        } else if (lbl_803297E0.s.pause._08[0] != 0) {
            lbl_803297E0.s.pause._08[0] = 0;
            lbl_803297E0.s.pause.slot[player] = 0;
            lbl_803297E0.s.pause._16[player] = 0;
        } else if (g_d_GameSettings._06 == 2) {
            lbl_803297E0.s.pause.state = 10;
            fn_800625A4(0, 0x33);
        } else {
            lbl_803297E0.s.pause._16[player] = 0;
            lbl_803297E0.s.pause.state = 12;
            fn_800625A4(player, 0x33);
        }
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
    }
}

static inline s8 FindEmptySlot(u8 team) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (lbl_80354720[team][i].charId == 0) {
            return i + 1;
        }
    }
    OSPanic("orderchange.c", 3433, "//OZ 戻り値がありません\b");
    return 0;
}

// .text:0x80044C98 size:0x14E4
void fn_80044C98(u8 dir, u8 player) {
    lbl_803297E0.s.pause.prevSlot[player] = lbl_803297E0.s.pause.slot[player];
    if (dir == 0) {
        if (lbl_803297E0.s.pause._1A[player] == 0) {
            lbl_803297E0.s.pause.slot[player]--;
            if (lbl_803297E0.s.pause._04[player] != 0 && lbl_803297E0.s.pause.slot[player] < 1) {
                lbl_803297E0.s.pause.slot[player] = 9;
                fn_800625A4(player, 0x3B);
                return;
            }
            if (lbl_803297E0.s.pause.prevSlot[player] == 0) {
                lbl_803297E0.s.pause.slot[player] = 9;
                fn_800625A4(player, 0x3D);
                return;
            }
            if (lbl_803297E0.s.pause.slot[player] == 0) {
                fn_800625A4(player, 0x3E);
                return;
            }
            fn_800625A4(player, 0x3B);
            return;
        }
        if (lbl_803297E0.s.pause.prevSlot[player] == 0) {
            lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 1);
            fn_800625A4(player, 0x3D);
            return;
        }
        switch (lbl_80354720[player][lbl_803297E0.s.pause.slot[player] - 1].charId) {
            case 0:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 5);
                break;
            case 1:
                lbl_803297E0.s.pause.slot[player] = FindEmptySlot(player);
                break;
            case 2:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 8);
                break;
            case 3:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 7);
                break;
            case 4:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 6);
                break;
            case 5:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 7);
                break;
            case 6:
                if (lbl_803297E0.s.pause._04[player] != 0) {
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 4);
                    fn_800625A4(player, 0x3B);
                } else {
                    lbl_803297E0.s.pause.slot[player] = 0;
                    fn_800625A4(player, 0x3E);
                }
                break;
            case 8:
                if (lbl_803297E0.s.pause._04[player] != 0) {
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 2);
                    fn_800625A4(player, 0x3B);
                } else {
                    lbl_803297E0.s.pause.slot[player] = 0;
                    fn_800625A4(player, 0x3E);
                }
                break;
            case 7:
                if (lbl_803297E0.s.pause._04[player] != 0) {
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 1);
                    fn_800625A4(player, 0x3B);
                } else {
                    lbl_803297E0.s.pause.slot[player] = 0;
                    fn_800625A4(player, 0x3E);
                }
                break;
        }
        if (lbl_803297E0.s.pause.slot[player] != 0 && lbl_803297E0.s.pause.prevSlot[player] != lbl_803297E0.s.pause.slot[player]) {
            fn_800625A4(player, 0x3B);
        }
    } else {
        if (lbl_803297E0.s.pause._1A[player] == 0) {
            lbl_803297E0.s.pause.slot[player]++;
            if (lbl_803297E0.s.pause._04[player] != 0 && lbl_803297E0.s.pause.slot[player] == 10) {
                lbl_803297E0.s.pause.slot[player] = 1;
                fn_800625A4(player, 0x3B);
                return;
            }
            if (lbl_803297E0.s.pause.slot[player] == 10) {
                lbl_803297E0.s.pause.slot[player] = 0;
                fn_800625A4(player, 0x3E);
                return;
            }
            if (lbl_803297E0.s.pause.prevSlot[player] == 0) {
                fn_800625A4(player, 0x3D);
                return;
            }
            fn_800625A4(player, 0x3B);
            return;
        }
        if (lbl_803297E0.s.pause.prevSlot[player] == 0) {
            lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 7);
            fn_800625A4(player, 0x3D);
            return;
        }
        switch (lbl_80354720[player][lbl_803297E0.s.pause.slot[player] - 1].charId) {
            case 0:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 1);
                break;
            case 2:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 1);
                break;
            case 4:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 1);
                break;
            case 3:
                lbl_803297E0.s.pause.slot[player] = FindEmptySlot(player);
                break;
            case 5:
                lbl_803297E0.s.pause.slot[player] = FindEmptySlot(player);
                break;
            case 7:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 5);
                break;
            case 6:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 4);
                break;
            case 8:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 2);
                break;
            case 1:
                if (lbl_803297E0.s.pause._04[player] != 0) {
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 7);
                    fn_800625A4(player, 0x3B);
                } else {
                    lbl_803297E0.s.pause.slot[player] = 0;
                    fn_800625A4(player, 0x3E);
                }
                break;
        }
        if (lbl_803297E0.s.pause.slot[player] != 0 && lbl_803297E0.s.pause.prevSlot[player] != lbl_803297E0.s.pause.slot[player]) {
            fn_800625A4(player, 0x3B);
        }
    }
}

// .text:0x80043880 size:0x1418
void fn_80043880(u8 dir, u8 player) {
    if (lbl_803297E0.s.pause.slot[player] != 0 && (g_d_GameSettings._06 != 2 || lbl_803297E0.s.pause._1A[player] == 1) &&
        (lbl_803297E0.s.pause._1A[player] == 1 || g_d_GameSettings._06 == 2)) {
        lbl_803297E0.s.pause._14[player] = lbl_803297E0.s.pause._12[player];
        if (dir == 0) {
            if (lbl_803297E0.s.pause.slot[player] != 0 && lbl_803297E0.s.pause._1A[player] == 1) {
                lbl_803297E0.s.pause.prevSlot[player] = lbl_803297E0.s.pause.slot[player];
                switch (lbl_80354720[player][lbl_803297E0.s.pause.slot[player] - 1].charId) {
                case 0:
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 4);
                    break;
                case 1:
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 4);
                    break;
                case 2:
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 3);
                    break;
                case 3:
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 5);
                    break;
                case 7:
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 6);
                    break;
                case 8:
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 7);
                    break;
                case 4:
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 2);
                    break;
                case 5:
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 4);
                    break;
                case 6:
                    lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 8);
                    break;
                }
                if (lbl_803297E0.s.pause.prevSlot[player] != lbl_803297E0.s.pause.slot[player]) {
                    fn_800625A4(player, 0x3B);
                }
            }
        } else if (lbl_803297E0.s.pause.slot[player] == 0) {
            if (g_d_GameSettings._06 != 2) {
                lbl_803297E0.s.pause._12[player]++;
                if (lbl_803297E0.s.pause._1A[player] > 1) {
                    lbl_803297E0.s.pause._1A[player] = 1;
                }
                switch (lbl_803297E0.s.pause._1A[player]) {
                case 0:
                    lbl_803297E0.s.pause._1A[player] = 0;
                    break;
                case 1:
                    lbl_803297E0.s.pause._1A[player] = 1;
                    break;
                }
                fn_800625A4(player, 0x3C);
            } else {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
                return;
            }
        } else if (lbl_803297E0.s.pause.slot[player] != 0 && lbl_803297E0.s.pause._1A[player] == 1) {
            lbl_803297E0.s.pause.prevSlot[player] = lbl_803297E0.s.pause.slot[player];
            switch (lbl_80354720[player][lbl_803297E0.s.pause.slot[player] - 1].charId) {
            case 0:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 2);
                break;
            case 1:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 2);
                break;
            case 4:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 5);
                break;
            case 5:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 3);
                break;
            case 6:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 7);
                break;
            case 7:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 8);
                break;
            case 8:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 6);
                break;
            case 2:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 4);
                break;
            case 3:
                lbl_803297E0.s.pause.slot[player] = fn_80042598(player, 2);
                break;
            }
            if (lbl_803297E0.s.pause.prevSlot[player] != lbl_803297E0.s.pause.slot[player]) {
                fn_800625A4(player, 0x3B);
            }
        }
        if (dir == 0) {
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else {
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    }
}

// .text:0x8004338C size:0x4F4
void starMenuCursor(void) {
    PadButtons pad;
    u8 count;
    u8 single = FALSE;
    s8 kind;

    memset(&pad, 0, sizeof(pad));
    pad.held = g_d_GameSettings._06 == 2 ? lbl_803297E0.pads[lbl_8034E9A0.s.port[0]].held : lbl_8034E9A0.s.pads[0].held;
    pad.pressed = g_d_GameSettings._06 == 2 ? lbl_803297E0.pads[lbl_8034E9A0.s.port[0]].pressed : lbl_8034E9A0.s.pads[0].pressed;
    pad.repeat = g_d_GameSettings._06 == 2 ? lbl_803297E0.pads[lbl_8034E9A0.s.port[0]].repeat : lbl_8034E9A0.s.pads[0].repeat;
    kind = starMissionCompletionTracker.chars[lbl_803297E0.s.pause._64].kind;
    count = lbl_8010B42C[kind];
    if (kind == 3) {
        single = TRUE;
    }
    if (pad.repeat & 8) {
        if (!single) {
            lbl_803297E0.s.pause.prevStarCursor = lbl_803297E0.s.pause.starCursor;
            lbl_803297E0.s.pause.starCursor -= count / 2;
            if (lbl_803297E0.s.pause.starCursor < 0) {
                lbl_803297E0.s.pause.starCursor += count;
            }
            if (lbl_803297E0.s.pause.prevStarCursor != lbl_803297E0.s.pause.starCursor) {
                lbl_803297E0.s.pause._3C = 2;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        }
    } else if (pad.repeat & 4) {
        if (!single) {
            lbl_803297E0.s.pause.prevStarCursor = lbl_803297E0.s.pause.starCursor;
            lbl_803297E0.s.pause.starCursor += count / 2;
            if (lbl_803297E0.s.pause.starCursor >= count) {
                lbl_803297E0.s.pause.starCursor = lbl_803297E0.s.pause.starCursor - count;
            }
            if (lbl_803297E0.s.pause.prevStarCursor != lbl_803297E0.s.pause.starCursor) {
                lbl_803297E0.s.pause._3C = 2;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        }
    } else if (pad.repeat & 1) {
        if (!single) {
            lbl_803297E0.s.pause.prevStarCursor = lbl_803297E0.s.pause.starCursor;
            lbl_803297E0.s.pause.starCursor--;
            if (lbl_803297E0.s.pause.starCursor < 0 && lbl_803297E0.s.pause.starCursor < count / 2) {
                lbl_803297E0.s.pause.starCursor = count / 2 - 1;
            } else if (lbl_803297E0.s.pause.starCursor < count / 2 && lbl_803297E0.s.pause.starCursor >= count / 2 - 1) {
                lbl_803297E0.s.pause.starCursor = count - 1;
            }
        } else {
            lbl_803297E0.s.pause.prevStarCursor = lbl_803297E0.s.pause.starCursor;
            lbl_803297E0.s.pause.starCursor--;
            if (lbl_803297E0.s.pause.starCursor < 0) {
                lbl_803297E0.s.pause.starCursor = count - 1;
            }
        }
        if (lbl_803297E0.s.pause.prevStarCursor != lbl_803297E0.s.pause.starCursor) {
            lbl_803297E0.s.pause._3C = 2;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad.repeat & 2) {
        if (!single) {
            lbl_803297E0.s.pause.prevStarCursor = lbl_803297E0.s.pause.starCursor;
            lbl_803297E0.s.pause.starCursor++;
            if (lbl_803297E0.s.pause.starCursor > count / 2 - 1 && lbl_803297E0.s.pause.starCursor <= count / 2) {
                lbl_803297E0.s.pause.starCursor = 0;
            } else if (lbl_803297E0.s.pause.starCursor > count - 1 && lbl_803297E0.s.pause.starCursor >= count / 2) {
                lbl_803297E0.s.pause.starCursor = count / 2;
            }
        } else {
            lbl_803297E0.s.pause.prevStarCursor = lbl_803297E0.s.pause.starCursor;
            lbl_803297E0.s.pause.starCursor++;
            if (lbl_803297E0.s.pause.starCursor == count) {
                lbl_803297E0.s.pause.starCursor = 0;
            }
        }
        if (lbl_803297E0.s.pause.prevStarCursor != lbl_803297E0.s.pause.starCursor) {
            lbl_803297E0.s.pause._3C = 2;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad.pressed & 0x100 || pad.pressed & 0x200) {
        lbl_803297E0.s.pause._3C = 3;
        if (pad.pressed & 0x100) {
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        } else {
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        }
        lbl_803297E0.s.pause.state = 2;
    }
}

// .text:0x80042DE8 size:0x5A4
void challengeStarMenu(void) {
    PadButtons pad;
    u8 single = FALSE;
    s32 kind;

    memset(&pad, 0, sizeof(pad));
    if (lbl_803297E0.s.pause._5A != 0) {
        return;
    }
    pad.held = lbl_803297E0.pads[lbl_8034E9A0.s.port[0]].held;
    pad.pressed = lbl_803297E0.pads[lbl_8034E9A0.s.port[0]].pressed;
    pad.repeat = lbl_803297E0.pads[lbl_8034E9A0.s.port[0]].repeat;
    kind = (u8)starMissionCompletionTracker.chars[lbl_803297E0.s.pause._64].kind;
    if (kind == 3) {
        single = TRUE;
    }
    if (pad.repeat & 8) {
        if (lbl_803297E0.s.pause.inStars != 0) {
            if (!single) {
                lbl_803297E0.s.pause.prevStar = lbl_803297E0.s.pause.star;
                lbl_803297E0.s.pause.star -= lbl_803297E0.s.pause.starCount / 2;
                if (lbl_803297E0.s.pause.star < 0) {
                    lbl_803297E0.s.pause.star += lbl_803297E0.s.pause.starCount;
                }
                if (lbl_803297E0.s.pause.prevStar != lbl_803297E0.s.pause.star) {
                    lbl_803297E0.s.pause._5A = 4;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
            }
        } else {
            lbl_803297E0.s.pause.prevRow = lbl_803297E0.s.pause.row;
            lbl_803297E0.s.pause.row--;
            if (lbl_803297E0.s.pause.row < 0) {
                lbl_803297E0.s.pause.row = 8;
            }
            if (lbl_803297E0.s.pause.prevRow != lbl_803297E0.s.pause.row) {
                lbl_803297E0.s.pause._5A = 3;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        }
    } else if (pad.repeat & 4) {
        if (lbl_803297E0.s.pause.inStars != 0) {
            if (!single) {
                lbl_803297E0.s.pause.prevStar = lbl_803297E0.s.pause.star;
                lbl_803297E0.s.pause.star += lbl_803297E0.s.pause.starCount / 2;
                if (lbl_803297E0.s.pause.star >= lbl_803297E0.s.pause.starCount) {
                    lbl_803297E0.s.pause.star = lbl_803297E0.s.pause.star - lbl_803297E0.s.pause.starCount;
                }
                if (lbl_803297E0.s.pause.prevStar != lbl_803297E0.s.pause.star) {
                    lbl_803297E0.s.pause._5A = 4;
                    sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
                }
            }
        } else {
            lbl_803297E0.s.pause.prevRow = lbl_803297E0.s.pause.row;
            lbl_803297E0.s.pause.row++;
            if (lbl_803297E0.s.pause.row == 9) {
                lbl_803297E0.s.pause.row = 0;
            }
            if (lbl_803297E0.s.pause.prevRow != lbl_803297E0.s.pause.row) {
                lbl_803297E0.s.pause._5A = 3;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        }
    } else if (pad.repeat & 1) {
        if (lbl_803297E0.s.pause.inStars != 0) {
            if (!single) {
                lbl_803297E0.s.pause.prevStar = lbl_803297E0.s.pause.star;
                lbl_803297E0.s.pause.star--;
                if (lbl_803297E0.s.pause.star < 0 && lbl_803297E0.s.pause.star < lbl_803297E0.s.pause.starCount / 2) {
                    lbl_803297E0.s.pause.star = lbl_803297E0.s.pause.starCount / 2 - 1;
                } else if (lbl_803297E0.s.pause.star < lbl_803297E0.s.pause.starCount / 2 && lbl_803297E0.s.pause.star >= lbl_803297E0.s.pause.starCount / 2 - 1) {
                    lbl_803297E0.s.pause.star = lbl_803297E0.s.pause.starCount - 1;
                }
            } else {
                lbl_803297E0.s.pause.prevStar = lbl_803297E0.s.pause.star;
                lbl_803297E0.s.pause.star--;
                if (lbl_803297E0.s.pause.star < 0) {
                    lbl_803297E0.s.pause.star = lbl_803297E0.s.pause.starCount - 1;
                }
            }
            if (lbl_803297E0.s.pause.prevStar != lbl_803297E0.s.pause.star) {
                lbl_803297E0.s.pause._5A = 4;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        }
    } else if (pad.repeat & 2) {
        if (lbl_803297E0.s.pause.inStars != 0) {
            if (!single) {
                lbl_803297E0.s.pause.prevStar = lbl_803297E0.s.pause.star;
                lbl_803297E0.s.pause.star++;
                if (lbl_803297E0.s.pause.star > lbl_803297E0.s.pause.starCount / 2 - 1 && lbl_803297E0.s.pause.star <= lbl_803297E0.s.pause.starCount / 2) {
                    lbl_803297E0.s.pause.star = 0;
                } else if (lbl_803297E0.s.pause.star > lbl_803297E0.s.pause.starCount - 1 && lbl_803297E0.s.pause.star >= lbl_803297E0.s.pause.starCount / 2) {
                    lbl_803297E0.s.pause.star = lbl_803297E0.s.pause.starCount / 2;
                }
            } else {
                lbl_803297E0.s.pause.prevStar = lbl_803297E0.s.pause.star;
                lbl_803297E0.s.pause.star++;
                if (lbl_803297E0.s.pause.star == lbl_803297E0.s.pause.starCount) {
                    lbl_803297E0.s.pause.star = 0;
                }
            }
            if (lbl_803297E0.s.pause.prevStar != lbl_803297E0.s.pause.star) {
                lbl_803297E0.s.pause._5A = 4;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
        }
    } else if (pad.pressed & 0x100) {
        if (lbl_803297E0.s.pause.inStars == 0) {
            lbl_803297E0.s.pause.inStars ^= 1;
            lbl_803297E0.s.pause._5A = 5;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        }
    } else if (pad.pressed & 0x200) {
        if (lbl_803297E0.s.pause.inStars == 0) {
            lbl_803297E0.s.pause._5A = 2;
            lbl_803297E0.s.pause.prevStar = 0;
            lbl_803297E0.s.pause.star = 0;
            lbl_803297E0.s.pause.prevRow = 0;
            lbl_803297E0.s.pause.row = 0;
            lbl_803297E0.s.pause.state = 10;
        } else {
            lbl_803297E0.s.pause.inStars ^= 1;
            lbl_803297E0.s.pause.prevStar = 0;
            lbl_803297E0.s.pause.star = 0;
            lbl_803297E0.s.pause._5A = 6;
        }
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
    }
}

// .text:0x80042DA8 size:0x40
s32 fn_80042DA8(SpriteGroup* group, s32 index, s32 frame) {
    Sprite* sprite = lbl_80371C30[group->_14 + index]._00;

    if ((s32)(sprite->_5C >> 16) == frame) {
        sprite->_68 = 0;
        return 1;
    }
    return 0;
}

// .text:0x80042D68 size:0x40
s32 fn_80042D68(SpriteGroup* group, s32 index, s32 frame) {
    Sprite* sprite = lbl_80371C30[group->_14 + index]._00;

    if ((s32)(sprite->_5C >> 16) >= frame) {
        sprite->_68 = 0;
        return 1;
    }
    return 0;
}

// .text:0x80042D38 size:0x30
void fn_80042D38(u16 scene) {
    lbl_803CBBCC->_06 = lbl_803CBBCC->_02;
    lbl_803CBBCC->_08 = lbl_803CBBCC->_04;
    lbl_803CBBCC->_02 = scene;
    lbl_803CBBCC->_04 = 0;
}

// .text:0x80042C44 size:0xF4
void sndFXRelated(u16 id) {
    switch (id) {
    case 3:
    case 0x20:
    case 0x40:
    case 0x400:
    case 0x800:
        break;
    case 0x100:
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        break;
    case 0x200:
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        break;
    case 1:
    case 2:
    case 4:
    case 8:
        sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        break;
    }
}

// .text:0x80042BF0 size:0x54
static inline s32 Rand(void) {
    lbl_803CB750 = lbl_803CB750 * 0x5D588B65 + 1;
    return lbl_803CB750 >> 16;
}

// The target multiplies the seed before computing the range; this computes the range first
// and allocates the modulo's registers differently
s32 randRange_FUN_80042bf0(s32 min, s32 max) {
    s32 lo;

    if (min == max) {
        return min;
    }
    if (min <= max) {
        lo = min;
    } else {
        lo = max;
        max = min;
    }
    return Rand() % (max - lo + 1) + lo;
}

// .text:0x800426DC size:0x514
// The target reads charId with lhau through the entry pointer and saves r25-r31; this build
// keeps one register fewer and allocates the rest differently
void transferStatsToInMemRoster(u8 team) {
    s32 slot;
    s16* charId;
    RosterEntry* dst;
    RosterEntry* src;
    u8 t;
    u8 p;

    if (g_d_GameSettings.GameModeSelected == 5) {
        return;
    }
    slot = lbl_803297E0.s.pause.slot[team] - 1;
    if (lbl_80361B20[inMemRoster[team][slot].charId] == 0) {
        return;
    }
    lbl_8034E9A0.s._4720[team]++;
    if (lbl_8034E9A0.s._4720[team] == 2) {
        lbl_8034E9A0.s._4720[team] = 0;
    }
    if (g_d_GameSettings.GameModeSelected != 5) {
        lbl_8034E9A0.s._489B[team][slot] ^= 1;
        memcpy(lbl_802E4B00[team], lbl_8034E9A0.s._489B[team], 9);
    } else {
        lbl_8034E9A0.s._489B[0][slot] = 1;
    }
    if (lbl_8034E9A0.s._489B[team][slot] != 0) {
        dst = &inMemRoster[team][slot];
        dst->_28[0] += lbl_800E86F0[0];
        dst->_28[1] += lbl_800E86F0[1];
        dst->_2A[0] += lbl_800E86F0[2];
        dst->_2A[1] += lbl_800E86F0[3];
        dst->_2F += lbl_800E86F0[5];
        dst->_30 += lbl_800E86F0[6];
        dst->_2C += lbl_800E86F0[4];
        dst->_00[0] += lbl_800E86F0[7];
        dst->_00[1] += lbl_800E86F0[8];
        dst->_00[2] += lbl_800E86F0[9];
        dst->_00[3] += lbl_800E86F0[10];
        dst->_00[4] += lbl_800E86F0[11];
        dst->bars[0] += 2;
        if (dst->bars[0] > 10) {
            dst->bars[0] = 10;
        }
        inMemRoster[team][slot].bars[1] += 2;
        if (inMemRoster[team][slot].bars[1] > 10) {
            inMemRoster[team][slot].bars[1] = 10;
        }
        inMemRoster[team][slot].bars[2] += 2;
        if (inMemRoster[team][slot].bars[2] > 10) {
            inMemRoster[team][slot].bars[2] = 10;
        }
        inMemRoster[team][slot].bars[3] += 2;
        if (inMemRoster[team][slot].bars[3] > 10) {
            inMemRoster[team][slot].bars[3] = 10;
        }
    } else {
        dst = &inMemRoster[team][slot];
        charId = &inMemRoster[team][slot].charId;
        t = *charId / 9;
        p = *charId % 9;
        src = &lbl_8034E9A0.roster[t][p];
        memcpy(dst->_00, src->_00, sizeof(dst->_00));
        *charId = lbl_8034E9A0.roster[t][p].charId;
        inMemRoster[team][slot]._26 = lbl_8034E9A0.roster[t][p]._26;
        inMemRoster[team][slot]._27 = lbl_8034E9A0.roster[t][p]._27;
        memcpy(dst->_28, src->_28, sizeof(dst->_28));
        memcpy(dst->_2A, src->_2A, sizeof(dst->_2A));
        inMemRoster[team][slot]._2C = lbl_8034E9A0.roster[t][p]._2C;
        inMemRoster[team][slot]._2D = lbl_8034E9A0.roster[t][p]._2D;
        inMemRoster[team][slot]._2E = lbl_8034E9A0.roster[t][p]._2E;
        inMemRoster[team][slot]._2F = lbl_8034E9A0.roster[t][p]._2F;
        inMemRoster[team][slot]._30 = lbl_8034E9A0.roster[t][p]._30;
        inMemRoster[team][slot]._31 = lbl_8034E9A0.roster[t][p]._31;
        inMemRoster[team][slot]._32 = lbl_8034E9A0.roster[t][p]._32;
        inMemRoster[team][slot]._33 = lbl_8034E9A0.roster[t][p]._33;
        inMemRoster[team][slot]._34 = lbl_8034E9A0.roster[t][p]._34;
        memcpy(dst->_35, src->_35, sizeof(dst->_35));
        inMemRoster[team][slot]._20 = lbl_8034E9A0.roster[t][p]._20;
        memcpy(dst->bars, src->bars, sizeof(dst->bars));
        memcpy(dst->chemistry, src->chemistry, sizeof(dst->chemistry));
        inMemRoster[team][slot]._71 = lbl_8034E9A0.roster[t][p]._71;
        inMemRoster[team][slot]._74[0] = lbl_8034E9A0.roster[t][p]._74[0];
        inMemRoster[team][slot]._74[1] = lbl_8034E9A0.roster[t][p]._74[1];
        inMemRoster[team][slot]._74[2] = lbl_8034E9A0.roster[t][p]._74[2];
        inMemRoster[team][slot]._74[3] = lbl_8034E9A0.roster[t][p]._74[3];
        inMemRoster[team][slot]._74[4] = lbl_8034E9A0.roster[t][p]._74[4];
        inMemRoster[team][slot]._74[5] = lbl_8034E9A0.roster[t][p]._74[5];
        inMemRoster[team][slot]._74[6] = lbl_8034E9A0.roster[t][p]._74[6];
        inMemRoster[team][slot]._74[7] = lbl_8034E9A0.roster[t][p]._74[7];
        inMemRoster[team][slot]._74[8] = lbl_8034E9A0.roster[t][p]._74[8];
        inMemRoster[team][slot]._74[9] = lbl_8034E9A0.roster[t][p]._74[9];
        inMemRoster[team][slot]._74[10] = lbl_8034E9A0.roster[t][p]._74[10];
        inMemRoster[team][slot]._74[11] = lbl_8034E9A0.roster[t][p]._74[11];
        inMemRoster[team][slot]._74[12] = lbl_8034E9A0.roster[t][p]._74[12];
        inMemRoster[team][slot]._74[13] = lbl_8034E9A0.roster[t][p]._74[13];
        inMemRoster[team][slot]._74[14] = lbl_8034E9A0.roster[t][p]._74[14];
        inMemRoster[team][slot]._74[15] = lbl_8034E9A0.roster[t][p]._74[15];
        inMemRoster[team][slot]._74[16] = lbl_8034E9A0.roster[t][p]._74[16];
        inMemRoster[team][slot]._74[17] = lbl_8034E9A0.roster[t][p]._74[17];
        inMemRoster[team][slot]._74[18] = lbl_8034E9A0.roster[t][p]._74[18];
        inMemRoster[team][slot]._74[19] = lbl_8034E9A0.roster[t][p]._74[19];
        inMemRoster[team][slot]._74[20] = lbl_8034E9A0.roster[t][p]._74[20];
    }
}

// .text:0x80042598 size:0x144
s32 fn_80042598(u8 team, s32 charId) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (charId == lbl_80354720[team][i].charId) {
            return i + 1;
        }
    }
    OSPanic("orderchange.c", 3433, "//OZ 戻り値がありません\b");
    return 0;
}
