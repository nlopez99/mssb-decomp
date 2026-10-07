#include "game/rep_3DA8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/rand.h"

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
    /* 0x4 */ s16 flags;
    /* 0x6 */ u8 _6[4];
} UnkMissionDef; // size: 0xA

extern UnkMissionDef lbl_80109AE8[32][10];

typedef struct {
    /* 0x000 */ u8 _000[0x17A];
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x268 - 0x17C];
} UnkFielder3DA8; // size: 0x268

extern UnkFielder3DA8 g_Fielders[9];

extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04[2][19];
    /* 0x50 */ s16 _50[2][19];
    /* 0x9C */ u8 _9C[0xA0 - 0x9C];
    /* 0xA0 */ s16 _A0;
    /* 0xA2 */ u8 _A2[0xA4 - 0xA2];
    /* 0xA4 */ s16 _A4;
} g_Scores;

typedef struct {
    /* 0x00 */ u8 _00[4];
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06[3];
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A[3];
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E[0x26 - 0xE];
} UnkPlayerStats3DA8; // size: 0x26

extern UnkPlayerStats3DA8 lbl_803537E4[2][9];

typedef struct {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19[0x1E - 0x19];
} UnkPitcherStats3DA8; // size: 0x1E

extern UnkPitcherStats3DA8 lbl_803535C8[2][9];

typedef struct {
    /* 0x00 */ s8 _00;
    /* 0x01 */ u8 _01[0x14 - 0x1];
} UnkTeamStats3DA8; // size: 0x14

extern struct {
    /* 0x000 */ u8 _000[0xBE];
    /* 0x0BE */ UnkTeamStats3DA8 _0BE[2];
    /* 0x0E6 */ u8 _0E6[0x103 - 0xE6];
    /* 0x103 */ s8 _103;
} lbl_80353A90;

extern struct {
    /* 0x0000 */ u8 _0000[0x46E4];
    /* 0x46E4 */ s32 _46E4;
} lbl_8034E9A0;

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

