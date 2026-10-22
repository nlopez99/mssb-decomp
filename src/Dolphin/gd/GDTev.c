#include "Dolphin/gd/GDBase.h"

#define BP_ALPHA_COMPARE(ref0, ref1, comp0, comp1, op, id)                                                            \
	((u32)(ref0) << 0 | (u32)(ref1) << 8 | (u32)(comp0) << 16 | (u32)(comp1) << 19 | (u32)(op) << 22                 \
	 | (u32)(id) << 24)

// .text:0x800A1E3C size:0x104
void GDSetAlphaCompare(GXCompare comp0, u8 ref0, GXAlphaOp op, GXCompare comp1, u8 ref1)
{
	GDWriteBPCmd(BP_ALPHA_COMPARE(ref0, ref1, comp0, comp1, op, 0xF3));
}
