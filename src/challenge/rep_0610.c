#include "challenge/rep_0610.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"
#include "Dolphin/gx.h"
#include "C3/control.h"
#include "string.h"

typedef struct LITObj {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ f32 _40;
    /* 0x44 */ f32 _44;
    /* 0x48 */ f32 _48;
    /* 0x4C */ u8 _4C[0x58 - 0x4C];
    /* 0x58 */ f32 _58;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u8 _64[0x70 - 0x64];
    /* 0x70 */ u8 _70;
    /* 0x71 */ u8 _71;
    /* 0x72 */ u8 _72;
    /* 0x73 */ u8 _73[0xC0 - 0x73];
} LITObj; // size: 0xC0

// Animation or track list: a count and a list of nodes
typedef struct UnkNode0610 {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u8 _02[0x14 - 0x2];
    /* 0x14 */ void* _14;
    /* 0x18 */ u8 _18[0x64 - 0x18];
    /* 0x64 */ f32 _64;
    /* 0x68 */ f32 _68;
    /* 0x6C */ f32 _6C;
    /* 0x70 */ u8 _70[0xE8 - 0x70];
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
    /* 0x1C */ u8 _1C[0x98 - 0x1C];
    /* 0x98 */ u8 _98;
} UnkList0610;

typedef struct Unk0060Elem {
    /* 0x00 */ UnkList0610* _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ u8 _08[0xE - 0x8];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ Control _10;
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
    /* 0x6D */ u8 _6D[0x90 - 0x6D];
} Unk0060Elem; // size: 0x90

typedef struct Unk0060 {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u8 _02[0x34 - 0x2];
    /* 0x34 */ Unk0060Elem _34[1];
} Unk0060;

typedef struct UnkKey0610 {
    /* 0x0 */ f32 _0;
    /* 0x4 */ u8 _4[0x10 - 0x4];
} UnkKey0610; // size: 0x10

typedef struct UnkAnimRef0610 {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ struct {
        /* 0x0 */ s32 _0;
        /* 0x4 */ struct UnkKey0610* _4;
        /* 0x8 */ u16 _8;
        /* 0xA */ u8 _A[0xC - 0xA];
    }* _4;
} UnkAnimRef0610;

typedef struct UnkPoseBlock0610 {
    /* 0x00 */ u8 _00[0x5C];
} UnkPoseBlock0610; // size: 0x5C

typedef struct UnkPose0610 {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ UnkPoseBlock0610 _04;
    /* 0x60 */ u8 _60;
    /* 0x61 */ u8 _61[0x68 - 0x61];
    /* 0x68 */ UnkPoseBlock0610 _68;
    /* 0xC4 */ u8 _C4;
    /* 0xC5 */ u8 _C5[0xCD - 0xC5];
    /* 0xCD */ u8 _CD;
    /* 0xCE */ u8 _CE;
    /* 0xCF */ u8 _CF;
    /* 0xD0 */ u8 _D0;
    /* 0xD1 */ u8 _D1[0xD4 - 0xD1];
} UnkPose0610; // size: 0xD4

typedef struct Unk8036E548Actor {
    /* 0x000 */ UnkList0610* _000;
    /* 0x004 */ UnkList0610* _004;
    /* 0x008 */ struct {
        /* 0x00 */ u8 _00[0x10];
        /* 0x10 */ void* _10;
    }* _008;
    /* 0x00C */ u8 _00C[0x10 - 0xC];
    /* 0x010 */ UnkAnimRef0610* _010[1];
    /* 0x014 */ u8 _014[0x30 - 0x14];
    /* 0x030 */ struct UnkPose0610* _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ f32 _040;
    /* 0x044 */ f32 _044;
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x62 - 0x4C];
    /* 0x062 */ s16 _062;
    /* 0x064 */ u8 _064[0x72 - 0x64];
    /* 0x072 */ u16 _072[120];
    /* 0x162 */ u16 _162[(0x254 - 0x162) / 2];
    /* 0x254 */ u8 _254;
    /* 0x255 */ u8 _255[0x25A - 0x255];
    /* 0x25A */ u8 _25A;
    /* 0x25B */ u8 _25B;
    /* 0x25C */ u8 _25C[0x276 - 0x25C];
    /* 0x276 */ u8 _276;
    /* 0x277 */ u8 _277;
    /* 0x278 */ u8 _278;
    /* 0x279 */ u8 _279[0x27C - 0x279];
} Unk8036E548Actor; // size: 0x27C

typedef struct Unk8036E548 {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ Unk0060* _0060;
    /* 0x0064 */ u8 _0064[0xAC - 0x64];
    /* 0x00AC */ LITObj* _00AC[4];
    /* 0x00BC */ u8 _00BC[0x140 - 0xBC];
    /* 0x0140 */ UnkPose0610 _0140[13];
    /* 0x0C04 */ Unk8036E548Actor _0C04[13];
    /* 0x2C50 */ Unk8036E548Actor* _2C50[13];
    /* 0x2C84 */ u8 _2C84[0x3083 - 0x2C84];
    /* 0x3083 */ u8 _3083;
    /* 0x3084 */ u8 _3084;
} Unk8036E548;

extern Unk8036E548 lbl_8036E548;

typedef struct UnkTimer0610 {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ u8 _08[0x11 - 0x8];
    /* 0x11 */ u8 _11_0 : 3;
    /* 0x11 */ u8 _11_3 : 2;
    /* 0x11 */ u8 _11_5 : 3;
    /* 0x12 */ u8 _12[0x1A - 0x12];
    /* 0x1A */ u16 _1A;
    /* 0x1C */ u32* _1C;
} UnkTimer0610; // size: 0x20

typedef struct UnkTask0610 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ struct UnkTask0610* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u16 _12;
    /* 0x14 */ struct UnkTimer0610* _14;
    /* 0x18 */ u16 _18;
    /* 0x1A */ u8 _1A[0x1C - 0x1A];
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
} UnkTask0610;

extern UnkTask0610* lbl_803CC1B8;

typedef struct UnkTaskF50C {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ Vec _14;
    /* 0x20 */ Vec _20;
    /* 0x2C */ Vec _2C;
    /* 0x38 */ u32 _38;
    /* 0x3C */ u16 _3C;
    /* 0x3E */ u8 _3E;
    /* 0x3F */ u8 _3F;
} UnkTaskF50C;

typedef struct UnkTaskMenu0610 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x20 - 0x4];
    /* 0x20 */ u8 _20;
} UnkTaskMenu0610;

// A task whose state lives in two bytes at 0x14
typedef struct UnkTaskState0610 {
    /* 0x00 */ void (*_00)(void);
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ s8 _15;
} UnkTaskState0610;
extern u8 lbl_803CBBC0;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ void* _08;
} lbl_80366158;

typedef struct UnkBurst0610 {
    /* 0x00 */ void* _00;
    /* 0x04 */ u8 _04[0x50 - 0x4];
} UnkBurst0610;

extern UnkBurst0610 lbl_80108B90;

typedef struct UnkCamera0610 {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ Mtx _08;
} UnkCamera0610; // size: 0x38

