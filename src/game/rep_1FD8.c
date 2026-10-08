#include "game/rep_1FD8.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/rand.h"
#include "musyx/musyx.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtxext.h"
#include "C3/control.h"
#include "C3/geoPalette.h"
#include "game/rep_1D58.h"
#include "game/rep_AC8.h"
#include "game/rep_23E8.h"
#include "string.h"
#include "game/m_sound.h"
#include "game/rep_D0.h"

typedef struct Rep1FD8Sprite {
    /* 0x00 */ u8 _00[0x48];
    /* 0x48 */ Vec _48;
    /* 0x54 */ u32 _54;
    /* 0x58 */ u8 _58[0x5C - 0x58];
    /* 0x5C */ s32 _5C;
    /* 0x60 */ u8 _60[0x69 - 0x60];
    /* 0x69 */ u8 _69;
} Rep1FD8Sprite;

typedef struct Rep1FD8SpriteRef {
    /* 0x00 */ Rep1FD8Sprite* _00;
    /* 0x04 */ u8 _04[0x8 - 0x4];
} Rep1FD8SpriteRef; // size: 0x8

typedef struct Rep1FD8Task {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ u16 _14;
} Rep1FD8Task;

typedef struct Rep1FD8Particle {
    /* 0x00 */ struct Rep1FD8Particle* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ f32 grow;
    /* 0x20 */ f32 growScale;
    /* 0x24 */ f32 alpha;
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
    /* 0x50 */ u8 _50;
} Rep1FD8Particle;

typedef struct Rep1FD8Spawner {
    /* 0x00 */ u8 _00[0x08];
    /* 0x08 */ void* _08;
    /* 0x0C */ Rep1FD8Particle* particles;
    /* 0x10 */ void* _10;
    /* 0x14 */ u16 _14_hi : 4;
    /* 0x14 */ u16 count : 12;
    union {
        /* 0x18 */ Vec pos;
        struct {
            /* 0x18 */ Vec* target;
            /* 0x1C */ u8 _1C[0x20 - 0x1C];
            /* 0x20 */ struct Rep1FD8Draw* owner;
        };
    };
    union {
        struct {
            /* 0x24 */ u8 idx;
            /* 0x25 */ u8 _25;
        };
        /* 0x24 */ s32 timer;
    };
} Rep1FD8Spawner;

typedef struct Rep1FD8SpawnerTask {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ Rep1FD8Spawner* spawners[6];
} Rep1FD8SpawnerTask;

extern u32 fn_8005268C(void);
extern camera_803c639c_s* fn_80052734(s32 idx);
extern void fn_80033CC8(Rep1FD8Particle* p, void* texture);
extern void fn_8003403C(f32 width, f32 height);
extern void fn_80033620(Rep1FD8Spawner* emitter);
typedef struct Rep1FD8TexRegs {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x4 - 0x1];
    /* 0x04 */ u32 _04;
    /* 0x08 */ u8 _08[0x10 - 0x8];
} Rep1FD8TexRegs; // size: 0x10

typedef struct Rep1FD8TexInfo {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ Rep1FD8TexRegs* _04;
    /* 0x08 */ u16 _08;
} Rep1FD8TexInfo;

typedef struct Rep1FD8TexMap {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ Rep1FD8TexInfo* _10;
} Rep1FD8TexMap;

typedef struct Rep1FD8Bone {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ Rep1FD8TexMap* _14;
} Rep1FD8Bone;

typedef struct Rep1FD8Actor {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x18 - 0x8];
    /* 0x18 */ Rep1FD8Bone** _18;
} Rep1FD8Actor;

typedef struct Rep1FD8Model {
    /* 0x00 */ Rep1FD8Actor* _00;
    /* 0x04 */ u8 _04[0x90 - 0x04];
} Rep1FD8Model; // size: 0x90

typedef struct Rep1FD8ModelTable {
    /* 0x00 */ u16 count;
    /* 0x04 */ Mtx _04;
    /* 0x34 */ Rep1FD8Model models[1];
} Rep1FD8ModelTable;

typedef struct Rep1FD8Draw {
    /* 0x00 */ Control control;
    /* 0x44 */ Mtx _44;
    /* 0x74 */ Rep1FD8Model* _74;
    /* 0x78 */ struct StadiumObjectCollision* _78;
    /* 0x7C */ void (*_7C)(struct Rep1FD8Draw* draw);
    /* 0x80 */ void (*_80)(s32 idx);
    /* 0x84 */ void (*_84)(struct Rep1FD8Draw* draw);
    /* 0x88 */ void (*_88)(struct Rep1FD8Draw* draw);
    /* 0x8C */ void* _8C;
    /* 0x90 */ u8 _90_7 : 1;
    /* 0x90 */ u8 _90_6 : 1;
    /* 0x90 */ u8 _90_5 : 1;
    /* 0x90 */ u8 _90_0 : 5;
    /* 0x91 */ u8 _91;
    /* 0x92 */ u8 _92;
    /* 0x93 */ u8 _93;
    /* 0x94 */ u16 _94;
    /* 0x96 */ s16 _96;
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B;
    /* 0x9C */ Vec _9C;
    /* 0xA8 */ u8 _A8;
    /* 0xA9 */ u8 _A9;
    /* 0xAA */ u8 _AA[0xAC - 0xAA];
    union {
        struct {
            /* 0xAC */ f32 _AC;
            /* 0xB0 */ u8 _B0;
            /* 0xB1 */ u8 _B1;
            /* 0xB2 */ u8 _B2;
        };
        /* 0xAC */ Vec vel;
    };
    /* 0xB8 */ u16 _B8;
    /* 0xBA */ u16 _BA;
    /* 0xBC */ u8 _BC;
    /* 0xBD */ u8 _BD;
    /* 0xBE */ u8 _BE[0xE8 - 0xBE];
} Rep1FD8Draw; // size: 0xE8

extern struct {
    union {
        /* 0x00 */ StadiumObject1D58* _00;
        /* 0x00 */ Rep1FD8Draw* draws;
    };
    /* 0x04 */ void* _04;
    /* 0x08 */ u8 _08[0x18 - 0x08];
    /* 0x18 */ void (*_18)(void);
    /* 0x1C */ u8 _1C[0x20 - 0x1C];
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32* _34;
    /* 0x38 */ u8 _38[0x3C - 0x38];
    /* 0x3C */ u32* _3C;
    /* 0x40 */ u16* _40;
    /* 0x44 */ s32* _44;
    /* 0x48 */ Vec* _48;
    /* 0x4C */ u8 _4C[0x64 - 0x4C];
    /* 0x64 */ s16 _64;
    /* 0x66 */ u8 _66[0x6D - 0x66];
    /* 0x6D */ u8 _6D;
} lbl_3_common_bss_350E4;

typedef struct Rep1FD8CameraSlot {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*_04)(struct Rep1FD8CameraSlot* slot);
    /* 0x08 */ Mtx view;
    /* 0x38 */ struct Rep1FD8CameraTask* task;
} Rep1FD8CameraSlot; // size: 0x3C

typedef struct Rep1FD8CameraTask {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ Vec _14;
    /* 0x20 */ s16 _20[2];
    /* 0x24 */ s8 _24;
    /* 0x25 */ s8 _25[2];
    /* 0x27 */ u8 _27[2];
    /* 0x29 */ u8 _29;
    /* 0x2A */ u8 _2A;
} Rep1FD8CameraTask;

extern u8 lbl_803CBBC0;
extern void fn_800A7D4C(s32, void*);
extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];
extern BOOL fn_8001B728(s32, s32, Vec*);
extern void fn_800BF058(void (*draw)(StadiumModel1D58* model, Mtx view));
extern void fn_800BDF70(StadiumModel1D58* model);
extern Rep1FD8Spawner* fn_80033A24(BOOL (*update)(Rep1FD8Spawner*), s32, s32, s32, s32, u8);
extern void pitchingMachinePitching(u8 id);
extern Rep1FD8Task* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800528C0(f32 x, f32 y, f32 z, s16* screenX, s16* screenY);
extern Rep1FD8SpriteRef lbl_80371C30[];
extern void* lbl_803CC1B8;
extern void fn_800B0A14_removeQueue(void);
extern void fn_80034CEC(Rep1FD8Task* task);
extern void fn_8003A8A0(struct DODisplayObj* obj, MtxPtr view, s32 arg2);

typedef struct Rep1FD8LightData {
    /* 0x00 */ s16 pos[3];
    /* 0x06 */ GXColor color;
} Rep1FD8LightData; // size: 0xA

typedef struct Rep1FD8Light {
    /* 0x00 */ Vec pos;
    /* 0x0C */ GXColor color;
} Rep1FD8Light; // size: 0x10

typedef struct Rep1FD8StadiumLights {
    /* 0x00 */ Rep1FD8LightData lights[4];
    /* 0x28 */ GXColor ambient;
} Rep1FD8StadiumLights; // size: 0x2C

typedef struct Rep1FD8StadiumFile {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ u32 tex;
} Rep1FD8StadiumFile;

extern Rep1FD8StadiumLights lbl_800F7478[14];
extern Rep1FD8Light lbl_80367318[4];
typedef struct Rep1FD8Fielder {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ f32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
} Rep1FD8Fielder;

extern struct {
    /* 0x0000 */ u8 _0000[0x4];
    /* 0x0004 */ Rep1FD8StadiumFile* _04;
    /* 0x0008 */ u8 _0008[0x6C - 0x8];
    /* 0x006C */ Rep1FD8ModelTable* _6C;
    /* 0x0070 */ u8 _0070[0x2C50 - 0x70];
    /* 0x2C50 */ Rep1FD8Fielder* _2C50[13];
} lbl_8036E548;
extern struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ u8 _04[0x14 - 0x04];
    /* 0x14 */ u16 _14;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A[0x1D - 0x1A];
    /* 0x1D */ u8 _1D;
} lbl_803C5090;
extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;
extern void fn_80023B90(Rep1FD8LightData* data, Rep1FD8Light* light);
extern void fn_800528B4(void);
extern Rep1FD8ModelTable* ActorObjectInitTable(u16 count);
extern void fn_800BDC88(Rep1FD8ModelTable* table, u16 first, u16 last, void* model, void* anim, s32 arg5);
extern void fn_800BD548(Rep1FD8Model* model, s32 count, ...);
extern void fn_80025DDC(void* anim);
extern void fn_80025C58(void* anim, Rep1FD8Model* model);
extern void fn_80025FFC(void* anim, struct Rep1FD8Anim* state);
extern void fn_80025EEC(struct Rep1FD8Anim* anim, s32, s32);
extern void fn_80035750(void* arg0, void* arg1, s32 arg2);
extern void fn_80034E20(Rep1FD8Task* task, void* desc);
extern u8 lbl_3_data_10C1C[0x120];
extern s16 fn_3_B7F70(s16 range);
extern BOOL fn_80033928(u8 id);
extern void SetDisplayStateTexture(void* tex, s32, s32);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern Rep1FD8Spawner* fn_800339F0(Rep1FD8Spawner* start, u8 id);
extern void fn_800BEBCC(u8 idx, Vec dir);

