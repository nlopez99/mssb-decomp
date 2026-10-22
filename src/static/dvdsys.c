#include "static/dvdsys.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"
#include "Dolphin/dvd.h"
#include "Dolphin/ar.h"

typedef struct DataVars {
    /* 0x000 */ OSThread t;
    /* 0x318 */ u8 _318[0x320 - 0x318];
    /* 0x320 */ OSSemaphore s[2];
    /* 0x338 */ u8 _338[0x33C - 0x338];
    /* 0x33C */ u32 CachedBytesToRead;
    /* 0x340 */ u8 _340[0x354 - 0x340];
    /* 0x354 */ u8* DataReadTop;
    /* 0x358 */ u8 _358[0x35C - 0x358];
    /* 0x35C */ void* _35C;
    /* 0x360 */ s8 segmentCount;
    /* 0x361 */ u8 _361[0x364 - 0x361];
    /* 0x364 */ s8 error;
    /* 0x365 */ s8 compressedFlag;
    /* 0x366 */ u8 ShouldWriteDataFlag;
} DataVars;

extern DataVars gDataDecompressorValues;

typedef struct DvdSys {
    /* 0x000 */ OSThread thread;
    /* 0x318 */ OSThread readThread;
    /* 0x630 */ OSSemaphore aramSem;
    /* 0x63C */ ARQRequest aramReq[4];
    /* 0x6BC */ u8* aramBufEnd;
    /* 0x6C0 */ u32 aramAddr;
    /* 0x6C4 */ u32 aramBase;
    /* 0x6C8 */ u8 aramReqIndex;
    /* 0x6CC */ void (**driveCallbacks)(void);
    /* 0x6D0 */ u32 timeoutReset;
    /* 0x6D4 */ u32 timeout;
    /* 0x6D8 */ u8 timeoutOn;
    /* 0x6DC */ DVDFileInfo* fileInfo;
    /* 0x6E0 */ u32 diskSize;
    /* 0x6E4 */ u32 diskOffset;
    /* 0x6E8 */ u32 readOffset;
    /* 0x6EC */ u32 readSize;
    /* 0x6F0 */ s32 remaining;
    /* 0x6F4 */ s32 chunk;
    /* 0x6F8 */ u8* bufStart;
    /* 0x6FC */ void* tempBuf;
    /* 0x700 */ u8* bufEnd;
    /* 0x704 */ u8* writePtr;
    /* 0x708 */ u8* readPtr;
    /* 0x70C */ s32 streamSize;
    /* 0x710 */ s32 streamDone;
    /* 0x714 */ volatile union {
        u16 status;
        u8 flags[2];
    } u;
    /* 0x716 */ u8 _716;
    /* 0x717 */ u8 mode;
    /* 0x718 */ s32 entryNum;
    /* 0x71C */ AssetLoadInstructions* instr;
    /* 0x720 */ s16 _720;
    /* 0x722 */ u8 driveStatus;
    /* 0x723 */ u8 streamEnd;
} DvdSys;

typedef struct DvdSysStacks {
    /* 0x0000 */ u8 readStack[0x1000];
    /* 0x1000 */ u8 stack[0x1000];
    /* 0x2000 */ DVDFileInfo fileInfo;
} DvdSysStacks;

extern DvdSys lbl_803C6CF8;
extern struct {
    /* 0x00 */ u8 _00[0x5C];
    /* 0x5C */ OSThreadQueue retraceQueue;
} lbl_803C7420;
extern DvdSysStacks lbl_802EAF80;

extern void* _OSAllocFromHeap(s32 heap, u32 size);
extern void fn_800ACF14(void* ptr);
extern void* fn_800ACF34(s32 heap, u32 size);
extern void StartThreadForReadingFromDisk(void);

