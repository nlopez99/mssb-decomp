#include "static/static_8000F150.h"
#include "static/UnknownHomes_Static.h"
#include "static/static_8000BA3C.h"

typedef struct TextBox {
    /* 0x00 */ void* _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ u16 _10;
    /* 0x12 */ u16 _12;
    /* 0x14 */ s16 _14;
    /* 0x16 */ s16 _16;
    /* 0x18 */ s16 _18[4];
    /* 0x20 */ s16 _20[4];
    /* 0x28 */ s16 _28;
    /* 0x2A */ u8 state;
    /* 0x2B */ u8 group;
    /* 0x2C */ u8 _2C;
    /* 0x2D */ u8 _2D;
    /* 0x2E */ u8 _2E;
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u8 _30;
    /* 0x31 */ u8 _31;
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34;
    /* 0x35 */ u8 _35;
    /* 0x36 */ u8 _36;
    /* 0x37 */ u8 _37;
} TextBox; // size: 0x38

typedef struct TextSlot {
    /* 0x0 */ struct TextModel* model;
    /* 0x4 */ u16 box;
    /* 0x6 */ u16 _06;
} TextSlot; // size: 0x8

typedef struct FontInfo {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ u8 _0C[0x14 - 0xC];
    /* 0x14 */ s32 _14;
    /* 0x18 */ s32 _18;
    /* 0x1C */ u16* _1C;
} FontInfo;

typedef struct FontHeader {
    /* 0x00 */ s32 _00;
    /* 0x04 */ FontInfo info;
} FontHeader;

typedef struct TextTable {
    /* 0x0 */ s32 count;
    /* 0x4 */ s32 entries[1];
} TextTable;

typedef struct TextState {
    /* 0x000 */ TextBox boxes[30];
    /* 0x690 */ TextSlot slots[30];
    /* 0x780 */ u32* _780;
    /* 0x784 */ struct TexFile* textures[4];
    /* 0x794 */ struct TexFile* icons;
    /* 0x798 */ struct TextTable* fonts[7];
    /* 0x7B4 */ FontInfo* info;
    /* 0x7B8 */ void* _7B8[4];
    /* 0x7C8 */ void* _7C8[9];
    /* 0x7EC */ s32 _7EC;
    /* 0x7F0 */ s32 _7F0;
    /* 0x7F4 */ s32 _7F4;
    /* 0x7F8 */ s32 _7F8;
    /* 0x7FC */ u8 _7FC;
    /* 0x7FD */ u8 _7FD;
    /* 0x7FE */ u8 mask;
    /* 0x7FF */ u8 _7FF;
} TextState; // size: 0x800

typedef struct TextModel {
    /* 0x00 */ u32 _00;
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ u8 _0C[0x54 - 0xC];
    /* 0x54 */ s32 flags;
    /* 0x58 */ s32 _58;
    /* 0x5C */ u8 _5C[0x64 - 0x5C];
    /* 0x64 */ u16 _64;
    /* 0x66 */ u8 _66;
    /* 0x67 */ u8 _67;
} TextModel;

typedef struct TextModelEntry {
    /* 0x0 */ TextModel* model;
    /* 0x4 */ u8 _04[4];
} TextModelEntry;

typedef struct RelocTable {
    /* 0x0 */ u16 count;
    /* 0x2 */ u16 _02;
    /* 0x4 */ u32 offsets[1];
} RelocTable;

extern TextState lbl_80366B18;
extern u16 lbl_80366218[0x480];
extern TextModelEntry lbl_80371C30[];
extern u8 lbl_800E9920[];
extern void* lbl_803CBBE8;

extern void convertTextureHeader(void* tex);

typedef struct AnimValues {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u8 _08[0xC - 0x8];
    /* 0x0C */ s16 _0C;
    /* 0x0E */ u8 _0E[0x14 - 0xE];
    /* 0x14 */ s16 x;
    /* 0x16 */ s16 y;
    /* 0x18 */ u8 _18[0x1C - 0x18];
    /* 0x1C */ s32 color;
    /* 0x20 */ u8 _20[0x50 - 0x20];
} AnimValues; // size: 0x50

