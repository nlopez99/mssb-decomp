#include "header_rep_data.h"
#include "menus/rep_0730.h"
#include "menus/rep_0788.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "string.h"

typedef struct MenuTask0730 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
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
    /* 0x000000 */ u8 _000000[0x1976C0];
    /* 0x1976C0 */ s32 _1976C0;
    /* 0x1976C4 */ u8 _1976C4[0x1976D6 - 0x1976C4];
    /* 0x1976D6 */ s16 _1976D6;
    /* 0x1976D8 */ u8 _1976D8[0x197746 - 0x1976D8];
    /* 0x197746 */ s16 _197746;
    /* 0x197748 */ u8 _197748[0x197756 - 0x197748];
    /* 0x197756 */ s16 _197756[8];
    /* 0x197766 */ u8 _197766[0x197833 - 0x197766];
    /* 0x197833 */ u8 _197833;
    /* 0x197834 */ u8 _197834;
    /* 0x197835 */ u8 _197835;
    /* 0x197836 */ u8 _197836[0x197838 - 0x197836];
    /* 0x197838 */ u8 _197838;
    /* 0x197839 */ u8 _197839[0x197843 - 0x197839];
    /* 0x197843 */ s8 _197843;
    /* 0x197844 */ u8 _197844[0x197848 - 0x197844];
    /* 0x197848 */ u8 _197848;
    /* 0x197849 */ u8 _197849[0x197863 - 0x197849];
    /* 0x197863 */ s8 _197863;
} *lbl_2_bss_1A824C;

extern struct {
    /* 0x0000 */ u8 _0000[0x1605];
    /* 0x1605 */ u8 _1605;
    /* 0x1606 */ s8 _1606;
    /* 0x1607 */ u8 _1607[0x4415 - 0x1607];
    /* 0x4415 */ u8 _4415;
    /* 0x4416 */ u8 _4416[0x441C - 0x4416];
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E[0x4426 - 0x441E];
    /* 0x4426 */ u8 _4426;
    /* 0x4427 */ u8 _4427[0x44F2 - 0x4427];
    /* 0x44F2 */ u8 _44F2;
    /* 0x44F3 */ u8 _44F3;
    /* 0x44F4 */ s8 _44F4;
} *lbl_2_bss_1A8248;

extern struct {
    /* 0x00 */ u8 _00[0x30];
    /* 0x30 */ s16 _30;
    /* 0x32 */ s16 _32;
    /* 0x34 */ u8 _34;
} *lbl_2_bss_1A823C;

extern struct {
    /* 0x000000 */ u8 _000000[0x162992];
    /* 0x162992 */ u8 _162992;
} *lbl_2_bss_1A8234;

extern struct {
    /* 0x00000 */ u8 _00000[0x32A86];
    /* 0x32A86 */ u8 _32A86;
} *lbl_2_bss_1A8230;

extern void* lbl_2_bss_1A8238;
extern void* lbl_2_bss_1A8244;
extern void* lbl_2_bss_340140;
extern u8 lbl_2_bss_1A8250[0x1978FC];

extern struct Unk8034E9A0 {
    /* 0x0000 */ u8 _0000[0x46E0];
    /* 0x46E0 */ s32 _46E0;
    /* 0x46E4 */ u8 _46E4[0x46F8 - 0x46E4];
    /* 0x46F8 */ s8 _46F8;
} lbl_8034E9A0;

extern u8 lbl_80361B20[0x130];
extern u8 starMissionCompletionTracker[0x4508];
extern u8 lbl_800E877C[0x38];
extern u8 lbl_8036E548[];
extern u8 lbl_803CB8F0[8];

extern u8 lbl_2_bss_1034C[];

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void changeScene(u8, s16);
extern void fn_8000F4B8(s32, s32, s32, s32);
extern void fn_8001F228(void);
extern void fn_800216F8(u8 group, int (*callback)(void));
extern int fn_800627F8(void);
extern void fn_8006877C(s32);
extern void fn_8006C488(void);
extern void fn_800B0A14_removeQueue(void);
extern void* ARAMTransfer(void* entry, s32 arg1, s32 arg2, u32 aram);
extern void convertTextureHeader(void* tex);
extern void fn_8004B1B8(void* tex);

