#include "static/static_8004A1BC.h"
#include "static/spani_default.h"
#include "static/static_80048EB8.h"
#include "static/static_8004C9FC.h"
#include "musyx/musyx.h"
#include "static/UnknownHomes_Static.h"

typedef struct Scene {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u16 _04;
    /* 0x06 */ u8 _06[0x10 - 0x06];
    /* 0x10 */ u8 _10;
} Scene;

// The message window at lbl_803C50E8
typedef struct MsgWindow {
    /* 0x00 */ u8 _00[3];
    /* 0x03 */ u8 port;
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05[0x3E - 0x05];
    /* 0x3E */ u8 _3E;
    /* 0x3F */ u8 msg;
    /* 0x40 */ u8 _40;
    /* 0x41 */ u8 _41;
    /* 0x42 */ u8 _42[2];
    /* 0x44 */ u8 _44;
    /* 0x45 */ u8 result;
    /* 0x46 */ u8 _46;
    /* 0x47 */ u8 _47;
    /* 0x48 */ u8 _48;
    /* 0x49 */ u8 _49;
    /* 0x4A */ u16 _4A;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 _4F;
    /* 0x50 */ u16 _50;
} MsgWindow;

typedef struct MsgEntry {
    /* 0x00 */ u16 id;
    /* 0x02 */ u8 kind;
    /* 0x03 */ u8 _03;
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05;
} MsgEntry; // size: 0x6

typedef struct MsgParent {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
} MsgParent;

typedef struct MsgTask {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ MsgParent* parent;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ MsgWindow* window;
    /* 0x18 */ u8 state;
    /* 0x19 */ u8 timer;
    /* 0x1A */ u8 result;
    /* 0x1B */ u8 _1B;
} MsgTask;

extern MsgTask* lbl_803CC1B8;
extern MsgWindow lbl_803C50E8;
extern u8 lbl_803C5F74[0xB4];
extern u8 lbl_800EFBA4[16];

typedef struct Card {
    /* 0x00 */ u8 _00[0x3E];
    /* 0x3E */ u8 _3E;
} Card;

extern Scene* lbl_803CBBCC;

extern struct {
    /* 0x00 */ u8 _00[0x2C];
    /* 0x2C */ u16 _2C;
    /* 0x2E */ u8 _2E;
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u16 _30;
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34;
    /* 0x35 */ u8 _35;
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 dir[4];
    /* 0x3B */ s8 option[5];
    /* 0x40 */ s8 prevOption[5];
    /* 0x45 */ s8 toggle[4][4];
    /* 0x55 */ s8 prevToggle[4][4];
    /* 0x65 */ s8 cursor[4];
    /* 0x69 */ s8 prevCursor[4];
} lbl_803C5F04;

extern struct {
    /* 0x00 */ u8 _00[0x55];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[0x5D - 0x57];
    /* 0x5D */ u8 _5D;
    /* 0x5E */ u8 _5E;
} lbl_803C66B0;

extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800B0A14_removeQueue(void);
extern void changeScene(s32 arg0, s32 arg1);
extern void fn_800569C8(void);
extern void fn_800625A4(s32 arg0, s32 arg1);
extern void fn_80062A74(void);
extern void fn_80062674(s32 arg0);
extern void fn_80021410(void);

