#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_08E8.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/vec.h"
#include "musyx/musyx.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

typedef struct AramEntry08E8 {
    /* 0x0 */ u32 _0[4];
} AramEntry08E8; // size: 0x10

// One entry per character, 0x34 bytes (starMissionCompletionTracker)
typedef struct MenuMissionPair08E8 {
    /* 0x0 */ s8 _0;
    /* 0x1 */ s8 _1;
} MenuMissionPair08E8; // size: 0x2

typedef struct MenuCharDef08E8 {
    /* 0x00 */ s8 _00;
    /* 0x01 */ s8 _01;
    /* 0x02 */ u8 _02[0x1C - 0x2];
} MenuCharDef08E8; // size: 0x1C

typedef struct MenuCharacter08E8 {
    /* 0x00 */ MenuCharDef08E8* _00;
    /* 0x04 */ s8 _04;
    /* 0x05 */ s8 _05;
    /* 0x06 */ s8 _06;
    /* 0x07 */ s8 _07;
    /* 0x08 */ u8 _08[0x9 - 0x8];
    /* 0x09 */ MenuMissionPair08E8 _09[10];
    /* 0x1D */ MenuMissionPair08E8 _1D[10];
    /* 0x31 */ s8 _31;
    /* 0x32 */ u8 _32[0x34 - 0x32];
} MenuCharacter08E8; // size: 0x34

typedef struct SortEntry08E8 {
    /* 0x0 */ s32 key;
    /* 0x4 */ s32 value;
} SortEntry08E8; // size: 0x8

typedef struct MenuRosterEntry08E8 {
    /* 0x0 */ s16 _0;
    /* 0x2 */ u8 _2[0x6 - 0x2];
} MenuRosterEntry08E8; // size: 0x6

typedef struct MenuSlot08E8 {
    /* 0x0 */ u8 _0[0x2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3[0x5 - 0x3];
    /* 0x5 */ u8 _5;
    /* 0x6 */ u8 _6[0xA - 0x6];
} MenuSlot08E8; // size: 0xA

typedef struct MenuTracker08E8 {
    /* 0x0000 */ MenuCharacter08E8 _0000[0x36];
    /* 0x0AF8 */ MenuCharacter08E8 _0AF8[0x36];
    /* 0x15F0 */ u8 _15F0;
    /* 0x15F1 */ u8 _15F1[0x1606 - 0x15F1];
    /* 0x1606 */ u8 _1606;
    /* 0x1607 */ u8 _1607[0x16C0 - 0x1607];
    /* 0x16C0 */ s16 _16C0;
    /* 0x16C2 */ s16 _16C2;
    /* 0x16C4 */ u8 _16C4[0x40B8 - 0x16C4];
    /* 0x40B8 */ MenuRosterEntry08E8 _40B8[9];
    /* 0x40EE */ MenuSlot08E8 _40EE[0x33];
    /* 0x42EC */ u8 _42EC[0x43BC - 0x42EC];
    /* 0x43BC */ s16 _43BC;
    /* 0x43BE */ s16 _43BE;
    /* 0x43C0 */ u8 _43C0[0x43C2 - 0x43C0];
    /* 0x43C2 */ s8 _43C2[0x14];
    /* 0x43D6 */ u8 _43D6[0x36];
    /* 0x440C */ u8 _440C[0x4415 - 0x440C];
    /* 0x4415 */ u8 _4415;
    /* 0x4416 */ u8 _4416[0x4418 - 0x4416];
    /* 0x4418 */ u8 _4418;
    /* 0x4419 */ u8 _4419[0x441B - 0x4419];
    /* 0x441B */ u8 _441B;
    /* 0x441C */ u8 _441C;
    /* 0x441D */ u8 _441D;
    /* 0x441E */ u8 _441E;
    /* 0x441F */ u8 _441F;
    /* 0x4420 */ u8 _4420;
    /* 0x4421 */ u8 _4421;
    /* 0x4422 */ u8 _4422;
    /* 0x4423 */ u8 _4423;
    /* 0x4424 */ u8 _4424;
    /* 0x4425 */ u8 _4425;
    /* 0x4426 */ u8 _4426;
    /* 0x4427 */ u8 _4427;
    /* 0x4428 */ u8 _4428;
    /* 0x4429 */ u8 _4429;
    /* 0x442A */ u8 _442A;
    /* 0x442B */ u8 _442B[0x444A - 0x442B];
    /* 0x444A */ u8 _444A;
    /* 0x444B */ s8 _444B;
    /* 0x444C */ u8 _444C;
    /* 0x444D */ s8 _444D[0x36];
    /* 0x4483 */ s8 _4483[0x36];
    /* 0x44B9 */ s8 _44B9[0x36];
    /* 0x44EF */ s8 _44EF;
    /* 0x44F0 */ u8 _44F0[0x44F7 - 0x44F0];
    /* 0x44F7 */ u8 _44F7;
    /* 0x44F8 */ s8 _44F8[5];
    /* 0x44FD */ s8 _44FD;
} MenuTracker08E8;

extern MenuTracker08E8* lbl_2_bss_1A8248;

extern struct {
    /* 0x00 */ u8 _00[0x36];
    /* 0x36 */ u8 _36[0xC6 - 0x36];
    /* 0xC6 */ u8 _C6[5][4];
    /* 0xDA */ u8 _DA[0xF4 - 0xDA];
    /* 0xF4 */ u8 _F4;
} *lbl_2_bss_1A8244;

extern struct {
    /* 0x000000 */ u8 _000000[0x195424];
    /* 0x195424 */ s32 _195424;
    /* 0x195428 */ s32 _195428;
    /* 0x19542C */ s32 _19542C[15];
    /* 0x195468 */ u8 _195468[0x1972B8 - 0x195468];
    /* 0x1972B8 */ u8 _1972B8;
    /* 0x1972B9 */ u8 _1972B9[0x19769C - 0x1972B9];
    /* 0x19769C */ s32 _19769C;
    /* 0x1976A0 */ u8 _1976A0[0x19776E - 0x1976A0];
    /* 0x19776E */ s16 _19776E;
    /* 0x197770 */ s16 _197770;
    /* 0x197772 */ s16 _197772;
    /* 0x197774 */ s16 _197774;
    /* 0x197776 */ s16 _197776;
    /* 0x197778 */ s16 _197778;
    /* 0x19777A */ s16 _19777A;
    /* 0x19777C */ s16 _19777C;
    /* 0x19777E */ s16 _19777E;
    /* 0x197780 */ s16 _197780;
    /* 0x197782 */ s16 _197782;
    /* 0x197784 */ u8 _197784[0x197792 - 0x197784];
    /* 0x197792 */ s16 _197792;
    /* 0x197794 */ s16 _197794;
    /* 0x197796 */ s16 _197796;
    /* 0x197798 */ s16 _197798;
    /* 0x19779A */ u8 _19779A[0x197843 - 0x19779A];
    /* 0x197843 */ s8 _197843;
    /* 0x197844 */ u8 _197844[0x197846 - 0x197844];
    /* 0x197846 */ u8 _197846;
    /* 0x197847 */ u8 _197847;
    /* 0x197848 */ u8 _197848[0x19784A - 0x197848];
    /* 0x19784A */ u8 _19784A;
    /* 0x19784B */ u8 _19784B[0x197863 - 0x19784B];
    /* 0x197863 */ s8 _197863;
    /* 0x197864 */ u8 _197864[0x197866 - 0x197864];
    /* 0x197866 */ s8 _197866;
    /* 0x197867 */ u8 _197867;
    /* 0x197868 */ s8 _197868[0x36];
    /* 0x19789E */ u8 _19789E[0x1978F1 - 0x19789E];
    /* 0x1978F1 */ u8 _1978F1;
    /* 0x1978F2 */ u8 _1978F2[0x1978F4 - 0x1978F2];
    /* 0x1978F4 */ u8 _1978F4;
} *lbl_2_bss_1A824C;

extern struct {
    /* 0x0 */ s32 _0;
    /* 0x4 */ s32 _4;
    /* 0x8 */ s32 _8;
} lbl_803C7898;

typedef struct MenuPlayer08E8 {
    /* 0x000 */ u8 _000[0x8];
    /* 0x008 */ void* _008;
    /* 0x00C */ u8 _00C[0x10 - 0xC];
    /* 0x010 */ s32 _010;
    /* 0x014 */ s32 _014;
    /* 0x018 */ s32 _018;
    /* 0x01C */ s32 _01C;
    /* 0x020 */ s32 _020;
    /* 0x024 */ u8 _024[0x34 - 0x24];
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ f32 _040;
    /* 0x044 */ f32 _044;
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x255 - 0x4C];
    /* 0x255 */ s8 _255;
    /* 0x256 */ u8 _256;
    /* 0x257 */ s8 _257;
    /* 0x258 */ u8 _258[0x27C - 0x258];
} MenuPlayer08E8; // size: 0x27C

typedef struct MenuModelList08E8 {
    /* 0x0 */ u16 _00;
} MenuModelList08E8;

typedef struct MenuActor08E8 {
    /* 0x00 */ u8 _00[0x98];
    /* 0x98 */ u8 _98;
} MenuActor08E8;

