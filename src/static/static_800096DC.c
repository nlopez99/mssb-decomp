#include "static/static_800096DC.h"
#include "static/static_80008E00.h"
#include "static/UnknownHomes_Static.h"
#include "static/sub.h"
#include "Dolphin/os.h"
#include "Dolphin/vi.h"
#include "Dolphin/OS/OSModule.h"
#include "Dolphin/OS/OSCache.h"
#include "musyx/musyx.h"

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
    /* 0x716 */ u8 _716[0x718 - 0x716];
    /* 0x718 */ s32 _718;
    /* 0x71C */ u8 _71C[0x722 - 0x71C];
    /* 0x722 */ s8 _722;
} lbl_803C6CF8;

typedef struct FileIdPair {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
} FileIdPair;

typedef struct FileEntry {
    /* 0x00 */ char* path;
    /* 0x04 */ s32 _04[3];
} FileEntry;

typedef struct MainTask {
    /* 0x00 */ void (*func)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ OSModuleHeader* module;
    /* 0x18 */ u16 _18;
    /* 0x1A */ u8 _1A[0x1C - 0x1A];
    /* 0x1C */ u32 size;
} MainTask;

typedef struct AramEntry {
    /* 0x00 */ u32 _00;
    /* 0x04 */ u32 _04;
    /* 0x08 */ u32 _08;
    /* 0x0C */ u32 _0C;
} AramEntry;

extern struct {
    /* 0x00 */ FileIdPair files;
    /* 0x08 */ u32 _08;
    /* 0x0C */ u32 resetCode;
    /* 0x10 */ u8 _10[0x1C - 0x10];
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
    /* 0x1E */ u8 _1E[0x20 - 0x1E];
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
    /* 0x22 */ u8 _22;
    /* 0x23 */ u8 _23;
    /* 0x24 */ u8 _24;
    /* 0x25 */ u8 _25;
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
} lbl_80366158;

extern struct {
    /* 0x000 */ u8 _000[0x50];
    /* 0x050 */ FileIdPair files;
    /* 0x058 */ u8 _058[0x388 - 0x58];
    /* 0x388 */ OSSemaphore sema;
    /* 0x394 */ u8 _394[0x396 - 0x394];
    /* 0x396 */ volatile u8 _396;
} lbl_803C7420;

extern struct {
    /* 0x00 */ u8 _00[0x5];
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06[0x10 - 0x6];
} lbl_80110080;

extern MainTask* lbl_803CC1B8;
extern s32 lbl_803CBBD0;
extern s32 lbl_803CBBD4;
extern char lbl_800E6568[];
extern char lbl_800E6578[];

extern s32 ConvertPathToEntryNum(FileEntry* entry);

extern struct {
    /* 0x000 */ u8 _000[0x780];
    /* 0x780 */ void* _780;
    /* 0x784 */ u8 _784[0x794 - 0x784];
    /* 0x794 */ void* _794;
    /* 0x798 */ void* _798;
} lbl_80366B18;

extern struct {
    /* 0x00 */ u32 _00;
    /* 0x04 */ u32 _04;
    /* 0x08 */ u32 _08;
} lbl_803C7898;

extern char lbl_800E6550[];
extern char lbl_800E655C[];
extern char lbl_800E6588[];
extern char lbl_800E65A0[];

extern void fn_800AD054(u32 arg0, u32 arg1, GameInitVariables* settings);
extern void fn_80021308(void);
extern void* ARAMTransfer(AramEntry* entry, s32 arg1, s32 arg2, u32 aram);
extern void fn_80011000(void);
extern void fn_800111B4(void* arg);
extern void fn_80010FA0(void);
extern void fn_800B0C80(void (*func)(void));
extern void fn_80021064(void);
extern void fn_800216F8(u8 group, void (*callback)(void));
extern void fn_8002158C(void);
extern void fn_800AD01C(u32 arg0);
extern void fn_80022D58(void);
extern void fn_800227E4(void);
extern void fn_800AD038(u32 arg0, GameInitVariables* settings);
extern void* _OSAllocFromHeap(s32 heap, u32 size);
extern void fn_80021410(void);
extern void resetAllDrawingStructs(void);
extern BOOL fn_800A8518(s32 arg0);
extern void fn_800A88C0(void);
extern void fn_800A8B78(void);
// spani_default.h declares it returning u8; this caller tests the whole register.
extern s32 fn_80035838(void* entry, u8 id);

