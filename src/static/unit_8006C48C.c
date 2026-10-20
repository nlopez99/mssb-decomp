#include "static/unit_8006C48C.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct MissionDesc {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ s8 stars[1]; // indexed by [mode * 6 + level]
} MissionDesc;

typedef struct MissionChar {
    /* 0x00 */ MissionDesc* desc;
    /* 0x04 */ s8 _04;
    /* 0x05 */ s8 _05;
    /* 0x06 */ s8 _06;
    /* 0x07 */ u8 _07[0x9 - 0x7];
    /* 0x09 */ struct {
        /* 0x0 */ s8 flag; // negative once the star is earned
        /* 0x1 */ s8 unlocked;
    } stars[10];
    /* 0x1D */ u8 _1D[0x31 - 0x1D];
    /* 0x31 */ s8 status;
    /* 0x32 */ u8 _32[0x34 - 0x32];
} MissionChar; // size: 0x34

typedef struct MissionTracker {
    /* 0x0000 */ MissionChar chars[54];
    /* 0x0AF8 */ u8 _0AF8[0x4415 - 0xAF8];
    /* 0x4415 */ u8 _4415;
    /* 0x4416 */ u8 _4416[0x441C - 0x4416];
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ u8 _441F;
    /* 0x4420 */ u8 _4420[0x4422 - 0x4420];
    /* 0x4422 */ u8 _4422;
    /* 0x4423 */ u8 _4423[0x444D - 0x4423];
    /* 0x444D */ u8 _444D[54];
} MissionTracker;

typedef struct StarReq {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 type;
    /* 0x4 */ s16 count;
    /* 0x6 */ s16 level;
    /* 0x8 */ s16 _8;
} StarReq; // size: 0xA

typedef struct MissionInfo {
    /* 0x0 */ u8 _0[0x2];
    /* 0x2 */ u8 table;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4[0x6 - 0x4];
} MissionInfo; // size: 0x6

typedef struct BigMenuState {
    /* 0x00000 */ u8 _00000[0xCF69];
    /* 0x0CF69 */ u8 _CF69;
    /* 0x0CF6A */ u8 _CF6A;
    /* 0x0CF6B */ u8 _CF6B;
    /* 0x0CF6C */ u8 _CF6C[4];
} BigMenuState;

typedef struct SoundSlot {
    /* 0x00 */ u8 _00[0x2F];
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u8 _30[0x38 - 0x30];
} SoundSlot; // size: 0x38

extern MissionTracker starMissionCompletionTracker;
extern MissionInfo lbl_800E8558[];
extern s16 lbl_8010B444[][11];
extern StarReq lbl_8010A768[][10];
extern f32 lbl_8010B4B4[][11];
extern f32 lbl_8010B590[][7];
extern BigMenuState lbl_803297E0;
extern SoundSlot lbl_80366B18[];
extern u8 lbl_801075A8[];
extern void (**lbl_803CC1B8)(void);