// .text:0x00163E94 size:0x578 mapped:0x807A2F28
void fn_3_163E94(void) {
    StarMissionCompletionTracker* tracker = &starMissionCompletionTracker;
    UnkBss37400* bss = &lbl_3_common_bss_37400;
    u8 mission = tracker->_441C;
    u8 level = tracker->_4415;
    s32 bonus = lbl_80109420[bss->_46]._9;
    s16 ids[9];
    s32 i;
    s32 n;
    BOOL found;
    ChallengeTrackingStruct* c;

    for (i = 0; i < 9; i++) {
        ids[i] = inMemRoster[1][i].stats.CharID;
    }
    fn_3_163D34();
    n = rand() % 9;
    found = fn_3_163BD4();
    if (bonus > 0 && found) {
        while (bonus > 0) {
            if (ids[n] != -1) {
                c = &tracker->characters[ids[n]];
                if (bss->_00[n]._1 != 0 && bss->_00[n]._0 < bss->_00[n]._1) {
                    bonus--;
                    bss->_12[n]._1 = c->scoutFlagPointer->_4[level][mission];
                    bss->_12[n]._0 = c->scoutFlagsAchieved;
                    bss->_12[n]._2++;
                    bss->_12[n]._3 = 1;
                    bss->_12[n]._4 = ids[n];
                    bss->_00[n]._0++;
                }
            }
            n = (n + 1) % 9;
            if (!fn_3_163948()) {
                break;
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

// .text:0x00162D54 size:0xA98 mapped:0x807A1DE8
void fn_3_162D54(void) {
    s32 i;
    s32 k;
    s32 side = lbl_3_common_bss_37400._40 ^ g_GameLogic.homeTeamInd;
    s32 id;
    s32 idx;
    s32 type;
    s16 flags;
    UnkMissionDef* m;
    UnkCharEntry* entry;

    if (g_d_GameSettings.bJMatchInd != 1) {
        if (lbl_3_common_bss_32A94._4C[side] == 1) {
            idx = lbl_80353A90._0BE[lbl_3_common_bss_37400._40]._00;
            id = lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][idx].stats.CharID]._1;
            m = lbl_80109AE8[lbl_800E8558[id]._2];
            for (k = 0; k < 10; k++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[k].starMissionStatus >= 0) {
                    type = m[k].type;
                    if (type == 7) {
                        if (lbl_3_common_bss_32A94._63[side] == 1) {
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[k].starMissionStatus = -1;
                        }
                    } else if (type == 9 || type == 6) {
                        if (lbl_803535C8[lbl_3_common_bss_37400._40][idx]._18) {
                            if (type == 6) {
                                if (m[k].target == lbl_800E8558[lbl_8034E9A0._46E4]._2) {
                                    starMissionCompletionTracker.characters[id].inGameMissionTracker[k].starMissionStatus = -1;
                                }
                            } else {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[k].starMissionStatus = -1;
                            }
                        }
                    } else if (type == 8) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[k].starMissionStatus = -1;
                    }
                }
            }
        }
        for (k = 0; k < 9; k++) {
            id = lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][k].stats.CharID]._1;
            m = lbl_80109AE8[lbl_800E8558[id]._2];
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    if (m[i].type == 25 && lbl_803537E4[lbl_3_common_bss_37400._40][k]._04 != 0 && lbl_803537E4[lbl_3_common_bss_37400._40][k]._05 * 10 / lbl_803537E4[lbl_3_common_bss_37400._40][k]._04 >= m[i].target) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                    }
                    if (m[i].type == 26 && lbl_803537E4[lbl_3_common_bss_37400._40][k]._0D == 0) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                    }
                }
            }
        }
        if (g_Scores._A4 == side) {
            entry = &lbl_800E8558[lbl_80353A90._103];
            id = entry->_1;
            m = lbl_80109AE8[entry->_2];
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0 &&
                    m[i].type == 1) {
                    starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                }
            }
            for (k = 0; k < 9; k++) {
                id = lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][k].stats.CharID]._1;
                m = lbl_80109AE8[lbl_800E8558[id]._2];
                for (i = 0; i < 10; i++) {
                    if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0 &&
                        m[i].type == 0 && g_d_GameSettings.StadiumID == m[i].target) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                    }
                }
            }
        } else {
            for (k = 0; k < 9; k++) {
                id = lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][k].stats.CharID]._1;
                m = lbl_80109AE8[lbl_800E8558[id]._2];
                for (i = 0; i < 10; i++) {
                    if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus == -1 &&
                        (m[i].flags & 1)) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = 0;
                    }
                }
            }
        }
    }
    for (k = 0; k < 9; k++) {
        id = lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][k].stats.CharID]._1;
        m = lbl_80109AE8[lbl_800E8558[id]._2];
        for (i = 0; i < 10; i++) {
            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus == -1) {
                flags = m[i].flags;
                if (flags & 2) {
                    if (g_d_GameSettings.challengeDifficulty < 1) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = 0;
                    }
                } else if (flags & 4) {
                    if (g_d_GameSettings.challengeDifficulty < 2) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = 0;
                    }
                } else if (flags & 8) {
                    if (g_d_GameSettings.challengeDifficulty < 3) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = 0;
                    }
                }
            }
        }
    }
    for (k = 0; k < 9; k++) {
        id = lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][k].stats.CharID]._1;
        m = lbl_80109AE8[lbl_800E8558[id]._2];
        for (i = 0; i < 10; i++) {
            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus == -1 &&
                (m[i].flags & 0x800) && lbl_8034E9A0._46E4 != 9 && starMissionCompletionTracker._16C2 != 42) {
                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = 0;
            }
        }
    }
    for (k = 0; k < 54; k++) {
        for (i = 0; i < 10; i++) {
            if (starMissionCompletionTracker.characters[k].inGameMissionTracker[i].starMissionStatus <= -1) {
                starMissionCompletionTracker.characters[k].inGameMissionTracker[i].starMissionStatus = -2;
            } else {
                starMissionCompletionTracker.characters[k].inGameMissionTracker[i].starMissionStatus = 0;
            }
        }
    }
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
    UnkBss37400* bss = &lbl_3_common_bss_37400;
    s32 i;
    s32 fielder;
    s32 j;
    s32 k;
    s32 id;
    s32 flags;
    s32 n;
    s32 team;
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
                if (def->type == 2) {
                    if (g_GameLogic.IsStarChance == 2) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                            def->target) {
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                        }
                    }
                } else {
                    for (j = 4; j < 13; j++) {
                        if (def->type == j) {
                            switch (j) {
                                case 4:
                                    if (result == 1 && def->target == lbl_800E8558[g_Batter.charID]._2) {
                                        done = TRUE;
                                    }
                                    break;
                                case 5:
                                    if (result == 3 && def->target == lbl_800E8558[g_Batter.charID]._2) {
                                        done = TRUE;
                                    }
                                    break;
                                case 10:
                                    if (result == 1) {
                                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                            def->target) {
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
        for (fielder = 0; fielder < 9; fielder++) {
            id = lbl_800E8558[g_Fielders[fielder]._17A]._1;
            m = lbl_80109AE8[lbl_800E8558[g_Fielders[fielder]._17A]._2];
            for (j = 0; j < 10; j++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[j].starMissionStatus >= 0 &&
                    m[j].type == 43 && g_Strikes.storedOuts + 2 <= g_Strikes.outs) {
                    def = &m[j];
                    for (k = 0, flags = 0; k < 5; k++) {
                        if (lbl_3_common_bss_32A94._10[k][0] >= 0) {
                            if (lbl_3_common_bss_32A94._10[k][0] == fielder) {
                                flags |= 1;
                            } else if (def->target == lbl_800E8558[g_Fielders[lbl_3_common_bss_32A94._10[k][0]]._17A]._2) {
                                flags |= 0x10;
                            }
                            if (k == 1 && lbl_3_common_bss_32A94._10[k][1] == 2) {
                                break;
                            }
                        }
                    }
                    if (flags == 0x11) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[j].starMissionStatus = -1;
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
                def = &m[i];
                done = FALSE;
                if (def->type == 2) {
                    if (g_GameLogic.IsStarChance == 3 || g_GameLogic.stadiumStarObtained) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                            def->target) {
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                        }
                    }
                } else {
                    team = bss->_40;
                    for (j = 13; j <= 32; j++) {
                        if (def->type == j) {
                            switch (j) {
                                case 13:
                                    if (result == 10 && g_Scores._00 == def->target) {
                                        done = TRUE;
                                    }
                                    break;
                                case 14:
                                    if (result == 10 && streak >= def->target) {
                                        done = TRUE;
                                    }
                                    break;
                                case 15:
                                    if (result >= def->target + 6 && result <= 10) {
                                        done = TRUE;
                                    }
                                    break;
                                case 16:
                                    if (result >= 7 && result <= 10 && g_Pitcher.charID == def->target) {
                                        done = TRUE;
                                    }
                                    break;
                                case 17:
                                    if (result == 10 && def->target == lbl_800E8558[g_Pitcher.charID]._2) {
                                        done = TRUE;
                                    }
                                    break;
                                case 18:
                                    if (streak != 0 && def->target == lbl_800E8558[g_Pitcher.charID]._2) {
                                        done = TRUE;
                                    }
                                    break;
                                case 19:
                                    if (result >= 7 && result <= 10) {
                                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                            def->target) {
                                            done = TRUE;
                                        }
                                    }
                                    break;
                                case 20:
                                case 21:
                                    if (result == 13) {
                                        if (j == 21) {
                                            if (g_Scores._04[g_GameLogic.homeTeamBattingInd_fieldingTeam][0] > g_Scores._A0 &&
                                                g_Runners[3].runnerOnFieldOrOutOrScored &&
                                                g_Runners[3].furthestBaseForcedToGoToOnWalk) {
                                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                                    def->target) {
                                                    done = TRUE;
                                                }
                                            }
                                        } else {
                                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                                def->target) {
                                                done = TRUE;
                                            }
                                        }
                                    }
                                    break;
                                case 22:
                                    if (streak != 0) {
                                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus += streak;
                                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                            def->target) {
                                            done = TRUE;
                                        }
                                    }
                                    break;
                                case 23:
                                    if (result == 10) {
                                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                            def->target) {
                                            done = TRUE;
                                        }
                                    }
                                    break;
                                case 30:
                                    if (result == 10) {
                                        for (k = 0; k < 9; k++) {
                                            if (def->target == lbl_800E8558[inMemRoster[team][k].stats.CharID]._2 &&
                                                lbl_803537E4[team][k]._09) {
                                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                case 24:
                                    if (g_Ball.currentStarSwing2 && streak != 0) {
                                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus += streak;
                                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                            def->target) {
                                            done = TRUE;
                                        }
                                    }
                                    break;
                                case 27:
                                    if (result >= 7 && result <= 10 && g_Batter.hitGeneralType == 1 &&
                                        g_Batter.chargeUp >= 1.0f && !g_Batter.nonCaptainStarSwingActivated) {
                                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                            def->target) {
                                            done = TRUE;
                                        }
                                    }
                                    break;
                                case 28:
                                    if (result == 10) {
                                        n = 0;
                                        for (k = 1; k < 4; k++) {
                                            if (g_Runners[k].runnerOnFieldOrOutOrScored &&
                                                (g_Runners[k].charID == 3 || g_Runners[k].charID == 39)) {
                                                n++;
                                            }
                                        }
                                        if (n == 2) {
                                            done = TRUE;
                                        }
                                    }
                                    break;
                                case 29:
                                    if (result >= 7 && result <= 10 && g_Batter.hitGeneralType == 3) {
                                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                        if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                            def->target) {
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
        if (result == 10) {
            for (k = 0; k < 9; k++) {
                id = lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][k].stats.CharID]._1;
                m = lbl_80109AE8[lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][k].stats.CharID]._2];
                for (i = 0; i < 10; i++) {
                    if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0 &&
                        m[i].type == 30 && m[i].target == lbl_800E8558[g_Batter.charID]._2 &&
                        lbl_803537E4[lbl_3_common_bss_37400._40][k]._09) {
                        starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                    }
                }
            }
        }
    }
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