static const u8 lbl_3_rodata_2028[3] = { 0xA0, 0x46, 0x00 };
static const Vec lbl_3_rodata_202C[6] = {
    { -19.3f, -14.5f, 86.0f },
    { 19.3f, -14.5f, 86.0f },
    { -15.92f, -18.8f, 112.16f },
    { 15.92f, -18.8f, 112.16f },
    { -36.5f, -17.9f, -22.8f },
    { 36.5f, -17.9f, -22.8f },
};
static const Vec lbl_3_rodata_2080 = { 0.0f, 0.0f, 0.0f };

typedef struct Rep1FD8Prop {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ u8 type;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} Rep1FD8Prop; // size: 0x14

typedef struct Rep1FD8Prop2 {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ u8 type;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
} Rep1FD8Prop2; // size: 0x18

// fn_3_C8650 reads 17508, 17514, 175FC, 17704 and 177E0 from one pool base, so they are static
static f32 lbl_3_data_17508[3] = { 1.0f, 3.0f, 5.0f };
static Rep1FD8Prop lbl_3_data_17514[11] = {
    { { -51.592f, -18.0f, 68.051f }, 306.0f, 2, 1, 1, 2 },
    { { -43.569f, -18.0f, 76.869f }, 314.0f, 2, 1, 1, 2 },
    { { -33.845f, -18.0f, 84.008f }, 330.0f, 2, 1, 1, 2 },
    { { 51.592f, -18.0f, 68.051f }, 52.0f, 2, 1, 2, 2 },
    { { 43.569f, -18.0f, 76.869f }, 44.0f, 2, 1, 2, 2 },
    { { 33.845f, -18.0f, 84.008f }, 28.0f, 2, 1, 2, 2 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 7, 0, 255, 7 },
};
f32 lbl_3_data_175F0[3] = { 0.06f, 0.07f, 0.08f };
static Rep1FD8Prop2 lbl_3_data_175FC[11] = {
    { { -48.0f, 5.5f, 25.0f }, 0.0f, 3, 1, 1, 3, 295, 1 },
    { { -43.0f, 5.5f, 56.0f }, 0.0f, 3, 1, 1, 3, 315, 90 },
    { { -10.0f, 5.5f, 77.0f }, 0.0f, 3, 1, 2, 3, 180, 90 },
    { { 10.0f, 5.5f, 77.0f }, 0.0f, 3, 1, 2, 3, 270, 90 },
    { { 45.0f, 5.5f, 23.0f }, 0.0f, 3, 1, 3, 3, 245, 1 },
    { { 43.0f, 5.5f, 56.0f }, 0.0f, 3, 1, 3, 3, 135, 90 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 7, 0, 255, 7 },
};
static Rep1FD8Prop lbl_3_data_17704[11] = {
    { { -12.891f, -5.93f, 87.961f }, 348.0f, 4, 1, 1, 6 },
    { { 12.891f, -5.93f, 87.961f }, 12.0f, 4, 1, 1, 6 },
    { { -23.0f, -0.02f, 72.0f }, 0.0f, 5, 1, 2, 6 },
    { { -22.0f, -0.02f, 45.0f }, 0.0f, 5, 1, 2, 6 },
    { { -50.0f, -0.02f, 38.0f }, 0.0f, 5, 1, 2, 6 },
    { { 23.0f, -0.02f, 72.0f }, 0.0f, 5, 1, 3, 6 },
    { { 22.0f, -0.02f, 45.0f }, 0.0f, 5, 1, 3, 6 },
    { { 50.0f, -0.02f, 38.0f }, 0.0f, 5, 1, 3, 6 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 7, 0, 255, 7 },
};
static u8 lbl_3_data_177E0[16] = { 1, 2, 2, 2, 2, 2, 2, 6, 6, 6, 8, 9, 8, 9, 0, 0 };
u16 lbl_3_data_177F0 = 4;
s32 lbl_3_data_177F4 = 2;
Rep1FD8LightData lbl_3_data_177F8 = { { 200, 1426, 2152 }, { 0xFF, 0xFF, 0xFF, 0x00 } };
Rep1FD8CameraSlot lbl_3_data_17804[2] = {
    { 0, fn_3_C1C18 },
    { 0, fn_3_C1C18 },
};
f32 lbl_3_data_1787C = 0.7f;
s16 lbl_3_data_17880[3][3] = {
    { 106, -98, 220 },
    { 94, -87, 230 },
    { 120, -80, 212 },
};

typedef struct Rep1FD8Anim {
    /* 0x00 */ void* file;
    /* 0x04 */ u8 _04[0x5C - 0x04];
} Rep1FD8Anim; // size: 0x5C

// .bss, declared in reverse address order (MWCC lays .bss statics out last to first)
static void* lbl_3_bss_9F0C[5];
static Rep1FD8Anim lbl_3_bss_9EB0;
static Rep1FD8Anim lbl_3_bss_9E54;
static Rep1FD8Task* lbl_3_bss_9E50;
static u8 lbl_3_bss_9E48[8];
static Vec lbl_3_bss_9DE8[8];
static u8 lbl_3_bss_9DE7;
static u8 lbl_3_bss_9DE6;
static u8 lbl_3_bss_9DE5;
static u8 lbl_3_bss_9DE4;
static u8 lbl_3_bss_9DE3;
static u8 lbl_3_bss_9DE2;
static u8 lbl_3_bss_9DE1;
static u8 lbl_3_bss_9DE0;
static u8 lbl_3_bss_9DA0[0x40];
static s32 lbl_3_bss_9D9C;
static u8* lbl_3_bss_9D98;
static StadiumObject1D58* lbl_3_bss_9D94;
static Rep1FD8CameraTask* lbl_3_bss_9D90;
static u32 lbl_3_bss_9D8C;
static u32 lbl_3_bss_9D88;
static u32 lbl_3_bss_9D84;
static u8 lbl_3_bss_9D82;
static u8 lbl_3_bss_9D81;
static u8 lbl_3_bss_9D80;

