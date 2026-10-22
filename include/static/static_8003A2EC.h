#ifndef __STATIC_STATIC_8003A2EC_H_
#define __STATIC_STATIC_8003A2EC_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "Dolphin/gx.h"

void fn_8003A2EC(void);
void fn_8003A37C(MtxPtr mtx, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* count, u8* mtxIdx);
void fn_8003A4C8(void);
s32 fn_8003A538(void);
void fn_8003A540(s32 value);
void fn_8003A548(void (*value)(void));
void fn_8003A550(s32 tex, Vec* pos, Vec* dir, u8 arg3);
void fn_8003A688(s32 i, f32 width, f32 height);
void fn_8003A6B0(s32 i, struct TextureDesc* tex, f32 width, f32 height);
void fn_8003A848(u8 r, u8 g, u8 b);
void fn_8003A85C(u8 enabled);
void fn_8003A8A0(struct Model* model, MtxPtr view, s32 arg2);
void fn_8003AC90(void);
void fn_8003AD84(struct TextureEntry* entry);
u8 fn_8003AE54(void);
void fn_8003AE5C(u8 value);
void fn_8003AE64(u32 request);
u8 fn_8003AE70(s32 kind);
void fn_8003AECC(void);
void fn_8003B5B0(void);
void fn_8003BB90(void);
void fn_8003BF54(u8 arg0, u8 arg1, u8 slot, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8);
void fn_8003C00C(void);
void fn_8003E8D8(void);
void fn_8003F23C(void);
void fn_8003F2B8(void);
void fn_8004053C(void);
void fn_80040C14(void);
s32 fn_80040FE0(struct SaveFile* save);
s32 fn_80041074(struct SaveFile* save, s32 arg1, s32 mask);
void fn_80041150(u8 mask, u8 slot);
u8 fn_80041348(void);
void fn_8004153C(void);

#endif // !__STATIC_STATIC_8003A2EC_H_
