#include "HVQM4/hvqm4dec.h"

typedef struct HuffTree {
    /* 0x000 */ s32 _00;
    /* 0x004 */ s32 root;
    /* 0x008 */ s16 array[2][0x200];
} HuffTree; // size: 0x808

typedef struct BitBuffer {
    /* 0x00 */ u8* ptr;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ u8 value;
    /* 0x0D */ u8 bit;
} BitBuffer; // size: 0x10

typedef struct BitBufferWithTree {
    /* 0x00 */ BitBuffer buf;
    /* 0x10 */ HuffTree* tree;
} BitBufferWithTree;

typedef struct BlockData {
    /* 0x0 */ u8 value;
    /* 0x1 */ u8 type;
} BlockData;

typedef struct StackState {
    /* 0x00 */ s32 plane_idx;
    /* 0x04 */ BlockData* line_prev;
    /* 0x08 */ BlockData* line_curr;
    /* 0x0C */ BlockData* line_next;
    /* 0x10 */ BlockData next;
    /* 0x12 */ BlockData curr;
    /* 0x14 */ u8 value_prev;
} StackState;

typedef struct Plane {
    /* 0x00 */ BlockData* _00;
    /* 0x04 */ BlockData* _04;
    /* 0x08 */ u16 _08;
    /* 0x0A */ u16 _0A;
    /* 0x0C */ u16 _0C;
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u16 blk_offs[4];
    /* 0x18 */ s32 pix_offs[4];
    /* 0x28 */ u16 _28;
    /* 0x2A */ u16 _2A;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ u8 _30;
    /* 0x31 */ u8 _31;
    /* 0x32 */ u8 _32;
    /* 0x33 */ u8 _33;
    /* 0x34 */ u8 _34;
    /* 0x35 */ u8 _35[3];
} Plane; // size: 0x38

typedef struct MCPlane {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ BlockData* _08;
    /* 0x0C */ BlockData* _0C;
    /* 0x10 */ s32 _10;
    /* 0x14 */ u8* _14;
    /* 0x18 */ u8* _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ s32 _20;
    /* 0x24 */ u16 _24;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 _30;
} MCPlane; // size: 0x34

typedef struct VideoState {
    /* 0x0000 */ Plane planes[3];
    /* 0x00A8 */ HuffTree trees[6];
    /* 0x30D8 */ BitBufferWithTree dc_values[3];
    /* 0x3114 */ BitBufferWithTree dc_rle[3];
    /* 0x3150 */ BitBufferWithTree bufTree0[3];
    /* 0x318C */ BitBufferWithTree basis_num[2];
    /* 0x31B4 */ BitBufferWithTree basis_num_run[2];
    /* 0x31DC */ BitBuffer fixvl[3];
    /* 0x320C */ BitBufferWithTree mv_h;
    /* 0x3220 */ BitBufferWithTree mv_v;
    /* 0x3234 */ BitBufferWithTree mcb_proc;
    /* 0x3248 */ BitBufferWithTree mcb_type;
    /* 0x325C */ u16 nest_stride;
    /* 0x325E */ u16 nest_height;
    /* 0x3260 */ u8 is_landscape;
    /* 0x3261 */ u8 nest_data[0x3CC6 - 0x3261];
    /* 0x3CC6 */ s16 dc_max;
    /* 0x3CC8 */ s16 dc_min;
    /* 0x3CCA */ u8 _3CCA;
    /* 0x3CCB */ u8 _3CCB[0x3CD0 - 0x3CCB];
} VideoState; // size: 0x3CD0

extern u8 lbl_80328DA0[0x200];

// .text:0x800DFDD4 size:0x6B4
void fn_800DFDD4(void) {
}

// .text:0x800E0488 size:0x360
void fn_800E0488(void* a, void* b) {
}

