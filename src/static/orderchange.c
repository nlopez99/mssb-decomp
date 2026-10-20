#include "static/orderchange.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "Dolphin/os.h"

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

extern struct {
    /* 0x0000 */ u8 _0000[0xCF38];
    /* 0xCF38 */ u16 _CF38;
    /* 0xCF3A */ s8 _CF3A;
    /* 0xCF3B */ u8 _CF3B;
    /* 0xCF3C */ u8 _CF3C[0xCF42 - 0xCF3C];
    /* 0xCF42 */ u8 _CF42;
} lbl_803297E0;

extern struct {
    /* 0x00 */ u8 _00[0x55];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
} lbl_803C66B0;

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
    lbl_803297E0._CF38 = 0;
    lbl_803297E0._CF3A = team;
    lbl_803297E0._CF42 = 0;
    if (g_d_GameSettings._06 != 2) {
        lbl_803297E0._CF3B = 0;
    } else {
        lbl_803297E0._CF3B = player;
    }
}

// .text:0x80047FE4 size:0x6FC
void pauseMenuSelection(void) {
}

// .text:0x80047CE0 size:0x304
void fn_80047CE0(void) {
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