extern UnkTask0610* fn_800B0A5C_insertQueue(void (*callback)(void), u16 arg1);
extern void fn_8004B208(s32, s32, s32);
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
extern void fn_800385F0(struct Unk30C0*, f32, f32, f32, f32);
extern void fn_80037AA0(struct Unk30C0*, s32, void (*)(s32), u16, UnkTimer0610*);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80011640(Mtx src, Mtx dst);
extern void fn_80052968(void);
extern void fn_800245EC(Mtx44 proj, Mtx view, Vec* points, f32 (*out)[2], s32 count, s32 arg5);
extern void* fn_80039AB4(void);
extern void fn_800B2BA8(UnkList0610* dst, u16 id, UnkList0610* src, u16 index);
extern void fn_80039A4C(void);
extern void LITAlloc(LITObj** light);
extern void LITInitAttn(LITObj* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern void LITInitColor(LITObj* light, GXColor color);
extern void LITInitDir(LITObj* light, f32 nx, f32 ny, f32 nz);
extern void LITInitPos(LITObj* light, f32 x, f32 y, f32 z);
extern void ACTSetAnimation(UnkList0610* actor, void* animBank, char* sequenceName, u16 seqNum, f32 time, f32 speed);
extern void fn_800B4CA0(UnkList0610* actor, f32 frame);
extern void fn_800B4C04(UnkList0610* actor, f32 speed);
extern void fn_800B4AFC(UnkList0610* actor, s32 flag);
extern void Set_FUN_800b2b6c(UnkList0610* actor, void* arg1);
extern void fn_800BDA24(Unk0060Elem* model);
extern u8 fn_800B3C04(s32 arg0, UnkList0610* actor, Mtx mtx);
extern void fn_800B2B74(UnkList0610* list, u16 id);
extern void fn_80052D70(UnkTask0610* task);
extern void makeLookAtMatrix(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);
extern void fn_1_F2C(s32, s32, s32);
extern void fn_8002F1AC(Vec* pos, u32 id);
extern void fn_8002F258(Vec* pos, u32 id, void* params);
extern void minigamesSetSomePointers(void);
extern void fn_800BD2CC(s32 arg0, GXColor color);
extern void fn_800BD670(void* model, Mtx mtx);
extern void fn_800BDA94(Unk0060Elem* model, Mtx mtx);
extern void fn_800B2C88(UnkList0610* list, u16 index, Mtx out);
extern void fn_800B806C(s32, f32, f32, f32, f32, f32, f32, f32);
extern void fn_80031CA4(Vec* pos, UnkBurst0610* glow);
extern void fn_80030D88(Vec* pos, Vec* dir, UnkBurst0610* burst, s32 n);
extern void* ARAMTransfer(void* entry, int arg1, int arg2, u32 aram);
extern void convertTextureHeader(void* tex);

typedef struct UnkSlot0610 {
    /* 0x0 */ s8 _0;
    /* 0x1 */ s8 _1;
    /* 0x2 */ s16 _2;
    /* 0x4 */ s16 _4;
    /* 0x6 */ s16 _6;
} UnkSlot0610; // size: 0x8

typedef struct UnkSlotSet0610 {
    /* 0x00 */ s8 _00;
    /* 0x01 */ u8 _01[0x10 - 0x1];
    /* 0x10 */ UnkSlot0610 _10[8];
} UnkSlotSet0610; // size: 0x50

typedef struct UnkSlotState0610 {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
    /* 0x4 */ s16 _4;
    /* 0x6 */ s16 _6;
} UnkSlotState0610; // size: 0x8

extern struct {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
    /* 0x4 */ UnkSlotSet0610* _4;
} lbl_1_data_F4D4;
extern UnkCamera0610 lbl_1_data_F4F8[];
extern UnkCamera0610 lbl_1_data_AA54[];
extern UnkCamera0610 lbl_1_data_AAC4[];
extern UnkCamera0610 lbl_1_data_AB34[];
extern UnkBurst0610* lbl_1_data_F278[3];
extern u8 lbl_1_data_F0A8[];
extern UnkBurst0610 lbl_1_data_F0BC;
extern u8 lbl_1_data_F284[];

typedef struct UnkSpark0610 {
    /* 0x00 */ void* _00;
    /* 0x04 */ u8 _04[0x5C - 0x4];
    /* 0x5C */ s32 _5C;
    /* 0x60 */ s32 _60;
    /* 0x64 */ u8 _64[0x68 - 0x64];
} UnkSpark0610;

extern UnkSpark0610 lbl_1_data_F10C;
typedef struct UnkFootprint0610 {
    /* 0x0 */ void* _0;
    /* 0x4 */ s32 _4;
} UnkFootprint0610;

extern UnkFootprint0610* lbl_1_data_F174[2];
typedef struct UnkPair0610 {
    /* 0x0 */ u16 _0;
    /* 0x2 */ u16 _2;
} UnkPair0610;

extern void* lbl_1_data_F4DC[3];
extern UnkPair0610 lbl_1_data_F4E8[4];
extern UnkBurst0610 lbl_1_data_F2A0;
extern u16 lbl_1_data_F17C;
extern u16 lbl_1_data_F56C;
extern u16 lbl_1_data_F56E;
extern UnkPair0610 lbl_1_data_1DC0[];
extern UnkPair0610 lbl_1_data_1E18[];
extern u8 lbl_1_data_1F1A[0x476];
extern u8 lbl_1_data_A940[];
extern u8 lbl_1_data_2390[7];
extern s16 lbl_1_data_A978[];
extern u8 lbl_1_data_A938[8];
extern u8 lbl_1_data_ABA8;
extern s8 lbl_1_data_AC90[];
extern Vec lbl_1_data_AD0C;
extern Vec lbl_1_data_AD18;
extern Vec lbl_1_data_AD30[8];
extern u8 lbl_1_data_AD90[6][4];
extern u32 lbl_1_data_ADA8[6];
extern Vec lbl_1_data_AD24;
extern f32 lbl_1_data_ADC0;
extern f32 lbl_1_data_F568;
extern f32 lbl_1_data_F570[6];
extern u8 lbl_1_data_ADC4[0x1C];
extern u8 lbl_1_data_ADE0[];

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

typedef struct UnkTexFile0610 {
    /* 0x00 */ u32 _00;
    /* 0x04 */ struct {
        /* 0x00 */ u8 _00[0x20];
    } _04[1];
} UnkTexFile0610;

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
    /* 0x40 */ u8 _40[4];
} lbl_1_bss_68FC;
static struct Unk67E0 {
    /* 0x000 */ Mtx _000;
    /* 0x030 */ LITObj _030;
    /* 0x0F0 */ u16 _0F0;
    /* 0x0F2 */ u16 _0F2;
    /* 0x0F4 */ f32 _0F4;
    /* 0x0F8 */ f32 _0F8;
    /* 0x0FC */ Vec _0FC;
    /* 0x108 */ Vec _108;
    /* 0x114 */ s32 _114;
    /* 0x118 */ u8 _118;
} lbl_1_bss_67E0;
static UnkTimer0610* lbl_1_bss_67B8[10];
static u8 lbl_1_bss_6764[0x54];
static UnkPoseBlock0610 lbl_1_bss_60EC[18];
static UnkTask0610* lbl_1_bss_60E8;
static UnkTexFile0610* lbl_1_bss_60E4;
static Unk0060* lbl_1_bss_60E0;
static s32 lbl_1_bss_60DC;
static u8 lbl_1_bss_60A4[0x36];
static s32 lbl_1_bss_60A0;
static u8 lbl_1_bss_5F88[0x118];
static u8 lbl_1_bss_5F80[8];
static Unk0060* lbl_1_bss_5F7C[1];
static u8 lbl_1_bss_5F78;
static f32 lbl_1_bss_5F74;
static u8 lbl_1_bss_5F73;
static u8 lbl_1_bss_5F72;
static u8 lbl_1_bss_5F71;
static s8 lbl_1_bss_5F70;
static u32 lbl_1_bss_5F6C;
static u8 lbl_1_bss_5F69;
static u8 lbl_1_bss_5F68;
static f32 lbl_1_bss_5F64;
static u8 lbl_1_bss_5F63;
static s8 lbl_1_bss_5F62;
static u16 lbl_1_bss_5F60;
static s32 lbl_1_bss_5F5C;
static s32 lbl_1_bss_5F58;
static u32 lbl_1_bss_3758[8][5][0x40];
static UnkTimer0610 lbl_1_bss_3258[8][5];
static UnkSlotState0610 lbl_1_bss_3218[8];
static u8 lbl_1_bss_3216;
static u8 lbl_1_bss_3215;
static u8 lbl_1_bss_3214;
static struct Unk30C0 {
    /* 0x000 */ Vec _000;
    /* 0x00C */ Vec _00C;
    /* 0x018 */ u8 _018[0x50 - 0x18];
    /* 0x050 */ f32 _050;
    /* 0x054 */ u8 _054[0x58 - 0x54];
    /* 0x058 */ Mtx _058;
    /* 0x088 */ u8 _088[0x128 - 0x88];
    /* 0x128 */ Vec _128;
    /* 0x134 */ u8 _134[0x140 - 0x134];
    /* 0x140 */ Vec _140;
    /* 0x14C */ u8 _14C[0x154 - 0x14C];
} lbl_1_bss_30C0;
static s32 lbl_1_bss_30BC;
static u8 lbl_1_bss_30B8;
static u8 lbl_1_bss_30B7;
static u8 lbl_1_bss_30B6;
static s16 lbl_1_bss_30B4;
static s32 lbl_1_bss_30B0;
static s32 lbl_1_bss_30AC;
static s32 lbl_1_bss_30A8;
static u16 lbl_1_bss_30A4;
static s32 lbl_1_bss_30A0;
static s32 lbl_1_bss_309C;
static void* lbl_1_bss_3098[1];
static void* lbl_1_bss_3094;
static u8 lbl_1_bss_3090;
static s32 lbl_1_bss_308C;
static s32 lbl_1_bss_3088;
static s32 lbl_1_bss_3084[1];
static u8 lbl_1_bss_3081;
static u8 lbl_1_bss_3080;
static s32 lbl_1_bss_307C;
static u8 lbl_1_bss_3078;
static s32 lbl_1_bss_3074;
static s32 lbl_1_bss_3070;

// .text:0x00017D90 size:0x16C
void fn_1_17D90(void) {
    fn_800AD038(lbl_80366158._08);
    lbl_803CC1B8->_10 = 0;
    lbl_803CC1B8->_00 = fn_1_17B5C;
    fn_1_E8D4();
}

// .text:0x00017B5C size:0x234
// The target's search tests fixed offsets of lbl_1_data_2390 after one lbzu,
// and its unrolled flag loop is scheduled differently; 88%
void fn_1_17B5C(void) {
    s32 i;
    s32 first;
    lbl_1_bss_5F62 = -1;
    lbl_1_bss_5F60 = 4;
    for (i = 0; i < 0x36; i++) {
        lbl_1_bss_60A4[i] = lbl_1_data_A978[i] != -1;
    }
    for (first = 0; first < 7; first++) {
        if (lbl_1_data_2390[first] != 0) {
            break;
        }
    }
    lbl_1_bss_68FC._40[0] = 0;
    lbl_1_bss_6940[0]._44 = first;
    lbl_1_bss_6940[0]._45 = 0;
    lbl_1_bss_6940[0]._46 = 0;
    lbl_1_bss_5F5C = 0;
    lbl_803CC1B8->_00 = fn_1_176EC;
    fn_80052D70(lbl_803CC1B8);
}

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

// .text:0x000168C8 size:0xB0
void fn_1_168C8(void) {
    UnkTask0610* task = lbl_803CC1B8;
    if (lbl_1_bss_3084[0] == 0) {
        lbl_1_bss_3084[0] = 1;
        task->_1C = OSGetTick();
        fn_1_135C0();
        task->_1C = OSGetTick() - task->_1C;
    } else {
        lbl_1_bss_3084[0] = 0;
        task->_10 = 0;
        if (lbl_8036E548._0C04[0]._008->_10 != NULL) {
            lbl_803CC1B8->_00 = fn_1_1770C;
        } else {
            lbl_803CC1B8->_00 = fn_1_1770C;
        }
    }
}

// .text:0x000165E0 size:0x2E8
void fn_1_165E0(void) {
    s16 delta = 0;
    LITObj* light = lbl_8036E548._00AC[lbl_1_bss_5F70];
    if (lbl_803C77B8[0]._04 & 1) {
        delta = -1;
    } else if (lbl_803C77B8[0]._04 & 2) {
        delta = 1;
    } else if (lbl_803C77B8[0]._04 & 8) {
        if (--lbl_1_bss_307C < 0) {
            lbl_1_bss_307C = 9;
        }
    } else if (lbl_803C77B8[0]._04 & 4) {
        if (++lbl_1_bss_307C >= 10) {
            lbl_1_bss_307C = 0;
        }
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        lbl_1_bss_5F70 = 0;
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 1;
    }
    if (lbl_803C77B8[0]._00 & 0x400) {
        delta *= 10;
    }
    switch (lbl_1_bss_307C) {
    case 0:
        lbl_1_bss_5F70 += delta;
        if (lbl_1_bss_5F70 < 0) {
            lbl_1_bss_5F70 = 2;
        } else if (lbl_1_bss_5F70 >= 3) {
            lbl_1_bss_5F70 = 0;
        }
        break;
    case 1:
        light->_70 += delta;
        if (light->_70 > 255) {
            light->_70 = 0;
        }
        break;
    case 2:
        light->_71 += delta;
        if (light->_71 > 255) {
            light->_71 = 0;
        }
        break;
    case 3:
        light->_72 += delta;
        if (light->_72 > 255) {
            light->_72 = 0;
        }
        break;
    case 4:
        light->_40 += delta;
        break;
    case 5:
        light->_44 += delta;
        break;
    case 6:
        light->_48 += delta;
        break;
    case 7:
        light->_58 += delta;
        break;
    case 8:
        light->_5C += delta;
        break;
    case 9:
        light->_60 += delta;
        break;
    }
}

// .text:0x00016590 size:0x50
s32 fn_1_16590(void) {
    return fn_1_16558(lbl_1_bss_6940[lbl_1_bss_5F73]._44, lbl_1_bss_6940[lbl_1_bss_5F73]._45);
}

// .text:0x00016558 size:0x38
s32 fn_1_16558(s32 arg0, s32 arg1) {
    return lbl_8036E548._0C04[lbl_1_bss_5F73]._010[arg0]->_4[arg1]._0;
}

// .text:0x0001644C size:0x10C
void fn_1_1644C(void) {
    s32 idx = lbl_1_bss_5F73;
    Unk8036E548Actor* actor = lbl_8036E548._2C50[idx];
    Unk0060Elem* elem;
    s32 i;
    lbl_1_bss_5F69 ^= 1;
    if (actor == NULL) {
        return;
    }
    elem = &lbl_8036E548._0060->_34[idx];
    if (lbl_1_bss_5F69 == 0) {
        elem->_68 = NULL;
    } else {
        elem->_68 = actor->_072;
    }
    fn_1_ECF8(lbl_1_bss_5F73, lbl_1_bss_6940[lbl_1_bss_5F73]._44, lbl_1_bss_5F69);
    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_67B8[i] != NULL) {
            lbl_1_bss_67B8[i]->_11_3 = 3;
        }
    }
}