typedef struct TextAnim {
    /* 0x00 */ u8 _00[0x38];
    /* 0x38 */ AnimFile* file;
} TextAnim; // size: 0x3C

extern TextAnim lbl_803C4BE0[];

extern s32 byteWiseMultiply(s32 a, s32 b);
extern s32 multBottomBits_asFloat(s32 a, s32 b);

// .text:0x800111B4 size:0x24
void fn_800111B4(RelocTable* table) {
    s32 n = table->count;
    u32* p = table->offsets;

    do {
        *p += (u32)table;
        p++;
    } while (--n != 0);
}

// .text:0x80011140 size:0x74
void fn_80011140(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        lbl_80366B18.boxes[i].state = 0;
        lbl_80366B18.slots[i].model = NULL;
    }
    lbl_80366B18.mask = 0;
}

// Differs: the loop counter and the state pointer swap r30/r31; a state pointer local,
// a second counter and declaration orders did not fix it.
// .text:0x80011000 size:0x140
void fn_80011000(void) {
    s32 i;

    lbl_80366B18.textures[0] = (TexFile*)((u8*)lbl_80366B18._780 + lbl_80366B18._780[0]);
    lbl_80366B18.textures[1] = (TexFile*)((u8*)lbl_80366B18._780 + lbl_80366B18._780[1]);
    lbl_80366B18.textures[2] = (TexFile*)((u8*)lbl_80366B18._780 + lbl_80366B18._780[2]);
    lbl_80366B18.textures[3] = (TexFile*)((u8*)lbl_80366B18._780 + lbl_80366B18._780[3]);
    for (i = 0; i < 4; i++) {
        convertTextureHeader(lbl_80366B18.textures[i]);
        lbl_80366B18._7B8[i] = (u8*)lbl_80366B18.textures[i] + lbl_80366B18.textures[i]->entries[0]._00 * 32 + 4;
    }
    convertTextureHeader(lbl_80366B18.icons);
    for (i = 0; i < 9; i++) {
        lbl_80366B18._7C8[i] = (u8*)lbl_80366B18.icons + lbl_80366B18.icons->entries[i]._00 * 32 + 4;
    }
    lbl_80366B18._7FC = 1;
    lbl_80366B18._7FD = 1;
}

// .text:0x80010FA0 size:0x60
void fn_80010FA0(void) {
    FontHeader* hdr = (FontHeader*)lbl_80366B18.fonts[0];
    FontInfo* info;
    u16* src;
    s32 i;
    u16 c;

    info = &hdr->info;
    lbl_80366B18.info = info;
    lbl_80366B18._7EC = ((FontHeader*)lbl_80366B18.fonts[0])->info._04;
    lbl_80366B18._7F0 = ((FontHeader*)lbl_80366B18.fonts[0])->info._08;
    lbl_80366B18._7F8 = ((FontHeader*)lbl_80366B18.fonts[0])->info._18;
    lbl_80366B18._7F4 = ((FontHeader*)lbl_80366B18.fonts[0])->info._14;
    src = info->_1C;
    for (i = 0;; i++) {
        c = src[i];
        if (c == 0x4001) {
            return;
        }
        lbl_80366218[i] = c;
    }
}

// .text:0x80010F2C size:0x74
void DrawTextOnCondition(s32 group) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (lbl_80366B18.boxes[i].state == 2 && group == lbl_80366B18.boxes[i].group) {
            DrawText(i);
        }
    }
}

// .text:0x80010498 size:0xA94
void DrawText(s32 i) {
}

// .text:0x800100A4 size:0x3F4
void fn_800100A4(void) {
}

