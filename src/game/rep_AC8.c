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
#include "game/rep_4090.h"
#include "string.h"

typedef struct UnkAC8Fielder {
    /* 0x000 */ f32 _000;
    /* 0x004 */ f32 _004;
    /* 0x008 */ f32 _008;
    /* 0x00C */ f32 _00C;
    /* 0x010 */ f32 _010;
    /* 0x014 */ f32 _014;
    /* 0x018 */ f32 _018;
    /* 0x01C */ f32 _01C;
    /* 0x020 */ f32 _020;
    /* 0x024 */ f32 _024;
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
    /* 0x060 */ f32 _060;
    /* 0x064 */ f32 _064;
    /* 0x068 */ f32 _068;
    /* 0x06C */ f32 _06C;
    /* 0x070 */ f32 _070;
    /* 0x074 */ f32 _074;
    /* 0x078 */ f32 _078;
    /* 0x07C */ f32 _07C;
    /* 0x080 */ f32 _080;
    /* 0x084 */ f32 _084[9];
    /* 0x0A8 */ f32 _0A8[4];
    /* 0x0B8 */ f32 _0B8;
    /* 0x0BC */ f32 _0BC[5];
    /* 0x0D0 */ u8 _0D0[0xD4 - 0xD0];
    /* 0x0D4 */ f32 _0D4;
    /* 0x0D8 */ f32 _0D8;
    /* 0x0DC */ u8 _0DC[0xE8 - 0xDC];
    /* 0x0E8 */ f32 _0E8;
    /* 0x0EC */ u8 _0EC[0xF4 - 0xEC];
    /* 0x0F4 */ f32 _0F4;
    /* 0x0F8 */ f32 _0F8;
    /* 0x0FC */ f32 _0FC;
    /* 0x100 */ u8 _100[0x118 - 0x100];
    /* 0x118 */ f32 _118;
    /* 0x11C */ f32 _11C;
    /* 0x120 */ u8 _120[0x128 - 0x120];
    /* 0x128 */ f32 _128;
    /* 0x12C */ f32 _12C;
    /* 0x130 */ f32 _130;
    /* 0x134 */ f32 _134;
    /* 0x138 */ f32 _138;
    /* 0x13C */ f32 _13C;
    /* 0x140 */ f32 _140;
    /* 0x144 */ f32 _144;
    /* 0x148 */ f32 _148;
    /* 0x14C */ f32 _14C;
    /* 0x150 */ f32 _150;
    /* 0x154 */ f32 _154;
    /* 0x158 */ f32 _158;
    /* 0x15C */ f32 _15C;
    /* 0x160 */ f32 _160;
    /* 0x164 */ f32 _164;
    /* 0x168 */ f32 _168;
    /* 0x16C */ u8 _16C[0x174 - 0x16C];
    /* 0x174 */ f32 _174;
    /* 0x178 */ s16 _178;
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x17E - 0x17C];
    /* 0x17E */ s16 _17E;
    /* 0x180 */ s16 _180;
    /* 0x182 */ s16 _182;
    /* 0x184 */ s16 _184;
    /* 0x186 */ s16 _186;
    /* 0x188 */ s16 _188;
    /* 0x18A */ s16 _18A;
    /* 0x18C */ s16 _18C;
    /* 0x18E */ u8 _18E[0x190 - 0x18E];
    /* 0x190 */ s16 _190;
    /* 0x192 */ s16 _192;
    /* 0x194 */ s16 _194;
    /* 0x196 */ u8 _196[0x198 - 0x196];
    /* 0x198 */ s16 _198;
    /* 0x19A */ s16 _19A;
    /* 0x19C */ s16 _19C;
    /* 0x19E */ s16 _19E;
    /* 0x1A0 */ s16 _1A0;
    /* 0x1A2 */ s16 _1A2;
    /* 0x1A4 */ s16 _1A4;
    /* 0x1A6 */ s16 _1A6;
    /* 0x1A8 */ s16 _1A8;
    /* 0x1AA */ u8 _1AA[0x1AC - 0x1AA];
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
    /* 0x1C7 */ u8 _1C7;
    /* 0x1C8 */ u8 _1C8;
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA;
    /* 0x1CB */ u8 _1CB[0x1CC - 0x1CB];
    /* 0x1CC */ u8 _1CC;
    /* 0x1CD */ u8 _1CD;
    /* 0x1CE */ u8 _1CE;
    /* 0x1CF */ u8 _1CF;
    /* 0x1D0 */ u8 _1D0;
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2;
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4;
    /* 0x1D5 */ u8 _1D5;
    /* 0x1D6 */ u8 _1D6;
    /* 0x1D7 */ u8 _1D7;
    /* 0x1D8 */ u8 _1D8[0x1D9 - 0x1D8];
    /* 0x1D9 */ u8 _1D9;
    /* 0x1DA */ u8 _1DA;
    /* 0x1DB */ u8 _1DB;
    /* 0x1DC */ u8 _1DC;
    /* 0x1DD */ u8 _1DD;
    /* 0x1DE */ u8 _1DE;
    /* 0x1DF */ u8 _1DF;
    /* 0x1E0 */ u8 _1E0;
    /* 0x1E1 */ u8 _1E1[0x1E3 - 0x1E1];
    /* 0x1E3 */ u8 _1E3;
    /* 0x1E4 */ u8 _1E4;
    /* 0x1E5 */ u8 _1E5[0x1E8 - 0x1E5];
    /* 0x1E8 */ u8 _1E8;
    /* 0x1E9 */ u8 _1E9;
    /* 0x1EA */ u8 _1EA[0x1EC - 0x1EA];
    /* 0x1EC */ u8 _1EC;
    /* 0x1ED */ u8 _1ED;
    /* 0x1EE */ u8 _1EE;
    /* 0x1EF */ u8 _1EF;
    /* 0x1F0 */ u8 _1F0;
    /* 0x1F1 */ u8 _1F1;
    /* 0x1F2 */ u8 _1F2;
    /* 0x1F3 */ u8 _1F3;
    /* 0x1F4 */ u8 _1F4;
    /* 0x1F5 */ s8 _1F5;
    /* 0x1F6 */ u8 _1F6;
    /* 0x1F7 */ s8 _1F7;
    /* 0x1F8 */ u8 _1F8;
    /* 0x1F9 */ u8 _1F9;
    /* 0x1FA */ u8 _1FA;
    /* 0x1FB */ u8 _1FB;
    /* 0x1FC */ u8 _1FC;
    /* 0x1FD */ u8 _1FD[0x1FF - 0x1FD];
    /* 0x1FF */ u8 _1FF;
    /* 0x200 */ u8 _200;
    /* 0x201 */ u8 _201;
    /* 0x202 */ u8 _202[0x203 - 0x202];
    /* 0x203 */ u8 _203;
    /* 0x204 */ u8 _204;
    /* 0x205 */ u8 _205;
    /* 0x206 */ u8 _206;
    /* 0x207 */ u8 _207;
    /* 0x208 */ u8 _208;
    /* 0x209 */ u8 _209;
    /* 0x20A */ u8 _20A[0x20B - 0x20A];
    /* 0x20B */ u8 _20B;
    /* 0x20C */ u8 _20C;
    /* 0x20D */ u8 _20D;
    /* 0x20E */ u8 _20E;
    /* 0x20F */ u8 _20F;
    /* 0x210 */ u8 _210;
    /* 0x211 */ u8 _211;
    /* 0x212 */ u8 _212;
    /* 0x213 */ u8 _213;
    /* 0x214 */ u8 _214;
    /* 0x215 */ u8 _215;
    /* 0x216 */ u8 _216;
    /* 0x217 */ u8 _217;
    /* 0x218 */ u8 _218;
    /* 0x219 */ u8 _219;
    /* 0x21A */ u8 _21A[0x21C - 0x21A];
    /* 0x21C */ f32 _21C;
    /* 0x220 */ f32 _220;
    /* 0x224 */ f32 _224;
    /* 0x228 */ f32 _228;
    /* 0x22C */ f32 _22C;
    /* 0x230 */ f32 _230;
    /* 0x234 */ u8 _234[0x248 - 0x234];
    /* 0x248 */ f32 _248;
    /* 0x24C */ s16 _24C;
    /* 0x24E */ s16 _24E;
    /* 0x250 */ s16 _250;
    /* 0x252 */ u8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ u8 _254;
    /* 0x255 */ u8 _255;
    /* 0x256 */ u8 _256;
    /* 0x257 */ u8 _257;
    /* 0x258 */ u8 _258;
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
    /* 0x265 */ u8 _265;
    /* 0x266 */ u8 _266[0x268 - 0x266];
} UnkAC8Fielder; // size: 0x268

extern UnkAC8Fielder g_Fielders[9];

extern struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ s16 _04;
    /* 0x06 */ u8 _06[0xE - 0x6];
    /* 0x0E */ s16 _0E;
    /* 0x10 */ u8 _10;
} g_RunningLogic;

typedef struct {
    /* 0x000 */ u8 _00[0x62];
    /* 0x062 */ s16 _62;
    /* 0x064 */ u8 _64[0x27A - 0x64];
    /* 0x27A */ u8 _27A;
} UnkAC8Actor;

// One model per fielder, then the batter's and the runners'
extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    union {
        /* 0x2C50 */ struct UnkPlayer3E58* _2C50[13];
        /* 0x2C50 */ UnkAC8Actor* actors[13];
    };
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
extern f32 lbl_3_data_4780[5];
extern VecXZ lbl_3_data_44B4[11];
extern VecXZ lbl_3_data_450C[9];
extern VecXZ lbl_3_data_4554[4][3];
extern VecXZ lbl_3_data_45B4[4];
extern VecXZ lbl_3_data_45D4[4];
extern VecXZ lbl_3_data_4290[7][2];
extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];
extern u8 fn_800639BC(s8 fielder, VecXYZ* pos, VecXYZ* prev);
extern void fn_80063958(s8 fielder);
extern void fn_3_13A048(s32 to, s32 from);
extern int RandomInt_Game_Range(int min, int max);
extern s16 fn_3_9FD28(s16 ang);
extern int fn_3_6D658(int team, int charID, int otherCharID);
extern f32 lbl_3_data_4618[8];
extern s16 lbl_3_data_4638[4];
extern f32 lbl_3_data_48C4;
extern s16 lbl_3_data_48C8[2][12];
extern f32 lbl_3_data_5CDC[11];
extern struct {
    /* 0x000 */ u8 _000[0x1D5];
    /* 0x1D5 */ u8 _1D5;
} lbl_3_common_bss_34C90;
extern VecXZ lbl_3_data_4300[9];
extern f32 lbl_3_data_4348[7][2];
extern void fn_3_9F79C(f32 a, f32 b, f32 c, f32* x, f32* y);

typedef struct {
    /* 0x0 */ f32 _0;
    /* 0x4 */ f32 _4;
    /* 0x8 */ f32 _8;
    /* 0xC */ f32 _C;
} UnkAC8Data4884; // size: 0x10

extern UnkAC8Data4884 lbl_3_data_4884[2];
extern u8 lbl_3_data_470C[2];
extern f32 lbl_3_data_1C44[4];
extern s16 lbl_3_data_1C54[2];
extern f32 lbl_3_data_4848;
extern s16 lbl_3_data_484C[10];
extern f32 lbl_3_data_4930[43];
extern f32 lbl_3_data_18984[6];
extern s16 lbl_3_data_1C3C[2];
extern u8 lbl_3_data_48F8[8];
extern s16 lbl_3_data_49DC[44];
extern f32 lbl_3_data_476C[5];
extern f32 lbl_3_data_4794[10];
extern s16 lbl_3_data_48A4[3][5];
extern u8 lbl_3_data_4900[2][3];
extern s16 lbl_3_data_4924[6];
extern f32 lbl_3_data_4B98;
extern s16 lbl_3_data_4B9C[6];
extern u8 lbl_3_data_4714[2][4][6];
extern f32 lbl_3_data_5FC4[12];
extern int RandomInt_Game(int max);
extern f32 lbl_3_data_46F0;
extern f32 lbl_3_data_46F4;
extern f32 lbl_3_data_21A14[7];
extern struct {
    /* 0x000 */ s16 sizes[54][8];
    /* 0x360 */ s16 mins[8];
} lbl_3_data_79B4;
extern s16 lbl_3_data_7F10[54];
extern f32 game_atan2(f32 x, f32 y);
extern f32 fn_3_9FEA8(f32 v);
extern s16 fn_3_9FE6C_normalizeAngle(s16);
extern f32 shortAngleToRad_Capped(s16);
extern void getComponentsFromRad(f32 v, f32* x, f32* y);
extern u8 fn_3_1379A0(int fielderIdx);

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
static s16 lbl_3_bss_CC[4][20];
static s16 lbl_3_bss_C8[2];

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
    s32 i;

    fn_3_58870();
    for (i = 0; i < 9; i++) {
        g_FieldingLogic._0F8[i] = 0;
        g_Fielders[i]._1CF = 100;
        g_Fielders[i]._058 = 0.0003f * g_Fielders[i]._1CF + 0.1f;
        g_Fielders[i]._1CD = 120;
        g_Fielders[i]._1D2 = 10;
        g_Fielders[i]._1D1 = 15;
        g_Fielders[i]._05C = g_Fielders[i]._058 / g_Fielders[i]._1D1;
        g_Fielders[i]._1D3 = 0;
        g_Fielders[i]._1D9 = 0;
        g_Fielders[i]._1F1 = 0;
        g_Fielders[i]._1E3 = 0;
        g_Fielders[i]._219 = 1;
        g_Fielders[i]._178 = -1;
    }
    g_FieldingLogic._0B0 = -1;
    g_FieldingLogic._000[0]._08 = 1.0f;
    g_FieldingLogic._000[0]._08 = 1.0f;
    g_FieldingLogic._000[0]._08 = 1.0f;
    g_FieldingLogic._0B2 = -1;
    g_FieldingLogic._0B4 = -1;
    g_FieldingLogic._0B6 = -1;
    g_FieldingLogic._0B8 = -1;
    g_FieldingLogic._0BA = -1;
    g_FieldingLogic._0BE = -1;
    g_FieldingLogic._136 = 1;
    g_FieldingLogic._137 = 0;
    g_FieldingLogic._070 = g_FieldingLogic._000;
    g_FieldingLogic._08C = (FieldingLogic08C*)g_FieldingLogic._074;
    g_FieldingLogic._000[0]._08 = 1.0f;
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
    s32 i;

    if (!g_d_GameSettings.minigamesEnabled) {
        fn_3_591AC();
    }
    for (i = 0; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];
        g_FieldingLogic._0F8[i] = 0;

        f->_18C = -1;
        f->_1D7 = 0;
        f->_1D8[0] = 0;
        f->_1D3 = 0;
        f->_1DD = 0;
        f->_17E = -1;
        f->_190 = -1;
        f->_1D5 = 0;
        f->_1D6 = 0;
        f->_192 = 0xF;
        f->_194 = 0;
        f->_1DF = 0;
        f->_198 = 0;
        f->_1E0 = 0;
        f->_1DB = 0;
        f->_1DC = 0;
        f->_19C = 0;
        f->_1EA[0] = 0;
        f->_1E9 = 0;
        f->_1EC = 0;
        f->_1ED = 0;
        f->_1EE = 0;
        f->_1EF = 0;
        f->_1E1[0] = 0;
        f->_1E3 = 1;
        f->_1E4 = 0;
        f->_050 = 0.0f;
        f->_060 = 0.0f;
        f->_1A0 = 0;
        f->_1F2 = 0;
        f->_1E5[2] = 0;
        f->_1F3 = 0;
        f->_1F4 = 0;
        f->_1F5 = -1;
        f->_1F7 = -1;
        f->_1F9 = 0;
        f->_1FA = 0;
        f->_1A8 = 0;
        f->_1FC = 1;
        f->_200 = 0;
        f->_201 = 0;
        f->_202[0] = 0;
        f->_203 = 0;
        f->_205 = 0;
        f->_207 = 0;
        f->_148 = 0.0f;
        f->_208 = 0;
        f->_209 = 0;
        f->_1B6 = 0;
        f->_20B = 0;
        f->_20C = 0;
        f->_18A = 0;
        f->_20F = 0;
        f->_1FD[0] = 0;
        f->_1FD[1] = 0;
        f->_215 = 0;
        f->_216 = 0;
        f->_210 = 0;
        f->_211 = 0;
        f->_212 = 0;
        f->_250 = 0;
        f->_252 = 0;
        f->_25B = 0;
        f->_256 = 0;
        f->_258 = 0;
        f->_259 = 0;
        f->_25A = 0;
        f->_25C = 0;
        f->_25E = 0;
        f->_25F = 0;
        f->_262 = 0;
        f->_263 = 0;
        f->_260 = 0;
        f->_265 = 0;
        f->_252 = 0;
        f->_1C5 = 0;
        f->_1C6 = 0;
        if (!g_d_GameSettings.minigamesEnabled) {
            fn_3_5372C(i);
            if (g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam] != 0) {
                f->_1C5 = 1;
            }
            if (g_GameLogic.autoFielding[g_GameLogic.awayTeamBattingInd_battingTeam] != 0) {
                f->_1C6 = 1;
            }
        }
    }
    if (g_d_GameSettings.minigamesEnabled) {
        if (g_Minigame.minigamePlayerSelectedOrder >= 0) {
            if (g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.minigamePlayerSelectedOrder] != 0) {
                g_Fielders[0]._1C5 = 1;
                g_Fielders[0]._1C6 = 1;
            }
        } else if (g_Minigame.minigameControlStruct._28[0] >= 0 &&
                   g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.minigameControlStruct._28[0]] != 0) {
            g_Fielders[2]._1C5 = 1;
            g_Fielders[2]._1C6 = 1;
        }
        for (i = 1; i < 4; i++) {
            if (g_Minigame.minigameControlStruct._28[i] >= 0 &&
                g_Minigame.minigameControlStruct.battingHandedness[g_Minigame.minigameControlStruct._28[i]] != 0) {
                g_Fielders[i + 2]._1C5 = 1;
                g_Fielders[i + 2]._1C6 = 1;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        g_FieldingLogic._0D0[i] = -1;
        g_FieldingLogic._101[i] = 0;
    }
    g_FieldingLogic._0D8 = -1;
    g_FieldingLogic.playerAtMoundCutoffLocation = 0;
    g_FieldingLogic._0B0 = -1;
    g_FieldingLogic._0B2 = -1;
    g_FieldingLogic._0B4 = -1;
    g_FieldingLogic._0BC = -1;
    g_FieldingLogic._0BE = -1;
    g_FieldingLogic._0C2 = -1;
    g_FieldingLogic._0C4 = -1;
    g_FieldingLogic._0C6 = -1;
    g_FieldingLogic._0CA = -1;
    g_FieldingLogic._0CC = -1;
    g_FieldingLogic._0DA = 0;
    g_FieldingLogic._0DE = -1;
    g_FieldingLogic._0DC = -1;
    g_FieldingLogic._0E2 = -1;
    g_FieldingLogic._0E8 = -1;
    g_FieldingLogic._0EA = -1;
    g_FieldingLogic._0EC = 0;
    g_FieldingLogic._0F0 = 0;
    g_FieldingLogic._0F2 = 0;
    g_FieldingLogic._107 = 0;
    g_FieldingLogic._108 = 0;
    g_FieldingLogic._10A = 0;
    g_FieldingLogic._111 = 0;
    g_FieldingLogic._10D = 0;
    g_FieldingLogic._113 = 0;
    g_FieldingLogic._114 = 0;
    g_FieldingLogic._116 = 0;
    g_FieldingLogic._117 = 1;
    g_FieldingLogic._118 = 1;
    g_FieldingLogic._11A = 0;
    g_FieldingLogic._11C = 0;
    g_FieldingLogic._11F = 0;
    g_FieldingLogic._120 = 0;
    g_FieldingLogic._115 = -1;
    g_FieldingLogic.throwSpeedType = 0;
    g_FieldingLogic._11D = 0;
    g_FieldingLogic._121 = -1;
    g_FieldingLogic._122 = 0;
    g_FieldingLogic._124 = 0;
    g_FieldingLogic._125 = -1;
    g_FieldingLogic._126 = -1;
    g_FieldingLogic._127 = 0;
    g_FieldingLogic._12A = 0;
    g_FieldingLogic._12B = 0;
    g_FieldingLogic._12C = 0;
    g_FieldingLogic._12D = 1;
    g_FieldingLogic._12E = 0;
    g_FieldingLogic._12F = 0;
    g_FieldingLogic._132 = 0;
    g_FieldingLogic._131 = 0;
    g_FieldingLogic._0F4 = -1;
    g_FieldingLogic._133 = 0;
    g_FieldingLogic._135 = 0;
    g_FieldingLogic._138 = 0;
    g_FieldingLogic._139 = 0;
    g_FieldingLogic._13A = 0;
    g_FieldingLogic._13B = 0;
    g_FieldingLogic._13F = 0;
    g_FieldingLogic._0F6 = 0;
    g_FieldingLogic._130 = 0;
    g_FieldingLogic._13E = 0;
    g_FieldingLogic._140 = 0;
    g_FieldingLogic._142 = 0;
    g_FieldingLogic._141 = 0;
    g_FieldingLogic._143 = 0;
    g_FieldingLogic._134 = -1;
    g_FieldingLogic._145 = 0;
    g_FieldingLogic._146 = 0;
    g_FieldingLogic._0C0 = 0;
    for (i = 0; i < 4; i++) {
        g_FieldingLogic._000[i]._0C = -1;
        g_FieldingLogic._000[i]._0E = -1;
        g_FieldingLogic._000[i]._10 = 0;
        g_FieldingLogic._000[i]._12 = 0;
        g_FieldingLogic._000[i]._14 = -1;
        g_FieldingLogic._000[i]._1A = 0;
    }
    g_FieldingLogic._070 = g_FieldingLogic._000;
    g_FieldingLogic._08C = (FieldingLogic08C*)g_FieldingLogic._074;
    g_AiLogic._78 = 0;
    for (i = 0; i < 20; i++) {
        lbl_3_bss_170[i] = -1;
    }
    lbl_3_bss_16C = -1;
    if (!g_d_GameSettings.minigamesEnabled) {
        s32 team = g_GameLogic.awayTeamBattingInd_battingTeam;

        if (g_GameLogic.battingOrderAndPositionMapping[team][0][0] >= 9) {
            if (g_GameLogic.battingOrderAndPositionMapping[team][0][1] >= 20) {
                g_GameLogic.battingOrderAndPositionMapping[team][0][1] -= 20;
            } else if (g_GameLogic.battingOrderAndPositionMapping[team][0][1] >= 10) {
                g_GameLogic.battingOrderAndPositionMapping[team][0][1] -= 10;
            }
        }
        g_Pitcher.unused_pitcherIsFielder = 0;
    }
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
    f32 best;
    s32 bestIdx;
    f32 second;
    s32 secondIdx;
    s32 i;

    if (g_Ball.fielderWBallIndex >= 0) {
        g_FieldingLogic._0B0 = g_Ball.fielderWBallIndex;
        return;
    }
    if (g_Ball.ballState == 2) {
        g_FieldingLogic._0B0 = g_Ball.fielderBeingThrownTo;
        return;
    }
    second = 999.9f;
    secondIdx = -1;
    best = 999.9f;
    bestIdx = -1;
    for (i = 1; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];

        if (f->_1D3 == 2 || f->_1D3 == 3) {
            if (f->_07C < second) {
                if (f->_07C < best) {
                    second = best;
                    secondIdx = bestIdx;
                    best = f->_07C;
                    bestIdx = i;
                } else {
                    second = f->_07C;
                    secondIdx = i;
                }
            }
        }
    }
    if (bestIdx >= 0) {
        g_FieldingLogic._0B0 = bestIdx;
    } else if (g_Fielders[0]._1D3 == 2 || g_Fielders[0]._1D3 == 3 || g_Fielders[0]._1D3 == 4) {
        g_FieldingLogic._0B0 = 0;
    }
    if (secondIdx >= 0) {
        g_FieldingLogic._0B2 = secondIdx;
    }
    if (g_FieldingLogic._0B0 >= 0) {
        fn_3_576B4(g_FieldingLogic._0B0);
    }
}

// .text:0x000576B4 size:0x360 mapped:0x80696748
void fn_3_576B4(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 i;

    if (g_FieldingLogic._08C->_4 && g_Ball.ballState == 0 && g_Ball.framesSinceHit >= f->_1D2 + 3) {
        g_FieldingLogic._08C->_3 = 0;
        if (g_Ball.AtBat_ContactResult == 0 && g_Ball.maxYOfHit > 5.0f) {
            if (g_Ball.framesUntilBallHitsGround < lbl_3_data_4924[0] && g_Ball.framesUntilBallHitsGround > 20) {
                f32 dist = f->_050 * (g_Ball.framesUntilBallHitsGround - 1);

                if (!(dist - 1.0f > f->_080) &&
                    !(f->_184 > 0 && f->_068 < 1.0f &&
                      g_Ball.physicsSubstruct.futureCoordsAndDist[f->_184].pos.y <= f->_0F4)) {
                    if (fielder <= 5) {
                        g_FieldingLogic._08C->_2 = 2;
                    } else {
                        g_FieldingLogic._08C->_2 = 2;
                        g_FieldingLogic._08C->_3 = 1;
                    }
                }
            }
        } else if (fielder >= 2 && fielder <= 5) {
            if (f->_07C < f->_0E8) {
                f32 reach = f->_070 - 1.0f;

                if (!(g_Ball.ballDistanceFromHome > reach)) {
                    for (i = 6; i <= 30; i += 2) {
                        if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].dist > reach) {
                            break;
                        }
                    }
                    if (i <= 30 && g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y > f->_0F4) {
                        g_FieldingLogic._08C->_2 = 2;
                        if (f->_203 == 0 && g_FieldingLogic._08C->_2 != 0 && f->_25A == 0) {
                            fn_3_2F7D4(fielder);
                            g_FieldingLogic._08C->_2 = 0;
                        }
                    }
                }
            } else {
                g_FieldingLogic._08C->_2 = 2;
            }
        }
    }
}

// .text:0x00057488 size:0x22C mapped:0x8069651C
void fn_3_57488(void) {
    s32 idx = g_FieldingLogic._0B0;
    UnkAC8Fielder* f;
    f32 len;

    if (g_d_GameSettings.minigamesEnabled) {
        idx = g_Minigame.minigameRelatedIndex;
    }
    f = &g_Fielders[idx];
    if (g_AiLogic._78 == 0 && g_Ball.ballState != 3) {
        if (g_Ball.ballState == 0) {
            if (g_Ball.hitWallInd || g_Ball.ballStoppingCode1ReallySlow2Stopped) {
                goto reset;
            }
            if (g_FieldingLogic._0B0 >= 6 || g_d_GameSettings.minigamesEnabled) {
                len = dolsqrtf2(f->_020 * f->_020 + f->_024 * f->_024);
                if (len > 10.0f && g_Ball.ballDistanceFromHome > len) {
                    goto reset;
                }
            }
        }
        if (f->_020 > 1000.0f) {
            fn_3_43038(g_FieldingLogic._0B0);
            f->_020 = f->_014;
            f->_024 = f->_01C;
        }
        return;
    }
reset:
    g_AiLogic._78 = 1;
    f->_020 = g_Ball.physicsSubstruct.futureCoordsAndDist[15].pos.x;
    f->_024 = g_Ball.physicsSubstruct.futureCoordsAndDist[15].pos.z;
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
    s32 i;

    if (g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam]) {
        fn_3_41D78();
    }
    if (g_Strikes.outs >= 3 && g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
        for (i = 0; i < 9; i++) {
            if (g_Fielders[i]._1D3 != 17 && (g_Ball.fielderWBallIndex != i || g_FieldingLogic._116 == 0) &&
                g_Fielders[i]._200 == 0) {
                fn_3_5985C(i, 17);
            }
        }
    }
    if (g_Ball._1BDF >= 1 && g_Ball._1BDF <= 4) {
        for (i = 0; i < 9; i++) {
            fn_3_5985C(i, 0);
        }
    } else if (g_Ball.deadBallReason != 0) {
        for (i = 0; i < 9; i++) {
            if (!(!(g_Ball._1BDF >= 1 && g_Ball._1BDF <= 4) && g_Fielders[i]._1D3 == 15 && g_Ball.deadBallReason != 0) &&
                g_Fielders[i]._1D3 != 12 && g_Fielders[i]._252 == 0) {
                fn_3_5985C(i, 12);
            }
        }
    }
    if (g_FieldingLogic._0C6 >= 0) {
        if (g_FieldingLogic._0C8 < 0x7FFE) {
            g_FieldingLogic._0C8++;
        } else {
            g_FieldingLogic._0C8 = 0x7FFF;
        }
        if (g_FieldingLogic._0C8 > 30) {
            g_FieldingLogic._0C6 = -1;
            g_FieldingLogic._0C8 = 0;
        }
    }
    if (g_FieldingLogic._0C4 >= 0) {
        if (g_Ball.ballState == 2) {
            g_FieldingLogic._0F0 = 0;
        } else if (g_FieldingLogic._0F0 < 0x7FFE) {
            g_FieldingLogic._0F0++;
        } else {
            g_FieldingLogic._0F0 = 0x7FFF;
        }
    } else {
        g_FieldingLogic._0F0 = 0;
    }
    if (g_FieldingLogic._12B) {
        if (g_Ball.fielderWBallIndex < 0) {
            g_FieldingLogic._12B = 0;
        } else if (g_Fielders[g_Ball.fielderWBallIndex]._1F5 >= 0) {
            g_FieldingLogic._12B = 0;
        } else {
            g_FieldingLogic._12B--;
        }
    }
    for (i = 0; i < 9; i++) {
        g_Fielders[i]._192 = 15;
    }
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
static inline SND_VOICEID playStadiumSound(s32 stadium, s32 sound) {
    SND_VOICEID voice;
    u8 vol;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][0];
    } else {
        vol = lbl_3_data_8404[stadium][sound][0];
    }
    voice = sndFXStartEx(lbl_3_data_81DC[stadium] + sound, vol, 63, 0);
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][1];
    } else {
        vol = lbl_3_data_8404[stadium][sound][1];
    }
    sndFXCtrl(voice, 91, vol);
    return voice;
}

