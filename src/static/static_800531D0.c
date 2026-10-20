#include "static/static_800531D0.h"
#include "static/UnknownHomes_Static.h"
#include "game/UnknownHomes_Game.h"
#include "static/spani_default.h"
#include "static/static_80021188.h"
#include "static/static_80062578.h"

typedef struct SpaniColor {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 a;
} SpaniColor;

typedef struct SpaniObj {
    /* 0x00 */ struct SpaniObj* parent;
    /* 0x04 */ struct SpaniObj* next;
    /* 0x08 */ struct SpaniObj* child;
    /* 0x0C */ Mtx mtx;
    /* 0x3C */ Vec _3C;
    /* 0x48 */ Vec _48;
    /* 0x54 */ u32 _54;
    /* 0x58 */ SpaniColor color;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ s32 _60;
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66; // index into lbl_803C4BE0
    /* 0x67 */ u8 _67;
    /* 0x68 */ u8 _68;
    /* 0x69 */ u8 _69;
    /* 0x6A */ u8 _6A[0x6C - 0x6A];
    /* 0x6C */ f32 _6C;
    /* 0x70 */ u8 _70;
    /* 0x71 */ u8 _71;
    /* 0x72 */ s16 _72;
    union {
        /* 0x74 */ SpaniColor _74;
        /* 0x74 */ u32 _74_rgba;
    };
    /* 0x78 */ Mtx _78;
    /* 0xA8 */ u8 _A8;
    /* 0xA9 */ u8 _A9[0xAC - 0xA9];
    /* 0xAC */ u16 _AC[10];
} SpaniObj; // size: 0xC0

typedef struct SpaniTask {
    /* 0x00 */ void (*func)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14; // first slot in lbl_80371C30
    /* 0x16 */ u16 _16; // slot count
} SpaniTask;

typedef struct SpaniSlot {
    /* 0x0 */ SpaniObj* obj;
    /* 0x4 */ SpaniTask* task;
} SpaniSlot; // size: 0x8

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
extern SpaniSlot lbl_80371C30[];

static inline SpaniObj* getSpaniObj(SpaniTask* task, s32 id) {
    return lbl_80371C30[task->_14 + id].obj;
}


extern s32 fn_80042DA8(void* task, s32 index, s32 value);

typedef struct MenuScreen {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u16 _0A;
    /* 0x0C */ u16 _0C;
    /* 0x0E */ u16 _0E;
} MenuScreen; // size: 0x10

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x8 - 0x1];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ s8 _0A[10];
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16[10];
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21[0x23 - 0x21];
    /* 0x23 */ u8 _23;
} lbl_8034E978;

extern s32 fn_8000FA9C(s32 id);

extern MenuScreen lbl_800FEF70[];

static inline SpaniObj* getTeamObj(SpaniTask* task, s32 offset, s32 id) {
    return lbl_80371C30[task->_14 + id + offset].obj;
}

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
void fn_80055798(SpaniTask* task, s32 port) {
    s32 i;

    if (isLockState(lbl_803C66B0.rows[8].port[port], 0)) {
        if (lbl_803C5F04._36 == 0) {
            if (lbl_803C5F04._3B[1] == 1) {
                lbl_80371C30[task->_14 + 0x1A].obj->_68 = 1;
            } else {
                getSpaniObj(task, 0x1A)->_5C = 0x1E0000;
                getSpaniObj(task, 0x1A)->_68 = 4;
            }
            lbl_80371C30[task->_14 + 0x6].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0xB].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0x1B].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0x1C].obj->_68 = 1;
            for (i = 0; i < 3; i++) {
                getSpaniObj(task, i + 0x20)->_68 = 1;
            }
            if (g_d_GameSettings._06 != 2 && g_d_GameSettings.GameModeSelected == 5) {
                getSpaniObj(task, 0x57)->_5C = 0x1E0000;
                getSpaniObj(task, 0x57)->_68 = 4;
            }
        } else {
            lbl_80371C30[task->_14 + 0x26].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0x29].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0x2A].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0x6].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0xB].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0x1B].obj->_68 = 1;
        }
        lbl_80371C30[task->_14 + 0x58].obj->_68 = 1;
        fn_800626EC(port);
        lbl_803C66B0.rows[8].port[port] = 1;
    }
}

