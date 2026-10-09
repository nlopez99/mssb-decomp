#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_1028.h"
#include "menus/rep_0840.h"
#include "menus/rep_08E8.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/vec.h"
#include "stl/math.h"
#include "string.h"

typedef void (*Item1028Fn)(struct Item1028* item);
typedef void (*Item1028IndexFn)(s32 index);

// One of the 29 items in the star-mission tracker's array at 0x21E0
typedef struct Item1028 {
    /* 0x00 */ Vec _00;
    /* 0x0C */ Vec _0C;
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ f32 _30;
    /* 0x34 */ u8 _34[0x38 - 0x34];
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ u8 _40[0x44 - 0x40];
    /* 0x44 */ f32 _44;
    /* 0x48 */ u8 _48[0x78 - 0x48];
    /* 0x78 */ s32 _78;
    /* 0x7C */ s32 _7C;
    /* 0x80 */ f32 _80;
    /* 0x84 */ f32 _84;
    /* 0x88 */ f32 _88;
    /* 0x8C */ f32 _8C;
    /* 0x90 */ s16 _90;
    /* 0x92 */ s16 _92;
    /* 0x94 */ s16 _94;
    /* 0x96 */ u8 _96[0x9C - 0x96];
    /* 0x9C */ s16 _9C;
    /* 0x9E */ u8 _9E[0xA0 - 0x9E];
    /* 0xA0 */ s16 _A0;
    /* 0xA2 */ u8 _A2[0xA6 - 0xA2];
    /* 0xA6 */ s16 _A6;
    /* 0xA8 */ u8 _A8;
    /* 0xA9 */ u8 _A9;
    /* 0xAA */ u8 _AA;
    /* 0xAB */ u8 _AB;
    /* 0xAC */ u8 _AC;
    /* 0xAD */ u8 _AD;
    /* 0xAE */ s8 _AE;
    /* 0xAF */ u8 _AF[0xB2 - 0xAF];
    /* 0xB2 */ u8 _B2;
    /* 0xB3 */ u8 _B3;
    /* 0xB4 */ u8 _B4;
    /* 0xB5 */ u8 _B5;
    /* 0xB6 */ u8 _B6[0xB8 - 0xB6];
    /* 0xB8 */ Item1028Fn _B8;
} Item1028; // size: 0xBC

// One of 14 objects in the star-mission tracker's array at 0x1610
typedef struct Obj1028 {
    /* 0x00 */ Vec _00;
    /* 0x0C */ u8 _0C[0xD8 - 0xC];
} Obj1028; // size: 0xD8

typedef struct Tracker1028 {
    /* 0x0000 */ u8 _0000[0x1610];
    /* 0x1610 */ Obj1028 _1610[14];
    /* 0x21E0 */ Item1028 _21E0[42];
    /* 0x40B8 */ u8 _40B8[0x43BE - 0x40B8];
    /* 0x43BE */ s16 _43BE;
    /* 0x43C0 */ u8 _43C0[0x44F2 - 0x43C0];
    /* 0x44F2 */ u8 _44F2;
} Tracker1028;

// A model in the array at 0x34 of lbl_8036E548._68
typedef struct Model1028 {
    /* 0x00 */ void* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ u8 _08[0xE - 0x8];
    /* 0x0E */ s16 _0E;
    /* 0x10 */ u8 _10[0x54 - 0x10];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u8 _64[0x90 - 0x64];
} Model1028; // size: 0x90

typedef struct ModelSet1028 {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ Model1028 _34[1];
} ModelSet1028;

// One of the entries at lbl_8036E548._2D94, one per item
typedef struct Shadow1028 {
    /* 0x00 */ Item1028IndexFn _00;
    /* 0x04 */ Vec _04;
    /* 0x10 */ u8 _10[0x14 - 0x10];
    /* 0x14 */ f32 _14;
    /* 0x18 */ u8 _18[0x26 - 0x18];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} Shadow1028; // size: 0x28

typedef struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ u8 _10[0x14 - 0x10];
} Spot1028; // size: 0x14

typedef struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ GXColor ambient;
} StadiumLights1028; // size: 0x2C

extern StadiumLights1028 lbl_800F7478[14];

extern struct {
    /* 0x0000 */ u8 _0000[0x68];
    /* 0x0068 */ ModelSet1028* _68;
    /* 0x006C */ u8 _006C[0x2D94 - 0x6C];
    /* 0x2D94 */ Shadow1028* _2D94;
    /* 0x2D98 */ u8 _2D98[0x3078 - 0x2D98];
    /* 0x3078 */ u16 _3078;
} *lbl_2_bss_340140;

extern struct {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ s32 _0C[17];
    /* 0x50 */ u8 _50[1];
} *lbl_2_bss_3401BC;