typedef struct MenuActorRef08E8 {
    /* 0x00 */ MenuActor08E8* _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ u8 _08[0xE - 0x8];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u8 _10[0x54 - 0x10];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u8 _64[0x68 - 0x64];
    /* 0x68 */ void* _68;
    /* 0x6C */ u8 _6C;
} MenuActorRef08E8;

typedef struct MenuFielder08E8 {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x25D - 0x40];
    /* 0x25D */ u8 _25D;
} MenuFielder08E8;

typedef struct MenuBufSet08E8 {
    /* 0x00 */ u8* _00[4];
    /* 0x10 */ u8 _10[0x14 - 0x10];
} MenuBufSet08E8; // size: 0x14

typedef struct LITObj {
    /* 0x00 */ u8 _00[0xC0];
} LITObj; // size: 0xC0

extern struct {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ MenuModelList08E8* _0060;
    /* 0x0064 */ u8 _0064[0xAC - 0x64];
    /* 0x00AC */ LITObj* _00AC[4];
    /* 0x00BC */ u8 _00BC[0x13C - 0xBC];
    /* 0x013C */ void* _013C;
    /* 0x0140 */ u8 _0140[0xC04 - 0x140];
    /* 0x0C04 */ MenuPlayer08E8 _0C04[4];
    /* 0x15F4 */ u8 _15F4[0x2C50 - 0x15F4];
    /* 0x2C50 */ MenuFielder08E8* _2C50[14];
    /* 0x2C88 */ void* _2C88;
    /* 0x2C8C */ void* _2C8C;
    /* 0x2C90 */ u32 _2C90;
    /* 0x2C94 */ u32 _2C94;
    /* 0x2C98 */ u32 _2C98;
    /* 0x2C9C */ u32 _2C9C;
    /* 0x2CA0 */ u8 _2CA0[0x2CEC - 0x2CA0];
    /* 0x2CEC */ MenuBufSet08E8 _2CEC[4];
    /* 0x2D3C */ u8 _2D3C[0x2D6A - 0x2D3C];
    /* 0x2D6A */ s8 _2D6A[4];
    /* 0x2D6E */ u8 _2D6E[0x2D77 - 0x2D6E];
    /* 0x2D77 */ u8 _2D77;
    /* 0x2D78 */ u8 _2D78[0x2D7B - 0x2D78];
    /* 0x2D7B */ u8 _2D7B;
    /* 0x2D7C */ u8 _2D7C;
    /* 0x2D7D */ u8 _2D7D[0x2D7F - 0x2D7D];
    /* 0x2D7F */ s8 _2D7F[9];
    /* 0x2D88 */ u8 _2D88;
    /* 0x2D89 */ s8 _2D89[4];
} lbl_8036E548;

typedef struct DrawCallback08E8 {
    /* 0x0 */ s32 _0;
    /* 0x4 */ void (*fn)(void);
} DrawCallback08E8; // size: 0x8

typedef struct MenuCharEntry08E8 {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1;
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3;
    /* 0x4 */ u8 _4[0x6 - 0x4];
} MenuCharEntry08E8; // size: 0x6

typedef struct MenuMissionDef08E8 {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
    /* 0x4 */ s16 _4;
    /* 0x6 */ s16 _6;
    /* 0x8 */ s16 _8;
} MenuMissionDef08E8; // size: 0xA

extern MenuCharEntry08E8 lbl_800E8558[54];
extern MenuCharDef08E8 lbl_801094E4[54];
extern u8 lbl_80361C18[0x38];
extern struct {
    /* 0x0000 */ u8 _0000[0x4380];
    /* 0x4380 */ u8 _4380[6][0x48];
} lbl_8034E9A0;
typedef struct MenuTextLayout08E8 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[15];
} MenuTextLayout08E8;

extern struct {
    /* 0x000 */ u8 _000[0x798];
    /* 0x798 */ MenuTextLayout08E8* _798[16];
} lbl_80366B18;
extern MenuMissionDef08E8 lbl_80109AE8[32][10];
extern MenuMissionDef08E8 lbl_8010A768[32][10];
// The menus' camera
typedef struct MenuCamera08E8 {
    /* 0x00 */ Mtx _00;
    /* 0x30 */ u8 _30[0x3C - 0x30];
    /* 0x3C */ f32 _3C;
    /* 0x40 */ Vec _40;
    /* 0x4C */ Vec _4C;
    /* 0x58 */ u8 _58[0x5C - 0x58];
} MenuCamera08E8; // size: 0x5C

extern MenuCamera08E8 lbl_2_bss_1A81D4;
extern struct {
    /* 0x0000 */ u8 _0000[0x307A];
    /* 0x307A */ u8 _307A;
} *lbl_2_bss_340140;
extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x2E - 0xA];
    /* 0x2E */ u16 _2E;
} lbl_80353A90;
extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_803CBBC0;
extern u32 lbl_803CBD0C;
extern u8 lbl_803CB8F0[8];
extern u8 lbl_800F5D98[];
extern u8 lbl_800F71D8[];
extern u8 lbl_2_data_2E64[];
extern s16 lbl_2_data_373C[20];
extern f32 lbl_2_data_3804[][3];
extern s32 lbl_2_data_3840[][3];
extern s32 lbl_2_data_387C[][3];
extern s32 lbl_2_data_38B8;
extern u8 lbl_2_data_3CC0[];
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
extern void LITXForm(LITObj* light, Mtx view);
extern void LITAlloc(LITObj** light);
extern void LITInitAttn(LITObj* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern void LITInitPos(LITObj* light, f32 x, f32 y, f32 z);
extern void LITInitColor(LITObj* light, GXColor color);
extern void LITInitDir(LITObj* light, f32 nx, f32 ny, f32 nz);
extern BOOL fn_8006CDC0(s32 index);
extern void starMissionRelated2(void);
extern void fn_8003BF54(s32, s32, s32, s32, s32, s32, s32, s32, s32);

extern void* _OSAllocFromHeap(u32 align, u32 size);

// rep_09B8 (an empty function there)
extern void fn_2_513E0(void* text, s32, s32, s32, s32, s32, s32, s32);

extern void fn_80052968(void);
extern void fn_80023B04(s32);
extern void fn_80014204(s32);
extern void* fn_80023AA4(void);
extern MenuActorRef08E8* fn_800111D8(MenuFielder08E8* fielder);
extern camera_803c639c_s* fn_80052734(s32);
extern s32 fn_800527BC(void);
extern void ACTSetAnimation(MenuActor08E8* actor, void* animBank, char* sequenceName, u16 seqNum, f32 time, f32 speed);
extern void fn_800B4CA0(MenuActor08E8* actor, f32 frame);
extern void fn_800B4C04(MenuActor08E8* actor, f32 speed);
extern void fn_800B4AFC(MenuActor08E8* actor, u8 flag);
extern void Set_FUN_800b2b6c(MenuActor08E8* actor, void* arg1);
extern void fn_800BDA24(MenuActorRef08E8* ref);
extern u8 fn_800B3C04(s32 arg0, MenuActor08E8* actor, Mtx mtx);

// rep_0B08
extern void fn_2_6A87C(void);
extern s32 fn_2_68690(s32);
extern void fn_2_68DAC(s32, Vec*);

// rep_1028
extern void fn_2_9007C(void);

// rep_10C0
extern void fn_2_93BF8(MenuCamera08E8* camera);

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
u16 lbl_2_data_13238[2] = { 0x16, 0xB };
AramEntry08E8 lbl_2_data_1323C = { { 0x0000040B, 0x400B2CB8, 0x18E3F000, 0x00053454 } };
AramEntry08E8 lbl_2_data_1324C = { { 0x0000040B, 0x40076AE0, 0x18ED7000, 0x00036BC8 } };
AramEntry08E8 lbl_2_data_1325C = { { 0x0000040B, 0x4011EC24, 0x18F0E000, 0x000D8818 } };
AramEntry08E8 lbl_2_data_1326C = { { 0x0000040B, 0x40069DFC, 0x18E92800, 0x000408D0 } };
static AramEntry08E8 lbl_2_data_1327C = { { 0x0000040B, 0x4009947C, 0x18FE7000, 0x0002F758 } };
static AramEntry08E8 lbl_2_data_1328C = { { 0x0000040B, 0x4006DC60, 0x19016800, 0x00024F50 } };
static AramEntry08E8 lbl_2_data_1329C = { { 0x0000040B, 0x400A2AB4, 0x1903B800, 0x000371F8 } };
static AramEntry08E8 lbl_2_data_132AC = { { 0x0000040B, 0x400A97F4, 0x19073000, 0x00048EEC } };
static AramEntry08E8 lbl_2_data_132BC = { { 0x0000040B, 0x4007B2D0, 0x190BC000, 0x0002B520 } };
static AramEntry08E8 lbl_2_data_132CC = { { 0x0000040B, 0x400AF4E8, 0x190E7800, 0x0004D804 } };
AramEntry08E8 lbl_2_data_132DC = { { 0x0000040B, 0x4023491C, 0x19135800, 0x00082928 } };
Vec lbl_2_data_132EC = { 0.0f, 0.0f, 0.0f };
u32 lbl_2_data_132F8[3] = { 0 };
Vec lbl_2_data_13304 = { 0.0f, 0.0f, 0.0f };
Vec lbl_2_data_13310 = { 0.0f, 0.0f, 0.0f };
DrawCallback08E8 lbl_2_data_1331C = { 2, fn_2_481B8 };
u32 lbl_2_data_13324[20] = {
    0x00000000, 0x00000004, 0x00000014, 0x00013880, 0x00007530, 0x000130B0, 0x0000003C, 0x0000000A, 0x0001A9C8, 0x00018A88,
    0x00000000, 0x0000003C, 0x00C35000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFF00, 0x00000000, 0x000124F8, 0x00000000,
};
u32* lbl_2_data_13374 = lbl_2_data_13324;

// .bss
static u8 lbl_2_bss_55C0[0x28];
static f32 lbl_2_bss_55BC;
static f32 lbl_2_bss_55B8;

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
    return fn_80035838(&lbl_2_data_1326C, 0x17) != 0;
}

