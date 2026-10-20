#include "static/static_8004157C.h"
#include "static/UnknownHomes_Static.h"

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
    /* 0x06 */ u8 _06[0x34 - 6];
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
void fn_800415A8(void) {}

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