// .text:0x000C8650 size:0xD2C mapped:0x807076E4
// 94.59%: registers differ throughout, and the target spills &g_d_GameSettings to 8(r1) for
// the final GameModeSelected test and sets the first loop's end flag before draws[1] is set up.
void fn_3_C8650(void** files) {
    Rep1FD8Draw* draw;
    Rep1FD8Prop* prop;
    Rep1FD8Prop2* prop2;
    s32* indices;
    u32 n;
    u32 total;
    u32 i;
    u32 j;
    u32 k;
    s32 l;
    s32 m;
    s32 count;
    u8 end;

    lbl_3_common_bss_350E4._18 = fn_3_B939C;
    indices = lbl_3_common_bss_350E4._34 = _OSAllocFromHeap(4, 16 * sizeof(s32));
    fn_3_B9D68(lbl_3_data_177E0, 16, files, indices);
    lbl_3_bss_9F0C[0] = files[0];
    for (n = 0; n < 10; n++) {
        if (lbl_3_data_175FC[n].type == 7) {
            break;
        }
    }
    total = n + 5;
    lbl_3_common_bss_350E4._6D = total;
    lbl_8036E548._6C = ActorObjectInitTable(total);
    fn_800BDC88(lbl_8036E548._6C, 0, 0, files[indices[1]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 1, 1, files[indices[2]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 2, 2, files[indices[3]], NULL, 0);
    for (i = 0, j = 3; i < n; i++, j++) {
        fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[4]], NULL, 0);
    }
    fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[5]], NULL, 0);
    k = j + 1;
    fn_800BDC88(lbl_8036E548._6C, k, k, files[indices[6]], NULL, 0);
    for (i = 0; i < total; i++) {
        fn_800BD548(&lbl_8036E548._6C->models[i], 4, lbl_3_common_bss_350E4._20, lbl_3_common_bss_350E4._24,
                    lbl_3_common_bss_350E4._28, lbl_3_common_bss_350E4._2C);
    }
    fn_80025DDC(files[indices[10]]);
    for (i = 0; i < n; i++) {
        fn_80025C58(files[indices[10]], &lbl_8036E548._6C->models[i + 3]);
    }
    lbl_3_bss_9EB0.file = files[indices[11]];
    fn_80025FFC(files[indices[10]], &lbl_3_bss_9EB0);
    fn_80025EEC(&lbl_3_bss_9EB0, 0, 0);
    fn_80025DDC(files[indices[12]]);
    fn_80025C58(files[indices[12]], &lbl_8036E548._6C->models[1]);
    lbl_3_bss_9E54.file = files[indices[13]];
    fn_80025FFC(files[indices[12]], &lbl_3_bss_9E54);
    fn_80025EEC(&lbl_3_bss_9E54, 0, 0);
    fn_80035750(files[indices[15]], files[indices[14]], 5);
    fn_80034E20(lbl_3_bss_9E50 = fn_800B0A5C_insertQueue(fn_3_C3C2C, 2), lbl_3_data_10C1C);

    lbl_3_common_bss_350E4._30 = 32;
    lbl_3_common_bss_350E4.draws = _OSAllocFromHeap(32, 32 * sizeof(Rep1FD8Draw));
    memset(lbl_3_common_bss_350E4.draws, 0, 32 * sizeof(Rep1FD8Draw));
    lbl_3_common_bss_350E4._04 = _OSAllocFromHeap(32, 32 * sizeof(Rep1FD8Draw));
    memset(lbl_3_common_bss_350E4._04, 0, 32 * sizeof(Rep1FD8Draw));

    draw = lbl_3_common_bss_350E4.draws;
    draw->_A9 = 0;
    draw->_74 = &lbl_8036E548._6C->models[0];
    draw->_78 = NULL;
    draw->_7C = fn_3_C4068;
    draw->_80 = NULL;
    draw->_90_7 = 1;
    draw->_90_6 = draw->_90_7 && draw->_78 != NULL;
    draw->control.type = 0;
    CTRLSetTranslation(&draw->control, 0.0f, 0.0f, 0.0f);
    CTRLSetRotation(&draw->control, 0.0f, 0.0f, 0.0f);
    draw->_90_5 = 0;
    draw->_92 = 0xFF;
    draw->_8C = NULL;
    draw->_84 = NULL;
    draw->_94 = 0;
    draw->_96 = -1;
    draw->_98 = 0;
    draw++;
    draw->_A9 = 1;
    draw->_74 = &lbl_8036E548._6C->models[1];
    draw->_78 = NULL;
    draw->_7C = fn_3_C3F70;
    draw->_80 = NULL;
    draw->_90_7 = 1;
    draw->_90_6 = draw->_90_7 && draw->_78 != NULL;
    draw->control.type = 0;
    CTRLSetTranslation(&draw->control, 0.0f, 0.0f, 0.0f);
    CTRLSetRotation(&draw->control, 0.0f, 0.0f, 0.0f);
    draw->_90_5 = 0;
    draw->_92 = 0xFF;
    draw->_8C = &lbl_3_bss_9E54;
    draw->_84 = NULL;
    draw->_94 = 0;
    draw->_96 = -1;
    draw->_98 = 1;
    draw++;
    count = 2;

    if (g_d_GameSettings.GameModeSelected != 7) {
        end = FALSE;
        lbl_3_bss_9DE5 = 0;
        lbl_3_bss_9DE4 = count;
        for (l = 0, prop = lbl_3_data_17514; l < 10; l++, prop++) {
            if (prop->type == 7) {
                end = TRUE;
            }
            if (end) {
                for (m = l; m < 11; m++) {
                    lbl_3_data_17514[m].type = 7;
                }
                break;
            }
            draw->_A8 = l;
            draw->_A9 = prop->type;
            draw->_74 = &lbl_8036E548._6C->models[2];
            draw->_78 = files[indices[7]];
            draw->_7C = fn_3_C7A0C;
            draw->_80 = (void (*)(s32))fn_3_C749C;
            draw->_90_7 = prop->_11;
            draw->_90_6 = draw->_90_7 && draw->_78 != NULL;
            draw->control.type = 0;
            CTRLSetTranslation(&draw->control, prop->pos.x, prop->pos.y, prop->pos.z);
            CTRLSetRotation(&draw->control, 0.0f, prop->rotY, 0.0f);
            draw->_9C.x = prop->pos.x;
            count++;
            draw->_9C.y = prop->pos.y;
            draw->_9C.z = prop->pos.z;
            draw->_AC = 0.0f;
            draw->_B0 = 0;
            draw->_B1 = 0;
            draw->_B2 = 1;
            draw->_90_5 = 0;
            draw->_92 = 0xFF;
            draw->_84 = fn_3_C7444;
            draw->_8C = NULL;
            draw->_94 = 0;
            draw->_96 = -1;
            draw->_98 = 1;
            draw->_9A = 1;
            draw++;
            lbl_3_bss_9DE5++;
        }
        end = FALSE;
        lbl_3_bss_9DE3 = 0;
        lbl_3_bss_9DE2 = count;
        for (l = 0, prop2 = lbl_3_data_175FC; l < 10; l++, prop2++) {
            if (prop2->type == 7) {
                end = TRUE;
            }
            if (end) {
                for (m = l; m < 11; m++) {
                    lbl_3_data_175FC[m].type = 7;
                }
                break;
            }
            draw->_A8 = l;
            draw->_A9 = prop2->type;
            draw->_74 = &lbl_8036E548._6C->models[l + 3];
            draw->_78 = NULL;
            draw->_7C = fn_3_C63D0;
            draw->_80 = NULL;
            draw->_90_7 = prop2->_11;
            draw->_90_6 = draw->_90_7 && draw->_78 != NULL;
            draw->_BC = fn_3_B7F70(240) + 1;
            draw->_BD = 0;
            draw->vel.x = draw->vel.y = draw->vel.z = 0.0f;
            draw->_B8 = prop2->_14;
            draw->_BA = prop2->_16;
            draw->control.type = 0;
            CTRLSetTranslation(&draw->control, prop2->pos.x, prop2->pos.y, prop2->pos.z);
            CTRLSetRotation(&draw->control, 0.0f, prop2->rotY, 0.0f);
            draw->_9C.x = prop2->pos.x;
            count++;
            draw->_9C.y = prop2->pos.y;
            draw->_9C.z = prop2->pos.z;
            draw->_90_5 = 1;
            draw->_92 = 0xFF;
            draw->_8C = &lbl_3_bss_9EB0;
            draw->_84 = fn_3_C56E8;
            draw->_88 = fn_3_C54D0;
            draw->_94 = 1;
            draw->_96 = 4;
            draw->_98 = 1;
            draw->_9A = 1;
            draw++;
            lbl_3_bss_9DE3++;
        }
        lbl_3_bss_9D82 = 0;
        fn_800B0A5C_insertQueue(fn_3_C5DDC, 0x6001);
        end = FALSE;
        lbl_3_bss_9DE1 = 0;
        lbl_3_bss_9DE0 = count;
        for (l = 0, prop = lbl_3_data_17704; l < 10; l++, prop++) {
            if (prop->type == 7) {
                end = TRUE;
            }
            if (end) {
                for (m = l; m < 11; m++) {
                    lbl_3_data_17704[m].type = 7;
                }
                break;
            }
            draw->_A8 = l;
            draw->_A9 = prop->type;
            if (draw->_A9 == 4) {
                draw->_74 = &lbl_8036E548._6C->models[j];
                draw->_78 = files[indices[8]];
            } else {
                draw->_74 = &lbl_8036E548._6C->models[k];
                draw->_78 = files[indices[9]];
            }
            draw->_7C = NULL;
            draw->_80 = fn_3_C414C;
            draw->_90_7 = prop->_11;
            draw->_90_6 = draw->_90_7 && draw->_78 != NULL;
            draw->control.type = 0;
            CTRLSetTranslation(&draw->control, prop->pos.x, prop->pos.y, prop->pos.z);
            CTRLSetRotation(&draw->control, 0.0f, prop->rotY, 0.0f);
            draw->_90_5 = 1;
            draw->_92 = 0xFF;
            count++;
            draw->_8C = NULL;
            draw->_84 = fn_3_C40EC;
            draw->_94 = 0;
            draw->_96 = -1;
            draw->_98 = 1;
            draw++;
            lbl_3_bss_9DE1++;
        }
    }
    if (count < lbl_3_common_bss_350E4._30) {
        for (l = count; l < lbl_3_common_bss_350E4._30; l++, draw++) {
            draw->_A9 = 0;
            draw->_74 = NULL;
            draw->_78 = NULL;
            draw->_7C = NULL;
            draw->_80 = NULL;
            draw->_90_7 = 0;
            draw->_90_6 = 0;
            draw->_90_5 = 0;
            draw->control.type = 0;
            CTRLSetTranslation(&draw->control, 0.0f, 0.0f, 0.0f);
            CTRLSetRotation(&draw->control, 0.0f, 0.0f, 0.0f);
            draw->_92 = 0;
            draw->_8C = NULL;
            draw->_94 = 0;
            draw->_96 = -1;
        }
    }
    lbl_3_common_bss_350E4._48 = NULL;
    if (g_d_GameSettings.GameModeSelected != 7) {
        fn_3_C82B4();
    }
    fn_800528AC(fn_3_C3A38);
    fn_3_C39C8();
    fn_3_C1974(files[indices[0]]);
    fn_3_B97C8(fn_3_C2974);
}

// .text:0x000C82B4 size:0x39C mapped:0x80707348
void fn_3_C82B4(void) {
    u32 n;
    s32 count;
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
    count = 0;
    fn_3_C805C(&n, &count);
    fn_3_C42A4(&n, &count);
    lbl_3_common_bss_350E4._64 = n;
}

// .text:0x000C823C size:0x78 mapped:0x807072D0
struct StadiumObjectCollision* fn_3_C823C(s32 idx, MtxPtr mtx) {
    Rep1FD8Draw* draw = &lbl_3_common_bss_350E4.draws[idx];

    CTRLBuildMatrix(&draw->control, mtx);
    if (draw->_A9 == 5) {
        mtx[1][3] = -0.002f;
    }
    return lbl_3_common_bss_350E4.draws[idx]._78;
}

// .text:0x000C805C size:0x1E0 mapped:0x807070F0
void fn_3_C805C(u32* n, s32* count) {
    Mtx m;
    Control control;
    StadiumObject1D58* obj;
    s32 next;
    s32 group;
    s32 i;

    for (group = 0; group < 5; group++) {
        next = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
        fn_3_B8574();
        for (i = 0; i < 10; i++) {
            if (group == lbl_3_data_17514[i]._12 && lbl_3_data_17514[i].type != 7) {
                if (lbl_3_common_bss_350E4._00[i + lbl_3_bss_9DE4]._90_6) {
                    lbl_3_common_bss_350E4._44[next] = i + lbl_3_bss_9DE4;
                    next++;
                    lbl_3_common_bss_350E4._3C[*n]++;
                    obj = &lbl_3_common_bss_350E4._00[i + lbl_3_bss_9DE4];
                    control = obj->control;
                    CTRLBuildMatrix(&obj->control, m);
                    fn_3_B8464(m, obj->_78);
                    CTRLSetTranslation(&control, lbl_3_data_17514[i].pos.x, -5.0f, lbl_3_data_17514[i].pos.z);
                    CTRLBuildMatrix(&control, m);
                    fn_3_B8464(m, obj->_78);
                    (*count)++;
                }
            }
        }
        if (lbl_3_common_bss_350E4._3C[*n] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
            (*n)++;
        }
    }
}

