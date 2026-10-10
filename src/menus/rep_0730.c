#include "header_rep_data.h"
#include "menus/rep_0730.h"
#include "menus/rep_0B08.h"
#include "menus/rep_0F60.h"
#include "menus/rep_0788.h"
#include "menus/rep_08E8.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/vec.h"
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

typedef struct Entry0730 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s16 _04;
    /* 0x06 */ s16 _06;
    /* 0x08 */ s16 _08;
    /* 0x0A */ s16 _0A;
    /* 0x0C */ s16 _0C;
    /* 0x0E */ s16 _0E;
    /* 0x10 */ s16 _10;
    /* 0x12 */ s16 _12;
    /* 0x14 */ s16 _14;
    /* 0x16 */ u8 _16[0x18 - 0x16];
} Entry0730; // size: 0x18

extern void* lbl_803CC1B8;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x000000 */ u8 _000000[0x195424];
    /* 0x195424 */ s32 _195424;
    /* 0x195428 */ s32 _195428;
    /* 0x19542C */ u8 _19542C[0x1972BC - 0x19542C];
    /* 0x1972BC */ u8 _1972BC[1];
    /* 0x1972BD */ u8 _1972BD;
    /* 0x1972BE */ u8 _1972BE[4];
    /* 0x1972C2 */ u8 _1972C2[0x197608 - 0x1972C2];
    /* 0x197608 */ Vec _197608[6];
    /* 0x197650 */ u8 _197650[0x197668 - 0x197650];
    /* 0x197668 */ f32 _197668[7];
    /* 0x197684 */ s32 _197684;
    /* 0x197688 */ s32 _197688;
    /* 0x19768C */ s32 _19768C;
    /* 0x197690 */ s32 _197690;
    /* 0x197694 */ s32 _197694;
    /* 0x197698 */ s32 _197698;
    /* 0x19769C */ s32 _19769C;
    /* 0x1976A0 */ s32 _1976A0;
    /* 0x1976A4 */ s32 _1976A4;
    /* 0x1976A8 */ s32 _1976A8;
    /* 0x1976AC */ u8 _1976AC[0x1976B0 - 0x1976AC];
    /* 0x1976B0 */ s32 _1976B0;
    /* 0x1976B4 */ s32 _1976B4;
    /* 0x1976B8 */ s32 _1976B8;
    /* 0x1976BC */ s32 _1976BC;
    /* 0x1976C0 */ s32 _1976C0;
    /* 0x1976C4 */ s16 _1976C4;
    /* 0x1976C6 */ s16 _1976C6;
    /* 0x1976C8 */ s16 _1976C8;
    /* 0x1976CA */ s16 _1976CA;
    /* 0x1976CC */ s16 _1976CC;
    /* 0x1976CE */ s16 _1976CE;
    /* 0x1976D0 */ s16 _1976D0;
    /* 0x1976D2 */ s16 _1976D2;
    /* 0x1976D4 */ s16 _1976D4;
    /* 0x1976D6 */ s16 _1976D6;
    /* 0x1976D8 */ s16 _1976D8;
    /* 0x1976DA */ s16 _1976DA;
    /* 0x1976DC */ s16 _1976DC;
    /* 0x1976DE */ u8 _1976DE[0x1976E0 - 0x1976DE];
    /* 0x1976E0 */ s16 _1976E0;
    /* 0x1976E2 */ s16 _1976E2;
    /* 0x1976E4 */ s16 _1976E4;
    /* 0x1976E6 */ s16 _1976E6;
    /* 0x1976E8 */ s16 _1976E8;
    /* 0x1976EA */ s16 _1976EA;
    /* 0x1976EC */ s16 _1976EC;
    /* 0x1976EE */ s16 _1976EE;
    /* 0x1976F0 */ s16 _1976F0;
    /* 0x1976F2 */ s16 _1976F2;
    /* 0x1976F4 */ s16 _1976F4;
    /* 0x1976F6 */ s16 _1976F6;
    /* 0x1976F8 */ s16 _1976F8;
    /* 0x1976FA */ s16 _1976FA;
    /* 0x1976FC */ s16 _1976FC;
    /* 0x1976FE */ s16 _1976FE;
    /* 0x197700 */ s16 _197700;
    /* 0x197702 */ s16 _197702;
    /* 0x197704 */ s16 _197704;
    /* 0x197706 */ s16 _197706;
    /* 0x197708 */ s16 _197708;
    /* 0x19770A */ s16 _19770A;
    /* 0x19770C */ u8 _19770C[0x19772E - 0x19770C];
    /* 0x19772E */ s16 _19772E;
    /* 0x197730 */ s16 _197730;
    /* 0x197732 */ s16 _197732;
    /* 0x197734 */ s16 _197734;
    /* 0x197736 */ s16 _197736;
    /* 0x197738 */ u8 _197738[0x19773C - 0x197738];
    /* 0x19773C */ s16 _19773C;
    /* 0x19773E */ s16 _19773E;
    /* 0x197740 */ u8 _197740[0x197746 - 0x197740];
    /* 0x197746 */ s16 _197746;
    /* 0x197748 */ s16 _197748;
    /* 0x19774A */ s16 _19774A;
    /* 0x19774C */ s16 _19774C;
    /* 0x19774E */ s16 _19774E;
    /* 0x197750 */ s16 _197750;
    /* 0x197752 */ s16 _197752;
    /* 0x197754 */ s16 _197754;
    /* 0x197756 */ s16 _197756[8];
    /* 0x197766 */ s16 _197766;
    /* 0x197768 */ s16 _197768;
    /* 0x19776A */ s16 _19776A;
    /* 0x19776C */ s16 _19776C;
    /* 0x19776E */ s16 _19776E;
    /* 0x197770 */ s16 _197770;
    /* 0x197772 */ s16 _197772;
    /* 0x197774 */ s16 _197774;
    /* 0x197776 */ s16 _197776;
    /* 0x197778 */ s16 _197778;
    /* 0x19777A */ s16 _19777A;
    /* 0x19777C */ s16 _19777C;
    /* 0x19777E */ s16 _19777E;
    /* 0x197780 */ s16 _197780;
    /* 0x197782 */ s16 _197782;
    /* 0x197784 */ s16 _197784;
    /* 0x197786 */ s16 _197786;
    /* 0x197788 */ s16 _197788;
    /* 0x19778A */ s16 _19778A;
    /* 0x19778C */ s16 _19778C;
    /* 0x19778E */ s16 _19778E;
    /* 0x197790 */ s16 _197790;
    /* 0x197792 */ s16 _197792;
    /* 0x197794 */ s16 _197794;
    /* 0x197796 */ s16 _197796;
    /* 0x197798 */ s16 _197798;
    /* 0x19779A */ u8 _19779A[0x197822 - 0x19779A];
    /* 0x197822 */ u8 _197822;
    /* 0x197823 */ u8 _197823;
    /* 0x197824 */ u8 _197824;
    /* 0x197825 */ u8 _197825;
    /* 0x197826 */ u8 _197826;
    /* 0x197827 */ u8 _197827;
    /* 0x197828 */ u8 _197828;
    /* 0x197829 */ u8 _197829[0x19782A - 0x197829];
    /* 0x19782A */ u8 _19782A;
    /* 0x19782B */ u8 _19782B;
    /* 0x19782C */ u8 _19782C;
    /* 0x19782D */ u8 _19782D;
    /* 0x19782E */ u8 _19782E;
    /* 0x19782F */ u8 _19782F;
    /* 0x197830 */ u8 _197830;
    /* 0x197831 */ u8 _197831;
    /* 0x197832 */ u8 _197832;
    /* 0x197833 */ u8 _197833;
    /* 0x197834 */ u8 _197834;
    /* 0x197835 */ u8 _197835;
    /* 0x197836 */ u8 _197836;
    /* 0x197837 */ u8 _197837;
    /* 0x197838 */ u8 _197838;
    /* 0x197839 */ u8 _197839;
    /* 0x19783A */ u8 _19783A;
    /* 0x19783B */ u8 _19783B;
    /* 0x19783C */ u8 _19783C;
    /* 0x19783D */ u8 _19783D;
    /* 0x19783E */ u8 _19783E;
    /* 0x19783F */ u8 _19783F;
    /* 0x197840 */ u8 _197840;
    /* 0x197841 */ u8 _197841;
    /* 0x197842 */ u8 _197842;
    /* 0x197843 */ s8 _197843;
    /* 0x197844 */ u8 _197844;
    /* 0x197845 */ u8 _197845;
    /* 0x197846 */ u8 _197846;
    /* 0x197847 */ u8 _197847;
    /* 0x197848 */ u8 _197848;
    /* 0x197849 */ u8 _197849;
    /* 0x19784A */ u8 _19784A;
    /* 0x19784B */ u8 _19784B;
    /* 0x19784C */ u8 _19784C;
    /* 0x19784D */ u8 _19784D;
    /* 0x19784E */ u8 _19784E;
    /* 0x19784F */ u8 _19784F;
    /* 0x197850 */ u8 _197850;
    /* 0x197851 */ u8 _197851;
    /* 0x197852 */ u8 _197852;
    /* 0x197853 */ u8 _197853;
    /* 0x197854 */ u8 _197854;
    /* 0x197855 */ u8 _197855;
    /* 0x197856 */ u8 _197856;
    /* 0x197857 */ u8 _197857;
    /* 0x197858 */ u8 _197858;
    /* 0x197859 */ u8 _197859;
    /* 0x19785A */ u8 _19785A;
    /* 0x19785B */ u8 _19785B;
    /* 0x19785C */ u8 _19785C;
    /* 0x19785D */ u8 _19785D[0x197863 - 0x19785D];
    /* 0x197863 */ s8 _197863;
    /* 0x197864 */ u8 _197864;
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
    /* 0x000000 */ Entry0730 _000000[70][864];
    /* 0x162600 */ u8 _162600[0x162992 - 0x162600];
    /* 0x162992 */ u8 _162992;
} *lbl_2_bss_1A8234;

