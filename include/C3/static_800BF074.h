#ifndef _C3_STATIC_800BF074_H_
#define _C3_STATIC_800BF074_H_

#include "C3/charPipeline.h"

void SKNLoadFile(sHdr* hdr);
void SKNFlushByIndex1(u16* indices, u32 count, void* base);
void SKNFlushByIndex2(u16* indices, u32 count, void* base);
void SKNBzero32B(void* base, u32 size);
void SKNInit(void);
void fn_800BF2A8(sBone** bones, sHdr* hdr, char* positionArray);
void SKNIt(sBone** bones, sHdr* hdr, char* positionArray);
void SKN1Vecs16Norms16(Mtx34 m, s16* srcBase, s16* dstBase, u32 count);
void fn_800BFF9C(Mtx34 m, s16* srcBase, s16* dstBase, u32 count);
void SKN2Vecs16Norms16NoTouch(Mtx34 m0, Mtx34 m1, u8* wtBase, s16* srcBase, s16* dstBase, u32 count);
void fn_800C02C8(Mtx34 m0, Mtx34 m1, u8* wtBase, s16* srcBase, s16* dstBase, u32 count);
void SKNAccVecs16Norms16Iu161(Mtx34 m, u16 count, s16* srcBase, s16* dstBase, u16* indices, u8* weights);
void SKNAccVecs16Norms16Iu162(Mtx34 m, u16 count, s16* srcBase, s16* dstBase, u16* indices, u8* weights);
void convertTextureHeader(void* tex);
void fn_800C07BC(void* base, void* tmp, u32 count, u32 size, s32 (*compare)(const void* a, const void* b));

#endif // _C3_STATIC_800BF074_H_