// .text:0x000C7A0C size:0x650 mapped:0x80706AA0
// 99.22%: only the inlined fn_3_C77AC differs, in the FPRs of its hoisted constants.
void fn_3_C7A0C(Rep1FD8Draw* draw) {
    Vec pos;
    Rep1FD8Spawner* spawner;
    f32 x;
    f32 dist;

    if (g_GameLogic.gameStatus != 2) {
        if (draw->_99 == 0) {
            draw->_9C.y = lbl_3_data_17514[draw->_A8].pos.y;
            draw->_B0 = 0;
            draw->_B2 = 1;
            CTRLSetTranslation(&draw->control, draw->_9C.x, draw->_9C.y, draw->_9C.z);
            pitchingMachinePitching(draw->_A8 + 62);
            draw->_99 = 1;
        }
        if (g_GameLogic.gameStatus == 0) {
            draw->_AC = lbl_3_data_17508[fn_3_B7F70(3)];
        }
    } else {
        draw->_99 = 0;
        switch (draw->_B0) {
        case 0:
            if (draw->_B2 != 0) {
                if (g_Ball.ballState != 0) {
                    draw->_B2 = 0;
                } else if (g_Ball.physicsSubstruct.velocity.z < 0.0f) {
                    draw->_B2 = 0;
                } else if (g_Ball.deadBallReason != 0) {
                    draw->_B2 = 0;
                } else {
                    x = g_Ball.physicsSubstruct.velocity.x / g_Ball.physicsSubstruct.velocity.z *
                            (draw->_9C.z - g_Ball.AtBat_Contact_BallPos.z) +
                        g_Ball.AtBat_Contact_BallPos.x;
                    if (x < draw->_9C.x - 25.0f || x > 25.0f + draw->_9C.x) {
                        draw->_B2 = 0;
                    } else {
                        dist = sqrt(pow(draw->_9C.x - g_Ball.AtBat_Contact_BallPos.x, 2.0) +
                                    pow(draw->_9C.y + g_Ball.AtBat_Contact_BallPos.y, 2.0) +
                                    pow(draw->_9C.z - g_Ball.AtBat_Contact_BallPos.z, 2.0));
                        if (dist < 23.0f && g_Ball.AtBat_Contact_BallPos.y < 3.0f - draw->_9C.y) {
                            draw->_B0 = 1;
                        }
                    }
                }
            }
            break;
        case 1:
            if (draw->_9C.y <= lbl_3_data_17514[draw->_A8].pos.y - 2.5) {
                draw->_9C.y = lbl_3_data_17514[draw->_A8].pos.y - 2.5;
                draw->_B0 = 2;
            } else {
                draw->_9C.y -= 0.25;
            }
            break;
        case 2:
            draw->_9C.y += draw->_AC;
            if (draw->_9C.y >= -5.0) {
                draw->_9C.y = -5.0f;
                memcpy(&pos, &draw->_9C, sizeof(Vec));
                draw->_B0 = 3;
                draw->_B1 = 0;
                lbl_3_bss_9D81 = 1;
                fn_800528AC(fn_3_C3A38);
                fn_3_8BBC4(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 5, &pos, NULL, 9);
            }
            if (4.0f * draw->_AC + draw->_9C.y >= -5.0) {
                spawner = fn_80033A24(fn_3_C75B8, 128, 0, 12, 1, draw->_A8 + 62);
                if (spawner != NULL) {
                    fn_3_C77AC(spawner, draw);
                }
            }
            break;
        case 3:
            if (draw->_B1++ > 40) {
                draw->_B0 = 4;
                draw->_B1 = 0;
            }
            break;
        case 4:
            if (draw->_9C.y <= lbl_3_data_17514[draw->_A8].pos.y) {
                draw->_9C.y = lbl_3_data_17514[draw->_A8].pos.y;
                draw->_B0 = 0;
            } else {
                draw->_9C.y -= 0.2;
            }
            break;
        }
        CTRLSetTranslation(&draw->control, draw->_9C.x, draw->_9C.y, draw->_9C.z);
    }
}

// .text:0x000C77AC size:0x260 mapped:0x80706840
void fn_3_C77AC(Rep1FD8Spawner* spawner, Rep1FD8Draw* draw) {
    Rep1FD8Particle* p = spawner->particles;
    u32 i;
    f32 rad;

    spawner->target = &draw->_9C;
    spawner->owner = draw;
    spawner->_10 = lbl_3_bss_9F0C[0];
    spawner->timer = 30;
    for (i = 0; p != NULL; i++, p = p->next) {
        p->_38 = p->_3C = 0.0f;
        p->grow = 8.0f - rand() % 3;
        rad = 3.1415927f * (lbl_3_data_17514[draw->_A8].rotY + i * 30) / 180.0f;
        p->vel.x = 0.35f * cos(rad);
        p->vel.y = -(rand() % 3);
        p->vel.z = 0.35f * sin(rad);
        p->pos.x = spawner->target->x;
        p->pos.z = spawner->target->z;
        p->delay = i / 4;
        p->_4D = 28;
        p->_4E = 0;
        p->color[0] = p->color[1] = p->color[2] = 127;
        p->color[3] = 153;
        p->life = 1;
    }
}

// .text:0x000C75B8 size:0x1F4 mapped:0x8070664C
BOOL fn_3_C75B8(Rep1FD8Spawner* spawner) {
    Rep1FD8Particle* p;
    s32 exp = -spawner->timer;

    fn_80033620(spawner);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    p = spawner->particles;
    do {
        if (p->delay != 0) {
            p->delay -= lbl_80366158._28 == 0;
        } else if (p->life != 0) {
            fn_8003403C(p->_38, p->_3C);
            fn_80033CC8(p, spawner->_10);
            if (lbl_80366158._28 == 0) {
                if (p->_38 < p->grow) {
                    p->_38 += p->grow / 12.0f;
                    p->_3C += p->grow / 12.0f;
                }
                p->pos.x += p->vel.x;
                p->pos.z += p->vel.z;
                p->pos.y = p->vel.y + spawner->target->y - 5.0 * pow(2.0, exp);
                if (30 - spawner->timer >= 16) {
                    p->color[3] -= 10.928572f;
                }
            }
        }
        p = p->next;
    } while (p != NULL);
    spawner->timer -= lbl_80366158._28 == 0;
    return !spawner->timer;
}

static inline void startBallEffect(s32 base) {
    s32 idx = (g_Ball.inAirOrBefore2ndBounceOrLowBallEnergy != 0) + base;

    lbl_3_bss_9E48[idx] = 1;
    lbl_3_bss_9DE8[idx].x = g_Ball.AtBat_Contact_BallPos.x;
    lbl_3_bss_9DE8[idx].y = -g_Ball.AtBat_Contact_BallPos.y;
    lbl_3_bss_9DE8[idx].z = g_Ball.AtBat_Contact_BallPos.z;
}

static inline void playStadiumSound(s32 sound) {
    s32 stadium;
    u8 vol;
    SND_VOICEID voice;

    stadium = g_d_GameSettings.StadiumID;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][0];
    } else {
        vol = lbl_3_data_8404[stadium][sound][0];
    }
    voice = sndFXStartEx(lbl_3_data_81DC[stadium] + sound, vol, 63, 0);
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        vol = lbl_3_data_84B8[sound][1];
    } else {
        vol = lbl_3_data_8404[stadium][sound][1];
    }
    sndFXCtrl(voice, 91, vol);
}

// .text:0x000C749C size:0x11C mapped:0x80706530
void fn_3_C749C(void) {
    startBallEffect(2);
    playStadiumSound(4);
}

// .text:0x000C7444 size:0x58 mapped:0x807064D8
void fn_3_C7444(Rep1FD8Draw* draw) {
    Rep1FD8TexRegs* regs = draw->_74->_00->_18[13]->_14->_10->_04;

    switch (draw->_B0) {
    case 0:
        regs->_04 &= ~0x1FFF;
        regs->_04 |= 2;
        break;
    default:
        regs->_04 &= ~0x1FFF;
        break;
    }
}

// .text:0x000C71CC size:0x278 mapped:0x80706260
void fn_3_C71CC(u32* n, s32* idx) {
    Mtx m;
    Control control;
    StadiumObject1D58* obj;
    s32 next;
    s32 group;
    s32 i;
    f32 dy;
    f32 d;
    f32 scale = 84.09091f;
    f32 base = 15.556819f;

    for (group = 0; group < 5; group++) {
        next = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
        fn_3_B8574();
        for (i = 0; i < 10; i++) {
            if (group == lbl_3_data_175FC[i]._12 && lbl_3_data_175FC[i].type != 7) {
                if (lbl_3_common_bss_350E4._00[*idx]._90_6) {
                    lbl_3_common_bss_350E4._44[next] = *idx;
                    next++;
                    lbl_3_common_bss_350E4._3C[*n]++;
                    obj = &lbl_3_common_bss_350E4._00[*idx];
                    control = obj->control;
                    CTRLBuildMatrix(&obj->control, m);
                    fn_3_B8464(m, obj->_78);
                    dy = -0.3 * scale + base;
                    d = lbl_3_data_175F0[2] * (2.0f * scale);
                    CTRLSetTranslation(&control, d + lbl_3_data_175FC[i].pos.x, dy + lbl_3_data_175FC[i].pos.y,
                                       d + lbl_3_data_175FC[i].pos.z);
                    CTRLBuildMatrix(&control, m);
                    fn_3_B8464(m, obj->_78);
                    CTRLSetTranslation(&control, lbl_3_data_175FC[i].pos.x - d, dy + lbl_3_data_175FC[i].pos.y,
                                       lbl_3_data_175FC[i].pos.z - d);
                    CTRLBuildMatrix(&control, m);
                    fn_3_B8464(m, obj->_78);
                    (*idx)++;
                }
            }
        }
        if (lbl_3_common_bss_350E4._3C[*n] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
            (*n)++;
        }
    }
}

