#include "static/static_8004157C.h"
#include "static/UnknownHomes_Static.h"
#include "static/mb_subfunc.h"
#include "string.h"

typedef struct RosterEntry {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01;
    /* 0x02 */ u8 _02;
    /* 0x03 */ u8 _03;
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05[0x24 - 0x05];
    /* 0x24 */ s16 charId;
    /* 0x26 */ u8 _26[2];
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
    /* 0x2A */ u8 _2A;
    /* 0x2B */ u8 _2B;
    /* 0x2C */ u8 _2C;
    /* 0x2D */ u8 _2D[2];
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u8 _30;
    /* 0x31 */ u8 _31[0x37 - 0x31];
    /* 0x37 */ u8 battingBar;
    /* 0x38 */ u8 pitchingBar;
    /* 0x39 */ u8 runningBar;
    /* 0x3A */ u8 fieldingBar;
    /* 0x3B */ u8 chemistry[0x36];
    /* 0x71 */ u8 _71[0xA0 - 0x71];
} RosterEntry; // size: 0xA0

typedef struct StarCharEntry {
    /* 0x00 */ u8 _00[5];
    /* 0x05 */ s8 _05;
    /* 0x06 */ u8 _06[0x31 - 6];
    /* 0x31 */ s8 state;
    /* 0x32 */ u8 _32[2];
} StarCharEntry; // size: 0x34

extern RosterEntry inMemRoster[2][9];
extern union {
    StarCharEntry chars[1];
    struct {
        /* 0x0000 */ u8 _0000[0x42EC];
        /* 0x42EC */ s32 capBonus;
    } s;
} starMissionCompletionTracker;

extern f32 starMissionMenu(s16 charId);
extern f32 fn_8006CA9C(void);


typedef struct CharEntry {
    /* 0x00 */ u8 _00[0x1E];
    /* 0x1E */ u8 _1E[2];
    /* 0x20 */ s32 _20;
    /* 0x24 */ s16 charId;
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
    /* 0x28 */ u8 _28[2];
    /* 0x2A */ u8 _2A[2];
    /* 0x2C */ u8 _2C;
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E;
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u8 _30;
    /* 0x31 */ u8 _31;
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34;
    /* 0x35 */ u8 _35[2];
    /* 0x37 */ u8 _37[4];
    /* 0x3B */ u8 chemistry[0x36];
    /* 0x71 */ u8 _71;
    /* 0x72 */ u8 _72[2];
    /* 0x74 */ u16 _74[21];
    /* 0x9E */ u8 _9E[2];
} CharEntry; // size: 0xA0

extern struct {
    /* 0x0000 */ CharEntry chars[6][9];
    /* 0x21C0 */ u8 _21C0[0x4757 - 0x21C0];
    /* 0x4757 */ u8 _4757[0x36];
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[2];
    /* 0x02 */ s8 _02[2][9];
} lbl_803C6724;

extern s16 lbl_80108EDC[9][5];
extern s8 lbl_80108FF8[10][5];

static inline void CopyCharEntry(CharEntry* dst, CharEntry* src) {
    memcpy(dst->_00, src->_00, sizeof(src->_00));
    dst->charId = src->charId;
    dst->_26 = src->_26;
    dst->_27 = src->_27;
    memcpy(dst->_28, src->_28, sizeof(src->_28));
    memcpy(dst->_2A, src->_2A, sizeof(src->_2A));
    dst->_2C = src->_2C;
    dst->_2D = src->_2D;
    dst->_2E = src->_2E;
    dst->_2F = src->_2F;
    dst->_30 = src->_30;
    dst->_31 = src->_31;
    dst->_32 = src->_32;
    dst->_33 = src->_33;
    dst->_34 = src->_34;
    memcpy(dst->_35, src->_35, sizeof(src->_35));
    dst->_20 = src->_20;
    memcpy(dst->_37, src->_37, sizeof(src->_37));
    memcpy(dst->chemistry, src->chemistry, sizeof(src->chemistry));
    dst->_71 = src->_71;
    dst->_74[0] = src->_74[0];
    dst->_74[1] = src->_74[1];
    dst->_74[2] = src->_74[2];
    dst->_74[3] = src->_74[3];
    dst->_74[4] = src->_74[4];
    dst->_74[5] = src->_74[5];
    dst->_74[6] = src->_74[6];
    dst->_74[7] = src->_74[7];
    dst->_74[8] = src->_74[8];
    dst->_74[9] = src->_74[9];
    dst->_74[10] = src->_74[10];
    dst->_74[11] = src->_74[11];
    dst->_74[12] = src->_74[12];
    dst->_74[13] = src->_74[13];
    dst->_74[14] = src->_74[14];
    dst->_74[15] = src->_74[15];
    dst->_74[16] = src->_74[16];
    dst->_74[17] = src->_74[17];
    dst->_74[18] = src->_74[18];
    dst->_74[19] = src->_74[19];
    dst->_74[20] = src->_74[20];
}

