#include "menus/rep_07F0.h"
#include "menus/rep_0898.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/pad.h"
#include "Dolphin/gx.h"
#include "string.h"
#include "menus/rep_08E8.h"

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u16 _10;
} UnkTaskParent07F0;

typedef struct {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ UnkTaskParent07F0* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x28 - 0x12];
    /* 0x28 */ s8 _28;
} UnkTask07F0;

typedef struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x4 - 0x1];
    /* 0x04 */ u32 _04;
    /* 0x08 */ void* _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ void* _10;
    /* 0x14 */ u8 _14[0x18 - 0x14];
} UnkWork07F0; // size: 0x18

UnkWork07F0 lbl_2_bss_15A0;

// One movie's cue: frames _00 to _04 show caption _08; -1 ends the list.
typedef struct {
    /* 0x0 */ s32 _00;
    /* 0x4 */ s32 _04;
    /* 0x8 */ s32 _08;
} UnkCue07F0; // size: 0xC

extern UnkCue07F0 lbl_2_data_34E0[2][8];

extern struct {
    /* 0x000000 */ u8 _000000[0x16264E];
    /* 0x16264E */ u8 _16264E;
    /* 0x16264F */ u8 _16264F[0x162835 - 0x16264F];
    /* 0x162835 */ u8 _162835;
    /* 0x162836 */ u8 _162836;
    /* 0x162837 */ u8 _162837;
    /* 0x162838 */ u8 _162838;
    /* 0x162839 */ u8 _162839;
    /* 0x16283A */ u8 _16283A[0x162992 - 0x16283A];
    /* 0x162992 */ u8 _162992;
} *lbl_2_bss_1A8234;

extern struct {
    /* 0x00000 */ u8 _00000[0x32A86];
    /* 0x32A86 */ u8 _32A86;
} *lbl_2_bss_1A8230;

extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern struct {
    /* 0x0000 */ u8 _0000[0x441C];
    /* 0x441C */ u8 _441C;
} *lbl_2_bss_1A8248;

extern struct {
    /* 0x000000 */ u8 _000000[0x1976B0];
    /* 0x1976B0 */ s32 _1976B0;
    /* 0x1976B4 */ s32 _1976B4;
    /* 0x1976B8 */ s32 _1976B8;
    /* 0x1976BC */ s32 _1976BC;
    /* 0x1976C0 */ u8 _1976C0[0x1976E4 - 0x1976C0];
    /* 0x1976E4 */ s16 _1976E4;
    /* 0x1976E6 */ u8 _1976E6[0x19774C - 0x1976E6];
    /* 0x19774C */ s16 _19774C;
    /* 0x19774E */ u8 _19774E[0x19783F - 0x19774E];
    /* 0x19783F */ u8 _19783F;
    /* 0x197840 */ u8 _197840[0x197863 - 0x197840];
    /* 0x197863 */ s8 _197863;
} *lbl_2_bss_1A824C;

extern u32 lbl_803CB850[4];
extern void* lbl_803CC1B8;

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80009018(void* arg0);
extern void fn_800AD070(void);
extern void fn_800AD500(void* arg0, void* arg1);
extern u32 fn_800AD6BC(void* arg0);
extern s32 fn_800AD780(void* arg0);
extern void fn_800AD95C(void* arg0, s32 arg1);
extern void fn_800AD830(void* arg0);
extern void fn_800AD9F4(void* arg0);
extern s32 fn_800AED24(void);
extern s32 fn_800ADAFC(void);
extern s32 fn_800ADB04(void* arg0, void* arg1, s32 arg2, s32 arg3);
extern void fn_800ADBFC(void);
extern void fn_800ADC40(void* arg0, u32 arg1);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void changeScene(u8, s16);
extern u8 fn_80068514(s32 arg0, s32 arg1);
extern u8 fn_8006862C(s32 arg0, s32 arg1);
extern void fn_8006877C(s32 arg0);
extern void fn_800A86B4(s32 arg0);
extern void fn_2_245C8(void);
extern void fn_2_42388(void);
extern void fn_2_515DC(s32 arg0);
extern void fn_2_54474(void);

