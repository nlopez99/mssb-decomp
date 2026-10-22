#include "static/mcard.h"
#include "Dolphin/os.h"
#include "Dolphin/card.h"
#include "string.h"
#include "Dolphin/dvd.h"
#include "Dolphin/gx.h"
#include "charPipeline/texPalette.h"

typedef struct McardTask {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct McardTask* parent;
    /* 0x10 */ s16 result;
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ s32 state;
    /* 0x18 */ u8 chan;
    /* 0x19 */ u8 async;
    /* 0x1A */ union {
        u16 flag;
        s16 blocks;
    } _1A;
    /* 0x1C */ char* fileName;
    /* 0x20 */ u8 status;
    /* 0x21 */ u8 _21[7];
    /* 0x28 */ s32 state2;
    /* 0x2C */ s32 buf;
    /* 0x30 */ u32 size;
    /* 0x34 */ char* name;
    /* 0x38 */ u8 _38;
    /* 0x39 */ u8 _39;
    /* 0x3A */ u8 _3A;
    /* 0x3B */ u8 _3B;
    /* 0x3C */ u8 _3C;
    /* 0x3D */ u8 _3D;
} McardTask;

typedef struct McardIoTask {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ McardTask* parent;
    /* 0x10 */ s16 result;
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ CARDFileInfo fileInfo;
    /* 0x28 */ s32 state;
    /* 0x2C */ void* buf;
    /* 0x30 */ u32 size;
    /* 0x34 */ char* name;
    /* 0x38 */ s32 fileNo;
    /* 0x3C */ u8 chan;
    /* 0x3D */ u8 async;
} McardIoTask;

typedef struct McardWriteTask {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ McardTask* parent;
    /* 0x10 */ s16 result;
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ CARDFileInfo fileInfo;
    /* 0x28 */ s32 state;
    /* 0x2C */ void* buf;
    /* 0x30 */ u32 size;
    /* 0x34 */ s32 fileNo;
    /* 0x38 */ u8 chan;
    /* 0x39 */ u8 async;
    /* 0x3A */ u8 attr;
} McardWriteTask;

typedef struct McardSlot {
    /* 0x00 */ u64 serial;
    /* 0x08 */ s32 probe;
    /* 0x0C */ s32 memSize;
    /* 0x10 */ s32 sectorSize;
    /* 0x14 */ s32 freeBlocks;
    /* 0x18 */ s32 bytesFree;
    /* 0x1C */ s32 filesFree;
    /* 0x20 */ s32 totalBlocks;
    /* 0x24 */ u8 _24[0x28 - 0x24];
} McardSlot;

typedef struct McardState {
    /* 0x00 */ McardSlot slots[2];
    /* 0x50 */ s32 lastResult;
    /* 0x54 */ u8 error;
    /* 0x55 */ u8 op;
    /* 0x56 */ u8 bannerSet;
    /* 0x57 */ u8 iconCount;
    /* 0x58 */ s32 xferred;
    /* 0x5C */ u8 percent;
    /* 0x5D */ u8 _5D[3];
} McardState;

typedef u32 (*McardCallback)(s32 buf, u32 size, s32 arg);

typedef struct McardRequest {
    /* 0x00 */ char* name;
    /* 0x04 */ s32 buf;
    /* 0x08 */ s32 size;
    /* 0x0C */ u8 chan;
    /* 0x0D */ u8 async;
    /* 0x0E */ u8 retries;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ McardCallback callback;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
} McardRequest;

extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800B0A14_removeQueue(void);
extern s32 CARDDeleteAsync(s32 chan, char* fileName, CARDCallback callback);
extern s32 CARDFastDelete(s32 chan, char* fileName);
extern s32 CARDGetResultCode(s32 chan);
extern s32 CARDCheckAsync(s32 chan, CARDCallback callback);
extern s32 CARDFormatAsync(s32 chan, CARDCallback callback);
extern s32 CARDGetXferredBytes(s32 chan);
extern s32 CARDSetAttributesAsync(s32 chan, s32 fileNo, u8 attr, CARDCallback callback);
extern s32 CARDSetAttributes(s32 chan, s32 fileNo, u8 attr);
extern void fn_800ACFB0(void* ptr);
extern void* _OSAllocFromHeap(s32 heap, u32 size);
extern McardTask* lbl_803CC1B8;
extern McardState lbl_803C7838;
extern u64 lbl_802EF2C0[2];
extern char lbl_802EF2D0[0x20];
extern CARDStat lbl_802EF330;
extern u8 lbl_802EF2F0[0x40];

void* lbl_803CC16C;
s32 lbl_803CC168;
void* lbl_803CC164;
s32 lbl_803CC160;
McardCallback lbl_803CC15C;
s32 lbl_803CC158;

extern CARDMemoryCard lbl_802EF3A0;

static const u16 lbl_800E7800[256] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
    0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
    0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
    0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
    0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
    0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
    0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
    0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
    0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
    0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
    0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
    0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
    0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
    0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
    0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
    0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
    0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
    0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
    0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
    0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
    0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
    0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
    0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0,
};

static inline s32 CheckSlot(u8 chan) {
    fn_800ACD64(lbl_803C7838.slots[chan].probe);
    if (lbl_803C7838.error == 0xF) {
        return 0;
    }
    if (lbl_803C7838.error != 0x11) {
        return 2;
    }
    fn_800ACD64(lbl_803C7838.slots[chan].sectorSize == 0x2000 ? 0 : -0x81);
    if (lbl_803C7838.error == 0xF) {
        return 0;
    }
    if (lbl_803C7838.error != 0x11) {
        return 2;
    }
    return 1;
}

static inline s32 Mount(s32 chan, s32 async) {
    s32 result;

    if (async == 1) {
        result = CARDMountAsync(chan, &lbl_802EF3A0, NULL, NULL);
        if (result == CARD_RESULT_BUSY) {
            return 1;
        }
    } else {
        result = CARDMount(chan, &lbl_802EF3A0, NULL);
    }
    fn_800ACD64(result);
    return 0;
}

