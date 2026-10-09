#include "menus/rep_0C50.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"

typedef struct UnkTask0C50 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
} UnkTask0C50;

typedef struct {
    /* 0x00 */ u8 _00[0x5C];
    /* 0x5C */ s32 _5C;
    /* 0x60 */ u8 _60[0x68 - 0x60];
    /* 0x68 */ u8 _68;
} UnkSprite0C50;

typedef struct {
    /* 0x00 */ UnkSprite0C50* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef0C50; // size: 0x8

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc0C50; // size: 0x20

extern UnkSpriteRef0C50 lbl_80371C30[];
extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x7];
    /* 0x07 */ u8 _07;
    /* 0x08 */ u8 _08[0xD - 0x8];
    /* 0x0D */ u8 _0D[0x55 - 0xD];
    /* 0x55 */ u8 _55[0x5D - 0x55];
    /* 0x5D */ u8 _5D[0x64 - 0x5D];
} lbl_803C66B0;

// Main-DOL .sbss object that symbols.txt lumps into lbl_803CBBC2 (+0x2)
extern struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4;
} lbl_803CBBC4;

extern struct {
    /* 0x00 */ u8 _00[0xF4];
    /* 0xF4 */ u8 _F4;
} lbl_80361B20;

extern struct {
    /* 0x0000 */ u8 _0000[0x46E0];
    /* 0x46E0 */ s32 _46E0;
    /* 0x46E4 */ u8 _46E4[0x470F - 0x46E4];
    /* 0x470F */ u8 _470F[0x4748 - 0x470F];
    /* 0x4748 */ UnkTask0C50* _4748;
    /* 0x474C */ u8 _474C[0x48AF - 0x474C];
    /* 0x48AF */ u8 _48AF;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0x37];
    /* 0x37 */ u8 _37;
    /* 0x38 */ u8 _38;
} lbl_803C5EA4;

extern UnkSpriteDesc0C50 lbl_2_data_2AADC[];
extern UnkSpriteDesc0C50 lbl_2_data_2B4DC[];

extern u8 lbl_800FE930[2][6];

extern s32 lbl_2_bss_A840;
extern struct {
    /* 0x00 */ s32 _00;
} lbl_2_bss_F410;
extern UnkSpriteDesc0C50 lbl_2_data_2D33C[];

extern s32 fn_80042DA8(UnkTask0C50* task, s32 index, s32 value);
extern void fn_80062674(s32 index);
extern void fn_800626EC(s32 index);
extern void fn_80034E20(UnkTask0C50* task, UnkSpriteDesc0C50* desc);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800363D8(UnkTask0C50* task, s32 id, s32 part, s32 kind, s32 value);
extern s32 fn_2_8794(s32 flag, s32 value);

static inline BOOL isAnimDone(UnkTask0C50* task, s32 index, s32 value) {
    return fn_80042DA8(task, index, value) ? TRUE : FALSE;
}

// .text:0x0008082C size:0xAC
void fn_2_8082C(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, index + 0x89, 5);

        n += isAnimDone(task, index + 0x8B, 10);
        if (n == 2) {
            fn_80062674(index);
            lbl_803C66B0._0D[index] = 2;
        }
    }
}

// .text:0x00082DE8 size:0x70
void fn_2_82DE8(void) {
    lbl_8034E9A0._4748 = lbl_803CC1B8;
    lbl_8034E9A0._48AF = 0;
    lbl_803C5EA4._37 = 0;
    lbl_803C5EA4._38 = 0;
    fn_80034E20(lbl_803CC1B8, lbl_2_data_2B4DC);
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_82CF0;
}

// .text:0x00079634 size:0x54
void fn_2_79634(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 1 ? TRUE : FALSE) {
        fn_80062674(index);
        lbl_803C66B0._0D[index] = 2;
    }
}

// .text:0x00078034 size:0x28
void fn_2_78034(UnkTask0C50* task, s32 index) {
    if (lbl_803C66B0._0D[index] == 0 ? TRUE : FALSE) {
        lbl_803C66B0._0D[index] = 1;
    }
}

// .text:0x0007664C size:0x4
void fn_2_7664C(void) {
}

// .text:0x0007609C size:0x30
void fn_2_7609C(UnkTask0C50* task, u8 flag, u8 skip) {
    if (!skip) {
        fn_2_8794(flag, 0);
    }
}

// .text:0x00076098 size:0x4
void fn_2_76098(void) {
}

// .text:0x00074DB8 size:0x5C
s32 fn_2_74DB8(s32 arg0) {
    switch (arg0) {
    case 0xD:
    case 0x10:
    case 0x14:
    case 0x16:
    case 0x19:
    case 0x22:
    case 0x2A:
    case 0x32:
    case 0x34:
        return 1;
    case 0x15:
    case 0x18:
    case 0x1D:
    case 0x21:
    case 0x2C:
    case 0x33:
    case 0x35:
        return 2;
    case 0x17:
    case 0x1E:
    case 0x24:
    case 0x2D:
        return 3;
    case 0xC:
    case 0x1A:
    case 0x1B:
    case 0x1F:
    case 0x23:
    case 0x2B:
    case 0x2E:
    case 0x31:
        return 4;
    case 0x20:
        return 5;
    case 0x2F:
        return 6;
    default:
        return 0;
    }
}

