#include "game/rep_1C18.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "musyx/musyx.h"
#include "game/m_sound.h"
#include "game/rep_1BC8.h"
#include "game/rep_D18.h"
#include "game/rep_31A0.h"

extern struct {
    /* 0x000 */ u8 _000[0x1D2];
    /* 0x1D2 */ u8 _1D2;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x00 */ u8 _00[0xB9];
    /* 0xB9 */ s8 _B9;
    /* 0xBA */ u8 _BA;
    /* 0xBB */ u8 _BB;
    /* 0xBC */ u8 _BC;
    /* 0xBD */ u8 _BD;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x0000 */ u8 _0000[0x2D77];
    /* 0x2D77 */ u8 _2D77;
    /* 0x2D78 */ u8 _2D78[0x2D7B - 0x2D78];
    /* 0x2D7B */ u8 _2D7B;
    /* 0x2D7C */ u8 _2D7C;
    /* 0x2D7D */ u8 _2D7D[0x307A - 0x2D7D];
    /* 0x307A */ u8 _307A;
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern struct {
    /* 0x00 */ u8 _00[0x27];
    /* 0x27 */ u8 _27;
} lbl_80366158;

extern u8 lbl_800EFBA4[0x10];

// In rep_1B20's .data range
extern u8 lbl_3_data_FAC4[8];
extern u8 lbl_3_data_FACC[][5];
extern u8 lbl_3_data_FC18[4];

extern struct {
    /* 0x00 */ u8 _00[0x7F];
    /* 0x7F */ s8 _7F[4];
} lbl_803C6028;

extern struct {
    /* 0x0000 */ CharacterStats _0000[1];
} lbl_8034E9A0;

extern void changeScene(u8, s16);
extern BOOL fn_8001594C(int team);
extern void fn_8004CC18(void);
extern u8 fn_8004FD64(int);
extern void fn_80050138(int, int, int, int, int, int);
extern void fn_80050FE8(int, int, int, int, int, int);
extern void fn_800506E8(int, int, int);
extern int fn_80050760(int, u16, u16, u16, int);
extern void fn_800628D4(int);
extern void fn_80062A74(void);
extern void fn_80062A94(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);

// .text:0x000B5D78 size:0x104 mapped:0x806F4E0C
void fn_3_B5D78(void) {
    if (g_Practice.returnToPracticeMenuState != 0) {
        fn_3_B5CB4();
        return;
    }
    if (g_Practice.practiceMenu_framesOnCurrMenuScreen < 0xFFFE) {
        g_Practice.practiceMenu_framesOnCurrMenuScreen++;
    } else {
        g_Practice.practiceMenu_framesOnCurrMenuScreen = 0xFFFF;
    }
    switch (g_Practice.practiceType_1) {
    case 0:
        fn_3_B5818();
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        fn_3_B51E4();
        break;
    case 6:
        fn_3_B4C40();
        break;
    }
}

// .text:0x000B5D4C size:0x2C mapped:0x806F4DE0
void fn_3_B5D4C(int type) {
    g_Practice.practiceType_1 = type;
    g_Practice.practiceState = 0;
    lbl_3_common_bss_34C90._1D2 = 0;
    g_Practice.practiceMenu_framesOnCurrMenuScreen = 0;
    g_Practice.framesInCurrTransitionState = 0;
}

// .text:0x000B5CB4 size:0x98 mapped:0x806F4D48
void fn_3_B5CB4(void) {
    switch (g_Practice.returnToPracticeMenuState) {
    case 1:
        fn_3_8B318(-1);
        g_Practice.returnToPracticeMenuState = 2;
        lbl_3_common_bss_34C58._2C = 0;
        lbl_3_common_bss_34C58._2A = 1;
        lbl_3_common_bss_34C58._24 = 1;
    case 2:
        g_Practice.returnToPracticeMenuState = 3;
        break;
    default:
        fn_800B0A5C_insertQueue(fn_80062A94, 1);
        g_Practice.returnToPracticeMenuState = 0;
        break;
    }
}

// .text:0x000B5818 size:0x49C mapped:0x806F48AC
void fn_3_B5818(void) {
    switch (g_Practice.practiceState) {
    case 0:
        g_Practice.subMenuCursor = 0;
        g_Practice.framesSincePracticeMenuDefaultTransition = 0;
        fn_3_B42A8();
        if (g_Practice._1DA != 0) {
            fn_3_B3C94(1);
        } else {
            fn_3_B3C94(2);
        }
        g_Practice._1DA = 0;
        break;
    case 1:
        if (lbl_8036E548._2D7B >= 10) {
            fn_3_B3C94(2);
        }
        break;
    case 2:
        changeScene(6, 6);
        fn_3_B3C94(3);
        break;
    case 3:
        if (g_Practice.framesSincePracticeMenuDefaultTransition > 30) {
            fn_3_B3C94(4);
        }
        break;
    case 4:
        fn_3_B5694();
        g_Practice.framesSincePracticeMenuDefaultTransition = 0;
        break;
    case 5:
        if (g_Practice._19C != 0) {
            fn_3_B3C94(6);
        }
        break;
    case 6:
        if (lbl_3_common_bss_32724._BB == 0) {
            switch (g_Practice.practiceType_2) {
            case 0:
                fn_3_B5D4C(1);
                break;
            case 1:
                fn_3_B5D4C(2);
                break;
            case 2:
                fn_3_B5D4C(3);
                break;
            case 3:
                fn_3_B5D4C(4);
                break;
            case 4:
                fn_3_B5D4C(5);
                break;
            }
        }
        break;
    case 7:
        switch (fn_3_5B380(g_Controls[lbl_80366158._27].newButtonInput)) {
        case 1:
            if (g_Practice._1B1 != 0) {
                fn_8004CC18();
                fn_3_5B368();
            } else {
                changeScene(4, 6);
            }
            fn_3_B3C94(8);
            break;
        case 2:
            fn_3_B3C94(4);
            break;
        }
        break;
    case 8:
        if (g_Practice._19C != 0) {
            if (g_Practice._1B1 != 0) {
                if (fn_3_5B220(3) != 0) {
                    changeScene(4, 6);
                    g_Practice._1B1 = 0;
                }
            } else if (lbl_8037169C._13 != 0) {
                fn_80062A74();
                fn_8004CC18();
                fn_3_B3CAC(17);
                lbl_8036E548._307A = 0;
            }
        }
        break;
    }
    if (g_Practice._19C == 0 && fn_8001594C(g_GameLogic.teamFielding) != 0) {
        g_Practice._19C = 1;
    }
}

// .text:0x000B5694 size:0x184 mapped:0x806F4728
void fn_3_B5694(void) {
    InputStruct* input = &g_Controls[g_Practice.homeAway];

    if (lbl_3_common_bss_32724._BB == 0) {
        if (input->newButtonInput & 0x100) {
            fn_3_B3C94(5);
            sndFXStartEx(440, lbl_800EFBA4[1], 63, 0);
        } else if (input->newButtonInput & 0x200) {
            fn_3_5B408();
            fn_3_B3C94(7);
            sndFXStartEx(441, lbl_800EFBA4[2], 63, 0);
        } else if (input->_08 & 1) {
            if (g_Practice.practiceType != 0) {
                g_Practice.practiceType--;
            } else {
                g_Practice.practiceType = 4;
            }
            lbl_3_common_bss_32724._BD = 1;
            sndFXStartEx(439, lbl_800EFBA4[0], 63, 0);
        } else if (input->_08 & 2) {
            if (++g_Practice.practiceType >= 5) {
                g_Practice.practiceType = 0;
            }
            lbl_3_common_bss_32724._BD = 2;
            sndFXStartEx(439, lbl_800EFBA4[0], 63, 0);
        }
    }
    g_Practice.practiceType_2 = lbl_3_data_FAC4[g_Practice.practiceType];
    lbl_3_common_bss_32724._B9 = g_Practice.practiceType;
}

// .text:0x000B51E4 size:0x4B0 mapped:0x806F4278
void fn_3_B51E4(void) {
    switch (g_Practice.practiceState) {
    case 0:
        g_Practice._19D = 0;
        lbl_8036E548._2D77 = 0;
        lbl_8036E548._2D7B = 0;
        lbl_8036E548._2D7C = 0;
        fn_3_B42A8();
        if (g_Practice.practiceType_2 == 0) {
            fn_3_B4124(0, 0, 0, -1);
        } else if (g_Practice.practiceType_2 == 1) {
            fn_3_B4124(0, 0, 1, -1);
            fn_3_B4124(1, 0, 0, -1);
        } else if (g_Practice.practiceType_2 == 2) {
            fn_3_B4124(0, 0, 0, -1);
            fn_3_B4124(1, 0, 1, -1);
        } else if (g_Practice.practiceType_2 == 3) {
            fn_3_B4124(1, 0, lbl_3_data_FC18[1], -1);
            fn_3_B4124(1, 1, lbl_3_data_FC18[2], -1);
            fn_3_B4124(1, 2, lbl_3_data_FC18[3], -1);
        }
        g_Practice.framesSincePracticeMenuDefaultTransition = 0;
        fn_3_B3C94(1);
        break;
    case 1:
        if (g_Practice._19C != 0 && g_Practice.framesSincePracticeMenuDefaultTransition > 30) {
            fn_3_B3C94(2);
        }
        break;
    case 2:
        fn_3_B5090();
        break;
    case 3:
        g_Practice.framesSincePracticeMenuDefaultTransition = 0;
        fn_3_B3C94(4);
        break;
    case 4:
        if (g_Practice._19D == 0) {
            g_Practice.framesSincePracticeMenuDefaultTransition = 0;
        } else if (g_Practice.framesSincePracticeMenuDefaultTransition >= 30) {
            if (g_Practice.framesSincePracticeMenuDefaultTransition == 30) {
                if (g_Practice.practiceType_2 != 4) {
                    changeScene(3, 6);
                }
            } else if (lbl_8037169C._13 != 0 || g_Practice.practiceType_2 == 4) {
                switch (g_Practice.practiceType_2) {
                case 0:
                    fn_3_B3CAC(11);
                    break;
                case 1:
                    fn_3_B3CAC(12);
                    break;
                case 2:
                    fn_3_B3CAC(13);
                    break;
                case 3:
                    fn_3_B3CAC(14);
                    break;
                case 4:
                    fn_3_B5D4C(6);
                    break;
                }
                if (g_Practice.practiceType_2 != 4) {
                    fn_80062A74();
                }
                fn_3_B3C78(0);
            }
        }
        break;
    case 5:
        if (g_Practice._19D != 0) {
            fn_3_B3C94(6);
        }
        break;
    case 6:
        g_Practice.framesSincePracticeMenuDefaultTransition = 0;
        fn_3_B3C94(7);
        break;
    case 7:
        if (g_Practice.framesSincePracticeMenuDefaultTransition >= 15) {
            fn_3_B5D4C(0);
        }
        break;
    }
    if (g_Practice._19C == 0) {
        if (fn_8001594C(g_GameLogic.teamFielding) != 0) {
            g_Practice._19C = 1;
        }
    } else if (g_Practice._19D == 0 && fn_8001594C(g_GameLogic.teamFielding) != 0) {
        g_Practice._19D = 1;
    }
}

// .text:0x000B5090 size:0x154 mapped:0x806F4124
void fn_3_B5090(void) {
    InputStruct* input = &g_Controls[g_Practice.homeAway];
    int count = lbl_3_data_FACC[g_Practice.practiceType_2][0];

    if (input->newButtonInput & 0x100) {
        g_Practice.practiceLevel = lbl_3_data_FACC[g_Practice.practiceType_2][g_Practice.subMenuCursor + 1];
        sndFXStartEx(440, lbl_800EFBA4[1], 63, 0);
        fn_3_B3C94(3);
    } else if (input->newButtonInput & 0x200) {
        fn_3_B3C94(5);
        sndFXStartEx(441, lbl_800EFBA4[2], 63, 0);
    } else if (input->_08 & 8) {
        if (g_Practice.subMenuCursor != 0) {
            g_Practice.subMenuCursor--;
        } else {
            g_Practice.subMenuCursor = count - 1;
        }
        sndFXStartEx(439, lbl_800EFBA4[0], 63, 0);
    } else if (input->_08 & 4) {
        if (++g_Practice.subMenuCursor >= count) {
            g_Practice.subMenuCursor = 0;
        }
        sndFXStartEx(439, lbl_800EFBA4[0], 63, 0);
    }
}

// .text:0x000B4C40 size:0x450 mapped:0x806F3CD4
void fn_3_B4C40(void) {
    int i;
    int flags[4];

    if (g_GameLogic._125 <= 2) {
        for (i = 0; i < 4; i++) {
            g_Minigame._19E8[i]._8 = g_Minigame._19E8[i]._7;
            g_Minigame._19E8[i]._7 = 1;
        }
    }
    switch (g_Practice.practiceState) {
    case 0:
        for (i = 0; i < 4; i++) {
            flags[i] = 0;
        }
        flags[g_Practice.homeAway] = 1;
        fn_80050FE8(flags[0], flags[1], flags[2], flags[3], 1, 1);
        fn_80050138(0, 0, 0, 0, 0, 0);
        for (i = 0; i < 4; i++) {
            g_Minigame._19E8[i]._2 = -1;
            g_Minigame._19E8[i]._1 = 0;
            g_Minigame._19D2[i] = 20;
            {
                CharacterStats* stats = &lbl_8034E9A0._0000[g_Minigame._19E8[i]._0];
                g_Minigame.battingHandedness[i] = stats->stats.BattingStance + stats->stats.FieldingArm * 2;
            }
        }
        lbl_8036E548._2D77 = 0;
        lbl_8036E548._307A = 5;
        g_Minigame._1A0C = -1;
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_Practice._1D9 = 0;
        g_Practice.practiceState++;
        for (i = 0; i < 4; i++) {
            g_Minigame._1A13[i] = 1;
        }
        break;
    case 1:
        changeScene(1, 6);
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) {
            g_Minigame._19E8[g_Practice.homeAway]._0 =
                fn_80050760(g_Practice.homeAway, g_Controls[g_Practice.homeAway].buttonInput,
                            g_Controls[g_Practice.homeAway].newButtonInput, g_Controls[g_Practice.homeAway]._08, 0);
            g_Minigame.battingHandedness[g_Practice.homeAway] =
                lbl_8034E9A0._0000[g_Minigame._19E8[g_Practice.homeAway]._0].stats.BattingStance +
                lbl_8034E9A0._0000[g_Minigame._19E8[g_Practice.homeAway]._0].stats.FieldingArm * 2;
        }
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > 30) {
            g_Minigame._19DE = 0;
            g_Practice.practiceState++;
        }
        break;
    case 2:
        fn_3_B49D4();
        fn_3_B4124(0, 0, g_Minigame._19E8[g_Practice.homeAway]._0, g_Minigame.battingHandedness[g_Practice.homeAway]);
        lbl_3_common_bss_34C58._2C = 0;
        break;
    case 3:
        if (fn_3_B3CD4()) {
            if (g_GameLogic.FrameCountOfCurrentAtBat_Copy >= 90) {
                changeScene(3, 6);
            }
            if (lbl_8037169C._13 != 0) {
                g_Practice.practiceState++;
            }
        }
        break;
    case 4:
        if (g_Practice.practiceLevel == 4) {
            fn_3_B3CAC(12);
        } else if (g_Practice.practiceLevel == 5) {
            fn_3_B3CAC(11);
        } else if (g_Practice.practiceLevel == 6) {
            fn_3_B3CAC(15);
        } else {
            fn_3_B3CAC(16);
        }
        fn_80062A74();
        fn_3_B3C78(0);
        break;
    case 5:
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_Practice.practiceState++;
        break;
    case 6:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy >= 15) {
            fn_3_B5D4C(5);
        }
        break;
    }
    if (g_Practice.practiceState >= 2) {
        fn_3_10C81C();
    }
}