void fn_3_544B8(void) {
    UnkAC8Fielder* f;
    u32 kind;
    s32 type;
    s32 i;
    VecSrcDst ray;
    CollisionStruct hit;
    VecXYZ pos;
    VecXYZ prev;
    f32 h;
    f32 v;

    for (i = 0; i < 9; i++) {
        f = &g_Fielders[i];
        if (g_d_GameSettings.minigamesEnabled && g_Minigame.minigameRelatedIndex != i) {
            continue;
        }
        if ((g_GameLogic.gameStatus == 1 || g_GameLogic.gameStatus == 2) && f->_0B8 > 6.5f &&
            g_Ball.totalFramesAtPlay > 1 && g_Ball.totalFramesAtPlay < 0x7FFF && i % 3 != g_Ball.totalFramesAtPlay % 3) {
            f->_00C = f->_010;
            type = f->_1E5[1];
        } else {
            ray.src.x = f->_000;
            ray.src.y = -1.0f;
            ray.src.z = f->_008;
            ray.dst.x = f->_000;
            ray.dst.y = 1.0f;
            ray.dst.z = f->_008;
            type = checkCollision(&ray, &hit, 0, 0);
            if (type == 0) {
                f->_00C = 0.0f;
            } else {
                f->_00C = -hit.position.y;
            }
            kind = type & 0x7F;
            if (kind == 10) {
                pos.x = f->_000;
                pos.y = f->_00C;
                pos.z = f->_008;
                prev.x = f->_0D4;
                prev.y = f->_00C;
                prev.z = f->_0D8;
                if (fn_800639BC(i, &pos, &prev) >= 2) {
                    if (g_d_GameSettings.StadiumID == 4) {
                        playStadiumSound(4, 7);
                    } else if (g_d_GameSettings.StadiumID == 5) {
                        playStadiumSound(5, 12);
                    }
                }
            } else {
                fn_80063958(i);
            }
            if (kind == 9) {
                fn_3_16D5E4(i + 1);
            }
            f->_010 = f->_00C;
        }
        if (f->_203) {
            f->_00C += f->_15C;
        }
        if (f->_205) {
            f->_00C = f->_148;
        }
        if (f->_207) {
            f->_00C = f->_148;
        }
        if (f->_252 == 4) {
            f->_00C = f->_148;
            if (f->_25C) {
                f->_25E = 1;
            } else {
                f->_25E = 2;
            }
        } else if (f->_25E != 0) {
            if (f->_25E == 2) {
                f->_25E = 3;
                f->_14C = 0.0f;
                f->_25D = 0;
                h = f->_148;
                v = 0.5f * f->_164;
                do {
                    v -= lbl_3_data_4930[11];
                    h += v;
                    f->_25D++;
                } while (!(h < 0.0f));
                getComponentsFromSAng(f->_180, &f->_150, &f->_158);
                f->_150 *= -lbl_3_data_4930[13];
                f->_158 *= -lbl_3_data_4930[13];
            } else if (f->_25E == 3) {
                f->_25D--;
                f->_14C -= lbl_3_data_4930[11];
                f->_148 += f->_14C;
                if (f->_148 < 0.0f) {
                    f->_148 = 0.0f;
                    f->_25E = 4;
                    f->_25F = lbl_3_data_49DC[4];
                }
            }
            f->_00C = f->_148;
        }
        f->_1E5[1] = type;
    }
}

// .text:0x00053F48 size:0x570 mapped:0x80692FDC
void fn_3_53F48(void) {
    s32 i;
    s32 j;
    UnkAC8Fielder* a;
    UnkAC8Fielder* b;
    s32 pi;
    s32 pj;
    f32 dx;
    f32 dz;
    f32 dx2;
    f32 dz2;
    f32 dist;
    f32 t;
    f32 mx;
    f32 mz;
    f32 nx;
    f32 nz;
    f32 len;
    struct _VecXYZ pos;

    for (i = 0; i < 8; i++) {
        a = &g_Fielders[i];
        if (a->_178 < 0) {
            continue;
        }
        for (j = i + 1; j < 9; j++) {
            b = &g_Fielders[j];
            if (b->_178 < 0) {
                continue;
            }
            dx = b->_000 - a->_000;
            dz = b->_008 - a->_008;
            dx2 = dx * dx;
            dz2 = dz * dz;
            dist = dolsqrtf2(dx2 + dz2);
            if (!(dist < lbl_3_data_476C[a->_1C9] + lbl_3_data_476C[b->_1C9])) {
                continue;
            }
            t = lbl_3_data_476C[a->_1C9] / (lbl_3_data_476C[a->_1C9] + lbl_3_data_476C[b->_1C9]);
            mx = t * (b->_000 - a->_000) + a->_000;
            mz = t * (b->_008 - a->_008) + a->_008;
            nx = mx - a->_000;
            nz = mz - a->_008;
            len = dolsqrtf2(nx * nx + nz * nz);
            if (!(len > 0.0f)) {
                continue;
            }
            nx /= len;
            nz /= len;
            if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_STAR_DASH) {
                pi = g_Minigame.minigameControlStruct._28[i - 2];
                pj = g_Minigame.minigameControlStruct._28[j - 2];
                if (g_Minigame.starDashStunType[pi] != 0 || g_Minigame.starDashStunType[pj] != 0) {
                    continue;
                }
                if (pi == g_Minigame._1D6D) {
                    g_Minigame.starDashStunType[pj] = 1;
                    g_Minigame._1CB8[pj].x = b->_000 - a->_000;
                    g_Minigame._1CB8[pj].z = b->_008 - a->_008;
                    fn_3_13A048(pi, pj);
                    continue;
                }
                if (pj == g_Minigame._1D6D) {
                    g_Minigame.starDashStunType[pi] = 1;
                    g_Minigame._1CB8[pi].x = a->_000 - b->_000;
                    g_Minigame._1CB8[pi].z = a->_008 - b->_008;
                    fn_3_13A048(pj, pi);
                    continue;
                }
            }
            if (a->_050 <= 0.0f) {
                b->_000 = nx * (lbl_3_data_476C[a->_1C9] + lbl_3_data_476C[b->_1C9]) + a->_000;
                b->_008 = nz * (lbl_3_data_476C[a->_1C9] + lbl_3_data_476C[b->_1C9]) + a->_008;
            } else if (b->_050 <= 0.0f) {
                a->_000 = b->_000 - nx * (lbl_3_data_476C[a->_1C9] + lbl_3_data_476C[b->_1C9]);
                a->_008 = b->_008 - nz * (lbl_3_data_476C[a->_1C9] + lbl_3_data_476C[b->_1C9]);
            } else {
                a->_000 = mx - nx * lbl_3_data_476C[a->_1C9];
                a->_008 = mz - nz * lbl_3_data_476C[a->_1C9];
                b->_000 = nx * lbl_3_data_476C[b->_1C9] + mx;
                b->_008 = nz * lbl_3_data_476C[b->_1C9] + mz;
            }
            if (fn_3_51798(i, &pos)) {
                a->_000 = a->_0D4;
                a->_008 = a->_0D8;
            }
            if (fn_3_51798(j, &pos)) {
                b->_000 = b->_0D4;
                b->_008 = b->_0D8;
            }
        }
    }
}

// .text:0x00053EE8 size:0x60 mapped:0x80692F7C
void fn_3_53EE8(s32 fielder) {
    fn_3_5985C(fielder, 0x13);
}

// .text:0x0005372C size:0x7BC mapped:0x806927C0
void fn_3_5372C(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dx;
    f32 dz;
    f32 dx2;
    f32 dz2;
    f32 dist;
    s32 i;

    if (f->_18C >= 0 && f->_18C <= 3) {
        dx = lbl_3_data_4444[f->_18C].x - f->_000;
        dz = lbl_3_data_4444[f->_18C].z - f->_008;
        dx2 = dx * dx;
        dz2 = dz * dz;
        dist = dolsqrtf2(dx2 + dz2);
        if (lbl_3_data_4780[f->_1C9] > dist) {
            g_FieldingLogic._101[f->_18C] = 1;
            f->_1F5 = f->_18C;
            if (fielder == 0 && f->_1D8[0] == 1) {
                f->_1D8[0] = 0;
            }
        }
        if (g_Ball.fielderWBallIndex == fielder) {
            s16 other = g_FieldingLogic._0D0[f->_18C];

            if (other != fielder && other >= 0 && g_FieldingLogic._101[f->_18C] != 0) {
                fn_3_4B8D0(fielder);
            }
        }
    } else if (g_Ball.fielderWBallIndex == fielder) {
        for (i = 0; i < 4; i++) {
            dx = lbl_3_data_4444[i].x - f->_000;
            dz = lbl_3_data_4444[i].z - f->_008;
            dx2 = dx * dx;
            dz2 = dz * dz;
            dist = dolsqrtf2(dx2 + dz2);
            if (lbl_3_data_4780[f->_1C9] > dist) {
                fn_3_4B8D0(g_FieldingLogic._0D0[i]);
                f->_18C = i;
                g_FieldingLogic._0D0[i] = fielder;
                f->_1D7 = 1;
                g_FieldingLogic._101[i] = 1;
                break;
            }
        }
    }
    if (f->_1F5 >= 0) {
        dx = lbl_3_data_4444[f->_1F5].x - f->_000;
        dz = lbl_3_data_4444[f->_1F5].z - f->_008;
        dx2 = dx * dx;
        dz2 = dz * dz;
        dist = dolsqrtf2(dx2 + dz2);
        if (g_Ball.fielderWBallIndex == fielder) {
            if (0.4f + lbl_3_data_4780[f->_1C9] < dist) {
                f->_1F5 = -1;
            }
        } else if (0.8f + lbl_3_data_4780[f->_1C9] < dist) {
            f->_1F5 = -1;
        }
    }
    if (f->_203 != 0) {
        f->_1F5 = -1;
    }
    if (f->_1F5 < 0) {
        for (i = 0; i < 4; i++) {
            if (g_FieldingLogic._0D0[i] == fielder) {
                g_FieldingLogic._101[i] = 0;
                break;
            }
        }
    }
}

// .text:0x00053130 size:0x5FC mapped:0x806921C4
s32 fn_3_53130(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    UnkAC8Actor* actor = lbl_8036E548.actors[9];
    s32 idx;

    if (g_d_GameSettings.minigamesEnabled) {
        idx = g_Minigame.minigameControlStruct._28[fielder - 2];
        actor = lbl_8036E548.actors[idx];
    }
    if (f->_1D3 == 12 && actor != NULL && actor->_62 >= 17 && actor->_62 <= 28) {
        return 2;
    }
    if (f->_20F) {
        fn_3_25648(fielder);
        return 2;
    }
    if (f->_210) {
        fn_3_251E4(fielder);
        return 2;
    }
    if (f->_211) {
        fn_3_A96FC(fielder);
        return 2;
    }
    if (f->_252 == 0 && f->_25B != 0) {
        if (f->_25A == 2 && f->_1ED != 0) {
            return 2;
        }
        f->_25B = 0;
    } else if (f->_25A == 2 && f->_1ED != 0) {
        return 2;
    }
    if (f->_252 == 0 && f->_262 != 0) {
        fn_3_25A68(fielder);
        return 2;
    }
    if (g_Ball._1BDF) {
        return 2;
    }
    if (f->_25E >= 3) {
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
        return 1;
    }
    if (f->_205) {
        fn_3_300B8(fielder);
        return 1;
    }
    if (f->_207) {
        fn_3_2F924(fielder);
        return 1;
    }
    if (f->_203) {
        fn_3_2F574(fielder);
        return 1;
    }
    if (f->_1EE) {
        return 2;
    }
    if (f->_1EF) {
        return 2;
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_PIRANHA_PANIC) {
        if (g_Minigame._1C9A_arr[idx]) {
            return 2;
        }
    } else if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_STAR_DASH &&
               (g_Minigame.starDashStunType[idx] == 1 || g_Minigame.starDashStunType[idx] == 2)) {
        return 2;
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_PIRANHA_PANIC || g_Minigame.GameMode_MiniGame == MINI_GAME_ID_STAR_DASH) {
        return 0;
    }
    return g_Ball.framesSinceHit < f->_1D2;
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
    UnkAC8Fielder* f = &g_Fielders[fielder];
    struct _VecXYZ pos;
    f32 dx;
    f32 dz;
    f32 dx2;
    f32 dz2;
    f32 speed;

    if (f->_1ED != 0) {
        f->_1E3 = 1;
        return;
    }
    if (f->_1FD[0] != 0) {
        f->_1E3 = 1;
        return;
    }
    if (f->_252 != 0) {
        fn_3_261E8(fielder);
        f->_1A2 = 0;
        return;
    }
    if (f->_068 > 0.0f) {
        s32 angle = radToShortAngle(f->_064);
        fn_3_9FCF8(angle, radToShortAngle(f->_0BC[0]));
        if (!g_d_GameSettings.minigamesEnabled || f->_1C5 == 0) {
            if (f->_1C5 != 0 && (f->_1D3 == 2 || f->_1D3 == 18) && (f->_1DC == 4 || f->_1DC == 5)) {
                f->_1E3 = 0;
                goto speed_by_step;
            }
            if (fielder == g_Ball.fielderWBallIndex && g_FieldingLogic._0DE >= 0 &&
                (g_FieldingLogic._111 == 2 || g_FieldingLogic._111 == 3 || g_FieldingLogic._111 == 4) &&
                g_FieldingLogic._112 == 1) {
                f->_1E3 = 0;
                dx = g_Runners[g_FieldingLogic._0DE].position.x - f->_000;
                dz = g_Runners[g_FieldingLogic._0DE].position.z - f->_008;
                speed = dolsqrtf2(dx * dx + dz * dz) - 1.2f;
                if (g_FieldingLogic._111 == 4) {
                    speed *= 0.5f;
                    if (g_FieldingLogic._0EC > 0) {
                        speed /= g_FieldingLogic._0EC;
                    }
                    f->_050 = speed;
                } else {
                    if (speed < 0.0f) {
                        speed = 0.0f;
                    }
                    if (g_FieldingLogic._0EC > 0) {
                        f->_050 = speed / g_FieldingLogic._0EC;
                    } else {
                        f->_050 = speed;
                    }
                }
                goto clamp;
            }
        }
        if (g_FieldingLogic._0F8[fielder] == 11 && f->_1D6 >= 1 && f->_1D6 <= 9) {
            if (f->_050 < 0.01f) {
                f->_1E3 = 0;
                f->_1E4 = 0;
                f->_1A2 = 0;
            } else {
                if (f->_1A2 > 45) {
                    f->_1A2 = 45;
                }
                if (f->_1A2 != 0) {
                    f->_1A2--;
                }
            }
        } else {
            f->_1E3 = 0;
            f->_1E4 = 0;
            if (f->_1A2 < 0x7FFE) {
                f->_1A2++;
            } else {
                f->_1A2 = 0x7FFF;
            }
        }
    } else {
        f->_1E3 = 1;
        if (f->_1A2 > 45) {
            f->_1A2 = 45;
        }
        if (f->_1A2 != 0) {
            f->_1A2--;
        }
    }
speed_by_step:
    switch (f->_1D6) {
    case 0:
        fn_3_3A234(fielder);
        break;
    case 1:
    case 5:
        f->_050 -= 0.0005f;
        break;
    case 2:
    case 6:
        f->_050 -= 0.001f;
        break;
    case 3:
    case 7:
        f->_050 -= 0.002f;
        break;
    case 4:
    case 8:
        f->_050 -= 0.003f;
        break;
    case 9:
        f->_050 = 0.0f;
        break;
    case 10:
        f->_050 = 0.07f;
        break;
    case 11:
        f->_050 = 0.1f;
        break;
    case 12:
        f->_050 = 0.03f;
        break;
    case 13:
        f->_050 = 0.25f;
        break;
    }
clamp:
    if (f->_1D6 < 5 && f->_1D6 >= 1 && f->_050 < 0.03f) {
        f->_050 = 0.03f;
    }
    if (f->_050 <= 0.0f) {
        f->_050 = 0.0f;
    }
    f->_068 -= f->_050;
    dx = f->_000 - f->_014;
    dz = f->_008 - f->_01C;
    dx2 = dx * dx;
    dz2 = dz * dz;
    if (dolsqrtf2(dx2 + dz2) < f->_050) {
        f->_068 = -1.0f;
    }
    if (!(f->_050 <= 0.0f)) {
        if (f->_068 < 0.0f) {
            f->_068 = 0.0f;
            f->_030 = f->_014 - f->_000;
            f->_034 = f->_01C - f->_008;
            if (fn_3_51798(fielder, &pos) == 0) {
                if (f->_1D6 >= 1 && f->_1D6 <= 8) {
                    f->_014 = f->_000;
                    f->_01C = f->_008;
                } else {
                    f->_000 = f->_014;
                    f->_008 = f->_01C;
                }
            }
            fn_3_530EC(fielder);
        } else {
            f->_030 = f->_050 * (f32)cos(f->_064);
            f->_034 = f->_050 * (f32)sin(f->_064);
            if (fn_3_51798(fielder, &pos)) {
                fn_3_530EC(fielder);
            } else {
                f->_000 += f->_030;
                f->_008 += f->_034;
                f->_064 = atan2(f->_01C - f->_008, f->_014 - f->_000);
            }
        }
    }
    if (f->_050 == 0.0f && f->_1E4 == 0) {
        f->_1E3 = 1;
    }
    f->_1F0 = 1;
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
    UnkAC8Fielder* f = &g_Fielders[fielder];
    VecSrcDst ray;
    CollisionStruct hit;
    u32 type;
    f32 ox;
    f32 oz;
    f32 dirX;
    f32 dirZ;
    f32 nx;
    f32 nz;
    f32 len;
    f32 reach;
    f32 dist;
    f32 ang;
    f32 dx;
    f32 dz;
    f32 dx2;
    f32 dz2;

    if (f->_050 == 0.0f) {
        return 0;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD && g_GameLogic.gameStatus == 1) {
        u32 ret = fn_3_5164C(fielder, delta);
        if (ret != 0) {
            return ret;
        }
    }
    if (!g_d_GameSettings.minigamesEnabled && f->_0A8[0] < 70.0f && !fn_3_B7E10(f->_000, f->_008)) {
        return 0;
    }
    if (f->_1FB != 0) {
        return 0;
    }
    if (fn_3_B7E10(f->_000, f->_008) || g_Minigame.GameMode_MiniGame == MINI_GAME_ID_STAR_DASH ||
        g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        ray.src.x = ray.dst.x = f->_000 + f->_030;
        ray.src.z = ray.dst.z = f->_008 + f->_034;
        ray.src.y = -5.0f;
        ray.dst.y = 10.0f;
        type = checkCollision(&ray, &hit, 0, 0) & 0x7F;
        if (!(type != 2 && type != 3 && type != 7 && type != 8 && type != 5)) {
            return 1;
        }
        if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_STAR_DASH && fn_3_1379A0(fielder)) {
            memcpy(delta, f, sizeof(VecXYZ));
            return 1;
        }
    }
    dirX = f->_030 / f->_050;
    dirZ = f->_034 / f->_050;
    ray.src.x = f->_000;
    ray.src.y = -0.5f;
    ray.src.z = f->_008;
    ray.dst.y = -0.5f;
    ray.dst.x = f->_000 + dirX;
    ray.dst.z = f->_008 + dirZ;
    type = checkCollision(&ray, &hit, 0, 0) & 0x7F;
    if (type != 2 && type != 5) {
        return 0;
    }
    len = dolsqrtf2(hit.normal.x * hit.normal.x + hit.normal.z * hit.normal.z);
    nx = hit.normal.x / len;
    nz = hit.normal.z / len;
    ox = nx * lbl_3_data_476C[f->_1C9];
    oz = nz * lbl_3_data_476C[f->_1C9];
    ang = game_atan2(-ox, -oz);
    reach = lbl_3_data_476C[f->_1C9] / (f32)cos(fn_3_9FEA8(ang - game_atan2(dirX, dirZ)));
    if (f->_25A == 2) {
        reach = lbl_3_data_7F10[f->_17A];
    }
    dx = f->_000 - hit.position.x;
    dz = f->_008 - hit.position.z;
    dx2 = dx * dx;
    dz2 = dz * dz;
    dist = dolsqrtf2(dx2 + dz2);
    if (dist < reach) {
        ray.dst.x = f->_000 + f->_030;
        ray.dst.z = f->_008 + f->_034;
        ray.src.x = ray.dst.x + 3.0f * nx;
        ray.src.z = ray.dst.z + 3.0f * nz;
        ray.dst.x = ray.dst.x - 3.0f * nx;
        ray.dst.z = ray.dst.z - 3.0f * nz;
        type = checkCollision(&ray, &hit, 1, 0);
        if (type != 0) {
            delta->x = ox * lbl_3_data_476C[f->_1C9] + hit.position.x;
            delta->z = oz * lbl_3_data_476C[f->_1C9] + hit.position.z;
            return 2;
        }
        return 1;
    }
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
// 96.70%: in the speed-ratio update the target loads the int-to-float constant through an
// `addi` and lbl_3_data_4B98 before 1.0f; the operands of the `fmadds` follow from that.
void fn_3_51220(void) {
    if (g_FieldingLogic._070->_1A != 0) {
        if (g_FieldingLogic._070->_0C < 0x7FFE) {
            g_FieldingLogic._070->_0C++;
        } else {
            g_FieldingLogic._070->_0C = 0x7FFF;
        }
        if (g_FieldingLogic._070->_0E < 0x7FFE) {
            g_FieldingLogic._070->_0E++;
        } else {
            g_FieldingLogic._070->_0E = 0x7FFF;
        }
        g_FieldingLogic._070->_12++;
        if (g_FieldingLogic._070->_1A == 4 || g_FieldingLogic._070->_1A == 3) {
            g_FieldingLogic._070->_18--;
            if (g_FieldingLogic._070->_18 == 0) {
                g_FieldingLogic._070->_1A = 0;
                g_FieldingLogic._070->_0C = -1;
                g_FieldingLogic._070->_0E = -1;
                g_FieldingLogic._070->_14 = -1;
                g_FieldingLogic._070->_08 = 1.0f;
                return;
            }
            g_FieldingLogic._070->_08 = (g_FieldingLogic._070->_08 - 1.0f) * (1.0f - 1.0f / g_FieldingLogic._070->_18);
            g_FieldingLogic._070->_08 += 1.0f;
            return;
        }
        if (g_FieldingLogic._070->_0C == 1) {
            g_FieldingLogic._070->_16++;
            g_FieldingLogic._070->_10 += lbl_3_data_4B9C[0];
            if (g_FieldingLogic._070->_10 >= lbl_3_data_4B9C[1]) {
                g_FieldingLogic._070->_10 = lbl_3_data_4B9C[1];
                g_FieldingLogic._070->_1A = 2;
                if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE || g_Practice.practiceType_2 == 2 ||
                    g_Practice.practiceLevel == 2) {
                    g_Practice._1CB = 1;
                }
            }
        } else if (g_FieldingLogic._070->_0C >= lbl_3_data_4B9C[2]) {
            UnkAC8Fielder* f = &g_Fielders[g_FieldingLogic._070->_14];

            if (f->_19E == -1) {
                g_FieldingLogic._070->_1A = 4;
                g_FieldingLogic._070->_18 = lbl_3_data_4B9C[4];
                g_FieldingLogic._070->_00 = f->_038;
                g_FieldingLogic._070->_04 = f->_03C;
                return;
            }
            g_FieldingLogic._070->_1A = 3;
            g_FieldingLogic._070->_18 = lbl_3_data_4B9C[5];
            return;
        }
        g_FieldingLogic._070->_08 = (f32)g_FieldingLogic._070->_10 / lbl_3_data_4B9C[1] * lbl_3_data_4B98 + 1.0f;
        return;
    }
    if (g_FieldingLogic._070->_0C >= 0) {
        if (g_FieldingLogic._070->_0E < 0) {
            g_FieldingLogic._070->_0E = 0;
            g_FieldingLogic._070->_10 = 0;
            g_FieldingLogic._070->_14 = -1;
            g_FieldingLogic._070->_16 = 0;
        }
        if (g_FieldingLogic._070->_0C < 0x7FFE) {
            g_FieldingLogic._070->_0C++;
        } else {
            g_FieldingLogic._070->_0C = 0x7FFF;
        }
        if (g_FieldingLogic._070->_0E < 0x7FFE) {
            g_FieldingLogic._070->_0E++;
        } else {
            g_FieldingLogic._070->_0E = 0x7FFF;
        }
        if (g_FieldingLogic._070->_0C >= lbl_3_data_4B9C[2]) {
            g_FieldingLogic._070->_0C = -1;
            g_FieldingLogic._070->_0E = -1;
            g_FieldingLogic._070->_14 = -1;
            return;
        }
        if (g_FieldingLogic._070->_0C == 1) {
            g_FieldingLogic._070->_16++;
        }
        if (g_FieldingLogic._070->_16 >= lbl_3_data_4B9C[3]) {
            if (g_d_GameSettings.minigamesEnabled) {
                g_FieldingLogic._070->_14 = g_Minigame.minigameRelatedIndex;
            } else {
                g_FieldingLogic._070->_14 = g_FieldingLogic._0B0;
            }
            g_FieldingLogic._070->_12 = 0;
            g_FieldingLogic._070->_1A = 1;
            g_FieldingLogic._070->_08 = 1.0f;
            g_FieldingLogic._070->_0C = -1;
            g_FieldingLogic._070->_10 = lbl_3_data_4B9C[0];
        }
    }
}

