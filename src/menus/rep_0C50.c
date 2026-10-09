#include "menus/rep_0C50.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "musyx/musyx.h"

typedef struct UnkTask0C50 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
} UnkTask0C50;

typedef struct {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ s32 _54;
    /* 0x58 */ s32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[0x68 - 0x66];
    /* 0x68 */ u8 _68;
} UnkSprite0C50;

typedef struct {
    /* 0x00 */ UnkSprite0C50* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef0C50; // size: 0x8

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc0C50; // size: 0x20

extern UnkSpriteRef0C50 lbl_80371C30[];
extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x7];
    /* 0x07 */ u8 _07;
    /* 0x08 */ u8 _08[0xD - 0x8];
    /* 0x0D */ u8 _0D[0x55 - 0xD];
    /* 0x55 */ u8 _55[4];
    /* 0x59 */ u8 _59[4];
    /* 0x5D */ u8 _5D[0x64 - 0x5D];
} lbl_803C66B0;

// Main-DOL .sbss object that symbols.txt lumps into lbl_803CBBC2 (+0x2)
extern struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
} lbl_803CBBC4;

// Main-DOL .sbss object that symbols.txt lumped into lbl_803CBCD0 (+0x8)
extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
} lbl_803CBCD8;

extern struct {
    /* 0x00 */ u8 _00[2];
    /* 0x02 */ s8 _02[2][9];
    /* 0x14 */ s8 _14[2][9];
    /* 0x26 */ u8 _26[2][9];
    /* 0x38 */ s8 _38[2][9];
    /* 0x4A */ s8 _4A[2][9];
} lbl_803C6724;

extern struct {
    /* 0x00 */ u8 _00[6][9];
    /* 0x36 */ u8 _36[0xF4 - 0x36];
    /* 0xF4 */ u8 _F4;
} lbl_80361B20;

typedef struct {
    /* 0x00 */ u32 _00;
    /* 0x04 */ u8 _04[0x7 - 0x4];
    /* 0x07 */ u8 _07;
    /* 0x08 */ u8 _08[0xD - 0x8];
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F[0x14 - 0xF];
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B[0xA0 - 0x1B];
} UnkRosterEntry0C50; // size: 0xA0

extern struct {
    /* 0x0000 */ u8 _0000[0x20];
    /* 0x0020 */ UnkRosterEntry0C50 _0020[2][9];
    /* 0x0B60 */ u8 _0B60[0x46E0 - 0xB60];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x46F8 - 0x46E8];
    /* 0x46F8 */ s8 _46F8[2];
    /* 0x46FA */ u8 _46FA[0x470D - 0x46FA];
    /* 0x470D */ u8 _470D[2];
    /* 0x470F */ u8 _470F[0x472A - 0x470F];
    /* 0x472A */ u8 _472A;
    /* 0x472B */ u8 _472B;
    /* 0x472C */ u16 _472C;
    /* 0x472E */ u16 _472E[2][3];
    /* 0x473A */ u8 _473A[0x4748 - 0x473A];
    /* 0x4748 */ UnkTask0C50* _4748;
    /* 0x474C */ UnkTask0C50* _474C;
    /* 0x4750 */ u8 _4750;
    /* 0x4751 */ u8 _4751;
    /* 0x4752 */ u8 _4752;
    /* 0x4753 */ u8 _4753[0x4760 - 0x4753];
    /* 0x4760 */ u16 _4760;
    /* 0x4762 */ u8 _4762[0x48AF - 0x4762];
    /* 0x48AF */ u8 _48AF;
    /* 0x48B0 */ u8 _48B0;
    /* 0x48B1 */ u8 _48B1;
    /* 0x48B2 */ u8 _48B2;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0x5];
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06[0x11 - 0x6];
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12[0x36 - 0x12];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
} lbl_803C5EA4;

extern UnkSpriteDesc0C50 lbl_2_data_2AADC[];
extern UnkSpriteDesc0C50 lbl_2_data_2B4DC[];
extern UnkSpriteDesc0C50 lbl_2_data_2B59C[];

extern u8 lbl_800FE930[2][6];

s32 lbl_2_bss_A840;
s32 lbl_2_bss_A844[0x37C / 4];
extern struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ u8 _08[0x10 - 0x8];
    /* 0x10 */ s32 _10[2];
    /* 0x18 */ u8 _18[0x20 - 0x18];
    /* 0x20 */ s32 _20[2];
    /* 0x28 */ u8 _28[0x4C - 0x28];
    /* 0x4C */ s32 _4C;
} lbl_2_bss_F410;
extern struct {
    /* 0x00 */ s32 _00[4];
    /* 0x10 */ u8 _10[0x20 - 0x10];
    /* 0x20 */ s32 _20[2];
    /* 0x28 */ u8 _28[0x37 - 0x28];
    /* 0x37 */ u8 _37[2];
    /* 0x39 */ u8 _39[0x3F - 0x39];
    /* 0x3F */ u8 _3F;
    /* 0x40 */ u8 _40;
    /* 0x41 */ u8 _41[2];
    /* 0x43 */ u8 _43[2];
    /* 0x45 */ u8 _45[2];
    /* 0x47 */ u8 _47[2];
    /* 0x49 */ u8 _49[2];
    /* 0x4B */ u8 _4B[2];
    /* 0x4D */ u8 _4D[2];
    /* 0x4F */ u8 _4F;
    /* 0x50 */ u8 _50[2];
    /* 0x52 */ u8 _52[2];
    /* 0x54 */ u8 _54[2];
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[0x59 - 0x57];
    /* 0x59 */ u8 _59[0x5F - 0x59];
    /* 0x5F */ u8 _5F[2];
    /* 0x61 */ s8 _61[2];
    /* 0x63 */ u8 _63[2];
    /* 0x65 */ u8 _65[2];
} lbl_2_bss_F468;
extern UnkSpriteDesc0C50 lbl_2_data_2D33C[];
extern UnkSpriteDesc0C50 lbl_2_data_2AF4C[];
extern u8 lbl_2_data_2B3A4[];

extern u8 lbl_800FE5D4[];
extern u8 lbl_80108EC4[];
extern u8 lbl_803CB8D0[];
extern u8 lbl_2_data_2AF08[];

extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u8 _10;
} lbl_8037169C;

extern struct {
    /* 0x0000 */ u8 _0000[0x15F1];
    /* 0x15F1 */ s8 _15F1[0x43C2 - 0x15F1];
    /* 0x43C2 */ s8 _43C2[0x441D - 0x43C2];
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ s8 _441F;
} starMissionCompletionTracker;
extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u8 _10;
} lbl_2_bss_100B8;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x8 - 0x1];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
} lbl_8034E978;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} lbl_800FEF70[]; // size: 0x10

extern struct {
    /* 0x0 */ u8 _0[0x2];
    /* 0x2 */ u16 _2;
    /* 0x4 */ u8 _4[0x6 - 0x4];
    /* 0x6 */ u16 _6;
}* lbl_803CBBCC;

extern s32 fn_80042DA8(UnkTask0C50* task, s32 index, s32 value);
extern void fn_80062674(s32 index);
extern void fn_800626EC(s32 index);
extern void fn_80034E20(UnkTask0C50* task, UnkSpriteDesc0C50* desc);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800363D8(UnkTask0C50* task, s32 id, s32 part, s32 kind, s32 value);
extern void fn_800625A4(s32 index, s32 value);
extern s32 fn_80036214(UnkTask0C50* task, s32 id, s32 arg2, s32 arg3);
extern void fn_80034CEC(UnkTask0C50* task);
extern void fn_800B0A14_removeQueue(void);
extern void fn_8004E2EC(void);
extern void fn_8004F964(void);
extern void fn_80053FE8(void);
extern void fn_80051D00(void);
extern void changeScene(u8, s16);
extern s32 fn_2_8794(s32 flag, s32 value);
extern void fn_2_CCE0(u8 index);
extern void fn_2_16A74(s32 port, s32 flag);
extern void fn_2_102C8(u8 index);
extern s8 translateStarPitchHitIndex(u8 index);
extern s16 translateStarPitch(u8 index);
extern s16 translateStarSwing(u8 index);
extern s32 fn_80064918(s16 id);
extern u8 lbl_800EFBA4[0x10];
extern u8 fn_80067B40(u8 team, u8 charID, s32 arg2);
extern u8 lbl_80108ED0[0xC];

static inline BOOL isAnimDone(UnkTask0C50* task, s32 index, s32 value) {
    if (fn_80042DA8(task, index, value)) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x00082DE8 size:0x70
void fn_2_82DE8(void) {
    lbl_8034E9A0._4748 = lbl_803CC1B8;
    lbl_8034E9A0._48AF = 0;
    lbl_803C5EA4._37 = 0;
    lbl_803C5EA4._38 = 0;
    fn_80034E20(lbl_803CC1B8, lbl_2_data_2B4DC);
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_82CF0;
}

// .text:0x00082CF0 size:0xF8
void fn_2_82CF0(void) {
    UnkTask0C50* task = lbl_8034E9A0._4748;

    if (lbl_803C5EA4._36) {
        lbl_80371C30[task->_14]._00->_5C = 0;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x280000;
        lbl_80371C30[task->_14 + 2]._00->_64 = lbl_803C5EA4._38 + 0x123;
        lbl_80371C30[task->_14 + 3]._00->_64 = lbl_803C5EA4._37 + 0x123;
        lbl_80371C30[task->_14]._00->_68 = 1;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_803C5EA4._36 = 0;
    }
    if (lbl_8034E9A0._48AF) {
        lbl_8034E9A0._48AF = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0008279C size:0x554
// 99.55%: registers only: flag and the _46F8 load in the first loop, the second
// starMissionCompletionTracker read, and the add operands of the unrolled clearing loop.
void fn_2_8279C(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s8 off;
    s32 value;
    s32 a;
    u8 c;
    s32 i;
    int j;

    lbl_8034E9A0._474C = task;
    fn_80034E20(task, lbl_2_data_2B59C);
    for (i = 0; i < 2; i++) {
        if (g_d_GameSettings._10 == 0 && i != 0) {
            if (g_d_GameSettings._10 == 0) {
                if (lbl_8034E9A0._46F8[0] == 0) {
                    off = 1;
                } else {
                    off = 0;
                }
            }
            lbl_80371C30[0x7A + task->_14 + i]._00->_5C = off << 16;
            lbl_80371C30[0x18 + task->_14 + i]._00->_5C = (off + 4) << 16;
        } else {
            BOOL flag = FALSE;

            lbl_80371C30[0x7A + task->_14 + i]._00->_5C = lbl_8034E9A0._46F8[i] << 16;
            if (g_d_GameSettings._10 == 0 && i != 0) {
                flag = TRUE;
            }
            if (flag) {
                if (lbl_8034E9A0._46F8[i] == -1) {
                    value = (i != 0) + 4;
                } else {
                    value = lbl_8034E9A0._46F8[i] + 4;
                }
            } else {
                value = lbl_8034E9A0._46F8[i];
            }
            lbl_80371C30[0x18 + task->_14 + i]._00->_5C = value << 16;
        }
        lbl_80371C30[0x1A + task->_14 + i]._00->_54 &= ~2;
        lbl_80371C30[0xB2 + task->_14 + i]._00->_54 &= ~2;
    }
    if (g_d_GameSettings.GameModeSelected == 5) {
        lbl_80371C30[task->_14 + 0x98]._00->_54 &= ~2;
        a = (s16)starMissionCompletionTracker._441D;
        c = lbl_8034E9A0._0020[a / 9][a % 9]._14;
        fn_800363D8(task, 0x89, 1, 3, lbl_2_data_2B3A4[c]);
        fn_800363D8(task, 0x8B, 1, 3, lbl_2_data_2B3A4[c]);
        a = starMissionCompletionTracker._441F;
        c = lbl_8034E9A0._0020[a / 9][a % 9]._14;
        fn_800363D8(task, 0x8A, 1, 3, lbl_2_data_2B3A4[c]);
        fn_800363D8(task, 0x8C, 1, 3, lbl_2_data_2B3A4[c]);
    }
    for (j = 0; j < 10; j++) {
        lbl_80371C30[0x6E + task->_14 + j]._00->_5C = 0;
        lbl_80371C30[0x6E + task->_14 + j]._00->_68 = 0;
    }
    lbl_80371C30[task->_14 + 0x1C]._00->_54 &= ~2;
    lbl_80371C30[task->_14 + 0x1D]._00->_54 &= ~2;
    lbl_80371C30[task->_14 + 0x1E]._00->_54 &= ~2;
    lbl_80371C30[task->_14 + 0x1F]._00->_54 &= ~2;
    lbl_80371C30[task->_14 + 0x84]._00->_54 &= ~2;
    lbl_80371C30[task->_14 + 0xAE]._00->_54 &= ~2;
    lbl_80371C30[task->_14 + 0xAF]._00->_54 &= ~2;
    lbl_8034E9A0._48B2 = 0;
    lbl_8034E9A0._48B1 = 0;
    lbl_8034E9A0._4760 = 0;
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_81628;
}

// .text:0x00081628 size:0x1174
// 99.75%: registers only: the inlined fn_2_80E0C (case 1) rotates i, n and expected, as
// in that function, and sets expected before the second call's arguments.
void fn_2_81628(void) {
    UnkTask0C50* task = lbl_8034E9A0._474C;
    s32 i;

    if (lbl_8034E9A0._48B2) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
    if (lbl_803C66B0._00[0] == 1) {
        for (i = 0; i < 2; i++) {
            switch (lbl_803C66B0._5D[i]) {
            case 1:
                fn_2_80F5C(task, i);
                fn_2_80E0C(task, i);
                break;
            case 2:
                fn_2_80C2C(task, i);
                fn_2_80B5C(task, i);
                break;
            case 3:
                fn_2_808D8(task, i);
                fn_2_8082C(task, i);
                break;
            case 4:
                fn_2_805DC(task, i);
                break;
            case 5:
                fn_2_80500(task, i);
                break;
            case 6:
                fn_2_802EC(task);
                break;
            case 7:
                fn_2_800B0(task, i);
                break;
            case 8:
                fn_2_7FAFC(task, i);
                break;
            }
            fn_2_776A0(task, i);
            if (i != 0 && (lbl_80371C30[task->_14 + 6]._00->_5C >> 16) == 60) {
                lbl_80371C30[task->_14 + 7]._00->_68 = 1;
                lbl_80371C30[task->_14 + 9]._00->_68 = 1;
            }
        }
    } else if (lbl_803C66B0._00[0] == 2) {
        for (i = 0; i < 2; i++) {
            switch (lbl_803C66B0._5D[i]) {
            case 9:
                fn_2_7BFF8(task, i);
                break;
            case 10:
                fn_2_7AE3C(task, i);
                fn_2_7AC64(task, i);
                break;
            case 11:
                fn_2_7A9D8(task, i);
                fn_2_7A748(task, i);
                break;
            case 14:
                fn_2_7DAB8(task, i);
                fn_2_7D85C(task, i);
                break;
            case 15:
                fn_2_7F8BC(task, i);
                fn_2_7F714(task, i);
                break;
            case 16:
                fn_2_7F2BC(task, i);
                fn_2_7F030(task, i);
                break;
            case 12:
                fn_2_7EF68(task, i);
                break;
            case 13:
                fn_2_7EE7C(task, i);
                break;
            case 17:
                fn_2_7E974(task, i);
                fn_2_7E860(task, i);
                break;
            case 18:
                fn_2_7E380(task, i);
                fn_2_7E194(task, i);
                break;
            case 19:
                fn_2_7A5B8(task, i);
                fn_2_7A460(task, i);
                break;
            case 20:
                fn_2_7A194(task, i);
                fn_2_79FAC(task, i);
                break;
            case 21:
                fn_2_79CF8(task, i);
                fn_2_79B24(task, i);
                break;
            case 22:
                fn_2_79930(task, i);
                fn_2_79764(task, i);
                break;
            case 23:
                fn_2_79688(task, i);
                fn_2_79634(task, i);
                break;
            case 24:
                fn_2_79394(task, i);
                break;
            case 25:
                fn_2_7912C(task, i);
                break;
            case 26:
                fn_2_78F78(task, i);
                break;
            case 27:
                fn_2_78AC0(task, i);
                break;
            case 28:
                fn_2_7836C(task, i);
                break;
            case 29:
                fn_2_7805C(task, i);
                break;
            }
            fn_2_776A0(task, i);
        }
        if (i != 0 && (lbl_80371C30[task->_14 + 6]._00->_5C >> 16) == 60) {
            lbl_80371C30[task->_14 + 7]._00->_68 = 1;
            lbl_80371C30[task->_14 + 9]._00->_68 = 1;
        }
    }
    if (lbl_8034E9A0._48B1) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00080F5C size:0x6CC
void fn_2_80F5C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + index]._00->_64 = 71;
        lbl_80371C30[2 + task->_14 + index]._00->_64 = 71;
        lbl_80371C30[4 + task->_14 + index]._00->_64 = 80;
        lbl_80371C30[task->_14 + index]._00->_5C = 0;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[task->_14 + index]._00->_68 = 1;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[4 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[4 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[task->_14 + 6]._00->_68 = 1;
        lbl_80371C30[task->_14 + 8]._00->_68 = 1;
        lbl_80371C30[0x12 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xC + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0x99 + task->_14 + index]._00->_64 = 121;
        if (index != 0 && lbl_2_bss_100B8._10 == 0 && g_d_GameSettings._10 == 0) {
            lbl_80371C30[0x80 + task->_14 + index]._00->_54 &= ~2;
            lbl_80371C30[0x7A + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0x97 + task->_14 + index]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x84]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x84]._00->_68 = 1;
        } else {
            if (g_d_GameSettings.GameModeSelected == 5) {
                lbl_80371C30[task->_14 + 0x84]._00->_54 &= ~2;
                lbl_80371C30[task->_14 + 0x98]._00->_54 &= ~2;
                lbl_80371C30[task->_14 + 0xAD]._00->_54 &= ~2;
            } else if (index != 0 && lbl_803C5EA4._05 != 0) {
                lbl_80371C30[task->_14 + index]._00->_64 = 71;
                lbl_80371C30[2 + task->_14 + index]._00->_64 = 71;
                lbl_80371C30[4 + task->_14 + index]._00->_64 = 80;
                lbl_80371C30[task->_14 + index]._00->_5C = 0x140000;
                lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x140000;
                lbl_80371C30[task->_14 + index]._00->_68 = 1;
                lbl_80371C30[2 + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[4 + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[task->_14 + 0x84]._00->_54 &= ~2;
                lbl_80371C30[0x97 + task->_14 + index]._00->_54 |= 2;
                lbl_80371C30[0x97 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x7A + task->_14 + index]._00->_5C = lbl_8034E9A0._46F8[1] << 16;
                lbl_80371C30[task->_14 + 0x19]._00->_5C = lbl_8034E9A0._46F8[1] << 16;
                lbl_80371C30[0x1A + task->_14 + index]._00->_54 |= 2;
                lbl_80371C30[0x1A + task->_14 + index]._00->_68 = 1;
                if (lbl_803C66B0._5D[0] == 4 && lbl_803C66B0._0D[0] == 1) {
                    fn_80062674(0);
                    lbl_803C66B0._0D[0] = 2;
                }
            }
            fn_2_7630C(task, index);
            lbl_80371C30[0x80 + task->_14 + index]._00->_54 |= 2;
            lbl_80371C30[0x80 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x80 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x85 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x87 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x85 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x87 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x8B + task->_14 + index]._00->_5C = 0x50000;
            lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x8B + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x78 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x78 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x7C + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x7C + task->_14 + index]._00->_68 = 1;
            fn_2_74F40(task, index);
        }
        lbl_80371C30[0xAC + task->_14 + index]._00->_54 &= ~2;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00080E0C size:0x150
// 98.76%: task and index sit in r28/r29 in the target and r27/r28 in the base, with expected
// in r27 against r29.
void fn_2_80E0C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index, 20);
        s32 expected = 2;

        n += isAnimDone(task, index + 2, 20);
        if (index == 0 || lbl_2_bss_100B8._10 != 0 || g_d_GameSettings._10 != 0) {
            n += isAnimDone(task, index + 0x85, 10);
            n += isAnimDone(task, index + 0x87, 10);
            n += isAnimDone(task, index + 0x89, 5);
            expected = 6;
            n += isAnimDone(task, index + 0x8B, 10);
        }
        if (n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00080C2C size:0x1E0
void fn_2_80C2C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (lbl_803C66B0._55[index]) {
            fn_80062674(index);
            lbl_803C66B0._5D[index] = 2;
        }
        lbl_80371C30[task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + index]._00->_68 = 4;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[4 + task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[4 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x80 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x78 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x7C + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xAC + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[task->_14 + 0x84]._00->_54 &= ~2;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00080B5C size:0xD0
void fn_2_80B5C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index, 0);

        n += isAnimDone(task, index + 2, 0);
        n += isAnimDone(task, index + 0x89, 10);
        if (n == 3) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x000808D8 size:0x284
// 87.04%: the inlined fn_2_760CC is scheduled differently: the target forms &lbl_2_bss_F410
// before the branch and saves r25. Writing the body out in place scores lower (85.43%).
void fn_2_808D8(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (g_d_GameSettings.GameModeSelected != 5) {
            fn_2_7630C(task, index);
        } else {
            fn_2_760CC(task);
        }
        fn_2_74F40(task, index);
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0008082C size:0xAC
void fn_2_8082C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index + 0x89, 5);

        n += isAnimDone(task, index + 0x8B, 10);
        if (n == 2) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x000805DC size:0x250
// 99.93%: the first isAnimDone result reuses task's r29 in the target and gets r26 in the base.
void fn_2_805DC(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        u8 off;

        lbl_80371C30[task->_14 + 0x81]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x84]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x84]._00->_68 = 1;
        lbl_80371C30[task->_14 + 0x98]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x86]._00->_5C = 0xA0000;
        lbl_80371C30[task->_14 + 0x86]._00->_68 = 4;
        lbl_80371C30[task->_14 + 0x8A]._00->_5C = 0x50000;
        lbl_80371C30[task->_14 + 0x8A]._00->_68 = 4;
        lbl_80371C30[task->_14 + 0x79]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + 0x79]._00->_68 = 4;
        lbl_80371C30[task->_14 + 0x7D]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + 0x7D]._00->_68 = 4;
        off = lbl_8034E9A0._46F8[0] == 0;
        lbl_80371C30[task->_14 + 0x7B]._00->_5C = off << 16;
        lbl_80371C30[task->_14 + 0x19]._00->_5C = (off + 4) << 16;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n = isAnimDone(task, 0x86, 0);

        n += isAnimDone(task, 0x8A, 0);
        if (n == 2) {
            if (g_d_GameSettings._10 == 1 && lbl_2_bss_100B8._10 == 0) {
                fn_2_16A74(1, 0);
            }
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
            g_d_GameSettings._10 = 0;
        }
    }
}

