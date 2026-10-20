#ifndef __STATIC_ANIM_H_
#define __STATIC_ANIM_H_

#include "mssbTypes.h"

struct AnimFile;
struct AnimPlayer;
struct AnimState;

u32 fn_80024D2C(struct AnimPlayer* anim);
void fn_80025DDC(struct AnimFile* file);
void fn_80025EEC(struct AnimState* state, int set, int index);
void fn_80025FFC(void* file, struct AnimState* state);

#endif // !__STATIC_ANIM_H_
