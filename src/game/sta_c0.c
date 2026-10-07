#include "game/sta_c0.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "Dolphin/rand.h"
#include "C3/control.h"
#include "game/rep_D0.h"
#include "game/m_sound.h"
#include "game/rep_1D58.h"
#include "math.h"
#include "string.h"

typedef struct {
    /* 0x00 */ void* _00;
} StaC0Model;

typedef struct StaC0Obj {
    /* 0x00 */ Control control;
    /* 0x3C */ u8 _3C[0x74 - 0x3C];
    /* 0x74 */ StaC0Model* _74;
    /* 0x78 */ void* _78;
    /* 0x7C */ void (*_7C)(struct StaC0Obj* obj);
    /* 0x80 */ void* _80;
    /* 0x84 */ void (*_84)(void);
    /* 0x88 */ u8 _88[0x8C - 0x88];
    /* 0x8C */ void* _8C;
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
    /* 0x99 */ u8 _99[0xA0 - 0x99];
} StaC0Obj; // size: 0xA0

typedef struct StaC0Draw {
    /* 0x00 */ StaC0Obj obj;
    /* 0xA0 */ u8 _A0;
    /* 0xA1 */ u8 _A1;
    /* 0xA2 */ u8 _A2;
    /* 0xA3 */ u8 _A3;
    /* 0xA4 */ u32 _A4;
    /* 0xA8 */ u8 _A8[0xE8 - 0xA8];
} StaC0Draw; // size: 0xE8

typedef struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ u8 _04[0x5C - 0x4];
} StaC0Anim; // size: 0x5C

typedef struct {
    /* 0x00 */ u8 _00[0x1C];
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u8 _1E[0x20 - 0x1E];
} StaC0Material; // size: 0x20

typedef struct {
    /* 0x00 */ u8 id;
    /* 0x01 */ u8 value[2];
} StaC0MaterialSwap; // size: 0x3

typedef struct {
    /* 0x00 */ StaC0MaterialSwap _00[2][2][2];
    /* 0x18 */ StaC0Material* _18;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ u8 _20;
} StaC0Swaps;

typedef struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ void* _04;
    /* 0x08 */ void* _08;
    /* 0x0C */ void* _0C;
    /* 0x10 */ u8* _10;
    /* 0x14 */ u16 _14;
    /* 0x16 */ u16 _16;
    /* 0x18 */ u16 _18;
} StaC0Tiles; // size: 0x1C

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec scale;
    /* 0x18 */ f32 rotY;
    /* 0x1C */ u8 type;
    /* 0x1D */ u8 _1D[3];
} StaC0Prop; // size: 0x20

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ StaC0Model _34;
    /* 0x38 */ u8 _38[0x90 - 0x38];
} StaC0Actor; // size: 0x90

extern struct {
    /* 0x00 */ StaC0Draw* _00;
    /* 0x04 */ u8* _04;
    /* 0x08 */ StaC0Tiles* _08;
    /* 0x0C */ StaC0Tiles* _0C;
    /* 0x10 */ StaC0Swaps* _10;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ void (*_18)(void);
    /* 0x1C */ void (*_1C)(void);
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32* _34;
    /* 0x38 */ u8 _38[0x48 - 0x38];
    /* 0x48 */ s32 _48;
    /* 0x4C */ u8 _4C[0x6D - 0x4C];
    /* 0x6D */ u8 _6D;
} lbl_3_common_bss_350E4;

extern struct {
    /* 0x00 */ u8 _00[0x6C];
    /* 0x6C */ StaC0Actor* _6C;
} lbl_8036E548;

extern u8 lbl_3_data_10F7C[8];
extern u8 lbl_3_data_10F84[4];
extern u8 lbl_3_data_10F88[0x80];
extern u8 lbl_3_data_11008[0x40];
extern u8 lbl_3_data_11048[0x20][3];
extern u8 lbl_3_data_11108[0x10][3];

