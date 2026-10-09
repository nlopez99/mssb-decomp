#include "game/rep_E08.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"
#include "game/m_sound.h"
#include "game/rep_1CB8.h"
#include "game/rep_D0.h"
#include "game/rep_A00.h"

typedef struct UnkE08Fielder {
    /* 0x000 */ VecXYZ _000;
    /* 0x00C */ f32 _00C;
    /* 0x010 */ f32 _010;
    /* 0x014 */ u8 _014[0x30 - 0x14];
    /* 0x030 */ f32 _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ u8 _038[0x48 - 0x38];
    /* 0x048 */ f32 _048;
    /* 0x04C */ u8 _04C[0x50 - 0x4C];
    /* 0x050 */ f32 _050;
    /* 0x054 */ u8 _054[0x58 - 0x54];
    /* 0x058 */ f32 _058;
    /* 0x05C */ u8 _05C[0xA8 - 0x5C];
    /* 0x0A8 */ f32 _0A8;
    /* 0x0AC */ u8 _0AC[0xB8 - 0xAC];
    /* 0x0B8 */ f32 _0B8;
    /* 0x0BC */ u8 _0BC[0xD4 - 0xBC];
    /* 0x0D4 */ f32 _0D4;
    /* 0x0D8 */ f32 _0D8;
    /* 0x0DC */ u8 _0DC[0xE8 - 0xDC];
    /* 0x0E8 */ f32 _0E8;
    /* 0x0EC */ u8 _0EC[0x178 - 0xEC];
    /* 0x178 */ s16 _178;
    /* 0x17A */ s16 _17A;
    /* 0x17C */ u8 _17C[0x1AA - 0x17C];
    /* 0x1AA */ s16 _1AA;
    /* 0x1AC */ u8 _1AC[0x1B4 - 0x1AC];
    /* 0x1B4 */ s16 _1B4;
    /* 0x1B6 */ u8 _1B6[0x1B8 - 0x1B6];
    /* 0x1B8 */ s16 _1B8;
    /* 0x1BA */ u8 _1BA[0x1BE - 0x1BA];
    /* 0x1BE */ s16 _1BE;
    /* 0x1C0 */ s16 _1C0;
    /* 0x1C2 */ u8 _1C2[0x1C7 - 0x1C2];
    /* 0x1C7 */ u8 _1C7;
    /* 0x1C8 */ u8 _1C8;
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA;
    /* 0x1CB */ u8 _1CB;
    /* 0x1CC */ u8 _1CC[0x1D3 - 0x1CC];
    /* 0x1D3 */ u8 _1D3;
    /* 0x1D4 */ u8 _1D4[0x1D6 - 0x1D4];
    /* 0x1D6 */ u8 _1D6;
    /* 0x1D7 */ u8 _1D7[0x1E5 - 0x1D7];
    /* 0x1E5 */ u8 _1E5;
    /* 0x1E6 */ u8 _1E6[0x1EC - 0x1E6];
    /* 0x1EC */ u8 _1EC;
    /* 0x1ED */ u8 _1ED;
    /* 0x1EE */ u8 _1EE;
    /* 0x1EF */ u8 _1EF[0x1F9 - 0x1EF];
    /* 0x1F9 */ u8 _1F9;
    /* 0x1FA */ u8 _1FA;
    /* 0x1FB */ u8 _1FB;
    /* 0x1FC */ u8 _1FC;
    /* 0x1FD */ u8 _1FD;
    /* 0x1FE */ u8 _1FE;
    /* 0x1FF */ u8 _1FF;
    /* 0x200 */ u8 _200;
    /* 0x201 */ u8 _201[0x203 - 0x201];
    /* 0x203 */ u8 _203;
    /* 0x204 */ u8 _204;
    /* 0x205 */ u8 _205;
    /* 0x206 */ u8 _206;
    /* 0x207 */ u8 _207;
    /* 0x208 */ u8 _208[0x20A - 0x208];
    /* 0x20A */ u8 _20A;
    /* 0x20B */ u8 _20B[0x20D - 0x20B];
    /* 0x20D */ u8 _20D;
    /* 0x20E */ u8 _20E;
    /* 0x20F */ u8 _20F;
    /* 0x210 */ u8 _210;
    /* 0x211 */ u8 _211;
    /* 0x212 */ u8 _212;
    /* 0x213 */ u8 _213[0x215 - 0x213];
    /* 0x215 */ u8 _215;
    /* 0x216 */ u8 _216[0x248 - 0x216];
    /* 0x248 */ f32 _248;
    /* 0x24C */ s16 _24C;
    /* 0x24E */ u8 _24E[0x252 - 0x24E];
    /* 0x252 */ u8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ u8 _254;
    /* 0x255 */ u8 _255;
    /* 0x256 */ u8 _256;
    /* 0x257 */ u8 _257;
    /* 0x258 */ u8 _258;
    /* 0x259 */ u8 _259;
    /* 0x25A */ u8 _25A;
    /* 0x25B */ u8 _25B;
    /* 0x25C */ u8 _25C;
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E;
    /* 0x25F */ u8 _25F[0x261 - 0x25F];
    /* 0x261 */ u8 _261;
    /* 0x262 */ u8 _262;
    /* 0x263 */ u8 _263[0x268 - 0x263];
} UnkE08Fielder; // size: 0x268

typedef struct UnkE08Anim {
    /* 0x00 */ f32 _00;
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ VecXYZ _10;
    /* 0x1C */ VecXYZ _1C;
    /* 0x28 */ u8 _28[0x2C - 0x28];
    /* 0x2C */ VecXYZ _2C;
    /* 0x38 */ s16 _38;
    /* 0x3A */ s16 _3A;
    /* 0x3C */ s16 _3C;
    /* 0x3E */ s16 _3E;
    /* 0x40 */ u8 _40;
    /* 0x41 */ u8 _41;
    /* 0x42 */ u8 _42;
    /* 0x43 */ u8 _43;
    /* 0x44 */ u8 _44;
    /* 0x45 */ u8 _45;
    /* 0x46 */ u8 _46;
    /* 0x47 */ u8 _47;
    /* 0x48 */ u8 _48;
    /* 0x49 */ u8 _49;
    /* 0x4A */ s16 _4A;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 _4F;
    /* 0x50 */ u8 _50;
    /* 0x51 */ u8 _51;
    /* 0x52 */ u8 _52[0x54 - 0x52];
} UnkE08Anim; // size: 0x54

typedef struct UnkE08Actor {
    /* 0x00 */ u8 _00[0x30];
    /* 0x30 */ void* _30;
    /* 0x34 */ VecXYZ _34;
    /* 0x40 */ u8 _40[0x4C - 0x40];
    /* 0x4C */ f32 _4C;
    /* 0x50 */ u8 _50[0x62 - 0x50];
    /* 0x62 */ s16 _62;
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[0x68 - 0x66];
    /* 0x68 */ s16 _68;
    /* 0x6A */ s16 _6A;
    /* 0x6C */ u8 _6C[0x70 - 0x6C];
    /* 0x70 */ s16 _70;
    /* 0x72 */ u8 _72[0x16A - 0x72];
    /* 0x16A */ u16 _16A;
    /* 0x16C */ u8 _16C[0x252 - 0x16C];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253[0x25D - 0x253];
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E;
    /* 0x25F */ u8 _25F[0x26F - 0x25F];
    /* 0x26F */ u8 _26F;
    /* 0x270 */ u8 _270[0x273 - 0x270];
    /* 0x273 */ u8 _273;
    /* 0x274 */ u8 _274;
    /* 0x275 */ u8 _275[0x27C - 0x275];
} UnkE08Actor; // size: 0x27C

typedef struct UnkE08Track {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0xA - 0x4];
    /* 0x0A */ s16 _0A;
    /* 0x0C */ u8 _0C[0x54 - 0xC];
    /* 0x54 */ u8 _54;
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x58 */ f32 _58;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ u8 _60[0x90 - 0x60];
} UnkE08Track; // size: 0x90

typedef struct UnkE08Tracks {
    /* 0x00 */ u8 _00[0x38];
    /* 0x38 */ UnkE08Track _38[4];
} UnkE08Tracks;

extern struct {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ UnkE08Tracks* _0060;
    /* 0x0064 */ u8 _0064[0xC04 - 0x64];
    /* 0x0C04 */ UnkE08Actor _0C04[13];
    /* 0x2C50 */ UnkE08Actor* _2C50[13];
    /* 0x2C84 */ u8 _2C84[0x307D - 0x2C84];
    /* 0x307D */ u8 _307D;
} lbl_8036E548;

extern struct {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
    /* 0x4 */ s16 _4;
    /* 0x6 */ s16 _6;
    /* 0x8 */ u8 _8;
    /* 0x9 */ u8 _9;
    /* 0xA */ u8 _A;
    /* 0xB */ u8 _B;
    /* 0xC */ s8 _C;
    /* 0xD */ u8 _D;
} lbl_3_common_bss_32220;

extern struct {
    /* 0x0 */ s16 _0;
    /* 0x2 */ u8 _2;
} lbl_3_common_bss_32230;

extern u8 lbl_3_common_bss_32234[8];

typedef struct UnkE08Replay {
    /* 0x000 */ u8 _000[0x25C];
    /* 0x25C */ u8 _25C;
} UnkE08Replay;

extern struct {
    /* 0x0 */ UnkE08Replay* _0;
} lbl_3_common_bss_1323C;

extern u8 lbl_803CBC3C[];

extern struct {
    /* 0x000 */ u8 _000[0x103];
    /* 0x103 */ s8 _103;
    /* 0x104 */ u8 _104;
} lbl_80353A90;

typedef struct UnkE08Throw {
    /* 0x00 */ Vec _00;
    /* 0x0C */ s16 _0C;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ u8 _10;
} UnkE08Throw;

extern UnkE08Throw g_UnkThrowing_31ACC[4];

typedef struct UnkE08RunnerAnim {
    /* 0x00 */ f32 _00;
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x16 - 0x12];
    /* 0x16 */ s16 _16;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
    /* 0x1E */ u8 _1E[0x20 - 0x1E];
} UnkE08RunnerAnim; // size: 0x20

extern UnkE08RunnerAnim lbl_3_common_bss_321A0[4];

// .data outside this unit's range in splits.txt
typedef struct UnkE08CharEntry {
    /* 0x0 */ u8 _0[2];
    /* 0x2 */ u8 _2;
    /* 0x3 */ u8 _3[3];
} UnkE08CharEntry; // size: 0x6

extern UnkE08CharEntry lbl_800E8558[54];

extern u8 lbl_3_data_7760[][5];
extern s16 lbl_3_data_7870[][3];
extern u8 lbl_3_data_7D24[][5];
extern u8 lbl_3_data_7F0C;
extern u8 lbl_3_data_7E34[54][4];
extern s16 lbl_3_data_7F10[54];
extern f32 lbl_3_data_476C[5];

extern UnkE08Fielder g_Fielders[9];
extern UnkE08Anim g_UnkAnimation_31EAC[9];

void fn_8001B4D8(int actor);
s16 fn_8001B35C(int actor, int which);
void** fn_800111D8(UnkE08Actor* actor);
f32 fn_800B4A44(void* model, u16 anim);
void fn_8004AE18(s32 fielder);
void fn_8001C528(void);
int fn_3_6D564(int team, int rosterID, int arg);
extern s16 lbl_3_data_5EDC[22];
void fn_8001B5EC(int actor, int flag);
void QueueCharacterAnimation(int actor, int anim, u8, u8, s16, u8, int);
void AnimateCharacter(int actor, int anim, u8, u8, u8, s16, u8, int);

static u8 lbl_3_data_65F0[0x10] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 0x14, 5, 5, 5, 0xF, 0xF, 0 };
static u8 lbl_3_data_6600 = 8;
static u8 lbl_3_data_6604[0x2C] = {
    0x14, 0x14, 0x14, 0x3C, 0x3C, 0x3C, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
    0x50, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
    0x14, 0x14, 0x14, 0x14, 0x14, 0, 5, 5, 5, 0xF, 5, 5, 5, 0,
};
static u8 lbl_3_data_6630[2] = { 10, 30 };
static s16 lbl_3_data_6634[8] = { 0x30, 0x32, 0x32, 0x50, 0x50, 0x19, 0x25, 0x25 };
static s16 lbl_3_data_6644[3][3] = { { 0x13, 0x12, 0x11 }, { 0x19, 0x18, 0x17 }, { 0x16, 0x15, 0x14 } };
static u8 lbl_3_data_6658[4] = { 0x14 };
static s16 lbl_3_data_665C[2] = { 5, 0x14 };
u16 lbl_3_data_6660[87][2] = {
    { 0x16, 0x10 }, { 0x17, 0x11 }, { 0x18, 0x12 }, { 0x19, 0x13 }, { 0x1A, 0x14 }, { 0x1B, 0x15 },
    { 0x20, 0x1C }, { 0x21, 0x1D }, { 0x22, 0x1E }, { 0x23, 0x1F }, { 0x26, 0x25 }, { 0x28, 0x27 },
    { 0x3D, 0x3C }, { 0xFFFF, 0x0 }, { 0x4A, 0x4B }, { 0xFFFF, 0x0 }, { 0x2F, 0x34 }, { 0x30, 0x35 },
    { 0x31, 0x36 }, { 0x32, 0x37 }, { 0x33, 0x38 }, { 0xFFFF, 0x0 }, { 0x41, 0x47 }, { 0x42, 0x48 },
    { 0x43, 0x49 }, { 0x44, 0x4A }, { 0x45, 0x4B }, { 0x46, 0x4C }, { 0xFFFF, 0x0 }, { 0x2F, 0x34 },
    { 0xFFFF, 0x0 }, { 0x0, 0x1 }, { 0x2, 0x3 }, { 0x4, 0x5 }, { 0x6, 0x7 }, { 0x8, 0x9 },
    { 0xE, 0xF }, { 0xD, 0xC }, { 0xB, 0xA }, { 0x16, 0x17 }, { 0x18, 0x19 }, { 0x1A, 0x1B },
    { 0x10, 0x11 }, { 0x12, 0x13 }, { 0x14, 0x15 }, { 0x20, 0x21 }, { 0x22, 0x23 }, { 0x1C, 0x1D },
    { 0x1E, 0x1F }, { 0x24, 0x26 }, { 0x25, 0x28 }, { 0x27, 0x29 }, { 0x2A, 0x2B }, { 0x2C, 0x2D },
    { 0x2E, 0x2F }, { 0x30, 0x31 }, { 0x32, 0x33 }, { 0x34, 0x35 }, { 0x36, 0x37 }, { 0x38, 0x39 },
    { 0x3A, 0x3B }, { 0x3D, 0x3C }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 },
    { 0x1, 0x203 }, { 0x405, 0x607 }, { 0x809, 0xA0B }, { 0xC0D, 0xE }, { 0xF10, 0x1112 }, { 0x1314, 0x1516 },
    { 0x1700, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x100 }, { 0x0, 0x0 },
    { 0x100, 0x0 }, { 0x101, 0x101 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x1, 0x0 }, { 0x0, 0x101 },
    { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x101, 0x0 },
};