// .text:0x8000FF04 size:0x1A0
s32 fn_8000FF04(s32 font, s32 str, s16 x, s16 y, s32 group, s32 arg5, u8 arg6) {
    s32 i;
    TextBox* box;

    for (i = 0; i < 30; i++) {
        if (lbl_80366B18.boxes[i].state == 0) {
            break;
        }
    }
    if (i >= 30) {
        return 0;
    }
    box = &lbl_80366B18.boxes[i];
    box->_04 = lbl_80366B18.fonts[font]->entries[str];
    box->_10 = x;
    box->_12 = y;
    box->group = group;
    box->state = 2;
    box->_2C = arg6;
    box->_08 = arg5;
    box->_18[0] = 0;
    box->_18[1] = 0;
    box->_18[2] = 0;
    box->_18[3] = 0;
    box->_2D = 0;
    box->_2E = 2;
    box->_2F = 0;
    box->_30 = 0;
    box->_00 = NULL;
    box->_28 = -1;
    box->_31 = 0;
    box->_32 = 0;
    box->_34 = 0;
    box->_33 = 0;
    box->_35 = 0;
    box->_36 = 0;
    return i;
}

// .text:0x8000FEE8 size:0x1C
void fn_8000FEE8(s32 i) {
    lbl_80366B18.boxes[i].state = 0;
}

// .text:0x8000FE54 size:0x94
void fn_8000FE54(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        lbl_80366B18.boxes[i].state = 0;
    }
}

// .text:0x8000FE08 size:0x4C
void fn_8000FE08(s32 i, s32 font, s32 str) {
    TextBox* box;

    box = &lbl_80366B18.boxes[i];
    box->_04 = lbl_80366B18.fonts[font]->entries[str];
    if (box->_28 >= 0) {
        box->_28 = 0;
        box->_34 = 0;
        box->_35 = 0;
    }
}

// .text:0x8000FD9C size:0x6C
void fn_8000FD9C(s32 i, s32 mode, s32 arg2) {
    if (mode == 0) {
        lbl_80366B18.boxes[i]._28 = -1;
        lbl_80366B18.boxes[i]._31 = 0;
        lbl_80366B18.boxes[i]._32 = 0;
        return;
    }
    if (arg2 >= 0) {
        lbl_80366B18.boxes[i]._28 = arg2;
    }
    lbl_80366B18.boxes[i]._31 = mode;
    lbl_80366B18.boxes[i]._32 = 0;
}

// .text:0x8000FD78 size:0x24
void fn_8000FD78(s32 i, s16 a, s16 b, s16 c, s16 d) {
    TextBox* box = &lbl_80366B18.boxes[i];

    box->_18[0] = a;
    box->_18[1] = b;
    box->_18[2] = c;
    box->_18[3] = d;
}

// .text:0x8000FD54 size:0x24
void fn_8000FD54(s32 i, s16 a, s16 b, s16 c, s16 d) {
    TextBox* box = &lbl_80366B18.boxes[i];

    box->_20[0] = a;
    box->_20[1] = b;
    box->_20[2] = c;
    box->_20[3] = d;
}

// .text:0x8000FA9C size:0x2B8
void fn_8000FA9C(void) {
}

// .text:0x8000F988 size:0x114
s32 fn_8000F988(TextModelSet* set, s32 i, u16 arg2, s32 font, s32 str, BOOL flag) {
    TextModel* model = lbl_80371C30[set->first + i].model;
    s32 j;

    model->flags |= 4;
    if (flag) {
        model->flags |= 8;
    }
    for (j = 0; j < 30; j++) {
        if (lbl_80366B18.slots[j].model == NULL) {
            lbl_80366B18.slots[j].model = model;
            lbl_80366B18.slots[j]._06 = arg2;
            lbl_80366B18.slots[j].box = fn_8000FF04(font, str, 0, 0, model->_67, -1, 0);
            if (model->_00 != 0) {
                lbl_80366B18.boxes[lbl_80366B18.slots[j].box]._00 = &model->_0C;
            } else {
                lbl_80366B18.boxes[lbl_80366B18.slots[j].box]._00 = NULL;
            }
            return lbl_80366B18.slots[j].box;
        }
    }
    return -1;
}

// .text:0x8000F8F4 size:0x94
void fn_8000F8F4(TextModelSet* set) {
    s32 first;
    s32 i;
    s32 j;
    TextModel* model;

    first = set->first;
    for (i = 0; i < set->count; i++) {
        model = lbl_80371C30[first + i].model;
        if (model != NULL && (model->flags & 4)) {
            for (j = 0; j < 30; j++) {
                if (lbl_80366B18.slots[j].model == lbl_80371C30[first + i].model) {
                    lbl_80366B18.slots[j].model = NULL;
                    break;
                }
            }
        }
    }
}

