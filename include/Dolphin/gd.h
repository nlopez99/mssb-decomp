#ifndef _DOLPHIN_GD_H
#define _DOLPHIN_GD_H

#include "Dolphin/gx.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////////// GD TYPES //////////////////
// Overflow callback function type.
typedef void (*GDOverflowCallback)(void);

// Struct for data download (size 0x10).
typedef struct GDCurrentDL {
	u8* begin;            // _00
	s32 length;           // _04
	u8* pDisplayListData; // _08
	u8* end;              // _0C
} GDCurrentDL;

////////////////////////////////////////////

////////////// GD FUNCTIONS ////////////////
// GD base functions.
void GDInitGDLObj(GDCurrentDL* dl, void* start, u32 length);
void GDFlushCurrToMem(void);
void GDPadCurr32(void);
void GDOverflowed(void);
void GDSetOverflowCallback(GDOverflowCallback callback);
GDOverflowCallback GDGetOverflowCallback(void);

// GD geometry functions.
void GDSetVtxDescv(GXVtxDescList* list);
void GDSetArray(GXAttr attr, const void* data, u8 stride);
void GDSetArrayRaw(GXAttr attr, u32 data, u8 stride);

// GD pixel functions.
void GDSetBlendMode(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp logic_op);

// GD TEV functions.
void GDSetAlphaCompare(GXCompare comp0, u8 ref0, GXAlphaOp op, GXCompare comp1, u8 ref1);

// GD texture functions.
void GDSetTexLookupMode(GXTexMapID id, GXTexWrapMode wrap_s, GXTexWrapMode wrap_t, GXTexFilter min_filt,
                        GXTexFilter mag_filt, f32 min_lod, f32 max_lod, f32 lod_bias, u8 bias_clamp, u8 do_edge_lod,
                        GXAnisotropy max_aniso);
void GDSetTexImgAttr(GXTexMapID id, u16 width, u16 height, GXTexFmt format);
void GDSetTexImgPtr(GXTexMapID id, void* image_ptr);
void GDSetTexTlut(GXTexMapID id, u32 tmem_addr, GXTlutFmt format);
void GDSetTexCoordScale2(GXTexCoordID coord, u16 s_scale, u8 s_bias, u8 s_wrap, u16 t_scale, u8 t_bias, u8 t_wrap);
void GDLoadTlut(void* tlut_ptr, u32 tmem_addr, GXTlutSize size);

////////////////////////////////////////////

///////////// GD DECLARATIONS //////////////

extern GDCurrentDL* __GDCurrentDL;
extern GDOverflowCallback overflowcb;

////////////////////////////////////////////

/////////// GD HELPER FUNCTIONS ////////////

static inline void __GDWrite(u8 data) { *__GDCurrentDL->pDisplayListData++ = data; }

static inline void __GDCheckOverflowed(size_t size)
{
	if (__GDCurrentDL->pDisplayListData + size > __GDCurrentDL->end) {
		GDOverflowed();
	}
}

static inline void __GDSetCurrent(GDCurrentDL* obj) { __GDCurrentDL = obj; }

static inline void __GDWriteU32(u32 data)
{
	__GDWrite((data >> 24) & 0xFF);
	__GDWrite((data >> 16) & 0xFF);
	__GDWrite((data >> 8) & 0xFF);
	__GDWrite((data >> 0) & 0xFF);
}

static inline void __GDWriteU16(u16 data)
{
	__GDWrite((data >> 8) & 0xFF);
	__GDWrite((data >> 0) & 0xFF);
}

static inline void __GDWriteU8(u8 data) { __GDWrite((data >> 0) & 0xFF); }

static inline void __GDWriteF32(f32 data)
{
	__GDWrite(((u8*)&data)[0]);
	__GDWrite(((u8*)&data)[1]);
	__GDWrite(((u8*)&data)[2]);
	__GDWrite(((u8*)&data)[3]);
}

inline void GDOverflowCheck(u32 len)
{
	if (__GDCurrentDL->pDisplayListData + len > __GDCurrentDL->end) {
		GDOverflowed();
	}
}

////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
