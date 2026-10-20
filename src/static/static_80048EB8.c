#include "static/static_80048EB8.h"
#include "static/orderchange.h"
#include "static/spani_default.h"
#include "static/static_8004157C.h"
#include "Dolphin/os.h"
#include "string.h"
#include "musyx/musyx.h"
#include "static/UnknownHomes_Static.h"

extern struct {
    /* 0x00 */ u8 _00[0x2C];
    /* 0x2C */ u16 _2C;
    /* 0x2E */ u8 _2E;
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u16 _30;
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34;
    /* 0x35 */ u8 _35;
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 dir[4];
    /* 0x3B */ s8 option[5];
    /* 0x40 */ s8 prevOption[5];
    /* 0x45 */ s8 toggle[4][4];
    /* 0x55 */ s8 prevToggle[4][4];
    /* 0x65 */ s8 cursor[4];
    /* 0x69 */ s8 prevCursor[4];
} lbl_803C5F04;

extern struct {
    /* 0x00 */ u8 _00[0x55];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[0x5D - 0x57];
    /* 0x5D */ u8 _5D;
    /* 0x5E */ u8 _5E;
} lbl_803C66B0;

typedef struct PadButtons {
    /* 0x0 */ u16 held;
    /* 0x2 */ u16 pressed;
    /* 0x4 */ u16 repeat;
} PadButtons; // size: 0x6

extern struct {
    /* 0x0000 */ u8 _0000[0x46F8];
    /* 0x46F8 */ s8 port[4];
    /* 0x46FC */ u8 _46FC[0x4704 - 0x46FC];
    /* 0x4704 */ u8 _4704;
    /* 0x4705 */ u8 _4705[0x472C - 0x4705];
    /* 0x472C */ PadButtons pads[4];
    /* 0x4744 */ u8 _4744[0x48AF - 0x4744];
    /* 0x48AF */ u8 _48AF;
    /* 0x48B0 */ u8 _48B0;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[7];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
    /* 0x0A */ u8 _0A[0x26 - 0x0A];
    /* 0x26 */ u8 _26;
} lbl_8034E978;

extern u16 lbl_800FEF70[];

extern struct {
    /* 0x00 */ u8 _00[0xF];
    /* 0x0F */ u8 _0F;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12[0x36 - 0x12];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
} lbl_803C5EA4;

typedef struct PlayerOptions {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6;
} PlayerOptions; // size: 0x7

extern struct {
    /* 0x00 */ u8 innings;
    /* 0x01 */ u8 _01[3];
    /* 0x04 */ u8 _04;
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06;
    /* 0x07 */ PlayerOptions players[5];
} gameInitOptions;

extern struct {
    /* 0x0000 */ u8 _0000[0xCF40];
    /* 0xCF40 */ u8 _CF40;
} lbl_803297E0;


extern u8 lbl_803C5EE0[0x16];

extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
} lbl_8037169C;

extern struct {
    /* 0x00 */ u8 _00[4];
    /* 0x04 */ u8 _04[4];
    /* 0x08 */ u8 _08[4];
} lbl_803C5EF8;

typedef struct ChallengeInnings {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2;
} ChallengeInnings; // size: 0x3

extern ChallengeInnings lbl_8010B600[];

extern struct {
    /* 0x0000 */ u8 _0000[0x16C2];
    /* 0x16C2 */ s16 _16C2;
    /* 0x16C4 */ u8 _16C4[0x441D - 0x16C4];
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ u8 _441F;
} starMissionCompletionTracker;

extern u8 lbl_800EFBA4[16];

extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800B0A14_removeQueue(void);
extern void changeScene(s32 arg0, s32 arg1);
extern void fn_800569C8(void);
extern void fn_800625A4(s32 arg0, s32 arg1);
extern void fn_80062A74(void);
extern void fn_80062674(s32 arg0);
extern void fn_80021410(void);

s32 lbl_803CBCF0;