// .text:0x800E07E8 size:0x11C
void fn_800E07E8(VideoInfo* info, s32 plane_idx, u8 h_samp, u8 v_samp) {
    Plane* plane = &info->state->planes[plane_idx];

    plane->_30 = (h_samp == 2) ? 1 : 0;
    plane->_28 = info->width >> plane->_30;
    plane->_31 = (v_samp == 2) ? 1 : 0;
    plane->_2A = info->height >> plane->_31;
    plane->_2C = plane->_28 * plane->_2A;
    plane->_32 = 2 >> plane->_30;
    plane->_33 = 2 >> plane->_31;
    plane->_34 = plane->_32 * plane->_33;
    plane->_08 = info->width / (h_samp * 4);
    plane->_0A = info->height / (v_samp * 4);
    plane->_0C = plane->_08 + 2;
    plane->_0E = plane->_0A + 2;
    plane->blk_offs[0] = 0;
    plane->blk_offs[3] = 1;
    plane->blk_offs[2] = (plane->blk_offs[1] = plane->_0C) + 1;
    plane->pix_offs[0] = 0;
    plane->pix_offs[3] = 4;
    plane->pix_offs[2] = (plane->pix_offs[1] = plane->_28 * 4) + 4;
}

// .text:0x800E0904 size:0x3C4
void fn_800E0904(void) {
}

// .text:0x800E0CC8 size:0x98
s16 fn_800E0CC8(BitBufferWithTree* bt) {
    BitBuffer* buf = &bt->buf;
    HuffTree* tree = bt->tree;
    s16 node = tree->root;
    u8 bit;

    while (node >= 0x100) {
        if (buf->bit == 0) {
            buf->value = *buf->ptr++;
            buf->bit = 0x80;
        }
        bit = buf->value & buf->bit;
        buf->bit >>= 1;
        if (bit) {
            node = tree->array[1][node];
        } else {
            node = tree->array[0][node];
        }
    }
    return tree->array[0][node];
}

// .text:0x800E0D60 size:0x354
void fn_800E0D60(void) {
}

// .text:0x800E10B4 size:0x114
// register allocation differs: the target keeps state + i * 0x14 from a mulli and the
// width copy in r24
void fn_800E10B4(VideoState* state) {
    s32 i;

    for (i = 0; i < 3; i++) {
        Plane* plane = &state->planes[i];
        BitBufferWithTree* dcval = &state->dc_values[i];
        BitBufferWithTree* dcrun = &state->dc_rle[i];
        s32 width = plane->_08;
        BlockData* curr = plane->_04;
        s32 y = plane->_0A;
        s32 stride = plane->_0C;
        s32 rle = 0;

        for (; y > 0; y--) {
            BlockData* prev = curr - stride;
            u8 value = prev->value;
            s32 x;

            for (x = width; x > 0; x--) {
                s16 delta;
                if (rle == 0) {
                    s16 max = state->dc_max;
                    s32 sum = 0;
                    s16 min = state->dc_min;
                    s16 v;
                    do {
                        v = fn_800E0CC8(dcval);
                        sum += v;
                    } while (min >= v || v >= max);
                    delta = sum;
                    if (delta == 0) {
                        rle = fn_800E0CC8(dcrun);
                    }
                } else {
                    delta = 0;
                    rle--;
                }
                value += delta;
                curr->value = value;
                value = (value + 1 + (++prev)->value) >> 1;
                curr++;
            }
            curr += 2;
        }
    }
}

// .text:0x800E11C8 size:0x3A4
void fn_800E11C8(void) {
}

// .text:0x800E156C size:0x19C
void fn_800E156C(u8* dst, s32 stride, u8 value, u8 top, u8 bottom, u8 left, u8 right) {
    s32 v2 = value * 2;
    s32 tmb = top - bottom;
    s32 lmr = left - right;
    s32 v8 = ((value + 0x80) << 3) + 4;
    s32 tpl = top + left - v2;
    s32 tpr = top + right - v2;
    s32 vph = tmb + lmr;
    s32 vmh = tmb - lmr;
    s32 bpr = bottom + right - v2;
    s32 tml = top - left;
    s32 tmr = top - right;
    s32 bpl = left + bottom - v2;
    s32 bml = bottom - left;
    s32 bmr = bottom - right;

    dst[0] = lbl_80328DA0[(tpl + (v8 + vph)) >> 3];
    dst[1] = lbl_80328DA0[(tml + (v8 + vph)) >> 3];
    dst[2] = lbl_80328DA0[(tmr + (v8 + vmh)) >> 3];
    dst[3] = lbl_80328DA0[(tpr + (v8 + vmh)) >> 3];
    dst += stride;
    dst[0] = lbl_80328DA0[((v8 + vph) - tml) >> 3];
    dst[1] = lbl_80328DA0[(v8 - bpr) >> 3];
    dst[2] = lbl_80328DA0[(v8 - bpl) >> 3];
    dst[3] = lbl_80328DA0[((v8 + vmh) - tmr) >> 3];
    dst += stride;
    dst[0] = lbl_80328DA0[((v8 - vmh) - bml) >> 3];
    dst[1] = lbl_80328DA0[(v8 - tpr) >> 3];
    dst[2] = lbl_80328DA0[(v8 - tpl) >> 3];
    dst[3] = lbl_80328DA0[((v8 - vph) - bmr) >> 3];
    dst += stride;
    dst[0] = lbl_80328DA0[(bpl + (v8 - vmh)) >> 3];
    dst[1] = lbl_80328DA0[(bml + (v8 - vmh)) >> 3];
    dst[2] = lbl_80328DA0[(bmr + (v8 - vph)) >> 3];
    dst[3] = lbl_80328DA0[(bpr + (v8 - vph)) >> 3];
}

