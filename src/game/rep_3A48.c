#include "game/rep_3A48.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/m_sound.h"
#include "game/rep_1668.h"
#include "game/rep_16B8.h"
#include "game/rep_1770.h"

typedef struct UnkTask3A48 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
    union {
        /* 0x1C */ u16 _1C_arr[4]; // text window ids
        struct {
            /* 0x1C */ u16 _1C;
            /* 0x1E */ u16 _1E;
            /* 0x20 */ u16 _20;
            /* 0x22 */ u16 _22;
        };
    };
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
    /* 0x97 */ u8 _97[0xA5 - 0x97];
    /* 0xA5 */ u8 _A5;
    /* 0xA6 */ u8 _A6;
    /* 0xA7 */ u8 _A7;
    /* 0xA8 */ u8 _A8[0xAA - 0xA8];
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB[0xBC - 0xAB];
    /* 0xBC */ u8 _BC;
    /* 0xBD */ u8 _BD[0xC0 - 0xBD];
    /* 0xC0 */ u8 _C0;
    /* 0xC1 */ u8 _C1;
    /* 0xC2 */ u8 _C2;
    /* 0xC3 */ u8 _C3[0xC6 - 0xC3];
    /* 0xC6 */ u8 _C6;
    /* 0xC7 */ u8 _C7;
    /* 0xC8 */ u8 _C8[0xD9 - 0xC8];
    /* 0xD9 */ u8 _D9;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x000 */ u8 _000[0x1D2];
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4;
    /* 0x1D5 */ u8 _1D5;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x000 */ u8 _000[0x398];
    /* 0x398 */ u8 _398;
} lbl_800EF808;

// One text window per entry
typedef struct {
    /* 0x00 */ u8 _00[0x2F];
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u8 _30;
    /* 0x31 */ u8 _31[0x34 - 0x31];
    /* 0x34 */ u8 _34;
    /* 0x35 */ u8 _35[0x38 - 0x35];
} UnkTextWindow3A48; // size: 0x38

extern UnkTextWindow3A48 lbl_80366B18[];
extern u8 lbl_800E8558[][6];
extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} lbl_800FEF70[];
extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x8 - 0x1];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A[0x26 - 0xA];
    /* 0x26 */ u8 _26;
} lbl_8034E978;
extern UnkSpriteRef3A48 lbl_80371C30[];
extern void* lbl_803CC1B8;

// In the 0x8110-0xD5B8 block outside every unit's .data range
extern u8 lbl_3_data_9D50[][5];
extern u8 lbl_3_data_A594[4];
extern UnkSpriteDesc3A48 lbl_3_data_B1BC[];
extern u16 lbl_3_data_B3DC[6];
extern u16 lbl_3_data_B3E8[6];
extern UnkSpriteDesc3A48 lbl_3_data_B3F4[];
extern UnkSpriteDesc3A48 lbl_3_data_B5D4[];
extern s16 lbl_3_data_B834[5][4];
extern UnkSpriteDesc3A48 lbl_3_data_B85C[];
extern u16 lbl_3_data_BA5C[10];
extern UnkSpriteDesc3A48 lbl_3_data_BA70[];
extern UnkSpriteDesc3A48 lbl_3_data_BD50[];
extern UnkSpriteDesc3A48 lbl_3_data_BD90[];
// In rep_1B20's .data range
typedef struct {
    /* 0x0 */ s16 _00;
    /* 0x2 */ s16 _02;
} UnkWindowDesc3A48; // size: 0x4
extern UnkWindowDesc3A48 lbl_3_data_103B8[4][4][4];
extern u8 lbl_3_data_FAC4[8];
extern u8 lbl_3_data_FAF4[4][4];
extern s16 lbl_3_data_104B8[16][2][3];

