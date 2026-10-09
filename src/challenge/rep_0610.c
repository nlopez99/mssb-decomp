#include "challenge/rep_0610.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"
#include "Dolphin/GX/GXTransform.h"

typedef struct LITObj {
    /* 0x00 */ u8 _00[0xC0];
} LITObj; // size: 0xC0

// Animation or track list: a count and a list of nodes
typedef struct UnkNode0610 {
    /* 0x00 */ u8 _00[0xE8];
    /* 0xE8 */ struct {
        /* 0x0 */ f32 _0;
        /* 0x4 */ u8 _4[0xC - 0x4];
        /* 0xC */ void* _C;
    }* _E8;
} UnkNode0610;

typedef struct UnkList0610 {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x18 - 0x8];
    /* 0x18 */ UnkNode0610** _18;
} UnkList0610;

typedef struct Unk0060Elem {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ UnkList0610* _34;
    /* 0x38 */ u8 _38[0x90 - 0x38];
} Unk0060Elem; // size: 0x90

typedef struct Unk8036E548Actor {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ UnkList0610* _004;
    /* 0x008 */ u8 _008[0x10 - 0x8];
    /* 0x010 */ struct {
        /* 0x0 */ u8 _0[0x4];
        /* 0x4 */ struct {
            /* 0x0 */ s32 _0;
            /* 0x4 */ u8 _4[0xC - 0x4];
        }* _4;
    }* _010[1];
    /* 0x014 */ u8 _014[0x27C - 0x14];
} Unk8036E548Actor; // size: 0x27C

extern struct {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ Unk0060Elem* _0060;
    /* 0x0064 */ u8 _0064[0xAC - 0x64];
    /* 0x00AC */ LITObj* _00AC[3];
    /* 0x00B8 */ u8 _00B8[0xC04 - 0xB8];
    /* 0x0C04 */ Unk8036E548Actor _0C04[13];
} lbl_8036E548;

typedef struct UnkTask0610 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct UnkTask0610* _0C;
    /* 0x10 */ s16 _10;
} UnkTask0610;

extern UnkTask0610* lbl_803CC1B8;
extern u8 lbl_803CBBC0;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

typedef struct UnkBurst0610 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0x50 - 0x4];
} UnkBurst0610;

extern UnkBurst0610 lbl_80108B90;

typedef struct UnkCamera0610 {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ Mtx _08;
} UnkCamera0610; // size: 0x38

extern UnkTask0610* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);
extern void SetDisplayStateTexture(void*, s32, s32);
extern void fn_800B9A9C(u8, f32);
extern void fn_800B9AA8(LITObj* light);
extern void LITXForm(LITObj* light, Mtx view);
extern void fn_800AD038(void*);
extern void fn_800A7D4C(s32, void*);
extern void fn_800324EC(u16, s32, s32, UnkBurst0610*);
extern void fn_8002955C(Vec* pos, s32 arg1, UnkBurst0610* burst);
extern void fn_80026134(s32, Vec*);
extern void fn_80026130(s32, void*, f32);

extern UnkCamera0610 lbl_1_data_F4F8[];
extern void* lbl_1_data_F4DC[3];
extern UnkBurst0610 lbl_1_data_F2A0;
extern u16 lbl_1_data_F17C;
extern f32 lbl_1_data_ADC0;
extern u8 lbl_1_data_ADC4[0x1C];

typedef struct UnkLight0610 {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ Vec _34;
    /* 0x40 */ u8 _40[0x70 - 0x40];
    /* 0x70 */ LITObj* _70;
} UnkLight0610;

typedef struct Unk10AA4 {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58[0x5A - 0x58];
    /* 0x5A */ u8 _5A;
} Unk10AA4;

typedef struct Unk6940 {
    /* 0x00 */ u8 _00[0x44];
    /* 0x44 */ u8 _44;
    /* 0x45 */ u8 _45;
    /* 0x46 */ u8 _46;
    /* 0x47 */ u8 _47;
} Unk6940; // size: 0x48

