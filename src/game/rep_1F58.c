#include "game/rep_1F58.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct {
    /* 0x00 */ s16 id; // actor index, -1 when free
    /* 0x02 */ s16 timer;
    /* 0x04 */ VecXYZ _04;
    /* 0x10 */ VecXYZ _10;
    /* 0x1C */ f32 _1C;
} UnkSlot; // size: 0x20

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0x1C - 0x04];
    /* 0x1C */ s32 _1C;
    /* 0x20 */ u8 _20[0x40 - 0x20];
} UnkSlotParams; // size: 0x40

typedef struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u16 _12;
    /* 0x14 */ u32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ u8 _20;
} UnkTrailTask;

typedef struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
} UnkFadeTask;

typedef struct {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ VecXYZ _034;
    /* 0x040 */ u8 _040[0x5C - 0x40];
    /* 0x05C */ void* _05C;
    /* 0x060 */ u8 _060[0x252 - 0x60];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ s8 _254;
} UnkActor1F58;

typedef struct {
    /* 0x00 */ u8 _00[0x98];
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
} UnkModel1F58;

typedef struct {
    /* 0x00 */ UnkModel1F58* _00;
} UnkModelRef1F58;

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ UnkModelRef1F58 _34;
} UnkObject1F58;

typedef struct Rep1F58Effect {
    /* 0x00 */ u32 _00;
    /* 0x04 */ void (*callback)(struct Rep1F58Effect* effect);
    /* 0x08 */ VecXYZ pos;
    /* 0x14 */ u32 frame;
} Rep1F58Effect; // size: 0x18

typedef struct {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ u8 _08[0xC - 0x8];
    /* 0x0C */ s16 _0C;
    /* 0x0E */ u8 _0E[0x18 - 0xE];
    /* 0x18 */ u16 _18;
    /* 0x1A */ u8 _1A[0x20 - 0x1A];
    /* 0x20 */ u32 _20;
    /* 0x24 */ u8 _24[0x5C - 0x24];
} UnkAnim1F58; // size: 0x5C

typedef struct {
    /* 0x00 */ u8 _00[0x40];
    /* 0x40 */ Mtx _40;
} UnkCamera1F58;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ UnkActor1F58* _2C50[13];
} lbl_8036E548;

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ s32 _004;
    /* 0x008 */ u8 _008[0x10 - 0x8];
    /* 0x010 */ UnkObject1F58* _010;
    /* 0x014 */ u8 _014[0x20 - 0x14];
    /* 0x020 */ UnkAnim1F58 _020[2];
    /* 0x0D8 */ u8 _0D8[0x3AC - 0xD8];
    /* 0x3AC */ u32 _3AC;
    /* 0x3B0 */ u8 _3B0[0x434 - 0x3B0];
    /* 0x434 */ VecXYZ _434;
    /* 0x440 */ u8 _440[0x467 - 0x440];
    /* 0x467 */ u8 _467;
    /* 0x468 */ u8 _468[0x477 - 0x468];
    /* 0x477 */ u8 _477[2];
} lbl_3_common_bss_35154;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern u8 lbl_803CBBC0;
extern void* lbl_803CC1B8;

// This unit's .data (0x17248 to 0x17508) lies outside its ranges in splits.txt
extern struct {
    /* 0x0 */ u8 _0[2];
    /* 0x4 */ f32 _4[3];
} lbl_3_data_17248;
extern u8 lbl_3_data_17258[2][3];
extern struct {
    /* 0x000 */ UnkSlot slots[2];
    /* 0x040 */ s32 _040;
    /* 0x044 */ s32 _044;
    /* 0x048 */ s32 _048;
    /* 0x04C */ UnkSlotParams _04C;
    /* 0x08C */ s32 _08C[54][2];
    /* 0x23C */ f32 _23C;
} lbl_3_data_17260;
extern UnkTrailTask* lbl_3_data_174A0[2];
extern Rep1F58Effect lbl_3_data_174A8[2][2];

extern UnkActor1F58* fn_80011570(void);
extern s32 fn_8005268C(void);
extern UnkCamera1F58* fn_80052734(s32);
extern void fn_80024DB0(UnkAnim1F58*);
extern void fn_80024FA4(UnkModelRef1F58*, u32, UnkAnim1F58*, s32);
extern void fn_80027674(VecXYZ*, VecXYZ*, UnkSlotParams*, f32, u8);
extern void fn_80027918(u8, f32);
extern void fn_800A7D4C(s32, void*);
extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B4C04(UnkModel1F58*, f32);
extern void fn_800B4CA0(UnkModel1F58*, f32);
extern void fn_800BDA24(UnkModelRef1F58*);
extern void fn_800BDA94(UnkModelRef1F58*, Mtx);

