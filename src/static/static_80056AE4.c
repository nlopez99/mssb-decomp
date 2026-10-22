#include "static/static_80056AE4.h"
#include "static/UnknownHomes_Static.h"
#include "game/UnknownHomes_Game.h"
#include "static/spani_default.h"
#include "static/static_80021188.h"
#include "static/static_800531D0.h"
#include "static/static_80062578.h"
#include "static/mb_subfunc.h"
#include "static/sub.h"
#include "static/static_8000F150.h"
#include "static/static_8006C48C.h"
#include "string.h"

typedef struct PadHold {
    /* 0x0 */ u16 _0;
    /* 0x2 */ u16 _2;
    /* 0x4 */ u16 _4;
} PadHold; // size: 0x6

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
    /* 0x00000 */ PadHold _00[2];
    /* 0x0000C */ u8 _0000C[0xCF3B - 0xC];
    /* 0x0CF3B */ u8 _CF3B;
    /* 0x0CF3C */ u8 _CF3C[2];
    /* 0x0CF3E */ u8 _CF3E[2];
    /* 0x0CF40 */ u8 _CF40[0xCF46 - 0xCF40];
    /* 0x0CF46 */ s8 _CF46[2];
    /* 0x0CF48 */ s8 _CF48[2];
    /* 0x0CF4A */ u8 _CF4A[0xCF52 - 0xCF4A];
    /* 0x0CF52 */ u8 _CF52[2];
    /* 0x0CF54 */ u8 _CF54[2];
    /* 0x0CF56 */ u8 _CF56[2];
    /* 0x0CF58 */ u8 _CF58[2];
    /* 0x0CF5A */ u8 _CF5A;
    /* 0x0CF5B */ u8 _CF5B[2];
    /* 0x0CF5D */ u8 _CF5D[0xCF61 - 0xCF5D];
    /* 0x0CF61 */ u8 _CF61[2];
    /* 0x0CF63 */ u8 _CF63[2];
    /* 0x0CF65 */ u8 _CF65[2];
    /* 0x0CF67 */ u8 _CF67[2];
    /* 0x0CF69 */ u8 _CF69[0xCF70 - 0xCF69];
    /* 0x0CF70 */ u8 _CF70;
    /* 0x0CF71 */ u8 _CF71[2];
    /* 0x0CF73 */ u8 _CF73;
    /* 0x0CF74 */ u8 _CF74;
    /* 0x0CF75 */ s8 _CF75;
    /* 0x0CF76 */ s8 _CF76;
    /* 0x0CF77 */ u8 _CF77;
    /* 0x0CF78 */ s16 _CF78;
    /* 0x0CF7A */ u8 texts[3];
    /* 0x0CF7D */ u8 _CF7D;
    /* 0x0CF7E */ u8 _CF7E;
    /* 0x0CF7F */ u8 _CF7F;
    /* 0x0CF80 */ s8 _CF80[9];
    /* 0x0CF89 */ s8 _CF89[9];
    /* 0x0CF92 */ u8 _CF92;
    /* 0x0CF93 */ u8 _CF93;
    /* 0x0CF94 */ u8 _CF94;
    /* 0x0CF95 */ s8 _CF95;
    /* 0x0CF96 */ s8 _CF96;
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
    /* 0x00 */ u8 _00[0x31];
    /* 0x31 */ u8 _31;
    /* 0x32 */ u8 _32[0x34 - 0x32];
    /* 0x34 */ u8 captainStar;
    /* 0x35 */ u8 starSwing;
    /* 0x36 */ u8 starPitch;
    /* 0x37 */ u8 _37[0xA0 - 0x37];
} RosterEntry; // size: 0xA0

