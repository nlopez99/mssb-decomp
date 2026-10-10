#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_0F60.h"
#include "menus/rep_10C0.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "C3/anim.h"
#include "Dolphin/vec.h"
#include "string.h"
#include "menus/rep_08E8.h"

typedef struct Model0F60 {
    /* 0x00 */ struct ActorObj0F60* _00;
    /* 0x04 */ u8 _04[0x10 - 0x04];
    /* 0x10 */ Control control;
    /* 0x54 */ u8 _54[0x6C - 0x54];
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D[0x70 - 0x6D];
    /* 0x70 */ void* _70;
    /* 0x74 */ u8 _74[0x90 - 0x74];
} Model0F60; // size: 0x90

typedef struct ModelTable0F60 {
    /* 0x00 */ u16 count;
    /* 0x04 */ Mtx _04;
    /* 0x34 */ Model0F60 models[1];
} ModelTable0F60;

typedef struct Bone0F60 {
    /* 0x000 */ u16 _000;
    /* 0x002 */ u8 _002[0x136 - 0x2];
    /* 0x136 */ u8 _136;
} Bone0F60;

typedef struct ActorObj0F60 {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x18 - 0x8];
    /* 0x18 */ Bone0F60** _18;
    /* 0x1C */ u8 _1C[0x8C - 0x1C];
    /* 0x8C */ f32 _8C;
    /* 0x90 */ u8 _90[0x99 - 0x90];
    /* 0x99 */ u8 _99;
} ActorObj0F60;

typedef struct AnimSet0F60 {
    /* 0x00 */ u8 _00[0xA];
    /* 0x0A */ u16 _0A;
} AnimSet0F60;

typedef struct ActorRef0F60 {
    /* 0x00 */ ActorObj0F60* _00;
    /* 0x04 */ AnimSet0F60* _04;
    /* 0x08 */ void (*_08)(struct Player0F60* player);
    /* 0x0C */ u8 _0C[0xE - 0xC];
    /* 0x0E */ s16 _0E;
    /* 0x10 */ Control control;
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
} ActorRef0F60;

typedef struct AnimPart0F60 {
    /* 0x00 */ u32* _00;
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ f32 _14;
    /* 0x18 */ u8 _18[0x64 - 0x18];
} AnimPart0F60; // size: 0x64

typedef struct AnimState0F60 {
    /* 0x00 */ AnimPart0F60 _00;
    /* 0x64 */ AnimPart0F60 _64;
    /* 0xC8 */ u8 _C8[0xCC - 0xC8];
    /* 0xCC */ u8 _CC;
    /* 0xCD */ u8 _CD[0xD4 - 0xCD];
} AnimState0F60; // size: 0xD4

typedef struct Player0F60 {
    /* 0x000 */ ActorObj0F60* _000;
    /* 0x004 */ u8 _004[0x8 - 0x4];
    /* 0x008 */ u32* _008;
    /* 0x00C */ u8 _00C[0x10 - 0xC];
    /* 0x010 */ AnimSet0F60* _010;
    /* 0x014 */ u8 _014[0x2C - 0x14];
    /* 0x02C */ AnimState0F60* _02C;
    /* 0x030 */ AnimState0F60* _030;
    /* 0x034 */ u8 _034[0x40 - 0x34];
    /* 0x040 */ f32 _040;
    /* 0x044 */ f32 _044;
    /* 0x048 */ f32 _048;
    /* 0x04C */ f32 _04C;
    /* 0x050 */ u8 _050[0x5C - 0x50];
    /* 0x05C */ s32 _05C;
    /* 0x060 */ s16 _060;
    /* 0x062 */ s16 _062;
    /* 0x064 */ s16 _064;
    /* 0x066 */ s16 _066;
    /* 0x068 */ s16 _068;
    /* 0x06A */ s16 _06A;
    /* 0x06C */ s16 _06C;
    /* 0x06E */ s16 _06E;
    /* 0x070 */ u8 _070[0x162 - 0x70];
    union {
        /* 0x162 */ u16 _162[120];
        struct {
            /* 0x162 */ u16 _162_[4];
            /* 0x16A */ u16 _16A;
        };
    };
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ u8 _254;
    /* 0x255 */ s8 _255;
    /* 0x256 */ u8 _256;
    /* 0x257 */ s8 _257;
    /* 0x258 */ u8 _258[0x25D - 0x258];
    /* 0x25D */ u8 _25D;
    /* 0x25E */ u8 _25E;
    /* 0x25F */ u8 _25F;
    /* 0x260 */ u8 _260;
    /* 0x261 */ u8 _261;
    /* 0x262 */ u8 _262;
    /* 0x263 */ u8 _263;
    /* 0x264 */ u8 _264;
    /* 0x265 */ u8 _265;
    /* 0x266 */ u8 _266;
    /* 0x267 */ u8 _267;
    /* 0x268 */ u8 _268;
    /* 0x269 */ u8 _269;
    /* 0x26A */ u8 _26A;
    /* 0x26B */ u8 _26B;
    /* 0x26C */ u8 _26C;
    /* 0x26D */ u8 _26D;
    /* 0x26E */ u8 _26E;
    /* 0x26F */ u8 _26F;
    /* 0x270 */ u8 _270;
    /* 0x271 */ u8 _271;
    /* 0x272 */ u8 _272;
    /* 0x273 */ u8 _273;
    /* 0x274 */ u8 _274[0x277 - 0x274];
    /* 0x277 */ u8 _277;
    /* 0x278 */ u8 _278[0x27C - 0x278];
} Player0F60; // size: 0x27C

typedef struct Entry0F60 {
    /* 0x00 */ s32 _00;
    /* 0x04 */ Vec _04;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
    /* 0x1C */ u8 _1C[0x26 - 0x1C];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} Entry0F60; // size: 0x28

typedef struct ActorFiles0F60 {
    /* 0x0 */ void* layout;
    /* 0x4 */ void* geo;
    /* 0x8 */ void* tex;
} ActorFiles0F60; // size: 0xC

typedef struct AramEntry0F60 {
    /* 0x0 */ u32 _0;
    /* 0x4 */ u32 _4;
    /* 0x8 */ u32 _8;
    /* 0xC */ u32 _C;
} AramEntry0F60; // size: 0x10

typedef struct Anims0F60 {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ ANIMBank* _10[7];
    /* 0x2C */ ANIMBank* _2C[2];
    /* 0x34 */ ANIMBank* _34[7];
    /* 0x50 */ u8 _50[0x74 - 0x50];
} Anims0F60; // size: 0x74

typedef struct AramReq0F60 {
    /* 0x00 */ AramEntry0F60 entry;
    /* 0x10 */ s32 _10[4];
    /* 0x20 */ void (*_20)(void);
} AramReq0F60; // size: 0x24