StaC0Prop lbl_3_data_17B98[11] = {
    { { 24.4f, 0.0f, 117.2f }, { 1.0f, 1.0f, 1.0f }, -16.0f, 2, { 1 } },
    { { 5.549f, 0.0f, 111.0f }, { 1.0f, 1.0f, 1.0f }, 0.0f, 2, { 1 } },
    { { -22.0f, 0.0f, 109.8f }, { 0.9f, 0.9f, 0.9f }, 32.0f, 2, { 1 } },
    { { 98.0f, 0.0f, 73.0f }, { 1.0f, 1.0f, 1.0f }, 75.0f, 2, { 1 } },
    { { -112.0f, 0.0f, 66.0f }, { 1.0f, 1.0f, 1.0f }, -25.0f, 2, { 1 } },
    { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 4 },
};
u8 lbl_3_data_17CF8[9] = { 1, 2, 4, 4, 4, 4, 2, 8, 9 };

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern StaC0Actor* ActorObjectInitTable(u16 count);
extern void fn_800BDC88(StaC0Actor* actors, u16 first, u16 last, void* model, void* anim, s32 arg5);
extern void fn_800BD548(void* model, s32 count, ...);
extern void fn_80025C58(void* anim, void* model);
extern void fn_80025DDC(void* anim);
extern void fn_80025FFC(void* anim, StaC0Anim* state);
extern void fn_80025EEC(StaC0Anim* state, s32, s32);
extern void fn_3_35E4(void (*callback)(void));
extern void fn_3_16E338(u16* arg0, s32 arg1);

extern void AnimateActorBones(void* bones);
extern s32 fn_8005268C(void);
extern camera_803c639c_s* fn_80052734(s32 idx);
extern s32 fn_800247E4(s32 x, s32 y, s32 width, s32 bytes);


extern u16 lbl_3_data_81DC[16];

// MWCC lays out .bss statics in reverse order of declaration
static u8 lbl_3_bss_9FCC[0x10];
static StaC0Anim lbl_3_bss_9F70;
static u8 lbl_3_bss_9F6C;
static GXTexObj lbl_3_bss_9F4C;
static u8* lbl_3_bss_9F48;
static s32 lbl_3_bss_9F44;
static s32 lbl_3_bss_9F40;
static u32 lbl_3_bss_9F3C;
static s32 lbl_3_bss_9F38;

