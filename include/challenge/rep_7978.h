#ifndef __CHALLENGE_rep_7978_H_
#define __CHALLENGE_rep_7978_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

// A free-flying debug camera driven by the first controller
typedef struct Camera7978 {
    /* 0x00 */ Mtx _00;
    /* 0x30 */ Mtx44 _30;
    /* 0x70 */ Vec _70;
    /* 0x7C */ Vec _7C;
    /* 0x88 */ Vec _88;
    /* 0x94 */ u8 _94[0xA4 - 0x94];
    /* 0xA4 */ f32 _A4;
    /* 0xA8 */ f32 _A8;
    /* 0xAC */ f32 _AC;
    /* 0xB0 */ f32 _B0;
    /* 0xB4 */ f32 _B4;
    /* 0xB8 */ f32 _B8;
    /* 0xBC */ f32 _BC;
    /* 0xC0 */ f32 _C0;
    /* 0xC4 */ f32 _C4;
    /* 0xC8 */ f32 _C8;
    /* 0xCC */ f32 _CC;
    /* 0xD0 */ f32 _D0;
    /* 0xD4 */ f32 _D4;
    /* 0xD8 */ void (*_D8)(struct Camera7978* cam, u16 held, u16 pressed, u16 repeat, s8* stick);
} Camera7978; // size: 0xDC

void fn_1_26D28(struct Camera7978* cam, u16 held, u16 pressed, u16 repeat, s8* stick);
void fn_1_272DC(struct Camera7978* cam, s32 id);
void fn_1_27330(struct Camera7978* cam);
void fn_1_273D8(struct Camera7978* cam);

#endif // !__CHALLENGE_rep_7978_H_
