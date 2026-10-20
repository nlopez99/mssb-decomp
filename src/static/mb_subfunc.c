#include "static/mb_subfunc.h"
#include "static/static_8006C100.h"
#include "Dolphin/os.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct MbRosterEntry {
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
    /* 0x31 */ u8 attribute;
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
} MbRosterEntry; // size: 0xA0

typedef struct MbState {
    /* 0x0000 */ MbRosterEntry chars[2][9];
    /* 0x0B40 */ u8 _0B40[0x4380 - 0xB40];
    /* 0x4380 */ u8 _4380[12][0x48];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x46F8 - 0x46E8];
    /* 0x46F8 */ u8 ports[2];
    /* 0x46FA */ u8 _46FA[0x4709 - 0x46FA];
    /* 0x4709 */ s8 _4709[2];
    /* 0x470B */ u8 _470B[0x470D - 0x470B];
    /* 0x470D */ s8 _470D[2];
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

typedef struct MbTeams {
    /* 0x00 */ u8 _00[0x2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ u8 _14[2][9];
    /* 0x26 */ u8 _26[2][9];
    /* 0x38 */ u8 _38[0x5C - 0x38];
} MbTeams; // size: 0x5C

typedef struct MbStatGroup {
    /* 0x0 */ s32 a;
    /* 0x4 */ s16 b;
    /* 0x6 */ s16 c;
} MbStatGroup; // size: 0x8

typedef struct MbStats {
    /* 0x000 */ MbStatGroup head[5];
    /* 0x028 */ MbStatGroup rows[6][5];
    /* 0x118 */ MbStatGroup tail[5];
    /* 0x140 */ StatBlock slots[32];
    /* 0x400 */ u8 _400[0x454 - 0x400];
} MbStats; // size: 0x454

extern MbStats lbl_803616CC;
extern s32 lbl_800E88C4[6][5][3];
extern s32 lbl_800E8A2C[5][3];
extern s32 lbl_800E8A68[5][3];
extern u8 lbl_800E869C[32];

typedef struct MbSlot {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
} MbSlot; // size: 0x4

extern MbSlot lbl_80354720[2][9];

typedef struct MbMissionChar {
    /* 0x00 */ u8 _00[0x31];
    /* 0x31 */ u8 state;
    /* 0x32 */ u8 _32[2];
} MbMissionChar; // size: 0x34

typedef struct MbMissionSlot {
    /* 0x0 */ s16 charId;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
} MbMissionSlot; // size: 0x6

typedef struct MbMissions {
    /* 0x0000 */ MbMissionChar chars[54];
    /* 0x0AF8 */ u8 _0AF8[0x40B8 - 0xAF8];
    /* 0x40B8 */ MbMissionSlot slots[9];
    /* 0x40EE */ u8 _40EE[0x441D - 0x40EE];
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ s8 _441F;
    /* 0x4420 */ u8 _4420[0x4445 - 0x4420];
    /* 0x4445 */ u8 _4445;
} MbMissions;

extern MbMissions starMissionCompletionTracker;
extern MbState lbl_8034E9A0;
extern MbTeams lbl_803C6724;
extern MbRosterEntry inMemRoster[2][9];
extern MbGameOptions gameInitOptions;
extern MbSound lbl_800EF808;
extern MbStadiumState lbl_80361B20;
extern u8 lbl_802E4CE8[][0x50];

extern u8 lbl_800E88A4[][2];
extern u8 lbl_800E87B4[][0x10];
extern u8 lbl_8034E478[][0x50];
extern u16 lbl_803CBD24;

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

u8 lbl_80108DB8[33] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x18, 0x1B, 0x1C, 0x21, 0x25, 0x26, 0x27, 0x28, 0x29, 0x30, 0x11 };
u8 lbl_80108DDC[22] = { 0x16, 0x17, 0x19, 0x1A, 0x1D, 0x1E, 0x1F, 0x20, 0x22, 0x23, 0x24, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x31, 0x32, 0x33, 0x34, 0x35 };
s16 lbl_80108DF4[33] = { 0x1C4, 0x1C5, 0x1CA, 0x1CB, 0x1C6, 0x1C7, 0x1CC, 0x1DE, 0x1DF, 0x1CE, 0x1C8, 0x1C9, 0x1DB, 0x1D4, 0x1D6, 0x1D5, 0x1DD, 0x1CD, 0x1D0, 0x1CF, 0x1DC, 0x1D1, 0x1D2, 0x1E1, 0x1D3, 0x1E3, 0x1D7, 0x1D8, 0x1E2, 0x1D9, 0x1DA, 0x1E0, 0x1E5 };
s16 lbl_80108E38[69] = { 0x284, 0x285, 0x286, 0x287, 0x288, 0x289, 0x28A, 0x28B, 0x28C, 0x28D, 0x28E, 0x28F, 0x290, 0x291, 0x292, 0x293, 0x294, 0x295, 0x296, 0x297, 0x298, 0x299, 0x29A, 0x29B, 0x29C, 0x29D, 0x29E, 0x29F, 0x2A0, 0x2A1, 0x2A2, 0x2A3, 0x2A4, 0x2A5, 0x2A6, 0x2A7, 0x2A8, 0x2A9, 0x2AA, 0x2AB, 0x2AC, 0x2AD, 0x2AE, 0x2AF, 0x2B0, 0x2B1, 0x2B2, 0x2B3, 0x2B4, 0x2B5, 0x2B6, 0x2B7, 0x2B8, 0x2B9, 0x2BA, 0x2BB, 0x2BC, 0x2BD, 0x2BE, 0x2BF, 0x2C0, 0x2C1, 0x2C2, 0x2C3, 0x2C4, 0x2C5, 0x2C6, 0x2C7, 0x2C8 };
u8 lbl_80108EC4[12] = { 0x00, 0x04, 0x0A, 0x02, 0x06, 0x09, 0x01, 0x05, 0x0B, 0x03, 0x11, 0x13 };
u8 lbl_80108ED0[12] = { 0x00, 0x01, 0x04, 0x05, 0x06, 0x11, 0x0A, 0x0B, 0x02, 0x03, 0x09, 0x13 };
s16 lbl_80108EDC[9][5] = {
    { 0xC, 0x2A, -1, -1, -1 },
    { 0xD, 0x1D, 0x1E, 0x1F, 0x20 },
    { 0x14, 0x2B, -1, -1, -1 },
    { 0x10, 0x2C, 0x2D, 0x2E, 0x2F },
    { 0x15, 0x16, 0x17, -1, -1 },
    { 0x18, 0x19, 0x1A, -1, -1 },
    { 0x21, 0x22, 0x23, 0x24, -1 },
    { 0x30, 0x31, 0x32, 0x33, -1 },
    { 0x1B, 0x34, 0x35, -1, -1 },
};
static u16 lbl_80108F38[12][2][4] = {
    { { 0x1, 0x12, 0x15, 0x18 }, { 0x4, 0x6, 0x9, 0x2 } },
    { { 0x5, 0x3, 0xB, 0x8 }, { 0x9, 0xD, 0xE, 0x25 } },
    { { 0x5, 0xD, 0xF, 0x1C }, { 0x0, 0x7, 0x9, 0x13 } },
    { { 0x4, 0xF, 0x18, 0x27 }, { 0xA, 0x11, 0x26, 0x27 } },
    { { 0x11, 0x10, 0x7, 0x8 }, { 0xE, 0x25, 0x14, 0x29 } },
    { { 0x6, 0x10, 0xC, 0x28 }, { 0x0, 0x1, 0x4, 0xD } },
    { { 0xB, 0x21, 0x25, 0x26 }, { 0x9, 0x2, 0x13, 0x1B } },
    { { 0xA, 0x25, 0x21, 0x30 }, { 0x0, 0x1, 0xA, 0x1C } },
    { { 0x3, 0x27, 0x28, 0xC }, { 0x6, 0x9, 0x26, 0x12 } },
    { { 0x27, 0x6, 0x11, 0xE }, { 0x0, 0x11, 0x7, 0xF } },
    { { 0x13, 0x30, 0x1B, 0x1B }, { 0xA, 0xB, 0x1B, 0x26 } },
    { { 0x3, 0x28, 0x10, 0xE }, { 0x3, 0x27, 0x7, 0x8 } },
};
u8 lbl_80108FF8[50] = { 0x15, 0x16, 0x17, 0xFF, 0xFF, 0x18, 0x19, 0x1A, 0xFF, 0xFF, 0x0D, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0xFF, 0x0C, 0x2A, 0xFF, 0xFF, 0xFF, 0x14, 0x2B, 0xFF, 0xFF, 0xFF, 0x10, 0x2C, 0x2D, 0x2E, 0x2F, 0x0E, 0xFF, 0xFF, 0xFF, 0xFF, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0x29, 0xFF, 0xFF, 0xFF, 0xFF };
u8 lbl_8010902C[12] = { 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01, 0x03, 0x01, 0x02, 0x01, 0x01 };
u8 lbl_80109038[9] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x0A, 0x0B, 0x11 };
u32 lbl_80109044[4] = { 0x0, 0xB4, 0x8E98000, 0xB4 };
u8 lbl_80109054[2][4][5] = {
    {
        { 0x02, 0x05, 0x04, 0x03, 0x08 },
        { 0x03, 0x04, 0x05, 0x02, 0x06 },
        { 0x00, 0x01, 0x08, 0x06, 0x07 },
        { 0x01, 0x02, 0x00, 0x07, 0x04 },
    },
    {
        { 0x04, 0x03, 0x01, 0x02, 0x05 },
        { 0x01, 0x02, 0x04, 0x06, 0x08 },
        { 0x07, 0x06, 0x08, 0x05, 0x03 },
        { 0x03, 0x05, 0x07, 0x04, 0x06 },
    },
};

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
    s8 pool[54];
    u8 n;
    s32 i;
    s32 j;
    s32 k;
    s32 team;
    u8 color;
    s16 id;
    u8 r;
    MbRosterEntry* src;
    MbRosterEntry* dst;

    n = 0;
    memset(pool, -1, sizeof(pool));
    for (i = 0; i < 54; i++) {
        if ((s32)starMissionCompletionTracker.chars[i].state == 2) {
            if (fn_80067B40(0, i, 1)) {
                for (j = 0; j < 9; j++) {
                    if (i == lbl_80108EDC[j][0]) {
                        break;
                    }
                }
                if (j == 9) {
                    continue;
                }
            }
            pool[n++] = i;
        }
    }
    lbl_8034E9A0._46E0[1] = 0x13;
    if (starMissionCompletionTracker._4445 != 0) {
        for (i = 0; i < 12; i++) {
            if (starMissionCompletionTracker._441D == lbl_80108EC4[i]) {
                color = i;
                break;
            }
        }
        for (team = 0; team < 2; team++) {
            for (i = 0; i < 9; i++) {
                if (team == 0) {
                    id = lbl_8034E9A0._4380[color][i];
                } else {
                    id = lbl_8034E9A0._4380[11][i];
                }
                src = &lbl_8034E9A0.chars[(u8)(id / 9)][(u8)(id % 9)];
                dst = &inMemRoster[team][i];
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
                dst->attribute = src->attribute;
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
                lbl_803C6724._02[team][i] = id;
            }
        }
        fn_80067C48(0);
        fn_80067C48(1);
        unsure_FillRosterPositions(1);
        characterSelectScreen(1);
        for (i = 0; i < 9; i++) {
            starMissionCompletionTracker.slots[i].charId = inMemRoster[0][i].charId;
            starMissionCompletionTracker.slots[i]._2 = lbl_80354720[0][i]._1;
            starMissionCompletionTracker.slots[i]._3 = lbl_80354720[0][i]._2;
            starMissionCompletionTracker.slots[i]._4 = inMemRoster[0][i]._27 + inMemRoster[0][i]._26 * 2;
        }
    } else {
        for (team = 0; team < 2; team++) {
            for (i = 0; i < 9; i++) {
                if (team == 0) {
                    id = starMissionCompletionTracker.slots[i].charId;
                } else {
                    id = lbl_8034E9A0._4380[11][i];
                    if (id != 0x13 && n != 0) {
                        do {
                            r = randRange_FUN_80042bf0(0, n - 1);
                            id = pool[r];
                        } while (id == -1);
                        pool[r] = -1;
                        lbl_8034E9A0._4757[id] = 1;
                        for (j = 0; j < n - 1; j++) {
                            for (k = j + 1; k < n; k++) {
                                if (pool[j] == -1) {
                                    s8 tmp = pool[j];
                                    pool[j] = pool[k];
                                    pool[k] = tmp;
                                }
                            }
                        }
                        n--;
                    }
                }
                src = &lbl_8034E9A0.chars[(u8)(id / 9)][(u8)(id % 9)];
                dst = &inMemRoster[team][i];
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
                dst->attribute = src->attribute;
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
                if (team == 0) {
                    lbl_80354720[team][i]._0 = i;
                    lbl_80354720[team][i]._1 = starMissionCompletionTracker.slots[i]._2;
                    lbl_80354720[team][i]._2 = starMissionCompletionTracker.slots[i]._3;
                    inMemRoster[team][i]._26 = starMissionCompletionTracker.slots[i]._4 / 2;
                    inMemRoster[team][i]._27 = starMissionCompletionTracker.slots[i]._4 % 2;
                }
                lbl_803C6724._02[team][i] = id;
            }
            if (team != 0) {
                unsure_FillRosterPositions(1);
                characterSelectScreen(1);
            }
        }
        fn_80067C48(0);
        fn_80067C48(1);
    }
    fn_80066EAC(0);
    fn_80069854();
    fn_8006496C();
    fn_80069854();
    fn_800678CC(0);
    fn_800678CC(1);
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
u8 fn_80067B40(s32 arg0, u8 id, u8 value) {
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
void fn_800678CC(s32 team) {
    s8 color = -1;
    s32 captain;
    int i;
    u8 rank;

    if (g_d_GameSettings.GameModeSelected == 5) {
        if (team == 0) {
            captain = lbl_8034E9A0._46E0[team] = starMissionCompletionTracker._441D;
        } else {
            captain = lbl_8034E9A0._46E0[team] = starMissionCompletionTracker._441F;
        }
    } else {
        captain = lbl_8034E9A0._46E0[team];
    }
    for (i = 0; i < 12; i++) {
        if (captain == lbl_80108ED0[i]) {
            color = i;
            break;
        }
    }
    rank = fn_800675C4(team, captain);
    if (rank == 0) {
        rank = fn_80067264(team, captain);
        if (rank != 0) {
            lbl_8034E9A0._470D[team] = rank - 1 + color * 4;
        } else {
            lbl_8034E9A0._470D[team] = (color + 1) * 4 - 1;
        }
    } else {
        lbl_8034E9A0._470D[team] = rank - 1 + color * 4;
    }
}

static inline s32 findFamily(s32 id) {
    s32 row;
    s32 c;

    for (row = 0; row < 9; row++) {
        for (c = 0; c < 5; c++) {
            if (id == lbl_80108EDC[row][c]) {
                return row;
            }
        }
    }
    return -1;
}

// .text:0x800675C4 size:0x308
// The target keeps &found in r6 from the start and computes the 0x80108F38 row once;
// declaration orders change nothing
u8 fn_800675C4(s32 team, s32 captain) {
    s32 found[4];
    s32 color;
    s32 count;
    s32 n;
    s32 k;
    s32 i;
    s32 row;
    s32 c;
    u16 id;

    color = -1;
    found[0] = 0;
    found[1] = 0;
    found[2] = 0;
    found[3] = 0;
    count = 0;
    for (i = 0; i < 12; i++) {
        if (captain == lbl_80108ED0[i]) {
            color = i;
            break;
        }
    }
    for (n = 0; n < 2; n++) {
        for (k = 0; k < 4; k++) {
            id = lbl_80108F38[color][n][k];
            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._02[team][i] == id) {
                    found[k] = 1;
                    count++;
                }
            }
            lbl_80108F38[color][n][k] = id;
        }
        if (count == 4) {
            return n + 1;
        }
        for (k = 0; k < 4; k++) {
            if (found[k] != 1) {
                row = findFamily(lbl_80108F38[color][n][k]);
                if (row != -1) {
                    for (c = 1; c < 5; c++) {
                        for (i = 0; i < 9; i++) {
                            if (lbl_803C6724._02[team][i] == lbl_80108EDC[row][c]) {
                                count++;
                                found[k] = 1;
                                if (count == 4) {
                                    return n + 1;
                                }
                                goto next;
                            }
                        }
                    }
                }
            }
        next:;
        }
        found[0] = 0;
        found[1] = 0;
        found[2] = 0;
        found[3] = 0;
        count = 0;
    }
    return 0;
}