// .text:0x00050DD8 size:0x448 mapped:0x8068FE6C
s32 fn_3_50DD8(s32 fielder, f32* outX, f32* outZ, BOOL update) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 x;
    f32 z;

    if (g_d_GameSettings.minigamesEnabled) {
        return 0;
    }
    if (fielder == 0 || fielder == 1 || fielder == 2 || fielder == 4) {
        return 0;
    }
    if (g_Ball.someCollisionInd) {
        f->_18A = 0;
        return 0;
    }
    if (!update) {
        f32 dx;
        f32 dz;
        f32 dx2;
        f32 dz2;

        f->_028 = *outX;
        f->_02C = *outZ;
        dx = f->_000 - f->_028;
        dz = f->_008 - f->_02C;
        dx2 = dx * dx;
        dz2 = dz * dz;
        if (dolsqrtf2(dx2 + dz2) < lbl_3_data_4930[31]) {
            return 0;
        }
        if (fn_3_50898(fielder, &x, &z)) {
            *outX = x;
            *outZ = z;
        }
        f->_18A = 1;
        f->_188 = 30;
    } else if (f->_20E == 0) {
        if (f->_18A > lbl_3_data_48A4[2][f->_1C4]) {
            f->_20E = 1;
        } else {
            f32 dx = f->_020 - f->_000;
            f32 dz = f->_024 - f->_008;
            f32 dx2 = dx * dx;
            f32 dz2 = dz * dz;

            if (dolsqrtf2(dx2 + dz2) < lbl_3_data_4930[32]) {
                f->_20E = 1;
            }
        }
        *outX = f->_020;
        *outZ = f->_024;
    } else {
        x = f->_028 - f->_020;
        z = f->_02C - f->_024;
        f->_188--;
        if (f->_188 <= 0) {
            *outX = f->_028;
            *outZ = f->_02C;
            f->_18A = 0;
        } else {
            f32 inv = 1.0f / f->_188;

            x *= inv;
            z *= inv;
            *outX = f->_020 + x;
            *outZ = f->_024 + z;
        }
    }
    return 1;
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
s32 fn_3_50898(s32 fielder, f32* x, f32* z) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 frame = f->_186 - g_Ball.framesSinceHit + 1;
    s16 angle = fn_3_9FB8C(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                           g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z);
    s32 i;

    if (fn_3_9FCF8(angle, f->_180) < lbl_3_data_49DC[27]) {
        return 0;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        goto toyField;
    }
    if (fielder <= 5) {
        if ((fielder == 3 && angle > f->_180) || (fielder == 5 && angle < f->_180)) {
            *x = f->_028;
            *z = f->_008;
            return 1;
        }
        i = frame + lbl_3_data_48A4[0][f->_1C4];
        *x = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x;
        *z = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z;
    } else if (fielder == 7) {
    toyField:
        for (i = 60; i < 240; i += 5) {
            if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z > f->_008) {
                break;
            }
        }
        if (i >= 240) {
            return 0;
        }
        *x = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x;
        *z = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z;
    } else if ((fielder == 6 && f->_180 > angle) || (fielder == 8 && f->_180 < angle)) {
        for (i = 60; i < 240; i += 5) {
            if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].dist > f->_070) {
                break;
            }
        }
        if (i >= 240) {
            return 0;
        }
        *x = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x;
        *z = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z;
    } else {
        i = frame + lbl_3_data_48A4[1][f->_1C4];
        *x = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x;
        *z = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z;
    }
    return 1;
}

// .text:0x0004FB34 size:0xD64 mapped:0x8068EBC8
void fn_3_4FB34(void) {
    return;
}

// .text:0x0004F504 size:0x630 mapped:0x8068E598
// 99.89%: as in fn_3_4EFC8, the inlined fn_3_52560 takes dx and dz in each other's float
// registers, and the last test's two sums compare in swapped registers.
void fn_3_4F504(int fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 i;
    s32 start;
    s32 frames;
    s32 catchFrame;
    s32 prevCatch = 9999;
    s32 arrive;
    s32 bestIdx = 0;
    s32 found = 0;
    s32 close = 0;
    s32 result = 0;
    f32 y;
    f32 bestY = 99.0f;

    start = f->_1D2 - g_Ball.framesSinceHit;
    if (start < 1) {
        start = 1;
    }
    i = start;
    while (i < 360) {
        if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y > 4.5f) {
            i += 3;
            continue;
        }
        frames = fn_3_52560(fielder, g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x,
                            g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z);
        catchFrame = start + frames - 5;
        if (catchFrame < i) {
            y = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y;
            if (y < 2.0f) {
                result = 1;
                break;
            }
            if (found && bestY < y) {
                i = bestIdx;
                result = 2;
                break;
            }
            bestY = y;
            bestIdx = i;
            found = 1;
        } else {
            if (catchFrame < i + 30) {
                close = 1;
            }
            if (found) {
                i = bestIdx;
                result = 2;
                break;
            }
        }
        if (catchFrame > prevCatch && !found &&
            dolsqrtf2(SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x) +
                      SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z)) > 10.0f) {
            result = 3;
            break;
        }
        prevCatch = catchFrame;
        i++;
    }
    if (i >= 360) {
        i = 359;
    }
    f->_186 = i;
    if (result == 2 && g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y < 2.0f) {
        result = 1;
    }
    if (result == 3 && !close) {
        result = 4;
    }
    f->_1DD = result;
    f->_1DA = 0;
    if (result != 1 && result != 2) {
        f->_1DA = 1;
    }
    if (dolsqrtf2(SQ(g_Ball.landingSpotLocation.x - g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x) +
                  SQ(g_Ball.landingSpotLocation.z - g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z)) < 3.0f &&
        result == 1) {
        f->_1DB = 0;
    } else {
        f->_1DB = 1;
    }
    if (f->_1DB == 0) {
        if (catchFrame + 30 < f->_186) {
            g_FieldingLogic._0F2 |= 1 << fielder;
        }
    } else if (result == 1) {
        arrive = f->_186 + fn_3_A6810(g_Ball.physicsSubstruct.futureCoordsAndDist[f->_186].pos.x,
                                      g_Ball.physicsSubstruct.futureCoordsAndDist[f->_186].pos.z, lbl_3_data_4444[1].x,
                                      lbl_3_data_4444[1].z);
        if (arrive + 60 < g_RunningLogic._0E + 30) {
            g_FieldingLogic._0F2 |= 1 << fielder;
        }
    }
}

// .text:0x0004EFC8 size:0x53C mapped:0x8068E05C
// 99.87%: registers only; the inlined fn_3_52560 takes dx and dz in each other's float
// registers (as in fn_3_43038), and the last test's two sums swap r0 and r3.
void fn_3_4EFC8(int fielder, BOOL flag) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 i;
    s32 start;
    s32 frames;
    s32 catchFrame;
    s32 arrive;
    s32 half;
    s32 bestIdx = 0;
    s32 found = 0;
    s32 close = 0;
    s32 result = 0;
    f32 speed;
    f32 dist;
    f32 dz;
    f32 dx;
    f32 z;
    f32 x;
    f32 y;
    f32 bestY = 99.0f;

    start = f->_1D2 - g_Ball.framesSinceHit;
    if (start < 1) {
        start = 1;
    }
    i = start;
    while (i < 360) {
        if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y > 4.5f) {
            i += 3;
            continue;
        }
        frames = fn_3_52560(fielder, g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x,
                            g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z);
        catchFrame = start + frames - 5;
        if (catchFrame < i) {
            y = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y;
            if (y < 2.0f) {
                result = 1;
                break;
            }
            if (found && bestY < y) {
                i = bestIdx;
                result = 2;
                break;
            }
            bestY = y;
            bestIdx = i;
            found = 1;
        } else {
            if (catchFrame < i + 30) {
                close = 1;
            }
            if (found) {
                if (!flag) {
                    result = 2;
                    i = g_Ball.framesUntilBallHitsGround;
                } else {
                    i = bestIdx;
                    result = 2;
                }
                break;
            }
        }
        i++;
    }
    if (i >= 360) {
        i = 359;
    }
    f->_186 = i + g_Ball.framesSinceHit;
    if (result == 2 && g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y < 2.0f) {
        result = 1;
    }
    if (result == 3 && !close) {
        result = 4;
    }
    f->_1DD = result;
    f->_1DA = 0;
    if (result != 1 && result != 2) {
        f->_1DA = 1;
    }
    if (dolsqrtf2(SQ(g_Ball.landingSpotLocation.x - g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x) +
                  SQ(g_Ball.landingSpotLocation.z - g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z)) < 3.0f &&
        result == 1) {
        f->_1DB = 0;
    } else {
        f->_1DB = 1;
    }
    if (f->_1DB == 0) {
        if (catchFrame + 30 < f->_186) {
            g_FieldingLogic._0F2 |= 1 << fielder;
        }
    } else if (result == 1) {
        arrive = f->_186 + fn_3_A6810(g_Ball.physicsSubstruct.futureCoordsAndDist[f->_186].pos.x,
                                      g_Ball.physicsSubstruct.futureCoordsAndDist[f->_186].pos.z, lbl_3_data_4444[1].x,
                                      lbl_3_data_4444[1].z);
        if (arrive + 60 < g_RunningLogic._0E + 30) {
            g_FieldingLogic._0F2 |= 1 << fielder;
        }
    }
}

// .text:0x0004EBC4 size:0x404 mapped:0x8068DC58
// 99.10%: the target tests the frame count with `extsh.` and then copies it with an extra
// `mr r6,r31`, one instruction this lacks.
void fn_3_4EBC4(void) {
    s32 frames;
    s32 best = -1;
    s16 bestFrames = 9999;
    s16 nextFrames = 9999;
    BOOL high = FALSE;
    s32 i;
    s32 j;
    BOOL waiting;

    if (g_FieldingLogic._0C4 >= 0) {
        g_Ball.fielderAboutToGetBall_hasBall = -1;
        return;
    }
    if (g_Ball.fielderAboutToGetBall_hasBall < 0 &&
        (g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow <= 0 || g_Ball.matchFramesAndBallAngle.framesAfterReceivingThrow >= 25)) {
        frames = -1;
        if (g_Ball.ballZoneAwayFromHome <= 1 && g_Ball.maxYOfHit <= 3.0f) {
            high = TRUE;
        }
        for (i = 0; i < 9; i++) {
            if (g_FieldingLogic._0F8[i] != 1) {
                continue;
            }
            if (g_Fielders[i]._17E == -1 && g_Ball.fielderAboutToGetBall_hasBall == i) {
                g_Ball.fielderAboutToGetBall_hasBall = -1;
                continue;
            }
            if (g_Fielders[i]._1DD == 1 && i <= 5 && g_Fielders[i]._080 > 5.0f) {
                high = TRUE;
                continue;
            }
            if (i < 6 || !high) {
                frames = g_Fielders[i]._17E;
                if (frames >= 0) {
                    if (g_Fielders[i]._19C != 0) {
                        frames = g_Fielders[i]._17E + 60;
                    } else if (g_Fielders[i]._1ED) {
                        frames = g_Fielders[i]._17E + 60;
                    }
                    if (i == 0 && g_Fielders[i]._1DD == 1 && g_Fielders[i]._080 > g_Fielders[i]._070) {
                        frames += 30;
                    }
                    if (frames < bestFrames) {
                        best = i;
                        bestFrames = frames;
                    } else if (frames < nextFrames) {
                        nextFrames = frames;
                    }
                }
            } else {
                break;
            }
        }
        if (best >= 0) {
            if (g_Fielders[best]._1DD == 1 && bestFrames < 60) {
                if (bestFrames + 60 < nextFrames) {
                    g_Ball.fielderAboutToGetBall_hasBall = best;
                }
                if (bestFrames < 30) {
                    g_Ball.fielderAboutToGetBall_hasBall = best;
                }
                if (g_Ball.AtBat_ContactResult == 0) {
                    if (g_Fielders[best]._1DB == 0) {
                        g_Ball.fielderAboutToGetBall_hasBall = best;
                    } else if (frames == best) {
                        g_Ball.fielderAboutToGetBall_hasBall = best;
                    }
                } else {
                    g_Ball.fielderAboutToGetBall_hasBall = best;
                }
            }
            if (g_Fielders[best]._1DC == 4 && bestFrames < 60) {
                g_Ball.fielderAboutToGetBall_hasBall = best;
            }
            if (g_Fielders[best]._1DC == 2 && bestFrames < 30) {
                waiting = FALSE;
                for (j = 0; j < 9; j++) {
                    if (g_FieldingLogic._0F8[j] == 1) {
                        if (g_Fielders[j]._1DD == 0) {
                            waiting = TRUE;
                            break;
                        } else if (g_Fielders[j]._1DB == 0) {
                            waiting = TRUE;
                            break;
                        } else if (g_Fielders[j]._1DC == 0 || g_Fielders[j]._1DC == 1) {
                            waiting = TRUE;
                            break;
                        }
                    }
                }
                if (!waiting) {
                    g_Ball.fielderAboutToGetBall_hasBall = best;
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

// .text:0x0004E638 size:0x58C mapped:0x8068D6CC
void fn_3_4E638(void) {
    UnkAC8Fielder* f = &g_Fielders[g_Ball.fielderBeingThrownTo];
    f32 traveled;
    f32 throwLen;
    f32 ballLen;
    s16 throwAngle;
    s32 diff;

    if (g_Ball.fielderBeingThrownTo < 0) {
        return;
    }
    traveled = dolsqrtf2(SQ(g_Ball.throwStartingLocation.x - g_Ball.AtBat_Contact_BallPos.x) +
                         SQ(g_Ball.throwStartingLocation.z - g_Ball.AtBat_Contact_BallPos.z));
    if (((g_Ball.framesSinceThrowStarted > 5 && f->_074 > f->_078) ||
         (g_Ball.framesUntilThrowReachesDest < 1 && f->_074 > 3.0f) ||
         (g_Ball.ballVelocity < 0.18f && g_Ball.fielderWBallIndex < 0 && g_Ball.framesSinceThrowStarted > 60) ||
         traveled > 2.0f + g_Ball.throwDistance || g_Ball.throwHasLastedEstimatedNOfFrames) &&
        f->_074 > f->_0E8 && (f->_252 == 0 || f->_24C <= 0)) {
        throwLen = dolsqrtf2(SQ(g_Ball.throwTarget.x - g_Ball.throwStartingLocation.x) +
                             SQ(g_Ball.throwTarget.z - g_Ball.throwStartingLocation.z));
        ballLen = dolsqrtf2(SQ(g_Ball.throwStartingLocation.x - g_Ball.AtBat_Contact_BallPos.x) +
                            SQ(g_Ball.throwStartingLocation.z - g_Ball.AtBat_Contact_BallPos.z));
        throwAngle = fn_3_9FB8C(g_Ball.throwTarget.x - g_Ball.throwStartingLocation.x,
                                g_Ball.throwTarget.z - g_Ball.throwStartingLocation.z);
        diff = fn_3_9FCF8(throwAngle, (s16)fn_3_9FB8C(g_Ball.AtBat_Contact_BallPos.x - g_Ball.throwStartingLocation.x,
                                                 g_Ball.AtBat_Contact_BallPos.z - g_Ball.throwStartingLocation.z));
        if (g_Ball.framesSinceThrowStarted > 5 && (3.0f + throwLen < ballLen || (throwLen < ballLen && diff < 0x20))) {
            g_Ball.looseBall_codeForHowLongUntilSomeoneWillGetIt = 1;
            if (!g_GameLogic.walkOffWinInd) {
                g_FieldingLogic._128 = 1;
            }
        } else {
            g_Ball.looseBall_codeForHowLongUntilSomeoneWillGetIt = 2;
            g_FieldingLogic._12C = 1;
        }
        g_Ball.ballIsLooseInd_unused = 1;
        g_Ball.ballState = 3;
        fn_3_4E1BC();
        g_FieldingLogic._0C4 = -1;
        g_Ball.fielderBeingThrownTo = -1;
        g_Ball.looseBall_5FrameCountdown = 5;
    }
}

// .text:0x0004E1BC size:0x47C mapped:0x8068D250
void fn_3_4E1BC(void) {
    s32 best[2];
    f32 next = 9999.9f;
    f32 nearest = 9999.9f;
    s32 i;

    for (i = 0; i < 9; i++) {
        f32 dist = dolsqrtf2(SQ(g_Fielders[i]._000 - g_Ball.physicsSubstruct.futureCoordsAndDist[120].pos.x) +
                             SQ(g_Fielders[i]._008 - g_Ball.physicsSubstruct.futureCoordsAndDist[120].pos.z));

        if (dist < nearest) {
            next = nearest;
            nearest = dist;
            best[1] = best[0];
            best[0] = i;
        } else if (dist < next) {
            next = dist;
            best[1] = i;
        }
    }
    for (i = 0; i < 2; i++) {
        UnkAC8Fielder* f = &g_Fielders[best[i]];

        fn_3_43038(best[i]);
        if (g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam]) {
            fn_3_5985C(best[i], 18);
        } else if (i == 0) {
            fn_3_5985C(best[i], 15);
            g_FieldingLogic._0B0 = best[i];
        } else {
            fn_3_5985C(best[i], 16);
        }
        if (f->_18C >= 0 && f->_18C <= 5) {
            fn_3_4B8D0(best[i]);
        }
        if (f->_18C >= 7 && f->_18C <= 14) {
            f->_18C = -1;
            f->_1D7 = 0;
        }
    }
}

// .text:0x0004DC14 size:0x5A8 mapped:0x8068CCA8
// 98.65%: registers only; the callee-saved registers of slow, mode, travel and the angles
// differ (for example travel in r30 against r25), and declaration orders tried do not fix it.
void fn_3_4DC14(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 target = -1;
    s32 pass = 0;
    s32 i;
    s32 travel;
    BOOL slow;
    s32 mode;
    f32 speed;
    f32 lift;
    s32 hAngle;
    s32 vAngle;
    s32 spread;
    s16 angle;
    f32 cz;
    f32 v;
    f32 cx;
    f32 h;

    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_TOY_FIELD) {
        h = lbl_3_data_4618[0];
        if (g_Ball.ballZoneAwayFromHome >= 3) {
            h = lbl_3_data_4618[1];
        }
        for (i = 0; i < 9; i++) {
            if (i != fielder && fn_3_6D658(g_GameLogic.teamFielding, f->_17A, g_Fielders[i]._17A) >= lbl_3_data_4638[2]) {
                if (f->_084[i] < h && f->_084[i] < 999.9f) {
                    target = i;
                    h = f->_084[i];
                }
            }
        }
        if (target >= 0) {
            pass = f->_259 ? 2 : 1;
            playSoundEffect(0x1AB);
        }
    }
    slow = FALSE;
    speed = g_Ball.ballVelocity;
    mode = 0;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        mode = 1;
    }
    if (speed < lbl_3_data_48C4) {
        slow = TRUE;
    }
    if (speed > 0.5f) {
        speed = 0.5f;
    }
    if (g_Ball.hardHitIndicator) {
        lift = speed * lbl_3_data_5CDC[pass + 8];
    } else {
        lift = speed * lbl_3_data_5CDC[pass + 5];
    }
    travel = fn_3_9FD28(g_Ball.ballTravelAngle + 0x800);
    if (pass != 0) {
        angle = fn_3_9FB8C(g_Fielders[target]._000 - f->_000, g_Fielders[target]._008 - f->_008);
        hAngle = angle + RandomInt_Game(0x200);
        hAngle -= 0x100;
        if (pass == 1) {
            vAngle = RandomInt_Game(0x100) + 0x100;
        } else {
            vAngle = RandomInt_Game(0x100) + 0x200;
        }
    } else if (f->_254 == 0) {
        vAngle = RandomInt_Game_Range(lbl_3_data_48C8[mode][0], lbl_3_data_48C8[mode][1]);
        hAngle = fn_3_9FD28(RandomInt_Game_Range(lbl_3_data_48C8[mode][2], lbl_3_data_48C8[mode][3]) + travel);
    } else if (!slow) {
        vAngle = RandomInt_Game_Range(lbl_3_data_48C8[mode][4], lbl_3_data_48C8[mode][5]);
        spread = RandomInt_Game_Range(lbl_3_data_48C8[mode][6], lbl_3_data_48C8[mode][7]);
        if (f->_254 == 1) {
            spread = -spread;
        }
        hAngle = fn_3_9FD28(spread + travel);
    } else {
        vAngle = RandomInt_Game_Range(lbl_3_data_48C8[mode][8], lbl_3_data_48C8[mode][9]);
        spread = RandomInt_Game_Range(lbl_3_data_48C8[mode][10], lbl_3_data_48C8[mode][11]);
        if (f->_254 == 1) {
            spread = -spread;
        }
        hAngle = fn_3_9FD28(spread + travel);
    }
    getComponentsFromSAng(vAngle, &h, &v);
    v *= lift;
    getComponentsFromSAng(hAngle, &cx, &cz);
    h *= speed;
    cx *= h;
    cz *= h;
    g_Ball.physicsSubstruct.velocity.x = cx;
    g_Ball.physicsSubstruct.velocity.y = v;
    g_Ball.physicsSubstruct.velocity.z = cz;
    g_Ball.physicsSubstruct.acceleration.x = 0.0f;
    g_Ball.physicsSubstruct.acceleration.y = 0.0f;
    g_Ball.physicsSubstruct.acceleration.z = 0.0f;
    if (f->_258 == 4) {
        if (f->_20F == 0) {
            f->_1BC = radToShortAngle(f->_048);
            f->_20F = 1;
            f->_1B8 = 0;
            f->_1BA = lbl_3_data_49DC[29];
            f->_252 = 0;
            f->_203 = 0;
            f->_205 = 0;
            f->_207 = 0;
            f->_1EE = 0;
        }
    } else {
        f->_1EE = g_Ball.ballEnergy * lbl_3_data_5CDC[4];
    }
    f->_252 = 0;
    f->_256 = 0;
    g_FieldingLogic._13B = 1;
    g_Ball.ballState = 3;
    g_Ball.fielderAboutToGetBall_hasBall = -1;
    g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy = 0;
    g_Ball.warioWaluGarlicIsActive = 0;
    g_Ball.ballIsRollingIndicator = 0;
    if (g_Ball.numFieldersWhoHandledBallDuringPlay < 0xFE) {
        g_Ball.numFieldersWhoHandledBallDuringPlay++;
    } else {
        g_Ball.numFieldersWhoHandledBallDuringPlay = 0xFF;
    }
    if (g_Ball.fielderWithBallIndexStored < 0) {
        g_Ball.fielderWithBallIndexStored = fielder;
    }
    if (g_Ball.numFieldersWhoHandledBallDuringPlay == 1) {
        if (fn_3_B7E10(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z)) {
            g_Ball.bobbleLocation_1fair_2foul = 2;
            if (g_Ball.ballInitialHitDoneInd == 0 && g_Ball.framesOnGroundUntilPickedUp != 0) {
                fn_3_A0F0();
            }
        } else {
            g_Ball.bobbleLocation_1fair_2foul = 1;
            if (g_Ball.ballInitialHitDoneInd == 0) {
                g_Ball.ballInitialHitDoneInd = 1;
            }
        }
    }
    if (pass != 0) {
        fn_3_90220(f->_17A, 0);
    } else if (f->_258 != 4) {
        fn_3_90220(f->_17A, 10);
    }
    playSoundEffect(0x16F);
    g_Ball.currentStarSwing = 0;
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
    s32 i;

    if (g_FieldingLogic._0F8[1] == 0) {
        g_Fielders[1]._18C = 0;
        fn_3_5985C(1, 1);
        g_FieldingLogic._0D0[0] = 1;
    } else if (g_Ball.hitClassification2 == 7) {
        g_Fielders[0]._18C = 0;
        fn_3_5985C(0, 1);
        g_FieldingLogic._0D0[0] = 0;
    }
    if (g_FieldingLogic._0F8[2] == 0) {
        g_Fielders[2]._18C = 1;
        fn_3_5985C(2, 1);
        g_FieldingLogic._0D0[1] = 2;
    } else if (g_Ball.physicsSubstruct.futureCoordsAndDist[g_Fielders[2]._186].pos.z < lbl_3_data_4444[1].z) {
        g_Fielders[3]._18C = 1;
        fn_3_5985C(3, 1);
        g_FieldingLogic._0D0[1] = 3;
    } else {
        g_Fielders[0]._18C = 1;
        fn_3_5985C(0, 1);
        g_FieldingLogic._0D0[1] = 0;
        g_Fielders[0]._1D8[0] = 1;
    }
    if (g_FieldingLogic._0F8[4] == 0) {
        g_Fielders[4]._18C = 3;
        fn_3_5985C(4, 1);
        g_FieldingLogic._0D0[3] = 4;
    } else if (g_Ball.physicsSubstruct.futureCoordsAndDist[g_Fielders[4]._186].pos.z < lbl_3_data_4444[3].z) {
        g_Fielders[5]._18C = 3;
        fn_3_5985C(5, 1);
        g_FieldingLogic._0D0[3] = 5;
    } else {
        g_Fielders[0]._18C = 3;
        fn_3_5985C(0, 1);
        g_FieldingLogic._0D0[3] = 0;
        g_Fielders[0]._1D8[0] = 1;
    }
    if (g_Ball.Hit_HorizontalAngle < 0x400 || g_Ball.hitClassification3 == 7) {
        if (g_FieldingLogic._0F8[5] == 0) {
            g_Fielders[5]._18C = 2;
            fn_3_5985C(5, 1);
            g_FieldingLogic._0D0[2] = 5;
        } else if (g_FieldingLogic._0F8[3] == 0) {
            g_Fielders[3]._18C = 2;
            fn_3_5985C(3, 1);
            g_FieldingLogic._0D0[2] = 3;
        } else {
            g_Fielders[3]._18C = 2;
            g_Fielders[5]._18C = 2;
        }
    } else if (g_FieldingLogic._0F8[3] == 0) {
        g_Fielders[3]._18C = 2;
        fn_3_5985C(3, 1);
        g_FieldingLogic._0D0[2] = 3;
    } else if (g_FieldingLogic._0F8[5] == 0) {
        g_Fielders[5]._18C = 2;
        fn_3_5985C(5, 1);
        g_FieldingLogic._0D0[2] = 5;
    } else {
        g_Fielders[3]._18C = 2;
        g_Fielders[5]._18C = 2;
    }
    for (i = 0; i < 9; i++) {
        if (g_Fielders[i]._18C >= 0 && g_Fielders[i]._18C <= 3) {
            g_Fielders[i]._1D7 = 1;
        }
    }
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
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 offset = 0.0f;

    if (fn_3_53130(fielder) == 0) {
        if (f->_1D4 >= 2) {
            fn_3_52F4C(fielder, lbl_3_data_44B4[f->_1D4].x, lbl_3_data_44B4[f->_1D4].z);
        } else {
            if (fielder == 6) {
                offset = 10.0f;
            }
            if (fielder == 8) {
                offset = -10.0f;
            }
            fn_3_52F4C(fielder, f->_000 + offset, f->_008 - 20.0f);
        }
        fn_3_5985C(fielder, 6);
    }
}

// .text:0x0004B128 size:0x3EC mapped:0x8068A1BC
void fn_3_4B128(s32 fielder) {
    f32 cx;
    f32 cz;
    f32 x;
    f32 z;
    s16 angle;

    switch (fn_3_53130(fielder)) {
    case 2:
        return;
    case 1:
        break;
    default:
        if (g_FieldingLogic._0C4 >= 1 && g_FieldingLogic._0C4 <= 3 && g_FieldingLogic._0E6 == 1 &&
            (g_FieldingLogic._0C4 == 2 || fielder != 7)) {
            getComponentsFromSAng(fn_3_9FB8C(g_Ball.throwDestination.x - g_Ball.AtBat_Contact_BallPos.x,
                                             g_Ball.throwDestination.z - g_Ball.AtBat_Contact_BallPos.z),
                                  &cx, &cz);
            x = 20.0f * cx + lbl_3_data_4444[g_FieldingLogic._0C4].x;
            z = 20.0f * cz + lbl_3_data_4444[g_FieldingLogic._0C4].z;
            angle = fn_3_9FB8C(x, z);
            if (angle <= 0x800 &&
                ((angle < 0x300 && fielder == 8) || (angle > 0x500 && fielder == 6) ||
                 (angle < 0x400 && (fielder == 7 || fielder == 8)) || (angle >= 0x400 && (fielder == 7 || fielder == 6)))) {
                if (z < lbl_3_data_4444[1].z) {
                    if (x < 0.0f) {
                        x = -35.0f;
                    } else {
                        x = 35.0f;
                    }
                    z = 30.0f;
                }
                fn_3_52F4C(fielder, x, z);
            }
        }
        fn_3_526DC(fielder);
        if (g_Fielders[fielder]._068 < 5.0f) {
            fn_3_5985C(fielder, 12);
        } else if (g_Ball.numberOfThrowsDuringPlay >= 2) {
            fn_3_5985C(fielder, 12);
        }
        break;
    }
}

// .text:0x0004A9AC size:0x77C mapped:0x80689A40
void fn_3_4A9AC(s32 fielder) {
    return;
}

// .text:0x0004A408 size:0x5A4 mapped:0x8068949C
// 98.64%: the inlined fn_3_5985C recomputes the fielder pointer and fn_3_52560 swaps dx and
// dz; with fielder, fn_3_52560 and fn_3_4EFC8 all s32 this reaches 99.83% (see fn_3_3EB6C).
void fn_3_4A408(int fielder, f32* x, f32* z) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 frame;
    f32 ahead;
    f32 vx;
    f32 vz;

    if (g_Ball.AtBat_ContactResult == 0) {
        frame = g_Ball.framesUntilBallHitsGround + 30;
        if (fn_3_52560(fielder, g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                       g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z) < g_Ball.framesUntilBallHitsGround + 30) {
            *x = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x;
            *z = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z;
        } else {
            *x = g_Ball.physicsSubstruct.futureCoordsAndDist[g_Ball.framesUntilBallHitsGround + 60].pos.x;
            *z = g_Ball.physicsSubstruct.futureCoordsAndDist[g_Ball.framesUntilBallHitsGround + 60].pos.z;
        }
        return;
    }
    if (fn_3_9CE0(f->_000, f->_008) < 1.0f) {
        fn_3_5985C(fielder, 12);
        f->_1D5 = 3;
        return;
    }
    if (fielder >= 6) {
        ahead = 60.0f - dolsqrtf2(SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.x) +
                                  SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.z));
        if (ahead > 0.0f) {
            vx = g_Ball.ballVelocityPercent.x * ahead;
            vz = g_Ball.ballVelocityPercent.z * ahead;
            *x = vx + g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.x;
            *z = vz + g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.z;
            return;
        }
    }
    if (fn_3_52560(fielder, g_Ball.physicsSubstruct.futureCoordsAndDist[30].pos.x,
                   g_Ball.physicsSubstruct.futureCoordsAndDist[30].pos.z) < 30) {
        *x = g_Ball.physicsSubstruct.futureCoordsAndDist[30].pos.x;
        *z = g_Ball.physicsSubstruct.futureCoordsAndDist[30].pos.z;
    } else {
        *x = g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.x;
        *z = g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.z;
    }
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
    UnkAC8Fielder* f = &g_Fielders[fielder];
    struct _VecXYZ pos;
    f32 x;
    f32 z;

    switch (fn_3_53130(fielder)) {
    case 2:
        return;
    case 1:
        break;
    default:
        if (f->_1FF == 0) {
            fn_3_499C4(fielder, &pos);
            x = pos.x;
            z = pos.z;
            fn_3_52F4C(fielder, x, z);
            f->_1FF = 1;
        }
        if (f->_1FF == 1) {
            fn_3_526DC(fielder);
            fn_3_494F4(fielder);
        }
        break;
    }
    if (g_Ball.ballState != 0 && g_Ball.ballState != 3) {
        fn_3_5985C(fielder, 12);
        if (fielder <= 5) {
            f->_1D6 = 7;
        } else {
            f->_1D6 = 6;
        }
    }
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
// 99.35%: registers only; in the plant branch the target keeps dz, dx and the distance in
// f8, f4 and f7 where this uses other float registers.
void fn_3_494F4(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (g_Ball.pauseBallMovementWhenInPlant) {
        f32 dz = g_Ball.AtBat_Contact_BallPos.z - f->_008;
        f32 dx = g_Ball.AtBat_Contact_BallPos.x - f->_000;
        f32 dist = dolsqrtf2(dx * dx + dz * dz);
        f32 reach;

        if (dist < lbl_3_data_4930[37]) {
            goto stop;
        }
        reach = lbl_3_data_4930[36] - 1.0f;
        dx /= dist;
        dz /= dist;
        fn_3_52F4C(fielder, reach * dx + f->_000, reach * dz + f->_008);
    }
    if (g_Ball.hitWallInd) {
        if (f->_074 < lbl_3_data_4930[1]) {
            goto stop;
        }
    } else if (dolsqrtf2(SQ(g_Ball.AtBat_Contact_BallPos.x - g_Ball.ballWillHitBallPos.x) +
                         SQ(g_Ball.AtBat_Contact_BallPos.z - g_Ball.ballWillHitBallPos.z)) < lbl_3_data_4930[2] &&
               f->_07C < lbl_3_data_4930[3]) {
        goto stop;
    }
    if (g_Ball.hitClassification1 == 2 && f->_07C < lbl_3_data_4930[3]) {
        goto stop;
    }
    return;
stop:
    fn_3_530EC(fielder);
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
void fn_3_483CC(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    f->_18C = fn_3_3D7D4(fielder);
    f->_1D7 = 2;
    fn_3_5985C(fielder, 14);
    f->_1D6 = 0;
    g_FieldingLogic._0BE = -1;
}

// .text:0x000480B8 size:0x314 mapped:0x8068714C
void fn_3_480B8(void) {
    return;
}

// .text:0x00047778 size:0x940 mapped:0x8068680C
void fn_3_47778(void) {
    if (g_Ball.hitClassification2 != 5 && g_Ball.hitClassification2 != 6 && g_Ball.hitClassification2 != 8) {
        return;
    }
    if (g_FieldingLogic._0F8[3] == 1 || g_FieldingLogic._0F8[3] == 10 || g_FieldingLogic._0F8[3] == 11) {
        if (g_Fielders[5]._18C != -1) {
            g_Fielders[3]._18C = 6;
            g_Fielders[3]._1D7 = 2;
        } else {
            g_Fielders[5]._18C = 6;
            g_Fielders[5]._1D7 = 2;
            if (g_FieldingLogic._0F8[5] == 0) {
                fn_3_5985C(5, 11);
            }
        }
    } else if (g_FieldingLogic._0F8[5] == 1 || g_FieldingLogic._0F8[5] == 10 || g_FieldingLogic._0F8[5] == 11) {
        if (g_Fielders[3]._18C != -1) {
            g_Fielders[5]._18C = 6;
            g_Fielders[5]._1D7 = 2;
        } else {
            g_Fielders[3]._18C = 6;
            g_Fielders[3]._1D7 = 2;
            if (g_FieldingLogic._0F8[3] == 0) {
                fn_3_5985C(3, 11);
            }
        }
    } else if (g_Ball.Hit_HorizontalAngle < 0x400) {
        if (g_Fielders[3]._18C == 1 &&
            (g_FieldingLogic._0F8[2] == 1 || g_FieldingLogic._0F8[2] == 10 || g_FieldingLogic._0F8[2] == 11)) {
            g_Fielders[2]._18C = 6;
            g_Fielders[2]._1D7 = 2;
        } else {
            g_Fielders[3]._18C = 6;
            g_Fielders[3]._1D7 = 2;
            if (g_FieldingLogic._0F8[3] == 0) {
                fn_3_5985C(3, 11);
            }
        }
    } else if (g_Fielders[5]._18C == 3 &&
               (g_FieldingLogic._0F8[4] == 1 || g_FieldingLogic._0F8[4] == 10 || g_FieldingLogic._0F8[4] == 11)) {
        g_Fielders[4]._18C = 6;
        g_Fielders[4]._1D7 = 2;
    } else {
        g_Fielders[5]._18C = 6;
        g_Fielders[5]._1D7 = 2;
        if (g_FieldingLogic._0F8[5] == 0) {
            fn_3_5985C(5, 11);
        }
    }
    if (g_FieldingLogic._0F8[0] == 0) {
        g_Fielders[0]._18C = 15;
        if (g_Ball.Hit_HorizontalAngle < 0x320) {
            fn_3_52F4C(0, 6.0f, 16.0f);
        } else if (g_Ball.Hit_HorizontalAngle < 0x400) {
            fn_3_52F4C(0, 3.0f, 21.0f);
        } else if (g_Ball.Hit_HorizontalAngle < 0x4E0) {
            fn_3_52F4C(0, -3.0f, 21.0f);
        } else {
            fn_3_52F4C(0, -6.0f, 16.0f);
        }
        fn_3_5985C(0, 14);
    }
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
void fn_3_46ABC(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dx;
    f32 dz;
    f32 dx2;
    f32 dz2;
    f32 t;
    f32 z;
    f32 x;

    if (g_Ball.framesSinceThrowStarted == 5 && g_Ball.ballVelocity != 0.0f) {
        t = f->_074 / g_Ball.ballVelocity;
        x = g_Ball.physicsSubstruct.velocity.x * t + g_Ball.AtBat_Contact_BallPos.x;
        z = g_Ball.physicsSubstruct.velocity.z * t + g_Ball.AtBat_Contact_BallPos.z;
        dx = f->_000 - x;
        dz = f->_008 - z;
        dx2 = dx * dx;
        dz2 = dz * dz;
        if (dolsqrtf2(dx2 + dz2) > f->_0E8) {
            f->_1E9 = 1;
            fn_3_52F4C(fielder, x, z);
        }
    }
    fn_3_526DC(fielder);
    if (f->_1E9 != 0 && f->_050 == 0.0f) {
        f->_1E9 = 0;
    }
    if (g_Ball.fielderBeingThrownTo == fielder) {
        fn_3_4E638();
    }
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
    UnkAC8Fielder* f = &g_Fielders[fielder];

    g_FieldingLogic._13C = 0;
    if (f->_1FF == 0) {
        f->_1FF = 1;
        f->_202[0] = 1;
        g_FieldingLogic._0B0 = fielder;
        fn_3_4597C(fielder);
    }
    switch (fn_3_53130(fielder)) {
    case 2:
        return;
    case 1:
        break;
    default:
        if (f->_202[0] != 0) {
            fn_3_526DC(fielder);
            if (g_FieldingLogic._14A & 0x100) {
                g_FieldingLogic._13C = 1;
            }
        }
        break;
    }
    if (g_Ball.ballState != 2) {
        g_FieldingLogic._0C2 = -1;
        f->_202[0] = 0;
        fn_3_5985C(fielder, 9);
    }
}

// .text:0x0004597C size:0x20C mapped:0x80684A10
void fn_3_4597C(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    VecXZ out;
    VecXZ path[2];
    VecXZ perp[2];
    f32 dx;
    f32 dz;
    f32 x;
    f32 z;

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
    x = out.x;
    z = out.z;
    fn_3_52F4C(fielder, x, z);
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
// 99.87%: the inlined fn_3_52560 takes dx and dz in each other's float registers.
void fn_3_43038(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 frames = 0;
    s32 i;

    f->_1DC = 4;
    i = 5;
    while (i <= 120) {
        if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y > 2.5f) {
            i++;
            continue;
        }
        frames = fn_3_52560(fielder, g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x,
                            g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z);
        if (frames < i) {
            f->_184 = i;
            goto found;
        }
        i += 5;
    }
    f->_184 = 120;
found:
    fn_3_52F4C(fielder, g_Ball.physicsSubstruct.futureCoordsAndDist[f->_184].pos.x,
               g_Ball.physicsSubstruct.futureCoordsAndDist[f->_184].pos.z);
    if (f->_184 >= 120) {
        f->_17E = 120;
    } else {
        f->_17E = frames;
    }
}

// .text:0x00042CDC size:0x35C mapped:0x80681D70
void fn_3_42CDC(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 x;
    f32 z;

    f->_028 = 5.0f * g_Ball._19E4 + g_Ball.ballWillHitBallPos.x;
    f->_02C = 5.0f * g_Ball._19E8 + g_Ball.ballWillHitBallPos.z;
    if (f->_18A != 0) {
        fn_3_50DD8(fielder, &x, &z, TRUE);
        fn_3_52F4C(fielder, x, z);
        f->_020 = x;
        f->_024 = z;
    } else {
        fn_3_52F4C(fielder, f->_028, f->_02C);
    }
}

// .text:0x00042BD0 size:0x10C mapped:0x80681C64
void fn_3_42BD0(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 i;

    if (fielder >= 6 && g_Ball.ballState == 0) {
        if (f->_070 < g_Ball.ballDistanceFromHome) {
            fn_3_43038(fielder);
            return;
        }
        for (i = 6; i < 9; i++) {
            if (i != fielder && g_Fielders[i]._1DC == 3 && g_Fielders[i]._17E <= f->_17E && g_Fielders[i]._17E < 90) {
                fn_3_43038(fielder);
                return;
            }
        }
    }
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
// 99.04%: before the second search the target sets busy to 0 and copies it into j
// (`mr r6,r5`); here j gets its own `li`.
void fn_3_41D78(void) {
    BOOL thrown = FALSE;
    BOOL busy;
    s32 i;
    s32 j;

    if (g_Ball.deadBallReason == 0 && g_Ball.AtBat_ContactResult != -1 && g_Ball.ballState != 1 && g_FieldingLogic._13F == 0) {
        if (g_Ball.ballState != 2 ||
            ((g_Ball.framesUntilThrowReachesDest <= 0 || g_Ball.fielderBeingThrownTo < 0) &&
             dolsqrtf2(SQ(g_Ball.throwStartingLocation.x - g_Ball.AtBat_Contact_BallPos.x) +
                       SQ(g_Ball.throwStartingLocation.z - g_Ball.AtBat_Contact_BallPos.z)) > 5.0f + g_Ball.throwDistance)) {
            for (i = 0; i < 9; i++) {
                if (g_FieldingLogic._0F8[i] == 1 || g_FieldingLogic._0F8[i] == 7) {
                    thrown = TRUE;
                    break;
                }
            }
            if (!thrown) {
                fn_3_4197C(FALSE);
                return;
            }
            busy = FALSE;
            for (j = 0; j < 9; j++) {
                if (g_Fielders[j]._1D3 == 2 || g_Fielders[j]._1D3 == 3 || g_Fielders[j]._1D3 == 4 || g_Fielders[j]._1D3 == 18) {
                    busy = TRUE;
                    break;
                }
            }
            if (!busy) {
                fn_3_4197C(FALSE);
            }
        }
    }
}

// .text:0x0004197C size:0x3FC mapped:0x80680A10
void fn_3_4197C(BOOL nearBall) {
    f32 bestDist = 999.9f;
    s32 i;
    s32 best;

    for (i = 0; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];
        f32 dist = dolsqrtf2(SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[90].pos.x - f->_000) +
                             SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[90].pos.z - f->_008));
        f32 score = dist;

        if (nearBall == TRUE && f->_19C != 0 && f->_1E0 != 1 && f->_1E0 != 2 && dist < 3.0f) {
            fn_3_5985C(i, 18);
            fn_3_43038(i);
            return;
        }
        if (g_FieldingLogic._0F8[i] == 4) {
            score -= 3.0f;
        }
        if (g_FieldingLogic._0F8[i] == 1) {
            if (bestDist > score - 5.0f) {
                bestDist = score;
                best = i;
            }
        } else if (bestDist > score) {
            best = i;
            bestDist = score;
        }
    }
    if (g_Fielders[best]._18C != 0) {
        fn_3_4B8D0(best);
    }
    fn_3_5985C(best, 18);
    fn_3_43038(best);
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
    if (g_Fielders[8]._1DB == 0 && g_Fielders[6]._1DB == 0) {
        fn_3_5985C(6, 3);
        fn_3_5985C(7, 3);
        fn_3_5985C(8, 3);
    } else if (g_Fielders[8]._1DB == 0) {
        fn_3_5985C(8, 3);
        fn_3_5985C(7, 3);
    } else if (g_Fielders[6]._1DB == 0) {
        fn_3_5985C(6, 3);
        fn_3_5985C(7, 3);
    } else if (g_Fielders[7]._1DB == 0) {
        fn_3_5985C(6, 3);
        fn_3_5985C(7, 3);
        fn_3_5985C(8, 3);
    } else if (g_Fielders[7]._182 > g_Ball.Hit_HorizontalAngle) {
        fn_3_5985C(8, 3);
        fn_3_5985C(7, 3);
    } else {
        fn_3_5985C(6, 3);
        fn_3_5985C(7, 3);
    }
    fn_3_4C9C8();
    fn_3_47778();
    fn_3_40D54();
}

