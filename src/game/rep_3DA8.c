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

typedef struct {
    /* 0x0 */ u8 _0[9];
    /* 0x9 */ s8 _9;
    /* 0xA */ u8 _A[0xF - 0xA];
} UnkChallengeTeam; // size: 0xF

extern UnkChallengeTeam lbl_80109420[];

typedef struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1; // index into starMissionCompletionTracker.characters
    /* 0x2 */ u8 _2; // index into lbl_80109AE8
    /* 0x3 */ u8 _3[3];
} UnkCharEntry; // size: 0x6

extern UnkCharEntry lbl_800E8558[54];

typedef struct {
    /* 0x0 */ s16 type;
    /* 0x2 */ s16 target;
    /* 0x4 */ u8 _4[6];
} UnkMissionDef; // size: 0xA

extern UnkMissionDef lbl_80109AE8[32][10];

// .text:0x00164664 size:0x410 mapped:0x807A36F8
void fn_3_164664(void) {
    s32 n;
    StarMissionCompletionTracker* tracker = &starMissionCompletionTracker;
    UnkBss37400* bss = &lbl_3_common_bss_37400;
    s32 bonus = lbl_80109420[bss->_46]._9;
    u8 mission = tracker->_441C;
    u8 level = tracker->_4415;
    s16 ids[9];
    s32 i;
    BOOL found;
    ChallengeTrackingStruct* c;

    for (i = 0; i < 9; i++) {
        ids[i] = inMemRoster[1][i].stats.CharID;
    }
    n = 0;
    found = fn_3_163BD4();
    if (bonus > 0 && found) {
        while (bonus > 0) {
            if (ids[n] != -1) {
                c = &tracker->characters[ids[n]];
                if (c->scoutFlagPointer->_4[level][mission] != 0 &&
                    c->scoutFlagsAchieved < c->scoutFlagPointer->_4[level][mission]) {
                    bonus--;
                    c->scoutFlagsAchieved++;
                }
            }
            n = (n + 1) % 9;
            if (!fn_3_163BD4()) {
                break;
            }
        }
    }
}

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

// .text:0x0016440C size:0x148 mapped:0x807A34A0
void fn_3_16440C(void) {
    UnkBss37400* bss = &lbl_3_common_bss_37400;
    StarMissionCompletionTracker* tracker = &starMissionCompletionTracker;
    u8 mission = tracker->_441C;
    u8 level = tracker->_4415;
    InMemBatterType* batter = &g_Batter;
    InMemPitcherType* pitcher = &g_Pitcher;
    s32 bonus = lbl_80109420[bss->_46]._9;
    s16 ids[9];
    s32 i;
    s32 charID;
    ChallengeTrackingStruct* c;

    for (i = 0; i < 9; i++) {
        ids[i] = inMemRoster[1][i].stats.CharID;
    }
    if (bss->_46 == 2) {
        charID = pitcher->charID;
    } else if (bss->_46 == 1) {
        charID = batter->charID;
    }
    for (i = 0; i < 9; i++) {
        if (charID == ids[i]) {
            c = &tracker->characters[ids[i]];
            if (c->scoutFlagPointer->_4[level][mission] != 0) {
                bss->_12[i]._1 = c->scoutFlagPointer->_4[level][mission];
                bss->_12[i]._0 = c->scoutFlagsAchieved;
                bss->_12[i]._2 = bonus;
                bonus = 0;
                bss->_12[i]._3 = 1;
                bss->_12[i]._4 = ids[i];
            }
        }
    }
}

// .text:0x00163D34 size:0x160 mapped:0x807A2DC8
void fn_3_163D34(void) {
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
        if (ids[i] != -1) {
            c = &tracker->characters[ids[i]];
            if (c->scoutFlagPointer->_4[level][mission] != 0) {
                bss->_00[i]._0 = c->scoutFlagsAchieved;
                bss->_00[i]._1 = c->scoutFlagPointer->_4[level][mission];
            }
        }
    }
}

// .text:0x00163BD4 size:0x160 mapped:0x807A2C68
BOOL fn_3_163BD4(void) {
    StarMissionCompletionTracker* tracker = &starMissionCompletionTracker;
    u8 mission = tracker->_441C;
    u8 level = tracker->_4415;
    s16 ids[9];
    s32 i;
    ChallengeTrackingStruct* c;
    BOOL ret;

    for (i = 0; i < 9; i++) {
        ids[i] = inMemRoster[1][i].stats.CharID;
    }
    ret = FALSE;
    for (i = 0; i < 9; i++) {
        if (ids[i] != -1) {
            c = &tracker->characters[ids[i]];
            if (c->scoutFlagPointer->_4[level][mission] != 0 &&
                c->scoutFlagsAchieved < c->scoutFlagPointer->_4[level][mission]) {
                ret = TRUE;
            }
        }
    }
    return ret;
}

