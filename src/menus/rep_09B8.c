#include "menus/rep_09B8.h"
#include "header_rep_data.h"
#include "menus/rep_08E8.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"
#include "string.h"

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800ACFB0(void* data);
extern void fn_2_380B0(void);
extern void fn_2_381A8(void);
extern void fn_2_382A0(void);
extern void fn_2_38538(void);
extern void fn_2_38824(void);
extern void fn_2_38A40(void);
extern void fn_2_39408(void);
extern u8 lbl_800EFBA4[0x10];
extern s16 lbl_2_data_38CC[];

extern struct {
    /* 0x000000 */ u8 _000000[0x1954AC];
    /* 0x1954AC */ u16* _1954AC[1];
    /* 0x1954B0 */ u8 _1954B0[0x196F1C - 0x1954B0];
    /* 0x196F1C */ s32* _196F1C;
    /* 0x196F20 */ s32 _196F20;
    /* 0x196F24 */ s32 _196F24;
    /* 0x196F28 */ s32 _196F28;
    /* 0x196F2C */ u8 _196F2C[0x196F30 - 0x196F2C];
    /* 0x196F30 */ s32 _196F30;
    /* 0x196F34 */ s32 _196F34;
    /* 0x196F38 */ s32 _196F38[0x20];
    /* 0x196FB8 */ s32 _196FB8[2];
    /* 0x196FC0 */ s16 _196FC0;
    /* 0x196FC2 */ u8 _196FC2[0x196FCA - 0x196FC2];
    /* 0x196FCA */ s16 _196FCA[2];
    /* 0x196FCE */ u8 _196FCE[0x196FD2 - 0x196FCE];
    /* 0x196FD2 */ s16 _196FD2;
    /* 0x196FD4 */ s16 _196FD4;
    /* 0x196FD6 */ s16 _196FD6;
    /* 0x196FD8 */ u8 _196FD8[0x196FE0 - 0x196FD8];
    /* 0x196FE0 */ s16 _196FE0;
    /* 0x196FE2 */ u8 _196FE2[0x196FE4 - 0x196FE2];
    /* 0x196FE4 */ s16 _196FE4;
    /* 0x196FE6 */ u8 _196FE6[0x196FE8 - 0x196FE6];
    /* 0x196FE8 */ s16 _196FE8[0xA8];
    /* 0x197138 */ u8 _197138[0x197294 - 0x197138];
    /* 0x197294 */ s16 _197294[2];
    /* 0x197298 */ s16 _197298[2];
    /* 0x19729C */ s16 _19729C;
    /* 0x19729E */ s16 _19729E;
    /* 0x1972A0 */ s16 _1972A0[2];
    /* 0x1972A4 */ s16 _1972A4[2];
    /* 0x1972A8 */ u8 _1972A8[0x1972AA - 0x1972A8];
    /* 0x1972AA */ s16 _1972AA;
    /* 0x1972AC */ s16 _1972AC[2];
    /* 0x1972B0 */ s16 _1972B0;
    /* 0x1972B2 */ s16 _1972B2;
    /* 0x1972B4 */ s16 _1972B4;
    /* 0x1972B6 */ u8 _1972B6;
    /* 0x1972B7 */ u8 _1972B7;
    /* 0x1972B8 */ u8 _1972B8;
    /* 0x1972B9 */ u8 _1972B9[2];
    /* 0x1972BB */ u8 _1972BB[0x1976DE - 0x1972BB];
    /* 0x1976DE */ s16 _1976DE;
    /* 0x1976E0 */ u8 _1976E0[0x1977A0 - 0x1976E0];
    /* 0x1977A0 */ s16 _1977A0;
    /* 0x1977A2 */ u8 _1977A2[0x19783F - 0x1977A2];
    /* 0x19783F */ u8 _19783F;
    /* 0x197840 */ u8 _197840;
    /* 0x197841 */ u8 _197841;
    /* 0x197842 */ u8 _197842;
    /* 0x197843 */ u8 _197843[0x197863 - 0x197843];
    /* 0x197863 */ s8 _197863;
} *lbl_2_bss_1A824C;

