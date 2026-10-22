#include "C3/static_800BF074.h"
#include "string.h"


typedef struct TexHeaderEntry {
    /* 0x00 */ u16 id;
    /* 0x02 */ u8 _02[2];
    /* 0x04 */ u32 _04;
    /* 0x08 */ u32 _08;
    /* 0x0C */ u8 _0C[0x20 - 0x0C];
} TexHeaderEntry; // size: 0x20

// .text:0x800BF074 size:0x130
void SKNLoadFile(sHdr* hdr) {
    SK1List* sk1;
    u32 i;
    SK2List* sk2;
    SKAccList* skAcc;

    if (hdr->sk1ListArray) {
        hdr->sk1ListArray = (SK1List*)((u32)hdr->sk1ListArray + (u32)hdr);
    }
    if (hdr->sk2ListArray) {
        hdr->sk2ListArray = (SK2List*)((u32)hdr->sk2ListArray + (u32)hdr);
    }
    if (hdr->skAccListArray) {
        hdr->skAccListArray = (SKAccList*)((u32)hdr->skAccListArray + (u32)hdr);
    }
    if (hdr->flushIndices) {
        hdr->flushIndices = (void*)((u32)hdr->flushIndices + (u32)hdr);
    }
    for (i = 0; i < hdr->numSk1List; i++) {
        sk1 = &hdr->sk1ListArray[i];
        sk1->vertSrc = (void*)((u32)sk1->vertSrc + (u32)hdr);
    }
    for (i = 0; i < hdr->numSk2List; i++) {
        sk2 = &hdr->sk2ListArray[i];
        sk2->vertSrc = (void*)((u32)sk2->vertSrc + (u32)hdr);
        sk2->weights = (void*)((u32)sk2->weights + (u32)hdr);
    }
    for (i = 0; i < hdr->numSkAccList; i++) {
        skAcc = &hdr->skAccListArray[i];
        skAcc->vertSrc = (void*)((u32)skAcc->vertSrc + (u32)hdr);
        skAcc->weights = (void*)((u32)skAcc->weights + (u32)hdr);
        skAcc->vertIndices = (void*)((u32)skAcc->vertIndices + (u32)hdr);
    }
    SKNInit();
}

// .text:0x800BF1A4 size:0x1C
asm void SKNFlushByIndex1(register u16* indices, register u32 count, register void* base) {
    nofralloc
    mtctr r4
    subi r3, r3, 0x2
L_800BF1AC:
    lhzu r6, 0x2(r3)
    mulli r7, r6, 0x18
    dcbf r7, r5
    bdnz L_800BF1AC
    blr
}

// .text:0x800BF1C0 size:0x28
asm void SKNFlushByIndex2(register u16* indices, register u32 count, register void* base) {
    nofralloc
    mtctr r4
    subi r3, r3, 0x2
L_800BF1C8:
    lhzu r6, 0x2(r3)
    add r7, r6, r6
    add r6, r7, r6
    add r6, r6, r6
    add r6, r6, r6
    dcbf r6, r5
    bdnz L_800BF1C8
    blr
}

// .text:0x800BF1E8 size:0x1C
asm void SKNBzero32B(register void* base, register u32 size) {
    nofralloc
    li r0, 0x0
    srwi r4, r4, 5
    mtctr r4
L_800BF1F4:
    dcbz r0, r3
    addi r3, r3, 0x20
    bdnz L_800BF1F4
    blr
}

// .text:0x800BF204 size:0xA4
void SKNInit(void) {
    if (!(PPCMfhid2() & 0x10000000)) {
        DCInvalidateRange((void*)0xE0000000, 0x4000);
        LCEnable();
    }
    lbl_803CB724[0] = (void*)0xE0000000;
    lbl_803CB724[1] = (void*)(0xE0000000 + 0x1000);
    lbl_803CB724[2] = (void*)(0xE0000000 + 0x2000);
    lbl_803CB724[3] = (void*)(0xE0000000 + 0x3000);
    lbl_803CB6FC[0].src = (s16*)0xE0000000;
    lbl_803CB6FC[0].indices = (u16*)(0xE0000000 + 0x1000);
    lbl_803CB6FC[0].weights = (u8*)(0xE0000000 + 0x1800);
    lbl_803CB6FC[1].src = (s16*)(0xE0000000 + 0x2000);
    lbl_803CB6FC[1].indices = (u16*)(0xE0000000 + 0x3000);
    lbl_803CB6FC[1].weights = (u8*)(0xE0000000 + 0x3800);
    GQRSetup5(8, 4, 8, 4);
}