static inline s32 Check(s32 chan, s32 async) {
    s32 result;

    if (async == 1) {
        result = CARDCheckAsync(chan, NULL);
        if (result == CARD_RESULT_BUSY) {
            return 1;
        }
    } else {
        result = CARDCheck(chan);
    }
    fn_800ACD64(result);
    return 0;
}

static inline s32 Format(s32 chan, s32 async) {
    s32 result;

    if (async == 1) {
        result = CARDFormatAsync(chan, NULL);
        if (result == CARD_RESULT_BUSY) {
            return 1;
        }
    } else {
        result = CARDFormat(chan);
    }
    fn_800ACD64(result);
    return 0;
}

static inline s32 ReadSerial(u8 chan) {
    u64 serial = 0;
    s32 result;

    result = CARDGetSerialNo(chan, &serial);
    lbl_803C7838.slots[chan].serial = serial;
    return result;
}

static inline s32 FindFile(u8 chan, char* fileName) {
    char name[0x21];
    CARDFileInfo info;
    s32 result;
    s32 found;

    strncpy(name, fileName, 0x20);
    name[0x20] = 0;
    if (strlen(name) >= 0x20) {
        OSPanic("mcard.c", 510, "MemoryCard FileName Error!!");
    }
    result = CARDOpen(chan, fileName, &info);
    switch (result) {
    case CARD_RESULT_READY:
        lbl_803C7838.error = 8;
        found = 0;
        CARDClose(&info);
        break;
    case CARD_RESULT_NOFILE:
        found = 1;
        break;
    default:
        fn_800ACD64(result);
        found = 2;
        break;
    }
    return found;
}

static inline s32 SetAttributes(s32 chan, s32 fileNo, u8 attr, s32 async) {
    s32 result;

    if (async == 1) {
        result = CARDSetAttributesAsync(chan, fileNo, attr, NULL);
        if (result == CARD_RESULT_BUSY) {
            return 1;
        }
    } else {
        result = CARDSetAttributes(chan, fileNo, attr);
    }
    fn_800ACD64(result);
    return 0;
}

static BOOL ReadOpening(u8* buf);
static void BindPalette(TEXPalettePtr pal);

// .text:0x800ACD64 size:0x1B0
void fn_800ACD64(s32 result) {
    lbl_803C7838.lastResult = result;
    switch (result) {
    case CARD_RESULT_READY:
        lbl_803C7838.error = 0x11;
        break;
    case CARD_RESULT_BUSY:
        lbl_803C7838.error = 0xF;
        break;
    case CARD_RESULT_NOCARD:
        lbl_803C7838.error = 0;
        break;
    case CARD_RESULT_BROKEN:
        lbl_803C7838.error = 1;
        break;
    case CARD_RESULT_ENCODING:
        lbl_803C7838.error = 2;
        break;
    case CARD_RESULT_IOERROR:
    case CARD_RESULT_FATAL_ERROR:
        lbl_803C7838.error = 3;
        break;
    case CARD_RESULT_WRONGDEVICE:
        lbl_803C7838.error = 4;
        break;
    case CARD_RESULT_NOENT:
        lbl_803C7838.error = 5;
        break;
    case CARD_RESULT_INSSPACE:
        lbl_803C7838.error = 6;
        break;
    case CARD_RESULT_EXIST:
        lbl_803C7838.error = 8;
        break;
    case CARD_RESULT_NOPERM:
    case CARD_RESULT_LIMIT:
    case CARD_RESULT_CANCELED:
        if (lbl_803C7838.op == 1) {
            lbl_803C7838.error = 9;
        } else if (lbl_803C7838.op == 2) {
            lbl_803C7838.error = 0xA;
        }
        break;
    case CARD_RESULT_NOFILE:
        if (lbl_803C7838.op == 1) {
            lbl_803C7838.error = 9;
        } else if (lbl_803C7838.op == 2) {
            lbl_803C7838.error = 0xE;
        }
        break;
    case CARD_RESULT_NAMETOOLONG:
        OSPanic("mcard.c", 236, "CARD_RESULT_NAMETOOLONG           \n");
        break;
    case -0x81:
        lbl_803C7838.error = 7;
        break;
    }
}

// .text:0x800ACD44 size:0x20
void fn_800ACD44(void) {
    CARDInit();
}

// .text:0x800ACCE8 size:0x5C
void fn_800ACCE8(void) {
    memset(&lbl_803C7838, 0, sizeof(McardState));
    lbl_803C7838.error = 0xF;
    lbl_803C7838.slots[0].probe = -1;
    lbl_803C7838.slots[1].probe = -1;
    fn_800B0A5C_insertQueue(fn_800ABB60, 0xF0);
}

// .text:0x800ACCD4 size:0x14
void fn_800ACCD4(void) {
    lbl_803C7838.op = 7;
}

// .text:0x800ACC6C size:0x68
s32 fn_800ACC6C(s32 type, s32 a, s32 b) {
    s32 blocks;

    switch (type) {
    case 0:
        type = 0;
        break;
    case 1:
        type = 0x1800;
        break;
    case 2:
        type = 0xE00;
        break;
    }
    type += a + b;
    blocks = type / 0x2000;
    if (type % 0x2000 != 0) {
        blocks++;
    }
    return blocks;
}

