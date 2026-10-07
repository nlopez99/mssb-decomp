#include "game/sta_c6.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "C3/control.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/os.h"
#include "Dolphin/rand.h"
#include "musyx/musyx.h"
#include "string.h"

typedef struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ u8 _04[0x06 - 0x04];
    /* 0x06 */ u8 format;
} StaC6Tex;

typedef struct {
    /* 0x00 */ u8 _00[0xA0];
    /* 0xA0 */ u16 _A0;
} StaC6Tev;

typedef struct {
    /* 0x00 */ u8 _00[0x0C];
    /* 0x0C */ StaC6Tev* _0C;
} StaC6DispState;

typedef struct {
    /* 0x00 */ u8 _00[0x20];
    /* 0x20 */ u8 _20;
} StaC6DispInfo;

typedef struct {
    /* 0x00 */ u8 _00[0x04];
    /* 0x04 */ StaC6DispInfo* _04;
} StaC6DispHeader;

typedef struct StaC6Shape {
    /* 0x00 */ u8 _00[0x04];
    /* 0x04 */ StaC6Tex* _04;
    /* 0x08 */ StaC6DispState* _08;
    /* 0x0C */ u8 _0C[0x10 - 0x0C];
    /* 0x10 */ StaC6DispHeader* _10;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ Mtx _18;
} StaC6Shape;

typedef struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ StaC6Shape* _14;
    /* 0x18 */ StaC6Shape* _18;
    /* 0x1C */ Control control;
    /* 0x58 */ u8 _58[0xEC - 0x58];
    /* 0xEC */ MtxPtr _EC;
} StaC6Bone;

typedef struct {
    /* 0x00 */ u8 _00[0x06];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0x18 - 0x08];
    /* 0x18 */ StaC6Bone** _18;
    /* 0x1C */ u8 _1C[0x98 - 0x1C];
    /* 0x98 */ u8 _98;
} StaC6Actor;

typedef struct {
    /* 0x00 */ StaC6Actor* _00;
    /* 0x04 */ u8 _04[0x10 - 0x04];
    /* 0x10 */ u8 _10[0x44];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A[0x5C - 0x5A];
    /* 0x5C */ f32 _5C;
    /* 0x60 */ u8 _60[0x90 - 0x60];
} StaC6Model; // size: 0x90

typedef struct {
    /* 0x00 */ u16 count;
    /* 0x04 */ Mtx _04;
    /* 0x34 */ StaC6Model models[1];
} StaC6ModelTable;

typedef struct StaC6Draw {
    /* 0x00 */ Control control;
    /* 0x3C */ u8 _3C[0x74 - 0x3C];
    /* 0x74 */ StaC6Model* _74;
    /* 0x78 */ void* _78;
    /* 0x7C */ void (*_7C)(void* arg);
    /* 0x80 */ void (*_80)(s32 idx);
    /* 0x84 */ void (*_84)(void* arg);
    /* 0x88 */ void (*_88)(void* arg);
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
    /* 0x99 */ u8 _99[0x9C - 0x99];
    /* 0x9C */ StaC6Model* _9C;
    /* 0xA0 */ u32 _A0;
    /* 0xA4 */ GXColor color;
    /* 0xA8 */ GXColor* from;
    /* 0xAC */ GXColor* to;
    /* 0xB0 */ GXColor* _B0;
    /* 0xB4 */ GXColor* _B4;
    /* 0xB8 */ GXColor* _B8;
    /* 0xBC */ GXColor* _BC;
    /* 0xC0 */ u8 _C0;
    /* 0xC1 */ u8 type;
    /* 0xC2 */ u8 _C2;
    /* 0xC3 */ u8 _C3;
    /* 0xC4 */ u8 _C4;
    /* 0xC5 */ u8 _C5[0xE8 - 0xC5];
} StaC6Draw; // size: 0xE8

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ u8 type;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} StaC6Prop; // size: 0x14

typedef struct {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 _01;
    /* 0x02 */ u8 _02;
    /* 0x03 */ u8 _03;
} StaC6Slot; // size: 0x4

typedef struct StaC6Sort {
    /* 0x00 */ f32 depth;
    /* 0x04 */ s32 idx;
} StaC6Sort; // size: 0x8

extern struct {
    /* 0x00 */ StaC6Draw* _00;
    /* 0x04 */ StaC6Draw* _04;
    /* 0x08 */ u8 _08[0x18 - 0x08];
    /* 0x18 */ void (*_18)(void);
    /* 0x1C */ u8 _1C[0x20 - 0x1C];
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ u32 _30;
    /* 0x34 */ s32* _34;
    /* 0x38 */ void** _38;
    /* 0x3C */ u32* _3C;
    /* 0x40 */ u16* _40;
    /* 0x44 */ u32* _44;
    /* 0x48 */ Vec* _48;
    /* 0x4C */ u8 _4C[0x64 - 0x4C];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66[0x6C - 0x66];
    /* 0x6C */ u8 _6C;
    /* 0x6D */ u8 _6D;
} lbl_3_common_bss_350E4;

extern struct {
    /* 0x00 */ u8 _00[0x6C];
    /* 0x6C */ StaC6ModelTable* _6C;
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];

