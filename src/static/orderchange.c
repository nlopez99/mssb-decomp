#include "static/orderchange.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "Dolphin/os.h"
#include "static/static_8004157C.h"

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

typedef struct ScrollList {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
} ScrollList;

extern Scene* lbl_803CBBCC;
extern SpriteRef lbl_80371C30[];
extern u32 lbl_803CB750;
extern u8 lbl_800EFBA4[16];

typedef struct OrderSlot {
    /* 0x00 */ u8 _00[2];
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
    /* 0x0E */ u8 _0E[4];
    /* 0x12 */ u8 _12[4];
    /* 0x16 */ u8 _16[2];
    /* 0x18 */ u8 _18[2];
    /* 0x1A */ u8 _1A[2];
    /* 0x1C */ u8 _1C[2];
    /* 0x1E */ u8 _1E[2];
    /* 0x20 */ u8 _20[2];
    /* 0x22 */ u8 _22[0x45 - 0x22];
    /* 0x45 */ u8 _45;
    /* 0x46 */ u8 _46[0x5A - 0x46];
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B[0x6A - 0x5B];
    /* 0x6A */ u8 _6A[2];
} PauseMenu;

extern struct {
    /* 0x0000 */ u8 _0000[0xCF38];
    /* 0xCF38 */ PauseMenu pause;
} lbl_803297E0;

extern struct {
    /* 0x00 */ u8 _00[0x55];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[2];
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
} lbl_803C66B0;

extern struct {
    /* 0x0000 */ u8 _0000[0x4705];
    /* 0x4705 */ u8 _4705;
    /* 0x4706 */ u8 _4706[0x4720 - 0x4706];
    /* 0x4720 */ s32 _4720;
    /* 0x4724 */ s32 _4724;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0x36];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
} lbl_803C5EA4;

extern struct {
    /* 0x0000 */ u8 _0000[0x4445];
    /* 0x4445 */ u8 _4445;
} starMissionCompletionTracker;

extern void characterSelectScreen(s32 team);
extern void unsure_FillRosterPositions(s32 team);
extern void SetMenuNumber(void);
extern void fn_800625A4(s32 arg0, s32 arg1);

extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);

// .text:0x80048BEC size:0x28
void fn_80048BEC(ScrollList* list) {
    s32 n = list->_08;
    s32 i;

    if (list->_04 < n) {
        n = list->_04;
    }
    for (i = n; i > 0; i--) {
    }
}

// .text:0x80048820 size:0x3CC
void fn_80048820(void) {
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
    lbl_803297E0.pause.state = 0;
    lbl_803297E0.pause.team = team;
    lbl_803297E0.pause._0A = 0;
    if (g_d_GameSettings._06 != 2) {
        lbl_803297E0.pause.player = 0;
    } else {
        lbl_803297E0.pause.player = player;
    }
}

// .text:0x80047FE4 size:0x6FC
void pauseMenuSelection(void) {
}

// .text:0x80047CE0 size:0x304
void fn_80047CE0(void) {
    s32 i;
    u8 kind;

    lbl_8034E9A0._4720 = 0;
    lbl_8034E9A0._4724 = 0;
    for (i = 0; i < 2; i++) {
        lbl_803297E0.pause._1A[i] = g_d_GameSettings._06 == 2 ? TRUE : FALSE;
    }
    lbl_803297E0.pause._06[0] = lbl_803297E0.pause._06[1] = 0xFF;
    lbl_803297E0.pause._04[0] = lbl_803297E0.pause._04[1] = 0;
    lbl_803297E0.pause._08[1] = lbl_803297E0.pause._08[0] = 0;
    lbl_803297E0.pause._0B = 0;
    lbl_803297E0.pause._0E[0] = lbl_803297E0.pause._0E[1] = lbl_803297E0.pause._0E[2] = lbl_803297E0.pause._0E[3] = 0;
    lbl_803297E0.pause._12[0] = lbl_803297E0.pause._12[1] = lbl_803297E0.pause._12[2] = lbl_803297E0.pause._12[3] = 0;
    lbl_803297E0.pause._1A[0] = lbl_803297E0.pause._1A[1] = lbl_803297E0.pause._1C[0] = lbl_803297E0.pause._1C[1] = 0;
    lbl_803297E0.pause._16[0] = lbl_803297E0.pause._16[1] = 0;
    lbl_803297E0.pause._1E[0] = lbl_803297E0.pause._1E[1] = 0;
    lbl_803297E0.pause._20[0] = lbl_803297E0.pause._20[1] = 0;
    lbl_8034E9A0._4705 = 1;
    lbl_803C66B0._59 = 0;
    lbl_803C66B0._5A = 1;
    if (g_d_GameSettings._06 != 2) {
        if (g_d_GameSettings.GameModeSelected != 5 && lbl_803CBBCC->_06 == 10) {
            characterSelectScreen(0);
            characterSelectScreen(1);
        } else if (g_d_GameSettings.GameModeSelected == 5 && starMissionCompletionTracker._4445 == 0) {
            fn_800415A8();
            unsure_FillRosterPositions(1);
            characterSelectScreen(1);
        }
        lbl_803297E0.pause._6A[1] = 0;
        lbl_803297E0.pause._6A[lbl_803297E0.pause.player] = 0;
        lbl_803C5EA4._36 = 1;
        lbl_803C5EA4._37 = lbl_803C5EA4._38;
        lbl_803C5EA4._38 = 1;
    } else if (lbl_803297E0.pause._6A[lbl_803297E0.pause.player] == 0) {
        lbl_803297E0.pause._1A[0] = lbl_803297E0.pause._1A[1] = 1;
    } else {
        lbl_803297E0.pause._1A[0] = lbl_803297E0.pause._1A[1] = 0;
    }
    SetMenuNumber();
    if (g_d_GameSettings._06 != 2 && lbl_803CBBCC->_06 != 10 && g_d_GameSettings._10 == 0 &&
        g_d_GameSettings.GameModeSelected != 5) {
        lbl_803297E0.pause._0B = 1;
        lbl_803297E0.pause._16[0] = 1;
        fn_800625A4(0, 0x39);
        fn_800625A4(1, 0x39);
        lbl_803297E0.pause.state = 1;
        return;
    }
    kind = lbl_803297E0.pause._6A[lbl_803297E0.pause.player];
    if (kind != 2 && kind != 3) {
        fn_800625A4(0, 0x38);
        if (g_d_GameSettings._06 != 2) {
            fn_800625A4(1, 0x38);
        } else if (g_d_GameSettings._06 == 2) {
            fn_800625A4(1, 0x38);
        }
        lbl_803297E0.pause.state = 1;
    } else if (kind == 2) {
        lbl_803297E0.pause._45 = 1;
        lbl_803297E0.pause.state = 4;
    } else {
        lbl_803297E0.pause._5A = 1;
        lbl_803297E0.pause.state = 5;
    }
}

// .text:0x800471F4 size:0xAEC
void fn_800471F4(void) {
}

// .text:0x8004617C size:0x1078
void fn_8004617C(void) {
}

// .text:0x80044C98 size:0x14E4
void fn_80044C98(void) {
}

// .text:0x80043880 size:0x1418
void fn_80043880(void) {
}

// .text:0x8004338C size:0x4F4
void starMenuCursor(void) {
}

// .text:0x80042DE8 size:0x5A4
void challengeStarMenu(void) {
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
void transferStatsToInMemRoster(s32 arg0) {
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
