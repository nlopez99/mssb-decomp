#include "game/rep_3C28.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "Dolphin/mtx.h"

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[15];
} Unk3C28Trail; // size: 0x40

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ s32 _004;
    /* 0x008 */ u8 _008[0x440 - 0x8];
    /* 0x440 */ Vec _440;
    /* 0x44C */ Vec _44C;
} lbl_3_common_bss_35154;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern void fn_8002C2D0(Vec* pos, Vec* dir, Unk3C28Trail* trail);

Unk3C28Trail lbl_3_data_27C98[3] = {
    { 0, { 4, 6, 110000, 1000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xFFFFFF00, 0, 50000, 20000 } },
    { 0, { 4, 6, 110000, 1000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xFFFFFF00, 0, 50000, 20000 } },
    { 0, { 4, 6, 150000, 1000, 90000, 40, 1, 102000, 101000, 100, 2000000, 0xFFFFFF00, 0, 50000, 20000 } },
};

// .text:0x0015F574 size:0xD4 mapped:0x8079E608
void fn_3_15F574(void) {
    Vec dir;
    s32 state;

    if (g_GameLogic.bOD_framesInLiveBallScene >= 0) {
        state = 2;
    } else {
        state = g_Ball.framesSinceHit > 0;
    }

    PSVECSubtract(&lbl_3_common_bss_35154._44C, &lbl_3_common_bss_35154._440, &dir);
    if (PSVECMag(&dir)) {
        lbl_3_data_27C98[state]._00 = lbl_3_common_bss_35154._004;
        if (lbl_80366158._28 == 0) {
            fn_8002C2D0(&lbl_3_common_bss_35154._440, &dir, &lbl_3_data_27C98[state]);
        }
    }
}
