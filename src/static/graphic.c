#include "static/graphic.h"
#include "Dolphin/os.h"
#include "Dolphin/gx.h"
#include "Dolphin/vi.h"
#include "Dolphin/PPCArch.h"

typedef struct DrawLink {
    u32 next : 30;
    u32 field : 1;
    u32 skip : 1;
} DrawLink;

typedef struct DrawNode {
    /* 0x0 */ u32 link;
    /* 0x4 */ void (*draw)(struct DrawNode* node);
} DrawNode;

typedef struct Graphic {
    /* 0x000 */ void* xfb;
    /* 0x004 */ void* fifoBase;
    /* 0x008 */ GXFifoObj* fifo;
    /* 0x00C */ GXRenderModeObj* rmode;
    /* 0x010 */ GXRenderModeObj rmodeObj;
    /* 0x04C */ u32* drawList;
    /* 0x050 */ void* heapLo;
    /* 0x054 */ void* heapHi;
    /* 0x058 */ u32 heapSize;
    /* 0x05C */ OSThreadQueue retraceQueue;
    /* 0x064 */ u8 _064[0x68 - 0x64];
    /* 0x068 */ OSThread drawThread;
    /* 0x380 */ OSThreadQueue drawQueue;
    /* 0x388 */ OSSemaphore drawSem;
    /* 0x394 */ u8 retraceInterval;
    /* 0x395 */ s8 retraceCount;
    /* 0x396 */ u8 drawing;
    /* 0x397 */ u8 field;
} Graphic;

extern Graphic lbl_803C7420;
extern u8 lbl_802ED140[0x2000];
GXColor lbl_803CBAD0 = { 0, 0, 0, 0xFF };

extern void fn_800AD054(void* lo, void* hi);

// .text:0x800A84C4 size:0x54
void fn_800A84C4(u32 retraceCount) {
    if (lbl_803C7420.drawing == 0) {
        if (--lbl_803C7420.retraceCount < 0) {
            lbl_803C7420.retraceCount = lbl_803C7420.retraceInterval;
            OSWakeupThread(&lbl_803C7420.retraceQueue);
        }
    }
}

// .text:0x800A80E8 size:0x3DC
void initRenderMode(GXRenderModeObj* rmode, u32 fifoSize, s32 overscan) {
    void* arenaLo;
    void* arenaHi;
    u32 xfbSize;
    u8* heapLo;

    lbl_803C7420.retraceInterval = 0;
    lbl_803C7420.retraceCount = 0;
    OSCreateThread(&lbl_803C7420.drawThread, (void* (*)(void*))fn_800A7C08, NULL, lbl_802ED140 + 0x2000, 0x2000, 12,
                   OS_THREAD_ATTR_DETACH);
    OSInitThreadQueue(&lbl_803C7420.drawQueue);
    OSInitSemaphore(&lbl_803C7420.drawSem, 0);
    OSResumeThread(&lbl_803C7420.drawThread);
    OSInitThreadQueue(&lbl_803C7420.retraceQueue);
    VIInit();
    if (rmode != NULL) {
        lbl_803C7420.rmode = rmode;
    } else {
        switch (VIGetTvFormat()) {
        case VI_NTSC:
            lbl_803C7420.rmode = &GXNtsc480IntDf;
            break;
        case VI_PAL:
            lbl_803C7420.rmode = &GXPal528IntDf;
            break;
        case VI_MPAL:
            lbl_803C7420.rmode = &GXMpal480IntDf;
            break;
        default:
            OSPanic("graphic.c", 96, "sNp_InitRenderMode: invalid TV format\n");
            break;
        }
        GXAdjustForOverscan(lbl_803C7420.rmode, &lbl_803C7420.rmodeObj, 0, overscan);
        lbl_803C7420.rmode = &lbl_803C7420.rmodeObj;
    }
    arenaLo = OSGetArenaLo();
    arenaHi = OSGetArenaHi();
    xfbSize = ((u16)(lbl_803C7420.rmode->fbWidth + 15) & ~15) * lbl_803C7420.rmode->xfbHeight * 2;
    lbl_803C7420.xfb = (void*)(((u32)arenaLo + 0x1F) & ~0x1F);
    heapLo = (u8*)(((u32)lbl_803C7420.xfb + xfbSize + 0x1F) & ~0x1F);
    lbl_803C7420.fifoBase = heapLo;
    lbl_803C7420.fifo = GXInit(heapLo, fifoSize);
    heapLo += fifoSize;
    fn_800AD054(heapLo, arenaHi);
    lbl_803C7420.heapLo = heapLo;
    lbl_803C7420.heapHi = arenaHi;
    lbl_803C7420.heapSize = (((u8*)arenaHi - heapLo) + 0x1F) & ~0x1F;
    OSSetArenaLo(arenaHi);
    VIConfigure(lbl_803C7420.rmode);
    VISetPreRetraceCallback(fn_800A84C4);
    if (lbl_803C7420.rmode->aa) {
        GXSetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
    } else {
        GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
    }
    GXSetDispCopySrc(0, 0, lbl_803C7420.rmode->fbWidth, lbl_803C7420.rmode->efbHeight);
    GXSetDispCopyDst(lbl_803C7420.rmode->fbWidth, lbl_803C7420.rmode->xfbHeight);
    GXSetDispCopyYScale((f32)lbl_803C7420.rmode->xfbHeight / (f32)lbl_803C7420.rmode->efbHeight);
    GXSetCopyFilter(lbl_803C7420.rmode->aa, lbl_803C7420.rmode->sample_pattern, GX_TRUE, lbl_803C7420.rmode->vfilter);
    GXSetDispCopyGamma(GX_GM_1_0);
    GXCopyDisp(lbl_803C7420.xfb, GX_TRUE);
    VISetNextFrameBuffer(lbl_803C7420.xfb);
    VIFlush();
    VIWaitForRetrace();
    if (lbl_803C7420.rmode->viTVmode & 1) {
        VIWaitForRetrace();
    }
    GXSetScissorBoxOffset(0, 0);
    GXSetScissor(0, 0, lbl_803C7420.rmode->fbWidth, lbl_803C7420.rmode->efbHeight);
    GXSetViewport(0.0f, 0.0f, lbl_803C7420.rmode->fbWidth, lbl_803C7420.rmode->xfbHeight, 0.0f, 1.0f);
    GXSetCopyClear(lbl_803CBAD0, 0xFFFFFF);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    VISetBlack(FALSE);
}

