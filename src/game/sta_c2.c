#include "game/sta_c2.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"
#include "musyx/musyx.h"
#include "C3/control.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "Dolphin/rand.h"
#include "Dolphin/mtxext.h"
#include "game/rep_1838.h"
#include "game/rep_AC8.h"
#include "game/rep_1D58.h"
#include "game/rep_540.h"
#include "game/m_sound.h"
#include "string.h"

typedef struct StaC2Place {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
} StaC2Place; // size: 0x10

typedef struct StaC2Place1C {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
} StaC2Place1C; // size: 0x1C

typedef struct StaC2Place20 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ Vec scale;
    /* 0x1C */ f32 rotY;
} StaC2Place20; // size: 0x20

typedef struct StaC2Place34 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ u8 _30;
} StaC2Place34; // size: 0x34

typedef struct StaC2Swing {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 type;
    /* 0x0D */ u8 _0D;
    /* 0x0E */ u8 _0E;
    /* 0x0F */ u8 _0F;
    /* 0x10 */ f32 _10;
    /* 0x14 */ Vec scale;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ f32 _30;
} StaC2Swing; // size: 0x34

typedef struct {
    /* 0x00 */ u8 _00[0x74];
    /* 0x74 */ u32 _74;
} StaC2TexRegs;

typedef struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ StaC2TexRegs* _04;
} StaC2TexInfo;

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ StaC2TexInfo* _10;
} StaC2TexMap;

typedef struct StaC2Bone {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ StaC2TexMap* _14;
    /* 0x18 */ u8 _18[0x1C - 0x18];
    /* 0x1C */ Control control;
    /* 0x60 */ u8 _60[0xEC - 0x60];
    /* 0xEC */ MtxPtr _EC;
} StaC2Bone;

typedef struct StaC2Actor {
    /* 0x00 */ u8 _00[0x06];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x18 - 0x08];
    /* 0x18 */ StaC2Bone** _18;
} StaC2Actor;

typedef struct {
    /* 0x000 */ u8 _000[0xC];
    /* 0x00C */ Vec _0C;
    /* 0x018 */ u8 _018[0x1CC - 0x18];
    /* 0x1CC */ Vec _1CC;
} StaC2Target;

typedef struct StaC2Model {
    /* 0x00 */ StaC2Actor* _00;
    /* 0x04 */ u8 _04[0x54 - 0x04];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ u8 _60[0x90 - 0x60];
} StaC2Model; // size: 0x90

typedef struct {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ f32 frame;
    /* 0x10 */ f32 speed;
    /* 0x14 */ u8 _14[0x24 - 0x14];
    /* 0x24 */ u16 length;
} StaC2Anim;

typedef struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u32 _08;
} StaC2Link;

typedef struct StaC2Draw {
    /* 0x00 */ Control control;
    /* 0x44 */ u8 _44[0x74 - 0x44];
    /* 0x74 */ StaC2Model* _74;
    /* 0x78 */ struct StadiumObjectCollision* _78;
    /* 0x7C */ u8 _7C[0x8C - 0x7C];
    /* 0x8C */ StaC2Anim* _8C;
    /* 0x90 */ u8 _90_7 : 1;
    /* 0x90 */ u8 _90_6 : 1;
    /* 0x90 */ u8 _90_5 : 1;
    /* 0x90 */ u8 _90_0 : 5;
    /* 0x91 */ u8 _91;
    /* 0x92 */ u8 _92;
    /* 0x93 */ u8 _93;
    /* 0x94 */ s16 _94;
    /* 0x96 */ s16 _96;
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A[0x9C - 0x9A];
    /* 0x9C */ u8 _9C;
    /* 0x9D */ u8 type;
    /* 0x9E */ u8 _9E[0xA0 - 0x9E];
    union {
        struct {
            /* 0xA0 */ Vec _A0;
            /* 0xAC */ Quaternion _AC;
            /* 0xBC */ f32 _BC;
            /* 0xC0 */ f32 _C0;
            /* 0xC4 */ f32 _C4;
            /* 0xC8 */ f32 _C8;
            /* 0xCC */ u8 _CC_D0[0xD0 - 0xCC];
            /* 0xD0 */ s8 _D0;
            /* 0xD1 */ u8 _D1;
        };
        struct {
            /* 0xA0 */ u8 _A0_B0[0xB0 - 0xA0];
            /* 0xB0 */ f32 _B0;
            /* 0xB4 */ u8 _B4_CA[0xCA - 0xB4];
            /* 0xCA */ u8 _CA;
            /* 0xCB */ u8 _CB;
            /* 0xCC */ u8 _CC;
        };
        struct {
            /* 0xA0 */ u8 _A0_C4[0xC4 - 0xA0];
            /* 0xC4 */ StaC2Target* target;
        };
        struct {
            /* 0xA0 */ f32 frame;
            /* 0xA4 */ f32 speed;
            /* 0xA8 */ u8* trigger;
            /* 0xAC */ u8 wait;
        };
        struct {
            /* 0xA0 */ StaC2Link* link;
        };
        struct {
            /* 0xA0 */ u8 _A0_C4_2[0xC4 - 0xA0];
            /* 0xC4 */ struct StaC2Spring* springs;
        };
        struct {
            /* 0xA0 */ u8 _A0_AC[0xAC - 0xA0];
            /* 0xAC */ f32 halfWidth;
        };
        struct {
            /* 0xA0 */ struct StaC2Draw* parent;
            /* 0xA4 */ Vec pos;
            /* 0xB0 */ Vec offset;
            /* 0xBC */ f32 radius;
        };
        /* 0xA0 */ u8 _A0_E8[0xE8 - 0xA0];
    };
} StaC2Draw; // size: 0xE8

typedef struct StaC2Particle {
    /* 0x00 */ struct StaC2Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    union {
        /* 0x1C */ Vec _1C;
        struct {
            /* 0x1C */ f32 grow;
            /* 0x20 */ f32 growScale;
            /* 0x24 */ f32 alpha;
        };
    };
    /* 0x28 */ u8 _28[0x38 - 0x28];
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 delay;
    /* 0x4A */ s16 life;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 duration;
} StaC2Particle;

typedef struct {
    /* 0x00 */ u8 _00[0xBC];
    /* 0xBC */ f32 _BC;
} StaC2EmitterSrc;

typedef struct {
    /* 0x00 */ u8 _00[0xA0];
    /* 0xA0 */ StaC2Draw* _A0;
    /* 0xA4 */ StaC2EmitterSrc* _A4;
    /* 0xA8 */ struct StaC2Emitter* _A8;
} StaC2EmitterOwner;

typedef struct StaC2Emitter {
    /* 0x00 */ u8 _00[0x0C];
    /* 0x0C */ StaC2Particle* particles;
    /* 0x10 */ void* _10;
    /* 0x14 */ u8 _14[0x20 - 0x14];
    /* 0x20 */ StaC2EmitterOwner* _20;
} StaC2Emitter;

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ s32 _04;
} StaC2ObjEntry; // size: 0x8

typedef struct {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ Vec _48;
    /* 0x54 */ u32 _54;
    /* 0x58 */ u8 _58[0x5C - 0x58];
    /* 0x5C */ s32 _5C;
    /* 0x60 */ u8 _60[0x69 - 0x60];
    /* 0x69 */ u8 _69;
} StaC2Sprite;

typedef struct {
    /* 0x00 */ StaC2Sprite* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} StaC2SpriteRef; // size: 0x8

typedef struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ u16 _14;
} StaC2Task;

typedef struct StaC2Spring {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ Vec _0C[2];
    /* 0x24 */ Vec _24;
    /* 0x30 */ Vec _30;
    /* 0x3C */ s32 _3C;
} StaC2Spring; // size: 0x40

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ Vec _34;
} StaC2Player;

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 dt;
    /* 0x1C */ f32 dt2;
    /* 0x20 */ s32 steps;
    /* 0x24 */ f32 _24;
} StaC2SpringParams; // size: 0x28

