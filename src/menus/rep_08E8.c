#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_08E8.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/vec.h"
#include "stdlib.h"
#include "math.h"

typedef struct AramEntry08E8 {
    /* 0x0 */ u32 _0[4];
} AramEntry08E8; // size: 0x10

// One entry per character, 0x34 bytes (starMissionCompletionTracker)
typedef struct MenuCharacter08E8 {
    /* 0x00 */ u8 _00[0x5];
    /* 0x05 */ s8 _05;
    /* 0x06 */ u8 _06[0x31 - 0x6];
    /* 0x31 */ s8 _31;
    /* 0x32 */ u8 _32[0x34 - 0x32];
} MenuCharacter08E8; // size: 0x34

typedef struct MenuSlot08E8 {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6[0xA - 0x6];
} MenuSlot08E8; // size: 0xA

extern struct {
    /* 0x0000 */ MenuCharacter08E8 _0000[0x36];
    /* 0x0AF8 */ u8 _0AF8[0x1606 - 0xAF8];
    /* 0x1606 */ u8 _1606;
    /* 0x1607 */ u8 _1607[0x40EE - 0x1607];
    /* 0x40EE */ MenuSlot08E8 _40EE[0x33];
    /* 0x42EC */ u8 _42EC[0x4415 - 0x42EC];
    /* 0x4415 */ u8 _4415;
    /* 0x4416 */ u8 _4416[0x441B - 0x4416];
    /* 0x441B */ u8 _441B;
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D[0x4422 - 0x441D];
    /* 0x4422 */ u8 _4422;
    /* 0x4423 */ u8 _4423;
    /* 0x4424 */ u8 _4424;
    /* 0x4425 */ u8 _4425;
} *lbl_2_bss_1A8248;

extern struct {
    /* 0x00 */ u8 _00[0xC6];
    /* 0xC6 */ u8 _C6[5][4];
    /* 0xDA */ u8 _DA[0xF4 - 0xDA];
    /* 0xF4 */ u8 _F4;
} *lbl_2_bss_1A8244;

extern struct {
    /* 0x000000 */ u8 _000000[0x195424];
    /* 0x195424 */ s32 _195424;
    /* 0x195428 */ s32 _195428;
    /* 0x19542C */ u8 _19542C[0x19769C - 0x19542C];
    /* 0x19769C */ s32 _19769C;
} *lbl_2_bss_1A824C;

extern struct {
    /* 0x0 */ s32 _0;
    /* 0x4 */ s32 _4;
    /* 0x8 */ s32 _8;
} lbl_803C7898;

typedef struct MenuPlayer08E8 {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ f32 _040;
    /* 0x044 */ f32 _044;
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x27C - 0x4C];
} MenuPlayer08E8; // size: 0x27C

extern struct {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ void* _0060;
    /* 0x0064 */ u8 _0064[0xC04 - 0x64];
    /* 0x0C04 */ MenuPlayer08E8 _0C04[4];
    /* 0x15F4 */ u8 _15F4[0x2C88 - 0x15F4];
    /* 0x2C88 */ void* _2C88;
    /* 0x2C8C */ void* _2C8C;
} lbl_8036E548;

typedef struct DrawCallback08E8 {
    /* 0x0 */ s32 _0;
    /* 0x4 */ void (*fn)(void);
} DrawCallback08E8; // size: 0x8

extern u8 lbl_803CBBC0;
extern u32 lbl_803CBD0C;
extern u8 lbl_803CB8F0[8];
extern u8 lbl_800F5D98[];
extern u8 lbl_800F71D8[];
extern s16 lbl_2_data_3EC8[6];
extern s16 lbl_2_data_3ED4[6];

