#ifndef __STATIC_SPRT_H_
#define __STATIC_SPRT_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "Dolphin/GX/GXEnum.h"

struct SprtVtx;
struct SprtTex;
struct SprtLayer;

void fn_800B0D28(u32* value);
void fn_800B0D38(s32 index, s32 mode);
s32 AllocateSprite(s32 index, s32 size);
void fn_800B117C(u8 value);
void fn_800B1188(void);
void DrawNullSprite(struct SprtVtx* verts, s32 count);
void fn_800B12DC(struct SprtVtx* verts, s32 count);
void fn_800B1314(struct SprtVtx* verts, struct SprtTex* tex, u16 width, u16 height);
void DrawSprite_TexObj(struct SprtVtx* verts, struct SprtTex* tex);
void fn_800B1388(struct SprtVtx* verts);
void fn_800B13C0(Vec* pos, u32* colors, s32 count);
void fn_800B1468(Vec* pos, u32 color, struct SprtTex* tex);
void DrawSprite(s32 prim, struct SprtVtx* verts, s32 count, struct SprtTex* tex, u16 width, u16 height);
s32 fn_800B1EBC(struct SprtTex* tex, s32 arg1, u16 width, u16 height);
void fn_800B2160(u8 value);
s32 fn_800B216C(u8 enable, s32 func, u8 update);
void fn_800B21A8(s32 mode);
void fn_800B2240(struct SprtLayer* layer);
void fn_800B24D4(s32 index);
void fn_800B251C(void);
void fn_800B27A4(s32 shift);
void fn_800B27DC(Mtx44 m, GXProjectionType type);
void fn_800B2854(u8* buf, s32 size, Mtx44 proj, s32 projType, s32 count, u32* handles, u32* sizes);

#endif // !__STATIC_SPRT_H_
