#include "game/rep_2390.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08[18];
} Unk2390Trail; // size: 0x50

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[16];
} Unk2390Spark; // size: 0x44

typedef struct {
    /* 0x000 */ u8 _000[0x25A];
    /* 0x25A */ u8 _25A;
} Unk2390Actor;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ Unk2390Actor* _2C50[13];
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ s32 _004;
    /* 0x008 */ u8 _008[0x440 - 0x8];
    /* 0x440 */ Vec _440;
    /* 0x44C */ Vec _44C;
} lbl_3_common_bss_35154;

extern u16 lbl_3_data_6660[][2];

static Unk2390Trail lbl_3_data_17DC0[4][3] = {
    {
        { 0, 0x15, { 5, 0x445C0, 0, 0, 4, 2, 0x1D4C0, 0x15F90, 0, 0x80, 0xF4240, 0xF4240, 0xFFF85EE0, 0x7A120, 0xFFFFFF00, 0, 0xFFFF92A0, 1 } },
        { 0, 7, { 10, 0x130B0, 0xEA60, 0xC350, 12, 6, 0x1A9C8, 0x18A88, 0, 0x28, 0x44AA20, 0x90F560, 0xFFF0BDC0, 0x44AA20, 0xFFFFFF00, 0, 0, 0 } },
        { 0, 4, { 3, 0x15F90, 0x186A0, 0x2710, 0x14, 10, 0x19258, 0x19E0F, 0, 0x3C, 0x989680, 0x112A880, 0xF4240, 0xFFF0BDC0, 0x3C3C3C00, 0, 0, 0 } },
    },
    {
        { 0, 0x15, { 5, 0x445C0, 0, 0, 4, 2, 0x1D4C0, 0x15F90, 0, 0x80, 0x7A120, 0xF4240, 0xFFF85EE0, 0x7A120, 0xFFFFFF00, 0, 0xFFFF92A0, 1 } },
        { 0, 7, { 10, 0x130B0, 0xEA60, 0xC350, 12, 6, 0x1A9C8, 0x18A88, 0, 0x28, 0x44AA20, 0x90F560, 0xFFF0BDC0, 0x44AA20, 0xFFFFFF00, 0, 0, 0 } },
        { 0, 4, { 3, 0x15F90, 0x186A0, 0x2710, 0x14, 10, 0x19258, 0x19E0F, 0, 0x3C, 0x989680, 0x112A880, 0xF4240, 0xFFF0BDC0, 0x3C3C3C00, 0, 0, 0 } },
    },
    {
        { 0, 0x15, { 5, 0x55730, 0, 0, 4, 2, 0x1D4C0, 0x15F90, 0, 0x3C, 0x7A120, 0xF4240, 0xFFF85EE0, 0x7A120, 0xFFFFFF00, 0, 0xFFFF3CB0, 1 } },
        { 0, 7, { 10, 0x11170, 0x13880, 0xC350, 0x14, 10, 0x1A9C8, 0x1ADB0, 0, 0x28, 0x44AA20, 0x895440, 0xFFBB55E0, 0x44AA20, 0xFFFFFF00, 0, 0, 0 } },
        { 0, 4, { 5, 0x15F90, 0x186A0, 0x2710, 0x14, 10, 0x19258, 0x19E0F, 0, 0x3C, 0x989680, 0x112A880, 0x44AA20, 0xFFBB55E0, 0x3C3C3C00, 0, 0, 0 } },
    },
    {
        { 0, 0x15, { 3, 0x222E0, 0, 0, 0x10, 2, 0x1D4C0, 0x15F90, 0, 0x80, 0xF4240, 0xF4240, 0xFFF85EE0, 0x7A120, 0xFFFFFF00, 0, 0xFFFF92A0, 1 } },
        { 0, 7, { 10, 0x9858, 0x7530, 0xC350, 12, 6, 0x1A9C8, 0x18A88, 0, 0x28, 0x44AA20, 0x90F560, 0xFFF0BDC0, 0x44AA20, 0xFFFFFF00, 0, 0, 0 } },
        { 0, 4, { 3, 0xAFC8, 0xC350, 0x2710, 0x14, 10, 0x19258, 0x19E0F, 0, 0x3C, 0x989680, 0x112A880, 0xF4240, 0xFFF0BDC0, 0x3C3C3C00, 0, 0, 0 } },
    },
};
Unk2390Spark lbl_3_data_18180[3] = {
    { 0, { 0x14, 8, 7, 0x3D090, 0xC350, 0x86470, 0, 0, 12, 13, 14, 15, 16, 17, 18, 19 } },
    { 0, { 0x14, 8, 7, 0x3D090, 0xC350, 0x86470, 0, 0, 12, 13, 14, 15, 16, 17, 18, 19 } },
    { 0, { 0x14, 8, 7, 0x493E0, 0x186A0, 0x86470, 0, 0, 12, 13, 14, 15, 16, 17, 18, 19 } },
};
static Vec lbl_3_data_1824C = { 0.0f, 0.0f, 1.0f };
static Vec lbl_3_data_18258 = { 0.0f, 0.0f, -0.2f };