static inline void animRowSelection(SpaniTask* task, u8 row, s8 sel) {
    switch (row) {
    case 1:
        lbl_80371C30[task->_14 + 0xC + sel].obj->_64 = 0x107;
        lbl_80371C30[task->_14 + 0xC + sel].obj->_5C = 10 << 16;
        lbl_80371C30[task->_14 + 0xC + sel].obj->_68 = 4;
        break;
    case 2:
        lbl_80371C30[task->_14 + 0xE + (sel ^ 1)].obj->_64 = 0x107;
        lbl_80371C30[task->_14 + 0xE + (sel ^ 1)].obj->_5C = 10 << 16;
        lbl_80371C30[task->_14 + 0xE + (sel ^ 1)].obj->_68 = 4;
        break;
    case 3:
        lbl_80371C30[task->_14 + 0x10 + sel].obj->_64 = 0x109;
        lbl_80371C30[task->_14 + 0x10 + sel].obj->_5C = 10 << 16;
        lbl_80371C30[task->_14 + 0x10 + sel].obj->_68 = 4;
        break;
    case 4:
        lbl_80371C30[task->_14 + 0x15 + (sel ^ 1)].obj->_64 = 0x107;
        lbl_80371C30[task->_14 + 0x15 + (sel ^ 1)].obj->_5C = 10 << 16;
        lbl_80371C30[task->_14 + 0x15 + (sel ^ 1)].obj->_68 = 4;
        break;
    }
}

// .text:0x80055374 size:0x424
void fn_80055374(SpaniTask* task, s32 port) {
    s8 id;
    s8 next;
    s32 i;

    if (isLockState(lbl_803C66B0.rows[8].port[port], 0)) {
        id = 0x15;
        if (g_d_GameSettings.GameModeSelected != 5) {
            id = 7;
        }
        setScreen(id);
        lbl_80371C30[task->_14 + 0x26].obj->_68 = 1;
        lbl_80371C30[task->_14 + 0x29].obj->_68 = 1;
        lbl_80371C30[task->_14 + 0x2A].obj->_68 = 1;
        next = lbl_803C5F04._69[port];
        lbl_803C5F04._69[port] = 0;
        getTeamObj(task, next, 1)->_5C = 0;
        getTeamObj(task, next, 1)->_68 = 0;
        animRowSelection(task, next, lbl_803C5F04._3B[(u8)next]);
        getSpaniObj(task, 0)->_5C = 10 << 16;
        getSpaniObj(task, 0)->_68 = 4;
        for (i = 0; i < 2; i++) {
            if (g_d_GameSettings._10 != 0 || i == 0) {
                lbl_80371C30[task->_14 + 0x2B + lbl_803C5F04._65[i] + i * 4].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x3F + lbl_803C5F04._65[i] * 2 + i].obj->_68 = 1;
            }
        }
        lbl_80371C30[task->_14 + 0xB].obj->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x58].obj->_68 = 1;
        fn_800626EC(port);
        lbl_803C66B0.rows[8].port[port] = 1;
    }
}

