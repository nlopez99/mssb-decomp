#include "menus/rep_0CA0.h"
#include "header_rep_data.h"

typedef struct UnkTask0CA0 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16[0x18 - 0x16];
    /* 0x18 */ u16 _18;
} UnkTask0CA0;

typedef struct {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ s32 _54;
    /* 0x58 */ s32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x64 - 0x60];
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[0x68 - 0x66];
    /* 0x68 */ u8 _68;
} UnkSprite0CA0;

typedef struct {
    /* 0x00 */ UnkSprite0CA0* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} UnkSpriteRef0CA0; // size: 0x8

// Read by fn_80034E20; a _00 of 3 ends the list.
typedef struct {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u16 _02;
    /* 0x04 */ s32 _04[3];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ s16 _12;
    /* 0x14 */ s32 _14[3];
} UnkSpriteDesc0CA0; // size: 0x20

extern UnkSpriteRef0CA0 lbl_80371C30[];
extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x2B];
    /* 0x2B */ u8 _2B;
    /* 0x2C */ u8 _2C[0x31 - 0x2C];
    /* 0x31 */ u8 _31;
} lbl_803C66B0;

// Main-DOL .sbss object that symbols.txt lumped into lbl_803CBCD0 (+0x8)
extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u8 _4;
    /* 0x5 */ u8 _5;
} lbl_803CBCD8;

extern struct {
    /* 0x00 */ u8 _00[0xE4];
    /* 0xE4 */ u8 _E4;
    /* 0xE5 */ u8 _E5[0xF4 - 0xE5];
    /* 0xF4 */ u8 _F4;
    /* 0xF5 */ u8 _F5;
} lbl_80361B20;

extern struct {
    /* 0x00 */ u8 _00[0x44];
    /* 0x44 */ s32 _44;
} lbl_2_bss_F410;

extern struct {
    /* 0x00 */ u8 _00[0x57];
    /* 0x57 */ u8 _57;
} lbl_2_bss_F468;

extern struct {
    /* 0x00 */ u8 _00[0x47];
    /* 0x47 */ u8 _47;
} lbl_803C50E8;

extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x8 - 0x1];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
} lbl_8034E978;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} lbl_800FEF70[]; // size: 0x10

extern struct {
    /* 0x0 */ u8 _0[0x6];
    /* 0x6 */ u16 _6;
}* lbl_803CBBCC;

extern u8 lbl_2_data_2DC84[];
extern UnkSpriteDesc0CA0 lbl_2_data_2DC8C[];
extern UnkSpriteDesc0CA0 lbl_2_data_2E02C[];
extern s8 lbl_2_data_2E2EC;

extern s32 fn_80042DA8(UnkTask0CA0* task, s32 index, s32 value);
extern void fn_80062674(s32 index);
extern void fn_800626EC(s32 index);
extern void fn_80034E20(UnkTask0CA0* task, UnkSpriteDesc0CA0* desc);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800363D8(UnkTask0CA0* task, s32 id, s32 part, s32 kind, s32 value);
extern void fn_80034CEC(UnkTask0CA0* task);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80053FE8(void);
extern void fn_2_82DE8(void);

static inline BOOL isZero(u8 value) {
    return value == 0 ? TRUE : FALSE;
}

// .text:0x00084FA8 size:0x160
void fn_2_84FA8(void) {
    UnkTask0CA0* task = lbl_803CC1B8;
    s32 i;
    s8 v;

    fn_80034E20(task, lbl_2_data_2DC8C);
    for (i = 0; i < 6; i++) {
        if (lbl_80361B20._F5 == 0 && lbl_2_data_2DC84[i] == 1) {
            v = 6;
        } else {
            v = lbl_2_data_2DC84[i];
        }
        fn_800363D8(task, i + 6, 2, 0x1E, v);
    }
    if (lbl_80361B20._F5 == 0 && lbl_2_data_2DC84[lbl_2_bss_F410._44] == 1) {
        v = 0x12;
    } else {
        v = lbl_2_data_2DC84[lbl_2_bss_F410._44];
    }
    if (lbl_2_bss_F410._44 != 0) {
        fn_800363D8(task, 0, 1, 0x20, v);
    }
    lbl_803CBCD8._4 = 0;
    task->_18 = 0;
    ((UnkTask0CA0*)lbl_803CC1B8)->_00 = fn_2_845A8;
}

