#include "static/fn_80021188.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"
#include "string.h"
#include "musyx/musyx.h"

#define ALIGN32(x) (((x) + 0x1F) & ~0x1F)

// A sound group file once loaded: offsets that fn_80021980 turns into pointers
typedef struct SoundGroupData {
    /* 0x00 */ void* proj;
    /* 0x04 */ u32 _04;
    /* 0x08 */ void* sdir;
    /* 0x0C */ u32 _0C;
    /* 0x10 */ void* pool;
    /* 0x14 */ u32 _14;
    /* 0x18 */ void* samples;
} SoundGroupData;

typedef struct SoundBank {
    /* 0x000 */ s32 _000;
    /* 0x004 */ SoundGroupData* groups[0x30];
    /* 0x0C4 */ SND_AUX_REVERBHI reverb;
    /* 0x2A4 */ SND_AUX_CHORUS chorus;
    /* 0x340 */ u8 groupIds[0x50];
    /* 0x390 */ u8 groupCount;
    /* 0x391 */ u8 musicVolume;
    /* 0x392 */ u8 fxVolume;
    /* 0x393 */ u8 _393[0x396 - 0x393];
    /* 0x396 */ u8 outputMode;
    /* 0x397 */ u8 channelMode;
    /* 0x398 */ u8 _398;
    /* 0x399 */ u8 _399;
    /* 0x39A */ u8 _39A;
    /* 0x39B */ u8 _39B;
} SoundBank; // size: 0x39C

// An ARAM file table entry
typedef struct SoundFile {
    /* 0x00 */ u32 _00;
    /* 0x04 */ u32 size;
    /* 0x08 */ u32 aram;
    /* 0x0C */ u32 _0C;
} SoundFile;

typedef struct SoundTaskState {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 state;
    /* 0x12 */ u16 priority;
} SoundTaskState;

typedef struct SoundLoadTask {
    /* 0x00 */ s32 group;
    /* 0x04 */ void (*onLoad)(struct SoundLoadTask* task, SoundGroupData* data);
    /* 0x08 */ SoundTaskState* owner;
} SoundLoadTask;

typedef struct SoundTask {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 state;
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ void* callback;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 group;
} SoundTask;

extern SoundFile lbl_800EF508[0x30];
extern SoundFile lbl_800EFBE8[0x15];
extern SoundFile lbl_800EFD38[0x203];
extern SoundFile lbl_800F1D78[0x402];
extern SoundFile lbl_800F71D8[0x2A];
extern SoundBank lbl_800EF808;
extern u8 lbl_800EFBB4[0xC];
extern struct {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ u32 _18;
} lbl_800EFBC0;
extern struct {
    /* 0x00 */ u8 _00[0x23];
    /* 0x23 */ u8 _23;
    /* 0x24 */ u8 _24;
} gameInitOptions;
typedef void (*AramCallback)(void* file, void* dst, void* user);

typedef struct AramRequest {
    /* 0x00 */ void* file;
    /* 0x04 */ void* dst;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ AramCallback callback;
    /* 0x14 */ void* user;
} AramRequest; // size: 0x18

// The queue of ARAM transfers, also used by the model loader
typedef struct AramQueue {
    /* 0x000 */ AramRequest current;
    /* 0x018 */ AramRequest queue[18];
    /* 0x1C8 */ s8 head;
    /* 0x1C9 */ s8 tail;
    /* 0x1CA */ s8 busy;
    /* 0x1CC */ void* _1CC;
    /* 0x1D0 */ void* _1D0;
    /* 0x1D4 */ u8 _1D4[0x1D8 - 0x1D4];
    /* 0x1D8 */ s32* _1D8;
    /* 0x1DC */ s32* _1DC;
    /* 0x1E0 */ s32* _1E0;
    /* 0x1E4 */ s32* _1E4;
    /* 0x1E8 */ u8 _1E8;
    /* 0x1E9 */ u8 _1E9;
    /* 0x1EA */ u8 _1EA;
    /* 0x1EB */ u8 _1EB[0x55C - 0x1EB];
    /* 0x55C */ u32 _55C;
} AramQueue;

extern AramQueue lbl_803716B8;
extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

static inline SoundFile* SoundFileAt(s32 id) {
    return &lbl_800EFD38[id];
}

static inline BOOL AramPush(void* file, void* dst, s32 arg2, s32 arg3, AramCallback callback, void* user) {
    s8 next = (lbl_803716B8.head + 1) % 18;
    AramRequest* req;

    if (next == lbl_803716B8.tail || (dst == NULL && callback == NULL)) {
        return FALSE;
    }
    lbl_803716B8.busy = 1;
    req = &lbl_803716B8.queue[lbl_803716B8.head];
    req->file = file;
    req->dst = dst;
    req->_08 = arg2;
    req->_0C = arg3;
    req->callback = callback;
    req->user = user;
    lbl_803716B8.head = next;
    return TRUE;
}
extern SoundTaskState* lbl_803CC1B8;
extern u8 lbl_80118740[0x40000];
extern u8 lbl_80158740[0x4000];
extern u8 lbl_8015C740[0x21BE0];