extern struct {
    /* 0x000000 */ u8 _000000[0x162658];
    /* 0x162658 */ u8 _162658;
    /* 0x162659 */ u8 _162659[0x162687 - 0x162659];
    /* 0x162687 */ u8 _162687;
    /* 0x162688 */ u8 _162688;
    /* 0x162689 */ u8 _162689;
    /* 0x16268A */ u8 _16268A[0x162842 - 0x16268A];
    /* 0x162842 */ u8 _162842;
    /* 0x162843 */ u8 _162843[0x162871 - 0x162843];
    /* 0x162871 */ u8 _162871;
    /* 0x162872 */ u8 _162872;
    /* 0x162873 */ u8 _162873;
} *lbl_2_bss_1A8234;

// One text window per entry
typedef struct MenuTextWindow09B8 {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ u8 _34;
    /* 0x35 */ u8 _35[0x38 - 0x35];
} MenuTextWindow09B8; // size: 0x38

extern struct {
    /* 0x000 */ MenuTextWindow09B8 _000[0x798 / 0x38];
    /* 0x770 */ u8 _770[0x798 - 0x770];
    /* 0x798 */ u16** _798[1];
} lbl_80366B18;

extern u16 lbl_2_data_1F3A0[8];

typedef struct MenuTask09B8 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct MenuTask09B8* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x16 - 0x12];
    /* 0x16 */ s16 _16;
    /* 0x18 */ s16 _18;
    /* 0x1A */ s16 _1A;
    /* 0x1C */ u8 _1C[0x28 - 0x1C];
    /* 0x28 */ s8 _28;
} MenuTask09B8;

extern void* lbl_803CC1B8;
extern u8* lbl_2_data_1E99C[];
extern void fn_800B0A14_removeQueue(void);
extern u16 lbl_2_data_1F3B0[];
extern u16* lbl_2_data_1F3E0[2];
extern u16* lbl_2_data_1F3E8[2];

static u16 lbl_2_bss_9A08[2][0x100];
static u16 lbl_2_bss_9608[2][0x100];
static u16 lbl_2_bss_9604[2];
u16 lbl_2_bss_9600[2];
s32 lbl_2_bss_5600[0x1000];
static u16* lbl_2_bss_55F8[2];
static u16* lbl_2_bss_55F0[2];
static u16* lbl_2_bss_55E8[2];

typedef struct MenuItem09B8 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u16 _10;
} MenuItem09B8;

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);

// .text:0x00051470 size:0xF8
// 98.39%: only the trailing blr differs; dtk split it off as fn_2_51568, past
// the end of this unit's .text range in splits.txt (0x51568).
u16 fn_2_51470(s32 idx, u16 k) {
    u16 sum = 0;
    u16 c;
    u16* p;
    u16 val;

    if (k == 0) {
        p = lbl_80366B18._798[lbl_2_bss_1A824C->_1972B8][idx + 1];
    } else {
        p = lbl_80366B18._798[lbl_2_bss_1A824C->_1972B8][idx + 1];
    }
    for (;;) {
        c = *p++;
        if (c & 0x4000) {
            switch (c & 0x3FFF) {
            case 2:
                sum += lbl_2_data_1F3A0[k] / 2;
                break;
            case 3:
                sum += lbl_2_data_1F3A0[k];
                break;
            default:
                return (u16)sum;
            }
        } else {
            if (c & 0x8000) {
                val = lbl_2_data_1F3A0[k];
            } else {
                val = lbl_2_data_1F3A0[k] / 2;
            }
            sum += val;
        }
    }
}

// .text:0x000513E8 size:0x88
u16 fn_2_513E8(u16* p, u16 k) {
    u16 c;
    u16 val;
    u16 sum = 0;

    for (;;) {
        c = *p++;
        if (c & 0x4000) {
            switch (c & 0x3FFF) {
            case 2:
                sum += lbl_2_data_1F3A0[k] / 2;
                break;
            case 3:
                sum += lbl_2_data_1F3A0[k];
                break;
            default:
                return (u16)sum;
            }
        } else {
            if (c & 0x8000) {
                val = lbl_2_data_1F3A0[k];
            } else {
                val = lbl_2_data_1F3A0[k] / 2;
            }
            sum += val;
        }
    }
}

// .text:0x000513E4 size:0x4
void fn_2_513E4(void) {
}

// .text:0x000513E0 size:0x4
void fn_2_513E0(void* text, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
}

// .text:0x000513DC size:0x4
void fn_2_513DC(void) {
}

