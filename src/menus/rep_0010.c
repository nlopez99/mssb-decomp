#include "menus/rep_0010.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/pad.h"
#include "Dolphin/os.h"
#include "musyx/musyx.h"

// A ring buffer of 32 commands
typedef struct UnkQueue0010 {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ u8 state;
    /* 0x15 */ u8 head;
    /* 0x16 */ u8 tail;
    /* 0x17 */ s8 entries[32];
} UnkQueue0010;

typedef struct UnkTask0010 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct UnkTask0010* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ u16 _14;
} UnkTask0010;

typedef struct {
    /* 0x0 */ u16 _0;
    /* 0x2 */ u16 _2;
    /* 0x4 */ u16 _4;
} UnkPad0010; // size: 0x6

typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u16 _04;
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0xC - 0x8];
    /* 0x0C */ u16 _0C[2];
    /* 0x10 */ u8 _10;
} UnkScene0010;

extern UnkScene0010* lbl_803CBBCC;
extern UnkScene0010 lbl_800E877C;
extern void* lbl_803CC1B8;
extern s32 lbl_803CB750;

extern struct {
    /* 0x0000 */ u8 _0000[0x46F8];
    /* 0x46F8 */ s8 _46F8[4];
    /* 0x46FC */ u8 _46FC[0x472C - 0x46FC];
    /* 0x472C */ UnkPad0010 _472C[4];
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0x55];
    /* 0x55 */ u8 _55[4];
} lbl_803C66B0;

extern struct {
    /* 0x00 */ u8 _00[0x1D];
    /* 0x1D */ u8 _1D;
} lbl_80366158;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern u32 lbl_2_bss_B644;

extern u32 lbl_2_data_0[2][23];
extern u8 lbl_2_data_C8[];
extern u8 lbl_2_data_C0[];
extern UnkQueue0010* lbl_2_bss_4[5];

extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800B0A14_removeQueue(void);
extern void fn_800A7D4C(s32 arg0, void* arg1);
extern void fn_80036C88(u32* arg0, u32* arg1);
extern void fn_800B0D28(u32* arg0);
extern void fn_80062744(void);
extern void fn_8001E474(void);
extern void fn_8001F228(void);
extern void fn_8004153C(void);
extern void fn_800A97D0(s32 arg0, s32 arg1);
extern void* ARAMTransfer(void* entry, void* dst, s32 arg2, u32 aram);
extern void fn_800216F8(u8 group, int (*callback)(void));
extern int fn_2_10FC(void);
extern void fn_2_11A0(s32 arg0);
extern BOOL fn_80022A24(u8 stadium, u8 arg1);
extern void fn_800229CC(void);
extern void fn_2_11D8(void);

// .text:0x00000A14 size:0x5C
void fn_2_A14(void) {
    fn_800B0A5C_insertQueue(fn_2_160, 0x1000);
    fn_800B0A5C_insertQueue(fn_2_110, 0xF000);
    lbl_803CBBCC->_04 = 0;
    lbl_803CBBCC->_02 = 0;
}

// .text:0x00000978 size:0x9C
// 60.77%: the target dispatches through a jump table (cases 0 to 9); every
// switch tried, with or without the empty cases, builds a compare tree.
void fn_2_978(void) {
    u8 mode = lbl_80366158._1D;

    fn_800B0A5C_insertQueue(fn_2_11D8, 0x2000);
    switch (mode) {
    case 0:
        fn_2_11A0(0x11);
        break;
    case 1:
        fn_2_11A0(0xE);
        break;
    case 7:
        fn_2_11A0(1);
        break;
    case 9:
        fn_2_11A0(1);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
        break;
    }
    lbl_80366158._1D = 1;
}

