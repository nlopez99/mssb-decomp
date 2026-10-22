#ifndef __STATIC_SOUND_H_
#define __STATIC_SOUND_H_

#include "mssbTypes.h"

struct SoundConfig;

void soundQuit(void);
void initSound(struct SoundConfig* config, u8* aiStack, u8* heap, u32 heapSize);
void fn_800B0934(void* addr);
void SndFree(void* addr);
void* SndAlloc(u32 size);

#endif // !__STATIC_SOUND_H_