// The animation an actor plays, or 0xFFFF without an actor
static inline int getActorAnim(UnkE08Actor* actor) {
    if (actor != NULL) {
        return actor->_16A;
    }
    return 0xFFFF;
}

// Sets an actor's remaining frames from its animation's length
static inline void updateAnimLength(UnkE08Actor* actor) {
    f32 length;
    int animIndex;

    if (actor != NULL && actor->_25D != 0) {
        length = 1.0f;
        animIndex = getActorAnim(actor);
        if (animIndex != 0xFFFF) {
            length = fn_800B4A44(*fn_800111D8(actor), animIndex);
        }
        actor->_68 = length / actor->_4C;
    }
}

// Whether there is no actor or the actor has no model
#define ACTOR_HAS_NO_MODEL(actor) ((actor) == NULL || (actor)->_30 == NULL)

// The minigame player slot whose fielder is `fielder`, or 4 when none is
static inline s32 findMinigameSlot(s32 fielder) {
    s32 slot;

    for (slot = 0; slot < 4; slot++) {
        if (g_Minigame.minigameFielderIndex[slot] == fielder) {
            break;
        }
    }
    return slot;
}

// .text:0x000674E0 size:0x2C mapped:0x806A6574
void fn_3_674E0(void) {
    lbl_3_common_bss_32234[0] = 0;
    lbl_3_common_bss_32230._2 = 0;
    lbl_3_common_bss_32234[1] = 0;
    lbl_3_common_bss_32220._A = 0;
}

// .text:0x0006714C size:0x394 mapped:0x806A61E0
void fn_3_6714C(BOOL arg0) {
    s32 i;
    s32 slot;
    UnkE08Anim* anim;
    UnkE08Actor* actor;

    fn_8001C528();
    lbl_3_common_bss_32230._0 = 0;
    lbl_3_common_bss_32220._6 = 0;
    lbl_3_common_bss_32220._9 = 0;
    lbl_3_common_bss_32220._0 = 0;
    lbl_3_common_bss_32220._A = 0;
    lbl_3_common_bss_32220._D = 0;
    for (i = 0; i < 4; i++) {
        g_UnkThrowing_31ACC[i]._0E = 0;
    }
    for (i = 0; i < 9; i++) {
        anim = &g_UnkAnimation_31EAC[i];
        slot = i;
        if (g_d_GameSettings.minigamesEnabled) {
            for (slot = 0; slot < 4; slot++) {
                if (g_Minigame.minigameFielderIndex[slot] == i) {
                    break;
                }
            }
            if (slot >= 4) {
                continue;
            }
        }
        actor = lbl_8036E548._2C50[slot];
        anim->_38 = 0;
        anim->_3A = 0;
        anim->_42 = 0;
        anim->_43 = 0;
        anim->_44 = 0;
        anim->_46 = 0;
        anim->_47 = 0;
        anim->_4C = 0;
        anim->_4F = 0;
        anim->_50 = 0;
        anim->_51 = 0;
        anim->_00 = 0.0f;
        if (actor != NULL && ACTOR_HAS_NO_MODEL(actor)) {
            fn_3_60804(i, FALSE);
        }
    }
    if (lbl_8036E548._307D == 0) {
        for (i = 0; i < 4; i++) {
            if (!g_d_GameSettings.minigamesEnabled || (i == 0 && g_Minigame.rosterID >= 0) || g_Minigame._18FC[i] >= 0) {
                lbl_3_common_bss_321A0[i]._10 = -1;
                lbl_3_common_bss_321A0[i]._18 = 0;
                lbl_3_common_bss_321A0[i]._19 = 0;
                lbl_3_common_bss_321A0[i]._16 = 0;
            }
        }
    }
    fn_3_67130();
    if (!arg0) {
        lbl_3_common_bss_32234[0] = 1;
        fn_3_64BDC();
        fn_3_63AF8();
    }
    if (g_d_GameSettings.minigamesEnabled) {
        fn_3_62E70();
    } else {
        fn_3_62E70();
        fn_3_63A38();
    }
}

// .text:0x00067130 size:0x1C mapped:0x806A61C4
void fn_3_67130(void) {
    lbl_3_common_bss_32220._8 = 0;
    lbl_3_common_bss_32220._B = 0;
    lbl_3_common_bss_32220._4 = 0;
}

// .text:0x000668BC size:0x874 mapped:0x806A5950
// 99.62%: the target copies the actor pointer into a saved register right after its NULL
// test (mr r26,r4) and reads it through both; registers differ in that first loop.
void fn_3_668BC(void) {
    s32 i;
    s32 slot;
    s32 player;
    UnkE08Actor* actor;
    UnkE08Fielder* fielder;
    UnkE08Anim* anim;
    s16 state;

    if (g_GameLogic.gameStatus == 3 || g_GameLogic.gameStatus == 5) {
        return;
    }
    for (i = 0; i < 13; i++) {
        lbl_8036E548._0C04[i]._274 = 0;
    }
    if (g_d_GameSettings.minigamesEnabled) {
        if (g_GameLogic.gameStatus >= 0x1B && g_GameLogic.gameStatus <= 0x21) {
            return;
        }
        if (g_GameLogic.gameStatus == 5) {
            return;
        }
    }
    for (i = 0; i < 13; i++) {
        actor = lbl_8036E548._2C50[i];
        updateAnimLength(actor);
    }
    if (g_Stats.replayInd != 0 && g_Stats.playFrameCounter == 1 && lbl_8036E548._2C50[9] != NULL && g_Stats._34 != 0) {
        lbl_8036E548._2C50[9]->_68 = g_Stats._34 - 1;
        lbl_8036E548._2C50[9]->_70 = g_Stats._34 - 1;
    }
    for (i = 0; i < 9; i++) {
        fielder = &g_Fielders[i];
        anim = &g_UnkAnimation_31EAC[i];
        player = i;
        actor = lbl_8036E548._2C50[i];
        anim->_1C.x = anim->_10.x;
        fielder->_20A = 0;
        anim->_1C.y = anim->_10.y;
        anim->_1C.z = anim->_10.z;
        if (g_d_GameSettings.minigamesEnabled) {
            slot = findMinigameSlot(i);
            if (slot >= 4) {
                continue;
            }
            player = g_Minigame.minigameControlStruct.characterIndex[slot];
            actor = lbl_8036E548._2C50[slot];
        }
        if (anim->_50 != 0) {
            fielder->_1EC = 1;
        } else {
            fielder->_1EC = 0;
        }
        if (anim->_4F != 0 && fielder->_24C <= 1) {
            fielder->_1ED = 1;
        } else {
            fielder->_1ED = 0;
        }
        if (actor != NULL) {
            if (anim->_42 != 0) {
                getAnimRelatedCoordinates(player, 4, &anim->_2C);
                fielder->_030 = anim->_2C.x - fielder->_000.x;
                fielder->_034 = anim->_2C.z - fielder->_000.z;
                fielder->_050 = dolsqrtf2(fielder->_030 * fielder->_030 + fielder->_034 * fielder->_034);
                fielder->_000.x = anim->_2C.x;
                fielder->_000.z = anim->_2C.z;
                fielder->_1FB = 1;
                fn_3_60A98(i, actor);
            } else {
                fielder->_1FB = 0;
                if (fielder->_050 > fielder->_058) {
                    fielder->_050 = fielder->_058;
                }
            }
        }
        fielder->_1F9 = anim->_43;
        fielder->_25A = 0;
        if (anim->_4F != 0 && anim->_4D != 0) {
            switch (anim->_4D) {
            case 1:
            case 2:
                fielder->_25A = 1;
                break;
            case 3:
                fielder->_25A = 2;
                break;
            }
        }
        if (anim->_44 != 0) {
            fielder->_1FD = 1;
            if (fielder->_1AA < 0x7FFE) {
                fielder->_1AA++;
            } else {
                fielder->_1AA = 0x7FFF;
            }
        } else {
            fielder->_1FD = 0;
            fielder->_1AA = 0;
        }
        if (actor != NULL && actor->_62 == 0xF) {
            fielder->_1FE = 1;
        } else {
            fielder->_1FE = 0;
        }
        anim->_3C = fn_8001B35C(player, 1);
        anim->_3E = fn_8001B35C(player, 0);
    }
    if (g_FieldingLogic._117 != 0) {
        player = 0;
        actor = lbl_8036E548._2C50[0];
        if (g_d_GameSettings.minigamesEnabled) {
            player = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
            actor = lbl_8036E548._2C50[player];
        }
        getAnimRelatedCoordinates(player, 4, &g_UnkAnimation_31EAC[0]._2C);
        g_Pitcher.pitcherCoord.x = g_UnkAnimation_31EAC[0]._2C.x;
        g_Pitcher.pitcherCoord.z = g_UnkAnimation_31EAC[0]._2C.z;
        if (actor != NULL) {
            state = actor->_62;
            if (state == 0x40 || state == 0x42 || (state == 0x41 && actor->_68 < 30) ||
                (state == 0x43 && actor->_68 < 30)) {
                g_Pitcher.pitchDeliveryAnimationPlaying = 1;
            } else {
                g_Pitcher.pitchDeliveryAnimationPlaying = 0;
            }
        } else {
            g_Pitcher.pitchDeliveryAnimationPlaying = 0;
        }
    }
    if (lbl_8036E548._307D == 0) {
        actor = lbl_8036E548._2C50[9];
        if (g_d_GameSettings.minigamesEnabled) {
            actor = &lbl_8036E548._0C04[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.rosterID]];
        }
        if (lbl_3_common_bss_32220._8 == 0) {
            if (actor != NULL && (actor->_62 == 0x4B || actor->_62 == 0x66)) {
                g_Batter.noSwingAnimationInd = 1;
            } else {
                g_Batter.noSwingAnimationInd = 0;
            }
        }
        if (actor != NULL) {
            if (actor->_62 == 0x67) {
                g_Batter.beginningOfABAnimationOccuring = 1;
            } else {
                g_Batter.beginningOfABAnimationOccuring = 0;
            }
            if (g_GameLogic.gameStatus == 1 || g_GameLogic.gameStatus == 2) {
                if (actor->_62 == 0x4D) {
                    lbl_3_common_bss_32220._A = 1;
                    lbl_3_common_bss_32220._2++;
                } else if (actor->_62 == 0x53) {
                    lbl_3_common_bss_32220._A = 2;
                    lbl_3_common_bss_32220._2++;
                } else if (actor->_62 == 0x50) {
                    lbl_3_common_bss_32220._A = 3;
                    lbl_3_common_bss_32220._2++;
                } else if (actor->_62 == 0x54) {
                    lbl_3_common_bss_32220._A = 4;
                    lbl_3_common_bss_32220._2++;
                } else if (lbl_3_common_bss_32220._A != 0) {
                    if (lbl_3_common_bss_32220._A == 9) {
                        lbl_3_common_bss_32220._A = 0;
                    } else {
                        lbl_3_common_bss_32220._A = 9;
                        lbl_3_common_bss_32220._2 = 0;
                    }
                }
            }
            state = actor->_62;
            if (state == 0x5E || state == 0x62 || state == 0x5F || state == 0x60 || state == 0x61) {
                lbl_3_common_bss_32220._6 = actor->_68;
            }
        }
    }
}