extern struct {
    /* 0x000000 */ u8 _000000[0x1972BE];
    /* 0x1972BE */ u8 _1972BE;
    /* 0x1972BF */ u8 _1972BF;
    /* 0x1972C0 */ u8 _1972C0;
    /* 0x1972C1 */ u8 _1972C1[0x197740 - 0x1972C1];
    /* 0x197740 */ s16 _197740;
    /* 0x197742 */ u8 _197742[0x197863 - 0x197742];
    /* 0x197863 */ s8 _197863;
} *lbl_2_bss_1A824C;

// Points to starMissionCompletionTracker
extern Tracker1028* lbl_2_bss_1A8248;

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
} MenuTask1028;

extern MenuTask1028* lbl_803CC1B8;

extern Spot1028 lbl_2_data_3198[];
extern Spot1028 lbl_2_data_369C[];
extern s32 lbl_2_data_38BC[];

// Outside this unit's ranges: lbl_2_data_30900 lumps this table with the next unit's data.
extern Item1028IndexFn lbl_2_data_30900[6];

extern void fn_800BD2CC(s32 arg0, GXColor color);
extern f32 fn_800B4A94(void* actor);
extern s32 fn_80062890(s32 id);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void fn_2_8AC84(s32 index, u8 value);

static inline f32 calcAngle(f32 dx, f32 dz) { return atan2(-dx, -dz); }

u32 lbl_2_data_2FFF8[0x7F8 / 4] = {
    0x42415420, 0x46495253, 0x54000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x42415420, 0x4C415354, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x464C0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x50430000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x52520000, 0x524C0000, 0x4C520000, 0x4C4C0000, 0x4F464600, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4F4E0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53454C45, 0x43542044, 0x45425547, 0x204D454E,
    0x55000000, 0x00000000, 0x00000000, 0x00000000, 0x48494445, 0x20434841, 0x52412053, 0x45540000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53544152, 0x20504C41, 0x59455220, 0x53455400,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4B4F4F50, 0x41205354, 0x4120464C, 0x41472053,
    0x45540000, 0x00000000, 0x00000000, 0x00000000, 0x4348414C, 0x4C45204C, 0x4556454C, 0x20465245,
    0x45205345, 0x54000000, 0x00000000, 0x00000000, 0x3150203E, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x434F4D31, 0x3E000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3250203E, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x434F4D32, 0x3E000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3350203E, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x434F4D33, 0x3E000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3450203E, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x434F4D34, 0x3E000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000FF0F, 0x0000880F, 0x00000FFF, 0x0000088F,
    0x0000F0FF, 0x0000808F, 0x0000F00F, 0x0000800F, 0x00000004, 0x000A0006, 0x00020009, 0x00010005,
    0x000B0011, 0x00030013, 0x00020608, 0x040A0103, 0x0705090B, 0x00000602, 0x08040A05, 0x0B030901,
    0x07000000, 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0, 0x0000040B, 0x400ADFFC, 0x18AEE800,
    0x0004BAB0, 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8, 0x0000040B, 0x4010E5A0, 0x0E97A800,
    0x0009BCAC, 0x0000040B, 0x40016980, 0x0EA16800, 0x0000D6C4, 0x0000040B, 0x40016980, 0x0EA24000,
    0x0000C944, 0x0000040B, 0x40016980, 0x0EA31000, 0x0000E700, 0x0000040B, 0x40016980, 0x0EA3F800,
    0x0000D64C, 0x0000040B, 0x40016980, 0x0EA4D000, 0x0000C900, 0x0000040B, 0x40016980, 0x0EA5A000,
    0x0000CFFC, 0x0000040B, 0x40016980, 0x0EA67000, 0x0000D720, 0x0000040B, 0x40016980, 0x0EA74800,
    0x0000D6CC, 0x0000040B, 0x40016980, 0x0EA82000, 0x0000D21C, 0x0000040B, 0x40016980, 0x0EA8F800,
    0x0000D0BC, 0x0000040B, 0x40016980, 0x0EA9D000, 0x0000B544, 0x0000040B, 0x40016980, 0x0EAA8800,
    0x0000C4F8, 0x42415454, 0x494E4700, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x44454645, 0x4E434500, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x52554E00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x46414C4C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x42415454, 0x494E475F, 0x32000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x44454645, 0x4E43455F, 0x32000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x52554E5F, 0x32000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x46414C4C, 0x5F320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x4F4E4520, 0x2020494E, 0x4E494E47, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x54485245, 0x4520494E, 0x4E494E47, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x46495645, 0x2020494E, 0x4E494E47, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x53455645, 0x4E20494E, 0x4E494E47, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x4E494E45, 0x2020494E, 0x4E494E47, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x4F464600, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x4F4E0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x4D414E55, 0x414C0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x4155544F, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x4E4F0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x59455300, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x4E4F524D, 0x414C0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x45415359, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x46495253, 0x54000000, 0x4C415354, 0x00000000, 0x45415359, 0x20202020, 0x20204D4F,
    0x44450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4E4F524D, 0x414C2020, 0x20204D4F,
    0x44450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x48415244, 0x20202020, 0x20204D4F,
    0x44450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x56455259, 0x20484152, 0x44204D4F,
    0x44450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4D555349, 0x43000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x534F554E, 0x44000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x56494252, 0x4154494F, 0x4E000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4D4F4E41, 0x5552414C, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53544552, 0x454F0000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53555252, 0x4F554E44, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4F4E0000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4F464600, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

Item1028Fn lbl_2_data_307F0[2] = { fn_2_924B0, fn_2_924A4 };
Item1028Fn lbl_2_data_307F8[3] = { fn_2_923E4, fn_2_923D8, fn_2_923CC };
Item1028Fn lbl_2_data_30804[3] = { fn_2_91D74, fn_2_91C4C, fn_2_91C40 };
Item1028Fn lbl_2_data_30810[3] = { fn_2_91B80, fn_2_91B7C, fn_2_91B70 };
Item1028Fn lbl_2_data_3081C[3] = { fn_2_91B2C, fn_2_91B28, fn_2_91B1C };
Item1028Fn lbl_2_data_30828[3] = { fn_2_919CC, fn_2_919C0, fn_2_919B4 };
Item1028Fn lbl_2_data_30834[3] = { fn_2_918F4, fn_2_918E8, fn_2_918DC };
Item1028Fn lbl_2_data_30840[3] = { fn_2_91788, fn_2_9177C, fn_2_916F8 };
Item1028Fn lbl_2_data_3084C[3] = { fn_2_91518, fn_2_9150C, fn_2_91488 };
Item1028Fn lbl_2_data_30858[3] = { fn_2_912A8, fn_2_9129C, fn_2_91218 };
Item1028Fn lbl_2_data_30864[3] = { fn_2_91058, fn_2_90EC4, fn_2_90E98 };
Item1028Fn lbl_2_data_30870[4] = { fn_2_90CD0, fn_2_90C4C, fn_2_90C14, fn_2_90C08 };
Item1028Fn lbl_2_data_30880[3] = { fn_2_90ABC, fn_2_90AB0, fn_2_90A2C };
Item1028Fn lbl_2_data_3088C[3] = { fn_2_9094C, fn_2_90940, fn_2_90934 };
Item1028Fn lbl_2_data_30898[3] = { fn_2_90888, fn_2_90838, fn_2_9082C };
Item1028Fn lbl_2_data_308A4[4] = { fn_2_90718, fn_2_90698, fn_2_90628, fn_2_9061C };
Item1028Fn lbl_2_data_308B4[16] = {
    fn_2_92504, fn_2_9246C, fn_2_92394, fn_2_91C08, fn_2_91B38, fn_2_91AE4, fn_2_9197C, fn_2_918A4,
    fn_2_916C0, fn_2_91450, fn_2_911E0, fn_2_90DAC, fn_2_90BD0, fn_2_909F4, fn_2_908FC, fn_2_907F4,
};
Vec lbl_2_data_308F4 = { 0.0f, 0.0f, 0.0f };

f32 lbl_2_bss_B640;

// .text:0x00092654 size:0x28
// Outside this unit's .text range, but inlined into its functions.
static inline void fn_2_92654(s32 index, u8 type) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    item->_AB = type;
    item->_90 = 0;
}

