#include "static/static_80008E00.h"
#include "static/static_8000F150.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"
#include "static/spani_default.h"
#include "static/particle.h"
#include "static/static_8003A2EC.h"
#include "static/mb_subfunc.h"
#include "static/uitexture.h"
#include "static/sub.h"
#include "Dolphin/gx.h"
#include "Dolphin/vi.h"
#include "Dolphin/dvd.h"
#include "Dolphin/ai.h"
#include "Dolphin/pad.h"
#include "Dolphin/rand.h"

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
    /* 0x716 */ u8 _716[0x718 - 0x716];
    /* 0x718 */ s32 _718;
    /* 0x71C */ u8 _71C[0x722 - 0x71C];
    /* 0x722 */ s8 _722;
} lbl_803C6CF8;

extern s32 lbl_803CBBA0;
extern u8 lbl_803CBBA4;
extern s32 lbl_803CBBAC;
extern u32 lbl_803CBBB0;
extern u8 lbl_803CBBB4;
extern void (*lbl_803CBBB8)(s32);
extern struct MainSave* lbl_803CBBBC;
extern u8 lbl_803CBBC1;
extern u8 lbl_803CBBC2;

extern void* fn_800B0A5C_insertQueue(void (*func)(void), u16 priority);
extern void fn_8001D2D4(void);

typedef struct FileIdPair {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
} FileIdPair;

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

typedef struct MainSave {
    /* 0x000 */ u8 _000[0x1B9];
    /* 0x1B9 */ u8 _1B9;
} MainSave;

typedef struct DrawList {
    /* 0x00 */ u8 _00[0x40];
} DrawList;

extern DrawList lbl_801181A0[2];
extern u8 lbl_803CBBC0;
extern s32 lbl_803CBBA8;
extern GXColor lbl_803CD300;

extern void initRenderMode(s32 arg0, s32 arg1, s32 arg2);
extern void fn_800BEC30(s32 arg0);
extern void fn_800A7AD8(void);
extern void fn_800A76BC(void);
extern void fn_800A6870(s32 arg0, s32 arg1);
extern void StartThreadForReadingFromDisk(void);
extern void f_initSound(void);
extern void fn_800A983C(void);
extern void resetAllDrawingStructs_tonop(void);
extern void fn_800A7D7C(DrawList* list, s32 count);
extern void fn_80021AA0(void);
extern void DrawShadows(s32 arg0);
extern void fn_8004B270(void);
extern void fn_80052188(void);
extern void fn_8001F16C(void);
extern void fn_8001AF98(void);
extern void fn_800A7BAC(s32 arg0);
extern s32 OSWaitSemaphore(OSSemaphore* sema);
extern OSThread* GXSetCurrentGXThread(void);
extern void fn_8001E784(void);
extern void fn_800A9520(void);
extern s32 fn_80021188(BOOL (*func)(void));
extern s32 fn_800211BC(BOOL (*func)(void));
extern u32 fn_800AD490(MainSave* save);
extern void fn_800AD914(MainSave* save);
extern void fn_800AD95C(MainSave* save, u8 arg1);
extern void RunDrawScripts_with_stack_variables(void);
extern void fn_800B251C(void);
extern u8 GetDrawShadows(void);
extern void fn_800A7DB0(void);
extern void soundQuit(void);
extern void fn_800A94C4(void);

static inline void updateSave(BOOL active) {
    u32 state;

    if (lbl_803CBBBC != NULL) {
        state = fn_800AD490(lbl_803CBBBC);
        if (active && (state == 1 || (state & 0x80000000))) {
            fn_800AD914(lbl_803CBBBC);
        } else if (!active && fn_800AD490(lbl_803CBBBC) == 2) {
            fn_800AD95C(lbl_803CBBBC, lbl_803CBBBC->_1B9);
        }
    }
}

