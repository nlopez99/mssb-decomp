#include "static/uitexture.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "static/UnknownHomes_Static.h"
#include "static/graphic.h"

typedef struct SpriteVtx {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ u32 color;
    /* 0x10 */ u16 s;
    /* 0x12 */ u16 t;
} SpriteVtx; // size: 0x14

typedef struct GridPoint {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
} GridPoint; // size: 0x8

extern OSThread* GXGetCurrentGXThread(void);
extern void fn_800B2160(s32 mode);
extern void fn_800B216C(s32 arg0, s32 arg1, s32 arg2);
extern void fn_800B24D4(s32 id);
extern void DrawSprite_TexObj(SpriteVtx* vtx, TextureDesc* tex);
extern int rand(void);
extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);

u8 lbl_8023DD80[640 * 480 * 2];
extern u8 lbl_803CBBC0;
extern ScreenEffect lbl_803C5090;

TextureDesc lbl_800F7A40 = {
    lbl_8023DD80, NULL, 448, 640, GX_CLAMP, GX_CLAMP, GX_LINEAR, GX_LINEAR, 0.0f, 0, 0, 0, GX_TF_RGB565,
};

ScreenEffectSlot lbl_800F7A60[2] = {
    { 0, fn_80039FF8 },
    { 0, fn_80039FF8 },
};

// The IA8 palette of the C4 texture fn_8003AD84 (static_8003A2EC.c) sets up
u16 lbl_800F7AC0[16] ATTRIBUTE_ALIGN(32) = {
    0x0000, 0x11FF, 0x22FF, 0x33FF, 0x44FF, 0x55FF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
};

TextureDesc lbl_800F7AE0 = {
    NULL, NULL, 480, 640, GX_CLAMP, GX_CLAMP, GX_LINEAR, GX_LINEAR, 0.0f, 0, 0, 0, GX_TF_RGB565,
};


// .text:0x8003A2C0 size:0x2C
void fn_8003A2C0(void) {
    fn_800B0A5C_insertQueue(fn_8003A1D0, 0x6001);
}

// .text:0x8003A1D0 size:0xF0
void fn_8003A1D0(void) {
    if (lbl_803C5090.flags & 2) {
        lbl_803C5090.width = 320;
        lbl_803C5090.height = 224;
        lbl_800F7A40.width = 320;
        lbl_800F7A40.height = 224;
    } else {
        lbl_803C5090.width = 640;
        lbl_803C5090.height = 448;
        lbl_800F7A40.width = 640;
        lbl_800F7A40.height = 448;
    }
    if ((lbl_803C5090.flags & 0x11) == 1) {
        lbl_800F7A60[lbl_803CBBC0].fx = lbl_803C5090;
        fn_800A7D4C(8, &lbl_800F7A60[lbl_803CBBC0]);
    }
    fn_80039AC0();
    fn_800B0A14_removeQueue();
}

// .text:0x8003A144 size:0x8C
void fn_8003A144(void) {
    if (GXGetCurrentGXThread() == OSGetCurrentThread()) {
        GXSetTexCopySrc(0, 0, 640, 448);
        GXSetTexCopyDst(640, 448, GX_TF_RGB565, GX_FALSE);
        GXCopyTex(lbl_8023DD80, GX_FALSE);
        GXPixModeSync();
        lbl_800F7A40.width = 640;
        lbl_800F7A40.height = 448;
    }
}

// .text:0x8003A090 size:0xB4
void fn_8003A090(void) {
    if (GXGetCurrentGXThread() == OSGetCurrentThread() && (lbl_803C5090.flags & 0x11)) {
        u16 width;
        u16 height;

        height = lbl_803C5090.height;
        width = lbl_803C5090.width;

        GXSetTexCopySrc(0, 0, 640, 448);
        GXSetTexCopyDst(width, height, GX_TF_RGB565, width != 640);
        GXCopyTex(lbl_8023DD80, GX_FALSE);
        GXPixModeSync();
        lbl_800F7A40.width = width;
        lbl_800F7A40.height = height;
    }
}

// .text:0x80039FF8 size:0x98
void fn_80039FF8(ScreenEffectSlot* slot) {
    if (slot->fx.flags & 1) {
        u16 width;
        u16 height;

        height = slot->fx.height;
        width = slot->fx.width;

        GXSetTexCopySrc(0, 0, 640, 448);
        GXSetTexCopyDst(width, height, GX_TF_RGB565, width != 640);
        GXCopyTex(lbl_8023DD80, GX_FALSE);
        GXPixModeSync();
        lbl_800F7A40.width = width;
        lbl_800F7A40.height = height;
    }
}

