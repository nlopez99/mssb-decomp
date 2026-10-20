#include "static/mb_subfunc.h"
#include "Dolphin/os.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct MbRosterEntry {
    /* 0x00 */ u8 _00[0x24];
    /* 0x24 */ s16 charId;
    /* 0x26 */ u8 _26[0x31 - 0x26];
    /* 0x31 */ u8 attribute;
    /* 0x32 */ u8 _32[0x3B - 0x32];
    /* 0x3B */ u8 chemistry[0x36];
    /* 0x71 */ u8 _71[0xA0 - 0x71];
} MbRosterEntry; // size: 0xA0

typedef struct MbState {
    /* 0x0000 */ MbRosterEntry chars[2][9];
    /* 0x0B40 */ u8 _0B40[0x46E0 - 0xB40];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x46F8 - 0x46E8];
    /* 0x46F8 */ u8 ports[2];
    /* 0x46FA */ u8 _46FA[0x4709 - 0x46FA];
    /* 0x4709 */ s8 _4709[2];
    /* 0x470B */ u8 _470B[0x470F - 0x470B];
    /* 0x470F */ s8 _470F[2];
    /* 0x4711 */ u8 _4711[0x4757 - 0x4711];
    /* 0x4757 */ u8 _4757[0x478D - 0x4757];
    /* 0x478D */ u8 _478D[2][54];
    /* 0x47F9 */ s8 _47F9[2][9][9];
    /* 0x489B */ u8 _489B[0x48AE - 0x489B];
    /* 0x48AE */ u8 _48AE;
    /* 0x48AF */ u8 _48AF[0x48C0 - 0x48AF];
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


typedef struct MbTrack {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec prev;
    /* 0x18 */ s32 _18;
    /* 0x1C */ u8 _1C;
} MbTrack; // size: 0x20