// .text:0x00016400 size:0x4C
void fn_1_16400(s8 arg0) {
    UnkList0610* list = lbl_8036E548._0C04[lbl_1_bss_5F73]._004;
    lbl_1_bss_5F6C = (lbl_1_bss_5F6C + list->_06 + arg0) % list->_06;
}

// .text:0x000163FC size:0x4
void fn_1_163FC(void) {}

// .text:0x0001620C size:0x1F0
void fn_1_1620C(void) {
    s32 i = 0;
    do {
        lbl_8036E548._0C04[i]._034 = 0.0f;
        lbl_8036E548._0C04[i]._038 = 0.0f;
        lbl_8036E548._0C04[i]._03C = 10.0f;
        lbl_8036E548._0C04[i]._040 = 0.0f;
        lbl_8036E548._0C04[i]._044 = 0.0f;
        lbl_8036E548._0C04[i]._048 = 0.0f;
        CTRLSetTranslation(&lbl_8036E548._0060->_34[i]._10, 0.0f, 0.0f, 0.0f);
        CTRLSetRotation(&lbl_8036E548._0060->_34[i]._10, 0.0f, 0.0f, 0.0f);
    } while (++i < 1);
    fn_1_1347C();
}

// .text:0x000161D0 size:0x3C
void fn_1_161D0(void) {
    lbl_1_bss_5F78 ^= 1;
    fn_800B9A9C(lbl_1_bss_5F78, lbl_1_bss_5F74);
}

// .text:0x000160F8 size:0xD8
void fn_1_160F8(s32 arg0) {
    f32 step = 0.01f;
    if (lbl_803C77B8[0]._00 & 0x400) {
        step *= 10.0f;
    }
    step *= arg0;
    lbl_1_bss_5F74 += step;
    if (lbl_1_bss_5F74 > 1.0f) {
        lbl_1_bss_5F74 = 0.0f;
    }
    if (lbl_1_bss_5F74 < 0.0f) {
        lbl_1_bss_5F74 = 1.0f;
    }
    fn_800B9A9C(lbl_1_bss_5F78, lbl_1_bss_5F74);
}

// .text:0x000160D8 size:0x20
u16 fn_1_160D8(s8 arg0, s8 arg1) {
    if (arg0 == arg1) {
        return 0xFF0F;
    }
    return 0xFFFF;
}

// .text:0x00015CE0 size:0x3F8
void fn_1_15CE0(void) {
    if (lbl_803C77B8[0]._04 & 8) {
        if (--lbl_1_bss_307C < 0) {
            lbl_1_bss_307C = 5;
        }
    } else if (lbl_803C77B8[0]._04 & 4) {
        if (++lbl_1_bss_307C >= 6) {
            lbl_1_bss_307C = 0;
        }
    } else if (lbl_803C77B8[0]._04 & 1) {
        switch (lbl_1_bss_307C) {
        case 0:
            if (--lbl_1_bss_5F72 >= 2) {
                lbl_1_bss_5F72 = 1;
            }
            break;
        case 2:
            lbl_1_bss_67E0._118 ^= 1;
            break;
        case 3:
            lbl_1_data_1F1A[0] ^= 1;
            break;
        case 4:
            if (lbl_1_bss_5F62 >= 0) {
                lbl_1_bss_5F62--;
            }
            break;
        case 5:
            if (lbl_1_bss_5F60 > 1) {
                lbl_1_bss_5F60--;
            }
            break;
        }
    } else if (lbl_803C77B8[0]._04 & 2) {
        switch (lbl_1_bss_307C) {
        case 0:
            if (++lbl_1_bss_5F72 >= 2) {
                lbl_1_bss_5F72 = 0;
            }
            break;
        case 2:
            lbl_1_bss_67E0._118 ^= 1;
            break;
        case 3:
            lbl_1_data_1F1A[0] ^= 1;
            break;
        case 4:
            if (lbl_1_bss_5F62 < 1) {
                lbl_1_bss_5F62++;
            }
            break;
        case 5:
            if (lbl_1_bss_5F60 < 16) {
                lbl_1_bss_5F60++;
            }
            break;
        }
    } else if (lbl_803C77B8[0]._04 & 0x100) {
        switch (lbl_1_bss_307C) {
        case 1:
            fn_1_1620C();
            break;
        }
    } else if (lbl_803C77B8[0]._04 & 0x200) {
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 1;
    }
}

// .text:0x0001540C size:0x354
// fn_1_1644C is inlined here twice, where the target calls it; the rest is
// believed right
void fn_1_1540C(void) {
    char text[0x28];
    s32 top;
    s32 lines;
    s32 selected;
    u16 id;
    lines = 20;
    selected = lbl_1_bss_5F6C;
    if (lbl_1_bss_3088 > selected) {
        lbl_1_bss_3088 = selected;
    } else if (lbl_1_bss_3088 < selected - 19) {
        lbl_1_bss_3088 = selected - 19;
    }
    top = lbl_1_bss_3088;
    fn_1_C2DC(lbl_8036E548._0060->_34[lbl_1_bss_5F73]._00->_18[0], text, 0, 19, 4, &selected, &top, &lines);
    if (lbl_803C77B8[0]._04 & 8) {
        if (--lbl_1_bss_307C < 0) {
            lbl_1_bss_307C = 5;
        }
    } else if (lbl_803C77B8[0]._04 & 4) {
        if (++lbl_1_bss_307C >= 6) {
            lbl_1_bss_307C = 0;
        }
    } else if (lbl_803C77B8[0]._04 & 1) {
        switch (lbl_1_bss_307C) {
        case 0:
            lbl_1_bss_3080 ^= 1;
            break;
        case 1:
            lbl_1_data_ABA8 ^= 1;
            break;
        case 2:
            fn_1_16400(-1);
            break;
        case 4:
            if (lbl_1_data_AC90[0] >= 0) {
                lbl_1_data_AC90[0]--;
            }
            break;
        case 5:
            fn_1_1644C();
            break;
        }
    } else if (lbl_803C77B8[0]._04 & 2) {
        switch (lbl_1_bss_307C) {
        case 0:
            lbl_1_bss_3080 ^= 1;
            break;
        case 1:
            lbl_1_data_ABA8 ^= 1;
            break;
        case 2:
            fn_1_16400(1);
            break;
        case 4:
            if (lbl_1_data_AC90[0] < 4) {
                lbl_1_data_AC90[0]++;
            }
            break;
        case 5:
            fn_1_1644C();
            break;
        }
    } else if (lbl_803C77B8[0]._04 & 0x200) {
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 1;
    }
    id = lbl_8036E548._0C04[0]._162[0x24];
    if (id != 0xFFFF) {
        if (lbl_1_data_AC90[0] >= 0) {
            UnkList0610* src = lbl_1_bss_60E0->_34[lbl_1_data_AC90[0]]._00;
            s32 i;
            for (i = 0; i < src->_06; i++) {
                if (src->_18[i]->_14 != NULL) {
                    fn_800B2BA8(lbl_8036E548._0060->_34[0]._00, id, src, i);
                }
            }
        } else {
            fn_800B2BA8(lbl_8036E548._0060->_34[0]._00, id, NULL, 0);
        }
    }
}

// .text:0x000151F8 size:0x214
void fn_1_151F8(void) {
    if (lbl_803C77B8[0]._04 & 8) {
        if (--lbl_1_bss_307C < 0) {
            lbl_1_bss_307C = 1;
        }
    } else if (lbl_803C77B8[0]._04 & 4) {
        if (++lbl_1_bss_307C >= 2) {
            lbl_1_bss_307C = 0;
        }
    } else if (lbl_803C77B8[0]._04 & 1) {
        switch (lbl_1_bss_307C) {
        case 0:
            fn_1_161D0();
            break;
        case 1:
            fn_1_160F8(-1);
            break;
        }
    } else if (lbl_803C77B8[0]._04 & 2) {
        switch (lbl_1_bss_307C) {
        case 0:
            fn_1_161D0();
            break;
        case 1:
            fn_1_160F8(1);
            break;
        }
    } else if (lbl_803C77B8[0]._04 & 0x200) {
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 1;
    }
}

// .text:0x00015170 size:0x88
void fn_1_15170(void) {
    if (lbl_803C77B8[0]._04 & 0x200) {
        fn_1_148CC();
    } else if (lbl_803C77B8[0]._04 & 0x100) {
        lbl_1_bss_5F71 = 1;
    }
}