// .text:0x800E1708 size:0x4AC
s32 fn_800E1708(VideoState* state, u8* basis, s32* bits, u8* nest, u32 nest_stride, s32 plane_idx) {
    return 0;
}

// .text:0x800E1BB4 size:0x4EC
s32 fn_800E1BB4(VideoState* state, u8* basis, s32* bits, u8* nest, u32 nest_stride, s32 plane_idx) {
    return 0;
}

// .text:0x800E20A0 size:0x270
// the target puts bits at sp+0x34 above basis (sp+0x24); this build puts it at sp+0x20
s32 fn_800E20A0(VideoState* state, s32* result, u8 count, u8* nest, u32 nest_stride, s32 plane_idx) {
    u8 basis[16];
    s32 bits = 0;

    result[0] = result[1] = result[2] = result[3] = result[4] = result[5] = result[6] = result[7] = result[8] =
        result[9] = result[10] = result[11] = result[12] = result[13] = result[14] = result[15] = 0;
    while (count--) {
        s32 factor = fn_800E1708(state, basis, &bits, nest, nest_stride, plane_idx);
        result[0] += factor * basis[0];
        result[1] += factor * basis[1];
        result[2] += factor * basis[2];
        result[3] += factor * basis[3];
        result[4] += factor * basis[4];
        result[5] += factor * basis[5];
        result[6] += factor * basis[6];
        result[7] += factor * basis[7];
        result[8] += factor * basis[8];
        result[9] += factor * basis[9];
        result[10] += factor * basis[10];
        result[11] += factor * basis[11];
        result[12] += factor * basis[12];
        result[13] += factor * basis[13];
        result[14] += factor * basis[14];
        result[15] += factor * basis[15];
    }
    return (result[0] + result[1] + result[2] + result[3] + result[4] + result[5] + result[6] + result[7] + result[8] +
            result[9] + result[10] + result[11] + result[12] + result[13] + result[14] + result[15]) >> 4;
}

// .text:0x800E2310 size:0x270
// the target puts bits at sp+0x34 above basis (sp+0x24); this build puts it at sp+0x20
s32 fn_800E2310(VideoState* state, s32* result, u8 count, u8* nest, u32 nest_stride, s32 plane_idx) {
    u8 basis[16];
    s32 bits = 0;

    result[0] = result[1] = result[2] = result[3] = result[4] = result[5] = result[6] = result[7] = result[8] =
        result[9] = result[10] = result[11] = result[12] = result[13] = result[14] = result[15] = 0;
    while (count--) {
        s32 factor = fn_800E1BB4(state, basis, &bits, nest, nest_stride, plane_idx);
        result[0] += factor * basis[0];
        result[1] += factor * basis[1];
        result[2] += factor * basis[2];
        result[3] += factor * basis[3];
        result[4] += factor * basis[4];
        result[5] += factor * basis[5];
        result[6] += factor * basis[6];
        result[7] += factor * basis[7];
        result[8] += factor * basis[8];
        result[9] += factor * basis[9];
        result[10] += factor * basis[10];
        result[11] += factor * basis[11];
        result[12] += factor * basis[12];
        result[13] += factor * basis[13];
        result[14] += factor * basis[14];
        result[15] += factor * basis[15];
    }
    return (result[0] + result[1] + result[2] + result[3] + result[4] + result[5] + result[6] + result[7] + result[8] +
            result[9] + result[10] + result[11] + result[12] + result[13] + result[14] + result[15]) >> 4;
}