u32 lbl_800FB5B0[4] = { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 };
MsgEntry lbl_800FB5C0[0x4E] = {
    { 0xA8, 3, 10, 0, 0 },
    { 0xA9, 1, 5, 0, 1 },
    { 0xAA, 1, 4, 1, 0 },
    { 0xAB, 2, 7, 0, 0 },
    { 0xAC, 2, 7, 0, 0 },
    { 0xAD, 1, 5, 0, 0 },
    { 0xAE, 1, 5, 0, 0 },
    { 0xAF, 2, 7, 0, 0 },
    { 0xB0, 3, 10, 0, 0 },
    { 0xB1, 1, 4, 0, 1 },
    { 0xB2, 1, 4, 0, 1 },
    { 0xB3, 1, 4, 0, 0 },
    { 0xB4, 3, 10, 0, 0 },
    { 0xB5, 2, 7, 0, 0 },
    { 0xB6, 1, 6, 0, 0 },
    { 0xB7, 1, 6, 0, 0 },
    { 0xB8, 3, 10, 0, 0 },
    { 0xB9, 1, 4, 0, 1 },
    { 0xBA, 1, 4, 0, 0 },
    { 0xBB, 1, 5, 0, 1 },
    { 0xBC, 1, 5, 0, 1 },
    { 0xBD, 1, 5, 0, 1 },
    { 0xBE, 3, 10, 0, 0 },
    { 0xBF, 1, 4, 0, 1 },
    { 0xC0, 2, 7, 0, 0 },
    { 0xC1, 1, 2, 0, 0 },
    { 0xC2, 1, 2, 0, 0 },
    { 0xC3, 1, 4, 0, 0 },
    { 0xC4, 1, 4, 0, 0 },
    { 0xC5, 1, 4, 0, 0 },
    { 0xC6, 1, 4, 0, 0 },
    { 0xC7, 1, 0, 0, 0 },
    { 0xC8, 2, 7, 0, 0 },
    { 0xC9, 2, 7, 0, 0 },
    { 0xCA, 3, 10, 0, 0 },
    { 0xCB, 1, 4, 0, 0 },
    { 0xCC, 1, 4, 0, 0 },
    { 0xCD, 2, 7, 0, 0 },
    { 0xCE, 1, 4, 0, 0 },
    { 0xCF, 1, 4, 0, 0 },
    { 0xD0, 3, 10, 0, 0 },
    { 0xD1, 1, 4, 1, 0 },
    { 0xD2, 1, 4, 0, 1 },
    { 0xD3, 1, 4, 0, 1 },
    { 0xD4, 3, 10, 0, 0 },
    { 0xD5, 2, 7, 0, 0 },
    { 0xD6, 1, 4, 1, 0 },
    { 0xD7, 1, 4, 1, 0 },
    { 0xD8, 1, 4, 0, 1 },
    { 0xD9, 1, 4, 0, 1 },
    { 0xDA, 3, 10, 0, 0 },
    { 0xDB, 2, 7, 0, 0 },
    { 0xDC, 1, 4, 0, 0 },
    { 0xDD, 1, 4, 0, 0 },
    { 0xDE, 2, 7, 0, 0 },
    { 0xDF, 2, 7, 0, 0 },
    { 0xE0, 2, 7, 0, 0 },
    { 0xE1, 1, 4, 0, 0 },
    { 0xE2, 3, 10, 0, 0 },
    { 0xE3, 2, 7, 0, 0 },
    { 0xE4, 2, 7, 0, 0 },
    { 0xE5, 2, 7, 0, 0 },
    { 0xE6, 2, 7, 0, 0 },
    { 0xE7, 1, 6, 0, 1 },
    { 0xE8, 1, 6, 0, 1 },
    { 0xE9, 1, 5, 0, 1 },
    { 0xEA, 1, 5, 0, 1 },
    { 0xEB, 1, 5, 0, 1 },
    { 0xEC, 1, 5, 0, 1 },
    { 0xED, 1, 5, 0, 1 },
    { 0xEE, 1, 5, 0, 1 },
    { 0xEF, 1, 5, 0, 1 },
    { 0xF0, 1, 5, 0, 1 },
    { 0x0, 1, 4, 0, 0 },
    { 0x1BE, 1, 2, 0, 0 },
    { 0x1BF, 2, 7, 0, 0 },
    { 0x1C0, 2, 7, 0, 0 },
    { 0xA8, 3, 10, 0, 0 },
};

// .text:0x8004A9E0 size:0x1F8
void fn_8004A9E0(void) {
    MsgTask* task = lbl_803CC1B8;
    u8 port = task->window->port;
    u16 pressed = lbl_803C77B8[port]._02;

    lbl_803CBBCC->_10 |= 1 << port;
    switch (task->state) {
    case 0:
        task->timer = 15;
        task->state++;
        break;
    case 1:
        fn_8004CC4C(lbl_803C50E8._4C, 1, lbl_803C50E8._4E, lbl_803C50E8._4D, lbl_803C50E8._50);
        if (lbl_803C50E8._4F != 0) {
            lbl_803C5F74[0x1E] = 1;
        }
        fn_800B0A5C_insertQueue(fn_8004D0F0, 0x3000);
        task->state++;
        break;
    case 2:
        if (task->timer != 0) {
            task->timer--;
        } else {
            task->result = 0;
            task->state = 3;
        }
        break;
    case 3:
        if (pressed & 0x100) {
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            task->state++;
            task->result = 1;
        } else if (pressed & 0x200) {
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
            task->state++;
            task->result = 4;
        }
        break;
    case 4:
        task->timer = 15;
        task->state++;
        break;
    case 5:
        if (task->timer != 0) {
            task->timer--;
        } else {
            lbl_803CC1B8->parent->_10 = task->result;
            fn_800B0A14_removeQueue();
        }
        break;
    }
}

