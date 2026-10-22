#ifndef _DOLPHIN_GD_GDBASE_H
#define _DOLPHIN_GD_GDBASE_H

#include "Dolphin/gd.h"

// The SDK's display-list writers, private to the GD library's sources.

static inline void GDWrite_u8(u8 data)
{
	GDOverflowCheck(sizeof(u8));
	__GDWrite(data);
}

static inline void GDWrite_u16(u16 data)
{
	GDOverflowCheck(sizeof(u16));
	__GDWrite((u8)(data >> 8));
	__GDWrite((u8)(data & 0xFF));
}

static inline void GDWrite_u32(u32 data)
{
	GDOverflowCheck(sizeof(u32));
	__GDWrite((u8)((data >> 24) & 0xFF));
	__GDWrite((u8)((data >> 16) & 0xFF));
	__GDWrite((u8)((data >> 8) & 0xFF));
	__GDWrite((u8)((data >> 0) & 0xFF));
}

static inline void GDWriteBPCmd(u32 regval)
{
	GDWrite_u8(GX_CMD_LOAD_BP_REG);
	GDWrite_u32(regval);
}

#endif