// .text:0x80067264 size:0x360
// The first loop interleaves its three lookups in the target and shares one zero register
// with the counts; this loads all three bytes first
u8 fn_80067264(s32 team, s32 captain) {
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
// Registers only: the target keeps the row pointer in r31 and the team base in r30 (swapped here);
// declaration orders and a row pointer local change nothing
void fn_80066EAC(u8 team) {
    s8 list[10];
    s32 i;
    s32 j;
    s32 k;
    s8 tmp;
    u8 chem;
    MbRosterEntry* entry;
    s16 id;

    for (i = 0; i < 9; i++) {
        entry = &inMemRoster[team][i];
        for (j = 0; j < 9; j++) {
            id = inMemRoster[team][j].charId;
            chem = entry->chemistry[id];
            if (chem < 90 || chem == 100) {
                list[j] = -1;
            } else {
                list[j] = id;
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

static inline void placeFielder(s8* fielders, s8 id) {
    s32 k;
    u8 r;
    u8* pos = lbl_80109054[0][lbl_8034E9A0.chars[(u8)(id / 9)][(u8)(id % 9)].attribute];

    for (k = 0; k < 5; k++, pos++) {
        if (fielders[*pos] == -1) {
            fielders[*pos] = id;
            break;
        }
    }
    if (k == 5) {
        do {
            r = randRange_FUN_80042bf0(0, 8);
        } while (fielders[r] != -1);
        fielders[r] = id;
    }
}

// .text:0x80065DEC size:0x10C0
void characterSelectScreen(u8 team) {
    s8 fielders[9];
    s8 captains[9];
    s8 others[9];
    u8 oldPos[9];
    s16 ids[9];
    s32 i;
    s32 j;
    s32 k;
    u8 n;
    u8 isCaptain;
    u8* pos;
    u8 r;
    s32 ri;
    s32 id;
    s32 rj;
    s8 tmp;
    MbRosterEntry* src;
    MbRosterEntry* dst;

    for (i = 0; i < 9; i++) {
        others[i] = -1;
        captains[i] = -1;
        fielders[i] = -1;
        ids[i] = inMemRoster[team][i].charId;
        oldPos[i] = lbl_803C6724._14[team][i];
    }
    fielders[lbl_80109054[0][inMemRoster[team][0].attribute][0]] = inMemRoster[team][0].charId;
    n = 0;
    for (i = 1; i < 9; i++) {
        for (k = 0; k < 12; k++) {
            if (lbl_80108EC4[k] == inMemRoster[team][i].charId) {
                captains[n++] = inMemRoster[team][i].charId;
            }
        }
    }
    if (captains[0] != -1) {
        if (captains[1] == -1) {
            placeFielder(fielders, captains[0]);
        } else {
            for (i = 0; i < 8; i++) {
                if (captains[i] == -1) {
                    break;
                }
                id = inMemRoster[team][captains[i]].charId;
                for (k = 0; k < 54; k++) {
                    if (lbl_8034E9A0._478D[team][k] == id) {
                        ri = k;
                        break;
                    }
                }
                for (j = i + 1; j < 9; j++) {
                    if (captains[j] == -1) {
                        break;
                    }
                    id = captains[j];
                    for (k = 0; k < 54; k++) {
                        if (lbl_8034E9A0._478D[team][k] == id) {
                            rj = k;
                            break;
                        }
                    }
                    if (ri > rj) {
                        tmp = captains[j];
                        captains[j] = captains[i];
                        captains[i] = tmp;
                    }
                }
            }
            for (i = 0; i < 9; i++) {
                if (captains[i] == -1) {
                    break;
                }
                placeFielder(fielders, captains[i]);
            }
        }
    }
    n = 0;
    for (i = 1; i < 9; i++) {
        isCaptain = 0;
        for (k = 0; k < 12; k++) {
            if (lbl_80108EC4[k] == inMemRoster[team][i].charId) {
                isCaptain = 1;
            }
        }
        if (isCaptain == 0) {
            others[n++] = inMemRoster[team][i].charId;
        }
    }
    for (i = 0; i < 8; i++) {
        if (others[i] == -1) {
            break;
        }
        id = others[i];
        for (k = 0; k < 54; k++) {
            if (lbl_8034E9A0._478D[team][k] == id) {
                ri = k;
                break;
            }
        }
        for (j = i + 1; j < 9; j++) {
            if (others[j] == -1) {
                break;
            }
            id = others[j];
            for (k = 0; k < 54; k++) {
                if (lbl_8034E9A0._478D[team][k] == id) {
                    rj = k;
                    break;
                }
            }
            if (ri > rj) {
                tmp = others[j];
                others[j] = others[i];
                others[i] = tmp;
            }
        }
    }
    for (i = 0; i < 9; i++) {
        if (others[i] == -1) {
            break;
        }
        pos = lbl_80109054[0][lbl_8034E9A0.chars[others[i] / 9][others[i] % 9].attribute];
        for (k = 0; k < 5; k++, pos++) {
            if (fielders[*pos] == -1) {
                fielders[*pos] = others[i];
                break;
            }
        }
        if (k == 5) {
            do {
                r = randRange_FUN_80042bf0(0, 8);
            } while (fielders[r] != -1);
            fielders[r] = others[i];
        }
    }
    for (i = 0; i < 9; i++) {
        src = &lbl_8034E9A0.chars[fielders[i] / 9][fielders[i] % 9];
        dst = &inMemRoster[team][i];
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
        dst->attribute = src->attribute;
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
        fn_80066EAC(team);
        lbl_80354720[team][i]._0 = i;
        lbl_80354720[team][i]._1 = i;
        for (k = 0; k < 9; k++) {
            if (fielders[i] == ids[k] && ids[k] != -1) {
                ids[k] = -1;
                break;
            }
        }
        lbl_80354720[team][i]._2 = oldPos[k];
    }
}

static inline void placeBatter(s8* order, u8 team, s8 id) {
    s32 k;
    s32 m;
    u8 r;
    u8 ok;
    u8* pos = lbl_80109054[1][lbl_8034E9A0.chars[(u8)(id / 9)][(u8)(id % 9)].attribute];

    for (k = 0; k < 5; k++, pos++) {
        for (m = 0; m < 9; m++) {
            if (order[m] == *pos) {
                break;
            }
        }
        if (m == 9) {
            for (m = 0; m < 9; m++) {
                if (id == lbl_803C6724._02[team][m] && order[m] == -1) {
                    order[m] = *pos;
                    return;
                }
            }
        }
    }
    if (k == 5) {
        do {
            r = randRange_FUN_80042bf0(0, 8);
            for (m = 0; m < 9; m++) {
                if (order[m] == r) {
                    ok = 0;
                    break;
                }
            }
            if (m == 9) {
                ok = 1;
            }
        } while (ok == 0);
        for (m = 0; m < 9; m++) {
            if (id == lbl_803C6724._02[team][m]) {
                order[m] = r;
                return;
            }
        }
    }
}

// .text:0x80064A04 size:0x13E8
void unsure_FillRosterPositions(u8 team) {
    s8 order[9];
    s8 captains[9];
    s8 others[9];
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    u8 n;
    u8 isCaptain;
    s32 cap;
    s32 ri;
    s32 rj;
    s32 id;
    s8 tmp;
    u8* pos;
    u8 r;
    u8 ok;

    for (i = 0; i < 9; i++) {
        others[i] = -1;
        captains[i] = -1;
        order[i] = -1;
    }
    cap = lbl_8034E9A0._46E0[team];
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._02[team][i] == cap) {
            order[i] = 0;
        }
    }
    n = 0;
    for (i = 0; i < 9; i++) {
        for (k = 0; k < 12; k++) {
            if (lbl_803C6724._02[team][i] == lbl_80108EC4[k] && cap != lbl_803C6724._02[team][i]) {
                captains[n++] = lbl_803C6724._02[team][i];
            }
        }
    }
    if (captains[0] != -1) {
        if (captains[1] == -1) {
            placeBatter(order, team, captains[0]);
        } else {
            for (i = 0; i < 8; i++) {
                if (captains[i] == -1) {
                    break;
                }
                id = lbl_803C6724._02[team][i];
                for (k = 0; k < 54; k++) {
                    if (lbl_8034E9A0._478D[team][k] == id) {
                        ri = k;
                        break;
                    }
                }
                for (j = i + 1; j < 9; j++) {
                    if (captains[j] == -1) {
                        break;
                    }
                    id = captains[j];
                    for (k = 0; k < 54; k++) {
                        if (lbl_8034E9A0._478D[team][k] == id) {
                            rj = k;
                            break;
                        }
                    }
                    if (ri > rj) {
                        tmp = captains[j];
                        captains[j] = captains[i];
                        captains[i] = tmp;
                    }
                }
            }
            for (i = 0; i < 9; i++) {
                if (captains[i] == -1) {
                    break;
                }
                placeBatter(order, team, captains[i]);
            }
        }
    }
    n = 0;
    for (i = 0; i < 9; i++) {
        isCaptain = 0;
        for (k = 0; k < 12; k++) {
            if (lbl_803C6724._02[team][i] == lbl_80108EC4[k]) {
                isCaptain = 1;
            }
        }
        if (isCaptain == 0) {
            others[n++] = lbl_803C6724._02[team][i];
        }
    }
    for (i = 0; i < 8; i++) {
        if (others[i] == -1) {
            break;
        }
        id = others[i];
        for (k = 0; k < 54; k++) {
            if (lbl_8034E9A0._478D[team][k] == id) {
                ri = k;
                break;
            }
        }
        for (j = i + 1; j < 9; j++) {
            if (others[j] == -1) {
                break;
            }
            id = others[j];
            for (k = 0; k < 54; k++) {
                if (lbl_8034E9A0._478D[team][k] == id) {
                    rj = k;
                    break;
                }
            }
            if (ri > rj) {
                tmp = others[j];
                others[j] = others[i];
                others[i] = tmp;
            }
        }
    }
    for (i = 0; i < 9; i++) {
        if (others[i] == -1) {
            break;
        }
        pos = lbl_80109054[1][lbl_8034E9A0.chars[others[i] / 9][others[i] % 9].attribute];
        for (k = 0; k < 5; k++, pos++) {
            for (m = 0; m < 9; m++) {
                if (order[m] == *pos) {
                    break;
                }
            }
            if (m == 9) {
                for (m = 0; m < 9; m++) {
                    if (others[i] == lbl_803C6724._02[team][m] && order[m] == -1) {
                        order[m] = *pos;
                        goto next;
                    }
                }
            }
        }
        if (k != 5) {
            continue;
        }
        do {
            r = randRange_FUN_80042bf0(0, 8);
            ok = 1;
            for (m = 0; m < 9; m++) {
                if (order[m] == r) {
                    ok = 0;
                    break;
                }
            }
        } while (ok == 0);
        for (m = 0; m < 9; m++) {
            if (others[i] == lbl_803C6724._02[team][m] && order[m] == -1) {
                order[m] = r;
                break;
            }
        }
    next:;
    }
    for (i = 0; i < 9; i++) {
        lbl_803C6724._14[team][i] = order[i];
    }
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
