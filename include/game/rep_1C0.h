#ifndef __GAME_rep_1C0_H_
#define __GAME_rep_1C0_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "game/rep_D0.h"

struct DrawTask1C0;
struct DrawTaskArg1C0;
struct DrawTaskTiles1C0;
struct StadiumFile;

void (*setFanObjPtr(void))(void);
void fn_3_35E4(void (*callback)(void));
void fn_3_35F0(void);
void fn_3_3638(StadiumDrawTask* task);
void fn_3_3818(struct DrawTask1C0* task);
void fn_3_38E8(void (*draw)(MtxPtr view, s32, s32));
void fn_3_3904(void);
void fn_3_3BE8(void);
void fn_3_3EE8(void);
void fn_3_42CC(void);
void fn_3_4984(void);
void fn_3_4A38(void);
void fn_3_4F90(void);
void fn_3_53E0(void);
void fn_3_5518(void);
void fn_3_567C(void);
void fn_3_5BAC(void);
void fn_3_5BCC(struct DrawTaskArg1C0* task);
void fn_3_5BF0(struct DrawTask1C0* task);
void fn_3_5C68(struct DrawTaskTiles1C0* task);
void fn_3_5E60(void);
void fn_3_5EC0(struct StadiumFile* file);
s16 fn_3_6424(u8* data, CollisionBox** out);
void fn_3_64DC(void);

#endif // !__GAME_rep_1C0_H_