// .text:0x00080500 size:0xDC
void fn_2_80500(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        u8 off = lbl_8034E9A0._46F8[0] == 0;

        lbl_80371C30[task->_14 + 0x7B]._00->_5C = off << 16;
        lbl_80371C30[task->_14 + 0x19]._00->_5C = (off + 4) << 16;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        fn_80062674(index);
        lbl_803C66B0._0D[index] = 2;
        g_d_GameSettings._10 = 0;
    }
}

// .text:0x000802EC size:0x214
void fn_2_802EC(UnkTask0C50* task) {
    if (lbl_803C66B0._0D[1] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + 0x81]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x81]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x81]._00->_68 = 1;
        lbl_80371C30[task->_14 + 0x84]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x84]._00->_68 = 0;
        lbl_80371C30[task->_14 + 0x7D]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x7D]._00->_68 = 1;
        lbl_80371C30[task->_14 + 0x98]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x86]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x86]._00->_68 = 1;
        lbl_80371C30[task->_14 + 0x8A]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x8A]._00->_68 = 1;
        fn_2_7630C(task, 1);
        fn_2_74F40(task, 1);
        fn_800626EC(1);
        lbl_803C66B0._0D[1] = 1;
    }
    if (lbl_803C66B0._0D[1] == 1) {
        s32 n = isAnimDone(task, 0x81, 20);

        n += isAnimDone(task, 0x7D, 20);
        n += isAnimDone(task, 0x86, 10);
        n += isAnimDone(task, 0x8A, 5);
        if (n == 4) {
            fn_80062674(1);
            lbl_803C66B0._0D[1] = 2;
        }
    }
}

// .text:0x000800B0 size:0x23C
void fn_2_800B0(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + index]._00->_68 = 1;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x80 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x80 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x78 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x78 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x7C + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x7C + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x97 + task->_14 + index]._00->_64 = 0x77;
        lbl_80371C30[0x97 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x97 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xB0 + task->_14 + index]._00->_54 &= ~2;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n = isAnimDone(task, index, 30);

        n += isAnimDone(task, index + 2, 30);
        if (n == 2) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007FAFC size:0x5B4
// 99.97%: the first isAnimDone result lands in r28 and n in r27 in the target; the base
// keeps both in r27.
void fn_2_7FAFC(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s32 a;
        u8 d;
        s32 b;
        u8 c;

        lbl_80371C30[task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[task->_14 + index]._00->_68 = 4;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[4 + task->_14 + index]._00->_64 = 0x50;
        lbl_80371C30[4 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[4 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x85 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x85 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x82 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0x7A + task->_14 + index]._00->_54 |= 2;
        if (g_d_GameSettings._10 == 0 && index != 0) {
            if (lbl_8034E9A0._46F8[0] == 0) {
                lbl_80371C30[0x7A + task->_14 + index]._00->_5C = 0x10000;
            } else {
                lbl_80371C30[0x7A + task->_14 + index]._00->_5C = 0;
            }
        } else {
            lbl_80371C30[0x7A + task->_14 + index]._00->_5C = lbl_8034E9A0._46F8[index] << 16;
        }
        if (g_d_GameSettings.GameModeSelected != 5) {
            a = lbl_800FE5D4[lbl_2_bss_F410._10[index]];
            b = lbl_800FE5D4[lbl_803C6724._00[index]];
        } else if (index != 0) {
            a = b = starMissionCompletionTracker._441F;
        } else {
            a = b = starMissionCompletionTracker._441D;
        }
        c = lbl_8034E9A0._0020[a / 9][a % 9]._14;
        d = lbl_8034E9A0._0020[b / 9][b % 9]._14;
        lbl_80371C30[0x82 + task->_14 + index]._00->_5C = lbl_2_data_2B3A4[c] << 16;
        lbl_80371C30[0x7E + task->_14 + index]._00->_5C = lbl_2_data_2B3A4[c] << 16;
        fn_800363D8(task, index + 0x89, 1, 3, lbl_2_data_2B3A4[c]);
        fn_800363D8(task, index + 0x8B, 1, 3, lbl_2_data_2B3A4[d]);
        lbl_80371C30[0x80 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x80 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x78 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x78 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x7C + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x7C + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x97 + task->_14 + index]._00->_64 = 0x78;
        lbl_80371C30[0x97 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x99 + task->_14 + index]._00->_64 = 0x79;
        fn_2_74F40(task, index);
        lbl_80371C30[0xAC + task->_14 + index]._00->_68 = 4;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n = isAnimDone(task, index, 20);

        n += isAnimDone(task, index + 2, 20);
        n += isAnimDone(task, index + 0x85, 10);
        n += isAnimDone(task, index + 0x89, 5);
        if (n == 4) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007F8BC size:0x240
void fn_2_7F8BC(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s8 sel = lbl_2_bss_F468._00[index];
        s8 found;
        s32 value;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                found = i;
                break;
            }
        }
        value = lbl_803C6724._02[index][found];
        // Written out, this keeps fn_2_7F8BC out of fn_2_81628, which calls it in the target.
        lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_54 =
            lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_54 | 2;
        lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_5C = 0;
        lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_68 = 1;
        lbl_80371C30[0x58 + task->_14 + sel + index * 9]._00->_5C = value << 16;
        fn_2_75BE4(task, index);
        fn_2_74F40(task, index);
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007F714 size:0x1A8
void fn_2_7F714(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1) {
        s8 sel = lbl_2_bss_F468._00[index];
        BOOL done;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                break;
            }
        }
        done = isAnimDone(task, 0x34 + sel + index * 9, 10);
        if (fn_2_75B58(task, index) && done == TRUE) {
            fn_80062674(index);
            fn_2_CCE0(index);
        }
    }
}

// .text:0x0007F2BC size:0x458
void fn_2_7F2BC(UnkTask0C50* task, s32 index) {
    s32 foundPrev;
    s32 sel;
    s32 prev;
    s32 i;
    s32 foundSel;

    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        sel = lbl_2_bss_F468._00[index];
        prev = lbl_2_bss_F468._00[index + 2];
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                foundSel = i;
            }
            if (lbl_803C6724._14[index][i] == prev) {
                foundPrev = i;
            }
        }
        if (sel != 9 && sel != 10) {
            if (lbl_803C6724._02[index][foundSel] != -1 && lbl_803C6724._02[index][foundSel] != 0x36) {
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_5C = 0;
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_68 = 1;
            }
            lbl_80371C30[0x46 + task->_14 + sel + index * 9]._00->_5C = 0;
            lbl_80371C30[0x46 + task->_14 + sel + index * 9]._00->_68 = 1;
            lbl_80371C30[0x22 + task->_14 + sel + index * 9]._00->_54 |= 2;
        }
        if (prev != 9 && prev != 10) {
            if (lbl_2_bss_F468._00[index + 2] != lbl_2_bss_F468._00[index]) {
                lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_5C = 0xF0000;
                lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 4;
                if (lbl_8034E9A0._46E0[index] == lbl_803C6724._02[index][foundPrev]) {
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 1;
                } else {
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 4;
                }
            }
            lbl_80371C30[0x22 + task->_14 + prev + index * 9]._00->_54 &= ~2;
        }
        fn_2_75BE4(task, index);
        fn_2_74F40(task, index);
        if (lbl_80371C30[0x93 + task->_14 + index]._00->_5C >> 16 == 10 &&
            lbl_8034E9A0._46E0[index] != lbl_803C6724._02[index][foundPrev])
        {
            lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 4;
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 4;
        } else if (lbl_80371C30[0x8F + task->_14 + index]._00->_5C >> 16 == 10 && sel == 10) {
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
        }
        if (sel == prev) {
            lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_68 = 4;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007F030 size:0x28C
void fn_2_7F030(UnkTask0C50* task, s32 index) {
    s32 n;
    s32 expected;
    s32 i;
    s32 sel;
    s32 prev;
    s32 foundPrev;
    s32 foundSel;

    sel = lbl_2_bss_F468._00[index];
    prev = lbl_2_bss_F468._00[index + 2];
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        n = 0;
        expected = 0;
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                foundSel = i;
            }
            if (lbl_803C6724._14[index][i] == prev) {
                foundPrev = i;
            }
        }
        if (sel == prev) {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 0);
        } else if (lbl_803C6724._02[index][foundSel] != -1 && lbl_803C6724._02[index][foundSel] != 0x36) {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 10);
        }
        if (lbl_8034E9A0._46E0[index] == lbl_803C6724._02[index][foundPrev]) {
            expected++;
            n += isAnimDone(task, 0x34 + prev + index * 9, 20);
        }
        if (fn_2_75B58(task, index) && n == expected) {
            if (sel == prev) {
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_54 &= ~2;
            }
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007EF68 size:0xC8
void fn_2_7EF68(UnkTask0C50* task, s32 index) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (i == lbl_2_bss_F468._00[index]) {
            lbl_80371C30[0x22 + task->_14 + i + index * 9]._00->_54 |= 2;
        }
    }
}

// .text:0x0007EE7C size:0xEC
void fn_2_7EE7C(UnkTask0C50* task, s32 index) {
    s32 sel = lbl_2_bss_F468._00[index];

    if (lbl_2_bss_F468._41[index]) {
        lbl_80371C30[0x22 + task->_14 + sel + index * 9]._00->_54 &= ~2;
    } else {
        lbl_80371C30[0x22 + task->_14 + sel + index * 9]._00->_54 |= 2;
    }
    fn_2_74F40(task, index);
    lbl_803C66B0._5D[index] = 0;
    if (lbl_2_bss_F468._59[index]) {
        fn_800625A4(index, 0x1A);
    }
}