// .text:0x0005135C size:0x80
void fn_2_5135C(MenuItem09B8* item, s32 k) {
    if (item->_10 % lbl_2_data_1F3B0[k] == 1) {
        lbl_2_bss_55F0[k] = lbl_2_data_1F3E0[k];
        lbl_2_bss_55E8[k] = lbl_2_data_1F3E8[k];
        lbl_2_bss_55F8[k] = lbl_2_bss_1A824C->_1954AC[k];
    }
}

// .text:0x000512C0 size:0x9C
// 94.74%: the target's switch has one more `b` after the dispatch and its only
// blr in the middle; case orders and a default did not reproduce it.
void fn_2_512C0(s32 idx) {
    u16* p = lbl_2_bss_1A824C->_1954AC[idx];
    u16 c;

    for (;;) {
        c = *p++;
        if (c & 0x4000) {
            switch (c & 0x3FFF) {
            case 0:
                return;
            case 4:
                break;
            }
            lbl_2_bss_1A824C->_197294[idx]++;
        } else {
            lbl_2_bss_1A824C->_197294[idx]++;
        }
    }
}

// .text:0x000512B8 size:0x8
s32 fn_2_512B8(void) {
    return 0;
}

// .text:0x000512B4 size:0x4
void fn_2_512B4(void) {
}

// .text:0x00051190 size:0x124
void fn_2_51190(s32 arg0, s32 arg1) {
    s32 i;

    lbl_2_bss_1A824C->_196FE0 = 1;
    lbl_2_bss_1A824C->_196FE4 = 1;
    for (i = 0; i < 0xA8; i++) {
        lbl_2_bss_1A824C->_196FE8[i] = 0;
    }
    lbl_2_bss_1A824C->_196FB8[0] = arg0;
    lbl_2_bss_1A824C->_196F30 = arg1;
    lbl_2_bss_1A824C->_196FCA[0] = 0;
    lbl_2_bss_1A824C->_197298[0] = 0;
    lbl_2_bss_1A824C->_19729C = 0;
}

// .text:0x0005118C size:0x4
void fn_2_5118C(void) {
}

// .text:0x000510A8 size:0xE4
void fn_2_510A8(void) {
    s32 i;

    lbl_2_bss_9604[1] = 0;
    lbl_2_bss_9604[0] = 0;
    lbl_2_bss_1A824C->_196FCA[1] = 1;
    lbl_2_bss_1A824C->_196FCA[0] = 1;
    for (i = 0; i < 0x100; i++) {
        lbl_2_bss_9A08[0][i] = 0;
        lbl_2_bss_9A08[1][i] = 0;
    }
}

// .text:0x00050FC8 size:0xE0
void fn_2_50FC8(s32 idx) {
    s32 i;

    lbl_2_bss_9604[idx] = 0;
    lbl_2_bss_1A824C->_196FCA[idx] = 1;
    for (i = 0; i < 0x100; i++) {
        lbl_2_bss_9A08[idx][i] = 0;
    }
}

// .text:0x00050F20 size:0xA8
void fn_2_50F20(s32 idx, s32 sel, u16* p) {
    u16** table = lbl_80366B18._798[lbl_2_bss_1A824C->_1972B8] + 1;
    u16 c;

    if (lbl_2_bss_9604[idx] != 0) {
        lbl_2_bss_9604[idx]--;
    }
    p = sel == -1 ? p : table[sel];
    do {
        c = *p++;
        lbl_2_bss_9A08[idx][lbl_2_bss_9604[idx]] = c;
        lbl_2_bss_9604[idx]++;
        if (lbl_2_bss_9604[idx] == 0x100) {
            return;
        }
    } while (!(c & 0x4000) || (c & 0x3FFF));
}

// .text:0x00050E5C size:0xC4
void fn_2_50E5C(s32 idx) {
    s32 i;

    lbl_2_bss_9600[idx] = 0;
    for (i = 0; i < 0x100; i++) {
        lbl_2_bss_9608[idx][i] = 0;
    }
}

