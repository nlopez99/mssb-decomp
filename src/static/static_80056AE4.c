#include "static/static_80056AE4.h"
#include "static/UnknownHomes_Static.h"
#include "game/UnknownHomes_Game.h"
#include "static/spani_default.h"
#include "static/static_80021188.h"
#include "static/static_800531D0.h"
#include "static/static_80062578.h"
#include "static/mb_subfunc.h"
#include "static/sub.h"
#include "string.h"

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

extern struct {
    /* 0x00000 */ u8 _00000[0xCF3B];
    /* 0x0CF3B */ u8 _CF3B;
    /* 0x0CF3C */ u8 _CF3C[2];
    /* 0x0CF3E */ u8 _CF3E[2];
    /* 0x0CF40 */ u8 _CF40[0xCF46 - 0xCF40];
    /* 0x0CF46 */ s8 _CF46[2];
    /* 0x0CF48 */ s8 _CF48[2];
    /* 0x0CF4A */ u8 _CF4A[0xCF52 - 0xCF4A];
    /* 0x0CF52 */ u8 _CF52[2];
    /* 0x0CF54 */ u8 _CF54[0xCF63 - 0xCF54];
    /* 0x0CF63 */ u8 _CF63[2];
    /* 0x0CF65 */ u8 _CF65[0xCF70 - 0xCF65];
    /* 0x0CF70 */ u8 _CF70;
    /* 0x0CF71 */ u8 _CF71[0xCF7C - 0xCF71];
    /* 0x0CF7C */ u8 _CF7C;
    /* 0x0CF7D */ u8 _CF7D[0xCF92 - 0xCF7D];
    /* 0x0CF92 */ u8 _CF92;
    /* 0x0CF93 */ u8 _CF93;
    /* 0x0CF94 */ u8 _CF94[0xCF97 - 0xCF94];
    /* 0x0CF97 */ s8 _CF97;
    /* 0x0CF98 */ s8 _CF98;
    /* 0x0CF99 */ u8 _CF99;
    /* 0x0CF9A */ u8 _CF9A;
    /* 0x0CF9B */ u8 _CF9B;
    /* 0x0CF9C */ s16 _CF9C;
    /* 0x0CF9E */ u8 _CF9E[0xCFA2 - 0xCF9E];
    /* 0x0CFA2 */ u8 _CFA2[1];
} lbl_803297E0;

extern struct {
    /* 0x00 */ u8 _00[6][9];
    /* 0x36 */ u8 _36[0xE4 - 0x36];
    /* 0xE4 */ u8 _E4;
} lbl_80361B20;

typedef struct RosterEntry {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ u8 captainStar;
    /* 0x35 */ u8 starSwing;
    /* 0x36 */ u8 starPitch;
    /* 0x37 */ u8 _37[0xA0 - 0x37];
} RosterEntry; // size: 0xA0

extern struct {
    /* 0x0000 */ RosterEntry chars[6][9];
    /* 0x21C0 */ u8 _21C0[0x47F9 - 0x21C0];
    /* 0x47F9 */ s8 _47F9[2][9][9];
} lbl_8034E9A0;

typedef struct MissionText {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
    /* 0x4 */ s16 _4;
    /* 0x6 */ s16 _6;
    /* 0x8 */ s16 _8;
} MissionText; // size: 0xA

typedef struct CaptainInfo {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 set;
    /* 0x3 */ u8 _3[3];
} CaptainInfo; // size: 0x6

extern CaptainInfo lbl_800E8558[];
extern MissionText lbl_8010A768[][10];

extern s32 fn_80042DA8(void* task, s32 index, s32 value);
extern void fn_8000FE08(s32 id, s32 arg1, s32 arg2);

typedef struct OrderSlot {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ s8 _2;
    /* 0x3 */ u8 _3;
} OrderSlot; // size: 0x4

extern OrderSlot lbl_80354720[2][9];

extern MenuScreen lbl_800FEF70[];
extern SpaniSlot lbl_80371C30[];
extern SpaniTask* lbl_803CC1B8;
extern struct SpaniDesc lbl_80108048[];

extern void fn_8006CF6C(void);

static inline BOOL isAnimDone(void* task, s32 id, s32 frame) {
    return fn_80042DA8(task, id, frame) != 0;
}