// .text:0x0007E974 size:0x508
void fn_2_7E974(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s8 off;
        s32 i;

        lbl_80371C30[0xC + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0x12 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xC + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xC + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xE + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xE + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x10 + task->_14 + index]._00->_5C = lbl_8034E9A0._470D[index] << 16;
        lbl_80371C30[0x12 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x12 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x14 + task->_14 + index]._00->_5C = lbl_8034E9A0._470D[index] << 16;
        lbl_80371C30[0xB6 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x8F + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0x50000;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xAC + task->_14 + index]._00->_68 = 4;
        if (g_d_GameSettings._10 == 0) {
            if (lbl_8034E9A0._46F8[0] == 0) {
                off = 1;
            } else {
                off = 0;
            }
            if (lbl_2_bss_F468._37[1]) {
                lbl_80371C30[task->_14 + 0x98]._00->_68 = 4;
            }
        }
        if (g_d_GameSettings._10 == 0 && lbl_2_bss_F468._37[0] && index == 0) {
            for (i = 0; i < 9; i++) {
                lbl_80371C30[0x4F + task->_14 + i]._00->_54 |= 2;
                lbl_80371C30[0x4F + task->_14 + i]._00->_64 = off + 0x11;
                lbl_80371C30[0x4F + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[0x4F + task->_14 + i]._00->_68 = 0;
            }
            lbl_80371C30[0x8F + task->_14 + off]._00->_68 = 1;
            lbl_80371C30[0x91 + task->_14 + off]._00->_5C = 0;
            lbl_80371C30[0x91 + task->_14 + off]._00->_68 = 1;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007E860 size:0x114
void fn_2_7E860(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index + 0xC, 10);

        n += isAnimDone(task, index + 0xE, 14);
        n += isAnimDone(task, index + 0x12, 10);
        n += isAnimDone(task, index + 0x1C, 20);
        n += isAnimDone(task, index + 0x6A, 30);
        if (n == 5) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007E380 size:0x4E0
void fn_2_7E380(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[0xC + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0x12 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xC + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xE + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x12 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x12 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xB6 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x8F + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xAC + task->_14 + index]._00->_68 = 1;
        if (g_d_GameSettings._10 == 0 && index == 0) {
            s8 id;
            s32 i;

            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._02[1][i] == lbl_8034E9A0._46E0[1]) {
                    id = lbl_803C6724._14[1][i];
                }
            }
            for (i = 0; i < 9; i++) {
                if (index == 0) {
                    if (i != id) {
                        lbl_80371C30[0x4F + task->_14 + i]._00->_54 &= ~2;
                    } else {
                        lbl_80371C30[0x3D + task->_14 + id]._00->_68 = 1;
                        lbl_80371C30[0x4F + task->_14 + id]._00->_68 = 4;
                        lbl_80371C30[0x4F + task->_14 + id]._00->_54 |= 2;
                    }
                }
                lbl_80371C30[0x22 + task->_14 + i + 9]._00->_54 &= ~2;
            }
            lbl_80371C30[task->_14 + 0x94]._00->_68 = 4;
            lbl_80371C30[task->_14 + 0x96]._00->_68 = 4;
            lbl_80371C30[task->_14 + 0x90]._00->_68 = 4;
            lbl_80371C30[task->_14 + 0x92]._00->_68 = 4;
            lbl_80371C30[task->_14 + 0x98]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0xAD]._00->_54 &= ~2;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007E194 size:0x1EC
void fn_2_7E194(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n;
        s32 expected = 2;
        s8 id;
        s32 i;

        n = isAnimDone(task, index + 0x1C, 10);
        n += isAnimDone(task, index + 0x6A, 10);
        expected++;
        n += isAnimDone(task, index + 0x89, 5);
        if (g_d_GameSettings._10 == 0 && index == 0) {
            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._02[1][i] == lbl_8034E9A0._46E0[1]) {
                    id = lbl_803C6724._14[1][i];
                }
            }
            expected++;
            n += isAnimDone(task, id + 0x3D, 20);
        }
        if (n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007DAB8 size:0x6DC
void fn_2_7DAB8(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s32 sel;
        s32 i;
        s32 foundSel;
        s32 foundPrev;
        s32 prev;

        prev = lbl_2_bss_F468._00[index + 2];
        sel = lbl_2_bss_F468._00[index];
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                foundSel = i;
            }
            if (lbl_803C6724._14[index][i] == prev) {
                foundPrev = i;
            }
        }
        if (prev != 9 && prev != 10 && prev < 9) {
            if (prev != lbl_2_bss_F468._61[index]) {
                lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_5C = 0xF0000;
                lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 4;
                if (lbl_803C6724._02[index][foundPrev] != -1 && lbl_803C6724._02[index][foundPrev] != 0x36) {
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_5C = 0xA0000;
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 1;
                }
            }
            lbl_80371C30[0x22 + task->_14 + prev + index * 9]._00->_54 &= ~2;
        }
        if (sel != 9 && sel != 10 && sel < 9 && sel != lbl_2_bss_F468._61[index]) {
            lbl_80371C30[0x46 + task->_14 + sel + index * 9]._00->_5C = 0;
            lbl_80371C30[0x46 + task->_14 + sel + index * 9]._00->_68 = 1;
            if (lbl_803C6724._02[index][foundSel] != -1 && lbl_803C6724._02[index][foundSel] != 0x36) {
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_5C = 0x140000;
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_68 = 4;
            }
            if (lbl_2_bss_F468._41[index] == 0) {
                lbl_80371C30[0x22 + task->_14 + sel + index * 9]._00->_54 |= 2;
                lbl_80371C30[0x22 + task->_14 + sel + index * 9]._00->_68 = 1;
            }
        }
        fn_2_74F40(task, index);
        if (sel == 9) {
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
        } else if (sel == 10) {
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 1;
        } else {
            if ((lbl_80371C30[0x95 + task->_14 + index]._00->_5C >> 16) > 10) {
                lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0xA0000;
                lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 4;
            }
            if ((lbl_80371C30[0x91 + task->_14 + index]._00->_5C >> 16) > 10 || prev == 10) {
                lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
                lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
            }
        }
        if (lbl_2_bss_F468._5F[index]) {
            if (prev == lbl_2_bss_F468._61[index] || sel == lbl_2_bss_F468._61[index]) {
                s32 found;

                for (i = 0; i < 9; i++) {
                    if (lbl_803C6724._14[index][i] == lbl_2_bss_F468._61[index]) {
                        found = i;
                    }
                }
                // The target stores the byte back unchanged.
                lbl_2_bss_F468._61[index] = lbl_2_bss_F468._61[index];
                if (lbl_803C6724._02[index][found] != -1 && lbl_803C6724._02[index][found] != 0x36) {
                    lbl_80371C30[0x34 + task->_14 + lbl_2_bss_F468._61[index] + index * 9]._00->_5C = 0xA0000;
                    lbl_80371C30[0x34 + task->_14 + lbl_2_bss_F468._61[index] + index * 9]._00->_68 = 0;
                }
                lbl_80371C30[0x46 + task->_14 + lbl_2_bss_F468._61[index] + index * 9]._00->_5C = 0xF0000;
                lbl_80371C30[0x46 + task->_14 + lbl_2_bss_F468._61[index] + index * 9]._00->_68 = 0;
                if (sel == lbl_2_bss_F468._61[index]) {
                    lbl_80371C30[0x22 + task->_14 + lbl_2_bss_F468._61[index] + index * 9]._00->_54 |= 2;
                }
            } else {
                lbl_80371C30[0x22 + task->_14 + lbl_2_bss_F468._61[index] + index * 9]._00->_54 &= ~2;
            }
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007D85C size:0x25C
void fn_2_7D85C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n;
        s32 expected;
        s32 i;
        s32 foundSel;
        s32 prev;
        s32 sel;
        s32 foundPrev;

        n = 0;
        expected = 0;
        sel = lbl_2_bss_F468._00[index];
        prev = lbl_2_bss_F468._00[index + 2];

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                foundSel = i;
            }
            if (lbl_803C6724._14[index][i] == prev) {
                foundPrev = i;
            }
        }
        if (prev != 9 && prev != 10 && prev < 9 && lbl_803C6724._02[index][foundPrev] != -1 &&
            lbl_803C6724._02[index][foundPrev] != 0x36 && prev != lbl_2_bss_F468._61[index] && prev != sel)
        {
            expected++;
            n += isAnimDone(task, 0x34 + prev + index * 9, 20);
        }
        if (sel != 9 && sel != 10 && sel < 9 && lbl_803C6724._02[index][foundSel] != -1 &&
            lbl_803C6724._02[index][foundSel] != 0x36 && sel != lbl_2_bss_F468._61[index])
        {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 10);
        }
        if (n == expected) {
            lbl_2_bss_F468._00[index + 2] = lbl_2_bss_F468._00[index];
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
            if (lbl_2_bss_F468._63[index]) {
                lbl_2_bss_F468._63[index] = 0;
                fn_800625A4(index, 0x1A);
            }
        }
    }
}