void (*lbl_8010F420[16])(void) = {
    fn_800A7AD4, fn_800A7AD4, fn_800A7AD4, fn_800A7AD4, fn_800A7AD4, fn_800A7AD4, fn_800A7AD4,
    fn_800A7AD4, fn_800A7AD4, fn_800A7AD4, fn_800A7AD4, fn_800A7AD4, fn_800A7AD4,
};
// .text:0x800A7AD4 size:0x4
void fn_800A7AD4(void) {
}

// .text:0x800A7A80 size:0x54
void fn_800A7A80(s32 result, DVDFileInfo* fileInfo) {
    if (result == -3) {
        lbl_803C6CF8.remaining = 0;
        lbl_803C6CF8.chunk = 0;
    } else if (result != -1) {
        OSResumeThread(&lbl_803C6CF8.readThread);
    }
}

// .text:0x800A77A0 size:0x2E0
void fn_800A77A0(void) {
    s32 done;
    u8* prev;
    s32 chunk;

    while (TRUE) {
        OSSuspendThread(&lbl_803C6CF8.readThread);
        lbl_803C6CF8.remaining -= lbl_803C6CF8.chunk;
        prev = lbl_803C6CF8.readPtr;
        lbl_803C6CF8.readPtr = prev + lbl_803C6CF8.chunk;
        done = lbl_803C6CF8.readSize - lbl_803C6CF8.remaining;
        switch (lbl_803C6CF8.mode) {
        case 0:
        case 3:
            gDataDecompressorValues.segmentCount++;
            if (lbl_803C6CF8.readPtr == gDataDecompressorValues.DataReadTop) {
                lbl_803C6CF8.readPtr = lbl_803C6CF8.bufStart;
            }
            if (OSIsThreadSuspended(&gDataDecompressorValues.t) == 1) {
                OSResumeThread(&gDataDecompressorValues.t);
            }
            break;
        case 2:
            DCFlushRange(prev, (lbl_803C6CF8.chunk + 0x1F) & ~0x1F);
            ARQPostRequest(&lbl_803C6CF8.aramReq[lbl_803C6CF8.aramReqIndex], 2000, ARQ_TYPE_MRAM_TO_ARAM, ARQ_PRIORITY_LOW, (u32)prev,
                           lbl_803C6CF8.aramAddr, (lbl_803C6CF8.chunk + 0x1F) & ~0x1F, (ARQCallback)fn_800A6890);
            if (lbl_803C6CF8.readPtr == lbl_803C6CF8.aramBufEnd) {
                lbl_803C6CF8.readPtr = lbl_803C6CF8.bufStart;
            }
            lbl_803C6CF8.aramReqIndex = (lbl_803C6CF8.aramReqIndex + 1) % 4;
            lbl_803C6CF8.aramAddr += (lbl_803C6CF8.chunk + 0x1F) & ~0x1F;
            break;
        }
        if (lbl_803C6CF8.remaining == 0) {
            if (lbl_803C6CF8.mode == 1 || lbl_803C6CF8.mode == 4) {
                lbl_803C6CF8.u.status = 1;
            }
            DVDClose(lbl_803C6CF8.fileInfo);
            continue;
        }
        chunk = lbl_803C6CF8.remaining >= 0x8000 ? 0x8000 : lbl_803C6CF8.remaining;
        switch (lbl_803C6CF8.mode) {
        case 0:
            OSWaitSemaphore(&gDataDecompressorValues.s[0]);
        case 1:
            lbl_803C6CF8.chunk = chunk;
            DVDReadAsyncPrio(lbl_803C6CF8.fileInfo, lbl_803C6CF8.readPtr, chunk, lbl_803C6CF8.diskOffset + done, fn_800A7A80, 2);
            break;
        case 2:
            OSWaitSemaphore(&lbl_803C6CF8.aramSem);
            lbl_803C6CF8.chunk = chunk;
            DVDReadAsyncPrio(lbl_803C6CF8.fileInfo, lbl_803C6CF8.readPtr, chunk, lbl_803C6CF8.diskOffset + done, fn_800A7A80, 2);
            break;
        case 3:
            OSWaitSemaphore(&gDataDecompressorValues.s[0]);
            lbl_803C6CF8.chunk = chunk;
            DCInvalidateRange(lbl_803C6CF8.readPtr, chunk);
            ARQPostRequest(&lbl_803C6CF8.aramReq[lbl_803C6CF8.aramReqIndex], 2000, ARQ_TYPE_ARAM_TO_MRAM, ARQ_PRIORITY_LOW,
                           lbl_803C6CF8.aramAddr, (u32)lbl_803C6CF8.readPtr, (lbl_803C6CF8.chunk + 0x1F) & ~0x1F,
                           (ARQCallback)fn_800A68D4);
            lbl_803C6CF8.aramReqIndex = (lbl_803C6CF8.aramReqIndex + 1) % 4;
            lbl_803C6CF8.aramAddr += (lbl_803C6CF8.chunk + 0x1F) & ~0x1F;
            break;
        }
    }
}