static inline BOOL isLockState(s32 lock, s32 state) {
    return lock == state ? TRUE : FALSE;
}

static inline SpaniObj* getSpaniObj(SpaniTask* task, s32 id) {
    return lbl_80371C30[task->_14 + id].obj;
}

static inline SpaniObj* getTeamObj(SpaniTask* task, s32 offset, s32 id) {
    return lbl_80371C30[task->_14 + id + offset].obj;
}

static inline SpaniObj* getGridObj(SpaniTask* task, s32 col, s32 row, s32 id) {
    return lbl_80371C30[task->_14 + id + col + row].obj;
}

static inline void setScreen(s16 id) {
    lbl_8034E978._00 = id;
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._08 = lbl_800FEF70[id]._08;
}

// .text:0x8006236C size:0x20C
void SetMenuNumber(void) {
    s32 i;
    u8 found = FALSE;
    s16 id;
    u8 mode;

    if (g_d_GameSettings._06 != 2) {
        if (g_d_GameSettings.GameModeSelected == 5) {
            id = 0x16;
        } else {
            for (i = 0; i < 54; i++) {
                if (lbl_80361B20._00[0][i]) {
                    found = TRUE;
                    break;
                }
            }
            if (found) {
                id = 4;
            } else {
                id = 3;
            }
        }
        setScreen(id);
    }
    mode = lbl_803297E0._CFA2[lbl_803297E0._CF3B];
    if (mode != 2 && mode != 3) {
        if (g_d_GameSettings.GameModeSelected == 5 && lbl_803297E0._CF70 != 0 && lbl_80361B20._E4 == 0) {
            fn_800B0A5C_insertQueue(fn_8006CF6C, 0x3000);
        }
        fn_800B0A5C_insertQueue(fn_80061B9C, 0x3000);
    } else if (mode == 2) {
        fn_800B0A5C_insertQueue(fn_80058050, 0x3000);
    } else {
        fn_800B0A5C_insertQueue(starMenu, 0x3000);
    }
}

// .text:0x80061B9C size:0x7D0
void fn_80061B9C(void) {
}

// .text:0x80060184 size:0x1A18
void fn_80060184(void) {
}

// .text:0x8005FCA0 size:0x4E4
void fn_8005FCA0(SpaniTask* task, s32 team) {
    if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
        getTeamObj(task, team, 4)->_5C = 0;
        getTeamObj(task, team, 4)->_68 = 1;
        getTeamObj(task, team, 6)->_5C = 14 << 16;
        getTeamObj(task, team, 6)->_68 = 1;
        if (g_d_GameSettings.GameModeSelected != 5) {
            if (g_d_GameSettings._10 == 0 && team != 0) {
                getSpaniObj(task, team)->_5C = 0;
                getSpaniObj(task, team)->_68 = 1;
                getTeamObj(task, team, 2)->_5C = 0;
                getTeamObj(task, team, 2)->_68 = 1;
                getTeamObj(task, team, 0x12)->_5C = 30 << 16;
                getTeamObj(task, team, 0x12)->_68 = 4;
                getTeamObj(task, team, 0x14)->_5C = 0;
                getTeamObj(task, team, 0x14)->_68 = 1;
                getTeamObj(task, team, 0x18)->_5C = 0;
                getTeamObj(task, team, 0x18)->_68 = 0;
                getTeamObj(task, team, 0xA)->_54 |= 2;
                getTeamObj(task, team, 0xA)->_5C = 0;
                getTeamObj(task, team, 0xA)->_68 = 1;
            } else {
                getSpaniObj(task, team)->_5C = 0;
                getSpaniObj(task, team)->_68 = 1;
                getTeamObj(task, team, 2)->_5C = 0;
                getTeamObj(task, team, 2)->_68 = 1;
                getTeamObj(task, team, 0xA)->_54 |= 2;
                getTeamObj(task, team, 0xA)->_5C = 0;
                getTeamObj(task, team, 0xA)->_68 = 1;
                getTeamObj(task, team, 2)->_5C = 0;
                getTeamObj(task, team, 2)->_68 = 1;
                getTeamObj(task, team, 0x12)->_5C = 0;
                getTeamObj(task, team, 0x12)->_68 = 1;
                getTeamObj(task, team, 0x14)->_5C = 0;
                getTeamObj(task, team, 0x14)->_68 = 1;
            }
        } else {
            getSpaniObj(task, team)->_5C = 0;
            getSpaniObj(task, team)->_68 = 1;
            getTeamObj(task, team, 0xA)->_54 |= 2;
            getTeamObj(task, team, 0xA)->_5C = 0;
            getTeamObj(task, team, 0xA)->_68 = 1;
            getSpaniObj(task, 0x12)->_5C = 0;
            getSpaniObj(task, 0x12)->_68 = 1;
            getSpaniObj(task, 0x14)->_5C = 0;
            getSpaniObj(task, 0x14)->_68 = 1;
            getSpaniObj(task, 2)->_5C = 0;
            getSpaniObj(task, 2)->_68 = 1;
            getSpaniObj(task, 3)->_5C = 0;
            getSpaniObj(task, 3)->_68 = 1;
            if (lbl_803297E0._CF70 == 0) {
                getSpaniObj(task, 0x1D2)->_54 |= 2;
                getSpaniObj(task, 0x1D2)->_5C = 10 << 16;
                getSpaniObj(task, 0x1D2)->_68 = 1;
            }
        }
        fn_800626EC(team);
        lbl_803C66B0.rows[9].port[team] = 1;
    }
}