static u8 lbl_1_bss_69D0[0x20];
static Unk6940 lbl_1_bss_6940[2];
static struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ Mtx _10;
    /* 0x40 */ u8 _40[0x4];
} lbl_1_bss_68FC;
static struct {
    /* 0x000 */ u8 _000[0x30];
    /* 0x030 */ LITObj _030;
    /* 0x0F0 */ u8 _0F0[0x108 - 0xF0];
    /* 0x108 */ Vec _108;
    /* 0x114 */ u8 _114[0x118 - 0x114];
    /* 0x118 */ u8 _118;
} lbl_1_bss_67E0;
static struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ f32 _4;
}* lbl_1_bss_67B8[10];
static s32 lbl_1_bss_5F7C[0x20F];
static u8 lbl_1_bss_5F78;
static f32 lbl_1_bss_5F74;
static u8 lbl_1_bss_5F73;
static u8 lbl_1_bss_5F72;
static u8 lbl_1_bss_5F71;
static u8 lbl_1_bss_5F70;
static u32 lbl_1_bss_5F6C;
static u8 lbl_1_bss_5F69;
static u8 lbl_1_bss_3218[0x2D51];
static u8 lbl_1_bss_3216;
static u8 lbl_1_bss_3215;
static u8 lbl_1_bss_3214;
static struct {
    /* 0x00 */ u8 _00[0x58];
    /* 0x58 */ Mtx _58;
    /* 0x88 */ u8 _88[0x154 - 0x88];
} lbl_1_bss_30C0;
static s32 lbl_1_bss_30BC;
static u8 lbl_1_bss_30B8;
static s32 lbl_1_bss_3098[8];
static s32 lbl_1_bss_3084[5];
static u8 lbl_1_bss_3081;
static u8 lbl_1_bss_3080;
static s32 lbl_1_bss_307C;
static s32 lbl_1_bss_3070[3];

// .text:0x00017954 size:0x78
void fn_1_17954(void) {
    Mtx44 m;
    C_MTXFrustum(m, -0.000175f, 0.000175f, 0.00025f, -0.00025f, 0.001f, 512.0f);
    GXSetProjection(m, GX_PERSPECTIVE);
}

// .text:0x000176EC size:0x20
void fn_1_176EC(void) {
    fn_1_1496C();
}

// .text:0x00016590 size:0x50
s32 fn_1_16590(void) {
    return fn_1_16558(lbl_1_bss_6940[lbl_1_bss_5F73]._44, lbl_1_bss_6940[lbl_1_bss_5F73]._45);
}

// .text:0x00016558 size:0x38
s32 fn_1_16558(s32 arg0, s32 arg1) {
    return lbl_8036E548._0C04[lbl_1_bss_5F73]._010[arg0]->_4[arg1]._0;
}

// .text:0x00016400 size:0x4C
void fn_1_16400(s8 arg0) {
    UnkList0610* list = lbl_8036E548._0C04[lbl_1_bss_5F73]._004;
    lbl_1_bss_5F6C = (lbl_1_bss_5F6C + list->_06 + arg0) % list->_06;
}

// .text:0x000163FC size:0x4
void fn_1_163FC(void) {}

// .text:0x000161D0 size:0x3C
void fn_1_161D0(void) {
    lbl_1_bss_5F78 ^= 1;
    fn_800B9A9C(lbl_1_bss_5F78, lbl_1_bss_5F74);
}

// .text:0x000160D8 size:0x20
u16 fn_1_160D8(s8 arg0, s8 arg1) {
    if (arg0 == arg1) {
        return 0xFF0F;
    }
    return 0xFFFF;
}

// .text:0x00015170 size:0x88
void fn_1_15170(void) {
    if (lbl_803C77B8[0]._04 & 0x200) {
        fn_1_148CC();
    } else if (lbl_803C77B8[0]._04 & 0x100) {
        lbl_1_bss_5F71 = 1;
    }
}

// .text:0x00014928 size:0x44
void fn_1_14928(void) {
    fn_800AD038(lbl_80366158._08);
    lbl_803CC1B8->_0C->_10 = 1;
}

// .text:0x000148CC size:0x5C
void fn_1_148CC(void) {
    fn_800AD038(lbl_80366158._08);
    lbl_803CC1B8->_10 = 0;
    lbl_803CC1B8->_00 = fn_1_176EC;
    lbl_1_bss_30B8 = 1;
}

// .text:0x00014888 size:0x44
void fn_1_14888(UnkLight0610* arg0) {
    if (lbl_1_bss_67E0._118) {
        fn_800B9AA8(&lbl_1_bss_67E0._030);
    } else {
        fn_800B9AA8(arg0->_70);
    }
}

// .text:0x00011C98 size:0x68
void fn_1_11C98(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        LITXForm(lbl_8036E548._00AC[i], lbl_1_bss_68FC._10);
    }
}

// .text:0x000116EC size:0x28
void fn_1_116EC(void* arg0) {
    SetDisplayStateTexture(arg0, 0, 0);
}

// .text:0x00010AA4 size:0x28
void fn_1_10AA4(Unk10AA4* arg0, f32 arg1) {
    arg0->_54 = arg1;
    arg0->_5A = 1;
    if (lbl_1_bss_67B8[0] != NULL) {
        lbl_1_bss_67B8[0]->_4 = arg1;
    }
}

// .text:0x0001073C size:0x7C
void fn_1_1073C(UnkLight0610* arg0) {
    Vec v;
    v.x = lbl_1_bss_67E0._108.x - arg0->_34.x;
    v.y = lbl_1_bss_67E0._108.y - arg0->_34.y;
    v.z = lbl_1_bss_67E0._108.z - arg0->_34.z;
    fn_80026134(0, &v);
    fn_80026130(0, lbl_1_data_ADC4, lbl_1_data_ADC0);
}

