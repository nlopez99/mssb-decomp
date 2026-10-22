#include "static/static_800A8518.h"
#include "static/dvdsys.h"
#include "Dolphin/os.h"
#include "Dolphin/dvd.h"
#include "Dolphin/ai.h"

extern BOOL DVDPrepareStreamAsync(DVDFileInfo* fileInfo, u32 length, u32 offset, DVDCallback callback);
extern BOOL DVDStopStreamAtEndAsync(DVDCommandBlock* block, DVDCBCallback callback);
extern BOOL DVDGetStreamPlayAddrAsync(DVDCommandBlock* block, DVDCBCallback callback);
extern BOOL DVDGetStreamErrorStatusAsync(DVDCommandBlock* block, DVDCBCallback callback);

extern struct {
    /* 0x000 */ u8 _000[0x718];
    /* 0x718 */ s32 entryNum;
} lbl_803C6CF8;

extern DVDCommandBlock lbl_802EF140;
extern DVDCommandBlock lbl_802EF170;
extern DVDCommandBlock lbl_802EF1A0;
extern DVDCommandBlock lbl_802EF1D0;
extern DVDCommandBlock lbl_802EF200;
extern DVDCommandBlock lbl_802EF230;
extern DVDCommandBlock lbl_802EF260;
extern DVDCommandBlock lbl_802EF290;

StreamEntry* lbl_803CC154;
StreamEntry* lbl_803CC150;
StreamEntry* lbl_803CC14C;
volatile u32 lbl_803CC148;
volatile u32 lbl_803CC144;
volatile u32 lbl_803CC140;
volatile s32 lbl_803CC13C;
volatile u32 lbl_803CC138;
volatile u8 lbl_803CC135;
volatile u8 lbl_803CC134;
u32 lbl_803CC130;
volatile u32 lbl_803CC12C;
void (*lbl_803CC128)(void);

static inline void Notify(StreamEntry* entry, u32 mask) {
    if (entry != NULL && entry->callback != NULL && (entry->flags & mask)) {
        entry->callback(entry->flags & mask);
    }
}

static inline void PrepareCurrent(void) {
    AISetStreamVolLeft(0);
    AISetStreamVolRight(0);
    AISetStreamPlayState(0);
    DVDPrepareStreamAsync(&lbl_803CC154->fileInfo, 0, 0, fn_800A9424);
}

static inline void CloseAll(void) {
    StreamEntry* entry;

    AISetStreamPlayState(0);
    for (entry = lbl_803CC150; entry != NULL; entry = entry->next) {
        DVDClose(&entry->fileInfo);
    }
    lbl_803CC150 = NULL;
    lbl_803CC14C = NULL;
    lbl_803CC154 = NULL;
    lbl_803CC148 = 0;
    if (lbl_803CC128 != NULL) {
        lbl_803CC128();
        lbl_803CC128 = NULL;
    }
    lbl_803CC148 = 0;
    lbl_803CC130 = 0;
}

// .text:0x800A94A8 size:0x1C
void fn_800A94A8(s32 result, DVDCommandBlock* block) {
    if ((u8)result == 0) {
        lbl_803CC12C = 1;
        lbl_803CC13C = 0;
    }
}

// .text:0x800A9424 size:0x84
void fn_800A9424(s32 result, DVDFileInfo* fileInfo) {
    AISetStreamVolLeft(lbl_803CC135);
    AISetStreamVolRight(lbl_803CC134);
    AIResetStreamSampleCount();
    AISetStreamTrigger(lbl_803CC138);
    AISetStreamPlayState(1);
    DVDStopStreamAtEndAsync(&lbl_802EF290, NULL);
    lbl_803CC148 = 1;
    Notify(lbl_803CC154, 1);
}

// .text:0x800A93AC size:0x78
void fn_800A93AC(s32 result, DVDFileInfo* fileInfo) {
    AISetStreamVolLeft(0);
    AISetStreamVolRight(0);
    AISetStreamPlayState(0);
    DVDStopStreamAtEndAsync(&lbl_802EF260, NULL);
    lbl_803CC148 = 2;
    Notify(lbl_803CC154, 0x20);
}