// .text:0x8004A0FC size:0xC0
void fn_8004A0FC(void) {
    s32 i;

    lbl_803C5F04.option[0] = 0;
    lbl_803C5F04.prevOption[0] = 0;
    lbl_803C5F04.option[1] = 1;
    lbl_803C5F04.option[2] = 1;
    lbl_803C5F04.option[3] = 2;
    lbl_803C5F04.option[4] = 0;
    lbl_803C5F04.prevOption[1] = 1;
    lbl_803C5F04.prevOption[2] = 1;
    lbl_803C5F04.prevOption[3] = 2;
    lbl_803C5F04.prevOption[4] = 0;
    for (i = 0; i < 4; i++) {
        lbl_803C5F04.toggle[i][0] = 0;
        lbl_803C5F04.toggle[i][1] = 0;
        lbl_803C5F04.toggle[i][2] = 0;
        lbl_803C5F04.toggle[i][3] = 1;
        lbl_803C5F04.prevToggle[i][0] = 0;
        lbl_803C5F04.prevToggle[i][1] = 0;
        lbl_803C5F04.prevToggle[i][2] = 0;
        lbl_803C5F04.prevToggle[i][3] = 1;
    }
}

// .text:0x80049D8C size:0x370
void fn_80049D8C(u8 dir, u8 team) {
    s32 count = 0;
    s32 row;

    lbl_803C5F04.prevCursor[team] = lbl_803C5F04.cursor[team];
    row = lbl_803C5F04.cursor[team];
    if (row == 0 && lbl_803C5F04._36 == 0) {
        return;
    }
    lbl_803C5F04.dir[team] = dir;
    if (dir == 0) {
        if (lbl_803C5F04._36 == 0) {
            if (row == 2 || row == 4) {
                goto next;
            }
        prev:
            lbl_803C5F04.prevOption[row] = lbl_803C5F04.option[row];
            lbl_803C5F04.option[row]--;
            switch (row) {
            case 3:
                count = 5;
                break;
            case 1:
            case 2:
            case 4:
                count = 2;
                break;
            }
            if (lbl_803C5F04.option[row] < 0) {
                lbl_803C5F04.option[row] = count - 1;
            }
            if (lbl_803C5F04.prevOption[row] != lbl_803C5F04.option[row]) {
                fn_800625A4(team, 0x30);
                sndFXRelated(2);
            }
        } else {
            lbl_803C5F04.prevToggle[team][row] = lbl_803C5F04.toggle[team][row];
            switch (row) {
            case 0:
                if (lbl_803C5F04.toggle[team][0] != 0) {
                    lbl_803C5F04.toggle[team][0] = 0;
                }
                break;
            case 1:
                if (lbl_803C5F04.toggle[team][1] != 0) {
                    lbl_803C5F04.toggle[team][1] = 0;
                }
                break;
            case 2:
                if (lbl_803C5F04.toggle[team][2] != 0) {
                    lbl_803C5F04.toggle[team][2] = 0;
                }
                break;
            case 3:
                if (lbl_803C5F04.toggle[team][3] == 0) {
                    lbl_803C5F04.toggle[team][3] = 1;
                }
                break;
            }
            if (lbl_803C5F04.prevToggle[team][row] != lbl_803C5F04.toggle[team][row]) {
                fn_800625A4(team, 0x30);
                sndFXRelated(2);
            }
        }
    } else {
        if (lbl_803C5F04._36 == 0) {
            if (row == 2 || row == 4) {
                goto prev;
            }
        next:
            lbl_803C5F04.prevOption[row] = lbl_803C5F04.option[row];
            lbl_803C5F04.option[row]++;
            switch (row) {
            case 3:
                count = 5;
                break;
            case 1:
            case 2:
            case 4:
                count = 2;
                break;
            }
            if (lbl_803C5F04.option[row] == count) {
                lbl_803C5F04.option[row] = 0;
            }
            if (lbl_803C5F04.prevOption[row] != lbl_803C5F04.option[row]) {
                fn_800625A4(team, 0x30);
                sndFXRelated(2);
            }
        } else {
            lbl_803C5F04.prevToggle[team][row] = lbl_803C5F04.toggle[team][row];
            switch (row) {
            case 0:
                if (lbl_803C5F04.toggle[team][0] == 0) {
                    lbl_803C5F04.toggle[team][0] = 1;
                }
                break;
            case 1:
                if (lbl_803C5F04.toggle[team][1] == 0) {
                    lbl_803C5F04.toggle[team][1] = 1;
                }
                break;
            case 2:
                if (lbl_803C5F04.toggle[team][2] == 0) {
                    lbl_803C5F04.toggle[team][2] = 1;
                }
                break;
            case 3:
                if (lbl_803C5F04.toggle[team][3] != 0) {
                    lbl_803C5F04.toggle[team][3] = 0;
                }
                break;
            }
            if (lbl_803C5F04.prevToggle[team][row] != lbl_803C5F04.toggle[team][row]) {
                fn_800625A4(team, 0x30);
                sndFXRelated(2);
            }
        }
    }
}