// .text:0x0004E9A8 size:0x114
s32 fn_2_4E9A8(void) {
    switch (lbl_2_bss_1A8248->_441C) {
    case 0:
        if (fn_80035838(&lbl_2_data_1327C, 0x18) == 0) {
            return 0;
        }
        break;
    case 1:
        if (fn_80035838(&lbl_2_data_1328C, 0x18) == 0) {
            return 0;
        }
        break;
    case 2:
        if (fn_80035838(&lbl_2_data_1329C, 0x18) == 0) {
            return 0;
        }
        break;
    case 3:
        if (fn_80035838(&lbl_2_data_132AC, 0x18) == 0) {
            return 0;
        }
        break;
    case 4:
        if (fn_80035838(&lbl_2_data_132BC, 0x18) == 0) {
            return 0;
        }
        break;
    case 5:
        if (fn_80035838(&lbl_2_data_132CC, 0x18) == 0) {
            return 0;
        }
        break;
    }
    return 1;
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

// .text:0x0004DEE8 size:0x2D8
void fn_2_4DEE8(void) {
    lbl_2_bss_1A824C->_197843 = -1;
    lbl_2_bss_1A8248->_441E = 1;
    lbl_2_bss_1A8248->_441F = 0x13;
    lbl_2_bss_1A8248->_444A = 0;
    fn_2_45FDC();
    fn_2_45E48();
}

// .text:0x0004DC24 size:0x2C4
void fn_2_4DC24(void) {
    lbl_2_bss_1A824C->_197843 = -1;
    lbl_2_bss_1A8248->_441E = 1;
    fn_2_45FDC();
    fn_2_45E48();
}

// .text:0x0004D960 size:0x2C4
void fn_2_4D960(void) {
    lbl_2_bss_1A824C->_197843 = -1;
    lbl_2_bss_1A8248->_441E = 1;
    fn_2_45FDC();
    fn_2_45E48();
}

// .text:0x0004D67C size:0x2E4
void fn_2_4D67C(void) {
    s32 team;

    lbl_2_bss_1A824C->_197843 = -1;
    team = fn_2_68690(0);
    lbl_2_bss_1A8248->_441E = team;
    lbl_2_bss_1A8248->_4420 = team - 2;
    fn_2_45FDC();
    fn_2_45E48();
}

// .text:0x0004D194 size:0x1E4
// The target loads lbl_2_bss_1A8248 with addi/lwz 0 into r3 at entry; this
// build loads it with lwz sym@l into r5.
void fn_2_4D194(void) {
    GameInitVariables* settings = &g_d_GameSettings;
    s32 flag;
    MenuTracker08E8* tracker = lbl_2_bss_1A8248;

    settings->exhibitionMatchInd = 0;
    settings->bJMatchInd = 0;
    settings->miniGameStadiumIndicator = 0;
    settings->challengeDifficulty = tracker->_4415;
    flag = tracker->_44EF;
    if (flag == 1) {
        settings->home_AwaySetting = 0;
        settings->StadiumID = 1;
    } else {
        settings->StadiumID = lbl_2_data_3CC0[tracker->_441E];
        settings->home_AwaySetting = 0;
    }
    settings->bJMatchRelated = lbl_2_bss_1A8248->_4418;
    fn_2_4C6A8();
}

// .text:0x0004CEE0 size:0x2B4
void fn_2_4CEE0(void) {
    GameInitVariables* settings = &g_d_GameSettings;
    u8 stadium;

    settings->exhibitionMatchInd = 0;
    settings->bJMatchInd = 1;
    g_d_GameSettings.home_AwaySetting = rand() % 2;
    g_d_GameSettings.bJMatchRelated = lbl_2_bss_1A8248->_4418;
    g_d_GameSettings.challengeDifficulty = lbl_2_bss_1A8248->_4415;
    fn_2_4C6A8();
    stadium = lbl_2_bss_1A8248->_40EE[lbl_2_bss_1A8248->_16C2]._2;
    if (stadium >= 6) {
        if (lbl_2_bss_1A8248->_16C0 == 3) {
            if (stadium == 0) {
                settings->StadiumID = 0;
                settings->miniGameStadiumIndicator = 0;
            } else if (stadium == 1) {
                settings->StadiumID = 1;
                settings->miniGameStadiumIndicator = 0;
            } else {
                settings->StadiumID = 4;
                settings->miniGameStadiumIndicator = 0;
            }
        } else if (stadium == 2) {
            settings->StadiumID = 2;
            settings->miniGameStadiumIndicator = 0;
        } else if (stadium == 3) {
            settings->StadiumID = 3;
            settings->miniGameStadiumIndicator = 0;
        } else {
            settings->StadiumID = 5;
            settings->miniGameStadiumIndicator = 0;
        }
    } else {
        settings->miniGameStadiumIndicator = 0;
        settings->StadiumID = lbl_2_data_3CC0[stadium];
    }
}

// .text:0x0004CD30 size:0x1B0
void fn_2_4CD30(void) {
    g_d_GameSettings.GameModeSelected = 7;
    g_d_GameSettings.exhibitionMatchInd = 0;
    g_d_GameSettings._33 = 6;
    g_d_GameSettings._35 = 0;
    g_d_GameSettings._36 = lbl_2_bss_1A8248->_441D;
    g_d_GameSettings.challengeDifficulty = lbl_2_bss_1A8248->_4415;
    g_d_GameSettings.bJMatchInd = 1;
    g_d_GameSettings.bJMatchRelated = lbl_2_bss_1A8248->_4418;
    fn_2_4C6A8();
}

// .text:0x0004CB94 size:0x19C
void fn_2_4CB94(void) {
    g_d_GameSettings.GameModeSelected = 6;
    g_d_GameSettings.exhibitionMatchInd = 0;
    g_d_GameSettings._36 = lbl_2_bss_1A8248->_441D;
    g_d_GameSettings.bJMatchInd = 1;
    g_d_GameSettings.bJMatchRelated = lbl_2_bss_1A8248->_4418;
    fn_2_4C6A8();
}

// .text:0x0004C9C4 size:0x1D0
// Scheduling only: the target forms lbl_2_bss_1A8248's address first (addi/lwz 0)
// and stores GameModeSelected after the lbl_2_data_2E64 lis.
void fn_2_4C9C4(void) {
    g_d_GameSettings.GameModeSelected = 7;
    g_d_GameSettings.exhibitionMatchInd = 0;
    g_d_GameSettings._35 = 0;
    g_d_GameSettings._33 = lbl_2_data_2E64[lbl_2_bss_1A8248->_4420];
    g_d_GameSettings._36 = lbl_2_bss_1A8248->_441D;
    g_d_GameSettings.challengeDifficulty = lbl_2_bss_1A8248->_4415;
    g_d_GameSettings.bJMatchRelated = lbl_2_bss_1A8248->_4418;
    g_d_GameSettings._3A = lbl_2_bss_1A824C->_1978F1;
    fn_2_4C6A8();
}

// .text:0x0004C81C size:0x1A8
void fn_2_4C81C(void) {
    g_d_GameSettings.GameModeSelected = 6;
    g_d_GameSettings.exhibitionMatchInd = 0;
    g_d_GameSettings._36 = lbl_2_bss_1A8248->_441D;
    g_d_GameSettings.bJMatchInd = 0;
    g_d_GameSettings.home_AwaySetting = 0;
    g_d_GameSettings.challengeDifficulty = lbl_2_bss_1A8248->_4415;
    g_d_GameSettings.bJMatchRelated = lbl_2_bss_1A8248->_4418;
    fn_2_4C6A8();
}

// .text:0x0004C6A8 size:0x174
void fn_2_4C6A8(void) {
    s32 i;
    GameInitVariables* settings = &g_d_GameSettings;

    for (i = 0; i < 20; i++) {
        settings->challengeCaptainStarBought[i] = 0;
    }
    for (i = 0; i < 20; i++) {
        if (lbl_2_data_373C[i] == 0 && lbl_2_bss_1A8248->_43C2[i] != 0) {
            settings->challengeCaptainStarBought[i] = 1;
        }
    }
    if (lbl_2_bss_1A8248->_444B != -1) {
        settings->challengeCaptainStarBought[lbl_2_bss_1A8248->_444B] = 1;
    }
}

// .text:0x0004C3EC size:0x2BC
void fn_2_4C3EC(void) {
    s32 i;
    s32 j;
    s32 teams[6];
    u8* seen = lbl_80361C18;

    for (i = 0; i < 6; i++) {
        teams[i] = 0;
    }
    for (i = 0; i < 0x36; i++) {
        seen[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        if (teams[i] != 0) {
            for (j = 0; j < 9; j++) {
                seen[lbl_8034E9A0._4380[i][j]] = 1;
            }
        }
    }
    for (i = 0; i < 0x36; i++) {
        if (fn_2_44F34(i) && ((MenuCharacter08E8*)lbl_2_bss_1A8248)[i]._31 == 1) {
            seen[i] = 1;
        }
    }
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

// .text:0x0004B1AC size:0x124
void fn_2_4B1AC(void) {
    s32 delta;

    fn_2_4B2D0();
    if (lbl_2_bss_1A824C->_197843 == 0) {
        lbl_2_bss_1A824C->_197778 = 0;
        lbl_2_bss_1A824C->_197798 = 0;
    } else if (lbl_2_bss_1A824C->_197843 == 1) {
        if (lbl_2_bss_1A8248->_43BC == 1) {
            delta = -1;
        } else {
            delta = -lbl_2_bss_1A8248->_43BC / 2;
        }
        fn_2_46D34(delta);
        lbl_2_bss_1A824C->_19777A = delta;
        lbl_2_bss_1A824C->_197798 = delta;
    } else if (lbl_2_bss_1A824C->_197843 == 2) {
        lbl_2_bss_1A824C->_197796 = 0;
        lbl_2_bss_1A824C->_197798 = 0;
    }
    starMissionRelated2();
}

// .text:0x0004AEE4 size:0x2C8
void fn_2_4AEE4(void) {
    GameInitVariables* settings = &g_d_GameSettings;
    s32 total;

    fn_2_4B2D0();
    if (lbl_2_bss_1A824C->_197843 == 0) {
        lbl_2_bss_1A824C->_19777C = lbl_2_data_3840[lbl_2_bss_1A8248->_4420][settings->_3A];
        lbl_2_bss_1A824C->_19777E = settings->_20[settings->_35][0] * lbl_2_data_3804[lbl_2_bss_1A8248->_4420][settings->_3A];
        total = lbl_2_bss_1A824C->_19777C + lbl_2_bss_1A824C->_19777E;
        fn_2_46D34(total);
        lbl_2_bss_1A824C->_197780 = total;
        lbl_2_bss_1A824C->_197798 = total;
    } else if (lbl_2_bss_1A824C->_197843 == 1) {
        total = lbl_2_data_387C[lbl_2_bss_1A8248->_4420][settings->_3A];
        fn_2_46D34(total);
        lbl_2_bss_1A824C->_197782 = total;
        lbl_2_bss_1A824C->_197798 = total;
    } else if (lbl_2_bss_1A824C->_197843 == 2) {
        lbl_2_bss_1A824C->_197796 = 0;
        lbl_2_bss_1A824C->_197798 = 0;
    }
    if (lbl_2_bss_1A8248->_44F8[lbl_2_bss_1A8248->_4420] > 0) {
        lbl_2_bss_1A8248->_44F8[lbl_2_bss_1A8248->_4420]--;
    }
    if (lbl_2_bss_1A824C->_197843 == 0 && !(lbl_2_bss_1A8248->_4428 & (1 << lbl_2_bss_1A8248->_4420))) {
        lbl_2_bss_1A8248->_4423++;
        lbl_2_bss_1A8248->_4428 |= 1 << lbl_2_bss_1A8248->_4420;
    }
}

// .text:0x0004ACF8 size:0x1EC
void fn_2_4ACF8(void) {
    GameInitVariables* settings = &g_d_GameSettings;

    fn_2_4B2D0();
    if (lbl_2_bss_1A824C->_197843 == 0) {
        fn_2_46D34(settings->challengeMinigame_baseCoinsEarned);
        lbl_2_bss_1A824C->_197792 = settings->challengeMinigame_baseCoinsEarned;
        lbl_2_bss_1A824C->_197798 = settings->challengeMinigame_baseCoinsEarned;
    } else if (lbl_2_bss_1A824C->_197843 == 1) {
        fn_2_46D34(lbl_2_data_38B8);
        lbl_2_bss_1A824C->_197794 = lbl_2_data_38B8;
        lbl_2_bss_1A824C->_197798 = lbl_2_data_38B8;
    } else if (lbl_2_bss_1A824C->_197843 == 2) {
        lbl_2_bss_1A824C->_197796 = 0;
        lbl_2_bss_1A824C->_197798 = 0;
    }
    if (lbl_2_bss_1A8248->_44FD > 0) {
        lbl_2_bss_1A8248->_44FD--;
    }
    if (lbl_2_bss_1A824C->_197843 == 0 && lbl_2_bss_1A8248->_4429 == 0) {
        lbl_2_bss_1A8248->_4429 = 1;
    }
}

// .text:0x0004AB1C size:0x1DC
// The target keeps the dead loads and clamps of stars and coins after
// fn_2_4B2D0; this build drops them. Everything else matches.
void fn_2_4AB1C(void) {
    s32 stars;
    s32 coins;

    fn_2_4B2D0();
    stars = lbl_80353A90._08;
    coins = lbl_80353A90._2E;
    if (stars < 0) {
        stars = 0;
    }
    if (stars > 99) {
        stars = 99;
    }
    if (coins > 99) {
        coins = 99;
    }
    if (lbl_2_bss_1A824C->_197843 == 0) {
        lbl_2_bss_1A824C->_19776E = 0;
        lbl_2_bss_1A824C->_197772 = 0;
        lbl_2_bss_1A824C->_197776 = 0;
        lbl_2_bss_1A824C->_197798 = lbl_2_bss_1A824C->_19776E + lbl_2_bss_1A824C->_197772 + lbl_2_bss_1A824C->_197776;
    } else if (lbl_2_bss_1A824C->_197843 == 1) {
        lbl_2_bss_1A824C->_197770 = 0;
        lbl_2_bss_1A824C->_197774 = 0;
        lbl_2_bss_1A824C->_197798 = lbl_2_bss_1A824C->_197770 + lbl_2_bss_1A824C->_197774;
    } else if (lbl_2_bss_1A824C->_197843 == 2) {
        lbl_2_bss_1A824C->_197796 = 0;
        lbl_2_bss_1A824C->_197798 = 0;
    }
    if (lbl_2_bss_1A8248->_441C != 5 || lbl_2_bss_1A8248->_44EF != 1) {
        if (!(lbl_2_bss_1A8248->_4427 & (1 << lbl_2_bss_1A8248->_441E))) {
            lbl_2_bss_1A8248->_4427 |= 1 << lbl_2_bss_1A8248->_441E;
        }
    }
    if (lbl_2_bss_1A824C->_197843 == 0) {
        if (lbl_2_bss_1A8248->_441C == 5 && lbl_2_bss_1A8248->_44EF == 1) {
            lbl_2_bss_1A8248->_4422++;
        } else if (!(lbl_2_bss_1A8248->_4426 & (1 << lbl_2_bss_1A8248->_441E))) {
            lbl_2_bss_1A8248->_4422++;
            lbl_2_bss_1A8248->_4426 |= 1 << lbl_2_bss_1A8248->_441E;
        }
    }
    starMissionRelated2();
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

// .text:0x0004A0C4 size:0x8C
s32 fn_2_4A0C4(u16* a, u16* b) {
    while (1) {
        if ((*a & 0xC000) == 0xC000) {
            return -1;
        }
        if ((*b & 0xC000) == 0xC000) {
            return 1;
        }
        if (*a == 0x4000 && *b == 0x4000) {
            break;
        }
        if (*a == 0x4000) {
            return -1;
        }
        if (*b == 0x4000) {
            return 1;
        }
        if (*a - *b != 0) {
            return *a - *b;
        }
        a++;
        b++;
    }
    return 0;
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

// .text:0x00049F7C size:0xE8
// Matches except for one unreachable trailing blr the base emits after the
// out-of-line loop preheader.
s32 fn_2_49F7C(u16* str, s32 max, u16 c, s32 pos) {
    s32 len = fn_2_4A068(str);

    if (len < pos || c == 0x4000 || len + 2 > max) {
        return 0;
    } else {
        while (len >= pos) {
            str[len + 1] = str[len];
            len--;
        }
        str[pos] = c;
        return (s32)str;
    }
}

// .text:0x00049EFC size:0x80
s32 fn_2_49EFC(u16* str, u16 font) {
    s32 width = 0;

    while (*str != 0x4000) {
        if (*str == 0x4003) {
            width += lbl_2_data_13238[font];
        } else if (*str == 0x4002) {
            width += lbl_2_data_13238[font] / 2;
        } else if (!(*str & 0x4000)) {
            if (*str & 0x8000) {
                width += lbl_2_data_13238[font];
            } else {
                width += lbl_2_data_13238[font] / 2;
            }
        }
        str++;
    }
    return width;
}

// .text:0x00049E5C size:0xA0
void fn_2_49E5C(s32 arg0, s32 arg1, s32 value, s32 flags, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    void* text = _OSAllocFromHeap(0x10, 0x40);

    fn_2_4917C(text, value, flags, arg4, arg5);
    fn_2_513E0(text, arg0, arg1, 0, arg5, arg6, arg7, arg8);
    if (text != NULL) {
        fn_800ACFB0(text);
    }
}

// .text:0x00049DB8 size:0xA4
void fn_2_49DB8(s32 arg0, s32 arg1, s32 value, s32 flags, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    void* text = _OSAllocFromHeap(0x10, 0x40);

    fn_2_4917C(text, value, flags, arg5, arg6);
    fn_2_513E0(text, arg0, arg1, arg4, arg6, arg7, arg8, arg9);
    if (text != NULL) {
        fn_800ACFB0(text);
    }
}

// .text:0x0004906C size:0x110
// The target reads the source as add+lwz 4(rX); this form builds i*4+4 for
// lwzx and needs three saved registers.
void fn_2_4906C(void) {
    s32 i;

    for (i = 0; i < 15; i++) {
        lbl_2_bss_1A824C->_19542C[i] = lbl_80366B18._798[lbl_2_bss_1A824C->_1972B8]->_04[i];
    }
}

// .text:0x00048DB4 size:0x2B8
void fn_2_48DB4(void) {
    GXColor color0 = { 0xFF, 0xFF, 0xFF, 0xFF };
    GXColor color1 = { 0xFF, 0xFF, 0xFF, 0xFF };
    GXColor color2 = { 0xFF, 0xFF, 0xFF, 0xFF };

    LITAlloc(&lbl_8036E548._00AC[0]);
    LITAlloc(&lbl_8036E548._00AC[1]);
    LITAlloc(&lbl_8036E548._00AC[2]);
    LITAlloc(&lbl_8036E548._00AC[3]);
    LITInitAttn(lbl_8036E548._00AC[0], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._00AC[0], 5.0f, -40.0f, -35.0f);
    LITInitDir(lbl_8036E548._00AC[0], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_8036E548._00AC[0], color2);
    LITInitDir(lbl_8036E548._00AC[0], -5.0f, -40.0f, -35.0f);
    LITInitAttn(lbl_8036E548._00AC[1], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._00AC[1], -5.0f, -45.0f, -30.0f);
    LITInitDir(lbl_8036E548._00AC[1], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_8036E548._00AC[1], color1);
    LITInitAttn(lbl_8036E548._00AC[2], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._00AC[2], 0.0f, -40.0f, -35.0f);
    LITInitDir(lbl_8036E548._00AC[2], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_8036E548._00AC[2], color0);
    LITInitAttn(lbl_8036E548._00AC[3], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._00AC[3], 0.0f, -40.0f, -35.0f);
    LITInitDir(lbl_8036E548._00AC[3], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_8036E548._00AC[3], color0);
}

// .text:0x00048D54 size:0x60
void fn_2_48D54(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        LITXForm(lbl_8036E548._00AC[i], fn_80052768_getCamera(0)->view);
    }
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

// .text:0x00048BE0 size:0x128
void fn_2_48BE0(void) {
    Vec pos;
    Vec delta;
    MenuPlayer08E8* player = &lbl_8036E548._0C04[lbl_2_bss_1A824C->_19769C];

    memcpy(&pos, &player->_034, sizeof(Vec));
    PSVECSubtract(&pos, (Vec*)lbl_2_data_132F8, &delta);
    delta.x *= -1.0f;
    delta.z *= -1.0f;
    if (0.0f != delta.x || 0.0f != delta.z) {
        lbl_2_bss_55B8 = fn_2_4A1E8(delta.z, delta.x);
    }
    memcpy(lbl_2_data_132F8, &player->_034, sizeof(Vec));
    player->_034 = pos.x;
    player->_038 = pos.y;
    player->_03C = pos.z;
    player->_040 = lbl_2_data_132EC.x;
    player->_044 = lbl_2_bss_55B8;
    player->_048 = lbl_2_data_132EC.z;
}

// .text:0x00048A1C size:0x1C4
void fn_2_48A1C(void) {
    Vec pos;
    Vec delta;
    MenuPlayer08E8* player = &lbl_8036E548._0C04[lbl_2_bss_1A824C->_19769C];

    memcpy(&pos, &player->_034, sizeof(Vec));
    PSVECSubtract(&pos, &lbl_2_data_13310, &delta);
    delta.x *= -1.0f;
    delta.z *= -1.0f;
    pos.x += lbl_803C77B8[lbl_2_bss_1A824C->_197863]._10 / 768.0f;
    pos.z += lbl_803C77B8[lbl_2_bss_1A824C->_197863]._11 / 768.0f;
    if (0.0f != delta.x || 0.0f != delta.z) {
        lbl_2_bss_55BC = fn_2_4A1E8(delta.z, delta.x);
    }
    memcpy(&lbl_2_data_13310, &player->_034, sizeof(Vec));
    player->_034 = pos.x;
    player->_038 = pos.y;
    player->_03C = pos.z;
    player->_040 = lbl_2_data_13304.x;
    player->_044 = lbl_2_bss_55BC;
    player->_048 = lbl_2_data_13304.z;
}

// .text:0x000489DC size:0x40
void fn_2_489DC(void) {
    fn_800A7D4C(0xC, &lbl_2_data_13228[lbl_803CBBC0]);
}

// .text:0x000487A0 size:0x23C
void fn_2_487A0(void) {
    s32 i;
    f32 f;

    GXLoadPosMtxImm(fn_80052768_getCamera(0)->view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetColorUpdate(GX_TRUE);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetNumTevStages(1);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetChanCtrl(GX_COLOR0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_ALPHA0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
    for (i = -24; i < 25; i++) {
        f = i;
        GXBegin(GX_LINES, GX_VTXFMT0, 4);
        GXPosition3f32(-24.0f, 0.0f, f);
        GXColor4u8(0, 0xFF, 0, 0xC8);
        GXPosition3f32(24.0f, 0.0f, f);
        GXColor4u8(0, 0xFF, 0, 0xC8);
        GXPosition3f32(f, 0.0f, -24.0f);
        GXColor4u8(0, 0xFF, 0, 0xC8);
        GXPosition3f32(f, 0.0f, 24.0f);
        GXColor4u8(0, 0xFF, 0, 0xC8);
        GXEnd();
    }
}

// .text:0x000481B8 size:0x3C
void fn_2_481B8(void) {
    camera_803c639c_s* camera = fn_80052768_getCamera(0);
    fn_800BD670(lbl_8036E548._0060, camera->view);
}

// .text:0x00047FF8 size:0x1C0
void fn_2_47FF8(void) {
    Mtx44 proj;

    C_MTXFrustum(proj, -0.175f, 0.175f, 0.25f, -0.25f, 1.0f, 512.0f);
    GXSetProjection(proj, GX_PERSPECTIVE);
    fn_2_48D54();
    if (lbl_2_bss_1A824C->_19784A != 0) {
        if (lbl_2_bss_1A824C->_197846 == 1) {
            if (lbl_2_bss_1A824C->_197847 == 0) {
                fn_2_6A87C();
            } else {
                fn_2_6A87C();
                fn_2_93BF8(&lbl_2_bss_1A81D4);
            }
        } else if (lbl_2_bss_1A824C->_197846 == 2) {
            fn_2_9007C();
        } else {
            fn_2_93BF8(&lbl_2_bss_1A81D4);
        }
    } else {
        fn_2_93BF8(&lbl_2_bss_1A81D4);
    }
    memcpy(&fn_80052768_getCamera(0)->eye, &lbl_2_bss_1A81D4._4C, sizeof(Vec));
    memcpy(&fn_80052768_getCamera(0)->target, &lbl_2_bss_1A81D4._40, sizeof(Vec));
    fn_80052768_getCamera(0)->zoom = lbl_2_bss_1A81D4._3C;
    PSMTXCopy(lbl_2_bss_1A81D4._00, fn_80052768_getCamera(0)->view);
    fn_80052968();
}

// .text:0x00047B24 size:0x1D8
void fn_2_47B24(MenuModelList08E8* list) {
    Mtx m;
    MtxPtr view;
    MenuActor08E8* actor;
    u16 i;
    u16 j;
    MenuActorRef08E8* ref;
    MenuFielder08E8* fielder;

    if (lbl_2_bss_340140->_307A == 3) {
        return;
    }
    for (i = 0; i < list->_00; i++) {
        fielder = lbl_8036E548._2C50[i];
        if (fielder == NULL || fielder->_25D == 0) {
            continue;
        }
        ref = fn_800111D8(fielder);
        if (ref->_00 == NULL) {
            continue;
        }
        if (ref->_58 != 0) {
            ACTSetAnimation(ref->_00, ref->_04, NULL, ref->_0E, 0.0f, ref->_60);
        }
        if (ref->_59 != 0) {
            fn_800B4CA0(ref->_00, ref->_5C);
        }
        if (ref->_5A != 0) {
            fn_800B4C04(ref->_00, ref->_54);
        }
        if (ref->_5B & 2) {
            fn_800B4AFC(ref->_00, ref->_5B & 1);
        }
        Set_FUN_800b2b6c(ref->_00, ref->_68);
        if (ref->_6C != 0) {
            fn_800BDA24(ref);
        }
        for (j = 0; j < fn_800527BC(); j++) {
            view = fn_80052734(j)->view;
            PSMTXTrans(m, fielder->_034, fielder->_038, fielder->_03C);
            PSMTXConcat(view, m, m);
            actor = ref->_00;
            actor->_98 = (actor->_98 & (u8)~(3 << (j * 3))) | (fn_800B3C04(j, actor, m) << (j * 3));
        }
        ref->_58 = 0;
        ref->_59 = 0;
        ref->_5A = 0;
        ref->_5B &= 1;
    }
}

// .text:0x00047AFC size:0x28
void fn_2_47AFC(void) {
    s32 i;
    for (i = 0; i < 13; i++) {
    }
}

// .text:0x000478F4 size:0x208
void fn_2_478F4(void) {
    s32 i;

    fn_2_477C0();
    fn_2_47540();
    fn_80023B04(0xD);
    fn_80014204(4);
    lbl_8036E548._013C = fn_80023AA4();
    for (i = 0; i < 4; i++) {
        lbl_8036E548._0C04[i]._255 = i;
        lbl_8036E548._2C50[i] = NULL;
        lbl_8036E548._2D6A[i] = -1;
        lbl_8036E548._0C04[i]._257 = -1;
    }
    for (i = 0; i < 9; i++) {
        lbl_8036E548._2D7F[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        lbl_8036E548._2D89[i] = -1;
    }
    lbl_8036E548._2D77 = 0;
    lbl_8036E548._2D7B = 0;
    lbl_8036E548._2D7C = 0;
}

// .text:0x000477C0 size:0x134
void fn_2_477C0(void) {
    u32 max = 0;
    u32 size;
    s32 idx;
    s32 i;
    u8* buf;
    u8* ptr;

    for (i = 0; i < 54; i++) {
        idx = i * 19;
        size = lbl_2_data_12EC0[idx]._0[1] & 0x0FFFFFFF;
        if (max < size) {
            max = size;
        }
    }
    max = (max + 0x1F) & ~0x1F;
    buf = _OSAllocFromHeap(0x20, max * 4);
    lbl_8036E548._2C8C = buf;
    ptr = buf;
    for (i = 0; i < 4; i++) {
        lbl_8036E548._0C04[i]._008 = ptr;
        ptr += max;
    }
}

// .text:0x0004777C size:0x44
void fn_2_4777C(void) {
    if (lbl_8036E548._2C8C != NULL) {
        fn_800ACFB0(lbl_8036E548._2C8C);
        lbl_8036E548._2C8C = NULL;
    }
}

// .text:0x00047540 size:0x23C
// Registers only: the four maxima land in other volatile registers.
void fn_2_47540(void) {
    u32 max3 = 0;
    u32 max2 = 0;
    u32 max0 = 0;
    u32 max1 = 0;
    s32 i;
    u32 size;
    u8* buf;

    for (i = 0; i < 4; i++) {
        size = lbl_2_data_12EC0[i * 19 + 4]._0[1] & 0x0FFFFFFF;
        if (max2 < size) {
            max2 = size;
        }
        size = lbl_2_data_12EC0[i * 19 + 3]._0[1] & 0x0FFFFFFF;
        if (max1 < size) {
            max1 = size;
        }
        size = lbl_2_data_12EC0[i * 19 + 5]._0[1] & 0x0FFFFFFF;
        if (max3 < size) {
            max3 = size;
        }
        size = lbl_2_data_12EC0[i * 19 + 2]._0[1] & 0x0FFFFFFF;
        if (max0 < size) {
            max0 = size;
        }
    }
    lbl_8036E548._2C94 = max1 = (max1 + 0x1F) & ~0x1F;
    lbl_8036E548._2C9C = max3 = (max3 + 0x1F) & ~0x1F;
    lbl_8036E548._2C90 = max0 = (max0 + 0x1F) & ~0x1F;
    lbl_8036E548._2C98 = max2 = (max2 + 0x1F) & ~0x1F;
    buf = _OSAllocFromHeap(0x20, (max2 + (max1 + max3 + max0)) * 4);
    lbl_8036E548._2C88 = buf;
    for (i = 0; i < 4; i++) {
        lbl_8036E548._2CEC[i]._00[0] = buf;
        buf += max2;
        lbl_8036E548._2CEC[i]._00[1] = buf;
        buf += max1;
        lbl_8036E548._2CEC[i]._00[2] = buf;
        buf += max3;
        lbl_8036E548._2CEC[i]._00[3] = buf;
        buf += max0;
        lbl_8036E548._0C04[i]._010 = 0;
        lbl_8036E548._0C04[i]._01C = 0;
        lbl_8036E548._0C04[i]._020 = 0;
        lbl_8036E548._0C04[i]._014 = 0;
        lbl_8036E548._0C04[i]._018 = 0;
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

// .text:0x000472C4 size:0x234
// Registers only: the target keeps cols in r8 and last in r0 from the
// first divide on.
void fn_2_472C4(s16* cursor, s16* page, s16 count, s16 cols, s16 flags) {
    s16 last;
    s16 rem;
    s16 step;
    s16 pos;

    if (count == 0) {
        return;
    }
    if ((cols == 0) | (count < cols)) {
        cols = count;
    }
    rem = cols;
    if (count % cols != 0) {
        rem = count % cols;
    }
    last = count - cols;
    if (flags & 4) {
        last = count - rem;
    }
    switch (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04) {
    case 0x20:
    case 0x4:
        if (!(flags & 8) && page != NULL && count > cols) {
            pos = *page;
            step = cols - pos % cols;
            if (pos == last) {
                if (flags & 2) {
                    *page = 0;
                } else {
                    *page = last;
                    return;
                }
            } else {
                pos += step;
                *page = pos;
                if (pos > last) {
                    *page = last;
                }
            }
            *cursor = 0;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        }
        break;
    case 0x40:
    case 0x8:
        if (!(flags & 8) && page != NULL && count > cols) {
            step = *page % cols;
            if (step == 0) {
                step = cols;
            }
            if (*page <= 0) {
                if (flags & 2) {
                    *page = last;
                    *cursor = 0;
                    sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
                }
            } else {
                *page -= step;
                *cursor = 0;
                sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            }
        }
        break;
    }
}

// .text:0x00046D34 size:0x60
void fn_2_46D34(s32 delta) {
    lbl_2_bss_1A8248->_43BE = lbl_2_bss_1A8248->_43BC;
    lbl_2_bss_1A8248->_43BC += delta;
    if (lbl_2_bss_1A8248->_43BC > 999) {
        lbl_2_bss_1A8248->_43BC = 999;
    }
    if (lbl_2_bss_1A8248->_43BC < 0) {
        lbl_2_bss_1A8248->_43BC = 0;
    }
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

// .text:0x00046ADC size:0x148
void fn_2_46ADC(void) {
    s32 i;
    s32 j;
    s32 team;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
        c->_00 = &lbl_801094E4[i];
        c->_04 = c->_00->_00;
        c->_05 = c->_00->_01;
        c->_07 = 0;
        c->_06 = 0;
        c->_08[0] = 0;
        for (j = 0; j < 10; j++) {
            c->_09[j]._0 = c->_1D[j]._0 = 0;
            c->_09[j]._1 = c->_1D[j]._1 = 0;
        }
        team = c->_04;
        if (team == lbl_2_bss_1A8248->_441C && c->_05 <= 3) {
            c->_31 = 1;
        } else {
            c->_31 = 0;
        }
    }
}

// .text:0x000468DC size:0x200
void fn_2_468DC(void) {
    s32 i;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
        c->_00 = &lbl_801094E4[i];
        c->_04 = c->_00->_00;
        c->_05 = c->_00->_01;
    }
}

// .text:0x000467FC size:0xE0
void fn_2_467FC(void) {
    s32 i;

    for (i = 0; i < 0x36; i++) {
        s32 team = ((MenuCharacter08E8*)lbl_2_bss_1A8248)[i]._04;
        if (team == lbl_2_bss_1A8248->_441C && ((MenuCharacter08E8*)lbl_2_bss_1A8248)[i]._05 <= 3) {
            ((MenuCharacter08E8*)lbl_2_bss_1A8248)[i]._31 = 1;
        } else {
            ((MenuCharacter08E8*)lbl_2_bss_1A8248)[i]._31 = 0;
        }
    }
}

// .text:0x000466AC size:0x150
void fn_2_466AC(void) {
    s32 i;
    s32 j;
    s32 goal;
    s32 kind;
    s32 need;
    s32 level;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
        for (j = 0; j < 10; j++) {
            goal = lbl_80109AE8[lbl_800E8558[i]._2][j]._0;
            kind = lbl_8010A768[lbl_800E8558[i]._2][j]._2;
            need = lbl_8010A768[lbl_800E8558[i]._2][j]._4;
            level = lbl_8010A768[lbl_800E8558[i]._2][j]._6;
            if (kind == 0) {
                c->_09[j]._1 = 1;
            }
            if (kind == 1) {
                if (fn_8006CDC0(i) >= need && lbl_2_bss_1A8248->_4415 >= level) {
                    c->_09[j]._1 = 1;
                } else {
                    c->_09[j]._1 = 0;
                }
            }
            if (kind == 19 && lbl_2_bss_1A8248->_441C == need && lbl_2_bss_1A8248->_4415 >= level) {
                c->_09[j]._1 = 1;
            }
            if (goal != -1 && c->_09[j]._0 < 0) {
                c->_09[j]._1 = 1;
            }
        }
    }
}

// .text:0x0004668C size:0x20
void fn_2_4668C(s32 id) {
    ((MenuCharacter08E8*)lbl_2_bss_1A8248)[id]._31 = 1;
}

// .text:0x00046418 size:0x274
void fn_2_46418(void) {
    s32 i;

    memcpy(lbl_2_bss_1A8248, lbl_2_bss_1A8248->_0AF8, sizeof(lbl_2_bss_1A8248->_0AF8));
    for (i = 0; i < 0x36; i++) {
        ((MenuCharacter08E8*)lbl_2_bss_1A8248)[i]._07 = 0;
        ((MenuCharacter08E8*)lbl_2_bss_1A8248)[i]._06 = 0;
        ((MenuCharacter08E8*)lbl_2_bss_1A8248)[i]._08[0] = 0;
        ((MenuCharacter08E8*)lbl_2_bss_1A8248)[i]._31 = 0;
    }
    lbl_2_bss_1A8248->_442A = lbl_2_bss_1A8248->_15F0;
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

// .text:0x00045FDC size:0x110
void fn_2_45FDC(void) {
    s32 i;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
        c->_07 = c->_06;
    }
}

// .text:0x00045E48 size:0x194
void fn_2_45E48(void) {
    s32 j;
    s32 i;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
        for (j = 0; j < 10; j++) {
            c->_1D[j]._0 = c->_09[j]._0;
            c->_1D[j]._1 = c->_09[j]._1;
        }
    }
}

// .text:0x00045D38 size:0x110
void fn_2_45D38(void) {
    s32 i;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
        c->_06 = c->_07;
    }
}

// .text:0x00045BA4 size:0x194
void fn_2_45BA4(void) {
    s32 j;
    s32 i;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
        for (j = 0; j < 10; j++) {
            c->_09[j]._0 = c->_1D[j]._0;
            c->_09[j]._1 = c->_1D[j]._1;
        }
    }
}

// .text:0x00045A84 size:0x120
s32 fn_2_45A84(void) {
    s32 i;
    s32 j;
    s32 found = 0;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
        for (j = 0; j < 10; j++) {
            if (c->_1D[j]._0 >= 0 && c->_09[j]._0 < 0) {
                found = 1;
                lbl_2_bss_1A8248->_44B9[i] = 1;
            }
        }
    }
    return found == 1;
}

// .text:0x00045978 size:0x10C
void fn_2_45978(void) {
    s32 i;
    s32 j;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
        c->_07 = c->_06;
        for (j = 0; j < 10; j++) {
            c->_1D[j]._0 = c->_09[j]._0;
            c->_1D[j]._1 = c->_09[j]._1;
        }
        lbl_2_bss_1A8248->_444D[i] = 0;
        lbl_2_bss_1A8248->_4483[i] = 0;
        lbl_2_bss_1A8248->_44B9[i] = 0;
    }
}

// .text:0x00045938 size:0x40
s32 fn_2_45938(s32 slot) {
    return ((MenuCharacter08E8*)lbl_2_bss_1A8248)[lbl_803CB8F0[lbl_2_bss_1A8248->_40EE[slot]._5]]._31 == 0;
}

// .text:0x00045810 size:0x128
void fn_2_45810(void) {
    s32 i;

    for (i = 0; i < 0x36; i++) {
        lbl_2_bss_1A8248->_43D6[i] = 0;
    }
}

// .text:0x000454E8 size:0x328
void fn_2_454E8(void) {
    s32 i;
    s32 j;
    s32 done;
    s32 total;
    u8 mission;
    MenuCharEntry08E8* entry;

    fn_2_45810();
    for (i = 0; i < 0x36; i++) {
        done = fn_8006CDC0(i);
        if (lbl_800E8558[i]._3 == 1) {
            mission = lbl_800E8558[i]._2;
            total = 0;
            for (j = 0; j < 10; j++) {
                if (lbl_80109AE8[mission][j]._0 != -1) {
                    total++;
                }
            }
            lbl_800E8558[i]._2 = mission;
        } else {
            total = 0;
        }
        if (done == total && total != 0) {
            lbl_2_bss_1A8248->_43D6[i] = 1;
            for (j = 0; j < 0x36; j++) {
                entry = &lbl_800E8558[j];
                if (entry->_1 == i) {
                    lbl_2_bss_1A8248->_43D6[j] = 1;
                }
            }
        }
    }
}

// .text:0x00045354 size:0x194
void fn_2_45354(void) {
    s32 i;

    lbl_2_bss_1A824C->_197866 = 0;
    for (i = 0; i < 0x36; i++) {
        lbl_2_bss_1A824C->_197868[i] = -1;
    }
    for (i = 0; i < 0x36; i++) {
        if (lbl_2_bss_1A8248->_4483[i] == 1) {
            lbl_2_bss_1A824C->_197868[lbl_2_bss_1A824C->_197866] = i;
            lbl_2_bss_1A824C->_197866++;
        }
    }
}

// .text:0x00045204 size:0x150
// Registers only: i and the lbl_800E8558 walker in swapped saved registers.
// Calling fn_2_44E2C instead inlines it with a separate &entry->_2 pointer.
void fn_2_45204(void) {
    s32 i;
    s32 j;
    s32 done;
    s32 total;
    u8 mission;

    for (i = 0; i < 0x36; i++) {
        done = fn_8006CDC0(i);
        if (lbl_800E8558[i]._3 == 1) {
            mission = lbl_800E8558[i]._2;
            total = 0;
            for (j = 0; j < 10; j++) {
                if (lbl_80109AE8[mission][j]._0 != -1) {
                    total++;
                }
            }
            lbl_800E8558[i]._2 = mission;
        } else {
            total = 0;
        }
        if (done == total && total != 0 && lbl_2_bss_1A8248->_43D6[i] == 0) {
            lbl_2_bss_1A8248->_4483[i] = 1;
        }
    }
}

// .text:0x000450E4 size:0x120
void fn_2_450E4(void) {
    s32 id;
    s32 i;
    s32 j;
    MenuCharEntry08E8* entry;

    for (i = 0; i < lbl_2_bss_1A824C->_197866; i++) {
        id = lbl_2_bss_1A824C->_197868[i];
        lbl_2_bss_1A8248->_43D6[id] = 1;
        for (j = 0; j < 0x36; j++) {
            entry = &lbl_800E8558[j];
            if (entry->_1 == id) {
                lbl_2_bss_1A8248->_43D6[j] = 1;
            }
        }
    }
}

// .text:0x00044F64 size:0x180
void fn_2_44F64(void) {
    s32 i;

    for (i = 0; i < 0x36; i++) {
        lbl_2_bss_1A8244->_00[i] |= lbl_2_bss_1A8248->_43D6[i];
    }
}

// .text:0x00044F34 size:0x30
s32 fn_2_44F34(s32 id) {
    return ((MenuCharacter08E8*)lbl_2_bss_1A8248)[id]._05 <= 3;
}

// .text:0x00044F14 size:0x20
s32 fn_2_44F14(s32 id) {
    return ((MenuCharacter08E8*)lbl_2_bss_1A8248)[id]._05;
}

// .text:0x00044E2C size:0xE8
s32 fn_2_44E2C(s32 id) {
    s32 i;
    s32 count;
    MenuCharEntry08E8* entry = &lbl_800E8558[id];
    u8 mission;
    u8* p;

    if (entry->_3 == 1) {
        p = &entry->_2;
        mission = *p;
        count = 0;
        for (i = 0; i < 10; i++) {
            if (lbl_80109AE8[mission][i]._0 != -1) {
                count++;
            }
        }
        *p = mission;
        return count;
    }
    return 0;
}

// .text:0x00044414 size:0xF0
void fn_2_44414(SortEntry08E8* entries) {
    s32 i;
    s32 j;
    SortEntry08E8 tmp;

    for (i = 1; i < 55; i++) {
        tmp = entries[i];
        entries[0] = tmp;
        j = i - 1;
        while (tmp.key < entries[j].key) {
            entries[j + 1] = entries[j];
            j--;
        }
        entries[j + 1] = tmp;
    }
}

// .text:0x00044368 size:0xAC
s32 fn_2_44368(void) {
    s32 i;
    s32 count = 0;
    s32 id;

    for (i = 0; i < 9; i++) {
        id = lbl_2_bss_1A8248->_40B8[i]._0;
        if (id == 13 || id == 29 || id == 30 || id == 31 || id == 32) {
            count++;
        }
    }
    return count >= 5;
}

// .text:0x000442E8 size:0x80
s32 fn_2_442E8(void) {
    s32 i;
    s32 count = 0;
    s32 id;

    for (i = 0; i < 9; i++) {
        id = lbl_2_bss_1A8248->_40B8[i]._0;
        if (id == 0 || id == 1) {
            count++;
        }
    }
    return count == 2;
}

// .text:0x00044238 size:0xB0
s32 fn_2_44238(s32 id) {
    s32 i;
    s32 count = 0;

    for (i = 0; i < 9; i++) {
        if (lbl_2_bss_1A8248->_40B8[i]._0 == id) {
            count++;
        }
    }
    return count != 0;
}

// .text:0x00044184 size:0xB4
void fn_2_44184(void) {
    s32 i;
    s32 count = 0;

    for (i = 0; i < 9; i++) {
        if (lbl_2_bss_1A8248->_40B8[i]._0 == 12) {
            count++;
        }
    }
    if (count == 0) {
        lbl_2_bss_1A8248->_44F7 = 1;
    }
}

// .text:0x00044014 size:0x170
void fn_2_44014(void) {
    s32 i;
    s32 j;
    s16 goal;
    s16 kind;
    s16 level;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        if (lbl_800E8558[i]._3 == 1) {
            c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
            if (c->_31 == 1) {
                for (j = 0; j < 10; j++) {
                    goal = lbl_80109AE8[lbl_800E8558[i]._2][j]._0;
                    kind = lbl_80109AE8[lbl_800E8558[i]._2][j]._2;
                    level = lbl_80109AE8[lbl_800E8558[i]._2][j]._6;
                    if (goal != -1 && c->_09[j]._0 == 0 && goal == 58 && lbl_2_bss_1A8248->_43C2[kind] == 1 &&
                        lbl_2_bss_1A8248->_4415 >= level) {
                        c->_09[j]._0 = -2;
                    }
                }
            }
        }
    }
}

// .text:0x00043E8C size:0x188
void fn_2_43E8C(void) {
    s32 i;
    s32 j;
    s16 goal;
    s16 level;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        if (lbl_800E8558[i]._3 == 1) {
            c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
            if (c->_31 == 1) {
                for (j = 0; j < 10; j++) {
                    goal = lbl_80109AE8[lbl_800E8558[i]._2][j]._0;
                    level = lbl_80109AE8[lbl_800E8558[i]._2][j]._6;
                    if (goal != -1 && c->_09[j]._0 == 0 && goal == 59 && lbl_2_bss_1A824C->_1978F4 == 1 &&
                        lbl_2_bss_1A8248->_4415 >= level) {
                        c->_09[j]._0 = -2;
                    }
                }
            }
        }
    }
    lbl_2_bss_1A824C->_1978F4 = 0;
}

// .text:0x00043404 size:0x188
void fn_2_43404(void) {
    s32 i;
    s32 j;
    s32 goal;
    s32 team;
    s32 level;
    s32 coins;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        if (lbl_800E8558[i]._3 == 1) {
            c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
            if (c->_31 == 1) {
                for (j = 0; j < 10; j++) {
                    goal = lbl_80109AE8[lbl_800E8558[i]._2][j]._0;
                    team = lbl_80109AE8[lbl_800E8558[i]._2][j]._2;
                    level = lbl_80109AE8[lbl_800E8558[i]._2][j]._6;
                    coins = lbl_80109AE8[lbl_800E8558[i]._2][j]._8;
                    if (goal != -1 && c->_09[j]._0 == 0 && goal == 70 && lbl_2_bss_1A8248->_441C == team &&
                        lbl_2_bss_1A8248->_43BC >= coins * 100 && lbl_2_bss_1A8248->_4415 >= level) {
                        c->_09[j]._0 = -2;
                    }
                }
            }
        }
    }
}