// .text:0x00040D54 size:0x34 mapped:0x8067FDE8
void fn_3_40D54(void) {
    fn_3_49F40(6, 7);
    fn_3_49F40(8, 6);
}

// .text:0x00040C04 size:0x150 mapped:0x8067FC98
void fn_3_40C04(void) {
    s32 i;

    for (i = 2; i < 6; i++) {
        if (g_Fielders[i]._1DD == 2) {
            fn_3_5985C(i, 3);
            break;
        }
    }
    if (i == 2) {
        fn_3_5985C(3, 3);
    }
    if (i == 4) {
        fn_3_5985C(5, 3);
    }
    fn_3_40D88();
}

// .text:0x000402A8 size:0x95C mapped:0x8067F33C
void fn_3_402A8(void) {
    return;
}

// .text:0x0003FCF0 size:0x5B8 mapped:0x8067ED84
// 91.99%: the target compares angle without re-extending it and keeps the four fielder
// angles one register lower; an s32 angle set from (s16)fn_3_9FB8C(...) scores 92.16%.
void fn_3_3FCF0(BOOL useLanding) {
    s16 angle = g_Ball.Hit_HorizontalAngle;
    s32 third;
    s16 a2;
    s16 a3;
    s16 a4;
    s16 a5;

    if (useLanding) {
        angle = fn_3_9FB8C(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                           g_Ball.physicsSubstruct.hitLandingSpotDistFromHome);
    }
    a2 = g_Fielders[2]._182;
    a3 = g_Fielders[3]._182;
    a4 = g_Fielders[4]._182;
    a5 = g_Fielders[5]._182;
    if (g_Fielders[0]._1DA == 0 && g_Ball.physicsSubstruct.hitLandingSpotDistFromHome < 25.0f && g_Ball.maxYOfHit < 8.0f) {
        fn_3_3F760();
        return;
    }
    if (angle < a2 + (a3 - a2) / 5) {
        fn_3_5985C(2, 3);
        fn_3_5985C(3, 3);
        return;
    }
    if (angle < (a2 + a3) / 2) {
        fn_3_5985C(2, 3);
        fn_3_5985C(3, 3);
        return;
    }
    third = (a5 - a3) / 3;
    if (angle < a3 + third) {
        fn_3_5985C(3, 3);
        if (angle > g_Fielders[0]._182 - 0x40) {
            fn_3_5985C(0, 4);
        }
    } else if (angle < a3 + third * 2) {
        fn_3_5985C(0, 4);
        if (__abs(angle - a3) < __abs(angle - a5)) {
            fn_3_5985C(3, 3);
        } else {
            fn_3_5985C(5, 3);
        }
    } else {
        third = (a4 - a5) / 3;
        if (angle < a5 + third) {
            fn_3_5985C(5, 3);
            if (angle < g_Fielders[0]._182 + 0x40) {
                fn_3_5985C(0, 4);
            }
        } else if (angle < a5 + third * 2) {
            fn_3_5985C(4, 3);
            fn_3_5985C(5, 3);
        } else {
            fn_3_5985C(4, 3);
            fn_3_5985C(5, 3);
        }
    }
}

// .text:0x0003F760 size:0x590 mapped:0x8067E7F4
// 98.96%: registers only; from the Hit_HorizontalAngle test on, the target's volatile
// registers are one higher (g_Ball's base in r7 against r6); the permuter found nothing.
void fn_3_3F760(void) {
    fn_3_5985C(0, 3);
    if (g_Fielders[1]._1DA == 0) {
        if (g_Runners[3].runnerOnFieldOrOutOrScored == 1 && g_Runners[3].runningDirectionCode == 1 &&
            g_Runners[3].fractionalBasesRan >= 3.25f && g_Fielders[1]._186 > 0) {
            if (dolsqrtf2(SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[g_Fielders[1]._186].pos.x) +
                          SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[g_Fielders[1]._186].pos.z)) < 5.0f) {
                fn_3_5985C(1, 3);
            }
        } else {
            fn_3_5985C(1, 3);
        }
    }
    if (g_Ball.Hit_HorizontalAngle < 0x400) {
        if (g_Fielders[2]._1DA == 0) {
            if (g_Fielders[3]._186 - 15 < g_Fielders[2]._186) {
                if (g_Fielders[0]._186 - g_Fielders[3]._186 < 120) {
                    fn_3_5985C(3, 3);
                }
            } else if (g_Ball.physicsSubstruct.futureCoordsAndDist[g_Fielders[2]._186].pos.z < lbl_3_data_4444[1].z) {
                if (g_Fielders[0]._186 - g_Fielders[2]._186 < 80) {
                    fn_3_5985C(2, 3);
                }
            } else if (g_Fielders[0]._186 - g_Fielders[3]._186 < 120) {
                fn_3_5985C(3, 3);
            }
        } else if (g_Fielders[3]._1DA == 0 && g_Fielders[0]._186 - g_Fielders[3]._186 < 120) {
            fn_3_5985C(3, 3);
        }
    } else if (g_Fielders[4]._1DA == 0) {
        if (g_Fielders[5]._186 - 15 < g_Fielders[4]._186) {
            if (g_Fielders[0]._186 - g_Fielders[5]._186 < 120) {
                fn_3_5985C(5, 3);
            }
        } else if (g_Ball.physicsSubstruct.futureCoordsAndDist[g_Fielders[4]._186].pos.z < lbl_3_data_4444[1].z) {
            if ((g_Runners[2].runnerOnFieldOrOutOrScored != 1 || g_Fielders[4]._186 <= 0) &&
                g_Fielders[0]._186 - g_Fielders[4]._186 < 80) {
                fn_3_5985C(4, 3);
            }
        } else if (g_Fielders[0]._186 - g_Fielders[5]._186 < 120) {
            fn_3_5985C(5, 3);
        }
    } else if (g_Fielders[5]._1DA == 0 && g_Fielders[0]._186 - g_Fielders[5]._186 < 120) {
        fn_3_5985C(5, 3);
    }
}

// .text:0x0003F24C size:0x514 mapped:0x8067E2E0
void fn_3_3F24C(void) {
    s16 angle = g_Ball.Hit_HorizontalAngle;

    if (g_Ball.Hit_VerticalAngle >= 0x400 && g_Ball.Hit_VerticalAngle <= 0xC00) {
        angle += 0x800;
        if (angle > 0x1000) {
            angle -= 0x1000;
        }
    }
    if (angle > 0xA00 && angle < 0xE00) {
        fn_3_5985C(1, 3);
    } else if (angle >= 0xE00 || angle < 0x200) {
        if (g_Ball.Hit_VerticalAngle > 0x800) {
            fn_3_5985C(2, 3);
        } else if (g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z < 10.0f) {
            fn_3_5985C(1, 3);
            fn_3_5985C(2, 3);
        } else if (g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z < 20.0f) {
            fn_3_5985C(2, 3);
            fn_3_5985C(3, 3);
        } else {
            fn_3_5985C(3, 3);
            fn_3_5985C(8, 3);
        }
    } else if (g_Ball.Hit_VerticalAngle > 0x800) {
        fn_3_5985C(4, 3);
    } else if (g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z < 10.0f) {
        fn_3_5985C(1, 3);
        fn_3_5985C(4, 3);
    } else if (g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z < 20.0f) {
        fn_3_5985C(4, 3);
        fn_3_5985C(5, 3);
    } else {
        fn_3_5985C(5, 3);
        fn_3_5985C(6, 3);
    }
    fn_3_4C9C8();
    fn_3_47778();
    fn_3_4A124();
}

// .text:0x0003F124 size:0x128 mapped:0x8067E1B8
void fn_3_3F124(void) {
    fn_3_5985C(0, 20);
    if ((g_Fielders[3]._182 + g_Fielders[5]._182) / 2 > g_Ball.Hit_HorizontalAngle) {
        fn_3_5985C(3, 3);
    } else {
        fn_3_5985C(5, 3);
    }
    fn_3_4C9C8();
    fn_3_47778();
    fn_3_4A124();
}

// .text:0x0003F034 size:0xF0 mapped:0x8067E0C8
void fn_3_3F034(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        g_FieldingLogic._0F8[i] = 0;
        fn_3_5985C(i, 0);
    }
    for (i = 0; i < 4; i++) {
        g_FieldingLogic._0D0[i] = -1;
        g_FieldingLogic._101[i] = 0;
    }
    g_FieldingLogic._0BC = -1;
    g_FieldingLogic._0BE = -1;
    g_FieldingLogic._0C2 = -1;
    if (g_Ball.AtBat_ContactResult == 0 && g_Ball.hangtimeOfHit > 45) {
        fn_3_3EB6C();
    } else {
        fn_3_3E690();
    }
}

