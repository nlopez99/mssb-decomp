#include "menus/rep_01A0.h"
#include "header_rep_data.h"
#include "musyx/musyx.h"
#include "musyx/seq.h"

typedef struct {
    /* 0x0 */ u16 _0; // sound group
    /* 0x2 */ u16 _2; // song
    /* 0x4 */ u16 _4; // index into lbl_2_bss_D984
} UnkSeq01A0; // size: 0x6

typedef struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ f32 _14;
} UnkTask01A0;

UnkSeq01A0 lbl_2_data_128[2] = {
    { 0x1F, 0x13, 0 },
    { 0x1F, 0x14, 1 },
};
SND_VOICEID lbl_2_data_134 = SND_ID_ERROR;

u8 lbl_2_bss_1C;
f32 lbl_2_bss_18;

extern s16 lbl_2_bss_D958[];
extern SND_SEQID lbl_2_bss_D974[4];
extern void** lbl_2_bss_D984;
extern void* lbl_803CC1B8;

extern bool32 sndSeqGetValid(s32 seqID);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800B0A14_removeQueue(void);

// .text:0x000010AC size:0x50
void fn_2_10AC(void** files) {
    s32 i;

    files[0] = (u8*)files[0] + (u32)files;
    files[1] = (u8*)files[1] + (u32)files;
    for (i = 0; i < 4; i++) {
        lbl_2_bss_D974[i] = SND_ID_ERROR;
        lbl_2_bss_D958[i] = -1;
    }
    lbl_2_bss_D984 = files;
}

// .text:0x00001018 size:0x94
void fn_2_1018(u16 index) {
    if (lbl_2_bss_D974[index] != SND_ID_ERROR) {
        if (sndSeqGetValid(lbl_2_bss_D974[index])) {
            sndSeqVolume(0, 0, lbl_2_bss_D974[index], 1);
            sndSeqStop(lbl_2_bss_D974[index]);
        }
        lbl_2_bss_D974[index] = SND_ID_ERROR;
        lbl_2_bss_D958[index] = -1;
    }
}

// .text:0x00000F64 size:0xB4
void fn_2_F64(void) {
    u16 i;

    for (i = 0; i < 4; i++) {
        fn_2_1018(i);
    }
}

// .text:0x00000E84 size:0xE0
void fn_2_E84(u16 index, s16 song) {
    UnkSeq01A0* seq = &lbl_2_data_128[song];

    fn_2_1018(index);
    lbl_2_bss_D974[index] = sndSeqPlayEx(seq->_0, seq->_2, lbl_2_bss_D984[seq->_4], NULL, 0);
    lbl_2_bss_D958[index] = song;
}

// .text:0x00000D88 size:0xFC
void fn_2_D88(u16 index, s16 song) {
    if (song != lbl_2_bss_D958[index] || !sndSeqGetValid(lbl_2_bss_D974[index])) {
        fn_2_E84(index, song);
    }
}

// .text:0x00000D08 size:0x80
void fn_2_D08(u16 index, u16 time, u8 mode) {
    if (lbl_2_bss_D974[index] != SND_ID_ERROR && sndSeqGetValid(lbl_2_bss_D974[index])) {
        sndSeqVolume(0, time, lbl_2_bss_D974[index], mode);
    }
}

// .text:0x00000C74 size:0x94
void fn_2_C74(u8 volume) {
    if (lbl_2_data_134 != SND_ID_ERROR && lbl_2_data_134 == sndFXCheck(lbl_2_data_134)) {
        sndFXCtrl(lbl_2_data_134, 7, volume);
    } else {
        lbl_2_bss_18 = volume;
    }
}

// .text:0x00000C18 size:0x5C
void fn_2_C18(void) {
    if (lbl_2_data_134 != SND_ID_ERROR && lbl_2_data_134 == sndFXCheck(lbl_2_data_134)) {
        sndFXKeyOff(lbl_2_data_134);
        lbl_2_data_134 = SND_ID_ERROR;
    }
}

// .text:0x00000B38 size:0xE0
void fn_2_B38(void) {
    lbl_2_bss_18 += ((UnkTask01A0*)lbl_803CC1B8)->_14;
    if (lbl_2_bss_18 < 0.0f) {
        lbl_2_bss_18 = 0.0f;
    }
    sndFXCtrl(lbl_2_data_134, 7, lbl_2_bss_18);
    if (lbl_2_bss_18 == 0.0f) {
        lbl_2_bss_1C = 0;
        fn_2_C18();
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00000A70 size:0xC8
void fn_2_A70(u16 frames) {
    UnkTask01A0* task;

    if (!lbl_2_bss_1C && lbl_2_data_134 != SND_ID_ERROR && lbl_2_data_134 == sndFXCheck(lbl_2_data_134)) {
        task = fn_800B0A5C_insertQueue(fn_2_B38, 0x8000);
        if (frames == 0) {
            frames = 1;
        }
        task->_14 = -lbl_2_bss_18 / frames;
        lbl_2_bss_1C = 1;
    }
}
