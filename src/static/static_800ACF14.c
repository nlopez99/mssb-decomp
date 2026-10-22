#include "static/static_800ACF14.h"

// A heap that allocates from both ends of one arena; each block keeps the
// previous end and its own size in the 8 bytes before it.
typedef struct Heap {
    /* 0x0 */ u32 free;
    /* 0x4 */ u8* lo;
    /* 0x8 */ u8* hi;
} Heap;

extern Heap lbl_803C7898;

// .text:0x800AD054 size:0x1C
void fn_800AD054(void* lo, void* hi) {
    lbl_803C7898.lo = lo;
    lbl_803C7898.hi = hi;
    lbl_803C7898.free = (u8*)hi - (u8*)lo;
}

// .text:0x800AD038 size:0x1C
void fn_800AD038(void* lo) {
    lbl_803C7898.lo = lo;
    lbl_803C7898.free = lbl_803C7898.hi - (u8*)lo;
}

// .text:0x800AD01C size:0x1C
void fn_800AD01C(void* hi) {
    lbl_803C7898.hi = hi;
    lbl_803C7898.free = (u8*)hi - lbl_803C7898.lo;
}

// .text:0x800ACFD0 size:0x4C
// Registers only: the target computes the rounded size and align + 7 into r7/r4 first and keeps
// the heap base in r6; the permuter got closest with -align assigned inside the expression.
void* _OSAllocFromHeap(s32 align, u32 size) {
    u8* lo = lbl_803C7898.lo;
    u8* hi = lbl_803C7898.hi;
    u8* p;
    size = (size + 3) & ~3;
    p = (u8*)(((u32)lo + align + 7) & -align);
    ((u8**)p)[-2] = lo;
    ((u32*)p)[-1] = (p - lo) + size;
    lo = size + p;
    lbl_803C7898.free = hi - lo;
    lbl_803C7898.lo = lo;
    return p;
}

// .text:0x800ACFB0 size:0x20
void fn_800ACFB0(void* ptr) {
    lbl_803C7898.lo = ((u8**)ptr)[-2];
    lbl_803C7898.free = lbl_803C7898.hi - lbl_803C7898.lo;
}

// .text:0x800ACF78 size:0x38
// Registers only: the block start and the offset inside it swap r5/r6.
void fn_800ACF78(void* ptr, u32 size) {
    u8* start = ((u8**)ptr)[-2];

    size = (size + 3) & ~3;
    size += (u8*)ptr - start;
    lbl_803C7898.lo = start + size;
    lbl_803C7898.free = lbl_803C7898.hi - lbl_803C7898.lo;
    ((u32*)ptr)[-1] = size;
}

// .text:0x800ACF34 size:0x44
// Registers only: the target keeps the heap base in r5 and lo in r4.
void* fn_800ACF34(s32 align, u32 size) {
    u8* lo = lbl_803C7898.lo;
    u8* hi = lbl_803C7898.hi;
    u8* p;
    u8* block;
    size = (size + 3) & ~3;
    p = (u8*)(-align & (u32)(hi - size));
    block = p - 8;
    ((u8**)p)[-2] = hi;
    ((u32*)p)[-1] = hi - block;
    lbl_803C7898.free = block - lo;
    lbl_803C7898.hi = block;
    return p;
}

// .text:0x800ACF14 size:0x20
void fn_800ACF14(void* ptr) {
    lbl_803C7898.hi = ((u8**)ptr)[-2];
    lbl_803C7898.free = lbl_803C7898.hi - lbl_803C7898.lo;
}
