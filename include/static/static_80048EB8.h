#ifndef __STATIC_STATIC_80048EB8_H_
#define __STATIC_STATIC_80048EB8_H_

#include "mssbTypes.h"

void startGameRelated(void);
void fn_80049220(u8 team);
void fn_800494CC(u8 team);
void possiblyTransferDataBetweenDifferentRels(void);
void fn_80049C80(void);
void fn_80049D3C(void);
void fn_80049D8C(u8 dir, u8 team);
void fn_8004A0FC(void);
void fn_8004A1BC(void);
void fn_8004A2BC(void);
s32 fn_8004A328(struct Card* card);
s32 fn_8004A34C(struct MsgWindow* window, u8 arg1, u8 msg, u8 arg3, s32 arg4);
void fn_8004A5B8(void);
void fn_8004A7D0(void);
void fn_8004A9E0(void);

// static_8004AC00.c (another worker's range)
void fn_8004CA14(s32 arg0, u16 id);
s32 fn_8004CA6C(u16 buttons);
void fn_8004CC18(void);
void fn_8004CC2C(void);
void fn_8004CC4C(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u16 id);
void fn_8004D0F0(void);

#endif // !__STATIC_STATIC_80048EB8_H_
