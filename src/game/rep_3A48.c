#include "game/rep_3A48.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/m_sound.h"
#include "game/rep_16B8.h"

typedef struct UnkTask3A48 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u16 _20;
    /* 0x22 */ u16 _22;
} UnkTask3A48;

typedef struct UnkSprite3A48 {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66[0x68 - 0x66];
    /* 0x68 */ u8 _68;
    /* 0x69 */ u8 _69;
} UnkSprite3A48;

typedef struct {
    /* 0x00 */ UnkSprite3A48* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef3A48; // size: 0x8

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc3A48; // size: 0x20

extern struct {
    /* 0x00 */ u8 _00[0x96];
    /* 0x96 */ u8 _96;
    /* 0x97 */ u8 _97[0xC0 - 0x97];
    /* 0xC0 */ u8 _C0;
    /* 0xC1 */ u8 _C1[0xC6 - 0xC1];
    /* 0xC6 */ u8 _C6;
    /* 0xC7 */ u8 _C7;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x000 */ u8 _000[0x1D2];
    /* 0x1D2 */ u8 _1D2;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x000 */ u8 _000[0x398];
    /* 0x398 */ u8 _398;
} lbl_800EF808;

extern UnkSpriteRef3A48 lbl_80371C30[];
extern void* lbl_803CC1B8;

// In the 0x8110-0xD5B8 block outside every unit's .data range
extern UnkSpriteDesc3A48 lbl_3_data_B1BC[];
extern u16 lbl_3_data_B3DC[6];
extern u16 lbl_3_data_B3E8[6];
extern UnkSpriteDesc3A48 lbl_3_data_B3F4[];
extern UnkSpriteDesc3A48 lbl_3_data_B85C[];
extern UnkSpriteDesc3A48 lbl_3_data_BD50[];
extern UnkSpriteDesc3A48 lbl_3_data_BD90[];
// In rep_1B20's .data range
extern u8 lbl_3_data_FAC4[8];
extern u8 lbl_3_data_FAF4[4][4];

extern void fn_80034CEC(UnkTask3A48* task);
extern void fn_80034E20(UnkTask3A48* task, UnkSpriteDesc3A48* desc);
extern void fn_800363D8(UnkTask3A48* task, s32, s32, s32, s32);
extern void fn_800B0A14_removeQueue(void);
extern UnkTask3A48* fn_800B0A5C_insertQueue(void (*)(void), s32);

// .text:0x0015A9F4 size:0x3A0 mapped:0x80799A88
void fn_3_15A9F4(void) {
    return;
}

// .text:0x0015A75C size:0x298 mapped:0x807997F0
void fn_3_15A75C(void) {
    return;
}

// .text:0x0015A448 size:0x314 mapped:0x807994DC
void fn_3_15A448(void) {
    return;
}

// .text:0x0015A244 size:0x204 mapped:0x807992D8
void fn_3_15A244(void) {
    UnkTask3A48* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_3_data_B1BC);
    for (i = 0; i < 5; i++) {
        lbl_80371C30[task->_14 + i + 6]._00->_5C = lbl_3_data_B3DC[lbl_3_data_FAC4[i]] << 16;
    }
    task->_1C = 1;
    if (g_Practice.practiceType_1 == 1 || g_Practice.practiceType_1 == 2 || g_Practice.practiceType_1 == 3 || g_Practice.practiceType_1 == 4 || g_Practice.practiceType_1 == 5) {
        lbl_80371C30[task->_14]._00->_64 = lbl_3_data_B3E8[g_Practice.practiceType];
        lbl_80371C30[task->_14]._00->_5C = 50 << 16;
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1 + g_Practice.practiceType]._00->_5C = 105 << 16;
        lbl_80371C30[task->_14 + 11 + g_Practice.practiceType]._00->_5C = 105 << 16;
        task->_1C = 5;
    }
    lbl_3_common_bss_32724._C0 = 1;
    ((UnkTask3A48*)lbl_803CC1B8)->_00 = fn_3_159D50;
}

// .text:0x00159D50 size:0x4F4 mapped:0x80798DE4
void fn_3_159D50(void) {
    return;
}

// .text:0x001599B8 size:0x398 mapped:0x80798A4C
void fn_3_1599B8(void) {
    return;
}

// .text:0x001595F4 size:0x3C4 mapped:0x80798688
void fn_3_1595F4(void) {
    return;
}

// .text:0x00159590 size:0x64 mapped:0x80798624
void fn_3_159590(void) {
    UnkTask3A48* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_B3F4);
    task->_18 = 0;
    task->_1A = 0;
    task->_1C = 0;
    ((UnkTask3A48*)lbl_803CC1B8)->_00 = fn_3_159114;
}

// .text:0x00159114 size:0x47C mapped:0x807981A8
void fn_3_159114(void) {
    return;
}

// .text:0x001590C8 size:0x4C mapped:0x8079815C
void fn_3_1590C8(void) {
    if (g_Practice.tutorialState == 0 && g_Practice.practiceState == 7) {
        fn_800B0A5C_insertQueue(fn_3_158FE4, 2);
    }
}