// .text:0x80049D3C size:0x50
void fn_80049D3C(void) {
    s32 i;

    if (g_d_GameSettings.GameModeSelected != 6 && lbl_803C5F04._36 != 0) {
        for (i = 0; i < (g_d_GameSettings.GameModeSelected == 6 ? 4 : 2); i++) {
        }
    }
}

// .text:0x80049C80 size:0xBC
void fn_80049C80(void) {
    if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
        return;
    }
    if (g_d_GameSettings.GameModeSelected == 5 && lbl_8037169C._12 == 0) {
        changeScene(1, 6);
    }
    lbl_803C5EA4._36 = 1;
    lbl_803C5EA4._37 = lbl_803C5EA4._38;
    lbl_803C5EA4._38 = 3;
    possiblyTransferDataBetweenDifferentRels();
    memset(lbl_803C5EE0, 0, sizeof(lbl_803C5EE0));
    fn_800569C8();
    fn_800625A4(0, 0x29);
}

// .text:0x80049878 size:0x408
static inline void LoadToggles(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (g_d_GameSettings.PlayerPorts[i] < 4) {
            lbl_803C5F04.toggle[i][0] = gameInitOptions.players[g_d_GameSettings.PlayerPorts[i]]._6;
            lbl_803C5F04.toggle[i][1] = gameInitOptions.players[g_d_GameSettings.PlayerPorts[i]]._3;
            lbl_803C5F04.toggle[i][2] = gameInitOptions.players[g_d_GameSettings.PlayerPorts[i]]._2;
            lbl_803C5F04.toggle[i][3] = gameInitOptions.players[g_d_GameSettings.PlayerPorts[i]]._4;
        } else {
            lbl_803C5F04.toggle[i][0] = gameInitOptions.players[i]._6;
            lbl_803C5F04.toggle[i][1] = gameInitOptions.players[i]._3;
            lbl_803C5F04.toggle[i][2] = gameInitOptions.players[i]._2;
            lbl_803C5F04.toggle[i][3] = gameInitOptions.players[i]._4;
        }
    }
}