// .text:0x8005F9D0 size:0x2D0
void fn_8005F9D0(void) {
}

// .text:0x8005F734 size:0x29C
void fn_8005F734(SpaniTask* task, s32 team) {
    if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
        getSpaniObj(task, team)->_64 = 0x49;
        getSpaniObj(task, team)->_5C = 50 << 16;
        getSpaniObj(task, team)->_68 = 4;
        getTeamObj(task, team, 2)->_64 = 0x52;
        getTeamObj(task, team, 2)->_5C = 0;
        getTeamObj(task, team, 2)->_68 = 1;
        getTeamObj(task, team, 4)->_5C = 0;
        getTeamObj(task, team, 4)->_68 = 1;
        getTeamObj(task, team, 6)->_5C = 14 << 16;
        getTeamObj(task, team, 6)->_68 = 1;
        getTeamObj(task, team, 0xA)->_54 |= 2;
        getTeamObj(task, team, 0xA)->_5C = 0;
        getTeamObj(task, team, 0xA)->_68 = 1;
        getTeamObj(task, team, 0x14)->_5C = 0;
        getTeamObj(task, team, 0x14)->_68 = 1;
        if (g_d_GameSettings._10 == 0 && team == 0) {
            getTeamObj(task, team, 0x12)->_5C = 30 << 16;
            getTeamObj(task, team, 0x12)->_68 = 4;
            getTeamObj(task, team, 0x18)->_5C = 0;
            getTeamObj(task, team, 0x18)->_68 = 0;
        } else {
            getTeamObj(task, team, 0x12)->_5C = 0;
            getTeamObj(task, team, 0x12)->_68 = 1;
        }
        fn_800626EC(team);
        lbl_803C66B0.rows[9].port[team] = 1;
    }
}

// .text:0x8005F068 size:0x6CC
void fn_8005F068(void) {
}

// .text:0x8005EC88 size:0x3E0
// 86.09%: the target guards the slot-clearing loop (li 0; cmpwi 9; bge) and
// unrolls it in its own order; the switch bodies match up to registers.
void fn_8005EC88(SpaniTask* task, s32 team) {
    s8 cur;
    s8 slot;
    s32 i;

    if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
        if (lbl_803297E0._CF46[team] != 0) {
            cur = lbl_803297E0._CF46[team] - 1;
            slot = lbl_80354720[team][cur]._2;
            for (i = 0; i < 9; i++) {
                getGridObj(task, i, team * 9, 0x64)->_54 &= ~2;
                getGridObj(task, i, team * 9, 0x12E)->_54 &= ~2;
            }
            switch (lbl_803297E0._CF52[team]) {
            case 0:
                getGridObj(task, cur, team * 9, 0x40)->_68 = 1;
                getGridObj(task, cur, team * 9, 0x1C)->_5C = 0;
                getGridObj(task, cur, team * 9, 0x1C)->_68 = 1;
                getGridObj(task, cur, team * 9, 0x52)->_5C = 0;
                getGridObj(task, cur, team * 9, 0x52)->_68 = 1;
                getGridObj(task, cur, team * 9, 0x64)->_54 |= 2;
                getGridObj(task, cur, team * 9, 0x64)->_64 = 0x2A;
                getGridObj(task, cur, team * 9, 0x64)->_68 = 1;
                fn_8005C830(task, team, cur);
                break;
            case 1:
                getGridObj(task, slot, team * 9, 0x10A)->_68 = 1;
                getGridObj(task, slot, team * 9, 0xF8)->_68 = 1;
                getGridObj(task, slot, team * 9, 0x12E)->_54 |= 2;
                getGridObj(task, slot, team * 9, 0x12E)->_64 = 0x2A;
                getGridObj(task, slot, team * 9, 0x12E)->_68 = 1;
                fn_8005C830(task, team, cur);
                break;
            }
        }
        getTeamObj(task, team, 0x18)->_5C = 10 << 16;
        getTeamObj(task, team, 0x18)->_68 = 4;
        fn_800626EC(team);
        lbl_803C66B0.rows[9].port[team] = 1;
    }
}