// .text:0x800E2580 size:0x318
void fn_800E2580(VideoState* state, u8* dst, s32 stride, u8 value, u8 type, s32 plane_idx) {
    s32 result[16];
    s32 shift;
    s32 mean;

    if (type == 6) {
        BitBuffer* buf = &state->fixvl[plane_idx];
        dst[0] = *buf->ptr++;
        dst[1] = *buf->ptr++;
        dst[2] = *buf->ptr++;
        dst[3] = *buf->ptr++;
        dst += stride;
        dst[0] = *buf->ptr++;
        dst[1] = *buf->ptr++;
        dst[2] = *buf->ptr++;
        dst[3] = *buf->ptr++;
        dst += stride;
        dst[0] = *buf->ptr++;
        dst[1] = *buf->ptr++;
        dst[2] = *buf->ptr++;
        dst[3] = *buf->ptr++;
        dst += stride;
        dst[0] = *buf->ptr++;
        dst[1] = *buf->ptr++;
        dst[2] = *buf->ptr++;
        dst[3] = *buf->ptr++;
        return;
    }
    shift = state->_3CCA;
    mean = ((value + 0x80) << shift) - fn_800E20A0(state, result, type, state->nest_data, state->nest_stride, plane_idx);
    dst[0] = lbl_80328DA0[(result[0] + mean) >> shift];
    dst[1] = lbl_80328DA0[(result[1] + mean) >> shift];
    dst[2] = lbl_80328DA0[(result[2] + mean) >> shift];
    dst[3] = lbl_80328DA0[(result[3] + mean) >> shift];
    dst += stride;
    dst[0] = lbl_80328DA0[(result[4] + mean) >> shift];
    dst[1] = lbl_80328DA0[(result[5] + mean) >> shift];
    dst[2] = lbl_80328DA0[(result[6] + mean) >> shift];
    dst[3] = lbl_80328DA0[(result[7] + mean) >> shift];
    dst += stride;
    dst[0] = lbl_80328DA0[(result[8] + mean) >> shift];
    dst[1] = lbl_80328DA0[(result[9] + mean) >> shift];
    dst[2] = lbl_80328DA0[(result[10] + mean) >> shift];
    dst[3] = lbl_80328DA0[(result[11] + mean) >> shift];
    dst += stride;
    dst[0] = lbl_80328DA0[(result[12] + mean) >> shift];
    dst[1] = lbl_80328DA0[(result[13] + mean) >> shift];
    dst[2] = lbl_80328DA0[(result[14] + mean) >> shift];
    dst[3] = lbl_80328DA0[(result[15] + mean) >> shift];
}

// .text:0x800E2898 size:0x144
void fn_800E2898(VideoState* state, u8* dst, s32 stride, StackState* stack) {
    if (stack->curr.type == 0) {
        u8 value = stack->curr.value;
        u8 top = (stack->line_prev->type & 0x77) ? value : stack->line_prev->value;
        u8 bottom = (stack->line_next->type & 0x77) ? value : stack->line_next->value;
        u8 right = (stack->next.type & 0x77) ? value : stack->next.value;
        fn_800E156C(dst, stride, value, top, bottom, stack->value_prev, right);
        stack->value_prev = value;
    } else if (stack->curr.type == 8) {
        u8 value = stack->curr.value;
        u8* p;
        dst[0] = dst[1] = dst[2] = dst[3] = value;
        p = dst + stride;
        p[0] = p[1] = p[2] = p[3] = value;
        p += stride;
        p[0] = p[1] = p[2] = p[3] = value;
        p += stride;
        p[0] = p[1] = p[2] = p[3] = value;
        stack->value_prev = value;
    } else {
        fn_800E2580(state, dst, stride, stack->curr.value, stack->curr.type, stack->plane_idx);
        stack->value_prev = stack->next.value;
    }
    stack->line_prev++;
    stack->line_next++;
}

