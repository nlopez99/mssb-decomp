#ifndef __GAME_sta_c5_H_
#define __GAME_sta_c5_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct StaC5Draw;
struct StaC5Emitter;
struct StadiumObjectCollision;
struct StaC5Ball;

void fn_3_EDFAC(void);
s32 fn_3_EE0BC(u32 flags);
void fn_3_EE100(void);
void fn_3_EE388(void);
void fn_3_EE67C(void);
void fn_3_EE96C(Vec* pos);
void fn_3_EEB94(void);
void fn_3_EECF4(void);
void fn_3_EEE3C(void);
void fn_3_EEF24(void);
void fn_3_EEFA4(void);
void fn_3_EEFD0(void);
void fn_3_EEFD4(s32 idx);
void fn_3_EF218(void);
void fn_3_EF21C(void);
void fn_3_EF3D4(struct StaC5Draw* draw, u8 idx);
void fn_3_EF408(struct StaC5Draw* draw);
void fn_3_EF55C(void);
void fn_3_EF7B4(void);
void fn_3_EF800(struct StaC5Draw* draw);
void fn_3_EF890(struct StaC5Draw* draw);
void fn_3_EF930(struct StaC5Draw* draw);
void fn_3_EFB54(void);
void fn_3_F0184(void);
void fn_3_F0224(void);
void fn_3_F082C(void);
void fn_3_F0FA4(void);
void fn_3_F13F8(struct StaC5Draw* draw);
void fn_3_F1448(struct StaC5Draw* draw);
void fn_3_F1518(struct StaC5Draw* draw);
void fn_3_F1674(void);
void fn_3_F1750(struct StaC5Draw* draw);
void fn_3_F18A4(struct StaC5Draw* draw);
void fn_3_F193C(void);
void fn_3_F1E2C(void);
void fn_3_F22FC(struct StaC5Draw* draw, s8 idx);
void fn_3_F2448(void);
void fn_3_F2724(struct StaC5Draw* draw, struct StaC5Draw* target);
void fn_3_F2938(void);
void fn_3_F2FFC(void);
void fn_3_F31E0(void);
u32 fn_3_F37BC(u32 n, u32 k);
void fn_3_F38D4(void);
void fn_3_F3A04(struct StaC5Draw* draw);
void fn_3_F3A5C(struct StaC5Draw* draw, f32 x, f32 y, f32 z, f32 rotY);
void fn_3_F3AE0(struct StaC5Draw* draw);
void fn_3_F3BB0(struct StaC5Draw* draw);
BOOL fn_3_F3CD0(struct StaC5Emitter* emitter);
void fn_3_F3EFC(void);
void fn_3_F42A0(void);
void fn_3_F466C(void);
void fn_3_F469C(void);
void fn_3_F46A0(void);
void fn_3_F4BA0(struct StaC5Ball* obj);
void fn_3_F4C4C(struct StaC5Ball* obj);
void fn_3_F4D00(struct StaC5Ball* obj);
void fn_3_F4DAC(void);
void fn_3_F4FBC(void);
void fn_3_F56CC(void);
void fn_3_F5C30(struct StaC5Ball* obj);
s32 fn_3_F5E78(u8 id);
s32 fn_3_F5EFC(const void* a, const void* b);
s32 fn_3_F5F28(const void* a, const void* b);
void fn_3_F5F4C(MtxPtr mtx);
void fn_3_F6084(void);
struct StadiumObjectCollision* fn_3_F6504(s32 idx, MtxPtr mtx);
void fn_3_F65C8(s32* n);
void fn_3_F66C8(void);
void fn_3_F6938(s32* n);
void fn_3_F6A94(s32* n);
void fn_3_F6C60(void);
void fn_3_F6FCC(void);
void fn_3_F6FDC(void);

#endif // !__GAME_sta_c5_H_