static inline void SetupCopy(void) {
    GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
    GXSetDispCopySrc(0, 0, lbl_803C7420.rmode->fbWidth, lbl_803C7420.rmode->efbHeight);
    GXSetDispCopyDst(lbl_803C7420.rmode->fbWidth, lbl_803C7420.rmode->xfbHeight);
    GXSetDispCopyYScale((f32)lbl_803C7420.rmode->xfbHeight / (f32)lbl_803C7420.rmode->efbHeight);
    GXSetScissor(0, 0, lbl_803C7420.rmode->fbWidth, lbl_803C7420.rmode->efbHeight);
    GXSetCopyFilter(lbl_803C7420.rmode->aa, lbl_803C7420.rmode->sample_pattern, GX_TRUE, lbl_803C7420.rmode->vfilter);
}

// .text:0x800A7F10 size:0x1D8
void fn_800A7F10(s32 arg0) {
    if (arg0) {
        fn_800A7E00();
        return;
    }
    VIConfigure(lbl_803C7420.rmode);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
    SetupCopy();
}

// .text:0x800A7E00 size:0x110
void fn_800A7E00(void) {
    GXAdjustForOverscan(&GXNtsc480Int, &lbl_803C7420.rmodeObj, 0, 16);
    lbl_803C7420.rmode = &lbl_803C7420.rmodeObj;
    VIConfigure(&lbl_803C7420.rmodeObj);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
    SetupCopy();
}

// .text:0x800A7DB0 size:0x50
void fn_800A7DB0(void) {
    OSSleepThread(&lbl_803C7420.retraceQueue);
    GXSetColorUpdate(GX_TRUE);
    VIFlush();
    GXDrawDone();
    GXCopyDisp(lbl_803C7420.xfb, GX_TRUE);
}

// .text:0x800A7D7C size:0x34
void fn_800A7D7C(u32* list, s32 count) {
    s32 i = count - 1;

    lbl_803C7420.drawList = list;
    do {
        *list = (u32)(list + 1) | 1;
        list++;
    } while (--i);
    *list = 0;
}

// .text:0x800A7D4C size:0x30
void fn_800A7D4C(s32 index, u32* entry) {
    ((DrawLink*)entry)->next = ((DrawLink*)lbl_803C7420.drawList)[index].next;
    lbl_803C7420.drawList[index] = (u32)entry | 1;
}

// .text:0x800A7C08 size:0x144
void fn_800A7C08(void) {
    GXRenderModeObj* rmode;
    DrawNode* node;
    u32 link;

    lbl_803C7420.field = 0;
    while (TRUE) {
        OSSleepThread(&lbl_803C7420.drawQueue);
        GXSetCurrentGXThread();
        rmode = lbl_803C7420.rmode;
        lbl_803C7420.drawing = 1;
        if (rmode->field_rendering) {
            GXSetViewportJitter(0.0f, 0.0f, rmode->fbWidth, rmode->efbHeight, 0.0f, 1.0f, VIGetNextField());
        } else {
            GXSetViewport(0.0f, 0.0f, rmode->fbWidth, rmode->efbHeight, 0.0f, 1.0f);
        }
        GXInvalidateVtxCache();
        node = (DrawNode*)lbl_803C7420.drawList;
        while (TRUE) {
            link = node->link;
            if (link == 0) {
                break;
            }
            if (!(link & 1) && (link & 2) == lbl_803C7420.field && node->draw != NULL) {
                node->draw(node);
            }
            node = (DrawNode*)(link & ~3);
        }
        lbl_803C7420.drawing = 0;
        OSSignalSemaphore(&lbl_803C7420.drawSem);
    }
}

// .text:0x800A7BAC size:0x5C
void fn_800A7BAC(u8 arg0) {
    if (arg0) {
        lbl_803C7420.field = 2;
    } else {
        lbl_803C7420.field = 0;
    }
    PPCSync();
    OSWakeupThread(&lbl_803C7420.drawQueue);
}
