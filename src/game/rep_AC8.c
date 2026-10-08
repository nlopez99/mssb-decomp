#include "game/rep_AC8.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_18E8.h"
#include "game/rep_1188.h"
#include "game/rep_1CB8.h"
#include "game/rep_3E58.h"
#include "game/rep_540.h"
#include "game/rep_D0.h"
#include "game/rep_720.h"
#include "game/m_sound.h"

typedef struct UnkAC8Fielder {
    /* 0x000 */ f32 _000;
    /* 0x004 */ f32 _004;
    /* 0x008 */ f32 _008;
    /* 0x00C */ u8 _00C[0x14 - 0xC];
    /* 0x014 */ f32 _014;
    /* 0x018 */ f32 _018;
    /* 0x01C */ f32 _01C;
    /* 0x020 */ u8 _020[0x28 - 0x20];
    /* 0x028 */ f32 _028;
    /* 0x02C */ f32 _02C;
    /* 0x030 */ f32 _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x48 - 0x40];
    /* 0x048 */ f32 _048;
    /* 0x04C */ f32 _04C;
    /* 0x050 */ f32 _050;
    /* 0x054 */ f32 _054;
    /* 0x058 */ f32 _058;
    /* 0x05C */ f32 _05C;
    /* 0x060 */ u8 _060[0x64 - 0x60];
    /* 0x064 */ f32 _064;
    /* 0x068 */ f32 _068;
    /* 0x06C */ u8 _06C[0x70 - 0x6C];
    /* 0x070 */ f32 _070;
    /* 0x074 */ f32 _074;
    /* 0x078 */ u8 _078[0x80 - 0x78];
    /* 0x080 */ f32 _080;
    /* 0x084 */ f32 _084[9];
    /* 0x0A8 */ f32 _0A8[4];
    /* 0x0B8 */ u8 _0B8[0xD4 - 0xB8];
    /* 0x0D4 */ f32 _0D4;
    /* 0x0D8 */ f32 _0D8;
    /* 0x0DC */ u8 _0DC[0xE8 - 0xDC];
    /* 0x0E8 */ f32 _0E8;
    /* 0x0EC */ u8 _0EC[0xF4 - 0xEC];
    /* 0x0F4 */ f32 _0F4;
    /* 0x0F8 */ u8 _0F8[0xFC - 0xF8];
    /* 0x0FC */ f32 _0FC;
    /* 0x100 */ u8 _100[0x118 - 0x100];
    /* 0x118 */ f32 _118;
    /* 0x11C */ f32 _11C;
    /* 0x120 */ u8 _120[0x128 - 0x120];
    /* 0x128 */ f32 _128;
    /* 0x12C */ f32 _12C;
    /* 0x130 */ f32 _130;
    /* 0x134 */ u8 _134[0x140 - 0x134];
    /* 0x140 */ f32 _140;
    /* 0x144 */ f32 _144;
    /* 0x148 */ f32 _148;
    /* 0x14C */ u8 _14C[0x150 - 0x14C];
    /* 0x150 */ f32 _150;
    /* 0x154 */ f32 _154;
    /* 0x158 */ f32 _158;
    /* 0x15C */ f32 _15C;
    /* 0x160 */ f32 _160;
    /* 0x164 */ f32 _164;
    /* 0x168 */ f32 _168;
    /* 0x16C */ u8 _16C[0x174 - 0x16C];
    /* 0x174 */ f32 _174;
    /* 0x178 */ u8 _178[0x17A - 0x178];
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x17E - 0x17C];
    /* 0x17E */ s16 _17E;
    /* 0x180 */ u8 _180[0x184 - 0x180];
    /* 0x184 */ s16 _184;
    /* 0x186 */ s16 _186;
    /* 0x188 */ u8 _188[0x18A - 0x188];
    /* 0x18A */ s16 _18A;
    /* 0x18C */ s16 _18C;
    /* 0x18E */ u8 _18E[0x190 - 0x18E];
    /* 0x190 */ s16 _190;
    /* 0x192 */ u8 _192[0x194 - 0x192];
    /* 0x194 */ s16 _194;
    /* 0x196 */ u8 _196[0x198 - 0x196];
    /* 0x198 */ s16 _198;
    /* 0x19A */ s16 _19A;
    /* 0x19C */ s16 _19C;
    /* 0x19E */ s16 _19E;
    /* 0x1A0 */ s16 _1A0;
    /* 0x1A2 */ u8 _1A2[0x1A4 - 0x1A2];
    /* 0x1A4 */ s16 _1A4;
    /* 0x1A6 */ u8 _1A6[0x1AC - 0x1A6];
    /* 0x1AC */ s16 _1AC;
    /* 0x1AE */ s16 _1AE;
    /* 0x1B0 */ s16 _1B0;
    /* 0x1B2 */ s16 _1B2;
    /* 0x1B4 */ s16 _1B4;
    /* 0x1B6 */ s16 _1B6;
    /* 0x1B8 */ s16 _1B8;
    /* 0x1BA */ s16 _1BA;
    /* 0x1BC */ s16 _1BC;
    /* 0x1BE */ s16 _1BE;
    /* 0x1C0 */ s16 _1C0;
    /* 0x1C2 */ s16 _1C2;
    /* 0x1C4 */ u8 _1C4;
    /* 0x1C5 */ u8 _1C5;
    /* 0x1C6 */ u8 _1C6;
    /* 0x1C7 */ u8 _1C7[0x1CA - 0x1C7];
    /* 0x1CA */ u8 _1CA;
    /* 0x1CB */ u8 _1CB[0x1CC - 0x1CB];
    /* 0x1CC */ u8 _1CC;
    /* 0x1CD */ u8 _1CD[0x1D1 - 0x1CD];
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4;
    /* 0x1D5 */ u8 _1D5;
    /* 0x1D6 */ u8 _1D6;
    /* 0x1D7 */ u8 _1D7;
    /* 0x1D8 */ u8 _1D8[0x1D9 - 0x1D8];
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ u8 _1DA[0x1DC - 0x1DA];
    /* 0x1DC */ u8 _1DC;
    /* 0x1DD */ u8 _1DD;
    /* 0x1DE */ u8 _1DE;
    /* 0x1DF */ u8 _1DF;
    /* 0x1E0 */ u8 _1E0[0x1E3 - 0x1E0];
    /* 0x1E3 */ u8 _1E3;
    /* 0x1E4 */ u8 _1E4[0x1E8 - 0x1E4];
    /* 0x1E8 */ u8 _1E8;
    /* 0x1E9 */ u8 _1E9;
    /* 0x1EA */ u8 _1EA[0x1EE - 0x1EA];
    /* 0x1EE */ u8 _1EE;
    /* 0x1EF */ u8 _1EF[0x1F0 - 0x1EF];
    /* 0x1F0 */ u8 _1F0;
    /* 0x1F1 */ u8 _1F1;
    /* 0x1F2 */ u8 _1F2;
    /* 0x1F3 */ u8 _1F3[0x1F5 - 0x1F3];
    /* 0x1F5 */ s8 _1F5;
    /* 0x1F6 */ u8 _1F6[0x1FA - 0x1F6];
    /* 0x1FA */ u8 _1FA;
    /* 0x1FB */ u8 _1FB[0x1FC - 0x1FB];
    /* 0x1FC */ u8 _1FC;
    /* 0x1FD */ u8 _1FD[0x1FF - 0x1FD];
    /* 0x1FF */ u8 _1FF;
    /* 0x200 */ u8 _200[0x201 - 0x200];
    /* 0x201 */ u8 _201;
    /* 0x202 */ u8 _202[0x203 - 0x202];
    /* 0x203 */ u8 _203;
    /* 0x204 */ u8 _204;
    /* 0x205 */ u8 _205;
    /* 0x206 */ u8 _206[0x207 - 0x206];
    /* 0x207 */ u8 _207;
    /* 0x208 */ u8 _208[0x209 - 0x208];
    /* 0x209 */ u8 _209;
    /* 0x20A */ u8 _20A[0x20B - 0x20A];
    /* 0x20B */ u8 _20B;
    /* 0x20C */ u8 _20C;
    /* 0x20D */ u8 _20D;
    /* 0x20E */ u8 _20E[0x20F - 0x20E];
    /* 0x20F */ u8 _20F;
    /* 0x210 */ u8 _210;
    /* 0x211 */ u8 _211;
    /* 0x212 */ u8 _212;
    /* 0x213 */ u8 _213;
    /* 0x214 */ u8 _214[0x216 - 0x214];
    /* 0x216 */ u8 _216;
    /* 0x217 */ u8 _217;
    /* 0x218 */ u8 _218[0x21C - 0x218];
    /* 0x21C */ f32 _21C;
    /* 0x220 */ f32 _220;
    /* 0x224 */ f32 _224;
    /* 0x228 */ u8 _228[0x24C - 0x228];
    /* 0x24C */ s16 _24C;
    /* 0x24E */ s16 _24E;
    /* 0x250 */ u8 _250[0x252 - 0x250];
    /* 0x252 */ u8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ u8 _254;
    /* 0x255 */ u8 _255;
    /* 0x256 */ u8 _256;
    /* 0x257 */ u8 _257;
    /* 0x258 */ u8 _258[0x259 - 0x258];
    /* 0x259 */ u8 _259;
    /* 0x25A */ u8 _25A;
    /* 0x25B */ u8 _25B;
    /* 0x25C */ u8 _25C;
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E;
    /* 0x25F */ u8 _25F;
    /* 0x260 */ u8 _260;
    /* 0x261 */ u8 _261;
    /* 0x262 */ u8 _262;
    /* 0x263 */ u8 _263;
    /* 0x264 */ u8 _264;
    /* 0x265 */ u8 _265[0x268 - 0x265];
} UnkAC8Fielder; // size: 0x268

extern UnkAC8Fielder g_Fielders[9];

extern struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ s16 _04;
    /* 0x06 */ u8 _06[0x10 - 0x6];
    /* 0x10 */ u8 _10;
} g_RunningLogic;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ struct UnkPlayer3E58* _2C50[9];
} lbl_8036E548;

// rep_1838.h declares fn_3_9FB8C as returning s16 and fn_3_9FCF8 as taking s16s: callers here
// sign-extend fn_3_9FB8C's result and pass fn_3_9FCF8 unextended ints, which it extends itself.
extern s16 radToShortAngle(f32 v);
extern s32 fn_3_9FB8C(f32 x, f32 y);
extern s16 fn_3_9FCA4(s16 a, s16 b);
extern s16 fn_3_9FCF8(s32 a, s32 b);
extern void getComponentsFromSAng(s16 ang, f32* x, f32* y);
extern bool calculateLineIntersection(VecXZ* out, VecXZ* a, VecXZ* b);
extern u8 lbl_3_data_46F8[][9];

typedef struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ f32 _08;
    /* 0x0C */ u8 _0C[0x14 - 0xC];
} UnkAC8Data47D0; // size: 0x14

extern UnkAC8Data47D0 lbl_3_data_47D0[6];
extern VecXZ lbl_3_data_4444[5];
extern VecXZ lbl_3_data_450C[9];
extern VecXZ lbl_3_data_4554[4][3];
extern VecXZ lbl_3_data_45B4[4];
extern VecXZ lbl_3_data_45D4[4];

typedef struct {
    /* 0x0 */ f32 _0;
    /* 0x4 */ f32 _4;
    /* 0x8 */ f32 _8;
    /* 0xC */ f32 _C;
} UnkAC8Data4884; // size: 0x10

extern UnkAC8Data4884 lbl_3_data_4884[2];
extern u8 lbl_3_data_470C[2];
extern s16 lbl_3_data_484C[10];
extern f32 lbl_3_data_4930[43];
extern f32 lbl_3_data_18984[6];
extern s16 lbl_3_data_1C3C[2];
extern u8 lbl_3_data_48F8[8];
extern s16 lbl_3_data_49DC[44];

// Per-action fielder handlers, indexed by the fielder's action (_1D3)
typedef struct {
    /* 0x0 */ s32 _0;
    /* 0x4 */ void (*_4)(s32 fielder);
} UnkAC8Action;

UnkAC8Action lbl_3_data_3C40[29] = {
    { 0, fn_3_3C220 },   { 2, fn_3_4D20C },   { -1, fn_3_45394 },  { 1, fn_3_45860 },  { 1, fn_3_455B4 },
    { -1, fn_3_48480 },  { -1, fn_3_4B128 },  { 6, fn_3_4B514 },   { 5, fn_3_4B514 },  { 0, fn_3_3CCB0 },
    { 7, fn_3_A9D20 },   { 3, fn_3_48A54 },   { 8, fn_3_3D6AC },   { 4, fn_3_4A9AC },  { 9, fn_3_3DB78 },
    { 10, fn_3_3B370 },  { 11, fn_3_35D28 },  { 12, fn_3_3D304 },  { 1, fn_3_45394 },  { 13, fn_3_3C1A8 },
    { 14, fn_3_3E34C },  { 10, fn_3_3AE34 },  { 10, fn_3_3AE34 },  { 10, fn_3_3AE34 }, { 4, fn_3_49C18 },
    { 15, fn_3_45B88 },  { 1, fn_3_2DCF4 },   { -1, fn_3_2DAC4 },  { -1, fn_3_2D92C },
};