extern void fn_8000F8F4(UnkTask3A48* task);
extern u16 fn_8000F988(UnkTask3A48* task, s32, u16, s32, s32, s32);
extern void fn_8000FD9C(s32 id, s32, s32);
extern void fn_8000FE08(s32 id, s32, s32);
extern void fn_8000FEE8(s32 id);
extern void fn_8004CC4C(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_8004D0F0(void);
extern void fn_80050F78(int);
extern void fn_80051D00(void);
extern void fn_80053FE8(void);
extern void fn_80034CEC(UnkTask3A48* task);
extern void fn_80034E20(UnkTask3A48* task, UnkSpriteDesc3A48* desc);
extern void fn_800363D8(UnkTask3A48* task, s32, s32, s32, s32);
extern void fn_800B0A14_removeQueue(void);
extern UnkTask3A48* fn_800B0A5C_insertQueue(void (*)(void), s32);
// Between rep_3448's and rep_34B0's .text ranges
extern void fn_3_12BFE8(void);
extern void fn_3_12C3F0(void);

static inline UnkSprite3A48* getSprite(UnkTask3A48* task, s32 i) {
    s32 idx = task->_14 + i;
    return lbl_80371C30[idx]._00;
}
static inline u32 getFrame(UnkTask3A48* task, s32 i) {
    i += task->_14;
    return lbl_80371C30[i]._00->_5C >> 16;
}

static inline BOOL isAnimDone(UnkSprite3A48* sprite) {
    return sprite->_69 == 2 ? TRUE : FALSE;
}

static inline void setScreen(u8 id) {
    lbl_8034E978._00 = id;
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._08 = lbl_800FEF70[id]._08;
}

// .text:0x0015A9F4 size:0x3A0 mapped:0x80799A88
void fn_3_15A9F4(void) {
    if (g_GameLogic.secondaryGameMode == 17 || g_GameLogic.framesOfExitingToMenu != 0) {
        return;
    }
    if (g_GameLogic.secondaryGameMode == 10) {
        lbl_3_common_bss_32724._A7 = 0;
        fn_3_15A448();
        return;
    }
    if (g_Practice.practiceType_2 == 0 || g_Practice.practiceType_2 == 1 || g_Practice.practiceType_2 == 2 || g_Practice.practiceType_2 == 3) {
        fn_3_1590C8();
    }
    if (g_Practice._1C7 != 0) {
        if (g_Practice.frames_onPauseScreen == 1) {
            fn_800B0A5C_insertQueue(fn_3_9894C, 2);
        }
    } else if (g_Practice._19F != 0) {
        if (lbl_3_common_bss_34C90._1D2 == 1 && g_Practice.frames_onPauseScreen2 == 1) {
            if (lbl_3_common_bss_32724._AA == 0) {
                fn_800B0A5C_insertQueue(fn_3_98DE0, 2);
            }
            fn_800B0A5C_insertQueue(fn_3_9894C, 2);
        }
        if (lbl_3_common_bss_34C90._1D2 == 3 && lbl_3_common_bss_34C90._1D3 == 3) {
            fn_800B0A5C_insertQueue(fn_3_983B8, 2);
        }
    }
    if (g_Practice.loadingGuidedPractice != 0 && g_Practice._1D5 == 0) {
        fn_800B0A5C_insertQueue(fn_3_1580AC, 2);
        g_Practice._1D5 = 1;
    }
    fn_3_97144();
    if ((g_Practice.practiceType_2 == 4 || g_Practice.practiceType_2 == 3) && g_Practice.practiceLevel != 4 && g_Practice.practiceLevel != 5) {
        fn_3_96914();
    }
    fn_3_15A75C();
    if (g_Practice.practiceLevel == 7 || g_Practice.practiceLevel == 6) {
        fn_3_9143C();
    }
    fn_3_1589C4();
}

// .text:0x0015A75C size:0x298 mapped:0x807997F0
void fn_3_15A75C(void) {
    if (g_GameLogic.hudElementLoadingInd != 0 && lbl_3_common_bss_32724._A5 == 0 && g_Practice.instructionNumber < 0) {
        lbl_3_common_bss_32724._A5 = 1;
        lbl_3_common_bss_32724._A6 = 0;
        lbl_3_common_bss_32724._A7 = 255;
        if (g_Practice.practiceLevel == 4) {
            fn_800B0A5C_insertQueue(fn_3_9976C, 2);
        } else if (g_Practice.practiceLevel == 5) {
            fn_800B0A5C_insertQueue(fn_3_99BDC, 2);
        } else if (g_Practice.practiceType_2 == 4) {
            fn_800B0A5C_insertQueue(fn_3_9C28C, 2);
            fn_800B0A5C_insertQueue(fn_3_9A8A4, 2);
        } else if (g_Practice.practiceType_2 == 0) {
            if (g_Practice.practiceLevel == 1) {
                fn_800B0A5C_insertQueue(fn_3_99BDC, 2);
            }
        } else if (g_Practice.practiceType_2 == 1) {
            if (g_Practice.practiceLevel == 1) {
                fn_800B0A5C_insertQueue(fn_3_9976C, 2);
            }
        }
    }
    if (lbl_3_common_bss_32724._A5 != 0 && lbl_3_common_bss_32724._A6 < 255) {
        if (lbl_3_common_bss_32724._A6 < 240) {
            lbl_3_common_bss_32724._A6 += 16;
        } else {
            lbl_3_common_bss_32724._A6 = 255;
        }
    }
    if (lbl_3_common_bss_32724._A7 != 0 && lbl_3_common_bss_32724._A7 < 255) {
        if (lbl_3_common_bss_32724._A7 <= 16) {
            lbl_3_common_bss_32724._A7 = 0;
            lbl_3_common_bss_32724._A5 = 0;
        } else {
            lbl_3_common_bss_32724._A7 -= 16;
        }
    } else if (lbl_3_common_bss_32724._A5 != 0) {
        if (g_GameLogic.gameStatus != 1 && g_GameLogic.gameStatus != 0 && g_GameLogic.gameStatus != 7) {
            lbl_3_common_bss_32724._A7 = 240;
        }
        if (lbl_3_common_bss_34C90._1D5 != 0) {
            lbl_3_common_bss_32724._A7 = 240;
        }
        if (g_Practice._19F != 0 && (lbl_3_common_bss_34C90._1D2 == 7 || lbl_3_common_bss_34C90._1D2 == 9 || lbl_3_common_bss_34C90._1D2 == 11)) {
            lbl_3_common_bss_32724._A7 = 0;
            lbl_3_common_bss_32724._A5 = 0;
        }
        if (g_Practice._1C7 != 0 && (lbl_3_common_bss_34C90._1D2 == 5 || lbl_3_common_bss_34C90._1D2 == 11 || lbl_3_common_bss_34C90._1D2 == 7)) {
            lbl_3_common_bss_32724._A7 = 0;
            lbl_3_common_bss_32724._A5 = 0;
        }
    }
    if (g_GameLogic.gameStatus == 8) {
        lbl_3_common_bss_32724._A7 = 0;
        lbl_3_common_bss_32724._A5 = 0;
    }
}

// .text:0x0015A448 size:0x314 mapped:0x807994DC
void fn_3_15A448(void) {
    if (g_GameLogic.secondaryGameMode == 10) {
        if (lbl_3_common_bss_32724._D9 == 0 && g_GameLogic.framesOfExitingToMenu == 0) {
            fn_800B0A5C_insertQueue(fn_3_12C3F0, 2);
            fn_800B0A5C_insertQueue(fn_80053FE8, 2);
            setScreen(60);
        }
        if (g_Practice.practiceType_1 == 0) {
            if (g_Practice.practiceState == 2) {
                if (lbl_3_common_bss_32724._C0 == 0) {
                    fn_800B0A5C_insertQueue(fn_3_15A244, 2);
                }
                if (lbl_3_common_bss_32724._BC == 0) {
                    fn_800B0A5C_insertQueue(fn_3_12BFE8, 2);
                }
                setScreen(60);
            }
            if (g_Practice.practiceState == 7 && g_Practice.framesSincePracticeMenuDefaultTransition == 1) {
                fn_8004CC4C(0, 1, 1, 0, 137);
                fn_800B0A5C_insertQueue(fn_8004D0F0, 2);
            }
        }
        if (g_Practice.practiceType_1 == 1 || g_Practice.practiceType_1 == 2 || g_Practice.practiceType_1 == 3 || g_Practice.practiceType_1 == 4 || g_Practice.practiceType_1 == 5) {
            if (g_Practice.practiceState == 0) {
                if (lbl_3_common_bss_32724._C0 == 0) {
                    fn_800B0A5C_insertQueue(fn_3_15A244, 2);
                }
                if (lbl_3_common_bss_32724._C1 == 0) {
                    fn_800B0A5C_insertQueue(fn_3_1599B8, 2);
                }
                if (lbl_3_common_bss_32724._BC == 0) {
                    fn_800B0A5C_insertQueue(fn_3_12BFE8, 2);
                }
                setScreen(61);
            }
        }
    }
    if (g_Practice.practiceType_1 == 6) {
        if (g_Practice.practiceState == 1 && g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            if (lbl_3_common_bss_32724._C1 == 0) {
                lbl_3_common_bss_32724._C2 = 1;
                fn_800B0A5C_insertQueue(fn_3_1599B8, 2);
            }
            fn_800B0A5C_insertQueue(fn_80051D00, 2);
            fn_800B0A5C_insertQueue(fn_3_159590, 2);
            setScreen(62);
        }
        if (g_Practice.practiceState == 5) {
            fn_80050F78(0);
        }
        if (g_Practice.practiceState == 4) {
            fn_80050F78(1);
        }
    }
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
    UnkTask3A48* task = lbl_803CC1B8;
    s32 i;
    s32 count;
    u32 frame;

    if (lbl_3_common_bss_32724._96 == 0 && g_Practice.practiceType_1 != 6 && g_GameLogic.secondaryGameMode == 10) {
        if (task->_1C == 1) {
            if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= 25) {
                lbl_80371C30[task->_14]._00->_68 = 0;
                task->_1C = 2;
            }
        } else if (task->_1C == 2) {
            for (i = 0; i < 5; i++) {
                if (g_Practice.practiceType == i) {
                    if ((lbl_80371C30[task->_14 + i + 1]._00->_5C >> 16) < 90) {
                        lbl_80371C30[task->_14 + i + 1]._00->_68 = 1;
                        lbl_80371C30[task->_14 + i + 11]._00->_68 = 1;
                    } else {
                        lbl_80371C30[task->_14 + i + 1]._00->_5C = 10 << 16;
                        lbl_80371C30[task->_14 + i + 11]._00->_5C = 10 << 16;
                    }
                } else {
                    frame = lbl_80371C30[task->_14 + i + 1]._00->_5C >> 16;
                    if (frame > 10) {
                        lbl_80371C30[task->_14 + i + 1]._00->_5C = 10 << 16;
                        lbl_80371C30[task->_14 + i + 1]._00->_68 = 4;
                        lbl_80371C30[task->_14 + i + 11]._00->_5C = 10 << 16;
                        lbl_80371C30[task->_14 + i + 11]._00->_68 = 4;
                    } else if (frame != 0) {
                        lbl_80371C30[task->_14 + i + 1]._00->_68 = 4;
                        lbl_80371C30[task->_14 + i + 11]._00->_68 = 4;
                    } else {
                        lbl_80371C30[task->_14 + i + 1]._00->_68 = 0;
                        lbl_80371C30[task->_14 + i + 11]._00->_68 = 0;
                    }
                }
            }
            if (g_Practice.practiceState == 5) {
                lbl_80371C30[task->_14]._00->_68 = 1;
                lbl_80371C30[task->_14]._00->_64 = lbl_3_data_B3E8[g_Practice.practiceType];
                lbl_80371C30[task->_14 + 1 + g_Practice.practiceType]._00->_68 = 1;
                lbl_80371C30[task->_14 + 1 + g_Practice.practiceType]._00->_5C = 90 << 16;
                lbl_80371C30[task->_14 + 11 + g_Practice.practiceType]._00->_68 = 1;
                lbl_80371C30[task->_14 + 11 + g_Practice.practiceType]._00->_5C = 90 << 16;
                task->_1C = 3;
            }
        } else if (task->_1C == 3) {
            if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= 40) {
                lbl_80371C30[task->_14]._00->_68 = 0;
            }
            if (g_Practice.practiceType_1 == 1 || g_Practice.practiceType_1 == 2 || g_Practice.practiceType_1 == 3 || g_Practice.practiceType_1 == 4 ||
                g_Practice.practiceType_1 == 5)
            {
                if (g_Practice.practiceState == 3) {
                    if (g_Practice.practiceType_2 == 4) {
                        lbl_80371C30[task->_14]._00->_68 = 1;
                        task->_1C = 9;
                    }
                } else if (g_Practice.practiceState == 6) {
                    lbl_80371C30[task->_14]._00->_68 = 4;
                    lbl_80371C30[task->_14 + 1 + g_Practice.practiceType]._00->_68 = 4;
                    lbl_80371C30[task->_14 + 11 + g_Practice.practiceType]._00->_68 = 4;
                    task->_1C = 4;
                }
            }
        } else if (task->_1C == 4) {
            count = 0;
            if ((lbl_80371C30[task->_14]._00->_5C >> 16) <= 25) {
                count = 1;
                lbl_80371C30[task->_14]._00->_68 = 0;
            }
            if ((lbl_80371C30[task->_14 + 1 + g_Practice.practiceType]._00->_5C >> 16) <= 90) {
                count++;
                lbl_80371C30[task->_14 + 1 + g_Practice.practiceType]._00->_68 = 0;
                lbl_80371C30[task->_14 + 11 + g_Practice.practiceType]._00->_68 = 0;
            }
            if (count >= 2) {
                task->_1C = 2;
            }
        } else if (task->_1C == 5) {
            if ((lbl_80371C30[task->_14]._00->_5C >> 16) <= 40) {
                lbl_80371C30[task->_14]._00->_68 = 0;
                task->_1C = 3;
            }
        }
    } else {
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
        lbl_3_common_bss_32724._C0 = 0;
    }
}