extern s32 challengeStarRelatedInd(s32 mission, s32 star);
extern void fn_8000F8F4(void* task);
extern u8 fn_8000F988(void* task, s32 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void fn_8000FEE8(u8 id);
extern void fn_80034CEC(void* task);
extern void fn_80034E20(void* task, void* desc);
extern void fn_800B0A14_removeQueue(void);

// .text:0x8006CF6C size:0xB8
void fn_8006CF6C(void) {
    void* task = lbl_803CC1B8;
    s32 i;

    lbl_803297E0._CF6B = 0;
    fn_80034E20(task, lbl_801075A8);
    for (i = 0; i < 4; i++) {
        lbl_803297E0._CF6C[i] = fn_8000F988(task, i + 2, 0, 0, i + 0x1C1, 0);
        lbl_80366B18[lbl_803297E0._CF6C[i]]._2F = 1;
    }
    *lbl_803CC1B8 = fn_8006CEBC;
}

// .text:0x8006CEBC size:0xB0
void fn_8006CEBC(void) {
    void* task = lbl_803CC1B8;
    s32 i;

    if (lbl_803297E0._CF6B != 0) {
        lbl_803297E0._CF6B = 0;
        for (i = 0; i < 4; i++) {
            fn_8000FEE8(lbl_803297E0._CF6C[i]);
        }
        fn_8000F8F4(task);
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
    if (lbl_803297E0._CF69 == 0) {
        lbl_803297E0._CF69 = 1;
        lbl_803297E0._CF6A = 1;
    }
}

// .text:0x8006CDC0 size:0xFC
s32 fn_8006CDC0(s32 index) {
    MissionTracker* tr = &starMissionCompletionTracker;
    MissionChar* ch;
    s32 count;
    s32 i;

    if (lbl_800E8558[index]._3 == 0) {
        return 0;
    }
    count = 0;
    ch = &tr->chars[index];
    for (i = 0; i < 10; i++) {
        if (ch->stars[i].flag < 0) {
            count++;
        }
    }
    return count;
}

// .text:0x8006CCA4 size:0x11C
s16 determineIfMissionDescriptionIsShown(s32 index) {
    MissionChar* ch = &starMissionCompletionTracker.chars[index];
    s32 count;
    s32 i;

    if (lbl_800E8558[index]._3 == 0) {
        count = 0;
    } else {
        count = 0;
        for (i = 0; i < 10; i++) {
            if (ch->stars[i].flag < 0) {
                count++;
            }
        }
    }
    return lbl_8010B444[ch->_05][count];
}

static inline s32 countEarnedStars(s32 index) {
    s32 count;
    s32 i;

    if (lbl_800E8558[index]._3 == 0) {
        count = 0;
    } else {
        count = 0;
        for (i = 0; i < 10; i++) {
            if (challengeStarRelatedInd(index, i) != 0) {
                count++;
            }
        }
    }
    return count;
}

// .text:0x8006CBE4 size:0xC0
// The target starts countEarnedStars' i as a copy of count (mr r30,r31) where this builds li r30,0
s16 challengeRelated(s32 index) {
    MissionChar* ch = &starMissionCompletionTracker.chars[index];

    return lbl_8010B444[ch->_05][countEarnedStars(index)];
}

// .text:0x8006CAC8 size:0x11C
f32 starMissionMenu(s32 index) {
    MissionChar* ch = &starMissionCompletionTracker.chars[index];
    s32 count;
    s32 i;

    if (lbl_800E8558[index]._3 == 0) {
        count = 0;
    } else {
        count = 0;
        for (i = 0; i < 10; i++) {
            if (ch->stars[i].flag < 0) {
                count++;
            }
        }
    }
    return lbl_8010B4B4[ch->_05][count];
}

// .text:0x8006CA9C size:0x2C
f32 fn_8006CA9C(void) {
    return lbl_8010B590[starMissionCompletionTracker._4415][starMissionCompletionTracker._4422];
}

// .text:0x8006C9D8 size:0xC4
// Registers only: the target keeps tr in r6, i in r10 and level in r8
void fn_8006C9D8(void) {
    s32 i;
    MissionTracker* tr = &starMissionCompletionTracker;
    MissionChar* ch = tr->chars;
    s32 level = tr->_4415 * 6 + tr->_441C;
    s8 star;

    for (i = 0; i < 54; i++, ch++) {
        if (ch->status != 1) {
            star = ch->desc->stars[level];
            if (ch->_06 == star && star != 0) {
                if ((s32)tr->_441F == 19) {
                    if (ch->status == 2) {
                        ch->status = 1;
                        tr->_444D[i] = 1;
                    }
                } else if (ch->status != 2 && ch->_04 == tr->_441E) {
                    ch->status = 1;
                    tr->_444D[i] = 1;
                }
            }
        }
    }
}

// .text:0x8006C7C4 size:0x214
void starMissionRelated2(void) {
}

// .text:0x8006C79C size:0x28
BOOL fn_8006C79C(s32 index) {
    MissionChar* ch = &starMissionCompletionTracker.chars[index];

    return ch->status == 1;
}

// .text:0x8006C6C4 size:0xD8
s32 fn_8006C6C4(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 54; i++) {
        if (starMissionCompletionTracker.chars[i].status == 1) {
            count++;
        }
    }
    return count;
}

// .text:0x8006C5CC size:0xF8
BOOL fn_8006C5CC(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 54; i++) {
        if (starMissionCompletionTracker.chars[i].status == 1 && starMissionCompletionTracker.chars[i]._04 != 5) {
            count++;
        }
    }
    return count >= 28;
}

// .text:0x8006C48C size:0x140
// Registers only: the saved registers r18-r27 are assigned in another order
void challengeDrawStarsOnMissionMenu(void) {
    s32 k;
    s32 i;
    s32 count;
    s32 type;
    s16 need;
    s16 minLevel;
    u8 level = starMissionCompletionTracker._4415;

    for (i = 0; i < 54; i++) {
        if (lbl_800E8558[i]._3 == 1 && starMissionCompletionTracker.chars[i].status == 1) {
            for (k = 0; k < 10; k++) {
                type = lbl_8010A768[lbl_800E8558[i].table][k].type;
                need = lbl_8010A768[lbl_800E8558[i].table][k].count;
                minLevel = lbl_8010A768[lbl_800E8558[i].table][k].level;
                if (type == 0) {
                    starMissionCompletionTracker.chars[i].stars[k].unlocked = 1;
                }
                if (challengeStarRelatedInd(i, k) != 0) {
                    starMissionCompletionTracker.chars[i].stars[k].unlocked = 1;
                }
                if (type == 1) {
                    count = countEarnedStars(i);
                    if (count >= need && level >= minLevel) {
                        starMissionCompletionTracker.chars[i].stars[k].unlocked = 1;
                    }
                }
            }
        }
    }
}

