#include "static/movie.h"
#include "Dolphin/ar.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "static/dvdsys.h"
#include "static/static_800ACF14.h"
#include "string.h"

typedef struct MovieFrame {
    /* 0x0 */ u8* buf;
    /* 0x4 */ u8 _4[0x8];
} MovieFrame; // size: 0xC

typedef struct MoviePlayer {
    /* 0x000 */ u8 _000[0x28];
    /* 0x028 */ u32 _028;
    /* 0x02C */ u8 _02C[0x30 - 0x2C];
    /* 0x030 */ u32 _030;
    /* 0x034 */ u8 _034[0xA0 - 0x34];
    /* 0x0A0 */ u8 _0A0[4];
    /* 0x0A4 */ u16 width;
    /* 0x0A6 */ u16 height;
    /* 0x0A8 */ u8 _0A8;
    /* 0x0A9 */ u8 _0A9;
    /* 0x0AA */ u8 _0AA[0xD0 - 0xAA];
    /* 0x0D0 */ u8* _0D0;
    /* 0x0D4 */ u8* _0D4;
    /* 0x0D8 */ u8 _0D8[0xE8 - 0xD8];
    /* 0x0E8 */ u8* _0E8;
    /* 0x0EC */ u8* _0EC;
    /* 0x0F0 */ struct MovieHeader* header;
    /* 0x0F4 */ MovieFrame frames[6];
    /* 0x13C */ MovieFrame* _13C[6];
    /* 0x154 */ u8* _154;
    /* 0x158 */ u8* _158;
    /* 0x15C */ u8* _15C;
    /* 0x160 */ u8* _160;
    /* 0x164 */ u8* _164;
    /* 0x168 */ u8* _168;
    /* 0x16C */ u8* _16C;
    /* 0x170 */ u8* _170;
    /* 0x174 */ s32 _174;
    /* 0x178 */ u8 _178[0x198 - 0x178];
    /* 0x198 */ OSTime pausedTime;
    /* 0x1A0 */ OSTime startTime;
    /* 0x1A8 */ u8 _1A8[0x1B8 - 0x1A8];
    /* 0x1B8 */ u8 _1B8;
    /* 0x1B9 */ u8 _1B9;
    /* 0x1BA */ u8 flags;
} MoviePlayer;

typedef struct MovieHeader {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ s32 _0C;
} MovieHeader;

typedef struct MovieRing {
    /* 0x00 */ u32 start;
    /* 0x04 */ u32 end;
    /* 0x08 */ u32 readPos;
    /* 0x0C */ u32 writePos;
    /* 0x10 */ u32 size;
    /* 0x14 */ u32 _14;
    /* 0x18 */ volatile u32 _18;
    /* 0x1C */ volatile u32 _1C;
    /* 0x20 */ volatile u32 _20;
    /* 0x24 */ volatile u32 _24;
    /* 0x28 */ u8 _28;
    /* 0x29 */ volatile u8 _29;
} MovieRing;

typedef struct MovieBuffer {
    /* 0x00 */ u8* _00;
    /* 0x04 */ u32 _04;
    /* 0x08 */ void* _08;
    /* 0x0C */ u32 end;
    /* 0x10 */ u32 pos;
    /* 0x14 */ u32 write;
    /* 0x18 */ u32 size;
    /* 0x1C */ u32 free;
    /* 0x20 */ u32 used;
} MovieBuffer;

extern struct {
    /* 0x000 */ u8 _000[0x700];
    /* 0x700 */ u8* bufEnd;
    /* 0x704 */ u8* writePtr;
    /* 0x708 */ u8* readPtr;
    /* 0x70C */ s32 streamSize;
    /* 0x710 */ u32 streamDone;
    /* 0x714 */ u8 _714;
    /* 0x715 */ volatile s8 _715;
    /* 0x716 */ u8 _716[0x722 - 0x716];
    /* 0x722 */ s8 error;
} lbl_803C6CF8;
extern MovieRing lbl_803C79D4;
extern MovieBuffer lbl_803C7A00;
extern OSMessageQueue lbl_802FB870;

