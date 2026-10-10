#ifndef __CHALLENGE_rep_7BF0_H_
#define __CHALLENGE_rep_7BF0_H_

#include "mssbTypes.h"

struct Camera7978;
struct Menu7BF0;
struct Sim7BF0;
struct Task7BF0;

void fn_1_2858C(struct Camera7978* cam, u16 held, u16 pressed, u16 repeat, s8* stick);
void fn_1_289C0(struct Camera7978* cam);
s32 fn_1_289E0(struct Menu7BF0* menu, u16 pressed);
s32 fn_1_28AE0(struct Menu7BF0* menu, u16 pressed);
void fn_1_28C34(struct Menu7BF0* menu, s32 index, char* title);
void fn_1_28CE8(struct Task7BF0* task);
void fn_1_2905C(void);
void fn_1_2935C(struct Sim7BF0* sim);
void fn_1_29414(struct Task7BF0* task);
void fn_1_2948C(struct Task7BF0* task);
void fn_1_295E8(void);
void fn_1_29A48(void);
void fn_1_29A9C(void);

#endif // !__CHALLENGE_rep_7BF0_H_