extern struct {
    /* 0x0000 */ RosterEntry chars[6][9];
    /* 0x21C0 */ u8 _21C0[0x46F8 - 0x21C0];
    /* 0x46F8 */ s8 ports[2];
    /* 0x46FA */ u8 _46FA[0x470D - 0x46FA];
    /* 0x470D */ u8 _470D[2];
    /* 0x470F */ u8 _470F[0x472C - 0x470F];
    /* 0x472C */ PadHold _472C[2];
    /* 0x4738 */ u8 _4738[0x47F9 - 0x4738];
    /* 0x47F9 */ s8 _47F9[2][9][9];
    /* 0x489B */ u8 _489B[2][9];
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

extern s32 fn_80042D68(void* task, s32 index, s32 value);
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
extern s16 lbl_8010B3E8[];

typedef struct TextModel {
    /* 0x00 */ u8 _00[0x2F];
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u8 _30[0x38 - 0x30];
} TextModel; // size: 0x38

extern TextModel lbl_80366B18[];
extern SpaniSlot lbl_80371C30[];
extern SpaniTask* lbl_803CC1B8;
extern u8 lbl_800EFBA4[16];
extern void transferStatsToInMemRoster(u8 team);
extern void sndFXRelated(u16 id);
extern s32 fn_80042598(u8 team, s32 charId);
extern struct SpaniDesc lbl_801000A8[];
extern struct SpaniDesc lbl_801041C8[];
extern struct SpaniDesc lbl_80107688[];
extern struct SpaniDesc lbl_80108048[];

extern void fn_8006CF6C(void);

static inline BOOL isAnimDone(void* task, s32 id, s32 frame) {
    return fn_80042DA8(task, id, frame) != 0;
}

static inline BOOL isAnimAt(void* task, s32 id, s32 frame) {
    return fn_80042D68(task, id, frame) != 0;
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
    SpaniTask* task = lbl_803CC1B8;
    s32 slot;
    s8 team;
    s32 i;
    u8 flag;
    u8 left;
    BOOL cpu;
    s32 port;

    lbl_803297E0._CF40[5] = 0;
    team = lbl_803297E0._CF3B;
    if (g_d_GameSettings._06 != 2) {
        fn_80034E20(task, lbl_801000A8);
        getSpaniObj(task, 0x10)->_5C = lbl_8034E9A0.ports[0] << 16;
        if (g_d_GameSettings._10 == 0) {
            getSpaniObj(task, 0x11)->_5C = ((s8)(lbl_8034E9A0.ports[0] == 0) + 4) << 16;
        } else {
            if (g_d_GameSettings._10 == 0) {
                port = 5;
                if (lbl_8034E9A0.ports[1] != -1) {
                    port = lbl_8034E9A0.ports[1] + 4;
                }
            } else {
                port = lbl_8034E9A0.ports[1];
            }
            getSpaniObj(task, 0x11)->_5C = port << 16;
        }
        if (g_d_GameSettings.GameModeSelected != 5) {
            for (i = 0; i < 9; i++) {
                lbl_80371C30[task->_14 + 0x164 + i].obj->_54 &= ~2;
            }
            getSpaniObj(task, 0x1D2)->_54 &= ~2;
            fn_8005C2B0(task);
            fn_8005BF40(task);
        } else {
            getSpaniObj(task, 0x1D2)->_54 &= ~2;
            fn_8005BB5C(task);
            for (i = 0; i < 9; i++) {
                slot = lbl_80354720[0][i]._2;
                fn_800363D8(task, slot + 0x10A, 1, 0x83, inMemRoster[0][i].stats.CharID);
                getTeamObj(task, i, 0xE6)->_54 &= ~2;
                if (g_d_GameSettings.GameModeSelected == 5) {
                    flag = starMissionCompletionTracker._43D6[inMemRoster[0][i].stats.CharID];
                } else {
                    flag = lbl_8034E9A0._489B[0][i];
                }
                if (flag != 0) {
                    getTeamObj(task, slot, 0x140)->_68 = 1;
                    getTeamObj(task, slot, 0x152)->_54 |= 2;
                    getTeamObj(task, slot, 0x152)->_5C = 0;
                    getTeamObj(task, slot, 0x152)->_68 = 1;
                } else {
                    getTeamObj(task, slot, 0x152)->_54 &= ~2;
                }
                getTeamObj(task, i, 0x12E)->_54 &= ~2;
                getTeamObj(task, i, 0xF8)->_64 = lbl_8034E9A0.ports[0] + 30;
            }
        }
        if (g_d_GameSettings.GameModeSelected == 5) {
            getSpaniObj(task, 0x17)->_54 &= ~2;
        }
    } else {
        fn_80034E20(task, lbl_801041C8);
        if (g_d_GameSettings.home_AwaySetting) {
            if (g_d_GameSettings.GameModeSelected == 5 && (s32)starMissionCompletionTracker._441F[0] == 19) {
                if (team != 0) {
                    left = TRUE;
                } else {
                    left = FALSE;
                }
            } else if (g_d_GameSettings.GameModeSelected == 5 && (s32)starMissionCompletionTracker._441F[0] == 19) {
                if (team != 0) {
                    left = TRUE;
                } else {
                    left = TRUE;
                }
            } else if (team == 0) {
                left = TRUE;
            } else {
                left = FALSE;
            }
        } else if (team != 0) {
            left = TRUE;
        } else {
            left = FALSE;
        }
        if (left) {
            getSpaniObj(task, 6)->_54 &= ~2;
            getSpaniObj(task, 9)->_54 &= ~2;
            getSpaniObj(task, 7)->_5C = (lbl_8034E9A0._470D[team] % 4) << 16;
            getSpaniObj(task, 10)->_5C = (lbl_8034E9A0._470D[team] % 4) << 16;
        } else {
            getSpaniObj(task, 7)->_54 &= ~2;
            getSpaniObj(task, 10)->_54 &= ~2;
            getSpaniObj(task, 6)->_5C = (lbl_8034E9A0._470D[team] % 4) << 16;
            getSpaniObj(task, 9)->_5C = (lbl_8034E9A0._470D[team] % 4) << 16;
        }
        cpu = FALSE;
        if (g_d_GameSettings._10 == 0 && team != 0) {
            cpu = TRUE;
        }
        if (cpu) {
            if (lbl_8034E9A0.ports[team] == -1) {
                port = (team != 0) + 4;
            } else {
                port = lbl_8034E9A0.ports[team] + 4;
            }
        } else {
            port = lbl_8034E9A0.ports[team];
        }
        getSpaniObj(task, 12)->_5C = port << 16;
        getSpaniObj(task, 2)->_5C = 20 << 16;
        getSpaniObj(task, 2)->_68 = 0;
        getSpaniObj(task, 4)->_5C = 20 << 16;
        getSpaniObj(task, 5)->_5C = 24 << 16;
        getSpaniObj(task, 4)->_68 = 0;
        getSpaniObj(task, 5)->_68 = 0;
        getSpaniObj(task, 8)->_5C = 10 << 16;
        getSpaniObj(task, 8)->_68 = 0;
        if (lbl_803297E0._CFA2[team] == 1) {
            getSpaniObj(task, 0x50)->_64 = 40;
            getSpaniObj(task, 1)->_64 = 71;
            getSpaniObj(task, 1)->_5C = 20 << 16;
            getSpaniObj(task, 1)->_68 = 0;
        }
        fn_8005B298(task);
        fn_8005AF68(task);
    }
    lbl_803CC1B8->func = fn_80060184;
}

static inline void orderStep38(SpaniTask* task, s32 port) {
    s32 done;
    s32 count;

    if (g_d_GameSettings._06 != 2) {
        fn_8005FCA0(task, port);
        fn_8005F9D0(task, port);
    } else {
        if (isLockState(lbl_803C66B0.rows[9].port[port], 0)) {
            getSpaniObj(task, 0)->_5C = 0;
            getSpaniObj(task, 0)->_68 = 1;
            if (lbl_803297E0._CFA2[port] != 1) {
                getSpaniObj(task, 1)->_5C = 0;
                getSpaniObj(task, 1)->_68 = 1;
            }
            getSpaniObj(task, 3)->_68 = 1;
            getSpaniObj(task, 0xE)->_5C = 0;
            getSpaniObj(task, 0xE)->_68 = 1;
            fn_800626EC(port);
            lbl_803C66B0.rows[9].port[port] = 1;
        }
        if (lbl_803C66B0.rows[9].port[port] == 1) {
            count = 1;
            done = isAnimDone(task, 0, 20);
            if (lbl_803297E0._CFA2[port] != 1) {
                count = 2;
                done += isAnimDone(task, 1, 20);
            }
            if (done == count) {
                fn_80062674(port);
                lbl_803C66B0.rows[9].port[port] = 2;
            }
        }
    }
}

static inline void orderStep3A(SpaniTask* task, s32 port) {
    s32 done;
    s32 count;

    if (isLockState(lbl_803C66B0.rows[9].port[port], 0)) {
        if (g_d_GameSettings.GameModeSelected != 5) {
            if (g_d_GameSettings._10 == 0 && port != 0) {
                getSpaniObj(task, port)->_5C = 30 << 16;
                getSpaniObj(task, port)->_68 = 1;
            } else {
                getSpaniObj(task, port)->_5C = 20 << 16;
                getSpaniObj(task, port)->_68 = 4;
            }
        } else {
            getSpaniObj(task, port)->_5C = 20 << 16;
            getSpaniObj(task, port)->_68 = 4;
        }
        fn_800626EC(port);
        lbl_803C66B0.rows[9].port[port] = 1;
    }
    if (lbl_803C66B0.rows[9].port[port] == 1) {
        if (g_d_GameSettings.GameModeSelected != 5) {
            if (g_d_GameSettings._10 == 0 && port != 0) {
                count = 1;
                done = isAnimDone(task, port, 50);
            } else {
                count = 1;
                done = isAnimDone(task, port, 0);
            }
        } else {
            count = 1;
            done = isAnimDone(task, port, 0);
        }
        if (done == count) {
            fn_80062674(port);
            lbl_803C66B0.rows[9].port[port] = 2;
        }
    }
}

static inline void orderStep3C(SpaniTask* task, s32 port) {
    s32 done;
    s32 count;

    if (g_d_GameSettings._06 != 2) {
        fn_8005F068(task, port);
        if (isLockState(lbl_803C66B0.rows[9].port[port], 1)) {
            done = 0;
            count = 0;
            switch (lbl_803297E0._CF52[port]) {
            case 0:
                if (lbl_803297E0._CF54[port] == 1) {
                    count = 1;
                    done = isAnimDone(task, port + 0x14, 10);
                }
                break;
            case 1:
                if (lbl_803297E0._CF54[port] != 1) {
                    count = 1;
                    done = isAnimDone(task, port + 0x14, 20);
                }
                break;
            }
            if (done == count) {
                fn_80062674(port);
                lbl_803C66B0.rows[9].port[port] = 2;
            }
        }
    }
}

static inline void orderStep3D(SpaniTask* task, s32 port) {
    if (g_d_GameSettings._06 != 2) {
        fn_8005EC88(task, port);
        if (isLockState(lbl_803C66B0.rows[9].port[port], 1)) {
            fn_80062674(port);
            lbl_803C66B0.rows[9].port[port] = 2;
        }
    } else {
        fn_8005B760(task, port);
        if (isLockState(lbl_803C66B0.rows[9].port[port], 1)) {
            fn_80062674(port);
            lbl_803C66B0.rows[9].port[port] = 2;
        }
    }
}

static inline void orderStep3B(SpaniTask* task, s32 port) {
    fn_8005E9D8(task, port);
}

static inline void orderStep3F(SpaniTask* task, s32 port) {
    s32 done;

    if (g_d_GameSettings._06 != 2) {
        if (isLockState(lbl_803C66B0.rows[9].port[port], 0)) {
            getSpaniObj(task, 0)->_5C = 20 << 16;
            getSpaniObj(task, 0)->_68 = 1;
            getSpaniObj(task, 1)->_5C = 30 << 16;
            getSpaniObj(task, 1)->_68 = 4;
            getSpaniObj(task, 0x18)->_5C = 10 << 16;
            getSpaniObj(task, 0x18)->_68 = 4;
            getSpaniObj(task, 0x19)->_5C = 0;
            getSpaniObj(task, 0x19)->_68 = 1;
            getSpaniObj(task, 0x12)->_5C = 10 << 16;
            getSpaniObj(task, 0x12)->_68 = 1;
            getSpaniObj(task, 0x13)->_5C = 20 << 16;
            getSpaniObj(task, 0x13)->_68 = 4;
            fn_800626EC(port);
            lbl_803C66B0.rows[9].port[port] = 1;
        }
        if (lbl_803C66B0.rows[9].port[port] == 1) {
            done = isAnimDone(task, 0, 30);
            done += isAnimDone(task, 1, 20);
            done += isAnimDone(task, 0x12, 20);
            done += isAnimDone(task, 0x13, 10);
            if (done == 4) {
                fn_80062674(port);
                lbl_803C66B0.rows[9].port[port] = 2;
            }
        }
    }
}

static inline void orderStep40(SpaniTask* task, s32 port) {
    s32 done;

    if (g_d_GameSettings._06 != 2) {
        if (isLockState(lbl_803C66B0.rows[9].port[port], 0)) {
            getSpaniObj(task, 0)->_5C = 30 << 16;
            getSpaniObj(task, 0)->_68 = 4;
            getSpaniObj(task, 1)->_5C = 20 << 16;
            getSpaniObj(task, 1)->_68 = 1;
            getSpaniObj(task, 0x18)->_5C = 0;
            getSpaniObj(task, 0x18)->_68 = 1;
            getSpaniObj(task, 0x19)->_5C = 10 << 16;
            getSpaniObj(task, 0x19)->_68 = 4;
            getSpaniObj(task, 0x12)->_5C = 20 << 16;
            getSpaniObj(task, 0x12)->_68 = 4;
            getSpaniObj(task, 0x13)->_5C = 10 << 16;
            getSpaniObj(task, 0x13)->_68 = 1;
            fn_800626EC(port);
            lbl_803C66B0.rows[9].port[port] = 1;
        }
        if (lbl_803C66B0.rows[9].port[port] == 1) {
            done = isAnimDone(task, 0, 20);
            done += isAnimDone(task, 1, 30);
            done += isAnimDone(task, 0x12, 10);
            done += isAnimDone(task, 0x13, 20);
            if (done == 4) {
                fn_80062674(port);
                lbl_803C66B0.rows[9].port[port] = 2;
            }
        }
    }
}

static inline void orderStep41(SpaniTask* task, s32 port) {
    s32 done;

    if (isLockState(lbl_803C66B0.rows[9].port[port], 0)) {
        getSpaniObj(task, port)->_5C = 20 << 16;
        getSpaniObj(task, port)->_68 = 1;
        getTeamObj(task, port, 0x18)->_5C = 10 << 16;
        getTeamObj(task, port, 0x18)->_68 = 4;
        getTeamObj(task, port, 0x12)->_5C = 10 << 16;
        getTeamObj(task, port, 0x12)->_68 = 1;
        fn_800626EC(port);
        lbl_803C66B0.rows[9].port[port] = 1;
    }
    if (lbl_803C66B0.rows[9].port[port] == 1) {
        done = isAnimAt(task, port, 30);
        done += isAnimAt(task, port + 0x12, 20);
        if (done == 2) {
            lbl_803297E0._CF4A[port + 6] = 0;
            fn_80062674(port);
            lbl_803C66B0.rows[9].port[port] = 2;
        }
    }
}

static inline void orderStep42(SpaniTask* task, s32 port) {
    s32 done;

    if (isLockState(lbl_803C66B0.rows[9].port[port], 0)) {
        getSpaniObj(task, port)->_5C = 30 << 16;
        getSpaniObj(task, port)->_68 = 4;
        getTeamObj(task, port, 0x18)->_5C = 0;
        getTeamObj(task, port, 0x18)->_68 = 1;
        getTeamObj(task, port, 0x12)->_5C = 20 << 16;
        getTeamObj(task, port, 0x12)->_68 = 4;
        fn_800626EC(port);
        lbl_803C66B0.rows[9].port[port] = 1;
    }
    if (lbl_803C66B0.rows[9].port[port] == 1) {
        done = isAnimDone(task, port, 20);
        done += isAnimDone(task, port + 0x12, 10);
        if (done == 2) {
            fn_80062674(port);
            lbl_803C66B0.rows[9].port[port] = 2;
        }
    }
}

static inline void orderStep43(SpaniTask* task, s32 port) {
    s32 done;
    s32 count;

    fn_8005C5C4(task, port);
    if (isLockState(lbl_803C66B0.rows[9].port[port], 1)) {
        done = 0;
        count = 0;
        if (g_d_GameSettings._06 != 2) {
            if (g_d_GameSettings.GameModeSelected == 5) {
                done = isAnimDone(task, 0, 0);
                count = 2;
                done += isAnimDone(task, 1, 0);
            } else if (g_d_GameSettings._10 == 0) {
                if (port != 0) {
                    count = 1;
                    done = isAnimDone(task, port, 0);
                } else {
                    count = 1;
                    done = isAnimDone(task, port, 50);
                }
            } else if ((getSpaniObj(task, port)->_5C >> 16) >= 30) {
                count = 1;
                done = isAnimDone(task, port, 50);
            } else {
                count = 1;
                done = isAnimDone(task, port, 0);
            }
        }
        if (done == count) {
            fn_80062674(port);
            lbl_803C66B0.rows[9].port[port] = 2;
        }
    }
}

static inline void orderStep44(SpaniTask* task, s32 port) {
    s8 last;
    s8 cur;
    s8 curSlot;
    s8 lastSlot;

    if (isLockState(lbl_803C66B0.rows[9].port[port], 0)) {
        last = lbl_803297E0._CF3E[port];
        cur = lbl_803297E0._CF46[port] - 1;
        if (lbl_803297E0._CF52[port] == 0) {
            if (last != -1 && last != cur) {
                getGridObj(task, last, port * 9, 0x1C)->_5C = 10 << 16;
                getGridObj(task, last, port * 9, 0x1C)->_68 = 4;
                getGridObj(task, last, port * 9, 0x40)->_5C = 10 << 16;
                getGridObj(task, last, port * 9, 0x40)->_68 = 4;
            }
        } else {
            curSlot = lbl_80354720[port][cur]._2;
            lastSlot = lbl_80354720[port][last]._2;
            if (g_d_GameSettings._06 != 2) {
                if (last != -1 && lastSlot != curSlot) {
                    getGridObj(task, lastSlot, port * 9, 0x10A)->_68 = 4;
                    getGridObj(task, lastSlot, port * 9, 0xF8)->_68 = 4;
                }
            } else if (last != -1 && lastSlot != curSlot) {
                getTeamObj(task, lastSlot, 0x23)->_68 = 4;
                getTeamObj(task, lastSlot, 0x1A)->_68 = 4;
            }
        }
        lbl_803297E0._CF3E[port] = -1;
        fn_800626EC(port);
        lbl_803C66B0.rows[9].port[port] = 1;
    }
    if (lbl_803C66B0.rows[9].port[port] == 1) {
        fn_80062674(port);
        lbl_803C66B0.rows[9].port[port] = 2;
    }
}

static inline void orderStep45(SpaniTask* task, s32 port) {
    s32 j;
    s32 k;
    s8 flags;
    u8 played;

    played = FALSE;
    if (lbl_803C66B0.rows[9].port[0] == 0) {
        for (j = 0; j < 9; j++) {
            flags = starMissionCompletionTracker.characters[inMemRoster[1][j].stats.CharID].scoutFlagsAchieved;
            for (k = 0; k < flags; k++) {
                played = TRUE;
                getGridObj(task, k, j * 5, 0x16D)->_68 = 1;
            }
        }
        if (played) {
            if (g_d_GameSettings._06 == 2) {
                sndFXStartEx(0x1B1, 0x7F, 0x3F, 0);
            } else {
                sndFXStartEx(0x1E6, 0x7F, 0x3F, 0);
            }
        }
        fn_800626EC(0);
        lbl_803C66B0.rows[9].port[0] = 1;
    }
    if (lbl_803C66B0.rows[9].port[0] == 1) {
        fn_80062674(0);
        lbl_803C66B0.rows[9].port[0] = 2;
    }
}

static inline void orderStep46(SpaniTask* task, s32 port) {
    getSpaniObj(task, 0x1D2)->_54 |= 2;
    getSpaniObj(task, 0x1D2)->_68 = 1;
    lbl_803C66B0.step[0] = 0;
}

static inline void orderStep3E_0(SpaniTask* task, s32 port) {
    s8 prev;
    s8 slot;
    s32 j;

    if (isLockState(lbl_803C66B0.rows[9].port[port], 0)) {
        if (lbl_803297E0._CF46[port] == 0) {
            prev = lbl_803297E0._CF48[port] - 1;
            slot = lbl_80354720[port][prev]._2;
            switch (lbl_803297E0._CF52[port]) {
            case 0:
                getGridObj(task, prev, port * 9, 0x40)->_68 = 4;
                getGridObj(task, prev, port * 9, 0x1C)->_5C = 10 << 16;
                getGridObj(task, prev, port * 9, 0x1C)->_68 = 4;
                for (j = 0; j < 9; j++) {
                    lbl_80371C30[task->_14 + 0x64 + j + port * 9].obj->_54 &= ~2;
                }
                break;
            case 1:
                getGridObj(task, slot, port * 9, 0x10A)->_68 = 4;
                getGridObj(task, slot, port * 9, 0xF8)->_68 = 4;
                getGridObj(task, slot, port * 9, 0xE6)->_54 &= ~2;
                for (j = 0; j < 9; j++) {
                    lbl_80371C30[task->_14 + 0x12E + j + port * 9].obj->_54 &= ~2;
                }
                break;
            }
        }
        getTeamObj(task, port, 0x18)->_5C = 0;
        getTeamObj(task, port, 0x18)->_68 = 1;
        fn_800626EC(port);
        lbl_803C66B0.rows[9].port[port] = 1;
    }
    if (lbl_803C66B0.rows[9].port[port] == 1) {
        fn_80062674(port);
        lbl_803C66B0.rows[9].port[port] = 2;
    }
}

static inline void orderStep3E_1(SpaniTask* task, s32 port) {
    s8 prev;
    s8 slot;
    s32 j;

    if (isLockState(lbl_803C66B0.rows[9].port[port], 0)) {
        switch (lbl_803297E0._CF52[port]) {
        case 0:
            prev = lbl_803297E0._CF48[port] - 1;
            getTeamObj(task, prev, 0x63)->_68 = 4;
            getTeamObj(task, prev, 0x51)->_5C = 10 << 16;
            getTeamObj(task, prev, 0x51)->_68 = 4;
            for (j = 0; j < 9; j++) {
                lbl_80371C30[task->_14 + 0x75 + j].obj->_54 &= ~2;
                lbl_80371C30[task->_14 + 0x35 + j].obj->_54 &= ~2;
            }
            break;
        case 1:
            slot = lbl_80354720[port][lbl_803297E0._CF48[port] - 1]._2;
            getTeamObj(task, slot, 0x23)->_68 = 4;
            getTeamObj(task, slot, 0x1A)->_68 = 4;
            getTeamObj(task, slot, 0x11)->_54 &= ~2;
            for (j = 0; j < 9; j++) {
                lbl_80371C30[task->_14 + 0x35 + j].obj->_54 &= ~2;
                lbl_80371C30[task->_14 + 0x75 + j].obj->_54 &= ~2;
            }
            break;
        }
        getSpaniObj(task, 0xE)->_5C = 0;
        getSpaniObj(task, 0xE)->_68 = 1;
        fn_800626EC(port);
        lbl_803C66B0.rows[9].port[port] = 1;
    }
    if (lbl_803C66B0.rows[9].port[port] == 1) {
        fn_80062674(port);
        lbl_803C66B0.rows[9].port[port] = 2;
    }
}

static inline void helperW(SpaniTask* task, s32 team) {
    s32 done;

    if (lbl_803297E0._CF61[lbl_803297E0._CF3B] != 0) {
        switch (lbl_803297E0._CF67[team]) {
        case 0:
            fn_80058644(task);
            break;
        case 1:
            fn_80058394(task);
            break;
        }
    } else {
        if (lbl_803297E0._CF67[team] == 0) {
            if ((getSpaniObj(task, 0x118)->_5C >> 16) > 5) {
                getSpaniObj(task, 0x118)->_5C = 5 << 16;
            }
            getSpaniObj(task, 0x118)->_68 = 4;
            getSpaniObj(task, 0x119)->_68 = 4;
            getSpaniObj(task, 0x121)->_68 = 4;
            done = isAnimDone(task, 0x118, 0);
            done += isAnimDone(task, 0x119, 0);
            done += isAnimDone(task, 0x121, 0);
            if (done == 3) {
                lbl_803297E0._CF65[team] = 0;
            }
        } else {
            if ((getSpaniObj(task, 0x118)->_5C >> 16) > 5) {
                getSpaniObj(task, 0x118)->_5C = 5 << 16;
            }
            getSpaniObj(task, 0x118)->_68 = 4;
            getSpaniObj(task, 0x12F)->_68 = 4;
            if (isAnimDone(task, 0x12F, 0) == 1) {
                lbl_803297E0._CF65[lbl_803297E0._CF3B] = 0;
            }
        }
        lbl_803297E0._CF63[lbl_803297E0._CF3B] = 0;
    }
}

static inline void helperX(SpaniTask* task) {
    s32 done;
    s32 i;

    if (lbl_803297E0._CF73 != 0) {
        done = isAnimDone(task, g_d_GameSettings._06 == 2 ? 0x16E : 0x1D7, 0);
        done += isAnimDone(task, g_d_GameSettings._06 == 2 ? 0x16A : 0x1D3, 0);
        done += isAnimDone(task, g_d_GameSettings._06 == 2 ? 0x16C : 0x1D5, 0);
        if (done == 3) {
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16A : 0x1D3)->_54 &= ~2;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16B : 0x1D4)->_54 &= ~2;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16C : 0x1D5)->_54 &= ~2;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16E : 0x1D7)->_54 &= ~2;
        for (i = 0; i < 3; i++) {
            fn_8000FEE8(lbl_803297E0.texts[i]);
        }
        fn_8000F8F4((struct TextModelSet*)task);
        lbl_803297E0._CF71[1] = 0;
        lbl_803297E0._CF74 = 0;
        lbl_803297E0._CF73 = 0;
        }
    }
}