// .text:0x000C9DB4 size:0xE00 mapped:0x80708E48
void fn_3_C9DB4(void** files) {
    StaC0Draw* draw;
    StaC0Draw* entry;
    StaC0Swaps* swaps;
    StaC0Tiles* tiles;
    StaC0Prop* prop;
    s32* indices;
    u32 size;
    s32 i;
    u32 n;
    s32 count;
    u8 end;
    s32 j;

    end = FALSE;
    lbl_3_common_bss_350E4._18 = fn_3_B939C;
    lbl_3_common_bss_350E4._1C = fn_3_C9744;
    lbl_3_bss_9F6C = 1;
    indices = lbl_3_common_bss_350E4._34 = _OSAllocFromHeap(4, 9 * sizeof(s32));
    fn_3_B9D68(lbl_3_data_17CF8, 9, files, indices);
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES && g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
        fn_3_16E338(files[0], 11);
    }

    prop = lbl_3_data_17B98;
    for (n = 0; n < 10; n++, prop++) {
        if (prop->type == 4) {
            break;
        }
    }
    lbl_3_common_bss_350E4._6D = n + 3;
    lbl_8036E548._6C = ActorObjectInitTable(n + 3);
    j = 0;
    fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[1]], NULL, 0);
    j++;
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[4]], files[indices[4] + 2], 0);
        fn_3_B97DC(&lbl_8036E548._6C[j]._34, files[indices[4] + 2]);
    } else {
        fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[2]], files[indices[2] + 2], 0);
        fn_3_B97DC(&lbl_8036E548._6C[j]._34, files[indices[2] + 2]);
    }
    j++;
    for (i = 0; i < n; j++, i++) {
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
            fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[5]], files[indices[5] + 2], 0);
            fn_3_B97DC(&lbl_8036E548._6C[j]._34, files[indices[5] + 2]);
        } else {
            fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[3]], files[indices[3] + 2], 0);
            fn_3_B97DC(&lbl_8036E548._6C[j]._34, files[indices[3] + 2]);
        }
    }
    fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[6]], NULL, 0);
    for (i = 0; i < lbl_3_common_bss_350E4._6D; i++) {
        fn_800BD548(&lbl_8036E548._6C[i]._34, 4, lbl_3_common_bss_350E4._20, lbl_3_common_bss_350E4._24,
                    lbl_3_common_bss_350E4._28, lbl_3_common_bss_350E4._2C);
    }
    if (files[indices[7]] != NULL) {
        fn_80025DDC(files[indices[7]]);
        fn_80025C58(files[indices[7]], &lbl_8036E548._6C->_34);
        lbl_3_bss_9F70._00 = files[indices[8]];
        fn_80025FFC(files[indices[7]], &lbl_3_bss_9F70);
        fn_80025EEC(&lbl_3_bss_9F70, 0, 0);
    }

    size = (20 * sizeof(StaC0Draw)) + (g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE ? 0xEC : 0);
    lbl_3_common_bss_350E4._30 = 20;
    lbl_3_common_bss_350E4._00 = _OSAllocFromHeap(0x20, size);
    memset(lbl_3_common_bss_350E4._00, 0, size);
    lbl_3_common_bss_350E4._04 = _OSAllocFromHeap(0x20, size);
    memset(lbl_3_common_bss_350E4._04, 0, size);
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
        lbl_3_common_bss_350E4._08 = (StaC0Tiles*)(lbl_3_common_bss_350E4._04 + 20 * sizeof(StaC0Draw));
        lbl_3_common_bss_350E4._0C = lbl_3_common_bss_350E4._08 + 1;
        lbl_3_common_bss_350E4._08->_10 = (u8*)(lbl_3_common_bss_350E4._0C + 1);
        lbl_3_common_bss_350E4._0C->_10 = lbl_3_common_bss_350E4._08->_10 + 0x60;
        lbl_3_common_bss_350E4._10 = (StaC0Swaps*)(lbl_3_common_bss_350E4._0C->_10 + 0x30);
    } else {
        lbl_3_common_bss_350E4._08 = NULL;
        lbl_3_common_bss_350E4._0C = NULL;
        lbl_3_common_bss_350E4._10 = NULL;
    }

    draw = lbl_3_common_bss_350E4._00;
    draw->_A1 = 1;
    draw->_A2 = 1;
    draw->obj._74 = &lbl_8036E548._6C[1]._34;
    draw->obj._78 = NULL;
    draw->obj._7C = fn_3_C9A60;
    draw->obj._80 = NULL;
    draw->obj._90_7 = 1;
    draw->obj._90_6 = draw->obj._90_7 && draw->obj._78 != NULL;
    draw->obj.control.type = 0;
    CTRLSetTranslation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
    CTRLSetRotation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
    draw->obj._90_5 = 1;
    draw->obj._92 = 0xFF;
    draw->obj._8C = NULL;
    draw->obj._84 = NULL;
    draw->obj._94 = 0;
    draw->obj._96 = -1;
    draw->obj._98 = 1;
    draw++;

    draw->_A1 = 0;
    draw->_A2 = 0;
    draw->obj._74 = &lbl_8036E548._6C->_34;
    draw->obj._78 = NULL;
    draw->obj._7C = fn_3_C9B5C;
    draw->obj._80 = NULL;
    draw->obj._90_7 = 1;
    draw->obj._90_6 = draw->obj._90_7 && draw->obj._78 != NULL;
    draw->obj.control.type = 0;
    CTRLSetTranslation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
    CTRLSetRotation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
    draw->obj._90_5 = 1;
    draw->obj._92 = 0xFF;
    draw->obj._8C = &lbl_3_bss_9F70;
    draw->obj._84 = fn_3_C9AC8;
    draw->obj._94 = 0;
    draw->obj._96 = -1;
    draw->obj._98 = 1;
    draw++;

    // Each entry's kind fields go through entry, retaken after every advance of draw;
    // writing them through draw drops the copies of r28 into r4 that the target has
    count = 2;
    entry = draw;
    for (i = 0; i < 10; i++) {
        if (lbl_3_data_17B98[i].type == 4) {
            end = TRUE;
        }
        if (end) {
            for (; i < 10; i++) {
                lbl_3_data_17B98[i].type = 4;
            }
            break;
        }
        entry->_A1 = 2;
        entry->_A2 = 2;
        entry->_A4 = i * 100;
        draw->obj._74 = &lbl_8036E548._6C[i + 2]._34;
        draw->obj._78 = NULL;
        draw->obj._7C = fn_3_C99F8;
        draw->obj._80 = NULL;
        draw->obj._90_7 = 1;
        draw->obj._90_6 = draw->obj._90_7 && draw->obj._78 != NULL;
        draw->obj.control.type = 0;
        CTRLSetScale(&draw->obj.control, lbl_3_data_17B98[i].scale.x, lbl_3_data_17B98[i].scale.y,
                     lbl_3_data_17B98[i].scale.z);
        CTRLSetTranslation(&draw->obj.control, lbl_3_data_17B98[i].pos.x, lbl_3_data_17B98[i].pos.y,
                           lbl_3_data_17B98[i].pos.z);
        CTRLSetRotation(&draw->obj.control, 0.0f, lbl_3_data_17B98[i].rotY, 0.0f);
        draw->obj._90_5 = 0;
        draw->obj._92 = 0xFF;
        draw->obj._8C = NULL;
        draw->obj._84 = NULL;
        draw->obj._94 = 0;
        draw->obj._96 = -1;
        draw->obj._98 = 1;
        entry = ++draw;
        count++;
    }

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES) {
        entry->_A1 = 3;
        draw->obj._74 = &lbl_8036E548._6C[j]._34;
        draw->obj._78 = NULL;
        draw->obj._7C = NULL;
        draw->obj._80 = NULL;
        draw->obj._90_7 = 1;
        draw->obj._90_6 = draw->obj._90_7 && draw->obj._78 != NULL;
        draw->obj.control.type = 0;
        CTRLSetTranslation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
        draw->obj._90_5 = 0;
        draw->obj._92 = 0xFF;
        draw->obj._8C = NULL;
        draw->obj._84 = NULL;
        draw->obj._94 = 0;
        draw->obj._96 = -1;
        draw->obj._98 = 1;
        entry = ++draw;
        count++;
    }

    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
        lbl_3_common_bss_350E4._08->_0C = lbl_3_data_10F7C;
        lbl_3_common_bss_350E4._08->_08 = lbl_3_data_10F88;
        lbl_3_common_bss_350E4._08->_00 = (u8*)g_UNK_StadiumDetails._00 + 0x60;
        lbl_3_common_bss_350E4._08->_04 = (u8*)g_UNK_StadiumDetails._00 + 0x40;
        lbl_3_common_bss_350E4._08->_14 = 0x20;
        lbl_3_common_bss_350E4._08->_18 = 6;
        lbl_3_common_bss_350E4._08->_16 = 5;
        for (i = 0; i < 0x20; i++) {
            lbl_3_common_bss_350E4._08->_10[i * 3] = lbl_3_data_11048[i][0];
            if (lbl_3_data_11048[i][1] < 6) {
                lbl_3_common_bss_350E4._08->_10[i * 3 + 1] = lbl_3_data_11048[i][1];
            } else {
                lbl_3_common_bss_350E4._08->_10[i * 3 + 1] = rand() % 6;
            }
            if (lbl_3_data_11048[i][2] < 5) {
                lbl_3_common_bss_350E4._08->_10[i * 3 + 2] = lbl_3_data_11048[i][2];
            } else {
                tiles = lbl_3_common_bss_350E4._08;
                tiles->_10[i * 3 + 2] = rand() % tiles->_16;
            }
        }

        lbl_3_common_bss_350E4._0C->_0C = lbl_3_data_10F84;
        lbl_3_common_bss_350E4._0C->_08 = lbl_3_data_11008;
        lbl_3_common_bss_350E4._0C->_00 = (u8*)g_UNK_StadiumDetails._00 + 0xA0;
        lbl_3_common_bss_350E4._0C->_04 = (u8*)g_UNK_StadiumDetails._00 + 0x80;
        lbl_3_common_bss_350E4._0C->_14 = 0x10;
        lbl_3_common_bss_350E4._0C->_18 = 2;
        lbl_3_common_bss_350E4._0C->_16 = 8;
        for (i = 0; i < 0x10; i++) {
            lbl_3_common_bss_350E4._0C->_10[i * 3] = lbl_3_data_11108[i][0];
            if (lbl_3_data_11108[i][1] < 2) {
                lbl_3_common_bss_350E4._0C->_10[i * 3 + 1] = lbl_3_data_11108[i][1];
            } else {
                lbl_3_common_bss_350E4._0C->_10[i * 3 + 1] = rand() % 6;
            }
            if (lbl_3_data_11108[i][2] < 8) {
                lbl_3_common_bss_350E4._0C->_10[i * 3 + 2] = lbl_3_data_11108[i][2];
            } else {
                tiles = lbl_3_common_bss_350E4._0C;
                tiles->_10[i * 3 + 2] = rand() % tiles->_16;
            }
        }

        fn_3_35E4(fn_3_C9878);
        swaps = lbl_3_common_bss_350E4._10;
        swaps->_18 = g_UNK_StadiumDetails._00;
        swaps->_20 = 2;
        swaps->_1C = cos(1.3962634801864624);
        entry = ++draw;
        swaps->_00[0][0][0].id = 8;
        swaps->_00[0][0][0].value[0] = 2;
        swaps->_00[0][0][0].value[1] = 7;
        swaps->_00[0][0][1].id = 4;
        swaps->_00[0][0][1].value[0] = 7;
        swaps->_00[0][0][1].value[1] = 4;
        swaps->_00[0][1][0].id = 9;
        swaps->_00[0][1][0].value[0] = 2;
        swaps->_00[0][1][0].value[1] = 7;
        swaps->_00[0][1][1].id = 10;
        swaps->_00[0][1][1].value[0] = 7;
        swaps->_00[0][1][1].value[1] = 4;
        swaps->_00[1][0][0].id = 8;
        swaps->_00[1][0][0].value[0] = 2;
        swaps->_00[1][0][0].value[1] = 7;
        swaps->_00[1][0][1].id = 4;
        swaps->_00[1][0][1].value[0] = 7;
        swaps->_00[1][0][1].value[1] = 4;
        swaps->_00[1][1][0].id = 9;
        swaps->_00[1][1][0].value[0] = 2;
        swaps->_00[1][1][0].value[1] = 7;
        swaps->_00[1][1][1].id = 10;
        swaps->_00[1][1][1].value[0] = 7;
        swaps->_00[1][1][1].value[1] = 4;
    }

    if (lbl_3_common_bss_350E4._30 > count) {
        for (i = count; i < lbl_3_common_bss_350E4._30; i++) {
            entry->_A1 = 0;
            entry->_A2 = 0;
            draw->obj._74 = NULL;
            draw->obj._78 = NULL;
            draw->obj._7C = NULL;
            draw->obj._80 = NULL;
            draw->obj._90_7 = 0;
            draw->obj._90_6 = 0;
            draw->obj._90_5 = 0;
            draw->obj.control.type = 0;
            CTRLSetTranslation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
            CTRLSetRotation(&draw->obj.control, 0.0f, 0.0f, 0.0f);
            draw->obj._92 = 0;
            draw->obj._8C = NULL;
            draw->obj._94 = 0;
            draw->obj._96 = -1;
            entry = ++draw;
        }
    }

    lbl_3_common_bss_350E4._48 = 0;
    fn_3_C9C94();
}

