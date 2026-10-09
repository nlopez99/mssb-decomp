#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_0568.h"
#include "menus/rep_11C0.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "musyx/musyx.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "string.h"

typedef struct Node0568 {
    /* 0x000 */ u16 _000;
    /* 0x002 */ u8 _002[0x136 - 0x2];
    /* 0x136 */ u8 _136;
} Node0568;

typedef struct Actor0568 {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x18 - 0x8];
    /* 0x18 */ Node0568** _18;
    /* 0x1C */ u8 _1C[0x98 - 0x1C];
    /* 0x98 */ u8 _98;
} Actor0568;

// One animated model of the list at lbl_8036E548._0060
typedef struct ActorRef0568 {
    /* 0x00 */ Actor0568* _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ void (*_08)(struct Obj0568* obj);
    /* 0x0C */ u8 _0C[0xE - 0xC];
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
} ActorRef0568; // size: 0x90

typedef struct ModelList0568 {
    /* 0x00 */ u16 _00;
    /* 0x02 */ u8 _02[0x34 - 0x2];
    /* 0x34 */ ActorRef0568 _34[1];
} ModelList0568;

typedef struct PoseBlock0568 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ f32 _10;
    /* 0x14 */ u8 _14[0x5C - 0x14];
} PoseBlock0568; // size: 0x5C

// One pose block per player in lbl_8036E548
typedef struct Pose0568 {
    /* 0x00 */ u8* _00;
    /* 0x04 */ PoseBlock0568 _04;
    /* 0x60 */ s8 _60;
    /* 0x61 */ u8 _61[0x64 - 0x61];
    /* 0x64 */ u8* _64;
    /* 0x68 */ PoseBlock0568 _68;
    /* 0xC4 */ s8 _C4;
    /* 0xC5 */ u8 _C5[0xC8 - 0xC5];
    /* 0xC8 */ s32 _C8;
    /* 0xCC */ u8 _CC;
    /* 0xCD */ u8 _CD;
    /* 0xCE */ u8 _CE;
    /* 0xCF */ s8 _CF;
    /* 0xD0 */ s8 _D0;
    /* 0xD1 */ s8 _D1;
    /* 0xD2 */ u8 _D2[0xD4 - 0xD2];
} Pose0568; // size: 0xD4

typedef struct AnimBank0568 {
    /* 0x00 */ u8 _00[0xA];
    /* 0x0A */ u16 _0A;
} AnimBank0568;

// A player record in lbl_8036E548
typedef struct Player0568 {
    /* 0x000 */ Actor0568* _000;
    /* 0x004 */ u8 _004[0x8 - 0x4];
    /* 0x008 */ u32* _008;
    /* 0x00C */ u8 _00C[0x10 - 0xC];
    /* 0x010 */ AnimBank0568* _010[7];
    /* 0x02C */ u8* _02C;
    /* 0x030 */ Pose0568* _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ f32 _040;
    /* 0x044 */ f32 _044;
    /* 0x048 */ f32 _048;
    /* 0x04C */ f32 _04C;
    /* 0x050 */ u8 _050[0x62 - 0x50];
    /* 0x062 */ s16 _062;
    /* 0x064 */ u8 _064[0x68 - 0x64];
    /* 0x068 */ s16 _068;
    /* 0x06A */ u8 _06A[0x162 - 0x6A];
    /* 0x162 */ u16 _162[50];
    /* 0x1C6 */ u8 _1C6[0x252 - 0x1C6];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ u8 _254;
    /* 0x255 */ s8 _255;
    /* 0x256 */ u8 _256[0x25C - 0x256];
    /* 0x25C */ u8 _25C;
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E[0x265 - 0x25E];
    /* 0x265 */ u8 _265;
    /* 0x266 */ u8 _266[0x268 - 0x266];
    /* 0x268 */ s8 _268;
    /* 0x269 */ u8 _269[0x26C - 0x269];
    /* 0x26C */ u8 _26C;
    /* 0x26D */ u8 _26D[0x27C - 0x26D];
} Player0568; // size: 0x27C

extern struct {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ struct ModelList0568* _0060;
    /* 0x0064 */ u8 _0064[0xAC - 0x64];
    /* 0x00AC */ void* _00AC[4];
    /* 0x00BC */ u8 _00BC[0x13C - 0xBC];
    /* 0x013C */ void* _013C;
    /* 0x0140 */ Pose0568 _0140[13];
    /* 0x0C04 */ Player0568 _0C04[13];
    /* 0x2C50 */ Player0568* _2C50[13];
    /* 0x2C84 */ u8 _2C84[0x2C8C - 0x2C84];
    /* 0x2C8C */ u8* _2C8C;
    /* 0x2C90 */ u8 _2C90[0x2D94 - 0x2C90];
    /* 0x2D94 */ struct {
        /* 0x00 */ u8 _00[0x28];
    }* _2D94;
    /* 0x2D98 */ u8 _2D98[0x3078 - 0x2D98];
    /* 0x3078 */ u16 _3078;
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B;
    /* 0x307C */ u8 _307C;
} lbl_8036E548;

extern struct {
    /* 0x00 */ s8 _00;
    /* 0x01 */ s8 _01;
    /* 0x02 */ s8 _02[10];
    /* 0x0C */ s32 _0C;
    /* 0x10 */ u8 _10[4];
    /* 0x14 */ u8 _14[4];
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C[0x27 - 0x1C];
    /* 0x27 */ s8 _27[4];
    /* 0x2B */ u8 _2B[0x2D - 0x2B];
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E[0x32 - 0x2E];
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33[0x40 - 0x33];
    /* 0x40 */ u8 _40[2];
    /* 0x42 */ u8 _42[4];
    /* 0x46 */ u8 _46[2];
} lbl_2_bss_100B8;