// .text:0x001599B8 size:0x398 mapped:0x80798A4C
void fn_3_1599B8(void) {
    UnkTask3A48* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_3_data_B5D4);
    task->_1C = 0xFFFF;
    task->_1E = 0xFFFF;
    task->_20 = 0xFFFF;
    task->_22 = 0xFFFF;
    for (i = 0; i < 4; i++) {
        fn_800363D8(task, i + 2, 1, 119, i);
        fn_800363D8(task, i + 2, 2, 119, i + 4);
        if (g_Practice.practiceType_1 == 5 || g_Practice.practiceType_1 == 6) {
            lbl_80371C30[task->_14 + 10 + i]._00->_54 &= ~2;
        } else if (g_Practice._1B2[g_Practice.practiceType_2][i] == 0) {
            lbl_80371C30[task->_14 + 10 + i]._00->_54 &= ~2;
        }
        task->_1C_arr[i] = fn_8000F988(task, i + 14, i, 5, lbl_3_data_B834[g_Practice.practiceType_2][i], 0);
    }
    for (; i < 4; i++) {
        lbl_80371C30[task->_14 + 2 + i]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 6 + i]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 14 + i]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + 10 + i]._00->_54 &= ~2;
    }
    task->_18 = 0;
    if (lbl_3_common_bss_32724._C2 != 0) {
        task->_18 = 2;
        lbl_80371C30[task->_14]._00->_5C = 15 << 16;
    }
    lbl_3_common_bss_32724._C1 = 1;
    task->_1A = 0;
    ((UnkTask3A48*)lbl_803CC1B8)->_00 = fn_3_1595F4;
}