// .text:0x800A76BC size:0xE4
// The target reaches the stacks and file info from this unit's .bss pool base (0x802EAF80); with them as
// statics it matches, but that .bss cannot be split yet (link-order cycle with Unknown/ .bss), so extern.
void fn_800A76BC(void) {
    DVDInit();
    lbl_803C6CF8.u.status = 1;
    gDataDecompressorValues._35C = NULL;
    lbl_803C6CF8.tempBuf = NULL;
    lbl_803C6CF8.fileInfo = &lbl_802EAF80.fileInfo;
    lbl_803C6CF8.driveCallbacks = lbl_8010F420;
    OSCreateThread(&lbl_803C6CF8.thread, (void* (*)(void*))fn_800A6900, NULL, lbl_802EAF80.stack + 0x1000, 0x1000, 14, OS_THREAD_ATTR_DETACH);
    OSResumeThread(&lbl_803C6CF8.thread);
    OSCreateThread(&lbl_803C6CF8.readThread, (void* (*)(void*))fn_800A77A0, NULL, lbl_802EAF80.readStack + 0x1000, 0x1000, 8,
                   OS_THREAD_ATTR_DETACH);
    OSResumeThread(&lbl_803C6CF8.readThread);
    lbl_803C6CF8.timeoutOn = 0;
}

// .text:0x800A7670 size:0x4C
void fn_800A7670(s32 result, DVDCommandBlock* block) {
    lbl_803C6CF8.u.status = 1;
    if (lbl_803C6CF8.tempBuf != NULL) {
        fn_800ACF14(lbl_803C6CF8.tempBuf);
        lbl_803C6CF8.tempBuf = NULL;
    }
}

// .text:0x800A75EC size:0x84
void fn_800A75EC(s32 result, DVDCommandBlock* block) {
    OSCancelThread(&gDataDecompressorValues.t);
    StartThreadForReadingFromDisk();
    lbl_803C6CF8.u.status = 1;
    if (gDataDecompressorValues._35C != NULL) {
        fn_800ACF14(gDataDecompressorValues._35C);
        gDataDecompressorValues._35C = NULL;
    }
    if (lbl_803C6CF8.tempBuf != NULL) {
        fn_800ACF14(lbl_803C6CF8.tempBuf);
        lbl_803C6CF8.tempBuf = NULL;
    }
}

// .text:0x800A7568 size:0x84
void fn_800A7568(void) {
    DVDCBCallback callback;

    lbl_803C6CF8.u.flags[0] = 0;
    lbl_803C6CF8.driveStatus = 0;
    if ((s32)lbl_803C6CF8.u.flags[1] != 1) {
        if (lbl_803C6CF8.mode == 0 || lbl_803C6CF8.mode == 3) {
            callback = fn_800A75EC;
        } else {
            callback = fn_800A7670;
        }
        DVDCancelAsync(&lbl_803C6CF8.fileInfo->cBlock, callback);
        ARQRemoveOwnerRequest(2000);
    }
}

// .text:0x800A7544 size:0x24
s32 ConvertPathToEntryNum(char** path) {
    return DVDConvertPathToEntrynum(*path);
}