// .text:0x000664FC size:0x3C0 mapped:0x806A5590
void fn_3_664FC(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        g_UnkAnimation_31EAC[i]._48 = 0;
    }
    if (g_GameLogic.gameStatus == 0xB || g_GameLogic.gameStatus == 3 || g_GameLogic.gameStatus == 4 ||
        g_GameLogic.gameStatus == 5 || g_GameLogic.secondaryGameMode == 0xA || g_GameLogic.secondaryGameMode == 0x12 ||
        (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice.tutorialState == 0)) {
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_GameLogic.secondaryGameMode == 0xA &&
            g_Practice.practiceType_1 == 6) {
            fn_3_65FE0();
        } else {
            for (i = 0; i < 13; i++) {
                AnimateCharacter(i, 2, 1, 1, 0, 0, 0, 0);
            }
        }
    } else if (g_GameLogic.gameStatus == 0xE) {
        if (g_GameLogic._125 > 2) {
            fn_3_657E4();
        }
    } else if (lbl_3_common_bss_1323C._0->_25C != 0) {
        fn_3_22C10();
    } else if (lbl_3_common_bss_32234[1] != 0) {
        fn_3_6714C(FALSE);
        lbl_3_common_bss_32234[1] = 0;
    } else if (g_GameLogic.minigameLastTurnSuccessInd != 0 && g_Ball.totalFramesAtPlay == 0) {
        fn_3_6714C(FALSE);
    } else {
        lbl_3_common_bss_32234[0] = 0;
        fn_3_64BDC();
        fn_3_63AF8();
        fn_3_62E70();
        fn_3_63A38();
    }
}

// .text:0x00066140 size:0x3BC mapped:0x806A51D4
void fn_3_66140(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        g_UnkAnimation_31EAC[i]._48 = 0;
    }
    if (g_Minigame._19A9 != 0 || g_GameLogic.gameStatus == 0x22 || g_GameLogic.gameStatus == 0x26 ||
        g_GameLogic.gameStatus == 0x27) {
        fn_3_657E4();
    } else if (g_GameLogic.gameStatus >= 0x1B && g_GameLogic.gameStatus <= 0x29) {
        fn_3_65FE0();
    } else if ((g_GameLogic.gameStatus == 3 || g_GameLogic.gameStatus == 4 || g_GameLogic.gameStatus == 5 ||
                 g_GameLogic.gameStatus == 6 || g_GameLogic.gameStatus == 7 || g_GameLogic.secondaryGameMode == 0xA ||
                g_GameLogic.secondaryGameMode == 0x12 || g_GameLogic.secondaryGameMode == 0xF) &&
               (g_Minigame.GameMode_MiniGame != 2 || g_GameLogic.gameStatus != 7)) {
        for (i = 0; i < 4; i++) {
            AnimateCharacter(i, 2, 1, 1, 0, 0, 0, 0);
        }
    } else if (lbl_803CBC3C[0] == 0) {
        if (lbl_3_common_bss_32234[1] != 0) {
            fn_3_6714C(FALSE);
            lbl_3_common_bss_32234[1] = 0;
        } else {
            if (g_GameLogic.minigameLastTurnSuccessInd != 0 && g_Ball.totalFramesAtPlay == 0) {
                if (g_Minigame.GameMode_MiniGame == 2 && g_Minigame.soloMinigameDifficulty == 3) {
                    lbl_3_common_bss_32234[0] = 0;
                } else {
                    fn_3_6714C(FALSE);
                    return;
                }
            } else {
                lbl_3_common_bss_32234[0] = 0;
            }
            fn_3_64BDC();
            fn_3_63AF8();
            fn_3_62E70();
            fn_3_63A38();
        }
    }
}

// .text:0x00065FE0 size:0x160 mapped:0x806A5074
void fn_3_65FE0(void) {
    BOOL flag;
    UnkE08Actor* actor;
    s32 i;
    s32 actorIdx;

    for (i = 0; i < 4; i++) {
        actorIdx = i;
        actor = lbl_8036E548._2C50[i];
        flag = FALSE;
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
            actorIdx = 9;
            actor = lbl_8036E548._2C50[9];
        }
        if (actor == NULL) {
            continue;
        }
        if (g_Minigame._19E8[i]._4 == 0 || g_Minigame._19E8[i]._4 == 2) {
            flag = TRUE;
        }
        if (g_Minigame._19E8[i]._2 < 0) {
            AnimateCharacter(actorIdx, 0x69, 1, 1, 1, 0, flag, 0);
        } else if (g_Minigame._19E8[i]._1 != 0) {
            if (actor->_62 == 0x69) {
                AnimateCharacter(actorIdx, 0x6A, 0, 1, 1, 0, flag, 0);
                QueueCharacterAnimation(actorIdx, 0x6B, 1, 1, 0, flag, -1);
            }
        } else {
            AnimateCharacter(actorIdx, 0x69, 1, 1, 1, 0, flag, 0);
        }
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
            break;
        }
    }
}

// .text:0x000657E4 size:0x7FC mapped:0x806A4878
void fn_3_657E4(void) {
    BOOL ended;
    BOOL flag;
    s32 i;
    s32 actor;
    s32 charID;
    s8 winner;

    ended = FALSE;
    if (g_GameLogic.gameStatus == 0xE) {
        if (g_d_GameSettings.minigamesEnabled && g_GameLogic._125 == 1) {
            ended = TRUE;
        }
        if (!g_d_GameSettings.minigamesEnabled && g_GameLogic._125 == 3) {
            ended = TRUE;
        }
    }
    if (g_GameLogic.gameStatus == 0x27 && g_GameLogic._125 == 0) {
        ended = TRUE;
    }
    if (ended) {
        if (!g_d_GameSettings.minigamesEnabled) {
            if (lbl_80353A90._104 == 2) {
                lbl_3_common_bss_32234[2] = 1;
            } else if (lbl_80353A90._104 == 3) {
                lbl_3_common_bss_32234[2] = 2;
            } else {
                lbl_3_common_bss_32234[2] = 0;
            }
        } else if (g_GameLogic.gameStatus == 0x27 && g_Minigame._1A3D == 1) {
            winner = g_Minigame._1908;
            flag = FALSE;
            for (i = 0; i < 4; i++) {
                if (g_Minigame._1E08[i][0] == winner && g_Minigame._1E08[i][1] == 0) {
                    flag = TRUE;
                    break;
                }
            }
            if (g_Minigame._1E08[0][1] == 0 && g_Minigame._1E08[1][1] == 0 && g_Minigame._1E08[2][1] == 0 &&
                g_Minigame._1E08[3][1] == 0) {
                lbl_3_common_bss_32234[2 + g_Minigame._1908] = 2;
            } else if (flag) {
                lbl_3_common_bss_32234[2 + g_Minigame._1908] = 0;
            } else {
                lbl_3_common_bss_32234[2 + g_Minigame._1908] = 1;
            }
        } else if (g_Minigame.miniGameNumberOfParticipants == 1) {
            for (i = 0; i < 4; i++) {
                if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                    if (g_Minigame.soloMinigameDifficulty == 3) {
                        if (g_Minigame._19AA != 0) {
                            lbl_3_common_bss_32234[2 + i] = 0;
                        } else {
                            lbl_3_common_bss_32234[2 + i] = 1;
                        }
                    } else if (g_Minigame._1A37 == 1) {
                        lbl_3_common_bss_32234[2 + i] = 0;
                    } else {
                        lbl_3_common_bss_32234[2 + i] = 1;
                    }
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                    if (g_Minigame.challenge_minigame_haven_tWonYetIndicator) {
                        lbl_3_common_bss_32234[2 + i] = 2;
                    } else if (g_Minigame.minigameControlStruct._1C[i] == 1) {
                        lbl_3_common_bss_32234[2 + i] = 0;
                    } else {
                        lbl_3_common_bss_32234[2 + i] = 1;
                    }
                }
            }
        }
    }
    if ((!g_d_GameSettings.minigamesEnabled && g_GameLogic._125 < 4) ||
        (g_d_GameSettings.minigamesEnabled && g_Minigame._19A9 <= 1)) {
        for (i = 0; i < 4; i++) {
            if (!g_d_GameSettings.minigamesEnabled) {
                actor = 9;
            } else {
                if (g_Minigame.minigameControlStruct.characterIndex[i] < 0) {
                    continue;
                }
                actor = g_Minigame.minigameControlStruct.characterIndex[i];
            }
            if (!g_d_GameSettings.minigamesEnabled) {
                flag = TRUE;
            } else if (g_Minigame._19E8[i]._4 == 0 || g_Minigame._19E8[i]._4 == 2) {
                flag = TRUE;
            } else {
                flag = FALSE;
            }
            if (lbl_3_common_bss_32234[2 + i] == 0) {
                AnimateCharacter(actor, 0x69, 1, 1, 1, 0, flag, 0);
            } else if (lbl_3_common_bss_32234[2 + i] == 1) {
                AnimateCharacter(actor, 0x6F, 1, 1, 1, 0, flag, 0);
            } else {
                AnimateCharacter(actor, 0x72, 1, 1, 1, 0, flag, 0);
            }
            if (!g_d_GameSettings.minigamesEnabled) {
                break;
            }
        }
    } else if ((!g_d_GameSettings.minigamesEnabled && g_GameLogic._125 == 4 &&
                g_GameLogic.FrameCountOfCurrentAtBat_Copy == 1) ||
               (g_d_GameSettings.minigamesEnabled && g_Minigame._19A9 == 2) ||
               (g_GameLogic.gameStatus == 0x27 && g_GameLogic._125 == 0)) {
        g_Minigame._19A9 = 3;
        for (i = 0; i < 4; i++) {
            if (!g_d_GameSettings.minigamesEnabled) {
                actor = 9;
            } else {
                if (g_Minigame.minigameControlStruct.characterIndex[i] < 0) {
                    continue;
                }
                actor = g_Minigame.minigameControlStruct.characterIndex[i];
            }
            if (g_GameLogic.gameStatus == 0x27 && g_Minigame._1908 >= 0 && g_Minigame._1908 != i) {
                continue;
            }
            if (!g_d_GameSettings.minigamesEnabled) {
                flag = TRUE;
                charID = lbl_80353A90._103;
            } else if (g_Minigame._19E8[i]._4 == 0 || g_Minigame._19E8[i]._4 == 2) {
                flag = TRUE;
                charID = g_Minigame.minigameControlStruct._4[i];
            } else {
                flag = FALSE;
                charID = g_Minigame.minigameControlStruct._4[i];
            }
            if (lbl_3_common_bss_32234[2 + i] == 0) {
                AnimateCharacter(actor, 0x6D, 0, 1, 1, 0, flag, -1);
                QueueCharacterAnimation(actor, 0x6B, 1, 1, 0, flag, -1);
                fn_3_90220(charID, 7);
            } else if (lbl_3_common_bss_32234[2 + i] == 1) {
                AnimateCharacter(actor, 0x70, 0, 1, 1, 0, flag, -1);
                QueueCharacterAnimation(actor, 0x71, 1, 1, 0, flag, -1);
                if (g_Minigame.miniGameNumberOfParticipants > 1) {
                    fn_3_90150(charID, 9);
                } else {
                    fn_3_90220(charID, 9);
                }
            } else {
                AnimateCharacter(actor, 0x73, 0, 1, 1, 0, flag, -1);
                QueueCharacterAnimation(actor, 0x74, 1, 1, 0, flag, -1);
            }
            if (!g_d_GameSettings.minigamesEnabled) {
                break;
            }
        }
    }
}