// .text:0x001595F4 size:0x3C4 mapped:0x80798688
void fn_3_1595F4(void) {
    UnkTask3A48* task = lbl_803CC1B8;
    s32 i;

    if (g_GameLogic.secondaryGameMode == 10 &&
        (g_Practice.practiceType_1 == 1 || g_Practice.practiceType_1 == 2 || g_Practice.practiceType_1 == 3 || g_Practice.practiceType_1 == 4 ||
         g_Practice.practiceType_1 == 5 || g_Practice.practiceType_1 == 6))
    {
        if (task->_18 == 0) {
            task->_18 = 1;
        } else if (task->_18 == 1) {
            if ((s32)(lbl_80371C30[task->_14]._00->_5C >> 16) >= 15) {
                task->_18 = 2;
            }
        } else if (task->_18 == 2) {
            task->_1A += 32;
            if (task->_1A > 255) {
                task->_1A = 255;
            }
            for (i = 0; i < 4; i++) {
                if (g_Practice.subMenuCursor == i) {
                    if (g_Practice.practiceState == 3 || g_Practice.practiceState == 4) {
                        lbl_80371C30[task->_14 + 2 + i]._00->_68 = 1;
                        lbl_80371C30[task->_14 + 6 + i]._00->_68 = 1;
                    } else {
                        if ((s32)(lbl_80371C30[task->_14 + 2 + i]._00->_5C >> 16) < 9) {
                            lbl_80371C30[task->_14 + 2 + i]._00->_68 = 1;
                        } else {
                            lbl_80371C30[task->_14 + 2 + i]._00->_68 = 0;
                        }
                        lbl_80371C30[task->_14 + 6 + i]._00->_5C = 1 << 16;
                        lbl_80371C30[task->_14 + 6 + i]._00->_68 = 0;
                    }
                } else {
                    lbl_80371C30[task->_14 + 2 + i]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 2 + i]._00->_68 = 0;
                    lbl_80371C30[task->_14 + 6 + i]._00->_5C = 0;
                    lbl_80371C30[task->_14 + 6 + i]._00->_68 = 0;
                }
            }
            if (g_Practice.practiceType_1 != 6 && g_Practice.practiceState == 6) {
                task->_18 = 3;
            }
        } else if (task->_18 == 3) {
            if (task->_1A >= 32) {
                task->_1A -= 32;
            } else {
                task->_1A = 0;
            }
            lbl_80371C30[task->_14]._00->_68 = 4;
            lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        }
        for (i = 0; i < 4; i++) {
            lbl_80371C30[task->_14 + 14 + i]._00->_58 = task->_1A | (lbl_80371C30[task->_14 + 14 + i]._00->_58 & ~0xFF);
        }
        return;
    }
    lbl_3_common_bss_32724._C1 = 0;
    lbl_3_common_bss_32724._C2 = 0;
    for (i = 0; i < 4; i++) {
        if (task->_1C_arr[i] != 0xFFFF) {
            fn_8000FEE8(task->_1C_arr[i]);
        }
    }
    fn_8000F8F4(task);
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
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
    UnkTask3A48* task = lbl_803CC1B8;
    s32 done;
    s32 id;
    u8* entry;

    if (task->_1A < 0xFFFE) {
        task->_1A++;
    } else {
        task->_1A = 0xFFFF;
    }
    if (lbl_3_common_bss_32724._96 != 0 || g_Practice.practiceType_1 != 6) {
        goto remove;
    }
    if (task->_1E == 0) {
        task->_1E = 1;
        task->_1A = 0;
    } else if (task->_1E == 1) {
        done = 0;
        if ((s32)(lbl_80371C30[task->_14]._00->_5C >> 16) >= 14) {
            done |= 16;
            lbl_80371C30[task->_14]._00->_68 = 0;
            lbl_80371C30[task->_14 + 2]._00->_68 = 0;
        }
        if (done == 16) {
            task->_1E = 2;
        }
    } else if (task->_1E == 2) {
        id = g_Minigame._19E8[g_Practice.homeAway]._0;
        lbl_80371C30[task->_14 + 5]._00->_5C = lbl_3_data_A594[g_Minigame.battingHandedness[g_Practice.homeAway]] << 16;
        if (lbl_800E8558[id][0] != 0 && g_Minigame._19E8[g_Practice.homeAway]._1 == 0 &&
            g_Minigame._19E8[g_Practice.homeAway]._6 == 0)
        {
            lbl_80371C30[task->_14 + 7]._00->_54 |= 2;
        } else {
            lbl_80371C30[task->_14 + 7]._00->_54 &= ~2;
        }
        if (g_Practice.practiceState == 4) {
            goto remove;
        }
        if (g_Practice.practiceState == 5) {
            task->_1E = 3;
            task->_1A = 0;
        }
    } else if (task->_1E == 3) {
        if (task->_1A == 1) {
            lbl_80371C30[task->_14]._00->_68 = 1;
            lbl_80371C30[task->_14 + 2]._00->_68 = 1;
        }
    }
    if (g_Minigame._19DA[0] >= 0) {
        if (g_Minigame._19E8[0]._0 != getFrame(task, 13)) {
            getSprite(task, 8)->_5C = 0;
            getSprite(task, 9)->_5C = 0;
        }
        getSprite(task, 8)->_54 |= 2;
        getSprite(task, 8)->_68 = 1;
        getSprite(task, 9)->_54 |= 2;
        getSprite(task, 9)->_68 = 1;
        getSprite(task, 13)->_5C = g_Minigame._19E8[0]._0 << 16;
        getSprite(task, 11)->_54 |= 2;
        getSprite(task, 11)->_68 = 1;
        entry = lbl_800E8558[g_Minigame._19E8[0]._0];
        getSprite(task, 12)->_5C = lbl_3_data_9D50[entry[0]][entry[5]] << 16;
    } else {
        getSprite(task, 8)->_5C = 0;
        getSprite(task, 8)->_54 &= ~2;
        getSprite(task, 9)->_5C = 0;
        getSprite(task, 9)->_54 &= ~2;
        getSprite(task, 13)->_5C = 54 << 16;
        getSprite(task, 11)->_5C = 0;
        getSprite(task, 11)->_54 &= ~2;
    }
    return;