// .text:0x800BF2A8 size:0x5F4
// 92.36%: the SKNIt draft with s16 vertices. Same differences as SKNIt.
void fn_800BF2A8(sBone** bones, sHdr* hdr, char* positionArray) {
    u32 i;
    u16 size[2];
    SK1List* sk1;
    SK2List* sk2;
    SKAccList* skAcc;

    GQRSetup6(hdr->posNrmShift, 7, hdr->posNrmShift, 7);
    if (hdr->numSk1List) {
        sk1 = hdr->sk1ListArray;
        size[0] = SKNLCTouchData(0, sk1->vertSrc, sk1->vertSrcOffset + sk1->count * 0xC);
        for (i = 0; i < hdr->numSk1List - 1; i++) {
            size[(i + 1) & 1] = SKNLCTouchData(((i + 1) & 1) * 2, hdr->sk1ListArray[i + 1].vertSrc, hdr->sk1ListArray[i + 1].vertSrcOffset + hdr->sk1ListArray[i + 1].count * 0xC);
            sk1 = &hdr->sk1ListArray[i];
            PSMTXReorder(bones[sk1->boneIndex]->skinMtx, (f32(*)[3])sk1->m);
            LCQueueWait(1);
            fn_800BFF9C(sk1->m, (s16*)(sk1->vertSrcOffset + (u32)lbl_803CB724[(i & 1) * 2]), (s16*)(sk1->vertSrcOffset + (u32)lbl_803CB724[(i & 1) * 2]), sk1->count);
            LCStoreData((void*)((u32)sk1->vertDst + (u32)positionArray), lbl_803CB724[(i & 1) * 2], size[i & 1]);
        }
        sk1 = &hdr->sk1ListArray[i];
        PSMTXReorder(bones[sk1->boneIndex]->skinMtx, (f32(*)[3])sk1->m);
        fn_800BFF9C(sk1->m, (s16*)(sk1->vertSrcOffset + (u32)lbl_803CB724[(i & 1) * 2]), (s16*)(sk1->vertSrcOffset + (u32)lbl_803CB724[(i & 1) * 2]), sk1->count);
        LCStoreData((void*)((u32)sk1->vertDst + (u32)positionArray), lbl_803CB724[(i & 1) * 2], size[i & 1]);
    }
    if (hdr->numSk2List) {
        sk2 = hdr->sk2ListArray;
        size[0] = SKNLC2TouchData(0, sk2->vertSrc, sk2->vertSrcOffset + sk2->count * 0xC);
        sk2 = hdr->sk2ListArray;
        SKNLC2TouchData(1, sk2->weights, sk2->count * 2);
        for (i = 0; i < hdr->numSk2List - 1; i++) {
            sk2 = &hdr->sk2ListArray[i];
            size[(i + 1) & 1] = SKNLC2TouchData(((i + 1) & 1) * 2, hdr->sk2ListArray[i + 1].vertSrc, hdr->sk2ListArray[i + 1].vertSrcOffset + hdr->sk2ListArray[i + 1].count * 0xC);
            SKNLC2TouchData(((i + 1) & 1) * 2 + 1, hdr->sk2ListArray[i + 1].weights, hdr->sk2ListArray[i + 1].count * 2);
            PSMTXReorder(bones[sk2->bone0Index]->skinMtx, (f32(*)[3])sk2->m0);
            PSMTXReorder(bones[sk2->bone1Index]->skinMtx, (f32(*)[3])sk2->m1);
            LCQueueWait(2);
            SKNLC2Vecs16Norms16(sk2->m0, sk2->m1, (i & 1) * 2, (s16*)(positionArray + (u32)sk2->vertDst), sk2->count, sk2->vertSrcOffset, size[i & 1]);
        }
        sk2 = &hdr->sk2ListArray[i];
        PSMTXReorder(bones[sk2->bone0Index]->skinMtx, (f32(*)[3])sk2->m0);
        PSMTXReorder(bones[sk2->bone1Index]->skinMtx, (f32(*)[3])sk2->m1);
        LCQueueWait(0);
        SKNLC2Vecs16Norms16(sk2->m0, sk2->m1, (i & 1) * 2, (s16*)(positionArray + (u32)sk2->vertDst), sk2->count, sk2->vertSrcOffset, size[i & 1]);
    }
    if (hdr->numSkAccList) {
        if (hdr->skBzeroSize) {
            SKNBzero32B((char*)((u32)hdr->skBzeroBase + (u32)positionArray), (hdr->skBzeroSize + 0x1F) & 0x07FFFFFF);
        }
        skAcc = hdr->skAccListArray;
        SKNLCAccTouchData(0, skAcc->vertSrc, skAcc->vertIndices, skAcc->weights, skAcc->count);
        LCQueueWait(0);
        for (i = 0; i < hdr->numSkAccList - 1; i++) {
            SKNLCAccTouchData((i + 1) & 1, hdr->skAccListArray[i + 1].vertSrc, hdr->skAccListArray[i + 1].vertIndices, hdr->skAccListArray[i + 1].weights, hdr->skAccListArray[i + 1].count);
            skAcc = &hdr->skAccListArray[i];
            PSMTXReorder(bones[skAcc->boneIndex]->skinMtx, (f32(*)[3])skAcc->m);
            SKNAccVecs16Norms16Iu162(skAcc->m, skAcc->count, lbl_803CB6FC[i & 1].src, (s16*)((u32)skAcc->vertDst + (u32)positionArray), lbl_803CB6FC[i & 1].indices, lbl_803CB6FC[i & 1].weights);
        }
        skAcc = &hdr->skAccListArray[i];
        PSMTXReorder(bones[skAcc->boneIndex]->skinMtx, (f32(*)[3])skAcc->m);
        SKNAccVecs16Norms16Iu162(skAcc->m, skAcc->count, lbl_803CB6FC[i & 1].src, (s16*)((u32)skAcc->vertDst + (u32)positionArray), lbl_803CB6FC[i & 1].indices, lbl_803CB6FC[i & 1].weights);
        DCStoreRange((char*)((u32)hdr->skBzeroBase + (u32)positionArray), (hdr->skBzeroSize + 0x1F) & 0x07FFFFFF);
        if (hdr->flushCount) {
            SKNFlushByIndex2(hdr->flushIndices, hdr->flushCount, (char*)((u32)hdr->skAccListArray->vertDst + (u32)positionArray));
        }
    }
}

// SKNLCAccTouchData for 0x18-byte vertices
static inline void SKNLCAccTouchDataF32(u8 buffer, s16* src, u16* indices, u8* weights, u32 count) {
    LCLoadBlocks(lbl_803CB6FC[buffer].src, src, ((count * 0x18) + 0x1F) >> 5);
    LCLoadBlocks(lbl_803CB6FC[buffer].indices, indices, ((count * 2) + 0x1F) >> 5);
    LCLoadBlocks(lbl_803CB6FC[buffer].weights, weights, (count + 0x1F) >> 5);
}

