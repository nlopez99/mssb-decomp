#ifndef __GAME_m_sound_H_
#define __GAME_m_sound_H_

#include "mssbTypes.h"
#include "Dolphin/vec.h"
#include "musyx/musyx.h"

void fn_3_8B094(void);
void fn_3_8B2E4(void);
void fn_3_8B718(void);
void fn_3_8B7DC(void);
void fn_3_8B804(void);
void fn_3_8B890(s32 handle);
void fn_3_8B964(SND_FVECTOR* pos, SND_FVECTOR* dir, SND_FVECTOR* heading);
void fn_3_8B9BC(SND_FVECTOR* pos);
void fn_3_8BA60(s32 handle, Vec* pos, Vec* dir);
s32 fn_3_8BBC4(u32 id, Vec* pos, Vec* dir, s32 arg3);
void fn_3_8BDF4(void);
void fn_3_8BE8C(void);
void fn_3_8C07C(void);
void fn_3_8C104(s32 arg0);
void fn_3_8C2DC(void);
void fn_3_8C4F0(void);
void fn_3_8C5C8(void);
void fn_3_8CD74(void);
void fn_3_8D9C0(void);
void fn_3_8DA80(void);
void fn_3_8F1C8(void);
void fn_3_8F21C(void);
void fn_3_8FC0C(void);
void fn_3_8FC80(void);
void fn_3_8FF18(void);
SND_VOICEID fn_3_8FF5C(s32 sound, f32 x, f32 y, f32 z);
SND_VOICEID fn_3_90064(int id);
void fn_3_90150(void);
u32 fn_3_90220(s32 charID, s32 sound);
SND_VOICEID playSoundEffect(int sound);
void fn_3_902FC(void);
void fn_3_903B8(void);
void fn_3_906FC(void);
struct Unk90754;
void fn_3_90754(struct Unk90754* p, u8 a, u8 b);
int fn_3_90764(void);
int fn_3_90798(void);
void fn_3_9081C(void);
void fn_3_908E8(void);
void fn_3_909B0(void);
int fn_3_91064(void);
int fn_3_910AC(void);

#endif // !__GAME_m_sound_H_
