#include "menus/rep_09B8.h"
#include "header_rep_data.h"

extern struct {
    /* 0x000000 */ u8 _000000[0x1954AC];
    /* 0x1954AC */ u16* _1954AC[1];
    /* 0x1954B0 */ u8 _1954B0[0x196F30 - 0x1954B0];
    /* 0x196F30 */ s32 _196F30;
    /* 0x196F34 */ u8 _196F34[0x196FB8 - 0x196F34];
    /* 0x196FB8 */ s32 _196FB8;
    /* 0x196FBC */ u8 _196FBC[0x196FCA - 0x196FBC];
    /* 0x196FCA */ s16 _196FCA;
    /* 0x196FCC */ u8 _196FCC[0x196FE0 - 0x196FCC];
    /* 0x196FE0 */ s16 _196FE0;
    /* 0x196FE2 */ u8 _196FE2[0x196FE4 - 0x196FE2];
    /* 0x196FE4 */ s16 _196FE4;
    /* 0x196FE6 */ u8 _196FE6[0x196FE8 - 0x196FE6];
    /* 0x196FE8 */ s16 _196FE8[0xA8];
    /* 0x197138 */ u8 _197138[0x197294 - 0x197138];
    /* 0x197294 */ s16 _197294[2];
    /* 0x197298 */ s16 _197298;
    /* 0x19729A */ u8 _19729A[0x19729C - 0x19729A];
    /* 0x19729C */ s16 _19729C;
    /* 0x19729E */ u8 _19729E[0x1972B8 - 0x19729E];
    /* 0x1972B8 */ u8 _1972B8;
} *lbl_2_bss_1A824C;

extern struct {
    /* 0x000 */ u8 _000[0x798];
    /* 0x798 */ u16** _798[1];
} lbl_80366B18;

extern u16 lbl_2_data_1F3A0[8];

// .text:0x00051470 size:0xF8
u16 fn_2_51470(s32 idx, u16 k) {
    u16* p;

    if (k == 0) {
        p = lbl_80366B18._798[lbl_2_bss_1A824C->_1972B8][idx + 1];
    } else {
        p = lbl_80366B18._798[lbl_2_bss_1A824C->_1972B8][idx + 1];
    }
    return fn_2_513E8(p, k);
}

// .text:0x0005146C size:0x4
void fn_2_5146C(void) {
}

// .text:0x000513E8 size:0x84
u16 fn_2_513E8(u16* p, u16 k) {
    u16 sum = 0;
    u16 c;

    for (;;) {
        c = *p++;
        if (c & 0x4000) {
            switch (c & 0x3FFF) {
            case 2:
                sum += lbl_2_data_1F3A0[k] / 2;
                break;
            case 3:
                sum += lbl_2_data_1F3A0[k];
                break;
            default:
                return sum;
            }
        } else if (c & 0x8000) {
            sum += lbl_2_data_1F3A0[k];
        } else {
            sum += lbl_2_data_1F3A0[k] >> 1;
        }
    }
}

// .text:0x000513E4 size:0x4
void fn_2_513E4(void) {
}

// .text:0x000513E0 size:0x4
void fn_2_513E0(void) {
}

// .text:0x000513DC size:0x4
void fn_2_513DC(void) {
}

// .text:0x00051358 size:0x4
void fn_2_51358(void) {
}

// .text:0x000512C0 size:0x98
void fn_2_512C0(s32 idx) {
    u16* p = lbl_2_bss_1A824C->_1954AC[idx];
    u16 c;

    for (;;) {
        c = *p++;
        if (c & 0x4000) {
            switch (c & 0x3FFF) {
            case 0:
                return;
            case 4:
                break;
            }
        }
        lbl_2_bss_1A824C->_197294[idx]++;
    }
}

// .text:0x000512B8 size:0x8
s32 fn_2_512B8(void) {
    return 0;
}

// .text:0x000512B4 size:0x4
void fn_2_512B4(void) {
}

// .text:0x00051190 size:0x124
void fn_2_51190(s32 arg0, s32 arg1) {
    s32 i;

    lbl_2_bss_1A824C->_196FE0 = 1;
    lbl_2_bss_1A824C->_196FE4 = 1;
    for (i = 0; i < 0xA8; i++) {
        lbl_2_bss_1A824C->_196FE8[i] = 0;
    }
    lbl_2_bss_1A824C->_196FB8 = arg0;
    lbl_2_bss_1A824C->_196F30 = arg1;
    lbl_2_bss_1A824C->_196FCA = 0;
    lbl_2_bss_1A824C->_197298 = 0;
    lbl_2_bss_1A824C->_19729C = 0;
}

// .text:0x0005118C size:0x4
void fn_2_5118C(void) {
}