// .text:0x00064BDC size:0xC08 mapped:0x806A3C70
void fn_3_64BDC(void) {
    VecSrcDst line;
    CollisionStruct hit;
    s32 kind;
    s32 player;
    UnkE08Actor* actor;
    s32 windup;
    u8 lefty;
    s32 speed;
    s16 counter;

    player = 0;
    lefty = FALSE;
    if (g_Pitcher.handedness != 0) {
        lefty = TRUE;
    }
    if (g_d_GameSettings.minigamesEnabled) {
        if (g_Minigame.minigamePlayerSelectedOrder < 0) {
            return;
        }
        player = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
    }
    actor = lbl_8036E548._2C50[player];
    if (actor != NULL) {
        if (actor->_62 == 0x44 && actor->_6A == 1) {
            fn_3_90220(actor->_252, 4);
        } else if (actor->_62 == 0x45 && actor->_6A == 1) {
            fn_3_90220(actor->_252, 3);
        }
    }
    if (g_GameLogic.gameStatus != 0 && (u8)(g_GameLogic.gameStatus - 1) > 1 && g_GameLogic.gameStatus != 0x16 &&
        (g_Minigame.GameMode_MiniGame != 2 || g_GameLogic.gameStatus != 7) &&
        (g_GameLogic.gameStatus != 0xB || lbl_3_common_bss_32234[0] == 0)) {
        if (g_d_GameSettings.minigamesEnabled && g_GameLogic.gameStatus == 0x1A) {
            AnimateCharacter(player, 0x3F, 1, 2, 1, 0, lefty, -1);
            lbl_3_common_bss_32230._2 = 1;
            return;
        }
        lbl_3_common_bss_32230._2 = 0;
        return;
    }
    if (g_GameLogic.secondaryGameMode == 0xB && g_Practice.instructionNumber < 0 && g_Practice._1C7 != 0) {
        return;
    }
    if (g_d_GameSettings.GameModeSelected == 2 && g_Practice.practiceLevel == 4) {
        return;
    }
    if (g_FieldingLogic._107 != 0) {
        lbl_3_common_bss_32230._2 = 0;
        return;
    }
    if (g_Minigame.GameMode_MiniGame == 2) {
        if (g_Minigame.wallBallRotatePitchersInd != 0) {
            return;
        }
        player = g_Minigame.minigamePlayerSelectedOrder;
    }
    if (lbl_3_common_bss_32234[0] != 0) {
        kind = 0;
        if (g_d_GameSettings.GameModeSelected != 2 && !g_d_GameSettings.minigamesEnabled) {
            if (g_Pitcher.playStartOfGameAnimation != 0) {
                g_Pitcher.playStartOfGameAnimation = 0;
                kind = 1;
                if (fn_3_6D564(g_GameLogic.teamFielding, g_Pitcher.rosterID, 0) < lbl_3_data_5EDC[3]) {
                    kind = 2;
                }
            } else if (g_Pitcher.nPitchesThisAB == 0 && g_Pitcher.nPickoffAttempts == 0 &&
                       fn_3_6D564(g_GameLogic.teamFielding, g_Pitcher.rosterID, 0) < lbl_3_data_5EDC[3]) {
                kind = 2;
            }
        }
        if (kind == 2) {
            AnimateCharacter(player, 0x46, 0, 1, 1, 0, lefty, 0);
            QueueCharacterAnimation(player, 0x3F, 1, 1, 0, lefty, -1);
        } else if (kind == 1) {
            AnimateCharacter(player, 0x48, 0, 1, 1, 0, lefty, 0);
            QueueCharacterAnimation(player, 0x3F, 1, 1, 0, lefty, -1);
        } else {
            AnimateCharacter(player, 0x3F, 1, 1, 1, 0, lefty, 0);
            lbl_3_common_bss_32230._2 = 1;
        }
        return;
    }
    if (g_Pitcher.pitchTotalTimeCounter == 0) {
        if (lbl_3_common_bss_32230._2 != 1 &&
            (g_GameLogic.secondaryGameMode != 0xB || g_Practice.instructionNumber >= 0 ||
             g_Practice.guidedPracticeCompletionRelated == 0) &&
            actor->_64 != 0x41 && actor->_64 != 0x43) {
            if (g_Minigame.GameMode_MiniGame == 2) {
                if (g_Minigame.soloMinigameDifficulty != 3) {
                    AnimateCharacter(player, 0x3F, 1, 1, 1, 0, lefty, 0xC);
                } else if (g_Minigame.miniGameTurnCounter == 0) {
                    AnimateCharacter(player, 0x3F, 1, 1, 1, 0, lefty, 0xC);
                } else {
                    AnimateCharacter(player, 0x3F, 1, 2, 1, 0, lefty, 0xC);
                }
            } else {
                AnimateCharacter(player, 0x3F, 1, 2, 1, 0, lefty, 0xC);
            }
        }
        lbl_3_common_bss_32230._2 = 1;
        if (g_d_GameSettings.GameModeSelected != 2 && (u8)(g_d_GameSettings.GameModeSelected - 6) > 1) {
            counter = 0x7FFF;
            if (lbl_3_common_bss_32230._0 < 0x7FFE) {
                counter = lbl_3_common_bss_32230._0 + 1;
            }
            lbl_3_common_bss_32230._0 = counter;
            if (counter > 0x244 && g_Ball.StaticRandomInt1 % 120 == 0) {
                lbl_3_common_bss_32230._0 = 0;
                AnimateCharacter(player, 0x47, 0, 2, 1, 0, lefty, -1);
                QueueCharacterAnimation(player, 0x3F, 1, 1, 0, lefty, 0xC);
            }
        }
        return;
    }
    lbl_3_common_bss_32230._0 = 0;
    if (g_Pitcher.pitchTotalTimeCounter == 1) {
        windup = 1;
        if (g_Pitcher.ChargePitchType >= 1 || g_Pitcher.TypeOfPitch != 0) {
            AnimateCharacter(player, 0x40, 0, 1, 1, 0, lefty, -1);
            windup = 0;
            g_Pitcher.windupCountdownUntilBallReleased = g_Pitcher.pitchWindUpCountDown;
        } else {
            AnimateCharacter(player, 0x42, 0, 1, 1, 0, lefty, -1);
            g_Pitcher.windupCountdownUntilBallReleased = g_Pitcher.curvePitchWindupFrames;
        }
        if (actor->_252 == 0xB || actor->_252 == 0x1B) {
            windup = 0;
        }
        if (actor->_252 == 3 || actor->_252 == 0xE || actor->_252 == 0x25 || actor->_252 == 0x26 ||
            lbl_800E8558[actor->_252]._2 == 0x17) {
            QueueCharacterAnimation(player, 0x3F, 1, 1, 0, lefty, 0xC);
        } else {
            QueueCharacterAnimation(player, windup + 0x49, 1, 1, 0, lefty, -1);
        }
        lbl_3_common_bss_32230._2 = 2;
        return;
    }
    if (g_Minigame.GameMode_MiniGame == 2 && g_Minigame.soloMinigameDifficulty == 3) {
        if (g_Minigame._1A8C[0] != 0) {
            if (actor->_62 == 0x40) {
                AnimateCharacter(player, 0x41, 0, 1, 1, 0, lefty, -1);
            } else {
                AnimateCharacter(player, 0x43, 0, 1, 1, 0, lefty, -1);
            }
            QueueCharacterAnimation(player, 0x3F, 1, 1, 0, lefty, 0xC);
            lbl_3_common_bss_32230._2 = 3;
            g_Minigame._1A8C[0] = 0;
        }
        return;
    }
    if (g_Pitcher.pitcherActionState == 4 && g_Ball.postPitchResultCounter > 1 && lbl_3_common_bss_32230._2 != 3) {
        if (g_Minigame.GameMode_MiniGame != 2 || g_Minigame.soloMinigameDifficulty == 3) {
            if (g_GameLogic.secondaryGameMode == 0xB && g_Practice.instructionNumber < 0 &&
                g_Practice.guidedPracticeCompletionRelated != 0) {
                if (lbl_3_common_bss_32230._2 != 4) {
                    AnimateCharacter(player, 0x44, 0, 2, 1, 0, lefty, -1);
                }
                lbl_3_common_bss_32230._2 = 4;
                return;
            }
            if (g_Pitcher.miniGameRelated != 0) {
                if (actor->_252 == 3 || actor->_252 == 0xE || actor->_252 == 0x25 || actor->_252 == 0x26 ||
                    lbl_800E8558[actor->_252]._2 == 0x17) {
                    AnimateCharacter(player, 0x3F, 1, 2, 1, 0, lefty, 0xC);
                    lbl_3_common_bss_32230._2 = 3;
                    return;
                }
                if (actor->_62 == 0x40 || actor->_62 == 0x42) {
                    speed = 2;
                } else {
                    speed = 1;
                }
                if (actor->_62 == 0x40 || actor->_62 == 0x49) {
                    AnimateCharacter(player, 0x41, 0, speed, 1, 0, lefty, 0xC);
                } else {
                    AnimateCharacter(player, 0x43, 0, speed, 1, 0, lefty, 0xC);
                }
                QueueCharacterAnimation(player, 0x3F, 1, 1, 0, lefty, 0xC);
                lbl_3_common_bss_32230._2 = 3;
            }
        }
    } else if (g_Pitcher.pitcherActionState == 5 &&
               ((g_Pitcher.strikeOutOrWalk == 1 && lbl_3_common_bss_32230._2 != 4) ||
                ((g_Pitcher.strikeOutOrWalk == 2 || g_Pitcher.strikeOutOrWalk == 3) && lbl_3_common_bss_32230._2 != 5)) &&
               (actor->_68 == 0 || actor->_62 == 0x49 || actor->_62 == 0x4A)) {
        if (g_Pitcher.strikeOutOrWalk == 1) {
            if (lbl_800E8558[actor->_252]._2 == 0xB) {
                AnimateCharacter(player, 0x44, 0, 1, 1, 0, lefty, 0);
            } else {
                AnimateCharacter(player, 0x44, 0, 1, 1, 0, lefty, -1);
            }
            lbl_3_common_bss_32230._2 = 4;
        } else {
            AnimateCharacter(player, 0x45, 0, 1, 1, 0, lefty, -1);
            lbl_3_common_bss_32230._2 = 5;
        }
        g_Pitcher.pitcher.x = g_UnkAnimation_31EAC[0]._2C.x;
        g_Pitcher.pitcher.z = g_UnkAnimation_31EAC[0]._2C.z;
        if (g_d_GameSettings.minigamesEnabled) {
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigamePlayerSelectedOrder]]._000.x =
                g_Pitcher.pitcher.x;
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigamePlayerSelectedOrder]]._000.z =
                g_Pitcher.pitcher.z;
        } else {
            g_Fielders[0]._000.x = g_Pitcher.pitcher.x;
            g_Fielders[0]._000.z = g_Pitcher.pitcher.z;
        }
        line.src.x = g_Fielders[0]._000.x;
        line.src.y = -1.0f;
        line.src.z = g_Fielders[0]._000.z;
        line.dst.x = g_Fielders[0]._000.x;
        line.dst.y = 1.0f;
        line.dst.z = g_Fielders[0]._000.z;
        checkCollision(&line, &hit, 0, FALSE);
        g_Fielders[0]._00C = -hit.position.y;
        g_Fielders[0]._010 = g_Fielders[0]._00C;
    }
}