// .text:0x80039AC0 size:0x538
void fn_80039AC0(void) {
    SpriteVtx quad[4];
    GridPoint grid[9][9];
    u32 color;
    s32 mode;
    s32 row;
    s32 col;
    GridPoint* p;
    u16 s0;
    u16 s1;
    u16 t0;
    u16 t1;
    f32 z;
    f32 w;
    f32 h;
    f32 rnd;

    if (lbl_803C5090.flags & 8) {
        // the target reads the colour as one unaligned word from 0x1A
        color = (*(u32*)&lbl_803C5090._1A & ~0xFF) | lbl_803C5090.alpha;
    } else {
        color = 0xFFFFFF00;
    }
    fn_800B24D4(11);
    fn_800B216C(1, 3, 0);
    mode = 1;
    if (lbl_803C5090._18 != 0) {
        mode = 2;
    }
    fn_800B2160(mode);
    if (lbl_803C5090.flags & 4) {
        for (row = 0; row <= 8; row++) {
            for (col = 0; col <= 8; col++) {
                p = &grid[row][col];
                w = (640.0f * lbl_803C5090.scale) / 1280.0f;
                p->x = -w / 2.0f + w * (f32)col / 8.0f;
                h = (448.0f * lbl_803C5090.scale) / 1280.0f;
                p->y = -h / 2.0f + h * (f32)row / 8.0f;
                rnd = (f32)(rand() & 0xFF) / 255.0f;
                p->x += lbl_803C5090.scale * (lbl_803C5090.jitterX / 2.0f - lbl_803C5090.jitterX * rnd) / 1280.0f;
                if ((col == 0 && p->x > 0.0f) || (8 - col == 0 && p->x < 0.0f)) {
                    p->x *= -1.0f;
                }
                rnd = (f32)(rand() & 0xFF) / 255.0f;
                p->y += lbl_803C5090.scale * (lbl_803C5090.jitterY / 2.0f - lbl_803C5090.jitterY * rnd) / 1280.0f;
                if ((row == 0 && p->y > 0.0f) || (8 - row == 0 && p->y < 0.0f)) {
                    p->y *= -1.0f;
                }
            }
        }
        t1 = 0;
        for (row = 0; row < 8; row++) {
            t0 = t1;
            t1 = t0 + 0x80;
            s1 = 0;
            for (col = 0; col < 8; col++) {
                s0 = s1;
                s1 = s0 + 0x80;
                quad[0].x = grid[row][col].x;
                quad[0].y = grid[row][col].y;
                quad[0].z = -lbl_803C5090.scale;
                quad[0].color = color;
                quad[0].s = s0;
                quad[0].t = t0;
                quad[1].x = grid[row + 1][col].x;
                quad[1].y = grid[row + 1][col].y;
                quad[1].z = -lbl_803C5090.scale;
                quad[1].color = color;
                quad[1].s = s0;
                quad[1].t = t1;
                quad[2].x = grid[row + 1][col + 1].x;
                quad[2].y = grid[row + 1][col + 1].y;
                quad[2].z = -lbl_803C5090.scale;
                quad[2].color = color;
                quad[2].s = s1;
                quad[2].t = t1;
                quad[3].x = grid[row][col + 1].x;
                quad[3].y = grid[row][col + 1].y;
                quad[3].z = -lbl_803C5090.scale;
                quad[3].color = color;
                quad[3].s = s1;
                quad[3].t = t0;
                do {
                    DrawSprite_TexObj(quad, &lbl_800F7A40);
                } while ((lbl_803C5090.repeat -= (lbl_803C5090.repeat != 0)) != 0);
            }
            if (t1 >= (lbl_803C5090._14 << 10) / 448) {
                break;
            }
        }
    } else {
        f32 x0;
        f32 x1;
        f32 y0;
        f32 y1;

        w = (640.0f * lbl_803C5090.scale) / 1280.0f;
        h = (448.0f * lbl_803C5090.scale) / 1280.0f;
        x0 = -w / 2.0f;
        x1 = w / 2.0f;
        y0 = -h / 2.0f;
        z = -lbl_803C5090.scale;
        y1 = y0 + (f32)lbl_803C5090._14 * lbl_803C5090.scale / 1280.0f;
        quad[0].x = x0;
        quad[0].y = y0;
        quad[0].z = z;
        quad[0].color = color;
        quad[0].s = 0;
        quad[0].t = 0;
        quad[1].x = x0;
        quad[1].y = y1;
        quad[1].z = z;
        quad[1].color = color;
        quad[1].s = 0;
        quad[1].t = (lbl_803C5090._14 << 10) / 448;
        quad[2].x = x1;
        quad[2].y = y1;
        quad[2].z = z;
        quad[2].color = color;
        quad[2].s = 0x400;
        quad[2].t = (lbl_803C5090._14 << 10) / 448;
        quad[3].x = x1;
        quad[3].y = y0;
        quad[3].z = z;
        quad[3].color = color;
        quad[3].s = 0x400;
        quad[3].t = 0;
        do {
            DrawSprite_TexObj(quad, &lbl_800F7A40);
        } while ((lbl_803C5090.repeat -= (lbl_803C5090.repeat != 0)) != 0);
    }
}

// .text:0x80039AB4 size:0xC
TextureDesc* fn_80039AB4(void) {
    return &lbl_800F7A40;
}

// .text:0x80039AA8 size:0xC
void* GetUITexture(void) {
    return lbl_8023DD80;
}