// .text:0x0007BFF8 size:0x1864
// 99.97%: registers only: the first isAnimDone result in the second part goes to n's r27 in
// the target and r22 in the base, and expected is set after the last call's arguments.
void fn_2_7BFF8(UnkTask0C50* task, s32 index) {
    s32 a;
    s32 b;
    u8 c;
    u8 d;
    s32 i;
    s32 off;
    u8 found;
    u8 slot;
    s32 p93;
    s32 p95;
    s32 a95;
    s32 p8F;
    s32 a8F;
    s32 p91;
    s32 a93;
    s32 a91;

    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (g_d_GameSettings.GameModeSelected != 5) {
            a = lbl_800FE5D4[lbl_2_bss_F410._10[index]];
            b = lbl_800FE5D4[lbl_803C6724._00[index]];
        } else if (index != 0) {
            a = b = starMissionCompletionTracker._441F;
        } else {
            a = b = starMissionCompletionTracker._441D;
        }
        c = lbl_8034E9A0._0020[a / 9][a % 9]._14;
        d = lbl_8034E9A0._0020[b / 9][b % 9]._14;
        lbl_80371C30[0x82 + task->_14 + index]._00->_5C = lbl_2_data_2B3A4[c] << 16;
        lbl_80371C30[0x7E + task->_14 + index]._00->_5C = lbl_2_data_2B3A4[c] << 16;
        fn_800363D8(task, index + 0x89, 1, 3, lbl_2_data_2B3A4[c]);
        fn_800363D8(task, index + 0x8B, 1, 3, lbl_2_data_2B3A4[d]);
        lbl_80371C30[task->_14 + 6]._00->_68 = 1;
        lbl_80371C30[task->_14 + 8]._00->_68 = 1;
        lbl_80371C30[0x1A + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0x1A + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x85 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x85 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x82 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0x7A + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0x82 + task->_14 + index]._00->_5C = lbl_80108ED0[lbl_8034E9A0._46E0[1]] << 16;
        lbl_80371C30[0x7E + task->_14 + index]._00->_5C = lbl_2_bss_F410._10[index] << 16;
        lbl_80371C30[0x7A + task->_14 + index]._00->_5C = lbl_8034E9A0._46F8[1] << 16;
        lbl_80371C30[task->_14 + 0x84]._00->_54 &= ~2;
        lbl_80371C30[0x97 + task->_14 + index]._00->_64 = 0x77;
        lbl_80371C30[0x97 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x97 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xB0 + task->_14 + index]._00->_54 &= ~2;
        for (i = 0; i < 9; i++) {
            lbl_80371C30[0x22 + task->_14 + i + index * 9]._00->_54 &= ~2;
        }
        lbl_80371C30[task->_14 + index]._00->_64 = 0x48;
        lbl_80371C30[2 + task->_14 + index]._00->_64 = 0x48;
        lbl_80371C30[4 + task->_14 + index]._00->_64 = 0x51;
        lbl_80371C30[task->_14 + index]._00->_5C = 0x280000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x280000;
        lbl_80371C30[4 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[task->_14 + index]._00->_68 = 4;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[4 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x10 + task->_14 + index]._00->_5C = lbl_8034E9A0._470D[index] << 16;
        lbl_80371C30[0x14 + task->_14 + index]._00->_5C = lbl_8034E9A0._470D[index] << 16;
        lbl_80371C30[task->_14 + 0x1C]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x1D]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x1E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x1F]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x78]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x79]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x7C]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x7D]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x80]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x81]._00->_54 &= ~2;
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_80371C30[4 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[4 + task->_14 + index]._00->_68 = 1;
            if (g_d_GameSettings._10 == 0 && index == 0) {
                lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 0;
                lbl_80371C30[0xC + task->_14 + index]._00->_5C = 0x140000;
                lbl_80371C30[0xC + task->_14 + index]._00->_68 = 4;
                lbl_80371C30[0xE + task->_14 + index]._00->_5C = 0x180000;
                lbl_80371C30[0xE + task->_14 + index]._00->_68 = 4;
                lbl_80371C30[0x12 + task->_14 + index]._00->_5C = 0x140000;
                lbl_80371C30[0x12 + task->_14 + index]._00->_68 = 4;
            } else {
                lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x97 + task->_14 + index]._00->_54 &= ~2;
                lbl_80371C30[0xC + task->_14 + index]._00->_54 |= 2;
                lbl_80371C30[0x12 + task->_14 + index]._00->_54 |= 2;
                lbl_80371C30[0xC + task->_14 + index]._00->_5C = 0x140000;
                lbl_80371C30[0xC + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0xE + task->_14 + index]._00->_5C = 0x180000;
                lbl_80371C30[0xE + task->_14 + index]._00->_68 = 4;
                lbl_80371C30[0x12 + task->_14 + index]._00->_5C = 0x140000;
                lbl_80371C30[0x12 + task->_14 + index]._00->_68 = 1;
            }
            lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._02[index][i] == lbl_8034E9A0._46E0[index]) {
                    found = lbl_803C6724._14[index][i];
                }
            }
            // The target stores the word back unchanged.
            lbl_8034E9A0._46E0[index] = lbl_8034E9A0._46E0[index];
            for (i = 0; i < 9; i++) {
                if (g_d_GameSettings._10 == 0 && lbl_2_bss_F468._37[index] == 0 && index == 1) {
                    if (i == found) {
                        off = lbl_8034E9A0._46F8[0] == 0;
                        lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_64 = off + 17;
                        lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_54 |= 2;
                    } else {
                        lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_54 &= ~2;
                    }
                } else {
                    if (g_d_GameSettings._10 == 0) {
                        if (lbl_8034E9A0._46F8[0] == 0) {
                            off = 1;
                        } else {
                            off = 0;
                        }
                    }
                    if (g_d_GameSettings._10 == 0 && index != 0) {
                        lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_64 = off + 17;
                    } else {
                        lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_64 = lbl_8034E9A0._46F8[index] + 17;
                    }
                    lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_5C = 0;
                    lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_54 |= 2;
                    lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_68 = 0;
                }
                if (lbl_803C6724._02[index][i] != -1) {
                    lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_54 |= 2;
                    if (i == lbl_2_bss_F468._00[index]) {
                        lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_5C = 0xA0000;
                        lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_68 = 0;
                    } else {
                        lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_5C = 0x140000;
                        lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_68 = 0;
                    }
                    slot = lbl_803C6724._14[index][i];
                    lbl_80371C30[0x58 + task->_14 + slot + index * 9]._00->_5C = lbl_803C6724._02[index][i] << 16;
                    lbl_80371C30[0x58 + task->_14 + slot + index * 9]._00->_68 = 0;
                } else {
                    lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_54 &= ~2;
                }
            }
            fn_2_75BE4(task, index);
            if (g_d_GameSettings._10 != 0 || index == 0) {
                lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 0;
            }
            lbl_80371C30[task->_14 + 0xAE]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0xAF]._00->_54 |= 2;
        } else {
            lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
            if (g_d_GameSettings._10 == 0) {
                if (lbl_8034E9A0._46F8[0] == 0) {
                    off = 1;
                } else {
                    off = 0;
                }
            }
            for (i = 0; i < 9; i++) {
                if (index != 0) {
                    lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_64 = off + 17;
                } else {
                    lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_64 = lbl_8034E9A0._46F8[index] + 17;
                }
                lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_5C = 0;
                if (i == lbl_2_bss_F468._00[index]) {
                    lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_54 |= 2;
                    lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_68 = 1;
                } else {
                    lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_54 |= 2;
                    lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_68 = 0;
                }
                if (lbl_803C6724._02[index][i] != -1) {
                    lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_54 |= 2;
                    if (i == lbl_2_bss_F468._00[index]) {
                        lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_5C = 0xA0000;
                        lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_68 = 0;
                    } else {
                        lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_5C = 0x140000;
                        lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_68 = 0;
                    }
                    slot = lbl_803C6724._14[index][i];
                    lbl_80371C30[0x58 + task->_14 + slot + index * 9]._00->_5C = lbl_803C6724._02[index][i] << 16;
                    lbl_80371C30[0x58 + task->_14 + slot + index * 9]._00->_68 = 0;
                } else {
                    lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_54 &= ~2;
                }
            }
            fn_2_75BE4(task, index);
            lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
        }
        if (lbl_803CBBCC->_6 == 11) {
            if (g_d_GameSettings.GameModeSelected != 5) {
                if (index == 0 && g_d_GameSettings._10 == 0) {
                    p93 = 0;
                    p95 = 0;
                    a93 = 0;
                    a95 = 0;
                    p8F = 0;
                    p91 = 0;
                    a8F = 0;
                    a91 = 0;
                } else {
                    p93 = 0;
                    p95 = 0;
                    a93 = 1;
                    a95 = 1;
                    p8F = 0;
                    p91 = 0;
                    a8F = 1;
                    a91 = 0;
                }
                lbl_80371C30[0x93 + task->_14 + index]._00->_5C = p93 << 16;
                lbl_80371C30[0x93 + task->_14 + index]._00->_68 = a93;
                lbl_80371C30[0x95 + task->_14 + index]._00->_5C = p95 << 16;
                lbl_80371C30[0x95 + task->_14 + index]._00->_68 = a95;
                lbl_80371C30[0x8F + task->_14 + index]._00->_5C = p8F << 16;
                lbl_80371C30[0x8F + task->_14 + index]._00->_68 = a8F;
                lbl_80371C30[0x91 + task->_14 + index]._00->_5C = p91 << 16;
                lbl_80371C30[0x91 + task->_14 + index]._00->_68 = a91;
            } else {
                if (index == 1) {
                    lbl_80371C30[0x93 + task->_14 + index]._00->_54 &= ~2;
                } else {
                    lbl_80371C30[0x93 + task->_14 + index]._00->_54 |= 2;
                    lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
                    lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
                    lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
                    lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
                }
                lbl_80371C30[0x8F + task->_14 + index]._00->_54 &= ~2;
            }
        }
        if (lbl_2_bss_F468._3F && lbl_2_bss_F468._37[0] && index == 0 && g_d_GameSettings.GameModeSelected == 5) {
            if (g_d_GameSettings.GameModeSelected != 5 || index == 0) {
                lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
            }
            if (g_d_GameSettings.GameModeSelected == 5) {
                lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 0;
            }
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n;
        s32 expected;

        if (g_d_GameSettings.GameModeSelected != 5) {
            n = isAnimDone(task, index, 20);
            n += isAnimDone(task, index + 2, 20);
            if (g_d_GameSettings._10 == 0 && index == 0) {
                n += isAnimDone(task, index + 0x6A, 30);
                n += isAnimDone(task, index + 0xC, 10);
                n += isAnimDone(task, index + 0xE, 14);
                expected = 6;
                n += isAnimDone(task, index + 0x12, 10);
            } else {
                n += isAnimDone(task, index + 0x1C, 10);
                n += isAnimDone(task, index + 0x6A, 10);
                n += isAnimDone(task, index + 0xC, 30);
                n += isAnimDone(task, index + 0xE, 14);
                n += isAnimDone(task, index + 0x12, 30);
                expected = 8;
                n += isAnimDone(task, index + 0x89, 5);
            }
        } else {
            n = isAnimDone(task, index, 20);
            n += isAnimDone(task, index + 2, 20);
            n += isAnimDone(task, index + 0x1C, 10);
            n += isAnimDone(task, index + 0x6A, 10);
            expected = 5;
            n += isAnimDone(task, index + 0x89, 5);
        }
        expected++;
        n += isAnimDone(task, index + 0x85, 10);
        if (fn_2_75B58(task, index) && n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007AE3C size:0x11BC
// 99.78%: registers only: where the first pass highlights the found slot, the target
// computes with r0 and the base with r22/r23; assigning off there instead costs more.
void fn_2_7AE3C(UnkTask0C50* task, s32 index) {
    s32 i;
    s8 found;
    s8 id;
    s8 off;

    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + 6]._00->_68 = 1;
        lbl_80371C30[task->_14 + 8]._00->_68 = 1;
        lbl_80371C30[task->_14 + 0x1C]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x1D]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x1E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x1F]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 0x78]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x79]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x7C]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x7D]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x80]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 0x81]._00->_54 &= ~2;
        lbl_80371C30[0x97 + task->_14 + index]._00->_64 = 0x77;
        lbl_80371C30[0x99 + task->_14 + index]._00->_64 = 0x76;
        for (i = 0; i < 9; i++) {
            lbl_80371C30[0x22 + task->_14 + i + index * 9]._00->_54 &= ~2;
        }
        lbl_80371C30[task->_14 + index]._00->_64 = 0x48;
        lbl_80371C30[2 + task->_14 + index]._00->_64 = 0x48;
        lbl_80371C30[4 + task->_14 + index]._00->_64 = 0x51;
        lbl_80371C30[task->_14 + index]._00->_5C = 0;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[4 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[task->_14 + index]._00->_68 = 1;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[4 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x12 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x12 + task->_14 + index]._00->_68 = 4;
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 1;
            {
                s32 cur = lbl_8034E9A0._46E0[index];

                for (i = 0; i < 9; i++) {
                    if (lbl_803C6724._02[index][i] == cur) {
                        found = lbl_803C6724._14[index][i];
                    }
                }
                lbl_8034E9A0._46E0[index] = cur;
            }
            for (i = 0; i < 9; i++) {
                id = lbl_803C6724._14[index][i];
                if (g_d_GameSettings._10 == 0 && lbl_2_bss_F468._37[index] == 0 && index == 1) {
                    if (i == found) {
                        s8 first = lbl_8034E9A0._46F8[0] == 0;

                        lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_64 = first + 17;
                        lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_54 |= 2;
                    } else {
                        lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_54 &= ~2;
                    }
                } else {
                    if (g_d_GameSettings._10 == 0) {
                        if (lbl_8034E9A0._46F8[0] == 0) {
                            off = 1;
                        } else {
                            off = 0;
                        }
                    }
                    if (g_d_GameSettings._10 == 0 && index != 0) {
                        lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_64 = off + 17;
                    } else {
                        lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_64 = lbl_8034E9A0._46F8[index] + 17;
                    }
                    lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_5C = 0;
                    lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_54 |= 2;
                    lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_68 = 0;
                }
                if (lbl_803C6724._02[index][i] != -1) {
                    lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_54 |= 2;
                    if (i == lbl_2_bss_F468._00[index]) {
                        lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_5C = 0xA0000;
                        lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_68 = 0;
                        lbl_80371C30[0x22 + task->_14 + id + index * 9]._00->_54 |= 2;
                        lbl_80371C30[0x22 + task->_14 + id + index * 9]._00->_68 = 1;
                    } else {
                        lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_5C = 0x140000;
                        lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_68 = 0;
                        lbl_80371C30[0x22 + task->_14 + id + index * 9]._00->_54 &= ~2;
                    }
                    lbl_80371C30[0x58 + task->_14 + id + index * 9]._00->_5C = lbl_803C6724._02[index][i] << 16;
                    lbl_80371C30[0x58 + task->_14 + id + index * 9]._00->_68 = 0;
                } else {
                    lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_54 &= ~2;
                    lbl_80371C30[0x22 + task->_14 + id + index * 9]._00->_54 &= ~2;
                }
            }
            lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x6E + task->_14 + index * 5]._00->_5C = 0;
            lbl_80371C30[0x6E + task->_14 + index * 5]._00->_68 = 0;
            lbl_80371C30[0x6F + task->_14 + index * 5]._00->_5C = 0;
            lbl_80371C30[0x6F + task->_14 + index * 5]._00->_68 = 0;
            lbl_80371C30[0x70 + task->_14 + index * 5]._00->_5C = 0;
            lbl_80371C30[0x70 + task->_14 + index * 5]._00->_68 = 0;
            lbl_80371C30[0x71 + task->_14 + index * 5]._00->_5C = 0;
            lbl_80371C30[0x71 + task->_14 + index * 5]._00->_68 = 0;
            lbl_80371C30[0x72 + task->_14 + index * 5]._00->_5C = 0;
            lbl_80371C30[0x72 + task->_14 + index * 5]._00->_68 = 0;
            if (g_d_GameSettings._10 != 0 || index == 0) {
                lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 1;
            }
        } else {
            lbl_80371C30[0x80 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x80 + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0x82 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x82 + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0x78 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x78 + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0x7A + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x7A + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0x97 + task->_14 + index]._00->_64 = 0x77;
            lbl_80371C30[task->_14 + 0x98]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x97]._00->_5C = 0;
            lbl_80371C30[task->_14 + 0x97]._00->_54 &= ~2;
            lbl_80371C30[0xB0 + task->_14 + index]._00->_54 &= ~2;
            lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x85 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x85 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 1;
            if (g_d_GameSettings._10 == 0) {
                if (lbl_8034E9A0._46F8[0] == 0) {
                    off = 1;
                } else {
                    off = 0;
                }
            }
            for (i = 0; i < 9; i++) {
                id = lbl_803C6724._14[index][i];
                if (index != 0) {
                    lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_64 = off + 17;
                } else {
                    lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_64 = lbl_8034E9A0._46F8[index] + 17;
                }
                if (i == lbl_2_bss_F468._00[index]) {
                    lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_54 |= 2;
                    lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_68 = 1;
                } else {
                    lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_54 |= 2;
                    lbl_80371C30[0x46 + task->_14 + id + index * 9]._00->_68 = 0;
                }
                if (lbl_803C6724._02[index][i] != -1) {
                    lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_54 |= 2;
                    if (i == lbl_2_bss_F468._00[index]) {
                        lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_5C = 0xA0000;
                        lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_68 = 0;
                    } else {
                        lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_5C = 0x140000;
                        lbl_80371C30[0x34 + task->_14 + id + index * 9]._00->_68 = 0;
                    }
                    id = lbl_803C6724._14[index][i];
                    lbl_80371C30[0x58 + task->_14 + id + index * 9]._00->_5C = lbl_803C6724._02[index][i] << 16;
                    lbl_80371C30[0x58 + task->_14 + id + index * 9]._00->_68 = 0;
                } else {
                    lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_54 &= ~2;
                }
            }
            if (lbl_803CBBCC->_6 == 11 && index == 0 && g_d_GameSettings._10 == 0) {
                lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 0;
            } else {
                lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
            }
            fn_2_75BE4(task, index);
        }
        if (lbl_803CBBCC->_6 == 11 || g_d_GameSettings.GameModeSelected == 5) {
            if (g_d_GameSettings.GameModeSelected != 5 || index == 0) {
                lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
            }
            if (g_d_GameSettings.GameModeSelected != 5) {
                lbl_80371C30[0x8F + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 0;
            }
        }
        if (lbl_2_bss_F468._3F && lbl_2_bss_F468._37[0] && g_d_GameSettings.GameModeSelected == 5) {
            if (index == 0) {
                lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
                lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
            } else {
                lbl_80371C30[0x93 + task->_14 + index]._00->_54 &= ~2;
            }
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007AC64 size:0x1D8
void fn_2_7AC64(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n;
        s32 expected = 2;

        n = isAnimDone(task, index, 20);
        n += isAnimDone(task, index + 2, 20);
        n += isAnimDone(task, index + 0x1C, 10);
        expected += 2;
        n += isAnimDone(task, index + 0x6A, 10);
        if (g_d_GameSettings.GameModeSelected == 5) {
            n += isAnimDone(task, index + 0x89, 5);
            expected += 2;
            n += isAnimDone(task, index + 0x85, 10);
        }
        if (fn_2_75B58(task, index) && n == expected) {
            fn_80062674(index);
            if (lbl_803CBBCC->_6 == 11 && index == 0 && g_d_GameSettings._10 == 0) {
                fn_800625A4(0, 0x11);
            } else {
                lbl_803C66B0._0D[index] = 2;
            }
        }
    }
}

// .text:0x0007A9D8 size:0x28C
void fn_2_7A9D8(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + index]._00->_68 = 4;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[4 + task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[4 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x85 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x85 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0x50000;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x34 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xB2 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xAE + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0x97 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xAC + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xC + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0x12 + task->_14 + index]._00->_54 &= ~2;
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007A748 size:0x290
void fn_2_7A748(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index, 0);

        n += isAnimDone(task, index + 2, 0);
        n += isAnimDone(task, index + 0x85, 0);
        n += isAnimDone(task, index + 0x6A, 0);
        if (n == 4) {
            lbl_80371C30[task->_14 + index]._00->_64 = 0x47;
            lbl_80371C30[2 + task->_14 + index]._00->_64 = 0x47;
            lbl_80371C30[0x97 + task->_14 + index]._00->_64 = 0x78;
            lbl_80371C30[0x99 + task->_14 + index]._00->_64 = 0x79;
            lbl_80371C30[task->_14 + 0x1C]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x1D]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x1E]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x1F]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 0x78]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x79]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x7C]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x7D]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x80]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0x81]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 0xF]._00->_68 = 0;
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007A5B8 size:0x190
void fn_2_7A5B8(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[2 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[task->_14 + index]._00->_68 = 1;
        lbl_80371C30[2 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x85 + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x85 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x1C + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x1C + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x6A + task->_14 + index]._00->_5C = 0x1E0000;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
        if (g_d_GameSettings.GameModeSelected != 5 || index == 0) {
            lbl_80371C30[0x93 + task->_14 + index]._00->_54 &= ~2;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007A460 size:0x158
void fn_2_7A460(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index, 40);

        n += isAnimDone(task, index + 2, 40);
        n += isAnimDone(task, index + 0x85, 30);
        n += isAnimDone(task, index + 0x1C, 30);
        n += isAnimDone(task, index + 0x6A, 50);
        if (n == 5) {
            lbl_80371C30[0xC + task->_14 + index]._00->_54 &= ~2;
            lbl_80371C30[0x12 + task->_14 + index]._00->_54 &= ~2;
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007A194 size:0x2CC
void fn_2_7A194(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s32 prev = lbl_2_bss_F468._00[index + 2];
        s8 found;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == prev) {
                found = i;
                break;
            }
        }
        lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
        if (prev == 10) {
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
        } else if (prev != 9) {
            lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_5C = 0xF0000;
            lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 4;
            if (lbl_803C6724._02[index][found] != -1 && lbl_803C6724._02[index][found] != 0x36) {
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_5C = 0xA0000;
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 1;
            }
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00079FAC size:0x1E8
void fn_2_79FAC(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = 0;
        s32 expected = 0;
        s32 sel = lbl_2_bss_F468._00[index + 2];
        s8 found;
        s32 i;
        s8 id;

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == sel) {
                found = i;
                break;
            }
        }
        id = lbl_803C6724._02[index][found];
        if (id != -1 && id != 0x36 && sel < 9) {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 20);
        }
        if (n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00079CF8 size:0x2B4
void fn_2_79CF8(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s8 sel = lbl_2_bss_F468._00[index];
        s8 prev = lbl_2_bss_F468._00[index + 2];
        s8 found;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (sel == lbl_803C6724._14[index][i]) {
                found = i;
                break;
            }
        }
        if (prev == 9) {
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 4;
        } else if (prev == 10) {
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
        }
        lbl_80371C30[0x46 + task->_14 + sel + index * 9]._00->_5C = 0;
        lbl_80371C30[0x46 + task->_14 + sel + index * 9]._00->_68 = 1;
        if (lbl_803C6724._02[index][found] != -1) {
            lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_5C = 0x140000;
            lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_68 = 4;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00079B24 size:0x1D4
void fn_2_79B24(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = 0;
        s32 expected = 0;
        s8 sel = lbl_2_bss_F468._00[index];
        s32 found;
        s32 i;

        for (i = 0; i < 9; i++) {
            if (sel == lbl_803C6724._14[index][i]) {
                found = i;
                break;
            }
        }
        if (lbl_803C6724._02[index][found] != -1) {
            expected++;
            n += isAnimDone(task, 0x34 + sel + index * 9, 10);
        }
        if (n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00079930 size:0x1F4
void fn_2_79930(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        s32 i;

        for (i = 0; i < 9; i++) {
            s32 slot = lbl_803C6724._14[index][i];
            s32 value = lbl_803C6724._02[index][i];

            lbl_80371C30[0x34 + task->_14 + slot + index * 9]._00->_54 |= 2;
            lbl_80371C30[0x34 + task->_14 + slot + index * 9]._00->_5C = 0;
            lbl_80371C30[0x34 + task->_14 + slot + index * 9]._00->_68 = 1;
            lbl_80371C30[0x58 + task->_14 + slot + index * 9]._00->_5C = value << 16;
        }
        fn_2_75BE4(task, index);
        if (lbl_2_bss_F468._00[index] == 9) {
            lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x00079764 size:0x1CC
void fn_2_79764(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = 0;
        s32 total = 0;
        s32 i;

        for (i = 0; i < 9; i++) {
            total++;
            n += isAnimDone(task, 0x34 + i + index * 9, 20);
        }
        if (fn_2_75B58(task, index) && n == total) {
            for (i = 0; i < 9; i++) {
                if (lbl_803C6724._4A[index][i] == 0) {
                    lbl_803C6724._4A[index][i] = 1;
                }
            }
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00079688 size:0xDC
void fn_2_79688(UnkTask0C50* task, s32 index) {
    s32 i;

    if (lbl_803C66B0._0D[index] == 0) {
        for (i = 0; i < 9; i++) {
            lbl_80371C30[0x46 + task->_14 + i + index * 9]._00->_68 = 4;
        }
        lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0xA0000;
        lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
    }
}

// .text:0x00079634 size:0x54
void fn_2_79634(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        fn_80062674(index);
        lbl_803C66B0._0D[index] = 2;
    }
}

// .text:0x00079394 size:0x2A0
void fn_2_79394(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (lbl_2_bss_F468._00[index] == 9) {
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 4;
        } else if (lbl_2_bss_F468._00[index] == 10) {
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x95 + task->_14 + index]._00->_68 = 4;
            lbl_80371C30[0x91 + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x91 + task->_14 + index]._00->_68 = 1;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n = 0;
        s32 expected = 0;

        if (lbl_2_bss_F468._00[index] == 9) {
            expected = 2;
            n = (lbl_80371C30[0x95 + task->_14 + index]._00->_5C >> 16 >= 10) +
                (lbl_80371C30[0x91 + task->_14 + index]._00->_5C >> 16 == 0);
        } else if (lbl_2_bss_F468._00[index] == 10) {
            expected = 2;
            n = (lbl_80371C30[0x95 + task->_14 + index]._00->_5C >> 16 == 0) +
                (lbl_80371C30[0x91 + task->_14 + index]._00->_5C >> 16 >= 10);
        }
        if (n == expected) {
            lbl_2_bss_F468._00[index + 2] = lbl_2_bss_F468._00[index];
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x0007912C size:0x268
void fn_2_7912C(UnkTask0C50* task, s32 index) {
    s32 i;

    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (lbl_803C66B0._00[0] == 2) {
            for (i = 1; i < 9; i++) {
                s8 slot = lbl_803C6724._14[index][i];
                s8 value = lbl_803C6724._02[index][slot];

                if (value != -1 && value != 0x36) {
                    lbl_80371C30[0x34 + task->_14 + i + index * 9]._00->_68 = 4;
                }
            }
            fn_2_75BE4(task, index);
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n = 0;
        s32 expected = 0;

        for (i = 1; i < 9; i++) {
            s8 slot = lbl_803C6724._14[index][i];
            s8 value = lbl_803C6724._02[index][slot];

            if (value != -1 && value != 0x36) {
                expected++;
                n += isAnimDone(task, 0x34 + i + index * 9, 0);
            }
        }
        if ((lbl_803C66B0._00[0] != 2 || fn_2_75B58(task, index)) && n == expected) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
            if (lbl_2_bss_F468._43[index]) {
                fn_2_102C8(index);
                lbl_2_bss_F468._43[index] = 0;
            }
        }
    }
}

// .text:0x00078F78 size:0x1B4
void fn_2_78F78(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[0xA + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xA + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x1E + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x8D + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x8D + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 4;
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_80371C30[0x8F + task->_14 + index]._00->_64 = 8;
            lbl_80371C30[0x8F + task->_14 + index]._00->_5C = 0;
            lbl_80371C30[0x8F + task->_14 + index]._00->_68 = 1;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        fn_80062674(index);
        lbl_803C66B0._0D[index] = 2;
    }
}

// .text:0x00078AC0 size:0x4B8
void fn_2_78AC0(UnkTask0C50* task, s32 index) {
    s8 prev;
    s8 found;
    s8 sel;
    s32 i;

    sel = lbl_2_bss_F468._00[index];
    prev = lbl_2_bss_F468._61[index];
    if (prev != -1) {
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == prev) {
                found = i;
            }
        }
    }
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_80371C30[0xA + task->_14 + index]._00->_5C = 0xF0000;
        lbl_80371C30[0xA + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x1E + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x93 + task->_14 + index]._00->_64 = 9;
        lbl_80371C30[0x89 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0x89 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0x8D + task->_14 + index]._00->_5C = 0x140000;
        lbl_80371C30[0x8D + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0x6A + task->_14 + index]._00->_68 = 1;
        if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_80371C30[0x8F + task->_14 + index]._00->_64 = 7;
        }
        if (prev != -1 && prev != sel) {
            lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 4;
            if (lbl_803C6724._02[index][found] != -1 && lbl_803C6724._02[index][found] != 0x36) {
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_5C = 0xA0000;
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 1;
            }
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        s32 n;
        s32 expected = 1;

        n = isAnimDone(task, index + 0x89, 5);
        expected++;
        n += isAnimDone(task, index + 0x6A, 10);
        if (prev != -1 && lbl_2_bss_F468._56 == 0 && prev != sel && lbl_803C6724._02[index][found] != -1 &&
            lbl_803C6724._02[index][found] != 0x36)
        {
            expected++;
            n += isAnimDone(task, 0x34 + prev + index * 9, 20);
        }
        if (n == expected) {
            lbl_2_bss_F468._61[index] = -1;
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
            if (lbl_2_bss_F468._65[index]) {
                if (g_d_GameSettings.GameModeSelected == 5) {
                    fn_800625A4(0, 0x13);
                    fn_800625A4(1, 0x13);
                } else if (g_d_GameSettings._10 == 0) {
                    fn_800625A4(index, 0x11);
                } else {
                    fn_800625A4(index, 0x11);
                }
                lbl_2_bss_F468._65[index] = 0;
            } else if (lbl_2_bss_F468._56) {
                fn_800625A4(index, 0xB);
            }
        }
    }
}

// .text:0x0007836C size:0x754
void fn_2_7836C(UnkTask0C50* task, s32 index) {
    s32 n;
    s32 expected;
    s8 prev;
    s8 foundPrev;
    s8 sel;
    s8 foundSel;
    s32 i;

    if (lbl_2_bss_F468._5F[index] == 0) {
        prev = lbl_2_bss_F468._61[index];
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == prev) {
                foundPrev = i;
            }
        }
        if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
            if (prev != -1) {
                lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_5C = 0;
                lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 1;
                if (lbl_803C6724._02[index][foundPrev] != -1 && lbl_803C6724._02[index][foundPrev] != 0x36) {
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_5C = 0x140000;
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 4;
                }
            }
            if (lbl_2_bss_F468._37[index]) {
                lbl_80371C30[0x93 + task->_14 + index]._00->_64 = 10;
                lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 1;
            }
            fn_800626EC(index);
            lbl_803C66B0._0D[index] = 1;
        }
        if (lbl_803C66B0._0D[index] == 1) {
            n = 0;
            expected = 0;
            if (lbl_803C6724._02[index][foundPrev] != -1 && lbl_803C6724._02[index][foundPrev] != 0x36 &&
                prev != -1)
            {
                expected++;
                n += isAnimDone(task, 0x34 + prev + index * 9, 10);
            }
            if (n == expected) {
                lbl_2_bss_F468._5F[index] = 1;
                fn_80062674(index);
                lbl_803C66B0._0D[index] = 2;
            }
        }
    } else {
        sel = lbl_2_bss_F468._00[index];
        prev = lbl_2_bss_F468._61[index];
        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == prev) {
                foundPrev = i;
            }
            if (lbl_803C6724._14[index][i] == sel) {
                foundSel = i;
            }
        }
        if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
            if (prev != -1) {
                if (lbl_803C6724._02[index][foundPrev] != -1 && lbl_803C6724._02[index][foundPrev] != 0x36) {
                    lbl_80371C30[0x58 + task->_14 + prev + index * 9]._00->_5C = lbl_803C6724._02[index][foundPrev]
                                                                                 << 16;
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_54 |= 2;
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_5C = 0xA0000;
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 1;
                } else {
                    lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_54 &= ~2;
                }
            }
            if (lbl_803C6724._02[index][foundSel] != -1 && lbl_803C6724._02[index][foundSel] != 0x36) {
                lbl_80371C30[0x58 + task->_14 + sel + index * 9]._00->_5C = lbl_803C6724._02[index][foundSel] << 16;
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_5C = 0xA0000;
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_68 = 0;
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_54 |= 2;
            } else {
                lbl_80371C30[0x34 + task->_14 + sel + index * 9]._00->_54 &= ~2;
            }
            if (prev != sel && prev != -1) {
                lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_5C = 0xF0000;
                lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 4;
            }
            if (lbl_2_bss_F468._37[index]) {
                lbl_80371C30[0x93 + task->_14 + index]._00->_64 = 9;
                lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0xA0000;
                lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 0;
            }
            fn_2_74F40(task, index);
            fn_800626EC(index);
            lbl_803C66B0._0D[index] = 1;
        }
        if (lbl_803C66B0._0D[index] == 1) {
            n = 0;
            expected = 0;
            if (lbl_803C6724._02[index][foundPrev] != -1 && lbl_803C6724._02[index][foundPrev] != 0x36 &&
                prev != -1 && prev != sel)
            {
                expected++;
                n += isAnimDone(task, 0x34 + prev + index * 9, 20);
            }
            if (n == expected) {
                lbl_2_bss_F468._5F[index] = 0;
                lbl_2_bss_F468._61[index] = -1;
                fn_80062674(index);
                lbl_803C66B0._0D[index] = 2;
            }
        }
    }
}

// .text:0x0007805C size:0x310
// 99.49%: prev and the common addresses (&lbl_2_bss_F468 + index, &_0D[index], index * 9)
// sit in rotated saved registers.
void fn_2_7805C(UnkTask0C50* task, s32 index) {
    s32 n;
    s8 prev;
    s32 expected;
    s8 found;
    s32 i;

    prev = lbl_2_bss_F468._61[index];
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._14[index][i] == prev) {
            found = i;
        }
    }
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        if (prev != lbl_2_bss_F468._00[index]) {
            lbl_80371C30[0x46 + task->_14 + prev + index * 9]._00->_68 = 4;
            if (lbl_803C6724._02[index][found] != -1 && lbl_803C6724._02[index][found] != 0x36) {
                lbl_80371C30[0x34 + task->_14 + prev + index * 9]._00->_68 = 1;
            }
        }
        if (lbl_2_bss_F468._37[index]) {
            lbl_80371C30[0x93 + task->_14 + index]._00->_64 = 9;
            lbl_80371C30[0x93 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x93 + task->_14 + index]._00->_68 = 0;
        }
        fn_800626EC(index);
        lbl_803C66B0._0D[index] = 1;
    }
    if (lbl_803C66B0._0D[index] == 1) {
        n = 0;
        expected = 0;
        if (lbl_2_bss_F468._61[index] != lbl_2_bss_F468._00[index] && lbl_803C6724._02[index][found] != -1 &&
            lbl_803C6724._02[index][found] != 0x36)
        {
            expected++;
            n += isAnimDone(task, 0x34 + prev + index * 9, 20);
        }
        if (n == expected) {
            lbl_2_bss_F468._5F[index] = 0;
            lbl_2_bss_F468._61[index] = -1;
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00078034 size:0x28
void fn_2_78034(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x000776A0 size:0x994
void fn_2_776A0(UnkTask0C50* task, s32 index) {
    s32 idx = lbl_803C66B0._59[index];
    u16 buttons = lbl_8034E9A0._472E[index][0];
    s8 sel;
    s32 n;
    s32 i;

    if (lbl_803C66B0._00[0] == 2 && lbl_2_bss_F468._45[idx] == 0) {
        if (lbl_2_bss_F468._41[idx] == 0) {
            if (lbl_2_bss_F468._00[idx + 2] != lbl_2_bss_F468._00[idx]) {
                fn_2_74F40(task, idx);
            }
        } else if (lbl_2_bss_F468._20[idx] != lbl_2_bss_F410._20[idx]) {
            fn_2_74F40(task, idx);
        }
    }
    if ((buttons & 0x800) && lbl_803CBBCC->_2 == 10 && lbl_2_bss_F468._52[idx] != 0 &&
        g_d_GameSettings.GameModeSelected != 5 && lbl_2_bss_F468._54[idx] == 0)
    {
        if (lbl_803C66B0._55[idx]) {
            fn_80062674(idx);
            lbl_803C66B0._0D[idx] = 2;
        } else {
            if (g_d_GameSettings._10 == 0 && idx != 0) {
                lbl_803C66B0._5D[idx] = 0;
            }
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        }
        for (i = 0; i < 9; i++) {
            if (lbl_8034E9A0._46E0[idx] == lbl_803C6724._02[idx][i]) {
                sel = lbl_803C6724._14[idx][i];
                break;
            }
        }
        for (i = 0; i < 9; i++) {
            if (i != sel) {
                lbl_80371C30[0x34 + task->_14 + i + idx * 9]._00->_68 = 4;
            }
        }
        lbl_80371C30[0x34 + task->_14 + sel + idx * 9]._00->_68 = 1;
        fn_2_75BE4(task, idx);
        lbl_80371C30[0x91 + task->_14 + idx]._00->_68 = 1;
        if (lbl_2_bss_F468._00[idx + 2] == 9) {
            lbl_80371C30[0x93 + task->_14 + idx]._00->_68 = 4;
            lbl_80371C30[0x95 + task->_14 + index]._00->_5C = 0xA0000;
            lbl_80371C30[0x95 + task->_14 + idx]._00->_68 = 4;
        } else if (lbl_2_bss_F468._00[idx + 2] == 10) {
            lbl_80371C30[0x93 + task->_14 + idx]._00->_68 = 4;
        } else {
            s32 prev = lbl_2_bss_F468._00[idx + 2];

            lbl_80371C30[0x46 + task->_14 + prev + idx * 9]._00->_5C = 0xF0000;
            lbl_80371C30[0x46 + task->_14 + prev + idx * 9]._00->_68 = 4;
            lbl_80371C30[0x93 + task->_14 + idx]._00->_68 = 4;
        }
        for (i = 0; i < 9; i++) {
            lbl_80371C30[0x97 + task->_14 + idx]._00->_54 &= ~2;
            lbl_80371C30[0xAC + task->_14 + idx]._00->_54 &= ~2;
            lbl_80371C30[0x22 + task->_14 + i + idx * 9]._00->_54 &= ~2;
        }
        lbl_2_bss_F468._54[idx] = 1;
    }
    if (lbl_803C66B0._00[0] == 2 && lbl_2_bss_F468._45[idx] == 0 && lbl_2_bss_F468._50[idx] != 0) {
        s32 cur = lbl_2_bss_F468._00[idx];

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[idx][i] == cur) {
                break;
            }
        }
        lbl_80371C30[0x58 + task->_14 + cur + idx * 9]._00->_5C = lbl_803C6724._02[idx][i] << 16;
        fn_2_74F40(task, idx);
        lbl_2_bss_F468._50[idx] = 0;
    }
    if (lbl_2_bss_F468._54[idx]) {
        for (i = 0; i < 9; i++) {
            if (lbl_8034E9A0._46E0[idx] == lbl_803C6724._02[idx][i]) {
                sel = lbl_803C6724._14[idx][i];
                break;
            }
        }
        if (isAnimDone(task, 0x34 + sel + idx * 9, 20) == TRUE) {
            lbl_2_bss_F468._54[idx] = 0;
            lbl_2_bss_F468._52[idx] = 0;
        }
    }
    if (lbl_2_bss_F468._4B[idx]) {
        if (lbl_2_bss_F468._45[idx]) {
            switch (lbl_2_bss_F468._47[idx]) {
            case 0:
                fn_2_76DF0(task, idx);
                break;
            case 1:
                fn_2_76874(task, idx);
                break;
            }
        } else {
            if (lbl_2_bss_F468._47[idx] == 0) {
                if ((lbl_80371C30[0xB4 + task->_14 + idx]._00->_5C >> 16) > 5) {
                    lbl_80371C30[0xB4 + task->_14 + idx]._00->_5C = 0x50000;
                }
                lbl_80371C30[0xB4 + task->_14 + idx]._00->_68 = 4;
                lbl_80371C30[0xB6 + task->_14 + idx]._00->_68 = 4;
                lbl_80371C30[0xC6 + task->_14 + idx]._00->_68 = 4;
                n = isAnimDone(task, idx + 0xB4, 0);
                n += isAnimDone(task, idx + 0xB6, 0);
                n += isAnimDone(task, idx + 0xC6, 0);
                if (n == 3) {
                    lbl_2_bss_F468._4B[idx] = 0;
                }
            } else {
                if ((lbl_80371C30[0xB4 + task->_14 + idx]._00->_5C >> 16) > 5) {
                    lbl_80371C30[0xB4 + task->_14 + idx]._00->_5C = 0x50000;
                }
                lbl_80371C30[0xB4 + task->_14 + idx]._00->_68 = 4;
                lbl_80371C30[0xE2 + task->_14 + idx]._00->_68 = 4;
                if (isAnimDone(task, idx + 0xE2, 0) == TRUE) {
                    lbl_2_bss_F468._4B[idx] = 0;
                }
            }
            lbl_2_bss_F468._49[idx] = 0;
        }
    }
}

// .text:0x00076DF0 size:0x8B0
// The (s32) casts keep MWCC from reusing the promoted index for lbl_2_bss_F410, as the
// target does here and in fn_2_76874.
void fn_2_76DF0(UnkTask0C50* task, u8 index) {
    s32 id;
    s32 j;
    u32 pos;
    u8 a;
    u8 b;
    u32 mask;
    u8 c;

    if (lbl_2_bss_F468._49[index] == 0) {
        if (lbl_803CBBCC->_2 == 9) {
            if (g_d_GameSettings.GameModeSelected != 5) {
                id = lbl_800FE5D4[lbl_2_bss_F410._10[(s32)index]];
            } else {
                id = lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[(s32)index]];
            }
        } else {
            if (lbl_2_bss_F468._41[index] == 0) {
                s32 sel = lbl_2_bss_F468._00[index];

                for (j = 0; j < 9; j++) {
                    if (lbl_803C6724._14[index][j] == sel) {
                        break;
                    }
                }
                id = lbl_803C6724._02[index][j];
            } else {
                id = lbl_2_bss_F410._20[(s32)index];
                if (id == -1) {
                    lbl_2_bss_F468._49[index] = 0;
                    return;
                }
            }
            lbl_2_bss_F468._4D[index] = id;
        }
        pos = id << 16;
        mask = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._00;
        a = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._0D;
        b = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._0E;
        c = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._07;
        lbl_80371C30[0xB4 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xCA + task->_14 + index]._00->_5C = pos;
        lbl_80371C30[0xCC + task->_14 + index]._00->_5C = fn_80064918(id) << 16;
        lbl_80371C30[0xC6 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xDE + task->_14 + index]._00->_5C = pos;
        fn_2_76650(task, index, mask);
        lbl_80371C30[0xD2 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xD4 + task->_14 + index]._00->_5C = 0x10000;
        lbl_80371C30[0xD6 + task->_14 + index]._00->_5C = 0x20000;
        lbl_80371C30[0xD8 + task->_14 + index]._00->_5C = 0x30000;
        lbl_80371C30[0xDA + task->_14 + index]._00->_5C = 0x40000;
        lbl_80371C30[0xDC + task->_14 + index]._00->_5C = 0x50000;
        lbl_80371C30[0xBA + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xBC + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xBE + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xC0 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xC2 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xC4 + task->_14 + index]._00->_5C = 0;
        switch (a) {
        case 0:
            lbl_80371C30[0xBA + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0xBC + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0xBE + task->_14 + index]._00->_68 = 0;
            break;
        case 1:
            if (c == 0) {
                lbl_80371C30[0xBA + task->_14 + index]._00->_68 = 0;
                lbl_80371C30[0xBC + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0xBE + task->_14 + index]._00->_68 = 0;
            } else {
                lbl_80371C30[0xBA + task->_14 + index]._00->_68 = 0;
                lbl_80371C30[0xBC + task->_14 + index]._00->_68 = 0;
                lbl_80371C30[0xBE + task->_14 + index]._00->_68 = 1;
            }
            break;
        case 2:
            if (c == 0) {
                lbl_80371C30[0xBA + task->_14 + index]._00->_68 = 0;
                lbl_80371C30[0xBC + task->_14 + index]._00->_68 = 0;
                lbl_80371C30[0xBE + task->_14 + index]._00->_68 = 1;
            } else {
                lbl_80371C30[0xBA + task->_14 + index]._00->_68 = 0;
                lbl_80371C30[0xBC + task->_14 + index]._00->_68 = 1;
                lbl_80371C30[0xBE + task->_14 + index]._00->_68 = 0;
            }
            break;
        }
        switch (b) {
        case 0:
            lbl_80371C30[0xC0 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0xC2 + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0xC4 + task->_14 + index]._00->_68 = 0;
            break;
        case 1:
            lbl_80371C30[0xC0 + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0xC2 + task->_14 + index]._00->_68 = 1;
            lbl_80371C30[0xC4 + task->_14 + index]._00->_68 = 0;
            break;
        case 2:
            lbl_80371C30[0xC0 + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0xC2 + task->_14 + index]._00->_68 = 0;
            lbl_80371C30[0xC4 + task->_14 + index]._00->_68 = 1;
            break;
        }
        lbl_80371C30[0xE0 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xE0 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xB6 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xC6 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xC6 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xEA + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xEA + task->_14 + index]._00->_68 = 0;
        lbl_80371C30[0xE2 + task->_14 + index]._00->_68 = 4;
        lbl_2_bss_F468._49[index] = 1;
    }
    if (lbl_803CBBCC->_2 == 10 && lbl_2_bss_F468._41[index] != 0 &&
        lbl_2_bss_F468._4D[index] != lbl_2_bss_F410._20[(s32)index])
    {
        fn_2_74F40(task, index);
        lbl_2_bss_F468._49[index] = 0;
    }
}