remove:
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
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
    UnkTask3A48* task = lbl_803CC1B8;
    BOOL done = FALSE;
    s16 text;
    UnkSprite3A48* sprite;
    s32 frame;

    if (lbl_3_common_bss_32724._96 == 0 && (g_Practice.tutorialState != 2 || g_Practice.practiceState != 3)) {
        if (task->_1C == 0) {
            task->_1C++;
            g_Practice.laukituTextChannelIndex = fn_8000F988(task, 9, 0, 5, 0, 0);
            lbl_80366B18[g_Practice.laukituTextChannelIndex]._2F = 0;
            lbl_80366B18[g_Practice.laukituTextChannelIndex]._30 = 1;
            fn_8000FD9C(g_Practice.laukituTextChannelIndex, 2, 0);
            g_Practice.diagramTextChannelIndex = fn_8000F988(task, 10, 0, 5, 0, 0);
            lbl_80366B18[g_Practice.diagramTextChannelIndex]._2F = 1;
            lbl_80366B18[g_Practice.diagramTextChannelIndex]._30 = 1;
        }
        if (g_Practice.instructionComplete_readyToAdvance != 0 || g_Practice.allInstructionsComplete != 0) {
            lbl_80371C30[task->_14 + 7]._00->_54 |= 2;
        } else {
            lbl_80371C30[task->_14 + 7]._00->_54 &= ~2;
        }
        sprite = lbl_80371C30[task->_14]._00;
        frame = sprite->_5C >> 16;
        if (g_Practice.textRelatedIndicator != 0) {
            if (frame <= 15) {
                sprite->_68 = 1;
            } else if (sprite->_69 == 2) {
                done = TRUE;
            }
        } else if (frame > 15) {
            sprite->_68 = 4;
        } else if (frame < 15) {
            sprite->_68 = 1;
        } else {
            sprite->_68 = 0;
        }
        if (g_Practice.maybeControlFlag1 != 0 && done) {
            lbl_80371C30[task->_14 + 8]._00->_64 = lbl_3_data_BA5C[g_Practice.maybeControlFlag1];
            lbl_80371C30[task->_14 + 8]._00->_54 |= 2;
            lbl_80371C30[task->_14 + 4]._00->_68 = 1;
            lbl_80371C30[task->_14 + 5]._00->_68 = 1;
            if (isAnimDone(lbl_80371C30[task->_14 + 4]._00)) {
                lbl_80371C30[task->_14 + 10]._00->_58 = (lbl_80371C30[task->_14 + 10]._00->_58 & ~0xFF) | 0xFF;
            } else {
                lbl_80371C30[task->_14 + 10]._00->_58 &= ~0xFF;
            }
        } else {
            lbl_80371C30[task->_14 + 8]._00->_54 &= ~2;
            lbl_80371C30[task->_14 + 4]._00->_68 = 4;
            lbl_80371C30[task->_14 + 5]._00->_68 = 4;
            lbl_80371C30[task->_14 + 10]._00->_58 &= ~0xFF;
        }
        lbl_80371C30[task->_14 + 6]._00->_5C = g_Practice.maybeControlFlag2 << 16;
        text = g_Practice.lakituTextIndex;
        if (text >= 0) {
            g_Practice.lakituTextIndex_stored = text;
            g_Practice.lakituTextIndex = -1;
            fn_8000FE08(g_Practice.laukituTextChannelIndex, 5, text);
        }
        text = g_Practice.diagramTitleTextIndex;
        if (text >= 0) {
            g_Practice.diagramTitleTextIndex_stored = text;
            g_Practice.diagramTitleTextIndex = -1;
            fn_8000FE08(g_Practice.diagramTextChannelIndex, 5, text);
        }
        g_Practice.currentMessageDoneTyping = lbl_80366B18[g_Practice.laukituTextChannelIndex]._34;
    } else {
        g_Practice.currentMessageDoneTyping = 1;
        if (g_Practice.laukituTextChannelIndex >= 0) {
            fn_8000FEE8(g_Practice.laukituTextChannelIndex);
        }
        if (g_Practice.diagramTextChannelIndex >= 0) {
            fn_8000FEE8(g_Practice.diagramTextChannelIndex);
        }
        if (g_Practice.laukituTextChannelIndex >= 0 || g_Practice.diagramTextChannelIndex >= 0) {
            fn_8000F8F4(task);
        }
        lbl_8034E978._26 = 1;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
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
    UnkTask3A48* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_3_data_BA70);
    if (g_Practice.practiceType_2 == 2 || g_Practice.practiceType_2 == 3) {
        lbl_80371C30[task->_14]._00->_64 = 59;
    }
    task->_1A = g_Practice.guidedPracticeCounter;
    if (g_Practice.practiceType_2 == 3) {
        lbl_80371C30[task->_14 + 1]._00->_54 &= ~2;
    } else {
        fn_3_158264(task);
    }
    for (i = 0; i < 4; i++) {
        if (lbl_3_data_103B8[g_Practice.practiceType_2][g_Practice.practiceLevel][i]._00 == 0) {
            lbl_80371C30[task->_14 + 2 + i]._00->_54 &= ~2;
        } else {
            lbl_80371C30[task->_14 + 14 + i]._00->_5C = lbl_3_data_103B8[g_Practice.practiceType_2][g_Practice.practiceLevel][i]._00 << 16;
        }
    }
    task->_18 = 0;
    ((UnkTask3A48*)lbl_803CC1B8)->_00 = fn_3_1583AC;
}