extern void fn_80034CEC(void* task);
extern void fn_80034E20(void* task, u32* layout);
extern void fn_80035B50(s32);
extern s32 fn_80035838(AramEntry08E8* entry, s32 count);
extern void fn_800AD054(s32 arg0, s32 arg1);
extern void fn_800ACFB0(void* data);
extern void fn_800A7D4C(s32, void*);
extern void fn_800BD670(void* model, MtxPtr mtx);
extern void fn_80031CA4(Vec* pos, u32* glow);
extern void fn_8003BF54(s32, s32, s32, s32, s32, s32, s32, s32, s32);

// rep_0B08
extern void fn_2_68690(s32);
extern void fn_2_68DAC(s32, Vec*);

Vec lbl_2_data_12EA8 = { 0.8f, 0.8f, 0.8f };
Vec lbl_2_data_12EB4 = { 0.8f, 0.8f, 0.8f };
AramEntry08E8 lbl_2_data_12EC0[54] = {
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x400431B4, 0x0EB1D800, 0x0002B22C } },
    { { 0x0000040B, 0x400396A0, 0x0EB49000, 0x00026ED4 } },
    { { 0x0000040B, 0x4003ED8C, 0x0EB70000, 0x00028C4C } },
    { { 0x0000040B, 0x40036944, 0x0EB99000, 0x00022DF4 } },
    { { 0x0000040B, 0x40039B44, 0x0EBBC000, 0x00026618 } },
    { { 0x0000040B, 0x400320E4, 0x0EBE2800, 0x00021E2C } },
    { { 0x0000040B, 0x40030878, 0x0EC04800, 0x0001DD80 } },
    { { 0x0000040B, 0x4002D3C4, 0x0EC22800, 0x0001B3EC } },
    { { 0x0000040B, 0x40035258, 0x0EC3E000, 0x000238DC } },
    { { 0x0000040B, 0x40041ED0, 0x0EC62000, 0x00029B84 } },
    { { 0x0000040B, 0x400414AC, 0x0EC8C000, 0x0002D160 } },
    { { 0x0000040B, 0x4002E988, 0x0ECB9800, 0x0001E0BC } },
    { { 0x0000040B, 0x4002FED0, 0x0ECD8000, 0x0001C398 } },
    { { 0x0000040B, 0x4001FF28, 0x0ECF4800, 0x00015000 } },
    { { 0x0000040B, 0x40032CF4, 0x0ED09800, 0x0001F4E4 } },
    { { 0x0000040B, 0x40021EF4, 0x0ED29000, 0x00015114 } },
    { { 0x0000040B, 0x40038998, 0x0ED3E800, 0x00023948 } },
    { { 0x0000040B, 0x4001CE38, 0x0ED62800, 0x00011B30 } },
    { { 0x0000040B, 0x40032FDC, 0x0ED74800, 0x00021154 } },
    { { 0x0000040B, 0x4002ED24, 0x0ED96000, 0x0001E94C } },
    { { 0x0000040B, 0x40031490, 0x0EDB5000, 0x0001F824 } },
    { { 0x0000040B, 0x40030370, 0x0EDD5000, 0x0001EB70 } },
    { { 0x0000040B, 0x40030370, 0x0EDF4000, 0x0001EB70 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x40032428, 0x0EE58000, 0x0001F020 } },
    { { 0x0000040B, 0x40036CD8, 0x0EE77800, 0x00023828 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x40029748, 0x0F08B800, 0x0001ABF4 } },
    { { 0x0000040B, 0x40029748, 0x0F08B800, 0x0001ABF4 } },
    { { 0x0000040B, 0x40029748, 0x0F08B800, 0x0001ABF4 } },
    { { 0x0000040B, 0x40029748, 0x0F08B800, 0x0001ABF4 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
    { { 0x0000040B, 0x4003C4B8, 0x0EAF7000, 0x000265A8 } },
};
void* lbl_2_data_13220[2] = { lbl_800F5D98, lbl_800F71D8 };
DrawCallback08E8 lbl_2_data_13228[2] = { { 2, fn_2_487A0 }, { 2, fn_2_487A0 } };
u32 lbl_2_data_13238 = 0x0016000B;
AramEntry08E8 lbl_2_data_1323C = { { 0x0000040B, 0x400B2CB8, 0x18E3F000, 0x00053454 } };
AramEntry08E8 lbl_2_data_1324C = { { 0x0000040B, 0x40076AE0, 0x18ED7000, 0x00036BC8 } };
AramEntry08E8 lbl_2_data_1325C = { { 0x0000040B, 0x4011EC24, 0x18F0E000, 0x000D8818 } };
AramEntry08E8 lbl_2_data_1326C[7] = {
    { { 0x0000040B, 0x40069DFC, 0x18E92800, 0x000408D0 } },
    { { 0x0000040B, 0x4009947C, 0x18FE7000, 0x0002F758 } },
    { { 0x0000040B, 0x4006DC60, 0x19016800, 0x00024F50 } },
    { { 0x0000040B, 0x400A2AB4, 0x1903B800, 0x000371F8 } },
    { { 0x0000040B, 0x400A97F4, 0x19073000, 0x00048EEC } },
    { { 0x0000040B, 0x4007B2D0, 0x190BC000, 0x0002B520 } },
    { { 0x0000040B, 0x400AF4E8, 0x190E7800, 0x0004D804 } },
};
AramEntry08E8 lbl_2_data_132DC = { { 0x0000040B, 0x4023491C, 0x19135800, 0x00082928 } };
Vec lbl_2_data_132EC = { 0.0f, 0.0f, 0.0f };
u32 lbl_2_data_132F8[3] = { 0 };
Vec lbl_2_data_13304 = { 0.0f, 0.0f, 0.0f };
u32 lbl_2_data_13310[5] = { 0, 0, 0, 2, (u32)fn_2_481B8 };
u32 lbl_2_data_13324[20] = {
    0x00000000, 0x00000004, 0x00000014, 0x00013880, 0x00007530, 0x000130B0, 0x0000003C, 0x0000000A, 0x0001A9C8, 0x00018A88,
    0x00000000, 0x0000003C, 0x00C35000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFF00, 0x00000000, 0x000124F8, 0x00000000,
};
u32* lbl_2_data_13374 = lbl_2_data_13324;

// .text:0x0004EB64 size:0x38
s32 fn_2_4EB64(void) {
    return fn_80035838(&lbl_2_data_1323C, 8) != 0;
}

// .text:0x0004EB2C size:0x38
s32 fn_2_4EB2C(void) {
    return fn_80035838(&lbl_2_data_1324C, 0x15) != 0;
}

// .text:0x0004EAF4 size:0x38
s32 fn_2_4EAF4(void) {
    return fn_80035838(&lbl_2_data_1325C, 0xC) != 0;
}

// .text:0x0004EABC size:0x38
s32 fn_2_4EABC(void) {
    return fn_80035838(lbl_2_data_1326C, 0x17) != 0;
}

// .text:0x0004E970 size:0x38
s32 fn_2_4E970(void) {
    return fn_80035838(&lbl_2_data_132DC, 0x17) != 0;
}

// .text:0x0004E94C size:0x24
void fn_2_4E94C(void) {
    fn_80035B50(8);
}

// .text:0x0004E928 size:0x24
void fn_2_4E928(void) {
    fn_80035B50(0x15);
}

// .text:0x0004E904 size:0x24
void fn_2_4E904(void) {
    fn_80035B50(0xC);
}

// .text:0x0004E8E0 size:0x24
void fn_2_4E8E0(void) {
    fn_80035B50(0x17);
}

// .text:0x0004E8BC size:0x24
void fn_2_4E8BC(void) {
    fn_80035B50(0x18);
}

// .text:0x0004E898 size:0x24
void fn_2_4E898(void) {
    fn_80035B50(0x17);
}

// .text:0x0004E878 size:0x20
void fn_2_4E878(void* task, u32* layout) {
    fn_80034E20(task, layout);
}

// .text:0x0004E858 size:0x20
void fn_2_4E858(void* task) {
    fn_80034CEC(task);
}

// .text:0x0004E824 size:0x34
void fn_2_4E824(void) {
    lbl_2_bss_1A824C->_195424 = lbl_803C7898._4;
    lbl_2_bss_1A824C->_195428 = lbl_803C7898._8;
}

// .text:0x0004E7EC size:0x38
void fn_2_4E7EC(void) {
    fn_800AD054(lbl_2_bss_1A824C->_195424, lbl_2_bss_1A824C->_195428);
}

// .text:0x0004E7A4 size:0x48
void fn_2_4E7A4(void) {
    fn_8003BF54(0, 0, 0, 1, 1, 4, 1, 3, 0);
}

// .text:0x0004C3D8 size:0x14
s32 fn_2_4C3D8(s32 index) {
    return lbl_2_data_3EC8[index];
}

// .text:0x0004C3C4 size:0x14
s32 fn_2_4C3C4(s32 index) {
    return lbl_2_data_3ED4[index];
}

// .text:0x0004C36C size:0x58
void fn_2_4C36C(void) {
    lbl_2_bss_1A8248->_4424 = 1;
    lbl_2_bss_1A8248->_4425 = 1;
    lbl_2_bss_1A8248->_441B = 0;
    lbl_2_bss_1A8244->_C6[lbl_2_bss_1A8248->_441C][lbl_2_bss_1A8248->_4415] = 1;
    lbl_2_bss_1A8248->_1606 = 1;
}

// .text:0x0004C314 size:0x58
void fn_2_4C314(void) {
    s32 i;
    s32 j;
    u8 done = 1;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            if (lbl_2_bss_1A8244->_C6[i][j] == 0) {
                done = 0;
            }
        }
    }
    lbl_2_bss_1A8244->_F4 = done;
}