typedef struct StaC2Spawner {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ Vec pos;
} StaC2Spawner;

typedef struct StaC2Rec5C {
    /* 0x00 */ u8 _00[0x5C];
} StaC2Rec5C; // size: 0x5C

// fn_3_D67CC reads these from one pool base, so they are static
static SND_VOICEID lbl_3_data_182C0 = -1;
static SND_VOICEID lbl_3_data_182C4 = -1;
static StaC2Place34 lbl_3_data_182C8[3] = {
    { { 55.0f, 0.0f, 40.0f }, 0, 1, 1, 0, 0.0f, 180.0f, 0.0f, 0.0f, 180.0f, 0.0f, 160.0f, 120.0f, 1 },
    { { -55.0f, 0.0f, 40.0f }, 0, 1, 2, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 290.0f, 100.0f, 0 },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0 },
};
static StaC2Swing lbl_3_data_18364[6] = {
    { { 28.5f, 7.0f, 37.5f }, 3, 1, 1, 0, 30.0f, { 1.0f, 1.0f, 1.0f }, -60.0f, 45.0f, 60.0f, 10.0f, 4.0f },
    { { -28.5f, 7.0f, 37.5f }, 3, 1, 3, 0, 330.0f, { 1.0f, 1.0f, 1.0f }, -60.0f, -10.0f, 60.0f, -45.0f, 4.0f },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0, 0.0f, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
StaC2Place1C lbl_3_data_1849C[11] = {
    { { 0.0f, -5.0f, 40.0f }, 6, 1, 1, 0, 10.0f, 0.0f, 360.0f },
    { { 20.0f, -5.0f, 40.0f }, 6, 1, 2, 0, 10.0f, 0.0f, 360.0f },
    { { -20.0f, -5.0f, 40.0f }, 6, 1, 3, 0, 10.0f, 0.0f, 360.0f },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0, 0.0f, 0.0f, 0.0f },
};
static StaC2Place20 lbl_3_data_185D0[11] = {
    { { 37.4f, 0.0f, 8.0f }, 7, 1, 1, 0, { 1.0f, 1.0f, 1.0f }, -35.0f },
    { { 22.5f, 0.0f, -7.3f }, 7, 1, 1, 0, { 1.0f, 1.0f, 1.0f }, -25.0f },
    { { -22.5f, 0.0f, -7.3f }, 7, 1, 1, 0, { 1.0f, 1.0f, 1.0f }, 20.0f },
    { { -37.4f, 0.0f, 8.0f }, 7, 1, 1, 0, { 1.0f, 1.0f, 1.0f }, 0.0f },
    { { -43.34f, -3.6f, 87.797f }, 7, 1, 1, 0, { 1.0f, 0.85f, 1.0f }, -25.0f },
    { { -32.055f, -3.6f, 101.771f }, 7, 1, 1, 0, { 1.0f, 0.8f, 1.0f }, -15.0f },
    { { 31.884f, -3.6f, 101.246f }, 7, 1, 1, 0, { 1.0f, 0.8f, 1.0f }, 20.0f },
    { { 43.626f, -3.6f, 87.915f }, 7, 1, 1, 0, { 1.0f, 0.88f, 1.0f }, 25.0f },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
static StaC2Place lbl_3_data_18730[11] = {
    { { 0.0f, 0.15f, 60.0f }, 8, 1, 1, 0 },
    { { 20.0f, 0.15f, 60.0f }, 8, 1, 2, 0 },
    { { -20.0f, 0.15f, 60.0f }, 8, 1, 3, 0 },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0 },
};
static StaC2Place lbl_3_data_187E0[11] = {
    { { 0.0f, 0.0f, 0.0f }, 11, 1, 1, 0 },
    { { 0.0f, 0.0f, 0.0f }, 13, 0, 0, 0 },
};
StaC2Place34 lbl_3_data_18890 = { { 0.0f, 0.0f, 10.0f }, 0, 1, 1, 0, 0.0f, -90.0f, 0.0f, 30.0f, -120.0f, 0.0f, 0.0f, 360.0f, 0 };
static u8 lbl_3_data_188C4[0x1A] = {
    1, 2, 2, 4, 2, 2, 2, 2, 4, 2, 2, 2, 2, 6, 6, 8, 8, 9, 8, 9, 8, 8, 8, 9, 0, 0,
};
f32 lbl_3_data_188E0 = 0.1f;

typedef struct {
    /* 0x000 */ Vec pos;
    /* 0x00C */ u8 _00C[0x210 - 0xC];
    /* 0x210 */ u8 _210;
    /* 0x211 */ u8 _211[0x268 - 0x211];
} StaC2Fielder; // size: 0x268

extern StaC2Fielder g_Fielders[9];

extern struct {
    /* 0x00 */ StaC2Draw* _00;
    /* 0x04 */ u8 _04[0x14 - 0x04];
    /* 0x14 */ StaC2ObjEntry* _14;
    /* 0x18 */ u8 _18[0x30 - 0x18];
    /* 0x30 */ u32 _30;
    /* 0x34 */ u8 _34[0x3C - 0x34];
    /* 0x3C */ u32* _3C;
    /* 0x40 */ u16* _40;
    /* 0x44 */ s32* _44;
    /* 0x48 */ Vec* _48;
    /* 0x4C */ u8 _4C[0x64 - 0x4C];
    /* 0x64 */ s16 _64;
} lbl_3_common_bss_350E4;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern void fn_800528C0(f32 x, f32 y, f32 z, s16* screenX, s16* screenY);
extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ StaC2Player* _2C50[13];
} lbl_8036E548;

extern s32 fn_8005268C(void);
extern camera_803c639c_s* fn_80052734(s32 idx);
extern void fn_80033CC8(StaC2Particle* p, void* texture);
extern void fn_8003403C(f32 width, f32 height);
extern void fn_80025EEC(StaC2Anim* anim, s32, s32);
extern u16 lbl_3_data_81DC[16];
extern void fn_80033620(StaC2Emitter* emitter);
extern void* lbl_803CC1B8;
extern void fn_80034CEC(StaC2Task* task);
extern void fn_800B0A14_removeQueue(void);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern StaC2SpriteRef lbl_80371C30[];

// fn_3_B7F70 lies in unsplit code
extern s16 fn_3_B7F70(s16 range);
extern void AnimateActorBones(StaC2Actor* actor);
extern void fn_800B4CA0(StaC2Actor* actor, f32 frame);

// MWCC lays out .bss statics in reverse order of declaration
static u8 lbl_3_bss_ADD0[0x30];
static StaC2Spring lbl_3_bss_ABD0[8];
static StaC2Spring lbl_3_bss_A9D0[8];
static StaC2Spring lbl_3_bss_A8D0[4];
static StaC2SpringParams lbl_3_bss_A8A8;
static StaC2Task* lbl_3_bss_A8A4;
static u8 lbl_3_bss_A898[0xC];
static Vec lbl_3_bss_A820[10];
static u8 lbl_3_bss_A81C;
static StaC2Rec5C lbl_3_bss_A764[2];
static StaC2Rec5C lbl_3_bss_A3CC[10];
static StaC2Rec5C lbl_3_bss_A034[10];
static f32 lbl_3_bss_A030;
static u8 lbl_3_bss_A02D;
static u8 lbl_3_bss_A02C;
static u8 lbl_3_bss_A02B;
static u8 lbl_3_bss_A02A;
static u8 lbl_3_bss_A029;
static u8 lbl_3_bss_A028;
static u8 lbl_3_bss_A027;
static u8 lbl_3_bss_A026;
static u8 lbl_3_bss_A025;
static u8 lbl_3_bss_A024;
static u8 lbl_3_bss_A023;
static u8 lbl_3_bss_A022;
static u8 lbl_3_bss_A021;
static u8 lbl_3_bss_A020;
static u8* lbl_3_bss_A01C;
static u8 lbl_3_bss_A018;