// .text:0x80060184 size:0x1A18
void fn_80060184(void) {
    SpaniTask* task = lbl_803CC1B8;
    s32 i;
    s32 j;
    s32 k;
    u8 port;
    s32 done;
    s32 count;
    s8 prev;
    s8 slot;
    s8 last;
    s8 cur;
    s8 curSlot;
    s8 lastSlot;
    s8 flags;
    u8 played;

    for (i = 0; i < 2; i++) {
        port = lbl_803C66B0.active[i + 4];
        switch (lbl_803C66B0.step[i]) {
        case 0x38:
            orderStep38(task, port);
            break;
        case 0x39:
            if (g_d_GameSettings._06 != 2) {
                fn_8005F734(task, port);
                if (isLockState(lbl_803C66B0.rows[9].port[port], 1)) {
                    count = 1;
                    done = isAnimDone(task, port + 0x14, 10);
                    if (g_d_GameSettings._10 == 0 && port == 0) {
                        count++;
                        done += isAnimDone(task, port, 30);
                        count++;
                        done += isAnimDone(task, port + 0x12, 20);
                    } else {
                        count++;
                        done += isAnimDone(task, port, 20);
                        count++;
                        done += isAnimDone(task, port + 0x12, 10);
                    }
                    count++;
                    done += isAnimDone(task, port + 4, 20);
                    count++;
                    done += isAnimDone(task, port + 10, 10);
                    if (done == count) {
                        if (g_d_GameSettings._10 == 0) {
                            lbl_803297E0._CF5B[port] = 1;
                            if (lbl_803297E0._CF5B[0] != 0 && lbl_803297E0._CF5B[1] != 0) {
                                lbl_803297E0._CF5B[1] = 0;
                                lbl_803297E0._CF5B[0] = 0;
                                fn_80062674(0);
                                fn_80062674(1);
                                lbl_803C66B0.rows[9].port[0] = 2;
                                lbl_803C66B0.rows[9].port[1] = 2;
                            }
                        } else {
                            fn_80062674(port);
                            lbl_803C66B0.rows[9].port[port] = 2;
                        }
                    }
                }
            }
            break;
        case 0x3A:
            orderStep3A(task, port);
            break;
        case 0x3C:
            orderStep3C(task, port);
            break;
        case 0x3D:
            orderStep3D(task, port);
            break;
        case 0x3E:
            if (g_d_GameSettings._06 != 2) {
                orderStep3E_0(task, port);
            } else {
                orderStep3E_1(task, port);
            }
            break;
        case 0x3B:
            orderStep3B(task, port);
            break;
        case 0x3F:
            orderStep3F(task, port);
            break;
        case 0x40:
            orderStep40(task, port);
            break;
        case 0x41:
            orderStep41(task, port);
            break;
        case 0x42:
            orderStep42(task, port);
            break;
        case 0x43:
            orderStep43(task, port);
            break;
        case 0x44:
            orderStep44(task, port);
            break;
        case 0x45:
            orderStep45(task, port);
            break;
        case 0x46:
            orderStep46(task, port);
            break;
        }
        fn_8005A350(task, port);
    }
    if (lbl_803297E0._CF40[5] != 0) {
        lbl_803297E0._CF40[5] = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
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
// 97.39%: the target compares the count with 5 held in r27 (set just before
// each branch's last call) and branches around the second flag test.
void fn_8005F9D0(SpaniTask* task, s32 team) {
    s32 done;

    if (isLockState(lbl_803C66B0.rows[9].port[team], 1)) {
        done = isAnimDone(task, team + 4, 20);
        if (g_d_GameSettings.GameModeSelected != 5) {
            if (g_d_GameSettings._10 == 0 && team != 0) {
                done += isAnimDone(task, team, 30);
                done += isAnimDone(task, team + 10, 10);
                done += isAnimDone(task, team + 0x12, 20);
                done += isAnimDone(task, team + 0x14, 10);
            } else {
                done += isAnimDone(task, team, 20);
                done += isAnimDone(task, team + 10, 10);
                done += isAnimDone(task, team + 0x12, 10);
                done += isAnimDone(task, team + 0x14, 10);
            }
        } else {
            done += isAnimDone(task, team, 20);
            done += isAnimDone(task, team + 10, 10);
            done += isAnimDone(task, 0x12, 10);
            done += isAnimDone(task, 0x14, 10);
        }
        if (done == 5) {
            if (g_d_GameSettings._10 == 0) {
                lbl_803297E0._CF5B[team] = 1;
                if (lbl_803297E0._CF5B[0] != 0) {
                    if (lbl_803297E0._CF5B[1] == 0) {
                        return;
                    }
                    lbl_803297E0._CF5B[1] = 0;
                    lbl_803297E0._CF5B[0] = 0;
                    fn_80062674(0);
                    fn_80062674(1);
                    lbl_803C66B0.rows[9].port[0] = 2;
                    lbl_803C66B0.rows[9].port[1] = 2;
                    if (g_d_GameSettings.GameModeSelected == 5) {
                        fn_800625A4(0, 0x45);
                    }
                }
            } else {
                fn_80062674(team);
                lbl_803C66B0.rows[9].port[team] = 2;
            }
        }
    }
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
void fn_8005F068(SpaniTask* task, s32 team) {
    s32 i;
    s8 cur;
    s8 slot;
    s8 prev;
    s8 prevSlot;

    if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
        cur = lbl_803297E0._CF46[team] - 1;
        slot = lbl_80354720[team][cur]._2;
        if (lbl_803297E0._CF3E[team] != 0xFF) {
            prev = lbl_803297E0._CF3E[team];
            prevSlot = lbl_80354720[team][prev]._2;
        }
        switch (lbl_803297E0._CF52[team]) {
        case 0:
            if (lbl_803297E0._CF54[team] == 1) {
                getTeamObj(task, team, 0x14)->_5C = 20 << 16;
                getTeamObj(task, team, 0x14)->_68 = 4;
                getTeamObj(task, team, 0x1A)->_68 = 1;
                getTeamObj(task, team, 0xE2)->_68 = 4;
                getTeamObj(task, team, 0xE4)->_68 = 4;
                for (i = 0; i < 9; i++) {
                    lbl_80371C30[task->_14 + 0x64 + i + team * 9].obj->_54 &= ~2;
                    lbl_80371C30[task->_14 + 0x1C + i + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x1C + i + team * 9].obj->_68 = 0;
                    lbl_80371C30[task->_14 + 0x40 + i + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x40 + i + team * 9].obj->_68 = 0;
                }
                if (cur >= 0 && cur < 9) {
                    lbl_80371C30[task->_14 + 0x1C + cur + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x1C + cur + team * 9].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x52 + cur + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x52 + cur + team * 9].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x64 + cur + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x64 + cur + team * 9].obj->_64 = 0x2A;
                    lbl_80371C30[task->_14 + 0x64 + cur + team * 9].obj->_68 = 1;
                    fn_8005C830(task, team, cur);
                    lbl_80371C30[task->_14 + 0x40 + cur + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x40 + cur + team * 9].obj->_68 = 1;
                    if (lbl_803297E0._CF3E[team] != 0xFF) {
                        lbl_80371C30[task->_14 + 0x1C + prev + team * 9].obj->_5C = 10 << 16;
                        lbl_80371C30[task->_14 + 0x1C + prev + team * 9].obj->_68 = 0;
                        lbl_80371C30[task->_14 + 0x40 + prev + team * 9].obj->_5C = 0;
                        lbl_80371C30[task->_14 + 0x40 + prev + team * 9].obj->_68 = 1;
                    }
                }
            }
            break;
        case 1:
            if (lbl_803297E0._CF54[team] != 1) {
                for (i = 0; i < 9; i++) {
                    lbl_80371C30[task->_14 + 0x10A + i + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x10A + i + team * 9].obj->_68 = 0;
                    lbl_80371C30[task->_14 + 0xF8 + i + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0xF8 + i + team * 9].obj->_68 = 0;
                    lbl_80371C30[task->_14 + 0xE6 + i + team * 9].obj->_54 &= ~2;
                    lbl_80371C30[task->_14 + 0x12E + i + team * 9].obj->_54 &= ~2;
                }
                getTeamObj(task, team, 0x14)->_5C = 10 << 16;
                getTeamObj(task, team, 0x14)->_68 = 1;
                getTeamObj(task, team, 0x1A)->_68 = 4;
                getTeamObj(task, team, 0xE2)->_68 = 1;
                getTeamObj(task, team, 0xE4)->_68 = 1;
                getTeamObj(task, team, 0xE2)->_54 |= 2;
                getTeamObj(task, team, 0xE4)->_54 |= 2;
                if (cur >= 0 && cur < 9) {
                    lbl_80371C30[task->_14 + 0x10A + slot + team * 9].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0xF8 + slot + team * 9].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0xE6 + slot + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x12E + slot + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x12E + slot + team * 9].obj->_64 = 0x2A;
                    lbl_80371C30[task->_14 + 0x12E + slot + team * 9].obj->_68 = 1;
                    fn_8005C830(task, team, cur);
                    if (lbl_803297E0._CF3E[team] != 0xFF) {
                        lbl_80371C30[task->_14 + 0x10A + prevSlot + team * 9].obj->_68 = 1;
                        lbl_80371C30[task->_14 + 0xF8 + prevSlot + team * 9].obj->_68 = 1;
                    }
                }
            }
            break;
        }
        fn_800626EC(team);
        lbl_803C66B0.rows[9].port[team] = 1;
    }
}