// .text:0x8005E9D8 size:0x2B0
// Drafted while fn_8005DE14 and fn_8005CCE4 are still stubs (inlined here).
void fn_8005E9D8(SpaniTask* task, s32 team) {
    u8 cur;
    s8 slot;

    if (lbl_803297E0._CF46[team] != lbl_803297E0._CF48[team]) {
        fn_8005DE14(task, team);
        if (isLockState(lbl_803C66B0.rows[9].port[team], 1)) {
            fn_80062674(team);
            lbl_803C66B0.rows[9].port[team] = 2;
        }
    } else if (lbl_803297E0._CF3C[team] != 0) {
        if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
            cur = lbl_803297E0._CF3E[team];
            slot = lbl_80354720[team][cur]._2;
            if (lbl_803297E0._CF52[team] == 0) {
                getGridObj(task, cur, team * 9, 0x1C)->_5C = 0xA0000;
                getGridObj(task, cur, team * 9, 0x1C)->_68 = 0;
                getGridObj(task, cur, team * 9, 0x40)->_5C = 0;
                getGridObj(task, cur, team * 9, 0x40)->_68 = 1;
            } else if (g_d_GameSettings._06 != 2) {
                getGridObj(task, slot, team * 9, 0x10A)->_5C = 0;
                getGridObj(task, slot, team * 9, 0x10A)->_68 = 1;
                getGridObj(task, slot, team * 9, 0xF8)->_5C = 0;
                getGridObj(task, slot, team * 9, 0xF8)->_68 = 1;
            } else {
                getTeamObj(task, slot, 0x23)->_5C = 0;
                getTeamObj(task, slot, 0x23)->_68 = 1;
                getTeamObj(task, slot, 0x1A)->_5C = 0;
                getTeamObj(task, slot, 0x1A)->_68 = 1;
            }
            lbl_803C66B0.step[team] = 0;
            lbl_803C66B0.rows[9].port[team] = 2;
        }
    } else if (lbl_803297E0._CF3C[team] == 0) {
        fn_8005CCE4(task, team);
    }
}

// .text:0x8005DE14 size:0xBC4
void fn_8005DE14(SpaniTask* task, s32 team) {
}

// .text:0x8005CCE4 size:0x1130
void fn_8005CCE4(SpaniTask* task, s32 team) {
}

