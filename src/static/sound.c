#include "static/sound.h"
#include "Dolphin/ai.h"
#include "Dolphin/ar.h"
#include "Dolphin/os.h"
#include "musyx/musyx.h"

typedef struct SoundConfig {
    /* 0x00 */ u8 voices;
    /* 0x01 */ u8 music;
    /* 0x02 */ u8 sfx;
    /* 0x03 */ u8 studios;
    /* 0x04 */ u32 flags;
    /* 0x08 */ u32 aramSize;
} SoundConfig; // size: 0xC

typedef struct SoundHeap {
    /* 0x00 */ s32 free;
    /* 0x04 */ u8* cur;
    /* 0x08 */ u8* end;
} SoundHeap;

extern SoundHeap lbl_802FE8A0;

SoundConfig lbl_801112F0 = { 64, 48, 16, 1, 0, 0x800000 };

SoundHeap* lbl_803CBB10 = &lbl_802FE8A0;

// .text:0x800B099C size:0x78
void* SndAlloc(u32 size) {
    u8* cur;
    u8* p;
    u32 total;
    u8* next;
    s32 remain;

    size = (size + 3) & ~3;
    cur = lbl_803CBB10->cur;
    p = (u8*)(((u32)cur + 8 + 31) & ~31);
    total = (p - cur) + size;
    next = size + p;
    remain = lbl_803CBB10->end - next;
    if (remain < 0) {
        OSReport("sNp_SndAlloc:: no enough space:%d\n", remain);
        while (TRUE) {
        }
    }
    ((u8**)p)[-2] = cur;
    ((u32*)p)[-1] = total;
    lbl_803CBB10->free = remain;
    lbl_803CBB10->cur = next;
    return p;
}

// .text:0x800B0938 size:0x64
void SndFree(void* addr) {
    u8* base = ((u8**)addr)[-2];

    if (base + ((u32*)addr)[-1] != lbl_803CBB10->cur) {
        OSReport("sNp_SndFree err\n");
        while (TRUE) {
        }
    }
    lbl_803CBB10->cur = base;
    lbl_803CBB10->free = lbl_803CBB10->end - lbl_803CBB10->cur;
}

// .text:0x800B0934 size:0x4
void fn_800B0934(void* addr) {
}

// .text:0x800B0834 size:0x100
void initSound(SoundConfig* config, u8* aiStack, u8* heap, u32 heapSize, u8 arg4, u8 arg5, void* arg6) {
    SND_HOOKS hooks = { SndAlloc, SndFree };
    u8* end;

    AIInit(aiStack);
    ARInit(NULL, 0);
    ARQInit();
    if (config == NULL) {
        config = &lbl_801112F0;
    }
    end = heap + heapSize;
    lbl_803CBB10->cur = heap;
    lbl_803CBB10->end = end;
    lbl_803CBB10->free = end - heap;
    sndSetHooks(&hooks);
    if (sndInit(config->voices, config->music, config->sfx, config->studios, config->flags, config->aramSize) != 0) {
        OSPanic("sound.c", 278, "gYd_MusyXInit()::Failed to sndInit().");
    }
    if (OSGetSoundMode() == OS_SOUND_MODE_MONO) {
        sndOutputMode(SND_OUTPUTMODE_MONO);
    } else {
        sndOutputMode(SND_OUTPUTMODE_STEREO);
    }
}

// .text:0x800B07FC size:0x38
void soundQuit(void) {
    SND_HOOKS hooks = { SndAlloc, fn_800B0934 };

    sndSetHooks(&hooks);
    sndQuit();
}
