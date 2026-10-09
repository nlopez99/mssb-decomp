#ifndef __MENUS_rep_04B0_H_
#define __MENUS_rep_04B0_H_

#include "mssbTypes.h"

struct Pad04B0;

void fn_2_13BA4(struct Pad04B0* pad);
void fn_2_13CA0(struct Pad04B0* pad);
void fn_2_13D70(struct Pad04B0* pad);
void fn_2_1406C(struct Pad04B0* pad);
void fn_2_14164(struct Pad04B0* pad);
void fn_2_14220(struct Pad04B0* pad);
void fn_2_14574(struct Pad04B0* pad);
void fn_2_14790(void);
void fn_2_14BB8(u8 port, s32 mode);
void fn_2_14CA0(u8 port, struct Pad04B0* pad);
void fn_2_14FB8(s32 team);
void fn_2_150D0(u8 port);
BOOL fn_2_15104(s32 a, s32 b, u8 port, u8 value);
void fn_2_151BC(u8 port);
void fn_2_1560C(u8 port);
void fn_2_15A90(s32* value, u8 port, s32 max);
void fn_2_15AFC(s32 port, u16 hold, u16 trg, u16 rep);
void fn_2_15E80(u8 port);
void fn_2_1641C(void);
void fn_2_16460(void);
void fn_2_16664(void);
void fn_2_166CC(void);
void fn_2_16724(void);

#endif // !__MENUS_rep_04B0_H_