// MWCC lays out these statics in reverse order of declaration
static u8 lbl_3_bss_9D40[0x40] ATTRIBUTE_ALIGN(32);
static GXTexObj lbl_3_bss_9D20;

// .text:0x000C1930 size:0x34 mapped:0x807009C4
// Outside this unit's .text range in splits.txt, but inlined into most functions here;
// static inline until the split moves, so this object has no extra function
static inline s32 fn_3_C1930(s32 id) {
    s32 i = 1;

    do {
        if (id == lbl_3_data_17260.slots[i].id) {
            break;
        }
    } while (i-- != 0);
    return i;
}

// .text:0x000C1770 size:0x1C0 mapped:0x80700804
// The target reaches this unit's .data from one pooled base (lbl_3_data_17248 + offset); this
// matches once that data is in this unit's splits.txt range and defined here as statics
void fn_3_C1770(s32 idx) {
    UnkActor1F58* actor = lbl_8036E548._2C50[idx];
    s32 i;
    s32 ch;

    if (actor != NULL) {
        i = fn_3_C1930(-1);
        if (i >= 0) {
            lbl_3_data_17260._04C._00 = lbl_3_common_bss_35154._004;
            lbl_3_data_17260.slots[i].id = idx;
            lbl_3_data_17260.slots[i]._10.x = actor->_034.x;
            lbl_3_data_17260.slots[i]._10.z = actor->_034.z;
            lbl_3_data_17260.slots[i]._10.y = -(lbl_3_data_17260._08C[actor->_252][0] / 100000.0f);
            memcpy(&lbl_3_data_17260.slots[i]._04, &lbl_3_data_17260.slots[i]._10, sizeof(VecXYZ));
            lbl_3_data_17260.slots[i].timer = 0;
            ch = 0x18;
            if (i != 0) {
                ch = 0x17;
            }
            fn_80027918(ch, 0.0f);
            fn_3_C0F8C();
            lbl_3_common_bss_35154._477[i] = 0;
        }
    }
}

// .text:0x000C1344 size:0x42C mapped:0x807003D8
// Pooled .data base as in fn_3_C1770; with the data as statics, registers (the i * 0x20 offset
// takes r31, the target's slot register) and the scheduling around fn_80027674 still differ
void fn_3_C1344(s32 idx, f32 chargeUp, f32 chargeDown, BOOL full) {
    UnkActor1F58* actor;
    UnkSlot* slot;
    VecXYZ* pos;
    s32 i;
    s32 ch;

    if (lbl_80366158._28 != 0) {
        return;
    }
    actor = lbl_8036E548._2C50[idx];
    if (actor == NULL) {
        return;
    }
    i = fn_3_C1930(idx);
    if (i < 0) {
        return;
    }
    slot = &lbl_3_data_17260.slots[i];
    pos = &slot->_04;
    getAnimRelatedCoordinates(idx, 4, pos);
    if (chargeUp > 0.0f && chargeUp < lbl_3_data_17260._23C) {
        if (lbl_3_data_17260.slots[i].timer-- == 0) {
            lbl_3_data_17260.slots[i].timer = lbl_3_data_17260._04C._1C;
            {
                VecXYZ* to = &slot->_10;
                UnkSlotParams* params = &lbl_3_data_17260._04C;
                f32 scale = lbl_3_data_17260._040 / 100000.0f;

                ch = 0x18;
                if (i != 0) {
                    ch = 0x17;
                }
                fn_80027674(to, pos, params, scale, ch);
            }
            actor->_05C = fn_3_C0DD8;
        }
    }
    sin(chargeUp * lbl_3_data_17248._4[i] / 100.0f);
    if (chargeUp < 100.0f) {
        fn_3_C0D10(i, lbl_3_data_17258[i][0], lbl_3_data_17258[i][1], lbl_3_data_17258[i][2],
                   lbl_3_data_17248._0[i] * (0.5 * sin(chargeUp * lbl_3_data_17248._4[i] / 100.0f) + 0.5));
        lbl_3_data_17260.slots[i]._1C = chargeUp;
    } else {
        fn_3_C0D10(i, lbl_3_data_17258[i][0], lbl_3_data_17258[i][1], lbl_3_data_17258[i][2],
                   lbl_3_data_17248._0[i] * (0.5 * sin(chargeDown * lbl_3_data_17248._4[i] / 100.0f) + 0.5));
        lbl_3_data_17260.slots[i]._1C = chargeDown;
    }
    if (full && lbl_3_common_bss_35154._477[i] == 0) {
        lbl_3_common_bss_35154._477[i] = 1;
        fn_3_C0C4C(i);
    }
}