// .text:0x0009257C size:0xD8
void fn_2_9257C(void) {
    s32 i;
    if (lbl_2_bss_1A8248->_44F2 == 1 || lbl_2_bss_1A8248->_44F2 == 2 || lbl_2_bss_1A8248->_44F2 == 3) {
        return;
    }
    for (i = 0; i < 29; i++) {
        fn_2_9253C(&lbl_2_bss_1A8248->_21E0[i]);
    }
    if (lbl_2_bss_1A824C->_1972C0 != 0) {
        lbl_2_bss_1A824C->_1972C0 = 0;
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0009253C size:0x40
void fn_2_9253C(Item1028* item) {
    item->_B8 = lbl_2_data_308B4[item->_AB];
    item->_B8(item);
}

// .text:0x00092504 size:0x38
void fn_2_92504(Item1028* item) { lbl_2_data_307F0[item->_90](item); }

// .text:0x000924B0 size:0x54
void fn_2_924B0(Item1028* item) {
    GXColor color = lbl_800F7478[0].ambient;
    fn_2_8AC84(item->_78, 0);
    color.a = 0xFF;
    fn_800BD2CC(0, color);
}

// .text:0x000924A4 size:0xC
void fn_2_924A4(Item1028* item) { item->_90 = 1; }

// .text:0x0009246C size:0x38
void fn_2_9246C(Item1028* item) { lbl_2_data_307F8[item->_90](item); }

// .text:0x000923E4 size:0x88
void fn_2_923E4(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    fn_2_8F6D0(item->_78, 0);
    item->_90 = 1;
}

// .text:0x000923D8 size:0xC
void fn_2_923D8(Item1028* item) { item->_90 = 2; }

// .text:0x000923CC size:0xC
void fn_2_923CC(Item1028* item) { item->_90 = 2; }

// .text:0x00092394 size:0x38
void fn_2_92394(Item1028* item) { lbl_2_data_30804[item->_90](item); }

// .text:0x00091D74 size:0x620
void fn_2_91D74(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    if (item->_78 >= 1 && item->_78 <= 7) {
        fn_2_8FB68(item->_78, 0);
    } else {
        switch (item->_78) {
        case 8:
            fn_2_8FBF8(item->_78, 0);
            break;
        default:
            fn_2_8FAE0(item->_78, 0);
            break;
        case 22:
            fn_2_8FA58(item->_78, 0);
            break;
        case 24:
            fn_2_8F9D0(item->_78, 0);
            break;
        case 27:
            fn_2_8F948(item->_78, 0);
            break;
        case 25:
            fn_2_8F8C0(item->_78, 0);
            break;
        case 26:
            fn_2_8F838(item->_78, 0);
            break;
        case 28:
            fn_2_8F7B0(item->_78, 0);
            break;
        }
    }
    fn_2_8F6D0(item->_78, 0);
    item->_90 = 1;
}

// .text:0x00091C4C size:0x128
void fn_2_91C4C(Item1028* item) {
    Model1028* model;
    switch (item->_A8) {
    case 1:
        if (lbl_2_bss_3401BC != NULL) {
            model = &lbl_2_bss_340140->_68->_34[item->_78];
            model->_54 = 0.0f;
            model->_5A = 1;
            model->_5C = 0.0f;
            model->_59 = 1;
            model->_5B = 2;
            model->_58 = 0;
            item->_90 = 2;
        }
        break;
    case 2:
        if (fn_2_8F774(item->_78) == 0.0f && lbl_2_bss_3401BC != NULL) {
            model = &lbl_2_bss_340140->_68->_34[item->_78];
            model->_54 = 0.0f;
            model->_5A = 1;
            model->_5C = 0.0f;
            model->_59 = 1;
            model->_5B = 2;
            model->_58 = 0;
            item->_90 = 2;
        }
        break;
    }
}

// .text:0x00091C40 size:0xC
void fn_2_91C40(Item1028* item) { item->_90 = 2; }

// .text:0x00091C08 size:0x38
void fn_2_91C08(Item1028* item) { lbl_2_data_30810[item->_90](item); }

// .text:0x00091B80 size:0x88
void fn_2_91B80(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    fn_2_8F6D0(item->_78, 0);
    item->_90 = 1;
}

// .text:0x00091B7C size:0x4
void fn_2_91B7C(Item1028* item) {}

// .text:0x00091B70 size:0xC
void fn_2_91B70(Item1028* item) { item->_90 = 2; }

// .text:0x00091B38 size:0x38
void fn_2_91B38(Item1028* item) { lbl_2_data_3081C[item->_90](item); }

// .text:0x00091B2C size:0xC
void fn_2_91B2C(Item1028* item) { item->_90 = 1; }

// .text:0x00091B28 size:0x4
void fn_2_91B28(Item1028* item) {}

// .text:0x00091B1C size:0xC
void fn_2_91B1C(Item1028* item) { item->_90 = 2; }

// .text:0x00091AE4 size:0x38
void fn_2_91AE4(Item1028* item) { lbl_2_data_30828[item->_90](item); }

// .text:0x000919CC size:0x118
void fn_2_919CC(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    fn_2_8FC88(item->_78);
    fn_2_8F6D0(item->_78, 0);
    item->_90 = 1;
}

// .text:0x000919C0 size:0xC
void fn_2_919C0(Item1028* item) { item->_90 = 2; }

// .text:0x000919B4 size:0xC
void fn_2_919B4(Item1028* item) { item->_90 = 2; }

// .text:0x0009197C size:0x38
void fn_2_9197C(Item1028* item) { lbl_2_data_30834[item->_90](item); }

// .text:0x000918F4 size:0x88
void fn_2_918F4(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    fn_2_8F6D0(item->_78, 2);
    item->_90 = 1;
}

// .text:0x000918E8 size:0xC
void fn_2_918E8(Item1028* item) { item->_90 = 2; }

// .text:0x000918DC size:0xC
void fn_2_918DC(Item1028* item) { item->_90 = 2; }

// .text:0x000918A4 size:0x38
void fn_2_918A4(Item1028* item) { lbl_2_data_30840[item->_90](item); }

// .text:0x00091788 size:0x11C
void fn_2_91788(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    fn_2_8FB68(item->_78, 1);
    fn_2_8F6D0(item->_78, 0);
    item->_90 = 1;
}

// .text:0x0009177C size:0xC
void fn_2_9177C(Item1028* item) { item->_90 = 2; }

// .text:0x000916F8 size:0x84
void fn_2_916F8(Item1028* item) {
    if (fn_2_8F774(item->_78) == 0.0f) {
        fn_2_92654(item->_78, 2);
    }
}

// .text:0x000916C0 size:0x38
void fn_2_916C0(Item1028* item) { lbl_2_data_3084C[item->_90](item); }

// .text:0x00091518 size:0x1A8
void fn_2_91518(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    if (item->_78 == 25) {
        fn_2_8F8C0(item->_78, 1);
    } else {
        fn_2_8F838(item->_78, 1);
    }
    fn_2_8F6D0(item->_78, 0);
    item->_90 = 1;
}

// .text:0x0009150C size:0xC
void fn_2_9150C(Item1028* item) { item->_90 = 2; }

// .text:0x00091488 size:0x84
void fn_2_91488(Item1028* item) {
    if (fn_2_8F774(item->_78) == 0.0f) {
        fn_2_92654(item->_78, 2);
    }
}

// .text:0x00091450 size:0x38
void fn_2_91450(Item1028* item) { lbl_2_data_30858[item->_90](item); }

// .text:0x000912A8 size:0x1A8
void fn_2_912A8(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    if (item->_78 == 25) {
        fn_2_8F8C0(item->_78, 3);
    } else {
        fn_2_8F838(item->_78, 3);
    }
    fn_2_8F6D0(item->_78, 0);
    item->_90 = 1;
}

// .text:0x0009129C size:0xC
void fn_2_9129C(Item1028* item) { item->_90 = 2; }

// .text:0x00091218 size:0x84
void fn_2_91218(Item1028* item) {
    if (fn_2_8F774(item->_78) == 0.0f) {
        fn_2_92654(item->_78, 2);
    }
}

// .text:0x000911E0 size:0x38
void fn_2_911E0(Item1028* item) { lbl_2_data_30864[item->_90](item); }

// .text:0x00091058 size:0x188
void fn_2_91058(Item1028* item) {
    Tracker1028* tracker = lbl_2_bss_1A8248;
    fn_2_8AC84(item->_78, 1);
    fn_2_8F7B0(item->_78, 1);
    fn_2_8F6D0(item->_78, 0);
    item->_B5 = 1;
    item->_88 = 0.07f;
    item->_00.y = 0.0f;
    item->_28 = 0.0f;
    item->_28 = 0.0f;
    fn_80062890(0x40);
    item->_2C = calcAngle(tracker->_1610[0]._00.x - tracker->_1610[1]._00.x,
                          tracker->_1610[0]._00.z - tracker->_1610[1]._00.z);
    item->_90 = 1;
}

// .text:0x00090EC4 size:0x194
void fn_2_90EC4(Item1028* item) {
    MenuTask1028* task = lbl_803CC1B8;
    Mtx mtx;
    Vec step;
    fn_2_90DE4(item, 0.0f);
    PSMTXRotRad(mtx, 'Y', item->_2C);
    step.x = 0.0f;
    step.y = 0.0f;
    step.z = 0.02f;
    PSMTXMultVec(mtx, &step, &step);
    item->_00.x -= step.x;
    item->_00.z -= step.z;
    if (item->_00.y >= 0.0f) {
        fn_2_46D34(lbl_2_data_38BC[0]);
        if (lbl_2_bss_1A8248->_43BE < 999) {
            *((u8*)fn_800B0A5C_insertQueue(fn_2_3FA14, 2) + 0x28) = 0;
            task->_10 = 0;
        } else {
            lbl_2_bss_1A824C->_197740 = 1;
        }
        item->_90 = 2;
    }
}

// .text:0x00090E98 size:0x2C
void fn_2_90E98(Item1028* item) { fn_2_92654(item->_78, 0); }

// .text:0x00090DE4 size:0xB4
void fn_2_90DE4(Item1028* item, f32 floor) {
    f32 y;
    if (item->_B5 != 0) {
        y = 1.5f * -(f32)sin(item->_88);
        item->_88 += 0.07f;
        if (y >= floor) {
            item->_88 = 0.0f;
            y = 0.0f;
            item->_B5 = 0;
        }
        item->_00.y = y;
    } else {
        item->_00.y = 0.0f;
    }
}

// .text:0x00090DAC size:0x38
void fn_2_90DAC(Item1028* item) { lbl_2_data_30870[item->_90](item); }

// .text:0x00090CD0 size:0xDC
void fn_2_90CD0(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    fn_2_8FB68(item->_78, 0);
    item->_9C = 28;
    item->_90 = 1;
}

// .text:0x00090C4C size:0x84
void fn_2_90C4C(Item1028* item) {
    if (item->_9C-- == 0) {
        item->_8C = 0.06f;
        item->_A0 = 0;
        fn_2_8F6D0(item->_78, 3);
        item->_90 = 2;
    }
}

// .text:0x00090C14 size:0x38
void fn_2_90C14(Item1028* item) {
    if (item->_A0 == 1) {
        fn_2_92654(item->_78, 0);
    }
}

// .text:0x00090C08 size:0xC
void fn_2_90C08(Item1028* item) { item->_90 = 3; }

// .text:0x00090BD0 size:0x38
void fn_2_90BD0(Item1028* item) { lbl_2_data_30880[item->_90](item); }

// .text:0x00090ABC size:0x114
void fn_2_90ABC(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    fn_2_8FAE0(item->_78, 1);
    fn_2_8F6D0(item->_78, 0);
    item->_90 = 1;
}

// .text:0x00090AB0 size:0xC
void fn_2_90AB0(Item1028* item) { item->_90 = 2; }

// .text:0x00090A2C size:0x84
void fn_2_90A2C(Item1028* item) {
    if (fn_2_8F774(item->_78) == 0.0f) {
        fn_2_92654(item->_78, 2);
    }
}

// .text:0x000909F4 size:0x38
void fn_2_909F4(Item1028* item) { lbl_2_data_3088C[item->_90](item); }

// .text:0x0009094C size:0xA8
void fn_2_9094C(Item1028* item) {
    fn_2_8AC84(item->_78, 0);
    item->_8C = 0.08f;
    item->_A0 = 0;
    fn_2_8AC84(item->_78, 1);
    fn_2_8F6D0(item->_78, 4);
    item->_90 = 1;
}

// .text:0x00090940 size:0xC
void fn_2_90940(Item1028* item) { item->_90 = 2; }

// .text:0x00090934 size:0xC
void fn_2_90934(Item1028* item) { item->_90 = 2; }

// .text:0x000908FC size:0x38
void fn_2_908FC(Item1028* item) { lbl_2_data_30898[item->_90](item); }

// .text:0x00090888 size:0x74
void fn_2_90888(Item1028* item) {
    item->_8C = 0.8f;
    fn_2_8F6D0(item->_78, 5);
    item->_A0 = 0;
    item->_90 = 1;
}

// .text:0x00090838 size:0x50
void fn_2_90838(Item1028* item) {
    if (item->_A0 == 1) {
        fn_2_8AC84(item->_78, 0);
        item->_A0 = 2;
    }
    item->_90 = 2;
}

// .text:0x0009082C size:0xC
void fn_2_9082C(Item1028* item) { item->_90 = 2; }

// .text:0x000907F4 size:0x38
void fn_2_907F4(Item1028* item) { lbl_2_data_308A4[item->_90](item); }

// .text:0x00090718 size:0xDC
void fn_2_90718(Item1028* item) {
    fn_2_8AC84(item->_78, 1);
    fn_2_8F9D0(item->_78, 2);
    item->_9C = 80;
    item->_A0 = 0;
    item->_90 = 1;
}

// .text:0x00090698 size:0x80
void fn_2_90698(Item1028* item) {
    if (item->_9C-- == 0) {
        item->_8C = 0.02f;
        fn_2_8F6D0(item->_78, 5);
        item->_90 = 2;
    }
}

// .text:0x00090628 size:0x70
void fn_2_90628(Item1028* item) {
    if (item->_A0 == 1) {
        fn_2_8AC84(item->_78, 0);
        item->_A0 = 2;
        fn_2_92654(item->_78, 0);
    }
}

// .text:0x0009061C size:0xC
void fn_2_9061C(Item1028* item) { item->_90 = 3; }

// .text:0x00090538 size:0xE4
void fn_2_90538(void) {
    s32 i;
    for (i = 0; i < 29; i++) {
        Item1028* item = &lbl_2_bss_1A8248->_21E0[i];
        memset(item, 0, sizeof(Item1028));
        item->_78 = i;
        item->_7C = i;
        item->_84 = 0.0f;
        item->_38 = 0.0f;
        item->_3C = 0.0f;
        item->_AA = 0;
        item->_92 = i;
        item->_94 = -1;
        item->_A8 = 0;
        item->_AB = 0;
        item->_90 = 0;
        item->_AE = -1;
        item->_AC = 0;
        item->_AD = 0;
        item->_80 = 0.0f;
        item->_A6 = 0;
        item->_B2 = 0xFF;
        item->_B4 = 0;
    }
}

// .text:0x000904A8 size:0x90
void fn_2_904A8(void) {
    s32 i;
    for (i = 0; i < 29; i++) {
        Item1028* item = &lbl_2_bss_1A8248->_21E0[i];
        item->_78 = i;
        item->_7C = i;
        item->_84 = 0.0f;
        item->_38 = 0.0f;
        item->_3C = 0.0f;
        item->_AA = 0;
        item->_92 = i;
        item->_94 = -1;
        item->_A8 = 0;
        item->_AB = 0;
        item->_90 = 0;
        item->_AE = -1;
        item->_AC = 0;
        item->_AD = 0;
        item->_80 = 0.0f;
        item->_A6 = 0;
        item->_B2 = 0xFF;
        item->_B4 = 0;
    }
}

// .text:0x00090428 size:0x80
void fn_2_90428(s32 index) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    memcpy(item, &lbl_2_data_3198[index]._00, sizeof(Vec));
    item->_30 = 0.0f;
    item->_28 = lbl_2_data_3198[index]._0C;
}

// .text:0x000903A8 size:0x80
void fn_2_903A8(s32 index) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    memcpy(item, &lbl_2_data_369C[index]._00, sizeof(Vec));
    item->_30 = 0.0f;
    item->_28 = lbl_2_data_369C[index]._0C;
}

