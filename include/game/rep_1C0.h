#ifndef __GAME_rep_1C0_H_
#define __GAME_rep_1C0_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "Dolphin/GX/GXTypes.h"
#include "game/rep_D0.h"

struct DrawTask1C0;
struct DrawTaskArg1C0;
struct DrawTaskTiles1C0;
struct StadiumFile;
struct StadiumTex;

void (*setFanObjPtr(void))(void);
void fn_3_35E4(void (*callback)(void));
void fn_3_35F0(void);
void fn_3_3638(StadiumDrawTask* task);
void fn_3_3818(struct DrawTask1C0* task);
void fn_3_38E8(void (*draw)(MtxPtr view, s32, u32));
void fn_3_3904(s16 x, s16 y, s32 id, GXColor c1, GXColor c2, u8 flag);
void fn_3_3BE8(struct StadiumTex* tex, s16 x0, s16 y0, s16 x1, s16 y1, s16 u, s16 v, s16 w, s16 h);
void fn_3_3EE8(struct StadiumTex* tex, s16 x0, s16 y0, s16 x1, s16 y1, s16 u, s16 v, s16 w, s16 h);
void fn_3_42CC(GXTexObj* obj, s16 x0, s16 y0, s16 x1, s16 y1, s16 u, s16 v, s16 w, s16 h, GXColor c1,
                GXColor c2, u8 flag);
void fn_3_4984(void);
void fn_3_4A38(u8 stadium);
void fn_3_4F90(GXTexObj* obj, s16 x, s16 y, s16 value, u8 digits, GXColor c1, GXColor c2, u8 flag);
void fn_3_53E0(u16* text, s16* u, s16* v, s16* w, s16* h, s16* page);
void fn_3_5518(void);
void fn_3_567C(void);
void fn_3_5BAC(void);
void fn_3_5BCC(struct DrawTaskArg1C0* task);
void fn_3_5BF0(struct DrawTask1C0* task);
void fn_3_5C68(struct DrawTaskTiles1C0* task);
void fn_3_5E60(void);
void fn_3_5EC0(struct StadiumFile* file);
s16 fn_3_6424(u8* data, CollisionBox** out);
void fn_3_64DC(void);

#endif // !__GAME_rep_1C0_H_