typedef struct Game0F60 {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ ModelTable0F60* _0060;
    /* 0x0064 */ u8 _0064[0x68 - 0x64];
    /* 0x0068 */ ModelTable0F60* _0068;
    /* 0x006C */ u8 _006C[0xAC - 0x6C];
    /* 0x00AC */ s32 _00AC;
    /* 0x00B0 */ s32 _00B0;
    /* 0x00B4 */ s32 _00B4;
    /* 0x00B8 */ s32 _00B8;
    /* 0x00BC */ u8 _00BC[0x13C - 0xBC];
    /* 0x013C */ void* _013C;
    /* 0x0140 */ AnimState0F60 _0140[9];
    /* 0x08B4 */ u8 _08B4[0xC04 - 0x8B4];
    /* 0x0C04 */ Player0F60 _0C04[9];
    /* 0x2260 */ u8 _2260[0x2C50 - 0x2260];
    /* 0x2C50 */ Player0F60* _2C50[9];
    /* 0x2C74 */ u8 _2C74[0x2C88 - 0x2C74];
    /* 0x2C88 */ u8* _2C88;
    /* 0x2C8C */ u8* _2C8C;
    /* 0x2C90 */ u32 _2C90;
    /* 0x2C94 */ u8 _2C94[0x2D6A - 0x2C94];
    /* 0x2D6A */ s8 _2D6A[9];
    /* 0x2D73 */ u8 _2D73[0x2D77 - 0x2D73];
    /* 0x2D77 */ u8 _2D77;
    /* 0x2D78 */ u8 _2D78[0x2D7B - 0x2D78];
    /* 0x2D7B */ u8 _2D7B;
    /* 0x2D7C */ u8 _2D7C[0x2D7F - 0x2D7C];
    /* 0x2D7F */ s8 _2D7F[9];
    /* 0x2D88 */ u8 _2D88;
    /* 0x2D89 */ s8 _2D89[4];
    /* 0x2D8D */ u8 _2D8D[0x2D94 - 0x2D8D];
    /* 0x2D94 */ Entry0F60* _2D94;
    /* 0x2D98 */ u8 _2D98[0x2D9C - 0x2D98];
    /* 0x2D9C */ s32* _2D9C;
    union {
        /* 0x2DA0 */ ActorFiles0F60 _2DA0[19];
        /* 0x2DA0 */ void* _2DA0w[57];
    };
    /* 0x2E84 */ u8 _2E84[0x3078 - 0x2E84];
    /* 0x3078 */ u16 _3078;
    /* 0x307A */ u8 _307A;
} Game0F60;

typedef struct Save0F60 {
    /* 0x000000 */ u8 _000000[0x197706];
    /* 0x197706 */ s16 _197706;
    /* 0x197708 */ u8 _197708[0x197746 - 0x197708];
    /* 0x197746 */ s16 _197746;
    /* 0x197748 */ u8 _197748[0x1978F3 - 0x197748];
    /* 0x1978F3 */ u8 _1978F3;
} Save0F60;

typedef struct Tracker0F60 {
    /* 0x0000 */ u8 _0000[0x441C];
    /* 0x441C */ u8 _441C;
} Tracker0F60;

typedef struct MenuTask0F60 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct MenuTask0F60* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ s16 _14;
    /* 0x16 */ s16 _16;
    /* 0x18 */ u8 _18[0x28 - 0x18];
    /* 0x28 */ s8 _28;
} MenuTask0F60;

typedef struct Obj0F60 {
    /* 0x00 */ u8 _00[0x70];
    /* 0x70 */ void* _70;
} Obj0F60;

extern Game0F60* lbl_2_bss_340140;
extern Game0F60 lbl_8036E548;
extern Anims0F60* lbl_2_bss_3401BC;
extern Anims0F60 lbl_2_bss_3401C0;
extern Tracker0F60* lbl_2_bss_1A8248;
extern void* lbl_803CC1B8;
extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;
extern u8 lbl_2_data_3CD0[];
extern u8 lbl_800E869C[];
extern u8 lbl_800F5D98[];
extern u8 lbl_800F71D8[];
extern u8 lbl_803CBC3C;
extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;
extern Save0F60* lbl_2_bss_1A824C;
extern Mtx lbl_2_bss_1A81D4;

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern ModelTable0F60* ActorObjectInitTable(u16 count);
extern void fn_800BDC88(ModelTable0F60* table, u16 first, u16 last, void* model, void* anim, s32 arg5);
extern void fn_800BD548(Model0F60* model, s32 count, ...);
extern void LoadActorLayout(void* layout);
extern void convertGeometryAndSknHeader(void* geo, void* skn);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void convertTextureHeader(void* tex);
extern void fn_800BD190(void* geo, void* tex);
extern void fn_800B9AA8(void* arg0);
extern void fn_2_190DC(ModelTable0F60* table, MtxPtr view);
extern void* ARAMTransfer(AramEntry0F60* entry, s32 arg1, s32 arg2, u32 aram);
extern void fn_80052D70(void);
extern void fn_80023B04(void);
extern void fn_80014204(s16 count);
extern void* fn_80023AA4(void);
extern ActorRef0F60* fn_800111D8(Player0F60* player);
extern f32 fn_800B4A44(ActorObj0F60* actor, u16 anim);
extern void fn_800B2B54(ActorObj0F60* actor, u16 anim, s32 arg2);
extern void fn_800B2B4C(ActorObj0F60* actor, f32 arg1);
extern void fn_80025EEC(void* state, s32 arg1, s32 arg2);
extern void fn_8001B5EC(s32 idx, u8 arg1);
extern void fn_8001B308(s32 idx, u8 arg1);
extern void fn_8002399C(ActorRef0F60* ref, s32 arg1, s32 idx, void* layout, ANIMBank* anims, void* skn);
extern void fn_800B2B74(ActorObj0F60* actor, u16 id);
extern void fn_800B2BA8(ActorObj0F60* actor, u16 id, void* src, u16 index);
extern void fn_800126EC(AnimPart0F60* part, void* tex, u8* ids);
extern void fn_8001D180(s32 idx, s32 arg1, s32 arg2);
extern void fn_80025DDC(void* anim);
extern void fn_80014990(s32 idx, void* anim, void* arg2);
extern void fn_80025C58(void* anim, ActorRef0F60* ref);
extern void fn_800B2C08(ActorObj0F60* actor, u16 id);
extern void fn_8001FC4C(Player0F60* player);
extern void fn_800638B4(Player0F60* player, ActorRef0F60* ref);
extern void fn_80063010(Player0F60* player, ActorRef0F60* ref);
extern void fn_8004B7B4(Player0F60* player, ActorRef0F60* ref);
extern void fn_800637BC(Player0F60* player, ActorRef0F60* ref);
extern void fn_8004BD6C(Player0F60* player, ActorRef0F60* ref);
extern void fn_800637D4(Player0F60* player, ActorRef0F60* ref);
extern void fn_80052634(Player0F60* player, ActorRef0F60* ref);
extern void fn_80062ED4(Player0F60* player, ActorRef0F60* ref);
extern void fn_800B0A14_removeQueue(void);
extern void fn_2_93C64(void);