// .text:0x0009033C size:0x6C
void fn_2_9033C(s32 index, Vec* pos, f32 arg2) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    memcpy(item, pos, sizeof(Vec));
    item->_28 = arg2;
    item->_30 = 0.0f;
    item->_28 = arg2;
}

// .text:0x0009007C size:0x2C0
void fn_2_9007C(void) {
    fn_2_8FE9C(lbl_2_bss_1A824C->_1972BE);
    fn_2_8FDB0(lbl_2_bss_1A824C->_1972BE);
}

// .text:0x0008FE9C size:0x1E0
void fn_2_8FE9C(s32 index) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    Vec pos;
    Vec diff;
    memcpy(&pos, item, sizeof(Vec));
    PSVECSubtract(&pos, &lbl_2_data_308F4, &diff);
    diff.x *= -1.0f;
    diff.z *= -1.0f;
    pos.x += lbl_803C77B8[lbl_2_bss_1A824C->_197863]._10 / 768.0f;
    pos.z += lbl_803C77B8[lbl_2_bss_1A824C->_197863]._11 / 768.0f;
    if (diff.x != 0.0f || diff.z != 0.0f) {
        lbl_2_bss_B640 = fn_2_4A1E8(diff.z, diff.x);
    }
    if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 0x40) {
        pos.y -= 0.05f;
    } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 & 0x20) {
        pos.y += 0.05f;
    }
    memcpy(&lbl_2_data_308F4, item, sizeof(Vec));
    item->_00 = pos;
    item->_44 = lbl_2_bss_B640;
}