extern u16 lbl_803CBAE4;
extern u32 fn_800E4B1C(void* arg);
extern void fn_800E4B90(void* arg, u8* buf, u32 blocks, u16 blockSize);
extern GXTexObj lbl_803C78A4;
extern ARQRequest lbl_803C78C4[2];
extern ARQRequest lbl_803C7994[2];
extern u8 lbl_803CC1A8;
extern GXTexFmt lbl_803CBAD8[2];

#define ALIGN32(x) (((x) + 31) & ~31)

extern u8 lbl_803CC17C;
extern u8 lbl_803CC17D;
extern u8 lbl_803CC17F;
extern s32 lbl_803CC19C;
extern MoviePlayer* lbl_803CC170;
extern u8 lbl_803CC17E;
extern u8 lbl_803CC181;
extern s32 lbl_803CC1A4;
extern u32 lbl_803CC1AC;
extern OSThread lbl_802FB220;

extern void fn_800A63C8(void);
extern struct {
    /* 0x00 */ u8 _00[0x5C];
    /* 0x5C */ OSThreadQueue retraceQueue;
} lbl_803C7420;
extern u32* lbl_803CBAE8[2];
extern u32* lbl_803CBAF0[2];
extern u32* lbl_803CBAF8[2];
extern u8* lbl_803CC174;
extern u32 lbl_803CC178;
extern u32 lbl_803CC1A0;
extern struct {
    /* 0x000 */ u32 free;
    /* 0x004 */ u8 _004[0x210 - 0x4];
} data_803C6780;
extern s32 fn_800A6418(u32 size);
extern void ARQSetChunkSize(u32 size);
extern void ARQFlushQueue(void);

// .text:0x800B05E4 size:0x140
void fn_800B05E4(s32 aramSize, u32 size) {
    MovieRing* ring = &lbl_803C79D4;
    MovieBuffer* buf = &lbl_803C7A00;

    lbl_803CC1A8 = 0;
    memset(ring, 0, sizeof(MovieRing));
    if (aramSize == -1) {
        ring->size = lbl_803CC1AC < data_803C6780.free ? lbl_803CC1AC : data_803C6780.free;
    } else {
        ring->size = lbl_803CC1AC < aramSize ? lbl_803CC1AC : aramSize;
    }
    ring->size = ALIGN32(ring->size);
    ring->readPos = ring->writePos = ring->start = fn_800A6418(ring->size);
    ring->end = ring->start + ring->size;
    ARQSetChunkSize(0x1000);
    ARQFlushQueue();
    size = ALIGN32(size);
    buf->_04 = lbl_803C6CF8.streamSize;
    buf->_00 = lbl_803C6CF8.bufEnd - lbl_803C6CF8.streamSize;
    buf->_04 = lbl_803C6CF8.streamSize;
    buf->_08 = _OSAllocFromHeap(32, size);
    buf->end = (u32)buf->_08 + size;
    buf->write = (u32)buf->_08;
    buf->pos = (u32)buf->_08;
    buf->size = size;
    buf->free = 0;
    buf->used = 0;
}

// .text:0x800B0580 size:0x64
void fn_800B0580(u32 request) {
    MovieRing* ring = &lbl_803C79D4;

    ring->writePos += ring->_18;
    if (ring->writePos >= ring->end) {
        ring->writePos -= ring->size;
    }
    lbl_803C79D4._1C += ring->_18;
    lbl_803C79D4._14 += ring->_18;
    lbl_803C79D4._29 = 0;
}