// .text:0x00161588 size:0xAF8 mapped:0x807A061C
void fn_3_161588(s32 event, s32 player) {
    s32 i;
    s32 id;
    s32 set;

    id = lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][player].stats.CharID]._1;
    set = lbl_800E8558[inMemRoster[lbl_3_common_bss_37400._40][player].stats.CharID]._2;
    switch (event) {
        case 0:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 31:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 32:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
        case 3:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 37:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 33:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                        case 34:
                            if (g_Ball.AtBat_ContactResult == 3) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                    lbl_80109AE8[set][i].target) {
                                    starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                                }
                            }
                            break;
                        case 35:
                            break;
                        case 36:
                            if (g_Ball.currentStarSwing == 5 || g_Ball.currentStarSwing == 6) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                    lbl_80109AE8[set][i].target) {
                                    starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                                }
                            }
                            break;
                    }
                }
            }
            break;
        case 4:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 35:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
        case 5:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 38:
                            if (g_Ball.AtBat_ContactResult == 3) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                    lbl_80109AE8[set][i].target) {
                                    starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                                }
                            }
                            break;
                    }
                }
            }
            break;
        case 6:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 39:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
        case 7:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 40:
                            if (lbl_80109AE8[set][i].target ==
                                lbl_800E8558[g_Fielders[g_Ball.fielderBeingThrownTo]._17A]._2) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
        case 8:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 41:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
        case 9:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 42:
                            if (g_Ball.AtBat_ContactResult == 3) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                    lbl_80109AE8[set][i].target) {
                                    starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                                }
                            }
                            break;
                    }
                }
            }
            break;
        case 10:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 44:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
        case 11:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 45:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
        case 12:
            for (i = 0; i < 10; i++) {
                if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 46:
                            starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus++;
                            if (starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus >=
                                lbl_80109AE8[set][i].target) {
                                starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus = -1;
                            }
                            break;
                    }
                }
            }
            break;
    }
}