static AramEntry lbl_800E8AA8[3] = {
    { 0x0000040B, 0x401027E4, 0x00000800, 0x0005A818 },
    { 0x0000040B, 0x402220F8, 0x0005B800, 0x000F4450 },
    { 0x0000040B, 0x4005912C, 0x00150000, 0x000271C0 },
};

static AramEntry lbl_800E8AD8[3] = {
    { 0x0000050E, 0x4003E1A0, 0x08E77000, 0x000143EC },
    { 0x00000000, 0x0000B5D6, 0x08E8B800, 0x0000B5D8 },
    { 0x00000000, 0x00000FE0, 0x08E97000, 0x00000FE0 },
};

static AramEntry lbl_800E8B08[62] = {
    { 0x0000040B, 0x4013764C, 0x1A635000, 0x0007DB48 },
    { 0x0000040B, 0x4003E3DC, 0x1A6B3000, 0x00021420 },
    { 0x0000040B, 0x4002EC10, 0x1A6D4800, 0x00013108 },
    { 0x0000040B, 0x400E72C0, 0x1A6E8000, 0x00060768 },
    { 0x0000040B, 0x40049404, 0x1A748800, 0x00020E34 },
    { 0x0000040B, 0x40076AE0, 0x18ED7000, 0x00036BC8 },
    { 0x0000040B, 0x4010FD70, 0x1A769800, 0x0005E284 },
    { 0x0000040B, 0x400DB738, 0x1A7C8000, 0x00049AB4 },
    { 0x0000040B, 0x400E9864, 0x1A812000, 0x00059DC0 },
    { 0x0000040B, 0x400B7718, 0x1A86C000, 0x00050288 },
    { 0x0000040B, 0x400D87FC, 0x1A8BC800, 0x00047BC4 },
    { 0x0000040B, 0x400D643C, 0x1A904800, 0x0004E3AC },
    { 0x0000040B, 0x400D5C7C, 0x1A953000, 0x00048D9C },
    { 0x0000040B, 0x400B767C, 0x1A99C000, 0x00047518 },
    { 0x0000040B, 0x400441F8, 0x1A9E3800, 0x0001AA84 },
    { 0x0000040B, 0x40106568, 0x1A9FE800, 0x00068C10 },
    { 0x0000040B, 0x4010E5A0, 0x0E97A800, 0x0009BCAC },
    { 0x0000040B, 0x40016980, 0x0EA16800, 0x0000D6C4 },
    { 0x0000040B, 0x40016980, 0x0EA24000, 0x0000C944 },
    { 0x0000040B, 0x40016980, 0x0EA31000, 0x0000E700 },
    { 0x0000040B, 0x40016980, 0x0EA3F800, 0x0000D64C },
    { 0x0000040B, 0x40016980, 0x0EA4D000, 0x0000C900 },
    { 0x0000040B, 0x40016980, 0x0EA5A000, 0x0000CFFC },
    { 0x0000040B, 0x40016980, 0x0EA67000, 0x0000D720 },
    { 0x0000040B, 0x40016980, 0x0EA74800, 0x0000D6CC },
    { 0x0000040B, 0x40016980, 0x0EA82000, 0x0000D21C },
    { 0x0000040B, 0x40016980, 0x0EA8F800, 0x0000D0BC },
    { 0x0000040B, 0x40016980, 0x0EA9D000, 0x0000B544 },
    { 0x0000040B, 0x40016980, 0x0EAA8800, 0x0000C4F8 },
    { 0x0000040B, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 },
    { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 },
    { 0x0000040B, 0x4000A820, 0x18ED3800, 0x00003758 },
    { 0x0000040B, 0x4011EC24, 0x18F0E000, 0x000D8818 },
    { 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8 },
    { 0x0000040B, 0x4006C850, 0x06C96000, 0x0002C884 },
    { 0x0000040B, 0x4005B178, 0x06CC3000, 0x0003555C },
    { 0x0000040B, 0x401EB174, 0x18D43800, 0x000FB220 },
    { 0x0000040B, 0x4001ED60, 0x1AA67800, 0x0000CFF0 },
    { 0x0000040B, 0x4000BF30, 0x1AA74800, 0x000026E0 },
    { 0x0000040B, 0x40003498, 0x1AA77000, 0x00000E28 },
    { 0x0000040B, 0x4000BDE0, 0x1AA78000, 0x000024F4 },
    { 0x0000040B, 0x40006088, 0x1AA7A800, 0x00001290 },
    { 0x0000040B, 0x400049F0, 0x1AA7C000, 0x000018F4 },
    { 0x0000040B, 0x40005ECC, 0x1AA7E000, 0x00001D38 },
    { 0x0000040B, 0x40002670, 0x1AA80000, 0x00000BE8 },
    { 0x00000000, 0x00028240, 0x1AA81000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AAA9800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AAD2000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AAFA800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB23000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB4B800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB74000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AB9C800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ABC5000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ABED800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC16000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC3E800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC67000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AC8F800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ACB8000, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1ACE0800, 0x00028240 },
    { 0x00000000, 0x00028240, 0x1AD09000, 0x00028240 },
};