// .text:0x800A750C size:0x38
BOOL fn_800A750C(char** path, DVDFileInfo* fileInfo) {
    return DVDFastOpen(lbl_803C6CF8.entryNum, fileInfo) != 0;
}

// .text:0x800A70DC size:0x430
void* ARAMTransfer(AssetLoadInstructions* instr, void* dst, u8 mode, u32 aram) {
    void* result;
    s32 size;
    s32 chunk;

    fn_800A7568();
    lbl_803C6CF8._720 = instr->compressionConstants;
    lbl_803C6CF8.readOffset = 0;
    lbl_803C6CF8.chunk = 0;
    lbl_803C6CF8.diskOffset = instr->diskLocation;
    lbl_803C6CF8.diskSize = ((u32*)instr)[1];
    gDataDecompressorValues.compressedFlag = instr->compressionFlag;
    lbl_803C6CF8.instr = instr;
    lbl_803C6CF8.mode = mode;
    while ((s32)lbl_803C6CF8.u.flags[1] != 1) {
    }
    DVDFastOpen(lbl_803C6CF8.entryNum, lbl_803C6CF8.fileInfo);
    size = (instr->compressedSize + 0x1F) & ~0x1F;
    if (dst == NULL) {
        if (lbl_803C6CF8.mode == 0 || lbl_803C6CF8.mode == 3) {
            dst = _OSAllocFromHeap(0x20, ((lbl_803C6CF8.diskSize & 0x0FFFFFFF) + 0x1F) & ~0x1F);
        } else if (lbl_803C6CF8.mode == 2) {
            OSPanic("dvdsys.c", 554, "ARAM直接転送の場合は読込先アドレスが必須です。\n");
        } else {
            dst = _OSAllocFromHeap(0x20, size);
        }
    }
    if (aram == 0) {
        if (lbl_803C6CF8.mode == 3) {
            OSPanic("dvdsys.c", 564, "ARAM->RAM転送の場合はARAMアドレスが必須です。\n");
        }
        if (lbl_803C6CF8.mode == 4) {
            OSPanic("dvdsys.c", 568, "ARAM->RAM転送の場合はARAMアドレスが必須です。\n");
        }
    }
    lbl_803C6CF8.readSize = size;
    lbl_803C6CF8.remaining = size;
    chunk = lbl_803C6CF8.remaining >= 0x8000 ? 0x8000 : lbl_803C6CF8.remaining;
    result = dst;
    lbl_803C6CF8.chunk = chunk;
    if (lbl_803C6CF8.mode == 0) {
        lbl_803C6CF8.bufEnd = dst;
        dst = lbl_803C6CF8.tempBuf = fn_800ACF34(0x20, 0x20000);
        SetReadParameters(instr, lbl_803C6CF8.tempBuf, lbl_803C6CF8.bufEnd, 1);
    } else if (lbl_803C6CF8.mode == 2) {
        OSInitSemaphore(&lbl_803C6CF8.aramSem, 3);
        lbl_803C6CF8.aramBase = (u32)dst;
        lbl_803C6CF8.aramAddr = (u32)dst;
        dst = lbl_803C6CF8.tempBuf = fn_800ACF34(0x20, 0x20000);
        lbl_803C6CF8.aramBufEnd = (u8*)lbl_803C6CF8.tempBuf + 0x20000;
        lbl_803C6CF8.aramReqIndex = 0;
    } else if (lbl_803C6CF8.mode == 3) {
        lbl_803C6CF8.aramBase = aram;
        lbl_803C6CF8.aramAddr = aram;
        lbl_803C6CF8.bufEnd = dst;
        dst = lbl_803C6CF8.tempBuf = fn_800ACF34(0x20, 0x20000);
        lbl_803C6CF8.aramReqIndex = 0;
        SetReadParameters(instr, lbl_803C6CF8.tempBuf, lbl_803C6CF8.bufEnd, 2);
    } else if (lbl_803C6CF8.mode == 4) {
        lbl_803C6CF8.aramBase = aram;
        lbl_803C6CF8.aramAddr = aram;
        lbl_803C6CF8.bufEnd = dst;
        lbl_803C6CF8.chunk = lbl_803C6CF8.remaining;
    }
    lbl_803C6CF8.bufStart = dst;
    lbl_803C6CF8.readPtr = dst;
    lbl_803C6CF8.u.status = 0x200;
    if (lbl_803C6CF8.mode == 3 || lbl_803C6CF8.mode == 4) {
        DCInvalidateRange(lbl_803C6CF8.readPtr, lbl_803C6CF8.chunk);
        ARQPostRequest(&lbl_803C6CF8.aramReq[lbl_803C6CF8.aramReqIndex], 2000, ARQ_TYPE_ARAM_TO_MRAM, ARQ_PRIORITY_LOW,
                       lbl_803C6CF8.aramAddr, (u32)lbl_803C6CF8.readPtr, (lbl_803C6CF8.chunk + 0x1F) & ~0x1F,
                       (ARQCallback)fn_800A68D4);
        lbl_803C6CF8.aramReqIndex = (lbl_803C6CF8.aramReqIndex + 1) % 4;
        lbl_803C6CF8.aramAddr += (lbl_803C6CF8.chunk + 0x1F) & ~0x1F;
    } else {
        DVDReadAsyncPrio(lbl_803C6CF8.fileInfo, dst, lbl_803C6CF8.chunk, lbl_803C6CF8.diskOffset, fn_800A7A80, 2);
    }
    if (lbl_803C6CF8.timeoutOn) {
        u32 t = size * 180;
        lbl_803C6CF8.timeout = lbl_803C6CF8.timeoutReset = (t >> 21) < 180 ? 180 : t >> 22;
    }
    return result;
}