extern void fn_2_409CC(void);
extern void fn_2_37460(void);
extern void fn_2_379D0(void);
extern void fn_2_37D98(void);
extern void fn_2_40A9C(void);
extern void fn_2_454E8(void);
extern void fn_2_46418(void);
extern void fn_2_466AC(void);
extern void fn_2_467FC(void);
extern void fn_2_468DC(void);
extern s32 fn_2_46D00(void);
extern void fn_2_47CFC(void);
extern void fn_2_4AB1C(void);
extern s32 fn_2_4E970(void);
extern s32 fn_2_4E9A8(void);
extern s32 fn_2_4EAF4(void);
extern s32 fn_2_4EB2C(void);
extern s32 fn_2_4EB64(void);
extern void fn_2_68FBC(s32, s32);
extern void fn_2_54474(void);
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
struct {
    GXColor _0;
    u32 _4[2];
} lbl_2_data_4BA8 = { { 0x00, 0x00, 0x00, 0x00 }, { 0x01000001, 0x02010000 } };

// .text:0x0001B7B4 size:0x79C
// 98.12%: the target computes &lbl_8034E9A0 before case 0's memset (into r30) and names
// g_d_GameSettings there, and keeps `flag` in r22; the rest is register numbers.
void fn_2_1B7B4(void) {
    struct Unk8034E9A0* data;
    GameInitVariables* settings;
    MenuTask0730* task;
    MenuTask0730* sub;
    s32 flag;

    settings = &g_d_GameSettings;
    data = &lbl_8034E9A0;
    task = lbl_803CC1B8;
    lbl_2_bss_1A824C = (void*)lbl_2_bss_1A8250;
    lbl_2_bss_1A8248 = (void*)starMissionCompletionTracker;
    lbl_2_bss_1A8238 = (void*)&starMissionCompletionTracker[0x1610];
    lbl_2_bss_1A8244 = (void*)lbl_80361B20;
    lbl_2_bss_1A823C = (void*)lbl_800E877C;
    lbl_2_bss_1A8234 = (void*)lbl_2_bss_1A8250;
    lbl_2_bss_1A8230 = (void*)&lbl_2_bss_1A8250[0x162998];
    lbl_2_bss_340140 = (void*)lbl_8036E548;
    switch (lbl_2_bss_1A823C->_32) {
    case 0:
        fn_8006C488();
        fn_8001F228();
        lbl_2_bss_1A823C->_34 = 1;
        memset(lbl_2_bss_1A8250, 0, sizeof(lbl_2_bss_1A8250));
        lbl_2_bss_1A824C->_197756[0] = -1;
        lbl_2_bss_1A824C->_197756[1] = -1;
        lbl_2_bss_1A824C->_197756[2] = -1;
        lbl_2_bss_1A824C->_197756[3] = -1;
        lbl_2_bss_1A824C->_197756[4] = -1;
        lbl_2_bss_1A824C->_197756[5] = -1;
        lbl_2_bss_1A824C->_197756[6] = -1;
        lbl_2_bss_1A824C->_197756[7] = -1;
        fn_2_54474();
        lbl_2_bss_1A8248->_44F2 = 0;
        lbl_2_bss_1A824C->_1976D6 = 0;
        lbl_2_bss_1A824C->_197833 = 0;
        lbl_2_bss_1A8234->_162992 = 0;
        lbl_2_bss_1A824C->_197838 = 0;
        lbl_2_bss_1A824C->_197835 = 0;
        settings->StadiumID = 0;
        lbl_2_bss_1A824C->_197863 = lbl_8034E9A0._46F8;
        lbl_2_bss_1A824C->_197848 = 0;
        fn_8000F4B8(0, -1, -1, -1);
        lbl_2_bss_1A823C->_32 = 2;
        break;
    case 1:
        if (task->_10 == 1) {
            lbl_2_bss_1A823C->_32 = 2;
        }
        break;
    case 2:
        lbl_2_bss_1A823C->_32 = 3;
        break;
    case 3:
        lbl_2_bss_1A823C->_32 = 4;
        break;
    case 4:
        flag = 0;
        if (lbl_2_bss_1A823C->_30 == 3) {
            fn_2_4AB1C();
            if (lbl_2_bss_1A824C->_197843 == 0) {
                if (lbl_2_bss_1A8248->_441C == 5) {
                    if (fn_2_46D00() != 0) {
                        flag = 1;
                    }
                } else if (lbl_2_bss_1A8248->_4426 & 0x20) {
                    flag = 1;
                }
            }
        }
        lbl_2_bss_1A8248->_44F4 = flag != 0;
        if (lbl_2_bss_1A8248->_44F4 == 0) {
            lbl_2_bss_1A823C->_32 = 12;
        } else {
            GXSetCopyClear(lbl_2_data_4BA8._0, 0xFFFFFF);
            changeScene(1, 6);
            if (lbl_2_bss_1A8248->_4415 >= 3) {
                if (fn_2_4E970() == 1) {
                    lbl_2_bss_1A823C->_32 = 5;
                }
            } else {
                lbl_2_bss_1A823C->_32 = 12;
            }
        }
        break;
    case 5:
        sub = fn_800B0A5C_insertQueue(fn_2_37460, 2);
        sub->_28 = 0;
        task->_10 = 0;
        lbl_2_bss_1A823C->_32 = 6;
        break;
    case 6:
        if (task->_10 == 1) {
            lbl_2_bss_1A823C->_32 = 7;
        }
        break;
    case 7:
        lbl_2_bss_1A8234->_162992 = 0;
        lbl_2_bss_1A8230->_32A86 = 0;
        fn_2_54474();
        fn_2_2460C();
        lbl_2_bss_1A823C->_32 = 8;
        break;
    case 8:
        fn_8006877C(13);
        sub = fn_800B0A5C_insertQueue(fn_2_37D98, 2);
        sub->_28 = 0;
        task->_10 = 0;
        lbl_2_bss_1A823C->_32 = 9;
        break;
    case 9:
        if (task->_10 == 1) {
            lbl_2_bss_1A823C->_32 = 10;
        }
        break;
    case 10:
        sub = fn_800B0A5C_insertQueue(fn_2_40A9C, 2);
        sub->_28 = 0;
        task->_10 = 0;
        lbl_2_bss_1A823C->_32 = 11;
        break;
    case 11:
        if (task->_10 == 1) {
            lbl_2_bss_1A823C->_32 = 12;
        }
        break;
    case 12:
        if (lbl_2_bss_1A8248->_44F4 == 0) {
            sub = fn_800B0A5C_insertQueue(fn_2_1B6CC, 2);
            sub->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A823C->_32 = 13;
        } else {
            sub = fn_800B0A5C_insertQueue(fn_2_1B5C0, 2);
            sub->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A823C->_32 = 13;
        }
        break;
    case 13:
        if (task->_10 == 1) {
            lbl_2_bss_1A823C->_32 = 14;
        }
        break;
    case 14:
        fn_800216F8(0x26, fn_800627F8);
        task->_10 = 0;
        lbl_2_bss_1A823C->_32 = 15;
        break;
    case 15:
        if (task->_10 == 1) {
            lbl_2_bss_1A823C->_32 = 18;
        }
        break;
    case 18:
        switch (lbl_2_bss_1A823C->_30) {
        case 0:
            lbl_2_bss_1A8248->_441C = fn_2_20CB0(data->_46E0);
            lbl_2_bss_1A8248->_441D = lbl_803CB8F0[lbl_2_bss_1A8248->_441C];
            if (lbl_2_bss_1A8248->_1606 == 0) {
                lbl_2_bss_1A8248->_1605 = 0;
                fn_2_207FC();
                fn_2_466AC();
            } else {
                fn_2_20328();
                fn_2_46418();
                fn_2_468DC();
                fn_2_466AC();
                fn_2_467FC();
                fn_2_454E8();
            }
            sub = fn_800B0A5C_insertQueue(fn_2_379D0, 2);
            sub->_28 = 0;
            task->_10 = 0;
            lbl_2_bss_1A823C->_32 = 19;
            break;
        case 1:
            fn_2_468DC();
            lbl_2_bss_1A823C->_32 = 23;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            lbl_2_bss_1A8248->_44F2 = 0;
            lbl_2_bss_1A823C->_32 = 23;
            break;
        case 8:
            lbl_2_bss_1A8248->_44F2 = 0;
            lbl_2_bss_1A823C->_32 = 23;
            break;
        }
        break;
    case 19:
        if (task->_10 == 1) {
            lbl_2_bss_1A823C->_32 = 23;
        }
        break;
    case 20:
        lbl_2_bss_1A824C->_197746 = 7;
        sub = fn_800B0A5C_insertQueue(fn_2_1B314, 2);
        sub->_28 = 0;
        task->_10 = 0;
        lbl_2_bss_1A823C->_32 = 21;
        break;
    case 21:
        if (task->_10 == 1) {
            lbl_2_bss_1A823C->_32 = 22;
        }
        break;
    case 22:
        sub = fn_800B0A5C_insertQueue(fn_2_1B1BC, 2);
        sub->_28 = 0;
        task->_10 = 0;
        lbl_2_bss_1A823C->_32 = 23;
        break;
    case 23:
        if (task->_10 == 1) {
            task->_10 = 0;
            ((MenuTask0730*)lbl_803CC1B8)->_00 = fn_2_20D08;
            lbl_2_bss_1A823C->_32 = 0;
        }
        break;
    }
    settings->FrameCountWhileNotAtMainMenu++;
    lbl_2_bss_1A824C->_1976C0++;
}

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