AramEntry0F60 lbl_2_data_2F990[13] = {
    { 0x0000040B, 0x4005A338, 0x19233000, 0x0003A448 },
    { 0x0000040B, 0x4004D644, 0x1926D800, 0x00030E60 },
    { 0x0000040B, 0x40061CB0, 0x1929E800, 0x0003E260 },
    { 0x0000040B, 0x4004A820, 0x1930B800, 0x000316E0 },
    { 0x0000040B, 0x40046B64, 0x192DD000, 0x0002E4EC },
    { 0x0000040B, 0x40047D78, 0x1933D000, 0x0002F2DC },
    { 0x0000040B, 0x40042A7C, 0x1936C800, 0x0002AD8C },
    { 0x0000040B, 0x40047B30, 0x19397800, 0x0002D5A8 },
    { 0x0000040B, 0x4003F9D0, 0x193C5000, 0x00025C68 },
    { 0x0000040B, 0x400413A4, 0x193EB000, 0x000292B0 },
    { 0x0000040B, 0x40044F28, 0x19432000, 0x0002D5EC },
    { 0x0000040B, 0x40030574, 0x19414800, 0x0001D740 },
    { 0x0000040B, 0x40036CD8, 0x1945F800, 0x00023828 },
};
AramEntry0F60 lbl_2_data_2FA60[54] = {
    { 0x0000040B, 0x4005A338, 0x19233000, 0x0003A448 },
    { 0x0000040B, 0x40062C34, 0x19483800, 0x000405F4 },
    { 0x0000040B, 0x4004A820, 0x1930B800, 0x000316E0 },
    { 0x0000040B, 0x4005C0CC, 0x194C4000, 0x0003C38C },
    { 0x0000040B, 0x4004D644, 0x1926D800, 0x00030E60 },
    { 0x0000040B, 0x4004E624, 0x19500800, 0x000333F4 },
    { 0x0000040B, 0x40046B64, 0x192DD000, 0x0002E4EC },
    { 0x0000040B, 0x40047BF8, 0x19534000, 0x0002D124 },
    { 0x0000040B, 0x400474C4, 0x19561800, 0x0002D2C4 },
    { 0x0000040B, 0x40047D78, 0x1933D000, 0x0002F2DC },
    { 0x0000040B, 0x40061CB0, 0x1929E800, 0x0003E260 },
    { 0x0000040B, 0x4005C08C, 0x1958F000, 0x0003F088 },
    { 0x0000040B, 0x40044F28, 0x19432000, 0x0002D5EC },
    { 0x0000040B, 0x4003F9D0, 0x193C5000, 0x00025C68 },
    { 0x0000040B, 0x4002F3E8, 0x195CE800, 0x0001E374 },
    { 0x0000040B, 0x40049F94, 0x195ED000, 0x0002D67C },
    { 0x0000040B, 0x40030574, 0x19414800, 0x0001D740 },
    { 0x0000040B, 0x4004EB58, 0x1961A800, 0x00031A64 },
    { 0x0000040B, 0x4002D3B8, 0x1964C800, 0x0001C224 },
    { 0x0000040B, 0x40042A7C, 0x1936C800, 0x0002AD8C },
    { 0x0000040B, 0x400425E0, 0x19669000, 0x0002BC8C },
    { 0x0000040B, 0x40047B30, 0x19397800, 0x0002D5A8 },
    { 0x0000040B, 0x400425E0, 0x19669000, 0x0002BC8C },
    { 0x0000040B, 0x40040EF0, 0x19695000, 0x00028E20 },
    { 0x0000040B, 0x40035DC0, 0x196BE000, 0x00021B80 },
    { 0x0000040B, 0x40027FF8, 0x196E0000, 0x00018538 },
    { 0x0000040B, 0x40027FF8, 0x196F8800, 0x00018538 },
    { 0x0000040B, 0x4003F0E8, 0x19711000, 0x00026FA4 },
    { 0x0000040B, 0x40036CD8, 0x1945F800, 0x00023828 },
    { 0x0000040B, 0x4003F9D0, 0x19738000, 0x00025C68 },
    { 0x0000040B, 0x4003F9D0, 0x1975E000, 0x00025C68 },
    { 0x0000040B, 0x4003F9D0, 0x19784000, 0x00025C68 },
    { 0x0000040B, 0x4003F9D0, 0x197AA000, 0x00025C68 },
    { 0x0000040B, 0x400413A4, 0x193EB000, 0x000292B0 },
    { 0x0000040B, 0x40034750, 0x197D0000, 0x000200C4 },
    { 0x0000040B, 0x40034750, 0x197F0800, 0x000200C4 },
    { 0x0000040B, 0x40034750, 0x19811000, 0x000200C4 },
    { 0x0000040B, 0x4002E558, 0x19831800, 0x0001C538 },
    { 0x0000040B, 0x4003CA98, 0x1984E000, 0x0002768C },
    { 0x0000040B, 0x4005577C, 0x19875800, 0x000386A0 },
    { 0x0000040B, 0x40023EF8, 0x198AE000, 0x00017274 },
    { 0x0000040B, 0x4003307C, 0x198C5800, 0x000203B8 },
    { 0x0000040B, 0x4003EF28, 0x198E6000, 0x000297C4 },
    { 0x0000040B, 0x4003CC00, 0x1990F800, 0x00027F38 },
    { 0x0000040B, 0x40030574, 0x19937800, 0x0001D740 },
    { 0x0000040B, 0x40030574, 0x19955000, 0x0001D740 },
    { 0x0000040B, 0x40030574, 0x19972800, 0x0001D740 },
    { 0x0000040B, 0x40030574, 0x19990000, 0x0001D740 },
    { 0x0000040B, 0x40038A88, 0x199AD800, 0x00023C60 },
    { 0x0000040B, 0x4002A408, 0x199D1800, 0x0001AB60 },
    { 0x0000040B, 0x40038A88, 0x199EC800, 0x00023C60 },
    { 0x0000040B, 0x4002A408, 0x19A10800, 0x0001AB60 },
    { 0x0000040B, 0x4003AD18, 0x19A2B800, 0x00021DBC },
    { 0x0000040B, 0x4003AD18, 0x19A4D800, 0x00021DBC },
};
s32 lbl_2_data_2FDC0[32] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x18, 0x1B, 0x1C, 0x21, 0x25, 0x26, 0x27, 0x28, 0x29, 0x30,
};
void* lbl_2_data_2FE40[2] = { lbl_800F5D98, lbl_800F71D8 };
AramEntry0F60 lbl_2_data_2FE48 = { 0x0000040B, 0x400D198C, 0x191D5800, 0x0005D268 };
AramReq0F60 lbl_2_data_2FE58 = {
    { 0x0000040B, 0x400204C0, 0x191C1800, 0x00013FCC },
    { 0, 0, 0, 2 },
    fn_2_8ACDC,
};
u8 lbl_2_data_2FE7C[8] = { 5, 6, 9, 11, 7, 8, 10, 12 };
s32 lbl_2_data_2FE84[10] = { 1, 1, 5, 5, 5, 5, 5, 5, 2, 5 };
s32 lbl_2_data_2FEAC[10] = { 2, 11, 4, 7, 10, 2, 8, 11, 38, 0 };
Vec lbl_2_data_2FED4 = { 0.0f, 0.0f, 0.0f };
Vec lbl_2_data_2FEE0 = { 0.0f, 0.0f, 0.0f };
f32 lbl_2_bss_B2B8;

