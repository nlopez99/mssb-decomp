#ifndef __GAME_rep_2998_H_
#define __GAME_rep_2998_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct Rep2998Obj;
struct Rep2998Mesh;

void fn_3_E1DB8(void);
void fn_3_E1FA8(struct Rep2998Obj* obj);
void fn_3_E2034(struct Rep2998Obj* obj);
void fn_3_E2118(u32 idx);
void fn_3_E22A4(struct Rep2998Obj* obj);
void fn_3_E2324(struct Rep2998Obj* obj);
void fn_3_E25D0(struct Rep2998Obj* obj, u32 anim);
void fn_3_E266C(struct Rep2998Obj* obj);
BOOL fn_3_E28DC(struct Rep2998Obj* obj);
BOOL fn_3_E29B4(struct Rep2998Obj* obj);
u8 fn_3_E2B70(struct Rep2998Obj* obj);
void fn_3_E2E78(struct Rep2998Obj* obj);
void fn_3_E2F4C(struct Rep2998Obj* obj);
void fn_3_E3044(struct Rep2998Obj* obj);
u8 fn_3_E3284(struct Rep2998Obj* obj);
void fn_3_E3668(struct Rep2998Obj* obj);
void fn_3_E3764(struct Rep2998Obj* obj);
void fn_3_E3914(struct Rep2998Obj* obj);
void fn_3_E3B88(void);
void fn_3_E4554(struct Rep2998Obj* obj);
void fn_3_E45A8(struct Rep2998Obj* obj);
void fn_3_E45F0(struct Rep2998Obj* obj);
void fn_3_E4658(struct Rep2998Obj* obj);
void fn_3_E4760(struct Rep2998Obj* obj);
void fn_3_E48D0(struct Rep2998Obj* obj);
void fn_3_E4A38(MtxPtr mtx, struct Rep2998Mesh* mesh);
void* fn_3_E4BE8(s32 idx, MtxPtr mtx);
void fn_3_E4CB0(s32* count, s32* objIdx);
void fn_3_E4EF4(void);
void fn_3_E4FC4(void);

#endif // !__GAME_rep_2998_H_
