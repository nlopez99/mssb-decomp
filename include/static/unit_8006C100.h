#ifndef __STATIC_UNIT_8006C100_H_
#define __STATIC_UNIT_8006C100_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

u8 fn_8006C100(s16 value);
s16 fn_8006C13C(struct StatBlock* block);
s16 fn_8006C268(struct StatTotals* totals);
void fn_8006C2B4(struct StatTotals* out, struct StatBlock* block);
void fn_8006C398(struct StatBlock* block);
void fn_8006C3F0(void (*callback)(void* arg0, void* arg1, void* arg2));
void fn_8006C3F8(void* arg0, void* arg1, void* arg2);
void fn_8006C43C(void (*callback)(void* arg0, void* arg1, void* arg2));
void fn_8006C444(void* arg0, void* arg1, void* arg2);
void fn_8006C488(void);

#endif // !__STATIC_UNIT_8006C100_H_