// .text:0x00076874 size:0x57C
void fn_2_76874(UnkTask0C50* task, u8 index) {
    s32 id;
    s32 j;
    s32 star;
    u32 kind;
    u8 swing;
    u8 pitch;
    s8 hit;
    s16 swingId;
    s16 pitchId;

    if (lbl_2_bss_F468._49[index] == 0) {
        lbl_80371C30[0xE0 + task->_14 + index]._00->_54 &= ~2;
        lbl_80371C30[0xE0 + task->_14 + index]._00->_68 = 0;
        lbl_80371C30[0xB6 + task->_14 + index]._00->_68 = 4;
        lbl_80371C30[0xC6 + task->_14 + index]._00->_68 = 4;
        if (lbl_803CBBCC->_2 == 9) {
            if (g_d_GameSettings.GameModeSelected != 5) {
                id = lbl_800FE5D4[lbl_2_bss_F410._10[index]];
            } else {
                id = lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[index]];
            }
        } else if (lbl_2_bss_F468._41[index] == 0) {
            s32 sel = lbl_2_bss_F468._00[index];

            for (j = 0; j < 9; j++) {
                if (lbl_803C6724._14[index][j] == sel) {
                    break;
                }
            }
            id = lbl_803C6724._02[index][j];
        } else {
            id = lbl_2_bss_F410._20[index];
            if (id == -1) {
                lbl_2_bss_F468._49[index] = 0;
                return;
            }
        }
        lbl_2_bss_F468._4D[index] = id;
        kind = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._14;
        if (kind == 0) {
            swing = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._15 + 11;
            pitch = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._16 + 11;
        } else if (g_d_GameSettings.GameModeSelected != 5) {
            swing = kind - 1;
            pitch = swing;
        } else {
            star = kind - 1;
            hit = translateStarPitchHitIndex(star);
            if (hit != -1 && starMissionCompletionTracker._15F1[hit] == 0 && lbl_803CBBCC->_2 == 9) {
                swing = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._15 + 11;
                pitch = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._16 + 11;
            } else if (hit != -1 && starMissionCompletionTracker._43C2[hit] == 0 && lbl_803CBBCC->_2 == 10) {
                swing = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._15 + 11;
                pitch = lbl_8034E9A0._0020[(s8)(id / 9)][(s8)(id % 9)]._16 + 11;
            } else {
                swing = star;
                pitch = kind - 1;
            }
        }
        swingId = translateStarSwing(swing);
        pitchId = translateStarPitch(pitch);
        lbl_80371C30[0xE6 + task->_14 + index]._00->_64 = swingId;
        lbl_80371C30[0xE6 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xE6 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xE8 + task->_14 + index]._00->_64 = pitchId;
        lbl_80371C30[0xE8 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xE8 + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xEA + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xEA + task->_14 + index]._00->_68 = 1;
        lbl_80371C30[0xE2 + task->_14 + index]._00->_68 = 1;
        lbl_2_bss_F468._49[index] = 1;
    }
    // The cast keeps MWCC from reusing the promoted index here, as the target does.
    if (lbl_803CBBCC->_2 == 10 && lbl_2_bss_F468._41[index] != 0 &&
        lbl_2_bss_F468._4D[index] != lbl_2_bss_F410._20[(s32)index])
    {
        fn_2_74F40(task, index);
        lbl_2_bss_F468._49[index] = 0;
    }
}