// .text:0x800AC508 size:0x764
// The target pools "/opening.bnr" and the palette-version string ahead of fn_800ABF44's, so four
// string offsets differ; the masked iconSpeed and the CARDStat base also swap r23/r24.
void fn_800AC508(char* fileName, void* banner, s32 bannerSize, void* icon, u32 iconSize, s32 iconSpeed, s32 iconAnim, char* comment, char* comment2, s32 blocks) {
    TEXDescriptorPtr desc;
    u8* opening = NULL;
    u8* dst;
    TEXPalettePtr pal;
    s32 shift;
    s32 i;
    s16 hasClut;
    char* comments;

    memset(&lbl_802EF330, 0, 0x6C);
    lbl_802EF330.length = blocks << 13;
    lbl_803CC16C = _OSAllocFromHeap(0x20, lbl_802EF330.length);
    memset(lbl_803CC16C, 0, lbl_802EF330.length);
    strncpy(lbl_802EF330.fileName, fileName, 0x20);
    if ((banner == NULL && bannerSize == 0) || comment == NULL) {
        opening = _OSAllocFromHeap(0x20, 0x1960);
        if (!ReadOpening(opening)) {
            OSPanic("mcard.c", 756, "\"opening.bnr\" is not found in the root directory.\n");
        }
    }
    comments = (char*)lbl_802EF2F0;
    memset(comments, 0, 4);
    if (comment == NULL) {
        strncpy(comments, (char*)(opening + 0x1820), 0x1F);
    } else {
        strncpy(comments, comment, 0x1F);
    }
    memset(comments + 0x20, 0, 4);
    strncpy(comments + 0x20, comment2, 0x1F);
    lbl_802EF330.iconAddr = 0;
    dst = lbl_803CC16C;
    if (banner == NULL) {
        if (bannerSize == 0) {
            lbl_802EF330.bannerFormat = CARD_STAT_BANNER_RGB5A3;
            memcpy(dst, opening + 0x20, 0x1800);
            dst += 0x1800;
            lbl_803C7838.bannerSet = 1;
        }
    } else {
        pal = _OSAllocFromHeap(0x20, bannerSize);
        memcpy(pal, banner, bannerSize);
        BindPalette(pal);
        desc = TEXGet(pal, 0);
        switch (desc->textureHeader->format) {
        case GX_TF_RGB5A3:
            lbl_802EF330.bannerFormat = CARD_STAT_BANNER_RGB5A3;
            memcpy(dst, desc->textureHeader->data, 0x1800);
            dst += 0x1800;
            break;
        case GX_TF_C8:
            lbl_802EF330.bannerFormat = CARD_STAT_BANNER_C8;
            memcpy(dst, desc->textureHeader->data, 0xC00);
            memcpy(dst + 0xC00, desc->CLUTHeader->data, 0x200);
            dst += 0xE00;
            break;
        default:
            OSPanic("mcard.c", 814, "Unsupported banner texture format.\n");
            break;
        }
        fn_800ACFB0(pal);
        lbl_803C7838.bannerSet = 1;
    }
    if (icon != NULL) {
        hasClut = 0;
        pal = _OSAllocFromHeap(0x20, iconSize);
        memcpy(pal, icon, iconSize);
        BindPalette(pal);
        for (i = 0, shift = 0; i < pal->numDescriptors && i < 8; i++, shift += 2) {
            desc = TEXGet(pal, i);
            switch (desc->textureHeader->format) {
            case GX_TF_RGB5A3:
                lbl_802EF330.iconFormat = (lbl_802EF330.iconFormat & ~(CARD_STAT_ICON_MASK << shift)) | (CARD_STAT_ICON_RGB5A3 << shift);
                memcpy(dst, desc->textureHeader->data, 0x800);
                dst += 0x800;
                break;
            case GX_TF_C8:
                lbl_802EF330.iconFormat = (lbl_802EF330.iconFormat & ~(CARD_STAT_ICON_MASK << shift)) | (CARD_STAT_ICON_C8 << shift);
                memcpy(dst, desc->textureHeader->data, 0x400);
                hasClut = 1;
                dst += 0x400;
                break;
            default:
                OSPanic("mcard.c", 849, "Unsupported icon texture formant.\n");
                break;
            }
            lbl_802EF330.iconSpeed = (lbl_802EF330.iconSpeed & ~(CARD_STAT_SPEED_MASK << shift)) | ((iconSpeed & CARD_STAT_SPEED_MASK) << shift);
        }
        for (; i < 8; i++) {
            CARDSetIconFormat(&lbl_802EF330, i, CARD_STAT_ICON_NONE);
            CARDSetIconSpeed(&lbl_802EF330, i, CARD_STAT_SPEED_END);
        }
        lbl_803C7838.iconCount = i;
        if (hasClut == 1) {
            memcpy(dst, desc->CLUTHeader->data, 0x200);
            dst += 0x200;
        }
        lbl_802EF330.bannerFormat |= iconAnim & CARD_STAT_ANIM_MASK;
        fn_800ACFB0(pal);
    }
    if (opening != NULL) {
        fn_800ACFB0(opening);
    }
    lbl_803CC164 = dst;
    lbl_802EF330.commentAddr = dst - (u8*)lbl_803CC16C;
}

