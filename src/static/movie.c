#include "static/movie.h"
#include "Dolphin/os.h"
#include "string.h"

typedef struct MoviePlayer {
    /* 0x000 */ u8 _000[0x198];
    /* 0x198 */ OSTime pausedTime;
    /* 0x1A0 */ OSTime startTime;
    /* 0x1A8 */ u8 _1A8[0x1B9 - 0x1A8];
    /* 0x1B9 */ u8 _1B9;
    /* 0x1BA */ u8 flags;
} MoviePlayer;

typedef struct MovieRing {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ u32 end;
    /* 0x08 */ u32 readPos;
    /* 0x0C */ u32 writePos;
    /* 0x10 */ u32 size;
    /* 0x14 */ u32 _14;
    /* 0x18 */ u32 _18;
    /* 0x1C */ u32 _1C;
    /* 0x20 */ u32 _20;
    /* 0x24 */ u32 _24;
    /* 0x28 */ u8 _28;
    /* 0x29 */ u8 _29;
} MovieRing;

typedef struct MovieBuffer {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ u32 end;
    /* 0x10 */ u32 pos;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ u32 size;
    /* 0x1C */ u32 free;
    /* 0x20 */ u32 used;
} MovieBuffer;

extern struct {
    /* 0x000 */ u8 _000[0x722];
    /* 0x722 */ s8 error;
} lbl_803C6CF8;
extern MovieRing lbl_803C79D4;
extern MovieBuffer lbl_803C7A00;
extern OSMessageQueue lbl_802FB870;

extern u8 lbl_803CC17C;
extern u8 lbl_803CC17D;
extern u8 lbl_803CC17F;
extern s32 lbl_803CC19C;
extern void* lbl_803CC170;

extern void fn_800A63C8(void);

// .text:0x800B05E4 size:0x140
void fn_800B05E4(void) {
}

// .text:0x800B0580 size:0x64
// 57.12%: same shape as fn_800B0390.
void fn_800B0580(void) {
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
void fn_800B03F4(void) {
}

// .text:0x800B0390 size:0x64
// 67.40%: the target reloads ring->_24 after each store to lbl_803C79D4 (two bases).
void fn_800B0390(void) {
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
void fn_800B0230(void) {
}

// .text:0x800B0134 size:0xFC
void fn_800B0134(void) {
}

// .text:0x800B0008 size:0x12C
void fn_800B0008(void) {
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
u8 fn_800AFFB0(void) {
    return lbl_803C79D4._28;
}

// .text:0x800AFD4C size:0x264
void fn_800AFD4C(void) {
}

// .text:0x800AFC10 size:0x13C
void fn_800AFC10(void) {
}

// .text:0x800AFBF0 size:0x20
void fn_800AFBF0(void) {
    fn_800A63C8();
}

// .text:0x800AF9B4 size:0x23C
void fn_800AF9B4(void) {
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
void fn_800ADB04(void) {
}

// .text:0x800ADAFC size:0x8
u8 fn_800ADAFC(void) {
    return lbl_803CC17D;
}

// .text:0x800AD9F4 size:0x108
void fn_800AD9F4(void) {
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
void fn_800AD830(void) {
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
void fn_800AD6BC(void) {
}

// .text:0x800AD500 size:0x1BC
void fn_800AD500(void) {
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