// .text:0x800BF89C size:0x5F4
// 92.36%: the target computes each vertDst + positionArray and count just before their calls and
// loads lbl_803CB724[buffer] again after SKN2Vecs16Norms16NoTouch (the inlines precompute them);
// the next sk2 touch computes ((i + 1) & 1) * 2 once and its size as offset + (count * 0x18 + 0x1F).
void SKNIt(sBone** bones, sHdr* hdr, char* positionArray) {
    u32 i;
    u16 size[2];
    SK1List* sk1;
    SK2List* sk2;
    SKAccList* skAcc;

    GQRSetup7(hdr->posNrmShift, 0, hdr->posNrmShift, 0);
    if (hdr->numSk1List) {
        sk1 = hdr->sk1ListArray;
        size[0] = SKNLCTouchData(0, sk1->vertSrc, sk1->vertSrcOffset + sk1->count * 0x18);
        for (i = 0; i < hdr->numSk1List - 1; i++) {
            size[(i + 1) & 1] = SKNLCTouchData(((i + 1) & 1) * 2, hdr->sk1ListArray[i + 1].vertSrc, hdr->sk1ListArray[i + 1].vertSrcOffset + hdr->sk1ListArray[i + 1].count * 0x18);
            sk1 = &hdr->sk1ListArray[i];
            PSMTXReorder(bones[sk1->boneIndex]->skinMtx, (f32(*)[3])sk1->m);
            LCQueueWait(1);
            SKN1Vecs16Norms16(sk1->m, (s16*)(sk1->vertSrcOffset + (u32)lbl_803CB724[(i & 1) * 2]), (s16*)(sk1->vertSrcOffset + (u32)lbl_803CB724[(i & 1) * 2]), sk1->count);
            LCStoreData((void*)((u32)sk1->vertDst + (u32)positionArray), lbl_803CB724[(i & 1) * 2], size[i & 1]);
        }
        sk1 = &hdr->sk1ListArray[i];
        PSMTXReorder(bones[sk1->boneIndex]->skinMtx, (f32(*)[3])sk1->m);
        SKN1Vecs16Norms16(sk1->m, (s16*)(sk1->vertSrcOffset + (u32)lbl_803CB724[(i & 1) * 2]), (s16*)(sk1->vertSrcOffset + (u32)lbl_803CB724[(i & 1) * 2]), sk1->count);
        LCStoreData((void*)((u32)sk1->vertDst + (u32)positionArray), lbl_803CB724[(i & 1) * 2], size[i & 1]);
    }
    if (hdr->numSk2List) {
        sk2 = hdr->sk2ListArray;
        size[0] = SKNLC2TouchData(0, sk2->vertSrc, sk2->vertSrcOffset + sk2->count * 0x18);
        sk2 = hdr->sk2ListArray;
        SKNLC2TouchData(1, sk2->weights, sk2->count * 2);
        for (i = 0; i < hdr->numSk2List - 1; i++) {
            sk2 = &hdr->sk2ListArray[i];
            size[(i + 1) & 1] = SKNLC2TouchData(((i + 1) & 1) * 2, hdr->sk2ListArray[i + 1].vertSrc, hdr->sk2ListArray[i + 1].vertSrcOffset + hdr->sk2ListArray[i + 1].count * 0x18);
            SKNLC2TouchData(((i + 1) & 1) * 2 + 1, hdr->sk2ListArray[i + 1].weights, hdr->sk2ListArray[i + 1].count * 2);
            PSMTXReorder(bones[sk2->bone0Index]->skinMtx, (f32(*)[3])sk2->m0);
            PSMTXReorder(bones[sk2->bone1Index]->skinMtx, (f32(*)[3])sk2->m1);
            LCQueueWait(2);
            SKNLC2Vecs16Norms16(sk2->m0, sk2->m1, (i & 1) * 2, (s16*)(positionArray + (u32)sk2->vertDst), sk2->count, sk2->vertSrcOffset, size[i & 1]);
        }
        sk2 = &hdr->sk2ListArray[i];
        PSMTXReorder(bones[sk2->bone0Index]->skinMtx, (f32(*)[3])sk2->m0);
        PSMTXReorder(bones[sk2->bone1Index]->skinMtx, (f32(*)[3])sk2->m1);
        LCQueueWait(0);
        SKNLC2Vecs16Norms16(sk2->m0, sk2->m1, (i & 1) * 2, (s16*)(positionArray + (u32)sk2->vertDst), sk2->count, sk2->vertSrcOffset, size[i & 1]);
    }
    if (hdr->numSkAccList) {
        if (hdr->skBzeroSize) {
            SKNBzero32B((char*)((u32)hdr->skBzeroBase + (u32)positionArray), (hdr->skBzeroSize + 0x1F) & 0x07FFFFFF);
        }
        skAcc = hdr->skAccListArray;
        SKNLCAccTouchDataF32(0, skAcc->vertSrc, skAcc->vertIndices, skAcc->weights, skAcc->count);
        LCQueueWait(0);
        for (i = 0; i < hdr->numSkAccList - 1; i++) {
            SKNLCAccTouchDataF32((i + 1) & 1, hdr->skAccListArray[i + 1].vertSrc, hdr->skAccListArray[i + 1].vertIndices, hdr->skAccListArray[i + 1].weights, hdr->skAccListArray[i + 1].count);
            skAcc = &hdr->skAccListArray[i];
            PSMTXReorder(bones[skAcc->boneIndex]->skinMtx, (f32(*)[3])skAcc->m);
            SKNAccVecs16Norms16Iu161(skAcc->m, skAcc->count, lbl_803CB6FC[i & 1].src, (s16*)((u32)skAcc->vertDst + (u32)positionArray), lbl_803CB6FC[i & 1].indices, lbl_803CB6FC[i & 1].weights);
        }
        skAcc = &hdr->skAccListArray[i];
        PSMTXReorder(bones[skAcc->boneIndex]->skinMtx, (f32(*)[3])skAcc->m);
        SKNAccVecs16Norms16Iu161(skAcc->m, skAcc->count, lbl_803CB6FC[i & 1].src, (s16*)((u32)skAcc->vertDst + (u32)positionArray), lbl_803CB6FC[i & 1].indices, lbl_803CB6FC[i & 1].weights);
        DCStoreRange((char*)((u32)hdr->skBzeroBase + (u32)positionArray), (hdr->skBzeroSize + 0x1F) & 0x07FFFFFF);
        if (hdr->flushCount) {
            SKNFlushByIndex1(hdr->flushIndices, hdr->flushCount, (char*)((u32)hdr->skAccListArray->vertDst + (u32)positionArray));
        }
    }
}