typedef struct MbTeams {
    /* 0x00 */ u8 _00[0x2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ u8 _14[0x26 - 0x14];
    /* 0x26 */ u8 _26[2][9];
    /* 0x38 */ u8 _38[0x5C - 0x38];
} MbTeams; // size: 0x5C

typedef struct MbStatGroup {
    /* 0x0 */ s32 a;
    /* 0x4 */ s16 b;
    /* 0x6 */ s16 c;
} MbStatGroup; // size: 0x8

typedef struct MbStatSlot {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
} MbStatSlot; // size: 0x16

typedef struct MbStats {
    /* 0x000 */ MbStatGroup head[5];
    /* 0x028 */ MbStatGroup rows[6][5];
    /* 0x118 */ MbStatGroup tail[5];
    /* 0x140 */ MbStatSlot slots[32];
    /* 0x400 */ u8 _400[0x454 - 0x400];
} MbStats; // size: 0x454

extern MbStats lbl_803616CC;
extern s32 lbl_800E88C4[6][5][3];
extern s32 lbl_800E8A2C[5][3];
extern s32 lbl_800E8A68[5][3];
extern u8 lbl_800E869C[32];

extern void fn_8006C398(MbStatSlot* slot);

typedef struct MbSlot {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
} MbSlot; // size: 0x4

extern MbSlot lbl_80354720[2][9];
extern MbState lbl_8034E9A0;
extern MbTeams lbl_803C6724;
extern u8 lbl_80108DB8[];
extern u8 lbl_80108ED0[12];
extern u8 lbl_8010902C[12];
extern u8 lbl_80108DDC[];
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

// fn_8002B7F8's parameter block (static/particle.c names its fields differently)
typedef struct MbSpark {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 glowTex;
    /* 0x08 */ s32 glowCount;
    /* 0x0C */ s32 glowLife;
    /* 0x10 */ s32 glowSwitch;
    /* 0x14 */ f32 glowH[3];
    /* 0x20 */ f32 glowW[3];
    /* 0x2C */ s32 glowAlpha[3];
    /* 0x38 */ f32 radius;
    /* 0x3C */ f32 angle;
    /* 0x40 */ f32 arc;
    /* 0x44 */ s32 sparkTex;
    /* 0x48 */ s32 sparkCount;
    /* 0x4C */ s32 sparkLife;
    /* 0x50 */ s32 sparkSwitch;
    /* 0x54 */ f32 size[3];
    /* 0x60 */ s32 alpha[3];
    /* 0x6C */ s32 _6C;
} MbSpark; // size: 0x70

extern MbSpark lbl_80108D48;
extern s32 lbl_803CBD0C;

extern void fn_8002B7F8(Vec* pos, MbSpark* params, u8 glow);
extern s32 randRange_FUN_80042bf0(s32 min, s32 max);
extern s32 ARAMTransfer(void* src, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800111B4(s32 handle);
extern u32 fn_800A8864(void);
extern void fn_800A8878(u8 left, u8 right);
extern u8 lbl_803CBD18;
extern u8 lbl_803CBD19;
extern s16 lbl_803CBD1A;
extern u8 lbl_803CBD1C;
extern u8 lbl_803CBD1D;
extern u8 lbl_803CBD1E;
extern u8 lbl_803CBD1F;
extern u8 lbl_803CBD20;
extern void fn_800A8AB0(s32 arg0);
extern void fn_800A8E30(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern void fn_800A86B4(s32 arg0);
extern void fn_800A8B78(void* arg0);

u8 lbl_80108EC4[12] = { 0, 4, 10, 2, 6, 9, 1, 5, 11, 3, 17, 19 };
u8 lbl_803CB8D0[8] = { 3, 2, 1 };

// .text:0x800698F8 size:0x170
s32 fn_800698F8(s32 charId) {
    s32 i;

    for (i = 0; i < 32; i++) {
        if (lbl_80108DB8[i] == charId) {
            if (i == 17 && lbl_8034E9A0._48AE != 0) {
                i = 32;
            }
            lbl_8034E9A0._48AE = 0;
            return i;
        }
    }
    if (i == 32) {
        for (i = 0; i < 22; i++) {
            if (lbl_80108DDC[i] == charId) {
                switch (i) {
                case 0:
                case 1:
                    charId = 0x15;
                    break;
                case 2:
                case 3:
                    charId = 0x16;
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    charId = 0xD;
                    break;
                case 8:
                case 9:
                case 10:
                    charId = 0x19;
                    break;
                case 11:
                    charId = 0xC;
                    break;
                case 12:
                    charId = 0x14;
                    break;
                case 13:
                case 14:
                case 15:
                case 16:
                    charId = 0x10;
                    break;
                case 17:
                case 18:
                case 19:
                    charId = 0x1F;
                    break;
                case 20:
                case 21:
                    charId = 0x17;
                    break;
                }
                lbl_8034E9A0._48AE = 0;
                return charId;
            }
        }
        if (i == 22) {
            OSPanic("mb_subfunc.c", 149, "The character doesn't exist");
        }
    }
    OSPanic("mb_subfunc.c", 153, "//OZ \x96\xdf\x82\xe8\x92l\x82\xaa\x82\xa0\x82\xe8\x82\xdc\x82\xb9\x82\xf1\n");
    return 0;
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
s32 fn_8006862C(u32 frames, u8 target) {
    u8 vol = fn_800A8864() >> 8;

    if (lbl_803CBD18 == 0) {
        lbl_803CBD20 = vol / (frames / 60);
        if (lbl_803CBD20 > 60) {
            lbl_803CBD20 = 60;
        }
        lbl_803CBD18 = 1;
    }
    if (lbl_803CBD19 % (60 / lbl_803CBD20) == 0) {
        vol--;
        lbl_803CBD19 = 0;
    }
    if (vol <= target || frames == 1) {
        lbl_803CBD19 = 0;
        lbl_803CBD1A = 0;
        lbl_803CBD20 = 0;
        lbl_803CBD18 = 0;
        return 0;
    }
    fn_800A8878(vol, vol);
    lbl_803CBD19++;
    return 1;
}

// .text:0x80068514 size:0x118
s32 fn_80068514(u32 frames, u8 target) {
    lbl_803CBD1F = fn_800A8864() >> 8;
    if (lbl_803CBD1F >= target) {
        lbl_803CBD1F = target;
        return 0;
    }
    if (lbl_803CBD1C == 0) {
        lbl_803CBD1E = target / (frames / 60);
        if (lbl_803CBD1E > 60) {
            lbl_803CBD1E = 60;
        }
        lbl_803CBD1C = 1;
    }
    if (lbl_803CBD1D % (60 / lbl_803CBD1E) == 0) {
        lbl_803CBD1D = 0;
        lbl_803CBD1F++;
    }
    if (lbl_803CBD1F >= target) {
        lbl_803CBD1D = 0;
        lbl_803CBD1E = 0;
        lbl_803CBD1C = 0;
        fn_800A8878(target, target);
        return 0;
    }
    fn_800A8878(lbl_803CBD1F, lbl_803CBD1F);
    lbl_803CBD1D++;
    return 1;
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
void fn_80067F70(u8 team) {
    s32 n;
    s8 pool[54];
    s32 cap;
    s32 i;
    s32 j;
    s32 k;
    s8 pick;
    s8 idx;
    s16 v;

    cap = lbl_8034E9A0._46E0[team];
    lbl_803C6724._02[team][0] = cap;
    fn_80067C48(team);
    memset(pool, -1, sizeof(pool));
    for (i = 0; i < 54; i++) {
        if (lbl_8034E9A0._4757[lbl_8034E9A0._478D[team][i]] == 0) {
            pool[i] = lbl_8034E9A0._478D[team][i];
        }
    }
    for (n = 1; n < 9; n++) {
        for (i = 0; i < 54; i++) {
            for (j = i; j < 54; j++) {
                if (pool[i] == -1 && pool[j] != -1) {
                    s8 tmp = pool[i];
                    pool[i] = pool[j];
                    pool[j] = tmp;
                    break;
                }
            }
        }
        do {
            idx = randRange_FUN_80042bf0(0, 19);
            pick = pool[idx];
        } while (pick == -1);
        pool[idx] = -1;
        lbl_8034E9A0._4757[pick] = 1;
        fn_80067B40(0, pick, 1);
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 5; j++) {
                if (pick == lbl_80108EDC[i][j]) {
                    pick = lbl_80108EDC[i][0];
                    for (k = 0; k < 5; k++) {
                        v = lbl_80108EDC[i][k];
                        if (v != -1) {
                            for (j = 0; j < 54; j++) {
                                if (pool[j] == v) {
                                    pool[j] = -1;
                                }
                            }
                        }
                    }
                    goto found;
                }
            }
        }
    found:
        lbl_803C6724._02[team][n] = pick;
        lbl_803C6724._26[team][n] = lbl_8034E9A0.chars[pick / 9][pick % 9].chemistry[cap];
    }
    for (i = 0; i < 9; i++) {
        lbl_80354720[team][i]._2 = i;
        lbl_80354720[team][i]._1 = i;
        lbl_80354720[team][i]._0 = i;
    }
    fn_800670A0(team);
}

// .text:0x80067C48 size:0x328
void fn_80067C48(u8 team) {
    u8 ids[54];
    u8 chem[54];
    s32 i;
    s32 j;
    u8 best;
    u8 t2;
    u8 t;
    s32 cap = lbl_8034E9A0._46E0[team];
    s32 col = cap % 9;
    s32 row = cap / 9;

    for (i = 0; i < 54; i++) {
        chem[i] = lbl_8034E9A0.chars[row][col].chemistry[i];
        ids[i] = i;
    }
    for (i = 0; i < 54; i++) {
        best = chem[i];
        for (j = i + 1; j < 54; j++) {
            if (best < chem[j]) {
                t = chem[i];
                best = chem[j];
                t2 = ids[i];
                chem[i] = chem[j];
                ids[i] = ids[j];
                chem[j] = t;
                ids[j] = t2;
            }
        }
    }
    for (i = 0; i < 54; i++) {
        lbl_8034E9A0._478D[team][i] = ids[i];
    }
}

// .text:0x80067B40 size:0x108
s32 fn_80067B40(s32 arg0, u8 id, u8 value) {
    s32 i;
    s32 j;
    s32 k;

    if (id == -1) {
        return 0;
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 5; j++) {
            if (id == lbl_80108EDC[i][j]) {
                for (k = 0; k < 5; k++) {
                    if (lbl_80108EDC[i][k] != -1 && value != 2) {
                        lbl_8034E9A0._4757[lbl_80108EDC[i][k]] = value;
                    }
                }
                return 1;
            }
        }
    }
    return 0;
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
s32 fn_80067264(s32 team, s32 captain) {
    s32 counts[4];
    s32 attr[2][9];
    s32 i;
    int j;
    s32 color;

    counts[0] = 0;
    counts[1] = 0;
    counts[2] = 0;
    counts[3] = 0;
    for (j = 0; j < 9; j++) {
        attr[team][j] = 0;
        attr[team][j] = lbl_8034E9A0.chars[lbl_803C6724._02[team][j] / 9][lbl_803C6724._02[team][j] % 9].attribute;
    }
    for (j = 0; j < 12; j++) {
        if (captain == lbl_80108ED0[j]) {
            color = lbl_8010902C[j];
            break;
        }
    }
    for (i = 0; i < 9; i++) {
        counts[attr[team][i]]++;
    }
    for (i = 0; i < 4; i++) {
        if (counts[color] <= counts[i] && i != color) {
            return 0;
        }
    }
    for (j = 0; j < 4; j++) {
        if (counts[j] >= 3 && j == color) {
            return 3;
        }
    }
    return 0;
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
void fn_800670A0(u8 team) {
    s32 i;
    s32 sum = 0;
    s32 avg = 0;
    s32 count = 0;
    s8 rank = 0;

    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._26[team][i] != 0 && lbl_803C6724._02[team][i] != lbl_8034E9A0._46E0[team]) {
            sum += lbl_803C6724._26[team][i];
            count++;
        }
    }
    if (count != 0) {
        avg = sum / count;
    }
    if (avg >= 70) {
        rank = 5;
    } else if (avg <= 69 && avg >= 55) {
        rank = 4;
    } else if (avg <= 54 && avg >= 35) {
        rank = 3;
    } else if (avg <= 34 && avg >= 15) {
        rank = 2;
    } else if (avg <= 14 && avg > 0) {
        rank = 1;
    }
    lbl_8034E9A0._470F[team] = rank;
}

// .text:0x80066EAC size:0x1F4
void fn_80066EAC(u8 team) {
    s8 list[10];
    s32 i;
    s32 j;
    s32 k;
    s8 tmp;
    u8 chem;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            chem = inMemRoster[team][i].chemistry[inMemRoster[team][j].charId];
            if (chem < 90 || chem == 100) {
                list[j] = -1;
            } else {
                list[j] = inMemRoster[team][j].charId;
            }
        }
        for (j = 0; j < 9; j++) {
            for (k = 0; k < 10; k++) {
                if (list[j] > list[k]) {
                    tmp = list[j];
                    list[j] = list[k];
                    list[k] = tmp;
                }
            }
        }
        memcpy(lbl_8034E9A0._47F9[team][i], list, 9);
    }
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
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            lbl_803616CC.rows[i][j].a = lbl_800E88C4[i][j][0];
            lbl_803616CC.rows[i][j].b = lbl_800E88C4[i][j][1];
            lbl_803616CC.rows[i][j].c = lbl_800E88C4[i][j][2];
        }
    }
    for (j = 0; j < 5; j++) {
        lbl_803616CC.head[j].a = lbl_800E8A2C[j][0];
        lbl_803616CC.head[j].b = lbl_800E8A2C[j][1];
        lbl_803616CC.head[j].c = lbl_800E8A2C[j][2];
    }
    for (j = 0; j < 5; j++) {
        lbl_803616CC.tail[j].a = lbl_800E8A68[j][0];
        lbl_803616CC.tail[j].b = lbl_800E8A68[j][1];
        lbl_803616CC.tail[j].c = lbl_800E8A68[j][2];
    }
    for (i = 0; i < 32; i++) {
        fn_8006C398(&lbl_803616CC.slots[i]);
        lbl_803616CC.slots[i]._14 = lbl_800E869C[i];
    }
}

