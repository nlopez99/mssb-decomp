#ifndef __STATIC_FN_80021188_H_
#define __STATIC_FN_80021188_H_

#include "mssbTypes.h"
#include "musyx/musyx.h"

s32 fn_80021188(void);
s32 fn_800211BC(void);
u8 fn_800211F0(void);
void fn_80021204(void);
void fn_80021228(u8 mode);
void fn_8002128C(u8 mode);
void fn_80021308(void);
void fn_800213F4(void* addr);
void* fn_800213F8(u32 len);
BOOL fn_80021410(void);
void fn_8002149C(s32 group);
BOOL fn_800214D0(void);
BOOL fn_80021518(u8 group, struct SoundGroupData* data);
s32 fn_8002158C(void);
void fn_800215F8(struct SoundLoadTask* task);
void fn_80021650(s32 arg0, struct SoundGroupData* data, struct SoundLoadTask* task);
void fn_800216F8(u8 group, void* callback);
void fn_80021758(void);
void fn_80021954(struct SoundGroupData** group);
void fn_80021980(struct SoundGroupData* data);
void f_initSound(void);
void fn_80021AA0(void);
void fn_80021AC0(void);
void fn_80021AC4(void);
void fn_80021AC8(void);
void fn_80021ADC(void);
void fn_80021BBC(void);
void fn_80021CA4(void);
void fn_8002204C(void);
void fn_8002244C(void);
void fn_8002254C(void);
void fn_80022620(void);
void fn_80022634(void);
void fn_800227A0(void);
void fn_800227E4(void);
void fn_800229CC(void);
void fn_80022A24(void);
void fn_80022B14(void);
void fn_80022B68(void);
BOOL fn_80022CB4(void* file, void* dst, s32 arg2, s32 arg3, void (*callback)(void* file, void* dst, void* user), void* user);
void fn_80022D58(void);

// Defined in units not yet split
void initSound(void* config, s32 arg1, void* aram, u32 aramSize, s32 arg4, s32 arg5, void* header);
void fn_800A8F68(void);
void fn_800A648C(void);
void fn_800ACD44(void);
void fn_800ACF78(void* addr, u32 len);
void fn_800ACFB0(void* data);
void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
void fn_800B0A14_removeQueue(void);
void* ARAMTransfer(void* file, void* dst, s32 arg2, s32 arg3);
void fn_800A7568(void);
void fn_800A6304(void);
u32 sndPushGroup(void* prj_data, u16 gid, void* samples, void* sdir, void* pool);
unsigned long sndPopGroup(void);
void sndSetAuxProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void* userA, u8 midiA, SND_SEQID seqIDA,
                                  SND_AUX_CALLBACK auxB, void* userB, u8 midiB, SND_SEQID seqIDB);

#endif // !__STATIC_FN_80021188_H_