typedef struct Pad0568 {
    /* 0x0 */ u16 _0;
    /* 0x2 */ u16 _2;
    /* 0x4 */ u16 _4;
} Pad0568; // size: 0x6

typedef struct Char0568 {
    /* 0x00 */ u8 _00[0x24];
    /* 0x24 */ s16 CharID;
    /* 0x26 */ u8 _26[0xA0 - 0x26];
} Char0568; // size: 0xA0

extern struct {
    /* 0x0000 */ Char0568 _0000[12][9];
    /* 0x4380 */ u8 _4380[0x46F8 - 0x4380];
    /* 0x46F8 */ s8 _46F8[2];
    /* 0x46FA */ u8 _46FA[0x4701 - 0x46FA];
    /* 0x4701 */ u8 _4701;
    /* 0x4702 */ u8 _4702[0x472C - 0x4702];
    /* 0x472C */ Pad0568 _472C[4];
    /* 0x4744 */ u8 _4744[0x4755 - 0x4744];
    /* 0x4755 */ u8 _4755;
} lbl_8034E9A0;

extern struct {
    /* 0x00 */ u8 _00[0x26];
    /* 0x26 */ u8 _26;
} lbl_8034E978;

extern struct {
    /* 0x00 */ u8 _00[0x13];
    /* 0x13 */ u8 _13;
} lbl_8037169C;

extern struct {
    /* 0x00 */ u8 _00[0x55];
    /* 0x55 */ u8 _55[4];
    /* 0x59 */ u8 _59[4];
    /* 0x5D */ u8 _5D[4];
} lbl_803C66B0;

extern struct {
    /* 0x000 */ u8 _000[0x396];
    /* 0x396 */ u8 _396;
    /* 0x397 */ u8 _397;
    /* 0x398 */ u8 _398;
} lbl_800EF808;

extern struct {
    /* 0x00 */ u8 _00[0x1F];
    /* 0x1F */ u8 _1F;
} lbl_80366158;

extern struct {
    /* 0x0 */ u16 _0;
    /* 0x2 */ s16 _2;
    /* 0x4 */ s16 _4;
    /* 0x6 */ s8 _6;
    /* 0x7 */ s8 _7;
    /* 0x8 */ s8 _8;
    /* 0x9 */ u8 _9;
    /* 0xA */ u8 _A;
    /* 0xB */ u8 _B;
    /* 0xC */ u8 _C;
    /* 0xD */ u8 _D;
    /* 0xE */ u8 _E;
    /* 0xF */ u8 _F;
} lbl_2_bss_1033C;

typedef struct Task0568 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ Player0568* _14;
    /* 0x18 */ s8 _18[4];
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
    /* 0x1E */ u8 _1E;
    /* 0x1F */ u8 _1F;
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
} Task0568;

extern void* lbl_803CC1B8;

extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ s32 _10[2];
    /* 0x18 */ s32 _18[4];
    /* 0x28 */ u8 _28[0x30 - 0x28];
    /* 0x30 */ s32 _30[2];
} lbl_2_bss_F410;

extern struct {
    /* 0x00 */ u8 _00[0xF4];
    /* 0xF4 */ u8 _F4;
} lbl_80361B20;

extern u8 lbl_800EFBA4[0x10];

extern struct {
    /* 0x00 */ u8 _00[0x47];
    /* 0x47 */ u8 _47;
} lbl_803C50E8;

extern u8 lbl_800FE930[][6];
extern u8 lbl_800FE5D4[];
extern u8 lbl_2_bss_100B4[2];

typedef struct Slot0568 {
    /* 0x00 */ u8* _00;
    /* 0x04 */ u8 _04[0x60 - 0x4];
    /* 0x60 */ s8 _60;
    /* 0x61 */ s8 _61;
    /* 0x62 */ u8 _62[0x64 - 0x62];
} Slot0568; // size: 0x64

extern Slot0568 lbl_2_bss_101AC[4];

extern u8 lbl_800F71D8[];

extern struct {
    /* 0x0 */ u8* _0;
    /* 0x4 */ s32 _4;
    /* 0x8 */ s32 _8;
} lbl_2_data_2780;

extern u8* lbl_2_bss_122C;
extern u8* lbl_2_bss_1228;

extern u8 lbl_2_data_2794[];
extern u8 lbl_2_data_278C[2][4];
extern Vec lbl_2_data_20F8[2];

typedef struct AramEntry0568 {
    /* 0x0 */ u32 _0[4];
} AramEntry0568; // size: 0x10

extern AramEntry0568 lbl_2_data_241C[54];
extern AramEntry0568* lbl_2_data_277C;

extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;

static inline s32 hasAltAnims(s8 type) {
    s32 result = 0;

    if (type == 0x12 || type == 0x26 || type == 0x28 || type == 0x29) {
        result = 1;
    }
    return result != 0;
}

static inline void setRefAnim(ActorRef0568* ref, AnimBank0568* bank, s32 seq, f32 speed) {
    ref->_04 = bank;
    ref->_0E = seq;
    ref->_5C = 0.0f;
    ref->_58 = 1;
    ref->_59 = bank != NULL;
    ref->_5A = bank != NULL;
    ref->_60 = speed;
}

static inline u16 getModelId(s32 index) {
    return lbl_8036E548._2C50[index] != NULL ? lbl_8036E548._2C50[index]->_162[4] : 0xFFFF;
}

extern Mtx lbl_2_bss_1010C;

extern struct {
    /* 0x0 */ u8 _0[0x6];
    /* 0x6 */ u16 _6;
}* lbl_803CBBCC;

Task0568* lbl_2_bss_1224;

typedef struct Obj0568 {
    /* 0x00 */ u8 _00[0x70];
    /* 0x70 */ void* _70;
} Obj0568;