static inline BOOL HasEmptySlot(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._02[1][i] == 0x36) {
            return TRUE;
        }
    }
    return FALSE;
}

u16 lbl_803CBCC0;

// .text:0x8004207C size:0x51C
static inline u8 ScaleStat(f32 scale, u8 value) {
    s32 scaled = scale * value;

    return scaled > 100 ? 100 : scaled;
}

void capApplicationFunction(void) {
    RosterEntry* player;
    s32 team;
    s32 i;
    s32 k;
    f32 scale;
    u8 bonus = 0;
    s32 delta = 0;
    s8 kind;

    for (team = 0; team < 2; team++) {
        for (i = 0; i < 9; i++) {
            player = &inMemRoster[team][i];
            if (team == 0) {
                scale = (100.0f + starMissionMenu(player->charId)) / 100.0f;
            } else {
                scale = (100.0f + fn_8006CA9C()) / 100.0f;
            }
            player->_28 = ScaleStat(scale, player->_28);
            player->_29 = ScaleStat(scale, player->_29);
            player->_2A = ScaleStat(scale, player->_2A);
            player->_2B = ScaleStat(scale, player->_2B);
            player->_2C = ScaleStat(scale, player->_2C);
            player->_2F = ScaleStat(scale, player->_2F);
            player->_30 = ScaleStat(scale, player->_30);
            player->_00 += 10;
            if (player->_00 > 200) {
                player->_00 = 200;
            }
            player->_01 += 10;
            if (player->_01 > 200) {
                player->_01 = 200;
            }
            player->_03 = ScaleStat(scale, player->_03);
            player->_04 = ScaleStat(scale, player->_04);
            if (team == 0) {
                bonus = starMissionCompletionTracker.s.capBonus;
                // the chemistry table is read as bytes from the entry's start
                for (k = 0; k < 0x36; k++) {
                    ((u8*)player)[0x3B + k] += bonus * 5;
                    if (((u8*)player)[0x3B + k] > 100) {
                        ((u8*)player)[0x3B + k] = 100;
                    }
                }
            }
            switch (bonus) {
            case 0:
                delta = -1;
                break;
            case 1:
                delta = 0;
                break;
            case 2:
                delta = 1;
                break;
            case 3:
                kind = starMissionCompletionTracker.chars[player->charId]._05;
                if (kind == 0 || kind == 1) {
                    delta = 2;
                } else {
                    delta = 1;
                }
                break;
            case 4:
                kind = starMissionCompletionTracker.chars[player->charId]._05;
                if (kind == 0) {
                    delta = 3;
                } else if (kind == 1) {
                    delta = 2;
                } else {
                    delta = 1;
                }
                break;
            }
            player->battingBar += delta;
            if (player->battingBar > 10) {
                player->battingBar = 10;
            }
            player->pitchingBar += delta;
            if (player->pitchingBar > 10) {
                player->pitchingBar = 10;
            }
            player->runningBar += delta;
            if (player->runningBar > 10) {
                player->runningBar = 10;
            }
            player->fieldingBar += delta;
            if (player->fieldingBar > 10) {
                player->fieldingBar = 10;
            }
        }
    }
}