// .text:0x8005C830 size:0x4B4
// 98.29%: registers only; the target keeps charID in r27 and the counters
// one register higher.
void fn_8005C830(SpaniTask* task, s32 team, s32 row) {
    s32 i;
    s32 j;
    s8 charID;
    for (j = 0; j < 9; j++) {
        charID = lbl_8034E9A0._47F9[team][row][j];
        for (i = 0; i < 9; i++) {
            if (inMemRoster[team][i].stats.CharID == charID) {
                if (lbl_803297E0._CF52[team] == 0) {
                    if (g_d_GameSettings._06 != 2) {
                        getGridObj(task, i, team * 9, 0x52)->_5C = 0;
                        getGridObj(task, i, team * 9, 0x52)->_68 = 1;
                        getGridObj(task, i, team * 9, 0x64)->_54 |= 2;
                        getGridObj(task, i, team * 9, 0x64)->_64 = 0x2B;
                        getGridObj(task, i, team * 9, 0x64)->_68 = 1;
                    } else {
                        getTeamObj(task, lbl_80354720[team][i]._2, 0x35)->_54 |= 2;
                        getTeamObj(task, lbl_80354720[team][i]._2, 0x35)->_64 = 0x2B;
                        getTeamObj(task, lbl_80354720[team][i]._2, 0x35)->_5C = 0;
                        getTeamObj(task, lbl_80354720[team][i]._2, 0x35)->_68 = 1;
                        getTeamObj(task, i, 0x6C)->_54 |= 2;
                        getTeamObj(task, i, 0x6C)->_5C = 0;
                        getTeamObj(task, i, 0x6C)->_68 = 1;
                        getTeamObj(task, i, 0x75)->_54 |= 2;
                        getTeamObj(task, i, 0x75)->_64 = 0x2B;
                        getTeamObj(task, i, 0x75)->_68 = 1;
                    }
                } else if (g_d_GameSettings._06 != 2) {
                    getGridObj(task, lbl_80354720[team][i]._2, team * 9, 0x12E)->_54 |= 2;
                    getGridObj(task, lbl_80354720[team][i]._2, team * 9, 0x12E)->_64 = 0x2B;
                    getGridObj(task, lbl_80354720[team][i]._2, team * 9, 0x12E)->_5C = 0;
                    getGridObj(task, lbl_80354720[team][i]._2, team * 9, 0x12E)->_68 = 1;
                } else {
                    getTeamObj(task, lbl_80354720[team][i]._2, 0x35)->_54 |= 2;
                    getTeamObj(task, lbl_80354720[team][i]._2, 0x35)->_64 = 0x2B;
                    getTeamObj(task, lbl_80354720[team][i]._2, 0x35)->_5C = 0;
                    getTeamObj(task, lbl_80354720[team][i]._2, 0x35)->_68 = 1;
                    getTeamObj(task, i, 0x6C)->_54 |= 2;
                    getTeamObj(task, i, 0x6C)->_5C = 0;
                    getTeamObj(task, i, 0x6C)->_68 = 1;
                    getTeamObj(task, i, 0x75)->_54 |= 2;
                    getTeamObj(task, i, 0x75)->_64 = 0x2B;
                    getTeamObj(task, i, 0x75)->_68 = 1;
                }
            }
        }
    }
}

// .text:0x8005C5C4 size:0x26C
void fn_8005C5C4(SpaniTask* task, s32 team) {
    if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
        if (g_d_GameSettings._06 == 2) {
            getSpaniObj(task, 0)->_5C = 20 << 16;
            getSpaniObj(task, 0)->_68 = 4;
        } else if (g_d_GameSettings.GameModeSelected == 5) {
            getSpaniObj(task, 0)->_5C = 20 << 16;
            getSpaniObj(task, 1)->_5C = 20 << 16;
            getSpaniObj(task, 0)->_68 = 4;
            getSpaniObj(task, 1)->_68 = 4;
        } else if (g_d_GameSettings._10 == 0) {
            if (team != 0) {
                getSpaniObj(task, team)->_5C = 20 << 16;
                getSpaniObj(task, team)->_68 = 4;
            } else {
                getSpaniObj(task, team)->_5C = 30 << 16;
                getSpaniObj(task, team)->_68 = 1;
            }
        } else {
            if ((getSpaniObj(task, team)->_5C >> 16) == 30) {
                getSpaniObj(task, team)->_5C = 30 << 16;
                getSpaniObj(task, team)->_68 = 1;
            } else {
                getSpaniObj(task, team)->_5C = 20 << 16;
                getSpaniObj(task, team)->_68 = 4;
            }
        }
        getTeamObj(task, team, 0x16)->_5C = 10 << 16;
        getTeamObj(task, team, 0x18)->_68 = 4;
        getTeamObj(task, team, 0x12)->_5C = 20 << 16;
        getTeamObj(task, team, 0x12)->_68 = 1;
        fn_800626EC(team);
        lbl_803C66B0.rows[9].port[team] = 1;
    }
}

// .text:0x8005C2B0 size:0x314
void fn_8005C2B0(void) {
}

// .text:0x8005BF40 size:0x370
void fn_8005BF40(void) {
}

// .text:0x8005BB5C size:0x3E4
void fn_8005BB5C(void) {
}

// .text:0x8005B760 size:0x3FC
void fn_8005B760(void) {
}

// .text:0x8005B298 size:0x4C8
void fn_8005B298(void) {
}