extern void fn_8002F5F4(Vec* pos, Vec* dir, Unk2390Spark* spark);
extern void fn_80030470(Vec* pos, Vec* dir, Vec* back, Unk2390Trail* trail, s32 n);
extern void fn_80030D88(Vec* pos, Vec* dir, Unk2390Trail* trail, s32 n);

// .text:0x000CB538 size:0x17C mapped:0x8070A5CC
void fn_3_CB538(s32 type) {
    Vec dir;
    Vec back;
    s32 state;
    s32 i;

    if (g_GameLogic.bOD_framesInLiveBallScene >= 0) {
        state = 2;
    } else {
        state = g_Ball.framesSinceHit > 0;
    }
    PSVECSubtract(&lbl_3_common_bss_35154._44C, &lbl_3_common_bss_35154._440, &dir);
    if (PSVECMag(&dir)) {
        lbl_3_data_17DC0[state][0]._00 = lbl_3_data_17DC0[state][1]._00 = lbl_3_data_17DC0[state][2]._00 =
            lbl_3_data_18180[state]._00 = lbl_3_common_bss_35154._004;
        if (type == 2) {
            lbl_3_data_17DC0[state][0]._04 = 0x1B;
            lbl_3_data_17DC0[state][1]._04 = 0x1C;
        } else {
            lbl_3_data_17DC0[state][0]._04 = 0x15;
            lbl_3_data_17DC0[state][1]._04 = 7;
        }
        fn_8002F5F4(&lbl_3_common_bss_35154._440, &dir, &lbl_3_data_18180[state]);
        if (lbl_80366158._28 == 0) {
            for (i = 1; i < 3; i++) {
                fn_80030D88(&lbl_3_common_bss_35154._440, &dir, &lbl_3_data_17DC0[state][i], 5);
            }
            PSVECNormalize(&dir, &dir);
            PSVECSubtract(&lbl_3_common_bss_35154._440, &lbl_3_common_bss_35154._44C, &back);
            fn_80030470(&lbl_3_common_bss_35154._440, &dir, &back, &lbl_3_data_17DC0[state][0], 5);
        }
    }
}

// .text:0x000CB3AC size:0x18C mapped:0x8070A440
void fn_3_CB3AC(void) {
    Vec pos;
    Unk2390Actor* actor = lbl_8036E548._2C50[0];
    s32 i;
    u16 anim;

    if (PSVECMag(&lbl_3_data_1824C) && actor != NULL) {
        lbl_3_data_17DC0[3][0]._00 = lbl_3_data_17DC0[3][1]._00 = lbl_3_data_17DC0[3][2]._00 = lbl_3_common_bss_35154._004;
        lbl_3_data_17DC0[3][0]._04 = 0x15;
        lbl_3_data_17DC0[3][1]._04 = 7;
        anim = 0x1A;
        if (actor->_25A) {
            i = 0;
            do {
                if (lbl_3_data_6660[i][0] == 0x1A) {
                    anim = lbl_3_data_6660[i][1];
                    break;
                }
                if (lbl_3_data_6660[i][1] == 0x1A) {
                    anim = lbl_3_data_6660[i][0];
                    break;
                }
            } while (lbl_3_data_6660[++i][0] != 0xFFFF);
        }
        getAnimRelatedCoordinates(0, anim, (VecXYZ*)&pos);
        PSVECAdd(&pos, &lbl_3_data_18258, &pos);
        if (lbl_80366158._28 == 0) {
            fn_80030D88(&pos, &lbl_3_data_1824C, &lbl_3_data_17DC0[3][1], 5);
            fn_80030D88(&pos, &lbl_3_data_1824C, &lbl_3_data_17DC0[3][2], 5);
            fn_80030470(&pos, &lbl_3_data_1824C, &lbl_3_data_1824C, &lbl_3_data_17DC0[3][0], 5);
        }
    }
}