// .text:0x800A91B0 size:0x1FC
void fn_800A91B0(s32 result, DVDCommandBlock* block) {
    lbl_803CC13C = result;
    if (lbl_803CC12C) {
        lbl_803CC12C = 0;
        Notify(lbl_803CC154, 0x10);
        lbl_803CC148 = 3;
        switch (lbl_803CC140) {
        case 0:
            if (lbl_803CC154 != NULL) {
                if (lbl_803CC154->next != NULL) {
                    lbl_803CC154 = lbl_803CC154->next;
                    PrepareCurrent();
                } else {
                    lbl_803CC154 = lbl_803CC150;
                    AISetStreamVolLeft(0);
                    AISetStreamVolRight(0);
                    AISetStreamPlayState(0);
                    lbl_803CC148 = 0;
                }
            }
            break;
        case 1:
            if (lbl_803CC154 != NULL) {
                if (lbl_803CC154->next != NULL) {
                    lbl_803CC154 = lbl_803CC154->next;
                    PrepareCurrent();
                } else {
                    lbl_803CC154 = lbl_803CC150;
                    PrepareCurrent();
                }
            }
            break;
        case 2:
            if (lbl_803CC154 != NULL) {
                PrepareCurrent();
            }
            break;
        }
    } else {
        DVDGetStreamErrorStatusAsync(&lbl_802EF230, fn_800A94A8);
    }
}

// .text:0x800A9168 size:0x48
void fn_800A9168(u32 count) {
    AISetStreamTrigger(count + lbl_803CC138);
    if (lbl_803CC154 != NULL) {
        DVDGetStreamPlayAddrAsync(&lbl_802EF200, fn_800A91B0);
    }
}

// .text:0x800A90E4 size:0x84
void fn_800A90E4(s32 result, DVDCommandBlock* block) {
    CloseAll();
}

// .text:0x800A908C size:0x58
void fn_800A908C(s32 result, DVDCommandBlock* block) {
    AISetStreamPlayState(0);
    Notify(lbl_803CC154, 2);
    lbl_803CC148 = 0;
}

static inline void AdvanceNext(void) {
    BOOL enabled = OSDisableInterrupts();
    if (lbl_803CC154 != NULL && lbl_803CC154->next != NULL) {
        lbl_803CC154 = lbl_803CC154->next;
    }
    OSRestoreInterrupts(enabled);
}

static inline void AdvancePrev(void) {
    BOOL enabled = OSDisableInterrupts();
    if (lbl_803CC154 != NULL && lbl_803CC154->prev != NULL) {
        lbl_803CC154 = lbl_803CC154->prev;
    }
    OSRestoreInterrupts(enabled);
}

// .text:0x800A9034 size:0x58
void fn_800A9034(s32 result, DVDCommandBlock* block) {
    AISetStreamPlayState(0);
    AdvanceNext();
    lbl_803CC148 = 0;
    fn_800A88D8(lbl_803CC144);
}

// .text:0x800A8FDC size:0x58
void fn_800A8FDC(s32 result, DVDCommandBlock* block) {
    AISetStreamPlayState(0);
    AdvancePrev();
    lbl_803CC148 = 0;
    fn_800A88D8(lbl_803CC144);
}

// .text:0x800A8F68 size:0x74
void fn_800A8F68(void) {
    lbl_803CC148 = 0;
    lbl_803CC140 = 0;
    lbl_803CC13C = 0;
    lbl_803CC138 = 12000;
    lbl_803CC135 = 0xFF;
    lbl_803CC154 = NULL;
    lbl_803CC150 = NULL;
    lbl_803CC14C = NULL;
    lbl_803CC134 = 0xFF;
    AISetStreamVolLeft(0);
    AISetStreamVolRight(0);
    AIRegisterStreamCallback(fn_800A9168);
    AIResetStreamSampleCount();
    AISetStreamPlayState(0);
}