static inline void ReadNextChunk(void) {
    s32 avail;
    s32 len;

    if (lbl_803C6CF8.writePtr >= lbl_803C6CF8.readPtr) {
        avail = lbl_803C6CF8.bufEnd - lbl_803C6CF8.writePtr;
    } else {
        avail = lbl_803C6CF8.readPtr - lbl_803C6CF8.writePtr;
    }
    if (avail > lbl_803C6CF8.remaining) {
        avail = lbl_803C6CF8.remaining;
    }
    len = 0x4000;
    if (avail < 0x4000) {
        len = avail;
    }
    if (len != 0) {
        DVDReadAsyncPrio(lbl_803C6CF8.fileInfo, lbl_803C6CF8.writePtr, len, lbl_803C6CF8.diskOffset + lbl_803C6CF8.readOffset,
                         fn_800A6F94, 2);
    }
}

// .text:0x800A6F94 size:0x148
void fn_800A6F94(s32 result, DVDFileInfo* fileInfo) {
    if (result > 0) {
        lbl_803C6CF8.streamDone += result;
        lbl_803C6CF8.readOffset += result;
        lbl_803C6CF8.writePtr += result;
        lbl_803C6CF8.remaining -= result;
        if (lbl_803C6CF8.writePtr == lbl_803C6CF8.bufEnd) {
            lbl_803C6CF8.writePtr = lbl_803C6CF8.bufStart;
        }
        if (lbl_803C6CF8.streamDone == lbl_803C6CF8.streamSize) {
            lbl_803C6CF8.streamEnd = 1;
            lbl_803C6CF8.u.flags[0] = 0;
        } else if (lbl_803C6CF8.readOffset == lbl_803C6CF8.readSize) {
            lbl_803C6CF8.u.status = 1;
        } else {
            ReadNextChunk();
        }
    } else if (result == -3) {
        lbl_803C6CF8.u.flags[0] = 0;
        DVDClose(fileInfo);
    }
}

