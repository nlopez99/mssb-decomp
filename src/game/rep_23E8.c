#include "game/rep_23E8.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "game/rep_1E08.h"
#include "static/UnknownHomes_Static.h"

typedef struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u16 _12;
} UnkTask23E8;

typedef struct {
    /* 0x000 */ u8 _000[0x3AC];
    /* 0x3AC */ u32 _3AC;
    /* 0x3B0 */ u8 _3B0[0x3E8 - 0x3B0];
    /* 0x3E8 */ f32 _3E8;
    /* 0x3EC */ f32 _3EC;
    /* 0x3F0 */ f32 _3F0;
    /* 0x3F4 */ f32 _3F4;
    /* 0x3F8 */ f32 _3F8;
    /* 0x3FC */ f32 _3FC;
    /* 0x400 */ u8 _400[0x404 - 0x400];
    /* 0x404 */ s16 _404;
    /* 0x406 */ u8 _406[0x40A - 0x406];
    /* 0x40A */ u8 _40A;
    /* 0x40B */ u8 _40B[0x479 - 0x40B];
    /* 0x479 */ u8 _479;
} Unk23E8State;

extern Unk23E8State lbl_3_common_bss_35154;

extern UnkTask23E8* lbl_803CC1B8;

extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), u16);

// .text:0x000CB7E8 size:0xC0 mapped:0x8070A87C
void fn_3_CB7E8(f32 x, f32 y, f32 z) {
    lbl_3_common_bss_35154._3E8 = x;
    lbl_3_common_bss_35154._3EC = y;
    lbl_3_common_bss_35154._3F0 = z;
    lbl_3_common_bss_35154._3F4 = lbl_3_common_bss_35154._3F8 = lbl_3_common_bss_35154._3FC = 0.0f;
    lbl_3_common_bss_35154._404 = 80;
    lbl_3_common_bss_35154._40A = 1;
    lbl_3_common_bss_35154._3AC |= 4;
    fn_800B0A5C_insertQueue(fn_3_CB738, lbl_803CC1B8->_12 + 1);
    playSoundEffect(0x19D);
    if (g_GameLogic.TeamStars[g_GameLogic.teamBatting] < 5) {
        g_GameLogic.TeamStars[g_GameLogic.teamBatting]++;
    }
    g_GameLogic.stadiumStarObtained = 1;
}

// .text:0x000CB7D4 size:0x14 mapped:0x8070A868
void fn_3_CB7D4(void) {
    lbl_3_common_bss_35154._404 = 0;
}

// .text:0x000CB738 size:0x9C mapped:0x8070A7CC
void fn_3_CB738(void) {
    Unk23E8State* state = &lbl_3_common_bss_35154;

    if (g_d_GameSettings._55 != 0 || state->_479 != 0 || state->_404-- == 0) {
        state->_40A = 0;
        fn_800B0A14_removeQueue();
    } else {
        fn_3_BD8D8();
        state->_3EC += -0.03125f;
        state->_3F8 += 0.15707964f;
    }
}