// Differs: the target keeps &anim->file (lwzu) in r31 and frame in r30, and computes each
// box address with the operands of the add swapped; declaration orders reached 99.16%.
// .text:0x8000F534 size:0x3C0
void fn_8000F534(TextModel* model, BOOL active) {
    AnimValues cur;
    AnimValues next;
    TextBox* box;
    TextAnim* anim;
    TextSlot* slot;
    BOOL flag = FALSE;
    u16 frame;
    s16 x;
    s16 y;
    s32 i;
    s32 v;
    s32 color;

    for (i = 0; i < 30; i++) {
        if (model == lbl_80366B18.slots[i].model) {
            break;
        }
    }
    if (i >= 30) {
        return;
    }
    slot = &lbl_80366B18.slots[i];
    if (!active) {
        lbl_80366B18.boxes[slot->box].state = 1;
        return;
    }
    lbl_80366B18.boxes[slot->box].state = 2;
    frame = model->_64;
    anim = &lbl_803C4BE0[model->_66];
    fn_8000CEF0(anim->file, frame, 0, slot->_06, (u32*)&cur);
    x = cur.x;
    y = cur.y;
    if (model->flags & 8) {
        color = byteWiseMultiply(cur.color, model->_58);
    } else {
        color = multBottomBits_asFloat(cur.color, model->_58);
    }
    lbl_80366B18.boxes[slot->box]._08 = color;
    v = (cur._0C << 8) / 1024;
    if (v == 16) {
        flag = TRUE;
        lbl_80366B18.boxes[slot->box]._2C = 2;
    } else if (v == 18) {
        lbl_80366B18.boxes[slot->box]._2C = 1;
    } else if (v == 22) {
        lbl_80366B18.boxes[slot->box]._2C = 0;
    } else {
        fn_8000CEF0(anim->file, cur._06, 0, 0, (u32*)&next);
        v = (next._0C << 8) / 1024;
        if (v < 17) {
            flag = TRUE;
            lbl_80366B18.boxes[slot->box]._2C = 2;
        } else if (v < 20) {
            lbl_80366B18.boxes[slot->box]._2C = 1;
        } else {
            lbl_80366B18.boxes[slot->box]._2C = 0;
        }
    }
    if (flag) {
        box = &lbl_80366B18.boxes[slot->box];
        box->_10 = x;
        box->_12 = y;
    } else {
        box = &lbl_80366B18.boxes[slot->box];
        box->_10 = x;
        box->_12 = y;
    }
    if (fn_8000CEF0(anim->file, frame, 1, slot->_06, (u32*)&cur)) {
        lbl_80366B18.boxes[slot->box]._0C = multBottomBits_asFloat(cur.color, model->_58);
        lbl_80366B18.boxes[slot->box]._14 = cur.x - lbl_80366B18.boxes[slot->box]._10;
        lbl_80366B18.boxes[slot->box]._16 = cur.y - lbl_80366B18.boxes[slot->box]._12;
    } else {
        lbl_80366B18.boxes[slot->box]._0C = 0;
    }
}

// .text:0x8000F4B8 size:0x7C
void fn_8000F4B8(s32 a, s32 b, s32 c, s32 d) {
    lbl_80366B18.mask = 0;
    if (a >= 0) {
        lbl_80366B18.mask = 1 << a;
    }
    if (b >= 0) {
        lbl_80366B18.mask |= 1 << b;
    }
    if (c >= 0) {
        lbl_80366B18.mask |= 1 << c;
    }
    if (d >= 0) {
        lbl_80366B18.mask |= 1 << d;
    }
}

// .text:0x8000F48C size:0x2C
void somethingSetTexturePointer(void) {
    lbl_803CBBE8 = lbl_800E9920;
    convertTextureHeader(lbl_800E9920);
}

// .text:0x8000F3E8 size:0xA4
void fn_8000F3E8(s32 arg0) {
}

// .text:0x8000F150 size:0x298
void fn_8000F150(void) {
}