FileEntry lbl_800E8EE8 = { lbl_800E6550 };
FileEntry lbl_800E8EF8 = { lbl_800E655C };

// .text:0x800097A0 size:0x6F4
void fn_800097A0(void) {
    BOOL result;
    MainTask* task;
    OSModuleHeader* module;
    AramEntry* entry;

    lbl_80366158._26 = 0;
    task = lbl_803CC1B8;
    lbl_80366158._25 = 0;
    switch (task->_18) {
    case 0:
        g_d_GameSettings._06 = 0;
        fn_800AD054(lbl_80366158.files._00, lbl_80366158.files._04, &g_d_GameSettings);
        fn_80021308();
        lbl_803C6CF8._718 = lbl_803CBBD0;
        lbl_80366B18._780 = ARAMTransfer(&lbl_800E8AD8[0], 0, 0, 0);
        task->_18 = 1;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            lbl_80366B18._794 = ARAMTransfer(&lbl_800E8AD8[2], 0, 1, 0);
            task->_18 = 2;
        }
        break;
    case 2:
        if (lbl_803C6CF8._715 == 1) {
            fn_80011000();
            lbl_80366B18._798 = ARAMTransfer(&lbl_800E8AD8[1], 0, 1, 0);
            task->_18 = 3;
        }
        break;
    case 3:
        if (lbl_803C6CF8._715 == 1) {
            fn_800111B4(lbl_80366B18._798);
            fn_80010FA0();
            task->_18 = 4;
        }
        break;
    case 4:
        if (lbl_803C6CF8._715 == 1) {
            task->_18 = 5;
        }
        break;
    case 5:
        result = fn_80035838(&lbl_800E8B08[37], 0);
        if (result) {
            fn_800B0C80(fn_80021064);
            task->_18 = 6;
        }
        break;
    case 6:
        result = fn_80035838(&lbl_800E8B08[15], 1);
        if (result) {
            fn_800216F8(0, fn_8002158C);
            task->_10 = 0;
            task->_18 = 7;
        }
        break;
    case 7:
        if (task->_10 == 0) {
            break;
        }
        lbl_80366158.files._00 = lbl_803C7898._04;
        if ((lbl_80366158.resetCode & 1) && (lbl_80366158.resetCode & 0x80000000)) {
            fn_80023CF4((lbl_80366158.resetCode >> 1) & 1);
            result = FALSE;
        } else if (VIGetDTVStatus() == 0) {
            fn_80023D44(0);
            result = FALSE;
        } else {
            result = FALSE;
            if (OSGetProgressiveMode() == 1 ||
                ((lbl_803C77B8[0]._00 | lbl_803C77B8[1]._00 | lbl_803C77B8[2]._00 | lbl_803C77B8[3]._00) & 0x200)) {
                result = TRUE;
            }
        }
        if (result) {
            lbl_80366158._1D = 0;
        } else {
            lbl_80366158._1D = 9;
        }
        if ((lbl_80366158.resetCode & 1) && (lbl_80366158.resetCode & 0x80000000)) {
            lbl_80366158._29 = 1;
        } else {
            lbl_80366158._29 = 0;
        }
        fn_800AD01C(lbl_80366158.files._04);
        fn_80022D58();
        fn_800227E4();
        fn_80009144();
    case 8:
        g_d_GameSettings._06 = 1;
        fn_800AD038(lbl_80366158.files._00, &g_d_GameSettings);
        lbl_803C6CF8._718 = lbl_803CBBD4;
        task->module = ARAMTransfer(&lbl_800E8AA8[0], 0, 0, 0);
        task->size = lbl_800E8AA8[0]._04 & 0x0FFFFFFF;
        OSReport(lbl_800E6588, 0, task->module);
        task->_18 = 9;
        break;
    case 9:
        if (lbl_803C6CF8._715 == 1) {
            module = task->module;
            lbl_803C6CF8._718 = lbl_803CBBD0;
            OSLink(&module->info, _OSAllocFromHeap(0x20, module->bssSize));
            ICInvalidateRange(task->module, task->size);
            lbl_80366158._08 = lbl_803C7898._04;
            ((void (*)(void))module->prolog)();
            task->_10 = 0;
            OSReport(lbl_800E65A0);
            task->_18 = 10;
        }
        break;
    case 10:
        if (task->_10 != 0) {
            fn_80021410();
            resetAllDrawingStructs();
            fn_80009144();
            module = task->module;
            ((void (*)(void))module->epilog)();
            OSUnlink(&module->info);
            switch (task->_10) {
            case 1:
                task->_18 = 11;
                break;
            }
        }
        break;
    case 11:
        g_d_GameSettings._06 = 2;
        fn_800AD038(lbl_80366158.files._00, &g_d_GameSettings);
        lbl_803C6CF8._718 = lbl_803CBBD4;
        entry = &lbl_800E8AA8[1];
        task->module = ARAMTransfer(entry, 0, 0, 0);
        task->size = entry->_04 & 0x0FFFFFFF;
        OSReport(lbl_800E6588, 1, task->module);
        task->_18 = 12;
        lbl_80366158._1C = 0;
        break;
    case 12:
        if (lbl_803C6CF8._715 == 1) {
            module = task->module;
            lbl_803C6CF8._718 = lbl_803CBBD0;
            OSLink(&module->info, _OSAllocFromHeap(0x20, module->bssSize));
            ICInvalidateRange(task->module, task->size);
            lbl_80366158._08 = lbl_803C7898._04;
            ((void (*)(void))module->prolog)();
            task->_10 = 0;
            OSReport(lbl_800E65A0);
            task->_18 = 13;
        }
        break;
    case 13:
        if (lbl_80366158._1C != 0) {
            DrawShadows(0);
            sndSilence();
        }
        task->_18 = 14;
    case 14:
        if (lbl_80366158._1C != 0 && fn_800A8518(3)) {
            fn_800A88C0();
            fn_800A8B78();
            fn_80021410();
            resetAllDrawingStructs();
            fn_80009144();
            module = task->module;
            ((void (*)(void))module->epilog)();
            OSUnlink(&module->info);
            task->_18 = 8;
            g_d_GameSettings.miniGameStadiumIndicator = 0;
            if (g_d_GameSettings.GameModeSelected == GAME_TYPE_DEMO) {
                lbl_80366158._1D = 7;
                lbl_80366158._29 = 2;
            } else if (!g_d_GameSettings.exhibitionMatchInd) {
                if (g_d_GameSettings.GameModeSelected == GAME_TYPE_CHALLENGE && !g_d_GameSettings.bJMatchInd) {
                    lbl_80366158._1D = 1;
                } else {
                    g_d_GameSettings.GameModeSelected = GAME_TYPE_CHALLENGE;
                }
            } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD ||
                       g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES ||
                       g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
                lbl_80366158._1D = 1;
            } else if (lbl_80366158._1C == 1) {
                lbl_80366158._1D = 1;
            } else {
                lbl_80366158._1D = 1;
            }
        }
        break;
    }
}

// .text:0x800096DC size:0xC4
void PrepFilesToBeLoaded(void) {
    MainTask* task;

    lbl_80366158.files._00 = lbl_803C7420.files._00;
    task = lbl_803CC1B8;
    lbl_80366158.files._04 = lbl_803C7420.files._04;
    lbl_803CBBD4 = ConvertPathToEntryNum(&lbl_800E8EE8);
    lbl_803CBBD0 = ConvertPathToEntryNum(&lbl_800E8EF8);
    task->_18 = 0;
    lbl_803CC1B8->func = fn_800097A0;
    OSReport(lbl_800E6568, lbl_803CBBD4);
    OSReport(lbl_800E6578, lbl_803CBBD0);
    lbl_80110080._05 = 4;
    lbl_80366158._1D = 1;
}