// .text:0x0008FDB0 size:0xEC
void fn_2_8FDB0(s32 index) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    Mtx mtx;
    Vec step;
    if (item->_30 != 0.0f) {
        PSMTXRotRad(mtx, 'Y', item->_44);
        step.x = 0.0f;
        step.y = 0.0f;
        step.z = -item->_30;
        PSMTXMultVec(mtx, &step, &step);
        item->_18 = step.x;
        item->_1C = step.z;
        item->_00.x += item->_18;
        item->_00.z += item->_1C;
    }
    item->_0C.x = item->_00.x;
    item->_0C.z = item->_00.z;
    if (item->_30 == 0.0f) {
        item->_20 = 0.0f;
        item->_24 = 0.0f;
    }
}

// .text:0x0008FD14 size:0x9C
void fn_2_8FD14(void) {
    s32 i;
    for (i = 0; i < lbl_2_bss_340140->_3078; i++) {
        if (lbl_2_bss_340140->_2D94 != NULL) {
            Item1028* item = &lbl_2_bss_1A8248->_21E0[i];
            Shadow1028* shadow = &lbl_2_bss_340140->_2D94[i];
            memcpy(&shadow->_04, item, sizeof(Vec));
            shadow->_14 = item->_28;
            shadow->_26 = item->_AA;
        }
    }
}

