#include "Dolphin/gd.h"
#include "Dolphin/os.h"

GDCurrentDL* __GDCurrentDL = NULL;
GDOverflowCallback overflowcb = NULL;

// .text:0x800A1A70 size:0x18
void GDInitGDLObj(GDCurrentDL* dl, void* start, u32 length)
{
	dl->begin = start;
	dl->pDisplayListData = start;
	dl->end = (u8*)start + length;
	dl->length = length;
}

// .text:0x800A1A88 size:0xF8
void GDPadCurr32(void)
{
	u32 n = (u32)__GDCurrentDL->pDisplayListData & 31;

	if (n) {
		for (; n < 32; n++) {
			__GDWrite(0);
		}
	}
}

// .text:0x800A1B80 size:0x30
void GDOverflowed(void)
{
	if (overflowcb) {
		(*overflowcb)();
	}
}