// .text:0x8005EC88 size:0x3E0
void fn_8005EC88(SpaniTask* task, s32 team) {
    s32 i;
    s32 cur;
    s8 slot;

    if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
        if (lbl_803297E0._CF46[team] != 0) {
            cur = lbl_803297E0._CF46[team] - 1;
            slot = lbl_80354720[team][cur]._2;
            for (i = 0; i < 9; i++) {
                lbl_80371C30[task->_14 + 0x64 + i + team * 9].obj->_54 &= ~2;
                lbl_80371C30[task->_14 + 0x12E + i + team * 9].obj->_54 &= ~2;
            }
            switch (lbl_803297E0._CF52[team]) {
            case 0:
                lbl_80371C30[task->_14 + 0x40 + cur + team * 9].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x1C + cur + team * 9].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x1C + cur + team * 9].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x52 + cur + team * 9].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x52 + cur + team * 9].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x64 + cur + team * 9].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x64 + cur + team * 9].obj->_64 = 0x2A;
                lbl_80371C30[task->_14 + 0x64 + cur + team * 9].obj->_68 = 1;
                fn_8005C830(task, team, cur);
                break;
            case 1:
                lbl_80371C30[task->_14 + 0x10A + slot + team * 9].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0xF8 + slot + team * 9].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x12E + slot + team * 9].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x12E + slot + team * 9].obj->_64 = 0x2A;
                lbl_80371C30[task->_14 + 0x12E + slot + team * 9].obj->_68 = 1;
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
                lbl_80371C30[task->_14 + 0x1C + cur + team * 9].obj->_5C = 0xA0000;
                lbl_80371C30[task->_14 + 0x1C + cur + team * 9].obj->_68 = 0;
                lbl_80371C30[task->_14 + 0x40 + cur + team * 9].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x40 + cur + team * 9].obj->_68 = 1;
            } else if (g_d_GameSettings._06 != 2) {
                lbl_80371C30[task->_14 + 0x10A + slot + team * 9].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x10A + slot + team * 9].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0xF8 + slot + team * 9].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0xF8 + slot + team * 9].obj->_68 = 1;
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
    s32 i;
    s8 prev;
    s8 cur;
    s8 last;
    s8 slot;
    s8 prevSlot;
    s8 lastSlot;

    if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
        cur = lbl_803297E0._CF46[team] - 1;
        prev = lbl_803297E0._CF48[team] - 1;
        last = lbl_803297E0._CF3E[team];
        if (lbl_803297E0._CF52[team] == 0) {
            if (g_d_GameSettings._06 != 2) {
                for (i = 0; i < 9; i++) {
                    lbl_80371C30[task->_14 + 0x64 + i + team * 9].obj->_54 &= ~2;
                }
                getGridObj(task, cur, team * 9, 0x40)->_5C = 0;
                getGridObj(task, cur, team * 9, 0x40)->_68 = 1;
                getGridObj(task, cur, team * 9, 0x1C)->_5C = 0;
                getGridObj(task, cur, team * 9, 0x1C)->_68 = 1;
                getGridObj(task, cur, team * 9, 0x52)->_5C = 0;
                getGridObj(task, cur, team * 9, 0x52)->_68 = 1;
                getGridObj(task, cur, team * 9, 0x64)->_54 |= 2;
                getGridObj(task, cur, team * 9, 0x64)->_64 = 0x2A;
                getGridObj(task, cur, team * 9, 0x64)->_68 = 1;
                fn_8005C830(task, team, cur);
                getGridObj(task, prev, team * 9, 0x40)->_5C = 0;
                getGridObj(task, prev, team * 9, 0x40)->_68 = 4;
                getGridObj(task, prev, team * 9, 0x1C)->_5C = 10 << 16;
                getGridObj(task, prev, team * 9, 0x1C)->_68 = 4;
                if (last != -1) {
                    getGridObj(task, last, team * 9, 0x1C)->_5C = 10 << 16;
                    getGridObj(task, last, team * 9, 0x1C)->_68 = 0;
                    getGridObj(task, last, team * 9, 0x40)->_68 = 1;
                }
            } else {
                slot = lbl_80354720[team][cur]._2;
                for (i = 0; i < 9; i++) {
                    lbl_80371C30[task->_14 + 0x75 + i].obj->_54 &= ~2;
                    lbl_80371C30[task->_14 + 0x35 + i].obj->_54 &= ~2;
                }
                lbl_80371C30[task->_14 + 0x63 + cur].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x63 + cur].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x51 + cur].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x51 + cur].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x6C + cur].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x75 + cur].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x75 + cur].obj->_64 = 0x2A;
                lbl_80371C30[task->_14 + 0x6C + cur].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x75 + cur].obj->_68 = 1;
                fn_8005C830(task, team, cur);
                lbl_80371C30[task->_14 + 0x63 + prev].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x63 + prev].obj->_68 = 4;
                lbl_80371C30[task->_14 + 0x51 + prev].obj->_5C = 10 << 16;
                lbl_80371C30[task->_14 + 0x51 + prev].obj->_68 = 4;
                lbl_80371C30[task->_14 + 0x35 + slot].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x35 + slot].obj->_64 = 0x2A;
                lbl_80371C30[task->_14 + 0x35 + slot].obj->_68 = 1;
                if (last != -1) {
                    lbl_80371C30[task->_14 + 0x51 + last].obj->_5C = 10 << 16;
                    lbl_80371C30[task->_14 + 0x51 + last].obj->_68 = 0;
                    lbl_80371C30[task->_14 + 0x63 + last].obj->_68 = 1;
                }
            }
        } else {
            slot = lbl_80354720[team][cur]._2;
            prevSlot = lbl_80354720[team][prev]._2;
            lastSlot = lbl_80354720[team][last]._2;
            if (g_d_GameSettings._06 != 2) {
                getGridObj(task, slot, team * 9, 0x10A)->_68 = 1;
                getGridObj(task, slot, team * 9, 0xF8)->_68 = 1;
                getGridObj(task, slot, team * 9, 0xE6)->_54 |= 2;
                getGridObj(task, prevSlot, team * 9, 0x10A)->_68 = 4;
                getGridObj(task, prevSlot, team * 9, 0xF8)->_68 = 4;
                getGridObj(task, prevSlot, team * 9, 0xE6)->_54 &= ~2;
                for (i = 0; i < 9; i++) {
                    lbl_80371C30[task->_14 + 0x12E + i + team * 9].obj->_54 &= ~2;
                }
                getGridObj(task, slot, team * 9, 0x12E)->_54 |= 2;
                getGridObj(task, slot, team * 9, 0x12E)->_64 = 0x2A;
                getGridObj(task, slot, team * 9, 0x12E)->_68 = 1;
                fn_8005C830(task, team, cur);
                if (last != -1) {
                    getGridObj(task, lastSlot, team * 9, 0x10A)->_68 = 1;
                    getGridObj(task, lastSlot, team * 9, 0xF8)->_68 = 1;
                }
            } else {
                lbl_80371C30[task->_14 + 0x23 + slot].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x1A + slot].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x11 + slot].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x23 + prevSlot].obj->_68 = 4;
                lbl_80371C30[task->_14 + 0x1A + prevSlot].obj->_68 = 4;
                lbl_80371C30[task->_14 + 0x11 + prevSlot].obj->_54 &= ~2;
                for (i = 0; i < 9; i++) {
                    lbl_80371C30[task->_14 + 0x35 + i].obj->_54 &= ~2;
                    lbl_80371C30[task->_14 + 0x75 + i].obj->_54 &= ~2;
                }
                lbl_80371C30[task->_14 + 0x6C + cur].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x6C + cur].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x6C + cur].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x75 + cur].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x75 + cur].obj->_64 = 0x2A;
                lbl_80371C30[task->_14 + 0x75 + cur].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x35 + slot].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x35 + slot].obj->_64 = 0x2A;
                lbl_80371C30[task->_14 + 0x35 + slot].obj->_68 = 1;
                if (last != -1) {
                    lbl_80371C30[task->_14 + 0x23 + lastSlot].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x1A + lastSlot].obj->_68 = 1;
                }
                fn_8005C830(task, team, cur);
            }
        }
        fn_800626EC(team);
        lbl_803C66B0.rows[9].port[team] = 1;
    }
}

// .text:0x8005CCE4 size:0x1130
void fn_8005CCE4(SpaniTask* task, s32 team) {
    u8 last;
    s32 cur;
    s8 curSlot;
    s8 lastSlot;
    s8 slot;
    s32 i;
    u8 flag;

    if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
        last = lbl_803297E0._CF3E[team];
        cur = lbl_803297E0._CF46[team] - 1;
        curSlot = lbl_80354720[team][cur]._2;
        lastSlot = lbl_80354720[team][last]._2;
        if (lbl_803297E0._CF52[team] == 0) {
            if (cur != last) {
                lbl_80371C30[task->_14 + 0x1C + last + team * 9].obj->_5C = 10 << 16;
                lbl_80371C30[task->_14 + 0x1C + last + team * 9].obj->_68 = 4;
            }
            lbl_80371C30[task->_14 + 0x40 + last + team * 9].obj->_68 = 4;
            fn_800363D8(task, 0x40 + cur + team * 9, 1, 0x83, inMemRoster[team][cur].stats.CharID);
            fn_800363D8(task, 0x40 + last + team * 9, 1, 0x83, inMemRoster[team][last].stats.CharID);
            lbl_80371C30[task->_14 + 0xD0 + cur + team * 9].obj->_5C = inMemRoster[team][cur].stats.CharacterClass << 16;
            lbl_80371C30[task->_14 + 0xD0 + last + team * 9].obj->_5C = inMemRoster[team][last].stats.CharacterClass << 16;
            lbl_80371C30[task->_14 + 0xAC + cur + team * 9].obj->_5C = (inMemRoster[team][cur].stats.BattingStance + inMemRoster[team][cur].stats.FieldingArm * 2) << 16;
            lbl_80371C30[task->_14 + 0xAC + last + team * 9].obj->_5C = (inMemRoster[team][last].stats.BattingStance + inMemRoster[team][last].stats.FieldingArm * 2) << 16;
            for (i = 0; i < 9; i++) {
                if (g_d_GameSettings.GameModeSelected == 5) {
                    flag = starMissionCompletionTracker._43D6[inMemRoster[team][i].stats.CharID];
                } else {
                    flag = lbl_8034E9A0._489B[team][i];
                }
                if (flag != 0) {
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x76 : 0x7E)->_54 |= 2;
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x76 : 0x7E)->_68 = 1;
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x88 : 0x87)->_54 |= 2;
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x88 : 0x87)->_5C = 15 << 16;
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x88 : 0x87)->_68 = 1;
                } else if (lbl_80361B20._00[0][inMemRoster[team][i].stats.CharID] != 0 && g_d_GameSettings.GameModeSelected != 5) {
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x76 : 0x7E)->_54 |= 2;
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x76 : 0x7E)->_68 = 1;
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x88 : 0x87)->_54 |= 2;
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x88 : 0x87)->_5C = 0;
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x88 : 0x87)->_68 = 0;
                } else {
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x76 : 0x7E)->_54 &= ~2;
                    getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x88 : 0x87)->_54 &= ~2;
                }
                if (g_d_GameSettings._06 != 2) {
                    lbl_80371C30[task->_14 + 0x64 + i + team * 9].obj->_54 &= ~2;
                } else {
                    lbl_80371C30[task->_14 + 0x75 + i].obj->_54 &= ~2;
                }
            }
            lbl_80371C30[task->_14 + 0x64 + cur + team * 9].obj->_54 |= 2;
            lbl_80371C30[task->_14 + 0x64 + cur + team * 9].obj->_64 = 0x2A;
            lbl_80371C30[task->_14 + 0x64 + cur + team * 9].obj->_68 = 1;
            fn_8005C830(task, team, cur);
        } else {
            if (g_d_GameSettings._06 != 2) {
                fn_800363D8(task, 0x10A + lastSlot + team * 9, 1, 0x83, inMemRoster[team][last].stats.CharID);
                fn_800363D8(task, 0x10A + curSlot + team * 9, 1, 0x83, inMemRoster[team][cur].stats.CharID);
                lbl_80371C30[task->_14 + 0x10A + curSlot + team * 9].obj->_68 = 4;
                lbl_80371C30[task->_14 + 0xF8 + curSlot + team * 9].obj->_68 = 4;
                lbl_80371C30[task->_14 + 0x10A + lastSlot + team * 9].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0xF8 + lastSlot + team * 9].obj->_68 = 1;
                for (i = 0; i < 9; i++) {
                    slot = lbl_80354720[team][i]._2;
                    if (g_d_GameSettings.GameModeSelected == 5) {
                        flag = starMissionCompletionTracker._43D6[inMemRoster[team][i].stats.CharID];
                    } else {
                        flag = lbl_8034E9A0._489B[team][i];
                    }
                    if (flag != 0) {
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x140 : 0x3E)->_54 |= 2;
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x140 : 0x3E)->_68 = 1;
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x152 : 0x47)->_54 |= 2;
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x152 : 0x47)->_5C = 15 << 16;
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x152 : 0x47)->_68 = 1;
                    } else if (lbl_80361B20._00[0][inMemRoster[team][i].stats.CharID] != 0 && g_d_GameSettings.GameModeSelected != 5) {
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x140 : 0x3E)->_54 |= 2;
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x140 : 0x3E)->_68 = 1;
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x152 : 0x47)->_54 |= 2;
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x152 : 0x47)->_5C = 0;
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x152 : 0x47)->_68 = 0;
                    } else {
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x140 : 0x3E)->_54 &= ~2;
                        getTeamObj(task, slot, g_d_GameSettings._06 != 2 ? team * 9 + 0x152 : 0x47)->_54 &= ~2;
                    }
                    lbl_80371C30[task->_14 + 0x12E + i + team * 9].obj->_54 &= ~2;
                }
                lbl_80371C30[task->_14 + 0x12E + lastSlot + team * 9].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x12E + lastSlot + team * 9].obj->_64 = 0x2A;
                lbl_80371C30[task->_14 + 0x12E + lastSlot + team * 9].obj->_68 = 1;
            } else {
                fn_800363D8(task, lastSlot + 0x23, 1, 0x83, inMemRoster[team][last].stats.CharID);
                fn_800363D8(task, curSlot + 0x23, 1, 0x83, inMemRoster[team][cur].stats.CharID);
                lbl_80371C30[task->_14 + 0x23 + curSlot].obj->_68 = 4;
                lbl_80371C30[task->_14 + 0x1A + curSlot].obj->_68 = 4;
                lbl_80371C30[task->_14 + 0x23 + lastSlot].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x1A + lastSlot].obj->_68 = 1;
                for (i = 0; i < 9; i++) {
                    slot = lbl_80354720[team][i]._2;
                    if (g_d_GameSettings.GameModeSelected == 5) {
                        flag = starMissionCompletionTracker._43D6[inMemRoster[team][i].stats.CharID];
                    } else {
                        flag = lbl_8034E9A0._489B[team][i];
                    }
                    if (flag != 0 && (team != 1 || g_d_GameSettings.GameModeSelected != 5)) {
                        lbl_80371C30[task->_14 + 0x3E + slot].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x3E + slot].obj->_68 = 1;
                        lbl_80371C30[task->_14 + 0x47 + slot].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x47 + slot].obj->_5C = 15 << 16;
                        lbl_80371C30[task->_14 + 0x47 + slot].obj->_68 = 1;
                        lbl_80371C30[task->_14 + 0x7E + i].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x7E + i].obj->_68 = 1;
                        lbl_80371C30[task->_14 + 0x87 + i].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x87 + i].obj->_5C = 15 << 16;
                        lbl_80371C30[task->_14 + 0x87 + i].obj->_68 = 1;
                    } else if (lbl_80361B20._00[0][inMemRoster[team][i].stats.CharID] != 0 && g_d_GameSettings.GameModeSelected != 5) {
                        lbl_80371C30[task->_14 + 0x3E + slot].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x3E + slot].obj->_68 = 1;
                        lbl_80371C30[task->_14 + 0x47 + slot].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x47 + slot].obj->_5C = 0;
                        lbl_80371C30[task->_14 + 0x47 + slot].obj->_68 = 0;
                        lbl_80371C30[task->_14 + 0x7E + i].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x7E + i].obj->_68 = 1;
                        lbl_80371C30[task->_14 + 0x87 + i].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x87 + i].obj->_5C = 0;
                        lbl_80371C30[task->_14 + 0x87 + i].obj->_68 = 0;
                    } else {
                        lbl_80371C30[task->_14 + 0x3E + slot].obj->_54 &= ~2;
                        lbl_80371C30[task->_14 + 0x47 + slot].obj->_54 &= ~2;
                        getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x76 : 0x7E)->_54 &= ~2;
                        getTeamObj(task, i, g_d_GameSettings._06 != 2 ? team * 9 + 0x88 : 0x87)->_54 &= ~2;
                    }
                    lbl_80371C30[task->_14 + 0x35 + i].obj->_54 &= ~2;
                    lbl_80371C30[task->_14 + 0x75 + i].obj->_54 &= ~2;
                }
                lbl_80371C30[task->_14 + 0x75 + last].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x75 + last].obj->_64 = 0x2A;
                lbl_80371C30[task->_14 + 0x75 + last].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x35 + lastSlot].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x35 + lastSlot].obj->_64 = 0x2A;
                lbl_80371C30[task->_14 + 0x35 + lastSlot].obj->_68 = 1;
            }
            fn_8005C830(task, team, last);
            lbl_803297E0._CF46[team] = fn_80042598(team, lbl_80354720[team][last]._2);
        }
        lbl_803297E0._CF3E[team] = -1;
        lbl_803C66B0.step[team] = 0;
        lbl_803C66B0.rows[9].port[team] = 2;
    }
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
                        lbl_80371C30[task->_14 + 0x52 + i + team * 9].obj->_5C = 0;
                        lbl_80371C30[task->_14 + 0x52 + i + team * 9].obj->_68 = 1;
                        lbl_80371C30[task->_14 + 0x64 + i + team * 9].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x64 + i + team * 9].obj->_64 = 0x2B;
                        lbl_80371C30[task->_14 + 0x64 + i + team * 9].obj->_68 = 1;
                    } else {
                        lbl_80371C30[task->_14 + 0x35 + lbl_80354720[team][i]._2].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x35 + lbl_80354720[team][i]._2].obj->_64 = 0x2B;
                        lbl_80371C30[task->_14 + 0x35 + lbl_80354720[team][i]._2].obj->_5C = 0;
                        lbl_80371C30[task->_14 + 0x35 + lbl_80354720[team][i]._2].obj->_68 = 1;
                        lbl_80371C30[task->_14 + 0x6C + i].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x6C + i].obj->_5C = 0;
                        lbl_80371C30[task->_14 + 0x6C + i].obj->_68 = 1;
                        lbl_80371C30[task->_14 + 0x75 + i].obj->_54 |= 2;
                        lbl_80371C30[task->_14 + 0x75 + i].obj->_64 = 0x2B;
                        lbl_80371C30[task->_14 + 0x75 + i].obj->_68 = 1;
                    }
                } else if (g_d_GameSettings._06 != 2) {
                    lbl_80371C30[task->_14 + 0x12E + lbl_80354720[team][i]._2 + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x12E + lbl_80354720[team][i]._2 + team * 9].obj->_64 = 0x2B;
                    lbl_80371C30[task->_14 + 0x12E + lbl_80354720[team][i]._2 + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x12E + lbl_80354720[team][i]._2 + team * 9].obj->_68 = 1;
                } else {
                    lbl_80371C30[task->_14 + 0x35 + lbl_80354720[team][i]._2].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x35 + lbl_80354720[team][i]._2].obj->_64 = 0x2B;
                    lbl_80371C30[task->_14 + 0x35 + lbl_80354720[team][i]._2].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x35 + lbl_80354720[team][i]._2].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x6C + i].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x6C + i].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x6C + i].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x75 + i].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x75 + i].obj->_64 = 0x2B;
                    lbl_80371C30[task->_14 + 0x75 + i].obj->_68 = 1;
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
void fn_8005C2B0(SpaniTask* task) {
    s32 team;
    s32 i;
    u8 flag;

    for (team = 0; team < 2; team++) {
        for (i = 0; i < 9; i++) {
            fn_800363D8(task, i + 0x40 + team * 9, 1, 0x83, inMemRoster[team][i].stats.CharID);
            getGridObj(task, i, team * 9, 0x2E)->_5C = i << 16;
            getGridObj(task, i, team * 9, 0xD0)->_5C = inMemRoster[team][i].stats.CharacterClass << 16;
            getGridObj(task, i, team * 9, 0xAC)->_5C = (inMemRoster[team][i].stats.BattingStance + inMemRoster[team][i].stats.FieldingArm * 2) << 16;
            if (g_d_GameSettings.GameModeSelected == 5) {
                flag = starMissionCompletionTracker._43D6[inMemRoster[team][i].stats.CharID];
            } else {
                flag = lbl_8034E9A0._489B[team][i];
            }
            if (flag != 0) {
                getGridObj(task, i, team * 9, 0x76)->_68 = 1;
                getGridObj(task, i, team * 9, 0x88)->_54 |= 2;
                getGridObj(task, i, team * 9, 0x88)->_5C = 0;
                getGridObj(task, i, team * 9, 0x88)->_68 = 1;
            } else if (lbl_80361B20._00[0][inMemRoster[team][i].stats.CharID] != 0) {
                getGridObj(task, i, team * 9, 0x76)->_68 = 1;
                getGridObj(task, i, team * 9, 0x88)->_54 |= 2;
                getGridObj(task, i, team * 9, 0x88)->_5C = 0;
                getGridObj(task, i, team * 9, 0x88)->_68 = 0;
            } else {
                getGridObj(task, i, team * 9, 0x88)->_54 &= ~2;
            }
            getGridObj(task, i, team * 9, 0x64)->_54 &= ~2;
        }
        getTeamObj(task, team, 8)->_5C = lbl_8034E9A0._470D[team] << 16;
        getTeamObj(task, team, 0xC)->_5C = lbl_8034E9A0._470D[team] << 16;
    }
}