typedef struct UnkEntry07F0 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ s32 _04;
    /* 0x08 */ u32 _08;
    /* 0x0C */ u32 _0C;
    /* 0x10 */ u32 _10;
    /* 0x14 */ u32 _14;
    /* 0x18 */ u32 _18;
    /* 0x1C */ u32 _1C;
} UnkEntry07F0; // size: 0x20

typedef struct UnkTable07F0 {
    /* 0x00 */ s32* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ u32* _08[4];
    /* 0x18 */ struct UnkTable07F0* _18;
    /* 0x1C */ u32* _1C[3];
    /* 0x28 */ UnkEntry07F0 _28[4];
    /* 0xA8 */ u32 _A8[3];
} UnkTable07F0; // size: 0xB4

u32 lbl_2_data_12170[4] = { 0, 0x0033452C, 0x05245800, 0x0033452C };
u32 lbl_2_data_12180[4] = { 0, 0x01700804, 0x0557A000, 0x01700804 };
s32 lbl_2_data_12190[11] = { 1, 0, 0x12, 0, 0, 0x6E, 0x16, 0, 0, -0x80, 0x7FFFFFFF };
UnkTable07F0 lbl_2_data_121BC = {
    lbl_2_data_12190,
    -1,
    { &lbl_803CB850[2], &lbl_803CB850[2], &lbl_803CB850[2], &lbl_803CB850[2] },
    &lbl_2_data_121BC,
    { &lbl_803CB850[2], &lbl_803CB850[2], &lbl_803CB850[2] },
    {
        { fn_2_37D94, 0, 0x00010064, 0x00800000, 0, 0, 9, 0 },
        { fn_2_37D8C, 1, 0x00010010, 0, 0, 0, 0x80000005, 0 },
        { fn_2_37D90, 0, 0x00010064, 0x00800000, 0, 0, 9, 0 },
        { fn_2_37D88, 1, 0x00010010, 0, 0, 0, 0x20000005, 0 },
    },
    { 0x000A0019, 0x002D0000, 0x11775500 },
};
GXColor lbl_2_data_12270 = { 0 };

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

