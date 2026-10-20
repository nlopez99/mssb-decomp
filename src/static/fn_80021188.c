#include "static/fn_80021188.h"
#include "static/fn_80021AC8.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"
#include "string.h"
#include "musyx/musyx.h"

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
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ SoundTaskState* owner;
    /* 0x10 */ s16 state;
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ BOOL (*callback)(u8* arg);
    /* 0x18 */ u8 step;
    /* 0x19 */ u8 group;
    /* 0x1A */ u8 arg;
} SoundTask;

extern SoundFile lbl_800EF508[0x30];
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

extern SoundTaskState* lbl_803CC1B8;
extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;
extern struct {
    /* 0x000 */ u8 _000[0x366];
    /* 0x366 */ u8 _366;
} gDataDecompressorValues;
extern u8 lbl_80118740[0x40000];
extern u8 lbl_80158740[0x4000];
extern u8 lbl_8015C740[0x21BE0];

u8* lbl_803CBC40;

SND_HOOKS lbl_803CB7D8 = { fn_800213F8, fn_800213F4 };

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
    SoundTask* task = (SoundTask*)lbl_803CC1B8;

    switch (task->step) {
    case 0:
        if (task->group == 1) {
            if (lbl_800EF808._399 != 0) {
                lbl_800EF808.groups[task->group] = ARAMTransfer(&lbl_800EF508[task->group], NULL, 3, 0xB44000);
            } else {
                lbl_800EF808.groups[task->group] = ARAMTransfer(&lbl_800EF508[task->group], NULL, 1, 0);
            }
        } else {
            lbl_800EF808.groups[task->group] = ARAMTransfer(&lbl_800EF508[task->group], NULL, 1, 0);
        }
        task->step = 1;
        break;
    case 1:
        if (lbl_803C6CF8._715 != 1 || gDataDecompressorValues._366 != 0) {
            break;
        }
        fn_80021980(lbl_800EF808.groups[task->group]);
        task->step = 2;
        task->arg = 0;
    case 2:
        if (task->callback(&task->arg) == 0) {
            fn_80021954(&lbl_800EF808.groups[task->group]);
            task->owner->state = 1;
            fn_800B0A14_removeQueue();
        }
        break;
    }
}

// .text:0x800216F8 size:0x60
void fn_800216F8(u8 group, void* callback) {
    SoundTask* task = fn_800B0A5C_insertQueue(fn_80021758, 1);

    task->step = 0;
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