// .text:0x800BFE90 size:0x10C
asm void SKN1Vecs16Norms16(register Mtx34 m, register s16* srcBase, register s16* dstBase, register u32 count) {
    nofralloc
    stwu r1, -0x40(r1)
    stfd f14, 0x8(r1)
    stfd f15, 0x10(r1)
    subi r6, r6, 0x1
    stfd f16, 0x18(r1)
    stfd f17, 0x20(r1)
    stfd f18, 0x28(r1)
    mtctr r6
    psq_l f0, 0x0(r3), 0, 0
    subi r4, r4, 0x8
    psq_l f1, 0x8(r3), 1, 0
    subi r5, r5, 0x4
    psq_l f6, 0x24(r3), 0, 0
    psq_lu f8, 0x8(r4), 0, 7
    psq_l f7, 0x2c(r3), 1, 0
    psq_lu f9, 0x8(r4), 0, 7
    ps_madds0 f11, f0, f8, f6
    psq_l f2, 0xc(r3), 0, 0
    ps_madds0 f12, f1, f8, f7
    psq_l f3, 0x14(r3), 1, 0
    ps_muls1 f13, f0, f9
    psq_lu f10, 0x8(r4), 0, 7
    ps_muls1 f14, f1, f9
    psq_l f5, 0x20(r3), 1, 0
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_l f4, 0x18(r3), 0, 0
    ps_madds0 f13, f2, f10, f13
    psq_lu f8, 0x8(r4), 0, 7
    ps_madds0 f14, f3, f10, f14
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    psq_lu f9, 0x8(r4), 0, 7
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_lu f10, 0x8(r4), 0, 7
L_800BFF20:
    ps_madds0 f11, f0, f8, f6
    psq_stu f15, 0x4(r5), 0, 7
    ps_madds0 f12, f1, f8, f7
    psq_stu f16, 0x8(r5), 1, 7
    ps_muls1 f13, f0, f9
    psq_stu f17, 0x4(r5), 0, 7
    ps_muls1 f14, f1, f9
    psq_stu f18, 0x8(r5), 1, 7
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_lu f8, 0x8(r4), 0, 7
    ps_madds0 f13, f2, f10, f13
    ps_madds0 f14, f3, f10, f14
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    psq_lu f9, 0x8(r4), 0, 7
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_lu f10, 0x8(r4), 0, 7
    bdnz L_800BFF20
    psq_stu f15, 0x4(r5), 0, 7
    psq_stu f16, 0x8(r5), 1, 7
    psq_stu f17, 0x4(r5), 0, 7
    psq_stu f18, 0x8(r5), 1, 7
    lfd f14, 0x8(r1)
    lfd f15, 0x10(r1)
    lfd f16, 0x18(r1)
    lfd f17, 0x20(r1)
    lfd f18, 0x28(r1)
    addi r1, r1, 0x40
    blr
}

// .text:0x800BFF9C size:0x10C
asm void fn_800BFF9C(register Mtx34 m, register s16* srcBase, register s16* dstBase, register u32 count) {
    nofralloc
    stwu r1, -0x40(r1)
    stfd f14, 0x8(r1)
    stfd f15, 0x10(r1)
    subi r6, r6, 0x1
    stfd f16, 0x18(r1)
    stfd f17, 0x20(r1)
    stfd f18, 0x28(r1)
    mtctr r6
    psq_l f0, 0x0(r3), 0, 0
    subi r4, r4, 0x4
    psq_l f1, 0x8(r3), 1, 0
    subi r5, r5, 0x2
    psq_l f6, 0x24(r3), 0, 0
    psq_lu f8, 0x4(r4), 0, 6
    psq_l f7, 0x2c(r3), 1, 0
    psq_lu f9, 0x4(r4), 0, 6
    ps_madds0 f11, f0, f8, f6
    psq_l f2, 0xc(r3), 0, 0
    ps_madds0 f12, f1, f8, f7
    psq_l f3, 0x14(r3), 1, 0
    ps_muls1 f13, f0, f9
    psq_lu f10, 0x4(r4), 0, 6
    ps_muls1 f14, f1, f9
    psq_l f5, 0x20(r3), 1, 0
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_l f4, 0x18(r3), 0, 0
    ps_madds0 f13, f2, f10, f13
    psq_lu f8, 0x4(r4), 0, 6
    ps_madds0 f14, f3, f10, f14
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    psq_lu f9, 0x4(r4), 0, 6
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_lu f10, 0x4(r4), 0, 6
L_800C002C:
    ps_madds0 f11, f0, f8, f6
    psq_stu f15, 0x2(r5), 0, 6
    ps_madds0 f12, f1, f8, f7
    psq_stu f16, 0x4(r5), 1, 6
    ps_muls1 f13, f0, f9
    psq_stu f17, 0x2(r5), 0, 6
    ps_muls1 f14, f1, f9
    psq_stu f18, 0x4(r5), 1, 6
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_lu f8, 0x4(r4), 0, 6
    ps_madds0 f13, f2, f10, f13
    ps_madds0 f14, f3, f10, f14
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    psq_lu f9, 0x4(r4), 0, 6
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_lu f10, 0x4(r4), 0, 6
    bdnz L_800C002C
    psq_stu f15, 0x2(r5), 0, 6
    psq_stu f16, 0x4(r5), 1, 6
    psq_stu f17, 0x2(r5), 0, 6
    psq_stu f18, 0x4(r5), 1, 6
    lfd f14, 0x8(r1)
    lfd f15, 0x10(r1)
    lfd f16, 0x18(r1)
    lfd f17, 0x20(r1)
    lfd f18, 0x28(r1)
    addi r1, r1, 0x40
    blr
}