// .text:0x800B03F4 size:0x18C
void fn_800B03F4(u8* src, u32 size) {
    MovieRing* ring = &lbl_803C79D4;
    u32 first;
    u32 second;
    u32 end;

    if (ring->writePos + size > ring->end) {
        first = ring->end - ring->writePos;
        second = size - first;
    } else {
        first = size;
        second = 0;
    }
    if (second != 0) {
        end = ring->start + second;
    } else {
        end = ring->writePos + size;
    }
    if ((ring->writePos > ring->readPos && end > ring->readPos && second != 0) ||
        (ring->writePos < ring->readPos && end > ring->readPos)) {
        ring->_29 = 3;
        return;
    }
    if (lbl_803C79D4._14 > lbl_803C79D4.size) {
        while (TRUE) {
        }
    }
    ring->_18 = size;
    lbl_803CC1A8++;
    ring->_29 = 1;
    DCFlushRangeNoSync(src, first);
    ARQPostRequest(&lbl_803C7994[0], 0, ARQ_TYPE_MRAM_TO_ARAM, ARQ_PRIORITY_HIGH, (u32)src, ring->writePos, first,
                   fn_800B0580);
    if (second != 0) {
        while (ring->_29 != 0) {
        }
        ring->_29 = 1;
        DCFlushRangeNoSync(src + first, second);
        ARQPostRequest(&lbl_803C7994[1], 0, ARQ_TYPE_MRAM_TO_ARAM, ARQ_PRIORITY_HIGH, (u32)src + first, ring->start,
                       second, fn_800B0580);
    }
}

// .text:0x800B0390 size:0x64
void fn_800B0390(u32 request) {
    MovieRing* ring = &lbl_803C79D4;

    ring->readPos += ring->_24;
    if (ring->readPos >= ring->end) {
        ring->readPos -= ring->size;
    }
    lbl_803C79D4._14 -= ring->_24;
    lbl_803C79D4._20 += ring->_24;
    lbl_803C79D4._29 = 0;
}

// .text:0x800B0230 size:0x160
// 87.39%: the target keeps dest + first in a fifth saved register (r27); the base recomputes it.
void fn_800B0230(u8* dest, u32 size) {
    MovieRing* ring = &lbl_803C79D4;
    u32 first;
    u32 second;
    u32 end;

    if (size != 0) {
        end = ring->readPos + size;
        if (end > ring->end) {
            first = ring->end - ring->readPos;
            second = size - first;
        } else {
            first = size;
            second = 0;
        }
        if (second != 0) {
            end = ring->start + second;
        }
        if ((ring->writePos > ring->readPos && end > ring->writePos) ||
            (ring->writePos < ring->readPos && end > ring->writePos && second != 0)) {
            ring->_29 = 3;
            return;
        }
        ring->_24 = size;
        ring->_29 = 2;
        DCInvalidateRange(dest, first);
        ARQPostRequest(&lbl_803C78C4[0], 0, ARQ_TYPE_ARAM_TO_MRAM, ARQ_PRIORITY_HIGH, ring->readPos, (u32)dest, first,
                       fn_800B0390);
        DCInvalidateRange(dest, first);
        if (second != 0) {
            while (ring->_29 != 0) {
            }
            ring->_29 = 2;
            DCInvalidateRange(dest + first, second);
            ARQPostRequest(&lbl_803C78C4[1], 0, ARQ_TYPE_ARAM_TO_MRAM, ARQ_PRIORITY_HIGH, ring->start, (u32)(dest + first),
                           second, fn_800B0390);
            DCInvalidateRange(dest + first, second);
        }
    }
}

