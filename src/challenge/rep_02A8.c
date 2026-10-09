#include "challenge/rep_02A8.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/musyx.h"

typedef struct Task02A8 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct Task02A8* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ s32 (*_14)(u8* arg0);
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
} Task02A8;

typedef struct ListEntry02A8 {
    /* 0x00 */ char* _00;
    /* 0x04 */ u8 _04[0x10 - 0x4];
} ListEntry02A8; // size: 0x10

typedef struct List02A8 {
    /* 0x00 */ ListEntry02A8* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10;
} List02A8;

typedef struct AramEntry02A8 {
    /* 0x0 */ u32 _0[4];
} AramEntry02A8; // size: 0x10

extern void* lbl_803CC1B8;

// The sound bank table: group data pointers, indexed by sound group
extern struct {
    /* 0x000 */ s32 _00;
    /* 0x004 */ void* groups[0xE3];
    /* 0x390 */ u8 _390;
    /* 0x391 */ u8 _391[0x396 - 0x391];
    /* 0x396 */ u8 _396;
} lbl_800EF808;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x00 */ s8 _00;
    /* 0x01 */ u8 _01;
    /* 0x02 */ u8 _02[0xC - 0x2];
    /* 0x0C */ s32 _0C;
    /* 0x10 */ u8 _10[0x24 - 0x10];
    /* 0x24 */ s32 _24[11];
} lbl_1_common_bss_49A78;

extern struct {
    /* 0x00 */ u8 _00[0xE0];
    /* 0x E0 */ u8 _E0;
} lbl_1_common_bss_49994;

extern void* ARAMTransfer(AramEntry02A8* entry, s32 arg1, s32 arg2, u32 aram);
extern u8 fn_800211F0(void);
extern BOOL fn_800214D0(void);
extern BOOL fn_80021518(s32 group, void* data);
extern void fn_80021954(void** group);
extern void fn_80021980(void* group);
extern void fn_800ACFB0(void* ptr);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void fn_800B0A14_removeQueue(void);

extern u8 lbl_1_data_17A4[];
extern u16 lbl_1_data_17C4[];
extern u16 lbl_1_data_17E8[];
extern u8 lbl_1_data_1884[];
extern AramEntry02A8 lbl_1_data_196C[];
extern void (*lbl_1_data_1C8C[5])(void);
extern u8 lbl_1_data_1CA0;
extern s16 lbl_1_data_1CA4;
extern s32 lbl_1_data_1CA8;

extern u8 lbl_1_bss_2FD9;
extern u8 lbl_1_bss_2FDA;
extern u8 lbl_1_bss_2FDB;
extern u8 lbl_1_bss_2FDD;
extern u8 lbl_1_bss_2FDE;
extern u8 lbl_1_bss_2FDF;
extern u8 lbl_1_bss_2FE8;
extern u8 lbl_1_bss_2FEE;
extern s16 lbl_1_bss_3054;
extern s16 lbl_1_bss_3056;

static inline s32 ListVisible02A8(List02A8* list) {
    if (list->_08 + list->_0C < list->_10) {
        return list->_0C;
    }
    if (list->_10 < list->_0C) {
        return list->_10;
    }
    return list->_10 - list->_08;
}

// .text:0x0000C2A4 size:0x38
void fn_1_C2A4(void) {
    ((Task02A8*)lbl_803CC1B8)->_0C->_10 = 1;
    fn_800B0A14_removeQueue();
}

// .text:0x0000C188 size:0x11C
void fn_1_C188(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FDD) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(lbl_1_bss_2FD9 + 5, fn_1_A908);
        lbl_1_bss_2FDD++;
        break;
    case 1:
        if (task->_10 != 0) {
            if (lbl_1_bss_2FD9 != 17) {
                lbl_1_bss_2FD9++;
                lbl_1_bss_2FDD = 0;
                break;
            }
            task->_10 = 0;
            lbl_1_bss_2FDD++;
        }
        break;
    case 2:
        task->_00 = fn_1_BFB0;
        lbl_1_bss_2FDD = 0;
        break;
    }
}