// .text:0x000C9C94 size:0x120 mapped:0x80708D28
void fn_3_C9C94(void) {
    Mtx23 mtx;
    u32 x;
    u32 y;
    s32 offset;

    mtx[0][0] = 0.5f;
    mtx[0][1] = 0.0f;
    mtx[0][2] = 0.0f;
    mtx[1][0] = 0.0f;
    mtx[1][1] = 0.0f;
    mtx[1][2] = 0.0f;
    GXSetIndTexMtx(GX_ITM_0, mtx, 2);
    lbl_3_bss_9F48 = fn_3_B9534(0x80, 0x40, &lbl_3_bss_9F4C);
    if (lbl_3_bss_9F48 == NULL) {
        OSErrorLine(671, "error\n");
    }
    for (y = 0; y < 0x40; y++) {
        for (x = 0; x < 0x80; x++) {
            offset = fn_800247E4(x, y, 0x80, 2);
            lbl_3_bss_9F48[offset] = (u8)(rand() % 4) + 0x7E;
        }
    }
}

// .text:0x000C9B5C size:0x138 mapped:0x80708BF0
void fn_3_C9B5C(StaC0Obj* obj) {
    u32 x;
    u32 y;
    s8 prev;
    s8 next;
    s32 offset;

    if (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT || g_GameLogic.gameStatus == GAME_STATUS_DEFAULT) {
        obj->_90_7 = 0;
        return;
    }
    obj->_90_7 = 1;
    if (lbl_3_bss_9F3C < 3) {
        lbl_3_bss_9F3C++;
        return;
    }
    for (x = 0; x < 0x80; x++) {
        for (y = 0; y < 0x40; y++) {
            if (y == 0) {
                offset = fn_800247E4(x, 0x3F, 0x80, 2);
                prev = lbl_3_bss_9F48[offset];
            }
            offset = fn_800247E4(x, y, 0x80, 2);
            next = lbl_3_bss_9F48[offset];
            lbl_3_bss_9F48[offset] = prev;
            prev = next;
        }
    }
    lbl_3_bss_9F3C = 0;
    DCFlushRange(lbl_3_bss_9F48, 0x4000);
}