// .text:0x00076650 size:0x224
void fn_2_76650(UnkTask0C50* task, u8 index, u32 mask) {
    s32 values[2];
    s32 n;
    s32 i;

    memset(values, -1, 2);
    for (i = 0, n = 0; i < 14; i++) {
        if (mask & (1 << i)) {
            switch (i) {
            case 0:
                i++;
                break;
            case 1:
                values[n++] = 1;
                break;
            case 2:
                values[n++] = 2;
                break;
            case 3:
                values[n++] = 3;
                break;
            case 4:
                values[n++] = 4;
                break;
            case 5:
                values[n++] = 5;
                break;
            case 6:
                values[n++] = 6;
                break;
            case 7:
                values[n++] = 7;
                break;
            case 8:
                values[n++] = 8;
                break;
            case 9:
                values[n++] = 9;
                break;
            case 10:
                values[n++] = 10;
                break;
            case 11:
                values[n++] = 11;
                break;
            case 12:
                values[n++] = 12;
                break;
            default:
                values[n++] = 13;
                break;
            }
        }
    }
    for (i = 0; i < 2; i++) {
        values[i]--;
    }
    for (i = 0; i < 2; i++) {
        if (values[i] < 0) {
            values[i] = 12;
        }
    }
    lbl_80371C30[0xCE + task->_14 + index]._00->_5C = values[0] << 16;
    lbl_80371C30[0xD0 + task->_14 + index]._00->_5C = values[1] << 16;
}

// .text:0x0007664C size:0x4
void fn_2_7664C(void) {
}

// .text:0x0007630C size:0x340
void fn_2_7630C(UnkTask0C50* task, u8 index) {
    u8 slot;
    s32 a;
    s32 b;
    u8 c;
    u8 d;

    if (g_d_GameSettings._10 == 0) {
        slot = lbl_803C66B0._59[0];
    } else {
        slot = lbl_803C66B0._59[index];
    }
    a = lbl_800FE5D4[lbl_2_bss_F410._10[slot]];
    b = lbl_800FE5D4[lbl_803C6724._00[slot]];
    c = lbl_8034E9A0._0020[a / 9][a % 9]._14;
    d = lbl_8034E9A0._0020[b / 9][b % 9]._14;
    lbl_80371C30[0x82 + task->_14 + slot]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    lbl_80371C30[0x85 + task->_14 + slot]._00->_5C = 0xA0000;
    lbl_80371C30[0x87 + task->_14 + slot]._00->_5C = 0xA0000;
    lbl_80371C30[0x85 + task->_14 + slot]._00->_68 = 0;
    lbl_80371C30[0x87 + task->_14 + slot]._00->_68 = 0;
    fn_800363D8(task, slot + 0x89, 1, 3, lbl_2_data_2B3A4[c]);
    fn_800363D8(task, slot + 0x8B, 1, 3, lbl_2_data_2B3A4[d]);
    lbl_80371C30[0x7E + task->_14 + slot]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    lbl_80371C30[0x1A + task->_14 + slot]._00->_54 |= 2;
    lbl_80371C30[0x1A + task->_14 + slot]._00->_68 = 1;
    lbl_80371C30[0x80 + task->_14 + slot]._00->_5C = 0;
    lbl_80371C30[0x89 + task->_14 + slot]._00->_5C = 0;
    lbl_80371C30[0x8B + task->_14 + slot]._00->_5C = 0xA0000;
    lbl_80371C30[0x78 + task->_14 + slot]._00->_5C = 0;
    lbl_80371C30[0x7C + task->_14 + slot]._00->_5C = 0;
    lbl_80371C30[0x80 + task->_14 + slot]._00->_68 = 1;
    lbl_80371C30[0x89 + task->_14 + slot]._00->_68 = 1;
    lbl_80371C30[0x8B + task->_14 + slot]._00->_68 = 4;
    lbl_80371C30[0x78 + task->_14 + slot]._00->_68 = 1;
    lbl_80371C30[0x7C + task->_14 + slot]._00->_68 = 1;
}

// .text:0x000760CC size:0x240
void fn_2_760CC(UnkTask0C50* task) {
    s32 a = lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[0]];
    s32 b = lbl_800FE930[lbl_80361B20._F4][lbl_803C6724._00[0]];
    u8 c = lbl_8034E9A0._0020[a / 9][a % 9]._14;
    u8 d = lbl_8034E9A0._0020[b / 9][b % 9]._14;

    lbl_80371C30[task->_14 + 0x82]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    fn_800363D8(task, 0x89, 1, 3, lbl_2_data_2B3A4[c]);
    fn_800363D8(task, 0x8B, 1, 3, lbl_2_data_2B3A4[d]);
    lbl_80371C30[task->_14 + 0x7E]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    lbl_80371C30[task->_14 + 0x80]._00->_5C = 0;
    lbl_80371C30[task->_14 + 0x89]._00->_5C = 0;
    lbl_80371C30[task->_14 + 0x8B]._00->_5C = 0xA0000;
    lbl_80371C30[task->_14 + 0x78]._00->_5C = 0;
    lbl_80371C30[task->_14 + 0x7C]._00->_5C = 0;
    lbl_80371C30[task->_14 + 0x80]._00->_68 = 1;
    lbl_80371C30[task->_14 + 0x89]._00->_68 = 1;
    lbl_80371C30[task->_14 + 0x8B]._00->_68 = 4;
    lbl_80371C30[task->_14 + 0x78]._00->_68 = 1;
    lbl_80371C30[task->_14 + 0x7C]._00->_68 = 1;
}