// .text:0x8005BF40 size:0x370
void fn_8005BF40(SpaniTask* task) {
    s32 team;
    s32 i;
    u8 flag;

    for (team = 0; team < 2; team++) {
        for (i = 0; i < 9; i++) {
            fn_800363D8(task, lbl_80354720[team][i]._2 + 0x10A + team * 9, 1, 0x83, inMemRoster[team][i].stats.CharID);
            lbl_80371C30[task->_14 + 0xE6 + i + team * 9].obj->_54 &= ~2;
            if (g_d_GameSettings.GameModeSelected == 5) {
                flag = starMissionCompletionTracker._43D6[inMemRoster[team][i].stats.CharID];
            } else {
                flag = lbl_8034E9A0._489B[team][i];
            }
            if (flag != 0) {
                lbl_80371C30[task->_14 + 0x140 + lbl_80354720[team][i]._2 + team * 9].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x152 + lbl_80354720[team][i]._2 + team * 9].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x152 + lbl_80354720[team][i]._2 + team * 9].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x152 + lbl_80354720[team][i]._2 + team * 9].obj->_68 = 1;
            } else if (lbl_80361B20._00[0][inMemRoster[team][i].stats.CharID] != 0) {
                lbl_80371C30[task->_14 + 0x140 + lbl_80354720[team][i]._2 + team * 9].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x152 + lbl_80354720[team][i]._2 + team * 9].obj->_54 |= 2;
                lbl_80371C30[task->_14 + 0x152 + lbl_80354720[team][i]._2 + team * 9].obj->_5C = 0;
                lbl_80371C30[task->_14 + 0x152 + lbl_80354720[team][i]._2 + team * 9].obj->_68 = 0;
            } else {
                lbl_80371C30[task->_14 + 0x152 + lbl_80354720[team][i]._2 + team * 9].obj->_54 &= ~2;
            }
            lbl_80371C30[task->_14 + 0x12E + i + team * 9].obj->_54 &= ~2;
            if (g_d_GameSettings._10 == 0 && team != 0) {
                lbl_80371C30[task->_14 + 0xF8 + i + team * 9].obj->_64 = (s8)(lbl_8034E9A0.ports[0] == 0) + 30;
            } else {
                lbl_80371C30[task->_14 + 0xF8 + i + team * 9].obj->_64 = lbl_8034E9A0.ports[team] + 30;
            }
        }
    }
}

// .text:0x8005BB5C size:0x3E4
// 95.34%: registers from the second team's branch on; the base hoists
// &inMemRoster[1][i] out of the scout-flag loop.
void fn_8005BB5C(SpaniTask* task) {
    s32 team;
    s32 i;
    s32 j;
    u8 flag;

    for (team = 0; team < 2; team++) {
        for (i = 0; i < 9; i++) {
            fn_800363D8(task, i + 0x40 + team * 9, 1, 0x83, inMemRoster[team][i].stats.CharID);
            getGridObj(task, i, team * 9, 0x2E)->_5C = i << 16;
            if (team == 0) {
                getTeamObj(task, i, 0xD0)->_5C = inMemRoster[0][i].stats.CharacterClass << 16;
                getTeamObj(task, i, 0xAC)->_5C = (inMemRoster[0][i].stats.BattingStance + inMemRoster[0][i].stats.FieldingArm * 2) << 16;
                getTeamObj(task, i, 0x64)->_54 &= ~2;
                if (g_d_GameSettings.GameModeSelected == 5) {
                    flag = starMissionCompletionTracker._43D6[inMemRoster[team][i].stats.CharID];
                } else {
                    flag = lbl_8034E9A0._489B[team][i];
                }
                if (flag != 0 && team == 0) {
                    getTeamObj(task, i, 0x76)->_68 = 1;
                    getTeamObj(task, i, 0x88)->_54 |= 2;
                    getTeamObj(task, i, 0x88)->_5C = 0;
                    getTeamObj(task, i, 0x88)->_68 = 1;
                } else {
                    getTeamObj(task, i, 0x88)->_54 &= ~2;
                }
            } else {
                getGridObj(task, i, team * 9, 0xD0)->_54 &= ~2;
                getGridObj(task, i, team * 9, 0xAC)->_54 &= ~2;
                getGridObj(task, i, team * 9, 0x88)->_54 &= ~2;
                getGridObj(task, i, team * 9, 0x64)->_54 &= ~2;
                for (j = 0; j < 5; j++) {
                    if (j < ((s8*)starMissionCompletionTracker.characters[inMemRoster[1][i].stats.CharID].scoutFlagPointer)[starMissionCompletionTracker._4415 * 6 + starMissionCompletionTracker._441C + 4]) {
                        getGridObj(task, j, i * 5, 0x16D)->_5C = 0;
                        getGridObj(task, j, i * 5, 0x16D)->_68 = 0;
                    } else {
                        getGridObj(task, j, i * 5, 0x16D)->_54 &= ~2;
                    }
                }
            }
        }
        getTeamObj(task, team, 8)->_5C = lbl_8034E9A0._470D[team] << 16;
        getTeamObj(task, team, 0xC)->_5C = lbl_8034E9A0._470D[team] << 16;
    }
}

// .text:0x8005B760 size:0x3FC
void fn_8005B760(SpaniTask* task, s32 team) {
    s32 cur;
    s8 slot;
    s32 i;

    if (isLockState(lbl_803C66B0.rows[9].port[team], 0)) {
        if (lbl_803297E0._CF46[team] != 0) {
            cur = lbl_803297E0._CF46[team] - 1;
            slot = lbl_80354720[team][cur]._2;
            for (i = 0; i < 9; i++) {
                lbl_80371C30[task->_14 + 0x75 + i].obj->_54 &= ~2;
                lbl_80371C30[task->_14 + 0x35 + i].obj->_54 &= ~2;
            }
            if (lbl_803297E0._CFA2[team] == 0) {
                getTeamObj(task, slot, 0x23)->_68 = 1;
                getTeamObj(task, slot, 0x1A)->_68 = 1;
            } else {
                getTeamObj(task, cur, 0x63)->_68 = 1;
                getTeamObj(task, cur, 0x51)->_54 |= 2;
                getTeamObj(task, cur, 0x51)->_5C = 0;
                getTeamObj(task, cur, 0x51)->_68 = 1;
                getTeamObj(task, cur, 0x6C)->_54 |= 2;
                getTeamObj(task, cur, 0x6C)->_5C = 0;
                getTeamObj(task, cur, 0x6C)->_68 = 1;
            }
            getTeamObj(task, cur, 0x6C)->_54 |= 2;
            getTeamObj(task, cur, 0x6C)->_5C = 0;
            getTeamObj(task, cur, 0x6C)->_68 = 1;
            getTeamObj(task, cur, 0x75)->_54 |= 2;
            getTeamObj(task, cur, 0x75)->_64 = 0x2A;
            getTeamObj(task, cur, 0x75)->_68 = 1;
            getTeamObj(task, slot, 0x35)->_54 |= 2;
            getTeamObj(task, slot, 0x35)->_64 = 0x2A;
            getTeamObj(task, slot, 0x35)->_68 = 1;
            fn_8005C830(task, team, cur);
            getSpaniObj(task, 0xE)->_5C = 0;
            getSpaniObj(task, 0xE)->_68 = 0;
        }
        fn_800626EC(team);
        lbl_803C66B0.rows[9].port[team] = 1;
    }
}