// .text:0x000432EC size:0x118
// Only the lbl_80109AE8 and lbl_8010A768 bases differ: the target forms
// lbl_80109AE8 first, in the lower register (fn_2_466AC, written the same
// way without the two guards, matches).
void fn_2_432EC(void) {
    s32 i;
    s32 j;
    s32 goal;
    s32 kind;
    s32 need;
    s32 level;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        if (lbl_800E8558[i]._3 == 1) {
            c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
            if (c->_31 == 1) {
                for (j = 0; j < 10; j++) {
                    kind = lbl_8010A768[lbl_800E8558[i]._2][j]._2;
                    need = lbl_8010A768[lbl_800E8558[i]._2][j]._4;
                    level = lbl_8010A768[lbl_800E8558[i]._2][j]._6;
                    goal = lbl_80109AE8[lbl_800E8558[i]._2][j]._0;
                    if (goal != -1 && c->_09[j]._0 < 0) {
                        c->_09[j]._1 = 1;
                    }
                    if (kind == 1 && fn_8006CDC0(i) >= need && lbl_2_bss_1A8248->_4415 >= level) {
                        c->_09[j]._1 = 1;
                    }
                }
            }
        }
    }
}

// .text:0x000430F4 size:0x1F8
// Registers only: the target keeps all four mission fields in saved registers
// (r28-r31) and the inlined fn_2_44238 count in r12.
void fn_2_430F4(void) {
    s32 i;
    s32 j;
    s16 goal;
    s16 level;
    s16 need;
    s16 kind;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        if (lbl_800E8558[i]._3 == 1) {
            c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
            if (c->_31 == 1) {
                for (j = 0; j < 10; j++) {
                    goal = lbl_80109AE8[lbl_800E8558[i]._2][j]._0;
                    level = lbl_8010A768[lbl_800E8558[i]._2][j]._6;
                    need = lbl_8010A768[lbl_800E8558[i]._2][j]._4;
                    kind = lbl_8010A768[lbl_800E8558[i]._2][j]._2;
                    if (kind != -1 && c->_09[j]._1 == 0) {
                        switch (kind) {
                        case 2:
                            if (lbl_2_bss_1A8248->_4415 >= need) {
                                c->_09[j]._1 = 1;
                            }
                            break;
                        case 21:
                            if (fn_2_44238(need) == 1 && lbl_2_bss_1A8248->_4415 >= level) {
                                c->_09[j]._1 = 1;
                            }
                            break;
                        }
                    }
                    if (goal != -1 && c->_09[j]._0 < 0) {
                        c->_09[j]._1 = 1;
                    }
                }
            }
        }
    }
}

