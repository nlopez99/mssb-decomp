#include "static/static_80062578.h"
#include "static/UnknownHomes_Static.h"
#include "static/mb_subfunc.h"
#include "static/static_80021188.h"
#include "musyx/musyx.h"
#include "Dolphin/os.h"

typedef struct PadLock {
    /* 0x00 */ struct {
        u8 _0;
        u8 port[5];
    } rows[14];
    /* 0x54 */ u8 _54;
    /* 0x55 */ u8 active[8];
    /* 0x5D */ u8 step[7];
} PadLock; // size: 0x64

typedef struct LoopSounds {
    /* 0x00 */ SND_VOICEID voice;
    /* 0x04 */ u8 playing;
    /* 0x05 */ u8 stop;
    /* 0x06 */ u8 fadeLen;
    /* 0x07 */ u8 fadeCount;
    /* 0x08 */ SND_VOICEID voice2;
    /* 0x0C */ u8 playing2;
    /* 0x0D */ u8 stop2;
} LoopSounds; // size: 0x10

extern struct {
    /* 0x000 */ s32 _00;
    /* 0x004 */ struct SoundGroupData* groups[0xE3];
    /* 0x390 */ u8 _390[8];
    /* 0x398 */ u8 _398;
} lbl_800EF808;

extern struct {
    /* 0x0000 */ u8 _0000[0x48AE];
    /* 0x48AE */ u8 _48AE;
    /* 0x48AF */ u8 _48AF[4];
    /* 0x48B3 */ u8 _48B3;
} lbl_8034E9A0;

extern s32 lbl_803C663C[4];
extern PadLock lbl_803C66B0;
extern LoopSounds lbl_803C6714;
extern u16 lbl_80108DF4[];
extern u16 lbl_80108E38[];
extern u8 lbl_80108B18[0x24];
extern u8 lbl_80108B3C[0x48];
typedef struct SoundLoadTask {
    /* 0x00 */ s32 group;
    /* 0x04 */ void* onLoad;
    /* 0x08 */ void* owner;
} SoundLoadTask;

extern SoundLoadTask lbl_80108B84;


u8 lbl_803CB888 = 0x69;
u8 lbl_803CB889 = 0x7D;

// .text:0x80062A94 size:0x150
void fn_80062A94(void) {
    if (lbl_800EF808._398 != 0) {
        if (lbl_803C6714.playing == 0) {
            lbl_803C6714.voice = sndFXStartEx(0x1E4, lbl_803CB888, 0x3F, 0);
            lbl_803C6714.playing = 1;
            lbl_803C6714.stop = 0;
            lbl_803C6714.fadeLen = 0;
            lbl_803C6714.fadeCount = 0;
        }
        if (lbl_803C6714.fadeLen != 0) {
            if (++lbl_803C6714.fadeCount >= lbl_803C6714.fadeLen) {
                lbl_803C6714.stop = 1;
            } else {
                sndFXCtrl(lbl_803C6714.voice, 7, lbl_803CB888 - lbl_803CB888 * lbl_803C6714.fadeCount / lbl_803C6714.fadeLen);
            }
        }
        if (lbl_803C6714.stop != 0) {
            sndFXKeyOff(lbl_803C6714.voice);
            lbl_803C6714.stop = 0;
            lbl_803C6714.voice = 0;
            lbl_803C6714.playing = 0;
            fn_800B0A14_removeQueue();
        }
    } else {
        sndFXKeyOff(lbl_803C6714.voice);
        lbl_803C6714.voice = 0;
        lbl_803C6714.stop = 0;
        lbl_803C6714.playing = 0;
        OSReport("sound end \n");
        fn_800B0A14_removeQueue();
    }
}

// .text:0x80062A74 size:0x20
void fn_80062A74(void) {
    lbl_803C6714.stop = 1;
    lbl_8034E9A0._48B3 = 1;
}

// .text:0x80062A50 size:0x24
void initializeUnknown(void) {
    lbl_8034E9A0._48B3 = 0;
    lbl_803C6714.voice = 0;
    lbl_803C6714.stop = 0;
    lbl_803C6714.playing = 0;
}