// .text:0x0003EB6C size:0x4C8 mapped:0x8067DC00
// 97.61%: registers only. With fn_3_4EFC8 and fn_3_52560 taking s32 rather than int this
// reaches 99.69%, but rep_13B8's callers of fn_3_52560 need int; the inlined fn_3_52560 also
// takes dx and dz in each other's float registers (as in fn_3_43038).
void fn_3_3EB6C(void) {
    UnkAC8Fielder* f;
    s32 i;
    int best;
    s32 bestFrames = 9999;
    s32 frames;
    s32 total;

    for (i = 0; i < 9; i++) {
        f = &g_Fielders[i];
        frames = fn_3_52560(i, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                            g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
        total = frames;
        if (f->_1D3 == 2) {
            total = frames - 15;
        }
        if (f->_18C >= 0 && f->_18C <= 3) {
            total += 30;
        }
        if (g_Ball.someCollisionInd == 0 && 5.0f + f->_070 < g_Ball.physicsSubstruct.hitLandingSpotDistFromHome) {
            total += 30;
        }
        if (g_Ball.ballZoneAwayFromHome >= 3 && i <= 5) {
            total += 15;
        }
        if (total < bestFrames) {
            best = i;
            bestFrames = total;
        }
    }
    fn_3_5985C(best, 3);
    fn_3_4EFC8(best, FALSE);
    g_Fielders[best]._1DC = 0;
    fn_3_3E468();
    g_FieldingLogic._0BE = -1;
}

// .text:0x0003E690 size:0x4DC mapped:0x8067D724
// 95.95%: registers only; 99.69% with fn_3_4EFC8 and fn_3_52560 taking s32, as in fn_3_3EB6C.
void fn_3_3E690(void) {
    UnkAC8Fielder* f;
    s32 i;
    s32 best;
    s32 bestFrames = 9999;
    s32 frames;
    s32 total;

    for (i = 0; i < 9; i++) {
        f = &g_Fielders[i];
        frames = fn_3_52560(i, g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.x,
                            g_Ball.physicsSubstruct.futureCoordsAndDist[60].pos.z);
        total = frames;
        if (f->_1D3 == 2) {
            total = frames - 15;
        }
        if (f->_18C >= 0 && f->_18C <= 3) {
            total += 30;
        }
        if (f->_210) {
            total += f->_1C0;
        } else if (f->_212 == 3) {
            total += 90;
        }
        if (f->_20F) {
            total += f->_1BA;
        }
        if (g_Ball.ballZoneAwayFromHome >= 3 && i <= 5) {
            total += 30;
        }
        if (total < bestFrames) {
            best = i;
            bestFrames = total;
        }
    }
    fn_3_5985C(best, 3);
    fn_3_4EFC8(best, FALSE);
    g_Fielders[best]._1DC = 4;
    fn_3_3E468();
    g_FieldingLogic._0BE = -1;
}

static inline void assignCutoffs(void) {
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

// .text:0x0003E468 size:0x228 mapped:0x8067D4FC
// 92.34%: the target keeps the last loop's counter in r31 (with a stack frame), apart from
// the zero the earlier stores use; here both share one register. The body is an inline
// helper so that fn_3_3EB6C inlines it as the target does.
void fn_3_3E468(void) {
    assignCutoffs();
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
s32 fn_3_3D7D4(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 action;
    s32 i;

    if (f->_000 > 0.0f) {
        if (f->_0A8[2] > f->_0A8[1]) {
            action = 10;
        } else {
            action = 11;
        }
    } else if (f->_0A8[2] > f->_0A8[3]) {
        action = 13;
    } else {
        action = 12;
    }
    if (action == 10) {
        for (i = 0; i < 6; i++) {
            if (i != fielder && g_Fielders[i]._18C == 10) {
                action = 11;
            }
        }
    } else if (action == 11) {
        for (i = 0; i < 6; i++) {
            if (i != fielder && g_Fielders[i]._18C == 10) {
                action = 12;
            }
        }
    } else if (action == 12) {
        for (i = 0; i < 6; i++) {
            if (i != fielder && g_Fielders[i]._18C == 10) {
                action = 11;
            }
        }
    } else if (action == 13) {
        for (i = 0; i < 6; i++) {
            if (i != fielder && g_Fielders[i]._18C == 10) {
                action = 12;
            }
        }
    }
    return action;
}

// .text:0x0003D6AC size:0x128 mapped:0x8067C740
void fn_3_3D6AC(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (fn_3_53130(fielder) == 0 && f->_1EC == 0) {
        f->_050 = 0.0f;
        f->_1E3 = 1;
        f->_1D5 = 0;
        f->_014 = f->_000;
        f->_01C = f->_008;
        if (g_Ball.ballState == 0) {
            if (fielder == 6) {
                if (g_Ball.ballAngleFromHome < 0x400 || g_Ball.ballAngleFromHome >= 0xC00) {
                    goto skip;
                }
            } else if (fielder == 8) {
                if (g_Ball.ballAngleFromHome >= 0x400 && g_Ball.ballAngleFromHome < 0xC00) {
                    goto skip;
                }
            }
        }
        fn_3_5985C(fielder, 9);
    skip:
        f->_1F0 = 1;
    }
}

// .text:0x0003D304 size:0x3A8 mapped:0x8067C398
void fn_3_3D304(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 x;
    f32 z;
    f32 dx;
    f32 dz;

    if (f->_20F) {
        g_FieldingLogic._111 = 0;
        return;
    }
    if (f->_210) {
        fn_3_251E4(fielder);
        f->_1EE = 0;
        return;
    }
    if (fn_3_53130(fielder) != 0) {
        return;
    }
    if (f->_211) {
        fn_3_A96FC(fielder);
        return;
    }
    if (f->_1EE) {
        fn_3_A9984(fielder);
        return;
    }
    if (f->_1EF) {
        return;
    }
    if (f->_203) {
        fn_3_2F574(fielder);
        return;
    }
    if (g_Ball.fielderWBallIndex == fielder && f->_1EC == 0) {
        g_Ball.fielderWBallIndex = -1;
    }
    x = lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.awayTeamBattingInd_battingTeam].x;
    z = lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.awayTeamBattingInd_battingTeam].z;
    if (f->_178 != g_GameLogic.Team_CaptainRosterLoc[g_GameLogic.teamFielding]) {
        fn_3_9F79C(lbl_3_data_4348[g_d_GameSettings.StadiumID][g_GameLogic.teamFielding], lbl_3_data_4300[fielder].x,
                   lbl_3_data_4300[fielder].z, &dx, &dz);
        x += dx;
        z += dz;
    }
    f->_1D6 = 13;
    fn_3_52F4C(fielder, x, z);
    fn_3_526DC(fielder);
    if (f->_068 <= 0.5f) {
        fn_3_5985C(fielder, 0);
        f->_1FA = 1;
    }
    if (fielder == g_Ball.fielderWBallIndex) {
        g_FieldingLogic._0C4 = -1;
    }
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
BOOL fn_3_3C484(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_0A8[0] < 5.0f) {
        f->_18C = 9;
    } else if (f->_0A8[1] < 5.0f) {
        f->_18C = fn_3_3D7D4(fielder);
    } else if (f->_0A8[2] < 5.0f) {
        f->_18C = fn_3_3D7D4(fielder);
    } else if (f->_0A8[3] < 5.0f) {
        f->_18C = fn_3_3D7D4(fielder);
    } else {
        return FALSE;
    }
    f->_1D7 = 2;
    fn_3_5985C(fielder, 14);
    f->_1D6 = 11;
    return TRUE;
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
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (fn_3_53130(fielder) == 0) {
        f->_050 = 0.0f;
        f->_068 = 0.0f;
    }
}

// .text:0x0003C1A8 size:0x78 mapped:0x8067B23C
void fn_3_3C1A8(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_1EC == 0 && fn_3_53130(fielder) == 0) {
        f->_050 = 0.0f;
        f->_1E3 = 1;
        f->_1D5 = 0;
        f->_014 = f->_000;
        f->_01C = f->_008;
    }
}

// .text:0x0003BE50 size:0x358 mapped:0x8067AEE4
void fn_3_3BE50(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 dx;
    f32 dz;
    f32 dx2;
    f32 dz2;
    f32 t;
    f32 z;
    f32 x;

    if (f->_1EC != 0) {
        return;
    }
    if (g_Ball.framesSinceThrowStarted == 5 && g_Ball.ballVelocity != 0.0f) {
        t = f->_074 / g_Ball.ballVelocity;
        x = g_Ball.physicsSubstruct.velocity.x * t + g_Ball.AtBat_Contact_BallPos.x;
        z = g_Ball.physicsSubstruct.velocity.z * t + g_Ball.AtBat_Contact_BallPos.z;
        dx = f->_000 - x;
        dz = f->_008 - z;
        dx2 = dx * dx;
        dz2 = dz * dz;
        if (dolsqrtf2(dx2 + dz2) > f->_0E8) {
            f->_1E9 = 1;
            fn_3_52F4C(fielder, x, z);
        }
    }
    fn_3_526DC(fielder);
    if (f->_1E9 != 0 && f->_050 == 0.0f) {
        f->_1E9 = 0;
    }
    if (g_Ball.fielderBeingThrownTo == fielder) {
        fn_3_4E638();
    }
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
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (g_Minigame.GameMode_MiniGame != MINI_GAME_ID_PIRANHA_PANIC && g_Minigame.GameMode_MiniGame != MINI_GAME_ID_STAR_DASH &&
        g_Ball.framesSinceHit <= 0) {
        return;
    }
    switch (fn_3_53130(fielder)) {
    case 2:
        return;
    case 1:
        break;
    default: {
        s32 target = lbl_3_bss_170[0];

        if (g_FieldingLogic._10E) {
            target = -1;
        }
        f->_19E = target;
        if (!g_GameLogic.autoFielding[g_GameLogic.awayTeamBattingInd_battingTeam] && target >= 0 && f->_1A0 > 10) {
            g_FieldingLogic._0CC = -1;
        }
        if (target >= 0 && g_FieldingLogic._070->_1A != 3 && g_FieldingLogic._070->_1A != 4) {
            if (g_FieldingLogic._14A & 0x200) {
                g_FieldingLogic._070->_0C = 0;
            }
            if (ACTIVE_TUTORIAL() && g_Practice.practice_fielding_enableSprinting) {
                g_FieldingLogic._070->_0C = 0;
            }
        }
        fn_3_3A584(fielder);
        break;
    }
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_PIRANHA_PANIC || g_Minigame.GameMode_MiniGame == MINI_GAME_ID_STAR_DASH) {
        return;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        return;
    }
    if (g_Ball.ballState != 0 && g_Ball.ballState != 3) {
        if (f->_18C == 6) {
            fn_3_5985C(fielder, 11);
        } else {
            fn_3_5985C(fielder, 12);
        }
        if (fielder <= 5) {
            f->_1D5 = 3;
        } else {
            f->_1D5 = 2;
        }
        g_FieldingLogic._0B0 = -1;
    }
    if (f->_18C >= 0 && f->_18C <= 3 && f->_0A8[f->_18C] > 3.0f) {
        fn_3_4B8D0(fielder);
    }
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
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 ch = fielder;
    BOOL stopped = FALSE;
    struct _VecXYZ pos;
    s32 angle;
    f32 speed;
    s32 result;

    if (g_d_GameSettings.minigamesEnabled) {
        if (fielder == 0) {
            ch = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            ch = g_Minigame.minigameControlStruct._28[fielder - 2];
        }
    }
    if (f->_252 != 0) {
        fn_3_261E8(fielder);
        f->_1A2 = 0;
    } else {
        angle = f->_19E;
        if (!fn_3_258D8(fielder)) {
            if (g_FieldingLogic._070->_1A == 4 && g_FieldingLogic._070->_14 == fielder) {
                f->_050 = g_FieldingLogic._070->_08 * f->_058;
                f->_030 = g_FieldingLogic._070->_00 * f->_050;
                f->_034 = g_FieldingLogic._070->_04 * f->_050;
            } else {
                if (angle < 0) {
                    if (g_FieldingLogic._070->_14 == fielder) {
                        f->_050 = g_FieldingLogic._070->_08 * f->_058;
                        if (f->_1A2 < 0x7FFE) {
                            f->_1A2++;
                        } else {
                            f->_1A2 = 0x7FFF;
                        }
                    } else {
                        if (f->_1B6 != 0) {
                            f->_050 = f->_054;
                        } else {
                            f->_050 = 0.0f;
                        }
                        if (!(f->_050 > 0.0f)) {
                            f->_1E3 = 1;
                            goto done;
                        }
                    }
                } else {
                    if (f->_1A2 < 0x7FFE) {
                        f->_1A2++;
                    } else {
                        f->_1A2 = 0x7FFF;
                    }
                    if (g_Ball.fielderWBallIndex == fielder && f->_1A2 <= lbl_3_data_49DC[0]) {
                        f->_050 = 0.0f;
                        f->_1E3 = 1;
                    } else {
                        f->_064 = shortAngleToRad_Capped(angle);
                        if (f->_1E3 == 4 || f->_1E3 == 1) {
                            f->_0BC[0] = f->_064;
                            f->_0BC[1] = f->_064;
                            f->_0BC[2] = f->_064;
                            f->_0BC[3] = f->_064;
                            f->_0BC[4] = f->_064;
                        }
                        fn_3_3A234(fielder);
                        f->_1E3 = 0;
                        f->_1E4 = 0;
                    }
                    if (!(f->_050 > 0.0f)) {
                        goto done;
                    }
                }
                speed = f->_050;
                if (g_Ball.fielderWBallIndex == fielder && checkFieldingStat(g_GameLogic.teamFielding, f->_178, 11)) {
                    speed *= lbl_3_data_46F0;
                    lbl_8036E548.actors[ch]->_27A = 1;
                    if (f->_1A0 == 1) {
                        fn_3_1682AC(lbl_8036E548._2C50[ch], 11);
                    }
                }
                f->_030 = speed * (f32)cos(f->_064);
                f->_034 = speed * (f32)sin(f->_064);
            }
            result = fn_3_51798(fielder, &pos);
            if (result == 1) {
                stopped = TRUE;
                f->_050 = 0.0f;
                f->_030 = 0.0f;
                f->_034 = 0.0f;
            } else if (result == 2) {
                if (pos.x > 55.0f || pos.x < -55.0f) {
                    f->_050 = 0.0f;
                } else {
                    f->_030 = 0.0f;
                    f->_034 = 0.0f;
                    f->_000 = pos.x;
                    f->_008 = pos.z;
                }
                stopped = TRUE;
            } else {
                f->_000 += f->_030;
                f->_008 += f->_034;
            }
            if (stopped) {
                g_FieldingLogic._070->_0E = 0;
                g_FieldingLogic._070->_10 = 0;
                g_FieldingLogic._070->_14 = -1;
                g_FieldingLogic._070->_16 = 0;
            }
        }
    }
done:
    f->_014 = f->_000;
    f->_01C = f->_008;
    f->_1F0 = 1;
}

// .text:0x0003A234 size:0x350 mapped:0x806792C8
void fn_3_3A234(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 ch = fielder;
    f32 maxSpeed = f->_058;
    s32 i;

    if (g_d_GameSettings.minigamesEnabled) {
        if (fielder == 0) {
            ch = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            ch = g_Minigame.minigameControlStruct._28[fielder - 2];
        }
    }
    if (f->_1A0 == 0) {
        s32 move = radToShortAngle(f->_064);
        s32 diff = fn_3_9FE6C_normalizeAngle(move - radToShortAngle(f->_048));

        if (diff < 0x200) {
            f->_1F3 = 0;
        } else if (diff < 0x600) {
            f->_1F3 = 3;
        } else if (diff < 0xA00) {
            f->_1F3 = 1;
        } else if (diff < 0xE00) {
            f->_1F3 = 2;
        } else {
            f->_1F3 = 0;
        }
        if (f->_1E3 != 1) {
            if (f->_1F3 == 1) {
                f->_1F3 = 5;
            } else {
                f->_1F3 = 4;
            }
        }
    }
    if (f->_1F3 == 4 || f->_1F3 == 5) {
        f->_050 += 0.5f * f->_05C;
    } else {
        f->_050 += f->_05C;
    }
    for (i = 0; i < f->_217; i++) {
        maxSpeed *= lbl_3_data_46F4;
    }
    if (f->_050 > maxSpeed) {
        f->_050 = maxSpeed;
    }
    if (g_FieldingLogic._070->_14 == fielder) {
        f->_050 = g_FieldingLogic._070->_08 * maxSpeed;
    }
    if (g_Ball.fielderWBallIndex == fielder && checkFieldingStat(g_GameLogic.teamFielding, f->_178, 11)) {
        f->_050 *= lbl_3_data_46F0;
        lbl_8036E548.actors[ch]->_27A = 1;
        if (f->_1A0 == 1) {
            fn_3_1682AC(lbl_8036E548._2C50[ch], 11);
        }
    }
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_STAR_DASH) {
        if (g_Minigame._1D6D == f->_20D) {
            f->_050 *= lbl_3_data_21A14[6];
        }
        if (g_Minigame.playerIDWithPowerup[0] == f->_20D) {
            f->_050 *= *g_Minigame.starDashRelated_0_5Or1_5;
        }
    }
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
    BOOL ready = TRUE;
    BOOL reset;

    if (g_d_GameSettings.GameModeSelected == 2 && g_GameLogic.secondaryGameMode == 12) {
        return;
    }
    if (g_Ball.deadBallReason != 0) {
        return;
    }
    if (g_Ball.ballState == 1) {
        return;
    }
    if (g_Ball.AtBat_ContactResult == 0 && g_Ball.maxYOfHit > 7.0f) {
        if (g_Ball.framesSinceHit < lbl_3_data_49DC[41]) {
            return;
        }
    } else if (g_Ball.framesSinceHit < lbl_3_data_49DC[42]) {
        return;
    }
    if (g_Ball.ballState == 2 && g_Ball.framesUntilThrowReachesDest > 0 && g_Ball.fielderBeingThrownTo >= 0) {
        if (g_Ball.framesSinceThrowStarted == 2 && g_FieldingLogic._0C4 != 6) {
            fn_3_35E1C();
        }
        return;
    }
    if (--g_FieldingLogic._0DA > 0) {
        ready = FALSE;
    } else {
        g_FieldingLogic._0DA = 0;
    }
    if (g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam] == 0 && (g_FieldingLogic._148 & 0x40)) {
        return;
    }
    if (g_FieldingLogic._0B0 >= 0 && g_Fielders[g_FieldingLogic._0B0]._205 != 0) {
        return;
    }
    if (!ready) {
        return;
    }
    if (g_FieldingLogic._137 != 0) {
        return;
    }
    if (g_Ball.catchAnimationTotalFrames != 0) {
        return;
    }
    reset = FALSE;
    if (g_FieldingLogic._0B0 < 0 && g_Ball.ballState == 3) {
        reset = TRUE;
    }
    if (g_FieldingLogic._13B != 0 || reset) {
        fn_3_39DC4();
        if (g_FieldingLogic._0B0 >= 0) {
            g_FieldingLogic._13B = 0;
        }
    } else if (g_FieldingLogic._0B4 >= 0) {
        fn_3_38FF8();
    } else if (g_FieldingLogic._13A != 0 && (g_FieldingLogic._0B0 == 3 || g_FieldingLogic._0B0 == 5)) {
        fn_3_38D10();
    } else if (g_Ball.AtBat_ContactResult == 0) {
        fn_3_39858();
    } else {
        fn_3_393B0();
    }
}

// .text:0x00039DC4 size:0xEC mapped:0x80678E58
void fn_3_39DC4(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        g_FieldingLogic._0F8[i] = 0;
        fn_3_5985C(i, 0);
        g_Fielders[i]._020 = 10000.0f;
        g_Fielders[i]._024 = 0.0f;
    }
    g_FieldingLogic._0B0 = -1;
    g_FieldingLogic._0B2 = -1;
    g_FieldingLogic._0B4 = -1;
    g_FieldingLogic._0BE = -1;
    g_FieldingLogic._139 = 0;
    for (i = 0; i < 4; i++) {
        g_FieldingLogic._0D0[i] = -1;
        g_FieldingLogic._101[i] = 0;
    }
    fn_3_37610(120);
}

// .text:0x00039858 size:0x56C mapped:0x806788EC
void fn_3_39858(void) {
    UnkAC8Fielder* f = &g_Fielders[g_FieldingLogic._0B0];
    s32 pick;

    if (g_FieldingLogic._0B2 < 0) {
        if (g_FieldingLogic._139 == 0 && g_FieldingLogic._0DA == 0) {
            fn_3_38304();
        }
        return;
    } else if (g_FieldingLogic._0B0 <= 5 && g_FieldingLogic._0B2 >= 6) {
        if (g_Ball.hitClassification1 == 2 || g_Ball.hitClassification1 == 5) {
            if (g_FieldingLogic._0B2 != fn_3_36678(g_FieldingLogic._0B0, g_FieldingLogic._0B2, 0,
                                                   g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                                                   g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z)) {
                return;
            }
        } else if (!(3.0f + f->_070 < g_Ball.ballDistanceFromHome)) {
            return;
        }
    } else {
        if (g_FieldingLogic._139 == 0) {
            return;
        }
        if (g_Ball.framesSinceHit < lbl_3_data_484C[3]) {
            return;
        }
        if (lbl_3_bss_170[0] < 0 || !(g_FieldingLogic._148 & 0x200)) {
            f32 limit;

            if (g_Ball.ballDistanceFromHome < (f32)lbl_3_data_484C[5]) {
                return;
            }
            limit = g_Ball.physicsSubstruct.hitLandingSpotDistFromHome - (f32)lbl_3_data_484C[7];
            if (limit > (f32)lbl_3_data_484C[6]) {
                limit = (f32)lbl_3_data_484C[6];
            }
            if (g_Ball.ballDistanceFromHome < limit) {
                return;
            }
        }
        if (g_Fielders[g_FieldingLogic._0B0]._080 < lbl_3_data_4848) {
            pick = g_FieldingLogic._0B0;
        } else if (g_Fielders[g_FieldingLogic._0B2]._080 < lbl_3_data_4848) {
            pick = g_FieldingLogic._0B2;
        } else {
            if (g_Ball.framesSinceHit < lbl_3_data_484C[4]) {
                s32 first = lbl_3_bss_170[0];
                s32 i;

                if (first > 0) {
                    for (i = 1; i < lbl_3_data_484C[8]; i++) {
                        if (lbl_3_bss_170[i] <= 0 || fn_3_9FCF8(first, lbl_3_bss_170[i]) > 0x200) {
                            break;
                        }
                    }
                    if (i < lbl_3_data_484C[8]) {
                        return;
                    }
                } else {
                    return;
                }
            }
            pick = fn_3_37114(g_FieldingLogic._0B0, g_FieldingLogic._0B2, FALSE,
                              0.5f * (g_Fielders[g_FieldingLogic._0B0]._014 + g_Fielders[g_FieldingLogic._0B2]._014),
                              0.5f * (g_Fielders[g_FieldingLogic._0B0]._01C + g_Fielders[g_FieldingLogic._0B2]._01C));
        }
        if (pick < 0) {
            return;
        }
        if (pick == g_FieldingLogic._0B2) {
            if (g_FieldingLogic._0BC < 0) {
                fn_3_5985C(g_FieldingLogic._0B0, 24);
            } else {
                fn_3_5985C(g_FieldingLogic._0B0, 12);
            }
            fn_3_5985C(g_FieldingLogic._0B2, 21);
            g_FieldingLogic._0B0 = g_FieldingLogic._0B2;
        } else {
            if (g_FieldingLogic._0BC < 0) {
                fn_3_5985C(g_FieldingLogic._0B2, 24);
            } else {
                fn_3_5985C(g_FieldingLogic._0B2, 12);
            }
            fn_3_5985C(g_FieldingLogic._0B0, 21);
        }
        g_FieldingLogic._0B2 = -1;
        g_FieldingLogic._139 = 0;
        return;
    }
    fn_3_38790(g_FieldingLogic._0B2, TRUE);
    g_FieldingLogic._0B2 = -1;
}

// .text:0x000393B0 size:0x4A8 mapped:0x80678444
void fn_3_393B0(void) {
    UnkAC8Fielder* fielders = g_Fielders;
    UnkAC8Fielder* f = &fielders[g_FieldingLogic._0B0];
    s32 frame;

    if (g_Ball.framesSinceHit < 60) {
        if (g_FieldingLogic._0B0 == 3) {
            for (frame = 2; frame < 30; frame += 2) {
                if (g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist > fielders[2]._070) {
                    break;
                }
            }
            if (frame < 30 && g_Ball.ballAngleFromHome > fielders[2]._180 && g_Ball.ballAngleFromHome < f->_180 &&
                fielders[2]._070 > 1.0f + g_Ball.ballDistanceFromHome &&
                fn_3_36678(2, 3, 0, g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                           g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z) == 2) {
                fn_3_38790(2, FALSE);
                return;
            }
        } else if (g_FieldingLogic._0B0 == 5) {
            for (frame = 2; frame < 30; frame += 2) {
                if (g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist > fielders[4]._070) {
                    break;
                }
            }
            if (frame < 30 && g_Ball.ballAngleFromHome < fielders[4]._180 && g_Ball.ballAngleFromHome > f->_180 &&
                fielders[4]._070 > 1.0f + g_Ball.ballDistanceFromHome &&
                fn_3_36678(4, 5, 0, g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                           g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z) == 4) {
                fn_3_38790(4, FALSE);
                return;
            }
        }
    }
    if (g_FieldingLogic._0B2 >= 0) {
        s32 pick;
        f32 x;
        f32 z;

        if (g_FieldingLogic._0B0 > 5) {
            return;
        }
        if (g_FieldingLogic._0B2 < 6) {
            return;
        }
        pick = -1;
        x = g_Ball.physicsSubstruct.futureCoordsAndDist[30].pos.x;
        z = g_Ball.physicsSubstruct.futureCoordsAndDist[30].pos.z;
        if (g_Ball.ballVelocity < 0.2f || g_Ball.ballState == 3) {
            if (g_Ball.ballVelocity < 0.1f && g_Ball.ballState == 0 && g_Ball.ballZoneAwayFromHome <= 1 &&
                f->_070 > g_Ball.ballDistanceFromHome && f->_07C < 5.0f) {
                fn_3_5985C(g_FieldingLogic._0B2, 12);
                g_FieldingLogic._0B2 = -1;
            }
            pick = fn_3_36678(g_FieldingLogic._0B0, g_FieldingLogic._0B2, 0, x, z);
        } else if (3.0f + f->_070 < g_Ball.ballDistanceFromHome) {
            pick = fn_3_36678(g_FieldingLogic._0B0, g_FieldingLogic._0B2, 0, x, z);
        }
        if (g_FieldingLogic._0B2 != pick) {
            return;
        }
    } else {
        if ((g_Ball.AtBat_ContactResult == 1 || g_Ball.AtBat_ContactResult == -1 || g_Ball.ballState == 3) &&
            g_Ball.ballVelocity < 0.25f && g_Fielders[g_FieldingLogic._0B0]._074 > 8.0f) {
            fn_3_37610(30);
        }
        return;
    }
    fn_3_38790(g_FieldingLogic._0B2, TRUE);
    g_FieldingLogic._0B2 = -1;
}

// .text:0x00038FF8 size:0x3B8 mapped:0x8067808C
void fn_3_38FF8(void) {
    s32 frame;
    UnkAC8Fielder* f = &g_Fielders[g_FieldingLogic._0B0];
    f32 reach = f->_070;
    s32 pick;

    for (frame = 1; frame < 61; frame += 3) {
        if (g_Ball.physicsSubstruct.futureCoordsAndDist[frame].dist > reach) {
            break;
        }
    }
    if (g_FieldingLogic._0B0 != 1) {
        if (frame <= 1) {
            goto take;
        }
        if (f->_07C < 2.5f) {
            if (lbl_3_bss_16C >= 0 &&
                fn_3_9FCF8(lbl_3_bss_16C, (s16)fn_3_9FB8C(g_Ball.AtBat_Contact_BallPos.x - f->_000,
                                                          g_Ball.AtBat_Contact_BallPos.z - f->_008)) < 0x100) {
                goto keep;
            }
            if (g_FieldingLogic._0B0 >= 2 && g_FieldingLogic._0B0 <= 5 &&
                (g_Ball.hitClassification2 == 2 || g_Ball.hitClassification2 == 3)) {
                goto keep;
            }
        }
    }
    if (g_Fielders[g_FieldingLogic._0B0]._1DB == 0 || g_Fielders[g_FieldingLogic._0B2]._1DB == 0) {
        pick = fn_3_36678(g_FieldingLogic._0B0, g_FieldingLogic._0B2, 3,
                          g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                          g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
    } else {
        pick = fn_3_36678(g_FieldingLogic._0B0, g_FieldingLogic._0B2, 3,
                          g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                          g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z);
    }
    if (pick >= 0) {
        if (pick == g_FieldingLogic._0B2) {
            goto take;
        }
        if (pick == g_FieldingLogic._0B0) {
            goto keep;
        }
    }
    if (g_Ball.framesSinceHit > 90) {
        if (g_Ball.framesSinceBallHitGroundOrWasCaught >= 0) {
            goto keep;
        }
        if (g_Fielders[g_FieldingLogic._0B0]._080 <= g_Fielders[g_FieldingLogic._0B2]._080) {
            goto keep;
        }
        goto take;
    }
    return;
keep:
    g_FieldingLogic._139 = 0;
    if (g_FieldingLogic._0B0 == 0) {
        return;
    }
    goto next;
take:
    if (g_FieldingLogic._13A != 0 && (g_FieldingLogic._0B2 == 3 || g_FieldingLogic._0B2 == 5)) {
        fn_3_38D10();
        if (g_FieldingLogic._13A != 0) {
            if (g_Ball.ballDistanceFromHome - 3.0f > g_Fielders[g_FieldingLogic._0B0]._070) {
                fn_3_38790(g_FieldingLogic._0B2, TRUE);
                goto next;
            }
            return;
        }
    } else {
        fn_3_38790(g_FieldingLogic._0B2, TRUE);
    }
next:
    g_FieldingLogic._0B2 = g_FieldingLogic._0B4;
    g_FieldingLogic._0B4 = -1;
    g_FieldingLogic._139 = 0;
}

// .text:0x00038D10 size:0x2E8 mapped:0x80677DA4
void fn_3_38D10(void) {
    s32 chaser;
    s32 i;
    f32 x;
    f32 z;
    f32 half;

    if (g_Ball.AtBat_ContactResult == 0 && (g_FieldingLogic._0B0 == 3 || g_FieldingLogic._0B0 == 5) &&
        g_Fielders[g_FieldingLogic._0B0]._080 < g_Fielders[g_FieldingLogic._0B0]._0E8) {
        chaser = g_FieldingLogic._0B0;
    } else {
        if ((g_Fielders[3]._1DB == 0 || g_Fielders[5]._1DB == 0) && g_Ball.AtBat_ContactResult == 0) {
            x = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
            z = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z;
        } else {
            half = 0.5f * (g_Fielders[3]._070 + g_Fielders[5]._070);
            for (i = 1; i < 120; i += 3) {
                if (g_Ball.physicsSubstruct.futureCoordsAndDist[i].dist > half) {
                    break;
                }
            }
            x = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.x;
            z = g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.z;
        }
        chaser = fn_3_37114(3, 5, TRUE, x, z);
        if (chaser < 0) {
            if (g_Ball.ballZoneAwayFromHome >= 2 && lbl_3_bss_16C > 0xA00 && lbl_3_bss_16C < 0xE00) {
                g_FieldingLogic._13A = 0;
            }
            return;
        }
    }
    if (chaser == 3) {
        fn_3_38790(3, TRUE);
        fn_3_5985C(5, 12);
    } else {
        fn_3_38790(5, TRUE);
        fn_3_5985C(3, 12);
    }
    g_FieldingLogic._13A = 0;
}

// .text:0x00038790 size:0x580 mapped:0x80677824
void fn_3_38790(s32 fielder, BOOL relay) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 prev = g_FieldingLogic._0B0;

    if (fielder < 0) {
        return;
    }
    if (fielder == prev) {
        return;
    }
    if (g_Ball.ballState == 0 && g_Ball.ballAngleFromHome >= 984 && g_Ball.ballAngleFromHome < 1064) {
        if (prev == 3 && fielder == 5 && f->_18C == 2 && f->_084[3] < 8.0f) {
            return;
        }
        if (prev == 5 && fielder == 3 && f->_18C == 2 && f->_084[5] < 8.0f) {
            return;
        }
    }
    if (g_Ball.ballState == 0 && g_Ball.hitClassification2 <= 6 && fielder == 1 &&
        (lbl_3_bss_170[0] >= 0x800 || lbl_3_bss_170[0] == 0)) {
        return;
    }
    g_FieldingLogic._0B0 = fielder;
    if (!relay) {
        fn_3_5985C(g_FieldingLogic._0B0, 15);
    } else {
        fn_3_5985C(g_FieldingLogic._0B0, 21);
    }
    if (f->_18C >= 0 && f->_18C <= 5) {
        fn_3_4B8D0(fielder);
    }
    if (g_FieldingLogic._0B0 == g_FieldingLogic._0BE) {
        g_FieldingLogic._0BE = -1;
    }
    if (prev >= 0) {
        if (prev >= 6) {
            fn_3_5985C(prev, 16);
        } else if (g_Ball.ballState == 0) {
            if (g_Fielders[prev]._070 > 3.0f + f->_070) {
                fn_3_5985C(prev, 16);
            } else if (g_Fielders[prev]._18C == 6) {
                fn_3_5985C(prev, 11);
            } else {
                fn_3_5985C(prev, 12);
                g_Fielders[prev]._1D5 = 4;
            }
        } else {
            fn_3_5985C(prev, 12);
            g_Fielders[prev]._1D5 = 4;
        }
    }
    if (g_Ball.framesSinceHit < 30) {
        g_FieldingLogic._0DA = 20;
    } else {
        g_FieldingLogic._0DA = 45;
    }
}

