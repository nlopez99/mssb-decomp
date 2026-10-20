#ifndef __STATIC_SPANI_DEFAULT_H_
#define __STATIC_SPANI_DEFAULT_H_

#include "mssbTypes.h"
#include "Dolphin/mtx.h"

struct SpaniTask;
struct SpaniDesc;
struct SpaniHook;
struct SpaniObj;
struct SabFile;
struct SabInfo;

s32 fn_80034BCC(struct SpaniHook* hook);
void fn_80034CEC(struct SpaniTask* task);
void fn_80034E20(struct SpaniTask* task, struct SpaniDesc* desc);
struct SpaniObj* fn_80034F50(struct SpaniDesc* desc);

void fn_80035750(struct SabFile* sab, void* tex, s16 id);
void fn_800356B8(void);
void fn_80035A00(void);
void fn_80035B50(s32 id);
void fn_80035CA4(s32 id);
s32 fn_80035DD4(s32 id);
void fn_80035ED0(s32 index);
struct SabInfo* fn_80035F20(s32 id, s32 index, u16 frame, s16 sel);
void fn_80035EEC(u32 frame, s32 index);
void fn_80036134(struct SpaniTask* task, s32 id, s32 arg2, s32 id2);
s32 fn_80036214(struct SpaniTask* task, s32 id, s32 arg2, s32 arg3);
void fn_80036270(struct SpaniTask* task, s32 id, s32 arg2, s32 arg3, s16* x, s16* y);
void fn_800362F0(struct SpaniTask* task, s32 id);
void fn_800363D8(struct SpaniTask* task, s32 id, u32 part, u16 kind, s32 value);
void fn_8003649C(struct SpaniTask* task, s32 id, s32 part, u16 kind, s32 value);
void fn_8003656C(struct SpaniTask* task, s32 id, s32 part, u16 kind, s32 value);
void fn_8003664C(s32 id, s32 index, s16 value, u32 sel);
u16 fn_80036824(s32 id, s32 anim, u16 frame);
void fn_800369DC(f32 zoom);

#endif // !__STATIC_SPANI_DEFAULT_H_
