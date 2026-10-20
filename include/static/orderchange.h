#ifndef __STATIC_ORDERCHANGE_H_
#define __STATIC_ORDERCHANGE_H_

#include "mssbTypes.h"

s32 fn_80042598(u8 team, s32 charId);
void transferStatsToInMemRoster(u8 team);
s32 randRange_FUN_80042bf0(s32 min, s32 max);
void sndFXRelated(u16 id);
void fn_80042D38(u16 scene);
s32 fn_80042D68(struct SpriteGroup* group, s32 index, s32 frame);
s32 fn_80042DA8(struct SpriteGroup* group, s32 index, s32 frame);
void challengeStarMenu(void);
void starMenuCursor(void);
void fn_80043880(u8 dir, u8 player);
void fn_80044C98(u8 dir, u8 player);
void fn_8004617C(s32 team);
u8 fn_800471F4(u8 mode, u8 player);
void fn_80047CE0(void);
void pauseMenuSelection(void);
void fn_800486E0(s32 priority, s8 team, u8 player);
void fn_80048764(void);
s32 fn_80048820(struct DebugMenu* menu, u16 held, u16 pressed, u16 repeat, u8 trigger);
void fn_80048BEC(struct DebugMenu* menu);

#endif // !__STATIC_ORDERCHANGE_H_