u8* lbl_803CBC40;

SND_HOOKS lbl_803CB7D8 = { fn_800213F8, fn_800213F4 };

// .text:0x80022D58 size:0x54
void fn_80022D58(void) {
    lbl_803716B8.tail = 0;
    lbl_803716B8.head = 0;
    memset(&lbl_803716B8.current, 0, sizeof(AramRequest));
    memset(lbl_803716B8.queue, 0, sizeof(lbl_803716B8.queue));
}

// .text:0x80022CB4 size:0xA4
BOOL fn_80022CB4(void* file, void* dst, s32 arg2, s32 arg3, AramCallback callback, void* user) {
    s8 next = (lbl_803716B8.head + 1) % 18;
    AramRequest* req;
    // dead stores stand for code the original compiled to nothing: fn_800215F8 calls this, while AramPush is inlined
    {
        s32 d;
        d = 0;
        d = 1;
        d = 2;
        d = 3;
        d = 4;
        d = 5;
        d = 6;
        d = 7;
        d = 8;
        d = 9;
        d = 10;
        d = 11;
        d = 12;
        d = 13;
        d = 14;
        d = 15;
    }

    if (next == lbl_803716B8.tail || (dst == NULL && callback == NULL)) {
        return FALSE;
    }
    lbl_803716B8.busy = 1;
    req = &lbl_803716B8.queue[lbl_803716B8.head];
    req->file = file;
    req->dst = dst;
    req->_08 = arg2;
    req->_0C = arg3;
    req->callback = callback;
    req->user = user;
    lbl_803716B8.head = next;
    return TRUE;
}

// .text:0x80022B68 size:0x14C
BOOL fn_80022B68(void) {
    AramRequest* req;

    if (lbl_803716B8.busy == 0) {
        return TRUE;
    }
    if (lbl_803C6CF8._715 != 1) {
        return FALSE;
    }
    if (lbl_803716B8.current.callback != NULL) {
        lbl_803716B8.current.callback(lbl_803716B8.current.file, lbl_803716B8.current.dst, lbl_803716B8.current.user);
    }
    if (lbl_803716B8.tail != lbl_803716B8.head) {
        req = &lbl_803716B8.queue[lbl_803716B8.tail];
        req->dst = ARAMTransfer(req->file, req->dst, req->_08, req->_0C);
        lbl_803716B8.current = *req;
        lbl_803716B8.tail = (lbl_803716B8.tail + 1) % 18;
    } else {
        lbl_803716B8.current.callback = NULL;
        lbl_803716B8.busy = 0;
        return TRUE;
    }
    return FALSE;
}

// .text:0x80022B14 size:0x54
void fn_80022B14(void) {
    if (lbl_803C6CF8._715 == 1) {
        if (lbl_803716B8._1D0 != NULL) {
            lbl_803716B8._1CC = lbl_803716B8._1D0;
            lbl_803716B8._1D0 = NULL;
        }
        fn_800B0A14_removeQueue();
    }
}

// .text:0x80022A24 size:0xF0
BOOL fn_80022A24(s32 stadium, s32 part) {
    if (lbl_803716B8._1D0 != NULL) {
        fn_800A7568();
    } else {
        if (lbl_803C6CF8._715 != 1) {
            return FALSE;
        }
        if (lbl_803716B8._1CC != NULL) {
            lbl_803716B8._1D0 = lbl_803716B8._1CC;
        } else {
            lbl_803716B8._1D0 = fn_800A6354(0xED440);
        }
    }
    lbl_803716B8._1CC = NULL;
    ARAMTransfer(&lbl_800EFBE8[stadium * 3 + part], lbl_803716B8._1D0, 2, 0);
    fn_800B0A5C_insertQueue(fn_80022B14, lbl_803CC1B8->priority + 1);
    return TRUE;
}

// .text:0x800229CC size:0x58
void fn_800229CC(void) {
    if (lbl_803716B8._1D0 != NULL) {
        fn_800A7568();
    } else if (lbl_803716B8._1CC != NULL) {
        lbl_803716B8._1CC = NULL;
    } else {
        return;
    }
    fn_800A6304();
}

// .text:0x800227E4 size:0x1E8
void fn_800227E4(void) {
}

