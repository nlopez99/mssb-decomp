#ifndef __CHALLENGE_rep_74A0_H_
#define __CHALLENGE_rep_74A0_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct Sort74A0;
struct Model74A0;
struct ModelTable74A0;
struct Shape74A0;
struct Particle74A0;

s32 fn_1_17EFC(struct Sort74A0* a, struct Sort74A0* b);
struct Particle74A0* fn_1_17F28(struct Particle74A0* list, s32 count);
s32 fn_1_19D1C(u32 fmt);
void fn_1_19D60(struct Shape74A0* shape, Mtx mtx);
void fn_1_1A1EC(struct Model74A0* model, Mtx mtx);
void fn_1_1A290(struct ModelTable74A0* table, Mtx mtx);
void fn_1_1A774(void);
void fn_1_1A850(Mtx m, void* arg1, u8 r, u8 g, u8 b, u8 a);
void fn_1_1B038(void);
void fn_1_1CBE4(void);
void fn_1_1D0E8(struct Model74A0* model);
void fn_1_1D10C(void);
void fn_1_1D450(void);
void fn_1_1D470(void);
void fn_1_1D514(void);

#endif // !__CHALLENGE_rep_74A0_H_
