#include "game/rep_D18.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"

typedef struct AramEntryD18 {
    /* 0x0 */ u32 _0[4];
} AramEntryD18; // size: 0x10

extern int fn_8004CA6C(u16 buttons);
extern void fn_8004CC2C(void);

AramEntryD18 lbl_3_data_3D60 = { { 0x0000040B, 0x400098A0, 0x0773D800, 0x00003C88 } };
AramEntryD18 lbl_3_data_3D70 = { { 0x0000040B, 0x40000970, 0x07741800, 0x00000368 } };
AramEntryD18 lbl_3_data_3D80[67] = {
    { { 0x0000040B, 0x4013764C, 0x1A635000, 0x0007DB48 } },
    { { 0x0000040B, 0x4003E3DC, 0x1A6B3000, 0x00021420 } },
    { { 0x0000040B, 0x4002EC10, 0x1A6D4800, 0x00013108 } },
    { { 0x0000040B, 0x400E72C0, 0x1A6E8000, 0x00060768 } },
    { { 0x0000040B, 0x40049404, 0x1A748800, 0x00020E34 } },
    { { 0x0000040B, 0x40076AE0, 0x18ED7000, 0x00036BC8 } },
    { { 0x0000040B, 0x4010FD70, 0x1A769800, 0x0005E284 } },
    { { 0x0000040B, 0x400DB738, 0x1A7C8000, 0x00049AB4 } },
    { { 0x0000040B, 0x400E9864, 0x1A812000, 0x00059DC0 } },
    { { 0x0000040B, 0x400B7718, 0x1A86C000, 0x00050288 } },
    { { 0x0000040B, 0x400D87FC, 0x1A8BC800, 0x00047BC4 } },
    { { 0x0000040B, 0x400D643C, 0x1A904800, 0x0004E3AC } },
    { { 0x0000040B, 0x400D5C7C, 0x1A953000, 0x00048D9C } },
    { { 0x0000040B, 0x400B767C, 0x1A99C000, 0x00047518 } },
    { { 0x0000040B, 0x400441F8, 0x1A9E3800, 0x0001AA84 } },
    { { 0x0000040B, 0x40106568, 0x1A9FE800, 0x00068C10 } },
    { { 0x0000040B, 0x4010E5A0, 0x0E97A800, 0x0009BCAC } },
    { { 0x0000040B, 0x40016980, 0x0EA16800, 0x0000D6C4 } },
    { { 0x0000040B, 0x40016980, 0x0EA24000, 0x0000C944 } },
    { { 0x0000040B, 0x40016980, 0x0EA31000, 0x0000E700 } },
    { { 0x0000040B, 0x40016980, 0x0EA3F800, 0x0000D64C } },
    { { 0x0000040B, 0x40016980, 0x0EA4D000, 0x0000C900 } },
    { { 0x0000040B, 0x40016980, 0x0EA5A000, 0x0000CFFC } },
    { { 0x0000040B, 0x40016980, 0x0EA67000, 0x0000D720 } },
    { { 0x0000040B, 0x40016980, 0x0EA74800, 0x0000D6CC } },
    { { 0x0000040B, 0x40016980, 0x0EA82000, 0x0000D21C } },
    { { 0x0000040B, 0x40016980, 0x0EA8F800, 0x0000D0BC } },
    { { 0x0000040B, 0x40016980, 0x0EA9D000, 0x0000B544 } },
    { { 0x0000040B, 0x40016980, 0x0EAA8800, 0x0000C4F8 } },
    { { 0x0000040B, 0x400ADFFC, 0x18AEE800, 0x0004BAB0 } },
    { { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 } },
    { { 0x0000040B, 0x4000A820, 0x18ED3800, 0x00003758 } },
    { { 0x0000040B, 0x4011EC24, 0x18F0E000, 0x000D8818 } },
    { { 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8 } },
    { { 0x0000040B, 0x4006C850, 0x06C96000, 0x0002C884 } },
    { { 0x0000040B, 0x4005B178, 0x06CC3000, 0x0003555C } },
    { { 0x0000040B, 0x401EB174, 0x18D43800, 0x000FB220 } },
    { { 0x0000040B, 0x4001ED60, 0x1AA67800, 0x0000CFF0 } },
    { { 0x0000040B, 0x4000BF30, 0x1AA74800, 0x000026E0 } },
    { { 0x0000040B, 0x40003498, 0x1AA77000, 0x00000E28 } },
    { { 0x0000040B, 0x4000BDE0, 0x1AA78000, 0x000024F4 } },
    { { 0x0000040B, 0x40006088, 0x1AA7A800, 0x00001290 } },
    { { 0x0000040B, 0x400049F0, 0x1AA7C000, 0x000018F4 } },
    { { 0x0000040B, 0x40005ECC, 0x1AA7E000, 0x00001D38 } },
    { { 0x0000040B, 0x40002670, 0x1AA80000, 0x00000BE8 } },
    { { 0x00000000, 0x00028240, 0x1AA81000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AAA9800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AAD2000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AAFA800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AB23000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AB4B800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AB74000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AB9C800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1ABC5000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1ABED800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AC16000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AC3E800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AC67000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AC8F800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1ACB8000, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1ACE0800, 0x00028240 } },
    { { 0x00000000, 0x00028240, 0x1AD09000, 0x00028240 } },
    { { 0x0000040B, 0x40001640, 0x08EB4800, 0x00000C38 } },
    { { 0x0000040B, 0x400B2D00, 0x08EB5800, 0x0006A948 } },
    { { 0x00000000, 0x00000686, 0x08F20800, 0x00000688 } },
    { { 0x00000000, 0x00003C98, 0x08F21000, 0x00003C98 } },
    { { 0x0000040B, 0x4000EBBC, 0x08F25000, 0x00009570 } },
};

