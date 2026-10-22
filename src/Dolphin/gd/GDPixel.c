#include "Dolphin/gd/GDBase.h"

#define BP_BLEND_MODE(enable, enable_logic, enable_dither, enable_color_update, enable_alpha_update, dst_factor,    \
                      src_factor, blend_sub, logic_op, id)                                                             \
	((u32)(enable) << 0 | (u32)(enable_logic) << 1 | (u32)(enable_dither) << 2 | (u32)(enable_color_update) << 3     \
	 | (u32)(enable_alpha_update) << 4 | (u32)(dst_factor) << 5 | (u32)(src_factor) << 8 | (u32)(blend_sub) << 11 \
	 | (u32)(logic_op) << 12 | (u32)(id) << 24)

// .text:0x800A1BB0 size:0x28C
void GDSetBlendMode(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp logic_op)
{
	GDWriteBPCmd(0xFE00FFE3);
	GDWriteBPCmd(BP_BLEND_MODE((type == GX_BM_BLEND) || (type == GX_BM_SUBTRACT), type == GX_BM_LOGIC, 0, 0, 0,
	                           dst_factor, src_factor, type == GX_BM_SUBTRACT, logic_op, 0x41));
}
