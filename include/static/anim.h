#ifndef __STATIC_ANIM_H_
#define __STATIC_ANIM_H_

#include "mssbTypes.h"

struct AnimFile;
struct AnimSub;
struct AnimState;
struct Model;

u32 fn_80024D2C(struct AnimSub* anim);
void fn_80025C58(struct AnimFile* file, struct Model* model);
int fn_80024DB0(struct AnimSub* anim);
void fn_80025DDC(struct AnimFile* file);
void fn_80025EEC(struct AnimState* state, int set, int index);
void fn_80025FFC(void* file, struct AnimState* state);

#endif // !__STATIC_ANIM_H_
