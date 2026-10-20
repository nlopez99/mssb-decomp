#ifndef __STATIC_FN_80021AC8_H_
#define __STATIC_FN_80021AC8_H_

#include "mssbTypes.h"

typedef void (*AramCallback)(void* file, void* dst, void* user);

// An ARAM file table entry
typedef struct SoundFile {
    /* 0x00 */ u32 _00;
    /* 0x04 */ u32 size;
    /* 0x08 */ u32 aram;
    /* 0x0C */ u32 _0C;
} SoundFile;

void fn_80021AC8(void);
void* fn_80021ADC(s32 index, void* dst);
void* fn_80021BBC(s32 index, void* dst);
void* fn_80021CA4(s32 player, s32 part, void* dst);
void* fn_8002204C(s32 player, void* dst);
void fn_8002244C(void* file, u8* data, s32 id);
void fn_8002254C(void* file, u8* data, s32 index);
void fn_80022620(void);
void fn_80022634(void);
void fn_800227A0(void);
void fn_800227E4(void);
void fn_800229CC(void);
BOOL fn_80022A24(s32 stadium, s32 part);
void fn_80022B14(void);
BOOL fn_80022B68(void);
BOOL fn_80022CB4(void* file, void* dst, s32 arg2, s32 arg3, void (*callback)(void* file, void* dst, void* user), void* user);
void fn_80022D58(void);

// Defined in units not yet split
void* ARAMTransfer(void* file, void* dst, s32 arg2, s32 arg3);
void fn_800A7568(void);
void fn_800A6304(void);
void* fn_800A6354(u32 size);
s32 fn_800A6418(u32 size);

#endif // !__STATIC_FN_80021AC8_H_
