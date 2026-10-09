#include "menus/rep_0438.h"
#include "menus/rep_04B0.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"
#include "string.h"

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x26 - 0x1];
    /* 0x26 */ u8 _26;
} lbl_8034E978;

extern struct {
    /* 0x0000 */ u8 _0000[0x4380];
    /* 0x4380 */ u8 _4380[6][4][0x12];
    /* 0x4530 */ u8 _4530[0x46E0 - 0x4530];
    /* 0x46E0 */ s32 _46E0;
    /* 0x46E4 */ s32 _46E4;
    /* 0x46E8 */ s32 _46E8;
    /* 0x46EC */ s32 _46EC;
    /* 0x46F0 */ s32 _46F0;
    /* 0x46F4 */ s32 _46F4;
    /* 0x46F8 */ s8 _46F8[2];
    /* 0x46FA */ u8 _46FA[0x472A - 0x46FA];
    /* 0x472A */ u8 _472A;
    /* 0x472B */ u8 _472B[0x4755 - 0x472B];
    /* 0x4755 */ u8 _4755;
    /* 0x4756 */ u8 _4756[0x48AD - 0x4756];
    /* 0x48AD */ u8 _48AD;
    /* 0x48AE */ u8 _48AE;
    /* 0x48AF */ u8 _48AF;
    /* 0x48B0 */ u8 _48B0;
    /* 0x48B1 */ u8 _48B1;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[6];
    /* 0x07 */ u8 _07[0x59 - 0x7];
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
} lbl_803C66B0;

extern struct {
    /* 0x0 */ s32 _0;
    /* 0x4 */ s32 _4;
    /* 0x8 */ s32 _8;
} lbl_803C7898;

extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
} lbl_803C5EA4;

extern struct {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ s32 _0C;
    /* 0x10 */ u8 _10[4];
    /* 0x14 */ u8 _14[4];
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C[4];
    /* 0x20 */ u8 _20;
    /* 0x21 */ s8 _21;
    /* 0x22 */ s8 _22;
    /* 0x23 */ u8 _23[2];
    /* 0x25 */ u8 _25[0x2D - 0x25];
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E[0x4A - 0x2E];
    /* 0x4A */ u8 _4A;
} lbl_2_bss_100B8;

extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s32 _10[2];
} lbl_2_bss_F410;

extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u16 _4;
}* lbl_803CBBCC;

extern struct {
    /* 0x00 */ u8 _00[0xF4];
    /* 0xF4 */ u8 _F4;
} lbl_80361B20;