// .text:0x000C11CC size:0x178 mapped:0x80700260
// Pooled .data base as in fn_3_C1770; with the data as statics, the code is identical
void fn_3_C11CC(s32 idx, BOOL remove) {
    UnkActor1F58* actor;
    UnkFadeTask* task;
    s32 ch;
    s32 i = fn_3_C1930(idx);

    if (i >= 0) {
        if (remove) {
            actor = lbl_8036E548._2C50[idx];
            if (actor != NULL) {
                actor->_05C = NULL;
            }
            lbl_3_data_17260.slots[i].id = -1;
            ch = 0x18;
            if (i != 0) {
                ch = 0x17;
            }
            fn_80027918(ch, 0.0f);
        } else {
            task = fn_800B0A5C_insertQueue(fn_3_C1004, ((UnkFadeTask*)lbl_803CC1B8)->_12);
            task->_14 = idx;
            task->_15 = lbl_3_data_17248._0[i] *
                        (0.5 * sin(lbl_3_data_17248._4[i] * lbl_3_data_17260.slots[i]._1C / 100.0f) + 0.5);
            task->_16 = 10;
        }
    }
}

// .text:0x000C1004 size:0x1C8 mapped:0x80700098
// Registers only: the inlined fn_3_C0D10's row offset and bss + 1 swap r29 and r30
void fn_3_C1004(void) {
    UnkFadeTask* task = lbl_803CC1B8;
    UnkActor1F58* actor = lbl_8036E548._2C50[task->_14];
    s32 i = fn_3_C1930(task->_14);
    s32 ch;

    if (i >= 0) {
        if (--task->_16 == 0) {
            if (actor != NULL) {
                actor->_05C = NULL;
            }
            lbl_3_data_17260.slots[i].id = -1;
            fn_800B0A14_removeQueue();
        }
        fn_3_C0D10(i, lbl_3_data_17258[i][0], lbl_3_data_17258[i][1], lbl_3_data_17258[i][2],
                   task->_15 * task->_16 / 10);
        ch = 0x18;
        if (i != 0) {
            ch = 0x17;
        }
        fn_80027918(ch, task->_16 / 10.0f);
    }
}