// .bss statics, in reverse address order: MWCC lays them out last declared first
static s16 lbl_3_bss_170[0x48];
static s16 lbl_3_bss_16C;
static s16 lbl_3_bss_C8[0x52];

// .text:0x000598D0 size:0x48 mapped:0x80698964
void fn_3_598D0(void) {
    return;
}

// .text:0x0005985C size:0x74 mapped:0x806988F0
void fn_3_5985C(s32 fielder, s32 action) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (fielder == -1) {
        return;
    }
    f->_1D3 = action;
    if (lbl_3_data_3C40[action]._0 >= 0) {
        g_FieldingLogic._0F8[fielder] = lbl_3_data_3C40[action]._0;
    }
    f->_1D5 = 0;
    f->_1D6 = 0;
    f->_1A4 = 0;
    f->_1AC = 0;
    f->_1FF = 0;
    if (action == 0x18) {
        g_FieldingLogic._0BC = fielder;
    }
}

// .text:0x000596F8 size:0x164 mapped:0x8069878C
// 94.21%: the second loop's setup is scheduled differently and the bonus product lands
// in f0 instead of f1.
void fn_3_596F8(void) {
    s32 i;
    s32 team;

    g_GameLogic.rosterLoc_skippingCap = 0;
    team = g_GameLogic.awayTeamBattingInd_battingTeam;
    for (i = 0; i < 10; i++) {
        if (g_GameLogic.battingOrderAndPositionMapping[team][i][1] <= 8) {
            fn_3_6E24C(g_GameLogic.battingOrderAndPositionMapping[team][i][0],
                       g_GameLogic.battingOrderAndPositionMapping[team][i][1]);
        }
    }
    for (i = 0; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];
        u8 ai = g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam];

        f->_1D2 = lbl_3_data_46F8[ai][i];
        if (ai != 0) {
            s32 bonus = lbl_3_data_470C[0] + (s32)((lbl_3_data_470C[1] - lbl_3_data_470C[0]) *
                                                   g_AiLogic.aIDifficultyMultiplierArray[g_GameLogic.homeTeamBattingInd_fieldingTeam]);

            if (i <= 1) {
                f->_1D2 += bonus / 2;
            } else {
                f->_1D2 += bonus;
            }
        }
    }
}

// .text:0x000595C4 size:0x134 mapped:0x80698658
void fn_3_595C4(void) {
    return;
}

// .text:0x00059338 size:0x28C mapped:0x806983CC
// 94.05%: the first loop walks the mapping with lwzu in the target; the inlined
// fn_3_596F8 carries that function's own differences.
void fn_3_59338(void) {
    s32 i;

    for (i = 1; i < 10; i++) {
        if (g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][1] >= 20) {
            g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][1] -= 20;
        } else if (g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][1] >= 10) {
            g_GameLogic.battingOrderAndPositionMapping[g_GameLogic.awayTeamBattingInd_battingTeam][i][1] -= 10;
        }
    }
    fn_3_596F8();
    for (i = 0; i < 9; i++) {
        g_Fielders[i]._1F1 = 0;
        g_Fielders[i]._1E3 = 0;
        g_Fielders[i]._1FA = 0;
        g_Fielders[i]._217 = 0;
    }
}

// .text:0x000591AC size:0x18C mapped:0x80698240
void fn_3_591AC(void) {
    f32 x;
    f32 z;
    s32 i;

    for (i = 0; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];
        if (g_GameLogic.pre_PostMiniGameInd != 0) {
            fn_3_58F58(i, &x, &z);
            f->_000 = x;
            f->_008 = z;
        }
        f->_014 = 0.0f;
        f->_018 = 0.0f;
        f->_01C = 0.0f;
        f->_030 = 0.0f;
        f->_034 = 0.0f;
        f->_0D4 = f->_000;
        f->_0D8 = f->_008;
        f->_050 = 0.0f;
        f->_1D9 = 0;
        f->_1F5 = -1;
        f->_20F = 0;
        x = -f->_000;
        z = -f->_008;
        f->_048 = atan2(z, x);
    }
    if (g_GameLogic.pre_PostMiniGameInd != 0) {
        for (i = 0; i < 9; i++) {
            UnkAC8Fielder* f = &g_Fielders[i];
            fn_3_58F58(i, &f->_000, &f->_008);
            f->_004 = 0.0f;
        }
    }
    if (g_Runners[1].runnerOnFieldOrOutOrScored == 1) {
        g_Fielders[2]._18C = 1;
        g_Fielders[2]._1D7 = 1;
        g_Fielders[2]._1F5 = 1;
        g_FieldingLogic._0D0[1] = 2;
        g_FieldingLogic._101[1] = 1;
    }
}

// .text:0x00058F58 size:0x254 mapped:0x80697FEC
// 99.87%: the lbl_3_data_4554 element address takes pos * 0x18 and row * 8 in swapped registers.
void fn_3_58F58(s32 pos, f32* x, f32* z) {
    BOOL bunt = FALSE;
    s32 depth = g_Pitcher.pitchTotalTimeCounter <= 0 ? 1 : 2;
    s32 row;

    if (pos <= 1) {
        *x = lbl_3_data_450C[pos].x;
        *z = lbl_3_data_450C[pos].z;
        return;
    }
    if (pos <= 5) {
        if (g_Runners[1].runnerOnFieldOrOutOrScored != 0 && g_Runners[1].furthestBaseForcedToGoToOnWalk != 0 &&
            g_Ball.pitchHangtimeCounter > 0 && g_Pitcher.framesUntilUnhittable < 15) {
            if (g_Batter.batterHand == 0 && pos == 3) {
                *x = lbl_3_data_4444[2].x;
                *z = lbl_3_data_4444[2].z;
                return;
            }
            if (g_Batter.batterHand != 0 && pos == 5) {
                *x = lbl_3_data_4444[2].x;
                *z = lbl_3_data_4444[2].z;
                return;
            }
        }
        row = 0;
        if (g_Pitcher.pitchTotalTimeCounter > 30 && (pos == 2 || pos == 4) && g_Batter.buntStatus >= 1 && g_Batter.buntStatus <= 3) {
            bunt = TRUE;
        }
        if ((pos == 2 && g_Runners[1].runnerOnFieldOrOutOrScored == 1) || (pos == 4 && g_Runners[3].runnerOnFieldOrOutOrScored == 1)) {
            row = depth;
        }
        if (g_Runners[2].runnerOnFieldOrOutOrScored == 1) {
            if (pos == 3 && g_Batter.batterHand == 0) {
                row = depth;
                g_FieldingLogic._11E = 0;
            }
            if (pos == 5 && g_Batter.batterHand == 1) {
                row = depth;
                g_FieldingLogic._11E = 1;
            }
        }
        if (bunt) {
            *x = lbl_3_data_45B4[pos - 2].x;
            *z = lbl_3_data_45B4[pos - 2].z;
            return;
        }
        *x = lbl_3_data_4554[pos - 2][row].x;
        *z = lbl_3_data_4554[pos - 2][row].z;
        return;
    }
    *x = lbl_3_data_45D4[pos - 6].x;
    *z = lbl_3_data_45D4[pos - 6].z;
}

// .text:0x00058E50 size:0x108 mapped:0x80697EE4
void fn_3_58E50(void) {
    s32 i;

    g_GameLogic.rosterLoc_skippingCap = 0;
    if (g_d_GameSettings.minigamesEnabled) {
        for (i = 0; i < 4; i++) {
            s8 roster = g_Minigame.minigameControlStruct._28[i];

            if (roster >= 0) {
                s32 idx = roster == g_Minigame.minigamePlayerSelectedOrder ? 0 : i + 2;
                UnkAC8Fielder* f;

                fn_3_6E24C(roster, idx);
                f = &g_Fielders[idx];
                if (idx == 0) {
                    f->_1D2 = lbl_3_data_46F8[g_Minigame.minigameControlStruct.battingHandedness[i]][0];
                } else {
                    f->_1D2 = lbl_3_data_46F8[g_Minigame.minigameControlStruct.battingHandedness[i]][7];
                }
            }
        }
    }
}

// .text:0x00058870 size:0x5E0 mapped:0x80697904
void fn_3_58870(void) {
    return;
}

// .text:0x00058688 size:0x1E8 mapped:0x8069771C
void fn_3_58688(void) {
    s32 i;

    g_FieldingLogic._0CE = g_FieldingLogic._0CC;
    g_FieldingLogic._0E0 = g_FieldingLogic._0DE;
    if (g_Ball.looseBall_5FrameCountdown != 0) {
        g_Ball.looseBall_5FrameCountdown--;
    }
    for (i = 0; i < 9; i++) {
        g_Fielders[i]._1FC = 0;
        g_Fielders[i]._257 = g_Fielders[i]._256;
        g_Fielders[i]._256 = 0;
        g_Fielders[i]._20C = g_Fielders[i]._20B;
        g_Fielders[i]._20B = 0;
        g_Fielders[i]._216 = 0;
        g_Fielders[i]._263 = 0;
    }
    if (g_Ball.framesSinceHit == 1 || (g_Ball.framesSinceHit == 0x65 && g_FieldingLogic._107 != 0)) {
        for (i = 0; i < 9; i++) {
            g_Fielders[i]._118 = g_Fielders[i]._000;
            g_Fielders[i]._11C = g_Fielders[i]._008;
        }
    }
    for (i = 0; i < 4; i++) {
        g_FieldingLogic._074[i]._0[2] = 0;
    }
    g_FieldingLogic._144 = 0;
    g_Ball.fielderActionOccuring = 0;
    g_Pitcher.unused_pitcherIsFielder = 0;
    if (g_FieldingLogic._146 != 0) {
        g_FieldingLogic._146--;
    }
}

// .text:0x000583B8 size:0x2D0 mapped:0x8069744C
void fn_3_583B8(void) {
    return;
}

// .text:0x00057BB4 size:0x804 mapped:0x80696C48
void fn_3_57BB4(void) {
    return;
}

// .text:0x00057A14 size:0x1A0 mapped:0x80696AA8
void fn_3_57A14(void) {
    return;
}

// .text:0x000576B4 size:0x360 mapped:0x80696748
void fn_3_576B4(void) {
    return;
}

// .text:0x00057488 size:0x22C mapped:0x8069651C
void fn_3_57488(void) {
    return;
}

// .text:0x00057144 size:0x344 mapped:0x806961D8
void fn_3_57144(void) {
    return;
}

// .text:0x00055EEC size:0x1258 mapped:0x80694F80
void fn_3_55EEC(void) {
    return;
}

// .text:0x00055CC4 size:0x228 mapped:0x80694D58
void fn_3_55CC4(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_1E8 == 2 && g_Ball.fielderWBallIndex != fielder) {
        f->_1E8 = 0;
    }
    if (f->_050 <= 0.0f) {
        f->_19A = -1;
        f->_1A0 = 0;
    } else {
        f->_19A = radToShortAngle(f->_064);
        if (f->_1A0 < 0x7FFE) {
            f->_1A0++;
        } else {
            f->_1A0 = 0x7FFF;
        }
    }
    if (g_FieldingLogic._0DE >= 0 && f->_1C6 == 0 && g_Runners[g_FieldingLogic._0DE].runnerOnFieldOrOutOrScored != 1) {
        g_FieldingLogic._0DE = -1;
    }
    if (g_Ball.ballState == 1 || g_Ball.ballState == 2) {
        if (g_FieldingLogic._0DC >= 0 && g_FieldingLogic._0CC == 9 && g_FieldingLogic._0DE >= 0) {
            f32 progress = g_Runners[g_FieldingLogic._0DE].percentTowardsNextBase;

            if (progress >= 0.3f && progress <= 0.65f) {
                g_FieldingLogic._0F4 = g_FieldingLogic._0DE;
            }
        }
        if (g_FieldingLogic._0F4 >= 0) {
            u8 from;
            u8 to;

            if (g_Runners[g_FieldingLogic._0F4].runnerOnFieldOrOutOrScored != 1 || g_Runners[g_FieldingLogic._0F4].baseStandingOn >= 0) {
                g_FieldingLogic._0F4 = -1;
                return;
            }
            from = g_Runners[g_FieldingLogic._0F4].currentBase;
            to = g_Runners[g_FieldingLogic._0F4].nextBase;
            if (g_FieldingLogic._0C4 != -1 && g_FieldingLogic._0C4 != from && g_FieldingLogic._0C4 != to) {
                g_FieldingLogic._0F4 = -1;
            }
            if (g_FieldingLogic._0CC != -1 && g_FieldingLogic._0CC != 9 && g_FieldingLogic._0CC != from && g_FieldingLogic._0CC != to) {
                g_FieldingLogic._0F4 = -1;
            }
        }
    }
}