// .text:0x00158FE4 size:0xE4 mapped:0x80798078
void fn_3_158FE4(void) {
    UnkTask3A48* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_B85C);
    lbl_80371C30[task->_14 + 8]._00->_54 &= ~2;
    fn_800363D8(task, 13, 1, 14, g_Practice.practiceLevel);
    fn_800363D8(task, 13, 2, 14, g_Practice.practiceLevel);
    g_Practice.laukituTextChannelIndex = -1;
    g_Practice.diagramTextChannelIndex = -1;
    task->_18 = 0;
    task->_1A = 0;
    task->_1C = 0;
    task->_1E = 0;
    task->_20 = 0;
    ((UnkTask3A48*)lbl_803CC1B8)->_00 = fn_3_158B64;
}

// .text:0x00158B64 size:0x480 mapped:0x80797BF8
void fn_3_158B64(void) {
    return;
}

// .text:0x001589C4 size:0x1A0 mapped:0x80797A58
void fn_3_1589C4(void) {
    if (g_Practice.practiceType_2 == 0 || g_Practice.practiceType_2 == 1 || g_Practice.practiceType_2 == 2) {
        if (g_Practice.tutorialState == 3 && g_Practice._1C7 == 0) {
            if (lbl_3_common_bss_32724._C6 == 0) {
                fn_800B0A5C_insertQueue(fn_3_1586B0, 2);
                lbl_3_common_bss_32724._C6 = 1;
            }
            if (g_Practice.practiceType_2 == 2 && g_Ball.totalFramesAtPlay == 1) {
                fn_800B0A5C_insertQueue(fn_3_9669C, 2);
            }
            if (g_Practice.practiceType_2 == 2) {
                if (g_Practice._186 == 60) {
                    fn_800B0A5C_insertQueue(fn_3_1581FC, 2);
                }
            } else if (g_Practice._186 == 1) {
                fn_800B0A5C_insertQueue(fn_3_1581FC, 2);
            }
        }
    } else if (g_Practice.practiceType_2 == 3) {
        if (g_Practice.tutorialState == 3 && g_Practice._1C7 == 0) {
            if (lbl_3_common_bss_32724._C7 == 0) {
                fn_800B0A5C_insertQueue(fn_3_1586B0, 2);
                fn_800B0A5C_insertQueue(fn_3_9669C, 2);
            }
            if (g_Practice._186 == 1) {
                fn_800B0A5C_insertQueue(fn_3_1581FC, 2);
            }
        }
    }
}

// .text:0x001586B0 size:0x314 mapped:0x80797744
void fn_3_1586B0(void) {
    return;
}

// .text:0x001583AC size:0x304 mapped:0x80797440
void fn_3_1583AC(void) {
    return;
}

// .text:0x00158264 size:0x148 mapped:0x807972F8
void fn_3_158264(UnkTask3A48* task) {
    s32 n;

    n = lbl_3_data_FAF4[g_Practice.practiceType_2][g_Practice.practiceLevel];
    fn_800363D8(task, 1, 3, 50, n);
    fn_800363D8(task, 1, 4, 50, n);
    n = g_Practice.guidedPracticeCounter;
    fn_800363D8(task, 1, 1, 50, n);
    fn_800363D8(task, 1, 2, 50, n);
    if (n != task->_1A) {
        if ((lbl_80371C30[task->_14 + 1]._00->_5C >> 16) <= 9) {
            lbl_80371C30[task->_14 + 1]._00->_5C = 10 << 16;
            lbl_80371C30[task->_14 + 1]._00->_68 = 1;
        }
        if ((lbl_80371C30[task->_14 + 1]._00->_5C >> 16) >= 19) {
            lbl_80371C30[task->_14 + 1]._00->_5C = 9 << 16;
            lbl_80371C30[task->_14 + 1]._00->_68 = 0;
            task->_1A = n;
        }
    }
}

// .text:0x001581FC size:0x68 mapped:0x80797290
void fn_3_1581FC(void) {
    fn_80034E20(lbl_803CC1B8, lbl_3_data_BD50);
    if (lbl_800EF808._398 == 1) {
        playSoundEffect(429);
    }
    ((UnkTask3A48*)lbl_803CC1B8)->_00 = fn_3_15810C;
}

// .text:0x0015810C size:0xF0 mapped:0x807971A0
void fn_3_15810C(void) {
    UnkTask3A48* task = lbl_803CC1B8;
    s32 n;

    if (lbl_3_common_bss_32724._96 == 0) {
        n = 150;
        if (g_Practice.practiceType_2 == 0) {
            n = 90;
        }
        if (g_Practice._186 < n - 20) {
            if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= 33) {
                lbl_80371C30[task->_14]._00->_68 = 0;
            }
        } else {
            lbl_80371C30[task->_14]._00->_68 = 1;
        }
        if (g_Practice._1C7 == 0 || lbl_3_common_bss_34C90._1D2 != 0) {
            return;
        }
    }
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}

// .text:0x001580AC size:0x60 mapped:0x80797140
void fn_3_1580AC(void) {
    UnkTask3A48* task = lbl_803CC1B8;

    fn_80034E20(task, lbl_3_data_BD90);
    task->_1C = 0;
    task->_1E = 0;
    ((UnkTask3A48*)lbl_803CC1B8)->_00 = fn_3_157E28;
}

// .text:0x00157E28 size:0x284 mapped:0x80796EBC
void fn_3_157E28(void) {
    return;
}