// .text:0x8005AF68 size:0x330
void fn_8005AF68(void) {
}

// .text:0x8005A350 size:0xC18
void fn_8005A350(void) {
}

// .text:0x80059B38 size:0x818
void starMissionRelated1(void) {
}

// .text:0x800596D4 size:0x464
void fn_800596D4(void) {
}

// .text:0x80059458 size:0x27C
// 97.99%: registers only around the loop counters and the shared 12.
void fn_80059458(SpaniTask* task, u8 team, s32 mask) {
    s32 i;
    s32 out[2];
    s32 n;
    memset(out, -1, 2);
    for (i = 0, n = 0; i < 14; i++) {
        if (mask & (1 << i)) {
            switch (i) {
            case 0:
                i++;
                break;
            case 1:
                out[n++] = 1;
                break;
            case 2:
                out[n++] = 2;
                break;
            case 3:
                out[n++] = 3;
                break;
            case 4:
                out[n++] = 4;
                break;
            case 5:
                out[n++] = 5;
                break;
            case 6:
                out[n++] = 6;
                break;
            case 7:
                out[n++] = 7;
                break;
            case 8:
                out[n++] = 8;
                break;
            case 9:
                out[n++] = 9;
                break;
            case 10:
                out[n++] = 10;
                break;
            case 11:
                out[n++] = 11;
                break;
            case 12:
                out[n++] = 12;
                break;
            default:
                out[n++] = 13;
                break;
            }
        }
    }
    out[0]--;
    out[1]--;
    if (out[0] < 0) {
        out[0] = 12;
    }
    if (out[1] < 0) {
        out[1] = 12;
    }
    if (g_d_GameSettings._06 != 2) {
        getTeamObj(task, team, 0x1B4)->_5C = out[0] << 16;
        getTeamObj(task, team, 0x1B6)->_5C = out[1] << 16;
    } else {
        lbl_80371C30[task->_14 + 0x125].obj->_5C = out[0] << 16;
        lbl_80371C30[task->_14 + 0x126].obj->_5C = out[1] << 16;
    }
}

// .text:0x80058E0C size:0x64C
void fn_80058E0C(void) {
}

// .text:0x80058B20 size:0x2EC
// 96.90%: registers only around the star lookup, as in fn_80058394.
void fn_80058B20(SpaniTask* task, u8 team) {
    CharacterStats* player;
    s8 row;
    s8 col;
    u8 star;
    u8 swing;
    u8 pitch;
    s8 hit;
    s32 swingID;
    s32 pitchID;

    if (lbl_803297E0._CF63[team] == 0) {
        getTeamObj(task, team, 0x1C6)->_54 &= ~2;
        getTeamObj(task, team, 0x1C6)->_68 = 0;
        getTeamObj(task, team, 0x19C)->_68 = 4;
        getTeamObj(task, team, 0x1AC)->_68 = 4;
        player = &inMemRoster[team][lbl_803297E0._CF46[team] - 1];
        row = player->stats.CharID / 9;
        col = player->stats.CharID % 9;
        star = lbl_8034E9A0.chars[row][col].captainStar;
        if (star == 0) {
            swing = lbl_8034E9A0.chars[row][col].starSwing + 11;
            pitch = lbl_8034E9A0.chars[row][col].starPitch + 11;
        } else if (g_d_GameSettings.GameModeSelected != 5) {
            swing = star - 1;
            pitch = swing;
        } else {
            pitch = star - 1;
            hit = translateStarPitchHitIndex(pitch);
            if (hit != -1 && (s8)starMissionCompletionTracker._43C2[hit] == 0) {
                swing = lbl_8034E9A0.chars[row][col].starSwing + 11;
                pitch = lbl_8034E9A0.chars[row][col].starPitch + 11;
            } else {
                swing = pitch;
                pitch = star - 1;
            }
        }
        swingID = translateStarSwing(swing);
        pitchID = translateStarPitch(pitch);
        getTeamObj(task, team, 0x1CC)->_64 = swingID;
        getTeamObj(task, team, 0x1CC)->_5C = 0;
        getTeamObj(task, team, 0x1CC)->_68 = 1;
        getTeamObj(task, team, 0x1CE)->_64 = pitchID;
        getTeamObj(task, team, 0x1CE)->_5C = 0;
        getTeamObj(task, team, 0x1CE)->_68 = 1;
        getTeamObj(task, team, 0x1D0)->_54 |= 2;
        getTeamObj(task, team, 0x1D0)->_68 = 1;
        getTeamObj(task, team, 0x1C8)->_68 = 1;
        lbl_803297E0._CF63[team] = 1;
    }
}