static inline BOOL isSpriteDone(StaC2Task* task, s32 i) {
    return lbl_80371C30[task->_14 + i]._00->_69 == 2 ? TRUE : FALSE;
}

// .text:0x000D67CC size:0x2244 mapped:0x80715860
void fn_3_D67CC(void) {
    return;
}

// .text:0x000D6514 size:0x2B8 mapped:0x807155A8
void fn_3_D6514(void) {
    u32 n;
    s32 size;

    size = (lbl_3_common_bss_350E4._30 * sizeof(u16)) + (lbl_3_common_bss_350E4._30 * sizeof(u32)) + (lbl_3_common_bss_350E4._30 * sizeof(s32)) + (lbl_3_common_bss_350E4._30 * sizeof(Vec) * 2);
    if (lbl_3_common_bss_350E4._48 == NULL) {
        lbl_3_common_bss_350E4._48 = _OSAllocFromHeap(4, size);
        lbl_3_common_bss_350E4._3C = (u32*)(lbl_3_common_bss_350E4._48 + lbl_3_common_bss_350E4._30 * 2);
        lbl_3_common_bss_350E4._44 = (s32*)(lbl_3_common_bss_350E4._3C + lbl_3_common_bss_350E4._30);
        lbl_3_common_bss_350E4._40 = (u16*)(lbl_3_common_bss_350E4._44 + lbl_3_common_bss_350E4._30);
    }
    memset(lbl_3_common_bss_350E4._48, 0, size);
    n = 0;
    fn_3_D62F0(&n);
    fn_3_D5C8C(&n);
    lbl_3_common_bss_350E4._64 = n;
}

// .text:0x000D62F0 size:0x224 mapped:0x80715384
void fn_3_D62F0(u32* n) {
    Mtx m;
    Control control;
    StaC2Draw* draw;
    s32 idx;
    s32 i;
    u16 next;

    for (i = 0; i < lbl_3_bss_A02D; i++) {
        next = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
        idx = lbl_3_bss_A02C + i;
        lbl_3_common_bss_350E4._44[next] = idx;
        lbl_3_common_bss_350E4._3C[*n]++;
        draw = &lbl_3_common_bss_350E4._00[idx];
        control = draw->control;
        CTRLBuildMatrix(&control, m);
        fn_3_B8464(m, draw->_78);
        CTRLSetTranslation(&control, 14.250000447034836 + lbl_3_data_182C8[draw->_9C].pos.x,
                           -(9.375f + lbl_3_data_182C8[draw->_9C].pos.y),
                           14.250000447034836 + lbl_3_data_182C8[draw->_9C].pos.z);
        CTRLBuildMatrix(&control, m);
        fn_3_B8464(m, draw->_78);
        CTRLSetTranslation(&control, lbl_3_data_182C8[draw->_9C].pos.x - 14.250000447034836,
                           -(9.375f + lbl_3_data_182C8[draw->_9C].pos.y),
                           lbl_3_data_182C8[draw->_9C].pos.z - 14.250000447034836);
        CTRLBuildMatrix(&control, m);
        fn_3_B8464(m, draw->_78);
        if (lbl_3_common_bss_350E4._3C[*n] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
            (*n)++;
        }
    }
}

// .text:0x000D60C0 size:0x230 mapped:0x80715154
// 99.64%: r7 and r8 swap between the draw-table base and idx * 232 in the inner loop.
void fn_3_D60C0(u32* n) {
    StaC2Draw* draw;
    s32 next;
    s32 idx;
    Mtx m;
    s32 group;
    Control control;
    s32 i;

    for (group = 0; group < 3; group++) {
        next = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
        fn_3_B8574();
        for (i = 0; i < lbl_3_bss_A02B; i++) {
            if (group == lbl_3_data_18364[i]._0E && lbl_3_data_18364[i].type != 13) {
                idx = i + lbl_3_bss_A02A;
                if (lbl_3_common_bss_350E4._00[idx]._90_6) {
                    lbl_3_common_bss_350E4._44[next] = idx;
                    next++;
                    lbl_3_common_bss_350E4._3C[*n]++;
                    draw = &lbl_3_common_bss_350E4._00[idx];
                    control = draw->control;
                    CTRLSetTranslation(&control, lbl_3_data_18364[draw->_9C].pos.x,
                                       -(lbl_3_data_18364[draw->_9C].pos.y - 0.5),
                                       lbl_3_data_18364[draw->_9C].pos.z);
                    CTRLBuildMatrix(&control, m);
                    fn_3_B8464(m, draw->_78);
                    CTRLSetTranslation(&control, lbl_3_data_18364[draw->_9C].pos.x,
                                       -(0.5 + lbl_3_data_18364[draw->_9C].pos.y),
                                       lbl_3_data_18364[draw->_9C].pos.z);
                    CTRLBuildMatrix(&control, m);
                    fn_3_B8464(m, draw->_78);
                }
            }
        }
        if (lbl_3_common_bss_350E4._3C[*n] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
            (*n)++;
        }
    }
}

// .text:0x000D5E80 size:0x240 mapped:0x80714F14
void fn_3_D5E80(u32* n) {
    StaC2Draw* draw;
    s32 next;
    s32 idx;
    Mtx m;
    s32 group;
    Control control;
    s32 i;

    for (group = 0; group < 5; group++) {
        next = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
        fn_3_B8574();
        for (i = 0; i < lbl_3_bss_A025; i++) {
            if (group == lbl_3_data_1849C[i]._0E && lbl_3_data_1849C[i].type != 13) {
                idx = i + lbl_3_bss_A024;
                if (lbl_3_common_bss_350E4._00[idx]._90_6) {
                    lbl_3_common_bss_350E4._44[next] = idx;
                    next++;
                    lbl_3_common_bss_350E4._3C[*n]++;
                    draw = &lbl_3_common_bss_350E4._00[idx];
                    control = draw->control;
                    CTRLBuildMatrix(&control, m);
                    fn_3_B8464(m, draw->_78);
                    CTRLSetTranslation(&control, draw->halfWidth + lbl_3_data_1849C[draw->_9C].pos.x, 0.0f,
                                       draw->halfWidth + lbl_3_data_1849C[draw->_9C].pos.z);
                    CTRLBuildMatrix(&control, m);
                    fn_3_B8464(m, draw->_78);
                    CTRLSetTranslation(&control, lbl_3_data_1849C[draw->_9C].pos.x - draw->halfWidth, 0.0f,
                                       lbl_3_data_1849C[draw->_9C].pos.z - draw->halfWidth);
                    CTRLBuildMatrix(&control, m);
                    fn_3_B8464(m, draw->_78);
                }
            }
        }
        if (lbl_3_common_bss_350E4._3C[*n] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
            (*n)++;
        }
    }
}

