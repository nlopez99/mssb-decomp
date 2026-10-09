#ifndef __CHALLENGE_rep_7920_H_
#define __CHALLENGE_rep_7920_H_

#include "mssbTypes.h"

struct Sprite7920;
struct TexHeader7920;
struct TexRef7920;

void fn_1_26B7C(struct Sprite7920* p);
struct TexRef7920* fn_1_26BFC(struct TexHeader7920* header, s32 index);
struct Sprite7920* fn_1_26C2C(struct TexRef7920* tex, s32 index);

#endif // !__CHALLENGE_rep_7920_H_
