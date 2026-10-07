#include "game/rep_3DA8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"

typedef struct ScoutFlagTable {
    /* 0x0 */ u8 _0[4];
    /* 0x4 */ s8 _4[1][6];
} ScoutFlagTable;

typedef struct {
    /* 0x0 */ s8 _0;
    /* 0x1 */ s8 _1;
} UnkBss37400Pair; // size: 0x2

typedef struct {
    /* 0x0 */ s8 _0;
    /* 0x1 */ s8 _1;
    /* 0x2 */ s8 _2;
    /* 0x3 */ s8 _3;
    /* 0x4 */ s8 _4;
} UnkBss37400Entry; // size: 0x5

typedef struct {
    /* 0x00 */ UnkBss37400Pair _00[9];
    /* 0x12 */ UnkBss37400Entry _12[9];
    /* 0x3F */ u8 _3F;
    /* 0x40 */ s16 _40;
    /* 0x42 */ u8 _42[0x46 - 0x42];
    /* 0x46 */ u8 _46;
    /* 0x47 */ u8 _47;
    /* 0x48 */ u8 _48;
    /* 0x49 */ s8 _49;
} UnkBss37400;

extern UnkBss37400 lbl_3_common_bss_37400;

// .text:0x00164554 size:0x110 mapped:0x807A35E8
void fn_3_164554(void) {
    StarMissionCompletionTracker* tracker = &starMissionCompletionTracker;
    UnkBss37400* bss = &lbl_3_common_bss_37400;
    u8 mission = tracker->_441C;
    u8 level = tracker->_4415;
    s16 ids[9];
    s32 i;
    ChallengeTrackingStruct* c;

    for (i = 0; i < 9; i++) {
        ids[i] = inMemRoster[1][i].stats.CharID;
    }
    for (i = 0; i < 9; i++) {
        if (ids[i] != -1 && bss->_12[i]._3 == 1) {
            c = &tracker->characters[ids[i]];
            if (c->scoutFlagPointer->_4[level][mission] != 0) {
                c->scoutFlagsAchieved += bss->_12[i]._2;
                if (c->scoutFlagsAchieved > c->scoutFlagPointer->_4[level][mission]) {
                    c->scoutFlagsAchieved = c->scoutFlagPointer->_4[level][mission];
                }
            }
        }
    }
}

// .text:0x0016230C size:0xA48 mapped:0x807A13A0
void fn_3_16230C(s32 result, s32 streak) {
    return;
}