// .text:0x0004A310 size:0x30
s16 fn_2_4A310(s16 a, s16 b) {
    s16 d = __abs(a - b);
    if (d > 0x800) {
        d = 0x1000 - d;
    }
    return d;
}

// .text:0x0004A2C4 size:0x4C
s32 fn_2_4A2C4(f32 angle) {
    if (angle < 0.0f) {
        angle = 6.2831855f + angle;
    }
    return 2048.0f * angle / 3.1415927f;
}

// .text:0x0004A234 size:0x90
s16 fn_2_4A234(f32 x, f32 y) {
    s16 angle;

    if (0.0f == x) {
        if (y >= 0.0f) {
            return 0x400;
        }
        return 0xC00;
    }
    angle = 2048.0f * (f32)atan2(y, x) / 3.1415927f;
    if (angle < 0) {
        angle += 0x1000;
    }
    return angle;
}

// .text:0x0004A1E8 size:0x4C
f32 fn_2_4A1E8(f32 x, f32 y) {
    if (0.0f == x && 0.0f == y) {
        return 0.0f;
    }
    return atan2(y, x);
}

// .text:0x0004A18C size:0x5C
f32 fn_2_4A18C(f32 angle) {
    if (angle >= 3.1415927f) {
        while (angle >= 3.1415927f) {
            angle -= 6.2831855f;
        }
    }
    if (angle < -3.1415927f) {
        while (angle < -3.1415927f) {
            angle = 6.2831855f + angle;
        }
    }
    return angle;
}