// .text:0x000C63D0 size:0xDFC mapped:0x80705464
// 99.77%: the target tests checkCollision's result unsigned (cmplwi), and the inlined
// fn_3_C48D0 and fn_3_C444C allocate their FPRs as in fn_3_C597C.
void fn_3_C63D0(Rep1FD8Draw* draw) {
    Vec pos;
    Vec up = { 0.0f, 1.0f, 0.0f };
    Vec axis;
    Vec dir;
    VecSrcDst seg;
    CollisionStruct col;
    Quaternion q;
    Rep1FD8Spawner* spawner;
    f32 angle;
    f32 speed;
    u32 i;
    u8 hit = 0;

    if (g_GameLogic.gameStatus != 2) {
        if (draw->_99 == 0) {
            draw->_9C.x = lbl_3_data_175FC[draw->_A8].pos.x;
            draw->_9C.y = lbl_3_data_175FC[draw->_A8].pos.y;
            draw->_9C.z = lbl_3_data_175FC[draw->_A8].pos.z;
            draw->_BD = 0;
            CTRLSetTranslation(&draw->control, draw->_9C.x, draw->_9C.y, draw->_9C.z);
            draw->_90_7 = 0;
            pitchingMachinePitching(draw->_A8 + 42);
            pitchingMachinePitching(draw->_A8 + 52);
            draw->_99 = 1;
        }
        return;
    }
    draw->_99 = 0;
    switch (draw->_BD) {
    case 0:
        if (draw->_BC == 0) {
            for (i = 6; i < 9; i++) {
                if ((f32)sqrt(pow(lbl_8036E548._2C50[i]->_34 - draw->_9C.x, 2.0) +
                              pow(lbl_8036E548._2C50[i]->_3C - draw->_9C.z, 2.0)) < 5.0) {
                    draw->_9C.x = lbl_3_data_175FC[draw->_A8].pos.x;
                    draw->_9C.y = lbl_3_data_175FC[draw->_A8].pos.y;
                    draw->_9C.z = lbl_3_data_175FC[draw->_A8].pos.z;
                    CTRLSetTranslation(&draw->control, draw->_9C.x, draw->_9C.y, draw->_9C.z);
                    return;
                }
            }
            draw->_BD = 1;
            draw->_90_7 = 1;
            angle = 3.1415927f * (draw->_B8 + fn_3_B7F70(draw->_BA)) / 180.0f;
            speed = lbl_3_data_175F0[fn_3_B7F70(3)];
            draw->vel.x = speed * cos(angle);
            draw->vel.y = 0.37f;
            draw->vel.z = speed * sin(angle);
            spawner = fn_80033A24(fn_3_C4F00, 128, 0, 7, 1, draw->_A8 + 42);
            if (spawner != NULL) {
                fn_3_C5304(spawner, draw);
                spawner->_10 = lbl_3_bss_9F0C[0];
            }
            draw->_BC = fn_3_B7F70(240) + 1;
            playStadiumSound(3);
        } else {
            draw->_BC--;
        }
        break;
    case 1:
        seg.src = draw->_9C;
        draw->_9C.x += draw->vel.x;
        draw->_9C.y -= draw->vel.y;
        draw->_9C.z += draw->vel.z;
        seg.dst = draw->_9C;
        draw->vel.y -= 0.0044f;
        PSVECNormalize(&draw->vel, &dir);
        PSVECCrossProduct(&dir, &up, &axis);
        C_QUATRotAxisRad(&q, &axis, acos(PSVECDotProduct(&dir, &up)));
        CTRLSetQuat(&draw->control, q.x, q.y, q.z, q.w);
        if (draw->vel.y < 0.0f && checkCollision(&seg, &col, 0, 0) != 0) {
            hit = 1;
        }
        if (fn_3_C625C(draw)) {
            hit = 2;
        }
        if (hit != 0) {
            pitchingMachinePitching(draw->_A8 + 42);
            if (hit == 1) {
                spawner = fn_80033A24(fn_3_C4724, 128, 0, 24, 1, draw->_A8 + 52);
                if (spawner != NULL) {
                    fn_3_C48D0(spawner, draw->_9C);
                    spawner->_10 = lbl_3_bss_9F0C[0];
                    spawner->timer = 30;
                }
            } else if (hit == 2) {
                spawner = fn_80033A24(fn_3_C4724, 128, 0, 24, 1, draw->_A8 + 52);
                if (spawner != NULL) {
                    fn_3_C444C(spawner, draw);
                    spawner->_10 = lbl_3_bss_9F0C[0];
                    spawner->timer = 30;
                }
            }
            draw->_BD = 3;
            draw->_90_7 = 0;
            draw->_9C.y = 10.0f;
        }
        break;
    case 2:
        if (fn_80033928(draw->_A8 + 52) == 0) {
            draw->_BD = 3;
        }
        break;
    case 3:
        draw->_BD = 0;
        draw->_9C.x = lbl_3_data_175FC[draw->_A8].pos.x;
        draw->_9C.y = lbl_3_data_175FC[draw->_A8].pos.y;
        draw->_9C.z = lbl_3_data_175FC[draw->_A8].pos.z;
        draw->vel.y = 0.37f;
        draw->_90_7 = 0;
        draw->_BC = fn_3_B7F70(240) + 1;
        CTRLSetRotation(&draw->control, 0.0f, lbl_3_data_175FC[draw->_A8].rotY, 0.0f);
        break;
    }
    CTRLSetTranslation(&draw->control, draw->_9C.x, draw->_9C.y, draw->_9C.z);
}

// .text:0x000C625C size:0x174 mapped:0x807052F0
u8 fn_3_C625C(Rep1FD8Draw* draw) {
    Vec pos = draw->_9C;
    Vec diff;

    if (g_Ball.ballState == 1) {
        return FALSE;
    }
    if (g_Ball.currentStarSwing2 == 11 | g_Ball.currentStarSwing2 == 12) {
        return FALSE;
    }
    pos.y *= -1.0f;
    PSVECSubtract((Vec*)&g_Ball, &pos, &diff);
    if (PSVECMag(&diff) <= 2.6f) {
        playStadiumSound(2);
        return TRUE;
    }
    return FALSE;
}

// .text:0x000C5DDC size:0x480 mapped:0x80704E70
// 99.77%: as in fn_3_C597C, the inlined fn_3_C48D0 allocates the position and angles in
// other FPRs (target y, z, theta, phi in f24..f21, base f22, f21, f23, f24).
void fn_3_C5DDC(void) {
    Rep1FD8Draw* draw;
    Rep1FD8Spawner* spawner;
    u32 i;

    if (lbl_3_bss_9D82 != 0) {
        lbl_3_bss_9D82 = 0;
        fn_800B0A14_removeQueue();
        return;
    }
    for (i = 0; i < lbl_3_bss_9DE3; i++) {
        draw = &lbl_3_common_bss_350E4.draws[lbl_3_bss_9DE2 + i];
        if (draw->_BD == 1 && fn_3_C5CE0(draw)) {
            spawner = fn_80033A24(fn_3_C4724, 128, 0, 24, 1, draw->_A8 + 52);
            if (spawner != NULL) {
                fn_3_C48D0(spawner, draw->_9C);
                spawner->_10 = lbl_3_bss_9F0C[0];
                spawner->timer = 30;
            }
            draw->_BD = 2;
            draw->_90_7 = 0;
            draw->_9C.y = 10.0f;
        }
    }
}