// .data 0x19018 to 0x19770 belongs to this file, but lies outside its splits.txt ranges
extern GXColor lbl_3_data_19018[3];
extern GXColor lbl_3_data_19024[9][3];
extern StaC6Prop lbl_3_data_19090[16];
extern StaC6Prop lbl_3_data_191D0[16];
extern StaC6Prop lbl_3_data_19310[16];
extern StaC6Prop lbl_3_data_19450[16];
extern StaC6Slot lbl_3_data_19590[8];
extern StaC6Slot lbl_3_data_195B0[8];
extern StaC6Slot lbl_3_data_195D0[8];
extern StaC6Slot lbl_3_data_195F0[8];
extern u8 lbl_3_data_19610[0x2F];
extern s8 lbl_3_data_1963F;
extern s8 lbl_3_data_19640;
extern Vec lbl_3_data_19644[7];
extern f32 lbl_3_data_19698[7];
extern u8 lbl_3_data_196B4[7];
extern Vec lbl_3_data_196BC[7];
extern f32 lbl_3_data_19710[7];
extern u32 lbl_3_data_1972C[16];
extern u8 lbl_3_data_1976C;

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern StaC6ModelTable* ActorObjectInitTable(u16 count);
extern void fn_800BDC88(StaC6ModelTable* table, u16 first, u16 last, void* model, void* anim, s32 arg5);
extern void fn_800BD478(StaC6Model* model, void* file);
extern void fn_800BD548(StaC6Model* model, s32 count, ...);
extern void fn_800BDA24(StaC6Model* model);
extern void fn_800BDA94(StaC6Model* model, Mtx camera);
extern f32 fn_800B4C40(StaC6Actor* actor);
extern void fn_800B4CA0(StaC6Actor* actor, f32 frame);
extern u8 fn_800B3C04(s32 arg0, StaC6Actor* actor, Mtx camera);
extern void AnimateActorBones(StaC6Actor* actor);
extern s32 fn_8005268C(void);
extern camera_803c639c_s* fn_80052734(s32 idx);
extern void fn_3_B8414(Vec* min, Vec* max);
extern void fn_3_B8464(Mtx m, void* model);
extern void fn_3_B8574(void);
extern void fn_3_B97DC(void* model, void* anim);
extern void fn_3_B9D68(u8* types, s32 count, void** files, s32* indices);

// MWCC lays out .bss statics in reverse order of declaration
static u8 lbl_3_bss_AEB8[0x28];
static StaC6Prop* lbl_3_bss_AEB4;
static StaC6Slot* lbl_3_bss_AEB0;
static u8 lbl_3_bss_AEAE;
static u8 lbl_3_bss_AEAD;
static u8 lbl_3_bss_AEAC;
static u8 lbl_3_bss_AE8C[0x20];
static s32 lbl_3_bss_AE88;
static s32 lbl_3_bss_AE84;
static u8 lbl_3_bss_AE80[4];
static u8 lbl_3_bss_AE7C;
static u8 lbl_3_bss_AE7B;
static u8 lbl_3_bss_AE54[0x27];
static u8 lbl_3_bss_AE53;
static u8 lbl_3_bss_AE52;
static u8 lbl_3_bss_AE51;
static u8 lbl_3_bss_AE50;

static inline StaC6Model* getModel(u32 idx) {
    return &lbl_8036E548._6C->models[idx];
}

