#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_04B0.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/vec.h"
#include "musyx/musyx.h"

typedef struct Pad04B0 {
    /* 0x0 */ u16 _0;
    /* 0x2 */ u16 _2;
    /* 0x4 */ u16 _4;
} Pad04B0;

typedef struct State04B0 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u8 _10[2];
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ u8 _14[4];
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C[8];
    /* 0x24 */ u8 _24[0x2D - 0x24];
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E[0x40 - 0x2E];
    /* 0x40 */ u8 _40[2];
    /* 0x42 */ u8 _42[2];
    /* 0x44 */ u8 _44[2];
    /* 0x46 */ u8 _46[5];
    /* 0x4B */ s8 _4B;
    /* 0x4C */ s8 _4C;
    /* 0x4D */ s8 _4D;
    /* 0x4E */ s8 _4E;
    /* 0x4F */ s8 _4F;
    /* 0x50 */ s8 _50;
    /* 0x51 */ s8 _51;
    /* 0x52 */ u8 _52[2];
} State04B0; // size: 0x54

extern State04B0 lbl_2_bss_100B8;
extern u8 lbl_80361B20[0x130];
extern u8 lbl_80108EC4[];
extern u8 lbl_800FE5D4[];
extern u8 lbl_800FE930[2][6];

extern struct {
    /* 0x00 */ u8 _00[0x74];
    /* 0x74 */ u8 _74[4];
    /* 0x78 */ u8 _78[0x7F - 0x78];
    /* 0x7F */ s8 _7F[4];
} lbl_803C6028;

typedef struct Select04B0 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s32 _10[2];
    /* 0x18 */ u8 _18[0x58 - 0x18];
} Select04B0; // size: 0x58

extern Select04B0 lbl_2_bss_F410;

extern struct {
    /* 0x00 */ u8 _00[0x45];
    /* 0x45 */ u8 _45[1];
    /* 0x46 */ u8 _46;
    /* 0x47 */ u8 _47[2];
    /* 0x49 */ u8 _49[0x4B - 0x49];
    /* 0x4B */ u8 _4B[2];
} lbl_2_bss_F468;

extern struct {
    /* 0x00 */ u8 _00[0xE];
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F[0x59 - 0xF];
    /* 0x59 */ u8 _59[2];
} lbl_803C66B0;

extern struct {
    /* 0x0000 */ u8 _0000[0xCF5D];
    /* 0xCF5D */ u8 _CF5D[2];
} lbl_803297E0;

extern u8 lbl_800EFBA4[0x10];

extern struct {
    /* 0x0 */ u8 _0[0x5];
    /* 0x5 */ u8 _5;
} lbl_803C5EA4;

extern struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
} lbl_803C6724;
extern u8 lbl_803CBBC4;
extern u8 lbl_2_bss_100B4;

extern struct {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2;
} lbl_803CBCD8;

extern struct {
    /* 0x0 */ u8 _0[4];
    /* 0x4 */ u16 _4;
    /* 0x6 */ u16 _6;
}* lbl_803CBBCC;

typedef struct LITObj {
    /* 0x00 */ u8 _00[0xC0];
} LITObj; // size: 0xC0

typedef struct Camera04B0 {
    /* 0x00 */ Mtx mtx;
    /* 0x30 */ u16 _30;
    /* 0x32 */ u16 _32;
    /* 0x34 */ f32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ Vec _3C;
    /* 0x48 */ Vec _48;
    /* 0x54 */ s32 _54;
} Camera04B0; // size: 0x58

extern Camera04B0 lbl_2_bss_1010C;
extern Vec lbl_2_data_20F8[];

typedef struct Light04B0 {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ Mtx _14;
    /* 0x44 */ u8 _44[0x48 - 0x44];
} Light04B0; // size: 0x48

extern Light04B0 lbl_2_bss_10164;

typedef struct Team04B0 {
    /* 0x000 */ u8 _000[0x25D];
    /* 0x25D */ u8 _25D;
} Team04B0;

extern struct {
    /* 0x0000 */ u8 _0000[0xAC];
    /* 0x00AC */ LITObj* _00AC[4];
    /* 0x00BC */ u8 _00BC[0x2C50 - 0xBC];
    /* 0x2C50 */ Team04B0* _2C50[2];
} lbl_8036E548;

extern struct {
    /* 0x0000 */ u8 _0000[0x46E0];
    /* 0x46E0 */ s32 _46E0[2];
    /* 0x46E8 */ u8 _46E8[0x46F8 - 0x46E8];
    /* 0x46F8 */ s8 _46F8[4];
    /* 0x46FC */ s8 _46FC[4];
    /* 0x4700 */ u8 _4700[4];
    /* 0x4704 */ u8 _4704;
    /* 0x4705 */ u8 _4705[0x4729 - 0x4705];
    /* 0x4729 */ u8 _4729;
    /* 0x472A */ u8 _472A[2];
    /* 0x472C */ Pad04B0 _472C[4];
    /* 0x4744 */ u8 _4744[0x4757 - 0x4744];
    /* 0x4757 */ u8 _4757[4];
} lbl_8034E9A0;