// .text:0x800415A8 size:0xAD4
void fn_800415A8(void) {
    u8 start = 0;
    s32 i;
    s32 k;
    s32 m;
    s16 j = 0;
    s16 id;
    u8 found;
    u8 count = 0;

    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._02[1][i] == 0x36) {
            found = 1;
        }
    }
    if (found) {
        for (i = 0; i < 9; i++) {
            for (j = 1; j < 5; j++) {
                id = fn_80067AC8(lbl_803C6724._02[1][i], j);
                if (id == -1) {
                    break;
                }
                for (k = 0; k < 9; k++) {
                    if (lbl_803C6724._02[1][k] == 0x36 && id != -1) {
                        for (m = 0; m < 9; m++) {
                            if (lbl_803C6724._02[1][m] == id) {
                                count++;
                            }
                        }
                        if (count < 2) {
                            lbl_803C6724._02[1][k] = id;
                            lbl_8034E9A0._4757[id] = 1;
                        }
                        count = 0;
                        break;
                    }
                }
            }
        }
        if (!HasEmptySlot()) {
            goto copy;
        }
    loop2:
        j = 1;
        for (i = start; i < 0x36; i++) {
            if (starMissionCompletionTracker.chars[i].state == 2) {
                id = fn_80067AC8(i, j);
                for (k = 0; k < 9; k++) {
                    if (id == lbl_803C6724._02[1][k]) {
                        j++;
                        if (j > 5) {
                            j = 1;
                            goto next2;
                        }
                        id = fn_80067AC8(i, j);
                    }
                }
                if (id != -1) {
                    for (m = 0; m < 9; m++) {
                        if (id == lbl_80108EDC[m][0]) {
                            id = -1;
                        }
                    }
                }
                start = i;
                if (id != -1) {
                    break;
                }
            }
        next2:;
        }
        if (i == 0x36) {
            start = 0;
        } else {
            for (k = 0; k < 9; k++) {
                if (lbl_803C6724._02[1][k] == 0x36) {
                    lbl_803C6724._02[1][k] = id;
                    lbl_8034E9A0._4757[id] = 1;
                    goto loop2;
                }
            }
            if (!HasEmptySlot()) {
                goto copy;
            }
        }
    loop3:
        for (i = start; i < 0x36; i++) {
            if (starMissionCompletionTracker.chars[i].state == 1 && lbl_8034E9A0._4757[i] == 0) {
                for (m = 0; m < 10; m++) {
                    if (i == lbl_80108FF8[m][0]) {
                        if (m < 7) {
                            if (lbl_8034E9A0._4757[lbl_80108FF8[m][0]] == 0) {
                                id = fn_80067AC8(i, 0);
                            } else {
                                id = -1;
                            }
                        } else {
                            id = i;
                        }
                        break;
                    }
                }
                if (m == 10) {
                    id = -1;
                }
                if (id != -1) {
                    start = i;
                    break;
                }
            }
        }
        if (i != 0x36) {
            for (k = 0; k < 9; k++) {
                if (lbl_803C6724._02[1][k] == 0x36) {
                    lbl_803C6724._02[1][k] = id;
                    lbl_8034E9A0._4757[id] = 1;
                    goto loop3;
                }
            }
            if (!HasEmptySlot()) {
                goto copy;
            }
        }
        count = 0;
        for (i = count; i < 9; i++) {
            for (j = 1; j < 5; j++) {
                id = fn_80067AC8(lbl_803C6724._02[1][i], j);
                if (id == -1) {
                    break;
                }
                for (k = 0; k < 9; k++) {
                    if (lbl_803C6724._02[1][k] == 0x36 && id != -1) {
                        for (m = 0; m < 9; m++) {
                            if (lbl_803C6724._02[1][m] == id) {
                                count++;
                            }
                        }
                        if (count < 4) {
                            lbl_803C6724._02[1][k] = id;
                            lbl_8034E9A0._4757[id] = 1;
                        }
                        count = 0;
                        break;
                    }
                }
            }
        }
    }
copy:
    for (i = 0; i < 9; i++) {
        id = lbl_803C6724._02[1][i];
        CopyCharEntry((CharEntry*)&inMemRoster[1][i], &lbl_8034E9A0.chars[id / 9][id % 9]);
    }
}

// .text:0x800415A0 size:0x8
void fn_800415A0(u16 frames) {
    lbl_803CBCC0 = frames;
}

// .text:0x8004157C size:0x24
u16 fn_8004157C(void) {
    if (lbl_803CBCC0 != 0) {
        lbl_803CBCC0--;
        return 1;
    }
    return 0;
}