// .text:0x000C5CE0 size:0xFC mapped:0x80704D74
u8 fn_3_C5CE0(Rep1FD8Draw* draw) {
    Vec pos = lbl_3_rodata_2080;
    Vec diff;
    u32 i;

    if (g_GameLogic.gameStatus == 2 && g_GameLogic.playOver != 0) {
        return FALSE;
    }
    for (i = 0; i < 9; i++) {
        memset(&pos, 0, sizeof(Vec));
        fn_8001B728(i, 4, &pos);
        PSVECSubtract(&pos, &draw->_9C, &diff);
        if (PSVECMag(&diff) <= 2.6f) {
            fn_3_25844(i, 1);
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000C597C size:0x364 mapped:0x80704A10
// 99.70%: the inlined fn_3_C444C allocates its position and angles in other FPRs
// (target x..phi in f25..f21 and speed in f26, base the reverse order).
void fn_3_C597C(s32 idx) {
    Rep1FD8Draw* draw = &lbl_3_common_bss_350E4.draws[idx];
    Rep1FD8Spawner* spawner;

    pitchingMachinePitching(draw->_A8 + 42);
    spawner = fn_80033A24(fn_3_C4724, 128, 0, 24, 1, draw->_A8 + 52);
    if (spawner != NULL) {
        fn_3_C444C(spawner, draw);
        spawner->_10 = lbl_3_bss_9F0C[0];
        spawner->timer = 30;
    }
    draw->_BD = 2;
    draw->_90_7 = 0;
    draw->_9C.y = 10.0f;
}

// .text:0x000C56E8 size:0x294 mapped:0x8070477C
void fn_3_C56E8(Rep1FD8Draw* draw) {
    Vec center;
    Vec pos;
    Rep1FD8Spawner* spawner;
    Rep1FD8Particle* p;

    PSMTXMultVec(fn_80052734(fn_8005268C())->view, &draw->_9C, &center);
    spawner = fn_800339F0(NULL, draw->_A8 + 42);
    if (spawner != NULL) {
        for (p = spawner->particles; p != NULL; p = p->next) {
            PSMTXMultVec(fn_80052734(fn_8005268C())->view, &p->pos, &pos);
            if (center.z >= pos.z) {
                p->_50 = 0;
            } else {
                p->_50 = 1;
            }
        }
        fn_3_C4CF4(spawner, 0);
    }
}

// .text:0x000C54D0 size:0x218 mapped:0x80704564
void fn_3_C54D0(Rep1FD8Draw* draw) {
    Rep1FD8Spawner* spawner = fn_800339F0(NULL, draw->_A8 + 42);

    if (spawner != NULL) {
        fn_3_C4CF4(spawner, 1);
    }
}

// .text:0x000C5304 size:0x1CC mapped:0x80704398
void fn_3_C5304(Rep1FD8Spawner* spawner, Rep1FD8Draw* draw) {
    Rep1FD8Particle* p = spawner->particles;
    s16 delay = 0;

    spawner->target = &draw->_9C;
    spawner->owner = draw;
    while (p != NULL) {
        p->_38 = p->_3C = 0.0f;
        p->delay = delay;
        delay += 4;
        p->_4D = 21;
        p->_4E = 0;
        p->color[0] = p->color[1] = p->color[2] = 255;
        p->color[3] = 0;
        p->life = 1;
        p->duration = 0;
        if (p->delay == 0) {
            p->pos.x = spawner->target->x + (f32)(15 - rand() % 31) / 10.0f;
            p->pos.y = 2.5f + spawner->target->y;
            p->pos.z = spawner->target->z + (f32)(15 - rand() % 31) / 10.0f;
        } else {
            p->pos.x = p->pos.y = p->pos.z = 0.0f;
        }
        p = p->next;
    }
}

// .text:0x000C4F00 size:0x404 mapped:0x80703F94
BOOL fn_3_C4F00(Rep1FD8Spawner* spawner) {
    Rep1FD8Particle* p;
    Mtx m;
    Vec offset;
    f32 angle;
    f32 radius;

    fn_80033620(spawner);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    p = spawner->particles;
    do {
        if (p->delay != 0) {
            p->delay -= lbl_80366158._28 == 0;
            if (p->delay == 0) {
                radius = (f32)(15 - rand() % 31) / 10.0f;
                angle = 3.1415927f * (rand() % 361) / 180.0f;
                offset.x = radius * cos(angle);
                offset.z = radius * sin(angle);
                offset.y = 2.5f;
                CTRLBuildMatrix(&spawner->owner->control, m);
                PSMTXMultVec(m, &offset, &p->pos);
            }
        } else if (p->life != 0 && lbl_80366158._28 == 0) {
            if (p->duration == 0) {
                p->color[3] += 15;
                p->_38 += 0.125f;
                p->_3C += 0.125f;
                if (p->_38 >= 2.0f || p->_3C >= 2.0f) {
                    p->duration = 1;
                }
            } else {
                p->color[3] -= 15;
                p->_38 -= 0.125f;
                p->_3C -= 0.125f;
                if (p->_38 <= 0.0f || p->_3C <= 0.0f) {
                    p->life = 0;
                }
            }
        }
        if (p->life == 0) {
            p->_38 = p->_3C = 0.0f;
            p->life = 1;
            p->duration = 0;
            p->delay = 0;
                radius = (f32)(15 - rand() % 31) / 10.0f;
            angle = 3.1415927f * (rand() % 361) / 180.0f;
            offset.x = radius * cos(angle);
            offset.z = radius * sin(angle);
            offset.y = 2.5f;
            CTRLBuildMatrix(&spawner->owner->control, m);
            PSMTXMultVec(m, &offset, &p->pos);
            p->color[3] = 0;
        }
        p = p->next;
    } while (p != NULL);
    return FALSE;
}

// .text:0x000C4CF4 size:0x20C mapped:0x80703D88
void fn_3_C4CF4(Rep1FD8Spawner* spawner, u8 layer) {
    Rep1FD8Particle* p = spawner->particles;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    fn_3_C4B80();
    while (p != NULL) {
        if (p->delay <= 0 && p->life > 0 && layer == p->_50) {
            fn_8003403C(p->_38, p->_3C);
            fn_80033CC8(p, spawner->_10);
        }
        p = p->next;
    }
}

// .text:0x000C4B80 size:0x174 mapped:0x80703C14
void fn_3_C4B80(void) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetCullMode(GX_CULL_NONE);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_RASA, GX_CA_TEXA, GX_CA_ZERO);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetProjection(fn_80052734(fn_8005268C())->proj, GX_PERSPECTIVE);
    GXLoadPosMtxImm(fn_80052734(fn_8005268C())->view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
}

// .text:0x000C48D0 size:0x2B0 mapped:0x80703964
void fn_3_C48D0(Rep1FD8Spawner* spawner, Vec pos) {
    Rep1FD8Particle* p;
    u32 i;
    f32 theta;
    f32 phi;
    f32 speed;

    for (i = 0, p = spawner->particles; p != NULL; p = p->next) {
        p->pos.x = pos.x;
        p->pos.y = pos.y;
        p->pos.z = pos.z;
        theta = 3.1415927f * (rand() % 181) / 180.0f;
        phi = 3.1415927f * (rand() % 360) / 180.0f;
        speed = 0.5f - (rand() % 3) / 10.0f;
        p->vel.x = speed * cos(theta) * cos(phi);
        p->vel.y = -speed * sin(theta);
        p->vel.z = speed * sin(theta) * cos(phi);
        p->_38 = p->_3C = 4.4f;
        p->delay = i / 6;
        p->_4D = 27;
        p->_4E = 0;
        p->color[0] = p->color[1] = p->color[2] = p->color[3] = 255;
        p->life = 1;
        i++;
    }
}

// .text:0x000C4724 size:0x1AC mapped:0x807037B8
BOOL fn_3_C4724(Rep1FD8Spawner* spawner) {
    Rep1FD8Particle* p = spawner->particles;
    u32 i = 0;

    fn_80033620(spawner);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    do {
        if (p->delay != 0) {
            p->delay -= lbl_80366158._28 == 0;
        } else {
            if (p->life == 0) {
                continue;
            }
            fn_8003403C(p->_38, p->_3C);
            fn_80033CC8(p, spawner->_10);
            if (lbl_80366158._28 == 0) {
                p->pos.x += p->vel.x;
                p->pos.y += p->vel.y;
                p->pos.z += p->vel.z;
                p->_38 -= 0.275f;
                p->_3C -= 0.275f;
                p->color[3] -= 15;
                if (p->_38 <= 0.0f || p->_3C <= 0.0f) {
                    p->life = 0;
                }
            }
        }
        i++;
    } while ((p = p->next) != NULL && i < spawner->count);
    spawner->timer -= lbl_80366158._28 == 0;
    if (spawner->timer == 0) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000C444C size:0x2D8 mapped:0x807034E0
void fn_3_C444C(Rep1FD8Spawner* spawner, Rep1FD8Draw* draw) {
    Rep1FD8Particle* p = spawner->particles;
    u32 i;
    f32 x = draw->_9C.x;
    f32 y = draw->_9C.y;
    f32 z = draw->_9C.z;
    f32 theta;
    f32 phi;
    f32 speed;

    for (i = 0; p != NULL; p = p->next) {
        p->pos.x = x;
        p->pos.y = y;
        p->pos.z = z;
        theta = 3.1415927f * (rand() % 360) / 180.0f;
        phi = 3.1415927f * (rand() % 360) / 180.0f;
        speed = 0.5f - (rand() % 3) / 10.0f;
        p->vel.x = speed * cos(theta) * cos(phi);
        p->vel.y = -speed * sin(theta);
        p->vel.z = speed * sin(theta) * cos(phi);
        p->_38 = p->_3C = 4.4f;
        p->delay = i / 6;
        p->_4D = 27;
        p->_4E = 0;
        p->color[0] = p->color[1] = p->color[2] = p->color[3] = 255;
        p->life = 1;
        i++;
    }
}

// .text:0x000C42A4 size:0x1A8 mapped:0x80703338
void fn_3_C42A4(u32* n, s32* count) {
    Mtx m;
    StadiumObject1D58* obj;
    s32 next;
    s32 group;
    s32 i;

    for (group = 0; group < 5; group++) {
        next = lbl_3_common_bss_350E4._40[*n] = lbl_3_common_bss_350E4._40[*n - 1] + lbl_3_common_bss_350E4._3C[*n - 1];
        fn_3_B8574();
        for (i = 0; i < 10; i++) {
            if (group == lbl_3_data_17704[i]._12 && lbl_3_data_17704[i].type != 7) {
                if (lbl_3_common_bss_350E4._00[i + lbl_3_bss_9DE0]._90_6) {
                    lbl_3_common_bss_350E4._44[next] = i + lbl_3_bss_9DE0;
                    next++;
                    lbl_3_common_bss_350E4._3C[*n]++;
                    obj = &lbl_3_common_bss_350E4._00[i + lbl_3_bss_9DE0];
                    CTRLBuildMatrix(&obj->control, m);
                    fn_3_B8464(m, obj->_78);
                    m[1][3] *= -100.0f;
                    fn_3_B8464(m, obj->_78);
                    (*count)++;
                }
            }
        }
        if (lbl_3_common_bss_350E4._3C[*n] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[*n * 2], &lbl_3_common_bss_350E4._48[*n * 2 + 1]);
            (*n)++;
        }
    }
}

// .text:0x000C414C size:0x158 mapped:0x807031E0
void fn_3_C414C(s32 idx) {
    Rep1FD8Draw* draw = &lbl_3_common_bss_350E4.draws[idx];
    Vec pos;
    u8 hit = FALSE;

    CTRLGetTranslation(&draw->control, &pos.x, &pos.y, &pos.z);
    if (g_Ball.AtBat_ContactResult != 2) {
        if (draw->_A9 == 5 && gameInitOptions.starSkillsSetting != 0) {
            fn_3_CB7E8(pos.x, pos.y - 5.0f, pos.z);
            hit = TRUE;
            draw->_A9 = 6;
        } else if (draw->_A9 == 4 && gameInitOptions.starSkillsSetting != 0) {
            fn_3_CB7E8(pos.x, pos.y, pos.z - 5.0f);
            hit = TRUE;
            draw->_A9 = 6;
        }
    }
    if (hit) {
        startBallEffect(6);
    }
}

// .text:0x000C40EC size:0x60 mapped:0x80703180
void fn_3_C40EC(Rep1FD8Draw* draw) {
    Rep1FD8TexRegs* regs = draw->_74->_00->_18[1]->_14->_10->_04;

    if (draw->_A9 != 6) {
        regs->_04 &= ~0x1FFF;
        regs->_04 |= 0x19;
    } else {
        regs->_04 &= ~0x1FFF;
        regs->_04 |= 0x1A;
    }
}

// .text:0x000C4068 size:0x84 mapped:0x807030FC
void fn_3_C4068(Rep1FD8Draw* draw) {
    Rep1FD8TexRegs* regs = draw->_74->_00->_18[1]->_14->_10->_04;
    u16 frame = regs->_04 & 0x1FFF;

    if (lbl_3_bss_9D84++ > 4) {
        frame++;
        if (frame > 19) {
            frame = 4;
        }
        lbl_3_bss_9D84 = 0;
    }
    regs->_04 &= ~0x1FFF;
    regs->_04 |= frame;
}

// .text:0x000C3F70 size:0xF8 mapped:0x80703004
void fn_3_C3F70(Rep1FD8Draw* draw) {
    Rep1FD8Actor* actor = draw->_74->_00;
    Rep1FD8TexMap* map;
    Rep1FD8TexRegs* regs;
    u32 i;
    u32 j;

    if (lbl_3_bss_9D88++ > 4) {
        if (++lbl_3_data_177F0 > 19) {
            lbl_3_data_177F0 = 4;
        }
        lbl_3_bss_9D88 = 0;
    }
    if (lbl_3_bss_9D88 == 0) {
        for (i = 0; i < actor->_06; i++) {
            map = actor->_18[i]->_14;
            if (map != NULL) {
                regs = map->_10->_04;
                for (j = 0; j < map->_10->_08; regs++, j++) {
                    if (regs->_00 == 1) {
                        regs->_04 &= ~0x1FFF;
                        regs->_04 |= lbl_3_data_177F0;
                    }
                }
            }
        }
    }
}

// .text:0x000C3E94 size:0xDC mapped:0x80702F28
void fn_3_C3E94(Vec* pos, s32 i) {
    s16 x;
    s16 y;

    fn_800528C0(pos->x, pos->y, pos->z, &x, &y);
    lbl_80371C30[lbl_3_bss_9E50->_14 + i]._00->_48.x = x;
    lbl_80371C30[lbl_3_bss_9E50->_14 + i]._00->_48.y = y;
    lbl_80371C30[lbl_3_bss_9E50->_14 + i]._00->_48.z = 0.0f;
}

static inline BOOL isSpriteDone(Rep1FD8Task* task, s32 i) {
    return lbl_80371C30[task->_14 + i]._00->_69 == 2 ? TRUE : FALSE;
}

// .text:0x000C3C2C size:0x268 mapped:0x80702CC0
void fn_3_C3C2C(void) {
    Rep1FD8Task* task = lbl_803CC1B8;
    s32 i;

    for (i = 0; i < 8; i++) {
        switch (lbl_3_bss_9E48[i]) {
        case 1:
            fn_3_C3E94(&lbl_3_bss_9DE8[i], i);
            lbl_80371C30[task->_14 + i]._00->_5C = 0;
            lbl_80371C30[task->_14 + i]._00->_54 |= 2;
            lbl_3_bss_9E48[i] = 2;
            break;
        case 2:
            fn_3_C3E94(&lbl_3_bss_9DE8[i], i);
            if (isSpriteDone(task, i)) {
                lbl_80371C30[task->_14 + i]._00->_54 &= ~2;
                lbl_3_bss_9E48[i] = 0;
            }
            break;
        }
    }
    if (lbl_3_bss_9DE7) {
        fn_800B0A14_removeQueue();
        fn_80034CEC(lbl_3_bss_9E50);
        lbl_3_bss_9DE7 = 0;
    }
}

// .text:0x000C3A38 size:0x1F4 mapped:0x80702ACC
void fn_3_C3A38(camera_803c639c_s* camera) {
    Vec shake;
    Mtx inv;

    if (g_GameLogic.gameStatus != 2 || camera == NULL) {
        lbl_3_bss_9D8C = 0;
        lbl_3_bss_9D81 = 0;
        fn_800528B4();
        return;
    }
    if (lbl_3_bss_9D81 != 0) {
        lbl_3_bss_9D8C = 60;
        lbl_3_bss_9D81 = 0;
    }
    if (lbl_3_bss_9D8C != 0) {
        shake.x = (f32)(rand() % 20 - 10) / 17.0f;
        shake.y = (f32)(rand() % 20 - 10) / 17.0f;
        shake.z = 0.0f;
        PSMTXInverse(fn_80052768_getCamera(0)->view, inv);
        PSMTXMultVecSR(inv, &shake, &shake);
        camera->eye.x += shake.x;
        camera->eye.y += shake.y;
        camera->eye.z += shake.z;
        camera->target.x += shake.x;
        camera->target.y += shake.y;
        camera->target.z += shake.z;
        lbl_3_bss_9D8C--;
    }
}

// .text:0x000C39C8 size:0x70 mapped:0x80702A5C
void fn_3_C39C8(void) {
    Rep1FD8Spawner* spawner;
    u32 i;

    for (i = 0; i < 6; i++) {
        spawner = fn_80033A24(fn_3_C30F0, 128, 0, 21, 1, 0);
        if (spawner != NULL) {
            fn_3_C366C(spawner, i);
        }
    }
}

// .text:0x000C366C size:0x35C mapped:0x80702700
void fn_3_C366C(Rep1FD8Spawner* spawner, u8 idx) {
    Rep1FD8Particle* p = spawner->particles;
    s32 i;
    f32 angle;
    s32 life;

    spawner->_10 = lbl_3_bss_9F0C[0];
    spawner->pos = lbl_3_rodata_202C[idx];
    spawner->idx = idx;
    for (i = 0; p != NULL; i++, p = p->next) {
        angle = rand() % 360;
        angle = 0.017453292f * angle;
        p->vel.x = 0.01 * cosf_kludge(angle);
        p->vel.z = 0.01 * sinf_kludge(angle);
        p->vel.y = 0.08f;
        p->delay = i * 4;
        p->grow = 0.5f;
        p->grow += (u32)rand() % 2500 / 1000.0;
        p->_38 = p->grow;
        p->_3C = 2.0 * p->grow;
        p->growScale = rand() % 101 / 100.0;
        p->pos.x = spawner->pos.x;
        p->pos.y = spawner->pos.y;
        p->pos.z = spawner->pos.z;
        p->color[0] = lbl_3_rodata_2028[0];
        p->color[1] = lbl_3_rodata_2028[1];
        p->color[2] = lbl_3_rodata_2028[2];
        p->color[3] = p->alpha = 255.0f;
        life = rand() % 24 + 72;
        p->life = life;
        p->duration = life;
        p->_4D = 29;
        p->_4E = 0;
    }
}

// .text:0x000C30F0 size:0x57C mapped:0x80702184
BOOL fn_3_C30F0(Rep1FD8Spawner* spawner) {
    Rep1FD8Particle* p = spawner->particles;
    Vec pos;

    if (g_GameLogic.gameStatus >= 27 && g_GameLogic.gameStatus <= 33) {
        return FALSE;
    }
    if (g_GameLogic.gameStatus == 2 || g_GameLogic.gameStatus == 1) {
        pos = spawner->pos;
        if (!fn_3_C2AA0(&pos, 4.0f, 4.0f)) {
            return FALSE;
        }
    }
    fn_80033620(spawner);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_CLEAR);
    do {
        if (p->delay <= 0 && p->life != 0) {
            fn_8003403C(p->_38, p->_3C);
            fn_80033CC8(p, spawner->_10);
            if (fn_8005268C() == 0) {
                fn_3_C2EDC(p);
            }
        }
        p->delay -= fn_8005268C() == 0;
        if (p->life == 0) {
            fn_3_C2C80(p, spawner);
        }
        p = p->next;
    } while (p != NULL);
    return FALSE;
}

// .text:0x000C2EDC size:0x214 mapped:0x80701F70
void fn_3_C2EDC(Rep1FD8Particle* p) {
    p->_38 += p->growScale * (3.0 * p->grow / p->duration);
    p->_3C += p->growScale * (2.0 * p->grow / p->duration);
    p->alpha += -255.0f / p->duration;
    if (p->alpha < 0.0f) {
        p->alpha = 0.0f;
    }
    p->color[3] = p->alpha;
    p->color[0] = lbl_3_rodata_2028[0] * (p->color[3] / 255.0);
    p->color[1] = lbl_3_rodata_2028[1] * (p->color[3] / 255.0);
    p->color[2] = lbl_3_rodata_2028[2] * (p->color[3] / 255.0);
    p->pos.x += p->vel.x;
    p->pos.y -= p->vel.y;
    p->pos.z += p->vel.z;
    p->life--;
}

// .text:0x000C2C80 size:0x25C mapped:0x80701D14
void fn_3_C2C80(Rep1FD8Particle* p, Rep1FD8Spawner* spawner) {
    f32 angle = 0.017453292f * (rand() % 360);

    p->vel.x = 0.01 * cosf_kludge(angle);
    p->vel.z = 0.01 * sinf_kludge(angle);
    p->vel.y = 0.08f;
    p->grow = 0.5f;
    p->grow += (u32)rand() % 2500 / 1000.0;
    p->_38 = p->grow;
    p->_3C = 2.0 * p->grow;
    p->growScale = rand() % 101 / 100.0;
    p->duration = p->life = rand() % 24 + 72;
    p->pos.x = spawner->pos.x;
    p->pos.y = spawner->pos.y;
    p->pos.z = spawner->pos.z;
    p->color[0] = lbl_3_rodata_2028[0];
    p->color[1] = lbl_3_rodata_2028[1];
    p->color[2] = lbl_3_rodata_2028[2];
    p->color[3] = p->alpha = 255.0f;
    p->life = p->duration;
    p->delay = 0;
}

// .text:0x000C2AA0 size:0x1E0 mapped:0x80701B34
// 93.77%, as sta_c2's identical fn_3_CD968: the target loads pos->x before pos->y for the
// corners and computes them in other FPRs.
u8 fn_3_C2AA0(Vec* pos, f32 width, f32 height) {
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

// .text:0x000C298C size:0x114 mapped:0x80701A20
void fn_3_C298C(void) {
    Rep1FD8SpawnerTask* task = lbl_803CC1B8;
    u32 i;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        if (g_GameLogic.gameStatus == GAME_STATUS_PAUSED || g_GameLogic.gameStatus >= GAME_STATUS_MINIGAME_POST_MENU) {
            if (g_Minigame._1A40 != 0 && g_Minigame._1A38 == 0) {
                fn_800B0A14_removeQueue();
            }
        }
    } else if (g_GameLogic._128 != 0 || g_d_GameSettings._13 != 0) {
        fn_800B0A14_removeQueue();
    }
    for (i = 0; i < 6; i++) {
        if (task->spawners[i] == NULL || task->spawners[i]->_08 == NULL) {
            task->spawners[i] = fn_80033A24(fn_3_C30F0, 128, 0, 21, 1, 0);
            if (task->spawners[i] != NULL) {
                fn_3_C366C(task->spawners[i], i);
            }
        }
    }
}

// .text:0x000C2974 size:0x18 mapped:0x80701A08
void fn_3_C2974(void) {
    lbl_3_bss_9DE7 = 1;
    lbl_3_bss_9D82 = 1;
}

// .text:0x000C2644 size:0x330 mapped:0x807016D8
void fn_3_C2644(void) {
    Rep1FD8Task* task;

    if (g_d_GameSettings.minigamesEnabled != 0 && g_GameLogic.gameStatus >= 27 && g_GameLogic.gameStatus <= 41) {
        return;
    }
    if (g_GameLogic.gameStatus == 23) {
        lbl_3_bss_9D9C = 1;
    }
    if (lbl_3_bss_9D9C != 0) {
        fn_800B0A14_removeQueue();
        return;
    }
    task = lbl_803CC1B8;
    switch (task->_10 = (task->_10 + 1) % 1800) {
    case 300:
    case 310:
    case 1200:
        task = fn_800B0A5C_insertQueue(fn_3_C24A0, 5);
        task->_10 = 16;
        fn_3_C19C8();
        break;
    }
}

// .text:0x000C24A0 size:0x1A4 mapped:0x80701534
void fn_3_C24A0(void) {
    Vec dir;
    s16 timer;
    u8 alpha;

    ((Rep1FD8Task*)lbl_803CC1B8)->_10--;
    timer = ((Rep1FD8Task*)lbl_803CC1B8)->_10;
    if (timer == 0) {
        fn_800B0A14_removeQueue();
        fn_80023B90(lbl_800F7478[g_d_GameSettings._54].lights, lbl_80367318);
        if (lbl_8036E548._04 != NULL) {
            *(u16*)((u8*)lbl_8036E548._04 + lbl_8036E548._04->tex + 0x60) = 2;
        }
    } else {
        if (timer < 12) {
            alpha = (timer << 7) / 12;
        } else {
            alpha = 128;
        }
        fn_80023B90(&lbl_3_data_177F8, lbl_80367318);
        if (lbl_8036E548._04 != NULL) {
            *(u16*)((u8*)lbl_8036E548._04 + lbl_8036E548._04->tex + 0x60) = 3;
        }
        lbl_803C5090._1D = 11;
        lbl_803C5090._00 = 1.0f;
        lbl_803C5090._14 = 0x1C0;
        lbl_803C5090._17 = alpha;
        lbl_803C5090._19 = lbl_3_data_177F4;
        lbl_803C5090._18 = 1;
    }
    dir.x = -lbl_80367318[0].pos.x;
    dir.y = -lbl_80367318[0].pos.y;
    dir.z = -lbl_80367318[0].pos.z;
    PSVECNormalize(&dir, &dir);
    fn_800BEBCC(0, dir);
}

// .text:0x000C23E0 size:0xC0 mapped:0x80701474
void fn_3_C23E0(void) {
    StadiumObject1D58* obj;
    s32 i;

    fn_800BF058(fn_3_B8184);
    for (i = 0; i < lbl_3_common_bss_350E4._30; i++) {
        obj = &lbl_3_common_bss_350E4._00[i];
        fn_3_B828C(obj);
        if (i >= 1 && i < 11 && obj->_90_7 && obj->_74 != NULL) {
            obj->_74->actor->_98 = obj->_93 | 6;
            fn_800BDF70(obj->_74);
        }
    }
}

// .text:0x000C2310 size:0xD0 mapped:0x807013A4
void fn_3_C2310(StadiumModel1D58* model, Mtx view) {
    Mtx mv;
    Mtx m;
    ModelActor1D58* actor;
    ModelBone1D58* bone;

    CTRLBuildMatrix(&lbl_3_bss_9D94->control, m);
    PSMTXConcat(view, m, mv);
    actor = model->actor;
    bone = actor->drawHead;
    if (actor->skinObject != NULL) {
        if (actor->_7C != NULL) {
            fn_8003A8A0(actor->skinObject, mv, 1);
        } else {
            DOVARenderSkin(actor->skinObject, mv, actor->skinMtxArray, actor->skinInvTransposeMtxArray, 0, NULL);
        }
    }
    while (bone != NULL) {
        if (bone->_014 != NULL) {
            DOSetWorldMatrix(bone->_014, bone->_0EC);
            fn_8003A8A0(bone->_014, mv, 0);
        }
        bone = bone->_100;
    }
}

// .text:0x000C2244 size:0xCC mapped:0x807012D8
void fn_3_C2244(void) {
    Rep1FD8CameraTask* task = lbl_803CC1B8;

    if (lbl_3_bss_9D9C != 0) {
        lbl_3_bss_9D90 = NULL;
        fn_800B0A14_removeQueue();
    } else if (task->_2A != 0) {
        fn_800A7D4C(1, &lbl_3_data_17804[lbl_803CBBC0]);
        PSMTXCopy(fn_80052768_getCamera(0)->view, lbl_3_data_17804[lbl_803CBBC0].view);
        lbl_3_data_17804[lbl_803CBBC0].task = task;
    }
}

// .text:0x000C1C18 size:0x62C mapped:0x80700CAC
// 95.95%: register allocation differs from the second quad loop on (target: size reuses
// f26, dx/dy in f28/f27, color in r27 and i in r25; base one register off each).
void fn_3_C1C18(Rep1FD8CameraSlot* slot) {
    Vec pos;
    Mtx m = {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
    };
    Rep1FD8CameraTask* task = slot->task;
    s32 i;
    u32 color;
    f32 halfWidth;
    f32 height;
    f32 size;
    f32 dx;
    f32 dy;

    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetCullMode(GX_CULL_NONE);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_CLEAR);
    GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    for (i = 0; i <= 2; i++) {
        SetDisplayStateTexture(lbl_3_bss_9D98 + i * 0x20, i, i);
    }
    color = (s32)(task->_2A * lbl_3_data_1787C) | 0xFFFFFF00;
    PSMTXMultVec(slot->view, &task->_14, &pos);
    halfWidth = 512.0f * ((100.0f + task->_24) / 100.0f) * -pos.z / 1280.0f / 2.0f;
    height = 256.0f * ((100.0f + task->_24) / 100.0f) * -pos.z / 1280.0f;
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(pos.x - halfWidth, pos.y - 0.25f * height, pos.z);
    GXColor1u32(color);
    GXTexCoord2u16(0, 0);
    GXPosition3f32(pos.x - halfWidth, pos.y + 0.75f * height, pos.z);
    GXColor1u32(color);
    GXTexCoord2u16(0, 1);
    GXPosition3f32(pos.x + halfWidth, pos.y + 0.75f * height, pos.z);
    GXColor1u32(color);
    GXTexCoord2u16(1, 1);
    GXPosition3f32(pos.x + halfWidth, pos.y - 0.25f * height, pos.z);
    GXColor1u32(color);
    GXTexCoord2u16(1, 0);
    GXEnd();
    size = 256.0f * -pos.z / 1280.0f;
    color = task->_2A | 0xFFFFFF00;
    for (i = task->_29; i < 2; i++) {
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, task->_27[i], GX_COLOR0A0);
        SetDisplayStateTexture(lbl_3_bss_9D98 + (task->_27[i] << 5), 0, 0);
        dx = (100.0f + task->_25[i]) / 100.0f * size * cos(0.0000958738f * task->_20[i]);
        dy = (100.0f + task->_25[i]) / 100.0f * size * sin(0.0000958738f * task->_20[i]);
        GXBegin(GX_QUADS, GX_VTXFMT0, 4);
        GXPosition3f32(pos.x, pos.y, pos.z);
        GXColor1u32(color);
        GXTexCoord2u16(0, 0);
        GXPosition3f32(pos.x - dy, pos.y + dx, pos.z);
        GXColor1u32(color);
        GXTexCoord2u16(0, 1);
        GXPosition3f32(pos.x + dx - dy, pos.y + dx + dy, pos.z);
        GXColor1u32(color);
        GXTexCoord2u16(1, 1);
        GXPosition3f32(pos.x + dx, pos.y + dy, pos.z);
        GXColor1u32(color);
        GXTexCoord2u16(1, 0);
        GXEnd();
        pos.x += (dx - dy) * 0.5f;
        pos.y += (dx + dy) * 0.5f;
    }
    task->_29 -= task->_29 != 0;
    i = task->_2A - (task->_29 == 0) * 42;
    task->_2A = i * (i > 0);
}

