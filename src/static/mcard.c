#include "static/mcard.h"
#include "Dolphin/os.h"
#include "Dolphin/card.h"
#include "string.h"

typedef struct McardTask {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct McardTask* parent;
    /* 0x10 */ s16 result;
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ s32 state;
    /* 0x18 */ u8 chan;
    /* 0x19 */ u8 async;
    /* 0x1A */ s16 fileNo;
    /* 0x1C */ char* fileName;
    /* 0x20 */ u8 _20[0xC];
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

typedef struct McardSlot {
    /* 0x00 */ u64 serial;
    /* 0x08 */ s32 probe;
    /* 0x0C */ s32 memSize;
    /* 0x10 */ s32 sectorSize;
    /* 0x14 */ u8 _14[0x28 - 0x14];
} McardSlot;

typedef struct McardState {
    /* 0x00 */ McardSlot slots[2];
    /* 0x50 */ s32 lastResult;
    /* 0x54 */ u8 error;
    /* 0x55 */ u8 op;
    /* 0x56 */ u8 _56[0x60 - 0x56];
} McardState;

extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800B0A14_removeQueue(void);
extern McardTask* lbl_803CC1B8;
extern McardState lbl_803C7838;
extern u64 lbl_802EF2C0[2];
extern char lbl_802EF2D0[0x20];

const u16 lbl_800E7800[256] = {
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
void fn_800AC508(void) {
}

// .text:0x800ABF44 size:0x5C4
void fn_800ABF44(void) {
}

// .text:0x800ABBD0 size:0x374
void fn_800ABBD0(void) {
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
}

// .text:0x800AB474 size:0xC0
void fn_800AB474(u8 chan, u8 async, s16 fileNo, char* fileName, u64 serial) {
    McardTask* task;

    lbl_803C7838.op = 3;
    task = fn_800B0A5C_insertQueue(fn_800AB534, 0xFF);
    memset(&task->state, 0, 0x2C);
    task->chan = chan;
    task->async = async;
    task->fileNo = fileNo;
    task->fileName = lbl_802EF2D0;
    memcpy(task->fileName, fileName, 0x20);
    lbl_802EF2C0[chan] = serial;
    lbl_803CC1B8->result = 0;
}

// .text:0x800AAFEC size:0x488
void fn_800AAFEC(void) {
}

// .text:0x800AAEE4 size:0x108
void fn_800AAEE4(void) {
}

// .text:0x800AAA70 size:0x474
void fn_800AAA70(void) {
}

// .text:0x800AA930 size:0x140
void fn_800AA930(void) {
}

// .text:0x800AA44C size:0x4E4
void fn_800AA44C(void) {
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
}

// .text:0x800A98FC size:0x3FC
void fn_800A98FC(void) {
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
