#ifndef __GAME_rep_3090_H_
#define __GAME_rep_3090_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct Unk3090Track;
struct Unk3090View;

void fn_3_FBD58(void);
void fn_3_FBD70(void);
void fn_3_FBDAC(int);
void fn_3_FBE24(void);
void fn_3_FC2FC(void);
void fn_3_FC448(void);
void fn_3_FC938(void);
int fn_3_FCE38(int i, f32 time);
void fn_3_FCEAC(void);
int fn_3_FCEB0(f32 time);
void fn_3_FCF20(void);
void fn_3_FCF24(void);
void fn_3_FD408(void);
void fn_3_FD4DC(void);
void fn_3_FD51C(void);
void fn_3_FD5A8(void);
void fn_3_FD670(void);
BOOL fn_3_FD9FC(void);
void fn_3_FDA1C(void);
void fn_3_FDB30(void);
BOOL fn_3_100018(void);
void fn_3_100038(void);
BOOL fn_3_10007C(void);
void fn_3_1000D8(void);
void fn_3_101CC4(void);
void fn_3_103C30(void);
void fn_3_103E7C(void);
void fn_3_1040D8(void);
void fn_3_104338(void);
void fn_3_1045A8(void);
void fn_3_104740(void);
void fn_3_1048E0(void);
void fn_3_104A3C(Vec* out, Mtx44 mtx);
void fn_3_104A88(Vec* out, Mtx44 mtx);
void fn_3_104AD4(Vec* out, Mtx44 mtx);
void fn_3_104B20(Vec* out, Mtx44 mtx);
void fn_3_104B3C(void);
void fn_3_1054CC(void);
void fn_3_1054D0(void);
void fn_3_105A10(void);
void fn_3_105ACC(void);
void fn_3_105BD8(struct Unk3090View* view);
u32 fn_3_105C28(struct Unk3090Track* track, u32 time);
void fn_3_105C84(struct Unk3090Track* track);
void fn_3_105CDC(void);
void fn_3_105E00(void);
void fn_3_106014(void);
void fn_3_1060D8(void);
void fn_3_10617C(void);
void fn_3_106270(void);
int fn_3_10698C(void** list);
void* fn_3_1069B0(void* base, int index);
void fn_3_1069C0(void);
void fn_3_106BA0(void);

#endif // !__GAME_rep_3090_H_
