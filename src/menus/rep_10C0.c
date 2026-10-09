#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "menus/rep_10C0.h"
#include "menus/rep_08E8.h"
#include "menus/rep_0B08.h"
#include "Dolphin/mtx.h"
#include "Dolphin/vec.h"
#include "string.h"

// The menus' camera
typedef struct Camera10C0 {
    /* 0x00 */ Mtx _00;
    /* 0x30 */ u16 _30;
    /* 0x32 */ u16 _32;
    /* 0x34 */ f32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ Vec _40;
    /* 0x4C */ Vec _4C;
    /* 0x58 */ u8 _58[0x5C - 0x58];
} Camera10C0; // size: 0x5C

typedef struct CameraBlend10C0 {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
} CameraBlend10C0; // size: 0x18

extern struct {
    /* 0x000000 */ u8 _000000[0x197608];
    /* 0x197608 */ Vec _197608;
    /* 0x197614 */ Vec _197614;
    /* 0x197620 */ Vec _197620;
    /* 0x19762C */ Vec _19762C;
    /* 0x197638 */ Vec _197638;
    /* 0x197644 */ Vec _197644;
    /* 0x197650 */ u8 _197650[0x19765C - 0x197650];
    /* 0x19765C */ f32 _19765C;
    /* 0x197660 */ u8 _197660[0x197664 - 0x197660];
    /* 0x197664 */ f32 _197664;
    /* 0x197668 */ CameraBlend10C0 _197668;
    /* 0x197680 */ u8 _197680[0x19774A - 0x197680];
    /* 0x19774A */ s16 _19774A;
    /* 0x19774C */ u8 _19774C[0x197845 - 0x19774C];
    /* 0x197845 */ u8 _197845;
    /* 0x197846 */ u8 _197846[0x197848 - 0x197846];
    /* 0x197848 */ u8 _197848;
    /* 0x197849 */ u8 _197849;
    /* 0x19784A */ u8 _19784A[0x197855 - 0x19784A];
    /* 0x197855 */ u8 _197855;
    /* 0x197856 */ u8 _197856;
    /* 0x197857 */ u8 _197857[0x197863 - 0x197857];
    /* 0x197863 */ s8 _197863;
} *lbl_2_bss_1A824C;

extern Camera10C0 lbl_2_bss_1A81D4;
extern CameraBlend10C0 lbl_2_data_3BB0[3];

extern void fn_80011640(Mtx src, Mtx dst);

// .text:0x000021D8 size:0x18
void fn_2_94854(s32 arg0) {
    lbl_2_bss_1A824C->_197849 = arg0;
}

// .text:0x00002060 size:0x178
void fn_2_946DC(s32 index) {
    lbl_2_bss_1A824C->_197668._00 = lbl_2_data_3BB0[index]._00;
    lbl_2_bss_1A824C->_197668._04 = lbl_2_data_3BB0[index]._04;
    lbl_2_bss_1A824C->_197668._08 = lbl_2_data_3BB0[index]._08;
    lbl_2_bss_1A824C->_197668._0C = lbl_2_data_3BB0[index]._0C;
    lbl_2_bss_1A824C->_197668._10 = lbl_2_data_3BB0[index]._10;
    lbl_2_bss_1A824C->_197668._14 = lbl_2_data_3BB0[index]._14;
    lbl_2_bss_1A824C->_197620.x = lbl_2_bss_1A81D4._4C.x;
    lbl_2_bss_1A824C->_197620.y = lbl_2_bss_1A81D4._4C.y;
    lbl_2_bss_1A824C->_197620.z = lbl_2_bss_1A81D4._4C.z;
    lbl_2_bss_1A824C->_19762C.x = lbl_2_bss_1A81D4._4C.x + 0.00001f;
    lbl_2_bss_1A824C->_19762C.y = lbl_2_bss_1A81D4._4C.y + 0.00001f;
    lbl_2_bss_1A824C->_19762C.z = lbl_2_bss_1A81D4._4C.z + 0.00001f;
    lbl_2_bss_1A824C->_197638.x = lbl_2_bss_1A81D4._40.x + 0.00001f;
    lbl_2_bss_1A824C->_197638.y = lbl_2_bss_1A81D4._40.y + 0.00001f;
    lbl_2_bss_1A824C->_197638.z = lbl_2_bss_1A81D4._40.z + 0.00001f;
    lbl_2_bss_1A824C->_197644.x = lbl_2_bss_1A81D4._40.x + 0.00002f;
    lbl_2_bss_1A824C->_197644.y = lbl_2_bss_1A81D4._40.y + 0.00002f;
    lbl_2_bss_1A824C->_197644.z = lbl_2_bss_1A81D4._40.z + 0.00002f;
}