// .text:0x000D5C8C size:0x1F4 mapped:0x80714D20
void fn_3_D5C8C(u32* n) {
    Control control;
    Mtx m;
    Mtx scale;
    s32 group;
    s32 i;
    s32 next;
    s32 idx;
    StaC2Draw* draw;
    StaC2Place* place;

    PSMTXIdentity(scale);
    PSMTXScale(scale, 2.0f, 2.0f, 2.0f);
    for (group = 0; group < 5; group++) {
        next = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
        fn_3_B8574();
        for (i = 0; i < lbl_3_bss_A023; i++) {
            place = &lbl_3_data_18730[i];
            if (group == place->_0E && place->type != 13) {
                idx = i + lbl_3_bss_A022;
                if (lbl_3_common_bss_350E4._00[idx]._90_6) {
                    lbl_3_common_bss_350E4._44[next] = idx;
                    next++;
                    lbl_3_common_bss_350E4._3C[*n]++;
                    draw = &lbl_3_common_bss_350E4._00[idx];
                    control = draw->control;
                    CTRLBuildMatrix(&control, m);
                    PSMTXConcat(m, scale, m);
                    fn_3_B8464(m, draw->_78);
                    m[1][3] *= 100.0f;
                    fn_3_B8464(m, draw->_78);
                }
            }
        }
        if (lbl_3_common_bss_350E4._3C[*n] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
            (*n)++;
        }
    }
}

// .text:0x000D5B6C size:0x120 mapped:0x80714C00
void fn_3_D5B6C(u32* n) {
    Control control;
    Mtx m;
    u16 next;
    StaC2Draw* draw;

    next = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
    lbl_3_common_bss_350E4._44[next] = lbl_3_bss_A020;
    lbl_3_common_bss_350E4._3C[*n]++;
    draw = &lbl_3_common_bss_350E4._00[lbl_3_bss_A020];
    control = draw->control;
    CTRLBuildMatrix(&control, m);
    fn_3_B8464(m, draw->_78);
    fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
    (*n)++;
}

// .text:0x000D55EC size:0x580 mapped:0x80714680
void fn_3_D55EC(void) {
    return;
}

// .text:0x000D5494 size:0x158 mapped:0x80714528
void fn_3_D5494(Mtx m) {
    Vec pos;
    StaC2Draw* draw;
    StaC2ObjEntry* entry;
    u32 i;
    u8 type;

    memcpy(&pos, &g_Ball, sizeof(Vec));
    PSMTXMultVec(m, &pos, &pos);
    for (i = 0; i < lbl_3_common_bss_350E4._30; i++) {
        entry = &lbl_3_common_bss_350E4._14[i];
        draw = &lbl_3_common_bss_350E4._00[entry->_04];
        if (draw->_90_7) {
            type = draw->type;
            if (type == 0 || type == 4 || type == 5 || (type > 7 && type < 11)) {
                entry->_00 = 1.0f;
            } else if (entry->_00 < 2.0f + pos.z) {
                entry->_00 = 1.0f;
            } else if (entry->_00 > 10.0f + pos.z) {
                entry->_00 = 0.25f;
            } else {
                entry->_00 = 1.0 - 0.75f * ((entry->_00 - (2.0f + pos.z)) / 8.0f);
            }
        }
    }
}

// .text:0x000D5470 size:0x24 mapped:0x80714504
s32 fn_3_D5470(const void* a, const void* b) {
    f32 fa = *(const f32*)a;
    f32 fb = *(const f32*)b;

    if (fa < fb) {
        return -1;
    }
    return fa > fb;
}

// .text:0x000D5444 size:0x2C mapped:0x807144D8
s32 fn_3_D5444(const void* a, const void* b) {
    u32 ua = *(const u32*)a;
    u32 ub = *(const u32*)b;

    if (ua < ub) {
        return -1;
    }
    return ua > ub;
}

// .text:0x000D53C0 size:0x84 mapped:0x80714454
s32 fn_3_D53C0(u8 id) {
    u32 i;

    for (i = lbl_3_common_bss_350E4._30; i != 0; i--) {
        if (id == lbl_3_common_bss_350E4._14[i - 1]._04) {
            return i - 1;
        }
    }
    // "came to a part with no return value"
    OSPanic("sta_c2.c", 2147, "//OZ \x96\xdf\x82\xe8\x92\x6c\x82\xcc\x96\xb3\x82\xa2\x95\x94\x95\xaa\x82\xc9\x97\x88\x82\xdc\x82\xb5\x82\xbd\x81\x42\n");
    return 0;
}

// .text:0x000D511C size:0x2A4 mapped:0x807141B0
void fn_3_D511C(void) {
    memset(&lbl_3_bss_A8A8, 0, sizeof(lbl_3_bss_A8A8));
    lbl_3_bss_A8A8._00 = 1.755f;
    lbl_3_bss_A8A8._04 = 0.5f;
    lbl_3_bss_A8A8._08 = 300.0f;
    lbl_3_bss_A8A8._0C = 20.0f;
    lbl_3_bss_A8A8._10 = 1.5f;
    lbl_3_bss_A8A8._14 = 0.001f;
    lbl_3_bss_A8A8.steps = 8;
    lbl_3_bss_A8A8.dt = 1.0f / lbl_3_bss_A8A8.steps / 60.0f;
    lbl_3_bss_A8A8.dt2 = lbl_3_bss_A8A8.dt * lbl_3_bss_A8A8.dt;
    lbl_3_bss_A8A8._24 = 1.0f / (2.0f * lbl_3_bss_A8A8.dt);
    fn_3_D501C(lbl_3_bss_ABD0);
    fn_3_D501C(lbl_3_bss_A9D0);
}

// .text:0x000D501C size:0x100 mapped:0x807140B0
void fn_3_D501C(StaC2Spring* springs) {
    u32 i;

    if (springs != NULL) {
        memset(springs, 0, sizeof(StaC2Spring));
        for (i = 0; i < 8; i++) {
            if (i == 7) {
                springs[i]._00 = lbl_3_data_188E0;
                springs[i]._08 = 0.504375f;
                springs[i]._3C = 1;
            } else {
                if (i == 0) {
                    springs[i]._3C = 1;
                }
                springs[i]._00 = lbl_3_data_188E0;
                springs[i]._08 = 0.504375f;
            }
            springs[i]._04 = 1.0f / springs[i]._00;
            memset(springs[i]._0C, 0, sizeof(springs[i]._0C));
            memset(&springs[i]._24, 0, sizeof(springs[i]._24));
            memset(&springs[i]._30, 0, sizeof(springs[i]._30));
        }
    }
}

// .text:0x000D4E00 size:0x21C mapped:0x80713E94
void fn_3_D4E00(void) {
    return;
}

// .text:0x000D4CA4 size:0x15C mapped:0x80713D38
void fn_3_D4CA4(void) {
    return;
}

// .text:0x000D4780 size:0x524 mapped:0x80713814
void fn_3_D4780(void) {
    return;
}

// .text:0x000D3F54 size:0x82C mapped:0x80712FE8
void fn_3_D3F54(void) {
    return;
}

// .text:0x000D3CDC size:0x278 mapped:0x80712D70
void fn_3_D3CDC(void) {
    return;
}

// .text:0x000D3880 size:0x45C mapped:0x80712914
void fn_3_D3880(void) {
    return;
}

// .text:0x000D36B0 size:0x1D0 mapped:0x80712744
void fn_3_D36B0(void) {
    return;
}

// .text:0x000D30D0 size:0x5E0 mapped:0x80712164
void fn_3_D30D0(void) {
    return;
}

// .text:0x000D2A0C size:0x6C4 mapped:0x80711AA0
void fn_3_D2A0C(void) {
    return;
}

// .text:0x000D278C size:0x280 mapped:0x80711820
void fn_3_D278C(void) {
    return;
}

