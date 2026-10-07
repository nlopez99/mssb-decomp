#ifndef __GAME_sta_c6_H_
#define __GAME_sta_c6_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "Dolphin/GX/GXTypes.h"

struct StaC6Draw;
struct StaC6Shape;
struct StaC6Sort;

void fn_3_E59B4(void* arg);
void fn_3_E5A1C(void* arg);
void fn_3_E5A84(struct StaC6Draw* draw);
void fn_3_E5CBC(struct StaC6Draw* draw, f32 t);
s32 fn_3_E5E14(struct StaC6Shape* shape);
void fn_3_E5E70(GXColor* dst, u8 format, void* src);
void fn_3_E5FEC(struct StaC6Draw* draw);
void fn_3_E6410(struct StaC6Draw* draw);
GXColor* fn_3_E64A8(void);
void fn_3_E6528(struct StaC6Draw* draw);
void fn_3_E6578(struct StaC6Draw* draw);
void fn_3_E6638(void* arg);
void fn_3_E6684(void* arg);
void fn_3_E671C(void* arg);
void fn_3_E6798(void* arg);
void fn_3_E67F4(void);
void fn_3_E68A8(void* arg);
void fn_3_E698C(void* arg);
void fn_3_E6A48(struct StaC6Draw* draw);
void fn_3_E6D90(void* arg);
void fn_3_E7350(void);
void fn_3_E7364(s32 idx);
void fn_3_E7388(void* arg0, struct StaC6Sort* out);
void fn_3_E7424(void);
void* fn_3_E751C(s32 idx, Mtx m);
void fn_3_E763C(void);
void fn_3_E7A2C(struct StaC6Draw* draw);
u8 fn_3_E7B20(void** files, s32* indices);
BOOL fn_3_E8AC8(void);
void fn_3_E8B24(void** files);

#endif // !__GAME_sta_c6_H_