extern void fn_2_16460(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void convertTextureHeader(void* tex);
extern void LoadActorLayout(void* layout);
extern void convertGeometryAndSknHeader(void* geo, void* skn);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void fn_800BD190(void* geo, void* tex);
extern void ANIMGet(void* bank);
extern void fn_8002399C(ActorRef0568* ref, s32 arg1, s32 arg2, void* layout, void* anim, void* skn);
extern void fn_800BD548(void* model, s32 count, ...);
extern void fn_800B2C08(Actor0568* actor, u16 id);
extern void fn_8001FC4C(Player0568* player);
extern void fn_800B2B74(Actor0568* actor, u16 id);
extern void fn_800B2BA8(Actor0568* dst, u16 id, Actor0568* src, u16 index);
extern void fn_800126EC(void* pose, void* tex, u8* arg2);
extern void fn_8001D180(s32 index, s32 arg1, s32 arg2);
extern void fn_80025DDC(void* anim);
extern void fn_80014990(s32 index, void* arg1, void* arg2);
extern void fn_80025C58(void* anim, ActorRef0568* ref);
extern void fn_800638B4(Player0568* player, ActorRef0568* ref);
extern void fn_8004B7B4(Player0568* player, ActorRef0568* ref);
extern void fn_80023B04(s32);
extern void fn_80014204(s32);
extern void* fn_80023AA4(void);
extern void* ARAMTransfer(AramEntry0568* entry, void* dst, s32 arg2, u32 aram);
extern void fn_2_14BB8(u8 index, s32 flag);
extern ActorRef0568* fn_800111D8(Player0568* player);
extern void fn_800B2B54(void* actor, u16 id, s32 mode);
extern void fn_80025EEC(void* state, s32, s32);
extern void fn_2_11A0(s32 arg0);
extern void changeScene(u8, s16);
extern void fn_800625A4(s32 index, s32 value);
extern void fn_8003BF54(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_800B9AA8(void* arg0);
extern void ACTSetAnimation(Actor0568* actor, void* animBank, char* sequenceName, u16 seqNum, f32 time, f32 speed);
extern void fn_800B4CA0(Actor0568* actor, f32 frame);
extern void fn_800B4C04(Actor0568* actor, f32 speed);
extern void fn_800B4AFC(Actor0568* actor, u8 flag);
extern void Set_FUN_800b2b6c(Actor0568* actor, void* arg1);
extern void fn_800BDA24(ActorRef0568* ref);
extern void fn_800BDA94(ActorRef0568* ref, Mtx view);
extern void fn_80021204(void);
extern void fn_80021228(u8 arg0);
extern void initializeUnknown(void);
extern void fn_80062A74(void);
extern void fn_80062A94(void);
extern void fn_800A97EC(s32 arg0, s32 arg1, s32 arg2);
extern s32 fn_8003AE70(s32 index);

static inline s32 settingsChanged(void) {
    s32 changed = 0;

    if (lbl_800EF808._398 != fn_8003AE70(0) || lbl_800EF808._397 != fn_8003AE70(1) ||
        lbl_80366158._1F != fn_8003AE70(2)) {
        changed = 1;
    }
    return changed;
}

// .text:0x00019D04 size:0x228
void fn_2_19D04(void) {
    switch (lbl_2_bss_1033C._0) {
    case 0:
        if (lbl_8037169C._13 == 0) {
            break;
        }
        lbl_2_bss_1033C._0 = 1;
    case 1:
        changeScene(1, 6);
        lbl_2_bss_F410._08 = 0;
        lbl_2_bss_F410._0C = 0;
        fn_2_96D20();
        fn_800625A4(0, 0x59);
        lbl_2_bss_1033C._4 = 0;
        lbl_2_bss_1033C._2 = 0;
        lbl_2_bss_1033C._B = 0;
        fn_2_19520();
        lbl_2_bss_1033C._D = lbl_2_bss_1033C._6 != 0;
        lbl_2_bss_1033C._0 = 2;
        break;
    case 2:
        if (lbl_803C66B0._5D[0] == 0) {
            lbl_2_bss_1033C._0 = 3;
        }
        break;
    case 3:
        fn_2_197AC(lbl_8034E9A0._46F8[0]);
        break;
    case 5:
        fn_2_194E8();
        fn_8003BF54(0, 0, 0, 0, 1, 4, 1, 0, 4);
        ((Task0568*)lbl_803CC1B8)->_10 = 0;
        lbl_2_bss_1033C._0 = 6;
        break;
    case 6:
        if (((Task0568*)lbl_803CC1B8)->_10 == 0) {
            break;
        }
        switch (((Task0568*)lbl_803CC1B8)->_10) {
        case 1:
        case 11:
            fn_800625A4(0, 0x5A);
            lbl_2_bss_1033C._0 = 4;
            break;
        default:
            lbl_2_bss_1033C._0 = 5;
            break;
        }
        break;
    case 4:
        if (lbl_803C66B0._55[0] == 0) {
            lbl_2_bss_1033C._F = 1;
            lbl_2_bss_1033C._0 = 0;
            lbl_8034E978._26 = 1;
            fn_2_11A0(5);
        }
        break;
    }
}

static inline u8 enableOption(s8* option) {
    s8 old = *option;

    *option = 1;
    return old == 0;
}

// .text:0x000197AC size:0x558
void fn_2_197AC(u8 index) {
    u8 changed = 0;
    Pad0568 pad;
    u8 old;

    if (lbl_8034E9A0._46F8[index] == -1) {
        return;
    }
    memset(&pad, 0, sizeof(pad));
    pad._0 = lbl_8034E9A0._472C[index]._0;
    pad._2 = lbl_8034E9A0._472C[index]._2;
    pad._4 = lbl_8034E9A0._472C[index]._4;
    if (pad._2 & 0x100) {
        if (lbl_2_bss_1033C._B != 0) {
            fn_2_195DC();
        } else {
            lbl_2_bss_1033C._B = 1;
        }
        fn_800625A4(0, 0x5C);
        sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
    } else if (pad._2 & 0x200) {
        if (lbl_2_bss_1033C._B != 0) {
            lbl_2_bss_1033C._B = 0;
            fn_800625A4(0, 0x5C);
            fn_2_19520();
        } else {
            if (lbl_803C50E8._47 != 0) {
                fn_2_194E8();
                fn_800625A4(0, 0x5A);
                lbl_2_bss_1033C._0 = 4;
                sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
                return;
            }
            if (settingsChanged()) {
                lbl_2_bss_1033C._0 = 5;
            } else {
                fn_800625A4(0, 0x5A);
                lbl_2_bss_1033C._0 = 4;
            }
        }
        sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
    } else if (pad._4 & 8) {
        if (lbl_2_bss_1033C._B == 0) {
            lbl_2_bss_1033C._4 = lbl_2_bss_1033C._2;
            lbl_2_bss_1033C._2--;
            if (lbl_2_bss_1033C._2 < 0) {
                lbl_2_bss_1033C._2 = 2;
            } else if (lbl_2_bss_1033C._6 == 0 && lbl_2_bss_1033C._2 == 1) {
                lbl_2_bss_1033C._2--;
            }
            fn_800625A4(0, 0x5B);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad._4 & 4) {
        if (lbl_2_bss_1033C._B == 0) {
            lbl_2_bss_1033C._4 = lbl_2_bss_1033C._2;
            lbl_2_bss_1033C._2++;
            if (lbl_2_bss_1033C._2 == 3) {
                lbl_2_bss_1033C._2 = 0;
            } else if (lbl_2_bss_1033C._6 == 0 && lbl_2_bss_1033C._2 == 1) {
                lbl_2_bss_1033C._2++;
            }
            fn_800625A4(0, 0x5B);
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad._2 & 1) {
        if (lbl_2_bss_1033C._B != 0) {
            switch (lbl_2_bss_1033C._2) {
            case 0:
                changed = enableOption(&lbl_2_bss_1033C._6);
                lbl_2_bss_1033C._A = 0;
                break;
            case 1:
                lbl_2_bss_1033C._9 = lbl_2_bss_1033C._7;
                if (lbl_2_bss_1033C._7 > 0) {
                    changed = 1;
                    lbl_2_bss_1033C._7--;
                }
                break;
            case 2:
                changed = enableOption(&lbl_2_bss_1033C._8);
                break;
            }
            if (changed) {
                fn_800625A4(0, 0x5B);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    } else if (pad._2 & 2) {
        if (lbl_2_bss_1033C._B != 0) {
            switch (lbl_2_bss_1033C._2) {
            case 0:
                old = lbl_2_bss_1033C._6;
                lbl_2_bss_1033C._6 = 0;
                if (lbl_2_bss_1033C._6 == 0) {
                    lbl_2_bss_1033C._A = 0;
                } else {
                    lbl_2_bss_1033C._A = 1;
                }
                if (old != lbl_2_bss_1033C._6) {
                    changed = 1;
                }
                break;
            case 1:
                old = lbl_2_bss_1033C._7;
                lbl_2_bss_1033C._9 = old;
                lbl_2_bss_1033C._7++;
                if (lbl_2_bss_1033C._7 == 3) {
                    lbl_2_bss_1033C._7 = 2;
                }
                if (old != lbl_2_bss_1033C._7) {
                    changed = 1;
                }
                break;
            case 2:
                old = lbl_2_bss_1033C._8;
                lbl_2_bss_1033C._8 = 0;
                if (old != lbl_2_bss_1033C._8) {
                    changed = 1;
                }
                break;
            }
            if (changed) {
                fn_800625A4(0, 0x5B);
            }
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
    }
}

// .text:0x00019778 size:0x34
void fn_2_19778(void) {
    s8 a = lbl_800EF808._398;
    s8 b = lbl_80366158._1F;
    s8 c = lbl_800EF808._396;

    lbl_2_bss_1033C._6 = a;
    lbl_2_bss_1033C._8 = b;
    lbl_2_bss_1033C._7 = c;
}

// .text:0x000195DC size:0x19C
void fn_2_195DC(void) {
    switch (lbl_2_bss_1033C._2) {
    case 0:
        if (lbl_2_bss_1033C._6 != 0 && lbl_800EF808._398 == 0) {
            initializeUnknown();
            fn_800B0A5C_insertQueue(fn_80062A94, 0x1000);
        } else if (lbl_2_bss_1033C._6 == 0 && lbl_800EF808._398 != 0) {
            fn_80062A74();
        }
        lbl_800EF808._398 = lbl_2_bss_1033C._6;
        lbl_2_bss_1033C._D = lbl_2_bss_1033C._6;
        break;
    case 1:
        if (lbl_2_bss_1033C._7 != lbl_800EF808._396) {
            fn_80062A74();
            if (lbl_2_bss_1033C._7 == 1) {
                lbl_800EF808._396 = 1;
            } else if (lbl_2_bss_1033C._7 == 0) {
                lbl_800EF808._396 = 0;
            } else {
                lbl_800EF808._396 = 2;
            }
            fn_80021228(lbl_800EF808._396);
            fn_800B0A5C_insertQueue(fn_80062A94, 0x1000);
            lbl_800EF808._396 = lbl_2_bss_1033C._7;
        }
        break;
    case 2:
        if (lbl_2_bss_1033C._8 != 0) {
            lbl_80366158._1F = 1;
            fn_800A97EC(0, 50, 1);
        } else {
            lbl_80366158._1F = 0;
        }
        break;
    }
    lbl_2_bss_1033C._B = 0;
}

// .text:0x000195D8 size:0x4
void fn_2_195D8(void) {
}

// .text:0x00019554 size:0x84
s8 fn_2_19554(void) {
    return settingsChanged();
}

// .text:0x00019520 size:0x34
void fn_2_19520(void) {
    s8 a = lbl_800EF808._398;
    s8 b = lbl_80366158._1F;
    s8 c = lbl_800EF808._396;

    lbl_2_bss_1033C._6 = a;
    lbl_2_bss_1033C._8 = b;
    lbl_2_bss_1033C._7 = c;
}

// .text:0x000194E8 size:0x38
void fn_2_194E8(void) {
    fn_80021204();
    gameInitOptions._25 = lbl_80366158._1F;
}

// .text:0x000194BC size:0x2C
void fn_2_194BC(Obj0568* obj) {
    if (obj->_70 != NULL) {
        fn_800B9AA8(obj->_70);
    }
}

// .text:0x0001937C size:0x140
void fn_2_1937C(ModelList0568* list, Mtx view) {
    Mtx44 proj;
    u16 i;
    Player0568* player;
    ActorRef0568* ref;
    f32 x;
    f32 y;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetCullMode(GX_CULL_BACK);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    for (i = 0; i < list->_00; i++) {
        player = lbl_8036E548._2C50[i];
        if (player == NULL) {
            continue;
        }
        ref = &list->_34[i];
        if (ref->_00 != NULL && ref->_6C != 0) {
            x = player->_034 / 1280.0f;
            y = player->_038 / 1280.0f;
            C_MTXFrustum(proj, -0.175f + y, 0.175f + y, 0.25f + x, -0.25f + x, 1.0f, 512.0f);
            GXSetProjection(proj, GX_PERSPECTIVE);
            fn_800BDA94(ref, view);
        }
    }
}

// .text:0x00019224 size:0x158
void fn_2_19224(ModelList0568* list) {
    u16 i;
    Player0568* player;
    ActorRef0568* ref;

    for (i = 0; i < list->_00; i++) {
        player = lbl_8036E548._2C50[i];
        if (player == NULL || player->_25D == 0) {
            continue;
        }
        ref = &list->_34[i];
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
        ref->_00->_98 = 1;
        ref->_58 = 0;
        ref->_59 = 0;
        ref->_5A = 0;
        ref->_5B &= 1;
    }
}

// .text:0x000190DC size:0x148
void fn_2_190DC(ModelList0568* list, Mtx view) {
    u16 i;
    ActorRef0568* ref;

    for (i = 0; i < list->_00; i++) {
        if (&lbl_8036E548._2D94[i] == NULL) {
            continue;
        }
        ref = &list->_34[i];
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
        ref->_00->_98 = 1;
        ref->_58 = 0;
        ref->_59 = 0;
        ref->_5A = 0;
        ref->_5B &= 1;
    }
}

// .text:0x000190B8 size:0x24
void fn_2_190B8(Obj0568* obj) {
    fn_800B9AA8(obj->_70);
}

// .text:0x00018FBC size:0xFC
void fn_2_18FBC(void) {
    Task0568* task = fn_800B0A5C_insertQueue(fn_2_188EC, 0x6000);
    s32 i;

    lbl_2_bss_100B8._19 = 0;
    lbl_2_bss_100B8._1B = 1;
    if (lbl_8034E9A0._4701 == 0) {
        for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
            lbl_2_bss_100B8._27[i] = -1;
        }
        task->_1C = 0;
    } else {
        for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
            lbl_2_bss_100B8._14[i] = 0;
        }
        task->_1C = 0;
    }
    lbl_2_bss_100B8._00 = 0;
    lbl_2_bss_100B8._01 = 0;
    for (i = 0; i < 10; i++) {
        lbl_2_bss_100B8._02[i] = -1;
    }
}

// .text:0x00018748 size:0x1A4
void fn_2_18748(void) {
    Task0568* task = lbl_803CC1B8;
    s32 i;

    switch (task->_1D) {
    case 0:
        for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
            if (g_d_GameSettings.GameModeSelected == 5) {
                task->_18[i] = lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[task->_1E]];
            } else {
                task->_18[i] = lbl_800FE5D4[lbl_2_bss_F410._10[task->_1E]];
            }
            if (task->_1E == 2) {
                task->_1E = 0;
            }
        }
        task->_10 = 0;
        task->_21 = 0;
        task->_1D++;
    case 1:
        fn_2_18148(task);
        if (lbl_2_bss_100B8._18 != 0) {
            lbl_2_bss_100B8._18 = 0;
            lbl_2_bss_100B8._32 = 0;
            task->_21 = 0;
            task->_10 = 0;
            task->_1E++;
            if (task->_1E >= lbl_2_bss_100B8._2D) {
                task->_1E = 0;
                task->_1D = 0;
                lbl_2_bss_100B8._19 = 1;
                fn_800B0A14_removeQueue();
            } else {
                task->_1D = 0;
            }
        } else if (lbl_2_bss_100B4[0] != 0) {
            task->_1E = 0;
            task->_1D = 0;
            fn_800B0A14_removeQueue();
        }
        break;
    }
}

// .text:0x00018650 size:0xF8
s32 fn_2_18650(s32 index) {
    s32 next = (lbl_2_bss_100B8._00 + 1) % 10;

    if (next != lbl_2_bss_100B8._01) {
        if (lbl_2_bss_1224 == NULL) {
            lbl_2_bss_1224 = fn_800B0A5C_insertQueue(fn_2_18398, 0xFFFF);
            if (lbl_2_bss_1224 != NULL) {
                lbl_2_bss_1224->_1C = 0;
                lbl_2_bss_1224->_1D = 0;
            } else {
                return 0;
            }
        }
        lbl_2_bss_100B8._02[lbl_2_bss_100B8._00] = index;
        lbl_2_bss_100B8._00 = next;
        lbl_2_bss_100B8._42[index] = 1;
        return 1;
    }
    return 0;
}

// .text:0x00018398 size:0x2B8
void fn_2_18398(void) {
    Task0568* task = lbl_803CC1B8;
    s8 id;
    s32 idx;
    u8 mode;
    u8 type;

    switch (task->_1D) {
    case 0:
        id = lbl_2_bss_100B8._02[lbl_2_bss_100B8._01];
        if (id == -1) {
            lbl_2_bss_100B8._18 = 0;
            lbl_2_bss_100B8._1B = 1;
            lbl_2_bss_100B8._1A = 0;
            lbl_2_bss_100B8._32 = 0;
            lbl_2_bss_1224 = NULL;
            fn_800B0A14_removeQueue();
            break;
        }
        task->_1E = id;
        lbl_2_bss_100B8._02[lbl_2_bss_100B8._01] = -1;
        lbl_2_bss_100B8._01 = (lbl_2_bss_100B8._01 + 1) % 10;
        lbl_2_bss_100B8._1A = 1;
        lbl_2_bss_100B8._1B = 0;
        lbl_2_bss_100B8._27[task->_1E] = task->_1E;
        task->_1D = 1;
        task->_10 = 0;
        mode = g_d_GameSettings.GameModeSelected;
        type = lbl_8034E9A0._4755;
        if (type == 0) {
            if (mode == 5) {
                task->_18[task->_1E] = lbl_800FE930[lbl_80361B20._F4][lbl_2_bss_F410._10[(u8)task->_1E]];
            } else {
                task->_18[task->_1E] = lbl_800FE5D4[lbl_2_bss_F410._10[(u8)task->_1E]];
            }
            if (task->_1E == 2) {
                task->_1E = 0;
            }
        } else if (type == 1) {
            idx = task->_1E;
            switch (idx) {
            case 0:
            case 1:
                task->_18[idx] = inMemRoster[idx][lbl_2_bss_F410._30[idx] - (idx * 11 + 2)].stats.CharID;
                break;
            case 2:
            case 3:
                task->_18[idx] = lbl_2_bss_F410._18[idx];
                break;
            }
        }
    case 1:
        fn_2_18148(task);
        if (lbl_2_bss_100B4[0] != 0 && lbl_2_bss_100B4[1] == 0) {
            lbl_2_bss_100B8._18 = 0;
            lbl_2_bss_100B8._1B = 1;
            lbl_2_bss_100B8._1A = 0;
            lbl_2_bss_100B8._32 = 0;
            lbl_2_bss_1224 = NULL;
            task->_1D = 0;
            fn_800B0A14_removeQueue();
        } else if (lbl_2_bss_100B8._18 != 0) {
            lbl_2_bss_100B8._18 = 0;
            lbl_2_bss_100B8._1A = 0;
            task->_1D = 0;
        }
        break;
    }
}

// .text:0x00018148 size:0x250
void fn_2_18148(Task0568* task) {
    switch (task->_21) {
    case 0:
        task->_14 = &lbl_8036E548._0C04[task->_1E];
        task->_14->_252 = task->_18[task->_1E];
        task->_20 = lbl_2_bss_100B8._46[task->_1E];
        lbl_8036E548._0C04[task->_1E]._25D = 0;
        task->_14->_068 = -1;
        lbl_2_bss_100B4[1] = 1;
        task->_21++;
        break;
    case 1:
        ARAMTransfer(&lbl_2_data_241C[task->_18[task->_1E]], task->_14->_008, 0, 0);
        task->_21++;
        break;
    case 2:
        if (lbl_803C6CF8._715 == 1) {
            fn_2_16F78(task->_1E);
            if (g_d_GameSettings._10 == 0 && lbl_803C66B0._59[0] == 0 && task->_1E == 1) {
                lbl_8036E548._0C04[task->_1E]._25D = 0;
            } else {
                lbl_8036E548._0C04[task->_1E]._25D = task->_20 != 0;
            }
            if (g_d_GameSettings.GameModeSelected == 5 || g_d_GameSettings._10 != 0 || lbl_803CBBCC->_6 == 5) {
                fn_2_14BB8(task->_1E, 1);
            } else if (lbl_2_bss_100B8._10[0] != 0) {
                fn_2_14BB8(task->_1E, task->_1E != 0);
            }
            task->_21 = 0;
            lbl_2_bss_100B8._32 = 1;
            lbl_2_bss_100B4[1] = 0;
            lbl_2_bss_100B8._18 = 1;
            lbl_2_bss_100B8._42[task->_1E] = 0;
        }
        break;
    }
}

// .text:0x00017ED8 size:0x270
void fn_2_17ED8(void) {
    fn_2_17C88();
    fn_80014204(lbl_2_bss_100B8._2D);
    lbl_8036E548._013C = fn_80023AA4();
    fn_80023B04(4);
}

// .text:0x00017C88 size:0x250
void fn_2_17C88(void) {
    s32 i;
    s32 j;
    u32 max = 0;
    u32 size;

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 9; j++) {
            if (i * 9 + j == 53) {
                goto done;
            }
            size = lbl_2_data_241C[lbl_8034E9A0._0000[i][j].CharID]._0[1] & 0x0FFFFFFF;
            if (max < size) {
                max = size;
            }
        }
    }
done:
    size = (max + 0x1F) & ~0x1F;
    lbl_8036E548._2C8C = _OSAllocFromHeap(0x20, size * lbl_2_bss_100B8._2D);
    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        lbl_8036E548._0C04[i]._008 = (u32*)(lbl_8036E548._2C8C + size * i);
    }
}