// .text:0x001583AC size:0x304 mapped:0x80797440
void fn_3_1583AC(void) {
    UnkTask3A48* task = lbl_803CC1B8;
    s32 i;
    BOOL shown;

    if (lbl_3_common_bss_32724._96 == 0 && (g_Practice._1C7 == 0 || lbl_3_common_bss_34C90._1D2 != 0) &&
        (g_Practice._19F == 0 || (lbl_3_common_bss_34C90._1D2 != 7 && lbl_3_common_bss_34C90._1D2 != 11)))
    {
        if (task->_18 == 0) {
            for (i = 0; i < 4; i++) {
                if (lbl_3_data_103B8[g_Practice.practiceType_2][g_Practice.practiceLevel][i]._00 != 0) {
                    task->_1C_arr[i] = fn_8000F988(task, i + 18, 0, 5, lbl_3_data_103B8[g_Practice.practiceType_2][g_Practice.practiceLevel][i]._02, 0);
                    lbl_80366B18[task->_1C_arr[i]]._2F = 1;
                    lbl_80366B18[task->_1C_arr[i]]._30 = 1;
                }
            }
            task->_18++;
        }
        fn_3_158264(task);
    } else {
        shown = FALSE;
        for (i = 0; i < 4; i++) {
            if (lbl_3_data_103B8[g_Practice.practiceType_2][g_Practice.practiceLevel][i]._00 > 0) {
                fn_8000FEE8(task->_1C_arr[i]);
                shown = TRUE;
            }
        }
        if (shown) {
            fn_8000F8F4(task);
        }
        lbl_3_common_bss_32724._C6 = 0;
        fn_80034CEC(task);
        fn_800B0A14_removeQueue();
    }
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
    UnkTask3A48* task = lbl_803CC1B8;

    if (lbl_3_common_bss_32724._96 != 0) {
        goto remove;
    }
    if (task->_1C == 0) {
        task->_1E = fn_8000F988(task, 4, 0, 5, 0, 0);
        lbl_80366B18[task->_1E]._2F = 0;
        lbl_80366B18[task->_1E]._30 = 1;
        fn_8000FD9C(task->_1E, 2, 0);
        task->_1C++;
    } else if (task->_1C == 1) {
        if ((lbl_80371C30[task->_14]._00->_5C >> 16) >= 15) {
            lbl_80371C30[task->_14]._00->_68 = 0;
        }
        if (g_Practice.loadingGuidedPractice == 0) {
            if (g_Practice._1C7 != 0) {
                goto remove;
            }
            lbl_80371C30[task->_14 + 1]._00->_68 = 4;
            lbl_80371C30[task->_14 + 2]._00->_68 = 4;
            lbl_80371C30[task->_14 + 2]._00->_5C = 9 << 16;
            task->_1C++;
        }
    } else if (task->_1C == 2) {
        if ((lbl_80371C30[task->_14 + 1]._00->_5C >> 16) == 0) {
            goto remove;
        }
    }
    if (g_Practice._1C7 != 0) {
        lbl_80371C30[task->_14 + 3]._00->_54 &= ~2;
    } else {
        lbl_80371C30[task->_14 + 3]._00->_54 |= 2;
    }
    if (g_Practice._188 == 1) {
        fn_8000FE08(task->_1E, 5, lbl_3_data_104B8[g_Practice.practiceLevel_2][g_Practice._1D7][g_Practice._1D8]);
    }
    g_Practice.currentMessageDoneTyping = lbl_80366B18[task->_1E]._34;
    return;

remove:
    fn_8000FEE8(task->_1E);
    fn_8000F8F4(task);
    fn_80034CEC(task);
    fn_800B0A14_removeQueue();
}