// .text:0x0008FC88 size:0x8C
void fn_2_8FC88(s32 index) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[0];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = 0;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008FBF8 size:0x90
void fn_2_8FBF8(s32 index, s16 frame) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[index];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = frame;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008FB68 size:0x90
void fn_2_8FB68(s32 index, s16 frame) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[index];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = frame;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008FAE0 size:0x88
void fn_2_8FAE0(s32 index, s16 frame) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[10];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = frame;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008FA58 size:0x88
void fn_2_8FA58(s32 index, s16 frame) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[11];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = frame;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008F9D0 size:0x88
void fn_2_8F9D0(s32 index, s16 frame) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[12];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = frame;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008F948 size:0x88
void fn_2_8F948(s32 index, s16 frame) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[13];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = frame;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008F8C0 size:0x88
void fn_2_8F8C0(s32 index, s16 frame) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[14];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = frame;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008F838 size:0x88
void fn_2_8F838(s32 index, s16 frame) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[15];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = frame;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008F7B0 size:0x88
void fn_2_8F7B0(s32 index, s16 frame) {
    s32 anim;
    Model1028* model;
    if (lbl_2_bss_3401BC != NULL) {
        anim = lbl_2_bss_3401BC->_0C[16];
        model = &lbl_2_bss_340140->_68->_34[index];
        model->_04 = anim;
        model->_0E = frame;
        model->_5C = 0.0f;
        model->_58 = 1;
        model->_5A = model->_59 = anim != 0;
        model->_60 = 0.0f;
        model->_54 = 1.0f;
        model->_5A = 1;
        model->_5C = 0.0f;
        model->_59 = 1;
        model->_5B = 3;
    }
}