// .text:0x00017AB8 size:0x1D0
void fn_2_17AB8(void) {
    s32 size = ((((u32*)lbl_2_data_2780._0)[1] & 0x0FFFFFFF) + 0x1F) & ~0x1F;
    s32 i;

    lbl_2_bss_122C = _OSAllocFromHeap(0x20, size * lbl_2_bss_100B8._2D);
    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        lbl_2_bss_101AC[i]._00 = lbl_2_bss_122C + size * i;
        lbl_2_bss_101AC[i]._61 = -1;
        lbl_2_bss_101AC[i]._60 = -1;
    }
}

// .text:0x00017648 size:0x470
void fn_2_17648(void) {
    s32 i;
    s32 j;
    s32 k;
    u32 max = 0;
    u32 size;

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 9; j++) {
            if (i * 9 + j == 53 || j != 0) {
                goto done;
            }
            for (k = 0; k < 6; k++) {
                size = lbl_2_data_277C[lbl_8034E9A0._0000[i][j].CharID + k]._0[1] & 0x0FFFFFFF;
                if (max < size) {
                    max = size;
                }
            }
        }
    }
done:
    size = (max + 0x1F) & ~0x1F;
    lbl_2_bss_1228 = _OSAllocFromHeap(0x20, size * lbl_2_bss_100B8._2D * 2);
    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        lbl_8036E548._0140[i]._00 = lbl_2_bss_1228 + size * (i * 2);
        lbl_8036E548._0140[i]._64 = lbl_2_bss_1228 + size * (i * 2 + 1);
    }
    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        lbl_8036E548._0140[i]._CF = -1;
        lbl_8036E548._0140[i]._D1 = -1;
        lbl_8036E548._0140[i]._D0 = -1;
        lbl_8036E548._0140[i]._CD = 0xFF;
        lbl_8036E548._0140[i]._C8 = 0;
        lbl_8036E548._0140[i]._CC = 0;
        lbl_8036E548._0140[i]._60 = i * 2;
        lbl_8036E548._0140[i]._C4 = i * 2 + 1;
    }
}

