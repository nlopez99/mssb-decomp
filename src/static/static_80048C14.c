#include "static/static_80048C14.h"
#include "Dolphin/gx.h"
#include "string.h"
#include "static/UnknownHomes_Static.h"

// GX performance counters: the latest reading, and the lowest and highest since the last reset
typedef struct GXMetrics {
    /* 0x00 */ u32 cur[11];
    /* 0x2C */ u32 min[11];
    /* 0x58 */ u32 max[11];
} GXMetrics; // size: 0x84

GXPerf0 lbl_800FB4C8[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
    19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
};
GXPerf1 lbl_800FB554[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
};

GXMetrics lbl_802E4B28;

s32 lbl_803CB838 = 1;
s32 lbl_803CB83C[2] = { 0, 0 };

u32 lbl_803CBCE8;

static inline void ResetMetrics(void) {
    memset(lbl_802E4B28.max, 0, sizeof(lbl_802E4B28.max));
    memset(lbl_802E4B28.min, 0xFF, sizeof(lbl_802E4B28.min));
    lbl_803CB838 = 300;
}

// .text:0x80048EA8 size:0x10
s32 fn_80048EA8(s32 which) {
    return lbl_803CB83C[which];
}

// .text:0x80048E00 size:0xA8
s32 fn_80048E00(s32 which, s32 value) {
    s32 count = 35;

    if (which != 0) {
        count = 23;
    }
    if (value >= count) {
        value = 0;
    } else if (value < 0) {
        value = count - 1;
    }
    if (value != lbl_803CB83C[which]) {
        lbl_803CB83C[which] = value;
        ResetMetrics();
    }
    return value;
}

// .text:0x80048D4C size:0xB4
void fn_80048D4C(void) {
    if (lbl_803CBCE8 != 0) {
        GXSetGPMetric(lbl_800FB4C8[lbl_803CB83C[0]], lbl_800FB554[lbl_803CB83C[1]]);
        GXClearGPMetric();
        if (lbl_800FB4C8[lbl_803CB83C[0]] == GX_PERF0_CLOCKS) {
            GXReadGP0Metric();
        }
        if (lbl_800FB554[lbl_803CB83C[1]] == GX_PERF1_CLOCKS) {
            GXReadGP1Metric();
        }
        GXSetVCacheMetric(GX_VC_ALL);
        GXClearVCacheMetric();
        GXClearPixMetric();
    }
}

// .text:0x80048C28 size:0x124
void fn_80048C28(void) {
    s32 i;

    if (lbl_803CBCE8 != 0) {
        GXSetDrawSync(0xABCD);
        while (GXReadDrawSync() != 0xABCD) {
        }
        GXReadGPMetric(&lbl_802E4B28.cur[0], &lbl_802E4B28.cur[1]);
        GXReadVCacheMetric(&lbl_802E4B28.cur[2], &lbl_802E4B28.cur[3], &lbl_802E4B28.cur[4]);
        GXReadPixMetric(&lbl_802E4B28.cur[5], &lbl_802E4B28.cur[6], &lbl_802E4B28.cur[7], &lbl_802E4B28.cur[8],
                        &lbl_802E4B28.cur[9], &lbl_802E4B28.cur[10]);
        if (--lbl_803CB838 == 0) {
            ResetMetrics();
        }
        i = 11;
        while (i-- != 0) {
            if (lbl_802E4B28.min[i] > lbl_802E4B28.cur[i]) {
                lbl_802E4B28.min[i] = lbl_802E4B28.cur[i];
            }
            if (lbl_802E4B28.max[i] < lbl_802E4B28.cur[i]) {
                lbl_802E4B28.max[i] = lbl_802E4B28.cur[i];
            }
        }
    }
}

// .text:0x80048C1C size:0xC
// Only the early return is left; whatever followed it compiled to nothing
void fn_80048C1C(void) {
    if (lbl_803CBCE8 == 0) {
        return;
    }
}

// .text:0x80048C14 size:0x8
void fn_80048C14(u32 enable) {
    lbl_803CBCE8 = enable;
}