// .text:0x00163A7C size:0x158 mapped:0x807A2B10
BOOL fn_3_163A7C(void) {
    StarMissionCompletionTracker* tracker = &starMissionCompletionTracker;
    UnkBss37400* bss = &lbl_3_common_bss_37400;
    u8 mission = tracker->_441C;
    u8 level = tracker->_4415;
    InMemBatterType* batter = &g_Batter;
    InMemPitcherType* pitcher = &g_Pitcher;
    s16 ids[9];
    s32 i;
    s32 charID;
    BOOL ret;

    for (i = 0; i < 9; i++) {
        ids[i] = inMemRoster[1][i].stats.CharID;
    }
    if (bss->_46 == 2) {
        charID = pitcher->charID;
    } else if (bss->_46 == 1) {
        charID = batter->charID;
    }
    for (i = 0; i < 9; i++) {
        if (charID == ids[i] && tracker->characters[ids[i]].scoutFlagPointer->_4[level][mission] != 0) {
            ret = TRUE;
        }
    }
    return ret;
}

// .text:0x00163948 size:0x134 mapped:0x807A29DC
BOOL fn_3_163948(void) {
    UnkBss37400* bss = &lbl_3_common_bss_37400;
    s16 ids[9];
    s32 i;
    BOOL ret;

    for (i = 0; i < 9; i++) {
        ids[i] = inMemRoster[1][i].stats.CharID;
    }
    ret = FALSE;
    for (i = 0; i < 9; i++) {
        if (ids[i] != -1 && bss->_00[i]._1 != 0 && bss->_00[i]._0 < bss->_00[i]._1) {
            ret = TRUE;
        }
    }
    return ret;
}

// .text:0x001637EC size:0x15C mapped:0x807A2880
void fn_3_1637EC(void) {
    StarMissionCompletionTracker* tracker = &starMissionCompletionTracker;
    u8 mission = tracker->_441C;
    u8 level = tracker->_4415;
    s16 ids[9];
    s32 i;
    ChallengeTrackingStruct* c;

    for (i = 0; i < 9; i++) {
        ids[i] = inMemRoster[1][i].stats.CharID;
    }
    for (i = 0; i < 9; i++) {
        if (ids[i] != -1) {
            c = &tracker->characters[ids[i]];
            if (c->scoutFlagPointer->_4[level][mission] != 0 &&
                c->scoutFlagsAchieved < c->scoutFlagPointer->_4[level][mission]) {
                c->scoutFlagsAchieved = c->scoutFlagPointer->_4[level][mission];
            }
        }
    }
}

// .text:0x0016230C size:0xA48 mapped:0x807A13A0
void fn_3_16230C(s32 result, s32 streak) {
    return;
}

// .text:0x00162080 size:0x28C mapped:0x807A1114
void fn_3_162080(void) {
    UnkBss37400* bss = &lbl_3_common_bss_37400;
    s32 i;
    s32 j;
    s32 id;
    UnkMissionDef* def;
    UnkMissionDef* m;
    BOOL done;

    if (bss->_40 == g_GameLogic.teamFielding) {
        id = lbl_800E8558[g_Pitcher.charID]._1;
        m = lbl_80109AE8[lbl_800E8558[g_Pitcher.charID]._2];
        for (i = 0; i < 10; i++) {
            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                def = &m[i];
                done = FALSE;
                if (def->type == 3) {
                    if (g_Pitcher.starPitchType) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus |= 1;
                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus == 0x11) {
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                        }
                    }
                } else {
                    for (j = 4; j < 13; j++) {
                        if (def->type == j) {
                            switch (j) {
                            case 11:
                                if (g_Pitcher.starPitchType) {
                                    starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                    if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= def->target) {
                                        done = TRUE;
                                    }
                                }
                                break;
                            case 12:
                                if (g_Pitcher.ChargePitchType == 3) {
                                    starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                    if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= def->target) {
                                        done = TRUE;
                                    }
                                }
                                break;
                            }
                            if (done) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (bss->_40 == g_GameLogic.teamBatting) {
        id = lbl_800E8558[g_Batter.charID]._1;
        m = lbl_80109AE8[lbl_800E8558[g_Batter.charID]._2];
        for (i = 0; i < 10; i++) {
            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                if (m[i].type == 3 && g_Ball.currentStarSwing2) {
                    starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus |= 0x10;
                    if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus == 0x11) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                    }
                }
                if (m[i].type == 2 && (g_GameLogic.IsStarChance == 3 || g_GameLogic.stadiumStarObtained)) {
                    starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                    if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= m[i].target) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                    }
                }
            }
        }
    }
}