// .text:0x00038304 size:0x48C mapped:0x80677398
// 97.20%: the target keeps fn_3_365D0's result in idx0's register (r30) and copies it to
// r3, and copies idx1's -1 into idx0 instead of loading -1 again.
void fn_3_38304(void) {
    BOOL deep;
    s32 pick;
    s32 i;
    s32 idx0;
    s32 idx1;
    s32 idx2;
    f32 t0;
    f32 t2;
    f32 t1;
    f32 landing;

    if (g_FieldingLogic._0B0 >= 0 && g_Fielders[g_FieldingLogic._0B0]._080 < 5.0f) {
        return;
    }
    landing = g_Ball.physicsSubstruct.hitLandingSpotDistFromHome;
    deep = FALSE;
    if (landing > 50.0f) {
        if (g_FieldingLogic._0B0 >= 6) {
            deep = TRUE;
        } else {
            f32 dist = g_Ball.ballDistanceFromHome - 5.0f;

            if (dist > g_Fielders[2]._070 && dist > g_Fielders[3]._070 && dist > g_Fielders[4]._070 &&
                dist > g_Fielders[5]._070) {
                deep = TRUE;
            }
        }
    }
    if (landing > 68.0f || deep) {
        s32 near;
        s32 far;

        if (g_Fielders[6]._080 < g_Fielders[8]._080) {
            if (g_Fielders[6]._080 < g_Fielders[7]._080) {
                near = 6;
                far = 7;
            } else {
                near = 7;
                far = 6;
            }
        } else if (g_Fielders[8]._080 < g_Fielders[7]._080) {
            near = 8;
            far = 7;
        } else {
            near = 7;
            far = 8;
        }
        if (20.0f + g_Fielders[near]._080 < g_Fielders[far]._080) {
            pick = near;
        } else {
            pick = fn_3_36678(near, far, 0, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                              g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
        }
    } else {

        idx2 = -1;
        t2 = 999.9f;
        idx0 = idx1 = -1;
        t0 = t1 = t2;
        for (i = 0; i < 9; i++) {
            f32 t = g_Fielders[i]._080;

            if (t0 > t) {
                t2 = t1;
                idx2 = idx1;
                t1 = t0;
                idx1 = idx0;
                t0 = t;
                idx0 = i;
            } else if (t1 > t) {
                t2 = t1;
                idx2 = idx1;
                t1 = t;
                idx1 = i;
            } else if (t2 > t) {
                t2 = t;
                idx2 = i;
            }
        }
        if (landing > 40.0f) {
            if (t0 <= 8.0f && idx0 == g_FieldingLogic._0B0) {
                pick = idx0;
            } else if (t1 - t0 > 20.0f) {
                pick = idx0;
            } else if (t2 - t1 > 20.0f) {
                pick = fn_3_36678(idx0, idx1, 0, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                                  g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
            } else {
                pick = fn_3_365D0(idx0, idx1, idx2, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                                  g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
            }
        } else {
            pick = fn_3_365D0(idx0, idx1, idx2, g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                              g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
        }
    }
    fn_3_38790(pick, FALSE);
}

// .text:0x00038234 size:0xD0 mapped:0x806772C8
void fn_3_38234(void) {
    if (g_Ball.hitClassification2 <= 4 || g_Ball.hitClassification2 == 7) {
        fn_3_38000();
    } else if (g_Ball.maxYOfHit > 7.0f) {
        fn_3_38304();
    } else if (g_Ball.maxYOfHit < 4.0f) {
        fn_3_38000();
    } else if (g_Ball.someYCoord > 5.0f) {
        fn_3_38304();
    } else if (g_Ball.ballDistanceFromHome < 60.0f) {
        if (lbl_3_bss_170[0] >= 0x900 && lbl_3_bss_170[0] < 0xF00) {
            fn_3_38304();
        } else {
            fn_3_38000();
        }
    } else {
        fn_3_38304();
    }
}

// .text:0x00038000 size:0x234 mapped:0x80677094
void fn_3_38000(void) {
    s16 angle = g_Ball.ballAngleFromHome;
    f32 extra;
    f32 reach;
    s32 frame = 30;
    f32 margin = 5.0f;
    s32 outfielder = 0;
    s32 pick;

    if (angle >= 0x800) {
        pick = 1;
    } else {
        if (angle < 0x300 &&
            (angle < g_Fielders[2]._180 || fn_3_9FCF8(angle, g_Fielders[3]._180) >= 0x100)) {
            outfielder = 8;
            reach = g_Fielders[2]._070;
        } else if (angle > 0x500 &&
                   (angle >= g_Fielders[4]._180 || fn_3_9FCF8(angle, g_Fielders[5]._180) >= 0x100)) {
            outfielder = 6;
            reach = g_Fielders[4]._070;
        } else if (angle < g_Fielders[3]._180) {
            if (g_Fielders[3]._070 >= g_Fielders[2]._070) {
                reach = g_Fielders[3]._070;
            } else {
                reach = g_Fielders[2]._070;
            }
        } else if (angle >= g_Fielders[5]._180) {
            if (g_Fielders[5]._070 >= g_Fielders[4]._070) {
                reach = g_Fielders[5]._070;
            } else {
                reach = g_Fielders[4]._070;
            }
        } else {
            if (g_Fielders[3]._070 >= g_Fielders[5]._070) {
                reach = g_Fielders[3]._070;
            } else {
                reach = g_Fielders[5]._070;
            }
        }
        if (g_Ball.ballVelocity > 0.3f) {
            extra = g_Ball.ballVelocity - 0.3f;
            margin -= 10.0f * extra;
            frame += (s32)(100.0f * extra);
        }
        if (reach + margin > g_Ball.ballDistanceFromHome) {
            pick = fn_3_378B4();
        } else {
            pick = fn_3_361D8(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                              g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z);
            if (outfielder == 8 && pick == 3) {
                pick = 8;
            }
            if (outfielder == 6 && pick == 5) {
                pick = 6;
            }
        }
    }
    fn_3_38790(pick, FALSE);
}

// .text:0x000378B4 size:0x74C mapped:0x80676948
s32 fn_3_378B4(void) {
    s32 result = -1;
    s32 throwAngle = lbl_3_bss_170[0];
    s32 ballAngle = g_Ball.ballAngleFromHome;
    s32 turn = 0x800;
    s32 pad;

    if (lbl_3_bss_170[0] >= 0 && lbl_3_bss_170[3] >= 0) {
        turn = __abs(lbl_3_bss_170[0] - lbl_3_bss_170[3]);
        if (turn > 0x800) {
            turn = 0x1000 - turn;
        }
    }
    if (g_FieldingLogic._0B0 == 0) {
        if (ballAngle >= g_Fielders[0]._180 - 0x40 && ballAngle < g_Fielders[0]._180 + 0x40 &&
            g_Ball.ballDistanceFromHome - g_Fielders[0]._070 < 3.0f) {
            result = 0;
            goto done;
        }
        if (ballAngle < g_Fielders[0]._180) {
            if (throwAngle >= 0xF00 || (throwAngle >= 0 && throwAngle < 0x300)) {
                result = 0;
                goto done;
            }
            if (throwAngle >= 0xB00 && throwAngle < 0xF00 &&
                g_Ball.ballDistanceFromHome - g_Fielders[0]._070 < 3.0f) {
                result = 0;
                goto done;
            }
        } else {
            if (throwAngle >= 0x500 && throwAngle < 0x900) {
                result = 0;
                goto done;
            }
            if (throwAngle >= 0x900 && throwAngle < 0xD00 &&
                g_Ball.ballDistanceFromHome - g_Fielders[0]._070 < 3.0f) {
                result = 0;
                goto done;
            }
        }
    }
    if (__abs(g_Fielders[2]._180 - g_Fielders[3]._180) < 0x40 &&
        ((g_FieldingLogic._0B0 != 2 && g_FieldingLogic._0B0 != 3) || turn >= 0x400)) {
        s32 mid = (g_Fielders[2]._180 + g_Fielders[3]._180) / 2;

        if (ballAngle >= mid - 0x100 && ballAngle < mid + 0x100) {
            if (g_Fielders[2]._070 < g_Fielders[3]._070) {
                if (g_Fielders[2]._070 > g_Ball.ballDistanceFromHome) {
                    result = 2;
                    goto done;
                }
                if (3.0f + g_Fielders[3]._070 > g_Ball.ballDistanceFromHome) {
                    result = 3;
                    goto done;
                }
            } else {
                if (g_Fielders[3]._070 > g_Ball.ballDistanceFromHome) {
                    result = 2;
                    goto done;
                }
                if (3.0f + g_Fielders[2]._070 > g_Ball.ballDistanceFromHome) {
                    result = 3;
                    goto done;
                }
            }
        }
    }
    if (__abs(g_Fielders[4]._180 - g_Fielders[5]._180) < 0x40 &&
        ((g_FieldingLogic._0B0 != 4 && g_FieldingLogic._0B0 != 5) || turn >= 0x400)) {
        s32 mid = (g_Fielders[4]._180 + g_Fielders[5]._180) / 2;

        if (ballAngle >= mid - 0x100 && ballAngle < mid + 0x100) {
            if (g_Fielders[4]._070 <= g_Fielders[5]._070) {
                if (g_Fielders[4]._070 > g_Ball.ballDistanceFromHome) {
                    result = 4;
                    goto done;
                }
                if (3.0f + g_Fielders[5]._070 > g_Ball.ballDistanceFromHome) {
                    result = 5;
                    goto done;
                }
            } else {
                if (g_Fielders[5]._070 > g_Ball.ballDistanceFromHome) {
                    result = 5;
                    goto done;
                }
                if (3.0f + g_Fielders[4]._070 > g_Ball.ballDistanceFromHome) {
                    result = 4;
                    goto done;
                }
            }
        }
    }
    if (ballAngle < g_Fielders[2]._180 + 0x40) {
        if (g_FieldingLogic._0B0 == 3 && turn < 0x400) {
            goto done;
        }
        result = 2;
        goto done;
    }
    if (ballAngle >= g_Fielders[4]._180 - 0x40 && ballAngle < 0x800) {
        if (g_FieldingLogic._0B0 == 5 && turn < 0x400) {
            goto done;
        }
        result = 4;
        goto done;
    }
    pad = 0;
    if (g_FieldingLogic._0B0 == 3) {
        pad = 0x20;
    }
    if (ballAngle >= g_Fielders[3]._180 - (pad + 0x40) && ballAngle < g_Fielders[3]._180 + (pad + 0x40)) {
        if (g_FieldingLogic._0B0 == 2) {
            if (throwAngle >= 0x500 && throwAngle < 0x900) {
                result = 2;
                goto done;
            }
            result = 3;
            goto done;
        }
        if (g_FieldingLogic._0B0 == 5 && g_Fielders[3]._18C == 2 && turn < 0x400) {
            goto done;
        }
        if (g_FieldingLogic._0B0 == 5 && g_Fielders[3]._18C == 2 && 5.0f + g_Fielders[3]._070 < g_Ball.ballDistanceFromHome) {
            goto done;
        }
        result = 3;
        goto done;
    }
    pad = 0;
    if (g_FieldingLogic._0B0 == 2) {
        pad = 0x20;
    }
    if (ballAngle >= g_Fielders[5]._180 - (pad + 0x40) && ballAngle < g_Fielders[5]._180 + (pad + 0x40)) {
        if (g_FieldingLogic._0B0 == 4) {
            if ((throwAngle >= 0 && throwAngle < 0x300) || throwAngle >= 0xF00) {
                result = 4;
                goto done;
            }
            result = 5;
            goto done;
        }
        if (g_FieldingLogic._0B0 == 3 && g_Fielders[5]._18C == 2 && turn < 0x400) {
            goto done;
        }
        if (g_FieldingLogic._0B0 == 3 && g_Fielders[5]._18C == 2 && 5.0f + g_Fielders[5]._070 < g_Ball.ballDistanceFromHome) {
            goto done;
        }
        result = 5;
        goto done;
    }
    if (ballAngle >= g_Fielders[2]._180 && ballAngle < g_Fielders[3]._180) {
        if (throwAngle >= 0x300 && throwAngle < 0x700) {
            result = 2;
            goto done;
        }
        if (throwAngle >= 0x700 && throwAngle < 0x900) {
            if (5.0f + g_Fielders[2]._008 > g_Ball.AtBat_Contact_BallPos.z) {
                result = 2;
                goto done;
            }
            goto done;
        }
        if (throwAngle >= 0xD00 || (throwAngle >= 0 && throwAngle < 0x300)) {
            result = 3;
            goto done;
        }
        goto done;
    }
    if (ballAngle >= g_Fielders[5]._180 && ballAngle < g_Fielders[4]._180) {
        if (throwAngle >= 0x100 && throwAngle < 0x500) {
            result = 4;
            goto done;
        }
        if (throwAngle >= 0xF00 || (throwAngle >= 0 && throwAngle < 0x100)) {
            if (5.0f + g_Fielders[4]._008 > g_Ball.AtBat_Contact_BallPos.z) {
                result = 4;
                goto done;
            }
            goto done;
        }
        if (throwAngle >= 0x500 && throwAngle < 0xB00) {
            result = 5;
            goto done;
        }
        goto done;
    }
    if (ballAngle >= g_Fielders[3]._180 && ballAngle < g_Fielders[5]._180) {
        if (g_Ball.ballDistanceFromHome < 5.0f + g_Fielders[0]._070) {
            if (ballAngle < g_Fielders[0]._180) {
                if (throwAngle > 0xD00 || (throwAngle >= 0 && throwAngle < 0x100)) {
                    result = 0;
                    goto done;
                }
            } else if (throwAngle >= 0x700 && throwAngle < 0xB00) {
                result = 0;
                goto done;
            }
        }
        if (throwAngle >= 0x500 && throwAngle < 0xB00) {
            result = 3;
            goto done;
        }
        if (throwAngle > 0xD00 || (throwAngle >= 0 && throwAngle < 0x300)) {
            result = 5;
            goto done;
        }
    }
done:
    return result;
}

// .text:0x00037610 size:0x2A4 mapped:0x806766A4
void fn_3_37610(s32 frame) {
    s32 best = -1;
    f32 bestTime = 1000.0f;
    s32 i;

    for (i = 0; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];

        if (f->_074 < 5.0f && f->_20F == 0 && f->_074 < bestTime &&
            (f->_210 == 0 || !(0.05f * f->_1C0 + f->_074 > bestTime))) {
            bestTime = f->_074;
            best = i;
        }
    }
    if (best >= 0) {
        if (!(g_Fielders[best]._074 < 5.0f)) {
            f32 dx = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x - g_Fielders[best]._000;
            f32 dz = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z - g_Fielders[best]._008;
            f32 dx2 = dx * dx;
            f32 dz2 = dz * dz;

            if (dolsqrtf2(dx2 + dz2) > 5.0f) {
                best = -1;
            }
        }
    }
    if (best >= 0 && best != g_FieldingLogic._0B0 && g_FieldingLogic._0B0 >= 0) {
        UnkAC8Fielder* f = &g_Fielders[g_FieldingLogic._0B0];

        if (f->_074 < 8.0f && f->_20F == 0) {
            best = -1;
        }
    }
    fn_3_38790(best >= 0 ? best
                         : fn_3_361D8(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                                      g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z),
               FALSE);
}

// .text:0x00037588 size:0x88 mapped:0x8067661C
void fn_3_37588(void) {
    if (g_Ball.ballVelocity > 0.17f) {
        fn_3_38790(fn_3_378B4(), FALSE);
    } else if (g_Ball.AtBat_ContactResult == 0 && g_Ball.hitClassification1 != 0) {
        fn_3_37610(g_Ball.framesUntilBallHitsGround);
    } else if (g_Ball.AtBat_ContactResult == 0) {
        fn_3_37610(30);
    } else {
        fn_3_37610(30);
    }
}

// .text:0x0003740C size:0x17C mapped:0x806764A0
void fn_3_3740C(void) {
    f32 maxReach = 0.0f;
    s32 bestDiff = 0x1000;
    s32 best = -1;
    s32 i;
    s32 diff;

    if (g_Ball.ballState == 0 && g_FieldingLogic._0B0 <= 5) {
        for (i = 0; i < 6; i++) {
            if (g_Fielders[i]._070 > maxReach) {
                maxReach = g_Fielders[i]._070;
            }
        }
        if (5.0f + maxReach < g_Ball.ballDistanceFromHome) {
            for (i = 6; i < 9; i++) {
                diff = __abs(g_Ball.ballAngleFromHome - g_Fielders[i]._180);
                if (bestDiff > diff) {
                    bestDiff = diff;
                    best = i;
                }
            }
            // Tests the loop counter, which is always 9 here, rather than best.
            if (i >= 0) {
                fn_3_38790(best, FALSE);
            }
        }
    }
}

// .text:0x00037114 size:0x2F8 mapped:0x806761A8
s32 fn_3_37114(s32 a, s32 b, BOOL wide, f32 x, f32 z) {
    UnkAC8Fielder* fa = &g_Fielders[a];
    UnkAC8Fielder* fb = &g_Fielders[b];
    s32 ball = lbl_3_bss_16C;
    s16 angA;
    s16 angB;
    s32 diffA;
    s32 diffB;
    f32 dx;
    f32 dz;
    f32 dist;

    if (ball < 0) {
        return -1;
    }
    dx = x - fa->_000;
    dz = z - fa->_008;
    dist = dolsqrtf2(dx * dx + dz * dz);
    angA = fn_3_9FB8C(dx, dz);
    dx = x - fb->_000;
    dz = z - fb->_008;
    dist = dolsqrtf2(dx * dx + dz * dz);
    angB = fn_3_9FB8C(dx, dz);
    if (wide) {
        if (ball >= 0x580 && ball < 0xA80) {
            if (angA >= 0x580 && angA < 0xA80 && angB >= 0x580 && angB < 0xA80) {
                goto nearest;
            }
            if (angA >= 0x580 && angA < 0xA80) {
                return a;
            }
            if (angB >= 0x580 && angB < 0xA80) {
                return b;
            }
        } else if (ball <= 0x280 && ball >= 0xD80) {
            if ((angA < 0x280 || angA >= 0xD80) && (angB < 0x280 || angB >= 0xD80)) {
                goto nearest;
            }
            if (angA < 0x280 || angA >= 0xD80) {
                return a;
            }
            if (angB < 0x280 || angB >= 0xD80) {
                return b;
            }
        }
    } else if (ball >= 0x400 && ball < 0xC00) {
        if (!(angA >= 0x400 && angA < 0xC00 && angB >= 0x400 && angB < 0xC00)) {
            if (angA >= 0x400 && angA < 0xC00) {
                return a;
            }
            if (angB >= 0x400 && angB < 0xC00) {
                return b;
            }
        }
    } else if (!((angA < 0x400 || angA >= 0xC00) && (angB < 0x400 || angB >= 0xC00))) {
        if (angA < 0x400 || angA >= 0xC00) {
            return a;
        }
        if (angB < 0x400 || angB >= 0xC00) {
            return b;
        }
    }
    if (wide) {
        return -1;
    }
    diffA = fn_3_9FCF8(lbl_3_bss_16C, angA);
    diffB = fn_3_9FCF8(lbl_3_bss_16C, angB);
    if (__abs(diffA - diffB) > 0x100) {
        if (diffA > 0x400) {
            if (diffB > 0x400) {
                return -1;
            }
            return b;
        }
        if (diffB > 0x400) {
            if (diffA > 0x400) {
                return -1;
            }
            return a;
        }
    }
nearest:
    if (angA < angB) {
        return a;
    }
    return b;
}

// .text:0x00036678 size:0xA9C mapped:0x8067570C
// 98.86%: the target keeps radToShortAngle's results unextended and passes them so to
// fn_3_9FCF8, which needs s16 angles and s16 parameters; the file's s32 prototype then
// extends them, and the swap and the closing angle gaps extend differently.
s32 fn_3_36678(s32 a, s32 b, s32 mode, f32 x, f32 z) {
    s32 angA;
    s32 angB;
    s16 diff;
    f32 distA;
    f32 distB;
    f32 dx;
    f32 dz;
    f32 dx2;
    f32 dz2;
    f32 gap;
    s16 offA;
    s16 offB;

    if (lbl_3_bss_16C < 0) {
        return -1;
    }
    angA = radToShortAngle(atan2(z - g_Fielders[a]._008, x - g_Fielders[a]._000));
    angB = radToShortAngle(atan2(z - g_Fielders[b]._008, x - g_Fielders[b]._000));
    diff = fn_3_9FCF8(angA, angB);
    dx = g_Fielders[a]._000 - x;
    dz = g_Fielders[a]._008 - z;
    dx2 = dx * dx;
    dz2 = dz * dz;
    distA = dolsqrtf2(dx2 + dz2);
    dx = g_Fielders[b]._000 - x;
    dz = g_Fielders[b]._008 - z;
    dx2 = dx * dx;
    dz2 = dz * dz;
    distB = dolsqrtf2(dx2 + dz2);
    if (diff <= 0x100) {
        if (distA < distB) {
            return a;
        }
        return b;
    }
    if (mode < 2) {
        if (g_FieldingLogic._0B0 == a) {
            distA -= 3.0f;
            if (distA < 0.0f) {
                distA = 0.0f;
            }
        } else if (g_FieldingLogic._0B0 == b) {
            distB -= 3.0f;
            if (distB < 0.0f) {
                distB = 0.0f;
            }
        }
        if (lbl_3_bss_170[3] >= 0) {
            s32 turn = __abs(lbl_3_bss_170[0] - lbl_3_bss_170[3]);
            if (turn > 0x800) {
                turn = 0x1000 - turn;
            }
            if (turn <= 0x400) {
                s32 holder = -1;
                f32 range;
                f32 cut;
                f32 limit;

                if (a == g_FieldingLogic._0B0) {
                    holder = a;
                }
                if (b == g_FieldingLogic._0B0) {
                    holder = b;
                }
                if (holder >= 0) {
                    f32 toPoint;
                    f32 toTarget;

                    dx = g_Fielders[holder]._000 - x;
                    dz = g_Fielders[holder]._008 - z;
                    dx2 = dx * dx;
                    dz2 = dz * dz;
                    toPoint = dolsqrtf2(dx2 + dz2);
                    dx = g_Fielders[holder]._0D4 - x;
                    dz = g_Fielders[holder]._0D8 - z;
                    dx2 = dx * dx;
                    dz2 = dz * dz;
                    toTarget = dolsqrtf2(dx2 + dz2);
                    if (toPoint > toTarget) {
                        goto compare;
                    }
                }
                cut = 7.0f;
                range = dolsqrtf2(x * x + z * z);
                if (range < 30.0f) {
                    cut = 4.0f;
                } else if (range < 38.0f) {
                    cut = 5.0f;
                } else if (range < 46.0f) {
                    cut = 6.0f;
                }
                limit = 8.0f;
                if (range < 38.0f) {
                    limit = 4.0f;
                } else if (range < 46.0f) {
                    limit = 0.2f * (range - 30.0f) + 4.0f;
                }
                if (a == g_FieldingLogic._0B0) {
                    if (distA > limit) {
                        distA -= cut;
                    } else {
                        distA = 0.0f;
                    }
                }
                if (b == g_FieldingLogic._0B0 && distA > limit) {
                    distB = distA - cut;
                }
            }
        }
    }
compare:
    if (distB < distA) {
        f32 tf = distA;
        s32 ti = a;
        s16 ta = angA;

        distA = distB;
        a = b;
        angA = angB;
        distB = tf;
        b = ti;
        angB = ta;
    }
    if (mode < 3) {
        if (distA < 2.0f) {
            return a;
        }
        gap = distB - distA;
        if (gap > 15.0f) {
            if (gap > 20.0f && g_Ball.AtBat_ContactResult == 1 && a >= 6) {
                return a;
            }
            if (g_Ball.ballState == 0 && g_Ball.AtBat_ContactResult == 1) {
                if (a == 1 && gap > 20.0f) {
                    return a;
                }
            } else {
                return a;
            }
        }
        if (gap > 10.0f && distA < 7.0f) {
            return a;
        }
        if (distA < 5.0f && distB < 5.0f && diff <= 0x400) {
            if (mode == 0) {
                return -1;
            }
            return a;
        }
        if (diff <= 0x200 && gap > 5.0f && distA < 15.0f) {
            return a;
        }
    }
    offA = __abs(lbl_3_bss_16C - angA);
    offB = __abs(lbl_3_bss_16C - angB);
    if (offA > 0x800) {
        offA = 0x1000 - offA;
    }
    if (offB > 0x800) {
        offB = 0x1000 - offB;
    }
    if (__abs(offA - offB) <= 0x100) {
        return a;
    }
    if (offA > 0x400) {
        if (g_Ball.ballState == 0 && g_Ball.AtBat_ContactResult == 1 && b == 1) {
            if (offB <= 0x200) {
                return b;
            }
        } else if (offB <= 0x400) {
            return b;
        }
        if (mode == 0) {
            return -1;
        }
    }
    if (offB > 0x400) {
        if (g_Ball.ballState == 0 && g_Ball.AtBat_ContactResult == 1 && b == 1) {
            if (offA <= 0x200) {
                return a;
            }
        } else {
            return a;
        }
    }
    if (offA > offB) {
        return b;
    }
    return a;
}

// .text:0x000365D0 size:0xA8 mapped:0x80675664
s32 fn_3_365D0(s32 a, s32 b, s32 c, f32 x, f32 z) {
    s32 r = fn_3_36678(b, c, 1, x, z);

    if (r == -1) {
        return a;
    }
    if (g_FieldingLogic._0B0 < 0) {
        return fn_3_36678(a, r, 1, x, z);
    }
    return fn_3_36678(a, r, 0, x, z);
}

// .text:0x000361D8 size:0x3F8 mapped:0x8067526C
// 88.11%: registers differ throughout, and the target extends each angle into r3/r4 at
// every fn_3_9FCF8 call where this extends each angle once in place.
s32 fn_3_361D8(f32 x, f32 z) {
    s32 i;
    s32 idx0;
    s32 idx1;
    s32 idx2;
    s32 idx3;
    f32 d0;
    f32 d1;
    f32 d2;
    f32 d3;
    s16 ang0;
    s16 ang1;
    s16 ang2;
    s16 ang3;

    idx0 = idx1 = idx2 = 0;
    d0 = d1 = d2 = d3 = 999.9f;
    idx3 = 0;
    for (i = 0; i < 9; i++) {
        f32 dx = g_Fielders[i]._000 - x;
        f32 dz = g_Fielders[i]._008 - z;
        f32 dist = dolsqrtf2(dx * dx + dz * dz);
        s16 angle = fn_3_9FB8C(dx, dz);

        if (d0 > dist) {
            d2 = d1;
            idx2 = idx1;
            d1 = d0;
            ang2 = ang1;
            idx1 = idx0;
            ang1 = ang0;
            d0 = dist;
            idx0 = i;
            ang0 = angle;
        } else if (d1 > dist) {
            d2 = d1;
            idx2 = idx1;
            d1 = dist;
            ang2 = ang1;
            idx1 = i;
            ang1 = angle;
        } else if (d2 > dist) {
            d3 = d2;
            idx3 = idx2;
            d2 = dist;
            ang3 = ang2;
            idx2 = i;
            ang2 = angle;
        } else if (d3 > dist) {
            d3 = dist;
            idx3 = i;
            ang3 = angle;
        }
    }
    if (d3 - 15.0f < d2) {
        if (fn_3_9FCF8(ang1, ang2) < 0x180) {
            if (fn_3_9FCF8(ang0, ang3) > 0x200 && fn_3_9FCF8(ang1, ang3) > 0x200) {
                idx2 = idx3;
            }
        } else if (fn_3_9FCF8(ang0, ang2) < 0x180) {
            if (fn_3_9FCF8(ang0, ang3) > 0x200 && fn_3_9FCF8(ang1, ang3) > 0x200) {
                idx2 = idx3;
            }
        } else if (fn_3_9FCF8(ang0, ang1) < 0x180 && fn_3_9FCF8(ang0, ang3) > 0x200 &&
                   fn_3_9FCF8(ang2, ang3) > 0x200) {
            idx1 = idx2;
            idx2 = idx3;
        }
    }
    return fn_3_365D0(idx0, idx1, idx2, x, z);
}

// .text:0x00035E1C size:0x3BC mapped:0x80674EB0
// 84.44%: the target keeps first, second and i as full ints (no extsh) yet unrolls the
// search three times; with s32 locals MWCC unrolls it fully instead.
void fn_3_35E1C(void) {
    s16 first = -1;
    s32 mode = 0;
    s16 second = first;
    s32 i;
    f32 dist;

    if (g_Ball.ballZoneAwayFromHome >= 3 && g_FieldingLogic._0C4 == 0) {
        mode = 1;
    } else if (g_Ball.ballZoneAwayFromHome <= 1) {
        mode = 2;
    }
    for (i = 0; i < 6; i++) {
        if (g_FieldingLogic._0F8[i] != 2 && i != g_Ball.throwingFielder) {
            if (first == -1) {
                first = i;
            } else {
                second = i;
                break;
            }
        }
    }
    if (mode != 0 && first >= 0 && second >= 0) {
        if (!(g_Fielders[first]._0B8 < g_Fielders[second]._0B8)) {
            first = second;
        }
    } else {
        dist = dolsqrtf2(SQ(g_Ball.throwTarget.x - g_Ball.AtBat_Contact_BallPos.x) +
                         SQ(g_Ball.throwTarget.z - g_Ball.AtBat_Contact_BallPos.z));
        if (dist < g_Fielders[first]._074) {
            first = -1;
        }
        if (dist < g_Fielders[second]._074) {
            second = -1;
        }
        if (first < 0) {
            first = second;
            second = -1;
        }
        if (first < 0) {
            return;
        }
        if (second >= 0 && g_Fielders[first]._07C > g_Fielders[second]._07C) {
            first = second;
        }
    }
    if (first >= 0) {
        if (mode == 2) {
            if (g_Fielders[first]._07C > 2.0f) {
                return;
            }
        } else if (mode == 0 && g_Fielders[first]._07C > 4.0f) {
            return;
        }
        fn_3_5985C(first, 25);
        g_FieldingLogic._0C2 = first;
    }
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
    s32 primary;
    s32 secondary;
    s16 angle;

    fn_3_33DD0(&primary, &secondary);
    g_FieldingLogic._0B0 = primary;
    g_FieldingLogic._0B2 = secondary;
    fn_3_5985C(g_FieldingLogic._0B0, 22);
    fn_3_5985C(g_FieldingLogic._0B2, 22);
    if (g_FieldingLogic._0B2 >= 0) {
        g_FieldingLogic._139 = 1;
    } else {
        angle = fn_3_9FB8C(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                           g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
        if (g_FieldingLogic._0B0 == 7) {
            if (angle < 0x400) {
                fn_3_5985C(8, 24);
            } else {
                fn_3_5985C(6, 24);
            }
        } else {
            fn_3_5985C(7, 24);
        }
    }
    fn_3_4C9C8();
    fn_3_47778();
    fn_3_33D9C();
}

// .text:0x00033DD0 size:0x418 mapped:0x80672E64
// 99.81%: registers only; in the last test the target puts angle - center->_182 in r5 and its
// sign in r4, this the reverse (as in fn_3_33088; the permuter found nothing).
void fn_3_33DD0(s32* primary, s32* secondary) {
    UnkAC8Fielder* center = &g_Fielders[7];
    s32 side = 6;
    s16 angle;
    UnkAC8Fielder* f;
    s32 centerState;
    s32 sideState;
    BOOL close;
    f32 diff;

    *secondary = -1;
    angle = fn_3_9FB8C(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                       g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
    if (angle > g_Fielders[6]._182) {
        *primary = 6;
        return;
    }
    if (angle < g_Fielders[8]._182) {
        *primary = 8;
        return;
    }
    if (angle < g_Fielders[7]._182) {
        side = 8;
    }
    f = &g_Fielders[side];
    sideState = 10;
    centerState = 10;
    if (center->_1DB == 0) {
        centerState = 0;
    } else if (center->_1DD == 1) {
        centerState = 1;
    } else if (center->_1DD == 2) {
        centerState = 2;
    } else if (center->_1DD == 3) {
        centerState = 3;
    }
    if (f->_1DB == 0) {
        sideState = 0;
    } else if (f->_1DD == 1) {
        sideState = 1;
    } else if (f->_1DD == 2) {
        sideState = 2;
    } else if (f->_1DD == 3) {
        sideState = 3;
    }
    close = FALSE;
    if (g_Ball.wallAndBallIntersectionDistFromHome > 40.0f) {
        diff = center->_080 - f->_080;
        if (diff < 0.0f) {
            diff = -diff;
        }
        if (diff < 10.0f) {
            close = TRUE;
        }
    }
    if ((centerState == sideState && centerState < 10) || close) {
        if (centerState == 0) {
            if (center->_080 <= f->_080) {
                *primary = 7;
                if (f->_080 - center->_080 < 10.0f) {
                    *secondary = side;
                }
            } else {
                *primary = side;
                if (center->_080 - f->_080 < 10.0f) {
                    *secondary = 7;
                }
            }
            return;
        }
        if (centerState == 1) {
            if (center->_186 <= f->_186) {
                *primary = 7;
                if (f->_186 - center->_186 < 45) {
                    *secondary = side;
                }
            } else {
                *primary = side;
                if (center->_186 - f->_186 < 45) {
                    *secondary = 7;
                }
            }
            return;
        }
    } else if (centerState < sideState) {
        if (centerState == 0) {
            *primary = 7;
            if (sideState == 1 && f->_186 - center->_186 < 30) {
                *secondary = side;
            }
            return;
        }
        if (centerState == 1) {
            *primary = 7;
            return;
        }
        if (sideState == 10) {
            *primary = 7;
            return;
        }
    } else if (sideState < centerState) {
        if (sideState == 0) {
            *primary = side;
            if (centerState == 1 && center->_186 - f->_186 < 30) {
                *secondary = 7;
            }
            return;
        }
        if (sideState == 1) {
            *primary = side;
            return;
        }
        if (centerState == 10) {
            *primary = side;
            return;
        }
    }
    if (g_Ball.landingSpotZoneAwayFromHome >= 3) {
        diff = center->_080 - f->_080;
        if (diff < 0.0f) {
            *primary = 7;
            if (diff > -10.0f) {
                *secondary = side;
            }
        } else {
            *primary = side;
            if (diff < 10.0f) {
                *secondary = 7;
            }
        }
    } else if (__abs(angle - center->_182) < __abs(angle - f->_182) + 0x40) {
        *primary = 7;
        *secondary = side;
    } else {
        *primary = side;
        *secondary = 7;
    }
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
// 99.80%: the two angle differences in the last test take each other's registers.
void fn_3_33088(void) {
    UnkAC8Fielder* center = &g_Fielders[7];
    s16 angle = fn_3_9FB8C(g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x,
                           g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z);
    s32 side = 6;
    UnkAC8Fielder* f;
    f32 distCenter;
    f32 distSide;

    if (angle < g_Fielders[7]._182) {
        side = 8;
    }
    f = &g_Fielders[side];
    if (center->_1DD == 1 && f->_1DD == 1) {
        if (center->_1DB == 0 && f->_1DB == 0 && center->_186 == f->_186) {
            distCenter = dolsqrtf2(SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[center->_186].pos.x - center->_000) +
                                   SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[center->_186].pos.z - center->_008));
            distSide = dolsqrtf2(SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[f->_186].pos.x - f->_000) +
                                 SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[f->_186].pos.z - f->_008));
            if (distCenter < distSide) {
                g_FieldingLogic._0B2 = 7;
            } else {
                g_FieldingLogic._0B2 = side;
            }
        } else if (center->_186 <= f->_186) {
            g_FieldingLogic._0B2 = 7;
        } else {
            g_FieldingLogic._0B2 = side;
        }
    } else if (center->_1DD == 1) {
        g_FieldingLogic._0B2 = 7;
    } else if (f->_1DD == 1) {
        g_FieldingLogic._0B2 = side;
    } else if (__abs(angle - center->_182) < __abs(angle - f->_182) + 0x60) {
        g_FieldingLogic._0B2 = 7;
    } else {
        g_FieldingLogic._0B2 = side;
    }
}

// .text:0x000329A4 size:0x6E4 mapped:0x80671A38
void fn_3_329A4(void) {
    return;
}

// .text:0x00032810 size:0x194 mapped:0x806718A4
void fn_3_32810(void) {
    fn_3_5985C(0, 21);
    g_FieldingLogic._0B0 = 0;
    if (g_Ball.Hit_HorizontalAngle < 0x400) {
        g_FieldingLogic._0B2 = 3;
    } else {
        g_FieldingLogic._0B2 = 5;
    }
    fn_3_5985C(3, 22);
    fn_3_5985C(5, 22);
    g_FieldingLogic._13A = 1;
    fn_3_5985C(7, 23);
    g_FieldingLogic._0B4 = 7;
    g_FieldingLogic._139 = 1;
    fn_3_4C9C8();
    fn_3_47778();
    fn_3_4A124();
}

// .text:0x000327F4 size:0x1C mapped:0x80671888
BOOL fn_3_327F4(void) {
    return g_Ball.hitClassification2 == 1;
}

// .text:0x000323A4 size:0x450 mapped:0x80671438
void fn_3_323A4(void) {
    if (g_Fielders[1]._1DA == 0) {
        if (g_Runners[3].runnerOnFieldOrOutOrScored == 1 && g_Runners[3].runningDirectionCode == 1 &&
            g_Runners[3].fractionalBasesRan >= 3.25f && g_Fielders[1]._186 > 0) {
            if (VEC_LENGTH_XZ(&g_Ball.physicsSubstruct.futureCoordsAndDist[g_Fielders[1]._186].pos) < 5.0f) {
                g_FieldingLogic._0B0 = 1;
                g_FieldingLogic._0B2 = 0;
            } else {
                g_FieldingLogic._0B0 = 0;
            }
        } else {
            g_FieldingLogic._0B0 = 1;
            g_FieldingLogic._0B2 = 0;
        }
    } else {
        g_FieldingLogic._0B0 = 0;
    }
    if (g_Ball.Hit_HorizontalAngle < 0x400) {
        if (g_Fielders[3]._186 - 15 < g_Fielders[2]._186) {
            if (g_Fielders[0]._186 - g_Fielders[3]._186 < 120) {
                g_FieldingLogic._0B2 = 3;
            } else {
                goto secondBaseman;
            }
        } else if (g_Ball.physicsSubstruct.futureCoordsAndDist[g_Fielders[2]._186].pos.z < lbl_3_data_4444[1].z) {
            if (g_Fielders[0]._186 - g_Fielders[2]._186 < 80) {
                g_FieldingLogic._0B2 = 2;
            } else {
                goto secondBaseman;
            }
        } else if (g_Fielders[0]._186 - g_Fielders[3]._186 < 120) {
            g_FieldingLogic._0B2 = 3;
        } else {
        secondBaseman:
            g_FieldingLogic._0B2 = 2;
        }
    } else if (g_Fielders[5]._186 - 15 < g_Fielders[4]._186) {
        if (g_Fielders[0]._186 - g_Fielders[5]._186 < 120) {
            g_FieldingLogic._0B2 = 5;
        } else {
            goto shortstop;
        }
    } else if (g_Ball.physicsSubstruct.futureCoordsAndDist[g_Fielders[4]._186].pos.z < lbl_3_data_4444[1].z) {
        if ((g_Runners[2].runnerOnFieldOrOutOrScored != 1 || g_Fielders[4]._186 <= 0) &&
            g_Fielders[0]._186 - g_Fielders[4]._186 < 80) {
            g_FieldingLogic._0B2 = 4;
        } else {
            goto shortstop;
        }
    } else if (g_Fielders[0]._186 - g_Fielders[5]._186 < 120) {
        g_FieldingLogic._0B2 = 5;
    } else {
    shortstop:
        g_FieldingLogic._0B2 = 4;
    }
    fn_3_5985C(g_FieldingLogic._0B0, 21);
    if (g_FieldingLogic._0B2 >= 0) {
        fn_3_5985C(g_FieldingLogic._0B2, 22);
    }
}

// .text:0x00032090 size:0x314 mapped:0x80671124
void fn_3_32090(void) {
    s32 i;
    s32 stat;

    for (i = 0; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];

        if (i == 1) {
            f->_182 = 0x400;
        } else if (f->_000 == 0.0f) {
            f->_182 = 0x400;
        } else {
            s32 angle = 2048.0f * (f32)atan2(f->_008, f->_000) / 3.1415927f;

            if (angle < 0) {
                angle += 0x800;
            }
            f->_182 = angle;
        }
        f->_070 = dolsqrtf2(f->_000 * f->_000 + f->_008 * f->_008);
    }
    fn_3_31C50();
    g_Ball.physicsSubstruct.velocity.x = 0.0f;
    g_Ball.physicsSubstruct.velocity.y = 0.0f;
    g_Ball.physicsSubstruct.velocity.z = 0.0f;
    g_Ball.physicsSubstruct.acceleration.x = 0.0f;
    g_Ball.physicsSubstruct.acceleration.y = 0.0f;
    g_Ball.physicsSubstruct.acceleration.z = 0.0f;
    g_Ball.ballState = 1;
    g_Ball.AtBat_ContactResult = 2;
    g_Ball.fielderAboutToGetBall_hasBall = 0;
    g_Ball.fielderBeingThrownTo = -1;
    g_Ball.ballIsLooseInd_unused = 0;
    g_Ball.looseBall_codeForHowLongUntilSomeoneWillGetIt = 0;
    if (g_FieldingLogic._107 == 1 || g_FieldingLogic._107 == 2) {
        g_Ball.numberOfThrowsDuringPlay = 1;
    }
    if (g_Pitcher.pickOffLoc == 5) {
        g_Ball.AtBat_Contact_BallPos.x = g_Fielders[1]._000;
        g_Ball.AtBat_Contact_BallPos.y = g_Fielders[1]._004;
        g_Ball.AtBat_Contact_BallPos.z = g_Fielders[1]._008;
        g_Ball.fielderWBallIndex = 1;
        return;
    }
    g_Ball.AtBat_Contact_BallPos.x = g_Fielders[0]._000;
    g_Ball.AtBat_Contact_BallPos.y = g_Fielders[0]._004;
    g_Ball.AtBat_Contact_BallPos.z = g_Fielders[0]._008;
    g_Ball.fielderWBallIndex = 0;
    if (g_Pitcher.pickOffLoc >= 1 && g_Pitcher.pickOffLoc <= 3) {
        g_FieldingLogic._0C4 = g_Pitcher.pickOffLoc;
    }
    stat = checkFieldingStat(g_GameLogic.teamFielding, g_Fielders[0]._178, 5);
    g_Fielders[0]._215 = lbl_3_data_4900[stat][2];
}

// .text:0x00031C50 size:0x440 mapped:0x80670CE4
void fn_3_31C50(void) {
    f32 offset3;
    f32 offset5;
    s32 i;

    if (g_Pitcher.pickOffLoc == 5) {
        g_Fielders[0]._18C = 5;
        g_FieldingLogic._0D8 = 0;
        fn_3_5985C(0, 14);
        g_Fielders[1]._18C = 0;
        fn_3_5985C(1, 10);
        g_FieldingLogic._0D0[0] = 1;
    } else {
        fn_3_5985C(0, 10);
        g_Fielders[1]._18C = 0;
        fn_3_5985C(1, 1);
        g_FieldingLogic._0D0[0] = 1;
    }
    g_Fielders[2]._18C = 1;
    fn_3_5985C(2, 1);
    g_FieldingLogic._0D0[1] = 2;
    g_Fielders[4]._18C = 3;
    fn_3_5985C(4, 1);
    g_FieldingLogic._0D0[3] = 4;
    offset3 = __abs(g_Fielders[3]._182 - 0x400);
    offset5 = __abs(g_Fielders[5]._182 - 0x400);
    if (offset3 < offset5) {
        g_Fielders[3]._18C = 2;
        fn_3_5985C(3, 1);
        g_FieldingLogic._0D0[2] = 3;
        fn_3_5985C(5, 0);
    } else {
        g_Fielders[5]._18C = 2;
        fn_3_5985C(5, 1);
        g_FieldingLogic._0D0[2] = 5;
        fn_3_5985C(3, 0);
    }
    for (i = 0; i < 9; i++) {
        if (g_Fielders[i]._18C >= 0 && g_Fielders[i]._18C <= 3) {
            g_Fielders[i]._1D7 = 1;
        }
    }
    fn_3_49F40(6, 5);
    fn_3_49F40(7, 1);
    fn_3_49F40(8, 4);
}

// .text:0x00031A3C size:0x214 mapped:0x80670AD0
void fn_3_31A3C(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];

        if (i == 1) {
            f->_182 = 0x400;
        } else if (f->_000 == 0.0f) {
            f->_182 = 0x400;
        } else {
            s32 angle = 2048.0f * (f32)atan2(f->_008, f->_000) / 3.1415927f;

            if (angle < 0) {
                angle += 0x800;
            }
            f->_182 = angle;
        }
        f->_070 = dolsqrtf2(f->_000 * f->_000 + f->_008 * f->_008);
    }
    fn_3_31678();
    g_Ball.physicsSubstruct.acceleration.x = 0.0f;
    g_Ball.physicsSubstruct.acceleration.y = 0.0f;
    g_Ball.physicsSubstruct.acceleration.z = 0.0f;
    g_Ball.ballState = 3;
    g_Ball.AtBat_ContactResult = 2;
    g_Ball.fielderAboutToGetBall_hasBall = -1;
    g_Ball.fielderBeingThrownTo = -1;
    g_Ball.ballIsLooseInd_unused = 0;
    g_Ball.looseBall_codeForHowLongUntilSomeoneWillGetIt = 0;
}