extern struct {
    /* 0x00 */ u8 _00[2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ u8 _14[2][9];
} lbl_803C6724;

extern struct {
    /* 0x0000 */ u8 _0000[0x40BB];
    /* 0x40BB */ u8 _40BB[9][6];
} starMissionCompletionTracker;

extern u8 lbl_800FE930[2][6];
extern u8 lbl_80108EC4[];

extern s8 lbl_2_bss_100B4;
extern u16 lbl_2_bss_AE0;

typedef struct CharEntry0438 {
    /* 0x00 */ u8 _00[0x1E];
    /* 0x1E */ u8 _1E[2];
    /* 0x20 */ u32 _20;
    /* 0x24 */ s16 CharID;
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
    /* 0x3B */ u8 _3B[0x36];
    /* 0x71 */ u8 _71;
    /* 0x72 */ u8 _72[2];
    /* 0x74 */ u16 _74[21];
    /* 0x9E */ u8 _9E[2];
} CharEntry0438; // size: 0xA0

typedef struct {
    /* 0x0 */ s8 _0;
    /* 0x1 */ s8 _1;
    /* 0x2 */ s8 _2;
    /* 0x3 */ s8 _3;
} Slot0438;

extern Slot0438 lbl_80354720[2][9];
extern CharEntry0438 inMemRoster[2][9];

static inline void copyChar0438(CharEntry0438* dst, CharEntry0438* src) {
    memcpy(dst->_00, src->_00, sizeof(dst->_00));
    dst->CharID = src->CharID;
    dst->_26 = src->_26;
    dst->_27 = src->_27;
    memcpy(dst->_28, src->_28, sizeof(dst->_28));
    memcpy(dst->_2A, src->_2A, sizeof(dst->_2A));
    dst->_2C = src->_2C;
    dst->_2D = src->_2D;
    dst->_2E = src->_2E;
    dst->_2F = src->_2F;
    dst->_30 = src->_30;
    dst->_31 = src->_31;
    dst->_32 = src->_32;
    dst->_33 = src->_33;
    dst->_34 = src->_34;
    memcpy(dst->_35, src->_35, sizeof(dst->_35));
    dst->_20 = src->_20;
    memcpy(dst->_37, src->_37, sizeof(dst->_37));
    memcpy(dst->_3B, src->_3B, sizeof(dst->_3B));
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

extern void fn_800AD038(s32 arg0);
extern void fn_800628D4(s32 charID);
extern void fn_8004EEF4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_800678CC(s32 arg0);

// .text:0x00012C34 size:0xA4
void fn_2_12C34(void) {
    u8 count;
    s32 i;
    s32 index;

    if (lbl_2_bss_100B8._4A) {
        return;
    }
    if (lbl_2_bss_100B8._20 == 1 || lbl_803C5EA4._5 == 0) {
        if (lbl_2_bss_AE0 == 60000) {
            lbl_2_bss_AE0 = 0;
        }
        lbl_2_bss_AE0++;
    }
    count = 12;
    index = 4;
    if (g_d_GameSettings.GameModeSelected == 5) {
        count = 6;
    }
    for (i = 0; i < count; i++) {
        index++;
        if (index == 21) {
            index = 5;
        }
    }
}

// .text:0x00012B60 size:0xD4
void fn_2_12B60(void) {
    s32 prev[2];
    s32 i;

    prev[0] = lbl_2_bss_F410._10[0];
    prev[1] = lbl_2_bss_F410._10[1];
    fn_2_15E80(0);
    if (g_d_GameSettings._10 == 1) {
        fn_2_15E80(1);
    }
    for (i = 0; i < 2; i++) {
        while (fn_2_15104(lbl_2_bss_F410._10[i], prev[i], i, 1) == 0 && lbl_2_bss_100B8._10[i] != 0) {
            prev[i] = lbl_2_bss_F410._10[i];
        }
    }
}

// .text:0x00012A70 size:0xF0
void fn_2_12A70(void) {
    if (lbl_2_bss_100B8._10[2]) {
        lbl_2_bss_100B8._10[2] = 0;
        fn_800628D4(lbl_8034E9A0._46E0);
    }
    if (lbl_2_bss_100B8._10[3]) {
        lbl_2_bss_100B8._10[3] = 0;
        fn_800628D4(lbl_8034E9A0._46E4);
    }
    if (lbl_2_bss_100B8._10[0] && lbl_2_bss_100B8._10[1]) {
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_2_bss_100B4 = 1;
        }
        lbl_803CBBCC->_4 = 4;
        if (g_d_GameSettings._10 == 0) {
            lbl_2_bss_100B8._10[1] = 0;
            lbl_2_bss_100B8._10[3] = 0;
        }
    }
}

// .text:0x000129D0 size:0xA0
void fn_2_129D0(void) {
    memset(lbl_2_bss_100B8._14, 0, lbl_2_bss_100B8._2D);
    memset(lbl_2_bss_100B8._1C, 0, lbl_2_bss_100B8._2D);
    memset(lbl_2_bss_100B8._23, -1, 2);
    lbl_2_bss_100B8._18 = 0;
    lbl_2_bss_100B8._19 = 0;
    lbl_2_bss_100B8._1A = 0;
    lbl_2_bss_100B8._1B = 0;
    lbl_2_bss_100B8._20 = 0;
    lbl_2_bss_100B8._21 = -1;
    lbl_2_bss_100B8._22 = -1;
    lbl_2_bss_100B8._0C = -1;
    lbl_2_bss_100B8._2D = 0;
}

// .text:0x000129AC size:0x24
void fn_2_129AC(void) {
    lbl_8034E9A0._46E8 = lbl_803C7898._4;
    lbl_8034E9A0._46EC = lbl_803C7898._8;
}

// .text:0x00012988 size:0x24
void fn_2_12988(void) {
    lbl_8034E9A0._46F0 = lbl_803C7898._4;
    lbl_8034E9A0._46F4 = lbl_803C7898._8;
}

static inline void setOrder0438(s32 captain, s32 count) {
    s32 j;

    for (j = 0; j < count; j++) {
        lbl_803C6724._02[0][j] = lbl_8034E9A0._4380[captain][0][j];
        lbl_803C6724._14[0][j] = j;
        starMissionCompletionTracker._40BB[j][0] = j;
    }
}

// .text:0x00012238 size:0x194
// 92.29%: the target tests 0 < 9 before the batting-order loop (li; cmpwi; bge),
// and its strength-reduced pointers sit in other registers.
void fn_2_12238(void) {
    s32 i;
    s32 captain;
    s32 id;

    id = lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[0]];
    for (i = 0; i < 6; i++) {
        if (lbl_80108EC4[i] == id) {
            captain = i;
            break;
        }
    }
    if (i == 6) {
        OSPanic("teamselect.c", 1113, " Captain Not Found ");
    }
    setOrder0438(captain, 9);
    fn_800678CC(0);
}

// .text:0x0001216C size:0xCC
void fn_2_1216C(void) {
    s8 ports[4];

    memset(ports, 2, 4);
    if (g_d_GameSettings._10 == 0) {
        ports[lbl_8034E9A0._46F8[0]] = 1;
        if (lbl_8034E9A0._46F8[0] == 0) {
            ports[1] = 2;
        } else {
            ports[0] = 2;
        }
    } else {
        ports[lbl_8034E9A0._46F8[1]] = 1;
        ports[lbl_8034E9A0._46F8[0]] = 1;
    }
    fn_8004EEF4(ports[0], ports[1], ports[2], ports[3], 1);
}

// .text:0x000120D0 size:0x9C
void fn_2_120D0(void) {
    lbl_8034E9A0._48AD = 1;
    lbl_8034E9A0._4755 = 3;
    lbl_803C66B0._00 = 0;
    lbl_803C66B0._5A = 0;
    lbl_803C66B0._59 = 0;
    lbl_8034E9A0._472A = 0xFF;
    lbl_8034E9A0._48AF = 1;
    lbl_8034E9A0._48B1 = 1;
    memset(lbl_803C66B0._01, 0, 6);
    lbl_8034E978._26 = 1;
    fn_800AD038(lbl_8034E9A0._46E8);
    g_d_GameSettings._10 = 0;
}

// .text:0x00011EA8 size:0x228
void fn_2_11EA8(void) {
    s32 i;
    s8 id;

    for (i = 0; i < 9; i++) {
        id = lbl_803C6724._02[0][i];
        copyChar0438(&inMemRoster[0][i], &((CharEntry0438(*)[9])&lbl_8034E9A0)[id / 9][id % 9]);
        lbl_80354720[0][i]._2 = i;
        lbl_80354720[0][i]._1 = i;
        lbl_80354720[0][i]._0 = i;
    }
}