// .text:0x800C00A8 size:0x220
asm void SKN2Vecs16Norms16NoTouch(register Mtx34 m0, register Mtx34 m1, register u8* wtBase, register s16* srcBase, register s16* dstBase, register u32 count) {
    nofralloc
    stwu r1, -0xa0(r1)
    stfd f14, 0x8(r1)
    subi r9, r8, 0x1
    stfd f15, 0x10(r1)
    stfd f16, 0x18(r1)
    stfd f17, 0x20(r1)
    stfd f18, 0x28(r1)
    stfd f19, 0x30(r1)
    stfd f20, 0x38(r1)
    stfd f21, 0x40(r1)
    stfd f22, 0x48(r1)
    stfd f23, 0x50(r1)
    stfd f24, 0x58(r1)
    stfd f25, 0x60(r1)
    stfd f26, 0x68(r1)
    stfd f27, 0x70(r1)
    mtctr r9
    psq_l f0, 0x0(r3), 0, 0
    subi r6, r6, 0x8
    psq_l f1, 0x8(r3), 1, 0
    subi r7, r7, 0x4
    psq_l f6, 0x24(r3), 0, 0
    subi r5, r5, 0x2
    psq_lu f8, 0x8(r6), 0, 7
    psq_l f7, 0x2c(r3), 1, 0
    psq_lu f9, 0x8(r6), 0, 7
    psq_lu f27, 0x2(r5), 0, 5
    ps_madds0 f15, f0, f8, f6
    psq_l f2, 0xc(r3), 0, 0
    ps_madds0 f16, f1, f8, f7
    psq_l f3, 0x14(r3), 1, 0
    ps_muls1 f17, f0, f9
    psq_lu f10, 0x8(r6), 0, 7
    ps_muls1 f18, f1, f9
    psq_l f5, 0x20(r3), 1, 0
    ps_madds1 f15, f2, f8, f15
    psq_l f19, 0x0(r4), 0, 0
    ps_madds1 f16, f3, f8, f16
    psq_l f4, 0x18(r3), 0, 0
    ps_madds0 f17, f2, f10, f17
    psq_l f20, 0x8(r4), 1, 0
    ps_madds0 f18, f3, f10, f18
    psq_l f21, 0xc(r4), 0, 0
    ps_madds0 f15, f4, f9, f15
    psq_l f22, 0x14(r4), 1, 0
    ps_madds0 f16, f5, f9, f16
    psq_l f23, 0x18(r4), 0, 0
    ps_madds1 f17, f4, f10, f17
    psq_l f24, 0x20(r4), 1, 0
    ps_madds1 f18, f5, f10, f18
    psq_l f25, 0x24(r4), 0, 0
    ps_muls0 f15, f15, f27
    psq_l f26, 0x2c(r4), 1, 0
    ps_muls0 f16, f16, f27
    ps_muls0 f17, f17, f27
    ps_muls0 f18, f18, f27
    ps_madds0 f11, f19, f8, f25
    ps_madds0 f12, f20, f8, f26
    ps_muls1 f13, f19, f9
    ps_muls1 f14, f20, f9
    ps_madds1 f11, f21, f8, f11
    ps_madds1 f12, f22, f8, f12
    ps_madds0 f13, f21, f10, f13
    psq_lu f8, 0x8(r6), 0, 7
    ps_madds0 f14, f22, f10, f14
    ps_madds0 f11, f23, f9, f11
    ps_madds0 f12, f24, f9, f12
    ps_madds1 f13, f23, f10, f13
    ps_madds1 f14, f24, f10, f14
    psq_lu f9, 0x8(r6), 0, 7
    ps_madds1 f11, f11, f27, f15
    ps_madds1 f12, f12, f27, f16
    ps_madds1 f13, f13, f27, f17
    psq_lu f10, 0x8(r6), 0, 7
    ps_madds1 f14, f14, f27, f18
L_800C01D4:
    ps_madds0 f15, f0, f8, f6
    psq_stu f11, 0x4(r7), 0, 7
    ps_madds0 f16, f1, f8, f7
    psq_stu f12, 0x8(r7), 1, 7
    ps_muls1 f17, f0, f9
    psq_stu f13, 0x4(r7), 0, 7
    ps_muls1 f18, f1, f9
    psq_stu f14, 0x8(r7), 1, 7
    ps_madds1 f15, f2, f8, f15
    ps_madds1 f16, f3, f8, f16
    ps_madds0 f17, f2, f10, f17
    ps_madds0 f18, f3, f10, f18
    ps_madds0 f15, f4, f9, f15
    ps_madds0 f16, f5, f9, f16
    psq_lu f27, 0x2(r5), 0, 5
    ps_madds1 f17, f4, f10, f17
    ps_madds1 f18, f5, f10, f18
    ps_muls0 f15, f15, f27
    ps_muls0 f16, f16, f27
    ps_muls0 f17, f17, f27
    ps_muls0 f18, f18, f27
    ps_madds0 f11, f19, f8, f25
    ps_madds0 f12, f20, f8, f26
    ps_muls1 f13, f19, f9
    ps_muls1 f14, f20, f9
    ps_madds1 f11, f21, f8, f11
    ps_madds1 f12, f22, f8, f12
    ps_madds0 f13, f21, f10, f13
    psq_lu f8, 0x8(r6), 0, 7
    ps_madds0 f14, f22, f10, f14
    ps_madds0 f11, f23, f9, f11
    ps_madds0 f12, f24, f9, f12
    ps_madds1 f13, f23, f10, f13
    ps_madds1 f14, f24, f10, f14
    psq_lu f9, 0x8(r6), 0, 7
    ps_madds1 f11, f11, f27, f15
    ps_madds1 f12, f12, f27, f16
    ps_madds1 f13, f13, f27, f17
    psq_lu f10, 0x8(r6), 0, 7
    ps_madds1 f14, f14, f27, f18
    bdnz L_800C01D4
    psq_stu f11, 0x4(r7), 0, 7
    psq_stu f12, 0x8(r7), 1, 7
    psq_stu f13, 0x4(r7), 0, 7
    psq_stu f14, 0x8(r7), 1, 7
    lfd f14, 0x8(r1)
    lfd f15, 0x10(r1)
    lfd f16, 0x18(r1)
    lfd f17, 0x20(r1)
    lfd f18, 0x28(r1)
    lfd f19, 0x30(r1)
    lfd f20, 0x38(r1)
    lfd f21, 0x40(r1)
    lfd f22, 0x48(r1)
    lfd f23, 0x50(r1)
    lfd f24, 0x58(r1)
    lfd f25, 0x60(r1)
    lfd f26, 0x68(r1)
    lfd f27, 0x70(r1)
    addi r1, r1, 0xa0
    blr
}