// .text:0x00055918 size:0x3AC mapped:0x806949AC
void fn_3_55918(void) {
    return;
}

// .text:0x00055710 size:0x208 mapped:0x806947A4
void fn_3_55710(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 base = f->_1F5;
    s32 i;

    if (g_FieldingLogic._116 != 0) {
        if (g_Runners[g_FieldingLogic._11B].baseStandingOn >= 0 || g_Runners[g_FieldingLogic._11B].runnerOnFieldOrOutOrScored == 2) {
            g_FieldingLogic._116 = 0;
            g_FieldingLogic._0EC = 0;
        }
        return;
    }
    if (g_FieldingLogic._125 >= 0) {
        base = g_FieldingLogic._125;
    }
    if (base < 0) {
        return;
    }
    for (i = 3; i >= 0; i--) {
        InMemRunnerType* r = &g_Runners[i];

        if (r->runnerOnFieldOrOutOrScored == 1 && r->forceOutCd <= 0 && r->baseRunningTowards == base &&
            r->tagUpInd == 0 && r->baseStandingOn < 0 && r->actionCode != 0) {
            if (r->actionCode == 2) {
                f->_211 = 2;
                f->_212 = 0;
                g_FieldingLogic._116 = 2;
                g_FieldingLogic._0EC = 6;
                g_FieldingLogic._111 = 7;
                g_FieldingLogic._13F = 2;
                f->_213 = i;
                if (g_GameLogic._13E[g_GameLogic.teamFielding] == 0) {
                    fn_3_6C854(g_GameLogic.teamFielding, 2);
                }
            } else if (r->actionCode == 3) {
                f->_211 = 1;
                f->_212 = 0;
                g_FieldingLogic._116 = 1;
                g_FieldingLogic._0EC = r->actionFrames_countDown;
                g_FieldingLogic._111 = 6;
                g_FieldingLogic._13F = 1;
                f->_213 = i;
            } else if (r->actionFrames_countDown < 6) {
                g_FieldingLogic._116 = 2;
                g_FieldingLogic._0EC = 6;
            } else {
                g_FieldingLogic._116 = 1;
                g_FieldingLogic._0EC = r->actionFrames_countDown;
            }
            g_FieldingLogic._11B = i;
            return;
        }
    }
}

// .text:0x000555AC size:0x164 mapped:0x80694640
void fn_3_555AC(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 lo;
    f32 hi;

    f->_1DE = 0;
    if (f->_008 > 45.0f) {
        return;
    }
    if (f->_008 < -5.0f) {
        return;
    }
    if (f->_000 > 25.0f) {
        return;
    }
    if (f->_000 < -25.0f) {
        return;
    }
    if (f->_008 > lbl_3_data_4444[1].z) {
        lo = lbl_3_data_4444[2].z - 2.0f;
        hi = 4.0f + lbl_3_data_4444[2].z;
        if (f->_000 > 0.0f) {
            if (f->_008 > -f->_000 + lo && f->_008 < -f->_000 + hi) {
                f->_1DE = 2;
            }
        } else if (f->_008 > f->_000 + lo && f->_008 < f->_000 + hi) {
            f->_1DE = 3;
        }
    } else {
        lo = lbl_3_data_4444[0].z - 4.0f;
        hi = 2.0f + lbl_3_data_4444[0].z;
        if (f->_000 > 0.0f) {
            if (f->_008 > f->_000 + lo && f->_008 < f->_000 + hi) {
                f->_1DE = 1;
            }
        } else if (f->_008 > -f->_000 + lo && f->_008 < -f->_000 + hi) {
            f->_1DE = 4;
        }
    }
}

// .text:0x00055370 size:0x23C mapped:0x80694404
void fn_3_55370(void) {
    return;
}

// .text:0x00054B58 size:0x818 mapped:0x80693BEC
void fn_3_54B58(void) {
    return;
}

// .text:0x00054900 size:0x258 mapped:0x80693994
void fn_3_54900(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 runners = g_RunningLogic._04;
    f32 x;
    f32 z;

    if (f->_1F5 >= 0) {
        x = lbl_3_data_4444[4].x;
        z = lbl_3_data_4444[4].z;
    } else {
        if (g_RunningLogic._10 == 0) {
            f->_04C = f->_048;
            f->_1F2 = 1;
            return;
        }
        if (g_Ball.AtBat_ContactResult == 3) {
            runners &= 0xFFF0;
        }
        switch (runners) {
        case 0x1:
            x = lbl_3_data_4444[1].x;
            z = lbl_3_data_4444[1].z;
            break;
        case 0x10:
            x = 0.7f * lbl_3_data_4444[2].x + 0.3f * lbl_3_data_4444[1].x;
            z = 0.7f * lbl_3_data_4444[2].z + 0.3f * lbl_3_data_4444[1].z;
            break;
        case 0x100:
            x = 0.7f * lbl_3_data_4444[3].x + 0.3f * lbl_3_data_4444[2].x;
            z = 0.7f * lbl_3_data_4444[3].z + 0.3f * lbl_3_data_4444[2].z;
            break;
        case 0x11:
            x = 0.5f * (lbl_3_data_4444[1].x + lbl_3_data_4444[2].x);
            z = 0.5f * (lbl_3_data_4444[1].z + lbl_3_data_4444[2].z);
            break;
        case 0x110:
            x = 0.5f * (lbl_3_data_4444[2].x + lbl_3_data_4444[3].x);
            z = 0.5f * (lbl_3_data_4444[2].z + lbl_3_data_4444[3].z);
            break;
        case 0x111:
            x = 0.3f * lbl_3_data_4444[3].x + 0.7f * lbl_3_data_4444[2].x;
            z = 0.3f * lbl_3_data_4444[3].z + 0.7f * lbl_3_data_4444[2].z;
            break;
        case 0x101:
            x = lbl_3_data_4444[4].x;
            z = lbl_3_data_4444[4].z;
            break;
        default:
            x = lbl_3_data_4444[0].x;
            z = lbl_3_data_4444[0].z;
            break;
        }
    }
    f->_048 = atan2(z - f->_008, x - f->_000);
}

// .text:0x000544B8 size:0x448 mapped:0x8069354C
void fn_3_544B8(void) {
    return;
}

// .text:0x00053F48 size:0x570 mapped:0x80692FDC
void fn_3_53F48(void) {
    return;
}

// .text:0x00053EE8 size:0x60 mapped:0x80692F7C
void fn_3_53EE8(s32 fielder) {
    fn_3_5985C(fielder, 0x13);
}

// .text:0x0005372C size:0x7BC mapped:0x806927C0
void fn_3_5372C(s32 fielder) {
    return;
}

// .text:0x00053130 size:0x5FC mapped:0x806921C4
void fn_3_53130(void) {
    return;
}

// .text:0x000530EC size:0x44 mapped:0x80692180
void fn_3_530EC(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    g_Fielders[fielder]._014 = f->_000;
    g_Fielders[fielder]._018 = f->_004;
    g_Fielders[fielder]._01C = f->_008;
    g_Fielders[fielder]._030 = 0.0f;
    g_Fielders[fielder]._034 = 0.0f;
    g_Fielders[fielder]._050 = 0.0f;
    g_Fielders[fielder]._068 = 0.0f;
}

// .text:0x00052F4C size:0x1A0 mapped:0x80691FE0
void fn_3_52F4C(s32 fielder, f32 x, f32 z) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dx;
    f32 dz;

    f->_014 = x;
    f->_01C = z;
    dx = x - f->_000;
    dz = z - f->_008;
    if (dx == 0.0f && dz == 0.0f) {
        f->_050 = 0.0f;
        f->_068 = 0.0f;
    } else {
        f->_064 = atan2(dz, dx);
        f->_068 = dolsqrtf2(dx * dx + dz * dz);
    }
    f->_1D9 = 1;
}

// .text:0x000526DC size:0x870 mapped:0x80691770
void fn_3_526DC(s32 fielder) {
    return;
}

// .text:0x00052560 size:0x17C mapped:0x806915F4
int fn_3_52560(int fielder, f32 x, f32 z) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dz;
    f32 dx;
    f32 dx2;
    f32 dz2;
    f32 dist;
    f32 speed;
    s32 extra;

    if (x == f->_000 && z == f->_008) {
        return 1;
    }
    dx = x - f->_000;
    dz = z - f->_008;
    dx2 = dx * dx;
    dz2 = dz * dz;
    dist = dolsqrtf2(dx2 + dz2);
    extra = f->_1D1 / 2;
    if (f->_058 == 0.0f) {
        speed = 1.0f;
    } else {
        speed = f->_058;
    }
    return extra + (s32)(dist / speed);
}

// .text:0x000522E0 size:0x280 mapped:0x80691374
void fn_3_522E0(s32 fielder, s32 frames, f32 dx, f32 dz, f32* x, f32* z, f32* dist) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 total = 0.0f;
    f32 speed = f->_050;
    f32 len;
    f32 nx;
    f32 nz;
    s32 angle;
    s32 i;

    if (dx == 0.0f && dz == 0.0f) {
        *x = f->_000;
        *z = f->_008;
        *dist = 0.0f;
        return;
    }
    len = dolsqrtf2(dx * dx + dz * dz);
    nx = dx / len;
    nz = dz / len;
    angle = fn_3_9FB8C(nx, nz);
    if (!(f->_050 < 0.05f) && f->_19A >= 0 && fn_3_9FCF8(angle, f->_19A) > 0x2A8) {
        speed = 0.0f;
    }
    for (i = 0; i <= f->_1D1; i++) {
        speed += f->_05C;
        if (speed > f->_058) {
            total += f->_058;
            break;
        }
        total += speed;
    }
    frames -= i + 1;
    total = f->_058 * frames + total;
    *dist = total;
    *x = nx * total + f->_000;
    *z = nz * total + f->_008;
}

// .text:0x00052084 size:0x25C mapped:0x80691118
f32 fn_3_52084(s32 fielder, f32 x, f32 z) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dx;
    f32 dz;
    f32 proj;
    f32 d2;

    if (f->_050 < 0.01f) {
        f32 az;
        f32 ax;
        f32 ax2;
        f32 az2;
        ax = f->_000 - x;
        az = f->_008 - z;
        ax2 = ax * ax;
        az2 = az * az;
        return dolsqrtf2(ax2 + az2);
    }
    dz = z - f->_008;
    dx = x - f->_000;
    proj = f->_038 * dx + f->_03C * dz;
    d2 = dx * dx + dz * dz - proj * proj;
    if (d2 < 0.0f) {
        return 0.0f;
    }
    return dolsqrtf2(d2);
}

// .text:0x00051DF0 size:0x294 mapped:0x80690E84
u8 fn_3_51DF0(f32 x, f32 z) {
    f32 xx;
    f32 dz;
    f32 dist;

    if (x - z + 40.0f > 0.0f && -x - z + 40.0f > 0.0f) {
        return 0;
    }
    xx = x * x;
    if (dolsqrtf2(z * z + xx) < 38.8f) {
        return 1;
    }
    dz = z - 18.4f;
    dist = dolsqrtf2(dz * dz + xx);
    if (dist < 28.0f) {
        return 1;
    }
    if (dist < 37.0f) {
        return 2;
    }
    if (dist < 43.0f) {
        return 3;
    }
    return 4;
}

// .text:0x00051798 size:0x658 mapped:0x8069082C
BOOL fn_3_51798(s32 fielder, struct _VecXYZ* delta) {
    return 0;
}

// .text:0x0005164C size:0x14C mapped:0x806906E0
s32 fn_3_5164C(s32 fielder, struct _VecXYZ* out) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 ret = 0;
    f32 x = f->_000 + f->_030;
    f32 z = f->_008 + f->_034;
    f32 h;
    f32 t;
    f32 c;
    f32 d;
    f32 nx;

    if (x > 0.0f) {
        if (x > z) {
            ret = 2;
            h = 0.5f * (x - z);
            x = z + h;
            z = x;
        }
    } else if (-x > z) {
        ret = 2;
        h = 0.5f * (-x - z);
        z = z + h;
        x = -z;
    }
    c = lbl_3_data_4444[2].z;
    d = z - c;
    if (!(d > x) && !(d > (nx = -x))) {
        if (x > 0.0f) {
            t = c - z;
            ret = 2;
            h = 0.5f * (x - t);
            x = t + h;
            z = -x + c;
        } else {
            t = c - z;
            ret = 2;
            h = 0.5f * (nx - t);
            x = -t - h;
            z = x + c;
        }
    }
    if (z <= lbl_3_data_4444[2].x) {
        return 1;
    }
    out->x = x;
    out->z = z;
    return ret;
}

