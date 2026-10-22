#ifndef _C3_STATIC_800BDE8C_H_
#define _C3_STATIC_800BDE8C_H_

#include "C3/charPipeline.h"
#include "C3/static_800BD478.h"

typedef struct ShadowEntry {
    /* 0x00 */ Vec eye;
    /* 0x0C */ Vec up;
    /* 0x18 */ Vec target;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 near;
    /* 0x30 */ f32 far;
    /* 0x34 */ Vec pos;
    /* 0x40 */ Mtx view;
    /* 0x70 */ Mtx44 proj;
    /* 0xB0 */ Mtx mtx;
} ShadowEntry; // size: 0xE0

typedef void (*ShadowCallback)(ActorSlot* slot, MtxPtr view);

typedef struct ShadowRange {
    /* 0x00 */ f32 min;
    /* 0x04 */ f32 max;
} ShadowRange;

typedef struct ShadowState {
    /* 0x00 */ u8 enabled;
    /* 0x01 */ u8 count;
    /* 0x02 */ u8 _02[0x4 - 0x2];
    /* 0x04 */ void** copyBuf;
    /* 0x08 */ GXTexObj* texObj;
    /* 0x0C */ GXTlutObj* tlut;
    /* 0x10 */ u16* tlutData;
    /* 0x14 */ ShadowEntry* entries;
    /* 0x18 */ void* _18;
    /* 0x1C */ ShadowCallback _1C;
    /* 0x20 */ void (*_20)(MtxPtr view, s32 arg1);
    /* 0x24 */ u16 _24;
    /* 0x26 */ u8 _26[2];
    /* 0x28 */ ShadowRange range[3];
    /* 0x40 */ Vec center;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ s8 _4D;
} ShadowState; // size: 0x50

void fn_800BDE8C(u32 arg0);
void fn_800BDEA0(void);
void fn_800BDF70(ActorSlot* slot);
void fn_800BDFE0(ActorGroup* group);
void fn_800BE09C(void);
void fn_800BE158(struct ShadowEntry* shadow, struct ShadowEntry* camera);
void fn_800BE498(void);
void fn_800BEA04(Vec pos);
void fn_800BEB3C(void);
MtxPtr fn_800BEB80(u8 index);
u8 fn_800BEBA0(void);
u8 GetDrawShadows(void);
void DrawShadows(u8 enable);
void fn_800BEBCC(u8 index, Vec pos);
void fn_800BEC00(s32 arg0);
void fn_800BEC30(u8 count);
void fn_800BF008(void);
void fn_800BF038(void (*arg0)(MtxPtr view, s32 arg1));
void fn_800BF048(void* arg0);
void fn_800BF058(ShadowCallback arg0);
ShadowState* fn_800BF068(void);

#endif // _C3_STATIC_800BDE8C_H_
