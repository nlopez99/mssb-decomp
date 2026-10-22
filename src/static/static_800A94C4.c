#include "static/static_800A94C4.h"
#include "Dolphin/pad.h"
#include "Dolphin/OS/OSSerial.h"

typedef struct PadSticks {
    /* 0x0 */ s8 stickX;
    /* 0x1 */ s8 stickY;
    /* 0x2 */ s8 substickX;
    /* 0x3 */ s8 substickY;
} PadSticks;

typedef struct PadAnalog {
    /* 0x0 */ u8 triggerLeft;
    /* 0x1 */ u8 triggerRight;
    /* 0x2 */ u8 analogA;
    /* 0x3 */ u8 analogB;
} PadAnalog;

typedef struct PadState {
    /* 0x00 */ u16 held;
    /* 0x02 */ u16 pressed;
    /* 0x04 */ u16 repeat;
    /* 0x06 */ u16 prev;
    /* 0x08 */ s8 err;
    /* 0x09 */ u8 motorState;
    /* 0x0A */ u8 motorTime;
    /* 0x0B */ u8 motorCmd;
    /* 0x0C */ s8 repeatDelay;
    /* 0x0D */ s8 repeatTimer;
    /* 0x0E */ u8 _0E[2];
    /* 0x10 */ PadSticks sticks;
    /* 0x14 */ PadAnalog analog;
    /* 0x18 */ u32 dirs;
    /* 0x1C */ u8 _1C[4];
} PadState; // size: 0x20

typedef struct PadConfig {
    /* 0x0 */ u32 readMask;
    /* 0x4 */ u8 repeatDelay;
    /* 0x5 */ u8 repeatRate;
    /* 0x6 */ u8 motorLock;
    /* 0x7 */ s8 dirShift;
    /* 0x8 */ s8 lo;
    /* 0x9 */ s8 hi;
    /* 0xA */ u8 _A[6];
} PadConfig;

extern PadState lbl_803C77B8[4];

PadConfig lbl_80110080 = { 0, 12, 2, 0, 32, -50, 50 };

// .text:0x800A983C size:0x28
void fn_800A983C(void) {
    PADInit();
    SISetSamplingRate(0);
}

// .text:0x800A97EC size:0x50
void fn_800A97EC(s32 chan, u32 time, u8 cmd) {
    PadState* pad;

    pad = &lbl_803C77B8[chan];
    if (!(lbl_80110080.motorLock & (1 << chan))) {
        pad->motorTime = time;
        pad->motorCmd = 0;
        if (time != 0) {
            pad->motorCmd = cmd;
        }
        pad->motorState = 1;
    }
}

// .text:0x800A97D0 size:0x1C
void fn_800A97D0(s8 shift, s8 threshold) {
    lbl_80110080.dirShift = shift;
    lbl_80110080.lo = -threshold;
    lbl_80110080.hi = threshold;
}

// .text:0x800A9520 size:0x2B0
void fn_800A9520(void) {
    u32 i;
    PadState* pad;
    PADStatus* st;
    PADStatus status[4];
    u16 prev;
    u32 dirs;

    lbl_80110080.readMask = PADRead(status);
    PADClamp(status);
    st = status;
    pad = lbl_803C77B8;
    for (i = 0; i < 4; i++, pad++, st++) {
        pad->err = st->err;
        if (pad->err == PAD_ERR_NO_CONTROLLER) {
            PADReset(PAD_CHAN0_BIT >> i);
        }
        if (pad->motorState == 1) {
            pad->motorState = 0;
            if (pad->motorCmd == 0) {
                PADControlMotor(i, PAD_MOTOR_STOP_HARD);
            } else {
                PADControlMotor(i, PAD_MOTOR_RUMBLE);
                pad->motorState = 2;
            }
        } else if (pad->motorState == 2) {
            if (--pad->motorTime == 0) {
                pad->motorState = 0;
                PADControlMotor(i, pad->motorCmd & ~1);
            }
        }
        pad->analog = *(PadAnalog*)&st->triggerLeft;
        pad->sticks = *(PadSticks*)&st->stickX;
        dirs = 0;
        dirs |= (pad->sticks.stickY < lbl_80110080.lo) << 18;
        dirs |= (pad->sticks.stickY > lbl_80110080.hi) << 19;
        dirs |= (pad->sticks.stickX < lbl_80110080.lo) << 16;
        dirs |= (pad->sticks.stickX > lbl_80110080.hi) << 17;
        dirs |= (pad->sticks.substickY < lbl_80110080.lo) << 2;
        dirs |= (pad->sticks.substickY > lbl_80110080.hi) << 3;
        dirs |= (pad->sticks.substickX < lbl_80110080.lo);
        dirs |= (pad->sticks.substickX > lbl_80110080.hi) << 1;
        pad->dirs = dirs;
        prev = pad->prev;
        dirs >>= lbl_80110080.dirShift;
        pad->held = st->button | dirs;
        pad->prev = pad->held;
        pad->pressed = pad->held & ~prev;
        pad->repeat = pad->pressed;
        if (pad->prev == prev) {
            if (pad->repeatDelay < 0) {
                if (--pad->repeatTimer <= 0) {
                    pad->repeat = pad->prev;
                    pad->repeatTimer = lbl_80110080.repeatRate;
                }
            } else if (--pad->repeatDelay < 0) {
                pad->repeat = pad->prev;
                pad->repeatTimer = lbl_80110080.repeatRate;
            }
        } else {
            pad->repeatDelay = lbl_80110080.repeatDelay;
        }
    }
}

// .text:0x800A94C4 size:0x5C
void fn_800A94C4(void) {
    u32 mask = 0;
    PadState* pad = lbl_803C77B8;
    s32 i = 0;

    do {
        if (pad->err == 0) {
            mask |= PAD_CHAN0_BIT >> i;
        }
        i++;
        pad++;
    } while (i < 4);
    PADRecalibrate(mask);
}
