#ifndef __STATIC_STATIC_8006C100_H_
#define __STATIC_STATIC_8006C100_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

// A player's stat block: six ratings, the order they are shown in, and two bonuses
typedef struct StatBlock {
    /* 0x00 */ s16 stats[6];
    /* 0x0C */ u8 order[6];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
} StatBlock; // size: 0x16

u8 fn_8006C100(s16 value);
s16 fn_8006C13C(struct StatBlock* block);
s16 fn_8006C268(struct StatTotals* totals);
void fn_8006C2B4(struct StatTotals* out, struct StatBlock* block);
void fn_8006C398(struct StatBlock* block);
void fn_8006C3F0(void (*callback)(void* arg0, void* arg1, void* arg2));
void fn_8006C3F8(void* arg0, void* arg1, void* arg2);
void fn_8006C43C(void (*callback)(void* arg0, void* arg1, void* arg2));
void fn_8006C444(void* arg0, void* arg1, void* arg2);
void fn_8006C488(void);

#endif // !__STATIC_STATIC_8006C100_H_
