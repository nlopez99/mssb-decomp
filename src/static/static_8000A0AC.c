#include "static/static_8000A0AC.h"
#include "static/static_80009E94.h"

typedef struct RelocHeader {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 _06;
    /* 0x08 */ u32 _08;
    /* 0x0C */ u32 _0C;
} RelocHeader;

typedef struct RelocList {
    /* 0x00 */ u32 count;
    /* 0x04 */ u32 _04;
    /* 0x08 */ u32 offsets[1];
} RelocList;

// .text:0x8000B9C8 size:0x74
void fn_8000B9C8(RelocHeader* hdr) {
    u32* p;
    u32* q;
    s32 n;
    s32 m;
    RelocList* sub;
    RelocList* list;

    hdr->_08 += (u32)hdr;
    if (hdr->_06 == 0) {
        hdr->_0C += (u32)hdr;
    }
    list = (RelocList*)hdr->_08;
    n = list->count;
    p = (u32*)list;
    do {
        p[2] += (u32)list;
        sub = (RelocList*)p[2];
        q = (u32*)sub;
        m = sub->count & 0x7FFFFFFF;
        do {
            q[2] += (u32)sub;
            q++;
        } while (--m != 0);
        n--;
        p++;
    } while (n != 0);
}

// .text:0x8000AF1C size:0xAAC
void fn_8000AF1C(void) {
}

// .text:0x8000A3EC size:0xB30
void fn_8000A3EC(void) {
}

// .text:0x8000A1E8 size:0x204
void interpolatePointsBezier_Vec2s(InterpPoint* out, BezierVec2s* p0, BezierVec2s* p1, BezierVec2s* p2, BezierVec2s* p3, u32 mode, f32 t) {
    InterpPoint pts[10];

    pts[0].x = p0->x;
    pts[0].y = p0->y;
    pts[3].x = p1->x;
    pts[3].y = p1->y;
    pts[6].x = p2->x;
    pts[6].y = p2->y;
    pts[9].x = p3->x;
    pts[9].y = p3->y;
    if (mode == 0) {
        interpolatePointsUnknown(3, pts, 1, 0);
        BezierInterpolate(out, &pts[0], &pts[1], &pts[2], &pts[3], t);
    } else if (mode == 1) {
        interpolatePointsUnknown(3, pts, 1, 0);
        interpolatePointsUnknown(6, pts, 0, 1);
        BezierInterpolate(out, &pts[3], &pts[4], &pts[5], &pts[6], t);
    } else {
        interpolatePointsUnknown(6, pts, 0, 1);
        BezierInterpolate(out, &pts[6], &pts[7], &pts[8], &pts[9], t);
    }
}

// .text:0x8000A0AC size:0x13C
void fn_8000A0AC(InterpPoint* out, BezierKey* a, BezierKey* b, f32 t) {
    InterpPoint pts[4];
    s16* handles[2];

    if (a->_04 == 2) {
        handles[0] = a->handles;
        handles[1] = b->handles;
    } else {
        handles[0] = a->handles;
        handles[1] = b->handles;
    }
    pts[0].x = a->x;
    pts[0].y = a->y;
    pts[1].x = handles[0][2];
    pts[1].y = handles[0][3];
    pts[2].x = handles[1][0];
    pts[2].y = handles[1][1];
    pts[3].x = b->x;
    pts[3].y = b->y;
    BezierInterpolate(out, &pts[0], &pts[1], &pts[2], &pts[3], t);
}