// .text:0x80058644 size:0x4DC
void fn_80058644(void) {
}

// .text:0x80058394 size:0x2B0
// 97.67%: registers only; the target keeps the captain star in r25 and
// recomputes star - 1 in the last branch.
void fn_80058394(SpaniTask* task) {
    CharacterStats* player;
    s8 row;
    s8 col;
    u8 star;
    u8 swing;
    u8 pitch;
    s8 hit;
    s32 swingID;
    s32 pitchID;

    if (lbl_803297E0._CF63[lbl_803297E0._CF3B] == 0) {
        lbl_80371C30[task->_14 + 0x12E].obj->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x12E].obj->_68 = 0;
        lbl_80371C30[task->_14 + 0x119].obj->_68 = 4;
        lbl_80371C30[task->_14 + 0x121].obj->_68 = 4;
        player = &inMemRoster[lbl_803297E0._CF3B][lbl_803297E0._CF46[lbl_803297E0._CF3B] - 1];
        row = player->stats.CharID / 9;
        col = player->stats.CharID % 9;
        star = lbl_8034E9A0.chars[row][col].captainStar;
        if (star == 0) {
            swing = lbl_8034E9A0.chars[row][col].starSwing + 11;
            pitch = lbl_8034E9A0.chars[row][col].starPitch + 11;
        } else if (g_d_GameSettings.GameModeSelected != 5) {
            swing = star - 1;
            pitch = swing;
        } else {
            pitch = star - 1;
            hit = translateStarPitchHitIndex(pitch);
            if (hit != -1 && (s8)starMissionCompletionTracker._43C2[hit] == 0) {
                swing = lbl_8034E9A0.chars[row][col].starSwing + 11;
                pitch = lbl_8034E9A0.chars[row][col].starPitch + 11;
            } else {
                swing = pitch;
                pitch = star - 1;
            }
        }
        swingID = translateStarSwing(swing);
        pitchID = translateStarPitch(pitch);
        lbl_80371C30[task->_14 + 0x131].obj->_64 = swingID;
        lbl_80371C30[task->_14 + 0x131].obj->_5C = 0;
        lbl_80371C30[task->_14 + 0x131].obj->_68 = 1;
        lbl_80371C30[task->_14 + 0x132].obj->_64 = pitchID;
        lbl_80371C30[task->_14 + 0x132].obj->_5C = 0;
        lbl_80371C30[task->_14 + 0x132].obj->_68 = 1;
        lbl_80371C30[task->_14 + 0x133].obj->_54 |= 2;
        lbl_80371C30[task->_14 + 0x133].obj->_68 = 1;
        lbl_80371C30[task->_14 + 0x12F].obj->_68 = 1;
        lbl_803297E0._CF63[lbl_803297E0._CF3B] = 1;
    }
}

// .text:0x80058050 size:0x344
void fn_80058050(void) {
}

// .text:0x80057CAC size:0x3A4
void fn_80057CAC(void) {
}

// .text:0x80057C08 size:0xA4
void starMenu(void) {
    SpaniTask* task;
    s32 i;

    fn_80034E20(task = lbl_803CC1B8, lbl_80108048);
    for (i = 0; i < 9; i++) {
        getTeamObj(task, i, 12)->_5C = i << 16;
        fn_800363D8(task, i + 0x15, 1, 0x83, inMemRoster[0][i].stats.CharID);
    }
    lbl_803CC1B8->func = challengeCheckStarsMenuLoading;
}

// .text:0x800576F0 size:0x518
void challengeCheckStarsMenuLoading(void) {
}