// .text:0x00051220 size:0x42C mapped:0x806902B4
void fn_3_51220(void) {
    return;
}

// .text:0x00050DD8 size:0x448 mapped:0x8068FE6C
void fn_3_50DD8(void) {
    return;
}

// .text:0x00050C20 size:0x1B8 mapped:0x8068FCB4
void fn_3_50C20(s32 fielder, f32* outX, f32* outZ) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s16 angle = fn_3_9FB8C(f->_028 - f->_000, f->_02C - f->_008);
    f32 x;
    f32 z;

    if (fielder == 7) {
        if (angle > 0x200 && angle < 0x600) {
            *outX = f->_000;
            *outZ = f->_02C;
        } else {
            *outX = f->_028;
            *outZ = f->_008;
        }
        f->_18A = lbl_3_data_48F8[f->_1C4];
    } else if (fielder == 8) {
        if (angle > 0x100 && angle < 0x600) {
            x = f->_000 / f->_070;
            z = f->_008 / f->_070;
            *outX = x * (10.0f + f->_070);
            *outZ = z * (10.0f + f->_070);
        } else {
            *outX = f->_028;
            *outZ = f->_008;
        }
        f->_18A = lbl_3_data_48F8[f->_1C4];
    } else {
        if (angle > 0x200 && angle < 0x700) {
            x = f->_000 / f->_070;
            z = f->_008 / f->_070;
            *outX = x * (10.0f + f->_070);
            *outZ = z * (10.0f + f->_070);
        } else {
            *outX = f->_028;
            *outZ = f->_008;
        }
        f->_18A = lbl_3_data_48F8[f->_1C4];
    }
}

// .text:0x00050898 size:0x388 mapped:0x8068F92C
void fn_3_50898(void) {
    return;
}

// .text:0x0004FB34 size:0xD64 mapped:0x8068EBC8
void fn_3_4FB34(void) {
    return;
}

// .text:0x0004F504 size:0x630 mapped:0x8068E598
void fn_3_4F504(void) {
    return;
}

// .text:0x0004EFC8 size:0x53C mapped:0x8068E05C
void fn_3_4EFC8(void) {
    return;
}

// .text:0x0004EBC4 size:0x404 mapped:0x8068DC58
void fn_3_4EBC4(void) {
    return;
}

// .text:0x0004E638 size:0x58C mapped:0x8068D6CC
void fn_3_4E638(void) {
    return;
}

// .text:0x0004E1BC size:0x47C mapped:0x8068D250
void fn_3_4E1BC(void) {
    return;
}

// .text:0x0004DC14 size:0x5A8 mapped:0x8068CCA8
void fn_3_4DC14(void) {
    return;
}

// .text:0x0004DB84 size:0x90 mapped:0x8068CC18
BOOL fn_3_4DB84(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (g_Ball.ballVelocityPercent.x == 0.0f && g_Ball.ballVelocityPercent.z == 0.0f) {
        return FALSE;
    }
    if (-(g_Ball.ballVelocityPercent.x * g_Ball.AtBat_Contact_BallPos.x) - g_Ball.ballVelocityPercent.z * g_Ball.AtBat_Contact_BallPos.z +
            (g_Ball.ballVelocityPercent.x * f->_000 + g_Ball.ballVelocityPercent.z * f->_008) > 0.0f) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x0004D20C size:0x978 mapped:0x8068C2A0
void fn_3_4D20C(s32 fielder) {
    return;
}

// .text:0x0004CFB0 size:0x25C mapped:0x8068C044
void fn_3_4CFB0(void) {
    f32 x;
    f32 z;
    f32 d;

    if (g_Fielders[0]._18C == 1) {
        d = lbl_3_data_4444[1].x - g_Fielders[0]._000;
        if (d > 15.0f) {
            d = 15.0f;
        }
        d /= 3.0f;
        x = lbl_3_data_4444[1].x;
        z = lbl_3_data_4444[1].z - d;
    } else if (g_Fielders[0]._18C == 3) {
        d = g_Fielders[0]._000 - lbl_3_data_4444[3].x;
        if (d > 15.0f) {
            d = 15.0f;
        }
        d /= 3.0f;
        x = lbl_3_data_4444[3].x;
        z = lbl_3_data_4444[3].z - d;
    } else {
        x = lbl_3_data_4444[g_Fielders[0]._18C].x;
        z = lbl_3_data_4444[g_Fielders[0]._18C].z;
    }
    fn_3_52F4C(0, x, z);
}

// .text:0x0004C9C8 size:0x5E8 mapped:0x8068BA5C
void fn_3_4C9C8(void) {
    return;
}

// .text:0x0004BA0C size:0xFBC mapped:0x8068AAA0
void fn_3_4BA0C(void) {
    return;
}

// .text:0x0004B8D0 size:0x13C mapped:0x8068A964
void fn_3_4B8D0(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s16 base = f->_18C;

    if (base < 0) {
        return;
    }
    if (base <= 3) {
        if (g_FieldingLogic._0D0[f->_18C] == fielder) {
            g_FieldingLogic._0D0[f->_18C] = -1;
            g_FieldingLogic._101[f->_18C] = 0;
        }
        f->_18C = -1;
        f->_1D7 = 0;
        if (f->_1D3 == 1) {
            fn_3_5985C(fielder, 0xC);
        }
    } else if (base == 5) {
        f->_18C = -1;
        g_FieldingLogic._0D8 = -1;
        f->_1D7 = 0;
        g_FieldingLogic.playerAtMoundCutoffLocation = 0;
        if (f->_1D3 == 0xE) {
            fn_3_5985C(fielder, 0xC);
        }
    }
}

// .text:0x0004B514 size:0x3BC mapped:0x8068A5A8
void fn_3_4B514(s32 fielder) {
    return;
}

// .text:0x0004B128 size:0x3EC mapped:0x8068A1BC
void fn_3_4B128(s32 fielder) {
    return;
}

// .text:0x0004A9AC size:0x77C mapped:0x80689A40
void fn_3_4A9AC(s32 fielder) {
    return;
}

// .text:0x0004A408 size:0x5A4 mapped:0x8068949C
void fn_3_4A408(void) {
    return;
}

// .text:0x0004A124 size:0x2E4 mapped:0x806891B8
void fn_3_4A124(void) {
    s32 i;

    if (g_Ball.hitClassification3 == 5) {
        if (g_FieldingLogic._0F8[2] == 1 || g_FieldingLogic._0F8[2] == 10 || g_FieldingLogic._0F8[2] == 11) {
            fn_3_49F40(8, 0);
            fn_3_49F40(6, 7);
            fn_3_49F40(7, 1);
        } else if (g_FieldingLogic._0F8[4] == 1 || g_FieldingLogic._0F8[4] == 10 || g_FieldingLogic._0F8[4] == 11) {
            fn_3_49F40(6, 0);
            fn_3_49F40(7, 1);
            fn_3_49F40(8, 4);
        } else {
            fn_3_49F40(7, 0);
            if (g_Ball.Hit_HorizontalAngle < 0x400) {
                fn_3_49F40(8, 0);
                fn_3_49F40(6, 7);
            } else {
                fn_3_49F40(6, 0);
                fn_3_49F40(8, 4);
            }
        }
    } else if (g_Ball.hitClassification3 == 6) {
        fn_3_49F40(7, 0);
        if (g_Ball.Hit_HorizontalAngle >= 0x3E0 && g_Ball.Hit_HorizontalAngle < 0x420) {
            fn_3_49F40(8, 0);
            fn_3_49F40(6, 0);
        } else if (g_Ball.Hit_HorizontalAngle < 0x400) {
            fn_3_49F40(8, 0);
            fn_3_49F40(6, 7);
        } else {
            fn_3_49F40(6, 0);
            fn_3_49F40(8, 6);
        }
    } else if (g_Ball.hitClassification3 == 7) {
        if (g_FieldingLogic._0F8[1] != 1 && g_FieldingLogic._0F8[1] != 10 && g_FieldingLogic._0F8[1] != 11) {
            fn_3_49F40(8, 0);
            fn_3_49F40(6, 1);
            fn_3_49F40(7, 1);
        } else {
            fn_3_49F40(6, 1);
            fn_3_49F40(7, 1);
            fn_3_49F40(8, 1);
        }
    } else if (g_Ball.hitClassification3 == 8) {
        if (g_FieldingLogic._0F8[1] != 1 && g_FieldingLogic._0F8[1] != 10 && g_FieldingLogic._0F8[1] != 11) {
            fn_3_49F40(6, 0);
            fn_3_49F40(7, 1);
            fn_3_49F40(8, 1);
        } else {
            fn_3_49F40(6, 1);
            fn_3_49F40(7, 1);
            fn_3_49F40(8, 1);
        }
    } else {
        fn_3_49F40(6, 1);
        fn_3_49F40(7, 1);
        fn_3_49F40(8, 4);
        for (i = 2; i < 6; i++) {
            fn_3_49F40(i, 0);
        }
    }
}

// .text:0x00049F40 size:0x1E4 mapped:0x80688FD4
void fn_3_49F40(s32 fielder, s32 kind) {
    if (g_FieldingLogic._0F8[fielder] != 0) {
        return;
    }
    g_Fielders[fielder]._1D4 = kind;
    if (kind == 0) {
        if (g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam] != 0) {
            fn_3_5985C(fielder, 3);
        } else {
            fn_3_5985C(fielder, 0x18);
        }
    } else if (kind == 1) {
        fn_3_5985C(fielder, 8);
    } else {
        fn_3_5985C(fielder, 7);
        if (kind == 2 || kind == 4) {
            g_Fielders[fielder]._190 = 1;
        }
        if (kind == 3 || kind == 5) {
            g_Fielders[fielder]._190 = 3;
        }
        if (kind == 6 || kind == 7) {
            g_Fielders[fielder]._190 = 2;
        }
    }
}

// .text:0x00049F3C size:0x4 mapped:0x80688FD0
void fn_3_49F3C(void) {
    return;
}

// .text:0x00049EA8 size:0x94 mapped:0x80688F3C
void fn_3_49EA8(s32 fielder) {
    if (g_FieldingLogic._0F8[fielder] == 9) {
        return;
    }
    g_Fielders[fielder]._18C = 7;
    fn_3_5985C(fielder, 0xE);
    g_Fielders[fielder]._1D6 = 0;
    g_Fielders[fielder]._190 = -1;
}

// .text:0x00049C18 size:0x290 mapped:0x80688CAC
void fn_3_49C18(s32 fielder) {
    return;
}

// .text:0x000499C4 size:0x254 mapped:0x80688A58
void fn_3_499C4(s32 fielder, struct _VecXYZ* out) {
    UnkAC8Fielder* holder;
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 idx = g_FieldingLogic._0B0;
    s32 found;
    s32 frame;
    s32 i;
    f32 len;
    f32 nx;
    f32 nz;

    out->y = 0.0f;
    if (g_FieldingLogic._0B2 >= 0) {
        idx = g_FieldingLogic._0B2;
    }
    found = 0;
    holder = &g_Fielders[idx];
    frame = holder->_186 - g_Ball.framesSinceHit;
    if (frame > 0) {
        f32 limit = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist + lbl_3_data_4930[0];
        for (i = frame + 1; i < 360; i += 3) {
            if (limit < g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist) {
                break;
            }
        }
        if (i < 360) {
            found = i;
        }
    }
    if (found == 0) {
        frame = f->_186 - g_Ball.framesSinceHit;
        if (frame <= 0) {
            frame = 90;
        } else if (frame >= 360) {
            frame = 359;
        }
        len = dolsqrtf2(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x *
                            g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x +
                        g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z *
                            g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z);
        nx = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x / len;
        nz = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z / len;
        len += lbl_3_data_4930[0];
        out->x = nx * len;
        out->z = nz * len;
    } else {
        out->x = g_Ball.physicsSubstruct.futureCoordsAndDist[found].pos.x;
        out->z = g_Ball.physicsSubstruct.futureCoordsAndDist[found].pos.z;
    }
}

// .text:0x000494F4 size:0x4D0 mapped:0x80688588
void fn_3_494F4(void) {
    return;
}

// .text:0x00048A54 size:0xAA0 mapped:0x80687AE8
void fn_3_48A54(s32 fielder) {
    return;
}

