#ifndef __STATIC_GRAPHIC_H_
#define __STATIC_GRAPHIC_H_

#include "mssbTypes.h"
#include "Dolphin/gx.h"

void fn_800A7BAC(u8 arg0);
void fn_800A7C08(void);
void fn_800A7D4C(s32 index, u32* entry);
void fn_800A7D7C(u32* list, s32 count);
void fn_800A7DB0(void);
void fn_800A7E00(void);
void fn_800A7F10(s32 arg0);
void initRenderMode(GXRenderModeObj* rmode, u32 fifoSize, s32 overscan);
void fn_800A84C4(u32 retraceCount);

#endif // !__STATIC_GRAPHIC_H_