void possiblyTransferDataBetweenDifferentRels(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        lbl_803C5EF8._00[i] = 0;
        lbl_803C5EF8._04[i] = 0;
    }
    lbl_803C5F04._2E = 0;
    if (lbl_8034E9A0._4704 == 0) {
        fn_8004A0FC();
        lbl_8034E9A0._4704 = 1;
    } else {
        LoadToggles();
        lbl_803C5F04.option[1] = g_d_GameSettings.home_AwaySetting;
        lbl_803C5F04.option[2] = gameInitOptions._04;
        lbl_803C5F04.option[3] = gameInitOptions.innings / 2u;
        if (gameInitOptions._05 == 10) {
            lbl_803C5F04.option[4] = 1;
        } else {
            lbl_803C5F04.option[4] = 0;
        }
        gameInitOptions._06 = 0;
    }
    if (g_d_GameSettings.GameModeSelected == 5) {
        LoadToggles();
        lbl_803C5F04.option[1] = 0;
        lbl_803C5F04.option[4] = 1;
        lbl_803C5F04.option[2] = 1;
        lbl_803C5F04.prevOption[1] = lbl_803C5F04.option[1] = 0;
        lbl_803C5F04.option[4] = lbl_803C5F04.prevOption[4] = 1;
        if (starMissionCompletionTracker._441D != 9) {
            s32 kind = starMissionCompletionTracker._441F;

            if (kind == 9) {
                lbl_803C5F04.option[3] = lbl_8010B600[g_d_GameSettings.challengeDifficulty]._1 / 2u;
            } else if (kind != 9 && starMissionCompletionTracker._441D != 9) {
                lbl_803C5F04.option[3] = lbl_8010B600[g_d_GameSettings.challengeDifficulty]._0 / 2u;
            }
        } else if (starMissionCompletionTracker._16C2 == 0x2A) {
            lbl_803C5F04.option[3] = lbl_8010B600[g_d_GameSettings.challengeDifficulty]._1 / 2u;
        } else {
            lbl_803C5F04.option[3] = lbl_8010B600[g_d_GameSettings.challengeDifficulty]._0 / 2u;
        }
    }
    if (g_d_GameSettings._06 == 2) {
        lbl_803C5F04._36 = 1;
        for (i = 0; i < 4; i++) {
            lbl_803C5F04.prevCursor[i] = 0;
            lbl_803C5F04.cursor[i] = 0;
        }
        lbl_803C5F04._30 = 3;
    } else {
        lbl_803C5F04.prevCursor[0] = 0;
        lbl_803C5F04.cursor[0] = 0;
        lbl_803C5F04._36 = 0;
        lbl_803C5F04._30 = 1;
    }
}

