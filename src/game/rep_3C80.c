#include "game/rep_3C80.h"
#include "header_rep_data.h"
#include "Dolphin/vec.h"
#include "static/UnknownHomes_Static.h"

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[15];
    /* 0x40 */ u32 _40;
    /* 0x44 */ s32 _44[3];
} Unk3C80Glow; // size: 0x50

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[20];
} Unk3C80Burst; // size: 0x54

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[19];
} Unk3C80Trail; // size: 0x50

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ s32 _004;
} lbl_3_common_bss_35154;

#define PACK_RGB(r, g, b) ((((r) & 0xFF) << 24) | (((g) & 0xFF) << 16) | (((b) & 0xFF) << 8))

extern u8 lbl_800FC0FC[][3];

extern void fn_8002955C(Vec* pos, s32 arg1, Unk3C80Burst* burst);
extern void fn_80030D88(Vec* pos, Vec* vel, Unk3C80Trail* trail, s32 arg3);
extern void fn_80031CA4(Vec* pos, Unk3C80Glow* glow);
extern s32 fn_8004AD54(u8 stadium, s32 type);
extern void fn_80064344(Vec* pos, Vec* vel);

static Unk3C80Glow lbl_3_data_27D58 = {
    0, { 4, 10, 70000, 30000, 78000, 30, 10, 109000, 101000, 0, 30, 12800000, 0, 0, 0 }, 0, { 0xFFFFFF00, 0, 75000 },
};
static Unk3C80Burst lbl_3_data_27DA8 = {
    0, { 2, 30, 20, 40, 10000, 20000, 0, 0, 50000, 60000, 10, 0xFF000080, 16, 16, 1, 0, 0, 0, 0, 0 },
};
static Unk3C80Trail lbl_3_data_27DFC = {
    0, { 4, 10, 80000, 90000, 50000, 30, 10, 104000, 105999, 0, 60, 12800000, 10000000, 1000000, 6000000, 0x3C3C3C00, 0, 0, 0 },
};
static Unk3C80Burst lbl_3_data_27E4C = {
    0, { 29, 15, 20, 30, 13000, 15000, -3000000, 3000000, 50000, 60000, 0, -1, 5, 10, 0, 0, 0, 0, 0, 1 },
};
static s32 lbl_3_data_27EA0[8] = { 30000, 30000, 24000 };

// .text:0x0015F648 size:0x22C mapped:0x8079E6DC
void fn_3_15F648(s32 type, s32 mode, Vec* pos, Vec* vel) {
    s32 kind;

    switch (type) {
    case 10:
        fn_80064344(pos, vel);
        break;
    default:
        if (mode == 1) {
            if (PSVECMag(vel) >= lbl_3_data_27EA0[1] / 100000.0f) {
                lbl_3_data_27DA8._00 = lbl_3_common_bss_35154._004;
                lbl_3_data_27DFC._00 = lbl_3_common_bss_35154._004;
                fn_8002955C(pos, 0, &lbl_3_data_27DA8);
                fn_80030D88(pos, vel, &lbl_3_data_27DFC, 5);
            }
        } else {
            kind = fn_8004AD54(g_d_GameSettings.StadiumID, type);
            if (PSVECMag(vel) >= lbl_3_data_27EA0[0] / 100000.0f) {
                lbl_3_data_27D58._00 = lbl_3_common_bss_35154._004;
                lbl_3_data_27D58._40 = PACK_RGB(lbl_800FC0FC[kind][0], lbl_800FC0FC[kind][1], lbl_800FC0FC[kind][2]);
                fn_80031CA4(pos, &lbl_3_data_27D58);
            }
            if (PSVECMag(vel) >= lbl_3_data_27EA0[2] / 100000.0f) {
                switch (kind) {
                case 1:
                case 3:
                case 7:
                    lbl_3_data_27E4C._00 = lbl_3_common_bss_35154._004;
                    fn_8002955C(pos, 0, &lbl_3_data_27E4C);
                    break;
                }
            }
        }
        break;
    }
}
