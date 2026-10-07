#ifndef __GAME_rep_3520_H_
#define __GAME_rep_3520_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"
#include "Dolphin/gx.h"
#include "static/UnknownHomes_Static.h"

struct Unk3520Obj;
struct Unk3520Box;

void fn_3_132EDC(void* arg0, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* arg4, u8* arg5);
void fn_3_1330E4(void);
void fn_3_133200(void);
void fn_3_133320(void);
void fn_3_13334C(void);
BOOL fn_3_1344BC(int a, int b);
s16 fn_3_1345AC(s16 angle, s16 target, int speed);
void fn_3_134658(void);
int fn_3_134908(const void* a, const void* b);
int fn_3_134918(const void* a, const void* b);
void fn_3_13493C(void);
void fn_3_134C80(void);
void fn_3_134D4C(void);
void fn_3_1350BC(void);
BOOL fn_3_1354BC(s32 i, f32 x, f32 z);
int fn_3_135520(f32 x, f32 z, f32 r);
void fn_3_135600(f32* outX, f32* outZ, f32 x, f32 z);
int fn_3_13564C(f32 x, f32 z);
int fn_3_135698(const void* a, const void* b);
void fn_3_1356F8(void);
void fn_3_1357A4(Vec* pos, Vec* dir);
void fn_3_13583C(Vec* pos);
void fn_3_135924(void);
void fn_3_135A64(void);
void fn_3_135C18(void);
void fn_3_135E38(void);
void fn_3_135E98(void);
void fn_3_135F4C(void);
void fn_3_135FF4(void);
void fn_3_136048(void);
void fn_3_1360BC(int player);
void fn_3_136220(void);
void fn_3_13688C(struct Unk3520Box* box);
void fn_3_136CF4(struct Unk3520Box* box);
void fn_3_136EA4(void);
void fn_3_1370A0(camera_803c639c_s* camera);
void fn_3_1371E8(void);
void fn_3_137224(Vec* center);
void fn_3_1373E0(void);
BOOL fn_3_1379A0(int fielderIdx);
u8 fn_3_137B10(struct Unk3520Obj* obj);
void fn_3_137CF8(struct Unk3520Obj* obj);
void fn_3_137DE4(struct Unk3520Obj* obj);
void fn_3_137F14(struct Unk3520Obj* obj);
void fn_3_13802C(void);
void fn_3_1382E0(struct Unk3520Obj* obj);
void fn_3_138448(struct Unk3520Obj* obj);
void fn_3_1384B4(struct Unk3520Obj* obj);
void fn_3_138AA4(void);
void fn_3_1391C0(void);
void fn_3_139700(void);
void fn_3_13974C(void);
void fn_3_139808(void);
void fn_3_139CA0(void);
void fn_3_139F84(void);
void fn_3_13A048(s32 to, s32 from);
void fn_3_13A0AC(void);
void fn_3_13A724(void);
void fn_3_13A89C(void);
void fn_3_13AA78(void);
void fn_3_13ACB4(void);
void fn_3_13ADC0(Vec* out, Vec* v, Vec* n);
void fn_3_13AE1C(void);
void fn_3_13AFE4(void);
void fn_3_13B284(void);
void fn_3_13B9C4(void);
void fn_3_13BB30(void);
void fn_3_13BBF4(void);
void fn_3_13BCB8(void);
void fn_3_13C464(void);
void fn_3_13C468(void);

#endif // !__GAME_rep_3520_H_
