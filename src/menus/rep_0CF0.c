#include "menus/rep_0CF0.h"
#include "header_rep_data.h"

extern void fn_8004A34C(void* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_8004C9FC(void);
extern void fn_8004CA08(s32 arg0);
extern void fn_80023CF4(s32 arg0);
extern void fn_2_11A0(s32 arg0);

extern struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ u16 _4;
}* lbl_803CBBCC;
extern struct {
    /* 0x00 */ u8 _00[0x45];
    /* 0x45 */ u8 _45;
} lbl_803C50E8;

// Debug menu labels and tables that no code in the module reads
char lbl_2_data_2E328[2][0x20] = { "BAT FIRST", "BAT LAST" };
char lbl_2_data_2E368[2][0x20] = { "FL", "PC" };
char lbl_2_data_2E3A8[4][4] = { "RR", "RL", "LR", "LL" };
char lbl_2_data_2E3B8[2][0x20] = { "OFF", "ON" };
char lbl_2_data_2E3F8[5][0x20] = {
    "SELECT DEBUG MENU", "HIDE CHARA SET", "STAR PLAYER SET", "KOOPA STA FLAG SET", "CHALLE LEVEL FREE SET",
};
char lbl_2_data_2E498[8][0x20] = {
    "1P >", "COM1>", "2P >", "COM2>", "3P >", "COM3>", "4P >", "COM4>",
};
u32 lbl_2_data_2E598[8] = { 0xFF0F, 0x880F, 0x0FFF, 0x088F, 0xF0FF, 0x808F, 0xF00F, 0x800F };
s16 lbl_2_data_2E5B8[12] = { 0, 4, 10, 6, 2, 9, 1, 5, 11, 17, 3, 19 };
u8 lbl_2_data_2E5D0[2][13] = {
    { 0, 2, 6, 8, 4, 10, 1, 3, 7, 5, 9, 11 },
    { 0, 6, 2, 8, 4, 10, 5, 11, 3, 9, 1, 7 },
};

// .text:0x000854B0 size:0x18C
void fn_2_854B0(void) {
    s32 next;

    switch (lbl_803CBBCC->_4) {
    case 0:
        fn_8004CA08(600);
        fn_8004A34C(&lbl_803C50E8, 0, 0x4A, 0, 0);
        lbl_803CBBCC->_4 = 2;
        break;
    case 2:
        switch (lbl_803C50E8._45) {
        case 2:
        case 4:
            fn_8004C9FC();
            fn_80023CF4(lbl_803C50E8._45 == 2);
            next = 4;
            if (lbl_803C50E8._45 == 2) {
                next = 3;
            }
            lbl_803CBBCC->_4 = next;
            break;
        }
        break;
    case 3:
        fn_8004A34C(&lbl_803C50E8, 0, 0x4B, 0, 0);
        lbl_803CBBCC->_4 = 6;
        break;
    case 4:
        fn_8004A34C(&lbl_803C50E8, 0, 0x4C, 0, 0);
        lbl_803CBBCC->_4 = 6;
        break;
    case 6:
        switch (lbl_803C50E8._45) {
        case 2:
            fn_2_11A0(1);
            fn_8004CA08(-1);
            break;
        }
        break;
    }
}