// .text:0x0007609C size:0x30
void fn_2_7609C(UnkTask0C50* task, u8 flag, u8 skip) {
    if (!skip) {
        fn_2_8794(flag, 0);
    }
}

// .text:0x00076098 size:0x4
void fn_2_76098(void) {
}

// .text:0x00075BE4 size:0x4B4
void fn_2_75BE4(UnkTask0C50* task, s32 index) {
    s32 level;
    s32 i;
    s32 sum = 0;
    s32 avg = 0;
    s32 count = 0;

    level = 0;
    for (i = 0; i < 9; i++) {
        if (lbl_803C6724._26[index][i] != 0 && lbl_803C6724._02[index][i] != lbl_8034E9A0._46E0[index]) {
            sum += lbl_803C6724._26[index][i];
            count++;
        }
    }
    if (count != 0) {
        avg = sum / count;
    }
    if (avg >= 70) {
        level = 5;
    } else if (avg <= 69 && avg >= 55) {
        level = 4;
    } else if (avg <= 54 && avg >= 35) {
        level = 3;
    } else if (avg <= 34 && avg >= 15) {
        level = 2;
    } else if (avg <= 14 && avg > 0) {
        level = 1;
    }
    lbl_8034E9A0._470F[index] = level;
    for (i = 0; i < 5; i++) {
        if (lbl_80371C30[0x6E + task->_14 + i + index * 5]._00->_5C >> 16 == 30) {
            lbl_80371C30[0x6E + task->_14 + i + index * 5]._00->_68 = 1;
        }
    }
    for (i = 0; i < level; i++) {
        lbl_80371C30[0x6E + task->_14 + i + index * 5]._00->_5C = 0;
        lbl_80371C30[0x6E + task->_14 + i + index * 5]._00->_68 = 1;
    }
}

// .text:0x00075B58 size:0x8C
u8 fn_2_75B58(UnkTask0C50* task, s32 index) {
    s32 i;
    u8 count = lbl_8034E9A0._470F[index];
    s32 hits = 0;
    s32 total = 0;

    for (i = 0; i < count; i++) {
        total++;
        hits += fn_80042DA8(task, 0x6E + i + index * 5, 0x1E) != 0;
    }
    return hits == total;
}

// .text:0x00074F40 size:0xC18
void fn_2_74F40(UnkTask0C50* task, s32 index) {
    s32 id;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s8 kind;
    s32 i;

    if (lbl_803CBBCC->_2 == 9 || lbl_803C66B0._5D[index] == 11) {
        if (g_d_GameSettings.GameModeSelected != 5) {
            id = lbl_800FE5D4[lbl_2_bss_F410._10[index]];
        } else {
            id = lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[0]];
        }
        a = lbl_8034E9A0._0020[id / 9][id % 9]._18;
        b = lbl_8034E9A0._0020[id / 9][id % 9]._17;
        c = lbl_8034E9A0._0020[id / 9][id % 9]._19;
        d = lbl_8034E9A0._0020[id / 9][id % 9]._1A;
        fn_2_74E14(task, index, a, 1);
        fn_2_74E14(task, index, c, 3);
        fn_2_74E14(task, index, b, 0);
        fn_2_74E14(task, index, d, 2);
        lbl_80371C30[0xAE + task->_14 + index]._00->_54 &= ~2;
        return;
    }
    if (lbl_2_bss_F468._41[index]) {
        id = lbl_2_bss_F410._20[index];
        lbl_80371C30[0xB2 + task->_14 + index]._00->_54 &= ~2;
    } else if (lbl_2_bss_F468._00[index] != 9 && lbl_2_bss_F468._00[index] != 10) {
        s8 cur = lbl_2_bss_F468._00[index];

        for (i = 0; i < 9; i++) {
            if (lbl_803C6724._14[index][i] == cur) {
                id = lbl_803C6724._02[index][i];
            }
        }
    } else {
        id = -1;
    }
    if (id != -1 && fn_80067B40(0, id, 2) && g_d_GameSettings.GameModeSelected != 5) {
        lbl_80371C30[0xB2 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xB2 + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xB2 + task->_14 + index]._00->_68 = 1;
        kind = fn_2_74DB8(id);
        lbl_80371C30[0xAE + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xAE + task->_14 + index]._00->_5C = kind << 16;
    } else {
        lbl_80371C30[0xB2 + task->_14 + index]._00->_54 &= ~2;
        if (lbl_2_bss_F468._00[index] != 9 && lbl_2_bss_F468._00[index] != 10) {
            lbl_80371C30[0xAE + task->_14 + index]._00->_54 |= 2;
            lbl_80371C30[0xAE + task->_14 + index]._00->_5C = 0;
        }
    }
    lbl_80371C30[0xAC + task->_14 + index]._00->_54 |= 2;
    if (id >= 0 && id < 54) {
        b = lbl_8034E9A0._0020[id / 9][id % 9]._17;
        c = lbl_8034E9A0._0020[id / 9][id % 9]._19;
        a = lbl_8034E9A0._0020[id / 9][id % 9]._18;
        d = lbl_8034E9A0._0020[id / 9][id % 9]._1A;
        lbl_80371C30[0xB0 + task->_14 + index]._00->_54 |= 2;
        lbl_80371C30[0xB0 + task->_14 + index]._00->_5C = id << 16;
        lbl_80371C30[0xAC + task->_14 + index]._00->_5C = 0;
        lbl_80371C30[0xAC + task->_14 + index]._00->_68 = 1;
    } else {
        b = c = a = d = 0;
        lbl_80371C30[0xB0 + task->_14 + index]._00->_54 &= ~2;
    }
    if (id >= 0 && id < 54) {
        fn_2_74E14(task, index, a, 1);
        fn_2_74E14(task, index, c, 3);
        fn_2_74E14(task, index, b, 0);
        fn_2_74E14(task, index, d, 2);
    } else {
        lbl_80371C30[0x97 + task->_14 + index]._00->_54 &= ~2;
    }
}

// .text:0x00074E14 size:0x12C
void fn_2_74E14(UnkTask0C50* task, s32 index, s32 count, u8 sel) {
    s32 value;

    lbl_80371C30[0x97 + task->_14 + index]._00->_54 |= 2;
    lbl_80371C30[0x97 + task->_14 + index]._00->_5C = 0;
    lbl_80371C30[0x97 + task->_14 + index]._00->_68 = 1;
    lbl_80371C30[0x9B + task->_14 + sel + index * 4]._00->_5C = (count - 1) << 16;
    value = fn_80036214(task, 0xAB, 0, (count + 1) / 2 - 1);
    lbl_80371C30[0xA3 + task->_14 + sel + index * 4]._00->_5C = (count - 1) << 16;
    lbl_80371C30[0xA3 + task->_14 + sel + index * 4]._00->_58 = value;
}

// .text:0x00074DB8 size:0x5C
s32 fn_2_74DB8(s32 arg0) {
    switch (arg0) {
    case 0xD:
    case 0x10:
    case 0x14:
    case 0x16:
    case 0x19:
    case 0x22:
    case 0x2A:
    case 0x32:
    case 0x34:
        return 1;
    case 0x15:
    case 0x18:
    case 0x1D:
    case 0x21:
    case 0x2C:
    case 0x33:
    case 0x35:
        return 2;
    case 0x17:
    case 0x1E:
    case 0x24:
    case 0x2D:
        return 3;
    case 0xC:
    case 0x1A:
    case 0x1B:
    case 0x1F:
    case 0x23:
    case 0x2B:
    case 0x2E:
    case 0x31:
        return 4;
    case 0x20:
        return 5;
    case 0x2F:
        return 6;
    default:
        return 0;
    }
}

// .text:0x00074D8C size:0x2C
void fn_2_74D8C(void) {
    fn_800B0A5C_insertQueue(fn_2_74CD8, 0x1000);
}

// .text:0x00074CD8 size:0xB4
void fn_2_74CD8(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2D33C);
    for (i = 0; i < 7; i++) {
        fn_800363D8(task, i + 0x18, 1, 0x36, i);
    }
    fn_800363D8(task, 0x20, 1, 0x32, 0);
    lbl_2_bss_A840 = lbl_2_bss_F410._00;
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_747FC;
}

// .text:0x000747FC size:0x4DC
// 98.97%: the target reads lbl_2_bss_A844 through addi and lwz 0 and loads the 0 for _4751
// earlier; an array type for lbl_2_bss_A844 compiles the same.
void fn_2_747FC(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 sel = lbl_2_bss_F410._00;
    s32 id;

    if (lbl_8034E9A0._472A == 0) {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        lbl_8034E9A0._472A = 0xFF;
        return;
    }
    switch (lbl_803C66B0._5D[0]) {
    case 0x54:
        fn_2_7463C(task);
        fn_2_74564(task);
        break;
    case 0x55:
        if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
            fn_800626EC(0);
            lbl_803C66B0._07 = 1;
        }
        if (lbl_803C66B0._07 == 1) {
            fn_80062674(0);
            lbl_803C66B0._07 = 2;
        }
        break;
    case 0x56:
        fn_2_73EFC(task);
        fn_2_73CBC(task);
        break;
    case 0x57:
        if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
            id = sel + 0x11;
            lbl_80371C30[task->_14 + id]._00->_5C = 0xE0000;
            lbl_80371C30[task->_14 + id]._00->_68 = 1;
            lbl_803C66B0._07 = 1;
        }
        if (lbl_803C66B0._07 == 1) {
            if (lbl_8034E9A0._472C == 0 && lbl_8034E9A0._4751 != 0) {
                lbl_8034E9A0._4752 = 1;
                if (lbl_2_bss_F410._00 != lbl_2_bss_F410._04) {
                    fn_800625A4(0, 0x56);
                }
                lbl_8034E9A0._4751 = 0;
                lbl_2_bss_A840 = lbl_2_bss_A844[0];
            } else {
                id = sel + 0x11;
                if (isAnimDone(task, id, 0x37) == TRUE) {
                    lbl_80371C30[task->_14 + id]._00->_5C = 0xE0000;
                    lbl_80371C30[task->_14 + id]._00->_68 = 1;
                }
            }
        }
        break;
    case 0x58:
        if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
            lbl_80371C30[0x11 + task->_14 + sel]._00->_5C = 0x370000;
            lbl_80371C30[0x11 + task->_14 + sel]._00->_68 = 1;
            fn_800626EC(0);
            lbl_803C66B0._07 = 1;
        }
        if (lbl_803C66B0._07 == 1) {
            if (isAnimDone(task, sel + 0x11, 0x41) == TRUE) {
                fn_80062674(0);
                lbl_803C66B0._07 = 2;
            }
        }
        break;
    }
}

// .text:0x0007463C size:0x1C0
void fn_2_7463C(UnkTask0C50* task) {
    s32 i;
    s32 sel;

    sel = lbl_2_bss_F410._00;
    if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
        for (i = 0; i < 7; i++) {
            if (sel == i) {
                lbl_80371C30[3 + task->_14 + i]._00->_54 |= 2;
                lbl_80371C30[3 + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[3 + task->_14 + i]._00->_68 = 1;
                lbl_80371C30[0x18 + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[0x18 + task->_14 + i]._00->_68 = 1;
            } else {
                lbl_80371C30[0x18 + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[0x18 + task->_14 + i]._00->_68 = 0;
                lbl_80371C30[3 + task->_14 + i]._00->_54 &= ~2;
            }
        }
        if (lbl_8037169C._10) {
            changeScene(1, 6);
        }
        lbl_80371C30[task->_14 + 0x20]._00->_5C = 0;
        lbl_80371C30[task->_14 + 0x20]._00->_68 = 1;
        fn_800626EC(0);
        lbl_803C66B0._07 = 1;
    }
}

// .text:0x00074564 size:0xD8
void fn_2_74564(UnkTask0C50* task) {
    s32 i;
    s32 n;
    s32 expected;
    s32 sel;

    sel = lbl_2_bss_F410._00;
    if (lbl_803C66B0._07 == 1 ? TRUE : FALSE) {
        n = 0;
        expected = 0;
        for (i = 0; i < 7; i++) {
            if (sel == i) {
                expected++;
                n += isAnimDone(task, i + 3, 14);
            }
        }
        n += isAnimDone(task, 0x20, 10);
        if (n == expected + 1) {
            fn_80062674(0);
            lbl_803C66B0._07 = 2;
            fn_800625A4(0, 0x57);
        }
    }
}

// .text:0x00074518 size:0x4C
void fn_2_74518(void) {
    if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
        fn_800626EC(0);
        lbl_803C66B0._07 = 1;
    }
}

// .text:0x000744C8 size:0x50
void fn_2_744C8(void) {
    if (lbl_803C66B0._07 == 1 ? TRUE : FALSE) {
        fn_80062674(0);
        lbl_803C66B0._07 = 2;
    }
}

// .text:0x00073EFC size:0x5CC
void fn_2_73EFC(UnkTask0C50* task) {
    s32 i;
    s32 sel;
    s32 prev;

    sel = lbl_2_bss_F410._00;
    prev = lbl_2_bss_F410._04;
    if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
        for (i = 0; i < 7; i++) {
            if (lbl_8034E9A0._472E[0][0] == 0 && lbl_8034E9A0._472E[0][1] != 0) {
                lbl_8034E9A0._4751 = 1;
                if (sel == i) {
                    lbl_80371C30[3 + task->_14 + i]._00->_54 |= 2;
                    lbl_80371C30[3 + task->_14 + i]._00->_5C = 0xE0000;
                    lbl_80371C30[3 + task->_14 + i]._00->_68 = 0;
                } else {
                    lbl_80371C30[3 + task->_14 + i]._00->_54 &= ~2;
                }
                lbl_80371C30[task->_14 + 0x20]._00->_5C = 0xA0000;
                lbl_80371C30[task->_14 + 0x21]._00->_5C = 0;
                fn_800363D8(task, 0x20, 1, 0x32, sel);
                fn_800363D8(task, 0x21, 1, 0x32, prev);
                lbl_80371C30[task->_14 + 0x20]._00->_68 = 0;
                lbl_80371C30[task->_14 + 0x21]._00->_68 = 0;
            } else {
                s32 frame;
                s32 mode;

                lbl_8034E9A0._4751 = 0;
                frame = fn_2_73BF0(sel);
                mode = fn_2_73B54(sel);
                if (sel == i) {
                    lbl_80371C30[3 + task->_14 + i]._00->_54 |= 2;
                    lbl_80371C30[3 + task->_14 + i]._00->_5C = frame << 16;
                    lbl_80371C30[3 + task->_14 + i]._00->_68 = mode;
                } else {
                    lbl_80371C30[3 + task->_14 + i]._00->_54 &= ~2;
                }
                if (lbl_2_bss_A840 == 0 && sel == 6 && i == lbl_2_bss_A840) {
                    lbl_80371C30[3 + task->_14 + i]._00->_54 |= 2;
                    lbl_80371C30[3 + task->_14 + i]._00->_5C = 0x80000;
                    lbl_80371C30[3 + task->_14 + i]._00->_68 = 4;
                } else if (lbl_2_bss_A840 == 6 && sel == 0 && i == lbl_2_bss_A840) {
                    lbl_80371C30[3 + task->_14 + i]._00->_54 |= 2;
                    lbl_80371C30[3 + task->_14 + i]._00->_5C = 0x2D0000;
                    lbl_80371C30[3 + task->_14 + i]._00->_68 = 1;
                }
                lbl_80371C30[task->_14 + 0x20]._00->_5C = 0;
                lbl_80371C30[task->_14 + 0x21]._00->_5C = 0xA0000;
                fn_800363D8(task, 0x20, 1, 0x32, sel);
                fn_800363D8(task, 0x21, 1, 0x32, prev);
                lbl_80371C30[task->_14 + 0x20]._00->_68 = 1;
                lbl_80371C30[task->_14 + 0x21]._00->_68 = 1;
            }
        }
        lbl_80371C30[0x18 + task->_14 + sel]._00->_5C = 0;
        lbl_80371C30[0x18 + task->_14 + sel]._00->_68 = 1;
        lbl_80371C30[0x18 + task->_14 + prev]._00->_5C = 0;
        lbl_80371C30[0x18 + task->_14 + prev]._00->_68 = 0;
        if (lbl_8034E9A0._4751 == 0) {
            lbl_80371C30[0x11 + task->_14 + sel]._00->_5C = 0;
            lbl_80371C30[0x11 + task->_14 + sel]._00->_68 = 1;
        } else {
            lbl_80371C30[0x11 + task->_14 + sel]._00->_5C = 0;
            lbl_80371C30[0x11 + task->_14 + sel]._00->_68 = 0;
        }
        if (lbl_8034E9A0._4751 == 0) {
            fn_800626EC(0);
        }
        lbl_803C66B0._07 = 1;
    }
}

