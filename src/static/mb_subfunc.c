#include "static/mb_subfunc.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct MbState {
    /* 0x0000 */ u8 _0000[0x46E0];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x46F8 - 0x46E8];
    /* 0x46F8 */ u8 ports[2];
    /* 0x46FA */ u8 _46FA[0x4709 - 0x46FA];
    /* 0x4709 */ s8 _4709[2];
    /* 0x470B */ u8 _470B[0x48C0 - 0x470B];
} MbState; // size: 0x48C0

typedef struct MbGameOptions {
    /* 0x00 */ u8 inningSetting;
    /* 0x01 */ u8 _01;
    /* 0x02 */ u8 _02;
    /* 0x03 */ u8 _03;
    /* 0x04 */ u8 _04[0x28 - 0x04];
} MbGameOptions; // size: 0x28

typedef struct MbSound {
    /* 0x000 */ u8 _000[0x398];
    /* 0x398 */ u8 _398;
} MbSound;

typedef struct MbStadiumState {
    /* 0x00 */ u8 _00[0xF5];
    /* 0xF5 */ u8 _F5;
} MbStadiumState;

typedef struct MbRosterEntry {
    /* 0x00 */ u8 _00[0x24];
    /* 0x24 */ s16 charId;
    /* 0x26 */ u8 _26[0xA0 - 0x26];
} MbRosterEntry; // size: 0xA0

typedef struct MbTrack {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec prev;
    /* 0x18 */ s32 _18;
    /* 0x1C */ u8 _1C;
} MbTrack; // size: 0x20

extern MbState lbl_8034E9A0;
extern MbRosterEntry inMemRoster[2][9];
extern MbTrack lbl_802E4BC0[9];
extern MbGameOptions gameInitOptions;
extern MbSound lbl_800EF808;
extern MbStadiumState lbl_80361B20;
extern u8 lbl_802E4CE8[][0x50];

extern s16 lbl_80108EDC[][5];
extern u8 lbl_800E88A4[][2];
extern u8 lbl_800E87B4[][0x10];
extern u8 lbl_8034E478[][0x50];
extern u16 lbl_803CBD24;
extern u8 lbl_80109044[];

typedef struct MbLoader {
    /* 0x000 */ u8 _000[0x79C];
    /* 0x79C */ s32 _79C;
} MbLoader;

typedef struct MbAram {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ u8 _715;
} MbAram;

extern MbLoader lbl_80366B18;
extern MbAram lbl_803C6CF8;

extern s32 randRange_FUN_80042bf0(s32 min, s32 max);
extern s32 ARAMTransfer(void* src, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800111B4(s32 handle);
extern void fn_800A8878(u8 arg0, u8 arg1);
extern void fn_800A8AB0(s32 arg0);
extern void fn_800A8E30(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern void fn_800A86B4(s32 arg0);
extern void fn_800A8B78(void* arg0);

u8 lbl_80108EC4[12] = { 0, 4, 10, 2, 6, 9, 1, 5, 11, 3, 17, 19 };
u8 lbl_803CB8D0[8] = { 3, 2, 1 };

// .text:0x800698F8 size:0x170
void fn_800698F8(void) {
}

// .text:0x80069854 size:0xA4
void fn_80069854(void) {
    s32 team;
    s32 i;

    for (team = 0; team < 2; team++) {
        for (i = 0; i < 9; i++) {
            if (lbl_8034E9A0._46E0[team] == inMemRoster[team][i].charId) {
                lbl_8034E9A0._4709[team] = i;
            }
        }
    }
}

// .text:0x800697B0 size:0xA4
s32 fn_800697B0(void) {
    switch (lbl_803CBD24) {
    case 0:
        lbl_80366B18._79C = ARAMTransfer(lbl_80109044, 0, 1, 0);
        lbl_803CBD24++;
        break;
    case 1:
        if ((s32)lbl_803C6CF8._715 == 1) {
            fn_800111B4(lbl_80366B18._79C);
            lbl_803CBD24 = 0;
            return 0;
        }
        break;
    }
    return 1;
}

// .text:0x80068838 size:0xF78
void fn_80068838(void) {
}

// .text:0x8006877C size:0xBC
void fn_8006877C(u8 index) {
    if (lbl_800EF808._398 != 0) {
        fn_800A8878(lbl_800E88A4[index][0], lbl_800E88A4[index][0]);
        if (index == 12) {
            fn_800A8AB0(0);
        } else {
            fn_800A8AB0(2);
        }
        fn_800A8E30(lbl_800E87B4[index], lbl_8034E478[index], 0, 0);
        fn_800A86B4(4);
        fn_800A86B4(1);
    }
}

// .text:0x80068720 size:0x5C
void fn_80068720(u8 index) {
    if (lbl_800EF808._398 != 0) {
        fn_800A86B4(3);
        fn_800A8B78(lbl_802E4CE8[index]);
    }
}

// .text:0x8006862C size:0xF4
void fn_8006862C(void) {
}

// .text:0x80068514 size:0x118
void fn_80068514(void) {
}

// .text:0x800684A4 size:0x70
void fn_800684A4(void) {
    s32* ids = lbl_8034E9A0._46E0;

    ids[0] = lbl_80108EC4[randRange_FUN_80042bf0(0, 12)];
    do {
        ids[1] = lbl_80108EC4[randRange_FUN_80042bf0(0, 12)];
    } while (ids[0] == ids[1]);
}

// .text:0x80067F70 size:0x534
void fn_80067F70(void) {
}

// .text:0x80067C48 size:0x328
void fn_80067C48(void) {
}

// .text:0x80067B40 size:0x108
void fn_80067B40(void) {
}

// .text:0x80067AC8 size:0x78
s16 fn_80067AC8(s16 id, s8 slot) {
    s32 i;
    s32 j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 5; j++) {
            if (id == lbl_80108EDC[i][j]) {
                if (slot == -1) {
                    return id;
                }
                return lbl_80108EDC[i][slot];
            }
            if (lbl_80108EDC[i][j] == -1) {
                break;
            }
        }
    }
    return -1;
}

