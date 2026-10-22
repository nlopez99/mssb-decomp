#ifndef __STATIC_STATIC_800A8518_H_
#define __STATIC_STATIC_800A8518_H_

#include "mssbTypes.h"
#include "Dolphin/dvd.h"

// One queued audio stream track
typedef struct StreamEntry {
    /* 0x00 */ struct StreamEntry* prev;
    /* 0x04 */ struct StreamEntry* next;
    /* 0x08 */ u32 flags;
    /* 0x0C */ void (*callback)(u32 event);
    /* 0x10 */ DVDFileInfo fileInfo;
    /* 0x4C */ char** path;
} StreamEntry; // size: 0x50

BOOL fn_800A8518(s32 cmd);
void fn_800A86B4(s32 cmd);
u16 fn_800A8864(void);
void fn_800A8878(u8 left, u8 right);
struct StreamEntry* fn_800A88C0(void);
s32 fn_800A88C8(void);
u32 fn_800A88D0(void);
void fn_800A88D8(s32 cmd);
void fn_800A8AB0(u32 mode);
void fn_800A8AB8(void (*callback)(void));
s32 fn_800A8B78(struct StreamEntry* entry);
s32 LoadFile(char** path, struct StreamEntry* entry, u32 flags, void (*callback)(u32 event), s32 unique);
s32 fn_800A8E30(char** path, struct StreamEntry* entry, u32 flags, void (*callback)(u32 event));
void fn_800A8F68(void);
void fn_800A8FDC(s32 result, DVDCommandBlock* block);
void fn_800A9034(s32 result, DVDCommandBlock* block);
void fn_800A908C(s32 result, DVDCommandBlock* block);
void fn_800A90E4(s32 result, DVDCommandBlock* block);
void fn_800A9168(u32 count);
void fn_800A91B0(s32 result, DVDCommandBlock* block);
void fn_800A93AC(s32 result, DVDFileInfo* fileInfo);
void fn_800A9424(s32 result, DVDFileInfo* fileInfo);
void fn_800A94A8(s32 result, DVDCommandBlock* block);

#endif // !__STATIC_STATIC_800A8518_H_