// .text:0x800A8E30 size:0x138
s32 fn_800A8E30(char** path, StreamEntry* entry, u32 flags, void (*callback)(u32 event)) {
    BOOL start = FALSE;
    s32 savedEntryNum;
    BOOL enabled;

    savedEntryNum = lbl_803C6CF8.entryNum;
    lbl_803C6CF8.entryNum = ConvertPathToEntryNum(path);
    if (fn_800A750C(path, &entry->fileInfo) == 0) {
        return 1;
    }
    lbl_803C6CF8.entryNum = savedEntryNum;
    enabled = OSDisableInterrupts();
    entry->path = path;
    entry->flags = flags;
    entry->callback = callback;
    if (lbl_803CC150 == NULL) {
        lbl_803CC150 = entry;
        lbl_803CC14C = entry;
        entry->prev = NULL;
        entry->next = NULL;
        if (lbl_803CC148 == 1) {
            start = TRUE;
        }
    } else {
        lbl_803CC14C->next = entry;
        entry->prev = lbl_803CC14C;
        lbl_803CC154 = entry;
        entry->next = NULL;
    }
    if (lbl_803CC154 == NULL) {
        lbl_803CC154 = entry;
    }
    OSRestoreInterrupts(enabled);
    Notify(entry, 8);
    if (start) {
        lbl_803CC148 = 3;
        DVDPrepareStreamAsync(&lbl_803CC154->fileInfo, 0, 0, fn_800A9424);
    }
    return 0;
}

// .text:0x800A8CBC size:0x174
s32 LoadFile(char** path, StreamEntry* entry, u32 flags, void (*callback)(u32 event), s32 unique) {
    StreamEntry* it;

    if ((unique & 1) && lbl_803CC150 != NULL) {
        for (it = lbl_803CC150; it != NULL; it = it->next) {
            if (it == entry) {
                return 0x100;
            }
        }
    }
    return fn_800A8E30(path, entry, flags, callback);
}