// .text:0x800494CC size:0x3AC
// Registers only: the target keeps team in r7 and found in r8, one above these
void fn_800494CC(u8 team) {
    s8* portp;
    s32 i;
    u8 found = FALSE;
    s8 port;
    u16 pressed;
    s32 row;
    s32 count;

    if (lbl_803C66B0._5D != 0 || lbl_803C66B0._5E != 0) {
        return;
    }
    portp = &lbl_8034E9A0.port[team];
    port = *portp;
    for (i = 0; i < 2; i++) {
        if (g_d_GameSettings.PlayerPorts[i] == port) {
            found = TRUE;
        }
    }
    *portp = port;
    if (!found) {
        return;
    }
    pressed = lbl_8034E9A0.pads[team].pressed;
    if (lbl_8034E9A0.pads[team].repeat & 8 || lbl_8034E9A0.pads[team].repeat & 4) {
        if (g_d_GameSettings.GameModeSelected == 5) {
            return;
        }
        lbl_803C5F04.prevCursor[0] = lbl_803C5F04.cursor[0];
        row = lbl_803C5F04.cursor[0];
        if (lbl_803C5F04._36 == 0) {
            count = 5;
        } else if (g_d_GameSettings.GameModeSelected != 6) {
            count = 4;
        } else {
            count = 2;
        }
        if (lbl_8034E9A0.pads[team].repeat & 8) {
            if (--row < 0) {
                if (lbl_803C5F04._36 == 0) {
                    row = 4;
                } else {
                    row = 3;
                }
            }
            fn_800625A4(0, 0x30);
            sndFXRelated(8);
        } else if (lbl_8034E9A0.pads[team].repeat & 4) {
            if (++row == count) {
                row = 0;
            }
            fn_800625A4(0, 0x30);
            sndFXRelated(4);
        }
        lbl_803C5F04.cursor[0] = row;
    } else if (lbl_8034E9A0.pads[team].repeat & 1) {
        fn_80049D8C(0, 0);
    } else if (lbl_8034E9A0.pads[team].repeat & 2) {
        fn_80049D8C(1, 0);
    } else if (pressed & 0x20) {
        if (g_d_GameSettings._06 != 2) {
            lbl_803C5F04._36 = 1;
            lbl_803C5F04._30 = 3;
            lbl_803C5F04.prevCursor[0] = lbl_803C5F04.cursor[0];
            lbl_803C5F04.cursor[0] = 0;
            if (g_d_GameSettings.GameModeSelected == 5) {
                lbl_8034E978._00 = 0x15;
                lbl_8034E978._09 = lbl_8034E978._08;
                lbl_8034E978._08 = lbl_800FEF70[0xAC];
            } else {
                lbl_8034E978._00 = 7;
                lbl_8034E978._09 = lbl_8034E978._08;
                lbl_8034E978._08 = lbl_800FEF70[0x3C];
            }
            fn_800625A4(0, 0x2B);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pressed & 0x100) {
        if (lbl_803C5F04.cursor[0] == 0) {
            if (g_d_GameSettings.GameModeSelected != 5) {
                fn_800625A4(0, 0x31);
                lbl_803C5F04._35 = 0;
            } else {
                lbl_8034E9A0._48B0 = 1;
                lbl_803C5EE0[0x15] = 1;
                fn_80062A74();
                fn_80021410();
                lbl_803C5F04._35 = 1;
            }
            changeScene(0xF, 6);
            lbl_803C5F04._30 = 5;
            lbl_803C5F04._34 = 1;
            sndFXRelated(0x100);
        }
    } else if (pressed & 0x200) {
        if (lbl_803C5F04.cursor[0] != 0) {
            lbl_803C5F04.prevCursor[0] = lbl_803C5F04.cursor[0];
            lbl_803C5F04.cursor[0] = 0;
            fn_800625A4(0, 0x30);
        } else {
            lbl_803CBCF0 = 0;
            fn_800625A4(0, 0x2A);
            lbl_803C5F04._30 = 5;
            lbl_803C5F04._34 = 0;
            lbl_803C5F04._35 = 1;
        }
        sndFXRelated(0x200);
    }
}

// .text:0x80049220 size:0x2AC
// fn_80049220 zeroes its stack copy of the buttons before filling it, and keeps the stores;
// this copy through GetPad stores them once, so the registers and stack differ
static inline PadButtons GetPad(s32 port) {
    PadButtons pad;

    pad.held = lbl_8034E9A0.pads[port].held;
    pad.pressed = lbl_8034E9A0.pads[port].pressed;
    pad.repeat = lbl_8034E9A0.pads[port].repeat;
    return pad;
}

void fn_80049220(u8 team) {
    PadButtons pad;
    s8 port;
    u8 found = FALSE;
    s32 row;
    s32 count;

    if (g_d_GameSettings.PlayerPorts[team] == lbl_8034E9A0.port[team]) {
        port = team;
        found = TRUE;
    }
    if (!found) {
        return;
    }
    if (lbl_803C66B0._5D != 0 || lbl_803C66B0._5E != 0) {
        return;
    }
    pad = GetPad(port);
    if (pad.repeat & 8 || pad.repeat & 4) {
        lbl_803C5F04.prevCursor[(u8)port] = lbl_803C5F04.cursor[(u8)port];
        row = lbl_803C5F04.cursor[(u8)port];
        if (lbl_803C5F04._36 == 0) {
            count = 5;
        } else if (g_d_GameSettings.GameModeSelected != 6) {
            count = 4;
        } else {
            count = 2;
        }
        if (pad.repeat & 8) {
            if (--row < 0) {
                if (lbl_803C5F04._36 == 0) {
                    row = 4;
                } else {
                    row = 3;
                }
            }
            fn_800625A4((u8)port, 0x30);
            sndFXRelated(8);
        } else if (pad.repeat & 4) {
            if (++row == count) {
                row = 0;
            }
            fn_800625A4((u8)port, 0x30);
            sndFXRelated(4);
        }
        lbl_803C5F04.cursor[(u8)port] = row;
    } else if (pad.repeat & 1) {
        fn_80049D8C(0, port);
    } else if (pad.repeat & 2) {
        fn_80049D8C(1, port);
    } else if ((pad.pressed & 0x40 || pad.pressed & 0x200) && g_d_GameSettings._06 != 2 && lbl_803C5F04._36 == 1) {
        lbl_803C5F04._36 = 0;
        lbl_803C5F04._30 = 2;
        if (g_d_GameSettings.GameModeSelected == 5) {
            lbl_8034E978._00 = 0x14;
            lbl_8034E978._09 = lbl_8034E978._08;
            lbl_8034E978._08 = lbl_800FEF70[0xA4];
        } else {
            lbl_8034E978._00 = 6;
            lbl_8034E978._09 = lbl_8034E978._08;
            lbl_8034E978._08 = lbl_800FEF70[0x34];
        }
        fn_800625A4(0, 0x2C);
        if (pad.pressed & 0x200) {
            sndFXRelated(0x200);
        } else {
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    }
}

// .text:0x80048EB8 size:0x368
void startGameRelated(void) {
    s32 i;

    switch (lbl_803C5F04._35) {
    case 0:
        lbl_803C5EE0[0x15] = 1;
        lbl_8034E9A0._48AF = 1;
        lbl_8034E978._26 = 1;
        fn_80062A74();
        fn_80021410();
        lbl_803C5F04._35++;
        break;
    case 1:
        if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
            if (lbl_803C66B0._5D == 0x31 && lbl_803C66B0._5E != 0) {
                fn_80062674(1);
            }
            break;
        }
        for (i = 0; i < 2; i++) {
            if (g_d_GameSettings.PlayerPorts[i] < 4) {
                gameInitOptions.players[g_d_GameSettings.PlayerPorts[i]]._6 = lbl_803C5F04.toggle[i][0];
                gameInitOptions.players[g_d_GameSettings.PlayerPorts[i]]._3 = lbl_803C5F04.toggle[i][1];
                gameInitOptions.players[g_d_GameSettings.PlayerPorts[i]]._2 = lbl_803C5F04.toggle[i][2];
                gameInitOptions.players[g_d_GameSettings.PlayerPorts[i]]._4 = lbl_803C5F04.toggle[i][3];
            } else {
                gameInitOptions.players[i]._6 = lbl_803C5F04.toggle[i][0];
                gameInitOptions.players[i]._3 = lbl_803C5F04.toggle[i][1];
                gameInitOptions.players[i]._2 = lbl_803C5F04.toggle[i][2];
                gameInitOptions.players[i]._4 = lbl_803C5F04.toggle[i][3];
            }
        }
        g_d_GameSettings.home_AwaySetting = lbl_803C5F04.option[1];
        gameInitOptions._04 = lbl_803C5F04.option[2];
        gameInitOptions.innings = lbl_803C5F04.option[3] * 2 + 1;
        if (lbl_803C5F04.option[4] != 0) {
            gameInitOptions._05 = 10;
        } else {
            gameInitOptions._05 = 0;
        }
        gameInitOptions._06 = 0;
        if (lbl_803C5F04._34 == 1) {
            if (g_d_GameSettings.GameModeSelected != 5) {
                fn_80035CA4(0xF);
                fn_80035CA4(0x12);
                fn_80035CA4(9);
                fn_80035CA4(6);
                lbl_803C5EA4._0F = 0;
                OSReport("Goto Game ..... option end \n");
                fn_80042D38(4);
            } else {
                transferStatsToInMemRoster(0);
                capApplicationFunction();
                fn_80035CA4(0xF);
                fn_80035CA4(9);
                fn_80035CA4(6);
                fn_80021410();
                lbl_803297E0._CF40 = 0;
                lbl_803C5EA4._0F = 0;
                changeScene(0xF, 6);
                lbl_803C5EA4._11 = 0;
                lbl_8034E9A0._48AF = 1;
                lbl_8034E978._26 = 1;
                fn_80042D38(4);
            }
        } else if (g_d_GameSettings.GameModeSelected != 5) {
            lbl_803C5EA4._36 = 1;
            lbl_803C5EA4._37 = lbl_803C5EA4._38;
            lbl_803C5EA4._38 = 2;
            lbl_8034E978._00 = 5;
            lbl_8034E978._09 = lbl_8034E978._08;
            lbl_8034E978._08 = lbl_800FEF70[0x2C];
            fn_80042D38(0xC);
        } else {
            lbl_803C5F04._32 = 0;
            lbl_803C5EE0[0x15] = 1;
            fn_80042D38(0xB);
        }
        lbl_803C5F04._35 = 0;
        lbl_803C5F04._30 = 0;
        fn_800B0A14_removeQueue();
        break;
    }
}