// .text:0x0004A150 size:0x3C
s16 fn_2_4A150(s16 angle) {
    if (angle < 0) {
        while (angle < 0) {
            angle += 0x1000;
        }
    }
    if (angle >= 0x1000) {
        while (angle >= 0x1000) {
            angle -= 0x1000;
        }
    }
    return angle;
}

// .text:0x0004A094 size:0x30
u16* fn_2_4A094(u16* dst, u16* src) {
    u16* ret = dst;
    while (*src != 0x4000) {
        *dst++ = *src++;
    }
    *dst = *src;
    return ret;
}

// .text:0x0004A068 size:0x2C
s32 fn_2_4A068(u16* str) {
    u16* p = str;
    while (*p != 0x4000) {
        p++;
    }
    return p - str;
}

// .text:0x0004A064 size:0x4
void fn_2_4A064(void) {
}

// .text:0x00048D08 size:0x4C
void fn_2_48D08(void) {
    MenuPlayer08E8* player = &lbl_8036E548._0C04[lbl_2_bss_1A824C->_19769C];

    player->_034 = 0.0f;
    player->_038 = 0.0f;
    player->_03C = 0.0f;
    player->_040 = 0.0f;
    player->_044 = 0.0f;
    player->_048 = 0.0f;
}

// .text:0x000489DC size:0x40
void fn_2_489DC(void) {
    fn_800A7D4C(0xC, &lbl_2_data_13228[lbl_803CBBC0]);
}