// .text:0x800B0134 size:0xFC
s32 fn_800B0134(u32 size) {
    BOOL enabled;
    u32 first;
    u32 second;
    u8* src;
    u8* wrap;

    while (lbl_803C6CF8.streamDone < size) {
    }
    enabled = OSDisableInterrupts();
    if (lbl_803C6CF8.readPtr + size < lbl_803C7A00._00 + lbl_803C7A00._04) {
        src = lbl_803C6CF8.readPtr;
        first = size;
        wrap = NULL;
        second = 0;
    } else {
        first = (lbl_803C7A00._00 + lbl_803C7A00._04) - lbl_803C6CF8.readPtr;
        src = lbl_803C6CF8.readPtr;
        wrap = lbl_803C7A00._00;
        second = size - first;
    }
    OSRestoreInterrupts(enabled);
    if (size >= first) {
        fn_800B03F4(src, size);
    } else {
        fn_800B03F4(src, first);
        while (lbl_803C79D4._29 != 0) {
        }
        fn_800B03F4(wrap, second);
    }
    while (lbl_803C79D4._29 != 0) {
    }
    if (size != 0) {
        fn_800A6D10(size);
    }
    return 1;
}

// .text:0x800B0008 size:0x12C
s32 fn_800B0008(u32 size) {
    MovieBuffer* buf = &lbl_803C7A00;
    u32 aligned = ALIGN32(size);
    u32 first;
    u32 second;
    u8* wrap;

    if (buf->free >= buf->size) {
        return 1;
    }
    if (buf->write + aligned > buf->end) {
        first = buf->end - buf->write;
        wrap = buf->_08;
        second = aligned - first;
    } else {
        first = aligned;
        wrap = NULL;
        second = 0;
    }
    fn_800B0230((u8*)buf->write, first);
    while (lbl_803C79D4._29 != 0) {
    }
    if (second != 0) {
        fn_800B0230(wrap, second);
        while (lbl_803C79D4._29 != 0) {
        }
    }
    if (buf->write + aligned < buf->end) {
        buf->write += first;
    } else {
        buf->write = (u32)buf->_08 + second;
    }
    buf->free += aligned;
    if (lbl_803C79D4._20 > lbl_803CC1AC) {
        memset((void*)(buf->write - (lbl_803C79D4._20 - lbl_803CC1AC)), 0, lbl_803C79D4._20 - lbl_803CC1AC);
    }
    return 1;
}

// .text:0x800AFFC0 size:0x48
void fn_800AFFC0(u32 n) {
    MovieBuffer* buf = &lbl_803C7A00;

    buf->pos += n;
    if (buf->pos >= buf->end) {
        buf->pos -= buf->size;
    }
    buf->free -= n;
    buf->used += n;
}

// .text:0x800AFFB0 size:0x10
BOOL fn_800AFFB0(void) {
    return lbl_803C79D4._28;
}

// .text:0x800AFD4C size:0x264
// 99.41%: registers of the inlined fn_800B0134 copy differ (first, second, src, wrap).
s32 fn_800AFD4C(void) {
    MovieRing* ring = &lbl_803C79D4;
    u32 size;

    if (ring->_28 != 0) {
        return 1;
    }
    if (ring->size > ring->_1C + 0x4000) {
        size = 0x4000;
    } else {
        size = ring->size - ring->_1C;
    }
    fn_800B0134(size);
    if (lbl_803C79D4._1C >= ring->size) {
        fn_800B0008(lbl_803C7A00.size);
        // A discarded read of the volatile counter; the target loads it here.
        lbl_803C79D4._1C;
        fn_800A6C80();
        while (lbl_803C6CF8._715 != 1) {
        }
        ring->_28 = 1;
        return 1;
    }
    return 1;
}

// .text:0x800AFC10 size:0x13C
void fn_800AFC10(void) {
    MovieBuffer* buf = &lbl_803C7A00;
    MovieRing* ring = &lbl_803C79D4;

    ring->writePos = ring->start;
    ring->readPos = ring->start;
    ring->_20 = 0;
    buf->write = (u32)buf->_08;
    buf->pos = (u32)buf->_08;
    buf->free = 0;
    buf->used = 0;
    fn_800B0008(buf->size);
}

// .text:0x800AFBF0 size:0x20
void fn_800AFBF0(void) {
    fn_800A63C8();
}

// .text:0x800AF9B4 size:0x23C
// Its body matches only in a file without fn_800AFBF0 to fn_800B05E4, which this file
// inlines into it while the target calls them with bl: the unit is two objects.
s32 fn_800AF9B4(u8* dest, u32 size) {
    return 0;
}