// .text:0x000C9AC8 size:0x94 mapped:0x80708B5C
void fn_3_C9AC8(void) {
    fn_3_B9510(0);
    fn_3_B9510(1);
    GXLoadTexObj(&lbl_3_bss_9F4C, GX_TEXMAP7);
    GXSetIndTexOrder(GX_IND_TEX_STAGE_0, GX_TEXCOORD0, GX_TEXMAP7);
    GXSetNumIndStages(1);
    GXSetIndTexCoordScale(GX_IND_TEX_STAGE_0, GX_ITS_1, GX_ITS_1);
    GXSetTevIndWarp(GX_TEVSTAGE0, GX_IND_TEX_STAGE_0, GX_FALSE, GX_FALSE, GX_ITM_0);
    GXSetTevIndWarp(GX_TEVSTAGE1, GX_IND_TEX_STAGE_0, GX_FALSE, GX_FALSE, GX_ITM_0);
}

// .text:0x000C9A60 size:0x68 mapped:0x80708AF4
void fn_3_C9A60(StaC0Obj* obj) {
    if (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT || g_GameLogic.gameStatus == GAME_STATUS_DEFAULT) {
        obj->_90_7 = 0;
    } else {
        obj->_90_7 = 1;
        AnimateActorBones(obj->_74->_00);
    }
}