// .text:0x800C02C8 size:0x220
asm void fn_800C02C8(register Mtx34 m0, register Mtx34 m1, register u8* wtBase, register s16* srcBase, register s16* dstBase, register u32 count) {
    nofralloc
    stwu r1, -0xa0(r1)
    stfd f14, 0x8(r1)
    subi r9, r8, 0x1
    stfd f15, 0x10(r1)
    stfd f16, 0x18(r1)
    stfd f17, 0x20(r1)
    stfd f18, 0x28(r1)
    stfd f19, 0x30(r1)
    stfd f20, 0x38(r1)
    stfd f21, 0x40(r1)
    stfd f22, 0x48(r1)
    stfd f23, 0x50(r1)
    stfd f24, 0x58(r1)
    stfd f25, 0x60(r1)
    stfd f26, 0x68(r1)
    stfd f27, 0x70(r1)
    mtctr r9
    psq_l f0, 0x0(r3), 0, 0
    subi r6, r6, 0x4
    psq_l f1, 0x8(r3), 1, 0
    subi r7, r7, 0x2
    psq_l f6, 0x24(r3), 0, 0
    subi r5, r5, 0x2
    psq_lu f8, 0x4(r6), 0, 6
    psq_l f7, 0x2c(r3), 1, 0
    psq_lu f9, 0x4(r6), 0, 6
    psq_lu f27, 0x2(r5), 0, 5
    ps_madds0 f15, f0, f8, f6
    psq_l f2, 0xc(r3), 0, 0
    ps_madds0 f16, f1, f8, f7
    psq_l f3, 0x14(r3), 1, 0
    ps_muls1 f17, f0, f9
    psq_lu f10, 0x4(r6), 0, 6
    ps_muls1 f18, f1, f9
    psq_l f5, 0x20(r3), 1, 0
    ps_madds1 f15, f2, f8, f15
    psq_l f19, 0x0(r4), 0, 0
    ps_madds1 f16, f3, f8, f16
    psq_l f4, 0x18(r3), 0, 0
    ps_madds0 f17, f2, f10, f17
    psq_l f20, 0x8(r4), 1, 0
    ps_madds0 f18, f3, f10, f18
    psq_l f21, 0xc(r4), 0, 0
    ps_madds0 f15, f4, f9, f15
    psq_l f22, 0x14(r4), 1, 0
    ps_madds0 f16, f5, f9, f16
    psq_l f23, 0x18(r4), 0, 0
    ps_madds1 f17, f4, f10, f17
    psq_l f24, 0x20(r4), 1, 0
    ps_madds1 f18, f5, f10, f18
    psq_l f25, 0x24(r4), 0, 0
    ps_muls0 f15, f15, f27
    psq_l f26, 0x2c(r4), 1, 0
    ps_muls0 f16, f16, f27
    ps_muls0 f17, f17, f27
    ps_muls0 f18, f18, f27
    ps_madds0 f11, f19, f8, f25
    ps_madds0 f12, f20, f8, f26
    ps_muls1 f13, f19, f9
    ps_muls1 f14, f20, f9
    ps_madds1 f11, f21, f8, f11
    ps_madds1 f12, f22, f8, f12
    ps_madds0 f13, f21, f10, f13
    psq_lu f8, 0x4(r6), 0, 6
    ps_madds0 f14, f22, f10, f14
    ps_madds0 f11, f23, f9, f11
    ps_madds0 f12, f24, f9, f12
    ps_madds1 f13, f23, f10, f13
    ps_madds1 f14, f24, f10, f14
    psq_lu f9, 0x4(r6), 0, 6
    ps_madds1 f11, f11, f27, f15
    ps_madds1 f12, f12, f27, f16
    ps_madds1 f13, f13, f27, f17
    psq_lu f10, 0x4(r6), 0, 6
    ps_madds1 f14, f14, f27, f18
L_800C03F4:
    ps_madds0 f15, f0, f8, f6
    psq_stu f11, 0x2(r7), 0, 6
    ps_madds0 f16, f1, f8, f7
    psq_stu f12, 0x4(r7), 1, 6
    ps_muls1 f17, f0, f9
    psq_stu f13, 0x2(r7), 0, 6
    ps_muls1 f18, f1, f9
    psq_stu f14, 0x4(r7), 1, 6
    ps_madds1 f15, f2, f8, f15
    ps_madds1 f16, f3, f8, f16
    ps_madds0 f17, f2, f10, f17
    ps_madds0 f18, f3, f10, f18
    ps_madds0 f15, f4, f9, f15
    ps_madds0 f16, f5, f9, f16
    psq_lu f27, 0x2(r5), 0, 5
    ps_madds1 f17, f4, f10, f17
    ps_madds1 f18, f5, f10, f18
    ps_muls0 f15, f15, f27
    ps_muls0 f16, f16, f27
    ps_muls0 f17, f17, f27
    ps_muls0 f18, f18, f27
    ps_madds0 f11, f19, f8, f25
    ps_madds0 f12, f20, f8, f26
    ps_muls1 f13, f19, f9
    ps_muls1 f14, f20, f9
    ps_madds1 f11, f21, f8, f11
    ps_madds1 f12, f22, f8, f12
    ps_madds0 f13, f21, f10, f13
    psq_lu f8, 0x4(r6), 0, 6
    ps_madds0 f14, f22, f10, f14
    ps_madds0 f11, f23, f9, f11
    ps_madds0 f12, f24, f9, f12
    ps_madds1 f13, f23, f10, f13
    ps_madds1 f14, f24, f10, f14
    psq_lu f9, 0x4(r6), 0, 6
    ps_madds1 f11, f11, f27, f15
    ps_madds1 f12, f12, f27, f16
    ps_madds1 f13, f13, f27, f17
    psq_lu f10, 0x4(r6), 0, 6
    ps_madds1 f14, f14, f27, f18
    bdnz L_800C03F4
    psq_stu f11, 0x2(r7), 0, 6
    psq_stu f12, 0x4(r7), 1, 6
    psq_stu f13, 0x2(r7), 0, 6
    psq_stu f14, 0x4(r7), 1, 6
    lfd f14, 0x8(r1)
    lfd f15, 0x10(r1)
    lfd f16, 0x18(r1)
    lfd f17, 0x20(r1)
    lfd f18, 0x28(r1)
    lfd f19, 0x30(r1)
    lfd f20, 0x38(r1)
    lfd f21, 0x40(r1)
    lfd f22, 0x48(r1)
    lfd f23, 0x50(r1)
    lfd f24, 0x58(r1)
    lfd f25, 0x60(r1)
    lfd f26, 0x68(r1)
    lfd f27, 0x70(r1)
    addi r1, r1, 0xa0
    blr
}

