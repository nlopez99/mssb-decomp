#ifndef __GAME_m_sound_H_
#define __GAME_m_sound_H_

#include "mssbTypes.h"
#include "Dolphin/vec.h"
#include "musyx/musyx.h"

void fn_3_8B094(void);
BOOL fn_3_8B258(s32 state, s32 id, s32 arg);
void fn_3_8B2E4(void);
void fn_3_8B318(int arg);
void fn_3_8B718(Vec* pos, Vec* vel, Vec* dir);
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
void fn_3_8C104(s32 vol);
bool fn_3_8C2DC(u32 steps, s32 sel);
BOOL fn_3_8C4F0(u32 steps, u8 target);
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
SND_VOICEID fn_3_90150(s32 charID, s32 sound);
u32 fn_3_90220(s32 charID, s32 sound);
SND_VOICEID playSoundEffect(int sound);
void fn_3_902FC(void);
void fn_3_90328(s32 time);
void fn_3_903B8(void);
void fn_3_90434(void);
BOOL fn_3_9056C(s32 song);
void fn_3_90674(s32 song);
void fn_3_906FC(void);
struct Unk90754;
void fn_3_90754(struct Unk90754* p, u8 a, u8 b);
int fn_3_90764(void);
int fn_3_90798(void);
void fn_3_9081C(void);
void fn_3_90CB0(void);
BOOL fn_3_90DD8(void);
BOOL fn_3_90860(void);
void fn_3_908E8(void);
int fn_3_90928(void);
void fn_3_909B0(void);
BOOL fn_3_90A18(void);
void fn_3_90AB0(s32 charID);
BOOL fn_3_90B14(int first, int second);
BOOL fn_3_90C14(int charID);
int fn_3_90F48(void);
int fn_3_91064(void);
int fn_3_910AC(void);

#endif // !__GAME_m_sound_H_