// .text:0x800572C0 size:0x430
// 98.06%: the target adds task->_14 and the mission index in the other
// register order.
void someChallengeStarFunction2(SpaniTask* task) {
    u8 set;
    s16 text;

    if (lbl_803297E0._CF93 == 0) {
        set = lbl_800E8558[lbl_803297E0._CF9C].set;
        if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF98)) {
            getSpaniObj(task, 0x23)->_54 |= 2;
            getSpaniObj(task, 0x23)->_5C = 0;
            getSpaniObj(task, 0x23)->_68 = 1;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x31)->_54 |= 2;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x31)->_5C = 0;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x31)->_68 = 1;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x45)->_5C = 0x10000;
        } else {
            getSpaniObj(task, 0x23)->_54 &= ~2;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x31)->_54 &= ~2;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x45)->_5C = 0;
        }
        getSpaniObj(task, lbl_803297E0._CF98 + 0x45)->_54 |= 2;
        getSpaniObj(task, lbl_803297E0._CF98 + 0x45)->_68 = 1;
        if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF97)) {
            getSpaniObj(task, lbl_803297E0._CF97 + 0x31)->_54 &= ~2;
            getSpaniObj(task, lbl_803297E0._CF97 + 0x27)->_5C = 0;
        } else {
            getSpaniObj(task, lbl_803297E0._CF97 + 0x27)->_5C = 0;
        }
        getSpaniObj(task, lbl_803297E0._CF97 + 0x45)->_54 &= ~2;
        getSpaniObj(task, lbl_803297E0._CF97 + 0x45)->_68 = 1;
        if (*(s8*)&starMissionCompletionTracker.characters[lbl_803297E0._CF9C].inGameMissionTracker[lbl_803297E0._CF98].shownOnPauseMenu != 0) {
            text = lbl_8010A768[set][lbl_803297E0._CF98]._0;
        } else if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF98)) {
            text = lbl_8010A768[set][lbl_803297E0._CF98]._0;
        } else if (lbl_8010A768[set][lbl_803297E0._CF98]._6 <= starMissionCompletionTracker._4415) {
            text = 0x1C5;
        } else {
            text = 0x1C6;
        }
        fn_8000FE08(lbl_803297E0._CF7C, 0, text);
        lbl_803297E0._CF93 = 1;
    }
    if (lbl_803297E0._CF93 != 0) {
        lbl_803297E0._CF93 = 0;
        lbl_803297E0._CF92 = 0;
    }
}

// .text:0x80056F70 size:0x350
// 99.62%: registers only where the mission index meets task->_14 and in the
// mission tracker lookup.
void someChallengeStarFunction(SpaniTask* task) {
    s16 set;
    s32 i;
    s16 text;

    if (lbl_803297E0._CF93 == 0) {
        set = lbl_800E8558[lbl_803297E0._CF9C].set;
        getSpaniObj(task, 1)->_68 = 4;
        getSpaniObj(task, 0)->_68 = 4;
        for (i = 0; i < lbl_803297E0._CF9A; i++) {
            getTeamObj(task, i, 0x31)->_54 &= ~2;
            getTeamObj(task, i, 0x45)->_5C = 0;
            getTeamObj(task, i, 0x45)->_54 &= ~2;
        }
        getSpaniObj(task, 0x23)->_54 &= ~2;
        if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF98)) {
            getSpaniObj(task, 0x23)->_54 |= 2;
            getSpaniObj(task, 0x23)->_5C = 0;
            getSpaniObj(task, 0x23)->_68 = 1;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x31)->_54 |= 2;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x31)->_5C = 0;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x31)->_68 = 1;
            getSpaniObj(task, lbl_803297E0._CF98 + 0x45)->_5C = 0x10000;
        }
        if (*(s8*)&starMissionCompletionTracker.characters[lbl_803297E0._CF9C].inGameMissionTracker[lbl_803297E0._CF98].shownOnPauseMenu != 0) {
            text = lbl_8010A768[set][lbl_803297E0._CF98]._0;
        } else if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF98)) {
            text = lbl_8010A768[set][lbl_803297E0._CF98]._0;
        } else if (lbl_8010A768[set][lbl_803297E0._CF98]._6 <= starMissionCompletionTracker._4415) {
            text = 0x1C5;
        } else {
            text = 0x1C6;
        }
        fn_8000FE08(lbl_803297E0._CF7C, 0, text);
        lbl_803297E0._CF93 = 1;
    }
    if (lbl_803297E0._CF93 && isAnimDone(task, 1, 10) == TRUE) {
        lbl_803297E0._CF93 = 0;
        lbl_803297E0._CF92 = 0;
    }
}

// .text:0x80056AE4 size:0x48C
void drawStarProgressionMenu(void) {
}