// .text:0x00000940 size:0x38
void fn_2_940(void) {
    if (lbl_803CBBCC->_00 == 5) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00000794 size:0x1AC
// 85.70%: only the inlined fn_2_978's switch differs (see there).
void fn_2_794(void) {
    UnkTask0010* task = lbl_803CC1B8;

    switch (lbl_803CBBCC->_00) {
    case 0:
        task->_10 = 0;
        fn_2_A14();
        fn_800B0A5C_insertQueue(fn_2_940, 0x100);
        lbl_803CBBCC->_00++;
        break;
    case 1:
        lbl_803CBBCC->_00 = 3;
        break;
    case 3:
        fn_2_978();
        lbl_803CBBCC->_00 = 4;
    case 4:
        if (task->_10 == 0) {
            break;
        }
        lbl_803CBBCC->_00 = 5;
    case 5:
        task->_0C->_10 = task->_10;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x00000708 size:0x8C
void fn_2_708(void) {
    UnkTask0010* task = lbl_803CC1B8;

    lbl_803CB750 += OSGetTick();
    fn_8004153C();
    fn_800A97D0(0x10, 0x1E);
    lbl_803CBBCC->_00 = 0;
    task->_14 = 0;
    fn_800B0A5C_insertQueue(fn_2_664, 0x1000);
    ((UnkTask0010*)lbl_803CC1B8)->_00 = fn_2_554;
}

// .text:0x00000664 size:0xA4
void fn_2_664(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (lbl_803C66B0._55[i] == 1 || lbl_8034E9A0._46F8[i] == -1) {
            lbl_8034E9A0._472C[i]._0 = 0;
            lbl_8034E9A0._472C[i]._2 = 0;
            lbl_8034E9A0._472C[i]._4 = 0;
        } else {
            lbl_8034E9A0._472C[i]._0 = lbl_803C77B8[lbl_8034E9A0._46F8[i]]._00;
            lbl_8034E9A0._472C[i]._2 = lbl_803C77B8[lbl_8034E9A0._46F8[i]]._02;
            lbl_8034E9A0._472C[i]._4 = lbl_803C77B8[lbl_8034E9A0._46F8[i]]._04;
        }
    }
}

// .text:0x00000554 size:0x110
void fn_2_554(void) {
    UnkTask0010* task = lbl_803CC1B8;

    switch (task->_14) {
    case 0:
        lbl_2_bss_B644 = OSGetTick();
        fn_800216F8(2, fn_2_10FC);
        task->_14 = 1;
    case 1:
        if (((UnkTask0010*)lbl_803CC1B8)->_10 == 0) {
            break;
        }
        sndVolume(0x7F, 10, 0xFF);
        task->_14 = 2;
    case 2:
        ARAMTransfer(lbl_2_data_C8, &lbl_8034E9A0, 1, 0);
        task->_14 = 3;
        break;
    case 3:
        if (lbl_803C6CF8._715 == 1) {
            task->_00 = fn_2_794;
            lbl_2_bss_4[0] = fn_800B0A5C_insertQueue(fn_2_374, 0x8000);
        }
        break;
    }
}

// .text:0x00000510 size:0x44
s8 fn_2_510(UnkQueue0010* queue) {
    if (queue->tail == queue->head) {
        return 0;
    }
    queue->tail = (queue->tail + 1) % 32;
    return queue->entries[queue->tail];
}

// .text:0x000004C4 size:0x4C
BOOL fn_2_4C4(UnkQueue0010* queue, s8 command) {
    u8 next = (queue->head + 1) % 32;

    if (next == queue->tail) {
        return FALSE;
    }
    queue->head = next;
    queue->entries[queue->head] = command;
    return TRUE;
}

// .text:0x00000374 size:0x150
void fn_2_374(void) {
    UnkQueue0010* queue = lbl_803CC1B8;

    switch (queue->state) {
    case 0:
        queue->state = fn_2_510(queue);
        break;
    case 1:
        if (!fn_80022A24(g_d_GameSettings.StadiumID, g_d_GameSettings.miniGameStadiumIndicator)) {
            break;
        }
        if ((queue->state = fn_2_510(queue)) != 2) {
            break;
        }
    case 2:
        fn_800229CC();
        queue->state = fn_2_510(queue);
        break;
    }
}

// .text:0x00000328 size:0x4C
void fn_2_328(void) {
    fn_2_4C4(lbl_2_bss_4[0], 1);
}

// .text:0x000002DC size:0x4C
void fn_2_2DC(void) {
    fn_2_4C4(lbl_2_bss_4[0], 2);
}

// .text:0x000002D8 size:0x4
void fn_2_2D8(void) {}

// .text:0x000001A8 size:0x130
s32 fn_2_1A8(u8 port, u8 kind, u16 mask) {
    u16 buttons = 0;
    s32 result = -1;

    switch (kind) {
    case 0:
        buttons = lbl_803C77B8[port]._00;
        break;
    case 1:
        buttons = lbl_803CBBCC->_0C[port];
        break;
    case 2:
        buttons = lbl_803C77B8[port]._04;
        break;
    }
    buttons &= mask;
    if (kind == 1) {
        lbl_803CBBCC->_10 |= 1 << port;
    }
    if (buttons & PAD_BUTTON_A) {
        result = 4;
    } else if (buttons & PAD_BUTTON_B) {
        result = 5;
    } else if (buttons & PAD_BUTTON_UP) {
        result = 0;
    } else if (buttons & PAD_BUTTON_DOWN) {
        result = 1;
    } else if (buttons & PAD_BUTTON_LEFT) {
        result = 2;
    } else if (buttons & PAD_BUTTON_RIGHT) {
        result = 3;
    } else if (buttons & PAD_TRIGGER_L) {
        result = 6;
    } else if (buttons & PAD_TRIGGER_R) {
        result = 7;
    }
    return result;
}

// .text:0x00000160 size:0x48
void fn_2_160(void) {
    lbl_803CBBCC->_0C[0] |= lbl_803C77B8[0]._02;
    lbl_803CBBCC->_0C[1] |= lbl_803C77B8[1]._02;
    lbl_803CBBCC->_10 = 0;
}

// .text:0x00000110 size:0x50
void fn_2_110(void) {
    u8 i;

    for (i = 0; i < 2; i++) {
        if (lbl_803CBBCC->_10 & (1 << i)) {
            lbl_803CBBCC->_0C[i] = 0;
        }
    }
}

// .text:0x00000088 size:0x88
void _prolog(void) {
    lbl_803CBBCC = &lbl_800E877C;
    lbl_800E877C._02 = 0;
    fn_800A7D4C(0, lbl_2_data_C0);
    fn_800B0A5C_insertQueue(fn_2_708, 0x8000);
    fn_80062744();
    fn_8001E474();
    fn_80036C88(lbl_2_data_0[0], lbl_2_data_0[1]);
    fn_800B0D28(lbl_2_data_0[1]);
}

// .text:0x00000068 size:0x20
void _epilog(void) {
    fn_8001F228();
}

// .text:0x0000003C size:0x2C
void fn_2_3C(void) {
    fn_800A7D4C(0, lbl_2_data_C0);
}

// .text:0x00000000 size:0x3C
void fn_2_0(void) {
    GXSetZCompLoc(GX_FALSE);
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
}
