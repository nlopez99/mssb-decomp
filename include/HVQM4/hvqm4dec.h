#ifndef __HVQM4_HVQM4DEC_H_
#define __HVQM4_HVQM4DEC_H_

#include "types.h"

struct VideoState;

typedef struct VideoInfo {
    /* 0x0 */ struct VideoState* state;
    /* 0x4 */ u16 width;
    /* 0x6 */ u16 height;
    /* 0x8 */ u8 h_samp;
    /* 0x9 */ u8 v_samp;
} VideoInfo;

struct BitBufferWithTree;
struct StackState;
struct VideoState;
struct Plane;
struct MCPlane;

void fn_800DFDD4(void);
void fn_800E0488(void* a, void* b);
void fn_800E07E8(struct VideoInfo* info, s32 plane_idx, u8 h_samp, u8 v_samp);
void fn_800E0904(void);
s16 fn_800E0CC8(struct BitBufferWithTree* bt);
void fn_800E0D60(void);
void fn_800E10B4(struct VideoState* state);
void fn_800E11C8(void);
void fn_800E156C(u8* dst, s32 stride, u8 value, u8 top, u8 bottom, u8 left, u8 right);
void fn_800E1708(void);
void fn_800E1BB4(void);
s32 fn_800E20A0(struct VideoState* state, s32* result, u8 count, u8* nest, u32 nest_stride, s32 plane_idx);
void fn_800E2310(void);
void fn_800E2580(struct VideoState* state, u8* dst, s32 stride, u8 value, u8 type, s32 plane_idx);
void fn_800E2898(struct VideoState* state, u8* dst, s32 stride, struct StackState* stack);
void fn_800E29DC(struct VideoState* state, u8* dst, s32 stride, struct StackState* stack, s32 count);
void fn_800E2AB0(struct VideoState* state, s32 plane_idx, u8* dst);
void fn_800E2B8C(struct Plane* plane, struct MCPlane* mc, s32 a, s32 b, s32 c);
void fn_800E2C18(u8* dst, s32 dst_stride, u8* src, s32 src_stride, s32 hpel_x, s32 hpel_y);
void fn_800E32E8(struct Plane* plane, struct MCPlane* mc, s32 x, s32 y);
void fn_800E33AC(void);
void fn_800E3860(void);
void fn_800E3E3C(void);
void fn_800E40E4(void);
void fn_800E423C(void);
void fn_800E46D4(void);
void fn_800E4AC8(void* a, void* b);
void fn_800E4AE8(struct VideoInfo* info, u8* p);
u32 fn_800E4B1C(struct VideoInfo* info);
void fn_800E4B90(void);
void fn_800E4FF4(void);
void fn_800E591C(void* a, void* b, void* c, void* d);
void fn_800E5940(void* a, void* b, void* c, void* d, void* e);

#endif // !__HVQM4_HVQM4DEC_H_
