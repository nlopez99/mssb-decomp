#ifndef __GAME_rep_1FD8_H_
#define __GAME_rep_1FD8_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"

struct StadiumObjectCollision;
struct StadiumModel1D58;
struct Rep1FD8Particle;
struct Rep1FD8Spawner;
struct Rep1FD8Draw;

void fn_3_C1964(void);
void fn_3_C1974(u8* stadium);
void fn_3_C19C8(void);
void fn_3_C1C18(void);
void fn_3_C2244(void);
void fn_3_C2310(struct StadiumModel1D58* model, Mtx view);
void fn_3_C23E0(void);
void fn_3_C24A0(void);
void fn_3_C2644(void);
void fn_3_C2974(void);
void fn_3_C298C(void);
u8 fn_3_C2AA0(Vec* pos, f32 width, f32 height);
void fn_3_C2C80(struct Rep1FD8Particle* p, struct Rep1FD8Spawner* spawner);
void fn_3_C2EDC(struct Rep1FD8Particle* p);
BOOL fn_3_C30F0(struct Rep1FD8Spawner* spawner);
void fn_3_C366C(struct Rep1FD8Spawner* spawner, u8 idx);
void fn_3_C39C8(void);
void fn_3_C3A38(camera_803c639c_s* camera);
void fn_3_C3C2C(void);
void fn_3_C3E94(Vec* pos, s32 i);
void fn_3_C3F70(struct Rep1FD8Draw* draw);
void fn_3_C4068(struct Rep1FD8Draw* draw);
void fn_3_C40EC(struct Rep1FD8Draw* draw);
void fn_3_C414C(s32 idx);
void fn_3_C42A4(u32* n, s32* count);
void fn_3_C444C(void);
BOOL fn_3_C4724(struct Rep1FD8Spawner* spawner);
void fn_3_C48D0(void);
void fn_3_C4B80(void);
void fn_3_C4CF4(struct Rep1FD8Spawner* spawner, u8 layer);
void fn_3_C4F00(void);
void fn_3_C5304(struct Rep1FD8Spawner* spawner, struct Rep1FD8Draw* draw);
void fn_3_C54D0(struct Rep1FD8Draw* draw);
void fn_3_C56E8(void);
void fn_3_C597C(void);
BOOL fn_3_C5CE0(struct Rep1FD8Draw* draw);
void fn_3_C5DDC(void);
BOOL fn_3_C625C(struct Rep1FD8Draw* draw);
void fn_3_C63D0(void);
void fn_3_C71CC(void);
void fn_3_C7444(struct Rep1FD8Draw* draw);
void fn_3_C749C(void);
BOOL fn_3_C75B8(struct Rep1FD8Spawner* spawner);
void fn_3_C77AC(void);
void fn_3_C7A0C(void);
void fn_3_C805C(u32* n, s32* count);
struct StadiumObjectCollision* fn_3_C823C(s32 idx, MtxPtr mtx);
void fn_3_C82B4(void);
void fn_3_C8650(void);

#endif // !__GAME_rep_1FD8_H_