// .text:0x80054B00 size:0x874
void fn_80054B00(SpaniTask* task, s32 port) {
    s8 cur;
    s8 next;
    s8 a;
    s8 b;

    if (isLockState(lbl_803C66B0.rows[8].port[port], 0)) {
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
        } else if (lbl_803C5F04._36 == 1) {
            a = lbl_803C5F04._45[port][cur];
            b = lbl_803C5F04._55[port][next];
        }
        if (cur != next) {
            if (lbl_803C5F04._36 == 0) {
                if (cur == 0) {
                    getTeamObj(task, next, 1)->_5C = 0;
                    getTeamObj(task, next, 1)->_68 = 0;
                    getSpaniObj(task, 0xB)->_5C = 0;
                    getSpaniObj(task, 0xB)->_68 = 1;
                    animRowSelection(task, next, lbl_803C5F04._3B[(u8)next]);
                } else if (next == 0) {
                    getTeamObj(task, cur, 1)->_68 = 1;
                    getSpaniObj(task, 0xB)->_5C = 10 << 16;
                    getSpaniObj(task, 0xB)->_68 = 4;
                } else if (next != 0) {
                    getTeamObj(task, cur, 1)->_68 = 1;
                    getTeamObj(task, next, 1)->_5C = 0;
                    getTeamObj(task, next, 1)->_68 = 0;
                    animRowSelection(task, next, lbl_803C5F04._3B[(u8)next]);
                }
            } else {
                if (port == 0) {
                    getSpaniObj(task, 0xB)->_5C = 0;
                    getSpaniObj(task, 0xB)->_68 = 0;
                }
                lbl_80371C30[task->_14 + 0x2B + cur + port * 4].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x3F + cur * 2 + port].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x2B + next + port * 4].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x2B + next + port * 4].obj->_68 = 0;
                lbl_80371C30[task->_14 + 0x3F + next * 2 + port].obj->_68 = 4;
            }
            if (lbl_803C5F04._36 == 0) {
                fn_800542C4(cur, next, task);
            }
        } else if (next == cur && a != b) {
            if (lbl_803C5F04._36 == 0 && cur != 0) {
                fn_800542C4(cur, next, task);
            } else if (lbl_803C5F04._36 == 1) {
                if (lbl_803C5F04._37[port] == 0) {
                    lbl_80371C30[task->_14 + 0x33 + cur + port * 4].obj->_68 = 4;
                    lbl_80371C30[task->_14 + 0x47 + cur * 4 + port].obj->_54 &= ~2;
                    lbl_80371C30[task->_14 + 0x49 + cur * 4 + port].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x47 + cur * 4 + port].obj->_68 = 0;
                    lbl_80371C30[task->_14 + 0x49 + cur * 4 + port].obj->_68 = 1;
                } else {
                    lbl_80371C30[task->_14 + 0x33 + cur + port * 4].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x47 + cur * 4 + port].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x49 + cur * 4 + port].obj->_54 &= ~2;
                    lbl_80371C30[task->_14 + 0x47 + cur * 4 + port].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x49 + cur * 4 + port].obj->_68 = 0;
                }
            }
        }
        fn_800626EC(port);
        lbl_803C66B0.rows[8].port[port] = 1;
    }
}

static inline BOOL isLockState(s32 lock, s32 state) {
    return lock == state ? TRUE : FALSE;
}

static inline BOOL isAnimDone(void* task, s32 id, s32 frame) {
    return fn_80042DA8(task, id, frame) != 0;
}

// .text:0x80054910 size:0x1F0
// 91.77%: the target branches around a one-case test of cur, sets waited after
// the call's arguments and copies each result into done (mr r7).
void fn_80054910(void* task, s32 port) {
    s8 cur;
    s8 next;
    s8 a;
    s8 b;
    BOOL done;
    BOOL waited;

    if (isLockState(lbl_803C66B0.rows[8].port[port], 1)) {
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
            lbl_803C66B0.rows[8].port[port] = 2;
        }
    }
}