// .text:0x00048480 size:0x5D4 mapped:0x80687514
void fn_3_48480(s32 fielder) {
    return;
}

// .text:0x000483CC size:0xB4 mapped:0x80687460
void fn_3_483CC(void) {
    return;
}

// .text:0x000480B8 size:0x314 mapped:0x8068714C
void fn_3_480B8(void) {
    return;
}

// .text:0x00047778 size:0x940 mapped:0x8068680C
void fn_3_47778(void) {
    return;
}

// .text:0x00047628 size:0x150 mapped:0x806866BC
s32 fn_3_47628(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (g_Runners[i].runnerOnFieldOrOutOrScored == 1) {
            InMemRunnerType* r;
            f32 bases;

            if (g_Runners[i].fractionalBasesRan >= 3.7f && g_Runners[i].runningDirectionCode == 1 && g_Runners[i].tagUpInd != 2) {
                continue;
            }
            r = &g_Runners[i];
            bases = r->fractionalBasesRan;
            if (bases >= 3.0f) {
                return 0;
            }
            if (r->tagUpInd == 2 && r->percentTowardsNextBase >= 0.7f) {
                return r->startingBase_baseAchieved;
            }
            if (bases >= 2.0f) {
                if (bases >= 2.7f && g_Runners[i].runningDirectionCode == 1) {
                    return 0;
                }
                return 3;
            }
            if (bases >= 1.7f && g_Runners[i].runningDirectionCode == 1) {
                return 3;
            }
            return 2;
        }
    }
    return 4;
}

// .text:0x00046E08 size:0x820 mapped:0x80685E9C
void fn_3_46E08(void) {
    return;
}

// .text:0x00046ABC size:0x34C mapped:0x80685B50
void fn_3_46ABC(void) {
    return;
}

// .text:0x000468DC size:0x1E0 mapped:0x80685970
BOOL fn_3_468DC(f32* x, f32* z) {
    if (g_Ball.fielderWBallIndex >= 0) {
        *x = g_Ball.AtBat_Contact_BallPos.x;
        *z = g_Ball.AtBat_Contact_BallPos.z;
    } else if (g_Ball.fielderAboutToGetBall_hasBall >= 0) {
        *x = g_Fielders[g_Ball.fielderAboutToGetBall_hasBall]._014;
        *z = g_Fielders[g_Ball.fielderAboutToGetBall_hasBall]._01C;
    } else if (g_FieldingLogic._0F8[7] == 1) {
        if (g_FieldingLogic._0F8[8] == 1) {
            if (g_Fielders[7]._17E == -1 || g_Fielders[8]._17E == -1) {
                return FALSE;
            }
            if (g_Fielders[7]._17E < g_Fielders[8]._17E) {
                *x = g_Fielders[7]._014;
                *z = g_Fielders[7]._01C;
            } else {
                *x = g_Fielders[8]._014;
                *z = g_Fielders[8]._01C;
            }
        } else if (g_FieldingLogic._0F8[6] == 1) {
            if (g_Fielders[7]._17E == -1 || g_Fielders[6]._17E == -1) {
                return FALSE;
            }
            if (g_Fielders[7]._17E < g_Fielders[6]._17E) {
                *x = g_Fielders[7]._014;
                *z = g_Fielders[7]._01C;
            } else {
                *x = g_Fielders[6]._014;
                *z = g_Fielders[6]._01C;
            }
        } else {
            if (g_Fielders[7]._17E == -1) {
                return FALSE;
            }
            *x = g_Fielders[7]._014;
            *z = g_Fielders[7]._01C;
        }
    } else if (g_FieldingLogic._0F8[8] == 1) {
        if (g_Fielders[8]._17E == -1) {
            return FALSE;
        }
        *x = g_Fielders[8]._014;
        *z = g_Fielders[8]._01C;
    } else {
        if (g_Fielders[6]._17E == -1) {
            return FALSE;
        }
        *x = g_Fielders[6]._014;
        *z = g_Fielders[6]._01C;
    }
    return TRUE;
}

// .text:0x00046688 size:0x254 mapped:0x8068571C
BOOL fn_3_46688(f32* x, f32* z) {
    UnkAC8Fielder* f = &g_Fielders[g_FieldingLogic._0B0];
    f32 dx;
    f32 dz;
    f32 dx2;
    f32 dz2;
    f32 dist;
    f32 t;

    if (g_Ball.fielderWBallIndex >= 0) {
        *x = g_Ball.AtBat_Contact_BallPos.x;
        *z = g_Ball.AtBat_Contact_BallPos.z;
    } else if (g_Ball.ballState == 2) {
        *x = g_Ball.throwStartingLocation.x;
        *z = g_Ball.deadballLastLoc.x;
    } else if (g_Ball.fielderAboutToGetBall_hasBall >= 0) {
        *x = g_Fielders[g_Ball.fielderAboutToGetBall_hasBall]._000;
        *z = g_Fielders[g_Ball.fielderAboutToGetBall_hasBall]._008;
    } else if (g_Ball.AtBat_ContactResult == 0) {
        *x = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
        *z = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z;
    } else {
        dx = g_Ball.AtBat_Contact_BallPos.x - f->_000;
        dz = g_Ball.AtBat_Contact_BallPos.z - f->_008;
        dx2 = dx * dx;
        dz2 = dz * dz;
        dist = dolsqrtf2(dx2 + dz2);
        if (dist == 0.0f) {
            *x = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
            *z = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z;
        } else if (g_Ball.ballVelocity <= 0.01f) {
            *x = g_Ball.AtBat_Contact_BallPos.x;
            *z = g_Ball.AtBat_Contact_BallPos.z;
        } else {
            t = dist / g_Ball.ballVelocity;
            *x = g_Ball.physicsSubstruct.velocity.x * t + g_Ball.AtBat_Contact_BallPos.x;
            *z = g_Ball.physicsSubstruct.velocity.z * t + g_Ball.AtBat_Contact_BallPos.z;
        }
    }
    return TRUE;
}

// .text:0x00045E98 size:0x7F0 mapped:0x80684F2C
void fn_3_45E98(void) {
    return;
}

// .text:0x00045B88 size:0x310 mapped:0x80684C1C
void fn_3_45B88(s32 fielder) {
    return;
}

// .text:0x0004597C size:0x20C mapped:0x80684A10
// 99.77%: out.x and out.z land in f4/f3 where the target has f3/f4.
void fn_3_4597C(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    VecXZ out;
    VecXZ path[2];
    VecXZ perp[2];
    f32 dx;
    f32 dz;

    path[0].x = g_Ball.AtBat_Contact_BallPos.x;
    path[0].z = g_Ball.AtBat_Contact_BallPos.z;
    path[1].x = g_Ball.throwTarget.x;
    path[1].z = g_Ball.throwTarget.z;
    dx = -(path[1].z - path[0].z);
    dz = path[1].x - path[0].x;
    perp[0].x = f->_000;
    perp[0].z = f->_008;
    perp[1].x = f->_000 + dx;
    perp[1].z = f->_008 + dz;
    calculateLineIntersection(&out, path, perp);
    fn_3_52F4C(fielder, out.x, out.z);
}

// .text:0x00045860 size:0x11C mapped:0x806848F4
void fn_3_45860(s32 fielder) {
    return;
}

// .text:0x000455B4 size:0x2AC mapped:0x80684648
void fn_3_455B4(s32 fielder) {
    return;
}

// .text:0x00045394 size:0x220 mapped:0x80684428
void fn_3_45394(s32 fielder) {
    return;
}

// .text:0x000447C4 size:0xBD0 mapped:0x80683858
void fn_3_447C4(void) {
    return;
}

// .text:0x000433E0 size:0x13E4 mapped:0x80682474
void fn_3_433E0(void) {
    return;
}

// .text:0x00043038 size:0x3A8 mapped:0x806820CC
void fn_3_43038(void) {
    return;
}

// .text:0x00042CDC size:0x35C mapped:0x80681D70
void fn_3_42CDC(void) {
    return;
}

// .text:0x00042BD0 size:0x10C mapped:0x80681C64
void fn_3_42BD0(void) {
    return;
}

// .text:0x00042A00 size:0x1D0 mapped:0x80681A94
void fn_3_42A00(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    fn_3_52F4C(fielder, g_Ball.physicsSubstruct.futureCoordsAndDist[f->_184].pos.x,
               g_Ball.physicsSubstruct.futureCoordsAndDist[f->_184].pos.z);
    if (f->_184 <= 1) {
        f->_1DC = 5;
    }
}

// .text:0x00042850 size:0x1B0 mapped:0x806818E4
void fn_3_42850(s32 fielder) {
    fn_3_52F4C(fielder, g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z);
}

// .text:0x0004207C size:0x7D4 mapped:0x80681110
void fn_3_4207C(void) {
    return;
}

// .text:0x00041D78 size:0x304 mapped:0x80680E0C
void fn_3_41D78(void) {
    return;
}

// .text:0x0004197C size:0x3FC mapped:0x80680A10
void fn_3_4197C(void) {
    return;
}

// .text:0x000417D4 size:0x1A8 mapped:0x80680868
void fn_3_417D4(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dz;
    f32 dx;
    f32 dx2;
    f32 dz2;

    dx = g_Ball.physicsSubstruct.futureCoordsAndDist[10].pos.x - f->_000;
    dz = g_Ball.physicsSubstruct.futureCoordsAndDist[10].pos.z - f->_008;
    dx2 = dx * dx;
    dz2 = dz * dz;
    if (dolsqrtf2(dx2 + dz2) < 0.7f && f->_1DD == 2 && g_Ball.physicsSubstruct.futureCoordsAndDist[10].pos.y > f->_0F4) {
        f->_198 = 0;
        fn_3_530EC(fielder);
    }
}

// .text:0x000411AC size:0x628 mapped:0x80680240
void fn_3_411AC(void) {
    return;
}

// .text:0x00040D88 size:0x424 mapped:0x8067FE1C
void fn_3_40D88(void) {
    return;
}

// .text:0x00040D54 size:0x34 mapped:0x8067FDE8
void fn_3_40D54(void) {
    fn_3_49F40(6, 7);
    fn_3_49F40(8, 6);
}

// .text:0x00040C04 size:0x150 mapped:0x8067FC98
void fn_3_40C04(void) {
    return;
}

// .text:0x000402A8 size:0x95C mapped:0x8067F33C
void fn_3_402A8(void) {
    return;
}

// .text:0x0003FCF0 size:0x5B8 mapped:0x8067ED84
void fn_3_3FCF0(void) {
    return;
}

// .text:0x0003F760 size:0x590 mapped:0x8067E7F4
void fn_3_3F760(void) {
    return;
}

// .text:0x0003F24C size:0x514 mapped:0x8067E2E0
void fn_3_3F24C(void) {
    return;
}

// .text:0x0003F124 size:0x128 mapped:0x8067E1B8
void fn_3_3F124(void) {
    return;
}

// .text:0x0003F034 size:0xF0 mapped:0x8067E0C8
void fn_3_3F034(void) {
    return;
}

// .text:0x0003EB6C size:0x4C8 mapped:0x8067DC00
void fn_3_3EB6C(void) {
    return;
}

// .text:0x0003E690 size:0x4DC mapped:0x8067D724
void fn_3_3E690(void) {
    return;
}

// .text:0x0003E468 size:0x228 mapped:0x8067D4FC
// 92.16%: the target keeps the last loop's counter in r31 (with a stack frame), apart from
// the zero the earlier stores use; here both share one register.
void fn_3_3E468(void) {
    s32 i;
    s32 j;
    s32 best;
    f32 bestDist;

    for (i = 0; i < 9; i++) {
        g_Fielders[i]._18C = -1;
        g_Fielders[i]._1D7 = 0;
    }
    for (i = 0; i < 4; i++) {
        g_FieldingLogic._0D0[i] = -1;
        g_FieldingLogic._101[i] = 0;
    }
    g_FieldingLogic._0D8 = -1;
    g_FieldingLogic.playerAtMoundCutoffLocation = 0;
    for (i = 0; i < 4; i++) {
        bestDist = 9999.9f;
        for (j = 0; j < 6; j++) {
            if (g_FieldingLogic._0F8[j] == 0 && g_Fielders[j]._0A8[i] < bestDist) {
                bestDist = g_Fielders[j]._0A8[i];
                best = j;
            }
        }
        g_Fielders[best]._18C = i;
        g_Fielders[best]._1D7 = 1;
        fn_3_5985C(best, 1);
        g_FieldingLogic._0D0[i] = best;
    }
}

// .text:0x0003E34C size:0x11C mapped:0x8067D3E0
void fn_3_3E34C(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_19C >= 1) {
        if (f->_1C5 != 0) {
            fn_3_5985C(fielder, 0x12);
        } else {
            fn_3_5985C(fielder, 0);
        }
    } else if (g_FieldingLogic._11C != 0) {
        fn_3_5985C(fielder, 0);
    }
}