// .text:0x00084388 size:0x220
void fn_2_84388(UnkTask0CA0* task) {
    s32 i;
    s32 sel;
    s32 done;

    if (isZero(lbl_803C66B0._2B)) {
        lbl_80371C30[task->_14]._00->_5C = 0;
        lbl_80371C30[task->_14]._00->_68 = 1;
        sel = lbl_2_bss_F410._44;
        lbl_80371C30[task->_14 + 4]._00->_5C = 0;
        lbl_80371C30[task->_14 + 4]._00->_68 = 1;
        for (i = 6; i < 12; i++) {
            lbl_80371C30[task->_14 + i]._00->_58 = (lbl_80371C30[task->_14 + i]._00->_58 & 0xFFFFFF00) | 0xFF;
        }
        lbl_80371C30[task->_14 + 6 + sel]._00->_5C = 0x10000;
        lbl_80371C30[task->_14 + 6 + sel]._00->_68 = 1;
        fn_800626EC(0);
        lbl_803C66B0._2B = 1;
    }
    if (lbl_803C66B0._2B == 1) {
        done = fn_80042DA8(task, 0, 10) != 0;
        if (done + (fn_80042DA8(task, 4, 20) != 0) == 2) {
            lbl_2_data_2E2EC = lbl_2_bss_F410._44;
            fn_80062674(0);
            lbl_803C66B0._2B = 2;
        }
    }
}

// .text:0x00084194 size:0x1F4
void fn_2_84194(UnkTask0CA0* task) {
    s32 done;

    if (isZero(lbl_803C66B0._2B)) {
        lbl_80371C30[task->_14]._00->_5C = 0xA0000;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0xA0000;
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_68 = 4;
        lbl_80371C30[task->_14 + 2]._00->_68 = 4;
        lbl_80371C30[task->_14 + 3]._00->_68 = 4;
        lbl_80371C30[task->_14 + 5]._00->_68 = 4;
        lbl_80371C30[task->_14 + 4]._00->_68 = 4;
        fn_800626EC(0);
        lbl_803C66B0._2B = 1;
    }
    if (lbl_803C66B0._2B == 1) {
        done = fn_80042DA8(task, 0, 0) != 0;
        done += fn_80042DA8(task, 1, 0) != 0;
        done += fn_80042DA8(task, 2, 0) != 0;
        done += fn_80042DA8(task, 3, 0) != 0;
        done += fn_80042DA8(task, 5, 0) != 0;
        if (done == 5) {
            lbl_2_data_2E2EC = lbl_2_bss_F410._44;
            fn_80062674(0);
            lbl_803C66B0._2B = 2;
            lbl_2_data_2E2EC = -1;
            fn_80034CEC(task);
            fn_800B0A14_removeQueue();
        }
    }
}

// .text:0x00083974 size:0x1C0
void fn_2_83974(UnkTask0CA0* task) {
    s32 done;

    if (isZero(lbl_803C66B0._2B)) {
        lbl_80371C30[task->_14]._00->_5C = 0xA0000;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0;
        lbl_80371C30[task->_14]._00->_68 = 1;
        lbl_80371C30[task->_14 + 1]._00->_68 = 0;
        lbl_80371C30[task->_14 + 2]._00->_68 = 4;
        lbl_80371C30[task->_14 + 3]._00->_68 = 4;
        lbl_80371C30[task->_14 + 5]._00->_68 = 4;
        lbl_80371C30[task->_14 + 4]._00->_68 = 1;
        fn_800626EC(0);
        lbl_803C66B0._2B = 1;
    }
    if (lbl_803C66B0._2B == 1) {
        done = fn_80042DA8(task, 0, 20) != 0;
        done += fn_80042DA8(task, 2, 0) != 0;
        done += fn_80042DA8(task, 5, 0) != 0;
        done += fn_80042DA8(task, 3, 0) != 0;
        if (done == 4) {
            lbl_2_data_2E2EC = lbl_2_bss_F410._44;
            fn_80062674(0);
            lbl_803C66B0._2B = 2;
        }
    }
}