static inline void playStadiumSound(s32 sound) {
    SND_VOICEID voice;
    u8 vol;
    s32 stadium = g_d_GameSettings.StadiumID;

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

// .text:0x000E8B24 size:0x5F8 mapped:0x80727BB8
void fn_3_E8B24(void** files) {
    s32* indices;
    StaC6Model* model;
    u32 i;

    lbl_3_common_bss_350E4._18 = fn_3_E7424;
    lbl_3_common_bss_350E4._6C = 0;
    indices = lbl_3_common_bss_350E4._34 = _OSAllocFromHeap(4, 0x2F * sizeof(s32));
    fn_3_B9D68(lbl_3_data_19610, 0x2F, files, indices);
    lbl_8036E548._6C = ActorObjectInitTable(30);
    fn_800BDC88(lbl_8036E548._6C, 0, 0, files[indices[1]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 1, 1, files[indices[2]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 2, 2, files[indices[3]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 3, 3, files[indices[4]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 4, 4, files[indices[5]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 5, 5, files[indices[6]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 6, 6, files[indices[7]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 7, 7, files[indices[8]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 8, 8, files[indices[9]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 9, 9, files[indices[10]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 10, 10, files[indices[11]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 11, 11, files[indices[12]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 12, 12, files[indices[13]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 13, 13, files[indices[14]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 14, 14, files[indices[15]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 15, 15, files[indices[16]], NULL, 0);
    for (i = 0; i < 7; i++) {
        fn_800BDC88(lbl_8036E548._6C, i + 16, i + 16, files[indices[i + 17]], NULL, 0);
        fn_3_B97DC(&lbl_8036E548._6C->models[i + 16], files[indices[i + 17] + 2]);
    }
    fn_800BDC88(lbl_8036E548._6C, 23, 23, files[indices[24]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 24, 24, files[indices[25]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 25, 25, files[indices[26]], NULL, 0);
    fn_3_B97DC(&lbl_8036E548._6C->models[25], files[indices[26] + 2]);
    fn_800BDC88(lbl_8036E548._6C, 26, 26, files[indices[27]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 27, 27, files[indices[28]], NULL, 0);
    fn_800BDC88(lbl_8036E548._6C, 28, 28, files[indices[29]], NULL, 0);
    fn_3_B97DC(&lbl_8036E548._6C->models[28], files[indices[29] + 2]);
    model = &lbl_8036E548._6C->models[28];
    model->_5C = 20.0f;
    model->_59 = 1;
    fn_800B4CA0(lbl_8036E548._6C->models[28]._00, lbl_8036E548._6C->models[28]._5C);
    fn_800BDC88(lbl_8036E548._6C, 29, 29, files[indices[30]], NULL, 0);
    fn_3_B97DC(&lbl_8036E548._6C->models[29], files[indices[30] + 2]);
    model = &lbl_8036E548._6C->models[29];
    model->_5C = 60.0f;
    model->_59 = 1;
    fn_800B4CA0(lbl_8036E548._6C->models[29]._00, lbl_8036E548._6C->models[29]._5C);

    lbl_3_common_bss_350E4._6D = 30;
    for (i = 0; i < lbl_3_common_bss_350E4._6D; i++) {
        fn_800BD478(&lbl_8036E548._6C->models[i], files[indices[i + 1]]);
    }
    for (i = 0; i < 30; i++) {
        fn_800BD548(&lbl_8036E548._6C->models[i], 4, lbl_3_common_bss_350E4._20, lbl_3_common_bss_350E4._24,
                    lbl_3_common_bss_350E4._28, lbl_3_common_bss_350E4._2C);
    }

    lbl_3_common_bss_350E4._30 = 32;
    lbl_3_common_bss_350E4._00 = _OSAllocFromHeap(32, lbl_3_common_bss_350E4._30 * sizeof(StaC6Draw));
    memset(lbl_3_common_bss_350E4._00, 0, lbl_3_common_bss_350E4._30 * sizeof(StaC6Draw));
    lbl_3_common_bss_350E4._04 = _OSAllocFromHeap(32, lbl_3_common_bss_350E4._30 * sizeof(StaC6Draw));
    memset(lbl_3_common_bss_350E4._04, 0, lbl_3_common_bss_350E4._30 * sizeof(StaC6Draw));
    lbl_3_common_bss_350E4._48 = NULL;
    fn_3_E7B20(files, indices);
    lbl_3_bss_AE88 = 0;
}

// .text:0x000E8AC8 size:0x5C mapped:0x80727B5C
BOOL fn_3_E8AC8(void) {
    if (g_d_GameSettings.StadiumID != STADIUM_ID_TOY_FIELD) {
        return FALSE;
    }
    return fn_3_E7B20(lbl_3_common_bss_350E4._38, lbl_3_common_bss_350E4._34) != 0;
}

// .text:0x000E7B20 size:0xFA8 mapped:0x80726BB4
// The target reaches .data 0x19018-0x19770 from one pool base, which externs cannot
// reproduce; with statics this scores 99.5% (pool bases in swapped registers, third loop counters)
u8 fn_3_E7B20(void** files, s32* indices) {
    StaC6Draw* draw;
    StaC6Draw* entry;
    StaC6Model* model;
    u32 n;
    u32 i;
    u8 end;

    n = 0;
    end = FALSE;
    if (files == NULL || indices == NULL) {
        return FALSE;
    }
    lbl_3_bss_AEAC = 0;
    memset(lbl_3_bss_AE8C, 0xFF, sizeof(lbl_3_bss_AE8C));
    memset(lbl_3_common_bss_350E4._00, 0, lbl_3_common_bss_350E4._30 * sizeof(StaC6Draw));
    draw = lbl_3_common_bss_350E4._00;
    entry = draw;
    switch (g_Minigame.miniGameNumberOfParticipants) {
    case 2:
        lbl_3_bss_AEB4 = lbl_3_data_19090;
        lbl_3_bss_AEB0 = lbl_3_data_19590;
        break;
    case 3:
        lbl_3_bss_AEB4 = lbl_3_data_191D0;
        lbl_3_bss_AEB0 = lbl_3_data_195B0;
        break;
    case 4:
    default:
        lbl_3_bss_AEB4 = lbl_3_data_19310;
        lbl_3_bss_AEB0 = lbl_3_data_195D0;
        break;
    }
    lbl_3_bss_AEAE = g_Minigame.miniGameNumberOfParticipants - 2;
    if (g_Minigame._19A6 > 1) {
        lbl_3_bss_AE52 = 1;
        lbl_3_bss_AEB4 = lbl_3_data_19450;
        lbl_3_bss_AEB0 = lbl_3_data_195F0;
        lbl_3_bss_AEAE = 3;
    }

    for (i = 0; i < 15; i++) {
        if (lbl_3_bss_AEB4[i].type == 0x1B) {
            end = TRUE;
        }
        if (end) {
            for (; i < 16; i++) {
                memset(&lbl_3_bss_AEB4[i], 0, sizeof(StaC6Prop));
                lbl_3_bss_AEB4[i].type = 0x1B;
                lbl_3_bss_AEB4[i]._12 = 10;
            }
            break;
        }
        entry->_C0 = i;
        entry->type = lbl_3_bss_AEB4[i].type;
        entry->_9C = &lbl_8036E548._6C->models[23];
        draw->_74 = &lbl_8036E548._6C->models[entry->type];
        draw->_78 = files[indices[entry->type + 31]];
        draw->_90_7 = 1;
        draw->_90_6 = 1;
        draw->control.type = 0;
        CTRLSetTranslation(&draw->control, 0.0f, 0.0f, 0.0f);
        entry->_B8 = &lbl_3_data_19024[entry->type][0];
        entry->_B4 = &lbl_3_data_19024[entry->type][1];
        entry->_B0 = &lbl_3_data_19024[entry->type][2];
        entry->_BC = &lbl_3_data_19024[8][1];
        fn_3_E6528(entry);
        draw->_90_5 = 0;
        draw->_92 = 0xFF;
        draw->_8C = NULL;
        draw->_94 = 0;
        draw->_96 = -1;
        draw->_98 = 1;
        fn_3_E7A2C(entry);
        entry = ++draw;
        n++;
    }

    end = FALSE;
    lbl_3_bss_AEAD = n;
    for (i = 0; i < 7; i++) {
        if (lbl_3_bss_AEB0[i].type == 0x1B) {
            end = TRUE;
        }
        if (end) {
            for (; i < 8; i++) {
                memset(&lbl_3_bss_AEB0[i], 0, sizeof(StaC6Slot));
                lbl_3_bss_AEB0[i].type = 0x1B;
                lbl_3_bss_AEB0[i]._02 = 10;
            }
            break;
        }
        entry->_C0 = n;
        entry->type = lbl_3_bss_AEB0[i].type;
        entry->_C3 = i;
        entry->_C4 = 6 - i;
        entry->_9C = &lbl_8036E548._6C->models[24];
        draw->_74 = &lbl_8036E548._6C->models[entry->type];
        draw->_78 = files[indices[entry->type + 31]];
        draw->_90_7 = 1;
        draw->_90_6 = 1;
        draw->control.type = 0;
        CTRLSetTranslation(&draw->control, 0.0f, 0.0f, 0.0f);
        entry->_B8 = &lbl_3_data_19024[entry->type - 8][0];
        entry->_B4 = &lbl_3_data_19024[entry->type - 8][1];
        entry->_B0 = &lbl_3_data_19024[entry->type - 8][2];
        entry->_BC = &lbl_3_data_19024[8][1];
        fn_3_E6528(entry);
        draw->_90_5 = 0;
        draw->_92 = 0xFF;
        draw->_8C = NULL;
        draw->_94 = 0;
        draw->_96 = -1;
        draw->_98 = 1;
        fn_3_E7A2C(entry);
        entry = ++draw;
        n++;
    }

    for (i = 0; i < 7; i++) {
        entry->_C0 = n;
        entry->type = i + 16;
        entry->_9C = &lbl_8036E548._6C->models[25];
        draw->_74 = &lbl_8036E548._6C->models[i + 16];
        draw->_78 = NULL;
        draw->_90_7 = 1;
        draw->_90_6 = 1;
        draw->control.type = 0;
        CTRLSetTranslation(&draw->control, lbl_3_data_196BC[entry->type - 16].x, lbl_3_data_196BC[entry->type - 16].y,
                           lbl_3_data_196BC[entry->type - 16].z);
        CTRLSetRotation(&draw->control, 0.0f, lbl_3_data_19710[entry->type - 16], 0.0f);
        draw->_90_5 = 1;
        draw->_92 = 0xFF;
        draw->_8C = NULL;
        draw->_94 = 0;
        draw->_96 = -1;
        draw->_98 = 1;
        fn_3_E7A2C(entry);
        entry = ++draw;
        n++;
    }

    draw[0]._C0 = n;
    draw[0].type = 23;
    draw[0]._74 = &lbl_8036E548._6C->models[26];
    draw[0]._78 = NULL;
    draw[0]._90_7 = 1;
    draw[0]._90_6 = 0;
    draw[0].control.type = 0;
    CTRLSetTranslation(&draw[0].control, 0.0f, 0.0f, 0.0f);
    draw[0]._90_5 = 0;
    draw[0]._92 = 0xFF;
    draw[0]._8C = NULL;
    draw[0]._94 = 0;
    draw[0]._96 = -1;
    draw[0]._98 = 1;
    fn_3_E7A2C(&draw[0]);

    draw[1]._C0 = n + 1;
    draw[1].type = 24;
    draw[1]._74 = &lbl_8036E548._6C->models[27];
    draw[1]._78 = NULL;
    draw[1]._90_7 = 1;
    draw[1]._90_6 = 0;
    draw[1].control.type = 0;
    entry = &draw[1];
    CTRLSetTranslation(&entry->control, 0.0f, 0.0f, 0.0f);
    draw[1]._90_5 = 0;
    draw[1]._92 = 0xFF;
    draw[1]._8C = NULL;
    draw[1]._94 = 0;
    draw[1]._96 = -1;
    draw[1]._98 = 1;
    fn_3_E7A2C(entry);

    draw[2]._C0 = n + 2;
    draw[2].type = 26;
    draw[2]._74 = &lbl_8036E548._6C->models[28];
    draw[2]._78 = NULL;
    draw[2]._90_7 = 1;
    draw[2]._90_6 = 0;
    draw[2].control.type = 0;
    entry = &draw[2];
    CTRLSetTranslation(&entry->control, 0.0f, 0.0f, 0.0f);
    draw[2]._90_5 = 0;
    draw[2]._92 = 0xFF;
    draw[2]._8C = NULL;
    draw[2]._94 = 0;
    draw[2]._96 = -1;
    draw[2]._98 = 0;
    fn_3_E7A2C(entry);

    draw[3]._C0 = n + 3;
    draw[3].type = 25;
    draw[3]._74 = &lbl_8036E548._6C->models[29];
    draw[3]._78 = NULL;
    draw[3]._90_7 = 1;
    draw[3]._90_6 = 0;
    draw[3].control.type = 0;
    entry = &draw[3];
    CTRLSetTranslation(&entry->control, 0.0f, 0.0f, 0.0f);
    draw[3]._90_5 = 0;
    draw[3]._92 = 0xFF;
    draw[3]._8C = NULL;
    draw[3]._94 = 0;
    draw[3]._96 = -1;
    draw[3]._98 = 1;
    fn_3_E7A2C(entry);

    i = n + 4;
    draw += 4;
    entry = draw;
    if (lbl_3_common_bss_350E4._30 > i) {
        for (; i < lbl_3_common_bss_350E4._30; i++) {
            entry->type = 0x1B;
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
            entry = ++draw;
        }
    }

    fn_3_E763C();
    if (g_GameLogic.gameStatus == GAME_STATUS_GAME_START_MOVIE) {
        for (i = 0; i < 7; i++) {
            lbl_3_data_196B4[i] = 0;
            model = &lbl_8036E548._6C->models[i + 16];
            model->_5C = 20.0f;
            model->_59 = 1;
            fn_800B4CA0(lbl_8036E548._6C->models[i + 16]._00, lbl_8036E548._6C->models[i + 16]._5C);
            AnimateActorBones(lbl_8036E548._6C->models[i + 16]._00);
        }
    }
    return TRUE;
}

// .text:0x000E7A2C size:0xF4 mapped:0x80726AC0
void fn_3_E7A2C(void* arg) {
    StaC6Draw* draw = arg;

    draw->_7C = NULL;
    draw->_80 = NULL;
    draw->_84 = NULL;
    draw->_88 = NULL;
    switch (draw->type) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        draw->_80 = fn_3_E7364;
        draw->_84 = fn_3_E6D90;
        lbl_3_bss_AEAC++;
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
        draw->_7C = fn_3_E698C;
        draw->_84 = fn_3_E68A8;
        break;
    case 23:
        draw->_84 = fn_3_E6798;
        draw->_88 = fn_3_E671C;
        break;
    case 24:
        draw->_84 = fn_3_E6684;
        draw->_88 = fn_3_E6638;
        break;
    case 26:
        draw->_7C = fn_3_E59B4;
        break;
    case 25:
        draw->_7C = fn_3_E5A1C;
        break;
    }
}

// .text:0x000E763C size:0x3F0 mapped:0x807266D0
// 98.4%: the target copies i's zero into the first loop's induction registers
// (mr r21,r24), and its frame is 0x10 bytes larger
void fn_3_E763C(void) {
    Control control;
    Mtx mtx;
    StaC6Draw* draw;
    u32 size;
    s32 start;
    s32 j;
    s32 i;
    s32 n;

    size = lbl_3_common_bss_350E4._30 * sizeof(u32) + lbl_3_common_bss_350E4._30 * sizeof(u16) +
           lbl_3_common_bss_350E4._30 * sizeof(u32) + lbl_3_common_bss_350E4._30 * 2 * sizeof(Vec);
    if (lbl_3_common_bss_350E4._48 == NULL) {
        lbl_3_common_bss_350E4._48 = _OSAllocFromHeap(4, size);
        lbl_3_common_bss_350E4._3C = (u32*)(lbl_3_common_bss_350E4._48 + lbl_3_common_bss_350E4._30 * 2);
        lbl_3_common_bss_350E4._44 = lbl_3_common_bss_350E4._3C + lbl_3_common_bss_350E4._30;
        lbl_3_common_bss_350E4._40 = (u16*)(lbl_3_common_bss_350E4._44 + lbl_3_common_bss_350E4._30);
    }
    memset(lbl_3_common_bss_350E4._48, 0, size);

    n = 0;
    for (i = 0; i < 10; i++) {
        start = lbl_3_common_bss_350E4._40[n] = lbl_3_common_bss_350E4._40[n - 1] + lbl_3_common_bss_350E4._3C[n - 1];
        fn_3_B8574();
        if ((lbl_803C77B8._00 & 0x800) && i != 0) {
            continue;
        }
        if ((lbl_803C77B8._00 & 0x400) && j != 0) {
            continue;
        }
        for (j = 0; j < 15; j++) {
            if (lbl_3_bss_AEB4[j]._12 == i) {
                draw = &lbl_3_common_bss_350E4._00[j];
                if (draw->_90_6 && draw->_78 != NULL) {
                    lbl_3_common_bss_350E4._44[start] = j;
                    start++;
                    lbl_3_common_bss_350E4._3C[n]++;
                    control.type = 0;
                    draw = &lbl_3_common_bss_350E4._00[j];
                    CTRLSetTranslation(&control, lbl_3_bss_AEB4[j].pos.x, lbl_3_bss_AEB4[j].pos.y,
                                       lbl_3_bss_AEB4[j].pos.z);
                    CTRLSetRotation(&control, 0.0f, lbl_3_bss_AEB4[j].rotY, 0.0f);
                    CTRLBuildMatrix(&control, mtx);
                    fn_3_B8464(mtx, draw->_78);
                }
            }
        }
        if (lbl_3_common_bss_350E4._3C[n] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[n * 2], &lbl_3_common_bss_350E4._48[n * 2 + 1]);
            n++;
        }
    }

    for (i = 0; i < 10; i++) {
        start = lbl_3_common_bss_350E4._40[n] = lbl_3_common_bss_350E4._40[n - 1] + lbl_3_common_bss_350E4._3C[n - 1];
        fn_3_B8574();
        for (j = 0; j < 7; j++) {
            if (lbl_3_bss_AEB4[j]._12 == i) {
                draw = &lbl_3_common_bss_350E4._00[j];
                if (draw->_90_6 && draw->_78 != NULL) {
                    lbl_3_common_bss_350E4._44[start] = j + lbl_3_bss_AEAD;
                    start++;
                    lbl_3_common_bss_350E4._3C[n]++;
                    control.type = 0;
                    draw = &lbl_3_common_bss_350E4._00[j + lbl_3_bss_AEAD];
                    CTRLSetTranslation(&control, lbl_3_data_19644[j].x, lbl_3_data_19644[j].y,
                                       lbl_3_data_19644[j].z);
                    CTRLSetRotation(&control, 0.0f, lbl_3_data_19698[j], 0.0f);
                    CTRLBuildMatrix(&control, mtx);
                    fn_3_B8464(mtx, draw->_78);
                }
            }
        }
        if (lbl_3_common_bss_350E4._3C[n] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[n * 2], &lbl_3_common_bss_350E4._48[n * 2 + 1]);
            n++;
        }
        lbl_3_common_bss_350E4._64 = n;
    }
}

// .text:0x000E751C size:0x120 mapped:0x807265B0
void* fn_3_E751C(s32 idx, Mtx m) {
    Control control;
    StaC6Draw* draw;

    control.type = 0;
    draw = &lbl_3_common_bss_350E4._00[idx];
    if (draw->type <= 7) {
        CTRLSetTranslation(&control, lbl_3_bss_AEB4[idx].pos.x, -0.04f, lbl_3_bss_AEB4[idx].pos.z);
        CTRLSetRotation(&control, 0.0f, lbl_3_bss_AEB4[idx].rotY, 0.0f);
    } else {
        CTRLSetTranslation(&control, lbl_3_data_19644[draw->_C3].x, -0.04f, lbl_3_data_19644[draw->_C3].z);
        CTRLSetRotation(&control, 0.0f, lbl_3_data_19698[draw->_C3], 0.0f);
    }
    CTRLBuildMatrix(&control, m);
    return draw->_78;
}

// .text:0x000E7424 size:0xF8 mapped:0x807264B8
void fn_3_E7424(void) {
    if (g_GameLogic.gameStatus == GAME_STATUS_AT_BAT || g_GameLogic.gameStatus == GAME_STATUS_DEFAULT) {
        lbl_3_bss_AE88++;
        lbl_3_bss_AE80[0] = g_Minigame._1914 != 0;
        lbl_3_bss_AE80[1] = g_Minigame._1915 != 0;
        lbl_3_bss_AE80[2] = g_Minigame._1916 != 0;
        lbl_3_bss_AE80[3] = g_Minigame._1917 != 0;
        lbl_3_data_1963F = -1;
        lbl_3_data_19640 = -1;
    }
    lbl_3_bss_AE7C = lbl_3_bss_AE7B;
    lbl_3_bss_AE7B = g_Minigame.toyFieldBallStateResult;
    lbl_3_bss_AE84 += lbl_80366158._28 == 0;
    if (lbl_3_bss_AE7C != lbl_3_bss_AE7B) {
        lbl_3_bss_AE84 = 0;
    }
    lbl_3_bss_AE51 = 0;
}

// .text:0x000E7388 size:0x9C mapped:0x8072641C
void fn_3_E7388(void* arg0, StaC6Sort* out) {
    StaC6Draw* draw;
    StaC6Sort* p;
    StaC6Draw* draw2;
    s32 i;

    draw = &lbl_3_common_bss_350E4._00[lbl_3_common_bss_350E4._30 - 1];
    p = out;
    i = lbl_3_common_bss_350E4._30 - 1;
    do {
        if (!draw->_90_7) {
            p->idx = i;
            p++;
        }
        draw--;
    } while (i-- != 0);
    draw2 = &lbl_3_common_bss_350E4._00[lbl_3_common_bss_350E4._30 - 1];
    p = out + lbl_3_common_bss_350E4._30;
    i = lbl_3_common_bss_350E4._30 - 1;
    do {
        if (draw2->_90_7) {
            p--;
            p->idx = i;
            p->depth = 1.0f;
        }
        draw2--;
    } while (i-- != 0);
}

// .text:0x000E7364 size:0x24 mapped:0x807263F8
void fn_3_E7364(s32 idx) {
    StaC6Draw* draw = &lbl_3_common_bss_350E4._00[idx];
    lbl_3_data_19640 = draw->_C0;
}

// .text:0x000E7350 size:0x14 mapped:0x807263E4
void fn_3_E7350(void) {
    lbl_3_data_1963F = lbl_3_data_19640;
}

// .text:0x000E6D90 size:0x5C0 mapped:0x80725E24
// The target reaches .data 0x19018-0x19770 from one pool base, which externs cannot
// reproduce; with that data defined here as statics this scores 99.96% (frame 0x10 smaller)
void fn_3_E6D90(void* arg) {
    StaC6Draw* draw = arg;

    fn_3_E5A84(draw);
    if (g_GameLogic.gameStatus == GAME_STATUS_DEFAULT || g_GameLogic.gameStatus == GAME_STATUS_AT_BAT) {
        fn_3_E6528(draw);
        if (lbl_3_bss_AE52) {
            lbl_3_bss_AE52 = 0;
        }
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL) {
        if (g_Ball.AtBat_ContactResult != 0) {
            if (lbl_3_data_1963F == draw->_C0 &&
                g_Minigame.maybeTFCollisionResultState == lbl_3_data_1972C[draw->type])
            {
                memcpy(&draw->color, draw->_B0, 4);
                draw->_BC = &lbl_3_data_19024[8][2];
                if (!draw->_C2) {
                    playStadiumSound(20);
                }
                draw->_C2 = 1;
                if (g_Minigame.toyFieldBallStateResult != 0 &&
                    g_Minigame.toyFieldBallStateResult == lbl_3_data_1972C[draw->type] && draw->type >= 8)
                {
                    if (!lbl_3_data_196B4[draw->_C4]) {
                        playStadiumSound(23);
                    }
                    lbl_3_data_196B4[draw->_C4] = 1;
                }
            } else {
                memcpy(&draw->color, draw->_B8, 4);
                draw->_BC = &lbl_3_data_19024[8][0];
                draw->_C2 = 0;
            }
        }
    } else {
        draw->_A0 = 0;
    }
    if (lbl_3_bss_AE52) {
        memcpy(&draw->color, draw->_B0, 4);
        draw->_BC = &lbl_3_data_19024[8][2];
        draw->_C2 = 1;
    }
    fn_3_E5FEC(draw);
    fn_3_E6578(draw);
    if (draw->_9C != NULL) {
        fn_800BDA94(draw->_9C, fn_80052768_getCamera(fn_8005268C())->view);
        draw->_9C->_00->_18[2]->_14 = draw->_9C->_00->_18[2]->_18;
    }
}

// .text:0x000E6A48 size:0x348 mapped:0x80725ADC
// The target reaches .data 0x19018-0x19770 from one pool base, which externs cannot
// reproduce; with that data defined here as statics this scores 99.8% (frame 0x10 smaller)
void fn_3_E6A48(StaC6Draw* draw) {
    fn_3_E5A84(draw);
    fn_3_E6578(draw);
    if (draw->_9C != NULL) {
        fn_3_E5FEC(draw);
        fn_800BDA94(draw->_9C, fn_80052768_getCamera(fn_8005268C())->view);
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_LIVE_BALL && g_Minigame.toyFieldBallStateResult != 0 &&
        g_Minigame.toyFieldBallStateResult == lbl_3_data_1972C[draw->type] && lbl_3_data_1963F == draw->_C0 &&
        draw->type >= 8)
    {
        lbl_3_data_196B4[draw->_C4] = 1;
    }
}

// .text:0x000E698C size:0xBC mapped:0x80725A20
void fn_3_E698C(void* arg) {
    StaC6Draw* draw = arg;
    StaC6Actor* actor = draw->_74->_00;
    f32 frame = fn_800B4C40(draw->_74->_00);
    u8 idx = draw->type - 16;

    if (lbl_3_data_196B4[idx] == 0) {
        fn_800B4CA0(actor, 0.0f);
        AnimateActorBones(actor);
    }
    if (lbl_3_data_196B4[idx] != 0 && frame <= 60.0f) {
        AnimateActorBones(actor);
    }
}

// .text:0x000E68A8 size:0xE4 mapped:0x8072593C
void fn_3_E68A8(void* arg) {
    StaC6Draw* draw = arg;
    StaC6Actor* actor = draw->_9C->_00;
    f32 frame;

    frame = fn_800B4C40(draw->_74->_00) - draw->_74->_54;
    if (frame < 0.0f) {
        frame = 0.0f;
    }
    if (draw->_9C != NULL) {
        memcpy(draw->_9C->_10, draw, 0x44);
        fn_800B4CA0(actor, frame);
        fn_800BDA24(draw->_9C);
        draw->_9C->_00->_98 = fn_800B3C04(0, draw->_9C->_00, fn_80052734(fn_8005268C())->view);
        fn_800BDA94(draw->_9C, fn_80052768_getCamera(fn_8005268C())->view);
    }
}

// .text:0x000E67F4 size:0xB4 mapped:0x80725888
void fn_3_E67F4(void) {
    StaC6Model* model;
    u32 i;
    StaC6Actor* actor;

    for (i = 0; i < 7; i++) {
        lbl_3_data_196B4[i] = 0;
        actor = lbl_8036E548._6C->models[i + 16]._00;
        model = getModel(i + 16);
        model->_5C = 20.0f;
        model->_59 = 1;
        fn_800B4CA0(actor, lbl_8036E548._6C->models[i + 16]._5C);
        AnimateActorBones(actor);
    }
}

// .text:0x000E6798 size:0x5C mapped:0x8072582C
void fn_3_E6798(void* arg) {
    StaC6Draw* draw = arg;
    StaC6Actor* actor = draw->_74->_00;
    s32 i;

    for (i = 0; i < 7; i++) {
        if (lbl_3_data_196B4[i]) {
            actor->_18[i]->_14 = actor->_18[i]->_18;
        } else {
            actor->_18[i]->_14 = NULL;
        }
    }
}

// .text:0x000E671C size:0x7C mapped:0x807257B0
void fn_3_E671C(void* arg) {
    StaC6Draw* draw = arg;
    StaC6Actor* actor = draw->_74->_00;
    s32 i;

    for (i = 0; i < 7; i++) {
        actor->_18[i]->_14 = actor->_18[i]->_18;
    }
}

// .text:0x000E6684 size:0x98 mapped:0x80725718
void fn_3_E6684(void* arg) {
    StaC6Draw* draw = arg;
    StaC6Bone* bone;
    s32 i;

    for (i = 0; i < 3; i++) {
        bone = draw->_74->_00->_18[i];
        if (lbl_3_bss_AE80[i + 1]) {
            bone->_14 = bone->_18;
        } else {
            bone->_14 = NULL;
        }
    }
}

// .text:0x000E6638 size:0x4C mapped:0x807256CC
void fn_3_E6638(void* arg) {
    StaC6Draw* draw = arg;
    draw->_74->_00->_18[0]->_14 = draw->_74->_00->_18[0]->_18;
    draw->_74->_00->_18[1]->_14 = draw->_74->_00->_18[1]->_18;
    draw->_74->_00->_18[2]->_14 = draw->_74->_00->_18[2]->_18;
}

// .text:0x000E6578 size:0xC0 mapped:0x8072560C
void fn_3_E6578(StaC6Draw* draw) {
    StaC6Shape* shape;
    StaC6DispState* state;

    if (draw->_9C == NULL) {
        return;
    }
    shape = draw->_9C->_00->_18[1]->_14;
    state = shape->_08;
    if (shape->_10->_04->_20 != 3) {
        OSErrorLine(1811, "参照するディスプレイステートがTEV設定部分じゃないです\n");
    }
    if (draw->type == 2) {
        state->_0C->_A0 = 1;
    } else if (draw->type == 10) {
        state->_0C->_A0 = 0;
    } else {
        state->_0C->_A0 = 4;
    }
}

// .text:0x000E6528 size:0x50 mapped:0x807255BC
void fn_3_E6528(StaC6Draw* draw) {
    memcpy(&draw->color, draw->_B4, 4);
    draw->_BC = &lbl_3_data_19024[8][1];
    draw->_C2 = 0;
}

// .text:0x000E64A8 size:0x80 mapped:0x8072553C
GXColor* fn_3_E64A8(void) {
    switch ((u8)(rand() % 3)) {
    case 0:
        return &lbl_3_data_19018[0];
    case 1:
        return &lbl_3_data_19018[1];
    default:
        return &lbl_3_data_19018[2];
    }
}

// .text:0x000E6410 size:0x98 mapped:0x807254A4
void fn_3_E6410(StaC6Draw* draw) {
    GXColor* colors[3];
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 3; i++) {
        if (draw->to != &lbl_3_data_19018[i]) {
            colors[n] = &lbl_3_data_19018[i];
            n++;
        }
    }
    draw->from = colors[rand() % 2];
}

// .text:0x000E5FEC size:0x424 mapped:0x80725080
void fn_3_E5FEC(StaC6Draw* draw) {
    StaC6Tex* tex;
    void* data;

    tex = draw->_9C->_00->_18[1]->_14->_04;
    data = tex->_00;
    switch ((u8)(tex->format >> 4)) {
    case GX_RGB565:
        *(u16*)data = ((u16)(draw->color.r >> 3) << 11) & 0xF800;
        *(u16*)data |= ((u16)(draw->color.g >> 2) << 5) & 0x7E0;
        *(u16*)data |= (u16)(draw->color.b >> 3) & 0x1F;
        DCStoreRange(data, 2);
        break;
    case GX_RGBA4:
        *(u16*)data = ((u16)(draw->color.r >> 4) << 12) & 0xF000;
        *(u16*)data |= ((u16)(draw->color.g >> 4) << 8) & 0xF00;
        *(u16*)data |= ((u16)(draw->color.b >> 4) << 4) & 0xF0;
        *(u16*)data |= (u16)(draw->color.a >> 4) & 0xF;
        DCStoreRange(data, 2);
        break;
    case GX_RGBA8:
        memcpy(data, &draw->color, 4);
        DCStoreRange(data, 4);
        break;
    case GX_RGB8:
    case GX_RGBX8:
        *(u32*)data = draw->color.r << 16;
        *(u32*)data |= draw->color.g << 8;
        *(u32*)data |= draw->color.b;
        DCStoreRange(data, 3);
        break;
    case GX_RGBA6:
        *(u32*)data = ((draw->color.r >> 2) & 0x3F) << 26;
        *(u32*)data = ((draw->color.g >> 2) & 0x3F) << 20;
        *(u32*)data = ((draw->color.b >> 2) & 0x3F) << 14;
        *(u32*)data = ((draw->color.a >> 2) & 0x3F) << 8;
        DCStoreRange(data, 3);
        break;
    }

    if (lbl_3_data_1976C) {
        if (draw->_C2) {
            draw->_9C->_00->_18[2]->_14 = draw->_9C->_00->_18[2]->_18;
        } else {
            draw->_9C->_00->_18[2]->_14 = NULL;
        }
    } else {
        draw->_9C->_00->_18[2]->_14 = NULL;
    }

    tex = draw->_74->_00->_18[0]->_14->_04;
    data = tex->_00;
    switch ((u8)(tex->format >> 4)) {
    case GX_RGB565:
        *(u16*)data = ((u16)(draw->_BC->r >> 3) << 11) & 0xF800;
        *(u16*)data |= ((u16)(draw->_BC->g >> 2) << 5) & 0x7E0;
        *(u16*)data |= (u16)(draw->_BC->b >> 3) & 0x1F;
        DCStoreRange(data, 2);
        break;
    case GX_RGBA4:
        *(u16*)data = ((u16)(draw->_BC->r >> 4) << 12) & 0xF000;
        *(u16*)data |= ((u16)(draw->_BC->g >> 4) << 8) & 0xF00;
        *(u16*)data |= ((u16)(draw->_BC->b >> 4) << 4) & 0xF0;
        *(u16*)data |= (u16)(draw->_BC->a >> 4) & 0xF;
        DCStoreRange(data, 2);
        break;
    case GX_RGBA8:
        memcpy(data, draw->_BC, 4);
        DCStoreRange(data, 4);
        break;
    case GX_RGB8:
    case GX_RGBX8:
        *(u32*)data = draw->_BC->r << 16;
        *(u32*)data |= draw->_BC->g << 8;
        *(u32*)data |= draw->_BC->b;
        DCStoreRange(data, 3);
        break;
    case GX_RGBA6:
        *(u32*)data = ((draw->_BC->r >> 2) & 0x3F) << 26;
        *(u32*)data = ((draw->_BC->g >> 2) & 0x3F) << 20;
        *(u32*)data = ((draw->_BC->b >> 2) & 0x3F) << 14;
        *(u32*)data = ((draw->_BC->a >> 2) & 0x3F) << 8;
        DCStoreRange(data, 3);
        break;
    }
}

// .text:0x000E5E70 size:0x17C mapped:0x80724F04
void fn_3_E5E70(GXColor* dst, u8 format, void* src) {
    u8 type = format >> 4;

    if (dst == NULL || src == NULL) {
        return;
    }
    switch (type) {
    case GX_RGB565:
        dst->r = (*(u16*)src & 0xF800) >> 8;
        dst->g = (*(u16*)src & 0x7E0) >> 3;
        dst->b = (*(u16*)src & 0x1F) << 3;
        dst->a = 0xFF;
        break;
    case GX_RGBA4:
        dst->r = (*(u16*)src & 0xF000) >> 12;
        dst->g = (*(u16*)src & 0xF00) >> 8;
        dst->b = (*(u16*)src & 0xF0) >> 4;
        dst->a = *(u16*)src & 0xF;
        dst->r |= dst->r << 4;
        dst->g |= dst->g << 4;
        dst->b |= dst->b << 4;
        dst->a |= dst->a << 4;
        break;
    case GX_RGBA8:
        dst->r = (*(u32*)src & 0xFF000000) >> 24;
        dst->g = (*(u32*)src & 0xFF0000) >> 16;
        dst->b = (*(u32*)src & 0xFF00) >> 8;
        dst->a = *(u32*)src & 0xFF;
        break;
    case GX_RGB8:
    case GX_RGBX8:
        dst->r = (*(u32*)src & 0xFF000000) >> 24;
        dst->g = (*(u32*)src & 0xFF0000) >> 16;
        dst->b = (*(u32*)src & 0xFF00) >> 8;
        dst->a = 0xFF;
        break;
    case GX_RGBA6:
        dst->r = (*(u16*)src & 0xFC0000) >> 16;
        dst->g = (*(u16*)src & 0x3F000) >> 10;
        dst->b = (*(u16*)src & 0xFC0) >> 4;
        dst->a = (*(u16*)src & 0x3F) << 2;
        break;
    }
}

// .text:0x000E5E14 size:0x5C mapped:0x80724EA8
s32 fn_3_E5E14(StaC6Shape* shape) {
    switch ((u8)(shape->_04->format >> 4)) {
    case GX_RGB565:
    case GX_RGBA4:
        return 2;
    case GX_RGBA8:
        return 4;
    case GX_RGB8:
    case GX_RGBX8:
    case GX_RGBA6:
        return 3;
    default:
        return 0;
    }
}

// .text:0x000E5CBC size:0x158 mapped:0x80724D50
void fn_3_E5CBC(StaC6Draw* draw, f32 t) {
    GXColor* to = draw->to;
    GXColor* from = draw->from;

    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    draw->color.r = (1.0f - t) * to->r + t * from->r;
    draw->color.g = (1.0f - t) * to->g + t * from->g;
    draw->color.b = (1.0f - t) * to->b + t * from->b;
    draw->color.a = (1.0f - t) * to->a + t * from->a;
}

// .text:0x000E5A84 size:0x238 mapped:0x80724B18
void fn_3_E5A84(StaC6Draw* draw) {
    Control control;
    Mtx mtx;
    StaC6Bone* bone;
    s32 i;

    PSMTXIdentity(mtx);
    control.type = 0;
    if (draw->type < 8) {
        CTRLSetTranslation(&control, lbl_3_bss_AEB4[draw->_C0].pos.x, lbl_3_bss_AEB4[draw->_C0].pos.y,
                           lbl_3_bss_AEB4[draw->_C0].pos.z);
        CTRLSetRotation(&control, 0.0f, lbl_3_bss_AEB4[draw->_C0].rotY, 0.0f);
    } else {
        CTRLSetTranslation(&control, lbl_3_data_19644[draw->_C3].x, lbl_3_data_19644[draw->_C3].y,
                           lbl_3_data_19644[draw->_C3].z);
        CTRLSetRotation(&control, 0.0f, lbl_3_data_19698[draw->_C3], 0.0f);
    }
    CTRLBuildMatrix(&control, mtx);
    for (i = 0; i < draw->_74->_00->_06; i++) {
        bone = draw->_74->_00->_18[i];
        CTRLBuildMatrix(&bone->control, bone->_EC);
        PSMTXConcat(mtx, bone->_EC, bone->_EC);
        PSMTXCopy(bone->_EC, bone->_14->_18);
    }
    if (draw->_9C != NULL) {
        for (i = 0; i < draw->_9C->_00->_06; i++) {
            bone = draw->_9C->_00->_18[i];
            CTRLBuildMatrix(&bone->control, bone->_EC);
            PSMTXConcat(mtx, bone->_EC, bone->_EC);
            if (bone->_14 != NULL) {
                PSMTXCopy(bone->_EC, bone->_14->_18);
            }
        }
        draw->_9C->_00->_98 = fn_800B3C04(0, draw->_9C->_00, fn_80052734(fn_8005268C())->view);
    }
    draw->_74->_00->_98 = fn_800B3C04(0, draw->_74->_00, fn_80052734(fn_8005268C())->view);
}

// .text:0x000E5A1C size:0x68 mapped:0x80724AB0
void fn_3_E5A1C(void* arg) {
    StaC6Draw* draw = arg;
    StaC6Actor* actor = draw->_74->_00;

    if (fn_800B4C40(actor) + 1.0f > 420.0f) {
        fn_800B4CA0(actor, 60.0f);
    }
    AnimateActorBones(actor);
}

// .text:0x000E59B4 size:0x68 mapped:0x80724A48
void fn_3_E59B4(void* arg) {
    StaC6Draw* draw = arg;
    StaC6Actor* actor = draw->_74->_00;

    if (fn_800B4C40(actor) + 1.0f > 340.0f) {
        fn_800B4CA0(actor, 20.0f);
    }
    AnimateActorBones(actor);
}