// .text:0x800A6E24 size:0x170
void fn_800A6E24(AssetLoadInstructions* instr, u8* buf, s32 size) {
    fn_800A7568();
    lbl_803C6CF8.instr = instr;
    lbl_803C6CF8.readOffset = 0;
    lbl_803C6CF8.diskOffset = instr->diskLocation;
    lbl_803C6CF8.remaining = lbl_803C6CF8.readSize = (instr->compressedSize + 0x1F) & ~0x1F;
    lbl_803C6CF8.writePtr = buf;
    lbl_803C6CF8.readPtr = buf;
    lbl_803C6CF8.bufStart = buf;
    lbl_803C6CF8.streamDone = 0;
    lbl_803C6CF8.streamEnd = 0;
    lbl_803C6CF8.streamSize = size;
    lbl_803C6CF8.bufEnd = buf + size;
    while ((s32)lbl_803C6CF8.u.flags[1] != 1) {
    }
    DVDFastOpen(lbl_803C6CF8.entryNum, lbl_803C6CF8.fileInfo);
    lbl_803C6CF8.u.status = 0x400;
    ReadNextChunk();
}

// .text:0x800A6D10 size:0x114
void fn_800A6D10(s32 consumed) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    lbl_803C6CF8.readPtr += consumed;
    if (lbl_803C6CF8.readPtr >= lbl_803C6CF8.bufEnd) {
        lbl_803C6CF8.readPtr -= lbl_803C6CF8.streamSize;
    }
    lbl_803C6CF8.streamDone -= consumed;
    if (lbl_803C6CF8.streamEnd) {
        lbl_803C6CF8.u.flags[0] = 4;
        lbl_803C6CF8.streamEnd = 0;
        ReadNextChunk();
    }
    OSRestoreInterrupts(enabled);
}

// .text:0x800A6C80 size:0x90
void fn_800A6C80(void) {
    fn_800A7568();
    lbl_803C6CF8.remaining = 0;
    lbl_803C6CF8.streamDone = 0;
}