// .text:0x00016F78 size:0x6D0
void fn_2_16F78(u8 index) {
    Player0568* player = &lbl_8036E548._0C04[index];
    u32* data;
    void* tex;
    void* layout;
    void* geo;
    void* skn;
    void* anim;
    ActorRef0568* ref;
    u16 count;
    u16 id;
    s32 i;
    s32 first;
    s32 second;
    Pose0568* pose;
    Vec* pos;

    player->_255 = index;
    data = player->_008;
    for (i = 0; i < 15; i++) {
        if (player->_008[i] == 0) {
            break;
        }
        player->_008[i] = (u32)data + data[i];
    }
    tex = (void*)player->_008[0];
    layout = (void*)player->_008[1];
    geo = (void*)player->_008[2];
    skn = (void*)player->_008[3];
    convertTextureHeader(tex);
    LoadActorLayout(layout);
    convertGeometryAndSknHeader(geo, skn);
    haveActLayoutPointToGeoHeader(layout, geo);
    fn_800BD190(geo, tex);
    anim = player->_010[5] = (AnimBank0568*)player->_008[4];
    ANIMGet(player->_010[5]);
    ref = fn_800111D8(player);
    fn_8002399C(ref, index, index, layout, anim, skn);
    setRefAnim(&lbl_8036E548._0060->_34[index], player->_010[5], 0, 0.0f);
    count = lbl_8036E548._0060->_34[index]._00->_06;
    memset(player->_162, 0xFF, sizeof(player->_162));
    for (i = 0; i < count; i++) {
        id = lbl_8036E548._0060->_34[index]._00->_18[i]->_000;
        if (id != 0xFFFF) {
            player->_162[id] = i;
        }
    }
    fn_800BD548(&lbl_8036E548._0060->_34[index], 4, lbl_8036E548._00AC[0], lbl_8036E548._00AC[1],
                lbl_8036E548._00AC[2], lbl_8036E548._00AC[3]);
    player->_040 = player->_044 = player->_048 = 0.0f;
    CTRLSetTranslation(&lbl_8036E548._0060->_34[index]._10, 0.0f, 0.0f, 0.0f);
    CTRLSetRotation(&lbl_8036E548._0060->_34[index]._10, 0.0f, 0.0f, 0.0f);
    lbl_8036E548._0060->_34[index]._54 = 0.5f;
    lbl_8036E548._0060->_34[index]._5A = 1;
    fn_800B2C08(lbl_8036E548._0060->_34[index]._00, getModelId(index));
    fn_8001FC4C(lbl_8036E548._2C50[index]);
    pos = &lbl_2_data_20F8[index];
    player->_034 = pos->x;
    player->_038 = pos->y;
    player->_03C = pos->z;
    player->_04C = 0.5f;
    player->_25D = 0;
    lbl_8036E548._0060->_34[index]._08 = fn_2_190B8;
    player->_000 = ref->_00;
    fn_800B2B74(ref->_00, player->_162[19]);
    fn_800B2B74(ref->_00, player->_162[25]);
    id = player->_162[3];
    if (id != 0xFFFF) {
        fn_800B2B54(player->_000, id, 13);
    }
    id = player->_162[3];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
        ref->_00->_18[id]->_136 = 1;
    }
    id = player->_162[2];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
        ref->_00->_18[id]->_136 = 1;
    }
    id = player->_162[1];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
        ref->_00->_18[id]->_136 = 1;
    }
    id = player->_162[36];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
    }
    id = player->_162[46];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
        ref->_00->_18[id]->_136 = 1;
    }
    pose = &lbl_8036E548._0140[player->_255];
    if (player->_008[5] != 0) {
        player->_030 = &lbl_8036E548._0140[index];
        pose->_00 = (u8*)player->_008;
        fn_800126EC(pose, tex, lbl_2_data_278C[0]);
        pose->_64 = (u8*)player->_008;
        fn_800126EC(&pose->_64, tex, lbl_2_data_278C[1]);
    }
    if (hasAltAnims(player->_252)) {
        switch (player->_252) {
        case 0x12:
            first = 4;
            second = 5;
            break;
        case 0x26:
            first = 2;
            second = 3;
            break;
        case 0x28:
        case 0x29:
            first = 6;
            second = 7;
            break;
        }
    } else {
        first = 1;
        second = 0;
    }
    fn_8001D180(index, first, 1);
    fn_8001D180(index, second, 1);
    if (player->_008[13] != 0 && player->_008[14] != 0) {
        fn_80025DDC((void*)player->_008[13]);
        fn_80014990(index, (void*)player->_008[13], (void*)player->_008[14]);
        fn_80025C58((void*)player->_008[13], ref);
    }
    player->_030->_CC = 1;
    player->_030->_68._10 = 0.5f;
    player->_030->_04._10 = 0.5f;
    switch (player->_252) {
    case 2:
        fn_800638B4(player, ref);
        break;
    case 0x13:
        player->_25C = 1;
        fn_8004B7B4(player, ref);
        break;
    }
    fn_2_16A98(index, 0, 1, 0, 0, 0, 0);
}

