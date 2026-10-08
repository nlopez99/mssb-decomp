#include "game/rep_2998.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/os.h"
#include "Dolphin/rand.h"
#include "C3/control.h"
#include "C3/geoPalette.h"
#include "musyx/musyx.h"
#include "game/m_sound.h"
#include "game/rep_540.h"
#include "game/rep_1838.h"
#include "game/rep_23E8.h"
#include "game/rep_AC8.h"
#include "math.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0xEC];
    /* 0xEC */ MtxPtr _EC;
} Rep2998Bone;

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ DODisplayData* pal;
    /* 0x14 */ u8 _14[0x18 - 0x14];
    /* 0x18 */ Rep2998Bone** _18;
    /* 0x1C */ u8 _1C[0x98 - 0x1C];
    /* 0x98 */ u8 _98;
} Rep2998Actor;

typedef struct {
    /* 0x00 */ Rep2998Actor* _00;
    /* 0x04 */ u8 _04[0x54 - 0x04];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ u8 _60[0x90 - 0x60];
} Rep2998Model; // size: 0x90

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ Rep2998Model _34[1];
} Rep2998ModelTable;

typedef struct Rep2998Obj {
    /* 0x00 */ Control control;
    /* 0x44 */ u8 _44[0x74 - 0x44];
    /* 0x74 */ Rep2998Model* _74;
    /* 0x78 */ void* _78;
    /* 0x7C */ void (*_7C)(struct Rep2998Obj* obj);
    /* 0x80 */ void (*_80)(u32 idx);
    /* 0x84 */ void (*_84)(struct Rep2998Obj* obj);
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
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B;
    /* 0x9C */ u8 _9C;
    /* 0x9D */ u8 _9D;
    /* 0x9E */ u8 _9E;
    /* 0x9F */ u8 _9F;
    /* 0xA0 */ Vec _A0;
    /* 0xAC */ void* _AC;
    /* 0xB0 */ f32 _B0;
    /* 0xB4 */ f32 _B4;
    /* 0xB8 */ f32 _B8;
    /* 0xBC */ f32 _BC;
    /* 0xC0 */ f32 _C0;
    /* 0xC4 */ u8 _C4;
    /* 0xC5 */ u8 _C5;
    /* 0xC6 */ u8 _C6;
    /* 0xC7 */ u8 _C7;
    /* 0xC8 */ u8 _C8;
    /* 0xC9 */ u8 _C9;
    /* 0xCA */ u8 _CA;
    /* 0xCB */ s8 _CB;
    /* 0xCC */ u8 _CC[0xE8 - 0xCC];
} Rep2998Obj; // size: 0xE8

typedef struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ u8 _10;
    /* 0x11 */ u8 _11;
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 _18;
} Rep2998Prop; // size: 0x1C

typedef struct {
    /* 0x00 */ Rep2998Obj* _00;
    /* 0x04 */ u8* _04;
    /* 0x08 */ u8 _08[0x18 - 0x08];
    /* 0x18 */ void (*_18)(void);
    /* 0x1C */ void (*_1C)(void);
    /* 0x20 */ s32 _20;
    /* 0x24 */ s32 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
    /* 0x34 */ s32* _34;
    /* 0x38 */ u8 _38[0x3C - 0x38];
    /* 0x3C */ u32* _3C;
    /* 0x40 */ u16* _40;
    /* 0x44 */ u32* _44;
    /* 0x48 */ Vec* _48;
    /* 0x4C */ u8 _4C[0x64 - 0x4C];
    /* 0x64 */ s16 _64;
    /* 0x66 */ s16 _66;
    /* 0x68 */ u8 _68[0x6D - 0x68];
    /* 0x6D */ u8 _6D;
} Rep2998Common;

extern Rep2998Common lbl_3_common_bss_350E4;

extern struct {
    /* 0x00 */ u8 _00[0x6C];
    /* 0x6C */ Rep2998ModelTable* _6C;
} lbl_8036E548;

typedef struct {
    /* 0x000 */ Vec _000;
    /* 0x00C */ u8 _00C[0x210 - 0x00C];
    /* 0x210 */ u8 _210;
    /* 0x211 */ u8 _211[0x268 - 0x211];
} Rep2998Fielder; // size: 0x268

typedef struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01;
    /* 0x02 */ u16 _02;
} Rep2998MeshHeader;

typedef struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ u32 _0C;
} Rep2998MeshVertex;

typedef struct Rep2998Mesh {
    /* 0x00 */ u8 _00[0x08];
    /* 0x08 */ u8* _08;
} Rep2998Mesh;

extern Rep2998Fielder g_Fielders[9];
extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];

extern void* _OSAllocFromHeap(u32 align, u32 size);
extern Rep2998ModelTable* ActorObjectInitTable(u16 count);
extern void fn_800BDC88(Rep2998ModelTable* table, u16 first, u16 last, void* model, void* anim, void* arg5);
extern void fn_800BD548(Rep2998Model* model, s32 count, ...);
extern void AnimateActorBones(Rep2998Actor* actor);
extern f32 fn_800B4A94(Rep2998Actor* actor);
extern void fn_800B4AFC(Rep2998Actor* actor, u8 flag);
extern void fn_800B4BC8(Rep2998Actor* actor, s32 arg1);
extern void fn_800B4C04(Rep2998Actor* actor, f32 speed);
extern f32 fn_800B4C40(Rep2998Actor* actor);
extern void fn_800B4CA0(Rep2998Actor* actor, f32 frame);
extern void fn_800BDF70(Rep2998Model* model);
extern void fn_800BF058(void (*cb)(void* a, void* b));
extern void fn_8003A548(void (*cb)(void));

