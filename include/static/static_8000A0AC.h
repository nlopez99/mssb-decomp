#ifndef __STATIC_STATIC_8000A0AC_H_
#define __STATIC_STATIC_8000A0AC_H_

#include "mssbTypes.h"
#include "static/static_80009E94.h"

void fn_8000A0AC(InterpPoint* out, BezierKey* a, BezierKey* b, f32 t);
void interpolatePointsBezier_Vec2s(InterpPoint* out, BezierVec2s* p0, BezierVec2s* p1, BezierVec2s* p2, BezierVec2s* p3, u32 mode, f32 t);
void fn_8000A3EC(void);
void fn_8000AF1C(void);
void fn_8000B9C8(struct RelocHeader* hdr);

#endif // !__STATIC_STATIC_8000A0AC_H_