// .text:0x00031678 size:0x3C4 mapped:0x8067070C
void fn_3_31678(void) {
    f32 offset3;
    f32 offset5;
    s32 i;

    g_Fielders[0]._18C = 0;
    fn_3_5985C(0, 1);
    g_FieldingLogic._0D0[0] = 0;
    if (g_GameLogic.teamAIInd[g_GameLogic.awayTeamBattingInd_battingTeam]) {
        fn_3_5985C(1, 18);
    } else {
        fn_3_5985C(1, 15);
    }
    g_Fielders[2]._18C = 1;
    fn_3_5985C(2, 1);
    g_FieldingLogic._0D0[1] = 2;
    g_Fielders[4]._18C = 3;
    fn_3_5985C(4, 1);
    g_FieldingLogic._0D0[3] = 4;
    offset3 = __abs(g_Fielders[3]._182 - 0x400);
    offset5 = __abs(g_Fielders[5]._182 - 0x400);
    if (offset3 < offset5) {
        g_Fielders[3]._18C = 2;
        fn_3_5985C(3, 1);
        g_FieldingLogic._0D0[2] = 3;
        fn_3_5985C(5, 0);
    } else {
        g_Fielders[5]._18C = 2;
        fn_3_5985C(5, 1);
        g_FieldingLogic._0D0[2] = 5;
        fn_3_5985C(3, 0);
    }
    for (i = 0; i < 9; i++) {
        if (g_Fielders[i]._18C >= 0 && g_Fielders[i]._18C <= 3) {
            g_Fielders[i]._1D7 = 1;
        }
    }
    fn_3_49F40(6, 5);
    fn_3_49F40(7, 1);
    fn_3_49F40(8, 4);
}

// .text:0x00031594 size:0xE4 mapped:0x80670628
void fn_3_31594(void) {
    return;
}

// .text:0x000313B0 size:0x1E4 mapped:0x80670444
void fn_3_313B0(void) {
    UnkAC8Fielder* f;
    s32 i;
    s32 k;

    for (i = 0; i < 9; i++) {
        f = &g_Fielders[i];
        if (g_d_GameSettings.minigamesEnabled) {
            for (k = 0; k < 4; k++) {
                if (g_Minigame.minigameFielderIndex[k] == i) {
                    break;
                }
            }
            if (k >= 4) {
                continue;
            }
        }
        if (f->_050 > 0.0f) {
            if (lbl_3_common_bss_34C90._1D5 == 0) {
                f->_048 = atan2(f->_034, f->_030);
            }
        } else if (g_Pitcher.pitchTotalTimeCounter <= 0 && g_Runners[1].runnerOnFieldOrOutOrScored == 1 && i == 2 &&
                   !g_d_GameSettings.minigamesEnabled) {
            f->_048 = -3.1415927f;
        } else {
            f->_048 = atan2(-f->_008, -f->_000);
        }
        if (f->_030 != 0.0f || f->_034 != 0.0f) {
            f->_064 = atan2(f->_034, f->_030);
            f->_19A = radToShortAngle(f->_064);
        } else {
            f->_064 = 0.0f;
            f->_19A = -1;
        }
        if (g_d_GameSettings.minigamesEnabled) {
            g_Minigame.minigameRelatedIndex = i;
            fn_3_544B8();
        }
    }
    if (g_d_GameSettings.minigamesEnabled) {
        fn_3_53F48();
    } else {
        fn_3_544B8();
    }
}

// .text:0x00030D74 size:0x63C mapped:0x8066FE08
void fn_3_30D74(void) {
    return;
}

// .text:0x00030A58 size:0x31C mapped:0x8066FAEC
void fn_3_30A58(void) {
    f32 x;
    f32 z;
    s32 i;

    for (i = 2; i < 9; i++) {
        UnkAC8Fielder* f = &g_Fielders[i];
        f32 dx;
        f32 dz;
        f32 dx2;
        f32 dz2;
        f32 mz;
        f32 mx;

        fn_3_58F58(i, &x, &z);
        dx = f->_000 - x;
        dz = f->_008 - z;
        dx2 = dx * dx;
        dz2 = dz * dz;
        if (dolsqrtf2(dx2 + dz2) < 0.1f) {
            x = f->_000;
            z = f->_008;
        }
        f->_014 = x;
        f->_01C = z;
        mx = x - f->_000;
        mz = z - f->_008;
        if (mx == 0.0f && mz == 0.0f) {
            f->_050 = 0.0f;
            f->_068 = 0.0f;
        } else {
            f->_064 = atan2(mz, mx);
            f->_068 = dolsqrtf2(mx * mx + mz * mz);
            f->_1D9 = 1;
        }
    }
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
    UnkAC8Fielder* f;
    s32 i;
    f32 dx;
    f32 dz;
    f32 dist;

    for (i = 0; i < 9; i++) {
        f = &g_Fielders[i];
        if (f->_1F1 == 0) {
            f->_1F1 = 1;
            f->_000 = lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.awayTeamBattingInd_battingTeam ^ 1].x;
            f->_004 = 0.0f;
            f->_008 = lbl_3_data_4290[g_d_GameSettings.StadiumID][g_GameLogic.awayTeamBattingInd_battingTeam ^ 1].z;
            f->_014 = lbl_3_data_450C[i].x;
            f->_01C = lbl_3_data_450C[i].z;
            f->_1A6 = RandomInt_Game(30);
        }
        dx = f->_014 - f->_000;
        dz = f->_01C - f->_008;
        dist = dolsqrtf2(dx * dx + dz * dz);
        if (dist < 0.3f || f->_1A6 > g_GameLogic.FrameCountOfCurrentPitch) {
            f->_030 = 0.0f;
            f->_034 = 0.0f;
            f->_050 = 0.0f;
        } else {
            f->_030 = 0.25f * (dx / dist) - 0.01f;
            f->_000 += f->_030;
            f->_034 = 0.25f * (dz / dist) - 0.01f;
            f->_008 += f->_034;
            f->_050 = 0.25f;
        }
    }
    fn_3_313B0();
    g_FieldingLogic._118 = 0;
    g_Ball.framesSinceHit = 100;
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
BOOL fn_3_30214(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    VecSrcDst line;
    CollisionStruct hit;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 len;

    if ((f->_038 == 0.0f && f->_03C == 0.0f) || f->_19A < 0) {
        return FALSE;
    }
    line.dst.y = -0.5f;
    line.src.y = -0.5f;
    line.src.x = f->_000;
    line.src.z = f->_008;
    line.dst.x = f->_000 + f->_038 * lbl_3_data_4930[15];
    line.dst.z = f->_008 + f->_03C * lbl_3_data_4930[15];
    if ((checkCollision(&line, &hit, 0, FALSE) & 0x7F) != 2) {
        return FALSE;
    }
    f->_205 = 1;
    dz = line.dst.z - f->_008;
    dx = line.dst.x - f->_000;
    dist = dolsqrtf2(dx * dx + dz * dz);
    f->_1B2 = (s32)(dist / lbl_3_data_4930[16]) + 1;
    f->_128 = hit.position.x + hit.normal.x * lbl_3_data_4930[27];
    f->_130 = hit.position.z + hit.normal.z * lbl_3_data_4930[27];
    f->_154 = lbl_3_data_4930[17];
    f->_148 = 0.0f;
    len = dolsqrtf2(hit.normal.x * hit.normal.x + hit.normal.z * hit.normal.z);
    f->_140 = hit.normal.x / len;
    f->_144 = hit.normal.z / len;
    f->_050 = 0.0f;
    return TRUE;
}

