#ifndef __STATIC_UITEXTURE_H_
#define __STATIC_UITEXTURE_H_

#include "mssbTypes.h"
#include "static/sub.h"

// The screen effect the frame's last draw applies: a full-screen copy of the frame drawn back
// scaled, jittered and faded
typedef struct ScreenEffect {
    /* 0x00 */ f32 scale;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 jitterX;
    /* 0x0C */ f32 jitterY;
    /* 0x10 */ u16 width;
    /* 0x12 */ u16 height;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 alpha;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 repeat;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 flags;
    /* 0x1E */ u8 _1E[0x20 - 0x1E];
} ScreenEffect; // size: 0x20

typedef struct ScreenEffectSlot {
    /* 0x00 */ s32 _00;
    /* 0x04 */ void (*callback)(struct ScreenEffectSlot* slot);
    /* 0x08 */ ScreenEffect fx;
} ScreenEffectSlot; // size: 0x28

extern u16 lbl_800F7AC0[16];
extern TextureDesc lbl_800F7AE0;

void* GetUITexture(void);
TextureDesc* fn_80039AB4(void);
void fn_80039AC0(void);
void fn_80039FF8(ScreenEffectSlot* slot);
void fn_8003A090(void);
void fn_8003A144(void);
void fn_8003A1D0(void);
void fn_8003A2C0(void);

#endif // !__STATIC_UITEXTURE_H_
