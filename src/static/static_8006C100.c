#include "static/static_8006C100.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct StatTotals {
    /* 0x00 */ s16 stats[6];
    /* 0x0C */ s16 _0C;
    /* 0x0E */ s16 _0E;
} StatTotals; // size: 0x10

typedef struct UnkQueueState {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} UnkQueueState;

extern UnkQueueState lbl_80366158;

extern f32 lbl_801093E8[6];
extern s16 lbl_80109400[8];
extern s16 lbl_80109410[8];
s16 lbl_803CB8E0[4] = { 999, 600, 200, 0 };
s16 lbl_803CB8E8 = 15;
typedef void (*StatCallback)(void* arg0, void* arg1, void* arg2);

StatCallback lbl_803CBD38;
StatCallback lbl_803CBD3C;

// .text:0x8006C488 size:0x4
void fn_8006C488(void) {
}

// .text:0x8006C444 size:0x44
void fn_8006C444(void* arg0, void* arg1, void* arg2) {
    if (lbl_80366158._28 != 1 && lbl_803CBD3C != NULL) {
        lbl_803CBD3C(arg0, arg1, arg2);
    }
}

// .text:0x8006C43C size:0x8
void fn_8006C43C(StatCallback callback) {
    lbl_803CBD3C = callback;
}

// .text:0x8006C3F8 size:0x44
void fn_8006C3F8(void* arg0, void* arg1, void* arg2) {
    if (lbl_80366158._28 != 1 && lbl_803CBD38 != NULL) {
        lbl_803CBD38(arg0, arg1, arg2);
    }
}

// .text:0x8006C3F0 size:0x8
void fn_8006C3F0(StatCallback callback) {
    lbl_803CBD38 = callback;
}

// .text:0x8006C398 size:0x58
void fn_8006C398(StatBlock* block) {
    u32 i;

    memset(block, 0, sizeof(StatBlock));
    i = 0;
    do {
        block->order[i] = i + 1;
    } while (++i < 6);
    block->_12 = 3;
}

// .text:0x8006C2B4 size:0xE4
void fn_8006C2B4(StatTotals* out, StatBlock* block) {
    u32 i;
    s16 v;
    s16 bonus;

    i = 0;
    do {
        u8 kind = block->order[i];

        v = block->stats[kind - 1];
        if (v > lbl_80109410[kind]) {
            v = lbl_80109410[kind];
        }
        v = v * lbl_801093E8[kind - 1];
        if (v > 999) {
            v = 999;
        }
        out->stats[kind - 1] = v;
    } while (++i < 6);
    bonus = lbl_803CB8E0[block->_12];
    if (bonus > 999) {
        bonus = 999;
    }
    out->_0C = bonus;
    bonus = block->_13 * lbl_803CB8E8;
    if (bonus > 999) {
        bonus = 999;
    }
    out->_0E = bonus;
}

// .text:0x8006C268 size:0x4C
s16 fn_8006C268(StatTotals* totals) {
    s16 total = 0;
    u32 i;

    i = 0;
    do {
        total += totals->stats[i];
    } while (++i < 6);
    total += totals->_0C;
    total += totals->_0E;
    if (total > 9999) {
        total = 9999;
    }
    return total;
}

// .text:0x8006C13C size:0x12C
s16 fn_8006C13C(StatBlock* block) {
    StatTotals totals;

    fn_8006C2B4(&totals, block);
    return fn_8006C268(&totals);
}

// .text:0x8006C100 size:0x3C
u8 fn_8006C100(s16 value) {
    u32 i;

    i = 0;
    do {
        if (value >= lbl_80109400[i]) {
            return i;
        }
    } while (++i < 7);
    return 6;
}
