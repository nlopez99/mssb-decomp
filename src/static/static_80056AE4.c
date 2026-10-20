#include "static/static_80056AE4.h"
#include "static/UnknownHomes_Static.h"
#include "game/UnknownHomes_Game.h"
#include "static/spani_default.h"
#include "static/static_80021188.h"
#include "static/static_800531D0.h"

typedef struct SpaniObj {
    /* 0x00 */ u8 _00[0x5C];
    /* 0x5C */ s32 _5C;
} SpaniObj;

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
    /* 0x0CF3C */ u8 _CF3C[0xCF70 - 0xCF3C];
    /* 0x0CF70 */ u8 _CF70;
    /* 0x0CF71 */ u8 _CF71[0xCFA2 - 0xCF71];
    /* 0x0CFA2 */ u8 _CFA2[1];
} lbl_803297E0;

extern struct {
    /* 0x00 */ u8 _00[6][9];
    /* 0x36 */ u8 _36[0xE4 - 0x36];
    /* 0xE4 */ u8 _E4;
} lbl_80361B20;

extern MenuScreen lbl_800FEF70[];
extern SpaniSlot lbl_80371C30[];
extern SpaniTask* lbl_803CC1B8;
extern struct SpaniDesc lbl_80108048[];

extern void fn_8006CF6C(void);

static inline SpaniObj* getSpaniObj(SpaniTask* task, s32 id) {
    return lbl_80371C30[task->_14 + id].obj;
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
void fn_8005FCA0(void) {
}

// .text:0x8005F9D0 size:0x2D0
void fn_8005F9D0(void) {
}

// .text:0x8005F734 size:0x29C
void fn_8005F734(void) {
}

// .text:0x8005F068 size:0x6CC
void fn_8005F068(void) {
}

// .text:0x8005EC88 size:0x3E0
void fn_8005EC88(void) {
}

// .text:0x8005E9D8 size:0x2B0
void fn_8005E9D8(void) {
}

// .text:0x8005DE14 size:0xBC4
void fn_8005DE14(void) {
}

// .text:0x8005CCE4 size:0x1130
void fn_8005CCE4(void) {
}

// .text:0x8005C830 size:0x4B4
void fn_8005C830(void) {
}

// .text:0x8005C5C4 size:0x26C
void fn_8005C5C4(void) {
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
void fn_80059458(void) {
}

// .text:0x80058E0C size:0x64C
void fn_80058E0C(void) {
}

// .text:0x80058B20 size:0x2EC
void fn_80058B20(void) {
}

// .text:0x80058644 size:0x4DC
void fn_80058644(void) {
}

// .text:0x80058394 size:0x2B0
void fn_80058394(void) {
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
        getSpaniObj(task, i + 12)->_5C = i << 16;
        fn_800363D8(task, i + 0x15, 1, 0x83, inMemRoster[0][i].stats.CharID);
    }
    lbl_803CC1B8->func = challengeCheckStarsMenuLoading;
}

// .text:0x800576F0 size:0x518
void challengeCheckStarsMenuLoading(void) {
}

// .text:0x800572C0 size:0x430
void someChallengeStarFunction2(void) {
}

// .text:0x80056F70 size:0x350
void someChallengeStarFunction(void) {
}

// .text:0x80056AE4 size:0x48C
void drawStarProgressionMenu(void) {
}
