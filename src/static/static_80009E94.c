#include "static/static_80009E94.h"

extern struct {
    /* 0x00 */ u8 _00[0x88];
    /* 0x88 */ void* _88;
} lbl_80366188;

// .text:0x8000A094 size:0x18
void* fn_8000A094(void* callback) {
    void* old = lbl_80366188._88;
    lbl_80366188._88 = callback;
    return old;
}

// Differs: FPR allocation only (the target keeps t*t*t in f12 and creates 3.0f before
// -3.0f); statement orders and operand orders of the sums were tried.
// .text:0x8000A00C size:0x88
void BezierInterpolate(InterpPoint* out, InterpPoint* p0, InterpPoint* p1, InterpPoint* p2, InterpPoint* p3, f32 t) {
    f32 b2;
    f32 t2;
    f32 t3;
    f32 b0;
    f32 b1;

    t2 = t * t;
    t3 = t2 * t;
    b2 = 3.0f * t2 + -3.0f * t3;
    b0 = -t3 + 3.0f * t2 + -3.0f * t + 1.0f;
    b1 = 3.0f * t3 + -6.0f * t2 + 3.0f * t;
    out->x = t3 * p3->x + (p2->x * b2 + (p0->x * b0 + p1->x * b1));
    out->y = t3 * p3->y + (p2->y * b2 + (p0->y * b0 + p1->y * b1));
}

// .text:0x80009E94 size:0x178
void interpolatePointsUnknown(s32 i, InterpPoint* pts, u32 first, u32 last) {
    InterpPoint* a = &pts[i - 3];
    InterpPoint* b = &pts[i];
    InterpPoint* c = &pts[i + 3];
    InterpPoint* p1 = &pts[i - 2];
    InterpPoint* p2 = &pts[i - 1];
    InterpPoint* p4 = &pts[i + 1];
    InterpPoint* p5 = &pts[i + 2];

    if (first) {
        p1->x = (7.0f * a->x + 6.0f * b->x - c->x) / 12.0f;
        p1->y = (7.0f * a->y + 6.0f * b->y - c->y) / 12.0f;
    }
    p2->x = (6.0f * b->x + a->x - c->x) / 6.0f;
    p2->y = (6.0f * b->y + a->y - c->y) / 6.0f;
    p4->x = (c->x + (-1.0f * a->x + 6.0f * b->x)) / 6.0f;
    p4->y = (c->y + (-1.0f * a->y + 6.0f * b->y)) / 6.0f;
    if (last) {
        p5->x = (7.0f * c->x + (-1.0f * a->x + 6.0f * b->x)) / 12.0f;
        p5->y = (7.0f * c->y + (-1.0f * a->y + 6.0f * b->y)) / 12.0f;
    }
}