// .text:0x0005B408 size:0x14 mapped:0x8069A49C
void fn_3_5B408(void) {
    g_GameLogic.frame_exitMenuShowing = 0;
}

// .text:0x0005B380 size:0x88 mapped:0x8069A414
int fn_3_5B380(u16 buttons) {
    if (g_GameLogic.frame_exitMenuShowing < 0x7FFE) {
        g_GameLogic.frame_exitMenuShowing++;
    } else {
        g_GameLogic.frame_exitMenuShowing = 0x7FFF;
    }
    if (g_GameLogic.frame_exitMenuShowing > 20) {
        int result = fn_8004CA6C(buttons);
        if (result == 1) {
            return 1;
        } else if (result == 2) {
            fn_8004CC2C();
        } else if (result == 4) {
            return 2;
        }
    }
    return 0;
}

// .text:0x0005B368 size:0x18 mapped:0x8069A3FC
void fn_3_5B368(void) {
    g_GameLogic.frames_memoryCardWriteOnMVP = 0;
    g_GameLogic.endGameStage = 0;
}

// .text:0x0005B220 size:0x148 mapped:0x8069A2B4
int fn_3_5B220(int arg) {
    return 0;
}

// .text:0x0005B0C4 size:0x15C mapped:0x8069A158
void fn_3_5B0C4(void) {
    return;
}

// .text:0x0005AE9C size:0x228 mapped:0x80699F30
void fn_3_5AE9C(void) {
    return;
}

// .text:0x0005AE0C size:0x90 mapped:0x80699EA0
void fn_3_5AE0C(void) {
    return;
}

// .text:0x0005ACA0 size:0x16C mapped:0x80699D34
void fn_3_5ACA0(void) {
    return;
}

// .text:0x0005A87C size:0x424 mapped:0x80699910
void fn_3_5A87C(void) {
    return;
}

// .text:0x0005A6FC size:0x180 mapped:0x80699790
void fn_3_5A6FC(void) {
    return;
}

// .text:0x0005A6D4 size:0x28 mapped:0x80699768
void fn_3_5A6D4(u8 status) {
    g_GameLogic.gameStatus_prev = g_GameLogic.gameStatus;
    g_GameLogic.FrameCountOfCurrentPitch = 0;
    g_GameLogic.gameStatus = status;
    g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
    g_GameLogic._125 = 0;
}

// .text:0x0005A6A0 size:0x34 mapped:0x80699734
void fn_3_5A6A0(int battingInd, int homeTeam, int arg2, int arg3) {
    g_GameLogic.homeTeamBattingInd_fieldingTeam = battingInd;
    g_GameLogic.awayTeamBattingInd_battingTeam = battingInd ^ 1;
    g_GameLogic.homeTeamInd = homeTeam;
    g_GameLogic.teamBatting = homeTeam ^ battingInd;
    g_GameLogic.teamFielding = g_GameLogic.teamBatting ^ 1;
    g_GameLogic._1C = arg2;
    g_GameLogic._20 = arg3;
}

// .text:0x0005A684 size:0x1C mapped:0x80699718
void fn_3_5A684(void) {
    g_Strikes.strikes = 0;
    g_Strikes.balls = 0;
    g_Strikes.outs = 0;
    g_Strikes.forcedOutToEndInningInd = 0;
}

// .text:0x0005A28C size:0x3F8 mapped:0x80699320
void fn_3_5A28C(void) {
    return;
}

// .text:0x00059F40 size:0x34C mapped:0x80698FD4
void fn_3_59F40(void) {
    return;
}

// .text:0x00059C2C size:0x314 mapped:0x80698CC0
void fn_3_59C2C(void) {
    return;
}