// .text:0x800A6900 size:0x380
void fn_800A6900(void) {
    s8 status;
    s32 chunk;

    while (TRUE) {
        OSSleepThread(&lbl_803C7420.retraceQueue);
        lbl_803C6CF8.driveStatus = DVDGetDriveStatus();
        lbl_803C6CF8.driveCallbacks[(s8)lbl_803C6CF8.driveStatus + 1]();
        if (lbl_803C6CF8.timeoutOn && lbl_803C6CF8.u.flags[0] == 2 && lbl_803C6CF8.timeout != 0) {
            switch (lbl_803C6CF8.driveStatus) {
            case 0:
                lbl_803C6CF8.timeout--;
                break;
            default:
                lbl_803C6CF8.timeout = lbl_803C6CF8.timeoutReset;
                break;
            }
        }
        switch (lbl_803C6CF8.u.flags[0]) {
        case 0:
            break;
        case 1:
            status = DVDGetCommandBlockStatus(&lbl_803C6CF8.fileInfo->cBlock);
            if ((status == DVD_STATE_END) | (status == DVD_STATE_CANCELED)) {
                lbl_803C6CF8.readOffset = 0;
                lbl_803C6CF8.readPtr = lbl_803C6CF8.bufStart;
                lbl_803C6CF8.remaining = lbl_803C6CF8.readSize;
                if (lbl_803C6CF8.timeoutOn) {
                    lbl_803C6CF8.timeout = lbl_803C6CF8.timeoutReset;
                }
                DVDFastOpen(lbl_803C6CF8.entryNum, lbl_803C6CF8.fileInfo);
                if (lbl_803C6CF8.mode == 0) {
                    SetReadParameters(lbl_803C6CF8.instr, lbl_803C6CF8.tempBuf, lbl_803C6CF8.bufEnd, 1);
                } else if (lbl_803C6CF8.mode == 3) {
                    SetReadParameters(lbl_803C6CF8.instr, lbl_803C6CF8.tempBuf, lbl_803C6CF8.bufEnd, 2);
                    lbl_803C6CF8.aramAddr = lbl_803C6CF8.aramBase;
                }
                chunk = lbl_803C6CF8.remaining >= 0x8000 ? 0x8000 : lbl_803C6CF8.remaining;
                lbl_803C6CF8.chunk = chunk;
                if (lbl_803C6CF8.mode == 3) {
                    DCInvalidateRange(lbl_803C6CF8.readPtr, chunk);
                    ARQPostRequest(&lbl_803C6CF8.aramReq[lbl_803C6CF8.aramReqIndex], 2000, ARQ_TYPE_ARAM_TO_MRAM, ARQ_PRIORITY_LOW,
                                   lbl_803C6CF8.aramAddr, (u32)lbl_803C6CF8.readPtr, (lbl_803C6CF8.chunk + 0x1F) & ~0x1F,
                                   (ARQCallback)fn_800A68D4);
                    lbl_803C6CF8.aramReqIndex = (lbl_803C6CF8.aramReqIndex + 1) % 4;
                    lbl_803C6CF8.aramAddr += (lbl_803C6CF8.chunk + 0x1F) & ~0x1F;
                } else {
                    DVDReadAsyncPrio(lbl_803C6CF8.fileInfo, lbl_803C6CF8.bufStart, lbl_803C6CF8.chunk, lbl_803C6CF8.diskOffset,
                                     fn_800A7A80, 2);
                }
                lbl_803C6CF8.u.flags[0] = 2;
            }
            break;
        case 2:
            if (lbl_803C6CF8.mode == 0 || lbl_803C6CF8.mode == 3) {
                if (!gDataDecompressorValues.ShouldWriteDataFlag) {
                    DCFlushRangeNoSync(lbl_803C6CF8.bufEnd, gDataDecompressorValues.CachedBytesToRead);
                    if (lbl_803C6CF8.tempBuf != NULL) {
                        fn_800ACF14(lbl_803C6CF8.tempBuf);
                        lbl_803C6CF8.tempBuf = NULL;
                    }
                    lbl_803C6CF8.u.status = 1;
                } else if (gDataDecompressorValues.error != 0 || (lbl_803C6CF8.timeoutOn && lbl_803C6CF8.timeout == 0)) {
                    DVDCancel(&lbl_803C6CF8.fileInfo->cBlock);
                    OSCancelThread(&gDataDecompressorValues.t);
                    StartThreadForReadingFromDisk();
                    OSCancelThread(&lbl_803C6CF8.readThread);
                    OSCreateThread(&lbl_803C6CF8.readThread, (void* (*)(void*))fn_800A77A0, NULL, lbl_802EAF80.readStack + 0x1000,
                                   0x1000, 8, OS_THREAD_ATTR_DETACH);
                    OSResumeThread(&lbl_803C6CF8.readThread);
                    lbl_803C6CF8.u.flags[0] = 1;
                    OSReport("\nDecode Error Retry : EntryNo%d %x Err:%d\n", lbl_803C6CF8.entryNum, lbl_803C6CF8.instr->diskLocation,
                             gDataDecompressorValues.error);
                }
            }
            break;
        case 3:
            fn_800A7670(0, NULL);
            break;
        case 4:
            break;
        }
    }
}

// .text:0x800A68D4 size:0x2C
void fn_800A68D4(u32 request) {
    OSResumeThread(&lbl_803C6CF8.readThread);
}

// .text:0x800A6890 size:0x44
void fn_800A6890(u32 request) {
    if (lbl_803C6CF8.remaining == 0) {
        lbl_803C6CF8.u.flags[0] = 3;
    } else {
        OSSignalSemaphore(&lbl_803C6CF8.aramSem);
    }
}

// .text:0x800A6870 size:0x20
u32 fn_800A6870(u8 on, u32 timeout) {
    u32 old;

    lbl_803C6CF8.timeoutOn = on;
    old = lbl_803C6CF8.timeoutReset;
    if (on) {
        lbl_803C6CF8.timeoutReset = timeout;
    }
    return old;
}