// .text:0x000C19C8 size:0x250 mapped:0x80700A5C
void fn_3_C19C8(void) {
    s32 i;

    if (lbl_3_bss_9D90 == NULL) {
        lbl_3_bss_9D90 = (Rep1FD8CameraTask*)fn_800B0A5C_insertQueue(fn_3_C2244, 5);
    }
    if (((Rep1FD8Task*)lbl_803CC1B8)->_10 != 0x136) {
        fn_3_B7FC8(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 6, 8);
    }
    lbl_3_bss_9D90->_2A = 0xFF;
    lbl_3_bss_9D90->_29 = 2;
    i = rand() % 3;
    lbl_3_bss_9D90->_14.x = lbl_3_data_17880[i][0];
    lbl_3_bss_9D90->_14.y = lbl_3_data_17880[i][1];
    lbl_3_bss_9D90->_14.z = lbl_3_data_17880[i][2];
    lbl_3_bss_9D90->_24 = 10 - rand() % 20;
    i = 2;
    while (i-- != 0) {
        lbl_3_bss_9D90->_20[i] = rand() * (((0x1FFF - rand() * 0x3FFF / 32767) >> (1 - i)) + 0x1FFF) / 32767;
        lbl_3_bss_9D90->_25[i] = lbl_3_bss_9D90->_24 + 2 - rand() % 2;
        lbl_3_bss_9D90->_27[i] = rand() % 2 + 1;
    }
}

// .text:0x000C1974 size:0x54 mapped:0x80700A08
void fn_3_C1974(u8* stadium) {
    Rep1FD8Task* task = fn_800B0A5C_insertQueue(fn_3_C2644, 4);

    task->_10 = 0;
    lbl_3_bss_9D98 = stadium + 0x3C4;
    lbl_3_bss_9D9C = 0;
}

// .text:0x000C1964 size:0x10 mapped:0x807009F8
void fn_3_C1964(void) {
    lbl_3_bss_9D9C = 1;
}
