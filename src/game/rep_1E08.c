#include "game/rep_1E08.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"

#include "game/rep_1F58.h"
#include "game/rep_1FD8.h"
#include "game/rep_2308.h"
#include "game/sta_c2.h"
#include "game/sta_c4.h"

typedef struct {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u16 _12;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
    /* 0x18 */ s16 _18;
} UnkTask1E08;

typedef struct {
    /* 0x000 */ UnkTask1E08* _000;
    /* 0x004 */ u8 _004[0x8 - 0x4];
    /* 0x008 */ void* _008;
    /* 0x00C */ u8 _00C[0x3AC - 0xC];
    /* 0x3AC */ u32 _3AC;
    /* 0x3B0 */ u8 _3B0;
    /* 0x3B1 */ u8 _3B1[0x40C - 0x3B1];
    /* 0x40C */ s32 _40C[3];
    /* 0x418 */ u8 _418;
    /* 0x419 */ s8 _419;
    /* 0x41A */ u8 _41A[0x41C - 0x41A];
    /* 0x41C */ Vec _41C;
    /* 0x428 */ u8 _428[0x466 - 0x428];
    /* 0x466 */ u8 _466;
    /* 0x467 */ u8 _467[0x479 - 0x467];
    /* 0x479 */ u8 _479;
    /* 0x47A */ u8 _47A[0x480 - 0x47A];
} Unk1E08State; // size: 0x480

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
} UnkPair1E08; // size: 0x8

extern Unk1E08State lbl_3_common_bss_35154;

extern struct {
    /* 0x0000 */ u8 _0000[0x70];
    /* 0x0070 */ void* _0070;
    /* 0x0074 */ u8 _0074[0xC60 - 0x74];
    /* 0x0C60 */ struct {
        /* 0x000 */ s32 _000;
        /* 0x004 */ u8 _004[0x27C - 0x4];
    } _0C60[13];
    /* 0x2CAC */ u8 _2CAC[0x3070 - 0x2CAC];
    /* 0x3070 */ void (*_3070)(void);
    /* 0x3074 */ void (*_3074)(s32);
} lbl_8036E548;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern UnkTask1E08* lbl_803CC1B8;

// .data outside this unit's range in splits.txt
extern UnkPair1E08 lbl_3_data_111C8[];
extern u8 lbl_3_data_11380[0x10];
extern void (*lbl_3_data_11390[])(s32);
extern u8 lbl_3_data_1146C[0x190];
extern s32 lbl_3_data_17000[0x36];
extern s32 lbl_3_data_170D8[6];

static f32 lbl_3_bss_9978[0xEA];
static Vec lbl_3_bss_996C;
static s32 lbl_3_bss_9968;
static f32 lbl_3_bss_9964;
static s32 lbl_3_bss_9960;
static u8 lbl_3_bss_995C;
static s16 lbl_3_bss_9952[5];
static u8 lbl_3_bss_9950;

extern void* ARAMTransfer(void* entry, int arg1, int arg2, u32 aram);
extern UnkTask1E08* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80034CEC(UnkTask1E08* task);
extern void fn_80034E20(UnkTask1E08* task, void* desc);
extern void fn_8003A688(void* arg0, f32 x, f32 y);
extern BOOL fn_80033928(s32 arg0);
extern void* fn_80033A24(void (*update)(void), s32, s32, s32, s32, s32);
extern void fn_800BD670(void* arg0, s32 arg1);
extern void fn_8006C43C(s32 arg0);
extern void fn_8006C3F0(s32 arg0);
extern void pitchingMachinePitching(u8 id);
extern void minigamesSetSomePointers(void);

// .text:0x000C07B0 size:0x60 mapped:0x806FF844
void fn_3_C07B0(void) {
    if (fn_80033928(0x10) || fn_80033A24(fn_3_C0134, 0x80, 0, 0, 0, 0x10) != NULL) {
        lbl_3_bss_995C = 0;
    }
}

// .text:0x000C07A0 size:0x10 mapped:0x806FF834
void fn_3_C07A0(void) {
    lbl_3_bss_995C = 3;
}

// .text:0x000C0770 size:0x30 mapped:0x806FF804
void fn_3_C0770(void) {
    pitchingMachinePitching(0x10);
    lbl_3_bss_9952[0] = 0;
}

// .text:0x000C0134 size:0x63C mapped:0x806FF1C8
void fn_3_C0134(void) {
    return;
}