// .text:0x0008F774 size:0x3C
f32 fn_2_8F774(s32 index) {
    Model1028* model = &lbl_2_bss_340140->_68->_34[index];
    return fn_800B4A94(model->_00);
}

// .text:0x0008F758 size:0x1C
void fn_2_8F758(s32 index, u8 value) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    item->_A8 = value;
}

// .text:0x0008F73C size:0x1C
void fn_2_8F73C(s32 index, u8 value) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    item->_B4 = value;
}

// .text:0x0008F720 size:0x1C
u8 fn_2_8F720(s32 index) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    return item->_B4;
}

// .text:0x0008F6D0 size:0x50
void fn_2_8F6D0(s32 index, s32 kind) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    Shadow1028* shadows = lbl_2_bss_340140->_2D94;
    if (shadows != NULL) {
        item->_A6 = 0;
        shadows[index]._00 = lbl_2_data_30900[kind];
    }
}

// .text:0x0008F688 size:0x48
void fn_2_8F688(s32 index) {
    GXColor color = lbl_800F7478[0].ambient;
    color.a = 0xFF;
    fn_800BD2CC(0, color);
}

// .text:0x0008F640 size:0x48
void fn_2_8F640(s32 index) {
    GXColor color = lbl_800F7478[0].ambient;
    color.a = 0xFF;
    fn_800BD2CC(1, color);
}

