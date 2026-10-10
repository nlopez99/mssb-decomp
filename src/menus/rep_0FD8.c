#include "menus/rep_0FD8.h"
#include "menus/rep_0318.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"

extern void changeScene(u8, s16);
extern void fn_2_11A0(s32 arg0);
extern void fn_8004A0FC(void);
extern void fn_8003F23C(void);
extern void fn_80021228(u8 mode);
extern void fn_80062764(void* task);

typedef struct Unk0FD8 {
    /* 0x00 */ u8 _00[0x3B];
    /* 0x3B */ u8 _3B;
} Unk0FD8;

extern Unk0FD8* fn_8006C0D0(void);

typedef struct State0FD8 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u16 _10;
    /* 0x12 */ u8 _12[0x18 - 0x12];
    /* 0x18 */ u16 _18;
} State0FD8;

extern State0FD8 lbl_2_bss_340234;
extern struct {
    /* 0x0 */ u8 inningSetting;
} gameInitOptions;
extern struct {
    /* 0x00 */ u8 _00[0x3E];
    /* 0x3E */ u8 _3E;
} lbl_803C5F04;
extern struct {
    /* 0x00 */ u8 _00;
} lbl_803C50E8;
extern struct {
    /* 0x00 */ u8 _00[0x1F];
    /* 0x1F */ u8 _1F;
} lbl_80366158;
extern struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ u16 _4;
    /* 0x06 */ u16 _6;
}* lbl_803CBBCC;
extern struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
}* lbl_803CC1B8;

u8 lbl_2_bss_B2C4[0x37C];
Unk0FD8* lbl_2_bss_B2C0;

// .text:0x0008EEC8 size:0x22C
void fn_2_8EEC8(void) {
    State0FD8* state = &lbl_2_bss_340234;

    switch (state->_10) {
    case 0:
        if (lbl_803CBBCC->_6 != 5) {
            fn_80062764(lbl_803CC1B8);
        }
        lbl_2_bss_B2C0 = fn_8006C0D0();
        state->_10 = 1;
        break;
    case 1:
        switch (lbl_2_bss_B2C0->_3B) {
        case 1:
            break;
        case 2:
            lbl_2_bss_B2C0->_3B = 0;
            state->_10 = 2;
            break;
        case 3:
            lbl_2_bss_B2C0->_3B = 0;
            state->_10 = 3;
            break;
        }
        break;
    case 2:
        fn_2_8EDC4();
        break;
    case 3:
        fn_2_8ED4C();
        changeScene(4, 6);
        fn_2_11A0(4);
        break;
    }
}

// .text:0x0008EDC4 size:0x104
void fn_2_8EDC4(void) {
    State0FD8* state = &lbl_2_bss_340234;
    s16 mode;

    switch (state->_18) {
    case 0:
        if (lbl_803C50E8._00 == 0) {
            lbl_80366158._1F = 1;
            fn_8003F23C();
            state->_18++;
            break;
        }
    case 1:
        if (lbl_803C50E8._00 == 0) {
            mode = lbl_803CC1B8->_10;
            if (mode == 1 || mode == 11) {
                if (mode != 1) {
                    fn_80021228(OSGetSoundMode());
                }
                lbl_803C50E8._00 = 1;
                state->_18++;
            }
            break;
        }
    case 2:
        state->_18 = 0;
        lbl_2_bss_340234._10 = 0;
        fn_2_11A0(5);
        break;
    }
}

// .text:0x0008ED4C size:0x78
void fn_2_8ED4C(void) {
    g_d_GameSettings._10 = 2;
    g_d_GameSettings.home_AwaySetting = 0;
    fn_2_2FC0(9, 0, 1);
    fn_8004A0FC();
    lbl_803C5F04._3E = 0;
    fn_8004A0FC();
    gameInitOptions.inningSetting = 3;
    g_d_GameSettings.GameModeSelected = 4;
}