// .text:0x800ABF44 size:0x5C4
// The inlined fn_800ABB14 copy swaps its data pointer and length registers (as in fn_800ABBD0),
// and the SizeOver string's pool offset waits on fn_800AC508's strings.
void fn_800ABF44(void) {
    McardWriteTask* wr;
    CARDStat* stat = &lbl_802EF330;
    McardTask* task = lbl_803CC1B8;
    char name[0x21];
    u8* buf;
    s32 result;
    u32 size;

    wr = (McardWriteTask*)task->parent;
    if (lbl_803C7838.slots[wr->chan].probe == CARD_RESULT_NOCARD) {
        task->state = 0xA;
    }
    switch (task->state) {
    case 0:
        buf = wr->buf;
        memcpy(buf, lbl_802EF2F0, 0x40);
        if (!(lbl_803CC160 & 1)) {
            *(u16*)(buf + 0x40) = fn_800ABB14((u8*)wr->buf + 0x44, wr->size - 0x44);
        }
        memcpy(lbl_803CC164, wr->buf, wr->size);
        if (stat->commentAddr + wr->size > stat->length) {
            OSPanic("mcard.c", 932, "MemoryCard SizeOver Error!!");
        }
        strncpy(name, stat->fileName, 0x20);
        name[0x20] = 0;
        if (strlen(name) >= 0x20) {
            OSPanic("mcard.c", 938, "MemoryCard FileName Error!!");
        }
        result = CARDOpen(wr->chan, stat->fileName, &wr->fileInfo);
        switch (result) {
        case CARD_RESULT_NOFILE:
            task->state += 1;
            break;
        case CARD_RESULT_READY:
            task->state += 3;
            break;
        default:
            fn_800ACD64(result);
            task->state = 0xA;
            break;
        }
        break;
    case 1:
        if (wr->async == 1) {
            result = CARDCreateAsync(wr->chan, stat->fileName, stat->length, &wr->fileInfo, NULL);
            if (result < 0) {
                fn_800ACD64(result);
                CARDClose(&wr->fileInfo);
                task->state = 0xA;
            } else {
                task->state += 1;
            }
        } else {
            result = CARDCreate(wr->chan, stat->fileName, stat->length, &wr->fileInfo);
            if (result < 0) {
                fn_800ACD64(result);
                CARDClose(&wr->fileInfo);
                task->state = 0xA;
            } else {
                task->state += 2;
            }
        }
        break;
    case 2:
        fn_800ACD64(CARDGetResultCode(wr->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state += 1;
            break;
        case 0x10:
        default:
            CARDClose(&wr->fileInfo);
            task->state = 0xA;
            break;
        }
        break;
    case 3:
        lbl_803CC168 = CARDGetXferredBytes(wr->chan);
        wr->fileNo = wr->fileInfo.fileNo;
        if (wr->async == 1) {
            result = CARDWriteAsync(&wr->fileInfo, lbl_803CC16C, stat->length, 0, NULL);
            if (result < 0) {
                fn_800ACD64(result);
                CARDClose(&wr->fileInfo);
                task->state = 0xA;
            } else {
                task->state += 1;
            }
        } else {
            result = CARDWrite(&wr->fileInfo, lbl_803CC16C, stat->length, 0);
            CARDClose(&wr->fileInfo);
            if (result < 0) {
                fn_800ACD64(result);
                task->state = 0xA;
            } else {
                task->state += 2;
            }
        }
        break;
    case 4:
        size = stat->length;
        result = CARDGetXferredBytes(wr->chan) - lbl_803CC168;
        lbl_803C7838.xferred = result;
        lbl_803C7838.percent = (result * 100) / (s32)size;
        if (lbl_803C7838.percent > 100) {
            lbl_803C7838.percent = 100;
        }
        fn_800ACD64(CARDGetResultCode(wr->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            CARDClose(&wr->fileInfo);
            task->state += 1;
            break;
        case 0x10:
        default:
            CARDClose(&wr->fileInfo);
            task->state = 0xA;
            break;
        }
        break;
    case 5:
        if (wr->async == 1) {
            result = CARDSetStatusAsync(wr->chan, wr->fileNo, stat, NULL);
            if (result < 0) {
                fn_800ACD64(result);
                task->state = 0xA;
            } else {
                task->state += 1;
            }
        } else {
            result = CARDSetStatus(wr->chan, wr->fileNo, stat);
            if (result < 0) {
                fn_800ACD64(result);
                task->state = 0xA;
            } else {
                task->state += 2;
            }
        }
        break;
    case 6:
        fn_800ACD64(CARDGetResultCode(wr->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state += 1;
            break;
        case 0x10:
        default:
            task->state = 0xA;
            break;
        }
        break;
    case 7:
        if (SetAttributes(wr->chan, wr->fileNo, wr->attr, wr->async) == 0) {
            task->state += 1;
        }
        break;
    case 8:
        fn_800ACD64(CARDGetResultCode(wr->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state = 9;
            break;
        case 0x10:
        default:
            task->state = 0xA;
            break;
        }
        break;
    case 9:
        lbl_803CC1B8->parent->result = 1;
        fn_800B0A14_removeQueue();
        break;
    case 0xA:
        lbl_803CC1B8->parent->result = 2;
        fn_800B0A14_removeQueue();
        break;
    }
}

static inline BOOL ReadOpening(u8* buf) {
    DVDFileInfo info;

    if (!DVDOpen("/opening.bnr", &info)) {
        return FALSE;
    }
    if (OSRoundUp32B(info.length) < 0x1960) {
        return FALSE;
    }
    if (!DVDReadPrio(&info, buf, 0x1960, 0, 2)) {
        return FALSE;
    }
    if (*(u32*)buf != 'BNR1') {
        return FALSE;
    }
    return TRUE;
}

static inline void BindPalette(TEXPalettePtr pal) {
    u16 i;

    if (pal->versionNumber != 2142000) {
        OSPanic("mcard.c", 1327, "invalid version number for texture palette");
    }
    pal->descriptorArray = (TEXDescriptorPtr)((u32)pal->descriptorArray + (u32)pal);
    for (i = 0; i < pal->numDescriptors; i++) {
        if (pal->descriptorArray[i].textureHeader) {
            pal->descriptorArray[i].textureHeader = (TEXHeaderPtr)((u32)pal->descriptorArray[i].textureHeader + (u32)pal);
            if (!pal->descriptorArray[i].textureHeader->unpacked) {
                pal->descriptorArray[i].textureHeader->data = (Ptr)((u32)pal->descriptorArray[i].textureHeader->data + (u32)pal);
                pal->descriptorArray[i].textureHeader->unpacked = 1;
            }
        }
        if (pal->descriptorArray[i].CLUTHeader) {
            pal->descriptorArray[i].CLUTHeader = (CLUTHeaderPtr)((u32)pal->descriptorArray[i].CLUTHeader + (u32)pal);
            if (!pal->descriptorArray[i].CLUTHeader->unpacked) {
                pal->descriptorArray[i].CLUTHeader->data = (Ptr)((u32)pal->descriptorArray[i].CLUTHeader->data + (u32)pal);
                pal->descriptorArray[i].CLUTHeader->unpacked = 1;
            }
        }
    }
}

// .text:0x800ABBD0 size:0x374
// Only the inlined fn_800ABB14 copy differs: its data pointer and length swap registers (r7/r8).
void fn_800ABBD0(void) {
    CARDStat* stat = &lbl_802EF330;
    McardTask* task = lbl_803CC1B8;
    McardIoTask* io = (McardIoTask*)task->parent;
    s32 result;
    s32 size;
    u8* buf;

    switch (task->state) {
    case 0:
        result = CARDOpen(io->chan, io->name, &io->fileInfo);
        if (result == CARD_RESULT_READY) {
            io->fileNo = io->fileInfo.fileNo;
        } else {
            fn_800ACD64(result);
            lbl_803CC1B8->parent->result = 2;
            fn_800B0A14_removeQueue();
            break;
        }
        result = CARDGetStatus(io->chan, io->fileNo, stat);
        if (result == CARD_RESULT_READY) {
            if (stat->iconAddr == 0xFFFFFFFF || stat->commentAddr == 0xFFFFFFFF) {
                fn_800ACD64(CARD_RESULT_CANCELED);
                lbl_803C7838.error = 0xB;
                lbl_803CC1B8->parent->result = 2;
                fn_800B0A14_removeQueue();
                break;
            }
        } else {
            fn_800ACD64(result);
            lbl_803CC1B8->parent->result = 2;
            fn_800B0A14_removeQueue();
            break;
        }
        task->state += 1;
        break;
    case 1:
        lbl_803CC168 = CARDGetXferredBytes(io->chan);
        if (io->async == 1) {
            result = CARDReadAsync(&io->fileInfo, io->buf, io->size, stat->offsetData, NULL);
            if (result < 0) {
                fn_800ACD64(result);
                CARDClose(&io->fileInfo);
                lbl_803CC1B8->parent->result = 2;
                fn_800B0A14_removeQueue();
            } else {
                task->state += 1;
            }
        } else {
            result = CARDRead(&io->fileInfo, io->buf, io->size, stat->offsetData);
            CARDClose(&io->fileInfo);
            if (result < 0) {
                fn_800ACD64(result);
                lbl_803CC1B8->parent->result = 2;
                fn_800B0A14_removeQueue();
            } else {
                task->state += 2;
            }
        }
        break;
    case 2:
        size = io->size;
        result = CARDGetXferredBytes(io->chan) - lbl_803CC168;
        lbl_803C7838.xferred = result;
        lbl_803C7838.percent = (result * 100) / size;
        if (lbl_803C7838.percent > 100) {
            lbl_803C7838.percent = 100;
        }
        fn_800ACD64(CARDGetResultCode(io->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            CARDClose(&io->fileInfo);
            task->state += 1;
            break;
        case 0x10:
        default:
            CARDClose(&io->fileInfo);
            lbl_803CC1B8->parent->result = 2;
            fn_800B0A14_removeQueue();
            break;
        }
        break;
    case 3:
        if (!(lbl_803CC160 & 1)) {
            buf = io->buf;
            if (*(u16*)(buf + 0x40) != fn_800ABB14(buf + 0x44, io->size - 0x44)) {
                lbl_803C7838.error = 0xB;
                task->parent->result = 2;
                fn_800B0A14_removeQueue();
                break;
            }
        }
        task->state += 1;
    case 4:
        lbl_803CC1B8->parent->result = 1;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x800ABB60 size:0x70
void fn_800ABB60(void) {
    McardSlot* slot = lbl_803C7838.slots;
    s32 chan;

    if (lbl_803C7838.op == 7) {
        fn_800B0A14_removeQueue();
        return;
    }
    for (chan = 0; chan < 2; chan++, slot++) {
        slot->probe = CARDProbeEx(chan, &slot->memSize, &slot->sectorSize);
    }
}

// .text:0x800ABB14 size:0x4C
u16 fn_800ABB14(u8* data, s32 len) {
    u16 crc = 0xFFFF;

    while (--len >= 0) {
        crc = (crc << 8) ^ lbl_800E7800[(u8)(crc >> 8) ^ *data++];
    }
    return ~crc;
}

// .text:0x800AB534 size:0x5E0
void fn_800AB534(void) {
    McardTask* task = lbl_803CC1B8;
    u8 chan;
    s32 result;
    McardSlot* slot;

    switch (task->state) {
    case 0:
        chan = task->chan;
        fn_800ACD64(CARDUnmount(chan));
        switch (CheckSlot(chan)) {
        case 0:
            break;
        case 1:
            task->state = 1;
            break;
        case 2:
            task->state = 9;
            break;
        }
        break;
    case 1:
        if (Mount(task->chan, task->async) == 0) {
            task->state = 2;
        }
        break;
    case 2:
        fn_800ACD64(CARDGetResultCode(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 1:
        case 2:
        case 0x11:
            task->state = 3;
            break;
        default:
            task->state = 9;
            break;
        }
        break;
    case 3:
        if (Check(task->chan, task->async) == 0) {
            task->state = 4;
        }
        break;
    case 4:
        fn_800ACD64(CARDGetResultCode(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state = 5;
            break;
        case 0x10:
        default:
            task->state = 9;
            break;
        }
        break;
    case 5:
        if (lbl_803C7838.error == 0x11) {
            if (ReadSerial(task->chan) != CARD_RESULT_BUSY) {
                if (lbl_803C7838.slots[task->chan].serial != 0) {
                    if (lbl_803C7838.slots[task->chan].serial == lbl_802EF2C0[task->chan]) {
                        task->state = 6;
                    } else {
                        lbl_803C7838.error = 0x10;
                        task->state = 9;
                    }
                } else {
                    lbl_803C7838.error = 0x10;
                    task->state = 9;
                }
            }
        } else {
            task->state = 9;
        }
        break;
    case 6:
        switch (FindFile(task->chan, task->fileName)) {
        case 0:
            task->status = 0;
            task->state = 8;
            break;
        case 1:
            task->state = 7;
            break;
        case 2:
            task->state = 9;
            break;
        }
        break;
    case 7:
        chan = task->chan;
        result = CARDFreeBlocks(chan, &lbl_803C7838.slots[chan].bytesFree, &lbl_803C7838.slots[chan].filesFree);
        if (result >= 0) {
            lbl_803C7838.slots[chan].freeBlocks = lbl_803C7838.slots[chan].bytesFree / lbl_803C7838.slots[chan].sectorSize;
            lbl_803C7838.slots[chan].totalBlocks =
                ((lbl_803C7838.slots[chan].memSize << 20) / 8) / lbl_803C7838.slots[chan].sectorSize - 5;
        }
        fn_800ACD64(result);
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            slot = &lbl_803C7838.slots[task->chan];
            if (slot->filesFree == 0) {
                task->status = 1;
            } else if (task->_1A.blocks > slot->freeBlocks) {
                task->status = 2;
            } else {
                task->status = 0;
            }
            task->state = 8;
            break;
        case 0x10:
        default:
            task->state = 9;
            break;
        }
        break;
    case 8:
        fn_800ACD64(CARDUnmount(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            switch (task->status) {
            case 1:
                lbl_803C7838.error = 5;
                break;
            case 2:
                lbl_803C7838.error = 6;
                break;
            }
            task->state = 9;
            break;
        case 0x10:
        default:
            task->state = 9;
            break;
        }
        break;
    case 9:
        task->parent->result = 1;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x800AB474 size:0xC0
void fn_800AB474(u8 chan, u8 async, s16 fileNo, char* fileName, u64 serial) {
    McardTask* task;

    lbl_803C7838.op = 3;
    task = fn_800B0A5C_insertQueue(fn_800AB534, 0xFF);
    memset(&task->state, 0, 0x2C);
    task->chan = chan;
    task->async = async;
    task->_1A.blocks = fileNo;
    task->fileName = lbl_802EF2D0;
    memcpy(task->fileName, fileName, 0x20);
    lbl_802EF2C0[chan] = serial;
    lbl_803CC1B8->result = 0;
}

// .text:0x800AAFEC size:0x488
void fn_800AAFEC(void) {
    McardTask* task = lbl_803CC1B8;
    u8 chan;
    u32 result;
    McardTask* sub;

    switch (task->state2) {
    case 0:
        chan = task->_38;
        fn_800ACD64(CARDUnmount(chan));
        switch (CheckSlot(chan)) {
        case 0:
            break;
        case 1:
            task->state2 = 1;
            break;
        case 2:
            task->state2 = 9;
            break;
        }
        break;
    case 1:
        if (Mount(task->_38, task->_39) == 0) {
            task->state2 = 2;
        }
        break;
    case 2:
        fn_800ACD64(CARDGetResultCode(task->_38));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 1:
        case 2:
        case 0x11:
            task->state2 = 3;
            break;
        default:
            task->state2 = 9;
            break;
        }
        break;
    case 3:
        if (Check(task->_38, task->_39) == 0) {
            task->state2 = 4;
        }
        break;
    case 4:
        fn_800ACD64(CARDGetResultCode(task->_38));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state2 = 5;
            break;
        case 0x10:
        default:
            task->state2 = 9;
            break;
        }
        break;
    case 5:
        if (lbl_803C7838.error == 0x11) {
            if (ReadSerial(task->_38) != CARD_RESULT_BUSY) {
                if (lbl_803C7838.slots[task->_38].serial != 0) {
                    if (lbl_803C7838.slots[task->_38].serial == lbl_802EF2C0[task->_38]) {
                        task->state2 = 6;
                    } else {
                        lbl_803C7838.error = 0x10;
                        task->state2 = 9;
                    }
                } else {
                    lbl_803C7838.error = 0x10;
                    task->state2 = 9;
                }
            }
        } else {
            task->state2 = 9;
        }
        break;
    case 6:
        if (lbl_803CC15C != NULL) {
            result = lbl_803CC15C(task->buf, task->size, lbl_803CC158);
            if (result != 0x11) {
                lbl_803C7838.error = result;
                task->state2 = 9;
                break;
            }
        }
        sub = fn_800B0A5C_insertQueue(fn_800ABF44, 0xFF);
        memset(&sub->state, 0, 0x2C);
        task->state2 = 7;
        lbl_803CC1B8->result = 0;
        break;
    case 7:
        switch (task->result) {
        case 0:
            break;
        case 1:
            task->state2 = 8;
            break;
        case 2:
            task->state2 = 9;
            break;
        }
        break;
    case 8:
        fn_800ACD64(CARDUnmount(task->_38));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state2 = 9;
            break;
        case 0x10:
        default:
            task->state2 = 9;
            break;
        }
        break;
    case 9:
        fn_800ACFB0(lbl_803CC16C);
        lbl_803CC1B8->parent->result = 1;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x800AAEE4 size:0x108
void fn_800AAEE4(struct McardRequest* req, u64 serial) {
    McardTask* task;
    u8 retries;

    if (req->size % 0x200 != 0) {
        OSPanic("mcard.c", 2082, "MemoryCard SaveSize Error!!");
    }
    lbl_803C7838.op = 1;
    task = fn_800B0A5C_insertQueue(fn_800AAFEC, 0xFF);
    task->_38 = req->chan;
    task->_39 = req->async;
    task->buf = req->buf;
    task->size = req->size;
    retries = req->retries;
    if (retries == 0) {
        retries = 4;
    }
    task->_3A = retries;
    lbl_802EF2C0[task->_38] = serial;
    lbl_803CC15C = req->callback;
    lbl_803CC158 = req->_14;
    lbl_803CC160 = req->_18;
    lbl_803CC1B8->result = 0;
}

// .text:0x800AAA70 size:0x474
void fn_800AAA70(void) {
    McardTask* task = lbl_803CC1B8;
    u8 chan;
    u32 result;
    McardTask* sub;

    switch (task->state2) {
    case 0:
        chan = task->_3C;
        fn_800ACD64(CARDUnmount(chan));
        switch (CheckSlot(chan)) {
        case 0:
            break;
        case 1:
            task->state2 = 1;
            break;
        case 2:
            task->state2 = 9;
            break;
        }
        break;
    case 1:
        if (Mount(task->_3C, task->_3D) == 0) {
            task->state2 = 2;
        }
        break;
    case 2:
        fn_800ACD64(CARDGetResultCode(task->_3C));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 1:
        case 2:
        case 0x11:
            task->state2 = 3;
            break;
        default:
            task->state2 = 9;
            break;
        }
        break;
    case 3:
        if (Check(task->_3C, task->_3D) == 0) {
            task->state2 = 4;
        }
        break;
    case 4:
        fn_800ACD64(CARDGetResultCode(task->_3C));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state2 = 5;
            break;
        case 0x10:
        default:
            task->state2 = 9;
            break;
        }
        break;
    case 5:
        if (lbl_803C7838.error == 0x11) {
            if (ReadSerial(task->_3C) != CARD_RESULT_BUSY) {
                if (lbl_803C7838.slots[task->_3C].serial != 0) {
                    if (lbl_803C7838.slots[task->_3C].serial == lbl_802EF2C0[task->_3C]) {
                        task->state2 = 6;
                    } else {
                        lbl_803C7838.error = 0x10;
                        task->state2 = 9;
                    }
                } else {
                    lbl_803C7838.error = 0x10;
                    task->state2 = 9;
                }
            }
        } else {
            task->state2 = 9;
        }
        break;
    case 6:
        sub = fn_800B0A5C_insertQueue(fn_800ABBD0, 0xFF);
        memset(&sub->state, 0, 0x2C);
        task->state2 = 7;
        lbl_803CC1B8->result = 0;
        break;
    case 7:
        switch (task->result) {
        case 0:
            break;
        case 1:
            if (lbl_803CC15C != NULL) {
                result = lbl_803CC15C(task->buf, task->size, lbl_803CC158);
                if (result != 0x11) {
                    lbl_803C7838.error = result;
                    goto fail;
                }
            }
            task->state2 = 8;
            break;
        case 2:
        fail:
            task->state2 = 9;
            break;
        }
        break;
    case 8:
        fn_800ACD64(CARDUnmount(task->_3C));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state2 = 9;
            break;
        case 0x10:
        default:
            task->state2 = 9;
            break;
        }
        break;
    case 9:
        task->parent->result = 1;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x800AA930 size:0x140
void fn_800AA930(struct McardRequest* req, u64 serial) {
    char name[0x21];
    McardTask* task;

    if (req->size % 0x200 != 0) {
        OSPanic("mcard.c", 2416, "MemoryCard LoadSize Error!!");
    }
    strncpy(name, req->name, 0x20);
    name[0x20] = 0;
    if (strlen(name) >= 0x20) {
        OSPanic("mcard.c", 2425, "MemoryCard FileName Error!!");
    }
    task = fn_800B0A5C_insertQueue(fn_800AAA70, 0xFF);
    task->_3C = req->chan;
    task->_3D = req->async;
    task->buf = req->buf;
    task->size = req->size;
    task->name = lbl_802EF2D0;
    memcpy(task->name, req->name, 0x20);
    lbl_802EF2C0[req->chan] = serial;
    lbl_803CC15C = req->callback;
    lbl_803CC158 = req->_14;
    lbl_803CC160 = req->_18;
    lbl_803CC1B8->result = 0;
}

// .text:0x800AA44C size:0x4E4
void fn_800AA44C(void) {
    McardTask* task = lbl_803CC1B8;
    u8 chan;

    switch (task->state) {
    case 0:
        chan = task->chan;
        fn_800ACD64(CARDUnmount(chan));
        switch (CheckSlot(chan)) {
        case 0:
            break;
        case 1:
            task->state = 1;
            break;
        case 2:
            task->state = 8;
            break;
        }
        break;
    case 1:
        if (Mount(task->chan, task->async) == 0) {
            task->state = 2;
        }
        break;
    case 2:
        fn_800ACD64(CARDGetResultCode(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 1:
        case 2:
        case 0x11:
            task->state = 3;
            break;
        default:
            task->state = 8;
            break;
        }
        break;
    case 3:
        if (Check(task->chan, task->async) == 0) {
            task->state = 4;
        }
        break;
    case 4:
        fn_800ACD64(CARDGetResultCode(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state = 5;
            break;
        case 0x10:
        default:
            task->state = 8;
            break;
        }
        break;
    case 5:
        if (lbl_803C7838.error == 0x11) {
            if (ReadSerial(task->chan) != CARD_RESULT_BUSY) {
                if (lbl_803C7838.slots[task->chan].serial != 0) {
                    if (lbl_802EF2C0[task->chan] == 0) {
                        task->state = 6;
                    } else if (lbl_803C7838.slots[task->chan].serial == lbl_802EF2C0[task->chan]) {
                        task->state = 6;
                    } else {
                        lbl_803C7838.error = 0x10;
                        task->state = 8;
                    }
                } else {
                    task->state = 8;
                }
            }
        } else {
            task->state = 8;
        }
        break;
    case 6:
        switch (FindFile(task->chan, task->fileName)) {
        case 0:
            task->_1A.flag = 1;
            task->state = 7;
            break;
        case 1:
            task->state = 7;
            break;
        case 2:
            task->state = 8;
            break;
        }
        break;
    case 7:
        fn_800ACD64(CARDUnmount(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            if (task->_1A.flag == 1) {
                lbl_803C7838.error = 8;
            }
            task->state = 8;
            break;
        case 0x10:
        default:
            task->state = 8;
            break;
        }
        break;
    case 8:
        task->parent->result = 1;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x800AA34C size:0x100
void fn_800AA34C(u8 chan, u8 async, char* fileName, u64 serial, u8 checkSerial) {
    char name[0x21];
    McardTask* task;

    lbl_803C7838.op = 5;
    strncpy(name, fileName, 0x20);
    name[0x20] = 0;
    if (strlen(name) >= 0x20) {
        OSPanic("mcard.c", 2666, "MemoryCard FileName Error!!");
    }
    task = fn_800B0A5C_insertQueue(fn_800AA44C, 0xFF);
    memset(&task->state, 0, 0x2C);
    task->chan = chan;
    task->async = async;
    task->fileName = lbl_802EF2D0;
    memcpy(task->fileName, fileName, 0x20);
    if (checkSerial) {
        lbl_802EF2C0[chan] = serial;
    }
    lbl_803CC1B8->result = 0;
}

// .text:0x800A9ECC size:0x480
void fn_800A9ECC(void) {
    McardTask* task = lbl_803CC1B8;
    u8 chan;

    switch (task->state) {
    case 0:
        chan = task->chan;
        fn_800ACD64(CARDUnmount(chan));
        switch (CheckSlot(chan)) {
        case 0:
            break;
        case 1:
            task->state = 1;
            break;
        case 2:
            task->state = 9;
            break;
        }
        break;
    case 1:
        if (Mount(task->chan, task->async) == 0) {
            task->state = 2;
        }
        break;
    case 2:
        fn_800ACD64(CARDGetResultCode(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 1:
        case 2:
        case 0x11:
            task->state = 3;
            break;
        default:
            task->state = 9;
            break;
        }
        break;
    case 3:
        if (Check(task->chan, task->async) == 0) {
            task->state = 4;
        }
        break;
    case 4:
        fn_800ACD64(CARDGetResultCode(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        default:
            task->state = 5;
            break;
        }
        break;
    case 5:
        if (lbl_803C7838.error == 0x11) {
            if (ReadSerial(task->chan) != CARD_RESULT_BUSY) {
                if (lbl_803C7838.slots[task->chan].serial == lbl_802EF2C0[task->chan]) {
                    task->state = 6;
                } else {
                    lbl_803C7838.error = 0x10;
                    task->state = 9;
                }
            }
        } else {
            task->state = 6;
        }
        break;
    case 6:
        if (Format(task->chan, task->async) == 0) {
            task->state = 7;
        }
        break;
    case 7:
        fn_800ACD64(CARDGetResultCode(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            ReadSerial(task->chan);
            task->state = 8;
            break;
        case 3:
            lbl_803C7838.error = 0xD;
            task->state = 9;
            break;
        default:
            lbl_803C7838.error = 0xC;
            task->state = 9;
            break;
        }
        break;
    case 8:
        fn_800ACD64(CARDUnmount(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state = 0xA;
            break;
        case 0x10:
        default:
            task->state = 9;
            break;
        }
        break;
    case 9:
        task->state = 0xA;
        break;
    case 0xA:
        task->parent->result = 1;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x800A9E34 size:0x98
void fn_800A9E34(u8 chan, u8 async, u64 serial) {
    McardTask* task;

    lbl_803C7838.op = 4;
    task = fn_800B0A5C_insertQueue(fn_800A9ECC, 0xFF);
    memset(&task->state, 0, 0x2C);
    task->chan = chan;
    task->async = async;
    lbl_802EF2C0[chan] = serial;
    lbl_803CC1B8->result = 0;
}

// .text:0x800A9CF8 size:0x13C
void fn_800A9CF8(void) {
    char* name = lbl_802EF330.fileName;
    McardTask* task = lbl_803CC1B8;
    McardTask* parent = task->parent;
    s32 result;

    switch (task->state) {
    case 0:
        if (parent->async == 1) {
            result = CARDDeleteAsync(parent->chan, name, NULL);
            if (result < 0) {
                fn_800ACD64(result);
                task->state = 3;
            } else {
                task->state += 1;
            }
        } else {
            result = CARDFastDelete(parent->chan, name);
            if (result < 0) {
                fn_800ACD64(result);
                task->state = 3;
            } else {
                task->state += 2;
            }
        }
        break;
    case 1:
        fn_800ACD64(CARDGetResultCode(parent->chan));
        switch (lbl_803CC1B8->result) {
        case 0xF:
            break;
        case 0x11:
            task->state += 1;
            break;
        default:
        case 0x10:
            task->state = 3;
            break;
        }
        break;
    case 2:
        parent->result = 1;
        fn_800B0A14_removeQueue();
        break;
    case 3:
        parent->result = 2;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x800A98FC size:0x3FC
void fn_800A98FC(void) {
    McardTask* task = lbl_803CC1B8;
    McardTask* sub;
    u8 chan;

    switch (task->state) {
    case 0:
        chan = task->chan;
        fn_800ACD64(CARDUnmount(chan));
        switch (CheckSlot(chan)) {
        case 0:
            break;
        case 1:
            task->state = 1;
            break;
        case 2:
            task->state = 9;
            break;
        }
        break;
    case 1:
        if (Mount(task->chan, task->async) == 0) {
            task->state = 2;
        }
        break;
    case 2:
        fn_800ACD64(CARDGetResultCode(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 1:
        case 2:
        case 0x11:
            task->state = 3;
            break;
        default:
            task->state = 9;
            break;
        }
        break;
    case 3:
        if (Check(task->chan, task->async) == 0) {
            task->state = 4;
        }
        break;
    case 4:
        fn_800ACD64(CARDGetResultCode(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        default:
            task->state = 5;
            break;
        }
        break;
    case 5:
        if (lbl_803C7838.error == 0x11) {
            if (ReadSerial(task->chan) != CARD_RESULT_BUSY) {
                if (lbl_803C7838.slots[task->chan].serial == lbl_802EF2C0[task->chan]) {
                    task->state = 6;
                } else {
                    lbl_803C7838.error = 0x10;
                    task->state = 9;
                }
            }
        } else {
            task->state = 6;
        }
        break;
    case 6:
        sub = fn_800B0A5C_insertQueue(fn_800A9CF8, 0xFF);
        memset(&sub->state, 0, 0x2C);
        lbl_803CC1B8->result = 0;
        task->state = 7;
        break;
    case 7:
        switch (task->result) {
        case 0:
            break;
        case 1:
            task->state = 8;
            break;
        case 2:
            task->state = 9;
            break;
        }
        break;
    case 8:
        fn_800ACD64(CARDUnmount(task->chan));
        switch (lbl_803C7838.error) {
        case 0xF:
            break;
        case 0x11:
            task->state = 0xA;
            break;
        case 0x10:
        default:
            task->state = 9;
            break;
        }
        break;
    case 9:
        task->state = 0xA;
        break;
    case 0xA:
        task->parent->result = 1;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x800A9864 size:0x98
void fn_800A9864(u8 chan, u8 async, u64 serial) {
    McardTask* task;

    lbl_803C7838.op = 6;
    task = fn_800B0A5C_insertQueue(fn_800A98FC, 0xFF);
    memset(&task->state, 0, 0x2C);
    task->chan = chan;
    task->async = async;
    lbl_802EF2C0[chan] = serial;
    lbl_803CC1B8->result = 0;
}