// .text:0x800E29DC size:0xD4
void fn_800E29DC(VideoState* state, u8* dst, s32 stride, StackState* stack, s32 count) {
    stack->next = *stack->line_curr;
    stack->value_prev = stack->line_curr->value;
    for (count--; count > 0; count--) {
        stack->curr = stack->next;
        stack->next = *++stack->line_curr;
        fn_800E2898(state, dst, stride, stack);
        dst += 4;
    }
    stack->curr = stack->next;
    stack->line_curr += 3;
    fn_800E2898(state, dst, stride, stack);
    stack->line_prev += 2;
    stack->line_next += 2;
}

// .text:0x800E2AB0 size:0xDC
// target keeps &plane->_04 in a register and reloads it after the first call
void fn_800E2AB0(VideoState* state, s32 plane_idx, u8* dst) {
    Plane* plane = state->planes + plane_idx;
    StackState stack;
    s32 i;
    s32 stride = plane->_28;
    s32 width = plane->_08;
    s32 stride4 = stride * 4;

    stack.line_prev = plane->_04;
    stack.line_curr = plane->_04;
    stack.line_next = plane->_04 + plane->_0C;
    stack.plane_idx = plane_idx;
    fn_800E29DC(state, dst, stride, &stack, width);
    dst += stride4;
    stack.line_prev = plane->_04;
    for (i = plane->_0A - 2; i > 0; i--) {
        fn_800E29DC(state, dst, stride, &stack, width);
        dst += stride4;
    }
    stack.line_next = stack.line_curr;
    fn_800E29DC(state, dst, stride, &stack, width);
}

// .text:0x800E2B8C size:0x8C
void fn_800E2B8C(Plane* plane, MCPlane* mc, s32 a, s32 b, s32 c) {
    int i;

    for (i = 0; i < 3; i++) {
        mc->_00 = 0;
        mc->_04 = 0x7F;
        mc->_10 = a;
        mc->_1C = b;
        mc->_20 = c;
        mc->_0C = mc->_08 = plane->_04;
        mc->_24 = 8 >> plane->_30;
        mc->_28 = (8 >> plane->_31) * plane->_28;
        mc->_2C = plane->_32;
        mc->_30 = plane->_0C * plane->_33;
        mc++;
        a += plane->_2C;
        b += plane->_2C;
        c += plane->_2C;
        plane++;
    }
}

// .text:0x800E2C18 size:0x6D0
void fn_800E2C18(u8* dst, s32 dst_stride, u8* src, s32 src_stride, s32 hpel_x, s32 hpel_y) {
}

// .text:0x800E32E8 size:0xC4
// registers only: the target keeps plane and mc in r30/r31 and n in r24
void fn_800E32E8(Plane* plane, MCPlane* mc, s32 x, s32 y) {
    s32 i;

    for (i = 0; i < 3; i++) {
        s32* offs = plane->pix_offs;
        s32 j = 0;
        u8* src = &mc->_18[(y >> (plane->_31 + 1)) * plane->_28 + (x >> (plane->_30 + 1))];
        u8 n = plane->_34;
        for (; j < n; j++) {
            s32 off = *offs++;
            fn_800E2C18(mc->_14 + off, plane->_28, src + off, plane->_28, x & 1, y & 1);
        }
        mc++;
        plane++;
    }
}

// .text:0x800E33AC size:0x4B4
void fn_800E33AC(void) {
}

// .text:0x800E3860 size:0x5DC
void fn_800E3860(void) {
}

// .text:0x800E3E3C size:0x2A8
void fn_800E3E3C(void) {
}

// .text:0x800E40E4 size:0x158
// registers only: the target gives the parameters and plane the lowest registers
void fn_800E40E4(VideoState* state, MCPlane* mc) {
    s32 i;
    BlockData* blocks;
    u16 stride;
    u16 hsafe;
    u16* boffs;
    s32* poffs;
    u8 n;
    s32 j;
    Plane* plane = state->planes;

    for (i = 0; i < 3; i++) {
        blocks = mc->_08;
        boffs = plane->blk_offs;
        stride = plane->_28;
        poffs = plane->pix_offs;
        hsafe = plane->_0C;
        n = plane->_34;

        for (j = 0; j < n; j++) {
            u16 off = *boffs++;
            u8* dst = mc->_14 + *poffs++;
            BlockData* b = &blocks[off];
            u8 type = b->type & 0xF;
            u8 value = b->value;

            if (type == 0) {
                u8 top = (blocks[off - hsafe].type & 0x77) ? value : blocks[off - hsafe].value;
                u8 left = (b[-1].type & 0x77) ? value : b[-1].value;
                u8 right = (b[1].type & 0x77) ? value : b[1].value;
                u8 bottom = (blocks[off + hsafe].type & 0x77) ? value : blocks[off + hsafe].value;
                fn_800E156C(dst, stride, value, top, bottom, left, right);
            } else {
                fn_800E2580(state, dst, stride, value, type, i);
            }
        }
        mc++;
        plane++;
    }
}