// .text:0x00016F0C size:0x6C
void fn_2_16F0C(u8 index) {
    s8 a = lbl_8036E548._0C04[index]._252;
    Player0568* player = &lbl_8036E548._0C04[index];
    s8 b = lbl_8036E548._0C04[index]._254;

    if (lbl_8036E548._0140[index]._D0 == -1) {
        lbl_8036E548._0140[index]._CF = a;
        lbl_8036E548._0140[index]._D1 = lbl_8036E548._0140[index]._D0;
        lbl_8036E548._0140[index]._D0 = b;
        lbl_8036E548._0140[index]._CD = player->_265;
    }
    player->_030 = &lbl_8036E548._0140[index];
}

// .text:0x00016DA8 size:0x164
void fn_2_16DA8(void) {
    s32 i;

    lbl_8036E548._3078 = 0;
    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        lbl_8036E548._2C50[i] = &lbl_8036E548._0C04[i];
    }
    i = 3;
    do {
        lbl_2_bss_100B8._42[i] = 0;
    } while (i-- != 0);
    if (lbl_803CBBCC->_6 == 5 || g_d_GameSettings.GameModeSelected == 5) {
        lbl_2_bss_100B8._46[0] = 1;
        lbl_2_bss_100B8._46[1] = 0;
    } else {
        lbl_2_bss_100B8._46[0] = 1;
        lbl_2_bss_100B8._46[1] = 1;
    }
}

