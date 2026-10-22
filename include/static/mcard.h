#ifndef __STATIC_MCARD_H_
#define __STATIC_MCARD_H_

#include "mssbTypes.h"

struct McardRequest;

void fn_800A9864(u8 chan, u8 async, u64 serial);
void fn_800A98FC(void);
void fn_800A9CF8(void);
void fn_800A9E34(u8 chan, u8 async, u64 serial);
void fn_800A9ECC(void);
void fn_800AA34C(u8 chan, u8 async, char* fileName, u64 serial, u8 checkSerial);
void fn_800AA44C(void);
void fn_800AA930(struct McardRequest* req, u64 serial);
void fn_800AAA70(void);
void fn_800AAEE4(struct McardRequest* req, u64 serial);
void fn_800AAFEC(void);
void fn_800AB474(u8 chan, u8 async, s16 fileNo, char* fileName, u64 serial);
void fn_800AB534(void);
u16 fn_800ABB14(u8* data, s32 len);
void fn_800ABB60(void);
void fn_800ABBD0(void);
void fn_800ABF44(void);
void fn_800AC508(char* fileName, void* banner, s32 bannerSize, void* icon, u32 iconSize, s32 iconSpeed, s32 iconAnim, char* comment, char* comment2, s32 blocks);
s32 fn_800ACC6C(s32 type, s32 a, s32 b);
void fn_800ACCD4(void);
void fn_800ACCE8(void);
void fn_800ACD44(void);
void fn_800ACD64(s32 result);

#endif // !__STATIC_MCARD_H_