// .text:0x800E423C size:0x498
void fn_800E423C(void) {
}

// .text:0x800E46D4 size:0x3F4
void fn_800E46D4(void) {
}

// .text:0x800E4AC8 size:0x20
void fn_800E4AC8(void* a, void* b) {
    fn_800E0488(a, b);
}

// .text:0x800E4AE8 size:0x34
void fn_800E4AE8(VideoInfo* info, u8* p) {
    info->width = (p[0] << 8) | p[1];
    info->height = (p[2] << 8) | p[3];
    info->h_samp = p[4];
    info->v_samp = p[5];
}

// .text:0x800E4B1C size:0x74
u32 fn_800E4B1C(VideoInfo* info) {
    int w = info->width / 4;
    int cw = (info->h_samp == 2) ? (w >> 1) : w;
    int h = info->height / 4;
    int ch = (info->v_samp == 2) ? (h >> 1) : h;
    return ((w + 2) * (h + 2) + (cw + 2) * (ch + 2) * 2) * 2 + 0x3CD0;
}

// .text:0x800E4B90 size:0x464
void fn_800E4B90(VideoInfo* info, VideoState* state) {
    BlockData* buf;
    Plane* plane;
    s32 i;

    info->state = state;
    fn_800E07E8(info, 0, 1, 1);
    fn_800E07E8(info, 1, info->h_samp, info->v_samp);
    fn_800E07E8(info, 2, info->h_samp, info->v_samp);
    if ((state->is_landscape = info->width >= info->height)) {
        state->nest_stride = 0x46;
        state->nest_height = 0x26;
    } else {
        state->nest_stride = 0x26;
        state->nest_height = 0x46;
    }
    state->basis_num[0].tree = state->basis_num[1].tree = &state->trees[3];
    state->basis_num_run[0].tree = state->basis_num_run[1].tree = &state->trees[1];
    state->dc_values[0].tree = state->dc_values[1].tree = state->dc_values[2].tree = &state->trees[0];
    state->dc_rle[0].tree = state->dc_rle[1].tree = state->dc_rle[2].tree = &state->trees[1];
    state->bufTree0[0].tree = state->bufTree0[1].tree = state->bufTree0[2].tree = &state->trees[2];
    state->mv_h.tree = state->mv_v.tree = &state->trees[4];
    state->mcb_proc.tree = state->mcb_type.tree = &state->trees[5];

    buf = (BlockData*)(state + 1);
    plane = state->planes;
    for (i = 0; i < 3; i++) {
        BlockData* p;
        s32 j;

        plane->_00 = buf;
        plane->_04 = buf + plane->_0C + 1;
        buf += plane->_0C * plane->_0E;
        p = plane->_00;
        for (j = plane->_0C; j > 0; j--) {
            p->value = 0x7F;
            p->type = 0xFF;
            p++;
        }
        p = buf;
        for (j = plane->_0C; j > 0; j--) {
            p--;
            p->value = 0x7F;
            p->type = 0xFF;
        }
        p = plane->_00 + plane->_0C;
        for (j = plane->_0E - 2; j > 0; j--) {
            p->value = 0x7F;
            p->type = 0xFF;
            p += plane->_0C;
        }
        p = plane->_00 + plane->_0C * 2 - 1;
        for (j = plane->_0E - 2; j > 0; j--) {
            p->value = 0x7F;
            p->type = 0xFF;
            p += plane->_0C;
        }
        plane++;
    }
}

// .text:0x800E4FF4 size:0x928
void fn_800E4FF4(void) {
}

// .text:0x800E591C size:0x24
void fn_800E591C(void* a, void* b, void* c, void* d) {
    fn_800E5940(a, b, c, d, c);
}

// .text:0x800E5940 size:0x9F0
void fn_800E5940(void* a, void* b, void* c, void* d, void* e) {
}