extern struct {
    /* 0x00000 */ Entry0730 _00000[10][864];
    /* 0x32A00 */ u8 _32A00[0x32A86 - 0x32A00];
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
extern void fn_80068720(s32);
extern void fn_80021410(void);
extern void fn_800ACFB0(void* data);

extern struct {
    /* 0x00 */ u8 _00[0x9C];
    /* 0x9C */ void* _9C;
} lbl_800EF808;

extern struct {
    /* 0x000 */ u8 _000[0x7A8];
    /* 0x7A8 */ void* _7A8;
} lbl_80366B18;

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
extern void fn_2_54474(void);
extern void fn_2_8ACB0(s32, s32);
extern void fn_2_8AEE0(void);
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

// .text:0x0001C0D4 size:0x148
void fn_2_1C0D4(void) {
    struct Unk8034E9A0* data = &lbl_8034E9A0;
    s32 i;

    lbl_2_bss_1A823C->_34 = 1;
    memset(lbl_2_bss_1A8250, 0, sizeof(lbl_2_bss_1A8250));
    for (i = 0; i < 8; i++) {
        lbl_2_bss_1A824C->_197756[i] = -1;
    }
    fn_2_54474();
    lbl_2_bss_1A8248->_44F2 = 0;
    lbl_2_bss_1A824C->_1976D6 = 0;
    lbl_2_bss_1A824C->_197833 = 0;
    lbl_2_bss_1A8234->_162992 = 0;
    lbl_2_bss_1A824C->_197838 = 0;
    lbl_2_bss_1A824C->_197835 = 0;
    g_d_GameSettings.StadiumID = 0;
    lbl_2_bss_1A824C->_197863 = data->_46F8;
    lbl_2_bss_1A824C->_197848 = 0;
}

// .text:0x0001BFD0 size:0x104
void fn_2_1BFD0(void) {
    fn_80068720(10);
    lbl_2_bss_1A824C->_1972BC[0] = 1;
    lbl_2_bss_1A824C->_1972BE[2] = 1;
    lbl_2_bss_1A824C->_1976D6 = 0;
    lbl_2_bss_1A8248->_44F2 = 0;
    if (lbl_2_bss_1A824C->_197864 == 0) {
        fn_2_4E7EC();
    }
    fn_8001F228();
    fn_80021410();
    fn_800ACFB0(lbl_800EF808._9C);
    if (lbl_2_bss_1A8248->_44F4 != 0) {
        fn_2_4E8BC();
        fn_2_4E904();
        fn_2_4E928();
    } else {
        fn_2_4E928();
    }
    fn_2_4E94C();
    if (lbl_80366B18._7A8 != NULL) {
        fn_800ACFB0(lbl_80366B18._7A8);
        lbl_80366B18._7A8 = NULL;
    }
    lbl_2_bss_1A823C->_34 = 0;
}

// .text:0x0001BF50 size:0x80
void fn_2_1BF50(void) {
    fn_80068720(13);
    lbl_2_bss_1A824C->_1972BC[0] = 1;
    lbl_2_bss_1A824C->_1972BE[2] = 1;
    lbl_2_bss_1A824C->_1976D6 = 0;
    lbl_2_bss_1A8248->_44F2 = 0;
    fn_2_4E898();
    lbl_2_bss_1A823C->_34 = 0;
}

// .text:0x0001B7B4 size:0x79C
void fn_2_1B7B4(void) {
    struct Unk8034E9A0* data;
    GameInitVariables* settings;
    MenuTask0730* task;
    MenuTask0730* sub;

    task = lbl_803CC1B8;
    settings = &g_d_GameSettings;
    data = &lbl_8034E9A0;
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
        fn_2_1C0D4();
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
        lbl_2_bss_1A8248->_44F4 = fn_2_1A420();
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

// .text:0x0001A4C8 size:0xCF4
void fn_2_1A4C8(void) {
    s32 j;
    Entry0730* entry;
    s32 i;

    for (i = 0; i < 70; i++) {
        for (j = 0; j < 864; j++) {
            entry = &lbl_2_bss_1A8234->_000000[i][j];
            entry->_04 = 0;
            entry->_06 = 0;
            entry->_10 = 0;
            entry->_08 = 0;
            entry->_0A = 0;
            entry->_0C = 0;
            entry->_0E = 0;
            entry->_12 = 0;
            entry->_14 = 0;
            entry->_00 = 0;
        }
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 864; j++) {
            entry = &lbl_2_bss_1A8230->_00000[i][j];
            entry->_04 = 0;
            entry->_06 = 0;
            entry->_10 = 0;
            entry->_08 = 0;
            entry->_0A = 0;
            entry->_0C = 0;
            entry->_0E = 0;
            entry->_12 = 0;
            entry->_14 = 0;
            entry->_00 = 0;
        }
    }
    lbl_2_bss_1A824C->_195424 = 0;
    lbl_2_bss_1A824C->_195428 = 0;
    memset(lbl_2_bss_1A824C->_19542C, 0, sizeof(lbl_2_bss_1A824C->_19542C));
    memset(lbl_2_bss_1A824C->_1972BC, 0, sizeof(lbl_2_bss_1A824C->_1972BC));
    memset(lbl_2_bss_1A824C->_1972BE, 0, sizeof(lbl_2_bss_1A824C->_1972BE));
    lbl_2_bss_1A824C->_197608[0].x = 0.0f;
    lbl_2_bss_1A824C->_197608[1].x = 0.0f;
    lbl_2_bss_1A824C->_197608[2].x = 0.0f;
    lbl_2_bss_1A824C->_197608[3].x = 0.0f;
    lbl_2_bss_1A824C->_197608[4].x = 0.0f;
    lbl_2_bss_1A824C->_197608[5].x = 0.0f;
    lbl_2_bss_1A824C->_197608[0].y = 0.0f;
    lbl_2_bss_1A824C->_197608[1].y = 0.0f;
    lbl_2_bss_1A824C->_197608[2].y = 0.0f;
    lbl_2_bss_1A824C->_197608[3].y = 0.0f;
    lbl_2_bss_1A824C->_197608[4].y = 0.0f;
    lbl_2_bss_1A824C->_197608[5].y = 0.0f;
    lbl_2_bss_1A824C->_197608[0].z = 0.0f;
    lbl_2_bss_1A824C->_197608[1].z = 0.0f;
    lbl_2_bss_1A824C->_197608[2].z = 0.0f;
    lbl_2_bss_1A824C->_197608[3].z = 0.0f;
    lbl_2_bss_1A824C->_197608[4].z = 0.0f;
    lbl_2_bss_1A824C->_197608[5].z = 0.0f;
    lbl_2_bss_1A824C->_197668[0] = 0.0f;
    lbl_2_bss_1A824C->_197668[1] = 0.0f;
    lbl_2_bss_1A824C->_197668[2] = 0.0f;
    lbl_2_bss_1A824C->_197668[3] = 0.0f;
    lbl_2_bss_1A824C->_197668[4] = 0.0f;
    lbl_2_bss_1A824C->_197668[5] = 0.0f;
    lbl_2_bss_1A824C->_197668[6] = 0.0f;
    lbl_2_bss_1A824C->_197684 = 0;
    lbl_2_bss_1A824C->_197688 = 0;
    lbl_2_bss_1A824C->_19768C = 0;
    lbl_2_bss_1A824C->_197690 = 0;
    lbl_2_bss_1A824C->_197694 = 0;
    lbl_2_bss_1A824C->_197698 = 0;
    lbl_2_bss_1A824C->_19769C = 0;
    lbl_2_bss_1A824C->_1976A0 = 0;
    lbl_2_bss_1A824C->_1976A4 = 0;
    lbl_2_bss_1A824C->_1976A8 = 0;
    lbl_2_bss_1A824C->_1976B0 = 0;
    lbl_2_bss_1A824C->_1976B4 = 0;
    lbl_2_bss_1A824C->_1976B8 = 0;
    lbl_2_bss_1A824C->_1976BC = 0;
    lbl_2_bss_1A824C->_1976C4 = 0;
    lbl_2_bss_1A824C->_1976C6 = 0;
    lbl_2_bss_1A824C->_1976C8 = 0;
    lbl_2_bss_1A824C->_1976CA = 0;
    lbl_2_bss_1A824C->_1976CC = 0;
    lbl_2_bss_1A824C->_1976CE = 0;
    lbl_2_bss_1A824C->_1976D0 = 0;
    lbl_2_bss_1A824C->_1976D2 = 0;
    lbl_2_bss_1A824C->_1976D4 = 0;
    lbl_2_bss_1A824C->_1976D6 = 0;
    lbl_2_bss_1A824C->_1976D8 = 0;
    lbl_2_bss_1A824C->_1976DA = 0;
    lbl_2_bss_1A824C->_1976DC = 0;
    lbl_2_bss_1A824C->_1976E0 = 0;
    lbl_2_bss_1A824C->_1976E2 = 0;
    lbl_2_bss_1A824C->_1976E4 = 0;
    lbl_2_bss_1A824C->_1976E6 = 0;
    lbl_2_bss_1A824C->_1976E8 = 0;
    lbl_2_bss_1A824C->_1976EC = 0;
    lbl_2_bss_1A824C->_1976EA = 0;
    lbl_2_bss_1A824C->_1976F0 = 0;
    lbl_2_bss_1A824C->_1976EE = 0;
    lbl_2_bss_1A824C->_1976F2 = 0;
    lbl_2_bss_1A824C->_1976F4 = 0;
    lbl_2_bss_1A824C->_1976F6 = 0;
    lbl_2_bss_1A824C->_1976F8 = 0;
    lbl_2_bss_1A824C->_1976FA = 0;
    lbl_2_bss_1A824C->_1976FC = 0;
    lbl_2_bss_1A824C->_1976FE = 0;
    lbl_2_bss_1A824C->_197700 = 0;
    lbl_2_bss_1A824C->_197702 = 0;
    lbl_2_bss_1A824C->_197704 = 0;
    lbl_2_bss_1A824C->_197706 = 0;
    lbl_2_bss_1A824C->_197708 = 0;
    lbl_2_bss_1A824C->_19770A = 0;
    lbl_2_bss_1A824C->_19772E = 0;
    lbl_2_bss_1A824C->_197730 = 0;
    lbl_2_bss_1A824C->_197732 = 0;
    lbl_2_bss_1A824C->_197734 = 0;
    lbl_2_bss_1A824C->_197736 = 0;
    lbl_2_bss_1A824C->_19773C = 0;
    lbl_2_bss_1A824C->_19773E = 0;
    lbl_2_bss_1A824C->_197746 = 0;
    lbl_2_bss_1A824C->_197748 = 0;
    lbl_2_bss_1A824C->_19774A = 0;
    lbl_2_bss_1A824C->_19774C = 0;
    lbl_2_bss_1A824C->_19774E = 0;
    lbl_2_bss_1A824C->_197750 = 0;
    lbl_2_bss_1A824C->_197752 = 0;
    lbl_2_bss_1A824C->_197754 = 0;
    lbl_2_bss_1A824C->_197756[0] = 0;
    lbl_2_bss_1A824C->_197756[1] = 0;
    lbl_2_bss_1A824C->_197756[2] = 0;
    lbl_2_bss_1A824C->_197756[3] = 0;
    lbl_2_bss_1A824C->_197756[4] = 0;
    lbl_2_bss_1A824C->_197756[5] = 0;
    lbl_2_bss_1A824C->_197756[6] = 0;
    lbl_2_bss_1A824C->_197756[7] = 0;
    lbl_2_bss_1A824C->_197766 = 0;
    lbl_2_bss_1A824C->_197768 = 0;
    lbl_2_bss_1A824C->_19776A = 0;
    lbl_2_bss_1A824C->_19776C = 0;
    lbl_2_bss_1A824C->_19776E = 0;
    lbl_2_bss_1A824C->_197770 = 0;
    lbl_2_bss_1A824C->_197772 = 0;
    lbl_2_bss_1A824C->_197774 = 0;
    lbl_2_bss_1A824C->_197776 = 0;
    lbl_2_bss_1A824C->_197778 = 0;
    lbl_2_bss_1A824C->_19777A = 0;
    lbl_2_bss_1A824C->_19777C = 0;
    lbl_2_bss_1A824C->_19777E = 0;
    lbl_2_bss_1A824C->_197780 = 0;
    lbl_2_bss_1A824C->_197782 = 0;
    lbl_2_bss_1A824C->_197784 = 0;
    lbl_2_bss_1A824C->_197786 = 0;
    lbl_2_bss_1A824C->_197788 = 0;
    lbl_2_bss_1A824C->_19778A = 0;
    lbl_2_bss_1A824C->_19778C = 0;
    lbl_2_bss_1A824C->_19778E = 0;
    lbl_2_bss_1A824C->_197792 = 0;
    lbl_2_bss_1A824C->_197794 = 0;
    lbl_2_bss_1A824C->_197790 = 0;
    lbl_2_bss_1A824C->_197796 = 0;
    lbl_2_bss_1A824C->_197798 = 0;
    lbl_2_bss_1A824C->_197822 = 0;
    lbl_2_bss_1A824C->_197823 = 0;
    lbl_2_bss_1A824C->_197824 = 0;
    lbl_2_bss_1A824C->_197825 = 0;
    lbl_2_bss_1A824C->_197826 = 0;
    lbl_2_bss_1A824C->_197827 = 0;
    lbl_2_bss_1A824C->_197828 = 0;
    lbl_2_bss_1A824C->_19782A = 0;
    lbl_2_bss_1A824C->_19782B = 0;
    lbl_2_bss_1A824C->_19782C = 0;
    lbl_2_bss_1A824C->_19782D = 0;
    lbl_2_bss_1A824C->_19782E = 0;
    lbl_2_bss_1A824C->_19782F = 0;
    lbl_2_bss_1A824C->_197830 = 0;
    lbl_2_bss_1A824C->_197831 = 0;
    lbl_2_bss_1A824C->_197832 = 0;
    lbl_2_bss_1A824C->_197833 = 0;
    lbl_2_bss_1A824C->_197834 = 0;
    lbl_2_bss_1A824C->_197835 = 0;
    lbl_2_bss_1A824C->_197836 = 0;
    lbl_2_bss_1A824C->_197837 = 0;
    lbl_2_bss_1A824C->_197838 = 0;
    lbl_2_bss_1A824C->_197839 = 0;
    lbl_2_bss_1A824C->_19783A = 0;
    lbl_2_bss_1A824C->_19783B = 0;
    lbl_2_bss_1A824C->_19783C = 0;
    lbl_2_bss_1A824C->_19783D = 0;
    lbl_2_bss_1A824C->_19783E = 0;
    lbl_2_bss_1A824C->_19783F = 0;
    lbl_2_bss_1A824C->_197840 = 0;
    lbl_2_bss_1A824C->_197841 = 0;
    lbl_2_bss_1A824C->_197842 = 0;
    lbl_2_bss_1A824C->_197843 = 0;
    lbl_2_bss_1A824C->_197844 = 0;
    lbl_2_bss_1A824C->_197845 = 0;
    lbl_2_bss_1A824C->_197846 = 0;
    lbl_2_bss_1A824C->_197847 = 0;
    lbl_2_bss_1A824C->_197848 = 0;
    lbl_2_bss_1A824C->_197849 = 0;
    lbl_2_bss_1A824C->_19784A = 0;
    lbl_2_bss_1A824C->_19784B = 0;
    lbl_2_bss_1A824C->_19784C = 0;
    lbl_2_bss_1A824C->_19784D = 0;
    lbl_2_bss_1A824C->_19784E = 0;
    lbl_2_bss_1A824C->_19784F = 0;
    lbl_2_bss_1A824C->_197850 = 0;
    lbl_2_bss_1A824C->_197851 = 0;
    lbl_2_bss_1A824C->_197852 = 0;
    lbl_2_bss_1A824C->_197853 = 0;
    lbl_2_bss_1A824C->_197854 = 0;
    lbl_2_bss_1A824C->_197855 = 0;
    lbl_2_bss_1A824C->_197856 = 0;
    lbl_2_bss_1A824C->_197857 = 0;
    lbl_2_bss_1A824C->_197858 = 0;
    lbl_2_bss_1A824C->_197859 = 0;
    lbl_2_bss_1A824C->_19785A = 0;
    lbl_2_bss_1A824C->_19785B = 0;
    lbl_2_bss_1A824C->_19785C = 0;
}

// .text:0x0001A420 size:0xA8
s32 fn_2_1A420(void) {
    s32 flag = 0;

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
    return !!flag;
}