// .text:0x00063AF8 size:0x10E4 mapped:0x806A2B8C
void fn_3_63AF8(void) {
    UnkE08Actor* actor;
    s32 i;
    s32 player;
    BOOL forced;
    BOOL ended;
    BOOL walkup;
    s16 counter;
    u8 lefty;

    player = 9;
    lefty = g_Batter.batterHand ^ 1;
    if (lbl_8036E548._307D != 0) {
        return;
    }
    if (g_d_GameSettings.minigamesEnabled) {
        if (g_Minigame.rosterID < 0) {
            return;
        }
        player = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.rosterID];
    }
    actor = lbl_8036E548._2C50[player];
    if (actor == NULL) {
        return;
    }
    if ((actor->_62 == 0x5D || actor->_62 == 0x5E || actor->_62 == 0x5F || actor->_62 == 0x60) && actor->_6A == 1) {
        fn_3_90220(actor->_252, 0xA);
    }
    if (actor->_62 == 0x52 || actor->_62 == 0x65) {
        lbl_3_common_bss_32220._8 = 4;
    }
    if (lbl_3_common_bss_32220._8 == 0) {
        if (g_FieldingLogic._107 == 1 || g_FieldingLogic._107 == 2 || g_FieldingLogic._107 == 3) {
            if (g_Strikes.outs < 3) {
                AnimateCharacter(player, 0x65, 1, 1, 1, 0, lefty, 0xA);
            }
        } else {
            if (lbl_3_common_bss_32234[0] == 0) {
                if (g_Runners[0].batterStayInBattersBoxReason == 0) {
                    goto end;
                }
                if (g_Runners[0].batterStayInBattersBoxReason >= 2) {
                    if (lbl_3_common_bss_32220._9 == 0) {
                        if (g_Batter.hitTrajectory == 2) {
                            lbl_3_common_bss_32220._9 = 1;
                        } else if (g_Batter.hitTrajectory == 5) {
                            if (g_Ball.framesSinceHit >= 5) {
                                lbl_3_common_bss_32220._9 = 1;
                            }
                        } else if (g_Batter.hitTrajectory == 6) {
                            AnimateCharacter(player, 0x64, 0, 2, 1, 0, lefty, -1);
                            lbl_3_common_bss_32220._9 = 1;
                        } else if (g_Batter.hitTrajectory == 3) {
                            AnimateCharacter(player, 0x63, 0, 2, 1, 0, lefty, -1);
                            lbl_3_common_bss_32220._9 = 1;
                        } else if (g_Batter.hitTrajectory == 4) {
                            AnimateCharacter(player, 0x51, 0, 2, 1, 8, lefty, 0);
                            QueueCharacterAnimation(player, 0x52, 1, 1, 0, lefty, -1);
                            lbl_3_common_bss_32220._9 = 1;
                        }
                    }
                    goto end;
                }
            }
            if (lbl_3_common_bss_32234[0] != 0) {
                walkup = FALSE;
                if (g_d_GameSettings.GameModeSelected != 2) {
                    if (g_d_GameSettings.GameModeSelected == 6) {
                        if (g_Minigame._19A5 != 0) {
                            walkup = TRUE;
                            g_Minigame._19A5 = 0;
                        }
                    } else if (g_Pitcher.nPitchesThisAB == 0 && g_Pitcher.nPickoffAttempts == 0 &&
                               g_GameLogic.playBatterWalkupAnimation == 1) {
                        walkup = TRUE;
                    }
                }
                if (g_GameLogic.scoutFlag_VsScreenInd != 0) {
                    walkup = FALSE;
                }
                if (walkup) {
                    AnimateCharacter(player, 0x67, 0, 1, 1, 0, lefty, 0);
                    QueueCharacterAnimation(player, 0x4B, 1, 1, 0, lefty, 0);
                } else {
                    AnimateCharacter(player, 0x4B, 1, 2, 1, 0, lefty, 0);
                    lbl_3_common_bss_32220._9 = 0;
                    lbl_3_common_bss_32220._0 = 0;
                }
            } else {
                if ((g_Ball.totalFramesAtPlay == 3 || g_GameLogic.gameStatus == 0) && g_Batter.swingInd == 0 &&
                    g_Batter.buntStatus == 0) {
                    AnimateCharacter(player, 0x4B, 1, 2, 1, 0, lefty, 0xA);
                    lbl_3_common_bss_32220._9 = 0;
                    lbl_3_common_bss_32220._0 = 0;
                }
                if (g_Pitcher.pitchTotalTimeCounter == 0) {
                    if (g_Batter.swingInd != 0 || g_Batter.buntStatus != 0) {
                        lbl_3_common_bss_32220._0 = 0;
                    }
                    if (g_d_GameSettings.GameModeSelected != 2 && g_d_GameSettings.GameModeSelected != 7) {
                        counter = 0x7FFF;
                        if (lbl_3_common_bss_32220._0 < 0x7FFE) {
                            counter = lbl_3_common_bss_32220._0 + 1;
                        }
                        lbl_3_common_bss_32220._0 = counter;
                        if (counter > 0x258 && g_Batter.chargeStatus == 0 && g_Ball.StaticRandomInt1 % 120 == 0) {
                            lbl_3_common_bss_32220._0 = 0;
                            AnimateCharacter(player, 0x66, 0, 2, 1, 0, lefty, -1);
                            QueueCharacterAnimation(player, 0x4B, 1, 1, 0, lefty, 0xF);
                        }
                    }
                }
                if (g_Batter.chargeStatus != 0 && g_Batter.swingInd == 0) {
                    if (g_Pitcher.pitcherActionState != 5) {
                        if (g_Batter.chargeStatus == 3) {
                            if (actor->_62 != 0x58 && actor->_62 != 0x68 && actor->_62 != 0x4B) {
                                if (actor->_62 == 0x55) {
                                    AnimateCharacter(player, 0x58, 1, 1, 1, 0, lefty, 0x14);
                                    QueueCharacterAnimation(player, 0x4B, 1, 1, 0, lefty, 0xC);
                                } else {
                                    AnimateCharacter(player, 0x68, 0, 1, 1, 0, lefty, 0x14);
                                    QueueCharacterAnimation(player, 0x4B, 1, 1, 0, lefty, 0xC);
                                }
                            }
                        } else if (g_Batter.chargeStatus == 1 && g_Batter.chargeFrames == 1) {
                            if (actor->_62 == 0x4B) {
                                AnimateCharacter(player, 0x4C, 0, 3, 1, g_Batter.chargeFrames, lefty, 0x14);
                            } else {
                                AnimateCharacter(player, 0x4C, 0, 3, 1, g_Batter.chargeFrames, lefty, 0);
                            }
                            QueueCharacterAnimation(player, 0x55, 1, 1, 0, lefty, 0xC);
                        }
                    }
                } else if (lbl_3_common_bss_32220._B != 0) {
                    if (g_Pitcher.pitcherActionState == 4 && g_Ball.postPitchResultCounter >= 3) {
                        lbl_3_common_bss_32220._B = 0;
                        if (actor->_62 == 0x55) {
                            AnimateCharacter(player, 0x58, 0, 1, 1, 0, lefty, 0x14);
                            QueueCharacterAnimation(player, 0x4B, 1, 1, 0, lefty, -1);
                        } else {
                            AnimateCharacter(player, 0x68, 0, 1, 1, 0, lefty, 0x14);
                            QueueCharacterAnimation(player, 0x4B, 1, 1, 0, lefty, 0xC);
                        }
                    } else {
                        lbl_3_common_bss_32220._4++;
                    }
                } else if (g_Pitcher.pitcherActionState == 2 && g_Batter.buntStatus == 0 && g_Batter.swingInd == 0 &&
                           g_Pitcher.windupCountdownUntilBallReleased <= 8) {
                    AnimateCharacter(player, 0x57, 0, 3, 1, 0, lefty, 0x14);
                    QueueCharacterAnimation(player, 0x56, 1, 1, 0, lefty, 0);
                    lbl_3_common_bss_32220._B = 1;
                    lbl_3_common_bss_32220._4 = 0;
                }
                if (g_Batter.buntStatus != 0) {
                    lbl_3_common_bss_32220._B = 0;
                    if (g_Pitcher.strikeOutOrWalk != 2) {
                        if (g_Batter.missedBuntStatus == 1) {
                            AnimateCharacter(player, 0x5C, 0, 1, 1, 0, lefty, -1);
                            QueueCharacterAnimation(player, 0x4B, 1, 1, 0, lefty, 0xA);
                        } else if (g_Batter.buntStatus == 1) {
                            if (g_Pitcher.framesUntilUnhittable > 5 && g_Pitcher.framesUntilUnhittable < 0xF) {
                                AnimateCharacter(player, 0x59, 0, 1, 1, 5, lefty, -1);
                                goto skip;
                            } else {
                                AnimateCharacter(player, 0x59, 0, 1, 1, 0, lefty, -1);
                            }
                        } else if (g_Batter.buntStatus == 2) {
                            AnimateCharacter(player, 0x5A, 0, 2, 1, 0, lefty, -1);
                        } else if (g_Batter.buntStatus == 4 && g_Pitcher.pitcherActionState != 4 &&
                                   g_Pitcher.pitcherActionState != 5) {
                            AnimateCharacter(player, 0x5B, 0, 1, 1, 0, lefty, -1);
                        } else if (g_Batter.buntStatus == 4 && g_Pitcher.pitcherActionState == 4) {
                            AnimateCharacter(player, 0x4B, 1, 2, 1, 0, lefty, 0xF);
                        } else if ((g_Batter.buntStatus == 5 || g_Batter.buntStatus == 7) && actor->_62 != 0x4B) {
                            AnimateCharacter(player, 0x5B, 0, 1, 1, 0, lefty, -1);
                        }
                    }
                    if (actor->_62 == 0x5B && actor->_64 != 0x4B && actor->_6A > 0 && g_Batter.buntStatus != 1 &&
                        lbl_3_common_bss_32220._B == 0) {
                        AnimateCharacter(player, 0x4B, 1, 2, 1, 0, lefty, 0xF);
                    }
                skip:;
                } else if (g_Batter.swingInd != 0) {
                    lbl_3_common_bss_32220._B = 0;
                    if (g_Batter.framesSinceStartOfSwing == 1) {
                        if (g_Batter.swingMissThatWasHittable != 0) {
                            lbl_3_common_bss_32220._C = g_Pitcher.framesUntilBallReachesBatterZ - 6;
                        } else {
                            lbl_3_common_bss_32220._C = 0;
                        }
                        lbl_3_common_bss_32220._D = 0;
                    }
                    if (lbl_3_common_bss_32220._C <= 0 && lbl_3_common_bss_32220._D == 0) {
                        if (g_Batter.hitGeneralType == 0) {
                            AnimateCharacter(player, 0x4D, 0, 1, 1, -lbl_3_common_bss_32220._C, lefty, 2);
                            QueueCharacterAnimation(player, 0x50, 0, 1, 0, lefty, 0);
                        } else {
                            AnimateCharacter(player, 0x53, 0, 1, 1, -lbl_3_common_bss_32220._C, lefty, 2);
                            QueueCharacterAnimation(player, 0x54, 0, 1, 0, lefty, 0);
                        }
                        lbl_3_common_bss_32220._D = 1;
                    } else {
                        lbl_3_common_bss_32220._C--;
                    }
                    if ((actor->_62 == 0x50 || actor->_62 == 0x54) && actor->_64 != 0x4E && actor->_64 != 0x4F &&
                        actor->_6A > 0) {
                        if (actor->_62 == 0x54) {
                            AnimateCharacter(player, 0x4F, 0, 2, 1, 0, lefty, -1);
                        } else {
                            AnimateCharacter(player, 0x4E, 0, 2, 1, 0, lefty, -1);
                        }
                    }
                    if ((actor->_62 == 0x4E || actor->_62 == 0x4F) && actor->_64 != 0x4B && actor->_6A > 0 &&
                        lbl_3_common_bss_32220._B == 0) {
                        AnimateCharacter(player, 0x4B, 1, 2, 1, 0, lefty, 0xA);
                    }
                }
                forced = FALSE;
                for (i = 1; i < 4; i++) {
                    if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 &&
                        g_Runners[i].furthestBaseForcedToGoToOnWalk != 0) {
                        forced = TRUE;
                    }
                }
                if (g_Batter.hitByPitch != 0) {
                    if (lbl_3_common_bss_32220._8 == 0 || lbl_3_common_bss_32220._8 == 5) {
                        AnimateCharacter(player, 0x62, 0, 1, 1, 0, lefty, -1);
                        lbl_3_common_bss_32220._8 = 3;
                        fn_3_90220(g_Batter.charID, 0xA);
                    }
                } else {
                    ended = FALSE;
                    if (g_Pitcher.pitcherActionState == 5) {
                        ended = TRUE;
                    } else if (g_Strikes.GameControls_StrikeBallBitVector >= 0x20 && g_Batter.missSwingOrBunt == 1 &&
                               (actor->_62 == 0x4D || actor->_62 == 0x53) && actor->_68 == 1 &&
                               g_Batter.contactMadeInd == 0) {
                        ended = TRUE;
                    }
                    if (g_Pitcher.strikeOutOrWalk == 2) {
                        if (forced) {
                            if (g_Ball.framesSinceHit > 0) {
                                AnimateCharacter(player, 0x66, 0, 1, 1, 0, lefty, -1);
                            }
                        } else if (g_Batter.buntStatus == 4) {
                            AnimateCharacter(player, 0x61, 0, 1, 1, 0, lefty, 0);
                        } else {
                            AnimateCharacter(player, 0x61, 0, 1, 1, 0, lefty, 0);
                        }
                    } else if (ended && lbl_3_common_bss_32220._8 == 0) {
                        if (g_Batter.buntStatus == 4) {
                            AnimateCharacter(player, 0x5F, 0, 1, 1, 0, lefty, -1);
                            lbl_3_common_bss_32220._8 = 1;
                        } else if (actor->_62 == 0x4D || actor->_62 == 0x53) {
                            if (forced && g_Strikes.storedOuts < 2) {
                                AnimateCharacter(player, 0x5E, 0, 2, 1, 0, lefty, -1);
                                QueueCharacterAnimation(player, 0x66, 1, 1, 0, lefty, -1);
                            } else if (actor->_62 == 0x53) {
                                AnimateCharacter(player, 0x60, 0, 2, 1, 0, lefty, -1);
                            } else {
                                AnimateCharacter(player, 0x5E, 0, 2, 1, 0, lefty, -1);
                            }
                            lbl_3_common_bss_32220._8 = 1;
                        } else if (actor->_62 == 0x4B || actor->_62 == 0x4C || actor->_62 == 0x55 ||
                                   actor->_62 == 0x56 || actor->_62 == 0x57 || actor->_62 == 0x58 ||
                                   actor->_62 == 0x68) {
                            AnimateCharacter(player, 0x5F, 0, 1, 1, 0, lefty, -1);
                            lbl_3_common_bss_32220._8 = 1;
                        } else if (actor->_62 == 0x4E || actor->_62 == 0x4F) {
                            AnimateCharacter(player, 0x5F, 0, 2, 1, 0, lefty, -1);
                            lbl_3_common_bss_32220._8 = 1;
                        }
                    }
                }
            }
        }
    }
end:
    actor->_273 = 1;
}

// .text:0x00063A38 size:0xC0 mapped:0x806A2ACC
void fn_3_63A38(void) {
    s32 i;
    InMemRunnerType* runner;
    UnkE08RunnerAnim* state;

    for (i = 0; i < 4; i++) {
        runner = &g_Runners[i];
        state = &lbl_3_common_bss_321A0[i];
        state->_1C = state->_1B;
        if (g_d_GameSettings.minigamesEnabled && g_Minigame._18FC[i] < 0) {
            continue;
        }
        if (runner->runnerOnFieldOrOutOrScored == 0) {
            state->_1B = 0;
        } else {
            state->_1B = 3;
            state->_00 = runner->groundVelocity[0];
            state->_1D = runner->runningDirectionCode;
            fn_3_63874(i);
            fn_3_631AC(i);
        }
    }
}

// .text:0x00063874 size:0x1C4 mapped:0x806A2908
void fn_3_63874(s32 i) {
    InMemRunnerType* runner = &g_Runners[i];
    UnkE08RunnerAnim* anim = &lbl_3_common_bss_321A0[i];

    if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_CHAINCHOMP_SPRINT && g_Minigame._1B15[i] == 1) {
        anim->_1B = 0x11;
    } else if (runner->batterStayInBattersBoxReason != 0) {
        anim->_1B = 1;
    } else if (runner->actionCode != 0) {
        anim->_1B = 8;
    } else if (runner->overRun1BStage >= 2) {
        if (runner->overRun1BStage == 2) {
            anim->_1B = 9;
        } else {
            anim->_1B = 0xA;
        }
    } else if (runner->overrunBaseStage >= 2) {
        if (runner->overrunBaseStage == 2) {
            anim->_1B = 0xB;
        } else {
            anim->_1B = 0xC;
        }
    } else if (runner->runningToDugoutInd == 1) {
        anim->_1B = 0xD;
    } else if (runner->runningToDugoutInd != 0) {
        anim->_1B = 0xE;
    } else if (runner->leadOffStatus == 1) {
        anim->_1B = 0xF;
    } else if (runner->leadOffStatus == 2) {
        anim->_1B = 0x10;
    } else if (runner->turnaroundCode != 0) {
        anim->_1B = 5;
    } else if (runner->runningDirectionCode == 1 || runner->runningDirectionCode == 3) {
        if (runner->turningAroundInd != 0 &&
            runner->framesSinceLastDirectionChange < lbl_3_data_7870[runner->charID][0]) {
            anim->_1B = 7;
        } else {
            anim->_1B = 2;
        }
    } else if (runner->baseStandingOn >= 0) {
        anim->_1B = 3;
    } else {
        anim->_1B = 4;
    }
}