// .text:0x0000BFB0 size:0x1D8
void fn_1_BFB0(void) {
    u16 trg = lbl_803C77B8[0]._02;
    u16 rep = lbl_803C77B8[0]._04;
    s16 n;

    if (trg & 0x100) {
        fn_1_BF34((u16)(lbl_1_bss_3056 % 13 + lbl_1_data_17C4[lbl_1_bss_3056 / 13]));
    } else if (trg & 0x1200) {
        fn_1_A718();
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A348;
    } else if (rep & 1) {
        if (rep & 0x800) {
            lbl_1_bss_3056 -= 10;
        } else {
            lbl_1_bss_3056 -= 1;
        }
        if (lbl_1_bss_3056 < 0) {
            lbl_1_bss_3056 = 233;
        }
    } else if (rep & 2) {
        n = lbl_1_bss_3056 + 1;
        if (rep & 0x800) {
            n = lbl_1_bss_3056 + 10;
        }
        lbl_1_bss_3056 = n;
        if (n > 233) {
            lbl_1_bss_3056 = 0;
        }
    }
}

// .text:0x0000BF34 size:0x7C
s32 fn_1_BF34(s32 fx) {
    SND_VOICEID vid = sndFXStartEx(fx, 0x7F, 0x3F, 0);

    OSReport("sndFXReverb was %s.\n", sndFXCtrl(vid, 0x5B, fn_800211F0()) ? "succeed" : "failed");
    return vid;
}

// .text:0x0000BEF4 size:0x40
void fn_1_BEF4(s16 vid) {
    sndFXKeyOff(vid);
    sndFXCtrl(vid, 7, 0);
}

// .text:0x0000BDD8 size:0x11C
void fn_1_BDD8(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FDE) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(lbl_1_data_1CA0 + 5, fn_1_A8B4);
        lbl_1_bss_2FDE++;
        break;
    case 1:
        if (task->_10 != 0) {
            if (lbl_1_data_1CA0 != 31) {
                lbl_1_data_1CA0++;
                lbl_1_bss_2FDE = 0;
                break;
            }
            task->_10 = 0;
            lbl_1_bss_2FDE++;
        }
        break;
    case 2:
        task->_00 = fn_1_BC00;
        lbl_1_bss_2FDE = 0;
        break;
    }
}

// .text:0x0000BC00 size:0x1D8
void fn_1_BC00(void) {
    u16 trg = lbl_803C77B8[0]._02;
    u16 rep = lbl_803C77B8[0]._04;
    s16 n;

    if (trg & 0x100) {
        fn_1_BF34((u16)(lbl_1_bss_3054 % 13 + lbl_1_data_17E8[lbl_1_bss_3054 / 13]));
    } else if (trg & 0x1200) {
        fn_1_A718();
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A348;
    } else if (rep & 1) {
        if (rep & 0x800) {
            lbl_1_bss_3054 -= 10;
        } else {
            lbl_1_bss_3054 -= 1;
        }
        if (lbl_1_bss_3054 < 0) {
            lbl_1_bss_3054 = 181;
        }
    } else if (rep & 2) {
        n = lbl_1_bss_3054 + 1;
        if (rep & 0x800) {
            n = lbl_1_bss_3054 + 10;
        }
        lbl_1_bss_3054 = n;
        if (n > 181) {
            lbl_1_bss_3054 = 0;
        }
    }
}

// .text:0x0000BA64 size:0x19C
void fn_1_BA64(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FDF) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(1, fn_1_A880);
        lbl_1_bss_2FDF++;
        break;
    case 1:
        if (task->_10 != 0) {
            task->_10 = 0;
            lbl_1_bss_2FDF++;
        }
        break;
    case 2:
        task->_10 = 0;
        lbl_1_bss_2FDF++;
        break;
    case 3:
        task->_10 = 0;
        lbl_1_bss_2FDF++;
        break;
    case 4:
        lbl_1_bss_2FDF++;
        break;
    case 5:
        lbl_1_bss_2FDF++;
        break;
    case 6:
        task->_10 = 0;
        fn_1_9EA0(41, fn_1_A77C);
        lbl_1_bss_2FDF++;
        break;
    case 7:
        if (task->_10 != 0) {
            task->_10 = 0;
            lbl_1_bss_2FDF++;
        }
        break;
    case 8:
        task->_00 = fn_1_B5B8;
        lbl_1_bss_2FDF = 0;
        break;
    }
}

// .text:0x0000B4A4 size:0x114
void fn_1_B4A4(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FE8) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(42, fn_1_A7E4);
        lbl_1_bss_2FE8++;
        break;
    case 1:
        if (task->_10 != 0) {
            lbl_800EF808._396 = 2;
            sndOutputMode(2);
            task->_10 = 0;
            lbl_1_bss_2FE8++;
        }
        break;
    case 2:
        task->_00 = fn_1_A95C;
        lbl_1_common_bss_49994._E0 = 0;
        lbl_1_bss_2FE8 = 0;
        break;
    }
}