// .text:0x00042FC8 size:0x12C
// Only the lbl_80109AE8 and lbl_8010A768 bases differ: the target forms
// lbl_80109AE8 first, in the lower register (fn_2_466AC, written the same
// way without the two guards, matches).
void fn_2_42FC8(void) {
    s32 i;
    s32 j;
    s16 kind;
    s16 goal;
    s16 need;
    s16 level;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        if (lbl_800E8558[i]._3 == 1) {
            c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
            if (c->_31 == 1) {
                for (j = 0; j < 10; j++) {
                    kind = lbl_8010A768[lbl_800E8558[i]._2][j]._2;
                    goal = lbl_80109AE8[lbl_800E8558[i]._2][j]._0;
                    need = lbl_8010A768[lbl_800E8558[i]._2][j]._4;
                    level = lbl_8010A768[lbl_800E8558[i]._2][j]._6;
                    if (kind != -1 && c->_09[j]._1 == 0 && kind == 1 && fn_8006CDC0(i) >= need && lbl_2_bss_1A8248->_4415 >= level) {
                        c->_09[j]._1 = 1;
                    }
                    if (goal != -1 && c->_09[j]._0 < 0) {
                        c->_09[j]._1 = 1;
                    }
                }
            }
        }
    }
}

// .text:0x00042EB0 size:0x118
// Only the lbl_80109AE8 and lbl_8010A768 bases differ: the target forms
// lbl_80109AE8 first, in the lower register (fn_2_466AC, written the same
// way without the two guards, matches).
void fn_2_42EB0(void) {
    s32 i;
    s32 j;
    s32 need;
    s32 goal;
    s32 kind;
    MenuCharacter08E8* c;

    for (i = 0; i < 0x36; i++) {
        if (lbl_800E8558[i]._3 == 1) {
            c = &((MenuCharacter08E8*)lbl_2_bss_1A8248)[i];
            if (c->_31 == 1) {
                for (j = 0; j < 10; j++) {
                    kind = lbl_8010A768[lbl_800E8558[i]._2][j]._2;
                    goal = lbl_80109AE8[lbl_800E8558[i]._2][j]._0;
                    need = lbl_8010A768[lbl_800E8558[i]._2][j]._4;
                    if (kind != -1 && c->_09[j]._1 == 0 && kind == 18 && lbl_2_bss_1A8248->_4415 >= need && lbl_2_bss_1A8248->_442A == 1) {
                        c->_09[j]._1 = 1;
                    }
                    if (goal != -1 && c->_09[j]._0 < 0) {
                        c->_09[j]._1 = 1;
                    }
                }
            }
        }
    }
}
