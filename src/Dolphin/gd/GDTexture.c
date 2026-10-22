#include "Dolphin/gd/GDBase.h"
#include "Dolphin/os.h"

#define BP_TEX_MODE0(wrap_s, wrap_t, mag_filt, min_filt, edge_lod, lod_bias, max_aniso, bias_clamp, id)             \
	((u32)(wrap_s) << 0 | (u32)(wrap_t) << 2 | (u32)(mag_filt) << 4 | (u32)(min_filt) << 5 | (u32)(edge_lod) << 8 \
	 | (u32)(lod_bias) << 9 | (u32)(max_aniso) << 19 | (u32)(bias_clamp) << 21 | (u32)(id) << 24)

#define BP_TEX_MODE1(min_lod, max_lod, id) ((u32)(min_lod) << 0 | (u32)(max_lod) << 8 | (u32)(id) << 24)

#define BP_IMAGE_ATTR(width, height, format, id) \
	((u32)(width) << 0 | (u32)(height) << 10 | (u32)(format) << 20 | (u32)(id) << 24)

#define BP_IMAGE_PTR(ptr, id) ((u32)(ptr) << 0 | (u32)(id) << 24)

#define BP_TEX_TLUT(tmem, format, id) ((u32)(tmem) << 0 | (u32)(format) << 10 | (u32)(id) << 24)

#define BP_TEXCOORD_S_SCALE(s_scale, s_bias, s_wrap, line_offset, point_offset, id)                                 \
	((u32)(s_scale) << 0 | (u32)(s_bias) << 16 | (u32)(s_wrap) << 17 | (u32)(line_offset) << 18                     \
	 | (u32)(point_offset) << 19 | (u32)(id) << 24)

#define BP_TEXCOORD_T_SCALE(t_scale, t_bias, t_wrap, id) \
	((u32)(t_scale) << 0 | (u32)(t_bias) << 16 | (u32)(t_wrap) << 17 | (u32)(id) << 24)

#define BP_LOAD_TLUT0(ptr, id) ((u32)(ptr) << 0 | (u32)(id) << 24)

#define BP_LOAD_TLUT1(ptr, size, id) ((u32)(ptr) << 0 | (u32)(size) << 10 | (u32)(id) << 24)

u8 GDTexMode0Ids[8] = { 0x80, 0x81, 0x82, 0x83, 0xA0, 0xA1, 0xA2, 0xA3 };
u8 GDTexMode1Ids[8] = { 0x84, 0x85, 0x86, 0x87, 0xA4, 0xA5, 0xA6, 0xA7 };
u8 GDTexImage0Ids[8] = { 0x88, 0x89, 0x8A, 0x8B, 0xA8, 0xA9, 0xAA, 0xAB };
u8 GDTexImage3Ids[8] = { 0x94, 0x95, 0x96, 0x97, 0xB4, 0xB5, 0xB6, 0xB7 };
u8 GDTexTlutIds[8] = { 0x98, 0x99, 0x9A, 0x9B, 0xB8, 0xB9, 0xBA, 0xBB };

// Declared before its definition without a size, which puts the table in .data and addresses it with lis/addi.
extern u8 GD2HWFiltConv[];

// .text:0x800A1F40 size:0x254
void GDSetTexLookupMode(GXTexMapID id, GXTexWrapMode wrap_s, GXTexWrapMode wrap_t, GXTexFilter min_filt,
                        GXTexFilter mag_filt, f32 min_lod, f32 max_lod, f32 lod_bias, u8 bias_clamp, u8 do_edge_lod,
                        GXAnisotropy max_aniso)
{
	GDWriteBPCmd(BP_TEX_MODE0(wrap_s, wrap_t, mag_filt == GX_LINEAR, GD2HWFiltConv[min_filt], !do_edge_lod,
	                          (u8)(lod_bias * 32.0f), max_aniso, bias_clamp, GDTexMode0Ids[id]));
	GDWriteBPCmd(BP_TEX_MODE1((u8)(min_lod * 16.0f), (u8)(max_lod * 16.0f), GDTexMode1Ids[id]));
}

u8 GD2HWFiltConv[] = { 0, 4, 1, 5, 2, 6 };

// .text:0x800A2194 size:0x100
void GDSetTexImgAttr(GXTexMapID id, u16 width, u16 height, GXTexFmt format)
{
	GDWriteBPCmd(BP_IMAGE_ATTR(width - 1, height - 1, format, GDTexImage0Ids[id]));
}

// .text:0x800A2294 size:0xE8
void GDSetTexImgPtr(GXTexMapID id, void* image_ptr)
{
	GDWriteBPCmd(BP_IMAGE_PTR(OSCachedToPhysical(image_ptr) >> 5, GDTexImage3Ids[id]));
}

// .text:0x800A237C size:0xF0
void GDSetTexTlut(GXTexMapID id, u32 tmem_addr, GXTlutFmt format)
{
	GDWriteBPCmd(BP_TEX_TLUT((tmem_addr - 0x80000) >> 9, format, GDTexTlutIds[id]));
}

// .text:0x800A246C size:0x290
void GDSetTexCoordScale2(GXTexCoordID coord, u16 s_scale, u8 s_bias, u8 s_wrap, u16 t_scale, u8 t_bias, u8 t_wrap)
{
	GDWriteBPCmd(0xFE03FFFF);
	GDWriteBPCmd(BP_TEXCOORD_S_SCALE(s_scale - 1, s_bias, s_wrap, 0, 0, coord * 2 + 0x30));
	GDWriteBPCmd(BP_TEXCOORD_T_SCALE(t_scale - 1, t_bias, t_wrap, coord * 2 + 0x31));
}

// .text:0x800A26FC size:0x460
void GDLoadTlut(void* tlut_ptr, u32 tmem_addr, GXTlutSize size)
{
	GDWriteBPCmd(0xFEFFFF00);
	GDWriteBPCmd(0x0F000000);
	GDWriteBPCmd(BP_LOAD_TLUT0(OSCachedToPhysical(tlut_ptr) >> 5, 0x64));
	GDWriteBPCmd(BP_LOAD_TLUT1((tmem_addr - 0x80000) >> 9, size, 0x65));
	GDWriteBPCmd(0xFEFFFF00);
	GDWriteBPCmd(0x0F000000);
}