// Loads a sound group into its slot of the bank table; the slot is computed by the caller
static inline void LoadGroup02A8(s32 group, s32 slot) {
    fn_80021518(group, lbl_800EF808.groups[slot]);
}

// .text:0x0000A908 size:0x54
s32 fn_1_A908(u8* arg0) {
    LoadGroup02A8(lbl_1_data_17A4[lbl_1_bss_2FD9], lbl_1_bss_2FD9 + 5);
    return 0;
}

// .text:0x0000A8B4 size:0x54
s32 fn_1_A8B4(u8* arg0) {
    LoadGroup02A8(lbl_1_data_17A4[lbl_1_data_1CA0], lbl_1_data_1CA0 + 5);
    return 0;
}

// .text:0x0000A880 size:0x34
s32 fn_1_A880(u8* arg0) {
    fn_80021518(0x1C, lbl_800EF808.groups[1]);
    return 0;
}

// .text:0x0000A838 size:0x48
s32 fn_1_A838(u8* arg0) {
    fn_80021518(0x1C, lbl_800EF808.groups[3]);
    fn_80021518(0x36, lbl_800EF808.groups[3]);
    return 0;
}

// .text:0x0000A7E4 size:0x54
s32 fn_1_A7E4(u8* arg0) {
    LoadGroup02A8(lbl_1_data_1884[lbl_1_bss_2FDB], lbl_1_bss_2FDB + 42);
    return 0;
}

// .text:0x0000A7B0 size:0x34
s32 fn_1_A7B0(u8* arg0) {
    fn_80021518(0x33, lbl_800EF808.groups[49]);
    return 0;
}

// .text:0x0000A77C size:0x34
s32 fn_1_A77C(u8* arg0) {
    fn_80021518(0x31, lbl_800EF808.groups[41]);
    return 0;
}

// .text:0x0000A718 size:0x64
BOOL fn_1_A718(void) {
    s8 i;

    for (i = (s8)lbl_800EF808._390 - 1; i > 0; i--) {
        if (!fn_800214D0()) {
            return FALSE;
        }
    }
    return TRUE;
}

// .text:0x0000A714 size:0x4
void fn_1_A714(void) {
}

// .text:0x0000A634 size:0xE0
void fn_1_A634(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (lbl_1_bss_2FEE) {
    case 0:
        task->_10 = 0;
        fn_1_9EA0(3, fn_1_A838);
        lbl_1_bss_2FEE++;
        break;
    case 1:
        if (task->_10 != 0) {
            task->_10 = 0;
            lbl_1_bss_2FEE++;
        }
        break;
    case 2:
        task->_00 = fn_1_A464;
        lbl_1_bss_2FEE = 0;
        break;
    }
}

// .text:0x0000A464 size:0x1D0
void fn_1_A464(void) {
    u16 trg = lbl_803C77B8[0]._02;
    u16 rep = lbl_803C77B8[0]._04;
    s16 n;

    if (trg & 0x100) {
        fn_1_BEF4(lbl_1_data_1CA8);
        lbl_1_data_1CA8 = fn_1_BF34(lbl_1_data_1CA4);
    } else if (trg & 0x1200) {
        fn_1_A718();
        fn_800ACFB0(lbl_800EF808.groups[3]);
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A348;
    } else if (rep & 1) {
        if (rep & 0x800) {
            lbl_1_data_1CA4 -= 10;
        } else {
            lbl_1_data_1CA4 -= 1;
        }
        if (lbl_1_data_1CA4 < 0x1AD) {
            lbl_1_data_1CA4 = 0x1B6;
        }
    } else if (rep & 2) {
        n = lbl_1_data_1CA4 + 1;
        if (rep & 0x800) {
            n = lbl_1_data_1CA4 + 10;
        }
        lbl_1_data_1CA4 = n;
        if (n > 0x1B6) {
            lbl_1_data_1CA4 = 0x151;
        }
    }
}

// .text:0x0000A348 size:0x11C
void fn_1_A348(void) {
    u16 rep = lbl_803C77B8[0]._04;
    u16 trg = lbl_803C77B8[0]._02;

    if (rep & 8) {
        lbl_1_common_bss_49A78._00 = (lbl_1_common_bss_49A78._00 + 4) % 5;
    } else if (rep & 4) {
        lbl_1_common_bss_49A78._00 = (lbl_1_common_bss_49A78._00 + 6) % 5;
    } else if (trg & 0x100) {
        ((Task02A8*)lbl_803CC1B8)->_00 = lbl_1_data_1C8C[lbl_1_common_bss_49A78._00];
        lbl_1_common_bss_49A78._01 = 0;
    } else if (trg & 0x1200) {
        lbl_1_bss_2FDA = 0;
        lbl_1_bss_2FD9 = 0;
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_C2A4;
    }
}