// .text:0x00014FB8 size:0x1B8
void fn_1_14FB8(void) {
    u16 buttons = lbl_803C77B8[0]._04;
    UnkTaskMenu0610* task = (UnkTaskMenu0610*)lbl_803CC1B8;
    if (buttons & 8) {
        if (task->_20 != 0) {
            task->_20--;
        } else {
            task->_20 = 8;
        }
    } else if (buttons & 4) {
        task->_20++;
        if (task->_20 == 9) {
            task->_20 = 0;
        }
    } else if (lbl_803C77B8[0]._00 & 0x100) {
        switch (task->_20) {
        case 0:
            if (buttons & 0x100) {
                lbl_1_bss_5F71 = 3;
            }
            break;
        case 1:
            if (buttons & 0x100) {
                lbl_1_bss_5F71 = 4;
            }
            break;
        case 2:
            if (buttons & 0x100) {
                lbl_1_bss_5F71 = 5;
            }
            break;
        case 3:
            if (buttons & 0x100) {
                lbl_1_bss_5F71 = 6;
            }
            break;
        case 4:
            if (lbl_803C77B8[0]._02 & 0x100) {
                lbl_1_bss_5F71 = 2;
            }
            break;
        case 5:
            if (lbl_803C77B8[0]._02 & 0x100) {
                lbl_1_bss_5F71 = 8;
            }
            break;
        case 6:
            if (lbl_803C77B8[0]._02 & 0x100) {
                lbl_1_bss_5F71 = 7;
            }
            break;
        case 7:
            if (buttons & 0x100) {
                lbl_1_bss_5F71 = 9;
            }
            break;
        case 8:
            if (buttons & 0x100) {
                lbl_1_bss_5F71 = 10;
            }
            break;
        }
    } else if (lbl_803C77B8[0]._02 & 0x200) {
        lbl_1_bss_5F71 = 0;
        minigamesSetSomePointers();
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

// .text:0x00014710 size:0x178
void fn_1_14710(Unk8036E548Actor* arg0) {
    s32 i;
    UnkPair0610* pair;
    UnkPair0610* list;
    u16 a;
    u16 b;
    for (i = 0; i < 120; i++) {
        arg0->_072[i] = i;
    }
    pair = lbl_1_data_1DC0;
    i = 0;
    do {
        a = arg0->_162[pair->_0];
        b = arg0->_162[pair->_2];
        if (a != 0xFFFF && b != 0xFFFF) {
            arg0->_072[a] = b;
            arg0->_072[b] = a;
        }
        pair++;
    } while (lbl_1_data_1DC0[++i]._0 != 0xFFFF);
    switch (lbl_1_bss_68FC._40[lbl_1_bss_5F73]) {
    case 0x10:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x2F:
        list = lbl_1_data_1E18;
        break;
    default:
        list = NULL;
        break;
    }
    if (list != NULL) {
        for (pair = list; pair->_0 != 0xFFFF; pair++) {
            a = arg0->_162[pair->_0];
            b = arg0->_162[pair->_2];
            if (a != 0xFFFF && b != 0xFFFF) {
                arg0->_072[a] = b;
                arg0->_072[b] = a;
            }
        }
    }
}

// .text:0x0001347C size:0x144
void fn_1_1347C(void) {
    lbl_1_bss_67E0._108.x = 0.0f;
    lbl_1_bss_67E0._108.y = -0.8f;
    lbl_1_bss_67E0._108.z = 0.0f;
    lbl_1_bss_67E0._0FC.x = 0.0f;
    lbl_1_bss_67E0._0FC.y = 0.0f;
    lbl_1_bss_67E0._0FC.z = 10.0f;
    fn_1_17954();
    fn_800B806C(0, -240.0f, 240.0f, -320.0f, 320.0f, -512.0f, -0.001f, 1280.0f);
    lbl_1_bss_67E0._114 = 0;
    lbl_1_bss_67E0._0F8 = 0.0f;
    lbl_1_bss_67E0._0F0 = 0;
    lbl_1_bss_67E0._0F2 = 0;
}

// .text:0x000131E4 size:0x298
void fn_1_131E4(void) {
    GXColor white = { 0xFF, 0xFF, 0xFF, 0xFF };
    GXColor blue = { 0x00, 0x00, 0xFF, 0xFF };
    GXColor red = { 0xFF, 0x00, 0x00, 0xFF };
    LITAlloc(&lbl_8036E548._00AC[0]);
    LITAlloc(&lbl_8036E548._00AC[1]);
    LITAlloc(&lbl_8036E548._00AC[2]);
    LITAlloc(&lbl_8036E548._00AC[3]);
    LITInitAttn(lbl_8036E548._00AC[0], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._00AC[0], 5.0f, -10.0f, 5.0f);
    LITInitDir(lbl_8036E548._00AC[0], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_8036E548._00AC[0], white);
    LITInitDir(lbl_8036E548._00AC[0], -5.0f, 0.0f, -5.0f);
    LITInitAttn(lbl_8036E548._00AC[1], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._00AC[1], -5.0f, -10.0f, 0.0f);
    LITInitDir(lbl_8036E548._00AC[1], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_8036E548._00AC[1], white);
    LITInitAttn(lbl_8036E548._00AC[2], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._00AC[2], 0.0f, -10.0f, 5.0f);
    LITInitDir(lbl_8036E548._00AC[2], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_8036E548._00AC[2], white);
    LITInitAttn(lbl_8036E548._00AC[3], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    LITInitPos(lbl_8036E548._00AC[3], 0.0f, -10.0f, -5.0f);
    LITInitDir(lbl_8036E548._00AC[3], 0.0f, 0.0f, 0.0f);
    LITInitColor(lbl_8036E548._00AC[3], white);
}

// .text:0x00012F8C size:0x258
void fn_1_12F8C(Unk0060* arg0, Mtx arg1) {
    Mtx m;
    Vec v;
    u16 i;
    for (i = 0; i < arg0->_00; i++) {
        Unk0060Elem* elem = &arg0->_34[i];
        UnkList0610* model;
        if (elem->_00 == NULL) {
            continue;
        }
        if (elem->_58 != 0) {
            ACTSetAnimation(elem->_00, elem->_04, NULL, elem->_0E, 0.0f, elem->_60);
        }
        if (elem->_59 != 0) {
            fn_800B4CA0(elem->_00, elem->_5C);
        }
        if (elem->_5A != 0) {
            fn_800B4C04(elem->_00, elem->_54);
        }
        if (elem->_5B & 2) {
            fn_800B4AFC(elem->_00, (elem->_5B & 1) != 0);
        }
        Set_FUN_800b2b6c(elem->_00, elem->_68);
        if (arg0->_34[i]._6C != 0) {
            fn_800BDA24(elem);
            if (lbl_1_bss_3081 != 0) {
                v.x = lbl_1_bss_67E0._108.x - lbl_8036E548._0C04[i]._034;
                v.y = lbl_1_bss_67E0._108.y - lbl_8036E548._0C04[i]._038;
                v.z = lbl_1_bss_67E0._108.z - lbl_8036E548._0C04[i]._03C;
                fn_80026134(0, &v);
                fn_80026130(0, lbl_1_data_ADC4, lbl_1_data_ADC0);
            }
            if (lbl_1_bss_308C != 0) {
                lbl_1_bss_308C = 0;
                for (i = 0; i < elem->_00->_06; i++) {
                    UnkNode0610* node = elem->_00->_18[i];
                    OSReport("#%3d %f %f %f\n", node->_00, node->_64, node->_68, node->_6C);
                }
            }
        }
        PSMTXTrans(m, lbl_8036E548._0C04[i]._034, lbl_8036E548._0C04[i]._038, lbl_8036E548._0C04[i]._03C);
        PSMTXConcat(arg1, m, m);
        model = elem->_00;
        model->_98 = (model->_98 & 0xFC) | fn_800B3C04(0, model, m);
        arg0->_34[i]._58 = 0;
        arg0->_34[i]._59 = 0;
        arg0->_34[i]._5A = 0;
        arg0->_34[i]._5B &= 1;
    }
}

// .text:0x00012F18 size:0x74
void fn_1_12F18(UnkCamera0610* arg0) {
    fn_1_12820(lbl_8036E548._0060, arg0->_08);
    if (lbl_1_data_A978[lbl_1_bss_68FC._40[0]] >= 0) {
        fn_800BD670(lbl_1_bss_5F7C[0], arg0->_08);
    }
}

// .text:0x00012820 size:0x1B0
// Only i and &arg0->_34[i] swap r30 and r31; declaration orders and the
// permuter (only a dead `if (1)`) did not fix it
void fn_1_12820(Unk0060* arg0, Mtx arg1) {
    GXColor color = { 0x64, 0x72, 0x6C, 0xFF };
    Mtx m;
    u16 i;
    u8 alpha = 0xFF;
    fn_1_17954();
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetCullMode(GX_CULL_BACK);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_OR);
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
    for (i = 0; i < arg0->_00; i++) {
        Unk8036E548Actor* actor = &lbl_8036E548._0C04[i];
        if (arg0->_34[i]._00 == NULL) {
            continue;
        }
        arg0->_34[i]._00->_98 = 0xFF;
        if (arg0->_34[i]._6C == 0) {
            continue;
        }
        if (alpha != actor->_277) {
            alpha = actor->_277;
            if (0xFF - alpha != 0) {
                color.a = alpha;
                if (alpha == 0) {
                    continue;
                }
                fn_800BD2CC(1, color);
            } else {
                color.a = 0xFF;
                fn_800BD2CC(0, color);
            }
        }
        PSMTXTrans(m, lbl_8036E548._0C04[i]._034, lbl_8036E548._0C04[i]._038, lbl_8036E548._0C04[i]._03C);
        PSMTXConcat(arg1, m, m);
        fn_800BDA94(&arg0->_34[i], m);
    }
}

// .text:0x000126CC size:0x154
// The conversions' stack slots match the target; the scheduling of the
// loads, conversions and stores differs throughout; 37%
void fn_1_126CC(void) {
    Unk8036E548Actor* actor = &lbl_8036E548._0C04[lbl_1_bss_5F73];
    actor->_034 += lbl_803C77B8[0]._10 / 768.0f;
    actor->_03C += lbl_803C77B8[0]._11 / 768.0f;
    actor->_038 = actor->_038 + lbl_803C77B8[0]._15 / 768.0f - lbl_803C77B8[0]._14 / 768.0f;
    lbl_1_data_AD0C.y -= lbl_803C77B8[0]._12 / 512.0f;
    lbl_1_data_AD0C.x -= lbl_803C77B8[0]._13 / 512.0f;
    actor->_040 = lbl_1_data_AD0C.x;
    actor->_044 = lbl_1_data_AD0C.y;
    actor->_048 = lbl_1_data_AD0C.z;
}

// .text:0x000121D4 size:0x4F8
void fn_1_121D4(struct Unk67E0* arg0) {
    switch (arg0->_114) {
    case 0:
        fn_1_11F08(arg0);
        break;
    case 1:
        fn_1_11D00(arg0);
        break;
    }
    fn_80011640(arg0->_000, arg0->_000);
    PSVECSubtract(&arg0->_108, &arg0->_0FC, (Vec*)&arg0->_030._58);
    PSVECNormalize((Vec*)&arg0->_030._58, (Vec*)&arg0->_030._58);
    fn_80052968();
}

// .text:0x00011F08 size:0x2CC
void fn_1_11F08(struct Unk67E0* arg0) {
    Mtx rotX;
    Mtx rotY;
    Mtx m;
    Vec rot;
    Vec v = { 0.0f, 0.0f, 100.0f };
    f32 cosY;
    f32 sinY;
    camera_803c639c_s* camera;
    if (!(lbl_803C77B8[0]._00 & 0x10)) {
        arg0->_0F0 -= lbl_803C77B8[0]._13 * 4;
        arg0->_0F2 += lbl_803C77B8[0]._12 * 4;
        arg0->_0F4 = lbl_803C77B8[0]._10 / -256.0f;
        arg0->_0F8 = lbl_803C77B8[0]._11 / 256.0f;
        arg0->_108.y += lbl_803C77B8[0]._15 / 1024.0f;
        arg0->_108.y -= lbl_803C77B8[0]._14 / 1024.0f;
    }
    rot.x = arg0->_0F0;
    rot.y = arg0->_0F2;
    rot.z = 0.0f;
    PSVECScale(&rot, 0.0000958738f, &rot);
    PSMTXRotRad(rotX, 'X', rot.x);
    PSMTXRotRad(rotY, 'Y', rot.y);
    sinY = rotY[0][2];
    cosY = rotY[0][0];
    PSMTXConcat(rotY, rotX, m);
    PSMTXMultVec(m, &v, &arg0->_0FC);
    arg0->_108.x += arg0->_0F8 * sinY - arg0->_0F4 * cosY;
    arg0->_108.z += arg0->_0F8 * cosY + arg0->_0F4 * sinY;
    arg0->_0FC.x += arg0->_108.x;
    arg0->_0FC.y += arg0->_108.y;
    arg0->_0FC.z += arg0->_108.z;
    makeLookAtMatrix(arg0->_000, &arg0->_108, &lbl_1_data_AD18, &arg0->_0FC);
    camera = fn_80052768_getCamera(0);
    memcpy(&camera->eye, &arg0->_108, sizeof(Vec));
    memcpy(&camera->target, &arg0->_0FC, sizeof(Vec));
}

// .text:0x00011D00 size:0x208
void fn_1_11D00(struct Unk67E0* arg0) {
    Mtx rotX;
    Mtx rotY;
    Mtx m;
    Vec rot;
    Vec v = { 0.0f, 0.0f, 100.0f };
    GXColor color = { 0xFF, 0xFF, 0xFF, 0xFF };
    if (!(lbl_803C77B8[0]._00 & 0x10)) {
        arg0->_0F0 -= lbl_803C77B8[0]._13 * 4;
        arg0->_0F2 += lbl_803C77B8[0]._12 * 4;
        arg0->_0F8 += lbl_803C77B8[0]._11 / 256.0f;
        arg0->_0FC.y += lbl_803C77B8[0]._15 / 1024.0f;
        arg0->_0FC.y -= lbl_803C77B8[0]._14 / 1024.0f;
    }
    rot.x = arg0->_0F0;
    rot.y = arg0->_0F2;
    rot.z = 0.0f;
    PSVECScale(&rot, 0.0000958738f, &rot);
    PSMTXRotRad(rotX, 'X', rot.x);
    PSMTXRotRad(rotY, 'Y', rot.y);
    PSMTXConcat(rotX, rotY, m);
    v.z = -arg0->_0F8;
    PSMTXMultVec(m, &v, &v);
    PSVECAdd(&v, &arg0->_0FC, &arg0->_108);
    PSMTXMultVec(m, &lbl_1_data_AD24, &v);
    makeLookAtMatrix(arg0->_000, &arg0->_108, &v, &arg0->_0FC);
}

// .text:0x00011C98 size:0x68
void fn_1_11C98(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        LITXForm(lbl_8036E548._00AC[i], lbl_1_bss_68FC._10);
    }
}

// .text:0x00011714 size:0x584
void fn_1_11714(UnkCamera0610* arg0) {
    Mtx44 proj;
    f32 uv[8][2];
    s32 i;
    u8* face;
    fn_1_17954();
    GXLoadPosMtxImm(arg0->_08, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetColorUpdate(GX_TRUE);
    C_MTXFrustum(proj, -0.000175f, 0.000175f, 0.00025f, -0.00025f, 0.001f, 512.0f);
    fn_800245EC(proj, lbl_1_bss_68FC._10, lbl_1_data_AD30, uv, 8, 1);
    SetDisplayStateTexture(fn_80039AB4(), 0, 0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetNumTevStages(1);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetChanCtrl(GX_COLOR0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_ALPHA0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
    GXBegin(GX_QUADS, GX_VTXFMT0, 24);
    for (i = 0; i < 24; i++) {
        s32 v = lbl_1_data_AD90[i / 4][i % 4];
        GXPosition3f32(lbl_1_data_AD30[v].x, lbl_1_data_AD30[v].y, lbl_1_data_AD30[v].z);
        GXColor1u32(lbl_1_data_ADA8[i / 4]);
        GXTexCoord2f32(uv[v][0], uv[v][1]);
    }
    GXEnd();
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetNumTexGens(0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    for (i = 0; i < 6; i++) {
        face = lbl_1_data_AD90[i];
        GXBegin(GX_LINESTRIP, GX_VTXFMT0, 6);
        GXWGFifo.f32 = lbl_1_data_AD30[face[0]].x;
        GXWGFifo.f32 = lbl_1_data_AD30[face[0]].y;
        GXWGFifo.f32 = lbl_1_data_AD30[face[0]].z;
        GXWGFifo.u32 = 0xFFFFFFFF;
        GXWGFifo.f32 = lbl_1_data_AD30[face[1]].x;
        GXWGFifo.f32 = lbl_1_data_AD30[face[1]].y;
        GXWGFifo.f32 = lbl_1_data_AD30[face[1]].z;
        GXWGFifo.u32 = 0xFFFFFFFF;
        GXWGFifo.f32 = lbl_1_data_AD30[face[2]].x;
        GXWGFifo.f32 = lbl_1_data_AD30[face[2]].y;
        GXWGFifo.f32 = lbl_1_data_AD30[face[2]].z;
        GXWGFifo.u32 = 0xFFFFFFFF;
        GXWGFifo.f32 = lbl_1_data_AD30[face[3]].x;
        GXWGFifo.f32 = lbl_1_data_AD30[face[3]].y;
        GXWGFifo.f32 = lbl_1_data_AD30[face[3]].z;
        GXWGFifo.u32 = 0xFFFFFFFF;
        GXWGFifo.f32 = lbl_1_data_AD30[face[0]].x;
        GXWGFifo.f32 = lbl_1_data_AD30[face[0]].y;
        GXWGFifo.f32 = lbl_1_data_AD30[face[0]].z;
        GXWGFifo.u32 = 0xFFFFFFFF;
        GXWGFifo.f32 = lbl_1_data_AD30[face[2]].x;
        GXWGFifo.f32 = lbl_1_data_AD30[face[2]].y;
        GXWGFifo.f32 = lbl_1_data_AD30[face[2]].z;
        GXWGFifo.u32 = 0xFFFFFFFF;
        GXEnd();
    }
}

// .text:0x000116EC size:0x28
void fn_1_116EC(void* arg0) {
    SetDisplayStateTexture(arg0, 0, 0);
}

// .text:0x0001125C size:0x490
void fn_1_1125C(UnkCamera0610* arg0) {
    s32 i;
    fn_1_17954();
    GXLoadPosMtxImm(arg0->_08, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetColorUpdate(GX_TRUE);
    if (lbl_1_bss_5F62 < 0) {
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
            f32 line = i;
            GXBegin(GX_LINES, GX_VTXFMT0, 4);
            GXPosition3f32(-24.0f, 0.0f, line);
            GXColor4u8(0, 0xFF, 0, 0xC8);
            GXPosition3f32(24.0f, 0.0f, line);
            GXColor4u8(0, 0xFF, 0, 0xC8);
            GXPosition3f32(line, 0.0f, -24.0f);
            GXColor4u8(0, 0xFF, 0, 0xC8);
            GXPosition3f32(line, 0.0f, 24.0f);
            GXColor4u8(0, 0xFF, 0, 0xC8);
            GXEnd();
        }
        return;
    }
    SetDisplayStateTexture(&lbl_1_bss_60E4->_04[lbl_1_bss_5F62], 0, 0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 0);
    GXSetNumTevStages(1);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetChanCtrl(GX_COLOR0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_ALPHA0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(-24.0f, 0.0f, -24.0f);
    GXColor1u32(0xFFFFFFFF);
    GXTexCoord2u16(0, 0);
    GXPosition3f32(-24.0f, 0.0f, 24.0f);
    GXColor1u32(0xFFFFFFFF);
    GXTexCoord2u16(0, lbl_1_bss_5F60);
    GXPosition3f32(24.0f, 0.0f, 24.0f);
    GXColor1u32(0xFFFFFFFF);
    GXTexCoord2u16(lbl_1_bss_5F60, lbl_1_bss_5F60);
    GXPosition3f32(24.0f, 0.0f, -24.0f);
    GXColor1u32(0xFFFFFFFF);
    GXTexCoord2u16(lbl_1_bss_5F60, 0);
    GXEnd();
}

// .text:0x00010E2C size:0x430
// Only the scheduling around the fifteenth vertex's color store differs
void fn_1_10E2C(Mtx arg0, Mtx arg1, u32 color0, u32 color1, u32 color2) {
    GXCullMode cullMode;
    Mtx m;
    GXGetCullMode(&cullMode);
    PSMTXConcat(arg1, arg0, m);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
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
    GXSetCullMode(GX_CULL_NONE);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    GXSetLineWidth(7, GX_TO_ZERO);
    GXBegin(GX_LINES, GX_VTXFMT0, 22);
    GXPosition3f32(-0.01f, 0.0f, 0.0f);
    GXColor1u32(color0);
    GXPosition3f32(0.2f, 0.0f, 0.0f);
    GXColor1u32(color0);
    GXPosition3f32(0.0f, 0.0f, 0.01f);
    GXColor1u32(color0);
    GXPosition3f32(0.2f, 0.0f, 0.0f);
    GXColor1u32(color0);
    GXPosition3f32(0.0f, 0.0f, -0.01f);
    GXColor1u32(color0);
    GXPosition3f32(0.2f, 0.0f, 0.0f);
    GXColor1u32(color0);
    GXPosition3f32(-0.01f, 0.0f, 0.0f);
    GXColor1u32(color0);
    GXPosition3f32(0.0f, 0.0f, 0.01f);
    GXColor1u32(color0);
    GXPosition3f32(-0.01f, 0.0f, 0.0f);
    GXColor1u32(color0);
    GXPosition3f32(0.0f, 0.0f, -0.01f);
    GXColor1u32(color0);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXColor1u32(color1);
    GXPosition3f32(0.0f, 0.05f, 0.0f);
    GXColor1u32(color1);
    GXPosition3f32(-0.005f, 0.0f, 0.0f);
    GXColor1u32(color1);
    GXPosition3f32(0.0f, 0.05f, 0.0f);
    GXColor1u32(color1);
    GXPosition3f32(0.005f, 0.0f, 0.0f);
    GXColor1u32(color1);
    GXPosition3f32(0.0f, 0.05f, 0.0f);
    GXColor1u32(color1);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXColor1u32(color2);
    GXPosition3f32(0.0f, 0.0f, 0.05f);
    GXColor1u32(color2);
    GXPosition3f32(-0.005f, 0.0f, 0.0f);
    GXColor1u32(color2);
    GXPosition3f32(0.0f, 0.0f, 0.05f);
    GXColor1u32(color2);
    GXPosition3f32(0.005f, 0.0f, 0.0f);
    GXColor1u32(color2);
    GXPosition3f32(0.0f, 0.0f, 0.05f);
    GXColor1u32(color2);
    GXEnd();
    GXSetLineWidth(6, GX_TO_ZERO);
    GXSetCullMode(cullMode);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
}

// .text:0x00010CEC size:0x140
void fn_1_10CEC(UnkCamera0610* arg0) {
    Mtx part;
    Mtx m;
    s32 i;
    u32 color0;
    u32 color1;
    u32 color2;
    if (lbl_1_data_ABA8 == 0) {
        PSMTXTrans(m, lbl_8036E548._0C04[lbl_1_bss_5F73]._034, lbl_8036E548._0C04[lbl_1_bss_5F73]._038,
                   lbl_8036E548._0C04[lbl_1_bss_5F73]._03C);
        PSMTXConcat(arg0->_08, m, m);
        for (i = 0; i < lbl_8036E548._0060->_34[lbl_1_bss_5F73]._00->_06; i++) {
            if (i != lbl_1_bss_5F6C) {
                color0 = 0x80008080;
                color1 = 0x80800080;
                color2 = 0x00808080;
            } else if (lbl_1_bss_3090++ & 0x20) {
                color0 = 0xFF8080FF;
                color1 = 0x80FF80FF;
                color2 = 0x8080FFFF;
            } else {
                color0 = 0xFFFFFFFF;
                color1 = 0xFFFFFFFF;
                color2 = 0xFFFFFFFF;
            }
            fn_800B2C88(lbl_8036E548._0060->_34[lbl_1_bss_5F73]._00, i, part);
            fn_1_10E2C(part, m, color0, color1, color2);
        }
    }
}

// .text:0x00010ACC size:0x220
void fn_1_10ACC(Mtx m, Vec* pos, void* arg2, GXColor* color, f32 length) {
    GXCullMode cullMode;
    GXGetCullMode(&cullMode);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
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
    GXSetCullMode(GX_CULL_NONE);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    GXSetLineWidth(10, GX_TO_ZERO);
    GXBegin(GX_LINES, GX_VTXFMT0, 2);
    GXPosition3f32(pos->x, pos->y, pos->z);
    GXColor4u8(color->r, color->g, color->b, color->a);
    GXPosition3f32(pos->x + length, pos->y + length, pos->z + length);
    GXColor4u8(color->r, color->g, color->b, color->a);
    GXEnd();
    GXSetLineWidth(6, GX_TO_ZERO);
    GXSetCullMode(cullMode);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
}

// .text:0x00010AA4 size:0x28
void fn_1_10AA4(Unk10AA4* arg0, f32 arg1) {
    arg0->_54 = arg1;
    arg0->_5A = 1;
    if (lbl_1_bss_67B8[0] != NULL) {
        lbl_1_bss_67B8[0]->_04 = arg1;
    }
}

// .text:0x000107B8 size:0x2EC
// Inlines fn_1_D300 and inherits its difference; registers differ at the top
void fn_1_107B8(void) {
    u8 slot = lbl_1_bss_6940[lbl_1_bss_5F73]._44;
    u8 anim;
    UnkAnimRef0610* ref;
    Unk0060Elem* elem;
    lbl_8036E548._0C04[lbl_1_bss_5F73]._278 = slot == 0;
    switch (slot) {
    case 0:
        lbl_8036E548._0C04[lbl_1_bss_5F73]._254 = 9;
        break;
    case 1:
        lbl_8036E548._0C04[lbl_1_bss_5F73]._254 = 10;
        break;
    case 2:
        lbl_8036E548._0C04[lbl_1_bss_5F73]._254 = 2;
        break;
    case 3:
        lbl_8036E548._0C04[lbl_1_bss_5F73]._254 = 0;
        break;
    case 4:
        lbl_8036E548._0C04[lbl_1_bss_5F73]._254 = 1;
        break;
    default:
        lbl_8036E548._0C04[lbl_1_bss_5F73]._254 = 9;
        break;
    }
    anim = lbl_1_bss_6940[lbl_1_bss_5F73]._45;
    lbl_8036E548._0C04[lbl_1_bss_5F73]._062 = lbl_1_data_A938[slot] + anim;
    ref = lbl_8036E548._0C04[lbl_1_bss_5F73]._010[slot];
    elem = &lbl_8036E548._0060->_34[lbl_1_bss_5F73];
    elem->_04 = ref;
    elem->_0E = anim;
    elem->_5C = 0.0f;
    elem->_58 = 1;
    elem->_59 = ref != NULL;
    elem->_5A = ref != NULL;
    elem->_60 = 0.0f;
    fn_1_ECF8(lbl_1_bss_5F73, lbl_1_bss_6940[lbl_1_bss_5F73]._44, lbl_1_bss_5F69);
    lbl_1_bss_5F5C = 0;
    fn_1_D300(&lbl_8036E548._0C04[lbl_1_bss_5F73]);
    fn_800B0A14_removeQueue();
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
void* fn_1_106A4(void) {
    return lbl_1_bss_3098[0];
}

// .text:0x00010670 size:0x34
void fn_1_10670(void) {
    UnkTask0610* task = fn_800B0A5C_insertQueue(fn_1_10560, 11);
    task->_10 = 0;
}

// .text:0x00010560 size:0x110
void fn_1_10560(void) {
    switch (lbl_803CC1B8->_10) {
    case 0:
        lbl_1_bss_3094 = ARAMTransfer(lbl_1_data_ADE0, 0, 0, 0);
        lbl_803CC1B8->_10 = 1;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            lbl_1_bss_3098[0] = (u8*)lbl_1_bss_3094 + *(u32*)lbl_1_bss_3094;
            convertTextureHeader(lbl_1_bss_3098[0]);
            lbl_1_bss_60E4 = ARAMTransfer(lbl_1_data_A940, 0, 1, 0);
            lbl_803CC1B8->_10 = 2;
        }
        break;
    case 2:
        if (lbl_803C6CF8._715 == 1) {
            convertTextureHeader(lbl_1_bss_60E4);
            fn_800B0A14_removeQueue();
        }
        break;
    }
}

// .text:0x00010458 size:0x108
void fn_1_10458(void) {
    if (lbl_1_bss_3098[0] == 0) {
        if (lbl_1_bss_3094 == 0) {
            fn_1_10670();
        }
    } else {
        u16 buttons = lbl_803C77B8[0]._04;
        if (buttons & 8) {
            if (lbl_1_bss_307C != 0) {
                lbl_1_bss_307C--;
            } else {
                lbl_1_bss_307C = 6;
            }
        } else if (buttons & 4) {
            if (++lbl_1_bss_307C == 7) {
                lbl_1_bss_307C = 0;
            }
        } else if (buttons & 1) {
        } else if (buttons & 2) {
        } else if (buttons & 0x100) {
            lbl_1_bss_5F71 += lbl_1_bss_307C + 1;
            lbl_1_bss_307C = 0;
        } else if (buttons & 0x200) {
            lbl_1_bss_307C = 0;
            lbl_1_bss_5F71 = 1;
        }
    }
}

// .text:0x0000F798 size:0x400
void fn_1_F798(UnkBurst0610* arg0, u8* ids, s32 count) {
    s32* params = (s32*)arg0;
    s32 step;
    s32 big;
    s32 huge;
    s32 v;
    if (lbl_803C77B8[0]._00 & 0x400) {
        step = 10;
        big = 100;
        huge = 10000;
    } else if (lbl_803C77B8[0]._00 & 0x800) {
        step = 20;
        huge = 1000000;
        big = 10000;
    } else {
        step = 1;
        huge = 100000;
        big = 1000;
    }
    if (lbl_803C77B8[0]._04 & 8) {
        if (lbl_1_bss_307C != 0) {
            lbl_1_bss_307C--;
        } else {
            lbl_1_bss_307C = count - 1;
        }
    } else if (lbl_803C77B8[0]._04 & 4) {
        if (++lbl_1_bss_307C == count) {
            lbl_1_bss_307C = 0;
        }
    } else if (lbl_803C77B8[0]._04 & 1) {
        switch (ids[lbl_1_bss_307C]) {
        case 1:
            params[ids[lbl_1_bss_307C]] = (params[ids[lbl_1_bss_307C]] + 41) % 42;
            break;
        case 2:
            params[2] -= step;
            if (params[2] < 1) {
                params[2] = 1;
            }
            break;
        case 3:
        case 4:
        case 5:
        case 8:
        case 9:
        case 20:
            if (params[ids[lbl_1_bss_307C]] - big > 0) {
                params[ids[lbl_1_bss_307C]] -= big;
            }
            break;
        case 6:
            params[6] -= step;
            if (params[6] < 1) {
                params[6] = 1;
                if (params[7] > params[6]) {
                    params[7] = params[6];
                }
            }
            break;
        case 7:
        case 11:
        case 21:
        case 22:
            params[ids[lbl_1_bss_307C]] -= step;
            if (params[ids[lbl_1_bss_307C]] < 0) {
                params[ids[lbl_1_bss_307C]] = 0;
            }
            break;
        case 10:
            params[ids[lbl_1_bss_307C]] ^= 1;
            break;
        case 12:
        case 13:
            params[ids[lbl_1_bss_307C]] -= huge;
            if (params[ids[lbl_1_bss_307C]] < 0) {
                params[ids[lbl_1_bss_307C]] = 0;
            }
            break;
        case 23:
        case 24:
            params[ids[lbl_1_bss_307C]] -= big;
            break;
        case 14:
        case 15:
            params[ids[lbl_1_bss_307C]] -= huge;
        case 16:
            v = (params[16] >> 8) & 0xFF;
            v -= step;
            if (v < 0) {
                v = 0;
            }
            params[16] = v * 0x01010100;
            break;
        }
    } else if (lbl_803C77B8[0]._04 & 2) {
        switch (ids[lbl_1_bss_307C]) {
        case 1:
            params[ids[lbl_1_bss_307C]] = (params[ids[lbl_1_bss_307C]] + 1) % 42;
            break;
        case 2:
            params[2] += step;
            break;
        case 3:
        case 4:
        case 5:
        case 8:
        case 9:
        case 20:
            params[ids[lbl_1_bss_307C]] += big;
            break;
        case 6:
            params[6] += step;
            break;
        case 7:
            params[7] += step;
            if (params[7] > params[6]) {
                params[7] = params[6];
            }
            break;
        case 11:
        case 21:
            params[ids[lbl_1_bss_307C]] += step;
            if (params[ids[lbl_1_bss_307C]] > 255) {
                params[ids[lbl_1_bss_307C]] = 255;
            }
            break;
        case 22:
            params[ids[lbl_1_bss_307C]] += step;
            break;
        case 10:
            params[ids[lbl_1_bss_307C]] ^= 1;
            break;
        case 12:
        case 13:
            params[ids[lbl_1_bss_307C]] += huge;
            break;
        case 23:
        case 24:
            params[ids[lbl_1_bss_307C]] += big;
            break;
        case 14:
        case 15:
            params[ids[lbl_1_bss_307C]] += huge;
            break;
        case 16:
            v = (params[16] >> 8) & 0xFF;
            v += step;
            if (v > 255) {
                v = 255;
            }
            params[16] = v * 0x01010100;
            break;
        }
    }
}

// .text:0x0000F6E4 size:0xB4
void fn_1_F6E4(void) {
    UnkBurst0610* burst = &lbl_1_data_F0BC;
    Vec pos = { 0.0f, 0.0f, 10.0f };
    fn_1_F798(burst, lbl_1_data_F0A8, 12);
    if (lbl_803C77B8[0]._04 & 0x100) {
        burst->_00 = lbl_1_bss_3098[0];
        fn_80031CA4(&pos, burst);
    } else if (lbl_803C77B8[0]._04 & 0x200) {
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 10;
    }
}

// .text:0x0000F50C size:0x1D8
void fn_1_F50C(void) {
    UnkTaskF50C* task = (UnkTaskF50C*)lbl_803CC1B8;
    Unk8036E548Actor* actor = &lbl_8036E548._0C04[lbl_1_bss_5F73];
    VecXYZ pos;
    if (actor != NULL) {
        actor->_034 = task->_14.x;
        actor->_038 = task->_14.y;
        actor->_03C = task->_14.z;
    }
    fn_80030D88(&task->_14, &task->_20, (UnkBurst0610*)&lbl_1_data_F10C, 5);
    if (task->_3E != 0) {
        task->_3E = 0;
        if (task->_3F != 0) {
            getAnimRelatedCoordinates(0, 0x1E, &pos);
            pos.y = 0.0f;
            fn_8002F258((Vec*)&pos, task->_38, lbl_1_data_F174[0]);
            getAnimRelatedCoordinates(0, 0x22, &pos);
            pos.y = 0.0f;
            fn_8002F258((Vec*)&pos, task->_38 + 1, lbl_1_data_F174[0]);
        } else {
            fn_8002F258(&task->_14, task->_38, lbl_1_data_F174[0]);
        }
    } else if (task->_3F != 0) {
        getAnimRelatedCoordinates(0, 0x1E, &pos);
        pos.y = 0.0f;
        fn_8002F1AC((Vec*)&pos, task->_38);
        getAnimRelatedCoordinates(0, 0x22, &pos);
        pos.y = 0.0f;
        fn_8002F1AC((Vec*)&pos, task->_38 + 1);
    } else {
        fn_8002F1AC(&task->_14, task->_38);
    }
    PSVECAdd(&task->_20, &task->_2C, &task->_20);
    PSVECAdd(&task->_20, &task->_14, &task->_14);
    task->_3C--;
    if (task->_3C == 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0000F37C size:0x190
// The target computes lbl_1_data_F10C's address before the 10.0f and creates the
// int-to-float constant before 10.0f and 100000.0f; only scheduling differs
void fn_1_F37C(void) {
    fn_1_F798((UnkBurst0610*)&lbl_1_data_F10C, lbl_1_data_F0A8, 18);
    if (lbl_803C77B8[0]._04 & 0x1100) {
        UnkTaskF50C* task;
        lbl_1_data_F10C._00 = lbl_1_bss_3098[0];
        lbl_1_data_F174[0]->_0 = lbl_1_bss_3098[0];
        lbl_1_data_F174[0]->_4 = 5;
        task = (UnkTaskF50C*)fn_800B0A5C_insertQueue(fn_1_F50C, lbl_803CC1B8->_12 + 1);
        task->_14.y = 0.0f;
        task->_14.x = 0.0f;
        task->_14.z = 10.0f;
        task->_20.x = 0.0f;
        task->_20.y = 0.0f;
        task->_20.z = lbl_1_data_F10C._5C / 100000.0f;
        task->_2C.x = 0.0f;
        task->_2C.y = 0.0f;
        task->_2C.z = lbl_1_data_F10C._60 / 100000.0f;
        task->_3C = 0x20;
        task->_3E = 1;
        task->_38 = lbl_1_bss_30A4;
        lbl_1_bss_30A4 += 2;
        task->_3F = (lbl_803C77B8[0]._04 >> 12) & 1;
    } else if (lbl_803C77B8[0]._04 & 0x200) {
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 10;
    }
}

// .text:0x0000F2F8 size:0x84
void fn_1_F2F8(void) {
    if (lbl_803C77B8[0]._04 & 0x100) {
        lbl_80108B90._00 = lbl_1_bss_3098[0];
        fn_800324EC(lbl_1_data_F17C, 0, -1, &lbl_80108B90);
    } else if (lbl_803C77B8[0]._04 & 0x200) {
        lbl_80108B90._00 = NULL;
        lbl_1_bss_307C = 0;
        lbl_1_bss_5F71 = 10;
    }
}

// .text:0x0000F1D8 size:0x120
void fn_1_F1D8(void) {
    UnkTask0610* task = lbl_803CC1B8;
    Unk8036E548Actor* actor = lbl_8036E548._2C50[lbl_1_bss_5F73];
    VecXYZ pos;
    Mtx m;
    Control ctrl;
    Vec dir;
    getAnimRelatedCoordinates(0, task->_24, &pos);
    ctrl.type = 0;
    CTRLSetRotation(&ctrl, actor->_040, actor->_044, actor->_048);
    CTRLBuildMatrix(&ctrl, m);
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 1.0f;
    PSMTXMultVec(m, &dir, &dir);
    fn_80030D88((Vec*)&pos, &dir, lbl_1_data_F278[0], 5);
    fn_80030D88((Vec*)&pos, &dir, lbl_1_data_F278[1], 5);
    fn_80030D88((Vec*)&pos, &dir, lbl_1_data_F278[2], 5);
    if (--task->_20 == 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0000F0D0 size:0x108
void fn_1_F0D0(void) {
    fn_1_F798(lbl_1_data_F278[lbl_1_bss_30A8], lbl_1_data_F284, 16);
    if (lbl_803C77B8[0]._04 & 0x1000) {
        lbl_1_bss_30A8 = (lbl_1_bss_30A8 + 1) % 3;
    } else if (lbl_803C77B8[0]._00 & 0x100) {
        if (lbl_803C77B8[0]._02 & 0x100) {
            UnkTask0610* task;
            lbl_1_data_F278[0]->_00 = lbl_1_data_F278[1]->_00 = lbl_1_data_F278[2]->_00 = lbl_1_bss_3098[0];
            task = fn_800B0A5C_insertQueue(fn_1_F1D8, 0);
            task->_20 = 0xF0;
            task->_24 = 4;
        }
    } else if (lbl_803C77B8[0]._04 & 0x200) {
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

// .text:0x0000ECF8 size:0x348
// Inlines fn_1_D300 (see there); registers and the search loops' scheduling
// differ
void fn_1_ECF8(s32 idx, s32 slot, s32 flag) {
    u16 idA;
    u16 idB;
    s32 first;
    s32 second;
    s32 i;
    if (lbl_1_bss_60A4[lbl_1_bss_68FC._40[idx]] == 0) {
        return;
    }
    idA = lbl_8036E548._0C04[idx]._162[0x13];
    idB = lbl_8036E548._0C04[idx]._162[0x19];
    switch (slot) {
    case 0:
    case 1:
    case 5:
    case 6:
        first = 1;
        second = 2;
        break;
    default:
        if (flag != 0) {
            first = 1;
            second = 4;
        } else {
            first = 3;
            second = 2;
        }
        break;
    }
    for (i = 0; i < lbl_1_bss_5F7C[0]->_34[first - 1]._00->_06; i++) {
        if (lbl_1_bss_5F7C[0]->_34[first - 1]._00->_18[i]->_14 != NULL) {
            fn_800B2BA8(lbl_8036E548._0060->_34[idx]._00, idA, lbl_1_bss_5F7C[0]->_34[first - 1]._00, i);
            break;
        }
    }
    for (i = 0; i < lbl_1_bss_5F7C[0]->_34[second - 1]._00->_06; i++) {
        if (lbl_1_bss_5F7C[0]->_34[second - 1]._00->_18[i]->_14 != NULL) {
            fn_800B2BA8(lbl_8036E548._0060->_34[idx]._00, idB, lbl_1_bss_5F7C[0]->_34[second - 1]._00, i);
            break;
        }
    }
    fn_1_D300(&lbl_8036E548._0C04[lbl_1_bss_5F73]);
}

// .text:0x0000EA20 size:0x2D8
// Case 0's loop differs: the target tests the count through a value loaded
// before the loop but reloads the animation pointer in the body; 86%
void fn_1_EA20(void) {
    switch (lbl_1_bss_30B0) {
    case 0: {
        Unk0060Elem* elem = &lbl_8036E548._0060->_34[lbl_1_bss_5F73];
        s32 i;
        UnkAnimRef0610* ref;
        s32 anim;
        lbl_1_bss_5F68 = 1;
        lbl_1_bss_5F64 = 0.0f;
        elem->_5C = 0.0f;
        elem->_59 = 1;
        lbl_1_bss_30B0 = 1;
        lbl_1_bss_5F58 = 0;
        ref = lbl_8036E548._0C04[lbl_1_bss_5F73]._010[lbl_1_bss_6940[lbl_1_bss_5F73]._44];
        anim = lbl_1_bss_6940[lbl_1_bss_5F73]._45;
        for (i = 0; i < ref->_4[anim]._8; i++) {
            if (lbl_1_bss_5F58 < ref->_4[anim]._4[i]._0) {
                lbl_1_bss_5F58 = ref->_4[anim]._4[i]._0;
            }
        }
        break;
    }
    case 1:
        if (lbl_803C77B8[0]._02 & 0x200) {
            lbl_1_bss_30B0 = 0;
            lbl_1_bss_5F71 = 1;
        } else if (lbl_803C77B8[0]._04 & 1) {
            if (--lbl_1_bss_30B4 < 0) {
                lbl_1_bss_30B4 = lbl_1_bss_5F58 - 2;
            }
        } else if (lbl_803C77B8[0]._04 & 2) {
            if (++lbl_1_bss_30B4 > lbl_1_bss_5F58 - 2) {
                lbl_1_bss_30B4 = 0;
            }
        } else if (lbl_803C77B8[0]._04 & 0x100) {
            lbl_1_bss_5F68 = 0;
            fn_80039A4C();
            lbl_8036E548._3084 = lbl_1_bss_5F73;
            lbl_1_bss_30B0 = 2;
            lbl_8036E548._2C50[lbl_1_bss_5F73] = &lbl_8036E548._0C04[lbl_1_bss_5F73];
        }
        break;
    default:
        if (lbl_1_bss_30B0 - 2 == lbl_1_bss_30B4 * 2) {
            lbl_8036E548._3083 = 1;
        }
        lbl_1_bss_30B0++;
        if (lbl_803C77B8[0]._02 & 0x200) {
            lbl_1_bss_30B0 = 0;
            lbl_8036E548._3083 = 0;
        } else if (lbl_803C77B8[0]._02 & 0x100) {
            Unk0060Elem* elem = &lbl_8036E548._0060->_34[lbl_1_bss_5F73];
            elem->_5C = 0.0f;
            elem->_59 = 1;
            fn_80039A4C();
            lbl_8036E548._3084 = lbl_1_bss_5F73;
            lbl_1_bss_30B0 = 2;
            lbl_8036E548._2C50[lbl_1_bss_5F73] = &lbl_8036E548._0C04[lbl_1_bss_5F73];
        }
        break;
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

// .text:0x0000E8D4 size:0x124
void fn_1_E8D4(void) {
    fn_1_D7A4(0);
    while (lbl_1_data_F4D4._4[lbl_1_data_F4D4._0]._00 != 0) {
        lbl_1_data_F4D4._0++;
    }
}

// .text:0x0000DF14 size:0x184
void fn_1_DF14(void) {
    UnkTaskState0610* task = (UnkTaskState0610*)lbl_803CC1B8;
    s32 slot = task->_14;
    s32 i;
    switch (task->_10) {
    case 0:
        lbl_1_bss_6940[lbl_1_bss_5F73]._44 = lbl_1_bss_3218[slot]._0;
        lbl_1_bss_6940[lbl_1_bss_5F73]._45 = lbl_1_bss_3218[slot]._2;
        fn_800B0A5C_insertQueue(fn_1_107B8, 0xFF);
        lbl_1_bss_5F5C = 2;
        lbl_803CC1B8->_10++;
        break;
    case 1:
        if (lbl_1_bss_5F5C == 0) {
            i = 5;
            while (i--) {
                if (lbl_1_bss_67B8[i] != NULL) {
                    memcpy(&lbl_1_bss_3258[slot][i], lbl_1_bss_67B8[i], 0x20);
                    lbl_1_bss_3258[slot][i]._1C = lbl_1_bss_3758[slot][i];
                    memcpy(lbl_1_bss_3758[slot][i], lbl_1_bss_67B8[i]->_1C, lbl_1_bss_67B8[i]->_1A * 4);
                } else {
                    memset(&lbl_1_bss_3258[slot][i], 0, 0x20);
                }
            }
            lbl_803CC1B8->_0C->_10 = 1;
            fn_800B0A14_removeQueue();
        }
        break;
    }
}

// .text:0x0000DE1C size:0xF8
// fn_1_D8A0 is inlined here, where the target calls it; it stays a call only
// with about 21 more statements in fn_1_D8A0 (measured with dummy stores)
void fn_1_DE1C(void) {
    UnkTaskState0610* task = (UnkTaskState0610*)lbl_803CC1B8;
    switch (task->_14) {
    case 0:
        if (task->_15 == 0) {
            task->_00 = fn_1_D9B8;
        } else {
            while (task->_15-- != 0) {
                if (lbl_1_bss_3218[task->_15]._0 >= 0) {
                    UnkTaskState0610* sub = (UnkTaskState0610*)fn_800B0A5C_insertQueue(fn_1_DF14, lbl_803CC1B8->_12 + 1);
                    sub->_10 = 0;
                    sub->_14 = task->_15;
                    task->_10 = 0;
                    task->_14++;
                    break;
                }
            }
        }
        break;
    case 1:
        if (task->_10 != 0) {
            task->_14 = 0;
        }
        break;
    }
    fn_1_D8A0();
}

// .text:0x0000D8A0 size:0x118
void fn_1_D8A0(void) {
    fn_1_17954();
    fn_1_179CC();
    PSMTXCopy(lbl_1_bss_67E0._000, lbl_1_bss_68FC._10);
    fn_800A7D4C(7, &lbl_1_data_AA54[lbl_803CBBC0]);
    if (lbl_1_bss_3078 != 0) {
        fn_800A7D4C(7, &lbl_1_data_AB34[lbl_803CBBC0]);
    }
    fn_800A7D4C(7, &lbl_1_data_AAC4[lbl_803CBBC0]);
    fn_1_129D0();
}

// .text:0x0000D7A4 size:0xFC
void fn_1_D7A4(s32 arg0) {
    UnkSlotSet0610* set = &lbl_1_data_F4D4._4[arg0];
    s32 i = 8;
    while (i--) {
        if (set->_10[i]._0 != 0) {
            s16 id;
            s16 frame;
            UnkAnimRef0610* ref;
            lbl_1_bss_3218[i]._0 = id = set->_10[i]._2;
            ref = lbl_8036E548._0C04[lbl_1_bss_5F73]._010[id];
            lbl_1_bss_3218[i]._2 = frame = set->_10[i]._4;
            lbl_1_bss_3218[i]._6 = set->_10[i]._1;
            if (set->_10[i]._6 == -2) {
                if (ref != NULL) {
                    lbl_1_bss_3218[i]._4 = ref->_4[frame]._4->_0;
                } else {
                    lbl_1_bss_3218[i]._4 = 0;
                }
            } else {
                lbl_1_bss_3218[i]._4 = set->_10[i]._6;
            }
        } else {
            lbl_1_bss_3218[i]._0 = -1;
            lbl_1_bss_3218[i]._6 = 0;
            lbl_1_bss_3218[i]._4 = 0;
        }
    }
}

// .text:0x0000D71C size:0x88
f32 fn_1_D71C(s32 arg0) {
    s32 i;
    UnkList0610* list = lbl_8036E548._0060->_34[arg0]._00;
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

// .text:0x0000D590 size:0xA8
void fn_1_D590(s32 arg0, s32 arg1, f32 arg2) {
    if (lbl_1_bss_3215 == 0 || lbl_1_bss_3216 == 0) {
        return;
    }
    if (lbl_1_bss_3216 == 2) {
        if ((s32)arg2 == 0) {
            lbl_1_bss_3214 += (lbl_1_bss_3214 != 0);
        }
        if (lbl_1_bss_3214 == 3) {
            lbl_1_bss_3214 = 0;
        }
        if (lbl_1_bss_3214 != 2) {
            return;
        }
    }
    fn_8004B208(arg0, arg1, lbl_1_bss_5F62 < 0 ? 0 : lbl_1_bss_5F62);
}

// .text:0x0000D4BC size:0xD4
void fn_1_D4BC(void) {
    VecXYZ pos;
    Unk8036E548* g = &lbl_8036E548;
    Unk8036E548Actor* actor = &g->_0C04[0];
    if (actor != NULL) {
        actor->_276 >>= 1;
        actor->_276 <<= 3;
        getAnimRelatedCoordinates(0, 0x1E, &pos);
        if (actor->_038 - pos.y < 0.3f) {
            actor->_276 |= 2;
        }
        getAnimRelatedCoordinates(0, 0x22, &pos);
        if (actor->_038 - pos.y < 0.3f) {
            actor->_276 |= 4;
        }
    }
    g->_2C50[0]->_276 |= 1;
}

// .text:0x0000D300 size:0x1BC
// Only the epilogue differs: the target restores r0 before r28-r31
void fn_1_D300(Unk8036E548Actor* arg0) {
    s32 first;
    s32 second;
    switch (lbl_1_bss_6940[lbl_1_bss_5F73]._44) {
    case 0:
    case 1:
        first = 1;
        second = 2;
        break;
    case 2:
    case 3:
    case 4:
    default:
        if (lbl_1_bss_5F69 != 0) {
            first = 1;
            second = 4;
        } else {
            first = 3;
            second = 2;
        }
        break;
    }
    lbl_8036E548._2C50[lbl_1_bss_5F73]->_030 = &lbl_8036E548._0140[lbl_1_bss_5F73];
    memcpy(&lbl_8036E548._2C50[lbl_1_bss_5F73]->_030->_04, &lbl_1_bss_60EC[first], sizeof(UnkPoseBlock0610));
    memcpy(&lbl_8036E548._2C50[lbl_1_bss_5F73]->_030->_68, &lbl_1_bss_60EC[second], sizeof(UnkPoseBlock0610));
    lbl_8036E548._2C50[lbl_1_bss_5F73]->_030->_60 = lbl_1_bss_5F73;
    lbl_8036E548._2C50[lbl_1_bss_5F73]->_030->_C4 = lbl_1_bss_5F73;
    lbl_8036E548._2C50[lbl_1_bss_5F73]->_030->_CD = arg0->_25A;
    lbl_8036E548._2C50[lbl_1_bss_5F73]->_030->_CE = arg0->_25B;
    lbl_8036E548._2C50[lbl_1_bss_5F73]->_030->_CF = lbl_1_bss_5F73;
    lbl_8036E548._2C50[lbl_1_bss_5F73]->_030->_D0 = lbl_1_bss_5F73;
    lbl_8036E548._2C50[lbl_1_bss_5F73]->_000 = lbl_8036E548._0060->_34[lbl_1_bss_5F73]._00;
}

// .text:0x0000D2F0 size:0x10
void fn_1_D2F0(void) {
    lbl_1_bss_30B8 = 1;
}

// .text:0x0000D13C size:0x1B4
void fn_1_D13C(void) {
    u16 ids[2];
    s32 kind;
    s32 i;
    Unk8036E548Actor* actor = &lbl_8036E548._0C04[lbl_1_bss_5F73];
    lbl_1_bss_60E8 = fn_800B0A5C_insertQueue(fn_1_CDC8, lbl_803CC1B8->_12 + 1);
    lbl_1_bss_60E8->_10 = lbl_1_bss_6940[lbl_1_bss_5F73]._44;
    switch (lbl_1_bss_68FC._40[lbl_1_bss_5F73]) {
    case 0x27:
        break;
    case 0x26:
        kind = 0;
        break;
    case 0x12:
        kind = 3;
        break;
    case 0x28:
        kind = 1;
        break;
    case 0x29:
        kind = 2;
        break;
    }
    actor->_25A = (lbl_1_bss_6940[lbl_1_bss_5F73]._44 < 2) == (lbl_1_bss_5F69 == 0);
    ids[actor->_25A] = lbl_8036E548._0C04[lbl_1_bss_5F73]._162[lbl_1_data_F4E8[kind]._0];
    ids[!actor->_25A] = lbl_8036E548._0C04[lbl_1_bss_5F73]._162[lbl_1_data_F4E8[kind]._2];
    for (i = 0; i < 2; i++) {
        fn_800B2B74(lbl_8036E548._0060->_34[lbl_1_bss_5F73]._00, ids[i]);
    }
}

// .text:0x0000CCC8 size:0x100
void fn_1_CCC8(void) {
    UnkTask0610* task = lbl_803CC1B8;
    if (task->_14 != NULL && task->_14->_00 < task->_14->_04) {
        if (lbl_1_bss_5F69 != 0) {
            fn_800385F0(&lbl_1_bss_30C0, 1.0f, 0.5f, 0.1f, 1.0f);
        } else {
            fn_800385F0(&lbl_1_bss_30C0, -1.0f, 0.5f, 0.1f, 1.0f);
        }
        lbl_1_bss_30C0._050 = lbl_1_data_F568;
        fn_80037AA0(&lbl_1_bss_30C0, 0, fn_1_CB9C, task->_18, task->_14);
        fn_800B0A14_removeQueue();
    }
}

// .text:0x0000CC24 size:0xA4
void fn_1_CC24(void) {
    UnkTask0610* task;
    if (lbl_1_bss_30BC == 0) {
        lbl_1_bss_30BC = 1;
        task = fn_800B0A5C_insertQueue(fn_1_CCC8, lbl_803CC1B8->_12 + 1);
        if (lbl_1_bss_5F69 != 0) {
            task->_14 = lbl_1_bss_67B8[1];
            task->_18 = lbl_1_data_F56C;
        } else {
            task->_14 = lbl_1_bss_67B8[2];
            task->_18 = lbl_1_data_F56E;
        }
    }
}

// .text:0x0000CB9C size:0x88
// Only the first PSMTXCopy's address registers differ (r3/r4/r5 rotated);
// local pointers, index casts and the permuter did not fix it
void fn_1_CB9C(s32 arg0) {
    if (arg0 != 0) {
        lbl_1_bss_30BC = 0;
    } else {
        PSMTXCopy(lbl_1_data_F4F8[lbl_803CBBC0]._08, lbl_1_bss_30C0._058);
        fn_800A7D4C(8, &lbl_1_data_F4F8[lbl_803CBBC0]);
    }
}

// .text:0x0000C9E0 size:0x1BC
void fn_1_C9E0(UnkCamera0610* arg0) {
    Mtx m;
    Vec v;
    fn_1_F2C(4, 0, 0);
    PSMTXConcat(lbl_1_bss_68FC._10, arg0->_08, m);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    GXBegin(GX_LINES, GX_VTXFMT0, 6);
    GXPosition3f32(lbl_1_bss_30C0._00C.x, lbl_1_bss_30C0._00C.y, lbl_1_bss_30C0._00C.z);
    GXColor1u32(0xFF0000FF);
    GXPosition3f32(lbl_1_bss_30C0._000.x, lbl_1_bss_30C0._000.y, lbl_1_bss_30C0._000.z);
    GXColor1u32(0x00FF00FF);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXColor1u32(0x000000FF);
    PSVECScale(&lbl_1_bss_30C0._128, lbl_1_data_F570[0], &v);
    GXPosition3f32(v.x, v.y, v.z);
    GXColor1u32(0x000000FF);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXColor1u32(0xFFFFFFFF);
    PSVECScale(&lbl_1_bss_30C0._140, lbl_1_data_F570[0], &v);
    GXPosition3f32(v.x, v.y, v.z);
    GXColor1u32(0xFFFFFFFF);
    GXEnd();
}

// .text:0x0000C5A8 size:0x4
void fn_1_C5A8(void) {}