// .text:0x800C04E8 size:0x148
asm void SKNAccVecs16Norms16Iu161(register Mtx34 m, register u16 count, register s16* srcBase, register s16* dstBase, register u16* indices, register u8* weights) {
    nofralloc
    stwu r1, -0xa0(r1)
    subi r7, r7, 0x2
    stfd f14, 0x8(r1)
    lhzu r9, 0x2(r7)
    stfd f15, 0x10(r1)
    stfd f16, 0x18(r1)
    add r11, r9, r9
    stfd f17, 0x20(r1)
    add r9, r9, r11
    stfd f18, 0x28(r1)
    add r9, r9, r9
    stfd f19, 0x30(r1)
    add r9, r9, r9
    stfd f20, 0x38(r1)
    add r9, r9, r9
    stfd f21, 0x40(r1)
    add r10, r9, r6
    stfd f22, 0x48(r1)
    subi r8, r8, 0x1
    stfd f23, 0x50(r1)
    mtctr r4
    psq_l f0, 0x0(r3), 0, 0
    subi r5, r5, 0x8
    psq_l f1, 0x8(r3), 1, 0
    psq_l f6, 0x24(r3), 0, 0
    psq_l f7, 0x2c(r3), 1, 0
    psq_lu f8, 0x8(r5), 0, 7
    psq_lu f9, 0x8(r5), 0, 7
    psq_l f2, 0xc(r3), 0, 0
    psq_l f3, 0x14(r3), 1, 0
    psq_lu f10, 0x8(r5), 0, 7
    psq_l f5, 0x20(r3), 1, 0
    psq_l f4, 0x18(r3), 0, 0
L_800C056C:
    ps_madds0 f11, f0, f8, f6
    psq_lu f23, 0x1(r8), 1, 5
    ps_madds0 f12, f1, f8, f7
    ps_muls1 f13, f0, f9
    psq_l f19, 0x0(r10), 0, 7
    ps_muls1 f14, f1, f9
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_l f20, 0x8(r10), 1, 7
    ps_madds0 f13, f2, f10, f13
    ps_madds0 f14, f3, f10, f14
    psq_l f21, 0xc(r10), 0, 7
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    lhzu r9, 0x2(r7)
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_l f22, 0x14(r10), 1, 7
    ps_madds0 f19, f15, f23, f19
    psq_lu f8, 0x8(r5), 0, 7
    ps_madds0 f20, f16, f23, f20
    psq_lu f9, 0x8(r5), 0, 7
    ps_madds0 f21, f17, f23, f21
    psq_lu f10, 0x8(r5), 0, 7
    ps_madds0 f22, f18, f23, f22
    add r11, r9, r9
    psq_st f19, 0x0(r10), 0, 7
    add r9, r9, r11
    psq_st f20, 0x8(r10), 1, 7
    add r9, r9, r9
    psq_st f21, 0xc(r10), 0, 7
    add r9, r9, r9
    psq_st f22, 0x14(r10), 1, 7
    add r9, r9, r9
    dcbst r0, r10
    add r10, r9, r6
    bdnz L_800C056C
    lfd f14, 0x8(r1)
    lfd f15, 0x10(r1)
    lfd f16, 0x18(r1)
    lfd f17, 0x20(r1)
    lfd f18, 0x28(r1)
    lfd f19, 0x30(r1)
    lfd f20, 0x38(r1)
    lfd f21, 0x40(r1)
    lfd f22, 0x48(r1)
    lfd f23, 0x50(r1)
    addi r1, r1, 0xa0
    blr
}

