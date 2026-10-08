#include "game/rep_1720.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_16B8.h"
#include "string.h"

extern struct {
    /* 0x000 */ s32 _000;
    /* 0x004 */ u8 _004[0x1D1 - 0x4];
    /* 0x1D1 */ u8 _1D1;
    /* 0x1D2 */ u8 _1D2;
} lbl_3_common_bss_34C90;

extern struct {
    /* 0x00 */ u8 _00[0xAA];
    /* 0xAA */ u8 _AA;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x0000 */ u8 _0000[0xCFA2];
    /* 0xCFA2 */ u8 _CFA2[4];
} lbl_803297E0;

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
    /* 0x27 */ u8 _27;
} lbl_8034E978;

extern void fn_80053FE8(void);
extern void fn_800486E0(int, s8, u8);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);

#define SET_SCREEN(id)                                                                                                 \
    lbl_8034E978._00 = (id);                                                                                           \
    lbl_8034E978._09 = lbl_8034E978._08;                                                                               \
    lbl_8034E978._08 = lbl_800FEF70[(id)]._08

// .text:0x00099064 size:0x344 mapped:0x806D80F8
void fn_3_99064(void) {
    if ((lbl_3_common_bss_34C90._1D1 == 2 || lbl_3_common_bss_34C90._1D1 == 9) && lbl_3_common_bss_34C90._1D2 == 0) {
        if (lbl_3_common_bss_32724._AA == 0) {
            fn_800B0A5C_insertQueue(fn_3_98DE0, 2);
        }
        fn_800B0A5C_insertQueue(fn_3_9894C, 2);
    }
    if (lbl_3_common_bss_34C90._1D1 == 4 || lbl_3_common_bss_34C90._1D1 == 11 || lbl_3_common_bss_34C90._1D1 == 14 ||
        lbl_3_common_bss_34C90._1D1 == 7 || lbl_3_common_bss_34C90._1D1 == 8 || lbl_3_common_bss_34C90._1D1 == 15) {
        fn_3_98EA8();
    }
    if ((lbl_3_common_bss_34C90._1D1 == 6 || lbl_3_common_bss_34C90._1D1 == 13) && lbl_3_common_bss_34C90._1D2 == 2) {
        fn_800B0A5C_insertQueue(fn_3_983B8, 2);
    }
    if ((lbl_3_common_bss_34C90._1D1 == 12 || lbl_3_common_bss_34C90._1D1 == 5) && lbl_3_common_bss_34C90._1D2 == 1) {
        fn_800B0A5C_insertQueue(fn_80053FE8, 0);
        if (g_d_GameSettings.GameModeSelected != GAME_TYPE_CHALLENGE) {
            SET_SCREEN(9);
        } else {
            SET_SCREEN(27);
        }
        fn_800B0A5C_insertQueue(fn_3_97CEC, 2);
    }
}

// .text:0x00098EA8 size:0x1BC mapped:0x806D7F3C
void fn_3_98EA8(void) {
    if (lbl_3_common_bss_34C90._1D2 == 2) {
        fn_800B0A5C_insertQueue(fn_80053FE8, 2);
        memset(&lbl_8034E978, 0, sizeof(lbl_8034E978));
        switch (lbl_803297E0._CFA2[lbl_3_common_bss_34C90._000]) {
        case 0:
            SET_SCREEN(g_d_GameSettings.GameModeSelected == GAME_TYPE_CHALLENGE ? 28 : 8);
            break;
        case 1:
            SET_SCREEN(10);
            break;
        case 2:
            SET_SCREEN(30);
            break;
        case 3:
            SET_SCREEN(31);
            break;
        }
        fn_800486E0(0, g_GameLogic.teams[lbl_3_common_bss_34C90._000], lbl_3_common_bss_34C90._000);
    }
    if (lbl_3_common_bss_34C90._1D2 == 5) {
        lbl_8034E978._26 = 1;
    }
}
