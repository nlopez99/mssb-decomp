#include "game/rep_60.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"
#include "game/rep_1D58.h"

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
} UnkLoadParent60;

typedef struct {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ UnkLoadParent60* _0C;
    /* 0x10 */ s16 state;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ void* data;
} UnkLoadTask60;

typedef struct {
    /* 0x00 */ u32 _00[4];
} UnkAramEntry60; // size: 0x10

extern UnkLoadTask60* lbl_803CC1B8;
extern UnkAramEntry60 lbl_800EFBE8[21];

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ void* _004;
} lbl_8036E548;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x000 */ u8 _000[0x1CC];
    /* 0x1CC */ u32 _1CC;
} lbl_803716B8;

extern struct {
    /* 0x00 */ u8 _00[0x6A];
    /* 0x6A */ u8 _6A;
} lbl_3_common_bss_350E4;

extern struct {
    /* 0x000 */ u8 _000[0x3B0];
    /* 0x3B0 */ u8 _3B0;
} lbl_3_common_bss_35154;

extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u8 _10;
} lbl_3_data_228;

extern void* ARAMTransfer(UnkAramEntry60* entry, int arg1, int arg2, u32 aram);
extern void fn_8001CBD4(void);
extern void fn_800229CC(void);
extern void fn_800B0A14_removeQueue(void);
extern void fn_3_5EC0(void* data);
extern void fn_3_106DFC(void);
extern BOOL fn_3_106E50(void);
// rep_1E08.h declares these as void(void), matching their stub definitions
extern void fn_3_BD7D8(void);
extern BOOL fn_3_BF878(void);

// .text:0x0000065C size:0x278 mapped:0x8063F6F0
void manageLoadingState(void) {
    UnkLoadTask60* task = lbl_803CC1B8;

    switch (task->state) {
    case 0:
        if (lbl_803716B8._1CC != 0) {
            if (lbl_803C6CF8._715 != 1) {
                break;
            }
            lbl_8036E548._004 = task->data = ARAMTransfer(
                &lbl_800EFBE8[g_d_GameSettings.StadiumID * 3 + g_d_GameSettings.miniGameStadiumIndicator], 0, 3,
                lbl_803716B8._1CC);
            OSReport("Sta %d-%d aram:%x -> mem:%x\n", g_d_GameSettings.StadiumID,
                     g_d_GameSettings.miniGameStadiumIndicator, lbl_803716B8._1CC, task->data);
        } else {
            lbl_8036E548._004 = task->data = ARAMTransfer(
                &lbl_800EFBE8[g_d_GameSettings.StadiumID * 3 + g_d_GameSettings.miniGameStadiumIndicator], 0, 0, 0);
        }
        task->state = 1;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_5EC0(task->data);
            task->state = 2;
            fn_800229CC();
        }
        break;
    case 2:
        switch (fn_3_B9BB4(g_d_GameSettings.StadiumID)) {
        case 0:
            break;
        case 1:
            task->state = 3;
            break;
        case -1:
            task->state = 4;
            break;
        }
        break;
    case 3:
        if (lbl_3_common_bss_350E4._6A == 0) {
            task->state = 4;
        }
        break;
    case 4:
        if (fn_3_BF878()) {
            task->state = 5;
        }
        break;
    case 5:
        if (lbl_3_common_bss_35154._3B0 == 0) {
            task->state = 6;
        }
        break;
    case 6:
        fn_3_BD7D8();
        task->state = 7;
        break;
    case 7:
        if (fn_3_106E50()) {
            task->state = 8;
        }
        break;
    case 8:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_106DFC();
            task->state = 9;
        }
        break;
    default:
        task->_0C->_10 = 1;
        lbl_3_data_228._10 = 1;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x000004F4 size:0x168 mapped:0x8063F588
void manageStadiumLoading(void) {
    UnkLoadTask60* task = lbl_803CC1B8;

    switch (task->state) {
    case 0:
        fn_8001CBD4();
        lbl_8036E548._004 = ARAMTransfer(
            &lbl_800EFBE8[g_d_GameSettings.StadiumID * 3 + g_d_GameSettings.miniGameStadiumIndicator], 0, 0, 0);
        task->state++;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            fn_3_5EC0(lbl_8036E548._004);
            task->state++;
        }
        break;
    case 2:
        switch (fn_3_B9BB4(g_d_GameSettings.StadiumID)) {
        case 0:
            break;
        case 1:
            task->state = 3;
            break;
        case -1:
            task->state = 4;
            break;
        }
        break;
    case 3:
        if (lbl_3_common_bss_350E4._6A == 0) {
            task->state++;
        }
        break;
    default:
        task->_0C->_10 = 1;
        lbl_3_data_228._10 = 1;
        fn_800B0A14_removeQueue();
        break;
    }
}