// .text:0x0003DB78 size:0x7D4 mapped:0x8067CC0C
void fn_3_3DB78(s32 fielder) {
    return;
}

// .text:0x0003D7D4 size:0x3A4 mapped:0x8067C868
void fn_3_3D7D4(void) {
    return;
}

// .text:0x0003D6AC size:0x128 mapped:0x8067C740
void fn_3_3D6AC(s32 fielder) {
    return;
}

// .text:0x0003D304 size:0x3A8 mapped:0x8067C398
void fn_3_3D304(s32 fielder) {
    return;
}

// .text:0x0003CCB0 size:0x654 mapped:0x8067BD44
void fn_3_3CCB0(s32 fielder) {
    return;
}

// .text:0x0003CB8C size:0x124 mapped:0x8067BC20
BOOL fn_3_3CB8C(s32 fielder) {
    if (g_Ball.AtBat_ContactResult > 1) {
        return FALSE;
    }
    if (g_Ball.hitWallInd != 0) {
        return FALSE;
    }
    if (g_FieldingLogic._0BC >= 0) {
        return FALSE;
    }
    if (g_Ball.AtBat_ContactResult == 0) {
        if (g_Ball.landingSpotZoneAwayFromHome >= 1 && fielder >= 6) {
            if (g_Ball.landingSpotAngle < 0x380 && fielder == 6) {
                return FALSE;
            }
            if (g_Ball.landingSpotAngle > 0x480 && fielder == 8) {
                return FALSE;
            }
            goto take;
        }
    } else if (fielder >= 6 && fielder == g_FieldingLogic._0B8) {
        goto take;
    }
    return FALSE;
take:
    fn_3_5985C(fielder, 0x18);
    g_FieldingLogic._0BC = fielder;
    return TRUE;
}

// .text:0x0003C594 size:0x5F8 mapped:0x8067B628
void fn_3_3C594(void) {
    return;
}

// .text:0x0003C484 size:0x110 mapped:0x8067B518
void fn_3_3C484(void) {
    return;
}

// .text:0x0003C270 size:0x214 mapped:0x8067B304
BOOL fn_3_3C270(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    f->_18C = 0xE;
    f->_1D7 = 2;
    fn_3_5985C(fielder, 0xE);
    f->_1D6 = 0xB;
    fn_3_52F4C(fielder, lbl_3_data_4444[4].x, lbl_3_data_4444[4].z);
    return TRUE;
}

// .text:0x0003C220 size:0x50 mapped:0x8067B2B4
void fn_3_3C220(s32 fielder) {
    return;
}

// .text:0x0003C1A8 size:0x78 mapped:0x8067B23C
void fn_3_3C1A8(s32 fielder) {
    return;
}

// .text:0x0003BE50 size:0x358 mapped:0x8067AEE4
void fn_3_3BE50(void) {
    return;
}

// .text:0x0003B9E4 size:0x46C mapped:0x8067AA78
void fn_3_3B9E4(void) {
    return;
}

// .text:0x0003B99C size:0x48 mapped:0x8067AA30
void fn_3_3B99C(void) {
    if (g_Minigame.GameMode_MiniGame == 5) {
        return;
    }
    if (!(g_FieldingLogic._14A & 0x100)) {
        return;
    }
    g_FieldingLogic._08C->_2 = 2;
    g_FieldingLogic._08C->_0 = lbl_3_bss_170[0];
}

// .text:0x0003B764 size:0x238 mapped:0x8067A7F8
void fn_3_3B764(void) {
    UnkAC8Fielder* f = &g_Fielders[g_FieldingLogic._0B0];
    f32 dx;
    f32 dz;
    f32 dx2;
    f32 dz2;

    if (g_FieldingLogic._0C4 >= 0) {
        g_Ball.fielderAboutToGetBall_hasBall = -1;
    } else if (g_FieldingLogic._0B0 >= 0 && g_Ball.looseBall_5FrameCountdown == 0) {
        if (g_Ball.AtBat_ContactResult == 0) {
            if (f->_080 < 5.0f) {
                g_Ball.fielderAboutToGetBall_hasBall = g_FieldingLogic._0B0;
            } else {
                g_Ball.fielderAboutToGetBall_hasBall = -1;
            }
        } else {
            dx = f->_000 - g_Ball.physicsSubstruct.futureCoordsAndDist[1].pos.x;
            dz = f->_008 - g_Ball.physicsSubstruct.futureCoordsAndDist[1].pos.z;
            dx2 = dx * dx;
            dz2 = dz * dz;
            if (dolsqrtf2(dx2 + dz2) <= f->_074) {
                if (fn_3_9CE0(f->_000, f->_008) < f->_0E8) {
                    g_Ball.fielderAboutToGetBall_hasBall = g_FieldingLogic._0B0;
                } else {
                    g_Ball.fielderAboutToGetBall_hasBall = -1;
                }
            }
        }
        if (g_Ball.fielderAboutToGetBall_hasBall >= 0) {
            g_Ball.ballIsLooseInd_unused = 0;
            g_Ball.looseBall_codeForHowLongUntilSomeoneWillGetIt = 0;
            g_Ball.fielderBeingThrownTo = -1;
        }
    }
}

// .text:0x0003B370 size:0x3F4 mapped:0x8067A404
void fn_3_3B370(s32 fielder) {
    return;
}

// .text:0x0003AE34 size:0x53C mapped:0x80679EC8
void fn_3_3AE34(s32 fielder) {
    return;
}

// .text:0x0003ACC0 size:0x174 mapped:0x80679D54
void fn_3_3ACC0(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s16 angle;
    s16 facing;

    if (g_Ball.fielderWithBallIndexStored >= 0) {
        goto stop;
    }
    if (fielder != g_FieldingLogic._0B0) {
        return;
    }
    if (g_FieldingLogic._139 != 0) {
        return;
    }
    if (g_Ball.framesSinceHit < lbl_3_data_484C[0]) {
        return;
    }
    if (g_Ball.framesSinceHit >= lbl_3_data_484C[1]) {
        goto stop;
    }
    if (lbl_3_bss_170[0] >= 0 && (g_FieldingLogic._148 & 0x200)) {
        goto stop;
    }
    if (ACTIVE_TUTORIAL() && g_Practice.practice_fielding_enableSprinting) {
        goto stop;
    }
    if (f->_201 != 0 && fielder >= 6 && fielder <= 8 && g_Ball.ballZoneAwayFromHome == 0) {
        return;
    }
    angle = lbl_3_bss_16C;
    if (angle < 0) {
        return;
    }
    facing = f->_19A;
    if (facing < 0) {
        if (g_Ball.framesSinceHit > f->_1D2 + 3) {
            goto stop;
        }
    } else if (fn_3_9FCF8(angle, facing) < lbl_3_data_484C[2]) {
        goto stop;
    }
    return;
stop:
    f->_1FF = 2;
    f->_201 = 0;
}

// .text:0x0003ABF0 size:0xD0 mapped:0x80679C84
void fn_3_3ABF0(s32 fielder) {
    s32 idx = g_FieldingLogic._0B0;
    UnkAC8Fielder* f = &g_Fielders[fielder];
    UnkAC8Fielder* fb = &g_Fielders[idx];

    if (g_Ball.framesSinceHit < lbl_3_data_484C[0]) {
        return;
    }
    if (g_FieldingLogic._139 != 0) {
        return;
    }
    if (fb->_256 != 1 || !(f->_084[idx] < 15.0f)) {
        if (fb->_252 == 0 || fb->_25B != 0) {
            return;
        }
    }
    fn_3_530EC(fielder);
}

// .text:0x0003AAF8 size:0xF8 mapped:0x80679B8C
void fn_3_3AAF8(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 target = lbl_3_bss_170[0];

    if (g_FieldingLogic._10E != 0) {
        target = -1;
    }
    f->_19E = target;
    if (g_GameLogic.autoFielding[g_GameLogic.awayTeamBattingInd_battingTeam] == 0 && target >= 0 && f->_1A0 > 10) {
        g_FieldingLogic._0CC = -1;
    }
    if (target < 0) {
        return;
    }
    if (g_FieldingLogic._070->_1A != 3 && g_FieldingLogic._070->_1A != 4) {
        if (g_FieldingLogic._14A & 0x200) {
            g_FieldingLogic._070->_0C = 0;
        }
        if (ACTIVE_TUTORIAL() && g_Practice.practice_fielding_enableSprinting != 0) {
            g_FieldingLogic._070->_0C = 0;
        }
    }
}

// .text:0x0003A584 size:0x574 mapped:0x80679618
void fn_3_3A584(s32 fielder) {
    return;
}

// .text:0x0003A234 size:0x350 mapped:0x806792C8
void fn_3_3A234(void) {
    return;
}

// .text:0x0003A1FC size:0x38 mapped:0x80679290
void fn_3_3A1FC(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_1B6 != 0) {
        f->_050 = f->_054;
    } else {
        f->_050 = 0.0f;
    }
}

// .text:0x00039EB0 size:0x34C mapped:0x80678F44
void fn_3_39EB0(void) {
    return;
}

// .text:0x00039DC4 size:0xEC mapped:0x80678E58
void fn_3_39DC4(void) {
    return;
}

// .text:0x00039858 size:0x56C mapped:0x806788EC
void fn_3_39858(void) {
    return;
}

// .text:0x000393B0 size:0x4A8 mapped:0x80678444
void fn_3_393B0(void) {
    return;
}

// .text:0x00038FF8 size:0x3B8 mapped:0x8067808C
void fn_3_38FF8(void) {
    return;
}

// .text:0x00038D10 size:0x2E8 mapped:0x80677DA4
void fn_3_38D10(void) {
    return;
}

// .text:0x00038790 size:0x580 mapped:0x80677824
void fn_3_38790(void) {
    return;
}

// .text:0x00038304 size:0x48C mapped:0x80677398
void fn_3_38304(void) {
    return;
}

// .text:0x00038234 size:0xD0 mapped:0x806772C8
void fn_3_38234(void) {
    return;
}

// .text:0x00038000 size:0x234 mapped:0x80677094
void fn_3_38000(void) {
    return;
}

// .text:0x000378B4 size:0x74C mapped:0x80676948
void fn_3_378B4(void) {
    return;
}

// .text:0x00037610 size:0x2A4 mapped:0x806766A4
void fn_3_37610(void) {
    return;
}

// .text:0x00037588 size:0x88 mapped:0x8067661C
void fn_3_37588(void) {
    return;
}

// .text:0x0003740C size:0x17C mapped:0x806764A0
void fn_3_3740C(void) {
    return;
}

// .text:0x00037114 size:0x2F8 mapped:0x806761A8
void fn_3_37114(void) {
    return;
}

// .text:0x00036678 size:0xA9C mapped:0x8067570C
void fn_3_36678(void) {
    return;
}

// .text:0x000365D0 size:0xA8 mapped:0x80675664
void fn_3_365D0(void) {
    return;
}

// .text:0x000361D8 size:0x3F8 mapped:0x8067526C
void fn_3_361D8(void) {
    return;
}

// .text:0x00035E1C size:0x3BC mapped:0x80674EB0
void fn_3_35E1C(void) {
    return;
}

// .text:0x00035D28 size:0xF4 mapped:0x80674DBC
void fn_3_35D28(s32 fielder) {
    return;
}

// .text:0x00034A40 size:0x12E8 mapped:0x80673AD4
void fn_3_34A40(void) {
    return;
}

// .text:0x00034450 size:0x5F0 mapped:0x806734E4
void fn_3_34450(void) {
    return;
}

// .text:0x000341E8 size:0x268 mapped:0x8067327C
void fn_3_341E8(void) {
    return;
}

// .text:0x00033DD0 size:0x418 mapped:0x80672E64
void fn_3_33DD0(void) {
    return;
}

// .text:0x00033D9C size:0x34 mapped:0x80672E30
void fn_3_33D9C(void) {
    fn_3_49F40(6, 7);
    fn_3_49F40(8, 6);
}

// .text:0x000334EC size:0x8B0 mapped:0x80672580
void fn_3_334EC(void) {
    return;
}

// .text:0x00033458 size:0x94 mapped:0x806724EC
void fn_3_33458(void) {
    return;
}

// .text:0x00033088 size:0x3D0 mapped:0x8067211C
void fn_3_33088(void) {
    return;
}

// .text:0x000329A4 size:0x6E4 mapped:0x80671A38
void fn_3_329A4(void) {
    return;
}

// .text:0x00032810 size:0x194 mapped:0x806718A4
void fn_3_32810(void) {
    return;
}