// rep_1D58.h is not included: it declares fn_3_B8184, fn_3_B828C, fn_3_B8414, fn_3_B8464 and
// fn_3_B98E8 with rep_1D58's stadium types, where this file passes its own. fn_3_B7F70 lies in
// unsplit code.
extern s16 fn_3_B7F70(s16 range);
extern s32 fn_3_B7FC8(u32 id, s32 arg1);
extern void fn_3_B8184(void* a, void* b);
extern void fn_3_B828C(void* obj);
extern void fn_3_B8414(void* a, void* b);
extern void fn_3_B8464(MtxPtr m, void* arg1);
extern void fn_3_B8574(void);
extern void fn_3_B939C(void);
extern void fn_3_B97DC(void* model, void* anim);
extern void fn_3_B98E8(Rep2998Model* model);
extern void fn_3_B9D68(u8* types, s32 count, void** files, s32* indices);

Rep2998Prop lbl_3_data_18ED0[11] = {
    { { -18.0f, 0.0f, 52.0f }, 0.0f, 0, 1, 1, 0, 0.0f, 360.0f },
    { { -35.0f, 0.0f, 35.0f }, 0.0f, 0, 1, 2, 0, 315.0f, 180.0f },
    { { 35.0f, 0.0f, 35.0f }, 0.0f, 0, 1, 3, 0, 225.0f, 180.0f },
    { { 18.0f, 0.0f, 52.0f }, 0.0f, 0, 1, 4, 0, 0.0f, 360.0f },
    { { 34.0f, 0.0f, 78.0f }, 0.0f, 0, 1, 5, 0, 0.0f, 360.0f },
    { { -34.0f, 0.0f, 78.0f }, 0.0f, 0, 1, 6, 0, 0.0f, 360.0f },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 2, 0, 0xFF, 0, 0.0f, 0.0f },
};
u8 lbl_3_data_19004[14] = { 1, 3, 4, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 };

