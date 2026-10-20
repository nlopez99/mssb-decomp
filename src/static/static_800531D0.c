#include "static/static_800531D0.h"
#include "static/UnknownHomes_Static.h"
#include "game/UnknownHomes_Game.h"
#include "static/spani_default.h"
#include "static/static_80021188.h"
#include "static/static_80062578.h"

typedef struct ModeSelect {
    /* 0x00 */ u8 _00[0x36];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37[4];
    /* 0x3B */ s8 _3B[5];
    /* 0x40 */ s8 _40[5];
    /* 0x45 */ s8 _45[4][4];
    /* 0x55 */ s8 _55[4][4];
    /* 0x65 */ s8 _65[4];
    /* 0x69 */ s8 _69[4];
    /* 0x6D */ u8 _6D[3];
} ModeSelect; // size: 0x70

extern ModeSelect lbl_803C5F04;

extern s32 fn_80042DA8(void* task, s32 index, s32 value);

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

static inline BOOL isAnimDone(void* task, s32 id, s32 frame) {
    return fn_80042DA8(task, id, frame) != 0;
}

// .text:0x80054910 size:0x1F0
// 89.43%: the target tests the lock with subfic/cntlzw (a compare used as a
// value), branches around a one-case test of cur and copies each result (mr r7).
void fn_80054910(void* task, s32 port) {
    u8* lock = &lbl_803C66B0.rows[8].port[port];
    s8 cur;
    s8 next;
    s8 a;
    s8 b;
    BOOL done;
    BOOL waited;

    if (*lock == 1) {
        cur = lbl_803C5F04._65[port];
        next = lbl_803C5F04._69[port];
        if (cur != 0) {
            if (lbl_803C5F04._36 == 0) {
                a = lbl_803C5F04._3B[cur];
                b = lbl_803C5F04._40[next];
            } else {
                a = lbl_803C5F04._45[port][cur];
                b = lbl_803C5F04._55[port][next];
            }
        }
        done = FALSE;
        waited = FALSE;
        if (next == cur && a != b) {
            if (lbl_803C5F04._36 == 0 && cur != 0) {
                if (cur == 1) {
                    if (a != 0) {
                        waited = TRUE;
                        done = fn_80042DA8(task, 0x1A, 5) != 0;
                    } else {
                        waited = TRUE;
                        done = isAnimDone(task, 0x1A, 0x19);
                    }
                }
            } else if (lbl_803C5F04._36 == 1) {
                if (lbl_803C5F04._37[port] == 0) {
                    waited = TRUE;
                    done = isAnimDone(task, cur + port * 4 + 0x33, 0);
                } else {
                    waited = TRUE;
                    done = isAnimDone(task, cur + port * 4 + 0x33, 10);
                }
            }
        }
        if (done == waited) {
            fn_80062674(port);
            *lock = 2;
        }
    }
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