// .text:0x8005B298 size:0x4C8
// 99.02%: the base keeps one more roster pointer live, so every saved
// register is one higher, and the target has one instruction more.
void fn_8005B298(SpaniTask* task) {
    u8 flag;
    ChallengeTrackingStruct* scout;
    s8 flags;
    s32 unseen;
    s32 i;
    s32 j;
    s8 team = lbl_803297E0._CF3B;

    for (i = 0; i < 9; i++) {
        getTeamObj(task, i, 0x5A)->_5C = i << 16;
        getTeamObj(task, i, 0x6C)->_54 &= ~2;
        if (lbl_803297E0._CFA2[team] == 0) {
            fn_800363D8(task, i + 0x63, 1, 0x83, inMemRoster[team][i].stats.CharID);
            getTeamObj(task, i, 0xAB)->_5C = inMemRoster[team][i].stats.CharacterClass << 16;
            getTeamObj(task, i, 0x99)->_5C = (inMemRoster[team][i].stats.BattingStance + inMemRoster[team][i].stats.FieldingArm * 2) << 16;
            getTeamObj(task, i, 0x134)->_54 &= ~2;
        } else {
            fn_800363D8(task, i + 0x63, 1, 0x83, inMemRoster[1][i].stats.CharID);
            scout = &starMissionCompletionTracker.characters[inMemRoster[1][i].stats.CharID];
            flags = *((s8*)starMissionCompletionTracker.characters[inMemRoster[1][i].stats.CharID].scoutFlagPointer + starMissionCompletionTracker._4415 * 6 + starMissionCompletionTracker._441C + 4);
            unseen = flags - scout->scoutFlagsAchieved;
            for (j = 0; j < 5; j++) {
                if (j < flags && unseen > j) {
                    getGridObj(task, j, i * 5, 0x13D)->_5C = 0;
                } else if (j < flags) {
                    getGridObj(task, j, i * 5, 0x13D)->_68 = 1;
                    if (g_d_GameSettings._06 == 2) {
                        sndFXStartEx(0x1B1, 0x7F, 0x3F, 0);
                    } else {
                        sndFXStartEx(0x1E6, 0x7F, 0x3F, 0);
                    }
                } else {
                    getGridObj(task, j, i * 5, 0x13D)->_54 &= ~2;
                }
            }
            getTeamObj(task, i, 0xAB)->_54 &= ~2;
            getTeamObj(task, i, 0x99)->_54 &= ~2;
        }
        if (g_d_GameSettings.GameModeSelected == 5) {
            flag = starMissionCompletionTracker._43D6[inMemRoster[team][i].stats.CharID];
        } else {
            flag = lbl_8034E9A0._489B[team][i];
        }
        if (flag != 0 && (team != 1 || g_d_GameSettings.GameModeSelected != 5)) {
            getTeamObj(task, i, 0x7E)->_68 = 1;
            getTeamObj(task, i, 0x87)->_54 |= 2;
            getTeamObj(task, i, 0x87)->_5C = 0;
            getTeamObj(task, i, 0x87)->_68 = 1;
        } else if (lbl_80361B20._00[0][inMemRoster[team][i].stats.CharID] != 0 && g_d_GameSettings.GameModeSelected != 5) {
            getTeamObj(task, i, 0x7E)->_68 = 1;
            getTeamObj(task, i, 0x87)->_54 |= 2;
            getTeamObj(task, i, 0x87)->_5C = 0;
            getTeamObj(task, i, 0x87)->_68 = 0;
        } else {
            getTeamObj(task, i, 0x7E)->_54 &= ~2;
            getTeamObj(task, i, 0x87)->_54 &= ~2;
        }
        getTeamObj(task, i, 0x75)->_54 &= ~2;
    }
}

// .text:0x8005AF68 size:0x330
void fn_8005AF68(SpaniTask* task) {
    s32 slot;
    s32 i;
    s8 team = lbl_803297E0._CF3B;
    u8 flag;

    for (i = 0; i < 9; i++) {
        if (lbl_803297E0._CFA2[team] != 2) {
            slot = lbl_80354720[team][i]._2;
            fn_800363D8(task, slot + 0x23, 1, 0x83, inMemRoster[team][i].stats.CharID);
            getTeamObj(task, i, 0x11)->_54 &= ~2;
            if (g_d_GameSettings.GameModeSelected == 5) {
                flag = starMissionCompletionTracker._43D6[inMemRoster[team][i].stats.CharID];
            } else {
                flag = lbl_8034E9A0._489B[team][i];
            }
            if (flag != 0 && (team != 1 || g_d_GameSettings.GameModeSelected != 5)) {
                getTeamObj(task, slot, 0x3E)->_68 = 1;
                getTeamObj(task, slot, 0x47)->_54 |= 2;
                getTeamObj(task, slot, 0x47)->_5C = 0;
                getTeamObj(task, slot, 0x47)->_68 = 1;
            } else if (lbl_80361B20._00[0][inMemRoster[team][i].stats.CharID] != 0 && g_d_GameSettings.GameModeSelected != 5) {
                getTeamObj(task, slot, 0x3E)->_68 = 1;
                getTeamObj(task, slot, 0x47)->_54 |= 2;
                getTeamObj(task, slot, 0x47)->_5C = 0;
                getTeamObj(task, slot, 0x47)->_68 = 0;
            } else {
                getTeamObj(task, slot, 0x3E)->_54 &= ~2;
                getTeamObj(task, slot, 0x47)->_54 &= ~2;
            }
            getTeamObj(task, i, 0x35)->_54 &= ~2;
            if (g_d_GameSettings._10 == 0 && team != 0) {
                getTeamObj(task, i, 0x1A)->_64 = (u8)(lbl_8034E9A0.ports[0] == 0) + 30;
            } else {
                getTeamObj(task, i, 0x1A)->_64 = lbl_8034E9A0.ports[team] + 30;
            }
        }
    }
}

static inline s32 nextHand(StatTable* stats) {
    s32 hand = stats->BattingStance + stats->FieldingArm * 2;
    hand++;
    if (hand == 4) {
        hand = 0;
    }
    stats->BattingStance = hand % 2;
    stats->FieldingArm = hand / 2;
    return hand;
}

static inline u16 getPadTrig(s32 pad, s32 team) {
    if (g_d_GameSettings._06 != 2) {
        return lbl_8034E9A0._472C[pad]._2;
    }
    return lbl_803297E0._00[team]._2;
}

// .text:0x8005A350 size:0xC18
void fn_8005A350(SpaniTask* task, s32 team) {
    s32 pad = team;
    s32 cur;
    s32 hand;
    s8 slot;
    s32 done;
    s32 i;

    if (g_d_GameSettings._10 == 0) {
        if (team != 0) {
            return;
        }
        if (lbl_803297E0._CF40[3] != 0) {
            team = 1;
        } else {
            team = 0;
        }
    }
    switch (getPadTrig(pad, team)) {
    case 0x400:
        if (lbl_803297E0._CF52[team] == 0 && g_d_GameSettings._06 != 2) {
            if (lbl_803297E0._CF46[team] != 0) {
                cur = lbl_803297E0._CF46[team] - 1;
                hand = nextHand(&inMemRoster[team][cur].stats);
                lbl_80371C30[task->_14 + 0xAC + cur + team * 9].obj->_5C = hand << 16;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
            lbl_803297E0._CF58[team] = 0;
        }
        break;
    }
    if (lbl_803297E0._CF9E[team] != 0) {
        if (g_d_GameSettings._06 != 2) {
            if (lbl_803297E0._CF46[team] != 0) {
                transferStatsToInMemRoster(team);
                sndFXRelated(0x40);
            } else {
                sndFXStartEx(0x1BA, lbl_800EFBA4[3], 0x3F, 0);
            }
            if (lbl_803297E0._CF46[team] != 0 && g_d_GameSettings.GameModeSelected != 5) {
                cur = lbl_803297E0._CF46[team] - 1;
                slot = lbl_80354720[team][cur]._2;
                if (lbl_8034E9A0._489B[team][cur] != 0) {
                    lbl_80371C30[task->_14 + 0x76 + cur + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x76 + cur + team * 9].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x88 + cur + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x88 + cur + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x88 + cur + team * 9].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x140 + slot + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x140 + slot + team * 9].obj->_68 = 1;
                    lbl_80371C30[task->_14 + 0x152 + slot + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x152 + slot + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x152 + slot + team * 9].obj->_68 = 1;
                } else {
                    lbl_80371C30[task->_14 + 0x88 + cur + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x88 + cur + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x88 + cur + team * 9].obj->_68 = 0;
                    lbl_80371C30[task->_14 + 0x152 + slot + team * 9].obj->_54 |= 2;
                    lbl_80371C30[task->_14 + 0x152 + slot + team * 9].obj->_5C = 0;
                    lbl_80371C30[task->_14 + 0x152 + slot + team * 9].obj->_68 = 0;
                }
            }
        }
        lbl_803297E0._CF9E[team] = 0;
    }
    if (lbl_803297E0._CF65[team] != 0) {
        if (g_d_GameSettings._06 != 2) {
            if (lbl_803297E0._CF61[team] != 0) {
                switch (lbl_803297E0._CF67[team]) {
                case 0:
                    fn_80058E0C(task, team);
                    break;
                case 1:
                    fn_80058B20(task, team);
                    break;
                }
            } else {
                if (lbl_803297E0._CF67[team] == 0) {
                    if ((getTeamObj(task, team, 0x19A)->_5C >> 16) > 5) {
                        getTeamObj(task, team, 0x19A)->_5C = 5 << 16;
                    }
                    getTeamObj(task, team, 0x19A)->_68 = 4;
                    getTeamObj(task, team, 0x19C)->_68 = 4;
                    getTeamObj(task, team, 0x1AC)->_68 = 4;
                    done = isAnimDone(task, team + 0x19A, 0);
                    done += isAnimDone(task, team + 0x19C, 0);
                    done += isAnimDone(task, team + 0x1AC, 0);
                    if (done == 3) {
                        lbl_803297E0._CF65[team] = 0;
                    }
                } else {
                    if ((getTeamObj(task, team, 0x19A)->_5C >> 16) > 5) {
                        getTeamObj(task, team, 0x19A)->_5C = 5 << 16;
                    }
                    getTeamObj(task, team, 0x19A)->_68 = 4;
                    getTeamObj(task, team, 0x1C8)->_68 = 4;
                    if (isAnimDone(task, team + 0x1C8, 0) == 1) {
                        lbl_803297E0._CF65[team] = 0;
                    }
                }
                lbl_803297E0._CF63[team] = 0;
            }
        } else {
            helperW(task, team);
        }
    }
    if (lbl_803297E0._CF71[0] != 0) {
        if (lbl_803297E0._CF71[1] != 0) {
            switch (lbl_803297E0._CF74) {
            case 1:
                starMissionRelated1(task);
                break;
            case 2:
                fn_800596D4(task);
                break;
            case 3:
                if (lbl_803297E0._CF73 == 0) {
                    getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16E : 0x1D7)->_68 = 4;
                    getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16A : 0x1D3)->_68 = 4;
                    getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16C : 0x1D5)->_68 = 4;
                    lbl_803297E0._CF73 = 1;
                }
                helperX(task);
                break;
            }
        } else {
            done = isAnimDone(task, g_d_GameSettings._06 == 2 ? 0x16A : 0x1D3, 0);
            done += isAnimDone(task, g_d_GameSettings._06 == 2 ? 0x16C : 0x1D5, 0);
            if (done == 2) {
                lbl_803297E0._CF73 = 0;
                lbl_803297E0._CF71[0] = 0;
            }
        }
    }
}