// .text:0x8006295C size:0xF4
void fn_8006295C(void) {
    if (lbl_800EF808._398 != 0) {
        if (lbl_803C6714.playing2 == 0) {
            lbl_803C6714.voice2 = sndFXStartEx(0, lbl_803CB889, 0x3F, 0);
            lbl_803C6714.playing2 = 1;
            lbl_803C6714.stop2 = 0;
        }
        if (lbl_803C6714.stop2 != 0) {
            sndFXKeyOff(lbl_803C6714.voice2);
            lbl_803C6714.voice2 = 0;
            lbl_803C6714.stop2 = 0;
            lbl_803C6714.playing2 = 0;
            fn_800B0A14_removeQueue();
        }
    } else {
        sndFXKeyOff(lbl_803C6714.voice2);
        lbl_803C6714.voice2 = 0;
        lbl_803C6714.stop2 = 0;
        lbl_803C6714.playing2 = 0;
        OSReport("sound end \n");
        fn_800B0A14_removeQueue();
    }
}

// .text:0x80062948 size:0x14
void fn_80062948(void) {
    lbl_803C6714.stop2 = 1;
}

// .text:0x800628D4 size:0x74
s32 fn_800628D4(s32 charID) {
    SND_VOICEID voice;
    s32 group;

    lbl_8034E9A0._48AE = 1;
    group = fn_800698F8(charID);
    voice = sndFXStartEx(lbl_80108DF4[group], lbl_80108B18[0], 0x3F, 0);
    sndFXCtrl(voice, 0x5B, 0);
    return voice;
}

// .text:0x80062890 size:0x44
s32 fn_80062890(s32 id) {
    return sndFXStartEx(lbl_80108E38[id], lbl_80108B3C[id], 0x3F, 0);
}

// .text:0x8006285C size:0x34
s32 fn_8006285C(void) {
    fn_80021518(0x20, lbl_800EF808.groups[0x25]);
    return 0;
}

// .text:0x8006282C size:0x30
void fn_8006282C(void) {
    fn_80021518(0x20, lbl_800EF808.groups[0x25]);
}

// .text:0x800627F8 size:0x34
s32 fn_800627F8(void) {
    fn_80021518(0x31, lbl_800EF808.groups[0x26]);
    return 0;
}

// .text:0x800627C4 size:0x34
s32 fn_800627C4(void) {
    fn_80021518(0, lbl_800EF808.groups[4]);
    return 0;
}

// .text:0x80062794 size:0x30
BOOL fn_80062794(SND_VOICEID voice) {
    return sndFXCheck(voice) != -1;
}

// .text:0x80062764 size:0x30
void fn_80062764(void* arg) {
    lbl_80108B84.owner = arg;
    fn_800215F8(&lbl_80108B84);
}

// .text:0x80062744 size:0x20
void fn_80062744(void) {
    lbl_803C663C[3] = 0;
    lbl_803C663C[2] = 0;
    lbl_803C663C[1] = 0;
    lbl_803C663C[0] = 0;
}

// .text:0x800626EC size:0x58
void fn_800626EC(s32 port) {
    if (g_d_GameSettings._10 == 0) {
        lbl_803C66B0.active[0] = 1;
    } else {
        lbl_803C66B0.active[port] = 1;
    }
    lbl_803C663C[port]++;
}

// .text:0x80062674 size:0x78
void fn_80062674(s32 port) {
    lbl_803C663C[port]--;
    if (lbl_803C663C[port] == 0) {
        if (g_d_GameSettings._10 == 0) {
            lbl_803C66B0.active[0] = 0;
        } else {
            lbl_803C66B0.active[port] = 0;
        }
        lbl_803C66B0.step[port] = 0;
    }
}

// .text:0x800625A4 size:0xD0
void fn_800625A4(s32 port, s32 step) {
    s32 i;
    s32 idx = g_d_GameSettings._10 == 0 ? 0 : port;

    if (lbl_803C66B0.active[idx]) {
        OSReport("パッド処理拒否中にムービー再生要求あり(%d) Step No %d \n", lbl_803C66B0.step[idx]);
    }
    lbl_803C66B0.step[port] = step;
    for (i = 0; i < 14; i++) {
        lbl_803C66B0.rows[i].port[port] = 0;
    }
}

// .text:0x80062578 size:0x2C
BOOL fn_80062578(void) {
    BOOL ret = FALSE;

    if (lbl_803C66B0.step[0] == 0 && lbl_803C66B0.step[1] == 0) {
        ret = TRUE;
    }
    return ret;
}