// .text:0x0000A2E4 size:0x64
void fn_1_A2E4(void) {
    switch (lbl_1_bss_2FDA) {
    case 0:
        lbl_1_bss_2FDA++;
        break;
    case 1:
        lbl_1_bss_2FDA++;
        break;
    case 2:
        ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A250;
        break;
    }
}

// .text:0x0000A250 size:0x94
void fn_1_A250(void) {
    s32 i;

    for (i = 0; i < 11; i++) {
        lbl_1_common_bss_49A78._24[i] = -1;
    }
    lbl_1_common_bss_49A78._0C = -1;
    ((Task02A8*)lbl_803CC1B8)->_00 = fn_1_A348;
}

// .text:0x0000A210 size:0x40
char* fn_1_A210(char* path) {
    char c;
    char* name = path;

    if (path == NULL) {
        return NULL;
    }
    while ((c = *path++) != 0) {
        if (c == '/') {
            name = path;
        }
    }
    return name;
}

// .text:0x0000A1F4 size:0x1C
void fn_1_A1F4(List02A8* list, ListEntry02A8* entries, s32 count, s32 page) {
    list->_00 = entries;
    list->_10 = count;
    list->_0C = page;
    list->_08 = 0;
    list->_04 = 0;
}

// .text:0x0000A184 size:0x70
// Differs only in registers: the entry pointer takes r3 and the string r4, the
// target the reverse (r5/r3). Declaration orders and loop forms did not change it.
void fn_1_A184(List02A8* list) {
    s32 n = ListVisible02A8(list);
    ListEntry02A8* entry = &list->_00[list->_08];
    s32 i;
    char* p;

    for (i = 0; i < n; i++, entry++) {
        if ((p = entry->_00) != NULL) {
            while (*p++ != 0) {
            }
        }
    }
}

// .text:0x0000A024 size:0x160
void fn_1_A024(List02A8* list, s32 dir) {
    s32 top = list->_08;
    s32 page = list->_0C;
    s32 count = list->_10;
    s32 cur = list->_04;
    s32 rel = cur - top;
    s32 n;

    if (top + page < count) {
        n = page;
    } else if (count < page) {
        n = count;
    } else {
        n = count - top;
    }

    switch (dir) {
    case 0:
        if (rel != 0) {
            list->_04--;
        } else if (top != 0) {
            list->_08--;
            list->_04--;
        }
        break;
    case 1:
        if (rel + 1 == n) {
            if (cur + 1 < count) {
                list->_08++;
                list->_04++;
            }
        } else {
            list->_04++;
        }
        break;
    case 2:
        if (top < page) {
            list->_08 = 0;
            list->_04 = 0;
        } else {
            list->_08 -= page;
            list->_04 -= list->_0C;
        }
        break;
    case 3:
        if (cur + n >= count) {
            list->_08 = count - n;
            list->_04 = list->_10 - 1;
        } else {
            list->_08 += page;
            list->_04 += list->_0C;
        }
        break;
    }
}

// .text:0x00009F04 size:0x120
void fn_1_9F04(void) {
    Task02A8* task = lbl_803CC1B8;

    switch (task->_18) {
    case 0:
        lbl_800EF808.groups[task->_19] = ARAMTransfer(&lbl_1_data_196C[task->_19], 0, 1, 0);
        task->_18 = 1;
        break;
    case 1:
        if (lbl_803C6CF8._715 != 1) {
            break;
        }
        fn_80021980(lbl_800EF808.groups[task->_19]);
        task->_18 = 2;
        task->_1A = 0;
    case 2:
        if (task->_14(&task->_1A) == 0) {
            fn_80021954(&lbl_800EF808.groups[task->_19]);
            task->_0C->_10 = 1;
            fn_800B0A14_removeQueue();
        }
        break;
    }
}

// .text:0x00009EA0 size:0x64
void fn_1_9EA0(s32 index, s32 (*callback)(u8* arg0)) {
    Task02A8* task = fn_800B0A5C_insertQueue(fn_1_9F04, 1);

    task->_18 = 0;
    task->_19 = index;
    task->_14 = callback;
    ((Task02A8*)lbl_803CC1B8)->_10 = 0;
}
