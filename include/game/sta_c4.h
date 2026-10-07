#ifndef __GAME_sta_c4_H_
#define __GAME_sta_c4_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct StaC4Particle;
struct StaC4Emitter;
struct StaC4Draw;
struct StaC4Hit;
struct StaC4Tex;
struct StaC4View;

void fn_3_F8444(void);
void fn_3_F8454(void);
void fn_3_F8524(struct StaC4Particle* p);
BOOL fn_3_F85B0(struct StaC4Emitter* emitter);
void fn_3_F8878(struct StaC4Emitter* emitter);
void fn_3_F8ABC(void);
void fn_3_F8B04(void);
void fn_3_F8B30(void);
void fn_3_F8B34(void);
void fn_3_F8BA8(struct StaC4Draw* draw);
void fn_3_F8D00(void);
void fn_3_F8E20(void);
void fn_3_F9088(Vec* pos, s32 i);
void fn_3_F9164(struct StaC4Draw* draw);
void fn_3_F92FC(void);
void fn_3_F934C(void);
void fn_3_F963C(s32 idx, struct StaC4Hit* hit);
void fn_3_F976C(s32 idx, void* arg1, struct StaC4Hit* hit);
void fn_3_F99F0(s32 idx, void* arg1, struct StaC4Hit* hit);
void fn_3_F9B9C(s32 idx, void* arg1, struct StaC4Hit* hit);
void fn_3_F9D94(struct StaC4Draw* draw);
void fn_3_F9E78(s32 idx, void* arg1, struct StaC4Hit* hit);
void fn_3_FA3C0(void);
void fn_3_FA58C(void** files);
void fn_3_FB3D8(struct StaC4View* view);
void fn_3_FBBA0(struct StaC4Tex* tex);
void fn_3_FBCD0(void);

#endif // !__GAME_sta_c4_H_