// .text:0x000327F4 size:0x1C mapped:0x80671888
BOOL fn_3_327F4(void) {
    return g_Ball.hitClassification2 == 1;
}

// .text:0x000323A4 size:0x450 mapped:0x80671438
void fn_3_323A4(void) {
    return;
}

// .text:0x00032090 size:0x314 mapped:0x80671124
void fn_3_32090(void) {
    return;
}

// .text:0x00031C50 size:0x440 mapped:0x80670CE4
void fn_3_31C50(void) {
    return;
}

// .text:0x00031A3C size:0x214 mapped:0x80670AD0
void fn_3_31A3C(void) {
    return;
}

// .text:0x00031678 size:0x3C4 mapped:0x8067070C
void fn_3_31678(void) {
    return;
}

// .text:0x00031594 size:0xE4 mapped:0x80670628
void fn_3_31594(void) {
    return;
}

// .text:0x000313B0 size:0x1E4 mapped:0x80670444
void fn_3_313B0(void) {
    return;
}

// .text:0x00030D74 size:0x63C mapped:0x8066FE08
void fn_3_30D74(void) {
    return;
}

// .text:0x00030A58 size:0x31C mapped:0x8066FAEC
void fn_3_30A58(void) {
    return;
}

// .text:0x000308B8 size:0x1A0 mapped:0x8066F94C
void fn_3_308B8(s32 fielder, f32 x, f32 z) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dx;
    f32 dz;

    f->_014 = x;
    f->_01C = z;
    dx = x - f->_000;
    dz = z - f->_008;
    if (dx == 0.0f && dz == 0.0f) {
        f->_050 = 0.0f;
        f->_068 = 0.0f;
        return;
    }
    f->_064 = atan2(dz, dx);
    f->_068 = dolsqrtf2(dx * dx + dz * dz);
    f->_1D9 = 1;
}

// .text:0x0003061C size:0x29C mapped:0x8066F6B0
void fn_3_3061C(void) {
    return;
}

// .text:0x00030564 size:0xB8 mapped:0x8066F5F8
BOOL fn_3_30564(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_25E == 3) {
        f->_150 *= lbl_3_data_4930[14];
        f->_158 *= lbl_3_data_4930[14];
        f->_000 += f->_150;
        f->_008 += f->_158;
        f->_014 = f->_000;
        f->_01C = f->_008;
        f->_1F0 = 1;
    } else if (f->_25E == 4) {
        f->_050 = 0.0f;
        f->_25F--;
        if (f->_25F == 0) {
            f->_25E = 0;
        }
    }
    return TRUE;
}

// .text:0x00030214 size:0x350 mapped:0x8066F2A8
void fn_3_30214(void) {
    return;
}

// .text:0x000300B8 size:0x15C mapped:0x8066F14C
void fn_3_300B8(void) {
    return;
}

// .text:0x0002FF2C size:0x18C mapped:0x8066EFC0
void fn_3_2FF2C(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_1B2 < 0x7FFE) {
        f->_1B2++;
    } else {
        f->_1B2 = 0x7FFF;
    }
    if (f->_205 == 5 && f->_1B2 < lbl_3_data_49DC[6]) {
        return;
    }
    if (f->_205 == 3 || f->_205 == 5) {
        if (f->_205 == 3) {
            f->_150 = f->_140 * lbl_3_data_4930[19];
            f->_158 = f->_144 * lbl_3_data_4930[19];
            f->_154 = lbl_3_data_4930[21];
        } else {
            f->_150 = f->_140 * lbl_3_data_4930[20];
            f->_158 = f->_144 * lbl_3_data_4930[20];
            f->_154 = lbl_3_data_4930[22];
        }
        f->_205++;
    } else {
        f->_150 *= lbl_3_data_4930[23];
        f->_158 *= lbl_3_data_4930[23];
        f->_154 += lbl_3_data_4930[24];
    }
    f->_000 += f->_150;
    f->_008 += f->_158;
    f->_148 += f->_154;
    if (f->_148 <= 0.0f) {
        f->_148 = 0.0f;
        f->_205 = 0;
        f->_1FC = 1;
    }
    f->_030 = f->_000 - f->_0D4;
    f->_034 = f->_008 - f->_0D8;
}

// .text:0x0002FB9C size:0x390 mapped:0x8066EC30
void fn_3_2FB9C(void) {
    return;
}

// .text:0x0002F924 size:0x278 mapped:0x8066E9B8
void fn_3_2F924(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dx;
    f32 dz;
    f32 dy;
    f32 step;

    if (f->_207 == 1) {
        dx = f->_128 - f->_000;
        dz = f->_130 - f->_008;
        dy = f->_12C - f->_148;
        if (f->_1B4 > 1) {
            step = 1.0f / f->_1B4;
        } else {
            step = 1.0f;
        }
        dx *= step;
        dz *= step;
        dy *= step;
        f->_030 = dx;
        f->_034 = dz;
        f->_000 += f->_030;
        f->_008 += f->_034;
        f->_148 += dy;
        f->_1B4--;
        if (f->_1B4 == 0) {
            f->_207 = 2;
            f->_1B4 = lbl_3_data_49DC[8];
            if (g_d_GameSettings.minigamesEnabled) {
                if (g_Minigame.minigameControlStruct.battingHandedness[f->_20D] == 0) {
                    fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[f->_20D], 2);
                }
            } else if (g_GameLogic._13E[g_GameLogic.teamFielding] == 0) {
                fn_3_6C854(g_GameLogic.teamFielding, 2);
            }
            fn_3_90220(f->_17A, 11);
        }
    } else if (f->_207 == 2) {
        f->_1B4--;
        if (f->_1B4 == 0) {
            f->_207 = 3;
            f->_1B4 = lbl_3_data_49DC[9];
        }
    } else if (f->_207 == 3) {
        f->_148 -= f->_148 / f->_1B4;
        f->_1B4--;
        if (f->_1B4 == 0) {
            f->_148 = 0.0f;
            f->_207 = 4;
            f->_1B4 = lbl_3_data_49DC[10];
        }
    } else if (f->_207 == 4) {
        f->_1B4--;
        if (f->_1B4 == 0) {
            f->_207 = 0;
        }
    }
}


// .text:0x0002F7D4 size:0x150 mapped:0x8066E868
void fn_3_2F7D4(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 type = f->_1CC;
    s32 ch = fielder;
    s32 frames;
    f32 v;
    s32 extra;

    f->_203 = 1;
    f->_15C = 0.0f;
    if (g_d_GameSettings.minigamesEnabled) {
        if (fielder == 0) {
            ch = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            ch = g_Minigame.minigameControlStruct._28[fielder - 2];
        }
    }
    f->_164 = lbl_3_data_4884[type]._0;
    v = scaleValue(f->_038, 0.1f);
    f->_160 = v * lbl_3_data_4884[type]._8;
    v = scaleValue(f->_03C, 0.1f);
    f->_168 = v * lbl_3_data_4884[type]._8;
    extra = lbl_3_data_4884[type]._C;
    frames = f->_164 / lbl_3_data_4884[type]._4;
    f->_1B0 = frames + 1;
    f->_1AE = (frames + 1) + (frames + 1) + extra;
    f->_204 = 0;
    if (type != 0) {
        fn_3_1682AC(lbl_8036E548._2C50[ch], 6);
    }
}

// .text:0x0002F574 size:0x260 mapped:0x8066E608
void fn_3_2F574(s32 fielder) {
    return;
}

// .text:0x0002F484 size:0xF0 mapped:0x8066E518
void fn_3_2F484(void) {
    return;
}

// .text:0x0002EEC4 size:0x5C0 mapped:0x8066DF58
void fn_3_2EEC4(void) {
    return;
}

// .text:0x0002EA88 size:0x43C mapped:0x8066DB1C
void fn_3_2EA88(void) {
    return;
}

// .text:0x0002EA24 size:0x64 mapped:0x8066DAB8
void fn_3_2EA24(void) {
    return;
}

// .text:0x0002E87C size:0x1A8 mapped:0x8066D910
void fn_3_2E87C(void) {
    f32 x;
    f32 z;
    s32 i;

    fn_3_58F58(0, &x, &z);
    g_Fielders[0]._000 = x;
    g_Fielders[0]._008 = z;
    g_Fielders[0]._014 = 0.0f;
    g_Fielders[0]._018 = 0.0f;
    g_Fielders[0]._01C = 0.0f;
    g_Fielders[0]._030 = 0.0f;
    g_Fielders[0]._034 = 0.0f;
    g_Fielders[0]._038 = 0.0f;
    if (g_Minigame.miniGameNumberOfParticipants >= 4) {
        g_Fielders[3]._000 = lbl_3_data_18984[2];
        g_Fielders[3]._008 = lbl_3_data_18984[3];
    } else if (g_Minigame.miniGameNumberOfParticipants >= 3) {
        g_Fielders[3]._000 = lbl_3_data_18984[0];
        g_Fielders[3]._008 = lbl_3_data_18984[1];
    }
    if (g_Minigame.miniGameNumberOfParticipants >= 4) {
        g_Fielders[4]._000 = lbl_3_data_18984[4];
        g_Fielders[4]._008 = lbl_3_data_18984[5];
    }
    for (i = 0; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];
        f->_014 = 0.0f;
        f->_018 = 0.0f;
        f->_01C = 0.0f;
        f->_030 = 0.0f;
        f->_034 = 0.0f;
        f->_0D4 = f->_000;
        f->_0D8 = f->_008;
        f->_050 = 0.0f;
        f->_1D9 = 0;
        f->_1F5 = -1;
        x = -f->_000;
        z = -f->_008;
        f->_048 = atan2(z, x);
    }
    g_AiLogic._B4 = 0;
    g_AiLogic._B8 = 0;
    g_AiLogic._B5 = 0;
    g_AiLogic._B9 = 0;
    g_AiLogic._B6 = 0;
    g_AiLogic._BA = 0;
    g_AiLogic._B7 = 0;
    g_AiLogic._BB = 0;
}

// .text:0x0002E41C size:0x460 mapped:0x8066D4B0
void fn_3_2E41C(void) {
    return;
}

// .text:0x0002DDB4 size:0x668 mapped:0x8066CE48
void fn_3_2DDB4(void) {
    return;
}

// .text:0x0002DCF4 size:0xC0 mapped:0x8066CD88
void fn_3_2DCF4(s32 fielder) {
    return;
}

// .text:0x0002DAC4 size:0x230 mapped:0x8066CB58
void fn_3_2DAC4(s32 fielder) {
    return;
}

// .text:0x0002D92C size:0x198 mapped:0x8066C9C0
void fn_3_2D92C(s32 fielder) {
    return;
}

// .text:0x0002D768 size:0x1C4 mapped:0x8066C7FC
void fn_3_2D768(void) {
    return;
}

// .text:0x0002D47C size:0x2EC mapped:0x8066C510
void fn_3_2D47C(void) {
    return;
}

// .text:0x0002D308 size:0x174 mapped:0x8066C39C
void fn_3_2D308(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dz;
    f32 dx;
    f32 dist;

    f->_19E = -1;
    dz = f->_01C - f->_008;
    dx = f->_014 - f->_000;
    dist = dolsqrtf2(dx * dx + dz * dz);
    if (dist < 0.5f) {
        f->_068 = dist;
        f->_209 = 0;
    } else {
        f->_19E = fn_3_9FB8C(dx, dz);
        f->_209 = 0;
    }
}

// .text:0x0002D080 size:0x288 mapped:0x8066C114
// Registers differ: the fielder pointer is computed earlier than in the target
// and the float temporaries take other registers.
s32 fn_3_2D080(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 bestY = 99.0f;
    s32 prevFrames = 9999;
    s32 bestIdx = 0;
    s32 found = 0;
    s32 i = 0;
    s32 margin = lbl_3_data_1C3C[1];
    s32 frames;
    f32 x;
    f32 z;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 speed;

    while (i < 360) {
        if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y > 4.5f) {
            if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y > 20.0f) {
                i += 10;
            } else if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y > 10.0f) {
                i += 5;
            } else {
                i += 2;
            }
            continue;
        }
        x = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x;
        z = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z;
        if (x == f->_000 && z == f->_008) {
            frames = 1;
        } else {
            dx = x - f->_000;
            dz = z - f->_008;
            dist = dx * dx;
            dz *= dz;
            dist = dolsqrtf2(dist + dz);
            speed = f->_058;
            if (speed == 0.0f) {
                speed = 1.0f;
            }
            frames = (s32)(dist / speed) + (f->_1D1 / 2u);
        }
        if (frames < i - margin) {
            if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y < f->_0F4) {
                break;
            }
            if (found && bestY < g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y) {
                i = bestIdx;
                break;
            }
            bestY = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y;
            bestIdx = i;
            found = 1;
        } else if (found) {
            i = bestIdx;
            break;
        }
        if (frames > prevFrames && !found) {
            break;
        }
        prevFrames = frames;
        i += 3;
    }
    if (i >= 360) {
        i = 359;
    }
    return i;
}