// .text:0x000379D0 size:0x3A0
void fn_2_379D0(void) {
    UnkTask07F0* task = lbl_803CC1B8;
    UnkTask07F0* child;
    u8 busy;

    switch (task->_28) {
    case 0:
        if (fn_2_4EABC() == 1) {
            task->_28 = 1;
        }
        break;
    case 1:
        GXSetCopyClear(lbl_2_data_12270, 0xFFFFFF);
        changeScene(1, 6);
        fn_2_515DC(4);
        lbl_2_bss_1A8234->_162992 = 0;
        lbl_2_bss_1A8230->_32A86 = 0;
        fn_2_54474();
        fn_2_245C8();
        lbl_2_bss_1A824C->_1976E4 = 360;
        lbl_2_bss_15A0._00 = 0;
        task->_28 = 2;
        break;
    case 2:
        task->_28 = 3;
        break;
    case 3:
        if (lbl_8037169C._12) {
            child = fn_800B0A5C_insertQueue(fn_2_37630, 2);
            child->_28 = 0;
            task->_10 = 0;
            task->_28 = 4;
        }
        break;
    case 4:
        if (task->_10 != 0) {
            if (lbl_2_bss_15A0._00) {
                changeScene(3, 6);
                lbl_2_bss_1A8234->_162838 = 1;
                lbl_2_bss_1A8234->_162839 = 1;
                lbl_2_bss_1A8234->_162835 = 1;
                lbl_2_bss_1A8234->_162837 = 1;
                task->_28 = 7;
                break;
            }
            fn_8006877C(11);
            if (lbl_2_bss_1A8248->_441C == 5) {
                fn_2_422FC(1);
            } else {
                fn_2_422FC(0);
            }
            child = fn_800B0A5C_insertQueue(fn_2_42388, 2);
            child->_28 = 0;
            task->_10 = 0;
            task->_28 = 5;
        }
        break;
    case 5:
        busy = fn_80068514(0x78, 0x7F);
        if (task->_10 == 1) {
            lbl_2_bss_1A824C->_19783F = 0;
            changeScene(3, 6);
            lbl_2_bss_1A8234->_162838 = 1;
            lbl_2_bss_1A8234->_162839 = 1;
            lbl_2_bss_1A8234->_162835 = 1;
            lbl_2_bss_1A8234->_162837 = 1;
            task->_28 = 6;
        }
        if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & PAD_BUTTON_START) && busy == 0) {
            lbl_2_bss_1A824C->_19783F = 1;
        }
        break;
    case 6:
        if (fn_8006862C(0x78, 0) == 0) {
            task->_28 = 7;
        }
        break;
    case 7:
        if (lbl_8037169C._13) {
            fn_800A86B4(3);
            GXSetCopyClear(lbl_2_data_12270, 0xFFFFFF);
            lbl_2_bss_1A8234->_162992 = 1;
            lbl_2_bss_1A8230->_32A86 = 1;
            task->_28 = 8;
        }
        break;
    case 8:
        fn_2_4E8E0();
        ((UnkTask07F0*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x00037630 size:0x3A0
void fn_2_37630(void) {
    UnkWork07F0* work = &lbl_2_bss_15A0;
    UnkTask07F0* task = lbl_803CC1B8;
    u32 size;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A824C->_1976B0 = 0;
        lbl_2_bss_1A824C->_1976B4 = 0;
        lbl_2_bss_1A824C->_1976B8 = 0;
        lbl_2_bss_1A824C->_1976BC = 0;
        fn_2_4E824();
        work->_10 = _OSAllocFromHeap(0x20, 0x1C0);
        memset(work->_10, 0, 0x1C0);
        work->_04 = 0x400000;
        work->_08 = _OSAllocFromHeap(0x20, 0x400000);
        fn_800ADC40(work->_08, work->_04);
        task->_28++;
        break;
    case 1:
        if (fn_800ADB04(lbl_2_data_12170, work->_10, 1, 0)) {
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
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & PAD_BUTTON_START) {
            work->_00 = 1;
            fn_800AD830(work->_10);
            task->_28++;
            break;
        }
        lbl_2_bss_1A824C->_1976B4++;
        fn_800AD070();
        if (fn_800AED24() == 1) {
            lbl_2_bss_1A824C->_1976B0++;
            if (lbl_2_bss_1A824C->_1976B0 == lbl_2_data_34E0[lbl_2_bss_1A8248->_441C == 5][lbl_2_bss_1A824C->_1976B8]._00 &&
                lbl_2_bss_1A824C->_1976BC == 0 &&
                lbl_2_data_34E0[lbl_2_bss_1A8248->_441C == 5][lbl_2_bss_1A824C->_1976B8]._00 != -1)
            {
                lbl_2_bss_1A824C->_19774C = lbl_2_data_34E0[lbl_2_bss_1A8248->_441C == 5][lbl_2_bss_1A824C->_1976B8]._08;
                lbl_2_bss_1A824C->_1976BC = 1;
                lbl_2_bss_1A8234->_16264E = 1;
            } else if (lbl_2_bss_1A824C->_1976B0 == lbl_2_data_34E0[lbl_2_bss_1A8248->_441C == 5][lbl_2_bss_1A824C->_1976B8]._04 &&
                       lbl_2_bss_1A824C->_1976BC == 1 &&
                       lbl_2_data_34E0[lbl_2_bss_1A8248->_441C == 5][lbl_2_bss_1A824C->_1976B8]._00 != -1)
            {
                lbl_2_bss_1A8234->_162838 = 1;
                lbl_2_bss_1A824C->_1976B8++;
                lbl_2_bss_1A824C->_1976BC = 0;
            }
        }
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