// .text:0x800227A0 size:0x44
void fn_800227A0(void) {
    lbl_803716B8._1E9 = 0;
    lbl_803716B8._1EA |= 1;
    lbl_803716B8._1EA |= 2;
    lbl_803716B8._1EA |= 4;
    lbl_803716B8._1EA |= 8;
}

// .text:0x80022634 size:0x16C
void fn_80022634(void) {
    if (fn_80022B68() && lbl_803716B8._1E8 == 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x80022620 size:0x14
void fn_80022620(void) {
    lbl_803716B8._1E8 = 0;
}

// .text:0x8002254C size:0xD4
void fn_8002254C(void* file, u8* data, s32 index) {
    data += *(s32*)data;
    AramPush(&lbl_800EFD38[index], data, 3, lbl_803716B8._1D8[index], (AramCallback)fn_80022620, NULL);
}

// .text:0x8002244C size:0x100
void fn_8002244C(void* file, u8* data, s32 id) {
    u32 size = ALIGN32(SoundFileAt((id >> 16) + 54)->size & 0x0FFFFFFF);

    *(u32*)(data + 0xC) = size;
    data += size;
    AramPush(SoundFileAt((u16)id + 54), data, 3, lbl_803716B8._1DC[(u16)id], (AramCallback)fn_80022620, NULL);
}

// .text:0x8002204C size:0x400
void fn_8002204C(void) {
}

// .text:0x80021CA4 size:0x3A8
void fn_80021CA4(void) {
}

// .text:0x80021BBC size:0xE8
void* fn_80021BBC(s32 index, void* dst) {
    if (index < 0 || index >= 54) {
        return NULL;
    }
    if (dst == NULL) {
        dst = _OSAllocFromHeap(0x20, SoundFileAt(index + 432)->size & 0x0FFFFFFF);
    }
    if (lbl_803716B8._1EA & 2) {
        ARAMTransfer(SoundFileAt(index + 432), dst, 3, lbl_803716B8._1E0[index]);
    } else {
        ARAMTransfer(&lbl_800F1D78[index * 19 + 15], dst, 0, 0);
    }
    return dst;
}

// .text:0x80021ADC size:0xE0
void* fn_80021ADC(s32 index, void* dst) {
    if (index < 0 || index >= 29) {
        return NULL;
    }
    if (dst == NULL) {
        dst = _OSAllocFromHeap(0x20, SoundFileAt(index + 486)->size & 0x0FFFFFFF);
    }
    if (lbl_803716B8._1EA & 8) {
        ARAMTransfer(SoundFileAt(index + 486), dst, 3, lbl_803716B8._1E4[index]);
    } else {
        ARAMTransfer(&lbl_800F71D8[index], dst, 0, 0);
    }
    return dst;
}

// .text:0x80021AC8 size:0x14
void fn_80021AC8(void) {
    lbl_803716B8._55C = 0;
}

// .text:0x80021AC4 size:0x4
void fn_80021AC4(void) {
}

// .text:0x80021AC0 size:0x4
void fn_80021AC0(void) {
}

// .text:0x80021AA0 size:0x20
void fn_80021AA0(void) {
    fn_800ACD44();
}

// .text:0x800219B4 size:0xEC
void f_initSound(void) {
    *(u32*)lbl_80158740 = 0xABF16D9C;
    lbl_80158740[0] = 'S';
    lbl_80158740[1] = 'N';
    lbl_80158740[2] = 'D';
    lbl_80158740[3] = '@';
    initSound(lbl_800EFBB4, 0, lbl_8015C740, sizeof(lbl_8015C740), 'D', 'N', lbl_80158740);
    fn_800A8F68();
    fn_800A648C();
    fn_80021228(OSGetSoundMode());
    sndVolume(lbl_800EF808.musicVolume, 0, SND_MUSIC_VOLGROUPS);
    sndVolume(lbl_800EF808.fxVolume, 0, SND_FX_VOLGROUPS);
}

// .text:0x80021980 size:0x34
void fn_80021980(SoundGroupData* data) {
    data->proj = (u8*)data->proj + (u32)data;
    data->sdir = (u8*)data->sdir + (u32)data;
    data->pool = (u8*)data->pool + (u32)data;
    data->samples = (u8*)data->samples + (u32)data;
}

// .text:0x80021954 size:0x2C
void fn_80021954(SoundGroupData** group) {
    fn_800ACF78(*group, (u8*)(*group)->samples - (u8*)*group);
}

// .text:0x80021758 size:0x1FC
void fn_80021758(void) {
}

// .text:0x800216F8 size:0x60
void fn_800216F8(u8 group, void* callback) {
    SoundTask* task = fn_800B0A5C_insertQueue(fn_80021758, 1);

    task->_18 = 0;
    task->group = group;
    task->callback = callback;
    lbl_803CC1B8->state = 0;
}

// .text:0x80021650 size:0xA8
void fn_80021650(s32 arg0, SoundGroupData* data, SoundLoadTask* task) {
    SoundGroupData** entry;

    entry = &lbl_800EF808.groups[task->group];
    *entry = data;
    fn_80021980(data);
    task->onLoad(task, data);
    fn_80021954(entry);
    task->owner->state = 1;
}

// .text:0x800215F8 size:0x58
void fn_800215F8(SoundLoadTask* task) {
    task->owner->state = 0;
    fn_80022CB4(&lbl_800EF508[task->group], NULL, 1, 0, (AramCallback)fn_80021650, task);
}

// .text:0x8002158C size:0x6C
s32 fn_8002158C(void) {
    fn_80021518(0x1E, lbl_800EF808.groups[0]);
    return 0;
}

// .text:0x80021518 size:0x74
BOOL fn_80021518(u16 group, SoundGroupData* data) {
    if (sndPushGroup(data->proj, group, data->samples, data->sdir, data->pool) == 0) {
        return FALSE;
    }
    lbl_800EF808.groupIds[lbl_800EF808.groupCount++] = group;
    return TRUE;
}

// .text:0x800214D0 size:0x48
BOOL fn_800214D0(void) {
    if (sndPopGroup() == 0) {
        return FALSE;
    }
    lbl_800EF808.groupCount--;
    return TRUE;
}

// .text:0x8002149C size:0x34
void fn_8002149C(s32 group) {
    fn_800ACFB0(lbl_800EF808.groups[group]);
}

// .text:0x80021410 size:0x8C
BOOL fn_80021410(void) {
    s8 i;

    for (i = (s8)lbl_800EF808.groupCount - 1; i > 0; i--) {
        if (!fn_800214D0()) {
            return FALSE;
        }
    }
    return TRUE;
}

// .text:0x800213F8 size:0x18
void* fn_800213F8(u32 len) {
    void* p = lbl_803CBC40;
    lbl_803CBC40 += (len + 0x1F) & ~0x1F;
    return p;
}

// .text:0x800213F4 size:0x4
void fn_800213F4(void* addr) {
}

// .text:0x80021308 size:0xEC
void fn_80021308(void) {
    SND_AUX_CHORUS* chorus;
    SND_AUX_REVERBHI* reverb;

    lbl_803CBC40 = lbl_80118740;
    sndSetHooks(&lbl_803CB7D8);
    reverb = &lbl_800EF808.reverb;
    lbl_800EF808.reverb.tempDisableFX = 0;
    lbl_800EF808.reverb.time = 2.0f;
    lbl_800EF808.reverb.preDelay = 0.1f;
    lbl_800EF808.reverb.damping = 0.5f;
    lbl_800EF808.reverb.coloration = 1.0f;
    lbl_800EF808.reverb.crosstalk = 0.0f;
    lbl_800EF808.reverb.mix = 0.8f;
    sndAuxCallbackPrepareReverbHI(reverb);
    lbl_800EF808.chorus.baseDelay = 5;
    chorus = &lbl_800EF808.chorus;
    lbl_800EF808.chorus.variation = 0;
    lbl_800EF808.chorus.period = 500;
    sndAuxCallbackPrepareChorus(chorus);
    sndSetAuxProcessingCallbacks(0, sndAuxCallbackReverbHI, reverb, 0xFF, 0, sndAuxCallbackChorus, chorus, 0xFF, 0);
}

// .text:0x8002128C size:0x7C
void fn_8002128C(u8 mode) {
    lbl_800EF808.channelMode = mode != 0 ? mode : 1;
    if (OSGetSoundMode() == 0) {
        mode = 0;
    } else if (mode != 2) {
        mode = 1;
    }
    lbl_800EF808.outputMode = mode;
    sndOutputMode(mode);
}

// .text:0x80021228 size:0x64
void fn_80021228(u8 mode) {
    lbl_800EF808.channelMode = mode != 0 ? mode : 1;
    lbl_800EF808.outputMode = mode;
    sndOutputMode(mode);
    OSSetSoundMode(lbl_800EF808.outputMode != 0);
}

// .text:0x80021204 size:0x24
void fn_80021204(void) {
    gameInitOptions._23 = lbl_800EF808._398;
    gameInitOptions._24 = lbl_800EF808.outputMode;
}

// .text:0x800211F0 size:0x14
u8 fn_800211F0(void) {
    return lbl_800EFBC0._18;
}

// .text:0x800211BC size:0x34
s32 fn_800211BC(void) {
    sndMasterVolume(0, 1, 1, 1);
    return 0;
}

// .text:0x80021188 size:0x34
s32 fn_80021188(void) {
    sndMasterVolume(0x7F, 1, 1, 1);
    return 0;
}
