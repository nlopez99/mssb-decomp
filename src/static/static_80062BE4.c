#include "static/static_80062BE4.h"
#include "static/UnknownHomes_Static.h"
#include "static/particle.h"
#include "static/static_8004AC00.h"
#include "C3/control.h"

typedef struct StreakParams {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[19];
} StreakParams; // size: 0x50

typedef struct FxBones {
    /* 0x000 */ u8 _000[0x162];
    /* 0x162 */ u16 bones[1];
} FxBones;

typedef struct FxActor {
    /* 0x000 */ u8 _000[0x252];
    /* 0x252 */ s8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ s8 _254;
} FxActor;

typedef struct ModelBone {
    /* 0x000 */ u16 id;
    /* 0x002 */ u8 _002[0x137 - 0x2];
    /* 0x137 */ u8 _137;
} ModelBone;

typedef struct ModelDesc {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 count;
    /* 0x08 */ u8 _08[0x18 - 0x8];
    /* 0x18 */ ModelBone** bones;
} ModelDesc;

typedef struct FlipBone {
    /* 0x00 */ u8 _00[0x60];
    /* 0x60 */ Control ctrl;
    /* 0xA4 */ Control blend;
} FlipBone;

typedef struct FlipOwner {
    /* 0x00 */ u8 _00[0x94];
    /* 0x94 */ s32 (*buildMtx)(u16* id, FlipBone* bone, MtxPtr m);
} FlipOwner;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ FxBones* fielders[13];
} lbl_8036E548;

extern s32 lbl_803CBD0C;
StreakParams lbl_80108B90 = {
    0, { 24, 30, 25, 1, 8, 10, 4000, 5000, 10000, 12000, 30000, 40000, 50000, 60000, 100, 100, 50000, 50000, -1 },
};
u16 lbl_80108BE0[8] = { 7, 8, 4, 5, 6, 0xFFFF, 0, 0 };
s8 lbl_80108BF0[5][0x36] = {
    {
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    },
    {
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    },
    {
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    },
    {
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    },
    {
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    },
};

extern void fn_800B84AC(Control* a, Control* b, Control* out);
extern void CTRLBuildMatrix_Flip(Control* ctrl, MtxPtr m, s32 flip);

// .text:0x80063010 size:0x18
s32 fn_80063010(void* arg0, FlipOwner** owner) {
    (*owner)->buildMtx = fn_80062F38;
    return 0;
}

// .text:0x80062F38 size:0xD8
s32 fn_80062F38(u16* id, FlipBone* bone, MtxPtr m) {
    switch (*id) {
    case 0x46:
        fn_800B84AC(&bone->ctrl, &bone->blend, &bone->ctrl);
        CTRLBuildMatrix_Flip(&bone->ctrl, m, 0);
        return 1;
    case 0x4A:
        fn_800B84AC(&bone->ctrl, &bone->blend, &bone->ctrl);
        CTRLBuildMatrix_Flip(&bone->ctrl, m, 0);
        return 1;
    case 0x4C:
        fn_800B84AC(&bone->ctrl, &bone->blend, &bone->ctrl);
        CTRLBuildMatrix_Flip(&bone->ctrl, m, 0);
        return 1;
    }
    return 0;
}

// .text:0x80062ED4 size:0x64
s32 fn_80062ED4(void* arg0, ModelDesc** model) {
    ModelDesc* desc = *model;
    s32 i;

    for (i = 0; i < desc->count; i++) {
        switch (desc->bones[i]->id) {
        case 0x41:
        case 0x43:
        case 0x45:
        case 0x47:
        case 0x49:
        case 0x4B:
            desc->bones[i]->_137 = 2;
            break;
        }
    }
    return 0;
}

// .text:0x80062E6C size:0x68
void fn_80062E6C(void* actor, s32 a, s32 b, f32 t) {
    s32 row = a - 0x28;

    if (lbl_80366158._28 != 1) {
        fn_8004B1C0(lbl_80108BF0[row][((FxActor*)actor)->_252], actor, a, b, t);
    }
}

static inline int getFielderBone(s8 slot, u16 id) {
    if (lbl_8036E548.fielders[slot] != NULL) {
        return lbl_8036E548.fielders[slot]->bones[id];
    }
    return 0xFFFF;
}

// .text:0x80062D94 size:0xD8
void fn_80062D94(void* actor, s32 a, s32 b, f32 t) {
    s32 i;

    if (lbl_80366158._28 != 1) {
        u16* id;

        i = 0;
        while (*(id = &lbl_80108BE0[i]) != 0xFFFF && getFielderBone(((FxActor*)actor)->_254, *id) == 0xFFFF) {
            i++;
        }
        if (lbl_80108BE0[i] != 0xFFFF) {
            lbl_80108B90._00 = lbl_803CBD0C;
            fn_800324EC(lbl_80108BE0[i], ((FxActor*)actor)->_254, -1, &lbl_80108B90);
        }
    }
}

// .text:0x80062C60 size:0x134
void fn_80062C60(void* actor, s32 a, s32 b, f32 t) {
    if (lbl_80366158._28 != 1) {
        if (0.5f == t) {
            fn_80062D94(actor, a, b, t);
        }
        fn_8006C3F8(actor, a, b, t);
    }
}

// .text:0x80062C24 size:0x3C
void fn_80062C24(Vec* pos) {
    if (lbl_80366158._28 != 1 && pos != NULL) {
        fn_80032284(pos);
    }
}

// .text:0x80062BE4 size:0x40
void fn_80062BE4(Vec* pos) {
    if (lbl_80366158._28 != 1) {
        lbl_80108B90._00 = lbl_803CBD0C;
        fn_80032064(pos, &lbl_80108B90);
    }
}
