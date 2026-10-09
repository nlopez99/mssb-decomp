#ifndef __CHALLENGE_rep_74A0_H_
#define __CHALLENGE_rep_74A0_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct Sort74A0;
struct Model74A0;
struct ModelTable74A0;
struct Shape74A0;
struct Particle74A0;
struct Camera74A0;
struct Emitter74A0;

s32 fn_1_17EFC(struct Sort74A0* a, struct Sort74A0* b);
struct Particle74A0* fn_1_17F28(struct Particle74A0* list, s32 count);
void fn_1_17FF0(void);
void fn_1_18174(void);
void fn_1_182C0(struct Particle74A0* p);
BOOL fn_1_1857C(struct Emitter74A0* e);
void fn_1_18E04(struct Particle74A0* p, f32 angle);
void fn_1_18EE4(struct Particle74A0* p);
void fn_1_191DC(struct Emitter74A0* e);
void fn_1_1957C(void);
void fn_1_1994C(void);
s32 fn_1_19D1C(u32 fmt);
void fn_1_19D60(struct Shape74A0* shape, Mtx mtx);
void fn_1_1A1EC(struct Model74A0* model, Mtx mtx);
void fn_1_1A290(struct ModelTable74A0* table, Mtx mtx);
void fn_1_1A774(void);
void fn_1_1A850(Mtx m, struct Camera74A0* cam, u8 r, u8 g, u8 b, u8 a);
void fn_1_1ADA4(void);
void fn_1_1B038(void);
void fn_1_1B0FC(void);
void fn_1_1B2C8(void);
void fn_1_1B424(void);
void fn_1_1B6BC(void);
void fn_1_1C3CC(void);
void fn_1_1C8C0(void);
void fn_1_1CBE4(void);
void fn_1_1D0E8(struct Model74A0* model);
void fn_1_1D10C(void);
void fn_1_1D110(void);
void fn_1_1D450(void);
void fn_1_1D470(void);
void fn_1_1D514(void);

#endif // !__CHALLENGE_rep_74A0_H_