// .text:0x00050DB4 size:0xA8
void fn_2_50DB4(s32 idx, s32 sel, u16* p) {
    u16** table = lbl_80366B18._798[lbl_2_bss_1A824C->_1972B8] + 1;
    u16* src;
    u16 c;

    if (lbl_2_bss_9600[idx] != 0) {
        lbl_2_bss_9600[idx]--;
    }
    src = sel == -1 ? p : table[sel];
    do {
        c = *src++;
        lbl_2_bss_9608[idx][lbl_2_bss_9600[idx]] = c;
        lbl_2_bss_9600[idx]++;
        if (lbl_2_bss_9600[idx] == 0x100) {
            return;
        }
    } while (!(c & 0x4000) || (c & 0x3FFF));
}

// .text:0x00050D40 size:0x74
void fn_2_50D40(s32 idx) {
    u16* src;
    u16 c;

    if (lbl_2_bss_9604[idx] != 0) {
        lbl_2_bss_9604[idx]--;
    }
    src = lbl_2_bss_9608[idx];
    do {
        c = *src++;
        lbl_2_bss_9A08[idx][lbl_2_bss_9604[idx]] = c;
        lbl_2_bss_9604[idx]++;
        if (lbl_2_bss_9604[idx] == 0x100) {
            return;
        }
    } while (!(c & 0x4000) || (c & 0x3FFF));
}

// .text:0x00050CC0 size:0x80
void fn_2_50CC0(s16 arg0) {
    MenuTask09B8* task;

    lbl_2_bss_1A824C->_196FD6 = arg0;
    lbl_2_bss_1A824C->_196FCA[1] = 0;
    lbl_2_bss_1A824C->_196FCA[0] = 0;
    lbl_2_bss_1A824C->_19729E = 0;
    lbl_2_bss_1A824C->_19729C = 0;
    task = fn_800B0A5C_insertQueue(fn_2_509A4, 4);
    task->_28 = 0;
}

// .text:0x00050BF4 size:0xCC
void fn_2_50BF4(s16 arg0) {
    lbl_2_bss_1A824C->_196FD4 = 0;
    lbl_2_bss_1A824C->_196FD2 = 0;
    lbl_2_bss_1A824C->_196FD6 = arg0;
    lbl_2_bss_1A824C->_196FCA[1] = 0;
    lbl_2_bss_1A824C->_196FCA[0] = 0;
    lbl_2_bss_1A824C->_19729E = 0;
    lbl_2_bss_1A824C->_19729C = 0;
    memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
    lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
    fn_2_4EB9C();
}

// .text:0x00050B0C size:0xE8
void fn_2_50B0C(s16 arg0, s16 arg1) {
    lbl_2_bss_1A824C->_196FD4 = 0;
    lbl_2_bss_1A824C->_196FD2 = 0;
    lbl_2_bss_1A824C->_196FD6 = arg0;
    lbl_2_bss_1A824C->_196F30 = lbl_2_bss_1A824C->_196F34 = arg1;
    lbl_2_bss_1A824C->_196FCA[1] = 0;
    lbl_2_bss_1A824C->_196FCA[0] = 0;
    lbl_2_bss_1A824C->_19729E = 0;
    lbl_2_bss_1A824C->_19729C = 0;
    memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
    lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
    fn_2_4EB9C();
}