extern void AnimateCharacter(int actor, int anim, u8, u8, u8, s16, u8, int);
extern void QueueCharacterAnimation(int actor, int anim, u8, u8, s16, u8, int);
extern void LITXForm(LITObj* light, Mtx view);
static inline void fn_2_13CA0(Pad04B0* pad);
static inline void fn_2_13BA4(Pad04B0* pad);
extern s32 fn_2_14F8(s32 min, s32 max);
extern u8 fn_2_35D0(u8 port);
extern void fn_2_12238(void);
extern void fn_2_1C34(u16 buttons);
extern void fn_2_16A74(s32 arg0, s32 arg1);
extern void fn_800625A4(s32 port, s32 arg1);
extern void fn_2_1A88(void);
extern void fn_8004E504(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_8004E5B4(s32 arg0, s32 arg1, s32 arg2);
extern void fn_8004D4F0(s32 arg0, s32 arg1, s32 arg2);
extern s32 fn_8004E62C(s32 player, u16 arg1, u16 arg2, u16 arg3);
extern s32 fn_8004D57C(u16 arg0, u16 arg1, u16 arg2);
extern void makeLookAtMatrix(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);
extern void fn_80052D70(void* camera);
extern void fn_80052968(void);
extern void fn_800B806C(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
extern void fn_2_16A48(s32 port, u8 value);
extern void fn_8001CB10(void* arg0, s32 arg1);
extern void fn_8001CCC8(void);

// Debug menu labels and tables that no code in the module reads
u32 lbl_2_data_19E8[0x3EC / 4] = {
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
    0x07000000, 0x02050403, 0x08030405, 0x02060001, 0x08060701, 0x02000704, 0x04030102, 0x05010204,
    0x06080706, 0x08050303, 0x05070406, 0x0000040B, 0x4037CF5C, 0x18B3A800, 0x00208AF0, 0x0000040B,
    0x400ADFFC, 0x18AEE800, 0x0004BAB0, 0x0000040B, 0x400193E8, 0x191B8800, 0x000089D8, 0x0000040B,
    0x4010E5A0, 0x0E97A800, 0x0009BCAC, 0x0000040B, 0x40016980, 0x0EA16800, 0x0000D6C4, 0x0000040B,
    0x40016980, 0x0EA24000, 0x0000C944, 0x0000040B, 0x40016980, 0x0EA31000, 0x0000E700, 0x0000040B,
    0x40016980, 0x0EA3F800, 0x0000D64C, 0x0000040B, 0x40016980, 0x0EA4D000, 0x0000C900, 0x0000040B,
    0x40016980, 0x0EA5A000, 0x0000CFFC, 0x0000040B, 0x40016980, 0x0EA67000, 0x0000D720, 0x0000040B,
    0x40016980, 0x0EA74800, 0x0000D6CC, 0x0000040B, 0x40016980, 0x0EA82000, 0x0000D21C, 0x0000040B,
    0x40016980, 0x0EA8F800, 0x0000D0BC, 0x0000040B, 0x40016980, 0x0EA9D000, 0x0000B544, 0x0000040B,
    0x40016980, 0x0EAA8800, 0x0000C4F8,
};
u8 lbl_2_data_1DD4[0x2C] = {
    0x00, 0xC8, 0x06, 0xEF, 0x0E, 0x87, 0xFF, 0xFF, 0xE4, 0x00, 0x00, 0xC8, 0x05, 0x23, 0x02,
    0x86, 0x96, 0x8C, 0x82, 0x00, 0x00, 0xC8, 0x04, 0x4A, 0x0A, 0x44, 0x58, 0x58, 0x58, 0x00,
    0x00, 0xC8, 0x01, 0x53, 0x06, 0x01, 0x21, 0x42, 0x2D, 0x00, 0x64, 0x72, 0x6C, 0xFF,
};
static Vec lbl_2_data_1E00 = { 0.0f, 0.0f, -16.5f };
static Vec lbl_2_data_1E0C = { 0.0f, 0.0f, 0.0f };
static Vec lbl_2_data_1E18 = { 0.0f, 1.0f, 0.0f };
u32 lbl_2_data_1E24[1] = { 0 };
// A second copy of the debug menu labels and tables
u32 lbl_2_data_1E28[0x2C4 / 4] = {
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
    0x07000000,
};
Vec lbl_2_data_20EC = { 0.8f, -1.1f, -4.9f };

// .text:0x00016724 size:0x14C
void fn_2_16724(void) {
    Mtx44 proj;

    lbl_2_bss_1010C._48.x = lbl_2_data_20EC.x;
    lbl_2_bss_1010C._48.y = lbl_2_data_20EC.y;
    lbl_2_bss_1010C._48.z = lbl_2_data_20EC.z;
    lbl_2_bss_1010C._3C.x = 0.0f;
    lbl_2_bss_1010C._3C.y = 0.0f;
    lbl_2_bss_1010C._3C.z = 10.0f;
    C_MTXFrustum(proj, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
    GXSetProjection(proj, GX_PERSPECTIVE);
    fn_800B806C(0, -240.0f, 240.0f, -320.0f, 320.0f, -512.0f, -1.0f, 1280.0f);
    lbl_2_bss_1010C._54 = 0;
    lbl_2_bss_1010C._38 = 0.0f;
    lbl_2_bss_1010C._30 = 0;
    lbl_2_bss_1010C._32 = 0;
}

// .text:0x000166CC size:0x58
void fn_2_166CC(void) {
    u8 stadium = g_d_GameSettings.StadiumID;

    g_d_GameSettings.StadiumID = 0;
    fn_8001CB10(lbl_2_data_1DD4, 4);
    fn_8001CCC8();
    g_d_GameSettings.StadiumID = stadium;
}

// .text:0x00016664 size:0x68
void fn_2_16664(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        LITXForm(lbl_8036E548._00AC[i], lbl_2_bss_10164._14);
    }
}

// .text:0x00016460 size:0x204
void fn_2_16460(void) {
    Vec angle;
    Vec offset = { 0.0f, 0.0f, 100.0f };
    Mtx rotX;
    Mtx rotY;
    Mtx rot;
    f32 cosY;
    f32 sinY;
    camera_803c639c_s* camera;

    angle.x = lbl_2_bss_1010C._30;
    angle.y = lbl_2_bss_1010C._32;
    angle.z = 0.0f;
    PSVECScale(&angle, 0.0000958738f, &angle);
    PSMTXRotRad(rotX, 'X', angle.x);
    PSMTXRotRad(rotY, 'Y', angle.y);
    sinY = rotY[0][2];
    cosY = rotY[0][0];
    PSMTXConcat(rotY, rotX, rot);
    PSMTXMultVec(rot, &offset, &lbl_2_bss_1010C._3C);
    lbl_2_bss_1010C._48.x += lbl_2_bss_1010C._38 * sinY - lbl_2_bss_1010C._34 * cosY;
    lbl_2_bss_1010C._48.z += lbl_2_bss_1010C._38 * cosY + lbl_2_bss_1010C._34 * sinY;
    lbl_2_bss_1010C._3C.x += lbl_2_bss_1010C._48.x;
    lbl_2_bss_1010C._3C.y += lbl_2_bss_1010C._48.y;
    lbl_2_bss_1010C._3C.z += lbl_2_bss_1010C._48.z;
    fn_80052D70(&lbl_2_bss_1010C);
    camera = fn_80052768_getCamera(0);
    camera->eye.x = lbl_2_data_1E00.x;
    camera->eye.y = lbl_2_data_1E00.y;
    camera->eye.z = lbl_2_data_1E00.z;
    camera->target.x = lbl_2_data_1E0C.x;
    camera->target.y = lbl_2_data_1E0C.y;
    camera->target.z = lbl_2_data_1E0C.z;
    fn_80052968();
    makeLookAtMatrix(lbl_2_bss_1010C.mtx, &lbl_2_bss_1010C._48, &lbl_2_data_1E18, &lbl_2_bss_1010C._3C);
}

// .text:0x0001641C size:0x44
void fn_2_1641C(void) {
    fn_2_1A88();
    lbl_8034E9A0._46FC[0] = 0;
    lbl_8034E9A0._46FC[1] = -1;
    lbl_8034E9A0._46FC[2] = -1;
    lbl_8034E9A0._46FC[3] = -1;
    lbl_8034E9A0._4729 = 0;
}

// .text:0x00015AFC size:0x384
void fn_2_15AFC(s32 port, u16 hold, u16 trg, u16 rep) {
    s8 players[4];
    s32 id;
    s32 i;

    if (lbl_8034E9A0._46F8[port] != -1) {
        if (lbl_803297E0._CF5D[lbl_803C66B0._59[port]] != 0) {
            if (g_d_GameSettings._10 == 0 && lbl_803C66B0._59[0] == 1) {
                players[lbl_803C66B0._59[port]] = lbl_803C66B0._59[0];
            } else {
                players[lbl_803C66B0._59[port]] = lbl_8034E9A0._46F8[lbl_803C66B0._59[port]];
            }
            if (lbl_803C6028._7F[players[lbl_803C66B0._59[port]]] < 0 ? TRUE : FALSE) {
                if (g_d_GameSettings.GameModeSelected != 5) {
                    id = fn_8004E62C(players[lbl_803C66B0._59[port]], hold, trg, rep);
                    for (i = 0; i < 12; i++) {
                        if (lbl_800FE5D4[i] == id) {
                            id = i;
                            break;
                        }
                    }
                    lbl_2_bss_F410._10[lbl_803C66B0._59[port]] = id;
                    fn_800625A4(lbl_803C66B0._59[port], 3);
                } else {
                    id = fn_8004D57C(hold, trg, rep);
                    for (i = 0; i < 6; i++) {
                        if (id == lbl_800FE930[lbl_80361B20[0xF4]][i]) {
                            id = i;
                            break;
                        }
                    }
                    lbl_2_bss_F410._10[0] = id;
                    fn_2_12238();
                    lbl_803CBBC4 = 3;
                }
                lbl_803297E0._CF5D[lbl_803C66B0._59[port]] = 0;
            }
        } else if (lbl_803297E0._CF5D[lbl_803C66B0._59[port]] == 0) {
            if (trg & 0x100) {
                if (fn_2_35D0(lbl_803C66B0._59[port]) == 0) {
                    fn_2_1560C(lbl_803C66B0._59[port]);
                }
            } else if (trg & 0x200) {
                if (fn_2_35D0(lbl_803C66B0._59[port]) == 0) {
                    fn_2_151BC(lbl_803C66B0._59[port]);
                }
            } else if (trg & 0x20) {
                if (fn_2_35D0(lbl_803C66B0._59[port]) == 0 && g_d_GameSettings.GameModeSelected != 5) {
                    lbl_803297E0._CF5D[lbl_803C66B0._59[port]] = 1;
                }
            } else if (trg & 0x10) {
                if (fn_2_35D0(lbl_803C66B0._59[port]) == 0) {
                                if (lbl_2_bss_100B8._10[lbl_803C66B0._59[port]] == 0) {
                        lbl_2_bss_F468._45[lbl_803C66B0._59[port]] = 1;
                        lbl_2_bss_F468._4B[lbl_803C66B0._59[port]] = 1;
                        lbl_2_bss_F468._47[lbl_803C66B0._59[port]] = 0;
                        sndFXStartEx(0x1BF, lbl_800EFBA4[8], 0x3F, 0);
                    }
                }
            }
        }
    }
}

// .text:0x00015A90 size:0x6C
void fn_2_15A90(s32* value, u8 port, s32 max) {
    u16 buttons = lbl_8034E9A0._472C[port]._4;

    if (buttons & 1) {
        (*value)--;
        if (*value < 0) {
            *value = max;
        }
    } else if (buttons & 2) {
        (*value)++;
        if (*value > max) {
            *value = 0;
        }
    }
}

// .text:0x0001560C size:0x484
void fn_2_1560C(u8 port) {
    s32 player;

    if (g_d_GameSettings.GameModeSelected == 5) {
        if (lbl_2_bss_100B8._1C[0] != 0 || lbl_2_bss_100B8._42[0] != 0) {
            return;
        }
        lbl_8034E9A0._46E0[0] = lbl_800FE930[lbl_80361B20[0xF4]][lbl_2_bss_F410._10[0]];
        lbl_2_bss_100B8._10[0] = 1;
        lbl_2_bss_100B8._12[0] = 1;
        fn_8004D4F0(lbl_8034E9A0._46F8[0], lbl_8034E9A0._46E0[0], 1);
        fn_2_14BB8(0, 0);
        lbl_803CBBCC->_4 = 4;
    } else {
        if (lbl_2_bss_100B8._1C[port] != 0 || lbl_2_bss_100B8._42[port] != 0) {
            return;
        }
        if (g_d_GameSettings._10 == 0 && lbl_8036E548._2C50[port]->_25D == 0 && port != 0) {
            return;
        }
        fn_2_14BB8(port, 0);
        if (lbl_2_bss_100B8._10[port] != 0) {
            return;
        }
        lbl_8034E9A0._46E0[port] = lbl_800FE5D4[lbl_2_bss_F410._10[port]];
        if (g_d_GameSettings._10 == 0 && port != 0) {
            if (lbl_8034E9A0._46F8[0] == 0) {
                fn_8004E5B4(1, lbl_8034E9A0._46E0[port], 1);
            } else {
                fn_8004E5B4(0, lbl_8034E9A0._46E0[port], 1);
            }
        } else {
            fn_8004E5B4(lbl_8034E9A0._46F8[port], lbl_8034E9A0._46E0[port], 1);
        }
        lbl_2_bss_100B8._10[port] = 1;
        lbl_2_bss_100B8._12[port] = 1;
        lbl_8034E9A0._4757[lbl_800FE5D4[lbl_2_bss_F410._10[port]]] = 1;
        if (port == 0 && g_d_GameSettings._10 == 0 && g_d_GameSettings.GameModeSelected != 5) {
            fn_800625A4(1, 6);
            player = lbl_8034E9A0._46F8[0] == 0;
            lbl_803C66B0._59[port] = 1;
            lbl_803C6028._74[player] = 1;
            if (lbl_2_bss_F410._10[0] == 0) {
                lbl_2_bss_F410._10[1] = 1;
            } else {
                lbl_2_bss_F410._10[1] = 0;
            }
            switch (player) {
            case 0:
                fn_8004E504(0, lbl_2_bss_F410._10[1], -1, -1, -1);
                break;
            case 1:
                fn_8004E504(0, -1, lbl_2_bss_F410._10[1], -1, -1);
                break;
            case 2:
                fn_8004E504(0, -1, -1, lbl_2_bss_F410._10[1], -1);
                break;
            case 3:
                fn_8004E504(0, -1, -1, -1, lbl_2_bss_F410._10[1]);
                break;
            }
            lbl_803C6724._1 = lbl_2_bss_F410._10[1];
            fn_2_15104(lbl_2_bss_F410._10[1], -1, 1, 1);
        }
    }
}

// .text:0x000151BC size:0x450
void fn_2_151BC(u8 port) {
    s32 i;

    if (lbl_2_bss_100B8._10[port] != 0) {
        lbl_2_bss_100B8._10[port] = 0;
        lbl_2_bss_100B8._12[port] = 0;
        lbl_8034E9A0._4757[lbl_8034E9A0._46E0[port]] = 0;
        fn_8004E5B4(port, lbl_8034E9A0._46E0[port], 0);
    } else if (port != 0) {
        if (lbl_803297E0._CF5D[port] != 0) {
            lbl_803297E0._CF5D[port] = 0;
        }
        if (g_d_GameSettings._10 == 0) {
            fn_2_16A74(port, 0);
            lbl_803C6028._7F[lbl_8034E9A0._46F8[lbl_803C66B0._59[0]]] = -1;
            lbl_2_bss_100B8._10[0] = 0;
            lbl_2_bss_100B8._12[0] = 0;
            lbl_803C66B0._59[0] = 0;
            lbl_8034E9A0._4757[lbl_8034E9A0._46E0[0]] = 0;
            fn_8004E5B4(0, lbl_8034E9A0._46E0[0], 0);
            lbl_8034E9A0._46E0[0] = -1;
            lbl_8034E9A0._46E0[1] = -1;
            fn_800625A4(0, 4);
            fn_2_14BB8(port ^ 1, 1);
        } else {
            lbl_8034E9A0._46FC[lbl_8034E9A0._46F8[1]] = 1;
            if (lbl_2_bss_100B8._10[0] != 0) {
                lbl_803C66B0._59[1] = 1;
                lbl_803C66B0._59[0] = 1;
            } else {
                lbl_803C66B0._59[1] = 0;
                lbl_803C66B0._59[0] = 0;
            }
            lbl_803C5EA4._5 = 0;
            lbl_803C6028._7F[lbl_8034E9A0._46F8[lbl_803C66B0._59[port]]] = -1;
            if (lbl_803CBBCC->_6 == 10 && lbl_2_bss_100B8._10[0] == 0) {
                lbl_8034E9A0._4757[lbl_8034E9A0._46E0[0]] = 0;
                fn_8004E5B4(0, lbl_8034E9A0._46E0[0], 0);
                lbl_8034E9A0._46E0[0] = -1;
                lbl_8034E9A0._46E0[1] = -1;
            }
            lbl_2_bss_100B8._10[port] = 0;
            lbl_2_bss_100B8._12[port] = 0;
            lbl_803C66B0._59[port] = 0;
            if (lbl_2_bss_100B8._10[0] != 0) {
                fn_800625A4(port, 5);
            } else {
                fn_800625A4(port, 4);
            }
        }
    } else {
        lbl_803C6028._7F[lbl_8034E9A0._46F8[0]] = -1;
        if (lbl_8034E9A0._46F8[1] != -1) {
            lbl_803C6028._7F[lbl_8034E9A0._46F8[1]] = -1;
        }
        lbl_803297E0._CF5D[1] = 0;
        lbl_803297E0._CF5D[0] = 0;
        lbl_2_bss_100B4 = 1;
        for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
            fn_2_16A74(i, 0);
        }
        if (g_d_GameSettings.GameModeSelected == 5) {
            lbl_803CBBC4 = 2;
        } else {
            if (g_d_GameSettings._10 == 0) {
                fn_800625A4(0, 2);
                fn_800625A4(1, 2);
            } else if (g_d_GameSettings._10 == 1) {
                fn_800625A4(0, 2);
                fn_800625A4(1, 2);
            }
            lbl_803CBCD8._2 = 20;
        }
        lbl_2_bss_F468._46 = 0;
        lbl_2_bss_F468._45[0] = 0;
        lbl_803CBBCC->_4 = 8;
    }
    if (g_d_GameSettings._10 == 1) {
        fn_2_14BB8(port, 1);
    }
    fn_2_1C34(0x200);
}

// .text:0x00015104 size:0xB8
BOOL fn_2_15104(s32 a, s32 b, u8 port, u8 value) {
    if (b != a) {
        lbl_2_bss_100B8._1C[port] = 1;
    } else if (lbl_2_bss_100B8._1C[port] != 0) {
        if (++lbl_2_bss_100B8._1C[port] >= 15) {
            lbl_2_bss_100B8._14[port] = 1;
            lbl_2_bss_100B8._1C[port] = 0;
            fn_2_16A48(port, value);
        }
    }
    return lbl_2_bss_100B8._1C[port] == 0;
}

// .text:0x000150D0 size:0x34
void fn_2_150D0(u8 port) {
    if (lbl_2_bss_100B8._14[port] == 0) {
        lbl_2_bss_100B8._14[port] = 1;
        lbl_2_bss_100B8._1C[port] = 0;
    }
}

// .text:0x00014FB8 size:0x118
void fn_2_14FB8(s32 team) {
    s32 ids[2];
    s32 i;

    ids[0] = lbl_80108EC4[lbl_2_bss_F410._10[0]];
    ids[1] = lbl_80108EC4[lbl_2_bss_F410._10[1]];
    do {
        ids[team] = fn_2_14F8(0, 19);
        for (i = 0; i < 12; i++) {
            if (lbl_80108EC4[i] == ids[team]) {
                break;
            }
        }
    } while (i == 12 || ids[0] == ids[1]);
    lbl_2_bss_F410._10[team] = i;
}

// .text:0x00014CA0 size:0x318
void fn_2_14CA0(u8 port, Pad04B0* pad) {
    s32 player;
    s32 id;
    s32 i;

    if (g_d_GameSettings.GameModeSelected != 5) {
        if (g_d_GameSettings._10 == 0 && port != 0) {
            player = lbl_8034E9A0._46F8[0] == 0;
            lbl_803C6028._74[player] = 1;
        } else {
            player = lbl_8034E9A0._46F8[port];
            lbl_803C6028._74[player] = 0;
        }
        switch (player) {
        case 0:
            fn_8004E504(0, lbl_2_bss_F410._10[port], -1, -1, -1);
            break;
        case 1:
            fn_8004E504(0, -1, lbl_2_bss_F410._10[port], -1, -1);
            break;
        case 2:
            fn_8004E504(0, -1, -1, lbl_2_bss_F410._10[port], -1);
            break;
        case 3:
            fn_8004E504(0, -1, -1, -1, lbl_2_bss_F410._10[port]);
            break;
        }
        id = fn_8004E62C(player, pad->_0, pad->_2, pad->_4);
        for (i = 0; i < 12; i++) {
            if (lbl_800FE5D4[i] == id) {
                id = i;
                break;
            }
        }
        lbl_2_bss_F410._10[port] = id;
    } else {
        id = fn_8004D57C(pad->_0, pad->_2, pad->_4);
        for (i = 0; i < 6; i++) {
            if (id == lbl_800FE930[lbl_80361B20[0xF4]][i]) {
                id = i;
                break;
            }
        }
        lbl_2_bss_F410._10[0] = id;
    }
}

// .text:0x00014BB8 size:0xE8
void fn_2_14BB8(u8 port, s32 mode) {
    switch (mode) {
    case 0:
        AnimateCharacter(port, 0x6A, 0, 1, 1, 0, 0, -1);
        QueueCharacterAnimation(port, 0x6B, 1, 1, 0, 0, -1);
        lbl_2_bss_100B8._40[port] = 0;
        break;
    case 1:
        AnimateCharacter(port, 0x69, 1, 1, 1, 0, 0, -1);
        lbl_2_bss_100B8._40[port] = 1;
        break;
    }
}

// .text:0x00014790 size:0x428
void fn_2_14790(void) {
    s8 port = -1;
    s32 i;
    s32 prev;

    if (lbl_2_bss_100B8._19 == 0 || lbl_2_bss_100B8._1A != 0 || g_d_GameSettings.GameModeSelected == 5) {
        return;
    }
    if (lbl_803C66B0._0E == 1) {
        return;
    }
    for (i = 1; i < 4; i++) {
        if (lbl_8034E9A0._46FC[i] != 0 && (lbl_803C77B8[i]._02 & 0x100)) {
            port = i;
            break;
        }
    }
    if (port != -1 && lbl_803C5EA4._5 == 0) {
        if (lbl_2_bss_100B8._10[1] != 0) {
            lbl_2_bss_100B8._10[1] = 0;
            lbl_2_bss_100B8._12[1] = 0;
            fn_8004E5B4(1, lbl_8034E9A0._46E0[1], 0);
            lbl_8034E9A0._4757[lbl_8034E9A0._46E0[1]] = 0;
            lbl_8034E9A0._46E0[1] = -1;
        }
        lbl_8034E9A0._46FC[port] = 0;
        lbl_803C5EA4._5 = 1;
        lbl_8034E9A0._46F8[port] = lbl_8034E9A0._46F8[1];
        lbl_8034E9A0._46F8[1] = port;
        lbl_803C66B0._59[0] = 0;
        lbl_803C66B0._59[1] = 1;
        if (lbl_8034E9A0._4757[0] != 0 || lbl_2_bss_F410._10[0] == 0) {
            lbl_803C6724._1 = 1;
        } else {
            lbl_803C6724._1 = 0;
        }
        lbl_803C6028._74[lbl_8034E9A0._46F8[1]] = 0;
        fn_800625A4(1, 1);
        g_d_GameSettings._10 = 1;
        lbl_803297E0._CF5D[1] = 0;
        lbl_803C6028._7F[1] = -1;
        if (lbl_2_bss_F410._10[0] == 0) {
            lbl_2_bss_F410._10[1] = 1;
        } else {
            lbl_2_bss_F410._10[1] = 0;
        }
        lbl_803C6028._74[lbl_8034E9A0._46F8[1]] = 0;
        switch (lbl_8034E9A0._46F8[1]) {
        case 0:
            fn_8004E504(0, lbl_2_bss_F410._10[1], -1, -1, -1);
            break;
        case 1:
            fn_8004E504(0, -1, lbl_2_bss_F410._10[1], -1, -1);
            break;
        case 2:
            fn_8004E504(0, -1, -1, lbl_2_bss_F410._10[1], -1);
            break;
        case 3:
            fn_8004E504(0, -1, -1, -1, lbl_2_bss_F410._10[1]);
            break;
        }
        prev = -1;
        while (!fn_2_15104(lbl_2_bss_F410._10[1], prev, 1, 1)) {
            prev = lbl_2_bss_F410._10[1];
        }
        lbl_8034E9A0._4704 = 0;
        if (lbl_2_bss_F468._46 != 0) {
            lbl_2_bss_F468._46 = 0;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        }
        lbl_8034E9A0._472C[1]._0 = lbl_8034E9A0._472C[1]._2 = lbl_8034E9A0._472C[1]._4 = 0;
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    }
}

// .text:0x00014574 size:0x21C
void fn_2_14574(Pad04B0* pad) {
    f32 pos;

    if (pad->_4 & 8) {
        if (pad->_0 & 0x200) {
            lbl_2_bss_1010C._48.x += 0.1f;
        } else if (pad->_0 & 0x100) {
            lbl_2_bss_1010C._48.y += 1.0f;
        } else if (pad->_0 & 0x400) {
            lbl_2_bss_1010C._48.z += 0.1f;
        }
    } else if (pad->_4 & 4) {
        if (pad->_0 & 0x200) {
            lbl_2_bss_1010C._48.x -= 0.1f;
        } else if (pad->_0 & 0x100) {
            lbl_2_bss_1010C._48.y -= 0.1f;
        } else if (pad->_0 & 0x400) {
            lbl_2_bss_1010C._48.z -= 0.1f;
        }
    } else if (pad->_4 & 1) {
        if (pad->_0 & 0x200) {
            pos = 320.0f + lbl_2_data_20F8[0].x;
            pos -= 0.1;
            lbl_2_data_20F8[0].x = pos - 320.0f;
        } else if (pad->_0 & 0x100) {
            pos = 320.0f + lbl_2_data_20F8[0].y;
            pos -= 0.1;
            lbl_2_data_20F8[0].y = pos - 320.0f;
        }
    } else if (pad->_4 & 2) {
        if (pad->_0 & 0x200) {
            pos = 320.0f + lbl_2_data_20F8[0].x;
            pos += 0.1;
            lbl_2_data_20F8[0].x = pos - 320.0f;
        } else if (pad->_0 & 0x100) {
            pos = 320.0f + lbl_2_data_20F8[0].y;
            pos += 0.1;
            lbl_2_data_20F8[0].y = pos - 320.0f;
        }
    }
}

// .text:0x00014220 size:0x354
void fn_2_14220(Pad04B0* pad) {
    switch (lbl_2_bss_100B8._50) {
    case 0:
        fn_2_14164(pad);
        break;
    case 1:
        fn_2_1406C(pad);
        break;
    case 2:
        fn_2_13D70(pad);
        break;
    case 3:
        fn_2_13CA0(pad);
        break;
    case 4:
        fn_2_13BA4(pad);
        break;
    }
}

// .text:0x00014164 size:0xBC
void fn_2_14164(Pad04B0* pad) {
    if (pad->_4 & 8) {
        lbl_2_bss_100B8._51--;
        if (lbl_2_bss_100B8._51 == 0) {
            lbl_2_bss_100B8._51 = 4;
        }
    } else if (pad->_4 & 4) {
        lbl_2_bss_100B8._51++;
        if (lbl_2_bss_100B8._51 == 5) {
            lbl_2_bss_100B8._51 = 1;
        }
    } else if (pad->_2 & 0x100) {
        lbl_2_bss_100B8._50 = lbl_2_bss_100B8._51;
    } else if (pad->_2 & 0x200) {
        lbl_2_bss_100B8._4C = 0;
        lbl_2_bss_100B8._50 = 0;
        lbl_2_bss_100B8._51 = 1;
        lbl_2_bss_100B8._4B = 0;
    }
}

// .text:0x0001406C size:0xF8
void fn_2_1406C(Pad04B0* pad) {
    if (pad->_4 & 8) {
        lbl_2_bss_100B8._4C--;
        if (lbl_2_bss_100B8._4C < 0) {
            lbl_2_bss_100B8._4C = 5;
        }
    } else if (pad->_4 & 4) {
        lbl_2_bss_100B8._4C++;
        if (lbl_2_bss_100B8._4C == 6) {
            lbl_2_bss_100B8._4C = 0;
        }
    } else if (pad->_4 & 1) {
        g_d_GameSettings._1A[lbl_2_bss_100B8._4C] ^= 1;
    } else if (pad->_4 & 2) {
        g_d_GameSettings._1A[lbl_2_bss_100B8._4C] ^= 1;
    } else if (pad->_2 & 0x200) {
        lbl_2_bss_100B8._50 = 0;
    }
}

// .text:0x00013D70 size:0x2FC
void fn_2_13D70(Pad04B0* pad) {
    s32 i;

    if (pad->_4 & 8) {
        lbl_2_bss_100B8._4D--;
        if (lbl_2_bss_100B8._4D < 0) {
            lbl_2_bss_100B8._4D = 53;
        }
    } else if (pad->_4 & 4) {
        lbl_2_bss_100B8._4D++;
        if (lbl_2_bss_100B8._4D == 54) {
            lbl_2_bss_100B8._4D = 0;
        }
    } else if (pad->_4 & 1) {
        lbl_80361B20[lbl_2_bss_100B8._4D] ^= 1;
    } else if (pad->_4 & 2) {
        lbl_80361B20[lbl_2_bss_100B8._4D] ^= 1;
    } else if (pad->_2 & 0x800) {
        for (i = 0; i < 54; i++) {
            lbl_80361B20[i] = 1;
        }
    } else if (pad->_2 & 0x400) {
        for (i = 0; i < 54; i++) {
            lbl_80361B20[i] = 0;
        }
    } else if (pad->_2 & 0x200) {
        lbl_2_bss_100B8._50 = 0;
    }
}

// .text:0x00013CA0 size:0xD0
// Outside the unit's .text range: inlined into fn_2_14220 (see report)
static inline void fn_2_13CA0(Pad04B0* pad) {
    if (pad->_4 & 8) {
        lbl_2_bss_100B8._4E--;
        if (lbl_2_bss_100B8._4E < 0) {
            lbl_2_bss_100B8._4E = 5;
        }
    } else if (pad->_4 & 4) {
        lbl_2_bss_100B8._4E++;
        if (lbl_2_bss_100B8._4E == 6) {
            lbl_2_bss_100B8._4E = 0;
        }
    } else if (pad->_4 & 1) {
        lbl_80361B20[0xF5] ^= 1;
    } else if (pad->_4 & 2) {
        lbl_80361B20[0xF5] ^= 1;
    } else if (pad->_2 & 0x200) {
        lbl_2_bss_100B8._50 = 0;
    }
}

// .text:0x00013BA4 size:0xFC
// Outside the unit's .text range: inlined into fn_2_14220 (see report)
static inline void fn_2_13BA4(Pad04B0* pad) {
    if (pad->_4 & 8) {
        lbl_2_bss_100B8._4F--;
        if (lbl_2_bss_100B8._4F < 0) {
            lbl_2_bss_100B8._4F = 3;
        }
    } else if (pad->_4 & 4) {
        lbl_2_bss_100B8._4F++;
        if (lbl_2_bss_100B8._4F == 4) {
            lbl_2_bss_100B8._4F = 0;
        }
    } else if (pad->_4 & 1) {
        lbl_80361B20[0xE4 + lbl_2_bss_100B8._4F] ^= 1;
    } else if (pad->_4 & 2) {
        lbl_80361B20[0xE4 + lbl_2_bss_100B8._4F] ^= 1;
    } else if (pad->_2 & 0x200) {
        lbl_2_bss_100B8._4F = 0;
        lbl_2_bss_100B8._50 = 0;
    }
}