// .text:0x000C99F8 size:0x68 mapped:0x80708A8C
void fn_3_C99F8(StaC0Obj* obj) {
    if (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT || g_GameLogic.gameStatus == GAME_STATUS_DEFAULT) {
        obj->_90_7 = 0;
    } else {
        obj->_90_7 = 1;
        AnimateActorBones(obj->_74->_00);
    }
}

// .text:0x000C9878 size:0x180 mapped:0x8070890C
void fn_3_C9878(void) {
    StaC0Swaps* swaps = lbl_3_common_bss_350E4._10;
    Vec dir;
    Vec up = { 0.0f, 0.0f, 1.0f };
    camera_803c639c_s* camera;
    s32 cam;
    f32 limit;
    u8 flag;
    s32 i;

    if (swaps == NULL) {
        return;
    }
    GXSetZCompLoc(GX_FALSE);
    cam = fn_8005268C();
    switch (g_GameLogic.gameStatus) {
    default:
        if (g_Stats.replayInd == 0) {
            camera = fn_80052734(cam);
            PSVECSubtract(&camera->target, &camera->eye, &dir);
            dir.y = 0.0f;
            limit = swaps->_1C * PSVECMag(&dir);
            flag = PSVECDotProduct(&dir, &up) > limit;
            break;
        }
    case GAME_STATUS_INNING_TRANSITION:
    case GAME_STATUS_PAUSED:
    case GAME_STATUS_HOMERUN_END:
    case GAME_STATUS_HOMERUN_LAP:
    case GAME_STATUS_BATTER_CELEBRATION:
    case GAME_STATUS_STAR_CHANCE_VS:
    case GAME_STATUS_CHAMPIONSHIP:
        flag = FALSE;
        break;
    }
    for (i = 0; i < swaps->_20; i++) {
        swaps->_18[swaps->_00[cam][i][0].id]._1C = swaps->_00[cam][i][0].value[flag];
        swaps->_18[swaps->_00[cam][i][1].id]._1C = swaps->_00[cam][i][1].value[flag];
    }
}

// .text:0x000C9744 size:0x134 mapped:0x807087D8
void fn_3_C9744(void) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        return;
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_MINIGAME_READY) {
        return;
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_PAUSED) {
        if (lbl_3_bss_9F6C == 0) {
            fn_3_8B890(lbl_3_bss_9F40);
            if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
                fn_3_8B890(lbl_3_bss_9F44);
            }
            lbl_3_bss_9F6C = 1;
        }
    } else if (lbl_3_bss_9F6C != 0) {
        lbl_3_bss_9F40 = fn_3_8BBC4(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 1, NULL, NULL, 1);
        if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
            lbl_3_bss_9F44 = fn_3_B7FC8(lbl_3_data_81DC[g_d_GameSettings.StadiumID], 0);
        }
        lbl_3_bss_9F6C = 0;
    } else {
        fn_3_8BA60(lbl_3_bss_9F40, NULL, NULL);
        if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
            fn_3_8BA60(lbl_3_bss_9F44, NULL, NULL);
        }
    }
}
