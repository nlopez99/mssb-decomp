#ifndef __GAME_rep_1D58_H_
#define __GAME_rep_1D58_H_

#include "mssbTypes.h"
#include "Dolphin/GX/GXTypes.h"
#include "Dolphin/mtx.h"
#include "C3/control.h"

struct _CollisionStruct;
struct StadiumObjectCollision;
struct StadiumObject1D58;
struct StadiumModel1D58;
struct StadiumSort1D58;
struct BoneData1D58;
struct ObjAnim1D58;
struct DODisplayObj;
struct DODisplayData;

typedef struct ModelBone1D58 {
    /* 0x000 */ u8 _000[0x14];
    /* 0x014 */ struct DODisplayObj* _014;
    /* 0x018 */ u8 _018[0xE8 - 0x18];
    /* 0x0E8 */ struct BoneData1D58* _0E8;
    /* 0x0EC */ MtxPtr _0EC;
    /* 0x0F0 */ u8 _0F0[0x100 - 0xF0];
    /* 0x100 */ struct ModelBone1D58* _100;
} ModelBone1D58;

typedef struct ModelActor1D58 {
    /* 0x00 */ u8 _00[0x6];
    /* 0x06 */ u16 totalBones;
    /* 0x08 */ u8 _08[0x10 - 0x8];
    /* 0x10 */ struct DODisplayData* pal;
    /* 0x14 */ struct DODisplayObj* skinObject;
    /* 0x18 */ struct ModelBone1D58** boneArray;
    /* 0x1C */ u8 _1C[0x64 - 0x1C];
    /* 0x64 */ MtxPtr skinMtxArray;
    /* 0x68 */ MtxPtr skinInvTransposeMtxArray;
    /* 0x6C */ u8 _6C[0x74 - 0x6C];
    /* 0x74 */ struct ModelBone1D58* drawHead;
    /* 0x78 */ u8 _78[0x7C - 0x78];
    /* 0x7C */ void* _7C;
    /* 0x80 */ u8 _80[0x98 - 0x80];
    /* 0x98 */ u8 _98;
} ModelActor1D58;

typedef struct StadiumModel1D58 {
    /* 0x00 */ struct ModelActor1D58* actor;
    /* 0x04 */ void* anim;
    /* 0x08 */ u8 _08[0xE - 0x8];
    /* 0x0E */ u16 _0E;
    /* 0x10 */ u8 _10[0x54 - 0x10];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ u16 _64;
    /* 0x66 */ u16 _66;
    /* 0x68 */ s32 _68;
    /* 0x6C */ u8 _6C[0x90 - 0x6C];
} StadiumModel1D58; // size: 0x90

typedef struct StadiumObject1D58 {
    /* 0x00 */ Control control;
    /* 0x44 */ Mtx _44;
    /* 0x74 */ struct StadiumModel1D58* _74;
    /* 0x78 */ struct StadiumObjectCollision* _78;
    /* 0x7C */ void (*_7C)(struct StadiumObject1D58* obj);
    /* 0x80 */ void (*_80)(s32 object, int type, struct _CollisionStruct* collision);
    /* 0x84 */ void (*_84)(struct StadiumObject1D58* obj);
    /* 0x88 */ void (*_88)(struct StadiumObject1D58* obj);
    /* 0x8C */ struct ObjAnim1D58* _8C;
    /* 0x90 */ u8 _90_7 : 1;
    /* 0x90 */ u8 _90_6 : 1;
    /* 0x90 */ u8 _90_5 : 1;
    /* 0x90 */ u8 _90_4 : 1;
    /* 0x90 */ u8 _90_3 : 1;
    /* 0x90 */ u8 _90_2 : 1;
    /* 0x90 */ u8 _90_1 : 1;
    /* 0x90 */ u8 _90_0 : 1;
    /* 0x91 */ u8 _91;
    /* 0x92 */ u8 _92;
    /* 0x93 */ u8 _93;
    /* 0x94 */ u16 _94;
    /* 0x96 */ s16 _96;
    /* 0x98 */ u8 _98;
    /* 0x99 */ u8 _99;
    /* 0x9A */ u8 _9A;
    /* 0x9B */ u8 _9B;
    /* 0x9C */ u8 _9C;
    /* 0x9D */ u8 _9D;
    /* 0x9E */ u8 _9E;
    /* 0x9F */ u8 _9F;
    /* 0xA0 */ Vec _A0;
    /* 0xAC */ void* _AC;
    /* 0xB0 */ f32 _B0;
    /* 0xB4 */ f32 _B4;
    /* 0xB8 */ f32 _B8;
    /* 0xBC */ f32 _BC;
    /* 0xC0 */ f32 _C0;
    /* 0xC4 */ u8 _C4;
    /* 0xC5 */ u8 _C5;
    /* 0xC6 */ u8 _C6;
    /* 0xC7 */ u8 _C7;
    /* 0xC8 */ u8 _C8;
    /* 0xC9 */ u8 _C9;
    /* 0xCA */ u8 _CA;
    /* 0xCB */ s8 _CB;
    /* 0xCC */ u8 _CC[0xE8 - 0xCC];
} StadiumObject1D58; // size: 0xE8

s32 fn_3_B7FC8(u32 id, s32 arg1);
void fn_3_B80D0(void);
void fn_3_B8184(struct StadiumModel1D58* model, Mtx view);
struct StadiumObject1D58* fn_3_B827C(void);
void fn_3_B828C(struct StadiumObject1D58* obj);
void fn_3_B8298(void);
void fn_3_B8414(Vec* min, Vec* max);
void fn_3_B8464(Mtx mtx, struct StadiumObjectCollision* collision);
void fn_3_B8574(void);
u32 fn_3_B85A8(s32 area, s32** objects);
void fn_3_B85DC(s32 area, Vec* min, Vec* max);
s32 fn_3_B8658(const void* a, const void* b);
void fn_3_B867C(Mtx view, struct StadiumSort1D58* sort);
void fn_3_B8828(MtxPtr view, s32 arg1, u32 arg2);
void fn_3_B8C08(Mtx view);
void fn_3_B902C(void);
void fn_3_B908C(void);
void fn_3_B9124(void);
void processStadiumObjectFunction(int stadium, s32 object, int type, struct _CollisionStruct* collision);
struct StadiumObjectCollision* fn_3_B91C8(int stadium, s32 object, Mtx mtx);
void fn_3_B939C(void);
void fn_3_B93C4(void);
void fn_3_B93C8(int arg0);
void fn_3_B93CC(void);
void fn_3_B950C(void);
void fn_3_B9510(s32 idx);
void fn_3_B9524(void);
u8* fn_3_B9534(s32 width, s32 height, GXTexObj* obj);
void fn_3_B95EC(void);
void fn_3_B97C8(void (*callback)(void));
void fn_3_B97DC(void* model, void* anim);
void fn_3_B98E8(struct StadiumModel1D58* model);
void fn_3_B99E4(void);
s32 fn_3_B9BB4(s32 stadium);
void fn_3_B9D68(u8* types, s32 count, void** files, s32* indices);
void fn_3_B9FB8(s32 stadium, void* file);

#endif // !__GAME_rep_1D58_H_