// .text:0x000509A4 size:0x168
void fn_2_509A4(void) {
    MenuTask09B8* task = lbl_803CC1B8;
    s16 result;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A824C->_196FD4 = 0;
        lbl_2_bss_1A824C->_196FD2 = 0;
        memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
        lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
        task->_28++;
    case 1:
        result = fn_2_4EB9C();
        if (result != 0) {
            switch (result) {
            case 1:
                ((MenuTask09B8*)lbl_803CC1B8)->_0C->_10 = 1;
                fn_800B0A14_removeQueue();
                break;
            default:
                ((MenuTask09B8*)lbl_803CC1B8)->_0C->_10 = 1;
                fn_800B0A14_removeQueue();
                break;
            }
            task->_28 = 0;
        }
        break;
    case 2:
        break;
    }
    if (lbl_2_bss_1A824C->_19783F == 1) {
        ((MenuTask09B8*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
    }
}

// .text:0x00050898 size:0x10C
void fn_2_50898(s32 arg0) {
    s32 i;

    lbl_2_bss_1A824C->_196FB8[0] = arg0;
    lbl_2_bss_1A824C->_196FE0 = 1;
    lbl_2_bss_1A824C->_196FE4 = 1;
    for (i = 0; i < 0xA8; i++) {
        lbl_2_bss_1A824C->_196FE8[i] = 0;
    }
    lbl_2_bss_1A824C->_196FD2 = 1;
    lbl_2_bss_1A824C->_196F30 = 1;
    lbl_2_bss_1A824C->_197298[0] = 0;
}

// .text:0x0004EB9C size:0x1CFC
s16 fn_2_4EB9C(void) {
    MenuTask09B8* task = lbl_803CC1B8;
    MenuTask09B8* child;
    s32 pads[2];
    s32 idx;
    s32 val;
    s32 key;
    s32 done2;
    s32 done;
    s32 flags;
    u16* text;

    if (lbl_2_bss_1A824C->_196F24 != 0) {
        lbl_2_bss_1A824C->_196F24--;
        return 0;
    }
    pads[0] = lbl_2_bss_1A824C->_1972A0[0];
    pads[1] = lbl_2_bss_1A824C->_1972A0[1];
    for (;;) {
        switch (lbl_2_bss_1A824C->_196F1C[0]) {
        case 0x0:
            lbl_2_bss_1A824C->_1972B0 = 0;
            lbl_2_bss_1A824C->_197298[1] = 0;
            lbl_2_bss_1A824C->_197298[0] = 0;
            lbl_2_bss_1A824C->_1977A0 = 0;
            lbl_2_bss_1A824C->_197840 = 0;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x1:
            lbl_2_bss_1A824C->_197840 = 0;
            return 1;
        case 0xB:
            idx = lbl_2_bss_1A824C->_196F1C[1];
            lbl_2_bss_1A824C->_196FB8[idx] = lbl_2_bss_1A824C->_196F1C[2];
            if (idx == 0) {
                lbl_2_bss_1A8234->_162687 = 1;
            } else {
                lbl_2_bss_1A8234->_162688 = 1;
            }
            lbl_2_bss_1A824C->_197298[idx] = 0;
            lbl_2_bss_1A824C->_196FC0 = idx;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0xD;
            break;
        case 0x25:
            idx = lbl_2_bss_1A824C->_196F1C[1];
            lbl_2_bss_1A824C->_196FB8[idx] = lbl_2_bss_1A824C->_196F1C[2];
            if (idx == 0) {
                lbl_2_bss_1A8234->_162687 = 1;
            } else {
                lbl_2_bss_1A8234->_162688 = 1;
            }
            lbl_2_bss_1A824C->_197298[idx] = 0;
            lbl_2_bss_1A824C->_196FC0 = idx;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0x26;
            break;
        case 0x8:
            lbl_2_bss_1A824C->_196FB8[0] = lbl_2_bss_1A824C->_196F1C[1];
            lbl_2_bss_1A8234->_162687 = 1;
            lbl_2_bss_1A824C->_197298[0] = 0;
            lbl_2_bss_1A824C->_196F1C += 2;
            continue;
        case 0x1C:
            idx = 0;
            lbl_2_bss_1A824C->_196FB8[idx] = lbl_2_bss_1A824C->_196F1C[1];
            if (idx == 0) {
                lbl_2_bss_1A8234->_162687 = 1;
            } else {
                lbl_2_bss_1A8234->_162688 = 1;
            }
            lbl_2_bss_1A824C->_197298[idx] = 0;
            lbl_2_bss_1A824C->_196FC0 = idx;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0x1D;
            break;
        case 0xD:
            if (lbl_80366B18._000[pads[lbl_2_bss_1A824C->_196FC0]]._34 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = 0xC;
            } else if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x1000) && lbl_2_bss_1A824C->_197842 == 1) {
                lbl_2_bss_1A824C->_197840 = 1;
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_1977A0;
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            }
            break;
        case 0x26:
            if (lbl_80366B18._000[pads[lbl_2_bss_1A824C->_196FC0]]._34 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 3;
            } else if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x1000) && lbl_2_bss_1A824C->_197842 == 1) {
                lbl_2_bss_1A824C->_197840 = 1;
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_1977A0;
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            }
            break;
        case 0x1D:
            if (lbl_80366B18._000[pads[lbl_2_bss_1A824C->_196FC0]]._34 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 2;
            } else if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x1000) && lbl_2_bss_1A824C->_197842 == 1) {
                lbl_2_bss_1A824C->_197840 = 1;
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_1977A0;
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            }
            break;
        case 0xC:
            idx = lbl_2_bss_1A824C->_196FC0;
            lbl_2_bss_1A824C->_197298[idx] = 1;
            if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
                lbl_2_bss_1A824C->_196FCA[1] = 0;
                lbl_2_bss_1A824C->_196FCA[0] = 0;
                lbl_2_bss_1A824C->_197298[idx] = 0;
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 3;
            } else if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x1000) && lbl_2_bss_1A824C->_197842 == 1) {
                lbl_2_bss_1A824C->_197840 = 1;
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_1977A0;
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            }
            break;
        case 0x14:
            lbl_2_bss_1A824C->_1972B2 = 1;
            done2 = 0;
            if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 8) {
                lbl_2_bss_1A824C->_1972B0 = (lbl_2_bss_1A824C->_1972B0 + 1) % 2;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 4) {
                lbl_2_bss_1A824C->_1972B0 = (lbl_2_bss_1A824C->_1972B0 + 1) % 2;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
            if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                done2 = 1;
            } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
                if (lbl_2_bss_1A824C->_1972B0 == 0) {
                    lbl_2_bss_1A824C->_1972B0 = 1;
                } else {
                    done2 = 1;
                }
                sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            }
            if (done2) {
                lbl_2_bss_1A824C->_196FCA[1] = 0;
                lbl_2_bss_1A824C->_196FCA[0] = 0;
                lbl_2_bss_1A824C->_1972B2 = 0;
                lbl_2_bss_1A824C->_196F1C += 1;
            }
            break;
        case 0x19:
            lbl_2_bss_1A824C->_1972B2 = 1;
            done = 0;
            if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 8) {
                lbl_2_bss_1A824C->_1972B0 = (lbl_2_bss_1A824C->_1972B0 + 2) % 3;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 4) {
                lbl_2_bss_1A824C->_1972B0 = (lbl_2_bss_1A824C->_1972B0 + 1) % 3;
                sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            }
            if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                done = 1;
            } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
                if (lbl_2_bss_1A824C->_1972B0 == 0 || lbl_2_bss_1A824C->_1972B0 == 1) {
                    lbl_2_bss_1A824C->_1972B0 = 2;
                } else {
                    done = 1;
                }
                sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            }
            if (done) {
                lbl_2_bss_1A824C->_196FCA[1] = 0;
                lbl_2_bss_1A824C->_196FCA[0] = 0;
                lbl_2_bss_1A824C->_1972B2 = 0;
                lbl_2_bss_1A824C->_196F1C += 1;
            }
            break;
        case 0x2:
            lbl_2_bss_1A824C->_196F24 = lbl_2_bss_1A824C->_196F1C[1];
            lbl_2_bss_1A824C->_196F1C += 2;
            break;
        case 0x15:
            if (lbl_2_bss_1A824C->_196F28-- == 0) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
            }
            break;
        case 0x16:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
            }
            break;
        case 0x20:
            fn_2_510A8();
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x3:
            val = lbl_2_bss_1A824C->_196F1C[1];
            fn_2_50FC8(val);
            lbl_2_bss_1A824C->_196F1C += 2;
            continue;
        case 0x4:
            fn_2_50F20(lbl_2_bss_1A824C->_196F1C[1], lbl_2_bss_1A824C->_196F1C[2], NULL);
            lbl_2_bss_1A824C->_196F1C += 3;
            continue;
        case 0x5:
            lbl_2_bss_1A824C->_196F30 = 1;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x6:
            idx = lbl_2_bss_1A824C->_196F1C[1];
            fn_2_50F20(idx, lbl_2_bss_1A824C->_196F1C[2] + lbl_2_bss_1A824C->_196F38[lbl_2_bss_1A824C->_196F1C[3]], NULL);
            lbl_2_bss_1A824C->_196F1C += 4;
            continue;
        case 0x7:
            fn_2_50F20(lbl_2_bss_1A824C->_196F1C[1], lbl_2_bss_1A824C->_196F1C[2] + lbl_2_bss_1A824C->_196F1C[3], NULL);
            lbl_2_bss_1A824C->_196F1C += 4;
            continue;
        case 0x9:
            lbl_2_bss_1A824C->_196F1C += 4;
            continue;
        case 0xE:
            child = fn_800B0A5C_insertQueue(fn_2_38A40, 2);
            child->_28 = 0;
            lbl_2_bss_1A824C->_19729C = lbl_2_bss_1A824C->_196F1C[1];
            lbl_2_bss_1A824C->_19729E = lbl_2_bss_1A824C->_196F1C[2];
            lbl_2_bss_1A824C->_1972AA = lbl_2_bss_1A824C->_196F1C[3];
            task->_10 = 0;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0xF;
            continue;
        case 0xF:
            if (task->_10 == 1) {
                if (lbl_2_bss_1A824C->_19729C == 1) {
                    lbl_2_bss_1A824C->_1972B9[0] = 1;
                }
                if (lbl_2_bss_1A824C->_19729E == 1) {
                    lbl_2_bss_1A824C->_1972B9[1] = 1;
                }
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 4;
            }
            break;
        case 0x1A:
            child = fn_800B0A5C_insertQueue(fn_2_38824, 2);
            child->_28 = 0;
            child->_1A = 0;
            child->_18 = 0;
            if (lbl_2_bss_1A824C->_196F1C[1] == 0) {
                lbl_2_bss_1A824C->_1972A4[0] = 1;
                lbl_2_bss_1A824C->_1972AC[0] = lbl_2_bss_1A824C->_196F1C[2];
                child->_18 = 1;
            } else if (lbl_2_bss_1A824C->_196F1C[1] == 1) {
                lbl_2_bss_1A824C->_1972A4[1] = 1;
                lbl_2_bss_1A824C->_1972AC[1] = lbl_2_bss_1A824C->_196F1C[2];
                child->_1A = 1;
            }
            task->_10 = 0;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0x1B;
            continue;
        case 0x1B:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 3;
            }
            break;
        case 0x10:
            if (lbl_2_bss_1A824C->_19729C == 1) {
                lbl_2_bss_1A824C->_1972B9[0] = 0;
            }
            if (lbl_2_bss_1A824C->_19729E == 1) {
                lbl_2_bss_1A824C->_1972B9[1] = 0;
            }
            lbl_2_bss_1A8234->_162842 = 1;
            lbl_2_bss_1A8234->_162871 = 1;
            lbl_2_bss_1A8234->_162872 = 1;
            child = fn_800B0A5C_insertQueue(fn_2_38538, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0x11;
            continue;
        case 0x11:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 1;
            }
            break;
        case 0x12:
            lbl_2_bss_1A8234->_162658 = 1;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x13:
            lbl_2_bss_1A8234->_162842 = 1;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x2F:
            lbl_2_bss_1A8234->_162689 = 1;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x30:
            lbl_2_bss_1A8234->_162873 = 1;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x17:
            memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
            lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            break;
        case 0x18:
            lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_196F1C[1];
            memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
            lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            break;
        case 0x1E:
            if (lbl_2_bss_1A824C->_1972B0 == 0) {
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_196F1C[1];
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            } else {
                lbl_2_bss_1A824C->_196F1C += 2;
            }
            break;
        case 0x21:
            idx = lbl_2_bss_1A824C->_196F1C[1];
            key = lbl_2_bss_1A824C->_196F1C[2];
            flags = lbl_2_bss_1A824C->_196F1C[3];
            fn_2_50E5C(idx);
            val = lbl_2_bss_1A824C->_196F38[key];
            text = _OSAllocFromHeap(0x10, 0xC);
            fn_2_4917C(text, val, flags, 4, 1);
            fn_2_50DB4(idx, -1, text);
            fn_2_50D40(idx);
            if (text != NULL) {
                fn_800ACFB0(text);
            }
            lbl_2_bss_1A824C->_196F1C += 4;
            continue;
        case 0x22:
            lbl_2_bss_1A824C->_1972B4 = lbl_2_bss_1A824C->_196F1C[1];
            lbl_2_bss_1A824C->_1972B6 = lbl_2_data_38CC[lbl_2_bss_1A824C->_1972B4];
            lbl_2_bss_1A824C->_1972B7 = 0;
            child = fn_800B0A5C_insertQueue(fn_2_39408, 2);
            child->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A824C->_196F1C += 2;
            continue;
        case 0x23:
            if (task->_10 != 0) {
                lbl_2_bss_1A824C->_196F1C += 1;
            }
            break;
        case 0x24:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_196F1C[1];
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            } else if (task->_10 == 2 || task->_10 == 3) {
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_196F1C[2];
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            }
            break;
        case 0x27:
            if (lbl_2_bss_1A824C->_1972B0 == 0) {
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_196F1C[1];
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            } else {
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_196F1C[2];
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            }
            break;
        case 0x1F:
            if (lbl_2_bss_1A824C->_1972B0 == 0) {
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_196F1C[1];
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            } else if (lbl_2_bss_1A824C->_1972B0 == 1) {
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_196F1C[2];
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            } else {
                lbl_2_bss_1A824C->_196FD6 = lbl_2_bss_1A824C->_196F1C[3];
                memcpy(lbl_2_bss_5600, lbl_2_data_1E99C[lbl_2_bss_1A824C->_196FD6], sizeof(lbl_2_bss_5600));
                lbl_2_bss_1A824C->_196F1C = lbl_2_bss_5600;
            }
            break;
        case 0x28:
            val = lbl_2_bss_1A824C->_196F1C[1];
            child = fn_800B0A5C_insertQueue(fn_2_382A0, 2);
            child->_28 = 0;
            child->_16 = val;
            task->_10 = 0;
            lbl_2_bss_1A8234->_162842 = 1;
            lbl_2_bss_1A8234->_162871 = 1;
            lbl_2_bss_1A8234->_162872 = 1;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0x29;
            continue;
        case 0x29:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 2;
            }
            break;
        case 0x32:
            child = fn_800B0A5C_insertQueue(fn_2_382A0, 2);
            child->_28 = 0;
            child->_16 = 2;
            task->_10 = 0;
            lbl_2_bss_1A8234->_162842 = 1;
            lbl_2_bss_1A8234->_162871 = 1;
            lbl_2_bss_1A8234->_162872 = 1;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0x33;
            continue;
        case 0x33:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 1;
            }
            break;
        case 0x2A:
            child = fn_800B0A5C_insertQueue(fn_2_381A8, 2);
            child->_28 = 0;
            child->_16 = 0;
            task->_10 = 0;
            lbl_2_bss_1A8234->_162842 = 1;
            lbl_2_bss_1A8234->_162871 = 1;
            lbl_2_bss_1A8234->_162872 = 1;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0x2B;
            continue;
        case 0x2B:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 1;
            }
            break;
        case 0x2C:
            lbl_2_bss_1A824C->_1972AA = lbl_2_bss_1A824C->_196F1C[1];
            child = fn_800B0A5C_insertQueue(fn_2_380B0, 2);
            child->_28 = 0;
            child->_16 = 0;
            task->_10 = 0;
            lbl_2_bss_1A8234->_162842 = 1;
            lbl_2_bss_1A8234->_162871 = 1;
            lbl_2_bss_1A8234->_162872 = 1;
            lbl_2_bss_1A824C->_196F20 = lbl_2_bss_1A824C->_196F1C[0];
            lbl_2_bss_1A824C->_196F1C[0] = 0x2D;
            continue;
        case 0x2D:
            if (task->_10 == 1) {
                lbl_2_bss_1A824C->_196F1C[0] = lbl_2_bss_1A824C->_196F20;
                lbl_2_bss_1A824C->_196F1C += 2;
            }
            break;
        case 0x2E:
            lbl_2_bss_1A824C->_1976DE = 1;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x34:
            lbl_2_bss_1A824C->_197842 = lbl_2_bss_1A824C->_196F1C[1];
            if (lbl_2_bss_1A824C->_197842 == 1) {
                lbl_2_bss_1A824C->_1977A0 = lbl_2_bss_1A824C->_196F1C[2];
            }
            lbl_2_bss_1A824C->_196F1C += 3;
            continue;
        case 0x35:
            lbl_2_bss_1A824C->_197298[0] = 1;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x36:
            lbl_2_bss_1A824C->_197298[0] = 0;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x37:
            lbl_2_bss_1A824C->_197298[1] = 1;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x38:
            lbl_2_bss_1A824C->_197298[1] = 1;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        case 0x39:
            lbl_2_bss_1A824C->_197298[0] = 0;
            lbl_2_bss_1A824C->_197298[1] = 0;
            lbl_2_bss_1A824C->_196F1C += 1;
            continue;
        }
        return 0;
    }
}