// .text:0x00075B58 size:0x8C
u8 fn_2_75B58(UnkTask0C50* task, s32 index) {
    s32 hits = 0;
    s32 total = 0;
    s32 i;
    u8 count = lbl_8034E9A0._470F[index];

    for (i = 0; i < count; i++) {
        total++;
        hits += fn_80042DA8(task, i + index * 5 + 0x6E, 0x1E) != 0;
    }
    return hits == total;
}

// .text:0x00074D8C size:0x2C
void fn_2_74D8C(void) {
    fn_800B0A5C_insertQueue(fn_2_74CD8, 0x1000);
}

// .text:0x00074CD8 size:0xB4
void fn_2_74CD8(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2D33C);
    for (i = 0; i < 7; i++) {
        fn_800363D8(task, i + 0x18, 1, 0x36, i);
    }
    fn_800363D8(task, 0x20, 1, 0x32, 0);
    lbl_2_bss_A840 = lbl_2_bss_F410._00;
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_747FC;
}

// .text:0x00074518 size:0x4C
void fn_2_74518(void) {
    if (lbl_803C66B0._07 == 0 ? TRUE : FALSE) {
        fn_800626EC(0);
        lbl_803C66B0._07 = 1;
    }
}

// .text:0x000744C8 size:0x50
void fn_2_744C8(void) {
    if (lbl_803C66B0._07 == 1 ? TRUE : FALSE) {
        fn_80062674(0);
        lbl_803C66B0._07 = 2;
    }
}

// .text:0x00073B94 size:0x5C
s32 fn_2_73B94(s32 arg0) {
    if (lbl_2_bss_A840 == 0 && arg0 == 6) {
        return 45;
    }
    if (lbl_2_bss_A840 == 6 && arg0 == 0) {
        return 14;
    }
    if (lbl_2_bss_A840 <= arg0) {
        return 29;
    }
    if (lbl_2_bss_A840 > arg0) {
        return 44;
    }
}

// .text:0x00073B54 size:0x40
s32 fn_2_73B54(s32 arg0) {
    if (lbl_2_bss_A840 == 0 && arg0 == 6) {
        return 4;
    }
    if (lbl_2_bss_A840 == 6 && arg0 == 0) {
        return 1;
    }
    return 1;
}

// .text:0x0007302C size:0x60
s32 fn_2_7302C(void) {
    s32 i;
    u8* p = lbl_800FE930[lbl_80361B20._F4];

    for (i = 0; i < (lbl_80361B20._F4 != 0) + 5; i++) {
        if (lbl_8034E9A0._46E0 == *p) {
            return i;
        }
        p++;
    }
    return i;
}

// .text:0x00073028 size:0x4
void fn_2_73028(void) {
}

// .text:0x00072DDC size:0x78
void fn_2_72DDC(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        if ((fn_80042DA8(task, 0, 25) ? TRUE : FALSE) == TRUE) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
        }
    }
}

// .text:0x000729E0 size:0x78
void fn_2_729E0(UnkTask0C50* task) {
    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 1;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x190000;
        lbl_80371C30[task->_14 + 1]._00->_68 = 1;
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072CB4 size:0xAC
void fn_2_72CB4(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, 0, 0);

        n += isAnimDone(task, 1, 0);
        if (n == 2) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
            lbl_803CBBC4._4 = 1;
        }
    }
}

// .text:0x00072D60 size:0x7C
void fn_2_72D60(UnkTask0C50* task) {
    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x190000;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072A58 size:0x30
void fn_2_72A58(void) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        lbl_803CBBC4._3 = 0;
        lbl_803CBBC4._2 = 0;
        lbl_803CBBC4._0 = 0;
    }
}

// .text:0x0007293C size:0xA4
void fn_2_7293C(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, 0, 25);

        n += isAnimDone(task, 1, 25);
        if (n == 2) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
        }
    }
}

// .text:0x000728C0 size:0x7C
void fn_2_728C0(UnkTask0C50* task) {
    if (lbl_803CBBC4._2 == 0 ? TRUE : FALSE) {
        lbl_80371C30[task->_14]._00->_5C = 0x190000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0x190000;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_803CBBC4._2 = 1;
        lbl_803CBBC4._3 = 1;
    }
}

// .text:0x00072814 size:0xAC
void fn_2_72814(UnkTask0C50* task) {
    if (lbl_803CBBC4._3 == 1 ? TRUE : FALSE) {
        s32 n = isAnimDone(task, 0, 0);

        n += isAnimDone(task, 1, 0);
        if (n == 2) {
            lbl_803CBBC4._3 = 0;
            lbl_803CBBC4._2 = 0;
            lbl_803CBBC4._0 = 0;
            lbl_803CBBC4._4 = 1;
        }
    }
}

// .text:0x00072630 size:0x2C
void fn_2_72630(void) {
    fn_800B0A5C_insertQueue(fn_2_72594, 0x3000);
}

// .text:0x00072594 size:0x9C
void fn_2_72594(void) {
    UnkTask0C50* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2AADC);
    for (i = 0; i < 4; i++) {
        fn_800363D8(task, i + 7, 1, 0x32, 3 - i);
    }
    fn_800363D8(task, 2, 1, 0x35, 0);
    ((UnkTask0C50*)lbl_803CC1B8)->_00 = fn_2_7207C;
}
