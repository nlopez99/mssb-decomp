#ifndef __STATIC_DVDSYS_H_
#define __STATIC_DVDSYS_H_

#include "mssbTypes.h"
#include "Dolphin/dvd.h"

#include "Unknown/File_0x800a64e0.h"

u32 fn_800A6870(u8 on, u32 timeout);
void fn_800A6890(u32 request);
void fn_800A68D4(u32 request);
void fn_800A6900(void);
void fn_800A6C80(void);
void fn_800A6D10(s32 consumed);
void fn_800A6E24(AssetLoadInstructions* instr, u8* buf, s32 size);
void fn_800A6F94(s32 result, DVDFileInfo* fileInfo);
void* ARAMTransfer(AssetLoadInstructions* instr, void* dst, u8 mode, u32 aram);
BOOL fn_800A750C(char** path, DVDFileInfo* fileInfo);
s32 ConvertPathToEntryNum(char** path);
void fn_800A7568(void);
void fn_800A75EC(s32 result, DVDCommandBlock* block);
void fn_800A7670(s32 result, DVDCommandBlock* block);
void fn_800A76BC(void);
void fn_800A77A0(void);
void fn_800A7A80(s32 result, DVDFileInfo* fileInfo);
void fn_800A7AD4(void);

#endif // !__STATIC_DVDSYS_H_