// .text:0x00016D38 size:0x70
void fn_2_16D38(void) {
    s32 i;

    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        memset(lbl_8036E548._0C04[i]._008, 0, 0x5C);
    }
}

// .text:0x00016CE0 size:0x58
void fn_2_16CE0(void) {
    Player0568* player;
    s32 i;

    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        player = lbl_8036E548._2C50[i];
        if (player != NULL && player->_062 == 0x6B) {
            lbl_2_bss_100B8._40[i] = 1;
        }
    }
}

// .text:0x00016A98 size:0x248
void fn_2_16A98(s32 index, s32 anim, u8 loop, s8 arg3, s16 frame, s32 arg5, u8 frames) {
    f32 speed = 0.0f;
    Player0568* player = lbl_8036E548._2C50[index];
    ActorRef0568* ref;
    AnimBank0568* bank;
    s32 slot;
    s32 seq;
    u8 value;

    if (player == NULL) {
        return;
    }
    ref = fn_800111D8(player);
    if (frames != 0) {
        speed = 1.0f / frames;
    }
    if (player->_26C == 0) {
        fn_800B2B54(player->_000, getModelId(index), 13);
    } else {
        fn_800B2B54(player->_000, getModelId(index), 1);
    }
    if (anim < 3) {
        slot = 5;
        seq = anim;
    }
    value = lbl_2_data_2794[seq];
    if (player->_02C != NULL) {
        fn_80025EEC(player->_02C + 4, 5, value);
    }
    if (player->_030 != NULL && player->_030->_CC != 0) {
        fn_80025EEC(&player->_030->_68, 5, value);
        fn_80025EEC(&player->_030->_04, 5, value);
    }
    if (index < lbl_2_bss_100B8._2D && (bank = player->_010[slot]) != NULL) {
        if (seq >= bank->_0A) {
            return;
        }
        ref->_04 = bank;
        ref->_0E = seq;
        ref->_5C = 0.0f;
        ref->_58 = 1;
        ref->_59 = bank != NULL;
        ref->_5A = bank != NULL;
        ref->_60 = speed;
    }
    if (loop) {
        ref->_5B = 3;
    } else {
        ref->_5B = 2;
    }
    ref->_5C = frame * player->_04C;
    ref->_59 = 1;
    player->_268 = arg3;
}

// .text:0x00016A74 size:0x24
void fn_2_16A74(s32 index, s32 flag) {
    lbl_8036E548._0C04[index]._25D = flag != 0;
}

// .text:0x00016A5C size:0x18
u8 fn_2_16A5C(s32 index) {
    return lbl_8036E548._0C04[index]._25D;
}

// .text:0x00016A48 size:0x14
void fn_2_16A48(s32 index, u8 value) {
    lbl_2_bss_100B8._46[index] = value;
}

// .text:0x00016A34 size:0x14
u8 fn_2_16A34(s32 index) {
    return lbl_2_bss_100B8._46[index];
}

// .text:0x00016870 size:0x1C4
void fn_2_16870(void) {
    s32 i;

    for (i = 0; i < lbl_2_bss_100B8._2D; i++) {
        if (lbl_2_bss_100B8._14[i] != 0 && fn_2_18650(i)) {
            lbl_2_bss_100B8._14[i] = 0;
        }
    }
    lbl_8036E548._307A = 5;
    lbl_8036E548._307C = 1;
    fn_2_16460();
    PSMTXCopy(lbl_2_bss_1010C, fn_80052768_getCamera(0)->view);
    fn_2_16CE0();
}
