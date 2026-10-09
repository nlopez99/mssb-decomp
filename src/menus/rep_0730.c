#include "header_rep_data.h"
#include "menus/rep_0730.h"

typedef struct MenuTask0730 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct MenuTask0730* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x28 - 0x12];
    /* 0x28 */ s8 _28;
} MenuTask0730;

typedef struct TexFile0730 {
    /* 0x0 */ void* _0;
    /* 0x4 */ void* _4;
    /* 0x8 */ u32* _8;
} TexFile0730;

extern void* lbl_803CC1B8;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x000000 */ u8 _000000[0x197746];
    /* 0x197746 */ s16 _197746;
} *lbl_2_bss_1A824C;

extern u8 lbl_2_bss_1034C[];

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void* ARAMTransfer(void* entry, s32 arg1, s32 arg2, u32 aram);
extern void convertTextureHeader(void* tex);
extern void fn_8004B1B8(void* tex);

extern void fn_2_409CC(void);
extern void fn_2_47CFC(void);
extern s32 fn_2_4E970(void);
extern s32 fn_2_4E9A8(void);
extern s32 fn_2_4EAF4(void);
extern s32 fn_2_4EB2C(void);
extern s32 fn_2_4EB64(void);
extern void fn_2_68FBC(s32, s32);
extern void fn_2_8ACB0(s32, s32);
extern void fn_2_8AEE0(void);
extern void fn_2_8CCAC(s32, s32);
extern void fn_2_8E478(void);
extern void fn_2_8EA80(void);

// .data:0x00004B90 size:0x10
u32 lbl_2_data_4B90[4] = { 0x0000040B, 0x40046100, 0x0E641000, 0x00024B48 };

// .data:0x00004BA0 size:0x8
struct {
    TexFile0730* _0;
    u32 _4;
} lbl_2_data_4BA0 = { (TexFile0730*)lbl_2_bss_1034C, 0x11775500 };

// .data:0x00004BA8 size:0xC
u32 lbl_2_data_4BA8[3] = { 0x00000000, 0x01000001, 0x02010000 };

// .text:0x0001B6CC size:0xE8
void fn_2_1B6CC(void) {
    MenuTask0730* task = lbl_803CC1B8;
    MenuTask0730* sub;

    switch (task->_28) {
    case 0:
        sub = fn_800B0A5C_insertQueue(fn_2_409CC, 2);
        sub->_28 = 0;
        task->_10 = 0;
        task->_28 = 1;
        break;
    case 1:
        if (task->_10 == 1) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (fn_2_4EB64() == 1) {
            task->_28 = 3;
        }
        break;
    case 3:
        if (fn_2_4EB2C() == 1) {
            task->_28 = 4;
        }
        break;
    case 4:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x0001B5C0 size:0x10C
void fn_2_1B5C0(void) {
    MenuTask0730* task = lbl_803CC1B8;
    MenuTask0730* sub;

    switch (task->_28) {
    case 0:
        sub = fn_800B0A5C_insertQueue(fn_2_409CC, 2);
        sub->_28 = 0;
        task->_10 = 0;
        task->_28 = 1;
        break;
    case 1:
        if (task->_10 == 1) {
            task->_28 = 2;
        }
        break;
    case 2:
        if (fn_2_4EB64() == 1) {
            task->_28 = 3;
        }
        break;
    case 3:
        if (fn_2_4EB2C() == 1) {
            task->_28 = 4;
        }
        break;
    case 4:
        if (fn_2_4EAF4() == 1) {
            task->_28 = 5;
        }
        break;
    case 5:
        if (fn_2_4E9A8() == 1) {
            task->_28 = 6;
        }
        break;
    case 6:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x0001B52C size:0x94
void fn_2_1B52C(void) {
    MenuTask0730* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        if (fn_2_4E970() == 1) {
            task->_28 = 1;
        }
        break;
    case 1:
        task->_28 = 6;
        break;
    case 6:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x0001B314 size:0x218
void fn_2_1B314(void) {
    MenuTask0730* task = lbl_803CC1B8;
    MenuTask0730* sub;
    s32 i;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A824C->_197746 = 7;
        sub = fn_800B0A5C_insertQueue(fn_2_8EA80, 2);
        sub->_28 = 0;
        task->_10 = 0;
        task->_28 = 1;
        break;
    case 1:
        if (task->_10 == 1) {
            task->_28 = 2;
        }
        break;
    case 2:
        sub = fn_800B0A5C_insertQueue(fn_2_8E478, 2);
        sub->_28 = 0;
        task->_10 = 0;
        task->_28 = 3;
        break;
    case 3:
        if (task->_10 == 1) {
            task->_28 = 12;
        }
        break;
    case 4:
        for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
            fn_2_8CCAC(i, 1);
            fn_2_68FBC(i, 1);
        }
        task->_28 = 5;
        break;
    case 5:
        fn_2_47CFC();
        task->_28 = 6;
        break;
    case 6:
        for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
            fn_2_8CCAC(i, 0);
        }
        fn_2_47CFC();
        task->_28 = 7;
        break;
    case 7:
        fn_2_47CFC();
        task->_28 = 8;
        break;
    case 8:
        task->_28 = 9;
        break;
    case 9:
        fn_2_8AEE0();
        task->_28 = 10;
        break;
    case 10:
        for (i = 0; i < 29; i++) {
            fn_2_8ACB0(i, 0);
        }
        fn_2_8AEE0();
        task->_28 = 11;
        break;
    case 11:
        fn_2_8AEE0();
        task->_28 = 12;
        break;
    case 12:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x0001B1BC size:0x158
void fn_2_1B1BC(void) {
    MenuTask0730* task = lbl_803CC1B8;
    u32* file;
    void* tex;
    s32 i;

    switch (task->_28) {
    case 0:
        lbl_2_data_4BA0._0 = (TexFile0730*)lbl_2_bss_1034C;
        lbl_2_data_4BA0._0->_8 = ARAMTransfer(lbl_2_data_4B90, 0, 0, 0);
        task->_28 = 1;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            task->_28 = 2;
        }
        break;
    case 2:
        file = lbl_2_data_4BA0._0->_8;
        i = 0;
        tex = (u8*)file + file[i++];
        while (i-- != 0) {
            file[i] += (u32)file;
        }
        convertTextureHeader(tex);
        lbl_2_data_4BA0._0->_4 = (void*)lbl_2_data_4BA0._0->_8[0];
        fn_8004B1B8(lbl_2_data_4BA0._0->_4);
        task->_28 = 3;
        break;
    case 3:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}