// .text:0x80059B38 size:0x818
void starMissionRelated1(SpaniTask* task) {
    s32 i;
    u8 set;
    u8 level;
    s32 variant;
    s32 shown;
    s32 count;
    s32 text;

    if (lbl_803297E0._CF73 == 0) {
        lbl_803297E0._CF9C = lbl_800E8558[lbl_803297E0._CF78]._0[1];
        variant = starMissionCompletionTracker.characters[lbl_803297E0._CF9C].variantClassification;
        set = lbl_800E8558[lbl_803297E0._CF78].set;
        level = lbl_8034E9A0.chars[lbl_803297E0._CF78 / 9][lbl_803297E0._CF78 % 9]._31;
        switch (variant) {
        case 0:
            variant = 3;
            count = 10;
            break;
        case 1:
            variant = 2;
            count = 8;
            break;
        case 2:
            variant = 1;
            count = 6;
            break;
        case 3:
            variant = 0;
            count = 4;
            break;
        }
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16E : 0x1D7)->_54 |= 2;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16E : 0x1D7)->_68 = 1;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16A : 0x1D3)->_54 |= 2;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16A : 0x1D3)->_68 = 1;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16B : 0x1D4)->_54 |= 2;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16B : 0x1D4)->_5C = variant << 16;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16C : 0x1D5)->_54 |= 2;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16C : 0x1D5)->_68 = 1;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x16D : 0x1D6)->_68 = 1;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x171 : 0x1DA)->_5C = level << 16;
        getSpaniObj(task, g_d_GameSettings._06 == 2 ? 0x172 : 0x1DB)->_5C = lbl_803297E0._CF78 << 16;
        lbl_803297E0.texts[0] = fn_8000F988((struct TextModelSet*)task, g_d_GameSettings._06 == 2 ? 0x19B : 0x205, 0, 0, lbl_803297E0._CF9C + 8, 0);
        lbl_803297E0.texts[1] = fn_8000F988((struct TextModelSet*)task, g_d_GameSettings._06 == 2 ? 0x19C : 0x206, 1, 0, lbl_8010B3E8[set] + determineIfMissionDescriptionIsShown(lbl_803297E0._CF9C), 0);
        shown = determineIfMissionDescriptionIsShown(lbl_803297E0._CF9C);
        getSpaniObj(task, 0x1DC)->_5C = (4 - shown) << 16;
        if (*(s8*)&starMissionCompletionTracker.characters[lbl_803297E0._CF9C].inGameMissionTracker[lbl_803297E0._CF75].shownOnPauseMenu != 0) {
            text = lbl_8010A768[set][lbl_803297E0._CF75]._0;
        } else if (lbl_8010A768[set][lbl_803297E0._CF75]._6 <= starMissionCompletionTracker._4415) {
            text = 0x1C5;
        } else {
            text = 0x1C6;
        }
        lbl_803297E0.texts[2] = fn_8000F988((struct TextModelSet*)task, g_d_GameSettings._06 == 2 ? 0x19D : 0x207, 0, 0, text, 0);
        lbl_80366B18[lbl_803297E0.texts[2]]._2F = 1;
        for (i = 0; i < count; i++) {
            if (challengeStarRelatedInd(lbl_803297E0._CF9C, i)) {
                getTeamObj(task, i, 0x1F1)->_54 |= 2;
                getTeamObj(task, i, 0x1F1)->_68 = 1;
            } else {
                getTeamObj(task, i, 0x1F1)->_54 &= ~2;
            }
            getTeamObj(task, i, 0x1FB)->_54 &= ~2;
            getTeamObj(task, i, 0x1E7)->_54 &= ~2;
            getTeamObj(task, i, g_d_GameSettings._06 == 2 ? 0x173 : 0x1DD)->_5C = 0;
        }
        if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF75)) {
            getSpaniObj(task, 0x1D9)->_54 |= 2;
            getSpaniObj(task, 0x1D9)->_68 = 1;
            lbl_80371C30[task->_14 + 0x1E7 + lbl_803297E0._CF75].obj->_54 |= 2;
            lbl_80371C30[task->_14 + 0x1E7 + lbl_803297E0._CF75].obj->_68 = 1;
            getTeamObj(task, lbl_803297E0._CF75, g_d_GameSettings._06 == 2 ? 0x173 : 0x1DD)->_5C = 0x10000;
        } else {
            getSpaniObj(task, 0x1D9)->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x1E7 + lbl_803297E0._CF75].obj->_54 &= ~2;
            getTeamObj(task, lbl_803297E0._CF75, g_d_GameSettings._06 == 2 ? 0x173 : 0x1DD)->_5C = 0;
        }
        lbl_80371C30[task->_14 + 0x1FB + lbl_803297E0._CF75].obj->_54 |= 2;
        lbl_80371C30[task->_14 + 0x1FB + lbl_803297E0._CF75].obj->_68 = 1;
        lbl_803297E0._CF73 = 1;
    }
    if (lbl_803297E0._CF73 != 0) {
        lbl_803297E0._CF74 = 0;
        lbl_803297E0._CF73 = 0;
    }
}

// .text:0x800596D4 size:0x464
void fn_800596D4(SpaniTask* task) {
    u8 set;
    s32 text;

    if (lbl_803297E0._CF73 == 0) {
        if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF75)) {
            getSpaniObj(task, 0x1D9)->_54 |= 2;
            getSpaniObj(task, 0x1D9)->_5C = 0;
            getSpaniObj(task, 0x1D9)->_68 = 1;
            lbl_80371C30[task->_14 + 0x1E7 + lbl_803297E0._CF75].obj->_54 |= 2;
            lbl_80371C30[task->_14 + 0x1E7 + lbl_803297E0._CF75].obj->_5C = 0;
            lbl_80371C30[task->_14 + 0x1E7 + lbl_803297E0._CF75].obj->_68 = 1;
            getTeamObj(task, lbl_803297E0._CF75, g_d_GameSettings._06 == 2 ? 0x173 : 0x1DD)->_5C = 0x10000;
        } else {
            getSpaniObj(task, 0x1D9)->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x1E7 + lbl_803297E0._CF75].obj->_54 &= ~2;
            getTeamObj(task, lbl_803297E0._CF75, g_d_GameSettings._06 == 2 ? 0x173 : 0x1DD)->_5C = 0;
        }
        lbl_80371C30[task->_14 + 0x1FB + lbl_803297E0._CF75].obj->_54 |= 2;
        lbl_80371C30[task->_14 + 0x1FB + lbl_803297E0._CF75].obj->_68 = 1;
        if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF76)) {
            lbl_80371C30[task->_14 + 0x1E7 + lbl_803297E0._CF76].obj->_54 &= ~2;
            getTeamObj(task, lbl_803297E0._CF76, g_d_GameSettings._06 == 2 ? 0x173 : 0x1DD)->_5C = 0;
        } else {
            getTeamObj(task, lbl_803297E0._CF76, g_d_GameSettings._06 == 2 ? 0x173 : 0x1DD)->_5C = 0;
        }
        lbl_80371C30[task->_14 + 0x1FB + lbl_803297E0._CF76].obj->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x1FB + lbl_803297E0._CF76].obj->_68 = 1;
        set = lbl_800E8558[lbl_803297E0._CF9C].set;
        if (*(s8*)&starMissionCompletionTracker.characters[lbl_803297E0._CF9C].inGameMissionTracker[lbl_803297E0._CF75].shownOnPauseMenu != 0) {
            text = lbl_8010A768[set][lbl_803297E0._CF75]._0;
        } else if (lbl_8010A768[set][lbl_803297E0._CF75]._6 <= starMissionCompletionTracker._4415) {
            text = 0x1C5;
        } else {
            text = 0x1C6;
        }
        fn_8000FE08(lbl_803297E0.texts[2], 0, text);
        lbl_803297E0._CF73 = 1;
    }
    if (lbl_803297E0._CF73 != 0) {
        lbl_803297E0._CF74 = 0;
        lbl_803297E0._CF73 = 0;
    }
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
void fn_80058E0C(SpaniTask* task, u8 team) {
    u8 pushPull;
    u8 highLow;
    s16 charID;
    s32 kind;
    s32 fielding;
    CharacterStats* player;
    u8 stance;
    s32 frame;

    if (lbl_803297E0._CF63[team] == 0) {
        player = &inMemRoster[team][lbl_803297E0._CF46[team] - 1];
        charID = player->stats.CharID;
        fielding = player->stats.FieldingStats;
        pushPull = player->stats.HitTrajectoryPushPull;
        frame = charID << 16;
        highLow = player->stats.HitTrajectoryHighLow;
        stance = player->stats.BattingStance;
        getTeamObj(task, team, 0x19A)->_68 = 1;
        getTeamObj(task, team, 0x1B0)->_5C = frame;
        kind = fn_80064918(charID);
        getTeamObj(task, team, 0x1B2)->_5C = kind << 16;
        getTeamObj(task, team, 0x1AC)->_5C = 0;
        getTeamObj(task, team, 0x1C4)->_5C = frame;
        fn_80059458(task, team, fielding);
        getTeamObj(task, team, 0x1B8)->_5C = 0;
        getTeamObj(task, team, 0x1BA)->_5C = 1 << 16;
        getTeamObj(task, team, 0x1BC)->_5C = 2 << 16;
        getTeamObj(task, team, 0x1BE)->_5C = 3 << 16;
        getTeamObj(task, team, 0x1C0)->_5C = 4 << 16;
        getTeamObj(task, team, 0x1C2)->_5C = 5 << 16;
        getTeamObj(task, team, 0x1A0)->_5C = 0;
        getTeamObj(task, team, 0x1A2)->_5C = 0;
        getTeamObj(task, team, 0x1A4)->_5C = 0;
        getTeamObj(task, team, 0x1A6)->_5C = 0;
        getTeamObj(task, team, 0x1A8)->_5C = 0;
        getTeamObj(task, team, 0x1AA)->_5C = 0;
        switch (pushPull) {
        case 0:
            getTeamObj(task, team, 0x1A0)->_68 = 1;
            getTeamObj(task, team, 0x1A2)->_68 = 0;
            getTeamObj(task, team, 0x1A4)->_68 = 0;
            break;
        case 1:
            if (stance == 0) {
                getTeamObj(task, team, 0x1A0)->_68 = 0;
                getTeamObj(task, team, 0x1A2)->_68 = 1;
                getTeamObj(task, team, 0x1A4)->_68 = 0;
            } else {
                getTeamObj(task, team, 0x1A0)->_68 = 0;
                getTeamObj(task, team, 0x1A2)->_68 = 0;
                getTeamObj(task, team, 0x1A4)->_68 = 1;
            }
            break;
        case 2:
            if (stance == 0) {
                getTeamObj(task, team, 0x1A0)->_68 = 0;
                getTeamObj(task, team, 0x1A2)->_68 = 0;
                getTeamObj(task, team, 0x1A4)->_68 = 1;
            } else {
                getTeamObj(task, team, 0x1A0)->_68 = 0;
                getTeamObj(task, team, 0x1A2)->_68 = 1;
                getTeamObj(task, team, 0x1A4)->_68 = 0;
            }
            break;
        }
        switch (highLow) {
        case 0:
            getTeamObj(task, team, 0x1A6)->_68 = 1;
            getTeamObj(task, team, 0x1A8)->_68 = 0;
            getTeamObj(task, team, 0x1AA)->_68 = 0;
            break;
        case 1:
            getTeamObj(task, team, 0x1A6)->_68 = 0;
            getTeamObj(task, team, 0x1A8)->_68 = 1;
            getTeamObj(task, team, 0x1AA)->_68 = 0;
            break;
        case 2:
            getTeamObj(task, team, 0x1A6)->_68 = 0;
            getTeamObj(task, team, 0x1A8)->_68 = 0;
            getTeamObj(task, team, 0x1AA)->_68 = 1;
            break;
        }
        getTeamObj(task, team, 0x1C6)->_54 |= 2;
        getTeamObj(task, team, 0x1C6)->_68 = 1;
        getTeamObj(task, team, 0x19C)->_68 = 1;
        getTeamObj(task, team, 0x1AC)->_5C = 0;
        getTeamObj(task, team, 0x1AC)->_68 = 1;
        getTeamObj(task, team, 0x1D0)->_54 &= ~2;
        getTeamObj(task, team, 0x1D0)->_68 = 0;
        getTeamObj(task, team, 0x1C8)->_68 = 4;
        lbl_803297E0._CF63[team] = 1;
    }
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
// 99.29%: the batter's roster address adds its row and column offsets in the
// other order (registers only).
void fn_80058644(SpaniTask* task) {
    CharacterStats* player;
    s16 charID;
    s32 fielding;
    u8 pushPull;
    u8 highLow;
    u8 stance;
    s32 frame;

    if (lbl_803297E0._CF63[lbl_803297E0._CF3B] == 0) {
        player = &inMemRoster[lbl_803297E0._CF3B][lbl_803297E0._CF46[lbl_803297E0._CF3B] - 1];
        charID = player->stats.CharID;
        fielding = player->stats.FieldingStats;
        pushPull = player->stats.HitTrajectoryPushPull;
        frame = charID << 16;
        highLow = player->stats.HitTrajectoryHighLow;
        stance = player->stats.BattingStance;
        lbl_80371C30[task->_14 + 0x123].obj->_5C = frame;
        lbl_80371C30[task->_14 + 0x124].obj->_5C = fn_80064918(charID) << 16;
        lbl_80371C30[task->_14 + 0x12D].obj->_5C = frame;
        fn_80059458(task, lbl_803297E0._CF3B, fielding);
        lbl_80371C30[task->_14 + 0x127].obj->_5C = 0;
        lbl_80371C30[task->_14 + 0x128].obj->_5C = 1 << 16;
        lbl_80371C30[task->_14 + 0x129].obj->_5C = 2 << 16;
        lbl_80371C30[task->_14 + 0x12A].obj->_5C = 3 << 16;
        lbl_80371C30[task->_14 + 0x12B].obj->_5C = 4 << 16;
        lbl_80371C30[task->_14 + 0x12C].obj->_5C = 5 << 16;
        lbl_80371C30[task->_14 + 0x11B].obj->_5C = 0;
        lbl_80371C30[task->_14 + 0x11C].obj->_5C = 0;
        lbl_80371C30[task->_14 + 0x11D].obj->_5C = 0;
        lbl_80371C30[task->_14 + 0x11E].obj->_5C = 0;
        lbl_80371C30[task->_14 + 0x11F].obj->_5C = 0;
        lbl_80371C30[task->_14 + 0x120].obj->_5C = 0;
        switch (pushPull) {
        case 0:
            lbl_80371C30[task->_14 + 0x11B].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0x11C].obj->_68 = 0;
            lbl_80371C30[task->_14 + 0x11D].obj->_68 = 0;
            break;
        case 1:
            if (stance == 0) {
                lbl_80371C30[task->_14 + 0x11B].obj->_68 = 0;
                lbl_80371C30[task->_14 + 0x11C].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x11D].obj->_68 = 0;
            } else {
                lbl_80371C30[task->_14 + 0x11B].obj->_68 = 0;
                lbl_80371C30[task->_14 + 0x11C].obj->_68 = 0;
                lbl_80371C30[task->_14 + 0x11D].obj->_68 = 1;
            }
            break;
        case 2:
            if (stance == 0) {
                lbl_80371C30[task->_14 + 0x11B].obj->_68 = 0;
                lbl_80371C30[task->_14 + 0x11C].obj->_68 = 0;
                lbl_80371C30[task->_14 + 0x11D].obj->_68 = 1;
            } else {
                lbl_80371C30[task->_14 + 0x11B].obj->_68 = 0;
                lbl_80371C30[task->_14 + 0x11C].obj->_68 = 1;
                lbl_80371C30[task->_14 + 0x11D].obj->_68 = 0;
            }
            break;
        }
        switch (highLow) {
        case 0:
            lbl_80371C30[task->_14 + 0x11E].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0x11F].obj->_68 = 0;
            lbl_80371C30[task->_14 + 0x120].obj->_68 = 0;
            break;
        case 1:
            lbl_80371C30[task->_14 + 0x11E].obj->_68 = 0;
            lbl_80371C30[task->_14 + 0x11F].obj->_68 = 1;
            lbl_80371C30[task->_14 + 0x120].obj->_68 = 0;
            break;
        case 2:
            lbl_80371C30[task->_14 + 0x11E].obj->_68 = 0;
            lbl_80371C30[task->_14 + 0x11F].obj->_68 = 0;
            lbl_80371C30[task->_14 + 0x120].obj->_68 = 1;
            break;
        }
        lbl_80371C30[task->_14 + 0x12E].obj->_54 |= 2;
        lbl_80371C30[task->_14 + 0x12E].obj->_68 = 1;
        lbl_80371C30[task->_14 + 0x119].obj->_68 = 1;
        lbl_80371C30[task->_14 + 0x121].obj->_5C = 0;
        lbl_80371C30[task->_14 + 0x121].obj->_68 = 1;
        lbl_80371C30[task->_14 + 0x133].obj->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x133].obj->_68 = 0;
        lbl_80371C30[task->_14 + 0x12F].obj->_68 = 4;
        lbl_803297E0._CF63[lbl_803297E0._CF3B] = 1;
    }
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
    SpaniTask* task;
    s32 i;
    s32 j;

    fn_80034E20(task = lbl_803CC1B8, lbl_80107688);
    for (i = 0; i < 9; i++) {
        lbl_803297E0._CF80[i] = *((s8*)starMissionCompletionTracker.characters[inMemRoster[1][i].stats.CharID].scoutFlagPointer + starMissionCompletionTracker._4415 * 6 + starMissionCompletionTracker._441C + 4);
        lbl_803297E0._CF89[i] = starMissionCompletionTracker.characters[inMemRoster[1][i].stats.CharID].scoutFlagsAchieved;
        for (j = 0; j < 5; j++) {
            if (j < lbl_803297E0._CF80[i] && lbl_803297E0._CF80[i] - lbl_803297E0._CF89[i] > j) {
                getGridObj(task, j, i * 5, 0x20)->_5C = 0;
            } else if (j >= lbl_803297E0._CF80[i]) {
                getGridObj(task, j, i * 5, 0x20)->_54 &= ~2;
            }
        }
        getTeamObj(task, i, 5)->_5C = i << 16;
        fn_800363D8(task, i + 0xE, 1, 0x83, inMemRoster[1][i].stats.CharID);
    }
    getSpaniObj(task, 4)->_5C = 5 << 16;
    if ((s32)starMissionCompletionTracker._441F[0] == 19) {
        if (g_d_GameSettings.home_AwaySetting ^ 1) {
            getSpaniObj(task, 2)->_54 |= 2;
            getSpaniObj(task, 2)->_5C = (lbl_8034E9A0._470D[1] % 4) << 16;
        } else {
            getSpaniObj(task, 3)->_54 |= 2;
            getSpaniObj(task, 3)->_5C = (lbl_8034E9A0._470D[1] % 4) << 16;
        }
    } else if (g_d_GameSettings.home_AwaySetting) {
        getSpaniObj(task, 2)->_54 |= 2;
        getSpaniObj(task, 2)->_5C = (lbl_8034E9A0._470D[1] % 4) << 16;
    } else {
        getSpaniObj(task, 3)->_54 |= 2;
        getSpaniObj(task, 3)->_5C = (lbl_8034E9A0._470D[1] % 4) << 16;
    }
    lbl_803CC1B8->func = fn_80057CAC;
}