// .text:0x8004A7D0 size:0x210
void fn_8004A7D0(void) {
    MsgTask* task = lbl_803CC1B8;
    u8 port = task->window->port;
    u16 pressed = lbl_803C77B8[port]._02;

    lbl_803CBBCC->_10 |= 1 << port;
    switch (task->state) {
    case 0:
        lbl_803C50E8._44 = 0;
        lbl_803C50E8.result = 0;
        lbl_803C50E8._46 = 0;
        task->state++;
        break;
    case 1:
        fn_8004CC4C(lbl_803C50E8._4C, 1, lbl_803C50E8._4E, lbl_803C50E8._4D, lbl_803C50E8._50);
        if (lbl_803C50E8._4F != 0) {
            lbl_803C5F74[0x1E] = 1;
        }
        fn_800B0A5C_insertQueue(fn_8004D0F0, 0x3000);
        task->state++;
        break;
    case 2:
        if (lbl_803C50E8._46 != 0) {
            fn_8004CC18();
            lbl_803C50E8._46 = 0;
            task->result = 0;
            task->state = 3;
        } else {
            switch (fn_8004CA6C(pressed)) {
            case 0:
                task->result = 0;
                break;
            case 1:
                fn_8004CC2C();
                break;
            case 3:
                task->result = 2;
                task->state = 5;
                break;
            case 2:
                fn_8004CC2C();
                break;
            case 4:
                task->result = 4;
                task->state = 5;
                break;
            }
        }
        break;
    case 3:
        task->state = 4;
        break;
    case 4:
        task->timer = 100;
        task->state++;
        break;
    case 5:
        lbl_803C50E8._44 = 1;
        lbl_803C50E8.result = task->result;
        fn_800B0A14_removeQueue();
        task->_1B = 0;
        task->state = 0;
        break;
    }
}

// .text:0x8004A5B8 size:0x218
void fn_8004A5B8(void) {
    MsgTask* task = lbl_803CC1B8;
    u8 port = task->window->port;
    u32 pressed = lbl_803C77B8[port]._02 & 0x100;

    lbl_803CBBCC->_10 |= 1 << port;
    switch (task->state) {
    case 0:
        lbl_803C50E8._44 = 0;
        lbl_803C50E8.result = 0;
        lbl_803C50E8._46 = 0;
        task->state++;
        break;
    case 1:
        fn_8004CC4C(lbl_803C50E8._4C, 1, lbl_803C50E8._4E, lbl_803C50E8._4D, lbl_803C50E8._50);
        if (lbl_803C50E8._4F != 0) {
            lbl_803C5F74[0x1E] = 1;
        }
        fn_800B0A5C_insertQueue(fn_8004D0F0, 0x3000);
        task->state = 3;
        break;
    case 2:
        task->state = 3;
        task->result = 0;
        break;
    case 3:
        if (lbl_803C50E8._46 != 0) {
            fn_8004CC18();
            lbl_803C50E8._46 = 0;
            task->result = 0;
            task->state = 5;
        } else {
            switch (fn_8004CA6C(pressed)) {
            case 0:
                task->result = 0;
                break;
            case 1:
                fn_8004CC2C();
                break;
            case 3:
                task->result = 2;
                task->state = 5;
                break;
            case 2:
                fn_8004CC2C();
                break;
            case 4:
                task->result = 2;
                task->state = 5;
                break;
            }
        }
        break;
    case 4:
        task->timer = 15;
        task->state++;
        break;
    case 5:
        lbl_803C50E8._44 = 1;
        lbl_803C50E8.result = task->result;
        fn_800B0A14_removeQueue();
        task->_1B = 0;
        task->state = 0;
        break;
    }
}