static inline BOOL checkReset(u8 ready) {
    u16 buttons = lbl_803C77B8[0]._00;

    if (lbl_803CBBAC != 0) {
        if ((buttons & 0x1600) != 0x1600) {
            if ((lbl_80366158._20 == 0 || lbl_80366158._23 == 0) && lbl_803CBBB4 >= 5) {
                lbl_80366158._23 = 1;
            }
            lbl_803CBBB0 = 0;
            lbl_803CBBB4++;
        } else if (lbl_80366158._20 != 0 && lbl_80366158._23 != 0) {
            lbl_803CBBB4 = 0;
            lbl_803CBBB0++;
        }
        if (lbl_803CBBB0 >= 30) {
            lbl_803CBBC1 = 1;
        }
    }
    if (lbl_80366158._21 != 0) {
        return TRUE;
    }
    if ((lbl_803CBBC2 != 0 || lbl_803CBBC1 != 0) && OSGetResetButtonState() == 0 &&
        (ready == 0 || lbl_803C6CF8._722 != -1) && lbl_80366158._20 != 0) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x80009180 size:0x55C
void main(void) {
    OSSemaphore* sema;
    u32 prev = 0;
    u8 cur;
    s32 failed;
    u16 token;
    BOOL reset;
    BOOL menu;
    GXColor clear;

    initRenderMode(0, 0x40000, 0x10);
    fn_800BEC30(1);
    somethingSetTexturePointer();
    fn_800A7AD8();
    fn_800A76BC();
    fn_800A6870(1, 0x438);
    StartThreadForReadingFromDisk();
    f_initSound();
    fn_800A983C();
    resetAllDrawingStructs_tonop();
    fn_800A7D7C(&lbl_801181A0[lbl_803CBBC0], 0x10);
    fn_80021AA0();
    DrawShadows(0);
    fn_80036A3C();
    fn_800356B8();
    lbl_803CBBC2 = 0;
    lbl_803CBBC1 = 0;
    VISetPostRetraceCallback(PostRetraceCallback);
    lbl_80366158._20 = 0;
    lbl_80366158._23 = 0;
    lbl_80366158._21 = 0;
    lbl_80366158.resetCode = OSGetResetCode();
    minigamesSetSomePointers2();
    fn_8003A2EC();
    fn_8004B270();
    lbl_80366158._28 = 0;
    fn_80052188();
    fn_80064534();
    sema = &lbl_803C7420.sema;
    do {
        if (prev == 0) {
            fn_8001F16C();
            fn_8001AF98();
        }
        fn_800A7BAC(1);
        OSWaitSemaphore(sema);
        GXSetCurrentGXThread();
        if (prev == 0) {
            fn_8001E784();
        }
        fn_800A7BAC(0);
        lbl_803CBBC0 ^= 1;
        fn_800A9520();
        fn_800A7D7C(&lbl_801181A0[lbl_803CBBC0], 0x10);
        cur = fn_80009028();
        if (prev != cur) {
            if (cur == 0) {
                failed = fn_80021188(fn_80008E08);
                lbl_803CBBA8 = 0;
            } else {
                failed = fn_800211BC(fn_80008E08);
                lbl_803CBBA8 = 1;
            }
            if (failed != 0) {
                break;
            }
        }
        prev = cur;
        updateSave(cur);
        if (cur != 0) {
            fn_8000F3E8(lbl_803CBBA0);
        } else {
            RunDrawScripts_with_stack_variables();
            fn_800B251C();
        }
        OSWaitSemaphore(sema);
        GXSetCurrentGXThread();
        fn_8003A090();
        while (lbl_803C7420._396 != 0) {
        }
        GXSetCurrentGXThread();
        GXFlush();
        if (GetDrawShadows()) {
            clear = lbl_803CD300;
            GXSetCopyClear(clear, 0xFFFFFF);
        }
        fn_800A7DB0();
        if (lbl_803CBBB8 != NULL) {
            VISetBlack(TRUE);
            VIFlush();
            VIWaitForRetrace();
            lbl_803CBBB8(fn_80023D3C());
            VISetBlack(FALSE);
            VIFlush();
            VIWaitForRetrace();
        }
        lbl_803CBBB8 = NULL;
    } while (!checkReset(cur));
    DVDDumpWaitingQueue();
    GXSetCurrentGXThread();
    token = rand();
    GXSetDrawSync(token);
    GXFlush();
    while (token != GXReadDrawSync()) {
    }
    AIRegisterStreamCallback(NULL);
    AIResetStreamSampleCount();
    AISetStreamPlayState(0);
    soundQuit();
    VISetBlack(TRUE);
    VIFlush();
    VIWaitForRetrace();
    fn_800A94C4();
    if (lbl_80366158._21 != 0) {
        PADStopMotorHard(0);
        PADStopMotorHard(1);
        PADStopMotorHard(2);
        PADStopMotorHard(3);
        OSResetSystem(TRUE, 0, TRUE);
        return;
    }
    reset = FALSE;
    if (DVDCheckDisk() && lbl_803CBBA8 == 0) {
        reset = TRUE;
    }
    menu = reset == FALSE;
    PADStopMotorHard(0);
    PADStopMotorHard(1);
    PADStopMotorHard(2);
    PADStopMotorHard(3);
    OSResetSystem(menu, (fn_80023D3C() ? 2 : 0) | 1, FALSE);
}

// .text:0x80009144 size:0x3C
void fn_80009144(void) {
    fn_800B0A5C_insertQueue(fn_800090B4, 0x6000);
    fn_800B0A5C_insertQueue(fn_80009094, 0x7000);
}

// .text:0x800090B4 size:0x90
void fn_800090B4(void) {
    if (fn_80009028() != 1) {
        fn_8001D2D4();
    }
}

// .text:0x80009094 size:0x20
void fn_80009094(void) {
    fn_80035168();
}

// .text:0x80009028 size:0x6C
u8 fn_80009028(void) {
    switch (lbl_803C6CF8._722) {
    case 0:
        lbl_803CBBA4 = 0;
        break;
    case -1:
    case 4:
    case 5:
    case 6:
    case 11:
        lbl_803CBBA0 = lbl_803C6CF8._722;
        lbl_803CBBA4 = 1;
        break;
    }
    return lbl_803CBBA4;
}

// .text:0x80009018 size:0x10
struct MainSave* fn_80009018(struct MainSave* save) {
    struct MainSave* old = lbl_803CBBBC;
    lbl_803CBBBC = save;
    return old;
}

// .text:0x8000900C size:0xC
void fn_8000900C(void) {
    lbl_803CBBAC = 1;
}

// .text:0x80008FD0 size:0x3C
void PostRetraceCallback(u32 retraceCount) {
    if (OSGetResetButtonState() != 0 && lbl_803CBBAC != 0) {
        lbl_803CBBC2 = 1;
    }
}

// .text:0x80008E08 size:0x1C8
BOOL fn_80008E08(void) {
    return checkReset(fn_80009028());
}

// .text:0x80008E00 size:0x8
void fn_80008E00(void (*func)(s32)) {
    lbl_803CBBB8 = func;
}
