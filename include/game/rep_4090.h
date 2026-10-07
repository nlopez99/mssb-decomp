#ifndef __GAME_rep_4090_H_
#define __GAME_rep_4090_H_

#include "mssbTypes.h"
#include "Dolphin/vec.h"

struct Emitter4090;

BOOL fn_3_16C548(struct Emitter4090* emitter);
void fn_3_16C878(Vec* pos, struct Emitter4090* emitter, s32 n);
void fn_3_16CC2C(Vec* pos, u8 fielder);
bool fn_3_16D4D8(u8 player, f32 height);
void fn_3_16D5E4(u8 fielder);

#endif // !__GAME_rep_4090_H_
