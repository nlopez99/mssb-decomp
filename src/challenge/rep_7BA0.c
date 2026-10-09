#include "challenge/rep_7BA0.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/pad.h"
#include "string.h"

typedef struct Task7BA0Parent {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u16 _10;
} Task7BA0Parent;

typedef struct Task7BA0 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ Task7BA0Parent* _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
} Task7BA0;

// A movie's location: a flag, its size, its offset and its size again
typedef struct Movie7BA0 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
} Movie7BA0; // size: 0x10

typedef struct Work7BA0 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ void* _08;
    /* 0x0C */ void* _0C;
} Work7BA0; // size: 0x10

extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800AD038(void* arg0);
extern void fn_800AD070(void);
extern void fn_800AD500(void* arg0, void* arg1);
extern u32 fn_800AD6BC(void* arg0);
extern s32 fn_800AD780(void* arg0);
extern void fn_800AD830(void* arg0);
extern void fn_800AD95C(void* arg0, s32 arg1);
extern void fn_800AD9F4(void* arg0);
extern s32 fn_800ADAFC(void);
extern s32 fn_800ADB04(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern void fn_800ADBFC(void);
extern void fn_800ADC40(void* arg0, u32 arg1);
extern void fn_800B0A14_removeQueue(void);

Movie7BA0 lbl_1_data_112D8[2] = {
    { 0x00000000, 0x05233458, 0x00012000, 0x05233458 },
    { 0 },
};
s32 lbl_1_data_112F8[2] = { 0 };

Work7BA0 lbl_1_bss_47058;

// .text:0x238 size:0x60
void fn_1_2852C(void) {
    Task7BA0* task = lbl_803CC1B8;

    fn_800AD038(lbl_80366158._08);
    task->_14 = 0;
    task->_15 = 0;
    ((Task7BA0*)lbl_803CC1B8)->_00 = fn_1_284A8;
}

// .text:0x1B4 size:0x84
void fn_1_284A8(void) {
    Task7BA0* task = lbl_803CC1B8;

    if (lbl_803C77B8[0]._04 & (PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT)) {
        task->_15 ^= 1;
    } else if (lbl_803C77B8[0]._04 & PAD_BUTTON_A) {
        task->_14 = 0;
        ((Task7BA0*)lbl_803CC1B8)->_00 = fn_1_282F4;
    } else if (lbl_803C77B8[0]._04 & PAD_BUTTON_B) {
        ((Task7BA0*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0 size:0x1B4
void fn_1_282F4(void) {
    Work7BA0* work = &lbl_1_bss_47058;
    Task7BA0* task = lbl_803CC1B8;
    u32 size;

    switch (task->_14) {
    case 0:
        work->_0C = _OSAllocFromHeap(0x20, 0x1C0);
        memset(work->_0C, 0, 0x1C0);
        work->_00 = 0x400000;
        work->_04 = _OSAllocFromHeap(0x20, 0x400000);
        fn_800ADC40(work->_04, work->_00);
        task->_14++;
        break;
    case 1:
        fn_800ADB04(&lbl_1_data_112D8[task->_15], work->_0C, 1, 0);
        task->_14++;
    case 2:
        if (fn_800ADAFC()) {
            size = fn_800AD6BC(work->_0C);
            work->_08 = _OSAllocFromHeap(0x20, size);
            fn_800AD500(work->_0C, work->_08);
            fn_800AD95C(work->_0C, 1);
            task->_14++;
        }
        break;
    case 3:
        if (lbl_803C77B8[0]._02 & PAD_BUTTON_B) {
            fn_800AD830(work->_0C);
            task->_14++;
        }
    case 4:
        if (fn_800AD780(work->_0C)) {
            fn_800AD9F4(work->_0C);
            fn_800ADBFC();
            fn_800AD038(lbl_80366158._08);
            task->_14 = 0;
            ((Task7BA0*)lbl_803CC1B8)->_00 = fn_1_284A8;
        } else {
            fn_800AD070();
        }
        break;
    }
}