// .text:0x0008EA80 size:0x2CC
// 98.83%: in the inlined fn_2_8D9DC the target loads lbl_2_bss_340140 into r3, so the clrlwi
// of fn_2_8D270's argument comes after the stwx; here it lands in r4 and the clrlwi moves up.
void fn_2_8EA80(void) {
    MenuTask0F60* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_340140 = &lbl_8036E548;
        lbl_2_bss_3401BC = &lbl_2_bss_3401C0;
        task->_14 = 0;
        fn_2_4E824();
        fn_80052D70();
        fn_2_8DCD8();
        fn_2_48DB4();
        fn_2_93C64();
        task->_28 = 1;
        break;
    case 1:
        lbl_2_bss_340140->_0C04[task->_14]._008 = (u32*)ARAMTransfer(&lbl_2_data_2F990[lbl_2_bss_1A8248->_441C], 0, 0, 0);
        task->_14++;
        task->_28 = 2;
        break;
    case 2:
        if (lbl_803C6CF8._715 == 1) {
            task->_28 = 3;
        }
        break;
    case 3:
        lbl_2_bss_340140->_0C04[task->_14]._008 = (u32*)ARAMTransfer(&lbl_2_data_2F990[task->_14 + 5], 0, 0, 0);
        task->_14++;
        task->_28 = 4;
        break;
    case 4:
        if (lbl_803C6CF8._715 == 1) {
            if (task->_14 == lbl_2_bss_1A824C->_197746) {
                task->_28 = 5;
            } else {
                task->_28 = 3;
            }
        }
        break;
    case 5:
        fn_2_8D9DC(0);
        task->_28 = 6;
        break;
    case 6:
        task->_28 = 7;
        break;
    case 7:
        fn_2_94854(0xB);
        fn_2_9461C(0);
        fn_2_94604(0);
        fn_2_94634(1);
        fn_2_93C64();
        lbl_2_bss_340140->_307A = 2;
        ((MenuTask0F60*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x0008E8A4 size:0x1DC
// 96.76%: in the inlined fn_2_8D9DC the target loads lbl_2_bss_340140 into r3, so the clrlwi
// of fn_2_8D270's argument comes after the stwx; here it lands in r4 and the clrlwi moves up;
// the loop's 0x1C is also not hoisted into r25.
void fn_2_8E8A4(void) {
    MenuTask0F60* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_340140 = &lbl_8036E548;
        task->_14 = 0;
        fn_2_4E824();
        fn_80052D70();
        fn_2_8DCD8();
        fn_2_48DB4();
        fn_2_93C64();
        task->_28 = 1;
        break;
    case 1:
        lbl_2_bss_340140->_0C04[task->_14]._008 = (u32*)ARAMTransfer(&lbl_2_data_2F990[task->_16], 0, 0, 0);
        task->_14++;
        task->_28 = 2;
        break;
    case 2:
        if (lbl_803C6CF8._715 == 1) {
            task->_28 = 5;
        }
        break;
    case 5:
        fn_2_8D9DC(1);
        task->_28 = 6;
        break;
    case 6:
        lbl_2_bss_340140->_307A = 2;
        ((MenuTask0F60*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x0008E6A4 size:0x200
// 98.36%: in the inlined fn_2_8D9DC the target loads lbl_2_bss_340140 into r3, so the clrlwi
// of fn_2_8D270's argument comes after the stwx; here it lands in r4 and the clrlwi moves up.
void fn_2_8E6A4(void) {
    MenuTask0F60* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_340140 = &lbl_8036E548;
        task->_14 = 0;
        fn_2_4E824();
        fn_80052D70();
        fn_2_8DCD8();
        fn_2_48DB4();
        fn_2_93C64();
        task->_28 = 1;
        break;
    case 1:
        lbl_2_bss_340140->_0C04[task->_14]._008 = (u32*)ARAMTransfer(&lbl_2_data_2FA60[lbl_2_data_2FDC0[task->_16]], 0, 0, 0);
        task->_14++;
        task->_28 = 2;
        break;
    case 2:
        if (lbl_803C6CF8._715 == 1) {
            task->_28 = 5;
        }
        break;
    case 5:
        fn_2_8D9DC(2);
        task->_28 = 6;
        break;
    case 6:
        lbl_2_bss_340140->_307A = 2;
        ((MenuTask0F60*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x0008E478 size:0x22C
void fn_2_8E478(void) {
    MenuTask0F60* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_340140 = &lbl_8036E548;
        task->_14 = 0;
        task->_28 = 1;
        break;
    case 1:
        lbl_2_bss_340140->_2D9C = ARAMTransfer(&lbl_2_data_2FE48, 0, 0, 0);
        task->_14++;
        task->_28 = 2;
        break;
    case 2:
        if (lbl_803C6CF8._715 == 1) {
            task->_28 = 5;
        }
        break;
    case 5:
        fn_2_8C910();
        task->_28 = 6;
        break;
    case 6:
        fn_2_8B418();
        fn_2_8C724();
        fn_80052D70();
        lbl_2_bss_1A824C->_1978F3 = 1;
        lbl_2_bss_340140->_307A = 4;
        ((MenuTask0F60*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x0008DFB0 size:0x4C8
void fn_2_8DFB0(void) {
    MenuTask0F60* task = lbl_803CC1B8;

    switch (task->_28) {
    case 0:
        lbl_2_bss_340140 = &lbl_8036E548;
        task->_14 = 0;
        fn_2_4E824();
        fn_80052D70();
        fn_2_48DB4();
        fn_2_93C64();
        task->_28 = 1;
        break;
    case 1:
        lbl_2_bss_1A824C->_197746 = 0;
        lbl_2_bss_340140->_2D9C = ARAMTransfer(&lbl_2_data_2FE58.entry, 0, 0, 0);
        task->_14++;
        task->_28 = 2;
        break;
    case 2:
        if (lbl_803C6CF8._715 == 1) {
            task->_28 = 5;
        }
        break;
    case 5:
        fn_2_8B2C0();
        task->_28 = 6;
        break;
    case 6:
        fn_2_8B158();
        fn_2_8C724();
        fn_80052D70();
        task->_28 = 7;
        break;
    case 7:
        task->_28 = 8;
        break;
    case 8:
        lbl_2_bss_340140->_307A = 3;
        task->_28 = 9;
        break;
    case 9:
        task->_28 = 10;
        break;
    case 10:
        lbl_2_bss_340140->_307A = 3;
        ((MenuTask0F60*)lbl_803CC1B8)->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}

// .text:0x0008DCD8 size:0x2D8
// 99.95%: the copy of fn_2_8DB14's last loop tests its bound in r3 instead of r0.
void fn_2_8DCD8(void) {
    u32 max;
    s32 i;
    s32 size;
    u32 size2;
    s32 j;

    max = 0;
    for (i = 0; i < 13; i++) {
        if (max < (lbl_2_data_2F990[i]._4 & 0x0FFFFFFF)) {
            max = lbl_2_data_2F990[i]._4 & 0x0FFFFFFF;
        }
    }
    size = (max + 0x1F) & ~0x1F;
    lbl_2_bss_340140->_2C8C = _OSAllocFromHeap(0x20, size * lbl_2_bss_1A824C->_197746);
    for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
        lbl_2_bss_340140->_0C04[i]._008 = (u32*)(lbl_2_bss_340140->_2C8C + i * size);
    }

    max = 0;
    for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
        if (max < (lbl_2_data_2F990[i]._4 & 0x0FFFFFFF)) {
            max = lbl_2_data_2F990[i]._4 & 0x0FFFFFFF;
        }
    }
    size2 = (max + 0x1F) & ~0x1F;
    lbl_2_bss_340140->_2C90 = size2;
    lbl_2_bss_340140->_2C88 = _OSAllocFromHeap(0x20, size2 * lbl_2_bss_1A824C->_197746);
    for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
        lbl_2_bss_340140->_0C04[i]._010 = NULL;
    }

    fn_80023B04();
    fn_80014204(lbl_2_bss_1A824C->_197746);
    lbl_2_bss_340140->_013C = fn_80023AA4();
    for (j = 0; j < lbl_2_bss_1A824C->_197746; j++) {
        lbl_2_bss_340140->_0C04[j]._255 = j;
        lbl_2_bss_340140->_2C50[j] = NULL;
        lbl_2_bss_340140->_2D6A[j] = -1;
        lbl_2_bss_340140->_0C04[j]._257 = -1;
    }
    for (i = 0; i < 9; i++) {
        lbl_2_bss_340140->_2D7F[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        lbl_2_bss_340140->_2D89[i] = -1;
    }
    lbl_2_bss_340140->_2D77 = 0;
    lbl_2_bss_340140->_2D7B = 0;
}

// .text:0x0008DC00 size:0xD8
void fn_2_8DC00(void) {
    u32 max = 0;
    s32 i;
    s32 size;

    for (i = 0; i < 13; i++) {
        if (max < (lbl_2_data_2F990[i]._4 & 0x0FFFFFFF)) {
            max = lbl_2_data_2F990[i]._4 & 0x0FFFFFFF;
        }
    }
    size = (max + 0x1F) & ~0x1F;
    lbl_2_bss_340140->_2C8C = _OSAllocFromHeap(0x20, size * lbl_2_bss_1A824C->_197746);
    for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
        lbl_2_bss_340140->_0C04[i]._008 = (u32*)(lbl_2_bss_340140->_2C8C + i * size);
    }
}

// .text:0x0008DB14 size:0xEC
void fn_2_8DB14(void) {
    u32 max = 0;
    s32 i;
    u32 size;

    for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
        if (max < (lbl_2_data_2F990[i]._4 & 0x0FFFFFFF)) {
            max = lbl_2_data_2F990[i]._4 & 0x0FFFFFFF;
        }
    }
    size = (max + 0x1F) & ~0x1F;
    lbl_2_bss_340140->_2C90 = size;
    lbl_2_bss_340140->_2C88 = _OSAllocFromHeap(0x20, size * lbl_2_bss_1A824C->_197746);
    for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
        lbl_2_bss_340140->_0C04[i]._010 = NULL;
    }
}

// .text:0x0008D9DC size:0x138
void fn_2_8D9DC(s32 mode) {
    s32 i;

    for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
        lbl_2_bss_340140->_2C50[i] = &lbl_8036E548._0C04[i];
        lbl_2_bss_340140->_2C50[i]->_255 = i;
        lbl_2_bss_340140->_2C50[i]->_254 = i;
        switch (mode) {
        case 0:
            lbl_2_bss_340140->_2C50[i]->_252 = lbl_2_data_3CD0[i];
            break;
        case 1:
            lbl_2_bss_340140->_2C50[i]->_252 = 0x1C;
            break;
        case 2:
            lbl_2_bss_340140->_2C50[i]->_252 = lbl_800E869C[lbl_2_bss_1A824C->_197706];
            break;
        }
        fn_2_8D270(i);
    }
}

static inline BOOL fn_2_8D270_isSpecial(s8 kind) {
    BOOL special = FALSE;

    if (kind == 0x12 || kind == 0x26 || kind == 0x28 || kind == 0x29) {
        special = TRUE;
    }
    return special;
}

// .text:0x0008D270 size:0x76C
// 95.58%: the target keeps the raw idx in r25 and p in r30, re-zero-extends idx for each call,
// tests the special kinds through neg/or/srwi. (as `return special != 0;` tested with `& 1`,
// 96.13%, like rep_0568's hasAltAnims), and copies the bone loop's zero with mr.
void fn_2_8D270(u8 idx) {
    Player0F60* p = &lbl_2_bss_340140->_0C04[idx];
    ActorRef0F60* ref = fn_800111D8(p);
    void* tex;
    void* layout;
    void* geo;
    void* skn;
    Model0F60* model;
    AnimState0F60* anim;
    u16 count;
    int j;
    int i;
    s32 id;
    s32 a;
    s32 b;
    u16 bone;
    void* sub;
    u32* base = p->_008;
    void* sub2;

    for (i = 0; i < 15; i++) {
        if (p->_008[i] == 0) {
            break;
        }
        p->_008[i] = (u32)base + base[i];
    }
    tex = (void*)p->_008[0];
    convertTextureHeader(tex);
    layout = (void*)p->_008[1];
    if (layout != NULL) {
        geo = (void*)p->_008[2];
        skn = (void*)p->_008[3];
        LoadActorLayout(layout);
        convertGeometryAndSknHeader(geo, skn);
        haveActLayoutPointToGeoHeader(layout, geo);
        fn_800BD190(geo, tex);
    } else {
        return;
    }
    p->_010 = (AnimSet0F60*)p->_008[4];
    ANIMGet((ANIMBank*)p->_010);
    fn_8002399C(ref, p->_255, idx, layout, (ANIMBank*)p->_010, skn);
    model = &lbl_2_bss_340140->_0060->models[idx];
    if (p == NULL && lbl_2_bss_340140->_0060 == NULL && model == NULL) {
        return;
    }
    count = model->_00->_06;
    memset(p->_162, 0xFF, sizeof(p->_162));
    for (j = 0; j < count; j++) {
        bone = model->_00->_18[j]->_000;
        if (bone != 0xFFFF) {
            p->_162[bone] = j;
        }
    }
    fn_800B2B74(ref->_00, p->_162[19]);
    fn_800B2B74(ref->_00, p->_162[25]);
    fn_800B2B74(ref->_00, p->_162[36]);
    p->_000 = ref->_00;
    id = p->_162[3];
    if (id != 0xFFFF) {
        fn_800B2B54(p->_000, id, 0xD);
    }
    fn_800BD548((Model0F60*)ref, 4, lbl_2_bss_340140->_00AC, lbl_2_bss_340140->_00B0, lbl_2_bss_340140->_00B4,
                lbl_2_bss_340140->_00B8);
    p->_040 = p->_044 = p->_048 = 0.0f;
    CTRLSetTranslation(&ref->control, 0.0f, 0.0f, 0.0f);
    CTRLSetRotation(&ref->control, 0.0f, 0.0f, 0.0f);
    ref->_54 = 0.5f;
    ref->_5A = 1;
    id = p->_162[3];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
        ref->_00->_18[(u16)id]->_136 = 1;
    }
    id = p->_162[2];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
        ref->_00->_18[(u16)id]->_136 = 1;
    }
    id = p->_162[1];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
        ref->_00->_18[(u16)id]->_136 = 1;
    }
    id = p->_162[36];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
    }
    id = p->_162[46];
    if (id != 0xFFFF) {
        fn_800B2BA8(ref->_00, id, NULL, 0);
        ref->_00->_18[(u16)id]->_136 = 1;
    }
    anim = &lbl_2_bss_340140->_0140[p->_255];
    if (p->_008[5] != 0) {
        p->_030 = &lbl_2_bss_340140->_0140[idx];
        anim->_00._00 = p->_008;
        fn_800126EC(&anim->_00, tex, &lbl_2_data_2FE7C[0]);
        anim->_64._00 = p->_008;
        fn_800126EC(&anim->_64, tex, &lbl_2_data_2FE7C[4]);
    }
    if (fn_2_8D270_isSpecial(p->_252)) {
        switch (p->_252) {
        case 0x12:
            a = 4;
            b = 5;
            break;
        case 0x26:
            a = 2;
            b = 3;
            break;
        case 0x28:
        case 0x29:
            a = 6;
            b = 7;
            break;
        }
    } else {
        a = 1;
        b = 0;
    }
    fn_8001D180(idx, a, 1);
    fn_8001D180(idx, b, 1);
    p->_02C = NULL;
    sub = (void*)p->_008[13];
    if (sub != NULL) {
        sub2 = (void*)p->_008[14];
        if (sub2 != NULL) {
            fn_80025DDC(sub);
            fn_80014990(idx, sub, sub2);
            fn_80025C58(sub, ref);
        }
    }
    p->_030->_CC = 1;
    p->_030->_64._14 = 0.5f;
    p->_030->_00._14 = 0.5f;
    fn_800B2C08(ref->_00, p->_16A);
    fn_8001FC4C(p);
    ref->_08 = (void (*)(Player0F60*))fn_2_8D24C;
    p->_060 = -1;
    p->_062 = -1;
    p->_064 = -1;
    p->_066 = -1;
    p->_068 = -1;
    p->_06A = -1;
    p->_06C = -1;
    p->_06E = -1;
    p->_25D = 0;
    p->_25E = 0;
    p->_25F = 0;
    p->_260 = 0;
    p->_261 = 0;
    p->_262 = 1;
    p->_263 = 1;
    p->_264 = 1;
    p->_265 = 0;
    p->_266 = 0;
    p->_267 = 0;
    p->_268 = 0;
    p->_269 = 0;
    p->_26A = 0;
    p->_26B = 0;
    p->_26C = 0;
    p->_26D = 0;
    p->_26E = 0;
    p->_270 = 0;
    p->_271 = 0;
    p->_272 = 0;
    p->_273 = 0;
    p->_277 = 0xFF;
    p->_05C = 0;
    p->_04C = 0.5f;
    switch (p->_252) {
    case 2:
        fn_800638B4(p, ref);
        break;
    case 6:
    case 10:
        ref->_00->_99 = 1;
        break;
    case 33:
    case 34:
    case 35:
    case 36:
        fn_80063010(p, ref);
        break;
    case 19:
        fn_8004B7B4(p, ref);
        break;
    case 12:
    case 42:
        ref->_00->_99 = 1;
        break;
    case 24:
    case 25:
    case 26:
        ref->_00->_99 = 1;
        break;
    case 20:
    case 43:
        fn_800637BC(p, ref);
        break;
    case 38:
        ref->_00->_99 = 1;
        fn_8004BD6C(p, ref);
        break;
    case 41:
        fn_800637D4(p, ref);
    case 18:
    case 40:
        fn_8004BD6C(p, ref);
        break;
    case 14:
    case 37:
        fn_80052634(p, ref);
        break;
    case 16:
    case 44:
    case 45:
    case 46:
    case 47:
        fn_80062ED4(p, ref);
        break;
    }
    fn_2_8CD58(idx, 0, 1, 1, 0, 0, 0);
}

// .text:0x0008D24C size:0x24
void fn_2_8D24C(Obj0F60* obj) {
    fn_800B9AA8(obj->_70);
}

// .text:0x0008D024 size:0x228
void fn_2_8D024(void) {
    Player0F60* p;
    s32 i;
    f32 frames;
    s32 anim;

    for (i = 0; i < lbl_2_bss_1A824C->_197746; i++) {
        p = lbl_2_bss_340140->_2C50[i];
        if (p == NULL || p->_25D == 0) {
            continue;
        }
        if (p->_06A < 600 && lbl_80366158._28 == 0 && lbl_803CBC3C == 0 && p->_26F == 0) {
            p->_06A++;
        }
        frames = 1.0f;
        anim = lbl_8036E548._2C50[i] != NULL ? lbl_8036E548._2C50[i]->_16A : 0xFFFF;
        if (anim != 0xFFFF) {
            frames = fn_800B4A44(fn_800111D8(p)->_00, anim);
        }
        p->_068 = frames / p->_04C;
        if (p->_25E == 1 || (p->_25E == 2 && p->_068 == 0 && p->_06A > 1) || p->_062 == -1) {
            if (p->_064 >= 0) {
                fn_2_8CD58(i, p->_064, p->_260, p->_263, p->_06C, p->_266, p->_26A);
                p->_060 = p->_062;
                p->_062 = p->_064;
                p->_064 = -1;
                p->_25F = p->_260;
                p->_262 = p->_263;
                p->_265 = p->_266;
                p->_269 = p->_26A;
                p->_26C = p->_26D;
                p->_06A = 0;
                if (p->_066 >= 0) {
                    p->_064 = p->_066;
                    p->_06C = p->_06E;
                    p->_260 = p->_261;
                    p->_263 = p->_264;
                    p->_25E = 2;
                    p->_266 = p->_267;
                    p->_26A = p->_26B;
                    p->_26D = p->_26E;
                    p->_066 = -1;
                    continue;
                }
            }
            p->_25E = 0;
        }
    }
}

// .text:0x0008CD58 size:0x2CC
void fn_2_8CD58(s32 idx, s32 anim, u8 arg2, s32 arg3, s16 arg4, s32 arg5, u8 arg6) {
    f32 rate = 0.0f;
    Player0F60* p = lbl_2_bss_340140->_2C50[idx];
    s32 a;
    s32 b;
    ActorRef0F60* ref;
    AnimSet0F60* set;

    if (idx == 4) {
        a = 1;
        b = 0;
    } else {
        a = lbl_2_data_2FE84[anim];
        b = lbl_2_data_2FEAC[anim];
    }
    if (p == NULL) {
        return;
    }
    ref = fn_800111D8(p);
    if (arg6) {
        rate = 1.0f / arg6;
    }
    if (p->_26C == 0) {
        fn_800B2B54(p->_000, lbl_8036E548._2C50[idx] != NULL ? lbl_8036E548._2C50[idx]->_16A : 0xFFFF, 0xD);
    } else {
        fn_800B2B54(p->_000, lbl_8036E548._2C50[idx] != NULL ? lbl_8036E548._2C50[idx]->_16A : 0xFFFF, 1);
        fn_800B2B54(ref->_00, lbl_8036E548._2C50[idx] != NULL ? lbl_8036E548._2C50[idx]->_16A : 0xFFFF, 1);
        fn_800B2B4C(ref->_00, 0.125f);
        ref->_00->_8C = 0.0f;
    }
    if (p->_02C != NULL) {
        fn_80025EEC(p->_02C->_00._04, a, b);
    }
    if (p->_030 != NULL && p->_030->_CC != 0) {
        fn_80025EEC(p->_030->_64._04, a, b);
        fn_80025EEC(p->_030->_00._04, a, b);
    }
    set = p->_010;
    if (set != NULL) {
        if (anim >= set->_0A) {
            return;
        }
        if (anim < 0) {
            return;
        }
        ref->_04 = set;
        ref->_0E = anim;
        ref->_5C = 0.0f;
        ref->_58 = 1;
        ref->_5A = ref->_59 = set != NULL;
        ref->_60 = rate;
    }
    if (arg2) {
        ref->_5B = 3;
    } else {
        ref->_5B = 2;
    }
    ref->_5C = arg4 * p->_04C;
    ref->_59 = 1;
    fn_8001B5EC(idx, arg3);
    fn_8001B308(idx, arg5);
    p->_268 = arg3;
}

// .text:0x0008CCCC size:0x8C
void fn_2_8CCCC(s32 idx, s32 arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Player0F60* p = lbl_2_bss_340140->_2C50[idx];

    if (p == NULL) {
        return;
    }
    if (arg3 == 1 && p->_062 == arg1) {
        return;
    }
    if (arg3 == 3) {
        arg3 = 1;
    }
    p->_064 = arg1;
    p->_06C = arg5;
    p->_260 = arg2;
    p->_25E = arg3;
    p->_263 = arg4;
    p->_266 = arg6;
    p->_26D = 0;
    if (arg7 == -1) {
        p->_26A = 5;
    } else {
        p->_26A = arg7;
    }
    p->_066 = -1;
}

// .text:0x0008CCAC size:0x20
void fn_2_8CCAC(s32 idx, s32 arg1) {
    Player0F60* p = &lbl_2_bss_340140->_0C04[idx];

    if (p != NULL) {
        p->_25D = arg1;
    }
}

// .text:0x0008CC88 size:0x24
s32 fn_2_8CC88(s32 idx) {
    return lbl_8036E548._2C50[idx]->_068 == 0;
}

// .text:0x0008C910 size:0x378
// 88.85%: the target swaps hdr and i (r31/r30), steps i before the other loop counters, and
// indexes the last seven banks as (i + k) * 4 where MWCC folds k into the displacement here.
void fn_2_8C910(void) {
    int i;
    s32 k;
    s32* hdr;
    void* layout;
    void* geo;
    void* tex;

    lbl_2_bss_340140->_3078 = 0;
    hdr = lbl_2_bss_340140->_2D9C;
    for (i = 0; i < 57; i++) {
        lbl_2_bss_340140->_2DA0w[i] = (u8*)hdr + hdr[i];
    }
    for (k = 0; k < 7; k++, i++) {
        lbl_2_bss_3401BC->_10[k] = (ANIMBank*)((u8*)hdr + hdr[i]);
        ANIMGet(lbl_2_bss_3401BC->_10[k]);
    }
    for (k = 0; k < 2; k++, i++) {
        lbl_2_bss_3401BC->_2C[k] = (ANIMBank*)((u8*)hdr + hdr[i]);
        ANIMGet(lbl_2_bss_3401BC->_2C[k]);
    }
    lbl_2_bss_3401BC->_34[0] = (ANIMBank*)((u8*)hdr + hdr[i]);
    ANIMGet(lbl_2_bss_3401BC->_34[0]);
    lbl_2_bss_3401BC->_34[1] = (ANIMBank*)((u8*)hdr + hdr[i + 1]);
    ANIMGet(lbl_2_bss_3401BC->_34[1]);
    lbl_2_bss_3401BC->_34[2] = (ANIMBank*)((u8*)hdr + hdr[i + 2]);
    ANIMGet(lbl_2_bss_3401BC->_34[2]);
    lbl_2_bss_3401BC->_34[3] = (ANIMBank*)((u8*)hdr + hdr[i + 3]);
    ANIMGet(lbl_2_bss_3401BC->_34[3]);
    lbl_2_bss_3401BC->_34[4] = (ANIMBank*)((u8*)hdr + hdr[i + 4]);
    ANIMGet(lbl_2_bss_3401BC->_34[4]);
    lbl_2_bss_3401BC->_34[5] = (ANIMBank*)((u8*)hdr + hdr[i + 5]);
    ANIMGet(lbl_2_bss_3401BC->_34[5]);
    lbl_2_bss_3401BC->_34[6] = (ANIMBank*)((u8*)hdr + hdr[i + 6]);
    ANIMGet(lbl_2_bss_3401BC->_34[6]);
    for (i = 0; i < 19; i++) {
        layout = lbl_2_bss_340140->_2DA0[i].layout;
        geo = lbl_2_bss_340140->_2DA0[i].geo;
        tex = lbl_2_bss_340140->_2DA0[i].tex;
        LoadActorLayout(layout);
        convertGeometryAndSknHeader(geo, NULL);
        haveActLayoutPointToGeoHeader(layout, geo);
        convertTextureHeader(tex);
        fn_800BD190(geo, tex);
    }
}

// .text:0x0008C80C size:0x104
void fn_2_8C80C(s32 file, s32 first, s32 count, void* anim, s32 arg4) {
    s32 i;

    for (i = first; i < first + count; i++) {
        fn_800BDC88(lbl_2_bss_340140->_0068, i, i, lbl_2_bss_340140->_2DA0[file].layout, anim, arg4);
        lbl_2_bss_340140->_0068->models[i]._00->_99 = 1;
        fn_800BD548(&lbl_2_bss_340140->_0068->models[i], 4, lbl_2_bss_340140->_00AC,
                    lbl_2_bss_340140->_00B0, lbl_2_bss_340140->_00B4, lbl_2_bss_340140->_00B8);
        CTRLSetTranslation(&lbl_2_bss_340140->_0068->models[i].control, 0.0f, 0.0f, 0.0f);
        CTRLSetRotation(&lbl_2_bss_340140->_0068->models[i].control, 0.0f, 0.0f, 0.0f);
    }
}

// .text:0x0008C724 size:0xE8
void fn_2_8C724(void) {
    s32 i;

    for (i = 0; i < lbl_2_bss_340140->_3078; i++) {
        lbl_2_bss_340140->_2D94[i]._04.x = 0.0f;
        lbl_2_bss_340140->_2D94[i]._04.y = 0.0f;
        lbl_2_bss_340140->_2D94[i]._04.z = 0.0f;
        lbl_2_bss_340140->_2D94[i]._10 = 0.0f;
        lbl_2_bss_340140->_2D94[i]._14 = 0.0f;
        lbl_2_bss_340140->_2D94[i]._18 = 0.0f;
        lbl_2_bss_340140->_2D94[i]._26 = 0;
        lbl_2_bss_340140->_2D94[i]._00 = 0;
        lbl_2_bss_340140->_0068->models[i]._6C = 0;
    }
}

// .text:0x0008B418 size:0x130C
void fn_2_8B418(void) {
    lbl_2_bss_340140->_3078 = 29;
    lbl_2_bss_340140->_2D94 = _OSAllocFromHeap(0x20, lbl_2_bss_340140->_3078 * sizeof(Entry0F60));
    lbl_2_bss_340140->_0068 = ActorObjectInitTable(lbl_2_bss_340140->_3078);
    fn_2_8C80C(0, 0, 1, NULL, 0);
    fn_2_8C80C(1, 1, 1, NULL, 0);
    fn_2_8C80C(2, 2, 1, NULL, 0);
    fn_2_8C80C(3, 3, 1, NULL, 0);
    fn_2_8C80C(4, 4, 1, NULL, 0);
    fn_2_8C80C(5, 5, 1, NULL, 0);
    fn_2_8C80C(6, 6, 1, NULL, 0);
    fn_2_8C80C(7, 7, 1, NULL, 0);
    fn_2_8C80C(8, 8, 1, NULL, 0);
    fn_2_8C80C(9, 9, 1, NULL, 0);
    fn_2_8C80C(10, 10, 1, NULL, 0);
    fn_2_8C80C(10, 11, 1, NULL, 0);
    fn_2_8C80C(10, 12, 1, NULL, 0);
    fn_2_8C80C(10, 13, 1, NULL, 0);
    fn_2_8C80C(10, 14, 1, NULL, 0);
    fn_2_8C80C(10, 15, 1, NULL, 0);
    fn_2_8C80C(11, 16, 1, NULL, 0);
    fn_2_8C80C(11, 17, 1, NULL, 0);
    fn_2_8C80C(11, 18, 1, NULL, 0);
    fn_2_8C80C(11, 19, 1, NULL, 0);
    fn_2_8C80C(11, 20, 1, NULL, 0);
    fn_2_8C80C(11, 21, 1, NULL, 0);
    fn_2_8C80C(12, 22, 1, NULL, 0);
    fn_2_8C80C(13, 23, 1, NULL, 0);
    fn_2_8C80C(14, 24, 1, NULL, 0);
    fn_2_8C80C(15, 25, 1, NULL, 0);
    fn_2_8C80C(16, 26, 1, NULL, 0);
    fn_2_8C80C(17, 27, 1, NULL, 0);
    fn_2_8C80C(18, 28, 1, NULL, 0);
}

// .text:0x0008B2C0 size:0x158
void fn_2_8B2C0(void) {
    int i;
    s32* hdr;
    void* layout;
    void* geo;
    void* tex;

    lbl_2_bss_340140->_3078 = 0;
    hdr = lbl_2_bss_340140->_2D9C;
    for (i = 0; i < 12; i++) {
        lbl_2_bss_340140->_2DA0w[i] = (u8*)hdr + hdr[i];
    }
    for (i = 0; i < 4; i++) {
        layout = lbl_2_bss_340140->_2DA0[i].layout;
        geo = lbl_2_bss_340140->_2DA0[i].geo;
        tex = lbl_2_bss_340140->_2DA0[i].tex;
        LoadActorLayout(layout);
        convertGeometryAndSknHeader(geo, NULL);
        haveActLayoutPointToGeoHeader(layout, geo);
        convertTextureHeader(tex);
        fn_800BD190(geo, tex);
    }
}

// .text:0x0008B158 size:0x168
void fn_2_8B158(void) {
    s32 i;

    lbl_2_bss_340140->_3078 = 4;
    lbl_2_bss_340140->_2D94 = _OSAllocFromHeap(0x20, lbl_2_bss_340140->_3078 * sizeof(Entry0F60));
    lbl_2_bss_340140->_0068 = ActorObjectInitTable(lbl_2_bss_340140->_3078);
    for (i = 0; i < lbl_2_bss_340140->_3078; i++) {
        fn_2_8C80C(i, i, 1, NULL, 0);
    }
}

// .text:0x0008B118 size:0x40
void fn_2_8B118(f32 x) {
    if (x) {
        lbl_2_bss_340140->_307A = 3;
    } else {
        lbl_2_bss_340140->_307A = 0;
    }
}

// .text:0x0008AEE0 size:0x238
void fn_2_8AEE0(void) {
    camera_803c639c_s* cam;

    fn_2_8ACE0();
    PSMTXCopy(lbl_2_bss_1A81D4, fn_80052768_getCamera(0)->view);
    cam = fn_80052768_getCamera(0);
    fn_2_190DC(lbl_2_bss_340140->_0068, cam->view);
}

// .text:0x0008ACE0 size:0x200
void fn_2_8ACE0(void) {
    Vec pos;
    Vec delta;
    Entry0F60* e;
    s32 i;

    for (i = 0; i < lbl_2_bss_340140->_3078; i++) {
        e = &lbl_2_bss_340140->_2D94[i];
        memcpy(&pos, &e->_04, sizeof(Vec));
        PSVECSubtract(&pos, &lbl_2_data_2FEE0, &delta);
        delta.x *= -1.0f;
        delta.z *= -1.0f;
        if (delta.x != 0.0f || delta.z != 0.0f) {
            lbl_2_bss_B2B8 = fn_2_4A1E8(delta.z, delta.x);
        }
        memcpy(&lbl_2_data_2FEE0, &e->_04, sizeof(Vec));
        if (pos.x != 0.0f) {
            e->_04.x = pos.x / 2.0f;
        }
        if (pos.y != 0.0f) {
            e->_04.y = pos.y / 2.0f;
        }
        if (pos.z != 0.0f) {
            e->_04.z = pos.z / 2.0f;
        }
        lbl_2_data_2FED4.y = e->_14;
        CTRLSetTranslation(&lbl_2_bss_340140->_0068->models[i].control, pos.x, pos.y, pos.z);
        CTRLSetRotation(&lbl_2_bss_340140->_0068->models[i].control, 57.295776f * lbl_2_data_2FED4.x,
                        57.295776f * lbl_2_data_2FED4.y, 57.295776f * lbl_2_data_2FED4.z);
        lbl_2_bss_340140->_0068->models[i]._6C = lbl_2_bss_3401BC->_50[i];
    }
}

// .text:0x0008ACDC size:0x4
void fn_2_8ACDC(void) {
}
