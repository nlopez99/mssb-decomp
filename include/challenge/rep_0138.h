#ifndef __CHALLENGE_rep_0138_H_
#define __CHALLENGE_rep_0138_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "Dolphin/gx.h"

void fn_1_4DD8(u16* data);
struct DObj0138;
void fn_1_4E98(struct DObj0138* obj, MtxPtr camera);
void fn_1_54E0(MtxPtr view);
void fn_1_5540(void);
void fn_1_5544(GXTevStageID stage, GXIndTexStageID indStage, GXIndTexMtxID mtx, GXTexCoordID coord, GXTexMapID map);
void fn_1_5698(void);
s32 fn_1_5924(s32 width, s32 x, s32 y, s32 bpp, s32 arg4);
void fn_1_5AC0(u16* image, s32 width, s32 height, f32 scale);
void fn_1_6050(u16* image, s32 width, s32 height, f32 scale);
void fn_1_6578(GXTexObj* obj, u16* image, s32 width, s32 height);
void fn_1_66C4(void);
void fn_1_6848(void);
void fn_1_6E14(void);
struct File0138;

void fn_1_717C(struct File0138* file);
void fn_1_7280(void);
void fn_1_73B8(void* arg0, u8 count, ...);
void fn_1_77EC(void* arg0);
void fn_1_7848(void);
void fn_1_786C(void);
void fn_1_78E4(void);
void fn_1_7960(void);
void fn_1_7E04(f32 zoom);
void fn_1_7EF8(void);
void fn_1_7FF8(void);
void fn_1_8368(void);
void fn_1_85A8(void);

#endif // !__CHALLENGE_rep_0138_H_
