#include "challenge/rep_7920.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"

typedef struct TexHeader7920 {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u8 _04[1];
} TexHeader7920;

typedef struct TexRef7920 {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ void* _04;
} TexRef7920;

typedef struct Sprite7920 {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ u16 _08;
    /* 0x0A */ u16 _0A;
    /* 0x0C */ u16 _0C;
    /* 0x0E */ s16 _0E;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11_0 : 1;
    /* 0x11 */ u8 _11_1 : 2;
    /* 0x11 */ u8 _11_3 : 2;
    /* 0x14 */ s32 _14;
    /* 0x18 */ u16 _18;
    /* 0x1A */ u16 _1A;
    /* 0x1C */ void* _1C;
} Sprite7920; // size: 0x20

extern Sprite7920 lbl_1_common_bss_4BC30[];
extern TexRef7920 lbl_1_common_bss_4C6F8[];

u8 lbl_1_data_108E0[8] = { 1, 1 };
u16 lbl_1_bss_47052;
u16 lbl_1_bss_47050;

static inline void fn_1_26B7C_inline1(Sprite7920* p, u8 v) {
    if (p != NULL) {
        p->_11_1 = v;
    }
}

static inline void fn_1_26B7C_inline2(Sprite7920* p, u8 v) {
    if (p != NULL) {
        p->_11_3 = v;
    }
}

// .text:0xB0 size:0xFC
Sprite7920* fn_1_26C2C(TexRef7920* tex, s32 index) {
    Sprite7920* p;

    if (tex == NULL) {
        return NULL;
    }
    if (lbl_1_data_108E0[0] != 0) {
        lbl_1_data_108E0[0] = 0;
    }
    fn_1_26B7C(&lbl_1_common_bss_4BC30[index]);
    p = &lbl_1_common_bss_4BC30[index];
    lbl_1_common_bss_4BC30[index]._18 = tex->_00;
    lbl_1_common_bss_4BC30[index]._1A = tex->_02;
    lbl_1_common_bss_4BC30[index]._1C = tex->_04;
    lbl_1_bss_47052 = tex->_00;
    lbl_1_bss_47050 = tex->_02;
    return p;
}

// .text:0x80 size:0x30
TexRef7920* fn_1_26BFC(TexHeader7920* header, s32 index) {
    TexRef7920* ref = &lbl_1_common_bss_4C6F8[index];

    ref->_00 = header->_00;
    ref->_02 = header->_02;
    ref->_04 = header->_04;
    return ref;
}

// .text:0x0 size:0x80
void fn_1_26B7C(Sprite7920* p) {
    p->_00 = 0.0f;
    p->_04 = 1.0f;
    p->_08 = 1;
    p->_0A = 0;
    p->_0C = 0;
    p->_0E = -1;
    p->_10 = 1;
    p->_14 = 0;
    p->_11_0 = 1;
    fn_1_26B7C_inline1(p, 3);
    fn_1_26B7C_inline2(p, 3);
}
