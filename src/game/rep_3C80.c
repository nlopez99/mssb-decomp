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

typedef struct {
    /* 0x000 */ Unk3C80Glow _000;
    /* 0x050 */ Unk3C80Burst _050;
    /* 0x0A4 */ Unk3C80Trail _0A4;
    /* 0x0F4 */ Unk3C80Burst _0F4;
    /* 0x148 */ s32 _148[3];
} Unk3C80Effects;

// .data outside this unit's split
extern Unk3C80Effects lbl_3_data_27D58;

#define PACK_RGB(r, g, b) ((((r) & 0xFF) << 24) | (((g) & 0xFF) << 16) | (((b) & 0xFF) << 8))

extern u8 lbl_800FC0FC[][3];

extern void fn_8002955C(Vec* pos, s32 arg1, Unk3C80Burst* burst);
extern void fn_80030D88(Vec* pos, Vec* vel, Unk3C80Trail* trail, s32 arg3);
extern void fn_80031CA4(Vec* pos, Unk3C80Glow* glow);
extern s32 fn_8004AD54(u8 stadium, s32 type);
extern void fn_80064344(Vec* pos, Vec* vel);

// .text:0x0015F648 size:0x22C mapped:0x8079E6DC
// The target reaches lbl_3_data_27D58 from a pool base: it is five statics of this file
// (0x50, 0x54, 0x50, 0x54 and an s32 array at 0x148), outside this unit's split. Defined
// as statics, this code differs only in that base symbol.
void fn_3_15F648(s32 type, s32 mode, Vec* pos, Vec* vel) {
    Unk3C80Effects* fx = &lbl_3_data_27D58;
    s32 kind;

    switch (type) {
    case 10:
        fn_80064344(pos, vel);
        break;
    default:
        if (mode == 1) {
            if (PSVECMag(vel) >= fx->_148[1] / 100000.0f) {
                fx->_050._00 = lbl_3_common_bss_35154._004;
                fx->_0A4._00 = lbl_3_common_bss_35154._004;
                fn_8002955C(pos, 0, &fx->_050);
                fn_80030D88(pos, vel, &fx->_0A4, 5);
            }
        } else {
            kind = fn_8004AD54(g_d_GameSettings.StadiumID, type);
            if (PSVECMag(vel) >= fx->_148[0] / 100000.0f) {
                fx->_000._00 = lbl_3_common_bss_35154._004;
                fx->_000._40 = PACK_RGB(lbl_800FC0FC[kind][0], lbl_800FC0FC[kind][1], lbl_800FC0FC[kind][2]);
                fn_80031CA4(pos, &fx->_000);
            }
            if (PSVECMag(vel) >= fx->_148[2] / 100000.0f) {
                switch (kind) {
                case 1:
                case 3:
                case 7:
                    fx->_0F4._00 = lbl_3_common_bss_35154._004;
                    fn_8002955C(pos, 0, &fx->_0F4);
                    break;
                }
            }
        }
        break;
    }
}