// .text:0x000BFDA4 size:0x390 mapped:0x806FEE38
f32 fn_3_BFDA4(struct UnkKey21F8* keys, int count, int frame, u8 current, u8* currentOut, f32 t) {
    return 0.0f;
}

// .text:0x000BFB3C size:0x268 mapped:0x806FEBD0
void fn_3_BFB3C(void) {
    return;
}

// .text:0x000BF8F8 size:0x244 mapped:0x806FE98C
void fn_3_BF8F8(struct UnkEffect21F8* effect, Mtx m, Vec* pos,
                 f32 (*callback)(struct UnkAnim21F8*, int, Mtx, f32)) {
    return;
}

// .text:0x000BF878 size:0x80 mapped:0x806FE90C
BOOL fn_3_BF878(void) {
    if (lbl_803C6CF8._715 == 1) {
        lbl_3_common_bss_35154._008 = ARAMTransfer(lbl_3_data_11380, 0, 0, 0);
        fn_800B0A5C_insertQueue(fn_3_BF6C0, 0);
        lbl_3_common_bss_35154._3B0 = 1;
        return TRUE;
    }
    return FALSE;
}

// .text:0x000BF6C0 size:0x1B8 mapped:0x806FE754
void fn_3_BF6C0(void) {
    return;
}

// .text:0x000BF238 size:0x488 mapped:0x806FE2CC
void fn_3_BF238(void) {
    return;
}

// .text:0x000BF20C size:0x2C mapped:0x806FE2A0
void fn_3_BF20C(void) {
    fn_8006C43C(0);
    fn_8006C3F0(0);
}

// .text:0x000BF1AC size:0x60 mapped:0x806FE240
void fn_3_BF1AC(void) {
    s32 i;

    minigamesSetSomePointers();
    fn_3_C0854();
    fn_3_CABB4();
    i = 12;
    do {
        lbl_8036E548._0C60[i]._000 = 0;
    } while (i-- != 0);
    lbl_3_common_bss_35154._479 = 1;
}

// .text:0x000BF158 size:0x54 mapped:0x806FE1EC
void fn_3_BF158(void) {
    u8 stadium = g_d_GameSettings.StadiumID;

    if (stadium == 1) {
        fn_3_C39C8();
    } else if (stadium == 2) {
        fn_3_CE8E4();
    } else if (stadium == 4) {
        fn_3_F8ABC();
    }
}

// .text:0x000BF070 size:0xE8 mapped:0x806FE104
void fn_3_BF070(void) {
    return;
}

// .text:0x000BEFF8 size:0x78 mapped:0x806FE08C
void fn_3_BEFF8(void) {
    UnkTask1E08* task = lbl_803CC1B8;

    lbl_3_common_bss_35154._000 = task;
    fn_80034E20(task, lbl_3_data_1146C);
    task->_18 = 0;
    lbl_803CC1B8->_00 = fn_3_BE1D4;
    lbl_3_common_bss_35154._3AC = 0;
}

// .text:0x000BE1D4 size:0xE24 mapped:0x806FD268
void fn_3_BE1D4(void) {
    return;
}

// .text:0x000BE174 size:0x60 mapped:0x806FD208
void fn_3_BE174(s32 type, f32 x, f32 y, f32 z) {
    lbl_3_common_bss_35154._3AC |= 1;
    lbl_3_common_bss_35154._41C.x = x;
    lbl_3_common_bss_35154._41C.y = y;
    lbl_3_common_bss_35154._41C.z = z;
    lbl_3_common_bss_35154._419 = type;
    if (type == 4) {
        fn_3_BE140();
    }
}

// .text:0x000BE140 size:0x34 mapped:0x806FD1D4
void fn_3_BE140(void) {
    UnkTask1E08* task = fn_800B0A5C_insertQueue(fn_3_BDF74, 3);
    task->_10 = 2;
}

// .text:0x000BDF74 size:0x1CC mapped:0x806FD008
void fn_3_BDF74(void) {
    return;
}

// .text:0x000BDE14 size:0x160 mapped:0x806FCEA8
void fn_3_BDE14(void) {
    return;
}

// .text:0x000BDCA4 size:0x170 mapped:0x806FCD38
void fn_3_BDCA4(void) {
    return;
}

// .text:0x000BD8FC size:0x3A8 mapped:0x806FC990
void fn_3_BD8FC(void) {
    return;
}

// .text:0x000BD8D8 size:0x24 mapped:0x806FC96C
void fn_3_BD8D8(void) {
    lbl_8036E548._3070 = fn_3_BD80C;
    lbl_8036E548._3074 = fn_3_BD7DC;
}