// .text:0x000481B8 size:0x3C
void fn_2_481B8(void) {
    camera_803c639c_s* camera = fn_80052768_getCamera(0);
    fn_800BD670(lbl_8036E548._0060, camera->view);
}

// .text:0x00047AFC size:0x28
void fn_2_47AFC(void) {
    s32 i;
    for (i = 0; i < 13; i++) {
    }
}

// .text:0x0004777C size:0x44
void fn_2_4777C(void) {
    if (lbl_8036E548._2C8C != NULL) {
        fn_800ACFB0(lbl_8036E548._2C8C);
        lbl_8036E548._2C8C = NULL;
    }
}

// .text:0x000474FC size:0x44
void fn_2_474FC(void) {
    if (lbl_8036E548._2C88 != NULL) {
        fn_800ACFB0(lbl_8036E548._2C88);
        lbl_8036E548._2C88 = NULL;
    }
}

// .text:0x000474F8 size:0x4
void fn_2_474F8(void) {
}

// .text:0x00046D00 size:0x34
s32 fn_2_46D00(void) {
    if (lbl_2_bss_1A8248->_441C == 5 && lbl_2_bss_1A8248->_4422 >= 6) {
        return 1;
    }
    return 0;
}

// .text:0x00046C88 size:0x78
void fn_2_46C88(s32 id) {
    Vec pos;

    fn_2_68690(0);
    fn_2_68DAC(id, &pos);
    PSVECScale(&pos, 2.0f, &pos);
    *lbl_2_data_13374 = lbl_803CBD0C;
    fn_80031CA4(&pos, lbl_2_data_13374);
}

// .text:0x00046C2C size:0x5C
void fn_2_46C2C(s32 unused, Vec* src) {
    Vec pos;

    pos.x = src->x;
    pos.y = src->y;
    pos.z = src->z;
    *lbl_2_data_13374 = lbl_803CBD0C;
    fn_80031CA4(&pos, lbl_2_data_13374);
}

// .text:0x00046C24 size:0x8
s32 fn_2_46C24(void) {
    return 0;
}

// .text:0x0004668C size:0x20
void fn_2_4668C(s32 id) {
    ((MenuCharacter08E8*)lbl_2_bss_1A8248)[id]._31 = 1;
}

// .text:0x000460F4 size:0x4
void fn_2_460F4(void) {
}

// .text:0x000460F0 size:0x4
void fn_2_460F0(void) {
}

// .text:0x000460EC size:0x4
void fn_2_460EC(s32 arg0) {
}

// .text:0x00045938 size:0x40
s32 fn_2_45938(s32 slot) {
    return ((MenuCharacter08E8*)lbl_2_bss_1A8248)[lbl_803CB8F0[lbl_2_bss_1A8248->_40EE[slot]._5]]._31 == 0;
}

// .text:0x00044F34 size:0x30
s32 fn_2_44F34(s32 id) {
    return ((MenuCharacter08E8*)lbl_2_bss_1A8248)[id]._05 <= 3;
}

// .text:0x00044F14 size:0x20
s32 fn_2_44F14(s32 id) {
    return ((MenuCharacter08E8*)lbl_2_bss_1A8248)[id]._05;
}