// .text:0x000C0F8C size:0x78 mapped:0x80700020
void fn_3_C0F8C(void) {
    GXInitTexObj(&lbl_3_bss_9D20, lbl_3_bss_9D40, 4, 4, GX_TF_RGBA8, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&lbl_3_bss_9D20, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
}

// .text:0x000C0DD8 size:0x1B4 mapped:0x806FFE6C
void fn_3_C0DD8(void* arg0, s32* tevStage, s32* texCoord, s32* texMap, u8* arg4, u8* arg5) {
    Mtx mtx;
    s32 i = fn_3_C1930(fn_80011570()->_254);

    if (i >= 0) {
        GXLoadTexObj(&lbl_3_bss_9D20, *texMap);
        memset(mtx, 0, sizeof(Mtx));
        mtx[0][3] = 0.0f;
        mtx[1][3] = i;
        GXLoadTexMtxImm(mtx, *texMap * 3 + GX_TEXMTX0, GX_MTX2x4);
        GXSetTexCoordGen2(*texCoord, GX_TG_MTX2X4, GX_TG_TEX0, *texMap * 3 + GX_TEXMTX0, GX_FALSE, GX_PTIDENTITY);
        GXSetTevOrder(*tevStage, *texCoord, *texMap, GX_COLOR0A0);
        GXSetTevColorIn(*tevStage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_TEXA, GX_CC_CPREV);
        GXSetTevColorOp(*tevStage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(*tevStage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(*tevStage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        (*tevStage)++;
        (*texMap)++;
        (*arg5)++;
        (*arg4)++;
    }
}

// .text:0x000C0D10 size:0xC8 mapped:0x806FFDA4
void fn_3_C0D10(s32 idx, u8 r, u8 g, u8 b, u8 a) {
    s32 row = idx * 16;
    s32 row2;

    lbl_3_bss_9D40[row] = a;
    lbl_3_bss_9D40[row + 1] = r;
    *(u16*)&lbl_3_bss_9D40[row + 2] = *(u16*)&lbl_3_bss_9D40[row];
    *(u32*)&lbl_3_bss_9D40[row + 4] = *(u32*)&lbl_3_bss_9D40[row];
    memcpy(&lbl_3_bss_9D40[row + 8], &lbl_3_bss_9D40[row], 8);
    row2 = row + 0x20;
    lbl_3_bss_9D40[row2] = g;
    lbl_3_bss_9D40[row2 + 1] = b;
    *(u16*)&lbl_3_bss_9D40[row + 0x22] = *(u16*)&lbl_3_bss_9D40[row2];
    *(u32*)&lbl_3_bss_9D40[row + 0x24] = *(u32*)&lbl_3_bss_9D40[row2];
    memcpy(&lbl_3_bss_9D40[row + 0x28], &lbl_3_bss_9D40[row2], 8);
    DCStoreRange(lbl_3_bss_9D40, sizeof(lbl_3_bss_9D40));
}

// .text:0x000C0CE8 size:0x28 mapped:0x806FFD7C
void fn_3_C0CE8(int type, f32 x, f32 y, f32 z) {
    lbl_3_common_bss_35154._434.x = x;
    lbl_3_common_bss_35154._434.y = y;
    lbl_3_common_bss_35154._434.z = z;
    lbl_3_common_bss_35154._467 = type;
    lbl_3_common_bss_35154._3AC |= 0x100;
}

// .text:0x000C0C4C size:0x9C mapped:0x806FFCE0
void fn_3_C0C4C(s32 idx) {
    UnkTrailTask* task = fn_800B0A5C_insertQueue(fn_3_C0AD8, 1);

    task->_14 = 0;
    task->_1C = lbl_3_data_17260.slots[idx].id;
    task->_20 = 0;
    for (idx = 0; idx < 2; idx++) {
        if (lbl_3_data_174A0[idx] == NULL) {
            lbl_3_data_174A0[idx] = task;
            task->_18 = idx;
            break;
        }
    }
}

// .text:0x000C0AD8 size:0x174 mapped:0x806FFB6C
void fn_3_C0AD8(void) {
    UnkTrailTask* task = lbl_803CC1B8;
    UnkActor1F58* actor = lbl_8036E548._2C50[task->_1C];

    if (task->_20 == 0 && actor != NULL) {
        fn_800A7D4C(0, &lbl_3_data_174A8[task->_18][lbl_803CBBC0]);
        lbl_3_data_174A8[task->_18][lbl_803CBBC0].frame = task->_14;
        lbl_3_data_174A8[task->_18][lbl_803CBBC0].pos.x = actor->_034.x;
        lbl_3_data_174A8[task->_18][lbl_803CBBC0].pos.y = actor->_034.y;
        lbl_3_data_174A8[task->_18][lbl_803CBBC0].pos.z = actor->_034.z;
        if (lbl_80366158._28 == 0) {
            task->_14++;
        }
    } else {
        lbl_3_data_174A0[task->_18] = NULL;
        fn_800B0A14_removeQueue();
    }
    if (task->_14 >= lbl_3_common_bss_35154._020[0]._18) {
        lbl_3_data_174A0[task->_18] = NULL;
        fn_800B0A14_removeQueue();
    }
}

// .text:0x000C095C size:0x17C mapped:0x806FF9F0
void fn_3_C095C(Rep1F58Effect* effect) {
    Mtx mtx;
    u32 animIds[2];
    UnkAnim1F58* anims[2];
    UnkModelRef1F58* model = &lbl_3_common_bss_35154._010->_34;
    s32 i;

    animIds[0] = lbl_3_common_bss_35154._020[0]._20;
    anims[0] = &lbl_3_common_bss_35154._020[0];
    animIds[1] = lbl_3_common_bss_35154._020[1]._20;
    anims[1] = &lbl_3_common_bss_35154._020[1];
    PSMTXTrans(mtx, effect->pos.x, effect->pos.y, effect->pos.z);
    PSMTXConcat(fn_80052734(fn_8005268C())->_40, mtx, mtx);
    i = 1;
    do {
        anims[i]->_00 = 0.0f;
        anims[i]->_0C = 0;
        anims[i]->_04 = effect->frame;
        fn_80024DB0(anims[i]);
        fn_80024FA4(model, animIds[i], anims[i], -1);
    } while (i-- != 0);
    model->_00->_99 = 1;
    fn_800B4CA0(model->_00, effect->frame);
    fn_800B4C04(model->_00, 1.0f);
    fn_800BDA24(model);
    model->_00->_98 = 0xFF;
    fn_800BDA94(model, mtx);
}

// .text:0x000C0854 size:0x108 mapped:0x806FF8E8
// Registers only, in the slot release: the target puts the offset in r4, -1 in r5 and the
// channel in r0, this the offset in r0, -1 in r4 and the channel in r5
void fn_3_C0854(void) {
    UnkActor1F58* actor;
    s32 i;
    s32 j;
    s32 ch;

    for (i = 0; i < 2; i++) {
        if (lbl_3_data_174A0[i] != NULL) {
            lbl_3_data_174A0[i]->_20 = 1;
        }
        if (lbl_3_data_17260.slots[i].id >= 0) {
            j = fn_3_C1930(lbl_3_data_17260.slots[i].id);
            if (j >= 0) {
                actor = lbl_8036E548._2C50[lbl_3_data_17260.slots[i].id];
                if (actor != NULL) {
                    actor->_05C = NULL;
                }
                lbl_3_data_17260.slots[j].id = -1;
                ch = 0x18;
                if (j != 0) {
                    ch = 0x17;
                }
                fn_80027918(ch, 0.0f);
            }
        }
    }
}