// .text:0x000D2684 size:0x108 mapped:0x80711718
Vec* fn_3_D2684(StaC2Draw* draw) {
    Vec diff;
    u8 right[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    u8 left[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    u8* order;
    u32 i;
    StaC2Player* player;

    if (draw->_A0.x > 0.0f) {
        order = right;
    } else {
        order = left;
    }
    for (i = 0; i < 4; i++) {
        player = lbl_8036E548._2C50[order[i]];
        if (player != NULL) {
            PSVECSubtract(&draw->_A0, &player->_34, &diff);
            if (PSVECMag(&diff) <= 12.5f) {
                return &player->_34;
            }
        }
    }
    return NULL;
}

// .text:0x000D255C size:0x128 mapped:0x807115F0
s8 fn_3_D255C(StaC2Draw* draw) {
    Vec diff;
    u8 right[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    u8 left[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    u32 i;
    u8* order;
    StaC2Fielder* fielder;

    if (draw->_A0.y > 3.0) {
        return -1;
    }
    if (draw->_A0.x > 0.0f) {
        order = right;
    } else {
        order = left;
    }
    for (i = 0; i < 9; i++) {
        fielder = &g_Fielders[order[i]];
        if (fielder != NULL && fielder->_210 == 0) {
            PSVECSubtract(&draw->_A0, &fielder->pos, &diff);
            if (PSVECMag(&diff) <= 4.5) {
                return order[i];
            }
        }
    }
    return -1;
}

// .text:0x000D24E8 size:0x74 mapped:0x8071157C
void fn_3_D24E8(StaC2Draw* draw, s8 fielder) {
    Vec dir;

    PSVECSubtract(&g_Fielders[fielder].pos, &draw->_A0, &dir);
    dir.y = 0.0f;
    PSVECNormalize(&dir, &dir);
    fn_3_253A4(fielder, fn_3_9FB8C(dir.x, dir.z));
}

// .text:0x000D249C size:0x4C mapped:0x80711530
BOOL fn_3_D249C(StaC2Draw* draw) {
    Vec diff;

    PSVECSubtract(&draw->target->_1CC, &draw->target->_0C, &diff);
    return PSVECMag(&diff) > 14.250000447034836;
}

// .text:0x000D233C size:0x160 mapped:0x807113D0
InMemBallType* fn_3_D233C(StaC2Draw* draw) {
    Mtx m;
    Vec diff;
    Vec dir;
    Vec fwd = { 1.0f, 0.0f, 0.0f };
    Vec axis = { 0.0f, 1.0f, 0.0f };
    Vec pos = draw->_A0;

    if (g_Ball.AtBat_ContactResult >= 2) {
        return NULL;
    }
    pos.y = 4.5f;
    PSVECSubtract((Vec*)&g_Ball, &pos, &diff);
    diff.y = 0.0f;
    if (PSVECMag(&diff) < 23.0f) {
        PSVECNormalize(&diff, &diff);
        PSMTXRotAxisRad(m, &axis, 0.017453292f * draw->_C0);
        PSMTXMultVec(m, &fwd, &dir);
        if (57.29578f * acosf_kludge(PSVECDotProduct(&diff, &dir)) <= 60.0f) {
            return &g_Ball;
        }
    }
    return NULL;
}

// .text:0x000D2220 size:0x11C mapped:0x807112B4
void fn_3_D2220(void) {
    return;
}

// .text:0x000D1F2C size:0x2F4 mapped:0x80710FC0
void fn_3_D1F2C(void) {
    return;
}

// .text:0x000D1B24 size:0x408 mapped:0x80710BB8
void fn_3_D1B24(void) {
    return;
}

// .text:0x000D1AC4 size:0x60 mapped:0x80710B58
void fn_3_D1AC4(StaC2Draw* draw) {
    StaC2TexRegs* regs = draw->_74->_00->_18[0]->_14->_10->_04;

    if (draw->_CA == 0) {
        regs->_74 &= ~0x1FFF;
        regs->_74 |= 3;
    } else {
        regs->_74 &= ~0x1FFF;
        regs->_74 |= 2;
    }
}

// .text:0x000D196C size:0x158 mapped:0x80710A00
void fn_3_D196C(s32 idx) {
    StaC2Draw* draw = &lbl_3_common_bss_350E4._00[idx];
    Vec pos;
    s32 slot;

    if (g_Ball.ballState != 1) {
        if (draw->_CA == 0) {
            draw->_99 &= 0xFB;
            draw->_CC = 5;
            draw->_CB = draw->_CA;
            draw->_CA = 2;
            draw->_B0 = 0.5f;
            fn_80025EEC(draw->_8C, 0, 3);
        }
        memcpy(&pos, &g_Ball, sizeof(Vec));
        pos.y *= -1.0f;
        fn_3_8BBC4(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 5, &pos, NULL, 13);
        slot = g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy != 0;
        lbl_3_bss_A898[slot] = 1;
        lbl_3_bss_A820[slot].x = g_Ball.AtBat_Contact_BallPos.x;
        lbl_3_bss_A820[slot].y = -g_Ball.AtBat_Contact_BallPos.y;
        lbl_3_bss_A820[slot].z = g_Ball.AtBat_Contact_BallPos.z;
        fn_3_65A8();
        fn_3_27648();
        g_FieldingLogic._13B = 1;
    }
}

// .text:0x000D1848 size:0x124 mapped:0x807108DC
void fn_3_D1848(StaC2Draw* draw) {
    StaC2Model* model = draw->_74;

    if (*draw->trigger != 0) {
        if (draw->_90_7) {
            draw->_90_7 = 0;
            draw->wait = draw->_9C % 3 * 30;
            draw->frame = 0.0f;
            model->_5C = draw->frame;
            model->_59 = 1;
            fn_800B4CA0(model->_00, model->_5C);
        }
    } else if (draw->wait != 0) {
        if (draw->_90_7) {
            draw->_90_7 = 0;
        }
        draw->wait--;
    } else {
        if (!draw->_90_7) {
            draw->_90_7 = 1;
        }
        draw->frame += draw->speed;
        if (draw->frame > 100.0f) {
            draw->frame -= 100.0f;
            draw->wait = 90;
        }
        AnimateActorBones(model->_00);
    }
}

// .text:0x000D173C size:0x10C mapped:0x807107D0
void fn_3_D173C(StaC2Draw* draw) {
    Mtx m;
    Mtx rot;
    u32 i;
    f32 angle = 3.1415927f;

    PSMTXInverse(fn_80052734(fn_8005268C())->view, m);
    PSMTXIdentity(rot);
    rot[0][0] = cosf_kludge(angle);
    rot[0][2] = -sinf_kludge(angle);
    rot[2][0] = sinf_kludge(angle);
    rot[2][2] = cosf_kludge(angle);
    PSMTXConcat(m, rot, m);
    m[0][3] = m[1][3] = m[2][3] = 0.0f;
    for (i = 0; i < draw->_74->_00->_06; i++) {
        PSMTXConcat(m, draw->_74->_00->_18[i]->_EC, draw->_74->_00->_18[i]->_EC);
    }
}

// .text:0x000D141C size:0x320 mapped:0x807104B0
void fn_3_D141C(void) {
    return;
}

// .text:0x000D1280 size:0x19C mapped:0x80710314
void fn_3_D1280(void) {
    return;
}

// .text:0x000D127C size:0x4 mapped:0x80710310
void fn_3_D127C(void) {
    return;
}

// .text:0x000D1110 size:0x16C mapped:0x807101A4
void fn_3_D1110(StaC2Draw* draw) {
    fn_3_D1004(draw, lbl_3_data_18364[draw->_9C].pos.x, lbl_3_data_18364[draw->_9C].pos.y,
               lbl_3_data_18364[draw->_9C].pos.z, lbl_3_data_18364[draw->_9C]._10, 0.0f);
    draw->_C8 = lbl_3_data_18364[draw->_9C].pos.y;
    draw->_BC = 0.0f;
    draw->_C4 = 0.0f;
    draw->_D1 = 0;
}

// .text:0x000D1004 size:0x10C mapped:0x80710098
void fn_3_D1004(StaC2Draw* draw, f32 x, f32 y, f32 z, f32 rotY, f32 tilt) {
    StaC2Bone* bone = draw->_74->_00->_18[3];
    Vec axis = { 0.0f, 1.0f, 0.0f };
    Quaternion q;

    draw->_A0.x = x;
    draw->_A0.y = y;
    draw->_A0.z = z;
    draw->_C0 = tilt;
    draw->control.type = 0;
    CTRLSetTranslation(&draw->control, draw->_A0.x, -draw->_A0.y, draw->_A0.z);
    CTRLSetRotation(&draw->control, 0.0f, rotY, 0.0f);
    C_QUATRotAxisRad(&q, &axis, 0.017453292f * draw->_C0);
    PSQUATMultiply(&q, &draw->_AC, &q);
    PSQUATNormalize(&q, &q);
    CTRLSetQuat(&bone->control, q.x, q.y, q.z, q.w);
}

// .text:0x000D0918 size:0x6EC mapped:0x8070F9AC
void fn_3_D0918(void) {
    return;
}

// .text:0x000D0854 size:0xC4 mapped:0x8070F8E8
f32 fn_3_D0854(StaC2Draw* draw) {
    f32 base;
    f32 range;

    if (draw->_D0 > 0) {
        base = lbl_3_data_18364[draw->_9C]._20;
        range = lbl_3_data_18364[draw->_9C]._24;
    } else {
        base = lbl_3_data_18364[draw->_9C]._28;
        range = lbl_3_data_18364[draw->_9C]._2C;
    }
    return base + range * (fn_3_B7F70(1000) / 1000.0);
}

// .text:0x000D0534 size:0x320 mapped:0x8070F5C8
void fn_3_D0534(void) {
    return;
}

// .text:0x000D052C size:0x8 mapped:0x8070F5C0
s32 fn_3_D052C(void) {
    return 0;
}

// .text:0x000D0528 size:0x4 mapped:0x8070F5BC
void fn_3_D0528(void) {
    return;
}

// .text:0x000D0490 size:0x98 mapped:0x8070F524
void fn_3_D0490(void) {
    s32 idx = (g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy != 0) + 2;

    lbl_3_bss_A898[idx] = 1;
    lbl_80371C30[lbl_3_bss_A8A4->_14 + idx]._00->_48.x = g_Ball.AtBat_Contact_BallPos.x;
    lbl_80371C30[lbl_3_bss_A8A4->_14 + idx]._00->_48.y = -g_Ball.AtBat_Contact_BallPos.y;
    lbl_80371C30[lbl_3_bss_A8A4->_14 + idx]._00->_48.z = g_Ball.AtBat_Contact_BallPos.z;
}

// .text:0x000D0284 size:0x20C mapped:0x8070F318
void fn_3_D0284(void* arg) {
    StaC2Draw* draw = arg;
    u8 state = draw->parent->_D1;
    f32 angle;
    s32 alpha;

    if (state == 0) {
        if (draw->_90_7) {
            draw->_90_7 = 0;
        }
        if (draw->_92 != 255) {
            draw->_92 = 255;
        }
        if (draw->radius != 1.0) {
            draw->radius = 1.0f;
        }
    } else {
        if (!draw->_90_7) {
            draw->_90_7 = 1;
        }
        CTRLSetRotation(&draw->control, 0.0f, draw->parent->_C0, 0.0f);
        angle = 0.017453292f * (rand() % 360);
        draw->offset.x = draw->radius * cosf_kludge(angle);
        draw->offset.z = draw->radius * sinf_kludge(angle);
        CTRLSetTranslation(&draw->control, draw->pos.x + draw->offset.x, 0.0f, draw->pos.z + draw->offset.z);
        if (state == 3) {
            alpha = draw->_92;
            alpha -= 1.7f;
            if (alpha < 0) {
                alpha = 0;
            }
            draw->_92 = alpha;
            draw->radius -= 1.0 / 150.0;
            if (draw->radius < 0.0f) {
                draw->radius = 0.0f;
            }
        }
    }
}

// .text:0x000D0280 size:0x4 mapped:0x8070F314
void fn_3_D0280(void) {
    return;
}

// .text:0x000D00D0 size:0x1B0 mapped:0x8070F164
void fn_3_D00D0(void) {
    return;
}

// .text:0x000D00CC size:0x4 mapped:0x8070F160
void fn_3_D00CC(void) {
    return;
}

// .text:0x000CFD58 size:0x374 mapped:0x8070EDEC
void fn_3_CFD58(void) {
    return;
}

// .text:0x000CFB44 size:0x214 mapped:0x8070EBD8
BOOL fn_3_CFB44(StaC2Emitter* emitter) {
    StaC2Particle* p = emitter->particles;
    StaC2EmitterOwner* owner = emitter->_20;
    s32 alpha;

    fn_80033620(emitter);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    do {
        if (p->delay <= 0 && p->life != 0) {
            fn_8003403C(p->_38, p->_3C);
            fn_80033CC8(p, emitter->_10);
            p->_38 += 0.1;
            if (p->_38 < 0.0f) {
                p->_38 = 0.0f;
            }
            p->_3C += 0.1;
            if (p->_3C < 0.0f) {
                p->_3C = 0.0f;
            }
            alpha = p->color[3];
            alpha -= 8;
            if (alpha < 0) {
                alpha = 0;
            }
            p->color[3] = alpha;
            p->pos.x += p->vel.x;
            p->pos.y -= p->vel.y;
            p->pos.z += p->vel.z;
            p->life--;
        }
        p->delay--;
        if (p->life == 0) {
            fn_3_CFAB4(p, emitter);
        }
        p = p->next;
    } while (p != NULL);
    if (owner->_A0->_D1 == 0) {
        owner->_A8 = NULL;
        return TRUE;
    }
    return FALSE;
}

// .text:0x000CFAB4 size:0x90 mapped:0x8070EB48
void fn_3_CFAB4(StaC2Particle* particle, StaC2Emitter* emitter) {
    StaC2EmitterSrc* src = emitter->_20->_A4;

    particle->pos.x = particle->_1C.x;
    particle->pos.y = particle->_1C.y;
    particle->pos.z = particle->_1C.z;
    particle->_38 = particle->_3C = 3.0 * src->_BC;
    particle->color[0] = particle->color[1] = particle->color[2] = 255;
    particle->color[3] = 255.0 * src->_BC;
    particle->life = 30;
    particle->delay = 0;
}

// .text:0x000CFA8C size:0x28 mapped:0x8070EB20
void fn_3_CFA8C(StaC2Draw* draw) {
    AnimateActorBones(draw->_74->_00);
}

// .text:0x000CFA88 size:0x4 mapped:0x8070EB1C
void fn_3_CFA88(void) {
    return;
}

// .text:0x000CF930 size:0x158 mapped:0x8070E9C4
void fn_3_CF930(StaC2Draw* draw) {
    StaC2Anim* anim = draw->_8C;
    u16 length;
    f32 speed;
    f32 step;

    if (anim != NULL) {
        length = anim->length;
        speed = anim->speed;
        if (anim->frame == length) {
            CTRLSetTranslation(&draw->control, lbl_3_data_18730[draw->_9C].pos.x, 5.0f,
                               lbl_3_data_18730[draw->_9C].pos.z);
            draw->_8C = NULL;
            draw->_90_7 = 0;
        }
        step = 255.0f / (length / speed);
        if (draw->_92 <= step) {
            draw->_92 = 0;
        } else {
            draw->_92 -= step;
        }
    }
    if (draw->link != NULL && draw->link->_08 == 0) {
        draw->link = NULL;
    }
}

// .text:0x000CF92C size:0x4 mapped:0x8070E9C0
void fn_3_CF92C(void) {
    return;
}

// .text:0x000CF72C size:0x200 mapped:0x8070E7C0
void fn_3_CF72C(void) {
    return;
}

// .text:0x000CF278 size:0x4B4 mapped:0x8070E30C
void fn_3_CF278(void) {
    return;
}

// .text:0x000CEFA8 size:0x2D0 mapped:0x8070E03C
void fn_3_CEFA8(void) {
    return;
}

// .text:0x000CEE5C size:0x14C mapped:0x8070DEF0
void fn_3_CEE5C(StaC2Particle* p, void* texture) {
    fn_8003403C(p->_38, p->_3C);
    fn_80033CC8(p, texture);
    if (lbl_80366158._28 == 0) {
        if (-p->delay < 5) {
            p->_38 += 0.38;
            p->_3C += 0.38;
            p->color[3] += 34.0;
        } else {
            p->color[3] += -6.8;
        }
        p->pos.x += p->vel.x;
        p->pos.y += p->vel.y;
        p->pos.z += p->vel.z;
    }
}

// .text:0x000CED40 size:0x11C mapped:0x8070DDD4
void fn_3_CED40(StaC2Particle* p, void* texture) {
    fn_8003403C(p->_38, p->_3C);
    fn_80033CC8(p, texture);
    if (lbl_80366158._28 == 0) {
        if (-p->delay < 5) {
            p->_38 += 0.38;
            p->_3C += 0.38;
            p->color[3] += 34.0;
        } else {
            p->color[3] -= 4;
        }
        p->pos.x += p->vel.x;
        p->pos.y += p->vel.y;
        p->pos.z += p->vel.z;
    }
}

// .text:0x000CED3C size:0x4 mapped:0x8070DDD0
void fn_3_CED3C(void) {
    return;
}

// .text:0x000CED38 size:0x4 mapped:0x8070DDCC
void fn_3_CED38(void) {
    return;
}

// .text:0x000CED34 size:0x4 mapped:0x8070DDC8
void fn_3_CED34(void) {
    return;
}

// .text:0x000CED30 size:0x4 mapped:0x8070DDC4
void fn_3_CED30(void) {
    return;
}

// .text:0x000CEC98 size:0x98 mapped:0x8070DD2C
void fn_3_CEC98(void) {
    s32 idx = (g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy != 0) + 8;

    lbl_3_bss_A898[idx] = 1;
    lbl_80371C30[lbl_3_bss_A8A4->_14 + idx]._00->_48.x = g_Ball.AtBat_Contact_BallPos.x;
    lbl_80371C30[lbl_3_bss_A8A4->_14 + idx]._00->_48.y = -g_Ball.AtBat_Contact_BallPos.y;
    lbl_80371C30[lbl_3_bss_A8A4->_14 + idx]._00->_48.z = g_Ball.AtBat_Contact_BallPos.z;
}

// .text:0x000CEBBC size:0xDC mapped:0x8070DC50
void fn_3_CEBBC(Vec* pos, s32 i) {
    s16 x;
    s16 y;

    fn_800528C0(pos->x, pos->y, pos->z, &x, &y);
    lbl_80371C30[lbl_3_bss_A8A4->_14 + i]._00->_48.x = x;
    lbl_80371C30[lbl_3_bss_A8A4->_14 + i]._00->_48.y = y;
    lbl_80371C30[lbl_3_bss_A8A4->_14 + i]._00->_48.z = 0.0f;
}

// .text:0x000CE954 size:0x268 mapped:0x8070D9E8
void fn_3_CE954(void) {
    StaC2Task* task = lbl_803CC1B8;
    s32 i;

    for (i = 0; i < 10; i++) {
        switch (lbl_3_bss_A898[i]) {
        case 1:
            fn_3_CEBBC(&lbl_3_bss_A820[i], i);
            lbl_80371C30[task->_14 + i]._00->_5C = 0;
            lbl_80371C30[task->_14 + i]._00->_54 |= 2;
            lbl_3_bss_A898[i] = 2;
            break;
        case 2:
            fn_3_CEBBC(&lbl_3_bss_A820[i], i);
            if (isSpriteDone(task, i)) {
                lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                lbl_3_bss_A898[i] = 0;
            }
            break;
        }
    }
    if (lbl_3_bss_A81C) {
        fn_800B0A14_removeQueue();
        fn_80034CEC(lbl_3_bss_A8A4);
        lbl_3_bss_A81C = 0;
    }
}

// .text:0x000CE8E4 size:0x70 mapped:0x8070D978
void fn_3_CE8E4(void) {
    return;
}

// .text:0x000CE56C size:0x378 mapped:0x8070D600
void fn_3_CE56C(void) {
    return;
}

// .text:0x000CDFA4 size:0x5C8 mapped:0x8070D038
void fn_3_CDFA4(void) {
    return;
}

// .text:0x000CDD90 size:0x214 mapped:0x8070CE24
void fn_3_CDD90(StaC2Particle* p) {
    p->_38 += p->growScale * (4.0 * p->grow / p->duration);
    p->_3C += p->growScale * (-2.0 * p->grow / p->duration);
    p->alpha += -255.0f / p->duration;
    if (p->alpha < 0.0f) {
        p->alpha = 0.0f;
    }
    p->color[3] = p->alpha;
    p->color[0] = lbl_3_bss_A01C[0] * (p->color[3] / 255.0);
    p->color[1] = lbl_3_bss_A01C[1] * (p->color[3] / 255.0);
    p->color[2] = lbl_3_bss_A01C[2] * (p->color[3] / 255.0);
    p->pos.x += p->vel.x;
    p->pos.y -= p->vel.y;
    p->pos.z += p->vel.z;
    p->life--;
}

// .text:0x000CDB48 size:0x248 mapped:0x8070CBDC
void fn_3_CDB48(StaC2Particle* p, StaC2Spawner* spawner) {
    f32 angle = 0.017453292f * (rand() % 360);

    p->vel.x = 0.01 * cosf_kludge(angle);
    p->vel.z = 0.01 * sinf_kludge(angle);
    p->vel.y = 0.12f;
    p->grow = 0.5f;
    p->grow += (u32)rand() % 2500 / 1000.0;
    p->_38 = 2.0 * p->grow;
    p->_3C = 6.0 * p->grow;
    p->growScale = rand() % 101 / 100.0;
    p->duration = p->life = rand() % 24 + 72;
    p->pos.x = spawner->pos.x;
    p->pos.y = spawner->pos.y;
    p->pos.z = spawner->pos.z;
    p->color[3] = p->alpha = 255.0f;
    p->life = p->duration;
    p->delay = 0;
}

// .text:0x000CD968 size:0x1E0 mapped:0x8070C9FC
// 93.77%: the target loads pos->x before pos->y for the corners and computes them in other
// FPRs; the permuter found nothing better.
BOOL fn_3_CD968(Vec* pos, f32 width, f32 height) {
    Vec out;
    Vec corners[4];
    camera_803c639c_s* camera;
    u32 i;
    u8 code;
    u8 all = 0;
    f32 left;
    f32 right;
    f32 bottom;
    f32 top;

    camera = fn_80052734(fn_8005268C());
    PSMTXMultVec(camera->view, pos, pos);
    if (pos->z > -1.0f || pos->z < -512.0f) {
        return FALSE;
    }
    bottom = pos->y - height * 0.5f;
    right = pos->x + width * 0.5f;
    left = pos->x - width * 0.5f;
    top = pos->y + height * 0.5f;
    corners[0].z = corners[1].z = corners[2].z = corners[3].z = pos->z;
    corners[0].x = corners[3].x = left;
    corners[1].x = corners[2].x = right;
    corners[0].y = corners[1].y = bottom;
    corners[3].y = corners[2].y = top;
    for (i = 0; i < 4; i++) {
        PSMTX44MultVec(camera->proj, &corners[i], &out);
        code = out.x < -1.0f;
        code |= (out.x > 1.0f) << 1;
        code |= (out.y < -1.0f) << 2;
        code |= (out.y > 1.0f) << 3;
        if (code == 0) {
            return TRUE;
        }
        all &= code;
    }
    if ((all & 3U) == 1 || (all & 3U) == 2) {
        return FALSE;
    }
    if ((all & 0xCU) == 4 || (all & 0xCU) == 8) {
        return FALSE;
    }
    return TRUE;
}

// .text:0x000CD958 size:0x10 mapped:0x8070C9EC
void fn_3_CD958(void) {
    lbl_3_bss_A81C = 1;
}

// .text:0x000CCC24 size:0xD34 mapped:0x8070BCB8
void fn_3_CCC24(void) {
    return;
}

// .text:0x000CC81C size:0x408 mapped:0x8070B8B0
void fn_3_CC81C(void) {
    return;
}

// .text:0x000CC5C4 size:0x258 mapped:0x8070B658
void fn_3_CC5C4(StaC2Draw* draw) {
    draw->_CA = g_Minigame._1B19;
    fn_80025EEC(draw->_8C, 0, 2);
    draw->_CB = draw->_CA;
    draw->_90_7 = 1;
    draw->control.type = 0;
    CTRLSetScale(&draw->control, 0.75f, 0.75f, 0.75f);
    draw->_A0.x = g_Minigame._1AE0;
    draw->_A0.y = g_Minigame._1AE4;
    draw->_A0.z = g_Minigame._1AE8;
    draw->_C0 = shortAngleToRad(g_Minigame._1AF8);
    CTRLSetRotation(&draw->control, 0.0f, draw->_C0, 0.0f);
    CTRLSetTranslation(&draw->control, draw->_A0.x, -draw->_A0.y, draw->_A0.z);
    fn_3_CC438();
    fn_3_CBF80(draw);
}

// .text:0x000CC438 size:0x18C mapped:0x8070B4CC
void fn_3_CC438(void) {
    lbl_3_bss_A8A8._00 = 1.755f;
    lbl_3_bss_A8A8._04 = 0.5f;
    lbl_3_bss_A8A8._08 = 300.0f;
    lbl_3_bss_A8A8._0C = 20.0f;
    lbl_3_bss_A8A8._10 = 1.5f;
    lbl_3_bss_A8A8._14 = 0.001f;
    lbl_3_bss_A8A8.steps = 8;
    lbl_3_bss_A8A8.dt = 1.0f / lbl_3_bss_A8A8.steps / 60.0f;
    lbl_3_bss_A8A8.dt2 = lbl_3_bss_A8A8.dt * lbl_3_bss_A8A8.dt;
    lbl_3_bss_A8A8._24 = 1.0f / (2.0f * lbl_3_bss_A8A8.dt);
    fn_3_CC354(lbl_3_bss_A8D0);
}

// .text:0x000CC354 size:0xE4 mapped:0x8070B3E8
void fn_3_CC354(StaC2Spring* springs) {
    u32 i;

    if (springs != NULL) {
        for (i = 0; i < 4; i++) {
            if (i == 3) {
                springs[i]._00 = lbl_3_data_188E0;
                springs[i]._08 = 0.504375f;
                springs[i]._3C = 1;
            } else {
                springs[i]._00 = lbl_3_data_188E0;
                springs[i]._08 = 0.504375f;
            }
            springs[i]._04 = 1.0f / springs[i]._00;
            memset(springs[i]._0C, 0, sizeof(springs[i]._0C));
            memset(&springs[i]._24, 0, sizeof(springs[i]._24));
            memset(&springs[i]._30, 0, sizeof(springs[i]._30));
        }
    }
}

// .text:0x000CC1D4 size:0x180 mapped:0x8070B268
void fn_3_CC1D4(void) {
    Mtx m;
    f32 angle;
    Vec offset;
    StaC2Draw* draw;
    u32 start;
    u32 i;
    StaC2Model* model;

    angle = shortAngleToRad(g_Minigame._1AF8);
    PSMTXRotRad(m, 'Y', 0.017453292f * -angle);
    offset.x = 4.5f;
    offset.y = 9.0f;
    offset.z = 0.0f;
    PSMTXMultVec(m, &offset, &offset);
    for (start = 0; start < lbl_3_common_bss_350E4._30; start++) {
        if (lbl_3_common_bss_350E4._00[start].type == 1) {
            break;
        }
    }
    for (i = start; i < start + 3; i++) {
        draw = &lbl_3_common_bss_350E4._00[i];
        CTRLSetTranslation(&draw->control, g_Minigame._1AE0 + offset.x, g_Minigame._1AE4 - offset.y,
                           g_Minigame._1AE8 + offset.z);
        model = draw->_74;
        draw->wait = i % 3 * 30;
        draw->frame = 0.0f;
        model->_5C = draw->frame;
        model->_59 = 1;
        fn_800B4CA0(model->_00, model->_5C);
    }
}

// .text:0x000CBF80 size:0x254 mapped:0x8070B014
void fn_3_CBF80(StaC2Draw* draw) {
    Control control;
    Mtx m;
    Vec offset = { -4.5f, 0.0f, 0.0f };
    Vec pos;
    u32 i;
    f32 dy;
    f32 dz;

    offset.y = -4.5f;
    control.type = 0;
    CTRLSetRotation(&control, 0.0f, draw->_C0, 0.0f);
    CTRLBuildMatrix(&control, m);
    PSMTXMultVec(m, &offset, &offset);
    offset.y *= -1.0f;
    offset.x += draw->_A0.x;
    offset.y += draw->_A0.y;
    offset.z += draw->_A0.z;
    pos = offset;
    for (i = 4; i != 0; i--) {
        draw->springs[i - 1]._0C[0].x = pos.x;
        draw->springs[i - 1]._0C[0].y = pos.y;
        draw->springs[i - 1]._0C[0].z = pos.z;
        pos.y -= 2.4f;
        if (pos.y - 0.15000000223517418 < 0.0) {
            dy = 0.15000000223517418 - pos.y;
            dz = 2.4f * cosf_kludge(acosf_kludge(dy / 2.4f));
            pos.y = 0.15f;
            pos.z += dz;
        }
    }
    for (i = 0; i < 4; i++) {
        draw->springs[i]._0C[1] = draw->springs[i]._0C[0];
        memset(&draw->springs[i]._24, 0, sizeof(Vec));
        memset(&draw->springs[i]._30, 0, sizeof(Vec));
    }
}

// .text:0x000CBC18 size:0x368 mapped:0x8070ACAC
void fn_3_CBC18(void) {
    return;
}

// .text:0x000CBAFC size:0x11C mapped:0x8070AB90
void fn_3_CBAFC(void) {
    return;
}

// .text:0x000CBA9C size:0x60 mapped:0x8070AB30
void fn_3_CBA9C(StaC2Draw* draw) {
    StaC2TexRegs* regs = draw->_74->_00->_18[0]->_14->_10->_04;

    if (draw->_CA == 0) {
        regs->_74 &= ~0x1FFF;
        regs->_74 |= 3;
    } else {
        regs->_74 &= ~0x1FFF;
        regs->_74 |= 2;
    }
}

// .text:0x000CB8A8 size:0x1F4 mapped:0x8070A93C
void fn_3_CB8A8(StaC2Draw* draw) {
    switch (draw->_CA) {
    case 0:
        fn_80025EEC(draw->_8C, 0, 2);
        fn_3_CC1D4();
        break;
    case 3:
        fn_80025EEC(draw->_8C, 0, 4);
        break;
    case 1:
        fn_80025EEC(draw->_8C, 0, 3);
        break;
    case 2:
    default:
        fn_80025EEC(draw->_8C, 0, 1);
        break;
    }
}