static inline void playSound(s32 sound) {
    u32 stadium = g_d_GameSettings.StadiumID;
    SND_VOICEID voice;
    u8 vol;

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

// MWCC lays out .bss statics in reverse order of declaration
static void* lbl_3_bss_AE18[14];
static u8 lbl_3_bss_AE14;
static u8 lbl_3_bss_AE13;
static u8 lbl_3_bss_AE12;
static u8 lbl_3_bss_AE11;
static u8 lbl_3_bss_AE10;
static s32 lbl_3_bss_AE0C;
static s32 lbl_3_bss_AE08;
static s32 lbl_3_bss_AE04;
static u8 lbl_3_bss_AE01;
static u8 lbl_3_bss_AE00;

// .text:0x000E4FC4 size:0x8B8 mapped:0x80724058
// 96.99%: the target copies entry to r16 at the loop top for the inlined fn_3_E4658 and fn_3_E4554
// and spills a constant's address (frame 0x90, here 0x80). Passing them entry gives that frame and
// spill but keeps entry itself in a saved register (95.42%); every copy of it is propagated away.
void fn_3_E4FC4(void** files) {
    Vec unused = { 0.0f, 3.6f, -2.0f };
    GameInitVariables* settings;
    Rep2998Obj* draw;
    Rep2998Obj* entry;
    Rep2998Prop* prop;
    Rep2998Model* model;
    s32* indices;
    s32 count;
    s32 i;
    u8 end;
    u8 n;
    u8 j;
    u8 total;

    count = 0;
    end = FALSE;
    lbl_3_common_bss_350E4._18 = fn_3_B939C;
    lbl_3_common_bss_350E4._1C = fn_3_E1DB8;
    lbl_3_bss_AE10 = 0;
    indices = lbl_3_common_bss_350E4._34 = _OSAllocFromHeap(4, 14 * sizeof(s32));
    fn_3_B9D68(lbl_3_data_19004, 14, files, indices);

    prop = lbl_3_data_18ED0;
    n = 0;
    for (i = 0; i < 10; i++) {
        if (prop[i]._10 == 2) {
            break;
        }
        n++;
    }
    total = n;
    total++;
    lbl_8036E548._6C = ActorObjectInitTable(total);
    lbl_3_common_bss_350E4._6D = total;
    j = 0;
    for (i = 0; i < n; j++, i++) {
        fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[1]], NULL, files[indices[1] + 2]);
        fn_3_B98E8(&lbl_8036E548._6C->_34[i]);
    }
    for (i = 0; i < 1; j++, i++) {
        fn_800BDC88(lbl_8036E548._6C, j, j, files[indices[2]], NULL, NULL);
        fn_3_B97DC(&lbl_8036E548._6C->_34[j], files[indices[2] + 2]);
        model = &lbl_8036E548._6C->_34[j];
        model->_5C = 180.0f;
        model->_59 = 1;
        fn_800B4CA0(lbl_8036E548._6C->_34[j]._00, lbl_8036E548._6C->_34[j]._5C);
    }
    for (i = 0; i < 10; i++) {
        lbl_3_bss_AE18[i] = files[indices[i + 4]];
    }
    for (i = 0; i < total; i++) {
        fn_800BD548(&lbl_8036E548._6C->_34[i], 4, lbl_3_common_bss_350E4._20, lbl_3_common_bss_350E4._24,
                    lbl_3_common_bss_350E4._28, lbl_3_common_bss_350E4._2C);
    }

    lbl_3_common_bss_350E4._30 = 20;
    lbl_3_common_bss_350E4._00 = _OSAllocFromHeap(0x20, 20 * sizeof(Rep2998Obj));
    memset(lbl_3_common_bss_350E4._00, 0, 20 * sizeof(Rep2998Obj));
    lbl_3_common_bss_350E4._04 = _OSAllocFromHeap(0x20, 20 * sizeof(Rep2998Obj));
    memset(lbl_3_common_bss_350E4._04, 0, 20 * sizeof(Rep2998Obj));
    settings = &g_d_GameSettings;
    draw = lbl_3_common_bss_350E4._00;
    entry = draw;
    if (settings->GameModeSelected == GAME_TYPE_MINIGAMES) {
        lbl_3_common_bss_350E4._18 = NULL;
    } else {
        lbl_3_bss_AE13 = 0;
        for (i = 0; i < 10; i++, prop++) {
            if (prop->_10 == 2) {
                end = TRUE;
            }
            if (end) {
                for (; i < 11; i++) {
                    lbl_3_data_18ED0[i]._10 = 2;
                }
                break;
            }
            entry->_9C = i;
            entry->_9D = 0;
            entry->_9E = prop->_12;
            draw->_74 = &lbl_8036E548._6C->_34[i];
            draw->_78 = files[indices[3]];
            draw->_7C = fn_3_E3B88;
            draw->_80 = fn_3_E2118;
            draw->_90_7 = 1;
            draw->_90_6 = draw->_90_7 && draw->_78 != NULL;
            draw->_9A = 1;
            fn_3_E4658(draw);
            fn_3_E4554(draw);
            draw->_90_5 = 0;
            draw->_92 = 0xFF;
            draw->_84 = fn_3_E22A4;
            draw->_8C = NULL;
            draw->_94 = 0;
            draw->_96 = -1;
            draw->_98 = 1;
            entry = ++draw;
            lbl_3_bss_AE14++;
            count++;
        }
    }
    lbl_3_bss_AE11 = count;
    entry->_9C = 0;
    entry->_9D = 1;
    entry->_9E = 0;
    draw->_74 = &lbl_8036E548._6C->_34[n];
    draw->_78 = NULL;
    draw->_7C = fn_3_E1FA8;
    draw->_80 = NULL;
    draw->_90_7 = 1;
    draw->_90_6 = 0;
    draw->_9A = 0;
    draw->control.type = 0;
    draw->_90_5 = 0;
    draw->_92 = 0xFF;
    draw->_84 = NULL;
    draw->_8C = NULL;
    draw->_94 = 0;
    draw->_96 = -1;
    draw->_98 = 1;
    entry = ++draw;
    lbl_3_bss_AE12++;
    count++;
    lbl_3_common_bss_350E4._30 = count;
    if (lbl_3_common_bss_350E4._30 > count) {
        for (i = count; i < lbl_3_common_bss_350E4._30; i++) {
            entry->_9D = 0;
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
    lbl_3_common_bss_350E4._48 = NULL;
    if (settings->GameModeSelected != GAME_TYPE_MINIGAMES) {
        fn_3_E4EF4();
    }
}

// .text:0x000E4EF4 size:0xD0 mapped:0x80723F88
void fn_3_E4EF4(void) {
    Rep2998Common* common = &lbl_3_common_bss_350E4;
    s32 count;
    s32 idx;
    u32 size = common->_30 * 2 + common->_30 * 4 + common->_30 * 4 + common->_30 * 2 * 12;

    if (common->_48 == NULL) {
        common->_48 = _OSAllocFromHeap(4, size);
        lbl_3_common_bss_350E4._3C = (u32*)(common->_48 + common->_30 * 2);
        lbl_3_common_bss_350E4._44 = lbl_3_common_bss_350E4._3C + common->_30;
        lbl_3_common_bss_350E4._40 = (u16*)(lbl_3_common_bss_350E4._44 + common->_30);
    }
    memset(common->_48, 0, size);
    count = 0;
    idx = 0;
    fn_3_E4CB0(&count, &idx);
    lbl_3_common_bss_350E4._64 = count;
}

// .text:0x000E4CB0 size:0x244 mapped:0x80723D44
void fn_3_E4CB0(s32* count, s32* objIdx) {
    Control control;
    Mtx m;
    Vec pos;
    Rep2998Obj* obj;
    s32 slot;
    s32 i;
    s32 j;

    for (i = 0; i < 10; i++) {
        slot = lbl_3_common_bss_350E4._40[*count] =
            lbl_3_common_bss_350E4._40[*count - 1] + lbl_3_common_bss_350E4._3C[*count - 1];
        fn_3_B8574();
        for (j = 0; j < 10; j++) {
            if (i != lbl_3_data_18ED0[j]._12 || lbl_3_data_18ED0[j]._10 == 2) {
                continue;
            }
            if (lbl_3_common_bss_350E4._00[*objIdx]._90_6) {
                lbl_3_common_bss_350E4._44[slot] = *objIdx;
                slot++;
                lbl_3_common_bss_350E4._3C[*count]++;
                obj = &lbl_3_common_bss_350E4._00[*objIdx];
                control = obj->control;
                CTRLGetTranslation(&control, &pos.x, &pos.y, &pos.z);
                CTRLSetTranslation(&control, pos.x - 4.0, pos.y, pos.z - 4.0);
                CTRLBuildMatrix(&control, m);
                fn_3_B8464(m, obj->_78);
                CTRLSetTranslation(&control, 4.0 + pos.x, pos.y - 10.0, 4.0 + pos.z);
                CTRLBuildMatrix(&control, m);
                fn_3_B8464(m, obj->_78);
                (*objIdx)++;
            }
        }
        if (lbl_3_common_bss_350E4._3C[*count] != 0) {
            fn_3_B8414(&lbl_3_common_bss_350E4._48[*count * 2], &lbl_3_common_bss_350E4._48[*count * 2 + 1]);
            (*count)++;
        }
    }
}

// .text:0x000E4BE8 size:0xC8 mapped:0x80723C7C
struct StadiumObjectCollision* fn_3_E4BE8(s32 idx, Mtx mtx) {
    Rep2998Obj* obj = &lbl_3_common_bss_350E4._00[idx];
    Mtx bone;

    CTRLBuildMatrix(&lbl_3_common_bss_350E4._00[idx].control, mtx);
    if (obj->_9D == 0) {
        if (obj->_C8 == 0 || obj->_C4 == 0 || obj->_C4 == 5 || obj->_C4 == 4) {
            return NULL;
        }
        PSMTXCopy(obj->_74->_00->_18[16]->_EC, bone);
        PSMTXConcat(mtx, bone, mtx);
    }
    return lbl_3_common_bss_350E4._00[idx]._78;
}

// .text:0x000E4A38 size:0x1B0 mapped:0x80723ACC
void fn_3_E4A38(MtxPtr mtx, Rep2998Mesh* mesh) {
    Vec v;
    Vec out;
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxX;
    f32 maxY;
    f32 maxZ;
    u32 n;
    u8* p;

    minX = 10000.0f;
    minY = 10000.0f;
    minZ = 10000.0f;
    maxX = -10000.0f;
    maxY = -10000.0f;
    maxZ = -10000.0f;
    p = mesh->_08;
    for (;;) {
        if (((Rep2998MeshHeader*)p)->_02 == 0) {
            break;
        }
        n = ((Rep2998MeshHeader*)p)->_01 ? ((Rep2998MeshHeader*)p)->_02 + 2 : ((Rep2998MeshHeader*)p)->_02 * 3;
        p += sizeof(Rep2998MeshHeader);
        do {
            if (!lbl_3_bss_AE01) {
                PSMTXMultVec(mtx, &((Rep2998MeshVertex*)p)->_00, &v);
            } else {
                PSVECScale(&((Rep2998MeshVertex*)p)->_00, 1.0f, &v);
            }
            p += sizeof(Rep2998MeshVertex);
            if (minX > v.x) {
                minX = v.x;
            }
            if (minY > v.y) {
                minY = v.y;
            }
            if (minZ > v.z) {
                minZ = v.z;
            }
            if (maxX < v.x) {
                maxX = v.x;
            }
            if (maxY < v.y) {
                maxY = v.y;
            }
            if (maxZ < v.z) {
                maxZ = v.z;
            }
        } while (--n != 0);
    }
    PSVECScale((Vec*)&g_Ball.AtBat_Contact_BallPos, 1.0f, &out);
}

// .text:0x000E48D0 size:0x168 mapped:0x80723964
void fn_3_E48D0(Rep2998Obj* obj) {
    fn_3_E4658(obj);
    fn_3_E4554(obj);
    obj->_C5 = 0;
    obj->_C4 = 0;
    obj->_C7 = 0;
    obj->_C8 = 0;
    if (obj->_CA) {
        fn_3_65F4();
        obj->_CA = 0;
        obj->_C0 = 0.0f;
    }
}

// .text:0x000E4760 size:0x170 mapped:0x807237F4
void fn_3_E4760(Rep2998Obj* obj) {
    fn_3_E48D0(obj);
    obj->_C9 = 0;
}

// .text:0x000E4658 size:0x108 mapped:0x807236EC
void fn_3_E4658(Rep2998Obj* obj) {
    obj->control.type = 0;
    CTRLSetTranslation(&obj->control, lbl_3_data_18ED0[obj->_9C]._00.x, 0.24f + lbl_3_data_18ED0[obj->_9C]._00.y,
                       lbl_3_data_18ED0[obj->_9C]._00.z);
    PSVECScale(&lbl_3_data_18ED0[obj->_9C]._00, 1.0f, &obj->_A0);
    obj->_A0.y -= 0.24f;
    fn_3_E45F0(obj);
    fn_3_E45A8(obj);
}

// .text:0x000E45F0 size:0x68 mapped:0x80723684
void fn_3_E45F0(Rep2998Obj* obj) {
    CTRLSetRotation(&obj->control, 0.0f, lbl_3_data_18ED0[obj->_9C]._0C, 0.0f);
    obj->_B0 = lbl_3_data_18ED0[obj->_9C]._0C;
}

// .text:0x000E45A8 size:0x48 mapped:0x8072363C
void fn_3_E45A8(Rep2998Obj* obj) {
    CTRLSetScale(&obj->control, 0.2f, 0.2f, 0.2f);
    obj->_B4 = 0.2f;
}

// .text:0x000E4554 size:0x54 mapped:0x807235E8
void fn_3_E4554(Rep2998Obj* obj) {
    fn_3_E25D0(obj, 0);
}

// .text:0x000E3B88 size:0x9CC mapped:0x80722C1C
void fn_3_E3B88(Rep2998Obj* obj) {
    if (g_GameLogic.gameStatus != GAME_STATUS_LIVE_BALL) {
        if (obj->_C4 != 0) {
            fn_3_E48D0(obj);
        } else if (obj->_C7 != 0) {
            fn_3_E45F0(obj);
            fn_3_E4554(obj);
            if (obj->_CA) {
                fn_3_65F4();
                obj->_CA = 0;
                obj->_C0 = 0.0f;
            }
            obj->_C7 = 0;
        }
    } else {
        if (obj->_CA) {
            Mtx bone;
            Mtx m;
            Vec pos = { 0.0f, 0.0f, 0.0f };

            PSMTXCopy(obj->_74->_00->_18[17]->_EC, bone);
            CTRLBuildMatrix(&obj->control, m);
            PSMTXConcat(m, bone, m);
            PSMTXMultVec(m, &pos, &pos);
            pos.y *= -1.0f;
            g_Ball.AtBat_Contact_BallPos.x = pos.x;
            g_Ball.AtBat_Contact_BallPos.y = pos.y;
            g_Ball.AtBat_Contact_BallPos.z = pos.z;
        }
        if (g_Ball.AtBat_ContactResult >= 2 && obj->_C4 != 0 && obj->_C4 != 5) {
            obj->_C4 = 5;
            if (obj->_CB != 1) {
                fn_3_E25D0(obj, 9);
            } else {
                fn_800B4BC8(obj->_74->_00, 0);
            }
        }
        switch (obj->_C4) {
        case 0:
            fn_3_E3914(obj);
            break;
        case 1:
            fn_3_E3764(obj);
            break;
        case 2:
            fn_3_E3668(obj);
            break;
        case 3:
            fn_3_E3044(obj);
            break;
        case 4:
            fn_3_E2F4C(obj);
            break;
        case 5:
            fn_3_E2E78(obj);
            break;
        }
    }
    fn_3_E266C(obj);
    if (obj->_C4 != 0 && obj->_C4 < 5 && obj->_C8 == 0) {
        fn_3_E2324(obj);
    }
}

// .text:0x000E3914 size:0x274 mapped:0x807229A8
void fn_3_E3914(Rep2998Obj* obj) {
    static const u8 counts[3] = { 20, 20, 20 };
    Vec pos;
    Vec d;
    u8 swing;

    if (obj->_C7 != 0) {
        return;
    }
    if (g_Ball.AtBat_ContactResult >= 2) {
        return;
    }
    if (g_Ball.AtBat_Contact_BallPos.y > 11.0) {
        return;
    }
    pos = obj->_A0;
    pos.y += 1.4000000000000001;
    PSVECSubtract((Vec*)&g_Ball.AtBat_Contact_BallPos, &pos, &d);
    d.y = 0.0f;
    if (PSVECMag(&d) <= 12.5) {
        swing = g_Ball.currentStarSwing2;
        if (!((swing == 3) | (swing == 4) | (swing == 11) | (swing == 12))) {
            obj->_C4 = 1;
            fn_3_E25D0(obj, 1);
            if (obj->_C9 == 0) {
                obj->_C8 = fn_3_B7F70(100) / 70;
            } else {
                obj->_C8 = 0;
            }
            obj->_C5 = 0;
            obj->_C6 = counts[fn_3_B7F70(3)];
            obj->_C7 = 1;
            playSound(3);
        }
    }
}

// .text:0x000E3764 size:0x1B0 mapped:0x807227F8
void fn_3_E3764(Rep2998Obj* obj) {
    obj->_C5++;
    obj->_B4 += 1.0857142857142859 / obj->_C6;
    CTRLSetScale(&obj->control, obj->_B4, obj->_B4, obj->_B4);
    obj->_A0.y = -(1.2 * obj->_B4);
    CTRLSetTranslation(&obj->control, obj->_A0.x, -obj->_A0.y, obj->_A0.z);
    if (fn_3_E2B70(obj)) {
        if (fn_3_E3284(obj)) {
            return;
        }
    } else {
        fn_3_E2034(obj);
    }
    if (obj->_C5 >= obj->_C6) {
        obj->_C4 = 2;
    }
}

// .text:0x000E3668 size:0xFC mapped:0x807226FC
void fn_3_E3668(Rep2998Obj* obj) {
    if (fn_3_E2B70(obj)) {
        fn_3_E3284(obj);
    } else {
        fn_3_E2034(obj);
    }
}

// .text:0x000E3284 size:0x3E4 mapped:0x80722318
u8 fn_3_E3284(Rep2998Obj* obj) {
    Mtx m;
    Mtx bone;
    Vec pos = { 0.0f, 0.0f, 0.0f };
    Vec down = { 0.0f, -1.0f, 0.0f };
    Vec cross;
    Vec a;
    Vec b;
    f32 limit;
    f32 angle;
    f32 base;
    f32 rad;

    PSMTXCopy(obj->_74->_00->_18[16]->_EC, bone);
    CTRLBuildMatrix(&obj->control, m);
    PSMTXConcat(m, bone, m);
    PSMTXMultVec(m, &pos, &pos);
    pos.y *= -1.0f;
    limit = 2.2f * obj->_B4;
    if (FABS(fn_3_9EFD0(&g_Ball.pastCoordinates[0], &g_Ball.AtBat_Contact_BallPos, (VecXYZ*)&pos, NULL)) <= limit) {
        obj->_C4 = 3;
        fn_3_E25D0(obj, 7);
        obj->_CA = 1;
        fn_3_6620();
        base = lbl_3_data_18ED0[obj->_9C]._14;
        obj->_BC = base + fn_3_B7F70((u32)(10.0f * lbl_3_data_18ED0[obj->_9C]._18)) / 10.0;
        g_Ball.physicsSubstruct.velocity.x = g_Ball.physicsSubstruct.velocity.y = g_Ball.physicsSubstruct.velocity.z =
            0.0f;
        a.x = sin(-(0.017453292f * obj->_B0));
        a.y = 0.0f;
        a.z = -(f32)cos(-(0.017453292f * obj->_B0));
        b.x = sin(0.017453292f * obj->_BC);
        b.y = 0.0f;
        b.z = -(f32)cos(0.017453292f * obj->_BC);
        PSVECNormalize(&a, &a);
        PSVECNormalize(&b, &b);
        rad = acos(PSVECDotProduct(&a, &b));
        angle = rad;
        if (angle) {
            PSVECCrossProduct(&a, &b, &cross);
            if (!(PSVECDotProduct(&cross, &down) > 0.0f)) {
                angle *= -1.0f;
            }
        }
        obj->_C0 = -(57.29578f * (angle / 60.0f));
        playSound(0);
        return TRUE;
    }
    return FALSE;
}

// .text:0x000E3044 size:0x240 mapped:0x807220D8
void fn_3_E3044(Rep2998Obj* obj) {
    f32 speed = obj->_74->_54;
    f32 angle;
    f32 x;
    f32 z;

    if (obj->_CB == 7) {
        obj->_B0 += obj->_C0;
        CTRLSetRotation(&obj->control, 0.0f, obj->_B0, 0.0f);
    } else if (obj->_B8 >= 20.0 && obj->_B8 - speed < 20.0) {
        angle = obj->_BC;
        angle = 0.017453292f * angle;
        x = obj->_B4 * (5.0 * sinf_kludge(angle)) + obj->_A0.x;
        z = obj->_B4 * (-5.0 * cosf_kludge(angle)) + obj->_A0.z;
        g_Ball.AtBat_Contact_BallPos.x = x;
        g_Ball.AtBat_Contact_BallPos.y = 2.0 * obj->_B4;
        g_Ball.AtBat_Contact_BallPos.z = z;
        g_Ball.physicsSubstruct.velocity.x = 0.1 * sinf_kludge(angle);
        g_Ball.physicsSubstruct.velocity.y = 0.0f;
        g_Ball.physicsSubstruct.velocity.z = 0.1 * -cosf_kludge(angle);
        fn_3_65F4();
        obj->_CA = 0;
        playSound(1);
    }
}

// .text:0x000E2F4C size:0xF8 mapped:0x80721FE0
void fn_3_E2F4C(Rep2998Obj* obj) {
    f32 speed = obj->_74->_54;
    f32 angle;
    f32 x;

    if (obj->_B8 >= 20.0 && obj->_B8 - speed < 20.0 && gameInitOptions.starSkillsSetting) {
        angle = -obj->_B0;
        angle = 0.017453292f * angle;
        x = obj->_B4 * (5.0 * sinf_kludge(angle)) + obj->_A0.x;
        fn_3_CB7E8(x, -2.0 * obj->_B4, obj->_B4 * (-5.0 * cosf_kludge(angle)) + obj->_A0.z);
    }
}

// .text:0x000E2E78 size:0xD4 mapped:0x80721F0C
void fn_3_E2E78(Rep2998Obj* obj) {
    if (obj->_C5 == 0) {
        obj->_C8 = 0;
        obj->_C4 = 0;
    } else {
        obj->_B4 -= 1.0857142857142859 / obj->_C6;
        obj->_A0.y = -(1.2 * obj->_B4);
        CTRLSetTranslation(&obj->control, obj->_A0.x, -obj->_A0.y, obj->_A0.z);
        CTRLSetScale(&obj->control, obj->_B4, obj->_B4, obj->_B4);
        obj->_C5--;
    }
}

// .text:0x000E2B70 size:0x308 mapped:0x80721C04
u8 fn_3_E2B70(Rep2998Obj* obj) {
    Vec d;

    if (g_Ball.AtBat_ContactResult >= 2) {
        return FALSE;
    }
    if (obj->_C8) {
        return FALSE;
    }
    if (g_Ball.deadBallReason == 1 || g_Ball.deadBallReason == 3) {
        return FALSE;
    }
    if (obj->_CB >= 4 && obj->_CB <= 6) {
        return TRUE;
    }
    PSVECSubtract((Vec*)&g_Ball.AtBat_Contact_BallPos, (Vec*)&g_Ball.pastCoordinates[0], &d);
    if (PSVECMag(&d) != 0.0f) {
        return fn_3_E29B4(obj);
    }
    return fn_3_E28DC(obj);
}

// .text:0x000E29B4 size:0x1BC mapped:0x80721A48
u8 fn_3_E29B4(Rep2998Obj* obj) {
    static const f32 speeds[3] = { 0.8f, 1.0f, 1.2f };
    Vec pos = obj->_A0;
    Vec d;
    Rep2998Model* model;
    f32 speed;

    PSVECSubtract((Vec*)&g_Ball.AtBat_Contact_BallPos, &pos, &d);
    d.y = 0.0f;
    if (5.5 * obj->_B4 > PSVECMag(&d) && g_Ball.AtBat_Contact_BallPos.y >= 1.5 * obj->_B4 &&
        g_Ball.AtBat_Contact_BallPos.y <= 8.5 * obj->_B4) {
        if (g_Ball.AtBat_Contact_BallPos.y < 5.0 * obj->_B4) {
            fn_3_E25D0(obj, 4);
        } else {
            fn_3_E25D0(obj, 5);
        }
        speed = speeds[fn_3_B7F70(3)];
        model = obj->_74;
        model->_54 = speed;
        model->_5A = 1;
        fn_800B4C04(obj->_74->_00, obj->_74->_54);
        return TRUE;
    }
    return FALSE;
}

// .text:0x000E28DC size:0xD8 mapped:0x80721970
u8 fn_3_E28DC(Rep2998Obj* obj) {
    Vec pos = obj->_A0;
    Vec d;

    PSVECSubtract((Vec*)&g_Ball.AtBat_Contact_BallPos, &pos, &d);
    d.y = 0.0f;
    if (2.5 >= PSVECMag(&d)) {
        fn_3_E25D0(obj, 6);
        return TRUE;
    }
    return FALSE;
}

// .text:0x000E266C size:0x270 mapped:0x80721700
void fn_3_E266C(Rep2998Obj* obj) {
    Rep2998Model* model = obj->_74;

    if (obj->_AC == NULL) {
        return;
    }
    if (!(model->_5B & 1) && !fn_800B4A94(model->_00)) {
        switch (obj->_CB) {
        case 1:
            if (obj->_C4 == 5 || obj->_C4 == 0) {
                fn_3_E25D0(obj, 0);
                break;
            }
        case 4:
        case 5:
            if (obj->_C8 == 0) {
                fn_3_E25D0(obj, 2);
            } else {
                fn_3_E25D0(obj, 3);
            }
            break;
        case 7:
            obj->_B0 = -obj->_BC;
            fn_3_E25D0(obj, 8);
            CTRLSetRotation(&obj->control, 0.0f, obj->_B0, 0.0f);
            break;
        case 8:
            fn_3_E25D0(obj, 9);
            obj->_C4 = 5;
            break;
        case 6:
        default:
            fn_3_E25D0(obj, 0);
            break;
        }
    }
    AnimateActorBones(model->_00);
    obj->_B8 = fn_800B4C40(model->_00);
}

// .text:0x000E25D0 size:0x9C mapped:0x80721664
void fn_3_E25D0(Rep2998Obj* obj, u32 anim) {
    obj->_AC = lbl_3_bss_AE18[anim];
    fn_3_B97DC(obj->_74, obj->_AC);
    if (anim != 0 && anim != 2 && anim != 3) {
        obj->_74->_5B = 2;
        fn_800B4AFC(obj->_74->_00, obj->_74->_5B & 1);
    }
    obj->_B8 = obj->_74->_5C;
    obj->_CB = anim;
}

// .text:0x000E2324 size:0x2AC mapped:0x807213B8
void fn_3_E2324(Rep2998Obj* obj) {
    Mtx bone;
    Mtx m;
    Vec fielderPos;
    Vec d;
    Vec dir;
    u8 fielders[7] = { 2, 3, 4, 5, 6, 7, 8 };
    Vec pos = { 0.0f, 0.0f, 0.0f };
    Vec down = { 0.0f, -1.0f, 0.0f };
    f32 limit;
    u32 i;
    Rep2998Fielder* fielder;

    if (obj->_CA) {
        return;
    }
    PSMTXCopy(obj->_74->_00->_18[16]->_EC, bone);
    CTRLBuildMatrix(&obj->control, m);
    PSMTXConcat(m, bone, m);
    PSMTXMultVec(m, &pos, &pos);
    pos.y *= -1.0f;
    limit = 2.2f * obj->_B4;
    for (i = 0; i < 7; i++) {
        fielder = &g_Fielders[fielders[i]];
        if (fielder->_210 == 0) {
            fielderPos.x = fielder->_000.x;
            fielderPos.y = 1.5f;
            fielderPos.z = fielder->_000.z;
            PSVECSubtract(&pos, &fielderPos, &d);
            dir.x = d.x;
            dir.y = 0.0f;
            dir.z = d.z;
            PSVECNormalize(&dir, &dir);
            if (PSVECMag(&d) <= limit) {
                fn_3_253A4(fielders[i], fn_3_9FB8C(dir.x, dir.z));
                if (obj->_CB != 8 && obj->_CA == 0) {
                    fn_3_E25D0(obj, 9);
                    obj->_C4 = 5;
                }
                playSound(4);
            }
        }
    }
}

// .text:0x000E22A4 size:0x80 mapped:0x80721338
void fn_3_E22A4(Rep2998Obj* obj) {
    DisplayStateList* state = obj->_74->_00->pal->descriptorArray[0].layout->displayData->displayStateList;
    u8 value;

    state->setting &= ~0x1FFF;
    if (obj->_C4 != 0) {
        value = obj->_C8 + 1;
        if (obj->_C4 == 1 || obj->_C4 == 5) {
            if (obj->_C5 % 2 == 0) {
                value = 0;
            }
        }
        state->setting |= value;
    }
}

// .text:0x000E2118 size:0x18C mapped:0x807211AC
void fn_3_E2118(u32 idx) {
    Rep2998Obj* obj = &lbl_3_common_bss_350E4._00[idx];

    if (obj->_C4 == 0 || obj->_C4 == 5) {
        return;
    }
    if (obj->_C8 != 0 && obj->_C4 != 4) {
        if (g_Ball.AtBat_ContactResult > 1) {
            return;
        }
        obj->_C9 = 1;
        obj->_C4 = 4;
        fn_3_E25D0(obj, 8);
        playSound(2);
    }
    fn_3_65A8();
    fn_3_27648();
    g_FieldingLogic._13B = 1;
}

// .text:0x000E2034 size:0xE4 mapped:0x807210C8
void fn_3_E2034(Rep2998Obj* obj) {
    Vec d;
    Vec fwd = { 0.0f, 0.0f, -1.0f };
    f32 angle;

    PSVECSubtract((Vec*)&g_Ball.AtBat_Contact_BallPos, &obj->_A0, &d);
    d.y = 0.0f;
    PSVECNormalize(&d, &d);
    PSVECNormalize(&fwd, &fwd);
    angle = 57.29578f * (f32)acos(PSVECDotProduct(&d, &fwd));
    if (d.x < 0.0f) {
        angle = 360.0f - angle;
    }
    obj->_B0 = -angle;
    CTRLSetRotation(&obj->control, 0.0f, obj->_B0, 0.0f);
}

// .text:0x000E1FA8 size:0x8C mapped:0x8072103C
void fn_3_E1FA8(Rep2998Obj* obj) {
    Rep2998Model* model = obj->_74;
    Rep2998Actor* actor = model->_00;

    if (model->_5C + model->_54 > 900.0f) {
        model->_5C = 180.0f;
        model->_59 = 1;
        fn_800B4CA0(actor, model->_5C);
    }
    AnimateActorBones(actor);
    model->_5C += model->_54;
}

// .text:0x000E1DB8 size:0x1F0 mapped:0x80720E4C
void fn_3_E1DB8(void) {
    if (g_GameLogic.gameStatus == GAME_STATUS_MINIGAME_READY) {
        return;
    }
    if (g_GameLogic.gameStatus == GAME_STATUS_PAUSED) {
        if (lbl_3_bss_AE10) {
            fn_3_8B890(lbl_3_bss_AE04);
            lbl_3_bss_AE10 = 0;
        }
        return;
    }
    if (!lbl_3_bss_AE10) {
        lbl_3_bss_AE04 = fn_3_8BBC4(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 5, NULL, NULL, 6);
        lbl_3_bss_AE10 = 1;
        lbl_3_bss_AE0C = rand() % 900 + 100;
        lbl_3_bss_AE08 = rand() % 900 + 100;
    }
    if (lbl_3_bss_AE0C <= 0) {
        fn_3_B7FC8(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 6, 7);
        lbl_3_bss_AE0C = rand() % 900 + 100;
    } else {
        lbl_3_bss_AE0C--;
    }
    if (lbl_3_bss_AE08 <= 0) {
        fn_3_B7FC8(lbl_3_data_81DC[g_d_GameSettings.StadiumID] + 7, 7);
        lbl_3_bss_AE08 = rand() % 900 + 100;
    } else {
        lbl_3_bss_AE08--;
    }
}

// .text:0x000E1D00 size:0xB8 mapped:0x80720D94
void fn_3_E1D00(void) {
    Rep2998Obj* obj;
    s32 i;

    fn_800BF058(fn_3_B8184);
    fn_8003A548(fn_3_E1C60);
    for (i = 0; i < lbl_3_common_bss_350E4._30; i++) {
        if (lbl_3_data_18ED0[i]._10 == 2) {
            break;
        }
        obj = &lbl_3_common_bss_350E4._00[i];
        fn_3_B828C(obj);
        if (obj->_74 != NULL) {
            obj->_74->_00->_98 = obj->_93 | 6;
            fn_800BDF70(obj->_74);
        }
    }
    fn_8003A548(NULL);
}

// .text:0x000E1C60 size:0xA0 mapped:0x80720CF4
void fn_3_E1C60(void) {
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_A2, GX_CC_RASC);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_TEXA);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
}