// .text:0x800542C4 size:0x64C
void fn_800542C4(u8 row, u8 cur, SpaniTask* task) {
    s32 i;
    s8 sel = lbl_803C5F04._3B[row];
    s8 sel2 = lbl_803C5F04._40[row];

    switch (row) {
    case 1:
        for (i = 0; i < 2; i++) {
            lbl_80371C30[task->_14 + 0xC + i].obj->_64 = 0x106;
            if (i == sel) {
                lbl_80371C30[task->_14 + 0xC + i].obj->_68 = 1;
            } else if (row == cur) {
                lbl_80371C30[task->_14 + 0xC + i].obj->_5C = 10 << 16;
                lbl_80371C30[task->_14 + 0xC + i].obj->_68 = 4;
            }
            if (row == cur) {
                if (sel != 0) {
                    getSpaniObj(task, 0x1A)->_5C = 0x19 << 16;
                    getSpaniObj(task, 0x1A)->_68 = 4;
                } else {
                    getSpaniObj(task, 0x1A)->_5C = 5 << 16;
                    getSpaniObj(task, 0x1A)->_68 = 1;
                }
            }
        }
        break;
    case 2:
        for (i = 0; i < 2; i++) {
            lbl_80371C30[task->_14 + 0xE + i].obj->_64 = 0x106;
            if ((i == sel) ^ 1) {
                lbl_80371C30[task->_14 + 0xE + i].obj->_68 = 1;
            } else if (row == cur) {
                lbl_80371C30[task->_14 + 0xE + i].obj->_5C = 10 << 16;
                lbl_80371C30[task->_14 + 0xE + i].obj->_68 = 4;
            }
        }
        getSpaniObj(task, 0x20)->_5C = 0;
        getSpaniObj(task, 0x23)->_5C = 10 << 16;
        fn_800363D8(task, 0x20, 1, 0xF9, lbl_803C5F04._3B[2] ^ 1);
        fn_800363D8(task, 0x23, 1, 0xF9, lbl_803C5F04._40[2] ^ 1);
        getSpaniObj(task, 0x20)->_68 = 1;
        getSpaniObj(task, 0x23)->_68 = 4;
        break;
    case 3:
        for (i = 0; i < 5; i++) {
            if (i == sel) {
                lbl_80371C30[task->_14 + 0x10 + i].obj->_64 = 0x108;
                lbl_80371C30[task->_14 + 0x10 + i].obj->_68 = 1;
            } else if (i == sel2 && row == cur) {
                lbl_80371C30[task->_14 + 0x10 + i].obj->_64 = 0x108;
                lbl_80371C30[task->_14 + 0x10 + i].obj->_5C = 10 << 16;
                lbl_80371C30[task->_14 + 0x10 + i].obj->_68 = 4;
            }
        }
        getSpaniObj(task, 0x21)->_5C = 0;
        getSpaniObj(task, 0x24)->_5C = 10 << 16;
        fn_800363D8(task, 0x21, 1, 0xF9, lbl_803C5F04._3B[3] + 2);
        fn_800363D8(task, 0x24, 1, 0xF9, lbl_803C5F04._40[3] + 2);
        getSpaniObj(task, 0x21)->_68 = 1;
        getSpaniObj(task, 0x24)->_68 = 4;
        break;
    case 4:
        for (i = 0; i < 2; i++) {
            lbl_80371C30[task->_14 + 0x15 + i].obj->_64 = 0x106;
            if ((i == sel) ^ 1) {
                lbl_80371C30[task->_14 + 0x15 + i].obj->_68 = 1;
            } else if (row == cur) {
                lbl_80371C30[task->_14 + 0x15 + i].obj->_5C = 10 << 16;
                lbl_80371C30[task->_14 + 0x15 + i].obj->_68 = 4;
            }
        }
        getSpaniObj(task, 0x22)->_5C = 0;
        getSpaniObj(task, 0x25)->_5C = 10 << 16;
        fn_800363D8(task, 0x22, 1, 0xF9, lbl_803C5F04._3B[4] ^ 1);
        fn_800363D8(task, 0x25, 1, 0xF9, lbl_803C5F04._40[4] ^ 1);
        getSpaniObj(task, 0x22)->_68 = 1;
        getSpaniObj(task, 0x25)->_68 = 4;
        break;
    }
}

// .text:0x80053FE8 size:0x2DC
void fn_80053FE8(void) {
}

// .text:0x80053810 size:0x7D8
void fn_80053810(void) {
}