// .text:0x00073CBC size:0x240
void fn_2_73CBC(UnkTask0C50* task) {
    s32 i;
    s32 n;
    s32 expected;
    s32 sel;

    sel = lbl_2_bss_F410._00;
    if (lbl_803C66B0._07 == 1 ? TRUE : FALSE) {
        n = 0;
        expected = 0;
        if (lbl_8034E9A0._4751 == 0) {
            for (i = 0; i < 7; i++) {
                s32 value = fn_2_73B94(sel);

                if (lbl_2_bss_F410._00 == i) {
                    expected++;
                    n += isAnimDone(task, i + 3, value);
                }
                if (lbl_2_bss_A840 == 0 && sel == 6 && i == lbl_2_bss_A840) {
                    expected++;
                    n += isAnimDone(task, i + 3, 0);
                } else if (lbl_2_bss_A840 == 6 && sel == 0 && i == lbl_2_bss_A840) {
                    expected++;
                    n += isAnimDone(task, i + 3, 0x36);
                }
            }
            n += isAnimDone(task, sel + 0x11, 14);
            expected += 2;
            n += isAnimDone(task, 0x20, 10);
        }
        if (n == expected) {
            if (lbl_8034E9A0._4751) {
                lbl_2_bss_A844[0] = lbl_2_bss_A840;
            }
            lbl_2_bss_A840 = sel;
            lbl_8034E9A0._4752 = 0;
            if (lbl_8034E9A0._4751 == 0) {
                fn_80062674(0);
            }
            lbl_803C66B0._07 = 2;
            fn_800625A4(0, 0x57);
        }
    }
}

// .text:0x00073BF0 size:0xCC
s32 fn_2_73BF0(s32 arg0) {
    s32 ret;

    if (lbl_2_bss_A840 == 0 && arg0 == 6) {
        if (lbl_8034E9A0._4752) {
            ret = 54;
        } else {
            ret = 54;
        }
    } else if (lbl_2_bss_A840 == 6 && arg0 == 0) {
        if (lbl_8034E9A0._4752) {
            ret = 8;
        } else {
            ret = 0;
        }
    } else if (lbl_2_bss_A840 <= arg0) {
        if (lbl_8034E9A0._4752) {
            ret = 23;
        } else {
            ret = 15;
        }
    } else if (lbl_2_bss_A840 > arg0) {
        if (lbl_8034E9A0._4752) {
            ret = 38;
        } else {
            ret = 30;
        }
    }
    return ret;
}

// .text:0x00073B94 size:0x5C
s32 fn_2_73B94(s32 arg0) {
    if (lbl_2_bss_A840 == 0 && arg0 == 6) {
        return 45;
    }
    if (lbl_2_bss_A840 == 6 && arg0 == 0) {
        return 14;
    }
    if (lbl_2_bss_A840 <= arg0) {
        return 29;
    }
    if (lbl_2_bss_A840 > arg0) {
        return 44;
    }
}

// .text:0x00073B54 size:0x40
s32 fn_2_73B54(s32 arg0) {
    if (lbl_2_bss_A840 == 0 && arg0 == 6) {
        return 4;
    }
    if (lbl_2_bss_A840 == 6 && arg0 == 0) {
        return 1;
    }
    return 1;
}

// .text:0x00073994 size:0x1C0
void fn_2_73994(UnkTask0C50* task, s32 index) {
    s32 a;
    s32 b;
    u8 c;
    u8 d;

    if (g_d_GameSettings.GameModeSelected != 5) {
        a = lbl_800FE5D4[lbl_2_bss_F410._10[index]];
        b = lbl_800FE5D4[lbl_803C6724._00[index]];
    } else if (index != 0) {
        a = b = starMissionCompletionTracker._441F;
    } else {
        a = b = starMissionCompletionTracker._441D;
    }
    c = lbl_8034E9A0._0020[a / 9][a % 9]._14;
    d = lbl_8034E9A0._0020[b / 9][b % 9]._14;
    lbl_80371C30[0x82 + task->_14 + index]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    lbl_80371C30[0x7E + task->_14 + index]._00->_5C = lbl_2_data_2B3A4[c] << 16;
    fn_800363D8(task, index + 0x89, 1, 3, lbl_2_data_2B3A4[c]);
    fn_800363D8(task, index + 0x8B, 1, 3, lbl_2_data_2B3A4[d]);
}

// .text:0x000738C8 size:0xCC
void fn_2_738C8(void) {
    if (lbl_803CBBCC->_6 == 5) {
        fn_800B0A5C_insertQueue(fn_80053FE8, 0);
    }
    if (g_d_GameSettings.GameModeSelected == 5) {
        lbl_8034E978._00 = 13;
        lbl_8034E978._09 = lbl_8034E978._08;
        lbl_8034E978._08 = lbl_800FEF70[13]._08;
        fn_800B0A5C_insertQueue(fn_8004E2EC, 0x3000);
    } else {
        lbl_8034E978._00 = 0;
        lbl_8034E978._09 = lbl_8034E978._08;
        lbl_8034E978._08 = lbl_800FEF70[0]._08;
        fn_800B0A5C_insertQueue(fn_8004F964, 0x3000);
    }
}

// .text:0x00073758 size:0x170
void fn_2_73758(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2AF4C);
    for (i = 0; i < 8; i++) {
        lbl_80371C30[task->_14 + 4 + i]._00->_5C = lbl_803C6724._02[0][1 + i] << 16;
    }
    lbl_803CBCD8._5 = 0;
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_7308C;
}

// .text:0x0007308C size:0x6CC
// 99.91%: registers only: &lbl_803CBBC4 in the inlined fn_2_72DDC and fn_2_72814 gets r29
// in the base and r28 in the target, as in the standalone fn_2_72814 and fn_2_72CB4.
void fn_2_7308C(void) {
    UnkTask0C50* task = lbl_803CC1B8;

    switch (lbl_803CBBC4._0) {
    case 1:
        fn_2_72E54(task);
        fn_2_72DDC(task);
        break;
    case 2:
        fn_2_72D60(task);
        fn_2_72CB4(task);
        break;
    case 3:
        fn_2_72A88(task);
        fn_2_72A58();
        break;
    case 71:
        fn_2_728C0(task);
        fn_2_72814(task);
        break;
    }
    if (lbl_803CBCD8._5) {
        lbl_803CBCD8._5 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0007302C size:0x60
// 58.54%: the base counts the search loop with mtctr/bdnz; the target compares the counter
// on every pass. int/s32 counters, break or return, and local bounds did not change it.
s32 fn_2_7302C(void) {
    s32 i;
    u8* p = lbl_800FE930[lbl_80361B20._F4];

    for (i = 0; i < (lbl_80361B20._F4 != 0) + 5; i++) {
        if (lbl_8034E9A0._46E0[0] == *p) {
            return i;
        }
        p++;
    }
    return i;
}

// .text:0x00073028 size:0x4
void fn_2_73028(void) {
}

// .text:0x00072E54 size:0x1D4
void fn_2_72E54(UnkTask0C50* task) {
    s32 found = -1;
    s32 i;

    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0;
        lbl_80371C30[task->_14]._00->_68 = 1;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0;
        lbl_80371C30[task->_14 + 1]._00->_68 = 1;
        for (i = 0; i < 6; i++) {
            if (lbl_80108EC4[i] == lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[0]]) {
                found = i;
                break;
            }
        }
        lbl_80371C30[task->_14 + 2]._00->_5C = lbl_2_data_2AF08[found] << 18;
        for (i = 0; i < 6; i++) {
            if (lbl_80108EC4[i] == lbl_800FE5D4[lbl_2_bss_F410._10[0]]) {
                break;
            }
        }
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072DDC size:0x78
void fn_2_72DDC(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        if ((fn_80042DA8(task, 0, 25) ? TRUE : FALSE) == TRUE) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
        }
    }
}

// .text:0x00072D60 size:0x7C
void fn_2_72D60(UnkTask0C50* task) {
    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x190000;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072CB4 size:0xAC
// 90.00%: task and &lbl_803CBBC4 sit in swapped saved registers (r31/r30), as in fn_2_72814.
void fn_2_72CB4(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, 0, 0);

        n += isAnimDone(task, 1, 0);
        if (n == 2) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
            lbl_803CBBC4._4 = 1;
        }
    }
}

// .text:0x00072A88 size:0x22C
void fn_2_72A88(UnkTask0C50* task) {
    s32 found = -1;
    s32 i;

    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        for (i = 0; i < 6; i++) {
            if (lbl_80108EC4[i] == lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[0]]) {
                found = i;
                break;
            }
        }
        lbl_80371C30[task->_14 + 2]._00->_5C = lbl_2_data_2AF08[found] << 18;
        lbl_80371C30[task->_14 + 3]._00->_5C = lbl_2_data_2AF08[found] << 18;
        for (i = 0; i < 8; i++) {
            lbl_80371C30[task->_14 + 4 + i]._00->_5C = lbl_803C6724._02[0][1 + i] << 16;
        }
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072A58 size:0x30
void fn_2_72A58(void) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        lbl_803CBBC4._3 = 0;
        lbl_803CBBC4._2 = 0;
        lbl_803CBBC4._0 = 0;
    }
}

// .text:0x000729E0 size:0x78
void fn_2_729E0(UnkTask0C50* task) {
    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 1;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x190000;
        lbl_80371C30[task->_14 + 1]._00->_68 = 1;
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x0007293C size:0xA4
// 89.51%: task and &lbl_803CBBC4 sit in swapped saved registers (r31/r30), as in fn_2_72814.
void fn_2_7293C(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, 0, 25);

        n += isAnimDone(task, 1, 25);
        if (n == 2) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
        }
    }
}

// .text:0x000728C0 size:0x7C
void fn_2_728C0(UnkTask0C50* task) {
    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x190000;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072814 size:0xAC
// 90.00%: task and &lbl_803CBBC4 sit in swapped saved registers (r31/r30);
// declaration orders, an array type for lbl_803CBBC4 and the permuter did not move them.
void fn_2_72814(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, 0, 0);

        n += isAnimDone(task, 1, 0);
        if (n == 2) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
            lbl_803CBBC4._4 = 1;
        }
    }
}

// .text:0x0007265C size:0x1B8
void fn_2_7265C(void) {
    s32 mode;
    s32 i;
    s32 found = FALSE;

    if (g_d_GameSettings.GameModeSelected == 5 && lbl_803C5EA4._11 == 0) {
        lbl_803C5EA4._11 = 1;
        fn_800B0A5C_insertQueue(fn_80053FE8, 0x3000);
        fn_800B0A5C_insertQueue(fn_2_82DE8, 0x3000);
    }
    for (i = 0; i < 54; i++) {
        if (((u8*)lbl_80361B20._00)[i]) {
            found = TRUE;
            break;
        }
    }
    if (g_d_GameSettings.GameModeSelected != 5) {
        if (found) {
            mode = 2;
        } else {
            mode = 1;
        }
    } else {
        mode = 19;
    }
    lbl_8034E978._00 = mode;
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._08 = lbl_800FEF70[mode]._08;
    fn_800B0A5C_insertQueue(fn_80051D00, 0x3000);
}

// .text:0x00072630 size:0x2C
void fn_2_72630(void) {
    fn_800B0A5C_insertQueue(fn_2_72594, 0x3000);
}

// .text:0x00072594 size:0x9C
void fn_2_72594(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2AADC);
    for (i = 0; i < 4; i++) {
        fn_800363D8(task, i + 7, 1, 0x32, 3 - i);
    }
    fn_800363D8(task, 2, 1, 0x35, 0);
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_7207C;
}

// .text:0x0007207C size:0x518
void fn_2_7207C(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 i;

    switch (lbl_803C66B0._5D[0]) {
    case 0x1E:
        if (lbl_803C66B0._0D[0x12] == 0 ? TRUE : FALSE) {
            lbl_80371C30[task->_14]._00->_5C = 0;
            lbl_80371C30[task->_14]._00->_68 = 1;
            lbl_80371C30[task->_14 + 2]._00->_68 = 1;
            for (i = 0; i < 4; i++) {
                lbl_80371C30[3 + task->_14 + i]._00->_58 &= ~0xFF;
            }
            lbl_80371C30[3 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_68 = 1;
            lbl_80371C30[3 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_58 = (lbl_80371C30[3 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_58 & ~0xFF) | 0xFF;
            lbl_80371C30[7 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_5C = 0;
            lbl_80371C30[7 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_68 = 1;
            fn_800626EC(0);
            lbl_803C66B0._0D[0x12] = 1;
        }
        if (lbl_803C66B0._0D[0x12] == 1) {
            s32 n = isAnimDone(task, 0, 0x16);

            n += isAnimDone(task, lbl_803CB8D0[lbl_2_bss_F410._4C] + 7, 5);
            if (n == 2) {
                lbl_803C66B0._5D[1] = 0;
                fn_80062674(0);
                lbl_803C66B0._0D[0x12] = 2;
            }
        }
        break;
    case 0x1F:
        if (lbl_803C66B0._0D[0x12] == 0 ? TRUE : FALSE) {
            lbl_80371C30[task->_14]._00->_68 = 1;
            fn_800626EC(0);
            lbl_803C66B0._0D[0x12] = 1;
        }
        if (lbl_803C66B0._0D[0x12] == 1) {
            if (fn_80042DA8(task, 0, 0x1C)) {
                fn_80062674(0);
                lbl_803C66B0._0D[0x12] = 2;
            }
        }
        break;
    case 0x20:
        if (lbl_803C66B0._0D[0x12] == 0 ? TRUE : FALSE) {
            for (i = 0; i < 4; i++) {
                lbl_80371C30[3 + task->_14 + i]._00->_68 = 0;
                lbl_80371C30[7 + task->_14 + i]._00->_68 = 0;
                lbl_80371C30[3 + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[7 + task->_14 + i]._00->_5C = 0;
                lbl_80371C30[3 + task->_14 + i]._00->_58 &= ~0xFF;
            }
            lbl_80371C30[3 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_68 = 1;
            lbl_80371C30[3 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_58 = (lbl_80371C30[3 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_58 & ~0xFF) | 0xFF;
            lbl_80371C30[7 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_5C = 0;
            lbl_80371C30[7 + task->_14 + lbl_803CB8D0[lbl_2_bss_F410._4C]]._00->_68 = 1;
            fn_800626EC(0);
            lbl_803C66B0._0D[0x12] = 1;
        }
        if (lbl_803C66B0._0D[0x12] == 1) {
            if (fn_80042DA8(task, lbl_803CB8D0[lbl_2_bss_F410._4C] + 7, 5)) {
                fn_80062674(0);
                lbl_803C66B0._0D[0x12] = 2;
            }
        }
        break;
    case 0x21:
        if (lbl_803C66B0._0D[0x12] == 0 ? TRUE : FALSE) {
            lbl_80371C30[task->_14]._00->_68 = 1;
            fn_800626EC(0);
            lbl_803C66B0._0D[0x12] = 1;
        }
        if (lbl_803C66B0._0D[0x12] == 1) {
            fn_80062674(0);
            lbl_803C66B0._0D[0x12] = 2;
        }
        break;
    }
    if (lbl_8034E9A0._472A == 1) {
        lbl_8034E9A0._472A = 0xFF;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
}