// .text:0x000631AC size:0x6C8 mapped:0x806A2240
void fn_3_631AC(s32 i) {
    InMemRunnerType* runner = &g_Runners[i];
    BOOL slides;
    s32 player = i + 9;
    UnkE08RunnerAnim* state = &lbl_3_common_bss_321A0[i];
    s16 actorAnim;
    UnkE08Actor* actor = lbl_8036E548._2C50[player];

    if (g_d_GameSettings.minigamesEnabled) {
        player = g_Minigame._18FC[i];
        actor = lbl_8036E548._2C50[player];
    }
    if (actor != NULL) {
        actorAnim = actor->_62;
    }
    switch (state->_1B) {
    case 0:
        return;
    case 2:
        slides = FALSE;
        if (lbl_800E8558[runner->charID]._2 == 0xE || lbl_800E8558[runner->charID]._2 == 0x14 ||
            lbl_800E8558[runner->charID]._2 == 0x1A || lbl_800E8558[runner->charID]._2 == 0x1E) {
            slides = TRUE;
        }
        if (runner->runningDirectionCode == 1 && runner->framesToNextBase < 10 &&
            g_GameLogic.secondaryGameMode != SECONDARY_GAME_MODE_CHAINCHOMP_SPRINT && slides) {
            AnimateCharacter(player, 0x2E, 0, 1, 0, lbl_3_data_7870[runner->charID][2] - 10, 0, -1);
        } else if (actorAnim == 0x31) {
            AnimateCharacter(player, 0x2D, 1, 2, 0, 0, 0, -1);
        } else {
            AnimateCharacter(player, 0x2D, 1, 1, 0, 0, 0, -1);
        }
        break;
    case 3:
        if (g_Minigame.GameMode_MiniGame != 0) {
            AnimateCharacter(player, 0x39, 1, 1, 1, 0, 0, -1);
        } else if (lbl_800E8558[runner->charID]._2 == 0xC) {
            AnimateCharacter(player, 0x39, 1, 1, 1, 0, 0, -1);
        } else {
            AnimateCharacter(player, 0x38, 1, 1, 1, 0, 0, -1);
        }
        break;
    case 4:
        AnimateCharacter(player, 0x39, 1, 1, 1, 0, 0, -1);
        break;
    case 5:
        if (runner->runningDirectionCode == 3) {
            AnimateCharacter(player, 0x30, 0, 1, 0, 0x14, 1, -1);
        } else {
            AnimateCharacter(player, 0x30, 0, 1, 0, 0x14, 0, -1);
        }
        break;
    case 7:
        if (runner->runnerDirectionCode_stored == 3) {
            AnimateCharacter(player, 0x31, 0, 1, 0, 0, 1, 0);
        } else {
            AnimateCharacter(player, 0x31, 0, 1, 0, 0, 0, 0);
        }
        break;
    case 8:
        if (runner->actionStage == 1) {
            if (runner->actionFrames_countUp == 1) {
                if (runner->actionCode == 2) {
                    AnimateCharacter(player, 0x33, 0, 1, 1,
                                     lbl_3_data_7760[runner->charID][2] - runner->actionFrames_countDown, 1, -1);
                } else if (runner->actionCode == 3) {
                    AnimateCharacter(player, 0x33, 0, 1, 1,
                                     lbl_3_data_7760[runner->charID][2] - runner->actionFrames_countDown, 1, -1);
                } else if (runner->actionInForwardDirectionInd != 0 && runner->nextBase != 0) {
                    AnimateCharacter(player, 0x32, 0, 1, 1,
                                     lbl_3_data_7760[runner->charID][2] - runner->actionFrames_countDown, 1, -1);
                } else {
                    AnimateCharacter(player, 0x34, 0, 1, 1,
                                     lbl_3_data_7760[runner->charID][4] - runner->actionFrames_countDown, 0, -1);
                }
                if (g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL) {
                    playSoundEffect(0x171);
                }
            }
        } else if (runner->actionStage == 2) {
            if (runner->actionFrames_countDown == 1) {
                AnimateCharacter(player, 0x38, 1, 1, 1, 0, 0, 0);
            }
        }
        break;
    case 9:
        AnimateCharacter(player, 0x2D, 1, 1, 0, 0, 0, -1);
        break;
    case 10:
        AnimateCharacter(player, 0x2F, 1, 1, 0, 0, 0, -1);
        break;
    case 11:
        AnimateCharacter(player, 0x30, 1, 1, 0, 0, 0, -1);
        break;
    case 12:
        AnimateCharacter(player, 0x2F, 1, 1, 0, 0, 0, -1);
        break;
    case 13:
        AnimateCharacter(player, 0x2D, 1, 1, 0, 0, 0, -1);
        break;
    case 14:
        if (runner->slideHomeFrames_CountDown == 0 && runner->velocity.x != 0.0f) {
            AnimateCharacter(player, 0x2D, 1, 1, 0, 0, 0, -1);
        }
        break;
    case 15:
        AnimateCharacter(player, 0x35, 0, 1, 0,
                         lbl_3_data_7870[runner->charID][1] - runner->leadOffTotalFrameCountDown, 0, -1);
        break;
    case 16:
        AnimateCharacter(player, 0x39, 1, 1, 1, 0, 0, 0);
        break;
    case 17:
        if (actorAnim != 0x24) {
            fn_3_90220(runner->charID, 10);
        }
        AnimateCharacter(player, 0x24, 0, 1, 1, 0, 0, 0x14);
        break;
    }
}

// .text:0x00062E70 size:0x33C mapped:0x806A1F04
void fn_3_62E70(void) {
    s32 i;

    g_UnkThrowing_31ACC[0]._0C = g_Ball.fielderWBallIndex;
    if (g_UnkThrowing_31ACC[0]._0C >= 0 && g_Fielders[g_UnkThrowing_31ACC[0]._0C]._203 != 0) {
        g_UnkThrowing_31ACC[0]._0C = -1;
    }
    if (g_Minigame.GameMode_MiniGame == 0) {
        fn_3_62B50();
        fn_3_62904();
    }
    for (i = 0; i < 9; i++) {
        UnkE08Fielder* fielder = &g_Fielders[i];

        g_UnkAnimation_31EAC[i]._40 = g_Fielders[i]._1C7;
        if (g_d_GameSettings.minigamesEnabled && findMinigameSlot(i) >= 4) {
            continue;
        }
        if (g_Minigame.GameMode_MiniGame == 2 && (s8)fielder->_20D == g_Minigame.minigamePlayerSelectedOrder &&
            g_Minigame.wallBallRotatePitchersInd == 0) {
            continue;
        }
        if (i == 0 && (g_GameLogic.gameStatus == 1 || g_GameLogic.gameStatus == 0 ||
                       (g_GameLogic.gameStatus == 2 && g_FieldingLogic._117 != 0) || g_GameLogic.gameStatus == 0xB ||
                       g_GameLogic.gameStatus == 0x16)) {
            continue;
        }
        if (i == 1 && (g_GameLogic.gameStatus == 1 || g_GameLogic.gameStatus == 0 || g_GameLogic.gameStatus == 0xB)) {
            fn_3_62E28();
        } else {
            // fn_3_62CA8 written out: inlined, its own declaration order swaps r3 and r4
            u8 kind;
            UnkE08Actor* actor = lbl_8036E548._2C50[i];
            UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];

            anim->_00 = fielder->_050;
            anim->_45 = 0;
            if (anim->_4C == 0) {
                kind = fielder->_252;
                anim->_4C = kind;
                anim->_4A = fielder->_24C;
                if (kind == 1 || kind == 2) {
                    anim->_4E = fielder->_253;
                }
                if (anim->_4C != 0) {
                    anim->_4D = anim->_4C;
                }
            }
            if (actor != NULL && actor->_62 == 0x24) {
                anim->_4C = 0;
                anim->_4F = 0;
            }
            fn_3_62E04(i);
            fn_3_62D44(i);
            fn_3_61B64(i);
        }
    }
}

// .text:0x00062E28 size:0x48 mapped:0x806A1EBC
void fn_3_62E28(void) {
    AnimateCharacter(1, 0x3D, 1, 1, 1, 0, g_Fielders[1]._1C7, 0);
}

// .text:0x00062E04 size:0x24 mapped:0x806A1E98
void fn_3_62E04(s32 i) {
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];

    anim->_3A = anim->_38;
    anim->_38 = 0;
}

// .text:0x00062D44 size:0xC0 mapped:0x806A1DD8
void fn_3_62D44(s32 i) {
    UnkE08Fielder* fielder = &g_Fielders[i];
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];

    anim->_41 = 0;
    if (fielder->_1E5 == 2) {
        anim->_41 = 1;
    } else if (fielder->_1E5 == 3) {
        anim->_41 = 2;
    }
    if (fielder->_256 != 0 && g_Ball.AtBat_ContactResult == 0 && fielder->_248 < fielder->_0E8 &&
        g_Ball.framesUntilBallHitsGround < 120 && g_Ball.maxYOfHit > 5.0f && g_FieldingLogic._144 != 0) {
        anim->_45 = 1;
    }
}

// .text:0x00062CA8 size:0x9C mapped:0x806A1D3C
void fn_3_62CA8(s32 i) {
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    u8 kind;
    UnkE08Fielder* fielder = &g_Fielders[i];
    UnkE08Actor* actor = lbl_8036E548._2C50[i];

    if (anim->_4C == 0) {
        kind = fielder->_252;
        anim->_4C = kind;
        anim->_4A = fielder->_24C;
        if (kind == 1 || kind == 2) {
            anim->_4E = fielder->_253;
        }
        if (anim->_4C != 0) {
            anim->_4D = anim->_4C;
        }
    }
    if (actor != NULL && actor->_62 == 0x24) {
        anim->_4C = 0;
        anim->_4F = 0;
    }
}

// .text:0x00062B50 size:0x158 mapped:0x806A1BE4
void fn_3_62B50(void) {
    s16 holder = g_Ball.fielderWBallIndex;

    if (holder < 0) {
        g_UnkThrowing_31ACC[0]._0E = 0;
        return;
    }
    if (g_FieldingLogic._0C4 < 0) {
        g_UnkThrowing_31ACC[0]._0E = 0;
        return;
    }
    if (g_UnkThrowing_31ACC[0]._0E != 0) {
        return;
    }
    g_FieldingLogic._10A = 0;
    g_UnkThrowing_31ACC[0]._00.x = g_Ball.throwDestination.x;
    g_UnkThrowing_31ACC[0]._00.y = g_Ball.throwDestination.y;
    g_UnkThrowing_31ACC[0]._00.z = g_Ball.throwDestination.z;
    if (g_FieldingLogic._107 == 1 && holder == 0 && (g_FieldingLogic._0C4 == 1 || g_FieldingLogic._0C4 == 2 || g_FieldingLogic._0C4 == 3) &&
        g_Pitcher.pickOffLoc != 4 && g_Pitcher.pickOffLoc != -1) {
        g_UnkThrowing_31ACC[0]._0E = 7;
    } else if (g_FieldingLogic.throwSpeedType == 8) {
        g_UnkThrowing_31ACC[0]._0E = 3;
    } else if (g_FieldingLogic.throwSpeedType == 9) {
        g_UnkThrowing_31ACC[0]._0E = 4;
    } else if (g_FieldingLogic.throwSpeedType == 10) {
        if (holder == 3) {
            g_UnkThrowing_31ACC[0]._0E = 5;
        } else {
            g_UnkThrowing_31ACC[0]._0E = 6;
        }
    } else if (g_FieldingLogic._109 != 0) {
        g_UnkThrowing_31ACC[0]._0E = 2;
    } else {
        g_UnkThrowing_31ACC[0]._0E = 1;
    }
}

// .text:0x00062904 size:0x24C mapped:0x806A1998
void fn_3_62904(void) {
    s32 i;
    s16 holder;
    UnkE08Anim* anim;
    UnkE08Fielder* fielder;
    u8 state;
    s16 runner;

    if (g_d_GameSettings.minigamesEnabled) {
        return;
    }
    for (i = 0; i < 9; i++) {
        if (g_Fielders[i]._211 != 0) {
            if (g_Fielders[i]._211 != 0 && g_UnkAnimation_31EAC[i]._51 != 8 && g_UnkAnimation_31EAC[i]._51 != 9) {
                g_UnkAnimation_31EAC[i]._51 = 8;
            }
            break;
        }
    }
    holder = g_Ball.fielderWBallIndex;
    if (holder < 0 || g_FieldingLogic._111 == 0) {
        return;
    }
    fielder = &g_Fielders[holder];
    anim = &g_UnkAnimation_31EAC[holder];
    if (g_FieldingLogic._135 != 0) {
        fielder->_1AA = 0;
    }
    g_UnkThrowing_31ACC[0]._10 = g_FieldingLogic._135;
    if (g_FieldingLogic._111 == 1) {
        state = 1;
        if (g_FieldingLogic._0E8 >= 0) {
            int angle = fn_3_9FB8C(g_FieldingLogic._090.x - fielder->_000.x, g_FieldingLogic._090.z - fielder->_000.z);
            int facing = radToShortAngle(fielder->_048);
            int diff = fn_3_9FCA4(angle, facing);
            if (diff < -0x280) {
                state = 2;
            } else if (diff > 0x280) {
                state = 3;
            }
        }
        anim->_51 = state;
    } else if (g_FieldingLogic._111 == 2) {
        anim->_51 = 4;
    } else if (g_FieldingLogic._111 == 5) {
        state = 5;
        runner = g_FieldingLogic._0E8;
        if (runner >= 0) {
            InMemRunnerType* target = &g_Runners[runner];
            int angle = fn_3_9FB8C(target->position.x - fielder->_000.x, target->position.z - fielder->_000.z);
            int facing = radToShortAngle(fielder->_048);
            int diff = fn_3_9FCA4(angle, facing);
            if (diff < -0x1C0) {
                state = 7;
            } else if (diff > 0x1C0) {
                state = 6;
            }
        }
        anim->_51 = state;
    }
}