// .text:0x00001FB8 size:0xA8
void fn_2_94634(s32 index) {
    lbl_2_bss_1A824C->_197668._00 = lbl_2_data_3BB0[index]._00;
    lbl_2_bss_1A824C->_197668._04 = lbl_2_data_3BB0[index]._04;
    lbl_2_bss_1A824C->_197668._08 = lbl_2_data_3BB0[index]._08;
    lbl_2_bss_1A824C->_197668._0C = lbl_2_data_3BB0[index]._0C;
    lbl_2_bss_1A824C->_197668._10 = lbl_2_data_3BB0[index]._10;
    lbl_2_bss_1A824C->_197668._14 = lbl_2_data_3BB0[index]._14;
    if (index == 0) {
        lbl_2_bss_1A824C->_197855 = 0;
    } else {
        lbl_2_bss_1A824C->_197855 = 1;
    }
}

// .text:0x00001FA0 size:0x18
void fn_2_9461C(s32 arg0) {
    lbl_2_bss_1A824C->_19774A = arg0;
}

// .text:0x00001F88 size:0x18
void fn_2_94604(s32 arg0) {
    lbl_2_bss_1A824C->_197856 = arg0;
}

// .text:0x000015E8 size:0x9A0
void fn_2_93C64(void) {
}

// .text:0x0000157C size:0x6C
void fn_2_93BF8(Camera10C0* camera) {
    switch (lbl_2_bss_1A824C->_197845) {
    case 0:
        fn_2_932DC(camera);
        break;
    case 1:
        fn_2_92F2C(camera);
        break;
    }
    fn_80011640(camera->_00, camera->_00);
}

// .text:0x00000634 size:0x27C
void fn_2_92CB0(void) {
    Vec result;
    Vec prevPos;
    Vec cur;
    Vec prevTarget;
    f32 x;
    f32 y;
    f32 z;

    if (lbl_2_bss_1A824C->_197855 != 0) {
        x = lbl_2_bss_1A824C->_197608.x;
        y = lbl_2_bss_1A824C->_197608.y;
        z = lbl_2_bss_1A824C->_197608.z;
        prevPos.x = lbl_2_bss_1A824C->_19762C.x;
        prevPos.y = lbl_2_bss_1A824C->_19762C.y;
        prevPos.z = lbl_2_bss_1A824C->_19762C.z;
        cur.x = x;
        cur.y = y;
        cur.z = z;
        prevTarget.x = lbl_2_bss_1A824C->_197620.x;
        prevTarget.y = lbl_2_bss_1A824C->_197620.y;
        prevTarget.z = lbl_2_bss_1A824C->_197620.z;
        result = fn_2_9267C(prevPos, cur, prevTarget, 0.01f, lbl_2_bss_1A824C->_197668._00,
                            lbl_2_bss_1A824C->_197668._04, lbl_2_bss_1A824C->_197668._08);
        lbl_2_bss_1A824C->_197608.x = result.x;
        lbl_2_bss_1A824C->_197608.y = result.y;
        lbl_2_bss_1A824C->_197608.z = result.z;
        lbl_2_bss_1A824C->_19762C.x = result.x;
        lbl_2_bss_1A824C->_19762C.y = result.y;
        lbl_2_bss_1A824C->_19762C.z = result.z;
        lbl_2_bss_1A824C->_197620.x = x;
        lbl_2_bss_1A824C->_197620.y = y;
        lbl_2_bss_1A824C->_197620.z = z;
    }
}