// .text:0x800AF5FC size:0x3B8
void fn_800AF5FC(void) {
}

// .text:0x800AF1A8 size:0x454
void fn_800AF1A8(void) {
}

// .text:0x800AED34 size:0x474
void MovDecodeThread(void) {
}

// .text:0x800AED24 size:0x10
s32 fn_800AED24(void) {
    return lbl_803CC19C == 0;
}

// .text:0x800AEB18 size:0x20C
void MovStreamThread(void) {
}

// .text:0x800AE8B8 size:0x260
void fn_800AE8B8(void) {
}

// .text:0x800AE5B8 size:0x300
void fn_800AE5B8(void) {
}

// .text:0x800AE298 size:0x320
void YUV2RGB_(void) {
}

// .text:0x800ADF60 size:0x338
void YUV2RGB(void) {
}

// .text:0x800ADD70 size:0x1F0
void fn_800ADD70(void) {
}

// .text:0x800ADC40 size:0x130
void fn_800ADC40(void) {
}

// .text:0x800ADBFC size:0x44
void fn_800ADBFC(void) {
    if (lbl_803CC17F != 0) {
        lbl_803CC17C = 1;
        OSSendMessage(&lbl_802FB870, (OSMessage)4, OS_MESSAGE_NOBLOCK);
    }
}

// .text:0x800ADB04 size:0xF8
s32 fn_800ADB04(MovieHeader* header, MoviePlayer* player, u8 arg2, u8 stream) {
    s32 i;

    if (fn_800ADAFC()) {
        return 0;
    }
    lbl_803CC181 = stream;
    lbl_803CC170 = player;
    player->header = header;
    lbl_803CC1A4 = header->_0C;
    if (lbl_803CC181 != 0) {
        lbl_803CC1AC = lbl_803CC1A4;
        if (lbl_803C7A00._08 != NULL) {
            fn_800ACFB0(lbl_803C7A00._08);
        }
    }
    for (i = 0; i < 6; i++) {
        lbl_803CC170->_13C[i] = &lbl_803CC170->frames[i];
    }
    lbl_803CC170->_1B8 = arg2;
    if (lbl_803CC17E == 0) {
        OSResumeThread(&lbl_802FB220);
    }
    OSSendMessage(&lbl_802FB870, (OSMessage)0, OS_MESSAGE_NOBLOCK);
    return 1;
}

// .text:0x800ADAFC size:0x8
s32 fn_800ADAFC(void) {
    return lbl_803CC17D;
}

// .text:0x800AD9F4 size:0x108
void fn_800AD9F4(MoviePlayer* player) {
    if (player != NULL) {
        if (player->flags & 3) {
            if (!fn_800AD780(player)) {
                OSSendMessage(&lbl_802FB870, (OSMessage)2, OS_MESSAGE_NOBLOCK);
            }
        }
        OSSendMessage(&lbl_802FB870, (OSMessage)3, OS_MESSAGE_NOBLOCK);
    }
}

// .text:0x800AD95C size:0x98
void fn_800AD95C(MoviePlayer* player, u8 arg) {
    u8 flags;

    if (player != NULL) {
        flags = player->flags;
        if (flags == 0 || flags == 4) {
            player->_1B9 = arg;
            OSSendMessage(&lbl_802FB870, (OSMessage)1, OS_MESSAGE_NOBLOCK);
        } else if (flags & 2) {
            player->flags = 1;
            player->pausedTime += OSGetTime() - player->startTime;
        }
    }
}

// .text:0x800AD914 size:0x48
void fn_800AD914(MoviePlayer* player) {
    if (player->flags & 1) {
        player->flags = 2;
        player->startTime = OSGetTime();
    }
}