// .text:0x80057CAC size:0x3A4
// 98.88%: registers only; the case-2 loops' counters and the lbl_803297E0
// pointer get other numbers (the switch on flag gave the copies of 0).
void fn_80057CAC(void) {
    SpaniTask* task = lbl_803CC1B8;
    u8 flag;
    s32 i;
    s32 j;

    flag = lbl_803297E0._CF7D;
    switch (flag) {
    case 1:
        if (lbl_803297E0._CF7E == 0) {
            getSpaniObj(task, 0)->_68 = 1;
            getSpaniObj(task, 1)->_68 = 1;
            for (i = 0; i < 9; i++) {
                getTeamObj(task, i, 0x17)->_68 = 1;
            }
            lbl_803297E0._CF7E = 1;
        }
        if (lbl_803297E0._CF7E != 0 && isAnimAt(task, 0, 10) == TRUE) {
            lbl_803297E0._CF7E = 0;
            lbl_803297E0._CF7D = 2;
        }
        break;
    case 2:
        flag = FALSE;
        if (lbl_803297E0._CF7E == 0) {
            for (i = 0; i < 9; i++) {
                for (j = 0; j < lbl_803297E0._CF89[i]; j++) {
                    flag = TRUE;
                    getGridObj(task, j, i * 5, 0x20)->_68 = 1;
                }
            }
            if (flag) {
                sndFXStartEx(0x1B1, 0x7F, 0x3F, 0);
            }
            lbl_803297E0._CF7E = 1;
        }
        if (lbl_803297E0._CF7E != 0) {
            lbl_803297E0._CF7E = 0;
            lbl_803297E0._CF7D = 0;
        }
        break;
    case 3:
        if (lbl_803297E0._CF7E == 0) {
            getSpaniObj(task, 0)->_68 = 4;
            lbl_803297E0._CF7E = 1;
        }
        if (lbl_803297E0._CF7E != 0 && isAnimDone(task, 0, 0) == TRUE) {
            lbl_803297E0._CF7F = 1;
            lbl_803297E0._CF7E = 0;
            lbl_803297E0._CF7D = 0;
        }
        break;
    }
    if (lbl_803297E0._CF7F != 0) {
        lbl_803297E0._CF7F = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
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
// 99.83%: registers only in case 2's text loop; the target keeps i in r29 and
// the lbl_803297E0 pointer in r28, the base the other way round.
void challengeCheckStarsMenuLoading(void) {
    SpaniTask* task = lbl_803CC1B8;
    s32 i;

    switch (lbl_803297E0._CF92) {
    case 1:
        if (lbl_803297E0._CF93 == 0) {
            getSpaniObj(task, 1)->_68 = 1;
            getSpaniObj(task, 0x1E)->_68 = 1;
            getSpaniObj(task, 3)->_68 = 1;
            challengeDrawStarsOnMissionMenu();
            drawStarProgressionMenu(task);
            if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF98)) {
                getSpaniObj(task, 0x23)->_54 |= 2;
                getSpaniObj(task, 0x23)->_5C = 0;
                getSpaniObj(task, 0x23)->_68 = 1;
                getSpaniObj(task, 0x45)->_5C = 1 << 16;
            }
            lbl_803297E0._CF93 = 1;
        }
        if (lbl_803297E0._CF93 != 0 && isAnimDone(task, 1, 10) == TRUE) {
            lbl_803297E0._CF93 = 0;
            lbl_803297E0._CF92 = 0;
        }
        break;
    case 2:
        if (lbl_803297E0._CF93 == 0) {
            getSpaniObj(task, 1)->_68 = 4;
            getSpaniObj(task, 0x1E)->_68 = 4;
            lbl_803297E0._CF93 = 1;
        }
        if (lbl_803297E0._CF93 != 0) {
            i = isAnimDone(task, 1, 0);
            i += isAnimDone(task, 0x1E, 0);
            if (i == 2) {
                lbl_803297E0._CF94 = 1;
                lbl_803297E0._CF93 = 0;
                lbl_803297E0._CF92 = 0;
                for (i = 0; i < 3; i++) {
                    fn_8000FEE8(lbl_803297E0.texts[i]);
                }
                fn_8000F8F4((struct TextModelSet*)task);
            }
        }
        break;
    case 3:
        if (lbl_803297E0._CF93 == 0) {
            lbl_80371C30[task->_14 + 3 + lbl_803297E0._CF96].obj->_5C = 0;
            lbl_80371C30[task->_14 + 3 + lbl_803297E0._CF96].obj->_68 = 1;
            lbl_80371C30[task->_14 + 3 + lbl_803297E0._CF95].obj->_5C = 10 << 16;
            lbl_80371C30[task->_14 + 3 + lbl_803297E0._CF95].obj->_68 = 4;
            drawStarProgressionMenu(task);
            if (challengeStarRelatedInd(lbl_803297E0._CF9C, lbl_803297E0._CF98)) {
                getSpaniObj(task, 0x23)->_54 |= 2;
                getSpaniObj(task, 0x23)->_5C = 0;
                getSpaniObj(task, 0x23)->_68 = 1;
                getSpaniObj(task, 0x45)->_5C = 1 << 16;
            } else {
                getSpaniObj(task, 0x23)->_54 &= ~2;
                getSpaniObj(task, 0x45)->_5C = 0;
            }
            lbl_803297E0._CF93 = 1;
        }
        if (lbl_803297E0._CF93 != 0) {
            lbl_803297E0._CF93 = 0;
            lbl_803297E0._CF92 = 0;
        }
        break;
    case 4:
        someChallengeStarFunction2(task);
        break;
    case 6:
        someChallengeStarFunction(task);
        break;
    case 5:
        if (lbl_803297E0._CF93 == 0) {
            getSpaniObj(task, 1)->_68 = 1;
            getSpaniObj(task, 0)->_68 = 1;
            getSpaniObj(task, 0x45)->_54 |= 2;
            getSpaniObj(task, 0x45)->_68 = 1;
            lbl_803297E0._CF93 = 1;
        }
        if (lbl_803297E0._CF93 != 0 && isAnimDone(task, 1, 20) == TRUE) {
            lbl_803297E0._CF93 = 0;
            lbl_803297E0._CF92 = 0;
        }
        break;
    }
    if (lbl_803297E0._CF94 != 0) {
        lbl_803297E0._CF94 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
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
        fn_8000FE08(lbl_803297E0.texts[2], 0, text);
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
        fn_8000FE08(lbl_803297E0.texts[2], 0, text);
        lbl_803297E0._CF93 = 1;
    }
    if (lbl_803297E0._CF93 && isAnimDone(task, 1, 10) == TRUE) {
        lbl_803297E0._CF93 = 0;
        lbl_803297E0._CF92 = 0;
    }
}

// .text:0x80056AE4 size:0x48C
void drawStarProgressionMenu(SpaniTask* task) {
    s16 charId;
    s16 set;
    s16 variant;
    s32 shown;
    u8 level;
    u16 text;
    s32 i;

    charId = inMemRoster[0][lbl_803297E0._CF96].stats.CharID;
    lbl_803297E0._CF9C = lbl_800E8558[charId]._0[1];
    set = lbl_800E8558[charId].set;
    variant = starMissionCompletionTracker.characters[lbl_803297E0._CF9C].variantClassification;
    level = lbl_8034E9A0.chars[charId / 9][charId % 9]._31;
    switch (variant) {
    case 0:
        variant = 3;
        lbl_803297E0._CF9A = 10;
        break;
    case 1:
        variant = 2;
        lbl_803297E0._CF9A = 8;
        break;
    case 2:
        variant = 1;
        lbl_803297E0._CF9A = 6;
        break;
    case 3:
        variant = 0;
        lbl_803297E0._CF9A = 4;
        break;
    }
    getSpaniObj(task, 0x1F)->_5C = variant << 16;
    getSpaniObj(task, 0x20)->_68 = 1;
    getSpaniObj(task, 0x24)->_5C = level << 16;
    getSpaniObj(task, 0x25)->_5C = charId << 16;
    shown = determineIfMissionDescriptionIsShown(charId);
    getSpaniObj(task, 0x26)->_5C = (4 - shown) << 16;
    if (*(s8*)&starMissionCompletionTracker.characters[lbl_803297E0._CF9C].inGameMissionTracker[0].shownOnPauseMenu != 0) {
        text = lbl_8010A768[set][0]._0;
    } else if (lbl_8010A768[set][0]._6 <= starMissionCompletionTracker._4415) {
        text = 0x1C5;
    } else {
        text = 0x1C6;
    }
    if (lbl_803297E0._CF92 == 1) {
        lbl_803297E0.texts[0] = fn_8000F988((struct TextModelSet*)task, 0x4F, 0, 0, charId + 8, 0);
        lbl_803297E0.texts[1] = fn_8000F988((struct TextModelSet*)task, 0x50, 1, 0, lbl_8010B3E8[lbl_800E8558[charId].set] + challengeRelated(lbl_803297E0._CF9C), 0);
        lbl_803297E0.texts[2] = fn_8000F988((struct TextModelSet*)task, 0x51, 0, 0, text, 0);
        lbl_80366B18[lbl_803297E0.texts[2]]._2F = 1;
    } else {
        fn_8000FE08(lbl_803297E0.texts[0], 0, charId + 8);
        fn_8000FE08(lbl_803297E0.texts[1], 0, lbl_8010B3E8[lbl_800E8558[charId].set] + challengeRelated(lbl_803297E0._CF9C));
        fn_8000FE08(lbl_803297E0.texts[2], 0, text);
    }
    for (i = 0; i < lbl_803297E0._CF9A; i++) {
        if (challengeStarRelatedInd(lbl_803297E0._CF9C, i)) {
            lbl_80371C30[task->_14 + 0x3B + i].obj->_54 |= 2;
            lbl_80371C30[task->_14 + 0x3B + i].obj->_68 = 1;
        } else {
            lbl_80371C30[task->_14 + 0x3B + i].obj->_54 &= ~2;
        }
        lbl_80371C30[task->_14 + 0x45 + i].obj->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x31 + i].obj->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x45 + i].obj->_5C = 0;
    }
}
