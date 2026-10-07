#include "game/rep_3D50.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
} UnkTask3D50;

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[15];
} UnkEffect3D50; // size: 0x40

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ s32 _004;
    /* 0x008 */ u8 _008[0x440 - 0x8];
    /* 0x440 */ Vec _440;
    /* 0x44C */ Vec _44C;
    /* 0x458 */ Vec _458;
    /* 0x464 */ s16 _464;
    /* 0x466 */ u8 _466;
    /* 0x467 */ u8 _467[0x479 - 0x467];
    /* 0x479 */ u8 _479;
    /* 0x47A */ u16 _47A[2];
} lbl_3_common_bss_35154;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern UnkTask3D50* lbl_803CC1B8;

// This unit's .data (0x281F0 to 0x28418) lies outside its ranges in splits.txt
extern UnkEffect3D50 lbl_3_data_281F0[8];
extern s32 lbl_3_data_283F0[2][4];
extern s32 lbl_3_data_28410[2];

static UnkTask3D50* lbl_3_bss_B9B8;

extern void fn_8002C2D0(Vec* pos, Vec* dir, UnkEffect3D50* effect);
extern void fn_800B0A14_removeQueue(void);
extern UnkTask3D50* fn_800B0A5C_insertQueue(void (*)(void), u16);

// .text:0x00160814 size:0xDC mapped:0x8079F8A8
// The target stores _15 between loading _14 and the table value, with the zero and the
// table value in swapped registers (r6 and r0), and stores _16 before _17.
void fn_3_160814(s32 type) {
    s32 time;

    if (lbl_3_common_bss_35154._464 == 0) {
        lbl_3_bss_B9B8 = fn_800B0A5C_insertQueue(fn_3_160578, lbl_803CC1B8->_12 + 1);
        lbl_3_bss_B9B8->_14 = type == 4;
        time = lbl_3_data_283F0[lbl_3_bss_B9B8->_14][0];
        lbl_3_bss_B9B8->_15 = 0;
        lbl_3_bss_B9B8->_17 = 0;
        lbl_3_bss_B9B8->_16 = time;
        lbl_3_common_bss_35154._47A[lbl_3_bss_B9B8->_14 != 0] = lbl_3_data_28410[lbl_3_bss_B9B8->_14];
    }
}

// .text:0x00160578 size:0x29C mapped:0x8079F60C
void fn_3_160578(void) {
    Vec pos;
    Vec diff;
    UnkTask3D50* task = lbl_803CC1B8;
    s32 idx;

    if (g_d_GameSettings._55 || lbl_3_common_bss_35154._479) {
        fn_800B0A14_removeQueue();
        return;
    }
    if (lbl_3_common_bss_35154._466 == 0) {
        lbl_3_bss_B9B8 = NULL;
        fn_800B0A14_removeQueue();
        return;
    }
    if (lbl_80366158._28 != 0) {
        return;
    }
    if (task->_15 == 0 && g_Ball.warioWaluGarlicIsActive) {
        task->_15 = 1;
        task->_17 = 0;
    }
    if (task->_17 != 0) {
        task->_17--;
        return;
    }
    if (task->_15 == 0) {
        idx = g_GameLogic.bOD_framesInLiveBallScene >= 0;
    } else if (task->_15 == 1) {
        task->_15 = 2;
        idx = 2;
    } else {
        idx = 3;
    }
    if (task->_14) {
        idx += 4;
    }
    PSVECSubtract(&lbl_3_common_bss_35154._44C, &lbl_3_common_bss_35154._440, &diff);
    if (PSVECMag(&diff)) {
        lbl_3_data_281F0[idx]._00 = lbl_3_common_bss_35154._004;
        fn_8002C2D0(&lbl_3_common_bss_35154._440, &diff, &lbl_3_data_281F0[idx]);
    }
    pos.x = g_Ball.warioStarHitCoords[2].x;
    pos.y = -g_Ball.warioStarHitCoords[2].y;
    pos.z = g_Ball.warioStarHitCoords[2].z;
    if (idx % 4 == 3) {
        PSVECSubtract(&lbl_3_common_bss_35154._458, &pos, &diff);
        if (PSVECMag(&diff)) {
            if (g_Ball.framesUntilBallHitsGround == lbl_3_common_bss_35154._47A[task->_14 != 0]) {
                idx--;
            }
            fn_8002C2D0(&pos, &diff, &lbl_3_data_281F0[idx]);
        }
    }
    if (task->_15 == 2) {
        memcpy(&lbl_3_common_bss_35154._458, &pos, sizeof(Vec));
    }
    task->_17 = task->_16;
    if (task->_16 != 0) {
        task->_16--;
    }
}
