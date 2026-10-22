#ifndef __STATIC_STATIC_8000F150_H_
#define __STATIC_STATIC_8000F150_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

typedef struct TextModelSet {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ u16 first;
    /* 0x16 */ u16 count;
} TextModelSet;

void fn_8000F150(void* arg);
void fn_8000F3E8(s32 arg0);
void somethingSetTexturePointer(void);
void fn_8000F4B8(s32 a, s32 b, s32 c, s32 d);
void fn_8000F534(struct TextModel* model, BOOL active);
void fn_8000F8F4(struct TextModelSet* set);
s32 fn_8000F988(struct TextModelSet* set, s32 i, u16 arg2, s32 font, s32 str, BOOL flag);
s32 fn_8000FA9C(s32 i);
void fn_8000FD54(s32 i, s16 a, s16 b, s16 c, s16 d);
void fn_8000FD78(s32 i, s16 a, s16 b, s16 c, s16 d);
void fn_8000FD9C(s32 i, s32 mode, s32 arg2);
void fn_8000FE08(s32 i, s32 font, s32 str);
void fn_8000FE54(void);
void fn_8000FEE8(s32 i);
s32 fn_8000FF04(s32 font, s32 str, s16 x, s16 y, s32 group, s32 arg5, u8 arg6);
void fn_800100A4(s32 x, s32 y, u16 s, u16 t, u16 w, u32 color, s32 font, MtxPtr mtx);
void DrawText(s32 i);
void DrawTextOnCondition(s32 group);
void fn_80010FA0(void);
void fn_80011000(void);
void fn_80011140(void);
void fn_800111B4(struct RelocTable* table);

#endif // !__STATIC_STATIC_8000F150_H_