// .text:0x0008F528 size:0x118
void fn_2_8F528(s32 index) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    GXColor color = lbl_800F7478[0].ambient;
    s32 alpha;
    switch (item->_A6) {
    case 0:
        item->_84 = 0.0f;
        item->_A6 = 1;
    case 1:
        item->_84 += 0.02;
        alpha = 256.0f * item->_84;
        if (alpha < 0xFF) {
            color.a = 1;
            color.a = alpha;
            fn_800BD2CC(1, color);
        } else {
            color.a = 0xFF;
            fn_800BD2CC(0, color);
            item->_A6 = 2;
        }
        break;
    case 2:
        item->_84 = 0.0f;
        break;
    }
}

// .text:0x0008F3D4 size:0x154
void fn_2_8F3D4(s32 index) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    GXColor color = lbl_800F7478[0].ambient;
    s32 alpha;
    switch (item->_A6) {
    case 0:
        color.a = 0xFF;
        item->_84 = 1.0f;
        item->_A6 = 1;
        fn_800BD2CC(1, color);
    case 1:
        item->_A6 = 2;
    case 2:
        item->_84 -= item->_8C;
        alpha = 255.0f * item->_84;
        if (alpha > 1) {
            color.a = alpha;
            fn_800BD2CC(1, color);
        } else {
            color.a = 0;
            fn_800BD2CC(1, color);
            item->_A6 = 3;
        }
        break;
    case 3:
        color.a = 0;
        fn_800BD2CC(1, color);
        item->_A0 = 1;
        item->_84 = 0.0f;
        break;
    }
}

// .text:0x0008F27C size:0x158
void fn_2_8F27C(s32 index) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    GXColor color = lbl_800F7478[0].ambient;
    s32 alpha;
    switch (item->_A6) {
    case 0:
        fn_2_8AC84(item->_78, 1);
        item->_84 = 0.0f;
        color.a = 256.0f * item->_84;
        fn_800BD2CC(1, color);
        item->_A6 = 1;
        break;
    case 1:
        item->_84 += item->_8C;
        alpha = 256.0f * item->_84;
        if (alpha < 0xFF) {
            color.a = 1;
            color.a = alpha;
            fn_800BD2CC(1, color);
        } else {
            color.a = 0xFF;
            fn_800BD2CC(0, color);
            item->_A6 = 2;
        }
        break;
    case 2:
        item->_84 = 0.0f;
        break;
    }
}

// .text:0x0008F0F4 size:0x188
void fn_2_8F0F4(s32 index) {
    Item1028* item = &lbl_2_bss_1A8248->_21E0[index];
    GXColor color = lbl_800F7478[0].ambient;
    s32 alpha;
    switch (item->_A6) {
    case 0:
        color.a = 0xFF;
        item->_84 = 1.0f;
        item->_A6 = 1;
        fn_800BD2CC(1, color);
    case 1:
        item->_84 -= item->_8C;
        alpha = 255.0f * item->_84;
        if (alpha > 1) {
            color.a = alpha;
            fn_800BD2CC(1, color);
        } else {
            color.a = 0;
            fn_800BD2CC(1, color);
            item->_A6 = 2;
        }
        break;
    case 2:
        color.a = 0;
        fn_800BD2CC(1, color);
        item->_A0 = 1;
        item->_84 = 0.0f;
        item->_A6 = 3;
        break;
    case 3:
        if (item->_A0 == 2) {
            color.a = 0xFF;
            fn_800BD2CC(0, color);
            item->_A6 = 4;
        }
        break;
    }
}
