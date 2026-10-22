#ifndef __STATIC_STATIC_8000A0AC_H_
#define __STATIC_STATIC_8000A0AC_H_

#include "mssbTypes.h"
#include "static/static_80009E94.h"
#include "Dolphin/mtx.h"

void fn_8000A0AC(InterpPoint* out, BezierKey* a, BezierKey* b, f32 t);
void interpolatePointsBezier_Vec2s(InterpPoint* out, BezierVec2s* p0, BezierVec2s* p1, BezierVec2s* p2, BezierVec2s* p3, u32 mode, f32 t);
s32 fn_8000A3EC(Mtx out, struct SpriteVerts* verts, struct SpriteKey* key, struct SpriteKey* next, InterpPoint* pt, f32 t, f32 z);
s32 fn_8000AF1C(Mtx out, struct SpriteVerts* verts, struct SpriteDesc* key, struct SpriteDesc* next, struct SpritePalette* pal, InterpPoint* pt, f32 t);
void fn_8000B9C8(struct RelocHeader* hdr);

#endif // !__STATIC_STATIC_8000A0AC_H_
