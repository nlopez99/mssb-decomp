#include "static/fn_80021AC8.h"
#include "static/fn_80021188.h"
#include "Dolphin/os.h"
#include "string.h"

#define ALIGN32(x) (((x) + 0x1F) & ~0x1F)

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
    /* 0x1D4 */ s32 aramBase;
    union {
        /* 0x1D8 */ s32* aramTables[4];
        struct {
            /* 0x1D8 */ s32* _1D8;
            /* 0x1DC */ s32* _1DC;
            /* 0x1E0 */ s32* _1E0;
            /* 0x1E4 */ s32* _1E4;
        };
    };
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

typedef struct AramTaskState {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u16 priority;
} AramTaskState;

extern SoundFile lbl_800EFBE8[0x15];
extern SoundFile lbl_800EFD38[0x203];
extern u8 lbl_800F1D68[0x10];
extern SoundFile lbl_800F1D78[0x402];
extern SoundFile lbl_800F71D8[0x2A];
extern AramTaskState* lbl_803CC1B8;
extern s32 lbl_8017E320[0x208];

u16 lbl_803CB7E0[4] = { 0x36, 0x17A, 0x36, 0x1D };

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
    s32 i;
    s32 j;
    s32* buf;
    SoundFile* file;

    lbl_803716B8.aramBase = fn_800A6418(0x4D6600);
    buf = lbl_8017E320;
    file = lbl_800EFD38;
    lbl_803716B8._1E9 = 1;
    for (i = 0; i < 4; i++) {
        lbl_803716B8.aramTables[i] = buf;
        buf += lbl_803CB7E0[i];
        for (j = 0; j < lbl_803CB7E0[i]; j++) {
            lbl_803716B8.aramTables[i][j] = lbl_803716B8.aramBase + file->aram;
            file++;
        }
    }
    AramPush(lbl_800F1D68, (void*)lbl_803716B8.aramBase, 2, 0, (AramCallback)fn_800227A0, NULL);
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

