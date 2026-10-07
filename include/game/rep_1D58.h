#ifndef __GAME_rep_1D58_H_
#define __GAME_rep_1D58_H_

#include "mssbTypes.h"
#include "Dolphin/GX/GXTypes.h"
#include "Dolphin/mtx.h"

struct _CollisionStruct;
struct StadiumObjectCollision;
struct StadiumObject1D58;
struct StadiumModel1D58;

s32 fn_3_B7FC8(u32 id, s32 arg1);
void fn_3_B80D0(void);
void fn_3_B8184(struct StadiumModel1D58* model, Mtx view);
struct StadiumObject1D58* fn_3_B827C(void);
void fn_3_B828C(struct StadiumObject1D58* obj);
void fn_3_B8298(void);
void fn_3_B8414(Vec* min, Vec* max);
void fn_3_B8464(Mtx mtx, struct StadiumObjectCollision* collision);
void fn_3_B8574(void);
u32 fn_3_B85A8(s32 area, s32** objects);
void fn_3_B85DC(s32 area, Vec* min, Vec* max);
s32 fn_3_B8658(const void* a, const void* b);
void fn_3_B867C(void);
void fn_3_B8828(void);
void fn_3_B8C08(Mtx view);
void fn_3_B902C(void);
void fn_3_B908C(void);
void fn_3_B9124(void);
void processStadiumObjectFunction(int stadium, s32 object, int type, struct _CollisionStruct* collision);
struct StadiumObjectCollision* fn_3_B91C8(int stadium, s32 object, Mtx mtx);
void fn_3_B939C(void);
void fn_3_B93C4(void);
void fn_3_B93C8(int arg0);
void fn_3_B93CC(void);
void fn_3_B950C(void);
void fn_3_B9510(s32 idx);
void fn_3_B9524(void);
u8* fn_3_B9534(s32 width, s32 height, GXTexObj* obj);
void fn_3_B95EC(void);
void fn_3_B97C8(void (*callback)(void));
void fn_3_B97DC(void* model, void* anim);
void fn_3_B98E8(struct StadiumModel1D58* model);
void fn_3_B99E4(void);
s32 fn_3_B9BB4(s32 stadium);
void fn_3_B9D68(u8* types, s32 count, void** files, s32* indices);
void fn_3_B9FB8(s32 stadium, void* file);

#endif // !__GAME_rep_1D58_H_