// .text:0x000003B8 size:0x27C
void fn_2_92A34(Vec* arg0, Vec* pos) {
    Vec result;
    Vec prevPos;
    Vec cur;
    Vec prevTarget;

    if (lbl_2_bss_1A824C->_197855 != 0) {
        pos->x = fn_2_4A18C(pos->x);
        pos->y = fn_2_4A18C(pos->y);
        prevPos.x = lbl_2_bss_1A824C->_197644.x;
        prevPos.y = lbl_2_bss_1A824C->_197644.y;
        prevPos.z = lbl_2_bss_1A824C->_197644.z;
        cur.x = pos->x;
        cur.y = pos->y;
        cur.z = 0.0f;
        prevTarget.x = lbl_2_bss_1A824C->_197638.x;
        prevTarget.y = lbl_2_bss_1A824C->_197638.y;
        prevTarget.z = lbl_2_bss_1A824C->_197638.z;
        result = fn_2_9267C(prevPos, cur, prevTarget, 0.01f, lbl_2_bss_1A824C->_197668._0C,
                            lbl_2_bss_1A824C->_197668._10, lbl_2_bss_1A824C->_197668._14);
        lbl_2_bss_1A824C->_197638.x = pos->x;
        lbl_2_bss_1A824C->_197638.y = pos->y;
        lbl_2_bss_1A824C->_197638.z = 0.0f;
        lbl_2_bss_1A824C->_197644.x = result.x;
        lbl_2_bss_1A824C->_197644.y = result.y;
        lbl_2_bss_1A824C->_197644.z = result.z;
        pos->x = result.x;
        pos->y = result.y;
    }
}

// .text:0x0000014C size:0x26C
void fn_2_927C8(Vec* arg0, Vec* pos) {
    Vec result;
    Vec prevPos;
    Vec cur;
    Vec prevTarget;
    Vec unused;

    if (lbl_2_bss_1A824C->_197855 != 0) {
        memcpy(&unused, pos, sizeof(Vec));
        prevPos.x = lbl_2_bss_1A824C->_197644.x;
        prevPos.y = lbl_2_bss_1A824C->_197644.y;
        prevPos.z = lbl_2_bss_1A824C->_197644.z;
        memcpy(&cur, pos, sizeof(Vec));
        prevTarget.x = lbl_2_bss_1A824C->_197638.x;
        prevTarget.y = lbl_2_bss_1A824C->_197638.y;
        prevTarget.z = lbl_2_bss_1A824C->_197638.z;
        result = fn_2_9267C(prevPos, cur, prevTarget, 0.01f, lbl_2_bss_1A824C->_197668._0C,
                            lbl_2_bss_1A824C->_197668._10, lbl_2_bss_1A824C->_197668._14);
        lbl_2_bss_1A824C->_197638.x = pos->x;
        lbl_2_bss_1A824C->_197638.y = pos->y;
        lbl_2_bss_1A824C->_197638.z = pos->z;
        lbl_2_bss_1A824C->_197644.x = result.x;
        lbl_2_bss_1A824C->_197644.y = result.y;
        lbl_2_bss_1A824C->_197644.z = result.z;
        pos->x = result.x;
        pos->y = result.y;
        pos->z = result.z;
    }
}

// .text:0x00000000 size:0x14C
Vec fn_2_9267C(Vec a, Vec b, Vec c, f32 scale, f32 p2, f32 p3, f32 p4) {
    Vec ab;
    Vec scaled;
    Vec cb;
    f32 dist;
    f32 t;

    PSVECSubtract(&a, &b, &ab);
    dist = PSVECDistance(&a, &b);
    PSVECSubtract(&c, &b, &cb);
    PSVECScale(&cb, scale, &scaled);
    t = p2 * (p4 - dist) + p3 * (PSVECDotProduct(&scaled, &ab) / dist);
    PSVECNormalize(&ab, &ab);
    PSVECScale(&ab, t * scale, &ab);
    PSVECAdd(&a, &ab, &a);
    return a;
}