// .text:0x800A8B78 size:0x144
s32 fn_800A8B78(StreamEntry* entry) {
    BOOL enabled;

    if (entry == lbl_803CC154) {
        return 2;
    }
    enabled = OSDisableInterrupts();
    DVDClose(&entry->fileInfo);
    if (entry == lbl_803CC150 && entry == lbl_803CC14C) {
        lbl_803CC150 = NULL;
        lbl_803CC14C = NULL;
        OSRestoreInterrupts(enabled);
        return 0;
    }
    if (entry == lbl_803CC150) {
        lbl_803CC150 = entry->next;
        lbl_803CC150->prev = NULL;
        if (lbl_803CC140 == 1) {
            lbl_803CC14C->next = lbl_803CC150;
        }
        OSRestoreInterrupts(enabled);
        return 0;
    }
    if (entry == lbl_803CC14C) {
        lbl_803CC14C = entry->prev;
        lbl_803CC14C->next = NULL;
        if (lbl_803CC140 == 1) {
            lbl_803CC14C->next = lbl_803CC150;
        }
        OSRestoreInterrupts(enabled);
        return 0;
    }
    if (entry->prev != NULL && entry->next != NULL) {
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

// .text:0x800A8AB8 size:0xC0
void fn_800A8AB8(void (*callback)(void)) {
    u32 state;

    if (lbl_803CC148 != 3) {
        state = lbl_803CC148;
        lbl_803CC128 = callback;
        lbl_803CC148 = 3;
        if (state == 1) {
            DVDCancelStreamAsync(&lbl_802EF1D0, fn_800A90E4);
        } else {
            CloseAll();
        }
    }
}

// .text:0x800A8AB0 size:0x8
void fn_800A8AB0(u32 mode) {
    lbl_803CC140 = mode;
}

// .text:0x800A88D8 size:0x1D8
void fn_800A88D8(s32 cmd) {
    if (lbl_803CC148 == cmd || lbl_803CC148 == 3) {
        return;
    }
    switch (cmd) {
    case 0:
        if (lbl_803CC154 != NULL) {
            lbl_803CC148 = 3;
            AISetStreamVolLeft(0);
            AISetStreamVolRight(0);
            DVDCancelStreamAsync(&lbl_802EF1A0, fn_800A908C);
        }
        break;
    case 1:
        if (lbl_803CC148 == 2) {
            AISetStreamVolLeft(lbl_803CC135);
            AISetStreamVolRight(lbl_803CC134);
            AIResetStreamSampleCount();
            AISetStreamTrigger(lbl_803CC138);
            AISetStreamPlayState(1);
            lbl_803CC148 = 1;
            if (lbl_803CC154 != NULL) {
                Notify(lbl_803CC154, 1);
            }
        } else if (lbl_803CC154 != NULL) {
            lbl_803CC148 = 3;
            DVDPrepareStreamAsync(&lbl_803CC154->fileInfo, 0, 0, fn_800A9424);
        } else {
            lbl_803CC148 = 1;
        }
        lbl_803CC12C = 0;
        break;
    case 4:
        if (lbl_803CC148 == 0) {
            if (lbl_803CC154 != NULL) {
                lbl_803CC148 = 3;
                DVDPrepareStreamAsync(&lbl_803CC154->fileInfo, 0, 0, fn_800A93AC);
            }
            lbl_803CC12C = 0;
        }
        break;
    case 2:
        AISetStreamPlayState(0);
        if (lbl_803CC148 == 1) {
            lbl_803CC148 = 2;
        }
        Notify(lbl_803CC154, 4);
        break;
    }
}

// .text:0x800A88D0 size:0x8
u32 fn_800A88D0(void) {
    return lbl_803CC140;
}

// .text:0x800A88C8 size:0x8
s32 fn_800A88C8(void) {
    return lbl_803CC148;
}

// .text:0x800A88C0 size:0x8
StreamEntry* fn_800A88C0(void) {
    return lbl_803CC154;
}

// .text:0x800A8878 size:0x48
void fn_800A8878(u8 left, u8 right) {
    lbl_803CC135 = left;
    lbl_803CC134 = right;
    if (lbl_803CC148 == 1) {
        AISetStreamVolLeft(left);
        AISetStreamVolRight(right);
    }
}

// .text:0x800A8864 size:0x14
u16 fn_800A8864(void) {
    return (lbl_803CC135 << 8) | lbl_803CC134;
}

static inline BOOL StreamCommand(s32 cmd) {
    s32 state;

    if (lbl_803CC154 != NULL) {
        if (lbl_803CC148 == 3) {
            return FALSE;
        }
        switch (cmd) {
        case 1:
            fn_800A88D8(1);
            break;
        case 2:
            fn_800A88D8(2);
            break;
        case 3:
            fn_800A88D8(0);
            break;
        case 4:
            if (lbl_803CC148 != 3 && lbl_803CC154 != NULL) {
                lbl_803CC144 = lbl_803CC148;
                lbl_803CC148 = 3;
                if (lbl_803CC144 == 1) {
                    AISetStreamVolLeft(0);
                    AISetStreamVolRight(0);
                    DVDCancelStreamAsync(&lbl_802EF170, fn_800A9034);
                } else {
                    AdvanceNext();
                    lbl_803CC148 = lbl_803CC144;
                }
            }
            break;
        case 5:
            if (lbl_803CC148 != 3 && lbl_803CC154 != NULL) {
                lbl_803CC144 = lbl_803CC148;
                lbl_803CC148 = 3;
                if (lbl_803CC144 == 1) {
                    AISetStreamVolLeft(0);
                    AISetStreamVolRight(0);
                    DVDCancelStreamAsync(&lbl_802EF140, fn_800A8FDC);
                } else {
                    AdvancePrev();
                    lbl_803CC148 = lbl_803CC144;
                }
            }
            break;
        }
    }
    return TRUE;
}

// .text:0x800A86B4 size:0x1B0
void fn_800A86B4(s32 cmd) {
    while (!StreamCommand(cmd)) {
    }
}

// .text:0x800A8518 size:0x19C
BOOL fn_800A8518(s32 cmd) {
    return StreamCommand(cmd);
}
