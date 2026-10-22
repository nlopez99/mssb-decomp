#include "C3/static_800BDE8C.h"

// In .bss that splits.txt cannot give this unit yet (see the report)
extern ShadowState lbl_803009F8;

// .text:0x800BDE8C size:0x14
void fn_800BDE8C(u32 arg0) {
    lbl_803009F8._4C = (arg0 & 7) << 5;
}

// .text:0x800BDEA0 size:0xD0
void fn_800BDEA0(void) {
    if (lbl_803009F8.enabled) {
        if (lbl_803009F8._20 != NULL) {
            lbl_803009F8._20(lbl_803009F8.entries->view, 0);
        }
        GXSetTexCopySrc(0, 0, 640, 448);
        GXSetTexCopyDst(640, 480, GX_CTF_R4, GX_FALSE);
        GXCopyTex(*lbl_803009F8.copyBuf, GX_TRUE);
        GXPixModeSync();
        lbl_803009F8._24 = 0;
        lbl_803009F8.range[0].min = lbl_803009F8.range[1].min = lbl_803009F8.range[2].min = 100000000.0f;
        lbl_803009F8.range[0].max = lbl_803009F8.range[1].max = lbl_803009F8.range[2].max = -100000000.0f;
        lbl_803009F8.center.x = lbl_803009F8.center.y = lbl_803009F8.center.z = 0.0f;
    }
}

// .text:0x800BDF70 size:0x70
void fn_800BDF70(ActorSlot* slot) {
    if (lbl_803009F8.enabled && lbl_803009F8._1C != NULL && slot->_6C && (slot->actor->_98 & 0x24) && (slot->actor->_98 & 0x12)) {
        lbl_803009F8._1C(slot, lbl_803009F8.entries->view);
    }
}

// .text:0x800BDFE0 size:0xBC
// 95.00%: registers only; the target gives group r29 and i r28 (and saves r28 later). int,
// a slot pointer and a group copy were tried.
void fn_800BDFE0(ActorGroup* group) {
    s32 i;

    if (lbl_803009F8.enabled && lbl_803009F8._1C != NULL) {
        for (i = 0; i < group->count; i++) {
            if (group->slots[i]._6C && (group->slots[i].actor->_98 & 0x24) && (group->slots[i].actor->_98 & 0x12)) {
                lbl_803009F8._1C(&group->slots[i], lbl_803009F8.entries->view);
            }
        }
    }
}

// .text:0x800BE09C size:0xBC
void fn_800BE09C(void) {}

// .text:0x800BE158 size:0x340
void fn_800BE158(void) {}

// .text:0x800BE498 size:0x56C
void fn_800BE498(void) {}

// .text:0x800BEA04 size:0x138
void fn_800BEA04(Vec pos) {
    lbl_803009F8.range[0].min = lbl_803009F8.range[0].min <= pos.x ? lbl_803009F8.range[0].min : pos.x;
    lbl_803009F8.range[0].max = lbl_803009F8.range[0].max >= pos.x ? lbl_803009F8.range[0].max : pos.x;
    lbl_803009F8.range[1].min = lbl_803009F8.range[1].min <= pos.y ? lbl_803009F8.range[1].min : pos.y;
    lbl_803009F8.range[1].max = lbl_803009F8.range[1].max >= pos.y ? lbl_803009F8.range[1].max : pos.y;
    lbl_803009F8.range[2].min = lbl_803009F8.range[2].min <= pos.z ? lbl_803009F8.range[2].min : pos.z;
    lbl_803009F8.range[2].max = lbl_803009F8.range[2].max >= pos.z ? lbl_803009F8.range[2].max : pos.z;
    PSVECAdd(&lbl_803009F8.center, &pos, &lbl_803009F8.center);
    lbl_803009F8._24++;
}

// .text:0x800BEB3C size:0x44
void fn_800BEB3C(void) {
    lbl_803009F8._24 = 0;
    lbl_803009F8.range[0].min = lbl_803009F8.range[1].min = lbl_803009F8.range[2].min = 100000000.0f;
    lbl_803009F8.range[0].max = lbl_803009F8.range[1].max = lbl_803009F8.range[2].max = -100000000.0f;
    lbl_803009F8.center.x = lbl_803009F8.center.y = lbl_803009F8.center.z = 0.0f;
}

// .text:0x800BEB80 size:0x20
MtxPtr fn_800BEB80(u8 index) {
    return lbl_803009F8.entries[index].mtx;
}

// .text:0x800BEBA0 size:0x10
u8 fn_800BEBA0(void) {
    return lbl_803009F8.enabled;
}

// .text:0x800BEBB0 size:0x10
u8 GetDrawShadows(void) {
    return lbl_803009F8.enabled;
}

// .text:0x800BEBC0 size:0xC
void DrawShadows(u8 enable) {
    lbl_803009F8.enabled = enable;
}

// .text:0x800BEBCC size:0x34
// 79.23%: the target loads the Vec's three words before the entry address and stores them
// after; a Vec pointer, a state pointer and a local copy compile the same as this.
void fn_800BEBCC(u8 index, Vec pos) {
    lbl_803009F8.entries[index].pos = pos;
}

// .text:0x800BEC00 size:0x30
void fn_800BEC00(s32 arg0) {
    if (arg0 != 0) {
        lbl_803009F8._4D = -1;
    } else {
        lbl_803009F8._4D = 1;
    }
}

// .text:0x800BEC30 size:0x3D8
void fn_800BEC30(void) {}

// .text:0x800BF008 size:0x30
void fn_800BF008(void) {
    GXLoadTlut(lbl_803009F8.tlut, GX_TLUT15);
}

// .text:0x800BF038 size:0x10
void fn_800BF038(void (*arg0)(MtxPtr view, s32 arg1)) {
    lbl_803009F8._20 = arg0;
}

// .text:0x800BF048 size:0x10
void fn_800BF048(void* arg0) {
    lbl_803009F8._18 = arg0;
}

// .text:0x800BF058 size:0x10
void fn_800BF058(ShadowCallback arg0) {
    lbl_803009F8._1C = arg0;
}

// .text:0x800BF068 size:0xC
ShadowState* fn_800BF068(void) {
    return &lbl_803009F8;
}
