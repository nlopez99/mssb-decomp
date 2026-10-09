#include "header_rep_data.h"
#include "menus/rep_0898.h"
#include "string.h"

extern struct {
    /* 0x000000 */ u8 _000000[0x197684];
    /* 0x197684 */ void* _197684;
    /* 0x197688 */ u8 _197688[0x19768C - 0x197688];
    /* 0x19768C */ s32 _19768C;
    /* 0x197690 */ s32 _197690;
    /* 0x197694 */ s32 _197694;
} *lbl_2_bss_1A824C;

extern void* lbl_2_data_12C0C[55];
extern void* lbl_2_data_12CE8[1];

// .bss:0x000015B8 size:0x4000
u8 lbl_2_bss_15B8[0x4000];

// .text:0x000422FC size:0x8C
void fn_2_422FC(s32 index) {
    lbl_2_bss_1A824C->_197694 = 0;
    lbl_2_bss_1A824C->_19768C = 0;
    lbl_2_bss_1A824C->_197690 = 0;
    memcpy(lbl_2_bss_15B8, lbl_2_data_12C0C[index], sizeof(lbl_2_bss_15B8));
    lbl_2_bss_1A824C->_197684 = lbl_2_bss_15B8;
}

// .text:0x00042270 size:0x8C
void fn_2_42270(s32 index) {
    lbl_2_bss_1A824C->_197694 = 0;
    lbl_2_bss_1A824C->_19768C = 0;
    lbl_2_bss_1A824C->_197690 = 0;
    memcpy(lbl_2_bss_15B8, lbl_2_data_12CE8[index], sizeof(lbl_2_bss_15B8));
    lbl_2_bss_1A824C->_197684 = lbl_2_bss_15B8;
}