// .text:0x00061B64 size:0xDA0 mapped:0x806A0BF8
void fn_3_61B64(s32 i) {
    s32 player = i;
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    UnkE08Actor* actor;
    UnkE08Throw* throwInfo = &g_UnkThrowing_31ACC[0];
    UnkE08Fielder* fielder = &g_Fielders[i];
    s16 actorAnim;
    s32 animId;
    s32 blend;

    if (g_d_GameSettings.minigamesEnabled) {
        if (i == 0) {
            player = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            player = g_Minigame.minigameControlStruct.characterIndex[fielder->_20D];
        }
    }
    actor = lbl_8036E548._2C50[player];
    if (actor == NULL) {
        return;
    }
    actorAnim = actor->_62;
    if (g_UnkThrowing_31ACC[0]._0C == i && g_Ball.fielderWBallIndex == i) {
        actor->_274 = 1;
    }
    if (g_Minigame.GameMode_MiniGame != 2) {
        if (g_Minigame.GameMode_MiniGame == 5) {
            if (g_Minigame._1C9A_arr[fielder->_20D] == 1) {
                if (actorAnim != 0x24) {
                    fn_3_90220(fielder->_17A, 10);
                }
                AnimateCharacter(player, 0x24, 1, 1, 0, 0, 0, -1);
                anim->_43 = 0;
                goto end;
            }
            if (g_Minigame._1C9A_arr[fielder->_20D] == 2) {
                AnimateCharacter(player, 0, 1, 1, 0, 0, 0, -1);
                goto end;
            }
            if (fn_3_60D80(i)) {
                goto end;
            }
        }
        if (g_Minigame.GameMode_MiniGame == 6 && g_Minigame.starDashStunType[fielder->_20D] == 2) {
            if (actorAnim != 0x24 && actorAnim != 0x25) {
                fn_3_90220(fielder->_17A, 10);
                AnimateCharacter(player, 0x24, 0, 1, 0, 0, 0, -1);
                QueueCharacterAnimation(player, 0x25, 0, 0, 0, 0, 0);
            }
            goto end;
        }
        if (fielder->_210 != 0) {
            if (fielder->_210 == 1) {
                if (fielder->_1BE == 1) {
                    fn_3_60804(i, FALSE);
                    if (actorAnim != 0x24) {
                        fn_3_90220(fielder->_17A, 10);
                    }
                    AnimateCharacter(player, 0x24, 0, 1, 0, 0, anim->_40, -1);
                }
            } else {
                if (fielder->_1BE == 1) {
                    AnimateCharacter(player, 0x25, 0, 1, 1, 0, anim->_40, 0);
                    fn_3_60804(i, TRUE);
                }
                if (fielder->_1C0 == 1) {
                    AnimateCharacter(player, 0, 1, 1, 0, 0, anim->_40, -1);
                    fn_3_60804(i, FALSE);
                }
            }
            anim->_43 = 0;
            goto end;
        }
        if (fn_3_61544(i)) {
            if (!fn_3_61228(i)) {
                fn_3_60E90(i);
            }
            goto end;
        }
        if (fielder->_20F != 0) {
            if (fielder->_1B8 == 0) {
                fn_3_60804(i, FALSE);
            }
            AnimateCharacter(player, 0x10, 1, 1, 0, 0, anim->_40, 0);
            if (actorAnim != 0x10) {
                fn_3_90220(fielder->_17A, 11);
            }
            anim->_43 = 0;
            goto end;
        }
        if (throwInfo->_0C == i) {
            if (!fn_3_61228(i) && !fn_3_60E90(i)) {
                if (fielder->_205 >= 3) {
                    AnimateCharacter(player, 0x27, 0, 1, 0, 0, anim->_40, -1);
                } else if (anim->_00 > 0.02f) {
                    if (g_Strikes.outs >= 3 && fielder->_1D6 == 0xD) {
                        AnimateCharacter(player, 7, 1, 1, 0, 0, anim->_40, -1);
                    } else if (g_Ball.fielderWBallIndex == i && fielder->_0B8 < 30.0f) {
                        if (actorAnim == 5) {
                            AnimateCharacter(player, 0x22, 1, 2, 0, 0, anim->_40, -1);
                        } else {
                            AnimateCharacter(player, 0x22, 1, 1, 0, 0, anim->_40, -1);
                        }
                    } else if (anim->_00 > 0.1f) {
                        if (actorAnim == 0x22) {
                            AnimateCharacter(player, 5, 1, 2, 0, 0, anim->_40, -1);
                        } else {
                            AnimateCharacter(player, 5, 1, 1, 0, 0, anim->_40, -1);
                        }
                    } else {
                        AnimateCharacter(player, 7, 1, 1, 0, 0, anim->_40, -1);
                    }
                } else {
                    AnimateCharacter(player, 1, 1, 1, 1, 0, anim->_40, -1);
                }
            }
            goto end;
        }
        anim->_44 = 0;
        if (fn_3_61148(i)) {
            goto end;
        }
    }
    if (fielder->_211 != 0 && fielder->_212 == 3) {
        if (g_FieldingLogic._0F6 <= 1) {
            fn_3_60804(player, FALSE);
            anim->_44 = 0;
            anim->_51 = 0;
        }
    } else if (fielder->_203 != 0) {
        AnimateCharacter(player, 0x26, 0, 1, 0, 0, anim->_40, -1);
    } else if (fielder->_207 != 0) {
        if (fielder->_207 == 1) {
            AnimateCharacter(player, 0x26, 0, 1, 0, 0, anim->_40, -1);
        } else if (fielder->_207 == 2) {
            AnimateCharacter(player, 0x28, 0, 1, 1, 0, anim->_40, -1);
            actor->_26F = 1;
        } else if (fielder->_207 == 3) {
            if (fielder->_1B4 == 1) {
                fn_3_60804(player, TRUE);
            }
        } else if (fielder->_207 == 4) {
            actor->_26F = 0;
            if (fielder->_1B4 == 1) {
                AnimateCharacter(player, 0, 1, 1, 0, 0, anim->_40, -1);
                fn_3_60804(player, FALSE);
            }
        }
    } else if (fielder->_205 != 0) {
        if (fielder->_205 == 1) {
            AnimateCharacter(player, 0x26, 0, 1, 0, 0, anim->_40, -1);
        } else if (fielder->_205 == 2) {
            if (fielder->_206 != 0) {
                s32 pose = 0x2A;

                if (fielder->_206 == 3) {
                    pose = 0x2B;
                } else if (fielder->_206 == 4) {
                    pose = 0x2C;
                }
                if (actorAnim == 0x2A || actorAnim == 0x2B || actorAnim == 0x2C) {
                    AnimateCharacter(player, pose, 1, 2, 1, 0, anim->_40, -1);
                } else {
                    AnimateCharacter(player, pose, 1, 1, 1, 0, anim->_40, -1);
                }
            } else if (actorAnim == 0x2A) {
                AnimateCharacter(player, 0x28, 1, 2, 1, 0, anim->_40, -1);
            } else {
                AnimateCharacter(player, 0x28, 1, 1, 1, 0, anim->_40, 0);
            }
        } else if (fielder->_205 >= 3) {
            AnimateCharacter(player, 0x27, 0, 1, 0, 0, anim->_40, -1);
        }
    } else if (anim->_00 > 0.01f) {
        if (fielder->_256 != 0) {
            int facing = radToShortAngle(fielder->_048);
            int target = fn_3_9FB8C(fielder->_030, fielder->_034);
            int diff = fn_3_9FCA4(facing, target);

            if (fielder->_256 == 1) {
                animId = 8;
                if (diff < -0x600 || diff > 0x600) {
                    animId = 9;
                } else if (diff > 0x200) {
                    if (anim->_40 == 0) {
                        animId = 0xA;
                    } else {
                        animId = 0xB;
                    }
                } else if (diff < -0x200) {
                    if (anim->_40 == 0) {
                        animId = 0xB;
                    } else {
                        animId = 0xA;
                    }
                }
            }
            AnimateCharacter(player, animId, 1, 1, 0, 0, anim->_40, -1);
        } else if (fielder->_1CB == 1 && actorAnim == 0x28) {
            AnimateCharacter(player, 2, 1, 2, 1, 0, anim->_40, -1);
            fielder->_20A = 1;
        } else if (anim->_00 > 0.1f) {
            AnimateCharacter(player, 5, 1, 1, 0, 0, anim->_40, -1);
        } else {
            AnimateCharacter(player, 7, 1, 1, 0, 0, anim->_40, -1);
        }
    } else {
        if (g_Minigame.GameMode_MiniGame == 2 && actorAnim >= 0x3F && actorAnim < 0x4B) {
            return;
        }
        animId = 2;
        if (anim->_41 == 1) {
            animId = 0;
        }
        if (actorAnim == 0x24 || actorAnim == 0x25) {
            if (actorAnim == 0x25) {
                AnimateCharacter(player, 0, 1, 2, 1, 0, anim->_40, -1);
            }
        } else if (anim->_45 != 0) {
            AnimateCharacter(player, 3, 1, 1, 0, 0, anim->_40, -1);
        } else if (fielder->_1CB == 1 && actorAnim == 0x28) {
            AnimateCharacter(player, animId, 1, 2, 1, 0, anim->_40, -1);
            fielder->_20A = 1;
        } else if (actorAnim == 0xF) {
            AnimateCharacter(player, animId, 1, 2, 1, 0, anim->_40, -1);
        } else if (i == 1 && g_Ball.framesSinceHit < 120) {
            if (g_Ball.framesSinceHit >= 30 && g_Ball.framesSinceHit == 30) {
                AnimateCharacter(player, 0x3E, 0, 1, 1, 0, anim->_40, -1);
            }
        } else if (actorAnim == 0x3E) {
            AnimateCharacter(player, animId, 1, 2, 1, 0, anim->_40, -1);
        } else {
            blend = -1;
            if (actorAnim == 0x40 || actorAnim == 0x42 || actorAnim == 0x49 || actorAnim == 0x4A) {
                blend = 0;
            }
            AnimateCharacter(player, animId, 1, 1, 1, 0, anim->_40, blend);
        }
    }
end:
    if (anim->_42 != 0) {
        actor->_34.x = anim->_10.x;
        actor->_34.z = anim->_10.z;
        anim->_42 = 1;
    } else {
        anim->_42 = 0;
    }
    if (fielder->_1CB == 1 && actorAnim == 0x28 && (actor->_68 <= 1 || actor->_25E == 1)) {
        fn_3_60804(player, FALSE);
    }
}