// .text:0x800C0630 size:0x140
asm void SKNAccVecs16Norms16Iu162(register Mtx34 m, register u16 count, register s16* srcBase, register s16* dstBase, register u16* indices, register u8* weights) {
    nofralloc
    stwu r1, -0xa0(r1)
    subi r7, r7, 0x2
    stfd f14, 0x8(r1)
    lhzu r9, 0x2(r7)
    stfd f15, 0x10(r1)
    stfd f16, 0x18(r1)
    add r11, r9, r9
    stfd f17, 0x20(r1)
    add r9, r9, r11
    stfd f18, 0x28(r1)
    add r9, r9, r9
    stfd f19, 0x30(r1)
    add r9, r9, r9
    stfd f20, 0x38(r1)
    add r10, r9, r6
    stfd f21, 0x40(r1)
    subi r8, r8, 0x1
    stfd f22, 0x48(r1)
    stfd f23, 0x50(r1)
    mtctr r4
    psq_l f0, 0x0(r3), 0, 0
    subi r5, r5, 0x4
    psq_l f1, 0x8(r3), 1, 0
    psq_l f6, 0x24(r3), 0, 0
    psq_l f7, 0x2c(r3), 1, 0
    psq_lu f8, 0x4(r5), 0, 6
    psq_lu f9, 0x4(r5), 0, 6
    psq_l f2, 0xc(r3), 0, 0
    psq_l f3, 0x14(r3), 1, 0
    psq_lu f10, 0x4(r5), 0, 6
    psq_l f5, 0x20(r3), 1, 0
    psq_l f4, 0x18(r3), 0, 0
L_800C06B0:
    ps_madds0 f11, f0, f8, f6
    psq_lu f23, 0x1(r8), 1, 5
    ps_madds0 f12, f1, f8, f7
    ps_muls1 f13, f0, f9
    psq_l f19, 0x0(r10), 0, 6
    ps_muls1 f14, f1, f9
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_l f20, 0x4(r10), 1, 6
    ps_madds0 f13, f2, f10, f13
    ps_madds0 f14, f3, f10, f14
    psq_l f21, 0x6(r10), 0, 6
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    lhzu r9, 0x2(r7)
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_l f22, 0xa(r10), 1, 6
    ps_madds0 f19, f15, f23, f19
    psq_lu f8, 0x4(r5), 0, 6
    ps_madds0 f20, f16, f23, f20
    psq_lu f9, 0x4(r5), 0, 6
    ps_madds0 f21, f17, f23, f21
    psq_lu f10, 0x4(r5), 0, 6
    ps_madds0 f22, f18, f23, f22
    add r11, r9, r9
    psq_st f19, 0x0(r10), 0, 6
    add r9, r9, r11
    psq_st f20, 0x4(r10), 1, 6
    add r9, r9, r9
    psq_st f21, 0x6(r10), 0, 6
    add r9, r9, r9
    psq_st f22, 0xa(r10), 1, 6
    dcbst r0, r10
    add r10, r9, r6
    bdnz L_800C06B0
    lfd f14, 0x8(r1)
    lfd f15, 0x10(r1)
    lfd f16, 0x18(r1)
    lfd f17, 0x20(r1)
    lfd f18, 0x28(r1)
    lfd f19, 0x30(r1)
    lfd f20, 0x38(r1)
    lfd f21, 0x40(r1)
    lfd f22, 0x48(r1)
    lfd f23, 0x50(r1)
    addi r1, r1, 0xa0
    blr
}

// .text:0x800C0770 size:0x4C
void convertTextureHeader(void* tex) {
    TexHeaderEntry* entry = tex;
    int i;

    for (i = 0; i < ((TexHeaderEntry*)tex)->id; i++) {
        if (entry->_04) {
            entry->_04 = (u32)tex + entry->_04;
        }
        if (entry->_08) {
            entry->_08 = (u32)tex + entry->_08;
        }
        (++entry)->id = i;
    }
}

// .text:0x800C07BC size:0x2D0
// 89.50%: registers only; the target gives the outer level's halfSize, base2, tmp2 and half r31-r28
// and the parameters r27-r23. 200 declaration orders and a permuter session were tried.
void fn_800C07BC(void* base, void* tmp, u32 count, u32 size, s32 (*compare)(const void* a, const void* b)) {
    u32 i;
    u32 j;
    void* src;
    u32 k;
    u32 half;
    u32 halfSize;
    void* base2;
    void* tmp2;

    if (count > 1) {
        half = count >> 1;
        halfSize = half * size;
        base2 = (u8*)base + halfSize;
        tmp2 = (u8*)tmp + halfSize;
        fn_800C07BC(base, tmp, half, size, compare);
        fn_800C07BC(base2, tmp2, count - half, size, compare);
        memcpy(tmp, base, halfSize);
        i = 0;
        j = half;
        k = 0;
        while (i < half && j < count) {
            if (compare((u8*)tmp + i * size, (u8*)base + j * size) <= 0) {
                src = (u8*)tmp + i++ * size;
            } else {
                src = (u8*)base + j++ * size;
            }
            memcpy((u8*)base + k++ * size, src, size);
        }
        if (i < half) {
            memcpy((u8*)base + k * size, (u8*)tmp + i * size, size * (half - i));
        }
    }
}
