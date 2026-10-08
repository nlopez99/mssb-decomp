#ifndef __GAME_rep_1E08_H_
#define __GAME_rep_1E08_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct UnkKey21F8;
struct UnkPlayer1E08;
struct UnkPanel1E08;
struct UnkSpark1E08;
struct UnkPanelList1E08;
struct UnkAnim21F8;
struct UnkEffect21F8;

void fn_3_BA538(struct UnkPanel1E08* panel);
BOOL fn_3_BA7F4(void* arg);
void fn_3_BB07C(struct UnkPanel1E08* obj, f32 angle);
void fn_3_BB15C(struct UnkPanel1E08* panel);
void fn_3_BB454(struct UnkPanelList1E08* list);
void fn_3_BB7F4(void);
void fn_3_BBBC4(void);
void fn_3_BBF94(void);
void fn_3_BC224(void);
void fn_3_BC25C(void);
BOOL fn_3_BC274(struct UnkPlayer1E08* player, struct _VecXYZ* a, struct _VecXYZ* b);
void fn_3_BC2DC(void);
void fn_3_BC6D8(Vec* pos, Vec* eye, int type, BOOL flag);
void fn_3_BC850(void* arg0, s32 index);
void fn_3_BC888(void);
void fn_3_BCA20(void);
void fn_3_BD1D4(void);
void fn_3_BD1D8(Mtx view);
void fn_3_BD434(s32 stadium, s32 mode);
void fn_3_BD4F0(void);
void fn_3_BD504(f32 x, f32 y, f32 z, BOOL arg3);
void fn_3_BD6AC(s32 arg0, f32 x, f32 y, f32 z);
void fn_3_BD758(void);
BOOL fn_3_BD7D0(void);
void fn_3_BD7D8(void);
void fn_3_BD7DC(s32 arg0);
void fn_3_BD80C(s32 arg0);
void fn_3_BD8D8(void);
void fn_3_BD8FC(struct UnkSpark1E08* spark);
void fn_3_BDCA4(void);
void fn_3_BDE14(void);
void fn_3_BDF74(void);
void fn_3_BE140(void);
void fn_3_BE174(s32 type, f32 x, f32 y, f32 z);
void fn_3_BE1D4(void);
void fn_3_BEFF8(void);
void fn_3_BF070(void);
void fn_3_BF158(void);
void fn_3_BF1AC(void);
void fn_3_BF20C(void);
void fn_3_BF238(void);
void fn_3_BF6C0(void);
BOOL fn_3_BF878(void);
void fn_3_BF8F8(struct UnkEffect21F8* effect, Mtx m, Vec* pos,
                 f32 (*callback)(struct UnkAnim21F8*, int, Mtx, f32));
f32 fn_3_BFB3C(struct UnkAnim21F8* anim, int frame, Mtx m, f32 t);
f32 fn_3_BFDA4(struct UnkKey21F8* keys, int count, int frame, u8 current, u8* currentOut, f32 t);
BOOL fn_3_C0134(void* arg);
void fn_3_C0770(void);
void fn_3_C07A0(void);
void fn_3_C07B0(void);

#endif // !__GAME_rep_1E08_H_