// .text:0x000300B8 size:0x15C mapped:0x8066F14C
void fn_3_300B8(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    f->_206 = 0;
    if (f->_205 == 1) {
        f32 dx = (f->_128 - f->_000) / f->_1B2;
        f32 dz = (f->_130 - f->_008) / f->_1B2;

        f->_000 += dx;
        f->_008 += dz;
        f->_154 -= lbl_3_data_4930[18];
        f->_148 += f->_154;
        if (f->_148 < 0.0f) {
            f->_148 = 0.0f;
        }
        f->_1B2--;
        if (f->_1B2 <= 0) {
            f->_205 = 2;
        }
    } else if (f->_205 == 2) {
        fn_3_2FB9C(fielder);
        f->_1B2 = 0;
    } else if (f->_205 >= 3) {
        fn_3_2FF2C(fielder);
        return;
    }
    f->_030 = f->_000 - f->_0D4;
    f->_034 = f->_008 - f->_0D8;
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
void fn_3_2FB9C(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    VecSrcDst ray;
    CollisionStruct hit;
    f32 cx;
    f32 cz;
    BOOL moved = FALSE;
    f32 y = f->_148;
    f32 ang;
    f32 outer;
    f32 inner;
    s32 side;
    u8 dir;

    if (g_Ball.ballState == 1 || g_Ball.ballState == 2) {
        f->_205 = 3;
        return;
    }
    if (g_FieldingLogic._14A & 0x100) {
        f->_205 = 3;
        return;
    }
    if (g_FieldingLogic._148 & 8) {
        dir = 1;
        y += lbl_3_data_4930[25];
    } else if (g_FieldingLogic._148 & 4) {
        dir = 2;
        y -= lbl_3_data_4930[25];
    } else {
        goto turn;
    }
    if (y <= 0.0f) {
        f->_205 = 3;
        return;
    }
    ray.src.y = ray.dst.y = -(y + f->_0F4);
    ray.src.x = 5.0f * f->_140 + f->_000;
    ray.src.z = 5.0f * f->_144 + f->_008;
    ray.dst.x = f->_000 - 5.0f * f->_140;
    ray.dst.z = f->_008 - 5.0f * f->_144;
    if ((checkCollision(&ray, &hit, 0, 0) & 0x7F) == 2) {
        f->_148 = y;
        moved = TRUE;
        f->_206 = dir;
    } else {
        return;
    }
turn:
    if (g_FieldingLogic._148 & 2) {
        side = 3;
        ang = f->_06C - lbl_3_data_4930[26];
    } else if (g_FieldingLogic._148 & 1) {
        side = 4;
        ang = f->_06C + lbl_3_data_4930[26];
    } else {
        goto done;
    }
    getComponentsFromRad(ang, &cx, &cz);
    inner = f->_070 - 5.0f;
    outer = 5.0f + f->_070;
    ray.src.x = cx * inner;
    ray.src.z = cz * inner;
    ray.dst.x = cx * outer;
    ray.dst.z = cz * outer;
    ray.src.y = ray.dst.y = -(f->_148 + f->_0F8);
    if ((checkCollision(&ray, &hit, 0, 0) & 0x7F) == 2) {
        f->_000 = hit.position.x;
        f->_008 = hit.position.z;
        if (side != 0) {
            f->_206 = side;
        }
        moved = TRUE;
    } else {
        moved = FALSE;
    }
done:
    if (moved) {
        f32 len = dolsqrtf2(hit.normal.x * hit.normal.x + hit.normal.z * hit.normal.z);
        f->_140 = hit.normal.x / len;
        f->_144 = hit.normal.z / len;
    }
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
    UnkAC8Fielder* f = &g_Fielders[fielder];
    struct _VecXYZ pos;
    s32 type = f->_1CC;

    f->_204++;
    f->_164 -= lbl_3_data_4884[type]._4;
    if (f->_1AE >= f->_1B0 && f->_164 < 0.0f) {
        f->_164 = 0.0f;
    }
    f->_15C += f->_164;
    f->_1AE--;
    if (f->_160 != 0.0f || f->_168 != 0.0f) {
        f->_030 = f->_160;
        f->_034 = f->_168;
        f->_050 = dolsqrtf2(f->_030 * f->_030 + f->_034 * f->_034);
        if (fn_3_51798(fielder, &pos)) {
            f->_160 = 0.0f;
            f->_168 = 0.0f;
            f->_030 = 0.0f;
            f->_034 = 0.0f;
            f->_050 = 0.0f;
        } else {
            f->_000 += f->_030;
            f->_008 += f->_034;
        }
    }
    f->_014 = f->_000;
    f->_01C = f->_008;
    f->_1F0 = 1;
    if (f->_1AE <= 0) {
        f->_203 = 0;
        f->_15C = 0.0f;
        f->_1A0 = 0;
    }
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
    s32 i;
    s32 j;

    if (lbl_3_common_bss_34C90._1D5 != 0) {
        return;
    }
    if (g_Minigame.GameMode_MiniGame == 2) {
        if (g_Minigame.wallBallRotatePitchersInd == 0) {
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigamePlayerSelectedOrder]]._000 = g_Pitcher.pitcher.x;
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigamePlayerSelectedOrder]]._008 = g_Pitcher.pitcher.z;
        }
        return;
    }
    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameFielderIndex[i] > 0) {
            s16* history;
            InputStruct* input;

            g_Minigame.minigameRelatedIndex = g_Minigame.minigameFielderIndex[i];
            g_Minigame._1922 = i;
            if (g_d_GameSettings.GameModeSelected == 6 && g_Minigame.minigameControlStruct.battingHandedness[i] != 0) {
                fn_3_2DDB4();
            }
            input = &g_Controls[g_Minigame.minigameControlStruct.characterIndex[i]];
            history = lbl_3_bss_CC[g_Minigame.minigameControlStruct.characterIndex[i]];
            for (j = 19; j > 0; j--) {
                lbl_3_bss_170[j] = history[j - 1];
            }
            lbl_3_bss_170[0] = input->controlStickAngle;
            if (lbl_3_bss_170[0] == -1) {
                for (j = 1; j < 20; j++) {
                    lbl_3_bss_170[j] = -1;
                }
            }
            if (lbl_3_bss_170[1] >= 0 && lbl_3_bss_170[2] != 0) {
                lbl_3_bss_16C = lbl_3_bss_170[0];
            } else {
                lbl_3_bss_16C = -1;
            }
            for (j = 0; j < 20; j++) {
                history[j] = lbl_3_bss_170[j];
            }
            g_FieldingLogic._148 = input->buttonInput;
            g_FieldingLogic._14A = input->newButtonInput;
            g_FieldingLogic._14C = input->_08;
            g_FieldingLogic._070 = &g_FieldingLogic._000[i];
            g_FieldingLogic._08C = (FieldingLogic08C*)&g_FieldingLogic._074[i];
            g_FieldingLogic._08C->_2 = 0;
            fn_3_3AAF8(g_Minigame.minigameFielderIndex[i]);
            fn_3_3A584(g_Minigame.minigameFielderIndex[i]);
        }
    }
    if (g_d_GameSettings.minigamesEnabled) {
        if (g_Minigame.minigamePlayerSelectedOrder >= 0) {
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigamePlayerSelectedOrder]]._000 = g_Pitcher.pitcher.x;
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigamePlayerSelectedOrder]]._008 = g_Pitcher.pitcher.z;
        }
    } else {
        g_Fielders[0]._000 = g_Pitcher.pitcher.x;
        g_Fielders[0]._008 = g_Pitcher.pitcher.z;
    }
}

// .text:0x0002DDB4 size:0x668 mapped:0x8066CE48
// 99.45%: the target masks the player index when scaling it ((p << 1) & 0x1FE, (p << 4) &
// 0xFF0), and loads the first target's x and z into f1 and f0 the other way round.
void fn_3_2DDB4(void) {
    u8 player = g_Minigame._1922;
    UnkAC8Fielder* f = &g_Fielders[g_Minigame.minigameRelatedIndex];
    InputStruct* input = &g_Controls[player];
    f32 x2;
    f32 z2;
    f32 dist;

    if (g_AiLogic.mgTimer[player] < 0x7FFE) {
        g_AiLogic.mgTimer[player]++;
    } else {
        g_AiLogic.mgTimer[player] = 0x7FFF;
    }
    if (g_AiLogic.mgMode[player] == 0) {
        if (g_AiLogic.mgStep[player] == 0) {
            f32 offset;

            x2 = f->_000 * f->_000;
            z2 = f->_008 * f->_008;
            offset = lbl_3_data_1C44[g_Batter.characterClass];
            dist = dolsqrtf2(x2 + z2);
            g_AiLogic.mgTarget[player].x = f->_000 / dist * offset + f->_000;
            g_AiLogic.mgTarget[player].z = f->_008 / dist * offset + f->_008;
            g_AiLogic.mgTimer[player] = 0;
            g_AiLogic.mgStep[player] = 1;
        } else if (g_AiLogic.mgStep[player] == 2) {
            if (f->_1C8 == 2 || f->_1C8 == 3) {
                g_AiLogic.mgMode[player] = 1;
                g_AiLogic.mgAngle[player] = f->_180;
            } else {
                g_AiLogic.mgMode[player] = 2;
            }
            g_AiLogic.mgStep[player] = 0;
        }
    } else if (g_AiLogic.mgMode[player] == 1) {
        if (g_AiLogic.mgStep[player] == 0) {
            x2 = f->_000 * f->_000;
            z2 = f->_008 * f->_008;
            dist = dolsqrtf2(x2 + z2);
            if (f->_000 < -15.0f) {
                g_AiLogic.mgAngle[player] = f->_180 - 0x600 + RandomInt_Game(0x400);
            } else if (f->_000 > 15.0f) {
                g_AiLogic.mgAngle[player] = f->_180 + 0x200 + RandomInt_Game(0x400);
            } else if (dist > 75.0f) {
                g_AiLogic.mgAngle[player] = RandomInt_Game(0x800) + 0x400 + f->_180;
            } else if (dist < 50.0f) {
                g_AiLogic.mgAngle[player] = RandomInt_Game(0x800) - 0x400 + f->_180;
            } else if (RandomInt_Game(2)) {
                g_AiLogic.mgAngle[player] += RandomInt_Game(0x400) - 0x200;
            } else {
                g_AiLogic.mgAngle[player] = RandomInt_Game(0x1000);
            }
            g_AiLogic.mgAngle[player] = fn_3_9FE6C_normalizeAngle(g_AiLogic.mgAngle[player]);
            g_AiLogic.mgDuration[player] = RandomInt_Game_Range(lbl_3_data_1C54[0], lbl_3_data_1C54[1]);
            g_AiLogic.mgTimer[player] = 0;
            g_AiLogic.mgStep[player] = 1;
        }
    }
    if (g_AiLogic.mgStep[player] == 1) {
        if (g_AiLogic.mgMode[player] == 1) {
            input->controlStickAngle = g_AiLogic.mgAngle[player];
            if (g_AiLogic.mgTimer[player] >= g_AiLogic.mgDuration[player]) {
                g_AiLogic.mgStep[player] = 0;
            }
        } else {
            f32 dz = g_AiLogic.mgTarget[player].z - f->_008;
            f32 dx = g_AiLogic.mgTarget[player].x - f->_000;

            if (dolsqrtf2(dx * dx + dz * dz) < 0.5f) {
                g_AiLogic.mgStep[player] = 2;
            } else {
                input->controlStickAngle = fn_3_9FB8C(dx, dz);
            }
        }
    }
}

// .text:0x0002DCF4 size:0xC0 mapped:0x8066CD88
void fn_3_2DCF4(s32 fielder) {
    return;
}

// .text:0x0002DAC4 size:0x230 mapped:0x8066CB58
void fn_3_2DAC4(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_1ED == 0) {
        fn_3_2D768(fielder);
    }
    if (g_Minigame.framesSincePanelHit != 0) {
        fn_3_5985C(fielder, 28);
    }
}

// .text:0x0002D92C size:0x198 mapped:0x8066C9C0
void fn_3_2D92C(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_1EC == 0) {
        fn_3_2CEF4(fielder);
    }
}

// .text:0x0002D768 size:0x1C4 mapped:0x8066C7FC
void fn_3_2D768(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];

    if (f->_208 == 0) {
        if (f->_1DB == 0) {
            f->_208 = 1;
        } else {
            f->_208 = 3;
        }
    }
    f->_1D6 = 0;
    fn_3_2CEF4(fielder);
}

// .text:0x0002D47C size:0x2EC mapped:0x8066C510
void fn_3_2D47C(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    BOOL stop = FALSE;

    if (g_Minigame.TF_ballDespawnedInd || g_Ball.fielderWBallIndex >= 0 || g_Ball.deadBallReason != 0) {
        stop = TRUE;
    }
    if (g_Minigame._1939 && stop) {
        f->_208 = 4;
    } else if (stop) {
        f->_014 = f->_000;
        f->_01C = f->_008;
        return;
    } else if (g_Ball.hitWallInd) {
        f->_208 = 2;
    }
    if (f->_208 == 1) {
        if (g_Ball.AtBat_ContactResult == 1) {
            f->_208 = 2;
        } else {
            f->_014 = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.x;
            f->_01C = g_Ball.physicsSubstruct.ballLandingSpotOrHeldSpot.z;
        }
    }
    if (f->_208 == 2) {
        f->_014 = g_Ball.AtBat_Contact_BallPos.x;
        f->_01C = g_Ball.AtBat_Contact_BallPos.z;
    }
    if (f->_208 == 3) {
        s32 frame = fn_3_2D080(fielder);

        f->_014 = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x;
        f->_01C = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z;
    }
    if (f->_208 == 4) {
        s32 best = -1;
        f32 bestDist = 999.9f;
        s32 i;

        for (i = 0; i < 100; i++) {
            if (g_Minigame.wallBall_coinsVisibleInd[i]) {
                f32 dx = f->_000 - g_Minigame.wallBall_coinCoordinates[i].x;
                f32 dz = f->_008 - g_Minigame.wallBall_coinCoordinates[i].z;
                f32 dx2 = dx * dx;
                f32 dz2 = dz * dz;
                f32 dist = dolsqrtf2(dx2 + dz2);

                if (dist < bestDist) {
                    best = i;
                    bestDist = dist;
                }
            }
        }
        if (best >= 0) {
            f->_014 = g_Minigame.wallBall_coinCoordinates[best].x;
            f->_01C = g_Minigame.wallBall_coinCoordinates[best].z;
        }
    }
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
void fn_3_2CEF4(s32 fielder) {
    UnkAC8Fielder* f;
    f32 dx;
    f32 dz;
    f32 dist;

    fn_3_2D47C(fielder);
    f = &g_Fielders[fielder];
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
    fn_3_3A584(fielder);
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
void fn_3_2C2F0(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 half;
    s32 i;
    s32 k;

    if (fielder != g_FieldingLogic._070->_14 && !g_Ball.warioWaluGarlicIsActive && g_Ball.AtBat_ContactResult == 0) {
        half = 0.5f * f->_0F4;
        for (i = 0; i < 20; i++) {
            k = g_Ball.framesUntilBallHitsGround - i;
            if (half < g_Ball.physicsSubstruct.futureCoordsAndDist[k].pos.y) {
                i--;
                break;
            }
        }
        if (i < 20) {
            f->_248 = dolsqrtf2(SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[k].pos.x - f->_000) +
                                SQ(g_Ball.physicsSubstruct.futureCoordsAndDist[k].pos.z - f->_008));
            if (f->_248 < 5.0f) {
                if (f->_250 == 0 && g_Ball.framesUntilBallHitsGround < 45) {
                    if (g_Ball.framesUntilBallHitsGround > 30) {
                        if (f->_257) {
                            if (f->_248 < 4.0f) {
                                f->_256 = 1;
                            }
                        } else if (f->_248 < 3.0f) {
                            f->_256 = 1;
                        }
                    }
                } else {
                    f->_256 = 1;
                }
                if (f->_248 < f->_0E8) {
                    g_FieldingLogic._144 = 1;
                }
            }
        }
    }
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
BOOL fn_3_2B694(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    f32 speed;
    s32 frame;

    if (f->_050 == 0.0f || f->_19A < 0) {
        return FALSE;
    }
    if (g_Ball.hitWallInd) {
        return FALSE;
    }
    if (g_Ball.numFieldersWhoHandledBallDuringPlay) {
        return FALSE;
    }
    if (g_Ball.AtBat_ContactResult == 1) {
        if (fn_3_9FCF8(f->_180, f->_19A) > 0x500) {
            return FALSE;
        }
    } else if (g_Ball.AtBat_ContactResult == 0 && fn_3_9FCF8(f->_180, f->_19A) > 0x500 &&
               1.0f + f->_070 < g_Ball.physicsSubstruct.hitLandingSpotDistFromHome) {
        return FALSE;
    }
    speed = f->_058;
    if (fielder == g_FieldingLogic._070->_14) {
        speed *= g_FieldingLogic._070->_08;
    }
    for (frame = lbl_3_data_49DC[17]; frame <= lbl_3_data_49DC[16]; frame++) {
        f32 dx;
        f32 dz;
        f32 dist;
        f32 reach;

        if (g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.y > f->_0F8) {
            continue;
        }
        dx = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x - f->_000;
        dz = g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z - f->_008;
        if (fn_3_9FCF8((s16)fn_3_9FB8C(dx, dz), f->_19A) > lbl_3_data_49DC[18]) {
            continue;
        }
        dist = dolsqrtf2(dx * dx + dz * dz);
        reach = dist - lbl_3_data_4794[f->_1C9];
        if ((s32)(reach / (speed * lbl_3_data_4930[30])) + 1 <= frame && !(reach < f->_0E8) &&
            !fn_3_B7CDC(g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.x,
                        g_Ball.physicsSubstruct.futureCoordsAndDist[frame].pos.z)) {
            fn_3_2C238(fielder, 7, frame, 0, 0);
            f->_21C = dx * (reach / dist) + f->_000;
            f->_224 = dz * (reach / dist) + f->_008;
            fn_3_2B5C0(fielder);
            return TRUE;
        }
    }
    return FALSE;
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
void fn_3_26664(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 ch = fielder;
    s32 toy;
    s32 chance;

    f->_258 = 0;
    if (g_d_GameSettings.minigamesEnabled) {
        if (fielder == 0) {
            ch = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            ch = g_Minigame.minigameControlStruct._28[fielder - 2];
        }
    }
    if (ACTIVE_TUTORIAL() || g_Ball.numFieldersWhoHandledBallDuringPlay != 0 || g_Ball.hitWallInd != 0 ||
        g_Ball.framesOnGroundUntilPickedUp >= 5) {
        return;
    }
    if (checkFieldingStat(g_GameLogic.teamFielding, f->_178, 10)) {
        fn_3_1682AC(lbl_8036E548._2C50[ch], 10);
        playSoundEffect(0x1A8);
        return;
    }
    toy = 0;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        toy = 1;
    }
    if (g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy) {
        if (f->_259) {
            chance = lbl_3_data_4714[toy][f->_1C8][5];
        } else if (f->_260) {
            chance = lbl_3_data_4714[toy][f->_1C8][4];
        } else if (f->_254 == 0) {
            chance = lbl_3_data_4714[toy][f->_1C8][3];
        } else {
            chance = lbl_3_data_4714[toy][f->_1C8][4];
        }
        if (fielder == 0) {
            chance *= 2;
        }
        chance *= 10;
        if (!g_d_GameSettings.exhibitionMatchInd && g_d_GameSettings.humanTeamNumber == g_GameLogic.teamFielding &&
            (g_d_GameSettings.challengeCaptainStarBought[3] || g_d_GameSettings._4F)) {
            chance *= lbl_3_data_5FC4[6];
        }
        if (RandomInt_Game(1000) < chance) {
            f->_258 = 3;
        } else {
            f->_258 = 1;
        }
    } else {
        if (f->_259) {
            chance = lbl_3_data_4714[toy][f->_1C8][2];
        } else if (f->_260) {
            chance = lbl_3_data_4714[toy][f->_1C8][1];
        } else if (f->_254 == 0) {
            chance = lbl_3_data_4714[toy][f->_1C8][0];
        } else {
            chance = lbl_3_data_4714[toy][f->_1C8][1];
        }
        chance *= 10;
        if (!g_d_GameSettings.exhibitionMatchInd && g_d_GameSettings.humanTeamNumber == g_GameLogic.teamFielding &&
            (g_d_GameSettings.challengeCaptainStarBought[3] || g_d_GameSettings._4F)) {
            chance *= lbl_3_data_5FC4[6];
        }
        if (RandomInt_Game(1000) < chance) {
            f->_258 = 2;
        } else {
            f->_258 = 0;
        }
    }
    g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy = 0;
}

// .text:0x000261E8 size:0x47C mapped:0x8066527C
// 99.84%: in the _25C branch the target loads _12C before _148, and the _164 quotient
// takes f1 where this takes f0.
void fn_3_261E8(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    struct _VecXYZ pos;
    s32 result;
    s16 frames = f->_24C;
    f32 n;
    f32 dy;

    if (f->_252 == 4) {
        if (f->_25C != 0) {
            n = f->_25C;
            f->_228 = (f->_128 - f->_000) / n;
            f->_230 = (f->_130 - f->_008) / n;
            dy = (f->_12C - f->_148) / n;
            f->_148 += dy;
            f->_25C--;
            if (f->_25C == 0) {
                fn_3_90220(f->_17A, 0);
            }
        } else {
            n = frames;
            f->_228 = (f->_134 - f->_000) / n;
            f->_230 = (f->_13C - f->_008) / n;
            dy = (f->_138 - f->_148) / n;
            f->_164 = dy;
            f->_148 += dy;
        }
    } else if (f->_24E <= 1) {
        f->_228 = 0.0f;
        f->_22C = 0.0f;
        f->_230 = 0.0f;
        if (f->_252 == 3 || f->_252 == 7 || f->_252 == 8) {
            if (checkFieldingStat(g_GameLogic.teamFielding, f->_178, 7) && f->_252 == 3 && f->_25B == 0) {
                f->_228 = 0.0f;
                f->_230 = 0.0f;
            } else {
                pos.x = f->_21C - f->_000;
                pos.z = f->_224 - f->_008;
                f->_228 = pos.x / f->_24C;
                f->_230 = pos.z / f->_24C;
                if (f->_252 == 7 || f->_252 == 8) {
                    f->_262 = lbl_3_data_49DC[21];
                }
            }
        }
    }
    if (checkFieldingStat(g_GameLogic.teamFielding, f->_178, 7) || f->_265) {
        if (f->_25B == 0) {
            fn_3_25C40(fielder);
        }
    } else {
        f->_000 += f->_228;
        f->_004 += f->_22C;
        f->_008 += f->_230;
        f->_030 = f->_228;
        f->_034 = f->_230;
        f->_050 = dolsqrtf2(f->_030 * f->_030 + f->_034 * f->_034);
    }
    result = fn_3_51798(fielder, &pos);
    if (result == 1) {
        f->_25B = 1;
        g_Ball.catchAnimationTotalFrames = 0;
    }
    if (result != 0) {
        f->_000 = f->_0D4;
        f->_008 = f->_0D8;
        f->_050 = 0.0f;
        f->_030 = 0.0f;
        f->_034 = 0.0f;
    }
    if (f->_050 > 0.0f) {
        f->_038 = f->_030 / f->_050;
        f->_03C = f->_034 / f->_050;
    } else {
        f->_03C = 0.0f;
        f->_038 = 0.0f;
    }
}

// .text:0x00025C40 size:0x5A8 mapped:0x80664CD4
// 99.75%: registers only; the second branch's dx and dz take each other's float registers,
// as do the catch lerp's differences.
void fn_3_25C40(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    s32 ch = fielder;
    VecXYZ pos;
    f32 dx;
    f32 dz;
    f32 scale;
    f32 ox;
    f32 oz;
    f32 t;
    f32 dy;

    if (g_d_GameSettings.minigamesEnabled) {
        if (fielder == 0) {
            ch = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            ch = g_Minigame.minigameControlStruct._28[fielder - 2];
        }
    }
    if (g_Ball.catchAnimationTotalFrames == 0) {
        if (f->_252 == 3) {
            if (f->_24C > lbl_3_data_49DC[26]) {
                return;
            }
            dz = f->_224 - f->_008;
            dx = f->_21C - f->_000;
            scale = 0.01f * lbl_3_data_79B4.sizes[f->_17A][4] / dolsqrtf2(dx * dx + dz * dz);
            ox = dx * scale;
            oz = dz * scale;
            g_Ball.diveCatchLocationOffset.x = f->_000 + ox;
            g_Ball.diveCatchLocationOffset.z = f->_008 + oz;
            g_Ball.diveCatchLocationOffset.y = 0.01f * lbl_3_data_79B4.sizes[f->_17A][7];
        } else {
            if (f->_24C > lbl_3_data_49DC[24]) {
                return;
            }
            dz = f->_224 - f->_008;
            dx = f->_21C - f->_000;
            scale = 0.01f * lbl_3_data_79B4.sizes[f->_17A][0] / dolsqrtf2(dx * dx + dz * dz);
            ox = dx * scale;
            oz = dz * scale;
            g_Ball.diveCatchLocationOffset.x = f->_000 + ox;
            g_Ball.diveCatchLocationOffset.z = f->_008 + oz;
            g_Ball.diveCatchLocationOffset.y = 0.01f * lbl_3_data_79B4.sizes[f->_17A][2];
        }
        g_Ball.fielderActionCatchCoords.x = g_Ball.AtBat_Contact_BallPos.x;
        g_Ball.fielderActionCatchCoords.y = g_Ball.AtBat_Contact_BallPos.y;
        g_Ball.fielderActionCatchCoords.z = g_Ball.AtBat_Contact_BallPos.z;
        g_Ball.catchAnimationTotalFrames = f->_24C;
        if (f->_265 == 0 && f->_252 == 3) {
            f->_24C = lbl_3_data_49DC[37];
            g_Ball.catchAnimationTotalFrames = lbl_3_data_49DC[37];
        }
        g_Batter.invisibleBallForPeachStarHit = 0;
    } else {
        if (f->_265) {
            getAnimRelatedCoordinates(ch, 66, &pos);
            pos.y = -pos.y;
        } else if (f->_252 == 3) {
            pos.x = g_Ball.diveCatchLocationOffset.x;
            pos.y = g_Ball.diveCatchLocationOffset.y;
            pos.z = g_Ball.diveCatchLocationOffset.z;
        } else if (f->_1C7 == 0) {
            getAnimRelatedCoordinates(ch, 79, &pos);
        } else {
            getAnimRelatedCoordinates(ch, 78, &pos);
        }
        t = (f32)f->_24C / g_Ball.catchAnimationTotalFrames;
        dx = g_Ball.AtBat_Contact_BallPos.x - pos.x;
        dy = g_Ball.AtBat_Contact_BallPos.y - pos.y;
        dz = g_Ball.AtBat_Contact_BallPos.z - pos.z;
        dx *= t;
        dy *= t;
        dz *= t;
        g_Ball.fielderActionCatchCoords.x = pos.x + dx;
        g_Ball.fielderActionCatchCoords.y = pos.y + dy;
        g_Ball.fielderActionCatchCoords.z = pos.z + dz;
        if (f->_24C == 1) {
            g_Ball.catchAnimationTotalFrames = 0;
        }
        g_Ball.fielderActionOccuring = 1;
    }
}

// .text:0x00025A68 size:0x1D8 mapped:0x80664AFC
void fn_3_25A68(s32 fielder) {
    UnkAC8Fielder* f = &g_Fielders[fielder];
    struct _VecXYZ pos;

    f->_228 *= 0.95f;
    f->_230 *= 0.95f;
    f->_030 = f->_228;
    f->_034 = f->_230;
    f->_050 = dolsqrtf2(f->_030 * f->_030 + f->_034 * f->_034);
    if (fn_3_51798(fielder, &pos)) {
        f->_000 = f->_0D4;
        f->_008 = f->_0D8;
        f->_050 = 0.0f;
        f->_030 = 0.0f;
        f->_034 = 0.0f;
    } else {
        f->_000 += f->_030;
        f->_008 += f->_034;
    }
    f->_014 = f->_000;
    f->_01C = f->_008;
    f->_1F0 = 1;
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
    UnkAC8Fielder* f = &g_Fielders[fielder];
    struct _VecXYZ pos;
    s32 result;

    f->_1BA--;
    if (f->_1BA <= 0) {
        f->_20F = 0;
        f->_050 = 0.0f;
        f->_030 = 0.0f;
        f->_034 = 0.0f;
        return;
    }
    f->_1B8++;
    f->_1BC = fn_3_9FE6C_normalizeAngle(f->_1BC + lbl_3_data_49DC[32]);
    f->_050 = lbl_3_data_4930[33];
    getComponentsFromSAng(f->_1BC, &f->_038, &f->_03C);
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
    if (g_d_GameSettings.minigamesEnabled) {
        if (g_Minigame.minigameControlStruct.battingHandedness[f->_20D] == 0) {
            fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[f->_20D], 0);
        }
    } else if (g_GameLogic._13E[g_GameLogic.teamFielding] == 0) {
        fn_3_6C854(g_GameLogic.teamFielding, 0);
    }
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