// .text:0x00061544 size:0x620 mapped:0x806A05D8
BOOL fn_3_61544(s32 i) {
    s32 animId = -1;
    s32 player = i;
    s32 turnAnim;
    UnkE08Fielder* fielder = &g_Fielders[i];
    UnkE08Actor* actor;
    s32 frames = 0;
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    u8 kind;
    if (g_d_GameSettings.minigamesEnabled) {
        if (i == 0) {
            player = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            player = g_Minigame.minigameControlStruct._28[i - 2];
        }
    }
    actor = lbl_8036E548._2C50[player];
    if (anim->_43 != 0) {
        return FALSE;
    }
    if (anim->_4F == 0) {
        if (fielder->_20F != 0) {
            return FALSE;
        }
        if (fielder->_210 != 0) {
            return FALSE;
        }
        if (fielder->_207 != 0) {
            return FALSE;
        }
        if (anim->_4C != 0) {
            anim->_4A--;
            if (anim->_4C == 1 || anim->_4C == 2) {
                if (anim->_4A <= lbl_3_data_665C[0]) {
                    kind = fielder->_254;
                    if (kind == 0) {
                        animId = lbl_3_data_6644[0][anim->_4E];
                    } else if ((kind == 1 && fielder->_1C7 == 0) || (kind == 2 && fielder->_1C7 != 0)) {
                        animId = lbl_3_data_6644[1][anim->_4E];
                    } else {
                        animId = lbl_3_data_6644[2][anim->_4E];
                    }
                    frames = lbl_3_data_665C[0] - anim->_4A;
                }
            } else if (anim->_4C == 7 || anim->_4C == 8) {
                if (fielder->_261 == 1) {
                    if (anim->_40 != 0) {
                        turnAnim = 0xE;
                    } else {
                        turnAnim = 0xD;
                    }
                } else if (fielder->_261 == 2) {
                    if (anim->_40 != 0) {
                        turnAnim = 0xD;
                    } else {
                        turnAnim = 0xE;
                    }
                } else {
                    turnAnim = 0xC;
                }
                AnimateCharacter(player, turnAnim, 1, 1, 0, 0, anim->_40, -1);
                anim->_46 = turnAnim;
                anim->_4F = 1;
                return TRUE;
            } else if (anim->_4C == 3) {
                if (anim->_4A <= lbl_3_data_665C[1]) {
                    frames = lbl_3_data_665C[1] - anim->_4A;
                    animId = 0x1B;
                }
            } else if (anim->_4C == 4) {
                AnimateCharacter(player, 0x26, 0, 1, 0, lbl_3_data_7F0C - fielder->_25C, anim->_40, -1);
                anim->_46 = 0x26;
                anim->_4F = 1;
                return TRUE;
            } else if (anim->_4C == 5) {
                animId = 0x29;
                frames = lbl_3_data_6600 - anim->_4A;
            }
            if (animId >= 0 && frames >= 0) {
                AnimateCharacter(player, animId, 0, 1, 0, frames, anim->_40, -1);
                anim->_46 = animId;
                anim->_4F = 1;
                anim->_50 = lbl_3_data_6658[0];
                return TRUE;
            }
        }
    } else {
        if (fielder->_20F != 0) {
            goto reset;
        }
        if (fielder->_200 != 0) {
            actor->_26F = 1;
            if (g_d_GameSettings.minigamesEnabled) {
                fn_8004AE18(fielder->_20D);
            } else {
                fn_8004AE18(i);
            }
        }
        if (anim->_50 != 0) {
            anim->_50--;
        }
        anim->_4A--;
        if (anim->_46 == 0x26) {
            if (fielder->_25C == 1) {
                AnimateCharacter(player, 0x28, 0, 1, 0, 0, anim->_40, 0);
            }
            if (fielder->_25E == 4) {
                goto reset;
            }
            return TRUE;
        }
        if (anim->_4A == 1 && (fielder->_258 != 1 || fielder->_252 != 1) && anim->_4C != 7 && anim->_4C != 8 &&
            actor->_62 != 0x29) {
            if (fielder->_258 == 3 && anim->_4C != 3) {
                AnimateCharacter(player, 0x1C, 0, 1, 1, 0, anim->_40, 10);
                fn_3_60804(i, TRUE);
            } else {
                fn_3_60804(i, TRUE);
            }
        }
        if (actor->_62 == 0x1B && g_Ball.timeSinceBallPickedUp >= lbl_3_data_6630[0] &&
            g_Ball.timeSinceBallPickedUp <= lbl_3_data_6630[1] &&
            !checkFieldingStat(g_GameLogic.teamFielding, fielder->_178, 7) &&
            !checkFieldingStat(g_GameLogic.teamFielding, fielder->_178, 8) &&
            !checkFieldingStat(g_GameLogic.teamFielding, fielder->_178, 9) &&
            (g_FieldingLogic._0C4 >= 0 || g_FieldingLogic._0C6 >= 0) && anim->_42 != 0) {
            AnimateCharacter(player, 0x1A, 0, 1, 1, 0, anim->_40, -1);
            fn_3_60804(i, TRUE);
        }
        if (anim->_4C == 7 || anim->_4C == 8) {
            if (fielder->_262 == 0 && fielder->_252 == 0 && fielder->_1EE == 0) {
                AnimateCharacter(player, 0, 0, 1, 1, 0, anim->_40, -1);
                goto reset;
            }
            return TRUE;
        }
        if (actor->_68 <= 1) {
        reset:
            anim->_4C = 0;
            anim->_4F = 0;
            anim->_47 = 0;
            anim->_46 = 0;
            anim->_50 = 0;
            fn_3_60804(i, FALSE);
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

// .text:0x00061228 size:0x31C mapped:0x806A02BC
BOOL fn_3_61228(s32 i) {
    s16 timer;
    s32 step;
    s32 player = i;
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    UnkE08Throw* throwInfo = &g_UnkThrowing_31ACC[0];
    UnkE08Fielder* fielder = &g_Fielders[i];
    UnkE08Actor* actor;
    s32 animId = 0x1D;
    BOOL turn = FALSE;
    g_FieldingLogic_s* logic = &g_FieldingLogic;

    if (g_d_GameSettings.minigamesEnabled) {
        if (i == 0) {
            player = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            player = g_Minigame.minigameControlStruct._28[i - 2];
        }
    }
    actor = lbl_8036E548._2C50[player];
    if (actor == NULL) {
        return FALSE;
    }
    if (throwInfo->_0C != i) {
        return FALSE;
    }
    if (anim->_43 != 0) {
        if (fielder->_1D3 == 0x11) {
            anim->_43 = 0;
            fn_3_60804(i, FALSE);
            return FALSE;
        }
        timer = actor->_6A;
        if (timer > 0 && actor->_68 <= 0) {
            anim->_43 = 0;
            fn_3_60804(i, FALSE);
            return FALSE;
        }
        step = actor->_62 - 0x1D;
        if (timer >= lbl_3_data_7D24[actor->_252][step]) {
            logic->_10A = 1;
        }
        return TRUE;
    }
    if (fielder->_215 != 0) {
        return FALSE;
    }
    if (throwInfo->_0E != 0) {
        switch (throwInfo->_0E) {
        case 2:
            animId = 0x1E;
            break;
        case 3:
            animId = 0x1F;
            break;
        case 4:
            animId = 0x1D;
            break;
        case 5:
            animId = 0x1D;
            break;
        case 6:
            animId = 0x1D;
            break;
        case 7:
            animId = 0x1D;
            turn = TRUE;
            break;
        }
        if (turn) {
            int adjust;
            int facing = radToShortAngle(fielder->_048);
            int target = fn_3_9FB8C(throwInfo->_00.x - fielder->_000.x, throwInfo->_00.z - fielder->_000.z);
            int diff = fn_3_9FCA4(facing, target);

            adjust = -diff;

            if (diff < -0x600 || diff > 0x600) {
                if (diff < -0x600) {
                    adjust = -0x800 - diff;
                } else {
                    adjust = 0x800 - diff;
                }
            } else if (diff > 0x200) {
                adjust = 0x400 - diff;
            } else if (diff < -0x200) {
                adjust = -0x400 - diff;
            }
            fielder->_048 = shortAngleToRad_Capped(facing + adjust);
        }
        AnimateCharacter(player, animId, 0, 1, 1, 0, anim->_40, -1);
        throwInfo->_0F = animId;
        anim->_43 = 1;
        if (turn) {
            anim->_43 = 2;
        }
        anim->_4C = 0;
        anim->_4F = 0;
        anim->_47 = 0;
        anim->_46 = 0;
        anim->_50 = 0;
        fn_3_60804(i, TRUE);
        return TRUE;
    }
    return FALSE;
}

// .text:0x00061148 size:0xE0 mapped:0x806A01DC
BOOL fn_3_61148(s32 i) {
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    s32 player = i;
    UnkE08Actor* actor;

    if (g_d_GameSettings.minigamesEnabled) {
        if (i == 0) {
            player = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            player = g_Minigame.minigameControlStruct._28[i - 2];
        }
    }
    actor = lbl_8036E548._2C50[player];
    if (actor == NULL) {
        return FALSE;
    }
    if (anim->_43 != 0) {
        if (actor->_68 <= 0) {
            anim->_43 = 0;
            fn_3_60804(i, FALSE);
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

// .text:0x00060E90 size:0x2B8 mapped:0x8069FF24
BOOL fn_3_60E90(s32 i) {
    s32 player = i;
    u8 state;
    UnkE08Actor* actor;
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    UnkE08Fielder* fielder = &g_Fielders[i];
    s16 actorAnim;

    if (g_d_GameSettings.minigamesEnabled) {
        if (i == 0) {
            player = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            player = g_Minigame.minigameControlStruct._28[i - 2];
        }
    }
    state = anim->_51;
    actor = lbl_8036E548._2C50[player];
    actorAnim = actor->_62;
    if (state != 9 && g_Ball.fielderWBallIndex != i) {
        anim->_44 = 0;
        return FALSE;
    }
    if (state == 9) {
        return TRUE;
    }
    if (anim->_44 != 0 && g_UnkThrowing_31ACC[0]._10 == 0) {
        if (state == 8 && fielder->_212 == 3) {
            if (actorAnim != 0x24) {
                fn_3_90220(fielder->_17A, 10);
            }
            anim->_51 = 9;
            AnimateCharacter(player, 0x24, 0, 1, 0, 0, anim->_40, 0);
            QueueCharacterAnimation(player, 0x25, 0, 1, 0, anim->_40, 0);
            fn_3_60804(i, FALSE);
            return TRUE;
        }
        if (actor->_68 <= 0) {
            anim->_44 = 0;
            anim->_51 = 0;
            fn_3_60804(i, FALSE);
            return FALSE;
        }
        return TRUE;
    }
    if (state != 0 && state != 4) {
        if (state == 8) {
            if (lbl_3_data_7E34[actor->_252][1] - g_FieldingLogic._0F6 < 0) {
                goto fail;
            }
            AnimateCharacter(player, 0x23, 0, 1, 1, lbl_3_data_7E34[actor->_252][0], anim->_40, -1);
            anim->_44 = 1;
        } else {
            AnimateCharacter(player, 0x21, 0, 1, 0, lbl_3_data_7E34[actor->_252][0], anim->_40, -1);
            anim->_44 = 1;
        }
        fn_3_60804(i, FALSE);
        return TRUE;
    }
fail:
    anim->_44 = 0;
    return FALSE;
}

// .text:0x00060D80 size:0x110 mapped:0x8069FE14
BOOL fn_3_60D80(s32 i) {
    s16 state;
    s16 timer;
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    s32 player;

    player = g_Minigame.minigameControlStruct._28[i - 2];
    state = lbl_8036E548._2C50[player]->_62;
    timer = g_Minigame._1B34[player];

    if (timer < 0) {
        if (state == 0x1D || state == 0x1F) {
            AnimateCharacter(player, 0, 1, 3, 0, 0, anim->_40, -1);
        }
        return FALSE;
    }
    if (timer == 0) {
        if (g_Minigame._1C92[player] == 3) {
            AnimateCharacter(player, 0x1F, 0, 3, 0, 0, anim->_40, -1);
        } else {
            AnimateCharacter(player, 0x1D, 0, 3, 0, 0, anim->_40, -1);
        }
    }
    return TRUE;
}

// .text:0x00060A98 size:0x2E8 mapped:0x8069FB2C
void fn_3_60A98(s32 i, UnkE08Actor* actor) {
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    UnkE08Fielder* fielder = &g_Fielders[i];
    s32 player = i;
    s16 actorAnim = actor->_62;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 nz;
    f32 scale;
    f32 nx;

    if (actor == NULL) {
        return;
    }
    if (fielder->_0A8 < 60.0f && !fn_3_B7E10(fielder->_000.x, fielder->_000.z)) {
        return;
    }
    dx = fielder->_000.x - anim->_10.x;
    dz = fielder->_000.z - anim->_10.z;
    dist = dolsqrtf2(dx * dx + dz * dz);
    if (dist <= 0.0f) {
        return;
    }
    nx = dx / dist;
    nz = dz / dist;
    if (actorAnim == 0x1A || actorAnim == 0x1B) {
        scale = 0.01f * (lbl_3_data_7F10[fielder->_17A] + 30) * charSizeMultipliers[fielder->_17A][0];
        nx *= scale;
        nz *= scale;
    } else {
        nx *= lbl_3_data_476C[fielder->_1C9];
        nz *= lbl_3_data_476C[fielder->_1C9];
    }
    nx += fielder->_000.x;
    nz += fielder->_000.z;
    if (fn_3_B7CDC(nx, nz)) {
        fn_3_60804(i, FALSE);
        if (g_d_GameSettings.minigamesEnabled) {
            if (i == 0) {
                player = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
            } else {
                player = g_Minigame.minigameControlStruct._28[i - 2];
            }
        }
        fn_8001B5EC(player, 0);
        fielder->_000.x = fielder->_0D4;
        fielder->_000.z = fielder->_0D8;
        fielder->_1FB = 0;
    }
}

// .text:0x00060804 size:0x294 mapped:0x8069F898
void fn_3_60804(s32 i, BOOL mode) {
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    UnkE08Fielder* fielder = &g_Fielders[i];
    UnkE08Actor* actor;
    VecXYZ pos;

    if (g_d_GameSettings.minigamesEnabled) {
        if (i == 0) {
            i = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder];
        } else {
            i = g_Minigame.minigameControlStruct._28[i - 2];
        }
    }
    actor = lbl_8036E548._2C50[i];
    if (actor == NULL) {
        return;
    }
    if (!mode) {
        if (anim->_42 == 1) {
            anim->_42 = 0;
            getAnimRelatedCoordinates(i, 4, &anim->_2C);
            fielder->_030 = anim->_2C.x - fielder->_000.x;
            fielder->_034 = anim->_2C.z - fielder->_000.z;
            fielder->_050 = dolsqrtf2(fielder->_030 * fielder->_030 + fielder->_034 * fielder->_034);
            fielder->_000.x = anim->_2C.x;
            fielder->_000.z = anim->_2C.z;
            anim->_48 = 1;
        }
    } else if (anim->_42 == 0) {
        fn_8001B4D8(i);
        if (anim->_48 == 1) {
            anim->_10.x = anim->_2C.x;
            anim->_10.z = anim->_2C.z;
        } else {
            anim->_10.x = actor->_34.x;
            anim->_10.z = actor->_34.z;
        }
        anim->_42 = 1;
    } else {
        getAnimRelatedCoordinates(i, 4, &pos);
        anim->_10.x = actor->_34.x = pos.x;
        anim->_10.z = actor->_34.z = pos.z;
    }
}

// .text:0x00060768 size:0x9C mapped:0x8069F7FC
void fn_3_60768(void) {
    s32 i;
    UnkE08Track* track;

    for (i = 0; i < 4; i++) {
        track = &lbl_8036E548._0060->_38[i];
        track->_00 = 0;
        track->_0A = 0;
        track->_58 = 0.0f;
        track->_54 = 1;
        track->_55 = 0;
        track->_56 = 0;
        track->_5C = 0.0f;
    }
}