// .text:0x800AD830 size:0xE4
void fn_800AD830(MoviePlayer* player) {
    if (!fn_800AD780(player)) {
        OSSendMessage(&lbl_802FB870, (OSMessage)2, OS_MESSAGE_NOBLOCK);
    }
}

// .text:0x800AD780 size:0xB0
s32 fn_800AD780(MoviePlayer* player) {
    u32 status = fn_800AD490(player);

    if (status == 0) {
        return 1;
    }
    if (status == 4 && lbl_803CC170 == NULL) {
        return 1;
    }
    return 0;
}

// .text:0x800AD6BC size:0xC4
// 83.88%: scheduling and registers of the size terms differ; locals, orders and += chains tried.
u32 fn_800AD6BC(MoviePlayer* player) {
    u32 audio;
    u32 sample;
    u32 pixels;
    u32 blocks;
    u32 size;

    sample = player->_0A8 * player->_0A9;
    pixels = player->width * player->height;
    audio = ALIGN32(player->_030);
    blocks = lbl_803CBAE4 * ((audio + lbl_803CBAE4 - 1) / lbl_803CBAE4);

    size = ALIGN32(player->_028);
    size += ALIGN32(pixels << (player->_1B8 + 1)) * 2;
    size += audio;
    size += blocks * 0x1C;
    size += ALIGN32(pixels * (sample + 2) / sample) * 6;
    size += ALIGN32(fn_800E4B1C(player->_0A0));
    return size;
}

// .text:0x800AD500 size:0x1BC
void fn_800AD500(MoviePlayer* player, u8* buf) {
    u32 blocks;
    u32 pixels;
    u32 texSize;
    u16 width;
    u16 height;
    u8 a;
    u8 b;
    u32 blockSize;
    u32 sample;
    u32 frameSize;
    s32 i;

    width = player->width;
    height = player->height;
    a = player->_0A8;
    b = player->_0A9;
    blocks = lbl_803CBAE4 * ((ALIGN32(player->_030) + lbl_803CBAE4 - 1) / lbl_803CBAE4);
    pixels = width * height;
    blockSize = blocks * 0x1C;
    texSize = pixels << (player->_1B8 + 1);

    fn_800E4B90(player->_0A0, buf, blocks, lbl_803CBAE4);
    player->_16C = buf + ALIGN32(fn_800E4B1C(player->_0A0));
    player->_170 = player->_16C + ALIGN32(texSize);
    memset(player->_16C, 0, ALIGN32(texSize) * 2);
    GXInitTexObj(&lbl_803C78A4, player->_16C, width, height, lbl_803CBAD8[player->_1B8], GX_CLAMP, GX_CLAMP, GX_FALSE);
    player->_174 = 0;
    player->_164 = player->_170 + ALIGN32(texSize);
    player->_168 = player->_164 + ALIGN32(player->_028);
    memset(player->_168, 0, blockSize);
    sample = a * b;
    player->_0D0 = player->_0E8 = player->_154 = player->_168 + ALIGN32(player->_030);
    player->_158 = player->_160 = player->_154;
    player->_0D4 = player->_0EC = player->_15C = player->frames[0].buf = player->_154 + blockSize;
    frameSize = ALIGN32(pixels * (sample + 2) / sample);
    for (i = 1; i < 6; i++) {
        player->frames[i].buf = player->frames[i - 1].buf + frameSize;
    }
}

// .text:0x800AD490 size:0x70
u32 fn_800AD490(MoviePlayer* player) {
    u8 flags;
    s8 error;

    if (player == NULL) {
        return 0xC0000000;
    }
    flags = player->flags;
    if (flags & 4) {
        return 4;
    }
    error = lbl_803C6CF8.error;
    switch (error) {
    case 0:
        break;
    case -1:
        return 0xA0000000;
    default:
        return error | 0x80000000;
    }
    if (flags & 2) {
        return flags & 0x12;
    }
    if (flags & 1) {
        return 1;
    }
    return 0;
}

// .text:0x800AD070 size:0x420
void fn_800AD070(void) {
}
