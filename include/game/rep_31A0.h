#ifndef __GAME_rep_31A0_H_
#define __GAME_rep_31A0_H_

#include "mssbTypes.h"

// Filled by fn_3_10754C; records of these sit 0x16 apart at lbl_803616CC + 0x140
typedef struct UnkStats3448 {
    /* 0x00 */ s16 _00[6];
    /* 0x0C */ u8 _0C[6];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
} UnkStats3448; // size: 0x16

// Written by fn_3_1079C8
typedef struct UnkRank31A0 {
    /* 0x0 */ u8 id;
    /* 0x1 */ u8 rank;
} UnkRank31A0; // size: 0x2

// One entry per player; fn_3_109D88 returns groups of five, one group per minigame
typedef struct UnkRecord3448 {
    /* 0x0 */ s32 _00;
    /* 0x4 */ s16 _04;
    /* 0x6 */ s16 _06;
} UnkRecord3448; // size: 0x8

void fn_3_106DFC(void);
BOOL fn_3_106E50(void);
void fn_3_106EB0(void);
void fn_3_106ED4(void);
void fn_3_107078(void);
void fn_3_1070A4(void);
void fn_3_10722C(void);
void fn_3_10754C(struct UnkStats3448* stats);
void fn_3_10768C(void);
void fn_3_107784(void);
void fn_3_1078F8(void);
BOOL fn_3_107988(u32 id);
void fn_3_1079C8(struct UnkRank31A0* out, int mode);
int fn_3_107B9C(const void* a, const void* b);
int fn_3_107BD0(const void* a, const void* b);
int fn_3_107C04(const void* a, const void* b);
u32 fn_3_107C40(void);
u32 fn_3_107C88(void);
s32 fn_3_107CD0(void);
int fn_3_107D34(const void* a, const void* b);
u32 fn_3_107D70(s8 port);
u32 fn_3_107DB4(s8 port);
u32 fn_3_107DF8(s8 port);
u32 minigame_checkIfAIInputIs_Algorithmic_Or_ControllerBased(s8 port);
void fn_3_107E80(void);
void fn_3_108230(void);
void fn_3_1084B4(void);
int fn_3_108854(void);
void fn_3_1089E8(void);
void fn_3_108C54(void);
void fn_3_109254(void);
void fn_3_10952C(void);
u32 fn_3_109CE8(struct UnkRecord3448* rec);
struct UnkRecord3448* fn_3_109D88(void);
void fn_3_109DE0(struct UnkRecord3448* rec);
void fn_3_10A01C(void);
void fn_3_10A0A0(void);
void fn_3_10AD48(void);
void fn_3_10AE18(void);
void fn_3_10AEF0(void);
void fn_3_10B200(void);
void fn_3_10B27C(void);
void fn_3_10B8D0(void);
void fn_3_10BE7C(void);
void fn_3_10C450(int player, int charID);
void fn_3_10C58C(void);
void fn_3_10C7A4(void);
void fn_3_10C81C(void);
void fn_3_10CC20(void);
void fn_3_10E60C(void);
void fn_3_10EFAC(void);
void fn_3_10F1D4(void);
void fn_3_10F3D8(void);
void fn_3_10F550(u8, s16);
s32 fn_3_10F564(void);
void fn_3_10F5BC(void);
void fn_3_10F684(void);
void fn_3_10F91C(void);
void fn_3_10FB74(void);
void fn_3_10FBE4(void);
void fn_3_10FDC8(void);
void fn_3_1104A8(void);
void fn_3_1104D4(void);

#endif // !__GAME_rep_31A0_H_
