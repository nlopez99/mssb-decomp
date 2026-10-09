#include "menus/rep_07F0.h"
#include "header_rep_data.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u16 _10;
} UnkTaskParent07F0;

typedef struct {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ UnkTaskParent07F0* _0C;
    /* 0x10 */ u8 _10[0x28 - 0x10];
    /* 0x28 */ s8 _28;
} UnkTask07F0;

typedef struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ u32 _04;
    /* 0x08 */ void* _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ void* _10;
    /* 0x14 */ u8 _14[0x18 - 0x14];
} UnkWork07F0; // size: 0x18

UnkWork07F0 lbl_2_bss_15A0;

extern u8 lbl_2_data_12180[];
extern void* lbl_803CC1B8;

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80009018(void* arg0);
extern void fn_800AD070(void);
extern void fn_800AD500(void* arg0, void* arg1);
extern u32 fn_800AD6BC(void* arg0);
extern s32 fn_800AD780(void* arg0);
extern void fn_800AD95C(void* arg0, s32 arg1);
extern void fn_800AD9F4(void* arg0);
extern s32 fn_800ADAFC(void);
extern s32 fn_800ADB04(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern void fn_800ADBFC(void);
extern void fn_800ADC40(void* arg0, u32 arg1);
extern void fn_2_4E7EC(void);
extern void fn_2_4E824(void);

// .text:0x00037D94 size:0x4
void fn_2_37D94(void) {}

// .text:0x00037D90 size:0x4
void fn_2_37D90(void) {}

// .text:0x00037D8C size:0x4
void fn_2_37D8C(void) {}

// .text:0x00037D88 size:0x4
void fn_2_37D88(void) {}

// .text:0x00037D84 size:0x4
void fn_2_37D84(void) {}

// .text:0x00037D80 size:0x4
void fn_2_37D80(void) {}

// .text:0x00037D7C size:0x4
void fn_2_37D7C(void) {}

// .text:0x00037D78 size:0x4
void fn_2_37D78(void) {}

// .text:0x00037D74 size:0x4
void fn_2_37D74(void) {}

// .text:0x00037D70 size:0x4
void fn_2_37D70(void) {}

// .text:0x00037460 size:0x1D0
void fn_2_37460(void) {
    UnkWork07F0* work = &lbl_2_bss_15A0;
    UnkTask07F0* task = lbl_803CC1B8;
    u32 size;

    switch (task->_28) {
    case 0:
        fn_2_4E824();
        work->_10 = _OSAllocFromHeap(0x20, 0x1C0);
        memset(work->_10, 0, 0x1C0);
        work->_04 = 0x400000;
        work->_08 = _OSAllocFromHeap(0x20, 0x400000);
        fn_800ADC40(work->_08, work->_04);
        task->_28++;
        break;
    case 1:
        if (fn_800ADB04(lbl_2_data_12180, work->_10, 1, 0)) {
            fn_80009018(work->_10);
            task->_28++;
        }
        break;
    case 2:
        if (fn_800ADAFC()) {
            size = fn_800AD6BC(work->_10);
            work->_0C = _OSAllocFromHeap(0x20, size);
            fn_800AD500(work->_10, work->_0C);
            fn_800AD95C(work->_10, 1);
            task->_28++;
        }
        break;
    case 3:
        fn_800AD070();
        if (fn_800AD780(work->_10)) {
            task->_28++;
        }
        break;
    case 4:
        if (fn_800AD780(work->_10)) {
            fn_80009018(NULL);
            fn_800AD9F4(work->_10);
            fn_800ADBFC();
            task->_28++;
        }
        break;
    case 5:
        fn_2_4E7EC();
        ((UnkTask07F0*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}