// .text:0x000B49D4 size:0x26C mapped:0x806F3A68
void fn_3_B49D4(void) {
    int i;
    int prev;
    int sel;

    for (i = 0; i < 4; i++) {
        if (i != g_Practice.homeAway) {
            continue;
        }
        if (g_Minigame._19D2[i] < 0xFFFE) {
            g_Minigame._19D2[i]++;
        } else {
            g_Minigame._19D2[i] = 0xFFFF;
        }
        if ((g_Controls[i].newButtonInput & 0x100) && g_Minigame._19E8[i]._0 >= 0 && g_Minigame._19E8[i]._6 == 0) {
            if (lbl_803C6028._7F[i] < 0 && g_Minigame._19E8[i]._0 == g_Minigame._19E8[i]._2 &&
                g_Minigame._19E8[i]._4 == g_Minigame._19E8[i]._5 && g_Minigame._19E8[i]._7 != 0 && g_Minigame._19E8[i]._8 != 0) {
                g_Minigame._19E8[i]._1 = 1;
                fn_800506E8(i, g_Minigame._19E8[i]._0, 1);
                fn_800628D4(g_Minigame._19E8[i]._0);
                g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
                g_Practice.practiceState = 3;
            }
        } else if (g_Controls[i].newButtonInput & 0x200) {
            g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
            g_Practice.practiceState = 5;
            sndFXStartEx(441, lbl_800EFBA4[2], 63, 0);
            return;
        } else {
            prev = g_Minigame._19E8[i]._0;
            sel = fn_80050760(i, g_Controls[i].buttonInput, g_Controls[i].newButtonInput, g_Controls[i]._08, 0);
            if (sel >= 0) {
                g_Minigame._19E8[i]._0 = sel;
                if (prev != g_Minigame._19E8[i]._0) {
                    g_Minigame._19D2[i] = 0;
                    g_Minigame.battingHandedness[i] = lbl_8034E9A0._0000[g_Minigame._19E8[i]._0].stats.BattingStance +
                                                      lbl_8034E9A0._0000[g_Minigame._19E8[i]._0].stats.FieldingArm * 2;
                }
                g_Minigame._19E8[i]._6 = 0;
            } else {
                g_Minigame._19E8[i]._0 = fn_8004FD64(i);
                g_Minigame._19E8[i]._6 = 1;
                g_Minigame._19E8[i]._7 = 0;
            }
        }
        if (g_Controls[i].newButtonInput & 0x400) {
            g_Minigame.battingHandedness[i]++;
            if (g_Minigame.battingHandedness[i] > 3) {
                g_Minigame.battingHandedness[i] = 0;
            }
            sndFXStartEx(439, lbl_800EFBA4[0], 63, 0);
        }
    }
}
