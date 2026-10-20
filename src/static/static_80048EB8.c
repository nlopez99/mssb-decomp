#include "static/static_80048EB8.h"
#include "static/orderchange.h"
#include "static/spani_default.h"
#include "string.h"
#include "static/UnknownHomes_Static.h"

typedef struct Scene {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ u16 _04;
} Scene;

typedef struct Card {
    /* 0x00 */ u8 _00[0x3E];
    /* 0x3E */ u8 _3E;
} Card;

extern Scene* lbl_803CBBCC;

extern struct {
    /* 0x00 */ u8 _00[0x2C];
    /* 0x2C */ u16 _2C;
    /* 0x2E */ u8 _2E[2];
    /* 0x30 */ u16 _30;
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33[3];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37[4];
    /* 0x3B */ u8 _3B;
    /* 0x3C */ u8 _3C;
    /* 0x3D */ u8 _3D;
    /* 0x3E */ u8 _3E;
    /* 0x3F */ u8 _3F;
    /* 0x40 */ u8 _40;
    /* 0x41 */ u8 _41;
    /* 0x42 */ u8 _42;
    /* 0x43 */ u8 _43;
    /* 0x44 */ u8 _44;
    /* 0x45 */ u8 _45[4][4];
    /* 0x55 */ u8 _55[4][4];
} lbl_803C5F04;

extern struct {
    /* 0x00 */ u8 _00[0x55];
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x57 */ u8 _57[0x5D - 0x57];
    /* 0x5D */ u8 _5D;
} lbl_803C66B0;

extern struct {
    /* 0x00 */ u8 _00[0x36];
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
} lbl_803C5EA4;

extern u8 lbl_803C5EE0[0x16];

extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
} lbl_8037169C;

extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void changeScene(s32 arg0, s32 arg1);
extern void fn_800569C8(void);
extern void fn_800625A4(s32 arg0, s32 arg1);

u32 lbl_800FB5B0[4] = { 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0 };

// .text:0x8004A9E0 size:0x1F8
void fn_8004A9E0(void) {
}

// .text:0x8004A7D0 size:0x210
void fn_8004A7D0(void) {
}

// .text:0x8004A5B8 size:0x218
void fn_8004A5B8(void) {
}

// .text:0x8004A34C size:0x26C
void fn_8004A34C(void) {
}

// .text:0x8004A328 size:0x24
s32 fn_8004A328(Card* card) {
    if (card->_3E != 0) {
        return 0;
    }
    card->_3E = 2;
    return 1;
}

// .text:0x8004A2BC size:0x6C
void fn_8004A2BC(void) {
    switch (lbl_803CBBCC->_04) {
    case 0:
        fn_800B0A5C_insertQueue(fn_8004A1BC, 0x2000);
        lbl_803C5F04._2C = 0;
        lbl_803CBBCC->_04++;
        break;
    case 1:
        break;
    }
}

// .text:0x8004A1BC size:0x100
void fn_8004A1BC(void) {
    s32 i;

    switch (lbl_803C5F04._30) {
    case 0:
        fn_80049C80();
        break;
    case 1:
        if (lbl_803C66B0._5D == 0) {
            lbl_803C5F04._30++;
        }
        break;
    case 2:
        for (i = 0; i < 2; i++) {
            fn_800494CC(i);
        }
        break;
    case 3:
        for (i = 0; i < 2; i++) {
            fn_80049220(i);
        }
        break;
    case 4:
        if (fn_80035838(lbl_800FB5B0, 6)) {
            lbl_803C5F04._32 = 1;
            lbl_803C5F04._30 = 0;
        }
        break;
    case 5:
        startGameRelated();
        break;
    }
    fn_80049D3C();
}

// .text:0x8004A0FC size:0xC0
void fn_8004A0FC(void) {
    s32 i;

    lbl_803C5F04._3B = 0;
    lbl_803C5F04._40 = 0;
    lbl_803C5F04._3C = 1;
    lbl_803C5F04._3D = 1;
    lbl_803C5F04._3E = 2;
    lbl_803C5F04._3F = 0;
    lbl_803C5F04._41 = 1;
    lbl_803C5F04._42 = 1;
    lbl_803C5F04._43 = 2;
    lbl_803C5F04._44 = 0;
    for (i = 0; i < 4; i++) {
        lbl_803C5F04._45[i][0] = 0;
        lbl_803C5F04._45[i][1] = 0;
        lbl_803C5F04._45[i][2] = 0;
        lbl_803C5F04._45[i][3] = 1;
        lbl_803C5F04._55[i][0] = 0;
        lbl_803C5F04._55[i][1] = 0;
        lbl_803C5F04._55[i][2] = 0;
        lbl_803C5F04._55[i][3] = 1;
    }
}

// .text:0x80049D8C size:0x370
void fn_80049D8C(void) {
}

// .text:0x80049D3C size:0x50
void fn_80049D3C(void) {
    s32 i;

    if (g_d_GameSettings.GameModeSelected != 6 && lbl_803C5F04._36 != 0) {
        for (i = 0; i < (g_d_GameSettings.GameModeSelected == 6 ? 4 : 2); i++) {
        }
    }
}

// .text:0x80049C80 size:0xBC
void fn_80049C80(void) {
    if (lbl_803C66B0._55 != 0 || lbl_803C66B0._56 != 0) {
        return;
    }
    if (g_d_GameSettings.GameModeSelected == 5 && lbl_8037169C._12 == 0) {
        changeScene(1, 6);
    }
    lbl_803C5EA4._36 = 1;
    lbl_803C5EA4._37 = lbl_803C5EA4._38;
    lbl_803C5EA4._38 = 3;
    possiblyTransferDataBetweenDifferentRels();
    memset(lbl_803C5EE0, 0, sizeof(lbl_803C5EE0));
    fn_800569C8();
    fn_800625A4(0, 0x29);
}

// .text:0x80049878 size:0x408
void possiblyTransferDataBetweenDifferentRels(void) {
}

// .text:0x800494CC size:0x3AC
void fn_800494CC(u8 team) {
}

// .text:0x80049220 size:0x2AC
void fn_80049220(u8 team) {
}

// .text:0x80048EB8 size:0x368
void startGameRelated(void) {
}