// .text:0x0002CEF4 size:0x18C mapped:0x8066BF88
void fn_3_2CEF4(void) {
    return;
}

// .text:0x0002CBE0 size:0x314 mapped:0x8066BC74
void fn_3_2CBE0(void) {
    return;
}

// .text:0x0002C698 size:0x548 mapped:0x8066B72C
void fn_3_2C698(void) {
    return;
}

// .text:0x0002C2F0 size:0x3A8 mapped:0x8066B384
void fn_3_2C2F0(void) {
    return;
}

// .text:0x0002C238 size:0xB8 mapped:0x8066B2CC
void fn_3_2C238(s32 fielder, s32 arg1, s32 arg2, u8 arg3, u8 arg4) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    f->_24C = arg2;
    f->_24E = 0;
    f->_252 = arg1;
    f->_253 = 0;
    f->_254 = 0;
    f->_255 = arg4;
    f->_25B = arg3;
    f->_259 = 0;
    f->_25C = 0;
    f->_25D = 0;
    f->_25E = 0;
    f->_25F = 0;
    f->_264 = 0;
    f->_260 = 0;
    if (arg1 == 7) {
        f->_260 = 1;
    }
    if (arg2 < g_Ball.framesUntilBallHitsGround) {
        f->_264 = 1;
    }
    switch (arg1) {
    case 3:
        f->_259 = 2;
        break;
    case 4:
        f->_259 = 3;
        break;
    }
    g_Ball.catchAnimationTotalFrames = 0;
}

// .text:0x0002BB04 size:0x734 mapped:0x8066AB98
void fn_3_2BB04(void) {
    return;
}

// .text:0x0002B694 size:0x470 mapped:0x8066A728
void fn_3_2B694(void) {
    return;
}

// .text:0x0002B5C0 size:0xD4 mapped:0x8066A654
void fn_3_2B5C0(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s16 ballAngle;
    s16 diff;

    f->_261 = 0;
    ballAngle = fn_3_9FB8C(g_Ball.AtBat_Contact_BallPos.x - f->_000, g_Ball.AtBat_Contact_BallPos.z - f->_008);
    diff = fn_3_9FCA4(ballAngle, fn_3_9FB8C(f->_21C - f->_000, f->_224 - f->_008));
    if (diff < -0x500 || diff > 0x500) {
        f->_261 = 3;
    } else if (diff < -0x200) {
        f->_261 = 1;
    } else if (diff > 0x200) {
        f->_261 = 2;
    }
}

// .text:0x0002AD68 size:0x858 mapped:0x80669DFC
void fn_3_2AD68(void) {
    return;
}

// .text:0x0002ACD8 size:0x90 mapped:0x80669D6C
void fn_3_2ACD8(void) {
    return;
}

// .text:0x0002A69C size:0x63C mapped:0x80669730
void fn_3_2A69C(void) {
    return;
}

// .text:0x0002A288 size:0x414 mapped:0x8066931C
void fn_3_2A288(void) {
    return;
}

// .text:0x0002A164 size:0x124 mapped:0x806691F8
BOOL fn_3_2A164(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_074 > lbl_3_data_47D0[f->_1CA]._08) {
        return FALSE;
    }
    if (g_Ball.AtBat_Contact_BallPos.y < f->_15C) {
        return FALSE;
    }
    if (g_Ball.AtBat_Contact_BallPos.y > f->_15C + f->_0F4) {
        return FALSE;
    }
    if (fn_3_B7CDC(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
        return FALSE;
    }
    fn_3_2C238(fielder, 6, 1, 0, 0);
    return TRUE;
}

// .text:0x00028CA8 size:0x14BC mapped:0x80667D3C
void fn_3_28CA8(void) {
    return;
}

// .text:0x00028224 size:0xA84 mapped:0x806672B8
void fn_3_28224(void) {
    return;
}

// .text:0x00027FF4 size:0x230 mapped:0x80667088
BOOL fn_3_27FF4(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    VecSrcDst line;
    CollisionStruct hit;
    f32 len;

    if ((f->_038 == 0.0f && f->_03C == 0.0f) || f->_19A < 0) {
        return FALSE;
    }
    line.src.x = f->_000;
    line.dst.y = -lbl_3_data_4930[29];
    line.src.y = -lbl_3_data_4930[29];
    line.src.z = f->_008;
    line.dst.x = f->_000 + f->_038 * lbl_3_data_4930[28];
    line.dst.z = f->_008 + f->_03C * lbl_3_data_4930[28];
    if ((checkCollision(&line, &hit, 0, FALSE) & 0x7F) != 2) {
        return FALSE;
    }
    f->_207 = 1;
    f->_1B4 = lbl_3_data_49DC[7];
    f->_128 = hit.position.x;
    f->_12C = lbl_3_data_4930[29];
    f->_130 = hit.position.z;
    f->_148 = 0.0f;
    len = dolsqrtf2(hit.normal.x * hit.normal.x + hit.normal.z * hit.normal.z);
    f->_140 = hit.normal.x / len;
    f->_144 = hit.normal.z / len;
    f->_050 = 0.0f;
    return TRUE;
}

// .text:0x00027D68 size:0x28C mapped:0x80666DFC
// Registers only: the distance temporaries and loop bounds take other
// float registers than the target's.
BOOL fn_3_27D68(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 i;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 h = f->_148;
    f32 top = 1.0f + (f->_0F4 + h);
    f32 bottom = f->_0FC + h;

    for (i = 1; i < 11; i++) {
        if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].dist < f->_070 &&
            g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y > bottom &&
            g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y < top) {
            dx = f->_000 - g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x;
            dz = f->_008 - g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z;
            dist = dx * dx;
            dz *= dz;
            dist = dolsqrtf2(dist + dz);
            if (dist < f->_0E8) {
                goto found;
            }
        }
    }
    return FALSE;

found:
    if (g_Ball.physicsSubstruct.futureCoordsAndDist[i + 1].dist < f->_070) {
        i -= 2;
    } else if (g_Ball.physicsSubstruct.futureCoordsAndDist[i + 2].dist < f->_070) {
        i -= 1;
    }
    if (i < 0) {
        i = 0;
    }
    fn_3_2C238(fielder, 5, i, 0, 0);
    fn_3_1AE44(3, 0, g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x,
               g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y,
               g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z);
    return TRUE;
}


// .text:0x00027860 size:0x508 mapped:0x806668F4
void fn_3_27860(void) {
    return;
}

// .text:0x00027764 size:0xFC mapped:0x806667F8
void fn_3_27764(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (g_d_GameSettings.GameModeSelected != 6 && fielder != g_FieldingLogic._0B0) {
        fn_3_5985C(fielder, 0xC);
    }
    f->_252 = 0;
    f->_050 = 0.0f;
    f->_194 = 0;
    f->_1E9 = 0;
    f->_1DF = 0;
    f->_205 = 0;
    f->_25E = 0;
    if (f->_1E8 != 0) {
        f->_1E8 = 2;
    }
    if (g_Ball.fielderWBallIndex >= 0 && g_Ball.catchAnimationTotalFrames != 0) {
        g_Ball.catchAnimationTotalFrames = 0;
        g_Ball.AtBat_Contact_BallPos.x = g_Ball.fielderActionCatchCoords.x;
        g_Ball.AtBat_Contact_BallPos.y = g_Ball.fielderActionCatchCoords.y;
        g_Ball.AtBat_Contact_BallPos.z = g_Ball.fielderActionCatchCoords.z;
    }
}

// .text:0x00027738 size:0x2C mapped:0x806667CC
void fn_3_27738(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    f->_25B = 1;
    g_Ball.catchAnimationTotalFrames = 0;
}

// .text:0x00027648 size:0xF0 mapped:0x806666DC
void fn_3_27648(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (g_Fielders[i]._252 != 0) {
            fn_3_27738(i);
        }
    }
}

// .text:0x00026A74 size:0xBD4 mapped:0x80665B08
void fn_3_26A74(void) {
    return;
}

// .text:0x00026664 size:0x410 mapped:0x806656F8
void fn_3_26664(void) {
    return;
}

// .text:0x000261E8 size:0x47C mapped:0x8066527C
void fn_3_261E8(void) {
    return;
}

// .text:0x00025C40 size:0x5A8 mapped:0x80664CD4
void fn_3_25C40(void) {
    return;
}

// .text:0x00025A68 size:0x1D8 mapped:0x80664AFC
void fn_3_25A68(s32 fielder) {
    return;
}

// .text:0x000258D8 size:0x190 mapped:0x8066496C
BOOL fn_3_258D8(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (g_FieldingLogic._08C->_2 == 0) {
        return FALSE;
    }
    if (f->_25A != 0) {
        return FALSE;
    }
    fn_3_2F7D4(fielder);
    g_FieldingLogic._08C->_2 = 0;
    return TRUE;
}

// .text:0x00025844 size:0x94 mapped:0x806648D8
void fn_3_25844(int fielder, int arg1) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_20F == 0) {
        f->_1BC = radToShortAngle(f->_048);
        f->_20F = 1;
        f->_1B8 = 0;
        f->_1BA = lbl_3_data_49DC[arg1 + 29];
        f->_252 = 0;
        f->_203 = 0;
        f->_205 = 0;
        f->_207 = 0;
        f->_1EE = 0;
    }
}

// .text:0x00025648 size:0x1FC mapped:0x806646DC
void fn_3_25648(s32 fielder) {
    return;
}

// .text:0x000253A4 size:0x2A4 mapped:0x80664438
// 99.29%: one `li r0,0` is scheduled an instruction earlier than in the target.
BOOL fn_3_253A4(s32 fielder, s32 angle) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_207 != 0 || f->_205 != 0 || f->_25E != 0) {
        return FALSE;
    }
    f->_1C2 = angle;
    f->_210 = 1;
    f->_1BE = 0;
    f->_1C0 = lbl_3_data_49DC[33];
    f->_174 = lbl_3_data_4930[34];
    if (f->_252 == 4 || f->_252 == 5) {
        f->_174 = 0.0f;
    }
    if (f->_207 != 0) {
        f->_174 = 0.0f;
    }
    if (g_d_GameSettings.minigamesEnabled) {
        if (g_Minigame.minigameControlStruct.battingHandedness[f->_20D] == 0) {
            fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[f->_20D], 2);
        }
    } else if (g_GameLogic._13E[g_GameLogic.teamFielding] == 0) {
        fn_3_6C854(g_GameLogic.teamFielding, 2);
    }
    fn_3_90220(f->_17A, 10);
    if (g_Ball.fielderWBallIndex == fielder) {
        fn_3_A9354(fielder, 1);
        g_FieldingLogic._13B = 1;
        g_FieldingLogic._111 = 0;
    }
    if (f->_252 != 0) {
        fn_3_27764(fielder);
    }
    f->_262 = 0;
    f->_203 = 0;
    f->_20F = 0;
    f->_1EE = 0;
    g_Ball.catchAnimationTotalFrames = 0;
    return TRUE;
}

// .text:0x000251E4 size:0x1C0 mapped:0x80664278
// Waits on fn_3_51798: while that is a stub it is inlined here and folds the result.
void fn_3_251E4(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    struct _VecXYZ pos;
    s32 result;

    if (f->_1BE < 0x7FFE) {
        f->_1BE++;
    } else {
        f->_1BE = 0x7FFF;
    }
    f->_1C0--;
    if (f->_210 == 1) {
        if (f->_1C0 <= 0) {
            f->_210 = 2;
            f->_1BE = 0;
            f->_1C0 = lbl_3_data_49DC[34];
            return;
        }
        f->_174 *= lbl_3_data_4930[35];
        f->_050 = f->_174;
        getComponentsFromSAng(f->_1C2, &f->_038, &f->_03C);
        f->_030 = f->_038 * f->_050;
        f->_034 = f->_03C * f->_050;
        result = fn_3_51798(fielder, &pos);
        if (result != 0) {
            if (result == 2 && !(pos.x > 55.0f) && !(pos.x < -55.0f)) {
                f->_030 = pos.x - f->_000;
                f->_034 = pos.z - f->_008;
                f->_000 = pos.x;
                f->_008 = pos.z;
            } else {
                f->_050 = 0.0f;
                f->_030 = 0.0f;
                f->_034 = 0.0f;
            }
        } else {
            f->_000 += f->_030;
            f->_008 += f->_034;
        }
        f->_014 = f->_000;
        f->_01C = f->_008;
    } else if (f->_1C0 <= 0) {
        f->_210 = 0;
    }
}
