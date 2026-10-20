#ifndef __STATIC_STATIC_80062578_H_
#define __STATIC_STATIC_80062578_H_

#include "mssbTypes.h"
#include "musyx/musyx.h"

// Per-port pad locks: rows[i].port[p] is the state of lock i for port p
typedef struct PadLock {
    /* 0x00 */ struct {
        u8 _0;
        u8 port[5];
    } rows[14];
    /* 0x54 */ u8 _54;
    /* 0x55 */ u8 active[8];
    /* 0x5D */ u8 step[7];
} PadLock; // size: 0x64

extern PadLock lbl_803C66B0;

BOOL fn_80062578(void);
void fn_800625A4(s32 port, s32 step);
void fn_80062674(s32 port);
void fn_800626EC(s32 port);
void fn_80062744(void);
void fn_80062764(void* arg);
BOOL fn_80062794(SND_VOICEID voice);
s32 fn_800627C4(void);
s32 fn_800627F8(void);
void fn_8006282C(void);
s32 fn_8006285C(void);
s32 fn_80062890(s32 id);
s32 fn_800628D4(s32 charID);
void fn_80062948(void);
void fn_8006295C(void);
void initializeUnknown(void);
void fn_80062A74(void);
void fn_80062A94(void);

#endif // !__STATIC_STATIC_80062578_H_