// .text:0x800678CC size:0x1FC
void fn_800678CC(void) {
}

// .text:0x800675C4 size:0x308
void fn_800675C4(void) {
}

// .text:0x80067264 size:0x360
void fn_80067264(void) {
}

// .text:0x800671FC size:0x68
void fn_800671FC(void) {
    u8 stadium;

    if (lbl_80361B20._F5 != 0) {
        stadium = randRange_FUN_80042bf0(0, 5);
    } else {
        do {
            stadium = randRange_FUN_80042bf0(0, 5);
        } while (stadium == 1);
    }
    g_d_GameSettings.StadiumID = stadium;
}

// .text:0x800670A0 size:0x15C
void fn_800670A0(void) {
}

// .text:0x80066EAC size:0x1F4
void fn_80066EAC(void) {
}

// .text:0x80065DEC size:0x10C0
void characterSelectScreen(void) {
}

// .text:0x80064A04 size:0x13E8
void unsure_FillRosterPositions(void) {
}

// .text:0x800649BC size:0x48
void fn_800649BC(void) {
    g_d_GameSettings.home_AwaySetting = randRange_FUN_80042bf0(0, 1);
    gameInitOptions.inningSetting = 3;
    gameInitOptions._03 = lbl_803CB8D0[0];
}

// .text:0x8006496C size:0x50
void fn_8006496C(void) {
    u8* ports = lbl_8034E9A0.ports;

    g_d_GameSettings.PlayerPorts[0] = ports[0];
    if (g_d_GameSettings._10 == 0) {
        if (ports[0] == 0) {
            g_d_GameSettings.PlayerPorts[1] = 5;
        } else {
            g_d_GameSettings.PlayerPorts[1] = 4;
        }
    } else {
        g_d_GameSettings.PlayerPorts[1] = ports[1];
    }
}

// .text:0x80064918 size:0x54
s32 fn_80064918(s16 id) {
    switch (id) {
    case 0:
    case 1:
        return 4;
    case 4:
    case 5:
    case 11:
    case 14:
        return 1;
    case 3:
    case 28:
    case 33:
    case 34:
    case 35:
    case 36:
    case 39:
    case 47:
        return 2;
    case 12:
    case 16:
    case 32:
    case 40:
    case 44:
    case 45:
    case 46:
    case 48:
    case 51:
        return 5;
    case 6:
    case 7:
    case 8:
    case 13:
    case 15:
    case 18:
    case 20:
    case 24:
    case 25:
    case 26:
    case 29:
    case 30:
    case 31:
    case 41:
    case 43:
        return 3;
    }
    return 0;
}

// .text:0x8006487C size:0x9C
s32 translateStarSwing(s32 index) {
    switch ((u8)index) {
    case 0:
        return 0x84;
    case 1:
        return 0x86;
    case 2:
        return 0x90;
    case 3:
        return 0x92;
    case 4:
        return 0x98;
    case 5:
        return 0x9A;
    case 6:
        return 0x8C;
    case 7:
        return 0x8E;
    case 8:
        return 0x88;
    case 9:
        return 0x8A;
    case 10:
        return 0x94;
    case 11:
        return 0x96;
    case 12:
        return 0x9D;
    case 13:
        return 0x9E;
    case 14:
        return 0x9F;
    }
    return index;
}

// .text:0x800647E0 size:0x9C
s32 translateStarPitch(s32 index) {
    switch ((u8)index) {
    case 0:
        return 0x85;
    case 1:
        return 0x87;
    case 2:
        return 0x91;
    case 3:
        return 0x93;
    case 4:
        return 0x99;
    case 5:
        return 0x9B;
    case 6:
        return 0x8D;
    case 7:
        return 0x8F;
    case 8:
        return 0x89;
    case 9:
        return 0x8B;
    case 10:
        return 0x95;
    case 11:
        return 0x97;
    case 12:
        return 0xA1;
    case 13:
        return 0xA0;
    case 14:
        return 0xA2;
    }
    return index;
}

// .text:0x80064754 size:0x8C
s8 translateStarPitchHitIndex(u8 index) {
    switch (index) {
    case 0:
        return 6;
    case 1:
        return 7;
    case 2:
        return 10;
    case 3:
        return 11;
    case 4:
        return 14;
    case 5:
        return 15;
    case 6:
        return 16;
    case 7:
        return 17;
    case 8:
        return 12;
    case 9:
        return 13;
    case 10:
        return 8;
    case 11:
        return 9;
    }
    return -1;
}

// .text:0x80064534 size:0x220
void fn_80064534(void) {
}

// .text:0x80064430 size:0x104
void fn_80064430(void) {
}

// .text:0x80064344 size:0xEC
void fn_80064344(void) {
}

// .text:0x800639BC size:0x988
void fn_800639BC(void) {
}

// .text:0x80063958 size:0x64
void fn_80063958(s8 index) {
    MbTrack* t = &lbl_802E4BC0[index];

    memset(&t->pos, 0, sizeof(Vec));
    memset(&t->prev, 0, sizeof(Vec));
    t->_18 = 0;
    t->_1C = 0;
}

// .text:0x800638CC size:0x8C
void fn_800638CC(void) {
    u32 i;

    for (i = 0; i < 9; i++) {
        fn_80063958(i);
    }
}

