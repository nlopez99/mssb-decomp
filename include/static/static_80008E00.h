#ifndef __STATIC_STATIC_80008E00_H_
#define __STATIC_STATIC_80008E00_H_

#include "mssbTypes.h"

void fn_80008E00(void (*func)(s32));
BOOL fn_80008E08(void);
void PostRetraceCallback(u32 retraceCount);
void fn_8000900C(void);
struct MainSave* fn_80009018(struct MainSave* save);
u8 fn_80009028(void);
void fn_80009094(void);
void fn_800090B4(void);
void fn_80009144(void);
void main(void);

#endif // !__STATIC_STATIC_80008E00_H_