// .text:0x800531D0 size:0x640
void fn_800531D0(SpaniTask* task) {
    s32 i;
    s32 len;

    if (lbl_800FEF70[lbl_8034E978._00]._0A != 0xFFFF) {
        if (lbl_8034E978._20 == 0) {
            for (i = 0; i < lbl_8034E978._14; i++) {
                getTeamObj(task, i, 0x16)->_54 |= 2;
            }
            getSpaniObj(task, 9)->_54 |= 2;
            if ((getSpaniObj(task, 9)->_5C >> 16) == 0xF) {
                if (lbl_8034E978._23 == 0) {
                    len = fn_8000FA9C(lbl_8034E978._0A[0]);
                    for (i = 0; i < 10; i++) {
                        lbl_8034E978._16[i] = 0xFF;
                    }
                    lbl_8034E978._15 = 0;
                    getSpaniObj(task, 10)->_5C = len << 16;
                    getSpaniObj(task, 10)->_68 = 0;
                    getSpaniObj(task, 0x15)->_5C = 0;
                    getSpaniObj(task, 0x15)->_54 |= 2;
                    if (lbl_800FEF70[lbl_8034E978._00]._0E != 0) {
                        getSpaniObj(task, 0x15)->_68 = 1;
                        lbl_8034E978._23 = 1;
                    } else {
                        getSpaniObj(task, 0x15)->_68 = 0;
                    }
                }
                if ((getSpaniObj(task, 0x15)->_5C >> 16) > 0xF && lbl_8034E978._23 != 0) {
                    lbl_8034E978._20 = 1;
                    lbl_8034E978._23 = 0;
                }
            }
        } else if (lbl_8034E978._20 == 1) {
            if ((getSpaniObj(task, 0x15)->_5C >> 16) == 0x73) {
                lbl_8034E978._20 = 2;
                getSpaniObj(task, 10)->_68 = 1;
            }
        } else if (lbl_8034E978._20 == 2) {
            fn_8000FA9C(lbl_8034E978._0A[lbl_8034E978._15]);
            len = fn_8000FA9C(lbl_8034E978._0A[lbl_8034E978._15]);
            if ((lbl_80371C30[task->_14 + 10 + lbl_8034E978._15].obj->_5C >> 16) > len) {
                lbl_8034E978._16[lbl_8034E978._15] = lbl_8034E978._15;
                lbl_8034E978._15++;
                if (lbl_8034E978._15 == lbl_8034E978._14) {
                    lbl_8034E978._15 = 0;
                }
                lbl_80371C30[task->_14 + 10 + lbl_8034E978._15].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 10 + lbl_8034E978._15].obj->_5C = 0;
                lbl_80371C30[task->_14 + 10 + lbl_8034E978._15].obj->_68 = 1;
            }
            for (i = 0; i < 10; i++) {
                if (lbl_8034E978._16[i] != 0xFF) {
                    SpaniObj* obj = lbl_80371C30[task->_14 + 10 + lbl_8034E978._16[i]].obj;
                    if ((obj->_5C >> 16) == 0x500) {
                        obj->_5C = 0;
                        lbl_80371C30[task->_14 + 10 + lbl_8034E978._16[i]].obj->_68 = 0;
                        lbl_80371C30[task->_14 + 10 + lbl_8034E978._16[i]].obj->_54 &= ~2;
                    }
                }
            }
        }
    } else if (lbl_8034E978._20 != 0) {
        s32 j;

        for (j = 0; j < 10; j++) {
            lbl_80371C30[task->_14 + 0x16 + j].obj->_54 &= ~2;
            lbl_80371C30[task->_14 + 10 + j].obj->_5C = 0;
            lbl_80371C30[task->_14 + 10 + j].obj->_68 = 0;
        }
        getSpaniObj(task, 9)->_54 &= ~2;
        getSpaniObj(task, 0x15)->_5C = 0;
        getSpaniObj(task, 0x15)->_68 = 0;
        lbl_8034E978._20 = 0;
    }
}