// .text:0x8004A34C size:0x26C
s32 fn_8004A34C(MsgWindow* window, u8 arg1, u8 msg, u8 arg3, u8 arg4) {
    MsgTask* task = NULL;

    window->msg = msg;
    window->_40 = arg1;
    window->_41 = arg3;
    window->_3E = 1;
    if (lbl_800FB5C0[msg]._03 == 10) {
        if (lbl_803C50E8._49 != 0) {
            if (lbl_803C50E8._48 != 0) {
                fn_8004CC18();
                lbl_803C50E8._48 = 0;
                lbl_803C50E8._49 = 0;
            } else if (lbl_803C50E8._4A != lbl_800FB5C0[msg].id) {
                lbl_803C50E8._4A = lbl_800FB5C0[msg].id;
                fn_8004CA14(0, lbl_800FB5C0[msg].id);
            }
        } else {
            fn_8004CC4C(lbl_800FB5C0[msg]._03, 1, lbl_800FB5C0[msg]._04, arg4, lbl_800FB5C0[msg].id);
            if (lbl_800FB5C0[msg]._05 != 0) {
                lbl_803C5F74[0x1E] = 1;
            }
            fn_800B0A5C_insertQueue(fn_8004D0F0, 0x3000);
            lbl_803C50E8._48 = 0;
            lbl_803C50E8._49 = 1;
            lbl_803C50E8._4A = lbl_800FB5C0[msg].id;
        }
    } else {
        if (lbl_803C50E8._49 != 0) {
            fn_8004CC18();
            lbl_803C50E8._49 = 0;
            lbl_803C50E8._48 = 0;
        }
        lbl_803C50E8._4C = lbl_800FB5C0[msg]._03;
        lbl_803C50E8._50 = lbl_800FB5C0[msg].id;
        lbl_803C50E8._4E = lbl_800FB5C0[msg]._04;
        lbl_803C50E8._4F = lbl_800FB5C0[msg]._05;
        lbl_803C50E8._4D = arg4;
        lbl_803C50E8.result = 0;
        switch (lbl_800FB5C0[msg].kind) {
        case 0:
            task = fn_800B0A5C_insertQueue(fn_8004A9E0, 0x8000);
            task->_1B = 1;
            break;
        case 1:
            task = fn_800B0A5C_insertQueue(fn_8004A7D0, 0x8000);
            task->_1B = 1;
            break;
        case 2:
            task = fn_800B0A5C_insertQueue(fn_8004A5B8, 0x8000);
            task->_1B = 1;
            break;
        case 3:
            task = fn_800B0A5C_insertQueue(fn_8004A7D0, 1);
            task->_1B = 0;
            break;
        }
    }
    if (task != NULL) {
        task->window = window;
        task->state = 0;
        task->window->_04 = 0;
    }
    return 1;
}

// .text:0x8004A328 size:0x24
s32 fn_8004A328(Card* card) {
    if (card->_3E != 0) {
        return 0;
    }
    card->_3E = 2;
    return 1;
}

// .text:0x8004A2BC size:0x6C
void fn_8004A2BC(void) {
    switch (lbl_803CBBCC->_04) {
    case 0:
        fn_800B0A5C_insertQueue(fn_8004A1BC, 0x2000);
        lbl_803C5F04._2C = 0;
        lbl_803CBBCC->_04++;
        break;
    case 1:
        break;
    }
}

// .text:0x8004A1BC size:0x100
void fn_8004A1BC(void) {
    s32 i;

    switch (lbl_803C5F04._30) {
    case 0:
        fn_80049C80();
        break;
    case 1:
        if (lbl_803C66B0._5D == 0) {
            lbl_803C5F04._30++;
        }
        break;
    case 2:
        for (i = 0; i < 2; i++) {
            fn_800494CC(i);
        }
        break;
    case 3:
        for (i = 0; i < 2; i++) {
            fn_80049220(i);
        }
        break;
    case 4:
        if (fn_80035838(lbl_800FB5B0, 6)) {
            lbl_803C5F04._32 = 1;
            lbl_803C5F04._30 = 0;
        }
        break;
    case 5:
        startGameRelated();
        break;
    }
    fn_80049D3C();
}