// .text:0x000106C4 size:0x78
void fn_1_106C4(void) {
    u16 buttons = lbl_803C77B8[0]._04;
    if (buttons & 8) {
    } else if (buttons & 4) {
    } else if (buttons & 1) {
        lbl_1_bss_3081 ^= 1;
    } else if (buttons & 2) {
        lbl_1_bss_3081 ^= 1;
    } else if (buttons & 0x100) {
    } else if (buttons & 0x200) {
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 1;
    }
}

// .text:0x000106B4 size:0x10
void fn_1_106B4(void) {
    lbl_1_bss_3098[0] = 0;
}

// .text:0x000106A4 size:0x10
s32 fn_1_106A4(void) {
    return lbl_1_bss_3098[0];
}

// .text:0x00010670 size:0x34
void fn_1_10670(void) {
    UnkTask0610* task = fn_800B0A5C_insertQueue(fn_1_10560, 11);
    task->_10 = 0;
}

// .text:0x0000F2F8 size:0x84
void fn_1_F2F8(void) {
    if (lbl_803C77B8[0]._04 & 0x100) {
        lbl_80108B90._00 = lbl_1_bss_3098[0];
        fn_800324EC(lbl_1_data_F17C, 0, -1, &lbl_80108B90);
    } else if (lbl_803C77B8[0]._04 & 0x200) {
        lbl_80108B90._00 = 0;
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 10;
    }
}

// .text:0x0000F040 size:0x90
void fn_1_F040(void) {
    Vec pos = { 0.0f, -5.0f, 0.0f };
    if (lbl_803C77B8[0]._04 & 0x100) {
        lbl_1_data_F2A0._00 = lbl_1_bss_3098[0];
        fn_8002955C(&pos, 0, &lbl_1_data_F2A0);
    } else if (lbl_803C77B8[0]._04 & 0x200) {
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 10;
    }
}

// .text:0x0000E9F8 size:0x28
void fn_1_E9F8(UnkList0610* arg0, s32 arg1, s32 arg2) {
    s32 i;
    for (i = 0; i < arg2; i++) {
        arg1++;
        if (arg1 == arg0->_06) {
            arg1 = 0;
        }
    }
}

// .text:0x0000D71C size:0x88
f32 fn_1_D71C(s32 arg0) {
    s32 i;
    UnkList0610* list = lbl_8036E548._0060[arg0]._34;
    for (i = 0; i < list->_06; i++) {
        if (list->_18[i]->_E8 != NULL && list->_18[i]->_E8->_C != NULL) {
            break;
        }
    }
    if (i < list->_06) {
        return list->_18[i]->_E8->_0;
    }
    return 0.0f;
}

// .text:0x0000D6E4 size:0x38
void* fn_1_D6E4(void) {
    switch (lbl_1_bss_3216) {
    case 0:
    case 1:
    case 2:
        return lbl_1_data_F4DC[lbl_1_bss_3216];
    }
    return NULL;
}

// .text:0x0000D6B4 size:0x30
void fn_1_D6B4(void) {
    if (lbl_1_bss_3216 == 0) {
        lbl_1_bss_3216 = 3;
    }
    lbl_1_bss_3216--;
}

// .text:0x0000D688 size:0x2C
void fn_1_D688(void) {
    lbl_1_bss_3216++;
    if (lbl_1_bss_3216 == 3) {
        lbl_1_bss_3216 = 0;
    }
}

// .text:0x0000D67C size:0xC
void fn_1_D67C(u8 arg0) {
    lbl_1_bss_3215 = arg0;
}

// .text:0x0000D660 size:0x1C
BOOL fn_1_D660(void) {
    return lbl_1_bss_3215 != 0;
}

// .text:0x0000D650 size:0x10
void fn_1_D650(void) {
    lbl_1_bss_3214 = 1;
}

// .text:0x0000D638 size:0x18
u8 fn_1_D638(void) {
    u8 ret = lbl_1_bss_3214;
    lbl_1_bss_3214 = 0;
    return ret;
}

// .text:0x0000D2F0 size:0x10
void fn_1_D2F0(void) {
    lbl_1_bss_30B8 = 1;
}

// .text:0x0000CB9C size:0x88
void fn_1_CB9C(s32 arg0) {
    if (arg0 != 0) {
        lbl_1_bss_30BC = 0;
    } else {
        PSMTXCopy(lbl_1_data_F4F8[lbl_803CBBC0]._08, lbl_1_bss_30C0._58);
        fn_800A7D4C(8, &lbl_1_data_F4F8[lbl_803CBBC0]);
    }
}

// .text:0x0000C5A8 size:0x4
void fn_1_C5A8(void) {}
