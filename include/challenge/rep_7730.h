#ifndef __CHALLENGE_rep_7730_H_
#define __CHALLENGE_rep_7730_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "Dolphin/gx.h"

struct Actor7730;
struct RopeParams7730;
struct Tex7730;
struct GameTask7730;

struct DrawEntry7730;

void fn_1_1D694(struct DrawEntry7730* entry);
void fn_1_1D944(void);
void fn_1_1DA54(void);
void fn_1_1DCE4(void);
f32 fn_1_1DD48(u16 buttons, s32 negate, f32 value, f32 step, f32 normal, f32 fast, f32 min, f32 max);
void fn_1_1DD94(void);
void fn_1_1DDE4(f32 v);
void fn_1_1DDF4(f32 v);
void fn_1_1DE04(f32 v);
void fn_1_1DE14(f32 v);
f32 fn_1_1DE20(void);
f32 fn_1_1DE30(void);
f32 fn_1_1DE40(void);
f32 fn_1_1DE50(void);
void fn_1_1DE5C(s16 arg0);
void fn_1_1DE60(s16 arg0);
void fn_1_1E28C(void);
void fn_1_1E5D0(void* arg0);
void fn_1_1E8C0(s32 arg0);
void fn_1_1EFF4(void);
void fn_1_1F05C(void);
void fn_1_1F23C(struct Actor7730* actor);
void fn_1_1F2D8(void);
void fn_1_1F418(struct GameTask7730* task);
void fn_1_1F618(struct GameTask7730* task);
void fn_1_1F900(struct GameTask7730* task);
void fn_1_1FD78(struct GameTask7730* task);
void fn_1_2004C(void);
void fn_1_202A4(void);
void fn_1_2040C(void);
GXBool fn_1_2051C(struct Tex7730* tex, GXTexObj* obj, GXTlutObj* tlutObj, GXTlut tlutName);
void fn_1_20640(struct GameTask7730* task, u32* ids);
void fn_1_207D4(void);
void fn_1_20890(void);
void fn_1_20BD8(void);
void fn_1_20DC8(void);
void fn_1_20F8C(void);
void fn_1_21040(void);
void fn_1_21180(struct RopeParams7730* params);
void fn_1_21298(struct RopeParams7730* params);
void fn_1_21408(void);
void fn_1_225B8(void);
void fn_1_22644(void);
void fn_1_22DF4(struct RopeParams7730* params);
void fn_1_22F4C(s32 rows, s32 cols, f32* out, f32* cur, f32* prev);
void fn_1_23AD8(Mtx44 m, Vec* eye, Vec* at);
void fn_1_24410(void);
void fn_1_246AC(void);
void fn_1_24778(void);
void fn_1_247A0(void);
void fn_1_267BC(void);
void fn_1_26928(void);
void fn_1_26A34(void);
void fn_1_25C68(void);
void fn_1_25F98(void);
void fn_1_267F4(void);
void fn_1_26AF8(void);

#endif // !__CHALLENGE_rep_7730_H_