// .text:0x000BD80C size:0xCC mapped:0x806FC8A0
void fn_3_BD80C(void) {
    return;
}

// .text:0x000BD7DC size:0x30 mapped:0x806FC870
void fn_3_BD7DC(s32 arg0) {
    fn_800BD670(lbl_8036E548._0070, arg0);
}

// .text:0x000BD7D8 size:0x4 mapped:0x806FC86C
void fn_3_BD7D8(void) {
    return;
}

// .text:0x000BD7D0 size:0x8 mapped:0x806FC864
BOOL fn_3_BD7D0(void) {
    return TRUE;
}

// .text:0x000BD758 size:0x78 mapped:0x806FC7EC
void fn_3_BD758(void) {
    UnkTask1E08* task = lbl_803CC1B8;

    if (lbl_803C6CF8._715 == 1) {
        lbl_3_common_bss_35154._418 = 0;
        lbl_3_data_11390[task->_14](lbl_3_common_bss_35154._40C[task->_16]);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000BD6AC size:0xAC mapped:0x806FC740
void fn_3_BD6AC(s32 arg0, f32 x, f32 y, f32 z) {
    return;
}

// .text:0x000BD504 size:0x1A8 mapped:0x806FC598
void fn_3_BD504(f32 x, f32 y, f32 z, BOOL arg3) {
    return;
}

// .text:0x000BD4F0 size:0x14 mapped:0x806FC584
void fn_3_BD4F0(void) {
    lbl_3_common_bss_35154._466 = 0;
}

// .text:0x000BD434 size:0xBC mapped:0x806FC4C8
void fn_3_BD434(s32 stadium, s32 mode) {
    return;
}

// .text:0x000BD1D8 size:0x25C mapped:0x806FC26C
void fn_3_BD1D8(Mtx view) {
    return;
}

// .text:0x000BD1D4 size:0x4 mapped:0x806FC268
void fn_3_BD1D4(void) {
    return;
}

// .text:0x000BCA20 size:0x7B4 mapped:0x806FBAB4
void fn_3_BCA20(void) {
    return;
}

// .text:0x000BC888 size:0x198 mapped:0x806FB91C
void fn_3_BC888(void) {
    return;
}

// .text:0x000BC850 size:0x38 mapped:0x806FB8E4
void fn_3_BC850(void* arg0, s32 index) {
    fn_8003A688(arg0, lbl_3_data_111C8[index]._00, lbl_3_data_111C8[index]._04);
}

// .text:0x000BC6D8 size:0x178 mapped:0x806FB76C
void fn_3_BC6D8(Vec* pos, Vec* eye, int type, BOOL flag) {
    return;
}

// .text:0x000BC2DC size:0x3FC mapped:0x806FB370
void fn_3_BC2DC(void) {
    return;
}

// .text:0x000BC274 size:0x68 mapped:0x806FB308
void fn_3_BC274(void) {
    return;
}

// .text:0x000BC25C size:0x18 mapped:0x806FB2F0
void fn_3_BC25C(void) {
    lbl_3_common_bss_35154._3AC |= 0x40;
}

// .text:0x000BC224 size:0x38 mapped:0x806FB2B8
void fn_3_BC224(void) {
    fn_80034CEC(lbl_3_common_bss_35154._000);
    lbl_3_common_bss_35154._000 = NULL;
}

// .text:0x000BBF94 size:0x290 mapped:0x806FB028
void fn_3_BBF94(void) {
    return;
}

// .text:0x000BBBC4 size:0x3D0 mapped:0x806FAC58
void fn_3_BBBC4(void) {
    return;
}

// .text:0x000BB7F4 size:0x3D0 mapped:0x806FA888
void fn_3_BB7F4(void) {
    return;
}

// .text:0x000BB454 size:0x3A0 mapped:0x806FA4E8
void fn_3_BB454(void) {
    return;
}

// .text:0x000BB15C size:0x2F8 mapped:0x806FA1F0
void fn_3_BB15C(void) {
    return;
}

// .text:0x000BB07C size:0xE0 mapped:0x806FA110
void fn_3_BB07C(void) {
    return;
}

// .text:0x000BA7F4 size:0x888 mapped:0x806F9888
void fn_3_BA7F4(void) {
    return;
}

// .text:0x000BA538 size:0x2BC mapped:0x806F95CC
void fn_3_BA538(void) {
    return;
}