// .text:0x80064430 size:0x104
void fn_80064430(Vec* pos, u8 glow, f32 size, f32 spread) {
    MbSpark params;

    memcpy(&params, &lbl_80108D48, sizeof(MbSpark));
    params._00 = lbl_803CBD0C;
    params.glowH[0] *= spread;
    params.glowH[1] *= spread;
    params.glowH[2] *= spread;
    params.glowW[0] *= spread;
    params.glowW[1] *= spread;
    params.glowW[2] *= spread;
    params.radius *= spread;
    params.size[0] *= size;
    params.size[1] *= size;
    params.size[2] *= size;
    fn_8002B7F8(pos, &params, glow);
}

// .text:0x80064344 size:0xEC
void fn_80064344(Vec* pos, Vec* vel) {
    MbSpark params;
    f32 scale = 3.0f * PSVECMag(vel);

    memcpy(&params, &lbl_80108D48, sizeof(MbSpark));
    params._00 = lbl_803CBD0C;
    params.glowH[0] *= scale;
    params.glowH[1] *= scale;
    params.glowH[2] *= scale;
    params.glowW[0] *= scale;
    params.glowW[1] *= scale;
    params.glowW[2] *= scale;
    params.radius *= scale;
    params.size[0] *= scale;
    params.size[1] *= scale;
    params.size[2] *= scale;
    fn_8002B7F8(pos, &params, 1);
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

