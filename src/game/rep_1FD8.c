#include "game/rep_1FD8.h"
#include "header_rep_data.h"
#include "C3/control.h"
#include "C3/geoPalette.h"
#include "game/rep_1D58.h"

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

extern Rep1FD8Task* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);
extern void fn_800528C0(f32 x, f32 y, f32 z, s16* screenX, s16* screenY);
extern Rep1FD8SpriteRef lbl_80371C30[];
extern void* lbl_803CC1B8;
extern void fn_800B0A14_removeQueue(void);
extern void fn_80034CEC(Rep1FD8Task* task);
extern void fn_8003A8A0(struct DODisplayObj* obj, MtxPtr view, s32 arg2);

// .bss, declared in reverse address order (MWCC lays .bss statics out last to first)
static s32 lbl_3_bss_9F0C[5];
static u8 lbl_3_bss_9E54[0xB8];
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
static s32 lbl_3_bss_9D90;
static s32 lbl_3_bss_9D8C;
static s32 lbl_3_bss_9D88;
static s32 lbl_3_bss_9D84;
static u8 lbl_3_bss_9D82;
static u8 lbl_3_bss_9D81;
static u8 lbl_3_bss_9D80;

// .text:0x000C8650 size:0xD2C mapped:0x807076E4
void fn_3_C8650(void) {
    return;
}

// .text:0x000C82B4 size:0x39C mapped:0x80707348
void fn_3_C82B4(void) {
    return;
}

// .text:0x000C823C size:0x78 mapped:0x807072D0
struct StadiumObjectCollision* fn_3_C823C(s32 idx, MtxPtr mtx) {
    return NULL;
}

// .text:0x000C805C size:0x1E0 mapped:0x807070F0
void fn_3_C805C(void) {
    return;
}

// .text:0x000C7A0C size:0x650 mapped:0x80706AA0
void fn_3_C7A0C(void) {
    return;
}

// .text:0x000C77AC size:0x260 mapped:0x80706840
void fn_3_C77AC(void) {
    return;
}

// .text:0x000C75B8 size:0x1F4 mapped:0x8070664C
void fn_3_C75B8(void) {
    return;
}

// .text:0x000C749C size:0x11C mapped:0x80706530
void fn_3_C749C(void) {
    return;
}

// .text:0x000C7444 size:0x58 mapped:0x807064D8
void fn_3_C7444(void) {
    return;
}

// .text:0x000C71CC size:0x278 mapped:0x80706260
void fn_3_C71CC(void) {
    return;
}

// .text:0x000C63D0 size:0xDFC mapped:0x80705464
void fn_3_C63D0(void) {
    return;
}

// .text:0x000C625C size:0x174 mapped:0x807052F0
void fn_3_C625C(void) {
    return;
}

// .text:0x000C5DDC size:0x480 mapped:0x80704E70
void fn_3_C5DDC(void) {
    return;
}

// .text:0x000C5CE0 size:0xFC mapped:0x80704D74
void fn_3_C5CE0(void) {
    return;
}

// .text:0x000C597C size:0x364 mapped:0x80704A10
void fn_3_C597C(void) {
    return;
}

// .text:0x000C56E8 size:0x294 mapped:0x8070477C
void fn_3_C56E8(void) {
    return;
}

// .text:0x000C54D0 size:0x218 mapped:0x80704564
void fn_3_C54D0(void) {
    return;
}

// .text:0x000C5304 size:0x1CC mapped:0x80704398
void fn_3_C5304(void) {
    return;
}

// .text:0x000C4F00 size:0x404 mapped:0x80703F94
void fn_3_C4F00(void) {
    return;
}

// .text:0x000C4CF4 size:0x20C mapped:0x80703D88
void fn_3_C4CF4(void) {
    return;
}

// .text:0x000C4B80 size:0x174 mapped:0x80703C14
void fn_3_C4B80(void) {
    return;
}

// .text:0x000C48D0 size:0x2B0 mapped:0x80703964
void fn_3_C48D0(void) {
    return;
}

// .text:0x000C4724 size:0x1AC mapped:0x807037B8
void fn_3_C4724(void) {
    return;
}

// .text:0x000C444C size:0x2D8 mapped:0x807034E0
void fn_3_C444C(void) {
    return;
}

// .text:0x000C42A4 size:0x1A8 mapped:0x80703338
void fn_3_C42A4(void) {
    return;
}

// .text:0x000C414C size:0x158 mapped:0x807031E0
void fn_3_C414C(void) {
    return;
}

// .text:0x000C40EC size:0x60 mapped:0x80703180
void fn_3_C40EC(void) {
    return;
}

// .text:0x000C4068 size:0x84 mapped:0x807030FC
void fn_3_C4068(void) {
    return;
}

// .text:0x000C3F70 size:0xF8 mapped:0x80703004
void fn_3_C3F70(void) {
    return;
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
void fn_3_C3A38(void) {
    return;
}

// .text:0x000C39C8 size:0x70 mapped:0x80702A5C
void fn_3_C39C8(void) {
    return;
}

// .text:0x000C366C size:0x35C mapped:0x80702700
void fn_3_C366C(void) {
    return;
}

// .text:0x000C30F0 size:0x57C mapped:0x80702184
void fn_3_C30F0(void) {
    return;
}

// .text:0x000C2EDC size:0x214 mapped:0x80701F70
void fn_3_C2EDC(void) {
    return;
}

// .text:0x000C2C80 size:0x25C mapped:0x80701D14
void fn_3_C2C80(void) {
    return;
}

// .text:0x000C2AA0 size:0x1E0 mapped:0x80701B34
void fn_3_C2AA0(void) {
    return;
}

// .text:0x000C298C size:0x114 mapped:0x80701A20
void fn_3_C298C(void) {
    return;
}

// .text:0x000C2974 size:0x18 mapped:0x80701A08
void fn_3_C2974(void) {
    lbl_3_bss_9DE7 = 1;
    lbl_3_bss_9D82 = 1;
}

// .text:0x000C2644 size:0x330 mapped:0x807016D8
void fn_3_C2644(void) {
    return;
}

// .text:0x000C24A0 size:0x1A4 mapped:0x80701534
void fn_3_C24A0(void) {
    return;
}

// .text:0x000C23E0 size:0xC0 mapped:0x80701474
void fn_3_C23E0(void) {
    return;
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
    return;
}

// .text:0x000C1C18 size:0x62C mapped:0x80700CAC
void fn_3_C1C18(void) {
    return;
}

// .text:0x000C19C8 size:0x250 mapped:0x80700A5C
void fn_3_C19C8(void) {
    return;
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