// .text:0x000837D8 size:0x19C
void fn_2_837D8(UnkTask0CA0* task) {
    s32 value;
    s32 done;

    if (isZero(lbl_803C66B0._2B)) {
        lbl_80371C30[task->_14]._00->_68 = 4;
        lbl_80371C30[task->_14 + 1]._00->_5C = 0;
        lbl_80371C30[task->_14 + 1]._00->_68 = 0;
        lbl_80371C30[task->_14 + 2]._00->_68 = 1;
        lbl_80371C30[task->_14 + 5]._00->_68 = 1;
        lbl_80371C30[task->_14 + 3]._00->_68 = 1;
        lbl_80371C30[task->_14 + 4]._00->_5C = 0x280000;
        lbl_80371C30[task->_14 + 4]._00->_68 = 4;
        fn_800626EC(0);
        lbl_803C66B0._2B = 1;
    }
    if (lbl_803C66B0._2B == 1) {
        done = fn_80042DA8(task, 0, 10) != 0;
        if (done + (fn_80042DA8(task, 4, 20) != 0) == 2) {
            value = lbl_2_bss_F410._44;
            if (lbl_80361B20._F5 == 0 && value != 0) {
                value--;
            }
            lbl_2_data_2E2EC = value;
            fn_80062674(0);
            lbl_803C66B0._2B = 2;
        }
    }
}

// .text:0x00083744 size:0x94
void fn_2_83744(UnkTask0CA0* task) {
    UnkSprite0CA0* sprite = lbl_80371C30[task->_14]._00;

    if ((sprite->_5C >> 16) == 20) {
        sprite->_68 = 1;
    }
    if ((lbl_80371C30[task->_14]._00->_5C >> 16) == 30) {
        lbl_803CBCD8._4 = 1;
        fn_80062674(0);
        lbl_803C66B0._31 = 2;
    }
}

// .text:0x000836A4 size:0xA0
void fn_2_836A4(void) {
    if (lbl_803C50E8._47) {
        fn_800B0A5C_insertQueue(fn_80053FE8, 0);
    }
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._00 = 12;
    lbl_8034E978._08 = lbl_800FEF70[12]._08;
    if (lbl_803CBBCC->_6 != 9) {
        fn_800B0A5C_insertQueue(fn_2_82DE8, 0x3000);
    }
    fn_800B0A5C_insertQueue(fn_2_834F0, 0x3000);
}

// .text:0x000834F0 size:0x1B4
void fn_2_834F0(void) {
    UnkTask0CA0* task = lbl_803CC1B8;
    s32 i;

    fn_80034E20(task, lbl_2_data_2E02C);
    for (i = 0; i < 4; i++) {
        if (lbl_2_bss_F468._57 < i) {
            fn_800363D8(task, i + 3, 1, 0x6B, 4);
        } else {
            fn_800363D8(task, i + 3, 1, 0x6B, i);
        }
    }
    lbl_80371C30[task->_14 + 12]._00->_5C = 0;
    if (lbl_80361B20._F4) {
        lbl_80371C30[task->_14 + 1]._00->_64 = 0x22;
        lbl_80371C30[task->_14 + 11]._00->_5C = 0x40000;
    } else {
        lbl_80371C30[task->_14 + 1]._00->_64 = 0x21;
        lbl_80371C30[task->_14 + 11]._00->_5C = 0;
    }
    if (lbl_80361B20._E4) {
        lbl_80371C30[task->_14 + 9]._00->_54 |= 2;
        lbl_80371C30[task->_14 + 9]._00->_68 = 1;
        fn_800363D8(task, 9, 1, 0x27, 0);
    }
    ((UnkTask0CA0*)lbl_803CC1B8)->_00 = fn_2_82EC0;
}
