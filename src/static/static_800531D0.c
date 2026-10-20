#include "static/static_800531D0.h"
#include "static/UnknownHomes_Static.h"
#include "game/UnknownHomes_Game.h"
#include "static/spani_default.h"
#include "static/static_80021188.h"

typedef struct MenuScreen {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} MenuScreen; // size: 0x10

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x8 - 0x1];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
} lbl_8034E978;

extern MenuScreen lbl_800FEF70[];

static inline void setScreen(s16 id) {
    lbl_8034E978._00 = id;
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._08 = lbl_800FEF70[id]._08;
}

// .text:0x800569C8 size:0x11C
void fn_800569C8(void) {
    if (g_d_GameSettings._06 == 2) {
        fn_800B0A5C_insertQueue(fn_80053FE8, 0);
        if (g_d_GameSettings.GameModeSelected == 5) {
            setScreen(0x15);
        } else {
            setScreen(7);
        }
    } else if (g_d_GameSettings.GameModeSelected == 5) {
        setScreen(0x14);
    } else {
        setScreen(6);
    }
    fn_800B0A5C_insertQueue(fn_80056120, 0x3000);
}

// .text:0x80056120 size:0x8A8
void fn_80056120(void) {
}

// .text:0x800559EC size:0x734
void fn_800559EC(void) {
}

// .text:0x80055798 size:0x254
void fn_80055798(void) {
}

// .text:0x80055374 size:0x424
void fn_80055374(void) {
}

// .text:0x80054B00 size:0x874
void fn_80054B00(void) {
}

// .text:0x80054910 size:0x1F0
void fn_80054910(void) {
}

// .text:0x800542C4 size:0x64C
void fn_800542C4(void) {
}

// .text:0x80053FE8 size:0x2DC
void fn_80053FE8(void) {
}

// .text:0x80053810 size:0x7D8
void fn_80053810(void) {
}

// .text:0x800531D0 size:0x640
void fn_800531D0(void) {
}
